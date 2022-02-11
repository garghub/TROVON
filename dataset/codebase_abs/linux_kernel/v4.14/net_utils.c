bool F_1 ( const char * V_1 , T_1 * V_2 )
{
int V_3 ;
if ( strlen ( V_1 ) < 3 * V_4 - 1 )
return false ;
for ( V_3 = 0 ; V_3 < V_4 ; V_3 ++ ) {
if ( ! isxdigit ( V_1 [ V_3 * 3 ] ) || ! isxdigit ( V_1 [ V_3 * 3 + 1 ] ) )
return false ;
if ( V_3 != V_4 - 1 && V_1 [ V_3 * 3 + 2 ] != ':' )
return false ;
}
for ( V_3 = 0 ; V_3 < V_4 ; V_3 ++ ) {
V_2 [ V_3 ] = ( F_2 ( V_1 [ V_3 * 3 ] ) << 4 ) | F_2 ( V_1 [ V_3 * 3 + 1 ] ) ;
}
return true ;
}
