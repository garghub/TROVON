T_1
F_1 ( T_2 V_1 , T_2 V_2 , T_3 V_3 , unsigned V_4 )
{
T_1 V_5 , V_6 ;
unsigned V_7 , V_8 ;
T_3 V_9 ;
T_1 V_10 ;
V_7 = V_4 ;
V_1 -= 1 ;
V_8 = V_11 - V_7 ;
V_5 = V_2 [ 0 ] ;
V_10 = V_5 << V_8 ;
V_6 = V_5 ;
for ( V_9 = 1 ; V_9 < V_3 ; V_9 ++ ) {
V_5 = V_2 [ V_9 ] ;
V_1 [ V_9 ] = ( V_6 >> V_7 ) | ( V_5 << V_8 ) ;
V_6 = V_5 ;
}
V_1 [ V_9 ] = V_6 >> V_7 ;
return V_10 ;
}
