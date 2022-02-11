static void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = (struct V_5 * ) V_2 -> V_7 ;
struct V_8 * V_9 = & V_4 -> V_9 ;
V_9 -> V_10 ++ ;
V_9 -> V_11 += V_6 -> V_12 ;
V_2 -> V_13 = V_14 ;
V_2 -> V_4 = V_4 ;
V_2 -> V_15 = V_16 ;
F_2 ( V_2 ) ;
}
static T_1 F_3 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = (struct V_5 * ) V_2 -> V_7 ;
struct V_8 * V_9 = & V_4 -> V_9 ;
int V_17 ;
if ( F_4 ( V_4 , V_2 ) )
return V_18 ;
V_9 -> V_19 ++ ;
V_9 -> V_20 += V_6 -> V_12 ;
V_17 = V_2 -> V_13 == V_21 ;
if ( ! V_22 ) {
if ( V_17 ) {
V_9 -> V_10 ++ ;
V_9 -> V_11 += V_6 -> V_12 ;
}
F_5 ( V_2 ) ;
return V_18 ;
}
if ( V_17 ) {
struct V_23 * V_24 = V_2 -> V_25 ;
V_2 = F_6 ( V_2 , V_26 ) ;
if ( ! V_2 )
return V_18 ;
V_2 -> V_25 = V_24 ;
F_1 ( V_2 , V_4 ) ;
} else {
F_5 ( V_2 ) ;
}
return V_18 ;
}
static int F_7 ( struct V_3 * V_4 , int V_27 )
{
if ( V_4 -> V_28 & V_29 )
return - V_30 ;
if ( V_27 != V_31 && V_27 != V_32 )
return - V_33 ;
V_4 -> V_34 = V_27 ;
return 0 ;
}
static void F_8 ( struct V_3 * V_4 )
{
V_4 -> type = V_35 ;
V_4 -> V_34 = V_31 ;
V_4 -> V_36 = 0 ;
V_4 -> V_37 = 0 ;
V_4 -> V_38 = 0 ;
V_4 -> V_28 = V_39 ;
if ( V_22 )
V_4 -> V_28 |= V_40 ;
V_4 -> V_41 = & V_42 ;
V_4 -> V_43 = V_44 ;
}
static T_2 int F_9 ( void )
{
F_10 ( V_45 ) ;
if ( V_22 )
F_10 ( V_46 L_1 ) ;
return F_11 ( & V_47 ) ;
}
static T_3 void F_12 ( void )
{
F_13 ( & V_47 ) ;
}
