static void T_1
F_1 ( void * V_1 , const void * V_2 )
{
asm("\
stmfd sp!, {r4-r9, lr} \n\
mov ip, %2 \n\
1: mov lr, r1 \n\
ldmia r1!, {r2 - r9} \n\
pld [lr, #32] \n\
pld [lr, #64] \n\
pld [lr, #96] \n\
pld [lr, #128] \n\
pld [lr, #160] \n\
pld [lr, #192] \n\
pld [lr, #224] \n\
stmia r0, {r2 - r9} \n\
ldmia r1!, {r2 - r9} \n\
mcr p15, 0, r0, c7, c14, 1 @ clean and invalidate D line\n\
add r0, r0, #32 \n\
stmia r0, {r2 - r9} \n\
ldmia r1!, {r2 - r9} \n\
mcr p15, 0, r0, c7, c14, 1 @ clean and invalidate D line\n\
add r0, r0, #32 \n\
stmia r0, {r2 - r9} \n\
ldmia r1!, {r2 - r9} \n\
mcr p15, 0, r0, c7, c14, 1 @ clean and invalidate D line\n\
add r0, r0, #32 \n\
stmia r0, {r2 - r9} \n\
ldmia r1!, {r2 - r9} \n\
mcr p15, 0, r0, c7, c14, 1 @ clean and invalidate D line\n\
add r0, r0, #32 \n\
stmia r0, {r2 - r9} \n\
ldmia r1!, {r2 - r9} \n\
mcr p15, 0, r0, c7, c14, 1 @ clean and invalidate D line\n\
add r0, r0, #32 \n\
stmia r0, {r2 - r9} \n\
ldmia r1!, {r2 - r9} \n\
mcr p15, 0, r0, c7, c14, 1 @ clean and invalidate D line\n\
add r0, r0, #32 \n\
stmia r0, {r2 - r9} \n\
ldmia r1!, {r2 - r9} \n\
mcr p15, 0, r0, c7, c14, 1 @ clean and invalidate D line\n\
add r0, r0, #32 \n\
stmia r0, {r2 - r9} \n\
subs ip, ip, #(32 * 8) \n\
mcr p15, 0, r0, c7, c14, 1 @ clean and invalidate D line\n\
add r0, r0, #32 \n\
bne 1b \n\
mcr p15, 0, ip, c7, c10, 4 @ drain WB\n\
ldmfd sp!, {r4-r9, pc}"
:
: "r" (kto), "r" (kfrom), "I" (PAGE_SIZE));
}
void F_2 ( struct V_3 * V_4 , struct V_3 * V_5 ,
unsigned long V_6 , struct V_7 * V_8 )
{
void * V_1 , * V_2 ;
V_1 = F_3 ( V_4 , V_9 ) ;
V_2 = F_3 ( V_5 , V_10 ) ;
F_4 ( V_8 , V_6 , F_5 ( V_5 ) ) ;
F_1 ( V_1 , V_2 ) ;
F_6 ( V_2 , V_10 ) ;
F_6 ( V_1 , V_9 ) ;
}
void F_7 ( struct V_3 * V_3 , unsigned long V_6 )
{
void * V_11 , * V_12 = F_3 ( V_3 , V_9 ) ;
asm volatile ("\
mov r1, %2 \n\
mov r2, #0 \n\
mov r3, #0 \n\
mov r4, #0 \n\
mov r5, #0 \n\
mov r6, #0 \n\
mov r7, #0 \n\
mov ip, #0 \n\
mov lr, #0 \n\
1: stmia %0, {r2-r7, ip, lr} \n\
subs r1, r1, #1 \n\
mcr p15, 0, %0, c7, c14, 1 @ clean and invalidate D line\n\
add %0, %0, #32 \n\
bne 1b \n\
mcr p15, 0, r1, c7, c10, 4 @ drain WB"
: "=r" (ptr)
: "0" (kaddr), "I" (PAGE_SIZE / 32)
: "r1", "r2", "r3", "r4", "r5", "r6", "r7", "ip", "lr");
F_6 ( V_12 , V_9 ) ;
}
