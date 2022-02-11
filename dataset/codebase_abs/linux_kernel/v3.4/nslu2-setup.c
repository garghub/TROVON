static void F_1 ( void )
{
F_2 ( V_1 , V_2 ) ;
F_3 ( V_1 , V_3 ) ;
}
static T_1 F_4 ( int V_4 , void * V_5 )
{
F_5 () ;
return V_6 ;
}
static T_1 F_6 ( int V_4 , void * V_5 )
{
F_7 () ;
return V_6 ;
}
static void T_2 F_8 ( void )
{
V_7 = V_8 ;
F_9 () ;
}
static void T_2 F_10 ( void )
{
T_3 T_4 * V_9 ;
int V_10 ;
F_11 () ;
V_11 . V_12 = F_12 ( 0 ) ;
V_11 . V_13 =
F_12 ( 0 ) + V_14 - 1 ;
F_13 ( 0 , V_15 ,
F_14 ( V_15 ) ) ;
( void ) F_15 ( & V_16 ) ;
F_16 ( V_17 , F_14 ( V_17 ) ) ;
V_18 = F_1 ;
if ( F_17 ( F_18 ( V_19 ) , & F_6 ,
V_20 | V_21 ,
L_1 , NULL ) < 0 ) {
F_19 ( V_22 L_2 ,
F_18 ( V_19 ) ) ;
}
if ( F_17 ( F_18 ( V_23 ) , & F_4 ,
V_20 | V_24 ,
L_3 , NULL ) < 0 ) {
F_19 ( V_22 L_4 ,
F_18 ( V_23 ) ) ;
}
V_9 = F_20 ( F_12 ( 0 ) , 0x40000 ) ;
if ( V_9 ) {
for ( V_10 = 0 ; V_10 < 6 ; V_10 ++ )
#ifdef F_21
V_25 [ 0 ] . V_26 [ V_10 ] = F_22 ( V_9 + 0x3FFB0 + V_10 ) ;
#else
V_25 [ 0 ] . V_26 [ V_10 ] = F_22 ( V_9 + 0x3FFB0 + ( V_10 ^ 3 ) ) ;
#endif
F_23 ( V_9 ) ;
}
F_19 ( V_27 L_5 ,
V_25 [ 0 ] . V_26 ) ;
}
