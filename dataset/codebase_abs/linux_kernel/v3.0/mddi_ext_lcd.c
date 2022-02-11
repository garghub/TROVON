static int F_1 ( struct V_1 * V_2 )
{
return 0 ;
}
static int F_2 ( struct V_1 * V_2 )
{
return 0 ;
}
static int T_1 F_3 ( struct V_1 * V_2 )
{
F_4 ( V_2 ) ;
return 0 ;
}
static int T_1 F_5 ( void )
{
int V_3 ;
struct V_4 * V_5 ;
V_3 = F_6 ( & V_6 ) ;
if ( ! V_3 ) {
V_5 = & V_7 . V_8 ;
V_5 -> V_9 . V_10 = FALSE ;
V_5 -> V_11 . V_12 = V_13 ;
V_3 = F_7 ( & V_14 ) ;
if ( V_3 )
F_8 ( & V_6 ) ;
}
return V_3 ;
}
