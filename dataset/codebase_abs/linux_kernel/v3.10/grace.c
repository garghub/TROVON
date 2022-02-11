void F_1 ( struct V_1 * V_1 , struct V_2 * V_3 )
{
struct V_4 * V_5 = F_2 ( V_1 , V_6 ) ;
F_3 ( & V_7 ) ;
F_4 ( & V_3 -> V_8 , & V_5 -> V_9 ) ;
F_5 ( & V_7 ) ;
}
void F_6 ( struct V_2 * V_3 )
{
F_3 ( & V_7 ) ;
F_7 ( & V_3 -> V_8 ) ;
F_5 ( & V_7 ) ;
}
int F_8 ( struct V_1 * V_1 )
{
struct V_4 * V_5 = F_2 ( V_1 , V_6 ) ;
return ! F_9 ( & V_5 -> V_9 ) ;
}
