static int F_1 ( struct V_1 * V_2 , const T_1 * V_3 ,
unsigned int V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( ! F_3 () ||
( V_6 -> V_7 [ 0 ] % V_8 ) + V_4 < V_8 )
return F_4 ( V_2 , V_3 , V_4 ) ;
F_5 ( F_6 ( struct V_5 , V_9 ) != 0 ) ;
F_7 () ;
F_8 ( V_2 , V_3 , V_4 ,
( V_10 * ) V_11 ) ;
F_9 () ;
return 0 ;
}
static int F_10 ( struct V_1 * V_2 , const T_1 * V_3 ,
unsigned int V_4 , T_1 * V_12 )
{
if ( ! F_3 () )
return F_11 ( V_2 , V_3 , V_4 , V_12 ) ;
F_7 () ;
if ( V_4 )
F_8 ( V_2 , V_3 , V_4 ,
( V_10 * ) V_11 ) ;
F_12 ( V_2 , ( V_10 * ) V_11 ) ;
F_9 () ;
return F_13 ( V_2 , V_12 ) ;
}
static int F_14 ( struct V_1 * V_2 , T_1 * V_12 )
{
return F_10 ( V_2 , NULL , 0 , V_12 ) ;
}
static bool T_2 F_15 ( void )
{
T_3 V_13 ;
if ( ! V_14 || ! V_15 )
return false ;
V_13 = F_16 ( V_16 ) ;
if ( ( V_13 & ( V_17 | V_18 ) ) != ( V_17 | V_18 ) ) {
F_17 ( L_1 ) ;
return false ;
}
return true ;
}
static int T_2 F_18 ( void )
{
if ( V_19 )
V_11 = V_20 ;
#ifdef F_19
if ( F_15 () ) {
#ifdef F_20
if ( F_21 ( V_21 ) )
V_11 = V_22 ;
else
#endif
V_11 = V_23 ;
}
#endif
if ( V_11 ) {
#ifdef F_19
if ( V_11 == V_23 )
F_17 ( L_2 ) ;
#ifdef F_20
else if ( V_11 == V_22 )
F_17 ( L_3 ) ;
#endif
else
#endif
F_17 ( L_4 ) ;
return F_22 ( V_24 , F_23 ( V_24 ) ) ;
}
F_17 ( L_5 ) ;
return - V_25 ;
}
static void T_4 F_24 ( void )
{
F_25 ( V_24 , F_23 ( V_24 ) ) ;
}
