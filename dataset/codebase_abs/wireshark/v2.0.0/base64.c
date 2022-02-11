T_1 F_1 ( char * V_1 )
{
static const char V_2 [] = L_1 ;
int V_3 , V_4 , V_5 , V_6 ;
unsigned char * V_7 = ( unsigned char * ) V_1 ;
char * V_8 ;
int V_9 ;
V_9 = ( int ) ( strchr ( V_2 , '\r' ) - V_2 ) ;
V_6 = 0 ;
while ( * V_1 && ( V_8 = strchr ( V_2 , * V_1 ) ) ) {
V_5 = ( int ) ( V_8 - V_2 ) ;
if( V_5 < V_9 ) {
V_4 = ( V_6 * 6 ) / 8 ;
V_3 = ( V_6 * 6 ) % 8 ;
V_7 [ V_4 ] &= ~ ( ( 1 << ( 8 - V_3 ) ) - 1 ) ;
if ( V_3 < 3 ) {
V_7 [ V_4 ] |= ( V_5 << ( 2 - V_3 ) ) ;
} else {
V_7 [ V_4 ] |= ( V_5 >> ( V_3 - 2 ) ) ;
V_7 [ V_4 + 1 ] = 0 ;
V_7 [ V_4 + 1 ] |= ( V_5 << ( 8 - ( V_3 - 2 ) ) ) & 0xFF ;
}
V_6 ++ ;
}
V_1 ++ ;
}
V_7 [ V_6 * 3 / 4 ] = 0 ;
return V_6 * 3 / 4 ;
}
