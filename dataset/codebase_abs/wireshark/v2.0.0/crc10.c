T_1
F_1 ( T_1 V_1 , const T_2 * V_2 ,
int V_3 )
{
register int V_4 ;
for ( V_4 = 0 ; V_4 < V_3 ; V_4 ++ ) {
V_1 = ( ( V_1 << 8 ) & 0x3ff )
^ V_5 [ ( V_1 >> 2 ) & 0xff ]
^ * V_2 ++ ;
}
return V_1 ;
}
