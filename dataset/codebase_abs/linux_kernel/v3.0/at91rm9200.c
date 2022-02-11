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
F_3 ( & V_7 ) ;
F_3 ( & V_8 ) ;
}
void T_1 F_5 ( int V_9 )
{
if ( V_9 >= F_2 ( V_4 ) )
return;
V_10 . V_11 = L_1 ;
V_10 . V_12 = V_4 [ V_9 ] . V_12 ;
F_6 ( & V_10 ) ;
}
static void F_7 ( void )
{
F_8 ( V_13 , V_14 | V_15 | 1 ) ;
F_8 ( V_16 , V_17 ) ;
}
void T_1 F_9 ( int type )
{
V_18 = type ;
}
void T_1 F_10 ( void )
{
F_11 ( V_19 , F_2 ( V_19 ) ) ;
}
void T_1 F_12 ( unsigned long V_20 )
{
V_21 = F_7 ;
V_22 = ( 1 << V_23 ) | ( 1 << V_24 )
| ( 1 << V_25 ) | ( 1 << V_26 )
| ( 1 << V_27 ) | ( 1 << V_28 )
| ( 1 << V_29 ) ;
F_13 ( V_20 ) ;
F_1 () ;
F_14 ( V_30 ,
F_15 () ? V_31 : V_32 ) ;
}
void T_1 F_16 ( unsigned int V_33 [ V_34 ] )
{
if ( ! V_33 )
V_33 = V_35 ;
F_17 ( V_33 ) ;
F_18 () ;
}
