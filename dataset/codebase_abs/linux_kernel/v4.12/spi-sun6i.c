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
V_12 = V_2 -> V_18 - F_5 ( V_2 ) ;
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
if ( V_23 )
V_3 |= V_28 ;
else
V_3 &= ~ V_28 ;
F_3 ( V_2 , V_25 , V_3 ) ;
}
static T_3 F_16 ( struct V_21 * V_22 )
{
return V_29 - 1 ;
}
static int F_17 ( struct V_30 * V_24 ,
struct V_21 * V_22 ,
struct V_31 * V_32 )
{
struct V_1 * V_2 = F_14 ( V_24 ) ;
unsigned int V_33 , div , V_34 ;
unsigned int V_35 , V_36 , V_37 ;
unsigned int V_38 ;
unsigned int V_39 = 0 ;
int V_40 = 0 ;
T_1 V_3 ;
if ( V_32 -> V_11 > V_29 )
return - V_41 ;
F_18 ( & V_2 -> V_42 ) ;
V_2 -> V_19 = V_32 -> V_19 ;
V_2 -> V_17 = V_32 -> V_17 ;
V_2 -> V_11 = V_32 -> V_11 ;
F_3 ( V_2 , V_43 , ~ 0 ) ;
F_3 ( V_2 , V_44 ,
V_45 | V_46 ) ;
V_38 = V_2 -> V_18 / 4 * 3 ;
F_3 ( V_2 , V_44 ,
( V_38 << V_47 ) |
( V_38 << V_48 ) ) ;
V_3 = F_1 ( V_2 , V_25 ) ;
if ( V_22 -> V_49 & V_50 )
V_3 |= V_51 ;
else
V_3 &= ~ V_51 ;
if ( V_22 -> V_49 & V_52 )
V_3 |= V_53 ;
else
V_3 &= ~ V_53 ;
if ( V_22 -> V_49 & V_54 )
V_3 |= V_55 ;
else
V_3 &= ~ V_55 ;
if ( V_2 -> V_17 )
V_3 &= ~ V_56 ;
else
V_3 |= V_56 ;
V_3 |= V_57 ;
F_3 ( V_2 , V_25 , V_3 ) ;
V_33 = F_19 ( V_2 -> V_58 ) ;
if ( V_33 < ( 2 * V_32 -> V_59 ) ) {
F_20 ( V_2 -> V_58 , 2 * V_32 -> V_59 ) ;
V_33 = F_19 ( V_2 -> V_58 ) ;
}
div = V_33 / ( 2 * V_32 -> V_59 ) ;
if ( div <= ( V_60 + 1 ) ) {
if ( div > 0 )
div -- ;
V_3 = F_21 ( div ) | V_61 ;
} else {
div = F_22 ( V_33 ) - F_22 ( V_32 -> V_59 ) ;
V_3 = F_23 ( div ) ;
}
F_3 ( V_2 , V_62 , V_3 ) ;
if ( V_2 -> V_19 )
V_39 = V_32 -> V_11 ;
F_3 ( V_2 , V_63 , F_24 ( V_32 -> V_11 ) ) ;
F_3 ( V_2 , V_64 , F_25 ( V_39 ) ) ;
F_3 ( V_2 , V_65 ,
F_26 ( V_39 ) ) ;
F_10 ( V_2 , V_2 -> V_18 ) ;
F_3 ( V_2 , V_10 , V_66 ) ;
F_6 ( V_2 , V_66 |
V_67 ) ;
if ( V_39 > V_2 -> V_18 )
F_6 ( V_2 , V_68 ) ;
V_3 = F_1 ( V_2 , V_25 ) ;
F_3 ( V_2 , V_25 , V_3 | V_69 ) ;
V_37 = F_27 ( V_32 -> V_11 * 8 * 2 / ( V_32 -> V_59 / 1000 ) , 100U ) ;
V_35 = V_70 ;
V_34 = F_28 ( & V_2 -> V_42 ,
F_29 ( V_37 ) ) ;
V_36 = V_70 ;
if ( ! V_34 ) {
F_30 ( & V_24 -> V_71 ,
L_1 ,
F_31 ( & V_22 -> V_71 ) , V_32 -> V_11 , V_32 -> V_59 ,
F_32 ( V_36 - V_35 ) , V_37 ) ;
V_40 = - V_72 ;
goto V_73;
}
V_73:
F_3 ( V_2 , V_10 , 0 ) ;
return V_40 ;
}
static T_4 F_33 ( int V_74 , void * V_75 )
{
struct V_1 * V_2 = V_75 ;
T_1 V_76 = F_1 ( V_2 , V_43 ) ;
if ( V_76 & V_66 ) {
F_3 ( V_2 , V_43 , V_66 ) ;
F_8 ( V_2 , V_2 -> V_18 ) ;
F_34 ( & V_2 -> V_42 ) ;
return V_77 ;
}
if ( V_76 & V_67 ) {
F_8 ( V_2 , V_78 ) ;
F_3 ( V_2 , V_43 , V_67 ) ;
return V_77 ;
}
if ( V_76 & V_68 ) {
F_10 ( V_2 , V_78 ) ;
if ( ! V_2 -> V_11 )
F_7 ( V_2 , V_68 ) ;
F_3 ( V_2 , V_43 , V_68 ) ;
return V_77 ;
}
return V_79 ;
}
static int F_35 ( struct V_80 * V_71 )
{
struct V_30 * V_24 = F_36 ( V_71 ) ;
struct V_1 * V_2 = F_14 ( V_24 ) ;
int V_40 ;
V_40 = F_37 ( V_2 -> V_81 ) ;
if ( V_40 ) {
F_38 ( V_71 , L_2 ) ;
goto V_73;
}
V_40 = F_37 ( V_2 -> V_58 ) ;
if ( V_40 ) {
F_38 ( V_71 , L_3 ) ;
goto V_82;
}
V_40 = F_39 ( V_2 -> V_83 ) ;
if ( V_40 ) {
F_38 ( V_71 , L_4 ) ;
goto V_84;
}
F_3 ( V_2 , V_85 ,
V_86 | V_87 | V_88 ) ;
return 0 ;
V_84:
F_40 ( V_2 -> V_58 ) ;
V_82:
F_40 ( V_2 -> V_81 ) ;
V_73:
return V_40 ;
}
static int F_41 ( struct V_80 * V_71 )
{
struct V_30 * V_24 = F_36 ( V_71 ) ;
struct V_1 * V_2 = F_14 ( V_24 ) ;
F_42 ( V_2 -> V_83 ) ;
F_40 ( V_2 -> V_58 ) ;
F_40 ( V_2 -> V_81 ) ;
return 0 ;
}
static int F_43 ( struct V_89 * V_90 )
{
struct V_30 * V_24 ;
struct V_1 * V_2 ;
struct V_91 * V_92 ;
int V_40 = 0 , V_74 ;
V_24 = F_44 ( & V_90 -> V_71 , sizeof( struct V_1 ) ) ;
if ( ! V_24 ) {
F_38 ( & V_90 -> V_71 , L_5 ) ;
return - V_93 ;
}
F_45 ( V_90 , V_24 ) ;
V_2 = F_14 ( V_24 ) ;
V_92 = F_46 ( V_90 , V_94 , 0 ) ;
V_2 -> V_4 = F_47 ( & V_90 -> V_71 , V_92 ) ;
if ( F_48 ( V_2 -> V_4 ) ) {
V_40 = F_49 ( V_2 -> V_4 ) ;
goto V_95;
}
V_74 = F_50 ( V_90 , 0 ) ;
if ( V_74 < 0 ) {
F_38 ( & V_90 -> V_71 , L_6 ) ;
V_40 = - V_96 ;
goto V_95;
}
V_40 = F_51 ( & V_90 -> V_71 , V_74 , F_33 ,
0 , L_7 , V_2 ) ;
if ( V_40 ) {
F_38 ( & V_90 -> V_71 , L_8 ) ;
goto V_95;
}
V_2 -> V_24 = V_24 ;
V_2 -> V_18 = ( unsigned long ) F_52 ( & V_90 -> V_71 ) ;
V_24 -> V_97 = 100 * 1000 * 1000 ;
V_24 -> V_98 = 3 * 1000 ;
V_24 -> V_99 = F_13 ;
V_24 -> V_100 = F_17 ;
V_24 -> V_101 = 4 ;
V_24 -> V_102 = V_50 | V_52 | V_103 | V_54 ;
V_24 -> V_104 = F_53 ( 8 ) ;
V_24 -> V_71 . V_105 = V_90 -> V_71 . V_105 ;
V_24 -> V_106 = true ;
V_24 -> V_107 = F_16 ;
V_2 -> V_81 = F_54 ( & V_90 -> V_71 , L_9 ) ;
if ( F_48 ( V_2 -> V_81 ) ) {
F_38 ( & V_90 -> V_71 , L_10 ) ;
V_40 = F_49 ( V_2 -> V_81 ) ;
goto V_95;
}
V_2 -> V_58 = F_54 ( & V_90 -> V_71 , L_11 ) ;
if ( F_48 ( V_2 -> V_58 ) ) {
F_38 ( & V_90 -> V_71 , L_12 ) ;
V_40 = F_49 ( V_2 -> V_58 ) ;
goto V_95;
}
F_55 ( & V_2 -> V_42 ) ;
V_2 -> V_83 = F_56 ( & V_90 -> V_71 , NULL ) ;
if ( F_48 ( V_2 -> V_83 ) ) {
F_38 ( & V_90 -> V_71 , L_13 ) ;
V_40 = F_49 ( V_2 -> V_83 ) ;
goto V_95;
}
V_40 = F_35 ( & V_90 -> V_71 ) ;
if ( V_40 ) {
F_38 ( & V_90 -> V_71 , L_14 ) ;
goto V_95;
}
F_57 ( & V_90 -> V_71 ) ;
F_58 ( & V_90 -> V_71 ) ;
F_59 ( & V_90 -> V_71 ) ;
V_40 = F_60 ( & V_90 -> V_71 , V_24 ) ;
if ( V_40 ) {
F_38 ( & V_90 -> V_71 , L_15 ) ;
goto V_108;
}
return 0 ;
V_108:
F_61 ( & V_90 -> V_71 ) ;
F_41 ( & V_90 -> V_71 ) ;
V_95:
F_62 ( V_24 ) ;
return V_40 ;
}
static int F_63 ( struct V_89 * V_90 )
{
F_61 ( & V_90 -> V_71 ) ;
return 0 ;
}
