static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = V_4 -> V_8 ;
struct V_9 * V_10 = F_2 ( V_7 ) ;
return V_10 -> V_11 ;
}
static int F_3 ( struct V_9 * V_10 , const struct V_12 * V_13 )
{
struct V_14 * V_15 ;
struct V_16 * V_16 ;
int V_17 ;
unsigned long V_18 ;
V_16 = F_4 ( & V_10 -> V_7 , sizeof( struct V_16 ) , V_19 ) ;
if ( ! V_16 )
return - V_20 ;
V_17 = F_5 ( V_10 ) ;
if ( V_17 ) {
F_6 ( & V_10 -> V_7 , L_1 ) ;
return - V_21 ;
}
V_16 -> V_22 = F_7 ( V_10 , 0 ) ;
if ( ! V_16 -> V_22 ) {
F_6 ( & V_10 -> V_7 , L_2 ) ;
V_17 = - V_21 ;
goto V_23;
}
V_15 = F_8 ( & V_10 -> V_7 , V_16 -> V_22 ,
V_24 ,
V_25 ) ;
if ( ! V_15 ) {
F_6 ( & V_10 -> V_7 , L_3 ) ;
V_17 = - V_26 ;
goto V_23;
}
V_16 -> V_27 = F_9 ( & V_10 -> V_7 , V_16 -> V_22 , V_24 ) ;
if ( ! V_16 -> V_27 ) {
F_6 ( & V_10 -> V_7 , L_4 ) ;
V_17 = - V_20 ;
goto V_23;
}
V_18 = F_10 ( V_10 , 0 ) ;
if ( V_18 & V_28 ) {
V_17 = - V_29 ;
F_6 ( & V_10 -> V_7 ,
L_5 ) ;
goto V_23;
}
F_11 ( V_10 , V_16 ) ;
V_16 -> V_5 = F_12 ( & V_10 -> V_7 ) ;
if ( F_13 ( V_16 -> V_5 ) ) {
V_17 = F_14 ( V_16 -> V_5 ) ;
goto V_23;
}
V_16 -> V_5 -> V_30 = F_1 ;
V_17 = F_15 ( V_16 -> V_5 , V_16 -> V_22 , V_16 -> V_27 ) ;
if ( V_17 < 0 )
goto V_31;
F_16 ( & V_10 -> V_7 , L_6 , V_17 ) ;
F_17 ( V_16 -> V_5 ) ;
return 0 ;
V_31:
F_18 ( V_16 -> V_5 ) ;
V_23:
F_19 ( V_10 ) ;
return V_17 ;
}
static void F_20 ( struct V_9 * V_10 )
{
struct V_16 * V_16 = F_21 ( V_10 ) ;
F_18 ( V_16 -> V_5 ) ;
F_19 ( V_10 ) ;
}
