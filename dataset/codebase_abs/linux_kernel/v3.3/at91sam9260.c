static void T_1 F_1 ( void )
{
int V_1 ;
for ( V_1 = 0 ; V_1 < F_2 ( V_2 ) ; V_1 ++ )
F_3 ( V_2 [ V_1 ] ) ;
F_4 ( V_3 ,
F_2 ( V_3 ) ) ;
F_4 ( V_4 ,
F_2 ( V_4 ) ) ;
F_3 ( & V_5 ) ;
F_3 ( & V_6 ) ;
}
void T_1 F_5 ( int V_7 )
{
if ( V_7 >= F_2 ( V_4 ) )
return;
V_8 . V_9 = L_1 ;
V_8 . V_10 = V_4 [ V_7 ] . V_10 ;
F_6 ( & V_8 ) ;
}
static void T_1 F_7 ( void )
{
unsigned long V_11 ;
switch ( V_12 . V_13 & V_14 ) {
case V_15 :
V_11 = 2 * V_16 ;
break;
case V_17 :
default:
V_11 = V_16 ;
}
F_8 ( 0 , V_18 , V_11 ) ;
}
static void T_1 F_9 ( void )
{
if ( F_10 () ) {
F_7 () ;
} else if ( F_11 () ) {
F_8 ( 0 , V_19 , V_20 ) ;
F_8 ( 1 , V_21 , V_22 ) ;
} else {
F_8 ( 0 , V_23 , V_24 ) ;
F_8 ( 1 , V_25 , V_26 ) ;
}
}
static void T_1 F_12 ( void )
{
F_13 ( V_27 ) ;
F_14 ( V_28 ) ;
F_15 ( V_29 ) ;
F_16 ( 0 , V_30 ) ;
}
static void T_1 F_17 ( void )
{
V_31 = V_32 ;
V_33 = ( 1 << V_34 ) | ( 1 << V_35 )
| ( 1 << V_36 ) ;
F_18 ( V_37 , 3 ) ;
}
