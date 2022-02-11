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
int V_18 ;
unsigned long V_19 ;
V_16 = F_4 ( & V_10 -> V_7 , sizeof( struct V_16 ) , V_20 ) ;
if ( ! V_16 )
return - V_21 ;
V_17 = F_5 ( V_10 ) ;
if ( V_17 ) {
F_6 ( & V_10 -> V_7 , L_1 ) ;
return - V_22 ;
}
V_16 -> V_23 = F_7 ( V_10 , 0 ) ;
if ( ! V_16 -> V_23 ) {
F_6 ( & V_10 -> V_7 , L_2 ) ;
goto V_24;
}
V_15 = F_8 ( V_16 -> V_23 , V_25 ,
V_26 ) ;
if ( ! V_15 ) {
F_6 ( & V_10 -> V_7 , L_3 ) ;
V_17 = - V_27 ;
goto V_24;
}
V_16 -> V_28 = F_9 ( V_16 -> V_23 , V_25 ) ;
if ( ! V_16 -> V_28 ) {
F_6 ( & V_10 -> V_7 , L_4 ) ;
V_17 = - V_21 ;
goto V_29;
}
V_19 = F_10 ( V_10 , 0 ) ;
if ( V_19 & V_30 ) {
V_17 = - V_31 ;
F_6 ( & V_10 -> V_7 ,
L_5 ) ;
goto V_29;
}
F_11 ( V_10 , V_16 ) ;
V_16 -> V_5 = F_12 ( & V_10 -> V_7 ) ;
if ( F_13 ( V_16 -> V_5 ) ) {
V_17 = F_14 ( V_16 -> V_5 ) ;
goto V_32;
}
V_16 -> V_5 -> V_33 = F_1 ;
V_17 = F_15 ( V_16 -> V_5 , V_16 -> V_23 , V_16 -> V_28 ) ;
if ( V_17 < 0 )
goto V_32;
V_18 = V_17 ;
F_16 ( & V_10 -> V_7 , L_6 , V_18 ) ;
F_17 ( V_16 -> V_5 ) ;
return 0 ;
V_32:
F_18 ( V_16 -> V_28 ) ;
V_29:
F_19 ( V_10 , 0 ) ;
V_24:
F_20 ( V_10 ) ;
return V_17 ;
}
static void F_21 ( struct V_9 * V_10 )
{
struct V_16 * V_16 = F_22 ( V_10 ) ;
F_23 ( V_16 -> V_5 ) ;
F_18 ( V_16 -> V_28 ) ;
F_24 ( V_16 -> V_23 , V_25 ) ;
F_20 ( V_10 ) ;
}
