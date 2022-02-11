static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
static int F_3 ( struct V_2 * V_5 , struct V_6 * V_7 )
{
struct V_1 * V_8 = F_1 ( V_5 ) ;
F_4 ( V_8 -> V_9 , V_10 , 1 ) ;
return 0 ;
}
static void F_5 ( struct V_2 * V_5 , struct V_6 * V_7 )
{
struct V_1 * V_8 = F_1 ( V_5 ) ;
F_4 ( V_8 -> V_9 , V_10 , 0 ) ;
}
static int F_6 ( struct V_2 * V_5 , struct V_6 * V_7 ,
int V_11 , int V_12 )
{
struct V_1 * V_8 = F_1 ( V_5 ) ;
struct V_13 * V_14 = V_8 -> V_4 . V_14 ;
int V_15 ;
if ( V_12 > V_16 ) {
F_7 ( V_14 , L_1 ) ;
return - V_17 ;
}
if ( V_7 -> V_18 != V_12 ) {
int V_19 ;
F_5 ( V_5 , V_7 ) ;
V_19 = V_20 * V_12 / V_21 ;
F_4 ( V_8 -> V_9 , V_22 ,
V_19 | V_23 ) ;
F_3 ( V_5 , V_7 ) ;
}
V_15 = V_11 * V_24 / V_12 ;
F_4 ( V_8 -> V_9 , V_25 , V_15 ) ;
return 0 ;
}
static int F_8 ( struct V_26 * V_27 )
{
struct V_1 * V_7 ;
struct V_13 * V_14 = V_27 -> V_14 . V_28 ;
struct V_29 * V_30 = F_9 ( V_14 ) ;
V_7 = F_10 ( & V_27 -> V_14 , sizeof( * V_7 ) , V_31 ) ;
if ( ! V_7 )
return - V_32 ;
V_7 -> V_4 . V_14 = & V_27 -> V_14 ;
V_7 -> V_4 . V_33 = & V_34 ;
V_7 -> V_4 . V_35 = - 1 ;
V_7 -> V_4 . V_36 = 1 ;
V_7 -> V_9 = V_30 -> V_9 ;
F_11 ( V_27 , V_7 ) ;
return F_12 ( & V_7 -> V_4 ) ;
}
static int F_13 ( struct V_26 * V_27 )
{
struct V_1 * V_7 = F_14 ( V_27 ) ;
return F_15 ( & V_7 -> V_4 ) ;
}
