static int T_1 F_1 ( struct V_1 * V_2 , T_2 V_3 , T_2 V_4 )
{
if ( V_2 -> V_5 == V_6 &&
V_2 -> V_7 == V_8 )
switch ( F_2 ( V_2 -> V_9 ) ) {
case 1 : return 14 ;
case 2 : return 15 ;
case 3 : return 12 ;
}
return V_10 [ ( V_3 + V_4 ) & 3 ] ;
}
static int T_1 F_3 ( void )
{
if ( F_4 () )
F_5 ( & V_11 ) ;
return 0 ;
}
