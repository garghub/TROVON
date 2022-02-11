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
V_12 -> V_202 = F_45 ( L_51 , V_188 , 0 ,
V_12 -> V_23 ) ;
if ( ! V_12 -> V_202 )
goto V_203;
return 0 ;
V_203:
F_46 ( V_12 -> V_200 ) ;
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
F_46 ( V_12 -> V_202 ) ;
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
if ( F_49 ( & V_15 -> V_204 ) ) {
F_50 ( V_15 ) ;
F_51 ( & V_15 -> V_204 ) ;
}
}
STATIC struct V_205 *
F_52 (
struct V_14 * V_15 )
{
F_53 () ;
return NULL ;
}
STATIC void
F_54 (
struct V_205 * V_205 )
{
struct V_206 * V_207 = F_55 ( V_205 ) ;
int error ;
F_56 ( V_207 ) ;
ASSERT ( ! F_57 ( & V_205 -> V_208 ) ) ;
F_58 ( V_207 -> V_209 , V_210 ) ;
F_58 ( V_207 -> V_209 , V_211 ) ;
if ( F_59 ( V_207 ) ) {
error = F_60 ( V_207 , 0 , V_212 , true ) ;
if ( error && ! F_61 ( V_207 -> V_209 ) )
F_10 ( V_207 -> V_209 ,
L_52 ,
error , V_207 -> V_213 ) ;
}
F_62 ( V_207 ) ;
ASSERT ( F_61 ( V_207 -> V_209 ) || V_207 -> V_214 == 0 ) ;
F_58 ( V_207 -> V_209 , V_215 ) ;
F_63 ( ! F_64 ( V_207 , V_216 ) ) ;
F_63 ( ! F_64 ( V_207 , V_217 ) ) ;
F_65 ( V_207 ) ;
}
STATIC void
F_66 (
void * V_205 )
{
struct V_206 * V_207 = V_205 ;
memset ( V_207 , 0 , sizeof( struct V_206 ) ) ;
F_67 ( F_68 ( V_207 ) ) ;
F_69 ( & V_207 -> V_218 , 0 ) ;
F_70 ( & V_207 -> V_219 ) ;
F_71 ( & V_207 -> V_220 , V_221 | V_222 ,
L_53 , V_207 -> V_213 ) ;
F_71 ( & V_207 -> V_223 , V_221 | V_222 ,
L_53 , V_207 -> V_213 ) ;
}
STATIC int
F_72 (
struct V_205 * V_205 )
{
struct V_206 * V_207 = F_55 ( V_205 ) ;
if ( V_207 -> V_224 & V_225 ) {
ASSERT ( V_207 -> V_209 -> V_226 -> V_227 & V_228 ) ;
return 0 ;
}
return F_73 ( V_205 ) || ( V_207 -> V_224 & V_229 ) ;
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
int V_230 )
{
struct V_11 * V_12 = F_76 ( V_15 ) ;
if ( ! V_230 )
return 0 ;
F_77 ( V_12 , V_231 ) ;
if ( V_232 ) {
F_78 ( & V_12 -> V_226 -> V_233 ) ;
}
return 0 ;
}
STATIC int
F_79 (
struct V_234 * V_234 ,
struct V_235 * V_236 )
{
struct V_11 * V_12 = F_76 ( V_234 -> V_237 ) ;
T_5 * V_144 = & V_12 -> V_145 ;
struct V_206 * V_207 = F_55 ( F_80 ( V_234 ) ) ;
T_3 V_238 , V_239 ;
T_3 V_150 ;
T_3 V_240 ;
T_3 V_241 ;
T_10 V_242 ;
T_11 V_243 ;
V_236 -> V_244 = V_245 ;
V_236 -> V_246 = V_25 - 1 ;
V_239 = F_81 ( V_12 -> V_171 -> V_247 ) ;
V_236 -> V_248 . V_249 [ 0 ] = ( V_250 ) V_239 ;
V_236 -> V_248 . V_249 [ 1 ] = ( V_250 ) ( V_239 >> 32 ) ;
V_150 = F_82 ( & V_12 -> V_251 ) ;
V_240 = F_82 ( & V_12 -> V_252 ) ;
V_241 = F_82 ( & V_12 -> V_253 ) ;
F_83 ( & V_12 -> V_254 ) ;
V_236 -> V_255 = V_144 -> V_256 ;
V_242 = V_144 -> V_257 ? V_144 -> V_258 : 0 ;
V_236 -> V_259 = V_144 -> V_151 - V_242 ;
F_84 ( & V_12 -> V_254 ) ;
V_236 -> V_260 = V_241 - V_12 -> V_261 ;
V_236 -> V_262 = V_236 -> V_260 ;
V_238 = V_236 -> V_260 << V_144 -> V_263 ;
V_236 -> V_264 = F_85 ( V_150 + V_238 , ( T_3 ) V_265 ) ;
if ( V_12 -> V_149 )
V_236 -> V_264 = F_86 ( F_87 ( V_236 -> V_264 ) ,
V_236 -> V_264 ,
V_12 -> V_149 ) ;
V_236 -> V_264 = F_88 ( F_87 ( V_236 -> V_264 ) ,
V_236 -> V_264 ,
V_144 -> V_266 ) ;
V_243 = V_236 -> V_264 - ( V_150 - V_240 ) ;
V_236 -> V_267 = F_88 ( T_11 , V_243 , 0 ) ;
if ( ( V_207 -> V_268 . V_269 & V_270 ) &&
( ( V_12 -> V_83 & ( V_97 | V_99 ) ) ) ==
( V_97 | V_99 ) )
F_89 ( V_207 , V_236 ) ;
return 0 ;
}
STATIC void
F_90 ( struct V_11 * V_12 )
{
T_3 V_271 = 0 ;
V_12 -> V_272 = V_12 -> V_273 ;
F_91 ( V_12 , & V_271 , NULL ) ;
}
STATIC void
F_92 ( struct V_11 * V_12 )
{
T_3 V_271 ;
if ( V_12 -> V_272 ) {
V_271 = V_12 -> V_272 ;
V_12 -> V_272 = 0 ;
} else
V_271 = F_93 ( V_12 ) ;
F_91 ( V_12 , & V_271 , NULL ) ;
}
void
F_94 (
struct V_11 * V_12 )
{
int error = 0 ;
while ( F_95 ( & V_12 -> V_274 ) > 0 )
F_96 ( 100 ) ;
F_77 ( V_12 , V_231 ) ;
F_97 ( V_12 , 0 ) ;
F_97 ( V_12 , V_275 ) ;
error = F_98 ( V_12 ) ;
if ( error )
F_10 ( V_12 , L_54
L_55 ) ;
F_99 ( F_95 ( & V_12 -> V_274 ) != 0 ) ;
F_100 ( V_12 ) ;
}
STATIC int
F_101 (
struct V_14 * V_15 ,
struct V_11 * V_12 ,
char * V_13 )
{
int error = 0 ;
struct V_11 * V_276 ;
V_276 = F_102 ( sizeof( * V_276 ) , V_277 ) ;
if ( ! V_276 )
return - V_9 ;
V_276 -> V_16 = V_15 ;
error = F_5 ( V_276 , V_13 ) ;
F_74 ( V_276 ) ;
F_4 ( V_276 ) ;
return error ;
}
STATIC int
F_103 (
struct V_14 * V_15 ,
int * V_278 ,
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
V_12 -> V_279 = F_23 ( V_12 , V_144 -> V_280 ) ;
break;
case V_66 :
V_12 -> V_30 |= V_67 ;
V_12 -> V_279 = F_23 ( V_12 , V_144 -> V_280 ) ;
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
if ( ( V_12 -> V_30 & V_31 ) && ! ( * V_278 & V_29 ) ) {
if ( V_12 -> V_30 & V_59 ) {
F_10 ( V_12 ,
L_56 ) ;
return - V_10 ;
}
if ( F_105 ( V_144 ) == V_281 &&
F_106 ( V_144 ,
V_282 ) ) {
F_10 ( V_12 ,
L_57 ,
( V_144 -> V_283 &
V_282 ) ) ;
return - V_10 ;
}
V_12 -> V_30 &= ~ V_31 ;
if ( V_12 -> V_284 ) {
error = F_107 ( V_12 , false ) ;
if ( error ) {
F_10 ( V_12 , L_58 ) ;
return error ;
}
V_12 -> V_284 = false ;
}
F_92 ( V_12 ) ;
F_108 ( V_12 ) ;
F_109 ( V_12 ) ;
error = F_110 ( V_12 ) ;
if ( error ) {
F_111 ( V_12 ,
L_59 , error ) ;
F_112 ( V_12 , V_285 ) ;
return error ;
}
error = F_113 ( V_12 ) ;
if ( error && error != - V_286 )
return error ;
}
if ( ! ( V_12 -> V_30 & V_31 ) && ( * V_278 & V_29 ) ) {
error = F_114 ( V_12 ) ;
if ( error ) {
F_112 ( V_12 , V_285 ) ;
return error ;
}
F_90 ( V_12 ) ;
F_115 ( & V_12 -> V_287 ) ;
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
struct V_234 * V_288 )
{
return F_16 ( F_76 ( V_288 -> V_237 ) , V_126 ) ;
}
STATIC int
F_119 (
struct V_11 * V_12 )
{
int V_289 = ( V_12 -> V_30 & V_31 ) ;
if ( F_120 ( & V_12 -> V_145 ) ) {
if ( V_12 -> V_39 <= 0 &&
V_12 -> V_145 . V_290 > V_291 ) {
V_12 -> V_39 = V_12 -> V_145 . V_290 ;
} else if ( V_12 -> V_39 > 0 &&
V_12 -> V_39 < V_12 -> V_145 . V_290 ) {
F_10 ( V_12 ,
L_60 ) ;
return - V_10 ;
}
} else {
if ( V_12 -> V_39 > V_291 ) {
F_10 ( V_12 ,
L_61 ) ;
return - V_10 ;
}
}
if ( F_121 ( & V_12 -> V_145 ) &&
( V_12 -> V_30 & V_79 ) ) {
F_10 ( V_12 , L_62
L_63 ) ;
return - V_10 ;
}
if ( F_122 ( & V_12 -> V_145 ) &&
! ( V_12 -> V_30 & V_79 ) )
V_12 -> V_30 |= V_77 ;
if ( ( V_12 -> V_145 . V_292 & V_293 ) && ! V_289 ) {
F_10 ( V_12 ,
L_64 ) ;
return - V_294 ;
}
if ( ( V_12 -> V_83 & ( V_103 | V_104 ) ) &&
( V_12 -> V_83 & ( V_97 | V_98 ) ) &&
! F_123 ( & V_12 -> V_145 ) ) {
F_10 ( V_12 ,
L_65 ) ;
return - V_10 ;
}
return 0 ;
}
static int
F_124 (
struct V_11 * V_12 )
{
int error ;
error = F_125 ( & V_12 -> V_251 , 0 , V_26 ) ;
if ( error )
return - V_9 ;
error = F_125 ( & V_12 -> V_252 , 0 , V_26 ) ;
if ( error )
goto V_295;
error = F_125 ( & V_12 -> V_253 , 0 , V_26 ) ;
if ( error )
goto V_296;
return 0 ;
V_296:
F_126 ( & V_12 -> V_252 ) ;
V_295:
F_126 ( & V_12 -> V_251 ) ;
return - V_9 ;
}
void
F_127 (
struct V_11 * V_12 )
{
F_128 ( & V_12 -> V_251 , V_12 -> V_145 . V_266 ) ;
F_128 ( & V_12 -> V_252 , V_12 -> V_145 . V_297 ) ;
F_128 ( & V_12 -> V_253 , V_12 -> V_145 . V_298 ) ;
}
static void
F_129 (
struct V_11 * V_12 )
{
F_126 ( & V_12 -> V_251 ) ;
F_126 ( & V_12 -> V_252 ) ;
F_126 ( & V_12 -> V_253 ) ;
}
STATIC int
F_130 (
struct V_14 * V_15 ,
void * V_299 ,
int V_300 )
{
struct V_205 * V_288 ;
struct V_11 * V_12 = NULL ;
int V_278 = 0 , error = - V_9 ;
V_12 = F_131 ( sizeof( struct V_11 ) , V_26 ) ;
if ( ! V_12 )
goto V_177;
F_70 ( & V_12 -> V_254 ) ;
F_132 ( & V_12 -> V_301 ) ;
F_69 ( & V_12 -> V_274 , 0 ) ;
F_133 ( & V_12 -> V_302 , V_303 ) ;
F_133 ( & V_12 -> V_287 , V_304 ) ;
F_133 ( & V_12 -> V_305 , V_306 ) ;
V_12 -> V_307 . V_308 . V_309 = V_310 ;
V_12 -> V_16 = V_15 ;
V_15 -> V_311 = V_12 ;
error = F_5 ( V_12 , ( char * ) V_299 ) ;
if ( error )
goto V_312;
F_134 ( V_15 , V_184 ) ;
V_15 -> V_313 = V_314 ;
V_15 -> V_315 = & V_316 ;
#ifdef F_13
V_15 -> V_317 = & V_318 ;
V_15 -> V_319 = V_320 | V_321 | V_322 ;
#endif
V_15 -> V_323 = & V_324 ;
if ( V_300 )
V_278 |= V_325 ;
error = F_39 ( V_12 ) ;
if ( error )
goto V_312;
error = F_44 ( V_12 ) ;
if ( error )
goto V_326;
error = F_124 ( V_12 ) ;
if ( error )
goto V_327;
V_12 -> V_328 . V_329 = F_135 ( struct V_330 ) ;
if ( ! V_12 -> V_328 . V_329 ) {
error = - V_9 ;
goto V_331;
}
error = F_136 ( V_12 , V_278 ) ;
if ( error )
goto V_332;
error = F_119 ( V_12 ) ;
if ( error )
goto V_333;
error = F_41 ( V_12 ) ;
if ( error )
goto V_333;
error = F_137 ( V_12 ) ;
if ( error )
goto V_333;
V_15 -> V_334 = V_245 ;
V_15 -> V_335 = V_12 -> V_145 . V_256 ;
V_15 -> V_336 = F_11 ( V_15 -> V_335 ) - 1 ;
V_15 -> V_337 = F_21 ( V_15 -> V_336 ) ;
V_15 -> V_338 = V_339 ;
V_15 -> V_340 = 1 ;
F_138 ( V_15 ) ;
if ( F_105 ( & V_12 -> V_145 ) == V_281 )
V_15 -> V_28 |= V_341 ;
if ( V_12 -> V_30 & V_111 ) {
F_10 ( V_12 ,
L_66 ) ;
error = F_139 ( V_15 , V_15 -> V_335 ) ;
if ( error ) {
F_140 ( V_12 ,
L_67 ) ;
V_12 -> V_30 &= ~ V_111 ;
}
if ( F_141 ( & V_12 -> V_145 ) )
F_140 ( V_12 ,
L_68 ) ;
}
if ( F_142 ( & V_12 -> V_145 ) ) {
if ( V_12 -> V_145 . V_342 ) {
F_140 ( V_12 ,
L_69 ) ;
error = - V_10 ;
goto V_343;
}
F_140 ( V_12 ,
L_70 ) ;
}
if ( F_141 ( & V_12 -> V_145 ) )
F_140 ( V_12 ,
L_71 ) ;
error = F_143 ( V_12 ) ;
if ( error )
goto V_343;
V_288 = F_144 ( F_68 ( V_12 -> V_344 ) ) ;
if ( ! V_288 ) {
error = - V_345 ;
goto V_346;
}
V_15 -> V_347 = F_145 ( V_288 ) ;
if ( ! V_15 -> V_347 ) {
error = - V_9 ;
goto V_346;
}
return 0 ;
V_343:
F_146 ( V_12 ) ;
V_333:
F_147 ( V_12 ) ;
V_332:
F_148 ( V_12 -> V_328 . V_329 ) ;
V_331:
F_129 ( V_12 ) ;
V_327:
F_47 ( V_12 ) ;
V_326:
F_37 ( V_12 ) ;
V_312:
F_74 ( V_12 ) ;
F_4 ( V_12 ) ;
V_177:
return error ;
V_346:
F_146 ( V_12 ) ;
F_149 ( V_12 ) ;
goto V_333;
}
STATIC void
F_150 (
struct V_14 * V_15 )
{
struct V_11 * V_12 = F_76 ( V_15 ) ;
F_151 ( V_12 , L_72 ) ;
F_146 ( V_12 ) ;
F_149 ( V_12 ) ;
F_147 ( V_12 ) ;
F_148 ( V_12 -> V_328 . V_329 ) ;
F_129 ( V_12 ) ;
F_47 ( V_12 ) ;
F_37 ( V_12 ) ;
F_74 ( V_12 ) ;
F_4 ( V_12 ) ;
}
STATIC struct V_234 *
F_152 (
struct V_348 * V_349 ,
int V_278 ,
const char * V_350 ,
void * V_299 )
{
return F_153 ( V_349 , V_278 , V_350 , V_299 , F_130 ) ;
}
static long
F_154 (
struct V_14 * V_15 ,
struct V_351 * V_352 )
{
return F_155 ( F_76 ( V_15 ) ) ;
}
static long
F_156 (
struct V_14 * V_15 ,
struct V_351 * V_352 )
{
return F_157 ( F_76 ( V_15 ) , V_352 -> V_353 ) ;
}
STATIC int T_12
F_158 ( void )
{
V_354 = F_159 ( 4 * V_355 ,
F_160 ( struct V_356 , V_357 ) ,
V_358 ) ;
if ( ! V_354 )
goto V_177;
V_359 = F_161 ( sizeof( V_360 ) ,
L_73 ) ;
if ( ! V_359 )
goto V_361;
V_362 = F_161 (
sizeof( struct V_363 ) ,
L_74 ) ;
if ( ! V_362 )
goto V_364;
V_365 = F_161 ( sizeof( V_366 ) ,
L_75 ) ;
if ( ! V_365 )
goto V_367;
V_368 = F_161 ( sizeof( V_369 ) ,
L_76 ) ;
if ( ! V_368 )
goto V_370;
V_371 = F_161 ( sizeof( V_372 ) , L_77 ) ;
if ( ! V_371 )
goto V_373;
V_374 = F_161 ( sizeof( V_375 ) , L_78 ) ;
if ( ! V_374 )
goto V_376;
V_377 =
F_161 ( sizeof( struct V_378 ) ,
L_79 ) ;
if ( ! V_377 )
goto V_379;
V_380 = F_161 ( sizeof( struct V_381 ) ,
L_80 ) ;
if ( ! V_380 )
goto V_382;
V_383 = F_161 ( ( sizeof( V_384 ) +
( ( V_385 - 1 ) *
sizeof( V_386 ) ) ) , L_81 ) ;
if ( ! V_383 )
goto V_387;
V_388 = F_161 ( ( sizeof( V_389 ) +
( ( V_390 - 1 ) *
sizeof( V_386 ) ) ) , L_82 ) ;
if ( ! V_388 )
goto V_391;
V_392 =
F_162 ( sizeof( V_393 ) , L_83 ,
V_394 | V_395 | V_396 |
V_397 , F_66 ) ;
if ( ! V_392 )
goto V_398;
V_399 =
F_162 ( sizeof( V_400 ) , L_84 ,
V_396 , NULL ) ;
if ( ! V_399 )
goto V_401;
V_402 = F_161 ( sizeof( struct V_403 ) ,
L_85 ) ;
if ( ! V_402 )
goto V_404;
V_405 = F_161 ( sizeof( struct V_406 ) ,
L_86 ) ;
if ( ! V_405 )
goto V_407;
V_408 = F_161 (
F_163 ( V_409 ) ,
L_87 ) ;
if ( ! V_408 )
goto V_410;
V_411 = F_161 ( sizeof( struct V_412 ) ,
L_88 ) ;
if ( ! V_411 )
goto V_413;
V_414 = F_161 (
F_164 ( V_415 ) ,
L_89 ) ;
if ( ! V_414 )
goto V_416;
V_417 = F_161 ( sizeof( struct V_418 ) ,
L_90 ) ;
if ( ! V_417 )
goto V_419;
V_420 = F_161 (
F_165 ( V_421 ) ,
L_91 ) ;
if ( ! V_420 )
goto V_422;
return 0 ;
V_422:
F_166 ( V_417 ) ;
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
F_166 ( V_392 ) ;
V_398:
F_166 ( V_388 ) ;
V_391:
F_166 ( V_383 ) ;
V_387:
F_166 ( V_380 ) ;
V_382:
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
F_167 ( V_354 ) ;
V_177:
return - V_9 ;
}
STATIC void
F_168 ( void )
{
F_169 () ;
F_166 ( V_420 ) ;
F_166 ( V_417 ) ;
F_166 ( V_414 ) ;
F_166 ( V_411 ) ;
F_166 ( V_408 ) ;
F_166 ( V_405 ) ;
F_166 ( V_402 ) ;
F_166 ( V_399 ) ;
F_166 ( V_392 ) ;
F_166 ( V_388 ) ;
F_166 ( V_383 ) ;
F_166 ( V_380 ) ;
F_166 ( V_377 ) ;
F_166 ( V_374 ) ;
F_166 ( V_371 ) ;
F_166 ( V_368 ) ;
F_166 ( V_365 ) ;
F_166 ( V_362 ) ;
F_166 ( V_359 ) ;
F_167 ( V_354 ) ;
}
STATIC int T_12
F_170 ( void )
{
V_423 = F_45 ( L_92 ,
V_187 | V_188 , 0 ) ;
if ( ! V_423 )
return - V_9 ;
V_424 = F_45 ( L_93 , V_425 , 0 ) ;
if ( ! V_424 )
goto V_426;
return 0 ;
V_426:
F_46 ( V_423 ) ;
return - V_9 ;
}
STATIC void
F_171 ( void )
{
F_46 ( V_424 ) ;
F_46 ( V_423 ) ;
}
STATIC int T_12
F_172 ( void )
{
int error ;
F_173 () ;
F_174 (KERN_INFO XFS_VERSION_STRING L_94
XFS_BUILD_OPTIONS L_95 ) ;
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
goto V_427;
error = F_180 () ;
if ( error )
goto V_428;
error = F_181 () ;
if ( error )
goto V_429;
error = F_182 () ;
if ( error )
goto V_430;
error = F_183 () ;
if ( error )
goto V_431;
V_310 = F_184 ( L_96 , NULL , V_432 ) ;
if ( ! V_310 ) {
error = - V_9 ;
goto V_433;
}
V_330 . V_434 . V_308 . V_309 = V_310 ;
V_330 . V_329 = F_135 ( struct V_330 ) ;
if ( ! V_330 . V_329 ) {
error = - V_9 ;
goto V_435;
}
error = F_185 ( & V_330 . V_434 , & V_436 , NULL ,
L_97 ) ;
if ( error )
goto V_332;
#ifdef F_186
V_437 . V_308 . V_309 = V_310 ;
error = F_185 ( & V_437 , & V_438 , NULL , L_98 ) ;
if ( error )
goto V_439;
#endif
error = F_187 () ;
if ( error )
goto V_440;
error = F_188 ( & V_441 ) ;
if ( error )
goto V_442;
return 0 ;
V_442:
F_189 () ;
V_440:
#ifdef F_186
F_190 ( & V_437 ) ;
V_439:
#endif
F_190 ( & V_330 . V_434 ) ;
V_332:
F_148 ( V_330 . V_329 ) ;
V_435:
F_191 ( V_310 ) ;
V_433:
F_192 () ;
V_431:
F_193 () ;
V_430:
F_194 () ;
V_429:
F_195 () ;
V_428:
F_171 () ;
V_427:
F_168 () ;
V_177:
return error ;
}
STATIC void T_13
F_196 ( void )
{
F_189 () ;
F_197 ( & V_441 ) ;
#ifdef F_186
F_190 ( & V_437 ) ;
#endif
F_190 ( & V_330 . V_434 ) ;
F_148 ( V_330 . V_329 ) ;
F_191 ( V_310 ) ;
F_192 () ;
F_193 () ;
F_194 () ;
F_195 () ;
F_171 () ;
F_168 () ;
F_198 () ;
}
