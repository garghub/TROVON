static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_1 V_5 ;
V_5 = F_3 ( V_4 -> V_6 + V_7 ) ;
V_5 |= V_8 ;
F_4 ( V_5 , V_4 -> V_6 + V_7 ) ;
return 0 ;
}
static void F_5 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_1 V_5 ;
V_5 = F_3 ( V_4 -> V_6 + V_7 ) ;
V_5 &= ~ V_8 ;
F_4 ( V_5 , V_4 -> V_6 + V_7 ) ;
}
static int F_6 ( struct V_1 * V_2 , int V_9 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return F_3 ( V_4 -> V_6 + V_10 ) & V_11 ;
}
static int F_7 ( struct V_1 * V_2 , T_1 * V_12 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
* V_12 = F_3 ( V_4 -> V_6 + V_13 ) ;
return 4 ;
}
static int F_8 ( struct V_14 * V_15 )
{
struct V_16 * V_17 ;
struct V_18 * V_18 ;
int V_19 ;
struct V_3 * V_4 ;
struct V_1 * V_2 ;
V_17 = F_9 ( V_15 , V_20 , 0 ) ;
if ( ! V_17 ) {
F_10 ( & V_15 -> V_21 , L_1 ) ;
V_19 = - V_22 ;
goto V_23;
}
V_4 = F_11 ( sizeof( * V_4 ) , V_24 ) ;
if ( ! V_4 ) {
F_10 ( & V_15 -> V_21 , L_2 ) ;
V_19 = - V_25 ;
goto V_23;
}
V_2 = F_11 ( sizeof( * V_2 ) , V_24 ) ;
if ( ! V_2 ) {
F_10 ( & V_15 -> V_21 , L_3 ) ;
V_19 = - V_25 ;
goto V_26;
}
F_12 ( V_15 , V_2 ) ;
V_2 -> V_4 = ( unsigned long ) V_4 ;
V_2 -> V_27 = V_15 -> V_27 ;
V_2 -> V_28 = F_1 ;
V_2 -> V_29 = F_5 ;
V_2 -> V_30 = F_6 ;
V_2 -> V_31 = F_7 ;
V_18 = F_13 ( & V_15 -> V_21 , L_4 ) ;
if ( F_14 ( V_18 ) ) {
F_10 ( & V_15 -> V_21 , L_5 ) ;
V_19 = F_15 ( V_18 ) ;
goto V_32;
}
V_4 -> V_18 = V_18 ;
if ( ! F_16 ( & V_15 -> V_21 , V_17 -> V_33 ,
F_17 ( V_17 ) , V_15 -> V_27 ) ) {
F_10 ( & V_15 -> V_21 , L_6 ) ;
V_19 = - V_25 ;
goto V_32;
}
V_4 -> V_6 = F_18 ( & V_15 -> V_21 , V_17 -> V_33 ,
F_17 ( V_17 ) ) ;
if ( ! V_4 -> V_6 ) {
F_10 ( & V_15 -> V_21 , L_7 ) ;
V_19 = - V_25 ;
goto V_32;
}
F_19 ( V_18 ) ;
V_19 = F_20 ( V_2 ) ;
if ( V_19 ) {
F_10 ( & V_15 -> V_21 , L_8 ) ;
goto V_34;
}
F_21 ( & V_15 -> V_21 , L_9 ) ;
return 0 ;
V_34:
F_22 ( V_18 ) ;
V_32:
F_23 ( V_2 ) ;
V_26:
F_23 ( V_4 ) ;
V_23:
return V_19 ;
}
static int F_24 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = F_25 ( V_15 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_26 ( V_2 ) ;
F_22 ( V_4 -> V_18 ) ;
F_23 ( V_4 ) ;
F_23 ( V_2 ) ;
return 0 ;
}
