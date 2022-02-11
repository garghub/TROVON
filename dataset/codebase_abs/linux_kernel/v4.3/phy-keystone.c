static inline T_1 F_1 ( void T_2 * V_1 , T_1 V_2 )
{
return F_2 ( V_1 + V_2 ) ;
}
static inline void F_3 ( void T_2 * V_1 ,
T_1 V_2 , T_1 V_3 )
{
F_4 ( V_3 , V_1 + V_2 ) ;
}
static int F_5 ( struct V_4 * V_5 )
{
struct V_6 * V_7 = F_6 ( V_5 -> V_8 ) ;
T_1 V_9 ;
V_9 = F_1 ( V_7 -> V_10 , V_11 ) ;
F_3 ( V_7 -> V_10 , V_11 ,
V_9 | V_12 ) ;
return 0 ;
}
static void F_7 ( struct V_4 * V_5 )
{
struct V_6 * V_7 = F_6 ( V_5 -> V_8 ) ;
T_1 V_9 ;
V_9 = F_1 ( V_7 -> V_10 , V_11 ) ;
F_3 ( V_7 -> V_10 , V_11 ,
V_9 &= ~ V_12 ) ;
}
static int F_8 ( struct V_13 * V_14 )
{
struct V_15 * V_8 = & V_14 -> V_8 ;
struct V_6 * V_7 ;
struct V_16 * V_17 ;
int V_18 ;
V_7 = F_9 ( V_8 , sizeof( * V_7 ) , V_19 ) ;
if ( ! V_7 )
return - V_20 ;
V_17 = F_10 ( V_14 , V_21 , 0 ) ;
V_7 -> V_10 = F_11 ( V_8 , V_17 ) ;
if ( F_12 ( V_7 -> V_10 ) )
return F_13 ( V_7 -> V_10 ) ;
V_18 = F_14 ( V_8 , & V_7 -> V_22 , NULL ) ;
if ( V_18 )
return V_18 ;
V_7 -> V_22 . V_5 . V_23 = F_5 ;
V_7 -> V_22 . V_5 . V_24 = F_7 ;
F_15 ( V_14 , V_7 ) ;
return F_16 ( & V_7 -> V_22 . V_5 ) ;
}
static int F_17 ( struct V_13 * V_14 )
{
struct V_6 * V_7 = F_18 ( V_14 ) ;
F_19 ( & V_7 -> V_22 . V_5 ) ;
return 0 ;
}
