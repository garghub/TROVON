void F_1 ( void )
{
V_1 = F_2 ( V_2 , NULL ) ;
if ( F_3 ( V_1 ) )
V_1 = NULL ;
}
void F_4 ( void )
{
if ( ! V_1 )
return;
F_5 ( V_1 ) ;
V_1 = NULL ;
}
int F_6 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = V_4 -> V_7 -> V_6 ;
if ( ! V_1 )
return - V_8 ;
V_4 -> V_9 = F_2 ( F_7 ( V_6 ) , V_1 ) ;
return F_8 ( V_4 -> V_9 ) ;
}
void F_9 ( struct V_3 * V_4 )
{
if ( ! F_10 ( V_4 -> V_9 ) )
F_5 ( V_4 -> V_9 ) ;
}
struct V_10 * F_11 ( struct V_3 * V_4 )
{
return V_4 -> V_9 ;
}
int F_12 ( struct V_3 * V_4 , const char * V_11 ,
int (* F_13)( struct V_12 * V_13 , void * V_14 ) )
{
struct V_10 * V_15 ;
V_15 = F_14 ( V_4 -> V_7 -> V_6 , V_11 ,
V_4 -> V_9 , F_13 ) ;
return F_8 ( V_15 ) ;
}
