static void T_1 F_1 ( T_2 type , T_2 V_1 , T_2 V_2 )
{
asm volatile(
".arch_extension sec\n\t"
"stmfd sp!, {r4 - r11, lr}\n\t"
__asmeq("%0", "r0")
__asmeq("%1", "r1")
__asmeq("%2", "r2")
"mov r3, #0\n\t"
"mov r4, #0\n\t"
"smc #0\n\t"
"ldmfd sp!, {r4 - r11, pc}"
:
: "r" (type), "r" (arg1), "r" (arg2)
: "memory");
}
static int F_2 ( int V_3 , unsigned long V_4 )
{
V_5 = V_4 ;
F_1 ( V_6 , V_5 , 0 ) ;
return 0 ;
}
static int F_3 ( void )
{
F_1 ( V_7 , V_8 , V_5 ) ;
return 0 ;
}
void F_4 ( struct V_9 * V_10 )
{
F_5 ( & V_11 ) ;
}
void F_6 ( void )
{
struct V_12 * V_13 ;
struct V_9 V_14 ;
int V_15 ;
V_13 = F_7 ( NULL , NULL , L_1 ) ;
if ( ! V_13 )
return;
V_15 = F_8 ( V_13 , L_2 ,
& V_14 . V_16 ) ;
if ( V_15 != 0 )
F_9 ( L_3 ) ;
V_15 = F_8 ( V_13 , L_4 ,
& V_14 . V_17 ) ;
if ( V_15 != 0 )
F_9 ( L_5 ) ;
F_4 ( & V_14 ) ;
}
