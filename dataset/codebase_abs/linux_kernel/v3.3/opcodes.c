T_1 unsigned int F_1 ( T_2 V_1 , T_2 V_2 )
{
T_2 V_3 = V_1 >> 28 ;
T_2 V_4 = V_2 >> 28 ;
unsigned int V_5 ;
if ( V_3 != V_6 ) {
if ( ( V_7 [ V_3 ] >> ( V_4 ) ) & 1 )
V_5 = V_8 ;
else
V_5 = V_9 ;
} else {
V_5 = V_10 ;
}
return V_5 ;
}
