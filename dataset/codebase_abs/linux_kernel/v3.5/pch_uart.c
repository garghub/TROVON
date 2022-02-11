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
static unsigned char F_21 ( struct V_5 * V_6 )
{
return F_3 ( V_6 -> V_15 + V_17 ) &\
( V_87 | V_88 | V_89 ) ;
}
static T_6 F_22 ( struct V_5 * V_6 )
{
return F_3 ( V_6 -> V_15 + V_20 ) ;
}
static void F_23 ( struct V_5 * V_6 , int V_90 )
{
unsigned int V_11 ;
V_11 = F_3 ( V_6 -> V_15 + V_18 ) ;
if ( V_90 )
V_11 |= V_91 ;
else
V_11 &= ~ V_91 ;
F_4 ( V_11 , V_6 -> V_15 + V_18 ) ;
}
static int F_24 ( struct V_5 * V_6 , const unsigned char * V_8 ,
int V_92 )
{
struct V_93 * V_14 ;
struct V_94 * V_95 ;
V_14 = & V_6 -> V_14 ;
V_95 = F_25 ( & V_14 -> V_96 -> V_14 ) ;
if ( ! V_95 ) {
F_15 ( V_6 -> V_14 . V_47 , L_26 , V_54 ) ;
return - V_97 ;
}
F_26 ( V_95 , V_8 , V_92 ) ;
F_27 ( V_95 ) ;
F_28 ( V_95 ) ;
return 0 ;
}
static int F_29 ( struct V_5 * V_6 , unsigned char * V_8 )
{
int V_10 = 0 ;
struct V_93 * V_14 = & V_6 -> V_14 ;
if ( V_14 -> V_98 ) {
F_15 ( V_6 -> V_14 . V_47 , L_27 ,
V_54 , V_14 -> V_98 , V_55 ) ;
V_8 [ 0 ] = V_14 -> V_98 ;
V_14 -> V_98 = 0 ;
V_10 = 1 ;
}
return V_10 ;
}
static int F_30 ( struct V_5 * V_6 , int V_92 )
{
struct V_94 * V_95 ;
int V_99 ;
struct V_93 * V_14 = & V_6 -> V_14 ;
V_14 = & V_6 -> V_14 ;
V_95 = F_25 ( & V_14 -> V_96 -> V_14 ) ;
if ( ! V_95 ) {
F_15 ( V_6 -> V_14 . V_47 , L_26 , V_54 ) ;
return 0 ;
}
V_99 = F_31 ( V_95 , V_92 ) ;
if ( V_99 < V_92 )
F_32 ( V_14 -> V_47 , L_28 ,
V_92 - V_99 ) ;
if ( ! V_99 )
return V_99 ;
F_26 ( V_95 , F_33 ( & V_6 -> V_100 ) , V_92 ) ;
V_14 -> V_101 . V_102 += V_99 ;
F_28 ( V_95 ) ;
return V_99 ;
}
static void F_34 ( struct V_93 * V_14 )
{
struct V_5 * V_6 ;
V_6 = F_35 ( V_14 , struct V_5 , V_14 ) ;
if ( V_6 -> V_103 ) {
F_36 ( V_6 -> V_103 ) ;
V_6 -> V_103 = NULL ;
}
if ( V_6 -> V_104 ) {
F_36 ( V_6 -> V_104 ) ;
V_6 -> V_104 = NULL ;
}
if ( V_6 -> V_105 ) {
F_37 ( V_14 -> V_47 , V_14 -> V_106 , V_6 -> V_107 ,
V_6 -> V_105 ) ;
V_6 -> V_107 = NULL ;
V_6 -> V_105 = 0 ;
}
return;
}
static bool F_38 ( struct V_108 * V_109 , void * V_110 )
{
struct V_111 * V_112 = V_110 ;
if ( ( V_109 -> V_113 == V_112 -> V_113 ) && ( V_112 -> V_114 ==
V_109 -> V_115 -> V_47 ) ) {
V_109 -> V_116 = V_112 ;
return true ;
} else {
return false ;
}
}
static void F_39 ( struct V_93 * V_14 )
{
T_7 V_117 ;
struct V_108 * V_109 ;
struct V_118 * V_114 ;
struct V_111 * V_112 ;
struct V_5 * V_6 =
F_35 ( V_14 , struct V_5 , V_14 ) ;
F_40 ( V_117 ) ;
F_41 ( V_119 , V_117 ) ;
V_114 = F_42 ( V_6 -> V_120 -> V_121 -> V_122 ,
F_43 ( 0xa , 0 ) ) ;
V_112 = & V_6 -> V_123 ;
V_112 -> V_114 = & V_114 -> V_47 ;
V_112 -> V_113 = V_6 -> V_14 . line * 2 ;
V_112 -> V_124 = V_14 -> V_125 + V_126 ;
V_109 = F_44 ( V_117 , F_38 , V_112 ) ;
if ( ! V_109 ) {
F_14 ( V_6 -> V_14 . V_47 , L_29 ,
V_54 ) ;
return;
}
V_6 -> V_103 = V_109 ;
V_112 = & V_6 -> V_127 ;
V_112 -> V_114 = & V_114 -> V_47 ;
V_112 -> V_113 = V_6 -> V_14 . line * 2 + 1 ;
V_112 -> V_128 = V_14 -> V_125 + V_129 ;
V_109 = F_44 ( V_117 , F_38 , V_112 ) ;
if ( ! V_109 ) {
F_14 ( V_6 -> V_14 . V_47 , L_30 ,
V_54 ) ;
F_36 ( V_6 -> V_103 ) ;
V_6 -> V_103 = NULL ;
return;
}
V_6 -> V_107 = F_45 ( V_14 -> V_47 , V_14 -> V_106 ,
& V_6 -> V_105 , V_13 ) ;
V_6 -> V_104 = V_109 ;
}
static void F_46 ( void * V_130 )
{
struct V_5 * V_6 = V_130 ;
struct V_93 * V_14 = & V_6 -> V_14 ;
struct V_94 * V_95 = F_25 ( & V_14 -> V_96 -> V_14 ) ;
int V_3 ;
if ( ! V_95 ) {
F_15 ( V_6 -> V_14 . V_47 , L_26 , V_54 ) ;
return;
}
F_47 ( V_14 -> V_47 , & V_6 -> V_100 , 1 , V_131 ) ;
V_3 = F_30 ( V_6 , V_6 -> V_69 ) ;
if ( V_3 )
F_27 ( V_95 ) ;
F_28 ( V_95 ) ;
F_48 ( V_6 -> V_132 ) ;
F_10 ( V_6 , V_133 ) ;
}
static void F_49 ( void * V_130 )
{
struct V_5 * V_6 = V_130 ;
struct V_93 * V_14 = & V_6 -> V_14 ;
struct V_134 * V_135 = & V_14 -> V_96 -> V_135 ;
struct V_136 * V_137 = V_6 -> V_138 ;
int V_79 ;
for ( V_79 = 0 ; V_79 < V_6 -> V_139 ; V_79 ++ , V_137 ++ ) {
V_135 -> V_140 += F_50 ( V_137 ) ;
V_14 -> V_101 . V_141 += F_50 ( V_137 ) ;
}
V_135 -> V_140 &= V_142 - 1 ;
F_48 ( V_6 -> V_143 ) ;
F_51 ( V_14 -> V_47 , V_137 , V_6 -> V_139 , V_144 ) ;
V_6 -> V_145 = 0 ;
V_6 -> V_139 = 0 ;
F_6 ( V_6 -> V_138 ) ;
F_10 ( V_6 , V_146 ) ;
}
static int F_52 ( struct V_5 * V_6 , int V_92 )
{
int V_3 = 0 ;
struct V_93 * V_14 = & V_6 -> V_14 ;
struct V_134 * V_135 = & V_14 -> V_96 -> V_135 ;
if ( F_53 ( V_14 ) || F_54 ( V_135 ) || V_3 >= V_92 )
goto V_147;
do {
int V_148 =
F_55 ( V_135 -> V_149 , V_135 -> V_140 , V_142 ) ;
int V_150 = F_56 ( V_92 - V_3 , V_148 ) ;
F_19 ( V_6 , & V_135 -> V_8 [ V_135 -> V_140 ] , V_150 ) ;
V_135 -> V_140 = ( V_135 -> V_140 + V_150 ) & ( V_142 - 1 ) ;
V_3 += V_150 ;
} while ( ! F_54 ( V_135 ) && V_3 < V_92 );
V_147:
F_15 ( V_6 -> V_14 . V_47 , L_31 ,
V_3 , V_92 - V_3 , V_55 ) ;
return V_3 ;
}
static int F_57 ( struct V_5 * V_6 )
{
struct V_151 * V_8 ;
int V_82 ;
int V_10 ;
if ( ! V_6 -> V_152 ) {
F_11 ( V_6 , V_133 ) ;
return 0 ;
}
V_8 = & V_6 -> V_153 ;
do {
V_82 = F_20 ( V_6 , V_8 -> V_8 , V_8 -> V_92 ) ;
V_10 = F_24 ( V_6 , V_8 -> V_8 , V_82 ) ;
if ( V_10 )
return 0 ;
} while ( V_82 == V_8 -> V_92 );
return V_154 ;
}
static int F_58 ( struct V_5 * V_6 )
{
return F_57 ( V_6 ) ;
}
static int F_59 ( struct V_5 * V_6 )
{
struct V_93 * V_14 = & V_6 -> V_14 ;
struct V_155 * V_156 ;
struct V_136 * V_137 ;
V_6 = F_35 ( V_14 , struct V_5 , V_14 ) ;
V_137 = & V_6 -> V_100 ;
F_60 ( & V_6 -> V_100 , 1 ) ;
F_50 ( V_137 ) = V_6 -> V_69 ;
F_61 ( & V_6 -> V_100 , F_62 ( V_6 -> V_107 ) ,
F_50 ( V_137 ) , ( unsigned long ) V_6 -> V_107 &
~ V_157 ) ;
F_63 ( V_137 ) = V_6 -> V_105 ;
V_156 = F_64 ( V_6 -> V_104 ,
V_137 , 1 , V_158 ,
V_159 | V_160 ) ;
if ( ! V_156 )
return 0 ;
V_6 -> V_132 = V_156 ;
V_156 -> V_161 = F_46 ;
V_156 -> V_162 = V_6 ;
V_156 -> V_163 ( V_156 ) ;
F_65 ( V_6 -> V_104 ) ;
return V_154 ;
}
static unsigned int F_66 ( struct V_5 * V_6 )
{
struct V_93 * V_14 = & V_6 -> V_14 ;
struct V_134 * V_135 = & V_14 -> V_96 -> V_135 ;
int V_64 ;
int V_78 ;
int V_92 ;
int V_164 ;
if ( ! V_6 -> V_165 ) {
F_67 ( V_6 -> V_14 . V_47 , L_32 ,
V_54 , V_55 ) ;
F_11 ( V_6 , V_146 ) ;
V_6 -> V_164 = 1 ;
return 0 ;
}
V_64 = F_68 ( V_6 -> V_64 , 1 ) ;
V_164 = 1 ;
if ( F_29 ( V_6 , V_135 -> V_8 ) ) {
F_19 ( V_6 , V_135 -> V_8 , 1 ) ;
V_14 -> V_101 . V_141 ++ ;
V_164 = 0 ;
V_64 -- ;
}
V_92 = F_56 ( V_135 -> V_149 - V_135 -> V_140 , V_64 ) ;
if ( V_92 < 0 )
V_92 = V_64 ;
V_78 = F_52 ( V_6 , V_92 ) ;
if ( V_78 > 0 ) {
V_14 -> V_101 . V_141 += V_78 ;
V_164 = 0 ;
}
V_6 -> V_164 = V_164 ;
if ( V_164 ) {
F_11 ( V_6 , V_146 ) ;
F_69 ( V_14 ) ;
}
return V_166 ;
}
static unsigned int F_70 ( struct V_5 * V_6 )
{
struct V_93 * V_14 = & V_6 -> V_14 ;
struct V_134 * V_135 = & V_14 -> V_96 -> V_135 ;
struct V_136 * V_137 ;
int V_139 ;
int V_64 ;
int V_164 ;
struct V_155 * V_156 ;
int V_167 ;
int V_79 ;
int V_168 ;
int V_92 ;
int V_169 ;
if ( ! V_6 -> V_165 ) {
F_67 ( V_6 -> V_14 . V_47 , L_32 ,
V_54 , V_55 ) ;
F_11 ( V_6 , V_146 ) ;
V_6 -> V_164 = 1 ;
return 0 ;
}
if ( V_6 -> V_145 ) {
F_15 ( V_6 -> V_14 . V_47 , L_33 ,
V_54 , V_55 ) ;
F_11 ( V_6 , V_146 ) ;
V_6 -> V_164 = 1 ;
return 0 ;
}
V_64 = F_68 ( V_6 -> V_64 , 1 ) ;
V_164 = 1 ;
if ( F_29 ( V_6 , V_135 -> V_8 ) ) {
F_19 ( V_6 , V_135 -> V_8 , 1 ) ;
V_14 -> V_101 . V_141 ++ ;
V_164 = 0 ;
V_64 -- ;
}
V_168 = F_56 ( ( int ) F_71 ( V_135 -> V_149 , V_135 -> V_140 ,
V_142 ) , F_55 ( V_135 -> V_149 ,
V_135 -> V_140 , V_142 ) ) ;
if ( ! V_168 ) {
F_15 ( V_6 -> V_14 . V_47 , L_34 , V_54 ) ;
F_11 ( V_6 , V_146 ) ;
F_69 ( V_14 ) ;
return 0 ;
}
if ( V_168 > V_64 ) {
V_167 = V_168 / V_64 + 1 ;
V_92 = V_64 ;
V_169 = V_168 % V_64 ;
} else {
V_167 = 1 ;
V_92 = V_168 ;
V_169 = V_168 ;
}
F_15 ( V_6 -> V_14 . V_47 , L_35 ,
V_54 , V_167 , V_92 , V_169 ) ;
V_6 -> V_145 = 1 ;
V_6 -> V_138 = F_2 ( sizeof( struct V_136 ) * V_167 , V_170 ) ;
F_60 ( V_6 -> V_138 , V_167 ) ;
V_137 = V_6 -> V_138 ;
for ( V_79 = 0 ; V_79 < V_167 ; V_79 ++ , V_137 ++ ) {
if ( V_79 == ( V_167 - 1 ) )
F_61 ( V_137 , F_62 ( V_135 -> V_8 ) ,
V_169 , V_64 * V_79 ) ;
else
F_61 ( V_137 , F_62 ( V_135 -> V_8 ) ,
V_92 , V_64 * V_79 ) ;
}
V_137 = V_6 -> V_138 ;
V_139 = F_72 ( V_14 -> V_47 , V_137 , V_167 , V_144 ) ;
if ( ! V_139 ) {
F_14 ( V_6 -> V_14 . V_47 , L_36 , V_54 ) ;
return 0 ;
}
V_6 -> V_139 = V_139 ;
for ( V_79 = 0 ; V_79 < V_139 ; V_79 ++ , V_137 ++ ) {
V_137 -> V_171 = ( V_135 -> V_140 & ( V_142 - 1 ) ) +
V_64 * V_79 ;
F_63 ( V_137 ) = ( F_63 ( V_137 ) &
~ ( V_142 - 1 ) ) + V_137 -> V_171 ;
if ( V_79 == ( V_139 - 1 ) )
F_50 ( V_137 ) = V_169 ;
else
F_50 ( V_137 ) = V_92 ;
}
V_156 = F_64 ( V_6 -> V_103 ,
V_6 -> V_138 , V_139 , V_172 ,
V_159 | V_160 ) ;
if ( ! V_156 ) {
F_14 ( V_6 -> V_14 . V_47 , L_37 ,
V_54 ) ;
return 0 ;
}
F_73 ( V_14 -> V_47 , V_6 -> V_138 , V_139 , V_144 ) ;
V_6 -> V_143 = V_156 ;
V_156 -> V_161 = F_49 ;
V_156 -> V_162 = V_6 ;
V_156 -> V_163 ( V_156 ) ;
F_65 ( V_6 -> V_103 ) ;
return V_166 ;
}
static void F_74 ( struct V_5 * V_6 , unsigned int V_84 )
{
T_6 V_61 = F_3 ( V_6 -> V_15 + V_62 ) ;
V_61 |= V_173 ;
F_4 ( V_61 , V_6 -> V_15 + V_62 ) ;
if ( V_84 & V_174 )
F_14 ( & V_6 -> V_120 -> V_47 , L_38 ) ;
if ( V_84 & V_175 )
F_14 ( & V_6 -> V_120 -> V_47 , L_39 ) ;
if ( V_84 & V_176 )
F_14 ( & V_6 -> V_120 -> V_47 , L_40 ) ;
if ( V_84 & V_177 )
F_14 ( & V_6 -> V_120 -> V_47 , L_41 ) ;
}
static T_8 F_75 ( int V_178 , void * V_179 )
{
struct V_5 * V_6 = V_179 ;
unsigned int V_180 ;
T_6 V_84 ;
int V_10 = 0 ;
unsigned char V_181 ;
unsigned long V_182 ;
int V_183 = 1 ;
T_6 V_75 ;
F_76 ( & V_6 -> V_14 . V_184 , V_182 ) ;
V_180 = 0 ;
while ( V_183 ) {
V_181 = F_21 ( V_6 ) ;
if ( V_181 & V_89 )
break;
switch ( V_181 ) {
case V_185 :
V_84 = F_22 ( V_6 ) ;
if ( V_84 & ( V_174 | V_175 |
V_176 | V_177 ) ) {
F_74 ( V_6 , V_84 ) ;
V_10 = V_186 ;
} else {
V_10 = V_187 ;
}
break;
case V_188 :
if ( V_6 -> V_189 ) {
F_11 ( V_6 ,
V_133 ) ;
V_10 = F_59 ( V_6 ) ;
if ( ! V_10 )
F_10 ( V_6 ,
V_133 ) ;
} else {
V_10 = F_58 ( V_6 ) ;
}
break;
case V_190 :
V_10 = F_57 ( V_6 ) ;
break;
case V_191 :
if ( V_6 -> V_189 )
V_10 = F_70 ( V_6 ) ;
else
V_10 = F_66 ( V_6 ) ;
break;
case V_192 :
V_75 = F_18 ( V_6 ) ;
V_183 = 0 ;
if ( ( V_75 & V_193 ) == 0 )
break;
V_10 |= V_194 ;
break;
default:
F_14 ( V_6 -> V_14 . V_47 , L_42 , V_54 ,
V_181 , V_55 ) ;
V_10 = - 1 ;
V_183 = 0 ;
break;
}
V_180 |= ( unsigned int ) V_10 ;
}
F_77 ( & V_6 -> V_14 . V_184 , V_182 ) ;
return F_78 ( V_180 ) ;
}
static unsigned int F_79 ( struct V_93 * V_14 )
{
struct V_5 * V_6 ;
V_6 = F_35 ( V_14 , struct V_5 , V_14 ) ;
if ( V_6 -> V_164 )
return V_195 ;
else
return 0 ;
}
static unsigned int F_80 ( struct V_93 * V_14 )
{
struct V_5 * V_6 ;
T_6 V_196 ;
unsigned int V_10 = 0 ;
V_6 = F_35 ( V_14 , struct V_5 , V_14 ) ;
V_196 = F_18 ( V_6 ) ;
if ( V_196 & V_197 )
V_10 |= V_198 ;
if ( V_196 & V_199 )
V_10 |= V_200 ;
if ( V_196 & V_201 )
V_10 |= V_202 ;
if ( V_196 & V_203 )
V_10 |= V_204 ;
return V_10 ;
}
static void F_81 ( struct V_93 * V_14 , unsigned int V_205 )
{
T_5 V_206 = 0 ;
struct V_5 * V_6 = F_35 ( V_14 , struct V_5 , V_14 ) ;
if ( V_205 & V_207 )
V_206 |= V_208 ;
if ( V_205 & V_209 )
V_206 |= V_210 ;
if ( V_205 & V_211 )
V_206 |= V_212 ;
if ( V_6 -> V_206 & V_213 )
V_206 |= V_213 ;
if ( V_205 )
F_4 ( V_206 , V_6 -> V_15 + V_19 ) ;
}
static void F_82 ( struct V_93 * V_14 )
{
struct V_5 * V_6 ;
V_6 = F_35 ( V_14 , struct V_5 , V_14 ) ;
V_6 -> V_165 = 0 ;
V_6 -> V_145 = 0 ;
}
static void F_83 ( struct V_93 * V_14 )
{
struct V_5 * V_6 ;
V_6 = F_35 ( V_14 , struct V_5 , V_14 ) ;
if ( V_6 -> V_189 ) {
if ( V_6 -> V_145 ) {
F_15 ( V_6 -> V_14 . V_47 , L_43 ,
V_54 ) ;
return;
}
}
V_6 -> V_165 = 1 ;
F_10 ( V_6 , V_146 ) ;
}
static void F_84 ( struct V_93 * V_14 )
{
struct V_5 * V_6 ;
V_6 = F_35 ( V_14 , struct V_5 , V_14 ) ;
V_6 -> V_152 = 0 ;
F_11 ( V_6 , V_133 ) ;
}
static void F_85 ( struct V_93 * V_14 )
{
struct V_5 * V_6 ;
V_6 = F_35 ( V_14 , struct V_5 , V_14 ) ;
F_10 ( V_6 , V_214 ) ;
}
static void F_86 ( struct V_93 * V_14 , int V_215 )
{
struct V_5 * V_6 ;
unsigned long V_182 ;
V_6 = F_35 ( V_14 , struct V_5 , V_14 ) ;
F_76 ( & V_14 -> V_184 , V_182 ) ;
F_23 ( V_6 , V_215 ) ;
F_77 ( & V_14 -> V_184 , V_182 ) ;
}
static int F_87 ( struct V_93 * V_14 )
{
struct V_5 * V_6 ;
int V_10 ;
int V_64 ;
int V_69 ;
V_6 = F_35 ( V_14 , struct V_5 , V_14 ) ;
V_6 -> V_164 = 1 ;
if ( V_14 -> V_45 )
V_6 -> V_45 = V_14 -> V_45 ;
else
V_14 -> V_45 = V_6 -> V_45 ;
F_11 ( V_6 , V_216 ) ;
V_10 = F_12 ( V_6 , V_217 ,
V_218 , V_219 ,
V_220 ) ;
if ( V_10 )
return V_10 ;
switch ( V_6 -> V_64 ) {
case 256 :
V_64 = V_221 ;
break;
case 64 :
V_64 = V_222 ;
break;
case 16 :
V_64 = V_223 ;
case 1 :
default:
V_64 = V_224 ;
break;
}
switch ( V_6 -> V_65 ) {
case V_225 :
V_69 = 1 ;
break;
case V_226 :
V_69 = V_6 -> V_64 / 4 ;
break;
case V_227 :
V_69 = V_6 -> V_64 / 2 ;
break;
case V_228 :
default:
V_69 = V_6 -> V_64 - ( V_6 -> V_64 / 8 ) ;
break;
}
V_6 -> V_69 = V_69 ;
V_10 = F_17 ( V_6 , V_229 ,
V_64 , V_6 -> V_65 ) ;
if ( V_10 < 0 )
return V_10 ;
V_10 = F_88 ( V_6 -> V_14 . V_178 , F_75 , V_230 ,
V_231 , V_6 ) ;
if ( V_10 < 0 )
return V_10 ;
if ( V_6 -> V_189 )
F_39 ( V_14 ) ;
V_6 -> V_152 = 1 ;
F_10 ( V_6 , V_133 ) ;
F_89 ( V_14 , V_232 , V_217 ) ;
return 0 ;
}
static void F_90 ( struct V_93 * V_14 )
{
struct V_5 * V_6 ;
int V_10 ;
V_6 = F_35 ( V_14 , struct V_5 , V_14 ) ;
F_11 ( V_6 , V_216 ) ;
F_16 ( V_6 , V_233 ) ;
V_10 = F_17 ( V_6 , V_229 ,
V_224 , V_225 ) ;
if ( V_10 )
F_14 ( V_6 -> V_14 . V_47 ,
L_44 , V_10 ) ;
F_34 ( V_14 ) ;
F_91 ( V_6 -> V_14 . V_178 , V_6 ) ;
}
static void F_92 ( struct V_93 * V_14 ,
struct V_234 * V_235 , struct V_234 * V_236 )
{
int V_39 ;
int V_237 ;
unsigned int V_40 , V_41 , V_42 ;
struct V_5 * V_6 ;
unsigned long V_182 ;
V_6 = F_35 ( V_14 , struct V_5 , V_14 ) ;
switch ( V_235 -> V_238 & V_239 ) {
case V_240 :
V_41 = V_241 ;
break;
case V_242 :
V_41 = V_243 ;
break;
case V_244 :
V_41 = V_245 ;
break;
default:
V_41 = V_219 ;
break;
}
if ( V_235 -> V_238 & V_246 )
V_42 = V_247 ;
else
V_42 = V_220 ;
if ( V_235 -> V_238 & V_248 ) {
if ( ! ( V_235 -> V_238 & V_249 ) )
V_40 = V_250 ;
else
V_40 = V_251 ;
} else
V_40 = V_218 ;
if ( ( V_235 -> V_238 & V_252 ) && ( V_6 -> V_64 == 256 ) )
V_6 -> V_206 |= V_213 ;
else
V_6 -> V_206 &= ~ V_213 ;
V_235 -> V_238 &= ~ V_253 ;
V_39 = F_93 ( V_14 , V_235 , V_236 , 0 , V_14 -> V_45 / 16 ) ;
F_76 ( & V_14 -> V_184 , V_182 ) ;
F_89 ( V_14 , V_235 -> V_238 , V_39 ) ;
V_237 = F_12 ( V_6 , V_39 , V_40 , V_41 , V_42 ) ;
if ( V_237 )
goto V_254;
F_81 ( & V_6 -> V_14 , V_6 -> V_14 . V_205 ) ;
if ( F_94 ( V_235 ) )
F_95 ( V_235 , V_39 , V_39 ) ;
V_254:
F_77 ( & V_14 -> V_184 , V_182 ) ;
}
static const char * F_96 ( struct V_93 * V_14 )
{
return V_231 ;
}
static void F_97 ( struct V_93 * V_14 )
{
struct V_5 * V_6 ;
V_6 = F_35 ( V_14 , struct V_5 , V_14 ) ;
F_98 ( V_6 -> V_120 , V_6 -> V_15 ) ;
F_99 ( V_6 -> V_120 ) ;
}
static int F_100 ( struct V_93 * V_14 )
{
struct V_5 * V_6 ;
int V_10 ;
void T_9 * V_15 ;
V_6 = F_35 ( V_14 , struct V_5 , V_14 ) ;
V_10 = F_101 ( V_6 -> V_120 , V_231 ) ;
if ( V_10 < 0 )
return - V_97 ;
V_15 = F_102 ( V_6 -> V_120 , 1 , 0 ) ;
if ( ! V_15 ) {
F_99 ( V_6 -> V_120 ) ;
return - V_97 ;
}
V_6 -> V_15 = V_14 -> V_15 = V_15 ;
return 0 ;
}
static void F_103 ( struct V_93 * V_14 , int type )
{
struct V_5 * V_6 ;
V_6 = F_35 ( V_14 , struct V_5 , V_14 ) ;
if ( type & V_255 ) {
V_14 -> type = V_6 -> V_256 ;
F_100 ( V_14 ) ;
}
}
static int F_104 ( struct V_93 * V_14 ,
struct V_257 * V_258 )
{
struct V_5 * V_6 ;
V_6 = F_35 ( V_14 , struct V_5 , V_14 ) ;
if ( V_258 -> V_182 & V_259 ) {
F_67 ( V_6 -> V_14 . V_47 ,
L_45 ) ;
V_6 -> V_189 = 0 ;
V_258 -> V_182 &= ~ V_259 ;
} else {
#ifndef F_105
F_14 ( V_6 -> V_14 . V_47 , L_46 ,
V_54 ) ;
return - V_260 ;
#endif
F_67 ( V_6 -> V_14 . V_47 , L_47 ) ;
if ( ! V_6 -> V_189 )
F_39 ( V_14 ) ;
V_6 -> V_189 = 1 ;
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
if ( V_261 -> V_14 . V_182 & V_264 ) {
unsigned int V_263 ;
for ( V_263 = 1000000 ; V_263 ; V_263 -- ) {
unsigned int V_75 = F_3 ( V_261 -> V_15 + V_21 ) ;
if ( V_75 & V_203 )
break;
F_107 ( 1 ) ;
F_108 () ;
}
}
}
static void F_109 ( struct V_93 * V_14 , int V_265 )
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
unsigned long V_182 ;
T_6 V_37 ;
int V_270 = 1 ;
V_6 = V_271 [ V_268 -> V_272 ] ;
F_108 () ;
F_111 ( V_182 ) ;
if ( V_6 -> V_14 . V_273 ) {
V_270 = 0 ;
} else if ( V_274 ) {
V_270 = F_112 ( & V_6 -> V_14 . V_184 ) ;
} else
F_113 ( & V_6 -> V_14 . V_184 ) ;
V_37 = F_3 ( V_6 -> V_15 + V_16 ) ;
F_11 ( V_6 , V_216 ) ;
F_114 ( & V_6 -> V_14 , V_269 , V_3 , F_109 ) ;
F_106 ( V_6 , V_275 ) ;
F_4 ( V_37 , V_6 -> V_15 + V_16 ) ;
if ( V_270 )
F_115 ( & V_6 -> V_14 . V_184 ) ;
F_116 ( V_182 ) ;
}
static int T_10 F_117 ( struct V_267 * V_268 , char * V_276 )
{
struct V_93 * V_14 ;
int V_39 = V_217 ;
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
static struct V_5 * F_120 ( struct V_118 * V_120 ,
const struct V_281 * V_282 )
{
struct V_5 * V_6 ;
int V_10 ;
unsigned int V_279 ;
unsigned int V_125 ;
unsigned char * V_153 ;
int V_106 ;
int V_256 ;
struct V_283 * V_284 ;
char V_285 [ 32 ] ;
V_284 = & V_286 [ V_282 -> V_287 ] ;
V_256 = V_284 -> V_256 ;
V_6 = F_2 ( sizeof( struct V_5 ) , V_13 ) ;
if ( V_6 == NULL )
goto V_288;
V_153 = ( unsigned char * ) F_121 ( V_13 ) ;
if ( ! V_153 )
goto V_289;
switch ( V_256 ) {
case V_290 :
V_106 = 256 ;
break;
case V_291 :
V_106 = 64 ;
break;
default:
F_14 ( & V_120 -> V_47 , L_48 , V_256 ) ;
goto V_292;
}
F_122 ( V_120 ) ;
F_123 ( V_120 ) ;
V_279 = F_124 ( V_120 , 0 ) ;
V_125 = F_124 ( V_120 , 1 ) ;
V_6 -> V_125 = V_125 ;
V_6 -> V_279 = V_279 ;
V_6 -> V_120 = V_120 ;
V_6 -> V_164 = 1 ;
V_6 -> V_153 . V_8 = V_153 ;
V_6 -> V_153 . V_92 = V_293 ;
V_6 -> V_64 = V_106 ;
V_6 -> V_45 = F_7 () ;
V_6 -> V_256 = V_294 + V_256 + 1 ;
V_6 -> V_14 . V_47 = & V_120 -> V_47 ;
V_6 -> V_14 . V_279 = V_279 ;
V_6 -> V_14 . V_15 = NULL ;
V_6 -> V_14 . V_125 = V_125 ;
V_6 -> V_14 . V_178 = V_120 -> V_178 ;
V_6 -> V_14 . V_295 = V_296 ;
V_6 -> V_14 . V_297 = & V_298 ;
V_6 -> V_14 . V_182 = V_299 ;
V_6 -> V_14 . V_106 = V_106 ;
V_6 -> V_14 . line = V_284 -> V_300 ;
V_6 -> V_65 = V_227 ;
F_125 ( & V_6 -> V_14 . V_184 ) ;
F_126 ( V_120 , V_6 ) ;
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
F_131 ( ( unsigned long ) V_153 ) ;
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
F_126 ( V_6 -> V_120 , NULL ) ;
F_131 ( ( unsigned long ) V_6 -> V_153 . V_8 ) ;
}
static void F_135 ( struct V_118 * V_120 )
{
struct V_5 * V_6 = F_136 ( V_120 ) ;
F_137 ( V_120 ) ;
#ifdef F_127
V_271 [ V_6 -> V_14 . line ] = NULL ;
#endif
F_132 ( V_6 ) ;
F_138 ( V_120 ) ;
F_6 ( V_6 ) ;
return;
}
static int F_139 ( struct V_118 * V_120 , T_11 V_96 )
{
struct V_5 * V_6 = F_136 ( V_120 ) ;
F_140 ( & V_301 , & V_6 -> V_14 ) ;
F_141 ( V_120 ) ;
F_142 ( V_120 , F_143 ( V_120 , V_96 ) ) ;
return 0 ;
}
static int F_144 ( struct V_118 * V_120 )
{
struct V_5 * V_6 = F_136 ( V_120 ) ;
int V_10 ;
F_142 ( V_120 , V_306 ) ;
F_145 ( V_120 ) ;
V_10 = F_146 ( V_120 ) ;
if ( V_10 ) {
F_14 ( & V_120 -> V_47 ,
L_50 , V_54 , V_10 ) ;
return V_10 ;
}
F_147 ( & V_301 , & V_6 -> V_14 ) ;
return 0 ;
}
static int T_12 F_148 ( struct V_118 * V_120 ,
const struct V_281 * V_282 )
{
int V_10 ;
struct V_5 * V_6 ;
V_10 = F_146 ( V_120 ) ;
if ( V_10 < 0 )
goto V_307;
V_6 = F_120 ( V_120 , V_282 ) ;
if ( ! V_6 ) {
V_10 = - V_97 ;
goto V_308;
}
F_126 ( V_120 , V_6 ) ;
return V_10 ;
V_308:
F_137 ( V_120 ) ;
F_138 ( V_120 ) ;
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
