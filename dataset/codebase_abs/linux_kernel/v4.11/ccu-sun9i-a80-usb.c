static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 ;
void T_1 * V_7 ;
int V_8 ;
V_4 = F_2 ( V_2 , V_9 , 0 ) ;
V_7 = F_3 ( & V_2 -> V_10 , V_4 ) ;
if ( F_4 ( V_7 ) )
return F_5 ( V_7 ) ;
V_6 = F_6 ( & V_2 -> V_10 , L_1 ) ;
if ( F_4 ( V_6 ) ) {
V_8 = F_5 ( V_6 ) ;
if ( V_8 != - V_11 )
F_7 ( & V_2 -> V_10 , L_2 , V_8 ) ;
return V_8 ;
}
V_8 = F_8 ( V_6 ) ;
if ( V_8 ) {
F_7 ( & V_2 -> V_10 , L_3 , V_8 ) ;
return V_8 ;
}
V_8 = F_9 ( V_2 -> V_10 . V_12 , V_7 ,
& V_13 ) ;
if ( V_8 )
goto V_14;
return 0 ;
V_14:
F_10 ( V_6 ) ;
return V_8 ;
}
