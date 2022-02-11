static void T_1
F_1 ( void * V_1 , const void * V_2 )
{
asm("\
stmfd sp!, {r4, r5, lr} \n\
mov lr, %2 \n\
\n\
pld [r1, #0] \n\
pld [r1, #32] \n\
1: pld [r1, #64] \n\
pld [r1, #96] \n\
\n\
2: ldrd r2, [r1], #8 \n\
mov ip, r0 \n\
ldrd r4, [r1], #8 \n\
mcr p15, 0, ip, c7, c6, 1 @ invalidate\n\
strd r2, [r0], #8 \n\
ldrd r2, [r1], #8 \n\
strd r4, [r0], #8 \n\
ldrd r4, [r1], #8 \n\
strd r2, [r0], #8 \n\
strd r4, [r0], #8 \n\
ldrd r2, [r1], #8 \n\
mov ip, r0 \n\
ldrd r4, [r1], #8 \n\
mcr p15, 0, ip, c7, c6, 1 @ invalidate\n\
strd r2, [r0], #8 \n\
ldrd r2, [r1], #8 \n\
subs lr, lr, #1 \n\
strd r4, [r0], #8 \n\
ldrd r4, [r1], #8 \n\
strd r2, [r0], #8 \n\
strd r4, [r0], #8 \n\
bgt 1b \n\
beq 2b \n\
\n\
ldmfd sp!, {r4, r5, pc}"
:
: "r" (kto), "r" (kfrom), "I" (PAGE_SIZE / 64 - 1));
}
void F_2 ( struct V_3 * V_4 , struct V_3 * V_5 ,
unsigned long V_6 , struct V_7 * V_8 )
{
void * V_1 , * V_2 ;
V_1 = F_3 ( V_4 ) ;
V_2 = F_3 ( V_5 ) ;
F_4 ( V_8 , V_6 , F_5 ( V_5 ) ) ;
F_1 ( V_1 , V_2 ) ;
F_6 ( V_2 ) ;
F_6 ( V_1 ) ;
}
void F_7 ( struct V_3 * V_3 , unsigned long V_6 )
{
void * V_9 , * V_10 = F_3 ( V_3 ) ;
asm volatile ("\
mov r1, %2 \n\
mov r2, #0 \n\
mov r3, #0 \n\
1: mcr p15, 0, %0, c7, c6, 1 @ invalidate line\n\
strd r2, [%0], #8 \n\
strd r2, [%0], #8 \n\
strd r2, [%0], #8 \n\
strd r2, [%0], #8 \n\
subs r1, r1, #1 \n\
bne 1b"
: "=r" (ptr)
: "0" (kaddr), "I" (PAGE_SIZE / 32)
: "r1", "r2", "r3");
F_6 ( V_10 ) ;
}
