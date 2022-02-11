static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( F_3 ( V_3 ) , struct V_1 , V_4 ) ;
}
static long F_4 ( struct V_2 * V_3 , unsigned long V_5 ,
unsigned long * V_6 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
return F_5 ( V_3 , V_5 , V_6 , NULL , V_7 -> V_8 ,
V_9 ) ;
}
static int F_6 ( struct V_2 * V_3 , unsigned long V_5 ,
unsigned long V_10 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
struct V_11 * V_4 = & V_7 -> V_4 ;
T_1 div ;
div = F_7 ( V_5 , V_10 , NULL , V_7 -> V_8 ,
V_9 ) ;
return F_8 ( V_4 -> V_12 , V_7 -> V_13 ,
( F_9 ( V_7 -> V_8 ) - 1 ) << V_7 -> V_14 ,
div << V_7 -> V_14 ) ;
}
static unsigned long F_10 ( struct V_2 * V_3 ,
unsigned long V_10 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
struct V_11 * V_4 = & V_7 -> V_4 ;
T_1 div ;
F_11 ( V_4 -> V_12 , V_7 -> V_13 , & div ) ;
div >>= V_7 -> V_14 ;
div &= F_9 ( V_7 -> V_8 ) - 1 ;
return F_12 ( V_3 , V_10 , div , NULL ,
V_9 ) ;
}
