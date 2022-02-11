static int F_1 ( struct V_1 * V_2 )
{
void T_1 * V_3 ;
struct V_4 * V_5 ;
struct V_6 * V_7 ;
unsigned long V_8 ;
int V_9 ;
V_7 = F_2 ( V_2 , V_10 , 0 ) ;
V_3 = F_3 ( & V_2 -> V_11 , V_7 ) ;
if ( F_4 ( V_3 ) )
return F_5 ( V_3 ) ;
V_8 = F_6 ( V_7 ) ;
V_5 = F_7 ( & V_2 -> V_11 , sizeof( * V_5 ) , V_12 ) ;
if ( ! V_5 )
return - V_13 ;
V_5 -> V_14 = F_8 ( & V_2 -> V_11 , NULL ) ;
if ( F_4 ( V_5 -> V_14 ) )
V_5 -> V_14 = NULL ;
else
F_9 ( V_5 -> V_14 ) ;
V_5 -> V_15 = F_10 ( & V_2 -> V_11 , F_11 ( V_16 ) , - 1 ) ;
if ( ! V_5 -> V_15 )
return - V_13 ;
V_9 = F_12 ( V_5 -> V_15 , ( unsigned long ) V_3 ,
V_7 -> V_17 , V_8 , - 1 ) ;
if ( V_9 < 0 ) {
F_13 ( V_5 -> V_15 ) ;
return V_9 ;
}
F_14 ( V_2 , V_5 ) ;
F_15 ( & V_2 -> V_11 , L_1 , V_8 / 1024 , V_3 ) ;
return 0 ;
}
static int F_16 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_17 ( V_2 ) ;
if ( F_18 ( V_5 -> V_15 ) < F_19 ( V_5 -> V_15 ) )
F_15 ( & V_2 -> V_11 , L_2 ) ;
F_13 ( V_5 -> V_15 ) ;
if ( V_5 -> V_14 )
F_20 ( V_5 -> V_14 ) ;
return 0 ;
}
static int T_2 F_21 ( void )
{
return F_22 ( & V_18 ) ;
}
