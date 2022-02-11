static void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 -> V_3 ) ;
}
static void F_3 ( struct V_1 * V_2 )
{
F_4 ( V_2 -> V_3 ) ;
}
static int F_5 ( struct V_1 * V_2 )
{
int V_4 ;
F_1 ( V_2 ) ;
if ( V_2 -> V_5 -> V_6 ) {
V_4 = V_2 -> V_5 -> V_6 ( V_2 -> V_7 ) ;
if ( V_4 )
return V_4 ;
}
return 0 ;
}
static void F_6 ( struct V_1 * V_2 )
{
if ( V_2 -> V_5 -> V_8 )
V_2 -> V_5 -> V_8 ( V_2 -> V_7 ) ;
F_3 ( V_2 ) ;
}
static int F_7 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_13 . V_14 ;
struct V_1 * V_2 = F_8 ( V_12 ) ;
int V_4 ;
if ( V_2 == NULL ) {
F_9 ( V_12 , L_1 ) ;
return - V_15 ;
}
V_10 -> V_16 = 1 ;
V_4 = F_10 ( V_10 ) ;
if ( V_4 )
F_9 ( V_12 , L_2 , V_4 ) ;
return V_4 ;
}
static int F_11 ( struct V_17 * V_18 )
{
struct V_19 * V_5 = F_12 ( & V_18 -> V_12 ) ;
struct V_9 * V_10 ;
struct V_20 * V_21 ;
struct V_1 * V_2 ;
struct V_22 * V_23 ;
int V_4 = - V_15 ;
T_1 V_24 ;
if ( ! V_5 ) {
F_9 ( & V_18 -> V_12 , L_3 ) ;
return - V_15 ;
}
if ( F_13 () )
return - V_15 ;
V_10 = F_14 ( & V_25 , & V_18 -> V_12 , L_4 ) ;
if ( ! V_10 )
return - V_26 ;
V_2 = F_15 ( & V_18 -> V_12 , sizeof( * V_2 ) , V_27 ) ;
if ( V_2 == NULL ) {
F_9 ( & V_18 -> V_12 , L_5 ) ;
V_4 = - V_26 ;
goto V_28;
}
F_16 ( V_18 , V_2 ) ;
V_2 -> V_5 = V_5 ;
V_2 -> V_10 = V_10 ;
V_2 -> V_3 = F_17 ( & V_18 -> V_12 , NULL ) ;
if ( F_18 ( V_2 -> V_3 ) ) {
F_9 ( & V_18 -> V_12 , L_6 ) ;
V_4 = F_19 ( V_2 -> V_3 ) ;
goto V_28;
}
V_23 = F_20 ( V_18 , V_29 , L_7 ) ;
if ( V_23 == NULL ) {
F_9 ( & V_18 -> V_12 , L_8 ) ;
V_4 = - V_15 ;
goto V_28;
}
V_2 -> V_7 = F_21 ( & V_18 -> V_12 , V_23 -> V_30 ,
F_22 ( V_23 ) ) ;
if ( ! V_2 -> V_7 ) {
F_9 ( & V_18 -> V_12 , L_9 ) ;
V_4 = - V_31 ;
goto V_28;
}
V_23 = F_20 ( V_18 , V_29 , L_10 ) ;
if ( ! V_23 ) {
F_9 ( & V_18 -> V_12 , L_11 ) ;
V_4 = - V_15 ;
goto V_28;
}
V_2 -> V_32 = F_21 ( & V_18 -> V_12 , V_23 -> V_30 ,
F_22 ( V_23 ) ) ;
if ( V_2 -> V_32 == NULL ) {
F_9 ( & V_18 -> V_12 , L_12 ) ;
V_4 = - V_31 ;
goto V_28;
}
V_4 = F_5 ( V_2 ) ;
if ( V_4 ) {
F_9 ( & V_18 -> V_12 , L_13 , V_4 ) ;
goto V_28;
}
V_24 = F_23 ( V_2 -> V_32 ) & V_33 ;
V_2 -> V_34 =
( void V_35 * ) ( ( unsigned long ) V_2 -> V_32 + V_24 ) ;
V_10 -> V_36 = V_23 -> V_30 ;
V_10 -> V_37 = F_22 ( V_23 ) ;
V_10 -> V_38 = V_2 -> V_34 ;
V_10 -> V_39 = F_24 ( V_18 , 0 ) ;
if ( ! V_10 -> V_39 ) {
F_9 ( & V_18 -> V_12 , L_14 ) ;
V_4 = - V_15 ;
goto V_40;
}
V_21 = F_25 ( V_10 ) ;
V_21 -> V_41 = (struct V_42 * ) V_2 -> V_32 ;
V_2 -> V_43 = V_5 -> V_43 ;
if ( V_2 -> V_43 == V_44 ) {
V_2 -> V_45 = F_26 ( & V_18 -> V_12 , V_46 ) ;
if ( F_18 ( V_2 -> V_45 ) ) {
V_4 = F_19 ( V_2 -> V_45 ) ;
if ( V_4 == - V_47 )
F_27 ( & V_18 -> V_12 , L_15
L_16 ) ;
else
F_9 ( & V_18 -> V_12 ,
L_17 ) ;
goto V_40;
}
V_4 = F_28 ( V_2 -> V_45 -> V_45 , & V_10 -> V_13 ) ;
if ( V_4 < 0 ) {
F_9 ( & V_18 -> V_12 ,
L_18 ) ;
V_4 = - V_15 ;
goto V_40;
}
F_6 ( V_2 ) ;
} else {
if ( V_5 -> V_48 )
V_5 -> V_48 ( 1 ) ;
V_4 = F_29 ( V_10 , V_10 -> V_39 , V_49 ) ;
if ( V_4 ) {
F_9 ( & V_18 -> V_12 ,
L_19 , V_4 ) ;
goto V_50;
}
F_30 ( V_10 -> V_13 . V_14 ) ;
}
if ( V_5 -> V_51 )
V_5 -> V_51 ( V_2 -> V_34 , V_2 -> V_7 ) ;
F_27 ( & V_18 -> V_12 ,
L_20
L_21 , V_10 -> V_38 , V_10 -> V_39 ,
V_2 -> V_43 == V_44 ? L_22 : L_23 ) ;
return 0 ;
V_50:
if ( V_5 -> V_48 )
V_5 -> V_48 ( 0 ) ;
V_40:
F_6 ( V_2 ) ;
V_28:
F_31 ( V_10 ) ;
return V_4 ;
}
static int F_32 ( struct V_17 * V_18 )
{
struct V_1 * V_2 = F_33 ( V_18 ) ;
struct V_9 * V_10 = V_2 -> V_10 ;
if ( V_10 -> V_52 )
F_34 ( V_10 ) ;
if ( ! F_35 ( V_2 -> V_45 ) )
F_28 ( V_2 -> V_45 -> V_45 , NULL ) ;
if ( V_2 -> V_43 == V_53 ) {
if ( V_2 -> V_5 -> V_48 )
V_2 -> V_5 -> V_48 ( 0 ) ;
F_6 ( V_2 ) ;
}
F_31 ( V_10 ) ;
return 0 ;
}
static void F_36 ( struct V_17 * V_18 )
{
struct V_1 * V_2 = F_33 ( V_18 ) ;
struct V_9 * V_10 = V_2 -> V_10 ;
if ( ! V_10 -> V_52 )
return;
if ( V_10 -> V_54 -> V_55 )
V_10 -> V_54 -> V_55 ( V_10 ) ;
}
