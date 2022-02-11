STATIC int
F_1 ( const T_1 * V_1 , unsigned int V_2 , int * V_3 )
{
int V_4 , V_5 = 0 , V_6 ;
char * V_7 ;
int V_8 = 0 ;
V_7 = F_2 ( V_1 ) ;
if ( ! V_7 )
return - V_9 ;
V_4 = strlen ( V_7 ) - 1 ;
if ( V_7 [ V_4 ] == 'K' || V_7 [ V_4 ] == 'k' ) {
V_5 = 10 ;
V_7 [ V_4 ] = '\0' ;
}
if ( V_7 [ V_4 ] == 'M' || V_7 [ V_4 ] == 'm' ) {
V_5 = 20 ;
V_7 [ V_4 ] = '\0' ;
}
if ( V_7 [ V_4 ] == 'G' || V_7 [ V_4 ] == 'g' ) {
V_5 = 30 ;
V_7 [ V_4 ] = '\0' ;
}
if ( F_3 ( V_7 , V_2 , & V_6 ) )
V_8 = - V_10 ;
F_4 ( V_7 ) ;
* V_3 = V_6 << V_5 ;
return V_8 ;
}
STATIC int
F_5 (
struct V_11 * V_12 ,
char * V_13 )
{
const struct V_14 * V_15 = V_12 -> V_16 ;
char * V_17 ;
T_1 args [ V_18 ] ;
int V_19 = 0 ;
int V_20 = 0 ;
int V_21 = 0 ;
T_2 V_22 = 0 ;
V_12 -> V_23 = F_6 ( V_15 -> V_24 , V_25 , V_26 ) ;
if ( ! V_12 -> V_23 )
return - V_9 ;
V_12 -> V_27 = strlen ( V_12 -> V_23 ) + 1 ;
if ( V_15 -> V_28 & V_29 )
V_12 -> V_30 |= V_31 ;
if ( V_15 -> V_28 & V_32 )
V_12 -> V_30 |= V_33 ;
if ( V_15 -> V_28 & V_34 )
V_12 -> V_30 |= V_35 ;
V_12 -> V_30 |= V_36 ;
V_12 -> V_30 |= V_37 ;
V_12 -> V_38 = - 1 ;
V_12 -> V_39 = - 1 ;
if ( ! V_13 )
goto V_40;
while ( ( V_17 = F_7 ( & V_13 , L_1 ) ) != NULL ) {
int V_41 ;
if ( ! * V_17 )
continue;
V_41 = F_8 ( V_17 , V_42 , args ) ;
switch ( V_41 ) {
case V_43 :
if ( F_9 ( args , & V_12 -> V_38 ) )
return - V_10 ;
break;
case V_44 :
if ( F_1 ( args , 10 , & V_12 -> V_39 ) )
return - V_10 ;
break;
case V_45 :
V_12 -> V_46 = F_2 ( args ) ;
if ( ! V_12 -> V_46 )
return - V_9 ;
break;
case V_47 :
F_10 ( V_12 , L_2 , V_17 ) ;
return - V_10 ;
case V_48 :
V_12 -> V_49 = F_2 ( args ) ;
if ( ! V_12 -> V_49 )
return - V_9 ;
break;
case V_50 :
case V_51 :
if ( F_1 ( args , 10 , & V_21 ) )
return - V_10 ;
V_22 = F_11 ( V_21 ) - 1 ;
break;
case V_52 :
case V_53 :
V_12 -> V_30 |= V_54 ;
break;
case V_55 :
case V_56 :
V_12 -> V_30 &= ~ V_54 ;
break;
case V_57 :
V_12 -> V_30 |= V_35 ;
break;
case V_58 :
V_12 -> V_30 |= V_59 ;
break;
case V_60 :
V_12 -> V_30 |= V_61 ;
break;
case V_62 :
V_12 -> V_30 |= V_63 ;
break;
case V_64 :
if ( F_9 ( args , & V_19 ) )
return - V_10 ;
break;
case V_65 :
if ( F_9 ( args , & V_20 ) )
return - V_10 ;
break;
case V_66 :
V_12 -> V_30 |= V_67 ;
break;
case V_68 :
V_12 -> V_30 &= ~ V_67 ;
break;
case V_69 :
V_12 -> V_30 |= V_70 ;
break;
case V_71 :
V_12 -> V_30 |= V_36 ;
break;
case V_72 :
V_12 -> V_30 &= ~ V_36 ;
break;
case V_73 :
V_12 -> V_30 |= V_74 ;
break;
case V_75 :
V_12 -> V_30 &= ~ V_74 ;
break;
case V_76 :
V_12 -> V_30 &= ~ V_37 ;
break;
case V_77 :
V_12 -> V_30 |= V_37 ;
break;
case V_78 :
V_12 -> V_30 |= V_79 ;
break;
case V_80 :
V_12 -> V_30 &= ~ V_79 ;
V_12 -> V_30 |= V_81 ;
break;
case V_82 :
V_12 -> V_30 |= V_83 ;
break;
case V_84 :
V_12 -> V_85 &= ~ V_86 ;
V_12 -> V_85 &= ~ V_87 ;
V_12 -> V_85 &= ~ V_88 ;
break;
case V_89 :
case V_90 :
case V_91 :
V_12 -> V_85 |= ( V_92 | V_93 |
V_94 ) ;
break;
case V_95 :
case V_96 :
V_12 -> V_85 |= ( V_92 | V_93 ) ;
V_12 -> V_85 &= ~ V_94 ;
break;
case V_97 :
case V_98 :
V_12 -> V_85 |= ( V_99 | V_100 |
V_101 ) ;
break;
case V_102 :
V_12 -> V_85 |= ( V_99 | V_100 ) ;
V_12 -> V_85 &= ~ V_101 ;
break;
case V_103 :
case V_104 :
V_12 -> V_85 |= ( V_105 | V_106 |
V_107 ) ;
break;
case V_108 :
V_12 -> V_85 |= ( V_105 | V_106 ) ;
V_12 -> V_85 &= ~ V_107 ;
break;
case V_109 :
V_12 -> V_30 |= V_110 ;
break;
case V_111 :
V_12 -> V_30 &= ~ V_110 ;
break;
#ifdef F_12
case V_112 :
V_12 -> V_30 |= V_113 ;
break;
#endif
default:
F_10 ( V_12 , L_3 , V_17 ) ;
return - V_10 ;
}
}
if ( ( V_12 -> V_30 & V_59 ) &&
! ( V_12 -> V_30 & V_31 ) ) {
F_10 ( V_12 , L_4 ) ;
return - V_10 ;
}
if ( ( V_12 -> V_30 & V_61 ) && ( V_19 || V_20 ) ) {
F_10 ( V_12 ,
L_5 ) ;
return - V_10 ;
}
#ifndef F_13
if ( F_14 ( V_12 ) ) {
F_10 ( V_12 , L_6 ) ;
return - V_10 ;
}
#endif
if ( ( V_19 && ! V_20 ) || ( ! V_19 && V_20 ) ) {
F_10 ( V_12 , L_7 ) ;
return - V_10 ;
}
if ( V_19 && ( V_20 % V_19 != 0 ) ) {
F_10 ( V_12 ,
L_8 ,
V_20 , V_19 ) ;
return - V_10 ;
}
V_40:
if ( V_19 && ! ( V_12 -> V_30 & V_61 ) ) {
V_12 -> V_114 = V_19 ;
V_12 -> V_115 = V_20 ;
}
if ( V_12 -> V_38 != - 1 &&
V_12 -> V_38 != 0 &&
( V_12 -> V_38 < V_116 ||
V_12 -> V_38 > V_117 ) ) {
F_10 ( V_12 , L_9 ,
V_12 -> V_38 , V_116 , V_117 ) ;
return - V_10 ;
}
if ( V_12 -> V_39 != - 1 &&
V_12 -> V_39 != 0 &&
( V_12 -> V_39 < V_118 ||
V_12 -> V_39 > V_119 ||
! F_15 ( V_12 -> V_39 ) ) ) {
F_10 ( V_12 ,
L_10 ,
V_12 -> V_39 ) ;
return - V_10 ;
}
if ( V_22 ) {
if ( V_22 > V_120 ||
V_22 < V_121 ) {
F_10 ( V_12 , L_11 ,
V_22 , V_121 ,
V_120 ) ;
return - V_10 ;
}
V_12 -> V_30 |= V_122 ;
V_12 -> V_123 = V_22 ;
V_12 -> V_124 = V_22 ;
}
return 0 ;
}
STATIC int
F_16 (
struct V_11 * V_12 ,
struct V_125 * V_126 )
{
static struct V_127 V_128 [] = {
{ V_74 , L_12 } ,
{ V_35 , L_13 } ,
{ V_61 , L_14 } ,
{ V_63 , L_15 } ,
{ V_70 , L_16 } ,
{ V_59 , L_17 } ,
{ V_79 , L_18 } ,
{ V_83 , L_19 } ,
{ V_54 , L_20 } ,
{ V_110 , L_21 } ,
{ V_67 , L_22 } ,
{ V_113 , L_23 } ,
{ 0 , NULL }
} ;
static struct V_127 V_129 [] = {
{ V_37 , L_24 } ,
{ V_36 , L_25 } ,
{ V_67 , L_26 } ,
{ 0 , NULL }
} ;
struct V_127 * V_130 ;
for ( V_130 = V_128 ; V_130 -> V_131 ; V_130 ++ ) {
if ( V_12 -> V_30 & V_130 -> V_131 )
F_17 ( V_126 , V_130 -> V_132 ) ;
}
for ( V_130 = V_129 ; V_130 -> V_131 ; V_130 ++ ) {
if ( ! ( V_12 -> V_30 & V_130 -> V_131 ) )
F_17 ( V_126 , V_130 -> V_132 ) ;
}
if ( V_12 -> V_30 & V_122 )
F_18 ( V_126 , L_27 ,
( int ) ( 1 << V_12 -> V_124 ) >> 10 ) ;
if ( V_12 -> V_38 > 0 )
F_18 ( V_126 , L_28 , V_12 -> V_38 ) ;
if ( V_12 -> V_39 > 0 )
F_18 ( V_126 , L_29 , V_12 -> V_39 >> 10 ) ;
if ( V_12 -> V_46 )
F_19 ( V_126 , L_30 , V_12 -> V_46 ) ;
if ( V_12 -> V_49 )
F_19 ( V_126 , L_31 , V_12 -> V_49 ) ;
if ( V_12 -> V_114 > 0 )
F_18 ( V_126 , L_32 ,
( int ) F_20 ( V_12 , V_12 -> V_114 ) ) ;
if ( V_12 -> V_115 > 0 )
F_18 ( V_126 , L_33 ,
( int ) F_20 ( V_12 , V_12 -> V_115 ) ) ;
if ( V_12 -> V_85 & ( V_92 | V_94 ) )
F_17 ( V_126 , L_34 ) ;
else if ( V_12 -> V_85 & V_92 )
F_17 ( V_126 , L_35 ) ;
if ( V_12 -> V_85 & V_99 ) {
if ( V_12 -> V_85 & V_101 )
F_17 ( V_126 , L_36 ) ;
else
F_17 ( V_126 , L_37 ) ;
}
if ( V_12 -> V_85 & V_105 ) {
if ( V_12 -> V_85 & V_107 )
F_17 ( V_126 , L_38 ) ;
else
F_17 ( V_126 , L_39 ) ;
}
if ( ! ( V_12 -> V_85 & V_86 ) )
F_17 ( V_126 , L_40 ) ;
return 0 ;
}
static T_3
F_21 (
unsigned int V_133 )
{
unsigned int V_134 = 1 ;
unsigned int V_135 = V_136 - 1 ;
#if V_136 == 32
# if F_22 ( V_137 )
ASSERT ( sizeof( V_138 ) == 8 ) ;
V_134 = V_139 ;
V_135 = V_136 ;
# else
V_134 = V_139 >> ( V_140 - V_133 ) ;
# endif
#endif
return ( ( ( T_3 ) V_134 ) << V_135 ) - 1 ;
}
T_4
F_23 (
struct V_11 * V_12 ,
T_4 V_141 )
{
T_4 V_142 ;
T_4 V_143 = 0 ;
T_5 * V_144 = & V_12 -> V_145 ;
T_4 V_146 ;
T_6 V_147 ;
T_7 V_148 ;
if ( V_12 -> V_149 ) {
T_3 V_150 ;
V_150 = V_144 -> V_151 * V_144 -> V_152 ;
F_24 ( V_150 , 100 ) ;
V_150 += V_144 -> V_153 - 1 ;
F_24 ( V_150 , V_144 -> V_153 ) ;
V_146 = V_150 ;
} else {
V_146 = V_141 ;
}
V_147 = F_25 ( V_12 , V_144 -> V_153 - 1 , 0 ) ;
V_148 = F_26 ( V_12 , V_141 - 1 , V_147 ) ;
if ( ( V_12 -> V_30 & V_67 ) && V_148 > V_154 )
V_12 -> V_30 |= V_155 ;
else
V_12 -> V_30 &= ~ V_155 ;
for ( V_142 = 0 ; V_142 < V_141 ; V_142 ++ ) {
struct V_156 * V_157 ;
V_148 = F_26 ( V_12 , V_142 , V_147 ) ;
V_157 = F_27 ( V_12 , V_142 ) ;
if ( V_12 -> V_30 & V_155 ) {
if ( V_148 > V_154 ) {
V_157 -> V_158 = 0 ;
V_157 -> V_159 = 0 ;
} else {
V_157 -> V_158 = 1 ;
V_143 ++ ;
if ( V_142 < V_146 )
V_157 -> V_159 = 1 ;
else
V_157 -> V_159 = 0 ;
}
} else {
V_157 -> V_158 = 1 ;
V_157 -> V_159 = 0 ;
}
F_28 ( V_157 ) ;
}
return ( V_12 -> V_30 & V_155 ) ? V_143 : V_141 ;
}
STATIC int
F_29 (
T_8 * V_12 ,
const char * V_160 ,
struct V_161 * * V_162 )
{
int error = 0 ;
* V_162 = F_30 ( V_160 , V_163 | V_164 | V_165 ,
V_12 ) ;
if ( F_31 ( * V_162 ) ) {
error = F_32 ( * V_162 ) ;
F_10 ( V_12 , L_41 , V_160 , error ) ;
}
return error ;
}
STATIC void
F_33 (
struct V_161 * V_166 )
{
if ( V_166 )
F_34 ( V_166 , V_163 | V_164 | V_165 ) ;
}
void
F_35 (
T_9 * V_167 )
{
F_36 ( V_167 -> V_168 , V_169 , NULL ) ;
}
STATIC void
F_37 (
struct V_11 * V_12 )
{
if ( V_12 -> V_170 && V_12 -> V_170 != V_12 -> V_171 ) {
struct V_161 * V_172 = V_12 -> V_170 -> V_168 ;
F_38 ( V_12 , V_12 -> V_170 ) ;
F_33 ( V_172 ) ;
}
if ( V_12 -> V_173 ) {
struct V_161 * V_174 = V_12 -> V_173 -> V_168 ;
F_38 ( V_12 , V_12 -> V_173 ) ;
F_33 ( V_174 ) ;
}
F_38 ( V_12 , V_12 -> V_171 ) ;
}
STATIC int
F_39 (
struct V_11 * V_12 )
{
struct V_161 * V_175 = V_12 -> V_16 -> V_176 ;
struct V_161 * V_172 = NULL , * V_174 = NULL ;
int error ;
if ( V_12 -> V_46 ) {
error = F_29 ( V_12 , V_12 -> V_46 , & V_172 ) ;
if ( error )
goto V_177;
}
if ( V_12 -> V_49 ) {
error = F_29 ( V_12 , V_12 -> V_49 , & V_174 ) ;
if ( error )
goto V_178;
if ( V_174 == V_175 || V_174 == V_172 ) {
F_10 ( V_12 ,
L_42 ) ;
error = - V_10 ;
goto V_179;
}
}
error = - V_9 ;
V_12 -> V_171 = F_40 ( V_12 , V_175 ) ;
if ( ! V_12 -> V_171 )
goto V_179;
if ( V_174 ) {
V_12 -> V_173 = F_40 ( V_12 , V_174 ) ;
if ( ! V_12 -> V_173 )
goto V_180;
}
if ( V_172 && V_172 != V_175 ) {
V_12 -> V_170 = F_40 ( V_12 , V_172 ) ;
if ( ! V_12 -> V_170 )
goto V_181;
} else {
V_12 -> V_170 = V_12 -> V_171 ;
}
return 0 ;
V_181:
if ( V_12 -> V_173 )
F_38 ( V_12 , V_12 -> V_173 ) ;
V_180:
F_38 ( V_12 , V_12 -> V_171 ) ;
V_179:
F_33 ( V_174 ) ;
V_178:
if ( V_172 && V_172 != V_175 )
F_33 ( V_172 ) ;
V_177:
return error ;
}
STATIC int
F_41 (
struct V_11 * V_12 )
{
int error ;
error = F_42 ( V_12 -> V_171 , V_12 -> V_145 . V_182 ) ;
if ( error )
return error ;
if ( V_12 -> V_170 && V_12 -> V_170 != V_12 -> V_171 ) {
unsigned int V_183 = V_184 ;
if ( F_43 ( & V_12 -> V_145 ) )
V_183 = V_12 -> V_145 . V_185 ;
error = F_42 ( V_12 -> V_170 ,
V_183 ) ;
if ( error )
return error ;
}
if ( V_12 -> V_173 ) {
error = F_42 ( V_12 -> V_173 ,
V_12 -> V_145 . V_182 ) ;
if ( error )
return error ;
}
return 0 ;
}
STATIC int
F_44 (
struct V_11 * V_12 )
{
V_12 -> V_186 = F_45 ( L_43 ,
V_187 | V_188 , 1 , V_12 -> V_23 ) ;
if ( ! V_12 -> V_186 )
goto V_177;
V_12 -> V_189 = F_45 ( L_44 ,
V_187 | V_188 , 0 , V_12 -> V_23 ) ;
if ( ! V_12 -> V_189 )
goto V_190;
V_12 -> V_191 = F_45 ( L_45 ,
V_187 | V_188 , 0 , V_12 -> V_23 ) ;
if ( ! V_12 -> V_191 )
goto V_192;
V_12 -> V_193 = F_45 ( L_46 ,
V_187 | V_188 , 0 , V_12 -> V_23 ) ;
if ( ! V_12 -> V_193 )
goto V_194;
V_12 -> V_195 = F_45 ( L_47 ,
V_187 | V_188 , 0 , V_12 -> V_23 ) ;
if ( ! V_12 -> V_195 )
goto V_196;
V_12 -> V_197 = F_45 ( L_48 ,
V_187 | V_188 | V_198 , 0 ,
V_12 -> V_23 ) ;
if ( ! V_12 -> V_197 )
goto V_199;
V_12 -> V_200 = F_45 ( L_49 ,
V_187 | V_188 , 0 , V_12 -> V_23 ) ;
if ( ! V_12 -> V_200 )
goto V_201;
return 0 ;
V_201:
F_46 ( V_12 -> V_197 ) ;
V_199:
F_46 ( V_12 -> V_195 ) ;
V_196:
F_46 ( V_12 -> V_193 ) ;
V_194:
F_46 ( V_12 -> V_191 ) ;
V_192:
F_46 ( V_12 -> V_189 ) ;
V_190:
F_46 ( V_12 -> V_186 ) ;
V_177:
return - V_9 ;
}
STATIC void
F_47 (
struct V_11 * V_12 )
{
F_46 ( V_12 -> V_200 ) ;
F_46 ( V_12 -> V_197 ) ;
F_46 ( V_12 -> V_195 ) ;
F_46 ( V_12 -> V_193 ) ;
F_46 ( V_12 -> V_189 ) ;
F_46 ( V_12 -> V_191 ) ;
F_46 ( V_12 -> V_186 ) ;
}
void
F_48 (
struct V_11 * V_12 )
{
struct V_14 * V_15 = V_12 -> V_16 ;
if ( F_49 ( & V_15 -> V_202 ) ) {
F_50 ( V_15 ) ;
F_51 ( & V_15 -> V_202 ) ;
}
}
STATIC struct V_203 *
F_52 (
struct V_14 * V_15 )
{
F_53 () ;
return NULL ;
}
STATIC void
F_54 (
struct V_203 * V_203 )
{
struct V_204 * V_205 = F_55 ( V_203 ) ;
F_56 ( V_205 ) ;
ASSERT ( ! F_57 ( & V_205 -> V_206 . V_207 ) ) ;
F_58 ( V_205 -> V_208 , V_209 ) ;
F_58 ( V_205 -> V_208 , V_210 ) ;
F_59 ( V_205 ) ;
ASSERT ( F_60 ( V_205 -> V_208 ) || V_205 -> V_211 == 0 ) ;
F_58 ( V_205 -> V_208 , V_212 ) ;
F_61 ( ! F_62 ( V_205 , V_213 ) ) ;
F_61 ( ! F_62 ( V_205 , V_214 ) ) ;
F_63 ( V_205 ) ;
}
STATIC void
F_64 (
void * V_203 )
{
struct V_204 * V_205 = V_203 ;
memset ( V_205 , 0 , sizeof( struct V_204 ) ) ;
F_65 ( F_66 ( V_205 ) ) ;
F_67 ( & V_205 -> V_215 , 0 ) ;
F_68 ( & V_205 -> V_216 ) ;
F_69 ( & V_205 -> V_217 , V_218 | V_219 ,
L_50 , V_205 -> V_220 ) ;
F_69 ( & V_205 -> V_221 , V_218 | V_219 ,
L_50 , V_205 -> V_220 ) ;
}
STATIC int
F_70 (
struct V_203 * V_203 )
{
struct V_204 * V_205 = F_55 ( V_203 ) ;
return F_71 ( V_203 ) || ( V_205 -> V_222 & V_223 ) ;
}
STATIC void
F_72 (
struct V_11 * V_12 )
{
F_4 ( V_12 -> V_23 ) ;
F_4 ( V_12 -> V_49 ) ;
F_4 ( V_12 -> V_46 ) ;
}
STATIC int
F_73 (
struct V_14 * V_15 ,
int V_224 )
{
struct V_11 * V_12 = F_74 ( V_15 ) ;
if ( ! V_224 )
return 0 ;
F_75 ( V_12 , V_225 ) ;
if ( V_226 ) {
F_76 ( & V_12 -> V_227 -> V_228 ) ;
}
return 0 ;
}
STATIC int
F_77 (
struct V_229 * V_229 ,
struct V_230 * V_231 )
{
struct V_11 * V_12 = F_74 ( V_229 -> V_232 ) ;
T_5 * V_144 = & V_12 -> V_145 ;
struct V_204 * V_205 = F_55 ( F_78 ( V_229 ) ) ;
T_3 V_233 , V_234 ;
T_3 V_150 ;
T_3 V_235 ;
T_3 V_236 ;
T_10 V_237 ;
T_11 V_238 ;
V_231 -> V_239 = V_240 ;
V_231 -> V_241 = V_25 - 1 ;
V_234 = F_79 ( V_12 -> V_171 -> V_242 ) ;
V_231 -> V_243 . V_244 [ 0 ] = ( V_245 ) V_234 ;
V_231 -> V_243 . V_244 [ 1 ] = ( V_245 ) ( V_234 >> 32 ) ;
V_150 = F_80 ( & V_12 -> V_246 ) ;
V_235 = F_80 ( & V_12 -> V_247 ) ;
V_236 = F_80 ( & V_12 -> V_248 ) ;
F_81 ( & V_12 -> V_249 ) ;
V_231 -> V_250 = V_144 -> V_251 ;
V_237 = V_144 -> V_252 ? V_144 -> V_253 : 0 ;
V_231 -> V_254 = V_144 -> V_151 - V_237 ;
F_82 ( & V_12 -> V_249 ) ;
V_231 -> V_255 = V_236 - V_12 -> V_256 ;
V_231 -> V_257 = V_231 -> V_255 ;
V_233 = V_231 -> V_255 << V_144 -> V_258 ;
V_231 -> V_259 = F_83 ( V_150 + V_233 , ( T_3 ) V_260 ) ;
if ( V_12 -> V_149 )
V_231 -> V_259 = F_84 ( F_85 ( V_231 -> V_259 ) ,
V_231 -> V_259 ,
V_12 -> V_149 ) ;
V_231 -> V_259 = F_86 ( F_85 ( V_231 -> V_259 ) ,
V_231 -> V_259 ,
V_144 -> V_261 ) ;
V_238 = V_231 -> V_259 - ( V_150 - V_235 ) ;
V_231 -> V_262 = F_86 ( T_11 , V_238 , 0 ) ;
if ( ( V_205 -> V_263 . V_264 & V_265 ) &&
( ( V_12 -> V_85 & ( V_99 | V_101 ) ) ) ==
( V_99 | V_101 ) )
F_87 ( V_205 , V_231 ) ;
return 0 ;
}
STATIC void
F_88 ( struct V_11 * V_12 )
{
T_3 V_266 = 0 ;
V_12 -> V_267 = V_12 -> V_268 ;
F_89 ( V_12 , & V_266 , NULL ) ;
}
STATIC void
F_90 ( struct V_11 * V_12 )
{
T_3 V_266 ;
if ( V_12 -> V_267 ) {
V_266 = V_12 -> V_267 ;
V_12 -> V_267 = 0 ;
} else
V_266 = F_91 ( V_12 ) ;
F_89 ( V_12 , & V_266 , NULL ) ;
}
static void
F_92 (
struct V_11 * V_12 )
{
int error = 0 ;
while ( F_93 ( & V_12 -> V_269 ) > 0 )
F_94 ( 100 ) ;
F_75 ( V_12 , V_225 ) ;
F_95 ( V_12 , 0 ) ;
F_95 ( V_12 , V_270 ) ;
error = F_96 ( V_12 ) ;
if ( error )
F_10 ( V_12 , L_51
L_52 ) ;
F_97 ( F_93 ( & V_12 -> V_269 ) != 0 ) ;
F_98 ( V_12 ) ;
}
STATIC int
F_99 (
struct V_14 * V_15 ,
struct V_11 * V_12 ,
char * V_13 )
{
int error = 0 ;
struct V_11 * V_271 ;
V_271 = F_100 ( sizeof( * V_271 ) , V_272 ) ;
if ( ! V_271 )
return - V_9 ;
V_271 -> V_16 = V_15 ;
error = F_5 ( V_271 , V_13 ) ;
F_72 ( V_271 ) ;
F_4 ( V_271 ) ;
return error ;
}
STATIC int
F_101 (
struct V_14 * V_15 ,
int * V_273 ,
char * V_13 )
{
struct V_11 * V_12 = F_74 ( V_15 ) ;
T_5 * V_144 = & V_12 -> V_145 ;
T_1 args [ V_18 ] ;
char * V_17 ;
int error ;
error = F_99 ( V_15 , V_12 , V_13 ) ;
if ( error )
return error ;
F_102 ( V_15 ) ;
while ( ( V_17 = F_7 ( & V_13 , L_1 ) ) != NULL ) {
int V_41 ;
if ( ! * V_17 )
continue;
V_41 = F_8 ( V_17 , V_42 , args ) ;
switch ( V_41 ) {
case V_71 :
V_12 -> V_30 |= V_36 ;
break;
case V_72 :
V_12 -> V_30 &= ~ V_36 ;
break;
case V_68 :
V_12 -> V_30 &= ~ V_67 ;
V_12 -> V_274 = F_23 ( V_12 , V_144 -> V_275 ) ;
break;
case V_66 :
V_12 -> V_30 |= V_67 ;
V_12 -> V_274 = F_23 ( V_12 , V_144 -> V_275 ) ;
break;
default:
#if 0
xfs_info(mp,
"mount option \"%s\" not supported for remount", p);
return -EINVAL;
#else
break;
#endif
}
}
if ( ( V_12 -> V_30 & V_31 ) && ! ( * V_273 & V_29 ) ) {
if ( V_12 -> V_30 & V_59 ) {
F_10 ( V_12 ,
L_53 ) ;
return - V_10 ;
}
if ( F_103 ( V_144 ) == V_276 &&
F_104 ( V_144 ,
V_277 ) ) {
F_10 ( V_12 ,
L_54 ,
( V_144 -> V_278 &
V_277 ) ) ;
return - V_10 ;
}
V_12 -> V_30 &= ~ V_31 ;
if ( V_12 -> V_279 ) {
error = F_105 ( V_12 , false ) ;
if ( error ) {
F_10 ( V_12 , L_55 ) ;
return error ;
}
V_12 -> V_279 = false ;
}
F_90 ( V_12 ) ;
F_106 ( V_12 ) ;
F_107 ( V_12 ) ;
}
if ( ! ( V_12 -> V_30 & V_31 ) && ( * V_273 & V_29 ) ) {
F_88 ( V_12 ) ;
F_108 ( & V_12 -> V_280 ) ;
F_92 ( V_12 ) ;
V_12 -> V_30 |= V_31 ;
}
return 0 ;
}
STATIC int
F_109 (
struct V_14 * V_15 )
{
struct V_11 * V_12 = F_74 ( V_15 ) ;
F_88 ( V_12 ) ;
F_92 ( V_12 ) ;
return F_105 ( V_12 , true ) ;
}
STATIC int
F_110 (
struct V_14 * V_15 )
{
struct V_11 * V_12 = F_74 ( V_15 ) ;
F_90 ( V_12 ) ;
F_106 ( V_12 ) ;
return 0 ;
}
STATIC int
F_111 (
struct V_125 * V_126 ,
struct V_229 * V_281 )
{
return F_16 ( F_74 ( V_281 -> V_232 ) , V_126 ) ;
}
STATIC int
F_112 (
struct V_11 * V_12 )
{
int V_282 = ( V_12 -> V_30 & V_31 ) ;
if ( F_113 ( & V_12 -> V_145 ) ) {
if ( V_12 -> V_39 <= 0 &&
V_12 -> V_145 . V_283 > V_284 ) {
V_12 -> V_39 = V_12 -> V_145 . V_283 ;
} else if ( V_12 -> V_39 > 0 &&
V_12 -> V_39 < V_12 -> V_145 . V_283 ) {
F_10 ( V_12 ,
L_56 ) ;
return - V_10 ;
}
} else {
if ( V_12 -> V_39 > V_284 ) {
F_10 ( V_12 ,
L_57 ) ;
return - V_10 ;
}
}
if ( F_114 ( & V_12 -> V_145 ) &&
( V_12 -> V_30 & V_81 ) ) {
F_10 ( V_12 , L_58
L_59 ) ;
return - V_10 ;
}
if ( F_115 ( & V_12 -> V_145 ) &&
! ( V_12 -> V_30 & V_81 ) )
V_12 -> V_30 |= V_79 ;
if ( ( V_12 -> V_145 . V_285 & V_286 ) && ! V_282 ) {
F_10 ( V_12 ,
L_60 ) ;
return - V_287 ;
}
if ( ( V_12 -> V_85 & ( V_105 | V_106 ) ) &&
( V_12 -> V_85 & ( V_99 | V_100 ) ) &&
! F_116 ( & V_12 -> V_145 ) ) {
F_10 ( V_12 ,
L_61 ) ;
return - V_10 ;
}
return 0 ;
}
static int
F_117 (
struct V_11 * V_12 )
{
int error ;
error = F_118 ( & V_12 -> V_246 , 0 , V_26 ) ;
if ( error )
return - V_9 ;
error = F_118 ( & V_12 -> V_247 , 0 , V_26 ) ;
if ( error )
goto V_288;
error = F_118 ( & V_12 -> V_248 , 0 , V_26 ) ;
if ( error )
goto V_289;
return 0 ;
V_289:
F_119 ( & V_12 -> V_247 ) ;
V_288:
F_119 ( & V_12 -> V_246 ) ;
return - V_9 ;
}
void
F_120 (
struct V_11 * V_12 )
{
F_121 ( & V_12 -> V_246 , V_12 -> V_145 . V_261 ) ;
F_121 ( & V_12 -> V_247 , V_12 -> V_145 . V_290 ) ;
F_121 ( & V_12 -> V_248 , V_12 -> V_145 . V_291 ) ;
}
static void
F_122 (
struct V_11 * V_12 )
{
F_119 ( & V_12 -> V_246 ) ;
F_119 ( & V_12 -> V_247 ) ;
F_119 ( & V_12 -> V_248 ) ;
}
STATIC int
F_123 (
struct V_14 * V_15 ,
void * V_292 ,
int V_293 )
{
struct V_203 * V_281 ;
struct V_11 * V_12 = NULL ;
int V_273 = 0 , error = - V_9 ;
V_12 = F_124 ( sizeof( struct V_11 ) , V_26 ) ;
if ( ! V_12 )
goto V_177;
F_68 ( & V_12 -> V_249 ) ;
F_125 ( & V_12 -> V_294 ) ;
F_67 ( & V_12 -> V_269 , 0 ) ;
F_126 ( & V_12 -> V_295 , V_296 ) ;
F_126 ( & V_12 -> V_280 , V_297 ) ;
V_12 -> V_298 . V_299 . V_300 = V_301 ;
V_12 -> V_16 = V_15 ;
V_15 -> V_302 = V_12 ;
error = F_5 ( V_12 , ( char * ) V_292 ) ;
if ( error )
goto V_303;
F_127 ( V_15 , V_184 ) ;
V_15 -> V_304 = V_305 ;
V_15 -> V_306 = & V_307 ;
#ifdef F_13
V_15 -> V_308 = & V_309 ;
V_15 -> V_310 = V_311 | V_312 | V_313 ;
#endif
V_15 -> V_314 = & V_315 ;
if ( V_293 )
V_273 |= V_316 ;
error = F_39 ( V_12 ) ;
if ( error )
goto V_303;
error = F_44 ( V_12 ) ;
if ( error )
goto V_317;
error = F_117 ( V_12 ) ;
if ( error )
goto V_318;
V_12 -> V_319 . V_320 = F_128 ( struct V_321 ) ;
if ( ! V_12 -> V_319 . V_320 ) {
error = - V_9 ;
goto V_322;
}
error = F_129 ( V_12 , V_273 ) ;
if ( error )
goto V_323;
error = F_112 ( V_12 ) ;
if ( error )
goto V_324;
error = F_41 ( V_12 ) ;
if ( error )
goto V_324;
error = F_130 ( V_12 ) ;
if ( error )
goto V_324;
V_15 -> V_325 = V_240 ;
V_15 -> V_326 = V_12 -> V_145 . V_251 ;
V_15 -> V_327 = F_11 ( V_15 -> V_326 ) - 1 ;
V_15 -> V_328 = F_21 ( V_15 -> V_327 ) ;
V_15 -> V_329 = V_330 ;
V_15 -> V_331 = 1 ;
F_131 ( V_15 ) ;
if ( F_103 ( & V_12 -> V_145 ) == V_276 )
V_15 -> V_28 |= V_332 ;
if ( V_12 -> V_30 & V_113 ) {
F_10 ( V_12 ,
L_62 ) ;
error = F_132 ( V_15 , V_15 -> V_326 ) ;
if ( error ) {
F_133 ( V_12 ,
L_63 ) ;
V_12 -> V_30 &= ~ V_113 ;
}
}
if ( F_134 ( & V_12 -> V_145 ) ) {
if ( V_12 -> V_145 . V_333 ) {
F_133 ( V_12 ,
L_64 ) ;
error = - V_10 ;
goto V_334;
}
F_133 ( V_12 ,
L_65 ) ;
}
error = F_135 ( V_12 ) ;
if ( error )
goto V_334;
V_281 = F_136 ( F_66 ( V_12 -> V_335 ) ) ;
if ( ! V_281 ) {
error = - V_336 ;
goto V_337;
}
V_15 -> V_338 = F_137 ( V_281 ) ;
if ( ! V_15 -> V_338 ) {
error = - V_9 ;
goto V_337;
}
return 0 ;
V_334:
F_138 ( V_12 ) ;
V_324:
F_139 ( V_12 ) ;
V_323:
F_140 ( V_12 -> V_319 . V_320 ) ;
V_322:
F_122 ( V_12 ) ;
V_318:
F_47 ( V_12 ) ;
V_317:
F_37 ( V_12 ) ;
V_303:
F_72 ( V_12 ) ;
F_4 ( V_12 ) ;
V_177:
return error ;
V_337:
F_138 ( V_12 ) ;
F_141 ( V_12 ) ;
goto V_324;
}
STATIC void
F_142 (
struct V_14 * V_15 )
{
struct V_11 * V_12 = F_74 ( V_15 ) ;
F_143 ( V_12 , L_66 ) ;
F_138 ( V_12 ) ;
F_141 ( V_12 ) ;
F_139 ( V_12 ) ;
F_140 ( V_12 -> V_319 . V_320 ) ;
F_122 ( V_12 ) ;
F_47 ( V_12 ) ;
F_37 ( V_12 ) ;
F_72 ( V_12 ) ;
F_4 ( V_12 ) ;
}
STATIC struct V_229 *
F_144 (
struct V_339 * V_340 ,
int V_273 ,
const char * V_341 ,
void * V_292 )
{
return F_145 ( V_340 , V_273 , V_341 , V_292 , F_123 ) ;
}
static long
F_146 (
struct V_14 * V_15 ,
struct V_342 * V_343 )
{
return F_147 ( F_74 ( V_15 ) ) ;
}
static long
F_148 (
struct V_14 * V_15 ,
struct V_342 * V_343 )
{
return F_149 ( F_74 ( V_15 ) , V_343 -> V_344 ) ;
}
STATIC int T_12
F_150 ( void )
{
V_345 = F_151 ( 4 * V_346 ,
F_152 ( struct V_347 , V_348 ) ) ;
if ( ! V_345 )
goto V_177;
V_349 = F_153 ( sizeof( V_350 ) ,
L_67 ) ;
if ( ! V_349 )
goto V_351;
V_352 = F_153 (
sizeof( struct V_353 ) ,
L_68 ) ;
if ( ! V_352 )
goto V_354;
V_355 = F_153 ( sizeof( V_356 ) ,
L_69 ) ;
if ( ! V_355 )
goto V_357;
V_358 = F_153 ( sizeof( V_359 ) ,
L_70 ) ;
if ( ! V_358 )
goto V_360;
V_361 = F_153 ( sizeof( V_362 ) , L_71 ) ;
if ( ! V_361 )
goto V_363;
V_364 = F_153 ( sizeof( V_365 ) , L_72 ) ;
if ( ! V_364 )
goto V_366;
V_367 =
F_153 ( sizeof( struct V_368 ) ,
L_73 ) ;
if ( ! V_367 )
goto V_369;
V_370 = F_153 ( sizeof( struct V_371 ) ,
L_74 ) ;
if ( ! V_370 )
goto V_372;
V_373 = F_153 ( ( sizeof( V_374 ) +
( ( V_375 - 1 ) *
sizeof( V_376 ) ) ) , L_75 ) ;
if ( ! V_373 )
goto V_377;
V_378 = F_153 ( ( sizeof( V_379 ) +
( ( V_380 - 1 ) *
sizeof( V_376 ) ) ) , L_76 ) ;
if ( ! V_378 )
goto V_381;
V_382 =
F_154 ( sizeof( V_383 ) , L_77 ,
V_384 | V_385 | V_386 |
V_387 , F_64 ) ;
if ( ! V_382 )
goto V_388;
V_389 =
F_154 ( sizeof( V_390 ) , L_78 ,
V_386 , NULL ) ;
if ( ! V_389 )
goto V_391;
V_392 = F_153 ( sizeof( struct V_393 ) ,
L_79 ) ;
if ( ! V_392 )
goto V_394;
V_395 = F_153 ( sizeof( struct V_396 ) ,
L_80 ) ;
if ( ! V_395 )
goto V_397;
V_398 = F_153 ( ( sizeof( struct V_399 ) +
( ( V_400 - 1 ) *
sizeof( struct V_401 ) ) ) ,
L_81 ) ;
if ( ! V_398 )
goto V_402;
return 0 ;
V_402:
F_155 ( V_395 ) ;
V_397:
F_155 ( V_392 ) ;
V_394:
F_155 ( V_389 ) ;
V_391:
F_155 ( V_382 ) ;
V_388:
F_155 ( V_378 ) ;
V_381:
F_155 ( V_373 ) ;
V_377:
F_155 ( V_370 ) ;
V_372:
F_155 ( V_367 ) ;
V_369:
F_155 ( V_364 ) ;
V_366:
F_155 ( V_361 ) ;
V_363:
F_155 ( V_358 ) ;
V_360:
F_155 ( V_355 ) ;
V_357:
F_155 ( V_352 ) ;
V_354:
F_155 ( V_349 ) ;
V_351:
F_156 ( V_345 ) ;
V_177:
return - V_9 ;
}
STATIC void
F_157 ( void )
{
F_158 () ;
F_155 ( V_398 ) ;
F_155 ( V_395 ) ;
F_155 ( V_392 ) ;
F_155 ( V_389 ) ;
F_155 ( V_382 ) ;
F_155 ( V_378 ) ;
F_155 ( V_373 ) ;
F_155 ( V_370 ) ;
F_155 ( V_367 ) ;
F_155 ( V_364 ) ;
F_155 ( V_361 ) ;
F_155 ( V_358 ) ;
F_155 ( V_355 ) ;
F_155 ( V_352 ) ;
F_155 ( V_349 ) ;
F_156 ( V_345 ) ;
}
STATIC int T_12
F_159 ( void )
{
V_403 = F_45 ( L_82 ,
V_187 | V_188 , 0 ) ;
if ( ! V_403 )
return - V_9 ;
return 0 ;
}
STATIC void
F_160 ( void )
{
F_46 ( V_403 ) ;
}
STATIC int T_12
F_161 ( void )
{
int error ;
F_162 () ;
F_163 (KERN_INFO XFS_VERSION_STRING L_83
XFS_BUILD_OPTIONS L_84 ) ;
F_164 () ;
F_165 () ;
F_166 () ;
error = F_150 () ;
if ( error )
goto V_177;
error = F_159 () ;
if ( error )
goto V_404;
error = F_167 () ;
if ( error )
goto V_405;
error = F_168 () ;
if ( error )
goto V_406;
error = F_169 () ;
if ( error )
goto V_407;
error = F_170 () ;
if ( error )
goto V_408;
V_301 = F_171 ( L_85 , NULL , V_409 ) ;
if ( ! V_301 ) {
error = - V_9 ;
goto V_410;
}
V_321 . V_411 . V_299 . V_300 = V_301 ;
V_321 . V_320 = F_128 ( struct V_321 ) ;
if ( ! V_321 . V_320 ) {
error = - V_9 ;
goto V_412;
}
error = F_172 ( & V_321 . V_411 , & V_413 , NULL ,
L_86 ) ;
if ( error )
goto V_323;
#ifdef F_173
V_414 . V_299 . V_300 = V_301 ;
error = F_172 ( & V_414 , & V_415 , NULL , L_87 ) ;
if ( error )
goto V_416;
#endif
error = F_174 () ;
if ( error )
goto V_417;
error = F_175 ( & V_418 ) ;
if ( error )
goto V_419;
return 0 ;
V_419:
F_176 () ;
V_417:
#ifdef F_173
F_177 ( & V_414 ) ;
V_416:
#endif
F_177 ( & V_321 . V_411 ) ;
V_323:
F_140 ( V_321 . V_320 ) ;
V_412:
F_178 ( V_301 ) ;
V_410:
F_179 () ;
V_408:
F_180 () ;
V_407:
F_181 () ;
V_406:
F_182 () ;
V_405:
F_160 () ;
V_404:
F_157 () ;
V_177:
return error ;
}
STATIC void T_13
F_183 ( void )
{
F_176 () ;
F_184 ( & V_418 ) ;
#ifdef F_173
F_177 ( & V_414 ) ;
#endif
F_177 ( & V_321 . V_411 ) ;
F_140 ( V_321 . V_320 ) ;
F_178 ( V_301 ) ;
F_179 () ;
F_180 () ;
F_181 () ;
F_182 () ;
F_160 () ;
F_157 () ;
F_185 () ;
}
