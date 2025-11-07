### 1.16.5

SandMan.exe version: 1.16.5 x64 windows

`RVA: 0x1B2400`

```text
48 89 5C 24 08 48 89 74 24 10 48 89 7C 24 18 55 41 54 41 55 41 56 41 57 48 8D 6C 24 D0 48 81 EC 30 01 00 00 48 8B 05 ?? ?? ?? ?? 48 33 C4 48 89 45 20 44 0F B6 E1 45 33 F6 44 89 74 24 48 45 32 ED F6 05 ?? ?? ?? ?? 01 
```

### 1.16.3

SandMan.exe version: 1.16.3 x64 windows

`RVA: 0x1A1850`

```text
00007FF6CFCF1850 | 48:895C24 08             | mov qword ptr ss:[rsp+8],rbx            
00007FF6CFCF1855 | 48:897424 10             | mov qword ptr ss:[rsp+10],rsi           
00007FF6CFCF185A | 48:897C24 18             | mov qword ptr ss:[rsp+18],rdi           
00007FF6CFCF185F | 55                       | push rbp                                
00007FF6CFCF1860 | 41:54                    | push r12                                
00007FF6CFCF1862 | 41:55                    | push r13                                
00007FF6CFCF1864 | 41:56                    | push r14                                
00007FF6CFCF1866 | 41:57                    | push r15                                
00007FF6CFCF1868 | 48:8D6C24 D0             | lea rbp,qword ptr ss:[rsp-30]           
00007FF6CFCF186D | 48:81EC 30010000         | sub rsp,130                             
00007FF6CFCF1874 | 48:8B05 85901E00         | mov rax,qword ptr ds:[7FF6CFEDA900]     
00007FF6CFCF187B | 48:33C4                  | xor rax,rsp                             
00007FF6CFCF187E | 48:8945 20               | mov qword ptr ss:[rbp+20],rax           
00007FF6CFCF1882 | 44:0FB6E1                | movzx r12d,cl                           
00007FF6CFCF1886 | 45:33F6                  | xor r14d,r14d                           
00007FF6CFCF1889 | 44:897424 48             | mov dword ptr ss:[rsp+48],r14d          
00007FF6CFCF188E | 45:32ED                  | xor r13b,r13b                           
00007FF6CFCF1891 | F605 48F41E00 01         | test byte ptr ds:[7FF6CFEE0CE0],1       
```

```text
48 89 5C 24 08 48 89 74 24 10 48 89 7C 24 18 55 41 54 41 55 41 56 41 57 48 8D 6C 24 D0 48 81 EC 30 01 00 00 48 8B 05 85 90 1E 00 48 33 C4 48 89 45 20 44 0F B6 E1 45 33 F6 44 89 74 24 48 45 32 ED F6 05 48 F4 1E 00 01
```

### 1.16.2

SandMan.exe version: 1.16.2 x64 windows

`RVA: 0x1948A0`

```text
00007FF754E248A0 | 48:895C24 08             | mov qword ptr ss:[rsp+0x8],rbx                       
00007FF754E248A5 | 48:897424 10             | mov qword ptr ss:[rsp+0x10],rsi                      
00007FF754E248AA | 48:897C24 18             | mov qword ptr ss:[rsp+0x18],rdi                      
00007FF754E248AF | 55                       | push rbp                                             
00007FF754E248B0 | 41:54                    | push r12                                             
00007FF754E248B2 | 41:55                    | push r13                                             
00007FF754E248B4 | 41:56                    | push r14                                             
00007FF754E248B6 | 41:57                    | push r15                                             
00007FF754E248B8 | 48:8D6C24 D0             | lea rbp,qword ptr ss:[rsp-0x30]                      
00007FF754E248BD | 48:81EC 30010000         | sub rsp,0x130                                        
00007FF754E248C4 | 48:8B05 35401E00         | mov rax,qword ptr ds:[0x7FF755008900]                
00007FF754E248CB | 48:33C4                  | xor rax,rsp                                          
00007FF754E248CE | 48:8945 20               | mov qword ptr ss:[rbp+0x20],rax                      
00007FF754E248D2 | 44:0FB6E1                | movzx r12d,cl                                        
00007FF754E248D6 | 45:33F6                  | xor r14d,r14d                                        
00007FF754E248D9 | 44:897424 48             | mov dword ptr ss:[rsp+0x48],r14d                     
00007FF754E248DE | 45:32ED                  | xor r13b,r13b                                        
00007FF754E248E1 | F605 308F1E00 01         | test byte ptr ds:[0x7FF75500D818],0x1                
```

```text
48 89 5C 24 08 48 89 74 24 10 48 89 7C 24 18 55 41 54 41 55 41 56 41 57 48 8D 6C 24 D0 48 81 EC 30 01 00 00 48 8B 05 35 40 1E 00 48 33 C4 48 89 45 20 44 0F B6 E1 45 33 F6 44 89 74 24 48 45 32 ED F6 05 30 8F 1E 00 01
```

### 1.15.12

SandMan.exe version: 1.15.12 x64 windows

`RVA: 0x147c80`

```text
00007FF74CCF7C80 | 48:895C24 08             | mov qword ptr ss:[rsp+0x8],rbx                       
00007FF74CCF7C85 | 48:897424 10             | mov qword ptr ss:[rsp+0x10],rsi                      
00007FF74CCF7C8A | 48:897C24 18             | mov qword ptr ss:[rsp+0x18],rdi                      
00007FF74CCF7C8F | 55                       | push rbp                                             
00007FF74CCF7C90 | 41:54                    | push r12                                             
00007FF74CCF7C92 | 41:55                    | push r13                                             
00007FF74CCF7C94 | 41:56                    | push r14                                             
00007FF74CCF7C96 | 41:57                    | push r15                                             
00007FF74CCF7C98 | 48:8D6C24 80             | lea rbp,qword ptr ss:[rsp-0x80]                      
00007FF74CCF7C9D | 48:81EC 80010000         | sub rsp,0x180                                        
00007FF74CCF7CA4 | 48:8B05 EDA41D00         | mov rax,qword ptr ds:[0x7FF74CED2198]                
00007FF74CCF7CAB | 48:33C4                  | xor rax,rsp                                          
00007FF74CCF7CAE | 48:8945 70               | mov qword ptr ss:[rbp+0x70],rax                      
00007FF74CCF7CB2 | 44:0FB6F9                | movzx r15d,cl                                        
00007FF74CCF7CB6 | 45:33ED                  | xor r13d,r13d                                        
00007FF74CCF7CB9 | 41:8BFD                  | mov edi,r13d                                         
00007FF74CCF7CBC | 44:896C24 48             | mov dword ptr ss:[rsp+0x48],r13d                     
00007FF74CCF7CC1 | 45:32E4                  | xor r12b,r12b                                        
00007FF74CCF7CC4 | F605 BDD21D00 01         | test byte ptr ds:[0x7FF74CED4F88],0x1                
```

```text
48 89 5C 24 08 48 89 74 24 10 48 89 7C 24 18 55 41 54 41 55 41 56 41 57 48 8D 6C 24 80 48 81 EC 80 01 00 00 48 8B 05 ED A4 1D 00 48 33 C4 48 89 45 70 44 0F B6 F9 45 33 ED 41 8B FD 44 89 6C 24 48 45 32 E4 F6 05 BD D2 1D 00 01
```