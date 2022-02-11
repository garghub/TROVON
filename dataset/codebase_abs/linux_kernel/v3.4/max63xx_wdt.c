static struct V_1 *
F_1 ( struct V_1 * V_2 , int V_3 )
{
while ( V_2 -> V_4 ) {
if ( V_3 <= V_2 -> V_4 ) {
if ( V_5 && V_2 -> V_6 == 0 )
return V_2 ;
if ( ! V_5 )
return V_2 ;
}
V_2 ++ ;
}
return NULL ;
}
static int F_2 ( struct V_7 * V_8 )
{
T_1 V_9 ;
F_3 ( & V_10 ) ;
V_9 = F_4 ( V_11 ) ;
F_5 ( V_9 | V_12 , V_11 ) ;
F_5 ( V_9 & ~ V_12 , V_11 ) ;
F_6 ( & V_10 ) ;
return 0 ;
}
static int F_7 ( struct V_7 * V_8 )
{
struct V_1 * V_13 = F_8 ( V_8 ) ;
T_1 V_9 ;
F_3 ( & V_10 ) ;
V_9 = F_4 ( V_11 ) ;
V_9 &= ~ V_14 ;
V_9 |= V_13 -> V_15 ;
F_5 ( V_9 , V_11 ) ;
F_6 ( & V_10 ) ;
if ( V_13 -> V_6 == 0 )
F_2 ( V_8 ) ;
return 0 ;
}
static int F_9 ( struct V_7 * V_8 )
{
T_1 V_9 ;
F_3 ( & V_10 ) ;
V_9 = F_4 ( V_11 ) ;
V_9 &= ~ V_14 ;
V_9 |= 3 ;
F_5 ( V_9 , V_11 ) ;
F_6 ( & V_10 ) ;
return 0 ;
}
static int T_2 F_10 ( struct V_16 * V_17 )
{
struct V_18 * V_19 ;
struct V_1 * V_2 ;
V_2 = (struct V_1 * ) V_17 -> V_20 -> V_21 ;
if ( V_22 < 1 || V_22 > V_23 )
V_22 = V_24 ;
F_11 ( & V_17 -> V_25 , L_1 , V_22 ) ;
V_26 = F_1 ( V_2 , V_22 ) ;
if ( ! V_26 ) {
F_12 ( & V_17 -> V_25 , L_2 ) ;
return - V_27 ;
}
F_11 ( & V_17 -> V_25 , L_3 ,
V_26 -> V_4 , V_26 -> V_6 ) ;
V_22 = V_26 -> V_4 ;
V_19 = F_13 ( V_17 , V_28 , 0 ) ;
V_11 = F_14 ( & V_17 -> V_25 , V_19 ) ;
if ( ! V_11 )
return - V_29 ;
V_30 . V_31 = V_22 ;
F_15 ( & V_30 , V_32 ) ;
F_16 ( & V_30 , V_26 ) ;
return F_17 ( & V_30 ) ;
}
static int T_3 F_18 ( struct V_16 * V_17 )
{
F_19 ( & V_30 ) ;
return 0 ;
}
