static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_3 ;
struct V_4 * V_5 = & V_2 -> V_5 ;
const struct V_6 * V_7 ;
V_7 = F_2 ( V_8 , & V_2 -> V_5 ) ;
if ( ! V_7 )
return - V_9 ;
V_3 = F_3 ( V_5 , L_1 , NULL , V_10 , 19200000 ) ;
if ( F_4 ( V_3 ) )
return F_5 ( V_3 ) ;
V_3 = F_3 ( V_5 , L_2 , NULL , V_10 , 27000000 ) ;
if ( F_4 ( V_3 ) )
return F_5 ( V_3 ) ;
return F_6 ( V_2 , V_7 -> V_11 ) ;
}
static int F_7 ( struct V_1 * V_2 )
{
F_8 ( V_2 ) ;
return 0 ;
}
static int T_1 F_9 ( void )
{
return F_10 ( & V_12 ) ;
}
static void T_2 F_11 ( void )
{
F_12 ( & V_12 ) ;
}
