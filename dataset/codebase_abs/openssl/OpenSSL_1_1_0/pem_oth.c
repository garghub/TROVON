void * F_1 ( T_1 * V_1 , const char * V_2 , T_2 * V_3 , void * * V_4 ,
T_3 * V_5 , void * V_6 )
{
const unsigned char * V_7 = NULL ;
unsigned char * V_8 = NULL ;
long V_9 ;
char * V_10 = NULL ;
if ( ! F_2 ( & V_8 , & V_9 , NULL , V_2 , V_3 , V_5 , V_6 ) )
return NULL ;
V_7 = V_8 ;
V_10 = V_1 ( V_4 , & V_7 , V_9 ) ;
if ( V_10 == NULL )
F_3 ( V_11 , V_12 ) ;
F_4 ( V_8 ) ;
return ( V_10 ) ;
}
