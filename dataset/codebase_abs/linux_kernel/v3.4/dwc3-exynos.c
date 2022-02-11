static int T_1 F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 . V_6 ;
struct V_1 * V_7 ;
struct V_8 * V_9 ;
struct V_10 * V_10 ;
int V_11 ;
int V_12 = - V_13 ;
V_9 = F_2 ( sizeof( * V_9 ) , V_14 ) ;
if ( ! V_9 ) {
F_3 ( & V_2 -> V_5 , L_1 ) ;
goto V_15;
}
F_4 ( V_2 , V_9 ) ;
V_11 = F_5 () ;
if ( V_11 < 0 )
goto V_16;
V_7 = F_6 ( L_2 , V_11 ) ;
if ( ! V_7 ) {
F_3 ( & V_2 -> V_5 , L_3 ) ;
goto V_17;
}
V_10 = F_7 ( & V_2 -> V_5 , L_4 ) ;
if ( F_8 ( V_10 ) ) {
F_3 ( & V_2 -> V_5 , L_5 ) ;
V_12 = - V_18 ;
goto V_19;
}
F_9 ( & V_7 -> V_5 , V_2 -> V_5 . V_20 ) ;
V_7 -> V_5 . V_21 = & V_2 -> V_5 ;
V_7 -> V_5 . V_22 = V_2 -> V_5 . V_22 ;
V_7 -> V_5 . V_23 = V_2 -> V_5 . V_23 ;
V_9 -> V_7 = V_7 ;
V_9 -> V_5 = & V_2 -> V_5 ;
V_9 -> V_10 = V_10 ;
F_10 ( V_9 -> V_10 ) ;
if ( ! V_4 ) {
F_11 ( & V_2 -> V_5 , L_6 ) ;
} else {
if ( V_4 -> V_24 )
V_4 -> V_24 ( V_2 , V_4 -> V_25 ) ;
}
V_12 = F_12 ( V_7 , V_2 -> V_26 ,
V_2 -> V_27 ) ;
if ( V_12 ) {
F_3 ( & V_2 -> V_5 , L_7 ) ;
goto V_28;
}
V_12 = F_13 ( V_7 ) ;
if ( V_12 ) {
F_3 ( & V_2 -> V_5 , L_8 ) ;
goto V_28;
}
return 0 ;
V_28:
if ( V_4 && V_4 -> V_29 )
V_4 -> V_29 ( V_2 , V_4 -> V_25 ) ;
F_14 ( V_10 ) ;
F_15 ( V_10 ) ;
V_19:
F_16 ( V_7 ) ;
V_17:
F_17 ( V_11 ) ;
V_16:
F_18 ( V_9 ) ;
V_15:
return V_12 ;
}
static int T_2 F_19 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = F_20 ( V_2 ) ;
struct V_3 * V_4 = V_2 -> V_5 . V_6 ;
F_21 ( V_9 -> V_7 ) ;
F_17 ( V_9 -> V_7 -> V_30 ) ;
if ( V_4 && V_4 -> V_29 )
V_4 -> V_29 ( V_2 , V_4 -> V_25 ) ;
F_14 ( V_9 -> V_10 ) ;
F_15 ( V_9 -> V_10 ) ;
F_18 ( V_9 ) ;
return 0 ;
}
