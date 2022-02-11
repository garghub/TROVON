int F_1 ( struct V_1 * V_2 )
{
return F_2 ( & V_3 , V_2 ) ;
}
void F_3 ( struct V_1 * V_2 )
{
F_4 ( & V_3 , V_2 ) ;
}
static void F_5 ( struct V_4 * V_5 , T_1 V_6 )
{
F_6 ( & V_3 , 0 , NULL ) ;
}
static int T_2 F_7 ( struct V_4 * V_5 )
{
if ( V_7 )
return - V_8 ;
V_7 = V_5 -> V_9 ;
return 0 ;
}
static int T_3 F_8 ( struct V_4 * V_5 , int type )
{
V_7 = NULL ;
return 0 ;
}
static int T_4 F_9 ( void )
{
if ( V_10 )
return - V_11 ;
if ( F_10 ( & V_12 ) < 0 )
return - V_11 ;
return 0 ;
}
static void T_5 F_11 ( void )
{
F_12 ( & V_12 ) ;
}
