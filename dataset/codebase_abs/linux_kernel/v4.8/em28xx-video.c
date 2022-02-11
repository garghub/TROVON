static inline unsigned int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
if ( V_2 -> V_5 . V_6 )
return V_4 -> V_7 ;
if ( V_2 -> V_5 . V_8 )
return 640 ;
return 720 ;
}
static inline unsigned int F_2 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
if ( V_2 -> V_5 . V_6 )
return V_4 -> V_9 ;
if ( V_2 -> V_5 . V_8 )
return 480 ;
return ( V_4 -> V_10 & V_11 ) ? 576 : 480 ;
}
static int F_3 ( struct V_1 * V_2 )
{
if ( V_12 == 1 )
return 0 ;
if ( V_2 -> V_5 . V_6 )
return 0 ;
if ( V_2 -> V_13 == V_14 ||
V_2 -> V_13 == V_15 )
return 1 ;
return 0 ;
}
static void F_4 ( struct V_1 * V_2 )
{
struct V_16 * V_17 = & V_2 -> V_4 -> V_17 ;
F_5 ( V_17 , 0 , V_18 , V_19 , 0 ) ;
F_5 ( V_17 , 0 , V_20 , V_21 ,
F_6 ( V_2 -> V_22 ) -> V_23 , 0 , 0 ) ;
}
static int F_7 ( struct V_1 * V_2 )
{
F_8 ( V_2 , V_24 , V_25 ) ;
F_8 ( V_2 , V_26 , V_27 ) ;
F_8 ( V_2 , V_28 , V_29 ) ;
F_8 ( V_2 , V_30 , V_31 ) ;
F_8 ( V_2 , V_32 , V_33 ) ;
F_8 ( V_2 , V_34 , V_35 ) ;
F_8 ( V_2 , V_36 , 0x20 ) ;
F_8 ( V_2 , V_37 , 0x20 ) ;
F_8 ( V_2 , V_38 , 0x20 ) ;
F_8 ( V_2 , V_39 , 0x20 ) ;
F_8 ( V_2 , V_40 , 0x00 ) ;
F_8 ( V_2 , V_41 , 0x00 ) ;
return F_8 ( V_2 , V_42 , 0x00 ) ;
}
static int F_9 ( struct V_1 * V_2 )
{
int V_43 ;
T_1 V_44 , V_45 ;
struct V_3 * V_4 = V_2 -> V_4 ;
V_44 = V_4 -> V_46 -> V_47 ;
if ( ! V_2 -> V_48 )
V_44 |= 0x20 ;
V_43 = F_8 ( V_2 , V_49 , V_44 ) ;
if ( V_43 < 0 )
return V_43 ;
V_43 = F_8 ( V_2 , V_50 , V_4 -> V_51 ) ;
if ( V_43 < 0 )
return V_43 ;
V_45 = V_4 -> V_52 ;
if ( F_3 ( V_2 ) == 1 ) {
V_45 |= V_53 ;
F_8 ( V_2 , V_54 , 0x00 ) ;
F_8 ( V_2 , V_55 , V_4 -> V_56 / 4 ) ;
F_8 ( V_2 , V_57 , V_4 -> V_58 ) ;
if ( V_4 -> V_10 & V_59 ) {
F_8 ( V_2 , V_60 , 0x09 ) ;
} else if ( V_4 -> V_10 & V_11 ) {
F_8 ( V_2 , V_60 , 0x07 ) ;
}
}
return F_8 ( V_2 , V_61 , V_45 ) ;
}
static int F_10 ( struct V_1 * V_2 , T_1 V_62 , T_1 V_63 ,
T_1 V_64 , T_1 V_65 )
{
F_11 ( L_1 ,
V_62 , V_64 , V_63 , V_65 ) ;
F_12 ( V_2 , V_66 , & V_62 , 1 ) ;
F_12 ( V_2 , V_67 , & V_63 , 1 ) ;
F_12 ( V_2 , V_68 , & V_64 , 1 ) ;
return F_12 ( V_2 , V_69 , & V_65 , 1 ) ;
}
static void F_13 ( struct V_1 * V_2 , T_1 V_70 , T_1 V_71 ,
T_2 V_72 , T_2 V_73 )
{
T_1 V_74 = V_72 >> 2 ;
T_1 V_75 = V_73 >> 2 ;
T_1 V_76 = ( V_73 >> 9 & 0x02 ) | ( V_72 >> 10 & 0x01 ) ;
F_11 ( L_2 ,
V_70 , V_71 ,
( ( V_76 & 2 ) << 9 | V_74 << 2 ) ,
( ( V_76 & 1 ) << 10 | V_75 << 2 ) ) ;
F_12 ( V_2 , V_77 , & V_70 , 1 ) ;
F_12 ( V_2 , V_78 , & V_71 , 1 ) ;
F_12 ( V_2 , V_79 , & V_74 , 1 ) ;
F_12 ( V_2 , V_80 , & V_75 , 1 ) ;
F_12 ( V_2 , V_81 , & V_76 , 1 ) ;
if ( V_2 -> V_48 ) {
F_8 ( V_2 , 0x34 , V_72 >> 4 ) ;
F_8 ( V_2 , 0x35 , V_73 >> 4 ) ;
}
}
static int F_14 ( struct V_1 * V_2 , T_2 V_82 , T_2 V_83 )
{
T_1 V_84 = 0x00 ;
if ( V_2 -> V_5 . V_85 ) {
V_84 = ( V_83 ? 0x20 : 0x00 ) | ( V_82 ? 0x10 : 0x00 ) ;
} else {
T_1 V_86 [ 2 ] ;
V_86 [ 0 ] = V_82 ;
V_86 [ 1 ] = V_82 >> 8 ;
F_12 ( V_2 , V_87 , ( char * ) V_86 , 2 ) ;
V_86 [ 0 ] = V_83 ;
V_86 [ 1 ] = V_83 >> 8 ;
F_12 ( V_2 , V_88 , ( char * ) V_86 , 2 ) ;
V_84 = ( V_82 || V_83 ) ? 0x30 : 0x00 ;
}
return F_8 ( V_2 , V_89 , V_84 ) ;
}
static int F_15 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
int V_72 = F_1 ( V_2 ) ;
int V_73 = F_2 ( V_2 ) ;
V_4 -> V_56 = 720 ;
if ( V_4 -> V_10 & V_59 )
V_4 -> V_58 = 12 ;
else
V_4 -> V_58 = 18 ;
F_9 ( V_2 ) ;
F_10 ( V_2 , 1 , ( V_72 - 4 ) >> 2 , 1 , ( V_73 - 4 ) >> 2 ) ;
if ( F_3 ( V_2 ) == 1 )
F_13 ( V_2 , 0 , 2 , V_72 , V_73 ) ;
else
F_13 ( V_2 , 0 , 0 , V_72 , V_73 ) ;
return F_14 ( V_2 , V_4 -> V_90 , V_4 -> V_91 ) ;
}
static int F_16 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
int V_92 ;
int V_93 ;
unsigned int V_94 = V_4 -> V_72 * 2 + 4 ;
V_2 -> V_95 = 0 ;
if ( ( V_95 > 0 ) && ( V_95 < V_2 -> V_96 ) ) {
F_11 ( L_3 , V_2 -> V_95 ) ;
V_2 -> V_95 = V_95 ;
goto V_97;
}
if ( V_2 -> V_98 )
goto V_97;
if ( V_4 -> V_72 * 2 * V_4 -> V_73 > 720 * 240 * 2 )
V_94 *= 2 ;
for ( V_93 = 0 ; V_93 < V_2 -> V_96 ; V_93 ++ ) {
if ( V_2 -> V_99 [ V_93 ] >= V_94 ) {
V_2 -> V_95 = V_93 ;
break;
} else if ( V_2 -> V_99 [ V_93 ] >
V_2 -> V_99 [ V_2 -> V_95 ] )
V_2 -> V_95 = V_93 ;
}
V_97:
if ( V_2 -> V_98 ) {
V_2 -> V_100 = 512 ;
V_2 -> V_101 = V_102 ;
} else {
F_11 ( L_4 ,
V_94 , V_2 -> V_95 ) ;
V_2 -> V_100 =
V_2 -> V_99 [ V_2 -> V_95 ] ;
V_2 -> V_101 = V_103 ;
}
F_11 ( L_5 ,
V_2 -> V_95 , V_2 -> V_100 ) ;
V_92 = F_17 ( V_2 -> V_104 , V_2 -> V_105 , V_2 -> V_95 ) ;
if ( V_92 < 0 ) {
F_18 ( L_6 ,
V_2 -> V_95 , V_92 ) ;
return V_92 ;
}
return 0 ;
}
static inline void F_19 ( struct V_1 * V_2 ,
struct V_106 * V_86 )
{
F_20 ( L_7 , V_86 , V_86 -> V_107 ) ;
V_86 -> V_108 . V_109 = V_2 -> V_4 -> V_110 ++ ;
if ( V_2 -> V_4 -> V_111 )
V_86 -> V_108 . V_112 = V_113 ;
else
V_86 -> V_108 . V_112 = V_114 ;
V_86 -> V_108 . V_115 . V_116 = F_21 () ;
F_22 ( & V_86 -> V_108 . V_115 , V_117 ) ;
}
static void F_23 ( struct V_1 * V_2 ,
struct V_106 * V_86 ,
unsigned char * V_118 ,
unsigned long V_119 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
void * V_120 , * V_121 , * V_122 ;
int V_123 , V_124 , V_125 , V_126 , V_127 ;
int V_128 = V_4 -> V_72 << 1 ;
if ( V_86 -> V_129 + V_119 > V_86 -> V_130 )
V_119 = V_86 -> V_130 - V_86 -> V_129 ;
V_122 = V_118 ;
V_127 = V_119 ;
if ( V_4 -> V_111 || V_86 -> V_107 )
V_120 = V_86 -> V_131 ;
else
V_120 = V_86 -> V_131 + V_128 ;
V_123 = V_86 -> V_129 / V_128 ;
V_124 = V_86 -> V_129 % V_128 ;
if ( V_4 -> V_111 )
V_125 = V_123 * V_128 + V_124 ;
else
V_125 = V_123 * V_128 * 2 + V_124 ;
V_121 = V_120 + V_125 ;
V_126 = V_128 - V_124 ;
V_126 = V_126 > V_127 ? V_127 : V_126 ;
if ( ( char * ) V_121 + V_126 > ( char * ) V_86 -> V_131 + V_86 -> V_130 ) {
F_20 ( L_8 ,
( ( char * ) V_121 + V_126 ) -
( ( char * ) V_86 -> V_131 + V_86 -> V_130 ) ) ;
V_127 = ( char * ) V_86 -> V_131 + V_86 -> V_130 -
( char * ) V_121 ;
V_126 = V_127 ;
}
if ( V_126 <= 0 )
return;
memcpy ( V_121 , V_122 , V_126 ) ;
V_127 -= V_126 ;
while ( V_127 > 0 ) {
if ( V_4 -> V_111 )
V_121 += V_126 ;
else
V_121 += V_126 + V_128 ;
V_122 += V_126 ;
if ( V_128 > V_127 )
V_126 = V_127 ;
else
V_126 = V_128 ;
if ( ( char * ) V_121 + V_126 > ( char * ) V_86 -> V_131 +
V_86 -> V_130 ) {
F_20 ( L_9
L_10 ,
( ( char * ) V_121 + V_126 ) -
( ( char * ) V_86 -> V_131 + V_86 -> V_130 ) ) ;
V_126 = V_127 = ( char * ) V_86 -> V_131 + V_86 -> V_130 -
( char * ) V_121 ;
}
if ( V_126 <= 0 )
break;
memcpy ( V_121 , V_122 , V_126 ) ;
V_127 -= V_126 ;
}
V_86 -> V_129 += V_119 ;
}
static void F_24 ( struct V_1 * V_2 ,
struct V_106 * V_86 ,
unsigned char * V_118 ,
unsigned long V_119 )
{
unsigned int V_125 ;
if ( V_86 -> V_129 + V_119 > V_86 -> V_130 )
V_119 = V_86 -> V_130 - V_86 -> V_129 ;
V_125 = V_86 -> V_129 ;
if ( V_86 -> V_107 == 0 )
V_125 += V_2 -> V_4 -> V_56 * V_2 -> V_4 -> V_58 ;
memcpy ( V_86 -> V_131 + V_125 , V_118 , V_119 ) ;
V_86 -> V_129 += V_119 ;
}
static inline void F_25 ( struct V_1 * V_2 ,
int V_132 , int V_133 )
{
char * V_134 = L_11 ;
switch ( V_133 ) {
case - V_135 :
V_134 = L_12 ;
break;
case - V_136 :
V_134 = L_13 ;
break;
case - V_137 :
V_134 = L_14 ;
break;
case - V_138 :
V_134 = L_15 ;
break;
case - V_139 :
V_134 = L_16 ;
break;
case - V_140 :
V_134 = L_17 ;
break;
case - V_141 :
V_134 = L_18 ;
break;
case - V_142 :
V_134 = L_19 ;
break;
}
if ( V_132 < 0 ) {
F_20 ( L_20 , V_133 , V_134 ) ;
} else {
F_20 ( L_21 ,
V_132 , V_133 , V_134 ) ;
}
}
static inline struct V_106 * F_26 ( struct V_1 * V_2 ,
struct V_143 * V_144 )
{
struct V_106 * V_86 ;
if ( F_27 ( & V_144 -> V_145 ) ) {
F_20 ( L_22 ) ;
return NULL ;
}
V_86 = F_28 ( V_144 -> V_145 . V_146 , struct V_106 , V_147 ) ;
F_29 ( & V_86 -> V_147 ) ;
V_86 -> V_129 = 0 ;
V_86 -> V_131 = V_86 -> V_148 ;
return V_86 ;
}
static struct V_106 *
F_30 ( struct V_1 * V_2 ,
struct V_106 * V_86 ,
struct V_143 * V_144 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
if ( V_4 -> V_111 || V_4 -> V_107 ) {
if ( V_86 != NULL )
F_19 ( V_2 , V_86 ) ;
V_86 = F_26 ( V_2 , V_144 ) ;
}
if ( V_86 != NULL ) {
V_86 -> V_107 = V_4 -> V_107 ;
V_86 -> V_129 = 0 ;
}
return V_86 ;
}
static inline void F_31 ( struct V_1 * V_2 ,
unsigned char * V_149 ,
unsigned int V_150 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_106 * V_86 = V_2 -> V_151 . V_152 ;
struct V_106 * V_153 = V_2 -> V_151 . V_153 ;
struct V_143 * V_144 = & V_2 -> V_154 ;
struct V_143 * V_155 = & V_2 -> V_156 ;
if ( V_150 >= 4 ) {
if ( V_149 [ 0 ] == 0x88 && V_149 [ 1 ] == 0x88 &&
V_149 [ 2 ] == 0x88 && V_149 [ 3 ] == 0x88 ) {
V_149 += 4 ;
V_150 -= 4 ;
} else if ( V_149 [ 0 ] == 0x33 && V_149 [ 1 ] == 0x95 ) {
V_4 -> V_157 = 0 ;
V_4 -> V_158 = 0 ;
F_20 ( L_23 ) ;
V_4 -> V_107 = ! ( V_149 [ 2 ] & 1 ) ;
V_149 += 4 ;
V_150 -= 4 ;
} else if ( V_149 [ 0 ] == 0x22 && V_149 [ 1 ] == 0x5a ) {
V_4 -> V_157 = 2 ;
F_20 ( L_24 ) ;
V_4 -> V_107 = ! ( V_149 [ 2 ] & 1 ) ;
V_149 += 4 ;
V_150 -= 4 ;
}
}
if ( V_4 -> V_157 == 0 ) {
V_153 = F_30 ( V_2 , V_153 , V_155 ) ;
V_2 -> V_151 . V_153 = V_153 ;
V_4 -> V_157 = 1 ;
}
if ( V_4 -> V_157 == 1 ) {
int V_159 = V_4 -> V_56 * V_4 -> V_58 ;
int V_160 = ( ( V_4 -> V_158 + V_150 ) > V_159 ) ?
( V_159 - V_4 -> V_158 ) : V_150 ;
if ( V_153 != NULL )
F_24 ( V_2 , V_153 , V_149 , V_160 ) ;
V_4 -> V_158 += V_160 ;
if ( V_160 < V_150 ) {
V_4 -> V_157 = 2 ;
V_149 += V_160 ;
V_150 -= V_160 ;
}
}
if ( V_4 -> V_157 == 2 ) {
V_86 = F_30 ( V_2 , V_86 , V_144 ) ;
V_2 -> V_151 . V_152 = V_86 ;
V_4 -> V_157 = 3 ;
}
if ( V_4 -> V_157 == 3 && V_86 != NULL && V_150 > 0 )
F_23 ( V_2 , V_86 , V_149 , V_150 ) ;
}
static inline void F_32 ( struct V_1 * V_2 ,
unsigned char * V_149 ,
unsigned int V_150 )
{
struct V_106 * V_86 = V_2 -> V_151 . V_152 ;
struct V_143 * V_161 = & V_2 -> V_154 ;
struct V_3 * V_4 = V_2 -> V_4 ;
bool V_162 = false ;
if ( V_150 >= 2 ) {
if ( ( V_149 [ 0 ] == V_163 ) &&
( ( V_149 [ 1 ] & ~ V_164 ) == 0x00 ) ) {
V_4 -> V_107 = ! ( V_149 [ 1 ] &
V_165 ) ;
V_162 = V_149 [ 1 ] &
V_166 ;
V_149 += 2 ;
V_150 -= 2 ;
}
if ( V_2 -> V_98 && V_162 ) {
V_86 = F_30 ( V_2 , V_86 , V_161 ) ;
V_2 -> V_151 . V_152 = V_86 ;
}
}
if ( V_86 != NULL && V_150 > 0 )
F_23 ( V_2 , V_86 , V_149 , V_150 ) ;
if ( ! V_2 -> V_98 && V_162 ) {
V_86 = F_30 ( V_2 , V_86 , V_161 ) ;
V_2 -> V_151 . V_152 = V_86 ;
}
}
static inline int F_33 ( struct V_1 * V_2 , struct V_167 * V_167 )
{
int V_168 , V_169 , V_93 ;
unsigned char * V_170 ;
unsigned int V_171 ;
if ( ! V_2 )
return 0 ;
if ( V_2 -> V_172 )
return 0 ;
if ( V_167 -> V_133 < 0 )
F_25 ( V_2 , - 1 , V_167 -> V_133 ) ;
V_168 = F_34 ( V_167 -> V_173 ) ;
if ( V_168 )
V_169 = 1 ;
else
V_169 = V_167 -> V_174 ;
for ( V_93 = 0 ; V_93 < V_169 ; V_93 ++ ) {
if ( V_168 ) {
V_171 = V_167 -> V_175 ;
V_170 = V_167 -> V_176 ;
} else {
if ( V_167 -> V_177 [ V_93 ] . V_133 < 0 ) {
F_25 ( V_2 , V_93 ,
V_167 -> V_177 [ V_93 ] . V_133 ) ;
if ( V_167 -> V_177 [ V_93 ] . V_133 != - V_140 )
continue;
}
V_171 = V_167 -> V_177 [ V_93 ] . V_175 ;
if ( V_171 > V_2 -> V_100 ) {
F_20 ( L_25 ) ;
continue;
}
V_170 = V_167 -> V_176 +
V_167 -> V_177 [ V_93 ] . V_125 ;
}
if ( V_171 == 0 ) {
continue;
}
if ( V_2 -> V_48 )
F_32 ( V_2 ,
V_170 , V_171 ) ;
else
F_31 ( V_2 ,
V_170 , V_171 ) ;
}
return 1 ;
}
static int F_35 ( enum V_178 V_179 )
{
switch ( V_179 ) {
case V_180 :
return V_181 ;
case V_182 :
return V_183 ;
default:
F_36 () ;
}
}
static int F_37 ( struct V_1 * V_2 , enum V_178 V_179 )
{
int V_184 = F_35 ( V_179 ) ;
if ( V_2 -> V_185 & V_184 ) {
return - V_186 ;
}
V_2 -> V_185 |= V_184 ;
F_11 ( L_26 , V_184 ) ;
return 0 ;
}
static void F_38 ( struct V_1 * V_2 , enum V_178 V_179 )
{
int V_184 = F_35 ( V_179 ) ;
V_2 -> V_185 &= ~ V_184 ;
F_11 ( L_27 , V_184 ) ;
}
static void F_39 ( struct V_1 * V_2 )
{
#ifdef F_40
int V_93 ;
for ( V_93 = 0 ; V_93 < V_187 ; V_93 ++ ) {
if ( ! F_6 ( V_93 ) -> type )
return;
F_41 ( & V_2 -> V_188 [ V_93 ] ) ;
}
#endif
}
static int F_42 ( struct V_1 * V_2 )
{
#ifdef F_40
struct V_189 * V_190 = V_2 -> V_191 ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_192 * V_193 ;
struct V_194 * V_195 , * V_196 = NULL ;
int V_43 , V_197 = 0 ;
if ( ! V_190 || ! V_4 -> V_198 )
return 0 ;
F_43 (link, &v4l2->decoder->links, list) {
if ( V_195 -> V_199 -> V_200 == V_4 -> V_198 ) {
V_196 = V_195 ;
if ( V_195 -> V_201 & V_202 )
V_197 ++ ;
break;
}
}
if ( V_197 == 1 || ! V_196 )
return 0 ;
V_193 = V_196 -> V_193 -> V_200 ;
F_43 (link, &source->links, list) {
struct V_192 * V_199 ;
int V_201 = 0 ;
V_199 = V_195 -> V_199 -> V_200 ;
if ( V_199 == V_4 -> V_198 )
V_201 = V_202 ;
V_43 = F_44 ( V_195 , V_201 ) ;
if ( V_43 ) {
F_45 ( L_28 ,
V_193 -> V_203 , V_199 -> V_203 ,
V_201 ? L_29 : L_30 ,
V_43 ) ;
return V_43 ;
} else
F_11 ( L_31 ,
V_193 -> V_203 , V_199 -> V_203 ,
V_201 ? L_32 : L_30 ) ;
}
#endif
return 0 ;
}
static void F_46 ( struct V_1 * V_2 )
{
#if F_47 ( F_40 )
struct V_3 * V_4 = V_2 -> V_4 ;
int V_43 , V_93 ;
V_4 -> V_204 . V_201 = V_205 ;
V_43 = F_48 ( & V_4 -> V_206 . V_200 , 1 , & V_4 -> V_204 ) ;
if ( V_43 < 0 )
F_45 ( L_33 ) ;
if ( F_3 ( V_2 ) ) {
V_4 -> V_207 . V_201 = V_205 ;
V_43 = F_48 ( & V_4 -> V_208 . V_200 , 1 ,
& V_4 -> V_207 ) ;
if ( V_43 < 0 )
F_45 ( L_34 ) ;
}
if ( V_2 -> V_5 . V_6 )
return;
for ( V_93 = 0 ; V_93 < V_187 ; V_93 ++ ) {
struct V_192 * V_209 = & V_2 -> V_188 [ V_93 ] ;
if ( ! F_6 ( V_93 ) -> type )
break;
V_209 -> V_203 = V_210 [ F_6 ( V_93 ) -> type ] ;
V_209 -> V_201 = V_211 ;
V_2 -> V_212 [ V_93 ] . V_201 = V_213 ;
switch ( F_6 ( V_93 ) -> type ) {
case V_214 :
V_209 -> V_215 = V_216 ;
break;
case V_217 :
V_209 -> V_215 = V_218 ;
break;
default:
if ( V_2 -> V_219 != V_220 )
V_209 -> V_215 = V_221 ;
break;
}
V_43 = F_48 ( V_209 , 1 , & V_2 -> V_212 [ V_93 ] ) ;
if ( V_43 < 0 )
F_45 ( L_35 , V_93 ) ;
V_43 = F_49 ( V_2 -> V_191 , V_209 ) ;
if ( V_43 < 0 )
F_45 ( L_36 , V_93 ) ;
}
#endif
}
static int F_50 ( struct V_222 * V_223 ,
unsigned int * V_224 , unsigned int * V_225 ,
unsigned int V_226 [] , struct V_227 * V_228 [] )
{
struct V_1 * V_2 = F_51 ( V_223 ) ;
struct V_3 * V_4 = V_2 -> V_4 ;
unsigned long V_229 =
( V_4 -> V_72 * V_4 -> V_73 * V_4 -> V_46 -> V_230 + 7 ) >> 3 ;
if ( * V_225 )
return V_226 [ 0 ] < V_229 ? - V_231 : 0 ;
* V_225 = 1 ;
V_226 [ 0 ] = V_229 ;
F_42 ( V_2 ) ;
return 0 ;
}
static int
F_52 ( struct V_232 * V_108 )
{
struct V_233 * V_234 = F_53 ( V_108 ) ;
struct V_1 * V_2 = F_51 ( V_108 -> V_222 ) ;
struct V_3 * V_4 = V_2 -> V_4 ;
unsigned long V_229 ;
F_11 ( L_37 , V_235 , V_234 -> V_112 ) ;
V_229 = ( V_4 -> V_72 * V_4 -> V_73 * V_4 -> V_46 -> V_230 + 7 ) >> 3 ;
if ( F_54 ( V_108 , 0 ) < V_229 ) {
F_11 ( L_38 ,
V_235 , F_54 ( V_108 , 0 ) , V_229 ) ;
return - V_231 ;
}
F_55 ( V_108 , 0 , V_229 ) ;
return 0 ;
}
int F_56 ( struct V_222 * V_223 , unsigned int V_236 )
{
struct V_1 * V_2 = F_51 ( V_223 ) ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_237 V_238 ;
struct V_239 * V_240 ;
int V_241 = 0 ;
F_11 ( L_39 , V_235 ) ;
V_241 = F_37 ( V_2 , V_223 -> type ) ;
if ( V_241 )
return V_241 ;
if ( V_4 -> V_242 == 0 ) {
F_16 ( V_2 ) ;
F_4 ( V_2 ) ;
V_4 -> V_157 = - 1 ;
V_241 = F_57 ( V_2 , V_243 ,
V_2 -> V_98 ,
V_244 ,
V_2 -> V_100 ,
V_2 -> V_101 ,
F_33 ) ;
if ( V_241 < 0 )
return V_241 ;
memset ( & V_238 , 0 , sizeof( V_238 ) ) ;
V_238 . V_245 = V_4 -> V_245 ;
V_240 = (struct V_239 * ) V_223 -> V_240 ;
if ( V_240 && V_240 -> V_206 -> V_246 == V_247 )
V_238 . type = V_248 ;
else
V_238 . type = V_249 ;
F_5 ( & V_4 -> V_17 ,
0 , V_250 , V_251 , & V_238 ) ;
F_5 ( & V_4 -> V_17 , 0 , V_20 , V_252 , 1 ) ;
}
V_4 -> V_242 ++ ;
return V_241 ;
}
static void F_58 ( struct V_222 * V_223 )
{
struct V_1 * V_2 = F_51 ( V_223 ) ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_143 * V_154 = & V_2 -> V_154 ;
unsigned long V_201 = 0 ;
F_11 ( L_39 , V_235 ) ;
F_38 ( V_2 , V_223 -> type ) ;
if ( V_4 -> V_242 -- == 1 ) {
F_5 ( & V_4 -> V_17 , 0 , V_20 , V_252 , 0 ) ;
F_59 ( V_2 , V_243 ) ;
}
F_60 ( & V_2 -> V_253 , V_201 ) ;
if ( V_2 -> V_151 . V_152 != NULL ) {
F_22 ( & V_2 -> V_151 . V_152 -> V_108 . V_115 ,
V_254 ) ;
V_2 -> V_151 . V_152 = NULL ;
}
while ( ! F_27 ( & V_154 -> V_145 ) ) {
struct V_106 * V_86 ;
V_86 = F_28 ( V_154 -> V_145 . V_146 , struct V_106 , V_147 ) ;
F_29 ( & V_86 -> V_147 ) ;
F_22 ( & V_86 -> V_108 . V_115 , V_254 ) ;
}
F_61 ( & V_2 -> V_253 , V_201 ) ;
}
void F_62 ( struct V_222 * V_223 )
{
struct V_1 * V_2 = F_51 ( V_223 ) ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_143 * V_156 = & V_2 -> V_156 ;
unsigned long V_201 = 0 ;
F_11 ( L_39 , V_235 ) ;
F_38 ( V_2 , V_223 -> type ) ;
if ( V_4 -> V_242 -- == 1 ) {
F_5 ( & V_4 -> V_17 , 0 , V_20 , V_252 , 0 ) ;
F_59 ( V_2 , V_243 ) ;
}
F_60 ( & V_2 -> V_253 , V_201 ) ;
if ( V_2 -> V_151 . V_153 != NULL ) {
F_22 ( & V_2 -> V_151 . V_153 -> V_108 . V_115 ,
V_254 ) ;
V_2 -> V_151 . V_153 = NULL ;
}
while ( ! F_27 ( & V_156 -> V_145 ) ) {
struct V_106 * V_86 ;
V_86 = F_28 ( V_156 -> V_145 . V_146 , struct V_106 , V_147 ) ;
F_29 ( & V_86 -> V_147 ) ;
F_22 ( & V_86 -> V_108 . V_115 , V_254 ) ;
}
F_61 ( & V_2 -> V_253 , V_201 ) ;
}
static void
F_63 ( struct V_232 * V_108 )
{
struct V_233 * V_234 = F_53 ( V_108 ) ;
struct V_1 * V_2 = F_51 ( V_108 -> V_222 ) ;
struct V_106 * V_86 =
F_64 ( V_234 , struct V_106 , V_108 ) ;
struct V_143 * V_154 = & V_2 -> V_154 ;
unsigned long V_201 = 0 ;
F_11 ( L_39 , V_235 ) ;
V_86 -> V_148 = F_65 ( V_108 , 0 ) ;
V_86 -> V_130 = F_54 ( V_108 , 0 ) ;
F_60 ( & V_2 -> V_253 , V_201 ) ;
F_66 ( & V_86 -> V_147 , & V_154 -> V_145 ) ;
F_61 ( & V_2 -> V_253 , V_201 ) ;
}
static int F_67 ( struct V_1 * V_2 )
{
int V_241 ;
struct V_222 * V_255 ;
struct V_3 * V_4 = V_2 -> V_4 ;
V_255 = & V_4 -> V_256 ;
V_255 -> type = V_180 ;
V_255 -> V_257 = V_258 | V_259 | V_260 | V_261 ;
V_255 -> V_262 = V_263 ;
V_255 -> V_264 = V_2 ;
V_255 -> V_265 = sizeof( struct V_106 ) ;
V_255 -> V_266 = & V_267 ;
V_255 -> V_268 = & V_269 ;
V_241 = F_68 ( V_255 ) ;
if ( V_241 < 0 )
return V_241 ;
V_255 = & V_4 -> V_270 ;
V_255 -> type = V_182 ;
V_255 -> V_257 = V_258 | V_259 | V_260 ;
V_255 -> V_262 = V_263 ;
V_255 -> V_264 = V_2 ;
V_255 -> V_265 = sizeof( struct V_106 ) ;
V_255 -> V_266 = & V_271 ;
V_255 -> V_268 = & V_269 ;
V_241 = F_68 ( V_255 ) ;
if ( V_241 < 0 )
return V_241 ;
return 0 ;
}
static void F_69 ( struct V_1 * V_2 , int V_272 )
{
struct V_16 * V_17 = & V_2 -> V_4 -> V_17 ;
V_2 -> V_22 = V_272 ;
V_2 -> V_273 = F_6 ( V_272 ) -> V_274 ;
V_2 -> V_275 = F_6 ( V_272 ) -> V_276 ;
if ( ! V_2 -> V_275 )
V_2 -> V_275 = V_277 ;
F_5 ( V_17 , 0 , V_20 , V_21 ,
F_6 ( V_272 ) -> V_23 , 0 , 0 ) ;
if ( V_2 -> V_5 . V_278 ) {
if ( V_2 -> V_279 ) {
F_5 ( V_17 , 0 , V_280 ,
V_281 , V_2 -> V_279 ) ;
}
F_5 ( V_17 , 0 , V_280 , V_21 ,
V_2 -> V_273 ,
F_70 ( V_282 ) , 0 ) ;
}
if ( V_2 -> V_5 . V_283 != V_284 ) {
F_5 ( V_17 , 0 , V_280 , V_21 ,
V_2 -> V_273 , V_2 -> V_275 , 0 ) ;
}
F_71 ( V_2 ) ;
}
static void F_72 ( struct V_285 * V_286 , void * V_287 )
{
struct V_1 * V_2 = V_287 ;
switch ( V_286 -> V_288 ) {
case V_289 :
V_2 -> V_290 = V_286 -> V_291 ;
F_71 ( V_2 ) ;
break;
case V_292 :
V_2 -> V_293 = V_286 -> V_291 ;
F_71 ( V_2 ) ;
break;
}
}
static int F_73 ( struct V_285 * V_286 )
{
struct V_3 * V_4 =
F_64 ( V_286 -> V_294 , struct V_3 , V_295 ) ;
struct V_1 * V_2 = V_4 -> V_2 ;
int V_43 = - V_231 ;
switch ( V_286 -> V_288 ) {
case V_289 :
V_2 -> V_290 = V_286 -> V_291 ;
V_43 = F_71 ( V_2 ) ;
break;
case V_292 :
V_2 -> V_293 = V_286 -> V_291 ;
V_43 = F_71 ( V_2 ) ;
break;
case V_296 :
V_43 = F_8 ( V_2 , V_24 , V_286 -> V_291 ) ;
break;
case V_297 :
V_43 = F_8 ( V_2 , V_26 , V_286 -> V_291 ) ;
break;
case V_298 :
V_43 = F_8 ( V_2 , V_28 , V_286 -> V_291 ) ;
break;
case V_299 :
V_43 = F_8 ( V_2 , V_30 , V_286 -> V_291 ) ;
break;
case V_300 :
V_43 = F_8 ( V_2 , V_32 , V_286 -> V_291 ) ;
break;
case V_301 :
V_43 = F_8 ( V_2 , V_34 , V_286 -> V_291 ) ;
break;
}
return ( V_43 < 0 ) ? V_43 : 0 ;
}
static void F_74 ( struct V_1 * V_2 ,
unsigned int V_72 , unsigned int V_73 ,
unsigned int * V_90 , unsigned int * V_91 )
{
unsigned int V_302 = F_1 ( V_2 ) ;
unsigned int V_303 = F_2 ( V_2 ) ;
* V_90 = ( ( ( unsigned long ) V_302 ) << 12 ) / V_72 - 4096L ;
if ( * V_90 > V_304 )
* V_90 = V_304 ;
* V_91 = ( ( ( unsigned long ) V_303 ) << 12 ) / V_73 - 4096L ;
if ( * V_91 > V_304 )
* V_91 = V_304 ;
}
static void F_75 ( struct V_1 * V_2 ,
unsigned int V_90 , unsigned int V_91 ,
unsigned int * V_72 , unsigned int * V_73 )
{
unsigned int V_302 = F_1 ( V_2 ) ;
unsigned int V_303 = F_2 ( V_2 ) ;
* V_72 = ( ( ( unsigned long ) V_302 ) << 12 ) / ( V_90 + 4096L ) ;
* V_73 = ( ( ( unsigned long ) V_303 ) << 12 ) / ( V_91 + 4096L ) ;
if ( * V_72 < 1 )
* V_72 = 1 ;
if ( * V_73 < 1 )
* V_73 = 1 ;
}
static int F_76 ( struct V_305 * V_305 , void * V_287 ,
struct V_306 * V_238 )
{
struct V_1 * V_2 = F_77 ( V_305 ) ;
struct V_3 * V_4 = V_2 -> V_4 ;
V_238 -> V_44 . V_307 . V_72 = V_4 -> V_72 ;
V_238 -> V_44 . V_307 . V_73 = V_4 -> V_73 ;
V_238 -> V_44 . V_307 . V_308 = V_4 -> V_46 -> V_309 ;
V_238 -> V_44 . V_307 . V_128 = ( V_4 -> V_72 * V_4 -> V_46 -> V_230 + 7 ) >> 3 ;
V_238 -> V_44 . V_307 . V_310 = V_238 -> V_44 . V_307 . V_128 * V_4 -> V_73 ;
V_238 -> V_44 . V_307 . V_311 = V_312 ;
if ( V_4 -> V_111 )
V_238 -> V_44 . V_307 . V_112 = V_113 ;
else
V_238 -> V_44 . V_307 . V_112 = V_4 -> V_313 ?
V_114 : V_314 ;
return 0 ;
}
static struct V_315 * F_78 ( unsigned int V_309 )
{
unsigned int V_93 ;
for ( V_93 = 0 ; V_93 < F_79 ( V_46 ) ; V_93 ++ )
if ( V_46 [ V_93 ] . V_309 == V_309 )
return & V_46 [ V_93 ] ;
return NULL ;
}
static int F_80 ( struct V_305 * V_305 , void * V_287 ,
struct V_306 * V_238 )
{
struct V_1 * V_2 = F_77 ( V_305 ) ;
struct V_3 * V_4 = V_2 -> V_4 ;
unsigned int V_72 = V_238 -> V_44 . V_307 . V_72 ;
unsigned int V_73 = V_238 -> V_44 . V_307 . V_73 ;
unsigned int V_302 = F_1 ( V_2 ) ;
unsigned int V_303 = F_2 ( V_2 ) ;
unsigned int V_90 , V_91 ;
struct V_315 * V_44 ;
V_44 = F_78 ( V_238 -> V_44 . V_307 . V_308 ) ;
if ( ! V_44 ) {
F_11 ( L_40 ,
V_238 -> V_44 . V_307 . V_308 ) ;
return - V_231 ;
}
if ( V_2 -> V_5 . V_85 ) {
V_73 = V_73 > ( 3 * V_303 / 4 ) ? V_303 : V_303 / 2 ;
V_72 = V_72 > ( 3 * V_302 / 4 ) ? V_302 : V_302 / 2 ;
if ( V_72 == V_302 && V_73 == V_303 )
V_72 /= 2 ;
} else {
F_81 ( & V_72 , 48 , V_302 , 1 , & V_73 , 32 , V_303 ,
1 , 0 ) ;
}
if ( V_72 < 1 )
V_72 = 1 ;
if ( V_73 < 1 )
V_73 = 1 ;
F_74 ( V_2 , V_72 , V_73 , & V_90 , & V_91 ) ;
F_75 ( V_2 , V_90 , V_91 , & V_72 , & V_73 ) ;
V_238 -> V_44 . V_307 . V_72 = V_72 ;
V_238 -> V_44 . V_307 . V_73 = V_73 ;
V_238 -> V_44 . V_307 . V_308 = V_44 -> V_309 ;
V_238 -> V_44 . V_307 . V_128 = ( V_72 * V_44 -> V_230 + 7 ) >> 3 ;
V_238 -> V_44 . V_307 . V_310 = V_238 -> V_44 . V_307 . V_128 * V_73 ;
V_238 -> V_44 . V_307 . V_311 = V_312 ;
if ( V_4 -> V_111 )
V_238 -> V_44 . V_307 . V_112 = V_113 ;
else
V_238 -> V_44 . V_307 . V_112 = V_4 -> V_313 ?
V_114 : V_314 ;
V_238 -> V_44 . V_307 . V_287 = 0 ;
return 0 ;
}
static int F_82 ( struct V_1 * V_2 , unsigned int V_309 ,
unsigned V_72 , unsigned V_73 )
{
struct V_315 * V_44 ;
struct V_3 * V_4 = V_2 -> V_4 ;
V_44 = F_78 ( V_309 ) ;
if ( ! V_44 )
return - V_231 ;
V_4 -> V_46 = V_44 ;
V_4 -> V_72 = V_72 ;
V_4 -> V_73 = V_73 ;
F_74 ( V_2 , V_4 -> V_72 , V_4 -> V_73 ,
& V_4 -> V_90 , & V_4 -> V_91 ) ;
F_15 ( V_2 ) ;
return 0 ;
}
static int F_83 ( struct V_305 * V_305 , void * V_287 ,
struct V_306 * V_238 )
{
struct V_1 * V_2 = F_77 ( V_305 ) ;
struct V_3 * V_4 = V_2 -> V_4 ;
if ( F_84 ( & V_4 -> V_256 ) )
return - V_186 ;
F_80 ( V_305 , V_287 , V_238 ) ;
return F_82 ( V_2 , V_238 -> V_44 . V_307 . V_308 ,
V_238 -> V_44 . V_307 . V_72 , V_238 -> V_44 . V_307 . V_73 ) ;
}
static int F_85 ( struct V_305 * V_305 , void * V_287 , T_3 * V_10 )
{
struct V_1 * V_2 = F_77 ( V_305 ) ;
* V_10 = V_2 -> V_4 -> V_10 ;
return 0 ;
}
static int F_86 ( struct V_305 * V_305 , void * V_287 , T_3 * V_10 )
{
struct V_1 * V_2 = F_77 ( V_305 ) ;
F_5 ( & V_2 -> V_4 -> V_17 , 0 , V_20 , V_316 , V_10 ) ;
return 0 ;
}
static int F_87 ( struct V_305 * V_305 , void * V_287 , T_3 V_10 )
{
struct V_1 * V_2 = F_77 ( V_305 ) ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_306 V_238 ;
if ( V_10 == V_4 -> V_10 )
return 0 ;
if ( V_4 -> V_242 > 0 )
return - V_186 ;
V_4 -> V_10 = V_10 ;
V_238 . V_44 . V_307 . V_72 = 720 ;
V_238 . V_44 . V_307 . V_73 = ( V_10 & V_59 ) ? 480 : 576 ;
F_80 ( V_305 , V_287 , & V_238 ) ;
V_4 -> V_72 = V_238 . V_44 . V_307 . V_72 ;
V_4 -> V_73 = V_238 . V_44 . V_307 . V_73 ;
F_74 ( V_2 , V_4 -> V_72 , V_4 -> V_73 ,
& V_4 -> V_90 , & V_4 -> V_91 ) ;
F_15 ( V_2 ) ;
F_5 ( & V_4 -> V_17 , 0 , V_20 , V_317 , V_4 -> V_10 ) ;
return 0 ;
}
static int F_88 ( struct V_305 * V_305 , void * V_287 ,
struct V_318 * V_319 )
{
struct V_1 * V_2 = F_77 ( V_305 ) ;
struct V_3 * V_4 = V_2 -> V_4 ;
int V_241 = 0 ;
V_319 -> V_320 . V_321 . V_322 = V_323 ;
if ( V_2 -> V_5 . V_6 )
V_241 = F_89 ( & V_4 -> V_17 , 0 ,
V_20 , V_324 , V_319 ) ;
else
F_90 ( V_4 -> V_10 ,
& V_319 -> V_320 . V_321 . V_325 ) ;
return V_241 ;
}
static int F_91 ( struct V_305 * V_305 , void * V_287 ,
struct V_318 * V_319 )
{
struct V_1 * V_2 = F_77 ( V_305 ) ;
V_319 -> V_320 . V_321 . V_322 = V_323 ;
return F_89 ( & V_2 -> V_4 -> V_17 ,
0 , V_20 , V_326 , V_319 ) ;
}
static int F_92 ( struct V_305 * V_305 , void * V_287 ,
struct V_327 * V_93 )
{
struct V_1 * V_2 = F_77 ( V_305 ) ;
unsigned int V_328 ;
V_328 = V_93 -> V_272 ;
if ( V_328 >= V_187 )
return - V_231 ;
if ( 0 == F_6 ( V_328 ) -> type )
return - V_231 ;
V_93 -> V_272 = V_328 ;
V_93 -> type = V_329 ;
strcpy ( V_93 -> V_203 , V_210 [ F_6 ( V_328 ) -> type ] ) ;
if ( ( V_330 == F_6 ( V_328 ) -> type ) )
V_93 -> type = V_331 ;
V_93 -> V_332 = V_2 -> V_4 -> V_206 . V_333 ;
if ( V_2 -> V_5 . V_6 )
V_93 -> V_334 = 0 ;
return 0 ;
}
static int F_93 ( struct V_305 * V_305 , void * V_287 , unsigned int * V_93 )
{
struct V_1 * V_2 = F_77 ( V_305 ) ;
* V_93 = V_2 -> V_22 ;
return 0 ;
}
static int F_94 ( struct V_305 * V_305 , void * V_287 , unsigned int V_93 )
{
struct V_1 * V_2 = F_77 ( V_305 ) ;
if ( V_93 >= V_187 )
return - V_231 ;
if ( 0 == F_6 ( V_93 ) -> type )
return - V_231 ;
F_69 ( V_2 , V_93 ) ;
return 0 ;
}
static int F_95 ( struct V_305 * V_305 , void * V_287 , struct V_335 * V_336 )
{
struct V_1 * V_2 = F_77 ( V_305 ) ;
switch ( V_336 -> V_272 ) {
case V_337 :
strcpy ( V_336 -> V_203 , L_41 ) ;
break;
case V_338 :
strcpy ( V_336 -> V_203 , L_42 ) ;
break;
case V_339 :
strcpy ( V_336 -> V_203 , L_43 ) ;
break;
case V_340 :
strcpy ( V_336 -> V_203 , L_44 ) ;
break;
case V_341 :
strcpy ( V_336 -> V_203 , L_45 ) ;
break;
case V_342 :
strcpy ( V_336 -> V_203 , L_46 ) ;
break;
case V_343 :
strcpy ( V_336 -> V_203 , L_47 ) ;
break;
case V_344 :
strcpy ( V_336 -> V_203 , L_48 ) ;
break;
default:
return - V_231 ;
}
V_336 -> V_272 = V_2 -> V_273 ;
V_336 -> V_345 = V_346 ;
return 0 ;
}
static int F_96 ( struct V_305 * V_305 , void * V_287 , const struct V_335 * V_336 )
{
struct V_1 * V_2 = F_77 ( V_305 ) ;
if ( V_336 -> V_272 >= V_187 )
return - V_231 ;
if ( 0 == F_6 ( V_336 -> V_272 ) -> type )
return - V_231 ;
V_2 -> V_273 = F_6 ( V_336 -> V_272 ) -> V_274 ;
V_2 -> V_275 = F_6 ( V_336 -> V_272 ) -> V_276 ;
if ( ! V_2 -> V_275 )
V_2 -> V_275 = V_277 ;
return 0 ;
}
static int F_97 ( struct V_305 * V_305 , void * V_287 ,
struct V_347 * V_348 )
{
struct V_1 * V_2 = F_77 ( V_305 ) ;
if ( 0 != V_348 -> V_272 )
return - V_231 ;
strcpy ( V_348 -> V_203 , L_49 ) ;
F_5 ( & V_2 -> V_4 -> V_17 , 0 , V_250 , V_349 , V_348 ) ;
return 0 ;
}
static int F_98 ( struct V_305 * V_305 , void * V_287 ,
const struct V_347 * V_348 )
{
struct V_1 * V_2 = F_77 ( V_305 ) ;
if ( 0 != V_348 -> V_272 )
return - V_231 ;
F_5 ( & V_2 -> V_4 -> V_17 , 0 , V_250 , V_350 , V_348 ) ;
return 0 ;
}
static int F_99 ( struct V_305 * V_305 , void * V_287 ,
struct V_237 * V_238 )
{
struct V_1 * V_2 = F_77 ( V_305 ) ;
struct V_3 * V_4 = V_2 -> V_4 ;
if ( 0 != V_238 -> V_250 )
return - V_231 ;
V_238 -> V_245 = V_4 -> V_245 ;
return 0 ;
}
static int F_100 ( struct V_305 * V_305 , void * V_287 ,
const struct V_237 * V_238 )
{
struct V_237 V_351 = * V_238 ;
struct V_1 * V_2 = F_77 ( V_305 ) ;
struct V_3 * V_4 = V_2 -> V_4 ;
if ( 0 != V_238 -> V_250 )
return - V_231 ;
F_5 ( & V_4 -> V_17 , 0 , V_250 , V_251 , V_238 ) ;
F_5 ( & V_4 -> V_17 , 0 , V_250 , V_352 , & V_351 ) ;
V_4 -> V_245 = V_351 . V_245 ;
return 0 ;
}
static int F_101 ( struct V_305 * V_305 , void * V_287 ,
struct V_353 * V_354 )
{
struct V_1 * V_2 = F_77 ( V_305 ) ;
if ( V_354 -> V_355 . V_356 > 1 )
return - V_231 ;
if ( V_354 -> V_355 . V_356 == 1 )
F_102 ( V_354 -> V_203 , L_50 , sizeof( V_354 -> V_203 ) ) ;
else
F_102 ( V_354 -> V_203 ,
V_2 -> V_4 -> V_17 . V_203 , sizeof( V_354 -> V_203 ) ) ;
return 0 ;
}
static int F_103 ( int V_47 )
{
switch ( V_47 ) {
case V_357 :
case V_87 :
case V_88 :
return 2 ;
default:
return 1 ;
}
}
static int F_104 ( struct V_305 * V_305 , void * V_287 ,
struct V_358 * V_47 )
{
struct V_1 * V_2 = F_77 ( V_305 ) ;
int V_43 ;
if ( V_47 -> V_355 . V_356 > 1 )
return - V_231 ;
if ( V_47 -> V_355 . V_356 ) {
V_43 = F_105 ( V_2 , V_47 -> V_47 ) ;
if ( V_43 < 0 )
return V_43 ;
V_47 -> V_291 = V_43 ;
V_47 -> V_229 = 1 ;
return 0 ;
}
V_47 -> V_229 = F_103 ( V_47 -> V_47 ) ;
if ( V_47 -> V_229 == 1 ) {
V_43 = F_106 ( V_2 , V_47 -> V_47 ) ;
if ( V_43 < 0 )
return V_43 ;
V_47 -> V_291 = V_43 ;
} else {
T_4 V_291 = 0 ;
V_43 = V_2 -> V_359 ( V_2 , V_360 ,
V_47 -> V_47 , ( char * ) & V_291 , 2 ) ;
if ( V_43 < 0 )
return V_43 ;
V_47 -> V_291 = F_107 ( V_291 ) ;
}
return 0 ;
}
static int F_108 ( struct V_305 * V_305 , void * V_287 ,
const struct V_358 * V_47 )
{
struct V_1 * V_2 = F_77 ( V_305 ) ;
T_4 V_86 ;
if ( V_47 -> V_355 . V_356 > 1 )
return - V_231 ;
if ( V_47 -> V_355 . V_356 )
return F_109 ( V_2 , V_47 -> V_47 , V_47 -> V_291 ) ;
V_86 = F_110 ( V_47 -> V_291 ) ;
return F_12 ( V_2 , V_47 -> V_47 , ( char * ) & V_86 ,
F_103 ( V_47 -> V_47 ) ) ;
}
static int F_111 ( struct V_305 * V_305 , void * V_287 ,
struct V_361 * V_362 )
{
struct V_363 * V_206 = F_112 ( V_305 ) ;
struct V_1 * V_2 = F_77 ( V_305 ) ;
struct V_3 * V_4 = V_2 -> V_4 ;
F_102 ( V_362 -> V_364 , L_51 , sizeof( V_362 -> V_364 ) ) ;
F_102 ( V_362 -> V_365 , V_366 [ V_2 -> V_367 ] . V_203 , sizeof( V_362 -> V_365 ) ) ;
F_113 ( V_2 -> V_104 , V_362 -> V_368 , sizeof( V_362 -> V_368 ) ) ;
if ( V_206 -> V_246 == V_369 )
V_362 -> V_370 = V_371 |
V_372 | V_373 ;
else if ( V_206 -> V_246 == V_247 )
V_362 -> V_370 = V_374 ;
else
V_362 -> V_370 = V_371 | V_375 ;
if ( V_2 -> V_376 != V_377 )
V_362 -> V_370 |= V_378 ;
if ( V_2 -> V_219 != V_220 )
V_362 -> V_370 |= V_379 ;
V_362 -> V_334 = V_362 -> V_370 | V_380 |
V_371 | V_372 | V_373 ;
if ( F_114 ( & V_4 -> V_208 ) )
V_362 -> V_334 |= V_375 ;
if ( F_114 ( & V_4 -> V_381 ) )
V_362 -> V_334 |= V_374 ;
return 0 ;
}
static int F_115 ( struct V_305 * V_305 , void * V_287 ,
struct V_382 * V_238 )
{
if ( F_116 ( V_238 -> V_272 >= F_79 ( V_46 ) ) )
return - V_231 ;
F_102 ( V_238 -> V_383 , V_46 [ V_238 -> V_272 ] . V_203 , sizeof( V_238 -> V_383 ) ) ;
V_238 -> V_308 = V_46 [ V_238 -> V_272 ] . V_309 ;
return 0 ;
}
static int F_117 ( struct V_305 * V_305 , void * V_287 ,
struct V_384 * V_385 )
{
struct V_1 * V_2 = F_77 ( V_305 ) ;
struct V_315 * V_44 ;
unsigned int V_302 = F_1 ( V_2 ) ;
unsigned int V_303 = F_2 ( V_2 ) ;
V_44 = F_78 ( V_385 -> V_386 ) ;
if ( ! V_44 ) {
F_11 ( L_40 ,
V_385 -> V_386 ) ;
return - V_231 ;
}
if ( V_2 -> V_5 . V_85 ) {
if ( V_385 -> V_272 > 1 )
return - V_231 ;
V_385 -> type = V_387 ;
V_385 -> V_388 . V_72 = V_302 / ( 1 + V_385 -> V_272 ) ;
V_385 -> V_388 . V_73 = V_303 / ( 1 + V_385 -> V_272 ) ;
return 0 ;
}
if ( V_385 -> V_272 != 0 )
return - V_231 ;
V_385 -> type = V_389 ;
F_75 ( V_2 , V_304 , V_304 ,
& V_385 -> V_390 . V_391 , & V_385 -> V_390 . V_392 ) ;
if ( V_385 -> V_390 . V_391 < 48 )
V_385 -> V_390 . V_391 = 48 ;
if ( V_385 -> V_390 . V_392 < 38 )
V_385 -> V_390 . V_392 = 38 ;
V_385 -> V_390 . V_393 = V_302 ;
V_385 -> V_390 . V_394 = V_303 ;
V_385 -> V_390 . V_395 = 1 ;
V_385 -> V_390 . V_396 = 1 ;
return 0 ;
}
static int F_118 ( struct V_305 * V_305 , void * V_287 ,
struct V_306 * V_46 )
{
struct V_1 * V_2 = F_77 ( V_305 ) ;
struct V_3 * V_4 = V_2 -> V_4 ;
V_46 -> V_44 . V_397 . V_398 = V_4 -> V_56 ;
V_46 -> V_44 . V_397 . V_399 = V_400 ;
V_46 -> V_44 . V_397 . V_125 = 0 ;
V_46 -> V_44 . V_397 . V_201 = 0 ;
V_46 -> V_44 . V_397 . V_401 = 6750000 * 4 / 2 ;
V_46 -> V_44 . V_397 . V_236 [ 0 ] = V_4 -> V_58 ;
V_46 -> V_44 . V_397 . V_236 [ 1 ] = V_4 -> V_58 ;
memset ( V_46 -> V_44 . V_397 . V_402 , 0 , sizeof( V_46 -> V_44 . V_397 . V_402 ) ) ;
if ( V_4 -> V_10 & V_59 ) {
V_46 -> V_44 . V_397 . V_403 [ 0 ] = 10 ;
V_46 -> V_44 . V_397 . V_403 [ 1 ] = 273 ;
} else if ( V_4 -> V_10 & V_11 ) {
V_46 -> V_44 . V_397 . V_403 [ 0 ] = 6 ;
V_46 -> V_44 . V_397 . V_403 [ 1 ] = 318 ;
}
return 0 ;
}
static int F_119 ( struct V_305 * V_305 , void * V_287 ,
struct V_347 * V_348 )
{
struct V_1 * V_2 = F_77 ( V_305 ) ;
if ( F_116 ( V_348 -> V_272 > 0 ) )
return - V_231 ;
strcpy ( V_348 -> V_203 , L_52 ) ;
F_5 ( & V_2 -> V_4 -> V_17 , 0 , V_250 , V_349 , V_348 ) ;
return 0 ;
}
static int F_120 ( struct V_305 * V_305 , void * V_287 ,
const struct V_347 * V_348 )
{
struct V_1 * V_2 = F_77 ( V_305 ) ;
if ( 0 != V_348 -> V_272 )
return - V_231 ;
F_5 ( & V_2 -> V_4 -> V_17 , 0 , V_250 , V_350 , V_348 ) ;
return 0 ;
}
static void F_121 ( struct V_404 * V_405 )
{
struct V_3 * V_4 = F_64 ( V_405 , struct V_3 , V_405 ) ;
V_4 -> V_2 -> V_4 = NULL ;
F_122 ( V_4 ) ;
}
static int F_123 ( struct V_305 * V_406 )
{
struct V_363 * V_206 = F_112 ( V_406 ) ;
struct V_1 * V_2 = F_77 ( V_406 ) ;
struct V_3 * V_4 = V_2 -> V_4 ;
enum V_178 V_407 = 0 ;
int V_43 ;
switch ( V_206 -> V_246 ) {
case V_369 :
V_407 = V_180 ;
break;
case V_408 :
V_407 = V_182 ;
break;
case V_247 :
break;
default:
return - V_231 ;
}
F_11 ( L_53 ,
F_124 ( V_206 ) , V_409 [ V_407 ] ,
V_4 -> V_410 ) ;
if ( F_125 ( & V_2 -> V_411 ) )
return - V_412 ;
V_43 = F_126 ( V_406 ) ;
if ( V_43 ) {
F_18 ( L_54 ,
V_235 , V_43 ) ;
F_127 ( & V_2 -> V_411 ) ;
return V_43 ;
}
if ( V_4 -> V_410 == 0 ) {
F_128 ( V_2 , V_243 ) ;
if ( V_206 -> V_246 != V_247 )
F_15 ( V_2 ) ;
F_4 ( V_2 ) ;
}
if ( V_206 -> V_246 == V_247 ) {
F_11 ( L_55 ) ;
F_5 ( & V_4 -> V_17 , 0 , V_250 , V_413 ) ;
}
F_129 ( & V_2 -> V_405 ) ;
F_129 ( & V_4 -> V_405 ) ;
V_4 -> V_410 ++ ;
F_127 ( & V_2 -> V_411 ) ;
return 0 ;
}
static int F_130 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
if ( V_2 -> V_414 ) {
return 0 ;
}
if ( ! V_2 -> V_415 ) {
return 0 ;
}
if ( V_4 == NULL )
return 0 ;
F_131 ( L_56 ) ;
F_132 ( & V_2 -> V_411 ) ;
F_133 ( & V_4 -> V_17 ) ;
F_59 ( V_2 , V_243 ) ;
F_39 ( V_2 ) ;
if ( F_114 ( & V_4 -> V_381 ) ) {
F_131 ( L_57 ,
F_124 ( & V_4 -> V_381 ) ) ;
F_134 ( & V_4 -> V_381 ) ;
}
if ( F_114 ( & V_4 -> V_208 ) ) {
F_131 ( L_57 ,
F_124 ( & V_4 -> V_208 ) ) ;
F_134 ( & V_4 -> V_208 ) ;
}
if ( F_114 ( & V_4 -> V_206 ) ) {
F_131 ( L_57 ,
F_124 ( & V_4 -> V_206 ) ) ;
F_134 ( & V_4 -> V_206 ) ;
}
F_135 ( & V_4 -> V_295 ) ;
F_136 ( & V_4 -> V_17 ) ;
if ( V_4 -> V_416 ) {
F_137 ( V_4 -> V_416 ) ;
V_4 -> V_416 = NULL ;
}
F_138 ( & V_4 -> V_405 , F_121 ) ;
F_127 ( & V_2 -> V_411 ) ;
F_138 ( & V_2 -> V_405 , V_417 ) ;
return 0 ;
}
static int F_139 ( struct V_1 * V_2 )
{
if ( V_2 -> V_414 )
return 0 ;
if ( ! V_2 -> V_415 )
return 0 ;
F_131 ( L_58 ) ;
F_140 ( V_2 ) ;
return 0 ;
}
static int F_141 ( struct V_1 * V_2 )
{
if ( V_2 -> V_414 )
return 0 ;
if ( ! V_2 -> V_415 )
return 0 ;
F_131 ( L_59 ) ;
return 0 ;
}
static int F_142 ( struct V_305 * V_406 )
{
struct V_1 * V_2 = F_77 ( V_406 ) ;
struct V_3 * V_4 = V_2 -> V_4 ;
int V_92 ;
F_11 ( L_60 , V_4 -> V_410 ) ;
F_143 ( V_406 ) ;
F_132 ( & V_2 -> V_411 ) ;
if ( V_4 -> V_410 == 1 ) {
if ( V_2 -> V_172 )
goto exit;
F_5 ( & V_4 -> V_17 , 0 , V_18 , V_418 , 0 ) ;
F_128 ( V_2 , V_419 ) ;
V_2 -> V_95 = 0 ;
F_11 ( L_61 ) ;
V_92 = F_17 ( V_2 -> V_104 , 0 , 0 ) ;
if ( V_92 < 0 ) {
F_18 ( L_62
L_63 , V_92 ) ;
}
}
exit:
V_4 -> V_410 -- ;
F_138 ( & V_4 -> V_405 , F_121 ) ;
F_127 ( & V_2 -> V_411 ) ;
F_138 ( & V_2 -> V_405 , V_417 ) ;
return 0 ;
}
static void F_144 ( struct V_1 * V_2 ,
struct V_363 * V_420 ,
const struct V_363 * V_421 ,
const char * V_422 )
{
* V_420 = * V_421 ;
V_420 -> V_17 = & V_2 -> V_4 -> V_17 ;
V_420 -> V_411 = & V_2 -> V_411 ;
if ( V_2 -> V_5 . V_6 )
V_420 -> V_333 = 0 ;
snprintf ( V_420 -> V_203 , sizeof( V_420 -> V_203 ) , L_64 ,
V_2 -> V_203 , V_422 ) ;
F_145 ( V_420 , V_2 ) ;
}
static void F_146 ( struct V_1 * V_2 , unsigned short V_423 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_16 * V_17 = & V_4 -> V_17 ;
struct V_424 V_425 ;
struct V_237 V_238 ;
memset ( & V_425 , 0 , sizeof( V_425 ) ) ;
V_425 . V_426 = V_427 | V_428 ;
V_425 . V_429 = V_430 ;
if ( V_2 -> V_5 . V_431 . type ) {
V_425 . type = V_2 -> V_5 . V_431 . type ;
V_425 . V_356 = V_2 -> V_5 . V_432 ;
F_5 ( V_17 ,
0 , V_250 , V_433 , & V_425 ) ;
}
if ( ( V_2 -> V_219 != V_220 ) && ( V_2 -> V_219 ) ) {
V_425 . type = V_2 -> V_219 ;
V_425 . V_356 = V_423 ;
F_5 ( V_17 ,
0 , V_250 , V_433 , & V_425 ) ;
}
if ( V_2 -> V_5 . V_434 ) {
struct V_435 V_436 ;
V_436 . V_250 = V_437 ;
V_436 . V_287 = & V_2 -> V_5 . V_434 ;
F_5 ( V_17 ,
0 , V_250 , V_438 , & V_436 ) ;
}
if ( V_2 -> V_219 == V_439 ) {
struct V_435 V_440 ;
struct V_441 V_442 ;
memset ( & V_440 , 0 , sizeof( V_440 ) ) ;
memset ( & V_442 , 0 , sizeof( V_442 ) ) ;
F_147 ( V_2 , & V_442 ) ;
V_440 . V_250 = V_439 ;
V_440 . V_287 = & V_442 ;
F_5 ( V_17 , 0 , V_250 , V_438 , & V_440 ) ;
}
V_238 . V_250 = 0 ;
V_238 . type = V_249 ;
V_238 . V_245 = 9076 ;
V_4 -> V_245 = V_238 . V_245 ;
F_5 ( V_17 , 0 , V_250 , V_251 , & V_238 ) ;
}
static int F_148 ( struct V_1 * V_2 )
{
T_1 V_291 ;
int V_43 ;
unsigned int V_302 ;
struct V_443 * V_444 ;
struct V_3 * V_4 ;
if ( V_2 -> V_414 ) {
return 0 ;
}
if ( ! V_2 -> V_415 ) {
return 0 ;
}
F_131 ( L_65 ) ;
F_132 ( & V_2 -> V_411 ) ;
V_4 = F_149 ( sizeof( struct V_3 ) , V_445 ) ;
if ( V_4 == NULL ) {
F_131 ( L_66 ) ;
F_127 ( & V_2 -> V_411 ) ;
return - V_446 ;
}
F_150 ( & V_4 -> V_405 ) ;
V_4 -> V_2 = V_2 ;
V_2 -> V_4 = V_4 ;
#ifdef F_40
V_4 -> V_17 . V_190 = V_2 -> V_191 ;
#endif
V_43 = F_151 ( & V_2 -> V_104 -> V_2 , & V_4 -> V_17 ) ;
if ( V_43 < 0 ) {
F_18 ( L_67 ) ;
goto V_447;
}
V_444 = & V_4 -> V_295 ;
F_152 ( V_444 , 8 ) ;
V_4 -> V_17 . V_295 = V_444 ;
if ( V_2 -> V_5 . V_6 )
V_4 -> V_111 = true ;
V_4 -> V_51 = 0x10 ;
V_4 -> V_52 = V_448 |
V_449 ;
if ( V_2 -> V_5 . V_278 )
F_153 ( & V_4 -> V_17 ,
& V_2 -> V_450 [ V_2 -> V_451 ] ,
L_68 , 0 , V_452 ) ;
if ( V_2 -> V_5 . V_198 == V_453 )
F_153 ( & V_4 -> V_17 ,
& V_2 -> V_450 [ V_2 -> V_451 ] ,
L_69 , 0 , V_454 ) ;
if ( V_2 -> V_5 . V_198 == V_455 )
F_153 ( & V_4 -> V_17 ,
& V_2 -> V_450 [ V_2 -> V_451 ] ,
L_70 , 0 , V_456 ) ;
if ( V_2 -> V_5 . V_283 == V_457 )
F_153 ( & V_4 -> V_17 ,
& V_2 -> V_450 [ V_2 -> V_451 ] ,
L_71 , V_2 -> V_5 . V_458 , NULL ) ;
if ( V_2 -> V_5 . V_219 != V_220 ) {
unsigned short V_423 = V_2 -> V_5 . V_423 ;
int V_459 = ( V_2 -> V_5 . V_434 & V_460 ) ;
if ( V_2 -> V_5 . V_431 . type )
F_153 ( & V_4 -> V_17 ,
& V_2 -> V_450 [ V_2 -> V_451 ] ,
L_72 , V_2 -> V_5 . V_432 ,
NULL ) ;
if ( V_459 )
F_153 ( & V_4 -> V_17 ,
& V_2 -> V_450 [ V_2 -> V_451 ] ,
L_72 , 0 ,
F_154 ( V_461 ) ) ;
if ( V_423 == 0 ) {
enum V_462 type =
V_459 ? V_463 : V_464 ;
struct V_465 * V_466 ;
V_466 = F_153 ( & V_4 -> V_17 ,
& V_2 -> V_450 [ V_2 -> V_451 ] ,
L_72 , 0 ,
F_154 ( type ) ) ;
if ( V_466 )
V_423 = F_155 ( V_466 ) ;
} else {
F_153 ( & V_4 -> V_17 ,
& V_2 -> V_450 [ V_2 -> V_451 ] ,
L_72 , V_423 , NULL ) ;
}
F_146 ( V_2 , V_423 ) ;
}
if ( V_2 -> V_467 != V_468 )
F_156 ( V_2 ) ;
V_43 = F_157 ( V_2 ) ;
if ( V_43 < 0 ) {
F_18 ( L_73 ,
V_235 , V_43 ) ;
goto V_469;
}
if ( V_2 -> V_470 . V_471 != V_472 ) {
F_158 ( V_444 , & V_473 ,
V_289 , 0 , 1 , 1 , 1 ) ;
F_158 ( V_444 , & V_473 ,
V_292 , 0 , 0x1f , 1 , 0x1f ) ;
} else {
F_159 ( F_160 ( V_444 , V_289 ) ,
F_72 , V_2 ) ;
F_159 ( F_160 ( V_444 , V_292 ) ,
F_72 , V_2 ) ;
}
F_4 ( V_2 ) ;
F_161 ( & V_2 -> V_154 . V_145 ) ;
F_161 ( & V_2 -> V_156 . V_145 ) ;
if ( V_2 -> V_5 . V_278 ) {
V_43 = F_8 ( V_2 , V_474 , 0xf7 ) ;
if ( V_43 < 0 ) {
F_18 ( L_74 ,
V_235 , V_43 ) ;
goto V_469;
}
F_162 ( 3 ) ;
V_43 = F_8 ( V_2 , V_474 , 0xff ) ;
if ( V_43 < 0 ) {
F_18 ( L_75 ,
V_235 , V_43 ) ;
goto V_469;
}
F_162 ( 3 ) ;
}
V_4 -> V_10 = V_475 ;
F_5 ( & V_4 -> V_17 , 0 , V_20 , V_317 , V_4 -> V_10 ) ;
V_4 -> V_313 = V_476 ;
V_4 -> V_46 = & V_46 [ 0 ] ;
V_302 = F_1 ( V_2 ) ;
if ( V_2 -> V_5 . V_85 )
V_302 /= 2 ;
F_82 ( V_2 , V_46 [ 0 ] . V_309 ,
V_302 , F_2 ( V_2 ) ) ;
F_69 ( V_2 , 0 ) ;
V_2 -> V_290 = 1 ;
V_2 -> V_293 = 0x1f ;
V_291 = ( T_1 ) F_106 ( V_2 , V_477 ) ;
F_8 ( V_2 , V_477 ,
( V_478 | V_291 ) ) ;
F_9 ( V_2 ) ;
if ( NULL == F_160 ( V_444 , V_296 ) )
F_158 ( V_444 , & V_473 ,
V_296 ,
0 , 0x1f , 1 , V_25 ) ;
if ( NULL == F_160 ( V_444 , V_297 ) )
F_158 ( V_444 , & V_473 ,
V_297 ,
- 0x80 , 0x7f , 1 , V_27 ) ;
if ( NULL == F_160 ( V_444 , V_298 ) )
F_158 ( V_444 , & V_473 ,
V_298 ,
0 , 0x1f , 1 , V_29 ) ;
if ( NULL == F_160 ( V_444 , V_299 ) )
F_158 ( V_444 , & V_473 ,
V_299 ,
- 0x30 , 0x30 , 1 , V_31 ) ;
if ( NULL == F_160 ( V_444 , V_300 ) )
F_158 ( V_444 , & V_473 ,
V_300 ,
- 0x30 , 0x30 , 1 , V_33 ) ;
if ( NULL == F_160 ( V_444 , V_301 ) )
F_158 ( V_444 , & V_473 ,
V_301 ,
0 , 0x0f , 1 , V_35 ) ;
F_7 ( V_2 ) ;
F_163 ( V_444 ) ;
V_43 = V_444 -> error ;
if ( V_43 )
goto V_469;
F_144 ( V_2 , & V_4 -> V_206 , & V_479 , L_76 ) ;
F_164 ( & V_4 -> V_480 ) ;
F_164 ( & V_4 -> V_481 ) ;
V_4 -> V_206 . V_482 = & V_4 -> V_256 ;
V_4 -> V_206 . V_482 -> V_411 = & V_4 -> V_480 ;
if ( V_2 -> V_5 . V_6 ) {
F_165 ( & V_4 -> V_206 , V_483 ) ;
F_165 ( & V_4 -> V_206 , V_484 ) ;
F_165 ( & V_4 -> V_206 , V_485 ) ;
} else {
F_165 ( & V_4 -> V_206 , V_486 ) ;
}
if ( V_2 -> V_219 == V_220 ) {
F_165 ( & V_4 -> V_206 , V_487 ) ;
F_165 ( & V_4 -> V_206 , V_488 ) ;
F_165 ( & V_4 -> V_206 , V_489 ) ;
F_165 ( & V_4 -> V_206 , V_490 ) ;
}
if ( V_2 -> V_376 == V_377 ) {
F_165 ( & V_4 -> V_206 , V_491 ) ;
F_165 ( & V_4 -> V_206 , V_492 ) ;
}
V_43 = F_166 ( & V_4 -> V_206 , V_369 ,
V_493 [ V_2 -> V_494 ] ) ;
if ( V_43 ) {
F_18 ( L_77 ,
V_43 ) ;
goto V_469;
}
if ( F_3 ( V_2 ) == 1 ) {
F_144 ( V_2 , & V_4 -> V_208 , & V_479 ,
L_78 ) ;
V_4 -> V_208 . V_482 = & V_4 -> V_270 ;
V_4 -> V_208 . V_482 -> V_411 = & V_4 -> V_481 ;
F_165 ( & V_4 -> V_208 , V_486 ) ;
if ( V_2 -> V_219 == V_220 ) {
F_165 ( & V_4 -> V_208 , V_487 ) ;
F_165 ( & V_4 -> V_208 , V_488 ) ;
F_165 ( & V_4 -> V_208 , V_489 ) ;
F_165 ( & V_4 -> V_208 , V_490 ) ;
}
if ( V_2 -> V_376 == V_377 ) {
F_165 ( & V_4 -> V_208 , V_491 ) ;
F_165 ( & V_4 -> V_208 , V_492 ) ;
}
V_43 = F_166 ( & V_4 -> V_208 , V_408 ,
V_495 [ V_2 -> V_494 ] ) ;
if ( V_43 < 0 ) {
F_18 ( L_79 ) ;
goto V_469;
}
}
if ( V_366 [ V_2 -> V_367 ] . V_431 . type == V_496 ) {
F_144 ( V_2 , & V_4 -> V_381 , & V_497 ,
L_80 ) ;
V_43 = F_166 ( & V_4 -> V_381 , V_247 ,
V_498 [ V_2 -> V_494 ] ) ;
if ( V_43 < 0 ) {
F_18 ( L_81 ) ;
goto V_469;
}
F_131 ( L_82 ,
F_124 ( & V_4 -> V_381 ) ) ;
}
F_46 ( V_2 ) ;
#ifdef F_40
V_43 = F_167 ( V_2 -> V_191 ) ;
if ( V_43 ) {
F_18 ( L_83 ) ;
F_39 ( V_2 ) ;
goto V_469;
}
#endif
F_131 ( L_84 ,
F_124 ( & V_4 -> V_206 ) ) ;
if ( F_114 ( & V_4 -> V_208 ) )
F_131 ( L_85 ,
F_124 ( & V_4 -> V_208 ) ) ;
F_5 ( & V_4 -> V_17 , 0 , V_18 , V_418 , 0 ) ;
F_67 ( V_2 ) ;
F_131 ( L_86 ) ;
F_129 ( & V_2 -> V_405 ) ;
F_127 ( & V_2 -> V_411 ) ;
return 0 ;
V_469:
if ( F_114 ( & V_4 -> V_381 ) ) {
F_131 ( L_57 ,
F_124 ( & V_4 -> V_381 ) ) ;
F_134 ( & V_4 -> V_381 ) ;
}
if ( F_114 ( & V_4 -> V_208 ) ) {
F_131 ( L_57 ,
F_124 ( & V_4 -> V_208 ) ) ;
F_134 ( & V_4 -> V_208 ) ;
}
if ( F_114 ( & V_4 -> V_206 ) ) {
F_131 ( L_57 ,
F_124 ( & V_4 -> V_206 ) ) ;
F_134 ( & V_4 -> V_206 ) ;
}
F_135 ( & V_4 -> V_295 ) ;
F_136 ( & V_4 -> V_17 ) ;
V_447:
V_2 -> V_4 = NULL ;
F_138 ( & V_4 -> V_405 , F_121 ) ;
F_127 ( & V_2 -> V_411 ) ;
return V_43 ;
}
static int T_5 F_168 ( void )
{
return F_169 ( & V_499 ) ;
}
static void T_6 F_170 ( void )
{
F_171 ( & V_499 ) ;
}
