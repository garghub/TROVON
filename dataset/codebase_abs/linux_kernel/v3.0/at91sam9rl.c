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
void T_1 F_9 ( void )
{
unsigned long V_14 , V_15 ;
F_10 ( V_16 , F_2 ( V_16 ) ) ;
V_14 = F_11 ( V_17 ) ;
switch ( V_14 & V_18 ) {
case V_19 :
V_15 = 2 * V_20 ;
break;
case V_21 :
default:
V_15 = V_20 ;
}
V_22 -> V_23 = V_24 - V_15 ;
V_22 -> V_25 = V_15 ;
F_10 ( V_22 , F_2 ( V_22 ) ) ;
}
void T_1 F_12 ( unsigned long V_26 )
{
V_27 = V_28 ;
V_29 = F_7 ;
V_30 = ( 1 << V_31 ) ;
F_13 ( V_26 ) ;
F_1 () ;
F_14 ( V_32 , 4 ) ;
}
void T_1 F_15 ( unsigned int V_33 [ V_34 ] )
{
if ( ! V_33 )
V_33 = V_35 ;
F_16 ( V_33 ) ;
F_17 () ;
}
