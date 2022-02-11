static void F_1 ( struct V_1 * V_2 )
{
T_1 * V_3 ;
T_1 * V_4 ;
T_1 * V_5 ;
T_2 V_6 ;
struct V_7 * V_8 = V_2 -> V_9 ;
V_3 = ( T_1 * ) V_8 + V_10 ;
V_4 = ( T_1 * ) V_8 + V_11 ;
V_5 = ( T_1 * ) V_8 + V_12 ;
V_6 = F_2 ( V_2 , ( T_2 * ) V_3 ) ;
F_3 ( V_2 , ( V_6 | V_13 ) ,
( T_2 * ) V_3 ) ;
V_6 = F_2 ( V_2 , ( T_2 * ) V_4 ) ;
V_6 = V_6 & ~ V_14 ;
F_3 ( V_2 , V_6 , ( T_2 * ) V_4 ) ;
F_3 ( V_2 , V_15 , ( T_2 * ) V_5 ) ;
F_4 ( V_16 , 1 ) ;
}
static int F_5 ( struct V_17 * V_18 )
{
struct V_1 * V_2 = F_6 ( V_18 ) ;
int V_19 ;
V_2 -> V_20 = 1 ;
V_2 -> V_21 = 1 ;
V_2 -> V_22 = V_18 -> V_9 ;
V_18 -> V_23 = 1 ;
V_19 = F_7 ( V_18 ) ;
if ( V_19 )
return V_19 ;
F_1 ( V_2 ) ;
return V_19 ;
}
static int F_8 ( struct V_24 * V_25 )
{
struct V_26 * V_27 ;
struct V_28 * V_29 = & V_25 -> V_25 ;
T_2 V_30 ;
int V_19 ;
V_27 = F_9 ( V_29 , V_31 , 1 ) ;
if ( V_27 == NULL )
return - V_32 ;
V_30 = F_10 ( V_27 ) ;
if ( ! F_11 ( V_27 -> V_33 , V_30 , L_1 ) )
return - V_34 ;
V_25 -> V_35 = F_12 ( V_27 -> V_33 , V_30 ) ;
if ( V_25 -> V_35 == NULL ) {
V_19 = - V_32 ;
goto V_36;
}
V_27 = F_9 ( V_29 , V_31 , 2 ) ;
if ( V_27 == NULL ) {
V_19 = - V_32 ;
goto V_37;
}
V_30 = F_10 ( V_27 ) ;
if ( ! F_11 ( V_27 -> V_33 , V_30 , L_2 ) ) {
V_19 = - V_34 ;
goto V_37;
}
V_25 -> V_38 = F_12 ( V_27 -> V_33 , V_30 ) ;
if ( V_25 -> V_38 == NULL ) {
V_19 = - V_32 ;
goto V_39;
}
return 0 ;
V_39:
V_27 = F_9 ( V_29 , V_31 , 2 ) ;
V_30 = F_10 ( V_27 ) ;
F_13 ( V_27 -> V_33 , V_30 ) ;
V_37:
F_14 ( V_25 -> V_35 ) ;
V_36:
V_27 = F_9 ( V_29 , V_31 , 1 ) ;
V_30 = F_10 ( V_27 ) ;
F_13 ( V_27 -> V_33 , V_30 ) ;
F_15 ( & V_29 -> V_25 , L_3 ) ;
return V_19 ;
}
int F_16 ( const struct V_40 * V_41 ,
struct V_28 * V_25 )
{
int V_19 ;
struct V_17 * V_18 ;
struct V_26 * V_27 ;
struct V_1 * V_2 ;
V_18 = F_17 ( V_41 , & V_25 -> V_25 , L_4 ) ;
if ( ! V_18 )
return - V_32 ;
V_27 = F_9 ( V_25 , V_31 , 0 ) ;
if ( V_27 == NULL ) {
F_18 ( L_5 , V_25 -> V_42 ) ;
V_19 = - V_32 ;
goto V_36;
}
V_18 -> V_43 = V_27 -> V_33 ;
V_18 -> V_44 = F_10 ( V_27 ) ;
if ( ! F_11 ( V_18 -> V_43 , V_18 -> V_44 , V_25 -> V_42 ) ) {
V_19 = - V_34 ;
goto V_36;
}
V_18 -> V_9 = F_12 ( V_18 -> V_43 , V_18 -> V_44 ) ;
if ( ! V_18 -> V_9 ) {
F_18 ( L_6 ) ;
V_19 = - V_32 ;
goto V_37;
}
V_27 = F_9 ( V_25 , V_45 , 0 ) ;
if ( V_27 == NULL ) {
F_15 ( & V_25 -> V_25 , L_7 , V_25 -> V_42 ) ;
V_19 = - V_32 ;
goto V_39;
}
V_19 = F_8 ( F_19 ( V_25 ) ) ;
if ( V_19 != 0 )
goto V_39;
V_2 = F_6 ( V_18 ) ;
V_2 -> V_20 = 1 ;
V_2 -> V_21 = 1 ;
V_19 = F_20 ( V_18 , V_27 -> V_33 , V_46 ) ;
if ( V_19 == 0 ) {
F_21 ( V_18 -> V_47 . V_48 ) ;
return 0 ;
}
F_22 ( V_18 ) ;
V_39:
F_14 ( V_18 -> V_9 ) ;
V_37:
F_13 ( V_18 -> V_43 , V_18 -> V_44 ) ;
V_36:
F_23 ( V_18 ) ;
return V_19 ;
}
void F_24 ( struct V_17 * V_18 , struct V_28 * V_25 )
{
F_22 ( V_18 ) ;
F_14 ( V_18 -> V_9 ) ;
F_13 ( V_18 -> V_43 , V_18 -> V_44 ) ;
F_23 ( V_18 ) ;
}
static int F_25 ( struct V_28 * V_29 )
{
int V_49 ;
F_18 ( L_8 ) ;
if ( F_26 () )
return - V_50 ;
F_27 ( V_16 , L_9 ) ;
V_49 = F_16 ( & V_51 , V_29 ) ;
return V_49 ;
}
static int F_28 ( struct V_28 * V_29 )
{
struct V_17 * V_18 = F_29 ( V_29 ) ;
F_24 ( V_18 , V_29 ) ;
F_30 ( V_16 ) ;
return 0 ;
}
