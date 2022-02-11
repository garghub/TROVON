static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 ;
struct V_7 * V_8 , * V_9 ;
int V_10 ;
V_4 = F_2 ( sizeof( struct V_3 ) , V_11 ) ;
if ( ! V_4 ) {
V_10 = - V_12 ;
goto V_13;
}
V_6 = & V_4 -> V_6 ;
V_8 = F_3 ( V_2 , V_14 , 0 ) ;
if ( ! V_8 ) {
F_4 ( & V_2 -> V_15 , L_1 ) ;
V_10 = - V_16 ;
goto V_17;
}
V_9 = F_5 ( V_8 -> V_18 , F_6 ( V_8 ) ,
V_2 -> V_19 ) ;
if ( ! V_9 ) {
F_4 ( & V_2 -> V_15 , L_2 ) ;
V_10 = - V_20 ;
goto V_17;
}
V_6 -> V_21 = F_7 ( V_8 -> V_18 , F_6 ( V_8 ) ) ;
if ( ! V_6 -> V_21 ) {
F_4 ( & V_2 -> V_15 , L_3 ) ;
V_10 = - V_12 ;
goto V_22;
}
V_6 -> V_23 = F_8 ( V_2 , 0 ) ;
if ( V_6 -> V_23 < 0 ) {
F_4 ( & V_2 -> V_15 , L_4 ) ;
V_10 = V_6 -> V_23 ;
goto V_24;
}
V_4 -> V_25 = F_9 ( & V_2 -> V_15 , NULL ) ;
if ( F_10 ( V_4 -> V_25 ) ) {
V_10 = F_11 ( V_4 -> V_25 ) ;
goto V_24;
}
F_12 ( V_4 -> V_25 ) ;
V_6 -> V_26 = & V_2 -> V_15 ;
V_6 -> V_27 = 0 ;
V_6 -> V_28 = 4 ;
V_6 -> V_29 = F_13 ( V_4 -> V_25 ) ;
V_10 = F_14 ( V_6 ) ;
if ( V_10 )
goto V_30;
F_15 ( V_2 , V_4 ) ;
return 0 ;
V_30:
F_16 ( V_4 -> V_25 ) ;
F_17 ( V_4 -> V_25 ) ;
V_4 -> V_25 = NULL ;
V_24:
F_18 ( V_6 -> V_21 ) ;
V_22:
F_19 ( V_8 -> V_18 , F_6 ( V_8 ) ) ;
V_17:
F_20 ( V_4 ) ;
V_13:
return V_10 ;
}
static int F_21 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_22 ( V_2 ) ;
struct V_7 * V_8 ;
F_16 ( V_4 -> V_25 ) ;
F_17 ( V_4 -> V_25 ) ;
V_4 -> V_25 = NULL ;
F_23 ( & V_4 -> V_6 ) ;
F_18 ( V_4 -> V_6 . V_21 ) ;
F_20 ( V_4 ) ;
V_8 = F_3 ( V_2 , V_14 , 0 ) ;
F_19 ( V_8 -> V_18 , F_6 ( V_8 ) ) ;
return 0 ;
}
