T_1 * F_1 ( T_2 * V_1 )
{
T_1 * V_2 ;
if ( ( V_2 = ( T_1 * ) F_2 ( sizeof( T_1 ) ) ) == NULL )
{
return ( NULL ) ;
}
memset ( V_2 , 0 , sizeof( T_1 ) ) ;
V_2 -> V_1 = V_1 ;
if ( ( V_2 -> V_1 -> V_3 != NULL ) && ! V_2 -> V_1 -> V_3 ( V_2 ) )
{
F_3 ( V_2 ) ;
V_2 = NULL ;
}
return ( V_2 ) ;
}
void F_4 ( T_1 * V_4 )
{
if( V_4 == NULL )
return;
if ( V_4 -> V_1 -> V_5 != NULL )
V_4 -> V_1 -> V_5 ( V_4 ) ;
F_3 ( V_4 ) ;
}
int F_5 ( T_1 * V_4 , unsigned char * V_6 , int V_7 ,
unsigned char * V_8 , int V_9 )
{
int V_2 ;
if ( V_4 -> V_1 -> V_10 == NULL )
{
return ( - 1 ) ;
}
V_2 = V_4 -> V_1 -> V_10 ( V_4 , V_6 , V_7 , V_8 , V_9 ) ;
if ( V_2 > 0 )
{
V_4 -> V_11 += V_9 ;
V_4 -> V_12 += V_2 ;
}
return ( V_2 ) ;
}
int F_6 ( T_1 * V_4 , unsigned char * V_6 , int V_7 ,
unsigned char * V_8 , int V_9 )
{
int V_2 ;
if ( V_4 -> V_1 -> V_13 == NULL )
{
return ( - 1 ) ;
}
V_2 = V_4 -> V_1 -> V_13 ( V_4 , V_6 , V_7 , V_8 , V_9 ) ;
if ( V_2 > 0 )
{
V_4 -> V_14 += V_9 ;
V_4 -> V_15 += V_2 ;
}
return ( V_2 ) ;
}
