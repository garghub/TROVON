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
F_3 ( & V_9 ) ;
F_3 ( & V_10 ) ;
}
void T_1 F_5 ( int V_11 )
{
if ( V_11 >= F_2 ( V_4 ) )
return;
V_12 . V_13 = L_1 ;
V_12 . V_14 = V_4 [ V_11 ] . V_14 ;
F_6 ( & V_12 ) ;
}
static void F_7 ( void )
{
F_8 ( V_15 , V_16 | V_17 ) ;
}
static void T_1 F_9 ( void )
{
if ( F_10 () )
F_11 ( 0 , V_18 , V_19 ) ;
else
F_11 ( 0 , V_20 , V_21 ) ;
}
static void T_1 F_12 ( void )
{
V_22 = V_23 ;
V_24 = F_7 ;
V_25 = ( 1 << V_26 ) | ( 1 << V_27 )
| ( 1 << V_28 ) ;
F_13 ( V_29 , 3 ) ;
}
