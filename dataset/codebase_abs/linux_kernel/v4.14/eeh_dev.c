struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
V_4 = F_2 ( sizeof( * V_4 ) , V_5 ) ;
if ( ! V_4 )
return NULL ;
V_3 -> V_4 = V_4 ;
V_4 -> V_3 = V_3 ;
F_3 ( & V_4 -> V_6 ) ;
F_3 ( & V_4 -> V_7 ) ;
return V_4 ;
}
void F_4 ( struct V_8 * V_9 )
{
F_5 ( V_9 ) ;
}
