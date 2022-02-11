static void F_1 ( const struct V_1 * V_2 , void * V_3 )
{
struct V_4 * V_5 = V_3 ;
struct V_6 * V_7 = & V_5 -> V_7 ;
struct V_8 * V_9 = F_2 ( V_5 ) ;
struct V_10 * V_10 = & V_9 -> V_10 ;
struct V_11 * V_12 = V_9 -> V_12 ;
struct V_13 * V_14 = V_9 -> V_14 ;
V_10 -> V_2 = V_2 ;
if ( ! V_2 ) {
F_3 ( V_7 , L_1 , V_14 -> V_15 ) ;
return;
}
V_9 -> V_16 =
F_4 ( V_7 , V_12 -> V_17 , - 1 ,
V_10 , sizeof( * V_10 ) ) ;
if ( F_5 ( V_9 -> V_16 ) ) {
F_3 ( V_7 , L_2 ,
V_12 -> V_17 , ( int ) F_6 ( V_9 -> V_16 ) ) ;
}
return;
}
static int F_7 ( struct V_4 * V_5 )
{
const struct V_18 * V_19 ;
struct V_6 * V_7 = & V_5 -> V_7 ;
struct V_8 * V_9 ;
struct V_10 * V_10 ;
struct V_13 * V_14 ;
struct V_11 * V_12 ;
struct V_20 * V_21 ;
int V_22 = 0 ;
V_9 = F_8 ( V_7 , sizeof( * V_9 ) , V_23 ) ;
if ( V_9 == NULL )
return - V_24 ;
V_19 = F_9 ( V_7 -> V_25 -> V_26 , V_7 ) ;
if ( ! V_19 )
return - V_27 ;
V_12 = (struct V_11 * ) V_19 -> V_28 ;
V_14 = F_10 ( V_12 -> V_29 ) ;
if ( V_14 == NULL ) {
F_3 ( V_7 , L_3 ) ;
return - V_27 ;
}
V_10 = & V_9 -> V_10 ;
V_10 -> V_19 = V_12 -> V_30 ;
V_10 -> V_31 = V_7 ;
V_9 -> V_12 = V_12 ;
V_9 -> V_14 = V_14 ;
V_10 -> V_32 = V_12 -> V_32 ;
if ( V_12 -> V_32 >= 0 ) {
V_10 -> V_33 = V_12 -> V_33 ;
V_10 -> V_34 = V_12 -> V_32 ;
V_10 -> V_35 = V_12 -> V_35 ;
}
if ( V_12 -> V_36 >= 0 )
V_10 -> V_37 = F_11 ( V_5 , V_12 -> V_36 ) ;
if ( V_12 -> V_38 >= 0 ) {
V_21 = F_12 ( V_5 , V_39 ,
V_12 -> V_38 ) ;
if ( V_21 ) {
V_10 -> V_40 = V_21 -> V_41 ;
V_10 -> V_42 = F_13 ( V_21 ) ;
}
}
if ( V_12 -> V_43 >= 0 ) {
V_21 = F_12 ( V_5 , V_39 ,
V_12 -> V_43 ) ;
if ( V_21 ) {
V_10 -> V_44 = V_21 -> V_41 ;
V_10 -> V_45 = F_13 ( V_21 ) ;
}
}
if ( V_12 -> V_46 >= 0 ) {
V_21 = F_12 ( V_5 , V_39 ,
V_12 -> V_46 ) ;
if ( V_21 ) {
V_10 -> V_47 = V_21 -> V_41 ;
V_10 -> V_48 = F_13 ( V_21 ) ;
}
}
F_14 ( V_5 , V_9 ) ;
V_9 -> V_49 =
F_4 ( V_7 , V_14 -> V_17 , - 1 ,
V_10 , sizeof( * V_10 ) ) ;
if ( F_5 ( V_9 -> V_49 ) )
return F_6 ( V_9 -> V_49 ) ;
V_22 = F_15 ( V_50 , true , V_14 -> V_15 ,
V_7 , V_23 , V_5 , F_1 ) ;
if ( V_22 )
F_16 ( V_9 -> V_49 ) ;
return V_22 ;
}
static int F_17 ( struct V_4 * V_5 )
{
struct V_8 * V_9 = F_2 ( V_5 ) ;
struct V_10 * V_10 = & V_9 -> V_10 ;
F_16 ( V_9 -> V_49 ) ;
if ( ! F_18 ( V_9 -> V_16 ) )
F_16 ( V_9 -> V_16 ) ;
F_19 ( V_10 -> V_2 ) ;
return 0 ;
}
