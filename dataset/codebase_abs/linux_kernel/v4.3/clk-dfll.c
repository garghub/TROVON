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
static V_27 F_19 ( T_1 V_29 ,
unsigned long V_30 )
{
return V_29 * ( V_30 / V_31 ) ;
}
static V_27 F_20 ( struct V_1 * V_2 )
{
T_1 V_32 , V_33 ;
V_27 V_34 , V_35 ;
if ( ! F_10 ( V_2 ) )
return 0 ;
V_32 = F_1 ( V_2 , V_36 ) ;
V_32 = ( V_32 & V_37 ) >> V_38 ;
V_34 = F_19 ( V_32 , V_2 -> V_30 ) ;
V_33 = F_1 ( V_2 , V_39 ) ;
V_33 = ( V_33 & V_40 ) >> V_41 ;
V_35 = F_18 ( V_33 , V_34 ) ;
return V_35 ;
}
static void F_21 ( struct V_1 * V_2 ,
enum V_42 V_9 )
{
V_2 -> V_9 = V_9 ;
F_3 ( V_2 , V_9 - 1 , V_7 ) ;
F_6 ( V_2 ) ;
}
static int F_22 ( struct V_1 * V_2 , bool V_43 )
{
T_1 V_5 ;
V_5 = F_7 ( V_2 , V_44 ) ;
if ( V_43 )
V_5 |= V_45 ;
else
V_5 &= ~ V_45 ;
F_8 ( V_2 , V_5 , V_44 ) ;
F_9 ( V_2 ) ;
return 0 ;
}
static void F_23 ( struct V_1 * V_2 )
{
int V_46 , V_47 ;
T_1 V_5 ;
for ( V_46 = 0 ; V_46 < V_48 ; V_46 ++ ) {
if ( V_46 < V_2 -> V_49 )
V_47 = V_2 -> V_49 ;
else if ( V_46 > V_2 -> V_50 )
V_47 = V_2 -> V_50 ;
else
V_47 = V_46 ;
V_5 = F_24 ( V_2 -> V_51 ,
V_2 -> V_52 [ V_47 ] ) ;
F_5 ( V_5 , V_2 -> V_53 + V_46 * 4 ) ;
}
F_9 ( V_2 ) ;
}
static void F_25 ( struct V_1 * V_2 )
{
T_1 V_5 ;
if ( V_2 -> V_54 > 0x7f ) {
V_5 = V_2 -> V_54 << V_55 ;
V_5 |= V_56 ;
} else {
V_5 = V_2 -> V_54 << V_57 ;
}
V_5 |= V_58 ;
V_5 |= V_59 ;
F_8 ( V_2 , V_5 , V_6 ) ;
F_8 ( V_2 , V_2 -> V_60 , V_61 ) ;
V_5 = F_26 ( V_2 -> V_62 , V_2 -> V_63 * 8 ) ;
F_27 ( ! V_5 || ( V_5 > V_64 ) ) ;
V_5 = ( V_5 - 1 ) << V_65 ;
V_5 |= 1 << V_66 ;
F_5 ( V_5 , V_2 -> V_67 + V_68 ) ;
F_9 ( V_2 ) ;
}
static void F_28 ( struct V_1 * V_2 )
{
T_1 V_5 ;
V_2 -> V_49 = 0 ;
V_2 -> V_50 = V_2 -> V_69 - 1 ;
V_2 -> V_70 = V_2 -> V_49 + 1 ;
F_8 ( V_2 , 0 , V_44 ) ;
V_5 = ( V_2 -> V_70 << V_71 ) |
( V_2 -> V_50 << V_72 ) |
( V_2 -> V_49 << V_73 ) ;
F_8 ( V_2 , V_5 , V_44 ) ;
F_9 ( V_2 ) ;
F_3 ( V_2 , 0 , V_74 ) ;
F_8 ( V_2 , 0 , V_75 ) ;
F_8 ( V_2 , V_76 | V_77 ,
V_78 ) ;
F_23 ( V_2 ) ;
F_25 ( V_2 ) ;
}
static int F_29 ( struct V_1 * V_2 , unsigned long V_79 )
{
struct V_80 * V_81 ;
int V_46 , V_82 ;
F_30 () ;
V_81 = F_31 ( V_2 -> V_19 -> V_12 , & V_79 ) ;
if ( F_32 ( V_81 ) ) {
F_33 () ;
return F_34 ( V_81 ) ;
}
V_82 = F_35 ( V_81 ) ;
F_33 () ;
for ( V_46 = 0 ; V_46 < V_2 -> V_69 ; V_46 ++ ) {
if ( F_36 ( V_2 -> V_51 , V_2 -> V_52 [ V_46 ] ) == V_82 )
return V_46 ;
}
return - V_83 ;
}
static int F_37 ( struct V_1 * V_2 ,
struct V_84 * V_85 ,
unsigned long V_79 )
{
T_1 V_5 ;
V_85 -> V_25 = V_28 - 1 ;
if ( V_79 < V_2 -> V_86 ) {
int V_87 ;
V_87 = F_38 ( V_79 / 1000 * V_28 ,
V_2 -> V_86 / 1000 ) ;
if ( ! V_87 ) {
F_14 ( V_2 -> V_12 , L_4 ,
V_88 , V_79 ) ;
return - V_89 ;
}
V_85 -> V_25 = V_87 - 1 ;
V_79 = V_2 -> V_86 ;
}
V_5 = F_39 ( V_79 , V_2 -> V_30 ) ;
if ( V_5 > V_90 ) {
F_14 ( V_2 -> V_12 , L_5 ,
V_88 , V_79 ) ;
return - V_89 ;
}
V_85 -> V_91 = V_5 ;
V_85 -> V_92 = F_40 ( V_85 -> V_91 , V_2 -> V_30 ) ;
V_85 -> V_79 = F_18 ( V_85 -> V_25 ,
V_85 -> V_92 ) ;
V_85 -> V_47 = F_29 ( V_2 , V_85 -> V_92 ) ;
if ( V_85 -> V_47 < 0 )
return V_85 -> V_47 ;
return 0 ;
}
static void F_41 ( struct V_1 * V_2 ,
struct V_84 * V_85 )
{
T_1 V_5 = 0 ;
int V_93 ;
int V_94 = 128 ; ;
V_93 = ( V_85 -> V_47 - V_2 -> V_70 ) * V_94 / V_2 -> V_95 ;
V_93 = F_42 ( V_93 , V_96 , V_97 ) ;
V_5 |= V_85 -> V_91 << V_98 ;
V_5 |= V_85 -> V_25 << V_41 ;
V_5 |= ( ( T_1 ) V_93 << V_99 ) &
V_100 ;
V_5 |= V_101 | V_102 ;
F_3 ( V_2 , V_5 , V_39 ) ;
F_6 ( V_2 ) ;
}
static int F_43 ( struct V_1 * V_2 , unsigned long V_79 )
{
int V_13 ;
struct V_84 V_85 ;
if ( V_2 -> V_9 == V_103 ) {
F_14 ( V_2 -> V_12 , L_6 ,
V_88 , V_104 [ V_2 -> V_9 ] ) ;
return - V_105 ;
}
V_13 = F_37 ( V_2 , & V_85 , V_79 ) ;
if ( V_13 )
return V_13 ;
V_2 -> V_106 = V_79 ;
V_2 -> V_107 = V_85 ;
if ( V_2 -> V_9 == V_108 )
F_41 ( V_2 , & V_2 -> V_107 ) ;
return 0 ;
}
static int F_44 ( struct V_1 * V_2 )
{
if ( V_2 -> V_9 != V_10 ) {
F_14 ( V_2 -> V_12 , L_7 ,
V_104 [ V_2 -> V_9 ] ) ;
return - V_89 ;
}
F_21 ( V_2 , V_109 ) ;
F_45 ( V_2 -> V_12 ) ;
return 0 ;
}
static int F_46 ( struct V_1 * V_2 )
{
if ( V_2 -> V_9 != V_109 ) {
F_14 ( V_2 -> V_12 , L_8 ,
V_104 [ V_2 -> V_9 ] ) ;
return - V_105 ;
}
F_47 ( V_2 -> V_12 ) ;
F_21 ( V_2 , V_10 ) ;
return 0 ;
}
static void F_48 ( struct V_1 * V_2 )
{
T_1 V_5 ;
if ( V_2 -> V_17 != V_18 )
F_17 ( V_2 ) ;
V_5 = F_1 ( V_2 , V_39 ) ;
V_5 |= V_40 ;
V_5 &= ~ V_102 ;
F_3 ( V_2 , V_5 , V_39 ) ;
F_6 ( V_2 ) ;
}
static int F_49 ( struct V_1 * V_2 )
{
struct V_84 * V_85 = & V_2 -> V_107 ;
switch ( V_2 -> V_9 ) {
case V_108 :
return 0 ;
case V_10 :
if ( V_85 -> V_79 == 0 ) {
F_14 ( V_2 -> V_12 , L_9 ,
V_88 ) ;
return - V_89 ;
}
F_22 ( V_2 , true ) ;
F_21 ( V_2 , V_108 ) ;
F_41 ( V_2 , V_85 ) ;
return 0 ;
default:
F_27 ( V_2 -> V_9 > V_108 ) ;
F_14 ( V_2 -> V_12 , L_10 ,
V_88 , V_104 [ V_2 -> V_9 ] ) ;
return - V_105 ;
}
}
static int F_50 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_9 ) {
case V_108 :
F_48 ( V_2 ) ;
F_21 ( V_2 , V_10 ) ;
F_22 ( V_2 , false ) ;
return 0 ;
case V_10 :
return 0 ;
default:
F_27 ( V_2 -> V_9 > V_108 ) ;
F_14 ( V_2 -> V_12 , L_11 ,
V_88 , V_104 [ V_2 -> V_9 ] ) ;
return - V_105 ;
}
}
static int F_51 ( struct V_110 * V_111 )
{
struct V_1 * V_2 = F_52 ( V_111 ) ;
return F_10 ( V_2 ) ;
}
static int F_53 ( struct V_110 * V_111 )
{
struct V_1 * V_2 = F_52 ( V_111 ) ;
int V_13 ;
V_13 = F_46 ( V_2 ) ;
if ( V_13 )
return V_13 ;
V_13 = F_49 ( V_2 ) ;
if ( V_13 )
F_44 ( V_2 ) ;
return V_13 ;
}
static void F_54 ( struct V_110 * V_111 )
{
struct V_1 * V_2 = F_52 ( V_111 ) ;
int V_13 ;
V_13 = F_50 ( V_2 ) ;
if ( ! V_13 )
F_44 ( V_2 ) ;
}
static unsigned long F_55 ( struct V_110 * V_111 ,
unsigned long V_112 )
{
struct V_1 * V_2 = F_52 ( V_111 ) ;
return V_2 -> V_106 ;
}
static long F_56 ( struct V_110 * V_111 ,
unsigned long V_79 ,
unsigned long * V_112 )
{
struct V_1 * V_2 = F_52 ( V_111 ) ;
struct V_84 V_85 ;
int V_13 ;
V_13 = F_37 ( V_2 , & V_85 , V_79 ) ;
if ( V_13 )
return V_13 ;
return V_79 ;
}
static int F_57 ( struct V_110 * V_111 , unsigned long V_79 ,
unsigned long V_112 )
{
struct V_1 * V_2 = F_52 ( V_111 ) ;
return F_43 ( V_2 , V_79 ) ;
}
static int F_58 ( struct V_1 * V_2 )
{
int V_13 ;
V_113 . V_114 = V_2 -> V_115 ;
V_2 -> V_116 . V_117 = & V_113 ;
V_2 -> V_118 = F_59 ( V_2 -> V_12 , & V_2 -> V_116 ) ;
if ( F_32 ( V_2 -> V_118 ) ) {
F_14 ( V_2 -> V_12 , L_12 ) ;
return - V_89 ;
}
V_13 = F_60 ( V_2 -> V_12 -> V_119 , V_120 ,
V_2 -> V_118 ) ;
if ( V_13 ) {
F_14 ( V_2 -> V_12 , L_13 ) ;
F_61 ( V_2 -> V_118 ) ;
return V_13 ;
}
return 0 ;
}
static void F_62 ( struct V_1 * V_2 )
{
F_63 ( V_2 -> V_12 -> V_119 ) ;
F_61 ( V_2 -> V_118 ) ;
V_2 -> V_118 = NULL ;
}
static int F_64 ( void * V_121 , V_27 * V_5 )
{
struct V_1 * V_2 = V_121 ;
* V_5 = F_10 ( V_2 ) ;
return 0 ;
}
static int F_65 ( void * V_121 , V_27 V_5 )
{
struct V_1 * V_2 = V_121 ;
return V_5 ? F_46 ( V_2 ) : F_44 ( V_2 ) ;
}
static int F_66 ( void * V_121 , V_27 * V_5 )
{
struct V_1 * V_2 = V_121 ;
* V_5 = ( V_2 -> V_9 == V_108 ) ;
return 0 ;
}
static int F_67 ( void * V_121 , V_27 V_5 )
{
struct V_1 * V_2 = V_121 ;
return V_5 ? F_49 ( V_2 ) : F_50 ( V_2 ) ;
}
static int F_68 ( void * V_121 , V_27 * V_5 )
{
struct V_1 * V_2 = V_121 ;
* V_5 = F_20 ( V_2 ) ;
return 0 ;
}
static int F_69 ( void * V_121 , V_27 V_5 )
{
struct V_1 * V_2 = V_121 ;
return F_43 ( V_2 , V_5 ) ;
}
static int F_70 ( struct V_122 * V_33 , void * V_121 )
{
T_1 V_5 , V_3 ;
struct V_1 * V_2 = V_33 -> V_123 ;
F_71 ( V_33 , L_14 ) ;
for ( V_3 = 0 ; V_3 <= V_36 ; V_3 += 4 ) {
if ( V_3 == V_44 )
V_5 = F_7 ( V_2 , V_3 ) ;
else
V_5 = F_1 ( V_2 , V_3 ) ;
F_72 ( V_33 , L_15 , V_3 , V_5 ) ;
}
F_71 ( V_33 , L_16 ) ;
for ( V_3 = V_6 ; V_3 <= V_124 ; V_3 += 4 )
F_72 ( V_33 , L_15 , V_3 ,
F_7 ( V_2 , V_3 ) ) ;
for ( V_3 = V_78 ; V_3 <= V_75 ; V_3 += 4 )
F_72 ( V_33 , L_15 , V_3 ,
F_7 ( V_2 , V_3 ) ) ;
F_71 ( V_33 , L_17 ) ;
V_3 = V_68 ;
F_72 ( V_33 , L_15 , V_3 ,
F_2 ( V_2 -> V_67 + V_3 ) ) ;
F_71 ( V_33 , L_18 ) ;
for ( V_3 = 0 ; V_3 < 4 * V_48 ; V_3 += 4 )
F_72 ( V_33 , L_15 , V_3 ,
F_2 ( V_2 -> V_53 + V_3 ) ) ;
return 0 ;
}
static int F_73 ( struct V_125 * V_125 , struct V_126 * V_126 )
{
return F_74 ( V_126 , F_70 , V_125 -> V_127 ) ;
}
static int F_75 ( struct V_1 * V_2 )
{
int V_13 ;
if ( ! V_2 || ( V_2 -> V_9 == V_103 ) )
return 0 ;
V_2 -> V_128 = F_76 ( L_19 , NULL ) ;
if ( ! V_2 -> V_128 )
return - V_129 ;
V_13 = - V_129 ;
if ( ! F_77 ( L_20 , V_130 | V_131 ,
V_2 -> V_128 , V_2 , & V_132 ) )
goto V_133;
if ( ! F_77 ( L_21 , V_130 ,
V_2 -> V_128 , V_2 , & V_134 ) )
goto V_133;
if ( ! F_77 ( L_22 , V_130 ,
V_2 -> V_128 , V_2 , & V_135 ) )
goto V_133;
if ( ! F_77 ( L_23 , V_130 ,
V_2 -> V_128 , V_2 , & V_136 ) )
goto V_133;
return 0 ;
V_133:
F_78 ( V_2 -> V_128 ) ;
return V_13 ;
}
static void F_79 ( struct V_1 * V_2 )
{
T_1 V_5 ;
V_5 = F_26 ( V_2 -> V_30 , V_2 -> V_137 * 32 ) ;
F_27 ( V_5 > V_138 ) ;
F_3 ( V_2 , V_5 , V_139 ) ;
V_5 = ( V_2 -> V_140 << V_141 ) |
( V_2 -> V_142 << V_143 ) |
( V_2 -> V_144 << V_145 ) |
( V_2 -> V_95 << V_146 ) |
( V_2 -> V_147 ? V_148 : 0 ) ;
F_3 ( V_2 , V_5 , V_149 ) ;
F_17 ( V_2 ) ;
F_3 ( V_2 , V_2 -> V_150 , V_151 ) ;
F_3 ( V_2 , V_152 , V_153 ) ;
}
static int F_80 ( struct V_1 * V_2 )
{
V_2 -> V_14 = F_81 ( V_2 -> V_12 , L_24 ) ;
if ( F_32 ( V_2 -> V_14 ) ) {
F_14 ( V_2 -> V_12 , L_25 ) ;
return F_34 ( V_2 -> V_14 ) ;
}
V_2 -> V_15 = F_81 ( V_2 -> V_12 , L_26 ) ;
if ( F_32 ( V_2 -> V_15 ) ) {
F_14 ( V_2 -> V_12 , L_27 ) ;
return F_34 ( V_2 -> V_15 ) ;
}
V_2 -> V_16 = F_81 ( V_2 -> V_12 , L_28 ) ;
if ( F_32 ( V_2 -> V_16 ) ) {
F_14 ( V_2 -> V_12 , L_29 ) ;
return F_34 ( V_2 -> V_16 ) ;
}
V_2 -> V_62 = F_82 ( V_2 -> V_16 ) ;
return 0 ;
}
static int F_83 ( struct V_1 * V_2 )
{
int V_13 ;
V_2 -> V_30 = F_82 ( V_2 -> V_14 ) ;
if ( V_2 -> V_30 != V_154 ) {
F_14 ( V_2 -> V_12 , L_30 ,
V_2 -> V_30 , V_154 ) ;
return - V_89 ;
}
F_84 ( V_2 -> V_155 ) ;
V_13 = F_85 ( V_2 -> V_14 ) ;
if ( V_13 ) {
F_14 ( V_2 -> V_12 , L_31 ) ;
return V_13 ;
}
V_13 = F_85 ( V_2 -> V_15 ) ;
if ( V_13 ) {
F_14 ( V_2 -> V_12 , L_32 ) ;
goto V_156;
}
V_13 = F_85 ( V_2 -> V_16 ) ;
if ( V_13 ) {
F_14 ( V_2 -> V_12 , L_33 ) ;
goto V_157;
}
V_2 -> V_106 = 0 ;
F_86 ( V_2 -> V_12 ) ;
F_47 ( V_2 -> V_12 ) ;
F_21 ( V_2 , V_109 ) ;
F_79 ( V_2 ) ;
if ( V_2 -> V_19 -> V_158 )
V_2 -> V_19 -> V_158 () ;
F_48 ( V_2 ) ;
F_28 ( V_2 ) ;
F_45 ( V_2 -> V_12 ) ;
return 0 ;
V_157:
F_87 ( V_2 -> V_15 ) ;
V_156:
F_87 ( V_2 -> V_14 ) ;
F_88 ( V_2 -> V_155 ) ;
return V_13 ;
}
static int F_89 ( struct V_1 * V_2 , int V_159 )
{
int V_46 , V_160 , V_161 ;
V_160 = F_90 ( V_2 -> V_51 ) ;
for ( V_46 = 0 ; V_46 < V_160 ; V_46 ++ ) {
V_161 = F_36 ( V_2 -> V_51 , V_46 ) ;
if ( V_161 < 0 )
break;
if ( V_159 == V_161 )
return V_46 ;
}
F_14 ( V_2 -> V_12 , L_34 , V_159 ) ;
return - V_89 ;
}
static int F_91 ( struct V_1 * V_2 , int V_159 )
{
int V_46 , V_160 , V_161 ;
V_160 = F_90 ( V_2 -> V_51 ) ;
for ( V_46 = 0 ; V_46 < V_160 ; V_46 ++ ) {
V_161 = F_36 ( V_2 -> V_51 , V_46 ) ;
if ( V_161 < 0 )
break;
if ( V_159 <= V_161 )
return V_46 ;
}
F_14 ( V_2 -> V_12 , L_35 , V_159 ) ;
return - V_89 ;
}
static int F_92 ( struct V_1 * V_2 )
{
int V_13 = - V_89 ;
int V_162 , V_32 , V_163 , V_164 ;
int V_165 ;
unsigned long V_79 ;
struct V_80 * V_81 ;
int V_166 ;
F_30 () ;
V_79 = V_167 ;
V_81 = F_93 ( V_2 -> V_19 -> V_12 , & V_79 ) ;
if ( F_32 ( V_81 ) ) {
F_14 ( V_2 -> V_12 , L_36 ) ;
goto V_168;
}
V_163 = F_35 ( V_81 ) ;
V_32 = V_2 -> V_19 -> V_169 * 1000 ;
V_166 = F_89 ( V_2 , V_32 ) ;
if ( V_166 < 0 )
goto V_168;
V_2 -> V_52 [ 0 ] = V_166 ;
for ( V_162 = 1 , V_79 = 0 ; ; V_79 ++ ) {
V_81 = F_31 ( V_2 -> V_19 -> V_12 , & V_79 ) ;
if ( F_32 ( V_81 ) )
break;
V_164 = F_35 ( V_81 ) ;
if ( V_164 <= V_2 -> V_19 -> V_169 * 1000 )
V_2 -> V_86 = F_94 ( V_81 ) ;
for (; ; ) {
V_32 += F_95 ( 1 , ( V_163 - V_32 ) / ( V_48 - V_162 ) ) ;
if ( V_32 >= V_164 )
break;
V_165 = F_91 ( V_2 , V_32 ) ;
if ( V_165 < 0 )
goto V_168;
if ( V_165 != V_2 -> V_52 [ V_162 - 1 ] )
V_2 -> V_52 [ V_162 ++ ] = V_165 ;
}
V_32 = ( V_162 == V_48 - 1 ) ? V_163 : V_164 ;
V_165 = F_89 ( V_2 , V_32 ) ;
if ( V_165 < 0 )
goto V_168;
if ( V_165 != V_2 -> V_52 [ V_162 - 1 ] )
V_2 -> V_52 [ V_162 ++ ] = V_165 ;
if ( V_32 >= V_163 )
break;
}
V_2 -> V_69 = V_162 ;
if ( ! V_2 -> V_86 )
F_14 ( V_2 -> V_12 , L_37 ,
V_2 -> V_19 -> V_169 ) ;
else
V_13 = 0 ;
V_168:
F_33 () ;
return V_13 ;
}
static bool F_96 ( struct V_1 * V_2 , const char * V_170 , T_1 * V_171 )
{
int V_172 = F_97 ( V_2 -> V_12 -> V_119 , V_170 , V_171 ) ;
if ( V_172 < 0 ) {
F_14 ( V_2 -> V_12 , L_38 ,
V_170 , V_172 ) ;
return false ;
}
return true ;
}
static int F_98 ( struct V_1 * V_2 )
{
struct V_173 * V_173 ;
struct V_11 * V_174 ;
struct V_175 * V_175 ;
int V_176 , V_177 ;
int V_13 ;
if ( ! F_96 ( V_2 , L_39 , & V_2 -> V_63 ) )
return - V_89 ;
V_173 = F_99 ( V_2 -> V_51 ) ;
V_174 = F_100 ( V_173 ) ;
V_175 = F_101 ( V_174 ) ;
V_2 -> V_54 = V_175 -> V_178 ;
V_13 = F_102 ( V_2 -> V_51 ,
& V_176 ,
& V_177 ) ;
if ( V_13 < 0 ) {
F_14 ( V_2 -> V_12 ,
L_40 ) ;
return - V_89 ;
}
V_2 -> V_60 = V_176 ;
V_13 = F_92 ( V_2 ) ;
if ( V_13 ) {
F_14 ( V_2 -> V_12 , L_41 ) ;
return V_13 ;
}
return 0 ;
}
static int F_103 ( struct V_1 * V_2 )
{
bool V_179 = true ;
V_179 &= F_96 ( V_2 , L_42 , & V_2 -> V_150 ) ;
V_179 &= F_96 ( V_2 , L_43 , & V_2 -> V_137 ) ;
V_179 &= F_96 ( V_2 , L_44 , & V_2 -> V_140 ) ;
V_179 &= F_96 ( V_2 , L_45 , & V_2 -> V_142 ) ;
V_179 &= F_96 ( V_2 , L_46 , & V_2 -> V_144 ) ;
V_179 &= F_96 ( V_2 , L_47 , & V_2 -> V_95 ) ;
V_2 -> V_147 = F_104 ( V_2 -> V_12 -> V_119 ,
L_48 ) ;
if ( F_105 ( V_2 -> V_12 -> V_119 , L_49 ,
& V_2 -> V_115 ) ) {
F_14 ( V_2 -> V_12 , L_50 ) ;
V_179 = false ;
}
return V_179 ? 0 : - V_89 ;
}
int F_106 ( struct V_180 * V_181 ,
struct V_182 * V_19 )
{
struct V_183 * V_184 ;
struct V_1 * V_2 ;
int V_13 ;
if ( ! V_19 ) {
F_14 ( & V_181 -> V_12 , L_51 ) ;
return - V_89 ;
}
V_2 = F_107 ( & V_181 -> V_12 , sizeof( * V_2 ) , V_185 ) ;
if ( ! V_2 )
return - V_129 ;
V_2 -> V_12 = & V_181 -> V_12 ;
F_108 ( V_181 , V_2 ) ;
V_2 -> V_19 = V_19 ;
V_2 -> V_51 = F_109 ( V_2 -> V_12 , L_52 ) ;
if ( F_32 ( V_2 -> V_51 ) ) {
F_14 ( V_2 -> V_12 , L_53 ) ;
return F_34 ( V_2 -> V_51 ) ;
}
V_2 -> V_155 = F_110 ( V_2 -> V_12 , L_54 ) ;
if ( F_32 ( V_2 -> V_155 ) ) {
F_14 ( V_2 -> V_12 , L_55 ) ;
return F_34 ( V_2 -> V_155 ) ;
}
V_13 = F_103 ( V_2 ) ;
if ( V_13 ) {
F_14 ( V_2 -> V_12 , L_56 ) ;
return V_13 ;
}
V_13 = F_98 ( V_2 ) ;
if ( V_13 )
return V_13 ;
V_184 = F_111 ( V_181 , V_186 , 0 ) ;
if ( ! V_184 ) {
F_14 ( V_2 -> V_12 , L_57 ) ;
return - V_187 ;
}
V_2 -> V_4 = F_112 ( V_2 -> V_12 , V_184 -> V_188 , F_113 ( V_184 ) ) ;
if ( ! V_2 -> V_4 ) {
F_14 ( V_2 -> V_12 , L_58 ) ;
return - V_187 ;
}
V_184 = F_111 ( V_181 , V_186 , 1 ) ;
if ( ! V_184 ) {
F_14 ( V_2 -> V_12 , L_59 ) ;
return - V_187 ;
}
V_2 -> V_8 = F_112 ( V_2 -> V_12 , V_184 -> V_188 , F_113 ( V_184 ) ) ;
if ( ! V_2 -> V_8 ) {
F_14 ( V_2 -> V_12 , L_60 ) ;
return - V_187 ;
}
V_184 = F_111 ( V_181 , V_186 , 2 ) ;
if ( ! V_184 ) {
F_14 ( V_2 -> V_12 , L_61 ) ;
return - V_187 ;
}
V_2 -> V_67 = F_112 ( V_2 -> V_12 , V_184 -> V_188 ,
F_113 ( V_184 ) ) ;
if ( ! V_2 -> V_67 ) {
F_14 ( V_2 -> V_12 ,
L_62 ) ;
return - V_187 ;
}
V_184 = F_111 ( V_181 , V_186 , 3 ) ;
if ( ! V_184 ) {
F_14 ( V_2 -> V_12 , L_63 ) ;
return - V_187 ;
}
V_2 -> V_53 = F_112 ( V_2 -> V_12 , V_184 -> V_188 , F_113 ( V_184 ) ) ;
if ( ! V_2 -> V_53 ) {
F_14 ( V_2 -> V_12 ,
L_64 ) ;
return - V_187 ;
}
V_13 = F_80 ( V_2 ) ;
if ( V_13 ) {
F_14 ( & V_181 -> V_12 , L_65 ) ;
return V_13 ;
}
V_13 = F_83 ( V_2 ) ;
if ( V_13 )
return V_13 ;
V_13 = F_58 ( V_2 ) ;
if ( V_13 ) {
F_14 ( & V_181 -> V_12 , L_66 ) ;
return V_13 ;
}
#ifdef F_114
F_75 ( V_2 ) ;
#endif
return 0 ;
}
int F_115 ( struct V_180 * V_181 )
{
struct V_1 * V_2 = F_116 ( V_181 ) ;
if ( V_2 -> V_9 != V_109 ) {
F_14 ( & V_181 -> V_12 ,
L_67 ) ;
return - V_189 ;
}
F_78 ( V_2 -> V_128 ) ;
F_62 ( V_2 ) ;
F_117 ( & V_181 -> V_12 ) ;
F_87 ( V_2 -> V_14 ) ;
F_87 ( V_2 -> V_15 ) ;
F_87 ( V_2 -> V_16 ) ;
F_88 ( V_2 -> V_155 ) ;
return 0 ;
}
