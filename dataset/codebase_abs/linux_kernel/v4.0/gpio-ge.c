static int T_1 F_1 ( struct V_1 * V_2 )
{
const struct V_3 * V_4 =
F_2 ( V_5 , & V_2 -> V_6 ) ;
struct V_7 * V_8 ;
void T_2 * V_9 ;
int V_10 ;
V_8 = F_3 ( & V_2 -> V_6 , sizeof( * V_8 ) , V_11 ) ;
if ( ! V_8 )
return - V_12 ;
V_9 = F_4 ( V_2 -> V_6 . V_13 , 0 ) ;
if ( ! V_9 )
return - V_12 ;
V_10 = F_5 ( V_8 , & V_2 -> V_6 , 4 , V_9 + V_14 ,
V_9 + V_15 , NULL , NULL ,
V_9 + V_16 , V_17 ) ;
if ( V_10 ) {
F_6 ( & V_2 -> V_6 , L_1 ) ;
goto V_18;
}
V_8 -> V_19 . V_20 = F_7 ( & V_2 -> V_6 , V_2 -> V_6 . V_13 -> V_21 ,
V_11 ) ;
if ( ! V_8 -> V_19 . V_20 ) {
V_10 = - V_12 ;
goto V_18;
}
V_8 -> V_19 . V_22 = - 1 ;
V_8 -> V_19 . V_23 = ( V_24 ) ( V_25 ) V_4 -> V_26 ;
V_8 -> V_19 . V_27 = 2 ;
V_8 -> V_19 . V_13 = V_2 -> V_6 . V_13 ;
V_10 = F_8 ( & V_8 -> V_19 ) ;
if ( V_10 )
goto V_18;
return 0 ;
V_18:
F_9 ( V_9 ) ;
F_10 ( L_2 ,
V_2 -> V_6 . V_13 -> V_21 ) ;
return V_10 ;
}
