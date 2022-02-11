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
if ( F_42 ( V_14 , V_108 ,
sizeof( struct V_109 ) , V_19 -> V_110 [ 1 ] . V_69 ) )
goto V_104;
if ( F_42 ( V_14 , V_111 , V_90 -> V_112 , V_90 -> V_19 ) )
goto V_104;
if ( V_36 -> V_34 & V_113 )
V_93 |= V_114 ;
if ( V_36 -> V_34 & V_115 )
V_93 |= V_116 ;
if ( F_43 ( V_14 , V_117 , V_93 ) )
goto V_104;
for ( V_94 = 0 ; V_94 < V_97 ; V_94 ++ ) {
V_96 [ V_94 ] . V_118 = V_36 -> V_119 . V_120 [ V_94 ] . V_118 ;
V_96 [ V_94 ] . V_121 = V_36 -> V_119 . V_120 [ V_94 ] . V_121 ;
}
if ( F_42 ( V_14 , V_122 ,
sizeof( struct V_95 ) * V_97 ,
V_96 ) )
goto V_104;
if ( F_44 ( V_14 , V_123 , ( unsigned long ) V_90 ) )
goto V_104;
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
struct V_37 * V_38 = F_19 ( V_28 , V_36 ) ;
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
struct V_146 * V_147 ;
if ( V_19 == V_126 )
continue;
if ( V_126 -> V_98 || ! V_126 -> V_148 ||
! F_31 ( V_126 , V_14 ) || ! V_126 -> V_55 ||
V_19 -> V_55 -> V_56 != V_126 -> V_55 -> V_56 ||
! ( V_19 -> V_149 & V_126 -> V_149 ) )
continue;
V_145 = F_55 ( V_14 , V_40 ) ;
if ( V_145 == NULL )
continue;
if ( F_33 ( V_126 , V_33 -> V_76 ) )
V_127 = true ;
V_129 . V_150 =
F_15 ( F_10 ( V_126 ) ) ;
V_147 = (struct V_146 * ) V_145 -> V_19 ;
if ( F_56 ( V_147 -> V_72 ) ||
F_57 ( V_147 -> V_72 ) )
V_147 -> V_151 . V_152 . V_153 = F_13 (
V_129 . V_150 +
( V_19 -> V_26 - V_126 -> V_26 ) +
24 * 8 * 10 / V_38 -> V_53 ) ;
memcpy ( F_58 ( V_145 ) , & V_129 , sizeof( V_129 ) ) ;
F_59 ( V_126 -> V_28 , V_145 ) ;
}
F_60 ( & V_144 ) ;
return V_127 ;
}
static void F_61 ( struct V_27 * V_28 , struct V_13 * V_14 )
{
bool V_127 ;
struct V_35 * V_154 ;
T_6 V_155 ;
F_17 ( V_28 , V_14 ) ;
if ( V_14 -> V_112 < 10 ) {
F_9 ( V_14 ) ;
return;
}
V_155 = F_62 ( V_156 ) ;
if ( V_155 )
return F_35 ( V_28 , V_14 , V_155 ) ;
V_127 = F_48 ( V_28 , V_14 ) ;
if ( V_127 && V_14 -> V_112 >= 16 ) {
struct V_70 * V_33 = (struct V_70 * ) V_14 -> V_19 ;
F_28 ( V_28 , V_33 -> V_157 ) ;
}
V_154 = F_18 ( V_14 ) ;
F_63 ( V_154 ) ;
V_154 -> V_135 . V_120 [ 0 ] . V_121 = 1 ;
V_154 -> V_135 . V_120 [ 1 ] . V_118 = - 1 ;
if ( ! ( V_154 -> V_34 & V_115 ) && V_127 )
V_154 -> V_34 |= V_158 ;
F_64 ( V_28 , V_14 ) ;
}
static int F_65 ( struct V_27 * V_28 )
{
struct V_18 * V_19 = V_28 -> V_29 ;
F_36 ( V_28 -> V_84 , L_4 , V_125 ) ;
V_19 -> V_148 = true ;
return 0 ;
}
static void F_66 ( struct V_27 * V_28 )
{
struct V_18 * V_19 = V_28 -> V_29 ;
V_19 -> V_148 = false ;
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
struct V_13 * V_14 ;
struct V_35 * V_36 ;
T_6 V_155 ;
F_1 ( V_2 ) ;
if ( V_2 -> type != V_164 &&
V_2 -> type != V_165 &&
V_2 -> type != V_166 )
return;
V_14 = F_74 ( V_28 , V_2 ) ;
if ( V_14 == NULL )
return;
V_36 = F_18 ( V_14 ) ;
F_17 ( V_28 , V_14 ) ;
V_155 = F_62 ( V_156 ) ;
if ( V_155 )
return F_35 ( V_28 , V_14 , V_155 ) ;
F_48 ( V_28 , V_14 ) ;
F_9 ( V_14 ) ;
}
static void F_75 ( unsigned long V_163 )
{
struct V_27 * V_28 = (struct V_27 * ) V_163 ;
struct V_18 * V_19 = V_28 -> V_29 ;
if ( ! V_19 -> V_148 )
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
if ( ! V_19 -> V_148 || ! V_19 -> V_169 )
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
if ( V_19 -> V_148 )
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
if ( F_43 ( V_14 , V_235 , V_226 -> V_78 ) )
goto V_104;
return F_94 ( V_14 ) ;
case V_238 :
F_95 ( V_28 ) ;
return 0 ;
case V_239 :
F_96 ( V_28 ) ;
return 0 ;
default:
return - V_240 ;
}
V_104:
F_97 ( V_14 ) ;
return - V_241 ;
}
static int F_98 ( struct V_27 * V_28 ,
struct V_1 * V_2 ,
enum V_242 V_243 ,
struct V_8 * V_9 , T_4 V_244 , T_4 * V_245 ,
T_5 V_246 )
{
switch ( V_243 ) {
case V_247 :
F_99 ( V_2 , V_9 -> V_69 , V_244 ) ;
break;
case V_248 :
F_100 ( V_2 , V_9 -> V_69 , V_244 ) ;
break;
case V_249 :
break;
case V_250 :
case V_251 :
break;
default:
return - V_240 ;
}
return 0 ;
}
static void F_101 ( struct V_27 * V_28 , bool V_252 )
{
}
static void F_102 ( struct V_253 * V_254 )
{
struct F_102 * V_255 =
F_103 ( V_254 , struct F_102 , V_256 . V_254 ) ;
F_104 ( V_255 -> V_28 , false ) ;
F_105 ( V_255 ) ;
}
static int F_106 ( struct V_27 * V_28 ,
struct V_1 * V_2 ,
struct V_257 * V_258 )
{
struct F_102 * V_255 = F_107 ( sizeof( * V_255 ) , V_259 ) ;
int V_94 ;
if ( ! V_255 )
return - V_237 ;
V_255 -> V_28 = V_28 ;
F_108 ( & V_255 -> V_256 , F_102 ) ;
F_41 ( V_107 L_24 ) ;
for ( V_94 = 0 ; V_94 < V_258 -> V_260 ; V_94 ++ )
F_41 ( V_107 L_25 ,
V_258 -> V_261 [ V_94 ] -> V_56 ) ;
F_109 ( V_107 , L_26 , V_262 ,
16 , 1 , V_258 -> V_263 , V_258 -> V_264 , 1 ) ;
F_110 ( V_28 , & V_255 -> V_256 , 2 * V_197 ) ;
return 0 ;
}
static void F_111 ( struct V_27 * V_28 )
{
struct V_18 * V_226 = V_28 -> V_29 ;
F_112 ( & V_226 -> V_265 ) ;
if ( V_226 -> V_266 ) {
F_41 ( V_107 L_27 ) ;
goto V_267;
}
F_41 ( V_107 L_28 ) ;
V_226 -> V_266 = true ;
V_267:
F_113 ( & V_226 -> V_265 ) ;
}
static void F_114 ( struct V_27 * V_28 )
{
struct V_18 * V_226 = V_28 -> V_29 ;
F_112 ( & V_226 -> V_265 ) ;
F_41 ( V_107 L_29 ) ;
V_226 -> V_266 = false ;
F_113 ( & V_226 -> V_265 ) ;
}
static void F_115 ( void )
{
struct V_268 V_269 , * V_94 , * V_270 ;
struct V_18 * V_19 , * V_271 ;
F_116 ( & V_269 ) ;
F_117 ( & V_144 ) ;
F_118 (i, tmp, &hwsim_radios)
F_119 ( V_94 , & V_269 ) ;
F_120 ( & V_144 ) ;
F_121 (data, tmpdata, &tmplist, list) {
F_122 ( V_19 -> V_272 ) ;
F_122 ( V_19 -> V_273 ) ;
F_122 ( V_19 -> V_274 ) ;
F_123 ( V_19 -> V_28 ) ;
F_124 ( V_19 -> V_16 ) ;
F_125 ( V_19 -> V_28 ) ;
}
F_126 ( V_275 ) ;
}
static void F_127 ( struct V_15 * V_16 )
{
V_16 -> V_276 = & V_277 ;
V_16 -> V_278 = V_279 ;
F_128 ( V_16 ) ;
V_16 -> V_280 = 0 ;
V_16 -> type = V_281 ;
memset ( V_16 -> V_282 , 0 , V_77 ) ;
V_16 -> V_282 [ 0 ] = 0x12 ;
}
static void F_129 ( void * V_283 , T_5 * V_86 , struct V_1 * V_2 )
{
struct V_18 * V_19 = V_283 ;
struct V_3 * V_4 = ( void * ) V_2 -> V_5 ;
struct V_13 * V_14 ;
struct V_284 * V_285 ;
T_6 V_155 ;
if ( ! V_4 -> V_194 )
return;
F_36 ( V_19 -> V_28 -> V_84 ,
L_30 ,
V_125 , V_4 -> V_192 , V_4 -> V_195 ) ;
V_14 = F_29 ( sizeof( * V_285 ) ) ;
if ( ! V_14 )
return;
V_285 = ( void * ) F_30 ( V_14 , sizeof( * V_285 ) ) ;
V_285 -> V_72 = F_23 ( V_73 |
V_286 |
V_99 ) ;
V_285 -> V_195 = F_23 ( 0xc000 | V_4 -> V_195 ) ;
memcpy ( V_285 -> V_192 , V_4 -> V_192 , V_77 ) ;
memcpy ( V_285 -> V_287 , V_86 , V_77 ) ;
V_155 = F_62 ( V_156 ) ;
if ( V_155 )
return F_35 ( V_19 -> V_28 , V_14 , V_155 ) ;
if ( ! F_48 ( V_19 -> V_28 , V_14 ) )
F_41 ( V_107 L_31 , V_125 ) ;
F_9 ( V_14 ) ;
}
static void F_130 ( struct V_18 * V_19 , T_5 * V_86 ,
struct V_1 * V_2 , int V_78 )
{
struct V_3 * V_4 = ( void * ) V_2 -> V_5 ;
struct V_13 * V_14 ;
struct V_70 * V_33 ;
T_6 V_155 ;
if ( ! V_4 -> V_194 )
return;
F_36 ( V_19 -> V_28 -> V_84 ,
L_32 ,
V_125 , V_4 -> V_192 , V_78 ) ;
V_14 = F_29 ( sizeof( * V_33 ) ) ;
if ( ! V_14 )
return;
V_33 = ( void * ) F_30 ( V_14 , sizeof( * V_33 ) - V_77 ) ;
V_33 -> V_72 = F_23 ( V_288 |
V_289 |
( V_78 ? V_99 : 0 ) ) ;
V_33 -> V_75 = F_23 ( 0 ) ;
memcpy ( V_33 -> V_76 , V_4 -> V_192 , V_77 ) ;
memcpy ( V_33 -> V_157 , V_86 , V_77 ) ;
memcpy ( V_33 -> V_290 , V_4 -> V_192 , V_77 ) ;
V_155 = F_62 ( V_156 ) ;
if ( V_155 )
return F_35 ( V_19 -> V_28 , V_14 , V_155 ) ;
if ( ! F_48 ( V_19 -> V_28 , V_14 ) )
F_41 ( V_107 L_33 , V_125 ) ;
F_9 ( V_14 ) ;
}
static void F_131 ( void * V_283 , T_5 * V_86 ,
struct V_1 * V_2 )
{
struct V_18 * V_19 = V_283 ;
F_130 ( V_19 , V_86 , V_2 , 1 ) ;
}
static void F_132 ( void * V_283 , T_5 * V_86 ,
struct V_1 * V_2 )
{
struct V_18 * V_19 = V_283 ;
F_130 ( V_19 , V_86 , V_2 , 0 ) ;
}
static int F_133 ( void * V_283 , T_3 * V_291 )
{
struct V_18 * V_19 = V_283 ;
* V_291 = V_19 -> V_78 ;
return 0 ;
}
static int F_91 ( void * V_283 , T_3 V_291 )
{
struct V_18 * V_19 = V_283 ;
enum V_292 V_293 ;
if ( V_291 != V_79 && V_291 != V_80 && V_291 != V_81 &&
V_291 != V_82 )
return - V_233 ;
V_293 = V_19 -> V_78 ;
V_19 -> V_78 = V_291 ;
if ( V_291 == V_82 ) {
F_134 ( V_19 -> V_28 ,
F_129 , V_19 ) ;
V_19 -> V_83 = true ;
} else if ( V_293 == V_79 && V_291 != V_79 ) {
F_134 ( V_19 -> V_28 ,
F_131 ,
V_19 ) ;
} else if ( V_293 != V_79 && V_291 == V_79 ) {
F_134 ( V_19 -> V_28 ,
F_132 ,
V_19 ) ;
}
return 0 ;
}
static int F_135 ( void * V_283 , T_3 * V_291 )
{
struct V_18 * V_19 = V_283 ;
* V_291 = V_19 -> V_149 ;
return 0 ;
}
static int F_136 ( void * V_283 , T_3 V_291 )
{
struct V_18 * V_19 = V_283 ;
V_19 -> V_149 = V_291 ;
return 0 ;
}
static struct V_18 * F_137 (
struct V_109 * V_69 )
{
struct V_18 * V_19 ;
bool V_294 = false ;
F_117 ( & V_144 ) ;
F_54 (data, &hwsim_radios, list) {
if ( memcmp ( V_19 -> V_110 [ 1 ] . V_69 , V_69 ,
sizeof( struct V_109 ) ) == 0 ) {
V_294 = true ;
break;
}
}
F_120 ( & V_144 ) ;
if ( ! V_294 )
return NULL ;
return V_19 ;
}
static int F_138 ( struct V_13 * V_295 ,
struct V_296 * V_36 )
{
struct V_70 * V_33 ;
struct V_18 * V_126 ;
struct V_35 * V_154 ;
struct V_95 * V_96 ;
unsigned long V_297 ;
struct V_13 * V_14 , * V_270 ;
struct V_109 * V_298 ;
unsigned int V_93 ;
int V_94 ;
bool V_299 = false ;
if ( ! V_36 -> V_300 [ V_108 ] ||
! V_36 -> V_300 [ V_117 ] ||
! V_36 -> V_300 [ V_123 ] ||
! V_36 -> V_300 [ V_122 ] )
goto V_267;
V_298 = (struct V_109 * ) F_139 (
V_36 -> V_300 [ V_108 ] ) ;
V_93 = F_90 ( V_36 -> V_300 [ V_117 ] ) ;
V_297 = F_140 ( V_36 -> V_300 [ V_123 ] ) ;
V_126 = F_137 ( V_298 ) ;
if ( V_126 == NULL )
goto V_267;
F_141 (&data2->pending, skb, tmp) {
if ( ( unsigned long ) V_14 == V_297 ) {
F_142 ( V_14 , & V_126 -> V_100 ) ;
V_299 = true ;
break;
}
}
if ( ! V_299 )
goto V_267;
V_96 = (struct V_95 * ) F_139 (
V_36 -> V_300 [ V_122 ] ) ;
V_154 = F_18 ( V_14 ) ;
F_63 ( V_154 ) ;
for ( V_94 = 0 ; V_94 < V_97 ; V_94 ++ ) {
V_154 -> V_119 . V_120 [ V_94 ] . V_118 = V_96 [ V_94 ] . V_118 ;
V_154 -> V_119 . V_120 [ V_94 ] . V_121 = V_96 [ V_94 ] . V_121 ;
}
V_154 -> V_119 . V_301 = F_90 ( V_36 -> V_300 [ V_302 ] ) ;
if ( ! ( V_93 & V_116 ) &&
( V_93 & V_303 ) ) {
if ( V_14 -> V_112 >= 16 ) {
V_33 = (struct V_70 * ) V_14 -> V_19 ;
F_28 ( V_126 -> V_28 , V_33 -> V_157 ) ;
}
V_154 -> V_34 |= V_158 ;
}
F_64 ( V_126 -> V_28 , V_14 ) ;
return 0 ;
V_267:
return - V_233 ;
}
static int F_143 ( struct V_13 * V_295 ,
struct V_296 * V_36 )
{
struct V_18 * V_126 ;
struct V_128 V_129 ;
struct V_109 * V_304 ;
int V_305 ;
char * V_306 ;
struct V_13 * V_14 = NULL ;
if ( ! V_36 -> V_300 [ V_307 ] ||
! V_36 -> V_300 [ V_111 ] ||
! V_36 -> V_300 [ V_308 ] ||
! V_36 -> V_300 [ V_302 ] )
goto V_267;
V_304 = (struct V_109 * ) F_139 (
V_36 -> V_300 [ V_307 ] ) ;
V_305 = F_144 ( V_36 -> V_300 [ V_111 ] ) ;
V_306 = ( char * ) F_139 ( V_36 -> V_300 [ V_111 ] ) ;
V_14 = F_145 ( V_305 , V_259 ) ;
if ( V_14 == NULL )
goto V_230;
if ( V_305 <= V_309 ) {
memcpy ( F_30 ( V_14 , V_305 ) , V_306 ,
V_305 ) ;
} else
goto V_230;
V_126 = F_137 ( V_304 ) ;
if ( V_126 == NULL )
goto V_267;
if ( V_126 -> V_98 || ! V_126 -> V_148 || ! V_126 -> V_55 )
goto V_267;
memset ( & V_129 , 0 , sizeof( V_129 ) ) ;
V_129 . V_132 = V_126 -> V_55 -> V_56 ;
V_129 . V_133 = V_126 -> V_55 -> V_133 ;
V_129 . V_134 = F_90 ( V_36 -> V_300 [ V_308 ] ) ;
V_129 . signal = F_90 ( V_36 -> V_300 [ V_302 ] ) ;
memcpy ( F_58 ( V_14 ) , & V_129 , sizeof( V_129 ) ) ;
F_59 ( V_126 -> V_28 , V_14 ) ;
return 0 ;
V_230:
F_41 ( V_107 L_3 , V_125 ) ;
goto V_267;
V_267:
F_9 ( V_14 ) ;
return - V_233 ;
}
static int F_146 ( struct V_13 * V_295 ,
struct V_296 * V_36 )
{
if ( V_36 == NULL )
goto V_267;
V_156 = V_36 -> V_310 ;
F_41 ( V_107 L_34
L_35 , V_36 -> V_310 ) ;
return 0 ;
V_267:
F_41 ( V_107 L_3 , V_125 ) ;
return - V_233 ;
}
static int F_147 ( struct V_311 * V_312 ,
unsigned long V_313 ,
void * V_314 )
{
struct V_315 * V_316 = V_314 ;
if ( V_313 != V_317 )
return V_318 ;
if ( V_316 -> V_319 == V_156 ) {
F_41 ( V_320 L_36
L_37 ) ;
V_156 = 0 ;
}
return V_318 ;
}
static int F_148 ( void )
{
int V_321 ;
F_41 ( V_320 L_38 ) ;
V_321 = F_149 ( & V_105 ,
V_322 , F_150 ( V_322 ) ) ;
if ( V_321 )
goto V_323;
V_321 = F_151 ( & V_324 ) ;
if ( V_321 )
goto V_323;
return 0 ;
V_323:
F_41 ( V_107 L_3 , V_125 ) ;
return - V_233 ;
}
static void F_152 ( void )
{
int V_89 ;
F_41 ( V_320 L_39 ) ;
F_153 ( & V_324 ) ;
V_89 = F_154 ( & V_105 ) ;
if ( V_89 )
F_41 ( V_107 L_40
L_41 , V_89 ) ;
}
static int T_7 F_155 ( void )
{
int V_94 , V_230 = 0 ;
T_5 V_69 [ V_77 ] ;
struct V_18 * V_19 ;
struct V_27 * V_28 ;
enum V_325 V_133 ;
if ( V_326 < 1 || V_326 > 100 )
return - V_233 ;
if ( V_327 ) {
V_328 . V_329 = F_106 ;
V_328 . V_330 = NULL ;
V_328 . V_331 = NULL ;
}
F_156 ( & V_144 ) ;
F_116 ( & V_332 ) ;
V_275 = F_157 ( V_333 , L_42 ) ;
if ( F_158 ( V_275 ) )
return F_159 ( V_275 ) ;
memset ( V_69 , 0 , V_77 ) ;
V_69 [ 0 ] = 0x02 ;
for ( V_94 = 0 ; V_94 < V_326 ; V_94 ++ ) {
F_41 ( V_107 L_43 ,
V_94 ) ;
V_28 = F_160 ( sizeof( * V_19 ) , & V_328 ) ;
if ( ! V_28 ) {
F_41 ( V_107 L_44
L_45 ) ;
V_230 = - V_237 ;
goto V_334;
}
V_19 = V_28 -> V_29 ;
V_19 -> V_28 = V_28 ;
V_19 -> V_16 = F_161 ( V_275 , NULL , 0 , V_28 ,
L_46 , V_94 ) ;
if ( F_158 ( V_19 -> V_16 ) ) {
F_41 ( V_107
L_47
L_48 , F_159 ( V_19 -> V_16 ) ) ;
V_230 = - V_237 ;
goto V_335;
}
V_19 -> V_16 -> V_336 = & V_337 ;
F_162 ( & V_19 -> V_100 ) ;
F_163 ( V_28 , V_19 -> V_16 ) ;
V_69 [ 3 ] = V_94 >> 8 ;
V_69 [ 4 ] = V_94 ;
memcpy ( V_19 -> V_110 [ 0 ] . V_69 , V_69 , V_77 ) ;
memcpy ( V_19 -> V_110 [ 1 ] . V_69 , V_69 , V_77 ) ;
V_19 -> V_110 [ 1 ] . V_69 [ 0 ] |= 0x40 ;
V_28 -> V_84 -> V_338 = 2 ;
V_28 -> V_84 -> V_110 = V_19 -> V_110 ;
V_28 -> V_84 -> V_339 = & V_340 ;
V_28 -> V_84 -> V_341 = 1 ;
if ( V_327 ) {
V_28 -> V_84 -> V_342 = 255 ;
V_28 -> V_84 -> V_343 = V_309 ;
}
V_28 -> V_344 = 1 ;
V_28 -> V_345 = 4 ;
V_28 -> V_84 -> V_346 =
F_164 ( V_347 ) |
F_164 ( V_164 ) |
F_164 ( V_348 ) |
F_164 ( V_349 ) |
F_164 ( V_166 ) |
F_164 ( V_165 ) ;
V_28 -> V_34 = V_350 |
V_351 |
V_352 |
V_353 |
V_354 |
V_355 ;
V_28 -> V_84 -> V_34 |= V_356 |
V_357 ;
V_28 -> V_358 = sizeof( struct V_3 ) ;
V_28 -> V_359 = sizeof( struct V_10 ) ;
memcpy ( V_19 -> V_360 , V_361 ,
sizeof( V_361 ) ) ;
memcpy ( V_19 -> V_362 , V_363 ,
sizeof( V_363 ) ) ;
memcpy ( V_19 -> V_120 , V_364 , sizeof( V_364 ) ) ;
for ( V_133 = V_365 ; V_133 < V_366 ; V_133 ++ ) {
struct V_367 * V_368 = & V_19 -> V_369 [ V_133 ] ;
switch ( V_133 ) {
case V_365 :
V_368 -> V_261 = V_19 -> V_360 ;
V_368 -> V_260 =
F_150 ( V_361 ) ;
V_368 -> V_370 = V_19 -> V_120 ;
V_368 -> V_371 = F_150 ( V_364 ) ;
break;
case V_372 :
V_368 -> V_261 = V_19 -> V_362 ;
V_368 -> V_260 =
F_150 ( V_363 ) ;
V_368 -> V_370 = V_19 -> V_120 + 4 ;
V_368 -> V_371 = F_150 ( V_364 ) - 4 ;
break;
default:
continue;
}
V_368 -> V_373 . V_374 = true ;
V_368 -> V_373 . V_375 = V_376 |
V_377 |
V_378 |
V_379 ;
V_368 -> V_373 . V_380 = 0x3 ;
V_368 -> V_373 . V_381 = 0x6 ;
memset ( & V_368 -> V_373 . V_382 , 0 ,
sizeof( V_368 -> V_373 . V_382 ) ) ;
V_368 -> V_373 . V_382 . V_383 [ 0 ] = 0xff ;
V_368 -> V_373 . V_382 . V_383 [ 1 ] = 0xff ;
V_368 -> V_373 . V_382 . V_384 = V_385 ;
V_28 -> V_84 -> V_369 [ V_133 ] = V_368 ;
}
V_19 -> V_149 = 1 ;
F_165 ( & V_19 -> V_265 ) ;
V_28 -> V_386 = 4 ;
V_28 -> V_387 = 11 ;
switch ( V_388 ) {
case V_389 :
case V_390 :
case V_391 :
case V_392 :
break;
case V_393 :
if ( V_94 == 0 ) {
V_28 -> V_84 -> V_34 |= V_394 ;
F_166 ( V_28 -> V_84 ,
& V_395 ) ;
}
break;
case V_396 :
V_28 -> V_84 -> V_34 |= V_394 ;
F_166 ( V_28 -> V_84 ,
& V_395 ) ;
break;
case V_397 :
if ( V_94 == 0 ) {
V_28 -> V_84 -> V_34 |= V_394 ;
F_166 ( V_28 -> V_84 ,
& V_395 ) ;
} else if ( V_94 == 1 ) {
V_28 -> V_84 -> V_34 |= V_394 ;
F_166 ( V_28 -> V_84 ,
& V_398 ) ;
}
break;
case V_399 :
V_28 -> V_84 -> V_34 |= V_400 ;
break;
case V_401 :
case V_402 :
if ( V_94 == 0 )
V_28 -> V_84 -> V_34 |= V_400 ;
break;
case V_403 :
if ( V_94 == 0 ) {
V_28 -> V_84 -> V_34 |= V_394 ;
F_166 ( V_28 -> V_84 ,
& V_395 ) ;
} else if ( V_94 == 1 ) {
V_28 -> V_84 -> V_34 |= V_394 ;
F_166 ( V_28 -> V_84 ,
& V_398 ) ;
} else if ( V_94 == 4 )
V_28 -> V_84 -> V_34 |= V_400 ;
break;
default:
break;
}
if ( V_388 )
F_167 ( 1 ) ;
V_230 = F_168 ( V_28 ) ;
if ( V_230 < 0 ) {
F_41 ( V_107 L_40
L_49 , V_230 ) ;
goto V_404;
}
switch ( V_388 ) {
case V_393 :
case V_389 :
break;
case V_390 :
if ( ! V_94 )
F_169 ( V_28 -> V_84 , V_405 [ 0 ] ) ;
break;
case V_391 :
case V_399 :
F_169 ( V_28 -> V_84 , V_405 [ 0 ] ) ;
break;
case V_392 :
if ( V_94 < F_150 ( V_405 ) )
F_169 ( V_28 -> V_84 , V_405 [ V_94 ] ) ;
break;
case V_396 :
case V_397 :
break;
case V_401 :
if ( V_94 == 0 )
F_169 ( V_28 -> V_84 , V_405 [ 0 ] ) ;
break;
case V_402 :
if ( V_94 == 0 )
F_169 ( V_28 -> V_84 , V_405 [ 0 ] ) ;
else if ( V_94 == 1 )
F_169 ( V_28 -> V_84 , V_405 [ 1 ] ) ;
break;
case V_403 :
if ( V_94 == 2 )
F_169 ( V_28 -> V_84 , V_405 [ 0 ] ) ;
else if ( V_94 == 3 )
F_169 ( V_28 -> V_84 , V_405 [ 1 ] ) ;
else if ( V_94 == 4 )
F_169 ( V_28 -> V_84 , V_405 [ 2 ] ) ;
break;
default:
break;
}
F_36 ( V_28 -> V_84 , L_50 ,
V_28 -> V_84 -> V_85 ) ;
V_19 -> V_274 = F_170 ( L_51 ,
V_28 -> V_84 -> V_406 ) ;
V_19 -> V_273 = F_171 ( L_52 , 0666 ,
V_19 -> V_274 , V_19 ,
& V_407 ) ;
V_19 -> V_272 = F_171 ( L_53 , 0666 ,
V_19 -> V_274 , V_19 ,
& V_408 ) ;
F_172 ( & V_19 -> V_159 , F_75 ,
( unsigned long ) V_28 ) ;
F_173 ( & V_19 -> V_409 , & V_332 ) ;
}
V_39 = F_174 ( 0 , L_46 , F_127 ) ;
if ( V_39 == NULL )
goto V_334;
F_175 () ;
V_230 = F_176 ( V_39 , V_39 -> V_410 ) ;
if ( V_230 < 0 )
goto V_411;
V_230 = F_177 ( V_39 ) ;
if ( V_230 < 0 )
goto V_411;
F_178 () ;
V_230 = F_148 () ;
if ( V_230 < 0 )
goto V_412;
return 0 ;
V_412:
F_41 ( V_107 L_54 ) ;
return V_230 ;
V_411:
F_178 () ;
V_279 ( V_39 ) ;
F_115 () ;
return V_230 ;
V_404:
F_124 ( V_19 -> V_16 ) ;
V_335:
F_125 ( V_28 ) ;
V_334:
F_115 () ;
return V_230 ;
}
static void T_8 F_179 ( void )
{
F_41 ( V_107 L_55 ) ;
F_152 () ;
F_115 () ;
F_180 ( V_39 ) ;
}
