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
static int F_9 ( struct V_3 * V_4 , int V_5 , int V_6 ,
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
static void T_1 F_10 ( void )
{
V_9 [ 0 ] = & V_10 ;
F_11 ( V_9 , V_11 ) ;
}
static inline void F_10 ( void )
{
}
static void T_1 F_12 ( void )
{
if ( F_4 () )
F_13 () ;
F_3 () ;
#ifdef F_14
if ( F_4 () ) {
unsigned char V_12 ;
F_15 ( V_13 ) ;
F_15 ( V_14 ) ;
F_15 ( V_15 ) ;
F_15 ( V_16 ) ;
F_15 ( V_17 ) ;
F_15 ( V_18 ) ;
V_12 = F_2 ( V_8 ) ;
V_12 |= V_19 ;
F_5 ( V_12 , V_8 ) ;
F_6 ( 10 ) ;
V_12 = F_2 ( V_8 ) ;
V_12 |= V_20 ;
F_5 ( V_12 , V_8 ) ;
F_6 ( 10 ) ;
F_16 ( V_21 , F_17 ( V_21 ) ) ;
F_18 ( V_22 ,
F_17 ( V_22 ) ) ;
}
#endif
#ifdef F_19
if ( ! F_4 () ) {
F_16 ( V_23 , F_17 ( V_23 ) ) ;
}
#endif
#ifdef F_14
if ( F_4 () ) {
F_20 ( & V_24 ) ;
V_25 [ 0 ] . V_26 = & V_27 ;
}
#endif
#ifdef F_19
if ( F_21 () ) {
F_20 ( & V_28 ) ;
V_25 [ 0 ] . V_26 = & V_29 ;
}
#endif
V_30 = V_25 ;
V_31 = F_17 ( V_25 ) ;
F_22 () ;
F_23 ( 1 , 100 , NULL , 0 ) ;
F_10 () ;
}
static void T_1 F_24 ( void )
{
F_25 () ;
F_26 ( V_32 , F_17 ( V_32 ) ) ;
F_6 ( 10 ) ;
F_27 ( L_3 ,
F_2 ( V_33 ) ,
F_2 ( V_34 ) ,
F_2 ( V_35 ) ) ;
}
