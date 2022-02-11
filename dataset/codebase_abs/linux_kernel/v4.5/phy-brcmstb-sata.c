static inline void T_1 * F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_2 V_6 = 0 ;
if ( V_4 -> V_7 == V_8 )
V_6 = V_9 ;
else if ( V_4 -> V_7 == V_10 )
V_6 = V_11 ;
else
F_2 ( V_4 -> V_12 , L_1 ) ;
return V_4 -> V_13 + ( V_2 -> V_14 * V_6 ) ;
}
static void F_3 ( void T_1 * V_15 , T_2 V_16 , T_2 V_17 ,
T_2 V_18 , T_2 V_19 )
{
T_2 V_20 ;
F_4 ( V_16 , V_15 + V_21 ) ;
V_20 = F_5 ( V_15 + F_6 ( V_17 ) ) ;
V_20 = ( V_20 & V_18 ) | V_19 ;
F_4 ( V_20 , V_15 + F_6 ( V_17 ) ) ;
}
static void F_7 ( struct V_1 * V_2 )
{
void T_1 * V_22 = F_1 ( V_2 ) ;
struct V_3 * V_4 = V_2 -> V_5 ;
T_2 V_20 ;
V_20 = V_23 | V_24 ;
F_3 ( V_22 , V_25 , V_26 , ~ V_20 , V_20 ) ;
F_3 ( V_22 , V_25 , V_27 ,
~ V_28 ,
V_29 ) ;
if ( V_2 -> V_30 ) {
F_8 ( V_4 -> V_12 , L_2 , V_2 -> V_14 ) ;
V_20 = V_31 ;
} else {
V_20 = V_32 ;
}
F_3 ( V_22 , V_25 , V_33 ,
~ V_34 , V_20 ) ;
}
static int F_9 ( struct V_35 * V_35 )
{
struct V_1 * V_2 = F_10 ( V_35 ) ;
F_7 ( V_2 ) ;
return 0 ;
}
static int F_11 ( struct V_36 * V_37 )
{
struct V_38 * V_12 = & V_37 -> V_12 ;
struct V_39 * V_40 = V_12 -> V_41 , * V_42 ;
const struct V_43 * V_44 ;
struct V_3 * V_4 ;
struct V_45 * V_46 ;
struct V_47 * V_48 ;
int V_49 , V_50 = 0 ;
if ( F_12 ( V_40 ) == 0 )
return - V_51 ;
V_4 = F_13 ( V_12 , sizeof( * V_4 ) , V_52 ) ;
if ( ! V_4 )
return - V_53 ;
F_14 ( V_12 , V_4 ) ;
V_4 -> V_12 = V_12 ;
V_46 = F_15 ( V_37 , V_54 , L_3 ) ;
V_4 -> V_13 = F_16 ( V_12 , V_46 ) ;
if ( F_17 ( V_4 -> V_13 ) )
return F_18 ( V_4 -> V_13 ) ;
V_44 = F_19 ( V_55 , V_40 ) ;
if ( V_44 )
V_4 -> V_7 = (enum V_56 ) V_44 -> V_57 ;
else
V_4 -> V_7 = V_8 ;
F_20 (dn, child) {
unsigned int V_58 ;
struct V_1 * V_2 ;
if ( F_21 ( V_42 , L_4 , & V_58 ) ) {
F_2 ( V_12 , L_5 ,
V_42 -> V_59 ) ;
V_49 = - V_60 ;
goto V_61;
}
if ( V_58 >= V_62 ) {
F_2 ( V_12 , L_6 , V_58 ) ;
V_49 = - V_60 ;
goto V_61;
}
if ( V_4 -> V_63 [ V_58 ] . V_35 ) {
F_2 ( V_12 , L_7 , V_58 ) ;
V_49 = - V_60 ;
goto V_61;
}
V_2 = & V_4 -> V_63 [ V_58 ] ;
V_2 -> V_14 = V_58 ;
V_2 -> V_5 = V_4 ;
V_2 -> V_35 = F_22 ( V_12 , V_42 , & V_64 ) ;
V_2 -> V_30 = F_23 ( V_42 , L_8 ) ;
if ( F_17 ( V_2 -> V_35 ) ) {
F_2 ( V_12 , L_9 ) ;
V_49 = F_18 ( V_2 -> V_35 ) ;
goto V_61;
}
F_24 ( V_2 -> V_35 , V_2 ) ;
V_50 ++ ;
}
V_48 = F_25 ( V_12 , V_65 ) ;
if ( F_17 ( V_48 ) ) {
F_2 ( V_12 , L_10 ) ;
return F_18 ( V_48 ) ;
}
F_8 ( V_12 , L_11 , V_50 ) ;
return 0 ;
V_61:
F_26 ( V_42 ) ;
return V_49 ;
}
