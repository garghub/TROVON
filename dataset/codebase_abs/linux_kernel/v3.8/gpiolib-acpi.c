static int F_1 ( struct V_1 * V_2 , void * V_3 )
{
if ( ! V_2 -> V_4 )
return false ;
return F_2 ( V_2 -> V_4 ) == V_3 ;
}
int F_3 ( char * V_5 , int V_6 )
{
struct V_1 * V_7 ;
T_1 V_8 ;
T_2 V_9 ;
V_9 = F_4 ( NULL , V_5 , & V_8 ) ;
if ( F_5 ( V_9 ) )
return - V_10 ;
V_7 = F_6 ( V_8 , F_1 ) ;
if ( ! V_7 )
return - V_10 ;
if ( ! F_7 ( V_7 -> V_11 + V_6 ) )
return - V_12 ;
return V_7 -> V_11 + V_6 ;
}
