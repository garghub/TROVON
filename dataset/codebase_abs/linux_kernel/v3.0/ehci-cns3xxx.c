static int F_1 ( struct V_1 * V_2 )
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
V_4 -> V_11 = V_2 -> V_12 ;
V_4 -> V_12 = V_2 -> V_12
+ F_9 ( V_4 , F_10 ( V_4 , & V_4 -> V_11 -> V_13 ) ) ;
V_4 -> V_14 = F_10 ( V_4 , & V_4 -> V_11 -> V_14 ) ;
V_2 -> V_15 = 0 ;
F_11 ( V_4 ) ;
V_5 = F_12 ( V_2 ) ;
if ( V_5 )
return V_5 ;
F_13 ( V_4 , 0 ) ;
return V_5 ;
}
static int F_14 ( struct V_16 * V_17 )
{
struct V_18 * V_19 = & V_17 -> V_19 ;
struct V_1 * V_2 ;
const struct V_20 * V_21 = & V_22 ;
struct V_23 * V_24 ;
int V_25 ;
int V_5 ;
if ( F_15 () )
return - V_26 ;
V_24 = F_16 ( V_17 , V_27 , 0 ) ;
if ( ! V_24 ) {
F_17 ( V_19 , L_1 ) ;
return - V_26 ;
}
V_25 = V_24 -> V_28 ;
V_2 = F_18 ( V_21 , & V_17 -> V_19 , F_19 ( & V_17 -> V_19 ) ) ;
if ( ! V_2 )
return - V_29 ;
V_24 = F_16 ( V_17 , V_30 , 0 ) ;
if ( ! V_24 ) {
F_17 ( V_19 , L_2 ) ;
V_5 = - V_26 ;
goto V_31;
}
V_2 -> V_32 = V_24 -> V_28 ;
V_2 -> V_33 = V_24 -> V_34 - V_24 -> V_28 + 1 ;
if ( ! F_20 ( V_2 -> V_32 , V_2 -> V_33 ,
V_21 -> V_35 ) ) {
F_21 ( V_19 , L_3 ) ;
V_5 = - V_36 ;
goto V_31;
}
V_2 -> V_12 = F_22 ( V_2 -> V_32 , V_2 -> V_33 ) ;
if ( V_2 -> V_12 == NULL ) {
F_21 ( V_19 , L_4 ) ;
V_5 = - V_37 ;
goto V_38;
}
V_5 = F_23 ( V_2 , V_25 , V_39 ) ;
if ( V_5 == 0 )
return V_5 ;
F_24 ( V_2 -> V_12 ) ;
V_38:
F_25 ( V_2 -> V_32 , V_2 -> V_33 ) ;
V_31:
F_26 ( V_2 ) ;
return V_5 ;
}
static int F_27 ( struct V_16 * V_17 )
{
struct V_1 * V_2 = F_28 ( V_17 ) ;
F_29 ( V_2 ) ;
F_24 ( V_2 -> V_12 ) ;
F_25 ( V_2 -> V_32 , V_2 -> V_33 ) ;
if ( F_30 ( & V_6 ) == 0 )
F_31 ( 1 << V_8 ) ;
F_26 ( V_2 ) ;
F_32 ( V_17 , NULL ) ;
return 0 ;
}
