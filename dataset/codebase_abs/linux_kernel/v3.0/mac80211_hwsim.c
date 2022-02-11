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
static bool F_28 ( struct V_18 * V_19 ,
struct V_13 * V_14 )
{
struct V_21 * V_22 = V_19 -> V_23 , * V_80 ;
bool V_81 = false ;
struct V_60 * V_25 = (struct V_60 * ) V_14 -> V_22 ;
struct V_27 * V_28 = F_11 ( V_14 ) ;
struct V_82 V_83 ;
if ( V_22 -> V_84 ) {
F_29 ( V_19 -> V_74 , L_1 ) ;
return false ;
}
memset ( & V_83 , 0 , sizeof( V_83 ) ) ;
V_83 . V_85 = V_22 -> V_45 -> V_46 ;
V_83 . V_86 = V_22 -> V_45 -> V_86 ;
V_83 . V_87 = V_28 -> V_88 . V_89 [ 0 ] . V_90 ;
V_83 . signal = V_22 -> V_91 - 50 ;
if ( V_22 -> V_68 != V_69 )
V_25 -> V_62 |= F_16 ( V_92 ) ;
F_30 ( V_14 ) ;
F_31 ( V_14 ) ;
V_14 -> V_93 = 0 ;
F_32 ( V_14 ) ;
F_33 ( V_14 ) ;
F_34 ( & V_94 ) ;
F_35 (data2, &hwsim_radios, list) {
struct V_13 * V_95 ;
if ( V_22 == V_80 )
continue;
if ( V_80 -> V_84 || ! V_80 -> V_96 ||
! F_24 ( V_80 , V_14 ) ||
! V_22 -> V_45 || ! V_80 -> V_45 ||
V_22 -> V_45 -> V_46 != V_80 -> V_45 -> V_46 ||
! ( V_22 -> V_97 & V_80 -> V_97 ) )
continue;
V_95 = F_36 ( V_14 , V_32 ) ;
if ( V_95 == NULL )
continue;
if ( F_26 ( V_80 , V_25 -> V_66 ) )
V_81 = true ;
memcpy ( F_37 ( V_95 ) , & V_83 , sizeof( V_83 ) ) ;
F_38 ( V_80 -> V_19 , V_95 ) ;
}
F_39 ( & V_94 ) ;
return V_81 ;
}
static void F_40 ( struct V_18 * V_19 , struct V_13 * V_14 )
{
bool V_81 ;
struct V_27 * V_98 ;
F_10 ( V_19 , V_14 ) ;
if ( V_14 -> V_99 < 10 ) {
F_9 ( V_14 ) ;
return;
}
V_81 = F_28 ( V_19 , V_14 ) ;
if ( V_81 && V_14 -> V_99 >= 16 ) {
struct V_60 * V_25 = (struct V_60 * ) V_14 -> V_22 ;
F_21 ( V_19 , V_25 -> V_100 ) ;
}
V_98 = F_11 ( V_14 ) ;
if ( V_98 -> V_88 . V_2 )
F_1 ( V_98 -> V_88 . V_2 ) ;
if ( V_98 -> V_88 . V_9 )
F_5 ( V_98 -> V_88 . V_9 ) ;
F_41 ( V_98 ) ;
if ( ! ( V_98 -> V_26 & V_101 ) && V_81 )
V_98 -> V_26 |= V_102 ;
F_42 ( V_19 , V_14 ) ;
}
static int F_43 ( struct V_18 * V_19 )
{
struct V_21 * V_22 = V_19 -> V_23 ;
F_29 ( V_19 -> V_74 , L_2 , V_103 ) ;
V_22 -> V_96 = 1 ;
return 0 ;
}
static void F_44 ( struct V_18 * V_19 )
{
struct V_21 * V_22 = V_19 -> V_23 ;
V_22 -> V_96 = 0 ;
F_45 ( & V_22 -> V_104 ) ;
F_29 ( V_19 -> V_74 , L_2 , V_103 ) ;
}
static int F_46 ( struct V_18 * V_19 ,
struct V_1 * V_2 )
{
F_29 ( V_19 -> V_74 , L_3 ,
V_103 , F_47 ( V_2 ) ,
V_2 -> V_59 ) ;
F_3 ( V_2 ) ;
return 0 ;
}
static int F_48 ( struct V_18 * V_19 ,
struct V_1 * V_2 ,
enum V_105 V_106 ,
bool V_107 )
{
V_106 = F_49 ( V_106 , V_107 ) ;
F_29 ( V_19 -> V_74 ,
L_4 ,
V_103 , F_47 ( V_2 ) ,
V_106 , V_2 -> V_59 ) ;
F_1 ( V_2 ) ;
return 0 ;
}
static void F_50 (
struct V_18 * V_19 , struct V_1 * V_2 )
{
F_29 ( V_19 -> V_74 , L_3 ,
V_103 , F_47 ( V_2 ) ,
V_2 -> V_59 ) ;
F_1 ( V_2 ) ;
F_4 ( V_2 ) ;
}
static void F_51 ( void * V_108 , T_3 * V_76 ,
struct V_1 * V_2 )
{
struct V_18 * V_19 = V_108 ;
struct V_13 * V_14 ;
struct V_27 * V_28 ;
F_1 ( V_2 ) ;
if ( V_2 -> type != V_109 &&
V_2 -> type != V_110 &&
V_2 -> type != V_111 )
return;
V_14 = F_52 ( V_19 , V_2 ) ;
if ( V_14 == NULL )
return;
V_28 = F_11 ( V_14 ) ;
F_10 ( V_19 , V_14 ) ;
F_28 ( V_19 , V_14 ) ;
F_9 ( V_14 ) ;
}
static void F_53 ( unsigned long V_108 )
{
struct V_18 * V_19 = (struct V_18 * ) V_108 ;
struct V_21 * V_22 = V_19 -> V_23 ;
if ( ! V_22 -> V_96 )
return;
F_27 (
V_19 , F_51 , V_19 ) ;
V_22 -> V_104 . V_112 = V_113 + V_22 -> V_114 ;
F_54 ( & V_22 -> V_104 ) ;
}
static int F_55 ( struct V_18 * V_19 , T_4 V_115 )
{
struct V_21 * V_22 = V_19 -> V_23 ;
struct V_116 * V_117 = & V_19 -> V_117 ;
static const char * V_118 [ V_119 ] = {
[ V_120 ] = L_5 ,
[ V_121 ] = L_6 ,
[ V_122 ] = L_7 ,
[ V_123 ] = L_8 ,
} ;
F_29 ( V_19 -> V_74 ,
L_9 ,
V_103 ,
V_117 -> V_45 -> V_46 ,
V_124 [ V_117 -> V_125 ] ,
! ! ( V_117 -> V_26 & V_126 ) ,
! ! ( V_117 -> V_26 & V_127 ) ,
V_118 [ V_117 -> V_128 ] ) ;
V_22 -> V_84 = ! ! ( V_117 -> V_26 & V_126 ) ;
V_22 -> V_45 = V_117 -> V_45 ;
V_22 -> V_91 = V_117 -> V_91 ;
if ( ! V_22 -> V_96 || ! V_22 -> V_114 )
F_45 ( & V_22 -> V_104 ) ;
else
F_56 ( & V_22 -> V_104 , V_113 + V_22 -> V_114 ) ;
return 0 ;
}
static void F_57 ( struct V_18 * V_19 ,
unsigned int V_129 ,
unsigned int * V_130 , T_5 V_131 )
{
struct V_21 * V_22 = V_19 -> V_23 ;
F_29 ( V_19 -> V_74 , L_2 , V_103 ) ;
V_22 -> V_132 = 0 ;
if ( * V_130 & V_133 )
V_22 -> V_132 |= V_133 ;
if ( * V_130 & V_134 )
V_22 -> V_132 |= V_134 ;
* V_130 = V_22 -> V_132 ;
}
static void F_58 ( struct V_18 * V_19 ,
struct V_1 * V_2 ,
struct V_135 * V_28 ,
T_4 V_115 )
{
struct V_3 * V_4 = ( void * ) V_2 -> V_5 ;
struct V_21 * V_22 = V_19 -> V_23 ;
F_1 ( V_2 ) ;
F_29 ( V_19 -> V_74 , L_10 , V_103 , V_115 ) ;
if ( V_115 & V_136 ) {
F_29 ( V_19 -> V_74 , L_11 ,
V_103 , V_28 -> V_137 ) ;
memcpy ( V_4 -> V_137 , V_28 -> V_137 , V_67 ) ;
}
if ( V_115 & V_138 ) {
F_29 ( V_19 -> V_74 , L_12 ,
V_28 -> V_139 , V_28 -> V_140 ) ;
V_4 -> V_139 = V_28 -> V_139 ;
V_4 -> V_140 = V_28 -> V_140 ;
}
if ( V_115 & V_141 ) {
F_29 ( V_19 -> V_74 , L_13 , V_28 -> V_114 ) ;
V_22 -> V_114 = 1024 * V_28 -> V_114 / 1000 * V_142 / 1000 ;
if ( F_2 ( ! V_22 -> V_114 ) )
V_22 -> V_114 = 1 ;
if ( V_22 -> V_96 )
F_56 ( & V_22 -> V_104 ,
V_113 + V_22 -> V_114 ) ;
}
if ( V_115 & V_143 ) {
F_29 ( V_19 -> V_74 , L_14 ,
V_28 -> V_144 ) ;
}
if ( V_115 & V_145 ) {
F_29 ( V_19 -> V_74 , L_15 ,
V_28 -> V_146 ) ;
}
if ( V_115 & V_147 ) {
F_29 ( V_19 -> V_74 , L_16 , V_28 -> V_148 ) ;
}
if ( V_115 & V_149 ) {
F_29 ( V_19 -> V_74 , L_17 ,
V_28 -> V_150 ,
V_124 [ V_28 -> V_125 ] ) ;
}
if ( V_115 & V_151 ) {
F_29 ( V_19 -> V_74 , L_18 ,
( unsigned long long ) V_28 -> V_152 ) ;
}
}
static int F_59 ( struct V_18 * V_19 ,
struct V_1 * V_2 ,
struct V_8 * V_9 )
{
F_1 ( V_2 ) ;
F_6 ( V_9 ) ;
return 0 ;
}
static int F_60 ( struct V_18 * V_19 ,
struct V_1 * V_2 ,
struct V_8 * V_9 )
{
F_1 ( V_2 ) ;
F_7 ( V_9 ) ;
return 0 ;
}
static void F_61 ( struct V_18 * V_19 ,
struct V_1 * V_2 ,
enum V_153 V_154 ,
struct V_8 * V_9 )
{
F_1 ( V_2 ) ;
switch ( V_154 ) {
case V_155 :
case V_156 :
break;
default:
F_62 ( 1 , L_19 , V_154 ) ;
break;
}
}
static int F_63 ( struct V_18 * V_19 ,
struct V_8 * V_9 ,
bool V_157 )
{
F_5 ( V_9 ) ;
return 0 ;
}
static int F_64 (
struct V_18 * V_19 , T_2 V_158 ,
const struct V_159 * V_160 )
{
F_29 ( V_19 -> V_74 ,
L_20 ,
V_103 , V_158 ,
V_160 -> V_161 , V_160 -> V_162 ,
V_160 -> V_163 , V_160 -> V_164 ) ;
return 0 ;
}
static int F_65 (
struct V_18 * V_19 , int V_90 ,
struct V_165 * V_166 )
{
struct V_116 * V_117 = & V_19 -> V_117 ;
F_29 ( V_19 -> V_74 , L_21 , V_103 , V_90 ) ;
if ( V_90 != 0 )
return - V_167 ;
V_166 -> V_45 = V_117 -> V_45 ;
V_166 -> V_168 = V_169 ;
V_166 -> V_170 = - 92 ;
return 0 ;
}
static int F_66 ( struct V_18 * V_19 ,
void * V_22 , int V_99 )
{
struct V_21 * V_171 = V_19 -> V_23 ;
struct V_172 * V_173 [ V_174 + 1 ] ;
struct V_13 * V_14 ;
int V_175 , V_68 ;
V_175 = F_67 ( V_173 , V_174 , V_22 , V_99 ,
V_176 ) ;
if ( V_175 )
return V_175 ;
if ( ! V_173 [ V_177 ] )
return - V_178 ;
switch ( F_68 ( V_173 [ V_177 ] ) ) {
case V_179 :
if ( ! V_173 [ V_180 ] )
return - V_178 ;
V_68 = F_68 ( V_173 [ V_180 ] ) ;
return F_69 ( V_171 , V_68 ) ;
case V_181 :
V_14 = F_70 ( V_19 -> V_74 ,
F_71 ( sizeof( T_4 ) ) ) ;
if ( ! V_14 )
return - V_182 ;
F_72 ( V_14 , V_180 , V_171 -> V_68 ) ;
return F_73 ( V_14 ) ;
default:
return - V_183 ;
}
V_184:
F_74 ( V_14 ) ;
return - V_185 ;
}
static int F_75 ( struct V_18 * V_19 ,
struct V_1 * V_2 ,
enum V_186 V_187 ,
struct V_8 * V_9 , T_2 V_188 , T_2 * V_189 ,
T_3 V_190 )
{
switch ( V_187 ) {
case V_191 :
F_76 ( V_2 , V_9 -> V_59 , V_188 ) ;
break;
case V_192 :
F_77 ( V_2 , V_9 -> V_59 , V_188 ) ;
break;
case V_193 :
break;
case V_194 :
case V_195 :
break;
default:
return - V_183 ;
}
return 0 ;
}
static void F_78 ( struct V_18 * V_19 , bool V_196 )
{
}
static void F_79 ( struct V_197 * V_198 )
{
struct F_79 * V_199 =
F_80 ( V_198 , struct F_79 , V_200 . V_198 ) ;
F_81 ( V_199 -> V_19 , false ) ;
F_82 ( V_199 ) ;
}
static int F_83 ( struct V_18 * V_19 ,
struct V_1 * V_2 ,
struct V_201 * V_202 )
{
struct F_79 * V_199 = F_84 ( sizeof( * V_199 ) , V_203 ) ;
int V_204 ;
if ( ! V_199 )
return - V_182 ;
V_199 -> V_19 = V_19 ;
F_85 ( & V_199 -> V_200 , F_79 ) ;
F_86 ( V_205 L_22 ) ;
for ( V_204 = 0 ; V_204 < V_202 -> V_206 ; V_204 ++ )
F_86 ( V_205 L_23 ,
V_202 -> V_207 [ V_204 ] -> V_46 ) ;
F_87 ( V_19 , & V_199 -> V_200 , 2 * V_142 ) ;
return 0 ;
}
static void F_88 ( struct V_18 * V_19 )
{
struct V_21 * V_171 = V_19 -> V_23 ;
F_89 ( & V_171 -> V_208 ) ;
if ( V_171 -> V_209 ) {
F_86 ( V_205 L_24 ) ;
goto V_210;
}
F_86 ( V_205 L_25 ) ;
V_171 -> V_209 = true ;
V_210:
F_90 ( & V_171 -> V_208 ) ;
}
static void F_91 ( struct V_18 * V_19 )
{
struct V_21 * V_171 = V_19 -> V_23 ;
F_89 ( & V_171 -> V_208 ) ;
F_86 ( V_205 L_26 ) ;
V_171 -> V_209 = false ;
F_90 ( & V_171 -> V_208 ) ;
}
static void F_92 ( void )
{
struct V_211 V_212 , * V_204 , * V_213 ;
struct V_21 * V_22 , * V_214 ;
F_93 ( & V_212 ) ;
F_94 ( & V_94 ) ;
F_95 (i, tmp, &hwsim_radios)
F_96 ( V_204 , & V_212 ) ;
F_97 ( & V_94 ) ;
F_98 (data, tmpdata, &tmplist, list) {
F_99 ( V_22 -> V_215 ) ;
F_99 ( V_22 -> V_216 ) ;
F_99 ( V_22 -> V_217 ) ;
F_100 ( V_22 -> V_19 ) ;
F_101 ( V_22 -> V_16 ) ;
F_102 ( V_22 -> V_19 ) ;
}
F_103 ( V_218 ) ;
}
static void F_104 ( struct V_15 * V_16 )
{
V_16 -> V_219 = & V_220 ;
V_16 -> V_221 = V_222 ;
F_105 ( V_16 ) ;
V_16 -> V_223 = 0 ;
V_16 -> type = V_224 ;
memset ( V_16 -> V_225 , 0 , V_67 ) ;
V_16 -> V_225 [ 0 ] = 0x12 ;
}
static void F_106 ( void * V_226 , T_3 * V_76 , struct V_1 * V_2 )
{
struct V_21 * V_22 = V_226 ;
struct V_3 * V_4 = ( void * ) V_2 -> V_5 ;
struct V_13 * V_14 ;
struct V_227 * V_228 ;
if ( ! V_4 -> V_139 )
return;
F_29 ( V_22 -> V_19 -> V_74 ,
L_27 ,
V_103 , V_4 -> V_137 , V_4 -> V_140 ) ;
V_14 = F_22 ( sizeof( * V_228 ) ) ;
if ( ! V_14 )
return;
V_228 = ( void * ) F_23 ( V_14 , sizeof( * V_228 ) ) ;
V_228 -> V_62 = F_16 ( V_63 |
V_229 |
V_92 ) ;
V_228 -> V_140 = F_16 ( 0xc000 | V_4 -> V_140 ) ;
memcpy ( V_228 -> V_137 , V_4 -> V_137 , V_67 ) ;
memcpy ( V_228 -> V_230 , V_76 , V_67 ) ;
if ( ! F_28 ( V_22 -> V_19 , V_14 ) )
F_86 ( V_205 L_28 , V_103 ) ;
F_9 ( V_14 ) ;
}
static void F_107 ( struct V_21 * V_22 , T_3 * V_76 ,
struct V_1 * V_2 , int V_68 )
{
struct V_3 * V_4 = ( void * ) V_2 -> V_5 ;
struct V_13 * V_14 ;
struct V_60 * V_25 ;
if ( ! V_4 -> V_139 )
return;
F_29 ( V_22 -> V_19 -> V_74 ,
L_29 ,
V_103 , V_4 -> V_137 , V_68 ) ;
V_14 = F_22 ( sizeof( * V_25 ) ) ;
if ( ! V_14 )
return;
V_25 = ( void * ) F_23 ( V_14 , sizeof( * V_25 ) - V_67 ) ;
V_25 -> V_62 = F_16 ( V_231 |
V_232 |
( V_68 ? V_92 : 0 ) ) ;
V_25 -> V_65 = F_16 ( 0 ) ;
memcpy ( V_25 -> V_66 , V_4 -> V_137 , V_67 ) ;
memcpy ( V_25 -> V_100 , V_76 , V_67 ) ;
memcpy ( V_25 -> V_233 , V_4 -> V_137 , V_67 ) ;
if ( ! F_28 ( V_22 -> V_19 , V_14 ) )
F_86 ( V_205 L_30 , V_103 ) ;
F_9 ( V_14 ) ;
}
static void F_108 ( void * V_226 , T_3 * V_76 ,
struct V_1 * V_2 )
{
struct V_21 * V_22 = V_226 ;
F_107 ( V_22 , V_76 , V_2 , 1 ) ;
}
static void F_109 ( void * V_226 , T_3 * V_76 ,
struct V_1 * V_2 )
{
struct V_21 * V_22 = V_226 ;
F_107 ( V_22 , V_76 , V_2 , 0 ) ;
}
static int F_110 ( void * V_226 , T_5 * V_234 )
{
struct V_21 * V_22 = V_226 ;
* V_234 = V_22 -> V_68 ;
return 0 ;
}
static int F_69 ( void * V_226 , T_5 V_234 )
{
struct V_21 * V_22 = V_226 ;
enum V_235 V_236 ;
if ( V_234 != V_69 && V_234 != V_70 && V_234 != V_71 &&
V_234 != V_72 )
return - V_178 ;
V_236 = V_22 -> V_68 ;
V_22 -> V_68 = V_234 ;
if ( V_234 == V_72 ) {
F_111 ( V_22 -> V_19 ,
F_106 , V_22 ) ;
V_22 -> V_73 = true ;
} else if ( V_236 == V_69 && V_234 != V_69 ) {
F_111 ( V_22 -> V_19 ,
F_108 ,
V_22 ) ;
} else if ( V_236 != V_69 && V_234 == V_69 ) {
F_111 ( V_22 -> V_19 ,
F_109 ,
V_22 ) ;
}
return 0 ;
}
static int F_112 ( void * V_226 , T_5 * V_234 )
{
struct V_21 * V_22 = V_226 ;
* V_234 = V_22 -> V_97 ;
return 0 ;
}
static int F_113 ( void * V_226 , T_5 V_234 )
{
struct V_21 * V_22 = V_226 ;
V_22 -> V_97 = V_234 ;
return 0 ;
}
static int T_6 F_114 ( void )
{
int V_204 , V_175 = 0 ;
T_3 V_59 [ V_67 ] ;
struct V_21 * V_22 ;
struct V_18 * V_19 ;
enum V_237 V_86 ;
if ( V_238 < 1 || V_238 > 100 )
return - V_178 ;
if ( V_239 ) {
V_240 . V_241 = F_83 ;
V_240 . V_242 = NULL ;
V_240 . V_243 = NULL ;
}
F_115 ( & V_94 ) ;
F_93 ( & V_244 ) ;
V_218 = F_116 ( V_245 , L_31 ) ;
if ( F_117 ( V_218 ) )
return F_118 ( V_218 ) ;
memset ( V_59 , 0 , V_67 ) ;
V_59 [ 0 ] = 0x02 ;
for ( V_204 = 0 ; V_204 < V_238 ; V_204 ++ ) {
F_86 ( V_205 L_32 ,
V_204 ) ;
V_19 = F_119 ( sizeof( * V_22 ) , & V_240 ) ;
if ( ! V_19 ) {
F_86 ( V_205 L_33
L_34 ) ;
V_175 = - V_182 ;
goto V_246;
}
V_22 = V_19 -> V_23 ;
V_22 -> V_19 = V_19 ;
V_22 -> V_16 = F_120 ( V_218 , NULL , 0 , V_19 ,
L_35 , V_204 ) ;
if ( F_117 ( V_22 -> V_16 ) ) {
F_86 ( V_205
L_36
L_37 , F_118 ( V_22 -> V_16 ) ) ;
V_175 = - V_182 ;
goto V_247;
}
V_22 -> V_16 -> V_248 = & V_249 ;
F_121 ( V_19 , V_22 -> V_16 ) ;
V_59 [ 3 ] = V_204 >> 8 ;
V_59 [ 4 ] = V_204 ;
memcpy ( V_22 -> V_250 [ 0 ] . V_59 , V_59 , V_67 ) ;
memcpy ( V_22 -> V_250 [ 1 ] . V_59 , V_59 , V_67 ) ;
V_22 -> V_250 [ 1 ] . V_59 [ 0 ] |= 0x40 ;
V_19 -> V_74 -> V_251 = 2 ;
V_19 -> V_74 -> V_250 = V_22 -> V_250 ;
if ( V_239 ) {
V_19 -> V_74 -> V_252 = 255 ;
V_19 -> V_74 -> V_253 = V_254 ;
}
V_19 -> V_255 = 1 ;
V_19 -> V_256 = 4 ;
V_19 -> V_74 -> V_257 =
F_122 ( V_258 ) |
F_122 ( V_109 ) |
F_122 ( V_259 ) |
F_122 ( V_260 ) |
F_122 ( V_111 ) |
F_122 ( V_110 ) ;
V_19 -> V_26 = V_261 |
V_262 |
V_263 |
V_264 |
V_265 ;
V_19 -> V_266 = sizeof( struct V_3 ) ;
V_19 -> V_267 = sizeof( struct V_10 ) ;
memcpy ( V_22 -> V_268 , V_269 ,
sizeof( V_269 ) ) ;
memcpy ( V_22 -> V_270 , V_271 ,
sizeof( V_271 ) ) ;
memcpy ( V_22 -> V_89 , V_272 , sizeof( V_272 ) ) ;
for ( V_86 = V_273 ; V_86 < V_274 ; V_86 ++ ) {
struct V_275 * V_276 = & V_22 -> V_277 [ V_86 ] ;
switch ( V_86 ) {
case V_273 :
V_276 -> V_207 = V_22 -> V_268 ;
V_276 -> V_206 =
F_123 ( V_269 ) ;
V_276 -> V_278 = V_22 -> V_89 ;
V_276 -> V_279 = F_123 ( V_272 ) ;
break;
case V_280 :
V_276 -> V_207 = V_22 -> V_270 ;
V_276 -> V_206 =
F_123 ( V_271 ) ;
V_276 -> V_278 = V_22 -> V_89 + 4 ;
V_276 -> V_279 = F_123 ( V_272 ) - 4 ;
break;
default:
break;
}
V_276 -> V_281 . V_282 = true ;
V_276 -> V_281 . V_283 = V_284 |
V_285 |
V_286 |
V_287 ;
V_276 -> V_281 . V_288 = 0x3 ;
V_276 -> V_281 . V_289 = 0x6 ;
memset ( & V_276 -> V_281 . V_290 , 0 ,
sizeof( V_276 -> V_281 . V_290 ) ) ;
V_276 -> V_281 . V_290 . V_291 [ 0 ] = 0xff ;
V_276 -> V_281 . V_290 . V_291 [ 1 ] = 0xff ;
V_276 -> V_281 . V_290 . V_292 = V_293 ;
V_19 -> V_74 -> V_277 [ V_86 ] = V_276 ;
}
V_22 -> V_97 = 1 ;
F_124 ( & V_22 -> V_208 ) ;
switch ( V_294 ) {
case V_295 :
case V_296 :
case V_297 :
case V_298 :
break;
case V_299 :
if ( V_204 == 0 ) {
V_19 -> V_74 -> V_26 |= V_300 ;
F_125 ( V_19 -> V_74 ,
& V_301 ) ;
}
break;
case V_302 :
V_19 -> V_74 -> V_26 |= V_300 ;
F_125 ( V_19 -> V_74 ,
& V_301 ) ;
break;
case V_303 :
if ( V_204 == 0 ) {
V_19 -> V_74 -> V_26 |= V_300 ;
F_125 ( V_19 -> V_74 ,
& V_301 ) ;
} else if ( V_204 == 1 ) {
V_19 -> V_74 -> V_26 |= V_300 ;
F_125 ( V_19 -> V_74 ,
& V_304 ) ;
}
break;
case V_305 :
V_19 -> V_74 -> V_26 |= V_306 ;
break;
case V_307 :
case V_308 :
if ( V_204 == 0 )
V_19 -> V_74 -> V_26 |= V_306 ;
break;
case V_309 :
if ( V_204 == 0 ) {
V_19 -> V_74 -> V_26 |= V_300 ;
F_125 ( V_19 -> V_74 ,
& V_301 ) ;
} else if ( V_204 == 1 ) {
V_19 -> V_74 -> V_26 |= V_300 ;
F_125 ( V_19 -> V_74 ,
& V_304 ) ;
} else if ( V_204 == 4 )
V_19 -> V_74 -> V_26 |= V_306 ;
break;
default:
break;
}
if ( V_294 )
F_126 ( 1 ) ;
V_175 = F_127 ( V_19 ) ;
if ( V_175 < 0 ) {
F_86 ( V_205 L_38
L_39 , V_175 ) ;
goto V_310;
}
switch ( V_294 ) {
case V_299 :
case V_295 :
break;
case V_296 :
if ( ! V_204 )
F_128 ( V_19 -> V_74 , V_311 [ 0 ] ) ;
break;
case V_297 :
case V_305 :
F_128 ( V_19 -> V_74 , V_311 [ 0 ] ) ;
break;
case V_298 :
if ( V_204 < F_123 ( V_311 ) )
F_128 ( V_19 -> V_74 , V_311 [ V_204 ] ) ;
break;
case V_302 :
case V_303 :
break;
case V_307 :
if ( V_204 == 0 )
F_128 ( V_19 -> V_74 , V_311 [ 0 ] ) ;
break;
case V_308 :
if ( V_204 == 0 )
F_128 ( V_19 -> V_74 , V_311 [ 0 ] ) ;
else if ( V_204 == 1 )
F_128 ( V_19 -> V_74 , V_311 [ 1 ] ) ;
break;
case V_309 :
if ( V_204 == 2 )
F_128 ( V_19 -> V_74 , V_311 [ 0 ] ) ;
else if ( V_204 == 3 )
F_128 ( V_19 -> V_74 , V_311 [ 1 ] ) ;
else if ( V_204 == 4 )
F_128 ( V_19 -> V_74 , V_311 [ 2 ] ) ;
break;
default:
break;
}
F_29 ( V_19 -> V_74 , L_40 ,
V_19 -> V_74 -> V_75 ) ;
V_22 -> V_217 = F_129 ( L_41 ,
V_19 -> V_74 -> V_312 ) ;
V_22 -> V_216 = F_130 ( L_42 , 0666 ,
V_22 -> V_217 , V_22 ,
& V_313 ) ;
V_22 -> V_215 = F_130 ( L_43 , 0666 ,
V_22 -> V_217 , V_22 ,
& V_314 ) ;
F_131 ( & V_22 -> V_104 , F_53 ,
( unsigned long ) V_19 ) ;
F_132 ( & V_22 -> V_315 , & V_244 ) ;
}
V_31 = F_133 ( 0 , L_35 , F_104 ) ;
if ( V_31 == NULL )
goto V_246;
V_175 = F_134 ( V_31 ) ;
if ( V_175 < 0 )
goto V_316;
return 0 ;
V_316:
F_135 () ;
V_222 ( V_31 ) ;
F_92 () ;
return V_175 ;
V_310:
F_101 ( V_22 -> V_16 ) ;
V_247:
F_102 ( V_19 ) ;
V_246:
F_92 () ;
return V_175 ;
}
static void T_7 F_136 ( void )
{
F_86 ( V_205 L_44 ) ;
F_92 () ;
F_137 ( V_31 ) ;
}
