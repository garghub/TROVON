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
static int F_5 ( struct V_15 * V_16 )
{
const struct V_17 * V_18 ;
struct V_3 * V_4 ;
struct V_5 * V_6 ;
struct V_19 * V_20 ;
int V_21 = 0 ;
V_4 = F_6 ( sizeof( * V_6 ) , L_1 ,
1 , L_2 , 1 , 2 , NULL , 0 , 0 ) ;
if ( ! V_4 )
return - V_22 ;
V_6 = V_4 -> V_7 ;
V_4 -> V_23 = & V_16 -> V_23 ;
F_7 ( V_16 , V_4 ) ;
if ( ! F_8 ( & V_16 -> V_23 , NULL , V_24 ) )
return - V_22 ;
V_20 = F_9 ( V_16 , V_25 , 0 ) ;
if ( ! V_20 ) {
F_10 ( & V_16 -> V_23 , L_3 ) ;
V_21 = - V_26 ;
goto V_27;
}
if ( ! F_11 ( & V_16 -> V_23 , V_20 -> V_28 ,
F_12 ( V_20 ) , F_13 ( & V_16 -> V_23 ) ) ) {
F_10 ( & V_16 -> V_23 , L_4 ) ;
V_21 = - V_29 ;
goto V_27;
}
V_6 -> V_9 = F_14 ( & V_16 -> V_23 , V_20 -> V_28 , F_12 ( V_20 ) ) ;
if ( ! V_6 -> V_9 ) {
F_10 ( & V_16 -> V_23 , L_5 ) ;
V_21 = - V_22 ;
goto V_27;
}
V_18 = F_15 ( V_30 , & V_16 -> V_23 ) ;
V_4 -> V_31 = V_16 -> V_23 . V_32 -> V_33 ;
V_4 -> V_11 = V_18 ? V_18 -> V_34 : L_6 ;
V_4 -> F_13 = F_13 ( & V_16 -> V_23 ) ;
if ( F_16 ( V_4 ) )
goto V_27;
V_6 -> V_12 = F_17 ( V_16 , 0 ) ;
V_21 = F_18 ( & V_16 -> V_23 , V_6 -> V_12 ,
F_1 ,
0 , F_13 ( & V_16 -> V_23 ) , V_4 ) ;
if ( V_21 < 0 )
goto V_35;
V_6 -> V_8 = F_17 ( V_16 , 1 ) ;
V_21 = F_18 ( & V_16 -> V_23 , V_6 -> V_8 ,
F_1 ,
0 , F_13 ( & V_16 -> V_23 ) , V_4 ) ;
if ( V_21 < 0 )
goto V_35;
F_19 ( & V_16 -> V_23 , NULL ) ;
return 0 ;
V_35:
F_20 ( & V_16 -> V_23 ) ;
V_27:
F_21 ( & V_16 -> V_23 , NULL ) ;
F_22 ( V_4 ) ;
return V_21 ;
}
static int F_23 ( struct V_15 * V_16 )
{
struct V_3 * V_4 = F_24 ( V_16 ) ;
F_20 ( & V_16 -> V_23 ) ;
F_22 ( V_4 ) ;
return 0 ;
}
