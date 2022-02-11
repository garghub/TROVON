T_1 * F_1 ( const unsigned char * V_1 , int V_2 , T_2 * V_3 )
{
return F_2 ( V_1 , V_2 , NULL , NULL , V_3 ) ;
}
T_1 * F_2 ( const unsigned char * V_1 , int V_2 ,
const T_3 * V_4 , const T_3 * V_5 ,
T_2 * V_3 )
{
if ( V_3 -> V_6 -> V_7 != NULL )
return V_3 -> V_6 -> V_7 ( V_1 , V_2 , V_4 , V_5 , V_3 ) ;
F_3 ( V_8 , V_9 ) ;
return NULL ;
}
int F_4 ( int type , const unsigned char * V_1 , int V_2 , unsigned char
* V_10 , unsigned int * V_11 , T_2 * V_3 )
{
return F_5 ( type , V_1 , V_2 , V_10 , V_11 , NULL , NULL , V_3 ) ;
}
int F_5 ( int type , const unsigned char * V_1 , int V_2 ,
unsigned char * V_10 , unsigned int * V_11 , const T_3 * V_4 ,
const T_3 * V_12 , T_2 * V_3 )
{
if ( V_3 -> V_6 -> V_13 != NULL )
return V_3 -> V_6 -> V_13 ( type , V_1 , V_2 , V_10 , V_11 , V_4 , V_12 , V_3 ) ;
F_3 ( V_14 , V_9 ) ;
return 0 ;
}
int F_6 ( T_2 * V_3 , T_4 * V_15 , T_3 * * V_16 ,
T_3 * * V_5 )
{
if ( V_3 -> V_6 -> V_17 != NULL )
return V_3 -> V_6 -> V_17 ( V_3 , V_15 , V_16 , V_5 ) ;
F_3 ( V_18 , V_9 ) ;
return 0 ;
}
