.MODEL FLAT, STDCALL
includelib kernel32.lib

ExitProcess PROTO :DWORD
MessageBoxA PROTO : DWORD, : DWORD, : DWORD, : DWORD

.STACK 4096

.CONST

.DATA
    myWords WORD 8Ah, 3Bh, 44h, 5Fh, 99h           ; 2 �����s
    massive DWORD 9, 1, 2, 3, 4, 5, 6, 0             ; 
    sumOfElements DWORD 0                          ; 

    ; ������ ��� MessageBoxA
    Str1 DB "Message", 0
    Str2 DB "Zero Element Found", 0
    Str3 DB "No Zero Element Found", 0

.CODE

main PROC
start:
    mov EDI, 4
    mov AX, [myWords + EDI]                         ; AX = myWords[4] = 44h
    mov BX, myWords[0]                              ; BX = myWords[0] = 8Ah

    ; ��������� ����� ��������� �������. ��������� ��������� � �������� EAX.
    mov ESI, OFFSET massive
    mov ECX, LENGTHOF massive                        ; �������
    mov EBX, 1
    mov eax, 0                                       ; �������� �����

CYCLE:
    add eax, [ESI]                                   ; EAX = EAX + massive[ESI], ESI = massive[0]
    add ESI, TYPE massive                           ; +4 �����
    loop CYCLE                                       ; ECX--, ���� (ECX != 0) ��������� � CYCLE

    ; ��������� ������� �������� ��������
    mov ESI, OFFSET massive
    mov ECX, LENGTHOF massive
CHECK_ZERO:
    cmp dword ptr [ESI], 0                           ; ��������� � �����
    je ZERO
    add ESI, TYPE massive                            ; +4 �����
    loop CHECK_ZERO                                  ; ECX--, ���� (ECX != 0) ��������� � CHECK_ZERO

    ; ���� ��������� ����� ����, ������, �������� �������� ���
    mov EBX, 0
    jmp ALLOK

ZERO:
    ; ���� ����� ������� �������, ������� ��������������� ���������
    INVOKE MessageBoxA, 0, OFFSET Str2, OFFSET Str1, 1

ALLOK:
    ; ��������� ���������
    INVOKE ExitProcess, 2

main ENDP

end main
