static void F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_4 = F_2 ( V_2 , struct V_4 , V_2 ) ;
F_3 ( V_4 -> V_5 , L_1 , V_6 , V_3 ) ;
if ( V_3 < 0 )
F_4 ( V_4 ) ;
else
F_5 ( V_4 ) ;
}
int F_6 ( struct V_4 * V_4 )
{
F_7 ( & V_4 -> V_2 ) ;
V_4 -> V_2 . V_7 = L_2 ;
V_4 -> V_2 . V_8 = V_4 -> V_9 . V_10 . V_11 ;
V_4 -> V_2 . V_12 = V_4 -> V_13 ;
V_4 -> V_2 . V_14 = F_1 ;
return F_8 ( & V_4 -> V_2 ) ;
}
void F_9 ( struct V_4 * V_4 )
{
if ( V_4 -> V_13 )
F_10 ( & V_4 -> V_2 ) ;
}
