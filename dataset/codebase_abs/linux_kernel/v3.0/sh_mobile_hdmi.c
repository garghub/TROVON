static void F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
F_2 ( V_3 , V_2 -> V_5 + V_4 ) ;
}
static T_1 F_3 ( struct V_1 * V_2 , T_1 V_4 )
{
return F_4 ( V_2 -> V_5 + V_4 ) ;
}
static unsigned int F_5 ( struct V_6 * V_7 ,
unsigned int V_4 )
{
struct V_1 * V_2 = F_6 ( V_7 ) ;
return F_3 ( V_2 , V_4 ) ;
}
static int F_7 ( struct V_6 * V_7 ,
unsigned int V_4 ,
unsigned int V_8 )
{
struct V_1 * V_2 = F_6 ( V_7 ) ;
F_1 ( V_2 , V_8 , V_4 ) ;
return 0 ;
}
static int F_8 ( struct V_6 * V_7 )
{
F_9 ( V_7 -> V_9 , L_1 ) ;
return 0 ;
}
static void F_10 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = & V_2 -> V_11 ;
T_2 V_12 , V_13 , V_14 , V_15 , V_16 , V_17 , V_18 ;
T_1 V_19 = 0 ;
V_12 = V_11 -> V_20 + V_11 -> V_21 + V_11 -> V_22 + V_11 -> V_23 ;
V_14 = V_11 -> V_23 + V_11 -> V_22 ;
V_13 = V_11 -> V_21 + V_14 ;
V_15 = V_11 -> V_24 + V_11 -> V_25 + V_11 -> V_26 + V_11 -> V_27 ;
V_17 = V_11 -> V_27 + V_11 -> V_25 ;
V_16 = V_11 -> V_26 + V_17 ;
V_18 = F_11 ( V_11 -> V_25 / 2 , 6U ) ;
if ( V_11 -> V_19 & V_28 )
V_19 |= 4 ;
if ( V_11 -> V_19 & V_29 )
V_19 |= 8 ;
F_12 ( V_2 -> V_9 , L_2 ,
V_12 , V_13 , V_14 , V_11 -> V_23 ,
V_15 , V_16 , V_17 , V_11 -> V_27 , V_19 ) ;
F_1 ( V_2 , V_19 | ( V_18 << 4 ) , V_30 ) ;
F_1 ( V_2 , V_12 , V_31 ) ;
F_1 ( V_2 , V_12 >> 8 , V_32 ) ;
F_1 ( V_2 , V_13 , V_33 ) ;
F_1 ( V_2 , V_13 >> 8 , V_34 ) ;
F_1 ( V_2 , V_14 , V_35 ) ;
F_1 ( V_2 , V_14 >> 8 , V_36 ) ;
F_1 ( V_2 , V_11 -> V_23 , V_37 ) ;
F_1 ( V_2 , V_11 -> V_23 >> 8 , V_38 ) ;
F_1 ( V_2 , V_15 , V_39 ) ;
F_1 ( V_2 , V_15 >> 8 , V_40 ) ;
F_1 ( V_2 , V_16 , V_41 ) ;
F_1 ( V_2 , V_17 , V_42 ) ;
F_1 ( V_2 , V_11 -> V_27 , V_43 ) ;
if ( ! V_2 -> V_44 )
F_1 ( V_2 , V_19 | 1 | ( V_18 << 4 ) ,
V_30 ) ;
}
static void F_13 ( struct V_1 * V_2 )
{
F_1 ( V_2 , 0x20 , V_45 ) ;
F_1 ( V_2 , 0x34 , V_46 ) ;
F_1 ( V_2 , 0x20 , V_47 ) ;
}
static void F_14 ( struct V_1 * V_2 )
{
T_1 V_3 ;
struct V_48 * V_49 = V_2 -> V_9 -> V_50 ;
F_1 ( V_2 , 0x00 , V_51 ) ;
F_1 ( V_2 , 0x18 , V_52 ) ;
F_1 ( V_2 , 0x00 , V_53 ) ;
F_1 ( V_2 , 0x20 , V_54 ) ;
switch ( V_49 -> V_55 & V_56 ) {
default:
case V_57 :
V_3 = 0x0 << 3 ;
break;
case V_58 :
V_3 = 0x1 << 3 ;
break;
case V_59 :
V_3 = 0x2 << 3 ;
break;
case V_60 :
V_3 = 0x3 << 3 ;
break;
}
F_1 ( V_2 , V_3 , V_61 ) ;
F_1 ( V_2 , 0x40 , V_62 ) ;
F_1 ( V_2 , 0x04 , V_63 ) ;
F_1 ( V_2 , 0x00 , V_64 ) ;
F_1 ( V_2 , 0x00 , V_65 ) ;
F_1 ( V_2 , 0x00 , V_66 ) ;
F_1 ( V_2 , 0x00 , V_67 ) ;
F_1 ( V_2 , 0x00 , V_68 ) ;
F_1 ( V_2 , 0x00 , V_69 ) ;
F_1 ( V_2 , 0x20 , V_45 ) ;
}
static void F_15 ( struct V_1 * V_2 )
{
if ( V_2 -> V_11 . V_70 < 10000 ) {
F_1 ( V_2 , 0x1d , V_71 ) ;
F_1 ( V_2 , 0x00 , V_72 ) ;
F_1 ( V_2 , 0x00 , V_73 ) ;
F_1 ( V_2 , 0x4c , V_74 ) ;
F_1 ( V_2 , 0x1e , V_75 ) ;
F_1 ( V_2 , 0x48 , V_76 ) ;
F_1 ( V_2 , 0x0e , V_77 ) ;
F_1 ( V_2 , 0x25 , V_78 ) ;
F_1 ( V_2 , 0x04 , V_79 ) ;
} else if ( V_2 -> V_11 . V_70 < 30000 ) {
F_1 ( V_2 , 0x0f , V_71 ) ;
F_1 ( V_2 , 0x00 , V_72 ) ;
F_1 ( V_2 , 0x00 , V_73 ) ;
F_1 ( V_2 , 0x44 , V_74 ) ;
F_1 ( V_2 , 0x32 , V_75 ) ;
F_1 ( V_2 , 0x4A , V_76 ) ;
F_1 ( V_2 , 0x00 , V_77 ) ;
F_1 ( V_2 , 0x25 , V_78 ) ;
F_1 ( V_2 , 0x04 , V_79 ) ;
} else {
F_1 ( V_2 , 0x19 , V_71 ) ;
F_1 ( V_2 , 0x00 , V_72 ) ;
F_1 ( V_2 , 0x00 , V_73 ) ;
F_1 ( V_2 , 0x44 , V_74 ) ;
F_1 ( V_2 , 0x32 , V_75 ) ;
F_1 ( V_2 , 0x48 , V_76 ) ;
F_1 ( V_2 , 0x0F , V_77 ) ;
F_1 ( V_2 , 0x20 , V_78 ) ;
F_1 ( V_2 , 0x04 , V_79 ) ;
}
}
static void F_16 ( struct V_1 * V_2 )
{
T_1 V_80 ;
F_1 ( V_2 , 0x06 , V_81 ) ;
F_1 ( V_2 , 0x82 , V_82 ) ;
F_1 ( V_2 , 0x02 , V_83 ) ;
F_1 ( V_2 , 0x0D , V_84 ) ;
F_1 ( V_2 , 0x00 , V_85 ) ;
F_1 ( V_2 , 0x00 , V_86 ) ;
F_1 ( V_2 , 0x28 , V_87 ) ;
F_1 ( V_2 , 0x00 , V_88 ) ;
if ( V_2 -> V_44 )
V_80 = V_2 -> V_44 ;
else
V_80 = 4 ;
F_1 ( V_2 , V_80 , V_89 ) ;
F_1 ( V_2 , 0x00 , V_90 ) ;
F_1 ( V_2 , 0x00 , V_91 ) ;
F_1 ( V_2 , 0x00 , V_92 ) ;
F_1 ( V_2 , 0x00 , V_93 ) ;
F_1 ( V_2 , 0x00 , V_94 ) ;
F_1 ( V_2 , 0x00 , V_95 ) ;
F_1 ( V_2 , 0x00 , V_96 ) ;
F_1 ( V_2 , 0x00 , V_97 ) ;
F_1 ( V_2 , 0x00 , V_98 ) ;
}
static void F_17 ( struct V_1 * V_2 )
{
F_1 ( V_2 , 0x08 , V_81 ) ;
F_1 ( V_2 , 0x84 , V_82 ) ;
F_1 ( V_2 , 0x01 , V_83 ) ;
F_1 ( V_2 , 0x0A , V_84 ) ;
F_1 ( V_2 , 0x00 , V_85 ) ;
F_1 ( V_2 , 0x00 , V_86 ) ;
F_1 ( V_2 , 0x00 , V_87 ) ;
F_1 ( V_2 , 0x00 , V_88 ) ;
F_1 ( V_2 , 0x00 , V_89 ) ;
F_1 ( V_2 , 0x00 , V_90 ) ;
F_1 ( V_2 , 0x00 , V_91 ) ;
F_1 ( V_2 , 0x00 , V_92 ) ;
F_1 ( V_2 , 0x00 , V_93 ) ;
F_1 ( V_2 , 0x00 , V_94 ) ;
F_1 ( V_2 , 0x00 , V_95 ) ;
}
static void F_18 ( struct V_1 * V_2 )
{
F_13 ( V_2 ) ;
F_14 ( V_2 ) ;
F_15 ( V_2 ) ;
F_16 ( V_2 ) ;
F_17 ( V_2 ) ;
F_1 ( V_2 , 0x8E , V_99 ) ;
F_19 ( 10 ) ;
F_1 ( V_2 , 0x4C , V_100 ) ;
F_20 ( 10 ) ;
F_1 ( V_2 , 0x40 , V_100 ) ;
}
static unsigned long F_21 ( struct V_1 * V_2 ,
const struct V_101 * V_102 ,
unsigned long * V_103 , unsigned long * V_104 )
{
unsigned long V_105 = F_22 ( V_102 -> V_70 ) * 1000 , V_106 ;
struct V_48 * V_49 = V_2 -> V_9 -> V_50 ;
* V_103 = F_23 ( V_2 -> V_107 , V_105 ) ;
if ( ( long ) * V_103 < 0 )
* V_103 = F_24 ( V_2 -> V_107 ) ;
V_106 = ( long ) * V_103 > 0 ? abs ( * V_103 - V_105 ) : V_108 ;
if ( V_106 && V_49 -> V_109 )
V_106 = V_49 -> V_109 ( V_105 , V_103 , V_104 ) ;
else if ( F_25 ( V_2 -> V_107 ) )
* V_104 = F_24 ( F_25 ( V_2 -> V_107 ) ) ;
F_12 ( V_2 -> V_9 , L_3 ,
V_102 -> V_22 , V_102 -> V_20 ,
V_102 -> V_21 , V_102 -> V_23 ,
V_102 -> V_25 , V_102 -> V_24 ,
V_102 -> V_26 , V_102 -> V_27 ) ;
F_12 ( V_2 -> V_9 , L_4 , V_105 ,
V_106 , V_106 ? 10000 / ( 10 * V_105 / V_106 ) : 0 ,
V_102 -> V_110 , * V_104 ) ;
return V_106 ;
}
static int F_26 ( struct V_1 * V_2 , unsigned long * V_103 ,
unsigned long * V_104 )
{
struct V_10 V_111 ;
struct V_10 * V_11 = & V_111 ;
const struct V_101 * V_102 , * V_112 = NULL ;
struct V_113 * V_114 = V_2 -> V_114 ;
struct V_115 * V_116 = NULL ;
unsigned int V_117 = 0 , V_118 = 0 , V_119 = 0 ;
unsigned long V_120 = V_108 ;
bool V_121 = false , V_122 = false ;
T_1 V_123 [ 128 ] ;
char * V_124 ;
int V_125 ;
F_12 ( V_2 -> V_9 , L_5 ) ;
for ( V_125 = 0 ; V_125 < 128 ; V_125 ++ ) {
V_123 [ V_125 ] = F_3 ( V_2 , V_126 ) ;
#ifdef F_27
if ( ( V_125 % 16 ) == 0 ) {
F_28 ( V_127 L_6 ) ;
F_28 ( V_128 L_7 , V_125 , V_123 [ V_125 ] ) ;
} else {
F_28 ( V_127 L_8 , V_123 [ V_125 ] ) ;
}
#endif
}
#ifdef F_27
F_28 ( V_127 L_6 ) ;
#endif
if ( ! V_2 -> V_129 ) {
F_29 ( V_123 , & V_2 -> V_130 ) ;
V_2 -> V_129 = V_123 [ 126 ] + 1 ;
F_12 ( V_2 -> V_9 , L_9 ,
V_2 -> V_130 . V_131 , V_2 -> V_129 - 1 ) ;
} else {
F_12 ( V_2 -> V_9 , L_10 ,
V_123 [ 0 ] , V_123 [ 2 ] ) ;
F_30 ( V_123 , & V_2 -> V_130 ) ;
}
if ( V_2 -> V_129 > V_2 -> V_132 * 2 +
( V_2 -> V_133 >> 7 ) + 1 ) {
if ( V_2 -> V_133 ) {
V_2 -> V_133 = 0 ;
V_2 -> V_132 ++ ;
} else {
V_2 -> V_133 = 0x80 ;
}
F_1 ( V_2 , V_2 -> V_133 , V_134 ) ;
F_1 ( V_2 , 0xC6 , V_135 ) ;
F_1 ( V_2 , V_2 -> V_132 , V_136 ) ;
return - V_137 ;
}
F_12 ( V_2 -> V_9 , L_11 , V_2 -> V_130 . V_131 ) ;
F_31 ( L_12 , & V_124 ) ;
if ( V_124 && * V_124 ) {
V_125 = sscanf ( V_124 , L_13 ,
& V_117 , & V_118 , & V_119 ) ;
if ( V_125 < 2 ) {
V_117 = 0 ;
V_118 = 0 ;
} else {
V_121 = true ;
}
F_12 ( V_2 -> V_9 , L_14 ,
V_117 , V_118 , V_119 ) ;
}
for ( V_125 = 0 , V_102 = V_2 -> V_130 . V_138 ;
V_125 < V_2 -> V_130 . V_131 && V_121 ;
V_125 ++ , V_102 ++ ) {
unsigned long V_106 ;
if ( ! V_117 && ! V_118 ) {
if ( ( V_102 -> V_139 & V_140 ) || V_122 )
V_121 = false ;
else
continue;
} else if ( V_117 != V_102 -> V_20 || V_118 != V_102 -> V_24 ) {
continue;
}
V_106 = F_21 ( V_2 , V_102 , V_103 , V_104 ) ;
if ( V_121 ) {
if ( V_119 == V_102 -> V_110 || ( ! V_119 && ! V_106 ) )
V_121 = false ;
else if ( V_112 && V_120 <= V_106 )
continue;
}
F_32 ( V_11 , V_102 ) ;
V_11 -> V_141 = V_114 -> V_11 . V_141 ;
if ( V_114 && V_114 -> V_142 -> V_143 &&
V_114 -> V_142 -> V_143 ( V_11 , V_114 ) ) {
V_121 = true ;
V_122 = true ;
continue;
}
V_112 = V_102 ;
V_120 = V_106 ;
}
V_2 -> V_11 . V_144 = V_2 -> V_130 . V_145 * 10 ;
V_2 -> V_11 . V_146 = V_2 -> V_130 . V_147 * 10 ;
if ( V_114 && ! V_112 ) {
V_116 = V_114 -> V_116 . V_148 &&
! F_33 ( & V_114 -> V_116 ) ?
F_34 ( V_114 -> V_116 . V_148 ,
struct V_115 , V_149 ) :
NULL ;
if ( V_116 ) {
V_112 = & V_116 -> V_102 ;
V_120 = F_21 ( V_2 , V_112 , V_103 , V_104 ) ;
}
}
if ( ! V_112 )
return - V_150 ;
if ( V_112 -> V_20 == 640 && V_112 -> V_24 == 480 && V_112 -> V_110 == 60 )
V_2 -> V_44 = 1 ;
else if ( V_112 -> V_20 == 720 && V_112 -> V_24 == 480 && V_112 -> V_110 == 60 )
V_2 -> V_44 = 2 ;
else if ( V_112 -> V_20 == 720 && V_112 -> V_24 == 576 && V_112 -> V_110 == 50 )
V_2 -> V_44 = 17 ;
else if ( V_112 -> V_20 == 1280 && V_112 -> V_24 == 720 && V_112 -> V_110 == 60 )
V_2 -> V_44 = 4 ;
else if ( V_112 -> V_20 == 1920 && V_112 -> V_24 == 1080 && V_112 -> V_110 == 24 )
V_2 -> V_44 = 32 ;
else if ( V_112 -> V_20 == 1920 && V_112 -> V_24 == 1080 && V_112 -> V_110 == 50 )
V_2 -> V_44 = 31 ;
else if ( V_112 -> V_20 == 1920 && V_112 -> V_24 == 1080 && V_112 -> V_110 == 60 )
V_2 -> V_44 = 16 ;
else
V_2 -> V_44 = 0 ;
F_12 ( V_2 -> V_9 , L_15 ,
V_116 ? L_16 : L_17 , V_2 -> V_44 ? L_18 : L_19 ,
V_112 -> V_20 , V_112 -> V_24 , V_112 -> V_110 ,
F_22 ( V_112 -> V_70 ) * 1000 , V_120 ) ;
F_32 ( & V_2 -> V_11 , V_112 ) ;
F_10 ( V_2 ) ;
return 0 ;
}
static T_3 F_35 ( int V_151 , void * V_152 )
{
struct V_1 * V_2 = V_152 ;
T_1 V_153 , V_154 , V_155 , V_156 ;
F_1 ( V_2 , 0x2C , V_100 ) ;
F_20 ( 10 ) ;
F_1 ( V_2 , 0x20 , V_100 ) ;
V_153 = F_3 ( V_2 , V_157 ) ;
V_154 = F_3 ( V_2 , V_158 ) ;
V_155 = F_3 ( V_2 , V_135 ) ;
V_156 = F_3 ( V_2 , V_159 ) ;
F_1 ( V_2 , 0xFF , V_157 ) ;
F_1 ( V_2 , 0xFF , V_158 ) ;
if ( F_36 () )
F_12 ( V_2 -> V_9 , L_20 ,
V_151 , V_153 , V_155 , V_154 , V_156 ) ;
if ( ! ( ( V_153 & V_155 ) | ( V_154 & V_156 ) ) ) {
return V_160 ;
} else if ( V_153 & 0xc0 ) {
T_1 V_161 ;
F_20 ( 500 ) ;
V_161 = F_3 ( V_2 , V_162 ) ;
F_12 ( V_2 -> V_9 , L_21 , V_161 ) ;
if ( ( V_161 & 0xC0 ) == 0xC0 ) {
V_2 -> V_132 = 0 ;
V_2 -> V_133 = 0 ;
V_2 -> V_129 = 0 ;
V_2 -> V_163 = V_164 ;
F_1 ( V_2 , 0x00 , V_134 ) ;
F_1 ( V_2 , 0xC6 , V_135 ) ;
F_1 ( V_2 , 0x00 , V_136 ) ;
} else if ( ! ( V_153 & 0x80 ) ) {
if ( V_2 -> V_163 != V_165 ) {
V_2 -> V_163 = V_165 ;
F_37 ( & V_2 -> V_166 , 0 ) ;
}
}
} else if ( V_153 & 2 ) {
F_1 ( V_2 , V_2 -> V_133 , V_134 ) ;
F_1 ( V_2 , V_2 -> V_132 , V_136 ) ;
} else if ( V_153 & 4 ) {
F_1 ( V_2 , 0xC0 , V_135 ) ;
F_37 ( & V_2 -> V_166 , F_38 ( 10 ) ) ;
}
return V_167 ;
}
static void F_39 ( void * V_168 , struct V_113 * V_114 )
{
struct V_1 * V_2 = V_168 ;
struct V_48 * V_49 = V_2 -> V_9 -> V_50 ;
struct V_169 * V_170 = V_114 -> V_171 ;
F_12 ( V_2 -> V_9 , L_22 , V_172 ,
V_49 -> V_173 , V_114 -> V_174 ) ;
V_2 -> V_114 = V_114 ;
switch ( V_2 -> V_163 ) {
case V_175 :
F_1 ( V_2 , 0x80 , V_100 ) ;
F_12 ( V_2 -> V_9 , L_23 ) ;
break;
case V_165 :
V_114 -> V_174 = V_176 ;
default:
V_2 -> V_11 = V_170 -> V_177 ;
}
}
static void F_40 ( void * V_168 )
{
struct V_1 * V_2 = V_168 ;
struct V_48 * V_49 = V_2 -> V_9 -> V_50 ;
F_12 ( V_2 -> V_9 , L_24 , V_172 , V_49 -> V_173 ) ;
F_1 ( V_2 , 0x10 , V_100 ) ;
}
static bool F_41 ( struct V_1 * V_2 )
{
struct V_113 * V_114 = V_2 -> V_114 ;
struct V_169 * V_170 = V_114 -> V_171 ;
struct V_10 * V_178 = & V_2 -> V_11 , * V_179 = & V_170 -> V_177 ;
struct V_101 V_180 , V_181 ;
F_42 ( & V_180 , V_179 ) ;
F_42 ( & V_181 , V_178 ) ;
F_12 ( V_114 -> V_9 , L_25 ,
V_180 . V_20 , V_180 . V_24 , V_181 . V_20 , V_181 . V_24 ) ;
if ( F_43 ( & V_180 , & V_181 ) ) {
V_179 -> V_144 = V_178 -> V_144 ;
V_179 -> V_146 = V_178 -> V_146 ;
return false ;
}
F_12 ( V_114 -> V_9 , L_26 ,
V_180 . V_24 , V_181 . V_24 ) ;
* V_179 = * V_178 ;
return true ;
}
static long F_44 ( struct V_1 * V_2 , unsigned long V_103 ,
unsigned long V_104 )
{
int V_182 ;
if ( V_104 && F_25 ( V_2 -> V_107 ) ) {
V_182 = F_45 ( F_25 ( V_2 -> V_107 ) , V_104 ) ;
if ( V_182 < 0 ) {
F_46 ( V_2 -> V_9 , L_27 , V_104 , V_182 ) ;
V_103 = F_23 ( V_2 -> V_107 , V_103 ) ;
} else {
F_12 ( V_2 -> V_9 , L_28 , V_104 ) ;
}
}
V_182 = F_45 ( V_2 -> V_107 , V_103 ) ;
if ( V_182 < 0 ) {
F_46 ( V_2 -> V_9 , L_29 , V_103 , V_182 ) ;
V_103 = 0 ;
} else {
F_12 ( V_2 -> V_9 , L_30 , V_103 ) ;
}
return V_103 ;
}
static void F_47 ( struct V_183 * V_184 )
{
struct V_1 * V_2 = F_48 ( V_184 , struct V_1 , V_166 . V_184 ) ;
struct V_48 * V_49 = V_2 -> V_9 -> V_50 ;
struct V_169 * V_170 ;
int V_182 ;
F_12 ( V_2 -> V_9 , L_31 , V_172 ,
V_49 -> V_173 , V_2 -> V_163 ) ;
if ( ! V_49 -> V_173 )
return;
F_49 ( & V_2 -> V_185 ) ;
if ( V_2 -> V_163 == V_164 ) {
struct V_113 * V_114 = V_2 -> V_114 ;
unsigned long V_104 = 0 , V_103 ;
V_182 = F_26 ( V_2 , & V_103 , & V_104 ) ;
if ( V_182 < 0 )
goto V_186;
V_2 -> V_163 = V_175 ;
V_182 = F_44 ( V_2 , V_103 , V_104 ) ;
if ( V_182 < 0 )
goto V_186;
F_19 ( 10 ) ;
F_18 ( V_2 ) ;
F_19 ( 10 ) ;
if ( ! V_114 )
goto V_186;
V_170 = V_114 -> V_171 ;
F_50 () ;
if ( ! F_41 ( V_2 ) &&
V_114 -> V_174 == V_187 ) {
if ( F_51 ( V_114 ) ) {
V_114 -> V_11 . V_144 = V_2 -> V_11 . V_144 ;
V_114 -> V_11 . V_146 = V_2 -> V_11 . V_146 ;
F_39 ( V_2 , V_114 ) ;
F_52 ( V_114 ) ;
}
} else {
F_53 ( V_114 , 0 ) ;
}
F_54 () ;
} else {
V_182 = 0 ;
if ( ! V_2 -> V_114 )
goto V_186;
V_2 -> V_130 . V_131 = 0 ;
F_55 ( V_2 -> V_130 . V_138 ) ;
V_2 -> V_130 . V_138 = NULL ;
F_50 () ;
F_53 ( V_2 -> V_114 , 1 ) ;
F_54 () ;
}
V_186:
if ( V_182 < 0 && V_182 != - V_137 )
V_2 -> V_163 = V_165 ;
F_56 ( & V_2 -> V_185 ) ;
F_12 ( V_2 -> V_9 , L_32 , V_172 , V_49 -> V_173 ) ;
}
static int F_57 ( struct V_188 * V_189 ,
unsigned long V_190 , void * V_3 )
{
struct V_191 * V_192 = V_3 ;
struct V_113 * V_114 = V_192 -> V_114 ;
struct V_169 * V_170 = V_114 -> V_171 ;
struct V_193 * V_194 = & V_170 -> V_195 . V_194 ;
struct V_1 * V_2 = V_194 -> V_196 ;
if ( ! V_2 || V_189 != & V_2 -> V_197 || V_2 -> V_114 != V_114 )
return V_198 ;
switch( V_190 ) {
case V_199 :
break;
case V_200 :
F_52 ( V_114 ) ;
F_49 ( & V_2 -> V_185 ) ;
V_2 -> V_114 = NULL ;
F_56 ( & V_2 -> V_185 ) ;
F_51 ( V_114 ) ;
return V_201 ;
}
return V_198 ;
}
static int T_4 F_58 ( struct V_202 * V_203 )
{
struct V_48 * V_49 = V_203 -> V_9 . V_50 ;
struct V_204 * V_205 = F_59 ( V_203 , V_206 , 0 ) ;
struct V_193 * V_194 ;
int V_151 = F_60 ( V_203 , 0 ) , V_182 ;
struct V_1 * V_2 ;
long V_207 ;
if ( ! V_205 || ! V_49 || V_151 < 0 )
return - V_208 ;
V_2 = F_61 ( sizeof( * V_2 ) , V_209 ) ;
if ( ! V_2 ) {
F_62 ( & V_203 -> V_9 , L_33 ) ;
return - V_210 ;
}
F_63 ( & V_2 -> V_185 ) ;
V_2 -> V_9 = & V_203 -> V_9 ;
V_2 -> V_107 = F_64 ( & V_203 -> V_9 , L_34 ) ;
if ( F_65 ( V_2 -> V_107 ) ) {
V_182 = F_66 ( V_2 -> V_107 ) ;
F_62 ( & V_203 -> V_9 , L_35 , V_182 ) ;
goto V_211;
}
V_207 = F_23 ( V_2 -> V_107 , F_22 ( 37037 ) ) ;
if ( V_207 > 0 )
V_207 = F_44 ( V_2 , V_207 , 0 ) ;
if ( V_207 < 0 ) {
V_182 = V_207 ;
goto V_212;
}
V_182 = F_67 ( V_2 -> V_107 ) ;
if ( V_182 < 0 ) {
F_62 ( V_2 -> V_9 , L_36 , V_182 ) ;
goto V_212;
}
F_12 ( & V_203 -> V_9 , L_37 , V_207 ) ;
if ( ! F_68 ( V_205 -> V_213 , F_69 ( V_205 ) , F_70 ( & V_203 -> V_9 ) ) ) {
F_62 ( & V_203 -> V_9 , L_38 ) ;
V_182 = - V_214 ;
goto V_215;
}
V_2 -> V_5 = F_71 ( V_205 -> V_213 , F_69 ( V_205 ) ) ;
if ( ! V_2 -> V_5 ) {
F_62 ( & V_203 -> V_9 , L_38 ) ;
V_182 = - V_210 ;
goto V_216;
}
F_72 ( V_203 , V_2 ) ;
V_194 = & V_49 -> V_217 -> V_194 ;
V_194 -> V_218 = V_219 ;
V_194 -> V_196 = V_2 ;
V_194 -> V_220 = F_39 ;
V_194 -> V_221 = F_40 ;
F_73 ( & V_2 -> V_166 , F_47 ) ;
F_74 ( & V_203 -> V_9 ) ;
F_75 ( & V_203 -> V_9 ) ;
F_9 ( & V_203 -> V_9 , L_39 ,
F_3 ( V_2 , V_222 ) , F_3 ( V_2 , V_223 ) ) ;
V_182 = F_76 ( V_151 , F_35 , 0 ,
F_70 ( & V_203 -> V_9 ) , V_2 ) ;
if ( V_182 < 0 ) {
F_62 ( & V_203 -> V_9 , L_40 , V_182 ) ;
goto V_224;
}
V_182 = F_77 ( & V_203 -> V_9 ,
& V_225 , & V_226 , 1 ) ;
if ( V_182 < 0 ) {
F_62 ( & V_203 -> V_9 , L_41 ) ;
goto V_227;
}
V_2 -> V_197 . V_228 = F_57 ;
F_78 ( & V_2 -> V_197 ) ;
return 0 ;
V_227:
F_79 ( V_151 , V_2 ) ;
V_224:
F_80 ( & V_203 -> V_9 ) ;
F_81 ( & V_203 -> V_9 ) ;
F_82 ( V_2 -> V_5 ) ;
V_216:
F_83 ( V_205 -> V_213 , F_69 ( V_205 ) ) ;
V_215:
F_84 ( V_2 -> V_107 ) ;
V_212:
F_85 ( V_2 -> V_107 ) ;
V_211:
F_86 ( & V_2 -> V_185 ) ;
F_87 ( V_2 ) ;
return V_182 ;
}
static int T_5 F_88 ( struct V_202 * V_203 )
{
struct V_48 * V_49 = V_203 -> V_9 . V_50 ;
struct V_1 * V_2 = F_89 ( V_203 ) ;
struct V_204 * V_205 = F_59 ( V_203 , V_206 , 0 ) ;
struct V_193 * V_194 = & V_49 -> V_217 -> V_194 ;
int V_151 = F_60 ( V_203 , 0 ) ;
F_90 ( & V_203 -> V_9 ) ;
F_91 ( & V_2 -> V_197 ) ;
V_194 -> V_220 = NULL ;
V_194 -> V_221 = NULL ;
V_194 -> V_196 = NULL ;
V_194 -> V_218 = NULL ;
F_79 ( V_151 , V_2 ) ;
F_92 ( & V_2 -> V_166 ) ;
F_80 ( & V_203 -> V_9 ) ;
F_81 ( & V_203 -> V_9 ) ;
F_84 ( V_2 -> V_107 ) ;
F_85 ( V_2 -> V_107 ) ;
F_82 ( V_2 -> V_5 ) ;
F_83 ( V_205 -> V_213 , F_69 ( V_205 ) ) ;
F_86 ( & V_2 -> V_185 ) ;
F_87 ( V_2 ) ;
return 0 ;
}
static int T_4 F_93 ( void )
{
return F_94 ( & V_229 , F_58 ) ;
}
static void T_5 F_95 ( void )
{
F_96 ( & V_229 ) ;
}
