int F_1 ( T_1 V_1 )
{
int V_2 , V_3 = 0 ;
for ( V_2 = 0 ; V_2 < 32 ; V_2 ++ ) {
if ( V_1 & 0x01 )
V_3 ++ ;
V_1 >>= 1 ;
}
return V_3 ;
}
