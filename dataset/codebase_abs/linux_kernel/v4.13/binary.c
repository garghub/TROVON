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
}
static enum V_30
#ifndef F_6
F_7 (
const struct V_31 * V_32 ,
unsigned int V_33 ,
const struct V_34 * V_35 ,
struct V_36 * V_20 )
#else
sh_css_binary_get_sc_requirements(
const struct V_31 * V_32 ,
unsigned int V_33 ,
const struct V_34 * V_35 ,
struct V_37 * V_38 )
#endif
{
enum V_30 V_39 ;
#ifndef F_6
#else
#endif
unsigned int V_40 , V_41 ;
#ifndef F_6
unsigned int V_42 ;
unsigned int V_43 ;
unsigned int V_44 ;
unsigned int V_45 ;
#else
unsigned int V_42 , V_43 , V_44 , V_45 ;
#endif
#ifndef F_6
unsigned int V_46 ;
#else
unsigned int V_46 ;
#endif
#ifndef F_6
unsigned int V_47 ;
unsigned int V_48 ;
unsigned int V_49 ;
unsigned int V_50 ;
unsigned int V_51 ;
unsigned int V_52 ;
V_39 = F_8
( V_33 , & V_40 , & V_41 ) ;
if ( V_39 != V_53 )
#else
unsigned int V_47 , V_54 , V_55 ;
unsigned int V_48 ;
unsigned int V_56 ;
int V_57 = V_58 ;
unsigned int V_59 ;
unsigned int V_60 ;
unsigned int V_61 ;
unsigned int V_62 ;
unsigned int V_63 ;
unsigned int V_64 ;
F_9 ( L_1 ,
V_32 , V_33 , V_35 ) ;
V_39 = F_8 ( V_33 , & V_40 , & V_41 ) ;
if ( V_39 != V_53 ) {
F_10 ( V_39 ) ;
#endif
return V_39 ;
#ifdef F_6
}
#endif
#ifndef F_6
#else
F_11 ( L_2 , V_40 , V_41 ) ;
#endif
V_42 = V_40 ;
V_43 = V_41 ;
V_44 = V_40 ;
V_45 = V_41 ;
#ifndef F_6
#else
#endif
if ( V_35 -> V_65 == - 1 )
V_46 = F_12 ( V_32 -> V_65 ) ;
else
#ifndef F_6
V_46 = ( unsigned int ) ( ( int ) V_66
- F_12 ( V_35 -> V_65 ) ) ;
#else
V_46 = ( unsigned int ) ( ( int ) V_66 - F_12 ( V_35 -> V_65 ) ) ;
#endif
#ifndef F_6
#else
F_11 ( L_3 ,
V_35 -> V_65 , V_32 -> V_65 , V_46 ) ;
#endif
V_47 = ( ( V_32 -> V_2 -> V_67 . V_68 . V_69 &
( F_13 ( V_70 ) |
F_13 ( V_71 ) |
F_13 ( V_72 ) |
F_13 ( V_73 ) |
F_13 ( V_74 ) |
F_13 ( V_75 ) |
F_13 ( V_76 ) |
F_13 ( V_77 ) ) ) != 0 ) ;
#ifndef F_6
if ( V_47 && V_32 -> V_2 -> V_67 . V_21 . V_22 > 0 )
V_48 = V_46 + V_66 ;
else
#else
V_54 = ( ( V_32 -> V_2 -> V_67 . V_68 . V_69 &
( F_13 ( V_78 ) |
F_13 ( V_79 ) |
F_13 ( V_72 ) |
F_13 ( V_74 ) |
F_13 ( V_76 ) ) ) != 0 ) ;
V_55 = ( ( V_32 -> V_2 -> V_67 . V_68 . V_69 &
( F_13 ( V_80 ) |
F_13 ( V_71 ) |
F_13 ( V_75 ) ) ) != 0 ) ;
if ( V_32 -> V_2 -> V_67 . V_21 . V_22 > 0 &&
( V_47 || V_54 || V_55 ) ) {
unsigned int V_81
= V_66 * V_42 / V_43 ;
V_48 = V_81
- F_12 ( V_32 -> V_2 -> V_67 . V_21 . V_22 ) ;
} else
#endif
V_48 = V_46 ;
#ifndef F_6
V_49 = 0 ;
V_51 = 0 ;
#else
F_11 ( L_4 ,
V_32 -> V_2 -> V_67 . V_68 . V_69 ,
V_47 , V_54 , V_55 ) ;
F_11 ( L_5 ,
V_32 -> V_2 -> V_67 . V_21 . V_22 , V_48 ) ;
V_56 = 0 ;
if ( V_32 -> V_2 -> V_67 . V_21 . V_23 > 0 &&
( V_33 == V_80 ||
V_33 == V_78 ||
V_33 == V_70 ) ) {
int V_82 = F_12 ( V_32 -> V_2 -> V_67 . V_21 . V_23 ) ;
int V_83 = V_40 * V_57 / V_41 ;
int V_84 = ( V_82 * V_83 - V_82 * V_57 )
+ ( 2 * V_57 - V_83 ) ;
V_56 = ( unsigned int ) ( ( V_84 + V_57 / 2 - 1 ) / V_57 ) ;
}
F_11 ( L_6 , V_32 -> V_2 -> V_67 . V_21 . V_23 , V_56 ) ;
V_59 = 0 ;
V_61 = 0 ;
#endif
#ifndef F_6
V_50 = 0 ;
V_52 = 0 ;
#else
if ( V_47 || V_54 || V_55 ) {
V_59 = 1 ;
V_61 = 1 ;
}
F_11 ( L_7 ,
V_59 , V_61 ) ;
V_60 = 0 ;
V_62 = 0 ;
#endif
#ifndef F_6
V_20 -> V_85
= ( ( V_48 + V_49 )
* V_43 + V_42 / 2 ) / V_42
+ V_50 ;
V_20 -> V_86
= ( V_51
* V_45 + V_44 / 2 ) / V_44
+ V_52 ;
V_20 -> V_87 = ( V_88 ) V_42 ;
V_20 -> V_89 = ( V_88 ) V_43 ;
V_20 -> V_90 = ( V_88 ) V_44 ;
V_20 -> V_91 = ( V_88 ) V_45 ;
#else
if ( V_32 -> V_2 -> V_92 . V_93 . V_94 -> V_95 . V_96 . V_97 != 0 ) {
V_60 = 1 ;
V_62 = 1 ;
}
F_11 ( L_8 ,
V_60 , V_62 ) ;
{
unsigned int V_98 = V_57 ;
unsigned int V_99 , V_100 ;
V_99 = V_43 * V_98 ;
V_100 = V_42 * V_98 ;
V_63
= ( ( V_48 + V_59 ) * V_99 + V_100 / 2 ) / V_100
+ V_60 ;
V_99 = V_45 * V_98 ;
V_100 = V_44 * V_98 ;
V_64
= ( ( V_56 + V_61 ) * V_99 + V_100 / 2 ) / V_100
+ V_62 ;
}
V_38 -> V_87 = ( V_88 ) V_42 ;
V_38 -> V_89 = ( V_88 ) V_43 ;
V_38 -> V_90 = ( V_88 ) V_44 ;
V_38 -> V_91 = ( V_88 ) V_45 ;
V_38 -> V_63 = ( V_88 ) V_63 ;
V_38 -> V_64 = ( V_88 ) V_64 ;
F_11 ( L_9 ,
V_38 -> V_87 , V_38 -> V_89 ,
V_38 -> V_90 , V_38 -> V_91 ,
V_38 -> V_63 , V_38 -> V_64 ) ;
#endif
#ifdef F_6
F_10 ( V_39 ) ;
#endif
return V_39 ;
}
static void F_14 ( const struct V_31 * V_32 ,
struct V_101 * V_2 )
{
assert ( V_32 != NULL ) ;
assert ( V_2 != NULL ) ;
V_2 -> V_102 = V_32 -> V_103 . V_20 . V_8 ;
V_2 -> V_104 = V_32 -> V_103 . V_20 . V_10 ;
V_2 -> V_105 = V_106 ;
}
void
F_15 ( const struct V_31 * V_32 ,
struct V_101 * V_2 ,
struct V_107 * V_108 )
{
struct V_109 * V_110 ;
( void ) V_108 ;
assert ( V_32 != NULL ) ;
assert ( V_2 != NULL ) ;
V_110 = & V_2 -> V_111 . V_112 ;
V_110 -> V_6 = V_32 -> V_2 -> V_67 . V_6 . V_113 ;
V_110 -> V_8 = V_32 -> V_113 . V_114 . V_115 . V_8 ;
V_110 -> V_10 = V_32 -> V_113 . V_114 . V_115 . V_10 ;
V_110 -> V_116 = V_32 -> V_113 . V_114 . V_117 . V_8 ;
V_110 -> V_118 = V_32 -> V_113 . V_114 . V_117 . V_10 ;
V_110 -> V_119 = 1 << V_32 -> V_113 . V_120 ;
V_110 -> V_121 = V_32 -> V_113 . V_122 . V_115 . V_8 ;
V_110 -> V_123 = V_32 -> V_113 . V_122 . V_115 . V_10 ;
F_14 ( V_32 , V_2 ) ;
}
void
F_16 (
const struct V_31 * V_32 ,
struct V_101 * V_2 ,
struct V_107 * V_108 )
{
( void ) V_108 ;
F_14 ( V_32 , V_2 ) ;
return;
}
enum V_30
F_17 ( const struct V_31 * V_32 ,
struct V_101 * V_2 ,
struct V_107 * V_108 )
{
struct V_124 * V_125 ;
enum V_30 V_39 = V_53 ;
F_9 ( L_10 ,
V_32 , V_2 , V_108 ) ;
assert ( V_32 != NULL ) ;
assert ( V_2 != NULL ) ;
V_125 = & V_2 -> V_126 ;
V_125 -> V_6 = V_32 -> V_2 -> V_67 . V_6 . V_127 ;
V_125 -> V_8 = V_32 -> V_128 ;
V_125 -> V_10 = V_32 -> V_129 ;
V_125 -> V_116 = V_32 -> V_130 ;
V_125 -> V_118 = V_32 -> V_131 ;
V_125 -> V_119 = ( 1 << V_32 -> V_120 ) ;
V_125 -> V_120 = V_32 -> V_120 ;
V_125 -> V_132 = V_133 ;
V_125 -> V_134 = V_32 -> V_2 -> V_67 . V_127 . V_135 ;
#if F_18 ( V_136 )
V_125 -> V_137 = 1 ;
#else
V_125 -> V_137 = 0 ;
#endif
F_10 ( V_39 ) ;
return V_39 ;
}
static void
F_19 ( struct V_138 * V_139 )
{
assert ( V_139 != NULL ) ;
V_139 -> V_140 = 0 ;
V_139 -> V_141 = NULL ;
V_139 -> V_142 = NULL ;
}
static void
F_20 ( struct V_143 * V_144 ,
const struct V_1 * V_2 )
{
assert ( V_144 != NULL ) ;
assert ( V_2 != NULL ) ;
V_144 -> V_25 = V_2 -> V_21 . V_25 ;
V_144 -> V_145 = V_2 -> V_145 ;
V_144 -> V_146 = NULL ;
F_19 ( & V_144 -> V_147 ) ;
F_19 ( & V_144 -> V_148 ) ;
}
static bool
F_21 ( const struct V_149 * V_2 ,
enum V_150 V_151 )
{
int V_152 ;
assert ( V_2 != NULL ) ;
for ( V_152 = 0 ; V_152 < V_2 -> V_153 ; V_152 ++ ) {
if ( V_2 -> V_154 [ V_152 ] == V_151 )
return true ;
}
return false ;
}
static bool
F_22 ( const struct V_149 * V_2 ,
enum V_155 V_151 )
{
assert ( V_2 != NULL ) ;
( void ) V_151 ;
return true ;
}
static bool
F_23 ( const struct V_149 * V_2 ,
enum V_150 V_151 )
{
int V_152 ;
assert ( V_2 != NULL ) ;
for ( V_152 = 0 ; V_152 < V_2 -> V_156 ; V_152 ++ ) {
if ( V_2 -> V_157 [ V_152 ] == V_151 )
return true ;
}
return false ;
}
static bool
F_24 ( V_88 V_158 ,
V_88 V_159 )
{
return ( ( V_158 & F_13 ( V_159 ) ) != 0 ) ;
}
static enum V_30
F_25 ( struct V_149 * V_2 , unsigned int V_152 ,
bool * V_160 )
{
const unsigned char * V_161 = V_162 [ V_152 ] . V_161 ;
unsigned V_97 = V_162 [ V_152 ] . V_163 . V_161 . V_97 ;
if ( ( V_2 == NULL ) || ( V_160 == NULL ) )
return V_164 ;
* V_2 = V_162 [ V_152 ] . V_163 . V_2 . V_165 ;
* V_160 = V_161 != NULL ;
V_2 -> V_166 = V_152 ;
if ( ! V_97 )
return V_53 ;
V_2 -> V_167 = F_26 ( V_161 , V_97 ) ;
if ( ! V_2 -> V_167 )
return V_168 ;
return V_53 ;
}
enum V_30
F_27 ( void )
{
unsigned int V_152 ;
unsigned int V_169 = V_170 - V_171 - V_172 ;
if ( V_169 == 0 )
return V_53 ;
V_173 = F_28 ( V_169 *
sizeof( * V_173 ) ) ;
if ( V_173 == NULL )
return V_168 ;
for ( V_152 = 0 ; V_152 < V_169 ; V_152 ++ ) {
enum V_30 V_174 ;
struct V_149 * V_32 = & V_173 [ V_152 ] ;
bool V_160 ;
V_174 = F_25 ( V_32 , V_152 , & V_160 ) ;
if ( V_174 != V_53 )
return V_174 ;
if ( ! V_160 )
continue;
V_32 -> V_146 = V_175 [ V_32 -> V_67 . V_21 . V_25 ] ;
V_175 [ V_32 -> V_67 . V_21 . V_25 ] = V_32 ;
V_32 -> V_161 = & V_162 [ V_152 ] ;
V_32 -> V_92 = V_162 [ V_152 ] . V_92 ;
}
return V_53 ;
}
enum V_30
F_29 ( void )
{
unsigned int V_152 ;
struct V_149 * V_176 ;
for ( V_152 = 0 ; V_152 < V_177 ; V_152 ++ ) {
for ( V_176 = V_175 [ V_152 ] ; V_176 ; V_176 = V_176 -> V_146 ) {
if ( V_176 -> V_167 )
F_30 ( V_176 -> V_167 ) ;
V_176 -> V_167 = V_178 ;
}
V_175 [ V_152 ] = NULL ;
}
F_31 ( V_173 ) ;
return V_53 ;
}
static int
F_32 ( int V_8 , int V_10 )
{
#define F_33 5
#define F_34 3
#define F_35 1280
#define F_36 640
int V_179 ;
int V_180 ;
assert ( F_37 ( V_8 , F_33 ) <= V_181 ) ;
assert ( F_38 ( V_10 , F_33 ) <= V_182 ) ;
V_179 = F_33 ;
while ( F_37 ( V_8 , V_179 - 1 ) <= V_181 &&
F_38 ( V_10 , V_179 - 1 ) <= V_182
&& V_179 > F_34 )
V_179 -- ;
if ( F_12 ( V_8 ) >= F_35 )
V_180 = 5 ;
else if ( F_12 ( V_8 ) >= F_36 )
V_180 = 4 ;
else
V_180 = 3 ;
return F_2 ( V_179 , V_180 ) ;
#undef F_33
#undef F_34
#undef F_35
#undef F_36
}
static int
F_39 ( int V_183 ,
int V_184 ,
int V_185 ,
int V_186 ,
int V_22 ,
bool V_187 )
{
int V_188 ;
int V_189 ;
#if F_18 ( V_190 )
V_189 = 0 ;
#else
V_189 = 2 * V_66 ;
#endif
if ( V_187 ) {
if ( V_186 != - 1 ) {
V_188 =
F_40 ( V_183 + V_189 ,
2 * V_66 ) ;
} else {
V_183 += V_185 ;
V_188 =
F_40 ( V_183 +
( V_22 ? V_189 : 0 ) ,
2 * V_66 ) ;
}
} else {
V_188 = V_184 ;
}
return V_188 ;
}
enum V_30
F_41 ( const struct V_149 * V_191 ,
bool V_192 ,
bool V_193 ,
enum V_155 V_194 ,
const struct V_11 * V_12 ,
const struct V_11 * V_13 ,
const struct V_11 * V_14 [] ,
const struct V_11 * V_195 ,
struct V_31 * V_32 ,
struct V_3 * V_4 ,
int V_186 ,
bool V_196 )
{
const struct V_1 * V_2 = & V_191 -> V_67 ;
unsigned int V_185 = 0 ,
V_197 = 0 ,
V_198 = 0 ,
V_199 = 0 ,
V_200 = 0 ,
V_201 = 0 ,
V_202 = 0 ,
V_203 = 0 ,
V_184 = 0 ,
V_204 = 0 ,
V_205 = 0 ;
bool V_187 = false ;
struct V_3 V_5 , V_15 ;
enum V_30 V_39 ;
unsigned int V_152 ;
const struct V_11 * V_206 = NULL ;
assert ( V_2 != NULL ) ;
assert ( V_32 != NULL ) ;
V_32 -> V_2 = V_191 ;
if ( ! V_196 ) {
V_39 = F_42 (
& V_32 -> V_207 , & V_32 -> V_208 ,
& V_2 -> V_209 ) ;
if ( V_39 != V_53 ) {
return V_39 ;
}
}
for ( V_152 = 0 ; V_152 < V_210 ; V_152 ++ ) {
if ( V_14 [ V_152 ] && ( V_14 [ V_152 ] -> V_20 . V_8 != 0 ) ) {
V_206 = V_14 [ V_152 ] ;
break;
}
}
if ( V_12 != NULL && V_206 != NULL ) {
V_187 = ( V_12 -> V_20 . V_8 != V_206 -> V_20 . V_8 ) ||
( V_12 -> V_20 . V_10 != V_206 -> V_20 . V_10 ) ;
}
V_5 . V_8 = 0 ;
V_5 . V_10 = 0 ;
F_1 ( V_2 , V_4 , & V_5 ) ;
V_185 = V_5 . V_8 ;
V_197 = V_5 . V_10 ;
V_32 -> V_7 . V_8 = V_185 ;
V_32 -> V_7 . V_10 = V_197 ;
V_15 . V_8 = 0 ;
V_15 . V_10 = 0 ;
F_3 ( V_12 , V_13 , V_206 , V_4 ,
V_2 , & V_15 ) ;
V_184 = V_15 . V_8 ;
V_204 = V_15 . V_10 ;
if ( V_206 != NULL )
V_32 -> V_103 . V_151 = V_206 -> V_151 ;
V_32 -> V_103 . V_20 . V_8 = V_184 ;
V_32 -> V_103 . V_24 = F_40 ( V_184 , 2 * V_66 ) ;
V_32 -> V_103 . V_20 . V_10 = V_204 ;
V_32 -> V_103 . V_211 = V_200 ;
if ( V_12 != NULL ) {
V_32 -> V_212 . V_8 = V_12 -> V_20 . V_8 ;
V_32 -> V_212 . V_10 = V_12 -> V_20 . V_10 ;
V_200 = V_12 -> V_211 ;
V_32 -> V_213 . V_20 . V_8 = V_12 -> V_20 . V_8 + V_2 -> V_21 . V_22 ;
V_32 -> V_213 . V_20 . V_10 = V_12 -> V_20 . V_10 + V_2 -> V_21 . V_23 ;
V_32 -> V_213 . V_20 . V_8 += V_185 ;
V_32 -> V_213 . V_20 . V_10 += V_197 ;
V_32 -> V_213 . V_24 =
F_39 ( V_12 -> V_20 . V_8 ,
V_184 ,
V_185 ,
V_186 ,
V_2 -> V_21 . V_22 ,
V_187 ) ;
V_32 -> V_213 . V_151 = V_12 -> V_151 ;
V_32 -> V_213 . V_214 = V_12 -> V_214 ;
V_32 -> V_213 . V_215 = V_12 -> V_215 ;
}
if ( V_192 ) {
V_200 = F_43 (
V_194 , V_193 ) ;
}
V_32 -> V_213 . V_211 = V_200 ;
for ( V_152 = 0 ; V_152 < V_210 ; V_152 ++ ) {
if ( V_14 [ V_152 ] != NULL ) {
V_32 -> V_216 [ V_152 ] . V_20 . V_8 = V_14 [ V_152 ] -> V_20 . V_8 ;
V_32 -> V_216 [ V_152 ] . V_20 . V_10 = V_14 [ V_152 ] -> V_20 . V_10 ;
V_32 -> V_216 [ V_152 ] . V_24 = V_14 [ V_152 ] -> V_24 ;
if ( V_2 -> V_21 . V_25 == V_217 ) {
V_32 -> V_216 [ V_152 ] . V_211 = V_200 ;
} else {
V_32 -> V_216 [ V_152 ] . V_211 = 16 ;
}
V_32 -> V_216 [ V_152 ] . V_151 = V_14 [ V_152 ] -> V_151 ;
}
}
if ( V_195 && ( V_195 -> V_20 . V_8 != 0 ) ) {
V_39 = F_44 ( V_32 , V_206 , (struct V_11 * ) V_195 , & V_198 ) ;
if ( V_39 != V_53 ) {
if ( ! V_196 ) {
F_45 (
& V_32 -> V_207 ,
& V_32 -> V_208 ) ;
}
return V_39 ;
}
}
V_32 -> V_218 = V_198 ;
V_32 -> V_192 = V_192 ;
V_32 -> V_219 = V_194 ;
if ( ( V_195 != NULL ) && ( V_195 -> V_20 . V_8 != 0 ) ) {
unsigned int V_220 , V_221 , V_222 ;
V_32 -> V_223 . V_151 = V_195 -> V_151 ;
if ( V_206 == NULL )
return V_224 ;
V_220 = F_46 ( V_206 -> V_24 ,
V_198 ) ;
V_221 = F_47 ( V_220 ) ;
V_222 = F_48 ( V_206 -> V_20 . V_10 ,
V_198 ) ;
if ( V_2 -> V_21 . V_25 == V_225 ) {
V_32 -> V_216 [ 0 ] . V_20 . V_8 =
( V_206 -> V_20 . V_8 >> V_198 ) ;
V_32 -> V_216 [ 0 ] . V_24 = V_221 ;
V_32 -> V_216 [ 0 ] . V_20 . V_10 = V_222 ;
V_32 -> V_223 . V_20 . V_8 = 0 ;
V_32 -> V_223 . V_24 = 0 ;
V_32 -> V_223 . V_20 . V_10 = 0 ;
} else {
V_32 -> V_223 . V_20 . V_8 =
( V_206 -> V_20 . V_8 >> V_198 ) ;
V_32 -> V_223 . V_24 = V_221 ;
V_32 -> V_223 . V_20 . V_10 = V_222 ;
}
} else {
V_32 -> V_223 . V_20 . V_8 = 0 ;
V_32 -> V_223 . V_24 = 0 ;
V_32 -> V_223 . V_20 . V_10 = 0 ;
}
if ( V_2 -> V_6 . V_226 ) {
V_32 -> V_227 =
F_49 ( V_184 ) ;
V_32 -> V_228 =
F_50 ( V_184 ) ;
V_32 -> V_229 =
F_51 ( V_204 ) ;
} else {
V_32 -> V_227 = 0 ;
V_32 -> V_228 = 0 ;
V_32 -> V_229 = 0 ;
}
V_201 = V_32 -> V_213 . V_20 . V_8 ;
V_202 = V_32 -> V_213 . V_24 ;
V_203 = V_32 -> V_213 . V_20 . V_10 ;
if ( V_13 != NULL && V_12 != NULL &&
V_13 -> V_20 . V_8 != V_12 -> V_20 . V_8 ) {
V_201 = V_13 -> V_20 . V_8 + V_2 -> V_21 . V_22 ;
V_202 = V_184 ;
V_203 = V_204 ;
}
V_205 = F_52 ( V_202 ,
V_2 -> V_21 . V_22 ) ;
if ( V_2 -> V_127 . V_230 ) {
V_199 = V_2 -> V_127 . V_230 ;
} else {
V_199 = F_32 ( V_205 ,
V_203 ) ;
}
V_32 -> V_120 = V_199 ;
if ( V_2 -> V_6 . V_127 ) {
V_32 -> V_128 =
F_53 ( V_201 ,
V_199 ) ;
V_32 -> V_129 =
F_54 ( V_203 ,
V_199 ) ;
V_32 -> V_130 =
F_55 ( V_205 ,
V_199 ) ;
V_32 -> V_131 =
F_56 ( V_203 ,
V_199 ) ;
} else {
V_32 -> V_128 = 0 ;
V_32 -> V_129 = 0 ;
V_32 -> V_130 = 0 ;
V_32 -> V_131 = 0 ;
}
if ( V_2 -> V_6 . V_231 ) {
V_32 -> V_232 =
#ifndef F_6
F_57 ( V_202 ,
V_199 ) ;
#else
F_57 ( V_184 , V_199 ) ;
#endif
V_32 -> V_233 =
V_234 ;
V_32 -> V_235 =
#ifndef F_6
F_58 ( V_203 , V_199 ) ;
#else
F_58 ( V_204 , V_199 ) ;
V_32 -> V_236 =
F_59 ( V_202 , V_199 ) ;
V_32 -> V_237 =
F_60 ( V_203 , V_199 ) ;
#endif
} else {
V_32 -> V_232 = 0 ;
V_32 -> V_233 = 0 ;
V_32 -> V_235 = 0 ;
#ifdef F_6
V_32 -> V_236 = 0 ;
V_32 -> V_237 = 0 ;
#endif
}
F_61 ( & V_32 -> V_113 ,
V_201 ,
V_202 ,
V_203 ,
V_2 -> V_21 . V_238 ,
V_2 -> V_6 . V_113 ) ;
if ( V_2 -> V_21 . V_22 )
V_32 -> V_65 = 2 * V_66 - V_2 -> V_21 . V_22 ;
else
V_32 -> V_65 = 0 ;
return V_53 ;
}
enum V_30
F_62 ( struct V_239 * V_240 ,
struct V_31 * V_32 )
{
int V_25 ;
bool V_192 ;
bool V_193 ;
enum V_155 V_194 ;
const struct V_11 * V_241 ,
* V_242 ,
* V_243 [ V_210 ] ,
* V_244 = NULL ,
* V_245 ;
struct V_149 * V_246 ;
#ifndef F_6
bool V_247 , V_248 , V_249 , V_250 , V_251 ;
#else
bool V_247 , V_248 , V_249 , V_250 , V_251 , V_252 ;
#endif
bool V_253 ;
bool V_254 ;
bool V_255 ;
bool V_256 ;
bool V_257 ;
bool V_258 ;
#ifdef F_6
bool V_259 ;
#endif
enum V_30 V_39 = V_224 ;
bool V_260 ;
unsigned int V_238 ;
struct V_3 V_4 , V_15 ;
unsigned int V_152 ;
assert ( V_240 != NULL ) ;
assert ( V_32 != NULL ) ;
F_63 ( V_261 ,
L_11 ,
V_240 , V_240 -> V_25 ,
V_32 ) ;
V_25 = V_240 -> V_25 ;
V_192 = V_240 -> V_192 ;
V_193 = V_240 -> V_193 ;
V_194 = V_240 -> V_194 ;
V_241 = V_240 -> V_12 ;
V_242 = V_240 -> V_13 ;
for ( V_152 = 0 ; V_152 < V_210 ; V_152 ++ ) {
V_243 [ V_152 ] = V_240 -> V_14 [ V_152 ] ;
if ( V_243 [ V_152 ] && ( V_243 [ V_152 ] -> V_20 . V_8 != 0 ) )
V_244 = V_243 [ V_152 ] ;
}
if ( V_244 == NULL )
return V_224 ;
#ifndef F_6
V_245 = V_240 -> V_195 ;
#else
if ( ( V_240 -> V_195 != NULL ) && ( V_240 -> V_195 -> V_20 . V_8 == 0 ) )
V_245 = NULL ;
else
V_245 = V_240 -> V_195 ;
#endif
V_250 = V_240 -> V_262 ;
V_247 = V_240 -> V_263 ;
V_248 = false ;
V_249 = false ;
V_251 = V_240 -> V_264 ;
#ifdef F_6
V_252 = V_240 -> V_265 ;
#endif
V_254 = V_240 -> V_254 ;
V_255 = V_240 -> V_255 ;
V_256 = V_240 -> V_256 ;
V_257 = V_240 -> V_257 ;
V_258 = V_240 -> V_258 ;
#ifdef F_6
V_259 = V_240 -> V_259 ;
#endif
V_260 = V_240 -> V_260 ;
V_253 = V_240 -> V_253 ;
V_238 = V_240 -> V_238 ;
V_4 . V_8 = 0 ;
V_4 . V_10 = 0 ;
V_15 . V_8 = 0 ;
V_15 . V_10 = 0 ;
if ( V_25 == V_266 ) {
V_4 = V_240 -> V_4 ;
V_248 = V_240 -> V_267 ;
V_249 = V_4 . V_8 || V_4 . V_10 ;
}
F_63 ( V_261 , L_12 ) ;
for ( V_152 = 0 ; V_152 < V_177 ; V_152 ++ ) {
V_246 = V_175 [ V_152 ] ;
if ( V_246 ) {
F_63 ( V_261 , L_13 , V_152 ) ;
while ( V_246 ) {
F_63 ( V_261 , L_14 ,
V_246 -> V_161 -> V_268 , V_246 -> type ,
V_246 -> V_67 . V_6 . V_260 ) ;
V_246 = V_246 -> V_146 ;
}
}
}
for ( V_246 = V_175 [ V_25 ] ; V_246 ;
V_246 = V_246 -> V_146 ) {
struct V_1 * V_269 = & V_246 -> V_67 ;
F_63 ( V_261 ,
L_15 ,
V_269 , V_269 -> V_21 . V_25 , V_269 -> V_145 ) ;
if ( ! V_269 -> V_6 . V_260 &&
V_260 && ( V_25 != V_217 ) ) {
F_63 ( V_261 ,
L_16 ,
__LINE__ , V_269 -> V_6 . V_260 ,
V_260 , V_25 ,
V_217 ) ;
continue;
}
if ( V_253 && V_269 -> V_270 . V_271 == 1 ) {
F_63 ( V_261 ,
L_17 ,
__LINE__ ) ;
continue;
}
if ( V_269 -> V_21 . V_238 != V_238 &&
( V_25 != V_217 ) &&
( V_25 != V_272 ) &&
( V_25 != V_273 ) ) {
F_63 ( V_261 ,
L_18 ,
__LINE__ ,
V_269 -> V_21 . V_238 , V_238 ) ;
continue;
}
if ( ! V_269 -> V_6 . V_274 && V_257 ) {
F_63 ( V_261 ,
L_19 ,
__LINE__ ,
V_269 -> V_6 . V_274 ,
V_257 ) ;
continue;
}
if ( ! V_269 -> V_6 . V_275 && V_256 ) {
F_63 ( V_261 ,
L_19 ,
__LINE__ ,
V_269 -> V_6 . V_275 ,
V_256 ) ;
continue;
}
if ( V_269 -> V_6 . V_276 && ! V_255 ) {
F_63 ( V_261 ,
L_20 ,
__LINE__ ,
V_269 -> V_6 . V_276 ,
V_255 ) ;
continue;
}
if ( ! V_269 -> V_6 . V_277 && V_250 ) {
F_63 ( V_261 ,
L_20 ,
__LINE__ ,
V_269 -> V_6 . V_277 ,
V_250 ) ;
continue;
}
if ( ! ( V_269 -> V_6 . V_19 & 2 ) && V_254 ) {
F_63 ( V_261 ,
L_19 ,
__LINE__ ,
( ( V_269 -> V_6 . V_19 & 2 ) != 0 ) ,
V_254 ) ;
continue;
}
if ( ( V_269 -> V_6 . V_19 & 2 ) && ! V_254 ) {
F_63 ( V_261 ,
L_20 ,
__LINE__ ,
( ( V_269 -> V_6 . V_19 & 2 ) != 0 ) ,
V_254 ) ;
continue;
}
if ( V_25 == V_266 &&
V_269 -> V_6 . V_19 && V_247 )
V_248 = false ;
if ( ( V_245 != NULL ) && ! ( V_269 -> V_6 . V_278 ||
V_269 -> V_279 . V_280 ||
V_246 -> V_281 > 1 ) ) {
F_63 ( V_261 ,
L_21 ,
__LINE__ , V_245 ,
V_269 -> V_6 . V_278 ,
V_269 -> V_279 . V_280 ,
V_246 -> V_281 , 1 ) ;
continue;
}
if ( ! V_269 -> V_6 . V_7 && V_249 ) {
F_63 ( V_261 ,
L_19 ,
__LINE__ ,
V_269 -> V_6 . V_7 , ( int ) V_249 ) ;
continue;
}
F_3 ( V_241 , V_242 ,
V_244 , & V_4 , V_269 , & V_15 ) ;
if ( V_15 . V_8 > V_269 -> V_282 . V_283 ) {
F_63 ( V_261 ,
L_22 ,
__LINE__ , V_15 . V_8 ,
V_269 -> V_282 . V_283 ) ;
continue;
}
if ( V_15 . V_10 > V_269 -> V_282 . V_284 ) {
F_63 ( V_261 ,
L_22 ,
__LINE__ , V_15 . V_10 ,
V_269 -> V_282 . V_284 ) ;
continue;
}
if ( ! V_269 -> V_6 . V_19 && V_247 && ! ( V_246 -> V_281 > 1 ) ) {
F_63 ( V_261 ,
L_19 ,
__LINE__ , V_269 -> V_6 . V_19 , ( int ) V_247 ) ;
continue;
}
if ( ! V_269 -> V_6 . V_285 && ! V_269 -> V_6 . V_275 && V_248 ) {
F_63 ( V_261 ,
L_23 ,
__LINE__ , V_269 -> V_6 . V_285 ,
V_269 -> V_6 . V_275 , ( int ) V_248 ) ;
continue;
}
if ( V_192 && V_269 -> V_286 . V_287 == V_288 ) {
F_63 ( V_261 ,
L_24 ,
__LINE__ , V_192 , V_269 -> V_286 . V_287 ,
V_288 ) ;
continue;
}
if ( ! V_192 && V_269 -> V_286 . V_287 == V_289 ) {
F_63 ( V_261 ,
L_25 ,
__LINE__ , V_192 , V_269 -> V_286 . V_287 ,
V_289 ) ;
continue;
}
if ( V_244 -> V_20 . V_8 < V_269 -> V_27 . V_290 ||
V_244 -> V_20 . V_8 > V_269 -> V_27 . V_283 ) {
F_63 ( V_261 ,
L_26 ,
__LINE__ ,
V_244 -> V_24 ,
V_269 -> V_27 . V_290 ,
V_244 -> V_24 ,
V_269 -> V_27 . V_283 ) ;
continue;
}
if ( V_246 -> V_281 > 1 &&
V_245 ) {
if ( V_245 -> V_20 . V_8 > V_269 -> V_27 . V_283 ) {
F_63 ( V_261 ,
L_27 ,
__LINE__ ,
V_245 -> V_20 . V_8 ,
V_269 -> V_27 . V_283 ) ;
continue;
}
}
if ( V_241 -> V_24 > V_269 -> V_286 . V_283 ) {
F_63 ( V_261 ,
L_22 ,
__LINE__ , V_241 -> V_24 ,
V_269 -> V_286 . V_283 ) ;
continue;
}
if ( ! F_21 ( V_246 , V_244 -> V_151 ) ) {
F_63 ( V_261 ,
L_28 ,
__LINE__ ,
F_21 ( V_246 , V_244 -> V_151 ) ) ;
continue;
}
#ifdef F_6
if ( ! F_22 ( V_246 , V_240 -> V_194 ) ) {
F_63 ( V_261 ,
L_28 ,
__LINE__ ,
F_22 ( V_246 , V_241 -> V_151 ) ) ;
continue;
}
#endif
if ( V_246 -> V_281 > 1 &&
V_245 &&
! F_21 ( V_246 , V_245 -> V_151 ) ) {
F_63 ( V_261 ,
L_29 ,
__LINE__ , V_246 -> V_281 , 1 ,
V_245 ,
F_21 ( V_246 , V_245 -> V_151 ) ) ;
continue;
}
if ( V_246 -> V_281 == 1 &&
V_245 && V_269 -> V_6 . V_278 &&
! F_23 ( V_246 , V_245 -> V_151 ) ) {
F_63 ( V_261 ,
L_30 ,
__LINE__ , V_246 -> V_281 , 1 ,
V_245 , V_269 -> V_6 . V_278 ,
F_23 ( V_246 , V_245 -> V_151 ) ) ;
continue;
}
if ( V_246 -> V_281 == 1 &&
V_245 && V_269 -> V_6 . V_278 ) {
if ( V_245 -> V_20 . V_8 > V_269 -> V_27 . V_283 ) {
F_63 ( V_261 ,
L_27 ,
__LINE__ ,
V_245 -> V_20 . V_8 ,
V_269 -> V_27 . V_283 ) ;
continue;
}
}
if ( ! F_24 ( V_269 -> V_68 . V_69 ,
V_240 -> V_33 ) ) {
F_63 ( V_261 ,
L_31 ,
__LINE__ , V_269 -> V_68 . V_69 ,
V_240 -> V_33 ) ;
continue;
}
if ( ! V_269 -> V_6 . V_291 && V_251 ) {
F_63 ( V_261 ,
L_31 ,
__LINE__ , V_269 -> V_6 . V_291 ,
V_240 -> V_264 ) ;
continue;
}
if ( V_269 -> V_285 . V_292 && V_258 ) {
F_63 ( V_261 ,
L_31 ,
__LINE__ , V_269 -> V_285 . V_292 ,
V_240 -> V_258 ) ;
continue;
}
#ifdef F_6
if ( V_269 -> V_6 . V_293 != V_259 ) {
F_63 ( V_261 ,
L_32 ,
__LINE__ , V_269 -> V_6 . V_293 ,
V_240 -> V_259 ) ;
continue;
}
if( ! V_269 -> V_6 . V_294 && V_252 ) {
F_63 ( V_261 ,
L_19 ,
__LINE__ , V_269 -> V_6 . V_294 ,
V_240 -> V_265 ) ;
continue;
}
#endif
V_39 = F_41 ( V_246 , V_192 , V_193 ,
V_194 , V_241 ,
V_242 ,
V_243 , V_245 ,
V_32 , & V_4 ,
V_240 -> V_186 ,
false ) ;
if ( V_39 != V_53 )
break;
F_20 ( & V_32 -> V_144 , & V_32 -> V_2 -> V_67 ) ;
break;
}
F_63 ( V_261 ,
L_33 ,
V_246 , V_246 ? V_246 -> V_67 . V_21 . V_25 : 0 , V_246 ? V_246 -> V_67 . V_145 : 0 ) ;
F_63 ( V_261 ,
L_34 , V_39 ) ;
return V_39 ;
}
unsigned
F_64 ( void )
{
if ( V_175 [ V_273 ] )
return V_175 [ V_273 ] -> V_67 . V_27 . V_283 ;
return 0 ;
}
void
F_65 ( struct V_31 * V_32 )
{
if ( V_32 ) {
F_45 ( & V_32 -> V_207 ,
& V_32 -> V_208 ) ;
}
}
void
F_66 ( struct V_149 * * V_295 ,
V_88 * V_296 )
{
assert ( V_295 != NULL ) ;
if ( V_296 )
* V_296 = 0 ;
* V_295 = V_173 ;
if ( V_173 && V_296 ) {
if ( V_170 > 0 )
* V_296 = V_170 - 1 ;
}
}
