int F_1 ( T_1 * V_1 , unsigned char * * V_2 )
{
if ( V_1 -> V_3 && V_1 -> V_3 -> V_4 )
{
return V_1 -> V_3 -> V_4 ( V_1 , V_2 ) ;
}
if ( V_1 -> V_3 && V_1 -> V_3 -> V_5 ) {
T_2 * V_6 = F_2 ( V_1 ) ;
int V_7 = F_3 ( V_6 , V_2 ) ;
F_4 ( V_6 ) ;
return V_7 ;
}
F_5 ( V_8 , V_9 ) ;
return ( - 1 ) ;
}
