static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
V_4 -> V_5 = V_2 -> V_6 ;
return F_3 ( V_2 ) ;
}
int F_4 ( const struct V_7 * V_8 ,
struct V_9 * V_10 )
{
struct V_1 * V_2 ;
struct V_11 * V_12 ;
int V_13 , V_14 ;
V_14 = F_5 ( V_10 , 0 ) ;
if ( V_14 < 0 ) {
F_6 ( & V_10 -> V_15 , L_1 ,
F_7 ( & V_10 -> V_15 ) ) ;
return - V_16 ;
}
V_12 = F_8 ( V_10 , V_17 , 0 ) ;
if ( ! V_12 ) {
F_6 ( & V_10 -> V_15 , L_2 ,
F_7 ( & V_10 -> V_15 ) ) ;
return - V_16 ;
}
V_2 = F_9 ( V_8 , & V_10 -> V_15 , F_7 ( & V_10 -> V_15 ) ) ;
if ( ! V_2 ) {
V_13 = - V_18 ;
goto V_19;
}
V_2 -> V_20 = V_12 -> V_21 ;
V_2 -> V_22 = F_10 ( V_12 ) ;
if ( ! F_11 ( V_2 -> V_20 , V_2 -> V_22 ,
V_8 -> V_23 ) ) {
F_12 ( & V_10 -> V_15 , L_3 ) ;
V_13 = - V_24 ;
goto V_25;
}
V_2 -> V_6 = F_13 ( V_2 -> V_20 , V_2 -> V_22 ) ;
if ( V_2 -> V_6 == NULL ) {
F_12 ( & V_10 -> V_15 , L_4 ) ;
V_13 = - V_26 ;
goto V_27;
}
V_13 = F_14 ( V_2 , V_14 , V_28 ) ;
if ( V_13 != 0 )
goto V_29;
return V_13 ;
V_29:
F_15 ( V_2 -> V_6 ) ;
V_27:
F_16 ( V_2 -> V_20 , V_2 -> V_22 ) ;
V_25:
F_17 ( V_2 ) ;
V_19:
F_6 ( & V_10 -> V_15 , L_5 , F_7 ( & V_10 -> V_15 ) ,
V_13 ) ;
return V_13 ;
}
static int F_18 ( struct V_9 * V_10 )
{
if ( F_19 () )
return - V_16 ;
return F_4 ( & V_30 , V_10 ) ;
}
static int F_20 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = F_21 ( V_10 ) ;
F_22 ( V_2 ) ;
F_15 ( V_2 -> V_6 ) ;
F_16 ( V_2 -> V_20 , V_2 -> V_22 ) ;
F_17 ( V_2 ) ;
return 0 ;
}
