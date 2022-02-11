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
if ( V_8 -> clock == 0 )
return;
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
static int F_7 ( struct V_1 * V_2 )
{
V_2 -> V_18 = 8 ;
return 0 ;
}
static int F_8 ( struct V_19 * V_20 )
{
const struct V_21 * V_22 ;
const struct V_23 * V_24 ;
if ( ! V_20 -> V_16 . V_25 )
return - V_26 ;
V_24 = F_9 ( V_27 , V_20 -> V_16 . V_25 ) ;
V_22 = V_24 -> V_28 ;
return F_10 ( V_20 , V_22 ) ;
}
static int F_11 ( struct V_29 * V_16 )
{
struct V_1 * V_2 = F_12 ( V_16 ) ;
return F_13 ( V_2 ) ;
}
static int F_14 ( struct V_29 * V_16 )
{
struct V_1 * V_2 = F_12 ( V_16 ) ;
return F_15 ( V_2 ) ;
}
