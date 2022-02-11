static void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = (struct V_5 * ) V_2 -> V_7 ;
struct V_8 * V_9 = & V_4 -> V_9 ;
V_9 -> V_10 ++ ;
V_9 -> V_11 += V_6 -> V_12 ;
V_2 -> V_13 = F_2 ( V_14 ) ;
V_2 -> V_15 = V_16 ;
V_2 -> V_4 = V_4 ;
V_2 -> V_17 = V_18 ;
F_3 ( V_2 ) ;
}
static T_1 F_4 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = (struct V_5 * ) V_2 -> V_7 ;
struct V_8 * V_9 = & V_4 -> V_9 ;
int V_19 ;
if ( F_5 ( V_4 , V_2 ) )
return V_20 ;
V_9 -> V_21 ++ ;
V_9 -> V_22 += V_6 -> V_12 ;
V_19 = V_2 -> V_15 == V_23 ;
if ( ! V_24 ) {
if ( V_19 ) {
V_9 -> V_10 ++ ;
V_9 -> V_11 += V_6 -> V_12 ;
}
F_6 ( V_2 ) ;
return V_20 ;
}
if ( V_19 ) {
struct V_25 * V_26 = V_2 -> V_27 ;
V_2 = F_7 ( V_2 , V_28 ) ;
if ( ! V_2 )
return V_20 ;
V_2 -> V_27 = V_26 ;
F_1 ( V_2 , V_4 ) ;
} else {
F_6 ( V_2 ) ;
}
return V_20 ;
}
static void F_8 ( struct V_3 * V_4 )
{
V_4 -> type = V_29 ;
V_4 -> V_30 = sizeof( struct V_5 ) ;
V_4 -> V_31 = 0 ;
V_4 -> V_32 = 0 ;
V_4 -> V_33 = 0 ;
V_4 -> V_34 = V_35 ;
if ( V_24 )
V_4 -> V_34 |= V_36 ;
V_4 -> V_37 = & V_38 ;
V_4 -> V_39 = V_40 ;
}
static T_2 int F_9 ( void )
{
F_10 ( V_41 ) ;
if ( V_24 )
F_10 ( V_42 L_1 ) ;
return F_11 ( & V_43 ) ;
}
static T_3 void F_12 ( void )
{
F_13 ( & V_43 ) ;
}
