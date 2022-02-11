static inline T_1 F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
return F_2 ( V_2 -> V_4 + V_3 ) ;
}
static inline void F_3 ( struct V_1 * V_2 , T_1 V_5 , T_1 V_3 )
{
F_4 ( V_3 >= V_6 ) ;
F_5 ( V_5 , V_2 -> V_4 + V_3 ) ;
}
static inline void F_6 ( struct V_1 * V_2 )
{
F_1 ( V_2 , V_7 ) ;
}
static inline T_1 F_7 ( struct V_1 * V_2 , T_1 V_3 )
{
return F_2 ( V_2 -> V_8 + V_3 ) ;
}
static inline void F_8 ( struct V_1 * V_2 , T_1 V_5 , T_1 V_3 )
{
F_5 ( V_5 , V_2 -> V_8 + V_3 ) ;
}
static inline void F_9 ( struct V_1 * V_2 )
{
F_7 ( V_2 , V_6 ) ;
}
static bool F_10 ( struct V_1 * V_2 )
{
return V_2 -> V_9 >= V_10 ;
}
int F_11 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = F_12 ( V_12 ) ;
int V_13 ;
V_13 = F_13 ( V_2 -> V_14 ) ;
if ( V_13 ) {
F_14 ( V_12 , L_1 , V_13 ) ;
return V_13 ;
}
V_13 = F_13 ( V_2 -> V_15 ) ;
if ( V_13 ) {
F_14 ( V_12 , L_2 , V_13 ) ;
F_15 ( V_2 -> V_14 ) ;
return V_13 ;
}
V_13 = F_13 ( V_2 -> V_16 ) ;
if ( V_13 ) {
F_14 ( V_12 , L_3 , V_13 ) ;
F_15 ( V_2 -> V_15 ) ;
F_15 ( V_2 -> V_14 ) ;
return V_13 ;
}
return 0 ;
}
int F_16 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = F_12 ( V_12 ) ;
F_15 ( V_2 -> V_14 ) ;
F_15 ( V_2 -> V_15 ) ;
F_15 ( V_2 -> V_16 ) ;
return 0 ;
}
static void F_17 ( struct V_1 * V_2 )
{
V_2 -> V_17 = V_18 ;
F_3 ( V_2 , V_2 -> V_19 -> V_20 , V_21 ) ;
F_3 ( V_2 , V_2 -> V_19 -> V_22 , V_23 ) ;
F_6 ( V_2 ) ;
if ( V_2 -> V_19 -> V_24 )
V_2 -> V_19 -> V_24 () ;
}
static unsigned long F_18 ( int V_25 ,
unsigned long V_26 )
{
return ( V_27 ) V_26 * ( V_25 + 1 ) / V_28 ;
}
static void F_19 ( struct V_1 * V_2 ,
enum V_29 V_9 )
{
V_2 -> V_9 = V_9 ;
F_3 ( V_2 , V_9 - 1 , V_7 ) ;
F_6 ( V_2 ) ;
}
static int F_20 ( struct V_1 * V_2 , bool V_30 )
{
T_1 V_5 ;
V_5 = F_7 ( V_2 , V_31 ) ;
if ( V_30 )
V_5 |= V_32 ;
else
V_5 &= ~ V_32 ;
F_8 ( V_2 , V_5 , V_31 ) ;
F_9 ( V_2 ) ;
return 0 ;
}
static void F_21 ( struct V_1 * V_2 )
{
int V_33 , V_34 ;
T_1 V_5 ;
for ( V_33 = 0 ; V_33 < V_35 ; V_33 ++ ) {
if ( V_33 < V_2 -> V_36 )
V_34 = V_2 -> V_36 ;
else if ( V_33 > V_2 -> V_37 )
V_34 = V_2 -> V_37 ;
else
V_34 = V_33 ;
V_5 = F_22 ( V_2 -> V_38 ,
V_2 -> V_39 [ V_34 ] ) ;
F_5 ( V_5 , V_2 -> V_40 + V_33 * 4 ) ;
}
F_9 ( V_2 ) ;
}
static void F_23 ( struct V_1 * V_2 )
{
T_1 V_5 ;
if ( V_2 -> V_41 > 0x7f ) {
V_5 = V_2 -> V_41 << V_42 ;
V_5 |= V_43 ;
} else {
V_5 = V_2 -> V_41 << V_44 ;
}
V_5 |= V_45 ;
V_5 |= V_46 ;
F_8 ( V_2 , V_5 , V_6 ) ;
F_8 ( V_2 , V_2 -> V_47 , V_48 ) ;
V_5 = F_24 ( V_2 -> V_49 , V_2 -> V_50 * 8 ) ;
F_25 ( ! V_5 || ( V_5 > V_51 ) ) ;
V_5 = ( V_5 - 1 ) << V_52 ;
V_5 |= 1 << V_53 ;
F_5 ( V_5 , V_2 -> V_54 + V_55 ) ;
F_9 ( V_2 ) ;
}
static void F_26 ( struct V_1 * V_2 )
{
T_1 V_5 ;
V_2 -> V_36 = 0 ;
V_2 -> V_37 = V_2 -> V_56 - 1 ;
V_2 -> V_57 = V_2 -> V_36 + 1 ;
F_8 ( V_2 , 0 , V_31 ) ;
V_5 = ( V_2 -> V_57 << V_58 ) |
( V_2 -> V_37 << V_59 ) |
( V_2 -> V_36 << V_60 ) ;
F_8 ( V_2 , V_5 , V_31 ) ;
F_9 ( V_2 ) ;
F_3 ( V_2 , 0 , V_61 ) ;
F_8 ( V_2 , 0 , V_62 ) ;
F_8 ( V_2 , V_63 | V_64 ,
V_65 ) ;
F_21 ( V_2 ) ;
F_23 ( V_2 ) ;
}
static int F_27 ( struct V_1 * V_2 , unsigned long V_66 )
{
struct V_67 * V_68 ;
int V_33 , V_69 ;
F_28 () ;
V_68 = F_29 ( V_2 -> V_19 -> V_12 , & V_66 ) ;
if ( F_30 ( V_68 ) ) {
F_31 () ;
return F_32 ( V_68 ) ;
}
V_69 = F_33 ( V_68 ) ;
F_31 () ;
for ( V_33 = 0 ; V_33 < V_2 -> V_56 ; V_33 ++ ) {
if ( F_34 ( V_2 -> V_38 , V_2 -> V_39 [ V_33 ] ) == V_69 )
return V_33 ;
}
return - V_70 ;
}
static int F_35 ( struct V_1 * V_2 ,
struct V_71 * V_72 ,
unsigned long V_66 )
{
T_1 V_5 ;
V_72 -> V_25 = V_28 - 1 ;
if ( V_66 < V_2 -> V_73 ) {
int V_74 ;
V_74 = F_36 ( V_66 / 1000 * V_28 ,
V_2 -> V_73 / 1000 ) ;
if ( ! V_74 ) {
F_14 ( V_2 -> V_12 , L_4 ,
V_75 , V_66 ) ;
return - V_76 ;
}
V_72 -> V_25 = V_74 - 1 ;
V_66 = V_2 -> V_73 ;
}
V_5 = F_37 ( V_66 , V_2 -> V_77 ) ;
if ( V_5 > V_78 ) {
F_14 ( V_2 -> V_12 , L_5 ,
V_75 , V_66 ) ;
return - V_76 ;
}
V_72 -> V_79 = V_5 ;
V_72 -> V_80 = F_38 ( V_72 -> V_79 , V_2 -> V_77 ) ;
V_72 -> V_66 = F_18 ( V_72 -> V_25 ,
V_72 -> V_80 ) ;
V_72 -> V_34 = F_27 ( V_2 , V_72 -> V_80 ) ;
if ( V_72 -> V_34 < 0 )
return V_72 -> V_34 ;
return 0 ;
}
static void F_39 ( struct V_1 * V_2 ,
struct V_71 * V_72 )
{
T_1 V_5 = 0 ;
int V_81 ;
int V_82 = 128 ; ;
V_81 = ( V_72 -> V_34 - V_2 -> V_57 ) * V_82 / V_2 -> V_83 ;
V_81 = F_40 ( V_81 , V_84 , V_85 ) ;
V_5 |= V_72 -> V_79 << V_86 ;
V_5 |= V_72 -> V_25 << V_87 ;
V_5 |= ( ( T_1 ) V_81 << V_88 ) &
V_89 ;
V_5 |= V_90 | V_91 ;
F_3 ( V_2 , V_5 , V_92 ) ;
F_6 ( V_2 ) ;
}
static int F_41 ( struct V_1 * V_2 , unsigned long V_66 )
{
int V_13 ;
struct V_71 V_72 ;
if ( V_2 -> V_9 == V_93 ) {
F_14 ( V_2 -> V_12 , L_6 ,
V_75 , V_94 [ V_2 -> V_9 ] ) ;
return - V_95 ;
}
V_13 = F_35 ( V_2 , & V_72 , V_66 ) ;
if ( V_13 )
return V_13 ;
V_2 -> V_96 = V_66 ;
V_2 -> V_97 = V_72 ;
if ( V_2 -> V_9 == V_98 )
F_39 ( V_2 , & V_2 -> V_97 ) ;
return 0 ;
}
static int F_42 ( struct V_1 * V_2 )
{
if ( V_2 -> V_9 != V_10 ) {
F_14 ( V_2 -> V_12 , L_7 ,
V_94 [ V_2 -> V_9 ] ) ;
return - V_76 ;
}
F_19 ( V_2 , V_99 ) ;
F_43 ( V_2 -> V_12 ) ;
return 0 ;
}
static int F_44 ( struct V_1 * V_2 )
{
if ( V_2 -> V_9 != V_99 ) {
F_14 ( V_2 -> V_12 , L_8 ,
V_94 [ V_2 -> V_9 ] ) ;
return - V_95 ;
}
F_45 ( V_2 -> V_12 ) ;
F_19 ( V_2 , V_10 ) ;
return 0 ;
}
static void F_46 ( struct V_1 * V_2 )
{
T_1 V_5 ;
if ( V_2 -> V_17 != V_18 )
F_17 ( V_2 ) ;
V_5 = F_1 ( V_2 , V_92 ) ;
V_5 |= V_100 ;
V_5 &= ~ V_91 ;
F_3 ( V_2 , V_5 , V_92 ) ;
F_6 ( V_2 ) ;
}
static int F_47 ( struct V_1 * V_2 )
{
struct V_71 * V_72 = & V_2 -> V_97 ;
switch ( V_2 -> V_9 ) {
case V_98 :
return 0 ;
case V_10 :
if ( V_72 -> V_66 == 0 ) {
F_14 ( V_2 -> V_12 , L_9 ,
V_75 ) ;
return - V_76 ;
}
F_20 ( V_2 , true ) ;
F_19 ( V_2 , V_98 ) ;
F_39 ( V_2 , V_72 ) ;
return 0 ;
default:
F_25 ( V_2 -> V_9 > V_98 ) ;
F_14 ( V_2 -> V_12 , L_10 ,
V_75 , V_94 [ V_2 -> V_9 ] ) ;
return - V_95 ;
}
}
static int F_48 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_9 ) {
case V_98 :
F_46 ( V_2 ) ;
F_19 ( V_2 , V_10 ) ;
F_20 ( V_2 , false ) ;
return 0 ;
case V_10 :
return 0 ;
default:
F_25 ( V_2 -> V_9 > V_98 ) ;
F_14 ( V_2 -> V_12 , L_11 ,
V_75 , V_94 [ V_2 -> V_9 ] ) ;
return - V_95 ;
}
}
static int F_49 ( struct V_101 * V_102 )
{
struct V_1 * V_2 = F_50 ( V_102 ) ;
return F_10 ( V_2 ) ;
}
static int F_51 ( struct V_101 * V_102 )
{
struct V_1 * V_2 = F_50 ( V_102 ) ;
int V_13 ;
V_13 = F_44 ( V_2 ) ;
if ( V_13 )
return V_13 ;
V_13 = F_47 ( V_2 ) ;
if ( V_13 )
F_42 ( V_2 ) ;
return V_13 ;
}
static void F_52 ( struct V_101 * V_102 )
{
struct V_1 * V_2 = F_50 ( V_102 ) ;
int V_13 ;
V_13 = F_48 ( V_2 ) ;
if ( ! V_13 )
F_42 ( V_2 ) ;
}
static unsigned long F_53 ( struct V_101 * V_102 ,
unsigned long V_103 )
{
struct V_1 * V_2 = F_50 ( V_102 ) ;
return V_2 -> V_96 ;
}
static int F_54 ( struct V_101 * V_102 ,
struct V_104 * V_105 )
{
struct V_1 * V_2 = F_50 ( V_102 ) ;
struct V_71 V_72 ;
int V_13 ;
V_13 = F_35 ( V_2 , & V_72 , V_105 -> V_66 ) ;
if ( V_13 )
return V_13 ;
return 0 ;
}
static int F_55 ( struct V_101 * V_102 , unsigned long V_66 ,
unsigned long V_103 )
{
struct V_1 * V_2 = F_50 ( V_102 ) ;
return F_41 ( V_2 , V_66 ) ;
}
static int F_56 ( struct V_1 * V_2 )
{
int V_13 ;
V_106 . V_107 = V_2 -> V_108 ;
V_2 -> V_109 . V_110 = & V_106 ;
V_2 -> V_111 = F_57 ( V_2 -> V_12 , & V_2 -> V_109 ) ;
if ( F_30 ( V_2 -> V_111 ) ) {
F_14 ( V_2 -> V_12 , L_12 ) ;
return - V_76 ;
}
V_13 = F_58 ( V_2 -> V_12 -> V_112 , V_113 ,
V_2 -> V_111 ) ;
if ( V_13 ) {
F_14 ( V_2 -> V_12 , L_13 ) ;
F_59 ( V_2 -> V_111 ) ;
return V_13 ;
}
return 0 ;
}
static void F_60 ( struct V_1 * V_2 )
{
F_61 ( V_2 -> V_12 -> V_112 ) ;
F_59 ( V_2 -> V_111 ) ;
V_2 -> V_111 = NULL ;
}
static V_27 F_62 ( T_1 V_114 ,
unsigned long V_77 )
{
return V_114 * ( V_77 / V_115 ) ;
}
static V_27 F_63 ( struct V_1 * V_2 )
{
T_1 V_116 , V_117 ;
V_27 V_118 , V_119 ;
if ( ! F_10 ( V_2 ) )
return 0 ;
V_116 = F_1 ( V_2 , V_120 ) ;
V_116 = ( V_116 & V_121 ) >> V_122 ;
V_118 = F_62 ( V_116 , V_2 -> V_77 ) ;
V_117 = F_1 ( V_2 , V_92 ) ;
V_117 = ( V_117 & V_100 ) >> V_87 ;
V_119 = F_18 ( V_117 , V_118 ) ;
return V_119 ;
}
static int F_64 ( void * V_123 , V_27 * V_5 )
{
struct V_1 * V_2 = V_123 ;
* V_5 = F_10 ( V_2 ) ;
return 0 ;
}
static int F_65 ( void * V_123 , V_27 V_5 )
{
struct V_1 * V_2 = V_123 ;
return V_5 ? F_44 ( V_2 ) : F_42 ( V_2 ) ;
}
static int F_66 ( void * V_123 , V_27 * V_5 )
{
struct V_1 * V_2 = V_123 ;
* V_5 = ( V_2 -> V_9 == V_98 ) ;
return 0 ;
}
static int F_67 ( void * V_123 , V_27 V_5 )
{
struct V_1 * V_2 = V_123 ;
return V_5 ? F_47 ( V_2 ) : F_48 ( V_2 ) ;
}
static int F_68 ( void * V_123 , V_27 * V_5 )
{
struct V_1 * V_2 = V_123 ;
* V_5 = F_63 ( V_2 ) ;
return 0 ;
}
static int F_69 ( void * V_123 , V_27 V_5 )
{
struct V_1 * V_2 = V_123 ;
return F_41 ( V_2 , V_5 ) ;
}
static int F_70 ( struct V_124 * V_117 , void * V_123 )
{
T_1 V_5 , V_3 ;
struct V_1 * V_2 = V_117 -> V_125 ;
F_71 ( V_117 , L_14 ) ;
for ( V_3 = 0 ; V_3 <= V_120 ; V_3 += 4 ) {
if ( V_3 == V_31 )
V_5 = F_7 ( V_2 , V_3 ) ;
else
V_5 = F_1 ( V_2 , V_3 ) ;
F_72 ( V_117 , L_15 , V_3 , V_5 ) ;
}
F_71 ( V_117 , L_16 ) ;
for ( V_3 = V_6 ; V_3 <= V_126 ; V_3 += 4 )
F_72 ( V_117 , L_15 , V_3 ,
F_7 ( V_2 , V_3 ) ) ;
for ( V_3 = V_65 ; V_3 <= V_62 ; V_3 += 4 )
F_72 ( V_117 , L_15 , V_3 ,
F_7 ( V_2 , V_3 ) ) ;
F_71 ( V_117 , L_17 ) ;
V_3 = V_55 ;
F_72 ( V_117 , L_15 , V_3 ,
F_2 ( V_2 -> V_54 + V_3 ) ) ;
F_71 ( V_117 , L_18 ) ;
for ( V_3 = 0 ; V_3 < 4 * V_35 ; V_3 += 4 )
F_72 ( V_117 , L_15 , V_3 ,
F_2 ( V_2 -> V_40 + V_3 ) ) ;
return 0 ;
}
static int F_73 ( struct V_127 * V_127 , struct V_128 * V_128 )
{
return F_74 ( V_128 , F_70 , V_127 -> V_129 ) ;
}
static int F_75 ( struct V_1 * V_2 )
{
int V_13 ;
if ( ! V_2 || ( V_2 -> V_9 == V_93 ) )
return 0 ;
V_2 -> V_130 = F_76 ( L_19 , NULL ) ;
if ( ! V_2 -> V_130 )
return - V_131 ;
V_13 = - V_131 ;
if ( ! F_77 ( L_20 , V_132 | V_133 ,
V_2 -> V_130 , V_2 , & V_134 ) )
goto V_135;
if ( ! F_77 ( L_21 , V_132 ,
V_2 -> V_130 , V_2 , & V_136 ) )
goto V_135;
if ( ! F_77 ( L_22 , V_132 ,
V_2 -> V_130 , V_2 , & V_137 ) )
goto V_135;
if ( ! F_77 ( L_23 , V_132 ,
V_2 -> V_130 , V_2 , & V_138 ) )
goto V_135;
return 0 ;
V_135:
F_78 ( V_2 -> V_130 ) ;
return V_13 ;
}
static void F_79 ( struct V_1 * V_2 )
{
T_1 V_5 ;
V_5 = F_24 ( V_2 -> V_77 , V_2 -> V_139 * 32 ) ;
F_25 ( V_5 > V_140 ) ;
F_3 ( V_2 , V_5 , V_141 ) ;
V_5 = ( V_2 -> V_142 << V_143 ) |
( V_2 -> V_144 << V_145 ) |
( V_2 -> V_146 << V_147 ) |
( V_2 -> V_83 << V_148 ) |
( V_2 -> V_149 ? V_150 : 0 ) ;
F_3 ( V_2 , V_5 , V_151 ) ;
F_17 ( V_2 ) ;
F_3 ( V_2 , V_2 -> V_152 , V_153 ) ;
F_3 ( V_2 , V_154 , V_155 ) ;
}
static int F_80 ( struct V_1 * V_2 )
{
V_2 -> V_14 = F_81 ( V_2 -> V_12 , L_24 ) ;
if ( F_30 ( V_2 -> V_14 ) ) {
F_14 ( V_2 -> V_12 , L_25 ) ;
return F_32 ( V_2 -> V_14 ) ;
}
V_2 -> V_15 = F_81 ( V_2 -> V_12 , L_26 ) ;
if ( F_30 ( V_2 -> V_15 ) ) {
F_14 ( V_2 -> V_12 , L_27 ) ;
return F_32 ( V_2 -> V_15 ) ;
}
V_2 -> V_16 = F_81 ( V_2 -> V_12 , L_28 ) ;
if ( F_30 ( V_2 -> V_16 ) ) {
F_14 ( V_2 -> V_12 , L_29 ) ;
return F_32 ( V_2 -> V_16 ) ;
}
V_2 -> V_49 = F_82 ( V_2 -> V_16 ) ;
return 0 ;
}
static int F_83 ( struct V_1 * V_2 )
{
int V_13 ;
V_2 -> V_77 = F_82 ( V_2 -> V_14 ) ;
if ( V_2 -> V_77 != V_156 ) {
F_14 ( V_2 -> V_12 , L_30 ,
V_2 -> V_77 , V_156 ) ;
return - V_76 ;
}
F_84 ( V_2 -> V_157 ) ;
V_13 = F_85 ( V_2 -> V_14 ) ;
if ( V_13 ) {
F_14 ( V_2 -> V_12 , L_31 ) ;
return V_13 ;
}
V_13 = F_85 ( V_2 -> V_15 ) ;
if ( V_13 ) {
F_14 ( V_2 -> V_12 , L_32 ) ;
goto V_158;
}
V_13 = F_85 ( V_2 -> V_16 ) ;
if ( V_13 ) {
F_14 ( V_2 -> V_12 , L_33 ) ;
goto V_159;
}
V_2 -> V_96 = 0 ;
F_86 ( V_2 -> V_12 ) ;
F_45 ( V_2 -> V_12 ) ;
F_19 ( V_2 , V_99 ) ;
F_79 ( V_2 ) ;
if ( V_2 -> V_19 -> V_160 )
V_2 -> V_19 -> V_160 () ;
F_46 ( V_2 ) ;
F_26 ( V_2 ) ;
F_43 ( V_2 -> V_12 ) ;
return 0 ;
V_159:
F_87 ( V_2 -> V_15 ) ;
V_158:
F_87 ( V_2 -> V_14 ) ;
F_88 ( V_2 -> V_157 ) ;
return V_13 ;
}
static int F_89 ( struct V_1 * V_2 , int V_161 )
{
int V_33 , V_162 , V_163 ;
V_162 = F_90 ( V_2 -> V_38 ) ;
for ( V_33 = 0 ; V_33 < V_162 ; V_33 ++ ) {
V_163 = F_34 ( V_2 -> V_38 , V_33 ) ;
if ( V_163 < 0 )
break;
if ( V_161 == V_163 )
return V_33 ;
}
F_14 ( V_2 -> V_12 , L_34 , V_161 ) ;
return - V_76 ;
}
static int F_91 ( struct V_1 * V_2 , int V_161 )
{
int V_33 , V_162 , V_163 ;
V_162 = F_90 ( V_2 -> V_38 ) ;
for ( V_33 = 0 ; V_33 < V_162 ; V_33 ++ ) {
V_163 = F_34 ( V_2 -> V_38 , V_33 ) ;
if ( V_163 < 0 )
break;
if ( V_161 <= V_163 )
return V_33 ;
}
F_14 ( V_2 -> V_12 , L_35 , V_161 ) ;
return - V_76 ;
}
static int F_92 ( struct V_1 * V_2 )
{
int V_13 = - V_76 ;
int V_164 , V_116 , V_165 , V_166 ;
int V_167 ;
unsigned long V_66 ;
struct V_67 * V_68 ;
int V_168 ;
F_28 () ;
V_66 = V_169 ;
V_68 = F_93 ( V_2 -> V_19 -> V_12 , & V_66 ) ;
if ( F_30 ( V_68 ) ) {
F_14 ( V_2 -> V_12 , L_36 ) ;
goto V_170;
}
V_165 = F_33 ( V_68 ) ;
V_116 = V_2 -> V_19 -> V_171 * 1000 ;
V_168 = F_89 ( V_2 , V_116 ) ;
if ( V_168 < 0 )
goto V_170;
V_2 -> V_39 [ 0 ] = V_168 ;
for ( V_164 = 1 , V_66 = 0 ; ; V_66 ++ ) {
V_68 = F_29 ( V_2 -> V_19 -> V_12 , & V_66 ) ;
if ( F_30 ( V_68 ) )
break;
V_166 = F_33 ( V_68 ) ;
if ( V_166 <= V_2 -> V_19 -> V_171 * 1000 )
V_2 -> V_73 = F_94 ( V_68 ) ;
for (; ; ) {
V_116 += F_95 ( 1 , ( V_165 - V_116 ) / ( V_35 - V_164 ) ) ;
if ( V_116 >= V_166 )
break;
V_167 = F_91 ( V_2 , V_116 ) ;
if ( V_167 < 0 )
goto V_170;
if ( V_167 != V_2 -> V_39 [ V_164 - 1 ] )
V_2 -> V_39 [ V_164 ++ ] = V_167 ;
}
V_116 = ( V_164 == V_35 - 1 ) ? V_165 : V_166 ;
V_167 = F_89 ( V_2 , V_116 ) ;
if ( V_167 < 0 )
goto V_170;
if ( V_167 != V_2 -> V_39 [ V_164 - 1 ] )
V_2 -> V_39 [ V_164 ++ ] = V_167 ;
if ( V_116 >= V_165 )
break;
}
V_2 -> V_56 = V_164 ;
if ( ! V_2 -> V_73 )
F_14 ( V_2 -> V_12 , L_37 ,
V_2 -> V_19 -> V_171 ) ;
else
V_13 = 0 ;
V_170:
F_31 () ;
return V_13 ;
}
static bool F_96 ( struct V_1 * V_2 , const char * V_172 , T_1 * V_173 )
{
int V_174 = F_97 ( V_2 -> V_12 -> V_112 , V_172 , V_173 ) ;
if ( V_174 < 0 ) {
F_14 ( V_2 -> V_12 , L_38 ,
V_172 , V_174 ) ;
return false ;
}
return true ;
}
static int F_98 ( struct V_1 * V_2 )
{
struct V_175 * V_175 ;
struct V_11 * V_176 ;
struct V_177 * V_177 ;
int V_178 , V_179 ;
int V_13 ;
if ( ! F_96 ( V_2 , L_39 , & V_2 -> V_50 ) )
return - V_76 ;
V_175 = F_99 ( V_2 -> V_38 ) ;
V_176 = F_100 ( V_175 ) ;
V_177 = F_101 ( V_176 ) ;
V_2 -> V_41 = V_177 -> V_180 ;
V_13 = F_102 ( V_2 -> V_38 ,
& V_178 ,
& V_179 ) ;
if ( V_13 < 0 ) {
F_14 ( V_2 -> V_12 ,
L_40 ) ;
return - V_76 ;
}
V_2 -> V_47 = V_178 ;
V_13 = F_92 ( V_2 ) ;
if ( V_13 ) {
F_14 ( V_2 -> V_12 , L_41 ) ;
return V_13 ;
}
return 0 ;
}
static int F_103 ( struct V_1 * V_2 )
{
bool V_181 = true ;
V_181 &= F_96 ( V_2 , L_42 , & V_2 -> V_152 ) ;
V_181 &= F_96 ( V_2 , L_43 , & V_2 -> V_139 ) ;
V_181 &= F_96 ( V_2 , L_44 , & V_2 -> V_142 ) ;
V_181 &= F_96 ( V_2 , L_45 , & V_2 -> V_144 ) ;
V_181 &= F_96 ( V_2 , L_46 , & V_2 -> V_146 ) ;
V_181 &= F_96 ( V_2 , L_47 , & V_2 -> V_83 ) ;
V_2 -> V_149 = F_104 ( V_2 -> V_12 -> V_112 ,
L_48 ) ;
if ( F_105 ( V_2 -> V_12 -> V_112 , L_49 ,
& V_2 -> V_108 ) ) {
F_14 ( V_2 -> V_12 , L_50 ) ;
V_181 = false ;
}
return V_181 ? 0 : - V_76 ;
}
int F_106 ( struct V_182 * V_183 ,
struct V_184 * V_19 )
{
struct V_185 * V_186 ;
struct V_1 * V_2 ;
int V_13 ;
if ( ! V_19 ) {
F_14 ( & V_183 -> V_12 , L_51 ) ;
return - V_76 ;
}
V_2 = F_107 ( & V_183 -> V_12 , sizeof( * V_2 ) , V_187 ) ;
if ( ! V_2 )
return - V_131 ;
V_2 -> V_12 = & V_183 -> V_12 ;
F_108 ( V_183 , V_2 ) ;
V_2 -> V_19 = V_19 ;
V_2 -> V_38 = F_109 ( V_2 -> V_12 , L_52 ) ;
if ( F_30 ( V_2 -> V_38 ) ) {
F_14 ( V_2 -> V_12 , L_53 ) ;
return F_32 ( V_2 -> V_38 ) ;
}
V_2 -> V_157 = F_110 ( V_2 -> V_12 , L_54 ) ;
if ( F_30 ( V_2 -> V_157 ) ) {
F_14 ( V_2 -> V_12 , L_55 ) ;
return F_32 ( V_2 -> V_157 ) ;
}
V_13 = F_103 ( V_2 ) ;
if ( V_13 ) {
F_14 ( V_2 -> V_12 , L_56 ) ;
return V_13 ;
}
V_13 = F_98 ( V_2 ) ;
if ( V_13 )
return V_13 ;
V_186 = F_111 ( V_183 , V_188 , 0 ) ;
if ( ! V_186 ) {
F_14 ( V_2 -> V_12 , L_57 ) ;
return - V_189 ;
}
V_2 -> V_4 = F_112 ( V_2 -> V_12 , V_186 -> V_190 , F_113 ( V_186 ) ) ;
if ( ! V_2 -> V_4 ) {
F_14 ( V_2 -> V_12 , L_58 ) ;
return - V_189 ;
}
V_186 = F_111 ( V_183 , V_188 , 1 ) ;
if ( ! V_186 ) {
F_14 ( V_2 -> V_12 , L_59 ) ;
return - V_189 ;
}
V_2 -> V_8 = F_112 ( V_2 -> V_12 , V_186 -> V_190 , F_113 ( V_186 ) ) ;
if ( ! V_2 -> V_8 ) {
F_14 ( V_2 -> V_12 , L_60 ) ;
return - V_189 ;
}
V_186 = F_111 ( V_183 , V_188 , 2 ) ;
if ( ! V_186 ) {
F_14 ( V_2 -> V_12 , L_61 ) ;
return - V_189 ;
}
V_2 -> V_54 = F_112 ( V_2 -> V_12 , V_186 -> V_190 ,
F_113 ( V_186 ) ) ;
if ( ! V_2 -> V_54 ) {
F_14 ( V_2 -> V_12 ,
L_62 ) ;
return - V_189 ;
}
V_186 = F_111 ( V_183 , V_188 , 3 ) ;
if ( ! V_186 ) {
F_14 ( V_2 -> V_12 , L_63 ) ;
return - V_189 ;
}
V_2 -> V_40 = F_112 ( V_2 -> V_12 , V_186 -> V_190 , F_113 ( V_186 ) ) ;
if ( ! V_2 -> V_40 ) {
F_14 ( V_2 -> V_12 ,
L_64 ) ;
return - V_189 ;
}
V_13 = F_80 ( V_2 ) ;
if ( V_13 ) {
F_14 ( & V_183 -> V_12 , L_65 ) ;
return V_13 ;
}
V_13 = F_83 ( V_2 ) ;
if ( V_13 )
return V_13 ;
V_13 = F_56 ( V_2 ) ;
if ( V_13 ) {
F_14 ( & V_183 -> V_12 , L_66 ) ;
return V_13 ;
}
#ifdef F_114
F_75 ( V_2 ) ;
#endif
return 0 ;
}
int F_115 ( struct V_182 * V_183 )
{
struct V_1 * V_2 = F_116 ( V_183 ) ;
if ( V_2 -> V_9 != V_99 ) {
F_14 ( & V_183 -> V_12 ,
L_67 ) ;
return - V_191 ;
}
F_78 ( V_2 -> V_130 ) ;
F_60 ( V_2 ) ;
F_117 ( & V_183 -> V_12 ) ;
F_87 ( V_2 -> V_14 ) ;
F_87 ( V_2 -> V_15 ) ;
F_87 ( V_2 -> V_16 ) ;
F_88 ( V_2 -> V_157 ) ;
return 0 ;
}
