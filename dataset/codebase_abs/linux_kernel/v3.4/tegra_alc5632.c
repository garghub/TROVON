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
struct V_24 * V_25 = V_11 -> V_13 -> V_20 -> V_26 ;
struct V_14 * V_27 = F_2 ( V_11 -> V_13 ) ;
F_8 ( V_11 , L_3 , V_28 ,
& V_29 ) ;
F_9 ( & V_29 ,
F_10 ( V_30 ) ,
V_30 ) ;
V_27 -> V_31 = F_11 ( V_25 , L_4 , 0 ) ;
if ( F_12 ( V_27 -> V_31 ) ) {
V_32 . V_33 = V_27 -> V_31 ;
F_13 ( & V_29 ,
1 ,
& V_32 ) ;
V_27 -> V_34 |= V_35 ;
}
F_14 ( V_23 , L_5 ) ;
return 0 ;
}
static T_1 int F_15 ( struct V_36 * V_37 )
{
struct V_12 * V_13 = & V_38 ;
struct V_14 * V_15 ;
int V_39 ;
V_15 = F_16 ( & V_37 -> V_20 ,
sizeof( struct V_14 ) , V_40 ) ;
if ( ! V_15 ) {
F_5 ( & V_37 -> V_20 , L_6 ) ;
V_39 = - V_41 ;
goto V_18;
}
V_13 -> V_20 = & V_37 -> V_20 ;
F_17 ( V_37 , V_13 ) ;
F_18 ( V_13 , V_15 ) ;
V_15 -> V_42 = F_19 ( - V_43 ) ;
if ( ! ( V_37 -> V_20 . V_26 ) ) {
F_5 ( & V_37 -> V_20 , L_7 ) ;
V_39 = - V_43 ;
goto V_18;
}
V_39 = F_20 ( V_13 , L_8 ) ;
if ( V_39 )
goto V_18;
V_39 = F_21 ( V_13 , L_9 ) ;
if ( V_39 )
goto V_18;
V_44 . V_45 = F_22 (
V_37 -> V_20 . V_26 , L_10 , 0 ) ;
if ( ! V_44 . V_45 ) {
F_5 ( & V_37 -> V_20 ,
L_11 ) ;
V_39 = - V_43 ;
goto V_18;
}
V_44 . V_46 = F_22 (
V_37 -> V_20 . V_26 , L_12 , 0 ) ;
if ( ! V_44 . V_46 ) {
F_5 ( & V_37 -> V_20 ,
L_13 ) ;
V_39 = - V_43 ;
goto V_18;
}
V_15 -> V_42 = F_23 (
L_14 , - 1 , NULL , 0 ) ;
if ( F_24 ( V_15 -> V_42 ) ) {
F_5 ( & V_37 -> V_20 ,
L_15 ) ;
V_39 = F_25 ( V_15 -> V_42 ) ;
goto V_18;
}
V_39 = F_26 ( & V_15 -> V_19 , & V_37 -> V_20 ) ;
if ( V_39 )
goto V_47;
V_39 = F_27 ( V_13 ) ;
if ( V_39 ) {
F_5 ( & V_37 -> V_20 , L_16 ,
V_39 ) ;
goto V_48;
}
return 0 ;
V_48:
F_28 ( & V_15 -> V_19 ) ;
V_47:
if ( ! F_24 ( V_15 -> V_42 ) )
F_29 ( V_15 -> V_42 ) ;
V_18:
return V_39 ;
}
static int T_2 F_30 ( struct V_36 * V_37 )
{
struct V_12 * V_13 = F_31 ( V_37 ) ;
struct V_14 * V_27 = F_2 ( V_13 ) ;
if ( V_27 -> V_34 & V_35 )
F_32 ( & V_29 ,
1 ,
& V_32 ) ;
V_27 -> V_34 = 0 ;
F_33 ( V_13 ) ;
F_28 ( & V_27 -> V_19 ) ;
if ( ! F_24 ( V_27 -> V_42 ) )
F_29 ( V_27 -> V_42 ) ;
return 0 ;
}
