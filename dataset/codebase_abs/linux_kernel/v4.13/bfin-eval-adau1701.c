static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_9 ;
int V_10 ;
V_10 = F_2 ( V_9 , V_11 , 12288000 ,
V_12 ) ;
return V_10 ;
}
static int F_3 ( struct V_13 * V_14 )
{
struct V_15 * V_16 = & V_17 ;
V_16 -> V_18 = & V_14 -> V_18 ;
return F_4 ( & V_14 -> V_18 , & V_17 ) ;
}
