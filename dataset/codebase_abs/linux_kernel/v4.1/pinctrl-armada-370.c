static int F_1 ( unsigned V_1 , unsigned long * V_2 )
{
return F_2 ( V_3 , V_1 , V_2 ) ;
}
static int F_3 ( unsigned V_1 , unsigned long V_2 )
{
return F_4 ( V_3 , V_1 , V_2 ) ;
}
static int F_5 ( struct V_4 * V_5 )
{
struct V_6 * V_7 = & V_8 ;
struct V_9 * V_10 ;
V_10 = F_6 ( V_5 , V_11 , 0 ) ;
V_3 = F_7 ( & V_5 -> V_12 , V_10 ) ;
if ( F_8 ( V_3 ) )
return F_9 ( V_3 ) ;
V_7 -> V_13 = 0 ;
V_7 -> V_14 = V_15 ;
V_7 -> V_16 = F_10 ( V_15 ) ;
V_7 -> V_17 = V_18 ;
V_7 -> V_19 = F_10 ( V_18 ) ;
V_7 -> V_20 = V_21 ;
V_7 -> V_22 = F_10 ( V_21 ) ;
V_5 -> V_12 . V_23 = V_7 ;
return F_11 ( V_5 ) ;
}
static int F_12 ( struct V_4 * V_5 )
{
return F_13 ( V_5 ) ;
}
