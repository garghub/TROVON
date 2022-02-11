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
if ( F_7 ( V_15 ) )
V_12 -> V_28 |= V_29 ;
if ( V_15 -> V_30 & V_31 )
V_12 -> V_28 |= V_32 ;
if ( V_15 -> V_30 & V_33 )
V_12 -> V_28 |= V_34 ;
V_12 -> V_28 |= V_35 ;
V_12 -> V_28 |= V_36 ;
V_12 -> V_37 = - 1 ;
V_12 -> V_38 = - 1 ;
if ( ! V_13 )
goto V_39;
while ( ( V_17 = F_8 ( & V_13 , L_1 ) ) != NULL ) {
int V_40 ;
if ( ! * V_17 )
continue;
V_40 = F_9 ( V_17 , V_41 , args ) ;
switch ( V_40 ) {
case V_42 :
if ( F_10 ( args , & V_12 -> V_37 ) )
return - V_10 ;
break;
case V_43 :
if ( F_1 ( args , 10 , & V_12 -> V_38 ) )
return - V_10 ;
break;
case V_44 :
V_12 -> V_45 = F_2 ( args ) ;
if ( ! V_12 -> V_45 )
return - V_9 ;
break;
case V_46 :
F_11 ( V_12 , L_2 , V_17 ) ;
return - V_10 ;
case V_47 :
V_12 -> V_48 = F_2 ( args ) ;
if ( ! V_12 -> V_48 )
return - V_9 ;
break;
case V_49 :
case V_50 :
if ( F_1 ( args , 10 , & V_21 ) )
return - V_10 ;
V_22 = F_12 ( V_21 ) - 1 ;
break;
case V_51 :
case V_52 :
V_12 -> V_28 |= V_53 ;
break;
case V_54 :
case V_55 :
V_12 -> V_28 &= ~ V_53 ;
break;
case V_56 :
V_12 -> V_28 |= V_34 ;
break;
case V_57 :
V_12 -> V_28 |= V_58 ;
break;
case V_59 :
V_12 -> V_28 |= V_60 ;
break;
case V_61 :
V_12 -> V_28 |= V_62 ;
break;
case V_63 :
if ( F_10 ( args , & V_19 ) )
return - V_10 ;
break;
case V_64 :
if ( F_10 ( args , & V_20 ) )
return - V_10 ;
break;
case V_65 :
V_12 -> V_28 |= V_66 ;
break;
case V_67 :
V_12 -> V_28 &= ~ V_66 ;
break;
case V_68 :
V_12 -> V_28 |= V_69 ;
break;
case V_70 :
V_12 -> V_28 |= V_71 ;
break;
case V_72 :
V_12 -> V_28 &= ~ V_71 ;
break;
case V_73 :
V_12 -> V_28 &= ~ V_36 ;
break;
case V_74 :
V_12 -> V_28 |= V_36 ;
break;
case V_75 :
V_12 -> V_28 |= V_76 ;
break;
case V_77 :
V_12 -> V_28 &= ~ V_76 ;
V_12 -> V_28 |= V_78 ;
break;
case V_79 :
V_12 -> V_28 |= V_80 ;
break;
case V_81 :
V_12 -> V_82 &= ~ V_83 ;
V_12 -> V_82 &= ~ V_84 ;
V_12 -> V_82 &= ~ V_85 ;
break;
case V_86 :
case V_87 :
case V_88 :
V_12 -> V_82 |= ( V_89 | V_90 |
V_91 ) ;
break;
case V_92 :
case V_93 :
V_12 -> V_82 |= ( V_89 | V_90 ) ;
V_12 -> V_82 &= ~ V_91 ;
break;
case V_94 :
case V_95 :
V_12 -> V_82 |= ( V_96 | V_97 |
V_98 ) ;
break;
case V_99 :
V_12 -> V_82 |= ( V_96 | V_97 ) ;
V_12 -> V_82 &= ~ V_98 ;
break;
case V_100 :
case V_101 :
V_12 -> V_82 |= ( V_102 | V_103 |
V_104 ) ;
break;
case V_105 :
V_12 -> V_82 |= ( V_102 | V_103 ) ;
V_12 -> V_82 &= ~ V_104 ;
break;
case V_106 :
V_12 -> V_28 |= V_107 ;
break;
case V_108 :
V_12 -> V_28 &= ~ V_107 ;
break;
#ifdef F_13
case V_109 :
V_12 -> V_28 |= V_110 ;
break;
#endif
case V_111 :
F_11 ( V_12 , L_3 , V_17 ) ;
V_12 -> V_28 |= V_35 ;
break;
case V_112 :
F_11 ( V_12 , L_3 , V_17 ) ;
V_12 -> V_28 &= ~ V_35 ;
break;
default:
F_11 ( V_12 , L_4 , V_17 ) ;
return - V_10 ;
}
}
if ( ( V_12 -> V_28 & V_58 ) &&
! ( V_12 -> V_28 & V_29 ) ) {
F_11 ( V_12 , L_5 ) ;
return - V_10 ;
}
if ( ( V_12 -> V_28 & V_60 ) && ( V_19 || V_20 ) ) {
F_11 ( V_12 ,
L_6 ) ;
return - V_10 ;
}
#ifndef F_14
if ( F_15 ( V_12 ) ) {
F_11 ( V_12 , L_7 ) ;
return - V_10 ;
}
#endif
if ( ( V_19 && ! V_20 ) || ( ! V_19 && V_20 ) ) {
F_11 ( V_12 , L_8 ) ;
return - V_10 ;
}
if ( V_19 && ( V_20 % V_19 != 0 ) ) {
F_11 ( V_12 ,
L_9 ,
V_20 , V_19 ) ;
return - V_10 ;
}
V_39:
if ( V_19 && ! ( V_12 -> V_28 & V_60 ) ) {
V_12 -> V_113 = V_19 ;
V_12 -> V_114 = V_20 ;
}
if ( V_12 -> V_37 != - 1 &&
V_12 -> V_37 != 0 &&
( V_12 -> V_37 < V_115 ||
V_12 -> V_37 > V_116 ) ) {
F_11 ( V_12 , L_10 ,
V_12 -> V_37 , V_115 , V_116 ) ;
return - V_10 ;
}
if ( V_12 -> V_38 != - 1 &&
V_12 -> V_38 != 0 &&
( V_12 -> V_38 < V_117 ||
V_12 -> V_38 > V_118 ||
! F_16 ( V_12 -> V_38 ) ) ) {
F_11 ( V_12 ,
L_11 ,
V_12 -> V_38 ) ;
return - V_10 ;
}
if ( V_22 ) {
if ( V_22 > V_119 ||
V_22 < V_120 ) {
F_11 ( V_12 , L_12 ,
V_22 , V_120 ,
V_119 ) ;
return - V_10 ;
}
V_12 -> V_28 |= V_121 ;
V_12 -> V_122 = V_22 ;
V_12 -> V_123 = V_22 ;
}
return 0 ;
}
STATIC int
F_17 (
struct V_11 * V_12 ,
struct V_124 * V_125 )
{
static struct V_126 V_127 [] = {
{ V_71 , L_13 } ,
{ V_34 , L_14 } ,
{ V_60 , L_15 } ,
{ V_62 , L_16 } ,
{ V_69 , L_17 } ,
{ V_58 , L_18 } ,
{ V_76 , L_19 } ,
{ V_80 , L_20 } ,
{ V_53 , L_21 } ,
{ V_107 , L_22 } ,
{ V_66 , L_23 } ,
{ V_110 , L_24 } ,
{ 0 , NULL }
} ;
static struct V_126 V_128 [] = {
{ V_36 , L_25 } ,
{ V_35 , L_26 } ,
{ V_66 , L_27 } ,
{ 0 , NULL }
} ;
struct V_126 * V_129 ;
for ( V_129 = V_127 ; V_129 -> V_130 ; V_129 ++ ) {
if ( V_12 -> V_28 & V_129 -> V_130 )
F_18 ( V_125 , V_129 -> V_131 ) ;
}
for ( V_129 = V_128 ; V_129 -> V_130 ; V_129 ++ ) {
if ( ! ( V_12 -> V_28 & V_129 -> V_130 ) )
F_18 ( V_125 , V_129 -> V_131 ) ;
}
if ( V_12 -> V_28 & V_121 )
F_19 ( V_125 , L_28 ,
( int ) ( 1 << V_12 -> V_123 ) >> 10 ) ;
if ( V_12 -> V_37 > 0 )
F_19 ( V_125 , L_29 , V_12 -> V_37 ) ;
if ( V_12 -> V_38 > 0 )
F_19 ( V_125 , L_30 , V_12 -> V_38 >> 10 ) ;
if ( V_12 -> V_45 )
F_20 ( V_125 , L_31 , V_12 -> V_45 ) ;
if ( V_12 -> V_48 )
F_20 ( V_125 , L_32 , V_12 -> V_48 ) ;
if ( V_12 -> V_113 > 0 )
F_19 ( V_125 , L_33 ,
( int ) F_21 ( V_12 , V_12 -> V_113 ) ) ;
if ( V_12 -> V_114 > 0 )
F_19 ( V_125 , L_34 ,
( int ) F_21 ( V_12 , V_12 -> V_114 ) ) ;
if ( V_12 -> V_82 & ( V_89 | V_91 ) )
F_18 ( V_125 , L_35 ) ;
else if ( V_12 -> V_82 & V_89 )
F_18 ( V_125 , L_36 ) ;
if ( V_12 -> V_82 & V_96 ) {
if ( V_12 -> V_82 & V_98 )
F_18 ( V_125 , L_37 ) ;
else
F_18 ( V_125 , L_38 ) ;
}
if ( V_12 -> V_82 & V_102 ) {
if ( V_12 -> V_82 & V_104 )
F_18 ( V_125 , L_39 ) ;
else
F_18 ( V_125 , L_40 ) ;
}
if ( ! ( V_12 -> V_82 & V_83 ) )
F_18 ( V_125 , L_41 ) ;
return 0 ;
}
static T_3
F_22 (
unsigned int V_132 )
{
unsigned int V_133 = 1 ;
unsigned int V_134 = V_135 - 1 ;
#if V_135 == 32
# if F_23 ( V_136 )
ASSERT ( sizeof( V_137 ) == 8 ) ;
V_133 = V_138 ;
V_134 = V_135 ;
# else
V_133 = V_138 >> ( V_139 - V_132 ) ;
# endif
#endif
return ( ( ( T_3 ) V_133 ) << V_134 ) - 1 ;
}
T_4
F_24 (
struct V_11 * V_12 ,
T_4 V_140 )
{
T_4 V_141 ;
T_4 V_142 = 0 ;
T_5 * V_143 = & V_12 -> V_144 ;
T_4 V_145 ;
T_6 V_146 ;
T_7 V_147 ;
if ( V_12 -> V_148 ) {
T_3 V_149 ;
V_149 = V_143 -> V_150 * V_143 -> V_151 ;
F_25 ( V_149 , 100 ) ;
V_149 += V_143 -> V_152 - 1 ;
F_25 ( V_149 , V_143 -> V_152 ) ;
V_145 = V_149 ;
} else {
V_145 = V_140 ;
}
V_146 = F_26 ( V_12 , V_143 -> V_152 - 1 , 0 ) ;
V_147 = F_27 ( V_12 , V_140 - 1 , V_146 ) ;
if ( ( V_12 -> V_28 & V_66 ) && V_147 > V_153 )
V_12 -> V_28 |= V_154 ;
else
V_12 -> V_28 &= ~ V_154 ;
for ( V_141 = 0 ; V_141 < V_140 ; V_141 ++ ) {
struct V_155 * V_156 ;
V_147 = F_27 ( V_12 , V_141 , V_146 ) ;
V_156 = F_28 ( V_12 , V_141 ) ;
if ( V_12 -> V_28 & V_154 ) {
if ( V_147 > V_153 ) {
V_156 -> V_157 = 0 ;
V_156 -> V_158 = 0 ;
} else {
V_156 -> V_157 = 1 ;
V_142 ++ ;
if ( V_141 < V_145 )
V_156 -> V_158 = 1 ;
else
V_156 -> V_158 = 0 ;
}
} else {
V_156 -> V_157 = 1 ;
V_156 -> V_158 = 0 ;
}
F_29 ( V_156 ) ;
}
return ( V_12 -> V_28 & V_154 ) ? V_142 : V_140 ;
}
STATIC int
F_30 (
T_8 * V_12 ,
const char * V_159 ,
struct V_160 * * V_161 )
{
int error = 0 ;
* V_161 = F_31 ( V_159 , V_162 | V_163 | V_164 ,
V_12 ) ;
if ( F_32 ( * V_161 ) ) {
error = F_33 ( * V_161 ) ;
F_11 ( V_12 , L_42 , V_159 , error ) ;
}
return error ;
}
STATIC void
F_34 (
struct V_160 * V_165 )
{
if ( V_165 )
F_35 ( V_165 , V_162 | V_163 | V_164 ) ;
}
void
F_36 (
T_9 * V_166 )
{
F_37 ( V_166 -> V_167 , V_168 , NULL ) ;
}
STATIC void
F_38 (
struct V_11 * V_12 )
{
struct V_169 * V_170 = V_12 -> V_171 -> V_172 ;
if ( V_12 -> V_173 && V_12 -> V_173 != V_12 -> V_171 ) {
struct V_160 * V_174 = V_12 -> V_173 -> V_167 ;
struct V_169 * V_175 = V_12 -> V_173 -> V_172 ;
F_39 ( V_12 , V_12 -> V_173 ) ;
F_34 ( V_174 ) ;
F_40 ( V_175 ) ;
}
if ( V_12 -> V_176 ) {
struct V_160 * V_177 = V_12 -> V_176 -> V_167 ;
struct V_169 * V_178 = V_12 -> V_176 -> V_172 ;
F_39 ( V_12 , V_12 -> V_176 ) ;
F_34 ( V_177 ) ;
F_40 ( V_178 ) ;
}
F_39 ( V_12 , V_12 -> V_171 ) ;
F_40 ( V_170 ) ;
}
STATIC int
F_41 (
struct V_11 * V_12 )
{
struct V_160 * V_179 = V_12 -> V_16 -> V_180 ;
struct V_169 * V_170 = F_42 ( V_179 ) ;
struct V_169 * V_175 = NULL , * V_178 = NULL ;
struct V_160 * V_174 = NULL , * V_177 = NULL ;
int error ;
if ( V_12 -> V_45 ) {
error = F_30 ( V_12 , V_12 -> V_45 , & V_174 ) ;
if ( error )
goto V_181;
V_175 = F_42 ( V_174 ) ;
}
if ( V_12 -> V_48 ) {
error = F_30 ( V_12 , V_12 -> V_48 , & V_177 ) ;
if ( error )
goto V_182;
if ( V_177 == V_179 || V_177 == V_174 ) {
F_11 ( V_12 ,
L_43 ) ;
error = - V_10 ;
goto V_183;
}
V_178 = F_42 ( V_177 ) ;
}
error = - V_9 ;
V_12 -> V_171 = F_43 ( V_12 , V_179 , V_170 ) ;
if ( ! V_12 -> V_171 )
goto V_183;
if ( V_177 ) {
V_12 -> V_176 = F_43 ( V_12 , V_177 , V_178 ) ;
if ( ! V_12 -> V_176 )
goto V_184;
}
if ( V_174 && V_174 != V_179 ) {
V_12 -> V_173 = F_43 ( V_12 , V_174 , V_175 ) ;
if ( ! V_12 -> V_173 )
goto V_185;
} else {
V_12 -> V_173 = V_12 -> V_171 ;
}
return 0 ;
V_185:
if ( V_12 -> V_176 )
F_39 ( V_12 , V_12 -> V_176 ) ;
V_184:
F_39 ( V_12 , V_12 -> V_171 ) ;
V_183:
F_34 ( V_177 ) ;
F_40 ( V_178 ) ;
V_182:
if ( V_174 && V_174 != V_179 ) {
F_34 ( V_174 ) ;
F_40 ( V_175 ) ;
}
V_181:
F_40 ( V_170 ) ;
return error ;
}
STATIC int
F_44 (
struct V_11 * V_12 )
{
int error ;
error = F_45 ( V_12 -> V_171 , V_12 -> V_144 . V_186 ) ;
if ( error )
return error ;
if ( V_12 -> V_173 && V_12 -> V_173 != V_12 -> V_171 ) {
unsigned int V_187 = V_188 ;
if ( F_46 ( & V_12 -> V_144 ) )
V_187 = V_12 -> V_144 . V_189 ;
error = F_45 ( V_12 -> V_173 ,
V_187 ) ;
if ( error )
return error ;
}
if ( V_12 -> V_176 ) {
error = F_45 ( V_12 -> V_176 ,
V_12 -> V_144 . V_186 ) ;
if ( error )
return error ;
}
return 0 ;
}
STATIC int
F_47 (
struct V_11 * V_12 )
{
V_12 -> V_190 = F_48 ( L_44 ,
V_191 | V_192 , 1 , V_12 -> V_23 ) ;
if ( ! V_12 -> V_190 )
goto V_181;
V_12 -> V_193 = F_48 ( L_45 ,
V_191 | V_192 , 0 , V_12 -> V_23 ) ;
if ( ! V_12 -> V_193 )
goto V_194;
V_12 -> V_195 = F_48 ( L_46 ,
V_191 | V_192 , 0 , V_12 -> V_23 ) ;
if ( ! V_12 -> V_195 )
goto V_196;
V_12 -> V_197 = F_48 ( L_47 ,
V_191 | V_192 , 0 , V_12 -> V_23 ) ;
if ( ! V_12 -> V_197 )
goto V_198;
V_12 -> V_199 = F_48 ( L_48 ,
V_191 | V_192 , 0 , V_12 -> V_23 ) ;
if ( ! V_12 -> V_199 )
goto V_200;
V_12 -> V_201 = F_48 ( L_49 ,
V_191 | V_192 | V_202 , 0 ,
V_12 -> V_23 ) ;
if ( ! V_12 -> V_201 )
goto V_203;
V_12 -> V_204 = F_48 ( L_50 ,
V_191 | V_192 , 0 , V_12 -> V_23 ) ;
if ( ! V_12 -> V_204 )
goto V_205;
V_12 -> V_206 = F_48 ( L_51 , V_192 , 0 ,
V_12 -> V_23 ) ;
if ( ! V_12 -> V_206 )
goto V_207;
return 0 ;
V_207:
F_49 ( V_12 -> V_204 ) ;
V_205:
F_49 ( V_12 -> V_201 ) ;
V_203:
F_49 ( V_12 -> V_199 ) ;
V_200:
F_49 ( V_12 -> V_197 ) ;
V_198:
F_49 ( V_12 -> V_195 ) ;
V_196:
F_49 ( V_12 -> V_193 ) ;
V_194:
F_49 ( V_12 -> V_190 ) ;
V_181:
return - V_9 ;
}
STATIC void
F_50 (
struct V_11 * V_12 )
{
F_49 ( V_12 -> V_206 ) ;
F_49 ( V_12 -> V_204 ) ;
F_49 ( V_12 -> V_201 ) ;
F_49 ( V_12 -> V_199 ) ;
F_49 ( V_12 -> V_197 ) ;
F_49 ( V_12 -> V_193 ) ;
F_49 ( V_12 -> V_195 ) ;
F_49 ( V_12 -> V_190 ) ;
}
void
F_51 (
struct V_11 * V_12 )
{
struct V_14 * V_15 = V_12 -> V_16 ;
if ( F_52 ( & V_15 -> V_208 ) ) {
F_53 ( V_15 ) ;
F_54 ( & V_15 -> V_208 ) ;
}
}
STATIC struct V_209 *
F_55 (
struct V_14 * V_15 )
{
F_56 () ;
return NULL ;
}
STATIC void
F_57 (
struct V_209 * V_209 )
{
struct V_210 * V_211 = F_58 ( V_209 ) ;
int error ;
F_59 ( V_211 ) ;
ASSERT ( ! F_60 ( & V_209 -> V_212 ) ) ;
F_61 ( V_211 -> V_213 , V_214 ) ;
F_61 ( V_211 -> V_213 , V_215 ) ;
if ( F_62 ( V_211 ) ) {
error = F_63 ( V_211 , 0 , V_216 , true ) ;
if ( error && ! F_64 ( V_211 -> V_213 ) )
F_11 ( V_211 -> V_213 ,
L_52 ,
error , V_211 -> V_217 ) ;
}
F_65 ( V_211 ) ;
ASSERT ( F_64 ( V_211 -> V_213 ) || V_211 -> V_218 == 0 ) ;
F_61 ( V_211 -> V_213 , V_219 ) ;
F_66 ( ! F_67 ( V_211 , V_220 ) ) ;
F_66 ( ! F_67 ( V_211 , V_221 ) ) ;
F_68 ( V_211 ) ;
}
STATIC void
F_69 (
void * V_209 )
{
struct V_210 * V_211 = V_209 ;
memset ( V_211 , 0 , sizeof( struct V_210 ) ) ;
F_70 ( F_71 ( V_211 ) ) ;
F_72 ( & V_211 -> V_222 , 0 ) ;
F_73 ( & V_211 -> V_223 ) ;
F_74 ( & V_211 -> V_224 , V_225 | V_226 ,
L_53 , V_211 -> V_217 ) ;
F_74 ( & V_211 -> V_227 , V_225 | V_226 ,
L_53 , V_211 -> V_217 ) ;
}
STATIC int
F_75 (
struct V_209 * V_209 )
{
struct V_210 * V_211 = F_58 ( V_209 ) ;
if ( V_211 -> V_228 & V_229 ) {
ASSERT ( V_211 -> V_213 -> V_230 -> V_231 & V_232 ) ;
return 0 ;
}
return F_76 ( V_209 ) || ( V_211 -> V_228 & V_233 ) ;
}
STATIC void
F_77 (
struct V_11 * V_12 )
{
F_4 ( V_12 -> V_23 ) ;
F_4 ( V_12 -> V_48 ) ;
F_4 ( V_12 -> V_45 ) ;
}
STATIC int
F_78 (
struct V_14 * V_15 ,
int V_234 )
{
struct V_11 * V_12 = F_79 ( V_15 ) ;
if ( ! V_234 )
return 0 ;
F_80 ( V_12 , V_235 ) ;
if ( V_236 ) {
F_81 ( & V_12 -> V_230 -> V_237 ) ;
}
return 0 ;
}
STATIC int
F_82 (
struct V_238 * V_238 ,
struct V_239 * V_240 )
{
struct V_11 * V_12 = F_79 ( V_238 -> V_241 ) ;
T_5 * V_143 = & V_12 -> V_144 ;
struct V_210 * V_211 = F_58 ( F_83 ( V_238 ) ) ;
T_3 V_242 , V_243 ;
T_3 V_149 ;
T_3 V_244 ;
T_3 V_245 ;
T_10 V_246 ;
T_11 V_247 ;
V_240 -> V_248 = V_249 ;
V_240 -> V_250 = V_25 - 1 ;
V_243 = F_84 ( V_12 -> V_171 -> V_251 ) ;
V_240 -> V_252 . V_253 [ 0 ] = ( V_254 ) V_243 ;
V_240 -> V_252 . V_253 [ 1 ] = ( V_254 ) ( V_243 >> 32 ) ;
V_149 = F_85 ( & V_12 -> V_255 ) ;
V_244 = F_85 ( & V_12 -> V_256 ) ;
V_245 = F_85 ( & V_12 -> V_257 ) ;
F_86 ( & V_12 -> V_258 ) ;
V_240 -> V_259 = V_143 -> V_260 ;
V_246 = V_143 -> V_261 ? V_143 -> V_262 : 0 ;
V_240 -> V_263 = V_143 -> V_150 - V_246 ;
F_87 ( & V_12 -> V_258 ) ;
V_240 -> V_264 = V_245 - V_12 -> V_265 ;
V_240 -> V_266 = V_240 -> V_264 ;
V_242 = V_240 -> V_264 << V_143 -> V_267 ;
V_240 -> V_268 = F_88 ( V_149 + V_242 , ( T_3 ) V_269 ) ;
if ( V_12 -> V_148 )
V_240 -> V_268 = F_89 ( F_90 ( V_240 -> V_268 ) ,
V_240 -> V_268 ,
V_12 -> V_148 ) ;
V_240 -> V_268 = F_91 ( F_90 ( V_240 -> V_268 ) ,
V_240 -> V_268 ,
V_143 -> V_270 ) ;
V_247 = V_240 -> V_268 - ( V_149 - V_244 ) ;
V_240 -> V_271 = F_91 ( T_11 , V_247 , 0 ) ;
if ( ( V_211 -> V_272 . V_273 & V_274 ) &&
( ( V_12 -> V_82 & ( V_96 | V_98 ) ) ) ==
( V_96 | V_98 ) )
F_92 ( V_211 , V_240 ) ;
return 0 ;
}
STATIC void
F_93 ( struct V_11 * V_12 )
{
T_3 V_275 = 0 ;
V_12 -> V_276 = V_12 -> V_277 ;
F_94 ( V_12 , & V_275 , NULL ) ;
}
STATIC void
F_95 ( struct V_11 * V_12 )
{
T_3 V_275 ;
if ( V_12 -> V_276 ) {
V_275 = V_12 -> V_276 ;
V_12 -> V_276 = 0 ;
} else
V_275 = F_96 ( V_12 ) ;
F_94 ( V_12 , & V_275 , NULL ) ;
}
void
F_97 (
struct V_11 * V_12 )
{
int error = 0 ;
while ( F_98 ( & V_12 -> V_278 ) > 0 )
F_99 ( 100 ) ;
F_80 ( V_12 , V_235 ) ;
F_100 ( V_12 , 0 ) ;
F_100 ( V_12 , V_279 ) ;
error = F_101 ( V_12 ) ;
if ( error )
F_11 ( V_12 , L_54
L_55 ) ;
F_102 ( F_98 ( & V_12 -> V_278 ) != 0 ) ;
F_103 ( V_12 ) ;
}
STATIC int
F_104 (
struct V_14 * V_15 ,
struct V_11 * V_12 ,
char * V_13 )
{
int error = 0 ;
struct V_11 * V_280 ;
V_280 = F_105 ( sizeof( * V_280 ) , V_281 ) ;
if ( ! V_280 )
return - V_9 ;
V_280 -> V_16 = V_15 ;
error = F_5 ( V_280 , V_13 ) ;
F_77 ( V_280 ) ;
F_106 ( V_280 ) ;
return error ;
}
STATIC int
F_107 (
struct V_14 * V_15 ,
int * V_282 ,
char * V_13 )
{
struct V_11 * V_12 = F_79 ( V_15 ) ;
T_5 * V_143 = & V_12 -> V_144 ;
T_1 args [ V_18 ] ;
char * V_17 ;
int error ;
error = F_104 ( V_15 , V_12 , V_13 ) ;
if ( error )
return error ;
F_108 ( V_15 ) ;
while ( ( V_17 = F_8 ( & V_13 , L_1 ) ) != NULL ) {
int V_40 ;
if ( ! * V_17 )
continue;
V_40 = F_9 ( V_17 , V_41 , args ) ;
switch ( V_40 ) {
case V_111 :
F_11 ( V_12 , L_3 , V_17 ) ;
V_12 -> V_28 |= V_35 ;
break;
case V_112 :
F_11 ( V_12 , L_3 , V_17 ) ;
V_12 -> V_28 &= ~ V_35 ;
break;
case V_67 :
V_12 -> V_28 &= ~ V_66 ;
V_12 -> V_283 = F_24 ( V_12 , V_143 -> V_284 ) ;
break;
case V_65 :
V_12 -> V_28 |= V_66 ;
V_12 -> V_283 = F_24 ( V_12 , V_143 -> V_284 ) ;
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
if ( ( V_12 -> V_28 & V_29 ) && ! ( * V_282 & V_285 ) ) {
if ( V_12 -> V_28 & V_58 ) {
F_11 ( V_12 ,
L_56 ) ;
return - V_10 ;
}
if ( F_109 ( V_143 ) == V_286 &&
F_110 ( V_143 ,
V_287 ) ) {
F_11 ( V_12 ,
L_57 ,
( V_143 -> V_288 &
V_287 ) ) ;
return - V_10 ;
}
V_12 -> V_28 &= ~ V_29 ;
if ( V_12 -> V_289 ) {
error = F_111 ( V_12 , false ) ;
if ( error ) {
F_11 ( V_12 , L_58 ) ;
return error ;
}
V_12 -> V_289 = false ;
}
F_95 ( V_12 ) ;
F_112 ( V_12 ) ;
F_113 ( V_12 ) ;
error = F_114 ( V_12 ) ;
if ( error ) {
F_115 ( V_12 ,
L_59 , error ) ;
F_116 ( V_12 , V_290 ) ;
return error ;
}
error = F_117 ( V_12 ) ;
if ( error && error != - V_291 )
return error ;
}
if ( ! ( V_12 -> V_28 & V_29 ) && ( * V_282 & V_285 ) ) {
error = F_118 ( V_12 ) ;
if ( error ) {
F_116 ( V_12 , V_290 ) ;
return error ;
}
F_93 ( V_12 ) ;
F_119 ( & V_12 -> V_292 ) ;
F_97 ( V_12 ) ;
V_12 -> V_28 |= V_29 ;
}
return 0 ;
}
STATIC int
F_120 (
struct V_14 * V_15 )
{
struct V_11 * V_12 = F_79 ( V_15 ) ;
F_93 ( V_12 ) ;
F_97 ( V_12 ) ;
return F_111 ( V_12 , true ) ;
}
STATIC int
F_121 (
struct V_14 * V_15 )
{
struct V_11 * V_12 = F_79 ( V_15 ) ;
F_95 ( V_12 ) ;
F_112 ( V_12 ) ;
return 0 ;
}
STATIC int
F_122 (
struct V_124 * V_125 ,
struct V_238 * V_293 )
{
return F_17 ( F_79 ( V_293 -> V_241 ) , V_125 ) ;
}
STATIC int
F_123 (
struct V_11 * V_12 )
{
int V_294 = ( V_12 -> V_28 & V_29 ) ;
if ( F_124 ( & V_12 -> V_144 ) ) {
if ( V_12 -> V_38 <= 0 &&
V_12 -> V_144 . V_295 > V_296 ) {
V_12 -> V_38 = V_12 -> V_144 . V_295 ;
} else if ( V_12 -> V_38 > 0 &&
V_12 -> V_38 < V_12 -> V_144 . V_295 ) {
F_11 ( V_12 ,
L_60 ) ;
return - V_10 ;
}
} else {
if ( V_12 -> V_38 > V_296 ) {
F_11 ( V_12 ,
L_61 ) ;
return - V_10 ;
}
}
if ( F_125 ( & V_12 -> V_144 ) &&
( V_12 -> V_28 & V_78 ) ) {
F_11 ( V_12 , L_62
L_63 ) ;
return - V_10 ;
}
if ( F_126 ( & V_12 -> V_144 ) &&
! ( V_12 -> V_28 & V_78 ) )
V_12 -> V_28 |= V_76 ;
if ( ( V_12 -> V_144 . V_297 & V_298 ) && ! V_294 ) {
F_11 ( V_12 ,
L_64 ) ;
return - V_299 ;
}
if ( ( V_12 -> V_82 & ( V_102 | V_103 ) ) &&
( V_12 -> V_82 & ( V_96 | V_97 ) ) &&
! F_127 ( & V_12 -> V_144 ) ) {
F_11 ( V_12 ,
L_65 ) ;
return - V_10 ;
}
return 0 ;
}
static int
F_128 (
struct V_11 * V_12 )
{
int error ;
error = F_129 ( & V_12 -> V_255 , 0 , V_26 ) ;
if ( error )
return - V_9 ;
error = F_129 ( & V_12 -> V_256 , 0 , V_26 ) ;
if ( error )
goto V_300;
error = F_129 ( & V_12 -> V_257 , 0 , V_26 ) ;
if ( error )
goto V_301;
return 0 ;
V_301:
F_130 ( & V_12 -> V_256 ) ;
V_300:
F_130 ( & V_12 -> V_255 ) ;
return - V_9 ;
}
void
F_131 (
struct V_11 * V_12 )
{
F_132 ( & V_12 -> V_255 , V_12 -> V_144 . V_270 ) ;
F_132 ( & V_12 -> V_256 , V_12 -> V_144 . V_302 ) ;
F_132 ( & V_12 -> V_257 , V_12 -> V_144 . V_303 ) ;
}
static void
F_133 (
struct V_11 * V_12 )
{
F_130 ( & V_12 -> V_255 ) ;
F_130 ( & V_12 -> V_256 ) ;
F_130 ( & V_12 -> V_257 ) ;
}
STATIC int
F_134 (
struct V_14 * V_15 ,
void * V_304 ,
int V_305 )
{
struct V_209 * V_293 ;
struct V_11 * V_12 = NULL ;
int V_282 = 0 , error = - V_9 ;
V_12 = F_135 ( sizeof( struct V_11 ) , V_26 ) ;
if ( ! V_12 )
goto V_181;
F_73 ( & V_12 -> V_258 ) ;
F_136 ( & V_12 -> V_306 ) ;
F_72 ( & V_12 -> V_278 , 0 ) ;
F_137 ( & V_12 -> V_307 , V_308 ) ;
F_137 ( & V_12 -> V_292 , V_309 ) ;
F_137 ( & V_12 -> V_310 , V_311 ) ;
V_12 -> V_312 . V_313 . V_314 = V_315 ;
V_12 -> V_16 = V_15 ;
V_15 -> V_316 = V_12 ;
error = F_5 ( V_12 , ( char * ) V_304 ) ;
if ( error )
goto V_317;
F_138 ( V_15 , V_188 ) ;
V_15 -> V_318 = V_319 ;
V_15 -> V_320 = & V_321 ;
#ifdef F_14
V_15 -> V_322 = & V_323 ;
V_15 -> V_324 = V_325 | V_326 | V_327 ;
#endif
V_15 -> V_328 = & V_329 ;
if ( V_305 )
V_282 |= V_330 ;
error = F_41 ( V_12 ) ;
if ( error )
goto V_317;
error = F_47 ( V_12 ) ;
if ( error )
goto V_331;
error = F_128 ( V_12 ) ;
if ( error )
goto V_332;
V_12 -> V_333 . V_334 = F_139 ( struct V_335 ) ;
if ( ! V_12 -> V_333 . V_334 ) {
error = - V_9 ;
goto V_336;
}
error = F_140 ( V_12 , V_282 ) ;
if ( error )
goto V_337;
error = F_123 ( V_12 ) ;
if ( error )
goto V_338;
error = F_44 ( V_12 ) ;
if ( error )
goto V_338;
error = F_141 ( V_12 ) ;
if ( error )
goto V_338;
V_15 -> V_339 = V_249 ;
V_15 -> V_340 = V_12 -> V_144 . V_260 ;
V_15 -> V_341 = F_12 ( V_15 -> V_340 ) - 1 ;
V_15 -> V_342 = F_22 ( V_15 -> V_341 ) ;
V_15 -> V_343 = V_344 ;
V_15 -> V_345 = 1 ;
F_142 ( V_15 ) ;
if ( F_109 ( & V_12 -> V_144 ) == V_286 )
V_15 -> V_30 |= V_346 ;
if ( V_12 -> V_28 & V_110 ) {
F_11 ( V_12 ,
L_66 ) ;
error = F_143 ( V_15 , V_15 -> V_340 ) ;
if ( error ) {
F_144 ( V_12 ,
L_67 ) ;
V_12 -> V_28 &= ~ V_110 ;
}
if ( F_145 ( & V_12 -> V_144 ) )
F_144 ( V_12 ,
L_68 ) ;
}
if ( V_12 -> V_28 & V_107 ) {
struct V_347 * V_348 = F_146 ( V_15 -> V_180 ) ;
if ( ! F_147 ( V_348 ) ) {
F_11 ( V_12 , L_69
L_70 ) ;
V_12 -> V_28 &= ~ V_107 ;
}
}
if ( F_148 ( & V_12 -> V_144 ) ) {
if ( V_12 -> V_144 . V_349 ) {
F_144 ( V_12 ,
L_71 ) ;
error = - V_10 ;
goto V_350;
}
F_144 ( V_12 ,
L_72 ) ;
}
if ( F_145 ( & V_12 -> V_144 ) )
F_144 ( V_12 ,
L_73 ) ;
error = F_149 ( V_12 ) ;
if ( error )
goto V_350;
V_293 = F_150 ( F_71 ( V_12 -> V_351 ) ) ;
if ( ! V_293 ) {
error = - V_352 ;
goto V_353;
}
V_15 -> V_354 = F_151 ( V_293 ) ;
if ( ! V_15 -> V_354 ) {
error = - V_9 ;
goto V_353;
}
return 0 ;
V_350:
F_152 ( V_12 ) ;
V_338:
F_153 ( V_12 ) ;
V_337:
F_154 ( V_12 -> V_333 . V_334 ) ;
V_336:
F_133 ( V_12 ) ;
V_332:
F_50 ( V_12 ) ;
V_331:
F_38 ( V_12 ) ;
V_317:
F_77 ( V_12 ) ;
F_4 ( V_12 ) ;
V_181:
return error ;
V_353:
F_152 ( V_12 ) ;
F_155 ( V_12 ) ;
goto V_338;
}
STATIC void
F_156 (
struct V_14 * V_15 )
{
struct V_11 * V_12 = F_79 ( V_15 ) ;
F_157 ( V_12 , L_74 ) ;
F_152 ( V_12 ) ;
F_155 ( V_12 ) ;
F_153 ( V_12 ) ;
F_154 ( V_12 -> V_333 . V_334 ) ;
F_133 ( V_12 ) ;
F_50 ( V_12 ) ;
F_38 ( V_12 ) ;
F_77 ( V_12 ) ;
F_4 ( V_12 ) ;
}
STATIC struct V_238 *
F_158 (
struct V_355 * V_356 ,
int V_282 ,
const char * V_357 ,
void * V_304 )
{
return F_159 ( V_356 , V_282 , V_357 , V_304 , F_134 ) ;
}
static long
F_160 (
struct V_14 * V_15 ,
struct V_358 * V_359 )
{
return F_161 ( F_79 ( V_15 ) ) ;
}
static long
F_162 (
struct V_14 * V_15 ,
struct V_358 * V_359 )
{
return F_163 ( F_79 ( V_15 ) , V_359 -> V_360 ) ;
}
STATIC int T_12
F_164 ( void )
{
V_361 = F_165 ( 4 * V_362 ,
F_166 ( struct V_363 , V_364 ) ,
V_365 ) ;
if ( ! V_361 )
goto V_181;
V_366 = F_167 ( sizeof( V_367 ) ,
L_75 ) ;
if ( ! V_366 )
goto V_368;
V_369 = F_167 (
sizeof( struct V_370 ) ,
L_76 ) ;
if ( ! V_369 )
goto V_371;
V_372 = F_167 ( sizeof( V_373 ) ,
L_77 ) ;
if ( ! V_372 )
goto V_374;
V_375 = F_167 ( sizeof( V_376 ) ,
L_78 ) ;
if ( ! V_375 )
goto V_377;
V_378 = F_167 ( sizeof( V_379 ) , L_79 ) ;
if ( ! V_378 )
goto V_380;
V_381 = F_167 ( sizeof( V_382 ) , L_80 ) ;
if ( ! V_381 )
goto V_383;
V_384 =
F_167 ( sizeof( struct V_385 ) ,
L_81 ) ;
if ( ! V_384 )
goto V_386;
V_387 = F_167 ( sizeof( struct V_388 ) ,
L_82 ) ;
if ( ! V_387 )
goto V_389;
V_390 = F_167 ( ( sizeof( V_391 ) +
( ( V_392 - 1 ) *
sizeof( V_393 ) ) ) , L_83 ) ;
if ( ! V_390 )
goto V_394;
V_395 = F_167 ( ( sizeof( V_396 ) +
( ( V_397 - 1 ) *
sizeof( V_393 ) ) ) , L_84 ) ;
if ( ! V_395 )
goto V_398;
V_399 =
F_168 ( sizeof( V_400 ) , L_85 ,
V_401 | V_402 | V_403 |
V_404 , F_69 ) ;
if ( ! V_399 )
goto V_405;
V_406 =
F_168 ( sizeof( V_407 ) , L_86 ,
V_403 , NULL ) ;
if ( ! V_406 )
goto V_408;
V_409 = F_167 ( sizeof( struct V_410 ) ,
L_87 ) ;
if ( ! V_409 )
goto V_411;
V_412 = F_167 ( sizeof( struct V_413 ) ,
L_88 ) ;
if ( ! V_412 )
goto V_414;
V_415 = F_167 (
F_169 ( V_416 ) ,
L_89 ) ;
if ( ! V_415 )
goto V_417;
V_418 = F_167 ( sizeof( struct V_419 ) ,
L_90 ) ;
if ( ! V_418 )
goto V_420;
V_421 = F_167 (
F_170 ( V_422 ) ,
L_91 ) ;
if ( ! V_421 )
goto V_423;
V_424 = F_167 ( sizeof( struct V_425 ) ,
L_92 ) ;
if ( ! V_424 )
goto V_426;
V_427 = F_167 (
F_171 ( V_428 ) ,
L_93 ) ;
if ( ! V_427 )
goto V_429;
return 0 ;
V_429:
F_172 ( V_424 ) ;
V_426:
F_172 ( V_421 ) ;
V_423:
F_172 ( V_418 ) ;
V_420:
F_172 ( V_415 ) ;
V_417:
F_172 ( V_412 ) ;
V_414:
F_172 ( V_409 ) ;
V_411:
F_172 ( V_406 ) ;
V_408:
F_172 ( V_399 ) ;
V_405:
F_172 ( V_395 ) ;
V_398:
F_172 ( V_390 ) ;
V_394:
F_172 ( V_387 ) ;
V_389:
F_172 ( V_384 ) ;
V_386:
F_172 ( V_381 ) ;
V_383:
F_172 ( V_378 ) ;
V_380:
F_172 ( V_375 ) ;
V_377:
F_172 ( V_372 ) ;
V_374:
F_172 ( V_369 ) ;
V_371:
F_172 ( V_366 ) ;
V_368:
F_173 ( V_361 ) ;
V_181:
return - V_9 ;
}
STATIC void
F_174 ( void )
{
F_175 () ;
F_172 ( V_427 ) ;
F_172 ( V_424 ) ;
F_172 ( V_421 ) ;
F_172 ( V_418 ) ;
F_172 ( V_415 ) ;
F_172 ( V_412 ) ;
F_172 ( V_409 ) ;
F_172 ( V_406 ) ;
F_172 ( V_399 ) ;
F_172 ( V_395 ) ;
F_172 ( V_390 ) ;
F_172 ( V_387 ) ;
F_172 ( V_384 ) ;
F_172 ( V_381 ) ;
F_172 ( V_378 ) ;
F_172 ( V_375 ) ;
F_172 ( V_372 ) ;
F_172 ( V_369 ) ;
F_172 ( V_366 ) ;
F_173 ( V_361 ) ;
}
STATIC int T_12
F_176 ( void )
{
V_430 = F_48 ( L_94 ,
V_191 | V_192 , 0 ) ;
if ( ! V_430 )
return - V_9 ;
V_431 = F_48 ( L_95 , V_432 , 0 ) ;
if ( ! V_431 )
goto V_433;
return 0 ;
V_433:
F_49 ( V_430 ) ;
return - V_9 ;
}
STATIC void
F_177 ( void )
{
F_49 ( V_431 ) ;
F_49 ( V_430 ) ;
}
STATIC int T_12
F_178 ( void )
{
int error ;
F_179 () ;
F_180 (KERN_INFO XFS_VERSION_STRING L_96
XFS_BUILD_OPTIONS L_97 ) ;
F_181 () ;
F_182 () ;
F_183 () ;
F_184 () ;
F_185 () ;
error = F_164 () ;
if ( error )
goto V_181;
error = F_176 () ;
if ( error )
goto V_434;
error = F_186 () ;
if ( error )
goto V_435;
error = F_187 () ;
if ( error )
goto V_436;
error = F_188 () ;
if ( error )
goto V_437;
error = F_189 () ;
if ( error )
goto V_438;
V_315 = F_190 ( L_98 , NULL , V_439 ) ;
if ( ! V_315 ) {
error = - V_9 ;
goto V_440;
}
V_335 . V_441 . V_313 . V_314 = V_315 ;
V_335 . V_334 = F_139 ( struct V_335 ) ;
if ( ! V_335 . V_334 ) {
error = - V_9 ;
goto V_442;
}
error = F_191 ( & V_335 . V_441 , & V_443 , NULL ,
L_99 ) ;
if ( error )
goto V_337;
#ifdef F_192
V_444 . V_313 . V_314 = V_315 ;
error = F_191 ( & V_444 , & V_445 , NULL , L_100 ) ;
if ( error )
goto V_446;
#endif
error = F_193 () ;
if ( error )
goto V_447;
error = F_194 ( & V_448 ) ;
if ( error )
goto V_449;
return 0 ;
V_449:
F_195 () ;
V_447:
#ifdef F_192
F_196 ( & V_444 ) ;
V_446:
#endif
F_196 ( & V_335 . V_441 ) ;
V_337:
F_154 ( V_335 . V_334 ) ;
V_442:
F_197 ( V_315 ) ;
V_440:
F_198 () ;
V_438:
F_199 () ;
V_437:
F_200 () ;
V_436:
F_201 () ;
V_435:
F_177 () ;
V_434:
F_174 () ;
V_181:
return error ;
}
STATIC void T_13
F_202 ( void )
{
F_195 () ;
F_203 ( & V_448 ) ;
#ifdef F_192
F_196 ( & V_444 ) ;
#endif
F_196 ( & V_335 . V_441 ) ;
F_154 ( V_335 . V_334 ) ;
F_197 ( V_315 ) ;
F_198 () ;
F_199 () ;
F_200 () ;
F_201 () ;
F_177 () ;
F_174 () ;
F_204 () ;
}
