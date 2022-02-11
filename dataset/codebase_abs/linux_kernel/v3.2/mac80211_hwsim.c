static inline void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = ( void * ) V_2 -> V_5 ;
F_2 ( V_4 -> V_6 != V_7 ) ;
}
static inline void F_3 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = ( void * ) V_2 -> V_5 ;
V_4 -> V_6 = V_7 ;
}
static inline void F_4 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = ( void * ) V_2 -> V_5 ;
V_4 -> V_6 = 0 ;
}
static inline void F_5 ( struct V_8 * V_9 )
{
struct V_10 * V_11 = ( void * ) V_9 -> V_5 ;
F_2 ( V_11 -> V_6 != V_12 ) ;
}
static inline void F_6 ( struct V_8 * V_9 )
{
struct V_10 * V_11 = ( void * ) V_9 -> V_5 ;
V_11 -> V_6 = V_12 ;
}
static inline void F_7 ( struct V_8 * V_9 )
{
struct V_10 * V_11 = ( void * ) V_9 -> V_5 ;
V_11 -> V_6 = 0 ;
}
static T_1 F_8 ( struct V_13 * V_14 ,
struct V_15 * V_16 )
{
F_9 ( V_14 ) ;
return V_17 ;
}
static void F_10 ( struct V_18 * V_19 ,
struct V_13 * V_20 )
{
struct V_21 * V_22 = V_19 -> V_23 ;
struct V_13 * V_14 ;
struct V_24 * V_25 ;
T_2 V_26 ;
struct V_27 * V_28 = F_11 ( V_20 ) ;
struct V_29 * V_30 = F_12 ( V_19 , V_28 ) ;
if ( ! F_13 ( V_31 ) )
return;
V_14 = F_14 ( V_20 , sizeof( * V_25 ) , 0 , V_32 ) ;
if ( V_14 == NULL )
return;
V_25 = (struct V_24 * ) F_15 ( V_14 , sizeof( * V_25 ) ) ;
V_25 -> V_25 . V_33 = V_34 ;
V_25 -> V_25 . V_35 = 0 ;
V_25 -> V_25 . V_36 = F_16 ( sizeof( * V_25 ) ) ;
V_25 -> V_25 . V_37 = F_17 ( ( 1 << V_38 ) |
( 1 << V_39 ) |
( 1 << V_40 ) ) ;
V_25 -> V_41 = 0 ;
V_25 -> V_42 = V_30 -> V_43 / 5 ;
V_25 -> V_44 = F_16 ( V_22 -> V_45 -> V_46 ) ;
V_26 = V_47 ;
if ( V_30 -> V_26 & V_48 )
V_26 |= V_49 ;
else
V_26 |= V_50 ;
V_25 -> V_51 = F_16 ( V_26 ) ;
V_14 -> V_16 = V_31 ;
F_18 ( V_14 , 0 ) ;
V_14 -> V_52 = V_53 ;
V_14 -> V_54 = V_55 ;
V_14 -> V_56 = F_19 ( V_57 ) ;
memset ( V_14 -> V_58 , 0 , sizeof( V_14 -> V_58 ) ) ;
F_20 ( V_14 ) ;
}
static void F_21 ( struct V_18 * V_19 , const T_3 * V_59 )
{
struct V_21 * V_22 = V_19 -> V_23 ;
struct V_13 * V_14 ;
struct V_24 * V_25 ;
T_2 V_26 ;
struct V_60 * V_61 ;
if ( ! F_13 ( V_31 ) )
return;
V_14 = F_22 ( 100 ) ;
if ( V_14 == NULL )
return;
V_25 = (struct V_24 * ) F_23 ( V_14 , sizeof( * V_25 ) ) ;
V_25 -> V_25 . V_33 = V_34 ;
V_25 -> V_25 . V_35 = 0 ;
V_25 -> V_25 . V_36 = F_16 ( sizeof( * V_25 ) ) ;
V_25 -> V_25 . V_37 = F_17 ( ( 1 << V_38 ) |
( 1 << V_40 ) ) ;
V_25 -> V_41 = 0 ;
V_25 -> V_42 = 0 ;
V_25 -> V_44 = F_16 ( V_22 -> V_45 -> V_46 ) ;
V_26 = V_47 ;
V_25 -> V_51 = F_16 ( V_26 ) ;
V_61 = (struct V_60 * ) F_23 ( V_14 , 10 ) ;
V_61 -> V_62 = F_16 ( V_63 |
V_64 ) ;
V_61 -> V_65 = F_16 ( 0 ) ;
memcpy ( V_61 -> V_66 , V_59 , V_67 ) ;
V_14 -> V_16 = V_31 ;
F_18 ( V_14 , 0 ) ;
V_14 -> V_52 = V_53 ;
V_14 -> V_54 = V_55 ;
V_14 -> V_56 = F_19 ( V_57 ) ;
memset ( V_14 -> V_58 , 0 , sizeof( V_14 -> V_58 ) ) ;
F_20 ( V_14 ) ;
}
static bool F_24 ( struct V_21 * V_22 ,
struct V_13 * V_14 )
{
switch ( V_22 -> V_68 ) {
case V_69 :
return true ;
case V_70 :
return false ;
case V_71 :
return true ;
case V_72 :
if ( V_22 -> V_73 &&
memcmp ( V_22 -> V_19 -> V_74 -> V_75 , V_14 -> V_22 + 4 ,
V_67 ) == 0 ) {
V_22 -> V_73 = false ;
return true ;
}
return false ;
}
return true ;
}
static void F_25 ( void * V_22 , T_3 * V_76 ,
struct V_1 * V_2 )
{
struct V_77 * V_78 = V_22 ;
if ( memcmp ( V_76 , V_78 -> V_59 , V_67 ) == 0 )
V_78 -> V_79 = true ;
}
static bool F_26 ( struct V_21 * V_22 ,
const T_3 * V_59 )
{
struct V_77 V_78 ;
if ( memcmp ( V_59 , V_22 -> V_19 -> V_74 -> V_75 , V_67 ) == 0 )
return true ;
V_78 . V_79 = false ;
V_78 . V_59 = V_59 ;
F_27 ( V_22 -> V_19 ,
F_25 ,
& V_78 ) ;
return V_78 . V_79 ;
}
static void F_28 ( struct V_18 * V_19 ,
struct V_13 * V_80 ,
int V_81 )
{
struct V_13 * V_14 ;
struct V_21 * V_22 = V_19 -> V_23 ;
struct V_60 * V_25 = (struct V_60 * ) V_80 -> V_22 ;
struct V_27 * V_28 = F_11 ( V_80 ) ;
void * V_82 ;
unsigned int V_83 = 0 ;
int V_84 ;
struct V_85 V_86 [ V_87 ] ;
if ( V_22 -> V_88 ) {
F_29 ( V_19 -> V_74 , L_1 ) ;
F_9 ( V_80 ) ;
return;
}
if ( V_22 -> V_68 != V_69 )
V_25 -> V_62 |= F_16 ( V_89 ) ;
if ( F_30 ( & V_22 -> V_90 ) >= V_91 ) {
while ( F_30 ( & V_22 -> V_90 ) >= V_92 )
F_31 ( & V_22 -> V_90 ) ;
}
V_14 = F_32 ( V_93 , V_32 ) ;
if ( V_14 == NULL )
goto V_94;
V_82 = F_33 ( V_14 , 0 , 0 , & V_95 , 0 ,
V_96 ) ;
if ( V_82 == NULL ) {
F_34 ( V_97 L_2 ) ;
goto V_94;
}
F_35 ( V_14 , V_98 ,
sizeof( struct V_99 ) , V_22 -> V_100 [ 1 ] . V_59 ) ;
F_35 ( V_14 , V_101 , V_80 -> V_102 , V_80 -> V_22 ) ;
if ( V_28 -> V_26 & V_103 )
V_83 |= V_104 ;
if ( V_28 -> V_26 & V_105 )
V_83 |= V_106 ;
F_36 ( V_14 , V_107 , V_83 ) ;
for ( V_84 = 0 ; V_84 < V_87 ; V_84 ++ ) {
V_86 [ V_84 ] . V_108 = V_28 -> V_109 . V_110 [ V_84 ] . V_108 ;
V_86 [ V_84 ] . V_111 = V_28 -> V_109 . V_110 [ V_84 ] . V_111 ;
}
F_35 ( V_14 , V_112 ,
sizeof( struct V_85 ) * V_87 ,
V_86 ) ;
F_37 ( V_14 , V_113 , ( unsigned long ) V_80 ) ;
F_38 ( V_14 , V_82 ) ;
F_39 ( & V_114 , V_14 , V_81 ) ;
F_40 ( & V_22 -> V_90 , V_80 ) ;
return;
V_94:
F_34 ( V_97 L_3 , V_115 ) ;
}
static bool F_41 ( struct V_18 * V_19 ,
struct V_13 * V_14 )
{
struct V_21 * V_22 = V_19 -> V_23 , * V_116 ;
bool V_117 = false ;
struct V_60 * V_25 = (struct V_60 * ) V_14 -> V_22 ;
struct V_27 * V_28 = F_11 ( V_14 ) ;
struct V_118 V_119 ;
if ( V_22 -> V_88 ) {
F_29 ( V_19 -> V_74 , L_1 ) ;
return false ;
}
memset ( & V_119 , 0 , sizeof( V_119 ) ) ;
V_119 . V_120 = V_22 -> V_45 -> V_46 ;
V_119 . V_121 = V_22 -> V_45 -> V_121 ;
V_119 . V_122 = V_28 -> V_123 . V_110 [ 0 ] . V_108 ;
if ( V_28 -> V_123 . V_110 [ 0 ] . V_26 & V_124 )
V_119 . V_125 |= V_126 ;
if ( V_28 -> V_123 . V_110 [ 0 ] . V_26 & V_127 )
V_119 . V_125 |= V_128 ;
if ( V_28 -> V_123 . V_110 [ 0 ] . V_26 & V_129 )
V_119 . V_125 |= V_130 ;
V_119 . signal = V_22 -> V_131 - 50 ;
if ( V_22 -> V_68 != V_69 )
V_25 -> V_62 |= F_16 ( V_89 ) ;
F_42 ( V_14 ) ;
F_43 ( V_14 ) ;
V_14 -> V_132 = 0 ;
F_44 ( V_14 ) ;
F_45 ( V_14 ) ;
F_46 ( & V_133 ) ;
F_47 (data2, &hwsim_radios, list) {
struct V_13 * V_134 ;
if ( V_22 == V_116 )
continue;
if ( V_116 -> V_88 || ! V_116 -> V_135 ||
! F_24 ( V_116 , V_14 ) ||
! V_22 -> V_45 || ! V_116 -> V_45 ||
V_22 -> V_45 -> V_46 != V_116 -> V_45 -> V_46 ||
! ( V_22 -> V_136 & V_116 -> V_136 ) )
continue;
V_134 = F_48 ( V_14 , V_32 ) ;
if ( V_134 == NULL )
continue;
if ( F_26 ( V_116 , V_25 -> V_66 ) )
V_117 = true ;
memcpy ( F_49 ( V_134 ) , & V_119 , sizeof( V_119 ) ) ;
F_50 ( V_116 -> V_19 , V_134 ) ;
}
F_51 ( & V_133 ) ;
return V_117 ;
}
static void F_52 ( struct V_18 * V_19 , struct V_13 * V_14 )
{
bool V_117 ;
struct V_27 * V_137 ;
int V_138 ;
F_10 ( V_19 , V_14 ) ;
if ( V_14 -> V_102 < 10 ) {
F_9 ( V_14 ) ;
return;
}
V_138 = V_139 ;
if ( V_138 )
return F_28 ( V_19 , V_14 , V_138 ) ;
V_117 = F_41 ( V_19 , V_14 ) ;
if ( V_117 && V_14 -> V_102 >= 16 ) {
struct V_60 * V_25 = (struct V_60 * ) V_14 -> V_22 ;
F_21 ( V_19 , V_25 -> V_140 ) ;
}
V_137 = F_11 ( V_14 ) ;
if ( V_137 -> V_123 . V_2 )
F_1 ( V_137 -> V_123 . V_2 ) ;
if ( V_137 -> V_123 . V_9 )
F_5 ( V_137 -> V_123 . V_9 ) ;
F_53 ( V_137 ) ;
if ( ! ( V_137 -> V_26 & V_105 ) && V_117 )
V_137 -> V_26 |= V_141 ;
F_54 ( V_19 , V_14 ) ;
}
static int F_55 ( struct V_18 * V_19 )
{
struct V_21 * V_22 = V_19 -> V_23 ;
F_29 ( V_19 -> V_74 , L_4 , V_115 ) ;
V_22 -> V_135 = 1 ;
return 0 ;
}
static void F_56 ( struct V_18 * V_19 )
{
struct V_21 * V_22 = V_19 -> V_23 ;
V_22 -> V_135 = 0 ;
F_57 ( & V_22 -> V_142 ) ;
F_29 ( V_19 -> V_74 , L_4 , V_115 ) ;
}
static int F_58 ( struct V_18 * V_19 ,
struct V_1 * V_2 )
{
F_29 ( V_19 -> V_74 , L_5 ,
V_115 , F_59 ( V_2 ) ,
V_2 -> V_59 ) ;
F_3 ( V_2 ) ;
return 0 ;
}
static int F_60 ( struct V_18 * V_19 ,
struct V_1 * V_2 ,
enum V_143 V_144 ,
bool V_145 )
{
V_144 = F_61 ( V_144 , V_145 ) ;
F_29 ( V_19 -> V_74 ,
L_6 ,
V_115 , F_59 ( V_2 ) ,
V_144 , V_2 -> V_59 ) ;
F_1 ( V_2 ) ;
return 0 ;
}
static void F_62 (
struct V_18 * V_19 , struct V_1 * V_2 )
{
F_29 ( V_19 -> V_74 , L_5 ,
V_115 , F_59 ( V_2 ) ,
V_2 -> V_59 ) ;
F_1 ( V_2 ) ;
F_4 ( V_2 ) ;
}
static void F_63 ( void * V_146 , T_3 * V_76 ,
struct V_1 * V_2 )
{
struct V_18 * V_19 = V_146 ;
struct V_13 * V_14 ;
struct V_27 * V_28 ;
int V_138 ;
F_1 ( V_2 ) ;
if ( V_2 -> type != V_147 &&
V_2 -> type != V_148 &&
V_2 -> type != V_149 )
return;
V_14 = F_64 ( V_19 , V_2 ) ;
if ( V_14 == NULL )
return;
V_28 = F_11 ( V_14 ) ;
F_10 ( V_19 , V_14 ) ;
V_138 = V_139 ;
if ( V_138 )
return F_28 ( V_19 , V_14 , V_138 ) ;
F_41 ( V_19 , V_14 ) ;
F_9 ( V_14 ) ;
}
static void F_65 ( unsigned long V_146 )
{
struct V_18 * V_19 = (struct V_18 * ) V_146 ;
struct V_21 * V_22 = V_19 -> V_23 ;
if ( ! V_22 -> V_135 )
return;
F_27 (
V_19 , F_63 , V_19 ) ;
V_22 -> V_142 . V_150 = V_151 + V_22 -> V_152 ;
F_66 ( & V_22 -> V_142 ) ;
}
static int F_67 ( struct V_18 * V_19 , T_4 V_153 )
{
struct V_21 * V_22 = V_19 -> V_23 ;
struct V_154 * V_155 = & V_19 -> V_155 ;
static const char * V_156 [ V_157 ] = {
[ V_158 ] = L_7 ,
[ V_159 ] = L_8 ,
[ V_160 ] = L_9 ,
[ V_161 ] = L_10 ,
} ;
F_29 ( V_19 -> V_74 ,
L_11 ,
V_115 ,
V_155 -> V_45 -> V_46 ,
V_162 [ V_155 -> V_163 ] ,
! ! ( V_155 -> V_26 & V_164 ) ,
! ! ( V_155 -> V_26 & V_165 ) ,
V_156 [ V_155 -> V_166 ] ) ;
V_22 -> V_88 = ! ! ( V_155 -> V_26 & V_164 ) ;
V_22 -> V_45 = V_155 -> V_45 ;
V_22 -> V_131 = V_155 -> V_131 ;
if ( ! V_22 -> V_135 || ! V_22 -> V_152 )
F_57 ( & V_22 -> V_142 ) ;
else
F_68 ( & V_22 -> V_142 , V_151 + V_22 -> V_152 ) ;
return 0 ;
}
static void F_69 ( struct V_18 * V_19 ,
unsigned int V_167 ,
unsigned int * V_168 , T_5 V_169 )
{
struct V_21 * V_22 = V_19 -> V_23 ;
F_29 ( V_19 -> V_74 , L_4 , V_115 ) ;
V_22 -> V_170 = 0 ;
if ( * V_168 & V_171 )
V_22 -> V_170 |= V_171 ;
if ( * V_168 & V_172 )
V_22 -> V_170 |= V_172 ;
* V_168 = V_22 -> V_170 ;
}
static void F_70 ( struct V_18 * V_19 ,
struct V_1 * V_2 ,
struct V_173 * V_28 ,
T_4 V_153 )
{
struct V_3 * V_4 = ( void * ) V_2 -> V_5 ;
struct V_21 * V_22 = V_19 -> V_23 ;
F_1 ( V_2 ) ;
F_29 ( V_19 -> V_74 , L_12 , V_115 , V_153 ) ;
if ( V_153 & V_174 ) {
F_29 ( V_19 -> V_74 , L_13 ,
V_115 , V_28 -> V_175 ) ;
memcpy ( V_4 -> V_175 , V_28 -> V_175 , V_67 ) ;
}
if ( V_153 & V_176 ) {
F_29 ( V_19 -> V_74 , L_14 ,
V_28 -> V_177 , V_28 -> V_178 ) ;
V_4 -> V_177 = V_28 -> V_177 ;
V_4 -> V_178 = V_28 -> V_178 ;
}
if ( V_153 & V_179 ) {
F_29 ( V_19 -> V_74 , L_15 , V_28 -> V_152 ) ;
V_22 -> V_152 = 1024 * V_28 -> V_152 / 1000 * V_180 / 1000 ;
if ( F_2 ( ! V_22 -> V_152 ) )
V_22 -> V_152 = 1 ;
if ( V_22 -> V_135 )
F_68 ( & V_22 -> V_142 ,
V_151 + V_22 -> V_152 ) ;
}
if ( V_153 & V_181 ) {
F_29 ( V_19 -> V_74 , L_16 ,
V_28 -> V_182 ) ;
}
if ( V_153 & V_183 ) {
F_29 ( V_19 -> V_74 , L_17 ,
V_28 -> V_184 ) ;
}
if ( V_153 & V_185 ) {
F_29 ( V_19 -> V_74 , L_18 , V_28 -> V_186 ) ;
}
if ( V_153 & V_187 ) {
F_29 ( V_19 -> V_74 , L_19 ,
V_28 -> V_188 ,
V_162 [ V_28 -> V_163 ] ) ;
}
if ( V_153 & V_189 ) {
F_29 ( V_19 -> V_74 , L_20 ,
( unsigned long long ) V_28 -> V_190 ) ;
}
}
static int F_71 ( struct V_18 * V_19 ,
struct V_1 * V_2 ,
struct V_8 * V_9 )
{
F_1 ( V_2 ) ;
F_6 ( V_9 ) ;
return 0 ;
}
static int F_72 ( struct V_18 * V_19 ,
struct V_1 * V_2 ,
struct V_8 * V_9 )
{
F_1 ( V_2 ) ;
F_7 ( V_9 ) ;
return 0 ;
}
static void F_73 ( struct V_18 * V_19 ,
struct V_1 * V_2 ,
enum V_191 V_192 ,
struct V_8 * V_9 )
{
F_1 ( V_2 ) ;
switch ( V_192 ) {
case V_193 :
case V_194 :
break;
default:
F_74 ( 1 , L_21 , V_192 ) ;
break;
}
}
static int F_75 ( struct V_18 * V_19 ,
struct V_8 * V_9 ,
bool V_195 )
{
F_5 ( V_9 ) ;
return 0 ;
}
static int F_76 (
struct V_18 * V_19 ,
struct V_1 * V_2 , T_2 V_196 ,
const struct V_197 * V_198 )
{
F_29 ( V_19 -> V_74 ,
L_22 ,
V_115 , V_196 ,
V_198 -> V_199 , V_198 -> V_200 ,
V_198 -> V_201 , V_198 -> V_202 ) ;
return 0 ;
}
static int F_77 (
struct V_18 * V_19 , int V_108 ,
struct V_203 * V_204 )
{
struct V_154 * V_155 = & V_19 -> V_155 ;
F_29 ( V_19 -> V_74 , L_23 , V_115 , V_108 ) ;
if ( V_108 != 0 )
return - V_205 ;
V_204 -> V_45 = V_155 -> V_45 ;
V_204 -> V_206 = V_207 ;
V_204 -> V_208 = - 92 ;
return 0 ;
}
static int F_78 ( struct V_18 * V_19 ,
void * V_22 , int V_102 )
{
struct V_21 * V_209 = V_19 -> V_23 ;
struct V_210 * V_211 [ V_212 + 1 ] ;
struct V_13 * V_14 ;
int V_213 , V_68 ;
V_213 = F_79 ( V_211 , V_212 , V_22 , V_102 ,
V_214 ) ;
if ( V_213 )
return V_213 ;
if ( ! V_211 [ V_215 ] )
return - V_216 ;
switch ( F_80 ( V_211 [ V_215 ] ) ) {
case V_217 :
if ( ! V_211 [ V_218 ] )
return - V_216 ;
V_68 = F_80 ( V_211 [ V_218 ] ) ;
return F_81 ( V_209 , V_68 ) ;
case V_219 :
V_14 = F_82 ( V_19 -> V_74 ,
F_83 ( sizeof( T_4 ) ) ) ;
if ( ! V_14 )
return - V_220 ;
F_36 ( V_14 , V_218 , V_209 -> V_68 ) ;
return F_84 ( V_14 ) ;
default:
return - V_221 ;
}
V_94:
F_85 ( V_14 ) ;
return - V_222 ;
}
static int F_86 ( struct V_18 * V_19 ,
struct V_1 * V_2 ,
enum V_223 V_224 ,
struct V_8 * V_9 , T_2 V_225 , T_2 * V_226 ,
T_3 V_227 )
{
switch ( V_224 ) {
case V_228 :
F_87 ( V_2 , V_9 -> V_59 , V_225 ) ;
break;
case V_229 :
F_88 ( V_2 , V_9 -> V_59 , V_225 ) ;
break;
case V_230 :
break;
case V_231 :
case V_232 :
break;
default:
return - V_221 ;
}
return 0 ;
}
static void F_89 ( struct V_18 * V_19 , bool V_233 )
{
}
static void F_90 ( struct V_234 * V_235 )
{
struct F_90 * V_236 =
F_91 ( V_235 , struct F_90 , V_237 . V_235 ) ;
F_92 ( V_236 -> V_19 , false ) ;
F_93 ( V_236 ) ;
}
static int F_94 ( struct V_18 * V_19 ,
struct V_1 * V_2 ,
struct V_238 * V_239 )
{
struct F_90 * V_236 = F_95 ( sizeof( * V_236 ) , V_240 ) ;
int V_84 ;
if ( ! V_236 )
return - V_220 ;
V_236 -> V_19 = V_19 ;
F_96 ( & V_236 -> V_237 , F_90 ) ;
F_34 ( V_97 L_24 ) ;
for ( V_84 = 0 ; V_84 < V_239 -> V_241 ; V_84 ++ )
F_34 ( V_97 L_25 ,
V_239 -> V_242 [ V_84 ] -> V_46 ) ;
F_97 ( V_97 , L_26 , V_243 ,
16 , 1 , V_239 -> V_244 , V_239 -> V_245 , 1 ) ;
F_98 ( V_19 , & V_236 -> V_237 , 2 * V_180 ) ;
return 0 ;
}
static void F_99 ( struct V_18 * V_19 )
{
struct V_21 * V_209 = V_19 -> V_23 ;
F_100 ( & V_209 -> V_246 ) ;
if ( V_209 -> V_247 ) {
F_34 ( V_97 L_27 ) ;
goto V_248;
}
F_34 ( V_97 L_28 ) ;
V_209 -> V_247 = true ;
V_248:
F_101 ( & V_209 -> V_246 ) ;
}
static void F_102 ( struct V_18 * V_19 )
{
struct V_21 * V_209 = V_19 -> V_23 ;
F_100 ( & V_209 -> V_246 ) ;
F_34 ( V_97 L_29 ) ;
V_209 -> V_247 = false ;
F_101 ( & V_209 -> V_246 ) ;
}
static void F_103 ( void )
{
struct V_249 V_250 , * V_84 , * V_251 ;
struct V_21 * V_22 , * V_252 ;
F_104 ( & V_250 ) ;
F_105 ( & V_133 ) ;
F_106 (i, tmp, &hwsim_radios)
F_107 ( V_84 , & V_250 ) ;
F_108 ( & V_133 ) ;
F_109 (data, tmpdata, &tmplist, list) {
F_110 ( V_22 -> V_253 ) ;
F_110 ( V_22 -> V_254 ) ;
F_110 ( V_22 -> V_255 ) ;
F_111 ( V_22 -> V_19 ) ;
F_112 ( V_22 -> V_16 ) ;
F_113 ( V_22 -> V_19 ) ;
}
F_114 ( V_256 ) ;
}
static void F_115 ( struct V_15 * V_16 )
{
V_16 -> V_257 = & V_258 ;
V_16 -> V_259 = V_260 ;
F_116 ( V_16 ) ;
V_16 -> V_261 = 0 ;
V_16 -> type = V_262 ;
memset ( V_16 -> V_263 , 0 , V_67 ) ;
V_16 -> V_263 [ 0 ] = 0x12 ;
}
static void F_117 ( void * V_264 , T_3 * V_76 , struct V_1 * V_2 )
{
struct V_21 * V_22 = V_264 ;
struct V_3 * V_4 = ( void * ) V_2 -> V_5 ;
struct V_13 * V_14 ;
struct V_265 * V_266 ;
int V_138 ;
if ( ! V_4 -> V_177 )
return;
F_29 ( V_22 -> V_19 -> V_74 ,
L_30 ,
V_115 , V_4 -> V_175 , V_4 -> V_178 ) ;
V_14 = F_22 ( sizeof( * V_266 ) ) ;
if ( ! V_14 )
return;
V_266 = ( void * ) F_23 ( V_14 , sizeof( * V_266 ) ) ;
V_266 -> V_62 = F_16 ( V_63 |
V_267 |
V_89 ) ;
V_266 -> V_178 = F_16 ( 0xc000 | V_4 -> V_178 ) ;
memcpy ( V_266 -> V_175 , V_4 -> V_175 , V_67 ) ;
memcpy ( V_266 -> V_268 , V_76 , V_67 ) ;
V_138 = V_139 ;
if ( V_138 )
return F_28 ( V_22 -> V_19 , V_14 , V_138 ) ;
if ( ! F_41 ( V_22 -> V_19 , V_14 ) )
F_34 ( V_97 L_31 , V_115 ) ;
F_9 ( V_14 ) ;
}
static void F_118 ( struct V_21 * V_22 , T_3 * V_76 ,
struct V_1 * V_2 , int V_68 )
{
struct V_3 * V_4 = ( void * ) V_2 -> V_5 ;
struct V_13 * V_14 ;
struct V_60 * V_25 ;
int V_138 ;
if ( ! V_4 -> V_177 )
return;
F_29 ( V_22 -> V_19 -> V_74 ,
L_32 ,
V_115 , V_4 -> V_175 , V_68 ) ;
V_14 = F_22 ( sizeof( * V_25 ) ) ;
if ( ! V_14 )
return;
V_25 = ( void * ) F_23 ( V_14 , sizeof( * V_25 ) - V_67 ) ;
V_25 -> V_62 = F_16 ( V_269 |
V_270 |
( V_68 ? V_89 : 0 ) ) ;
V_25 -> V_65 = F_16 ( 0 ) ;
memcpy ( V_25 -> V_66 , V_4 -> V_175 , V_67 ) ;
memcpy ( V_25 -> V_140 , V_76 , V_67 ) ;
memcpy ( V_25 -> V_271 , V_4 -> V_175 , V_67 ) ;
V_138 = V_139 ;
if ( V_138 )
return F_28 ( V_22 -> V_19 , V_14 , V_138 ) ;
if ( ! F_41 ( V_22 -> V_19 , V_14 ) )
F_34 ( V_97 L_33 , V_115 ) ;
F_9 ( V_14 ) ;
}
static void F_119 ( void * V_264 , T_3 * V_76 ,
struct V_1 * V_2 )
{
struct V_21 * V_22 = V_264 ;
F_118 ( V_22 , V_76 , V_2 , 1 ) ;
}
static void F_120 ( void * V_264 , T_3 * V_76 ,
struct V_1 * V_2 )
{
struct V_21 * V_22 = V_264 ;
F_118 ( V_22 , V_76 , V_2 , 0 ) ;
}
static int F_121 ( void * V_264 , T_5 * V_272 )
{
struct V_21 * V_22 = V_264 ;
* V_272 = V_22 -> V_68 ;
return 0 ;
}
static int F_81 ( void * V_264 , T_5 V_272 )
{
struct V_21 * V_22 = V_264 ;
enum V_273 V_274 ;
if ( V_272 != V_69 && V_272 != V_70 && V_272 != V_71 &&
V_272 != V_72 )
return - V_216 ;
V_274 = V_22 -> V_68 ;
V_22 -> V_68 = V_272 ;
if ( V_272 == V_72 ) {
F_122 ( V_22 -> V_19 ,
F_117 , V_22 ) ;
V_22 -> V_73 = true ;
} else if ( V_274 == V_69 && V_272 != V_69 ) {
F_122 ( V_22 -> V_19 ,
F_119 ,
V_22 ) ;
} else if ( V_274 != V_69 && V_272 == V_69 ) {
F_122 ( V_22 -> V_19 ,
F_120 ,
V_22 ) ;
}
return 0 ;
}
static int F_123 ( void * V_264 , T_5 * V_272 )
{
struct V_21 * V_22 = V_264 ;
* V_272 = V_22 -> V_136 ;
return 0 ;
}
static int F_124 ( void * V_264 , T_5 V_272 )
{
struct V_21 * V_22 = V_264 ;
V_22 -> V_136 = V_272 ;
return 0 ;
}
struct V_21 * F_125 (
struct V_99 * V_59 )
{
struct V_21 * V_22 ;
bool V_275 = false ;
F_105 ( & V_133 ) ;
F_47 (data, &hwsim_radios, list) {
if ( memcmp ( V_22 -> V_100 [ 1 ] . V_59 , V_59 ,
sizeof( struct V_99 ) ) == 0 ) {
V_275 = true ;
break;
}
}
F_108 ( & V_133 ) ;
if ( ! V_275 )
return NULL ;
return V_22 ;
}
static int F_126 ( struct V_13 * V_276 ,
struct V_277 * V_28 )
{
struct V_60 * V_25 ;
struct V_21 * V_116 ;
struct V_27 * V_137 ;
struct V_85 * V_86 ;
struct V_13 T_6 * V_278 ;
struct V_13 * V_14 , * V_251 ;
struct V_99 * V_279 ;
unsigned int V_83 ;
int V_84 ;
bool V_280 = false ;
if ( ! V_28 -> V_281 [ V_98 ] ||
! V_28 -> V_281 [ V_107 ] ||
! V_28 -> V_281 [ V_113 ] ||
! V_28 -> V_281 [ V_112 ] )
goto V_248;
V_279 = (struct V_99 * ) F_127 (
V_28 -> V_281 [ V_98 ] ) ;
V_83 = F_80 ( V_28 -> V_281 [ V_107 ] ) ;
V_278 = (struct V_13 T_6 * )
( unsigned long ) F_128 ( V_28 -> V_281 [ V_113 ] ) ;
V_116 = F_125 ( V_279 ) ;
if ( V_116 == NULL )
goto V_248;
F_129 (&data2->pending, skb, tmp) {
if ( V_14 == V_278 ) {
F_130 ( V_14 , & V_116 -> V_90 ) ;
V_280 = true ;
break;
}
}
if ( ! V_280 )
goto V_248;
V_86 = (struct V_85 * ) F_127 (
V_28 -> V_281 [ V_112 ] ) ;
V_137 = F_11 ( V_14 ) ;
if ( V_137 -> V_123 . V_2 )
F_1 ( V_137 -> V_123 . V_2 ) ;
if ( V_137 -> V_123 . V_9 )
F_5 ( V_137 -> V_123 . V_9 ) ;
F_53 ( V_137 ) ;
for ( V_84 = 0 ; V_84 < V_87 ; V_84 ++ ) {
V_137 -> V_109 . V_110 [ V_84 ] . V_108 = V_86 [ V_84 ] . V_108 ;
V_137 -> V_109 . V_110 [ V_84 ] . V_111 = V_86 [ V_84 ] . V_111 ;
}
V_137 -> V_109 . V_282 = F_80 ( V_28 -> V_281 [ V_283 ] ) ;
if ( ! ( V_83 & V_106 ) &&
( V_83 & V_284 ) ) {
if ( V_14 -> V_102 >= 16 ) {
V_25 = (struct V_60 * ) V_14 -> V_22 ;
F_21 ( V_116 -> V_19 , V_25 -> V_140 ) ;
}
}
F_54 ( V_116 -> V_19 , V_14 ) ;
return 0 ;
V_248:
return - V_216 ;
}
static int F_131 ( struct V_13 * V_276 ,
struct V_277 * V_28 )
{
struct V_21 * V_116 ;
struct V_118 V_119 ;
struct V_99 * V_285 ;
int V_286 ;
char * V_287 ;
struct V_13 * V_14 = NULL ;
if ( ! V_28 -> V_281 [ V_288 ] ||
! V_28 -> V_281 [ V_101 ] ||
! V_28 -> V_281 [ V_289 ] ||
! V_28 -> V_281 [ V_283 ] )
goto V_248;
V_285 = (struct V_99 * ) F_127 (
V_28 -> V_281 [ V_288 ] ) ;
V_286 = F_132 ( V_28 -> V_281 [ V_101 ] ) ;
V_287 = ( char * ) F_127 ( V_28 -> V_281 [ V_101 ] ) ;
V_14 = F_133 ( V_286 , V_240 ) ;
if ( V_14 == NULL )
goto V_213;
if ( V_286 <= V_290 ) {
memcpy ( F_23 ( V_14 , V_286 ) , V_287 ,
V_286 ) ;
} else
goto V_213;
V_116 = F_125 ( V_285 ) ;
if ( V_116 == NULL )
goto V_248;
if ( V_116 -> V_88 || ! V_116 -> V_135 || ! V_116 -> V_45 )
goto V_248;
memset ( & V_119 , 0 , sizeof( V_119 ) ) ;
V_119 . V_120 = V_116 -> V_45 -> V_46 ;
V_119 . V_121 = V_116 -> V_45 -> V_121 ;
V_119 . V_122 = F_80 ( V_28 -> V_281 [ V_289 ] ) ;
V_119 . signal = F_80 ( V_28 -> V_281 [ V_283 ] ) ;
memcpy ( F_49 ( V_14 ) , & V_119 , sizeof( V_119 ) ) ;
F_50 ( V_116 -> V_19 , V_14 ) ;
return 0 ;
V_213:
F_34 ( V_97 L_3 , V_115 ) ;
goto V_248;
V_248:
F_9 ( V_14 ) ;
return - V_216 ;
}
static int F_134 ( struct V_13 * V_276 ,
struct V_277 * V_28 )
{
if ( V_28 == NULL )
goto V_248;
V_139 = V_28 -> V_291 ;
F_34 ( V_97 L_34
L_35 , V_28 -> V_291 ) ;
return 0 ;
V_248:
F_34 ( V_97 L_3 , V_115 ) ;
return - V_216 ;
}
static int F_135 ( struct V_292 * V_293 ,
unsigned long V_294 ,
void * V_295 )
{
struct V_296 * V_297 = V_295 ;
if ( V_294 != V_298 )
return V_299 ;
if ( V_297 -> V_300 == V_139 ) {
F_34 ( V_301 L_36
L_37 ) ;
V_139 = 0 ;
}
return V_299 ;
}
static int F_136 ( void )
{
int V_302 ;
F_34 ( V_301 L_38 ) ;
V_139 = 0 ;
V_302 = F_137 ( & V_95 ,
V_303 , F_138 ( V_303 ) ) ;
if ( V_302 )
goto V_304;
V_302 = F_139 ( & V_305 ) ;
if ( V_302 )
goto V_304;
return 0 ;
V_304:
F_34 ( V_97 L_3 , V_115 ) ;
return - V_216 ;
}
static void F_140 ( void )
{
int V_79 ;
F_34 ( V_301 L_39 ) ;
F_141 ( & V_305 ) ;
V_79 = F_142 ( & V_95 ) ;
if ( V_79 )
F_34 ( V_97 L_40
L_41 , V_79 ) ;
}
static int T_7 F_143 ( void )
{
int V_84 , V_213 = 0 ;
T_3 V_59 [ V_67 ] ;
struct V_21 * V_22 ;
struct V_18 * V_19 ;
enum V_306 V_121 ;
if ( V_307 < 1 || V_307 > 100 )
return - V_216 ;
if ( V_308 ) {
V_309 . V_310 = F_94 ;
V_309 . V_311 = NULL ;
V_309 . V_312 = NULL ;
}
F_144 ( & V_133 ) ;
F_104 ( & V_313 ) ;
V_256 = F_145 ( V_314 , L_42 ) ;
if ( F_146 ( V_256 ) )
return F_147 ( V_256 ) ;
memset ( V_59 , 0 , V_67 ) ;
V_59 [ 0 ] = 0x02 ;
for ( V_84 = 0 ; V_84 < V_307 ; V_84 ++ ) {
F_34 ( V_97 L_43 ,
V_84 ) ;
V_19 = F_148 ( sizeof( * V_22 ) , & V_309 ) ;
if ( ! V_19 ) {
F_34 ( V_97 L_44
L_45 ) ;
V_213 = - V_220 ;
goto V_315;
}
V_22 = V_19 -> V_23 ;
V_22 -> V_19 = V_19 ;
V_22 -> V_16 = F_149 ( V_256 , NULL , 0 , V_19 ,
L_46 , V_84 ) ;
if ( F_146 ( V_22 -> V_16 ) ) {
F_34 ( V_97
L_47
L_48 , F_147 ( V_22 -> V_16 ) ) ;
V_213 = - V_220 ;
goto V_316;
}
V_22 -> V_16 -> V_317 = & V_318 ;
F_150 ( & V_22 -> V_90 ) ;
F_151 ( V_19 , V_22 -> V_16 ) ;
V_59 [ 3 ] = V_84 >> 8 ;
V_59 [ 4 ] = V_84 ;
memcpy ( V_22 -> V_100 [ 0 ] . V_59 , V_59 , V_67 ) ;
memcpy ( V_22 -> V_100 [ 1 ] . V_59 , V_59 , V_67 ) ;
V_22 -> V_100 [ 1 ] . V_59 [ 0 ] |= 0x40 ;
V_19 -> V_74 -> V_319 = 2 ;
V_19 -> V_74 -> V_100 = V_22 -> V_100 ;
if ( V_308 ) {
V_19 -> V_74 -> V_320 = 255 ;
V_19 -> V_74 -> V_321 = V_290 ;
}
V_19 -> V_322 = 1 ;
V_19 -> V_323 = 4 ;
V_19 -> V_74 -> V_324 =
F_152 ( V_325 ) |
F_152 ( V_147 ) |
F_152 ( V_326 ) |
F_152 ( V_327 ) |
F_152 ( V_149 ) |
F_152 ( V_148 ) ;
V_19 -> V_26 = V_328 |
V_329 |
V_330 |
V_331 |
V_332 ;
V_19 -> V_333 = sizeof( struct V_3 ) ;
V_19 -> V_334 = sizeof( struct V_10 ) ;
memcpy ( V_22 -> V_335 , V_336 ,
sizeof( V_336 ) ) ;
memcpy ( V_22 -> V_337 , V_338 ,
sizeof( V_338 ) ) ;
memcpy ( V_22 -> V_110 , V_339 , sizeof( V_339 ) ) ;
for ( V_121 = V_340 ; V_121 < V_341 ; V_121 ++ ) {
struct V_342 * V_343 = & V_22 -> V_344 [ V_121 ] ;
switch ( V_121 ) {
case V_340 :
V_343 -> V_242 = V_22 -> V_335 ;
V_343 -> V_241 =
F_138 ( V_336 ) ;
V_343 -> V_345 = V_22 -> V_110 ;
V_343 -> V_346 = F_138 ( V_339 ) ;
break;
case V_347 :
V_343 -> V_242 = V_22 -> V_337 ;
V_343 -> V_241 =
F_138 ( V_338 ) ;
V_343 -> V_345 = V_22 -> V_110 + 4 ;
V_343 -> V_346 = F_138 ( V_339 ) - 4 ;
break;
default:
break;
}
V_343 -> V_348 . V_349 = true ;
V_343 -> V_348 . V_350 = V_351 |
V_352 |
V_353 |
V_354 ;
V_343 -> V_348 . V_355 = 0x3 ;
V_343 -> V_348 . V_356 = 0x6 ;
memset ( & V_343 -> V_348 . V_357 , 0 ,
sizeof( V_343 -> V_348 . V_357 ) ) ;
V_343 -> V_348 . V_357 . V_358 [ 0 ] = 0xff ;
V_343 -> V_348 . V_357 . V_358 [ 1 ] = 0xff ;
V_343 -> V_348 . V_357 . V_359 = V_360 ;
V_19 -> V_74 -> V_344 [ V_121 ] = V_343 ;
}
V_22 -> V_136 = 1 ;
F_153 ( & V_22 -> V_246 ) ;
V_19 -> V_361 = 4 ;
V_19 -> V_362 = 11 ;
switch ( V_363 ) {
case V_364 :
case V_365 :
case V_366 :
case V_367 :
break;
case V_368 :
if ( V_84 == 0 ) {
V_19 -> V_74 -> V_26 |= V_369 ;
F_154 ( V_19 -> V_74 ,
& V_370 ) ;
}
break;
case V_371 :
V_19 -> V_74 -> V_26 |= V_369 ;
F_154 ( V_19 -> V_74 ,
& V_370 ) ;
break;
case V_372 :
if ( V_84 == 0 ) {
V_19 -> V_74 -> V_26 |= V_369 ;
F_154 ( V_19 -> V_74 ,
& V_370 ) ;
} else if ( V_84 == 1 ) {
V_19 -> V_74 -> V_26 |= V_369 ;
F_154 ( V_19 -> V_74 ,
& V_373 ) ;
}
break;
case V_374 :
V_19 -> V_74 -> V_26 |= V_375 ;
break;
case V_376 :
case V_377 :
if ( V_84 == 0 )
V_19 -> V_74 -> V_26 |= V_375 ;
break;
case V_378 :
if ( V_84 == 0 ) {
V_19 -> V_74 -> V_26 |= V_369 ;
F_154 ( V_19 -> V_74 ,
& V_370 ) ;
} else if ( V_84 == 1 ) {
V_19 -> V_74 -> V_26 |= V_369 ;
F_154 ( V_19 -> V_74 ,
& V_373 ) ;
} else if ( V_84 == 4 )
V_19 -> V_74 -> V_26 |= V_375 ;
break;
default:
break;
}
if ( V_363 )
F_155 ( 1 ) ;
V_213 = F_156 ( V_19 ) ;
if ( V_213 < 0 ) {
F_34 ( V_97 L_40
L_49 , V_213 ) ;
goto V_379;
}
switch ( V_363 ) {
case V_368 :
case V_364 :
break;
case V_365 :
if ( ! V_84 )
F_157 ( V_19 -> V_74 , V_380 [ 0 ] ) ;
break;
case V_366 :
case V_374 :
F_157 ( V_19 -> V_74 , V_380 [ 0 ] ) ;
break;
case V_367 :
if ( V_84 < F_138 ( V_380 ) )
F_157 ( V_19 -> V_74 , V_380 [ V_84 ] ) ;
break;
case V_371 :
case V_372 :
break;
case V_376 :
if ( V_84 == 0 )
F_157 ( V_19 -> V_74 , V_380 [ 0 ] ) ;
break;
case V_377 :
if ( V_84 == 0 )
F_157 ( V_19 -> V_74 , V_380 [ 0 ] ) ;
else if ( V_84 == 1 )
F_157 ( V_19 -> V_74 , V_380 [ 1 ] ) ;
break;
case V_378 :
if ( V_84 == 2 )
F_157 ( V_19 -> V_74 , V_380 [ 0 ] ) ;
else if ( V_84 == 3 )
F_157 ( V_19 -> V_74 , V_380 [ 1 ] ) ;
else if ( V_84 == 4 )
F_157 ( V_19 -> V_74 , V_380 [ 2 ] ) ;
break;
default:
break;
}
F_29 ( V_19 -> V_74 , L_50 ,
V_19 -> V_74 -> V_75 ) ;
V_22 -> V_255 = F_158 ( L_51 ,
V_19 -> V_74 -> V_381 ) ;
V_22 -> V_254 = F_159 ( L_52 , 0666 ,
V_22 -> V_255 , V_22 ,
& V_382 ) ;
V_22 -> V_253 = F_159 ( L_53 , 0666 ,
V_22 -> V_255 , V_22 ,
& V_383 ) ;
F_160 ( & V_22 -> V_142 , F_65 ,
( unsigned long ) V_19 ) ;
F_161 ( & V_22 -> V_384 , & V_313 ) ;
}
V_31 = F_162 ( 0 , L_46 , F_115 ) ;
if ( V_31 == NULL )
goto V_315;
F_163 () ;
V_213 = F_164 ( V_31 , V_31 -> V_385 ) ;
if ( V_213 < 0 )
goto V_386;
V_213 = F_165 ( V_31 ) ;
if ( V_213 < 0 )
goto V_386;
F_166 () ;
V_213 = F_136 () ;
if ( V_213 < 0 )
goto V_387;
return 0 ;
V_387:
F_34 ( V_97 L_54 ) ;
return V_213 ;
V_386:
F_166 () ;
V_260 ( V_31 ) ;
F_103 () ;
return V_213 ;
V_379:
F_112 ( V_22 -> V_16 ) ;
V_316:
F_113 ( V_19 ) ;
V_315:
F_103 () ;
return V_213 ;
}
static void T_8 F_167 ( void )
{
F_34 ( V_97 L_55 ) ;
F_140 () ;
F_103 () ;
F_168 ( V_31 ) ;
}
