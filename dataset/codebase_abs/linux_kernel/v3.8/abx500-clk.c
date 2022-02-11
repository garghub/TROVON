static int F_1 ( struct V_1 * V_2 )
{
return 0 ;
}
static int F_2 ( struct V_1 * V_2 )
{
return 0 ;
}
static int F_3 ( struct V_1 * V_2 )
{
return 0 ;
}
static int F_4 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_5 ( V_4 -> V_2 . V_6 ) ;
int V_7 ;
if ( F_6 ( V_6 ) || F_7 ( V_6 ) ) {
V_7 = F_1 ( & V_4 -> V_2 ) ;
} else if ( F_8 ( V_6 ) ) {
V_7 = F_2 ( & V_4 -> V_2 ) ;
} else if ( F_9 ( V_6 ) ) {
V_7 = F_3 ( & V_4 -> V_2 ) ;
} else {
F_10 ( & V_4 -> V_2 , L_1 ) ;
return - V_8 ;
}
return V_7 ;
}
static int T_1 F_11 ( void )
{
return F_12 ( & V_9 ) ;
}
