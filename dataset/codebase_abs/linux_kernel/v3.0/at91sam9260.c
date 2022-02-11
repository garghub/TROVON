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
unsigned long V_14 , V_15 ;
V_14 = F_10 ( V_16 ) ;
switch ( V_14 & V_17 ) {
case V_18 :
V_15 = 2 * V_19 ;
break;
case V_20 :
default:
V_15 = V_19 ;
}
V_21 -> V_22 = V_23 - V_15 ;
V_21 -> V_24 = V_15 ;
F_11 ( V_21 , F_2 ( V_21 ) ) ;
}
void T_1 F_12 ( void )
{
F_11 ( V_25 , F_2 ( V_25 ) ) ;
if ( F_13 () )
F_9 () ;
else if ( F_14 () )
F_11 ( V_26 , F_2 ( V_26 ) ) ;
else
F_11 ( V_27 , F_2 ( V_27 ) ) ;
}
void T_1 F_15 ( unsigned long V_28 )
{
V_29 = V_30 ;
V_31 = F_7 ;
V_32 = ( 1 << V_33 ) | ( 1 << V_34 )
| ( 1 << V_35 ) ;
F_16 ( V_28 ) ;
F_1 () ;
F_17 ( V_36 , 3 ) ;
}
void T_1 F_18 ( unsigned int V_37 [ V_38 ] )
{
if ( ! V_37 )
V_37 = V_39 ;
F_19 ( V_37 ) ;
F_20 () ;
}
