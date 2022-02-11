static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 , * V_7 ;
struct V_8 * V_9 ;
void T_1 * V_10 ;
const struct V_11 * V_12 ;
int V_13 ;
V_12 = F_2 ( & V_2 -> V_14 ) ;
if ( ! V_12 )
return - V_15 ;
V_4 = F_3 ( V_2 , V_16 , 0 ) ;
V_10 = F_4 ( & V_2 -> V_14 , V_4 ) ;
if ( F_5 ( V_10 ) )
return F_6 ( V_10 ) ;
V_6 = F_7 ( & V_2 -> V_14 , L_1 ) ;
if ( F_5 ( V_6 ) ) {
V_13 = F_6 ( V_6 ) ;
if ( V_13 != - V_17 )
F_8 ( & V_2 -> V_14 , L_2 , V_13 ) ;
return V_13 ;
}
V_7 = F_7 ( & V_2 -> V_14 , L_3 ) ;
if ( F_5 ( V_7 ) ) {
V_13 = F_6 ( V_7 ) ;
if ( V_13 != - V_17 )
F_8 ( & V_2 -> V_14 , L_4 , V_13 ) ;
return V_13 ;
}
V_9 = F_9 ( & V_2 -> V_14 , NULL ) ;
if ( F_5 ( V_9 ) ) {
V_13 = F_6 ( V_9 ) ;
if ( V_13 != - V_17 )
F_8 ( & V_2 -> V_14 ,
L_5 , V_13 ) ;
return V_13 ;
}
V_13 = F_10 ( V_6 ) ;
if ( V_13 ) {
F_8 ( & V_2 -> V_14 , L_6 , V_13 ) ;
return V_13 ;
}
V_13 = F_10 ( V_7 ) ;
if ( V_13 ) {
F_8 ( & V_2 -> V_14 , L_7 , V_13 ) ;
goto V_18;
}
V_13 = F_11 ( V_9 ) ;
if ( V_13 ) {
F_8 ( & V_2 -> V_14 ,
L_8 , V_13 ) ;
goto V_19;
}
V_13 = F_12 ( V_2 -> V_14 . V_20 , V_10 , V_12 ) ;
if ( V_13 )
goto V_21;
return 0 ;
V_21:
F_13 ( V_9 ) ;
V_19:
F_14 ( V_7 ) ;
V_18:
F_14 ( V_6 ) ;
return V_13 ;
}
