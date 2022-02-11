T_1 F_1 ( T_1 V_1 , const T_2 * V_2 ,
int V_3 )
{
register int V_4 ;
T_1 V_5 = 0 ;
for ( V_4 = 0 ; V_4 < V_3 ; V_4 ++ ) {
V_5 = ( ( V_5 << 8 ) & 0x3ff )
^ V_6 [ ( V_5 >> 2 ) & 0xff ]
^ * V_2 ++ ;
}
V_5 = ( ( V_5 << 8 ) & 0x3ff )
^ V_6 [ ( V_5 >> 2 ) & 0xff ]
^ ( V_1 >> 2 ) ;
V_5 = ( ( V_5 << 8 ) & 0x3ff )
^ V_6 [ ( V_5 >> 2 ) & 0xff ]
^ ( ( V_1 << 6 ) & 0xFF ) ;
return V_5 ;
}
