static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
int V_5 ;
V_5 = F_2 ( V_2 , & V_4 -> V_6 , NULL , 0 ) ;
if ( V_5 < 0 )
return V_5 ;
V_5 = F_3 ( V_2 , & V_4 -> V_6 ) ;
if ( V_5 < 0 )
return V_5 ;
return 0 ;
}
static int F_4 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
int V_5 ;
V_4 = F_5 ( sizeof( * V_4 ) , V_7 ) ;
if ( ! V_4 )
return - V_8 ;
F_6 ( V_4 ) ;
V_2 -> V_4 = V_4 ;
V_4 -> V_9 = 1 ;
V_2 -> V_10 -> V_11 = 1 ;
V_5 = F_1 ( V_2 ) ;
if ( V_5 < 0 )
goto error;
V_2 -> V_12 = V_13 ;
return 0 ;
error:
F_7 ( V_2 ) ;
return V_5 ;
}
static int T_1 F_8 ( void )
{
return F_9 ( & V_14 ) ;
}
static void T_2 F_10 ( void )
{
F_11 ( & V_14 ) ;
}
