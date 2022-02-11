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
static void T_1 F_7 ( void )
{
F_8 ( 0 , V_13 , V_14 ) ;
}
static void T_1 F_9 ( void )
{
F_10 ( V_15 ) ;
F_11 ( V_16 ) ;
F_12 ( V_17 ) ;
F_13 ( 0 , V_18 ) ;
}
static void T_1 F_14 ( void )
{
V_19 = V_20 ;
V_21 = ( 1 << V_22 ) | ( 1 << V_23 ) ;
F_15 ( V_24 , 4 ) ;
if ( F_16 () )
V_25 = 0xB ;
else if ( F_17 () )
V_25 = 0xC ;
}
