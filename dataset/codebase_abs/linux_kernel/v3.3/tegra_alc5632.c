static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_9 ;
struct V_10 * V_11 = V_6 -> V_11 ;
struct V_12 * V_13 = V_11 -> V_13 ;
struct V_14 * V_15 = F_2 ( V_13 ) ;
int V_16 , V_17 ;
int V_18 ;
V_16 = F_3 ( V_4 ) ;
V_17 = 512 * V_16 ;
V_18 = F_4 ( & V_15 -> V_19 , V_16 , V_17 ) ;
if ( V_18 < 0 ) {
F_5 ( V_13 -> V_20 , L_1 ) ;
return V_18 ;
}
V_18 = F_6 ( V_9 , 0 , V_17 ,
V_21 ) ;
if ( V_18 < 0 ) {
F_5 ( V_13 -> V_20 , L_2 ) ;
return V_18 ;
}
return 0 ;
}
static int F_7 ( struct V_5 * V_6 )
{
struct V_10 * V_11 = V_6 -> V_11 ;
struct V_22 * V_23 = & V_11 -> V_23 ;
F_8 ( V_11 , L_3 , V_24 ,
& V_25 ) ;
F_9 ( & V_25 ,
F_10 ( V_26 ) ,
V_26 ) ;
F_11 ( V_23 , L_4 ) ;
return 0 ;
}
static T_1 int F_12 ( struct V_27 * V_28 )
{
struct V_12 * V_13 = & V_29 ;
struct V_14 * V_15 ;
int V_30 ;
V_15 = F_13 ( & V_28 -> V_20 ,
sizeof( struct V_14 ) , V_31 ) ;
if ( ! V_15 ) {
F_5 ( & V_28 -> V_20 , L_5 ) ;
return - V_32 ;
}
V_30 = F_14 ( & V_15 -> V_19 , & V_28 -> V_20 ) ;
if ( V_30 )
return V_30 ;
V_13 -> V_20 = & V_28 -> V_20 ;
F_15 ( V_28 , V_13 ) ;
F_16 ( V_13 , V_15 ) ;
V_30 = F_17 ( V_13 ) ;
if ( V_30 ) {
F_5 ( & V_28 -> V_20 , L_6 ,
V_30 ) ;
F_18 ( & V_15 -> V_19 ) ;
return V_30 ;
}
return 0 ;
}
static int T_2 F_19 ( struct V_27 * V_28 )
{
struct V_12 * V_13 = F_20 ( V_28 ) ;
struct V_14 * V_15 = F_2 ( V_13 ) ;
F_21 ( V_13 ) ;
F_18 ( & V_15 -> V_19 ) ;
return 0 ;
}
