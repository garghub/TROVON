char * F_1 ( int (* F_2)() , char * (* F_3)() , char * V_1 )
{
unsigned char * V_2 , * V_3 ;
long V_4 ;
char * V_5 ;
if ( V_1 == NULL ) return ( NULL ) ;
V_4 = ( long ) F_2 ( V_1 , NULL ) ;
V_2 = ( unsigned char * ) Malloc ( ( unsigned int ) V_4 + 10 ) ;
if ( V_2 == NULL )
{ F_4 ( V_6 , V_7 ) ; return ( NULL ) ; }
V_3 = V_2 ;
V_4 = F_2 ( V_1 , & V_3 ) ;
V_3 = V_2 ;
V_5 = F_3 ( NULL , & V_3 , V_4 ) ;
Free ( V_2 ) ;
return ( V_5 ) ;
}
