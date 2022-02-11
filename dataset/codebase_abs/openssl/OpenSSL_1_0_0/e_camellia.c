static int F_1 ( T_1 * V_1 , const unsigned char * V_2 ,
const unsigned char * V_3 , int V_4 )
{
int V_5 ;
V_5 = F_2 ( V_2 , V_1 -> V_6 * 8 , V_1 -> V_7 ) ;
if( V_5 < 0 )
{
F_3 ( V_8 , V_9 ) ;
return 0 ;
}
return 1 ;
}
