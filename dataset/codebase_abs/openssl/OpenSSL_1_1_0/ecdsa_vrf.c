int F_1 ( const unsigned char * V_1 , int V_2 ,
const T_1 * V_3 , T_2 * V_4 )
{
if ( V_4 -> V_5 -> V_6 != NULL )
return V_4 -> V_5 -> V_6 ( V_1 , V_2 , V_3 , V_4 ) ;
F_2 ( V_7 , V_8 ) ;
return 0 ;
}
int F_3 ( int type , const unsigned char * V_1 , int V_2 ,
const unsigned char * V_9 , int V_10 , T_2 * V_4 )
{
if ( V_4 -> V_5 -> V_11 != NULL )
return V_4 -> V_5 -> V_11 ( type , V_1 , V_2 , V_9 , V_10 ,
V_4 ) ;
F_2 ( V_12 , V_8 ) ;
return 0 ;
}
