static int
F_1 ( struct V_1 * V_2 , const struct V_3 * V_4 )
{
struct V_5 * V_6 ;
T_1 V_7 ;
T_2 V_8 ;
T_3 * V_9 ;
int V_10 ;
if ( F_2 ( V_2 ) ) {
F_3 ( V_11 L_1 , V_12 ) ;
return - V_13 ;
}
F_4 ( V_2 , V_14 , & V_7 ) ;
#if V_15 > V_16
F_5 ( V_17 , L_2 , V_7 ) ;
#endif
if ( V_7 < V_18 ) {
F_6 ( V_2 , V_14 ,
V_19 ) ;
}
if ( F_7 ( V_2 , F_8 ( 32 ) ) ) {
F_3 ( V_11 L_3 , V_12 ) ;
goto V_20;
}
if ( V_21 >= 0 ) {
F_6 ( V_2 , 0x40 , ( T_1 ) V_21 ) ;
F_6 ( V_2 , 0x41 , ( T_1 ) V_21 ) ;
} else {
F_3 ( V_22 L_4 ) ;
}
V_10 = F_9 ( V_2 , V_12 ) ;
if ( V_10 ) {
F_3 ( V_11 L_5 ,
V_12 , V_10 ) ;
goto V_20;
}
V_10 = F_10 ( V_2 , V_23 , & V_8 ) ;
if ( V_10 || ! V_8 ) {
F_3 ( V_11 L_6 ,
V_12 ) ;
goto V_24;
}
F_5 ( V_17 , L_7 , V_12 ) ;
F_11 ( V_2 ) ;
F_12 ( V_2 ) ;
if ( ! ( V_6 = F_13 ( V_2 ) ) ) {
F_3 ( V_11 L_8 ,
V_12 ) ;
goto V_25;
}
V_9 = F_14 ( V_6 ) ;
F_15 ( V_9 , V_26 ) ;
F_16 ( V_9 -> V_27 ) ;
V_10 = F_17 ( V_2 -> V_28 , V_29 ,
V_30 , V_6 -> V_31 , V_9 ) ;
if ( V_10 ) {
F_3 ( V_11 L_9 ,
V_6 -> V_31 ) ;
goto V_32;
}
return 0 ;
V_32:
F_18 ( V_6 ) ;
F_19 ( V_9 ) ;
F_20 ( V_2 , NULL ) ;
F_21 ( V_6 ) ;
V_9 = NULL ;
V_25:
F_22 ( V_2 ) ;
V_24:
F_23 ( V_2 ) ;
V_20:
F_24 ( V_2 ) ;
return - V_33 ;
}
static void
F_25 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_26 ( V_2 ) ;
T_3 * V_9 = V_6 ? F_14 ( V_6 ) : NULL ;
F_27 ( ! V_9 ) ;
if ( ! V_34 ) {
F_3 ( V_35 L_10 , V_6 -> V_31 ) ;
F_15 ( V_9 , V_36 ) ;
}
F_3 ( V_35 L_11 , V_6 -> V_31 ) ;
F_18 ( V_6 ) ;
if ( F_28 ( V_9 ) != V_36 ) {
F_16 ( V_9 -> V_27 ) ;
F_15 ( V_9 , V_36 ) ;
}
F_29 ( V_2 -> V_28 , V_9 ) ;
F_19 ( V_9 ) ;
F_20 ( V_2 , NULL ) ;
F_21 ( V_6 ) ;
V_9 = NULL ;
F_22 ( V_2 ) ;
F_23 ( V_2 ) ;
F_24 ( V_2 ) ;
}
static int
F_30 ( struct V_1 * V_2 , T_4 V_37 )
{
struct V_5 * V_6 = F_26 ( V_2 ) ;
T_3 * V_9 = V_6 ? F_14 ( V_6 ) : NULL ;
F_27 ( ! V_9 ) ;
F_31 ( V_2 ) ;
F_16 ( V_9 -> V_27 ) ;
F_15 ( V_9 , V_36 ) ;
F_32 ( V_6 ) ;
F_33 ( V_6 ) ;
return 0 ;
}
static int
F_34 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_26 ( V_2 ) ;
T_3 * V_9 = V_6 ? F_14 ( V_6 ) : NULL ;
int V_38 ;
F_27 ( ! V_9 ) ;
F_3 ( V_39 L_12 , V_6 -> V_31 ) ;
V_38 = F_2 ( V_2 ) ;
if ( V_38 ) {
F_3 ( V_11 L_13 ,
V_6 -> V_31 ) ;
return V_38 ;
}
F_35 ( V_2 ) ;
F_36 ( V_9 , 1 ) ;
F_37 ( V_6 ) ;
F_38 ( V_6 ) ;
return 0 ;
}
static int T_5
F_39 ( void )
{
F_3 ( V_22 L_14 ,
V_12 , V_40 ) ;
F_40 () ;
return F_41 ( & V_41 ) ;
}
static void T_6
F_42 ( void )
{
V_34 = 1 ;
F_43 ( & V_41 ) ;
F_3 ( V_22 L_15 , V_12 ) ;
V_34 = 0 ;
}
