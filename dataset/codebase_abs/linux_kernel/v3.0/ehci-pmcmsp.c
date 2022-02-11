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
#ifdef F_5
F_4 ( V_17 , 1 ) ;
#endif
}
static int F_6 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = F_7 ( V_19 ) ;
int V_20 ;
V_2 -> V_21 = 1 ;
V_2 -> V_22 = 1 ;
V_2 -> V_23 = V_19 -> V_9 ;
V_2 -> V_9 = V_19 -> V_9 +
F_8 ( V_2 , F_2 ( V_2 , & V_2 -> V_23 -> V_24 ) ) ;
F_9 ( V_2 , L_1 ) ;
F_10 ( V_2 , L_1 ) ;
V_2 -> V_25 = F_2 ( V_2 , & V_2 -> V_23 -> V_25 ) ;
V_19 -> V_26 = 1 ;
V_20 = F_11 ( V_2 ) ;
if ( V_20 )
return V_20 ;
F_12 ( V_2 ) ;
V_20 = F_13 ( V_19 ) ;
if ( V_20 )
return V_20 ;
F_1 ( V_2 ) ;
F_14 ( V_2 , 0 ) ;
return V_20 ;
}
static int F_15 ( struct V_27 * V_28 )
{
struct V_29 * V_30 ;
struct V_31 * V_32 = & V_28 -> V_28 ;
T_2 V_33 ;
int V_20 ;
V_30 = F_16 ( V_32 , V_34 , 1 ) ;
if ( V_30 == NULL )
return - V_35 ;
V_33 = V_30 -> V_36 - V_30 -> V_37 + 1 ;
if ( ! F_17 ( V_30 -> V_37 , V_33 , L_2 ) )
return - V_38 ;
V_28 -> V_39 = F_18 ( V_30 -> V_37 , V_33 ) ;
if ( V_28 -> V_39 == NULL ) {
V_20 = - V_35 ;
goto V_40;
}
V_30 = F_16 ( V_32 , V_34 , 2 ) ;
if ( V_30 == NULL ) {
V_20 = - V_35 ;
goto V_41;
}
V_33 = V_30 -> V_36 - V_30 -> V_37 + 1 ;
if ( ! F_17 ( V_30 -> V_37 , V_33 , L_3 ) ) {
V_20 = - V_38 ;
goto V_41;
}
V_28 -> V_42 = F_18 ( V_30 -> V_37 , V_33 ) ;
if ( V_28 -> V_42 == NULL ) {
V_20 = - V_35 ;
goto V_43;
}
return 0 ;
V_43:
V_30 = F_16 ( V_32 , V_34 , 2 ) ;
V_33 = V_30 -> V_36 - V_30 -> V_37 + 1 ;
F_19 ( V_30 -> V_37 , V_33 ) ;
V_41:
F_20 ( V_28 -> V_39 ) ;
V_40:
V_30 = F_16 ( V_32 , V_34 , 1 ) ;
V_33 = V_30 -> V_36 - V_30 -> V_37 + 1 ;
F_19 ( V_30 -> V_37 , V_33 ) ;
F_21 ( & V_32 -> V_28 , L_4 ) ;
return V_20 ;
}
int F_22 ( const struct V_44 * V_45 ,
struct V_31 * V_28 )
{
int V_20 ;
struct V_18 * V_19 ;
struct V_29 * V_30 ;
struct V_1 * V_2 ;
V_19 = F_23 ( V_45 , & V_28 -> V_28 , L_5 ) ;
if ( ! V_19 )
return - V_35 ;
V_30 = F_16 ( V_28 , V_34 , 0 ) ;
if ( V_30 == NULL ) {
F_24 ( L_6 , V_28 -> V_46 ) ;
V_20 = - V_35 ;
goto V_40;
}
V_19 -> V_47 = V_30 -> V_37 ;
V_19 -> V_48 = V_30 -> V_36 - V_30 -> V_37 + 1 ;
if ( ! F_17 ( V_19 -> V_47 , V_19 -> V_48 , V_28 -> V_46 ) ) {
V_20 = - V_38 ;
goto V_40;
}
V_19 -> V_9 = F_18 ( V_19 -> V_47 , V_19 -> V_48 ) ;
if ( ! V_19 -> V_9 ) {
F_24 ( L_7 ) ;
V_20 = - V_35 ;
goto V_41;
}
V_30 = F_16 ( V_28 , V_49 , 0 ) ;
if ( V_30 == NULL ) {
F_21 ( & V_28 -> V_28 , L_8 , V_28 -> V_46 ) ;
V_20 = - V_35 ;
goto V_43;
}
V_20 = F_15 ( F_25 ( V_28 ) ) ;
if ( V_20 != 0 )
goto V_43;
V_2 = F_7 ( V_19 ) ;
V_2 -> V_21 = 1 ;
V_2 -> V_22 = 1 ;
V_20 = F_26 ( V_19 , V_30 -> V_37 , V_50 ) ;
if ( V_20 == 0 )
return 0 ;
F_27 ( V_19 ) ;
V_43:
F_20 ( V_19 -> V_9 ) ;
V_41:
F_19 ( V_19 -> V_47 , V_19 -> V_48 ) ;
V_40:
F_28 ( V_19 ) ;
return V_20 ;
}
void F_29 ( struct V_18 * V_19 , struct V_31 * V_28 )
{
F_27 ( V_19 ) ;
F_20 ( V_19 -> V_9 ) ;
F_19 ( V_19 -> V_47 , V_19 -> V_48 ) ;
F_28 ( V_19 ) ;
}
static T_3 F_30 ( struct V_18 * V_19 )
{
T_2 V_51 ;
struct V_52 * V_28 = V_19 -> V_53 . V_54 ;
struct V_31 * V_32 ;
struct V_27 * V_55 ;
struct V_1 * V_2 = F_7 ( V_19 ) ;
V_32 = F_31 ( V_28 ) ;
V_55 = F_25 ( V_32 ) ;
V_51 = F_2 ( V_2 , & V_55 -> V_39 -> V_56 ) ;
if ( V_51 & ( 1 << V_32 -> V_57 ) )
return F_32 ( V_19 ) ;
return V_58 ;
}
static int F_33 ( struct V_31 * V_32 )
{
int V_59 ;
F_24 ( L_9 ) ;
if ( F_34 () )
return - V_60 ;
F_35 ( V_16 , L_10 ) ;
#ifdef F_5
F_35 ( V_17 , L_11 ) ;
#endif
V_59 = F_22 ( & V_61 , V_32 ) ;
return V_59 ;
}
static int F_36 ( struct V_31 * V_32 )
{
struct V_18 * V_19 = F_37 ( V_32 ) ;
F_29 ( V_19 , V_32 ) ;
F_38 ( V_16 ) ;
#ifdef F_5
F_38 ( V_17 ) ;
#endif
return 0 ;
}
