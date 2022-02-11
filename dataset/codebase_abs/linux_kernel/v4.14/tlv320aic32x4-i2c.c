static int F_1 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
struct V_5 * V_5 ;
struct V_6 V_7 ;
V_7 = V_8 ;
V_7 . V_9 = 8 ;
V_7 . V_10 = 8 ;
V_5 = F_2 ( V_2 , & V_7 ) ;
return F_3 ( & V_2 -> V_11 , V_5 ) ;
}
static int F_4 ( struct V_1 * V_2 )
{
return F_5 ( & V_2 -> V_11 ) ;
}
