static int F_1 ( struct V_1 * V_2 )
{
const struct V_3 * V_4 ;
struct V_5 * V_5 ;
V_4 = F_2 ( & V_2 -> V_6 ) ;
if ( V_4 -> V_7 ) {
V_5 = F_3 ( & V_2 -> V_6 , L_1 ) ;
if ( F_4 ( V_5 ) )
return F_5 ( V_5 ) ;
F_6 ( V_5 ) ;
}
if ( V_4 -> V_8 ) {
V_5 = F_3 ( & V_2 -> V_6 , L_2 ) ;
if ( F_4 ( V_5 ) ) {
F_7 ( L_3 ) ;
return F_5 ( V_5 ) ;
}
F_6 ( V_5 ) ;
}
return 0 ;
}
static int T_1 F_8 ( void )
{
return F_9 ( & V_9 ) ;
}
