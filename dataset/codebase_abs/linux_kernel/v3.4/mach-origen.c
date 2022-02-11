static void T_1 F_1 ( void )
{
struct V_1 * V_2 = & V_3 ;
F_2 ( V_2 ) ;
}
static void T_1 F_3 ( void )
{
struct V_4 * V_2 = & V_5 ;
F_4 ( V_2 ) ;
}
static void F_5 ( struct V_6 * V_7 , unsigned int V_8 )
{
int V_9 ;
if ( V_8 )
V_9 = F_6 ( F_7 ( 4 ) ,
V_10 , L_1 ) ;
else
V_9 = F_6 ( F_7 ( 4 ) ,
V_11 , L_1 ) ;
F_8 ( F_7 ( 4 ) ) ;
if ( V_9 )
F_9 ( L_2 , V_9 ) ;
}
static void T_1 F_10 ( void )
{
F_11 ( F_12 ( 0 ) , L_3 ) ;
F_13 ( F_12 ( 0 ) , 4 , F_14 ( 2 ) ) ;
F_15 ( F_16 ( 2 ) , V_12 ) ;
F_17 ( F_16 ( 2 ) , V_13 ) ;
}
static void F_18 ( void )
{
F_6 ( F_19 ( 7 ) , V_14 , L_4 ) ;
F_15 ( F_19 ( 7 ) , F_14 ( 0x3 ) ) ;
F_17 ( F_19 ( 7 ) , V_13 ) ;
}
static void T_1 F_20 ( void )
{
F_21 ( NULL , 0 ) ;
F_22 ( 24000000 ) ;
F_23 ( V_15 , F_24 ( V_15 ) ) ;
}
static void T_1 F_25 ( void )
{
F_11 ( F_26 ( 4 ) , L_5 ) ;
F_15 ( F_26 ( 4 ) , F_14 ( 0xf ) ) ;
F_17 ( F_26 ( 4 ) , V_13 ) ;
}
static void T_1 F_27 ( void )
{
F_28 ( 0x43000000 , 8 << 20 , 0x51000000 , 8 << 20 ) ;
}
static void T_1 F_29 ( void )
{
F_25 () ;
F_30 ( NULL ) ;
F_31 ( 0 , V_16 , F_24 ( V_16 ) ) ;
F_32 ( & V_17 ) ;
F_33 ( & V_18 ) ;
F_1 () ;
F_3 () ;
V_19 . V_20 = 24000000 ;
F_18 () ;
F_34 ( NULL ) ;
F_35 ( & V_21 ) ;
F_36 ( V_22 , F_24 ( V_22 ) ) ;
F_37 ( & V_23 , & V_24 ) ;
F_10 () ;
}
