bool F_1 ( struct V_1 * V_2 )
{
T_1 V_3 ;
T_1 V_4 ;
T_1 * V_5 ;
V_4 = sizeof( V_6 ) / sizeof( T_1 ) ;
V_5 = V_6 ;
for ( V_3 = 0 ; V_3 < V_4 ; V_3 = V_3 + 2 )
F_2 ( V_2 , V_5 [ V_3 ] , ( V_7 ) V_5 [ V_3 + 1 ] ) ;
F_2 ( V_2 , V_8 , V_9 ) ;
return true ;
}
