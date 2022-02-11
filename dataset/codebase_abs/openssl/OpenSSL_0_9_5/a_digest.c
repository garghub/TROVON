int F_1 ( int (* F_2)() , const T_1 * type , char * V_1 ,
unsigned char * V_2 , unsigned int * V_3 )
{
T_2 V_4 ;
int V_5 ;
unsigned char * V_6 , * V_7 ;
V_5 = F_2 ( V_1 , NULL ) ;
if ( ( V_6 = ( unsigned char * ) Malloc ( V_5 ) ) == NULL ) return ( 0 ) ;
V_7 = V_6 ;
F_2 ( V_1 , & V_7 ) ;
F_3 ( & V_4 , type ) ;
F_4 ( & V_4 , V_6 , V_5 ) ;
F_5 ( & V_4 , V_2 , V_3 ) ;
Free ( V_6 ) ;
return ( 1 ) ;
}
