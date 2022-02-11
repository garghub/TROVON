static T_1
F_1 ( struct V_1 * V_2 , T_2 V_3 )
{
T_1 V_4 ;
F_2 ( V_5 != V_6 ) ;
switch ( V_3 ) {
case V_7 :
switch ( F_3 ( V_2 ) ) {
default:
F_4 ( F_3 ( V_2 ) ) ;
case 9 :
return V_8 ;
case 8 :
return V_9 . V_10 ?
V_11 :
V_12 ;
case 7 :
if ( F_5 ( V_2 ) )
return V_13 ;
V_4 = F_6 ( V_14 ) ;
return F_7 ( F_8 ( V_4 ) * 64 ,
V_6 ) ;
case 6 :
V_4 = F_6 ( V_15 ) ;
return F_7 ( F_9 ( V_4 ) * 64 ,
V_6 ) ;
case 5 :
case 4 :
case 3 :
case 2 :
case 1 :
return 0 ;
}
break;
default:
F_4 ( V_3 ) ;
case V_16 :
case V_17 :
case V_18 :
if ( F_3 ( V_2 ) < 8 )
return 0 ;
return V_19 ;
}
}
static int
F_10 ( struct V_1 * V_2 ,
enum V_20 V_21 )
{
const struct V_22 * V_23 = & V_24 [ V_21 ] ;
const struct V_25 * V_26 ;
struct V_27 * V_28 ;
F_11 ( V_23 -> V_3 >= F_12 ( V_29 ) ) ;
V_26 = & V_29 [ V_23 -> V_3 ] ;
F_11 ( V_2 -> V_28 [ V_21 ] ) ;
V_28 = F_13 ( sizeof( * V_28 ) , V_30 ) ;
if ( ! V_28 )
return - V_31 ;
V_28 -> V_21 = V_21 ;
V_28 -> V_9 = V_2 ;
F_14 ( snprintf ( V_28 -> V_32 , sizeof( V_28 -> V_32 ) , L_1 ,
V_26 -> V_32 , V_23 -> V_33 ) >=
sizeof( V_28 -> V_32 ) ) ;
V_28 -> V_34 = V_23 -> V_34 ;
V_28 -> V_35 = V_28 -> V_36 = V_23 -> V_35 ;
V_28 -> V_37 = V_23 -> V_37 ;
V_28 -> V_38 = V_23 -> V_38 ;
V_28 -> V_3 = V_23 -> V_3 ;
V_28 -> V_33 = V_23 -> V_33 ;
V_28 -> V_39 = F_1 ( V_2 ,
V_28 -> V_3 ) ;
if ( F_14 ( V_28 -> V_39 > F_15 ( 20 ) ) )
V_28 -> V_39 = 0 ;
V_28 -> V_40 = NULL ;
F_16 ( & V_28 -> V_41 ) ;
V_2 -> V_28 [ V_21 ] = V_28 ;
return 0 ;
}
int F_17 ( struct V_1 * V_2 )
{
struct V_42 * V_43 = F_18 ( V_2 ) ;
const unsigned int V_44 = F_19 ( V_2 ) -> V_44 ;
struct V_27 * V_28 ;
enum V_20 V_21 ;
unsigned int V_45 = 0 ;
unsigned int V_46 ;
int V_47 ;
F_14 ( V_44 == 0 ) ;
F_14 ( V_44 &
F_20 ( sizeof( V_45 ) * V_48 - 1 , V_49 ) ) ;
for ( V_46 = 0 ; V_46 < F_12 ( V_24 ) ; V_46 ++ ) {
if ( ! F_21 ( V_2 , V_46 ) )
continue;
V_47 = F_10 ( V_2 , V_46 ) ;
if ( V_47 )
goto V_50;
V_45 |= F_22 ( V_46 ) ;
}
if ( F_14 ( V_45 != V_44 ) )
V_43 -> V_44 = V_45 ;
if ( F_14 ( ! F_21 ( V_2 , V_51 ) ) ) {
V_47 = - V_52 ;
goto V_50;
}
V_43 -> V_53 = F_23 ( V_45 ) ;
return 0 ;
V_50:
F_24 (engine, dev_priv, id)
F_25 ( V_28 ) ;
return V_47 ;
}
int F_26 ( struct V_1 * V_2 )
{
struct V_42 * V_43 = F_18 ( V_2 ) ;
struct V_27 * V_28 ;
enum V_20 V_21 , V_54 ;
unsigned int V_45 = 0 ;
int V_47 = 0 ;
F_24 (engine, dev_priv, id) {
const struct V_25 * V_26 =
& V_29 [ V_28 -> V_3 ] ;
int (* F_27)( struct V_27 * V_28 );
if ( V_9 . V_10 )
F_27 = V_26 -> V_55 ;
else
F_27 = V_26 -> V_56 ;
if ( ! F_27 ) {
F_25 ( V_28 ) ;
V_2 -> V_28 [ V_21 ] = NULL ;
continue;
}
V_47 = F_27 ( V_28 ) ;
if ( V_47 ) {
V_54 = V_21 ;
goto V_50;
}
F_11 ( ! V_28 -> V_57 ) ;
V_45 |= F_22 ( V_21 ) ;
}
if ( F_14 ( V_45 != F_19 ( V_2 ) -> V_44 ) )
V_43 -> V_44 = V_45 ;
V_43 -> V_53 = F_23 ( V_45 ) ;
return 0 ;
V_50:
F_24 (engine, dev_priv, id) {
if ( V_21 >= V_54 )
F_25 ( V_28 ) ;
else
V_2 -> V_58 . V_59 ( V_28 ) ;
}
return V_47 ;
}
void F_28 ( struct V_27 * V_28 , T_1 V_60 )
{
struct V_1 * V_2 = V_28 -> V_9 ;
F_11 ( ! F_29 ( V_28 ) ) ;
F_11 ( F_30 ( & V_28 -> V_61 -> V_62 ) ) ;
if ( F_31 ( V_2 ) || F_32 ( V_2 ) ) {
F_33 ( F_34 ( V_28 -> V_37 ) , 0 ) ;
F_33 ( F_35 ( V_28 -> V_37 ) , 0 ) ;
if ( F_36 ( V_2 ) )
F_33 ( F_37 ( V_28 -> V_37 ) , 0 ) ;
}
if ( V_2 -> V_63 ) {
struct V_64 * V_64 = F_38 ( V_2 -> V_63 ) ;
void * V_65 ;
V_65 = F_39 ( V_64 ) ;
memset ( V_65 + F_40 ( V_28 -> V_21 , 0 ) ,
0 , V_49 * V_66 ) ;
F_41 ( V_65 + F_40 ( V_28 -> V_21 , 0 ) ,
V_49 * V_66 ) ;
F_42 ( V_65 ) ;
}
F_43 ( V_28 , V_67 , V_60 ) ;
F_44 ( V_68 , & V_28 -> V_69 ) ;
F_45 ( V_28 ) ;
F_11 ( F_46 ( V_28 ) != V_60 ) ;
}
static void F_47 ( struct V_27 * V_28 )
{
V_28 -> V_61 = & V_28 -> V_9 -> V_58 . V_70 . V_28 [ V_28 -> V_21 ] ;
}
void F_48 ( struct V_27 * V_28 )
{
V_28 -> V_71 = V_72 ;
V_28 -> V_73 = NULL ;
F_47 ( V_28 ) ;
F_49 ( V_28 ) ;
F_50 ( V_28 , & V_28 -> V_74 ) ;
F_51 ( V_28 ) ;
}
int F_52 ( struct V_27 * V_28 , int V_75 )
{
struct V_76 * V_77 ;
struct V_78 * V_79 ;
int V_80 ;
F_14 ( V_28 -> V_81 ) ;
V_77 = F_53 ( V_28 -> V_9 , V_75 ) ;
if ( ! V_77 )
V_77 = F_54 ( V_28 -> V_9 , V_75 ) ;
if ( F_55 ( V_77 ) ) {
F_56 ( L_2 ) ;
return F_57 ( V_77 ) ;
}
V_79 = F_58 ( V_77 , & V_28 -> V_9 -> V_82 . V_83 , NULL ) ;
if ( F_55 ( V_79 ) ) {
V_80 = F_57 ( V_79 ) ;
goto V_84;
}
V_80 = F_59 ( V_79 , 0 , 4096 , V_85 | V_86 ) ;
if ( V_80 )
goto V_84;
V_28 -> V_81 = V_79 ;
F_60 ( L_3 ,
V_28 -> V_32 , F_61 ( V_79 ) ) ;
return 0 ;
V_84:
F_62 ( V_77 ) ;
return V_80 ;
}
static void F_63 ( struct V_27 * V_28 )
{
F_64 ( & V_28 -> V_81 ) ;
}
int F_65 ( struct V_27 * V_28 )
{
struct V_87 * V_88 ;
int V_80 ;
V_28 -> V_89 ( V_28 ) ;
V_88 = V_28 -> V_90 ( V_28 , V_28 -> V_9 -> V_91 ) ;
if ( F_55 ( V_88 ) )
return F_57 ( V_88 ) ;
V_80 = F_66 ( V_28 ) ;
if ( V_80 )
goto V_92;
V_80 = F_67 ( V_28 ) ;
if ( V_80 )
goto V_92;
return 0 ;
V_92:
V_28 -> V_93 ( V_28 , V_28 -> V_9 -> V_91 ) ;
return V_80 ;
}
void F_68 ( struct V_27 * V_28 )
{
F_63 ( V_28 ) ;
F_69 ( V_28 ) ;
F_70 ( V_28 ) ;
F_71 ( V_28 ) ;
F_72 ( & V_28 -> V_74 ) ;
V_28 -> V_93 ( V_28 , V_28 -> V_9 -> V_91 ) ;
}
T_3 F_73 ( struct V_27 * V_28 )
{
struct V_1 * V_2 = V_28 -> V_9 ;
T_3 V_94 ;
if ( F_3 ( V_2 ) >= 8 )
V_94 = F_74 ( F_75 ( V_28 -> V_37 ) ,
F_76 ( V_28 -> V_37 ) ) ;
else if ( F_3 ( V_2 ) >= 4 )
V_94 = F_6 ( F_75 ( V_28 -> V_37 ) ) ;
else
V_94 = F_6 ( V_95 ) ;
return V_94 ;
}
T_3 F_77 ( struct V_27 * V_28 )
{
struct V_1 * V_2 = V_28 -> V_9 ;
T_3 V_96 ;
if ( F_3 ( V_2 ) >= 8 )
V_96 = F_74 ( F_78 ( V_28 -> V_37 ) ,
F_79 ( V_28 -> V_37 ) ) ;
else
V_96 = F_6 ( F_78 ( V_28 -> V_37 ) ) ;
return V_96 ;
}
const char * F_80 ( struct V_1 * V_9 , int type )
{
switch ( type ) {
case V_97 : return L_4 ;
case V_98 : return F_81 ( V_9 ) ? L_5 : L_6 ;
case V_99 : return L_7 ;
case V_100 : return L_8 ;
default: return L_9 ;
}
}
static inline T_4
F_82 ( struct V_1 * V_2 , int V_101 ,
int V_102 , T_5 V_103 )
{
T_4 V_104 ;
T_4 V_80 ;
enum V_105 V_106 ;
V_106 = F_83 ( V_2 , V_103 ,
V_107 ) ;
V_106 |= F_83 ( V_2 ,
V_108 ,
V_107 | V_109 ) ;
F_84 ( & V_2 -> V_110 . V_111 ) ;
F_85 ( V_2 , V_106 ) ;
V_104 = F_86 ( V_108 ) ;
F_87 ( V_104 & ( V_112 | V_113 ) ) ;
V_104 &= ~ ( V_112 | V_113 ) ;
V_104 |= F_88 ( V_101 ) | F_89 ( V_102 ) ;
F_90 ( V_108 , V_104 ) ;
V_80 = F_86 ( V_103 ) ;
V_104 &= ~ ( V_112 | V_113 ) ;
F_90 ( V_108 , V_104 ) ;
F_91 ( V_2 , V_106 ) ;
F_92 ( & V_2 -> V_110 . V_111 ) ;
return V_80 ;
}
void F_93 ( struct V_27 * V_28 ,
struct V_114 * V_115 )
{
struct V_1 * V_2 = V_28 -> V_9 ;
T_1 V_37 = V_28 -> V_37 ;
int V_101 ;
int V_102 ;
memset ( V_115 , 0 , sizeof( * V_115 ) ) ;
switch ( F_3 ( V_2 ) ) {
default:
V_115 -> V_115 = F_6 ( F_94 ( V_37 ) ) ;
if ( V_28 -> V_21 != V_51 )
break;
V_115 -> V_116 = F_6 ( V_117 ) ;
F_95 (dev_priv, slice, subslice) {
V_115 -> V_118 [ V_101 ] [ V_102 ] =
F_82 ( V_2 , V_101 , V_102 ,
V_119 ) ;
V_115 -> V_120 [ V_101 ] [ V_102 ] =
F_82 ( V_2 , V_101 , V_102 ,
V_121 ) ;
}
break;
case 7 :
V_115 -> V_115 = F_6 ( F_94 ( V_37 ) ) ;
if ( V_28 -> V_21 != V_51 )
break;
V_115 -> V_116 = F_6 ( V_117 ) ;
V_115 -> V_118 [ 0 ] [ 0 ] = F_6 ( V_119 ) ;
V_115 -> V_120 [ 0 ] [ 0 ] = F_6 ( V_121 ) ;
break;
case 6 :
case 5 :
case 4 :
V_115 -> V_115 = F_6 ( F_94 ( V_37 ) ) ;
if ( V_28 -> V_21 == V_51 )
V_115 -> V_116 = F_6 ( V_122 ) ;
break;
case 3 :
case 2 :
V_115 -> V_115 = F_6 ( V_123 ) ;
break;
}
}
static int F_96 ( struct V_1 * V_2 ,
T_5 V_124 ,
const T_1 V_45 , const T_1 V_125 )
{
const T_1 V_126 = V_2 -> V_127 . V_128 ;
if ( F_14 ( V_126 >= V_129 ) )
return - V_130 ;
V_2 -> V_127 . V_103 [ V_126 ] . V_124 = V_124 ;
V_2 -> V_127 . V_103 [ V_126 ] . V_131 = V_125 ;
V_2 -> V_127 . V_103 [ V_126 ] . V_45 = V_45 ;
V_2 -> V_127 . V_128 ++ ;
return 0 ;
}
static int F_97 ( struct V_27 * V_28 ,
T_5 V_103 )
{
struct V_1 * V_2 = V_28 -> V_9 ;
struct V_132 * V_133 = & V_2 -> V_127 ;
const T_4 V_134 = V_133 -> V_135 [ V_28 -> V_21 ] ;
if ( F_14 ( V_134 >= V_136 ) )
return - V_137 ;
F_98 ( F_99 ( V_28 -> V_37 , V_134 ) ,
F_100 ( V_103 ) ) ;
V_133 -> V_135 [ V_28 -> V_21 ] ++ ;
return 0 ;
}
static int F_101 ( struct V_27 * V_28 )
{
struct V_1 * V_2 = V_28 -> V_9 ;
F_102 ( V_138 , V_139 ) ;
F_102 ( V_140 , V_141 ) ;
F_102 ( V_142 ,
V_143 ) ;
F_102 ( V_144 ,
V_145 |
V_146 ) ;
F_103 ( V_147 , V_148 ) ;
F_102 ( V_149 , V_150 ) ;
F_104 ( V_151 ,
V_152 ,
V_153 ) ;
return 0 ;
}
static int F_105 ( struct V_27 * V_28 )
{
struct V_1 * V_2 = V_28 -> V_9 ;
int V_80 ;
V_80 = F_101 ( V_28 ) ;
if ( V_80 )
return V_80 ;
F_102 ( V_142 , V_154 ) ;
F_102 ( V_155 ,
V_156 ) ;
F_102 ( V_157 ,
V_158 ) ;
F_102 ( V_144 ,
V_159 |
( F_106 ( V_2 ) ? V_160 : 0 ) ) ;
return 0 ;
}
static int F_107 ( struct V_27 * V_28 )
{
struct V_1 * V_2 = V_28 -> V_9 ;
int V_80 ;
V_80 = F_101 ( V_28 ) ;
if ( V_80 )
return V_80 ;
F_102 ( V_142 , V_154 ) ;
F_102 ( V_161 , V_162 ) ;
return 0 ;
}
static int F_108 ( struct V_27 * V_28 )
{
struct V_1 * V_2 = V_28 -> V_9 ;
int V_80 ;
F_33 ( V_163 , F_109 ( V_164 ) ) ;
F_33 ( V_165 , F_6 ( V_165 ) |
V_166 ) ;
if ( ! F_110 ( V_2 ) )
F_33 ( V_167 , F_6 ( V_167 ) |
V_168 ) ;
F_102 ( V_142 ,
V_169 |
V_143 ) ;
if ( ! F_110 ( V_2 ) )
F_102 ( V_157 ,
V_170 ) ;
if ( F_111 ( V_2 , 0 , V_171 ) )
F_103 ( V_172 ,
V_173 ) ;
if ( F_111 ( V_2 , 0 , V_171 ) ) {
F_102 ( V_174 ,
V_175 ) ;
}
F_102 ( V_176 ,
V_177 |
V_178 ) ;
F_102 ( V_149 , ( V_150 |
V_179 ) ) ;
F_103 ( V_172 ,
V_180 ) ;
if ( F_111 ( V_2 , 0 , V_171 ) )
F_102 ( V_181 ,
V_182 ) ;
F_102 ( V_144 ,
V_159 |
V_183 ) ;
F_102 ( V_144 ,
V_146 ) ;
F_33 ( V_167 , F_6 ( V_167 ) |
V_184 ) ;
if ( F_112 ( V_2 ) ||
F_113 ( V_2 ) ||
F_110 ( V_2 ) ||
F_111 ( V_2 , 0 , V_185 ) )
F_102 ( V_157 ,
V_158 ) ;
F_102 ( V_186 , V_187 ) ;
F_33 ( V_188 , ( F_6 ( V_188 ) |
V_189 ) ) ;
V_80 = F_97 ( V_28 , V_190 ) ;
if ( V_80 )
return V_80 ;
V_80 = F_97 ( V_28 , V_191 ) ;
if ( V_80 )
return V_80 ;
V_80 = F_97 ( V_28 , V_192 ) ;
if ( V_80 )
return V_80 ;
return 0 ;
}
static int F_114 ( struct V_27 * V_28 )
{
struct V_1 * V_2 = V_28 -> V_9 ;
T_2 V_193 [ 3 ] = { 0 , 0 , 0 } ;
unsigned int V_46 ;
for ( V_46 = 0 ; V_46 < 3 ; V_46 ++ ) {
T_2 V_194 ;
if ( ! F_115 ( F_19 ( V_2 ) -> V_195 . V_196 [ V_46 ] ) )
continue;
V_194 = F_116 ( F_19 ( V_2 ) -> V_195 . V_196 [ V_46 ] ) - 1 ;
V_193 [ V_46 ] = 3 - V_194 ;
}
if ( V_193 [ 0 ] == 0 && V_193 [ 1 ] == 0 && V_193 [ 2 ] == 0 )
return 0 ;
F_104 ( V_151 ,
F_117 ( 2 ) |
F_117 ( 1 ) |
F_117 ( 0 ) ,
F_118 ( 2 , V_193 [ 2 ] ) |
F_118 ( 1 , V_193 [ 1 ] ) |
F_118 ( 0 , V_193 [ 0 ] ) ) ;
return 0 ;
}
static int F_119 ( struct V_27 * V_28 )
{
struct V_1 * V_2 = V_28 -> V_9 ;
int V_80 ;
V_80 = F_108 ( V_28 ) ;
if ( V_80 )
return V_80 ;
F_33 ( V_197 ,
F_109 ( V_198 ) ) ;
F_33 ( V_199 , ( F_6 ( V_199 ) |
V_200 ) ) ;
F_120 ( V_201 , V_202 ) ;
if ( F_121 ( V_2 , V_203 , V_204 ) )
F_120 ( V_205 ,
V_206 ) ;
V_80 = F_97 ( V_28 , V_188 ) ;
if ( V_80 )
return V_80 ;
return F_114 ( V_28 ) ;
}
static int F_122 ( struct V_27 * V_28 )
{
struct V_1 * V_2 = V_28 -> V_9 ;
int V_80 ;
V_80 = F_108 ( V_28 ) ;
if ( V_80 )
return V_80 ;
if ( F_111 ( V_2 , 0 , V_171 ) )
F_33 ( V_207 , F_6 ( V_207 ) | V_208 ) ;
if ( F_111 ( V_2 , 0 , V_171 ) ) {
F_33 ( V_209 , ( F_6 ( V_209 ) &
~ V_210 ) ) ;
}
F_102 ( V_142 ,
V_154 ) ;
if ( F_111 ( V_2 , V_185 , V_204 ) ) {
F_102 ( V_211 ,
V_212 ) ;
}
if ( F_111 ( V_2 , 0 , V_185 ) ) {
F_102 (
V_213 ,
V_214 ) ;
}
if ( F_111 ( V_2 , 0 , V_171 ) ) {
V_80 = F_97 ( V_28 , V_215 ) ;
if ( V_80 )
return V_80 ;
V_80 = F_97 ( V_28 , V_188 ) ;
if ( V_80 )
return V_80 ;
}
if ( F_111 ( V_2 , V_185 , V_204 ) )
F_33 ( V_216 , F_123 ( 62 ) |
F_124 ( 2 ) ) ;
if ( F_111 ( V_2 , V_217 , V_204 ) )
F_102 ( V_218 ,
V_219 ) ;
if ( F_111 ( V_2 , V_217 , V_204 ) )
F_120 ( V_205 ,
V_206 ) ;
return 0 ;
}
static int F_125 ( struct V_27 * V_28 )
{
struct V_1 * V_2 = V_28 -> V_9 ;
int V_80 ;
V_80 = F_108 ( V_28 ) ;
if ( V_80 )
return V_80 ;
F_33 ( V_199 , ( F_6 ( V_199 ) |
V_200 ) ) ;
if ( F_126 ( V_2 , 0 , V_220 ) )
F_120 ( V_221 ,
V_222 ) ;
if ( F_126 ( V_2 , V_223 , V_223 ) )
F_102 ( V_144 ,
V_160 ) ;
if ( F_126 ( V_2 , V_224 , V_204 ) )
F_102 ( V_218 ,
V_219 ) ;
F_120 ( V_201 , V_202 ) ;
F_102 (
V_213 ,
V_214 ) ;
F_120 ( V_205 ,
V_206 ) ;
V_80 = F_97 ( V_28 , V_188 ) ;
if ( V_80 )
return V_80 ;
return 0 ;
}
static int F_127 ( struct V_27 * V_28 )
{
struct V_1 * V_2 = V_28 -> V_9 ;
int V_80 ;
V_80 = F_108 ( V_28 ) ;
if ( V_80 )
return V_80 ;
F_102 ( V_218 ,
V_219 ) ;
return 0 ;
}
static int F_128 ( struct V_27 * V_28 )
{
struct V_1 * V_2 = V_28 -> V_9 ;
int V_80 ;
V_80 = F_108 ( V_28 ) ;
if ( V_80 )
return V_80 ;
F_33 ( V_199 , ( F_6 ( V_199 ) |
V_200 ) ) ;
F_102 ( V_218 ,
V_219 ) ;
F_120 ( V_201 , V_202 ) ;
F_102 (
V_213 ,
V_214 ) ;
F_120 ( V_205 ,
V_206 ) ;
return 0 ;
}
int F_129 ( struct V_27 * V_28 )
{
struct V_1 * V_2 = V_28 -> V_9 ;
int V_47 ;
F_14 ( V_28 -> V_21 != V_51 ) ;
V_2 -> V_127 . V_128 = 0 ;
V_2 -> V_127 . V_135 [ V_28 -> V_21 ] = 0 ;
if ( F_130 ( V_2 ) )
V_47 = F_105 ( V_28 ) ;
else if ( F_131 ( V_2 ) )
V_47 = F_107 ( V_28 ) ;
else if ( F_112 ( V_2 ) )
V_47 = F_119 ( V_28 ) ;
else if ( F_132 ( V_2 ) )
V_47 = F_122 ( V_28 ) ;
else if ( F_113 ( V_2 ) )
V_47 = F_125 ( V_28 ) ;
else if ( F_133 ( V_2 ) )
V_47 = F_127 ( V_28 ) ;
else if ( F_110 ( V_2 ) )
V_47 = F_128 ( V_28 ) ;
else
V_47 = 0 ;
if ( V_47 )
return V_47 ;
F_60 ( L_10 ,
V_28 -> V_32 , V_2 -> V_127 . V_128 ) ;
return 0 ;
}
int F_134 ( struct V_225 * V_226 )
{
struct V_132 * V_227 = & V_226 -> V_9 -> V_127 ;
T_1 * V_228 ;
int V_80 , V_46 ;
if ( V_227 -> V_128 == 0 )
return 0 ;
V_80 = V_226 -> V_28 -> V_229 ( V_226 , V_230 ) ;
if ( V_80 )
return V_80 ;
V_228 = F_135 ( V_226 , ( V_227 -> V_128 * 2 + 2 ) ) ;
if ( F_55 ( V_228 ) )
return F_57 ( V_228 ) ;
* V_228 ++ = F_136 ( V_227 -> V_128 ) ;
for ( V_46 = 0 ; V_46 < V_227 -> V_128 ; V_46 ++ ) {
* V_228 ++ = F_100 ( V_227 -> V_103 [ V_46 ] . V_124 ) ;
* V_228 ++ = V_227 -> V_103 [ V_46 ] . V_131 ;
}
* V_228 ++ = V_231 ;
F_137 ( V_226 , V_228 ) ;
V_80 = V_226 -> V_28 -> V_229 ( V_226 , V_230 ) ;
if ( V_80 )
return V_80 ;
return 0 ;
}
static bool F_138 ( struct V_27 * V_28 )
{
struct V_1 * V_2 = V_28 -> V_9 ;
bool V_232 = true ;
F_139 ( V_2 ) ;
if ( ( F_140 ( V_28 ) & V_233 ) !=
( F_141 ( V_28 ) & V_234 ) )
V_232 = false ;
if ( F_3 ( V_2 ) > 2 && ! ( F_142 ( V_28 ) & V_235 ) )
V_232 = false ;
F_143 ( V_2 ) ;
return V_232 ;
}
bool F_29 ( struct V_27 * V_28 )
{
struct V_1 * V_2 = V_28 -> V_9 ;
if ( F_144 ( & V_2 -> V_236 ) )
return true ;
if ( ! F_145 ( F_46 ( V_28 ) ,
F_146 ( V_28 ) ) )
return false ;
if ( F_147 ( V_28 -> V_237 . V_238 ) )
return true ;
if ( F_148 ( V_239 , & V_28 -> V_69 ) )
return false ;
if ( F_149 ( & V_28 -> V_240 [ 0 ] ) )
return false ;
if ( ! F_138 ( V_28 ) )
return false ;
return true ;
}
bool F_150 ( struct V_1 * V_2 )
{
struct V_27 * V_28 ;
enum V_20 V_21 ;
if ( F_151 ( V_2 -> V_58 . V_241 ) )
return false ;
if ( F_144 ( & V_2 -> V_236 ) )
return true ;
F_24 (engine, dev_priv, id) {
if ( ! F_29 ( V_28 ) )
return false ;
}
return true ;
}
void F_152 ( struct V_1 * V_9 )
{
struct V_27 * V_28 ;
enum V_20 V_21 ;
F_24 (engine, i915, id)
V_28 -> V_89 ( V_28 ) ;
}
void F_153 ( struct V_1 * V_9 )
{
struct V_27 * V_28 ;
enum V_20 V_21 ;
F_24 (engine, i915, id) {
F_154 ( V_28 ) ;
F_72 ( & V_28 -> V_74 ) ;
V_28 -> V_242 = false ;
}
}
