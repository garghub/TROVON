static void F_1 ( struct V_1 * V_2 , unsigned V_3 , int V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
unsigned int V_7 ;
V_7 = F_3 ( V_6 -> V_8 + V_9 ) ;
if ( V_4 )
V_7 = V_7 | F_4 ( V_3 ) ;
else
V_7 = V_7 & ~ F_4 ( V_3 ) ;
F_5 ( V_7 , V_6 -> V_8 + V_9 ) ;
}
static int F_6 ( struct V_1 * V_2 , unsigned V_3 )
{
unsigned int V_7 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_7 = F_3 ( V_6 -> V_8 + V_10 ) ;
V_7 = V_7 | F_4 ( V_3 ) ;
F_5 ( V_7 , V_6 -> V_8 + V_10 ) ;
return 0 ;
}
static int F_7 ( struct V_1 * V_2 , unsigned V_3 , int V_4 )
{
unsigned int V_7 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_1 ( V_6 -> V_8 + V_9 , V_3 , V_4 ) ;
V_7 = F_3 ( V_6 -> V_8 + V_10 ) ;
V_7 = V_7 & ~ F_4 ( V_3 ) ;
F_5 ( V_7 , V_6 -> V_8 + V_10 ) ;
return 0 ;
}
static int F_8 ( struct V_1 * V_2 , unsigned V_3 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
return ! ! ( F_3 ( V_6 -> V_8 + V_11 ) & F_4 ( V_3 ) ) ;
}
static int T_1 F_9 ( struct V_12 * V_13 )
{
const struct V_14 * V_15 =
F_10 ( V_16 , & V_13 -> V_17 ) ;
struct V_5 * V_6 ;
V_6 = F_11 ( & V_13 -> V_17 , sizeof( * V_6 ) , V_18 ) ;
if ( ! V_6 )
return - V_19 ;
V_6 -> V_20 . V_21 = ( V_22 ) ( V_23 ) V_15 -> V_7 ;
V_6 -> V_20 . V_24 = 2 ;
V_6 -> V_20 . V_25 = F_6 ;
V_6 -> V_20 . V_26 = F_7 ;
V_6 -> V_20 . V_27 = F_8 ;
V_6 -> V_20 . V_28 = F_1 ;
return F_12 ( V_13 -> V_17 . V_29 , V_6 ) ;
}
