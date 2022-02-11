static void F_1 ( struct V_1 * V_2 , T_1 * V_3 )
{
* V_3 |= V_4 ;
}
static int F_2 ( struct V_1 * V_2 )
{
V_2 -> V_5 /= V_6 ;
return 0 ;
}
static void F_3 ( struct V_1 * V_2 , struct V_7 * V_8 )
{
int V_9 ;
unsigned int V_10 ;
T_1 V_5 ;
if ( V_8 -> V_11 == V_12 &&
V_8 -> V_13 == V_14 )
V_10 = 2 * V_8 -> clock * V_6 ;
else
V_10 = V_8 -> clock * V_6 ;
V_9 = F_4 ( V_2 -> V_15 , V_10 ) ;
if ( V_9 )
F_5 ( V_2 -> V_16 , L_1 , V_8 -> clock ) ;
V_5 = F_6 ( V_2 -> V_15 ) / V_6 ;
if ( V_5 != V_2 -> V_5 ) {
V_2 -> V_5 = V_5 ;
V_2 -> V_17 = 0 ;
}
}
static int F_7 ( struct V_18 * V_19 )
{
const struct V_20 * V_21 ;
const struct V_22 * V_23 ;
if ( ! V_19 -> V_16 . V_24 )
return - V_25 ;
V_23 = F_8 ( V_26 , V_19 -> V_16 . V_24 ) ;
V_21 = V_23 -> V_27 ;
return F_9 ( V_19 , V_21 ) ;
}
static int F_10 ( struct V_28 * V_16 )
{
struct V_1 * V_2 = F_11 ( V_16 ) ;
return F_12 ( V_2 ) ;
}
static int F_13 ( struct V_28 * V_16 )
{
struct V_1 * V_2 = F_11 ( V_16 ) ;
return F_14 ( V_2 ) ;
}
