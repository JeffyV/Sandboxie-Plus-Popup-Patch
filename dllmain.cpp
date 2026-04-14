#include <Windows.h>
#include <cstdint>
#include <format>
#include <vector>

#pragma region Proxy
struct version_dll {
    HMODULE dll;
    FARPROC oGetFileVersionInfoA;
    FARPROC oGetFileVersionInfoByHandle;
    FARPROC oGetFileVersionInfoExA;
    FARPROC oGetFileVersionInfoExW;
    FARPROC oGetFileVersionInfoSizeA;
    FARPROC oGetFileVersionInfoSizeExA;
    FARPROC oGetFileVersionInfoSizeExW;
    FARPROC oGetFileVersionInfoSizeW;
    FARPROC oGetFileVersionInfoW;
    FARPROC oVerFindFileA;
    FARPROC oVerFindFileW;
    FARPROC oVerInstallFileA;
    FARPROC oVerInstallFileW;
    FARPROC oVerLanguageNameA;
    FARPROC oVerLanguageNameW;
    FARPROC oVerQueryValueA;
    FARPROC oVerQueryValueW;
} version;

extern "C"
{
    FARPROC PA = 0;

    int runASM() {
        (*(void (*)())PA)();
        return 0;
    }

    void fGetFileVersionInfoA() {
        PA = version.oGetFileVersionInfoA;
        runASM();
    }

    void fGetFileVersionInfoByHandle() {
        PA = version.oGetFileVersionInfoByHandle;
        runASM();
    }

    void fGetFileVersionInfoExA() {
        PA = version.oGetFileVersionInfoExA;
        runASM();
    }

    void fGetFileVersionInfoExW() {
        PA = version.oGetFileVersionInfoExW;
        runASM();
    }

    void fGetFileVersionInfoSizeA() {
        PA = version.oGetFileVersionInfoSizeA;
        runASM();
    }

    void fGetFileVersionInfoSizeExA() {
        PA = version.oGetFileVersionInfoSizeExA;
        runASM();
    }

    void fGetFileVersionInfoSizeExW() {
        PA = version.oGetFileVersionInfoSizeExW;
        runASM();
    }

    void fGetFileVersionInfoSizeW() {
        PA = version.oGetFileVersionInfoSizeW;
        runASM();
    }

    void fGetFileVersionInfoW() {
        PA = version.oGetFileVersionInfoW;
        runASM();
    }

    void fVerFindFileA() {
        PA = version.oVerFindFileA;
        runASM();
    }

    void fVerFindFileW() {
        PA = version.oVerFindFileW;
        runASM();
    }

    void fVerInstallFileA() {
        PA = version.oVerInstallFileA;
        runASM();
    }

    void fVerInstallFileW() {
        PA = version.oVerInstallFileW;
        runASM();
    }

    void fVerLanguageNameA() {
        PA = version.oVerLanguageNameA;
        runASM();
    }

    void fVerLanguageNameW() {
        PA = version.oVerLanguageNameW;
        runASM();
    }

    void fVerQueryValueA() {
        PA = version.oVerQueryValueA;
        runASM();
    }

    void fVerQueryValueW() {
        PA = version.oVerQueryValueW;
        runASM();
    }
}

void setupFunctions() {
    version.oGetFileVersionInfoA        = GetProcAddress(version.dll, "GetFileVersionInfoA");
    version.oGetFileVersionInfoByHandle = GetProcAddress(version.dll, "GetFileVersionInfoByHandle");
    version.oGetFileVersionInfoExA      = GetProcAddress(version.dll, "GetFileVersionInfoExA");
    version.oGetFileVersionInfoExW      = GetProcAddress(version.dll, "GetFileVersionInfoExW");
    version.oGetFileVersionInfoSizeA    = GetProcAddress(version.dll, "GetFileVersionInfoSizeA");
    version.oGetFileVersionInfoSizeExA  = GetProcAddress(version.dll, "GetFileVersionInfoSizeExA");
    version.oGetFileVersionInfoSizeExW  = GetProcAddress(version.dll, "GetFileVersionInfoSizeExW");
    version.oGetFileVersionInfoSizeW    = GetProcAddress(version.dll, "GetFileVersionInfoSizeW");
    version.oGetFileVersionInfoW        = GetProcAddress(version.dll, "GetFileVersionInfoW");
    version.oVerFindFileA               = GetProcAddress(version.dll, "VerFindFileA");
    version.oVerFindFileW               = GetProcAddress(version.dll, "VerFindFileW");
    version.oVerInstallFileA            = GetProcAddress(version.dll, "VerInstallFileA");
    version.oVerInstallFileW            = GetProcAddress(version.dll, "VerInstallFileW");
    version.oVerLanguageNameA           = GetProcAddress(version.dll, "VerLanguageNameA");
    version.oVerLanguageNameW           = GetProcAddress(version.dll, "VerLanguageNameW");
    version.oVerQueryValueA             = GetProcAddress(version.dll, "VerQueryValueA");
    version.oVerQueryValueW             = GetProcAddress(version.dll, "VerQueryValueW");
}
#pragma endregion

