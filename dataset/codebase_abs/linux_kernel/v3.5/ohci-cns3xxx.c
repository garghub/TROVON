static int T_1
F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_5 ;
if ( F_3 ( & V_6 ) == 1 ) {
F_4 ( 1 << V_7 ) ;
F_5 ( 1 << V_8 ) ;
F_6 ( 1 << V_9 ) ;
F_7 ( ( F_8 ( V_10 ) | ( 0X2 << 24 ) ) ,
V_10 ) ;
}
V_5 = F_9 ( V_4 ) ;
if ( V_5 < 0 )
return V_5 ;
V_4 -> V_11 = 1 ;
V_5 = F_10 ( V_4 ) ;
if ( V_5 < 0 ) {
F_11 ( V_2 -> V_12 . V_13 , L_1 ,
V_2 -> V_12 . V_14 ) ;
F_12 ( V_2 ) ;
return V_5 ;
}
return 0 ;
}
static int F_13 ( struct V_15 * V_16 )
{
struct V_17 * V_18 = & V_16 -> V_18 ;
struct V_1 * V_2 ;
const struct V_19 * V_20 = & V_21 ;
struct V_22 * V_23 ;
int V_24 ;
int V_25 ;
if ( F_14 () )
return - V_26 ;
V_23 = F_15 ( V_16 , V_27 , 0 ) ;
if ( ! V_23 ) {
F_11 ( V_18 , L_2 ) ;
return - V_26 ;
}
V_24 = V_23 -> V_28 ;
V_2 = F_16 ( V_20 , V_18 , F_17 ( V_18 ) ) ;
if ( ! V_2 )
return - V_29 ;
V_23 = F_15 ( V_16 , V_30 , 0 ) ;
if ( ! V_23 ) {
F_11 ( V_18 , L_3 ) ;
V_25 = - V_26 ;
goto V_31;
}
V_2 -> V_32 = V_23 -> V_28 ;
V_2 -> V_33 = F_18 ( V_23 ) ;
if ( ! F_19 ( V_2 -> V_32 , V_2 -> V_33 ,
V_20 -> V_34 ) ) {
F_20 ( V_18 , L_4 ) ;
V_25 = - V_35 ;
goto V_31;
}
V_2 -> V_36 = F_21 ( V_2 -> V_32 , V_2 -> V_33 ) ;
if ( ! V_2 -> V_36 ) {
F_20 ( V_18 , L_5 ) ;
V_25 = - V_37 ;
goto V_38;
}
F_22 ( F_2 ( V_2 ) ) ;
V_25 = F_23 ( V_2 , V_24 , V_39 ) ;
if ( V_25 == 0 )
return V_25 ;
F_24 ( V_2 -> V_36 ) ;
V_38:
F_25 ( V_2 -> V_32 , V_2 -> V_33 ) ;
V_31:
F_26 ( V_2 ) ;
return V_25 ;
}
static int F_27 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = F_28 ( V_16 ) ;
F_29 ( V_2 ) ;
F_24 ( V_2 -> V_36 ) ;
F_25 ( V_2 -> V_32 , V_2 -> V_33 ) ;
if ( F_30 ( & V_6 ) == 0 )
F_31 ( 1 << V_8 ) ;
F_26 ( V_2 ) ;
F_32 ( V_16 , NULL ) ;
return 0 ;
}
