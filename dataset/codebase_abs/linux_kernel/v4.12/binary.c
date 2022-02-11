static void
F_1 ( const struct V_1 * V_2 ,
const struct V_3 * V_4 ,
struct V_3 * V_5 )
{
if ( V_2 -> V_6 . V_7 ) {
assert ( V_4 != NULL ) ;
V_5 -> V_8 = F_2 ( V_4 -> V_8 , V_9 ) ;
V_5 -> V_10 = F_2 ( V_4 -> V_10 , V_9 ) ;
}
}
static void
F_3 ( const struct V_11 * V_12 ,
const struct V_11 * V_13 ,
const struct V_11 * V_14 ,
const struct V_3 * V_4 ,
const struct V_1 * V_2 ,
struct V_3 * V_15 )
{
unsigned int V_16 = 0 ,
V_17 = 0 ;
bool V_18 = V_2 -> V_6 . V_19 & 2 ;
struct V_3 V_5 ;
V_5 . V_8 = 0 ;
V_5 . V_10 = 0 ;
F_1 ( V_2 , V_4 , & V_5 ) ;
if ( V_18 ) {
if ( V_12 != NULL ) {
V_16 = V_12 -> V_20 . V_8
+ V_2 -> V_21 . V_22 + V_5 . V_8 ;
V_17 = V_12 -> V_20 . V_10
+ V_2 -> V_21 . V_23 + V_5 . V_10 ;
}
} else if ( ( V_13 != NULL ) && ( V_14 != NULL ) &&
( V_13 -> V_20 . V_8 >= V_14 -> V_20 . V_8 ) ) {
V_16 = V_13 -> V_24 ;
V_17 = V_13 -> V_20 . V_10 ;
} else {
if ( V_14 != NULL ) {
V_16 = V_14 -> V_24 ;
V_17 = V_14 -> V_20 . V_10 ;
}
}
V_15 -> V_8 = F_4 ( V_16 ,
( int ) V_5 . V_8 ,
V_2 -> V_21 . V_22 , V_2 -> V_21 . V_25 ,
V_2 -> V_21 . V_26 ,
V_2 -> V_27 . V_28 , V_2 -> V_21 . V_29 ) ;
V_15 -> V_10 = F_5 ( V_17 ,
V_2 -> V_21 . V_23 ,
V_5 . V_10 ) ;
#if F_6 ( V_30 )
V_15 -> V_10 = ( V_13 == NULL ) ? V_15 -> V_10 : V_13 -> V_20 . V_10 ;
V_15 -> V_8 = ( V_13 == NULL ) ? V_15 -> V_8 : V_13 -> V_20 . V_8 ;
#endif
}
static enum V_31
#ifndef F_7
F_8 (
const struct V_32 * V_33 ,
unsigned int V_34 ,
const struct V_35 * V_36 ,
struct V_37 * V_20 )
#else
sh_css_binary_get_sc_requirements(
const struct V_32 * V_33 ,
unsigned int V_34 ,
const struct V_35 * V_36 ,
struct V_38 * V_39 )
#endif
{
enum V_31 V_40 ;
#ifndef F_7
#else
#endif
unsigned int V_41 , V_42 ;
#ifndef F_7
unsigned int V_43 ;
unsigned int V_44 ;
unsigned int V_45 ;
unsigned int V_46 ;
#else
unsigned int V_43 , V_44 , V_45 , V_46 ;
#endif
#ifndef F_7
unsigned int V_47 ;
#else
unsigned int V_47 ;
#endif
#ifndef F_7
unsigned int V_48 ;
unsigned int V_49 ;
unsigned int V_50 ;
unsigned int V_51 ;
unsigned int V_52 ;
unsigned int V_53 ;
V_40 = F_9
( V_34 , & V_41 , & V_42 ) ;
if ( V_40 != V_54 )
#else
unsigned int V_48 , V_55 , V_56 ;
unsigned int V_49 ;
unsigned int V_57 ;
int V_58 = V_59 ;
unsigned int V_60 ;
unsigned int V_61 ;
unsigned int V_62 ;
unsigned int V_63 ;
unsigned int V_64 ;
unsigned int V_65 ;
F_10 ( L_1 ,
V_33 , V_34 , V_36 ) ;
V_40 = F_9 ( V_34 , & V_41 , & V_42 ) ;
if ( V_40 != V_54 ) {
F_11 ( V_40 ) ;
#endif
return V_40 ;
#ifdef F_7
}
#endif
#ifndef F_7
#else
F_12 ( L_2 , V_41 , V_42 ) ;
#endif
V_43 = V_41 ;
V_44 = V_42 ;
V_45 = V_41 ;
V_46 = V_42 ;
#ifndef F_7
#else
#endif
if ( V_36 -> V_66 == - 1 )
V_47 = F_13 ( V_33 -> V_66 ) ;
else
#ifndef F_7
V_47 = ( unsigned int ) ( ( int ) V_67
- F_13 ( V_36 -> V_66 ) ) ;
#else
V_47 = ( unsigned int ) ( ( int ) V_67 - F_13 ( V_36 -> V_66 ) ) ;
#endif
#ifndef F_7
#else
F_12 ( L_3 ,
V_36 -> V_66 , V_33 -> V_66 , V_47 ) ;
#endif
V_48 = ( ( V_33 -> V_2 -> V_68 . V_69 . V_70 &
( F_14 ( V_71 ) |
F_14 ( V_72 ) |
F_14 ( V_73 ) |
F_14 ( V_74 ) |
F_14 ( V_75 ) |
F_14 ( V_76 ) |
F_14 ( V_77 ) |
F_14 ( V_78 ) ) ) != 0 ) ;
#ifndef F_7
if ( V_48 && V_33 -> V_2 -> V_68 . V_21 . V_22 > 0 )
V_49 = V_47 + V_67 ;
else
#else
V_55 = ( ( V_33 -> V_2 -> V_68 . V_69 . V_70 &
( F_14 ( V_79 ) |
F_14 ( V_80 ) |
F_14 ( V_73 ) |
F_14 ( V_75 ) |
F_14 ( V_77 ) ) ) != 0 ) ;
V_56 = ( ( V_33 -> V_2 -> V_68 . V_69 . V_70 &
( F_14 ( V_81 ) |
F_14 ( V_72 ) |
F_14 ( V_76 ) ) ) != 0 ) ;
if ( V_33 -> V_2 -> V_68 . V_21 . V_22 > 0 &&
( V_48 || V_55 || V_56 ) ) {
unsigned int V_82
= V_67 * V_43 / V_44 ;
V_49 = V_82
- F_13 ( V_33 -> V_2 -> V_68 . V_21 . V_22 ) ;
} else
#endif
V_49 = V_47 ;
#ifndef F_7
V_50 = 0 ;
V_52 = 0 ;
#else
F_12 ( L_4 ,
V_33 -> V_2 -> V_68 . V_69 . V_70 ,
V_48 , V_55 , V_56 ) ;
F_12 ( L_5 ,
V_33 -> V_2 -> V_68 . V_21 . V_22 , V_49 ) ;
V_57 = 0 ;
if ( V_33 -> V_2 -> V_68 . V_21 . V_23 > 0 &&
( V_34 == V_81 ||
V_34 == V_79 ||
V_34 == V_71 ) ) {
int V_83 = F_13 ( V_33 -> V_2 -> V_68 . V_21 . V_23 ) ;
int V_84 = V_41 * V_58 / V_42 ;
int V_85 = ( V_83 * V_84 - V_83 * V_58 )
+ ( 2 * V_58 - V_84 ) ;
V_57 = ( unsigned int ) ( ( V_85 + V_58 / 2 - 1 ) / V_58 ) ;
}
F_12 ( L_6 , V_33 -> V_2 -> V_68 . V_21 . V_23 , V_57 ) ;
V_60 = 0 ;
V_62 = 0 ;
#endif
#ifndef F_7
V_51 = 0 ;
V_53 = 0 ;
#else
if ( V_48 || V_55 || V_56 ) {
V_60 = 1 ;
V_62 = 1 ;
}
F_12 ( L_7 ,
V_60 , V_62 ) ;
V_61 = 0 ;
V_63 = 0 ;
#endif
#ifndef F_7
V_20 -> V_86
= ( ( V_49 + V_50 )
* V_44 + V_43 / 2 ) / V_43
+ V_51 ;
V_20 -> V_87
= ( V_52
* V_46 + V_45 / 2 ) / V_45
+ V_53 ;
V_20 -> V_88 = ( V_89 ) V_43 ;
V_20 -> V_90 = ( V_89 ) V_44 ;
V_20 -> V_91 = ( V_89 ) V_45 ;
V_20 -> V_92 = ( V_89 ) V_46 ;
#else
if ( V_33 -> V_2 -> V_93 . V_94 . V_95 -> V_96 . V_97 . V_98 != 0 ) {
V_61 = 1 ;
V_63 = 1 ;
}
F_12 ( L_8 ,
V_61 , V_63 ) ;
{
unsigned int V_99 = V_58 ;
unsigned int V_100 , V_101 ;
V_100 = V_44 * V_99 ;
V_101 = V_43 * V_99 ;
V_64
= ( ( V_49 + V_60 ) * V_100 + V_101 / 2 ) / V_101
+ V_61 ;
V_100 = V_46 * V_99 ;
V_101 = V_45 * V_99 ;
V_65
= ( ( V_57 + V_62 ) * V_100 + V_101 / 2 ) / V_101
+ V_63 ;
}
V_39 -> V_88 = ( V_89 ) V_43 ;
V_39 -> V_90 = ( V_89 ) V_44 ;
V_39 -> V_91 = ( V_89 ) V_45 ;
V_39 -> V_92 = ( V_89 ) V_46 ;
V_39 -> V_64 = ( V_89 ) V_64 ;
V_39 -> V_65 = ( V_89 ) V_65 ;
F_12 ( L_9 ,
V_39 -> V_88 , V_39 -> V_90 ,
V_39 -> V_91 , V_39 -> V_92 ,
V_39 -> V_64 , V_39 -> V_65 ) ;
#endif
#ifdef F_7
F_11 ( V_40 ) ;
#endif
return V_40 ;
}
static void F_15 ( const struct V_32 * V_33 ,
struct V_102 * V_2 )
{
assert ( V_33 != NULL ) ;
assert ( V_2 != NULL ) ;
V_2 -> V_103 = V_33 -> V_104 . V_20 . V_8 ;
V_2 -> V_105 = V_33 -> V_104 . V_20 . V_10 ;
V_2 -> V_106 = V_107 ;
}
void
F_16 ( const struct V_32 * V_33 ,
struct V_102 * V_2 ,
struct V_108 * V_109 )
{
struct V_110 * V_111 ;
( void ) V_109 ;
assert ( V_33 != NULL ) ;
assert ( V_2 != NULL ) ;
V_111 = & V_2 -> V_112 . V_113 ;
V_111 -> V_6 = V_33 -> V_2 -> V_68 . V_6 . V_114 ;
V_111 -> V_8 = V_33 -> V_114 . V_115 . V_116 . V_8 ;
V_111 -> V_10 = V_33 -> V_114 . V_115 . V_116 . V_10 ;
V_111 -> V_117 = V_33 -> V_114 . V_115 . V_118 . V_8 ;
V_111 -> V_119 = V_33 -> V_114 . V_115 . V_118 . V_10 ;
V_111 -> V_120 = 1 << V_33 -> V_114 . V_121 ;
V_111 -> V_122 = V_33 -> V_114 . V_123 . V_116 . V_8 ;
V_111 -> V_124 = V_33 -> V_114 . V_123 . V_116 . V_10 ;
F_15 ( V_33 , V_2 ) ;
}
void
F_17 (
const struct V_32 * V_33 ,
struct V_102 * V_2 ,
struct V_108 * V_109 )
{
#if F_6 ( V_30 )
struct V_125 * V_126 ;
unsigned int V_127 ;
assert ( V_33 != NULL ) ;
assert ( V_2 != NULL ) ;
V_126 = & V_2 -> V_112 . V_128 ;
if ( V_33 -> V_2 -> V_68 . V_6 . V_129 ) {
for ( V_127 = 0 ; V_127 < V_130 ; V_127 ++ ) {
V_126 -> V_131 [ V_127 ] . V_132 . V_6 = 1 ;
}
F_18 ( V_109 , V_126 ) ;
}
else {
memset ( V_126 , 0 , sizeof( struct V_125 ) ) ;
}
#endif
( void ) V_109 ;
F_15 ( V_33 , V_2 ) ;
return;
}
enum V_31
F_19 ( const struct V_32 * V_33 ,
struct V_102 * V_2 ,
struct V_108 * V_109 )
{
struct V_133 * V_134 ;
enum V_31 V_40 = V_54 ;
F_10 ( L_10 ,
V_33 , V_2 , V_109 ) ;
assert ( V_33 != NULL ) ;
assert ( V_2 != NULL ) ;
V_134 = & V_2 -> V_135 ;
V_134 -> V_6 = V_33 -> V_2 -> V_68 . V_6 . V_136 ;
V_134 -> V_8 = V_33 -> V_137 ;
V_134 -> V_10 = V_33 -> V_138 ;
V_134 -> V_117 = V_33 -> V_139 ;
V_134 -> V_119 = V_33 -> V_140 ;
V_134 -> V_120 = ( 1 << V_33 -> V_121 ) ;
V_134 -> V_121 = V_33 -> V_121 ;
V_134 -> V_141 = V_142 ;
V_134 -> V_143 = V_33 -> V_2 -> V_68 . V_136 . V_144 ;
#if F_6 ( V_145 )
V_134 -> V_146 = 1 ;
#else
V_134 -> V_146 = 0 ;
#endif
F_11 ( V_40 ) ;
return V_40 ;
}
static void
F_20 ( struct V_147 * V_148 )
{
assert ( V_148 != NULL ) ;
V_148 -> V_149 = 0 ;
V_148 -> V_150 = NULL ;
V_148 -> V_151 = NULL ;
}
static void
F_21 ( struct V_152 * V_153 ,
const struct V_1 * V_2 )
{
assert ( V_153 != NULL ) ;
assert ( V_2 != NULL ) ;
V_153 -> V_25 = V_2 -> V_21 . V_25 ;
V_153 -> V_154 = V_2 -> V_154 ;
V_153 -> V_155 = NULL ;
F_20 ( & V_153 -> V_156 ) ;
F_20 ( & V_153 -> V_157 ) ;
}
static bool
F_22 ( const struct V_158 * V_2 ,
enum V_159 V_160 )
{
int V_127 ;
assert ( V_2 != NULL ) ;
for ( V_127 = 0 ; V_127 < V_2 -> V_161 ; V_127 ++ ) {
if ( V_2 -> V_162 [ V_127 ] == V_160 )
return true ;
}
return false ;
}
static bool
F_23 ( const struct V_158 * V_2 ,
enum V_163 V_160 )
{
assert ( V_2 != NULL ) ;
( void ) V_160 ;
return true ;
}
static bool
F_24 ( const struct V_158 * V_2 ,
enum V_159 V_160 )
{
int V_127 ;
assert ( V_2 != NULL ) ;
for ( V_127 = 0 ; V_127 < V_2 -> V_164 ; V_127 ++ ) {
if ( V_2 -> V_165 [ V_127 ] == V_160 )
return true ;
}
return false ;
}
static bool
F_25 ( V_89 V_166 ,
V_89 V_167 )
{
return ( ( V_166 & F_14 ( V_167 ) ) != 0 ) ;
}
static enum V_31
F_26 ( struct V_158 * V_2 , unsigned int V_127 ,
bool * V_168 )
{
const unsigned char * V_169 = V_170 [ V_127 ] . V_169 ;
unsigned V_98 = V_170 [ V_127 ] . V_171 . V_169 . V_98 ;
if ( ( V_2 == NULL ) || ( V_168 == NULL ) )
return V_172 ;
* V_2 = V_170 [ V_127 ] . V_171 . V_2 . V_173 ;
* V_168 = V_169 != NULL ;
V_2 -> V_174 = V_127 ;
if ( ! V_98 )
return V_54 ;
V_2 -> V_175 = F_27 ( V_169 , V_98 ) ;
if ( ! V_2 -> V_175 )
return V_176 ;
return V_54 ;
}
enum V_31
F_28 ( void )
{
unsigned int V_127 ;
unsigned int V_177 = V_178 - V_179 - V_180 ;
if ( V_177 == 0 )
return V_54 ;
V_181 = F_29 ( V_177 *
sizeof( * V_181 ) ) ;
if ( V_181 == NULL )
return V_176 ;
for ( V_127 = 0 ; V_127 < V_177 ; V_127 ++ ) {
enum V_31 V_182 ;
struct V_158 * V_33 = & V_181 [ V_127 ] ;
bool V_168 ;
V_182 = F_26 ( V_33 , V_127 , & V_168 ) ;
if ( V_182 != V_54 )
return V_182 ;
if ( ! V_168 )
continue;
V_33 -> V_155 = V_183 [ V_33 -> V_68 . V_21 . V_25 ] ;
V_183 [ V_33 -> V_68 . V_21 . V_25 ] = V_33 ;
V_33 -> V_169 = & V_170 [ V_127 ] ;
V_33 -> V_93 = V_170 [ V_127 ] . V_93 ;
}
return V_54 ;
}
enum V_31
F_30 ( void )
{
unsigned int V_127 ;
struct V_158 * V_184 ;
for ( V_127 = 0 ; V_127 < V_185 ; V_127 ++ ) {
for ( V_184 = V_183 [ V_127 ] ; V_184 ; V_184 = V_184 -> V_155 ) {
if ( V_184 -> V_175 )
F_31 ( V_184 -> V_175 ) ;
V_184 -> V_175 = V_186 ;
}
V_183 [ V_127 ] = NULL ;
}
F_32 ( V_181 ) ;
return V_54 ;
}
static int
F_33 ( int V_8 , int V_10 )
{
#define F_34 5
#define F_35 3
#define F_36 1280
#define F_37 640
int V_187 ;
int V_188 ;
assert ( F_38 ( V_8 , F_34 ) <= V_189 ) ;
assert ( F_39 ( V_10 , F_34 ) <= V_190 ) ;
V_187 = F_34 ;
while ( F_38 ( V_8 , V_187 - 1 ) <= V_189 &&
F_39 ( V_10 , V_187 - 1 ) <= V_190
&& V_187 > F_35 )
V_187 -- ;
if ( F_13 ( V_8 ) >= F_36 )
V_188 = 5 ;
else if ( F_13 ( V_8 ) >= F_37 )
V_188 = 4 ;
else
V_188 = 3 ;
return F_2 ( V_187 , V_188 ) ;
#undef F_34
#undef F_35
#undef F_36
#undef F_37
}
static int
F_40 ( int V_191 ,
int V_192 ,
int V_193 ,
int V_194 ,
int V_22 ,
bool V_195 )
{
int V_196 ;
int V_197 ;
#if F_6 ( V_198 )
V_197 = 0 ;
#else
V_197 = 2 * V_67 ;
#endif
#if F_6 ( V_30 )
( void ) V_193 ;
#endif
if ( V_195 ) {
if ( V_194 != - 1 ) {
V_196 =
F_41 ( V_191 + V_197 ,
2 * V_67 ) ;
} else {
#if ! F_6 ( V_30 )
V_191 += V_193 ;
#endif
V_196 =
F_41 ( V_191 +
( V_22 ? V_197 : 0 ) ,
2 * V_67 ) ;
}
} else {
V_196 = V_192 ;
}
return V_196 ;
}
enum V_31
F_42 ( const struct V_158 * V_199 ,
bool V_200 ,
bool V_201 ,
enum V_163 V_202 ,
const struct V_11 * V_12 ,
const struct V_11 * V_13 ,
const struct V_11 * V_14 [] ,
const struct V_11 * V_203 ,
struct V_32 * V_33 ,
struct V_3 * V_4 ,
int V_194 ,
bool V_204 )
{
const struct V_1 * V_2 = & V_199 -> V_68 ;
unsigned int V_193 = 0 ,
V_205 = 0 ,
V_206 = 0 ,
V_207 = 0 ,
V_208 = 0 ,
V_209 = 0 ,
V_210 = 0 ,
V_211 = 0 ,
V_192 = 0 ,
V_212 = 0 ,
V_213 = 0 ;
bool V_195 = false ;
struct V_3 V_5 , V_15 ;
enum V_31 V_40 ;
unsigned int V_127 ;
const struct V_11 * V_214 = NULL ;
assert ( V_2 != NULL ) ;
assert ( V_33 != NULL ) ;
V_33 -> V_2 = V_199 ;
if ( ! V_204 ) {
V_40 = F_43 (
& V_33 -> V_215 , & V_33 -> V_216 ,
& V_2 -> V_217 ) ;
if ( V_40 != V_54 ) {
return V_40 ;
}
}
for ( V_127 = 0 ; V_127 < V_218 ; V_127 ++ ) {
if ( V_14 [ V_127 ] && ( V_14 [ V_127 ] -> V_20 . V_8 != 0 ) ) {
V_214 = V_14 [ V_127 ] ;
break;
}
}
if ( V_12 != NULL && V_214 != NULL ) {
V_195 = ( V_12 -> V_20 . V_8 != V_214 -> V_20 . V_8 ) ||
( V_12 -> V_20 . V_10 != V_214 -> V_20 . V_10 ) ;
}
V_5 . V_8 = 0 ;
V_5 . V_10 = 0 ;
F_1 ( V_2 , V_4 , & V_5 ) ;
V_193 = V_5 . V_8 ;
V_205 = V_5 . V_10 ;
V_33 -> V_7 . V_8 = V_193 ;
V_33 -> V_7 . V_10 = V_205 ;
V_15 . V_8 = 0 ;
V_15 . V_10 = 0 ;
F_3 ( V_12 , V_13 , V_214 , V_4 ,
V_2 , & V_15 ) ;
V_192 = V_15 . V_8 ;
V_212 = V_15 . V_10 ;
if ( V_214 != NULL )
V_33 -> V_104 . V_160 = V_214 -> V_160 ;
V_33 -> V_104 . V_20 . V_8 = V_192 ;
V_33 -> V_104 . V_24 = F_41 ( V_192 , 2 * V_67 ) ;
V_33 -> V_104 . V_20 . V_10 = V_212 ;
V_33 -> V_104 . V_219 = V_208 ;
if ( V_12 != NULL ) {
V_33 -> V_220 . V_8 = V_12 -> V_20 . V_8 ;
V_33 -> V_220 . V_10 = V_12 -> V_20 . V_10 ;
V_208 = V_12 -> V_219 ;
V_33 -> V_221 . V_20 . V_8 = V_12 -> V_20 . V_8 + V_2 -> V_21 . V_22 ;
V_33 -> V_221 . V_20 . V_10 = V_12 -> V_20 . V_10 + V_2 -> V_21 . V_23 ;
#if ! F_6 ( V_30 )
V_33 -> V_221 . V_20 . V_8 += V_193 ;
V_33 -> V_221 . V_20 . V_10 += V_205 ;
#endif
V_33 -> V_221 . V_24 =
F_40 ( V_12 -> V_20 . V_8 ,
V_192 ,
V_193 ,
V_194 ,
V_2 -> V_21 . V_22 ,
V_195 ) ;
V_33 -> V_221 . V_160 = V_12 -> V_160 ;
V_33 -> V_221 . V_222 = V_12 -> V_222 ;
V_33 -> V_221 . V_223 = V_12 -> V_223 ;
}
if ( V_200 ) {
V_208 = F_44 (
V_202 , V_201 ) ;
}
V_33 -> V_221 . V_219 = V_208 ;
for ( V_127 = 0 ; V_127 < V_218 ; V_127 ++ ) {
if ( V_14 [ V_127 ] != NULL ) {
V_33 -> V_224 [ V_127 ] . V_20 . V_8 = V_14 [ V_127 ] -> V_20 . V_8 ;
V_33 -> V_224 [ V_127 ] . V_20 . V_10 = V_14 [ V_127 ] -> V_20 . V_10 ;
V_33 -> V_224 [ V_127 ] . V_24 = V_14 [ V_127 ] -> V_24 ;
if ( V_2 -> V_21 . V_25 == V_225 ) {
V_33 -> V_224 [ V_127 ] . V_219 = V_208 ;
} else {
V_33 -> V_224 [ V_127 ] . V_219 = 16 ;
}
V_33 -> V_224 [ V_127 ] . V_160 = V_14 [ V_127 ] -> V_160 ;
}
}
if ( V_203 && ( V_203 -> V_20 . V_8 != 0 ) ) {
V_40 = F_45 ( V_33 , V_214 , (struct V_11 * ) V_203 , & V_206 ) ;
if ( V_40 != V_54 ) {
if ( ! V_204 ) {
F_46 (
& V_33 -> V_215 ,
& V_33 -> V_216 ) ;
}
return V_40 ;
}
}
V_33 -> V_226 = V_206 ;
V_33 -> V_200 = V_200 ;
V_33 -> V_227 = V_202 ;
if ( ( V_203 != NULL ) && ( V_203 -> V_20 . V_8 != 0 ) ) {
unsigned int V_228 , V_229 , V_230 ;
V_33 -> V_231 . V_160 = V_203 -> V_160 ;
if ( V_214 == NULL )
return V_232 ;
V_228 = F_47 ( V_214 -> V_24 ,
V_206 ) ;
V_229 = F_48 ( V_228 ) ;
V_230 = F_49 ( V_214 -> V_20 . V_10 ,
V_206 ) ;
if ( V_2 -> V_21 . V_25 == V_233 ) {
V_33 -> V_224 [ 0 ] . V_20 . V_8 =
( V_214 -> V_20 . V_8 >> V_206 ) ;
V_33 -> V_224 [ 0 ] . V_24 = V_229 ;
V_33 -> V_224 [ 0 ] . V_20 . V_10 = V_230 ;
V_33 -> V_231 . V_20 . V_8 = 0 ;
V_33 -> V_231 . V_24 = 0 ;
V_33 -> V_231 . V_20 . V_10 = 0 ;
} else {
V_33 -> V_231 . V_20 . V_8 =
( V_214 -> V_20 . V_8 >> V_206 ) ;
V_33 -> V_231 . V_24 = V_229 ;
V_33 -> V_231 . V_20 . V_10 = V_230 ;
}
} else {
V_33 -> V_231 . V_20 . V_8 = 0 ;
V_33 -> V_231 . V_24 = 0 ;
V_33 -> V_231 . V_20 . V_10 = 0 ;
}
if ( V_2 -> V_6 . V_234 ) {
V_33 -> V_235 =
F_50 ( V_192 ) ;
V_33 -> V_236 =
F_51 ( V_192 ) ;
V_33 -> V_237 =
F_52 ( V_212 ) ;
} else {
V_33 -> V_235 = 0 ;
V_33 -> V_236 = 0 ;
V_33 -> V_237 = 0 ;
}
V_209 = V_33 -> V_221 . V_20 . V_8 ;
V_210 = V_33 -> V_221 . V_24 ;
V_211 = V_33 -> V_221 . V_20 . V_10 ;
if ( V_13 != NULL && V_12 != NULL &&
V_13 -> V_20 . V_8 != V_12 -> V_20 . V_8 ) {
V_209 = V_13 -> V_20 . V_8 + V_2 -> V_21 . V_22 ;
V_210 = V_192 ;
V_211 = V_212 ;
}
V_213 = F_53 ( V_210 ,
V_2 -> V_21 . V_22 ) ;
if ( V_2 -> V_136 . V_238 ) {
V_207 = V_2 -> V_136 . V_238 ;
} else {
V_207 = F_33 ( V_213 ,
V_211 ) ;
}
V_33 -> V_121 = V_207 ;
if ( V_2 -> V_6 . V_136 ) {
V_33 -> V_137 =
F_54 ( V_209 ,
V_207 ) ;
V_33 -> V_138 =
F_55 ( V_211 ,
V_207 ) ;
V_33 -> V_139 =
F_56 ( V_213 ,
V_207 ) ;
V_33 -> V_140 =
F_57 ( V_211 ,
V_207 ) ;
} else {
V_33 -> V_137 = 0 ;
V_33 -> V_138 = 0 ;
V_33 -> V_139 = 0 ;
V_33 -> V_140 = 0 ;
}
if ( V_2 -> V_6 . V_239 ) {
V_33 -> V_240 =
#ifndef F_7
F_58 ( V_210 ,
V_207 ) ;
#else
F_58 ( V_192 , V_207 ) ;
#endif
V_33 -> V_241 =
V_242 ;
V_33 -> V_243 =
#ifndef F_7
F_59 ( V_211 , V_207 ) ;
#else
F_59 ( V_212 , V_207 ) ;
V_33 -> V_244 =
F_60 ( V_210 , V_207 ) ;
V_33 -> V_245 =
F_61 ( V_211 , V_207 ) ;
#endif
} else {
V_33 -> V_240 = 0 ;
V_33 -> V_241 = 0 ;
V_33 -> V_243 = 0 ;
#ifdef F_7
V_33 -> V_244 = 0 ;
V_33 -> V_245 = 0 ;
#endif
}
F_62 ( & V_33 -> V_114 ,
V_209 ,
V_210 ,
V_211 ,
V_2 -> V_21 . V_246 ,
V_2 -> V_6 . V_114 ) ;
if ( V_2 -> V_21 . V_22 )
V_33 -> V_66 = 2 * V_67 - V_2 -> V_21 . V_22 ;
else
V_33 -> V_66 = 0 ;
return V_54 ;
}
enum V_31
F_63 ( struct V_247 * V_248 ,
struct V_32 * V_33 )
{
int V_25 ;
bool V_200 ;
bool V_201 ;
enum V_163 V_202 ;
const struct V_11 * V_249 ,
* V_250 ,
* V_251 [ V_218 ] ,
* V_252 = NULL ,
* V_253 ;
struct V_158 * V_254 ;
#ifndef F_7
bool V_255 , V_256 , V_257 , V_258 , V_259 ;
#else
bool V_255 , V_256 , V_257 , V_258 , V_259 , V_260 ;
#endif
bool V_261 ;
bool V_262 ;
bool V_263 ;
bool V_264 ;
bool V_265 ;
bool V_266 ;
#ifdef F_7
bool V_267 ;
#endif
enum V_31 V_40 = V_232 ;
bool V_268 ;
unsigned int V_246 ;
struct V_3 V_4 , V_15 ;
unsigned int V_127 ;
assert ( V_248 != NULL ) ;
assert ( V_33 != NULL ) ;
F_64 ( V_269 ,
L_11 ,
V_248 , V_248 -> V_25 ,
V_33 ) ;
V_25 = V_248 -> V_25 ;
V_200 = V_248 -> V_200 ;
V_201 = V_248 -> V_201 ;
V_202 = V_248 -> V_202 ;
V_249 = V_248 -> V_12 ;
V_250 = V_248 -> V_13 ;
for ( V_127 = 0 ; V_127 < V_218 ; V_127 ++ ) {
V_251 [ V_127 ] = V_248 -> V_14 [ V_127 ] ;
if ( V_251 [ V_127 ] && ( V_251 [ V_127 ] -> V_20 . V_8 != 0 ) )
V_252 = V_251 [ V_127 ] ;
}
if ( V_252 == NULL )
return V_232 ;
#ifndef F_7
V_253 = V_248 -> V_203 ;
#else
if ( ( V_248 -> V_203 != NULL ) && ( V_248 -> V_203 -> V_20 . V_8 == 0 ) )
V_253 = NULL ;
else
V_253 = V_248 -> V_203 ;
#endif
V_258 = V_248 -> V_270 ;
V_255 = V_248 -> V_271 ;
V_256 = false ;
V_257 = false ;
V_259 = V_248 -> V_272 ;
#ifdef F_7
V_260 = V_248 -> V_273 ;
#endif
V_262 = V_248 -> V_262 ;
V_263 = V_248 -> V_263 ;
V_264 = V_248 -> V_264 ;
V_265 = V_248 -> V_265 ;
V_266 = V_248 -> V_266 ;
#ifdef F_7
V_267 = V_248 -> V_267 ;
#endif
V_268 = V_248 -> V_268 ;
V_261 = V_248 -> V_261 ;
V_246 = V_248 -> V_246 ;
V_4 . V_8 = 0 ;
V_4 . V_10 = 0 ;
V_15 . V_8 = 0 ;
V_15 . V_10 = 0 ;
if ( V_25 == V_274 ) {
V_4 = V_248 -> V_4 ;
V_256 = V_248 -> V_275 ;
V_257 = V_4 . V_8 || V_4 . V_10 ;
}
F_64 ( V_269 , L_12 ) ;
for ( V_127 = 0 ; V_127 < V_185 ; V_127 ++ ) {
V_254 = V_183 [ V_127 ] ;
if ( V_254 ) {
F_64 ( V_269 , L_13 , V_127 ) ;
while ( V_254 ) {
F_64 ( V_269 , L_14 ,
V_254 -> V_169 -> V_276 , V_254 -> type ,
V_254 -> V_68 . V_6 . V_268 ) ;
V_254 = V_254 -> V_155 ;
}
}
}
for ( V_254 = V_183 [ V_25 ] ; V_254 ;
V_254 = V_254 -> V_155 ) {
struct V_1 * V_277 = & V_254 -> V_68 ;
F_64 ( V_269 ,
L_15 ,
V_277 , V_277 -> V_21 . V_25 , V_277 -> V_154 ) ;
if ( ! V_277 -> V_6 . V_268 &&
V_268 && ( V_25 != V_225 ) ) {
F_64 ( V_269 ,
L_16 ,
__LINE__ , V_277 -> V_6 . V_268 ,
V_268 , V_25 ,
V_225 ) ;
continue;
}
if ( V_261 && V_277 -> V_278 . V_279 == 1 ) {
F_64 ( V_269 ,
L_17 ,
__LINE__ ) ;
continue;
}
if ( V_277 -> V_21 . V_246 != V_246 &&
( V_25 != V_225 ) &&
( V_25 != V_280 ) &&
( V_25 != V_281 ) ) {
F_64 ( V_269 ,
L_18 ,
__LINE__ ,
V_277 -> V_21 . V_246 , V_246 ) ;
continue;
}
if ( ! V_277 -> V_6 . V_282 && V_265 ) {
F_64 ( V_269 ,
L_19 ,
__LINE__ ,
V_277 -> V_6 . V_282 ,
V_265 ) ;
continue;
}
if ( ! V_277 -> V_6 . V_283 && V_264 ) {
F_64 ( V_269 ,
L_19 ,
__LINE__ ,
V_277 -> V_6 . V_283 ,
V_264 ) ;
continue;
}
if ( V_277 -> V_6 . V_284 && ! V_263 ) {
F_64 ( V_269 ,
L_20 ,
__LINE__ ,
V_277 -> V_6 . V_284 ,
V_263 ) ;
continue;
}
if ( ! V_277 -> V_6 . V_285 && V_258 ) {
F_64 ( V_269 ,
L_20 ,
__LINE__ ,
V_277 -> V_6 . V_285 ,
V_258 ) ;
continue;
}
if ( ! ( V_277 -> V_6 . V_19 & 2 ) && V_262 ) {
F_64 ( V_269 ,
L_19 ,
__LINE__ ,
( ( V_277 -> V_6 . V_19 & 2 ) != 0 ) ,
V_262 ) ;
continue;
}
if ( ( V_277 -> V_6 . V_19 & 2 ) && ! V_262 ) {
F_64 ( V_269 ,
L_20 ,
__LINE__ ,
( ( V_277 -> V_6 . V_19 & 2 ) != 0 ) ,
V_262 ) ;
continue;
}
if ( V_25 == V_274 &&
V_277 -> V_6 . V_19 && V_255 )
V_256 = false ;
if ( ( V_253 != NULL ) && ! ( V_277 -> V_6 . V_286 ||
V_277 -> V_287 . V_288 ||
V_254 -> V_289 > 1 ) ) {
F_64 ( V_269 ,
L_21 ,
__LINE__ , V_253 ,
V_277 -> V_6 . V_286 ,
V_277 -> V_287 . V_288 ,
V_254 -> V_289 , 1 ) ;
continue;
}
if ( ! V_277 -> V_6 . V_7 && V_257 ) {
F_64 ( V_269 ,
L_19 ,
__LINE__ ,
V_277 -> V_6 . V_7 , ( int ) V_257 ) ;
continue;
}
F_3 ( V_249 , V_250 ,
V_252 , & V_4 , V_277 , & V_15 ) ;
if ( V_15 . V_8 > V_277 -> V_290 . V_291 ) {
F_64 ( V_269 ,
L_22 ,
__LINE__ , V_15 . V_8 ,
V_277 -> V_290 . V_291 ) ;
continue;
}
if ( V_15 . V_10 > V_277 -> V_290 . V_292 ) {
F_64 ( V_269 ,
L_22 ,
__LINE__ , V_15 . V_10 ,
V_277 -> V_290 . V_292 ) ;
continue;
}
if ( ! V_277 -> V_6 . V_19 && V_255 & ! ( V_254 -> V_289 > 1 ) ) {
F_64 ( V_269 ,
L_19 ,
__LINE__ , V_277 -> V_6 . V_19 , ( int ) V_255 ) ;
continue;
}
if ( ! V_277 -> V_6 . V_293 && ! V_277 -> V_6 . V_283 && V_256 ) {
F_64 ( V_269 ,
L_23 ,
__LINE__ , V_277 -> V_6 . V_293 ,
V_277 -> V_6 . V_283 , ( int ) V_256 ) ;
continue;
}
if ( V_200 && V_277 -> V_294 . V_295 == V_296 ) {
F_64 ( V_269 ,
L_24 ,
__LINE__ , V_200 , V_277 -> V_294 . V_295 ,
V_296 ) ;
continue;
}
if ( ! V_200 && V_277 -> V_294 . V_295 == V_297 ) {
F_64 ( V_269 ,
L_25 ,
__LINE__ , V_200 , V_277 -> V_294 . V_295 ,
V_297 ) ;
continue;
}
if ( V_252 -> V_20 . V_8 < V_277 -> V_27 . V_298 ||
V_252 -> V_20 . V_8 > V_277 -> V_27 . V_291 ) {
F_64 ( V_269 ,
L_26 ,
__LINE__ ,
V_252 -> V_24 ,
V_277 -> V_27 . V_298 ,
V_252 -> V_24 ,
V_277 -> V_27 . V_291 ) ;
continue;
}
if ( V_254 -> V_289 > 1 &&
V_253 ) {
if ( V_253 -> V_20 . V_8 > V_277 -> V_27 . V_291 ) {
F_64 ( V_269 ,
L_27 ,
__LINE__ ,
V_253 -> V_20 . V_8 ,
V_277 -> V_27 . V_291 ) ;
continue;
}
}
if ( V_249 -> V_24 > V_277 -> V_294 . V_291 ) {
F_64 ( V_269 ,
L_22 ,
__LINE__ , V_249 -> V_24 ,
V_277 -> V_294 . V_291 ) ;
continue;
}
if ( ! F_22 ( V_254 , V_252 -> V_160 ) ) {
F_64 ( V_269 ,
L_28 ,
__LINE__ ,
F_22 ( V_254 , V_252 -> V_160 ) ) ;
continue;
}
#ifdef F_7
if ( ! F_23 ( V_254 , V_248 -> V_202 ) ) {
F_64 ( V_269 ,
L_28 ,
__LINE__ ,
F_23 ( V_254 , V_249 -> V_160 ) ) ;
continue;
}
#endif
if ( V_254 -> V_289 > 1 &&
V_253 &&
! F_22 ( V_254 , V_253 -> V_160 ) ) {
F_64 ( V_269 ,
L_29 ,
__LINE__ , V_254 -> V_289 , 1 ,
V_253 ,
F_22 ( V_254 , V_253 -> V_160 ) ) ;
continue;
}
if ( V_254 -> V_289 == 1 &&
V_253 && V_277 -> V_6 . V_286 &&
! F_24 ( V_254 , V_253 -> V_160 ) ) {
F_64 ( V_269 ,
L_30 ,
__LINE__ , V_254 -> V_289 , 1 ,
V_253 , V_277 -> V_6 . V_286 ,
F_24 ( V_254 , V_253 -> V_160 ) ) ;
continue;
}
if ( V_254 -> V_289 == 1 &&
V_253 && V_277 -> V_6 . V_286 ) {
if ( V_253 -> V_20 . V_8 > V_277 -> V_27 . V_291 ) {
F_64 ( V_269 ,
L_27 ,
__LINE__ ,
V_253 -> V_20 . V_8 ,
V_277 -> V_27 . V_291 ) ;
continue;
}
}
if ( ! F_25 ( V_277 -> V_69 . V_70 ,
V_248 -> V_34 ) ) {
F_64 ( V_269 ,
L_31 ,
__LINE__ , V_277 -> V_69 . V_70 ,
V_248 -> V_34 ) ;
continue;
}
if ( ! V_277 -> V_6 . V_299 && V_259 ) {
F_64 ( V_269 ,
L_31 ,
__LINE__ , V_277 -> V_6 . V_299 ,
V_248 -> V_272 ) ;
continue;
}
if ( V_277 -> V_293 . V_300 && V_266 ) {
F_64 ( V_269 ,
L_31 ,
__LINE__ , V_277 -> V_293 . V_300 ,
V_248 -> V_266 ) ;
continue;
}
#ifdef F_7
if ( V_277 -> V_6 . V_301 != V_267 ) {
F_64 ( V_269 ,
L_32 ,
__LINE__ , V_277 -> V_6 . V_301 ,
V_248 -> V_267 ) ;
continue;
}
if( ! V_277 -> V_6 . V_302 && V_260 ) {
F_64 ( V_269 ,
L_19 ,
__LINE__ , V_277 -> V_6 . V_302 ,
V_248 -> V_273 ) ;
continue;
}
#endif
V_40 = F_42 ( V_254 , V_200 , V_201 ,
V_202 , V_249 ,
V_250 ,
V_251 , V_253 ,
V_33 , & V_4 ,
V_248 -> V_194 ,
false ) ;
if ( V_40 != V_54 )
break;
F_21 ( & V_33 -> V_153 , & V_33 -> V_2 -> V_68 ) ;
break;
}
F_64 ( V_269 ,
L_33 ,
V_254 , V_254 ? V_254 -> V_68 . V_21 . V_25 : 0 , V_254 ? V_254 -> V_68 . V_154 : 0 ) ;
F_64 ( V_269 ,
L_34 , V_40 ) ;
return V_40 ;
}
unsigned
F_65 ( void )
{
if ( V_183 [ V_281 ] )
return V_183 [ V_281 ] -> V_68 . V_27 . V_291 ;
return 0 ;
}
void
F_66 ( struct V_32 * V_33 )
{
if ( V_33 ) {
F_46 ( & V_33 -> V_215 ,
& V_33 -> V_216 ) ;
}
}
void
F_67 ( struct V_158 * * V_303 ,
V_89 * V_304 )
{
assert ( V_303 != NULL ) ;
if ( V_304 )
* V_304 = 0 ;
* V_303 = V_181 ;
if ( V_181 && V_304 ) {
if ( V_178 > 0 )
* V_304 = V_178 - 1 ;
}
}
