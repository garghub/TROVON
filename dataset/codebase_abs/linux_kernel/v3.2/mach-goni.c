static int F_1 ( struct V_1 * V_2 , int V_3 )
{
return 1 ;
}
static int F_2 ( struct V_1 * V_2 )
{
static unsigned int V_4 = 1 ;
int V_5 = - 1 ;
V_5 = F_3 ( 5 ) ;
if ( V_4 ) {
F_4 ( V_5 , L_1 ) ;
V_4 = 0 ;
}
F_5 ( V_5 , 1 ) ;
return 1 ;
}
static void T_1 F_6 ( void )
{
int V_6 ;
V_6 = F_7 ( 4 ) ;
F_4 ( V_6 , L_2 ) ;
F_8 ( V_6 , F_9 ( 0xf ) ) ;
V_7 [ 0 ] . V_8 = F_10 ( V_6 ) ;
V_6 = F_7 ( 5 ) ;
F_4 ( V_6 , L_3 ) ;
F_5 ( V_6 , 1 ) ;
}
static void T_1 F_11 ( void )
{
int V_6 ;
V_6 = F_12 ( 3 ) ;
F_4 ( V_6 , L_4 ) ;
F_5 ( V_6 , 1 ) ;
F_13 ( V_6 , 0 ) ;
V_6 = F_14 ( 5 ) ;
F_4 ( V_6 , L_5 ) ;
F_15 ( V_6 ) ;
F_8 ( V_6 , F_9 ( 0xf ) ) ;
F_16 ( V_6 , V_9 ) ;
V_10 [ 0 ] . V_8 = F_10 ( V_6 ) ;
}
static void F_17 ( void )
{
F_18 ( V_11 ) ;
F_19 ( F_20 ( 3 ) , V_12 ) ;
}
static void T_1 F_21 ( void )
{
F_8 ( F_22 ( 7 ) , F_9 ( 0xf ) ) ;
F_16 ( F_22 ( 7 ) , V_9 ) ;
F_8 ( F_23 ( 6 ) , F_9 ( 0xf ) ) ;
F_16 ( F_23 ( 6 ) , V_9 ) ;
}
static void F_24 ( void )
{
F_25 ( & V_13 ) ;
F_26 ( & V_14 ) ;
F_27 ( & V_15 ) ;
}
static void T_1 F_28 ( void )
{
F_29 ( F_30 ( V_16 ) | ( 0x3 << 8 ) , V_16 ) ;
}
static void T_1 F_31 ( void )
{
F_32 ( NULL , 0 , V_17 ) ;
F_33 ( 24000000 ) ;
F_34 ( V_18 , F_35 ( V_18 ) ) ;
F_36 ( V_19 , V_20 ) ;
}
static void T_1 F_37 ( void )
{
F_38 ( 0x43000000 , 8 << 20 , 0x51000000 , 8 << 20 ) ;
}
static void T_1 F_39 ( void )
{
F_6 () ;
F_40 ( NULL ) ;
F_41 ( NULL ) ;
F_42 ( 1 , V_7 , F_35 ( V_7 ) ) ;
F_11 () ;
F_43 ( & V_21 ) ;
F_42 ( 2 , V_10 , F_35 ( V_10 ) ) ;
F_21 () ;
F_42 ( V_22 , V_23 ,
F_35 ( V_23 ) ) ;
F_24 () ;
F_28 () ;
F_42 ( V_24 , V_25 ,
F_35 ( V_25 ) ) ;
F_44 ( & V_26 ) ;
F_45 ( & V_27 , sizeof( V_27 ) ,
& V_28 ) ;
F_17 () ;
F_46 ( V_29 , F_35 ( V_29 ) ) ;
F_47 ( & V_30 ) ;
V_31 . V_32 = 24000000 ;
F_48 ( V_33 , F_35 ( V_33 ) ) ;
}
