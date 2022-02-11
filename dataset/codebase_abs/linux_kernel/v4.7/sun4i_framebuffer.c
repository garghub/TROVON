static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( V_4 -> V_6 )
F_2 ( V_4 -> V_6 ) ;
}
struct V_7 * F_3 ( struct V_1 * V_2 )
{
F_4 ( V_2 ) ;
V_2 -> V_8 . V_9 = 8192 ;
V_2 -> V_8 . V_10 = 8192 ;
V_2 -> V_8 . V_11 = & V_12 ;
return F_5 ( V_2 , 32 ,
V_2 -> V_8 . V_13 ,
V_2 -> V_8 . V_14 ) ;
}
void F_6 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_7 ( V_4 -> V_6 ) ;
F_8 ( V_2 ) ;
}
