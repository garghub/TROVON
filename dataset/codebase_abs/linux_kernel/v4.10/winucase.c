T_1
F_1 ( T_1 V_1 )
{
unsigned char V_2 ;
const T_1 * V_3 ;
T_1 V_4 ;
V_2 = ( V_1 & 0xff00 ) >> 8 ;
V_3 = V_5 [ V_2 ] ;
if ( ! V_3 )
return V_1 ;
V_2 = V_1 & 0xff ;
V_4 = V_3 [ V_2 ] ;
if ( V_4 )
return V_4 ;
return V_1 ;
}
