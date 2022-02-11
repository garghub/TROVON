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
struct V_85 * V_14 = & V_6 -> V_14 ;
V_84 = F_3 ( V_6 -> V_15 + V_20 ) ;
for ( V_79 = 0 , V_84 = F_3 ( V_6 -> V_15 + V_20 ) ;
V_79 < V_82 && V_84 & ( V_86 | V_87 ) ;
V_84 = F_3 ( V_6 -> V_15 + V_20 ) ) {
V_83 = F_3 ( V_6 -> V_15 + V_88 ) ;
if ( V_84 & V_87 ) {
V_14 -> V_89 . V_90 ++ ;
if ( F_21 ( V_14 ) )
continue;
}
#ifdef F_22
if ( V_14 -> V_91 ) {
if ( F_23 ( V_14 , V_83 ) )
continue;
}
#endif
V_8 [ V_79 ++ ] = V_83 ;
}
return V_79 ;
}
static unsigned char F_24 ( struct V_5 * V_6 )
{
return F_3 ( V_6 -> V_15 + V_17 ) &\
( V_92 | V_93 | V_94 ) ;
}
static T_6 F_25 ( struct V_5 * V_6 )
{
return F_3 ( V_6 -> V_15 + V_20 ) ;
}
static void F_26 ( struct V_5 * V_6 , int V_95 )
{
unsigned int V_11 ;
V_11 = F_3 ( V_6 -> V_15 + V_18 ) ;
if ( V_95 )
V_11 |= V_96 ;
else
V_11 &= ~ V_96 ;
F_4 ( V_11 , V_6 -> V_15 + V_18 ) ;
}
static int F_27 ( struct V_5 * V_6 , const unsigned char * V_8 ,
int V_97 )
{
struct V_85 * V_14 = & V_6 -> V_14 ;
struct V_98 * V_99 = & V_14 -> V_100 -> V_14 ;
F_28 ( V_99 , V_8 , V_97 ) ;
F_29 ( V_99 ) ;
return 0 ;
}
static int F_30 ( struct V_5 * V_6 , unsigned char * V_8 )
{
int V_10 = 0 ;
struct V_85 * V_14 = & V_6 -> V_14 ;
if ( V_14 -> V_101 ) {
F_15 ( V_6 -> V_14 . V_47 , L_26 ,
V_54 , V_14 -> V_101 , V_55 ) ;
V_8 [ 0 ] = V_14 -> V_101 ;
V_14 -> V_101 = 0 ;
V_10 = 1 ;
}
return V_10 ;
}
static int F_31 ( struct V_5 * V_6 , int V_97 )
{
struct V_102 * V_103 ;
int V_104 ;
struct V_85 * V_14 = & V_6 -> V_14 ;
struct V_98 * V_99 = & V_14 -> V_100 -> V_14 ;
V_14 = & V_6 -> V_14 ;
V_103 = F_32 ( V_99 ) ;
if ( ! V_103 ) {
F_15 ( V_6 -> V_14 . V_47 , L_27 , V_54 ) ;
return 0 ;
}
V_104 = F_33 ( V_99 , V_97 ) ;
if ( V_104 < V_97 )
F_34 ( V_14 -> V_47 , L_28 ,
V_97 - V_104 ) ;
if ( ! V_104 )
return V_104 ;
F_28 ( V_99 , F_35 ( & V_6 -> V_105 ) , V_97 ) ;
V_14 -> V_89 . V_106 += V_104 ;
F_36 ( V_103 ) ;
return V_104 ;
}
static void F_37 ( struct V_85 * V_14 )
{
struct V_5 * V_6 ;
V_6 = F_38 ( V_14 , struct V_5 , V_14 ) ;
if ( V_6 -> V_107 ) {
F_39 ( V_6 -> V_107 ) ;
V_6 -> V_107 = NULL ;
}
if ( V_6 -> V_108 ) {
F_39 ( V_6 -> V_108 ) ;
V_6 -> V_108 = NULL ;
}
if ( V_6 -> V_109 ) {
F_40 ( V_14 -> V_47 , V_14 -> V_110 , V_6 -> V_111 ,
V_6 -> V_109 ) ;
V_6 -> V_111 = NULL ;
V_6 -> V_109 = 0 ;
}
return;
}
static bool F_41 ( struct V_112 * V_113 , void * V_114 )
{
struct V_115 * V_116 = V_114 ;
if ( ( V_113 -> V_117 == V_116 -> V_117 ) && ( V_116 -> V_118 ==
V_113 -> V_119 -> V_47 ) ) {
V_113 -> V_120 = V_116 ;
return true ;
} else {
return false ;
}
}
static void F_42 ( struct V_85 * V_14 )
{
T_7 V_121 ;
struct V_112 * V_113 ;
struct V_122 * V_118 ;
struct V_115 * V_116 ;
struct V_5 * V_6 =
F_38 ( V_14 , struct V_5 , V_14 ) ;
F_43 ( V_121 ) ;
F_44 ( V_123 , V_121 ) ;
V_118 = F_45 ( V_6 -> V_124 -> V_125 -> V_126 ,
F_46 ( 0xa , 0 ) ) ;
V_116 = & V_6 -> V_127 ;
V_116 -> V_118 = & V_118 -> V_47 ;
V_116 -> V_117 = V_6 -> V_14 . line * 2 ;
V_116 -> V_128 = V_14 -> V_129 + V_130 ;
V_113 = F_47 ( V_121 , F_41 , V_116 ) ;
if ( ! V_113 ) {
F_14 ( V_6 -> V_14 . V_47 , L_29 ,
V_54 ) ;
return;
}
V_6 -> V_107 = V_113 ;
V_116 = & V_6 -> V_131 ;
V_116 -> V_118 = & V_118 -> V_47 ;
V_116 -> V_117 = V_6 -> V_14 . line * 2 + 1 ;
V_116 -> V_132 = V_14 -> V_129 + V_133 ;
V_113 = F_47 ( V_121 , F_41 , V_116 ) ;
if ( ! V_113 ) {
F_14 ( V_6 -> V_14 . V_47 , L_30 ,
V_54 ) ;
F_39 ( V_6 -> V_107 ) ;
V_6 -> V_107 = NULL ;
return;
}
V_6 -> V_111 = F_48 ( V_14 -> V_47 , V_14 -> V_110 ,
& V_6 -> V_109 , V_13 ) ;
V_6 -> V_108 = V_113 ;
}
static void F_49 ( void * V_134 )
{
struct V_5 * V_6 = V_134 ;
struct V_85 * V_14 = & V_6 -> V_14 ;
int V_3 ;
F_50 ( V_14 -> V_47 , & V_6 -> V_105 , 1 , V_135 ) ;
V_3 = F_31 ( V_6 , V_6 -> V_69 ) ;
if ( V_3 )
F_29 ( & V_14 -> V_100 -> V_14 ) ;
F_51 ( V_6 -> V_136 ) ;
F_10 ( V_6 , V_137 |
V_138 ) ;
}
static void F_52 ( void * V_134 )
{
struct V_5 * V_6 = V_134 ;
struct V_85 * V_14 = & V_6 -> V_14 ;
struct V_139 * V_140 = & V_14 -> V_100 -> V_140 ;
struct V_141 * V_142 = V_6 -> V_143 ;
int V_79 ;
for ( V_79 = 0 ; V_79 < V_6 -> V_144 ; V_79 ++ , V_142 ++ ) {
V_140 -> V_145 += F_53 ( V_142 ) ;
V_14 -> V_89 . V_146 += F_53 ( V_142 ) ;
}
V_140 -> V_145 &= V_147 - 1 ;
F_51 ( V_6 -> V_148 ) ;
F_54 ( V_14 -> V_47 , V_142 , V_6 -> V_144 , V_149 ) ;
V_6 -> V_150 = 0 ;
V_6 -> V_144 = 0 ;
F_6 ( V_6 -> V_143 ) ;
F_10 ( V_6 , V_151 ) ;
}
static int F_55 ( struct V_5 * V_6 , int V_97 )
{
int V_3 = 0 ;
struct V_85 * V_14 = & V_6 -> V_14 ;
struct V_139 * V_140 = & V_14 -> V_100 -> V_140 ;
if ( F_56 ( V_14 ) || F_57 ( V_140 ) || V_3 >= V_97 )
goto V_152;
do {
int V_153 =
F_58 ( V_140 -> V_154 , V_140 -> V_145 , V_147 ) ;
int V_155 = F_59 ( V_97 - V_3 , V_153 ) ;
F_19 ( V_6 , & V_140 -> V_8 [ V_140 -> V_145 ] , V_155 ) ;
V_140 -> V_145 = ( V_140 -> V_145 + V_155 ) & ( V_147 - 1 ) ;
V_3 += V_155 ;
} while ( ! F_57 ( V_140 ) && V_3 < V_97 );
V_152:
F_15 ( V_6 -> V_14 . V_47 , L_31 ,
V_3 , V_97 - V_3 , V_55 ) ;
return V_3 ;
}
static int F_60 ( struct V_5 * V_6 )
{
struct V_156 * V_8 ;
int V_82 ;
int V_10 ;
if ( ! V_6 -> V_157 ) {
F_11 ( V_6 , V_137 |
V_138 ) ;
return 0 ;
}
V_8 = & V_6 -> V_158 ;
do {
V_82 = F_20 ( V_6 , V_8 -> V_8 , V_8 -> V_97 ) ;
V_10 = F_27 ( V_6 , V_8 -> V_8 , V_82 ) ;
if ( V_10 )
return 0 ;
} while ( V_82 == V_8 -> V_97 );
return V_159 ;
}
static int F_61 ( struct V_5 * V_6 )
{
return F_60 ( V_6 ) ;
}
static int F_62 ( struct V_5 * V_6 )
{
struct V_85 * V_14 = & V_6 -> V_14 ;
struct V_160 * V_161 ;
struct V_141 * V_142 ;
V_6 = F_38 ( V_14 , struct V_5 , V_14 ) ;
V_142 = & V_6 -> V_105 ;
F_63 ( & V_6 -> V_105 , 1 ) ;
F_53 ( V_142 ) = V_6 -> V_69 ;
F_64 ( & V_6 -> V_105 , F_65 ( V_6 -> V_111 ) ,
F_53 ( V_142 ) , ( unsigned long ) V_6 -> V_111 &
~ V_162 ) ;
F_66 ( V_142 ) = V_6 -> V_109 ;
V_161 = F_67 ( V_6 -> V_108 ,
V_142 , 1 , V_163 ,
V_164 | V_165 ) ;
if ( ! V_161 )
return 0 ;
V_6 -> V_136 = V_161 ;
V_161 -> V_166 = F_49 ;
V_161 -> V_167 = V_6 ;
V_161 -> V_168 ( V_161 ) ;
F_68 ( V_6 -> V_108 ) ;
return V_159 ;
}
static unsigned int F_69 ( struct V_5 * V_6 )
{
struct V_85 * V_14 = & V_6 -> V_14 ;
struct V_139 * V_140 = & V_14 -> V_100 -> V_140 ;
int V_64 ;
int V_78 ;
int V_97 ;
int V_169 ;
if ( ! V_6 -> V_170 ) {
F_70 ( V_6 -> V_14 . V_47 , L_32 ,
V_54 , V_55 ) ;
F_11 ( V_6 , V_151 ) ;
V_6 -> V_169 = 1 ;
return 0 ;
}
V_64 = F_71 ( V_6 -> V_64 , 1 ) ;
V_169 = 1 ;
if ( F_30 ( V_6 , V_140 -> V_8 ) ) {
F_19 ( V_6 , V_140 -> V_8 , 1 ) ;
V_14 -> V_89 . V_146 ++ ;
V_169 = 0 ;
V_64 -- ;
}
V_97 = F_59 ( V_140 -> V_154 - V_140 -> V_145 , V_64 ) ;
if ( V_97 < 0 )
V_97 = V_64 ;
V_78 = F_55 ( V_6 , V_97 ) ;
if ( V_78 > 0 ) {
V_14 -> V_89 . V_146 += V_78 ;
V_169 = 0 ;
}
V_6 -> V_169 = V_169 ;
if ( V_169 ) {
F_11 ( V_6 , V_151 ) ;
F_72 ( V_14 ) ;
}
return V_171 ;
}
static unsigned int F_73 ( struct V_5 * V_6 )
{
struct V_85 * V_14 = & V_6 -> V_14 ;
struct V_139 * V_140 = & V_14 -> V_100 -> V_140 ;
struct V_141 * V_142 ;
int V_144 ;
int V_64 ;
int V_169 ;
struct V_160 * V_161 ;
int V_172 ;
int V_79 ;
int V_173 ;
int V_97 ;
int V_174 ;
if ( ! V_6 -> V_170 ) {
F_70 ( V_6 -> V_14 . V_47 , L_32 ,
V_54 , V_55 ) ;
F_11 ( V_6 , V_151 ) ;
V_6 -> V_169 = 1 ;
return 0 ;
}
if ( V_6 -> V_150 ) {
F_15 ( V_6 -> V_14 . V_47 , L_33 ,
V_54 , V_55 ) ;
F_11 ( V_6 , V_151 ) ;
V_6 -> V_169 = 1 ;
return 0 ;
}
V_64 = F_71 ( V_6 -> V_64 , 1 ) ;
V_169 = 1 ;
if ( F_30 ( V_6 , V_140 -> V_8 ) ) {
F_19 ( V_6 , V_140 -> V_8 , 1 ) ;
V_14 -> V_89 . V_146 ++ ;
V_169 = 0 ;
V_64 -- ;
}
V_173 = F_59 ( ( int ) F_74 ( V_140 -> V_154 , V_140 -> V_145 ,
V_147 ) , F_58 ( V_140 -> V_154 ,
V_140 -> V_145 , V_147 ) ) ;
if ( ! V_173 ) {
F_15 ( V_6 -> V_14 . V_47 , L_34 , V_54 ) ;
F_11 ( V_6 , V_151 ) ;
F_72 ( V_14 ) ;
return 0 ;
}
if ( V_173 > V_64 ) {
V_172 = V_173 / V_64 + 1 ;
V_97 = V_64 ;
V_174 = V_173 % V_64 ;
} else {
V_172 = 1 ;
V_97 = V_173 ;
V_174 = V_173 ;
}
F_15 ( V_6 -> V_14 . V_47 , L_35 ,
V_54 , V_172 , V_97 , V_174 ) ;
V_6 -> V_150 = 1 ;
V_6 -> V_143 = F_2 ( sizeof( struct V_141 ) * V_172 , V_175 ) ;
if ( ! V_6 -> V_143 ) {
F_14 ( V_6 -> V_14 . V_47 , L_36 , V_54 ) ;
return 0 ;
}
F_63 ( V_6 -> V_143 , V_172 ) ;
V_142 = V_6 -> V_143 ;
for ( V_79 = 0 ; V_79 < V_172 ; V_79 ++ , V_142 ++ ) {
if ( V_79 == ( V_172 - 1 ) )
F_64 ( V_142 , F_65 ( V_140 -> V_8 ) ,
V_174 , V_64 * V_79 ) ;
else
F_64 ( V_142 , F_65 ( V_140 -> V_8 ) ,
V_97 , V_64 * V_79 ) ;
}
V_142 = V_6 -> V_143 ;
V_144 = F_75 ( V_14 -> V_47 , V_142 , V_172 , V_149 ) ;
if ( ! V_144 ) {
F_14 ( V_6 -> V_14 . V_47 , L_37 , V_54 ) ;
return 0 ;
}
V_6 -> V_144 = V_144 ;
for ( V_79 = 0 ; V_79 < V_144 ; V_79 ++ , V_142 ++ ) {
V_142 -> V_176 = ( V_140 -> V_145 & ( V_147 - 1 ) ) +
V_64 * V_79 ;
F_66 ( V_142 ) = ( F_66 ( V_142 ) &
~ ( V_147 - 1 ) ) + V_142 -> V_176 ;
if ( V_79 == ( V_144 - 1 ) )
F_53 ( V_142 ) = V_174 ;
else
F_53 ( V_142 ) = V_97 ;
}
V_161 = F_67 ( V_6 -> V_107 ,
V_6 -> V_143 , V_144 , V_177 ,
V_164 | V_165 ) ;
if ( ! V_161 ) {
F_14 ( V_6 -> V_14 . V_47 , L_38 ,
V_54 ) ;
return 0 ;
}
F_76 ( V_14 -> V_47 , V_6 -> V_143 , V_144 , V_149 ) ;
V_6 -> V_148 = V_161 ;
V_161 -> V_166 = F_52 ;
V_161 -> V_167 = V_6 ;
V_161 -> V_168 ( V_161 ) ;
F_68 ( V_6 -> V_107 ) ;
return V_171 ;
}
static void F_77 ( struct V_5 * V_6 , unsigned int V_84 )
{
struct V_85 * V_14 = & V_6 -> V_14 ;
struct V_102 * V_103 = F_32 ( & V_14 -> V_100 -> V_14 ) ;
char * V_178 [ 5 ] = {} ;
int V_79 = 0 ;
if ( V_84 & V_179 )
V_178 [ V_79 ++ ] = L_39 ;
if ( V_84 & V_180 ) {
V_14 -> V_89 . V_181 ++ ;
V_178 [ V_79 ++ ] = L_40 ;
}
if ( V_84 & V_182 ) {
V_14 -> V_89 . V_40 ++ ;
V_178 [ V_79 ++ ] = L_41 ;
}
if ( V_84 & V_183 ) {
V_14 -> V_89 . V_184 ++ ;
V_178 [ V_79 ++ ] = L_42 ;
}
if ( V_103 == NULL ) {
for ( V_79 = 0 ; V_178 [ V_79 ] != NULL ; V_79 ++ )
F_14 ( & V_6 -> V_124 -> V_47 , V_178 [ V_79 ] ) ;
}
}
static T_8 F_78 ( int V_185 , void * V_186 )
{
struct V_5 * V_6 = V_186 ;
unsigned int V_187 ;
T_6 V_84 ;
int V_10 = 0 ;
unsigned char V_188 ;
unsigned long V_189 ;
int V_190 = 1 ;
T_6 V_75 ;
F_79 ( & V_6 -> V_191 , V_189 ) ;
V_187 = 0 ;
while ( V_190 ) {
V_188 = F_24 ( V_6 ) ;
if ( V_188 & V_94 )
break;
switch ( V_188 ) {
case V_192 :
V_84 = F_25 ( V_6 ) ;
if ( V_84 & ( V_179 | V_180 |
V_182 | V_183 ) ) {
F_77 ( V_6 , V_84 ) ;
V_10 = V_193 ;
} else {
V_10 = V_194 ;
}
break;
case V_195 :
if ( V_6 -> V_196 ) {
F_11 ( V_6 ,
V_137 |
V_138 ) ;
V_10 = F_62 ( V_6 ) ;
if ( ! V_10 )
F_10 ( V_6 ,
V_137 |
V_138 ) ;
} else {
V_10 = F_61 ( V_6 ) ;
}
break;
case V_197 :
V_10 = F_60 ( V_6 ) ;
break;
case V_198 :
if ( V_6 -> V_196 )
V_10 = F_73 ( V_6 ) ;
else
V_10 = F_69 ( V_6 ) ;
break;
case V_199 :
V_75 = F_18 ( V_6 ) ;
V_190 = 0 ;
if ( ( V_75 & V_200 ) == 0 )
break;
V_10 |= V_201 ;
break;
default:
F_14 ( V_6 -> V_14 . V_47 , L_43 , V_54 ,
V_188 , V_55 ) ;
V_10 = - 1 ;
V_190 = 0 ;
break;
}
V_187 |= ( unsigned int ) V_10 ;
}
F_80 ( & V_6 -> V_191 , V_189 ) ;
return F_81 ( V_187 ) ;
}
static unsigned int F_82 ( struct V_85 * V_14 )
{
struct V_5 * V_6 ;
V_6 = F_38 ( V_14 , struct V_5 , V_14 ) ;
if ( V_6 -> V_169 )
return V_202 ;
else
return 0 ;
}
static unsigned int F_83 ( struct V_85 * V_14 )
{
struct V_5 * V_6 ;
T_6 V_203 ;
unsigned int V_10 = 0 ;
V_6 = F_38 ( V_14 , struct V_5 , V_14 ) ;
V_203 = F_18 ( V_6 ) ;
if ( V_203 & V_204 )
V_10 |= V_205 ;
if ( V_203 & V_206 )
V_10 |= V_207 ;
if ( V_203 & V_208 )
V_10 |= V_209 ;
if ( V_203 & V_210 )
V_10 |= V_211 ;
return V_10 ;
}
static void F_84 ( struct V_85 * V_14 , unsigned int V_212 )
{
T_5 V_213 = 0 ;
struct V_5 * V_6 = F_38 ( V_14 , struct V_5 , V_14 ) ;
if ( V_212 & V_214 )
V_213 |= V_215 ;
if ( V_212 & V_216 )
V_213 |= V_217 ;
if ( V_212 & V_218 )
V_213 |= V_219 ;
if ( V_6 -> V_213 & V_220 )
V_213 |= V_220 ;
if ( V_212 )
F_4 ( V_213 , V_6 -> V_15 + V_19 ) ;
}
static void F_85 ( struct V_85 * V_14 )
{
struct V_5 * V_6 ;
V_6 = F_38 ( V_14 , struct V_5 , V_14 ) ;
V_6 -> V_170 = 0 ;
V_6 -> V_150 = 0 ;
}
static void F_86 ( struct V_85 * V_14 )
{
struct V_5 * V_6 ;
V_6 = F_38 ( V_14 , struct V_5 , V_14 ) ;
if ( V_6 -> V_196 ) {
if ( V_6 -> V_150 ) {
F_15 ( V_6 -> V_14 . V_47 , L_44 ,
V_54 ) ;
return;
}
}
V_6 -> V_170 = 1 ;
F_10 ( V_6 , V_151 ) ;
}
static void F_87 ( struct V_85 * V_14 )
{
struct V_5 * V_6 ;
V_6 = F_38 ( V_14 , struct V_5 , V_14 ) ;
V_6 -> V_157 = 0 ;
F_11 ( V_6 , V_137 |
V_138 ) ;
}
static void F_88 ( struct V_85 * V_14 )
{
struct V_5 * V_6 ;
V_6 = F_38 ( V_14 , struct V_5 , V_14 ) ;
F_10 ( V_6 , V_221 ) ;
}
static void F_89 ( struct V_85 * V_14 , int V_222 )
{
struct V_5 * V_6 ;
unsigned long V_189 ;
V_6 = F_38 ( V_14 , struct V_5 , V_14 ) ;
F_79 ( & V_6 -> V_191 , V_189 ) ;
F_26 ( V_6 , V_222 ) ;
F_80 ( & V_6 -> V_191 , V_189 ) ;
}
static int F_90 ( struct V_85 * V_14 )
{
struct V_5 * V_6 ;
int V_10 ;
int V_64 ;
int V_69 ;
V_6 = F_38 ( V_14 , struct V_5 , V_14 ) ;
V_6 -> V_169 = 1 ;
if ( V_14 -> V_45 )
V_6 -> V_45 = V_14 -> V_45 ;
else
V_14 -> V_45 = V_6 -> V_45 ;
F_11 ( V_6 , V_223 ) ;
V_10 = F_12 ( V_6 , V_224 ,
V_225 , V_226 ,
V_227 ) ;
if ( V_10 )
return V_10 ;
switch ( V_6 -> V_64 ) {
case 256 :
V_64 = V_228 ;
break;
case 64 :
V_64 = V_229 ;
break;
case 16 :
V_64 = V_230 ;
break;
case 1 :
default:
V_64 = V_231 ;
break;
}
switch ( V_6 -> V_65 ) {
case V_232 :
V_69 = 1 ;
break;
case V_233 :
V_69 = V_6 -> V_64 / 4 ;
break;
case V_234 :
V_69 = V_6 -> V_64 / 2 ;
break;
case V_235 :
default:
V_69 = V_6 -> V_64 - ( V_6 -> V_64 / 8 ) ;
break;
}
V_6 -> V_69 = V_69 ;
V_10 = F_17 ( V_6 , V_236 ,
V_64 , V_6 -> V_65 ) ;
if ( V_10 < 0 )
return V_10 ;
V_10 = F_91 ( V_6 -> V_14 . V_185 , F_78 , V_237 ,
V_238 , V_6 ) ;
if ( V_10 < 0 )
return V_10 ;
if ( V_6 -> V_196 )
F_42 ( V_14 ) ;
V_6 -> V_157 = 1 ;
F_10 ( V_6 , V_137 |
V_138 ) ;
F_92 ( V_14 , V_239 , V_224 ) ;
return 0 ;
}
static void F_93 ( struct V_85 * V_14 )
{
struct V_5 * V_6 ;
int V_10 ;
V_6 = F_38 ( V_14 , struct V_5 , V_14 ) ;
F_11 ( V_6 , V_223 ) ;
F_16 ( V_6 , V_240 ) ;
V_10 = F_17 ( V_6 , V_236 ,
V_231 , V_232 ) ;
if ( V_10 )
F_14 ( V_6 -> V_14 . V_47 ,
L_45 , V_10 ) ;
F_37 ( V_14 ) ;
F_94 ( V_6 -> V_14 . V_185 , V_6 ) ;
}
static void F_95 ( struct V_85 * V_14 ,
struct V_241 * V_242 , struct V_241 * V_243 )
{
int V_39 ;
int V_244 ;
unsigned int V_40 , V_41 , V_42 ;
struct V_5 * V_6 ;
unsigned long V_189 ;
V_6 = F_38 ( V_14 , struct V_5 , V_14 ) ;
switch ( V_242 -> V_245 & V_246 ) {
case V_247 :
V_41 = V_248 ;
break;
case V_249 :
V_41 = V_250 ;
break;
case V_251 :
V_41 = V_252 ;
break;
default:
V_41 = V_226 ;
break;
}
if ( V_242 -> V_245 & V_253 )
V_42 = V_254 ;
else
V_42 = V_227 ;
if ( V_242 -> V_245 & V_255 ) {
if ( V_242 -> V_245 & V_256 )
V_40 = V_257 ;
else
V_40 = V_258 ;
} else
V_40 = V_225 ;
if ( ( V_242 -> V_245 & V_259 ) && ( V_6 -> V_64 == 256 ) )
V_6 -> V_213 |= V_220 ;
else
V_6 -> V_213 &= ~ V_220 ;
V_242 -> V_245 &= ~ V_260 ;
V_39 = F_96 ( V_14 , V_242 , V_243 , 0 , V_14 -> V_45 / 16 ) ;
F_79 ( & V_6 -> V_191 , V_189 ) ;
F_97 ( & V_14 -> V_191 ) ;
F_92 ( V_14 , V_242 -> V_245 , V_39 ) ;
V_244 = F_12 ( V_6 , V_39 , V_40 , V_41 , V_42 ) ;
if ( V_244 )
goto V_261;
F_84 ( & V_6 -> V_14 , V_6 -> V_14 . V_212 ) ;
if ( F_98 ( V_242 ) )
F_99 ( V_242 , V_39 , V_39 ) ;
V_261:
F_100 ( & V_14 -> V_191 ) ;
F_80 ( & V_6 -> V_191 , V_189 ) ;
}
static const char * F_101 ( struct V_85 * V_14 )
{
return V_238 ;
}
static void F_102 ( struct V_85 * V_14 )
{
struct V_5 * V_6 ;
V_6 = F_38 ( V_14 , struct V_5 , V_14 ) ;
F_103 ( V_6 -> V_124 , V_6 -> V_15 ) ;
F_104 ( V_6 -> V_124 ) ;
}
static int F_105 ( struct V_85 * V_14 )
{
struct V_5 * V_6 ;
int V_10 ;
void T_9 * V_15 ;
V_6 = F_38 ( V_14 , struct V_5 , V_14 ) ;
V_10 = F_106 ( V_6 -> V_124 , V_238 ) ;
if ( V_10 < 0 )
return - V_262 ;
V_15 = F_107 ( V_6 -> V_124 , 1 , 0 ) ;
if ( ! V_15 ) {
F_104 ( V_6 -> V_124 ) ;
return - V_262 ;
}
V_6 -> V_15 = V_14 -> V_15 = V_15 ;
return 0 ;
}
static void F_108 ( struct V_85 * V_14 , int type )
{
struct V_5 * V_6 ;
V_6 = F_38 ( V_14 , struct V_5 , V_14 ) ;
if ( type & V_263 ) {
V_14 -> type = V_6 -> V_264 ;
F_105 ( V_14 ) ;
}
}
static int F_109 ( struct V_85 * V_14 ,
struct V_265 * V_266 )
{
struct V_5 * V_6 ;
V_6 = F_38 ( V_14 , struct V_5 , V_14 ) ;
if ( V_266 -> V_189 & V_267 ) {
F_70 ( V_6 -> V_14 . V_47 ,
L_46 ) ;
V_6 -> V_196 = 0 ;
V_266 -> V_189 &= ~ V_267 ;
} else {
#ifndef F_110
F_14 ( V_6 -> V_14 . V_47 , L_47 ,
V_54 ) ;
return - V_268 ;
#endif
F_70 ( V_6 -> V_14 . V_47 , L_48 ) ;
if ( ! V_6 -> V_196 )
F_42 ( V_14 ) ;
V_6 -> V_196 = 1 ;
}
return 0 ;
}
static void F_111 ( struct V_5 * V_269 , int V_41 )
{
unsigned int V_270 , V_271 = 10000 ;
for (; ; ) {
V_270 = F_3 ( V_269 -> V_15 + V_20 ) ;
if ( ( V_270 & V_41 ) == V_41 )
break;
if ( -- V_271 == 0 )
break;
F_112 ( 1 ) ;
}
if ( V_269 -> V_14 . V_189 & V_272 ) {
unsigned int V_271 ;
for ( V_271 = 1000000 ; V_271 ; V_271 -- ) {
unsigned int V_75 = F_3 ( V_269 -> V_15 + V_21 ) ;
if ( V_75 & V_210 )
break;
F_112 ( 1 ) ;
F_113 () ;
}
}
}
static void F_114 ( struct V_85 * V_14 , int V_273 )
{
struct V_5 * V_6 =
F_38 ( V_14 , struct V_5 , V_14 ) ;
F_111 ( V_6 , V_274 ) ;
F_4 ( V_273 , V_6 -> V_15 + V_81 ) ;
}
static void
F_115 ( struct V_275 * V_276 , const char * V_277 , unsigned int V_3 )
{
struct V_5 * V_6 ;
unsigned long V_189 ;
int V_278 = 1 ;
int V_279 = 1 ;
T_6 V_37 ;
V_6 = V_280 [ V_276 -> V_281 ] ;
F_113 () ;
F_116 ( V_189 ) ;
if ( V_6 -> V_14 . V_91 ) {
V_278 = 0 ;
V_279 = 0 ;
} else if ( V_282 ) {
V_278 = F_117 ( & V_6 -> V_191 ) ;
V_279 = F_117 ( & V_6 -> V_14 . V_191 ) ;
} else {
F_97 ( & V_6 -> V_191 ) ;
F_97 ( & V_6 -> V_14 . V_191 ) ;
}
V_37 = F_3 ( V_6 -> V_15 + V_16 ) ;
F_11 ( V_6 , V_223 ) ;
F_118 ( & V_6 -> V_14 , V_277 , V_3 , F_114 ) ;
F_111 ( V_6 , V_283 ) ;
F_4 ( V_37 , V_6 -> V_15 + V_16 ) ;
if ( V_279 )
F_100 ( & V_6 -> V_14 . V_191 ) ;
if ( V_278 )
F_100 ( & V_6 -> V_191 ) ;
F_119 ( V_189 ) ;
}
static int T_10 F_120 ( struct V_275 * V_276 , char * V_284 )
{
struct V_85 * V_14 ;
int V_39 = V_224 ;
int V_41 = 8 ;
int V_40 = 'n' ;
int V_285 = 'n' ;
if ( V_276 -> V_281 >= V_286 )
V_276 -> V_281 = 0 ;
V_14 = & V_280 [ V_276 -> V_281 ] -> V_14 ;
if ( ! V_14 || ( ! V_14 -> V_287 && ! V_14 -> V_15 ) )
return - V_288 ;
V_14 -> V_45 = F_7 () ;
if ( V_284 )
F_121 ( V_284 , & V_39 , & V_40 , & V_41 , & V_285 ) ;
return F_122 ( V_14 , V_276 , V_39 , V_40 , V_41 , V_285 ) ;
}
static struct V_5 * F_123 ( struct V_122 * V_124 ,
const struct V_289 * V_290 )
{
struct V_5 * V_6 ;
int V_10 ;
unsigned int V_287 ;
unsigned int V_129 ;
unsigned char * V_158 ;
int V_110 ;
int V_264 ;
struct V_291 * V_292 ;
char V_293 [ 32 ] ;
V_292 = & V_294 [ V_290 -> V_295 ] ;
V_264 = V_292 -> V_264 ;
V_6 = F_2 ( sizeof( struct V_5 ) , V_13 ) ;
if ( V_6 == NULL )
goto V_296;
V_158 = ( unsigned char * ) F_124 ( V_13 ) ;
if ( ! V_158 )
goto V_297;
switch ( V_264 ) {
case V_298 :
V_110 = 256 ;
break;
case V_299 :
V_110 = 64 ;
break;
default:
F_14 ( & V_124 -> V_47 , L_49 , V_264 ) ;
goto V_300;
}
F_125 ( V_124 ) ;
F_126 ( V_124 ) ;
F_127 ( & V_6 -> V_191 ) ;
V_287 = F_128 ( V_124 , 0 ) ;
V_129 = F_128 ( V_124 , 1 ) ;
V_6 -> V_129 = V_129 ;
V_6 -> V_287 = V_287 ;
V_6 -> V_124 = V_124 ;
V_6 -> V_169 = 1 ;
V_6 -> V_158 . V_8 = V_158 ;
V_6 -> V_158 . V_97 = V_301 ;
V_6 -> V_64 = V_110 ;
V_6 -> V_45 = F_7 () ;
V_6 -> V_264 = V_302 + V_264 + 1 ;
V_6 -> V_14 . V_47 = & V_124 -> V_47 ;
V_6 -> V_14 . V_287 = V_287 ;
V_6 -> V_14 . V_15 = NULL ;
V_6 -> V_14 . V_129 = V_129 ;
V_6 -> V_14 . V_185 = V_124 -> V_185 ;
V_6 -> V_14 . V_303 = V_304 ;
V_6 -> V_14 . V_305 = & V_306 ;
V_6 -> V_14 . V_189 = V_307 ;
V_6 -> V_14 . V_110 = V_110 ;
V_6 -> V_14 . line = V_292 -> V_308 ;
V_6 -> V_65 = V_234 ;
F_127 ( & V_6 -> V_14 . V_191 ) ;
F_129 ( V_124 , V_6 ) ;
V_6 -> V_69 = 1 ;
V_6 -> V_61 = 0 ;
#ifdef F_130
V_280 [ V_292 -> V_308 ] = V_6 ;
#endif
V_10 = F_131 ( & V_309 , & V_6 -> V_14 ) ;
if ( V_10 < 0 )
goto V_300;
#ifdef F_132
snprintf ( V_293 , sizeof( V_293 ) , L_50 , V_292 -> V_308 ) ;
V_6 -> V_310 = F_133 ( V_293 , V_311 | V_312 ,
NULL , V_6 , & V_313 ) ;
#endif
return V_6 ;
V_300:
#ifdef F_130
V_280 [ V_292 -> V_308 ] = NULL ;
#endif
F_134 ( ( unsigned long ) V_158 ) ;
V_297:
F_6 ( V_6 ) ;
V_296:
return NULL ;
}
static void F_135 ( struct V_5 * V_6 )
{
#ifdef F_132
if ( V_6 -> V_310 )
F_136 ( V_6 -> V_310 ) ;
#endif
F_137 ( & V_309 , & V_6 -> V_14 ) ;
F_129 ( V_6 -> V_124 , NULL ) ;
F_134 ( ( unsigned long ) V_6 -> V_158 . V_8 ) ;
}
static void F_138 ( struct V_122 * V_124 )
{
struct V_5 * V_6 = F_139 ( V_124 ) ;
F_140 ( V_124 ) ;
#ifdef F_130
V_280 [ V_6 -> V_14 . line ] = NULL ;
#endif
F_135 ( V_6 ) ;
F_141 ( V_124 ) ;
F_6 ( V_6 ) ;
return;
}
static int F_142 ( struct V_122 * V_124 , T_11 V_100 )
{
struct V_5 * V_6 = F_139 ( V_124 ) ;
F_143 ( & V_309 , & V_6 -> V_14 ) ;
F_144 ( V_124 ) ;
F_145 ( V_124 , F_146 ( V_124 , V_100 ) ) ;
return 0 ;
}
static int F_147 ( struct V_122 * V_124 )
{
struct V_5 * V_6 = F_139 ( V_124 ) ;
int V_10 ;
F_145 ( V_124 , V_314 ) ;
F_148 ( V_124 ) ;
V_10 = F_149 ( V_124 ) ;
if ( V_10 ) {
F_14 ( & V_124 -> V_47 ,
L_51 , V_54 , V_10 ) ;
return V_10 ;
}
F_150 ( & V_309 , & V_6 -> V_14 ) ;
return 0 ;
}
static int F_151 ( struct V_122 * V_124 ,
const struct V_289 * V_290 )
{
int V_10 ;
struct V_5 * V_6 ;
V_10 = F_149 ( V_124 ) ;
if ( V_10 < 0 )
goto V_315;
V_6 = F_123 ( V_124 , V_290 ) ;
if ( ! V_6 ) {
V_10 = - V_262 ;
goto V_316;
}
F_129 ( V_124 , V_6 ) ;
return V_10 ;
V_316:
F_140 ( V_124 ) ;
F_141 ( V_124 ) ;
V_315:
return V_10 ;
}
static int T_10 F_152 ( void )
{
int V_10 ;
V_10 = F_153 ( & V_309 ) ;
if ( V_10 < 0 )
return V_10 ;
V_10 = F_154 ( & V_317 ) ;
if ( V_10 < 0 )
F_155 ( & V_309 ) ;
return V_10 ;
}
static void T_12 F_156 ( void )
{
F_157 ( & V_317 ) ;
F_155 ( & V_309 ) ;
}
