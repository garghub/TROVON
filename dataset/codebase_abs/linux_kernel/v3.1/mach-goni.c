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
static void T_1 F_17 ( void )
{
F_8 ( F_18 ( 7 ) , F_9 ( 0xf ) ) ;
F_16 ( F_18 ( 7 ) , V_9 ) ;
F_8 ( F_19 ( 6 ) , F_9 ( 0xf ) ) ;
F_16 ( F_19 ( 6 ) , V_9 ) ;
}
static void F_20 ( void )
{
F_21 ( & V_11 ) ;
F_22 ( & V_12 ) ;
F_23 ( & V_13 ) ;
}
static void T_1 F_24 ( void )
{
F_25 ( F_26 ( V_14 ) | ( 0x3 << 8 ) , V_14 ) ;
}
static void T_1 F_27 ( void )
{
F_28 ( NULL , 0 , V_15 ) ;
F_29 ( 24000000 ) ;
F_30 ( V_16 , F_31 ( V_16 ) ) ;
F_32 ( V_17 , V_18 ) ;
}
static void T_1 F_33 ( void )
{
F_34 ( 0x43000000 , 8 << 20 , 0x51000000 , 8 << 20 ) ;
}
static void T_1 F_35 ( void )
{
F_6 () ;
F_36 ( NULL ) ;
F_37 ( NULL ) ;
F_38 ( 1 , V_7 , F_31 ( V_7 ) ) ;
F_11 () ;
F_39 ( & V_19 ) ;
F_38 ( 2 , V_10 , F_31 ( V_10 ) ) ;
F_17 () ;
F_38 ( V_20 , V_21 ,
F_31 ( V_21 ) ) ;
F_20 () ;
F_24 () ;
F_38 ( V_22 , V_23 ,
F_31 ( V_23 ) ) ;
F_40 ( & V_24 ) ;
F_41 ( V_25 , F_31 ( V_25 ) ) ;
F_42 ( & V_26 ) ;
V_27 . V_28 = 24000000 ;
F_43 ( V_29 , F_31 ( V_29 ) ) ;
}
