static int T_1 F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_5 ;
V_5 = F_3 ( V_4 ) ;
if ( V_5 < 0 )
return V_5 ;
V_5 = F_4 ( V_4 ) ;
if ( V_5 < 0 )
goto V_6;
return 0 ;
V_6:
F_5 ( V_2 ) ;
return V_5 ;
}
static int F_6 ( struct V_7 * V_8 )
{
struct V_1 * V_2 ;
struct V_9 * V_10 ;
int V_11 ;
int V_5 ;
if ( F_7 () )
return - V_12 ;
V_10 = F_8 ( V_8 , V_13 , 0 ) ;
if ( ! V_10 ) {
F_9 ( & V_8 -> V_14 , L_1 ) ;
return - V_12 ;
}
V_11 = V_10 -> V_15 ;
V_2 = F_10 ( & V_16 , & V_8 -> V_14 ,
F_11 ( & V_8 -> V_14 ) ) ;
if ( ! V_2 )
return - V_17 ;
V_10 = F_8 ( V_8 , V_18 , 0 ) ;
if ( ! V_10 ) {
F_9 ( & V_8 -> V_14 , L_2 ) ;
V_5 = - V_12 ;
goto V_19;
}
V_2 -> V_20 = V_10 -> V_15 ;
V_2 -> V_21 = F_12 ( V_10 ) ;
if ( ! F_13 ( V_2 -> V_20 , V_2 -> V_21 , V_22 ) ) {
F_9 ( & V_8 -> V_14 , L_3 ) ;
V_5 = - V_23 ;
goto V_19;
}
V_2 -> V_24 = F_14 ( V_2 -> V_20 , V_2 -> V_21 ) ;
if ( ! V_2 -> V_24 ) {
F_9 ( & V_8 -> V_14 , L_4 ) ;
V_5 = - V_25 ;
goto V_26;
}
F_15 ( F_2 ( V_2 ) ) ;
V_5 = F_16 ( V_2 , V_11 , V_27 ) ;
if ( V_5 )
goto V_28;
return 0 ;
V_28:
F_17 ( V_2 -> V_24 ) ;
V_26:
F_18 ( V_2 -> V_20 , V_2 -> V_21 ) ;
V_19:
F_19 ( V_2 ) ;
return V_5 ;
}
static int F_20 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = F_21 ( V_8 ) ;
F_22 ( V_2 ) ;
F_17 ( V_2 -> V_24 ) ;
F_18 ( V_2 -> V_20 , V_2 -> V_21 ) ;
F_19 ( V_2 ) ;
return 0 ;
}
