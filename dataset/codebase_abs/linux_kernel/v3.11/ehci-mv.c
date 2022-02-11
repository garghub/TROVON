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
struct V_19 * V_5 = V_18 -> V_12 . V_20 ;
struct V_9 * V_10 ;
struct V_21 * V_22 ;
struct V_1 * V_2 ;
struct V_23 * V_24 ;
int V_4 = - V_15 ;
T_1 V_25 ;
if ( ! V_5 ) {
F_9 ( & V_18 -> V_12 , L_3 ) ;
return - V_15 ;
}
if ( F_12 () )
return - V_15 ;
V_10 = F_13 ( & V_26 , & V_18 -> V_12 , L_4 ) ;
if ( ! V_10 )
return - V_27 ;
V_2 = F_14 ( & V_18 -> V_12 , sizeof( * V_2 ) , V_28 ) ;
if ( V_2 == NULL ) {
F_9 ( & V_18 -> V_12 , L_5 ) ;
V_4 = - V_27 ;
goto V_29;
}
F_15 ( V_18 , V_2 ) ;
V_2 -> V_5 = V_5 ;
V_2 -> V_10 = V_10 ;
V_2 -> V_3 = F_16 ( & V_18 -> V_12 , NULL ) ;
if ( F_17 ( V_2 -> V_3 ) ) {
F_9 ( & V_18 -> V_12 , L_6 ) ;
V_4 = F_18 ( V_2 -> V_3 ) ;
goto V_29;
}
V_24 = F_19 ( V_18 , V_30 , L_7 ) ;
if ( V_24 == NULL ) {
F_9 ( & V_18 -> V_12 , L_8 ) ;
V_4 = - V_15 ;
goto V_29;
}
V_2 -> V_7 = F_20 ( & V_18 -> V_12 , V_24 -> V_31 ,
F_21 ( V_24 ) ) ;
if ( V_2 -> V_7 == 0 ) {
F_9 ( & V_18 -> V_12 , L_9 ) ;
V_4 = - V_32 ;
goto V_29;
}
V_24 = F_19 ( V_18 , V_30 , L_10 ) ;
if ( ! V_24 ) {
F_9 ( & V_18 -> V_12 , L_11 ) ;
V_4 = - V_15 ;
goto V_29;
}
V_2 -> V_33 = F_20 ( & V_18 -> V_12 , V_24 -> V_31 ,
F_21 ( V_24 ) ) ;
if ( V_2 -> V_33 == NULL ) {
F_9 ( & V_18 -> V_12 , L_12 ) ;
V_4 = - V_32 ;
goto V_29;
}
V_4 = F_5 ( V_2 ) ;
if ( V_4 ) {
F_9 ( & V_18 -> V_12 , L_13 , V_4 ) ;
goto V_29;
}
V_25 = F_22 ( V_2 -> V_33 ) & V_34 ;
V_2 -> V_35 =
( void V_36 * ) ( ( unsigned long ) V_2 -> V_33 + V_25 ) ;
V_10 -> V_37 = V_24 -> V_31 ;
V_10 -> V_38 = F_21 ( V_24 ) ;
V_10 -> V_39 = V_2 -> V_35 ;
V_10 -> V_40 = F_23 ( V_18 , 0 ) ;
if ( ! V_10 -> V_40 ) {
F_9 ( & V_18 -> V_12 , L_14 ) ;
V_4 = - V_15 ;
goto V_41;
}
V_22 = F_24 ( V_10 ) ;
V_22 -> V_42 = (struct V_43 * ) V_2 -> V_33 ;
V_2 -> V_44 = V_5 -> V_44 ;
if ( V_2 -> V_44 == V_45 ) {
V_2 -> V_46 = F_25 ( & V_18 -> V_12 , V_47 ) ;
if ( F_17 ( V_2 -> V_46 ) ) {
V_4 = F_18 ( V_2 -> V_46 ) ;
if ( V_4 == - V_48 )
F_26 ( & V_18 -> V_12 , L_15
L_16 ) ;
else
F_9 ( & V_18 -> V_12 ,
L_17 ) ;
goto V_41;
}
V_4 = F_27 ( V_2 -> V_46 -> V_46 , & V_10 -> V_13 ) ;
if ( V_4 < 0 ) {
F_9 ( & V_18 -> V_12 ,
L_18 ) ;
V_4 = - V_15 ;
goto V_41;
}
F_6 ( V_2 ) ;
} else {
if ( V_5 -> V_49 )
V_5 -> V_49 ( 1 ) ;
V_4 = F_28 ( V_10 , V_10 -> V_40 , V_50 ) ;
if ( V_4 ) {
F_9 ( & V_18 -> V_12 ,
L_19 , V_4 ) ;
goto V_51;
}
}
if ( V_5 -> V_52 )
V_5 -> V_52 ( V_2 -> V_35 , V_2 -> V_7 ) ;
F_26 ( & V_18 -> V_12 ,
L_20
L_21 , V_10 -> V_39 , V_10 -> V_40 ,
V_2 -> V_44 == V_45 ? L_22 : L_23 ) ;
return 0 ;
V_51:
if ( V_5 -> V_49 )
V_5 -> V_49 ( 0 ) ;
V_41:
F_6 ( V_2 ) ;
V_29:
F_29 ( V_10 ) ;
return V_4 ;
}
static int F_30 ( struct V_17 * V_18 )
{
struct V_1 * V_2 = F_31 ( V_18 ) ;
struct V_9 * V_10 = V_2 -> V_10 ;
if ( V_10 -> V_53 )
F_32 ( V_10 ) ;
if ( ! F_33 ( V_2 -> V_46 ) )
F_27 ( V_2 -> V_46 -> V_46 , NULL ) ;
if ( V_2 -> V_44 == V_54 ) {
if ( V_2 -> V_5 -> V_49 )
V_2 -> V_5 -> V_49 ( 0 ) ;
F_6 ( V_2 ) ;
}
F_29 ( V_10 ) ;
return 0 ;
}
static void F_34 ( struct V_17 * V_18 )
{
struct V_1 * V_2 = F_31 ( V_18 ) ;
struct V_9 * V_10 = V_2 -> V_10 ;
if ( ! V_10 -> V_53 )
return;
if ( V_10 -> V_55 -> V_56 )
V_10 -> V_55 -> V_56 ( V_10 ) ;
}
