static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( & V_2 -> V_5 ) ;
struct V_6 V_7 ;
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
V_9 = F_4 ( & V_2 -> V_5 , sizeof( struct V_8 ) ,
V_17 ) ;
if ( ! V_9 )
return - V_18 ;
V_11 = F_5 ( V_2 , V_19 , 0 ) ;
V_9 -> V_20 = F_6 ( & V_2 -> V_5 , V_11 ) ;
if ( F_7 ( V_9 -> V_20 ) )
return F_8 ( V_9 -> V_20 ) ;
V_9 -> V_15 . V_21 = & V_9 ;
V_9 -> V_22 . V_21 = & V_9 -> V_15 ;
V_9 -> V_22 . V_5 . V_23 = & V_2 -> V_5 ;
V_9 -> V_15 . V_24 = V_9 -> V_20 ;
V_9 -> V_15 . V_25 = V_9 -> V_20 ;
V_9 -> V_15 . V_26 = V_4 -> V_27 . V_26 ;
V_9 -> V_15 . V_28 = V_4 -> V_27 . V_28 ;
V_9 -> V_15 . V_29 = V_4 -> V_27 . V_29 ;
V_9 -> V_15 . V_30 = V_4 -> V_27 . V_30 ;
V_9 -> V_15 . V_31 = V_4 -> V_27 . V_31 ;
V_9 -> V_15 . V_32 = V_4 -> V_27 . V_32 ;
V_9 -> V_15 . V_33 = V_4 -> V_15 . V_33 ;
V_9 -> V_15 . V_34 |= V_4 -> V_15 . V_34 ;
V_9 -> V_15 . V_35 |= V_4 -> V_15 . V_35 ;
V_9 -> V_15 . V_36 . V_37 = V_4 -> V_27 . V_38 ;
V_9 -> V_15 . V_36 . V_39 = V_4 -> V_15 . V_40 ;
V_9 -> V_15 . V_36 . V_41 = V_42 ;
F_9 ( V_2 , V_9 ) ;
if ( V_4 -> V_27 . V_43 ) {
V_13 = V_4 -> V_27 . V_43 ( V_2 ) ;
if ( V_13 )
goto V_44;
}
if ( F_10 ( & V_9 -> V_22 , V_4 -> V_15 . V_16 ) ) {
V_13 = - V_45 ;
goto V_44;
}
V_12 = V_4 -> V_15 . V_46 ;
V_7 . V_47 = V_2 -> V_5 . V_47 ;
V_13 = F_11 ( & V_9 -> V_22 , V_12 , & V_7 ,
V_4 -> V_15 . V_48 ,
V_4 -> V_15 . V_49 ) ;
if ( ! V_13 )
return V_13 ;
F_12 ( & V_9 -> V_22 ) ;
V_44:
if ( V_4 -> V_27 . remove )
V_4 -> V_27 . remove ( V_2 ) ;
return V_13 ;
}
static int F_13 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = F_14 ( V_2 ) ;
struct V_3 * V_4 = F_2 ( & V_2 -> V_5 ) ;
F_12 ( & V_9 -> V_22 ) ;
if ( V_4 -> V_27 . remove )
V_4 -> V_27 . remove ( V_2 ) ;
return 0 ;
}