std::vector<size_t> RVAs = {
    0x147c80, // 1.15.12
    0x1948A0, // 1.16.2
    0x1A1850, // 1.16.3
    0x1B2400, // 1.16.5
    0x1B3D60, // 1.16.8
    0x1B4030, // 1.16.9
    0x1B5020, // 1.17.2
};

using bytes = std::vector<uint8_t>;

std::vector<std::string> patterns {
    // from 1.17.4
    "48 89 5C 24 08 48 89 74 24 10 48 89 7C 24 18 55 41 54 41 55 41 56 41 57 48 8D 6C 24 D0 48 81 EC 30 01 00 00 48 8B 05 ?? ?? ?? ?? 48 33 C4 48 89 45 20 44 0F B6 E1 45 33 F6 44 89 74 24 48 45 32 ED F6 05 ?? ?? ?? ?? 01"
};

MEMORY_BASIC_INFORMATION GetCodeSegment() {
    auto base = reinterpret_cast<size_t>(GetModuleHandle("SandMan.exe"));

    MEMORY_BASIC_INFORMATION info;
    do {
        VirtualQuery(reinterpret_cast<LPVOID>(base), &info, sizeof(info));
        base += info.RegionSize;
    } while (info.Protect != PAGE_EXECUTE_READ);

    return info;
}

void PatchNew() {
    struct PatternItem {
        bool    isWildcard; // ?
        uint8_t value;
    };

    const auto info = GetCodeSegment();

    // read process .text segment code
    bytes code(info.RegionSize);
    ReadProcessMemory(GetCurrentProcess(), info.BaseAddress, code.data(), info.RegionSize, nullptr);

    for (const std::string &pattern: patterns) {
        // parse pattern
        std::vector<PatternItem> bytesPattern;
        for (size_t i = 0; i < pattern.size();) {
            if (pattern[i] == ' ') {
                ++i;
                continue;
            }
            if (pattern[i] == '?' && i + 1 < pattern.size() && pattern[i + 1] == '?') {
                bytesPattern.emplace_back(true, 0);
                i += 2; // skip "??"
            } else {
                bytesPattern.emplace_back(false, std::stoi(pattern.substr(i, 2), nullptr, 16));
                i += 2;
            }
        }

        // find pattern in code
        std::vector<size_t> foundOffsets;
        for (size_t i = 0; i < code.size() - bytesPattern.size(); ++i) {
            bool found = true;
            for (size_t j = 0; j < bytesPattern.size(); ++j) {
                if (!bytesPattern[j].isWildcard && code[i + j] != bytesPattern[j].value) {
                    found = false;
                    break;
                }
            }
            if (found) {
                foundOffsets.emplace_back(i);
            }
        }

        // do patch when only find one pattern
        if (foundOffsets.size() != 1) {
            MessageBox(nullptr, std::format("found {} patterns, expected 1", foundOffsets.size()).c_str(), "pattern", MB_OK);
        } else {
            size_t  patchAddr = reinterpret_cast<size_t>(info.BaseAddress) + foundOffsets.at(0);
            uint8_t patch[]   = { 0xB0, 0x00, 0xC3, 0x90, 0x90 };
            WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<LPVOID>(patchAddr), patch, sizeof(patch), nullptr);
        }
    }
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved) {
    switch (ul_reason_for_call) {
        case DLL_PROCESS_ATTACH: {
            char path[MAX_PATH];
            GetWindowsDirectory(path, sizeof(path));

            strcat_s(path, "\\System32\\version.dll");
            version.dll = LoadLibrary(path);
            setupFunctions();

            // for (size_t &rva: RVAs) {
            //     size_t addr = reinterpret_cast<size_t>(GetModuleHandleA("SandMan.exe")) + rva;
            //
            //     // check
            //     uint8_t original[5] = { 0x48, 0x89, 0x5C, 0x24, 0x08 };
            //     if (memcmp((void *)addr, original, 5) == 0) {
            //         // patch
            //         uint8_t patch[] = { 0xB0, 0x00, 0xC3, 0x90, 0x90 };
            //         WriteProcessMemory(GetCurrentProcess(), (void *)addr, patch, sizeof(patch), nullptr);
            //
            //         // MessageBox(nullptr, std::format("patch success\nat: 0x{:016X}", rva).c_str(), "patch", MB_OK);
            //     }
            // }

            PatchNew();

            break;
        }
        case DLL_PROCESS_DETACH:
            FreeLibrary(version.dll);
            break;
    }
    return 1;
}
