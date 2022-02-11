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
F_57 ( V_205 -> V_206 , V_207 ) ;
ASSERT ( F_58 ( V_205 -> V_206 ) || V_205 -> V_208 == 0 ) ;
F_59 ( ! F_60 ( V_205 , V_209 ) ) ;
F_59 ( ! F_60 ( V_205 , V_210 ) ) ;
F_61 ( V_205 ) ;
}
STATIC void
F_62 (
void * V_203 )
{
struct V_204 * V_205 = V_203 ;
memset ( V_205 , 0 , sizeof( struct V_204 ) ) ;
F_63 ( F_64 ( V_205 ) ) ;
F_65 ( & V_205 -> V_211 , 0 ) ;
F_66 ( & V_205 -> V_212 ) ;
F_67 ( & V_205 -> V_213 , V_214 | V_215 ,
L_50 , V_205 -> V_216 ) ;
F_67 ( & V_205 -> V_217 , V_214 | V_215 ,
L_50 , V_205 -> V_216 ) ;
}
STATIC void
F_68 (
struct V_203 * V_203 )
{
T_10 * V_205 = F_55 ( V_203 ) ;
ASSERT ( ! F_69 ( & V_205 -> V_218 . V_219 ) ) ;
F_70 ( V_205 ) ;
F_71 ( & V_203 -> V_220 ) ;
F_72 ( V_203 ) ;
F_57 ( V_205 -> V_206 , V_221 ) ;
F_57 ( V_205 -> V_206 , V_222 ) ;
F_73 ( V_205 ) ;
}
STATIC int
F_74 (
struct V_203 * V_203 )
{
struct V_204 * V_205 = F_55 ( V_203 ) ;
return F_75 ( V_203 ) || ( V_205 -> V_223 & V_224 ) ;
}
STATIC void
F_76 (
struct V_11 * V_12 )
{
F_4 ( V_12 -> V_23 ) ;
F_4 ( V_12 -> V_49 ) ;
F_4 ( V_12 -> V_46 ) ;
}
STATIC int
F_77 (
struct V_14 * V_15 ,
int V_225 )
{
struct V_11 * V_12 = F_78 ( V_15 ) ;
if ( ! V_225 )
return 0 ;
F_79 ( V_12 , V_226 ) ;
if ( V_227 ) {
F_80 ( & V_12 -> V_228 -> V_229 ) ;
}
return 0 ;
}
STATIC int
F_81 (
struct V_230 * V_230 ,
struct V_231 * V_232 )
{
struct V_11 * V_12 = F_78 ( V_230 -> V_233 ) ;
T_5 * V_144 = & V_12 -> V_145 ;
struct V_204 * V_205 = F_55 ( F_82 ( V_230 ) ) ;
T_3 V_234 , V_235 ;
T_3 V_150 ;
T_3 V_236 ;
T_3 V_237 ;
T_11 V_238 ;
T_12 V_239 ;
V_232 -> V_240 = V_241 ;
V_232 -> V_242 = V_25 - 1 ;
V_235 = F_83 ( V_12 -> V_171 -> V_243 ) ;
V_232 -> V_244 . V_245 [ 0 ] = ( V_246 ) V_235 ;
V_232 -> V_244 . V_245 [ 1 ] = ( V_246 ) ( V_235 >> 32 ) ;
V_150 = F_84 ( & V_12 -> V_247 ) ;
V_236 = F_84 ( & V_12 -> V_248 ) ;
V_237 = F_84 ( & V_12 -> V_249 ) ;
F_85 ( & V_12 -> V_250 ) ;
V_232 -> V_251 = V_144 -> V_252 ;
V_238 = V_144 -> V_253 ? V_144 -> V_254 : 0 ;
V_232 -> V_255 = V_144 -> V_151 - V_238 ;
F_86 ( & V_12 -> V_250 ) ;
V_232 -> V_256 = V_237 - F_87 ( V_12 ) ;
V_232 -> V_257 = V_232 -> V_256 ;
V_234 = V_232 -> V_256 << V_144 -> V_258 ;
V_232 -> V_259 = F_88 ( V_150 + V_234 , ( T_3 ) V_260 ) ;
if ( V_12 -> V_149 )
V_232 -> V_259 = F_89 ( F_90 ( V_232 -> V_259 ) ,
V_232 -> V_259 ,
V_12 -> V_149 ) ;
V_232 -> V_259 = F_91 ( F_90 ( V_232 -> V_259 ) ,
V_232 -> V_259 ,
V_144 -> V_261 ) ;
V_239 = V_232 -> V_259 - ( V_150 - V_236 ) ;
V_232 -> V_262 = F_91 ( T_12 , V_239 , 0 ) ;
if ( ( V_205 -> V_263 . V_264 & V_265 ) &&
( ( V_12 -> V_85 & ( V_99 | V_101 ) ) ) ==
( V_99 | V_101 ) )
F_92 ( V_205 , V_232 ) ;
return 0 ;
}
STATIC void
F_93 ( struct V_11 * V_12 )
{
T_3 V_266 = 0 ;
V_12 -> V_267 = V_12 -> V_268 ;
F_94 ( V_12 , & V_266 , NULL ) ;
}
STATIC void
F_95 ( struct V_11 * V_12 )
{
T_3 V_266 ;
if ( V_12 -> V_267 ) {
V_266 = V_12 -> V_267 ;
V_12 -> V_267 = 0 ;
} else
V_266 = F_96 ( V_12 ) ;
F_94 ( V_12 , & V_266 , NULL ) ;
}
static void
F_97 (
struct V_11 * V_12 )
{
int error = 0 ;
while ( F_98 ( & V_12 -> V_269 ) > 0 )
F_99 ( 100 ) ;
F_79 ( V_12 , V_226 ) ;
F_100 ( V_12 , 0 ) ;
F_100 ( V_12 , V_270 ) ;
error = F_101 ( V_12 ) ;
if ( error )
F_10 ( V_12 , L_51
L_52 ) ;
F_102 ( F_98 ( & V_12 -> V_269 ) != 0 ) ;
F_103 ( V_12 ) ;
}
STATIC int
F_104 (
struct V_14 * V_15 ,
struct V_11 * V_12 ,
char * V_13 )
{
int error = 0 ;
struct V_11 * V_271 ;
V_271 = F_105 ( sizeof( * V_271 ) , V_272 ) ;
if ( ! V_271 )
return - V_9 ;
V_271 -> V_16 = V_15 ;
error = F_5 ( V_271 , V_13 ) ;
F_76 ( V_271 ) ;
F_4 ( V_271 ) ;
return error ;
}
STATIC int
F_106 (
struct V_14 * V_15 ,
int * V_273 ,
char * V_13 )
{
struct V_11 * V_12 = F_78 ( V_15 ) ;
T_5 * V_144 = & V_12 -> V_145 ;
T_1 args [ V_18 ] ;
char * V_17 ;
int error ;
error = F_104 ( V_15 , V_12 , V_13 ) ;
if ( error )
return error ;
F_107 ( V_15 ) ;
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
V_12 -> V_30 &= ~ V_31 ;
if ( V_12 -> V_276 ) {
error = F_108 ( V_12 , false ) ;
if ( error ) {
F_10 ( V_12 , L_54 ) ;
return error ;
}
V_12 -> V_276 = false ;
}
F_95 ( V_12 ) ;
F_109 ( V_12 ) ;
}
if ( ! ( V_12 -> V_30 & V_31 ) && ( * V_273 & V_29 ) ) {
F_93 ( V_12 ) ;
F_97 ( V_12 ) ;
V_12 -> V_30 |= V_31 ;
}
return 0 ;
}
STATIC int
F_110 (
struct V_14 * V_15 )
{
struct V_11 * V_12 = F_78 ( V_15 ) ;
F_93 ( V_12 ) ;
F_97 ( V_12 ) ;
return F_108 ( V_12 , true ) ;
}
STATIC int
F_111 (
struct V_14 * V_15 )
{
struct V_11 * V_12 = F_78 ( V_15 ) ;
F_95 ( V_12 ) ;
F_109 ( V_12 ) ;
return 0 ;
}
STATIC int
F_112 (
struct V_125 * V_126 ,
struct V_230 * V_277 )
{
return F_16 ( F_78 ( V_277 -> V_233 ) , V_126 ) ;
}
STATIC int
F_113 (
struct V_11 * V_12 )
{
int V_278 = ( V_12 -> V_30 & V_31 ) ;
if ( F_114 ( & V_12 -> V_145 ) ) {
if ( V_12 -> V_39 <= 0 &&
V_12 -> V_145 . V_279 > V_280 ) {
V_12 -> V_39 = V_12 -> V_145 . V_279 ;
} else if ( V_12 -> V_39 > 0 &&
V_12 -> V_39 < V_12 -> V_145 . V_279 ) {
F_10 ( V_12 ,
L_55 ) ;
return - V_10 ;
}
} else {
if ( V_12 -> V_39 > V_280 ) {
F_10 ( V_12 ,
L_56 ) ;
return - V_10 ;
}
}
if ( F_115 ( & V_12 -> V_145 ) &&
( V_12 -> V_30 & V_81 ) ) {
F_10 ( V_12 , L_57
L_58 ) ;
return - V_10 ;
}
if ( F_116 ( & V_12 -> V_145 ) &&
! ( V_12 -> V_30 & V_81 ) )
V_12 -> V_30 |= V_79 ;
if ( ( V_12 -> V_145 . V_281 & V_282 ) && ! V_278 ) {
F_10 ( V_12 ,
L_59 ) ;
return - V_283 ;
}
if ( ( V_12 -> V_85 & ( V_105 | V_106 ) ) &&
( V_12 -> V_85 & ( V_99 | V_100 ) ) &&
! F_117 ( & V_12 -> V_145 ) ) {
F_10 ( V_12 ,
L_60 ) ;
return - V_10 ;
}
return 0 ;
}
static int
F_118 (
struct V_11 * V_12 )
{
int error ;
error = F_119 ( & V_12 -> V_247 , 0 , V_26 ) ;
if ( error )
return - V_9 ;
error = F_119 ( & V_12 -> V_248 , 0 , V_26 ) ;
if ( error )
goto V_284;
error = F_119 ( & V_12 -> V_249 , 0 , V_26 ) ;
if ( error )
goto V_285;
return 0 ;
V_285:
F_120 ( & V_12 -> V_248 ) ;
V_284:
F_120 ( & V_12 -> V_247 ) ;
return - V_9 ;
}
void
F_121 (
struct V_11 * V_12 )
{
F_122 ( & V_12 -> V_247 , V_12 -> V_145 . V_261 ) ;
F_122 ( & V_12 -> V_248 , V_12 -> V_145 . V_286 ) ;
F_122 ( & V_12 -> V_249 , V_12 -> V_145 . V_287 ) ;
}
static void
F_123 (
struct V_11 * V_12 )
{
F_120 ( & V_12 -> V_247 ) ;
F_120 ( & V_12 -> V_248 ) ;
F_120 ( & V_12 -> V_249 ) ;
}
STATIC int
F_124 (
struct V_14 * V_15 ,
void * V_288 ,
int V_289 )
{
struct V_203 * V_277 ;
struct V_11 * V_12 = NULL ;
int V_273 = 0 , error = - V_9 ;
V_12 = F_125 ( sizeof( struct V_11 ) , V_26 ) ;
if ( ! V_12 )
goto V_177;
F_66 ( & V_12 -> V_250 ) ;
F_126 ( & V_12 -> V_290 ) ;
F_65 ( & V_12 -> V_269 , 0 ) ;
F_127 ( & V_12 -> V_291 , V_292 ) ;
F_127 ( & V_12 -> V_293 , V_294 ) ;
V_12 -> V_295 . V_296 . V_297 = V_298 ;
V_12 -> V_16 = V_15 ;
V_15 -> V_299 = V_12 ;
error = F_5 ( V_12 , ( char * ) V_288 ) ;
if ( error )
goto V_300;
F_128 ( V_15 , V_184 ) ;
V_15 -> V_301 = V_302 ;
V_15 -> V_303 = & V_304 ;
#ifdef F_13
V_15 -> V_305 = & V_306 ;
V_15 -> V_307 = V_308 | V_309 | V_310 ;
#endif
V_15 -> V_311 = & V_312 ;
if ( V_289 )
V_273 |= V_313 ;
error = F_39 ( V_12 ) ;
if ( error )
goto V_300;
error = F_44 ( V_12 ) ;
if ( error )
goto V_314;
error = F_118 ( V_12 ) ;
if ( error )
goto V_315;
V_12 -> V_316 . V_317 = F_129 ( struct V_318 ) ;
if ( ! V_12 -> V_316 . V_317 ) {
error = - V_9 ;
goto V_319;
}
error = F_130 ( V_12 , V_273 ) ;
if ( error )
goto V_320;
error = F_113 ( V_12 ) ;
if ( error )
goto V_321;
error = F_41 ( V_12 ) ;
if ( error )
goto V_321;
error = F_131 ( V_12 ) ;
if ( error )
goto V_321;
V_15 -> V_322 = V_241 ;
V_15 -> V_323 = V_12 -> V_145 . V_252 ;
V_15 -> V_324 = F_11 ( V_15 -> V_323 ) - 1 ;
V_15 -> V_325 = F_21 ( V_15 -> V_324 ) ;
V_15 -> V_326 = V_327 ;
V_15 -> V_328 = 1 ;
F_132 ( V_15 ) ;
if ( F_133 ( & V_12 -> V_145 ) == V_329 )
V_15 -> V_28 |= V_330 ;
if ( V_12 -> V_30 & V_113 ) {
F_10 ( V_12 ,
L_61 ) ;
if ( V_15 -> V_323 != V_139 ) {
F_134 ( V_12 ,
L_62 ) ;
V_12 -> V_30 &= ~ V_113 ;
} else if ( ! V_15 -> V_176 -> V_331 -> V_332 -> V_333 ) {
F_134 ( V_12 ,
L_63 ) ;
V_12 -> V_30 &= ~ V_113 ;
}
}
if ( F_135 ( & V_12 -> V_145 ) )
F_134 ( V_12 ,
L_64 ) ;
error = F_136 ( V_12 ) ;
if ( error )
goto V_334;
V_277 = F_137 ( F_64 ( V_12 -> V_335 ) ) ;
if ( ! V_277 ) {
error = - V_336 ;
goto V_337;
}
V_15 -> V_338 = F_138 ( V_277 ) ;
if ( ! V_15 -> V_338 ) {
error = - V_9 ;
goto V_337;
}
return 0 ;
V_334:
F_139 ( V_12 ) ;
V_321:
F_140 ( V_12 ) ;
V_320:
F_141 ( V_12 -> V_316 . V_317 ) ;
V_319:
F_123 ( V_12 ) ;
V_315:
F_47 ( V_12 ) ;
V_314:
F_37 ( V_12 ) ;
V_300:
F_76 ( V_12 ) ;
F_4 ( V_12 ) ;
V_177:
return error ;
V_337:
F_139 ( V_12 ) ;
F_142 ( V_12 ) ;
goto V_321;
}
STATIC void
F_143 (
struct V_14 * V_15 )
{
struct V_11 * V_12 = F_78 ( V_15 ) ;
F_144 ( V_12 , L_65 ) ;
F_139 ( V_12 ) ;
F_142 ( V_12 ) ;
F_140 ( V_12 ) ;
F_141 ( V_12 -> V_316 . V_317 ) ;
F_123 ( V_12 ) ;
F_47 ( V_12 ) ;
F_37 ( V_12 ) ;
F_76 ( V_12 ) ;
F_4 ( V_12 ) ;
}
STATIC struct V_230 *
F_145 (
struct V_339 * V_340 ,
int V_273 ,
const char * V_341 ,
void * V_288 )
{
return F_146 ( V_340 , V_273 , V_341 , V_288 , F_124 ) ;
}
static long
F_147 (
struct V_14 * V_15 ,
struct V_342 * V_343 )
{
return F_148 ( F_78 ( V_15 ) ) ;
}
static long
F_149 (
struct V_14 * V_15 ,
struct V_342 * V_343 )
{
return F_150 ( F_78 ( V_15 ) , V_343 -> V_344 ) ;
}
STATIC int T_13
F_151 ( void )
{
V_345 = F_152 ( sizeof( V_346 ) , L_66 ) ;
if ( ! V_345 )
goto V_177;
V_347 = F_153 ( 4 * V_348 ,
V_345 ) ;
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
V_359 = F_152 ( sizeof( V_360 ) ,
L_70 ) ;
if ( ! V_359 )
goto V_361;
V_362 = F_152 ( sizeof( V_363 ) , L_71 ) ;
if ( ! V_362 )
goto V_364;
V_365 = F_152 ( sizeof( V_366 ) , L_72 ) ;
if ( ! V_365 )
goto V_367;
V_368 =
F_152 ( sizeof( struct V_369 ) ,
L_73 ) ;
if ( ! V_368 )
goto V_370;
V_371 = F_152 ( sizeof( struct V_372 ) ,
L_74 ) ;
if ( ! V_371 )
goto V_373;
V_374 = F_152 ( ( sizeof( V_375 ) +
( ( V_376 - 1 ) *
sizeof( V_377 ) ) ) , L_75 ) ;
if ( ! V_374 )
goto V_378;
V_379 = F_152 ( ( sizeof( V_380 ) +
( ( V_381 - 1 ) *
sizeof( V_377 ) ) ) , L_76 ) ;
if ( ! V_379 )
goto V_382;
V_383 =
F_154 ( sizeof( T_10 ) , L_77 ,
V_384 | V_385 | V_386 |
V_387 , F_62 ) ;
if ( ! V_383 )
goto V_388;
V_389 =
F_154 ( sizeof( V_390 ) , L_78 ,
V_386 , NULL ) ;
if ( ! V_389 )
goto V_391;
V_392 = F_152 ( sizeof( struct V_393 ) ,
L_79 ) ;
if ( ! V_392 )
goto V_394;
return 0 ;
V_394:
F_155 ( V_389 ) ;
V_391:
F_155 ( V_383 ) ;
V_388:
F_155 ( V_379 ) ;
V_382:
F_155 ( V_374 ) ;
V_378:
F_155 ( V_371 ) ;
V_373:
F_155 ( V_368 ) ;
V_370:
F_155 ( V_365 ) ;
V_367:
F_155 ( V_362 ) ;
V_364:
F_155 ( V_359 ) ;
V_361:
F_155 ( V_356 ) ;
V_358:
F_155 ( V_353 ) ;
V_355:
F_155 ( V_350 ) ;
V_352:
F_156 ( V_347 ) ;
V_349:
F_155 ( V_345 ) ;
V_177:
return - V_9 ;
}
STATIC void
F_157 ( void )
{
F_158 () ;
F_155 ( V_392 ) ;
F_155 ( V_389 ) ;
F_155 ( V_383 ) ;
F_155 ( V_379 ) ;
F_155 ( V_374 ) ;
F_155 ( V_371 ) ;
F_155 ( V_368 ) ;
F_155 ( V_365 ) ;
F_155 ( V_362 ) ;
F_155 ( V_359 ) ;
F_155 ( V_356 ) ;
F_155 ( V_353 ) ;
F_155 ( V_350 ) ;
F_156 ( V_347 ) ;
F_155 ( V_345 ) ;
}
STATIC int T_13
F_159 ( void )
{
V_395 = F_45 ( L_80 ,
V_187 | V_188 , 0 ) ;
if ( ! V_395 )
return - V_9 ;
return 0 ;
}
STATIC void
F_160 ( void )
{
F_46 ( V_395 ) ;
}
STATIC int T_13
F_161 ( void )
{
int error ;
F_162 () ;
F_163 (KERN_INFO XFS_VERSION_STRING L_81
XFS_BUILD_OPTIONS L_82 ) ;
F_164 () ;
error = F_151 () ;
if ( error )
goto V_177;
error = F_159 () ;
if ( error )
goto V_396;
error = F_165 () ;
if ( error )
goto V_397;
error = F_166 () ;
if ( error )
goto V_398;
error = F_167 () ;
if ( error )
goto V_399;
error = F_168 () ;
if ( error )
goto V_400;
V_298 = F_169 ( L_83 , NULL , V_401 ) ;
if ( ! V_298 ) {
error = - V_9 ;
goto V_402;
}
V_318 . V_403 . V_296 . V_297 = V_298 ;
V_318 . V_317 = F_129 ( struct V_318 ) ;
if ( ! V_318 . V_317 ) {
error = - V_9 ;
goto V_404;
}
error = F_170 ( & V_318 . V_403 , & V_405 , NULL ,
L_84 ) ;
if ( error )
goto V_320;
#ifdef F_171
V_406 . V_296 . V_297 = V_298 ;
error = F_170 ( & V_406 , & V_407 , NULL , L_85 ) ;
if ( error )
goto V_408;
#endif
error = F_172 () ;
if ( error )
goto V_409;
error = F_173 ( & V_410 ) ;
if ( error )
goto V_411;
return 0 ;
V_411:
F_174 () ;
V_409:
#ifdef F_171
F_175 ( & V_406 ) ;
V_408:
#endif
F_175 ( & V_318 . V_403 ) ;
V_320:
F_141 ( V_318 . V_317 ) ;
V_404:
F_176 ( V_298 ) ;
V_402:
F_177 () ;
V_400:
F_178 () ;
V_399:
F_179 () ;
V_398:
F_180 () ;
V_397:
F_160 () ;
V_396:
F_157 () ;
V_177:
return error ;
}
STATIC void T_14
F_181 ( void )
{
F_174 () ;
F_182 ( & V_410 ) ;
#ifdef F_171
F_175 ( & V_406 ) ;
#endif
F_175 ( & V_318 . V_403 ) ;
F_141 ( V_318 . V_317 ) ;
F_176 ( V_298 ) ;
F_177 () ;
F_178 () ;
F_179 () ;
F_180 () ;
F_160 () ;
F_157 () ;
F_183 () ;
}
