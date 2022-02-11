static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
const struct V_5 * V_6 ;
struct V_1 * V_7 ;
int V_8 ;
V_6 = F_2 ( V_9 , & V_2 -> V_4 ) ;
if ( ! V_6 )
return - V_10 ;
V_8 = F_3 ( V_4 , L_1 , L_2 , 19200000 ) ;
if ( V_8 )
return V_8 ;
V_8 = F_3 ( V_4 , L_3 , L_4 , 27000000 ) ;
if ( V_8 )
return V_8 ;
V_8 = F_4 ( V_2 , V_6 -> V_11 ) ;
if ( V_8 )
return V_8 ;
V_7 = F_5 ( & V_2 -> V_4 , L_5 , - 1 ,
NULL , 0 ) ;
if ( F_6 ( V_7 ) )
return F_7 ( V_7 ) ;
F_8 ( V_2 , V_7 ) ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 )
{
struct V_1 * V_7 = F_10 ( V_2 ) ;
F_11 ( V_7 ) ;
return 0 ;
}
static int T_1 F_12 ( void )
{
return F_13 ( & V_12 ) ;
}
static void T_2 F_14 ( void )
{
F_15 ( & V_12 ) ;
}
