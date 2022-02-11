static int F_1 ( struct V_1 * V_2 , unsigned int V_3 , T_1 * V_4 )
{
int V_5 = - V_6 ;
* V_4 = 0xe6060380 ;
if ( V_3 >= F_2 ( 3 , 0 ) && V_3 <= F_2 ( 3 , 11 ) )
V_5 = V_3 & 0x1f ;
if ( V_3 >= F_2 ( 4 , 0 ) && V_3 <= F_2 ( 4 , 17 ) )
V_5 = ( V_3 & 0x1f ) + 12 ;
return V_5 ;
}
