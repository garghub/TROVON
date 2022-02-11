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
case 10 :
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
struct V_27 * V_28 ;
enum V_20 V_21 , V_54 ;
int V_47 ;
F_24 (engine, dev_priv, id) {
const struct V_25 * V_26 =
& V_29 [ V_28 -> V_3 ] ;
int (* F_27)( struct V_27 * V_28 );
if ( V_9 . V_10 )
F_27 = V_26 -> V_55 ;
else
F_27 = V_26 -> V_56 ;
V_47 = - V_57 ;
V_54 = V_21 ;
if ( F_28 ( ! F_27 ) )
goto V_50;
V_47 = F_27 ( V_28 ) ;
if ( V_47 )
goto V_50;
F_11 ( ! V_28 -> V_58 ) ;
}
return 0 ;
V_50:
F_24 (engine, dev_priv, id) {
if ( V_21 >= V_54 ) {
F_25 ( V_28 ) ;
V_2 -> V_28 [ V_21 ] = NULL ;
} else {
V_2 -> V_59 . V_60 ( V_28 ) ;
}
}
return V_47 ;
}
void F_29 ( struct V_27 * V_28 , T_1 V_61 )
{
struct V_1 * V_2 = V_28 -> V_9 ;
if ( F_30 ( V_2 ) || F_31 ( V_2 ) ) {
F_32 ( F_33 ( V_28 -> V_37 ) , 0 ) ;
F_32 ( F_34 ( V_28 -> V_37 ) , 0 ) ;
if ( F_35 ( V_2 ) )
F_32 ( F_36 ( V_28 -> V_37 ) , 0 ) ;
}
if ( V_2 -> V_62 ) {
struct V_63 * V_63 = F_37 ( V_2 -> V_62 ) ;
void * V_64 ;
V_64 = F_38 ( V_63 ) ;
memset ( V_64 + F_39 ( V_28 -> V_21 , 0 ) ,
0 , V_49 * V_65 ) ;
F_40 ( V_64 + F_39 ( V_28 -> V_21 , 0 ) ,
V_49 * V_65 ) ;
F_41 ( V_64 ) ;
}
F_42 ( V_28 , V_66 , V_61 ) ;
F_43 ( V_67 , & V_28 -> V_68 ) ;
F_44 ( V_28 ) ;
F_11 ( F_45 ( V_28 ) != V_61 ) ;
}
static void F_46 ( struct V_27 * V_28 )
{
V_28 -> V_69 = & V_28 -> V_9 -> V_59 . V_70 . V_28 [ V_28 -> V_21 ] ;
}
void F_47 ( struct V_27 * V_28 )
{
V_28 -> V_71 = V_72 ;
V_28 -> V_73 = NULL ;
F_46 ( V_28 ) ;
F_48 ( V_28 ) ;
F_49 ( V_28 , & V_28 -> V_74 ) ;
F_50 ( V_28 ) ;
}
int F_51 ( struct V_27 * V_28 , int V_75 )
{
struct V_76 * V_77 ;
struct V_78 * V_79 ;
int V_80 ;
F_14 ( V_28 -> V_81 ) ;
V_77 = F_52 ( V_28 -> V_9 , V_75 ) ;
if ( ! V_77 )
V_77 = F_53 ( V_28 -> V_9 , V_75 ) ;
if ( F_54 ( V_77 ) ) {
F_55 ( L_2 ) ;
return F_56 ( V_77 ) ;
}
V_79 = F_57 ( V_77 , & V_28 -> V_9 -> V_82 . V_83 , NULL ) ;
if ( F_54 ( V_79 ) ) {
V_80 = F_56 ( V_79 ) ;
goto V_84;
}
V_80 = F_58 ( V_79 , 0 , 4096 , V_85 | V_86 ) ;
if ( V_80 )
goto V_84;
V_28 -> V_81 = V_79 ;
F_59 ( L_3 ,
V_28 -> V_32 , F_60 ( V_79 ) ) ;
return 0 ;
V_84:
F_61 ( V_77 ) ;
return V_80 ;
}
static void F_62 ( struct V_27 * V_28 )
{
F_63 ( & V_28 -> V_81 ) ;
}
int F_64 ( struct V_27 * V_28 )
{
struct V_87 * V_88 ;
int V_80 ;
V_28 -> V_89 ( V_28 ) ;
V_88 = V_28 -> V_90 ( V_28 , V_28 -> V_9 -> V_91 ) ;
if ( F_54 ( V_88 ) )
return F_56 ( V_88 ) ;
V_80 = F_65 ( V_28 ) ;
if ( V_80 )
goto V_92;
V_80 = F_66 ( V_28 ) ;
if ( V_80 )
goto V_92;
return 0 ;
V_92:
V_28 -> V_93 ( V_28 , V_28 -> V_9 -> V_91 ) ;
return V_80 ;
}
void F_67 ( struct V_27 * V_28 )
{
F_62 ( V_28 ) ;
F_68 ( V_28 ) ;
F_69 ( V_28 ) ;
F_70 ( V_28 ) ;
F_71 ( & V_28 -> V_74 ) ;
V_28 -> V_93 ( V_28 , V_28 -> V_9 -> V_91 ) ;
}
T_3 F_72 ( struct V_27 * V_28 )
{
struct V_1 * V_2 = V_28 -> V_9 ;
T_3 V_94 ;
if ( F_3 ( V_2 ) >= 8 )
V_94 = F_73 ( F_74 ( V_28 -> V_37 ) ,
F_75 ( V_28 -> V_37 ) ) ;
else if ( F_3 ( V_2 ) >= 4 )
V_94 = F_6 ( F_74 ( V_28 -> V_37 ) ) ;
else
V_94 = F_6 ( V_95 ) ;
return V_94 ;
}
T_3 F_76 ( struct V_27 * V_28 )
{
struct V_1 * V_2 = V_28 -> V_9 ;
T_3 V_96 ;
if ( F_3 ( V_2 ) >= 8 )
V_96 = F_73 ( F_77 ( V_28 -> V_37 ) ,
F_78 ( V_28 -> V_37 ) ) ;
else
V_96 = F_6 ( F_77 ( V_28 -> V_37 ) ) ;
return V_96 ;
}
const char * F_79 ( struct V_1 * V_9 , int type )
{
switch ( type ) {
case V_97 : return L_4 ;
case V_98 : return F_80 ( V_9 ) ? L_5 : L_6 ;
case V_99 : return L_7 ;
case V_100 : return L_8 ;
default: return L_9 ;
}
}
static inline T_4
F_81 ( struct V_1 * V_2 , int V_101 ,
int V_102 , T_5 V_103 )
{
T_4 V_104 ;
T_4 V_80 ;
enum V_105 V_106 ;
V_106 = F_82 ( V_2 , V_103 ,
V_107 ) ;
V_106 |= F_82 ( V_2 ,
V_108 ,
V_107 | V_109 ) ;
F_83 ( & V_2 -> V_110 . V_111 ) ;
F_84 ( V_2 , V_106 ) ;
V_104 = F_85 ( V_108 ) ;
F_86 ( V_104 & ( V_112 | V_113 ) ) ;
V_104 &= ~ ( V_112 | V_113 ) ;
V_104 |= F_87 ( V_101 ) | F_88 ( V_102 ) ;
F_89 ( V_108 , V_104 ) ;
V_80 = F_85 ( V_103 ) ;
V_104 &= ~ ( V_112 | V_113 ) ;
F_89 ( V_108 , V_104 ) ;
F_90 ( V_2 , V_106 ) ;
F_91 ( & V_2 -> V_110 . V_111 ) ;
return V_80 ;
}
void F_92 ( struct V_27 * V_28 ,
struct V_114 * V_115 )
{
struct V_1 * V_2 = V_28 -> V_9 ;
T_1 V_37 = V_28 -> V_37 ;
int V_101 ;
int V_102 ;
memset ( V_115 , 0 , sizeof( * V_115 ) ) ;
switch ( F_3 ( V_2 ) ) {
default:
V_115 -> V_115 = F_6 ( F_93 ( V_37 ) ) ;
if ( V_28 -> V_21 != V_51 )
break;
V_115 -> V_116 = F_6 ( V_117 ) ;
F_94 (dev_priv, slice, subslice) {
V_115 -> V_118 [ V_101 ] [ V_102 ] =
F_81 ( V_2 , V_101 , V_102 ,
V_119 ) ;
V_115 -> V_120 [ V_101 ] [ V_102 ] =
F_81 ( V_2 , V_101 , V_102 ,
V_121 ) ;
}
break;
case 7 :
V_115 -> V_115 = F_6 ( F_93 ( V_37 ) ) ;
if ( V_28 -> V_21 != V_51 )
break;
V_115 -> V_116 = F_6 ( V_117 ) ;
V_115 -> V_118 [ 0 ] [ 0 ] = F_6 ( V_119 ) ;
V_115 -> V_120 [ 0 ] [ 0 ] = F_6 ( V_121 ) ;
break;
case 6 :
case 5 :
case 4 :
V_115 -> V_115 = F_6 ( F_93 ( V_37 ) ) ;
if ( V_28 -> V_21 == V_51 )
V_115 -> V_116 = F_6 ( V_122 ) ;
break;
case 3 :
case 2 :
V_115 -> V_115 = F_6 ( V_123 ) ;
break;
}
}
static int F_95 ( struct V_1 * V_2 ,
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
static int F_96 ( struct V_27 * V_28 ,
T_5 V_103 )
{
struct V_1 * V_2 = V_28 -> V_9 ;
struct V_132 * V_133 = & V_2 -> V_127 ;
const T_4 V_134 = V_133 -> V_135 [ V_28 -> V_21 ] ;
if ( F_14 ( V_134 >= V_136 ) )
return - V_57 ;
F_97 ( F_98 ( V_28 -> V_37 , V_134 ) ,
F_99 ( V_103 ) ) ;
V_133 -> V_135 [ V_28 -> V_21 ] ++ ;
return 0 ;
}
static int F_100 ( struct V_27 * V_28 )
{
struct V_1 * V_2 = V_28 -> V_9 ;
F_101 ( V_137 , V_138 ) ;
F_101 ( V_139 , V_140 ) ;
F_101 ( V_141 ,
V_142 ) ;
F_101 ( V_143 ,
V_144 |
V_145 ) ;
F_102 ( V_146 , V_147 ) ;
F_101 ( V_148 , V_149 ) ;
F_103 ( V_150 ,
V_151 ,
V_152 ) ;
return 0 ;
}
static int F_104 ( struct V_27 * V_28 )
{
struct V_1 * V_2 = V_28 -> V_9 ;
int V_80 ;
V_80 = F_100 ( V_28 ) ;
if ( V_80 )
return V_80 ;
F_101 ( V_141 , V_153 ) ;
F_101 ( V_154 ,
V_155 ) ;
F_101 ( V_156 ,
V_157 ) ;
F_101 ( V_143 ,
V_158 |
( F_105 ( V_2 ) ? V_159 : 0 ) ) ;
return 0 ;
}
static int F_106 ( struct V_27 * V_28 )
{
struct V_1 * V_2 = V_28 -> V_9 ;
int V_80 ;
V_80 = F_100 ( V_28 ) ;
if ( V_80 )
return V_80 ;
F_101 ( V_141 , V_153 ) ;
F_101 ( V_160 , V_161 ) ;
return 0 ;
}
static int F_107 ( struct V_27 * V_28 )
{
struct V_1 * V_2 = V_28 -> V_9 ;
int V_80 ;
F_32 ( V_162 , F_108 ( V_163 ) ) ;
F_32 ( V_164 , F_6 ( V_164 ) |
V_165 ) ;
if ( ! F_109 ( V_2 ) )
F_32 ( V_166 , F_6 ( V_166 ) |
V_167 ) ;
F_101 ( V_141 ,
V_168 |
V_142 ) ;
if ( ! F_109 ( V_2 ) )
F_101 ( V_156 ,
V_169 ) ;
if ( F_110 ( V_2 , 0 , V_170 ) )
F_102 ( V_171 ,
V_172 ) ;
if ( F_110 ( V_2 , 0 , V_170 ) ) {
F_101 ( V_173 ,
V_174 ) ;
}
F_101 ( V_175 ,
V_176 |
V_177 ) ;
F_101 ( V_148 , ( V_149 |
V_178 ) ) ;
F_102 ( V_171 ,
V_179 ) ;
if ( F_110 ( V_2 , 0 , V_170 ) )
F_101 ( V_180 ,
V_181 ) ;
F_101 ( V_143 ,
V_158 |
V_182 ) ;
F_101 ( V_143 ,
V_145 ) ;
F_32 ( V_166 , F_6 ( V_166 ) |
V_183 ) ;
if ( F_111 ( V_2 ) ||
F_112 ( V_2 ) ||
F_109 ( V_2 ) ||
F_110 ( V_2 , 0 , V_184 ) )
F_101 ( V_156 ,
V_157 ) ;
F_101 ( V_185 , V_186 ) ;
F_32 ( V_187 , ( F_6 ( V_187 ) |
V_188 ) ) ;
V_80 = F_96 ( V_28 , V_189 ) ;
if ( V_80 )
return V_80 ;
V_80 = F_96 ( V_28 , V_190 ) ;
if ( V_80 )
return V_80 ;
V_80 = F_96 ( V_28 , V_191 ) ;
if ( V_80 )
return V_80 ;
return 0 ;
}
static int F_113 ( struct V_27 * V_28 )
{
struct V_1 * V_2 = V_28 -> V_9 ;
T_2 V_192 [ 3 ] = { 0 , 0 , 0 } ;
unsigned int V_46 ;
for ( V_46 = 0 ; V_46 < 3 ; V_46 ++ ) {
T_2 V_193 ;
if ( ! F_114 ( F_19 ( V_2 ) -> V_194 . V_195 [ V_46 ] ) )
continue;
V_193 = F_115 ( F_19 ( V_2 ) -> V_194 . V_195 [ V_46 ] ) - 1 ;
V_192 [ V_46 ] = 3 - V_193 ;
}
if ( V_192 [ 0 ] == 0 && V_192 [ 1 ] == 0 && V_192 [ 2 ] == 0 )
return 0 ;
F_103 ( V_150 ,
F_116 ( 2 ) |
F_116 ( 1 ) |
F_116 ( 0 ) ,
F_117 ( 2 , V_192 [ 2 ] ) |
F_117 ( 1 , V_192 [ 1 ] ) |
F_117 ( 0 , V_192 [ 0 ] ) ) ;
return 0 ;
}
static int F_118 ( struct V_27 * V_28 )
{
struct V_1 * V_2 = V_28 -> V_9 ;
int V_80 ;
V_80 = F_107 ( V_28 ) ;
if ( V_80 )
return V_80 ;
F_32 ( V_196 ,
F_108 ( V_197 ) ) ;
F_32 ( V_198 , ( F_6 ( V_198 ) |
V_199 ) ) ;
F_119 ( V_200 , V_201 ) ;
if ( F_120 ( V_2 , V_202 , V_203 ) )
F_119 ( V_204 ,
V_205 ) ;
V_80 = F_96 ( V_28 , V_187 ) ;
if ( V_80 )
return V_80 ;
return F_113 ( V_28 ) ;
}
static int F_121 ( struct V_27 * V_28 )
{
struct V_1 * V_2 = V_28 -> V_9 ;
int V_80 ;
V_80 = F_107 ( V_28 ) ;
if ( V_80 )
return V_80 ;
if ( F_110 ( V_2 , 0 , V_170 ) )
F_32 ( V_206 , F_6 ( V_206 ) | V_207 ) ;
if ( F_110 ( V_2 , 0 , V_170 ) ) {
F_32 ( V_208 , ( F_6 ( V_208 ) &
~ V_209 ) ) ;
}
F_101 ( V_141 ,
V_153 ) ;
if ( F_110 ( V_2 , V_184 , V_203 ) ) {
F_101 ( V_210 ,
V_211 ) ;
}
if ( F_110 ( V_2 , 0 , V_184 ) ) {
F_101 (
V_212 ,
V_213 ) ;
}
if ( F_110 ( V_2 , 0 , V_170 ) ) {
V_80 = F_96 ( V_28 , V_214 ) ;
if ( V_80 )
return V_80 ;
V_80 = F_96 ( V_28 , V_187 ) ;
if ( V_80 )
return V_80 ;
}
if ( F_110 ( V_2 , V_184 , V_203 ) ) {
T_1 V_125 = F_6 ( V_215 ) ;
V_125 &= ~ V_216 ;
V_125 |= F_122 ( 62 ) | F_123 ( 2 ) ;
F_32 ( V_215 , V_125 ) ;
}
if ( F_110 ( V_2 , V_217 , V_203 ) )
F_101 ( V_218 ,
V_219 ) ;
if ( F_110 ( V_2 , V_217 , V_203 ) )
F_119 ( V_204 ,
V_205 ) ;
return 0 ;
}
static int F_124 ( struct V_27 * V_28 )
{
struct V_1 * V_2 = V_28 -> V_9 ;
int V_80 ;
V_80 = F_107 ( V_28 ) ;
if ( V_80 )
return V_80 ;
F_32 ( V_198 , ( F_6 ( V_198 ) |
V_199 ) ) ;
if ( F_125 ( V_2 , 0 , V_220 ) )
F_119 ( V_221 ,
V_222 ) ;
if ( F_125 ( V_2 , V_223 , V_223 ) )
F_101 ( V_143 ,
V_159 ) ;
if ( F_125 ( V_2 , V_224 , V_203 ) )
F_101 ( V_218 ,
V_219 ) ;
F_119 ( V_200 , V_201 ) ;
F_101 (
V_212 ,
V_213 ) ;
F_119 ( V_204 ,
V_205 ) ;
V_80 = F_96 ( V_28 , V_187 ) ;
if ( V_80 )
return V_80 ;
return 0 ;
}
static int F_126 ( struct V_27 * V_28 )
{
struct V_1 * V_2 = V_28 -> V_9 ;
int V_80 ;
V_80 = F_107 ( V_28 ) ;
if ( V_80 )
return V_80 ;
F_101 ( V_218 ,
V_219 ) ;
return 0 ;
}
static int F_127 ( struct V_27 * V_28 )
{
struct V_1 * V_2 = V_28 -> V_9 ;
int V_80 ;
V_80 = F_107 ( V_28 ) ;
if ( V_80 )
return V_80 ;
F_32 ( V_198 , ( F_6 ( V_198 ) |
V_199 ) ) ;
F_101 ( V_218 ,
V_219 ) ;
F_119 ( V_200 , V_201 ) ;
F_101 (
V_212 ,
V_213 ) ;
F_119 ( V_204 ,
V_205 ) ;
return 0 ;
}
int F_128 ( struct V_27 * V_28 )
{
struct V_1 * V_2 = V_28 -> V_9 ;
int V_47 ;
F_14 ( V_28 -> V_21 != V_51 ) ;
V_2 -> V_127 . V_128 = 0 ;
V_2 -> V_127 . V_135 [ V_28 -> V_21 ] = 0 ;
if ( F_129 ( V_2 ) )
V_47 = F_104 ( V_28 ) ;
else if ( F_130 ( V_2 ) )
V_47 = F_106 ( V_28 ) ;
else if ( F_111 ( V_2 ) )
V_47 = F_118 ( V_28 ) ;
else if ( F_131 ( V_2 ) )
V_47 = F_121 ( V_28 ) ;
else if ( F_112 ( V_2 ) )
V_47 = F_124 ( V_28 ) ;
else if ( F_132 ( V_2 ) )
V_47 = F_126 ( V_28 ) ;
else if ( F_109 ( V_2 ) )
V_47 = F_127 ( V_28 ) ;
else
V_47 = 0 ;
if ( V_47 )
return V_47 ;
F_59 ( L_10 ,
V_28 -> V_32 , V_2 -> V_127 . V_128 ) ;
return 0 ;
}
int F_133 ( struct V_225 * V_226 )
{
struct V_132 * V_227 = & V_226 -> V_9 -> V_127 ;
T_1 * V_228 ;
int V_80 , V_46 ;
if ( V_227 -> V_128 == 0 )
return 0 ;
V_80 = V_226 -> V_28 -> V_229 ( V_226 , V_230 ) ;
if ( V_80 )
return V_80 ;
V_228 = F_134 ( V_226 , ( V_227 -> V_128 * 2 + 2 ) ) ;
if ( F_54 ( V_228 ) )
return F_56 ( V_228 ) ;
* V_228 ++ = F_135 ( V_227 -> V_128 ) ;
for ( V_46 = 0 ; V_46 < V_227 -> V_128 ; V_46 ++ ) {
* V_228 ++ = F_99 ( V_227 -> V_103 [ V_46 ] . V_124 ) ;
* V_228 ++ = V_227 -> V_103 [ V_46 ] . V_131 ;
}
* V_228 ++ = V_231 ;
F_136 ( V_226 , V_228 ) ;
V_80 = V_226 -> V_28 -> V_229 ( V_226 , V_230 ) ;
if ( V_80 )
return V_80 ;
return 0 ;
}
static bool F_137 ( struct V_27 * V_28 )
{
struct V_1 * V_2 = V_28 -> V_9 ;
bool V_232 = true ;
F_138 ( V_2 ) ;
if ( ( F_139 ( V_28 ) & V_233 ) !=
( F_140 ( V_28 ) & V_234 ) )
V_232 = false ;
if ( F_3 ( V_2 ) > 2 && ! ( F_141 ( V_28 ) & V_235 ) )
V_232 = false ;
F_142 ( V_2 ) ;
return V_232 ;
}
bool F_143 ( struct V_27 * V_28 )
{
struct V_1 * V_2 = V_28 -> V_9 ;
if ( F_144 ( & V_2 -> V_236 ) )
return true ;
if ( ! F_145 ( F_45 ( V_28 ) ,
F_146 ( V_28 ) ) )
return false ;
if ( F_147 ( V_28 -> V_237 . V_238 ) )
return true ;
if ( F_148 ( V_239 , & V_28 -> V_68 ) )
return false ;
if ( F_149 ( & V_28 -> V_240 [ 0 ] ) )
return false ;
if ( F_150 ( V_28 -> V_73 ) )
return false ;
if ( ! F_137 ( V_28 ) )
return false ;
return true ;
}
bool F_151 ( struct V_1 * V_2 )
{
struct V_27 * V_28 ;
enum V_20 V_21 ;
if ( F_150 ( V_2 -> V_59 . V_241 ) )
return false ;
if ( F_144 ( & V_2 -> V_236 ) )
return true ;
F_24 (engine, dev_priv, id) {
if ( ! F_143 ( V_28 ) )
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
F_71 ( & V_28 -> V_74 ) ;
F_155 ( & V_28 -> V_242 ) ;
V_28 -> V_243 = false ;
}
}
