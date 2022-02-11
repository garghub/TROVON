static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
return 0 ;
}
static int F_2 ( struct V_5 * V_6 ,
T_1 V_7 )
{
return 0 ;
}
static int F_3 ( struct V_5 * V_6 )
{
struct V_1 * V_8 = F_4 ( V_6 ) ;
F_5 ( V_8 ) ;
return 0 ;
}
static int F_6 ( struct V_5 * V_6 ,
const struct V_9 * V_10 )
{
struct V_11 * V_12 = F_7 ( V_6 ) ;
struct V_1 * V_8 ;
int V_13 ;
V_8 = F_8 ( & V_14 , & V_6 -> V_8 ) ;
if ( F_9 ( V_8 ) )
return F_10 ( V_8 ) ;
V_13 = F_11 ( V_8 , ( unsigned long ) V_12 ) ;
if ( V_13 )
goto V_15;
F_12 ( V_6 , V_8 ) ;
F_13 ( L_1 , V_8 -> V_16 -> V_17 ) ;
return 0 ;
V_15:
F_14 ( V_8 ) ;
return V_13 ;
}
static void F_15 ( struct V_5 * V_6 )
{
struct V_1 * V_8 = F_4 ( V_6 ) ;
F_16 ( V_8 ) ;
F_17 ( V_8 ) ;
F_18 ( V_8 ) ;
F_19 ( V_8 ) ;
}
