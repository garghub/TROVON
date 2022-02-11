int F_1 ( T_1 * V_1 , unsigned int V_2 )
{
char V_3 [ 32 ] ;
int V_4 ;
snprintf ( V_3 , sizeof( V_3 ) , L_1 , V_2 ) ;
V_4 = F_2 ( ( V_5 ) V_3 , 0 ) ;
if ( V_4 < 0 ) {
V_1 -> V_4 = - 1 ;
if ( V_4 >= V_6 && V_4 <= V_7 )
return V_4 ;
else
return - V_8 ;
}
V_1 -> V_4 = V_4 ;
return 0 ;
}
