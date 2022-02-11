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
F_3 ( V_2 , V_2 -> V_19 -> V_20 -> V_21 . V_22 , V_23 ) ;
F_3 ( V_2 , V_2 -> V_19 -> V_20 -> V_21 . V_24 , V_25 ) ;
F_6 ( V_2 ) ;
if ( V_2 -> V_19 -> V_26 )
V_2 -> V_19 -> V_26 () ;
}
static unsigned long F_18 ( int V_27 ,
unsigned long V_28 )
{
return ( V_29 ) V_28 * ( V_27 + 1 ) / V_30 ;
}
static void F_19 ( struct V_1 * V_2 ,
enum V_31 V_9 )
{
V_2 -> V_9 = V_9 ;
F_3 ( V_2 , V_9 - 1 , V_7 ) ;
F_6 ( V_2 ) ;
}
static int F_20 ( struct V_1 * V_2 , bool V_32 )
{
T_1 V_5 ;
V_5 = F_7 ( V_2 , V_33 ) ;
if ( V_32 )
V_5 |= V_34 ;
else
V_5 &= ~ V_34 ;
F_8 ( V_2 , V_5 , V_33 ) ;
F_9 ( V_2 ) ;
return 0 ;
}
static void F_21 ( struct V_1 * V_2 )
{
int V_35 , V_36 ;
T_1 V_5 ;
for ( V_35 = 0 ; V_35 < V_37 ; V_35 ++ ) {
if ( V_35 < V_2 -> V_38 )
V_36 = V_2 -> V_38 ;
else if ( V_35 > V_2 -> V_39 )
V_36 = V_2 -> V_39 ;
else
V_36 = V_35 ;
V_5 = F_22 ( V_2 -> V_40 ,
V_2 -> V_41 [ V_36 ] ) ;
F_5 ( V_5 , V_2 -> V_42 + V_35 * 4 ) ;
}
F_9 ( V_2 ) ;
}
static void F_23 ( struct V_1 * V_2 )
{
T_1 V_5 ;
if ( V_2 -> V_43 > 0x7f ) {
V_5 = V_2 -> V_43 << V_44 ;
V_5 |= V_45 ;
} else {
V_5 = V_2 -> V_43 << V_46 ;
}
V_5 |= V_47 ;
V_5 |= V_48 ;
F_8 ( V_2 , V_5 , V_6 ) ;
F_8 ( V_2 , V_2 -> V_49 , V_50 ) ;
V_5 = F_24 ( V_2 -> V_51 , V_2 -> V_52 * 8 ) ;
F_25 ( ! V_5 || ( V_5 > V_53 ) ) ;
V_5 = ( V_5 - 1 ) << V_54 ;
V_5 |= 1 << V_55 ;
F_5 ( V_5 , V_2 -> V_56 + V_57 ) ;
F_9 ( V_2 ) ;
}
static void F_26 ( struct V_1 * V_2 )
{
T_1 V_5 ;
V_2 -> V_38 = 0 ;
V_2 -> V_39 = V_2 -> V_58 - 1 ;
V_2 -> V_59 = V_2 -> V_38 + 1 ;
F_8 ( V_2 , 0 , V_33 ) ;
V_5 = ( V_2 -> V_59 << V_60 ) |
( V_2 -> V_39 << V_61 ) |
( V_2 -> V_38 << V_62 ) ;
F_8 ( V_2 , V_5 , V_33 ) ;
F_9 ( V_2 ) ;
F_3 ( V_2 , 0 , V_63 ) ;
F_8 ( V_2 , 0 , V_64 ) ;
F_8 ( V_2 , V_65 | V_66 ,
V_67 ) ;
F_21 ( V_2 ) ;
F_23 ( V_2 ) ;
}
static int F_27 ( struct V_1 * V_2 , unsigned long V_68 )
{
struct V_69 * V_70 ;
int V_35 , V_71 ;
F_28 () ;
V_70 = F_29 ( V_2 -> V_19 -> V_12 , & V_68 ) ;
if ( F_30 ( V_70 ) ) {
F_31 () ;
return F_32 ( V_70 ) ;
}
V_71 = F_33 ( V_70 ) ;
F_31 () ;
for ( V_35 = 0 ; V_35 < V_2 -> V_58 ; V_35 ++ ) {
if ( F_34 ( V_2 -> V_40 , V_2 -> V_41 [ V_35 ] ) == V_71 )
return V_35 ;
}
return - V_72 ;
}
static int F_35 ( struct V_1 * V_2 ,
struct V_73 * V_74 ,
unsigned long V_68 )
{
T_1 V_5 ;
V_74 -> V_27 = V_30 - 1 ;
if ( V_68 < V_2 -> V_75 ) {
int V_76 ;
V_76 = F_36 ( V_68 / 1000 * V_30 ,
V_2 -> V_75 / 1000 ) ;
if ( ! V_76 ) {
F_14 ( V_2 -> V_12 , L_4 ,
V_77 , V_68 ) ;
return - V_78 ;
}
V_74 -> V_27 = V_76 - 1 ;
V_68 = V_2 -> V_75 ;
}
V_5 = F_37 ( V_68 , V_2 -> V_79 ) ;
if ( V_5 > V_80 ) {
F_14 ( V_2 -> V_12 , L_5 ,
V_77 , V_68 ) ;
return - V_78 ;
}
V_74 -> V_81 = V_5 ;
V_74 -> V_82 = F_38 ( V_74 -> V_81 , V_2 -> V_79 ) ;
V_74 -> V_68 = F_18 ( V_74 -> V_27 ,
V_74 -> V_82 ) ;
V_74 -> V_36 = F_27 ( V_2 , V_74 -> V_82 ) ;
if ( V_74 -> V_36 < 0 )
return V_74 -> V_36 ;
return 0 ;
}
static void F_39 ( struct V_1 * V_2 ,
struct V_73 * V_74 )
{
T_1 V_5 = 0 ;
int V_83 ;
int V_84 = 128 ; ;
V_83 = ( V_74 -> V_36 - V_2 -> V_59 ) * V_84 / V_2 -> V_85 ;
V_83 = F_40 ( V_83 , V_86 , V_87 ) ;
V_5 |= V_74 -> V_81 << V_88 ;
V_5 |= V_74 -> V_27 << V_89 ;
V_5 |= ( ( T_1 ) V_83 << V_90 ) &
V_91 ;
V_5 |= V_92 | V_93 ;
F_3 ( V_2 , V_5 , V_94 ) ;
F_6 ( V_2 ) ;
}
static int F_41 ( struct V_1 * V_2 , unsigned long V_68 )
{
int V_13 ;
struct V_73 V_74 ;
if ( V_2 -> V_9 == V_95 ) {
F_14 ( V_2 -> V_12 , L_6 ,
V_77 , V_96 [ V_2 -> V_9 ] ) ;
return - V_97 ;
}
V_13 = F_35 ( V_2 , & V_74 , V_68 ) ;
if ( V_13 )
return V_13 ;
V_2 -> V_98 = V_68 ;
V_2 -> V_99 = V_74 ;
if ( V_2 -> V_9 == V_100 )
F_39 ( V_2 , & V_2 -> V_99 ) ;
return 0 ;
}
static int F_42 ( struct V_1 * V_2 )
{
if ( V_2 -> V_9 != V_10 ) {
F_14 ( V_2 -> V_12 , L_7 ,
V_96 [ V_2 -> V_9 ] ) ;
return - V_78 ;
}
F_19 ( V_2 , V_101 ) ;
F_43 ( V_2 -> V_12 ) ;
return 0 ;
}
static int F_44 ( struct V_1 * V_2 )
{
if ( V_2 -> V_9 != V_101 ) {
F_14 ( V_2 -> V_12 , L_8 ,
V_96 [ V_2 -> V_9 ] ) ;
return - V_97 ;
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
V_5 = F_1 ( V_2 , V_94 ) ;
V_5 |= V_102 ;
V_5 &= ~ V_93 ;
F_3 ( V_2 , V_5 , V_94 ) ;
F_6 ( V_2 ) ;
}
static int F_47 ( struct V_1 * V_2 )
{
struct V_73 * V_74 = & V_2 -> V_99 ;
switch ( V_2 -> V_9 ) {
case V_100 :
return 0 ;
case V_10 :
if ( V_74 -> V_68 == 0 ) {
F_14 ( V_2 -> V_12 , L_9 ,
V_77 ) ;
return - V_78 ;
}
F_20 ( V_2 , true ) ;
F_19 ( V_2 , V_100 ) ;
F_39 ( V_2 , V_74 ) ;
return 0 ;
default:
F_25 ( V_2 -> V_9 > V_100 ) ;
F_14 ( V_2 -> V_12 , L_10 ,
V_77 , V_96 [ V_2 -> V_9 ] ) ;
return - V_97 ;
}
}
static int F_48 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_9 ) {
case V_100 :
F_46 ( V_2 ) ;
F_19 ( V_2 , V_10 ) ;
F_20 ( V_2 , false ) ;
return 0 ;
case V_10 :
return 0 ;
default:
F_25 ( V_2 -> V_9 > V_100 ) ;
F_14 ( V_2 -> V_12 , L_11 ,
V_77 , V_96 [ V_2 -> V_9 ] ) ;
return - V_97 ;
}
}
static int F_49 ( struct V_103 * V_104 )
{
struct V_1 * V_2 = F_50 ( V_104 ) ;
return F_10 ( V_2 ) ;
}
static int F_51 ( struct V_103 * V_104 )
{
struct V_1 * V_2 = F_50 ( V_104 ) ;
int V_13 ;
V_13 = F_44 ( V_2 ) ;
if ( V_13 )
return V_13 ;
V_13 = F_47 ( V_2 ) ;
if ( V_13 )
F_42 ( V_2 ) ;
return V_13 ;
}
static void F_52 ( struct V_103 * V_104 )
{
struct V_1 * V_2 = F_50 ( V_104 ) ;
int V_13 ;
V_13 = F_48 ( V_2 ) ;
if ( ! V_13 )
F_42 ( V_2 ) ;
}
static unsigned long F_53 ( struct V_103 * V_104 ,
unsigned long V_105 )
{
struct V_1 * V_2 = F_50 ( V_104 ) ;
return V_2 -> V_98 ;
}
static int F_54 ( struct V_103 * V_104 ,
struct V_106 * V_107 )
{
struct V_1 * V_2 = F_50 ( V_104 ) ;
struct V_73 V_74 ;
int V_13 ;
V_13 = F_35 ( V_2 , & V_74 , V_107 -> V_68 ) ;
if ( V_13 )
return V_13 ;
return 0 ;
}
static int F_55 ( struct V_103 * V_104 , unsigned long V_68 ,
unsigned long V_105 )
{
struct V_1 * V_2 = F_50 ( V_104 ) ;
return F_41 ( V_2 , V_68 ) ;
}
static int F_56 ( struct V_1 * V_2 )
{
int V_13 ;
V_108 . V_109 = V_2 -> V_110 ;
V_2 -> V_111 . V_112 = & V_108 ;
V_2 -> V_113 = F_57 ( V_2 -> V_12 , & V_2 -> V_111 ) ;
if ( F_30 ( V_2 -> V_113 ) ) {
F_14 ( V_2 -> V_12 , L_12 ) ;
return - V_78 ;
}
V_13 = F_58 ( V_2 -> V_12 -> V_114 , V_115 ,
V_2 -> V_113 ) ;
if ( V_13 ) {
F_14 ( V_2 -> V_12 , L_13 ) ;
F_59 ( V_2 -> V_113 ) ;
return V_13 ;
}
return 0 ;
}
static void F_60 ( struct V_1 * V_2 )
{
F_61 ( V_2 -> V_12 -> V_114 ) ;
F_59 ( V_2 -> V_113 ) ;
V_2 -> V_113 = NULL ;
}
static V_29 F_62 ( T_1 V_116 ,
unsigned long V_79 )
{
return V_116 * ( V_79 / V_117 ) ;
}
static V_29 F_63 ( struct V_1 * V_2 )
{
T_1 V_118 , V_119 ;
V_29 V_120 , V_121 ;
if ( ! F_10 ( V_2 ) )
return 0 ;
V_118 = F_1 ( V_2 , V_122 ) ;
V_118 = ( V_118 & V_123 ) >> V_124 ;
V_120 = F_62 ( V_118 , V_2 -> V_79 ) ;
V_119 = F_1 ( V_2 , V_94 ) ;
V_119 = ( V_119 & V_102 ) >> V_89 ;
V_121 = F_18 ( V_119 , V_120 ) ;
return V_121 ;
}
static int F_64 ( void * V_125 , V_29 * V_5 )
{
struct V_1 * V_2 = V_125 ;
* V_5 = F_10 ( V_2 ) ;
return 0 ;
}
static int F_65 ( void * V_125 , V_29 V_5 )
{
struct V_1 * V_2 = V_125 ;
return V_5 ? F_44 ( V_2 ) : F_42 ( V_2 ) ;
}
static int F_66 ( void * V_125 , V_29 * V_5 )
{
struct V_1 * V_2 = V_125 ;
* V_5 = ( V_2 -> V_9 == V_100 ) ;
return 0 ;
}
static int F_67 ( void * V_125 , V_29 V_5 )
{
struct V_1 * V_2 = V_125 ;
return V_5 ? F_47 ( V_2 ) : F_48 ( V_2 ) ;
}
static int F_68 ( void * V_125 , V_29 * V_5 )
{
struct V_1 * V_2 = V_125 ;
* V_5 = F_63 ( V_2 ) ;
return 0 ;
}
static int F_69 ( void * V_125 , V_29 V_5 )
{
struct V_1 * V_2 = V_125 ;
return F_41 ( V_2 , V_5 ) ;
}
static int F_70 ( struct V_126 * V_119 , void * V_125 )
{
T_1 V_5 , V_3 ;
struct V_1 * V_2 = V_119 -> V_127 ;
F_71 ( V_119 , L_14 ) ;
for ( V_3 = 0 ; V_3 <= V_122 ; V_3 += 4 ) {
if ( V_3 == V_33 )
V_5 = F_7 ( V_2 , V_3 ) ;
else
V_5 = F_1 ( V_2 , V_3 ) ;
F_72 ( V_119 , L_15 , V_3 , V_5 ) ;
}
F_71 ( V_119 , L_16 ) ;
for ( V_3 = V_6 ; V_3 <= V_128 ; V_3 += 4 )
F_72 ( V_119 , L_15 , V_3 ,
F_7 ( V_2 , V_3 ) ) ;
for ( V_3 = V_67 ; V_3 <= V_64 ; V_3 += 4 )
F_72 ( V_119 , L_15 , V_3 ,
F_7 ( V_2 , V_3 ) ) ;
F_71 ( V_119 , L_17 ) ;
V_3 = V_57 ;
F_72 ( V_119 , L_15 , V_3 ,
F_2 ( V_2 -> V_56 + V_3 ) ) ;
F_71 ( V_119 , L_18 ) ;
for ( V_3 = 0 ; V_3 < 4 * V_37 ; V_3 += 4 )
F_72 ( V_119 , L_15 , V_3 ,
F_2 ( V_2 -> V_42 + V_3 ) ) ;
return 0 ;
}
static int F_73 ( struct V_129 * V_129 , struct V_130 * V_130 )
{
return F_74 ( V_130 , F_70 , V_129 -> V_131 ) ;
}
static int F_75 ( struct V_1 * V_2 )
{
int V_13 ;
if ( ! V_2 || ( V_2 -> V_9 == V_95 ) )
return 0 ;
V_2 -> V_132 = F_76 ( L_19 , NULL ) ;
if ( ! V_2 -> V_132 )
return - V_133 ;
V_13 = - V_133 ;
if ( ! F_77 ( L_20 , V_134 | V_135 ,
V_2 -> V_132 , V_2 , & V_136 ) )
goto V_137;
if ( ! F_77 ( L_21 , V_134 ,
V_2 -> V_132 , V_2 , & V_138 ) )
goto V_137;
if ( ! F_77 ( L_22 , V_134 ,
V_2 -> V_132 , V_2 , & V_139 ) )
goto V_137;
if ( ! F_77 ( L_23 , V_134 ,
V_2 -> V_132 , V_2 , & V_140 ) )
goto V_137;
return 0 ;
V_137:
F_78 ( V_2 -> V_132 ) ;
return V_13 ;
}
static void F_79 ( struct V_1 * V_2 )
{
T_1 V_5 ;
V_5 = F_24 ( V_2 -> V_79 , V_2 -> V_141 * 32 ) ;
F_25 ( V_5 > V_142 ) ;
F_3 ( V_2 , V_5 , V_143 ) ;
V_5 = ( V_2 -> V_144 << V_145 ) |
( V_2 -> V_146 << V_147 ) |
( V_2 -> V_148 << V_149 ) |
( V_2 -> V_85 << V_150 ) |
( V_2 -> V_151 ? V_152 : 0 ) ;
F_3 ( V_2 , V_5 , V_153 ) ;
F_17 ( V_2 ) ;
F_3 ( V_2 , V_2 -> V_154 , V_155 ) ;
F_3 ( V_2 , V_156 , V_157 ) ;
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
V_2 -> V_51 = F_82 ( V_2 -> V_16 ) ;
return 0 ;
}
static int F_83 ( struct V_1 * V_2 )
{
int V_13 ;
V_2 -> V_79 = F_82 ( V_2 -> V_14 ) ;
if ( V_2 -> V_79 != V_158 ) {
F_14 ( V_2 -> V_12 , L_30 ,
V_2 -> V_79 , V_158 ) ;
return - V_78 ;
}
F_84 ( V_2 -> V_159 ) ;
V_13 = F_85 ( V_2 -> V_14 ) ;
if ( V_13 ) {
F_14 ( V_2 -> V_12 , L_31 ) ;
return V_13 ;
}
V_13 = F_85 ( V_2 -> V_15 ) ;
if ( V_13 ) {
F_14 ( V_2 -> V_12 , L_32 ) ;
goto V_160;
}
V_13 = F_85 ( V_2 -> V_16 ) ;
if ( V_13 ) {
F_14 ( V_2 -> V_12 , L_33 ) ;
goto V_161;
}
V_2 -> V_98 = 0 ;
F_86 ( V_2 -> V_12 ) ;
F_45 ( V_2 -> V_12 ) ;
F_19 ( V_2 , V_101 ) ;
F_79 ( V_2 ) ;
if ( V_2 -> V_19 -> V_162 )
V_2 -> V_19 -> V_162 () ;
F_46 ( V_2 ) ;
F_26 ( V_2 ) ;
F_43 ( V_2 -> V_12 ) ;
return 0 ;
V_161:
F_87 ( V_2 -> V_15 ) ;
V_160:
F_87 ( V_2 -> V_14 ) ;
F_88 ( V_2 -> V_159 ) ;
return V_13 ;
}
static int F_89 ( struct V_1 * V_2 , int V_163 )
{
int V_35 , V_164 , V_165 ;
V_164 = F_90 ( V_2 -> V_40 ) ;
for ( V_35 = 0 ; V_35 < V_164 ; V_35 ++ ) {
V_165 = F_34 ( V_2 -> V_40 , V_35 ) ;
if ( V_165 < 0 )
break;
if ( V_163 == V_165 )
return V_35 ;
}
F_14 ( V_2 -> V_12 , L_34 , V_163 ) ;
return - V_78 ;
}
static int F_91 ( struct V_1 * V_2 , int V_163 )
{
int V_35 , V_164 , V_165 ;
V_164 = F_90 ( V_2 -> V_40 ) ;
for ( V_35 = 0 ; V_35 < V_164 ; V_35 ++ ) {
V_165 = F_34 ( V_2 -> V_40 , V_35 ) ;
if ( V_165 < 0 )
break;
if ( V_163 <= V_165 )
return V_35 ;
}
F_14 ( V_2 -> V_12 , L_35 , V_163 ) ;
return - V_78 ;
}
static int F_92 ( struct V_1 * V_2 )
{
int V_13 = - V_78 ;
int V_166 , V_118 , V_167 , V_168 ;
int V_169 ;
unsigned long V_68 ;
struct V_69 * V_70 ;
int V_170 ;
F_28 () ;
V_68 = V_171 ;
V_70 = F_93 ( V_2 -> V_19 -> V_12 , & V_68 ) ;
if ( F_30 ( V_70 ) ) {
F_14 ( V_2 -> V_12 , L_36 ) ;
goto V_172;
}
V_167 = F_33 ( V_70 ) ;
V_118 = V_2 -> V_19 -> V_20 -> V_173 * 1000 ;
V_170 = F_89 ( V_2 , V_118 ) ;
if ( V_170 < 0 )
goto V_172;
V_2 -> V_41 [ 0 ] = V_170 ;
for ( V_166 = 1 , V_68 = 0 ; ; V_68 ++ ) {
V_70 = F_29 ( V_2 -> V_19 -> V_12 , & V_68 ) ;
if ( F_30 ( V_70 ) )
break;
V_168 = F_33 ( V_70 ) ;
if ( V_168 <= V_2 -> V_19 -> V_20 -> V_173 * 1000 )
V_2 -> V_75 = F_94 ( V_70 ) ;
for (; ; ) {
V_118 += F_95 ( 1 , ( V_167 - V_118 ) / ( V_37 - V_166 ) ) ;
if ( V_118 >= V_168 )
break;
V_169 = F_91 ( V_2 , V_118 ) ;
if ( V_169 < 0 )
goto V_172;
if ( V_169 != V_2 -> V_41 [ V_166 - 1 ] )
V_2 -> V_41 [ V_166 ++ ] = V_169 ;
}
V_118 = ( V_166 == V_37 - 1 ) ? V_167 : V_168 ;
V_169 = F_89 ( V_2 , V_118 ) ;
if ( V_169 < 0 )
goto V_172;
if ( V_169 != V_2 -> V_41 [ V_166 - 1 ] )
V_2 -> V_41 [ V_166 ++ ] = V_169 ;
if ( V_118 >= V_167 )
break;
}
V_2 -> V_58 = V_166 ;
if ( ! V_2 -> V_75 )
F_14 ( V_2 -> V_12 , L_37 ,
V_2 -> V_19 -> V_20 -> V_173 ) ;
else
V_13 = 0 ;
V_172:
F_31 () ;
return V_13 ;
}
static bool F_96 ( struct V_1 * V_2 , const char * V_174 , T_1 * V_175 )
{
int V_176 = F_97 ( V_2 -> V_12 -> V_114 , V_174 , V_175 ) ;
if ( V_176 < 0 ) {
F_14 ( V_2 -> V_12 , L_38 ,
V_174 , V_176 ) ;
return false ;
}
return true ;
}
static int F_98 ( struct V_1 * V_2 )
{
struct V_177 * V_177 ;
struct V_11 * V_178 ;
struct V_179 * V_179 ;
int V_180 , V_181 ;
int V_13 ;
if ( ! F_96 ( V_2 , L_39 , & V_2 -> V_52 ) )
return - V_78 ;
V_177 = F_99 ( V_2 -> V_40 ) ;
V_178 = F_100 ( V_177 ) ;
V_179 = F_101 ( V_178 ) ;
V_2 -> V_43 = V_179 -> V_182 ;
V_13 = F_102 ( V_2 -> V_40 ,
& V_180 ,
& V_181 ) ;
if ( V_13 < 0 ) {
F_14 ( V_2 -> V_12 ,
L_40 ) ;
return - V_78 ;
}
V_2 -> V_49 = V_180 ;
V_13 = F_92 ( V_2 ) ;
if ( V_13 ) {
F_14 ( V_2 -> V_12 , L_41 ) ;
return V_13 ;
}
return 0 ;
}
static int F_103 ( struct V_1 * V_2 )
{
bool V_183 = true ;
V_183 &= F_96 ( V_2 , L_42 , & V_2 -> V_154 ) ;
V_183 &= F_96 ( V_2 , L_43 , & V_2 -> V_141 ) ;
V_183 &= F_96 ( V_2 , L_44 , & V_2 -> V_144 ) ;
V_183 &= F_96 ( V_2 , L_45 , & V_2 -> V_146 ) ;
V_183 &= F_96 ( V_2 , L_46 , & V_2 -> V_148 ) ;
V_183 &= F_96 ( V_2 , L_47 , & V_2 -> V_85 ) ;
V_2 -> V_151 = F_104 ( V_2 -> V_12 -> V_114 ,
L_48 ) ;
if ( F_105 ( V_2 -> V_12 -> V_114 , L_49 ,
& V_2 -> V_110 ) ) {
F_14 ( V_2 -> V_12 , L_50 ) ;
V_183 = false ;
}
return V_183 ? 0 : - V_78 ;
}
int F_106 ( struct V_184 * V_185 ,
struct V_186 * V_19 )
{
struct V_187 * V_188 ;
struct V_1 * V_2 ;
int V_13 ;
if ( ! V_19 ) {
F_14 ( & V_185 -> V_12 , L_51 ) ;
return - V_78 ;
}
V_2 = F_107 ( & V_185 -> V_12 , sizeof( * V_2 ) , V_189 ) ;
if ( ! V_2 )
return - V_133 ;
V_2 -> V_12 = & V_185 -> V_12 ;
F_108 ( V_185 , V_2 ) ;
V_2 -> V_19 = V_19 ;
V_2 -> V_40 = F_109 ( V_2 -> V_12 , L_52 ) ;
if ( F_30 ( V_2 -> V_40 ) ) {
F_14 ( V_2 -> V_12 , L_53 ) ;
return F_32 ( V_2 -> V_40 ) ;
}
V_2 -> V_159 = F_110 ( V_2 -> V_12 , L_54 ) ;
if ( F_30 ( V_2 -> V_159 ) ) {
F_14 ( V_2 -> V_12 , L_55 ) ;
return F_32 ( V_2 -> V_159 ) ;
}
V_13 = F_103 ( V_2 ) ;
if ( V_13 ) {
F_14 ( V_2 -> V_12 , L_56 ) ;
return V_13 ;
}
V_13 = F_98 ( V_2 ) ;
if ( V_13 )
return V_13 ;
V_188 = F_111 ( V_185 , V_190 , 0 ) ;
if ( ! V_188 ) {
F_14 ( V_2 -> V_12 , L_57 ) ;
return - V_191 ;
}
V_2 -> V_4 = F_112 ( V_2 -> V_12 , V_188 -> V_192 , F_113 ( V_188 ) ) ;
if ( ! V_2 -> V_4 ) {
F_14 ( V_2 -> V_12 , L_58 ) ;
return - V_191 ;
}
V_188 = F_111 ( V_185 , V_190 , 1 ) ;
if ( ! V_188 ) {
F_14 ( V_2 -> V_12 , L_59 ) ;
return - V_191 ;
}
V_2 -> V_8 = F_112 ( V_2 -> V_12 , V_188 -> V_192 , F_113 ( V_188 ) ) ;
if ( ! V_2 -> V_8 ) {
F_14 ( V_2 -> V_12 , L_60 ) ;
return - V_191 ;
}
V_188 = F_111 ( V_185 , V_190 , 2 ) ;
if ( ! V_188 ) {
F_14 ( V_2 -> V_12 , L_61 ) ;
return - V_191 ;
}
V_2 -> V_56 = F_112 ( V_2 -> V_12 , V_188 -> V_192 ,
F_113 ( V_188 ) ) ;
if ( ! V_2 -> V_56 ) {
F_14 ( V_2 -> V_12 ,
L_62 ) ;
return - V_191 ;
}
V_188 = F_111 ( V_185 , V_190 , 3 ) ;
if ( ! V_188 ) {
F_14 ( V_2 -> V_12 , L_63 ) ;
return - V_191 ;
}
V_2 -> V_42 = F_112 ( V_2 -> V_12 , V_188 -> V_192 , F_113 ( V_188 ) ) ;
if ( ! V_2 -> V_42 ) {
F_14 ( V_2 -> V_12 ,
L_64 ) ;
return - V_191 ;
}
V_13 = F_80 ( V_2 ) ;
if ( V_13 ) {
F_14 ( & V_185 -> V_12 , L_65 ) ;
return V_13 ;
}
V_13 = F_83 ( V_2 ) ;
if ( V_13 )
return V_13 ;
V_13 = F_56 ( V_2 ) ;
if ( V_13 ) {
F_14 ( & V_185 -> V_12 , L_66 ) ;
return V_13 ;
}
#ifdef F_114
F_75 ( V_2 ) ;
#endif
return 0 ;
}
int F_115 ( struct V_184 * V_185 )
{
struct V_1 * V_2 = F_116 ( V_185 ) ;
if ( V_2 -> V_9 != V_101 ) {
F_14 ( & V_185 -> V_12 ,
L_67 ) ;
return - V_193 ;
}
F_78 ( V_2 -> V_132 ) ;
F_60 ( V_2 ) ;
F_117 ( & V_185 -> V_12 ) ;
F_87 ( V_2 -> V_14 ) ;
F_87 ( V_2 -> V_15 ) ;
F_87 ( V_2 -> V_16 ) ;
F_88 ( V_2 -> V_159 ) ;
return 0 ;
}
