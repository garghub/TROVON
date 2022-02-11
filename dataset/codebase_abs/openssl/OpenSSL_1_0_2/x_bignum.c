static void F_1 ( T_1 * * V_1 , const T_2 * V_2 )
{
if( ! * V_1 ) return;
if( V_2 -> V_3 & V_4 ) F_2 ( ( V_5 * ) * V_1 ) ;
else F_3 ( ( V_5 * ) * V_1 ) ;
* V_1 = NULL ;
}
static int F_4 ( T_1 * * V_1 , unsigned char * V_6 , int * V_7 , const T_2 * V_2 )
{
V_5 * V_8 ;
int V_9 ;
if( ! * V_1 ) return - 1 ;
V_8 = ( V_5 * ) * V_1 ;
if( F_5 ( V_8 ) & 0x7 ) V_9 = 0 ;
else V_9 = 1 ;
if( V_6 ) {
if( V_9 ) * V_6 ++ = 0 ;
F_6 ( V_8 , V_6 ) ;
}
return V_9 + F_7 ( V_8 ) ;
}
static int F_8 ( T_1 * * V_1 , const unsigned char * V_6 , int V_10 ,
int V_11 , char * V_12 , const T_2 * V_2 )
{
V_5 * V_8 ;
if( ! * V_1 ) F_9 ( V_1 , V_2 ) ;
V_8 = ( V_5 * ) * V_1 ;
if( ! F_10 ( V_6 , V_10 , V_8 ) ) {
F_1 ( V_1 , V_2 ) ;
return 0 ;
}
return 1 ;
}
