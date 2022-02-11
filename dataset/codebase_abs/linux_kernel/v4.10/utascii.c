T_1 F_1 ( char * V_1 )
{
T_2 V_2 ;
for ( V_2 = 0 ; V_2 < V_3 ; V_2 ++ ) {
if ( ! F_2 ( V_1 [ V_2 ] , V_2 ) ) {
return ( FALSE ) ;
}
}
return ( TRUE ) ;
}
T_1 F_2 ( char V_4 , T_2 V_5 )
{
if ( ! ( ( V_4 >= 'A' && V_4 <= 'Z' ) ||
( V_4 >= '0' && V_4 <= '9' ) || ( V_4 == '_' ) ) ) {
if ( V_4 == '!' && V_5 == 3 ) {
return ( TRUE ) ;
}
return ( FALSE ) ;
}
return ( TRUE ) ;
}
void F_3 ( T_1 * V_1 , char * V_6 , T_2 V_7 )
{
T_2 V_2 ;
for ( V_2 = 0 ; V_2 < V_7 ; V_2 ++ ) {
V_6 [ V_2 ] = ( char ) V_1 [ V_2 ] ;
if ( ! V_1 [ V_2 ] ) {
return;
}
if ( ! isprint ( V_1 [ V_2 ] ) ) {
V_6 [ V_2 ] = ' ' ;
}
}
}
