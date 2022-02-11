static int F_1 ( struct V_1 * V_2 , unsigned long V_3 , void * V_4 )
{
struct V_5 * V_6 = V_4 ;
switch ( V_3 ) {
case V_7 :
case V_8 :
F_2 ( V_6 ) ;
break;
case V_9 :
F_3 ( V_6 ) ;
break;
}
return V_10 ;
}
static T_1 T_2 F_4 ( void )
{
T_1 V_11 ;
__asm__ __volatile__ (
"mrc p15, 0, %0, c1, c0, 2\n\t"
: "=r" (value));
return V_11 ;
}
static void T_2 F_5 ( T_1 V_11 )
{
T_1 V_12 ;
__asm__ __volatile__ (
"mcr p15, 0, %1, c1, c0, 2\n\t"
"mrc p15, 0, %0, c1, c0, 2\n\t"
"mov %0, %0\n\t"
"sub pc, pc, #4\n\t"
: "=r" (temp) : "r" (value));
}
static int T_2 F_6 ( void )
{
T_1 V_13 ;
V_13 = F_4 () & ~ 0xf ;
F_5 ( V_13 ) ;
F_7 ( V_14 L_1 ) ;
V_15 |= V_16 ;
F_8 ( & V_17 ) ;
return 0 ;
}
