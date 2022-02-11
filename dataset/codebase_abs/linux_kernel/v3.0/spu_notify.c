void F_1 ( struct V_1 * V_1 , struct V_2 * V_3 )
{
F_2 ( & V_4 ,
V_3 ? V_3 -> V_5 : 0 , V_1 ) ;
}
int F_3 ( struct V_6 * V_7 )
{
int V_8 ;
V_8 = F_4 ( & V_4 , V_7 ) ;
if ( ! V_8 )
F_5 () ;
return V_8 ;
}
int F_6 ( struct V_6 * V_7 )
{
return F_7 ( & V_4 , V_7 ) ;
}
void F_8 ( struct V_2 * V_3 ,
struct V_9 * V_10 ,
void (* F_9) ( struct V_9 * V_9 ) )
{
V_3 -> V_11 = V_10 ;
V_3 -> V_12 = F_9 ;
}
void * F_10 ( struct V_2 * V_3 )
{
return V_3 -> V_11 ;
}
