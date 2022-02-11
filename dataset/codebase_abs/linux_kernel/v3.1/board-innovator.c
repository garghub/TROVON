static int F_1 ( void )
{
return ! ( F_2 ( V_1 ) & ( 1 << 5 ) ) ;
}
static void T_1 F_3 ( void )
{
if ( F_4 () ) {
F_5 ( F_2 ( V_2 ) & ~ 1 ,
V_2 ) ;
F_6 ( 750 ) ;
} else {
if ( F_7 ( 0 , L_1 ) < 0 ) {
F_8 ( L_2 ) ;
return;
}
}
}
static void T_1 F_9 ( void )
{
F_10 () ;
F_11 () ;
}
static int F_12 ( struct V_3 * V_4 , int V_5 , int V_6 ,
int V_7 )
{
if ( V_6 )
F_5 ( F_2 ( V_8 ) | ( 1 << 3 ) ,
V_8 ) ;
else
F_5 ( F_2 ( V_8 ) & ~ ( 1 << 3 ) ,
V_8 ) ;
return 0 ;
}
static void T_1 F_13 ( void )
{
V_9 [ 0 ] = & V_10 ;
F_14 ( V_9 , V_11 ) ;
}
static inline void F_13 ( void )
{
}
static void T_1 F_15 ( void )
{
if ( F_4 () )
F_16 () ;
F_3 () ;
#ifdef F_17
if ( F_4 () ) {
unsigned char V_12 ;
F_18 ( V_13 ) ;
F_18 ( V_14 ) ;
F_18 ( V_15 ) ;
F_18 ( V_16 ) ;
F_18 ( V_17 ) ;
F_18 ( V_18 ) ;
V_12 = F_2 ( V_8 ) ;
V_12 |= V_19 ;
F_5 ( V_12 , V_8 ) ;
F_6 ( 10 ) ;
V_12 = F_2 ( V_8 ) ;
V_12 |= V_20 ;
F_5 ( V_12 , V_8 ) ;
F_6 ( 10 ) ;
F_19 ( V_21 , F_20 ( V_21 ) ) ;
F_21 ( V_22 ,
F_20 ( V_22 ) ) ;
}
#endif
#ifdef F_22
if ( ! F_4 () ) {
F_19 ( V_23 , F_20 ( V_23 ) ) ;
}
#endif
#ifdef F_17
if ( F_4 () ) {
F_23 ( & V_24 ) ;
V_25 [ 1 ] . V_26 = & V_27 ;
}
#endif
#ifdef F_22
if ( F_24 () ) {
F_23 ( & V_28 ) ;
V_25 [ 1 ] . V_26 = & V_29 ;
}
#endif
V_30 = V_25 ;
V_31 = F_20 ( V_25 ) ;
F_25 () ;
F_26 ( 1 , 100 , NULL , 0 ) ;
F_13 () ;
}
static void T_1 F_27 ( void )
{
F_28 () ;
#ifdef F_17
if ( F_4 () ) {
F_29 ( V_32 , F_20 ( V_32 ) ) ;
F_6 ( 10 ) ;
F_8 ( L_3 ,
F_2 ( V_33 ) ,
F_2 ( V_34 ) ,
F_2 ( V_35 ) ) ;
}
#endif
}
