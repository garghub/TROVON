T_1 * F_1 ( const unsigned char * V_1 , int V_2 , T_2 * V_3 )
{
return F_2 ( V_1 , V_2 , NULL , NULL , V_3 ) ;
}
T_1 * F_2 ( const unsigned char * V_1 , int V_2 ,
const T_3 * V_4 , const T_3 * V_5 ,
T_2 * V_3 )
{
T_4 * V_6 = F_3 ( V_3 ) ;
if ( V_6 == NULL )
return NULL ;
return V_6 -> V_7 -> V_8 ( V_1 , V_2 , V_4 , V_5 , V_3 ) ;
}
int F_4 ( int type , const unsigned char * V_1 , int V_2 , unsigned char
* V_9 , unsigned int * V_10 , T_2 * V_3 )
{
return F_5 ( type , V_1 , V_2 , V_9 , V_10 , NULL , NULL , V_3 ) ;
}
int F_5 ( int type , const unsigned char * V_1 , int V_2 , unsigned char
* V_9 , unsigned int * V_10 , const T_3 * V_4 ,
const T_3 * V_11 , T_2 * V_3 )
{
T_1 * V_12 ;
F_6 ( V_1 , V_2 ) ;
V_12 = F_2 ( V_1 , V_2 , V_4 , V_11 , V_3 ) ;
if ( V_12 == NULL ) {
* V_10 = 0 ;
return 0 ;
}
* V_10 = F_7 ( V_12 , & V_9 ) ;
F_8 ( V_12 ) ;
return 1 ;
}
int F_9 ( T_2 * V_3 , T_5 * V_13 , T_3 * * V_14 ,
T_3 * * V_5 )
{
T_4 * V_6 = F_3 ( V_3 ) ;
if ( V_6 == NULL )
return 0 ;
return V_6 -> V_7 -> V_15 ( V_3 , V_13 , V_14 , V_5 ) ;
}
