.MODEL FLAT, STDCALL
includelib kernel32.lib

ExitProcess PROTO :DWORD
MessageBoxA PROTO : DWORD, : DWORD, : DWORD, : DWORD

.STACK 4096

.CONST

.DATA
    myWords WORD 8Ah, 3Bh, 44h, 5Fh, 99h           ; 2 байтаs
    massive DWORD 9, 1, 2, 3, 4, 5, 6, 0             ; 
    sumOfElements DWORD 0                          ; 

    ; Строки для MessageBoxA
    Str1 DB "Message", 0
    Str2 DB "Zero Element Found", 0
    Str3 DB "No Zero Element Found", 0

.CODE

main PROC
start:
    mov EDI, 4
    mov AX, [myWords + EDI]                         ; AX = myWords[4] = 44h
    mov BX, myWords[0]                              ; BX = myWords[0] = 8Ah

    ; Вычислить сумму элементов массива. Результат запомнить в регистре EAX.
    mov ESI, OFFSET massive
    mov ECX, LENGTHOF massive                        ; счетчик
    mov EBX, 1
    mov eax, 0                                       ; обнулить сумму

CYCLE:
    add eax, [ESI]                                   ; EAX = EAX + massive[ESI], ESI = massive[0]
    add ESI, TYPE massive                           ; +4 байта
    loop CYCLE                                       ; ECX--, если (ECX != 0) переходим к CYCLE

    ; Проверить наличие нулевого элемента
    mov ESI, OFFSET massive
    mov ECX, LENGTHOF massive
CHECK_ZERO:
    cmp dword ptr [ESI], 0                           ; сравнение с нулем
    je ZERO
    add ESI, TYPE massive                            ; +4 байта
    loop CHECK_ZERO                                  ; ECX--, если (ECX != 0) переходим к CHECK_ZERO

    ; Если программа дошла сюда, значит, нулевого элемента нет
    mov EBX, 0
    jmp ALLOK

ZERO:
    ; Если нашли нулевой элемент, выводим соответствующее сообщение
    INVOKE MessageBoxA, 0, OFFSET Str2, OFFSET Str1, 1

ALLOK:
    ; Завершить программу
    INVOKE ExitProcess, 2

main ENDP

end main
