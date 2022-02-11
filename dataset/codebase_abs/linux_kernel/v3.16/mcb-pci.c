static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = V_4 -> V_8 ;
struct V_9 * V_10 = F_2 ( V_7 ) ;
return V_10 -> V_11 ;
}
static int F_3 ( struct V_9 * V_10 , const struct V_12 * V_13 )
{
struct V_14 * V_14 ;
T_1 V_15 ;
int V_16 ;
int V_17 ;
unsigned long V_18 ;
V_14 = F_4 ( & V_10 -> V_7 , sizeof( struct V_14 ) , V_19 ) ;
if ( ! V_14 )
return - V_20 ;
V_16 = F_5 ( V_10 ) ;
if ( V_16 ) {
F_6 ( & V_10 -> V_7 , L_1 ) ;
return - V_21 ;
}
V_15 = F_7 ( V_10 , 0 ) ;
if ( ! V_15 ) {
F_6 ( & V_10 -> V_7 , L_2 ) ;
goto V_22;
}
V_16 = F_8 ( V_10 , 0 , V_23 ) ;
if ( V_16 ) {
F_6 ( & V_10 -> V_7 , L_3 ) ;
goto V_22;
}
V_14 -> V_24 = F_9 ( V_10 , 0 , 0 ) ;
if ( ! V_14 -> V_24 ) {
F_6 ( & V_10 -> V_7 , L_4 ) ;
V_16 = - V_20 ;
goto V_25;
}
V_18 = F_10 ( V_10 , 0 ) ;
if ( V_18 & V_26 ) {
V_16 = - V_27 ;
F_6 ( & V_10 -> V_7 ,
L_5 ) ;
goto V_25;
}
F_11 ( V_10 , V_14 ) ;
V_14 -> V_5 = F_12 ( & V_10 -> V_7 ) ;
if ( F_13 ( V_14 -> V_5 ) ) {
V_16 = F_14 ( V_14 -> V_5 ) ;
goto V_28;
}
V_14 -> V_5 -> V_29 = F_1 ;
V_16 = F_15 ( V_14 -> V_5 , V_15 , V_14 -> V_24 ) ;
if ( V_16 < 0 )
goto V_28;
V_17 = V_16 ;
F_16 ( & V_10 -> V_7 , L_6 , V_17 ) ;
F_17 ( V_14 -> V_5 ) ;
V_28:
F_18 ( V_10 , V_14 -> V_24 ) ;
V_25:
F_19 ( V_10 , 0 ) ;
V_22:
F_20 ( V_10 ) ;
return V_16 ;
}
static void F_21 ( struct V_9 * V_10 )
{
struct V_14 * V_14 = F_22 ( V_10 ) ;
F_23 ( V_14 -> V_5 ) ;
}
