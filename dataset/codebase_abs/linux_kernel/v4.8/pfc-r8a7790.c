static int F_1 ( struct V_1 * V_2 , unsigned int V_3 , T_1 * V_4 )
{
if ( V_3 < V_5 ( 3, 0 ) || V_3 > V_5 ( 3 , 31 ) )
return - V_6 ;
* V_4 = 0xe606008c ;
return 31 - ( V_3 & 0x1f ) ;
}
