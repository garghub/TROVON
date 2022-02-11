int F_1 ( T_1 * V_1 , const T_2 * type , char * V_2 ,
unsigned char * V_3 , unsigned int * V_4 )
{
int V_5 ;
unsigned char * V_6 , * V_7 ;
V_5 = V_1 ( V_2 , NULL ) ;
if ( ( V_6 = ( unsigned char * ) F_2 ( V_5 ) ) == NULL )
{
F_3 ( V_8 , V_9 ) ;
return ( 0 ) ;
}
V_7 = V_6 ;
V_1 ( V_2 , & V_7 ) ;
F_4 ( V_6 , V_5 , V_3 , V_4 , type , NULL ) ;
F_5 ( V_6 ) ;
return ( 1 ) ;
}
int F_6 ( const T_3 * V_10 , const T_2 * type , void * V_11 ,
unsigned char * V_3 , unsigned int * V_4 )
{
int V_5 ;
unsigned char * V_6 = NULL ;
V_5 = F_7 ( V_11 , & V_6 , V_10 ) ;
if ( ! V_6 ) return ( 0 ) ;
F_4 ( V_6 , V_5 , V_3 , V_4 , type , NULL ) ;
F_5 ( V_6 ) ;
return ( 1 ) ;
}
