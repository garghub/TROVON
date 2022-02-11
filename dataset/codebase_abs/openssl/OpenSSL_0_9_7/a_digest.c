int F_1 ( int (* F_2)() , const T_1 * type , char * V_1 ,
unsigned char * V_2 , unsigned int * V_3 )
{
int V_4 ;
unsigned char * V_5 , * V_6 ;
V_4 = F_2 ( V_1 , NULL ) ;
if ( ( V_5 = ( unsigned char * ) F_3 ( V_4 ) ) == NULL ) return ( 0 ) ;
V_6 = V_5 ;
F_2 ( V_1 , & V_6 ) ;
F_4 ( V_5 , V_4 , V_2 , V_3 , type , NULL ) ;
F_5 ( V_5 ) ;
return ( 1 ) ;
}
int F_6 ( const T_2 * V_7 , const T_1 * type , void * V_8 ,
unsigned char * V_2 , unsigned int * V_3 )
{
int V_4 ;
unsigned char * V_5 = NULL ;
V_4 = F_7 ( V_8 , & V_5 , V_7 ) ;
if ( ! V_5 ) return ( 0 ) ;
F_4 ( V_5 , V_4 , V_2 , V_3 , type , NULL ) ;
F_5 ( V_5 ) ;
return ( 1 ) ;
}
