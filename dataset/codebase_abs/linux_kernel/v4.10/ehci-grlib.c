static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 . V_6 ;
struct V_7 * V_8 ;
struct V_9 * V_10 = NULL ;
struct V_11 V_12 ;
T_1 V_13 ;
int V_14 ;
int V_15 ;
if ( F_2 () )
return - V_16 ;
F_3 ( & V_2 -> V_5 , L_1 ) ;
V_15 = F_4 ( V_4 , 0 , & V_12 ) ;
if ( V_15 )
return V_15 ;
V_2 -> V_5 . V_17 = & V_2 -> V_5 . V_18 ;
V_8 = F_5 ( & V_19 , & V_2 -> V_5 ,
L_2 ) ;
if ( ! V_8 )
return - V_20 ;
V_8 -> V_21 = V_12 . V_22 ;
V_8 -> V_23 = F_6 ( & V_12 ) ;
V_14 = F_7 ( V_4 , 0 ) ;
if ( V_14 == V_24 ) {
F_8 ( & V_2 -> V_5 , L_3 ,
__FILE__ ) ;
V_15 = - V_25 ;
goto V_26;
}
V_8 -> V_27 = F_9 ( & V_2 -> V_5 , & V_12 ) ;
if ( F_10 ( V_8 -> V_27 ) ) {
V_15 = F_11 ( V_8 -> V_27 ) ;
goto V_28;
}
V_10 = F_12 ( V_8 ) ;
V_10 -> V_29 = V_8 -> V_27 ;
V_13 = F_13 ( V_10 , & V_10 -> V_29 -> V_13 ) ;
if ( F_14 ( V_10 , V_13 ) != V_30 ) {
V_10 -> V_31 = 1 ;
V_10 -> V_32 = 1 ;
V_10 -> V_33 = 1 ;
}
V_15 = F_15 ( V_8 , V_14 , 0 ) ;
if ( V_15 )
goto V_28;
F_16 ( V_8 -> V_34 . V_35 ) ;
return 0 ;
V_28:
F_17 ( V_14 ) ;
V_26:
F_18 ( V_8 ) ;
return V_15 ;
}
static int F_19 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_20 ( V_2 ) ;
F_3 ( & V_2 -> V_5 , L_4 ) ;
F_21 ( V_8 ) ;
F_17 ( V_8 -> V_14 ) ;
F_18 ( V_8 ) ;
return 0 ;
}
