static void F_1 ( struct V_1 * V_2 ,
enum V_3 V_4 )
{
V_5 . V_6 ( V_7 , V_4 ? 1 : 0 ) ;
}
static int F_2 ( struct V_8 * V_9 )
{
return F_3 ( & V_9 -> V_10 , & V_11 ) ;
}
static int F_4 ( struct V_8 * V_9 )
{
F_5 ( & V_11 ) ;
return 0 ;
}
static int T_1 F_6 ( void )
{
int V_12 ;
if ( ! V_5 . V_10 ) {
V_12 = - V_13 ;
goto V_14;
}
V_12 = F_7 ( & V_15 ) ;
if ( V_12 < 0 )
goto V_14;
V_9 = F_8 ( V_16 , - 1 , NULL , 0 ) ;
if ( F_9 ( V_9 ) ) {
V_12 = F_10 ( V_9 ) ;
F_11 ( & V_15 ) ;
goto V_14;
}
V_14:
return V_12 ;
}
static void T_2 F_12 ( void )
{
F_13 ( V_9 ) ;
F_11 ( & V_15 ) ;
}
