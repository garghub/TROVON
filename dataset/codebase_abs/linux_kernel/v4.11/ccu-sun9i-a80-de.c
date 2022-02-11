static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 ;
struct V_7 * V_8 ;
void T_1 * V_9 ;
int V_10 ;
V_4 = F_2 ( V_2 , V_11 , 0 ) ;
V_9 = F_3 ( & V_2 -> V_12 , V_4 ) ;
if ( F_4 ( V_9 ) )
return F_5 ( V_9 ) ;
V_6 = F_6 ( & V_2 -> V_12 , L_1 ) ;
if ( F_4 ( V_6 ) ) {
V_10 = F_5 ( V_6 ) ;
if ( V_10 != - V_13 )
F_7 ( & V_2 -> V_12 , L_2 , V_10 ) ;
return V_10 ;
}
V_8 = F_8 ( & V_2 -> V_12 , NULL ) ;
if ( F_4 ( V_8 ) ) {
V_10 = F_5 ( V_8 ) ;
if ( V_10 != - V_13 )
F_7 ( & V_2 -> V_12 ,
L_3 , V_10 ) ;
return V_10 ;
}
V_10 = F_9 ( V_6 ) ;
if ( V_10 ) {
F_7 ( & V_2 -> V_12 , L_4 , V_10 ) ;
return V_10 ;
}
V_10 = F_10 ( V_8 ) ;
if ( V_10 ) {
F_7 ( & V_2 -> V_12 ,
L_5 , V_10 ) ;
goto V_14;
}
V_10 = F_11 ( V_2 -> V_12 . V_15 , V_9 ,
& V_16 ) ;
if ( V_10 )
goto V_17;
return 0 ;
V_17:
F_12 ( V_8 ) ;
V_14:
F_13 ( V_6 ) ;
return V_10 ;
}
