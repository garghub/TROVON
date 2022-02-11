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
F_5 ( V_9 -> V_15 , L_1 ,
V_16 , V_13 ) ;
return V_13 ;
}
V_12 = V_11 * V_13 * 2 * V_17 ;
V_14 = F_6 ( V_6 -> V_18 , 0 , V_12 , 0 ) ;
if ( V_14 ) {
F_5 ( V_9 -> V_15 , L_2 ,
V_16 , V_12 , V_14 ) ;
return V_14 ;
}
return 0 ;
}
static int F_7 ( struct V_8 * V_9 )
{
struct V_19 * V_20 = V_9 -> V_20 ;
struct V_21 * V_22 = V_9 -> V_15 -> V_23 ;
V_20 -> V_24 = F_8 ( V_22 , L_3 , 0 ) ;
if ( ! V_20 -> V_24 ) {
F_5 ( V_9 -> V_15 , L_4 ,
V_16 ) ;
return - V_25 ;
}
V_20 -> V_26 = V_20 -> V_24 ;
V_20 -> V_27 = F_8 ( V_22 , L_5 , 0 ) ;
if ( ! V_20 -> V_27 ) {
F_5 ( V_9 -> V_15 , L_6 ,
V_16 ) ;
return - V_25 ;
}
return 0 ;
}
static int F_9 ( struct V_28 * V_29 )
{
struct V_8 * V_9 ;
int V_14 ;
V_9 = F_10 ( & V_29 -> V_15 , sizeof( * V_9 ) , V_30 ) ;
if ( ! V_9 )
return - V_31 ;
V_9 -> V_15 = & V_29 -> V_15 ;
F_11 ( V_29 , V_9 ) ;
V_14 = F_12 ( V_9 , L_7 ) ;
if ( V_14 ) {
F_5 ( & V_29 -> V_15 , L_8 ,
V_16 , V_14 ) ;
return V_14 ;
}
V_9 -> V_20 = & V_32 ;
V_9 -> V_33 = 1 ;
V_14 = F_7 ( V_9 ) ;
if ( V_14 ) {
F_5 ( & V_29 -> V_15 , L_9 ,
V_16 , V_14 ) ;
return V_14 ;
}
V_14 = F_13 ( & V_29 -> V_15 , V_9 ) ;
if ( V_14 )
F_5 ( & V_29 -> V_15 , L_10 ,
V_16 , V_14 ) ;
return V_14 ;
}
