void * F_1 ( T_1 * V_1 , T_2 * V_2 , char * V_3 )
{
unsigned char * V_4 , * V_5 ;
const unsigned char * V_6 ;
int V_7 ;
char * V_8 ;
if ( V_3 == NULL ) return ( NULL ) ;
V_7 = V_1 ( V_3 , NULL ) ;
V_4 = F_2 ( V_7 + 10 ) ;
if ( V_4 == NULL )
{ F_3 ( V_9 , V_10 ) ; return ( NULL ) ; }
V_5 = V_4 ;
V_7 = V_1 ( V_3 , & V_5 ) ;
V_6 = V_4 ;
V_8 = V_2 ( NULL , & V_6 , V_7 ) ;
F_4 ( V_4 ) ;
return ( V_8 ) ;
}
void * F_5 ( const T_3 * V_11 , void * V_3 )
{
unsigned char * V_4 = NULL ;
const unsigned char * V_5 ;
long V_7 ;
void * V_8 ;
if ( V_3 == NULL ) return ( NULL ) ;
V_7 = F_6 ( V_3 , & V_4 , V_11 ) ;
if ( V_4 == NULL )
{ F_3 ( V_12 , V_10 ) ; return ( NULL ) ; }
V_5 = V_4 ;
V_8 = F_7 ( NULL , & V_5 , V_7 , V_11 ) ;
F_4 ( V_4 ) ;
return ( V_8 ) ;
}
