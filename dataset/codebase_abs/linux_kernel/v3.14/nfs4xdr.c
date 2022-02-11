static T_1
F_1 ( char * V_1 , int V_2 )
{
int V_3 ;
if ( V_2 == 0 )
return V_4 ;
if ( F_2 ( V_1 , V_2 ) )
return V_5 ;
for ( V_3 = 0 ; V_3 < V_2 ; V_3 ++ )
if ( V_1 [ V_3 ] == '/' )
return V_5 ;
return 0 ;
}
static void F_3 ( struct V_6 * V_7 )
{
V_7 -> V_8 = F_4 ( V_7 -> V_9 [ 0 ] ) ;
V_7 -> V_9 ++ ;
if ( V_7 -> V_10 < V_11 ) {
V_7 -> V_12 = V_7 -> V_8 + ( V_7 -> V_10 >> 2 ) ;
V_7 -> V_10 = 0 ;
} else {
V_7 -> V_12 = V_7 -> V_8 + ( V_11 >> 2 ) ;
V_7 -> V_10 -= V_11 ;
}
}
static T_1 * F_5 ( struct V_6 * V_7 , T_2 V_13 )
{
unsigned int V_14 = ( char * ) V_7 -> V_12 - ( char * ) V_7 -> V_8 ;
T_1 * V_8 ;
if ( V_14 + V_7 -> V_10 < V_13 )
return NULL ;
if ( V_14 + V_11 < V_13 )
return NULL ;
if ( V_13 <= sizeof( V_7 -> V_15 ) )
V_8 = V_7 -> V_15 ;
else {
F_6 ( V_7 -> V_16 ) ;
V_8 = V_7 -> V_16 = F_7 ( V_13 , V_17 ) ;
if ( ! V_8 )
return NULL ;
}
memcpy ( V_8 , V_7 -> V_8 , V_14 ) ;
F_3 ( V_7 ) ;
memcpy ( ( ( char * ) V_8 ) + V_14 , V_7 -> V_8 , ( V_13 - V_14 ) ) ;
V_7 -> V_8 += F_8 ( V_13 - V_14 ) ;
return V_8 ;
}
static int F_9 ( T_3 * V_18 )
{
return ( V_18 -> V_19 == 0 ) && ( V_18 -> V_20 == 0 ) ;
}
static int
F_10 ( struct V_6 * V_7 ,
void (* F_11)( const void * ) , void * V_8 )
{
struct V_21 * V_22 ;
V_22 = F_7 ( sizeof( * V_22 ) , V_17 ) ;
if ( ! V_22 )
return - V_23 ;
V_22 -> V_24 = V_8 ;
V_22 -> F_11 = F_11 ;
V_22 -> V_25 = V_7 -> V_26 ;
V_7 -> V_26 = V_22 ;
return 0 ;
}
static char * F_12 ( struct V_6 * V_7 , T_1 * V_8 , int V_13 )
{
if ( V_8 == V_7 -> V_15 ) {
V_8 = F_13 ( V_7 -> V_15 , V_13 , V_17 ) ;
if ( ! V_8 )
return NULL ;
} else {
F_14 ( V_8 != V_7 -> V_16 ) ;
V_7 -> V_16 = NULL ;
}
if ( F_10 ( V_7 , F_6 , V_8 ) ) {
F_6 ( V_8 ) ;
return NULL ;
} else
return ( char * ) V_8 ;
}
static T_1
F_15 ( struct V_6 * V_7 , T_2 * V_27 )
{
T_2 V_28 ;
V_29 ;
V_27 [ 0 ] = 0 ;
V_27 [ 1 ] = 0 ;
V_27 [ 2 ] = 0 ;
F_16 ( 4 ) ;
F_17 ( V_28 ) ;
if ( V_28 > 1000 )
goto V_30;
F_16 ( V_28 << 2 ) ;
if ( V_28 > 0 )
F_17 ( V_27 [ 0 ] ) ;
if ( V_28 > 1 )
F_17 ( V_27 [ 1 ] ) ;
if ( V_28 > 2 )
F_17 ( V_27 [ 2 ] ) ;
V_31 ;
}
static T_1
F_18 ( struct V_6 * V_7 , T_2 * V_27 ,
struct V_32 * V_32 , struct V_33 * * V_34 ,
struct V_35 * V_36 )
{
int V_37 , V_2 = 0 ;
T_2 V_38 ;
char * V_24 ;
V_29 ;
V_32 -> V_39 = 0 ;
if ( ( V_40 = F_15 ( V_7 , V_27 ) ) )
return V_40 ;
F_16 ( 4 ) ;
F_17 ( V_37 ) ;
if ( V_27 [ 0 ] & V_41 ) {
F_16 ( 8 ) ;
V_2 += 8 ;
F_19 ( V_32 -> V_42 ) ;
V_32 -> V_39 |= V_43 ;
}
if ( V_27 [ 0 ] & V_44 ) {
T_2 V_45 ;
struct V_46 * V_47 ;
F_16 ( 4 ) ; V_2 += 4 ;
F_17 ( V_45 ) ;
if ( V_45 > V_48 )
return V_49 ;
* V_34 = F_20 ( V_45 ) ;
if ( * V_34 == NULL )
return V_50 ;
F_10 ( V_7 , F_6 , * V_34 ) ;
( * V_34 ) -> V_51 = V_45 ;
for ( V_47 = ( * V_34 ) -> V_52 ; V_47 < ( * V_34 ) -> V_52 + V_45 ; V_47 ++ ) {
F_16 ( 16 ) ; V_2 += 16 ;
F_17 ( V_47 -> type ) ;
F_17 ( V_47 -> V_53 ) ;
F_17 ( V_47 -> V_54 ) ;
F_17 ( V_38 ) ;
F_16 ( V_38 ) ;
V_2 += F_8 ( V_38 ) << 2 ;
F_21 ( V_24 , V_38 ) ;
V_47 -> V_55 = F_22 ( V_24 , V_38 ) ;
V_40 = V_56 ;
if ( V_47 -> V_55 != V_57 )
;
else if ( V_47 -> V_53 & V_58 )
V_40 = F_23 ( V_7 -> V_59 ,
V_24 , V_38 , & V_47 -> V_60 ) ;
else
V_40 = F_24 ( V_7 -> V_59 ,
V_24 , V_38 , & V_47 -> V_61 ) ;
if ( V_40 )
return V_40 ;
}
} else
* V_34 = NULL ;
if ( V_27 [ 1 ] & V_62 ) {
F_16 ( 4 ) ;
V_2 += 4 ;
F_17 ( V_32 -> V_63 ) ;
V_32 -> V_63 &= ( V_64 | V_65 ) ;
V_32 -> V_39 |= V_66 ;
}
if ( V_27 [ 1 ] & V_67 ) {
F_16 ( 4 ) ;
V_2 += 4 ;
F_17 ( V_38 ) ;
F_16 ( V_38 ) ;
V_2 += ( F_8 ( V_38 ) << 2 ) ;
F_21 ( V_24 , V_38 ) ;
if ( ( V_40 = F_24 ( V_7 -> V_59 , V_24 , V_38 , & V_32 -> V_68 ) ) )
return V_40 ;
V_32 -> V_39 |= V_69 ;
}
if ( V_27 [ 1 ] & V_70 ) {
F_16 ( 4 ) ;
V_2 += 4 ;
F_17 ( V_38 ) ;
F_16 ( V_38 ) ;
V_2 += ( F_8 ( V_38 ) << 2 ) ;
F_21 ( V_24 , V_38 ) ;
if ( ( V_40 = F_23 ( V_7 -> V_59 , V_24 , V_38 , & V_32 -> V_71 ) ) )
return V_40 ;
V_32 -> V_39 |= V_72 ;
}
if ( V_27 [ 1 ] & V_73 ) {
F_16 ( 4 ) ;
V_2 += 4 ;
F_17 ( V_38 ) ;
switch ( V_38 ) {
case V_74 :
F_16 ( 12 ) ;
V_2 += 12 ;
F_19 ( V_32 -> V_75 . V_76 ) ;
F_17 ( V_32 -> V_75 . V_77 ) ;
if ( V_32 -> V_75 . V_77 >= ( T_2 ) 1000000000 )
return V_4 ;
V_32 -> V_39 |= ( V_78 | V_79 ) ;
break;
case V_80 :
V_32 -> V_39 |= V_78 ;
break;
default:
goto V_30;
}
}
if ( V_27 [ 1 ] & V_81 ) {
F_16 ( 4 ) ;
V_2 += 4 ;
F_17 ( V_38 ) ;
switch ( V_38 ) {
case V_74 :
F_16 ( 12 ) ;
V_2 += 12 ;
F_19 ( V_32 -> V_82 . V_76 ) ;
F_17 ( V_32 -> V_82 . V_77 ) ;
if ( V_32 -> V_82 . V_77 >= ( T_2 ) 1000000000 )
return V_4 ;
V_32 -> V_39 |= ( V_83 | V_84 ) ;
break;
case V_80 :
V_32 -> V_39 |= V_83 ;
break;
default:
goto V_30;
}
}
V_36 -> V_2 = 0 ;
#ifdef F_25
if ( V_27 [ 2 ] & V_85 ) {
F_16 ( 4 ) ;
V_2 += 4 ;
F_17 ( V_38 ) ;
F_16 ( 4 ) ;
V_2 += 4 ;
F_17 ( V_38 ) ;
F_16 ( 4 ) ;
V_2 += 4 ;
F_17 ( V_38 ) ;
F_16 ( V_38 ) ;
if ( V_38 > V_86 )
return V_87 ;
V_2 += ( F_8 ( V_38 ) << 2 ) ;
F_21 ( V_24 , V_38 ) ;
V_36 -> V_88 = F_26 ( V_38 + 1 , V_17 ) ;
if ( ! V_36 -> V_88 )
return V_50 ;
V_36 -> V_2 = V_38 ;
F_10 ( V_7 , F_6 , V_36 -> V_88 ) ;
memcpy ( V_36 -> V_88 , V_24 , V_38 ) ;
}
#endif
if ( V_27 [ 0 ] & ~ V_89
|| V_27 [ 1 ] & ~ V_90
|| V_27 [ 2 ] & ~ V_91 )
F_16 ( V_37 - V_2 ) ;
else if ( V_2 != V_37 )
goto V_30;
V_31 ;
}
static T_1
F_27 ( struct V_6 * V_7 , T_4 * V_92 )
{
V_29 ;
F_16 ( sizeof( T_4 ) ) ;
F_17 ( V_92 -> V_93 ) ;
F_28 ( & V_92 -> V_94 , sizeof( V_95 ) ) ;
V_31 ;
}
static T_1
F_29 ( struct V_6 * V_7 , struct V_96 * V_97 )
{
V_29 ;
F_16 ( 4 ) ;
F_17 ( V_97 -> V_98 ) ;
V_31 ;
}
static T_1 F_30 ( struct V_6 * V_7 , struct V_99 * V_100 )
{
V_29 ;
T_2 V_101 , V_102 , V_103 ;
char * V_104 ;
int V_3 ;
int V_105 ;
F_16 ( 4 ) ;
F_17 ( V_105 ) ;
if ( V_105 )
V_100 -> V_106 = ( T_2 ) ( - 1 ) ;
else
V_100 -> V_106 = 0 ;
for ( V_3 = 0 ; V_3 < V_105 ; ++ V_3 ) {
F_16 ( 4 ) ;
F_17 ( V_101 ) ;
switch ( V_101 ) {
case V_107 :
if ( V_100 -> V_106 == ( T_2 ) ( - 1 ) )
V_100 -> V_106 = V_107 ;
break;
case V_108 :
F_16 ( 8 ) ;
F_17 ( V_101 ) ;
F_17 ( V_101 ) ;
F_16 ( V_101 ) ;
F_31 ( V_104 , V_101 ) ;
F_16 ( 8 ) ;
F_17 ( V_102 ) ;
F_17 ( V_103 ) ;
F_16 ( 4 ) ;
F_17 ( V_101 ) ;
F_16 ( V_101 * 4 ) ;
if ( V_100 -> V_106 == ( T_2 ) ( - 1 ) ) {
T_5 V_109 = F_32 ( & V_110 , V_102 ) ;
T_6 V_111 = F_33 ( & V_110 , V_103 ) ;
if ( F_34 ( V_109 ) && F_35 ( V_111 ) ) {
V_100 -> V_102 = V_109 ;
V_100 -> V_103 = V_111 ;
V_100 -> V_106 = V_108 ;
} else {
F_36 ( L_1
L_2 ) ;
}
}
break;
case V_112 :
F_36 ( L_3
L_4 ) ;
F_16 ( 8 ) ;
F_17 ( V_101 ) ;
F_17 ( V_101 ) ;
F_16 ( V_101 ) ;
V_8 += F_8 ( V_101 ) ;
F_16 ( 4 ) ;
F_17 ( V_101 ) ;
F_16 ( V_101 ) ;
break;
default:
F_36 ( L_5 ) ;
return V_4 ;
}
}
V_31 ;
}
static T_1 F_37 ( struct V_6 * V_7 , struct V_113 * V_114 )
{
V_29 ;
F_16 ( 4 ) ;
F_17 ( V_114 -> V_115 ) ;
F_30 ( V_7 , & V_114 -> V_116 ) ;
V_31 ;
}
static T_1 F_38 ( struct V_6 * V_7 , struct V_117 * V_118 )
{
V_29 ;
F_16 ( V_119 + 8 ) ;
F_28 ( V_118 -> V_120 . V_88 , V_119 ) ;
F_17 ( V_118 -> V_121 ) ;
V_31 ;
}
static T_1
F_39 ( struct V_6 * V_7 , struct V_122 * V_123 )
{
V_29 ;
F_16 ( 4 ) ;
F_17 ( V_123 -> V_124 ) ;
return F_27 ( V_7 , & V_123 -> V_125 ) ;
V_31 ;
}
static T_1
F_40 ( struct V_6 * V_7 , struct V_126 * V_127 )
{
V_29 ;
F_16 ( 12 ) ;
F_19 ( V_127 -> V_128 ) ;
F_17 ( V_127 -> V_129 ) ;
V_31 ;
}
static T_1
F_41 ( struct V_6 * V_7 , struct V_130 * V_131 )
{
V_29 ;
F_16 ( 4 ) ;
F_17 ( V_131 -> V_132 ) ;
switch ( V_131 -> V_132 ) {
case V_133 :
F_16 ( 4 ) ;
F_17 ( V_131 -> V_134 ) ;
F_16 ( V_131 -> V_134 ) ;
F_31 ( V_131 -> V_135 , V_131 -> V_134 ) ;
break;
case V_136 :
case V_137 :
F_16 ( 8 ) ;
F_17 ( V_131 -> V_138 ) ;
F_17 ( V_131 -> V_139 ) ;
break;
case V_140 :
case V_141 :
case V_142 :
default:
break;
}
F_16 ( 4 ) ;
F_17 ( V_131 -> V_143 ) ;
F_16 ( V_131 -> V_143 ) ;
F_31 ( V_131 -> V_144 , V_131 -> V_143 ) ;
if ( ( V_40 = F_1 ( V_131 -> V_144 , V_131 -> V_143 ) ) )
return V_40 ;
V_40 = F_18 ( V_7 , V_131 -> V_145 , & V_131 -> V_146 ,
& V_131 -> V_147 , & V_131 -> V_148 ) ;
if ( V_40 )
goto V_149;
V_31 ;
}
static inline T_1
F_42 ( struct V_6 * V_7 , struct V_150 * V_151 )
{
return F_27 ( V_7 , & V_151 -> V_152 ) ;
}
static inline T_1
F_43 ( struct V_6 * V_7 , struct V_153 * V_154 )
{
return F_15 ( V_7 , V_154 -> V_155 ) ;
}
static T_1
F_44 ( struct V_6 * V_7 , struct V_156 * V_157 )
{
V_29 ;
F_16 ( 4 ) ;
F_17 ( V_157 -> V_158 ) ;
F_16 ( V_157 -> V_158 ) ;
F_31 ( V_157 -> V_159 , V_157 -> V_158 ) ;
if ( ( V_40 = F_1 ( V_157 -> V_159 , V_157 -> V_158 ) ) )
return V_40 ;
V_31 ;
}
static T_1
F_45 ( struct V_6 * V_7 , struct V_160 * V_161 )
{
V_29 ;
F_16 ( 28 ) ;
F_17 ( V_161 -> V_162 ) ;
if ( ( V_161 -> V_162 < V_163 ) || ( V_161 -> V_162 > V_164 ) )
goto V_30;
F_17 ( V_161 -> V_165 ) ;
F_19 ( V_161 -> V_166 ) ;
F_19 ( V_161 -> V_167 ) ;
F_17 ( V_161 -> V_168 ) ;
if ( V_161 -> V_168 ) {
F_16 ( 4 ) ;
F_17 ( V_161 -> V_169 ) ;
V_40 = F_27 ( V_7 , & V_161 -> V_170 ) ;
if ( V_40 )
return V_40 ;
F_16 ( 8 + sizeof( T_3 ) ) ;
F_17 ( V_161 -> V_171 ) ;
F_28 ( & V_161 -> V_172 , sizeof( T_3 ) ) ;
F_17 ( V_161 -> V_173 . V_2 ) ;
F_16 ( V_161 -> V_173 . V_2 ) ;
F_21 ( V_161 -> V_173 . V_88 , V_161 -> V_173 . V_2 ) ;
} else {
V_40 = F_27 ( V_7 , & V_161 -> V_174 ) ;
if ( V_40 )
return V_40 ;
F_16 ( 4 ) ;
F_17 ( V_161 -> V_175 ) ;
}
V_31 ;
}
static T_1
F_46 ( struct V_6 * V_7 , struct V_176 * V_177 )
{
V_29 ;
F_16 ( 32 ) ;
F_17 ( V_177 -> V_178 ) ;
if( ( V_177 -> V_178 < V_163 ) || ( V_177 -> V_178 > V_164 ) )
goto V_30;
F_19 ( V_177 -> V_179 ) ;
F_19 ( V_177 -> V_180 ) ;
F_28 ( & V_177 -> V_181 , 8 ) ;
F_17 ( V_177 -> V_182 . V_2 ) ;
F_16 ( V_177 -> V_182 . V_2 ) ;
F_21 ( V_177 -> V_182 . V_88 , V_177 -> V_182 . V_2 ) ;
V_31 ;
}
static T_1
F_47 ( struct V_6 * V_7 , struct V_183 * V_184 )
{
V_29 ;
F_16 ( 8 ) ;
F_17 ( V_184 -> V_185 ) ;
if ( ( V_184 -> V_185 < V_163 ) || ( V_184 -> V_185 > V_164 ) )
goto V_30;
F_17 ( V_184 -> V_186 ) ;
V_40 = F_27 ( V_7 , & V_184 -> V_187 ) ;
if ( V_40 )
return V_40 ;
F_16 ( 16 ) ;
F_19 ( V_184 -> V_188 ) ;
F_19 ( V_184 -> V_189 ) ;
V_31 ;
}
static T_1
F_48 ( struct V_6 * V_7 , struct V_190 * V_191 )
{
V_29 ;
F_16 ( 4 ) ;
F_17 ( V_191 -> V_192 ) ;
F_16 ( V_191 -> V_192 ) ;
F_31 ( V_191 -> V_193 , V_191 -> V_192 ) ;
if ( ( V_40 = F_1 ( V_191 -> V_193 , V_191 -> V_192 ) ) )
return V_40 ;
V_31 ;
}
static T_1 F_49 ( struct V_6 * V_7 , T_2 * V_194 , T_2 * V_195 , T_2 * V_196 )
{
T_1 * V_8 ;
T_2 V_197 ;
F_16 ( 4 ) ;
F_17 ( V_197 ) ;
* V_194 = V_197 & V_198 ;
* V_195 = V_197 & V_199 ;
if ( V_196 )
* V_196 = V_197 & V_200 ;
switch ( V_197 & V_198 ) {
case V_201 :
case V_202 :
case V_203 :
break;
default:
return V_204 ;
}
V_197 &= ~ V_198 ;
if ( ! V_197 )
return V_56 ;
if ( ! V_7 -> V_205 )
return V_204 ;
switch ( V_197 & V_199 ) {
case V_206 :
case V_207 :
case V_208 :
case V_209 :
case V_210 :
case V_211 :
break;
default:
return V_204 ;
}
V_197 &= ~ V_199 ;
if ( ! V_197 )
return V_56 ;
if ( ! V_196 )
return V_4 ;
switch ( V_197 ) {
case V_212 :
case V_213 :
case ( V_212 |
V_213 ) :
return V_56 ;
}
V_30:
return V_204 ;
}
static T_1 F_50 ( struct V_6 * V_7 , T_2 * V_214 )
{
T_1 * V_8 ;
F_16 ( 4 ) ;
F_17 ( * V_214 ) ;
if ( * V_214 & ~ V_215 )
return V_204 ;
return V_56 ;
V_30:
return V_204 ;
}
static T_1 F_51 ( struct V_6 * V_7 , struct V_35 * V_216 )
{
T_1 * V_8 ;
F_16 ( 4 ) ;
F_17 ( V_216 -> V_2 ) ;
if ( V_216 -> V_2 == 0 || V_216 -> V_2 > V_217 )
return V_204 ;
F_16 ( V_216 -> V_2 ) ;
F_31 ( V_216 -> V_88 , V_216 -> V_2 ) ;
return V_56 ;
V_30:
return V_204 ;
}
static T_1
F_52 ( struct V_6 * V_7 , struct V_218 * V_219 )
{
V_29 ;
T_2 V_101 ;
memset ( V_219 -> V_220 , 0 , sizeof( V_219 -> V_220 ) ) ;
V_219 -> V_221 . V_39 = 0 ;
V_219 -> V_222 = NULL ;
V_219 -> V_223 = 0 ;
F_16 ( 4 ) ;
F_17 ( V_219 -> V_224 ) ;
V_40 = F_49 ( V_7 , & V_219 -> V_225 ,
& V_219 -> V_226 , & V_101 ) ;
if ( V_40 )
goto V_30;
V_40 = F_50 ( V_7 , & V_219 -> V_227 ) ;
if ( V_40 )
goto V_30;
F_16 ( sizeof( T_3 ) ) ;
F_28 ( & V_219 -> V_228 , sizeof( T_3 ) ) ;
V_40 = F_51 ( V_7 , & V_219 -> V_229 ) ;
if ( V_40 )
goto V_30;
F_16 ( 4 ) ;
F_17 ( V_219 -> V_230 ) ;
switch ( V_219 -> V_230 ) {
case V_231 :
break;
case V_232 :
F_16 ( 4 ) ;
F_17 ( V_219 -> V_233 ) ;
switch ( V_219 -> V_233 ) {
case V_234 :
case V_235 :
V_40 = F_18 ( V_7 , V_219 -> V_220 ,
& V_219 -> V_221 , & V_219 -> V_236 , & V_219 -> V_237 ) ;
if ( V_40 )
goto V_149;
break;
case V_238 :
F_16 ( V_239 ) ;
F_28 ( V_219 -> V_240 . V_88 , V_239 ) ;
break;
case V_241 :
if ( V_7 -> V_205 < 1 )
goto V_30;
F_16 ( V_239 ) ;
F_28 ( V_219 -> V_240 . V_88 , V_239 ) ;
V_40 = F_18 ( V_7 , V_219 -> V_220 ,
& V_219 -> V_221 , & V_219 -> V_236 , & V_219 -> V_237 ) ;
if ( V_40 )
goto V_149;
break;
default:
goto V_30;
}
break;
default:
goto V_30;
}
F_16 ( 4 ) ;
F_17 ( V_219 -> V_242 ) ;
switch ( V_219 -> V_242 ) {
case V_243 :
case V_244 :
F_16 ( 4 ) ;
F_17 ( V_219 -> V_245 . V_2 ) ;
F_16 ( V_219 -> V_245 . V_2 ) ;
F_31 ( V_219 -> V_245 . V_88 , V_219 -> V_245 . V_2 ) ;
if ( ( V_40 = F_1 ( V_219 -> V_245 . V_88 , V_219 -> V_245 . V_2 ) ) )
return V_40 ;
break;
case V_246 :
F_16 ( 4 ) ;
F_17 ( V_219 -> V_247 ) ;
break;
case V_248 :
V_40 = F_27 ( V_7 , & V_219 -> V_249 ) ;
if ( V_40 )
return V_40 ;
F_16 ( 4 ) ;
F_17 ( V_219 -> V_245 . V_2 ) ;
F_16 ( V_219 -> V_245 . V_2 ) ;
F_31 ( V_219 -> V_245 . V_88 , V_219 -> V_245 . V_2 ) ;
if ( ( V_40 = F_1 ( V_219 -> V_245 . V_88 , V_219 -> V_245 . V_2 ) ) )
return V_40 ;
break;
case V_250 :
case V_251 :
if ( V_7 -> V_205 < 1 )
goto V_30;
break;
case V_252 :
if ( V_7 -> V_205 < 1 )
goto V_30;
V_40 = F_27 ( V_7 , & V_219 -> V_249 ) ;
if ( V_40 )
return V_40 ;
break;
default:
goto V_30;
}
V_31 ;
}
static T_1
F_53 ( struct V_6 * V_7 , struct V_253 * V_254 )
{
V_29 ;
if ( V_7 -> V_205 >= 1 )
return V_255 ;
V_40 = F_27 ( V_7 , & V_254 -> V_256 ) ;
if ( V_40 )
return V_40 ;
F_16 ( 4 ) ;
F_17 ( V_254 -> V_257 ) ;
V_31 ;
}
static T_1
F_54 ( struct V_6 * V_7 , struct V_258 * V_259 )
{
V_29 ;
V_40 = F_27 ( V_7 , & V_259 -> V_260 ) ;
if ( V_40 )
return V_40 ;
F_16 ( 4 ) ;
F_17 ( V_259 -> V_261 ) ;
V_40 = F_49 ( V_7 , & V_259 -> V_262 ,
& V_259 -> V_263 , NULL ) ;
if ( V_40 )
return V_40 ;
V_40 = F_50 ( V_7 , & V_259 -> V_264 ) ;
if ( V_40 )
return V_40 ;
V_31 ;
}
static T_1
F_55 ( struct V_6 * V_7 , struct V_265 * V_266 )
{
V_29 ;
F_16 ( 4 ) ;
F_17 ( V_266 -> V_267 ) ;
if ( V_266 -> V_267 > V_268 )
goto V_30;
F_16 ( V_266 -> V_267 ) ;
F_31 ( V_266 -> V_269 , V_266 -> V_267 ) ;
V_31 ;
}
static T_1
F_56 ( struct V_6 * V_7 , void * V_8 )
{
if ( V_7 -> V_205 == 0 )
return V_56 ;
return V_255 ;
}
static T_1
F_57 ( struct V_6 * V_7 , struct V_270 * V_271 )
{
V_29 ;
V_40 = F_27 ( V_7 , & V_271 -> V_272 ) ;
if ( V_40 )
return V_40 ;
F_16 ( 12 ) ;
F_19 ( V_271 -> V_273 ) ;
F_17 ( V_271 -> V_274 ) ;
V_31 ;
}
static T_1
F_58 ( struct V_6 * V_7 , struct V_275 * V_276 )
{
V_29 ;
F_16 ( 24 ) ;
F_19 ( V_276 -> V_277 ) ;
F_28 ( V_276 -> V_278 . V_88 , sizeof( V_276 -> V_278 . V_88 ) ) ;
F_17 ( V_276 -> V_279 ) ;
F_17 ( V_276 -> V_280 ) ;
if ( ( V_40 = F_15 ( V_7 , V_276 -> V_281 ) ) )
goto V_149;
V_31 ;
}
static T_1
F_59 ( struct V_6 * V_7 , struct V_282 * remove )
{
V_29 ;
F_16 ( 4 ) ;
F_17 ( remove -> V_283 ) ;
F_16 ( remove -> V_283 ) ;
F_31 ( remove -> V_284 , remove -> V_283 ) ;
if ( ( V_40 = F_1 ( remove -> V_284 , remove -> V_283 ) ) )
return V_40 ;
V_31 ;
}
static T_1
F_60 ( struct V_6 * V_7 , struct V_285 * rename )
{
V_29 ;
F_16 ( 4 ) ;
F_17 ( rename -> V_286 ) ;
F_16 ( rename -> V_286 + 4 ) ;
F_31 ( rename -> V_287 , rename -> V_286 ) ;
F_17 ( rename -> V_288 ) ;
F_16 ( rename -> V_288 ) ;
F_31 ( rename -> V_289 , rename -> V_288 ) ;
if ( ( V_40 = F_1 ( rename -> V_287 , rename -> V_286 ) ) )
return V_40 ;
if ( ( V_40 = F_1 ( rename -> V_289 , rename -> V_288 ) ) )
return V_40 ;
V_31 ;
}
static T_1
F_61 ( struct V_6 * V_7 , T_3 * V_290 )
{
V_29 ;
if ( V_7 -> V_205 >= 1 )
return V_255 ;
F_16 ( sizeof( T_3 ) ) ;
F_28 ( V_290 , sizeof( T_3 ) ) ;
V_31 ;
}
static T_1
F_62 ( struct V_6 * V_7 ,
struct V_291 * V_292 )
{
V_29 ;
F_16 ( 4 ) ;
F_17 ( V_292 -> V_293 ) ;
F_16 ( V_292 -> V_293 ) ;
F_31 ( V_292 -> V_294 , V_292 -> V_293 ) ;
V_40 = F_1 ( V_292 -> V_294 , V_292 -> V_293 ) ;
if ( V_40 )
return V_40 ;
V_31 ;
}
static T_1
F_63 ( struct V_6 * V_7 ,
struct V_295 * sin )
{
V_29 ;
F_16 ( 4 ) ;
F_17 ( sin -> V_296 ) ;
V_31 ;
}
static T_1
F_64 ( struct V_6 * V_7 , struct V_297 * V_298 )
{
T_1 V_40 ;
V_40 = F_27 ( V_7 , & V_298 -> V_299 ) ;
if ( V_40 )
return V_40 ;
return F_18 ( V_7 , V_298 -> V_300 , & V_298 -> V_301 ,
& V_298 -> V_302 , & V_298 -> V_303 ) ;
}
static T_1
F_65 ( struct V_6 * V_7 , struct V_304 * V_305 )
{
V_29 ;
if ( V_7 -> V_205 >= 1 )
return V_255 ;
F_16 ( V_239 ) ;
F_28 ( V_305 -> V_306 . V_88 , V_239 ) ;
V_40 = F_51 ( V_7 , & V_305 -> V_307 ) ;
if ( V_40 )
return V_204 ;
F_16 ( 8 ) ;
F_17 ( V_305 -> V_308 ) ;
F_17 ( V_305 -> V_309 ) ;
F_16 ( V_305 -> V_309 + 4 ) ;
F_31 ( V_305 -> V_310 , V_305 -> V_309 ) ;
F_17 ( V_305 -> V_311 ) ;
F_16 ( V_305 -> V_311 + 4 ) ;
F_31 ( V_305 -> V_312 , V_305 -> V_311 ) ;
F_17 ( V_305 -> V_313 ) ;
V_31 ;
}
static T_1
F_66 ( struct V_6 * V_7 , struct V_314 * V_315 )
{
V_29 ;
if ( V_7 -> V_205 >= 1 )
return V_255 ;
F_16 ( 8 + V_239 ) ;
F_28 ( & V_315 -> V_316 , 8 ) ;
F_28 ( & V_315 -> V_317 , V_239 ) ;
V_31 ;
}
static T_1
F_67 ( struct V_6 * V_7 , struct V_318 * V_319 )
{
V_29 ;
if ( ( V_40 = F_15 ( V_7 , V_319 -> V_320 ) ) )
goto V_149;
F_16 ( 4 ) ;
F_17 ( V_319 -> V_321 ) ;
F_16 ( V_319 -> V_321 ) ;
F_31 ( V_319 -> V_322 , V_319 -> V_321 ) ;
V_31 ;
}
static T_1
F_68 ( struct V_6 * V_7 , struct V_323 * V_324 )
{
int V_14 ;
int V_2 ;
V_29 ;
V_40 = F_27 ( V_7 , & V_324 -> V_325 ) ;
if ( V_40 )
return V_40 ;
F_16 ( 16 ) ;
F_19 ( V_324 -> V_326 ) ;
F_17 ( V_324 -> V_327 ) ;
if ( V_324 -> V_327 > 2 )
goto V_30;
F_17 ( V_324 -> V_328 ) ;
V_14 = ( char * ) V_7 -> V_12 - ( char * ) V_7 -> V_8 ;
if ( V_14 + V_7 -> V_10 < V_324 -> V_328 ) {
F_36 ( L_6 ,
__FILE__ , __LINE__ ) ;
goto V_30;
}
V_324 -> V_329 . V_330 = V_8 ;
V_324 -> V_329 . V_331 = V_14 ;
F_69 ( V_14 != ( F_8 ( V_14 ) << 2 ) ) ;
V_324 -> V_332 = V_7 -> V_9 ;
V_2 = F_8 ( V_324 -> V_328 ) << 2 ;
if ( V_2 >= V_14 ) {
int V_333 ;
V_2 -= V_14 ;
V_333 = V_2 >> V_334 ;
V_7 -> V_9 += V_333 ;
V_7 -> V_10 -= V_333 * V_11 ;
V_2 -= V_333 * V_11 ;
V_7 -> V_8 = ( T_1 * ) F_4 ( V_7 -> V_9 [ 0 ] ) ;
V_7 -> V_9 ++ ;
V_7 -> V_12 = V_7 -> V_8 + F_8 ( V_11 ) ;
}
V_7 -> V_8 += F_8 ( V_2 ) ;
V_31 ;
}
static T_1
F_70 ( struct V_6 * V_7 , struct V_335 * V_336 )
{
V_29 ;
if ( V_7 -> V_205 >= 1 )
return V_255 ;
F_16 ( 12 ) ;
F_28 ( & V_336 -> V_337 , sizeof( T_3 ) ) ;
F_17 ( V_336 -> V_338 . V_2 ) ;
F_16 ( V_336 -> V_338 . V_2 ) ;
F_21 ( V_336 -> V_338 . V_88 , V_336 -> V_338 . V_2 ) ;
if ( V_7 -> V_205 && ! F_9 ( & V_336 -> V_337 ) )
return V_4 ;
V_31 ;
}
static T_1
F_71 ( struct V_6 * V_7 ,
struct V_339 * V_340 )
{
int V_101 , V_15 ;
V_29 ;
F_16 ( V_239 ) ;
F_28 ( V_340 -> V_341 . V_88 , V_239 ) ;
V_40 = F_51 ( V_7 , & V_340 -> V_342 ) ;
if ( V_40 )
return V_204 ;
F_16 ( 4 ) ;
F_17 ( V_340 -> V_343 ) ;
F_16 ( 4 ) ;
F_17 ( V_340 -> V_344 ) ;
switch ( V_340 -> V_344 ) {
case V_345 :
break;
case V_346 :
F_16 ( 4 ) ;
F_17 ( V_101 ) ;
F_16 ( V_101 * 4 ) ;
V_8 += V_101 ;
F_16 ( 4 ) ;
F_17 ( V_101 ) ;
F_16 ( V_101 * 4 ) ;
V_8 += V_101 ;
break;
case V_347 :
F_16 ( 4 ) ;
F_17 ( V_101 ) ;
F_16 ( V_101 * 4 ) ;
V_8 += V_101 ;
F_16 ( 4 ) ;
F_17 ( V_101 ) ;
F_16 ( V_101 * 4 ) ;
V_8 += V_101 ;
F_16 ( 4 ) ;
F_17 ( V_15 ) ;
while ( V_15 -- ) {
F_16 ( 4 ) ;
F_17 ( V_101 ) ;
F_16 ( V_101 ) ;
V_8 += F_8 ( V_101 ) ;
}
F_16 ( 4 ) ;
F_17 ( V_15 ) ;
while ( V_15 -- ) {
F_16 ( 4 ) ;
F_17 ( V_101 ) ;
F_16 ( V_101 ) ;
V_8 += F_8 ( V_101 ) ;
}
F_16 ( 8 ) ;
F_17 ( V_101 ) ;
F_17 ( V_101 ) ;
break;
default:
goto V_30;
}
F_16 ( 4 ) ;
F_17 ( V_101 ) ;
if ( V_101 > 1 )
goto V_30;
if ( V_101 == 1 ) {
F_16 ( 4 ) ;
F_17 ( V_101 ) ;
F_16 ( V_101 ) ;
V_8 += F_8 ( V_101 ) ;
F_16 ( 4 ) ;
F_17 ( V_101 ) ;
F_16 ( V_101 ) ;
V_8 += F_8 ( V_101 ) ;
F_16 ( 12 ) ;
V_8 += 3 ;
}
V_31 ;
}
static T_1
F_72 ( struct V_6 * V_7 ,
struct V_348 * V_349 )
{
V_29 ;
T_2 V_101 ;
F_16 ( 16 ) ;
F_28 ( & V_349 -> V_290 , 8 ) ;
F_17 ( V_349 -> V_350 ) ;
F_17 ( V_349 -> V_343 ) ;
F_16 ( 28 ) ;
F_17 ( V_101 ) ;
F_17 ( V_349 -> V_351 . V_352 ) ;
F_17 ( V_349 -> V_351 . V_353 ) ;
F_17 ( V_349 -> V_351 . V_354 ) ;
F_17 ( V_349 -> V_351 . V_355 ) ;
F_17 ( V_349 -> V_351 . V_356 ) ;
F_17 ( V_349 -> V_351 . V_357 ) ;
if ( V_349 -> V_351 . V_357 == 1 ) {
F_16 ( 4 ) ;
F_17 ( V_349 -> V_351 . V_358 ) ;
} else if ( V_349 -> V_351 . V_357 > 1 ) {
F_36 ( L_7 ) ;
goto V_30;
}
F_16 ( 28 ) ;
F_17 ( V_101 ) ;
F_17 ( V_349 -> V_359 . V_352 ) ;
F_17 ( V_349 -> V_359 . V_353 ) ;
F_17 ( V_349 -> V_359 . V_354 ) ;
F_17 ( V_349 -> V_359 . V_355 ) ;
F_17 ( V_349 -> V_359 . V_356 ) ;
F_17 ( V_349 -> V_359 . V_357 ) ;
if ( V_349 -> V_359 . V_357 == 1 ) {
F_16 ( 4 ) ;
F_17 ( V_349 -> V_359 . V_358 ) ;
} else if ( V_349 -> V_359 . V_357 > 1 ) {
F_36 ( L_8 ) ;
goto V_30;
}
F_16 ( 4 ) ;
F_17 ( V_349 -> V_360 ) ;
F_30 ( V_7 , & V_349 -> V_361 ) ;
V_31 ;
}
static T_1
F_73 ( struct V_6 * V_7 ,
struct V_362 * V_363 )
{
V_29 ;
F_16 ( V_119 ) ;
F_28 ( V_363 -> V_120 . V_88 , V_119 ) ;
V_31 ;
}
static T_1
F_74 ( struct V_6 * V_7 ,
struct V_364 * V_365 )
{
V_29 ;
F_16 ( sizeof( T_4 ) ) ;
F_17 ( V_365 -> V_366 . V_93 ) ;
F_28 ( & V_365 -> V_366 . V_94 , sizeof( V_95 ) ) ;
V_31 ;
}
static T_1
F_75 ( struct V_6 * V_7 ,
struct V_367 * V_368 )
{
V_29 ;
F_16 ( V_119 + 16 ) ;
F_28 ( V_368 -> V_120 . V_88 , V_119 ) ;
F_17 ( V_368 -> V_350 ) ;
F_17 ( V_368 -> V_369 ) ;
F_17 ( V_368 -> V_370 ) ;
F_17 ( V_368 -> V_371 ) ;
V_31 ;
}
static T_1
F_76 ( struct V_6 * V_7 , struct V_372 * V_373 )
{
int V_3 ;
T_1 * V_8 , V_40 ;
struct V_374 * V_375 ;
F_16 ( 4 ) ;
V_373 -> V_376 = F_77 ( * V_8 ++ ) ;
F_78 ( & V_373 -> V_377 ) ;
for ( V_3 = 0 ; V_3 < V_373 -> V_376 ; V_3 ++ ) {
V_375 = F_7 ( sizeof( struct V_374 ) , V_17 ) ;
if ( ! V_375 ) {
V_40 = F_79 ( - V_23 ) ;
goto V_149;
}
F_10 ( V_7 , F_6 , V_375 ) ;
F_78 ( & V_375 -> V_378 ) ;
F_80 ( & V_375 -> V_378 , & V_373 -> V_377 ) ;
V_40 = F_27 ( V_7 , & V_375 -> V_379 ) ;
if ( V_40 )
goto V_149;
}
V_40 = 0 ;
V_149:
return V_40 ;
V_30:
F_36 ( L_6 , __FILE__ , __LINE__ ) ;
V_40 = V_204 ;
goto V_149;
}
static T_1 F_81 ( struct V_6 * V_7 , struct V_380 * V_381 )
{
V_29 ;
F_16 ( 8 ) ;
F_28 ( & V_381 -> V_290 , 8 ) ;
V_31 ;
}
static T_1 F_82 ( struct V_6 * V_7 , struct V_382 * V_383 )
{
V_29 ;
F_16 ( 4 ) ;
F_17 ( V_383 -> V_384 ) ;
V_31 ;
}
static T_1
F_83 ( struct V_6 * V_7 , void * V_8 )
{
return V_56 ;
}
static T_1
F_84 ( struct V_6 * V_7 , void * V_8 )
{
return V_255 ;
}
static inline bool
F_85 ( struct V_6 * V_7 , struct V_385 * V_386 )
{
if ( V_386 -> V_387 < V_388 )
return false ;
else if ( V_7 -> V_205 == 0 && V_386 -> V_387 > V_389 )
return false ;
else if ( V_7 -> V_205 == 1 && V_386 -> V_387 > V_390 )
return false ;
else if ( V_7 -> V_205 == 2 && V_386 -> V_387 > V_391 )
return false ;
return true ;
}
static int F_86 ( T_2 V_387 )
{
switch ( V_387 ) {
case V_392 :
case V_393 :
return 2 * V_11 ;
case V_394 :
return V_395 ;
default:
return V_11 ;
}
}
static T_1
F_87 ( struct V_6 * V_7 )
{
V_29 ;
struct V_385 * V_386 ;
bool V_371 = false ;
int V_396 = V_11 ;
int V_3 ;
F_16 ( 4 ) ;
F_17 ( V_7 -> V_397 ) ;
F_16 ( V_7 -> V_397 + 8 ) ;
F_31 ( V_7 -> V_398 , V_7 -> V_397 ) ;
F_17 ( V_7 -> V_205 ) ;
F_17 ( V_7 -> V_399 ) ;
if ( V_7 -> V_397 > V_400 )
goto V_30;
if ( V_7 -> V_399 > 100 )
goto V_30;
if ( V_7 -> V_399 > F_88 ( V_7 -> V_401 ) ) {
V_7 -> V_402 = F_7 ( V_7 -> V_399 * sizeof( * V_7 -> V_402 ) , V_17 ) ;
if ( ! V_7 -> V_402 ) {
V_7 -> V_402 = V_7 -> V_401 ;
F_36 ( L_9 ) ;
goto V_30;
}
}
if ( V_7 -> V_205 > V_403 )
V_7 -> V_399 = 0 ;
for ( V_3 = 0 ; V_3 < V_7 -> V_399 ; V_3 ++ ) {
V_386 = & V_7 -> V_402 [ V_3 ] ;
V_386 -> V_404 = NULL ;
F_16 ( 4 ) ;
F_17 ( V_386 -> V_387 ) ;
if ( F_85 ( V_7 , V_386 ) )
V_386 -> V_40 = V_405 [ V_386 -> V_387 ] ( V_7 , & V_386 -> V_406 ) ;
else {
V_386 -> V_387 = V_407 ;
V_386 -> V_40 = V_408 ;
}
if ( V_386 -> V_40 ) {
V_7 -> V_399 = V_3 + 1 ;
break;
}
V_371 |= F_89 ( V_386 ) ;
V_396 = F_90 ( V_396 , F_86 ( V_386 -> V_387 ) ) ;
}
if ( V_7 -> V_205 )
V_371 = false ;
if ( V_396 != V_395 )
F_91 ( V_7 -> V_59 , V_396 ) ;
V_7 -> V_59 -> V_409 = V_371 ? V_410 : V_411 ;
V_31 ;
}
static void F_92 ( T_1 * * V_8 , T_2 V_412 )
{
* ( * V_8 ) ++ = F_93 ( V_412 ) ;
}
static void F_94 ( T_1 * * V_8 , T_7 V_412 )
{
F_92 ( V_8 , ( V_412 >> 32 ) ) ;
F_92 ( V_8 , ( T_2 ) V_412 ) ;
}
static void F_95 ( T_1 * * V_8 , struct V_413 * V_414 , struct V_415 * V_415 )
{
if ( F_96 ( V_415 ) ) {
F_94 ( V_8 , V_415 -> V_416 ) ;
} else {
F_92 ( V_8 , V_414 -> ctime . V_76 ) ;
F_92 ( V_8 , V_414 -> ctime . V_77 ) ;
}
}
static void F_97 ( T_1 * * V_8 , struct V_417 * V_418 )
{
F_92 ( V_8 , V_418 -> V_419 ) ;
if ( V_418 -> V_420 ) {
F_94 ( V_8 , V_418 -> V_421 ) ;
F_94 ( V_8 , V_418 -> V_422 ) ;
} else {
F_92 ( V_8 , V_418 -> V_423 ) ;
F_92 ( V_8 , V_418 -> V_424 ) ;
F_92 ( V_8 , V_418 -> V_425 ) ;
F_92 ( V_8 , V_418 -> V_426 ) ;
}
}
static T_1 F_98 ( char V_427 , char * V_428 ,
T_1 * * V_429 , int * V_430 ,
char V_431 , char V_432 )
{
T_1 * V_8 = * V_429 ;
T_1 * V_433 = V_8 ;
int strlen , V_434 = 0 ;
char * V_1 , * V_12 , * V_25 ;
F_36 ( L_10 , V_428 ) ;
if ( ( * V_430 -= 4 ) < 0 )
return V_49 ;
F_99 ( 0 ) ;
V_12 = V_1 = V_428 ;
while ( * V_12 ) {
bool V_435 = false ;
if ( * V_1 == V_431 ) {
for (; * V_12 && ( * V_12 != V_432 ) ; V_12 ++ )
;
V_25 = V_12 + 1 ;
if ( * V_12 && ( ! * V_25 || * V_25 == V_427 ) ) {
V_1 ++ ;
V_435 = true ;
}
}
if ( ! V_435 )
for (; * V_12 && ( * V_12 != V_427 ) ; V_12 ++ )
;
strlen = V_12 - V_1 ;
if ( strlen ) {
if ( ( * V_430 -= ( ( F_8 ( strlen ) << 2 ) + 4 ) ) < 0 )
return V_49 ;
F_99 ( strlen ) ;
F_100 ( V_1 , strlen ) ;
V_434 ++ ;
}
else
V_12 ++ ;
V_1 = V_12 ;
}
* V_429 = V_8 ;
V_8 = V_433 ;
F_99 ( V_434 ) ;
return 0 ;
}
static T_1 F_101 ( char V_427 , char * V_428 ,
T_1 * * V_429 , int * V_430 )
{
return F_98 ( V_427 , V_428 , V_429 , V_430 , 0 , 0 ) ;
}
static T_1 F_102 ( struct V_436 * V_437 ,
T_1 * * V_429 , int * V_430 )
{
T_1 V_40 ;
T_1 * V_8 = * V_429 ;
V_40 = F_98 ( ':' , V_437 -> V_438 , & V_8 , V_430 ,
'[' , ']' ) ;
if ( V_40 )
return V_40 ;
V_40 = F_101 ( '/' , V_437 -> V_439 , & V_8 , V_430 ) ;
if ( V_40 )
return V_40 ;
* V_429 = V_8 ;
return 0 ;
}
static T_1 F_103 ( const struct V_439 * V_440 ,
const struct V_439 * V_439 , T_1 * * V_429 , int * V_430 )
{
struct V_439 V_441 = * V_439 ;
T_1 * V_8 = * V_429 ;
struct V_442 * * V_428 = NULL ;
unsigned int V_443 = 0 ;
T_1 V_444 = V_50 ;
F_36 ( L_11 ) ;
F_104 ( & V_441 ) ;
for (; ; ) {
if ( V_441 . V_442 == V_440 -> V_442 && V_441 . V_445 == V_440 -> V_445 )
break;
if ( V_441 . V_442 == V_441 . V_445 -> V_446 ) {
if ( F_105 ( & V_441 ) )
continue;
goto V_447;
}
if ( ( V_443 & 15 ) == 0 ) {
struct V_442 * * V_448 ;
V_448 = F_106 ( V_428 ,
sizeof( * V_448 ) * ( V_443 + 16 ) ,
V_17 ) ;
if ( ! V_448 )
goto V_447;
V_428 = V_448 ;
}
V_428 [ V_443 ++ ] = V_441 . V_442 ;
V_441 . V_442 = F_107 ( V_441 . V_442 ) ;
}
* V_430 -= 4 ;
if ( * V_430 < 0 )
goto V_447;
F_99 ( V_443 ) ;
while ( V_443 ) {
struct V_442 * V_442 = V_428 [ V_443 - 1 ] ;
unsigned int V_2 ;
F_108 ( & V_442 -> V_449 ) ;
V_2 = V_442 -> V_450 . V_2 ;
* V_430 -= 4 + ( F_8 ( V_2 ) << 2 ) ;
if ( * V_430 < 0 ) {
F_109 ( & V_442 -> V_449 ) ;
goto V_447;
}
F_99 ( V_2 ) ;
F_100 ( V_442 -> V_450 . V_451 , V_2 ) ;
F_36 ( L_12 , V_442 -> V_450 . V_451 ) ;
F_109 ( & V_442 -> V_449 ) ;
F_110 ( V_442 ) ;
V_443 -- ;
}
* V_429 = V_8 ;
V_444 = 0 ;
V_447:
F_36 ( L_13 ) ;
while ( V_443 )
F_110 ( V_428 [ -- V_443 ] ) ;
F_6 ( V_428 ) ;
F_111 ( & V_441 ) ;
return V_444 ;
}
static T_1 F_112 ( struct V_452 * V_59 ,
const struct V_439 * V_439 , T_1 * * V_429 , int * V_430 )
{
struct V_453 * V_454 ;
T_1 V_455 ;
V_454 = F_113 ( V_59 ) ;
if ( F_114 ( V_454 ) )
return F_79 ( F_115 ( V_454 ) ) ;
V_455 = F_103 ( & V_454 -> V_456 , V_439 , V_429 , V_430 ) ;
F_116 ( V_454 ) ;
return V_455 ;
}
static T_1 F_117 ( struct V_452 * V_59 ,
struct V_453 * exp ,
T_1 * * V_429 , int * V_430 )
{
T_1 V_40 ;
int V_3 ;
T_1 * V_8 = * V_429 ;
struct V_457 * V_458 = & exp -> V_459 ;
V_40 = F_112 ( V_59 , & exp -> V_456 , & V_8 , V_430 ) ;
if ( V_40 )
return V_40 ;
if ( ( * V_430 -= 4 ) < 0 )
return V_49 ;
F_99 ( V_458 -> V_460 ) ;
for ( V_3 = 0 ; V_3 < V_458 -> V_460 ; V_3 ++ ) {
V_40 = F_102 ( & V_458 -> V_461 [ V_3 ] ,
& V_8 , V_430 ) ;
if ( V_40 )
return V_40 ;
}
* V_429 = V_8 ;
return 0 ;
}
static T_2 F_118 ( T_8 V_462 )
{
switch ( V_462 & V_64 ) {
case V_463 : return V_141 ;
case V_464 : return V_137 ;
case V_465 : return V_142 ;
case V_466 : return V_136 ;
case V_467 : return V_133 ;
case V_468 : return V_469 ;
case V_470 : return V_140 ;
default: return V_471 ;
} ;
}
static inline T_1
F_119 ( struct V_452 * V_59 , struct V_46 * V_47 ,
T_1 * * V_8 , int * V_430 )
{
if ( V_47 -> V_55 != V_57 )
return F_120 ( V_47 -> V_55 , V_8 , V_430 ) ;
else if ( V_47 -> V_53 & V_58 )
return F_121 ( V_59 , V_47 -> V_60 , V_8 , V_430 ) ;
else
return F_122 ( V_59 , V_47 -> V_61 , V_8 , V_430 ) ;
}
static inline T_1
F_123 ( struct V_452 * V_59 , void * V_472 , int V_2 , T_1 * * V_429 , int * V_430 )
{
T_1 * V_8 = * V_429 ;
if ( * V_430 < ( ( F_8 ( V_2 ) << 2 ) + 4 + 4 + 4 ) )
return V_49 ;
if ( ( * V_430 -= 8 ) < 0 )
return V_49 ;
F_99 ( 0 ) ;
F_99 ( 0 ) ;
V_8 = F_124 ( V_8 , V_472 , V_2 ) ;
* V_430 -= ( F_8 ( V_2 ) << 2 ) + 4 ;
* V_429 = V_8 ;
return 0 ;
}
static inline T_1
F_123 ( struct V_452 * V_59 , void * V_472 , int V_2 , T_1 * * V_429 , int * V_430 )
{ return 0 ; }
static T_1 F_125 ( T_2 * V_473 , T_2 * V_474 , T_2 * V_475 )
{
if ( * V_473 & ~ V_476 ||
* V_474 & ~ V_477 ) {
if ( * V_473 & V_478 ||
* V_473 & V_479 )
* V_475 = V_480 ;
else
return V_481 ;
}
* V_473 &= V_476 ;
* V_474 &= V_477 ;
return 0 ;
}
static int F_126 ( struct V_453 * exp , struct V_413 * V_414 )
{
struct V_439 V_439 = exp -> V_456 ;
int V_444 ;
F_104 ( & V_439 ) ;
while ( F_105 ( & V_439 ) ) {
if ( V_439 . V_442 != V_439 . V_445 -> V_446 )
break;
}
V_444 = F_127 ( & V_439 , V_414 ) ;
F_111 ( & V_439 ) ;
return V_444 ;
}
T_1
F_128 ( struct V_482 * V_483 , struct V_453 * exp ,
struct V_442 * V_442 , T_1 * * V_484 , int V_434 , T_2 * V_27 ,
struct V_452 * V_59 , int V_485 )
{
T_2 V_473 = V_27 [ 0 ] ;
T_2 V_474 = V_27 [ 1 ] ;
T_2 V_486 = V_27 [ 2 ] ;
struct V_413 V_414 ;
struct V_482 * V_487 = NULL ;
struct V_488 V_489 ;
int V_430 = V_434 << 2 ;
T_1 * V_490 ;
T_2 V_101 ;
T_7 V_491 ;
T_2 V_475 = 0 ;
T_1 * V_8 = * V_484 ;
T_1 V_40 ;
int V_444 ;
int V_492 = 0 ;
struct V_33 * V_34 = NULL ;
void * V_472 = NULL ;
int V_493 ;
bool V_494 = false ;
struct V_495 * V_496 = V_59 -> V_497 ;
T_2 V_205 = V_496 -> V_498 . V_205 ;
struct V_439 V_439 = {
. V_445 = exp -> V_456 . V_445 ,
. V_442 = V_442 ,
} ;
struct V_499 * V_500 = F_129 ( F_130 ( V_59 ) , V_501 ) ;
F_14 ( V_474 & V_502 ) ;
F_14 ( V_473 & ~ F_131 ( V_205 ) ) ;
F_14 ( V_474 & ~ F_132 ( V_205 ) ) ;
F_14 ( V_486 & ~ F_133 ( V_205 ) ) ;
if ( exp -> V_459 . V_503 ) {
F_14 ( V_27 [ 2 ] ) ;
V_40 = F_125 ( & V_473 , & V_474 , & V_475 ) ;
if ( V_40 )
goto V_149;
}
V_444 = F_127 ( & V_439 , & V_414 ) ;
if ( V_444 )
goto V_504;
if ( ( V_473 & ( V_505 | V_506 |
V_507 ) ) ||
( V_474 & ( V_508 | V_509 |
V_510 ) ) ) {
V_444 = F_134 ( & V_439 , & V_489 ) ;
if ( V_444 )
goto V_504;
}
if ( ( V_473 & ( V_511 | V_512 ) ) && ! V_483 ) {
V_487 = F_7 ( sizeof( struct V_482 ) , V_17 ) ;
V_40 = V_50 ;
if ( ! V_487 )
goto V_149;
F_135 ( V_487 , V_268 ) ;
V_40 = F_136 ( V_487 , exp , V_442 , NULL ) ;
if ( V_40 )
goto V_149;
V_483 = V_487 ;
}
if ( V_473 & ( V_44 | V_513
| V_514 ) ) {
V_444 = F_137 ( V_59 , V_442 , & V_34 ) ;
V_492 = ( V_444 == 0 ) ;
if ( V_473 & V_44 ) {
if ( V_444 == - V_515 )
V_473 &= ~ V_44 ;
else if ( V_444 == - V_516 ) {
V_40 = V_517 ;
goto V_149;
} else if ( V_444 != 0 )
goto V_504;
}
}
#ifdef F_25
if ( ( V_27 [ 2 ] & V_85 ) ||
V_27 [ 0 ] & V_514 ) {
V_444 = F_138 ( V_442 -> V_518 ,
& V_472 , & V_493 ) ;
V_494 = ( V_444 == 0 ) ;
if ( V_486 & V_85 ) {
if ( V_444 == - V_515 )
V_486 &= ~ V_85 ;
else if ( V_444 )
goto V_504;
}
}
#endif
if ( V_486 ) {
if ( ( V_430 -= 16 ) < 0 )
goto V_519;
F_99 ( 3 ) ;
F_99 ( V_473 ) ;
F_99 ( V_474 ) ;
F_99 ( V_486 ) ;
} else if ( V_474 ) {
if ( ( V_430 -= 12 ) < 0 )
goto V_519;
F_99 ( 2 ) ;
F_99 ( V_473 ) ;
F_99 ( V_474 ) ;
} else {
if ( ( V_430 -= 8 ) < 0 )
goto V_519;
F_99 ( 1 ) ;
F_99 ( V_473 ) ;
}
V_490 = V_8 ++ ;
if ( V_473 & V_514 ) {
T_2 V_520 = F_131 ( V_205 ) ;
T_2 V_521 = F_132 ( V_205 ) ;
T_2 V_522 = F_133 ( V_205 ) ;
if ( ! V_492 )
V_520 &= ~ V_44 ;
if ( ! V_494 )
V_522 &= ~ V_85 ;
if ( ! V_522 ) {
if ( ( V_430 -= 12 ) < 0 )
goto V_519;
F_99 ( 2 ) ;
F_99 ( V_520 ) ;
F_99 ( V_521 ) ;
} else {
if ( ( V_430 -= 16 ) < 0 )
goto V_519;
F_99 ( 3 ) ;
F_99 ( V_520 ) ;
F_99 ( V_521 ) ;
F_99 ( V_522 ) ;
}
}
if ( V_473 & V_523 ) {
if ( ( V_430 -= 4 ) < 0 )
goto V_519;
V_101 = F_118 ( V_414 . V_462 ) ;
if ( V_101 == V_471 ) {
V_40 = V_524 ;
goto V_149;
}
F_99 ( V_101 ) ;
}
if ( V_473 & V_525 ) {
if ( ( V_430 -= 4 ) < 0 )
goto V_519;
if ( exp -> V_526 & V_527 )
F_99 ( V_528 ) ;
else
F_99 ( V_528 | V_529 ) ;
}
if ( V_473 & V_530 ) {
if ( ( V_430 -= 8 ) < 0 )
goto V_519;
F_95 ( & V_8 , & V_414 , V_442 -> V_518 ) ;
}
if ( V_473 & V_41 ) {
if ( ( V_430 -= 8 ) < 0 )
goto V_519;
F_139 ( V_414 . V_531 ) ;
}
if ( V_473 & V_532 ) {
if ( ( V_430 -= 4 ) < 0 )
goto V_519;
F_99 ( 1 ) ;
}
if ( V_473 & V_533 ) {
if ( ( V_430 -= 4 ) < 0 )
goto V_519;
F_99 ( 1 ) ;
}
if ( V_473 & V_534 ) {
if ( ( V_430 -= 4 ) < 0 )
goto V_519;
F_99 ( 0 ) ;
}
if ( V_473 & V_512 ) {
if ( ( V_430 -= 16 ) < 0 )
goto V_519;
if ( exp -> V_459 . V_503 ) {
F_139 ( V_535 ) ;
F_139 ( V_536 ) ;
} else switch( F_140 ( V_483 ) ) {
case V_537 :
F_139 ( ( T_7 ) exp -> V_538 ) ;
F_139 ( ( T_7 ) 0 ) ;
break;
case V_539 :
F_99 ( 0 ) ;
F_99 ( F_141 ( V_414 . V_540 ) ) ;
F_99 ( 0 ) ;
F_99 ( F_142 ( V_414 . V_540 ) ) ;
break;
case V_541 :
F_100 ( exp -> V_542 , 16 ) ;
break;
}
}
if ( V_473 & V_543 ) {
if ( ( V_430 -= 4 ) < 0 )
goto V_519;
F_99 ( 0 ) ;
}
if ( V_473 & V_544 ) {
if ( ( V_430 -= 4 ) < 0 )
goto V_519;
F_99 ( V_500 -> V_545 ) ;
}
if ( V_473 & V_478 ) {
if ( ( V_430 -= 4 ) < 0 )
goto V_519;
F_99 ( V_475 ) ;
}
if ( V_473 & V_44 ) {
struct V_46 * V_47 ;
if ( V_34 == NULL ) {
if ( ( V_430 -= 4 ) < 0 )
goto V_519;
F_99 ( 0 ) ;
goto V_546;
}
if ( ( V_430 -= 4 ) < 0 )
goto V_519;
F_99 ( V_34 -> V_51 ) ;
for ( V_47 = V_34 -> V_52 ; V_47 < V_34 -> V_52 + V_34 -> V_51 ; V_47 ++ ) {
if ( ( V_430 -= 4 * 3 ) < 0 )
goto V_519;
F_99 ( V_47 -> type ) ;
F_99 ( V_47 -> V_53 ) ;
F_99 ( V_47 -> V_54 & V_547 ) ;
V_40 = F_119 ( V_59 , V_47 , & V_8 , & V_430 ) ;
if ( V_40 )
goto V_149;
}
}
V_546:
if ( V_473 & V_513 ) {
if ( ( V_430 -= 4 ) < 0 )
goto V_519;
F_99 ( V_492 ?
V_548 | V_549 : 0 ) ;
}
if ( V_473 & V_550 ) {
if ( ( V_430 -= 4 ) < 0 )
goto V_519;
F_99 ( 1 ) ;
}
if ( V_473 & V_551 ) {
if ( ( V_430 -= 4 ) < 0 )
goto V_519;
F_99 ( 0 ) ;
}
if ( V_473 & V_552 ) {
if ( ( V_430 -= 4 ) < 0 )
goto V_519;
F_99 ( 1 ) ;
}
if ( V_473 & V_553 ) {
if ( ( V_430 -= 4 ) < 0 )
goto V_519;
F_99 ( 1 ) ;
}
if ( V_473 & V_511 ) {
V_430 -= ( F_8 ( V_483 -> V_554 . V_555 ) << 2 ) + 4 ;
if ( V_430 < 0 )
goto V_519;
F_99 ( V_483 -> V_554 . V_555 ) ;
F_100 ( & V_483 -> V_554 . V_556 , V_483 -> V_554 . V_555 ) ;
}
if ( V_473 & V_557 ) {
if ( ( V_430 -= 8 ) < 0 )
goto V_519;
F_139 ( V_414 . V_558 ) ;
}
if ( V_473 & V_559 ) {
if ( ( V_430 -= 8 ) < 0 )
goto V_519;
F_139 ( ( T_7 ) V_489 . V_560 ) ;
}
if ( V_473 & V_505 ) {
if ( ( V_430 -= 8 ) < 0 )
goto V_519;
F_139 ( ( T_7 ) V_489 . V_560 ) ;
}
if ( V_473 & V_506 ) {
if ( ( V_430 -= 8 ) < 0 )
goto V_519;
F_139 ( ( T_7 ) V_489 . V_561 ) ;
}
if ( V_473 & V_479 ) {
V_40 = F_117 ( V_59 , exp , & V_8 , & V_430 ) ;
if ( V_40 )
goto V_149;
}
if ( V_473 & V_562 ) {
if ( ( V_430 -= 4 ) < 0 )
goto V_519;
F_99 ( 1 ) ;
}
if ( V_473 & V_563 ) {
if ( ( V_430 -= 8 ) < 0 )
goto V_519;
F_139 ( exp -> V_456 . V_445 -> V_564 -> V_565 ) ;
}
if ( V_473 & V_566 ) {
if ( ( V_430 -= 4 ) < 0 )
goto V_519;
F_99 ( 255 ) ;
}
if ( V_473 & V_507 ) {
if ( ( V_430 -= 4 ) < 0 )
goto V_519;
F_99 ( V_489 . V_567 ) ;
}
if ( V_473 & V_568 ) {
if ( ( V_430 -= 8 ) < 0 )
goto V_519;
F_139 ( ( T_7 ) F_143 ( V_59 ) ) ;
}
if ( V_473 & V_569 ) {
if ( ( V_430 -= 8 ) < 0 )
goto V_519;
F_139 ( ( T_7 ) F_143 ( V_59 ) ) ;
}
if ( V_474 & V_62 ) {
if ( ( V_430 -= 4 ) < 0 )
goto V_519;
F_99 ( V_414 . V_462 & V_65 ) ;
}
if ( V_474 & V_570 ) {
if ( ( V_430 -= 4 ) < 0 )
goto V_519;
F_99 ( 1 ) ;
}
if ( V_474 & V_571 ) {
if ( ( V_430 -= 4 ) < 0 )
goto V_519;
F_99 ( V_414 . V_572 ) ;
}
if ( V_474 & V_67 ) {
V_40 = F_122 ( V_59 , V_414 . V_102 , & V_8 , & V_430 ) ;
if ( V_40 )
goto V_149;
}
if ( V_474 & V_70 ) {
V_40 = F_121 ( V_59 , V_414 . V_103 , & V_8 , & V_430 ) ;
if ( V_40 )
goto V_149;
}
if ( V_474 & V_573 ) {
if ( ( V_430 -= 8 ) < 0 )
goto V_519;
F_99 ( ( T_2 ) F_141 ( V_414 . V_574 ) ) ;
F_99 ( ( T_2 ) F_142 ( V_414 . V_574 ) ) ;
}
if ( V_474 & V_508 ) {
if ( ( V_430 -= 8 ) < 0 )
goto V_519;
V_491 = ( T_7 ) V_489 . V_575 * ( T_7 ) V_489 . V_576 ;
F_139 ( V_491 ) ;
}
if ( V_474 & V_509 ) {
if ( ( V_430 -= 8 ) < 0 )
goto V_519;
V_491 = ( T_7 ) V_489 . V_577 * ( T_7 ) V_489 . V_576 ;
F_139 ( V_491 ) ;
}
if ( V_474 & V_510 ) {
if ( ( V_430 -= 8 ) < 0 )
goto V_519;
V_491 = ( T_7 ) V_489 . V_578 * ( T_7 ) V_489 . V_576 ;
F_139 ( V_491 ) ;
}
if ( V_474 & V_579 ) {
if ( ( V_430 -= 8 ) < 0 )
goto V_519;
V_491 = ( T_7 ) V_414 . V_580 << 9 ;
F_139 ( V_491 ) ;
}
if ( V_474 & V_581 ) {
if ( ( V_430 -= 12 ) < 0 )
goto V_519;
F_139 ( ( V_582 ) V_414 . V_583 . V_76 ) ;
F_99 ( V_414 . V_583 . V_77 ) ;
}
if ( V_474 & V_584 ) {
if ( ( V_430 -= 12 ) < 0 )
goto V_519;
F_99 ( 0 ) ;
F_99 ( 1 ) ;
F_99 ( 0 ) ;
}
if ( V_474 & V_585 ) {
if ( ( V_430 -= 12 ) < 0 )
goto V_519;
F_139 ( ( V_582 ) V_414 . ctime . V_76 ) ;
F_99 ( V_414 . ctime . V_77 ) ;
}
if ( V_474 & V_586 ) {
if ( ( V_430 -= 12 ) < 0 )
goto V_519;
F_139 ( ( V_582 ) V_414 . V_587 . V_76 ) ;
F_99 ( V_414 . V_587 . V_77 ) ;
}
if ( V_474 & V_588 ) {
if ( ( V_430 -= 8 ) < 0 )
goto V_519;
if ( V_485 == 0 &&
V_442 == exp -> V_456 . V_445 -> V_446 )
F_126 ( exp , & V_414 ) ;
F_139 ( V_414 . V_558 ) ;
}
if ( V_486 & V_85 ) {
V_40 = F_123 ( V_59 , V_472 ,
V_493 , & V_8 , & V_430 ) ;
if ( V_40 )
goto V_149;
}
if ( V_486 & V_589 ) {
F_99 ( 3 ) ;
F_99 ( V_590 ) ;
F_99 ( V_591 ) ;
F_99 ( V_592 ) ;
}
* V_490 = F_93 ( ( char * ) V_8 - ( char * ) V_490 - 4 ) ;
* V_484 = V_8 ;
V_40 = V_56 ;
V_149:
#ifdef F_25
if ( V_472 )
F_144 ( V_472 , V_493 ) ;
#endif
F_6 ( V_34 ) ;
if ( V_487 )
F_145 ( V_487 ) ;
return V_40 ;
V_504:
V_40 = F_79 ( V_444 ) ;
goto V_149;
V_519:
V_40 = V_49 ;
goto V_149;
}
static inline int F_146 ( T_2 * V_27 )
{
if ( V_27 [ 0 ] & ~ ( V_478 | V_544 ) )
return 1 ;
if ( V_27 [ 1 ] & ~ V_588 )
return 1 ;
return 0 ;
}
static T_1
F_147 ( struct V_275 * V_593 ,
const char * V_451 , int V_594 , T_1 * * V_8 , int V_430 )
{
struct V_453 * exp = V_593 -> V_595 -> V_596 ;
struct V_442 * V_442 ;
T_1 V_597 ;
int V_485 = 0 ;
V_442 = F_148 ( V_451 , V_593 -> V_595 -> V_598 , V_594 ) ;
if ( F_114 ( V_442 ) )
return F_79 ( F_115 ( V_442 ) ) ;
if ( ! V_442 -> V_518 ) {
F_110 ( V_442 ) ;
return V_599 ;
}
F_149 ( exp ) ;
if ( F_150 ( V_442 , exp ) ) {
int V_444 ;
if ( ! ( exp -> V_526 & V_600 )
&& ! F_146 ( V_593 -> V_281 ) ) {
V_485 = 1 ;
goto V_601;
}
V_444 = F_151 ( V_593 -> V_602 , & V_442 , & exp ) ;
if ( V_444 ) {
V_597 = F_79 ( V_444 ) ;
goto V_603;
}
V_597 = F_152 ( exp , V_593 -> V_602 ) ;
if ( V_597 )
goto V_603;
}
V_601:
V_597 = F_128 ( NULL , exp , V_442 , V_8 , V_430 , V_593 -> V_281 ,
V_593 -> V_602 , V_485 ) ;
V_603:
F_110 ( V_442 ) ;
F_116 ( exp ) ;
return V_597 ;
}
static T_1 *
F_153 ( T_1 * V_8 , int V_430 , T_1 V_597 )
{
if ( V_430 < 6 )
return NULL ;
* V_8 ++ = F_93 ( 2 ) ;
* V_8 ++ = F_93 ( V_478 ) ;
* V_8 ++ = F_93 ( 0 ) ;
* V_8 ++ = F_93 ( 4 ) ;
* V_8 ++ = V_597 ;
return V_8 ;
}
static int
F_154 ( void * V_604 , const char * V_451 , int V_594 ,
T_9 V_605 , T_7 V_558 , unsigned int V_606 )
{
struct V_607 * V_608 = V_604 ;
struct V_275 * V_593 = F_155 ( V_608 , struct V_275 , V_609 ) ;
int V_430 ;
T_1 * V_8 = V_593 -> V_484 ;
T_1 * V_610 ;
T_1 V_597 = V_611 ;
if ( V_451 && F_2 ( V_451 , V_594 ) ) {
V_593 -> V_609 . V_444 = V_56 ;
return 0 ;
}
if ( V_593 -> V_605 )
F_156 ( V_593 -> V_605 , ( T_7 ) V_605 ) ;
V_430 = V_593 -> V_430 - 4 - F_8 ( V_594 ) ;
if ( V_430 < 0 )
goto V_612;
* V_8 ++ = V_613 ;
V_610 = V_8 ;
V_8 = F_156 ( V_8 , V_614 ) ;
V_8 = F_157 ( V_8 , V_451 , V_594 ) ;
V_597 = F_147 ( V_593 , V_451 , V_594 , & V_8 , V_430 ) ;
switch ( V_597 ) {
case V_56 :
break;
case V_49 :
V_597 = V_611 ;
goto V_612;
case V_599 :
goto V_615;
default:
if ( ! ( V_593 -> V_281 [ 0 ] & V_478 ) )
goto V_612;
V_8 = F_153 ( V_8 , V_430 , V_597 ) ;
if ( V_8 == NULL ) {
V_597 = V_611 ;
goto V_612;
}
}
V_593 -> V_430 -= ( V_8 - V_593 -> V_484 ) ;
V_593 -> V_484 = V_8 ;
V_593 -> V_605 = V_610 ;
V_615:
V_593 -> V_609 . V_444 = V_56 ;
return 0 ;
V_612:
V_593 -> V_609 . V_444 = V_597 ;
return - V_516 ;
}
static void
F_158 ( struct V_495 * V_496 , T_4 * V_92 )
{
T_1 * V_8 ;
F_159 ( sizeof( T_4 ) ) ;
F_99 ( V_92 -> V_93 ) ;
F_100 ( & V_92 -> V_94 , sizeof( V_95 ) ) ;
F_160 () ;
}
static T_1
F_161 ( struct V_495 * V_496 , T_1 V_597 , struct V_96 * V_97 )
{
T_1 * V_8 ;
if ( ! V_597 ) {
F_159 ( 8 ) ;
F_99 ( V_97 -> V_616 ) ;
F_99 ( V_97 -> V_617 ) ;
F_160 () ;
}
return V_597 ;
}
static T_1 F_162 ( struct V_495 * V_496 , T_1 V_597 , struct V_117 * V_118 )
{
T_1 * V_8 ;
if ( ! V_597 ) {
F_159 ( V_119 + 8 ) ;
F_100 ( V_118 -> V_120 . V_88 , V_119 ) ;
F_99 ( V_118 -> V_121 ) ;
F_99 ( 0 ) ;
F_160 () ;
}
return V_597 ;
}
static T_1
F_163 ( struct V_495 * V_496 , T_1 V_597 , struct V_122 * V_123 )
{
if ( ! V_597 )
F_158 ( V_496 , & V_123 -> V_125 ) ;
return V_597 ;
}
static T_1
F_164 ( struct V_495 * V_496 , T_1 V_597 , struct V_126 * V_127 )
{
T_1 * V_8 ;
if ( ! V_597 ) {
F_159 ( V_239 ) ;
F_100 ( V_127 -> V_618 . V_88 , V_239 ) ;
F_160 () ;
}
return V_597 ;
}
static T_1
F_165 ( struct V_495 * V_496 , T_1 V_597 , struct V_130 * V_131 )
{
T_1 * V_8 ;
if ( ! V_597 ) {
F_159 ( 32 ) ;
F_97 ( & V_8 , & V_131 -> V_619 ) ;
F_99 ( 2 ) ;
F_99 ( V_131 -> V_145 [ 0 ] ) ;
F_99 ( V_131 -> V_145 [ 1 ] ) ;
F_160 () ;
}
return V_597 ;
}
static T_1
F_166 ( struct V_495 * V_496 , T_1 V_597 , struct V_153 * V_154 )
{
struct V_482 * V_483 = V_154 -> V_620 ;
int V_430 ;
if ( V_597 )
return V_597 ;
V_430 = V_496 -> V_12 - V_496 -> V_8 - ( V_621 >> 2 ) ;
V_597 = F_128 ( V_483 , V_483 -> V_596 , V_483 -> V_598 ,
& V_496 -> V_8 , V_430 , V_154 -> V_155 ,
V_496 -> V_59 , 0 ) ;
return V_597 ;
}
static T_1
F_167 ( struct V_495 * V_496 , T_1 V_597 , struct V_482 * * V_622 )
{
struct V_482 * V_483 = * V_622 ;
unsigned int V_2 ;
T_1 * V_8 ;
if ( ! V_597 ) {
V_2 = V_483 -> V_554 . V_555 ;
F_159 ( V_2 + 4 ) ;
F_99 ( V_2 ) ;
F_100 ( & V_483 -> V_554 . V_556 , V_2 ) ;
F_160 () ;
}
return V_597 ;
}
static void
F_168 ( struct V_495 * V_496 , struct V_623 * V_624 )
{
struct V_35 * V_625 = & V_624 -> V_626 ;
T_1 * V_8 ;
F_159 ( 32 + F_169 ( V_625 -> V_2 ) ) ;
F_139 ( V_624 -> V_627 ) ;
F_139 ( V_624 -> V_628 ) ;
F_99 ( V_624 -> V_629 ) ;
if ( V_625 -> V_2 ) {
F_100 ( & V_624 -> V_630 , 8 ) ;
F_99 ( V_625 -> V_2 ) ;
F_100 ( V_625 -> V_88 , V_625 -> V_2 ) ;
F_6 ( V_625 -> V_88 ) ;
} else {
F_139 ( ( T_7 ) 0 ) ;
F_99 ( 0 ) ;
}
F_160 () ;
}
static T_1
F_170 ( struct V_495 * V_496 , T_1 V_597 , struct V_160 * V_161 )
{
if ( ! V_597 )
F_158 ( V_496 , & V_161 -> V_631 ) ;
else if ( V_597 == V_632 )
F_168 ( V_496 , & V_161 -> V_633 ) ;
return V_597 ;
}
static T_1
F_171 ( struct V_495 * V_496 , T_1 V_597 , struct V_176 * V_177 )
{
if ( V_597 == V_632 )
F_168 ( V_496 , & V_177 -> V_634 ) ;
return V_597 ;
}
static T_1
F_172 ( struct V_495 * V_496 , T_1 V_597 , struct V_183 * V_184 )
{
if ( ! V_597 )
F_158 ( V_496 , & V_184 -> V_187 ) ;
return V_597 ;
}
static T_1
F_173 ( struct V_495 * V_496 , T_1 V_597 , struct V_156 * V_157 )
{
T_1 * V_8 ;
if ( ! V_597 ) {
F_159 ( 20 ) ;
F_97 ( & V_8 , & V_157 -> V_635 ) ;
F_160 () ;
}
return V_597 ;
}
static T_1
F_174 ( struct V_495 * V_496 , T_1 V_597 , struct V_218 * V_219 )
{
T_1 * V_8 ;
if ( V_597 )
goto V_149;
F_158 ( V_496 , & V_219 -> V_636 ) ;
F_159 ( 40 ) ;
F_97 ( & V_8 , & V_219 -> V_637 ) ;
F_99 ( V_219 -> V_638 ) ;
F_99 ( 2 ) ;
F_99 ( V_219 -> V_220 [ 0 ] ) ;
F_99 ( V_219 -> V_220 [ 1 ] ) ;
F_99 ( V_219 -> V_247 ) ;
F_160 () ;
switch ( V_219 -> V_247 ) {
case V_639 :
break;
case V_640 :
F_158 ( V_496 , & V_219 -> V_249 ) ;
F_159 ( 20 ) ;
F_99 ( V_219 -> V_641 ) ;
F_99 ( V_642 ) ;
F_99 ( 0 ) ;
F_99 ( 0 ) ;
F_99 ( 0 ) ;
F_160 () ;
break;
case V_643 :
F_158 ( V_496 , & V_219 -> V_249 ) ;
F_159 ( 32 ) ;
F_99 ( 0 ) ;
F_99 ( V_644 ) ;
F_99 ( ~ ( T_2 ) 0 ) ;
F_99 ( ~ ( T_2 ) 0 ) ;
F_99 ( V_642 ) ;
F_99 ( 0 ) ;
F_99 ( 0 ) ;
F_99 ( 0 ) ;
F_160 () ;
break;
case V_645 :
switch ( V_219 -> V_646 ) {
case V_647 :
case V_648 :
F_159 ( 8 ) ;
F_99 ( V_219 -> V_646 ) ;
F_99 ( 0 ) ;
break;
default:
F_159 ( 4 ) ;
F_99 ( V_219 -> V_646 ) ;
}
F_160 () ;
break;
default:
F_175 () ;
}
V_149:
return V_597 ;
}
static T_1
F_176 ( struct V_495 * V_496 , T_1 V_597 , struct V_253 * V_649 )
{
if ( ! V_597 )
F_158 ( V_496 , & V_649 -> V_650 ) ;
return V_597 ;
}
static T_1
F_177 ( struct V_495 * V_496 , T_1 V_597 , struct V_258 * V_651 )
{
if ( ! V_597 )
F_158 ( V_496 , & V_651 -> V_260 ) ;
return V_597 ;
}
static T_1
F_178 ( struct V_495 * V_496 , T_1 V_597 ,
struct V_270 * V_271 )
{
T_2 V_652 ;
int V_653 ;
struct V_654 * V_654 ;
unsigned long V_655 ;
long V_2 ;
T_1 * V_8 ;
if ( V_597 )
return V_597 ;
if ( V_496 -> V_656 -> V_657 )
return V_49 ;
F_159 ( 8 ) ;
V_655 = F_143 ( V_496 -> V_59 ) ;
if ( V_655 > V_271 -> V_274 )
V_655 = V_271 -> V_274 ;
V_2 = V_655 ;
V_653 = 0 ;
while ( V_2 > 0 ) {
V_654 = * ( V_496 -> V_59 -> V_658 ) ;
if ( ! V_654 ) {
V_655 -= V_2 ;
break;
}
V_496 -> V_59 -> V_659 [ V_653 ] . V_330 = F_4 ( V_654 ) ;
V_496 -> V_59 -> V_659 [ V_653 ] . V_331 =
V_2 < V_11 ? V_2 : V_11 ;
V_496 -> V_59 -> V_658 ++ ;
V_653 ++ ;
V_2 -= V_11 ;
}
V_271 -> V_660 = V_653 ;
V_597 = F_179 ( V_271 -> V_602 , V_271 -> V_595 , V_271 -> V_661 ,
V_271 -> V_273 , V_496 -> V_59 -> V_659 , V_271 -> V_660 ,
& V_655 ) ;
if ( V_597 )
return V_597 ;
V_652 = ( V_271 -> V_273 + V_655 >=
V_271 -> V_595 -> V_598 -> V_518 -> V_662 ) ;
F_99 ( V_652 ) ;
F_99 ( V_655 ) ;
F_160 () ;
V_496 -> V_656 -> V_663 [ 0 ] . V_331 = ( char * ) V_8
- ( char * ) V_496 -> V_656 -> V_663 [ 0 ] . V_330 ;
V_496 -> V_656 -> V_657 = V_655 ;
V_496 -> V_656 -> V_664 [ 0 ] . V_330 = V_8 ;
V_496 -> V_656 -> V_664 [ 0 ] . V_331 = 0 ;
if ( V_655 & 3 ) {
F_159 ( 4 ) ;
F_99 ( 0 ) ;
V_496 -> V_656 -> V_664 [ 0 ] . V_330 += V_655 & 3 ;
V_496 -> V_656 -> V_664 [ 0 ] . V_331 = 4 - ( V_655 & 3 ) ;
F_160 () ;
}
return 0 ;
}
static T_1
F_180 ( struct V_495 * V_496 , T_1 V_597 , struct V_665 * V_666 )
{
int V_655 ;
char * V_654 ;
T_1 * V_8 ;
if ( V_597 )
return V_597 ;
if ( V_496 -> V_656 -> V_657 )
return V_49 ;
if ( ! * V_496 -> V_59 -> V_658 )
return V_49 ;
V_654 = F_4 ( * ( V_496 -> V_59 -> V_658 ++ ) ) ;
V_655 = V_11 ;
F_159 ( 4 ) ;
V_597 = F_181 ( V_666 -> V_667 , V_666 -> V_668 , V_654 , & V_655 ) ;
if ( V_597 == V_669 )
return V_4 ;
if ( V_597 )
return V_597 ;
F_99 ( V_655 ) ;
F_160 () ;
V_496 -> V_656 -> V_663 [ 0 ] . V_331 = ( char * ) V_8
- ( char * ) V_496 -> V_656 -> V_663 [ 0 ] . V_330 ;
V_496 -> V_656 -> V_657 = V_655 ;
V_496 -> V_656 -> V_664 [ 0 ] . V_330 = V_8 ;
V_496 -> V_656 -> V_664 [ 0 ] . V_331 = 0 ;
if ( V_655 & 3 ) {
F_159 ( 4 ) ;
F_99 ( 0 ) ;
V_496 -> V_656 -> V_664 [ 0 ] . V_330 += V_655 & 3 ;
V_496 -> V_656 -> V_664 [ 0 ] . V_331 = 4 - ( V_655 & 3 ) ;
F_160 () ;
}
return 0 ;
}
static T_1
F_182 ( struct V_495 * V_496 , T_1 V_597 , struct V_275 * V_276 )
{
int V_655 ;
T_9 V_605 ;
T_1 * V_654 , * V_670 , * V_671 ;
T_1 * V_8 ;
if ( V_597 )
return V_597 ;
if ( V_496 -> V_656 -> V_657 )
return V_49 ;
if ( ! * V_496 -> V_59 -> V_658 )
return V_49 ;
F_159 ( V_239 ) ;
V_670 = V_8 ;
F_99 ( 0 ) ;
F_99 ( 0 ) ;
F_160 () ;
V_496 -> V_656 -> V_663 [ 0 ] . V_331 = ( ( char * ) V_496 -> V_8 ) - ( char * ) V_496 -> V_656 -> V_663 [ 0 ] . V_330 ;
V_671 = V_8 ;
V_655 = V_11 ;
if ( V_655 > V_276 -> V_280 )
V_655 = V_276 -> V_280 ;
V_655 = ( V_655 >> 2 ) - 4 ;
if ( V_655 < 0 ) {
V_597 = V_611 ;
goto V_672;
}
V_654 = F_4 ( * ( V_496 -> V_59 -> V_658 ++ ) ) ;
V_276 -> V_609 . V_444 = 0 ;
V_276 -> V_430 = V_655 ;
V_276 -> V_484 = V_654 ;
V_276 -> V_605 = NULL ;
V_605 = V_276 -> V_277 ;
V_597 = F_183 ( V_276 -> V_602 , V_276 -> V_595 ,
& V_605 ,
& V_276 -> V_609 , F_154 ) ;
if ( V_597 == V_56 &&
V_276 -> V_609 . V_444 == V_611 &&
V_276 -> V_484 == V_654 )
V_597 = V_611 ;
if ( V_597 )
goto V_672;
if ( V_276 -> V_605 )
F_156 ( V_276 -> V_605 , V_605 ) ;
V_8 = V_276 -> V_484 ;
* V_8 ++ = 0 ;
* V_8 ++ = F_93 ( V_276 -> V_609 . V_444 == V_673 ) ;
V_496 -> V_656 -> V_657 = ( ( char * ) V_8 ) -
( char * ) F_4 ( * ( V_496 -> V_59 -> V_658 - 1 ) ) ;
V_496 -> V_656 -> V_664 [ 0 ] . V_330 = V_671 ;
V_496 -> V_656 -> V_664 [ 0 ] . V_331 = 0 ;
V_496 -> V_8 = V_496 -> V_656 -> V_664 [ 0 ] . V_330 ;
V_496 -> V_12 = V_496 -> V_8 + ( V_11 - V_496 -> V_656 -> V_663 [ 0 ] . V_331 ) / 4 ;
return 0 ;
V_672:
V_8 = V_670 ;
F_160 () ;
return V_597 ;
}
static T_1
F_184 ( struct V_495 * V_496 , T_1 V_597 , struct V_282 * remove )
{
T_1 * V_8 ;
if ( ! V_597 ) {
F_159 ( 20 ) ;
F_97 ( & V_8 , & remove -> V_674 ) ;
F_160 () ;
}
return V_597 ;
}
static T_1
F_185 ( struct V_495 * V_496 , T_1 V_597 , struct V_285 * rename )
{
T_1 * V_8 ;
if ( ! V_597 ) {
F_159 ( 40 ) ;
F_97 ( & V_8 , & rename -> V_675 ) ;
F_97 ( & V_8 , & rename -> V_676 ) ;
F_160 () ;
}
return V_597 ;
}
static T_1
F_186 ( struct V_495 * V_496 ,
T_1 V_597 , struct V_453 * exp )
{
T_2 V_3 , V_677 , V_678 ;
struct V_679 * V_680 ;
struct V_679 V_681 [ 2 ] ;
T_1 * V_8 , * V_682 ;
static bool V_683 = true ;
if ( V_597 )
goto V_149;
if ( exp -> V_684 ) {
V_680 = exp -> V_685 ;
V_677 = exp -> V_684 ;
} else {
V_680 = V_681 ;
if ( exp -> V_686 -> V_687 -> V_687 == V_108 ) {
V_677 = 2 ;
V_680 [ 0 ] . V_688 = V_108 ;
V_680 [ 1 ] . V_688 = V_107 ;
} else if ( exp -> V_686 -> V_687 -> V_687 == V_112 ) {
V_677 = 1 ;
V_680 [ 0 ] . V_688
= F_187 ( exp -> V_686 ) ;
} else {
V_677 = 1 ;
V_680 [ 0 ] . V_688
= exp -> V_686 -> V_687 -> V_687 ;
}
}
V_678 = 0 ;
F_159 ( 4 ) ;
V_682 = V_8 ++ ;
F_160 () ;
for ( V_3 = 0 ; V_3 < V_677 ; V_3 ++ ) {
T_10 V_689 = V_680 [ V_3 ] . V_688 ;
struct V_690 V_691 ;
if ( F_188 ( V_689 , & V_691 ) == 0 ) {
V_678 ++ ;
F_159 ( 4 + 4 + F_169 ( V_691 . V_692 . V_2 ) + 4 + 4 ) ;
F_99 ( V_112 ) ;
F_99 ( V_691 . V_692 . V_2 ) ;
F_100 ( V_691 . V_692 . V_88 , V_691 . V_692 . V_2 ) ;
F_99 ( V_691 . V_693 ) ;
F_99 ( V_691 . V_694 ) ;
F_160 () ;
} else if ( V_689 < V_695 ) {
V_678 ++ ;
F_159 ( 4 ) ;
F_99 ( V_689 ) ;
F_160 () ;
} else {
if ( V_683 )
F_189 ( L_14
L_15 , V_689 ) ;
}
}
if ( V_677 != V_678 )
V_683 = false ;
* V_682 = F_93 ( V_678 ) ;
V_149:
if ( exp )
F_116 ( exp ) ;
return V_597 ;
}
static T_1
F_190 ( struct V_495 * V_496 , T_1 V_597 ,
struct V_291 * V_292 )
{
return F_186 ( V_496 , V_597 , V_292 -> V_696 ) ;
}
static T_1
F_191 ( struct V_495 * V_496 , T_1 V_597 ,
struct V_295 * V_292 )
{
return F_186 ( V_496 , V_597 , V_292 -> V_697 ) ;
}
static T_1
F_192 ( struct V_495 * V_496 , T_1 V_597 , struct V_297 * V_298 )
{
T_1 * V_8 ;
F_159 ( 16 ) ;
if ( V_597 ) {
F_99 ( 3 ) ;
F_99 ( 0 ) ;
F_99 ( 0 ) ;
F_99 ( 0 ) ;
}
else {
F_99 ( 3 ) ;
F_99 ( V_298 -> V_300 [ 0 ] ) ;
F_99 ( V_298 -> V_300 [ 1 ] ) ;
F_99 ( V_298 -> V_300 [ 2 ] ) ;
}
F_160 () ;
return V_597 ;
}
static T_1
F_193 ( struct V_495 * V_496 , T_1 V_597 , struct V_304 * V_698 )
{
T_1 * V_8 ;
if ( ! V_597 ) {
F_159 ( 8 + V_239 ) ;
F_100 ( & V_698 -> V_699 , 8 ) ;
F_100 ( & V_698 -> V_700 , V_239 ) ;
F_160 () ;
}
else if ( V_597 == V_701 ) {
F_159 ( 8 ) ;
F_99 ( 0 ) ;
F_99 ( 0 ) ;
F_160 () ;
}
return V_597 ;
}
static T_1
F_194 ( struct V_495 * V_496 , T_1 V_597 , struct V_323 * V_324 )
{
T_1 * V_8 ;
if ( ! V_597 ) {
F_159 ( 16 ) ;
F_99 ( V_324 -> V_702 ) ;
F_99 ( V_324 -> V_703 ) ;
F_100 ( V_324 -> V_704 . V_88 , V_239 ) ;
F_160 () ;
}
return V_597 ;
}
static T_1
F_195 ( struct V_495 * V_496 , T_1 V_597 ,
struct V_339 * V_340 )
{
T_1 * V_8 ;
char * V_705 ;
char * V_706 ;
int V_707 ;
int V_708 ;
T_11 V_709 = 0 ;
if ( V_597 )
return V_597 ;
V_705 = F_196 () -> V_710 ;
V_707 = strlen ( V_705 ) ;
V_706 = F_196 () -> V_710 ;
V_708 = strlen ( V_706 ) ;
F_159 (
8 +
4 +
4 +
4 ) ;
F_100 ( & V_340 -> V_290 , 8 ) ;
F_99 ( V_340 -> V_350 ) ;
F_99 ( V_340 -> V_343 ) ;
F_99 ( V_340 -> V_344 ) ;
F_160 () ;
switch ( V_340 -> V_344 ) {
case V_345 :
break;
case V_346 :
F_159 ( 16 ) ;
F_99 ( 2 ) ;
F_99 ( V_711 [ 0 ] ) ;
F_99 ( V_711 [ 1 ] ) ;
F_99 ( 0 ) ;
F_160 () ;
break;
default:
F_197 ( 1 ) ;
}
F_159 (
8 +
4 +
( F_8 ( V_707 ) * 4 ) +
4 +
( F_8 ( V_708 ) * 4 ) +
4 ) ;
F_139 ( V_709 ) ;
F_99 ( V_707 ) ;
F_100 ( V_705 , V_707 ) ;
F_99 ( V_708 ) ;
F_100 ( V_706 , V_708 ) ;
F_99 ( 0 ) ;
F_160 () ;
return 0 ;
}
static T_1
F_198 ( struct V_495 * V_496 , T_1 V_597 ,
struct V_348 * V_349 )
{
T_1 * V_8 ;
if ( V_597 )
return V_597 ;
F_159 ( 24 ) ;
F_100 ( V_349 -> V_120 . V_88 , V_119 ) ;
F_99 ( V_349 -> V_350 ) ;
F_99 ( V_349 -> V_343 ) ;
F_160 () ;
F_159 ( 28 ) ;
F_99 ( 0 ) ;
F_99 ( V_349 -> V_351 . V_352 ) ;
F_99 ( V_349 -> V_351 . V_353 ) ;
F_99 ( V_349 -> V_351 . V_354 ) ;
F_99 ( V_349 -> V_351 . V_355 ) ;
F_99 ( V_349 -> V_351 . V_356 ) ;
F_99 ( V_349 -> V_351 . V_357 ) ;
F_160 () ;
if ( V_349 -> V_351 . V_357 ) {
F_159 ( 4 ) ;
F_99 ( V_349 -> V_351 . V_358 ) ;
F_160 () ;
}
F_159 ( 28 ) ;
F_99 ( 0 ) ;
F_99 ( V_349 -> V_359 . V_352 ) ;
F_99 ( V_349 -> V_359 . V_353 ) ;
F_99 ( V_349 -> V_359 . V_354 ) ;
F_99 ( V_349 -> V_359 . V_355 ) ;
F_99 ( V_349 -> V_359 . V_356 ) ;
F_99 ( V_349 -> V_359 . V_357 ) ;
F_160 () ;
if ( V_349 -> V_359 . V_357 ) {
F_159 ( 4 ) ;
F_99 ( V_349 -> V_359 . V_358 ) ;
F_160 () ;
}
return 0 ;
}
static T_1
F_199 ( struct V_495 * V_496 , T_1 V_597 ,
struct V_367 * V_368 )
{
T_1 * V_8 ;
if ( V_597 )
return V_597 ;
F_159 ( V_119 + 20 ) ;
F_100 ( V_368 -> V_120 . V_88 , V_119 ) ;
F_99 ( V_368 -> V_350 ) ;
F_99 ( V_368 -> V_369 ) ;
F_99 ( V_368 -> V_370 - 1 ) ;
F_99 ( V_368 -> V_370 - 1 ) ;
F_99 ( V_368 -> V_712 ) ;
F_160 () ;
V_496 -> V_498 . V_713 = V_8 ;
return 0 ;
}
static T_1
F_200 ( struct V_495 * V_496 , T_1 V_597 ,
struct V_372 * V_373 )
{
struct V_374 * V_375 , * V_25 ;
T_1 * V_8 ;
F_159 ( 4 + ( 4 * V_373 -> V_376 ) ) ;
* V_8 ++ = F_93 ( V_373 -> V_376 ) ;
F_201 (stateid, next, &test_stateid->ts_stateid_list, ts_id_list) {
* V_8 ++ = V_375 -> V_714 ;
}
F_160 () ;
return V_597 ;
}
static T_1
F_202 ( struct V_495 * V_496 , T_1 V_597 , void * V_8 )
{
return V_597 ;
}
T_1 F_203 ( struct V_495 * V_496 , T_2 V_715 )
{
struct V_716 * V_717 = & V_496 -> V_59 -> V_718 ;
struct V_719 * V_720 = NULL ;
struct V_721 * V_722 = V_496 -> V_498 . V_722 ;
T_2 V_723 , V_724 = 0 ;
if ( ! F_204 ( & V_496 -> V_498 ) )
return 0 ;
V_720 = V_496 -> V_498 . V_720 ;
if ( V_720 == NULL )
return 0 ;
if ( V_717 -> V_657 == 0 ) {
V_723 = ( char * ) V_496 -> V_8 - ( char * ) V_717 -> V_663 [ 0 ] . V_330 + V_715 ;
} else {
if ( V_717 -> V_664 [ 0 ] . V_330 && V_717 -> V_664 [ 0 ] . V_331 > 0 )
V_724 = ( char * ) V_496 -> V_8 - ( char * ) V_717 -> V_664 [ 0 ] . V_330 ;
V_723 = V_717 -> V_663 [ 0 ] . V_331 + V_717 -> V_657 + V_724 + V_715 ;
}
F_36 ( L_16 , V_725 ,
V_723 , V_717 -> V_657 , V_724 , V_715 ) ;
if ( V_723 > V_720 -> V_726 . V_353 )
return V_727 ;
if ( ( V_722 -> V_728 & V_729 ) &&
V_723 > V_720 -> V_726 . V_354 )
return V_730 ;
return 0 ;
}
void
F_205 ( struct V_495 * V_496 , struct V_385 * V_386 )
{
struct V_731 * V_732 = V_496 -> V_498 . V_733 ;
T_1 * V_734 ;
T_1 * V_8 ;
F_159 ( 8 ) ;
F_99 ( V_386 -> V_387 ) ;
V_734 = V_8 ++ ;
F_160 () ;
if ( V_386 -> V_387 == V_407 )
goto V_40;
F_14 ( V_386 -> V_387 < 0 || V_386 -> V_387 >= F_88 ( V_735 ) ||
! V_735 [ V_386 -> V_387 ] ) ;
V_386 -> V_40 = V_735 [ V_386 -> V_387 ] ( V_496 , V_386 -> V_40 , & V_386 -> V_406 ) ;
if ( ! V_386 -> V_40 )
V_386 -> V_40 = F_203 ( V_496 , 0 ) ;
if ( V_732 ) {
V_732 -> V_736 . V_737 = V_386 -> V_40 ;
V_732 -> V_736 . V_738 = ( char * ) V_496 -> V_8 - ( char * ) ( V_734 + 1 ) ;
memcpy ( V_732 -> V_736 . V_739 , V_734 + 1 , V_732 -> V_736 . V_738 ) ;
}
V_40:
* V_734 = V_386 -> V_40 ;
}
void
F_206 ( struct V_495 * V_496 , struct V_385 * V_386 )
{
T_1 * V_8 ;
struct V_740 * V_741 = V_386 -> V_404 ;
F_14 ( ! V_741 ) ;
F_159 ( 8 ) ;
F_99 ( V_386 -> V_387 ) ;
* V_8 ++ = V_741 -> V_737 ;
F_160 () ;
F_159 ( V_741 -> V_738 ) ;
F_100 ( V_741 -> V_739 , V_741 -> V_738 ) ;
F_160 () ;
}
int
F_207 ( struct V_452 * V_59 , T_1 * V_8 , void * V_101 )
{
return F_208 ( V_59 , V_8 ) ;
}
int F_209 ( void * V_742 , T_1 * V_8 , void * V_496 )
{
struct V_452 * V_59 = V_742 ;
struct V_6 * args = V_59 -> V_743 ;
if ( args -> V_402 != args -> V_401 ) {
F_6 ( args -> V_402 ) ;
args -> V_402 = args -> V_401 ;
}
F_6 ( args -> V_16 ) ;
args -> V_16 = NULL ;
while ( args -> V_26 ) {
struct V_21 * V_22 = args -> V_26 ;
args -> V_26 = V_22 -> V_25 ;
V_22 -> F_11 ( V_22 -> V_24 ) ;
F_6 ( V_22 ) ;
}
return 1 ;
}
int
F_210 ( struct V_452 * V_59 , T_1 * V_8 , struct V_6 * args )
{
args -> V_8 = V_8 ;
args -> V_12 = V_59 -> V_744 . V_663 [ 0 ] . V_330 + V_59 -> V_744 . V_663 [ 0 ] . V_331 ;
args -> V_9 = V_59 -> V_744 . V_333 ;
args -> V_10 = V_59 -> V_744 . V_657 ;
args -> V_16 = NULL ;
args -> V_26 = NULL ;
args -> V_402 = args -> V_401 ;
args -> V_59 = V_59 ;
return ! F_87 ( args ) ;
}
int
F_211 ( struct V_452 * V_59 , T_1 * V_8 , struct V_495 * V_496 )
{
struct V_745 * V_746 = & V_496 -> V_498 ;
struct V_747 * V_748 ;
V_8 = V_496 -> V_749 ;
* V_8 ++ = F_93 ( V_496 -> V_397 ) ;
memcpy ( V_8 , V_496 -> V_398 , V_496 -> V_397 ) ;
V_8 += F_8 ( V_496 -> V_397 ) ;
* V_8 ++ = F_93 ( V_496 -> V_399 ) ;
if ( V_59 -> V_718 . V_657 )
V_748 = & V_59 -> V_718 . V_664 [ 0 ] ;
else
V_748 = & V_59 -> V_718 . V_663 [ 0 ] ;
V_748 -> V_331 = ( ( char * ) V_496 -> V_8 ) - ( char * ) V_748 -> V_330 ;
F_14 ( V_748 -> V_331 > V_11 ) ;
if ( F_204 ( V_746 ) ) {
struct V_499 * V_500 = F_129 ( F_130 ( V_59 ) , V_501 ) ;
struct V_750 * V_751 = V_746 -> V_720 -> V_752 ;
if ( V_746 -> V_40 != V_753 ) {
F_212 ( V_496 ) ;
V_746 -> V_722 -> V_728 &= ~ V_754 ;
}
F_108 ( & V_500 -> V_755 ) ;
F_213 ( V_746 -> V_720 ) ;
F_109 ( & V_500 -> V_755 ) ;
F_214 ( V_751 ) ;
}
return 1 ;
}
