static T_1 F_1 ( struct V_1 * V_2 )
{
return ( T_1 ) F_2 ( V_3 + V_4 ) ;
}
static int T_2 F_3 ( void )
{
T_3 V_5 ;
if ( ! F_4 () )
return - V_6 ;
if ( ! F_5 ( V_3 + V_4 ,
V_7 ,
L_1 ) ) {
F_6 ( L_2 ) ;
return - V_6 ;
}
F_7 ( V_8 | ( V_9 ? V_10 : 0 ) ,
V_3 + V_11 ) ;
V_5 = ( V_12 + V_13 ) ;
if ( V_9 )
V_5 *= 27 ;
F_8 ( L_3 , V_9 ? L_4 : L_5 , V_13 ) ;
return F_9 ( & V_14 , V_5 ) ;
}
