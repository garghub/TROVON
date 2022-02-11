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
static void T_1 F_18 ( void )
{
F_8 ( F_19 ( 7 ) , F_9 ( 0xf ) ) ;
F_17 ( F_19 ( 7 ) , V_10 ) ;
F_8 ( F_20 ( 6 ) , F_9 ( 0xf ) ) ;
F_17 ( F_20 ( 6 ) , V_10 ) ;
}
static void F_21 ( void )
{
F_22 ( & V_12 ) ;
F_23 ( & V_13 ) ;
F_24 ( & V_14 ) ;
}
static void T_1 F_25 ( void )
{
F_26 ( F_27 ( V_15 ) | ( 0x3 << 8 ) , V_15 ) ;
}
static void T_1 F_28 ( void )
{
F_29 ( NULL , 0 ) ;
F_30 ( V_16 . V_17 ) ;
F_31 ( V_18 , F_32 ( V_18 ) ) ;
F_33 ( V_19 , V_20 ) ;
}
static void T_1 F_34 ( void )
{
F_35 ( 0x43000000 , 8 << 20 , 0x51000000 , 8 << 20 ) ;
}
static void T_1 F_36 ( void )
{
F_6 () ;
F_37 ( NULL ) ;
F_38 ( NULL ) ;
F_39 ( 1 , V_7 , F_32 ( V_7 ) ) ;
F_12 () ;
F_40 ( & V_21 ) ;
F_39 ( 2 , V_11 , F_32 ( V_11 ) ) ;
F_18 () ;
F_39 ( V_22 , V_23 ,
F_32 ( V_23 ) ) ;
F_21 () ;
F_25 () ;
F_39 ( V_24 , V_25 ,
F_32 ( V_25 ) ) ;
F_41 ( & V_26 ) ;
F_42 ( & V_27 ) ;
F_43 ( V_28 , F_32 ( V_28 ) ) ;
F_44 ( & V_29 ) ;
F_45 ( V_30 , F_32 ( V_30 ) ) ;
}
