static int F_1 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
struct V_5 * V_5 ;
int V_6 ;
V_5 = F_2 ( & V_2 -> V_7 , sizeof( * V_5 ) , V_8 ) ;
if ( ! V_5 )
return - V_9 ;
F_3 ( V_2 , V_5 ) ;
V_5 -> V_7 = & V_2 -> V_7 ;
V_5 -> V_2 = V_2 ;
V_5 -> V_10 = F_4 ( V_2 ,
& V_11 ) ;
if ( F_5 ( V_5 -> V_10 ) ) {
V_6 = F_6 ( V_5 -> V_10 ) ;
F_7 ( & V_2 -> V_7 , L_1 , V_6 ) ;
return V_6 ;
}
V_5 -> V_12 = F_8 ( V_2 -> V_13 ,
V_2 -> V_14 | F_9 ( 2 ) ) ;
if ( ! V_5 -> V_12 ) {
F_7 ( & V_2 -> V_7 , L_2 ) ;
return - V_15 ;
}
F_3 ( V_5 -> V_12 , V_5 ) ;
V_5 -> V_16 = F_4 ( V_5 -> V_12 ,
& V_17 ) ;
if ( F_5 ( V_5 -> V_16 ) ) {
V_6 = F_6 ( V_5 -> V_16 ) ;
F_7 ( & V_5 -> V_12 -> V_7 ,
L_3 , V_6 ) ;
goto V_18;
}
V_6 = F_10 ( & V_2 -> V_7 , - 1 , V_19 ,
F_11 ( V_19 ) , NULL , 0 , NULL ) ;
if ( V_6 < 0 ) {
F_7 ( & V_2 -> V_7 , L_4 , V_6 ) ;
goto V_18;
}
return 0 ;
V_18:
F_12 ( V_5 -> V_12 ) ;
return V_6 ;
}
