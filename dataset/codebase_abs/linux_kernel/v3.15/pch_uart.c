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
static unsigned int F_7 ( void )
{
const struct V_26 * V_27 ;
if ( V_28 )
return V_28 ;
V_27 = F_8 ( V_29 ) ;
if ( V_27 )
return ( unsigned long ) V_27 -> V_30 ;
return V_31 ;
}
static void F_9 ( struct V_5 * V_6 ,
unsigned int V_32 )
{
T_6 V_33 = F_3 ( V_6 -> V_15 + V_16 ) ;
V_33 |= V_32 & V_34 ;
F_4 ( V_33 , V_6 -> V_15 + V_16 ) ;
}
static void F_10 ( struct V_5 * V_6 ,
unsigned int V_32 )
{
T_6 V_33 = F_3 ( V_6 -> V_15 + V_16 ) ;
V_33 &= ~ ( V_32 & V_34 ) ;
F_4 ( V_33 , V_6 -> V_15 + V_16 ) ;
}
static int F_11 ( struct V_5 * V_6 , unsigned int V_35 ,
unsigned int V_36 , unsigned int V_37 ,
unsigned int V_38 )
{
unsigned int V_39 , V_40 , V_11 ;
int div ;
div = F_12 ( V_6 -> V_41 / 16 , V_35 ) ;
if ( div < 0 || V_42 <= div ) {
F_13 ( V_6 -> V_14 . V_43 , L_12 , div ) ;
return - V_44 ;
}
V_39 = ( unsigned int ) div & 0x00FFU ;
V_40 = ( ( unsigned int ) div >> 8 ) & 0x00FFU ;
if ( V_36 & ~ ( V_45 | V_46 | V_47 ) ) {
F_13 ( V_6 -> V_14 . V_43 , L_13 , V_36 ) ;
return - V_44 ;
}
if ( V_37 & ~ V_48 ) {
F_13 ( V_6 -> V_14 . V_43 , L_14 , V_37 ) ;
return - V_44 ;
}
if ( V_38 & ~ V_49 ) {
F_13 ( V_6 -> V_14 . V_43 , L_15 , V_38 ) ;
return - V_44 ;
}
V_11 = V_36 ;
V_11 |= V_37 ;
V_11 |= V_38 ;
F_14 ( V_6 -> V_14 . V_43 , L_16 ,
V_50 , V_35 , div , V_11 , V_51 ) ;
F_4 ( V_23 , V_6 -> V_15 + V_18 ) ;
F_4 ( V_39 , V_6 -> V_15 + V_52 ) ;
F_4 ( V_40 , V_6 -> V_15 + V_53 ) ;
F_4 ( V_11 , V_6 -> V_15 + V_18 ) ;
return 0 ;
}
static int F_15 ( struct V_5 * V_6 ,
unsigned int V_32 )
{
if ( V_32 & ~ ( V_54 | V_55 ) ) {
F_13 ( V_6 -> V_14 . V_43 , L_17 ,
V_50 , V_32 ) ;
return - V_44 ;
}
F_4 ( V_56 | V_6 -> V_57 , V_6 -> V_15 + V_58 ) ;
F_4 ( V_56 | V_6 -> V_57 | V_32 ,
V_6 -> V_15 + V_58 ) ;
F_4 ( V_6 -> V_57 , V_6 -> V_15 + V_58 ) ;
return 0 ;
}
static int F_16 ( struct V_5 * V_6 ,
unsigned int V_59 ,
unsigned int V_60 , unsigned int V_61 )
{
T_6 V_57 ;
if ( V_59 & ~ V_62 ) {
F_13 ( V_6 -> V_14 . V_43 , L_18 ,
V_50 , V_59 ) ;
return - V_44 ;
}
if ( V_60 & ~ ( V_56 | V_63 ) ) {
F_13 ( V_6 -> V_14 . V_43 , L_19 ,
V_50 , V_60 ) ;
return - V_44 ;
}
if ( V_61 & ~ V_64 ) {
F_13 ( V_6 -> V_14 . V_43 , L_20 ,
V_50 , V_61 ) ;
return - V_44 ;
}
switch ( V_6 -> V_60 ) {
case 256 :
V_6 -> V_65 =
V_66 [ V_61 >> V_67 ] ;
break;
case 64 :
V_6 -> V_65 =
V_68 [ V_61 >> V_67 ] ;
break;
case 16 :
V_6 -> V_65 =
V_69 [ V_61 >> V_67 ] ;
break;
default:
V_6 -> V_65 =
V_70 [ V_61 >> V_67 ] ;
break;
}
V_57 =
V_59 | V_60 | V_61 | V_55 | V_54 ;
F_4 ( V_56 , V_6 -> V_15 + V_58 ) ;
F_4 ( V_56 | V_55 | V_54 ,
V_6 -> V_15 + V_58 ) ;
F_4 ( V_57 , V_6 -> V_15 + V_58 ) ;
V_6 -> V_57 = V_57 ;
return 0 ;
}
static T_6 F_17 ( struct V_5 * V_6 )
{
unsigned int V_71 = F_3 ( V_6 -> V_15 + V_21 ) ;
V_6 -> V_72 = V_71 & V_73 ;
return ( T_6 ) V_71 ;
}
static void F_18 ( struct V_5 * V_6 ,
const unsigned char * V_8 , int V_74 )
{
int V_75 ;
unsigned int V_76 ;
for ( V_75 = 0 ; V_75 < V_74 ; ) {
V_76 = V_8 [ V_75 ++ ] ;
F_4 ( V_76 , V_6 -> V_15 + V_77 ) ;
}
}
static int F_19 ( struct V_5 * V_6 , unsigned char * V_8 ,
int V_78 )
{
int V_75 ;
T_6 V_79 , V_80 ;
struct V_81 * V_14 = & V_6 -> V_14 ;
V_80 = F_3 ( V_6 -> V_15 + V_20 ) ;
for ( V_75 = 0 , V_80 = F_3 ( V_6 -> V_15 + V_20 ) ;
V_75 < V_78 && V_80 & ( V_82 | V_83 ) ;
V_80 = F_3 ( V_6 -> V_15 + V_20 ) ) {
V_79 = F_3 ( V_6 -> V_15 + V_84 ) ;
if ( V_80 & V_83 ) {
V_14 -> V_85 . V_86 ++ ;
if ( F_20 ( V_14 ) )
continue;
}
#ifdef F_21
if ( V_14 -> V_87 ) {
if ( F_22 ( V_14 , V_79 ) )
continue;
}
#endif
V_8 [ V_75 ++ ] = V_79 ;
}
return V_75 ;
}
static unsigned char F_23 ( struct V_5 * V_6 )
{
return F_3 ( V_6 -> V_15 + V_17 ) &\
( V_88 | V_89 | V_90 ) ;
}
static T_6 F_24 ( struct V_5 * V_6 )
{
return F_3 ( V_6 -> V_15 + V_20 ) ;
}
static void F_25 ( struct V_5 * V_6 , int V_91 )
{
unsigned int V_11 ;
V_11 = F_3 ( V_6 -> V_15 + V_18 ) ;
if ( V_91 )
V_11 |= V_92 ;
else
V_11 &= ~ V_92 ;
F_4 ( V_11 , V_6 -> V_15 + V_18 ) ;
}
static int F_26 ( struct V_5 * V_6 , const unsigned char * V_8 ,
int V_93 )
{
struct V_81 * V_14 = & V_6 -> V_14 ;
struct V_94 * V_95 = & V_14 -> V_96 -> V_14 ;
F_27 ( V_95 , V_8 , V_93 ) ;
F_28 ( V_95 ) ;
return 0 ;
}
static int F_29 ( struct V_5 * V_6 , unsigned char * V_8 )
{
int V_10 = 0 ;
struct V_81 * V_14 = & V_6 -> V_14 ;
if ( V_14 -> V_97 ) {
F_14 ( V_6 -> V_14 . V_43 , L_21 ,
V_50 , V_14 -> V_97 , V_51 ) ;
V_8 [ 0 ] = V_14 -> V_97 ;
V_14 -> V_97 = 0 ;
V_10 = 1 ;
}
return V_10 ;
}
static int F_30 ( struct V_5 * V_6 , int V_93 )
{
int V_98 ;
struct V_81 * V_14 = & V_6 -> V_14 ;
struct V_94 * V_95 = & V_14 -> V_96 -> V_14 ;
V_98 = F_31 ( V_95 , V_93 ) ;
if ( V_98 < V_93 )
F_32 ( V_14 -> V_43 , L_22 ,
V_93 - V_98 ) ;
if ( ! V_98 )
return 0 ;
F_27 ( V_95 , F_33 ( & V_6 -> V_99 ) , V_93 ) ;
V_14 -> V_85 . V_100 += V_98 ;
return V_98 ;
}
static void F_34 ( struct V_81 * V_14 )
{
struct V_5 * V_6 ;
V_6 = F_35 ( V_14 , struct V_5 , V_14 ) ;
if ( V_6 -> V_101 ) {
F_36 ( V_6 -> V_101 ) ;
V_6 -> V_101 = NULL ;
}
if ( V_6 -> V_102 ) {
F_36 ( V_6 -> V_102 ) ;
V_6 -> V_102 = NULL ;
}
if ( V_6 -> V_103 ) {
F_37 ( V_14 -> V_43 , V_14 -> V_104 , V_6 -> V_105 ,
V_6 -> V_103 ) ;
V_6 -> V_105 = NULL ;
V_6 -> V_103 = 0 ;
}
return;
}
static bool F_38 ( struct V_106 * V_107 , void * V_108 )
{
struct V_109 * V_110 = V_108 ;
if ( ( V_107 -> V_111 == V_110 -> V_111 ) && ( V_110 -> V_112 ==
V_107 -> V_113 -> V_43 ) ) {
V_107 -> V_114 = V_110 ;
return true ;
} else {
return false ;
}
}
static void F_39 ( struct V_81 * V_14 )
{
T_7 V_115 ;
struct V_106 * V_107 ;
struct V_116 * V_112 ;
struct V_109 * V_110 ;
struct V_5 * V_6 =
F_35 ( V_14 , struct V_5 , V_14 ) ;
F_40 ( V_115 ) ;
F_41 ( V_117 , V_115 ) ;
V_112 = F_42 ( V_6 -> V_118 -> V_119 -> V_120 ,
F_43 ( 0xa , 0 ) ) ;
V_110 = & V_6 -> V_121 ;
V_110 -> V_112 = & V_112 -> V_43 ;
V_110 -> V_111 = V_6 -> V_14 . line * 2 ;
V_110 -> V_122 = V_14 -> V_123 + V_124 ;
V_107 = F_44 ( V_115 , F_38 , V_110 ) ;
if ( ! V_107 ) {
F_13 ( V_6 -> V_14 . V_43 , L_23 ,
V_50 ) ;
return;
}
V_6 -> V_101 = V_107 ;
V_110 = & V_6 -> V_125 ;
V_110 -> V_112 = & V_112 -> V_43 ;
V_110 -> V_111 = V_6 -> V_14 . line * 2 + 1 ;
V_110 -> V_126 = V_14 -> V_123 + V_127 ;
V_107 = F_44 ( V_115 , F_38 , V_110 ) ;
if ( ! V_107 ) {
F_13 ( V_6 -> V_14 . V_43 , L_24 ,
V_50 ) ;
F_36 ( V_6 -> V_101 ) ;
V_6 -> V_101 = NULL ;
return;
}
V_6 -> V_105 = F_45 ( V_14 -> V_43 , V_14 -> V_104 ,
& V_6 -> V_103 , V_13 ) ;
V_6 -> V_102 = V_107 ;
}
static void F_46 ( void * V_128 )
{
struct V_5 * V_6 = V_128 ;
struct V_81 * V_14 = & V_6 -> V_14 ;
int V_3 ;
F_47 ( V_14 -> V_43 , & V_6 -> V_99 , 1 , V_129 ) ;
V_3 = F_30 ( V_6 , V_6 -> V_65 ) ;
if ( V_3 )
F_28 ( & V_14 -> V_96 -> V_14 ) ;
F_48 ( V_6 -> V_130 ) ;
F_9 ( V_6 , V_131 |
V_132 ) ;
}
static void F_49 ( void * V_128 )
{
struct V_5 * V_6 = V_128 ;
struct V_81 * V_14 = & V_6 -> V_14 ;
struct V_133 * V_134 = & V_14 -> V_96 -> V_134 ;
struct V_135 * V_136 = V_6 -> V_137 ;
int V_75 ;
for ( V_75 = 0 ; V_75 < V_6 -> V_138 ; V_75 ++ , V_136 ++ ) {
V_134 -> V_139 += F_50 ( V_136 ) ;
V_14 -> V_85 . V_140 += F_50 ( V_136 ) ;
}
V_134 -> V_139 &= V_141 - 1 ;
F_48 ( V_6 -> V_142 ) ;
F_51 ( V_14 -> V_43 , V_136 , V_6 -> V_138 , V_143 ) ;
V_6 -> V_144 = 0 ;
V_6 -> V_138 = 0 ;
F_6 ( V_6 -> V_137 ) ;
F_9 ( V_6 , V_145 ) ;
}
static int F_52 ( struct V_5 * V_6 , int V_93 )
{
int V_3 = 0 ;
struct V_81 * V_14 = & V_6 -> V_14 ;
struct V_133 * V_134 = & V_14 -> V_96 -> V_134 ;
if ( F_53 ( V_14 ) || F_54 ( V_134 ) || V_3 >= V_93 )
goto V_146;
do {
int V_147 =
F_55 ( V_134 -> V_148 , V_134 -> V_139 , V_141 ) ;
int V_149 = F_56 ( V_93 - V_3 , V_147 ) ;
F_18 ( V_6 , & V_134 -> V_8 [ V_134 -> V_139 ] , V_149 ) ;
V_134 -> V_139 = ( V_134 -> V_139 + V_149 ) & ( V_141 - 1 ) ;
V_3 += V_149 ;
} while ( ! F_54 ( V_134 ) && V_3 < V_93 );
V_146:
F_14 ( V_6 -> V_14 . V_43 , L_25 ,
V_3 , V_93 - V_3 , V_51 ) ;
return V_3 ;
}
static int F_57 ( struct V_5 * V_6 )
{
struct V_150 * V_8 ;
int V_78 ;
int V_10 ;
if ( ! V_6 -> V_151 ) {
F_10 ( V_6 , V_131 |
V_132 ) ;
return 0 ;
}
V_8 = & V_6 -> V_152 ;
do {
V_78 = F_19 ( V_6 , V_8 -> V_8 , V_8 -> V_93 ) ;
V_10 = F_26 ( V_6 , V_8 -> V_8 , V_78 ) ;
if ( V_10 )
return 0 ;
} while ( V_78 == V_8 -> V_93 );
return V_153 ;
}
static int F_58 ( struct V_5 * V_6 )
{
return F_57 ( V_6 ) ;
}
static int F_59 ( struct V_5 * V_6 )
{
struct V_81 * V_14 = & V_6 -> V_14 ;
struct V_154 * V_155 ;
struct V_135 * V_136 ;
V_6 = F_35 ( V_14 , struct V_5 , V_14 ) ;
V_136 = & V_6 -> V_99 ;
F_60 ( & V_6 -> V_99 , 1 ) ;
F_50 ( V_136 ) = V_6 -> V_65 ;
F_61 ( & V_6 -> V_99 , F_62 ( V_6 -> V_105 ) ,
F_50 ( V_136 ) , ( unsigned long ) V_6 -> V_105 &
~ V_156 ) ;
F_63 ( V_136 ) = V_6 -> V_103 ;
V_155 = F_64 ( V_6 -> V_102 ,
V_136 , 1 , V_157 ,
V_158 | V_159 ) ;
if ( ! V_155 )
return 0 ;
V_6 -> V_130 = V_155 ;
V_155 -> V_160 = F_46 ;
V_155 -> V_161 = V_6 ;
V_155 -> V_162 ( V_155 ) ;
F_65 ( V_6 -> V_102 ) ;
return V_153 ;
}
static unsigned int F_66 ( struct V_5 * V_6 )
{
struct V_81 * V_14 = & V_6 -> V_14 ;
struct V_133 * V_134 = & V_14 -> V_96 -> V_134 ;
int V_60 ;
int V_74 ;
int V_93 ;
int V_163 ;
if ( ! V_6 -> V_164 ) {
F_67 ( V_6 -> V_14 . V_43 , L_26 ,
V_50 , V_51 ) ;
F_10 ( V_6 , V_145 ) ;
V_6 -> V_163 = 1 ;
return 0 ;
}
V_60 = F_68 ( V_6 -> V_60 , 1 ) ;
V_163 = 1 ;
if ( F_29 ( V_6 , V_134 -> V_8 ) ) {
F_18 ( V_6 , V_134 -> V_8 , 1 ) ;
V_14 -> V_85 . V_140 ++ ;
V_163 = 0 ;
V_60 -- ;
}
V_93 = F_56 ( V_134 -> V_148 - V_134 -> V_139 , V_60 ) ;
if ( V_93 < 0 )
V_93 = V_60 ;
V_74 = F_52 ( V_6 , V_93 ) ;
if ( V_74 > 0 ) {
V_14 -> V_85 . V_140 += V_74 ;
V_163 = 0 ;
}
V_6 -> V_163 = V_163 ;
if ( V_163 ) {
F_10 ( V_6 , V_145 ) ;
F_69 ( V_14 ) ;
}
return V_165 ;
}
static unsigned int F_70 ( struct V_5 * V_6 )
{
struct V_81 * V_14 = & V_6 -> V_14 ;
struct V_133 * V_134 = & V_14 -> V_96 -> V_134 ;
struct V_135 * V_136 ;
int V_138 ;
int V_60 ;
int V_163 ;
struct V_154 * V_155 ;
int V_166 ;
int V_75 ;
int V_167 ;
int V_93 ;
int V_168 ;
if ( ! V_6 -> V_164 ) {
F_67 ( V_6 -> V_14 . V_43 , L_26 ,
V_50 , V_51 ) ;
F_10 ( V_6 , V_145 ) ;
V_6 -> V_163 = 1 ;
return 0 ;
}
if ( V_6 -> V_144 ) {
F_14 ( V_6 -> V_14 . V_43 , L_27 ,
V_50 , V_51 ) ;
F_10 ( V_6 , V_145 ) ;
V_6 -> V_163 = 1 ;
return 0 ;
}
V_60 = F_68 ( V_6 -> V_60 , 1 ) ;
V_163 = 1 ;
if ( F_29 ( V_6 , V_134 -> V_8 ) ) {
F_18 ( V_6 , V_134 -> V_8 , 1 ) ;
V_14 -> V_85 . V_140 ++ ;
V_163 = 0 ;
V_60 -- ;
}
V_167 = F_56 ( ( int ) F_71 ( V_134 -> V_148 , V_134 -> V_139 ,
V_141 ) , F_55 ( V_134 -> V_148 ,
V_134 -> V_139 , V_141 ) ) ;
if ( ! V_167 ) {
F_14 ( V_6 -> V_14 . V_43 , L_28 , V_50 ) ;
F_10 ( V_6 , V_145 ) ;
F_69 ( V_14 ) ;
return 0 ;
}
if ( V_167 > V_60 ) {
V_166 = V_167 / V_60 + 1 ;
V_93 = V_60 ;
V_168 = V_167 % V_60 ;
} else {
V_166 = 1 ;
V_93 = V_167 ;
V_168 = V_167 ;
}
F_14 ( V_6 -> V_14 . V_43 , L_29 ,
V_50 , V_166 , V_93 , V_168 ) ;
V_6 -> V_144 = 1 ;
V_6 -> V_137 = F_2 ( sizeof( struct V_135 ) * V_166 , V_169 ) ;
if ( ! V_6 -> V_137 ) {
F_13 ( V_6 -> V_14 . V_43 , L_30 , V_50 ) ;
return 0 ;
}
F_60 ( V_6 -> V_137 , V_166 ) ;
V_136 = V_6 -> V_137 ;
for ( V_75 = 0 ; V_75 < V_166 ; V_75 ++ , V_136 ++ ) {
if ( V_75 == ( V_166 - 1 ) )
F_61 ( V_136 , F_62 ( V_134 -> V_8 ) ,
V_168 , V_60 * V_75 ) ;
else
F_61 ( V_136 , F_62 ( V_134 -> V_8 ) ,
V_93 , V_60 * V_75 ) ;
}
V_136 = V_6 -> V_137 ;
V_138 = F_72 ( V_14 -> V_43 , V_136 , V_166 , V_143 ) ;
if ( ! V_138 ) {
F_13 ( V_6 -> V_14 . V_43 , L_31 , V_50 ) ;
return 0 ;
}
V_6 -> V_138 = V_138 ;
for ( V_75 = 0 ; V_75 < V_138 ; V_75 ++ , V_136 ++ ) {
V_136 -> V_170 = ( V_134 -> V_139 & ( V_141 - 1 ) ) +
V_60 * V_75 ;
F_63 ( V_136 ) = ( F_63 ( V_136 ) &
~ ( V_141 - 1 ) ) + V_136 -> V_170 ;
if ( V_75 == ( V_138 - 1 ) )
F_50 ( V_136 ) = V_168 ;
else
F_50 ( V_136 ) = V_93 ;
}
V_155 = F_64 ( V_6 -> V_101 ,
V_6 -> V_137 , V_138 , V_171 ,
V_158 | V_159 ) ;
if ( ! V_155 ) {
F_13 ( V_6 -> V_14 . V_43 , L_32 ,
V_50 ) ;
return 0 ;
}
F_73 ( V_14 -> V_43 , V_6 -> V_137 , V_138 , V_143 ) ;
V_6 -> V_142 = V_155 ;
V_155 -> V_160 = F_49 ;
V_155 -> V_161 = V_6 ;
V_155 -> V_162 ( V_155 ) ;
F_65 ( V_6 -> V_101 ) ;
return V_165 ;
}
static void F_74 ( struct V_5 * V_6 , unsigned int V_80 )
{
struct V_81 * V_14 = & V_6 -> V_14 ;
struct V_172 * V_173 = F_75 ( & V_14 -> V_96 -> V_14 ) ;
char * V_174 [ 5 ] = {} ;
int V_75 = 0 ;
if ( V_80 & V_175 )
V_174 [ V_75 ++ ] = L_33 ;
if ( V_80 & V_176 ) {
V_14 -> V_85 . V_177 ++ ;
V_174 [ V_75 ++ ] = L_34 ;
}
if ( V_80 & V_178 ) {
V_14 -> V_85 . V_36 ++ ;
V_174 [ V_75 ++ ] = L_35 ;
}
if ( V_80 & V_179 ) {
V_14 -> V_85 . V_180 ++ ;
V_174 [ V_75 ++ ] = L_36 ;
}
if ( V_173 == NULL ) {
for ( V_75 = 0 ; V_174 [ V_75 ] != NULL ; V_75 ++ )
F_13 ( & V_6 -> V_118 -> V_43 , V_174 [ V_75 ] ) ;
} else {
F_76 ( V_173 ) ;
}
}
static T_8 F_77 ( int V_181 , void * V_182 )
{
struct V_5 * V_6 = V_182 ;
unsigned int V_183 ;
T_6 V_80 ;
int V_10 = 0 ;
unsigned char V_184 ;
unsigned long V_185 ;
int V_186 = 1 ;
T_6 V_71 ;
F_78 ( & V_6 -> V_187 , V_185 ) ;
V_183 = 0 ;
while ( V_186 ) {
V_184 = F_23 ( V_6 ) ;
if ( V_184 & V_90 )
break;
switch ( V_184 ) {
case V_188 :
V_80 = F_24 ( V_6 ) ;
if ( V_80 & ( V_175 | V_176 |
V_178 | V_179 ) ) {
F_74 ( V_6 , V_80 ) ;
V_10 = V_189 ;
} else {
V_10 = V_190 ;
}
break;
case V_191 :
if ( V_6 -> V_192 ) {
F_10 ( V_6 ,
V_131 |
V_132 ) ;
V_10 = F_59 ( V_6 ) ;
if ( ! V_10 )
F_9 ( V_6 ,
V_131 |
V_132 ) ;
} else {
V_10 = F_58 ( V_6 ) ;
}
break;
case V_193 :
V_10 = F_57 ( V_6 ) ;
break;
case V_194 :
if ( V_6 -> V_192 )
V_10 = F_70 ( V_6 ) ;
else
V_10 = F_66 ( V_6 ) ;
break;
case V_195 :
V_71 = F_17 ( V_6 ) ;
V_186 = 0 ;
if ( ( V_71 & V_196 ) == 0 )
break;
V_10 |= V_197 ;
break;
default:
F_13 ( V_6 -> V_14 . V_43 , L_37 , V_50 ,
V_184 , V_51 ) ;
V_10 = - 1 ;
V_186 = 0 ;
break;
}
V_183 |= ( unsigned int ) V_10 ;
}
F_79 ( & V_6 -> V_187 , V_185 ) ;
return F_80 ( V_183 ) ;
}
static unsigned int F_81 ( struct V_81 * V_14 )
{
struct V_5 * V_6 ;
V_6 = F_35 ( V_14 , struct V_5 , V_14 ) ;
if ( V_6 -> V_163 )
return V_198 ;
else
return 0 ;
}
static unsigned int F_82 ( struct V_81 * V_14 )
{
struct V_5 * V_6 ;
T_6 V_199 ;
unsigned int V_10 = 0 ;
V_6 = F_35 ( V_14 , struct V_5 , V_14 ) ;
V_199 = F_17 ( V_6 ) ;
if ( V_199 & V_200 )
V_10 |= V_201 ;
if ( V_199 & V_202 )
V_10 |= V_203 ;
if ( V_199 & V_204 )
V_10 |= V_205 ;
if ( V_199 & V_206 )
V_10 |= V_207 ;
return V_10 ;
}
static void F_83 ( struct V_81 * V_14 , unsigned int V_208 )
{
T_5 V_209 = 0 ;
struct V_5 * V_6 = F_35 ( V_14 , struct V_5 , V_14 ) ;
if ( V_208 & V_210 )
V_209 |= V_211 ;
if ( V_208 & V_212 )
V_209 |= V_213 ;
if ( V_208 & V_214 )
V_209 |= V_215 ;
if ( V_6 -> V_209 & V_216 )
V_209 |= V_216 ;
if ( V_208 )
F_4 ( V_209 , V_6 -> V_15 + V_19 ) ;
}
static void F_84 ( struct V_81 * V_14 )
{
struct V_5 * V_6 ;
V_6 = F_35 ( V_14 , struct V_5 , V_14 ) ;
V_6 -> V_164 = 0 ;
V_6 -> V_144 = 0 ;
}
static void F_85 ( struct V_81 * V_14 )
{
struct V_5 * V_6 ;
V_6 = F_35 ( V_14 , struct V_5 , V_14 ) ;
if ( V_6 -> V_192 ) {
if ( V_6 -> V_144 ) {
F_14 ( V_6 -> V_14 . V_43 , L_38 ,
V_50 ) ;
return;
}
}
V_6 -> V_164 = 1 ;
F_9 ( V_6 , V_145 ) ;
}
static void F_86 ( struct V_81 * V_14 )
{
struct V_5 * V_6 ;
V_6 = F_35 ( V_14 , struct V_5 , V_14 ) ;
V_6 -> V_151 = 0 ;
F_10 ( V_6 , V_131 |
V_132 ) ;
}
static void F_87 ( struct V_81 * V_14 )
{
struct V_5 * V_6 ;
V_6 = F_35 ( V_14 , struct V_5 , V_14 ) ;
F_9 ( V_6 , V_217 ) ;
}
static void F_88 ( struct V_81 * V_14 , int V_218 )
{
struct V_5 * V_6 ;
unsigned long V_185 ;
V_6 = F_35 ( V_14 , struct V_5 , V_14 ) ;
F_78 ( & V_6 -> V_187 , V_185 ) ;
F_25 ( V_6 , V_218 ) ;
F_79 ( & V_6 -> V_187 , V_185 ) ;
}
static int F_89 ( struct V_81 * V_14 )
{
struct V_5 * V_6 ;
int V_10 ;
int V_60 ;
int V_65 ;
V_6 = F_35 ( V_14 , struct V_5 , V_14 ) ;
V_6 -> V_163 = 1 ;
if ( V_14 -> V_41 )
V_6 -> V_41 = V_14 -> V_41 ;
else
V_14 -> V_41 = V_6 -> V_41 ;
F_10 ( V_6 , V_219 ) ;
V_10 = F_11 ( V_6 , V_220 ,
V_221 , V_222 ,
V_223 ) ;
if ( V_10 )
return V_10 ;
switch ( V_6 -> V_60 ) {
case 256 :
V_60 = V_224 ;
break;
case 64 :
V_60 = V_225 ;
break;
case 16 :
V_60 = V_226 ;
break;
case 1 :
default:
V_60 = V_227 ;
break;
}
switch ( V_6 -> V_61 ) {
case V_228 :
V_65 = 1 ;
break;
case V_229 :
V_65 = V_6 -> V_60 / 4 ;
break;
case V_230 :
V_65 = V_6 -> V_60 / 2 ;
break;
case V_231 :
default:
V_65 = V_6 -> V_60 - ( V_6 -> V_60 / 8 ) ;
break;
}
V_6 -> V_65 = V_65 ;
V_10 = F_16 ( V_6 , V_232 ,
V_60 , V_6 -> V_61 ) ;
if ( V_10 < 0 )
return V_10 ;
V_10 = F_90 ( V_6 -> V_14 . V_181 , F_77 , V_233 ,
V_234 , V_6 ) ;
if ( V_10 < 0 )
return V_10 ;
if ( V_6 -> V_192 )
F_39 ( V_14 ) ;
V_6 -> V_151 = 1 ;
F_9 ( V_6 , V_131 |
V_132 ) ;
F_91 ( V_14 , V_235 , V_220 ) ;
return 0 ;
}
static void F_92 ( struct V_81 * V_14 )
{
struct V_5 * V_6 ;
int V_10 ;
V_6 = F_35 ( V_14 , struct V_5 , V_14 ) ;
F_10 ( V_6 , V_219 ) ;
F_15 ( V_6 , V_236 ) ;
V_10 = F_16 ( V_6 , V_232 ,
V_227 , V_228 ) ;
if ( V_10 )
F_13 ( V_6 -> V_14 . V_43 ,
L_39 , V_10 ) ;
F_34 ( V_14 ) ;
F_93 ( V_6 -> V_14 . V_181 , V_6 ) ;
}
static void F_94 ( struct V_81 * V_14 ,
struct V_237 * V_238 , struct V_237 * V_239 )
{
int V_240 ;
unsigned int V_35 , V_36 , V_37 , V_38 ;
struct V_5 * V_6 ;
unsigned long V_185 ;
V_6 = F_35 ( V_14 , struct V_5 , V_14 ) ;
switch ( V_238 -> V_241 & V_242 ) {
case V_243 :
V_37 = V_244 ;
break;
case V_245 :
V_37 = V_246 ;
break;
case V_247 :
V_37 = V_248 ;
break;
default:
V_37 = V_222 ;
break;
}
if ( V_238 -> V_241 & V_249 )
V_38 = V_250 ;
else
V_38 = V_223 ;
if ( V_238 -> V_241 & V_251 ) {
if ( V_238 -> V_241 & V_252 )
V_36 = V_253 ;
else
V_36 = V_254 ;
} else
V_36 = V_221 ;
if ( ( V_238 -> V_241 & V_255 ) && ( V_6 -> V_60 == 256 ) )
V_6 -> V_209 |= V_216 ;
else
V_6 -> V_209 &= ~ V_216 ;
V_238 -> V_241 &= ~ V_256 ;
V_35 = F_95 ( V_14 , V_238 , V_239 , 0 , V_14 -> V_41 / 16 ) ;
F_78 ( & V_6 -> V_187 , V_185 ) ;
F_96 ( & V_14 -> V_187 ) ;
F_91 ( V_14 , V_238 -> V_241 , V_35 ) ;
V_240 = F_11 ( V_6 , V_35 , V_36 , V_37 , V_38 ) ;
if ( V_240 )
goto V_257;
F_83 ( & V_6 -> V_14 , V_6 -> V_14 . V_208 ) ;
if ( F_97 ( V_238 ) )
F_98 ( V_238 , V_35 , V_35 ) ;
V_257:
F_99 ( & V_14 -> V_187 ) ;
F_79 ( & V_6 -> V_187 , V_185 ) ;
}
static const char * F_100 ( struct V_81 * V_14 )
{
return V_234 ;
}
static void F_101 ( struct V_81 * V_14 )
{
struct V_5 * V_6 ;
V_6 = F_35 ( V_14 , struct V_5 , V_14 ) ;
F_102 ( V_6 -> V_118 , V_6 -> V_15 ) ;
F_103 ( V_6 -> V_118 ) ;
}
static int F_104 ( struct V_81 * V_14 )
{
struct V_5 * V_6 ;
int V_10 ;
void T_9 * V_15 ;
V_6 = F_35 ( V_14 , struct V_5 , V_14 ) ;
V_10 = F_105 ( V_6 -> V_118 , V_234 ) ;
if ( V_10 < 0 )
return - V_258 ;
V_15 = F_106 ( V_6 -> V_118 , 1 , 0 ) ;
if ( ! V_15 ) {
F_103 ( V_6 -> V_118 ) ;
return - V_258 ;
}
V_6 -> V_15 = V_14 -> V_15 = V_15 ;
return 0 ;
}
static void F_107 ( struct V_81 * V_14 , int type )
{
struct V_5 * V_6 ;
V_6 = F_35 ( V_14 , struct V_5 , V_14 ) ;
if ( type & V_259 ) {
V_14 -> type = V_6 -> V_260 ;
F_104 ( V_14 ) ;
}
}
static int F_108 ( struct V_81 * V_14 ,
struct V_261 * V_262 )
{
struct V_5 * V_6 ;
V_6 = F_35 ( V_14 , struct V_5 , V_14 ) ;
if ( V_262 -> V_185 & V_263 ) {
F_67 ( V_6 -> V_14 . V_43 ,
L_40 ) ;
V_6 -> V_192 = 0 ;
V_262 -> V_185 &= ~ V_263 ;
} else {
#ifndef F_109
F_13 ( V_6 -> V_14 . V_43 , L_41 ,
V_50 ) ;
return - V_264 ;
#endif
if ( ! V_6 -> V_192 ) {
F_39 ( V_14 ) ;
if ( V_6 -> V_102 )
V_6 -> V_192 = 1 ;
}
F_67 ( V_6 -> V_14 . V_43 , L_42 ,
V_6 -> V_192 ?
L_43 : L_44 ) ;
}
return 0 ;
}
static void F_110 ( struct V_5 * V_265 , int V_37 )
{
unsigned int V_266 , V_267 = 10000 ;
for (; ; ) {
V_266 = F_3 ( V_265 -> V_15 + V_20 ) ;
if ( ( V_266 & V_37 ) == V_37 )
break;
if ( -- V_267 == 0 )
break;
F_111 ( 1 ) ;
}
if ( V_265 -> V_14 . V_185 & V_268 ) {
unsigned int V_267 ;
for ( V_267 = 1000000 ; V_267 ; V_267 -- ) {
unsigned int V_71 = F_3 ( V_265 -> V_15 + V_21 ) ;
if ( V_71 & V_206 )
break;
F_111 ( 1 ) ;
F_112 () ;
}
}
}
static int F_113 ( struct V_81 * V_14 )
{
struct V_5 * V_6 =
F_35 ( V_14 , struct V_5 , V_14 ) ;
T_6 V_80 = F_3 ( V_6 -> V_15 + V_20 ) ;
if ( ! ( V_80 & V_82 ) )
return V_269 ;
return F_3 ( V_6 -> V_15 + V_84 ) ;
}
static void F_114 ( struct V_81 * V_14 ,
unsigned char V_270 )
{
unsigned int V_33 ;
struct V_5 * V_6 =
F_35 ( V_14 , struct V_5 , V_14 ) ;
V_33 = F_3 ( V_6 -> V_15 + V_16 ) ;
F_10 ( V_6 , V_219 ) ;
F_110 ( V_6 , V_271 ) ;
F_4 ( V_270 , V_6 -> V_15 + V_77 ) ;
if ( V_270 == 10 ) {
F_110 ( V_6 , V_271 ) ;
F_4 ( 13 , V_6 -> V_15 + V_77 ) ;
}
F_110 ( V_6 , V_272 ) ;
F_4 ( V_33 , V_6 -> V_15 + V_16 ) ;
}
static void F_115 ( struct V_81 * V_14 , int V_273 )
{
struct V_5 * V_6 =
F_35 ( V_14 , struct V_5 , V_14 ) ;
F_110 ( V_6 , V_271 ) ;
F_4 ( V_273 , V_6 -> V_15 + V_77 ) ;
}
static void
F_116 ( struct V_274 * V_275 , const char * V_276 , unsigned int V_3 )
{
struct V_5 * V_6 ;
unsigned long V_185 ;
int V_277 = 1 ;
int V_278 = 1 ;
T_6 V_33 ;
V_6 = V_279 [ V_275 -> V_280 ] ;
F_112 () ;
F_117 ( V_185 ) ;
if ( V_6 -> V_14 . V_87 ) {
V_277 = 0 ;
V_278 = 0 ;
} else if ( V_281 ) {
V_277 = F_118 ( & V_6 -> V_187 ) ;
V_278 = F_118 ( & V_6 -> V_14 . V_187 ) ;
} else {
F_96 ( & V_6 -> V_187 ) ;
F_96 ( & V_6 -> V_14 . V_187 ) ;
}
V_33 = F_3 ( V_6 -> V_15 + V_16 ) ;
F_10 ( V_6 , V_219 ) ;
F_119 ( & V_6 -> V_14 , V_276 , V_3 , F_115 ) ;
F_110 ( V_6 , V_272 ) ;
F_4 ( V_33 , V_6 -> V_15 + V_16 ) ;
if ( V_278 )
F_99 ( & V_6 -> V_14 . V_187 ) ;
if ( V_277 )
F_99 ( & V_6 -> V_187 ) ;
F_120 ( V_185 ) ;
}
static int T_10 F_121 ( struct V_274 * V_275 , char * V_282 )
{
struct V_81 * V_14 ;
int V_35 = V_220 ;
int V_37 = 8 ;
int V_36 = 'n' ;
int V_283 = 'n' ;
if ( V_275 -> V_280 >= V_284 )
V_275 -> V_280 = 0 ;
V_14 = & V_279 [ V_275 -> V_280 ] -> V_14 ;
if ( ! V_14 || ( ! V_14 -> V_285 && ! V_14 -> V_15 ) )
return - V_286 ;
V_14 -> V_41 = F_7 () ;
if ( V_282 )
F_122 ( V_282 , & V_35 , & V_36 , & V_37 , & V_283 ) ;
return F_123 ( V_14 , V_275 , V_35 , V_36 , V_37 , V_283 ) ;
}
static struct V_5 * F_124 ( struct V_116 * V_118 ,
const struct V_287 * V_288 )
{
struct V_5 * V_6 ;
int V_10 ;
unsigned int V_285 ;
unsigned int V_123 ;
unsigned char * V_152 ;
int V_104 ;
int V_260 ;
struct V_289 * V_290 ;
#ifdef F_125
char V_291 [ 32 ] ;
#endif
V_290 = & V_292 [ V_288 -> V_30 ] ;
V_260 = V_290 -> V_260 ;
V_6 = F_2 ( sizeof( struct V_5 ) , V_13 ) ;
if ( V_6 == NULL )
goto V_293;
V_152 = ( unsigned char * ) F_126 ( V_13 ) ;
if ( ! V_152 )
goto V_294;
switch ( V_260 ) {
case V_295 :
V_104 = 256 ;
break;
case V_296 :
V_104 = 64 ;
break;
default:
F_13 ( & V_118 -> V_43 , L_45 , V_260 ) ;
goto V_297;
}
F_127 ( V_118 ) ;
F_128 ( V_118 ) ;
F_129 ( & V_6 -> V_187 ) ;
V_285 = F_130 ( V_118 , 0 ) ;
V_123 = F_130 ( V_118 , 1 ) ;
V_6 -> V_123 = V_123 ;
V_6 -> V_285 = V_285 ;
V_6 -> V_118 = V_118 ;
V_6 -> V_163 = 1 ;
V_6 -> V_152 . V_8 = V_152 ;
V_6 -> V_152 . V_93 = V_298 ;
V_6 -> V_60 = V_104 ;
V_6 -> V_41 = F_7 () ;
V_6 -> V_260 = V_299 + V_260 + 1 ;
V_6 -> V_14 . V_43 = & V_118 -> V_43 ;
V_6 -> V_14 . V_285 = V_285 ;
V_6 -> V_14 . V_15 = NULL ;
V_6 -> V_14 . V_123 = V_123 ;
V_6 -> V_14 . V_181 = V_118 -> V_181 ;
V_6 -> V_14 . V_300 = V_301 ;
V_6 -> V_14 . V_302 = & V_303 ;
V_6 -> V_14 . V_185 = V_304 ;
V_6 -> V_14 . V_104 = V_104 ;
V_6 -> V_14 . line = V_290 -> V_305 ;
V_6 -> V_61 = V_230 ;
F_129 ( & V_6 -> V_14 . V_187 ) ;
F_131 ( V_118 , V_6 ) ;
V_6 -> V_65 = 1 ;
V_6 -> V_57 = 0 ;
#ifdef F_132
V_279 [ V_290 -> V_305 ] = V_6 ;
#endif
V_10 = F_133 ( & V_306 , & V_6 -> V_14 ) ;
if ( V_10 < 0 )
goto V_297;
#ifdef F_125
snprintf ( V_291 , sizeof( V_291 ) , L_46 , V_290 -> V_305 ) ;
V_6 -> V_307 = F_134 ( V_291 , V_308 | V_309 ,
NULL , V_6 , & V_310 ) ;
#endif
return V_6 ;
V_297:
#ifdef F_132
V_279 [ V_290 -> V_305 ] = NULL ;
#endif
F_135 ( ( unsigned long ) V_152 ) ;
V_294:
F_6 ( V_6 ) ;
V_293:
return NULL ;
}
static void F_136 ( struct V_5 * V_6 )
{
#ifdef F_125
if ( V_6 -> V_307 )
F_137 ( V_6 -> V_307 ) ;
#endif
F_138 ( & V_306 , & V_6 -> V_14 ) ;
F_135 ( ( unsigned long ) V_6 -> V_152 . V_8 ) ;
}
static void F_139 ( struct V_116 * V_118 )
{
struct V_5 * V_6 = F_140 ( V_118 ) ;
F_141 ( V_118 ) ;
#ifdef F_132
V_279 [ V_6 -> V_14 . line ] = NULL ;
#endif
F_136 ( V_6 ) ;
F_142 ( V_118 ) ;
F_6 ( V_6 ) ;
return;
}
static int F_143 ( struct V_116 * V_118 , T_11 V_96 )
{
struct V_5 * V_6 = F_140 ( V_118 ) ;
F_144 ( & V_306 , & V_6 -> V_14 ) ;
F_145 ( V_118 ) ;
F_146 ( V_118 , F_147 ( V_118 , V_96 ) ) ;
return 0 ;
}
static int F_148 ( struct V_116 * V_118 )
{
struct V_5 * V_6 = F_140 ( V_118 ) ;
int V_10 ;
F_146 ( V_118 , V_311 ) ;
F_149 ( V_118 ) ;
V_10 = F_150 ( V_118 ) ;
if ( V_10 ) {
F_13 ( & V_118 -> V_43 ,
L_47 , V_50 , V_10 ) ;
return V_10 ;
}
F_151 ( & V_306 , & V_6 -> V_14 ) ;
return 0 ;
}
static int F_152 ( struct V_116 * V_118 ,
const struct V_287 * V_288 )
{
int V_10 ;
struct V_5 * V_6 ;
V_10 = F_150 ( V_118 ) ;
if ( V_10 < 0 )
goto V_312;
V_6 = F_124 ( V_118 , V_288 ) ;
if ( ! V_6 ) {
V_10 = - V_258 ;
goto V_313;
}
F_131 ( V_118 , V_6 ) ;
return V_10 ;
V_313:
F_141 ( V_118 ) ;
F_142 ( V_118 ) ;
V_312:
return V_10 ;
}
static int T_10 F_153 ( void )
{
int V_10 ;
V_10 = F_154 ( & V_306 ) ;
if ( V_10 < 0 )
return V_10 ;
V_10 = F_155 ( & V_314 ) ;
if ( V_10 < 0 )
F_156 ( & V_306 ) ;
return V_10 ;
}
static void T_12 F_157 ( void )
{
F_158 ( & V_314 ) ;
F_156 ( & V_306 ) ;
}
