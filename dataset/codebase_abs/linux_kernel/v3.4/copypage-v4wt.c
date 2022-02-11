static void T_1
F_1 ( void * V_1 , const void * V_2 )
{
asm("\
stmfd sp!, {r4, lr} @ 2\n\
mov r2, %2 @ 1\n\
ldmia r1!, {r3, r4, ip, lr} @ 4\n\
1: stmia r0!, {r3, r4, ip, lr} @ 4\n\
ldmia r1!, {r3, r4, ip, lr} @ 4+1\n\
stmia r0!, {r3, r4, ip, lr} @ 4\n\
ldmia r1!, {r3, r4, ip, lr} @ 4\n\
stmia r0!, {r3, r4, ip, lr} @ 4\n\
ldmia r1!, {r3, r4, ip, lr} @ 4\n\
subs r2, r2, #1 @ 1\n\
stmia r0!, {r3, r4, ip, lr} @ 4\n\
ldmneia r1!, {r3, r4, ip, lr} @ 4\n\
bne 1b @ 1\n\
mcr p15, 0, r2, c7, c7, 0 @ flush ID cache\n\
ldmfd sp!, {r4, pc} @ 3"
:
: "r" (kto), "r" (kfrom), "I" (PAGE_SIZE / 64));
}
void F_2 ( struct V_3 * V_4 , struct V_3 * V_5 ,
unsigned long V_6 , struct V_7 * V_8 )
{
void * V_1 , * V_2 ;
V_1 = F_3 ( V_4 ) ;
V_2 = F_3 ( V_5 ) ;
F_1 ( V_1 , V_2 ) ;
F_4 ( V_2 ) ;
F_4 ( V_1 ) ;
}
void F_5 ( struct V_3 * V_3 , unsigned long V_6 )
{
void * V_9 , * V_10 = F_3 ( V_3 ) ;
asm volatile("\
mov r1, %2 @ 1\n\
mov r2, #0 @ 1\n\
mov r3, #0 @ 1\n\
mov ip, #0 @ 1\n\
mov lr, #0 @ 1\n\
1: stmia %0!, {r2, r3, ip, lr} @ 4\n\
stmia %0!, {r2, r3, ip, lr} @ 4\n\
stmia %0!, {r2, r3, ip, lr} @ 4\n\
stmia %0!, {r2, r3, ip, lr} @ 4\n\
subs r1, r1, #1 @ 1\n\
bne 1b @ 1\n\
mcr p15, 0, r2, c7, c7, 0 @ flush ID cache"
: "=r" (ptr)
: "0" (kaddr), "I" (PAGE_SIZE / 64)
: "r1", "r2", "r3", "ip", "lr");
F_4 ( V_10 ) ;
}
