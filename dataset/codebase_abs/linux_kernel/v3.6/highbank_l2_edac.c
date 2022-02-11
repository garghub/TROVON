static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = V_2 ;
struct V_5 * V_6 = V_4 -> V_7 ;
if ( V_1 == V_6 -> V_8 ) {
F_2 ( 1 , V_6 -> V_9 + V_10 ) ;
F_3 ( V_4 , 0 , 0 , V_4 -> V_11 ) ;
}
if ( V_1 == V_6 -> V_12 ) {
F_2 ( 1 , V_6 -> V_9 + V_13 ) ;
F_4 ( V_4 , 0 , 0 , V_4 -> V_11 ) ;
}
return V_14 ;
}
static int T_2 F_5 ( struct V_15 * V_16 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 ;
struct V_17 * V_18 ;
int V_19 = 0 ;
V_4 = F_6 ( sizeof( * V_6 ) , L_1 ,
1 , L_2 , 1 , 2 , NULL , 0 , 0 ) ;
if ( ! V_4 )
return - V_20 ;
V_6 = V_4 -> V_7 ;
V_4 -> V_21 = & V_16 -> V_21 ;
F_7 ( V_16 , V_4 ) ;
if ( ! F_8 ( & V_16 -> V_21 , NULL , V_22 ) )
return - V_20 ;
V_18 = F_9 ( V_16 , V_23 , 0 ) ;
if ( ! V_18 ) {
F_10 ( & V_16 -> V_21 , L_3 ) ;
V_19 = - V_24 ;
goto V_25;
}
if ( ! F_11 ( & V_16 -> V_21 , V_18 -> V_26 ,
F_12 ( V_18 ) , F_13 ( & V_16 -> V_21 ) ) ) {
F_10 ( & V_16 -> V_21 , L_4 ) ;
V_19 = - V_27 ;
goto V_25;
}
V_6 -> V_9 = F_14 ( & V_16 -> V_21 , V_18 -> V_26 , F_12 ( V_18 ) ) ;
if ( ! V_6 -> V_9 ) {
F_10 ( & V_16 -> V_21 , L_5 ) ;
V_19 = - V_20 ;
goto V_25;
}
V_6 -> V_12 = F_15 ( V_16 , 0 ) ;
V_19 = F_16 ( & V_16 -> V_21 , V_6 -> V_12 ,
F_1 ,
0 , F_13 ( & V_16 -> V_21 ) , V_4 ) ;
if ( V_19 < 0 )
goto V_25;
V_6 -> V_8 = F_15 ( V_16 , 1 ) ;
V_19 = F_16 ( & V_16 -> V_21 , V_6 -> V_8 ,
F_1 ,
0 , F_13 ( & V_16 -> V_21 ) , V_4 ) ;
if ( V_19 < 0 )
goto V_25;
V_4 -> V_28 = F_13 ( & V_16 -> V_21 ) ;
V_4 -> F_13 = F_13 ( & V_16 -> V_21 ) ;
if ( F_17 ( V_4 ) )
goto V_25;
F_18 ( & V_16 -> V_21 , NULL ) ;
return 0 ;
V_25:
F_19 ( & V_16 -> V_21 , NULL ) ;
F_20 ( V_4 ) ;
return V_19 ;
}
static int F_21 ( struct V_15 * V_16 )
{
struct V_3 * V_4 = F_22 ( V_16 ) ;
F_23 ( & V_16 -> V_21 ) ;
F_20 ( V_4 ) ;
return 0 ;
}
