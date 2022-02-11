static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_3 ;
struct V_4 V_5 ;
V_5 = V_6 ;
V_5 . V_7 = 7 ;
V_5 . V_8 = 1 ;
V_5 . V_9 = 8 ;
V_5 . V_10 = 0x01 ;
V_3 = F_2 ( V_2 , & V_5 ) ;
return F_3 ( & V_2 -> V_11 , V_3 ) ;
}
static int F_4 ( struct V_1 * V_2 )
{
return F_5 ( & V_2 -> V_11 ) ;
}
