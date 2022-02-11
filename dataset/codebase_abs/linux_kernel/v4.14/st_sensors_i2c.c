static unsigned int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return F_3 ( V_4 -> V_5 ) -> V_6 ;
}
static int F_4 ( struct V_7 * V_8 ,
struct V_9 * V_5 , T_1 V_10 , T_1 * V_11 )
{
int V_12 ;
V_12 = F_5 ( F_3 ( V_5 ) , V_10 ) ;
if ( V_12 < 0 )
goto V_13;
* V_11 = V_12 & 0xff ;
V_13:
return V_12 < 0 ? V_12 : 0 ;
}
static int F_6 (
struct V_7 * V_8 , struct V_9 * V_5 ,
T_1 V_10 , int V_14 , T_1 * V_15 , bool V_16 )
{
if ( V_16 )
V_10 |= V_17 ;
return F_7 ( F_3 ( V_5 ) ,
V_10 , V_14 , V_15 ) ;
}
static int F_8 ( struct V_7 * V_8 ,
struct V_9 * V_5 , T_1 V_10 , T_1 V_15 )
{
return F_9 ( F_3 ( V_5 ) , V_10 , V_15 ) ;
}
void F_10 ( struct V_1 * V_2 ,
struct V_18 * V_19 , struct V_3 * V_4 )
{
F_11 ( V_19 , V_2 ) ;
V_2 -> V_5 . V_20 = & V_19 -> V_5 ;
V_2 -> V_21 = V_19 -> V_21 ;
V_4 -> V_5 = & V_19 -> V_5 ;
V_4 -> V_22 = & V_23 ;
V_4 -> V_24 = F_1 ;
}
int F_12 ( struct V_9 * V_5 )
{
const struct V_25 * V_26 ;
T_2 V_27 = 0 ;
if ( F_13 ( V_5 ) ) {
V_26 = F_14 ( V_5 -> V_28 -> V_29 , V_5 ) ;
if ( ! V_26 ) {
F_15 ( V_5 , L_1 ) ;
return - V_30 ;
}
V_27 = V_26 -> V_27 ;
}
return V_27 ;
}
