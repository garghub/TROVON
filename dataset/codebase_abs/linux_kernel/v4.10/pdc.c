static int T_1 F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 , * V_5 ;
V_4 = F_2 ( & V_2 -> V_6 , L_1 ) ;
if ( F_3 ( V_4 ) ) {
F_4 ( & V_2 -> V_6 , L_2 ) ;
return F_5 ( V_4 ) ;
}
V_5 = F_2 ( & V_2 -> V_6 , L_3 ) ;
if ( F_3 ( V_5 ) ) {
F_4 ( & V_2 -> V_6 , L_4 ) ;
F_6 ( V_4 ) ;
return F_5 ( V_5 ) ;
}
F_7 ( V_4 ) ;
F_7 ( V_5 ) ;
F_8 ( & V_2 -> V_6 , L_5 ) ;
return 0 ;
}
static int T_1 F_9 ( void )
{
return F_10 ( & V_7 , F_1 ) ;
}
