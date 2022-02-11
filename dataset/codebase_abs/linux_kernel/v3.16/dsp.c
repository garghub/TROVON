void T_1 F_1 ( void )
{
T_2 V_1 = V_2 ;
T_2 V_3 ;
if ( ! F_2 () )
return;
if ( ! V_1 )
return;
V_3 = F_3 ( V_1 , V_4 ) ;
if ( ! V_3 ) {
F_4 ( L_1 ,
V_5 , ( unsigned long long ) V_1 ) ;
return;
}
V_6 = V_3 ;
}
static T_2 F_5 ( void )
{
return V_6 ;
}
static int T_1 F_6 ( void )
{
struct V_7 * V_8 ;
int V_9 = - V_10 ;
struct V_11 * V_12 = & V_13 ;
if ( ! F_2 () )
return 0 ;
V_12 -> V_14 = F_5 () ;
if ( V_12 -> V_14 ) {
V_12 -> V_15 = V_2 ;
F_7 ( L_2 , V_5 ,
( unsigned long long ) V_12 -> V_15 ,
( unsigned long long ) V_12 -> V_14 ) ;
}
V_8 = F_8 ( L_3 , - 1 ) ;
if ( ! V_8 )
goto V_16;
V_9 = F_9 ( V_8 , V_12 , sizeof( * V_12 ) ) ;
if ( V_9 )
goto V_16;
V_9 = F_10 ( V_8 ) ;
if ( V_9 )
goto V_16;
V_17 = V_8 ;
return 0 ;
V_16:
F_11 ( V_8 ) ;
return V_9 ;
}
static void T_3 F_12 ( void )
{
if ( ! F_2 () )
return;
F_13 ( V_17 ) ;
}
