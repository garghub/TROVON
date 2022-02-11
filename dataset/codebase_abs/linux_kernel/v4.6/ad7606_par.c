static int F_1 ( struct V_1 * V_2 ,
int V_3 , void * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = F_3 ( V_6 ) ;
struct V_9 * V_10 = F_4 ( V_8 ) ;
F_5 ( ( unsigned long ) V_10 -> V_11 , V_4 , V_3 ) ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 ,
int V_3 , void * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = F_3 ( V_6 ) ;
struct V_9 * V_10 = F_4 ( V_8 ) ;
F_7 ( ( unsigned long ) V_10 -> V_11 , V_4 , V_3 * 2 ) ;
return 0 ;
}
static int F_8 ( struct V_5 * V_6 )
{
struct V_12 * V_13 ;
struct V_7 * V_8 ;
void T_1 * V_14 ;
T_2 V_15 ;
int V_16 ;
V_16 = F_9 ( V_6 , 0 ) ;
if ( V_16 < 0 ) {
F_10 ( & V_6 -> V_2 , L_1 ) ;
return - V_17 ;
}
V_13 = F_11 ( V_6 , V_18 , 0 ) ;
V_14 = F_12 ( & V_6 -> V_2 , V_13 ) ;
if ( F_13 ( V_14 ) )
return F_14 ( V_14 ) ;
V_15 = F_15 ( V_13 ) ;
V_8 = F_16 ( & V_6 -> V_2 , V_16 , V_14 ,
F_17 ( V_6 ) -> V_19 ,
V_15 > 1 ? & V_20 :
& V_21 ) ;
if ( F_13 ( V_8 ) )
return F_14 ( V_8 ) ;
F_18 ( V_6 , V_8 ) ;
return 0 ;
}
static int F_19 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = F_3 ( V_6 ) ;
F_20 ( V_8 , F_9 ( V_6 , 0 ) ) ;
return 0 ;
}
