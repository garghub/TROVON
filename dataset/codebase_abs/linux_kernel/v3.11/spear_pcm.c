static struct V_1 * F_1 ( struct V_2 * V_3 ,
struct V_4 * V_5 )
{
struct V_6 * V_7 ;
V_7 = F_2 ( V_3 -> V_8 , V_5 ) ;
return F_3 ( V_7 -> V_9 , V_7 ) ;
}
static int F_4 ( struct V_10 * V_11 )
{
return F_5 ( & V_11 -> V_12 ,
& V_13 ,
V_14 |
V_15 ) ;
}
static int F_6 ( struct V_10 * V_11 )
{
F_7 ( & V_11 -> V_12 ) ;
return 0 ;
}
