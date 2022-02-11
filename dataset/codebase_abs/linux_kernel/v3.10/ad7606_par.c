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
int V_16 , V_17 ;
V_17 = F_9 ( V_6 , 0 ) ;
if ( V_17 < 0 ) {
F_10 ( & V_6 -> V_2 , L_1 ) ;
return - V_18 ;
}
V_13 = F_11 ( V_6 , V_19 , 0 ) ;
if ( ! V_13 )
return - V_18 ;
V_15 = F_12 ( V_13 ) ;
if ( ! F_13 ( V_13 -> V_20 , V_15 , L_2 ) ) {
V_16 = - V_21 ;
goto V_22;
}
V_14 = F_14 ( V_13 -> V_20 , V_15 ) ;
if ( ! V_14 ) {
V_16 = - V_23 ;
goto V_22;
}
V_8 = F_15 ( & V_6 -> V_2 , V_17 , V_14 ,
F_16 ( V_6 ) -> V_24 ,
V_15 > 1 ? & V_25 :
& V_26 ) ;
if ( F_17 ( V_8 ) ) {
V_16 = F_18 ( V_8 ) ;
goto V_27;
}
F_19 ( V_6 , V_8 ) ;
return 0 ;
V_27:
F_20 ( V_14 ) ;
V_22:
F_21 ( V_13 -> V_20 , V_15 ) ;
return V_16 ;
}
static int F_22 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = F_3 ( V_6 ) ;
struct V_12 * V_13 ;
struct V_9 * V_10 = F_4 ( V_8 ) ;
F_23 ( V_8 , F_9 ( V_6 , 0 ) ) ;
F_20 ( V_10 -> V_11 ) ;
V_13 = F_11 ( V_6 , V_19 , 0 ) ;
F_21 ( V_13 -> V_20 , F_12 ( V_13 ) ) ;
F_19 ( V_6 , NULL ) ;
return 0 ;
}
static int F_24 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_25 ( V_2 ) ;
F_26 ( V_8 ) ;
return 0 ;
}
static int F_27 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_25 ( V_2 ) ;
F_28 ( V_8 ) ;
return 0 ;
}
