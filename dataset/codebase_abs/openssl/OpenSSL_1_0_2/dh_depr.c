T_1 * F_1 ( int V_1 , int V_2 ,
void (* F_2) ( int , int , void * ) , void * V_3 )
{
T_2 V_4 ;
T_1 * V_5 = NULL ;
if ( ( V_5 = F_3 () ) == NULL )
return NULL ;
F_4 ( & V_4 , F_2 , V_3 ) ;
if ( F_5 ( V_5 , V_1 , V_2 , & V_4 ) )
return V_5 ;
F_6 ( V_5 ) ;
return NULL ;
}
