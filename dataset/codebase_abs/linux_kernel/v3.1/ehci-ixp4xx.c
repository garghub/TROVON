static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_5 = 0 ;
V_4 -> V_6 = 1 ;
V_4 -> V_7 = 1 ;
V_4 -> V_8 = V_2 -> V_9 + 0x100 ;
V_4 -> V_9 = V_2 -> V_9 + 0x100
+ F_3 ( V_4 , F_4 ( V_4 , & V_4 -> V_8 -> V_10 ) ) ;
V_4 -> V_11 = F_4 ( V_4 , & V_4 -> V_8 -> V_11 ) ;
V_2 -> V_12 = 1 ;
F_5 ( V_4 ) ;
V_5 = F_6 ( V_2 ) ;
if ( V_5 )
return V_5 ;
F_7 ( V_4 , 0 ) ;
return V_5 ;
}
static int F_8 ( struct V_13 * V_14 )
{
struct V_1 * V_2 ;
const struct V_15 * V_16 = & V_17 ;
struct V_18 * V_19 ;
int V_20 ;
int V_5 ;
if ( F_9 () )
return - V_21 ;
V_19 = F_10 ( V_14 , V_22 , 0 ) ;
if ( ! V_19 ) {
F_11 ( & V_14 -> V_23 ,
L_1 ,
F_12 ( & V_14 -> V_23 ) ) ;
return - V_21 ;
}
V_20 = V_19 -> V_24 ;
V_2 = F_13 ( V_16 , & V_14 -> V_23 , F_12 ( & V_14 -> V_23 ) ) ;
if ( ! V_2 ) {
V_5 = - V_25 ;
goto V_26;
}
V_19 = F_10 ( V_14 , V_27 , 0 ) ;
if ( ! V_19 ) {
F_11 ( & V_14 -> V_23 ,
L_2 ,
F_12 ( & V_14 -> V_23 ) ) ;
V_5 = - V_21 ;
goto V_28;
}
V_2 -> V_29 = V_19 -> V_24 ;
V_2 -> V_30 = F_14 ( V_19 ) ;
if ( ! F_15 ( V_2 -> V_29 , V_2 -> V_30 ,
V_16 -> V_31 ) ) {
F_16 ( & V_14 -> V_23 , L_3 ) ;
V_5 = - V_32 ;
goto V_28;
}
V_2 -> V_9 = F_17 ( V_2 -> V_29 , V_2 -> V_30 ) ;
if ( V_2 -> V_9 == NULL ) {
F_16 ( & V_14 -> V_23 , L_4 ) ;
V_5 = - V_33 ;
goto V_34;
}
V_5 = F_18 ( V_2 , V_20 , V_35 ) ;
if ( V_5 )
goto V_36;
return V_5 ;
V_36:
F_19 ( V_2 -> V_9 ) ;
V_34:
F_20 ( V_2 -> V_29 , V_2 -> V_30 ) ;
V_28:
F_21 ( V_2 ) ;
V_26:
F_11 ( & V_14 -> V_23 , L_5 , F_12 ( & V_14 -> V_23 ) , V_5 ) ;
return V_5 ;
}
static int F_22 ( struct V_13 * V_14 )
{
struct V_1 * V_2 = F_23 ( V_14 ) ;
F_24 ( V_2 ) ;
F_19 ( V_2 -> V_9 ) ;
F_20 ( V_2 -> V_29 , V_2 -> V_30 ) ;
F_21 ( V_2 ) ;
return 0 ;
}
