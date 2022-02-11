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
F_1 ( V_5 , V_4 , 0 ) ;
return 0 ;
}
void F_3 ( struct V_6 * V_7 )
{
F_4 ( & V_8 ) ;
}
void F_5 ( void )
{
struct V_9 * V_10 ;
struct V_6 V_11 ;
int V_12 ;
V_10 = F_6 ( NULL , NULL , L_1 ) ;
if ( ! V_10 )
return;
V_12 = F_7 ( V_10 , L_2 ,
& V_11 . V_13 ) ;
if ( V_12 != 0 )
F_8 ( L_3 ) ;
V_12 = F_7 ( V_10 , L_4 ,
& V_11 . V_14 ) ;
if ( V_12 != 0 )
F_8 ( L_5 ) ;
F_3 ( & V_11 ) ;
}
