char * F_1 ( char * (* F_2)() , const char * V_1 , T_1 * V_2 , char * * V_3 ,
T_2 * V_4 , void * V_5 )
{
unsigned char * V_6 = NULL , * V_7 = NULL ;
long V_8 ;
char * V_9 = NULL ;
if ( ! F_3 ( & V_7 , & V_8 , NULL , V_1 , V_2 , V_4 , V_5 ) )
return NULL ;
V_6 = V_7 ;
V_9 = F_2 ( V_3 , & V_6 , V_8 ) ;
if ( V_9 == NULL )
F_4 ( V_10 , V_11 ) ;
F_5 ( V_7 ) ;
return ( V_9 ) ;
}
