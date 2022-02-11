T_1 *
F_1 ( T_1 * V_1 )
{
T_1 * V_2 ;
for ( V_2 = V_1 ; * V_2 ; V_2 ++ )
* V_2 = F_2 ( * V_2 ) ;
return ( V_1 ) ;
}
T_1 *
F_3 ( T_1 * V_1 )
{
T_1 * V_2 ;
for ( V_2 = V_1 ; * V_2 ; V_2 ++ )
* V_2 = F_4 ( * V_2 ) ;
return ( V_1 ) ;
}
T_2
F_5 ( T_3 * V_1 )
{
T_4 V_3 ;
for( V_3 = 0 ; V_1 [ V_3 ] != '\0' ; V_3 ++ ) {
if( ! isprint ( V_1 [ V_3 ] ) ) {
return FALSE ;
}
}
return TRUE ;
}
T_2
F_6 ( T_3 * V_1 )
{
T_4 V_3 ;
for( V_3 = 0 ; V_1 [ V_3 ] != '\0' ; V_3 ++ ) {
if( ! isdigit ( V_1 [ V_3 ] ) ) {
return FALSE ;
}
}
return TRUE ;
}
