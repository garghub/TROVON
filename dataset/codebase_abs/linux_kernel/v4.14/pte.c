T_1 * F_1 ( unsigned long V_1 )
{
T_1 * V_2 ;
unsigned int V_3 ;
V_2 = F_2 ( V_1 , & V_3 ) ;
if ( ! V_2 )
return NULL ;
if ( V_3 != V_4 )
return NULL ;
if ( ! F_3 ( * V_2 ) )
return NULL ;
return V_2 ;
}
