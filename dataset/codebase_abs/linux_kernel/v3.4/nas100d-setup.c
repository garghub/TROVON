static void F_1 ( void )
{
F_2 ( V_1 , V_2 ) ;
F_3 ( V_1 , V_3 ) ;
}
static void F_4 ( unsigned long V_4 )
{
if ( F_5 ( V_5 ) ) {
if ( V_6 > 0 )
V_6 -- ;
} else {
if ( V_6 == 0 ) {
F_6 () ;
F_3 ( V_7 , V_8 ) ;
} else {
V_6 = V_9 ;
}
}
F_7 ( & V_10 , V_11 + F_8 ( 500 ) ) ;
}
static T_1 F_9 ( int V_12 , void * V_13 )
{
F_10 () ;
return V_14 ;
}
static void T_2 F_11 ( void )
{
T_3 T_4 * V_15 ;
int V_16 ;
F_12 () ;
* V_17 = 0 ;
V_18 . V_19 = F_13 ( 0 ) ;
V_18 . V_20 =
F_13 ( 0 ) + V_21 - 1 ;
F_14 ( 0 , V_22 ,
F_15 ( V_22 ) ) ;
( void ) F_16 ( & V_23 ) ;
F_17 ( V_24 , F_15 ( V_24 ) ) ;
V_25 = F_1 ;
if ( F_18 ( F_19 ( V_26 ) , & F_9 ,
V_27 | V_28 ,
L_1 , NULL ) < 0 ) {
F_20 ( V_29 L_2 ,
F_19 ( V_26 ) ) ;
}
F_2 ( V_5 , V_30 ) ;
V_6 = V_9 ;
F_7 ( & V_10 , V_11 + F_8 ( 500 ) ) ;
V_15 = F_21 ( F_13 ( 0 ) , 0x1000000 ) ;
if ( V_15 ) {
for ( V_16 = 0 ; V_16 < 6 ; V_16 ++ )
#ifdef F_22
V_31 [ 0 ] . V_32 [ V_16 ] = F_23 ( V_15 + 0xFC0FD8 + V_16 ) ;
#else
V_31 [ 0 ] . V_32 [ V_16 ] = F_23 ( V_15 + 0xFC0FD8 + ( V_16 ^ 3 ) ) ;
#endif
F_24 ( V_15 ) ;
}
F_20 ( V_33 L_3 ,
V_31 [ 0 ] . V_32 ) ;
}
