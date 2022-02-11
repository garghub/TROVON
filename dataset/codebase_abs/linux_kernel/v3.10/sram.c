static int F_1 ( struct V_1 * V_2 )
{
void T_1 * V_3 ;
struct V_4 * V_5 ;
struct V_6 * V_7 ;
unsigned long V_8 ;
int V_9 ;
V_7 = F_2 ( V_2 , V_10 , 0 ) ;
if ( ! V_7 )
return - V_11 ;
V_8 = F_3 ( V_7 ) ;
V_3 = F_4 ( & V_2 -> V_12 , V_7 ) ;
if ( ! V_3 )
return - V_13 ;
V_5 = F_5 ( & V_2 -> V_12 , sizeof( * V_5 ) , V_14 ) ;
if ( ! V_5 )
return - V_15 ;
V_5 -> V_16 = F_6 ( & V_2 -> V_12 , NULL ) ;
if ( F_7 ( V_5 -> V_16 ) )
V_5 -> V_16 = NULL ;
else
F_8 ( V_5 -> V_16 ) ;
V_5 -> V_17 = F_9 ( & V_2 -> V_12 , F_10 ( V_18 ) , - 1 ) ;
if ( ! V_5 -> V_17 )
return - V_15 ;
V_9 = F_11 ( V_5 -> V_17 , ( unsigned long ) V_3 ,
V_7 -> V_19 , V_8 , - 1 ) ;
if ( V_9 < 0 ) {
F_12 ( V_5 -> V_17 ) ;
return V_9 ;
}
F_13 ( V_2 , V_5 ) ;
F_14 ( & V_2 -> V_12 , L_1 , V_8 / 1024 , V_3 ) ;
return 0 ;
}
static int F_15 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_16 ( V_2 ) ;
if ( F_17 ( V_5 -> V_17 ) < F_18 ( V_5 -> V_17 ) )
F_14 ( & V_2 -> V_12 , L_2 ) ;
F_12 ( V_5 -> V_17 ) ;
if ( V_5 -> V_16 )
F_19 ( V_5 -> V_16 ) ;
return 0 ;
}
static int T_2 F_20 ( void )
{
return F_21 ( & V_20 ) ;
}
