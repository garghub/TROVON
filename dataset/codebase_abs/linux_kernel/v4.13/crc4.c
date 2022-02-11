T_1 F_1 ( T_1 V_1 , T_2 V_2 , int V_3 )
{
int V_4 ;
V_2 &= ( 1ull << V_3 ) - 1 ;
V_3 = ( V_3 + 3 ) & ~ 0x3 ;
for ( V_4 = V_3 - 4 ; V_4 >= 0 ; V_4 -= 4 )
V_1 = V_5 [ V_1 ^ ( ( V_2 >> V_4 ) & 0xf ) ] ;
return V_1 ;
}
