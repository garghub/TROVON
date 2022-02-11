static void T_1
F_1 ( void * V_1 , void * V_2 )
{
asm volatile(
"stmfd sp!, {r4, lr} @ 2\n\
mov r4, %2 @ 1\n\
ldmia %0!, {r2, r3, ip, lr} @ 4\n\
1: mcr p15, 0, %1, c7, c6, 1 @ 1 invalidate D line\n\
stmia %1!, {r2, r3, ip, lr} @ 4\n\
ldmia %0!, {r2, r3, ip, lr} @ 4+1\n\
stmia %1!, {r2, r3, ip, lr} @ 4\n\
ldmia %0!, {r2, r3, ip, lr} @ 4\n\
mcr p15, 0, %1, c7, c6, 1 @ 1 invalidate D line\n\
stmia %1!, {r2, r3, ip, lr} @ 4\n\
ldmia %0!, {r2, r3, ip, lr} @ 4\n\
subs r4, r4, #1 @ 1\n\
stmia %1!, {r2, r3, ip, lr} @ 4\n\
ldmneia %0!, {r2, r3, ip, lr} @ 4\n\
bne 1b @ 1\n\
ldmfd sp!, {r4, pc} @ 3"
:
: "r" (from), "r" (to), "I" (PAGE_SIZE / 64));
}
void F_2 ( struct V_3 * V_2 , struct V_3 * V_1 ,
unsigned long V_4 , struct V_5 * V_6 )
{
void * V_7 = F_3 ( V_2 ) ;
if ( ! F_4 ( V_8 , & V_1 -> V_9 ) )
F_5 ( F_6 ( V_1 ) , V_1 ) ;
F_7 ( & V_10 ) ;
F_8 ( V_11 , F_9 ( V_1 , V_12 ) ) ;
F_1 ( ( void * ) V_11 , V_7 ) ;
F_10 ( & V_10 ) ;
F_11 ( V_7 ) ;
}
void F_12 ( struct V_3 * V_3 , unsigned long V_4 )
{
void * V_13 , * V_14 = F_3 ( V_3 ) ;
asm volatile("\
mov r1, %2 @ 1\n\
mov r2, #0 @ 1\n\
mov r3, #0 @ 1\n\
mov ip, #0 @ 1\n\
mov lr, #0 @ 1\n\
1: mcr p15, 0, %0, c7, c6, 1 @ 1 invalidate D line\n\
stmia %0!, {r2, r3, ip, lr} @ 4\n\
stmia %0!, {r2, r3, ip, lr} @ 4\n\
mcr p15, 0, %0, c7, c6, 1 @ 1 invalidate D line\n\
stmia %0!, {r2, r3, ip, lr} @ 4\n\
stmia %0!, {r2, r3, ip, lr} @ 4\n\
subs r1, r1, #1 @ 1\n\
bne 1b @ 1"
: "=r" (ptr)
: "0" (kaddr), "I" (PAGE_SIZE / 64)
: "r1", "r2", "r3", "ip", "lr");
F_11 ( V_14 ) ;
}
