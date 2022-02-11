static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
unsigned int V_5 = F_2 ( V_4 ) ;
if ( V_5 & V_6 )
return - V_7 ;
return F_3 ( V_4 ) ;
}
static int F_4 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
if ( F_5 ( V_4 ) < 0 )
return - V_7 ;
return 0 ;
}
static int T_1 F_6 ( struct V_8 * V_2 )
{
struct V_9 * V_10 ;
V_10 = F_7 ( L_1 , & V_2 -> V_2 , & V_11 ,
V_12 ) ;
if ( F_8 ( V_10 ) )
return F_9 ( V_10 ) ;
F_10 ( V_2 , V_10 ) ;
return 0 ;
}
static int T_2 F_11 ( struct V_8 * V_2 )
{
struct V_9 * V_10 = F_12 ( V_2 ) ;
F_13 ( V_10 ) ;
return 0 ;
}
static int T_1 F_14 ( void )
{
return F_15 ( & V_13 , F_6 ) ;
}
static void T_2 F_16 ( void )
{
F_17 ( & V_13 ) ;
}
