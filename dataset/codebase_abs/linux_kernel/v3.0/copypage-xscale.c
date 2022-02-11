static void T_1
F_1 ( void * V_1 , void * V_2 )
{
asm volatile(
"stmfd sp!, {r4, r5, lr} \n\
mov lr, %2 \n\
pld [r0, #0] \n\
pld [r0, #32] \n\
pld [r1, #0] \n\
pld [r1, #32] \n\
1: pld [r0, #64] \n\
pld [r0, #96] \n\
pld [r1, #64] \n\
pld [r1, #96] \n\
2: ldrd r2, [r0], #8 \n\
ldrd r4, [r0], #8 \n\
mov ip, r1 \n\
strd r2, [r1], #8 \n\
ldrd r2, [r0], #8 \n\
strd r4, [r1], #8 \n\
ldrd r4, [r0], #8 \n\
strd r2, [r1], #8 \n\
strd r4, [r1], #8 \n\
mcr p15, 0, ip, c7, c10, 1 @ clean D line\n\
ldrd r2, [r0], #8 \n\
mcr p15, 0, ip, c7, c6, 1 @ invalidate D line\n\
ldrd r4, [r0], #8 \n\
mov ip, r1 \n\
strd r2, [r1], #8 \n\
ldrd r2, [r0], #8 \n\
strd r4, [r1], #8 \n\
ldrd r4, [r0], #8 \n\
strd r2, [r1], #8 \n\
strd r4, [r1], #8 \n\
mcr p15, 0, ip, c7, c10, 1 @ clean D line\n\
subs lr, lr, #1 \n\
mcr p15, 0, ip, c7, c6, 1 @ invalidate D line\n\
bgt 1b \n\
beq 2b \n\
ldmfd sp!, {r4, r5, pc} "
:
: "r" (from), "r" (to), "I" (PAGE_SIZE / 64 - 1));
}
void F_2 ( struct V_3 * V_2 , struct V_3 * V_1 ,
unsigned long V_4 , struct V_5 * V_6 )
{
void * V_7 = F_3 ( V_2 , V_8 ) ;
if ( ! F_4 ( V_9 , & V_1 -> V_10 ) )
F_5 ( F_6 ( V_1 ) , V_1 ) ;
F_7 ( & V_11 ) ;
F_8 ( F_9 ( V_12 ) , F_10 ( F_11 ( V_1 ) , V_13 ) , 0 ) ;
F_12 ( V_12 ) ;
F_1 ( ( void * ) V_12 , V_7 ) ;
F_13 ( & V_11 ) ;
F_14 ( V_7 , V_8 ) ;
}
void
F_15 ( struct V_3 * V_3 , unsigned long V_4 )
{
void * V_14 , * V_15 = F_3 ( V_3 , V_16 ) ;
asm volatile(
"mov r1, %2 \n\
mov r2, #0 \n\
mov r3, #0 \n\
1: mov ip, %0 \n\
strd r2, [%0], #8 \n\
strd r2, [%0], #8 \n\
strd r2, [%0], #8 \n\
strd r2, [%0], #8 \n\
mcr p15, 0, ip, c7, c10, 1 @ clean D line\n\
subs r1, r1, #1 \n\
mcr p15, 0, ip, c7, c6, 1 @ invalidate D line\n\
bne 1b"
: "=r" (ptr)
: "0" (kaddr), "I" (PAGE_SIZE / 32)
: "r1", "r2", "r3", "ip");
F_14 ( V_15 , V_16 ) ;
}
