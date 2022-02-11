static void F_1 ( void )
{
F_2 ( V_1 , 1 ) ;
}
static T_1 F_3 ( int V_2 , void * V_3 )
{
F_4 () ;
return V_4 ;
}
static T_1 F_5 ( int V_2 , void * V_3 )
{
F_6 () ;
return V_4 ;
}
static int T_2 F_7 ( void )
{
if ( ! F_8 () )
return 0 ;
return F_9 ( V_1 , L_1 ) ;
}
static void T_2 F_10 ( void )
{
V_5 = V_6 ;
F_11 () ;
}
static void T_2 F_12 ( void )
{
T_3 T_4 * V_7 ;
int V_8 ;
F_13 () ;
V_9 . V_10 = F_14 ( 0 ) ;
V_9 . V_11 =
F_14 ( 0 ) + V_12 - 1 ;
F_15 ( 0 , V_13 ,
F_16 ( V_13 ) ) ;
( void ) F_17 ( & V_14 ) ;
F_18 ( V_15 , F_16 ( V_15 ) ) ;
V_16 = F_1 ;
if ( F_19 ( F_20 ( V_17 ) , & F_5 ,
V_18 , L_2 , NULL ) < 0 ) {
F_21 ( V_19 L_3 ,
F_20 ( V_17 ) ) ;
}
if ( F_19 ( F_20 ( V_20 ) , & F_3 ,
V_21 , L_4 , NULL ) < 0 ) {
F_21 ( V_19 L_5 ,
F_20 ( V_20 ) ) ;
}
V_7 = F_22 ( F_14 ( 0 ) , 0x40000 ) ;
if ( V_7 ) {
for ( V_8 = 0 ; V_8 < 6 ; V_8 ++ )
#ifdef F_23
V_22 [ 0 ] . V_23 [ V_8 ] = F_24 ( V_7 + 0x3FFB0 + V_8 ) ;
#else
V_22 [ 0 ] . V_23 [ V_8 ] = F_24 ( V_7 + 0x3FFB0 + ( V_8 ^ 3 ) ) ;
#endif
F_25 ( V_7 ) ;
}
F_21 ( V_24 L_6 ,
V_22 [ 0 ] . V_23 ) ;
}
