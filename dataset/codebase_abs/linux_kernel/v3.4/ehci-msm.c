static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_5 ;
V_4 -> V_6 = V_7 ;
V_2 -> V_8 = 1 ;
V_5 = F_3 ( V_2 ) ;
if ( V_5 )
return V_5 ;
F_4 ( 0 , V_9 ) ;
F_4 ( 0 , V_10 ) ;
F_4 ( 0x13 , V_11 ) ;
F_5 ( V_4 , 1 ) ;
return 0 ;
}
static int F_6 ( struct V_12 * V_13 )
{
struct V_1 * V_2 ;
struct V_14 * V_15 ;
int V_16 ;
F_7 ( & V_13 -> V_17 , L_1 ) ;
V_2 = F_8 ( & V_18 , & V_13 -> V_17 , F_9 ( & V_13 -> V_17 ) ) ;
if ( ! V_2 ) {
F_10 ( & V_13 -> V_17 , L_2 ) ;
return - V_19 ;
}
V_2 -> V_20 = F_11 ( V_13 , 0 ) ;
if ( V_2 -> V_20 < 0 ) {
F_10 ( & V_13 -> V_17 , L_3 ) ;
V_16 = V_2 -> V_20 ;
goto V_21;
}
V_15 = F_12 ( V_13 , V_22 , 0 ) ;
if ( ! V_15 ) {
F_10 ( & V_13 -> V_17 , L_4 ) ;
V_16 = - V_23 ;
goto V_21;
}
V_2 -> V_24 = V_15 -> V_25 ;
V_2 -> V_26 = F_13 ( V_15 ) ;
V_2 -> V_27 = F_14 ( V_2 -> V_24 , V_2 -> V_26 ) ;
if ( ! V_2 -> V_27 ) {
F_10 ( & V_13 -> V_17 , L_5 ) ;
V_16 = - V_19 ;
goto V_21;
}
V_28 = F_15 () ;
if ( ! V_28 ) {
F_10 ( & V_13 -> V_17 , L_6 ) ;
V_16 = - V_23 ;
goto V_29;
}
V_16 = F_16 ( V_28 -> V_30 , & V_2 -> V_31 ) ;
if ( V_16 < 0 ) {
F_10 ( & V_13 -> V_17 , L_7 ) ;
goto V_32;
}
F_17 ( & V_13 -> V_17 , 1 ) ;
F_18 ( & V_13 -> V_17 ) ;
F_19 ( & V_13 -> V_17 ) ;
return 0 ;
V_32:
F_20 ( V_28 ) ;
V_29:
F_21 ( V_2 -> V_27 ) ;
V_21:
F_22 ( V_2 ) ;
return V_16 ;
}
static int T_1 F_23 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = F_24 ( V_13 ) ;
F_17 ( & V_13 -> V_17 , 0 ) ;
F_25 ( & V_13 -> V_17 ) ;
F_26 ( & V_13 -> V_17 ) ;
F_16 ( V_28 -> V_30 , NULL ) ;
F_20 ( V_28 ) ;
F_22 ( V_2 ) ;
return 0 ;
}
static int F_27 ( struct V_33 * V_17 )
{
struct V_1 * V_2 = F_28 ( V_17 ) ;
bool V_34 = F_29 ( V_17 ) ;
F_7 ( V_17 , L_8 ) ;
if ( V_2 -> V_31 . V_35 -> V_36 && ! V_34 ) {
F_30 ( V_17 ) ;
F_31 ( F_2 ( V_2 ) ,
V_34 ) ;
}
return 0 ;
}
static int F_32 ( struct V_33 * V_17 )
{
struct V_1 * V_2 = F_28 ( V_17 ) ;
F_7 ( V_17 , L_9 ) ;
F_33 ( F_2 ( V_2 ) ) ;
return 0 ;
}
