static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
struct V_5 * V_6 ;
struct V_7 * V_8 ;
struct V_9 * V_10 ;
struct V_11 * V_11 ;
void T_1 * V_12 ;
V_6 = F_2 ( V_2 , V_13 , 0 ) ;
V_12 = F_3 ( V_4 , V_6 ) ;
if ( F_4 ( V_12 ) )
return F_5 ( V_12 ) ;
V_10 = F_6 ( V_4 , sizeof( * V_10 ) , V_14 ) ;
if ( ! V_10 )
return - V_15 ;
V_16 . V_17 = F_7 ( V_6 ) - 1 ;
V_11 = F_8 ( V_4 , V_12 , & V_16 ) ;
if ( F_4 ( V_11 ) ) {
F_9 ( V_4 , L_1 ) ;
return F_5 ( V_11 ) ;
}
V_10 -> V_4 = V_4 ;
V_10 -> V_18 = V_19 ;
V_8 = F_10 ( V_10 ) ;
if ( F_4 ( V_8 ) )
return F_5 ( V_8 ) ;
F_11 ( V_2 , V_8 ) ;
return 0 ;
}
static int F_12 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_13 ( V_2 ) ;
return F_14 ( V_8 ) ;
}
static int T_2 F_15 ( void )
{
int V_20 ;
V_20 = F_16 ( & V_21 ) ;
if ( V_20 ) {
F_17 ( L_2 ) ;
return V_20 ;
}
return 0 ;
}
static void T_3 F_18 ( void )
{
return F_19 ( & V_21 ) ;
}
