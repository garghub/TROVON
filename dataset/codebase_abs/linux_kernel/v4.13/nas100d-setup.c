static void F_1 ( void )
{
F_2 ( V_1 , 1 ) ;
}
static void F_3 ( unsigned long V_2 )
{
if ( F_4 ( V_3 ) ) {
if ( V_4 > 0 )
V_4 -- ;
} else {
if ( V_4 == 0 ) {
F_5 () ;
F_6 ( V_5 , 0 ) ;
} else {
V_4 = V_6 ;
}
}
F_7 ( & V_7 , V_8 + F_8 ( 500 ) ) ;
}
static T_1 F_9 ( int V_9 , void * V_10 )
{
F_10 () ;
return V_11 ;
}
static int T_2 F_11 ( void )
{
if ( ! F_12 () )
return 0 ;
F_13 ( V_1 , L_1 ) ;
F_13 ( V_3 , L_2 ) ;
F_14 ( V_3 ) ;
V_4 = V_6 ;
F_7 ( & V_7 , V_8 + F_8 ( 500 ) ) ;
return 0 ;
}
static void T_2 F_15 ( void )
{
T_3 T_4 * V_12 ;
int V_13 ;
F_16 () ;
* V_14 = 0 ;
V_15 . V_16 = F_17 ( 0 ) ;
V_15 . V_17 =
F_17 ( 0 ) + V_18 - 1 ;
F_18 ( 0 , V_19 ,
F_19 ( V_19 ) ) ;
( void ) F_20 ( & V_20 ) ;
F_21 ( V_21 , F_19 ( V_21 ) ) ;
V_22 = F_1 ;
if ( F_22 ( F_23 ( V_23 ) , & F_9 ,
V_24 , L_3 , NULL ) < 0 ) {
F_24 ( V_25 L_4 ,
F_23 ( V_23 ) ) ;
}
V_12 = F_25 ( F_17 ( 0 ) , 0x1000000 ) ;
if ( V_12 ) {
for ( V_13 = 0 ; V_13 < 6 ; V_13 ++ )
#ifdef F_26
V_26 [ 0 ] . V_27 [ V_13 ] = F_27 ( V_12 + 0xFC0FD8 + V_13 ) ;
#else
V_26 [ 0 ] . V_27 [ V_13 ] = F_27 ( V_12 + 0xFC0FD8 + ( V_13 ^ 3 ) ) ;
#endif
F_28 ( V_12 ) ;
}
F_24 ( V_28 L_5 ,
V_26 [ 0 ] . V_27 ) ;
}
