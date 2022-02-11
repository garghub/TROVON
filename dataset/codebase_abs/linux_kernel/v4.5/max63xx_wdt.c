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
struct V_9 * V_10 = F_3 ( V_8 ) ;
V_10 -> V_11 ( V_10 ) ;
return 0 ;
}
static int F_4 ( struct V_7 * V_8 )
{
struct V_9 * V_10 = F_3 ( V_8 ) ;
V_10 -> V_12 ( V_10 , V_10 -> V_13 -> V_14 ) ;
if ( V_10 -> V_13 -> V_6 == 0 )
V_10 -> V_11 ( V_10 ) ;
return 0 ;
}
static int F_5 ( struct V_7 * V_8 )
{
struct V_9 * V_10 = F_3 ( V_8 ) ;
V_10 -> V_12 ( V_10 , V_15 ) ;
return 0 ;
}
static void F_6 ( struct V_9 * V_10 )
{
T_1 V_16 ;
F_7 ( & V_10 -> V_17 ) ;
V_16 = F_8 ( V_10 -> V_18 ) ;
F_9 ( V_16 | V_19 , V_10 -> V_18 ) ;
F_9 ( V_16 & ~ V_19 , V_10 -> V_18 ) ;
F_10 ( & V_10 -> V_17 ) ;
}
static void F_11 ( struct V_9 * V_10 , T_1 V_12 )
{
T_1 V_16 ;
F_7 ( & V_10 -> V_17 ) ;
V_16 = F_8 ( V_10 -> V_18 ) ;
V_16 &= ~ V_20 ;
V_16 |= V_12 & V_20 ;
F_9 ( V_16 , V_10 -> V_18 ) ;
F_10 ( & V_10 -> V_17 ) ;
}
static int F_12 ( struct V_21 * V_22 , struct V_9 * V_10 )
{
struct V_23 * V_24 = F_13 ( V_22 , V_25 , 0 ) ;
V_10 -> V_18 = F_14 ( & V_22 -> V_26 , V_24 ) ;
if ( F_15 ( V_10 -> V_18 ) )
return F_16 ( V_10 -> V_18 ) ;
F_17 ( & V_10 -> V_17 ) ;
V_10 -> V_11 = F_6 ;
V_10 -> V_12 = F_11 ;
return 0 ;
}
static int F_18 ( struct V_21 * V_27 )
{
struct V_9 * V_10 ;
struct V_1 * V_2 ;
int V_28 ;
V_10 = F_19 ( & V_27 -> V_26 , sizeof( * V_10 ) , V_29 ) ;
if ( ! V_10 )
return - V_30 ;
V_2 = (struct V_1 * ) V_27 -> V_31 -> V_32 ;
if ( V_33 < 1 || V_33 > V_34 )
V_33 = V_35 ;
V_10 -> V_13 = F_1 ( V_2 , V_33 ) ;
if ( ! V_10 -> V_13 ) {
F_20 ( & V_27 -> V_26 , L_1 ,
V_33 ) ;
return - V_36 ;
}
V_28 = F_12 ( V_27 , V_10 ) ;
if ( V_28 )
return V_28 ;
F_21 ( V_27 , & V_10 -> V_8 ) ;
F_22 ( & V_10 -> V_8 , V_10 ) ;
V_10 -> V_8 . V_37 = & V_27 -> V_26 ;
V_10 -> V_8 . V_13 = V_10 -> V_13 -> V_4 ;
V_10 -> V_8 . V_38 = & V_39 ;
V_10 -> V_8 . V_40 = & V_41 ;
F_23 ( & V_10 -> V_8 , V_42 ) ;
V_28 = F_24 ( & V_10 -> V_8 ) ;
if ( V_28 )
return V_28 ;
F_25 ( & V_27 -> V_26 , L_2 ,
V_10 -> V_13 -> V_4 , V_10 -> V_13 -> V_6 ) ;
return 0 ;
}
static int F_26 ( struct V_21 * V_27 )
{
struct V_7 * V_8 = F_27 ( V_27 ) ;
F_28 ( V_8 ) ;
return 0 ;
}
