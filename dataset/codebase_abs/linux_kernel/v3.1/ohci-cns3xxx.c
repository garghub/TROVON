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
F_11 ( L_1 , V_2 -> V_12 . V_13 ) ;
F_12 ( V_2 ) ;
return V_5 ;
}
return 0 ;
}
static int F_13 ( struct V_14 * V_15 )
{
struct V_16 * V_17 = & V_15 -> V_17 ;
struct V_1 * V_2 ;
const struct V_18 * V_19 = & V_20 ;
struct V_21 * V_22 ;
int V_23 ;
int V_24 ;
if ( F_14 () )
return - V_25 ;
V_22 = F_15 ( V_15 , V_26 , 0 ) ;
if ( ! V_22 ) {
F_16 ( V_17 , L_2 ) ;
return - V_25 ;
}
V_23 = V_22 -> V_27 ;
V_2 = F_17 ( V_19 , V_17 , F_18 ( V_17 ) ) ;
if ( ! V_2 )
return - V_28 ;
V_22 = F_15 ( V_15 , V_29 , 0 ) ;
if ( ! V_22 ) {
F_16 ( V_17 , L_3 ) ;
V_24 = - V_25 ;
goto V_30;
}
V_2 -> V_31 = V_22 -> V_27 ;
V_2 -> V_32 = F_19 ( V_22 ) ;
if ( ! F_20 ( V_2 -> V_31 , V_2 -> V_32 ,
V_19 -> V_33 ) ) {
F_21 ( V_17 , L_4 ) ;
V_24 = - V_34 ;
goto V_30;
}
V_2 -> V_35 = F_22 ( V_2 -> V_31 , V_2 -> V_32 ) ;
if ( ! V_2 -> V_35 ) {
F_21 ( V_17 , L_5 ) ;
V_24 = - V_36 ;
goto V_37;
}
F_23 ( F_2 ( V_2 ) ) ;
V_24 = F_24 ( V_2 , V_23 , V_38 ) ;
if ( V_24 == 0 )
return V_24 ;
F_25 ( V_2 -> V_35 ) ;
V_37:
F_26 ( V_2 -> V_31 , V_2 -> V_32 ) ;
V_30:
F_27 ( V_2 ) ;
return V_24 ;
}
static int F_28 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = F_29 ( V_15 ) ;
F_30 ( V_2 ) ;
F_25 ( V_2 -> V_35 ) ;
F_26 ( V_2 -> V_31 , V_2 -> V_32 ) ;
if ( F_31 ( & V_6 ) == 0 )
F_32 ( 1 << V_8 ) ;
F_27 ( V_2 ) ;
F_33 ( V_15 , NULL ) ;
return 0 ;
}
