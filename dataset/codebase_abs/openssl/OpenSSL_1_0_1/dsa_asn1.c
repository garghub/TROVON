static int F_1 ( int V_1 , T_1 * * V_2 , const T_2 * V_3 ,
void * V_4 )
{
if( V_1 == V_5 ) {
T_3 * V_6 ;
V_6 = F_2 ( sizeof( T_3 ) ) ;
if ( ! V_6 )
{
F_3 ( V_7 , V_8 ) ;
return 0 ;
}
V_6 -> V_9 = NULL ;
V_6 -> V_10 = NULL ;
* V_2 = ( T_1 * ) V_6 ;
return 2 ;
}
return 1 ;
}
int F_4 ( int type , const unsigned char * V_11 , int V_12 , unsigned char * V_6 ,
unsigned int * V_13 , T_4 * V_14 )
{
T_3 * V_10 ;
F_5 ( V_11 , V_12 ) ;
V_10 = F_6 ( V_11 , V_12 , V_14 ) ;
if ( V_10 == NULL )
{
* V_13 = 0 ;
return ( 0 ) ;
}
* V_13 = F_7 ( V_10 , & V_6 ) ;
F_8 ( V_10 ) ;
return ( 1 ) ;
}
int F_9 ( int type , const unsigned char * V_11 , int V_15 ,
const unsigned char * V_16 , int V_13 , T_4 * V_14 )
{
T_3 * V_10 ;
int V_17 = - 1 ;
V_10 = F_10 () ;
if ( V_10 == NULL ) return ( V_17 ) ;
if ( F_11 ( & V_10 , & V_16 , V_13 ) == NULL ) goto V_18;
V_17 = F_12 ( V_11 , V_15 , V_10 , V_14 ) ;
V_18:
F_8 ( V_10 ) ;
return ( V_17 ) ;
}
