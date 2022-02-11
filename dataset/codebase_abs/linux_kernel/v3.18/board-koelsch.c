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
F_13 ( NULL , L_3 , - 1 ,
& V_17 ,
sizeof( V_17 ) ) ;
F_13 ( NULL , L_4 , - 1 ,
& V_18 ,
sizeof( V_18 ) ) ;
F_14 ( NULL , L_5 , 0 ,
V_19 ,
F_2 ( V_19 ) ,
& V_20 , sizeof( V_20 ) ) ;
F_15 ( V_21 , F_2 ( V_21 ) ) ;
F_1 () ;
F_4 ( & V_22 ) ;
F_5 ( 1 ) ;
F_5 ( 2 ) ;
F_5 ( 4 ) ;
F_5 ( 5 ) ;
F_13 ( NULL , L_6 , 0 ,
& V_23 , sizeof( struct V_24 ) ) ;
F_13 ( NULL , L_6 , 1 ,
& V_25 , sizeof( struct V_24 ) ) ;
F_13 ( NULL , L_6 , 2 ,
& V_26 , sizeof( struct V_24 ) ) ;
F_13 ( NULL , L_7 , 0 ,
& V_27 , sizeof( struct V_28 ) ) ;
F_13 ( NULL , L_7 , 1 ,
& V_29 , sizeof( struct V_28 ) ) ;
F_13 ( NULL , L_7 , 2 ,
& V_30 , sizeof( struct V_28 ) ) ;
F_14 ( NULL , L_8 , 0 ,
V_31 , F_2 ( V_31 ) ,
& V_32 , sizeof( struct V_33 ) ) ;
F_14 ( NULL , L_8 , 1 ,
V_34 , F_2 ( V_34 ) ,
& V_35 , sizeof( struct V_33 ) ) ;
F_14 ( NULL , L_8 , 2 ,
V_36 , F_2 ( V_36 ) ,
& V_37 , sizeof( struct V_33 ) ) ;
}
static int F_16 ( struct V_38 * V_39 )
{
T_2 V_40 = F_17 ( V_39 , 0x1e ) ;
V_40 &= ~ 0xc000 ;
V_40 |= 0x4000 ;
return F_18 ( V_39 , 0x1e , V_40 ) ;
}
static void T_1 F_19 ( void )
{
F_8 () ;
F_20 ( F_21 ( 0 ) , V_41 ) ;
if ( F_22 ( V_42 ) )
F_23 ( L_9 ,
F_16 ) ;
}
