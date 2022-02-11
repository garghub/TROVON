T_1 F_1 ( int V_1 )
{
if ( V_1 == 14 ) {
return 2484 ;
}
if ( V_1 < 14 ) {
return ( 2407 + ( V_1 * 5 ) ) ;
}
if ( V_1 < 27 ) {
return ( 2512 + ( ( V_1 - 15 ) * 20 ) ) ;
}
return ( 5000 + ( V_1 * 5 ) ) ;
}
T_2 F_2 ( T_1 V_2 )
{
if ( V_2 == 2484 )
return 14 ;
if ( V_2 < 2484 )
return ( V_2 - 2407 ) / 5 ;
if ( V_2 < 5000 )
return 15 + ( ( V_2 - 2512 ) / 20 ) ;
return ( V_2 - 5000 ) / 5 ;
}
