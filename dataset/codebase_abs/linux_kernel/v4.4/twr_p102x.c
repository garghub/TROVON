static void T_1 F_1 ( void )
{
struct V_1 * V_1 ;
#ifdef F_2
struct V_2 * V_3 ;
#endif
V_1 = F_3 ( NULL , 0 , V_4 |
V_5 ,
0 , 256 , L_1 ) ;
F_4 ( V_1 == NULL ) ;
F_5 ( V_1 ) ;
#ifdef F_2
V_3 = F_6 ( NULL , NULL , L_2 ) ;
if ( V_3 ) {
F_7 ( V_3 , 0 , V_6 ,
V_7 ) ;
F_8 ( V_3 ) ;
} else
F_9 ( L_3 ) ;
#endif
}
static void T_1 F_10 ( void )
{
#ifdef F_2
struct V_2 * V_3 ;
#endif
if ( V_8 . V_9 )
V_8 . V_9 ( L_4 , 0 ) ;
F_11 () ;
F_12 () ;
#ifdef F_2
F_13 () ;
F_14 () ;
#if F_15 ( V_10 ) || F_15 ( V_11 )
if ( F_16 ( V_12 ) ) {
struct V_13 T_2 * V_14 ;
V_3 = F_6 ( NULL , NULL , L_5 ) ;
if ( V_3 ) {
V_14 = F_17 ( V_3 , 0 ) ;
if ( ! V_14 )
F_9 ( L_6 ) ;
else {
F_18 ( & V_14 -> V_15 , F_19 ( 0 ) |
F_19 ( 3 ) |
F_19 ( 9 ) |
F_19 ( 12 ) ) ;
F_20 ( V_14 ) ;
#if F_15 ( V_11 )
F_21 ( 0 , 18 , 0 , 0 , 0 , 0 ) ;
#endif
F_21 ( 1 , 29 , 1 , 0 , 0 , 0 ) ;
F_22 ( 1 , 29 , 0 ) ;
}
F_8 ( V_3 ) ;
}
}
#endif
#endif
F_23 ( L_7 ) ;
}
static int T_1 F_24 ( void )
{
unsigned long V_16 = F_25 () ;
return F_26 ( V_16 , L_8 ) ;
}
