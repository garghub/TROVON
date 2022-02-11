static int F_1 ( struct V_1 * V_2 )
{
const struct V_3 * V_4 ;
const struct V_5 * V_6 ;
struct V_7 * V_7 ;
V_4 = F_2 ( V_8 , & V_2 -> V_9 ) ;
V_6 = V_4 -> V_10 ;
if ( V_6 -> V_11 ) {
V_7 = F_3 ( & V_2 -> V_9 , L_1 ) ;
if ( F_4 ( V_7 ) )
return F_5 ( V_7 ) ;
F_6 ( V_7 ) ;
}
if ( V_6 -> V_12 ) {
V_7 = F_3 ( & V_2 -> V_9 , L_2 ) ;
if ( F_4 ( V_7 ) ) {
F_7 ( L_3 ) ;
return F_5 ( V_7 ) ;
}
F_6 ( V_7 ) ;
}
return 0 ;
}
static int T_1 F_8 ( void )
{
return F_9 ( & V_13 ) ;
}
