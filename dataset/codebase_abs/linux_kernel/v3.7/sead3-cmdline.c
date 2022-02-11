char * T_1 F_1 ( void )
{
return & ( V_1 [ 0 ] ) ;
}
void T_1 F_2 ( void )
{
char * V_2 ;
int V_3 ;
V_3 = 1 ;
V_2 = & ( V_1 [ 0 ] ) ;
while ( V_3 < V_4 ) {
strcpy ( V_2 , F_3 ( V_3 ) ) ;
V_2 += strlen ( F_3 ( V_3 ) ) ;
* V_2 ++ = ' ' ;
V_3 ++ ;
}
if ( V_2 != & ( V_1 [ 0 ] ) ) {
-- V_2 ;
* V_2 = '\0' ;
}
}
