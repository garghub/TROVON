static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_9 ;
T_1 V_10 = F_2 ( V_4 ) ;
unsigned int V_11 = F_3 ( V_4 ) ;
unsigned int V_12 ;
int V_13 , V_14 ;
V_13 = F_4 ( V_10 ) ;
if ( V_13 < 0 ) {
F_5 ( V_9 -> V_15 , L_1 , V_13 ) ;
return V_13 ;
}
V_12 = V_11 * V_13 * 2 * V_16 ;
V_14 = F_6 ( V_6 -> V_17 , 0 , V_12 , 0 ) ;
if ( V_14 ) {
F_5 ( V_9 -> V_15 , L_2 ,
V_12 , V_14 ) ;
return V_14 ;
}
return 0 ;
}
static int F_7 ( struct V_8 * V_9 )
{
struct V_18 * V_19 = V_9 -> V_19 ;
struct V_20 * V_21 = V_9 -> V_15 -> V_22 ;
V_19 -> V_23 = F_8 ( V_21 , L_3 , 0 ) ;
if ( ! V_19 -> V_23 ) {
F_5 ( V_9 -> V_15 , L_4 ) ;
return - V_24 ;
}
V_19 -> V_25 = V_19 -> V_23 ;
V_19 -> V_26 = F_8 ( V_21 , L_5 , 0 ) ;
if ( ! V_19 -> V_26 ) {
F_5 ( V_9 -> V_15 , L_6 ) ;
return - V_24 ;
}
return 0 ;
}
static int F_9 ( struct V_27 * V_28 )
{
struct V_8 * V_9 ;
int V_14 ;
V_9 = F_10 ( & V_28 -> V_15 , sizeof( * V_9 ) , V_29 ) ;
if ( ! V_9 )
return - V_30 ;
V_9 -> V_15 = & V_28 -> V_15 ;
V_14 = F_11 ( V_9 , L_7 ) ;
if ( V_14 ) {
F_5 ( & V_28 -> V_15 , L_8 , V_14 ) ;
return V_14 ;
}
V_9 -> V_19 = & V_31 ;
V_9 -> V_32 = 1 ;
V_14 = F_7 ( V_9 ) ;
if ( V_14 ) {
F_5 ( & V_28 -> V_15 , L_9 , V_14 ) ;
return V_14 ;
}
V_14 = F_12 ( & V_28 -> V_15 , V_9 ) ;
if ( V_14 )
F_5 ( & V_28 -> V_15 , L_10 , V_14 ) ;
return V_14 ;
}
