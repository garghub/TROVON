static void F_1 ( struct V_1 * V_2 , int V_3 )
{
T_1 V_4 ;
V_4 = F_2 ( V_2 -> V_5 + V_6 ) ;
if ( V_3 ) {
V_4 &= ~ ( V_7 | V_8 |
V_9 | V_10 ) ;
V_4 |= V_11 | V_12 ;
} else {
V_4 &= ~ ( V_11 | V_12 ) ;
}
F_3 ( V_4 , V_2 -> V_5 + V_6 ) ;
}
static int F_4 ( struct V_2 * V_13 )
{
struct V_1 * V_2 = F_5 ( V_13 ) ;
T_1 V_4 ;
V_4 = F_2 ( V_2 -> V_5 + V_14 ) ;
V_4 &= ~ V_15 ;
V_4 |= V_16 ;
F_3 ( V_4 , V_2 -> V_5 + V_14 ) ;
F_3 ( V_4 & ~ V_16 , V_2 -> V_5 + V_14 ) ;
F_6 ( 2 ) ;
F_3 ( V_4 | V_16 , V_2 -> V_5 + V_14 ) ;
return 0 ;
}
static int F_7 ( struct V_2 * V_13 )
{
struct V_1 * V_2 = F_5 ( V_13 ) ;
F_1 ( V_2 , 1 ) ;
return 0 ;
}
static int F_8 ( struct V_2 * V_13 )
{
struct V_1 * V_2 = F_5 ( V_13 ) ;
F_1 ( V_2 , 0 ) ;
return 0 ;
}
static int F_9 ( struct V_17 * V_18 )
{
struct V_19 * V_20 = & V_18 -> V_20 ;
struct V_1 * V_2 ;
struct V_21 * V_22 ;
struct V_2 * V_13 ;
struct V_23 * V_23 ;
V_2 = F_10 ( V_20 , sizeof( * V_2 ) , V_24 ) ;
if ( ! V_2 )
return - V_25 ;
V_22 = F_11 ( V_18 , V_26 , 0 ) ;
V_2 -> V_5 = F_12 ( & V_18 -> V_20 , V_22 ) ;
if ( F_13 ( V_2 -> V_5 ) )
return F_14 ( V_2 -> V_5 ) ;
F_15 ( V_18 , V_2 ) ;
V_13 = F_16 ( V_20 , & V_27 , NULL ) ;
if ( F_13 ( V_13 ) )
return F_14 ( V_13 ) ;
F_17 ( V_13 , 8 ) ;
F_18 ( V_13 , V_2 ) ;
V_23 = F_19 ( V_20 ,
V_28 ) ;
if ( F_13 ( V_23 ) )
return F_14 ( V_23 ) ;
return 0 ;
}
