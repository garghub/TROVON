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
V_19 -> V_24 = 1 ;
V_20 = F_8 ( V_19 ) ;
if ( V_20 )
return V_20 ;
F_1 ( V_2 ) ;
F_9 ( V_2 , 0 ) ;
return V_20 ;
}
static int F_10 ( struct V_25 * V_26 )
{
struct V_27 * V_28 ;
struct V_29 * V_30 = & V_26 -> V_26 ;
T_2 V_31 ;
int V_20 ;
V_28 = F_11 ( V_30 , V_32 , 1 ) ;
if ( V_28 == NULL )
return - V_33 ;
V_31 = F_12 ( V_28 ) ;
if ( ! F_13 ( V_28 -> V_34 , V_31 , L_1 ) )
return - V_35 ;
V_26 -> V_36 = F_14 ( V_28 -> V_34 , V_31 ) ;
if ( V_26 -> V_36 == NULL ) {
V_20 = - V_33 ;
goto V_37;
}
V_28 = F_11 ( V_30 , V_32 , 2 ) ;
if ( V_28 == NULL ) {
V_20 = - V_33 ;
goto V_38;
}
V_31 = F_12 ( V_28 ) ;
if ( ! F_13 ( V_28 -> V_34 , V_31 , L_2 ) ) {
V_20 = - V_35 ;
goto V_38;
}
V_26 -> V_39 = F_14 ( V_28 -> V_34 , V_31 ) ;
if ( V_26 -> V_39 == NULL ) {
V_20 = - V_33 ;
goto V_40;
}
return 0 ;
V_40:
V_28 = F_11 ( V_30 , V_32 , 2 ) ;
V_31 = F_12 ( V_28 ) ;
F_15 ( V_28 -> V_34 , V_31 ) ;
V_38:
F_16 ( V_26 -> V_36 ) ;
V_37:
V_28 = F_11 ( V_30 , V_32 , 1 ) ;
V_31 = F_12 ( V_28 ) ;
F_15 ( V_28 -> V_34 , V_31 ) ;
F_17 ( & V_30 -> V_26 , L_3 ) ;
return V_20 ;
}
int F_18 ( const struct V_41 * V_42 ,
struct V_29 * V_26 )
{
int V_20 ;
struct V_18 * V_19 ;
struct V_27 * V_28 ;
struct V_1 * V_2 ;
V_19 = F_19 ( V_42 , & V_26 -> V_26 , L_4 ) ;
if ( ! V_19 )
return - V_33 ;
V_28 = F_11 ( V_26 , V_32 , 0 ) ;
if ( V_28 == NULL ) {
F_20 ( L_5 , V_26 -> V_43 ) ;
V_20 = - V_33 ;
goto V_37;
}
V_19 -> V_44 = V_28 -> V_34 ;
V_19 -> V_45 = F_12 ( V_28 ) ;
if ( ! F_13 ( V_19 -> V_44 , V_19 -> V_45 , V_26 -> V_43 ) ) {
V_20 = - V_35 ;
goto V_37;
}
V_19 -> V_9 = F_14 ( V_19 -> V_44 , V_19 -> V_45 ) ;
if ( ! V_19 -> V_9 ) {
F_20 ( L_6 ) ;
V_20 = - V_33 ;
goto V_38;
}
V_28 = F_11 ( V_26 , V_46 , 0 ) ;
if ( V_28 == NULL ) {
F_17 ( & V_26 -> V_26 , L_7 , V_26 -> V_43 ) ;
V_20 = - V_33 ;
goto V_40;
}
V_20 = F_10 ( F_21 ( V_26 ) ) ;
if ( V_20 != 0 )
goto V_40;
V_2 = F_7 ( V_19 ) ;
V_2 -> V_21 = 1 ;
V_2 -> V_22 = 1 ;
V_20 = F_22 ( V_19 , V_28 -> V_34 , V_47 ) ;
if ( V_20 == 0 )
return 0 ;
F_23 ( V_19 ) ;
V_40:
F_16 ( V_19 -> V_9 ) ;
V_38:
F_15 ( V_19 -> V_44 , V_19 -> V_45 ) ;
V_37:
F_24 ( V_19 ) ;
return V_20 ;
}
void F_25 ( struct V_18 * V_19 , struct V_29 * V_26 )
{
F_23 ( V_19 ) ;
F_16 ( V_19 -> V_9 ) ;
F_15 ( V_19 -> V_44 , V_19 -> V_45 ) ;
F_24 ( V_19 ) ;
}
static T_3 F_26 ( struct V_18 * V_19 )
{
T_2 V_48 ;
struct V_49 * V_26 = V_19 -> V_50 . V_51 ;
struct V_29 * V_30 ;
struct V_25 * V_52 ;
struct V_1 * V_2 = F_7 ( V_19 ) ;
V_30 = F_27 ( V_26 ) ;
V_52 = F_21 ( V_30 ) ;
V_48 = F_2 ( V_2 , & V_52 -> V_36 -> V_53 ) ;
if ( V_48 & ( 1 << V_30 -> V_54 ) )
return F_28 ( V_19 ) ;
return V_55 ;
}
static int F_29 ( struct V_29 * V_30 )
{
int V_56 ;
F_20 ( L_8 ) ;
if ( F_30 () )
return - V_57 ;
F_31 ( V_16 , L_9 ) ;
#ifdef F_5
F_31 ( V_17 , L_10 ) ;
#endif
V_56 = F_18 ( & V_58 , V_30 ) ;
return V_56 ;
}
static int F_32 ( struct V_29 * V_30 )
{
struct V_18 * V_19 = F_33 ( V_30 ) ;
F_25 ( V_19 , V_30 ) ;
F_34 ( V_16 ) ;
#ifdef F_5
F_34 ( V_17 ) ;
#endif
return 0 ;
}
