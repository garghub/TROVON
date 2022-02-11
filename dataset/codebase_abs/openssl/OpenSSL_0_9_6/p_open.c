int F_1 ( T_1 * V_1 , T_2 * type , unsigned char * V_2 ,
int V_3 , unsigned char * V_4 , T_3 * V_5 )
{
unsigned char * V_6 = NULL ;
int V_7 , V_8 = 0 , V_9 = 0 ;
if( type ) {
F_2 ( V_1 ) ;
if( ! F_3 ( V_1 , type , NULL , NULL ) ) return 0 ;
}
if( ! V_5 ) return 1 ;
if ( V_5 -> type != V_10 )
{
F_4 ( V_11 , V_12 ) ;
goto V_13;
}
V_8 = F_5 ( V_5 -> V_14 . V_15 ) ;
V_6 = ( unsigned char * ) F_6 ( V_8 + 2 ) ;
if ( V_6 == NULL )
{
F_4 ( V_11 , V_16 ) ;
goto V_13;
}
V_7 = F_7 ( V_6 , V_2 , V_3 , V_5 ) ;
if ( ( V_7 <= 0 ) || ! F_8 ( V_1 , V_7 ) )
{
goto V_13;
}
if( ! F_3 ( V_1 , NULL , V_6 , V_4 ) ) goto V_13;
V_9 = 1 ;
V_13:
if ( V_6 != NULL ) memset ( V_6 , 0 , V_8 ) ;
F_9 ( V_6 ) ;
return ( V_9 ) ;
}
int F_10 ( T_1 * V_1 , unsigned char * V_17 , int * V_18 )
{
int V_7 ;
V_7 = F_11 ( V_1 , V_17 , V_18 ) ;
F_3 ( V_1 , NULL , NULL , NULL ) ;
return ( V_7 ) ;
}
