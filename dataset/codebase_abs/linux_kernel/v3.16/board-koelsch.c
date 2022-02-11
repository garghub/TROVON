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
static void T_1 F_5 ( unsigned V_12 )
{
unsigned V_13 = V_12 * 2 ;
F_6 ( V_13 >= F_2 ( V_14 ) ) ;
F_7 ( L_2 , V_12 ,
V_14 + V_13 , 2 ) ;
}
static void T_1 F_8 ( void )
{
F_9 () ;
F_10 ( V_15 ,
F_2 ( V_15 ) ) ;
F_11 () ;
F_12 () ;
F_4 ( & V_16 ) ;
F_13 ( & V_17 , L_3 , - 1 ,
& V_18 ,
sizeof( V_18 ) ) ;
F_13 ( & V_17 , L_4 , - 1 ,
& V_19 ,
sizeof( V_19 ) ) ;
F_14 ( & V_17 , L_5 , 0 ,
V_20 ,
F_2 ( V_20 ) ,
& V_21 , sizeof( V_21 ) ) ;
F_15 ( V_22 , F_2 ( V_22 ) ) ;
F_1 () ;
F_4 ( & V_23 ) ;
F_5 ( 1 ) ;
F_5 ( 2 ) ;
F_5 ( 4 ) ;
F_5 ( 5 ) ;
F_13 ( & V_17 , L_6 , 0 ,
& V_24 , sizeof( struct V_25 ) ) ;
F_13 ( & V_17 , L_6 , 1 ,
& V_26 , sizeof( struct V_25 ) ) ;
F_13 ( & V_17 , L_6 , 2 ,
& V_27 , sizeof( struct V_25 ) ) ;
F_13 ( & V_17 , L_7 , 0 ,
& V_28 , sizeof( struct V_29 ) ) ;
F_13 ( & V_17 , L_7 , 1 ,
& V_30 , sizeof( struct V_29 ) ) ;
F_13 ( & V_17 , L_7 , 2 ,
& V_31 , sizeof( struct V_29 ) ) ;
F_14 ( & V_17 , L_8 , 0 ,
V_32 , F_2 ( V_32 ) ,
& V_33 , sizeof( struct V_34 ) ) ;
F_14 ( & V_17 , L_8 , 1 ,
V_35 , F_2 ( V_35 ) ,
& V_36 , sizeof( struct V_34 ) ) ;
F_14 ( & V_17 , L_8 , 2 ,
V_37 , F_2 ( V_37 ) ,
& V_38 , sizeof( struct V_34 ) ) ;
}
static int F_16 ( struct V_39 * V_40 )
{
T_2 V_41 = F_17 ( V_40 , 0x1e ) ;
V_41 &= ~ 0xc000 ;
V_41 |= 0x4000 ;
return F_18 ( V_40 , 0x1e , V_41 ) ;
}
static void T_1 F_19 ( void )
{
F_8 () ;
F_20 ( F_21 ( 0 ) , V_42 ) ;
if ( F_22 ( V_43 ) )
F_23 ( L_9 ,
F_16 ) ;
}
