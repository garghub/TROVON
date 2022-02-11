static void F_1 ( struct V_1 * V_2 ,
unsigned int V_3 )
{
if ( V_3 ) {
#if ! F_2 ( V_4 )
F_3 ( F_4 ( 3 ) , L_1 ) ;
F_5 ( F_4 ( 3 ) , 1 ) ;
F_6 ( F_4 ( 3 ) ) ;
#endif
F_3 ( F_7 ( 6 ) , L_2 ) ;
F_5 ( F_7 ( 6 ) , 1 ) ;
F_8 ( F_7 ( 6 ) , 0 ) ;
F_9 ( 10 ) ;
F_8 ( F_7 ( 6 ) , 1 ) ;
F_9 ( 10 ) ;
F_6 ( F_7 ( 6 ) ) ;
} else {
#if ! F_2 ( V_4 )
F_3 ( F_4 ( 3 ) , L_1 ) ;
F_5 ( F_4 ( 3 ) , 0 ) ;
F_6 ( F_4 ( 3 ) ) ;
#endif
}
}
static int F_10 ( struct V_5 * V_6 )
{
int V_7 ;
V_7 = F_3 ( F_4 ( 3 ) , L_3 ) ;
if ( V_7 ) {
F_11 ( V_8 L_4 ) ;
return V_7 ;
}
F_12 ( F_4 ( 3 ) , F_13 ( 2 ) ) ;
return 0 ;
}
static void F_14 ( struct V_5 * V_6 )
{
F_12 ( F_4 ( 3 ) , V_9 ) ;
F_6 ( F_4 ( 3 ) ) ;
}
static void T_1 F_15 ( void )
{
unsigned int V_10 ;
F_3 ( F_16 ( 5 ) , L_5 ) ;
F_12 ( F_16 ( 5 ) , F_13 ( 2 ) ) ;
F_6 ( F_16 ( 5 ) ) ;
V_10 = ( 5 << V_11 ) ;
F_17 ( V_10 , V_12 ) ;
V_10 = F_18 ( V_13 ) ;
V_10 &= ( V_14 << V_15 ) ;
V_10 |= ( 1 << V_15 ) ;
F_17 ( V_10 , V_13 ) ;
}
static void T_1 F_19 ( void )
{
F_20 ( NULL , 0 , V_16 ) ;
F_21 ( 24000000 ) ;
F_22 ( V_17 , F_23 ( V_17 ) ) ;
F_24 ( V_18 , V_19 ) ;
}
static void T_1 F_25 ( void )
{
F_26 () ;
F_15 () ;
F_27 ( & V_20 ) ;
F_28 ( & V_21 ) ;
F_29 ( NULL ) ;
F_30 ( NULL ) ;
F_31 ( NULL ) ;
F_32 ( 0 , V_22 ,
F_23 ( V_22 ) ) ;
F_32 ( 1 , V_23 ,
F_23 ( V_23 ) ) ;
F_32 ( 2 , V_24 ,
F_23 ( V_24 ) ) ;
F_33 ( & V_25 ) ;
F_34 ( & V_26 ) ;
F_35 ( V_27 , F_23 ( V_27 ) ) ;
}
