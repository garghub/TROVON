static struct V_1 * F_1 ( struct V_1 * V_2 ,
T_1 V_3 )
{
struct V_1 * V_4 = F_2 ( - V_5 ) ;
unsigned int V_6 , V_7 ;
T_2 V_8 ;
int V_9 ;
F_3 ( V_2 ) ;
V_9 = V_2 -> V_10 - V_2 -> V_11 ;
V_7 = V_2 -> V_7 ;
if ( F_4 ( ! F_5 ( V_2 , V_12 ) ) )
goto V_13;
V_6 = F_6 ( F_7 ( V_2 ) ) ;
if ( F_4 ( ! F_5 ( V_2 , V_6 ) ) )
goto V_13;
V_8 = F_8 ( F_7 ( V_2 ) -> V_14 ) ;
if ( ! V_8 )
goto V_13;
F_9 ( V_2 , V_6 ) ;
F_10 ( V_2 ) ;
F_11 ( V_2 ) ;
V_2 -> V_15 = V_8 ;
V_3 &= V_16 ;
V_4 = F_12 ( V_2 , V_3 ) ;
if ( F_13 ( V_4 ) ) {
F_14 ( V_2 , F_15 ( V_17 ) , V_6 ,
V_2 -> V_10 - V_9 ,
V_7 ) ;
goto V_13;
}
for ( V_2 = V_4 ; V_2 ; V_2 = V_2 -> V_18 ) {
V_2 -> V_15 = F_15 ( V_17 ) ;
F_16 ( V_2 , V_6 ) ;
F_17 ( V_2 , - V_9 ) ;
V_2 -> V_10 = V_2 -> V_11 + V_7 ;
V_2 -> V_7 = V_7 ;
}
V_13:
return V_4 ;
}
static int T_3 F_18 ( void )
{
F_19 ( & V_19 ) ;
return 0 ;
}
static void T_4 F_20 ( void )
{
F_21 ( & V_19 ) ;
}
