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
V_2 -> V_13 = 0 ;
V_5 = F_9 ( V_2 ) ;
if ( V_5 )
return V_5 ;
F_10 ( V_4 , 0 ) ;
return V_5 ;
}
static int F_11 ( struct V_14 * V_15 )
{
struct V_16 * V_17 = & V_15 -> V_17 ;
struct V_1 * V_2 ;
const struct V_18 * V_19 = & V_20 ;
struct V_21 * V_22 ;
int V_23 ;
int V_5 ;
if ( F_12 () )
return - V_24 ;
V_22 = F_13 ( V_15 , V_25 , 0 ) ;
if ( ! V_22 ) {
F_14 ( V_17 , L_1 ) ;
return - V_24 ;
}
V_23 = V_22 -> V_26 ;
V_2 = F_15 ( V_19 , & V_15 -> V_17 , F_16 ( & V_15 -> V_17 ) ) ;
if ( ! V_2 )
return - V_27 ;
V_22 = F_13 ( V_15 , V_28 , 0 ) ;
if ( ! V_22 ) {
F_14 ( V_17 , L_2 ) ;
V_5 = - V_24 ;
goto V_29;
}
V_2 -> V_30 = V_22 -> V_26 ;
V_2 -> V_31 = F_17 ( V_22 ) ;
V_2 -> V_12 = F_18 ( & V_15 -> V_17 , V_22 ) ;
if ( V_2 -> V_12 == NULL ) {
F_19 ( V_17 , L_3 ) ;
V_5 = - V_32 ;
goto V_29;
}
V_5 = F_20 ( V_2 , V_23 , V_33 ) ;
if ( V_5 == 0 )
return V_5 ;
V_29:
F_21 ( V_2 ) ;
return V_5 ;
}
static int F_22 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = F_23 ( V_15 ) ;
F_24 ( V_2 ) ;
if ( F_25 ( & V_6 ) == 0 )
F_26 ( 1 << V_8 ) ;
F_21 ( V_2 ) ;
F_27 ( V_15 , NULL ) ;
return 0 ;
}
