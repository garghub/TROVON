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
static T_2 F_10 ( struct V_18 * V_19 )
{
struct V_20 V_21 = F_11 ( F_12 () ) ;
T_3 V_22 = V_21 . V_23 * V_24 + V_21 . V_25 ;
return F_13 ( V_22 + V_19 -> V_26 ) ;
}
static T_3 F_14 ( struct V_27 * V_28 ,
struct V_1 * V_2 )
{
struct V_18 * V_19 = V_28 -> V_29 ;
return F_15 ( F_10 ( V_19 ) ) ;
}
static void F_16 ( struct V_27 * V_28 ,
struct V_1 * V_2 , T_3 V_30 )
{
struct V_18 * V_19 = V_28 -> V_29 ;
struct V_20 V_21 = F_11 ( F_12 () ) ;
T_3 V_22 = V_21 . V_23 * V_24 + V_21 . V_25 ;
V_19 -> V_26 = V_30 - V_22 ;
}
static void F_17 ( struct V_27 * V_28 ,
struct V_13 * V_31 )
{
struct V_18 * V_19 = V_28 -> V_29 ;
struct V_13 * V_14 ;
struct V_32 * V_33 ;
T_4 V_34 ;
struct V_35 * V_36 = F_18 ( V_31 ) ;
struct V_37 * V_38 = F_19 ( V_28 , V_36 ) ;
if ( ! F_20 ( V_39 ) )
return;
V_14 = F_21 ( V_31 , sizeof( * V_33 ) , 0 , V_40 ) ;
if ( V_14 == NULL )
return;
V_33 = (struct V_32 * ) F_22 ( V_14 , sizeof( * V_33 ) ) ;
V_33 -> V_33 . V_41 = V_42 ;
V_33 -> V_33 . V_43 = 0 ;
V_33 -> V_33 . V_44 = F_23 ( sizeof( * V_33 ) ) ;
V_33 -> V_33 . V_45 = F_24 ( ( 1 << V_46 ) |
( 1 << V_47 ) |
( 1 << V_48 ) |
( 1 << V_49 ) ) ;
V_33 -> V_50 = F_10 ( V_19 ) ;
V_33 -> V_51 = 0 ;
V_33 -> V_52 = V_38 -> V_53 / 5 ;
V_33 -> V_54 = F_23 ( V_19 -> V_55 -> V_56 ) ;
V_34 = V_57 ;
if ( V_38 -> V_34 & V_58 )
V_34 |= V_59 ;
else
V_34 |= V_60 ;
V_33 -> V_61 = F_23 ( V_34 ) ;
V_14 -> V_16 = V_39 ;
F_25 ( V_14 , 0 ) ;
V_14 -> V_62 = V_63 ;
V_14 -> V_64 = V_65 ;
V_14 -> V_66 = F_26 ( V_67 ) ;
memset ( V_14 -> V_68 , 0 , sizeof( V_14 -> V_68 ) ) ;
F_27 ( V_14 ) ;
}
static void F_28 ( struct V_27 * V_28 , const T_5 * V_69 )
{
struct V_18 * V_19 = V_28 -> V_29 ;
struct V_13 * V_14 ;
struct V_32 * V_33 ;
T_4 V_34 ;
struct V_70 * V_71 ;
if ( ! F_20 ( V_39 ) )
return;
V_14 = F_29 ( 100 ) ;
if ( V_14 == NULL )
return;
V_33 = (struct V_32 * ) F_30 ( V_14 , sizeof( * V_33 ) ) ;
V_33 -> V_33 . V_41 = V_42 ;
V_33 -> V_33 . V_43 = 0 ;
V_33 -> V_33 . V_44 = F_23 ( sizeof( * V_33 ) ) ;
V_33 -> V_33 . V_45 = F_24 ( ( 1 << V_46 ) |
( 1 << V_49 ) ) ;
V_33 -> V_51 = 0 ;
V_33 -> V_52 = 0 ;
V_33 -> V_54 = F_23 ( V_19 -> V_55 -> V_56 ) ;
V_34 = V_57 ;
V_33 -> V_61 = F_23 ( V_34 ) ;
V_71 = (struct V_70 * ) F_30 ( V_14 , 10 ) ;
V_71 -> V_72 = F_23 ( V_73 |
V_74 ) ;
V_71 -> V_75 = F_23 ( 0 ) ;
memcpy ( V_71 -> V_76 , V_69 , V_77 ) ;
V_14 -> V_16 = V_39 ;
F_25 ( V_14 , 0 ) ;
V_14 -> V_62 = V_63 ;
V_14 -> V_64 = V_65 ;
V_14 -> V_66 = F_26 ( V_67 ) ;
memset ( V_14 -> V_68 , 0 , sizeof( V_14 -> V_68 ) ) ;
F_27 ( V_14 ) ;
}
static bool F_31 ( struct V_18 * V_19 ,
struct V_13 * V_14 )
{
switch ( V_19 -> V_78 ) {
case V_79 :
return true ;
case V_80 :
return false ;
case V_81 :
return true ;
case V_82 :
if ( V_19 -> V_83 &&
memcmp ( V_19 -> V_28 -> V_84 -> V_85 , V_14 -> V_19 + 4 ,
V_77 ) == 0 ) {
V_19 -> V_83 = false ;
return true ;
}
return false ;
}
return true ;
}
static void F_32 ( void * V_19 , T_5 * V_86 ,
struct V_1 * V_2 )
{
struct V_87 * V_88 = V_19 ;
if ( memcmp ( V_86 , V_88 -> V_69 , V_77 ) == 0 )
V_88 -> V_89 = true ;
}
static bool F_33 ( struct V_18 * V_19 ,
const T_5 * V_69 )
{
struct V_87 V_88 ;
if ( memcmp ( V_69 , V_19 -> V_28 -> V_84 -> V_85 , V_77 ) == 0 )
return true ;
V_88 . V_89 = false ;
V_88 . V_69 = V_69 ;
F_34 ( V_19 -> V_28 ,
F_32 ,
& V_88 ) ;
return V_88 . V_89 ;
}
static void F_35 ( struct V_27 * V_28 ,
struct V_13 * V_90 ,
int V_91 )
{
struct V_13 * V_14 ;
struct V_18 * V_19 = V_28 -> V_29 ;
struct V_70 * V_33 = (struct V_70 * ) V_90 -> V_19 ;
struct V_35 * V_36 = F_18 ( V_90 ) ;
void * V_92 ;
unsigned int V_93 = 0 ;
int V_94 ;
struct V_95 V_96 [ V_97 ] ;
if ( V_19 -> V_98 ) {
F_36 ( V_28 -> V_84 , L_1 ) ;
F_9 ( V_90 ) ;
return;
}
if ( V_19 -> V_78 != V_79 )
V_33 -> V_72 |= F_23 ( V_99 ) ;
if ( F_37 ( & V_19 -> V_100 ) >= V_101 ) {
while ( F_37 ( & V_19 -> V_100 ) >= V_102 )
F_38 ( & V_19 -> V_100 ) ;
}
V_14 = F_39 ( V_103 , V_40 ) ;
if ( V_14 == NULL )
goto V_104;
V_92 = F_40 ( V_14 , 0 , 0 , & V_105 , 0 ,
V_106 ) ;
if ( V_92 == NULL ) {
F_41 ( V_107 L_2 ) ;
goto V_104;
}
F_42 ( V_14 , V_108 ,
sizeof( struct V_109 ) , V_19 -> V_110 [ 1 ] . V_69 ) ;
F_42 ( V_14 , V_111 , V_90 -> V_112 , V_90 -> V_19 ) ;
if ( V_36 -> V_34 & V_113 )
V_93 |= V_114 ;
if ( V_36 -> V_34 & V_115 )
V_93 |= V_116 ;
F_43 ( V_14 , V_117 , V_93 ) ;
for ( V_94 = 0 ; V_94 < V_97 ; V_94 ++ ) {
V_96 [ V_94 ] . V_118 = V_36 -> V_119 . V_120 [ V_94 ] . V_118 ;
V_96 [ V_94 ] . V_121 = V_36 -> V_119 . V_120 [ V_94 ] . V_121 ;
}
F_42 ( V_14 , V_122 ,
sizeof( struct V_95 ) * V_97 ,
V_96 ) ;
F_44 ( V_14 , V_123 , ( unsigned long ) V_90 ) ;
F_45 ( V_14 , V_92 ) ;
F_46 ( & V_124 , V_14 , V_91 ) ;
F_47 ( & V_19 -> V_100 , V_90 ) ;
return;
V_104:
F_41 ( V_107 L_3 , V_125 ) ;
}
static bool F_48 ( struct V_27 * V_28 ,
struct V_13 * V_14 )
{
struct V_18 * V_19 = V_28 -> V_29 , * V_126 ;
bool V_127 = false ;
struct V_70 * V_33 = (struct V_70 * ) V_14 -> V_19 ;
struct V_35 * V_36 = F_18 ( V_14 ) ;
struct V_128 V_129 ;
if ( V_19 -> V_98 ) {
F_36 ( V_28 -> V_84 , L_1 ) ;
return false ;
}
memset ( & V_129 , 0 , sizeof( V_129 ) ) ;
V_129 . V_130 |= V_131 ;
V_129 . V_132 = V_19 -> V_55 -> V_56 ;
V_129 . V_133 = V_19 -> V_55 -> V_133 ;
V_129 . V_134 = V_36 -> V_135 . V_120 [ 0 ] . V_118 ;
if ( V_36 -> V_135 . V_120 [ 0 ] . V_34 & V_136 )
V_129 . V_130 |= V_137 ;
if ( V_36 -> V_135 . V_120 [ 0 ] . V_34 & V_138 )
V_129 . V_130 |= V_139 ;
if ( V_36 -> V_135 . V_120 [ 0 ] . V_34 & V_140 )
V_129 . V_130 |= V_141 ;
V_129 . signal = V_19 -> V_142 - 50 ;
if ( V_19 -> V_78 != V_79 )
V_33 -> V_72 |= F_23 ( V_99 ) ;
F_49 ( V_14 ) ;
F_50 ( V_14 ) ;
V_14 -> V_143 = 0 ;
F_51 ( V_14 ) ;
F_52 ( V_14 ) ;
F_53 ( & V_144 ) ;
F_54 (data2, &hwsim_radios, list) {
struct V_13 * V_145 ;
if ( V_19 == V_126 )
continue;
if ( V_126 -> V_98 || ! V_126 -> V_146 ||
! F_31 ( V_126 , V_14 ) ||
! V_19 -> V_55 || ! V_126 -> V_55 ||
V_19 -> V_55 -> V_56 != V_126 -> V_55 -> V_56 ||
! ( V_19 -> V_147 & V_126 -> V_147 ) )
continue;
V_145 = F_55 ( V_14 , V_40 ) ;
if ( V_145 == NULL )
continue;
if ( F_33 ( V_126 , V_33 -> V_76 ) )
V_127 = true ;
V_129 . V_148 =
F_15 ( F_10 ( V_126 ) ) ;
memcpy ( F_56 ( V_145 ) , & V_129 , sizeof( V_129 ) ) ;
F_57 ( V_126 -> V_28 , V_145 ) ;
}
F_58 ( & V_144 ) ;
return V_127 ;
}
static void F_59 ( struct V_27 * V_28 , struct V_13 * V_14 )
{
bool V_127 ;
struct V_35 * V_149 ;
T_6 V_150 ;
struct V_151 * V_152 = (struct V_151 * ) V_14 -> V_19 ;
struct V_18 * V_19 = V_28 -> V_29 ;
if ( F_60 ( V_152 -> V_72 ) ||
F_61 ( V_152 -> V_72 ) )
V_152 -> V_153 . V_154 . V_155 = F_10 ( V_19 ) ;
F_17 ( V_28 , V_14 ) ;
if ( V_14 -> V_112 < 10 ) {
F_9 ( V_14 ) ;
return;
}
V_150 = F_62 ( V_156 ) ;
if ( V_150 )
return F_35 ( V_28 , V_14 , V_150 ) ;
V_127 = F_48 ( V_28 , V_14 ) ;
if ( V_127 && V_14 -> V_112 >= 16 ) {
struct V_70 * V_33 = (struct V_70 * ) V_14 -> V_19 ;
F_28 ( V_28 , V_33 -> V_157 ) ;
}
V_149 = F_18 ( V_14 ) ;
if ( V_149 -> V_135 . V_2 )
F_1 ( V_149 -> V_135 . V_2 ) ;
if ( V_149 -> V_135 . V_9 )
F_5 ( V_149 -> V_135 . V_9 ) ;
F_63 ( V_149 ) ;
if ( ! ( V_149 -> V_34 & V_115 ) && V_127 )
V_149 -> V_34 |= V_158 ;
F_64 ( V_28 , V_14 ) ;
}
static int F_65 ( struct V_27 * V_28 )
{
struct V_18 * V_19 = V_28 -> V_29 ;
F_36 ( V_28 -> V_84 , L_4 , V_125 ) ;
V_19 -> V_146 = true ;
return 0 ;
}
static void F_66 ( struct V_27 * V_28 )
{
struct V_18 * V_19 = V_28 -> V_29 ;
V_19 -> V_146 = false ;
F_67 ( & V_19 -> V_159 ) ;
F_36 ( V_28 -> V_84 , L_4 , V_125 ) ;
}
static int F_68 ( struct V_27 * V_28 ,
struct V_1 * V_2 )
{
F_36 ( V_28 -> V_84 , L_5 ,
V_125 , F_69 ( V_2 ) ,
V_2 -> V_69 ) ;
F_3 ( V_2 ) ;
return 0 ;
}
static int F_70 ( struct V_27 * V_28 ,
struct V_1 * V_2 ,
enum V_160 V_161 ,
bool V_162 )
{
V_161 = F_71 ( V_161 , V_162 ) ;
F_36 ( V_28 -> V_84 ,
L_6 ,
V_125 , F_69 ( V_2 ) ,
V_161 , V_2 -> V_69 ) ;
F_1 ( V_2 ) ;
return 0 ;
}
static void F_72 (
struct V_27 * V_28 , struct V_1 * V_2 )
{
F_36 ( V_28 -> V_84 , L_5 ,
V_125 , F_69 ( V_2 ) ,
V_2 -> V_69 ) ;
F_1 ( V_2 ) ;
F_4 ( V_2 ) ;
}
static void F_73 ( void * V_163 , T_5 * V_86 ,
struct V_1 * V_2 )
{
struct V_27 * V_28 = V_163 ;
struct V_18 * V_19 = V_28 -> V_29 ;
struct V_13 * V_14 ;
struct V_35 * V_36 ;
T_6 V_150 ;
struct V_151 * V_152 ;
F_1 ( V_2 ) ;
if ( V_2 -> type != V_164 &&
V_2 -> type != V_165 &&
V_2 -> type != V_166 )
return;
V_14 = F_74 ( V_28 , V_2 ) ;
if ( V_14 == NULL )
return;
V_36 = F_18 ( V_14 ) ;
V_152 = (struct V_151 * ) V_14 -> V_19 ;
V_152 -> V_153 . V_154 . V_155 = F_10 ( V_19 ) ;
F_17 ( V_28 , V_14 ) ;
V_150 = F_62 ( V_156 ) ;
if ( V_150 )
return F_35 ( V_28 , V_14 , V_150 ) ;
F_48 ( V_28 , V_14 ) ;
F_9 ( V_14 ) ;
}
static void F_75 ( unsigned long V_163 )
{
struct V_27 * V_28 = (struct V_27 * ) V_163 ;
struct V_18 * V_19 = V_28 -> V_29 ;
if ( ! V_19 -> V_146 )
return;
F_34 (
V_28 , F_73 , V_28 ) ;
V_19 -> V_159 . V_167 = V_168 + V_19 -> V_169 ;
F_76 ( & V_19 -> V_159 ) ;
}
static int F_77 ( struct V_27 * V_28 , T_6 V_170 )
{
struct V_18 * V_19 = V_28 -> V_29 ;
struct V_171 * V_172 = & V_28 -> V_172 ;
static const char * V_173 [ V_174 ] = {
[ V_175 ] = L_7 ,
[ V_176 ] = L_8 ,
[ V_177 ] = L_9 ,
[ V_178 ] = L_10 ,
} ;
F_36 ( V_28 -> V_84 ,
L_11 ,
V_125 ,
V_172 -> V_55 -> V_56 ,
V_179 [ V_172 -> V_180 ] ,
! ! ( V_172 -> V_34 & V_181 ) ,
! ! ( V_172 -> V_34 & V_182 ) ,
V_173 [ V_172 -> V_183 ] ) ;
V_19 -> V_98 = ! ! ( V_172 -> V_34 & V_181 ) ;
V_19 -> V_55 = V_172 -> V_55 ;
V_19 -> V_142 = V_172 -> V_142 ;
if ( ! V_19 -> V_146 || ! V_19 -> V_169 )
F_67 ( & V_19 -> V_159 ) ;
else
F_78 ( & V_19 -> V_159 , V_168 + V_19 -> V_169 ) ;
return 0 ;
}
static void F_79 ( struct V_27 * V_28 ,
unsigned int V_184 ,
unsigned int * V_185 , T_3 V_186 )
{
struct V_18 * V_19 = V_28 -> V_29 ;
F_36 ( V_28 -> V_84 , L_4 , V_125 ) ;
V_19 -> V_187 = 0 ;
if ( * V_185 & V_188 )
V_19 -> V_187 |= V_188 ;
if ( * V_185 & V_189 )
V_19 -> V_187 |= V_189 ;
* V_185 = V_19 -> V_187 ;
}
static void F_80 ( struct V_27 * V_28 ,
struct V_1 * V_2 ,
struct V_190 * V_36 ,
T_6 V_170 )
{
struct V_3 * V_4 = ( void * ) V_2 -> V_5 ;
struct V_18 * V_19 = V_28 -> V_29 ;
F_1 ( V_2 ) ;
F_36 ( V_28 -> V_84 , L_12 , V_125 , V_170 ) ;
if ( V_170 & V_191 ) {
F_36 ( V_28 -> V_84 , L_13 ,
V_125 , V_36 -> V_192 ) ;
memcpy ( V_4 -> V_192 , V_36 -> V_192 , V_77 ) ;
}
if ( V_170 & V_193 ) {
F_36 ( V_28 -> V_84 , L_14 ,
V_36 -> V_194 , V_36 -> V_195 ) ;
V_4 -> V_194 = V_36 -> V_194 ;
V_4 -> V_195 = V_36 -> V_195 ;
}
if ( V_170 & V_196 ) {
F_36 ( V_28 -> V_84 , L_15 , V_36 -> V_169 ) ;
V_19 -> V_169 = 1024 * V_36 -> V_169 / 1000 * V_197 / 1000 ;
if ( F_2 ( ! V_19 -> V_169 ) )
V_19 -> V_169 = 1 ;
if ( V_19 -> V_146 )
F_78 ( & V_19 -> V_159 ,
V_168 + V_19 -> V_169 ) ;
}
if ( V_170 & V_198 ) {
F_36 ( V_28 -> V_84 , L_16 ,
V_36 -> V_199 ) ;
}
if ( V_170 & V_200 ) {
F_36 ( V_28 -> V_84 , L_17 ,
V_36 -> V_201 ) ;
}
if ( V_170 & V_202 ) {
F_36 ( V_28 -> V_84 , L_18 , V_36 -> V_203 ) ;
}
if ( V_170 & V_204 ) {
F_36 ( V_28 -> V_84 , L_19 ,
V_36 -> V_205 ,
V_179 [ V_36 -> V_180 ] ) ;
}
if ( V_170 & V_206 ) {
F_36 ( V_28 -> V_84 , L_20 ,
( unsigned long long ) V_36 -> V_207 ) ;
}
}
static int F_81 ( struct V_27 * V_28 ,
struct V_1 * V_2 ,
struct V_8 * V_9 )
{
F_1 ( V_2 ) ;
F_6 ( V_9 ) ;
return 0 ;
}
static int F_82 ( struct V_27 * V_28 ,
struct V_1 * V_2 ,
struct V_8 * V_9 )
{
F_1 ( V_2 ) ;
F_7 ( V_9 ) ;
return 0 ;
}
static void F_83 ( struct V_27 * V_28 ,
struct V_1 * V_2 ,
enum V_208 V_209 ,
struct V_8 * V_9 )
{
F_1 ( V_2 ) ;
switch ( V_209 ) {
case V_210 :
case V_211 :
break;
default:
F_84 ( 1 , L_21 , V_209 ) ;
break;
}
}
static int F_85 ( struct V_27 * V_28 ,
struct V_8 * V_9 ,
bool V_212 )
{
F_5 ( V_9 ) ;
return 0 ;
}
static int F_86 (
struct V_27 * V_28 ,
struct V_1 * V_2 , T_4 V_213 ,
const struct V_214 * V_215 )
{
F_36 ( V_28 -> V_84 ,
L_22 ,
V_125 , V_213 ,
V_215 -> V_216 , V_215 -> V_217 ,
V_215 -> V_218 , V_215 -> V_219 ) ;
return 0 ;
}
static int F_87 (
struct V_27 * V_28 , int V_118 ,
struct V_220 * V_221 )
{
struct V_171 * V_172 = & V_28 -> V_172 ;
F_36 ( V_28 -> V_84 , L_23 , V_125 , V_118 ) ;
if ( V_118 != 0 )
return - V_222 ;
V_221 -> V_55 = V_172 -> V_55 ;
V_221 -> V_223 = V_224 ;
V_221 -> V_225 = - 92 ;
return 0 ;
}
static int F_88 ( struct V_27 * V_28 ,
void * V_19 , int V_112 )
{
struct V_18 * V_226 = V_28 -> V_29 ;
struct V_227 * V_228 [ V_229 + 1 ] ;
struct V_13 * V_14 ;
int V_230 , V_78 ;
V_230 = F_89 ( V_228 , V_229 , V_19 , V_112 ,
V_231 ) ;
if ( V_230 )
return V_230 ;
if ( ! V_228 [ V_232 ] )
return - V_233 ;
switch ( F_90 ( V_228 [ V_232 ] ) ) {
case V_234 :
if ( ! V_228 [ V_235 ] )
return - V_233 ;
V_78 = F_90 ( V_228 [ V_235 ] ) ;
return F_91 ( V_226 , V_78 ) ;
case V_236 :
V_14 = F_92 ( V_28 -> V_84 ,
F_93 ( sizeof( T_6 ) ) ) ;
if ( ! V_14 )
return - V_237 ;
F_43 ( V_14 , V_235 , V_226 -> V_78 ) ;
return F_94 ( V_14 ) ;
default:
return - V_238 ;
}
V_104:
F_95 ( V_14 ) ;
return - V_239 ;
}
static int F_96 ( struct V_27 * V_28 ,
struct V_1 * V_2 ,
enum V_240 V_241 ,
struct V_8 * V_9 , T_4 V_242 , T_4 * V_243 ,
T_5 V_244 )
{
switch ( V_241 ) {
case V_245 :
F_97 ( V_2 , V_9 -> V_69 , V_242 ) ;
break;
case V_246 :
F_98 ( V_2 , V_9 -> V_69 , V_242 ) ;
break;
case V_247 :
break;
case V_248 :
case V_249 :
break;
default:
return - V_238 ;
}
return 0 ;
}
static void F_99 ( struct V_27 * V_28 , bool V_250 )
{
}
static void F_100 ( struct V_251 * V_252 )
{
struct F_100 * V_253 =
F_101 ( V_252 , struct F_100 , V_254 . V_252 ) ;
F_102 ( V_253 -> V_28 , false ) ;
F_103 ( V_253 ) ;
}
static int F_104 ( struct V_27 * V_28 ,
struct V_1 * V_2 ,
struct V_255 * V_256 )
{
struct F_100 * V_253 = F_105 ( sizeof( * V_253 ) , V_257 ) ;
int V_94 ;
if ( ! V_253 )
return - V_237 ;
V_253 -> V_28 = V_28 ;
F_106 ( & V_253 -> V_254 , F_100 ) ;
F_41 ( V_107 L_24 ) ;
for ( V_94 = 0 ; V_94 < V_256 -> V_258 ; V_94 ++ )
F_41 ( V_107 L_25 ,
V_256 -> V_259 [ V_94 ] -> V_56 ) ;
F_107 ( V_107 , L_26 , V_260 ,
16 , 1 , V_256 -> V_261 , V_256 -> V_262 , 1 ) ;
F_108 ( V_28 , & V_253 -> V_254 , 2 * V_197 ) ;
return 0 ;
}
static void F_109 ( struct V_27 * V_28 )
{
struct V_18 * V_226 = V_28 -> V_29 ;
F_110 ( & V_226 -> V_263 ) ;
if ( V_226 -> V_264 ) {
F_41 ( V_107 L_27 ) ;
goto V_265;
}
F_41 ( V_107 L_28 ) ;
V_226 -> V_264 = true ;
V_265:
F_111 ( & V_226 -> V_263 ) ;
}
static void F_112 ( struct V_27 * V_28 )
{
struct V_18 * V_226 = V_28 -> V_29 ;
F_110 ( & V_226 -> V_263 ) ;
F_41 ( V_107 L_29 ) ;
V_226 -> V_264 = false ;
F_111 ( & V_226 -> V_263 ) ;
}
static void F_113 ( void )
{
struct V_266 V_267 , * V_94 , * V_268 ;
struct V_18 * V_19 , * V_269 ;
F_114 ( & V_267 ) ;
F_115 ( & V_144 ) ;
F_116 (i, tmp, &hwsim_radios)
F_117 ( V_94 , & V_267 ) ;
F_118 ( & V_144 ) ;
F_119 (data, tmpdata, &tmplist, list) {
F_120 ( V_19 -> V_270 ) ;
F_120 ( V_19 -> V_271 ) ;
F_120 ( V_19 -> V_272 ) ;
F_121 ( V_19 -> V_28 ) ;
F_122 ( V_19 -> V_16 ) ;
F_123 ( V_19 -> V_28 ) ;
}
F_124 ( V_273 ) ;
}
static void F_125 ( struct V_15 * V_16 )
{
V_16 -> V_274 = & V_275 ;
V_16 -> V_276 = V_277 ;
F_126 ( V_16 ) ;
V_16 -> V_278 = 0 ;
V_16 -> type = V_279 ;
memset ( V_16 -> V_280 , 0 , V_77 ) ;
V_16 -> V_280 [ 0 ] = 0x12 ;
}
static void F_127 ( void * V_281 , T_5 * V_86 , struct V_1 * V_2 )
{
struct V_18 * V_19 = V_281 ;
struct V_3 * V_4 = ( void * ) V_2 -> V_5 ;
struct V_13 * V_14 ;
struct V_282 * V_283 ;
T_6 V_150 ;
if ( ! V_4 -> V_194 )
return;
F_36 ( V_19 -> V_28 -> V_84 ,
L_30 ,
V_125 , V_4 -> V_192 , V_4 -> V_195 ) ;
V_14 = F_29 ( sizeof( * V_283 ) ) ;
if ( ! V_14 )
return;
V_283 = ( void * ) F_30 ( V_14 , sizeof( * V_283 ) ) ;
V_283 -> V_72 = F_23 ( V_73 |
V_284 |
V_99 ) ;
V_283 -> V_195 = F_23 ( 0xc000 | V_4 -> V_195 ) ;
memcpy ( V_283 -> V_192 , V_4 -> V_192 , V_77 ) ;
memcpy ( V_283 -> V_285 , V_86 , V_77 ) ;
V_150 = F_62 ( V_156 ) ;
if ( V_150 )
return F_35 ( V_19 -> V_28 , V_14 , V_150 ) ;
if ( ! F_48 ( V_19 -> V_28 , V_14 ) )
F_41 ( V_107 L_31 , V_125 ) ;
F_9 ( V_14 ) ;
}
static void F_128 ( struct V_18 * V_19 , T_5 * V_86 ,
struct V_1 * V_2 , int V_78 )
{
struct V_3 * V_4 = ( void * ) V_2 -> V_5 ;
struct V_13 * V_14 ;
struct V_70 * V_33 ;
T_6 V_150 ;
if ( ! V_4 -> V_194 )
return;
F_36 ( V_19 -> V_28 -> V_84 ,
L_32 ,
V_125 , V_4 -> V_192 , V_78 ) ;
V_14 = F_29 ( sizeof( * V_33 ) ) ;
if ( ! V_14 )
return;
V_33 = ( void * ) F_30 ( V_14 , sizeof( * V_33 ) - V_77 ) ;
V_33 -> V_72 = F_23 ( V_286 |
V_287 |
( V_78 ? V_99 : 0 ) ) ;
V_33 -> V_75 = F_23 ( 0 ) ;
memcpy ( V_33 -> V_76 , V_4 -> V_192 , V_77 ) ;
memcpy ( V_33 -> V_157 , V_86 , V_77 ) ;
memcpy ( V_33 -> V_288 , V_4 -> V_192 , V_77 ) ;
V_150 = F_62 ( V_156 ) ;
if ( V_150 )
return F_35 ( V_19 -> V_28 , V_14 , V_150 ) ;
if ( ! F_48 ( V_19 -> V_28 , V_14 ) )
F_41 ( V_107 L_33 , V_125 ) ;
F_9 ( V_14 ) ;
}
static void F_129 ( void * V_281 , T_5 * V_86 ,
struct V_1 * V_2 )
{
struct V_18 * V_19 = V_281 ;
F_128 ( V_19 , V_86 , V_2 , 1 ) ;
}
static void F_130 ( void * V_281 , T_5 * V_86 ,
struct V_1 * V_2 )
{
struct V_18 * V_19 = V_281 ;
F_128 ( V_19 , V_86 , V_2 , 0 ) ;
}
static int F_131 ( void * V_281 , T_3 * V_289 )
{
struct V_18 * V_19 = V_281 ;
* V_289 = V_19 -> V_78 ;
return 0 ;
}
static int F_91 ( void * V_281 , T_3 V_289 )
{
struct V_18 * V_19 = V_281 ;
enum V_290 V_291 ;
if ( V_289 != V_79 && V_289 != V_80 && V_289 != V_81 &&
V_289 != V_82 )
return - V_233 ;
V_291 = V_19 -> V_78 ;
V_19 -> V_78 = V_289 ;
if ( V_289 == V_82 ) {
F_132 ( V_19 -> V_28 ,
F_127 , V_19 ) ;
V_19 -> V_83 = true ;
} else if ( V_291 == V_79 && V_289 != V_79 ) {
F_132 ( V_19 -> V_28 ,
F_129 ,
V_19 ) ;
} else if ( V_291 != V_79 && V_289 == V_79 ) {
F_132 ( V_19 -> V_28 ,
F_130 ,
V_19 ) ;
}
return 0 ;
}
static int F_133 ( void * V_281 , T_3 * V_289 )
{
struct V_18 * V_19 = V_281 ;
* V_289 = V_19 -> V_147 ;
return 0 ;
}
static int F_134 ( void * V_281 , T_3 V_289 )
{
struct V_18 * V_19 = V_281 ;
V_19 -> V_147 = V_289 ;
return 0 ;
}
struct V_18 * F_135 (
struct V_109 * V_69 )
{
struct V_18 * V_19 ;
bool V_292 = false ;
F_115 ( & V_144 ) ;
F_54 (data, &hwsim_radios, list) {
if ( memcmp ( V_19 -> V_110 [ 1 ] . V_69 , V_69 ,
sizeof( struct V_109 ) ) == 0 ) {
V_292 = true ;
break;
}
}
F_118 ( & V_144 ) ;
if ( ! V_292 )
return NULL ;
return V_19 ;
}
static int F_136 ( struct V_13 * V_293 ,
struct V_294 * V_36 )
{
struct V_70 * V_33 ;
struct V_18 * V_126 ;
struct V_35 * V_149 ;
struct V_95 * V_96 ;
struct V_13 T_7 * V_295 ;
struct V_13 * V_14 , * V_268 ;
struct V_109 * V_296 ;
unsigned int V_93 ;
int V_94 ;
bool V_297 = false ;
if ( ! V_36 -> V_298 [ V_108 ] ||
! V_36 -> V_298 [ V_117 ] ||
! V_36 -> V_298 [ V_123 ] ||
! V_36 -> V_298 [ V_122 ] )
goto V_265;
V_296 = (struct V_109 * ) F_137 (
V_36 -> V_298 [ V_108 ] ) ;
V_93 = F_90 ( V_36 -> V_298 [ V_117 ] ) ;
V_295 = (struct V_13 T_7 * )
( unsigned long ) F_138 ( V_36 -> V_298 [ V_123 ] ) ;
V_126 = F_135 ( V_296 ) ;
if ( V_126 == NULL )
goto V_265;
F_139 (&data2->pending, skb, tmp) {
if ( V_14 == V_295 ) {
F_140 ( V_14 , & V_126 -> V_100 ) ;
V_297 = true ;
break;
}
}
if ( ! V_297 )
goto V_265;
V_96 = (struct V_95 * ) F_137 (
V_36 -> V_298 [ V_122 ] ) ;
V_149 = F_18 ( V_14 ) ;
if ( V_149 -> V_135 . V_2 )
F_1 ( V_149 -> V_135 . V_2 ) ;
if ( V_149 -> V_135 . V_9 )
F_5 ( V_149 -> V_135 . V_9 ) ;
F_63 ( V_149 ) ;
for ( V_94 = 0 ; V_94 < V_97 ; V_94 ++ ) {
V_149 -> V_119 . V_120 [ V_94 ] . V_118 = V_96 [ V_94 ] . V_118 ;
V_149 -> V_119 . V_120 [ V_94 ] . V_121 = V_96 [ V_94 ] . V_121 ;
}
V_149 -> V_119 . V_299 = F_90 ( V_36 -> V_298 [ V_300 ] ) ;
if ( ! ( V_93 & V_116 ) &&
( V_93 & V_301 ) ) {
if ( V_14 -> V_112 >= 16 ) {
V_33 = (struct V_70 * ) V_14 -> V_19 ;
F_28 ( V_126 -> V_28 , V_33 -> V_157 ) ;
}
}
F_64 ( V_126 -> V_28 , V_14 ) ;
return 0 ;
V_265:
return - V_233 ;
}
static int F_141 ( struct V_13 * V_293 ,
struct V_294 * V_36 )
{
struct V_18 * V_126 ;
struct V_128 V_129 ;
struct V_109 * V_302 ;
int V_303 ;
char * V_304 ;
struct V_13 * V_14 = NULL ;
if ( ! V_36 -> V_298 [ V_305 ] ||
! V_36 -> V_298 [ V_111 ] ||
! V_36 -> V_298 [ V_306 ] ||
! V_36 -> V_298 [ V_300 ] )
goto V_265;
V_302 = (struct V_109 * ) F_137 (
V_36 -> V_298 [ V_305 ] ) ;
V_303 = F_142 ( V_36 -> V_298 [ V_111 ] ) ;
V_304 = ( char * ) F_137 ( V_36 -> V_298 [ V_111 ] ) ;
V_14 = F_143 ( V_303 , V_257 ) ;
if ( V_14 == NULL )
goto V_230;
if ( V_303 <= V_307 ) {
memcpy ( F_30 ( V_14 , V_303 ) , V_304 ,
V_303 ) ;
} else
goto V_230;
V_126 = F_135 ( V_302 ) ;
if ( V_126 == NULL )
goto V_265;
if ( V_126 -> V_98 || ! V_126 -> V_146 || ! V_126 -> V_55 )
goto V_265;
memset ( & V_129 , 0 , sizeof( V_129 ) ) ;
V_129 . V_132 = V_126 -> V_55 -> V_56 ;
V_129 . V_133 = V_126 -> V_55 -> V_133 ;
V_129 . V_134 = F_90 ( V_36 -> V_298 [ V_306 ] ) ;
V_129 . signal = F_90 ( V_36 -> V_298 [ V_300 ] ) ;
memcpy ( F_56 ( V_14 ) , & V_129 , sizeof( V_129 ) ) ;
F_57 ( V_126 -> V_28 , V_14 ) ;
return 0 ;
V_230:
F_41 ( V_107 L_3 , V_125 ) ;
goto V_265;
V_265:
F_9 ( V_14 ) ;
return - V_233 ;
}
static int F_144 ( struct V_13 * V_293 ,
struct V_294 * V_36 )
{
if ( V_36 == NULL )
goto V_265;
V_156 = V_36 -> V_308 ;
F_41 ( V_107 L_34
L_35 , V_36 -> V_308 ) ;
return 0 ;
V_265:
F_41 ( V_107 L_3 , V_125 ) ;
return - V_233 ;
}
static int F_145 ( struct V_309 * V_310 ,
unsigned long V_311 ,
void * V_312 )
{
struct V_313 * V_314 = V_312 ;
if ( V_311 != V_315 )
return V_316 ;
if ( V_314 -> V_317 == V_156 ) {
F_41 ( V_318 L_36
L_37 ) ;
V_156 = 0 ;
}
return V_316 ;
}
static int F_146 ( void )
{
int V_319 ;
F_41 ( V_318 L_38 ) ;
V_319 = F_147 ( & V_105 ,
V_320 , F_148 ( V_320 ) ) ;
if ( V_319 )
goto V_321;
V_319 = F_149 ( & V_322 ) ;
if ( V_319 )
goto V_321;
return 0 ;
V_321:
F_41 ( V_107 L_3 , V_125 ) ;
return - V_233 ;
}
static void F_150 ( void )
{
int V_89 ;
F_41 ( V_318 L_39 ) ;
F_151 ( & V_322 ) ;
V_89 = F_152 ( & V_105 ) ;
if ( V_89 )
F_41 ( V_107 L_40
L_41 , V_89 ) ;
}
static int T_8 F_153 ( void )
{
int V_94 , V_230 = 0 ;
T_5 V_69 [ V_77 ] ;
struct V_18 * V_19 ;
struct V_27 * V_28 ;
enum V_323 V_133 ;
if ( V_324 < 1 || V_324 > 100 )
return - V_233 ;
if ( V_325 ) {
V_326 . V_327 = F_104 ;
V_326 . V_328 = NULL ;
V_326 . V_329 = NULL ;
}
F_154 ( & V_144 ) ;
F_114 ( & V_330 ) ;
V_273 = F_155 ( V_331 , L_42 ) ;
if ( F_156 ( V_273 ) )
return F_157 ( V_273 ) ;
memset ( V_69 , 0 , V_77 ) ;
V_69 [ 0 ] = 0x02 ;
for ( V_94 = 0 ; V_94 < V_324 ; V_94 ++ ) {
F_41 ( V_107 L_43 ,
V_94 ) ;
V_28 = F_158 ( sizeof( * V_19 ) , & V_326 ) ;
if ( ! V_28 ) {
F_41 ( V_107 L_44
L_45 ) ;
V_230 = - V_237 ;
goto V_332;
}
V_19 = V_28 -> V_29 ;
V_19 -> V_28 = V_28 ;
V_19 -> V_16 = F_159 ( V_273 , NULL , 0 , V_28 ,
L_46 , V_94 ) ;
if ( F_156 ( V_19 -> V_16 ) ) {
F_41 ( V_107
L_47
L_48 , F_157 ( V_19 -> V_16 ) ) ;
V_230 = - V_237 ;
goto V_333;
}
V_19 -> V_16 -> V_334 = & V_335 ;
F_160 ( & V_19 -> V_100 ) ;
F_161 ( V_28 , V_19 -> V_16 ) ;
V_69 [ 3 ] = V_94 >> 8 ;
V_69 [ 4 ] = V_94 ;
memcpy ( V_19 -> V_110 [ 0 ] . V_69 , V_69 , V_77 ) ;
memcpy ( V_19 -> V_110 [ 1 ] . V_69 , V_69 , V_77 ) ;
V_19 -> V_110 [ 1 ] . V_69 [ 0 ] |= 0x40 ;
V_28 -> V_84 -> V_336 = 2 ;
V_28 -> V_84 -> V_110 = V_19 -> V_110 ;
if ( V_325 ) {
V_28 -> V_84 -> V_337 = 255 ;
V_28 -> V_84 -> V_338 = V_307 ;
}
V_28 -> V_339 = 1 ;
V_28 -> V_340 = 4 ;
V_28 -> V_84 -> V_341 =
F_162 ( V_342 ) |
F_162 ( V_164 ) |
F_162 ( V_343 ) |
F_162 ( V_344 ) |
F_162 ( V_166 ) |
F_162 ( V_165 ) ;
V_28 -> V_34 = V_345 |
V_346 |
V_347 |
V_348 |
V_349 ;
V_28 -> V_84 -> V_34 |= V_350 ;
V_28 -> V_351 = sizeof( struct V_3 ) ;
V_28 -> V_352 = sizeof( struct V_10 ) ;
memcpy ( V_19 -> V_353 , V_354 ,
sizeof( V_354 ) ) ;
memcpy ( V_19 -> V_355 , V_356 ,
sizeof( V_356 ) ) ;
memcpy ( V_19 -> V_120 , V_357 , sizeof( V_357 ) ) ;
for ( V_133 = V_358 ; V_133 < V_359 ; V_133 ++ ) {
struct V_360 * V_361 = & V_19 -> V_362 [ V_133 ] ;
switch ( V_133 ) {
case V_358 :
V_361 -> V_259 = V_19 -> V_353 ;
V_361 -> V_258 =
F_148 ( V_354 ) ;
V_361 -> V_363 = V_19 -> V_120 ;
V_361 -> V_364 = F_148 ( V_357 ) ;
break;
case V_365 :
V_361 -> V_259 = V_19 -> V_355 ;
V_361 -> V_258 =
F_148 ( V_356 ) ;
V_361 -> V_363 = V_19 -> V_120 + 4 ;
V_361 -> V_364 = F_148 ( V_357 ) - 4 ;
break;
default:
break;
}
V_361 -> V_366 . V_367 = true ;
V_361 -> V_366 . V_368 = V_369 |
V_370 |
V_371 |
V_372 ;
V_361 -> V_366 . V_373 = 0x3 ;
V_361 -> V_366 . V_374 = 0x6 ;
memset ( & V_361 -> V_366 . V_375 , 0 ,
sizeof( V_361 -> V_366 . V_375 ) ) ;
V_361 -> V_366 . V_375 . V_376 [ 0 ] = 0xff ;
V_361 -> V_366 . V_375 . V_376 [ 1 ] = 0xff ;
V_361 -> V_366 . V_375 . V_377 = V_378 ;
V_28 -> V_84 -> V_362 [ V_133 ] = V_361 ;
}
V_19 -> V_147 = 1 ;
F_163 ( & V_19 -> V_263 ) ;
V_28 -> V_379 = 4 ;
V_28 -> V_380 = 11 ;
switch ( V_381 ) {
case V_382 :
case V_383 :
case V_384 :
case V_385 :
break;
case V_386 :
if ( V_94 == 0 ) {
V_28 -> V_84 -> V_34 |= V_387 ;
F_164 ( V_28 -> V_84 ,
& V_388 ) ;
}
break;
case V_389 :
V_28 -> V_84 -> V_34 |= V_387 ;
F_164 ( V_28 -> V_84 ,
& V_388 ) ;
break;
case V_390 :
if ( V_94 == 0 ) {
V_28 -> V_84 -> V_34 |= V_387 ;
F_164 ( V_28 -> V_84 ,
& V_388 ) ;
} else if ( V_94 == 1 ) {
V_28 -> V_84 -> V_34 |= V_387 ;
F_164 ( V_28 -> V_84 ,
& V_391 ) ;
}
break;
case V_392 :
V_28 -> V_84 -> V_34 |= V_393 ;
break;
case V_394 :
case V_395 :
if ( V_94 == 0 )
V_28 -> V_84 -> V_34 |= V_393 ;
break;
case V_396 :
if ( V_94 == 0 ) {
V_28 -> V_84 -> V_34 |= V_387 ;
F_164 ( V_28 -> V_84 ,
& V_388 ) ;
} else if ( V_94 == 1 ) {
V_28 -> V_84 -> V_34 |= V_387 ;
F_164 ( V_28 -> V_84 ,
& V_391 ) ;
} else if ( V_94 == 4 )
V_28 -> V_84 -> V_34 |= V_393 ;
break;
default:
break;
}
if ( V_381 )
F_165 ( 1 ) ;
V_230 = F_166 ( V_28 ) ;
if ( V_230 < 0 ) {
F_41 ( V_107 L_40
L_49 , V_230 ) ;
goto V_397;
}
switch ( V_381 ) {
case V_386 :
case V_382 :
break;
case V_383 :
if ( ! V_94 )
F_167 ( V_28 -> V_84 , V_398 [ 0 ] ) ;
break;
case V_384 :
case V_392 :
F_167 ( V_28 -> V_84 , V_398 [ 0 ] ) ;
break;
case V_385 :
if ( V_94 < F_148 ( V_398 ) )
F_167 ( V_28 -> V_84 , V_398 [ V_94 ] ) ;
break;
case V_389 :
case V_390 :
break;
case V_394 :
if ( V_94 == 0 )
F_167 ( V_28 -> V_84 , V_398 [ 0 ] ) ;
break;
case V_395 :
if ( V_94 == 0 )
F_167 ( V_28 -> V_84 , V_398 [ 0 ] ) ;
else if ( V_94 == 1 )
F_167 ( V_28 -> V_84 , V_398 [ 1 ] ) ;
break;
case V_396 :
if ( V_94 == 2 )
F_167 ( V_28 -> V_84 , V_398 [ 0 ] ) ;
else if ( V_94 == 3 )
F_167 ( V_28 -> V_84 , V_398 [ 1 ] ) ;
else if ( V_94 == 4 )
F_167 ( V_28 -> V_84 , V_398 [ 2 ] ) ;
break;
default:
break;
}
F_36 ( V_28 -> V_84 , L_50 ,
V_28 -> V_84 -> V_85 ) ;
V_19 -> V_272 = F_168 ( L_51 ,
V_28 -> V_84 -> V_399 ) ;
V_19 -> V_271 = F_169 ( L_52 , 0666 ,
V_19 -> V_272 , V_19 ,
& V_400 ) ;
V_19 -> V_270 = F_169 ( L_53 , 0666 ,
V_19 -> V_272 , V_19 ,
& V_401 ) ;
F_170 ( & V_19 -> V_159 , F_75 ,
( unsigned long ) V_28 ) ;
F_171 ( & V_19 -> V_402 , & V_330 ) ;
}
V_39 = F_172 ( 0 , L_46 , F_125 ) ;
if ( V_39 == NULL )
goto V_332;
F_173 () ;
V_230 = F_174 ( V_39 , V_39 -> V_403 ) ;
if ( V_230 < 0 )
goto V_404;
V_230 = F_175 ( V_39 ) ;
if ( V_230 < 0 )
goto V_404;
F_176 () ;
V_230 = F_146 () ;
if ( V_230 < 0 )
goto V_405;
return 0 ;
V_405:
F_41 ( V_107 L_54 ) ;
return V_230 ;
V_404:
F_176 () ;
V_277 ( V_39 ) ;
F_113 () ;
return V_230 ;
V_397:
F_122 ( V_19 -> V_16 ) ;
V_333:
F_123 ( V_28 ) ;
V_332:
F_113 () ;
return V_230 ;
}
static void T_9 F_177 ( void )
{
F_41 ( V_107 L_55 ) ;
F_150 () ;
F_113 () ;
F_178 ( V_39 ) ;
}
