static int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
V_5 -> V_6 = V_2 -> V_7 ;
V_5 -> V_7 = V_2 -> V_7 +
F_3 ( V_5 , F_4 ( V_5 , & V_5 -> V_6 -> V_8 ) ) ;
F_5 ( V_5 , L_1 ) ;
F_6 ( V_5 , L_1 ) ;
V_5 -> V_9 = F_4 ( V_5 , & V_5 -> V_6 -> V_9 ) ;
V_3 = F_7 ( V_5 ) ;
if ( V_3 )
return V_3 ;
V_3 = F_8 ( V_2 ) ;
if ( V_3 )
return V_3 ;
F_9 ( V_5 ) ;
return V_3 ;
}
int F_10 ( const struct V_10 * V_11 ,
struct V_12 * V_13 )
{
struct V_1 * V_2 ;
struct V_14 * V_15 ;
int V_3 , V_16 ;
V_16 = F_11 ( V_13 , 0 ) ;
if ( V_16 < 0 ) {
F_12 ( & V_13 -> V_17 , L_2 ,
F_13 ( & V_13 -> V_17 ) ) ;
return - V_18 ;
}
V_15 = F_14 ( V_13 , V_19 , 0 ) ;
if ( ! V_15 ) {
F_12 ( & V_13 -> V_17 , L_3 ,
F_13 ( & V_13 -> V_17 ) ) ;
return - V_18 ;
}
V_2 = F_15 ( V_11 , & V_13 -> V_17 , F_13 ( & V_13 -> V_17 ) ) ;
if ( ! V_2 ) {
V_3 = - V_20 ;
goto V_21;
}
V_2 -> V_22 = V_15 -> V_23 ;
V_2 -> V_24 = V_15 -> V_25 - V_15 -> V_23 + 1 ;
if ( ! F_16 ( V_2 -> V_22 , V_2 -> V_24 ,
V_11 -> V_26 ) ) {
F_17 ( & V_13 -> V_17 , L_4 ) ;
V_3 = - V_27 ;
goto V_28;
}
V_2 -> V_7 = F_18 ( V_2 -> V_22 , V_2 -> V_24 ) ;
if ( V_2 -> V_7 == NULL ) {
F_17 ( & V_13 -> V_17 , L_5 ) ;
V_3 = - V_29 ;
goto V_30;
}
V_3 = F_19 ( V_2 , V_16 , V_31 ) ;
if ( V_3 != 0 )
goto V_32;
return V_3 ;
V_32:
F_20 ( V_2 -> V_7 ) ;
V_30:
F_21 ( V_2 -> V_22 , V_2 -> V_24 ) ;
V_28:
F_22 ( V_2 ) ;
V_21:
F_12 ( & V_13 -> V_17 , L_6 , F_13 ( & V_13 -> V_17 ) ,
V_3 ) ;
return V_3 ;
}
static int F_23 ( struct V_12 * V_13 )
{
if ( F_24 () )
return - V_18 ;
return F_10 ( & V_33 , V_13 ) ;
}
static int F_25 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = F_26 ( V_13 ) ;
F_27 ( V_2 ) ;
F_20 ( V_2 -> V_7 ) ;
F_21 ( V_2 -> V_22 , V_2 -> V_24 ) ;
F_22 ( V_2 ) ;
return 0 ;
}
