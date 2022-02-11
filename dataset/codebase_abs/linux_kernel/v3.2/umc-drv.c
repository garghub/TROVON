int F_1 ( struct V_1 * V_2 , struct V_3 * V_3 ,
const char * V_4 )
{
V_2 -> V_5 . V_6 = V_2 -> V_6 ;
V_2 -> V_5 . V_7 = V_3 ;
V_2 -> V_5 . V_4 = V_4 ;
V_2 -> V_5 . V_8 = & V_9 ;
return F_2 ( & V_2 -> V_5 ) ;
}
void F_3 ( struct V_1 * V_2 )
{
F_4 ( & V_2 -> V_5 ) ;
}
