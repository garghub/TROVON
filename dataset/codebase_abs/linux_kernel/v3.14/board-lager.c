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
int V_12 = 0 ;
int V_13 = 0 ;
F_6 () ;
F_7 ( V_14 ,
F_2 ( V_14 ) ) ;
F_8 () ;
F_9 () ;
F_10 ( & V_15 , L_2 , - 1 ,
& V_16 ,
sizeof( V_16 ) ) ;
F_10 ( & V_15 , L_3 , - 1 ,
& V_17 ,
sizeof( V_17 ) ) ;
F_11 ( V_12 ++ ,
L_4 , V_18 ,
F_2 ( V_18 ) , 3300000 ) ;
F_12 ( & V_15 , L_5 , 1 ,
V_19 , F_2 ( V_19 ) ,
& V_20 , sizeof( V_20 ) ) ;
F_12 ( & V_15 , L_6 , - 1 ,
V_21 ,
F_2 ( V_21 ) ,
& V_22 , sizeof( V_22 ) ) ;
F_1 () ;
F_12 ( & V_15 , L_7 , 0 ,
V_23 ,
F_2 ( V_23 ) ,
& V_24 , sizeof( V_24 ) ) ;
F_13 ( V_25 , F_2 ( V_25 ) ) ;
F_10 ( & V_15 , L_8 , V_12 ++ ,
& V_26 , sizeof( struct V_27 ) ) ;
F_10 ( & V_15 , L_8 , V_12 ++ ,
& V_28 , sizeof( struct V_27 ) ) ;
F_10 ( & V_15 , L_9 , V_13 ++ ,
& V_29 , sizeof( struct V_30 ) ) ;
F_10 ( & V_15 , L_9 , V_13 ++ ,
& V_31 , sizeof( struct V_30 ) ) ;
}
static int F_14 ( struct V_32 * V_33 )
{
T_2 V_34 = F_15 ( V_33 , 0x1e ) ;
V_34 &= ~ 0xc000 ;
V_34 |= 0x4000 ;
return F_16 ( V_33 , 0x1e , V_34 ) ;
}
static void T_1 F_17 ( void )
{
F_5 () ;
if ( F_18 ( V_35 ) )
F_19 ( L_10 ,
F_14 ) ;
}
