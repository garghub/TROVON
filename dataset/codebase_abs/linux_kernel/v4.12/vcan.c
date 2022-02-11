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
V_2 = F_6 ( V_2 ) ;
if ( ! V_2 )
return V_18 ;
F_1 ( V_2 , V_4 ) ;
} else {
F_5 ( V_2 ) ;
}
return V_18 ;
}
static int F_7 ( struct V_3 * V_4 , int V_23 )
{
if ( V_4 -> V_24 & V_25 )
return - V_26 ;
if ( V_23 != V_27 && V_23 != V_28 )
return - V_29 ;
V_4 -> V_30 = V_23 ;
return 0 ;
}
static void F_8 ( struct V_3 * V_4 )
{
V_4 -> type = V_31 ;
V_4 -> V_30 = V_28 ;
V_4 -> V_32 = 0 ;
V_4 -> V_33 = 0 ;
V_4 -> V_34 = 0 ;
V_4 -> V_24 = V_35 ;
if ( V_22 )
V_4 -> V_24 |= V_36 ;
V_4 -> V_37 = & V_38 ;
V_4 -> V_39 = true ;
}
static T_2 int F_9 ( void )
{
F_10 ( L_1 ) ;
if ( V_22 )
F_11 ( V_40 L_2 ) ;
return F_12 ( & V_41 ) ;
}
static T_3 void F_13 ( void )
{
F_14 ( & V_41 ) ;
}
