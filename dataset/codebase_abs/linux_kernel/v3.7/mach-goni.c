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
F_11 ( V_6 , V_9 , L_3 ) ;
}
static void T_1 F_12 ( void )
{
int V_6 ;
V_6 = F_13 ( 3 ) ;
F_11 ( V_6 , V_9 , L_4 ) ;
F_14 ( V_6 , 0 ) ;
V_6 = F_15 ( 5 ) ;
F_4 ( V_6 , L_5 ) ;
F_16 ( V_6 ) ;
F_8 ( V_6 , F_9 ( 0xf ) ) ;
F_17 ( V_6 , V_10 ) ;
V_11 [ 0 ] . V_8 = F_10 ( V_6 ) ;
}
static void F_18 ( void )
{
F_19 ( V_12 ) ;
F_20 ( F_21 ( 3 ) , V_13 ) ;
}
static void T_1 F_22 ( void )
{
F_8 ( F_23 ( 7 ) , F_9 ( 0xf ) ) ;
F_17 ( F_23 ( 7 ) , V_10 ) ;
F_8 ( F_24 ( 6 ) , F_9 ( 0xf ) ) ;
F_17 ( F_24 ( 6 ) , V_10 ) ;
}
static void F_25 ( void )
{
F_26 ( & V_14 ) ;
F_27 ( & V_15 ) ;
F_28 ( & V_16 ) ;
}
static void T_1 F_29 ( void )
{
F_30 ( F_31 ( V_17 ) | ( 0x3 << 8 ) , V_17 ) ;
}
static void T_1 F_32 ( void )
{
F_33 ( NULL , 0 ) ;
F_34 ( V_18 . V_19 ) ;
F_35 ( V_20 , F_36 ( V_20 ) ) ;
F_37 ( V_21 , V_22 ) ;
}
static void T_1 F_38 ( void )
{
F_39 ( 0x43000000 , 8 << 20 , 0x51000000 , 8 << 20 ) ;
}
static void T_1 F_40 ( void )
{
F_6 () ;
F_41 ( NULL ) ;
F_42 ( NULL ) ;
F_43 ( 1 , V_7 , F_36 ( V_7 ) ) ;
F_12 () ;
F_44 ( & V_23 ) ;
F_43 ( 2 , V_11 , F_36 ( V_11 ) ) ;
F_22 () ;
F_43 ( V_24 , V_25 ,
F_36 ( V_25 ) ) ;
F_25 () ;
F_29 () ;
F_43 ( V_26 , V_27 ,
F_36 ( V_27 ) ) ;
F_45 ( & V_28 ) ;
F_46 ( & V_29 , sizeof( V_29 ) ,
& V_30 ) ;
F_47 ( & V_31 ) ;
F_18 () ;
F_48 ( V_32 , F_36 ( V_32 ) ) ;
F_49 ( & V_33 ) ;
F_50 ( V_34 , F_36 ( V_34 ) ) ;
}
