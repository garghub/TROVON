static inline T_1 F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
return F_2 ( V_2 -> V_4 + V_3 ) ;
}
static inline void F_3 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_5 )
{
F_4 ( V_5 , V_2 -> V_4 + V_3 ) ;
}
static inline void F_5 ( struct V_1 * V_2 , int V_6 )
{
T_1 V_3 , V_7 ;
T_2 V_8 ;
V_3 = F_1 ( V_2 , V_9 ) ;
V_3 &= V_10 ;
V_7 = V_3 >> V_11 ;
if ( V_6 > V_7 )
V_6 = V_7 ;
while ( V_6 -- ) {
V_8 = F_6 ( V_2 -> V_4 + V_12 ) ;
if ( V_2 -> V_13 )
* V_2 -> V_13 ++ = V_8 ;
}
}
static inline void F_7 ( struct V_1 * V_2 , int V_6 )
{
T_2 V_8 ;
if ( V_6 > V_2 -> V_6 )
V_6 = V_2 -> V_6 ;
while ( V_6 -- ) {
V_8 = V_2 -> V_14 ? * V_2 -> V_14 ++ : 0 ;
F_8 ( V_8 , V_2 -> V_4 + V_15 ) ;
V_2 -> V_6 -- ;
}
}
static void F_9 ( struct V_16 * V_17 , bool V_18 )
{
struct V_1 * V_2 = F_10 ( V_17 -> V_19 ) ;
T_1 V_3 ;
V_3 = F_1 ( V_2 , V_20 ) ;
V_3 &= ~ V_21 ;
V_3 |= F_11 ( V_17 -> V_22 ) ;
if ( V_18 )
V_3 |= V_23 ;
else
V_3 &= ~ V_23 ;
F_3 ( V_2 , V_20 , V_3 ) ;
}
static int F_12 ( struct V_24 * V_19 ,
struct V_16 * V_17 ,
struct V_25 * V_26 )
{
struct V_1 * V_2 = F_10 ( V_19 ) ;
unsigned int V_27 , div , V_28 ;
unsigned int V_29 = 0 ;
int V_30 = 0 ;
T_1 V_3 ;
if ( V_26 -> V_6 > V_31 )
return - V_32 ;
F_13 ( & V_2 -> V_33 ) ;
V_2 -> V_14 = V_26 -> V_14 ;
V_2 -> V_13 = V_26 -> V_13 ;
V_2 -> V_6 = V_26 -> V_6 ;
F_3 ( V_2 , V_34 , ~ 0 ) ;
F_3 ( V_2 , V_35 ,
V_36 | V_37 ) ;
V_3 = F_1 ( V_2 , V_20 ) ;
if ( V_17 -> V_38 & V_39 )
V_3 |= V_40 ;
else
V_3 &= ~ V_40 ;
if ( V_17 -> V_38 & V_41 )
V_3 |= V_42 ;
else
V_3 &= ~ V_42 ;
if ( V_17 -> V_38 & V_43 )
V_3 |= V_44 ;
else
V_3 &= ~ V_44 ;
if ( V_2 -> V_13 )
V_3 &= ~ V_45 ;
else
V_3 |= V_45 ;
V_3 |= V_46 ;
F_3 ( V_2 , V_20 , V_3 ) ;
V_27 = F_14 ( V_2 -> V_47 ) ;
if ( V_27 < ( 2 * V_17 -> V_48 ) ) {
F_15 ( V_2 -> V_47 , 2 * V_17 -> V_48 ) ;
V_27 = F_14 ( V_2 -> V_47 ) ;
}
div = V_27 / ( 2 * V_17 -> V_48 ) ;
if ( div <= ( V_49 + 1 ) ) {
if ( div > 0 )
div -- ;
V_3 = F_16 ( div ) | V_50 ;
} else {
div = F_17 ( V_27 ) - F_17 ( V_17 -> V_48 ) ;
V_3 = F_18 ( div ) ;
}
F_3 ( V_2 , V_51 , V_3 ) ;
if ( V_2 -> V_14 )
V_29 = V_26 -> V_6 ;
F_3 ( V_2 , V_52 , F_19 ( V_26 -> V_6 ) ) ;
F_3 ( V_2 , V_53 , F_20 ( V_29 ) ) ;
F_3 ( V_2 , V_54 ,
F_21 ( V_29 ) ) ;
F_7 ( V_2 , V_31 ) ;
F_3 ( V_2 , V_55 , V_56 ) ;
V_3 = F_1 ( V_2 , V_20 ) ;
F_3 ( V_2 , V_20 , V_3 | V_57 ) ;
V_28 = F_22 ( & V_2 -> V_33 ,
F_23 ( 1000 ) ) ;
if ( ! V_28 ) {
V_30 = - V_58 ;
goto V_59;
}
F_5 ( V_2 , V_31 ) ;
V_59:
F_3 ( V_2 , V_55 , 0 ) ;
return V_30 ;
}
static T_3 F_24 ( int V_60 , void * V_61 )
{
struct V_1 * V_2 = V_61 ;
T_1 V_62 = F_1 ( V_2 , V_34 ) ;
if ( V_62 & V_56 ) {
F_3 ( V_2 , V_34 , V_56 ) ;
F_25 ( & V_2 -> V_33 ) ;
return V_63 ;
}
return V_64 ;
}
static int F_26 ( struct V_65 * V_66 )
{
struct V_24 * V_19 = F_27 ( V_66 ) ;
struct V_1 * V_2 = F_10 ( V_19 ) ;
int V_30 ;
V_30 = F_28 ( V_2 -> V_67 ) ;
if ( V_30 ) {
F_29 ( V_66 , L_1 ) ;
goto V_59;
}
V_30 = F_28 ( V_2 -> V_47 ) ;
if ( V_30 ) {
F_29 ( V_66 , L_2 ) ;
goto V_68;
}
V_30 = F_30 ( V_2 -> V_69 ) ;
if ( V_30 ) {
F_29 ( V_66 , L_3 ) ;
goto V_70;
}
F_3 ( V_2 , V_71 ,
V_72 | V_73 | V_74 ) ;
return 0 ;
V_70:
F_31 ( V_2 -> V_47 ) ;
V_68:
F_31 ( V_2 -> V_67 ) ;
V_59:
return V_30 ;
}
static int F_32 ( struct V_65 * V_66 )
{
struct V_24 * V_19 = F_27 ( V_66 ) ;
struct V_1 * V_2 = F_10 ( V_19 ) ;
F_33 ( V_2 -> V_69 ) ;
F_31 ( V_2 -> V_47 ) ;
F_31 ( V_2 -> V_67 ) ;
return 0 ;
}
static int F_34 ( struct V_75 * V_76 )
{
struct V_24 * V_19 ;
struct V_1 * V_2 ;
struct V_77 * V_78 ;
int V_30 = 0 , V_60 ;
V_19 = F_35 ( & V_76 -> V_66 , sizeof( struct V_1 ) ) ;
if ( ! V_19 ) {
F_29 ( & V_76 -> V_66 , L_4 ) ;
return - V_79 ;
}
F_36 ( V_76 , V_19 ) ;
V_2 = F_10 ( V_19 ) ;
V_78 = F_37 ( V_76 , V_80 , 0 ) ;
V_2 -> V_4 = F_38 ( & V_76 -> V_66 , V_78 ) ;
if ( F_39 ( V_2 -> V_4 ) ) {
V_30 = F_40 ( V_2 -> V_4 ) ;
goto V_81;
}
V_60 = F_41 ( V_76 , 0 ) ;
if ( V_60 < 0 ) {
F_29 ( & V_76 -> V_66 , L_5 ) ;
V_30 = - V_82 ;
goto V_81;
}
V_30 = F_42 ( & V_76 -> V_66 , V_60 , F_24 ,
0 , L_6 , V_2 ) ;
if ( V_30 ) {
F_29 ( & V_76 -> V_66 , L_7 ) ;
goto V_81;
}
V_2 -> V_19 = V_19 ;
V_19 -> V_83 = F_9 ;
V_19 -> V_84 = F_12 ;
V_19 -> V_85 = 4 ;
V_19 -> V_86 = V_39 | V_41 | V_87 | V_43 ;
V_19 -> V_88 = F_43 ( 8 ) ;
V_19 -> V_66 . V_89 = V_76 -> V_66 . V_89 ;
V_19 -> V_90 = true ;
V_2 -> V_67 = F_44 ( & V_76 -> V_66 , L_8 ) ;
if ( F_39 ( V_2 -> V_67 ) ) {
F_29 ( & V_76 -> V_66 , L_9 ) ;
V_30 = F_40 ( V_2 -> V_67 ) ;
goto V_81;
}
V_2 -> V_47 = F_44 ( & V_76 -> V_66 , L_10 ) ;
if ( F_39 ( V_2 -> V_47 ) ) {
F_29 ( & V_76 -> V_66 , L_11 ) ;
V_30 = F_40 ( V_2 -> V_47 ) ;
goto V_81;
}
F_45 ( & V_2 -> V_33 ) ;
V_2 -> V_69 = F_46 ( & V_76 -> V_66 , NULL ) ;
if ( F_39 ( V_2 -> V_69 ) ) {
F_29 ( & V_76 -> V_66 , L_12 ) ;
V_30 = F_40 ( V_2 -> V_69 ) ;
goto V_81;
}
V_30 = F_26 ( & V_76 -> V_66 ) ;
if ( V_30 ) {
F_29 ( & V_76 -> V_66 , L_13 ) ;
goto V_81;
}
F_47 ( & V_76 -> V_66 ) ;
F_48 ( & V_76 -> V_66 ) ;
F_49 ( & V_76 -> V_66 ) ;
V_30 = F_50 ( & V_76 -> V_66 , V_19 ) ;
if ( V_30 ) {
F_29 ( & V_76 -> V_66 , L_14 ) ;
goto V_91;
}
return 0 ;
V_91:
F_51 ( & V_76 -> V_66 ) ;
F_32 ( & V_76 -> V_66 ) ;
V_81:
F_52 ( V_19 ) ;
return V_30 ;
}
static int F_53 ( struct V_75 * V_76 )
{
F_51 ( & V_76 -> V_66 ) ;
return 0 ;
}
