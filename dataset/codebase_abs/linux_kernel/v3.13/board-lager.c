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
& V_14 ,
sizeof( V_14 ) ) ;
F_10 ( & V_13 , L_3 , - 1 ,
& V_15 ,
sizeof( V_15 ) ) ;
F_11 ( 0 , L_4 , V_16 ,
F_2 ( V_16 ) , 3300000 ) ;
F_12 ( & V_13 , L_5 , 1 ,
V_17 , F_2 ( V_17 ) ,
& V_18 , sizeof( V_18 ) ) ;
F_12 ( & V_13 , L_6 , - 1 ,
V_19 ,
F_2 ( V_19 ) ,
& V_20 , sizeof( V_20 ) ) ;
F_1 () ;
}
static int F_13 ( struct V_21 * V_22 )
{
T_2 V_23 = F_14 ( V_22 , 0x1e ) ;
V_23 &= ~ 0xc000 ;
V_23 |= 0x4000 ;
return F_15 ( V_22 , 0x1e , V_23 ) ;
}
static void T_1 F_16 ( void )
{
F_5 () ;
if ( F_17 ( V_24 ) )
F_18 ( L_7 ,
F_13 ) ;
}
