static inline T_1 F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
return F_2 ( V_2 -> V_4 + V_3 ) ;
}
static inline void F_3 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_5 )
{
F_4 ( V_5 , V_2 -> V_4 + V_3 ) ;
}
static inline T_1 F_5 ( struct V_1 * V_2 )
{
T_1 V_3 = F_1 ( V_2 , V_6 ) ;
V_3 >>= V_7 ;
return V_3 & V_8 ;
}
static inline void F_6 ( struct V_1 * V_2 , T_1 V_9 )
{
T_1 V_3 = F_1 ( V_2 , V_10 ) ;
V_3 |= V_9 ;
F_3 ( V_2 , V_10 , V_3 ) ;
}
static inline void F_7 ( struct V_1 * V_2 , T_1 V_9 )
{
T_1 V_3 = F_1 ( V_2 , V_10 ) ;
V_3 &= ~ V_9 ;
F_3 ( V_2 , V_10 , V_3 ) ;
}
static inline void F_8 ( struct V_1 * V_2 , int V_11 )
{
T_1 V_3 , V_12 ;
T_2 V_13 ;
V_3 = F_1 ( V_2 , V_6 ) ;
V_3 &= V_14 ;
V_12 = V_3 >> V_15 ;
if ( V_11 > V_12 )
V_11 = V_12 ;
while ( V_11 -- ) {
V_13 = F_9 ( V_2 -> V_4 + V_16 ) ;
if ( V_2 -> V_17 )
* V_2 -> V_17 ++ = V_13 ;
}
}
static inline void F_10 ( struct V_1 * V_2 , int V_11 )
{
T_1 V_12 ;
T_2 V_13 ;
V_12 = V_18 - F_5 ( V_2 ) ;
V_11 = F_11 ( V_11 , ( int ) V_12 , V_2 -> V_11 ) ;
while ( V_11 -- ) {
V_13 = V_2 -> V_19 ? * V_2 -> V_19 ++ : 0 ;
F_12 ( V_13 , V_2 -> V_4 + V_20 ) ;
V_2 -> V_11 -- ;
}
}
static void F_13 ( struct V_21 * V_22 , bool V_23 )
{
struct V_1 * V_2 = F_14 ( V_22 -> V_24 ) ;
T_1 V_3 ;
V_3 = F_1 ( V_2 , V_25 ) ;
V_3 &= ~ V_26 ;
V_3 |= F_15 ( V_22 -> V_27 ) ;
V_3 |= V_28 ;
if ( V_23 )
V_3 |= V_29 ;
else
V_3 &= ~ V_29 ;
if ( V_22 -> V_30 & V_31 )
V_3 &= ~ V_32 ;
else
V_3 |= V_32 ;
F_3 ( V_2 , V_25 , V_3 ) ;
}
static T_3 F_16 ( struct V_21 * V_22 )
{
return V_18 - 1 ;
}
static int F_17 ( struct V_33 * V_24 ,
struct V_21 * V_22 ,
struct V_34 * V_35 )
{
struct V_1 * V_2 = F_14 ( V_24 ) ;
unsigned int V_36 , div , V_37 ;
unsigned int V_38 , V_39 , V_40 ;
unsigned int V_41 = 0 ;
int V_42 = 0 ;
T_1 V_3 ;
if ( V_35 -> V_11 > V_43 )
return - V_44 ;
if ( V_35 -> V_19 && V_35 -> V_11 >= V_43 )
return - V_44 ;
F_18 ( & V_2 -> V_45 ) ;
V_2 -> V_19 = V_35 -> V_19 ;
V_2 -> V_17 = V_35 -> V_17 ;
V_2 -> V_11 = V_35 -> V_11 ;
F_3 ( V_2 , V_46 , ~ 0 ) ;
V_3 = F_1 ( V_2 , V_25 ) ;
F_3 ( V_2 , V_25 ,
V_3 | V_47 | V_48 ) ;
if ( V_22 -> V_30 & V_49 )
V_3 |= V_50 ;
else
V_3 &= ~ V_50 ;
if ( V_22 -> V_30 & V_51 )
V_3 |= V_52 ;
else
V_3 &= ~ V_52 ;
if ( V_22 -> V_30 & V_53 )
V_3 |= V_54 ;
else
V_3 &= ~ V_54 ;
if ( V_2 -> V_17 )
V_3 &= ~ V_55 ;
else
V_3 |= V_55 ;
F_3 ( V_2 , V_25 , V_3 ) ;
V_36 = F_19 ( V_2 -> V_56 ) ;
if ( V_36 < ( 2 * V_35 -> V_57 ) ) {
F_20 ( V_2 -> V_56 , 2 * V_35 -> V_57 ) ;
V_36 = F_19 ( V_2 -> V_56 ) ;
}
div = V_36 / ( 2 * V_35 -> V_57 ) ;
if ( div <= ( V_58 + 1 ) ) {
if ( div > 0 )
div -- ;
V_3 = F_21 ( div ) | V_59 ;
} else {
div = F_22 ( V_36 ) - F_22 ( V_35 -> V_57 ) ;
V_3 = F_23 ( div ) ;
}
F_3 ( V_2 , V_60 , V_3 ) ;
if ( V_2 -> V_19 )
V_41 = V_35 -> V_11 ;
F_3 ( V_2 , V_61 , F_24 ( V_35 -> V_11 ) ) ;
F_3 ( V_2 , V_62 , F_25 ( V_41 ) ) ;
F_10 ( V_2 , V_18 - 1 ) ;
F_6 ( V_2 , V_63 |
V_64 ) ;
if ( V_41 > V_18 )
F_6 ( V_2 , V_65 ) ;
V_3 = F_1 ( V_2 , V_25 ) ;
F_3 ( V_2 , V_25 , V_3 | V_66 ) ;
V_40 = F_26 ( V_35 -> V_11 * 8 * 2 / ( V_35 -> V_57 / 1000 ) , 100U ) ;
V_38 = V_67 ;
V_37 = F_27 ( & V_2 -> V_45 ,
F_28 ( V_40 ) ) ;
V_39 = V_67 ;
if ( ! V_37 ) {
F_29 ( & V_24 -> V_68 ,
L_1 ,
F_30 ( & V_22 -> V_68 ) , V_35 -> V_11 , V_35 -> V_57 ,
F_31 ( V_39 - V_38 ) , V_40 ) ;
V_42 = - V_69 ;
goto V_70;
}
V_70:
F_3 ( V_2 , V_10 , 0 ) ;
return V_42 ;
}
static T_4 F_32 ( int V_71 , void * V_72 )
{
struct V_1 * V_2 = V_72 ;
T_1 V_73 = F_1 ( V_2 , V_46 ) ;
if ( V_73 & V_63 ) {
F_3 ( V_2 , V_46 , V_63 ) ;
F_8 ( V_2 , V_18 ) ;
F_33 ( & V_2 -> V_45 ) ;
return V_74 ;
}
if ( V_73 & V_64 ) {
F_8 ( V_2 , V_18 ) ;
F_3 ( V_2 , V_46 , V_64 ) ;
return V_74 ;
}
if ( V_73 & V_65 ) {
F_10 ( V_2 , V_18 ) ;
if ( ! V_2 -> V_11 )
F_7 ( V_2 , V_65 ) ;
F_3 ( V_2 , V_46 , V_65 ) ;
return V_74 ;
}
return V_75 ;
}
static int F_34 ( struct V_76 * V_68 )
{
struct V_33 * V_24 = F_35 ( V_68 ) ;
struct V_1 * V_2 = F_14 ( V_24 ) ;
int V_42 ;
V_42 = F_36 ( V_2 -> V_77 ) ;
if ( V_42 ) {
F_37 ( V_68 , L_2 ) ;
goto V_70;
}
V_42 = F_36 ( V_2 -> V_56 ) ;
if ( V_42 ) {
F_37 ( V_68 , L_3 ) ;
goto V_78;
}
F_3 ( V_2 , V_25 ,
V_79 | V_80 | V_81 ) ;
return 0 ;
V_78:
F_38 ( V_2 -> V_77 ) ;
V_70:
return V_42 ;
}
static int F_39 ( struct V_76 * V_68 )
{
struct V_33 * V_24 = F_35 ( V_68 ) ;
struct V_1 * V_2 = F_14 ( V_24 ) ;
F_38 ( V_2 -> V_56 ) ;
F_38 ( V_2 -> V_77 ) ;
return 0 ;
}
static int F_40 ( struct V_82 * V_83 )
{
struct V_33 * V_24 ;
struct V_1 * V_2 ;
struct V_84 * V_85 ;
int V_42 = 0 , V_71 ;
V_24 = F_41 ( & V_83 -> V_68 , sizeof( struct V_1 ) ) ;
if ( ! V_24 ) {
F_37 ( & V_83 -> V_68 , L_4 ) ;
return - V_86 ;
}
F_42 ( V_83 , V_24 ) ;
V_2 = F_14 ( V_24 ) ;
V_85 = F_43 ( V_83 , V_87 , 0 ) ;
V_2 -> V_4 = F_44 ( & V_83 -> V_68 , V_85 ) ;
if ( F_45 ( V_2 -> V_4 ) ) {
V_42 = F_46 ( V_2 -> V_4 ) ;
goto V_88;
}
V_71 = F_47 ( V_83 , 0 ) ;
if ( V_71 < 0 ) {
F_37 ( & V_83 -> V_68 , L_5 ) ;
V_42 = - V_89 ;
goto V_88;
}
V_42 = F_48 ( & V_83 -> V_68 , V_71 , F_32 ,
0 , L_6 , V_2 ) ;
if ( V_42 ) {
F_37 ( & V_83 -> V_68 , L_7 ) ;
goto V_88;
}
V_2 -> V_24 = V_24 ;
V_24 -> V_90 = 100 * 1000 * 1000 ;
V_24 -> V_91 = 3 * 1000 ;
V_24 -> V_92 = F_13 ;
V_24 -> V_93 = F_17 ;
V_24 -> V_94 = 4 ;
V_24 -> V_95 = V_49 | V_51 | V_31 | V_53 ;
V_24 -> V_96 = F_49 ( 8 ) ;
V_24 -> V_68 . V_97 = V_83 -> V_68 . V_97 ;
V_24 -> V_98 = true ;
V_24 -> V_99 = F_16 ;
V_2 -> V_77 = F_50 ( & V_83 -> V_68 , L_8 ) ;
if ( F_45 ( V_2 -> V_77 ) ) {
F_37 ( & V_83 -> V_68 , L_9 ) ;
V_42 = F_46 ( V_2 -> V_77 ) ;
goto V_88;
}
V_2 -> V_56 = F_50 ( & V_83 -> V_68 , L_10 ) ;
if ( F_45 ( V_2 -> V_56 ) ) {
F_37 ( & V_83 -> V_68 , L_11 ) ;
V_42 = F_46 ( V_2 -> V_56 ) ;
goto V_88;
}
F_51 ( & V_2 -> V_45 ) ;
V_42 = F_34 ( & V_83 -> V_68 ) ;
if ( V_42 ) {
F_37 ( & V_83 -> V_68 , L_12 ) ;
goto V_88;
}
F_52 ( & V_83 -> V_68 ) ;
F_53 ( & V_83 -> V_68 ) ;
F_54 ( & V_83 -> V_68 ) ;
V_42 = F_55 ( & V_83 -> V_68 , V_24 ) ;
if ( V_42 ) {
F_37 ( & V_83 -> V_68 , L_13 ) ;
goto V_100;
}
return 0 ;
V_100:
F_56 ( & V_83 -> V_68 ) ;
F_39 ( & V_83 -> V_68 ) ;
V_88:
F_57 ( V_24 ) ;
return V_42 ;
}
static int F_58 ( struct V_82 * V_83 )
{
F_56 ( & V_83 -> V_68 ) ;
return 0 ;
}
