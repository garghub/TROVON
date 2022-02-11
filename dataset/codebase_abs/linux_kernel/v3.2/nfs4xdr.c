static T_1
F_1 ( char * V_1 , int V_2 , T_1 V_3 )
{
int V_4 ;
if ( V_2 == 0 )
return V_5 ;
if ( F_2 ( V_1 , V_2 ) )
return V_3 ;
for ( V_4 = 0 ; V_4 < V_2 ; V_4 ++ )
if ( V_1 [ V_4 ] == '/' )
return V_3 ;
return 0 ;
}
static void F_3 ( struct V_6 * V_7 , struct V_8 * V_9 )
{
V_9 -> V_10 = V_7 -> V_10 ;
V_9 -> V_11 = V_7 -> V_11 ;
V_9 -> V_12 = V_7 -> V_12 ;
V_9 -> V_13 = V_7 -> V_13 ;
}
static void F_4 ( struct V_6 * V_7 , struct V_8 * V_9 )
{
V_7 -> V_10 = V_9 -> V_10 ;
V_7 -> V_11 = V_9 -> V_11 ;
V_7 -> V_12 = V_9 -> V_12 ;
V_7 -> V_13 = V_9 -> V_13 ;
}
static T_1 * F_5 ( struct V_6 * V_7 , T_2 V_14 )
{
unsigned int V_15 = ( char * ) V_7 -> V_11 - ( char * ) V_7 -> V_10 ;
T_1 * V_10 ;
if ( V_15 + V_7 -> V_12 < V_14 )
return NULL ;
if ( V_15 + V_16 < V_14 )
return NULL ;
if ( V_14 <= sizeof( V_7 -> V_17 ) )
V_10 = V_7 -> V_17 ;
else {
F_6 ( V_7 -> V_18 ) ;
V_10 = V_7 -> V_18 = F_7 ( V_14 , V_19 ) ;
if ( ! V_10 )
return NULL ;
}
memcpy ( V_10 , V_7 -> V_10 , V_15 ) ;
V_7 -> V_10 = F_8 ( V_7 -> V_13 [ 0 ] ) ;
V_7 -> V_13 ++ ;
if ( V_7 -> V_12 < V_16 ) {
V_7 -> V_11 = V_7 -> V_10 + ( V_7 -> V_12 >> 2 ) ;
V_7 -> V_12 = 0 ;
} else {
V_7 -> V_11 = V_7 -> V_10 + ( V_16 >> 2 ) ;
V_7 -> V_12 -= V_16 ;
}
memcpy ( ( ( char * ) V_10 ) + V_15 , V_7 -> V_10 , ( V_14 - V_15 ) ) ;
V_7 -> V_10 += F_9 ( V_14 - V_15 ) ;
return V_10 ;
}
static int F_10 ( T_3 * V_20 )
{
return ( V_20 -> V_21 == 0 ) && ( V_20 -> V_22 == 0 ) ;
}
static int
F_11 ( struct V_6 * V_7 ,
void (* F_12)( const void * ) , void * V_10 )
{
struct V_23 * V_24 ;
V_24 = F_7 ( sizeof( * V_24 ) , V_19 ) ;
if ( ! V_24 )
return - V_25 ;
V_24 -> V_26 = V_10 ;
V_24 -> F_12 = F_12 ;
V_24 -> V_27 = V_7 -> V_28 ;
V_7 -> V_28 = V_24 ;
return 0 ;
}
static char * F_13 ( struct V_6 * V_7 , T_1 * V_10 , int V_14 )
{
if ( V_10 == V_7 -> V_17 ) {
V_10 = F_7 ( V_14 , V_19 ) ;
if ( ! V_10 )
return NULL ;
memcpy ( V_10 , V_7 -> V_17 , V_14 ) ;
} else {
F_14 ( V_10 != V_7 -> V_18 ) ;
V_7 -> V_18 = NULL ;
}
if ( F_11 ( V_7 , F_6 , V_10 ) ) {
F_6 ( V_10 ) ;
return NULL ;
} else
return ( char * ) V_10 ;
}
static T_1
F_15 ( struct V_6 * V_7 , T_2 * V_29 )
{
T_2 V_30 ;
V_31 ;
V_29 [ 0 ] = 0 ;
V_29 [ 1 ] = 0 ;
V_29 [ 2 ] = 0 ;
F_16 ( 4 ) ;
F_17 ( V_30 ) ;
if ( V_30 > 1000 )
goto V_32;
F_16 ( V_30 << 2 ) ;
if ( V_30 > 0 )
F_17 ( V_29 [ 0 ] ) ;
if ( V_30 > 1 )
F_17 ( V_29 [ 1 ] ) ;
if ( V_30 > 2 )
F_17 ( V_29 [ 2 ] ) ;
V_33 ;
}
static T_1
F_18 ( struct V_6 * V_7 , T_2 * V_29 ,
struct V_34 * V_34 , struct V_35 * * V_36 )
{
int V_37 , V_2 = 0 ;
T_2 V_38 ;
char * V_26 ;
int V_39 ;
V_31 ;
V_34 -> V_40 = 0 ;
if ( ( V_41 = F_15 ( V_7 , V_29 ) ) )
return V_41 ;
F_16 ( 4 ) ;
F_17 ( V_37 ) ;
if ( V_29 [ 0 ] & V_42 ) {
F_16 ( 8 ) ;
V_2 += 8 ;
F_19 ( V_34 -> V_43 ) ;
V_34 -> V_40 |= V_44 ;
}
if ( V_29 [ 0 ] & V_45 ) {
int V_46 ;
struct V_47 * V_48 ;
F_16 ( 4 ) ; V_2 += 4 ;
F_17 ( V_46 ) ;
if ( V_46 > V_49 )
return V_50 ;
* V_36 = F_20 ( V_46 ) ;
if ( * V_36 == NULL ) {
V_39 = - V_25 ;
goto V_51;
}
F_11 ( V_7 , F_6 , * V_36 ) ;
( * V_36 ) -> V_52 = V_46 ;
for ( V_48 = ( * V_36 ) -> V_53 ; V_48 < ( * V_36 ) -> V_53 + V_46 ; V_48 ++ ) {
F_16 ( 16 ) ; V_2 += 16 ;
F_17 ( V_48 -> type ) ;
F_17 ( V_48 -> V_54 ) ;
F_17 ( V_48 -> V_55 ) ;
F_17 ( V_38 ) ;
F_16 ( V_38 ) ;
V_2 += F_9 ( V_38 ) << 2 ;
F_21 ( V_26 , V_38 ) ;
V_48 -> V_56 = F_22 ( V_26 , V_38 ) ;
V_41 = V_57 ;
if ( V_48 -> V_56 != V_58 )
V_48 -> V_59 = 0 ;
else if ( V_48 -> V_54 & V_60 )
V_41 = F_23 ( V_7 -> V_61 ,
V_26 , V_38 , & V_48 -> V_59 ) ;
else
V_41 = F_24 ( V_7 -> V_61 ,
V_26 , V_38 , & V_48 -> V_59 ) ;
if ( V_41 )
return V_41 ;
}
} else
* V_36 = NULL ;
if ( V_29 [ 1 ] & V_62 ) {
F_16 ( 4 ) ;
V_2 += 4 ;
F_17 ( V_34 -> V_63 ) ;
V_34 -> V_63 &= ( V_64 | V_65 ) ;
V_34 -> V_40 |= V_66 ;
}
if ( V_29 [ 1 ] & V_67 ) {
F_16 ( 4 ) ;
V_2 += 4 ;
F_17 ( V_38 ) ;
F_16 ( V_38 ) ;
V_2 += ( F_9 ( V_38 ) << 2 ) ;
F_21 ( V_26 , V_38 ) ;
if ( ( V_41 = F_24 ( V_7 -> V_61 , V_26 , V_38 , & V_34 -> V_68 ) ) )
return V_41 ;
V_34 -> V_40 |= V_69 ;
}
if ( V_29 [ 1 ] & V_70 ) {
F_16 ( 4 ) ;
V_2 += 4 ;
F_17 ( V_38 ) ;
F_16 ( V_38 ) ;
V_2 += ( F_9 ( V_38 ) << 2 ) ;
F_21 ( V_26 , V_38 ) ;
if ( ( V_41 = F_23 ( V_7 -> V_61 , V_26 , V_38 , & V_34 -> V_71 ) ) )
return V_41 ;
V_34 -> V_40 |= V_72 ;
}
if ( V_29 [ 1 ] & V_73 ) {
F_16 ( 4 ) ;
V_2 += 4 ;
F_17 ( V_38 ) ;
switch ( V_38 ) {
case V_74 :
F_16 ( 12 ) ;
V_2 += 12 ;
F_17 ( V_38 ) ;
if ( V_38 )
return V_5 ;
F_17 ( V_34 -> V_75 . V_76 ) ;
F_17 ( V_34 -> V_75 . V_77 ) ;
if ( V_34 -> V_75 . V_77 >= ( T_2 ) 1000000000 )
return V_5 ;
V_34 -> V_40 |= ( V_78 | V_79 ) ;
break;
case V_80 :
V_34 -> V_40 |= V_78 ;
break;
default:
goto V_32;
}
}
if ( V_29 [ 1 ] & V_81 ) {
F_16 ( 4 ) ;
V_2 += 4 ;
F_17 ( V_38 ) ;
switch ( V_38 ) {
case V_74 :
F_16 ( 12 ) ;
V_2 += 12 ;
F_17 ( V_38 ) ;
if ( V_38 )
return V_5 ;
F_17 ( V_34 -> V_82 . V_76 ) ;
F_17 ( V_34 -> V_82 . V_77 ) ;
if ( V_34 -> V_82 . V_77 >= ( T_2 ) 1000000000 )
return V_5 ;
V_34 -> V_40 |= ( V_83 | V_84 ) ;
break;
case V_80 :
V_34 -> V_40 |= V_83 ;
break;
default:
goto V_32;
}
}
if ( V_29 [ 0 ] & ~ V_85
|| V_29 [ 1 ] & ~ V_86
|| V_29 [ 2 ] & ~ V_87 )
F_16 ( V_37 - V_2 ) ;
else if ( V_2 != V_37 )
goto V_32;
V_33 ;
V_51:
V_41 = F_25 ( V_39 ) ;
goto V_88;
}
static T_1
F_26 ( struct V_6 * V_7 , T_4 * V_89 )
{
V_31 ;
F_16 ( sizeof( T_4 ) ) ;
F_17 ( V_89 -> V_90 ) ;
F_27 ( & V_89 -> V_91 , sizeof( V_92 ) ) ;
V_33 ;
}
static T_1
F_28 ( struct V_6 * V_7 , struct V_93 * V_94 )
{
V_31 ;
F_16 ( 4 ) ;
F_17 ( V_94 -> V_95 ) ;
V_33 ;
}
static T_1 F_29 ( struct V_6 * V_7 , struct V_96 * V_97 )
{
V_31 ;
F_16 ( V_98 + 8 ) ;
F_27 ( V_97 -> V_99 . V_100 , V_98 ) ;
F_17 ( V_97 -> V_101 ) ;
V_33 ;
}
static T_1
F_30 ( struct V_6 * V_7 , struct V_102 * V_103 )
{
V_31 ;
F_16 ( 4 ) ;
F_17 ( V_103 -> V_104 ) ;
return F_26 ( V_7 , & V_103 -> V_105 ) ;
V_33 ;
}
static T_1
F_31 ( struct V_6 * V_7 , struct V_106 * V_107 )
{
V_31 ;
F_16 ( 12 ) ;
F_19 ( V_107 -> V_108 ) ;
F_17 ( V_107 -> V_109 ) ;
V_33 ;
}
static T_1
F_32 ( struct V_6 * V_7 , struct V_110 * V_111 )
{
V_31 ;
F_16 ( 4 ) ;
F_17 ( V_111 -> V_112 ) ;
switch ( V_111 -> V_112 ) {
case V_113 :
F_16 ( 4 ) ;
F_17 ( V_111 -> V_114 ) ;
F_16 ( V_111 -> V_114 ) ;
F_33 ( V_111 -> V_115 , V_111 -> V_114 ) ;
break;
case V_116 :
case V_117 :
F_16 ( 8 ) ;
F_17 ( V_111 -> V_118 ) ;
F_17 ( V_111 -> V_119 ) ;
break;
case V_120 :
case V_121 :
case V_122 :
default:
break;
}
F_16 ( 4 ) ;
F_17 ( V_111 -> V_123 ) ;
F_16 ( V_111 -> V_123 ) ;
F_33 ( V_111 -> V_124 , V_111 -> V_123 ) ;
if ( ( V_41 = F_1 ( V_111 -> V_124 , V_111 -> V_123 , V_5 ) ) )
return V_41 ;
V_41 = F_18 ( V_7 , V_111 -> V_125 , & V_111 -> V_126 ,
& V_111 -> V_127 ) ;
if ( V_41 )
goto V_88;
V_33 ;
}
static inline T_1
F_34 ( struct V_6 * V_7 , struct V_128 * V_129 )
{
return F_26 ( V_7 , & V_129 -> V_130 ) ;
}
static inline T_1
F_35 ( struct V_6 * V_7 , struct V_131 * V_132 )
{
return F_15 ( V_7 , V_132 -> V_133 ) ;
}
static T_1
F_36 ( struct V_6 * V_7 , struct V_134 * V_135 )
{
V_31 ;
F_16 ( 4 ) ;
F_17 ( V_135 -> V_136 ) ;
F_16 ( V_135 -> V_136 ) ;
F_33 ( V_135 -> V_137 , V_135 -> V_136 ) ;
if ( ( V_41 = F_1 ( V_135 -> V_137 , V_135 -> V_136 , V_5 ) ) )
return V_41 ;
V_33 ;
}
static T_1
F_37 ( struct V_6 * V_7 , struct V_138 * V_139 )
{
V_31 ;
F_16 ( 28 ) ;
F_17 ( V_139 -> V_140 ) ;
if ( ( V_139 -> V_140 < V_141 ) || ( V_139 -> V_140 > V_142 ) )
goto V_32;
F_17 ( V_139 -> V_143 ) ;
F_19 ( V_139 -> V_144 ) ;
F_19 ( V_139 -> V_145 ) ;
F_17 ( V_139 -> V_146 ) ;
if ( V_139 -> V_146 ) {
F_16 ( 4 ) ;
F_17 ( V_139 -> V_147 ) ;
V_41 = F_26 ( V_7 , & V_139 -> V_148 ) ;
if ( V_41 )
return V_41 ;
F_16 ( 8 + sizeof( T_3 ) ) ;
F_17 ( V_139 -> V_149 ) ;
F_27 ( & V_139 -> V_150 , sizeof( T_3 ) ) ;
F_17 ( V_139 -> V_151 . V_2 ) ;
F_16 ( V_139 -> V_151 . V_2 ) ;
F_21 ( V_139 -> V_151 . V_100 , V_139 -> V_151 . V_2 ) ;
} else {
V_41 = F_26 ( V_7 , & V_139 -> V_152 ) ;
if ( V_41 )
return V_41 ;
F_16 ( 4 ) ;
F_17 ( V_139 -> V_153 ) ;
}
V_33 ;
}
static T_1
F_38 ( struct V_6 * V_7 , struct V_154 * V_155 )
{
V_31 ;
F_16 ( 32 ) ;
F_17 ( V_155 -> V_156 ) ;
if( ( V_155 -> V_156 < V_141 ) || ( V_155 -> V_156 > V_142 ) )
goto V_32;
F_19 ( V_155 -> V_157 ) ;
F_19 ( V_155 -> V_158 ) ;
F_27 ( & V_155 -> V_159 , 8 ) ;
F_17 ( V_155 -> V_160 . V_2 ) ;
F_16 ( V_155 -> V_160 . V_2 ) ;
F_21 ( V_155 -> V_160 . V_100 , V_155 -> V_160 . V_2 ) ;
V_33 ;
}
static T_1
F_39 ( struct V_6 * V_7 , struct V_161 * V_162 )
{
V_31 ;
F_16 ( 8 ) ;
F_17 ( V_162 -> V_163 ) ;
if ( ( V_162 -> V_163 < V_141 ) || ( V_162 -> V_163 > V_142 ) )
goto V_32;
F_17 ( V_162 -> V_164 ) ;
V_41 = F_26 ( V_7 , & V_162 -> V_165 ) ;
if ( V_41 )
return V_41 ;
F_16 ( 16 ) ;
F_19 ( V_162 -> V_166 ) ;
F_19 ( V_162 -> V_167 ) ;
V_33 ;
}
static T_1
F_40 ( struct V_6 * V_7 , struct V_168 * V_169 )
{
V_31 ;
F_16 ( 4 ) ;
F_17 ( V_169 -> V_170 ) ;
F_16 ( V_169 -> V_170 ) ;
F_33 ( V_169 -> V_171 , V_169 -> V_170 ) ;
if ( ( V_41 = F_1 ( V_169 -> V_171 , V_169 -> V_170 , V_172 ) ) )
return V_41 ;
V_33 ;
}
static T_1 F_41 ( struct V_6 * V_7 , T_2 * V_173 )
{
T_1 * V_10 ;
T_2 V_174 ;
F_16 ( 4 ) ;
F_17 ( V_174 ) ;
* V_173 = V_174 ;
switch ( V_174 & V_175 ) {
case V_176 :
case V_177 :
case V_178 :
break;
default:
return V_179 ;
}
V_174 &= ~ V_175 ;
if ( ! V_174 )
return V_57 ;
if ( ! V_7 -> V_180 )
return V_179 ;
switch ( V_174 & V_181 ) {
case V_182 :
case V_183 :
case V_184 :
case V_185 :
case V_186 :
case V_187 :
break;
default:
return V_179 ;
}
V_174 &= ~ V_181 ;
if ( ! V_174 )
return V_57 ;
switch ( V_174 ) {
case V_188 :
case V_189 :
case ( V_188 |
V_189 ) :
return V_57 ;
}
V_32:
return V_179 ;
}
static T_1 F_42 ( struct V_6 * V_7 , T_2 * V_173 )
{
T_1 * V_10 ;
F_16 ( 4 ) ;
F_17 ( * V_173 ) ;
if ( * V_173 & ~ V_190 )
return V_179 ;
return V_57 ;
V_32:
return V_179 ;
}
static T_1 F_43 ( struct V_6 * V_7 , struct V_191 * V_192 )
{
T_1 * V_10 ;
F_16 ( 4 ) ;
F_17 ( V_192 -> V_2 ) ;
if ( V_192 -> V_2 == 0 || V_192 -> V_2 > V_193 )
return V_179 ;
F_16 ( V_192 -> V_2 ) ;
F_33 ( V_192 -> V_100 , V_192 -> V_2 ) ;
return V_57 ;
V_32:
return V_179 ;
}
static T_1
F_44 ( struct V_6 * V_7 , struct V_194 * V_195 )
{
V_31 ;
memset ( V_195 -> V_196 , 0 , sizeof( V_195 -> V_196 ) ) ;
V_195 -> V_197 . V_40 = 0 ;
V_195 -> V_198 = NULL ;
F_16 ( 4 ) ;
F_17 ( V_195 -> V_199 ) ;
V_41 = F_41 ( V_7 , & V_195 -> V_200 ) ;
if ( V_41 )
goto V_32;
V_41 = F_42 ( V_7 , & V_195 -> V_201 ) ;
if ( V_41 )
goto V_32;
F_16 ( sizeof( T_3 ) ) ;
F_27 ( & V_195 -> V_202 , sizeof( T_3 ) ) ;
V_41 = F_43 ( V_7 , & V_195 -> V_203 ) ;
if ( V_41 )
goto V_32;
F_16 ( 4 ) ;
F_17 ( V_195 -> V_204 ) ;
switch ( V_195 -> V_204 ) {
case V_205 :
break;
case V_206 :
F_16 ( 4 ) ;
F_17 ( V_195 -> V_207 ) ;
switch ( V_195 -> V_207 ) {
case V_208 :
case V_209 :
V_41 = F_18 ( V_7 , V_195 -> V_196 ,
& V_195 -> V_197 , & V_195 -> V_210 ) ;
if ( V_41 )
goto V_88;
break;
case V_211 :
F_16 ( 8 ) ;
F_27 ( V_195 -> V_212 . V_100 , 8 ) ;
break;
case V_213 :
if ( V_7 -> V_180 < 1 )
goto V_32;
F_16 ( 8 ) ;
F_27 ( V_195 -> V_212 . V_100 , 8 ) ;
V_41 = F_18 ( V_7 , V_195 -> V_196 ,
& V_195 -> V_197 , & V_195 -> V_210 ) ;
if ( V_41 )
goto V_88;
break;
default:
goto V_32;
}
break;
default:
goto V_32;
}
F_16 ( 4 ) ;
F_17 ( V_195 -> V_214 ) ;
switch ( V_195 -> V_214 ) {
case V_215 :
case V_216 :
F_16 ( 4 ) ;
F_17 ( V_195 -> V_217 . V_2 ) ;
F_16 ( V_195 -> V_217 . V_2 ) ;
F_33 ( V_195 -> V_217 . V_100 , V_195 -> V_217 . V_2 ) ;
if ( ( V_41 = F_1 ( V_195 -> V_217 . V_100 , V_195 -> V_217 . V_2 , V_5 ) ) )
return V_41 ;
break;
case V_218 :
F_16 ( 4 ) ;
F_17 ( V_195 -> V_219 ) ;
break;
case V_220 :
V_41 = F_26 ( V_7 , & V_195 -> V_221 ) ;
if ( V_41 )
return V_41 ;
F_16 ( 4 ) ;
F_17 ( V_195 -> V_217 . V_2 ) ;
F_16 ( V_195 -> V_217 . V_2 ) ;
F_33 ( V_195 -> V_217 . V_100 , V_195 -> V_217 . V_2 ) ;
if ( ( V_41 = F_1 ( V_195 -> V_217 . V_100 , V_195 -> V_217 . V_2 , V_5 ) ) )
return V_41 ;
break;
case V_222 :
case V_223 :
if ( V_7 -> V_180 < 1 )
goto V_32;
break;
case V_224 :
if ( V_7 -> V_180 < 1 )
goto V_32;
V_41 = F_26 ( V_7 , & V_195 -> V_221 ) ;
if ( V_41 )
return V_41 ;
break;
default:
goto V_32;
}
V_33 ;
}
static T_1
F_45 ( struct V_6 * V_7 , struct V_225 * V_226 )
{
V_31 ;
V_41 = F_26 ( V_7 , & V_226 -> V_227 ) ;
if ( V_41 )
return V_41 ;
F_16 ( 4 ) ;
F_17 ( V_226 -> V_228 ) ;
V_33 ;
}
static T_1
F_46 ( struct V_6 * V_7 , struct V_229 * V_230 )
{
V_31 ;
V_41 = F_26 ( V_7 , & V_230 -> V_231 ) ;
if ( V_41 )
return V_41 ;
F_16 ( 4 ) ;
F_17 ( V_230 -> V_232 ) ;
V_41 = F_41 ( V_7 , & V_230 -> V_233 ) ;
if ( V_41 )
return V_41 ;
V_41 = F_42 ( V_7 , & V_230 -> V_234 ) ;
if ( V_41 )
return V_41 ;
V_33 ;
}
static T_1
F_47 ( struct V_6 * V_7 , struct V_235 * V_236 )
{
V_31 ;
F_16 ( 4 ) ;
F_17 ( V_236 -> V_237 ) ;
if ( V_236 -> V_237 > V_238 )
goto V_32;
F_16 ( V_236 -> V_237 ) ;
F_33 ( V_236 -> V_239 , V_236 -> V_237 ) ;
V_33 ;
}
static T_1
F_48 ( struct V_6 * V_7 , struct V_240 * V_241 )
{
V_31 ;
V_41 = F_26 ( V_7 , & V_241 -> V_242 ) ;
if ( V_41 )
return V_41 ;
F_16 ( 12 ) ;
F_19 ( V_241 -> V_243 ) ;
F_17 ( V_241 -> V_244 ) ;
V_33 ;
}
static T_1
F_49 ( struct V_6 * V_7 , struct V_245 * V_246 )
{
V_31 ;
F_16 ( 24 ) ;
F_19 ( V_246 -> V_247 ) ;
F_27 ( V_246 -> V_248 . V_100 , sizeof( V_246 -> V_248 . V_100 ) ) ;
F_17 ( V_246 -> V_249 ) ;
F_17 ( V_246 -> V_250 ) ;
if ( ( V_41 = F_15 ( V_7 , V_246 -> V_251 ) ) )
goto V_88;
V_33 ;
}
static T_1
F_50 ( struct V_6 * V_7 , struct V_252 * remove )
{
V_31 ;
F_16 ( 4 ) ;
F_17 ( remove -> V_253 ) ;
F_16 ( remove -> V_253 ) ;
F_33 ( remove -> V_254 , remove -> V_253 ) ;
if ( ( V_41 = F_1 ( remove -> V_254 , remove -> V_253 , V_172 ) ) )
return V_41 ;
V_33 ;
}
static T_1
F_51 ( struct V_6 * V_7 , struct V_255 * rename )
{
V_31 ;
F_16 ( 4 ) ;
F_17 ( rename -> V_256 ) ;
F_16 ( rename -> V_256 + 4 ) ;
F_33 ( rename -> V_257 , rename -> V_256 ) ;
F_17 ( rename -> V_258 ) ;
F_16 ( rename -> V_258 ) ;
F_33 ( rename -> V_259 , rename -> V_258 ) ;
if ( ( V_41 = F_1 ( rename -> V_257 , rename -> V_256 , V_172 ) ) )
return V_41 ;
if ( ( V_41 = F_1 ( rename -> V_259 , rename -> V_258 , V_5 ) ) )
return V_41 ;
V_33 ;
}
static T_1
F_52 ( struct V_6 * V_7 , T_3 * V_260 )
{
V_31 ;
F_16 ( sizeof( T_3 ) ) ;
F_27 ( V_260 , sizeof( T_3 ) ) ;
V_33 ;
}
static T_1
F_53 ( struct V_6 * V_7 ,
struct V_261 * V_262 )
{
V_31 ;
F_16 ( 4 ) ;
F_17 ( V_262 -> V_263 ) ;
F_16 ( V_262 -> V_263 ) ;
F_33 ( V_262 -> V_264 , V_262 -> V_263 ) ;
V_41 = F_1 ( V_262 -> V_264 , V_262 -> V_263 ,
V_172 ) ;
if ( V_41 )
return V_41 ;
V_33 ;
}
static T_1
F_54 ( struct V_6 * V_7 ,
struct V_265 * sin )
{
V_31 ;
F_16 ( 4 ) ;
F_17 ( sin -> V_266 ) ;
V_33 ;
}
static T_1
F_55 ( struct V_6 * V_7 , struct V_267 * V_268 )
{
T_1 V_41 ;
V_41 = F_26 ( V_7 , & V_268 -> V_269 ) ;
if ( V_41 )
return V_41 ;
return F_18 ( V_7 , V_268 -> V_270 , & V_268 -> V_271 ,
& V_268 -> V_272 ) ;
}
static T_1
F_56 ( struct V_6 * V_7 , struct V_273 * V_274 )
{
V_31 ;
F_16 ( 8 ) ;
F_27 ( V_274 -> V_275 . V_100 , 8 ) ;
V_41 = F_43 ( V_7 , & V_274 -> V_276 ) ;
if ( V_41 )
return V_179 ;
F_16 ( 8 ) ;
F_17 ( V_274 -> V_277 ) ;
F_17 ( V_274 -> V_278 ) ;
F_16 ( V_274 -> V_278 + 4 ) ;
F_33 ( V_274 -> V_279 , V_274 -> V_278 ) ;
F_17 ( V_274 -> V_280 ) ;
F_16 ( V_274 -> V_280 + 4 ) ;
F_33 ( V_274 -> V_281 , V_274 -> V_280 ) ;
F_17 ( V_274 -> V_282 ) ;
V_33 ;
}
static T_1
F_57 ( struct V_6 * V_7 , struct V_283 * V_284 )
{
V_31 ;
F_16 ( 8 + sizeof( V_285 ) ) ;
F_27 ( & V_284 -> V_286 , 8 ) ;
F_27 ( & V_284 -> V_287 , sizeof( V_285 ) ) ;
V_33 ;
}
static T_1
F_58 ( struct V_6 * V_7 , struct V_288 * V_289 )
{
#if 0
struct nfsd4_compoundargs save = {
.p = argp->p,
.end = argp->end,
.rqstp = argp->rqstp,
};
u32 ve_bmval[2];
struct iattr ve_iattr;
struct nfs4_acl *ve_acl;
#endif
V_31 ;
if ( ( V_41 = F_15 ( V_7 , V_289 -> V_290 ) ) )
goto V_88;
#if 0
status = nfsd4_decode_fattr(ve_bmval, &ve_iattr, &ve_acl);
if (status == nfserr_inval) {
status = nfserrno(status);
goto out;
}
#endif
F_16 ( 4 ) ;
F_17 ( V_289 -> V_291 ) ;
F_16 ( V_289 -> V_291 ) ;
F_33 ( V_289 -> V_292 , V_289 -> V_291 ) ;
V_33 ;
}
static T_1
F_59 ( struct V_6 * V_7 , struct V_293 * V_294 )
{
int V_15 ;
int V_295 ;
int V_2 ;
V_31 ;
V_41 = F_26 ( V_7 , & V_294 -> V_296 ) ;
if ( V_41 )
return V_41 ;
F_16 ( 16 ) ;
F_19 ( V_294 -> V_297 ) ;
F_17 ( V_294 -> V_298 ) ;
if ( V_294 -> V_298 > 2 )
goto V_32;
F_17 ( V_294 -> V_299 ) ;
V_15 = ( char * ) V_7 -> V_11 - ( char * ) V_7 -> V_10 ;
if ( V_15 + V_7 -> V_12 < V_294 -> V_299 ) {
F_60 ( L_1 ,
__FILE__ , __LINE__ ) ;
goto V_32;
}
V_7 -> V_61 -> V_300 [ 0 ] . V_301 = V_10 ;
V_7 -> V_61 -> V_300 [ 0 ] . V_302 = V_15 ;
V_295 = 0 ;
V_2 = V_294 -> V_299 ;
while ( V_2 > V_7 -> V_61 -> V_300 [ V_295 ] . V_302 ) {
V_2 -= V_7 -> V_61 -> V_300 [ V_295 ] . V_302 ;
V_295 ++ ;
V_7 -> V_61 -> V_300 [ V_295 ] . V_301 = F_8 ( V_7 -> V_13 [ 0 ] ) ;
V_7 -> V_13 ++ ;
if ( V_7 -> V_12 >= V_16 ) {
V_7 -> V_61 -> V_300 [ V_295 ] . V_302 = V_16 ;
V_7 -> V_12 -= V_16 ;
} else {
V_7 -> V_61 -> V_300 [ V_295 ] . V_302 = V_7 -> V_12 ;
V_7 -> V_12 -= V_2 ;
}
}
V_7 -> V_11 = ( T_1 * ) ( V_7 -> V_61 -> V_300 [ V_295 ] . V_301 + V_7 -> V_61 -> V_300 [ V_295 ] . V_302 ) ;
V_7 -> V_10 = ( T_1 * ) ( V_7 -> V_61 -> V_300 [ V_295 ] . V_301 + ( F_9 ( V_2 ) << 2 ) ) ;
V_7 -> V_61 -> V_300 [ V_295 ] . V_302 = V_2 ;
V_294 -> V_303 = V_295 + 1 ;
V_33 ;
}
static T_1
F_61 ( struct V_6 * V_7 , struct V_304 * V_305 )
{
V_31 ;
F_16 ( 12 ) ;
F_27 ( & V_305 -> V_306 , sizeof( T_3 ) ) ;
F_17 ( V_305 -> V_307 . V_2 ) ;
F_16 ( V_305 -> V_307 . V_2 ) ;
F_21 ( V_305 -> V_307 . V_100 , V_305 -> V_307 . V_2 ) ;
if ( V_7 -> V_180 && ! F_10 ( & V_305 -> V_306 ) )
return V_5 ;
V_33 ;
}
static T_1
F_62 ( struct V_6 * V_7 ,
struct V_308 * V_309 )
{
int V_310 , V_17 ;
V_31 ;
F_16 ( V_311 ) ;
F_27 ( V_309 -> V_312 . V_100 , V_311 ) ;
V_41 = F_43 ( V_7 , & V_309 -> V_313 ) ;
if ( V_41 )
return V_179 ;
F_16 ( 4 ) ;
F_17 ( V_309 -> V_314 ) ;
F_16 ( 4 ) ;
F_17 ( V_309 -> V_315 ) ;
switch ( V_309 -> V_315 ) {
case V_316 :
break;
case V_317 :
F_16 ( 4 ) ;
F_17 ( V_310 ) ;
F_16 ( V_310 * 4 ) ;
V_10 += V_310 ;
F_16 ( 4 ) ;
F_17 ( V_310 ) ;
F_16 ( V_310 * 4 ) ;
V_10 += V_310 ;
break;
case V_318 :
F_16 ( 4 ) ;
F_17 ( V_310 ) ;
F_16 ( V_310 * 4 ) ;
V_10 += V_310 ;
F_16 ( 4 ) ;
F_17 ( V_310 ) ;
F_16 ( V_310 * 4 ) ;
V_10 += V_310 ;
F_16 ( 4 ) ;
F_17 ( V_17 ) ;
while ( V_17 -- ) {
F_16 ( 4 ) ;
F_17 ( V_310 ) ;
F_16 ( V_310 ) ;
V_10 += F_9 ( V_310 ) ;
}
F_16 ( 4 ) ;
F_17 ( V_17 ) ;
while ( V_17 -- ) {
F_16 ( 4 ) ;
F_17 ( V_310 ) ;
F_16 ( V_310 ) ;
V_10 += F_9 ( V_310 ) ;
}
F_16 ( 8 ) ;
F_17 ( V_310 ) ;
F_17 ( V_310 ) ;
break;
default:
goto V_32;
}
F_16 ( 4 ) ;
F_17 ( V_310 ) ;
if ( V_310 > 1 )
goto V_32;
if ( V_310 == 1 ) {
F_16 ( 4 ) ;
F_17 ( V_310 ) ;
F_16 ( V_310 ) ;
V_10 += F_9 ( V_310 ) ;
F_16 ( 4 ) ;
F_17 ( V_310 ) ;
F_16 ( V_310 ) ;
V_10 += F_9 ( V_310 ) ;
F_16 ( 12 ) ;
V_10 += 3 ;
}
V_33 ;
}
static T_1
F_63 ( struct V_6 * V_7 ,
struct V_319 * V_320 )
{
V_31 ;
T_2 V_310 ;
char * V_321 ;
int V_4 ;
int V_322 ;
F_16 ( 16 ) ;
F_27 ( & V_320 -> V_260 , 8 ) ;
F_17 ( V_320 -> V_323 ) ;
F_17 ( V_320 -> V_314 ) ;
F_16 ( 28 ) ;
F_17 ( V_310 ) ;
F_17 ( V_320 -> V_324 . V_325 ) ;
F_17 ( V_320 -> V_324 . V_326 ) ;
F_17 ( V_320 -> V_324 . V_327 ) ;
F_17 ( V_320 -> V_324 . V_328 ) ;
F_17 ( V_320 -> V_324 . V_329 ) ;
F_17 ( V_320 -> V_324 . V_330 ) ;
if ( V_320 -> V_324 . V_330 == 1 ) {
F_16 ( 4 ) ;
F_17 ( V_320 -> V_324 . V_331 ) ;
} else if ( V_320 -> V_324 . V_330 > 1 ) {
F_60 ( L_2 ) ;
goto V_32;
}
F_16 ( 28 ) ;
F_17 ( V_310 ) ;
F_17 ( V_320 -> V_332 . V_325 ) ;
F_17 ( V_320 -> V_332 . V_326 ) ;
F_17 ( V_320 -> V_332 . V_327 ) ;
F_17 ( V_320 -> V_332 . V_328 ) ;
F_17 ( V_320 -> V_332 . V_329 ) ;
F_17 ( V_320 -> V_332 . V_330 ) ;
if ( V_320 -> V_332 . V_330 == 1 ) {
F_16 ( 4 ) ;
F_17 ( V_320 -> V_332 . V_331 ) ;
} else if ( V_320 -> V_332 . V_330 > 1 ) {
F_60 ( L_3 ) ;
goto V_32;
}
F_16 ( 8 ) ;
F_17 ( V_320 -> V_333 ) ;
F_17 ( V_322 ) ;
for ( V_4 = 0 ; V_4 < V_322 ; ++ V_4 ) {
F_16 ( 4 ) ;
F_17 ( V_310 ) ;
switch ( V_310 ) {
case V_334 :
break;
case V_335 :
F_16 ( 8 ) ;
F_17 ( V_310 ) ;
F_17 ( V_310 ) ;
F_16 ( V_310 ) ;
F_33 ( V_321 , V_310 ) ;
F_16 ( 8 ) ;
F_17 ( V_320 -> V_336 ) ;
F_17 ( V_320 -> V_337 ) ;
F_16 ( 4 ) ;
F_17 ( V_310 ) ;
F_16 ( V_310 * 4 ) ;
break;
case V_338 :
F_60 ( L_4
L_5 ) ;
F_16 ( 8 ) ;
F_17 ( V_310 ) ;
F_17 ( V_310 ) ;
F_16 ( V_310 ) ;
V_10 += F_9 ( V_310 ) ;
F_16 ( 4 ) ;
F_17 ( V_310 ) ;
F_16 ( V_310 ) ;
break;
default:
F_60 ( L_6 ) ;
return V_5 ;
}
}
V_33 ;
}
static T_1
F_64 ( struct V_6 * V_7 ,
struct V_339 * V_340 )
{
V_31 ;
F_16 ( V_98 ) ;
F_27 ( V_340 -> V_99 . V_100 , V_98 ) ;
V_33 ;
}
static T_1
F_65 ( struct V_6 * V_7 ,
struct V_341 * V_342 )
{
V_31 ;
F_16 ( sizeof( T_4 ) ) ;
F_17 ( V_342 -> V_343 . V_90 ) ;
F_27 ( & V_342 -> V_343 . V_91 , sizeof( V_92 ) ) ;
V_33 ;
}
static T_1
F_66 ( struct V_6 * V_7 ,
struct V_344 * V_345 )
{
V_31 ;
F_16 ( V_98 + 16 ) ;
F_27 ( V_345 -> V_99 . V_100 , V_98 ) ;
F_17 ( V_345 -> V_323 ) ;
F_17 ( V_345 -> V_346 ) ;
F_17 ( V_345 -> V_347 ) ;
F_17 ( V_345 -> V_348 ) ;
V_33 ;
}
static T_1
F_67 ( struct V_6 * V_7 , struct V_349 * V_350 )
{
unsigned int V_14 ;
T_4 V_351 ;
int V_4 ;
T_1 * V_10 ;
T_1 V_41 ;
F_16 ( 4 ) ;
V_350 -> V_352 = F_68 ( * V_10 ++ ) ;
V_14 = V_350 -> V_352 * sizeof( T_4 ) ;
if ( V_14 > ( T_2 ) ( ( char * ) V_7 -> V_11 - ( char * ) V_7 -> V_10 ) )
goto V_32;
V_350 -> V_353 = V_7 ;
F_3 ( V_7 , & V_350 -> V_354 ) ;
for ( V_4 = 0 ; V_4 < V_350 -> V_352 ; V_4 ++ ) {
V_41 = F_26 ( V_7 , & V_351 ) ;
if ( V_41 )
return V_41 ;
}
V_41 = 0 ;
V_88:
return V_41 ;
V_32:
F_60 ( L_1 , __FILE__ , __LINE__ ) ;
V_41 = V_179 ;
goto V_88;
}
static T_1 F_69 ( struct V_6 * V_7 , struct V_355 * V_356 )
{
V_31 ;
F_16 ( 8 ) ;
F_27 ( & V_356 -> V_260 , 8 ) ;
V_33 ;
}
static T_1 F_70 ( struct V_6 * V_7 , struct V_357 * V_358 )
{
V_31 ;
F_16 ( 4 ) ;
F_17 ( V_358 -> V_359 ) ;
V_33 ;
}
static T_1
F_71 ( struct V_6 * V_7 , void * V_10 )
{
return V_57 ;
}
static T_1
F_72 ( struct V_6 * V_7 , void * V_10 )
{
return V_360 ;
}
static T_1
F_73 ( struct V_6 * V_7 )
{
V_31 ;
struct V_361 * V_362 ;
struct V_363 * V_364 ;
bool V_348 = false ;
int V_4 ;
F_16 ( 4 ) ;
F_17 ( V_7 -> V_365 ) ;
F_16 ( V_7 -> V_365 + 8 ) ;
F_33 ( V_7 -> V_366 , V_7 -> V_365 ) ;
F_17 ( V_7 -> V_180 ) ;
F_17 ( V_7 -> V_367 ) ;
if ( V_7 -> V_365 > V_368 )
goto V_32;
if ( V_7 -> V_367 > 100 )
goto V_32;
if ( V_7 -> V_367 > F_74 ( V_7 -> V_369 ) ) {
V_7 -> V_364 = F_7 ( V_7 -> V_367 * sizeof( * V_7 -> V_364 ) , V_19 ) ;
if ( ! V_7 -> V_364 ) {
V_7 -> V_364 = V_7 -> V_369 ;
F_60 ( L_7 ) ;
goto V_32;
}
}
if ( V_7 -> V_180 >= F_74 ( V_370 ) )
V_7 -> V_367 = 0 ;
V_364 = & V_370 [ V_7 -> V_180 ] ;
for ( V_4 = 0 ; V_4 < V_7 -> V_367 ; V_4 ++ ) {
V_362 = & V_7 -> V_364 [ V_4 ] ;
V_362 -> V_371 = NULL ;
if ( V_7 -> V_10 == V_7 -> V_11 ) {
if ( V_7 -> V_12 < 4 ) {
V_362 -> V_372 = V_373 + 1 ;
V_362 -> V_41 = V_179 ;
V_7 -> V_367 = V_4 + 1 ;
break;
}
V_7 -> V_10 = F_8 ( V_7 -> V_13 [ 0 ] ) ;
V_7 -> V_13 ++ ;
if ( V_7 -> V_12 < V_16 ) {
V_7 -> V_11 = V_7 -> V_10 + ( V_7 -> V_12 >> 2 ) ;
V_7 -> V_12 = 0 ;
} else {
V_7 -> V_11 = V_7 -> V_10 + ( V_16 >> 2 ) ;
V_7 -> V_12 -= V_16 ;
}
}
V_362 -> V_372 = F_68 ( * V_7 -> V_10 ++ ) ;
if ( V_362 -> V_372 >= V_374 && V_362 -> V_372 <= V_375 )
V_362 -> V_41 = V_364 -> V_376 [ V_362 -> V_372 ] ( V_7 , & V_362 -> V_377 ) ;
else {
V_362 -> V_372 = V_378 ;
V_362 -> V_41 = V_379 ;
}
if ( V_362 -> V_41 ) {
V_7 -> V_367 = V_4 + 1 ;
break;
}
V_348 |= F_75 ( V_362 ) ;
}
if ( V_7 -> V_180 )
V_348 = false ;
V_7 -> V_61 -> V_380 = V_348 ? V_381 : V_382 ;
V_33 ;
}
static void F_76 ( T_1 * * V_10 , T_2 V_383 )
{
* ( * V_10 ) ++ = V_383 ;
}
static void F_77 ( T_1 * * V_10 , T_5 V_383 )
{
F_76 ( V_10 , ( T_2 ) ( V_383 >> 32 ) ) ;
F_76 ( V_10 , ( T_2 ) V_383 ) ;
}
static void F_78 ( T_1 * * V_10 , struct V_384 * V_385 , struct V_386 * V_386 )
{
if ( F_79 ( V_386 ) ) {
F_77 ( V_10 , V_386 -> V_387 ) ;
} else {
F_76 ( V_10 , V_385 -> ctime . V_76 ) ;
F_76 ( V_10 , V_385 -> ctime . V_77 ) ;
}
}
static void F_80 ( T_1 * * V_10 , struct V_388 * V_389 )
{
F_76 ( V_10 , V_389 -> V_390 ) ;
if ( V_389 -> V_391 ) {
F_77 ( V_10 , V_389 -> V_392 ) ;
F_77 ( V_10 , V_389 -> V_393 ) ;
} else {
F_76 ( V_10 , V_389 -> V_394 ) ;
F_76 ( V_10 , V_389 -> V_395 ) ;
F_76 ( V_10 , V_389 -> V_396 ) ;
F_76 ( V_10 , V_389 -> V_397 ) ;
}
}
static void F_81 ( struct V_398 * V_399 , T_1 * V_400 , T_1 V_401 )
{
struct V_402 * V_403 = V_399 -> V_404 . V_405 ;
if ( F_82 ( F_68 ( V_401 ) ) && V_403 ) {
V_403 -> V_406 ++ ;
V_403 -> V_407 . V_408 = V_401 ;
V_403 -> V_407 . V_409 =
( char * ) V_399 -> V_10 - ( char * ) V_400 ;
memcpy ( V_403 -> V_407 . V_410 , V_400 ,
V_403 -> V_407 . V_409 ) ;
F_83 ( V_403 ) ;
}
}
static T_1 F_84 ( char V_411 , char * V_412 ,
T_1 * * V_413 , int * V_414 )
{
T_1 * V_10 = * V_413 ;
T_1 * V_415 = V_10 ;
int strlen , V_416 = 0 ;
char * V_1 , * V_11 ;
F_60 ( L_8 , V_412 ) ;
if ( ( * V_414 -= 4 ) < 0 )
return V_50 ;
F_85 ( 0 ) ;
V_11 = V_1 = V_412 ;
while ( * V_11 ) {
for (; * V_11 && ( * V_11 != V_411 ) ; V_11 ++ )
;
strlen = V_11 - V_1 ;
if ( strlen ) {
if ( ( * V_414 -= ( ( F_9 ( strlen ) << 2 ) + 4 ) ) < 0 )
return V_50 ;
F_85 ( strlen ) ;
F_86 ( V_1 , strlen ) ;
V_416 ++ ;
}
else
V_11 ++ ;
V_1 = V_11 ;
}
* V_413 = V_10 ;
V_10 = V_415 ;
F_85 ( V_416 ) ;
return 0 ;
}
static T_1 F_87 ( struct V_417 * V_418 ,
T_1 * * V_413 , int * V_414 )
{
T_1 V_41 ;
T_1 * V_10 = * V_413 ;
V_41 = F_84 ( ':' , V_418 -> V_419 , & V_10 , V_414 ) ;
if ( V_41 )
return V_41 ;
V_41 = F_84 ( '/' , V_418 -> V_420 , & V_10 , V_414 ) ;
if ( V_41 )
return V_41 ;
* V_413 = V_10 ;
return 0 ;
}
static T_1 F_88 ( const struct V_420 * V_421 ,
const struct V_420 * V_420 , T_1 * * V_413 , int * V_414 )
{
struct V_420 V_422 = {
. V_423 = V_420 -> V_423 ,
. V_424 = V_420 -> V_424 ,
} ;
T_1 * V_10 = * V_413 ;
struct V_424 * * V_412 = NULL ;
unsigned int V_425 = 0 ;
T_1 V_3 = V_426 ;
F_60 ( L_9 ) ;
F_89 ( & V_422 ) ;
for (; ; ) {
if ( V_422 . V_424 == V_421 -> V_424 && V_422 . V_423 == V_421 -> V_423 )
break;
if ( V_422 . V_424 == V_422 . V_423 -> V_427 ) {
if ( F_90 ( & V_422 ) )
continue;
goto V_428;
}
if ( ( V_425 & 15 ) == 0 ) {
struct V_424 * * V_429 ;
V_429 = F_91 ( V_412 ,
sizeof( * V_429 ) * ( V_425 + 16 ) ,
V_19 ) ;
if ( ! V_429 )
goto V_428;
V_412 = V_429 ;
}
V_412 [ V_425 ++ ] = V_422 . V_424 ;
V_422 . V_424 = F_92 ( V_422 . V_424 ) ;
}
* V_414 -= 4 ;
if ( * V_414 < 0 )
goto V_428;
F_85 ( V_425 ) ;
while ( V_425 ) {
struct V_424 * V_424 = V_412 [ V_425 - 1 ] ;
unsigned int V_2 = V_424 -> V_430 . V_2 ;
* V_414 -= 4 + ( F_9 ( V_2 ) << 2 ) ;
if ( * V_414 < 0 )
goto V_428;
F_85 ( V_2 ) ;
F_86 ( V_424 -> V_430 . V_431 , V_2 ) ;
F_60 ( L_10 , V_424 -> V_430 . V_431 ) ;
F_93 ( V_424 ) ;
V_425 -- ;
}
* V_413 = V_10 ;
V_3 = 0 ;
V_428:
F_60 ( L_11 ) ;
while ( V_425 )
F_93 ( V_412 [ -- V_425 ] ) ;
F_6 ( V_412 ) ;
F_94 ( & V_422 ) ;
return V_3 ;
}
static T_1 F_95 ( struct V_432 * V_61 ,
const struct V_420 * V_420 , T_1 * * V_413 , int * V_414 )
{
struct V_433 * V_434 ;
T_1 V_435 ;
V_434 = F_96 ( V_61 ) ;
if ( F_97 ( V_434 ) )
return F_25 ( F_98 ( V_434 ) ) ;
V_435 = F_88 ( & V_434 -> V_436 , V_420 , V_413 , V_414 ) ;
F_99 ( V_434 ) ;
return V_435 ;
}
static T_1 F_100 ( struct V_432 * V_61 ,
struct V_433 * exp ,
T_1 * * V_413 , int * V_414 )
{
T_1 V_41 ;
int V_4 ;
T_1 * V_10 = * V_413 ;
struct V_437 * V_438 = & exp -> V_439 ;
V_41 = F_95 ( V_61 , & exp -> V_436 , & V_10 , V_414 ) ;
if ( V_41 )
return V_41 ;
if ( ( * V_414 -= 4 ) < 0 )
return V_50 ;
F_85 ( V_438 -> V_440 ) ;
for ( V_4 = 0 ; V_4 < V_438 -> V_440 ; V_4 ++ ) {
V_41 = F_87 ( & V_438 -> V_441 [ V_4 ] ,
& V_10 , V_414 ) ;
if ( V_41 )
return V_41 ;
}
* V_413 = V_10 ;
return 0 ;
}
static T_2 F_101 ( T_6 V_442 )
{
switch ( V_442 & V_64 ) {
case V_443 : return V_121 ;
case V_444 : return V_117 ;
case V_445 : return V_122 ;
case V_446 : return V_116 ;
case V_447 : return V_113 ;
case V_448 : return V_449 ;
case V_450 : return V_120 ;
default: return V_451 ;
} ;
}
static T_1
F_102 ( struct V_432 * V_61 , int V_56 , T_7 V_452 , int V_453 ,
T_1 * * V_10 , int * V_414 )
{
int V_41 ;
if ( * V_414 < ( F_9 ( V_454 ) << 2 ) + 4 )
return V_50 ;
if ( V_56 != V_58 )
V_41 = F_103 ( V_56 , ( V_455 * ) ( * V_10 + 1 ) ) ;
else if ( V_453 )
V_41 = F_104 ( V_61 , V_452 , ( V_455 * ) ( * V_10 + 1 ) ) ;
else
V_41 = F_105 ( V_61 , V_452 , ( V_455 * ) ( * V_10 + 1 ) ) ;
if ( V_41 < 0 )
return F_25 ( V_41 ) ;
* V_10 = F_106 ( * V_10 , NULL , V_41 ) ;
* V_414 -= ( F_9 ( V_41 ) << 2 ) + 4 ;
F_14 ( * V_414 < 0 ) ;
return 0 ;
}
static inline T_1
F_107 ( struct V_432 * V_61 , T_7 V_336 , T_1 * * V_10 , int * V_414 )
{
return F_102 ( V_61 , V_58 , V_336 , 0 , V_10 , V_414 ) ;
}
static inline T_1
F_108 ( struct V_432 * V_61 , T_7 V_337 , T_1 * * V_10 , int * V_414 )
{
return F_102 ( V_61 , V_58 , V_337 , 1 , V_10 , V_414 ) ;
}
static inline T_1
F_109 ( struct V_432 * V_61 , int V_56 , T_7 V_452 , int V_453 ,
T_1 * * V_10 , int * V_414 )
{
return F_102 ( V_61 , V_56 , V_452 , V_453 , V_10 , V_414 ) ;
}
static T_1 F_110 ( T_2 * V_456 , T_2 * V_457 , T_2 * V_458 )
{
if ( * V_456 & ~ V_459 ||
* V_457 & ~ V_460 ) {
if ( * V_456 & V_461 ||
* V_456 & V_462 )
* V_458 = V_463 ;
else
return V_464 ;
}
* V_456 &= V_459 ;
* V_457 &= V_460 ;
return 0 ;
}
T_1
F_111 ( struct V_465 * V_466 , struct V_433 * exp ,
struct V_424 * V_424 , T_1 * V_467 , int * V_415 , T_2 * V_29 ,
struct V_432 * V_61 , int V_468 )
{
T_2 V_456 = V_29 [ 0 ] ;
T_2 V_457 = V_29 [ 1 ] ;
T_2 V_469 = V_29 [ 2 ] ;
struct V_384 V_385 ;
struct V_465 V_470 ;
struct V_471 V_472 ;
int V_414 = * V_415 << 2 ;
T_1 * V_473 ;
T_2 V_310 ;
T_5 V_474 ;
T_2 V_458 = 0 ;
T_1 * V_10 = V_467 ;
T_1 V_41 ;
int V_3 ;
int V_475 = 0 ;
struct V_35 * V_36 = NULL ;
struct V_398 * V_399 = V_61 -> V_476 ;
T_2 V_180 = V_399 -> V_404 . V_180 ;
struct V_420 V_420 = {
. V_423 = exp -> V_436 . V_423 ,
. V_424 = V_424 ,
} ;
F_14 ( V_457 & V_477 ) ;
F_14 ( V_456 & ~ F_112 ( V_180 ) ) ;
F_14 ( V_457 & ~ F_113 ( V_180 ) ) ;
F_14 ( V_469 & ~ F_114 ( V_180 ) ) ;
if ( exp -> V_439 . V_478 ) {
F_14 ( V_29 [ 2 ] ) ;
V_41 = F_110 ( & V_456 , & V_457 , & V_458 ) ;
if ( V_41 )
goto V_88;
}
V_3 = F_115 ( exp -> V_436 . V_423 , V_424 , & V_385 ) ;
if ( V_3 )
goto V_51;
if ( ( V_456 & ( V_479 | V_480 |
V_481 ) ) ||
( V_457 & ( V_482 | V_483 |
V_484 ) ) ) {
V_3 = F_116 ( & V_420 , & V_472 ) ;
if ( V_3 )
goto V_51;
}
if ( ( V_456 & ( V_485 | V_486 ) ) && ! V_466 ) {
F_117 ( & V_470 , V_238 ) ;
V_41 = F_118 ( & V_470 , exp , V_424 , NULL ) ;
if ( V_41 )
goto V_88;
V_466 = & V_470 ;
}
if ( V_456 & ( V_45 | V_487
| V_488 ) ) {
V_3 = F_119 ( V_61 , V_424 , & V_36 ) ;
V_475 = ( V_3 == 0 ) ;
if ( V_456 & V_45 ) {
if ( V_3 == - V_489 )
V_456 &= ~ V_45 ;
else if ( V_3 == - V_490 ) {
V_41 = V_491 ;
goto V_88;
} else if ( V_3 != 0 )
goto V_51;
}
}
if ( V_469 ) {
if ( ( V_414 -= 16 ) < 0 )
goto V_492;
F_85 ( 3 ) ;
F_85 ( V_456 ) ;
F_85 ( V_457 ) ;
F_85 ( V_469 ) ;
} else if ( V_457 ) {
if ( ( V_414 -= 12 ) < 0 )
goto V_492;
F_85 ( 2 ) ;
F_85 ( V_456 ) ;
F_85 ( V_457 ) ;
} else {
if ( ( V_414 -= 8 ) < 0 )
goto V_492;
F_85 ( 1 ) ;
F_85 ( V_456 ) ;
}
V_473 = V_10 ++ ;
if ( V_456 & V_488 ) {
T_2 V_493 = F_112 ( V_180 ) ;
T_2 V_494 = F_113 ( V_180 ) ;
T_2 V_495 = F_114 ( V_180 ) ;
if ( ! V_475 )
V_493 &= ~ V_45 ;
if ( ! V_495 ) {
if ( ( V_414 -= 12 ) < 0 )
goto V_492;
F_85 ( 2 ) ;
F_85 ( V_493 ) ;
F_85 ( V_494 ) ;
} else {
if ( ( V_414 -= 16 ) < 0 )
goto V_492;
F_85 ( 3 ) ;
F_85 ( V_493 ) ;
F_85 ( V_494 ) ;
F_85 ( V_495 ) ;
}
}
if ( V_456 & V_496 ) {
if ( ( V_414 -= 4 ) < 0 )
goto V_492;
V_310 = F_101 ( V_385 . V_442 ) ;
if ( V_310 == V_451 )
goto V_497;
F_85 ( V_310 ) ;
}
if ( V_456 & V_498 ) {
if ( ( V_414 -= 4 ) < 0 )
goto V_492;
if ( exp -> V_499 & V_500 )
F_85 ( V_501 ) ;
else
F_85 ( V_501 | V_502 ) ;
}
if ( V_456 & V_503 ) {
if ( ( V_414 -= 8 ) < 0 )
goto V_492;
F_78 ( & V_10 , & V_385 , V_424 -> V_504 ) ;
}
if ( V_456 & V_42 ) {
if ( ( V_414 -= 8 ) < 0 )
goto V_492;
F_120 ( V_385 . V_505 ) ;
}
if ( V_456 & V_506 ) {
if ( ( V_414 -= 4 ) < 0 )
goto V_492;
F_85 ( 1 ) ;
}
if ( V_456 & V_507 ) {
if ( ( V_414 -= 4 ) < 0 )
goto V_492;
F_85 ( 1 ) ;
}
if ( V_456 & V_508 ) {
if ( ( V_414 -= 4 ) < 0 )
goto V_492;
F_85 ( 0 ) ;
}
if ( V_456 & V_486 ) {
if ( ( V_414 -= 16 ) < 0 )
goto V_492;
if ( exp -> V_439 . V_478 ) {
F_120 ( V_509 ) ;
F_120 ( V_510 ) ;
} else switch( F_121 ( V_466 ) ) {
case V_511 :
F_120 ( ( T_5 ) exp -> V_512 ) ;
F_120 ( ( T_5 ) 0 ) ;
break;
case V_513 :
F_85 ( 0 ) ;
F_85 ( F_122 ( V_385 . V_514 ) ) ;
F_85 ( 0 ) ;
F_85 ( F_123 ( V_385 . V_514 ) ) ;
break;
case V_515 :
F_86 ( exp -> V_516 , 16 ) ;
break;
}
}
if ( V_456 & V_517 ) {
if ( ( V_414 -= 4 ) < 0 )
goto V_492;
F_85 ( 0 ) ;
}
if ( V_456 & V_518 ) {
if ( ( V_414 -= 4 ) < 0 )
goto V_492;
F_85 ( V_519 ) ;
}
if ( V_456 & V_461 ) {
if ( ( V_414 -= 4 ) < 0 )
goto V_492;
F_85 ( V_458 ) ;
}
if ( V_456 & V_45 ) {
struct V_47 * V_48 ;
if ( V_36 == NULL ) {
if ( ( V_414 -= 4 ) < 0 )
goto V_492;
F_85 ( 0 ) ;
goto V_520;
}
if ( ( V_414 -= 4 ) < 0 )
goto V_492;
F_85 ( V_36 -> V_52 ) ;
for ( V_48 = V_36 -> V_53 ; V_48 < V_36 -> V_53 + V_36 -> V_52 ; V_48 ++ ) {
if ( ( V_414 -= 4 * 3 ) < 0 )
goto V_492;
F_85 ( V_48 -> type ) ;
F_85 ( V_48 -> V_54 ) ;
F_85 ( V_48 -> V_55 & V_521 ) ;
V_41 = F_109 ( V_61 , V_48 -> V_56 ,
V_48 -> V_59 , V_48 -> V_54 & V_60 ,
& V_10 , & V_414 ) ;
if ( V_41 == V_50 )
goto V_492;
if ( V_41 )
goto V_88;
}
}
V_520:
if ( V_456 & V_487 ) {
if ( ( V_414 -= 4 ) < 0 )
goto V_492;
F_85 ( V_475 ?
V_522 | V_523 : 0 ) ;
}
if ( V_456 & V_524 ) {
if ( ( V_414 -= 4 ) < 0 )
goto V_492;
F_85 ( 1 ) ;
}
if ( V_456 & V_525 ) {
if ( ( V_414 -= 4 ) < 0 )
goto V_492;
F_85 ( 1 ) ;
}
if ( V_456 & V_526 ) {
if ( ( V_414 -= 4 ) < 0 )
goto V_492;
F_85 ( 1 ) ;
}
if ( V_456 & V_527 ) {
if ( ( V_414 -= 4 ) < 0 )
goto V_492;
F_85 ( 1 ) ;
}
if ( V_456 & V_485 ) {
V_414 -= ( F_9 ( V_466 -> V_528 . V_529 ) << 2 ) + 4 ;
if ( V_414 < 0 )
goto V_492;
F_85 ( V_466 -> V_528 . V_529 ) ;
F_86 ( & V_466 -> V_528 . V_530 , V_466 -> V_528 . V_529 ) ;
}
if ( V_456 & V_531 ) {
if ( ( V_414 -= 8 ) < 0 )
goto V_492;
F_120 ( V_385 . V_532 ) ;
}
if ( V_456 & V_533 ) {
if ( ( V_414 -= 8 ) < 0 )
goto V_492;
F_120 ( ( T_5 ) V_472 . V_534 ) ;
}
if ( V_456 & V_479 ) {
if ( ( V_414 -= 8 ) < 0 )
goto V_492;
F_120 ( ( T_5 ) V_472 . V_534 ) ;
}
if ( V_456 & V_480 ) {
if ( ( V_414 -= 8 ) < 0 )
goto V_492;
F_120 ( ( T_5 ) V_472 . V_535 ) ;
}
if ( V_456 & V_462 ) {
V_41 = F_100 ( V_61 , exp , & V_10 , & V_414 ) ;
if ( V_41 == V_50 )
goto V_492;
if ( V_41 )
goto V_88;
}
if ( V_456 & V_536 ) {
if ( ( V_414 -= 4 ) < 0 )
goto V_492;
F_85 ( 1 ) ;
}
if ( V_456 & V_537 ) {
if ( ( V_414 -= 8 ) < 0 )
goto V_492;
F_120 ( ~ ( T_5 ) 0 ) ;
}
if ( V_456 & V_538 ) {
if ( ( V_414 -= 4 ) < 0 )
goto V_492;
F_85 ( 255 ) ;
}
if ( V_456 & V_481 ) {
if ( ( V_414 -= 4 ) < 0 )
goto V_492;
F_85 ( V_472 . V_539 ) ;
}
if ( V_456 & V_540 ) {
if ( ( V_414 -= 8 ) < 0 )
goto V_492;
F_120 ( ( T_5 ) F_124 ( V_61 ) ) ;
}
if ( V_456 & V_541 ) {
if ( ( V_414 -= 8 ) < 0 )
goto V_492;
F_120 ( ( T_5 ) F_124 ( V_61 ) ) ;
}
if ( V_457 & V_62 ) {
if ( ( V_414 -= 4 ) < 0 )
goto V_492;
F_85 ( V_385 . V_442 & V_65 ) ;
}
if ( V_457 & V_542 ) {
if ( ( V_414 -= 4 ) < 0 )
goto V_492;
F_85 ( 1 ) ;
}
if ( V_457 & V_543 ) {
if ( ( V_414 -= 4 ) < 0 )
goto V_492;
F_85 ( V_385 . V_544 ) ;
}
if ( V_457 & V_67 ) {
V_41 = F_107 ( V_61 , V_385 . V_336 , & V_10 , & V_414 ) ;
if ( V_41 == V_50 )
goto V_492;
if ( V_41 )
goto V_88;
}
if ( V_457 & V_70 ) {
V_41 = F_108 ( V_61 , V_385 . V_337 , & V_10 , & V_414 ) ;
if ( V_41 == V_50 )
goto V_492;
if ( V_41 )
goto V_88;
}
if ( V_457 & V_545 ) {
if ( ( V_414 -= 8 ) < 0 )
goto V_492;
F_85 ( ( T_2 ) F_122 ( V_385 . V_546 ) ) ;
F_85 ( ( T_2 ) F_123 ( V_385 . V_546 ) ) ;
}
if ( V_457 & V_482 ) {
if ( ( V_414 -= 8 ) < 0 )
goto V_492;
V_474 = ( T_5 ) V_472 . V_547 * ( T_5 ) V_472 . V_548 ;
F_120 ( V_474 ) ;
}
if ( V_457 & V_483 ) {
if ( ( V_414 -= 8 ) < 0 )
goto V_492;
V_474 = ( T_5 ) V_472 . V_549 * ( T_5 ) V_472 . V_548 ;
F_120 ( V_474 ) ;
}
if ( V_457 & V_484 ) {
if ( ( V_414 -= 8 ) < 0 )
goto V_492;
V_474 = ( T_5 ) V_472 . V_550 * ( T_5 ) V_472 . V_548 ;
F_120 ( V_474 ) ;
}
if ( V_457 & V_551 ) {
if ( ( V_414 -= 8 ) < 0 )
goto V_492;
V_474 = ( T_5 ) V_385 . V_552 << 9 ;
F_120 ( V_474 ) ;
}
if ( V_457 & V_553 ) {
if ( ( V_414 -= 12 ) < 0 )
goto V_492;
F_85 ( 0 ) ;
F_85 ( V_385 . V_554 . V_76 ) ;
F_85 ( V_385 . V_554 . V_77 ) ;
}
if ( V_457 & V_555 ) {
if ( ( V_414 -= 12 ) < 0 )
goto V_492;
F_85 ( 0 ) ;
F_85 ( 1 ) ;
F_85 ( 0 ) ;
}
if ( V_457 & V_556 ) {
if ( ( V_414 -= 12 ) < 0 )
goto V_492;
F_85 ( 0 ) ;
F_85 ( V_385 . ctime . V_76 ) ;
F_85 ( V_385 . ctime . V_77 ) ;
}
if ( V_457 & V_557 ) {
if ( ( V_414 -= 12 ) < 0 )
goto V_492;
F_85 ( 0 ) ;
F_85 ( V_385 . V_558 . V_76 ) ;
F_85 ( V_385 . V_558 . V_77 ) ;
}
if ( V_457 & V_559 ) {
if ( ( V_414 -= 8 ) < 0 )
goto V_492;
if ( V_468 == 0 &&
V_424 == exp -> V_436 . V_423 -> V_427 ) {
struct V_420 V_420 = exp -> V_436 ;
F_89 ( & V_420 ) ;
while ( F_90 ( & V_420 ) ) {
if ( V_420 . V_424 != V_420 . V_423 -> V_427 )
break;
}
V_3 = F_115 ( V_420 . V_423 , V_420 . V_424 , & V_385 ) ;
F_94 ( & V_420 ) ;
if ( V_3 )
goto V_51;
}
F_120 ( V_385 . V_532 ) ;
}
if ( V_469 & V_560 ) {
F_85 ( 3 ) ;
F_85 ( V_561 ) ;
F_85 ( V_562 ) ;
F_85 ( V_563 ) ;
}
* V_473 = F_125 ( ( char * ) V_10 - ( char * ) V_473 - 4 ) ;
* V_415 = V_10 - V_467 ;
V_41 = V_57 ;
V_88:
F_6 ( V_36 ) ;
if ( V_466 == & V_470 )
F_126 ( & V_470 ) ;
return V_41 ;
V_51:
V_41 = F_25 ( V_3 ) ;
goto V_88;
V_492:
* V_415 = 0 ;
V_41 = V_50 ;
goto V_88;
V_497:
V_41 = V_564 ;
goto V_88;
}
static inline int F_127 ( T_2 * V_29 )
{
if ( V_29 [ 0 ] & ~ ( V_461 | V_518 ) )
return 1 ;
if ( V_29 [ 1 ] & ~ V_559 )
return 1 ;
return 0 ;
}
static T_1
F_128 ( struct V_245 * V_565 ,
const char * V_431 , int V_566 , T_1 * V_10 , int * V_414 )
{
struct V_433 * exp = V_565 -> V_567 -> V_568 ;
struct V_424 * V_424 ;
T_1 V_401 ;
int V_468 = 0 ;
V_424 = F_129 ( V_431 , V_565 -> V_567 -> V_569 , V_566 ) ;
if ( F_97 ( V_424 ) )
return F_25 ( F_98 ( V_424 ) ) ;
if ( ! V_424 -> V_504 ) {
F_93 ( V_424 ) ;
return V_172 ;
}
F_130 ( exp ) ;
if ( F_131 ( V_424 , exp ) ) {
int V_3 ;
if ( ! ( exp -> V_499 & V_570 )
&& ! F_127 ( V_565 -> V_251 ) ) {
V_468 = 1 ;
goto V_571;
}
V_3 = F_132 ( V_565 -> V_572 , & V_424 , & exp ) ;
if ( V_3 ) {
V_401 = F_25 ( V_3 ) ;
goto V_573;
}
V_401 = F_133 ( exp , V_565 -> V_572 ) ;
if ( V_401 )
goto V_573;
}
V_571:
V_401 = F_111 ( NULL , exp , V_424 , V_10 , V_414 , V_565 -> V_251 ,
V_565 -> V_572 , V_468 ) ;
V_573:
F_93 ( V_424 ) ;
F_99 ( exp ) ;
return V_401 ;
}
static T_1 *
F_134 ( T_1 * V_10 , int V_414 , T_1 V_401 )
{
T_1 * V_473 ;
if ( V_414 < 6 )
return NULL ;
* V_10 ++ = F_125 ( 2 ) ;
* V_10 ++ = F_125 ( V_461 ) ;
* V_10 ++ = F_125 ( 0 ) ;
V_473 = V_10 ++ ;
* V_10 ++ = V_401 ;
* V_473 = F_125 ( ( char * ) V_10 - ( char * ) V_473 - 4 ) ;
return V_10 ;
}
static int
F_135 ( void * V_574 , const char * V_431 , int V_566 ,
T_8 V_575 , T_5 V_532 , unsigned int V_576 )
{
struct V_577 * V_578 = V_574 ;
struct V_245 * V_565 = F_136 ( V_578 , struct V_245 , V_579 ) ;
int V_414 ;
T_1 * V_10 = V_565 -> V_467 ;
T_1 * V_580 ;
T_1 V_401 = V_581 ;
if ( V_431 && F_2 ( V_431 , V_566 ) ) {
V_565 -> V_579 . V_3 = V_57 ;
return 0 ;
}
if ( V_565 -> V_575 )
F_137 ( V_565 -> V_575 , ( T_5 ) V_575 ) ;
V_414 = V_565 -> V_414 - 4 - F_9 ( V_566 ) ;
if ( V_414 < 0 )
goto V_582;
* V_10 ++ = V_583 ;
V_580 = V_10 ;
V_10 = F_137 ( V_10 , V_584 ) ;
V_10 = F_138 ( V_10 , V_431 , V_566 ) ;
V_401 = F_128 ( V_565 , V_431 , V_566 , V_10 , & V_414 ) ;
switch ( V_401 ) {
case V_57 :
V_10 += V_414 ;
break;
case V_50 :
V_401 = V_581 ;
goto V_582;
case V_172 :
goto V_585;
default:
if ( ! ( V_565 -> V_251 [ 0 ] & V_461 ) )
goto V_582;
V_10 = F_134 ( V_10 , V_414 , V_401 ) ;
if ( V_10 == NULL ) {
V_401 = V_581 ;
goto V_582;
}
}
V_565 -> V_414 -= ( V_10 - V_565 -> V_467 ) ;
V_565 -> V_467 = V_10 ;
V_565 -> V_575 = V_580 ;
V_585:
V_565 -> V_579 . V_3 = V_57 ;
return 0 ;
V_582:
V_565 -> V_579 . V_3 = V_401 ;
return - V_490 ;
}
static void
F_139 ( struct V_398 * V_399 , T_4 * V_89 )
{
T_1 * V_10 ;
F_140 ( sizeof( T_4 ) ) ;
F_85 ( V_89 -> V_90 ) ;
F_86 ( & V_89 -> V_91 , sizeof( V_92 ) ) ;
F_141 () ;
}
static T_1
F_142 ( struct V_398 * V_399 , T_1 V_401 , struct V_93 * V_94 )
{
T_1 * V_10 ;
if ( ! V_401 ) {
F_140 ( 8 ) ;
F_85 ( V_94 -> V_586 ) ;
F_85 ( V_94 -> V_587 ) ;
F_141 () ;
}
return V_401 ;
}
static T_1 F_143 ( struct V_398 * V_399 , T_1 V_401 , struct V_96 * V_97 )
{
T_1 * V_10 ;
if ( ! V_401 ) {
F_140 ( V_98 + 8 ) ;
F_86 ( V_97 -> V_99 . V_100 , V_98 ) ;
F_85 ( V_97 -> V_101 ) ;
F_85 ( 0 ) ;
F_141 () ;
}
return V_401 ;
}
static T_1
F_144 ( struct V_398 * V_399 , T_1 V_401 , struct V_102 * V_103 )
{
V_588 ;
if ( ! V_401 )
F_139 ( V_399 , & V_103 -> V_105 ) ;
F_81 ( V_399 , V_400 , V_401 ) ;
return V_401 ;
}
static T_1
F_145 ( struct V_398 * V_399 , T_1 V_401 , struct V_106 * V_107 )
{
T_1 * V_10 ;
if ( ! V_401 ) {
F_140 ( 8 ) ;
F_86 ( V_107 -> V_589 . V_100 , 8 ) ;
F_141 () ;
}
return V_401 ;
}
static T_1
F_146 ( struct V_398 * V_399 , T_1 V_401 , struct V_110 * V_111 )
{
T_1 * V_10 ;
if ( ! V_401 ) {
F_140 ( 32 ) ;
F_80 ( & V_10 , & V_111 -> V_590 ) ;
F_85 ( 2 ) ;
F_85 ( V_111 -> V_125 [ 0 ] ) ;
F_85 ( V_111 -> V_125 [ 1 ] ) ;
F_141 () ;
}
return V_401 ;
}
static T_1
F_147 ( struct V_398 * V_399 , T_1 V_401 , struct V_131 * V_132 )
{
struct V_465 * V_466 = V_132 -> V_591 ;
int V_414 ;
if ( V_401 )
return V_401 ;
V_414 = V_399 -> V_11 - V_399 -> V_10 - ( V_592 >> 2 ) ;
V_401 = F_111 ( V_466 , V_466 -> V_568 , V_466 -> V_569 ,
V_399 -> V_10 , & V_414 , V_132 -> V_133 ,
V_399 -> V_61 , 0 ) ;
if ( ! V_401 )
V_399 -> V_10 += V_414 ;
return V_401 ;
}
static T_1
F_148 ( struct V_398 * V_399 , T_1 V_401 , struct V_465 * * V_593 )
{
struct V_465 * V_466 = * V_593 ;
unsigned int V_2 ;
T_1 * V_10 ;
if ( ! V_401 ) {
V_2 = V_466 -> V_528 . V_529 ;
F_140 ( V_2 + 4 ) ;
F_85 ( V_2 ) ;
F_86 ( & V_466 -> V_528 . V_530 , V_2 ) ;
F_141 () ;
}
return V_401 ;
}
static void
F_149 ( struct V_398 * V_399 , struct V_594 * V_595 )
{
struct V_191 * V_596 = & V_595 -> V_597 ;
T_1 * V_10 ;
F_140 ( 32 + F_150 ( V_596 -> V_2 ) ) ;
F_120 ( V_595 -> V_598 ) ;
F_120 ( V_595 -> V_599 ) ;
F_85 ( V_595 -> V_600 ) ;
if ( V_596 -> V_2 ) {
F_86 ( & V_595 -> V_601 , 8 ) ;
F_85 ( V_596 -> V_2 ) ;
F_86 ( V_596 -> V_100 , V_596 -> V_2 ) ;
F_6 ( V_596 -> V_100 ) ;
} else {
F_120 ( ( T_5 ) 0 ) ;
F_85 ( 0 ) ;
}
F_141 () ;
}
static T_1
F_151 ( struct V_398 * V_399 , T_1 V_401 , struct V_138 * V_139 )
{
V_588 ;
if ( ! V_401 )
F_139 ( V_399 , & V_139 -> V_602 ) ;
else if ( V_401 == V_603 )
F_149 ( V_399 , & V_139 -> V_604 ) ;
F_81 ( V_399 , V_400 , V_401 ) ;
return V_401 ;
}
static T_1
F_152 ( struct V_398 * V_399 , T_1 V_401 , struct V_154 * V_155 )
{
if ( V_401 == V_603 )
F_149 ( V_399 , & V_155 -> V_605 ) ;
return V_401 ;
}
static T_1
F_153 ( struct V_398 * V_399 , T_1 V_401 , struct V_161 * V_162 )
{
V_588 ;
if ( ! V_401 )
F_139 ( V_399 , & V_162 -> V_165 ) ;
F_81 ( V_399 , V_400 , V_401 ) ;
return V_401 ;
}
static T_1
F_154 ( struct V_398 * V_399 , T_1 V_401 , struct V_134 * V_135 )
{
T_1 * V_10 ;
if ( ! V_401 ) {
F_140 ( 20 ) ;
F_80 ( & V_10 , & V_135 -> V_606 ) ;
F_141 () ;
}
return V_401 ;
}
static T_1
F_155 ( struct V_398 * V_399 , T_1 V_401 , struct V_194 * V_195 )
{
T_1 * V_10 ;
V_588 ;
if ( V_401 )
goto V_88;
F_139 ( V_399 , & V_195 -> V_607 ) ;
F_140 ( 40 ) ;
F_80 ( & V_10 , & V_195 -> V_608 ) ;
F_85 ( V_195 -> V_609 ) ;
F_85 ( 2 ) ;
F_85 ( V_195 -> V_196 [ 0 ] ) ;
F_85 ( V_195 -> V_196 [ 1 ] ) ;
F_85 ( V_195 -> V_219 ) ;
F_141 () ;
switch ( V_195 -> V_219 ) {
case V_610 :
break;
case V_611 :
F_139 ( V_399 , & V_195 -> V_221 ) ;
F_140 ( 20 ) ;
F_85 ( V_195 -> V_612 ) ;
F_85 ( V_613 ) ;
F_85 ( 0 ) ;
F_85 ( 0 ) ;
F_85 ( 0 ) ;
F_141 () ;
break;
case V_614 :
F_139 ( V_399 , & V_195 -> V_221 ) ;
F_140 ( 32 ) ;
F_85 ( 0 ) ;
F_85 ( V_615 ) ;
F_85 ( ~ ( T_2 ) 0 ) ;
F_85 ( ~ ( T_2 ) 0 ) ;
F_85 ( V_613 ) ;
F_85 ( 0 ) ;
F_85 ( 0 ) ;
F_85 ( 0 ) ;
F_141 () ;
break;
default:
F_156 () ;
}
V_88:
F_81 ( V_399 , V_400 , V_401 ) ;
return V_401 ;
}
static T_1
F_157 ( struct V_398 * V_399 , T_1 V_401 , struct V_225 * V_616 )
{
V_588 ;
if ( ! V_401 )
F_139 ( V_399 , & V_616 -> V_617 ) ;
F_81 ( V_399 , V_400 , V_401 ) ;
return V_401 ;
}
static T_1
F_158 ( struct V_398 * V_399 , T_1 V_401 , struct V_229 * V_618 )
{
V_588 ;
if ( ! V_401 )
F_139 ( V_399 , & V_618 -> V_231 ) ;
F_81 ( V_399 , V_400 , V_401 ) ;
return V_401 ;
}
static T_1
F_159 ( struct V_398 * V_399 , T_1 V_401 ,
struct V_240 * V_241 )
{
T_2 V_619 ;
int V_295 , V_620 ;
unsigned long V_621 ;
long V_2 ;
T_1 * V_10 ;
if ( V_401 )
return V_401 ;
if ( V_399 -> V_622 -> V_623 )
return V_50 ;
F_140 ( 8 ) ;
V_621 = F_124 ( V_399 -> V_61 ) ;
if ( V_621 > V_241 -> V_244 )
V_621 = V_241 -> V_244 ;
V_2 = V_621 ;
V_295 = 0 ;
while ( V_2 > 0 ) {
V_620 = V_399 -> V_61 -> V_624 ++ ;
V_399 -> V_61 -> V_300 [ V_295 ] . V_301 =
F_8 ( V_399 -> V_61 -> V_625 [ V_620 ] ) ;
V_399 -> V_61 -> V_300 [ V_295 ] . V_302 =
V_2 < V_16 ? V_2 : V_16 ;
V_295 ++ ;
V_2 -= V_16 ;
}
V_241 -> V_626 = V_295 ;
V_401 = F_160 ( V_241 -> V_572 , V_241 -> V_567 , V_241 -> V_627 ,
V_241 -> V_243 , V_399 -> V_61 -> V_300 , V_241 -> V_626 ,
& V_621 ) ;
if ( V_401 )
return V_401 ;
V_619 = ( V_241 -> V_243 + V_621 >=
V_241 -> V_567 -> V_569 -> V_504 -> V_628 ) ;
F_85 ( V_619 ) ;
F_85 ( V_621 ) ;
F_141 () ;
V_399 -> V_622 -> V_629 [ 0 ] . V_302 = ( char * ) V_10
- ( char * ) V_399 -> V_622 -> V_629 [ 0 ] . V_301 ;
V_399 -> V_622 -> V_623 = V_621 ;
V_399 -> V_622 -> V_630 [ 0 ] . V_301 = V_10 ;
V_399 -> V_622 -> V_630 [ 0 ] . V_302 = 0 ;
if ( V_621 & 3 ) {
F_140 ( 4 ) ;
F_85 ( 0 ) ;
V_399 -> V_622 -> V_630 [ 0 ] . V_301 += V_621 & 3 ;
V_399 -> V_622 -> V_630 [ 0 ] . V_302 = 4 - ( V_621 & 3 ) ;
F_141 () ;
}
return 0 ;
}
static T_1
F_161 ( struct V_398 * V_399 , T_1 V_401 , struct V_631 * V_632 )
{
int V_621 ;
char * V_633 ;
T_1 * V_10 ;
if ( V_401 )
return V_401 ;
if ( V_399 -> V_622 -> V_623 )
return V_50 ;
V_633 = F_8 ( V_399 -> V_61 -> V_625 [ V_399 -> V_61 -> V_624 ++ ] ) ;
V_621 = V_16 ;
F_140 ( 4 ) ;
V_401 = F_162 ( V_632 -> V_634 , V_632 -> V_635 , V_633 , & V_621 ) ;
if ( V_401 == V_636 )
return V_5 ;
if ( V_401 )
return V_401 ;
F_85 ( V_621 ) ;
F_141 () ;
V_399 -> V_622 -> V_629 [ 0 ] . V_302 = ( char * ) V_10
- ( char * ) V_399 -> V_622 -> V_629 [ 0 ] . V_301 ;
V_399 -> V_622 -> V_623 = V_621 ;
V_399 -> V_622 -> V_630 [ 0 ] . V_301 = V_10 ;
V_399 -> V_622 -> V_630 [ 0 ] . V_302 = 0 ;
if ( V_621 & 3 ) {
F_140 ( 4 ) ;
F_85 ( 0 ) ;
V_399 -> V_622 -> V_630 [ 0 ] . V_301 += V_621 & 3 ;
V_399 -> V_622 -> V_630 [ 0 ] . V_302 = 4 - ( V_621 & 3 ) ;
F_141 () ;
}
return 0 ;
}
static T_1
F_163 ( struct V_398 * V_399 , T_1 V_401 , struct V_245 * V_246 )
{
int V_621 ;
T_8 V_575 ;
T_1 * V_633 , * V_9 , * V_637 ;
T_1 * V_10 ;
if ( V_401 )
return V_401 ;
if ( V_399 -> V_622 -> V_623 )
return V_50 ;
F_140 ( 8 ) ;
V_9 = V_10 ;
F_85 ( 0 ) ;
F_85 ( 0 ) ;
F_141 () ;
V_399 -> V_622 -> V_629 [ 0 ] . V_302 = ( ( char * ) V_399 -> V_10 ) - ( char * ) V_399 -> V_622 -> V_629 [ 0 ] . V_301 ;
V_637 = V_10 ;
V_621 = V_16 ;
if ( V_621 > V_246 -> V_250 )
V_621 = V_246 -> V_250 ;
V_621 = ( V_621 >> 2 ) - 4 ;
if ( V_621 < 0 ) {
V_401 = V_581 ;
goto V_638;
}
V_633 = F_8 ( V_399 -> V_61 -> V_625 [ V_399 -> V_61 -> V_624 ++ ] ) ;
V_246 -> V_579 . V_3 = 0 ;
V_246 -> V_414 = V_621 ;
V_246 -> V_467 = V_633 ;
V_246 -> V_575 = NULL ;
V_575 = V_246 -> V_247 ;
V_401 = F_164 ( V_246 -> V_572 , V_246 -> V_567 ,
& V_575 ,
& V_246 -> V_579 , F_135 ) ;
if ( V_401 == V_57 &&
V_246 -> V_579 . V_3 == V_581 &&
V_246 -> V_467 == V_633 )
V_401 = V_581 ;
if ( V_401 )
goto V_638;
if ( V_246 -> V_575 )
F_137 ( V_246 -> V_575 , V_575 ) ;
V_10 = V_246 -> V_467 ;
* V_10 ++ = 0 ;
* V_10 ++ = F_125 ( V_246 -> V_579 . V_3 == V_639 ) ;
V_399 -> V_622 -> V_623 = ( ( char * ) V_10 ) - ( char * ) F_8 (
V_399 -> V_61 -> V_625 [ V_399 -> V_61 -> V_624 - 1 ] ) ;
V_399 -> V_622 -> V_630 [ 0 ] . V_301 = V_637 ;
V_399 -> V_622 -> V_630 [ 0 ] . V_302 = 0 ;
V_399 -> V_10 = V_399 -> V_622 -> V_630 [ 0 ] . V_301 ;
V_399 -> V_11 = V_399 -> V_10 + ( V_16 - V_399 -> V_622 -> V_629 [ 0 ] . V_302 ) / 4 ;
return 0 ;
V_638:
V_10 = V_9 ;
F_141 () ;
return V_401 ;
}
static T_1
F_165 ( struct V_398 * V_399 , T_1 V_401 , struct V_252 * remove )
{
T_1 * V_10 ;
if ( ! V_401 ) {
F_140 ( 20 ) ;
F_80 ( & V_10 , & remove -> V_640 ) ;
F_141 () ;
}
return V_401 ;
}
static T_1
F_166 ( struct V_398 * V_399 , T_1 V_401 , struct V_255 * rename )
{
T_1 * V_10 ;
if ( ! V_401 ) {
F_140 ( 40 ) ;
F_80 ( & V_10 , & rename -> V_641 ) ;
F_80 ( & V_10 , & rename -> V_642 ) ;
F_141 () ;
}
return V_401 ;
}
static T_1
F_167 ( struct V_398 * V_399 ,
T_1 V_401 , struct V_433 * exp )
{
int V_4 = 0 ;
T_2 V_643 ;
struct V_644 * V_645 ;
struct V_644 V_646 [ 2 ] ;
T_1 * V_10 ;
if ( V_401 )
goto V_88;
if ( exp -> V_647 ) {
V_645 = exp -> V_648 ;
V_643 = exp -> V_647 ;
} else {
V_645 = V_646 ;
if ( exp -> V_649 -> V_650 -> V_650 == V_335 ) {
V_643 = 2 ;
V_645 [ 0 ] . V_651 = V_335 ;
V_645 [ 1 ] . V_651 = V_334 ;
} else if ( exp -> V_649 -> V_650 -> V_650 == V_338 ) {
V_643 = 1 ;
V_645 [ 0 ] . V_651
= F_168 ( exp -> V_649 ) ;
} else {
V_643 = 1 ;
V_645 [ 0 ] . V_651
= exp -> V_649 -> V_650 -> V_650 ;
}
}
F_140 ( 4 ) ;
F_85 ( V_643 ) ;
F_141 () ;
for ( V_4 = 0 ; V_4 < V_643 ; V_4 ++ ) {
T_2 V_652 = V_645 [ V_4 ] . V_651 ;
struct V_653 * V_654 = F_169 ( V_652 ) ;
if ( V_654 ) {
F_140 ( 4 ) ;
F_85 ( V_338 ) ;
F_141 () ;
F_140 ( 4 + V_654 -> V_655 . V_2 ) ;
F_85 ( V_654 -> V_655 . V_2 ) ;
F_86 ( V_654 -> V_655 . V_100 , V_654 -> V_655 . V_2 ) ;
F_141 () ;
F_140 ( 4 ) ;
F_85 ( 0 ) ;
F_141 () ;
F_140 ( 4 ) ;
F_85 ( F_170 ( V_654 , V_652 ) ) ;
F_141 () ;
F_171 ( V_654 ) ;
} else {
F_140 ( 4 ) ;
F_85 ( V_652 ) ;
F_141 () ;
}
}
V_88:
if ( exp )
F_99 ( exp ) ;
return V_401 ;
}
static T_1
F_172 ( struct V_398 * V_399 , T_1 V_401 ,
struct V_261 * V_262 )
{
return F_167 ( V_399 , V_401 , V_262 -> V_656 ) ;
}
static T_1
F_173 ( struct V_398 * V_399 , T_1 V_401 ,
struct V_265 * V_262 )
{
return F_167 ( V_399 , V_401 , V_262 -> V_657 ) ;
}
static T_1
F_174 ( struct V_398 * V_399 , T_1 V_401 , struct V_267 * V_268 )
{
T_1 * V_10 ;
F_140 ( 12 ) ;
if ( V_401 ) {
F_85 ( 2 ) ;
F_85 ( 0 ) ;
F_85 ( 0 ) ;
}
else {
F_85 ( 2 ) ;
F_85 ( V_268 -> V_270 [ 0 ] ) ;
F_85 ( V_268 -> V_270 [ 1 ] ) ;
}
F_141 () ;
return V_401 ;
}
static T_1
F_175 ( struct V_398 * V_399 , T_1 V_401 , struct V_273 * V_658 )
{
T_1 * V_10 ;
if ( ! V_401 ) {
F_140 ( 8 + sizeof( V_285 ) ) ;
F_86 ( & V_658 -> V_659 , 8 ) ;
F_86 ( & V_658 -> V_660 , sizeof( V_285 ) ) ;
F_141 () ;
}
else if ( V_401 == V_661 ) {
F_140 ( 8 ) ;
F_85 ( 0 ) ;
F_85 ( 0 ) ;
F_141 () ;
}
return V_401 ;
}
static T_1
F_176 ( struct V_398 * V_399 , T_1 V_401 , struct V_293 * V_294 )
{
T_1 * V_10 ;
if ( ! V_401 ) {
F_140 ( 16 ) ;
F_85 ( V_294 -> V_662 ) ;
F_85 ( V_294 -> V_663 ) ;
F_86 ( V_294 -> V_664 . V_100 , 8 ) ;
F_141 () ;
}
return V_401 ;
}
static T_1
F_177 ( struct V_398 * V_399 , int V_401 ,
struct V_308 * V_309 )
{
T_1 * V_10 ;
char * V_665 ;
char * V_666 ;
int V_667 ;
int V_668 ;
T_9 V_669 = 0 ;
if ( V_401 )
return V_401 ;
V_665 = F_178 () -> V_670 ;
V_667 = strlen ( V_665 ) ;
V_666 = F_178 () -> V_670 ;
V_668 = strlen ( V_666 ) ;
F_140 (
8 +
4 +
4 +
4 +
8 +
4 +
( F_9 ( V_667 ) * 4 ) +
4 +
( F_9 ( V_668 ) * 4 ) +
4 ) ;
F_86 ( & V_309 -> V_260 , 8 ) ;
F_85 ( V_309 -> V_323 ) ;
F_85 ( V_309 -> V_314 ) ;
F_14 ( V_309 -> V_315 != V_316 ) ;
F_85 ( V_309 -> V_315 ) ;
F_120 ( V_669 ) ;
F_85 ( V_667 ) ;
F_86 ( V_665 , V_667 ) ;
F_85 ( V_668 ) ;
F_86 ( V_666 , V_668 ) ;
F_85 ( 0 ) ;
F_141 () ;
return 0 ;
}
static T_1
F_179 ( struct V_398 * V_399 , int V_401 ,
struct V_319 * V_320 )
{
T_1 * V_10 ;
if ( V_401 )
return V_401 ;
F_140 ( 24 ) ;
F_86 ( V_320 -> V_99 . V_100 , V_98 ) ;
F_85 ( V_320 -> V_323 ) ;
F_85 ( V_320 -> V_314 ) ;
F_141 () ;
F_140 ( 28 ) ;
F_85 ( 0 ) ;
F_85 ( V_320 -> V_324 . V_325 ) ;
F_85 ( V_320 -> V_324 . V_326 ) ;
F_85 ( V_320 -> V_324 . V_327 ) ;
F_85 ( V_320 -> V_324 . V_328 ) ;
F_85 ( V_320 -> V_324 . V_329 ) ;
F_85 ( V_320 -> V_324 . V_330 ) ;
F_141 () ;
if ( V_320 -> V_324 . V_330 ) {
F_140 ( 4 ) ;
F_85 ( V_320 -> V_324 . V_331 ) ;
F_141 () ;
}
F_140 ( 28 ) ;
F_85 ( 0 ) ;
F_85 ( V_320 -> V_332 . V_325 ) ;
F_85 ( V_320 -> V_332 . V_326 ) ;
F_85 ( V_320 -> V_332 . V_327 ) ;
F_85 ( V_320 -> V_332 . V_328 ) ;
F_85 ( V_320 -> V_332 . V_329 ) ;
F_85 ( V_320 -> V_332 . V_330 ) ;
F_141 () ;
if ( V_320 -> V_332 . V_330 ) {
F_140 ( 4 ) ;
F_85 ( V_320 -> V_332 . V_331 ) ;
F_141 () ;
}
return 0 ;
}
static T_1
F_180 ( struct V_398 * V_399 , int V_401 ,
struct V_339 * V_340 )
{
return V_401 ;
}
static T_1
F_181 ( struct V_398 * V_399 , int V_401 ,
struct V_341 * V_342 )
{
T_1 * V_10 ;
if ( V_401 )
return V_401 ;
F_140 ( 4 ) ;
F_85 ( V_401 ) ;
F_141 () ;
return V_401 ;
}
static T_1
F_182 ( struct V_398 * V_399 , int V_401 ,
struct V_344 * V_345 )
{
T_1 * V_10 ;
if ( V_401 )
return V_401 ;
F_140 ( V_98 + 20 ) ;
F_86 ( V_345 -> V_99 . V_100 , V_98 ) ;
F_85 ( V_345 -> V_323 ) ;
F_85 ( V_345 -> V_346 ) ;
F_85 ( V_345 -> V_347 - 1 ) ;
F_85 ( V_345 -> V_347 - 1 ) ;
F_85 ( V_345 -> V_671 ) ;
F_141 () ;
V_399 -> V_404 . V_672 = V_10 ;
return 0 ;
}
T_1
F_183 ( struct V_398 * V_399 , int V_401 ,
struct V_349 * V_350 )
{
struct V_6 * V_7 ;
struct V_673 * V_674 = V_399 -> V_404 . V_675 -> V_676 ;
T_4 V_351 ;
T_1 * V_10 ;
int V_4 ;
int V_677 ;
F_4 ( V_350 -> V_353 , & V_350 -> V_354 ) ;
V_7 = V_350 -> V_353 ;
F_140 ( 4 ) ;
* V_10 ++ = F_125 ( V_350 -> V_352 ) ;
V_399 -> V_10 = V_10 ;
F_184 () ;
for ( V_4 = 0 ; V_4 < V_350 -> V_352 ; V_4 ++ ) {
F_26 ( V_7 , & V_351 ) ;
V_677 = F_185 ( V_674 , & V_351 ) ;
F_140 ( 4 ) ;
* V_10 ++ = F_125 ( V_677 ) ;
V_399 -> V_10 = V_10 ;
}
F_186 () ;
return V_401 ;
}
static T_1
F_187 ( struct V_398 * V_399 , T_1 V_401 , void * V_10 )
{
return V_401 ;
}
int F_188 ( struct V_398 * V_399 , T_2 V_678 )
{
struct V_679 * V_680 = & V_399 -> V_61 -> V_681 ;
struct V_682 * V_675 = NULL ;
struct V_683 * V_684 = V_399 -> V_404 . V_684 ;
T_2 V_685 , V_686 = 0 ;
if ( ! F_189 ( & V_399 -> V_404 ) )
return 0 ;
V_675 = V_399 -> V_404 . V_675 ;
if ( V_675 == NULL )
return 0 ;
if ( V_680 -> V_623 == 0 ) {
V_685 = ( char * ) V_399 -> V_10 - ( char * ) V_680 -> V_629 [ 0 ] . V_301 + V_678 ;
} else {
if ( V_680 -> V_630 [ 0 ] . V_301 && V_680 -> V_630 [ 0 ] . V_302 > 0 )
V_686 = ( char * ) V_399 -> V_10 - ( char * ) V_680 -> V_630 [ 0 ] . V_301 ;
V_685 = V_680 -> V_629 [ 0 ] . V_302 + V_680 -> V_623 + V_686 + V_678 ;
}
F_60 ( L_12 , V_687 ,
V_685 , V_680 -> V_623 , V_686 , V_678 ) ;
if ( V_685 > V_675 -> V_688 . V_326 )
return V_689 ;
if ( V_684 -> V_690 == 1 &&
V_685 > V_675 -> V_688 . V_327 )
return V_691 ;
return 0 ;
}
void
F_190 ( struct V_398 * V_399 , struct V_361 * V_362 )
{
T_1 * V_692 ;
T_1 * V_10 ;
F_140 ( 8 ) ;
F_85 ( V_362 -> V_372 ) ;
V_692 = V_10 ++ ;
F_141 () ;
if ( V_362 -> V_372 == V_378 )
goto V_41;
F_14 ( V_362 -> V_372 < 0 || V_362 -> V_372 >= F_74 ( V_693 ) ||
! V_693 [ V_362 -> V_372 ] ) ;
V_362 -> V_41 = V_693 [ V_362 -> V_372 ] ( V_399 , V_362 -> V_41 , & V_362 -> V_377 ) ;
if ( ! V_362 -> V_41 )
V_362 -> V_41 = F_188 ( V_399 , 0 ) ;
V_41:
* V_692 = V_362 -> V_41 ;
}
void
F_191 ( struct V_398 * V_399 , struct V_361 * V_362 )
{
T_1 * V_10 ;
struct V_694 * V_695 = V_362 -> V_371 ;
F_14 ( ! V_695 ) ;
F_140 ( 8 ) ;
F_85 ( V_362 -> V_372 ) ;
* V_10 ++ = V_695 -> V_408 ;
F_141 () ;
F_140 ( V_695 -> V_409 ) ;
F_86 ( V_695 -> V_410 , V_695 -> V_409 ) ;
F_141 () ;
}
int
F_192 ( struct V_432 * V_61 , T_1 * V_10 , void * V_310 )
{
return F_193 ( V_61 , V_10 ) ;
}
int F_194 ( void * V_696 , T_1 * V_10 , void * V_399 )
{
struct V_432 * V_61 = V_696 ;
struct V_6 * args = V_61 -> V_697 ;
if ( args -> V_364 != args -> V_369 ) {
F_6 ( args -> V_364 ) ;
args -> V_364 = args -> V_369 ;
}
F_6 ( args -> V_18 ) ;
args -> V_18 = NULL ;
while ( args -> V_28 ) {
struct V_23 * V_24 = args -> V_28 ;
args -> V_28 = V_24 -> V_27 ;
V_24 -> F_12 ( V_24 -> V_26 ) ;
F_6 ( V_24 ) ;
}
return 1 ;
}
int
F_195 ( struct V_432 * V_61 , T_1 * V_10 , struct V_6 * args )
{
args -> V_10 = V_10 ;
args -> V_11 = V_61 -> V_698 . V_629 [ 0 ] . V_301 + V_61 -> V_698 . V_629 [ 0 ] . V_302 ;
args -> V_13 = V_61 -> V_698 . V_699 ;
args -> V_12 = V_61 -> V_698 . V_623 ;
args -> V_18 = NULL ;
args -> V_28 = NULL ;
args -> V_364 = args -> V_369 ;
args -> V_61 = V_61 ;
return ! F_73 ( args ) ;
}
int
F_196 ( struct V_432 * V_61 , T_1 * V_10 , struct V_398 * V_399 )
{
struct V_700 * V_701 = & V_399 -> V_404 ;
struct V_702 * V_703 ;
V_10 = V_399 -> V_704 ;
* V_10 ++ = F_125 ( V_399 -> V_365 ) ;
memcpy ( V_10 , V_399 -> V_366 , V_399 -> V_365 ) ;
V_10 += F_9 ( V_399 -> V_365 ) ;
* V_10 ++ = F_125 ( V_399 -> V_367 ) ;
if ( V_61 -> V_681 . V_623 )
V_703 = & V_61 -> V_681 . V_630 [ 0 ] ;
else
V_703 = & V_61 -> V_681 . V_629 [ 0 ] ;
V_703 -> V_302 = ( ( char * ) V_399 -> V_10 ) - ( char * ) V_703 -> V_301 ;
F_14 ( V_703 -> V_302 > V_16 ) ;
if ( F_189 ( V_701 ) ) {
if ( V_701 -> V_41 != V_705 ) {
F_197 ( V_399 ) ;
F_60 ( L_13 , V_687 ) ;
V_701 -> V_684 -> V_706 = false ;
}
F_198 ( V_701 -> V_675 ) ;
F_199 ( V_701 -> V_675 ) ;
}
return 1 ;
}
