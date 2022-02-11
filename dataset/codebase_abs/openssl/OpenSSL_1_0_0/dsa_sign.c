T_1 * F_1 ( const unsigned char * V_1 , int V_2 , T_2 * V_3 )
{
return V_3 -> V_4 -> V_5 ( V_1 , V_2 , V_3 ) ;
}
int F_2 ( int type , const unsigned char * V_1 , int V_2 , unsigned char * V_6 ,
unsigned int * V_7 , T_2 * V_3 )
{
T_1 * V_8 ;
F_3 ( V_1 , V_2 ) ;
V_8 = F_1 ( V_1 , V_2 , V_3 ) ;
if ( V_8 == NULL )
{
* V_7 = 0 ;
return ( 0 ) ;
}
* V_7 = F_4 ( V_8 , & V_6 ) ;
F_5 ( V_8 ) ;
return ( 1 ) ;
}
int F_6 ( T_2 * V_3 , T_3 * V_9 , T_4 * * V_10 , T_4 * * V_11 )
{
return V_3 -> V_4 -> V_12 ( V_3 , V_9 , V_10 , V_11 ) ;
}
