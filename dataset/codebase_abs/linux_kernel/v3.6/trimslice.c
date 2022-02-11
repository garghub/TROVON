static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_9 ;
struct V_10 * V_11 = V_9 -> V_11 ;
struct V_12 * V_13 = V_11 -> V_13 ;
struct V_14 * V_15 = F_2 ( V_13 ) ;
int V_16 , V_17 ;
int V_18 ;
V_16 = F_3 ( V_4 ) ;
V_17 = 128 * V_16 ;
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
static T_1 int F_7 ( struct V_22 * V_23 )
{
struct V_12 * V_13 = & V_24 ;
struct V_14 * V_15 ;
int V_25 ;
V_15 = F_8 ( & V_23 -> V_20 , sizeof( struct V_14 ) ,
V_26 ) ;
if ( ! V_15 ) {
F_5 ( & V_23 -> V_20 , L_3 ) ;
V_25 = - V_27 ;
goto V_18;
}
if ( V_23 -> V_20 . V_28 ) {
V_29 . V_30 = NULL ;
V_29 . V_31 = F_9 (
V_23 -> V_20 . V_28 , L_4 , 0 ) ;
if ( ! V_29 . V_31 ) {
F_5 ( & V_23 -> V_20 ,
L_5 ) ;
V_25 = - V_32 ;
goto V_18;
}
V_29 . V_33 = NULL ;
V_29 . V_34 = F_9 (
V_23 -> V_20 . V_28 , L_6 , 0 ) ;
if ( ! V_29 . V_34 ) {
F_5 ( & V_23 -> V_20 ,
L_7 ) ;
V_25 = - V_32 ;
goto V_18;
}
V_29 . V_35 = NULL ;
V_29 . V_36 =
V_29 . V_34 ;
}
V_25 = F_10 ( & V_15 -> V_19 , & V_23 -> V_20 ) ;
if ( V_25 )
goto V_18;
V_13 -> V_20 = & V_23 -> V_20 ;
F_11 ( V_23 , V_13 ) ;
F_12 ( V_13 , V_15 ) ;
V_25 = F_13 ( V_13 ) ;
if ( V_25 ) {
F_5 ( & V_23 -> V_20 , L_8 ,
V_25 ) ;
goto V_37;
}
return 0 ;
V_37:
F_14 ( & V_15 -> V_19 ) ;
V_18:
return V_25 ;
}
static int T_2 F_15 ( struct V_22 * V_23 )
{
struct V_12 * V_13 = F_16 ( V_23 ) ;
struct V_14 * V_15 = F_2 ( V_13 ) ;
F_17 ( V_13 ) ;
F_14 ( & V_15 -> V_19 ) ;
return 0 ;
}
