static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = V_2 -> V_4 ;
F_2 ( V_3 -> V_5 ) ;
}
int F_3 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = V_2 -> V_4 ;
struct V_6 * V_5 ;
V_2 -> V_7 . V_8 = 0 ;
V_2 -> V_7 . V_9 = 0 ;
V_2 -> V_7 . V_10 = 4096 ;
V_2 -> V_7 . V_11 = 4096 ;
V_2 -> V_7 . V_12 = & V_13 ;
V_5 = F_4 ( V_2 , 32 , V_2 -> V_7 . V_14 ,
V_2 -> V_7 . V_15 ) ;
if ( F_5 ( V_5 ) )
return F_6 ( V_5 ) ;
V_3 -> V_5 = V_5 ;
return 0 ;
}
void F_7 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = V_2 -> V_4 ;
F_8 ( V_3 -> V_5 ) ;
}
