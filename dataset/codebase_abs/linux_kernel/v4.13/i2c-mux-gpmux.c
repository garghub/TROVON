static int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_4 * V_4 = F_2 ( V_2 ) ;
int V_5 ;
V_5 = F_3 ( V_4 -> V_6 , V_3 ) ;
V_4 -> V_7 = V_5 < 0 ;
return V_5 ;
}
static int F_4 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_4 * V_4 = F_2 ( V_2 ) ;
if ( V_4 -> V_7 )
return 0 ;
return F_5 ( V_4 -> V_6 ) ;
}
static struct V_8 * F_6 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_11 * V_14 ;
struct V_8 * V_15 ;
V_14 = F_7 ( V_12 , L_1 , 0 ) ;
if ( ! V_14 ) {
F_8 ( V_10 , L_2 ) ;
return F_9 ( - V_16 ) ;
}
V_15 = F_10 ( V_14 ) ;
F_11 ( V_14 ) ;
if ( ! V_15 )
return F_9 ( - V_17 ) ;
return V_15 ;
}
static int F_12 ( struct V_18 * V_19 )
{
struct V_9 * V_10 = & V_19 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_11 * V_20 ;
struct V_1 * V_2 ;
struct V_4 * V_4 ;
struct V_8 * V_15 ;
int V_21 ;
int V_5 ;
if ( ! V_12 )
return - V_16 ;
V_4 = F_13 ( V_10 , sizeof( * V_4 ) , V_22 ) ;
if ( ! V_4 )
return - V_23 ;
V_4 -> V_6 = F_14 ( V_10 , NULL ) ;
if ( F_15 ( V_4 -> V_6 ) ) {
if ( F_16 ( V_4 -> V_6 ) != - V_17 )
F_8 ( V_10 , L_3 ) ;
return F_16 ( V_4 -> V_6 ) ;
}
V_15 = F_6 ( V_10 ) ;
if ( F_15 ( V_15 ) ) {
if ( F_16 ( V_15 ) != - V_17 )
F_8 ( V_10 , L_4 ) ;
return F_16 ( V_15 ) ;
}
V_21 = F_17 ( V_12 ) ;
V_2 = F_18 ( V_15 , V_10 , V_21 , 0 , 0 ,
F_1 , F_4 ) ;
if ( ! V_2 ) {
V_5 = - V_23 ;
goto V_24;
}
V_2 -> V_25 = V_4 ;
F_19 ( V_19 , V_2 ) ;
V_2 -> V_26 = F_20 ( V_12 , L_5 ) ;
F_21 (np, child) {
T_1 V_3 ;
V_5 = F_22 ( V_20 , L_6 , & V_3 ) ;
if ( V_5 < 0 ) {
F_8 ( V_10 , L_7 ,
V_20 -> V_27 ) ;
goto V_28;
}
if ( V_3 >= F_23 ( V_4 -> V_6 ) ) {
F_8 ( V_10 , L_8 , V_3 ) ;
V_5 = - V_29 ;
goto V_28;
}
V_5 = F_24 ( V_2 , 0 , V_3 , 0 ) ;
if ( V_5 )
goto V_28;
}
F_25 ( V_10 , L_9 , V_21 , V_15 -> V_27 ) ;
return 0 ;
V_28:
F_26 ( V_2 ) ;
V_24:
F_27 ( V_15 ) ;
return V_5 ;
}
static int F_28 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = F_29 ( V_19 ) ;
F_26 ( V_2 ) ;
F_27 ( V_2 -> V_15 ) ;
return 0 ;
}
