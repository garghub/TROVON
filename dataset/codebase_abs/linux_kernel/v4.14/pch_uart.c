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
V_112 = F_42 ( V_6 -> V_118 -> V_119 ,
F_43 ( F_44 ( V_6 -> V_118 -> V_120 ) , 0 ) ) ;
V_110 = & V_6 -> V_121 ;
V_110 -> V_112 = & V_112 -> V_43 ;
V_110 -> V_111 = V_6 -> V_14 . line * 2 ;
V_110 -> V_122 = V_14 -> V_123 + V_124 ;
V_107 = F_45 ( V_115 , F_38 , V_110 ) ;
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
V_107 = F_45 ( V_115 , F_38 , V_110 ) ;
if ( ! V_107 ) {
F_13 ( V_6 -> V_14 . V_43 , L_24 ,
V_50 ) ;
F_36 ( V_6 -> V_101 ) ;
V_6 -> V_101 = NULL ;
return;
}
V_6 -> V_105 = F_46 ( V_14 -> V_43 , V_14 -> V_104 ,
& V_6 -> V_103 , V_13 ) ;
V_6 -> V_102 = V_107 ;
}
static void F_47 ( void * V_128 )
{
struct V_5 * V_6 = V_128 ;
struct V_81 * V_14 = & V_6 -> V_14 ;
int V_3 ;
F_48 ( V_14 -> V_43 , & V_6 -> V_99 , 1 , V_129 ) ;
V_3 = F_30 ( V_6 , V_6 -> V_65 ) ;
if ( V_3 )
F_28 ( & V_14 -> V_96 -> V_14 ) ;
F_49 ( V_6 -> V_130 ) ;
F_9 ( V_6 , V_131 |
V_132 ) ;
}
static void F_50 ( void * V_128 )
{
struct V_5 * V_6 = V_128 ;
struct V_81 * V_14 = & V_6 -> V_14 ;
struct V_133 * V_134 = & V_14 -> V_96 -> V_134 ;
struct V_135 * V_136 = V_6 -> V_137 ;
int V_75 ;
for ( V_75 = 0 ; V_75 < V_6 -> V_138 ; V_75 ++ , V_136 ++ ) {
V_134 -> V_139 += F_51 ( V_136 ) ;
V_14 -> V_85 . V_140 += F_51 ( V_136 ) ;
}
V_134 -> V_139 &= V_141 - 1 ;
F_49 ( V_6 -> V_142 ) ;
F_52 ( V_14 -> V_43 , V_136 , V_6 -> V_138 , V_143 ) ;
V_6 -> V_144 = 0 ;
V_6 -> V_138 = 0 ;
F_6 ( V_6 -> V_137 ) ;
F_9 ( V_6 , V_145 ) ;
}
static int F_53 ( struct V_5 * V_6 , int V_93 )
{
int V_3 = 0 ;
struct V_81 * V_14 = & V_6 -> V_14 ;
struct V_133 * V_134 = & V_14 -> V_96 -> V_134 ;
if ( F_54 ( V_14 ) || F_55 ( V_134 ) || V_3 >= V_93 )
goto V_146;
do {
int V_147 =
F_56 ( V_134 -> V_148 , V_134 -> V_139 , V_141 ) ;
int V_149 = F_57 ( V_93 - V_3 , V_147 ) ;
F_18 ( V_6 , & V_134 -> V_8 [ V_134 -> V_139 ] , V_149 ) ;
V_134 -> V_139 = ( V_134 -> V_139 + V_149 ) & ( V_141 - 1 ) ;
V_3 += V_149 ;
} while ( ! F_55 ( V_134 ) && V_3 < V_93 );
V_146:
F_14 ( V_6 -> V_14 . V_43 , L_25 ,
V_3 , V_93 - V_3 , V_51 ) ;
return V_3 ;
}
static int F_58 ( struct V_5 * V_6 )
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
static int F_59 ( struct V_5 * V_6 )
{
return F_58 ( V_6 ) ;
}
static int F_60 ( struct V_5 * V_6 )
{
struct V_81 * V_14 = & V_6 -> V_14 ;
struct V_154 * V_155 ;
struct V_135 * V_136 ;
V_6 = F_35 ( V_14 , struct V_5 , V_14 ) ;
V_136 = & V_6 -> V_99 ;
F_61 ( & V_6 -> V_99 , 1 ) ;
F_51 ( V_136 ) = V_6 -> V_65 ;
F_62 ( & V_6 -> V_99 , F_63 ( V_6 -> V_105 ) ,
F_51 ( V_136 ) , F_64 ( V_6 -> V_105 ) ) ;
F_65 ( V_136 ) = V_6 -> V_103 ;
V_155 = F_66 ( V_6 -> V_102 ,
V_136 , 1 , V_156 ,
V_157 | V_158 ) ;
if ( ! V_155 )
return 0 ;
V_6 -> V_130 = V_155 ;
V_155 -> V_159 = F_47 ;
V_155 -> V_160 = V_6 ;
V_155 -> V_161 ( V_155 ) ;
F_67 ( V_6 -> V_102 ) ;
return V_153 ;
}
static unsigned int F_68 ( struct V_5 * V_6 )
{
struct V_81 * V_14 = & V_6 -> V_14 ;
struct V_133 * V_134 = & V_14 -> V_96 -> V_134 ;
int V_60 ;
int V_74 ;
int V_93 ;
int V_162 ;
if ( ! V_6 -> V_163 ) {
F_69 ( V_6 -> V_14 . V_43 , L_26 ,
V_50 , V_51 ) ;
F_10 ( V_6 , V_145 ) ;
V_6 -> V_162 = 1 ;
return 0 ;
}
V_60 = F_70 ( V_6 -> V_60 , 1 ) ;
V_162 = 1 ;
if ( F_29 ( V_6 , V_134 -> V_8 ) ) {
F_18 ( V_6 , V_134 -> V_8 , 1 ) ;
V_14 -> V_85 . V_140 ++ ;
V_162 = 0 ;
V_60 -- ;
}
V_93 = F_57 ( V_134 -> V_148 - V_134 -> V_139 , V_60 ) ;
if ( V_93 < 0 )
V_93 = V_60 ;
V_74 = F_53 ( V_6 , V_93 ) ;
if ( V_74 > 0 ) {
V_14 -> V_85 . V_140 += V_74 ;
V_162 = 0 ;
}
V_6 -> V_162 = V_162 ;
if ( V_162 ) {
F_10 ( V_6 , V_145 ) ;
F_71 ( V_14 ) ;
}
return V_164 ;
}
static unsigned int F_72 ( struct V_5 * V_6 )
{
struct V_81 * V_14 = & V_6 -> V_14 ;
struct V_133 * V_134 = & V_14 -> V_96 -> V_134 ;
struct V_135 * V_136 ;
int V_138 ;
int V_60 ;
int V_162 ;
struct V_154 * V_155 ;
int V_165 ;
int V_75 ;
int V_166 ;
int V_93 ;
int V_167 ;
if ( ! V_6 -> V_163 ) {
F_69 ( V_6 -> V_14 . V_43 , L_26 ,
V_50 , V_51 ) ;
F_10 ( V_6 , V_145 ) ;
V_6 -> V_162 = 1 ;
return 0 ;
}
if ( V_6 -> V_144 ) {
F_14 ( V_6 -> V_14 . V_43 , L_27 ,
V_50 , V_51 ) ;
F_10 ( V_6 , V_145 ) ;
V_6 -> V_162 = 1 ;
return 0 ;
}
V_60 = F_70 ( V_6 -> V_60 , 1 ) ;
V_162 = 1 ;
if ( F_29 ( V_6 , V_134 -> V_8 ) ) {
F_18 ( V_6 , V_134 -> V_8 , 1 ) ;
V_14 -> V_85 . V_140 ++ ;
V_162 = 0 ;
V_60 -- ;
}
V_166 = F_57 ( ( int ) F_73 ( V_134 -> V_148 , V_134 -> V_139 ,
V_141 ) , F_56 ( V_134 -> V_148 ,
V_134 -> V_139 , V_141 ) ) ;
if ( ! V_166 ) {
F_14 ( V_6 -> V_14 . V_43 , L_28 , V_50 ) ;
F_10 ( V_6 , V_145 ) ;
F_71 ( V_14 ) ;
return 0 ;
}
if ( V_166 > V_60 ) {
V_165 = V_166 / V_60 + 1 ;
V_93 = V_60 ;
V_167 = V_166 % V_60 ;
} else {
V_165 = 1 ;
V_93 = V_166 ;
V_167 = V_166 ;
}
F_14 ( V_6 -> V_14 . V_43 , L_29 ,
V_50 , V_165 , V_93 , V_167 ) ;
V_6 -> V_144 = 1 ;
V_6 -> V_137 = F_2 ( sizeof( struct V_135 ) * V_165 , V_168 ) ;
if ( ! V_6 -> V_137 ) {
F_13 ( V_6 -> V_14 . V_43 , L_30 , V_50 ) ;
return 0 ;
}
F_61 ( V_6 -> V_137 , V_165 ) ;
V_136 = V_6 -> V_137 ;
for ( V_75 = 0 ; V_75 < V_165 ; V_75 ++ , V_136 ++ ) {
if ( V_75 == ( V_165 - 1 ) )
F_62 ( V_136 , F_63 ( V_134 -> V_8 ) ,
V_167 , V_60 * V_75 ) ;
else
F_62 ( V_136 , F_63 ( V_134 -> V_8 ) ,
V_93 , V_60 * V_75 ) ;
}
V_136 = V_6 -> V_137 ;
V_138 = F_74 ( V_14 -> V_43 , V_136 , V_165 , V_143 ) ;
if ( ! V_138 ) {
F_13 ( V_6 -> V_14 . V_43 , L_31 , V_50 ) ;
return 0 ;
}
V_6 -> V_138 = V_138 ;
for ( V_75 = 0 ; V_75 < V_138 ; V_75 ++ , V_136 ++ ) {
V_136 -> V_169 = ( V_134 -> V_139 & ( V_141 - 1 ) ) +
V_60 * V_75 ;
F_65 ( V_136 ) = ( F_65 ( V_136 ) &
~ ( V_141 - 1 ) ) + V_136 -> V_169 ;
if ( V_75 == ( V_138 - 1 ) )
F_51 ( V_136 ) = V_167 ;
else
F_51 ( V_136 ) = V_93 ;
}
V_155 = F_66 ( V_6 -> V_101 ,
V_6 -> V_137 , V_138 , V_170 ,
V_157 | V_158 ) ;
if ( ! V_155 ) {
F_13 ( V_6 -> V_14 . V_43 , L_32 ,
V_50 ) ;
return 0 ;
}
F_75 ( V_14 -> V_43 , V_6 -> V_137 , V_138 , V_143 ) ;
V_6 -> V_142 = V_155 ;
V_155 -> V_159 = F_50 ;
V_155 -> V_160 = V_6 ;
V_155 -> V_161 ( V_155 ) ;
F_67 ( V_6 -> V_101 ) ;
return V_164 ;
}
static void F_76 ( struct V_5 * V_6 , unsigned int V_80 )
{
struct V_81 * V_14 = & V_6 -> V_14 ;
struct V_171 * V_172 = F_77 ( & V_14 -> V_96 -> V_14 ) ;
char * V_173 [ 5 ] = {} ;
int V_75 = 0 ;
if ( V_80 & V_174 )
V_173 [ V_75 ++ ] = L_33 ;
if ( V_80 & V_175 ) {
V_14 -> V_85 . V_176 ++ ;
V_173 [ V_75 ++ ] = L_34 ;
}
if ( V_80 & V_177 ) {
V_14 -> V_85 . V_36 ++ ;
V_173 [ V_75 ++ ] = L_35 ;
}
if ( V_80 & V_178 ) {
V_14 -> V_85 . V_179 ++ ;
V_173 [ V_75 ++ ] = L_36 ;
}
if ( V_172 == NULL ) {
for ( V_75 = 0 ; V_173 [ V_75 ] != NULL ; V_75 ++ )
F_13 ( & V_6 -> V_118 -> V_43 , V_173 [ V_75 ] ) ;
} else {
F_78 ( V_172 ) ;
}
}
static T_8 F_79 ( int V_180 , void * V_181 )
{
struct V_5 * V_6 = V_181 ;
unsigned int V_182 ;
T_6 V_80 ;
int V_10 = 0 ;
unsigned char V_183 ;
unsigned long V_184 ;
int V_185 = 1 ;
T_6 V_71 ;
F_80 ( & V_6 -> V_186 , V_184 ) ;
V_182 = 0 ;
while ( V_185 ) {
V_183 = F_23 ( V_6 ) ;
if ( V_183 & V_90 )
break;
switch ( V_183 ) {
case V_187 :
V_80 = F_24 ( V_6 ) ;
if ( V_80 & ( V_174 | V_175 |
V_177 | V_178 ) ) {
F_76 ( V_6 , V_80 ) ;
V_10 = V_188 ;
} else {
V_10 = V_189 ;
}
break;
case V_190 :
if ( V_6 -> V_191 ) {
F_10 ( V_6 ,
V_131 |
V_132 ) ;
V_10 = F_60 ( V_6 ) ;
if ( ! V_10 )
F_9 ( V_6 ,
V_131 |
V_132 ) ;
} else {
V_10 = F_59 ( V_6 ) ;
}
break;
case V_192 :
V_10 = F_58 ( V_6 ) ;
break;
case V_193 :
if ( V_6 -> V_191 )
V_10 = F_72 ( V_6 ) ;
else
V_10 = F_68 ( V_6 ) ;
break;
case V_194 :
V_71 = F_17 ( V_6 ) ;
V_185 = 0 ;
if ( ( V_71 & V_195 ) == 0 )
break;
V_10 |= V_196 ;
break;
default:
F_13 ( V_6 -> V_14 . V_43 , L_37 , V_50 ,
V_183 , V_51 ) ;
V_10 = - 1 ;
V_185 = 0 ;
break;
}
V_182 |= ( unsigned int ) V_10 ;
}
F_81 ( & V_6 -> V_186 , V_184 ) ;
return F_82 ( V_182 ) ;
}
static unsigned int F_83 ( struct V_81 * V_14 )
{
struct V_5 * V_6 ;
V_6 = F_35 ( V_14 , struct V_5 , V_14 ) ;
if ( V_6 -> V_162 )
return V_197 ;
else
return 0 ;
}
static unsigned int F_84 ( struct V_81 * V_14 )
{
struct V_5 * V_6 ;
T_6 V_198 ;
unsigned int V_10 = 0 ;
V_6 = F_35 ( V_14 , struct V_5 , V_14 ) ;
V_198 = F_17 ( V_6 ) ;
if ( V_198 & V_199 )
V_10 |= V_200 ;
if ( V_198 & V_201 )
V_10 |= V_202 ;
if ( V_198 & V_203 )
V_10 |= V_204 ;
if ( V_198 & V_205 )
V_10 |= V_206 ;
return V_10 ;
}
static void F_85 ( struct V_81 * V_14 , unsigned int V_207 )
{
T_5 V_208 = 0 ;
struct V_5 * V_6 = F_35 ( V_14 , struct V_5 , V_14 ) ;
if ( V_207 & V_209 )
V_208 |= V_210 ;
if ( V_207 & V_211 )
V_208 |= V_212 ;
if ( V_207 & V_213 )
V_208 |= V_214 ;
if ( V_6 -> V_208 & V_215 )
V_208 |= V_215 ;
if ( V_207 )
F_4 ( V_208 , V_6 -> V_15 + V_19 ) ;
}
static void F_86 ( struct V_81 * V_14 )
{
struct V_5 * V_6 ;
V_6 = F_35 ( V_14 , struct V_5 , V_14 ) ;
V_6 -> V_163 = 0 ;
V_6 -> V_144 = 0 ;
}
static void F_87 ( struct V_81 * V_14 )
{
struct V_5 * V_6 ;
V_6 = F_35 ( V_14 , struct V_5 , V_14 ) ;
if ( V_6 -> V_191 ) {
if ( V_6 -> V_144 ) {
F_14 ( V_6 -> V_14 . V_43 , L_38 ,
V_50 ) ;
return;
}
}
V_6 -> V_163 = 1 ;
F_9 ( V_6 , V_145 ) ;
}
static void F_88 ( struct V_81 * V_14 )
{
struct V_5 * V_6 ;
V_6 = F_35 ( V_14 , struct V_5 , V_14 ) ;
V_6 -> V_151 = 0 ;
F_10 ( V_6 , V_131 |
V_132 ) ;
}
static void F_89 ( struct V_81 * V_14 )
{
struct V_5 * V_6 ;
V_6 = F_35 ( V_14 , struct V_5 , V_14 ) ;
F_9 ( V_6 , V_216 ) ;
}
static void F_90 ( struct V_81 * V_14 , int V_217 )
{
struct V_5 * V_6 ;
unsigned long V_184 ;
V_6 = F_35 ( V_14 , struct V_5 , V_14 ) ;
F_80 ( & V_6 -> V_186 , V_184 ) ;
F_25 ( V_6 , V_217 ) ;
F_81 ( & V_6 -> V_186 , V_184 ) ;
}
static int F_91 ( struct V_81 * V_14 )
{
struct V_5 * V_6 ;
int V_10 ;
int V_60 ;
int V_65 ;
V_6 = F_35 ( V_14 , struct V_5 , V_14 ) ;
V_6 -> V_162 = 1 ;
if ( V_14 -> V_41 )
V_6 -> V_41 = V_14 -> V_41 ;
else
V_14 -> V_41 = V_6 -> V_41 ;
F_10 ( V_6 , V_218 ) ;
V_10 = F_11 ( V_6 , V_219 ,
V_220 , V_221 ,
V_222 ) ;
if ( V_10 )
return V_10 ;
switch ( V_6 -> V_60 ) {
case 256 :
V_60 = V_223 ;
break;
case 64 :
V_60 = V_224 ;
break;
case 16 :
V_60 = V_225 ;
break;
case 1 :
default:
V_60 = V_226 ;
break;
}
switch ( V_6 -> V_61 ) {
case V_227 :
V_65 = 1 ;
break;
case V_228 :
V_65 = V_6 -> V_60 / 4 ;
break;
case V_229 :
V_65 = V_6 -> V_60 / 2 ;
break;
case V_230 :
default:
V_65 = V_6 -> V_60 - ( V_6 -> V_60 / 8 ) ;
break;
}
V_6 -> V_65 = V_65 ;
V_10 = F_16 ( V_6 , V_231 ,
V_60 , V_6 -> V_61 ) ;
if ( V_10 < 0 )
return V_10 ;
V_10 = F_92 ( V_6 -> V_14 . V_180 , F_79 , V_232 ,
V_6 -> V_233 , V_6 ) ;
if ( V_10 < 0 )
return V_10 ;
if ( V_6 -> V_191 )
F_39 ( V_14 ) ;
V_6 -> V_151 = 1 ;
F_9 ( V_6 , V_131 |
V_132 ) ;
F_93 ( V_14 , V_234 , V_219 ) ;
return 0 ;
}
static void F_94 ( struct V_81 * V_14 )
{
struct V_5 * V_6 ;
int V_10 ;
V_6 = F_35 ( V_14 , struct V_5 , V_14 ) ;
F_10 ( V_6 , V_218 ) ;
F_15 ( V_6 , V_235 ) ;
V_10 = F_16 ( V_6 , V_231 ,
V_226 , V_227 ) ;
if ( V_10 )
F_13 ( V_6 -> V_14 . V_43 ,
L_39 , V_10 ) ;
F_34 ( V_14 ) ;
F_95 ( V_6 -> V_14 . V_180 , V_6 ) ;
}
static void F_96 ( struct V_81 * V_14 ,
struct V_236 * V_237 , struct V_236 * V_238 )
{
int V_239 ;
unsigned int V_35 , V_36 , V_37 , V_38 ;
struct V_5 * V_6 ;
unsigned long V_184 ;
V_6 = F_35 ( V_14 , struct V_5 , V_14 ) ;
switch ( V_237 -> V_240 & V_241 ) {
case V_242 :
V_37 = V_243 ;
break;
case V_244 :
V_37 = V_245 ;
break;
case V_246 :
V_37 = V_247 ;
break;
default:
V_37 = V_221 ;
break;
}
if ( V_237 -> V_240 & V_248 )
V_38 = V_249 ;
else
V_38 = V_222 ;
if ( V_237 -> V_240 & V_250 ) {
if ( V_237 -> V_240 & V_251 )
V_36 = V_252 ;
else
V_36 = V_253 ;
} else
V_36 = V_220 ;
if ( ( V_237 -> V_240 & V_254 ) && ( V_6 -> V_60 == 256 ) )
V_6 -> V_208 |= V_215 ;
else
V_6 -> V_208 &= ~ V_215 ;
V_237 -> V_240 &= ~ V_255 ;
V_35 = F_97 ( V_14 , V_237 , V_238 , 0 , V_14 -> V_41 / 16 ) ;
F_80 ( & V_6 -> V_186 , V_184 ) ;
F_98 ( & V_14 -> V_186 ) ;
F_93 ( V_14 , V_237 -> V_240 , V_35 ) ;
V_239 = F_11 ( V_6 , V_35 , V_36 , V_37 , V_38 ) ;
if ( V_239 )
goto V_256;
F_85 ( & V_6 -> V_14 , V_6 -> V_14 . V_207 ) ;
if ( F_99 ( V_237 ) )
F_100 ( V_237 , V_35 , V_35 ) ;
V_256:
F_101 ( & V_14 -> V_186 ) ;
F_81 ( & V_6 -> V_186 , V_184 ) ;
}
static const char * F_102 ( struct V_81 * V_14 )
{
return V_257 ;
}
static void F_103 ( struct V_81 * V_14 )
{
struct V_5 * V_6 ;
V_6 = F_35 ( V_14 , struct V_5 , V_14 ) ;
F_104 ( V_6 -> V_118 , V_6 -> V_15 ) ;
F_105 ( V_6 -> V_118 ) ;
}
static int F_106 ( struct V_81 * V_14 )
{
struct V_5 * V_6 ;
int V_10 ;
void T_9 * V_15 ;
V_6 = F_35 ( V_14 , struct V_5 , V_14 ) ;
V_10 = F_107 ( V_6 -> V_118 , V_257 ) ;
if ( V_10 < 0 )
return - V_258 ;
V_15 = F_108 ( V_6 -> V_118 , 1 , 0 ) ;
if ( ! V_15 ) {
F_105 ( V_6 -> V_118 ) ;
return - V_258 ;
}
V_6 -> V_15 = V_14 -> V_15 = V_15 ;
return 0 ;
}
static void F_109 ( struct V_81 * V_14 , int type )
{
struct V_5 * V_6 ;
V_6 = F_35 ( V_14 , struct V_5 , V_14 ) ;
if ( type & V_259 ) {
V_14 -> type = V_6 -> V_260 ;
F_106 ( V_14 ) ;
}
}
static int F_110 ( struct V_81 * V_14 ,
struct V_261 * V_262 )
{
struct V_5 * V_6 ;
V_6 = F_35 ( V_14 , struct V_5 , V_14 ) ;
if ( V_262 -> V_184 & V_263 ) {
F_69 ( V_6 -> V_14 . V_43 ,
L_40 ) ;
V_6 -> V_191 = 0 ;
V_262 -> V_184 &= ~ V_263 ;
} else {
#ifndef F_111
F_13 ( V_6 -> V_14 . V_43 , L_41 ,
V_50 ) ;
return - V_264 ;
#endif
if ( ! V_6 -> V_191 ) {
F_39 ( V_14 ) ;
if ( V_6 -> V_102 )
V_6 -> V_191 = 1 ;
}
F_69 ( V_6 -> V_14 . V_43 , L_42 ,
V_6 -> V_191 ?
L_43 : L_44 ) ;
}
return 0 ;
}
static void F_112 ( struct V_5 * V_265 , int V_37 )
{
unsigned int V_266 , V_267 = 10000 ;
for (; ; ) {
V_266 = F_3 ( V_265 -> V_15 + V_20 ) ;
if ( ( V_266 & V_37 ) == V_37 )
break;
if ( -- V_267 == 0 )
break;
F_113 ( 1 ) ;
}
if ( V_265 -> V_14 . V_184 & V_268 ) {
unsigned int V_267 ;
for ( V_267 = 1000000 ; V_267 ; V_267 -- ) {
unsigned int V_71 = F_3 ( V_265 -> V_15 + V_21 ) ;
if ( V_71 & V_205 )
break;
F_113 ( 1 ) ;
F_114 () ;
}
}
}
static int F_115 ( struct V_81 * V_14 )
{
struct V_5 * V_6 =
F_35 ( V_14 , struct V_5 , V_14 ) ;
T_6 V_80 = F_3 ( V_6 -> V_15 + V_20 ) ;
if ( ! ( V_80 & V_82 ) )
return V_269 ;
return F_3 ( V_6 -> V_15 + V_84 ) ;
}
static void F_116 ( struct V_81 * V_14 ,
unsigned char V_270 )
{
unsigned int V_33 ;
struct V_5 * V_6 =
F_35 ( V_14 , struct V_5 , V_14 ) ;
V_33 = F_3 ( V_6 -> V_15 + V_16 ) ;
F_10 ( V_6 , V_218 ) ;
F_112 ( V_6 , V_271 ) ;
F_4 ( V_270 , V_6 -> V_15 + V_77 ) ;
F_112 ( V_6 , V_272 ) ;
F_4 ( V_33 , V_6 -> V_15 + V_16 ) ;
}
static void F_117 ( struct V_81 * V_14 , int V_273 )
{
struct V_5 * V_6 =
F_35 ( V_14 , struct V_5 , V_14 ) ;
F_112 ( V_6 , V_271 ) ;
F_4 ( V_273 , V_6 -> V_15 + V_77 ) ;
}
static void
F_118 ( struct V_274 * V_275 , const char * V_276 , unsigned int V_3 )
{
struct V_5 * V_6 ;
unsigned long V_184 ;
int V_277 = 1 ;
int V_278 = 1 ;
T_6 V_33 ;
V_6 = V_279 [ V_275 -> V_280 ] ;
F_114 () ;
F_119 ( V_184 ) ;
if ( V_6 -> V_14 . V_87 ) {
V_277 = 0 ;
V_278 = 0 ;
} else if ( V_281 ) {
V_277 = F_120 ( & V_6 -> V_186 ) ;
V_278 = F_120 ( & V_6 -> V_14 . V_186 ) ;
} else {
F_98 ( & V_6 -> V_186 ) ;
F_98 ( & V_6 -> V_14 . V_186 ) ;
}
V_33 = F_3 ( V_6 -> V_15 + V_16 ) ;
F_10 ( V_6 , V_218 ) ;
F_121 ( & V_6 -> V_14 , V_276 , V_3 , F_117 ) ;
F_112 ( V_6 , V_272 ) ;
F_4 ( V_33 , V_6 -> V_15 + V_16 ) ;
if ( V_278 )
F_101 ( & V_6 -> V_14 . V_186 ) ;
if ( V_277 )
F_101 ( & V_6 -> V_186 ) ;
F_122 ( V_184 ) ;
}
static int T_10 F_123 ( struct V_274 * V_275 , char * V_282 )
{
struct V_81 * V_14 ;
int V_35 = V_219 ;
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
F_124 ( V_282 , & V_35 , & V_36 , & V_37 , & V_283 ) ;
return F_125 ( V_14 , V_275 , V_35 , V_36 , V_37 , V_283 ) ;
}
static struct V_5 * F_126 ( struct V_116 * V_118 ,
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
#ifdef F_127
char V_291 [ 32 ] ;
#endif
V_290 = & V_292 [ V_288 -> V_30 ] ;
V_260 = V_290 -> V_260 ;
V_6 = F_2 ( sizeof( struct V_5 ) , V_13 ) ;
if ( V_6 == NULL )
goto V_293;
V_152 = ( unsigned char * ) F_128 ( V_13 ) ;
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
F_129 ( V_118 ) ;
F_130 ( V_118 ) ;
F_131 ( & V_6 -> V_186 ) ;
V_285 = F_132 ( V_118 , 0 ) ;
V_123 = F_132 ( V_118 , 1 ) ;
V_6 -> V_123 = V_123 ;
V_6 -> V_285 = V_285 ;
V_6 -> V_118 = V_118 ;
V_6 -> V_162 = 1 ;
V_6 -> V_152 . V_8 = V_152 ;
V_6 -> V_152 . V_93 = V_298 ;
V_6 -> V_60 = V_104 ;
V_6 -> V_41 = F_7 () ;
V_6 -> V_260 = V_260 ;
V_6 -> V_14 . V_43 = & V_118 -> V_43 ;
V_6 -> V_14 . V_285 = V_285 ;
V_6 -> V_14 . V_15 = NULL ;
V_6 -> V_14 . V_123 = V_123 ;
V_6 -> V_14 . V_180 = V_118 -> V_180 ;
V_6 -> V_14 . V_299 = V_300 ;
V_6 -> V_14 . V_301 = & V_302 ;
V_6 -> V_14 . V_184 = V_303 ;
V_6 -> V_14 . V_104 = V_104 ;
V_6 -> V_14 . line = V_290 -> V_304 ;
V_6 -> V_61 = V_229 ;
snprintf ( V_6 -> V_233 , V_305 ,
V_257 L_46 V_306 L_47 ,
V_6 -> V_14 . line ) ;
F_131 ( & V_6 -> V_14 . V_186 ) ;
F_133 ( V_118 , V_6 ) ;
V_6 -> V_65 = 1 ;
V_6 -> V_57 = 0 ;
if ( V_118 -> V_43 . V_307 )
F_134 ( V_118 -> V_43 . V_307 , L_48
, & V_28 ) ;
#ifdef F_135
V_279 [ V_290 -> V_304 ] = V_6 ;
#endif
V_10 = F_136 ( & V_308 , & V_6 -> V_14 ) ;
if ( V_10 < 0 )
goto V_297;
#ifdef F_127
snprintf ( V_291 , sizeof( V_291 ) , L_49 , V_290 -> V_304 ) ;
V_6 -> V_309 = F_137 ( V_291 , V_310 | V_311 ,
NULL , V_6 , & V_312 ) ;
#endif
return V_6 ;
V_297:
#ifdef F_135
V_279 [ V_290 -> V_304 ] = NULL ;
#endif
F_138 ( ( unsigned long ) V_152 ) ;
V_294:
F_6 ( V_6 ) ;
V_293:
return NULL ;
}
static void F_139 ( struct V_5 * V_6 )
{
#ifdef F_127
F_140 ( V_6 -> V_309 ) ;
#endif
F_141 ( & V_308 , & V_6 -> V_14 ) ;
F_138 ( ( unsigned long ) V_6 -> V_152 . V_8 ) ;
}
static void F_142 ( struct V_116 * V_118 )
{
struct V_5 * V_6 = F_143 ( V_118 ) ;
F_144 ( V_118 ) ;
#ifdef F_135
V_279 [ V_6 -> V_14 . line ] = NULL ;
#endif
F_139 ( V_6 ) ;
F_145 ( V_118 ) ;
F_6 ( V_6 ) ;
return;
}
static int F_146 ( struct V_116 * V_118 , T_11 V_96 )
{
struct V_5 * V_6 = F_143 ( V_118 ) ;
F_147 ( & V_308 , & V_6 -> V_14 ) ;
F_148 ( V_118 ) ;
F_149 ( V_118 , F_150 ( V_118 , V_96 ) ) ;
return 0 ;
}
static int F_151 ( struct V_116 * V_118 )
{
struct V_5 * V_6 = F_143 ( V_118 ) ;
int V_10 ;
F_149 ( V_118 , V_313 ) ;
F_152 ( V_118 ) ;
V_10 = F_153 ( V_118 ) ;
if ( V_10 ) {
F_13 ( & V_118 -> V_43 ,
L_50 , V_50 , V_10 ) ;
return V_10 ;
}
F_154 ( & V_308 , & V_6 -> V_14 ) ;
return 0 ;
}
static int F_155 ( struct V_116 * V_118 ,
const struct V_287 * V_288 )
{
int V_10 ;
struct V_5 * V_6 ;
V_10 = F_153 ( V_118 ) ;
if ( V_10 < 0 )
goto V_314;
V_6 = F_126 ( V_118 , V_288 ) ;
if ( ! V_6 ) {
V_10 = - V_258 ;
goto V_315;
}
F_133 ( V_118 , V_6 ) ;
return V_10 ;
V_315:
F_144 ( V_118 ) ;
F_145 ( V_118 ) ;
V_314:
return V_10 ;
}
static int T_10 F_156 ( void )
{
int V_10 ;
V_10 = F_157 ( & V_308 ) ;
if ( V_10 < 0 )
return V_10 ;
V_10 = F_158 ( & V_316 ) ;
if ( V_10 < 0 )
F_159 ( & V_308 ) ;
return V_10 ;
}
static void T_12 F_160 ( void )
{
F_161 ( & V_316 ) ;
F_159 ( & V_308 ) ;
}
