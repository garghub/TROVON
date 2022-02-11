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
V_12 -> V_30 |= V_72 ;
break;
case V_73 :
V_12 -> V_30 &= ~ V_72 ;
break;
case V_74 :
V_12 -> V_30 &= ~ V_37 ;
break;
case V_75 :
V_12 -> V_30 |= V_37 ;
break;
case V_76 :
V_12 -> V_30 |= V_77 ;
break;
case V_78 :
V_12 -> V_30 &= ~ V_77 ;
V_12 -> V_30 |= V_79 ;
break;
case V_80 :
V_12 -> V_30 |= V_81 ;
break;
case V_82 :
V_12 -> V_83 &= ~ V_84 ;
V_12 -> V_83 &= ~ V_85 ;
V_12 -> V_83 &= ~ V_86 ;
break;
case V_87 :
case V_88 :
case V_89 :
V_12 -> V_83 |= ( V_90 | V_91 |
V_92 ) ;
break;
case V_93 :
case V_94 :
V_12 -> V_83 |= ( V_90 | V_91 ) ;
V_12 -> V_83 &= ~ V_92 ;
break;
case V_95 :
case V_96 :
V_12 -> V_83 |= ( V_97 | V_98 |
V_99 ) ;
break;
case V_100 :
V_12 -> V_83 |= ( V_97 | V_98 ) ;
V_12 -> V_83 &= ~ V_99 ;
break;
case V_101 :
case V_102 :
V_12 -> V_83 |= ( V_103 | V_104 |
V_105 ) ;
break;
case V_106 :
V_12 -> V_83 |= ( V_103 | V_104 ) ;
V_12 -> V_83 &= ~ V_105 ;
break;
case V_107 :
V_12 -> V_30 |= V_108 ;
break;
case V_109 :
V_12 -> V_30 &= ~ V_108 ;
break;
#ifdef F_12
case V_110 :
V_12 -> V_30 |= V_111 ;
break;
#endif
case V_112 :
F_10 ( V_12 , L_3 , V_17 ) ;
V_12 -> V_30 |= V_36 ;
break;
case V_113 :
F_10 ( V_12 , L_3 , V_17 ) ;
V_12 -> V_30 &= ~ V_36 ;
break;
default:
F_10 ( V_12 , L_4 , V_17 ) ;
return - V_10 ;
}
}
if ( ( V_12 -> V_30 & V_59 ) &&
! ( V_12 -> V_30 & V_31 ) ) {
F_10 ( V_12 , L_5 ) ;
return - V_10 ;
}
if ( ( V_12 -> V_30 & V_61 ) && ( V_19 || V_20 ) ) {
F_10 ( V_12 ,
L_6 ) ;
return - V_10 ;
}
#ifndef F_13
if ( F_14 ( V_12 ) ) {
F_10 ( V_12 , L_7 ) ;
return - V_10 ;
}
#endif
if ( ( V_19 && ! V_20 ) || ( ! V_19 && V_20 ) ) {
F_10 ( V_12 , L_8 ) ;
return - V_10 ;
}
if ( V_19 && ( V_20 % V_19 != 0 ) ) {
F_10 ( V_12 ,
L_9 ,
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
F_10 ( V_12 , L_10 ,
V_12 -> V_38 , V_116 , V_117 ) ;
return - V_10 ;
}
if ( V_12 -> V_39 != - 1 &&
V_12 -> V_39 != 0 &&
( V_12 -> V_39 < V_118 ||
V_12 -> V_39 > V_119 ||
! F_15 ( V_12 -> V_39 ) ) ) {
F_10 ( V_12 ,
L_11 ,
V_12 -> V_39 ) ;
return - V_10 ;
}
if ( V_22 ) {
if ( V_22 > V_120 ||
V_22 < V_121 ) {
F_10 ( V_12 , L_12 ,
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
{ V_72 , L_13 } ,
{ V_35 , L_14 } ,
{ V_61 , L_15 } ,
{ V_63 , L_16 } ,
{ V_70 , L_17 } ,
{ V_59 , L_18 } ,
{ V_77 , L_19 } ,
{ V_81 , L_20 } ,
{ V_54 , L_21 } ,
{ V_108 , L_22 } ,
{ V_67 , L_23 } ,
{ V_111 , L_24 } ,
{ 0 , NULL }
} ;
static struct V_127 V_129 [] = {
{ V_37 , L_25 } ,
{ V_36 , L_26 } ,
{ V_67 , L_27 } ,
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
F_18 ( V_126 , L_28 ,
( int ) ( 1 << V_12 -> V_124 ) >> 10 ) ;
if ( V_12 -> V_38 > 0 )
F_18 ( V_126 , L_29 , V_12 -> V_38 ) ;
if ( V_12 -> V_39 > 0 )
F_18 ( V_126 , L_30 , V_12 -> V_39 >> 10 ) ;
if ( V_12 -> V_46 )
F_19 ( V_126 , L_31 , V_12 -> V_46 ) ;
if ( V_12 -> V_49 )
F_19 ( V_126 , L_32 , V_12 -> V_49 ) ;
if ( V_12 -> V_114 > 0 )
F_18 ( V_126 , L_33 ,
( int ) F_20 ( V_12 , V_12 -> V_114 ) ) ;
if ( V_12 -> V_115 > 0 )
F_18 ( V_126 , L_34 ,
( int ) F_20 ( V_12 , V_12 -> V_115 ) ) ;
if ( V_12 -> V_83 & ( V_90 | V_92 ) )
F_17 ( V_126 , L_35 ) ;
else if ( V_12 -> V_83 & V_90 )
F_17 ( V_126 , L_36 ) ;
if ( V_12 -> V_83 & V_97 ) {
if ( V_12 -> V_83 & V_99 )
F_17 ( V_126 , L_37 ) ;
else
F_17 ( V_126 , L_38 ) ;
}
if ( V_12 -> V_83 & V_103 ) {
if ( V_12 -> V_83 & V_105 )
F_17 ( V_126 , L_39 ) ;
else
F_17 ( V_126 , L_40 ) ;
}
if ( ! ( V_12 -> V_83 & V_84 ) )
F_17 ( V_126 , L_41 ) ;
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
F_10 ( V_12 , L_42 , V_160 , error ) ;
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
L_43 ) ;
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
V_12 -> V_186 = F_45 ( L_44 ,
V_187 | V_188 , 1 , V_12 -> V_23 ) ;
if ( ! V_12 -> V_186 )
goto V_177;
V_12 -> V_189 = F_45 ( L_45 ,
V_187 | V_188 , 0 , V_12 -> V_23 ) ;
if ( ! V_12 -> V_189 )
goto V_190;
V_12 -> V_191 = F_45 ( L_46 ,
V_187 | V_188 , 0 , V_12 -> V_23 ) ;
if ( ! V_12 -> V_191 )
goto V_192;
V_12 -> V_193 = F_45 ( L_47 ,
V_187 | V_188 , 0 , V_12 -> V_23 ) ;
if ( ! V_12 -> V_193 )
goto V_194;
V_12 -> V_195 = F_45 ( L_48 ,
V_187 | V_188 , 0 , V_12 -> V_23 ) ;
if ( ! V_12 -> V_195 )
goto V_196;
V_12 -> V_197 = F_45 ( L_49 ,
V_187 | V_188 | V_198 , 0 ,
V_12 -> V_23 ) ;
if ( ! V_12 -> V_197 )
goto V_199;
V_12 -> V_200 = F_45 ( L_50 ,
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
int error ;
F_56 ( V_205 ) ;
ASSERT ( ! F_57 ( & V_203 -> V_206 ) ) ;
F_58 ( V_205 -> V_207 , V_208 ) ;
F_58 ( V_205 -> V_207 , V_209 ) ;
if ( F_59 ( V_205 ) ) {
error = F_60 ( V_205 , 0 , V_210 , true ) ;
if ( error && ! F_61 ( V_205 -> V_207 ) )
F_10 ( V_205 -> V_207 ,
L_51 ,
error , V_205 -> V_211 ) ;
}
F_62 ( V_205 ) ;
ASSERT ( F_61 ( V_205 -> V_207 ) || V_205 -> V_212 == 0 ) ;
F_58 ( V_205 -> V_207 , V_213 ) ;
F_63 ( ! F_64 ( V_205 , V_214 ) ) ;
F_63 ( ! F_64 ( V_205 , V_215 ) ) ;
F_65 ( V_205 ) ;
}
STATIC void
F_66 (
void * V_203 )
{
struct V_204 * V_205 = V_203 ;
memset ( V_205 , 0 , sizeof( struct V_204 ) ) ;
F_67 ( F_68 ( V_205 ) ) ;
F_69 ( & V_205 -> V_216 , 0 ) ;
F_70 ( & V_205 -> V_217 ) ;
F_71 ( & V_205 -> V_218 , V_219 | V_220 ,
L_52 , V_205 -> V_211 ) ;
F_71 ( & V_205 -> V_221 , V_219 | V_220 ,
L_52 , V_205 -> V_211 ) ;
}
STATIC int
F_72 (
struct V_203 * V_203 )
{
struct V_204 * V_205 = F_55 ( V_203 ) ;
if ( V_205 -> V_222 & V_223 ) {
ASSERT ( V_205 -> V_207 -> V_224 -> V_225 & V_226 ) ;
return 0 ;
}
return F_73 ( V_203 ) || ( V_205 -> V_222 & V_227 ) ;
}
STATIC void
F_74 (
struct V_11 * V_12 )
{
F_4 ( V_12 -> V_23 ) ;
F_4 ( V_12 -> V_49 ) ;
F_4 ( V_12 -> V_46 ) ;
}
STATIC int
F_75 (
struct V_14 * V_15 ,
int V_228 )
{
struct V_11 * V_12 = F_76 ( V_15 ) ;
if ( ! V_228 )
return 0 ;
F_77 ( V_12 , V_229 ) ;
if ( V_230 ) {
F_78 ( & V_12 -> V_224 -> V_231 ) ;
}
return 0 ;
}
STATIC int
F_79 (
struct V_232 * V_232 ,
struct V_233 * V_234 )
{
struct V_11 * V_12 = F_76 ( V_232 -> V_235 ) ;
T_5 * V_144 = & V_12 -> V_145 ;
struct V_204 * V_205 = F_55 ( F_80 ( V_232 ) ) ;
T_3 V_236 , V_237 ;
T_3 V_150 ;
T_3 V_238 ;
T_3 V_239 ;
T_10 V_240 ;
T_11 V_241 ;
V_234 -> V_242 = V_243 ;
V_234 -> V_244 = V_25 - 1 ;
V_237 = F_81 ( V_12 -> V_171 -> V_245 ) ;
V_234 -> V_246 . V_247 [ 0 ] = ( V_248 ) V_237 ;
V_234 -> V_246 . V_247 [ 1 ] = ( V_248 ) ( V_237 >> 32 ) ;
V_150 = F_82 ( & V_12 -> V_249 ) ;
V_238 = F_82 ( & V_12 -> V_250 ) ;
V_239 = F_82 ( & V_12 -> V_251 ) ;
F_83 ( & V_12 -> V_252 ) ;
V_234 -> V_253 = V_144 -> V_254 ;
V_240 = V_144 -> V_255 ? V_144 -> V_256 : 0 ;
V_234 -> V_257 = V_144 -> V_151 - V_240 ;
F_84 ( & V_12 -> V_252 ) ;
V_234 -> V_258 = V_239 - V_12 -> V_259 ;
V_234 -> V_260 = V_234 -> V_258 ;
V_236 = V_234 -> V_258 << V_144 -> V_261 ;
V_234 -> V_262 = F_85 ( V_150 + V_236 , ( T_3 ) V_263 ) ;
if ( V_12 -> V_149 )
V_234 -> V_262 = F_86 ( F_87 ( V_234 -> V_262 ) ,
V_234 -> V_262 ,
V_12 -> V_149 ) ;
V_234 -> V_262 = F_88 ( F_87 ( V_234 -> V_262 ) ,
V_234 -> V_262 ,
V_144 -> V_264 ) ;
V_241 = V_234 -> V_262 - ( V_150 - V_238 ) ;
V_234 -> V_265 = F_88 ( T_11 , V_241 , 0 ) ;
if ( ( V_205 -> V_266 . V_267 & V_268 ) &&
( ( V_12 -> V_83 & ( V_97 | V_99 ) ) ) ==
( V_97 | V_99 ) )
F_89 ( V_205 , V_234 ) ;
return 0 ;
}
STATIC void
F_90 ( struct V_11 * V_12 )
{
T_3 V_269 = 0 ;
V_12 -> V_270 = V_12 -> V_271 ;
F_91 ( V_12 , & V_269 , NULL ) ;
}
STATIC void
F_92 ( struct V_11 * V_12 )
{
T_3 V_269 ;
if ( V_12 -> V_270 ) {
V_269 = V_12 -> V_270 ;
V_12 -> V_270 = 0 ;
} else
V_269 = F_93 ( V_12 ) ;
F_91 ( V_12 , & V_269 , NULL ) ;
}
void
F_94 (
struct V_11 * V_12 )
{
int error = 0 ;
while ( F_95 ( & V_12 -> V_272 ) > 0 )
F_96 ( 100 ) ;
F_77 ( V_12 , V_229 ) ;
F_97 ( V_12 , 0 ) ;
F_97 ( V_12 , V_273 ) ;
error = F_98 ( V_12 ) ;
if ( error )
F_10 ( V_12 , L_53
L_54 ) ;
F_99 ( F_95 ( & V_12 -> V_272 ) != 0 ) ;
F_100 ( V_12 ) ;
}
STATIC int
F_101 (
struct V_14 * V_15 ,
struct V_11 * V_12 ,
char * V_13 )
{
int error = 0 ;
struct V_11 * V_274 ;
V_274 = F_102 ( sizeof( * V_274 ) , V_275 ) ;
if ( ! V_274 )
return - V_9 ;
V_274 -> V_16 = V_15 ;
error = F_5 ( V_274 , V_13 ) ;
F_74 ( V_274 ) ;
F_4 ( V_274 ) ;
return error ;
}
STATIC int
F_103 (
struct V_14 * V_15 ,
int * V_276 ,
char * V_13 )
{
struct V_11 * V_12 = F_76 ( V_15 ) ;
T_5 * V_144 = & V_12 -> V_145 ;
T_1 args [ V_18 ] ;
char * V_17 ;
int error ;
error = F_101 ( V_15 , V_12 , V_13 ) ;
if ( error )
return error ;
F_104 ( V_15 ) ;
while ( ( V_17 = F_7 ( & V_13 , L_1 ) ) != NULL ) {
int V_41 ;
if ( ! * V_17 )
continue;
V_41 = F_8 ( V_17 , V_42 , args ) ;
switch ( V_41 ) {
case V_112 :
F_10 ( V_12 , L_3 , V_17 ) ;
V_12 -> V_30 |= V_36 ;
break;
case V_113 :
F_10 ( V_12 , L_3 , V_17 ) ;
V_12 -> V_30 &= ~ V_36 ;
break;
case V_68 :
V_12 -> V_30 &= ~ V_67 ;
V_12 -> V_277 = F_23 ( V_12 , V_144 -> V_278 ) ;
break;
case V_66 :
V_12 -> V_30 |= V_67 ;
V_12 -> V_277 = F_23 ( V_12 , V_144 -> V_278 ) ;
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
if ( ( V_12 -> V_30 & V_31 ) && ! ( * V_276 & V_29 ) ) {
if ( V_12 -> V_30 & V_59 ) {
F_10 ( V_12 ,
L_55 ) ;
return - V_10 ;
}
if ( F_105 ( V_144 ) == V_279 &&
F_106 ( V_144 ,
V_280 ) ) {
F_10 ( V_12 ,
L_56 ,
( V_144 -> V_281 &
V_280 ) ) ;
return - V_10 ;
}
V_12 -> V_30 &= ~ V_31 ;
if ( V_12 -> V_282 ) {
error = F_107 ( V_12 , false ) ;
if ( error ) {
F_10 ( V_12 , L_57 ) ;
return error ;
}
V_12 -> V_282 = false ;
}
F_92 ( V_12 ) ;
F_108 ( V_12 ) ;
F_109 ( V_12 ) ;
error = F_110 ( V_12 ) ;
if ( error ) {
F_111 ( V_12 ,
L_58 , error ) ;
F_112 ( V_12 , V_283 ) ;
return error ;
}
error = F_113 ( V_12 ) ;
if ( error && error != - V_284 )
return error ;
}
if ( ! ( V_12 -> V_30 & V_31 ) && ( * V_276 & V_29 ) ) {
error = F_114 ( V_12 ) ;
if ( error ) {
F_112 ( V_12 , V_283 ) ;
return error ;
}
F_90 ( V_12 ) ;
F_115 ( & V_12 -> V_285 ) ;
F_94 ( V_12 ) ;
V_12 -> V_30 |= V_31 ;
}
return 0 ;
}
STATIC int
F_116 (
struct V_14 * V_15 )
{
struct V_11 * V_12 = F_76 ( V_15 ) ;
F_90 ( V_12 ) ;
F_94 ( V_12 ) ;
return F_107 ( V_12 , true ) ;
}
STATIC int
F_117 (
struct V_14 * V_15 )
{
struct V_11 * V_12 = F_76 ( V_15 ) ;
F_92 ( V_12 ) ;
F_108 ( V_12 ) ;
return 0 ;
}
STATIC int
F_118 (
struct V_125 * V_126 ,
struct V_232 * V_286 )
{
return F_16 ( F_76 ( V_286 -> V_235 ) , V_126 ) ;
}
STATIC int
F_119 (
struct V_11 * V_12 )
{
int V_287 = ( V_12 -> V_30 & V_31 ) ;
if ( F_120 ( & V_12 -> V_145 ) ) {
if ( V_12 -> V_39 <= 0 &&
V_12 -> V_145 . V_288 > V_289 ) {
V_12 -> V_39 = V_12 -> V_145 . V_288 ;
} else if ( V_12 -> V_39 > 0 &&
V_12 -> V_39 < V_12 -> V_145 . V_288 ) {
F_10 ( V_12 ,
L_59 ) ;
return - V_10 ;
}
} else {
if ( V_12 -> V_39 > V_289 ) {
F_10 ( V_12 ,
L_60 ) ;
return - V_10 ;
}
}
if ( F_121 ( & V_12 -> V_145 ) &&
( V_12 -> V_30 & V_79 ) ) {
F_10 ( V_12 , L_61
L_62 ) ;
return - V_10 ;
}
if ( F_122 ( & V_12 -> V_145 ) &&
! ( V_12 -> V_30 & V_79 ) )
V_12 -> V_30 |= V_77 ;
if ( ( V_12 -> V_145 . V_290 & V_291 ) && ! V_287 ) {
F_10 ( V_12 ,
L_63 ) ;
return - V_292 ;
}
if ( ( V_12 -> V_83 & ( V_103 | V_104 ) ) &&
( V_12 -> V_83 & ( V_97 | V_98 ) ) &&
! F_123 ( & V_12 -> V_145 ) ) {
F_10 ( V_12 ,
L_64 ) ;
return - V_10 ;
}
return 0 ;
}
static int
F_124 (
struct V_11 * V_12 )
{
int error ;
error = F_125 ( & V_12 -> V_249 , 0 , V_26 ) ;
if ( error )
return - V_9 ;
error = F_125 ( & V_12 -> V_250 , 0 , V_26 ) ;
if ( error )
goto V_293;
error = F_125 ( & V_12 -> V_251 , 0 , V_26 ) ;
if ( error )
goto V_294;
return 0 ;
V_294:
F_126 ( & V_12 -> V_250 ) ;
V_293:
F_126 ( & V_12 -> V_249 ) ;
return - V_9 ;
}
void
F_127 (
struct V_11 * V_12 )
{
F_128 ( & V_12 -> V_249 , V_12 -> V_145 . V_264 ) ;
F_128 ( & V_12 -> V_250 , V_12 -> V_145 . V_295 ) ;
F_128 ( & V_12 -> V_251 , V_12 -> V_145 . V_296 ) ;
}
static void
F_129 (
struct V_11 * V_12 )
{
F_126 ( & V_12 -> V_249 ) ;
F_126 ( & V_12 -> V_250 ) ;
F_126 ( & V_12 -> V_251 ) ;
}
STATIC int
F_130 (
struct V_14 * V_15 ,
void * V_297 ,
int V_298 )
{
struct V_203 * V_286 ;
struct V_11 * V_12 = NULL ;
int V_276 = 0 , error = - V_9 ;
V_12 = F_131 ( sizeof( struct V_11 ) , V_26 ) ;
if ( ! V_12 )
goto V_177;
F_70 ( & V_12 -> V_252 ) ;
F_132 ( & V_12 -> V_299 ) ;
F_69 ( & V_12 -> V_272 , 0 ) ;
F_133 ( & V_12 -> V_300 , V_301 ) ;
F_133 ( & V_12 -> V_285 , V_302 ) ;
F_133 ( & V_12 -> V_303 , V_304 ) ;
V_12 -> V_305 . V_306 . V_307 = V_308 ;
V_12 -> V_16 = V_15 ;
V_15 -> V_309 = V_12 ;
error = F_5 ( V_12 , ( char * ) V_297 ) ;
if ( error )
goto V_310;
F_134 ( V_15 , V_184 ) ;
V_15 -> V_311 = V_312 ;
V_15 -> V_313 = & V_314 ;
#ifdef F_13
V_15 -> V_315 = & V_316 ;
V_15 -> V_317 = V_318 | V_319 | V_320 ;
#endif
V_15 -> V_321 = & V_322 ;
if ( V_298 )
V_276 |= V_323 ;
error = F_39 ( V_12 ) ;
if ( error )
goto V_310;
error = F_44 ( V_12 ) ;
if ( error )
goto V_324;
error = F_124 ( V_12 ) ;
if ( error )
goto V_325;
V_12 -> V_326 . V_327 = F_135 ( struct V_328 ) ;
if ( ! V_12 -> V_326 . V_327 ) {
error = - V_9 ;
goto V_329;
}
error = F_136 ( V_12 , V_276 ) ;
if ( error )
goto V_330;
error = F_119 ( V_12 ) ;
if ( error )
goto V_331;
error = F_41 ( V_12 ) ;
if ( error )
goto V_331;
error = F_137 ( V_12 ) ;
if ( error )
goto V_331;
V_15 -> V_332 = V_243 ;
V_15 -> V_333 = V_12 -> V_145 . V_254 ;
V_15 -> V_334 = F_11 ( V_15 -> V_333 ) - 1 ;
V_15 -> V_335 = F_21 ( V_15 -> V_334 ) ;
V_15 -> V_336 = V_337 ;
V_15 -> V_338 = 1 ;
F_138 ( V_15 ) ;
if ( F_105 ( & V_12 -> V_145 ) == V_279 )
V_15 -> V_28 |= V_339 ;
if ( V_12 -> V_30 & V_111 ) {
F_10 ( V_12 ,
L_65 ) ;
error = F_139 ( V_15 , V_15 -> V_333 ) ;
if ( error ) {
F_140 ( V_12 ,
L_66 ) ;
V_12 -> V_30 &= ~ V_111 ;
}
if ( F_141 ( & V_12 -> V_145 ) )
F_140 ( V_12 ,
L_67 ) ;
}
if ( F_142 ( & V_12 -> V_145 ) ) {
if ( V_12 -> V_145 . V_340 ) {
F_140 ( V_12 ,
L_68 ) ;
error = - V_10 ;
goto V_341;
}
F_140 ( V_12 ,
L_69 ) ;
}
if ( F_141 ( & V_12 -> V_145 ) )
F_140 ( V_12 ,
L_70 ) ;
error = F_143 ( V_12 ) ;
if ( error )
goto V_341;
V_286 = F_144 ( F_68 ( V_12 -> V_342 ) ) ;
if ( ! V_286 ) {
error = - V_343 ;
goto V_344;
}
V_15 -> V_345 = F_145 ( V_286 ) ;
if ( ! V_15 -> V_345 ) {
error = - V_9 ;
goto V_344;
}
return 0 ;
V_341:
F_146 ( V_12 ) ;
V_331:
F_147 ( V_12 ) ;
V_330:
F_148 ( V_12 -> V_326 . V_327 ) ;
V_329:
F_129 ( V_12 ) ;
V_325:
F_47 ( V_12 ) ;
V_324:
F_37 ( V_12 ) ;
V_310:
F_74 ( V_12 ) ;
F_4 ( V_12 ) ;
V_177:
return error ;
V_344:
F_146 ( V_12 ) ;
F_149 ( V_12 ) ;
goto V_331;
}
STATIC void
F_150 (
struct V_14 * V_15 )
{
struct V_11 * V_12 = F_76 ( V_15 ) ;
F_151 ( V_12 , L_71 ) ;
F_146 ( V_12 ) ;
F_149 ( V_12 ) ;
F_147 ( V_12 ) ;
F_148 ( V_12 -> V_326 . V_327 ) ;
F_129 ( V_12 ) ;
F_47 ( V_12 ) ;
F_37 ( V_12 ) ;
F_74 ( V_12 ) ;
F_4 ( V_12 ) ;
}
STATIC struct V_232 *
F_152 (
struct V_346 * V_347 ,
int V_276 ,
const char * V_348 ,
void * V_297 )
{
return F_153 ( V_347 , V_276 , V_348 , V_297 , F_130 ) ;
}
static long
F_154 (
struct V_14 * V_15 ,
struct V_349 * V_350 )
{
return F_155 ( F_76 ( V_15 ) ) ;
}
static long
F_156 (
struct V_14 * V_15 ,
struct V_349 * V_350 )
{
return F_157 ( F_76 ( V_15 ) , V_350 -> V_351 ) ;
}
STATIC int T_12
F_158 ( void )
{
V_352 = F_159 ( 4 * V_353 ,
F_160 ( struct V_354 , V_355 ) ) ;
if ( ! V_352 )
goto V_177;
V_356 = F_161 ( sizeof( V_357 ) ,
L_72 ) ;
if ( ! V_356 )
goto V_358;
V_359 = F_161 (
sizeof( struct V_360 ) ,
L_73 ) ;
if ( ! V_359 )
goto V_361;
V_362 = F_161 ( sizeof( V_363 ) ,
L_74 ) ;
if ( ! V_362 )
goto V_364;
V_365 = F_161 ( sizeof( V_366 ) ,
L_75 ) ;
if ( ! V_365 )
goto V_367;
V_368 = F_161 ( sizeof( V_369 ) , L_76 ) ;
if ( ! V_368 )
goto V_370;
V_371 = F_161 ( sizeof( V_372 ) , L_77 ) ;
if ( ! V_371 )
goto V_373;
V_374 =
F_161 ( sizeof( struct V_375 ) ,
L_78 ) ;
if ( ! V_374 )
goto V_376;
V_377 = F_161 ( sizeof( struct V_378 ) ,
L_79 ) ;
if ( ! V_377 )
goto V_379;
V_380 = F_161 ( ( sizeof( V_381 ) +
( ( V_382 - 1 ) *
sizeof( V_383 ) ) ) , L_80 ) ;
if ( ! V_380 )
goto V_384;
V_385 = F_161 ( ( sizeof( V_386 ) +
( ( V_387 - 1 ) *
sizeof( V_383 ) ) ) , L_81 ) ;
if ( ! V_385 )
goto V_388;
V_389 =
F_162 ( sizeof( V_390 ) , L_82 ,
V_391 | V_392 | V_393 |
V_394 , F_66 ) ;
if ( ! V_389 )
goto V_395;
V_396 =
F_162 ( sizeof( V_397 ) , L_83 ,
V_393 , NULL ) ;
if ( ! V_396 )
goto V_398;
V_399 = F_161 ( sizeof( struct V_400 ) ,
L_84 ) ;
if ( ! V_399 )
goto V_401;
V_402 = F_161 ( sizeof( struct V_403 ) ,
L_85 ) ;
if ( ! V_402 )
goto V_404;
V_405 = F_161 (
F_163 ( V_406 ) ,
L_86 ) ;
if ( ! V_405 )
goto V_407;
V_408 = F_161 ( sizeof( struct V_409 ) ,
L_87 ) ;
if ( ! V_408 )
goto V_410;
V_411 = F_161 (
F_164 ( V_412 ) ,
L_88 ) ;
if ( ! V_411 )
goto V_413;
V_414 = F_161 ( sizeof( struct V_415 ) ,
L_89 ) ;
if ( ! V_414 )
goto V_416;
V_417 = F_161 (
F_165 ( V_418 ) ,
L_90 ) ;
if ( ! V_417 )
goto V_419;
return 0 ;
V_419:
F_166 ( V_414 ) ;
V_416:
F_166 ( V_411 ) ;
V_413:
F_166 ( V_408 ) ;
V_410:
F_166 ( V_405 ) ;
V_407:
F_166 ( V_402 ) ;
V_404:
F_166 ( V_399 ) ;
V_401:
F_166 ( V_396 ) ;
V_398:
F_166 ( V_389 ) ;
V_395:
F_166 ( V_385 ) ;
V_388:
F_166 ( V_380 ) ;
V_384:
F_166 ( V_377 ) ;
V_379:
F_166 ( V_374 ) ;
V_376:
F_166 ( V_371 ) ;
V_373:
F_166 ( V_368 ) ;
V_370:
F_166 ( V_365 ) ;
V_367:
F_166 ( V_362 ) ;
V_364:
F_166 ( V_359 ) ;
V_361:
F_166 ( V_356 ) ;
V_358:
F_167 ( V_352 ) ;
V_177:
return - V_9 ;
}
STATIC void
F_168 ( void )
{
F_169 () ;
F_166 ( V_417 ) ;
F_166 ( V_414 ) ;
F_166 ( V_411 ) ;
F_166 ( V_408 ) ;
F_166 ( V_405 ) ;
F_166 ( V_402 ) ;
F_166 ( V_399 ) ;
F_166 ( V_396 ) ;
F_166 ( V_389 ) ;
F_166 ( V_385 ) ;
F_166 ( V_380 ) ;
F_166 ( V_377 ) ;
F_166 ( V_374 ) ;
F_166 ( V_371 ) ;
F_166 ( V_368 ) ;
F_166 ( V_365 ) ;
F_166 ( V_362 ) ;
F_166 ( V_359 ) ;
F_166 ( V_356 ) ;
F_167 ( V_352 ) ;
}
STATIC int T_12
F_170 ( void )
{
V_420 = F_45 ( L_91 ,
V_187 | V_188 , 0 ) ;
if ( ! V_420 )
return - V_9 ;
V_421 = F_45 ( L_92 , V_422 , 0 ) ;
if ( ! V_421 )
goto V_423;
return 0 ;
V_423:
F_46 ( V_420 ) ;
return - V_9 ;
}
STATIC void
F_171 ( void )
{
F_46 ( V_421 ) ;
F_46 ( V_420 ) ;
}
STATIC int T_12
F_172 ( void )
{
int error ;
F_173 () ;
F_174 (KERN_INFO XFS_VERSION_STRING L_93
XFS_BUILD_OPTIONS L_94 ) ;
F_175 () ;
F_176 () ;
F_177 () ;
F_178 () ;
F_179 () ;
error = F_158 () ;
if ( error )
goto V_177;
error = F_170 () ;
if ( error )
goto V_424;
error = F_180 () ;
if ( error )
goto V_425;
error = F_181 () ;
if ( error )
goto V_426;
error = F_182 () ;
if ( error )
goto V_427;
error = F_183 () ;
if ( error )
goto V_428;
V_308 = F_184 ( L_95 , NULL , V_429 ) ;
if ( ! V_308 ) {
error = - V_9 ;
goto V_430;
}
V_328 . V_431 . V_306 . V_307 = V_308 ;
V_328 . V_327 = F_135 ( struct V_328 ) ;
if ( ! V_328 . V_327 ) {
error = - V_9 ;
goto V_432;
}
error = F_185 ( & V_328 . V_431 , & V_433 , NULL ,
L_96 ) ;
if ( error )
goto V_330;
#ifdef F_186
V_434 . V_306 . V_307 = V_308 ;
error = F_185 ( & V_434 , & V_435 , NULL , L_97 ) ;
if ( error )
goto V_436;
#endif
error = F_187 () ;
if ( error )
goto V_437;
error = F_188 ( & V_438 ) ;
if ( error )
goto V_439;
return 0 ;
V_439:
F_189 () ;
V_437:
#ifdef F_186
F_190 ( & V_434 ) ;
V_436:
#endif
F_190 ( & V_328 . V_431 ) ;
V_330:
F_148 ( V_328 . V_327 ) ;
V_432:
F_191 ( V_308 ) ;
V_430:
F_192 () ;
V_428:
F_193 () ;
V_427:
F_194 () ;
V_426:
F_195 () ;
V_425:
F_171 () ;
V_424:
F_168 () ;
V_177:
return error ;
}
STATIC void T_13
F_196 ( void )
{
F_189 () ;
F_197 ( & V_438 ) ;
#ifdef F_186
F_190 ( & V_434 ) ;
#endif
F_190 ( & V_328 . V_431 ) ;
F_148 ( V_328 . V_327 ) ;
F_191 ( V_308 ) ;
F_192 () ;
F_193 () ;
F_194 () ;
F_195 () ;
F_171 () ;
F_168 () ;
F_198 () ;
}
