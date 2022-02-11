static inline T_1 F_1 ( struct V_1 * V_2 , unsigned V_3 )
{
return F_2 ( V_2 -> V_4 + V_3 ) ;
}
static inline void F_3 ( struct V_1 * V_2 , unsigned V_3 , T_1 V_5 )
{
F_4 ( V_5 , V_2 -> V_4 + V_3 ) ;
}
static inline void F_5 ( struct V_1 * V_2 )
{
T_2 V_6 ;
while ( ( V_2 -> V_7 ) &&
( F_1 ( V_2 , V_8 ) & V_9 ) ) {
V_6 = F_1 ( V_2 , V_10 ) ;
if ( V_2 -> V_11 )
* V_2 -> V_11 ++ = V_6 ;
V_2 -> V_7 -- ;
}
}
static inline void F_6 ( struct V_1 * V_2 )
{
T_2 V_6 ;
while ( ( V_2 -> V_12 ) &&
( F_1 ( V_2 , V_8 ) & V_13 ) ) {
V_6 = V_2 -> V_14 ? * V_2 -> V_14 ++ : 0 ;
F_3 ( V_2 , V_10 , V_6 ) ;
V_2 -> V_12 -- ;
}
}
static void F_7 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = F_8 ( V_16 ) ;
T_1 V_17 = F_1 ( V_2 , V_8 ) ;
V_17 &= ~ ( V_18 |
V_19 |
V_20 |
V_21 ) ;
V_17 |= V_22 | V_23 ;
F_3 ( V_2 , V_8 , V_17 ) ;
F_3 ( V_2 , V_24 , 0 ) ;
}
static T_3 F_9 ( int V_25 , void * V_26 )
{
struct V_15 * V_16 = V_26 ;
struct V_1 * V_2 = F_8 ( V_16 ) ;
F_5 ( V_2 ) ;
F_6 ( V_2 ) ;
if ( F_1 ( V_2 , V_8 ) & V_27 ) {
F_7 ( V_16 ) ;
F_10 ( & V_16 -> V_28 ) ;
}
return V_29 ;
}
static int F_11 ( struct V_15 * V_16 ,
struct V_30 * V_31 ,
struct V_32 * V_33 ,
T_1 V_17 )
{
struct V_1 * V_2 = F_8 ( V_16 ) ;
if ( F_12 ( V_31 -> V_34 ) ) {
F_3 ( V_2 , V_8 ,
V_17 | V_21 ) ;
F_6 ( V_2 ) ;
}
V_17 |= V_18 | V_19 | V_21 ;
F_3 ( V_2 , V_8 , V_17 ) ;
return 1 ;
}
static void F_13 ( void * V_35 )
{
struct V_15 * V_16 = V_35 ;
struct V_1 * V_2 = F_8 ( V_16 ) ;
F_7 ( V_16 ) ;
F_14 ( V_16 -> V_36 ) ;
V_2 -> V_37 = 0 ;
;
F_10 ( & V_16 -> V_28 ) ;
}
static int F_15 ( struct V_15 * V_16 ,
struct V_32 * V_33 ,
bool V_38 )
{
struct V_39 * V_40 ;
struct V_41 * V_42 ;
unsigned int V_43 ;
enum V_44 V_45 ;
unsigned long V_46 ;
struct V_47 * V_48 ;
T_4 V_49 ;
if ( V_38 ) {
V_45 = V_50 ;
V_40 = V_16 -> V_36 ;
V_43 = V_33 -> V_51 . V_43 ;
V_42 = V_33 -> V_51 . V_42 ;
V_46 = 0 ;
} else {
V_45 = V_52 ;
V_40 = V_16 -> V_53 ;
V_43 = V_33 -> V_54 . V_43 ;
V_42 = V_33 -> V_54 . V_42 ;
V_46 = V_55 ;
}
V_48 = F_16 ( V_40 , V_42 , V_43 , V_45 , V_46 ) ;
if ( ! V_48 )
return - V_56 ;
if ( ! V_38 ) {
V_48 -> V_57 = F_13 ;
V_48 -> V_58 = V_16 ;
}
V_49 = F_17 ( V_48 ) ;
return F_18 ( V_49 ) ;
}
static inline int F_19 ( struct V_59 * V_60 )
{
int V_61 ;
struct V_41 * V_42 ;
F_20 (sgt->sgl, sgl, (int)sgt->nents - 1 , i) {
if ( F_21 ( V_42 ) % 4 )
return - V_62 ;
}
return 0 ;
}
static int F_22 ( struct V_15 * V_16 ,
struct V_30 * V_31 ,
struct V_32 * V_33 ,
T_1 V_17 )
{
struct V_1 * V_2 = F_8 ( V_16 ) ;
int V_63 ;
if ( F_19 ( & V_33 -> V_51 ) ||
F_19 ( & V_33 -> V_54 ) ) {
F_23 ( & V_31 -> V_64 ,
L_1 ) ;
return F_11 ( V_16 , V_31 , V_33 , V_17 ) ;
}
V_63 = F_15 ( V_16 , V_33 , true ) ;
if ( V_63 )
return V_63 ;
F_24 ( V_16 -> V_36 ) ;
V_2 -> V_37 = 1 ;
F_3 ( V_2 , V_24 , V_33 -> V_65 ) ;
F_3 ( V_2 , V_8 ,
V_17 | V_21 | V_20 ) ;
V_63 = F_15 ( V_16 , V_33 , false ) ;
if ( V_63 ) {
F_14 ( V_16 -> V_36 ) ;
F_7 ( V_16 ) ;
return V_63 ;
}
F_24 ( V_16 -> V_53 ) ;
return 1 ;
}
static bool F_25 ( struct V_15 * V_16 ,
struct V_30 * V_31 ,
struct V_32 * V_33 )
{
if ( ! F_12 ( V_31 -> V_34 ) )
return false ;
if ( V_33 -> V_65 < V_66 )
return false ;
if ( V_33 -> V_65 > 65535 ) {
F_23 ( & V_31 -> V_64 ,
L_2 ,
V_33 -> V_65 ) ;
return false ;
}
if ( ( ( ( V_67 ) V_33 -> V_11 & 3 ) == 0 ) &&
( ( ( V_67 ) V_33 -> V_14 & 3 ) == 0 ) )
return true ;
if ( ( ( V_67 ) V_33 -> V_14 & V_68 ) + V_33 -> V_65 > V_69 ) {
F_23 ( & V_31 -> V_64 ,
L_3 ) ;
return false ;
}
if ( ( ( V_67 ) V_33 -> V_11 & V_68 ) + V_33 -> V_65 > V_69 ) {
F_23 ( & V_31 -> V_64 ,
L_3 ) ;
return false ;
}
return true ;
}
static void F_26 ( struct V_15 * V_16 )
{
if ( V_16 -> V_36 ) {
F_14 ( V_16 -> V_36 ) ;
F_27 ( V_16 -> V_36 ) ;
V_16 -> V_36 = NULL ;
}
if ( V_16 -> V_53 ) {
F_14 ( V_16 -> V_53 ) ;
F_27 ( V_16 -> V_53 ) ;
V_16 -> V_53 = NULL ;
}
}
static void F_28 ( struct V_15 * V_16 , struct V_70 * V_64 )
{
struct V_71 V_72 ;
const T_5 * V_73 ;
T_6 V_74 ;
int V_63 ;
V_73 = F_29 ( V_16 -> V_64 . V_75 , 0 , NULL , NULL ) ;
if ( ! V_73 ) {
F_30 ( V_64 , L_4 ) ;
goto V_76;
}
V_74 = F_31 ( V_73 ) ;
V_16 -> V_36 = F_32 ( V_64 , L_5 ) ;
if ( ! V_16 -> V_36 ) {
F_30 ( V_64 , L_6 ) ;
goto V_76;
}
V_16 -> V_53 = F_32 ( V_64 , L_7 ) ;
if ( ! V_16 -> V_53 ) {
F_30 ( V_64 , L_8 ) ;
goto V_77;
}
V_72 . V_78 = V_50 ;
V_72 . V_79 = ( T_1 ) ( V_74 + V_10 ) ;
V_72 . V_80 = V_81 ;
V_63 = F_33 ( V_16 -> V_36 , & V_72 ) ;
if ( V_63 )
goto V_82;
V_72 . V_78 = V_52 ;
V_72 . V_83 = ( T_1 ) ( V_74 + V_10 ) ;
V_72 . V_84 = V_81 ;
V_63 = F_33 ( V_16 -> V_53 , & V_72 ) ;
if ( V_63 )
goto V_82;
V_16 -> V_85 = F_25 ;
V_16 -> V_86 = 65535 ;
V_16 -> V_46 = V_87 | V_88 ;
return;
V_82:
F_30 ( V_64 , L_9 ,
V_63 ) ;
V_77:
F_26 ( V_16 ) ;
V_76:
return;
}
static int F_34 ( struct V_15 * V_16 ,
struct V_30 * V_31 ,
struct V_32 * V_33 ,
T_1 V_17 ,
unsigned long V_89 )
{
struct V_1 * V_2 = F_8 ( V_16 ) ;
unsigned long V_90 ;
F_3 ( V_2 , V_8 , V_17 | V_21 ) ;
F_6 ( V_2 ) ;
V_90 = V_91 + V_92 ;
while ( V_2 -> V_7 ) {
F_6 ( V_2 ) ;
F_5 ( V_2 ) ;
if ( V_2 -> V_7 && F_35 ( V_91 , V_90 ) ) {
F_36 ( & V_31 -> V_64 ,
L_10 ,
V_91 - V_90 ,
V_2 -> V_12 , V_2 -> V_7 ) ;
return F_11 ( V_16 , V_31 ,
V_33 , V_17 ) ;
}
}
F_7 ( V_16 ) ;
return 0 ;
}
static int F_37 ( struct V_15 * V_16 ,
struct V_30 * V_31 ,
struct V_32 * V_33 )
{
struct V_1 * V_2 = F_8 ( V_16 ) ;
unsigned long V_93 , V_94 , V_95 ;
unsigned long V_96 , V_89 ;
T_1 V_17 = F_1 ( V_2 , V_8 ) ;
V_93 = V_33 -> V_97 ;
V_94 = F_38 ( V_2 -> V_98 ) ;
if ( V_93 >= V_94 / 2 ) {
V_95 = 2 ;
} else if ( V_93 ) {
V_95 = F_39 ( V_94 , V_93 ) ;
V_95 += ( V_95 % 2 ) ;
if ( V_95 >= 65536 )
V_95 = 0 ;
} else {
V_95 = 0 ;
}
V_96 = V_95 ? ( V_94 / V_95 ) : ( V_94 / 65536 ) ;
F_3 ( V_2 , V_99 , V_95 ) ;
if ( ( V_31 -> V_100 & V_101 ) && ( V_33 -> V_11 ) )
V_17 |= V_102 ;
if ( V_31 -> V_100 & V_103 )
V_17 |= V_104 ;
if ( V_31 -> V_100 & V_105 )
V_17 |= V_106 ;
if ( F_12 ( V_31 -> V_34 ) || ( V_31 -> V_100 & V_107 ) )
V_17 |= V_108 | V_109 ;
V_2 -> V_14 = V_33 -> V_14 ;
V_2 -> V_11 = V_33 -> V_11 ;
V_2 -> V_12 = V_33 -> V_65 ;
V_2 -> V_7 = V_33 -> V_65 ;
V_89 = V_33 -> V_65
* 9
* 1000000 / V_96 ;
if ( V_89 <= V_110 )
return F_34 ( V_16 , V_31 , V_33 ,
V_17 , V_89 ) ;
if ( V_16 -> V_85 && F_25 ( V_16 , V_31 , V_33 ) )
return F_22 ( V_16 , V_31 , V_33 , V_17 ) ;
return F_11 ( V_16 , V_31 , V_33 , V_17 ) ;
}
static void F_40 ( struct V_15 * V_16 ,
struct V_111 * V_112 )
{
struct V_1 * V_2 = F_8 ( V_16 ) ;
if ( V_2 -> V_37 ) {
F_14 ( V_16 -> V_36 ) ;
F_14 ( V_16 -> V_53 ) ;
V_2 -> V_37 = 0 ;
}
F_7 ( V_16 ) ;
}
static void F_41 ( struct V_30 * V_31 , bool V_113 )
{
struct V_15 * V_16 = V_31 -> V_16 ;
struct V_1 * V_2 = F_8 ( V_16 ) ;
T_1 V_17 = F_1 ( V_2 , V_8 ) ;
bool V_114 ;
V_114 = ( V_31 -> V_100 & V_115 ) ? V_113 : ! V_113 ;
if ( V_31 -> V_100 & V_115 ) {
V_17 |= V_116 ;
V_17 |= V_117 << V_31 -> V_118 ;
} else {
V_17 &= ~ V_116 ;
V_17 &= ~ ( V_117 << V_31 -> V_118 ) ;
}
if ( V_114 ) {
if ( V_31 -> V_100 & V_107 ) {
V_17 |= V_108 | V_109 ;
} else {
V_17 &= ~ ( V_108 | V_109 ) ;
V_17 |= V_31 -> V_118 ;
}
} else {
V_17 &= ~ V_116 ;
V_17 |= V_108 | V_109 ;
}
F_3 ( V_2 , V_8 , V_17 ) ;
}
static int F_42 ( struct V_119 * V_120 , void * V_35 )
{
return ! strcmp ( V_120 -> V_121 , V_35 ) ;
}
static int F_43 ( struct V_30 * V_31 )
{
int V_76 ;
struct V_119 * V_120 ;
if ( V_31 -> V_100 & V_107 )
return 0 ;
if ( F_12 ( V_31 -> V_34 ) )
return 0 ;
if ( V_31 -> V_118 > 1 ) {
F_30 ( & V_31 -> V_64 ,
L_11 ) ;
return - V_56 ;
}
V_120 = F_44 ( L_12 , F_42 ) ;
if ( ! V_120 )
return 0 ;
V_31 -> V_34 = V_120 -> V_122 + 8 - V_31 -> V_118 ;
F_45 ( & V_31 -> V_64 , L_13 ,
V_31 -> V_118 , V_31 -> V_34 ) ;
V_76 = F_46 ( V_31 -> V_34 ,
( V_31 -> V_100 & V_115 ) ? 0 : 1 ) ;
if ( V_76 ) {
F_30 ( & V_31 -> V_64 ,
L_14 ,
V_31 -> V_118 , V_31 -> V_34 , V_76 ) ;
return V_76 ;
}
F_47 ( V_31 -> V_34 , ( V_31 -> V_100 & V_115 ) ? 0 : 1 ) ;
return 0 ;
}
static int F_48 ( struct V_123 * V_124 )
{
struct V_15 * V_16 ;
struct V_1 * V_2 ;
struct V_125 * V_126 ;
int V_76 ;
V_16 = F_49 ( & V_124 -> V_64 , sizeof( * V_2 ) ) ;
if ( ! V_16 ) {
F_30 ( & V_124 -> V_64 , L_15 ) ;
return - V_127 ;
}
F_50 ( V_124 , V_16 ) ;
V_16 -> V_128 = V_129 ;
V_16 -> V_130 = F_51 ( 8 ) ;
V_16 -> V_131 = 3 ;
V_16 -> V_132 = F_43 ;
V_16 -> V_133 = F_41 ;
V_16 -> V_134 = F_37 ;
V_16 -> V_135 = F_40 ;
V_16 -> V_64 . V_75 = V_124 -> V_64 . V_75 ;
V_2 = F_8 ( V_16 ) ;
V_126 = F_52 ( V_124 , V_136 , 0 ) ;
V_2 -> V_4 = F_53 ( & V_124 -> V_64 , V_126 ) ;
if ( F_54 ( V_2 -> V_4 ) ) {
V_76 = F_55 ( V_2 -> V_4 ) ;
goto V_137;
}
V_2 -> V_98 = F_56 ( & V_124 -> V_64 , NULL ) ;
if ( F_54 ( V_2 -> V_98 ) ) {
V_76 = F_55 ( V_2 -> V_98 ) ;
F_30 ( & V_124 -> V_64 , L_16 , V_76 ) ;
goto V_137;
}
V_2 -> V_25 = F_57 ( V_124 -> V_64 . V_75 , 0 ) ;
if ( V_2 -> V_25 <= 0 ) {
F_30 ( & V_124 -> V_64 , L_17 , V_2 -> V_25 ) ;
V_76 = V_2 -> V_25 ? V_2 -> V_25 : - V_138 ;
goto V_137;
}
F_58 ( V_2 -> V_98 ) ;
V_76 = F_59 ( & V_124 -> V_64 , V_2 -> V_25 , F_9 , 0 ,
F_60 ( & V_124 -> V_64 ) , V_16 ) ;
if ( V_76 ) {
F_30 ( & V_124 -> V_64 , L_18 , V_76 ) ;
goto V_139;
}
F_28 ( V_16 , & V_124 -> V_64 ) ;
F_3 ( V_2 , V_8 ,
V_22 | V_23 ) ;
V_76 = F_61 ( & V_124 -> V_64 , V_16 ) ;
if ( V_76 ) {
F_30 ( & V_124 -> V_64 , L_19 , V_76 ) ;
goto V_139;
}
return 0 ;
V_139:
F_62 ( V_2 -> V_98 ) ;
V_137:
F_63 ( V_16 ) ;
return V_76 ;
}
static int F_64 ( struct V_123 * V_124 )
{
struct V_15 * V_16 = F_65 ( V_124 ) ;
struct V_1 * V_2 = F_8 ( V_16 ) ;
F_3 ( V_2 , V_8 ,
V_22 | V_23 ) ;
F_62 ( V_2 -> V_98 ) ;
F_26 ( V_16 ) ;
return 0 ;
}
