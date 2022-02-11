static void T_1 F_1 ( void )
{
struct V_1 V_2 = {
. V_3 = L_1 ,
. V_4 = - 1 ,
. V_5 = V_6 ,
. V_7 = F_2 ( V_6 ) ,
. V_8 = & V_9 ,
. V_10 = sizeof( V_9 ) ,
. V_11 = F_3 ( 32 ) ,
} ;
F_4 ( & V_2 ) ;
}
static void T_1 F_5 ( void )
{
F_6 () ;
F_7 ( V_12 ,
F_2 ( V_12 ) ) ;
F_8 () ;
F_9 () ;
F_10 ( & V_13 , L_2 , - 1 ,
V_14 ,
F_2 ( V_14 ) ,
& V_15 , sizeof( V_15 ) ) ;
F_11 ( & V_13 , L_3 , - 1 ,
& V_16 ,
sizeof( V_16 ) ) ;
F_11 ( & V_13 , L_4 , - 1 ,
& V_17 ,
sizeof( V_17 ) ) ;
F_1 () ;
}
static int F_12 ( struct V_18 * V_19 )
{
T_2 V_20 = F_13 ( V_19 , 0x1e ) ;
V_20 &= ~ 0xc000 ;
V_20 |= 0x4000 ;
return F_14 ( V_19 , 0x1e , V_20 ) ;
}
static void T_1 F_15 ( void )
{
F_5 () ;
if ( F_16 ( V_21 ) )
F_17 ( L_5 ,
F_12 ) ;
}
