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
T_3
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
V_231 -> V_255 = V_236 - F_83 ( V_12 ) ;
V_231 -> V_256 = V_231 -> V_255 ;
V_233 = V_231 -> V_255 << V_144 -> V_257 ;
V_231 -> V_258 = F_84 ( V_150 + V_233 , ( T_3 ) V_259 ) ;
if ( V_12 -> V_149 )
V_231 -> V_258 = F_85 ( F_86 ( V_231 -> V_258 ) ,
V_231 -> V_258 ,
V_12 -> V_149 ) ;
V_231 -> V_258 = F_87 ( F_86 ( V_231 -> V_258 ) ,
V_231 -> V_258 ,
V_144 -> V_260 ) ;
V_238 = V_231 -> V_258 - ( V_150 - V_235 ) ;
V_231 -> V_261 = F_87 ( T_11 , V_238 , 0 ) ;
if ( ( V_205 -> V_262 . V_263 & V_264 ) &&
( ( V_12 -> V_85 & ( V_99 | V_101 ) ) ) ==
( V_99 | V_101 ) )
F_88 ( V_205 , V_231 ) ;
return 0 ;
}
STATIC void
F_89 ( struct V_11 * V_12 )
{
T_3 V_265 = 0 ;
V_12 -> V_266 = V_12 -> V_267 ;
F_90 ( V_12 , & V_265 , NULL ) ;
}
STATIC void
F_91 ( struct V_11 * V_12 )
{
T_3 V_265 ;
if ( V_12 -> V_266 ) {
V_265 = V_12 -> V_266 ;
V_12 -> V_266 = 0 ;
} else
V_265 = F_92 ( V_12 ) ;
F_90 ( V_12 , & V_265 , NULL ) ;
}
static void
F_93 (
struct V_11 * V_12 )
{
int error = 0 ;
while ( F_94 ( & V_12 -> V_268 ) > 0 )
F_95 ( 100 ) ;
F_75 ( V_12 , V_225 ) ;
F_96 ( V_12 , 0 ) ;
F_96 ( V_12 , V_269 ) ;
error = F_97 ( V_12 ) ;
if ( error )
F_10 ( V_12 , L_51
L_52 ) ;
F_98 ( F_94 ( & V_12 -> V_268 ) != 0 ) ;
F_99 ( V_12 ) ;
}
STATIC int
F_100 (
struct V_14 * V_15 ,
struct V_11 * V_12 ,
char * V_13 )
{
int error = 0 ;
struct V_11 * V_270 ;
V_270 = F_101 ( sizeof( * V_270 ) , V_271 ) ;
if ( ! V_270 )
return - V_9 ;
V_270 -> V_16 = V_15 ;
error = F_5 ( V_270 , V_13 ) ;
F_72 ( V_270 ) ;
F_4 ( V_270 ) ;
return error ;
}
STATIC int
F_102 (
struct V_14 * V_15 ,
int * V_272 ,
char * V_13 )
{
struct V_11 * V_12 = F_74 ( V_15 ) ;
T_5 * V_144 = & V_12 -> V_145 ;
T_1 args [ V_18 ] ;
char * V_17 ;
int error ;
error = F_100 ( V_15 , V_12 , V_13 ) ;
if ( error )
return error ;
F_103 ( V_15 ) ;
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
V_12 -> V_273 = F_23 ( V_12 , V_144 -> V_274 ) ;
break;
case V_66 :
V_12 -> V_30 |= V_67 ;
V_12 -> V_273 = F_23 ( V_12 , V_144 -> V_274 ) ;
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
if ( ( V_12 -> V_30 & V_31 ) && ! ( * V_272 & V_29 ) ) {
if ( V_12 -> V_30 & V_59 ) {
F_10 ( V_12 ,
L_53 ) ;
return - V_10 ;
}
if ( F_104 ( V_144 ) == V_275 &&
F_105 ( V_144 ,
V_276 ) ) {
F_10 ( V_12 ,
L_54 ,
( V_144 -> V_277 &
V_276 ) ) ;
return - V_10 ;
}
V_12 -> V_30 &= ~ V_31 ;
if ( V_12 -> V_278 ) {
error = F_106 ( V_12 , false ) ;
if ( error ) {
F_10 ( V_12 , L_55 ) ;
return error ;
}
V_12 -> V_278 = false ;
}
F_91 ( V_12 ) ;
F_107 ( V_12 ) ;
}
if ( ! ( V_12 -> V_30 & V_31 ) && ( * V_272 & V_29 ) ) {
F_89 ( V_12 ) ;
F_93 ( V_12 ) ;
V_12 -> V_30 |= V_31 ;
}
return 0 ;
}
STATIC int
F_108 (
struct V_14 * V_15 )
{
struct V_11 * V_12 = F_74 ( V_15 ) ;
F_89 ( V_12 ) ;
F_93 ( V_12 ) ;
return F_106 ( V_12 , true ) ;
}
STATIC int
F_109 (
struct V_14 * V_15 )
{
struct V_11 * V_12 = F_74 ( V_15 ) ;
F_91 ( V_12 ) ;
F_107 ( V_12 ) ;
return 0 ;
}
STATIC int
F_110 (
struct V_125 * V_126 ,
struct V_229 * V_279 )
{
return F_16 ( F_74 ( V_279 -> V_232 ) , V_126 ) ;
}
STATIC int
F_111 (
struct V_11 * V_12 )
{
int V_280 = ( V_12 -> V_30 & V_31 ) ;
if ( F_112 ( & V_12 -> V_145 ) ) {
if ( V_12 -> V_39 <= 0 &&
V_12 -> V_145 . V_281 > V_282 ) {
V_12 -> V_39 = V_12 -> V_145 . V_281 ;
} else if ( V_12 -> V_39 > 0 &&
V_12 -> V_39 < V_12 -> V_145 . V_281 ) {
F_10 ( V_12 ,
L_56 ) ;
return - V_10 ;
}
} else {
if ( V_12 -> V_39 > V_282 ) {
F_10 ( V_12 ,
L_57 ) ;
return - V_10 ;
}
}
if ( F_113 ( & V_12 -> V_145 ) &&
( V_12 -> V_30 & V_81 ) ) {
F_10 ( V_12 , L_58
L_59 ) ;
return - V_10 ;
}
if ( F_114 ( & V_12 -> V_145 ) &&
! ( V_12 -> V_30 & V_81 ) )
V_12 -> V_30 |= V_79 ;
if ( ( V_12 -> V_145 . V_283 & V_284 ) && ! V_280 ) {
F_10 ( V_12 ,
L_60 ) ;
return - V_285 ;
}
if ( ( V_12 -> V_85 & ( V_105 | V_106 ) ) &&
( V_12 -> V_85 & ( V_99 | V_100 ) ) &&
! F_115 ( & V_12 -> V_145 ) ) {
F_10 ( V_12 ,
L_61 ) ;
return - V_10 ;
}
return 0 ;
}
static int
F_116 (
struct V_11 * V_12 )
{
int error ;
error = F_117 ( & V_12 -> V_246 , 0 , V_26 ) ;
if ( error )
return - V_9 ;
error = F_117 ( & V_12 -> V_247 , 0 , V_26 ) ;
if ( error )
goto V_286;
error = F_117 ( & V_12 -> V_248 , 0 , V_26 ) ;
if ( error )
goto V_287;
return 0 ;
V_287:
F_118 ( & V_12 -> V_247 ) ;
V_286:
F_118 ( & V_12 -> V_246 ) ;
return - V_9 ;
}
void
F_119 (
struct V_11 * V_12 )
{
F_120 ( & V_12 -> V_246 , V_12 -> V_145 . V_260 ) ;
F_120 ( & V_12 -> V_247 , V_12 -> V_145 . V_288 ) ;
F_120 ( & V_12 -> V_248 , V_12 -> V_145 . V_289 ) ;
}
static void
F_121 (
struct V_11 * V_12 )
{
F_118 ( & V_12 -> V_246 ) ;
F_118 ( & V_12 -> V_247 ) ;
F_118 ( & V_12 -> V_248 ) ;
}
STATIC int
F_122 (
struct V_14 * V_15 ,
void * V_290 ,
int V_291 )
{
struct V_203 * V_279 ;
struct V_11 * V_12 = NULL ;
int V_272 = 0 , error = - V_9 ;
V_12 = F_123 ( sizeof( struct V_11 ) , V_26 ) ;
if ( ! V_12 )
goto V_177;
F_68 ( & V_12 -> V_249 ) ;
F_124 ( & V_12 -> V_292 ) ;
F_67 ( & V_12 -> V_268 , 0 ) ;
F_125 ( & V_12 -> V_293 , V_294 ) ;
F_125 ( & V_12 -> V_295 , V_296 ) ;
V_12 -> V_297 . V_298 . V_299 = V_300 ;
V_12 -> V_16 = V_15 ;
V_15 -> V_301 = V_12 ;
error = F_5 ( V_12 , ( char * ) V_290 ) ;
if ( error )
goto V_302;
F_126 ( V_15 , V_184 ) ;
V_15 -> V_303 = V_304 ;
V_15 -> V_305 = & V_306 ;
#ifdef F_13
V_15 -> V_307 = & V_308 ;
V_15 -> V_309 = V_310 | V_311 | V_312 ;
#endif
V_15 -> V_313 = & V_314 ;
if ( V_291 )
V_272 |= V_315 ;
error = F_39 ( V_12 ) ;
if ( error )
goto V_302;
error = F_44 ( V_12 ) ;
if ( error )
goto V_316;
error = F_116 ( V_12 ) ;
if ( error )
goto V_317;
V_12 -> V_318 . V_319 = F_127 ( struct V_320 ) ;
if ( ! V_12 -> V_318 . V_319 ) {
error = - V_9 ;
goto V_321;
}
error = F_128 ( V_12 , V_272 ) ;
if ( error )
goto V_322;
error = F_111 ( V_12 ) ;
if ( error )
goto V_323;
error = F_41 ( V_12 ) ;
if ( error )
goto V_323;
error = F_129 ( V_12 ) ;
if ( error )
goto V_323;
V_15 -> V_324 = V_240 ;
V_15 -> V_325 = V_12 -> V_145 . V_251 ;
V_15 -> V_326 = F_11 ( V_15 -> V_325 ) - 1 ;
V_15 -> V_327 = F_21 ( V_15 -> V_326 ) ;
V_15 -> V_328 = V_329 ;
V_15 -> V_330 = 1 ;
F_130 ( V_15 ) ;
if ( F_104 ( & V_12 -> V_145 ) == V_275 )
V_15 -> V_28 |= V_331 ;
if ( V_12 -> V_30 & V_113 ) {
F_10 ( V_12 ,
L_62 ) ;
error = F_131 ( V_15 , V_15 -> V_325 ) ;
if ( error ) {
F_132 ( V_12 ,
L_63 ) ;
V_12 -> V_30 &= ~ V_113 ;
}
}
if ( F_133 ( & V_12 -> V_145 ) )
F_132 ( V_12 ,
L_64 ) ;
error = F_134 ( V_12 ) ;
if ( error )
goto V_332;
V_279 = F_135 ( F_66 ( V_12 -> V_333 ) ) ;
if ( ! V_279 ) {
error = - V_334 ;
goto V_335;
}
V_15 -> V_336 = F_136 ( V_279 ) ;
if ( ! V_15 -> V_336 ) {
error = - V_9 ;
goto V_335;
}
return 0 ;
V_332:
F_137 ( V_12 ) ;
V_323:
F_138 ( V_12 ) ;
V_322:
F_139 ( V_12 -> V_318 . V_319 ) ;
V_321:
F_121 ( V_12 ) ;
V_317:
F_47 ( V_12 ) ;
V_316:
F_37 ( V_12 ) ;
V_302:
F_72 ( V_12 ) ;
F_4 ( V_12 ) ;
V_177:
return error ;
V_335:
F_137 ( V_12 ) ;
F_140 ( V_12 ) ;
goto V_323;
}
STATIC void
F_141 (
struct V_14 * V_15 )
{
struct V_11 * V_12 = F_74 ( V_15 ) ;
F_142 ( V_12 , L_65 ) ;
F_137 ( V_12 ) ;
F_140 ( V_12 ) ;
F_138 ( V_12 ) ;
F_139 ( V_12 -> V_318 . V_319 ) ;
F_121 ( V_12 ) ;
F_47 ( V_12 ) ;
F_37 ( V_12 ) ;
F_72 ( V_12 ) ;
F_4 ( V_12 ) ;
}
STATIC struct V_229 *
F_143 (
struct V_337 * V_338 ,
int V_272 ,
const char * V_339 ,
void * V_290 )
{
return F_144 ( V_338 , V_272 , V_339 , V_290 , F_122 ) ;
}
static long
F_145 (
struct V_14 * V_15 ,
struct V_340 * V_341 )
{
return F_146 ( F_74 ( V_15 ) ) ;
}
static long
F_147 (
struct V_14 * V_15 ,
struct V_340 * V_341 )
{
return F_148 ( F_74 ( V_15 ) , V_341 -> V_342 ) ;
}
STATIC int T_12
F_149 ( void )
{
V_343 = F_150 ( 4 * V_344 ,
F_151 ( struct V_345 , V_346 ) ) ;
if ( ! V_343 )
goto V_177;
V_347 = F_152 ( sizeof( V_348 ) ,
L_66 ) ;
if ( ! V_347 )
goto V_349;
V_350 = F_152 ( sizeof( V_351 ) ,
L_67 ) ;
if ( ! V_350 )
goto V_352;
V_353 = F_152 ( sizeof( V_354 ) ,
L_68 ) ;
if ( ! V_353 )
goto V_355;
V_356 = F_152 ( sizeof( V_357 ) ,
L_69 ) ;
if ( ! V_356 )
goto V_358;
V_359 = F_152 ( sizeof( V_360 ) , L_70 ) ;
if ( ! V_359 )
goto V_361;
V_362 = F_152 ( sizeof( V_363 ) , L_71 ) ;
if ( ! V_362 )
goto V_364;
V_365 =
F_152 ( sizeof( struct V_366 ) ,
L_72 ) ;
if ( ! V_365 )
goto V_367;
V_368 = F_152 ( sizeof( struct V_369 ) ,
L_73 ) ;
if ( ! V_368 )
goto V_370;
V_371 = F_152 ( ( sizeof( V_372 ) +
( ( V_373 - 1 ) *
sizeof( V_374 ) ) ) , L_74 ) ;
if ( ! V_371 )
goto V_375;
V_376 = F_152 ( ( sizeof( V_377 ) +
( ( V_378 - 1 ) *
sizeof( V_374 ) ) ) , L_75 ) ;
if ( ! V_376 )
goto V_379;
V_380 =
F_153 ( sizeof( V_381 ) , L_76 ,
V_382 | V_383 | V_384 |
V_385 , F_64 ) ;
if ( ! V_380 )
goto V_386;
V_387 =
F_153 ( sizeof( V_388 ) , L_77 ,
V_384 , NULL ) ;
if ( ! V_387 )
goto V_389;
V_390 = F_152 ( sizeof( struct V_391 ) ,
L_78 ) ;
if ( ! V_390 )
goto V_392;
return 0 ;
V_392:
F_154 ( V_387 ) ;
V_389:
F_154 ( V_380 ) ;
V_386:
F_154 ( V_376 ) ;
V_379:
F_154 ( V_371 ) ;
V_375:
F_154 ( V_368 ) ;
V_370:
F_154 ( V_365 ) ;
V_367:
F_154 ( V_362 ) ;
V_364:
F_154 ( V_359 ) ;
V_361:
F_154 ( V_356 ) ;
V_358:
F_154 ( V_353 ) ;
V_355:
F_154 ( V_350 ) ;
V_352:
F_154 ( V_347 ) ;
V_349:
F_155 ( V_343 ) ;
V_177:
return - V_9 ;
}
STATIC void
F_156 ( void )
{
F_157 () ;
F_154 ( V_390 ) ;
F_154 ( V_387 ) ;
F_154 ( V_380 ) ;
F_154 ( V_376 ) ;
F_154 ( V_371 ) ;
F_154 ( V_368 ) ;
F_154 ( V_365 ) ;
F_154 ( V_362 ) ;
F_154 ( V_359 ) ;
F_154 ( V_356 ) ;
F_154 ( V_353 ) ;
F_154 ( V_350 ) ;
F_154 ( V_347 ) ;
F_155 ( V_343 ) ;
}
STATIC int T_12
F_158 ( void )
{
V_393 = F_45 ( L_79 ,
V_187 | V_188 , 0 ) ;
if ( ! V_393 )
return - V_9 ;
return 0 ;
}
STATIC void
F_159 ( void )
{
F_46 ( V_393 ) ;
}
STATIC int T_12
F_160 ( void )
{
int error ;
F_161 () ;
F_162 (KERN_INFO XFS_VERSION_STRING L_80
XFS_BUILD_OPTIONS L_81 ) ;
F_163 () ;
error = F_149 () ;
if ( error )
goto V_177;
error = F_158 () ;
if ( error )
goto V_394;
error = F_164 () ;
if ( error )
goto V_395;
error = F_165 () ;
if ( error )
goto V_396;
error = F_166 () ;
if ( error )
goto V_397;
error = F_167 () ;
if ( error )
goto V_398;
V_300 = F_168 ( L_82 , NULL , V_399 ) ;
if ( ! V_300 ) {
error = - V_9 ;
goto V_400;
}
V_320 . V_401 . V_298 . V_299 = V_300 ;
V_320 . V_319 = F_127 ( struct V_320 ) ;
if ( ! V_320 . V_319 ) {
error = - V_9 ;
goto V_402;
}
error = F_169 ( & V_320 . V_401 , & V_403 , NULL ,
L_83 ) ;
if ( error )
goto V_322;
#ifdef F_170
V_404 . V_298 . V_299 = V_300 ;
error = F_169 ( & V_404 , & V_405 , NULL , L_84 ) ;
if ( error )
goto V_406;
#endif
error = F_171 () ;
if ( error )
goto V_407;
error = F_172 ( & V_408 ) ;
if ( error )
goto V_409;
return 0 ;
V_409:
F_173 () ;
V_407:
#ifdef F_170
F_174 ( & V_404 ) ;
V_406:
#endif
F_174 ( & V_320 . V_401 ) ;
V_322:
F_139 ( V_320 . V_319 ) ;
V_402:
F_175 ( V_300 ) ;
V_400:
F_176 () ;
V_398:
F_177 () ;
V_397:
F_178 () ;
V_396:
F_179 () ;
V_395:
F_159 () ;
V_394:
F_156 () ;
V_177:
return error ;
}
STATIC void T_13
F_180 ( void )
{
F_173 () ;
F_181 ( & V_408 ) ;
#ifdef F_170
F_174 ( & V_404 ) ;
#endif
F_174 ( & V_320 . V_401 ) ;
F_139 ( V_320 . V_319 ) ;
F_175 ( V_300 ) ;
F_176 () ;
F_177 () ;
F_178 () ;
F_179 () ;
F_159 () ;
F_156 () ;
F_182 () ;
}
