static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 . V_6 ;
struct V_7 * V_5 = & V_2 -> V_5 ;
if ( ! V_4 ) {
F_2 ( V_5 , L_1 ) ;
return - V_8 ;
}
F_3 ( V_5 ) ;
F_4 ( V_5 ) ;
F_5 ( V_5 , L_2 ) ;
return 0 ;
}
static int T_1 F_6 ( struct V_1 * V_2 )
{
struct V_7 * V_5 = & V_2 -> V_5 ;
F_7 ( V_5 ) ;
return 0 ;
}
static int F_8 ( struct V_7 * V_5 )
{
struct V_3 * V_4 = V_5 -> V_6 ;
int V_9 = 0 ;
if ( V_4 -> V_10 )
V_9 = V_4 -> V_10 ( V_5 ) ;
F_9 ( V_5 , L_3 ) ;
return V_9 ;
}
static int F_10 ( struct V_7 * V_5 )
{
struct V_3 * V_4 = V_5 -> V_6 ;
int V_9 = 0 ;
if ( V_4 -> V_11 )
V_9 = V_4 -> V_11 ( V_5 ) ;
F_9 ( V_5 , L_4 ) ;
return V_9 ;
}
static int T_2 F_11 ( void )
{
int V_9 ;
V_9 = F_12 ( & V_12 ) ;
if ( V_9 )
F_13 ( V_13 L_5 , V_14 ) ;
return V_9 ;
}
