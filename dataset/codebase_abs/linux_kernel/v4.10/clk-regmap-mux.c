static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( F_3 ( V_3 ) , struct V_1 , V_4 ) ;
}
static T_1 F_4 ( struct V_2 * V_3 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_6 * V_4 = F_3 ( V_3 ) ;
unsigned int V_7 = F_5 ( V_5 -> V_8 - 1 , 0 ) ;
unsigned int V_9 ;
F_6 ( V_4 -> V_10 , V_5 -> V_11 , & V_9 ) ;
V_9 >>= V_5 -> V_12 ;
V_9 &= V_7 ;
return V_9 ;
}
static int F_7 ( struct V_2 * V_3 , T_1 V_13 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_6 * V_4 = F_3 ( V_3 ) ;
unsigned int V_7 = F_5 ( V_5 -> V_8 + V_5 -> V_12 - 1 , V_5 -> V_12 ) ;
unsigned int V_9 ;
V_9 = V_13 ;
V_9 <<= V_5 -> V_12 ;
return F_8 ( V_4 -> V_10 , V_5 -> V_11 , V_7 , V_9 ) ;
}
