static int F_1 ( struct V_1 * V_2 ,
T_1 V_3 )
{
return 0 ;
}
static int F_2 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_3 ( V_2 ) ;
F_4 ( V_5 ) ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 ,
const struct V_6 * V_7 )
{
struct V_8 * V_9 = F_6 ( V_2 ) ;
struct V_4 * V_5 ;
int V_10 ;
V_5 = F_7 ( & V_11 , & V_2 -> V_5 ) ;
if ( F_8 ( V_5 ) )
return F_9 ( V_5 ) ;
V_10 = F_10 ( V_5 , ( unsigned long ) V_9 ) ;
if ( V_10 )
goto V_12;
F_11 ( V_2 , V_5 ) ;
F_12 ( L_1 , V_5 -> V_13 -> V_14 ) ;
return 0 ;
V_12:
F_13 ( V_5 ) ;
return V_10 ;
}
static void F_14 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_3 ( V_2 ) ;
F_15 ( V_5 ) ;
F_16 ( V_5 ) ;
F_17 ( V_5 ) ;
F_18 ( V_5 ) ;
}
