int
F_1 ( void * V_1 , int V_2 , void * V_3 , int * V_4 )
{
T_1 * V_5 = ( T_1 * ) V_1 ;
T_2 * V_6 = ( T_2 * ) V_3 ;
int V_7 ;
for ( V_7 = 0 ; V_7 < V_2 ; V_7 ++ )
{
V_6 [ V_7 ] = V_8 [ V_5 [ V_7 ] ] ;
}
* V_4 = V_2 * 2 ;
return 0 ;
}
