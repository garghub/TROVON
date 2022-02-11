static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( & V_2 -> V_5 ) ;
struct V_6 * V_7 ;
struct V_8 * V_9 ;
struct V_10 * V_11 ;
const char * * V_12 ;
int V_13 = 0 ;
if ( ! V_4 ) {
F_3 ( & V_2 -> V_5 , L_1 ) ;
return - V_14 ;
}
if ( V_4 -> V_15 . V_16 < 1 ) {
F_3 ( & V_2 -> V_5 , L_2 ) ;
return - V_14 ;
}
V_7 = F_4 ( & V_2 -> V_5 , sizeof( struct V_6 ) ,
V_17 ) ;
if ( ! V_7 )
return - V_18 ;
V_11 = F_5 ( V_2 , V_19 , 0 ) ;
V_7 -> V_20 = F_6 ( & V_2 -> V_5 , V_11 ) ;
if ( F_7 ( V_7 -> V_20 ) )
return F_8 ( V_7 -> V_20 ) ;
F_9 ( & V_7 -> V_15 , V_2 -> V_5 . V_21 ) ;
V_9 = F_10 ( & V_7 -> V_15 ) ;
V_9 -> V_5 . V_22 = & V_2 -> V_5 ;
V_7 -> V_15 . V_23 = V_7 -> V_20 ;
V_7 -> V_15 . V_24 = V_7 -> V_20 ;
V_7 -> V_15 . V_25 = V_4 -> V_26 . V_25 ;
V_7 -> V_15 . V_27 = V_4 -> V_26 . V_27 ;
V_7 -> V_15 . V_28 = V_4 -> V_26 . V_28 ;
V_7 -> V_15 . V_29 = V_4 -> V_26 . V_29 ;
V_7 -> V_15 . V_30 = V_4 -> V_26 . V_30 ;
V_7 -> V_15 . V_31 = V_4 -> V_26 . V_31 ;
V_7 -> V_15 . V_32 = V_4 -> V_15 . V_32 ;
V_7 -> V_15 . V_33 |= V_4 -> V_15 . V_33 ;
V_7 -> V_15 . V_34 |= V_4 -> V_15 . V_34 ;
V_7 -> V_15 . V_35 . V_36 = V_4 -> V_26 . V_37 ;
V_7 -> V_15 . V_35 . V_38 = V_39 ;
V_7 -> V_15 . V_35 . V_40 = V_41 ;
F_11 ( V_2 , V_7 ) ;
if ( V_4 -> V_26 . V_42 ) {
V_13 = V_4 -> V_26 . V_42 ( V_2 ) ;
if ( V_13 )
goto V_43;
}
if ( F_12 ( V_9 , V_4 -> V_15 . V_16 ) ) {
V_13 = - V_44 ;
goto V_43;
}
V_12 = V_4 -> V_15 . V_45 ;
V_13 = F_13 ( V_9 , V_12 , NULL ,
V_4 -> V_15 . V_46 ,
V_4 -> V_15 . V_47 ) ;
if ( ! V_13 )
return V_13 ;
F_14 ( V_9 ) ;
V_43:
if ( V_4 -> V_26 . remove )
V_4 -> V_26 . remove ( V_2 ) ;
return V_13 ;
}
static int F_15 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_16 ( V_2 ) ;
struct V_3 * V_4 = F_2 ( & V_2 -> V_5 ) ;
F_14 ( F_10 ( & V_7 -> V_15 ) ) ;
if ( V_4 -> V_26 . remove )
V_4 -> V_26 . remove ( V_2 ) ;
return 0 ;
}
