static void F_1 ( void )
{
V_1 = * ( volatile unsigned long * ) 0xfeff9820 ;
* ( volatile unsigned long * ) 0xfeff9820 = ~ ( 1 << ( V_2 + 16 ) ) & 0xfffe0000 ;
}
static void F_2 ( void )
{
* ( volatile unsigned long * ) 0xfeff9820 = V_1 ;
}
static int F_3 ( void )
{
return 1 ;
}
static int T_1 F_4 ( void )
{
V_3 = F_1 ;
V_4 = F_3 ;
V_5 = F_2 ;
return 0 ;
}
