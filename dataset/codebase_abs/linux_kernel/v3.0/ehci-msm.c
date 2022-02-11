static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_5 ;
V_4 -> V_6 = V_7 ;
V_4 -> V_8 = V_7 +
F_3 ( V_4 , F_4 ( V_4 , & V_4 -> V_6 -> V_9 ) ) ;
F_5 ( V_4 , L_1 ) ;
F_6 ( V_4 , L_1 ) ;
V_4 -> V_10 = F_4 ( V_4 , & V_4 -> V_6 -> V_10 ) ;
V_2 -> V_11 = 1 ;
V_4 -> V_12 = V_13 ;
V_5 = F_7 ( V_4 ) ;
if ( V_5 )
return V_5 ;
V_5 = F_8 ( V_2 ) ;
if ( V_5 )
return V_5 ;
V_5 = F_9 ( V_4 ) ;
if ( V_5 )
return V_5 ;
F_10 ( 0 , V_14 ) ;
F_10 ( 0 , V_15 ) ;
F_10 ( 0x13 , V_16 ) ;
F_11 ( V_4 , 1 ) ;
return 0 ;
}
static int F_12 ( struct V_17 * V_18 )
{
struct V_1 * V_2 ;
struct V_19 * V_20 ;
int V_21 ;
F_13 ( & V_18 -> V_22 , L_2 ) ;
V_2 = F_14 ( & V_23 , & V_18 -> V_22 , F_15 ( & V_18 -> V_22 ) ) ;
if ( ! V_2 ) {
F_16 ( & V_18 -> V_22 , L_3 ) ;
return - V_24 ;
}
V_2 -> V_25 = F_17 ( V_18 , 0 ) ;
if ( V_2 -> V_25 < 0 ) {
F_16 ( & V_18 -> V_22 , L_4 ) ;
V_21 = V_2 -> V_25 ;
goto V_26;
}
V_20 = F_18 ( V_18 , V_27 , 0 ) ;
if ( ! V_20 ) {
F_16 ( & V_18 -> V_22 , L_5 ) ;
V_21 = - V_28 ;
goto V_26;
}
V_2 -> V_29 = V_20 -> V_30 ;
V_2 -> V_31 = F_19 ( V_20 ) ;
V_2 -> V_8 = F_20 ( V_2 -> V_29 , V_2 -> V_31 ) ;
if ( ! V_2 -> V_8 ) {
F_16 ( & V_18 -> V_22 , L_6 ) ;
V_21 = - V_24 ;
goto V_26;
}
V_32 = F_21 () ;
if ( ! V_32 ) {
F_16 ( & V_18 -> V_22 , L_7 ) ;
V_21 = - V_28 ;
goto V_33;
}
V_21 = F_22 ( V_32 , & V_2 -> V_34 ) ;
if ( V_21 < 0 ) {
F_16 ( & V_18 -> V_22 , L_8 ) ;
goto V_35;
}
F_23 ( & V_18 -> V_22 , 1 ) ;
F_24 ( & V_18 -> V_22 ) ;
F_25 ( & V_18 -> V_22 ) ;
return 0 ;
V_35:
F_26 ( V_32 ) ;
V_33:
F_27 ( V_2 -> V_8 ) ;
V_26:
F_28 ( V_2 ) ;
return V_21 ;
}
static int T_1 F_29 ( struct V_17 * V_18 )
{
struct V_1 * V_2 = F_30 ( V_18 ) ;
F_23 ( & V_18 -> V_22 , 0 ) ;
F_31 ( & V_18 -> V_22 ) ;
F_32 ( & V_18 -> V_22 ) ;
F_22 ( V_32 , NULL ) ;
F_26 ( V_32 ) ;
F_28 ( V_2 ) ;
return 0 ;
}
static int F_33 ( struct V_36 * V_22 )
{
struct V_1 * V_2 = F_34 ( V_22 ) ;
bool V_37 = F_35 ( V_22 ) ;
F_13 ( V_22 , L_9 ) ;
if ( V_2 -> V_34 . V_38 -> V_39 && ! V_37 ) {
F_36 ( V_22 ) ;
F_37 ( F_2 ( V_2 ) ,
V_37 ) ;
}
return 0 ;
}
static int F_38 ( struct V_36 * V_22 )
{
struct V_1 * V_2 = F_34 ( V_22 ) ;
F_13 ( V_22 , L_10 ) ;
F_39 ( F_2 ( V_2 ) ) ;
return 0 ;
}
