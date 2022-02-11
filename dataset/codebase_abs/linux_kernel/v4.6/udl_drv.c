static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
return 0 ;
}
static int F_2 ( struct V_5 * V_6 ,
const struct V_7 * V_8 )
{
struct V_9 * V_10 = F_3 ( V_6 ) ;
struct V_1 * V_11 ;
int V_12 ;
V_11 = F_4 ( & V_13 , & V_6 -> V_11 ) ;
if ( ! V_11 )
return - V_14 ;
V_12 = F_5 ( V_11 , ( unsigned long ) V_10 ) ;
if ( V_12 )
goto V_15;
F_6 ( V_6 , V_11 ) ;
F_7 ( L_1 , V_11 -> V_16 -> V_17 ) ;
return 0 ;
V_15:
F_8 ( V_11 ) ;
return V_12 ;
}
static void F_9 ( struct V_5 * V_6 )
{
struct V_1 * V_11 = F_10 ( V_6 ) ;
F_11 ( V_11 ) ;
F_12 ( V_11 ) ;
F_13 ( V_11 ) ;
F_14 ( V_11 ) ;
F_15 ( V_11 ) ;
}
