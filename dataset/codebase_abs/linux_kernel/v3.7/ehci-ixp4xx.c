static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_5 = 0 ;
V_4 -> V_6 = 1 ;
V_4 -> V_7 = 1 ;
V_4 -> V_8 = V_2 -> V_9 + 0x100 ;
V_2 -> V_10 = 1 ;
V_5 = F_3 ( V_2 ) ;
if ( V_5 )
return V_5 ;
F_4 ( V_4 , 0 ) ;
return V_5 ;
}
static int F_5 ( struct V_11 * V_12 )
{
struct V_1 * V_2 ;
const struct V_13 * V_14 = & V_15 ;
struct V_16 * V_17 ;
int V_18 ;
int V_5 ;
if ( F_6 () )
return - V_19 ;
V_17 = F_7 ( V_12 , V_20 , 0 ) ;
if ( ! V_17 ) {
F_8 ( & V_12 -> V_21 ,
L_1 ,
F_9 ( & V_12 -> V_21 ) ) ;
return - V_19 ;
}
V_18 = V_17 -> V_22 ;
V_2 = F_10 ( V_14 , & V_12 -> V_21 , F_9 ( & V_12 -> V_21 ) ) ;
if ( ! V_2 ) {
V_5 = - V_23 ;
goto V_24;
}
V_17 = F_7 ( V_12 , V_25 , 0 ) ;
if ( ! V_17 ) {
F_8 ( & V_12 -> V_21 ,
L_2 ,
F_9 ( & V_12 -> V_21 ) ) ;
V_5 = - V_19 ;
goto V_26;
}
V_2 -> V_27 = V_17 -> V_22 ;
V_2 -> V_28 = F_11 ( V_17 ) ;
V_2 -> V_9 = F_12 ( & V_12 -> V_21 , V_17 ) ;
if ( V_2 -> V_9 == NULL ) {
F_13 ( & V_12 -> V_21 , L_3 ) ;
V_5 = - V_29 ;
goto V_26;
}
V_5 = F_14 ( V_2 , V_18 , V_30 ) ;
if ( V_5 )
goto V_26;
return V_5 ;
V_26:
F_15 ( V_2 ) ;
V_24:
F_8 ( & V_12 -> V_21 , L_4 , F_9 ( & V_12 -> V_21 ) , V_5 ) ;
return V_5 ;
}
static int F_16 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = F_17 ( V_12 ) ;
F_18 ( V_2 ) ;
F_15 ( V_2 ) ;
return 0 ;
}
