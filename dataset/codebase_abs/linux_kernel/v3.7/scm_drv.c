static void F_1 ( struct V_1 * V_2 )
{
F_2 ( L_1 ,
( unsigned long ) V_2 -> V_3 ) ;
F_3 ( 2 , L_2 ) ;
F_4 ( 2 , V_2 ) ;
}
static int F_5 ( struct V_1 * V_2 )
{
struct V_4 * V_5 ;
int V_6 ;
F_3 ( 2 , L_3 ) ;
F_4 ( 2 , V_2 ) ;
if ( V_2 -> V_7 . V_8 != V_9 )
return - V_10 ;
V_5 = F_6 ( sizeof( * V_5 ) , V_11 ) ;
if ( ! V_5 )
return - V_12 ;
F_7 ( & V_2 -> V_13 , V_5 ) ;
V_6 = F_8 ( V_5 , V_2 ) ;
if ( V_6 ) {
F_7 ( & V_2 -> V_13 , NULL ) ;
F_9 ( V_5 ) ;
goto V_14;
}
V_14:
return V_6 ;
}
static int F_10 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_11 ( & V_2 -> V_13 ) ;
F_12 ( V_5 ) ;
F_7 ( & V_2 -> V_13 , NULL ) ;
F_9 ( V_5 ) ;
return 0 ;
}
int T_1 F_13 ( void )
{
return F_14 ( & V_15 ) ;
}
void F_15 ( void )
{
F_16 ( & V_15 ) ;
}
