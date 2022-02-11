T_1 * F_1 ( int V_1 ,
unsigned char * V_2 , int V_3 ,
int * V_4 , unsigned long * V_5 ,
void (* F_2)( int , int , void * ) ,
void * V_6 )
{
T_2 V_7 ;
T_1 * V_8 ;
if ( ( V_8 = F_3 () ) == NULL ) return NULL ;
F_4 ( & V_7 , F_2 , V_6 ) ;
if( F_5 ( V_8 , V_1 , V_2 , V_3 ,
V_4 , V_5 , & V_7 ) )
return V_8 ;
F_6 ( V_8 ) ;
return NULL ;
}
