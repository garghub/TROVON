static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = V_2 ;
struct V_5 * V_6 = V_4 -> V_7 ;
if ( F_2 ( V_6 -> V_8 ) ) {
F_3 ( V_6 -> V_1 , V_9 ) ;
F_4 ( V_6 -> V_1 , V_2 ) ;
} else {
F_3 ( V_6 -> V_1 , V_10 ) ;
}
return V_11 ;
}
static void F_5 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_12 * V_13 ;
V_13 = V_4 -> V_14 [ 0 ] ;
V_13 -> V_15 = & V_16 ;
V_13 -> V_17 = V_18 ;
V_13 -> V_19 . V_20 = V_6 -> V_21 + V_22 ;
V_13 -> V_19 . V_23 = V_6 -> V_21 + V_24 ;
V_13 -> V_19 . V_25 = V_6 -> V_21 + V_24 ;
F_6 ( & V_13 -> V_19 ) ;
V_13 -> V_19 . V_26 = V_6 -> V_21 + V_27 ;
V_13 -> V_19 . V_28 = V_6 -> V_21 + V_29 ;
}
static int F_7 ( struct V_30 * V_31 )
{
int V_1 ;
int V_32 ;
struct V_33 * V_34 ;
struct V_3 * V_4 ;
struct V_5 * V_6 ;
int V_35 ;
V_34 = F_8 ( V_31 , V_36 , 0 ) ;
if ( ! V_34 ) {
F_9 ( & V_31 -> V_37 , L_1 ) ;
return - V_38 ;
}
V_1 = F_10 ( V_31 , 0 ) ;
if ( V_1 <= 0 ) {
F_9 ( & V_31 -> V_37 , L_2 ) ;
return - V_39 ;
}
V_32 = F_11 ( V_1 ) ;
if ( V_32 < 0 ) {
F_9 ( & V_31 -> V_37 , L_3 , V_1 ) ;
return - V_39 ;
}
V_35 = F_12 ( V_32 , V_40 ) ;
if ( V_35 ) {
F_9 ( & V_31 -> V_37 , L_4 ) ;
return V_35 ;
}
V_4 = F_13 ( & V_31 -> V_37 , V_41 ) ;
if ( ! V_4 )
return - V_42 ;
F_14 ( V_31 , V_4 ) ;
V_6 = F_15 ( & V_31 -> V_37 , sizeof( * V_6 ) , V_43 ) ;
if ( ! V_6 )
return - V_42 ;
V_4 -> V_7 = V_6 ;
V_6 -> V_8 = V_32 ;
V_6 -> V_1 = V_1 ;
V_6 -> V_21 = F_16 ( & V_31 -> V_37 , V_34 -> V_44 ,
F_17 ( V_34 ) ) ;
if ( ! V_6 -> V_21 )
return - V_42 ;
V_35 = F_18 ( V_32 ) ;
if ( V_35 ) {
F_9 ( & V_31 -> V_37 , L_5 ,
V_35 ) ;
goto V_45;
}
F_5 ( V_4 ) ;
V_35 = F_19 ( V_4 , V_1 , F_1 ,
V_46 , & V_47 ) ;
if ( V_35 )
goto V_45;
return 0 ;
V_45:
F_20 ( V_32 ) ;
return V_35 ;
}
static int F_21 ( struct V_30 * V_31 )
{
struct V_3 * V_4 = F_22 ( V_31 ) ;
struct V_5 * V_6 = V_4 -> V_7 ;
F_23 ( V_4 ) ;
F_20 ( V_6 -> V_8 ) ;
return 0 ;
}
