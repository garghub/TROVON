static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned int V_5 = 1 << F_3 ( V_4 -> V_6 ) ;
unsigned long V_7 , V_8 , V_9 ;
int V_10 ;
T_1 V_11 ;
V_11 = F_4 ( V_4 -> V_12 ) ;
V_8 = ( V_11 & V_4 -> V_6 ) >> F_5 ( V_4 -> V_6 ) ;
V_10 = V_8 * 360 / V_5 ;
if ( V_4 -> V_13 ) {
V_7 = F_6 ( ( unsigned long ) V_14 * 1000 ,
F_7 ( V_2 -> V_15 ) ) ;
V_9 = ( V_11 & V_4 -> V_13 ) >> F_5 ( V_4 -> V_13 ) ;
V_10 += V_9 * V_4 -> V_16 * 360 / V_7 ;
V_10 %= 360 ;
}
return V_10 ;
}
static void F_8 ( struct V_3 * V_4 ,
unsigned int V_17 ,
unsigned int V_18 )
{
T_1 V_11 ;
V_11 = F_4 ( V_4 -> V_12 ) ;
V_11 &= ~ V_4 -> V_6 ;
V_11 |= V_17 << F_5 ( V_4 -> V_6 ) ;
if ( V_4 -> V_13 ) {
V_11 &= ~ V_4 -> V_13 ;
V_11 |= V_18 << F_5 ( V_4 -> V_13 ) ;
}
F_9 ( V_11 , V_4 -> V_12 ) ;
}
static int F_10 ( struct V_1 * V_2 , int V_10 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned int V_5 = 1 << F_3 ( V_4 -> V_6 ) ;
unsigned long V_7 , V_9 = 0 , V_19 ;
T_2 V_8 ;
V_8 = V_10 % 360 ;
if ( ! V_4 -> V_13 ) {
V_8 = F_11 ( V_8 , 360 / V_5 ) ;
} else {
V_7 = F_6 ( ( unsigned long ) V_14 * 1000 ,
F_7 ( V_2 -> V_15 ) ) ;
V_19 = F_12 ( V_8 , 360 / V_5 ) ;
V_9 = F_13 ( V_19 * V_7 ,
360 * V_4 -> V_16 ) ;
V_9 = F_14 ( V_9 , V_4 -> V_13 >> F_5 ( V_4 -> V_13 ) ) ;
}
F_8 ( V_4 , V_8 , V_9 ) ;
return 0 ;
}
static unsigned int F_15 ( struct V_20 * V_21 )
{
unsigned int V_22 = V_21 -> V_23 / V_24 ;
if ( ! V_22 )
return V_25 ;
V_22 = F_16 ( V_22 ) ;
return F_14 ( V_22 , 32768U ) ;
}
static struct V_26 * F_17 ( struct V_26 * V_27 )
{
if ( V_27 -> V_28 == V_29 && ! V_27 -> error )
return V_27 -> V_30 -> V_27 ;
else if ( F_18 ( V_27 -> V_28 ) &&
( ! V_27 -> V_30 -> V_31 || V_27 -> error || V_27 -> V_21 -> error ) )
return V_27 -> V_30 -> V_32 ;
else
return NULL ;
}
static void F_19 ( struct V_33 * V_4 ,
struct V_34 * V_30 )
{
struct V_20 * V_21 = V_30 -> V_21 ;
struct V_35 * V_36 ;
int V_37 ;
bool V_38 = true ;
if ( V_30 -> V_27 -> V_28 == V_39 )
return;
F_20 (data->sg, sg, data->sg_len, i)
if ( V_36 -> V_40 & 7 ) {
F_21 ( 1 , L_1 ) ;
V_38 = false ;
break;
}
if ( V_38 )
V_21 -> V_41 |= V_42 ;
}
static inline bool F_22 ( const struct V_20 * V_21 )
{
return V_21 -> V_41 & V_42 ;
}
static inline bool F_23 ( const struct V_20 * V_21 )
{
return V_21 && V_21 -> V_43 & V_44 &&
! F_22 ( V_21 ) ;
}
static void F_24 ( struct V_33 * V_4 , struct V_34 * V_30 )
{
struct V_20 * V_21 = V_30 -> V_21 ;
if ( ! V_21 )
return;
F_19 ( V_4 , V_30 ) ;
V_21 -> V_41 |= V_45 ;
if ( ! F_22 ( V_21 ) )
return;
V_21 -> V_46 = F_25 ( F_26 ( V_4 ) , V_21 -> V_36 , V_21 -> V_47 ,
F_27 ( V_21 ) ) ;
if ( ! V_21 -> V_46 )
F_28 ( F_26 ( V_4 ) , L_2 ) ;
}
static void F_29 ( struct V_33 * V_4 , struct V_34 * V_30 ,
int V_48 )
{
struct V_20 * V_21 = V_30 -> V_21 ;
if ( V_21 && F_22 ( V_21 ) && V_21 -> V_46 )
F_30 ( F_26 ( V_4 ) , V_21 -> V_36 , V_21 -> V_47 ,
F_27 ( V_21 ) ) ;
}
static bool F_31 ( struct V_49 * V_50 )
{
if ( V_50 -> V_51 == V_52 ||
V_50 -> V_51 == V_53 ||
V_50 -> V_51 == V_54 )
return true ;
return false ;
}
static void F_32 ( struct V_55 * V_56 )
{
T_1 V_57 ;
if ( V_56 -> V_58 ) {
F_33 ( V_56 -> V_59 , V_56 -> V_58 ) ;
} else {
V_57 = F_4 ( V_56 -> V_60 + V_61 ) ;
V_57 |= V_62 ;
F_9 ( V_57 , V_56 -> V_60 + V_61 ) ;
}
}
static void F_34 ( struct V_55 * V_56 )
{
T_1 V_57 ;
if ( V_56 -> V_58 )
F_33 ( V_56 -> V_59 , V_56 -> V_63 ) ;
V_57 = F_4 ( V_56 -> V_60 + V_61 ) ;
V_57 &= ~ V_62 ;
F_9 ( V_57 , V_56 -> V_60 + V_61 ) ;
}
static int F_35 ( struct V_55 * V_56 , struct V_49 * V_50 )
{
struct V_33 * V_4 = V_56 -> V_4 ;
unsigned long V_64 = V_50 -> clock ;
int V_65 ;
T_1 V_57 ;
if ( F_31 ( V_50 ) )
V_64 <<= 1 ;
if ( V_56 -> V_66 == V_64 )
return 0 ;
F_32 ( V_56 ) ;
V_56 -> V_66 = 0 ;
if ( ! V_64 ) {
V_4 -> V_67 = 0 ;
return 0 ;
}
V_57 = F_4 ( V_56 -> V_60 + V_61 ) ;
V_57 |= V_62 ;
F_9 ( V_57 , V_56 -> V_60 + V_61 ) ;
V_65 = F_36 ( V_56 -> V_68 , V_64 ) ;
if ( V_65 ) {
F_28 ( V_56 -> V_69 , L_3 ,
V_64 , V_65 ) ;
return V_65 ;
}
V_56 -> V_66 = V_64 ;
V_4 -> V_67 = F_7 ( V_56 -> V_68 ) ;
if ( F_31 ( V_50 ) )
V_4 -> V_67 >>= 1 ;
F_37 ( V_56 -> V_69 , L_4 , V_4 -> V_67 ) ;
if ( V_50 -> clock != V_4 -> V_67 )
F_37 ( V_56 -> V_69 , L_5 , V_50 -> clock ) ;
F_34 ( V_56 ) ;
return 0 ;
}
static int F_38 ( struct V_55 * V_56 )
{
struct V_70 V_71 ;
struct V_72 * V_73 ;
struct V_74 * div ;
struct V_3 * V_75 , * V_76 , * V_77 ;
struct V_15 * V_15 ;
char V_78 [ 32 ] ;
int V_37 , V_65 = 0 ;
const char * V_79 [ V_80 ] ;
const char * V_81 [ 1 ] ;
T_1 V_82 ;
V_82 = 0 ;
V_82 |= V_83 ;
V_82 |= V_84 ;
F_9 ( V_82 , V_56 -> V_60 + V_85 ) ;
for ( V_37 = 0 ; V_37 < V_80 ; V_37 ++ ) {
struct V_15 * V_15 ;
char V_86 [ 16 ] ;
snprintf ( V_86 , sizeof( V_86 ) , L_6 , V_37 ) ;
V_15 = F_39 ( V_56 -> V_69 , V_86 ) ;
if ( F_40 ( V_15 ) ) {
if ( V_15 != F_41 ( - V_87 ) )
F_28 ( V_56 -> V_69 , L_7 , V_86 ) ;
return F_42 ( V_15 ) ;
}
V_79 [ V_37 ] = F_43 ( V_15 ) ;
}
V_73 = F_44 ( V_56 -> V_69 , sizeof( * V_73 ) , V_88 ) ;
if ( ! V_73 )
return - V_89 ;
snprintf ( V_78 , sizeof( V_78 ) , L_8 , F_45 ( V_56 -> V_69 ) ) ;
V_71 . V_86 = V_78 ;
V_71 . V_90 = & V_91 ;
V_71 . V_43 = 0 ;
V_71 . V_92 = V_79 ;
V_71 . V_93 = V_80 ;
V_73 -> V_12 = V_56 -> V_60 + V_85 ;
V_73 -> V_94 = F_5 ( V_95 ) ;
V_73 -> V_96 = V_95 >> V_73 -> V_94 ;
V_73 -> V_2 . V_71 = & V_71 ;
V_15 = F_46 ( V_56 -> V_69 , & V_73 -> V_2 ) ;
if ( F_47 ( F_40 ( V_15 ) ) )
return F_42 ( V_15 ) ;
div = F_44 ( V_56 -> V_69 , sizeof( * div ) , V_88 ) ;
if ( ! div )
return - V_89 ;
snprintf ( V_78 , sizeof( V_78 ) , L_9 , F_45 ( V_56 -> V_69 ) ) ;
V_71 . V_86 = V_78 ;
V_71 . V_90 = & V_97 ;
V_71 . V_43 = V_98 ;
V_81 [ 0 ] = F_43 ( V_15 ) ;
V_71 . V_92 = V_81 ;
V_71 . V_93 = 1 ;
div -> V_12 = V_56 -> V_60 + V_85 ;
div -> V_94 = F_5 ( V_84 ) ;
div -> V_99 = F_48 ( V_84 ) ;
div -> V_2 . V_71 = & V_71 ;
div -> V_43 = V_100 ;
V_15 = F_46 ( V_56 -> V_69 , & div -> V_2 ) ;
if ( F_47 ( F_40 ( V_15 ) ) )
return F_42 ( V_15 ) ;
V_75 = F_44 ( V_56 -> V_69 , sizeof( * V_75 ) , V_88 ) ;
if ( ! V_75 )
return - V_89 ;
snprintf ( V_78 , sizeof( V_78 ) , L_10 , F_45 ( V_56 -> V_69 ) ) ;
V_71 . V_86 = V_78 ;
V_71 . V_90 = & V_101 ;
V_71 . V_43 = V_98 ;
V_81 [ 0 ] = F_43 ( V_15 ) ;
V_71 . V_92 = V_81 ;
V_71 . V_93 = 1 ;
V_75 -> V_12 = V_56 -> V_60 + V_85 ;
V_75 -> V_6 = V_102 ;
V_75 -> V_2 . V_71 = & V_71 ;
V_56 -> V_68 = F_46 ( V_56 -> V_69 , & V_75 -> V_2 ) ;
if ( F_47 ( F_49 ( V_56 -> V_68 ) ) )
return F_42 ( V_56 -> V_68 ) ;
V_76 = F_44 ( V_56 -> V_69 , sizeof( * V_76 ) , V_88 ) ;
if ( ! V_76 )
return - V_89 ;
snprintf ( V_78 , sizeof( V_78 ) , L_11 , F_45 ( V_56 -> V_69 ) ) ;
V_71 . V_86 = V_78 ;
V_71 . V_90 = & V_101 ;
V_71 . V_43 = 0 ;
V_81 [ 0 ] = F_43 ( V_56 -> V_68 ) ;
V_71 . V_92 = V_81 ;
V_71 . V_93 = 1 ;
V_76 -> V_12 = V_56 -> V_60 + V_85 ;
V_76 -> V_6 = V_103 ;
V_76 -> V_13 = V_104 ;
V_76 -> V_16 = V_105 ;
V_76 -> V_2 . V_71 = & V_71 ;
V_56 -> V_106 = F_46 ( V_56 -> V_69 , & V_76 -> V_2 ) ;
if ( F_47 ( F_49 ( V_56 -> V_106 ) ) )
return F_42 ( V_56 -> V_106 ) ;
V_77 = F_44 ( V_56 -> V_69 , sizeof( * V_77 ) , V_88 ) ;
if ( ! V_77 )
return - V_89 ;
snprintf ( V_78 , sizeof( V_78 ) , L_12 , F_45 ( V_56 -> V_69 ) ) ;
V_71 . V_86 = V_78 ;
V_71 . V_90 = & V_101 ;
V_71 . V_43 = 0 ;
V_81 [ 0 ] = F_43 ( V_56 -> V_68 ) ;
V_71 . V_92 = V_81 ;
V_71 . V_93 = 1 ;
V_77 -> V_12 = V_56 -> V_60 + V_85 ;
V_77 -> V_6 = V_107 ;
V_77 -> V_13 = V_108 ;
V_77 -> V_16 = V_105 ;
V_77 -> V_2 . V_71 = & V_71 ;
V_56 -> V_109 = F_46 ( V_56 -> V_69 , & V_77 -> V_2 ) ;
if ( F_47 ( F_49 ( V_56 -> V_109 ) ) )
return F_42 ( V_56 -> V_109 ) ;
V_56 -> V_4 -> V_110 = F_50 ( V_56 -> V_68 , 400000 ) ;
V_65 = F_36 ( V_56 -> V_68 , V_56 -> V_4 -> V_110 ) ;
if ( V_65 )
return V_65 ;
F_51 ( V_56 -> V_68 , 180 ) ;
F_51 ( V_56 -> V_106 , 270 ) ;
F_51 ( V_56 -> V_109 , 0 ) ;
return F_52 ( V_56 -> V_68 ) ;
}
static void F_53 ( unsigned long * V_111 , unsigned long V_94 )
{
F_54 ( V_112 , V_113 ) ;
F_54 ( V_114 , V_113 ) ;
F_55 ( V_114 , V_111 , V_94 , V_113 ) ;
F_56 ( V_112 , V_111 , V_113 - V_94 ,
V_113 ) ;
F_57 ( V_111 , V_112 , V_114 , V_113 ) ;
}
static void F_58 ( unsigned long * V_111 ,
unsigned long * V_115 ,
unsigned long * V_32 )
{
* V_115 = F_59 ( V_111 , V_113 , * V_115 ) ;
* V_32 = F_60 ( V_111 , V_113 , * V_115 ) ;
}
static int F_61 ( unsigned long * V_116 )
{
unsigned long V_94 , V_32 , V_40 = 0 , V_115 = 0 , V_117 = 0 ;
if ( F_62 ( V_116 , V_113 ) )
return 0 ;
else if ( F_63 ( V_116 , V_113 ) )
return - V_118 ;
V_94 = F_64 ( V_116 , V_113 ) ;
if ( V_94 != 0 )
F_53 ( V_116 , V_94 ) ;
while ( V_115 < V_113 ) {
F_58 ( V_116 , & V_115 , & V_32 ) ;
if ( ( V_32 - V_115 ) > V_117 ) {
V_40 = V_115 ;
V_117 = V_32 - V_115 ;
}
V_115 = V_32 ;
}
V_40 += ( V_117 / 2 ) ;
V_40 = ( V_40 + V_94 ) % V_113 ;
return V_40 ;
}
static int F_65 ( struct V_33 * V_4 , T_1 V_28 ,
struct V_15 * V_15 )
{
int V_119 , V_65 ;
F_54 ( V_116 , V_113 ) ;
F_37 ( F_26 ( V_4 ) , L_13 ,
F_43 ( V_15 ) ) ;
F_66 ( V_116 , V_113 ) ;
for ( V_119 = 0 ; V_119 < V_113 ; V_119 ++ ) {
F_51 ( V_15 , V_119 * V_120 ) ;
V_65 = F_67 ( V_4 , V_28 , NULL ) ;
if ( ! V_65 )
F_68 ( V_119 , V_116 ) ;
}
V_119 = F_61 ( V_116 ) ;
if ( V_119 < 0 )
return V_119 ;
F_51 ( V_15 , V_119 * V_120 ) ;
F_37 ( F_26 ( V_4 ) , L_14 ,
F_69 ( V_15 ) ) ;
return 0 ;
}
static int F_70 ( struct V_33 * V_4 , T_1 V_28 )
{
struct V_55 * V_56 = F_71 ( V_4 ) ;
int V_65 ;
if ( ! V_4 -> V_121 ) {
V_65 = F_65 ( V_4 , V_28 , V_56 -> V_109 ) ;
if ( V_65 )
return V_65 ;
}
V_65 = F_65 ( V_4 , V_28 , V_56 -> V_106 ) ;
if ( V_65 )
return V_65 ;
return F_65 ( V_4 , V_28 , V_56 -> V_109 ) ;
}
static void F_72 ( struct V_33 * V_4 , struct V_49 * V_50 )
{
struct V_55 * V_56 = F_71 ( V_4 ) ;
T_1 V_122 , V_11 ;
int V_48 ;
switch ( V_50 -> V_123 ) {
case V_124 :
if ( ! F_40 ( V_4 -> V_125 . V_126 ) )
F_73 ( V_4 , V_4 -> V_125 . V_126 , 0 ) ;
if ( ! F_40 ( V_4 -> V_125 . V_127 ) && V_56 -> V_128 ) {
F_74 ( V_4 -> V_125 . V_127 ) ;
V_56 -> V_128 = false ;
}
break;
case V_129 :
if ( ! F_40 ( V_4 -> V_125 . V_126 ) )
F_73 ( V_4 , V_4 -> V_125 . V_126 , V_50 -> V_130 ) ;
F_51 ( V_56 -> V_109 , 0 ) ;
F_51 ( V_56 -> V_106 , 270 ) ;
break;
case V_131 :
if ( ! F_40 ( V_4 -> V_125 . V_127 ) && ! V_56 -> V_128 ) {
int V_65 = F_75 ( V_4 -> V_125 . V_127 ) ;
if ( V_65 < 0 )
F_28 ( V_56 -> V_69 ,
L_15 ) ;
else
V_56 -> V_128 = true ;
}
break;
}
switch ( V_50 -> V_122 ) {
case V_132 :
V_122 = V_133 ;
break;
case V_134 :
V_122 = V_135 ;
break;
case V_136 :
V_122 = V_137 ;
break;
default:
F_28 ( V_56 -> V_69 , L_16 ,
V_50 -> V_122 ) ;
V_122 = V_135 ;
}
V_11 = F_4 ( V_56 -> V_60 + V_61 ) ;
V_11 &= ~ V_138 ;
V_11 |= F_76 ( V_138 , V_122 ) ;
V_11 &= ~ V_139 ;
if ( F_31 ( V_50 ) )
V_11 |= V_139 ;
V_11 &= ~ V_140 ;
if ( V_50 -> V_51 == V_54 )
V_11 |= V_140 ;
V_48 = F_35 ( V_56 , V_50 ) ;
if ( V_48 )
F_28 ( V_56 -> V_69 , L_17 , V_48 ) ;
F_9 ( V_11 , V_56 -> V_60 + V_61 ) ;
F_37 ( V_56 -> V_69 , L_18 , V_11 ) ;
}
static void F_77 ( struct V_33 * V_4 ,
struct V_34 * V_30 )
{
struct V_55 * V_56 = F_71 ( V_4 ) ;
V_56 -> V_27 = NULL ;
F_78 ( V_56 -> V_4 , V_30 ) ;
}
static void F_79 ( struct V_33 * V_4 , unsigned int V_141 )
{
struct V_55 * V_56 = F_71 ( V_4 ) ;
T_1 V_57 , V_142 ;
V_57 = F_4 ( V_56 -> V_60 + V_61 ) ;
V_142 = F_80 ( V_143 , V_57 ) ;
if ( ! F_81 ( V_141 ) )
F_28 ( V_56 -> V_69 , L_19 , V_141 ) ;
V_141 = F_82 ( V_141 ) ;
if ( V_141 == V_142 )
return;
F_37 ( V_56 -> V_69 , L_20 , V_144 ,
V_142 , V_141 ) ;
V_57 &= ~ V_143 ;
V_57 |= F_76 ( V_143 , V_141 ) ;
F_9 ( V_57 , V_56 -> V_60 + V_61 ) ;
}
static void F_83 ( struct V_26 * V_27 , T_1 * V_145 )
{
if ( V_27 -> V_43 & V_146 ) {
if ( V_27 -> V_43 & V_147 )
* V_145 |= V_148 ;
* V_145 |= V_149 ;
if ( ! ( V_27 -> V_43 & V_150 ) )
* V_145 |= V_151 ;
if ( V_27 -> V_43 & V_152 )
* V_145 |= V_153 ;
} else {
* V_145 |= V_154 ;
}
}
static void F_84 ( struct V_33 * V_4 , T_1 V_145 )
{
struct V_55 * V_56 = F_71 ( V_4 ) ;
struct V_155 * V_156 = V_56 -> V_157 ;
struct V_20 * V_21 = V_56 -> V_27 -> V_21 ;
struct V_35 * V_36 ;
T_1 V_115 ;
int V_37 ;
if ( V_21 -> V_43 & V_158 )
V_145 |= V_159 ;
if ( V_21 -> V_160 > 1 ) {
V_145 |= V_161 ;
F_79 ( V_4 , V_21 -> V_141 ) ;
}
F_20 (data->sg, sg, data->sg_count, i) {
unsigned int V_162 = F_85 ( V_36 ) ;
if ( V_21 -> V_160 > 1 )
V_162 /= V_21 -> V_141 ;
V_156 [ V_37 ] . V_145 = V_145 ;
V_156 [ V_37 ] . V_145 |= F_76 ( V_163 , V_162 ) ;
if ( V_37 > 0 )
V_156 [ V_37 ] . V_145 |= V_164 ;
V_156 [ V_37 ] . V_165 = V_56 -> V_27 -> V_166 ;
V_156 [ V_37 ] . V_167 = 0 ;
V_156 [ V_37 ] . V_168 = F_86 ( V_36 ) ;
}
V_156 [ V_21 -> V_46 - 1 ] . V_145 |= V_169 ;
F_87 () ;
V_115 = V_56 -> V_170 | V_171 ;
F_9 ( V_115 , V_56 -> V_60 + V_172 ) ;
}
static void F_88 ( struct V_33 * V_4 , struct V_26 * V_27 )
{
struct V_55 * V_56 = F_71 ( V_4 ) ;
struct V_20 * V_21 = V_27 -> V_21 ;
T_1 V_145 = 0 , V_168 = 0 ;
unsigned int V_173 = 0 ;
F_89 () ;
V_56 -> V_27 = V_27 ;
V_145 |= F_76 ( V_174 , V_27 -> V_28 ) ;
V_145 |= V_175 ;
F_83 ( V_27 , & V_145 ) ;
if ( V_21 ) {
V_21 -> V_176 = 0 ;
V_145 |= V_177 ;
V_145 |= F_76 ( V_178 ,
F_82 ( F_15 ( V_21 ) ) ) ;
if ( F_22 ( V_21 ) ) {
F_84 ( V_4 , V_145 ) ;
return;
}
if ( V_21 -> V_160 > 1 ) {
V_145 |= V_161 ;
V_145 |= F_76 ( V_163 ,
V_21 -> V_160 ) ;
F_79 ( V_4 , V_21 -> V_141 ) ;
} else {
V_145 |= F_76 ( V_163 , V_21 -> V_141 ) ;
}
V_173 = V_21 -> V_141 * V_21 -> V_160 ;
if ( V_21 -> V_43 & V_158 ) {
V_145 |= V_159 ;
F_47 ( V_173 > V_56 -> V_179 ) ;
F_90 ( V_21 -> V_36 , V_21 -> V_47 ,
V_56 -> V_180 , V_173 ) ;
F_87 () ;
}
V_168 = V_56 -> V_181 & V_182 ;
} else {
V_145 |= F_76 ( V_178 ,
F_82 ( V_183 ) ) ;
}
V_145 |= V_169 ;
F_9 ( V_145 , V_56 -> V_60 + V_184 ) ;
F_9 ( V_168 , V_56 -> V_60 + V_185 ) ;
F_9 ( 0 , V_56 -> V_60 + V_186 ) ;
F_91 () ;
F_9 ( V_27 -> V_166 , V_56 -> V_60 + V_187 ) ;
}
static void F_92 ( struct V_33 * V_4 , struct V_34 * V_30 )
{
struct V_55 * V_56 = F_71 ( V_4 ) ;
bool V_188 = V_30 -> V_21 &&
! ( V_30 -> V_21 -> V_41 & V_45 ) ;
if ( V_188 ) {
F_19 ( V_4 , V_30 ) ;
if ( ! F_22 ( V_30 -> V_21 ) )
V_188 = false ;
}
if ( V_188 )
F_24 ( V_4 , V_30 ) ;
F_9 ( 0 , V_56 -> V_60 + V_172 ) ;
F_88 ( V_4 , V_30 -> V_31 ? : V_30 -> V_27 ) ;
if ( V_188 )
F_29 ( V_4 , V_30 , 0 ) ;
}
static void F_93 ( struct V_33 * V_4 , struct V_26 * V_27 )
{
struct V_55 * V_56 = F_71 ( V_4 ) ;
if ( V_27 -> V_43 & V_147 ) {
V_27 -> V_189 [ 0 ] = F_4 ( V_56 -> V_60 + V_190 ) ;
V_27 -> V_189 [ 1 ] = F_4 ( V_56 -> V_60 + V_191 ) ;
V_27 -> V_189 [ 2 ] = F_4 ( V_56 -> V_60 + V_192 ) ;
V_27 -> V_189 [ 3 ] = F_4 ( V_56 -> V_60 + V_186 ) ;
} else if ( V_27 -> V_43 & V_146 ) {
V_27 -> V_189 [ 0 ] = F_4 ( V_56 -> V_60 + V_186 ) ;
}
}
static T_3 F_94 ( int V_193 , void * V_194 )
{
struct V_55 * V_56 = V_194 ;
struct V_26 * V_27 ;
struct V_20 * V_21 ;
T_1 V_195 , V_196 , V_197 ;
T_3 V_65 = V_198 ;
if ( F_47 ( ! V_56 ) || F_47 ( ! V_56 -> V_27 ) )
return V_198 ;
F_95 ( & V_56 -> V_199 ) ;
V_27 = V_56 -> V_27 ;
V_21 = V_27 -> V_21 ;
V_195 = F_4 ( V_56 -> V_60 + V_200 ) ;
V_197 = F_4 ( V_56 -> V_60 + V_201 ) ;
V_196 = V_197 & V_195 ;
V_27 -> error = 0 ;
if ( V_196 & V_202 ) {
F_37 ( V_56 -> V_69 , L_21 , V_196 ) ;
V_27 -> error = - V_203 ;
V_65 = V_204 ;
goto V_205;
}
if ( V_196 & V_206 ) {
F_37 ( V_56 -> V_69 , L_22 , V_196 ) ;
V_27 -> error = - V_207 ;
V_65 = V_204 ;
goto V_205;
}
F_93 ( V_56 -> V_4 , V_27 ) ;
if ( V_196 & V_208 ) {
F_37 ( V_56 -> V_69 , L_23 ) ;
V_65 = V_204 ;
}
if ( V_196 & ( V_209 | V_210 ) ) {
if ( V_21 && ! V_27 -> error )
V_21 -> V_176 = V_21 -> V_141 * V_21 -> V_160 ;
if ( F_23 ( V_21 ) ||
F_17 ( V_27 ) )
V_65 = V_211 ;
else
V_65 = V_204 ;
}
V_205:
F_9 ( V_195 , V_56 -> V_60 + V_201 ) ;
if ( V_65 == V_204 )
F_77 ( V_56 -> V_4 , V_27 -> V_30 ) ;
else if ( V_65 == V_198 )
F_96 ( V_56 -> V_69 ,
L_24 ,
V_197 , V_195 ) ;
F_97 ( & V_56 -> V_199 ) ;
return V_65 ;
}
static T_3 F_98 ( int V_193 , void * V_194 )
{
struct V_55 * V_56 = V_194 ;
struct V_26 * V_212 , * V_27 = V_56 -> V_27 ;
struct V_20 * V_21 ;
unsigned int V_173 ;
if ( F_47 ( ! V_27 ) )
return V_198 ;
V_21 = V_27 -> V_21 ;
if ( F_23 ( V_21 ) ) {
V_173 = V_21 -> V_141 * V_21 -> V_160 ;
F_47 ( V_173 > V_56 -> V_179 ) ;
F_99 ( V_21 -> V_36 , V_21 -> V_47 ,
V_56 -> V_180 , V_173 ) ;
}
V_212 = F_17 ( V_27 ) ;
if ( V_212 )
F_88 ( V_56 -> V_4 , V_212 ) ;
else
F_77 ( V_56 -> V_4 , V_27 -> V_30 ) ;
return V_204 ;
}
static int F_100 ( struct V_33 * V_4 )
{
int V_196 = F_101 ( V_4 ) ;
if ( V_196 == - V_213 )
return 1 ;
return V_196 ;
}
static void F_102 ( struct V_55 * V_56 )
{
T_1 V_57 = 0 ;
V_57 |= F_76 ( V_214 ,
F_82 ( V_215 ) ) ;
V_57 |= F_76 ( V_216 , F_82 ( V_217 ) ) ;
V_57 |= F_76 ( V_143 , F_82 ( V_218 ) ) ;
F_9 ( V_57 , V_56 -> V_60 + V_61 ) ;
}
static int F_103 ( struct V_33 * V_4 )
{
struct V_55 * V_56 = F_71 ( V_4 ) ;
T_1 V_219 ;
V_219 = F_4 ( V_56 -> V_60 + V_201 ) ;
return ! ( F_80 ( V_220 , V_219 ) & 0xf ) ;
}
static int F_104 ( struct V_33 * V_4 , struct V_49 * V_50 )
{
if ( ! F_40 ( V_4 -> V_125 . V_127 ) ) {
return F_105 ( V_4 , V_50 ) ;
}
if ( V_50 -> V_221 == V_222 )
return 0 ;
return - V_223 ;
}
static int F_106 ( struct V_224 * V_225 )
{
struct V_226 * V_227 ;
struct V_55 * V_56 ;
struct V_33 * V_4 ;
int V_65 , V_193 ;
V_4 = F_107 ( sizeof( struct V_55 ) , & V_225 -> V_69 ) ;
if ( ! V_4 )
return - V_89 ;
V_56 = F_71 ( V_4 ) ;
V_56 -> V_4 = V_4 ;
V_56 -> V_69 = & V_225 -> V_69 ;
F_108 ( & V_225 -> V_69 , V_56 ) ;
F_109 ( & V_56 -> V_199 ) ;
V_56 -> V_128 = false ;
V_65 = F_110 ( V_4 ) ;
if ( V_65 == - V_87 )
goto V_228;
V_65 = F_111 ( V_4 ) ;
if ( V_65 ) {
if ( V_65 != - V_87 )
F_96 ( & V_225 -> V_69 , L_25 , V_65 ) ;
goto V_228;
}
V_227 = F_112 ( V_225 , V_229 , 0 ) ;
V_56 -> V_60 = F_113 ( & V_225 -> V_69 , V_227 ) ;
if ( F_40 ( V_56 -> V_60 ) ) {
V_65 = F_42 ( V_56 -> V_60 ) ;
goto V_228;
}
V_193 = F_114 ( V_225 , 0 ) ;
if ( ! V_193 ) {
F_28 ( & V_225 -> V_69 , L_26 ) ;
V_65 = - V_223 ;
goto V_228;
}
V_56 -> V_59 = F_115 ( & V_225 -> V_69 ) ;
if ( F_40 ( V_56 -> V_59 ) ) {
V_65 = F_42 ( V_56 -> V_59 ) ;
goto V_228;
}
V_56 -> V_63 = F_116 ( V_56 -> V_59 ,
V_230 ) ;
if ( F_40 ( V_56 -> V_63 ) ) {
V_65 = F_42 ( V_56 -> V_63 ) ;
goto V_228;
}
V_56 -> V_58 = F_116 ( V_56 -> V_59 ,
L_27 ) ;
if ( F_40 ( V_56 -> V_58 ) ) {
F_96 ( & V_225 -> V_69 ,
L_28 ) ;
V_56 -> V_58 = NULL ;
}
V_56 -> V_231 = F_39 ( & V_225 -> V_69 , L_29 ) ;
if ( F_40 ( V_56 -> V_231 ) ) {
V_65 = F_42 ( V_56 -> V_231 ) ;
goto V_228;
}
V_65 = F_52 ( V_56 -> V_231 ) ;
if ( V_65 )
goto V_228;
V_65 = F_38 ( V_56 ) ;
if ( V_65 )
goto V_232;
F_102 ( V_56 ) ;
F_9 ( 0 , V_56 -> V_60 + V_172 ) ;
F_9 ( 0 , V_56 -> V_60 + V_200 ) ;
F_9 ( V_202 | V_206 | V_209 ,
V_56 -> V_60 + V_201 ) ;
F_9 ( V_202 | V_206 | V_209 ,
V_56 -> V_60 + V_200 ) ;
V_65 = F_117 ( & V_225 -> V_69 , V_193 , F_94 ,
F_98 , V_233 ,
NULL , V_56 ) ;
if ( V_65 )
goto V_234;
V_4 -> V_235 |= V_236 ;
V_4 -> V_237 = V_163 ;
V_4 -> V_238 = V_4 -> V_237 * V_4 -> V_239 ;
V_4 -> V_240 = V_241 / sizeof( struct V_155 ) ;
V_4 -> V_242 = V_4 -> V_238 ;
V_56 -> V_179 = V_4 -> V_238 ;
V_56 -> V_180 =
F_118 ( V_56 -> V_69 , V_56 -> V_179 ,
& V_56 -> V_181 , V_88 ) ;
if ( V_56 -> V_180 == NULL ) {
F_28 ( V_56 -> V_69 , L_30 ) ;
V_65 = - V_89 ;
goto V_234;
}
V_56 -> V_157 = F_118 ( V_56 -> V_69 , V_241 ,
& V_56 -> V_170 , V_88 ) ;
if ( ! V_56 -> V_157 ) {
F_28 ( V_56 -> V_69 , L_31 ) ;
V_65 = - V_89 ;
goto V_243;
}
V_4 -> V_90 = & V_244 ;
F_119 ( V_4 ) ;
return 0 ;
V_243:
F_120 ( V_56 -> V_69 , V_56 -> V_179 ,
V_56 -> V_180 , V_56 -> V_181 ) ;
V_234:
F_121 ( V_56 -> V_68 ) ;
V_232:
F_121 ( V_56 -> V_231 ) ;
V_228:
F_122 ( V_4 ) ;
return V_65 ;
}
static int F_123 ( struct V_224 * V_225 )
{
struct V_55 * V_56 = F_124 ( & V_225 -> V_69 ) ;
F_125 ( V_56 -> V_4 ) ;
F_9 ( 0 , V_56 -> V_60 + V_200 ) ;
F_120 ( V_56 -> V_69 , V_241 ,
V_56 -> V_157 , V_56 -> V_170 ) ;
F_120 ( V_56 -> V_69 , V_56 -> V_179 ,
V_56 -> V_180 , V_56 -> V_181 ) ;
F_121 ( V_56 -> V_68 ) ;
F_121 ( V_56 -> V_231 ) ;
F_122 ( V_56 -> V_4 ) ;
return 0 ;
}
