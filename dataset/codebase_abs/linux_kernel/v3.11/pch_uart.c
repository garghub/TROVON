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
V_26 = F_8 ( V_28 ) ;
if ( V_26 && strstr ( V_26 , L_17 ) )
return V_35 ;
return V_36 ;
}
static void F_10 ( struct V_5 * V_6 ,
unsigned int V_37 )
{
T_6 V_38 = F_3 ( V_6 -> V_15 + V_16 ) ;
V_38 |= V_37 & V_39 ;
F_4 ( V_38 , V_6 -> V_15 + V_16 ) ;
}
static void F_11 ( struct V_5 * V_6 ,
unsigned int V_37 )
{
T_6 V_38 = F_3 ( V_6 -> V_15 + V_16 ) ;
V_38 &= ~ ( V_37 & V_39 ) ;
F_4 ( V_38 , V_6 -> V_15 + V_16 ) ;
}
static int F_12 ( struct V_5 * V_6 , int V_40 ,
unsigned int V_41 , unsigned int V_42 ,
unsigned int V_43 )
{
unsigned int V_44 , V_45 , V_11 ;
int div ;
div = F_13 ( V_6 -> V_46 / 16 , V_40 ) ;
if ( div < 0 || V_47 <= div ) {
F_14 ( V_6 -> V_14 . V_48 , L_18 , div ) ;
return - V_49 ;
}
V_44 = ( unsigned int ) div & 0x00FFU ;
V_45 = ( ( unsigned int ) div >> 8 ) & 0x00FFU ;
if ( V_41 & ~ ( V_50 | V_51 | V_52 ) ) {
F_14 ( V_6 -> V_14 . V_48 , L_19 , V_41 ) ;
return - V_49 ;
}
if ( V_42 & ~ V_53 ) {
F_14 ( V_6 -> V_14 . V_48 , L_20 , V_42 ) ;
return - V_49 ;
}
if ( V_43 & ~ V_54 ) {
F_14 ( V_6 -> V_14 . V_48 , L_21 , V_43 ) ;
return - V_49 ;
}
V_11 = V_41 ;
V_11 |= V_42 ;
V_11 |= V_43 ;
F_15 ( V_6 -> V_14 . V_48 , L_22 ,
V_55 , V_40 , div , V_11 , V_56 ) ;
F_4 ( V_23 , V_6 -> V_15 + V_18 ) ;
F_4 ( V_44 , V_6 -> V_15 + V_57 ) ;
F_4 ( V_45 , V_6 -> V_15 + V_58 ) ;
F_4 ( V_11 , V_6 -> V_15 + V_18 ) ;
return 0 ;
}
static int F_16 ( struct V_5 * V_6 ,
unsigned int V_37 )
{
if ( V_37 & ~ ( V_59 | V_60 ) ) {
F_14 ( V_6 -> V_14 . V_48 , L_23 ,
V_55 , V_37 ) ;
return - V_49 ;
}
F_4 ( V_61 | V_6 -> V_62 , V_6 -> V_15 + V_63 ) ;
F_4 ( V_61 | V_6 -> V_62 | V_37 ,
V_6 -> V_15 + V_63 ) ;
F_4 ( V_6 -> V_62 , V_6 -> V_15 + V_63 ) ;
return 0 ;
}
static int F_17 ( struct V_5 * V_6 ,
unsigned int V_64 ,
unsigned int V_65 , unsigned int V_66 )
{
T_6 V_62 ;
if ( V_64 & ~ V_67 ) {
F_14 ( V_6 -> V_14 . V_48 , L_24 ,
V_55 , V_64 ) ;
return - V_49 ;
}
if ( V_65 & ~ ( V_61 | V_68 ) ) {
F_14 ( V_6 -> V_14 . V_48 , L_25 ,
V_55 , V_65 ) ;
return - V_49 ;
}
if ( V_66 & ~ V_69 ) {
F_14 ( V_6 -> V_14 . V_48 , L_26 ,
V_55 , V_66 ) ;
return - V_49 ;
}
switch ( V_6 -> V_65 ) {
case 256 :
V_6 -> V_70 =
V_71 [ V_66 >> V_72 ] ;
break;
case 64 :
V_6 -> V_70 =
V_73 [ V_66 >> V_72 ] ;
break;
case 16 :
V_6 -> V_70 =
V_74 [ V_66 >> V_72 ] ;
break;
default:
V_6 -> V_70 =
V_75 [ V_66 >> V_72 ] ;
break;
}
V_62 =
V_64 | V_65 | V_66 | V_60 | V_59 ;
F_4 ( V_61 , V_6 -> V_15 + V_63 ) ;
F_4 ( V_61 | V_60 | V_59 ,
V_6 -> V_15 + V_63 ) ;
F_4 ( V_62 , V_6 -> V_15 + V_63 ) ;
V_6 -> V_62 = V_62 ;
return 0 ;
}
static T_6 F_18 ( struct V_5 * V_6 )
{
unsigned int V_76 = F_3 ( V_6 -> V_15 + V_21 ) ;
V_6 -> V_77 = V_76 & V_78 ;
return ( T_6 ) V_76 ;
}
static void F_19 ( struct V_5 * V_6 ,
const unsigned char * V_8 , int V_79 )
{
int V_80 ;
unsigned int V_81 ;
for ( V_80 = 0 ; V_80 < V_79 ; ) {
V_81 = V_8 [ V_80 ++ ] ;
F_4 ( V_81 , V_6 -> V_15 + V_82 ) ;
}
}
static int F_20 ( struct V_5 * V_6 , unsigned char * V_8 ,
int V_83 )
{
int V_80 ;
T_6 V_84 , V_85 ;
struct V_86 * V_14 = & V_6 -> V_14 ;
V_85 = F_3 ( V_6 -> V_15 + V_20 ) ;
for ( V_80 = 0 , V_85 = F_3 ( V_6 -> V_15 + V_20 ) ;
V_80 < V_83 && V_85 & ( V_87 | V_88 ) ;
V_85 = F_3 ( V_6 -> V_15 + V_20 ) ) {
V_84 = F_3 ( V_6 -> V_15 + V_89 ) ;
if ( V_85 & V_88 ) {
V_14 -> V_90 . V_91 ++ ;
if ( F_21 ( V_14 ) )
continue;
}
#ifdef F_22
if ( V_14 -> V_92 ) {
if ( F_23 ( V_14 , V_84 ) )
continue;
}
#endif
V_8 [ V_80 ++ ] = V_84 ;
}
return V_80 ;
}
static unsigned char F_24 ( struct V_5 * V_6 )
{
return F_3 ( V_6 -> V_15 + V_17 ) &\
( V_93 | V_94 | V_95 ) ;
}
static T_6 F_25 ( struct V_5 * V_6 )
{
return F_3 ( V_6 -> V_15 + V_20 ) ;
}
static void F_26 ( struct V_5 * V_6 , int V_96 )
{
unsigned int V_11 ;
V_11 = F_3 ( V_6 -> V_15 + V_18 ) ;
if ( V_96 )
V_11 |= V_97 ;
else
V_11 &= ~ V_97 ;
F_4 ( V_11 , V_6 -> V_15 + V_18 ) ;
}
static int F_27 ( struct V_5 * V_6 , const unsigned char * V_8 ,
int V_98 )
{
struct V_86 * V_14 = & V_6 -> V_14 ;
struct V_99 * V_100 = & V_14 -> V_101 -> V_14 ;
F_28 ( V_100 , V_8 , V_98 ) ;
F_29 ( V_100 ) ;
return 0 ;
}
static int F_30 ( struct V_5 * V_6 , unsigned char * V_8 )
{
int V_10 = 0 ;
struct V_86 * V_14 = & V_6 -> V_14 ;
if ( V_14 -> V_102 ) {
F_15 ( V_6 -> V_14 . V_48 , L_27 ,
V_55 , V_14 -> V_102 , V_56 ) ;
V_8 [ 0 ] = V_14 -> V_102 ;
V_14 -> V_102 = 0 ;
V_10 = 1 ;
}
return V_10 ;
}
static int F_31 ( struct V_5 * V_6 , int V_98 )
{
struct V_103 * V_104 ;
int V_105 ;
struct V_86 * V_14 = & V_6 -> V_14 ;
struct V_99 * V_100 = & V_14 -> V_101 -> V_14 ;
V_14 = & V_6 -> V_14 ;
V_104 = F_32 ( V_100 ) ;
if ( ! V_104 ) {
F_15 ( V_6 -> V_14 . V_48 , L_28 , V_55 ) ;
return 0 ;
}
V_105 = F_33 ( V_100 , V_98 ) ;
if ( V_105 < V_98 )
F_34 ( V_14 -> V_48 , L_29 ,
V_98 - V_105 ) ;
if ( ! V_105 )
return V_105 ;
F_28 ( V_100 , F_35 ( & V_6 -> V_106 ) , V_98 ) ;
V_14 -> V_90 . V_107 += V_105 ;
F_36 ( V_104 ) ;
return V_105 ;
}
static void F_37 ( struct V_86 * V_14 )
{
struct V_5 * V_6 ;
V_6 = F_38 ( V_14 , struct V_5 , V_14 ) ;
if ( V_6 -> V_108 ) {
F_39 ( V_6 -> V_108 ) ;
V_6 -> V_108 = NULL ;
}
if ( V_6 -> V_109 ) {
F_39 ( V_6 -> V_109 ) ;
V_6 -> V_109 = NULL ;
}
if ( V_6 -> V_110 ) {
F_40 ( V_14 -> V_48 , V_14 -> V_111 , V_6 -> V_112 ,
V_6 -> V_110 ) ;
V_6 -> V_112 = NULL ;
V_6 -> V_110 = 0 ;
}
return;
}
static bool F_41 ( struct V_113 * V_114 , void * V_115 )
{
struct V_116 * V_117 = V_115 ;
if ( ( V_114 -> V_118 == V_117 -> V_118 ) && ( V_117 -> V_119 ==
V_114 -> V_120 -> V_48 ) ) {
V_114 -> V_121 = V_117 ;
return true ;
} else {
return false ;
}
}
static void F_42 ( struct V_86 * V_14 )
{
T_7 V_122 ;
struct V_113 * V_114 ;
struct V_123 * V_119 ;
struct V_116 * V_117 ;
struct V_5 * V_6 =
F_38 ( V_14 , struct V_5 , V_14 ) ;
F_43 ( V_122 ) ;
F_44 ( V_124 , V_122 ) ;
V_119 = F_45 ( V_6 -> V_125 -> V_126 -> V_127 ,
F_46 ( 0xa , 0 ) ) ;
V_117 = & V_6 -> V_128 ;
V_117 -> V_119 = & V_119 -> V_48 ;
V_117 -> V_118 = V_6 -> V_14 . line * 2 ;
V_117 -> V_129 = V_14 -> V_130 + V_131 ;
V_114 = F_47 ( V_122 , F_41 , V_117 ) ;
if ( ! V_114 ) {
F_14 ( V_6 -> V_14 . V_48 , L_30 ,
V_55 ) ;
return;
}
V_6 -> V_108 = V_114 ;
V_117 = & V_6 -> V_132 ;
V_117 -> V_119 = & V_119 -> V_48 ;
V_117 -> V_118 = V_6 -> V_14 . line * 2 + 1 ;
V_117 -> V_133 = V_14 -> V_130 + V_134 ;
V_114 = F_47 ( V_122 , F_41 , V_117 ) ;
if ( ! V_114 ) {
F_14 ( V_6 -> V_14 . V_48 , L_31 ,
V_55 ) ;
F_39 ( V_6 -> V_108 ) ;
V_6 -> V_108 = NULL ;
return;
}
V_6 -> V_112 = F_48 ( V_14 -> V_48 , V_14 -> V_111 ,
& V_6 -> V_110 , V_13 ) ;
V_6 -> V_109 = V_114 ;
}
static void F_49 ( void * V_135 )
{
struct V_5 * V_6 = V_135 ;
struct V_86 * V_14 = & V_6 -> V_14 ;
int V_3 ;
F_50 ( V_14 -> V_48 , & V_6 -> V_106 , 1 , V_136 ) ;
V_3 = F_31 ( V_6 , V_6 -> V_70 ) ;
if ( V_3 )
F_29 ( & V_14 -> V_101 -> V_14 ) ;
F_51 ( V_6 -> V_137 ) ;
F_10 ( V_6 , V_138 |
V_139 ) ;
}
static void F_52 ( void * V_135 )
{
struct V_5 * V_6 = V_135 ;
struct V_86 * V_14 = & V_6 -> V_14 ;
struct V_140 * V_141 = & V_14 -> V_101 -> V_141 ;
struct V_142 * V_143 = V_6 -> V_144 ;
int V_80 ;
for ( V_80 = 0 ; V_80 < V_6 -> V_145 ; V_80 ++ , V_143 ++ ) {
V_141 -> V_146 += F_53 ( V_143 ) ;
V_14 -> V_90 . V_147 += F_53 ( V_143 ) ;
}
V_141 -> V_146 &= V_148 - 1 ;
F_51 ( V_6 -> V_149 ) ;
F_54 ( V_14 -> V_48 , V_143 , V_6 -> V_145 , V_150 ) ;
V_6 -> V_151 = 0 ;
V_6 -> V_145 = 0 ;
F_6 ( V_6 -> V_144 ) ;
F_10 ( V_6 , V_152 ) ;
}
static int F_55 ( struct V_5 * V_6 , int V_98 )
{
int V_3 = 0 ;
struct V_86 * V_14 = & V_6 -> V_14 ;
struct V_140 * V_141 = & V_14 -> V_101 -> V_141 ;
if ( F_56 ( V_14 ) || F_57 ( V_141 ) || V_3 >= V_98 )
goto V_153;
do {
int V_154 =
F_58 ( V_141 -> V_155 , V_141 -> V_146 , V_148 ) ;
int V_156 = F_59 ( V_98 - V_3 , V_154 ) ;
F_19 ( V_6 , & V_141 -> V_8 [ V_141 -> V_146 ] , V_156 ) ;
V_141 -> V_146 = ( V_141 -> V_146 + V_156 ) & ( V_148 - 1 ) ;
V_3 += V_156 ;
} while ( ! F_57 ( V_141 ) && V_3 < V_98 );
V_153:
F_15 ( V_6 -> V_14 . V_48 , L_32 ,
V_3 , V_98 - V_3 , V_56 ) ;
return V_3 ;
}
static int F_60 ( struct V_5 * V_6 )
{
struct V_157 * V_8 ;
int V_83 ;
int V_10 ;
if ( ! V_6 -> V_158 ) {
F_11 ( V_6 , V_138 |
V_139 ) ;
return 0 ;
}
V_8 = & V_6 -> V_159 ;
do {
V_83 = F_20 ( V_6 , V_8 -> V_8 , V_8 -> V_98 ) ;
V_10 = F_27 ( V_6 , V_8 -> V_8 , V_83 ) ;
if ( V_10 )
return 0 ;
} while ( V_83 == V_8 -> V_98 );
return V_160 ;
}
static int F_61 ( struct V_5 * V_6 )
{
return F_60 ( V_6 ) ;
}
static int F_62 ( struct V_5 * V_6 )
{
struct V_86 * V_14 = & V_6 -> V_14 ;
struct V_161 * V_162 ;
struct V_142 * V_143 ;
V_6 = F_38 ( V_14 , struct V_5 , V_14 ) ;
V_143 = & V_6 -> V_106 ;
F_63 ( & V_6 -> V_106 , 1 ) ;
F_53 ( V_143 ) = V_6 -> V_70 ;
F_64 ( & V_6 -> V_106 , F_65 ( V_6 -> V_112 ) ,
F_53 ( V_143 ) , ( unsigned long ) V_6 -> V_112 &
~ V_163 ) ;
F_66 ( V_143 ) = V_6 -> V_110 ;
V_162 = F_67 ( V_6 -> V_109 ,
V_143 , 1 , V_164 ,
V_165 | V_166 ) ;
if ( ! V_162 )
return 0 ;
V_6 -> V_137 = V_162 ;
V_162 -> V_167 = F_49 ;
V_162 -> V_168 = V_6 ;
V_162 -> V_169 ( V_162 ) ;
F_68 ( V_6 -> V_109 ) ;
return V_160 ;
}
static unsigned int F_69 ( struct V_5 * V_6 )
{
struct V_86 * V_14 = & V_6 -> V_14 ;
struct V_140 * V_141 = & V_14 -> V_101 -> V_141 ;
int V_65 ;
int V_79 ;
int V_98 ;
int V_170 ;
if ( ! V_6 -> V_171 ) {
F_70 ( V_6 -> V_14 . V_48 , L_33 ,
V_55 , V_56 ) ;
F_11 ( V_6 , V_152 ) ;
V_6 -> V_170 = 1 ;
return 0 ;
}
V_65 = F_71 ( V_6 -> V_65 , 1 ) ;
V_170 = 1 ;
if ( F_30 ( V_6 , V_141 -> V_8 ) ) {
F_19 ( V_6 , V_141 -> V_8 , 1 ) ;
V_14 -> V_90 . V_147 ++ ;
V_170 = 0 ;
V_65 -- ;
}
V_98 = F_59 ( V_141 -> V_155 - V_141 -> V_146 , V_65 ) ;
if ( V_98 < 0 )
V_98 = V_65 ;
V_79 = F_55 ( V_6 , V_98 ) ;
if ( V_79 > 0 ) {
V_14 -> V_90 . V_147 += V_79 ;
V_170 = 0 ;
}
V_6 -> V_170 = V_170 ;
if ( V_170 ) {
F_11 ( V_6 , V_152 ) ;
F_72 ( V_14 ) ;
}
return V_172 ;
}
static unsigned int F_73 ( struct V_5 * V_6 )
{
struct V_86 * V_14 = & V_6 -> V_14 ;
struct V_140 * V_141 = & V_14 -> V_101 -> V_141 ;
struct V_142 * V_143 ;
int V_145 ;
int V_65 ;
int V_170 ;
struct V_161 * V_162 ;
int V_173 ;
int V_80 ;
int V_174 ;
int V_98 ;
int V_175 ;
if ( ! V_6 -> V_171 ) {
F_70 ( V_6 -> V_14 . V_48 , L_33 ,
V_55 , V_56 ) ;
F_11 ( V_6 , V_152 ) ;
V_6 -> V_170 = 1 ;
return 0 ;
}
if ( V_6 -> V_151 ) {
F_15 ( V_6 -> V_14 . V_48 , L_34 ,
V_55 , V_56 ) ;
F_11 ( V_6 , V_152 ) ;
V_6 -> V_170 = 1 ;
return 0 ;
}
V_65 = F_71 ( V_6 -> V_65 , 1 ) ;
V_170 = 1 ;
if ( F_30 ( V_6 , V_141 -> V_8 ) ) {
F_19 ( V_6 , V_141 -> V_8 , 1 ) ;
V_14 -> V_90 . V_147 ++ ;
V_170 = 0 ;
V_65 -- ;
}
V_174 = F_59 ( ( int ) F_74 ( V_141 -> V_155 , V_141 -> V_146 ,
V_148 ) , F_58 ( V_141 -> V_155 ,
V_141 -> V_146 , V_148 ) ) ;
if ( ! V_174 ) {
F_15 ( V_6 -> V_14 . V_48 , L_35 , V_55 ) ;
F_11 ( V_6 , V_152 ) ;
F_72 ( V_14 ) ;
return 0 ;
}
if ( V_174 > V_65 ) {
V_173 = V_174 / V_65 + 1 ;
V_98 = V_65 ;
V_175 = V_174 % V_65 ;
} else {
V_173 = 1 ;
V_98 = V_174 ;
V_175 = V_174 ;
}
F_15 ( V_6 -> V_14 . V_48 , L_36 ,
V_55 , V_173 , V_98 , V_175 ) ;
V_6 -> V_151 = 1 ;
V_6 -> V_144 = F_2 ( sizeof( struct V_142 ) * V_173 , V_176 ) ;
if ( ! V_6 -> V_144 ) {
F_14 ( V_6 -> V_14 . V_48 , L_37 , V_55 ) ;
return 0 ;
}
F_63 ( V_6 -> V_144 , V_173 ) ;
V_143 = V_6 -> V_144 ;
for ( V_80 = 0 ; V_80 < V_173 ; V_80 ++ , V_143 ++ ) {
if ( V_80 == ( V_173 - 1 ) )
F_64 ( V_143 , F_65 ( V_141 -> V_8 ) ,
V_175 , V_65 * V_80 ) ;
else
F_64 ( V_143 , F_65 ( V_141 -> V_8 ) ,
V_98 , V_65 * V_80 ) ;
}
V_143 = V_6 -> V_144 ;
V_145 = F_75 ( V_14 -> V_48 , V_143 , V_173 , V_150 ) ;
if ( ! V_145 ) {
F_14 ( V_6 -> V_14 . V_48 , L_38 , V_55 ) ;
return 0 ;
}
V_6 -> V_145 = V_145 ;
for ( V_80 = 0 ; V_80 < V_145 ; V_80 ++ , V_143 ++ ) {
V_143 -> V_177 = ( V_141 -> V_146 & ( V_148 - 1 ) ) +
V_65 * V_80 ;
F_66 ( V_143 ) = ( F_66 ( V_143 ) &
~ ( V_148 - 1 ) ) + V_143 -> V_177 ;
if ( V_80 == ( V_145 - 1 ) )
F_53 ( V_143 ) = V_175 ;
else
F_53 ( V_143 ) = V_98 ;
}
V_162 = F_67 ( V_6 -> V_108 ,
V_6 -> V_144 , V_145 , V_178 ,
V_165 | V_166 ) ;
if ( ! V_162 ) {
F_14 ( V_6 -> V_14 . V_48 , L_39 ,
V_55 ) ;
return 0 ;
}
F_76 ( V_14 -> V_48 , V_6 -> V_144 , V_145 , V_150 ) ;
V_6 -> V_149 = V_162 ;
V_162 -> V_167 = F_52 ;
V_162 -> V_168 = V_6 ;
V_162 -> V_169 ( V_162 ) ;
F_68 ( V_6 -> V_108 ) ;
return V_172 ;
}
static void F_77 ( struct V_5 * V_6 , unsigned int V_85 )
{
struct V_86 * V_14 = & V_6 -> V_14 ;
struct V_103 * V_104 = F_32 ( & V_14 -> V_101 -> V_14 ) ;
char * V_179 [ 5 ] = {} ;
int V_80 = 0 ;
if ( V_85 & V_180 )
V_179 [ V_80 ++ ] = L_40 ;
if ( V_85 & V_181 ) {
V_14 -> V_90 . V_182 ++ ;
V_179 [ V_80 ++ ] = L_41 ;
}
if ( V_85 & V_183 ) {
V_14 -> V_90 . V_41 ++ ;
V_179 [ V_80 ++ ] = L_42 ;
}
if ( V_85 & V_184 ) {
V_14 -> V_90 . V_185 ++ ;
V_179 [ V_80 ++ ] = L_43 ;
}
if ( V_104 == NULL ) {
for ( V_80 = 0 ; V_179 [ V_80 ] != NULL ; V_80 ++ )
F_14 ( & V_6 -> V_125 -> V_48 , V_179 [ V_80 ] ) ;
}
}
static T_8 F_78 ( int V_186 , void * V_187 )
{
struct V_5 * V_6 = V_187 ;
unsigned int V_188 ;
T_6 V_85 ;
int V_10 = 0 ;
unsigned char V_189 ;
unsigned long V_190 ;
int V_191 = 1 ;
T_6 V_76 ;
F_79 ( & V_6 -> V_192 , V_190 ) ;
V_188 = 0 ;
while ( V_191 ) {
V_189 = F_24 ( V_6 ) ;
if ( V_189 & V_95 )
break;
switch ( V_189 ) {
case V_193 :
V_85 = F_25 ( V_6 ) ;
if ( V_85 & ( V_180 | V_181 |
V_183 | V_184 ) ) {
F_77 ( V_6 , V_85 ) ;
V_10 = V_194 ;
} else {
V_10 = V_195 ;
}
break;
case V_196 :
if ( V_6 -> V_197 ) {
F_11 ( V_6 ,
V_138 |
V_139 ) ;
V_10 = F_62 ( V_6 ) ;
if ( ! V_10 )
F_10 ( V_6 ,
V_138 |
V_139 ) ;
} else {
V_10 = F_61 ( V_6 ) ;
}
break;
case V_198 :
V_10 = F_60 ( V_6 ) ;
break;
case V_199 :
if ( V_6 -> V_197 )
V_10 = F_73 ( V_6 ) ;
else
V_10 = F_69 ( V_6 ) ;
break;
case V_200 :
V_76 = F_18 ( V_6 ) ;
V_191 = 0 ;
if ( ( V_76 & V_201 ) == 0 )
break;
V_10 |= V_202 ;
break;
default:
F_14 ( V_6 -> V_14 . V_48 , L_44 , V_55 ,
V_189 , V_56 ) ;
V_10 = - 1 ;
V_191 = 0 ;
break;
}
V_188 |= ( unsigned int ) V_10 ;
}
F_80 ( & V_6 -> V_192 , V_190 ) ;
return F_81 ( V_188 ) ;
}
static unsigned int F_82 ( struct V_86 * V_14 )
{
struct V_5 * V_6 ;
V_6 = F_38 ( V_14 , struct V_5 , V_14 ) ;
if ( V_6 -> V_170 )
return V_203 ;
else
return 0 ;
}
static unsigned int F_83 ( struct V_86 * V_14 )
{
struct V_5 * V_6 ;
T_6 V_204 ;
unsigned int V_10 = 0 ;
V_6 = F_38 ( V_14 , struct V_5 , V_14 ) ;
V_204 = F_18 ( V_6 ) ;
if ( V_204 & V_205 )
V_10 |= V_206 ;
if ( V_204 & V_207 )
V_10 |= V_208 ;
if ( V_204 & V_209 )
V_10 |= V_210 ;
if ( V_204 & V_211 )
V_10 |= V_212 ;
return V_10 ;
}
static void F_84 ( struct V_86 * V_14 , unsigned int V_213 )
{
T_5 V_214 = 0 ;
struct V_5 * V_6 = F_38 ( V_14 , struct V_5 , V_14 ) ;
if ( V_213 & V_215 )
V_214 |= V_216 ;
if ( V_213 & V_217 )
V_214 |= V_218 ;
if ( V_213 & V_219 )
V_214 |= V_220 ;
if ( V_6 -> V_214 & V_221 )
V_214 |= V_221 ;
if ( V_213 )
F_4 ( V_214 , V_6 -> V_15 + V_19 ) ;
}
static void F_85 ( struct V_86 * V_14 )
{
struct V_5 * V_6 ;
V_6 = F_38 ( V_14 , struct V_5 , V_14 ) ;
V_6 -> V_171 = 0 ;
V_6 -> V_151 = 0 ;
}
static void F_86 ( struct V_86 * V_14 )
{
struct V_5 * V_6 ;
V_6 = F_38 ( V_14 , struct V_5 , V_14 ) ;
if ( V_6 -> V_197 ) {
if ( V_6 -> V_151 ) {
F_15 ( V_6 -> V_14 . V_48 , L_45 ,
V_55 ) ;
return;
}
}
V_6 -> V_171 = 1 ;
F_10 ( V_6 , V_152 ) ;
}
static void F_87 ( struct V_86 * V_14 )
{
struct V_5 * V_6 ;
V_6 = F_38 ( V_14 , struct V_5 , V_14 ) ;
V_6 -> V_158 = 0 ;
F_11 ( V_6 , V_138 |
V_139 ) ;
}
static void F_88 ( struct V_86 * V_14 )
{
struct V_5 * V_6 ;
V_6 = F_38 ( V_14 , struct V_5 , V_14 ) ;
F_10 ( V_6 , V_222 ) ;
}
static void F_89 ( struct V_86 * V_14 , int V_223 )
{
struct V_5 * V_6 ;
unsigned long V_190 ;
V_6 = F_38 ( V_14 , struct V_5 , V_14 ) ;
F_79 ( & V_6 -> V_192 , V_190 ) ;
F_26 ( V_6 , V_223 ) ;
F_80 ( & V_6 -> V_192 , V_190 ) ;
}
static int F_90 ( struct V_86 * V_14 )
{
struct V_5 * V_6 ;
int V_10 ;
int V_65 ;
int V_70 ;
V_6 = F_38 ( V_14 , struct V_5 , V_14 ) ;
V_6 -> V_170 = 1 ;
if ( V_14 -> V_46 )
V_6 -> V_46 = V_14 -> V_46 ;
else
V_14 -> V_46 = V_6 -> V_46 ;
F_11 ( V_6 , V_224 ) ;
V_10 = F_12 ( V_6 , V_225 ,
V_226 , V_227 ,
V_228 ) ;
if ( V_10 )
return V_10 ;
switch ( V_6 -> V_65 ) {
case 256 :
V_65 = V_229 ;
break;
case 64 :
V_65 = V_230 ;
break;
case 16 :
V_65 = V_231 ;
break;
case 1 :
default:
V_65 = V_232 ;
break;
}
switch ( V_6 -> V_66 ) {
case V_233 :
V_70 = 1 ;
break;
case V_234 :
V_70 = V_6 -> V_65 / 4 ;
break;
case V_235 :
V_70 = V_6 -> V_65 / 2 ;
break;
case V_236 :
default:
V_70 = V_6 -> V_65 - ( V_6 -> V_65 / 8 ) ;
break;
}
V_6 -> V_70 = V_70 ;
V_10 = F_17 ( V_6 , V_237 ,
V_65 , V_6 -> V_66 ) ;
if ( V_10 < 0 )
return V_10 ;
V_10 = F_91 ( V_6 -> V_14 . V_186 , F_78 , V_238 ,
V_239 , V_6 ) ;
if ( V_10 < 0 )
return V_10 ;
if ( V_6 -> V_197 )
F_42 ( V_14 ) ;
V_6 -> V_158 = 1 ;
F_10 ( V_6 , V_138 |
V_139 ) ;
F_92 ( V_14 , V_240 , V_225 ) ;
return 0 ;
}
static void F_93 ( struct V_86 * V_14 )
{
struct V_5 * V_6 ;
int V_10 ;
V_6 = F_38 ( V_14 , struct V_5 , V_14 ) ;
F_11 ( V_6 , V_224 ) ;
F_16 ( V_6 , V_241 ) ;
V_10 = F_17 ( V_6 , V_237 ,
V_232 , V_233 ) ;
if ( V_10 )
F_14 ( V_6 -> V_14 . V_48 ,
L_46 , V_10 ) ;
F_37 ( V_14 ) ;
F_94 ( V_6 -> V_14 . V_186 , V_6 ) ;
}
static void F_95 ( struct V_86 * V_14 ,
struct V_242 * V_243 , struct V_242 * V_244 )
{
int V_40 ;
int V_245 ;
unsigned int V_41 , V_42 , V_43 ;
struct V_5 * V_6 ;
unsigned long V_190 ;
V_6 = F_38 ( V_14 , struct V_5 , V_14 ) ;
switch ( V_243 -> V_246 & V_247 ) {
case V_248 :
V_42 = V_249 ;
break;
case V_250 :
V_42 = V_251 ;
break;
case V_252 :
V_42 = V_253 ;
break;
default:
V_42 = V_227 ;
break;
}
if ( V_243 -> V_246 & V_254 )
V_43 = V_255 ;
else
V_43 = V_228 ;
if ( V_243 -> V_246 & V_256 ) {
if ( V_243 -> V_246 & V_257 )
V_41 = V_258 ;
else
V_41 = V_259 ;
} else
V_41 = V_226 ;
if ( ( V_243 -> V_246 & V_260 ) && ( V_6 -> V_65 == 256 ) )
V_6 -> V_214 |= V_221 ;
else
V_6 -> V_214 &= ~ V_221 ;
V_243 -> V_246 &= ~ V_261 ;
V_40 = F_96 ( V_14 , V_243 , V_244 , 0 , V_14 -> V_46 / 16 ) ;
F_79 ( & V_6 -> V_192 , V_190 ) ;
F_97 ( & V_14 -> V_192 ) ;
F_92 ( V_14 , V_243 -> V_246 , V_40 ) ;
V_245 = F_12 ( V_6 , V_40 , V_41 , V_42 , V_43 ) ;
if ( V_245 )
goto V_262;
F_84 ( & V_6 -> V_14 , V_6 -> V_14 . V_213 ) ;
if ( F_98 ( V_243 ) )
F_99 ( V_243 , V_40 , V_40 ) ;
V_262:
F_100 ( & V_14 -> V_192 ) ;
F_80 ( & V_6 -> V_192 , V_190 ) ;
}
static const char * F_101 ( struct V_86 * V_14 )
{
return V_239 ;
}
static void F_102 ( struct V_86 * V_14 )
{
struct V_5 * V_6 ;
V_6 = F_38 ( V_14 , struct V_5 , V_14 ) ;
F_103 ( V_6 -> V_125 , V_6 -> V_15 ) ;
F_104 ( V_6 -> V_125 ) ;
}
static int F_105 ( struct V_86 * V_14 )
{
struct V_5 * V_6 ;
int V_10 ;
void T_9 * V_15 ;
V_6 = F_38 ( V_14 , struct V_5 , V_14 ) ;
V_10 = F_106 ( V_6 -> V_125 , V_239 ) ;
if ( V_10 < 0 )
return - V_263 ;
V_15 = F_107 ( V_6 -> V_125 , 1 , 0 ) ;
if ( ! V_15 ) {
F_104 ( V_6 -> V_125 ) ;
return - V_263 ;
}
V_6 -> V_15 = V_14 -> V_15 = V_15 ;
return 0 ;
}
static void F_108 ( struct V_86 * V_14 , int type )
{
struct V_5 * V_6 ;
V_6 = F_38 ( V_14 , struct V_5 , V_14 ) ;
if ( type & V_264 ) {
V_14 -> type = V_6 -> V_265 ;
F_105 ( V_14 ) ;
}
}
static int F_109 ( struct V_86 * V_14 ,
struct V_266 * V_267 )
{
struct V_5 * V_6 ;
V_6 = F_38 ( V_14 , struct V_5 , V_14 ) ;
if ( V_267 -> V_190 & V_268 ) {
F_70 ( V_6 -> V_14 . V_48 ,
L_47 ) ;
V_6 -> V_197 = 0 ;
V_267 -> V_190 &= ~ V_268 ;
} else {
#ifndef F_110
F_14 ( V_6 -> V_14 . V_48 , L_48 ,
V_55 ) ;
return - V_269 ;
#endif
F_70 ( V_6 -> V_14 . V_48 , L_49 ) ;
if ( ! V_6 -> V_197 )
F_42 ( V_14 ) ;
V_6 -> V_197 = 1 ;
}
return 0 ;
}
static void F_111 ( struct V_5 * V_270 , int V_42 )
{
unsigned int V_271 , V_272 = 10000 ;
for (; ; ) {
V_271 = F_3 ( V_270 -> V_15 + V_20 ) ;
if ( ( V_271 & V_42 ) == V_42 )
break;
if ( -- V_272 == 0 )
break;
F_112 ( 1 ) ;
}
if ( V_270 -> V_14 . V_190 & V_273 ) {
unsigned int V_272 ;
for ( V_272 = 1000000 ; V_272 ; V_272 -- ) {
unsigned int V_76 = F_3 ( V_270 -> V_15 + V_21 ) ;
if ( V_76 & V_211 )
break;
F_112 ( 1 ) ;
F_113 () ;
}
}
}
static int F_114 ( struct V_86 * V_14 )
{
struct V_5 * V_6 =
F_38 ( V_14 , struct V_5 , V_14 ) ;
T_6 V_85 = F_3 ( V_6 -> V_15 + V_20 ) ;
if ( ! ( V_85 & V_87 ) )
return V_274 ;
return F_3 ( V_6 -> V_15 + V_89 ) ;
}
static void F_115 ( struct V_86 * V_14 ,
unsigned char V_275 )
{
unsigned int V_38 ;
struct V_5 * V_6 =
F_38 ( V_14 , struct V_5 , V_14 ) ;
V_38 = F_3 ( V_6 -> V_15 + V_16 ) ;
F_11 ( V_6 , V_224 ) ;
F_111 ( V_6 , V_276 ) ;
F_4 ( V_275 , V_6 -> V_15 + V_82 ) ;
if ( V_275 == 10 ) {
F_111 ( V_6 , V_276 ) ;
F_4 ( 13 , V_6 -> V_15 + V_82 ) ;
}
F_111 ( V_6 , V_277 ) ;
F_4 ( V_38 , V_6 -> V_15 + V_16 ) ;
}
static void F_116 ( struct V_86 * V_14 , int V_278 )
{
struct V_5 * V_6 =
F_38 ( V_14 , struct V_5 , V_14 ) ;
F_111 ( V_6 , V_276 ) ;
F_4 ( V_278 , V_6 -> V_15 + V_82 ) ;
}
static void
F_117 ( struct V_279 * V_280 , const char * V_281 , unsigned int V_3 )
{
struct V_5 * V_6 ;
unsigned long V_190 ;
int V_282 = 1 ;
int V_283 = 1 ;
T_6 V_38 ;
V_6 = V_284 [ V_280 -> V_285 ] ;
F_113 () ;
F_118 ( V_190 ) ;
if ( V_6 -> V_14 . V_92 ) {
V_282 = 0 ;
V_283 = 0 ;
} else if ( V_286 ) {
V_282 = F_119 ( & V_6 -> V_192 ) ;
V_283 = F_119 ( & V_6 -> V_14 . V_192 ) ;
} else {
F_97 ( & V_6 -> V_192 ) ;
F_97 ( & V_6 -> V_14 . V_192 ) ;
}
V_38 = F_3 ( V_6 -> V_15 + V_16 ) ;
F_11 ( V_6 , V_224 ) ;
F_120 ( & V_6 -> V_14 , V_281 , V_3 , F_116 ) ;
F_111 ( V_6 , V_277 ) ;
F_4 ( V_38 , V_6 -> V_15 + V_16 ) ;
if ( V_283 )
F_100 ( & V_6 -> V_14 . V_192 ) ;
if ( V_282 )
F_100 ( & V_6 -> V_192 ) ;
F_121 ( V_190 ) ;
}
static int T_10 F_122 ( struct V_279 * V_280 , char * V_287 )
{
struct V_86 * V_14 ;
int V_40 = V_225 ;
int V_42 = 8 ;
int V_41 = 'n' ;
int V_288 = 'n' ;
if ( V_280 -> V_285 >= V_289 )
V_280 -> V_285 = 0 ;
V_14 = & V_284 [ V_280 -> V_285 ] -> V_14 ;
if ( ! V_14 || ( ! V_14 -> V_290 && ! V_14 -> V_15 ) )
return - V_291 ;
V_14 -> V_46 = F_7 () ;
if ( V_287 )
F_123 ( V_287 , & V_40 , & V_41 , & V_42 , & V_288 ) ;
return F_124 ( V_14 , V_280 , V_40 , V_41 , V_42 , V_288 ) ;
}
static struct V_5 * F_125 ( struct V_123 * V_125 ,
const struct V_292 * V_293 )
{
struct V_5 * V_6 ;
int V_10 ;
unsigned int V_290 ;
unsigned int V_130 ;
unsigned char * V_159 ;
int V_111 ;
int V_265 ;
struct V_294 * V_295 ;
char V_296 [ 32 ] ;
V_295 = & V_297 [ V_293 -> V_298 ] ;
V_265 = V_295 -> V_265 ;
V_6 = F_2 ( sizeof( struct V_5 ) , V_13 ) ;
if ( V_6 == NULL )
goto V_299;
V_159 = ( unsigned char * ) F_126 ( V_13 ) ;
if ( ! V_159 )
goto V_300;
switch ( V_265 ) {
case V_301 :
V_111 = 256 ;
break;
case V_302 :
V_111 = 64 ;
break;
default:
F_14 ( & V_125 -> V_48 , L_50 , V_265 ) ;
goto V_303;
}
F_127 ( V_125 ) ;
F_128 ( V_125 ) ;
F_129 ( & V_6 -> V_192 ) ;
V_290 = F_130 ( V_125 , 0 ) ;
V_130 = F_130 ( V_125 , 1 ) ;
V_6 -> V_130 = V_130 ;
V_6 -> V_290 = V_290 ;
V_6 -> V_125 = V_125 ;
V_6 -> V_170 = 1 ;
V_6 -> V_159 . V_8 = V_159 ;
V_6 -> V_159 . V_98 = V_304 ;
V_6 -> V_65 = V_111 ;
V_6 -> V_46 = F_7 () ;
V_6 -> V_265 = V_305 + V_265 + 1 ;
V_6 -> V_14 . V_48 = & V_125 -> V_48 ;
V_6 -> V_14 . V_290 = V_290 ;
V_6 -> V_14 . V_15 = NULL ;
V_6 -> V_14 . V_130 = V_130 ;
V_6 -> V_14 . V_186 = V_125 -> V_186 ;
V_6 -> V_14 . V_306 = V_307 ;
V_6 -> V_14 . V_308 = & V_309 ;
V_6 -> V_14 . V_190 = V_310 ;
V_6 -> V_14 . V_111 = V_111 ;
V_6 -> V_14 . line = V_295 -> V_311 ;
V_6 -> V_66 = V_235 ;
F_129 ( & V_6 -> V_14 . V_192 ) ;
F_131 ( V_125 , V_6 ) ;
V_6 -> V_70 = 1 ;
V_6 -> V_62 = 0 ;
#ifdef F_132
V_284 [ V_295 -> V_311 ] = V_6 ;
#endif
V_10 = F_133 ( & V_312 , & V_6 -> V_14 ) ;
if ( V_10 < 0 )
goto V_303;
#ifdef F_134
snprintf ( V_296 , sizeof( V_296 ) , L_51 , V_295 -> V_311 ) ;
V_6 -> V_313 = F_135 ( V_296 , V_314 | V_315 ,
NULL , V_6 , & V_316 ) ;
#endif
return V_6 ;
V_303:
#ifdef F_132
V_284 [ V_295 -> V_311 ] = NULL ;
#endif
F_136 ( ( unsigned long ) V_159 ) ;
V_300:
F_6 ( V_6 ) ;
V_299:
return NULL ;
}
static void F_137 ( struct V_5 * V_6 )
{
#ifdef F_134
if ( V_6 -> V_313 )
F_138 ( V_6 -> V_313 ) ;
#endif
F_139 ( & V_312 , & V_6 -> V_14 ) ;
F_131 ( V_6 -> V_125 , NULL ) ;
F_136 ( ( unsigned long ) V_6 -> V_159 . V_8 ) ;
}
static void F_140 ( struct V_123 * V_125 )
{
struct V_5 * V_6 = F_141 ( V_125 ) ;
F_142 ( V_125 ) ;
#ifdef F_132
V_284 [ V_6 -> V_14 . line ] = NULL ;
#endif
F_137 ( V_6 ) ;
F_143 ( V_125 ) ;
F_6 ( V_6 ) ;
return;
}
static int F_144 ( struct V_123 * V_125 , T_11 V_101 )
{
struct V_5 * V_6 = F_141 ( V_125 ) ;
F_145 ( & V_312 , & V_6 -> V_14 ) ;
F_146 ( V_125 ) ;
F_147 ( V_125 , F_148 ( V_125 , V_101 ) ) ;
return 0 ;
}
static int F_149 ( struct V_123 * V_125 )
{
struct V_5 * V_6 = F_141 ( V_125 ) ;
int V_10 ;
F_147 ( V_125 , V_317 ) ;
F_150 ( V_125 ) ;
V_10 = F_151 ( V_125 ) ;
if ( V_10 ) {
F_14 ( & V_125 -> V_48 ,
L_52 , V_55 , V_10 ) ;
return V_10 ;
}
F_152 ( & V_312 , & V_6 -> V_14 ) ;
return 0 ;
}
static int F_153 ( struct V_123 * V_125 ,
const struct V_292 * V_293 )
{
int V_10 ;
struct V_5 * V_6 ;
V_10 = F_151 ( V_125 ) ;
if ( V_10 < 0 )
goto V_318;
V_6 = F_125 ( V_125 , V_293 ) ;
if ( ! V_6 ) {
V_10 = - V_263 ;
goto V_319;
}
F_131 ( V_125 , V_6 ) ;
return V_10 ;
V_319:
F_142 ( V_125 ) ;
F_143 ( V_125 ) ;
V_318:
return V_10 ;
}
static int T_10 F_154 ( void )
{
int V_10 ;
V_10 = F_155 ( & V_312 ) ;
if ( V_10 < 0 )
return V_10 ;
V_10 = F_156 ( & V_320 ) ;
if ( V_10 < 0 )
F_157 ( & V_312 ) ;
return V_10 ;
}
static void T_12 F_158 ( void )
{
F_159 ( & V_320 ) ;
F_157 ( & V_312 ) ;
}
