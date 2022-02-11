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
static void F_7 ( void )
{
F_8 ( V_11 , V_12 | V_13 ) ;
}
static void T_1 F_9 ( void )
{
unsigned long V_14 ;
switch ( V_15 . V_16 & V_17 ) {
case V_18 :
V_14 = 2 * V_19 ;
break;
case V_20 :
default:
V_14 = V_19 ;
}
F_10 ( 0 , V_21 , V_14 ) ;
}
static void T_1 F_11 ( void )
{
if ( F_12 () ) {
F_9 () ;
} else if ( F_13 () ) {
F_10 ( 0 , V_22 , V_23 ) ;
F_10 ( 1 , V_24 , V_25 ) ;
} else {
F_10 ( 0 , V_26 , V_27 ) ;
F_10 ( 1 , V_28 , V_29 ) ;
}
}
static void T_1 F_14 ( void )
{
V_30 = V_31 ;
V_32 = F_7 ;
V_33 = ( 1 << V_34 ) | ( 1 << V_35 )
| ( 1 << V_36 ) ;
F_15 ( V_37 , 3 ) ;
}
