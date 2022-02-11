static T_1 F_1 ( int V_1 , void * V_2 )
{
if ( V_1 == 0 ) {
F_2 ( & ( (struct V_3 * ) V_2 ) -> V_4 , L_1 ) ;
return V_5 ;
}
return F_3 () ;
}
static int T_2 F_4 ( struct V_3 * V_2 ,
const struct V_6 * V_7 )
{
void T_3 * V_8 = NULL ;
int V_9 = 0 ;
if ( V_7 == NULL )
return - V_10 ;
V_9 = F_5 ( V_2 ) ;
if ( V_9 )
goto V_11;
if ( ! V_2 -> V_1 ) {
F_2 ( & V_2 -> V_4 , L_2 ) ;
V_9 = - V_12 ;
goto V_13;
}
V_9 = F_6 ( V_2 , V_14 ) ;
if ( V_9 )
goto V_13;
V_8 = F_7 ( V_2 , 0 , 0 ) ;
if ( ! V_8 ) {
F_2 ( & V_2 -> V_4 , L_3 ) ;
V_9 = - V_15 ;
goto V_16;
}
F_8 ( V_2 , ( V_17 void * ) V_8 ) ;
F_9 ( V_2 ) ;
F_10 ( V_2 ) ;
V_9 = F_11 ( & V_18 , & V_2 -> V_4 , V_8 ) ;
if ( V_9 )
goto V_19;
V_9 = F_12 ( V_2 -> V_1 , F_1 , V_20 ,
V_14 , V_2 ) ;
if ( V_9 )
goto V_21;
return 0 ;
V_21:
F_13 () ;
V_19:
F_14 ( V_2 , V_8 ) ;
V_16:
F_15 ( V_2 ) ;
V_13:
F_16 ( V_2 ) ;
V_11:
return V_9 ;
}
static void T_4 F_17 ( struct V_3 * V_2 )
{
F_18 ( V_2 -> V_1 , V_2 ) ;
F_13 () ;
F_14 ( V_2 , ( V_17 void T_3 * ) F_19 ( V_2 ) ) ;
F_15 ( V_2 ) ;
F_16 ( V_2 ) ;
}
static int T_5 F_20 ( void )
{
return F_21 ( & V_22 ) ;
}
static void T_6 F_22 ( void )
{
F_23 ( & V_22 ) ;
}
