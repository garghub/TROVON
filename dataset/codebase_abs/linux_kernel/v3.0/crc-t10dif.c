T_1 F_1 ( const unsigned char * V_1 , T_2 V_2 )
{
T_1 V_3 = 0 ;
unsigned int V_4 ;
for ( V_4 = 0 ; V_4 < V_2 ; V_4 ++ )
V_3 = ( V_3 << 8 ) ^ V_5 [ ( ( V_3 >> 8 ) ^ V_1 [ V_4 ] ) & 0xff ] ;
return V_3 ;
}
