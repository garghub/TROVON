static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 , * V_5 = V_2 -> V_6 . V_7 ;
struct V_8 * V_9 ;
int V_10 = 0 ;
V_4 = F_2 ( V_5 , L_1 , 0 ) ;
if ( ! V_4 ) {
F_3 ( & V_2 -> V_6 , L_2 ) ;
V_10 = - V_11 ;
goto V_12;
}
V_9 = F_4 ( & V_2 -> V_6 , sizeof( * V_9 ) , V_13 ) ;
if ( ! V_9 ) {
V_10 = - V_14 ;
goto V_12;
}
V_9 -> V_15 . V_16 = L_3 ;
V_9 -> V_15 . V_17 = L_3 ;
V_9 -> V_15 . V_18 = L_4 ;
V_9 -> V_15 . V_19 = L_5 ;
V_9 -> V_15 . V_20 = V_4 ;
V_9 -> V_15 . V_21 = V_4 ;
V_9 -> V_15 . V_22 = true ;
V_9 -> V_15 . V_23 = true ;
if ( F_5 ( V_5 , L_6 ) )
V_9 -> V_15 . V_23 = false ;
if ( F_5 ( V_5 , L_7 ) )
V_9 -> V_15 . V_22 = false ;
if ( V_9 -> V_15 . V_22 && V_9 -> V_15 . V_23 ) {
F_3 ( & V_2 -> V_6 , L_8 ) ;
goto V_12;
}
V_9 -> V_24 . V_6 = & V_2 -> V_6 ;
V_9 -> V_24 . V_25 = & V_9 -> V_15 ;
V_9 -> V_24 . V_26 = 1 ;
V_9 -> V_24 . V_27 = V_28 ;
V_10 = F_6 ( & V_9 -> V_24 , L_9 ) ;
if ( V_10 )
goto V_12;
V_10 = F_7 ( & V_2 -> V_6 , & V_9 -> V_24 ) ;
if ( V_10 ) {
F_3 ( & V_2 -> V_6 , L_10 , V_10 ) ;
goto V_12;
}
V_12:
F_8 ( V_4 ) ;
return V_10 ;
}
