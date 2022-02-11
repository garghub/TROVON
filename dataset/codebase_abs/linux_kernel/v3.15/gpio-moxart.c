static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
static int F_3 ( struct V_2 * V_3 , unsigned V_5 )
{
return F_4 ( V_5 ) ;
}
static void F_5 ( struct V_2 * V_3 , unsigned V_5 )
{
F_6 ( V_5 ) ;
}
static void F_7 ( struct V_2 * V_3 , unsigned V_5 , int V_6 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
void T_1 * V_8 = V_7 -> V_9 + V_10 ;
T_2 V_11 = F_8 ( V_8 ) ;
if ( V_6 )
V_11 = V_11 | F_9 ( V_5 ) ;
else
V_11 = V_11 & ~ F_9 ( V_5 ) ;
F_10 ( V_11 , V_8 ) ;
}
static int F_11 ( struct V_2 * V_3 , unsigned V_5 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
T_2 V_12 = F_8 ( V_7 -> V_9 + V_13 ) ;
if ( V_12 & F_9 ( V_5 ) )
return ! ! ( F_8 ( V_7 -> V_9 + V_10 ) & F_9 ( V_5 ) ) ;
else
return ! ! ( F_8 ( V_7 -> V_9 + V_14 ) & F_9 ( V_5 ) ) ;
}
static int F_12 ( struct V_2 * V_3 , unsigned V_5 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
void T_1 * V_8 = V_7 -> V_9 + V_13 ;
F_10 ( F_8 ( V_8 ) & ~ F_9 ( V_5 ) , V_8 ) ;
return 0 ;
}
static int F_13 ( struct V_2 * V_3 ,
unsigned V_5 , int V_6 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
void T_1 * V_8 = V_7 -> V_9 + V_13 ;
F_7 ( V_3 , V_5 , V_6 ) ;
F_10 ( F_8 ( V_8 ) | F_9 ( V_5 ) , V_8 ) ;
return 0 ;
}
static int F_14 ( struct V_15 * V_16 )
{
struct V_17 * V_18 = & V_16 -> V_18 ;
struct V_19 * V_20 ;
struct V_1 * V_21 ;
int V_12 ;
V_21 = F_15 ( V_18 , sizeof( * V_21 ) , V_22 ) ;
if ( ! V_21 ) {
F_16 ( V_18 , L_1 ) ;
return - V_23 ;
}
V_21 -> V_4 = V_24 ;
V_20 = F_17 ( V_16 , V_25 , 0 ) ;
V_21 -> V_9 = F_18 ( V_18 , V_20 ) ;
if ( F_19 ( V_21 -> V_9 ) )
return F_20 ( V_21 -> V_9 ) ;
V_21 -> V_4 . V_18 = V_18 ;
V_12 = F_21 ( & V_21 -> V_4 ) ;
if ( V_12 ) {
F_16 ( V_18 , L_2 ,
V_18 -> V_26 -> V_27 ) ;
return V_12 ;
}
return 0 ;
}
