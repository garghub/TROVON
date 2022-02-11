static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_9 ;
struct V_8 * V_10 = V_6 -> V_10 ;
struct V_11 * V_12 = V_6 -> V_12 ;
struct V_13 * V_14 = V_12 -> V_14 ;
struct V_15 * V_16 = F_2 ( V_14 ) ;
int V_17 , V_18 ;
int V_19 ;
V_17 = F_3 ( V_4 ) ;
V_18 = 128 * V_17 ;
V_19 = F_4 ( & V_16 -> V_20 , V_17 , V_18 ) ;
if ( V_19 < 0 ) {
F_5 ( V_14 -> V_21 , L_1 ) ;
return V_19 ;
}
V_19 = F_6 ( V_9 ,
V_22 |
V_23 |
V_24 ) ;
if ( V_19 < 0 ) {
F_5 ( V_14 -> V_21 , L_2 ) ;
return V_19 ;
}
V_19 = F_6 ( V_10 ,
V_22 |
V_23 |
V_24 ) ;
if ( V_19 < 0 ) {
F_5 ( V_14 -> V_21 , L_3 ) ;
return V_19 ;
}
V_19 = F_7 ( V_9 , 0 , V_18 ,
V_25 ) ;
if ( V_19 < 0 ) {
F_5 ( V_14 -> V_21 , L_4 ) ;
return V_19 ;
}
return 0 ;
}
static T_1 int F_8 ( struct V_26 * V_27 )
{
struct V_13 * V_14 = & V_28 ;
struct V_15 * V_16 ;
int V_29 ;
V_16 = F_9 ( & V_27 -> V_21 , sizeof( struct V_15 ) ,
V_30 ) ;
if ( ! V_16 ) {
F_5 ( & V_27 -> V_21 , L_5 ) ;
V_29 = - V_31 ;
goto V_19;
}
V_29 = F_10 ( & V_16 -> V_20 , & V_27 -> V_21 ) ;
if ( V_29 )
goto V_19;
V_14 -> V_21 = & V_27 -> V_21 ;
F_11 ( V_27 , V_14 ) ;
F_12 ( V_14 , V_16 ) ;
V_29 = F_13 ( V_14 ) ;
if ( V_29 ) {
F_5 ( & V_27 -> V_21 , L_6 ,
V_29 ) ;
goto V_32;
}
return 0 ;
V_32:
F_14 ( & V_16 -> V_20 ) ;
V_19:
return V_29 ;
}
static int T_2 F_15 ( struct V_26 * V_27 )
{
struct V_13 * V_14 = F_16 ( V_27 ) ;
struct V_15 * V_16 = F_2 ( V_14 ) ;
F_17 ( V_14 ) ;
F_14 ( & V_16 -> V_20 ) ;
return 0 ;
}
