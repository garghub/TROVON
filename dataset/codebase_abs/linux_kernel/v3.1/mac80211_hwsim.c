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
V_119 . signal = V_22 -> V_124 - 50 ;
if ( V_22 -> V_68 != V_69 )
V_25 -> V_62 |= F_16 ( V_89 ) ;
F_42 ( V_14 ) ;
F_43 ( V_14 ) ;
V_14 -> V_125 = 0 ;
F_44 ( V_14 ) ;
F_45 ( V_14 ) ;
F_46 ( & V_126 ) ;
F_47 (data2, &hwsim_radios, list) {
struct V_13 * V_127 ;
if ( V_22 == V_116 )
continue;
if ( V_116 -> V_88 || ! V_116 -> V_128 ||
! F_24 ( V_116 , V_14 ) ||
! V_22 -> V_45 || ! V_116 -> V_45 ||
V_22 -> V_45 -> V_46 != V_116 -> V_45 -> V_46 ||
! ( V_22 -> V_129 & V_116 -> V_129 ) )
continue;
V_127 = F_48 ( V_14 , V_32 ) ;
if ( V_127 == NULL )
continue;
if ( F_26 ( V_116 , V_25 -> V_66 ) )
V_117 = true ;
memcpy ( F_49 ( V_127 ) , & V_119 , sizeof( V_119 ) ) ;
F_50 ( V_116 -> V_19 , V_127 ) ;
}
F_51 ( & V_126 ) ;
return V_117 ;
}
static void F_52 ( struct V_18 * V_19 , struct V_13 * V_14 )
{
bool V_117 ;
struct V_27 * V_130 ;
int V_131 ;
F_10 ( V_19 , V_14 ) ;
if ( V_14 -> V_102 < 10 ) {
F_9 ( V_14 ) ;
return;
}
V_131 = V_132 ;
if ( V_131 )
return F_28 ( V_19 , V_14 , V_131 ) ;
V_117 = F_41 ( V_19 , V_14 ) ;
if ( V_117 && V_14 -> V_102 >= 16 ) {
struct V_60 * V_25 = (struct V_60 * ) V_14 -> V_22 ;
F_21 ( V_19 , V_25 -> V_133 ) ;
}
V_130 = F_11 ( V_14 ) ;
if ( V_130 -> V_123 . V_2 )
F_1 ( V_130 -> V_123 . V_2 ) ;
if ( V_130 -> V_123 . V_9 )
F_5 ( V_130 -> V_123 . V_9 ) ;
F_53 ( V_130 ) ;
if ( ! ( V_130 -> V_26 & V_105 ) && V_117 )
V_130 -> V_26 |= V_134 ;
F_54 ( V_19 , V_14 ) ;
}
static int F_55 ( struct V_18 * V_19 )
{
struct V_21 * V_22 = V_19 -> V_23 ;
F_29 ( V_19 -> V_74 , L_4 , V_115 ) ;
V_22 -> V_128 = 1 ;
return 0 ;
}
static void F_56 ( struct V_18 * V_19 )
{
struct V_21 * V_22 = V_19 -> V_23 ;
V_22 -> V_128 = 0 ;
F_57 ( & V_22 -> V_135 ) ;
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
enum V_136 V_137 ,
bool V_138 )
{
V_137 = F_61 ( V_137 , V_138 ) ;
F_29 ( V_19 -> V_74 ,
L_6 ,
V_115 , F_59 ( V_2 ) ,
V_137 , V_2 -> V_59 ) ;
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
static void F_63 ( void * V_139 , T_3 * V_76 ,
struct V_1 * V_2 )
{
struct V_18 * V_19 = V_139 ;
struct V_13 * V_14 ;
struct V_27 * V_28 ;
int V_131 ;
F_1 ( V_2 ) ;
if ( V_2 -> type != V_140 &&
V_2 -> type != V_141 &&
V_2 -> type != V_142 )
return;
V_14 = F_64 ( V_19 , V_2 ) ;
if ( V_14 == NULL )
return;
V_28 = F_11 ( V_14 ) ;
F_10 ( V_19 , V_14 ) ;
V_131 = V_132 ;
if ( V_131 )
return F_28 ( V_19 , V_14 , V_131 ) ;
F_41 ( V_19 , V_14 ) ;
F_9 ( V_14 ) ;
}
static void F_65 ( unsigned long V_139 )
{
struct V_18 * V_19 = (struct V_18 * ) V_139 ;
struct V_21 * V_22 = V_19 -> V_23 ;
if ( ! V_22 -> V_128 )
return;
F_27 (
V_19 , F_63 , V_19 ) ;
V_22 -> V_135 . V_143 = V_144 + V_22 -> V_145 ;
F_66 ( & V_22 -> V_135 ) ;
}
static int F_67 ( struct V_18 * V_19 , T_4 V_146 )
{
struct V_21 * V_22 = V_19 -> V_23 ;
struct V_147 * V_148 = & V_19 -> V_148 ;
static const char * V_149 [ V_150 ] = {
[ V_151 ] = L_7 ,
[ V_152 ] = L_8 ,
[ V_153 ] = L_9 ,
[ V_154 ] = L_10 ,
} ;
F_29 ( V_19 -> V_74 ,
L_11 ,
V_115 ,
V_148 -> V_45 -> V_46 ,
V_155 [ V_148 -> V_156 ] ,
! ! ( V_148 -> V_26 & V_157 ) ,
! ! ( V_148 -> V_26 & V_158 ) ,
V_149 [ V_148 -> V_159 ] ) ;
V_22 -> V_88 = ! ! ( V_148 -> V_26 & V_157 ) ;
V_22 -> V_45 = V_148 -> V_45 ;
V_22 -> V_124 = V_148 -> V_124 ;
if ( ! V_22 -> V_128 || ! V_22 -> V_145 )
F_57 ( & V_22 -> V_135 ) ;
else
F_68 ( & V_22 -> V_135 , V_144 + V_22 -> V_145 ) ;
return 0 ;
}
static void F_69 ( struct V_18 * V_19 ,
unsigned int V_160 ,
unsigned int * V_161 , T_5 V_162 )
{
struct V_21 * V_22 = V_19 -> V_23 ;
F_29 ( V_19 -> V_74 , L_4 , V_115 ) ;
V_22 -> V_163 = 0 ;
if ( * V_161 & V_164 )
V_22 -> V_163 |= V_164 ;
if ( * V_161 & V_165 )
V_22 -> V_163 |= V_165 ;
* V_161 = V_22 -> V_163 ;
}
static void F_70 ( struct V_18 * V_19 ,
struct V_1 * V_2 ,
struct V_166 * V_28 ,
T_4 V_146 )
{
struct V_3 * V_4 = ( void * ) V_2 -> V_5 ;
struct V_21 * V_22 = V_19 -> V_23 ;
F_1 ( V_2 ) ;
F_29 ( V_19 -> V_74 , L_12 , V_115 , V_146 ) ;
if ( V_146 & V_167 ) {
F_29 ( V_19 -> V_74 , L_13 ,
V_115 , V_28 -> V_168 ) ;
memcpy ( V_4 -> V_168 , V_28 -> V_168 , V_67 ) ;
}
if ( V_146 & V_169 ) {
F_29 ( V_19 -> V_74 , L_14 ,
V_28 -> V_170 , V_28 -> V_171 ) ;
V_4 -> V_170 = V_28 -> V_170 ;
V_4 -> V_171 = V_28 -> V_171 ;
}
if ( V_146 & V_172 ) {
F_29 ( V_19 -> V_74 , L_15 , V_28 -> V_145 ) ;
V_22 -> V_145 = 1024 * V_28 -> V_145 / 1000 * V_173 / 1000 ;
if ( F_2 ( ! V_22 -> V_145 ) )
V_22 -> V_145 = 1 ;
if ( V_22 -> V_128 )
F_68 ( & V_22 -> V_135 ,
V_144 + V_22 -> V_145 ) ;
}
if ( V_146 & V_174 ) {
F_29 ( V_19 -> V_74 , L_16 ,
V_28 -> V_175 ) ;
}
if ( V_146 & V_176 ) {
F_29 ( V_19 -> V_74 , L_17 ,
V_28 -> V_177 ) ;
}
if ( V_146 & V_178 ) {
F_29 ( V_19 -> V_74 , L_18 , V_28 -> V_179 ) ;
}
if ( V_146 & V_180 ) {
F_29 ( V_19 -> V_74 , L_19 ,
V_28 -> V_181 ,
V_155 [ V_28 -> V_156 ] ) ;
}
if ( V_146 & V_182 ) {
F_29 ( V_19 -> V_74 , L_20 ,
( unsigned long long ) V_28 -> V_183 ) ;
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
enum V_184 V_185 ,
struct V_8 * V_9 )
{
F_1 ( V_2 ) ;
switch ( V_185 ) {
case V_186 :
case V_187 :
break;
default:
F_74 ( 1 , L_21 , V_185 ) ;
break;
}
}
static int F_75 ( struct V_18 * V_19 ,
struct V_8 * V_9 ,
bool V_188 )
{
F_5 ( V_9 ) ;
return 0 ;
}
static int F_76 (
struct V_18 * V_19 , T_2 V_189 ,
const struct V_190 * V_191 )
{
F_29 ( V_19 -> V_74 ,
L_22 ,
V_115 , V_189 ,
V_191 -> V_192 , V_191 -> V_193 ,
V_191 -> V_194 , V_191 -> V_195 ) ;
return 0 ;
}
static int F_77 (
struct V_18 * V_19 , int V_108 ,
struct V_196 * V_197 )
{
struct V_147 * V_148 = & V_19 -> V_148 ;
F_29 ( V_19 -> V_74 , L_23 , V_115 , V_108 ) ;
if ( V_108 != 0 )
return - V_198 ;
V_197 -> V_45 = V_148 -> V_45 ;
V_197 -> V_199 = V_200 ;
V_197 -> V_201 = - 92 ;
return 0 ;
}
static int F_78 ( struct V_18 * V_19 ,
void * V_22 , int V_102 )
{
struct V_21 * V_202 = V_19 -> V_23 ;
struct V_203 * V_204 [ V_205 + 1 ] ;
struct V_13 * V_14 ;
int V_206 , V_68 ;
V_206 = F_79 ( V_204 , V_205 , V_22 , V_102 ,
V_207 ) ;
if ( V_206 )
return V_206 ;
if ( ! V_204 [ V_208 ] )
return - V_209 ;
switch ( F_80 ( V_204 [ V_208 ] ) ) {
case V_210 :
if ( ! V_204 [ V_211 ] )
return - V_209 ;
V_68 = F_80 ( V_204 [ V_211 ] ) ;
return F_81 ( V_202 , V_68 ) ;
case V_212 :
V_14 = F_82 ( V_19 -> V_74 ,
F_83 ( sizeof( T_4 ) ) ) ;
if ( ! V_14 )
return - V_213 ;
F_36 ( V_14 , V_211 , V_202 -> V_68 ) ;
return F_84 ( V_14 ) ;
default:
return - V_214 ;
}
V_94:
F_85 ( V_14 ) ;
return - V_215 ;
}
static int F_86 ( struct V_18 * V_19 ,
struct V_1 * V_2 ,
enum V_216 V_217 ,
struct V_8 * V_9 , T_2 V_218 , T_2 * V_219 ,
T_3 V_220 )
{
switch ( V_217 ) {
case V_221 :
F_87 ( V_2 , V_9 -> V_59 , V_218 ) ;
break;
case V_222 :
F_88 ( V_2 , V_9 -> V_59 , V_218 ) ;
break;
case V_223 :
break;
case V_224 :
case V_225 :
break;
default:
return - V_214 ;
}
return 0 ;
}
static void F_89 ( struct V_18 * V_19 , bool V_226 )
{
}
static void F_90 ( struct V_227 * V_228 )
{
struct F_90 * V_229 =
F_91 ( V_228 , struct F_90 , V_230 . V_228 ) ;
F_92 ( V_229 -> V_19 , false ) ;
F_93 ( V_229 ) ;
}
static int F_94 ( struct V_18 * V_19 ,
struct V_1 * V_2 ,
struct V_231 * V_232 )
{
struct F_90 * V_229 = F_95 ( sizeof( * V_229 ) , V_233 ) ;
int V_84 ;
if ( ! V_229 )
return - V_213 ;
V_229 -> V_19 = V_19 ;
F_96 ( & V_229 -> V_230 , F_90 ) ;
F_34 ( V_97 L_24 ) ;
for ( V_84 = 0 ; V_84 < V_232 -> V_234 ; V_84 ++ )
F_34 ( V_97 L_25 ,
V_232 -> V_235 [ V_84 ] -> V_46 ) ;
F_97 ( V_97 , L_26 , V_236 ,
16 , 1 , V_232 -> V_237 , V_232 -> V_238 , 1 ) ;
F_98 ( V_19 , & V_229 -> V_230 , 2 * V_173 ) ;
return 0 ;
}
static void F_99 ( struct V_18 * V_19 )
{
struct V_21 * V_202 = V_19 -> V_23 ;
F_100 ( & V_202 -> V_239 ) ;
if ( V_202 -> V_240 ) {
F_34 ( V_97 L_27 ) ;
goto V_241;
}
F_34 ( V_97 L_28 ) ;
V_202 -> V_240 = true ;
V_241:
F_101 ( & V_202 -> V_239 ) ;
}
static void F_102 ( struct V_18 * V_19 )
{
struct V_21 * V_202 = V_19 -> V_23 ;
F_100 ( & V_202 -> V_239 ) ;
F_34 ( V_97 L_29 ) ;
V_202 -> V_240 = false ;
F_101 ( & V_202 -> V_239 ) ;
}
static void F_103 ( void )
{
struct V_242 V_243 , * V_84 , * V_244 ;
struct V_21 * V_22 , * V_245 ;
F_104 ( & V_243 ) ;
F_105 ( & V_126 ) ;
F_106 (i, tmp, &hwsim_radios)
F_107 ( V_84 , & V_243 ) ;
F_108 ( & V_126 ) ;
F_109 (data, tmpdata, &tmplist, list) {
F_110 ( V_22 -> V_246 ) ;
F_110 ( V_22 -> V_247 ) ;
F_110 ( V_22 -> V_248 ) ;
F_111 ( V_22 -> V_19 ) ;
F_112 ( V_22 -> V_16 ) ;
F_113 ( V_22 -> V_19 ) ;
}
F_114 ( V_249 ) ;
}
static void F_115 ( struct V_15 * V_16 )
{
V_16 -> V_250 = & V_251 ;
V_16 -> V_252 = V_253 ;
F_116 ( V_16 ) ;
V_16 -> V_254 = 0 ;
V_16 -> type = V_255 ;
memset ( V_16 -> V_256 , 0 , V_67 ) ;
V_16 -> V_256 [ 0 ] = 0x12 ;
}
static void F_117 ( void * V_257 , T_3 * V_76 , struct V_1 * V_2 )
{
struct V_21 * V_22 = V_257 ;
struct V_3 * V_4 = ( void * ) V_2 -> V_5 ;
struct V_13 * V_14 ;
struct V_258 * V_259 ;
int V_131 ;
if ( ! V_4 -> V_170 )
return;
F_29 ( V_22 -> V_19 -> V_74 ,
L_30 ,
V_115 , V_4 -> V_168 , V_4 -> V_171 ) ;
V_14 = F_22 ( sizeof( * V_259 ) ) ;
if ( ! V_14 )
return;
V_259 = ( void * ) F_23 ( V_14 , sizeof( * V_259 ) ) ;
V_259 -> V_62 = F_16 ( V_63 |
V_260 |
V_89 ) ;
V_259 -> V_171 = F_16 ( 0xc000 | V_4 -> V_171 ) ;
memcpy ( V_259 -> V_168 , V_4 -> V_168 , V_67 ) ;
memcpy ( V_259 -> V_261 , V_76 , V_67 ) ;
V_131 = V_132 ;
if ( V_131 )
return F_28 ( V_22 -> V_19 , V_14 , V_131 ) ;
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
int V_131 ;
if ( ! V_4 -> V_170 )
return;
F_29 ( V_22 -> V_19 -> V_74 ,
L_32 ,
V_115 , V_4 -> V_168 , V_68 ) ;
V_14 = F_22 ( sizeof( * V_25 ) ) ;
if ( ! V_14 )
return;
V_25 = ( void * ) F_23 ( V_14 , sizeof( * V_25 ) - V_67 ) ;
V_25 -> V_62 = F_16 ( V_262 |
V_263 |
( V_68 ? V_89 : 0 ) ) ;
V_25 -> V_65 = F_16 ( 0 ) ;
memcpy ( V_25 -> V_66 , V_4 -> V_168 , V_67 ) ;
memcpy ( V_25 -> V_133 , V_76 , V_67 ) ;
memcpy ( V_25 -> V_264 , V_4 -> V_168 , V_67 ) ;
V_131 = V_132 ;
if ( V_131 )
return F_28 ( V_22 -> V_19 , V_14 , V_131 ) ;
if ( ! F_41 ( V_22 -> V_19 , V_14 ) )
F_34 ( V_97 L_33 , V_115 ) ;
F_9 ( V_14 ) ;
}
static void F_119 ( void * V_257 , T_3 * V_76 ,
struct V_1 * V_2 )
{
struct V_21 * V_22 = V_257 ;
F_118 ( V_22 , V_76 , V_2 , 1 ) ;
}
static void F_120 ( void * V_257 , T_3 * V_76 ,
struct V_1 * V_2 )
{
struct V_21 * V_22 = V_257 ;
F_118 ( V_22 , V_76 , V_2 , 0 ) ;
}
static int F_121 ( void * V_257 , T_5 * V_265 )
{
struct V_21 * V_22 = V_257 ;
* V_265 = V_22 -> V_68 ;
return 0 ;
}
static int F_81 ( void * V_257 , T_5 V_265 )
{
struct V_21 * V_22 = V_257 ;
enum V_266 V_267 ;
if ( V_265 != V_69 && V_265 != V_70 && V_265 != V_71 &&
V_265 != V_72 )
return - V_209 ;
V_267 = V_22 -> V_68 ;
V_22 -> V_68 = V_265 ;
if ( V_265 == V_72 ) {
F_122 ( V_22 -> V_19 ,
F_117 , V_22 ) ;
V_22 -> V_73 = true ;
} else if ( V_267 == V_69 && V_265 != V_69 ) {
F_122 ( V_22 -> V_19 ,
F_119 ,
V_22 ) ;
} else if ( V_267 != V_69 && V_265 == V_69 ) {
F_122 ( V_22 -> V_19 ,
F_120 ,
V_22 ) ;
}
return 0 ;
}
static int F_123 ( void * V_257 , T_5 * V_265 )
{
struct V_21 * V_22 = V_257 ;
* V_265 = V_22 -> V_129 ;
return 0 ;
}
static int F_124 ( void * V_257 , T_5 V_265 )
{
struct V_21 * V_22 = V_257 ;
V_22 -> V_129 = V_265 ;
return 0 ;
}
struct V_21 * F_125 (
struct V_99 * V_59 )
{
struct V_21 * V_22 ;
bool V_268 = false ;
F_105 ( & V_126 ) ;
F_47 (data, &hwsim_radios, list) {
if ( memcmp ( V_22 -> V_100 [ 1 ] . V_59 , V_59 ,
sizeof( struct V_99 ) ) == 0 ) {
V_268 = true ;
break;
}
}
F_108 ( & V_126 ) ;
if ( ! V_268 )
return NULL ;
return V_22 ;
}
static int F_126 ( struct V_13 * V_269 ,
struct V_270 * V_28 )
{
struct V_60 * V_25 ;
struct V_21 * V_116 ;
struct V_27 * V_130 ;
struct V_85 * V_86 ;
struct V_13 T_6 * V_271 ;
struct V_13 * V_14 , * V_244 ;
struct V_99 * V_272 ;
unsigned int V_83 ;
int V_84 ;
bool V_273 = false ;
if ( ! V_28 -> V_274 [ V_98 ] ||
! V_28 -> V_274 [ V_107 ] ||
! V_28 -> V_274 [ V_113 ] ||
! V_28 -> V_274 [ V_112 ] )
goto V_241;
V_272 = (struct V_99 * ) F_127 (
V_28 -> V_274 [ V_98 ] ) ;
V_83 = F_80 ( V_28 -> V_274 [ V_107 ] ) ;
V_271 = (struct V_13 T_6 * )
( unsigned long ) F_128 ( V_28 -> V_274 [ V_113 ] ) ;
V_116 = F_125 ( V_272 ) ;
if ( V_116 == NULL )
goto V_241;
F_129 (&data2->pending, skb, tmp) {
if ( V_14 == V_271 ) {
F_130 ( V_14 , & V_116 -> V_90 ) ;
V_273 = true ;
break;
}
}
if ( ! V_273 )
goto V_241;
V_86 = (struct V_85 * ) F_127 (
V_28 -> V_274 [ V_112 ] ) ;
V_130 = F_11 ( V_14 ) ;
if ( V_130 -> V_123 . V_2 )
F_1 ( V_130 -> V_123 . V_2 ) ;
if ( V_130 -> V_123 . V_9 )
F_5 ( V_130 -> V_123 . V_9 ) ;
F_53 ( V_130 ) ;
for ( V_84 = 0 ; V_84 < V_87 ; V_84 ++ ) {
V_130 -> V_109 . V_110 [ V_84 ] . V_108 = V_86 [ V_84 ] . V_108 ;
V_130 -> V_109 . V_110 [ V_84 ] . V_111 = V_86 [ V_84 ] . V_111 ;
}
V_130 -> V_109 . V_275 = F_80 ( V_28 -> V_274 [ V_276 ] ) ;
if ( ! ( V_83 & V_106 ) &&
( V_83 & V_277 ) ) {
if ( V_14 -> V_102 >= 16 ) {
V_25 = (struct V_60 * ) V_14 -> V_22 ;
F_21 ( V_116 -> V_19 , V_25 -> V_133 ) ;
}
}
F_54 ( V_116 -> V_19 , V_14 ) ;
return 0 ;
V_241:
return - V_209 ;
}
static int F_131 ( struct V_13 * V_269 ,
struct V_270 * V_28 )
{
struct V_21 * V_116 ;
struct V_118 V_119 ;
struct V_99 * V_278 ;
int V_279 ;
char * V_280 ;
struct V_13 * V_14 = NULL ;
if ( ! V_28 -> V_274 [ V_281 ] ||
! V_28 -> V_274 [ V_101 ] ||
! V_28 -> V_274 [ V_282 ] ||
! V_28 -> V_274 [ V_276 ] )
goto V_241;
V_278 = (struct V_99 * ) F_127 (
V_28 -> V_274 [ V_281 ] ) ;
V_279 = F_132 ( V_28 -> V_274 [ V_101 ] ) ;
V_280 = ( char * ) F_127 ( V_28 -> V_274 [ V_101 ] ) ;
V_14 = F_133 ( V_279 , V_233 ) ;
if ( V_14 == NULL )
goto V_206;
if ( V_279 <= V_283 ) {
memcpy ( F_23 ( V_14 , V_279 ) , V_280 ,
V_279 ) ;
} else
goto V_206;
V_116 = F_125 ( V_278 ) ;
if ( V_116 == NULL )
goto V_241;
if ( V_116 -> V_88 || ! V_116 -> V_128 || ! V_116 -> V_45 )
goto V_241;
memset ( & V_119 , 0 , sizeof( V_119 ) ) ;
V_119 . V_120 = V_116 -> V_45 -> V_46 ;
V_119 . V_121 = V_116 -> V_45 -> V_121 ;
V_119 . V_122 = F_80 ( V_28 -> V_274 [ V_282 ] ) ;
V_119 . signal = F_80 ( V_28 -> V_274 [ V_276 ] ) ;
memcpy ( F_49 ( V_14 ) , & V_119 , sizeof( V_119 ) ) ;
F_50 ( V_116 -> V_19 , V_14 ) ;
return 0 ;
V_206:
F_34 ( V_97 L_3 , V_115 ) ;
goto V_241;
V_241:
F_9 ( V_14 ) ;
return - V_209 ;
}
static int F_134 ( struct V_13 * V_269 ,
struct V_270 * V_28 )
{
if ( V_28 == NULL )
goto V_241;
V_132 = V_28 -> V_284 ;
F_34 ( V_97 L_34
L_35 , V_28 -> V_284 ) ;
return 0 ;
V_241:
F_34 ( V_97 L_3 , V_115 ) ;
return - V_209 ;
}
static int F_135 ( struct V_285 * V_286 ,
unsigned long V_287 ,
void * V_288 )
{
struct V_289 * V_290 = V_288 ;
if ( V_287 != V_291 )
return V_292 ;
if ( V_290 -> V_293 == V_132 ) {
F_34 ( V_294 L_36
L_37 ) ;
V_132 = 0 ;
}
return V_292 ;
}
static int F_136 ( void )
{
int V_295 ;
F_34 ( V_294 L_38 ) ;
V_132 = 0 ;
V_295 = F_137 ( & V_95 ,
V_296 , F_138 ( V_296 ) ) ;
if ( V_295 )
goto V_297;
V_295 = F_139 ( & V_298 ) ;
if ( V_295 )
goto V_297;
return 0 ;
V_297:
F_34 ( V_97 L_3 , V_115 ) ;
return - V_209 ;
}
static void F_140 ( void )
{
int V_79 ;
F_34 ( V_294 L_39 ) ;
F_141 ( & V_298 ) ;
V_79 = F_142 ( & V_95 ) ;
if ( V_79 )
F_34 ( V_97 L_40
L_41 , V_79 ) ;
}
static int T_7 F_143 ( void )
{
int V_84 , V_206 = 0 ;
T_3 V_59 [ V_67 ] ;
struct V_21 * V_22 ;
struct V_18 * V_19 ;
enum V_299 V_121 ;
if ( V_300 < 1 || V_300 > 100 )
return - V_209 ;
if ( V_301 ) {
V_302 . V_303 = F_94 ;
V_302 . V_304 = NULL ;
V_302 . V_305 = NULL ;
}
F_144 ( & V_126 ) ;
F_104 ( & V_306 ) ;
V_249 = F_145 ( V_307 , L_42 ) ;
if ( F_146 ( V_249 ) )
return F_147 ( V_249 ) ;
memset ( V_59 , 0 , V_67 ) ;
V_59 [ 0 ] = 0x02 ;
for ( V_84 = 0 ; V_84 < V_300 ; V_84 ++ ) {
F_34 ( V_97 L_43 ,
V_84 ) ;
V_19 = F_148 ( sizeof( * V_22 ) , & V_302 ) ;
if ( ! V_19 ) {
F_34 ( V_97 L_44
L_45 ) ;
V_206 = - V_213 ;
goto V_308;
}
V_22 = V_19 -> V_23 ;
V_22 -> V_19 = V_19 ;
V_22 -> V_16 = F_149 ( V_249 , NULL , 0 , V_19 ,
L_46 , V_84 ) ;
if ( F_146 ( V_22 -> V_16 ) ) {
F_34 ( V_97
L_47
L_48 , F_147 ( V_22 -> V_16 ) ) ;
V_206 = - V_213 ;
goto V_309;
}
V_22 -> V_16 -> V_310 = & V_311 ;
F_150 ( & V_22 -> V_90 ) ;
F_151 ( V_19 , V_22 -> V_16 ) ;
V_59 [ 3 ] = V_84 >> 8 ;
V_59 [ 4 ] = V_84 ;
memcpy ( V_22 -> V_100 [ 0 ] . V_59 , V_59 , V_67 ) ;
memcpy ( V_22 -> V_100 [ 1 ] . V_59 , V_59 , V_67 ) ;
V_22 -> V_100 [ 1 ] . V_59 [ 0 ] |= 0x40 ;
V_19 -> V_74 -> V_312 = 2 ;
V_19 -> V_74 -> V_100 = V_22 -> V_100 ;
if ( V_301 ) {
V_19 -> V_74 -> V_313 = 255 ;
V_19 -> V_74 -> V_314 = V_283 ;
}
V_19 -> V_315 = 1 ;
V_19 -> V_316 = 4 ;
V_19 -> V_74 -> V_317 =
F_152 ( V_318 ) |
F_152 ( V_140 ) |
F_152 ( V_319 ) |
F_152 ( V_320 ) |
F_152 ( V_142 ) |
F_152 ( V_141 ) ;
V_19 -> V_26 = V_321 |
V_322 |
V_323 |
V_324 |
V_325 ;
V_19 -> V_326 = sizeof( struct V_3 ) ;
V_19 -> V_327 = sizeof( struct V_10 ) ;
memcpy ( V_22 -> V_328 , V_329 ,
sizeof( V_329 ) ) ;
memcpy ( V_22 -> V_330 , V_331 ,
sizeof( V_331 ) ) ;
memcpy ( V_22 -> V_110 , V_332 , sizeof( V_332 ) ) ;
for ( V_121 = V_333 ; V_121 < V_334 ; V_121 ++ ) {
struct V_335 * V_336 = & V_22 -> V_337 [ V_121 ] ;
switch ( V_121 ) {
case V_333 :
V_336 -> V_235 = V_22 -> V_328 ;
V_336 -> V_234 =
F_138 ( V_329 ) ;
V_336 -> V_338 = V_22 -> V_110 ;
V_336 -> V_339 = F_138 ( V_332 ) ;
break;
case V_340 :
V_336 -> V_235 = V_22 -> V_330 ;
V_336 -> V_234 =
F_138 ( V_331 ) ;
V_336 -> V_338 = V_22 -> V_110 + 4 ;
V_336 -> V_339 = F_138 ( V_332 ) - 4 ;
break;
default:
break;
}
V_336 -> V_341 . V_342 = true ;
V_336 -> V_341 . V_343 = V_344 |
V_345 |
V_346 |
V_347 ;
V_336 -> V_341 . V_348 = 0x3 ;
V_336 -> V_341 . V_349 = 0x6 ;
memset ( & V_336 -> V_341 . V_350 , 0 ,
sizeof( V_336 -> V_341 . V_350 ) ) ;
V_336 -> V_341 . V_350 . V_351 [ 0 ] = 0xff ;
V_336 -> V_341 . V_350 . V_351 [ 1 ] = 0xff ;
V_336 -> V_341 . V_350 . V_352 = V_353 ;
V_19 -> V_74 -> V_337 [ V_121 ] = V_336 ;
}
V_22 -> V_129 = 1 ;
F_153 ( & V_22 -> V_239 ) ;
V_19 -> V_354 = 4 ;
V_19 -> V_355 = 11 ;
switch ( V_356 ) {
case V_357 :
case V_358 :
case V_359 :
case V_360 :
break;
case V_361 :
if ( V_84 == 0 ) {
V_19 -> V_74 -> V_26 |= V_362 ;
F_154 ( V_19 -> V_74 ,
& V_363 ) ;
}
break;
case V_364 :
V_19 -> V_74 -> V_26 |= V_362 ;
F_154 ( V_19 -> V_74 ,
& V_363 ) ;
break;
case V_365 :
if ( V_84 == 0 ) {
V_19 -> V_74 -> V_26 |= V_362 ;
F_154 ( V_19 -> V_74 ,
& V_363 ) ;
} else if ( V_84 == 1 ) {
V_19 -> V_74 -> V_26 |= V_362 ;
F_154 ( V_19 -> V_74 ,
& V_366 ) ;
}
break;
case V_367 :
V_19 -> V_74 -> V_26 |= V_368 ;
break;
case V_369 :
case V_370 :
if ( V_84 == 0 )
V_19 -> V_74 -> V_26 |= V_368 ;
break;
case V_371 :
if ( V_84 == 0 ) {
V_19 -> V_74 -> V_26 |= V_362 ;
F_154 ( V_19 -> V_74 ,
& V_363 ) ;
} else if ( V_84 == 1 ) {
V_19 -> V_74 -> V_26 |= V_362 ;
F_154 ( V_19 -> V_74 ,
& V_366 ) ;
} else if ( V_84 == 4 )
V_19 -> V_74 -> V_26 |= V_368 ;
break;
default:
break;
}
if ( V_356 )
F_155 ( 1 ) ;
V_206 = F_156 ( V_19 ) ;
if ( V_206 < 0 ) {
F_34 ( V_97 L_40
L_49 , V_206 ) ;
goto V_372;
}
switch ( V_356 ) {
case V_361 :
case V_357 :
break;
case V_358 :
if ( ! V_84 )
F_157 ( V_19 -> V_74 , V_373 [ 0 ] ) ;
break;
case V_359 :
case V_367 :
F_157 ( V_19 -> V_74 , V_373 [ 0 ] ) ;
break;
case V_360 :
if ( V_84 < F_138 ( V_373 ) )
F_157 ( V_19 -> V_74 , V_373 [ V_84 ] ) ;
break;
case V_364 :
case V_365 :
break;
case V_369 :
if ( V_84 == 0 )
F_157 ( V_19 -> V_74 , V_373 [ 0 ] ) ;
break;
case V_370 :
if ( V_84 == 0 )
F_157 ( V_19 -> V_74 , V_373 [ 0 ] ) ;
else if ( V_84 == 1 )
F_157 ( V_19 -> V_74 , V_373 [ 1 ] ) ;
break;
case V_371 :
if ( V_84 == 2 )
F_157 ( V_19 -> V_74 , V_373 [ 0 ] ) ;
else if ( V_84 == 3 )
F_157 ( V_19 -> V_74 , V_373 [ 1 ] ) ;
else if ( V_84 == 4 )
F_157 ( V_19 -> V_74 , V_373 [ 2 ] ) ;
break;
default:
break;
}
F_29 ( V_19 -> V_74 , L_50 ,
V_19 -> V_74 -> V_75 ) ;
V_22 -> V_248 = F_158 ( L_51 ,
V_19 -> V_74 -> V_374 ) ;
V_22 -> V_247 = F_159 ( L_52 , 0666 ,
V_22 -> V_248 , V_22 ,
& V_375 ) ;
V_22 -> V_246 = F_159 ( L_53 , 0666 ,
V_22 -> V_248 , V_22 ,
& V_376 ) ;
F_160 ( & V_22 -> V_135 , F_65 ,
( unsigned long ) V_19 ) ;
F_161 ( & V_22 -> V_377 , & V_306 ) ;
}
V_31 = F_162 ( 0 , L_46 , F_115 ) ;
if ( V_31 == NULL )
goto V_308;
F_163 () ;
V_206 = F_164 ( V_31 , V_31 -> V_378 ) ;
if ( V_206 < 0 )
goto V_379;
V_206 = F_165 ( V_31 ) ;
if ( V_206 < 0 )
goto V_379;
F_166 () ;
V_206 = F_136 () ;
if ( V_206 < 0 )
goto V_380;
return 0 ;
V_380:
F_34 ( V_97 L_54 ) ;
return V_206 ;
V_379:
F_166 () ;
V_253 ( V_31 ) ;
F_103 () ;
return V_206 ;
V_372:
F_112 ( V_22 -> V_16 ) ;
V_309:
F_113 ( V_19 ) ;
V_308:
F_103 () ;
return V_206 ;
}
static void T_8 F_167 ( void )
{
F_34 ( V_97 L_55 ) ;
F_140 () ;
F_103 () ;
F_168 ( V_31 ) ;
}
