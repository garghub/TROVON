static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 . V_6 ;
void T_1 * V_7 ;
V_7 = F_2 ( V_4 , 0 ) ;
F_3 ( V_4 ) ;
if ( ! V_7 )
return - V_8 ;
return F_4 ( V_7 ) ;
}
static int F_5 ( struct V_1 * V_2 )
{
return F_6 () ;
}
static int T_2 F_7 ( void )
{
struct V_1 * V_2 ;
struct V_3 * V_6 ;
V_6 = F_8 ( L_1 ) ;
if ( ! V_6 )
return - V_9 ;
if ( ! F_9 ( V_10 , V_6 ) )
return - V_9 ;
V_2 = F_10 ( V_6 , L_2 , NULL ) ;
if ( ! V_2 )
return - V_9 ;
return F_11 ( & V_11 ) ;
}
