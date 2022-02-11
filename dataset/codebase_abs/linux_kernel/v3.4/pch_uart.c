static T_1 F_1 ( struct V_1 * V_1 , char T_2 * V_2 ,
T_3 V_3 , T_4 * V_4 )
{
struct V_5 * V_6 = V_1 -> V_7 ;
char * V_8 ;
T_5 V_9 = 0 ;
T_1 V_10 ;
unsigned char V_11 ;
V_8 = F_2 ( V_12 , V_13 ) ;
if ( ! V_8 )
return 0 ;
V_9 += snprintf ( V_8 + V_9 , V_12 - V_9 ,
L_1 , V_6 -> V_14 . line ) ;
V_9 += snprintf ( V_8 + V_9 , V_12 - V_9 ,
L_2 ) ;
V_9 += snprintf ( V_8 + V_9 , V_12 - V_9 ,
L_3 , F_3 ( V_6 -> V_15 + V_16 ) ) ;
V_9 += snprintf ( V_8 + V_9 , V_12 - V_9 ,
L_4 , F_3 ( V_6 -> V_15 + V_17 ) ) ;
V_9 += snprintf ( V_8 + V_9 , V_12 - V_9 ,
L_5 , F_3 ( V_6 -> V_15 + V_18 ) ) ;
V_9 += snprintf ( V_8 + V_9 , V_12 - V_9 ,
L_6 , F_3 ( V_6 -> V_15 + V_19 ) ) ;
V_9 += snprintf ( V_8 + V_9 , V_12 - V_9 ,
L_7 , F_3 ( V_6 -> V_15 + V_20 ) ) ;
V_9 += snprintf ( V_8 + V_9 , V_12 - V_9 ,
L_8 , F_3 ( V_6 -> V_15 + V_21 ) ) ;
V_9 += snprintf ( V_8 + V_9 , V_12 - V_9 ,
L_9 ,
F_3 ( V_6 -> V_15 + V_22 ) ) ;
V_11 = F_3 ( V_6 -> V_15 + V_18 ) ;
F_4 ( V_23 , V_6 -> V_15 + V_18 ) ;
V_9 += snprintf ( V_8 + V_9 , V_12 - V_9 ,
L_10 , F_3 ( V_6 -> V_15 + V_24 ) ) ;
V_9 += snprintf ( V_8 + V_9 , V_12 - V_9 ,
L_11 , F_3 ( V_6 -> V_15 + V_25 ) ) ;
F_4 ( V_11 , V_6 -> V_15 + V_18 ) ;
if ( V_9 > V_12 )
V_9 = V_12 ;
V_10 = F_5 ( V_2 , V_3 , V_4 , V_8 , V_9 ) ;
F_6 ( V_8 ) ;
return V_10 ;
}
static int F_7 ( void )
{
const char * V_26 ;
if ( V_27 )
return V_27 ;
V_26 = F_8 ( V_28 ) ;
if ( V_26 && strstr ( V_26 , L_12 ) )
return V_29 ;
V_26 = F_8 ( V_30 ) ;
if ( V_26 && F_9 ( V_26 , L_13 , 4 ) )
return V_31 ;
V_26 = F_8 ( V_32 ) ;
if ( V_26 && strstr ( V_26 , L_14 ) )
return V_33 ;
V_26 = F_8 ( V_28 ) ;
if ( V_26 && ( strstr ( V_26 , L_15 ) ||
strstr ( V_26 , L_16 ) ) )
return V_34 ;
return V_35 ;
}
static void F_10 ( struct V_5 * V_6 ,
unsigned int V_36 )
{
T_6 V_37 = F_3 ( V_6 -> V_15 + V_16 ) ;
V_37 |= V_36 & V_38 ;
F_4 ( V_37 , V_6 -> V_15 + V_16 ) ;
}
static void F_11 ( struct V_5 * V_6 ,
unsigned int V_36 )
{
T_6 V_37 = F_3 ( V_6 -> V_15 + V_16 ) ;
V_37 &= ~ ( V_36 & V_38 ) ;
F_4 ( V_37 , V_6 -> V_15 + V_16 ) ;
}
static int F_12 ( struct V_5 * V_6 , int V_39 ,
unsigned int V_40 , unsigned int V_41 ,
unsigned int V_42 )
{
unsigned int V_43 , V_44 , V_11 ;
int div ;
div = F_13 ( V_6 -> V_45 / 16 , V_39 ) ;
if ( div < 0 || V_46 <= div ) {
F_14 ( V_6 -> V_14 . V_47 , L_17 , div ) ;
return - V_48 ;
}
V_43 = ( unsigned int ) div & 0x00FFU ;
V_44 = ( ( unsigned int ) div >> 8 ) & 0x00FFU ;
if ( V_40 & ~ ( V_49 | V_50 | V_51 ) ) {
F_14 ( V_6 -> V_14 . V_47 , L_18 , V_40 ) ;
return - V_48 ;
}
if ( V_41 & ~ V_52 ) {
F_14 ( V_6 -> V_14 . V_47 , L_19 , V_41 ) ;
return - V_48 ;
}
if ( V_42 & ~ V_53 ) {
F_14 ( V_6 -> V_14 . V_47 , L_20 , V_42 ) ;
return - V_48 ;
}
V_11 = V_40 ;
V_11 |= V_41 ;
V_11 |= V_42 ;
F_15 ( V_6 -> V_14 . V_47 , L_21 ,
V_54 , V_39 , div , V_11 , V_55 ) ;
F_4 ( V_23 , V_6 -> V_15 + V_18 ) ;
F_4 ( V_43 , V_6 -> V_15 + V_56 ) ;
F_4 ( V_44 , V_6 -> V_15 + V_57 ) ;
F_4 ( V_11 , V_6 -> V_15 + V_18 ) ;
return 0 ;
}
static int F_16 ( struct V_5 * V_6 ,
unsigned int V_36 )
{
if ( V_36 & ~ ( V_58 | V_59 ) ) {
F_14 ( V_6 -> V_14 . V_47 , L_22 ,
V_54 , V_36 ) ;
return - V_48 ;
}
F_4 ( V_60 | V_6 -> V_61 , V_6 -> V_15 + V_62 ) ;
F_4 ( V_60 | V_6 -> V_61 | V_36 ,
V_6 -> V_15 + V_62 ) ;
F_4 ( V_6 -> V_61 , V_6 -> V_15 + V_62 ) ;
return 0 ;
}
static int F_17 ( struct V_5 * V_6 ,
unsigned int V_63 ,
unsigned int V_64 , unsigned int V_65 )
{
T_6 V_61 ;
if ( V_63 & ~ V_66 ) {
F_14 ( V_6 -> V_14 . V_47 , L_23 ,
V_54 , V_63 ) ;
return - V_48 ;
}
if ( V_64 & ~ ( V_60 | V_67 ) ) {
F_14 ( V_6 -> V_14 . V_47 , L_24 ,
V_54 , V_64 ) ;
return - V_48 ;
}
if ( V_65 & ~ V_68 ) {
F_14 ( V_6 -> V_14 . V_47 , L_25 ,
V_54 , V_65 ) ;
return - V_48 ;
}
switch ( V_6 -> V_64 ) {
case 256 :
V_6 -> V_69 =
V_70 [ V_65 >> V_71 ] ;
break;
case 64 :
V_6 -> V_69 =
V_72 [ V_65 >> V_71 ] ;
break;
case 16 :
V_6 -> V_69 =
V_73 [ V_65 >> V_71 ] ;
break;
default:
V_6 -> V_69 =
V_74 [ V_65 >> V_71 ] ;
break;
}
V_61 =
V_63 | V_64 | V_65 | V_59 | V_58 ;
F_4 ( V_60 , V_6 -> V_15 + V_62 ) ;
F_4 ( V_60 | V_59 | V_58 ,
V_6 -> V_15 + V_62 ) ;
F_4 ( V_61 , V_6 -> V_15 + V_62 ) ;
V_6 -> V_61 = V_61 ;
return 0 ;
}
static T_6 F_18 ( struct V_5 * V_6 )
{
unsigned int V_75 = F_3 ( V_6 -> V_15 + V_21 ) ;
V_6 -> V_76 = V_75 & V_77 ;
return ( T_6 ) V_75 ;
}
static void F_19 ( struct V_5 * V_6 ,
const unsigned char * V_8 , int V_78 )
{
int V_79 ;
unsigned int V_80 ;
for ( V_79 = 0 ; V_79 < V_78 ; ) {
V_80 = V_8 [ V_79 ++ ] ;
F_4 ( V_80 , V_6 -> V_15 + V_81 ) ;
}
}
static int F_20 ( struct V_5 * V_6 , unsigned char * V_8 ,
int V_82 )
{
int V_79 ;
T_6 V_83 , V_84 ;
V_84 = F_3 ( V_6 -> V_15 + V_20 ) ;
for ( V_79 = 0 , V_84 = F_3 ( V_6 -> V_15 + V_20 ) ;
V_79 < V_82 && V_84 & V_85 ;
V_84 = F_3 ( V_6 -> V_15 + V_20 ) ) {
V_83 = F_3 ( V_6 -> V_15 + V_86 ) ;
V_8 [ V_79 ++ ] = V_83 ;
}
return V_79 ;
}
static unsigned int F_21 ( struct V_5 * V_6 )
{
unsigned int V_87 ;
int V_10 ;
V_87 = F_3 ( V_6 -> V_15 + V_17 ) ;
V_10 = ( V_87 & ( V_88 | V_89 | V_90 ) ) ;
return V_10 ;
}
static T_6 F_22 ( struct V_5 * V_6 )
{
return F_3 ( V_6 -> V_15 + V_20 ) ;
}
static void F_23 ( struct V_5 * V_6 , int V_91 )
{
unsigned int V_11 ;
V_11 = F_3 ( V_6 -> V_15 + V_18 ) ;
if ( V_91 )
V_11 |= V_92 ;
else
V_11 &= ~ V_92 ;
F_4 ( V_11 , V_6 -> V_15 + V_18 ) ;
}
static int F_24 ( struct V_5 * V_6 , const unsigned char * V_8 ,
int V_93 )
{
struct V_94 * V_14 ;
struct V_95 * V_96 ;
V_14 = & V_6 -> V_14 ;
V_96 = F_25 ( & V_14 -> V_97 -> V_14 ) ;
if ( ! V_96 ) {
F_15 ( V_6 -> V_14 . V_47 , L_26 , V_54 ) ;
return - V_98 ;
}
F_26 ( V_96 , V_8 , V_93 ) ;
F_27 ( V_96 ) ;
F_28 ( V_96 ) ;
return 0 ;
}
static int F_29 ( struct V_5 * V_6 , unsigned char * V_8 )
{
int V_10 = 0 ;
struct V_94 * V_14 = & V_6 -> V_14 ;
if ( V_14 -> V_99 ) {
F_15 ( V_6 -> V_14 . V_47 , L_27 ,
V_54 , V_14 -> V_99 , V_55 ) ;
V_8 [ 0 ] = V_14 -> V_99 ;
V_14 -> V_99 = 0 ;
V_10 = 1 ;
}
return V_10 ;
}
static int F_30 ( struct V_5 * V_6 , int V_93 )
{
struct V_95 * V_96 ;
int V_100 ;
struct V_94 * V_14 = & V_6 -> V_14 ;
V_14 = & V_6 -> V_14 ;
V_96 = F_25 ( & V_14 -> V_97 -> V_14 ) ;
if ( ! V_96 ) {
F_15 ( V_6 -> V_14 . V_47 , L_26 , V_54 ) ;
return 0 ;
}
V_100 = F_31 ( V_96 , V_93 ) ;
if ( V_100 < V_93 )
F_32 ( V_14 -> V_47 , L_28 ,
V_93 - V_100 ) ;
if ( ! V_100 )
return V_100 ;
F_26 ( V_96 , F_33 ( & V_6 -> V_101 ) , V_93 ) ;
V_14 -> V_102 . V_103 += V_100 ;
F_28 ( V_96 ) ;
return V_100 ;
}
static void F_34 ( struct V_94 * V_14 )
{
struct V_5 * V_6 ;
V_6 = F_35 ( V_14 , struct V_5 , V_14 ) ;
if ( V_6 -> V_104 ) {
F_36 ( V_6 -> V_104 ) ;
V_6 -> V_104 = NULL ;
}
if ( V_6 -> V_105 ) {
F_36 ( V_6 -> V_105 ) ;
V_6 -> V_105 = NULL ;
}
if ( F_37 ( & V_6 -> V_101 ) )
F_38 ( V_14 -> V_47 , V_14 -> V_106 ,
F_33 ( & V_6 -> V_101 ) ,
F_37 ( & V_6 -> V_101 ) ) ;
return;
}
static bool F_39 ( struct V_107 * V_108 , void * V_109 )
{
struct V_110 * V_111 = V_109 ;
if ( ( V_108 -> V_112 == V_111 -> V_112 ) && ( V_111 -> V_113 ==
V_108 -> V_114 -> V_47 ) ) {
V_108 -> V_115 = V_111 ;
return true ;
} else {
return false ;
}
}
static void F_40 ( struct V_94 * V_14 )
{
T_7 V_116 ;
struct V_107 * V_108 ;
struct V_117 * V_113 ;
struct V_110 * V_111 ;
struct V_5 * V_6 =
F_35 ( V_14 , struct V_5 , V_14 ) ;
F_41 ( V_116 ) ;
F_42 ( V_118 , V_116 ) ;
V_113 = F_43 ( V_6 -> V_119 -> V_120 -> V_121 ,
F_44 ( 0xa , 0 ) ) ;
V_111 = & V_6 -> V_122 ;
V_111 -> V_113 = & V_113 -> V_47 ;
V_111 -> V_112 = V_6 -> V_14 . line * 2 ;
V_111 -> V_123 = V_14 -> V_124 + V_125 ;
V_108 = F_45 ( V_116 , F_39 , V_111 ) ;
if ( ! V_108 ) {
F_14 ( V_6 -> V_14 . V_47 , L_29 ,
V_54 ) ;
return;
}
V_6 -> V_104 = V_108 ;
V_111 = & V_6 -> V_126 ;
V_111 -> V_113 = & V_113 -> V_47 ;
V_111 -> V_112 = V_6 -> V_14 . line * 2 + 1 ;
V_111 -> V_127 = V_14 -> V_124 + V_128 ;
V_108 = F_45 ( V_116 , F_39 , V_111 ) ;
if ( ! V_108 ) {
F_14 ( V_6 -> V_14 . V_47 , L_30 ,
V_54 ) ;
F_36 ( V_6 -> V_104 ) ;
V_6 -> V_104 = NULL ;
return;
}
V_6 -> V_129 = F_46 ( V_14 -> V_47 , V_14 -> V_106 ,
& V_6 -> V_130 , V_13 ) ;
V_6 -> V_105 = V_108 ;
}
static void F_47 ( void * V_131 )
{
struct V_5 * V_6 = V_131 ;
struct V_94 * V_14 = & V_6 -> V_14 ;
struct V_95 * V_96 = F_25 ( & V_14 -> V_97 -> V_14 ) ;
int V_3 ;
if ( ! V_96 ) {
F_15 ( V_6 -> V_14 . V_47 , L_26 , V_54 ) ;
return;
}
F_48 ( V_14 -> V_47 , & V_6 -> V_101 , 1 , V_132 ) ;
V_3 = F_30 ( V_6 , V_6 -> V_69 ) ;
if ( V_3 )
F_27 ( V_96 ) ;
F_28 ( V_96 ) ;
F_49 ( V_6 -> V_133 ) ;
F_10 ( V_6 , V_134 ) ;
}
static void F_50 ( void * V_131 )
{
struct V_5 * V_6 = V_131 ;
struct V_94 * V_14 = & V_6 -> V_14 ;
struct V_135 * V_136 = & V_14 -> V_97 -> V_136 ;
struct V_137 * V_138 = V_6 -> V_139 ;
int V_79 ;
for ( V_79 = 0 ; V_79 < V_6 -> V_140 ; V_79 ++ , V_138 ++ ) {
V_136 -> V_141 += F_51 ( V_138 ) ;
V_14 -> V_102 . V_142 += F_51 ( V_138 ) ;
}
V_136 -> V_141 &= V_143 - 1 ;
F_49 ( V_6 -> V_144 ) ;
F_52 ( V_14 -> V_47 , V_138 , V_6 -> V_140 , V_145 ) ;
V_6 -> V_146 = 0 ;
V_6 -> V_140 = 0 ;
F_6 ( V_6 -> V_139 ) ;
F_10 ( V_6 , V_147 ) ;
}
static int F_53 ( struct V_5 * V_6 , int V_93 )
{
int V_3 = 0 ;
struct V_94 * V_14 = & V_6 -> V_14 ;
struct V_135 * V_136 = & V_14 -> V_97 -> V_136 ;
if ( F_54 ( V_14 ) || F_55 ( V_136 ) || V_3 >= V_93 )
goto V_148;
do {
int V_149 =
F_56 ( V_136 -> V_150 , V_136 -> V_141 , V_143 ) ;
int V_151 = F_57 ( V_93 - V_3 , V_149 ) ;
F_19 ( V_6 , & V_136 -> V_8 [ V_136 -> V_141 ] , V_151 ) ;
V_136 -> V_141 = ( V_136 -> V_141 + V_151 ) & ( V_143 - 1 ) ;
V_3 += V_151 ;
} while ( ! F_55 ( V_136 ) && V_3 < V_93 );
V_148:
F_15 ( V_6 -> V_14 . V_47 , L_31 ,
V_3 , V_93 - V_3 , V_55 ) ;
return V_3 ;
}
static int F_58 ( struct V_5 * V_6 )
{
struct V_152 * V_8 ;
int V_82 ;
int V_10 ;
if ( ! V_6 -> V_153 ) {
F_11 ( V_6 , V_134 ) ;
return 0 ;
}
V_8 = & V_6 -> V_154 ;
do {
V_82 = F_20 ( V_6 , V_8 -> V_8 , V_8 -> V_93 ) ;
V_10 = F_24 ( V_6 , V_8 -> V_8 , V_82 ) ;
if ( V_10 )
return 0 ;
} while ( V_82 == V_8 -> V_93 );
return V_155 ;
}
static int F_59 ( struct V_5 * V_6 )
{
return F_58 ( V_6 ) ;
}
static int F_60 ( struct V_5 * V_6 )
{
struct V_94 * V_14 = & V_6 -> V_14 ;
struct V_156 * V_157 ;
struct V_137 * V_138 ;
V_6 = F_35 ( V_14 , struct V_5 , V_14 ) ;
V_138 = & V_6 -> V_101 ;
F_61 ( & V_6 -> V_101 , 1 ) ;
F_51 ( V_138 ) = V_6 -> V_69 ;
F_62 ( & V_6 -> V_101 , F_63 ( V_6 -> V_129 ) ,
F_51 ( V_138 ) , ( unsigned long ) V_6 -> V_129 &
~ V_158 ) ;
F_37 ( V_138 ) = V_6 -> V_130 ;
V_157 = F_64 ( V_6 -> V_105 ,
V_138 , 1 , V_159 ,
V_160 | V_161 ) ;
if ( ! V_157 )
return 0 ;
V_6 -> V_133 = V_157 ;
V_157 -> V_162 = F_47 ;
V_157 -> V_163 = V_6 ;
V_157 -> V_164 ( V_157 ) ;
F_65 ( V_6 -> V_105 ) ;
return V_155 ;
}
static unsigned int F_66 ( struct V_5 * V_6 )
{
struct V_94 * V_14 = & V_6 -> V_14 ;
struct V_135 * V_136 = & V_14 -> V_97 -> V_136 ;
int V_64 ;
int V_78 ;
int V_93 ;
int V_165 ;
if ( ! V_6 -> V_166 ) {
F_67 ( V_6 -> V_14 . V_47 , L_32 ,
V_54 , V_55 ) ;
F_11 ( V_6 , V_147 ) ;
V_6 -> V_165 = 1 ;
return 0 ;
}
V_64 = F_68 ( V_6 -> V_64 , 1 ) ;
V_165 = 1 ;
if ( F_29 ( V_6 , V_136 -> V_8 ) ) {
F_19 ( V_6 , V_136 -> V_8 , 1 ) ;
V_14 -> V_102 . V_142 ++ ;
V_165 = 0 ;
V_64 -- ;
}
V_93 = F_57 ( V_136 -> V_150 - V_136 -> V_141 , V_64 ) ;
if ( V_93 < 0 )
V_93 = V_64 ;
V_78 = F_53 ( V_6 , V_93 ) ;
if ( V_78 > 0 ) {
V_14 -> V_102 . V_142 += V_78 ;
V_165 = 0 ;
}
V_6 -> V_165 = V_165 ;
if ( V_165 ) {
F_11 ( V_6 , V_147 ) ;
F_69 ( V_14 ) ;
}
return V_167 ;
}
static unsigned int F_70 ( struct V_5 * V_6 )
{
struct V_94 * V_14 = & V_6 -> V_14 ;
struct V_135 * V_136 = & V_14 -> V_97 -> V_136 ;
struct V_137 * V_138 ;
int V_140 ;
int V_64 ;
int V_165 ;
struct V_156 * V_157 ;
int V_168 ;
int V_79 ;
int V_169 ;
int V_93 ;
int V_170 ;
if ( ! V_6 -> V_166 ) {
F_67 ( V_6 -> V_14 . V_47 , L_32 ,
V_54 , V_55 ) ;
F_11 ( V_6 , V_147 ) ;
V_6 -> V_165 = 1 ;
return 0 ;
}
if ( V_6 -> V_146 ) {
F_15 ( V_6 -> V_14 . V_47 , L_33 ,
V_54 , V_55 ) ;
F_11 ( V_6 , V_147 ) ;
V_6 -> V_165 = 1 ;
return 0 ;
}
V_64 = F_68 ( V_6 -> V_64 , 1 ) ;
V_165 = 1 ;
if ( F_29 ( V_6 , V_136 -> V_8 ) ) {
F_19 ( V_6 , V_136 -> V_8 , 1 ) ;
V_14 -> V_102 . V_142 ++ ;
V_165 = 0 ;
V_64 -- ;
}
V_169 = F_57 ( ( int ) F_71 ( V_136 -> V_150 , V_136 -> V_141 ,
V_143 ) , F_56 ( V_136 -> V_150 ,
V_136 -> V_141 , V_143 ) ) ;
if ( ! V_169 ) {
F_15 ( V_6 -> V_14 . V_47 , L_34 , V_54 ) ;
F_11 ( V_6 , V_147 ) ;
F_69 ( V_14 ) ;
return 0 ;
}
if ( V_169 > V_64 ) {
V_168 = V_169 / V_64 + 1 ;
V_93 = V_64 ;
V_170 = V_169 % V_64 ;
} else {
V_168 = 1 ;
V_93 = V_169 ;
V_170 = V_169 ;
}
F_15 ( V_6 -> V_14 . V_47 , L_35 ,
V_54 , V_168 , V_93 , V_170 ) ;
V_6 -> V_146 = 1 ;
V_6 -> V_139 = F_2 ( sizeof( struct V_137 ) * V_168 , V_171 ) ;
F_61 ( V_6 -> V_139 , V_168 ) ;
V_138 = V_6 -> V_139 ;
for ( V_79 = 0 ; V_79 < V_168 ; V_79 ++ , V_138 ++ ) {
if ( V_79 == ( V_168 - 1 ) )
F_62 ( V_138 , F_63 ( V_136 -> V_8 ) ,
V_170 , V_64 * V_79 ) ;
else
F_62 ( V_138 , F_63 ( V_136 -> V_8 ) ,
V_93 , V_64 * V_79 ) ;
}
V_138 = V_6 -> V_139 ;
V_140 = F_72 ( V_14 -> V_47 , V_138 , V_168 , V_145 ) ;
if ( ! V_140 ) {
F_14 ( V_6 -> V_14 . V_47 , L_36 , V_54 ) ;
return 0 ;
}
V_6 -> V_140 = V_140 ;
for ( V_79 = 0 ; V_79 < V_140 ; V_79 ++ , V_138 ++ ) {
V_138 -> V_172 = ( V_136 -> V_141 & ( V_143 - 1 ) ) +
V_64 * V_79 ;
F_37 ( V_138 ) = ( F_37 ( V_138 ) &
~ ( V_143 - 1 ) ) + V_138 -> V_172 ;
if ( V_79 == ( V_140 - 1 ) )
F_51 ( V_138 ) = V_170 ;
else
F_51 ( V_138 ) = V_93 ;
}
V_157 = F_64 ( V_6 -> V_104 ,
V_6 -> V_139 , V_140 , V_173 ,
V_160 | V_161 ) ;
if ( ! V_157 ) {
F_14 ( V_6 -> V_14 . V_47 , L_37 ,
V_54 ) ;
return 0 ;
}
F_73 ( V_14 -> V_47 , V_6 -> V_139 , V_140 , V_145 ) ;
V_6 -> V_144 = V_157 ;
V_157 -> V_162 = F_50 ;
V_157 -> V_163 = V_6 ;
V_157 -> V_164 ( V_157 ) ;
F_65 ( V_6 -> V_104 ) ;
return V_167 ;
}
static void F_74 ( struct V_5 * V_6 , unsigned int V_84 )
{
T_6 V_61 = F_3 ( V_6 -> V_15 + V_62 ) ;
V_61 |= V_174 ;
F_4 ( V_61 , V_6 -> V_15 + V_62 ) ;
if ( V_84 & V_175 )
F_14 ( & V_6 -> V_119 -> V_47 , L_38 ) ;
if ( V_84 & V_176 )
F_14 ( & V_6 -> V_119 -> V_47 , L_39 ) ;
if ( V_84 & V_177 )
F_14 ( & V_6 -> V_119 -> V_47 , L_40 ) ;
if ( V_84 & V_178 )
F_14 ( & V_6 -> V_119 -> V_47 , L_41 ) ;
}
static T_8 F_75 ( int V_179 , void * V_180 )
{
struct V_5 * V_6 = V_180 ;
unsigned int V_181 ;
T_6 V_84 ;
int V_10 = 0 ;
unsigned int V_182 ;
unsigned long V_183 ;
F_76 ( & V_6 -> V_14 . V_184 , V_183 ) ;
V_181 = 0 ;
while ( ( V_182 = F_21 ( V_6 ) ) > 1 ) {
switch ( V_182 ) {
case V_185 :
V_84 = F_22 ( V_6 ) ;
if ( V_84 & ( V_175 | V_176 |
V_177 | V_178 ) ) {
F_74 ( V_6 , V_84 ) ;
V_10 = V_186 ;
}
break;
case V_187 :
if ( V_6 -> V_188 ) {
F_11 ( V_6 ,
V_134 ) ;
V_10 = F_60 ( V_6 ) ;
if ( ! V_10 )
F_10 ( V_6 ,
V_134 ) ;
} else {
V_10 = F_59 ( V_6 ) ;
}
break;
case V_189 :
V_10 = F_58 ( V_6 ) ;
break;
case V_190 :
if ( V_6 -> V_188 )
V_10 = F_70 ( V_6 ) ;
else
V_10 = F_66 ( V_6 ) ;
break;
case V_191 :
V_10 = V_192 ;
break;
default:
F_14 ( V_6 -> V_14 . V_47 , L_42 , V_54 ,
V_182 , V_55 ) ;
V_10 = - 1 ;
break;
}
V_181 |= ( unsigned int ) V_10 ;
}
if ( V_181 == 0 && V_182 <= 1 ) {
if ( V_6 -> V_193 )
V_6 -> V_193 = 0 ;
}
F_77 ( & V_6 -> V_14 . V_184 , V_183 ) ;
return F_78 ( V_181 ) ;
}
static unsigned int F_79 ( struct V_94 * V_14 )
{
struct V_5 * V_6 ;
V_6 = F_35 ( V_14 , struct V_5 , V_14 ) ;
if ( V_6 -> V_165 )
return V_194 ;
else
return 0 ;
}
static unsigned int F_80 ( struct V_94 * V_14 )
{
struct V_5 * V_6 ;
T_6 V_195 ;
unsigned int V_10 = 0 ;
V_6 = F_35 ( V_14 , struct V_5 , V_14 ) ;
V_195 = F_18 ( V_6 ) ;
if ( V_195 & V_196 )
V_10 |= V_197 ;
if ( V_195 & V_198 )
V_10 |= V_199 ;
if ( V_195 & V_200 )
V_10 |= V_201 ;
if ( V_195 & V_202 )
V_10 |= V_203 ;
return V_10 ;
}
static void F_81 ( struct V_94 * V_14 , unsigned int V_204 )
{
T_5 V_205 = 0 ;
struct V_5 * V_6 = F_35 ( V_14 , struct V_5 , V_14 ) ;
if ( V_204 & V_206 )
V_205 |= V_207 ;
if ( V_204 & V_208 )
V_205 |= V_209 ;
if ( V_204 & V_210 )
V_205 |= V_211 ;
if ( V_6 -> V_205 & V_212 )
V_205 |= V_212 ;
if ( V_204 )
F_4 ( V_205 , V_6 -> V_15 + V_19 ) ;
}
static void F_82 ( struct V_94 * V_14 )
{
struct V_5 * V_6 ;
V_6 = F_35 ( V_14 , struct V_5 , V_14 ) ;
V_6 -> V_166 = 0 ;
V_6 -> V_146 = 0 ;
}
static void F_83 ( struct V_94 * V_14 )
{
struct V_5 * V_6 ;
V_6 = F_35 ( V_14 , struct V_5 , V_14 ) ;
if ( V_6 -> V_188 ) {
if ( V_6 -> V_146 ) {
F_15 ( V_6 -> V_14 . V_47 , L_43 ,
V_54 ) ;
return;
}
}
V_6 -> V_166 = 1 ;
F_10 ( V_6 , V_147 ) ;
}
static void F_84 ( struct V_94 * V_14 )
{
struct V_5 * V_6 ;
V_6 = F_35 ( V_14 , struct V_5 , V_14 ) ;
V_6 -> V_153 = 0 ;
F_11 ( V_6 , V_134 ) ;
V_6 -> V_193 = 1 ;
}
static void F_85 ( struct V_94 * V_14 )
{
struct V_5 * V_6 ;
V_6 = F_35 ( V_14 , struct V_5 , V_14 ) ;
F_10 ( V_6 , V_213 ) ;
}
static void F_86 ( struct V_94 * V_14 , int V_214 )
{
struct V_5 * V_6 ;
unsigned long V_183 ;
V_6 = F_35 ( V_14 , struct V_5 , V_14 ) ;
F_76 ( & V_14 -> V_184 , V_183 ) ;
F_23 ( V_6 , V_214 ) ;
F_77 ( & V_14 -> V_184 , V_183 ) ;
}
static int F_87 ( struct V_94 * V_14 )
{
struct V_5 * V_6 ;
int V_10 ;
int V_64 ;
int V_69 ;
V_6 = F_35 ( V_14 , struct V_5 , V_14 ) ;
V_6 -> V_165 = 1 ;
if ( V_14 -> V_45 )
V_6 -> V_45 = V_14 -> V_45 ;
else
V_14 -> V_45 = V_6 -> V_45 ;
F_11 ( V_6 , V_215 ) ;
V_10 = F_12 ( V_6 , V_216 ,
V_217 , V_218 ,
V_219 ) ;
if ( V_10 )
return V_10 ;
switch ( V_6 -> V_64 ) {
case 256 :
V_64 = V_220 ;
break;
case 64 :
V_64 = V_221 ;
break;
case 16 :
V_64 = V_222 ;
case 1 :
default:
V_64 = V_223 ;
break;
}
switch ( V_6 -> V_65 ) {
case V_224 :
V_69 = 1 ;
break;
case V_225 :
V_69 = V_6 -> V_64 / 4 ;
break;
case V_226 :
V_69 = V_6 -> V_64 / 2 ;
break;
case V_227 :
default:
V_69 = V_6 -> V_64 - ( V_6 -> V_64 / 8 ) ;
break;
}
V_6 -> V_69 = V_69 ;
V_10 = F_17 ( V_6 , V_228 ,
V_64 , V_6 -> V_65 ) ;
if ( V_10 < 0 )
return V_10 ;
V_10 = F_88 ( V_6 -> V_14 . V_179 , F_75 , V_229 ,
V_230 , V_6 ) ;
if ( V_10 < 0 )
return V_10 ;
if ( V_6 -> V_188 )
F_40 ( V_14 ) ;
V_6 -> V_153 = 1 ;
F_10 ( V_6 , V_134 ) ;
F_89 ( V_14 , V_231 , V_216 ) ;
return 0 ;
}
static void F_90 ( struct V_94 * V_14 )
{
struct V_5 * V_6 ;
int V_10 ;
V_6 = F_35 ( V_14 , struct V_5 , V_14 ) ;
F_11 ( V_6 , V_215 ) ;
F_16 ( V_6 , V_232 ) ;
V_10 = F_17 ( V_6 , V_228 ,
V_223 , V_224 ) ;
if ( V_10 )
F_14 ( V_6 -> V_14 . V_47 ,
L_44 , V_10 ) ;
F_34 ( V_14 ) ;
F_91 ( V_6 -> V_14 . V_179 , V_6 ) ;
}
static void F_92 ( struct V_94 * V_14 ,
struct V_233 * V_234 , struct V_233 * V_235 )
{
int V_39 ;
int V_236 ;
unsigned int V_40 , V_41 , V_42 ;
struct V_5 * V_6 ;
unsigned long V_183 ;
V_6 = F_35 ( V_14 , struct V_5 , V_14 ) ;
switch ( V_234 -> V_237 & V_238 ) {
case V_239 :
V_41 = V_240 ;
break;
case V_241 :
V_41 = V_242 ;
break;
case V_243 :
V_41 = V_244 ;
break;
default:
V_41 = V_218 ;
break;
}
if ( V_234 -> V_237 & V_245 )
V_42 = V_246 ;
else
V_42 = V_219 ;
if ( V_234 -> V_237 & V_247 ) {
if ( ! ( V_234 -> V_237 & V_248 ) )
V_40 = V_249 ;
else
V_40 = V_250 ;
} else
V_40 = V_217 ;
if ( ( V_234 -> V_237 & V_251 ) && ( V_6 -> V_64 == 256 ) )
V_6 -> V_205 |= V_212 ;
else
V_6 -> V_205 &= ~ V_212 ;
V_234 -> V_237 &= ~ V_252 ;
V_39 = F_93 ( V_14 , V_234 , V_235 , 0 , V_14 -> V_45 / 16 ) ;
F_76 ( & V_14 -> V_184 , V_183 ) ;
F_89 ( V_14 , V_234 -> V_237 , V_39 ) ;
V_236 = F_12 ( V_6 , V_39 , V_40 , V_41 , V_42 ) ;
if ( V_236 )
goto V_253;
F_81 ( & V_6 -> V_14 , V_6 -> V_14 . V_204 ) ;
if ( F_94 ( V_234 ) )
F_95 ( V_234 , V_39 , V_39 ) ;
V_253:
F_77 ( & V_14 -> V_184 , V_183 ) ;
}
static const char * F_96 ( struct V_94 * V_14 )
{
return V_230 ;
}
static void F_97 ( struct V_94 * V_14 )
{
struct V_5 * V_6 ;
V_6 = F_35 ( V_14 , struct V_5 , V_14 ) ;
F_98 ( V_6 -> V_119 , V_6 -> V_15 ) ;
F_99 ( V_6 -> V_119 ) ;
}
static int F_100 ( struct V_94 * V_14 )
{
struct V_5 * V_6 ;
int V_10 ;
void T_9 * V_15 ;
V_6 = F_35 ( V_14 , struct V_5 , V_14 ) ;
V_10 = F_101 ( V_6 -> V_119 , V_230 ) ;
if ( V_10 < 0 )
return - V_98 ;
V_15 = F_102 ( V_6 -> V_119 , 1 , 0 ) ;
if ( ! V_15 ) {
F_99 ( V_6 -> V_119 ) ;
return - V_98 ;
}
V_6 -> V_15 = V_14 -> V_15 = V_15 ;
return 0 ;
}
static void F_103 ( struct V_94 * V_14 , int type )
{
struct V_5 * V_6 ;
V_6 = F_35 ( V_14 , struct V_5 , V_14 ) ;
if ( type & V_254 ) {
V_14 -> type = V_6 -> V_255 ;
F_100 ( V_14 ) ;
}
}
static int F_104 ( struct V_94 * V_14 ,
struct V_256 * V_257 )
{
struct V_5 * V_6 ;
V_6 = F_35 ( V_14 , struct V_5 , V_14 ) ;
if ( V_257 -> V_183 & V_258 ) {
F_67 ( V_6 -> V_14 . V_47 ,
L_45 ) ;
V_6 -> V_188 = 0 ;
V_257 -> V_183 &= ~ V_258 ;
} else {
#ifndef F_105
F_14 ( V_6 -> V_14 . V_47 , L_46 ,
V_54 ) ;
return - V_259 ;
#endif
V_6 -> V_260 = 1 ;
F_67 ( V_6 -> V_14 . V_47 , L_47 ) ;
if ( ! V_6 -> V_188 )
F_40 ( V_14 ) ;
V_6 -> V_188 = 1 ;
}
return 0 ;
}
static void F_106 ( struct V_5 * V_261 , int V_41 )
{
unsigned int V_262 , V_263 = 10000 ;
for (; ; ) {
V_262 = F_3 ( V_261 -> V_15 + V_20 ) ;
if ( ( V_262 & V_41 ) == V_41 )
break;
if ( -- V_263 == 0 )
break;
F_107 ( 1 ) ;
}
if ( V_261 -> V_14 . V_183 & V_264 ) {
unsigned int V_263 ;
for ( V_263 = 1000000 ; V_263 ; V_263 -- ) {
unsigned int V_75 = F_3 ( V_261 -> V_15 + V_21 ) ;
if ( V_75 & V_202 )
break;
F_107 ( 1 ) ;
F_108 () ;
}
}
}
static void F_109 ( struct V_94 * V_14 , int V_265 )
{
struct V_5 * V_6 =
F_35 ( V_14 , struct V_5 , V_14 ) ;
F_106 ( V_6 , V_266 ) ;
F_4 ( V_265 , V_6 -> V_15 + V_81 ) ;
}
static void
F_110 ( struct V_267 * V_268 , const char * V_269 , unsigned int V_3 )
{
struct V_5 * V_6 ;
unsigned long V_183 ;
T_6 V_37 ;
int V_270 = 1 ;
V_6 = V_271 [ V_268 -> V_272 ] ;
F_108 () ;
F_111 ( V_183 ) ;
if ( V_6 -> V_14 . V_273 ) {
V_270 = 0 ;
} else if ( V_274 ) {
V_270 = F_112 ( & V_6 -> V_14 . V_184 ) ;
} else
F_113 ( & V_6 -> V_14 . V_184 ) ;
V_37 = F_3 ( V_6 -> V_15 + V_16 ) ;
F_11 ( V_6 , V_215 ) ;
F_114 ( & V_6 -> V_14 , V_269 , V_3 , F_109 ) ;
F_106 ( V_6 , V_275 ) ;
F_4 ( V_37 , V_6 -> V_15 + V_16 ) ;
if ( V_270 )
F_115 ( & V_6 -> V_14 . V_184 ) ;
F_116 ( V_183 ) ;
}
static int T_10 F_117 ( struct V_267 * V_268 , char * V_276 )
{
struct V_94 * V_14 ;
int V_39 = V_216 ;
int V_41 = 8 ;
int V_40 = 'n' ;
int V_277 = 'n' ;
if ( V_268 -> V_272 >= V_278 )
V_268 -> V_272 = 0 ;
V_14 = & V_271 [ V_268 -> V_272 ] -> V_14 ;
if ( ! V_14 || ( ! V_14 -> V_279 && ! V_14 -> V_15 ) )
return - V_280 ;
V_14 -> V_45 = F_7 () ;
if ( V_276 )
F_118 ( V_276 , & V_39 , & V_40 , & V_41 , & V_277 ) ;
return F_119 ( V_14 , V_268 , V_39 , V_40 , V_41 , V_277 ) ;
}
static struct V_5 * F_120 ( struct V_117 * V_119 ,
const struct V_281 * V_282 )
{
struct V_5 * V_6 ;
int V_10 ;
unsigned int V_279 ;
unsigned int V_124 ;
unsigned char * V_154 ;
int V_106 ;
int V_255 ;
struct V_283 * V_284 ;
char V_285 [ 32 ] ;
V_284 = & V_286 [ V_282 -> V_287 ] ;
V_255 = V_284 -> V_255 ;
V_6 = F_2 ( sizeof( struct V_5 ) , V_13 ) ;
if ( V_6 == NULL )
goto V_288;
V_154 = ( unsigned char * ) F_121 ( V_13 ) ;
if ( ! V_154 )
goto V_289;
switch ( V_255 ) {
case V_290 :
V_106 = 256 ;
break;
case V_291 :
V_106 = 64 ;
break;
default:
F_14 ( & V_119 -> V_47 , L_48 , V_255 ) ;
goto V_292;
}
F_122 ( V_119 ) ;
F_123 ( V_119 ) ;
V_279 = F_124 ( V_119 , 0 ) ;
V_124 = F_124 ( V_119 , 1 ) ;
V_6 -> V_124 = V_124 ;
V_6 -> V_279 = V_279 ;
V_6 -> V_119 = V_119 ;
V_6 -> V_165 = 1 ;
V_6 -> V_154 . V_8 = V_154 ;
V_6 -> V_154 . V_93 = V_293 ;
V_6 -> V_64 = V_106 ;
V_6 -> V_45 = F_7 () ;
V_6 -> V_255 = V_294 + V_255 + 1 ;
V_6 -> V_14 . V_47 = & V_119 -> V_47 ;
V_6 -> V_14 . V_279 = V_279 ;
V_6 -> V_14 . V_15 = NULL ;
V_6 -> V_14 . V_124 = V_124 ;
V_6 -> V_14 . V_179 = V_119 -> V_179 ;
V_6 -> V_14 . V_295 = V_296 ;
V_6 -> V_14 . V_297 = & V_298 ;
V_6 -> V_14 . V_183 = V_299 ;
V_6 -> V_14 . V_106 = V_106 ;
V_6 -> V_14 . line = V_284 -> V_300 ;
V_6 -> V_65 = V_226 ;
F_125 ( & V_6 -> V_14 . V_184 ) ;
F_126 ( V_119 , V_6 ) ;
V_6 -> V_69 = 1 ;
V_6 -> V_61 = 0 ;
#ifdef F_127
V_271 [ V_284 -> V_300 ] = V_6 ;
#endif
V_10 = F_128 ( & V_301 , & V_6 -> V_14 ) ;
if ( V_10 < 0 )
goto V_292;
#ifdef F_129
snprintf ( V_285 , sizeof( V_285 ) , L_49 , V_284 -> V_300 ) ;
V_6 -> V_302 = F_130 ( V_285 , V_303 | V_304 ,
NULL , V_6 , & V_305 ) ;
#endif
return V_6 ;
V_292:
#ifdef F_127
V_271 [ V_284 -> V_300 ] = NULL ;
#endif
F_131 ( ( unsigned long ) V_154 ) ;
V_289:
F_6 ( V_6 ) ;
V_288:
return NULL ;
}
static void F_132 ( struct V_5 * V_6 )
{
#ifdef F_129
if ( V_6 -> V_302 )
F_133 ( V_6 -> V_302 ) ;
#endif
F_134 ( & V_301 , & V_6 -> V_14 ) ;
F_126 ( V_6 -> V_119 , NULL ) ;
F_131 ( ( unsigned long ) V_6 -> V_154 . V_8 ) ;
}
static void F_135 ( struct V_117 * V_119 )
{
struct V_5 * V_6 = F_136 ( V_119 ) ;
F_137 ( V_119 ) ;
#ifdef F_127
V_271 [ V_6 -> V_14 . line ] = NULL ;
#endif
F_132 ( V_6 ) ;
F_138 ( V_119 ) ;
F_6 ( V_6 ) ;
return;
}
static int F_139 ( struct V_117 * V_119 , T_11 V_97 )
{
struct V_5 * V_6 = F_136 ( V_119 ) ;
F_140 ( & V_301 , & V_6 -> V_14 ) ;
F_141 ( V_119 ) ;
F_142 ( V_119 , F_143 ( V_119 , V_97 ) ) ;
return 0 ;
}
static int F_144 ( struct V_117 * V_119 )
{
struct V_5 * V_6 = F_136 ( V_119 ) ;
int V_10 ;
F_142 ( V_119 , V_306 ) ;
F_145 ( V_119 ) ;
V_10 = F_146 ( V_119 ) ;
if ( V_10 ) {
F_14 ( & V_119 -> V_47 ,
L_50 , V_54 , V_10 ) ;
return V_10 ;
}
F_147 ( & V_301 , & V_6 -> V_14 ) ;
return 0 ;
}
static int T_12 F_148 ( struct V_117 * V_119 ,
const struct V_281 * V_282 )
{
int V_10 ;
struct V_5 * V_6 ;
V_10 = F_146 ( V_119 ) ;
if ( V_10 < 0 )
goto V_307;
V_6 = F_120 ( V_119 , V_282 ) ;
if ( ! V_6 ) {
V_10 = - V_98 ;
goto V_308;
}
F_126 ( V_119 , V_6 ) ;
return V_10 ;
V_308:
F_137 ( V_119 ) ;
F_138 ( V_119 ) ;
V_307:
return V_10 ;
}
static int T_10 F_149 ( void )
{
int V_10 ;
V_10 = F_150 ( & V_301 ) ;
if ( V_10 < 0 )
return V_10 ;
V_10 = F_151 ( & V_309 ) ;
if ( V_10 < 0 )
F_152 ( & V_301 ) ;
return V_10 ;
}
static void T_13 F_153 ( void )
{
F_154 ( & V_309 ) ;
F_152 ( & V_301 ) ;
}
