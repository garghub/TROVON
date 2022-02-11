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
struct V_92 * V_93 = F_17 ( V_2 -> V_94 ) ;
int V_95 ;
int V_96 ;
unsigned int V_97 = V_4 -> V_72 * 2 + 4 ;
V_2 -> V_98 = 0 ;
if ( ( V_98 > 0 ) && ( V_98 < V_2 -> V_99 ) ) {
F_11 ( L_3 , V_2 -> V_98 ) ;
V_2 -> V_98 = V_98 ;
goto V_100;
}
if ( V_2 -> V_101 )
goto V_100;
if ( V_4 -> V_72 * 2 * V_4 -> V_73 > 720 * 240 * 2 )
V_97 *= 2 ;
for ( V_96 = 0 ; V_96 < V_2 -> V_99 ; V_96 ++ ) {
if ( V_2 -> V_102 [ V_96 ] >= V_97 ) {
V_2 -> V_98 = V_96 ;
break;
} else if ( V_2 -> V_102 [ V_96 ] >
V_2 -> V_102 [ V_2 -> V_98 ] )
V_2 -> V_98 = V_96 ;
}
V_100:
if ( V_2 -> V_101 ) {
V_2 -> V_103 = 512 ;
V_2 -> V_104 = V_105 ;
} else {
F_11 ( L_4 ,
V_97 , V_2 -> V_98 ) ;
V_2 -> V_103 =
V_2 -> V_102 [ V_2 -> V_98 ] ;
V_2 -> V_104 = V_106 ;
}
F_11 ( L_5 ,
V_2 -> V_98 , V_2 -> V_103 ) ;
V_95 = F_18 ( V_93 , V_2 -> V_107 , V_2 -> V_98 ) ;
if ( V_95 < 0 ) {
F_19 ( & V_2 -> V_94 -> V_2 ,
L_6 ,
V_2 -> V_98 , V_95 ) ;
return V_95 ;
}
return 0 ;
}
static inline void F_20 ( struct V_1 * V_2 ,
struct V_108 * V_86 )
{
F_21 ( L_7 , V_86 , V_86 -> V_109 ) ;
V_86 -> V_110 . V_111 = V_2 -> V_4 -> V_112 ++ ;
if ( V_2 -> V_4 -> V_113 )
V_86 -> V_110 . V_114 = V_115 ;
else
V_86 -> V_110 . V_114 = V_116 ;
V_86 -> V_110 . V_117 . V_118 = F_22 () ;
F_23 ( & V_86 -> V_110 . V_117 , V_119 ) ;
}
static void F_24 ( struct V_1 * V_2 ,
struct V_108 * V_86 ,
unsigned char * V_120 ,
unsigned long V_121 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
void * V_122 , * V_123 , * V_124 ;
int V_125 , V_126 , V_127 , V_128 , V_129 ;
int V_130 = V_4 -> V_72 << 1 ;
if ( V_86 -> V_131 + V_121 > V_86 -> V_132 )
V_121 = V_86 -> V_132 - V_86 -> V_131 ;
V_124 = V_120 ;
V_129 = V_121 ;
if ( V_4 -> V_113 || V_86 -> V_109 )
V_122 = V_86 -> V_133 ;
else
V_122 = V_86 -> V_133 + V_130 ;
V_125 = V_86 -> V_131 / V_130 ;
V_126 = V_86 -> V_131 % V_130 ;
if ( V_4 -> V_113 )
V_127 = V_125 * V_130 + V_126 ;
else
V_127 = V_125 * V_130 * 2 + V_126 ;
V_123 = V_122 + V_127 ;
V_128 = V_130 - V_126 ;
V_128 = V_128 > V_129 ? V_129 : V_128 ;
if ( ( char * ) V_123 + V_128 > ( char * ) V_86 -> V_133 + V_86 -> V_132 ) {
F_21 ( L_8 ,
( ( char * ) V_123 + V_128 ) -
( ( char * ) V_86 -> V_133 + V_86 -> V_132 ) ) ;
V_129 = ( char * ) V_86 -> V_133 + V_86 -> V_132 -
( char * ) V_123 ;
V_128 = V_129 ;
}
if ( V_128 <= 0 )
return;
memcpy ( V_123 , V_124 , V_128 ) ;
V_129 -= V_128 ;
while ( V_129 > 0 ) {
if ( V_4 -> V_113 )
V_123 += V_128 ;
else
V_123 += V_128 + V_130 ;
V_124 += V_128 ;
if ( V_130 > V_129 )
V_128 = V_129 ;
else
V_128 = V_130 ;
if ( ( char * ) V_123 + V_128 > ( char * ) V_86 -> V_133 +
V_86 -> V_132 ) {
F_21 ( L_9 ,
( ( char * ) V_123 + V_128 ) -
( ( char * ) V_86 -> V_133 + V_86 -> V_132 ) ) ;
V_128 = V_129 = ( char * ) V_86 -> V_133 + V_86 -> V_132 -
( char * ) V_123 ;
}
if ( V_128 <= 0 )
break;
memcpy ( V_123 , V_124 , V_128 ) ;
V_129 -= V_128 ;
}
V_86 -> V_131 += V_121 ;
}
static void F_25 ( struct V_1 * V_2 ,
struct V_108 * V_86 ,
unsigned char * V_120 ,
unsigned long V_121 )
{
unsigned int V_127 ;
if ( V_86 -> V_131 + V_121 > V_86 -> V_132 )
V_121 = V_86 -> V_132 - V_86 -> V_131 ;
V_127 = V_86 -> V_131 ;
if ( V_86 -> V_109 == 0 )
V_127 += V_2 -> V_4 -> V_56 * V_2 -> V_4 -> V_58 ;
memcpy ( V_86 -> V_133 + V_127 , V_120 , V_121 ) ;
V_86 -> V_131 += V_121 ;
}
static inline void F_26 ( struct V_1 * V_2 ,
int V_134 , int V_135 )
{
char * V_136 = L_10 ;
switch ( V_135 ) {
case - V_137 :
V_136 = L_11 ;
break;
case - V_138 :
V_136 = L_12 ;
break;
case - V_139 :
V_136 = L_13 ;
break;
case - V_140 :
V_136 = L_14 ;
break;
case - V_141 :
V_136 = L_15 ;
break;
case - V_142 :
V_136 = L_16 ;
break;
case - V_143 :
V_136 = L_17 ;
break;
case - V_144 :
V_136 = L_18 ;
break;
}
if ( V_134 < 0 ) {
F_21 ( L_19 , V_135 , V_136 ) ;
} else {
F_21 ( L_20 ,
V_134 , V_135 , V_136 ) ;
}
}
static inline struct V_108 * F_27 ( struct V_1 * V_2 ,
struct V_145 * V_146 )
{
struct V_108 * V_86 ;
if ( F_28 ( & V_146 -> V_147 ) ) {
F_21 ( L_21 ) ;
return NULL ;
}
V_86 = F_29 ( V_146 -> V_147 . V_148 , struct V_108 , V_149 ) ;
F_30 ( & V_86 -> V_149 ) ;
V_86 -> V_131 = 0 ;
V_86 -> V_133 = V_86 -> V_150 ;
return V_86 ;
}
static struct V_108 *
F_31 ( struct V_1 * V_2 ,
struct V_108 * V_86 ,
struct V_145 * V_146 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
if ( V_4 -> V_113 || V_4 -> V_109 ) {
if ( V_86 != NULL )
F_20 ( V_2 , V_86 ) ;
V_86 = F_27 ( V_2 , V_146 ) ;
}
if ( V_86 != NULL ) {
V_86 -> V_109 = V_4 -> V_109 ;
V_86 -> V_131 = 0 ;
}
return V_86 ;
}
static inline void F_32 ( struct V_1 * V_2 ,
unsigned char * V_151 ,
unsigned int V_152 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_108 * V_86 = V_2 -> V_153 . V_154 ;
struct V_108 * V_155 = V_2 -> V_153 . V_155 ;
struct V_145 * V_146 = & V_2 -> V_156 ;
struct V_145 * V_157 = & V_2 -> V_158 ;
if ( V_152 >= 4 ) {
if ( V_151 [ 0 ] == 0x88 && V_151 [ 1 ] == 0x88 &&
V_151 [ 2 ] == 0x88 && V_151 [ 3 ] == 0x88 ) {
V_151 += 4 ;
V_152 -= 4 ;
} else if ( V_151 [ 0 ] == 0x33 && V_151 [ 1 ] == 0x95 ) {
V_4 -> V_159 = 0 ;
V_4 -> V_160 = 0 ;
F_21 ( L_22 ) ;
V_4 -> V_109 = ! ( V_151 [ 2 ] & 1 ) ;
V_151 += 4 ;
V_152 -= 4 ;
} else if ( V_151 [ 0 ] == 0x22 && V_151 [ 1 ] == 0x5a ) {
V_4 -> V_159 = 2 ;
F_21 ( L_23 ) ;
V_4 -> V_109 = ! ( V_151 [ 2 ] & 1 ) ;
V_151 += 4 ;
V_152 -= 4 ;
}
}
if ( V_4 -> V_159 == 0 ) {
V_155 = F_31 ( V_2 , V_155 , V_157 ) ;
V_2 -> V_153 . V_155 = V_155 ;
V_4 -> V_159 = 1 ;
}
if ( V_4 -> V_159 == 1 ) {
int V_161 = V_4 -> V_56 * V_4 -> V_58 ;
int V_162 = ( ( V_4 -> V_160 + V_152 ) > V_161 ) ?
( V_161 - V_4 -> V_160 ) : V_152 ;
if ( V_155 != NULL )
F_25 ( V_2 , V_155 , V_151 , V_162 ) ;
V_4 -> V_160 += V_162 ;
if ( V_162 < V_152 ) {
V_4 -> V_159 = 2 ;
V_151 += V_162 ;
V_152 -= V_162 ;
}
}
if ( V_4 -> V_159 == 2 ) {
V_86 = F_31 ( V_2 , V_86 , V_146 ) ;
V_2 -> V_153 . V_154 = V_86 ;
V_4 -> V_159 = 3 ;
}
if ( V_4 -> V_159 == 3 && V_86 != NULL && V_152 > 0 )
F_24 ( V_2 , V_86 , V_151 , V_152 ) ;
}
static inline void F_33 ( struct V_1 * V_2 ,
unsigned char * V_151 ,
unsigned int V_152 )
{
struct V_108 * V_86 = V_2 -> V_153 . V_154 ;
struct V_145 * V_163 = & V_2 -> V_156 ;
struct V_3 * V_4 = V_2 -> V_4 ;
bool V_164 = false ;
if ( V_152 >= 2 ) {
if ( ( V_151 [ 0 ] == V_165 ) &&
( ( V_151 [ 1 ] & ~ V_166 ) == 0x00 ) ) {
V_4 -> V_109 = ! ( V_151 [ 1 ] &
V_167 ) ;
V_164 = V_151 [ 1 ] &
V_168 ;
V_151 += 2 ;
V_152 -= 2 ;
}
if ( V_2 -> V_101 && V_164 ) {
V_86 = F_31 ( V_2 , V_86 , V_163 ) ;
V_2 -> V_153 . V_154 = V_86 ;
}
}
if ( V_86 != NULL && V_152 > 0 )
F_24 ( V_2 , V_86 , V_151 , V_152 ) ;
if ( ! V_2 -> V_101 && V_164 ) {
V_86 = F_31 ( V_2 , V_86 , V_163 ) ;
V_2 -> V_153 . V_154 = V_86 ;
}
}
static inline int F_34 ( struct V_1 * V_2 , struct V_169 * V_169 )
{
int V_170 , V_171 , V_96 ;
unsigned char * V_172 ;
unsigned int V_173 ;
if ( ! V_2 )
return 0 ;
if ( V_2 -> V_174 )
return 0 ;
if ( V_169 -> V_135 < 0 )
F_26 ( V_2 , - 1 , V_169 -> V_135 ) ;
V_170 = F_35 ( V_169 -> V_175 ) ;
if ( V_170 )
V_171 = 1 ;
else
V_171 = V_169 -> V_176 ;
for ( V_96 = 0 ; V_96 < V_171 ; V_96 ++ ) {
if ( V_170 ) {
V_173 = V_169 -> V_177 ;
V_172 = V_169 -> V_178 ;
} else {
if ( V_169 -> V_179 [ V_96 ] . V_135 < 0 ) {
F_26 ( V_2 , V_96 ,
V_169 -> V_179 [ V_96 ] . V_135 ) ;
if ( V_169 -> V_179 [ V_96 ] . V_135 != - V_142 )
continue;
}
V_173 = V_169 -> V_179 [ V_96 ] . V_177 ;
if ( V_173 > V_2 -> V_103 ) {
F_21 ( L_24 ) ;
continue;
}
V_172 = V_169 -> V_178 +
V_169 -> V_179 [ V_96 ] . V_127 ;
}
if ( V_173 == 0 ) {
continue;
}
if ( V_2 -> V_48 )
F_33 ( V_2 ,
V_172 , V_173 ) ;
else
F_32 ( V_2 ,
V_172 , V_173 ) ;
}
return 1 ;
}
static int F_36 ( enum V_180 V_181 )
{
switch ( V_181 ) {
case V_182 :
return V_183 ;
case V_184 :
return V_185 ;
default:
F_37 () ;
}
}
static int F_38 ( struct V_1 * V_2 , enum V_180 V_181 )
{
int V_186 = F_36 ( V_181 ) ;
if ( V_2 -> V_187 & V_186 ) {
return - V_188 ;
}
V_2 -> V_187 |= V_186 ;
F_11 ( L_25 , V_186 ) ;
return 0 ;
}
static void F_39 ( struct V_1 * V_2 , enum V_180 V_181 )
{
int V_186 = F_36 ( V_181 ) ;
V_2 -> V_187 &= ~ V_186 ;
F_11 ( L_26 , V_186 ) ;
}
static void F_40 ( struct V_1 * V_2 )
{
#ifdef F_41
int V_96 ;
for ( V_96 = 0 ; V_96 < V_189 ; V_96 ++ ) {
if ( ! F_6 ( V_96 ) -> type )
return;
F_42 ( & V_2 -> V_190 [ V_96 ] ) ;
}
#endif
}
static int F_43 ( struct V_1 * V_2 )
{
#ifdef F_41
struct V_191 * V_192 = V_2 -> V_193 ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_194 * V_195 ;
struct V_196 * V_197 , * V_198 = NULL ;
int V_43 , V_199 = 0 ;
if ( ! V_192 || ! V_4 -> V_200 )
return 0 ;
F_44 (link, &v4l2->decoder->links, list) {
if ( V_197 -> V_201 -> V_202 == V_4 -> V_200 ) {
V_198 = V_197 ;
if ( V_197 -> V_203 & V_204 )
V_199 ++ ;
break;
}
}
if ( V_199 == 1 || ! V_198 )
return 0 ;
V_195 = V_198 -> V_195 -> V_202 ;
F_44 (link, &source->links, list) {
struct V_194 * V_201 ;
int V_203 = 0 ;
V_201 = V_197 -> V_201 -> V_202 ;
if ( V_201 == V_4 -> V_200 )
V_203 = V_204 ;
V_43 = F_45 ( V_197 , V_203 ) ;
if ( V_43 ) {
F_19 ( & V_2 -> V_94 -> V_2 ,
L_27 ,
V_195 -> V_205 , V_201 -> V_205 ,
V_203 ? L_28 : L_29 ,
V_43 ) ;
return V_43 ;
} else
F_11 ( L_30 ,
V_195 -> V_205 , V_201 -> V_205 ,
V_203 ? L_31 : L_29 ) ;
}
#endif
return 0 ;
}
static void F_46 ( struct V_1 * V_2 )
{
#if F_47 ( F_41 )
struct V_3 * V_4 = V_2 -> V_4 ;
int V_43 , V_96 ;
V_4 -> V_206 . V_203 = V_207 ;
V_43 = F_48 ( & V_4 -> V_208 . V_202 , 1 , & V_4 -> V_206 ) ;
if ( V_43 < 0 )
F_19 ( & V_2 -> V_94 -> V_2 ,
L_32 ) ;
if ( F_3 ( V_2 ) ) {
V_4 -> V_209 . V_203 = V_207 ;
V_43 = F_48 ( & V_4 -> V_210 . V_202 , 1 ,
& V_4 -> V_209 ) ;
if ( V_43 < 0 )
F_19 ( & V_2 -> V_94 -> V_2 ,
L_33 ) ;
}
if ( V_2 -> V_5 . V_6 )
return;
for ( V_96 = 0 ; V_96 < V_189 ; V_96 ++ ) {
struct V_194 * V_211 = & V_2 -> V_190 [ V_96 ] ;
if ( ! F_6 ( V_96 ) -> type )
break;
V_211 -> V_205 = V_212 [ F_6 ( V_96 ) -> type ] ;
V_211 -> V_203 = V_213 ;
V_2 -> V_214 [ V_96 ] . V_203 = V_215 ;
switch ( F_6 ( V_96 ) -> type ) {
case V_216 :
V_211 -> V_217 = V_218 ;
break;
case V_219 :
V_211 -> V_217 = V_220 ;
break;
default:
if ( V_2 -> V_221 != V_222 )
V_211 -> V_217 = V_223 ;
break;
}
V_43 = F_48 ( V_211 , 1 , & V_2 -> V_214 [ V_96 ] ) ;
if ( V_43 < 0 )
F_19 ( & V_2 -> V_94 -> V_2 ,
L_34 , V_96 ) ;
V_43 = F_49 ( V_2 -> V_193 , V_211 ) ;
if ( V_43 < 0 )
F_19 ( & V_2 -> V_94 -> V_2 ,
L_35 , V_96 ) ;
}
#endif
}
static int F_50 ( struct V_224 * V_225 ,
unsigned int * V_226 , unsigned int * V_227 ,
unsigned int V_228 [] , struct V_229 * V_230 [] )
{
struct V_1 * V_2 = F_51 ( V_225 ) ;
struct V_3 * V_4 = V_2 -> V_4 ;
unsigned long V_231 =
( V_4 -> V_72 * V_4 -> V_73 * V_4 -> V_46 -> V_232 + 7 ) >> 3 ;
if ( * V_227 )
return V_228 [ 0 ] < V_231 ? - V_233 : 0 ;
* V_227 = 1 ;
V_228 [ 0 ] = V_231 ;
F_43 ( V_2 ) ;
return 0 ;
}
static int
F_52 ( struct V_234 * V_110 )
{
struct V_235 * V_236 = F_53 ( V_110 ) ;
struct V_1 * V_2 = F_51 ( V_110 -> V_224 ) ;
struct V_3 * V_4 = V_2 -> V_4 ;
unsigned long V_231 ;
F_11 ( L_36 , V_237 , V_236 -> V_114 ) ;
V_231 = ( V_4 -> V_72 * V_4 -> V_73 * V_4 -> V_46 -> V_232 + 7 ) >> 3 ;
if ( F_54 ( V_110 , 0 ) < V_231 ) {
F_11 ( L_37 ,
V_237 , F_54 ( V_110 , 0 ) , V_231 ) ;
return - V_233 ;
}
F_55 ( V_110 , 0 , V_231 ) ;
return 0 ;
}
int F_56 ( struct V_224 * V_225 , unsigned int V_238 )
{
struct V_1 * V_2 = F_51 ( V_225 ) ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_239 V_240 ;
struct V_241 * V_242 ;
int V_243 = 0 ;
F_11 ( L_38 , V_237 ) ;
V_243 = F_38 ( V_2 , V_225 -> type ) ;
if ( V_243 )
return V_243 ;
if ( V_4 -> V_244 == 0 ) {
F_16 ( V_2 ) ;
F_4 ( V_2 ) ;
V_4 -> V_159 = - 1 ;
V_243 = F_57 ( V_2 , V_245 ,
V_2 -> V_101 ,
V_246 ,
V_2 -> V_103 ,
V_2 -> V_104 ,
F_34 ) ;
if ( V_243 < 0 )
return V_243 ;
memset ( & V_240 , 0 , sizeof( V_240 ) ) ;
V_240 . V_247 = V_4 -> V_247 ;
V_242 = (struct V_241 * ) V_225 -> V_242 ;
if ( V_242 && V_242 -> V_208 -> V_248 == V_249 )
V_240 . type = V_250 ;
else
V_240 . type = V_251 ;
F_5 ( & V_4 -> V_17 ,
0 , V_252 , V_253 , & V_240 ) ;
F_5 ( & V_4 -> V_17 , 0 , V_20 , V_254 , 1 ) ;
}
V_4 -> V_244 ++ ;
return V_243 ;
}
static void F_58 ( struct V_224 * V_225 )
{
struct V_1 * V_2 = F_51 ( V_225 ) ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_145 * V_156 = & V_2 -> V_156 ;
unsigned long V_203 = 0 ;
F_11 ( L_38 , V_237 ) ;
F_39 ( V_2 , V_225 -> type ) ;
if ( V_4 -> V_244 -- == 1 ) {
F_5 ( & V_4 -> V_17 , 0 , V_20 , V_254 , 0 ) ;
F_59 ( V_2 , V_245 ) ;
}
F_60 ( & V_2 -> V_255 , V_203 ) ;
if ( V_2 -> V_153 . V_154 != NULL ) {
F_23 ( & V_2 -> V_153 . V_154 -> V_110 . V_117 ,
V_256 ) ;
V_2 -> V_153 . V_154 = NULL ;
}
while ( ! F_28 ( & V_156 -> V_147 ) ) {
struct V_108 * V_86 ;
V_86 = F_29 ( V_156 -> V_147 . V_148 , struct V_108 , V_149 ) ;
F_30 ( & V_86 -> V_149 ) ;
F_23 ( & V_86 -> V_110 . V_117 , V_256 ) ;
}
F_61 ( & V_2 -> V_255 , V_203 ) ;
}
void F_62 ( struct V_224 * V_225 )
{
struct V_1 * V_2 = F_51 ( V_225 ) ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_145 * V_158 = & V_2 -> V_158 ;
unsigned long V_203 = 0 ;
F_11 ( L_38 , V_237 ) ;
F_39 ( V_2 , V_225 -> type ) ;
if ( V_4 -> V_244 -- == 1 ) {
F_5 ( & V_4 -> V_17 , 0 , V_20 , V_254 , 0 ) ;
F_59 ( V_2 , V_245 ) ;
}
F_60 ( & V_2 -> V_255 , V_203 ) ;
if ( V_2 -> V_153 . V_155 != NULL ) {
F_23 ( & V_2 -> V_153 . V_155 -> V_110 . V_117 ,
V_256 ) ;
V_2 -> V_153 . V_155 = NULL ;
}
while ( ! F_28 ( & V_158 -> V_147 ) ) {
struct V_108 * V_86 ;
V_86 = F_29 ( V_158 -> V_147 . V_148 , struct V_108 , V_149 ) ;
F_30 ( & V_86 -> V_149 ) ;
F_23 ( & V_86 -> V_110 . V_117 , V_256 ) ;
}
F_61 ( & V_2 -> V_255 , V_203 ) ;
}
static void
F_63 ( struct V_234 * V_110 )
{
struct V_235 * V_236 = F_53 ( V_110 ) ;
struct V_1 * V_2 = F_51 ( V_110 -> V_224 ) ;
struct V_108 * V_86 =
F_64 ( V_236 , struct V_108 , V_110 ) ;
struct V_145 * V_156 = & V_2 -> V_156 ;
unsigned long V_203 = 0 ;
F_11 ( L_38 , V_237 ) ;
V_86 -> V_150 = F_65 ( V_110 , 0 ) ;
V_86 -> V_132 = F_54 ( V_110 , 0 ) ;
F_60 ( & V_2 -> V_255 , V_203 ) ;
F_66 ( & V_86 -> V_149 , & V_156 -> V_147 ) ;
F_61 ( & V_2 -> V_255 , V_203 ) ;
}
static int F_67 ( struct V_1 * V_2 )
{
int V_243 ;
struct V_224 * V_257 ;
struct V_3 * V_4 = V_2 -> V_4 ;
V_257 = & V_4 -> V_258 ;
V_257 -> type = V_182 ;
V_257 -> V_259 = V_260 | V_261 | V_262 | V_263 ;
V_257 -> V_264 = V_265 ;
V_257 -> V_266 = V_2 ;
V_257 -> V_267 = sizeof( struct V_108 ) ;
V_257 -> V_268 = & V_269 ;
V_257 -> V_270 = & V_271 ;
V_243 = F_68 ( V_257 ) ;
if ( V_243 < 0 )
return V_243 ;
V_257 = & V_4 -> V_272 ;
V_257 -> type = V_184 ;
V_257 -> V_259 = V_260 | V_261 | V_262 ;
V_257 -> V_264 = V_265 ;
V_257 -> V_266 = V_2 ;
V_257 -> V_267 = sizeof( struct V_108 ) ;
V_257 -> V_268 = & V_273 ;
V_257 -> V_270 = & V_271 ;
V_243 = F_68 ( V_257 ) ;
if ( V_243 < 0 )
return V_243 ;
return 0 ;
}
static void F_69 ( struct V_1 * V_2 , int V_274 )
{
struct V_16 * V_17 = & V_2 -> V_4 -> V_17 ;
V_2 -> V_22 = V_274 ;
V_2 -> V_275 = F_6 ( V_274 ) -> V_276 ;
V_2 -> V_277 = F_6 ( V_274 ) -> V_278 ;
if ( ! V_2 -> V_277 )
V_2 -> V_277 = V_279 ;
F_5 ( V_17 , 0 , V_20 , V_21 ,
F_6 ( V_274 ) -> V_23 , 0 , 0 ) ;
if ( V_2 -> V_5 . V_280 ) {
if ( V_2 -> V_281 ) {
F_5 ( V_17 , 0 , V_282 ,
V_283 , V_2 -> V_281 ) ;
}
F_5 ( V_17 , 0 , V_282 , V_21 ,
V_2 -> V_275 ,
F_70 ( V_284 ) , 0 ) ;
}
if ( V_2 -> V_5 . V_285 != V_286 ) {
F_5 ( V_17 , 0 , V_282 , V_21 ,
V_2 -> V_275 , V_2 -> V_277 , 0 ) ;
}
F_71 ( V_2 ) ;
}
static void F_72 ( struct V_287 * V_288 , void * V_289 )
{
struct V_1 * V_2 = V_289 ;
switch ( V_288 -> V_290 ) {
case V_291 :
V_2 -> V_292 = V_288 -> V_293 ;
F_71 ( V_2 ) ;
break;
case V_294 :
V_2 -> V_295 = V_288 -> V_293 ;
F_71 ( V_2 ) ;
break;
}
}
static int F_73 ( struct V_287 * V_288 )
{
struct V_3 * V_4 =
F_64 ( V_288 -> V_296 , struct V_3 , V_297 ) ;
struct V_1 * V_2 = V_4 -> V_2 ;
int V_43 = - V_233 ;
switch ( V_288 -> V_290 ) {
case V_291 :
V_2 -> V_292 = V_288 -> V_293 ;
V_43 = F_71 ( V_2 ) ;
break;
case V_294 :
V_2 -> V_295 = V_288 -> V_293 ;
V_43 = F_71 ( V_2 ) ;
break;
case V_298 :
V_43 = F_8 ( V_2 , V_24 , V_288 -> V_293 ) ;
break;
case V_299 :
V_43 = F_8 ( V_2 , V_26 , V_288 -> V_293 ) ;
break;
case V_300 :
V_43 = F_8 ( V_2 , V_28 , V_288 -> V_293 ) ;
break;
case V_301 :
V_43 = F_8 ( V_2 , V_30 , V_288 -> V_293 ) ;
break;
case V_302 :
V_43 = F_8 ( V_2 , V_32 , V_288 -> V_293 ) ;
break;
case V_303 :
V_43 = F_8 ( V_2 , V_34 , V_288 -> V_293 ) ;
break;
}
return ( V_43 < 0 ) ? V_43 : 0 ;
}
static void F_74 ( struct V_1 * V_2 ,
unsigned int V_72 , unsigned int V_73 ,
unsigned int * V_90 , unsigned int * V_91 )
{
unsigned int V_304 = F_1 ( V_2 ) ;
unsigned int V_305 = F_2 ( V_2 ) ;
* V_90 = ( ( ( unsigned long ) V_304 ) << 12 ) / V_72 - 4096L ;
if ( * V_90 > V_306 )
* V_90 = V_306 ;
* V_91 = ( ( ( unsigned long ) V_305 ) << 12 ) / V_73 - 4096L ;
if ( * V_91 > V_306 )
* V_91 = V_306 ;
}
static void F_75 ( struct V_1 * V_2 ,
unsigned int V_90 , unsigned int V_91 ,
unsigned int * V_72 , unsigned int * V_73 )
{
unsigned int V_304 = F_1 ( V_2 ) ;
unsigned int V_305 = F_2 ( V_2 ) ;
* V_72 = ( ( ( unsigned long ) V_304 ) << 12 ) / ( V_90 + 4096L ) ;
* V_73 = ( ( ( unsigned long ) V_305 ) << 12 ) / ( V_91 + 4096L ) ;
if ( * V_72 < 1 )
* V_72 = 1 ;
if ( * V_73 < 1 )
* V_73 = 1 ;
}
static int F_76 ( struct V_307 * V_307 , void * V_289 ,
struct V_308 * V_240 )
{
struct V_1 * V_2 = F_77 ( V_307 ) ;
struct V_3 * V_4 = V_2 -> V_4 ;
V_240 -> V_44 . V_309 . V_72 = V_4 -> V_72 ;
V_240 -> V_44 . V_309 . V_73 = V_4 -> V_73 ;
V_240 -> V_44 . V_309 . V_310 = V_4 -> V_46 -> V_311 ;
V_240 -> V_44 . V_309 . V_130 = ( V_4 -> V_72 * V_4 -> V_46 -> V_232 + 7 ) >> 3 ;
V_240 -> V_44 . V_309 . V_312 = V_240 -> V_44 . V_309 . V_130 * V_4 -> V_73 ;
V_240 -> V_44 . V_309 . V_313 = V_314 ;
if ( V_4 -> V_113 )
V_240 -> V_44 . V_309 . V_114 = V_115 ;
else
V_240 -> V_44 . V_309 . V_114 = V_4 -> V_315 ?
V_116 : V_316 ;
return 0 ;
}
static struct V_317 * F_78 ( unsigned int V_311 )
{
unsigned int V_96 ;
for ( V_96 = 0 ; V_96 < F_79 ( V_46 ) ; V_96 ++ )
if ( V_46 [ V_96 ] . V_311 == V_311 )
return & V_46 [ V_96 ] ;
return NULL ;
}
static int F_80 ( struct V_307 * V_307 , void * V_289 ,
struct V_308 * V_240 )
{
struct V_1 * V_2 = F_77 ( V_307 ) ;
struct V_3 * V_4 = V_2 -> V_4 ;
unsigned int V_72 = V_240 -> V_44 . V_309 . V_72 ;
unsigned int V_73 = V_240 -> V_44 . V_309 . V_73 ;
unsigned int V_304 = F_1 ( V_2 ) ;
unsigned int V_305 = F_2 ( V_2 ) ;
unsigned int V_90 , V_91 ;
struct V_317 * V_44 ;
V_44 = F_78 ( V_240 -> V_44 . V_309 . V_310 ) ;
if ( ! V_44 ) {
F_11 ( L_39 ,
V_240 -> V_44 . V_309 . V_310 ) ;
return - V_233 ;
}
if ( V_2 -> V_5 . V_85 ) {
V_73 = V_73 > ( 3 * V_305 / 4 ) ? V_305 : V_305 / 2 ;
V_72 = V_72 > ( 3 * V_304 / 4 ) ? V_304 : V_304 / 2 ;
if ( V_72 == V_304 && V_73 == V_305 )
V_72 /= 2 ;
} else {
F_81 ( & V_72 , 48 , V_304 , 1 , & V_73 , 32 , V_305 ,
1 , 0 ) ;
}
if ( V_72 < 1 )
V_72 = 1 ;
if ( V_73 < 1 )
V_73 = 1 ;
F_74 ( V_2 , V_72 , V_73 , & V_90 , & V_91 ) ;
F_75 ( V_2 , V_90 , V_91 , & V_72 , & V_73 ) ;
V_240 -> V_44 . V_309 . V_72 = V_72 ;
V_240 -> V_44 . V_309 . V_73 = V_73 ;
V_240 -> V_44 . V_309 . V_310 = V_44 -> V_311 ;
V_240 -> V_44 . V_309 . V_130 = ( V_72 * V_44 -> V_232 + 7 ) >> 3 ;
V_240 -> V_44 . V_309 . V_312 = V_240 -> V_44 . V_309 . V_130 * V_73 ;
V_240 -> V_44 . V_309 . V_313 = V_314 ;
if ( V_4 -> V_113 )
V_240 -> V_44 . V_309 . V_114 = V_115 ;
else
V_240 -> V_44 . V_309 . V_114 = V_4 -> V_315 ?
V_116 : V_316 ;
V_240 -> V_44 . V_309 . V_289 = 0 ;
return 0 ;
}
static int F_82 ( struct V_1 * V_2 , unsigned int V_311 ,
unsigned V_72 , unsigned V_73 )
{
struct V_317 * V_44 ;
struct V_3 * V_4 = V_2 -> V_4 ;
V_44 = F_78 ( V_311 ) ;
if ( ! V_44 )
return - V_233 ;
V_4 -> V_46 = V_44 ;
V_4 -> V_72 = V_72 ;
V_4 -> V_73 = V_73 ;
F_74 ( V_2 , V_4 -> V_72 , V_4 -> V_73 ,
& V_4 -> V_90 , & V_4 -> V_91 ) ;
F_15 ( V_2 ) ;
return 0 ;
}
static int F_83 ( struct V_307 * V_307 , void * V_289 ,
struct V_308 * V_240 )
{
struct V_1 * V_2 = F_77 ( V_307 ) ;
struct V_3 * V_4 = V_2 -> V_4 ;
if ( F_84 ( & V_4 -> V_258 ) )
return - V_188 ;
F_80 ( V_307 , V_289 , V_240 ) ;
return F_82 ( V_2 , V_240 -> V_44 . V_309 . V_310 ,
V_240 -> V_44 . V_309 . V_72 , V_240 -> V_44 . V_309 . V_73 ) ;
}
static int F_85 ( struct V_307 * V_307 , void * V_289 , T_3 * V_10 )
{
struct V_1 * V_2 = F_77 ( V_307 ) ;
* V_10 = V_2 -> V_4 -> V_10 ;
return 0 ;
}
static int F_86 ( struct V_307 * V_307 , void * V_289 , T_3 * V_10 )
{
struct V_1 * V_2 = F_77 ( V_307 ) ;
F_5 ( & V_2 -> V_4 -> V_17 , 0 , V_20 , V_318 , V_10 ) ;
return 0 ;
}
static int F_87 ( struct V_307 * V_307 , void * V_289 , T_3 V_10 )
{
struct V_1 * V_2 = F_77 ( V_307 ) ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_308 V_240 ;
if ( V_10 == V_4 -> V_10 )
return 0 ;
if ( V_4 -> V_244 > 0 )
return - V_188 ;
V_4 -> V_10 = V_10 ;
V_240 . V_44 . V_309 . V_72 = 720 ;
V_240 . V_44 . V_309 . V_73 = ( V_10 & V_59 ) ? 480 : 576 ;
F_80 ( V_307 , V_289 , & V_240 ) ;
V_4 -> V_72 = V_240 . V_44 . V_309 . V_72 ;
V_4 -> V_73 = V_240 . V_44 . V_309 . V_73 ;
F_74 ( V_2 , V_4 -> V_72 , V_4 -> V_73 ,
& V_4 -> V_90 , & V_4 -> V_91 ) ;
F_15 ( V_2 ) ;
F_5 ( & V_4 -> V_17 , 0 , V_20 , V_319 , V_4 -> V_10 ) ;
return 0 ;
}
static int F_88 ( struct V_307 * V_307 , void * V_289 ,
struct V_320 * V_321 )
{
struct V_1 * V_2 = F_77 ( V_307 ) ;
struct V_3 * V_4 = V_2 -> V_4 ;
int V_243 = 0 ;
V_321 -> V_322 . V_323 . V_324 = V_325 ;
if ( V_2 -> V_5 . V_6 )
V_243 = F_89 ( & V_4 -> V_17 , 0 ,
V_20 , V_326 , V_321 ) ;
else
F_90 ( V_4 -> V_10 ,
& V_321 -> V_322 . V_323 . V_327 ) ;
return V_243 ;
}
static int F_91 ( struct V_307 * V_307 , void * V_289 ,
struct V_320 * V_321 )
{
struct V_1 * V_2 = F_77 ( V_307 ) ;
V_321 -> V_322 . V_323 . V_324 = V_325 ;
return F_89 ( & V_2 -> V_4 -> V_17 ,
0 , V_20 , V_328 , V_321 ) ;
}
static int F_92 ( struct V_307 * V_307 , void * V_289 ,
struct V_329 * V_96 )
{
struct V_1 * V_2 = F_77 ( V_307 ) ;
unsigned int V_330 ;
V_330 = V_96 -> V_274 ;
if ( V_330 >= V_189 )
return - V_233 ;
if ( 0 == F_6 ( V_330 ) -> type )
return - V_233 ;
V_96 -> V_274 = V_330 ;
V_96 -> type = V_331 ;
strcpy ( V_96 -> V_205 , V_212 [ F_6 ( V_330 ) -> type ] ) ;
if ( ( V_332 == F_6 ( V_330 ) -> type ) )
V_96 -> type = V_333 ;
V_96 -> V_334 = V_2 -> V_4 -> V_208 . V_335 ;
if ( V_2 -> V_5 . V_6 )
V_96 -> V_336 = 0 ;
return 0 ;
}
static int F_93 ( struct V_307 * V_307 , void * V_289 , unsigned int * V_96 )
{
struct V_1 * V_2 = F_77 ( V_307 ) ;
* V_96 = V_2 -> V_22 ;
return 0 ;
}
static int F_94 ( struct V_307 * V_307 , void * V_289 , unsigned int V_96 )
{
struct V_1 * V_2 = F_77 ( V_307 ) ;
if ( V_96 >= V_189 )
return - V_233 ;
if ( 0 == F_6 ( V_96 ) -> type )
return - V_233 ;
F_69 ( V_2 , V_96 ) ;
return 0 ;
}
static int F_95 ( struct V_307 * V_307 , void * V_289 , struct V_337 * V_338 )
{
struct V_1 * V_2 = F_77 ( V_307 ) ;
switch ( V_338 -> V_274 ) {
case V_339 :
strcpy ( V_338 -> V_205 , L_40 ) ;
break;
case V_340 :
strcpy ( V_338 -> V_205 , L_41 ) ;
break;
case V_341 :
strcpy ( V_338 -> V_205 , L_42 ) ;
break;
case V_342 :
strcpy ( V_338 -> V_205 , L_43 ) ;
break;
case V_343 :
strcpy ( V_338 -> V_205 , L_44 ) ;
break;
case V_344 :
strcpy ( V_338 -> V_205 , L_45 ) ;
break;
case V_345 :
strcpy ( V_338 -> V_205 , L_46 ) ;
break;
case V_346 :
strcpy ( V_338 -> V_205 , L_47 ) ;
break;
default:
return - V_233 ;
}
V_338 -> V_274 = V_2 -> V_275 ;
V_338 -> V_347 = V_348 ;
return 0 ;
}
static int F_96 ( struct V_307 * V_307 , void * V_289 , const struct V_337 * V_338 )
{
struct V_1 * V_2 = F_77 ( V_307 ) ;
if ( V_338 -> V_274 >= V_189 )
return - V_233 ;
if ( 0 == F_6 ( V_338 -> V_274 ) -> type )
return - V_233 ;
V_2 -> V_275 = F_6 ( V_338 -> V_274 ) -> V_276 ;
V_2 -> V_277 = F_6 ( V_338 -> V_274 ) -> V_278 ;
if ( ! V_2 -> V_277 )
V_2 -> V_277 = V_279 ;
return 0 ;
}
static int F_97 ( struct V_307 * V_307 , void * V_289 ,
struct V_349 * V_350 )
{
struct V_1 * V_2 = F_77 ( V_307 ) ;
if ( 0 != V_350 -> V_274 )
return - V_233 ;
strcpy ( V_350 -> V_205 , L_48 ) ;
F_5 ( & V_2 -> V_4 -> V_17 , 0 , V_252 , V_351 , V_350 ) ;
return 0 ;
}
static int F_98 ( struct V_307 * V_307 , void * V_289 ,
const struct V_349 * V_350 )
{
struct V_1 * V_2 = F_77 ( V_307 ) ;
if ( 0 != V_350 -> V_274 )
return - V_233 ;
F_5 ( & V_2 -> V_4 -> V_17 , 0 , V_252 , V_352 , V_350 ) ;
return 0 ;
}
static int F_99 ( struct V_307 * V_307 , void * V_289 ,
struct V_239 * V_240 )
{
struct V_1 * V_2 = F_77 ( V_307 ) ;
struct V_3 * V_4 = V_2 -> V_4 ;
if ( 0 != V_240 -> V_252 )
return - V_233 ;
V_240 -> V_247 = V_4 -> V_247 ;
return 0 ;
}
static int F_100 ( struct V_307 * V_307 , void * V_289 ,
const struct V_239 * V_240 )
{
struct V_239 V_353 = * V_240 ;
struct V_1 * V_2 = F_77 ( V_307 ) ;
struct V_3 * V_4 = V_2 -> V_4 ;
if ( 0 != V_240 -> V_252 )
return - V_233 ;
F_5 ( & V_4 -> V_17 , 0 , V_252 , V_253 , V_240 ) ;
F_5 ( & V_4 -> V_17 , 0 , V_252 , V_354 , & V_353 ) ;
V_4 -> V_247 = V_353 . V_247 ;
return 0 ;
}
static int F_101 ( struct V_307 * V_307 , void * V_289 ,
struct V_355 * V_356 )
{
struct V_1 * V_2 = F_77 ( V_307 ) ;
if ( V_356 -> V_357 . V_358 > 1 )
return - V_233 ;
if ( V_356 -> V_357 . V_358 == 1 )
F_102 ( V_356 -> V_205 , L_49 , sizeof( V_356 -> V_205 ) ) ;
else
F_102 ( V_356 -> V_205 ,
V_2 -> V_4 -> V_17 . V_205 , sizeof( V_356 -> V_205 ) ) ;
return 0 ;
}
static int F_103 ( int V_47 )
{
switch ( V_47 ) {
case V_359 :
case V_87 :
case V_88 :
return 2 ;
default:
return 1 ;
}
}
static int F_104 ( struct V_307 * V_307 , void * V_289 ,
struct V_360 * V_47 )
{
struct V_1 * V_2 = F_77 ( V_307 ) ;
int V_43 ;
if ( V_47 -> V_357 . V_358 > 1 )
return - V_233 ;
if ( V_47 -> V_357 . V_358 ) {
V_43 = F_105 ( V_2 , V_47 -> V_47 ) ;
if ( V_43 < 0 )
return V_43 ;
V_47 -> V_293 = V_43 ;
V_47 -> V_231 = 1 ;
return 0 ;
}
V_47 -> V_231 = F_103 ( V_47 -> V_47 ) ;
if ( V_47 -> V_231 == 1 ) {
V_43 = F_106 ( V_2 , V_47 -> V_47 ) ;
if ( V_43 < 0 )
return V_43 ;
V_47 -> V_293 = V_43 ;
} else {
T_4 V_293 = 0 ;
V_43 = V_2 -> V_361 ( V_2 , V_362 ,
V_47 -> V_47 , ( char * ) & V_293 , 2 ) ;
if ( V_43 < 0 )
return V_43 ;
V_47 -> V_293 = F_107 ( V_293 ) ;
}
return 0 ;
}
static int F_108 ( struct V_307 * V_307 , void * V_289 ,
const struct V_360 * V_47 )
{
struct V_1 * V_2 = F_77 ( V_307 ) ;
T_4 V_86 ;
if ( V_47 -> V_357 . V_358 > 1 )
return - V_233 ;
if ( V_47 -> V_357 . V_358 )
return F_109 ( V_2 , V_47 -> V_47 , V_47 -> V_293 ) ;
V_86 = F_110 ( V_47 -> V_293 ) ;
return F_12 ( V_2 , V_47 -> V_47 , ( char * ) & V_86 ,
F_103 ( V_47 -> V_47 ) ) ;
}
static int F_111 ( struct V_307 * V_307 , void * V_289 ,
struct V_363 * V_364 )
{
struct V_365 * V_208 = F_112 ( V_307 ) ;
struct V_1 * V_2 = F_77 ( V_307 ) ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_92 * V_93 = F_17 ( V_2 -> V_94 ) ;
F_102 ( V_364 -> V_366 , L_50 , sizeof( V_364 -> V_366 ) ) ;
F_102 ( V_364 -> V_367 , V_368 [ V_2 -> V_369 ] . V_205 , sizeof( V_364 -> V_367 ) ) ;
F_113 ( V_93 , V_364 -> V_370 , sizeof( V_364 -> V_370 ) ) ;
if ( V_208 -> V_248 == V_371 )
V_364 -> V_372 = V_373 |
V_374 | V_375 ;
else if ( V_208 -> V_248 == V_249 )
V_364 -> V_372 = V_376 ;
else
V_364 -> V_372 = V_373 | V_377 ;
if ( V_2 -> V_378 != V_379 )
V_364 -> V_372 |= V_380 ;
if ( V_2 -> V_221 != V_222 )
V_364 -> V_372 |= V_381 ;
V_364 -> V_336 = V_364 -> V_372 | V_382 |
V_373 | V_374 | V_375 ;
if ( F_114 ( & V_4 -> V_210 ) )
V_364 -> V_336 |= V_377 ;
if ( F_114 ( & V_4 -> V_383 ) )
V_364 -> V_336 |= V_376 ;
return 0 ;
}
static int F_115 ( struct V_307 * V_307 , void * V_289 ,
struct V_384 * V_240 )
{
if ( F_116 ( V_240 -> V_274 >= F_79 ( V_46 ) ) )
return - V_233 ;
F_102 ( V_240 -> V_385 , V_46 [ V_240 -> V_274 ] . V_205 , sizeof( V_240 -> V_385 ) ) ;
V_240 -> V_310 = V_46 [ V_240 -> V_274 ] . V_311 ;
return 0 ;
}
static int F_117 ( struct V_307 * V_307 , void * V_289 ,
struct V_386 * V_387 )
{
struct V_1 * V_2 = F_77 ( V_307 ) ;
struct V_317 * V_44 ;
unsigned int V_304 = F_1 ( V_2 ) ;
unsigned int V_305 = F_2 ( V_2 ) ;
V_44 = F_78 ( V_387 -> V_388 ) ;
if ( ! V_44 ) {
F_11 ( L_39 ,
V_387 -> V_388 ) ;
return - V_233 ;
}
if ( V_2 -> V_5 . V_85 ) {
if ( V_387 -> V_274 > 1 )
return - V_233 ;
V_387 -> type = V_389 ;
V_387 -> V_390 . V_72 = V_304 / ( 1 + V_387 -> V_274 ) ;
V_387 -> V_390 . V_73 = V_305 / ( 1 + V_387 -> V_274 ) ;
return 0 ;
}
if ( V_387 -> V_274 != 0 )
return - V_233 ;
V_387 -> type = V_391 ;
F_75 ( V_2 , V_306 , V_306 ,
& V_387 -> V_392 . V_393 , & V_387 -> V_392 . V_394 ) ;
if ( V_387 -> V_392 . V_393 < 48 )
V_387 -> V_392 . V_393 = 48 ;
if ( V_387 -> V_392 . V_394 < 38 )
V_387 -> V_392 . V_394 = 38 ;
V_387 -> V_392 . V_395 = V_304 ;
V_387 -> V_392 . V_396 = V_305 ;
V_387 -> V_392 . V_397 = 1 ;
V_387 -> V_392 . V_398 = 1 ;
return 0 ;
}
static int F_118 ( struct V_307 * V_307 , void * V_289 ,
struct V_308 * V_46 )
{
struct V_1 * V_2 = F_77 ( V_307 ) ;
struct V_3 * V_4 = V_2 -> V_4 ;
V_46 -> V_44 . V_399 . V_400 = V_4 -> V_56 ;
V_46 -> V_44 . V_399 . V_401 = V_402 ;
V_46 -> V_44 . V_399 . V_127 = 0 ;
V_46 -> V_44 . V_399 . V_203 = 0 ;
V_46 -> V_44 . V_399 . V_403 = 6750000 * 4 / 2 ;
V_46 -> V_44 . V_399 . V_238 [ 0 ] = V_4 -> V_58 ;
V_46 -> V_44 . V_399 . V_238 [ 1 ] = V_4 -> V_58 ;
memset ( V_46 -> V_44 . V_399 . V_404 , 0 , sizeof( V_46 -> V_44 . V_399 . V_404 ) ) ;
if ( V_4 -> V_10 & V_59 ) {
V_46 -> V_44 . V_399 . V_405 [ 0 ] = 10 ;
V_46 -> V_44 . V_399 . V_405 [ 1 ] = 273 ;
} else if ( V_4 -> V_10 & V_11 ) {
V_46 -> V_44 . V_399 . V_405 [ 0 ] = 6 ;
V_46 -> V_44 . V_399 . V_405 [ 1 ] = 318 ;
}
return 0 ;
}
static int F_119 ( struct V_307 * V_307 , void * V_289 ,
struct V_349 * V_350 )
{
struct V_1 * V_2 = F_77 ( V_307 ) ;
if ( F_116 ( V_350 -> V_274 > 0 ) )
return - V_233 ;
strcpy ( V_350 -> V_205 , L_51 ) ;
F_5 ( & V_2 -> V_4 -> V_17 , 0 , V_252 , V_351 , V_350 ) ;
return 0 ;
}
static int F_120 ( struct V_307 * V_307 , void * V_289 ,
const struct V_349 * V_350 )
{
struct V_1 * V_2 = F_77 ( V_307 ) ;
if ( 0 != V_350 -> V_274 )
return - V_233 ;
F_5 ( & V_2 -> V_4 -> V_17 , 0 , V_252 , V_352 , V_350 ) ;
return 0 ;
}
static void F_121 ( struct V_406 * V_407 )
{
struct V_3 * V_4 = F_64 ( V_407 , struct V_3 , V_407 ) ;
V_4 -> V_2 -> V_4 = NULL ;
F_122 ( V_4 ) ;
}
static int F_123 ( struct V_307 * V_408 )
{
struct V_365 * V_208 = F_112 ( V_408 ) ;
struct V_1 * V_2 = F_77 ( V_408 ) ;
struct V_3 * V_4 = V_2 -> V_4 ;
enum V_180 V_409 = 0 ;
int V_43 ;
switch ( V_208 -> V_248 ) {
case V_371 :
V_409 = V_182 ;
break;
case V_410 :
V_409 = V_184 ;
break;
case V_249 :
break;
default:
return - V_233 ;
}
F_11 ( L_52 ,
F_124 ( V_208 ) , V_411 [ V_409 ] ,
V_4 -> V_412 ) ;
if ( F_125 ( & V_2 -> V_413 ) )
return - V_414 ;
V_43 = F_126 ( V_408 ) ;
if ( V_43 ) {
F_19 ( & V_2 -> V_94 -> V_2 ,
L_53 ,
V_237 , V_43 ) ;
F_127 ( & V_2 -> V_413 ) ;
return V_43 ;
}
if ( V_4 -> V_412 == 0 ) {
F_128 ( V_2 , V_245 ) ;
if ( V_208 -> V_248 != V_249 )
F_15 ( V_2 ) ;
F_4 ( V_2 ) ;
}
if ( V_208 -> V_248 == V_249 ) {
F_11 ( L_54 ) ;
F_5 ( & V_4 -> V_17 , 0 , V_252 , V_415 ) ;
}
F_129 ( & V_2 -> V_407 ) ;
F_129 ( & V_4 -> V_407 ) ;
V_4 -> V_412 ++ ;
F_127 ( & V_2 -> V_413 ) ;
return 0 ;
}
static int F_130 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
if ( V_2 -> V_416 ) {
return 0 ;
}
if ( ! V_2 -> V_417 ) {
return 0 ;
}
if ( V_4 == NULL )
return 0 ;
F_131 ( & V_2 -> V_94 -> V_2 , L_55 ) ;
F_132 ( & V_2 -> V_413 ) ;
F_133 ( & V_4 -> V_17 ) ;
F_59 ( V_2 , V_245 ) ;
F_40 ( V_2 ) ;
if ( F_114 ( & V_4 -> V_383 ) ) {
F_131 ( & V_2 -> V_94 -> V_2 , L_56 ,
F_124 ( & V_4 -> V_383 ) ) ;
F_134 ( & V_4 -> V_383 ) ;
}
if ( F_114 ( & V_4 -> V_210 ) ) {
F_131 ( & V_2 -> V_94 -> V_2 , L_56 ,
F_124 ( & V_4 -> V_210 ) ) ;
F_134 ( & V_4 -> V_210 ) ;
}
if ( F_114 ( & V_4 -> V_208 ) ) {
F_131 ( & V_2 -> V_94 -> V_2 , L_56 ,
F_124 ( & V_4 -> V_208 ) ) ;
F_134 ( & V_4 -> V_208 ) ;
}
F_135 ( & V_4 -> V_297 ) ;
F_136 ( & V_4 -> V_17 ) ;
if ( V_4 -> V_418 ) {
F_137 ( V_4 -> V_418 ) ;
V_4 -> V_418 = NULL ;
}
F_138 ( & V_4 -> V_407 , F_121 ) ;
F_127 ( & V_2 -> V_413 ) ;
F_138 ( & V_2 -> V_407 , V_419 ) ;
return 0 ;
}
static int F_139 ( struct V_1 * V_2 )
{
if ( V_2 -> V_416 )
return 0 ;
if ( ! V_2 -> V_417 )
return 0 ;
F_131 ( & V_2 -> V_94 -> V_2 , L_57 ) ;
F_140 ( V_2 ) ;
return 0 ;
}
static int F_141 ( struct V_1 * V_2 )
{
if ( V_2 -> V_416 )
return 0 ;
if ( ! V_2 -> V_417 )
return 0 ;
F_131 ( & V_2 -> V_94 -> V_2 , L_58 ) ;
return 0 ;
}
static int F_142 ( struct V_307 * V_408 )
{
struct V_1 * V_2 = F_77 ( V_408 ) ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_92 * V_93 = F_17 ( V_2 -> V_94 ) ;
int V_95 ;
F_11 ( L_59 , V_4 -> V_412 ) ;
F_143 ( V_408 ) ;
F_132 ( & V_2 -> V_413 ) ;
if ( V_4 -> V_412 == 1 ) {
if ( V_2 -> V_174 )
goto exit;
F_5 ( & V_4 -> V_17 , 0 , V_18 , V_420 , 0 ) ;
F_128 ( V_2 , V_421 ) ;
V_2 -> V_98 = 0 ;
F_11 ( L_60 ) ;
V_95 = F_18 ( V_93 , 0 , 0 ) ;
if ( V_95 < 0 ) {
F_19 ( & V_2 -> V_94 -> V_2 ,
L_61 ,
V_95 ) ;
}
}
exit:
V_4 -> V_412 -- ;
F_138 ( & V_4 -> V_407 , F_121 ) ;
F_127 ( & V_2 -> V_413 ) ;
F_138 ( & V_2 -> V_407 , V_419 ) ;
return 0 ;
}
static void F_144 ( struct V_1 * V_2 ,
struct V_365 * V_422 ,
const struct V_365 * V_423 ,
const char * V_424 )
{
* V_422 = * V_423 ;
V_422 -> V_17 = & V_2 -> V_4 -> V_17 ;
V_422 -> V_413 = & V_2 -> V_413 ;
if ( V_2 -> V_5 . V_6 )
V_422 -> V_335 = 0 ;
snprintf ( V_422 -> V_205 , sizeof( V_422 -> V_205 ) , L_62 ,
F_145 ( & V_2 -> V_94 -> V_2 ) , V_424 ) ;
F_146 ( V_422 , V_2 ) ;
}
static void F_147 ( struct V_1 * V_2 , unsigned short V_425 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_16 * V_17 = & V_4 -> V_17 ;
struct V_426 V_427 ;
struct V_239 V_240 ;
memset ( & V_427 , 0 , sizeof( V_427 ) ) ;
V_427 . V_428 = V_429 | V_430 ;
V_427 . V_431 = V_432 ;
if ( V_2 -> V_5 . V_433 . type ) {
V_427 . type = V_2 -> V_5 . V_433 . type ;
V_427 . V_358 = V_2 -> V_5 . V_434 ;
F_5 ( V_17 ,
0 , V_252 , V_435 , & V_427 ) ;
}
if ( ( V_2 -> V_221 != V_222 ) && ( V_2 -> V_221 ) ) {
V_427 . type = V_2 -> V_221 ;
V_427 . V_358 = V_425 ;
F_5 ( V_17 ,
0 , V_252 , V_435 , & V_427 ) ;
}
if ( V_2 -> V_5 . V_436 ) {
struct V_437 V_438 ;
V_438 . V_252 = V_439 ;
V_438 . V_289 = & V_2 -> V_5 . V_436 ;
F_5 ( V_17 ,
0 , V_252 , V_440 , & V_438 ) ;
}
if ( V_2 -> V_221 == V_441 ) {
struct V_437 V_442 ;
struct V_443 V_444 ;
memset ( & V_442 , 0 , sizeof( V_442 ) ) ;
memset ( & V_444 , 0 , sizeof( V_444 ) ) ;
F_148 ( V_2 , & V_444 ) ;
V_442 . V_252 = V_441 ;
V_442 . V_289 = & V_444 ;
F_5 ( V_17 , 0 , V_252 , V_440 , & V_442 ) ;
}
V_240 . V_252 = 0 ;
V_240 . type = V_251 ;
V_240 . V_247 = 9076 ;
V_4 -> V_247 = V_240 . V_247 ;
F_5 ( V_17 , 0 , V_252 , V_253 , & V_240 ) ;
}
static int F_149 ( struct V_1 * V_2 )
{
T_1 V_293 ;
int V_43 ;
unsigned int V_304 ;
struct V_445 * V_446 ;
struct V_3 * V_4 ;
if ( V_2 -> V_416 ) {
return 0 ;
}
if ( ! V_2 -> V_417 ) {
return 0 ;
}
F_131 ( & V_2 -> V_94 -> V_2 , L_63 ) ;
F_132 ( & V_2 -> V_413 ) ;
V_4 = F_150 ( sizeof( struct V_3 ) , V_447 ) ;
if ( ! V_4 ) {
F_127 ( & V_2 -> V_413 ) ;
return - V_448 ;
}
F_151 ( & V_4 -> V_407 ) ;
V_4 -> V_2 = V_2 ;
V_2 -> V_4 = V_4 ;
#ifdef F_41
V_4 -> V_17 . V_192 = V_2 -> V_193 ;
#endif
V_43 = F_152 ( & V_2 -> V_94 -> V_2 , & V_4 -> V_17 ) ;
if ( V_43 < 0 ) {
F_19 ( & V_2 -> V_94 -> V_2 ,
L_64 ) ;
goto V_449;
}
V_446 = & V_4 -> V_297 ;
F_153 ( V_446 , 8 ) ;
V_4 -> V_17 . V_297 = V_446 ;
if ( V_2 -> V_5 . V_6 )
V_4 -> V_113 = true ;
V_4 -> V_51 = 0x10 ;
V_4 -> V_52 = V_450 |
V_451 ;
if ( V_2 -> V_5 . V_280 )
F_154 ( & V_4 -> V_17 ,
& V_2 -> V_452 [ V_2 -> V_453 ] ,
L_65 , 0 , V_454 ) ;
if ( V_2 -> V_5 . V_200 == V_455 )
F_154 ( & V_4 -> V_17 ,
& V_2 -> V_452 [ V_2 -> V_453 ] ,
L_66 , 0 , V_456 ) ;
if ( V_2 -> V_5 . V_200 == V_457 )
F_154 ( & V_4 -> V_17 ,
& V_2 -> V_452 [ V_2 -> V_453 ] ,
L_67 , 0 , V_458 ) ;
if ( V_2 -> V_5 . V_285 == V_459 )
F_154 ( & V_4 -> V_17 ,
& V_2 -> V_452 [ V_2 -> V_453 ] ,
L_68 , V_2 -> V_5 . V_460 , NULL ) ;
if ( V_2 -> V_5 . V_221 != V_222 ) {
unsigned short V_425 = V_2 -> V_5 . V_425 ;
int V_461 = ( V_2 -> V_5 . V_436 & V_462 ) ;
if ( V_2 -> V_5 . V_433 . type )
F_154 ( & V_4 -> V_17 ,
& V_2 -> V_452 [ V_2 -> V_453 ] ,
L_69 , V_2 -> V_5 . V_434 ,
NULL ) ;
if ( V_461 )
F_154 ( & V_4 -> V_17 ,
& V_2 -> V_452 [ V_2 -> V_453 ] ,
L_69 , 0 ,
F_155 ( V_463 ) ) ;
if ( V_425 == 0 ) {
enum V_464 type =
V_461 ? V_465 : V_466 ;
struct V_467 * V_468 ;
V_468 = F_154 ( & V_4 -> V_17 ,
& V_2 -> V_452 [ V_2 -> V_453 ] ,
L_69 , 0 ,
F_155 ( type ) ) ;
if ( V_468 )
V_425 = F_156 ( V_468 ) ;
} else {
F_154 ( & V_4 -> V_17 ,
& V_2 -> V_452 [ V_2 -> V_453 ] ,
L_69 , V_425 , NULL ) ;
}
F_147 ( V_2 , V_425 ) ;
}
if ( V_2 -> V_469 != V_470 )
F_157 ( V_2 ) ;
V_43 = F_158 ( V_2 ) ;
if ( V_43 < 0 ) {
F_19 ( & V_2 -> V_94 -> V_2 ,
L_70 ,
V_237 , V_43 ) ;
goto V_471;
}
if ( V_2 -> V_472 . V_473 != V_474 ) {
F_159 ( V_446 , & V_475 ,
V_291 , 0 , 1 , 1 , 1 ) ;
F_159 ( V_446 , & V_475 ,
V_294 , 0 , 0x1f , 1 , 0x1f ) ;
} else {
F_160 ( F_161 ( V_446 , V_291 ) ,
F_72 , V_2 ) ;
F_160 ( F_161 ( V_446 , V_294 ) ,
F_72 , V_2 ) ;
}
F_4 ( V_2 ) ;
F_162 ( & V_2 -> V_156 . V_147 ) ;
F_162 ( & V_2 -> V_158 . V_147 ) ;
if ( V_2 -> V_5 . V_280 ) {
V_43 = F_8 ( V_2 , V_476 , 0xf7 ) ;
if ( V_43 < 0 ) {
F_19 ( & V_2 -> V_94 -> V_2 ,
L_71 ,
V_237 , V_43 ) ;
goto V_471;
}
F_163 ( 3 ) ;
V_43 = F_8 ( V_2 , V_476 , 0xff ) ;
if ( V_43 < 0 ) {
F_19 ( & V_2 -> V_94 -> V_2 ,
L_72 ,
V_237 , V_43 ) ;
goto V_471;
}
F_163 ( 3 ) ;
}
V_4 -> V_10 = V_477 ;
F_5 ( & V_4 -> V_17 , 0 , V_20 , V_319 , V_4 -> V_10 ) ;
V_4 -> V_315 = V_478 ;
V_4 -> V_46 = & V_46 [ 0 ] ;
V_304 = F_1 ( V_2 ) ;
if ( V_2 -> V_5 . V_85 )
V_304 /= 2 ;
F_82 ( V_2 , V_46 [ 0 ] . V_311 ,
V_304 , F_2 ( V_2 ) ) ;
F_69 ( V_2 , 0 ) ;
V_2 -> V_292 = 1 ;
V_2 -> V_295 = 0x1f ;
V_293 = ( T_1 ) F_106 ( V_2 , V_479 ) ;
F_8 ( V_2 , V_479 ,
( V_480 | V_293 ) ) ;
F_9 ( V_2 ) ;
if ( NULL == F_161 ( V_446 , V_298 ) )
F_159 ( V_446 , & V_475 ,
V_298 ,
0 , 0x1f , 1 , V_25 ) ;
if ( NULL == F_161 ( V_446 , V_299 ) )
F_159 ( V_446 , & V_475 ,
V_299 ,
- 0x80 , 0x7f , 1 , V_27 ) ;
if ( NULL == F_161 ( V_446 , V_300 ) )
F_159 ( V_446 , & V_475 ,
V_300 ,
0 , 0x1f , 1 , V_29 ) ;
if ( NULL == F_161 ( V_446 , V_301 ) )
F_159 ( V_446 , & V_475 ,
V_301 ,
- 0x30 , 0x30 , 1 , V_31 ) ;
if ( NULL == F_161 ( V_446 , V_302 ) )
F_159 ( V_446 , & V_475 ,
V_302 ,
- 0x30 , 0x30 , 1 , V_33 ) ;
if ( NULL == F_161 ( V_446 , V_303 ) )
F_159 ( V_446 , & V_475 ,
V_303 ,
0 , 0x0f , 1 , V_35 ) ;
F_7 ( V_2 ) ;
F_164 ( V_446 ) ;
V_43 = V_446 -> error ;
if ( V_43 )
goto V_471;
F_144 ( V_2 , & V_4 -> V_208 , & V_481 , L_73 ) ;
F_165 ( & V_4 -> V_482 ) ;
F_165 ( & V_4 -> V_483 ) ;
V_4 -> V_208 . V_484 = & V_4 -> V_258 ;
V_4 -> V_208 . V_484 -> V_413 = & V_4 -> V_482 ;
if ( V_2 -> V_5 . V_6 ) {
F_166 ( & V_4 -> V_208 , V_485 ) ;
F_166 ( & V_4 -> V_208 , V_486 ) ;
F_166 ( & V_4 -> V_208 , V_487 ) ;
} else {
F_166 ( & V_4 -> V_208 , V_488 ) ;
}
if ( V_2 -> V_221 == V_222 ) {
F_166 ( & V_4 -> V_208 , V_489 ) ;
F_166 ( & V_4 -> V_208 , V_490 ) ;
F_166 ( & V_4 -> V_208 , V_491 ) ;
F_166 ( & V_4 -> V_208 , V_492 ) ;
}
if ( V_2 -> V_378 == V_379 ) {
F_166 ( & V_4 -> V_208 , V_493 ) ;
F_166 ( & V_4 -> V_208 , V_494 ) ;
}
V_43 = F_167 ( & V_4 -> V_208 , V_371 ,
V_495 [ V_2 -> V_496 ] ) ;
if ( V_43 ) {
F_19 ( & V_2 -> V_94 -> V_2 ,
L_74 , V_43 ) ;
goto V_471;
}
if ( F_3 ( V_2 ) == 1 ) {
F_144 ( V_2 , & V_4 -> V_210 , & V_481 ,
L_75 ) ;
V_4 -> V_210 . V_484 = & V_4 -> V_272 ;
V_4 -> V_210 . V_484 -> V_413 = & V_4 -> V_483 ;
F_166 ( & V_4 -> V_210 , V_488 ) ;
if ( V_2 -> V_221 == V_222 ) {
F_166 ( & V_4 -> V_210 , V_489 ) ;
F_166 ( & V_4 -> V_210 , V_490 ) ;
F_166 ( & V_4 -> V_210 , V_491 ) ;
F_166 ( & V_4 -> V_210 , V_492 ) ;
}
if ( V_2 -> V_378 == V_379 ) {
F_166 ( & V_4 -> V_210 , V_493 ) ;
F_166 ( & V_4 -> V_210 , V_494 ) ;
}
V_43 = F_167 ( & V_4 -> V_210 , V_410 ,
V_497 [ V_2 -> V_496 ] ) ;
if ( V_43 < 0 ) {
F_19 ( & V_2 -> V_94 -> V_2 ,
L_76 ) ;
goto V_471;
}
}
if ( V_368 [ V_2 -> V_369 ] . V_433 . type == V_498 ) {
F_144 ( V_2 , & V_4 -> V_383 , & V_499 ,
L_77 ) ;
V_43 = F_167 ( & V_4 -> V_383 , V_249 ,
V_500 [ V_2 -> V_496 ] ) ;
if ( V_43 < 0 ) {
F_19 ( & V_2 -> V_94 -> V_2 ,
L_78 ) ;
goto V_471;
}
F_131 ( & V_2 -> V_94 -> V_2 ,
L_79 ,
F_124 ( & V_4 -> V_383 ) ) ;
}
F_46 ( V_2 ) ;
#ifdef F_41
V_43 = F_168 ( V_2 -> V_193 ) ;
if ( V_43 ) {
F_19 ( & V_2 -> V_94 -> V_2 ,
L_80 ) ;
F_40 ( V_2 ) ;
goto V_471;
}
#endif
F_131 ( & V_2 -> V_94 -> V_2 ,
L_81 ,
F_124 ( & V_4 -> V_208 ) ) ;
if ( F_114 ( & V_4 -> V_210 ) )
F_131 ( & V_2 -> V_94 -> V_2 ,
L_82 ,
F_124 ( & V_4 -> V_210 ) ) ;
F_5 ( & V_4 -> V_17 , 0 , V_18 , V_420 , 0 ) ;
F_67 ( V_2 ) ;
F_131 ( & V_2 -> V_94 -> V_2 ,
L_83 ) ;
F_129 ( & V_2 -> V_407 ) ;
F_127 ( & V_2 -> V_413 ) ;
return 0 ;
V_471:
if ( F_114 ( & V_4 -> V_383 ) ) {
F_131 ( & V_2 -> V_94 -> V_2 ,
L_56 ,
F_124 ( & V_4 -> V_383 ) ) ;
F_134 ( & V_4 -> V_383 ) ;
}
if ( F_114 ( & V_4 -> V_210 ) ) {
F_131 ( & V_2 -> V_94 -> V_2 ,
L_56 ,
F_124 ( & V_4 -> V_210 ) ) ;
F_134 ( & V_4 -> V_210 ) ;
}
if ( F_114 ( & V_4 -> V_208 ) ) {
F_131 ( & V_2 -> V_94 -> V_2 ,
L_56 ,
F_124 ( & V_4 -> V_208 ) ) ;
F_134 ( & V_4 -> V_208 ) ;
}
F_135 ( & V_4 -> V_297 ) ;
F_136 ( & V_4 -> V_17 ) ;
V_449:
V_2 -> V_4 = NULL ;
F_138 ( & V_4 -> V_407 , F_121 ) ;
F_127 ( & V_2 -> V_413 ) ;
return V_43 ;
}
static int T_5 F_169 ( void )
{
return F_170 ( & V_501 ) ;
}
static void T_6 F_171 ( void )
{
F_172 ( & V_501 ) ;
}
