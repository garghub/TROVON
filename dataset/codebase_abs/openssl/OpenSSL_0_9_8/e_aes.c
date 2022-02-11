static int F_1 ( T_1 * V_1 , const unsigned char * V_2 ,
const unsigned char * V_3 , int V_4 )
{
int V_5 ;
if ( ( V_1 -> V_6 -> V_7 & V_8 ) == V_9
|| ( V_1 -> V_6 -> V_7 & V_8 ) == V_10
|| V_4 )
V_5 = F_2 ( V_2 , V_1 -> V_11 * 8 , V_1 -> V_12 ) ;
else
V_5 = F_3 ( V_2 , V_1 -> V_11 * 8 , V_1 -> V_12 ) ;
if( V_5 < 0 )
{
F_4 ( V_13 , V_14 ) ;
return 0 ;
}
return 1 ;
}
