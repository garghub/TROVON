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
F_22 ( V_15 , F_23 ( V_15 ) ) ;
V_16 = 0 ;
V_17 = 24000000 ;
}
static void T_1 F_24 ( void )
{
F_11 ( F_25 ( 4 ) , L_5 ) ;
F_15 ( F_25 ( 4 ) , F_14 ( 0xf ) ) ;
F_17 ( F_25 ( 4 ) , V_13 ) ;
}
static void T_1 F_26 ( void )
{
F_27 ( 0x43000000 , 8 << 20 , 0x51000000 , 8 << 20 ) ;
}
static void T_1 F_28 ( void )
{
F_24 () ;
F_29 ( NULL ) ;
F_30 ( 0 , V_18 , F_23 ( V_18 ) ) ;
F_31 ( & V_19 ) ;
F_32 ( & V_20 ) ;
F_1 () ;
F_3 () ;
F_33 ( & V_21 ) ;
F_18 () ;
F_34 ( NULL ) ;
F_35 ( & V_22 , NULL , 0 ) ;
#ifdef F_36
V_23 . V_24 . V_25 = & V_26 ;
F_37 () ;
#else
F_38 ( & V_27 ) ;
#endif
F_39 ( V_28 , F_23 ( V_28 ) ) ;
F_40 ( V_29 , F_23 ( V_29 ) ) ;
F_41 ( & V_30 , & V_31 ) ;
F_10 () ;
}
