static void F_1 ( struct V_1 * V_2 ,
unsigned int V_3 )
{
if ( V_3 ) {
#if ! F_2 ( V_4 )
F_3 ( F_4 ( 3 ) , V_5 , L_1 ) ;
F_5 ( F_4 ( 3 ) ) ;
#endif
F_3 ( F_6 ( 6 ) , V_5 , L_2 ) ;
F_7 ( F_6 ( 6 ) , 0 ) ;
F_8 ( 10 ) ;
F_7 ( F_6 ( 6 ) , 1 ) ;
F_8 ( 10 ) ;
F_5 ( F_6 ( 6 ) ) ;
} else {
#if ! F_2 ( V_4 )
F_3 ( F_4 ( 3 ) , V_6 , L_1 ) ;
F_5 ( F_4 ( 3 ) ) ;
#endif
}
}
static void T_1 F_9 ( void )
{
unsigned int V_7 ;
F_10 ( F_11 ( 5 ) , L_3 ) ;
F_12 ( F_11 ( 5 ) , F_13 ( 2 ) ) ;
F_5 ( F_11 ( 5 ) ) ;
V_7 = ( 5 << V_8 ) ;
F_14 ( V_7 , V_9 ) ;
V_7 = F_15 ( V_10 ) ;
V_7 &= ( V_11 << V_12 ) ;
V_7 |= ( 1 << V_12 ) ;
F_14 ( V_7 , V_10 ) ;
}
static void T_1 F_16 ( void )
{
F_17 ( NULL , 0 ) ;
F_18 ( 24000000 ) ;
F_19 ( V_13 , F_20 ( V_13 ) ) ;
F_21 ( V_14 , V_15 ) ;
}
static void T_1 F_22 ( void )
{
F_23 () ;
F_9 () ;
F_24 ( & V_16 ) ;
F_25 ( NULL ) ;
F_26 ( NULL ) ;
F_27 ( NULL ) ;
F_28 ( NULL ) ;
F_29 ( 0 , V_17 ,
F_20 ( V_17 ) ) ;
F_29 ( 1 , V_18 ,
F_20 ( V_18 ) ) ;
F_29 ( 2 , V_19 ,
F_20 ( V_19 ) ) ;
F_30 ( & V_20 ) ;
F_31 ( & V_21 ) ;
F_32 ( & V_22 , & V_23 ) ;
F_33 ( V_24 , F_20 ( V_24 ) ) ;
}
