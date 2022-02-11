static void
F_1 ( struct V_1 * V_2 , T_1 V_3 ,
const struct V_4 * V_5 )
{
struct V_6 * V_7 = (struct V_6 * ) V_2 ;
char * V_8 = ( char * ) V_2 ;
T_2 V_9 = V_10 [ F_2 ( V_3 ) ] ;
memset ( V_8 , 0 , 256 ) ;
V_2 -> V_11 = F_3 ( V_9 + sizeof( struct V_1 )
- 4 ) ;
V_2 -> V_12 = V_13 ;
V_2 -> V_14 = F_4 ( 64 ) ;
V_2 -> V_15 = V_3 ;
V_2 -> V_16 = F_4 ( 2 ) ;
V_2 -> V_17 = F_5 ( ( T_2 ) V_18 -> V_19 ) ;
if ( ! V_5 )
goto V_20;
if ( ( V_5 -> V_21 ) && ( V_5 -> V_21 -> V_22 ) &&
( V_5 -> V_21 -> V_22 -> V_23 & V_24 ) )
V_2 -> V_25 = F_4 ( 1 ) ;
V_2 -> V_26 = V_5 -> V_27 ;
if ( V_5 -> V_21 )
V_2 -> V_28 = V_5 -> V_21 -> V_29 ;
if ( V_5 -> V_21 && V_5 -> V_21 -> V_22 && V_5 -> V_21 -> V_22 -> V_30 )
V_2 -> V_31 |= V_32 ;
V_20:
V_7 -> V_33 = F_4 ( V_9 ) ;
return;
}
static int
F_6 ( T_1 V_34 , struct V_4 * V_5 )
{
int V_35 = 0 ;
struct V_36 * V_37 ;
struct V_38 * V_21 ;
struct V_39 * V_22 ;
if ( V_5 == NULL )
return V_35 ;
if ( V_34 == V_40 )
return V_35 ;
if ( V_5 -> V_41 == V_42 ) {
if ( ( V_34 != V_43 ) &&
( V_34 != V_44 ) &&
( V_34 != V_45 ) ) {
F_7 ( V_46 , L_1 ,
V_34 ) ;
return - V_47 ;
}
}
if ( ( ! V_5 -> V_21 ) || ( V_5 -> V_21 -> V_48 == V_42 ) ||
( ! V_5 -> V_21 -> V_22 ) )
return - V_49 ;
V_21 = V_5 -> V_21 ;
V_22 = V_21 -> V_22 ;
while ( V_22 -> V_50 == V_51 ) {
switch ( V_34 ) {
case V_45 :
case V_52 :
case V_53 :
case V_54 :
return - V_55 ;
}
F_8 ( V_22 -> V_56 ,
( V_22 -> V_50 != V_51 ) , 10 * V_57 ) ;
if ( V_22 -> V_50 != V_51 )
break;
if ( ! V_5 -> V_58 ) {
F_7 ( V_46 , L_2 ) ;
return - V_59 ;
}
}
if ( ! V_5 -> V_21 -> V_60 && ! V_5 -> V_60 )
return V_35 ;
V_37 = F_9 () ;
F_10 ( & V_5 -> V_21 -> V_61 ) ;
V_35 = F_11 ( 0 , V_5 -> V_21 ) ;
if ( ! V_35 && V_5 -> V_21 -> V_60 )
V_35 = F_12 ( 0 , V_5 -> V_21 , V_37 ) ;
if ( V_35 || ! V_5 -> V_60 ) {
F_13 ( & V_5 -> V_21 -> V_61 ) ;
goto V_20;
}
F_14 ( V_5 ) ;
V_35 = F_15 ( 0 , V_5 -> V_21 , V_5 -> V_62 , V_5 , V_37 ) ;
F_13 ( & V_5 -> V_21 -> V_61 ) ;
F_7 ( V_46 , L_3 , V_35 ) ;
if ( V_35 )
goto V_20;
F_16 ( & V_63 ) ;
V_20:
switch ( V_34 ) {
case V_64 :
case V_65 :
case V_43 :
case V_66 :
case V_67 :
case V_68 :
case V_69 :
case V_70 :
case V_71 :
return - V_55 ;
}
F_17 ( V_37 ) ;
return V_35 ;
}
static int
F_18 ( T_1 V_34 , struct V_4 * V_5 ,
void * * V_72 )
{
int V_35 = 0 ;
V_35 = F_6 ( V_34 , V_5 ) ;
if ( V_35 )
return V_35 ;
* V_72 = F_19 () ;
if ( * V_72 == NULL ) {
return - V_73 ;
}
F_1 ( (struct V_1 * ) * V_72 , V_34 , V_5 ) ;
if ( V_5 != NULL ) {
#ifdef F_20
T_3 V_74 = F_2 ( V_34 ) ;
F_21 ( & V_5 -> V_75 . V_76 . V_77 [ V_74 ] ) ;
#endif
F_21 ( & V_5 -> V_78 ) ;
}
return V_35 ;
}
static void
F_22 ( struct V_79 * V_80 )
{
V_80 -> V_81 = V_82 ;
V_80 -> V_83 = F_4 ( 38 ) ;
V_80 -> V_84 = F_4 ( 1 ) ;
V_80 -> V_85 = F_4 ( V_86 ) ;
F_23 ( V_80 -> V_87 , V_86 ) ;
V_80 -> V_88 = V_89 ;
}
static void
F_24 ( struct V_90 * V_80 )
{
V_80 -> V_81 = V_91 ;
V_80 -> V_83 = F_4 ( 6 ) ;
V_80 -> V_92 = F_4 ( 2 ) ;
V_80 -> V_93 [ 0 ] = V_94 ;
V_80 -> V_93 [ 1 ] = V_95 ;
}
static void
F_25 ( struct V_96 * V_97 )
{
char * V_80 = ( char * ) V_97 + V_98 + 4 ;
F_22 ( (struct V_79 * ) V_80 ) ;
V_80 += 2 + sizeof( struct V_79 ) ;
F_24 ( (struct V_90 * ) V_80 ) ;
V_97 -> V_99 = F_5 ( V_98 ) ;
V_97 -> V_100 = F_4 ( 2 ) ;
F_26 ( V_97 , 4 + sizeof( struct V_79 ) + 2
+ sizeof( struct V_90 ) ) ;
}
static void F_25 ( struct V_96 * V_97 )
{
return;
}
int
F_27 ( const unsigned int V_101 , struct V_38 * V_21 )
{
struct V_96 * V_97 ;
struct V_102 * V_103 ;
struct V_104 V_105 [ 1 ] ;
int V_35 = 0 ;
int V_106 ;
struct V_39 * V_22 = V_21 -> V_22 ;
int V_107 , V_108 ;
char * V_109 ;
int V_110 = V_111 ;
F_7 ( V_46 , L_4 ) ;
if ( ! V_22 ) {
F_28 ( 1 , L_5 , V_112 ) ;
return - V_49 ;
}
V_35 = F_18 ( V_113 , NULL , ( void * * ) & V_97 ) ;
if ( V_35 )
return V_35 ;
V_97 -> V_2 . V_28 = 0 ;
V_97 -> V_114 [ 0 ] = F_4 ( V_21 -> V_22 -> V_115 -> V_116 ) ;
V_97 -> V_117 = F_4 ( 1 ) ;
F_26 ( V_97 , 2 ) ;
if ( V_21 -> V_30 )
V_97 -> V_118 = F_4 ( V_119 ) ;
else if ( V_120 & V_121 )
V_97 -> V_118 = F_4 ( V_122 ) ;
else
V_97 -> V_118 = 0 ;
V_97 -> V_123 = F_5 ( V_21 -> V_22 -> V_115 -> V_124 ) ;
if ( V_21 -> V_22 -> V_115 -> V_116 == V_125 )
memset ( V_97 -> V_126 , 0 , V_127 ) ;
else {
memcpy ( V_97 -> V_126 , V_22 -> V_128 ,
V_127 ) ;
if ( V_21 -> V_22 -> V_115 -> V_116 == V_129 )
F_25 ( V_97 ) ;
}
V_105 [ 0 ] . V_130 = ( char * ) V_97 ;
V_105 [ 0 ] . V_131 = F_29 ( V_97 ) + 4 ;
V_35 = F_30 ( V_101 , V_21 , V_105 , 1 , & V_106 , V_110 ) ;
V_103 = (struct V_102 * ) V_105 [ 0 ] . V_130 ;
if ( V_35 != 0 )
goto V_132;
F_7 ( V_46 , L_6 , V_103 -> V_118 ) ;
if ( V_103 -> V_133 == F_4 ( V_125 ) )
F_7 ( V_46 , L_7 ) ;
else if ( V_103 -> V_133 == F_4 ( V_134 ) )
F_7 ( V_46 , L_8 ) ;
else if ( V_103 -> V_133 == F_4 ( V_135 ) )
F_7 ( V_46 , L_9 ) ;
else if ( V_103 -> V_133 == F_4 ( V_136 ) )
F_7 ( V_46 , L_10 ) ;
#ifdef F_31
else if ( V_103 -> V_133 == F_4 ( V_129 ) )
F_7 ( V_46 , L_11 ) ;
#endif
else {
F_7 ( V_137 , L_12 ,
F_2 ( V_103 -> V_133 ) ) ;
V_35 = - V_49 ;
goto V_132;
}
V_22 -> V_138 = F_2 ( V_103 -> V_133 ) ;
V_22 -> V_139 = V_140 ;
V_22 -> V_141 = F_32 (unsigned int, le32_to_cpu(rsp->MaxTransactSize),
SMB2_MAX_BUFFER_SIZE) ;
V_22 -> V_142 = F_33 ( V_103 -> V_143 ) ;
V_22 -> V_144 = F_33 ( V_103 -> V_145 ) ;
V_22 -> V_146 = F_2 ( V_103 -> V_118 ) ;
V_22 -> V_23 = F_33 ( V_103 -> V_123 ) ;
V_22 -> V_23 |= V_147 | V_148 ;
V_109 = F_34 ( & V_107 , & V_108 ,
& V_103 -> V_2 ) ;
if ( V_108 == 0 )
F_7 ( V_46 , L_13 ) ;
V_35 = F_35 ( V_22 , V_21 -> V_30 ) ;
if ( V_35 )
goto V_132;
if ( V_108 ) {
V_35 = F_36 ( V_109 , V_108 , V_22 ) ;
if ( V_35 == 1 )
V_35 = 0 ;
else if ( V_35 == 0 )
V_35 = - V_49 ;
}
V_132:
F_37 ( V_106 , V_103 ) ;
return V_35 ;
}
int F_38 ( const unsigned int V_101 , struct V_4 * V_5 )
{
int V_35 = 0 ;
struct V_149 V_150 ;
struct V_151 * V_152 ;
T_4 V_153 ;
F_7 ( V_46 , L_14 ) ;
if ( V_5 -> V_21 -> V_22 -> V_30 == false )
return 0 ;
V_150 . V_123 =
F_5 ( V_5 -> V_21 -> V_22 -> V_115 -> V_124 ) ;
memcpy ( V_150 . V_154 , V_5 -> V_21 -> V_22 -> V_128 ,
V_127 ) ;
if ( V_5 -> V_21 -> V_30 )
V_150 . V_118 =
F_4 ( V_119 ) ;
else if ( V_120 & V_121 )
V_150 . V_118 =
F_4 ( V_122 ) ;
else
V_150 . V_118 = 0 ;
V_150 . V_117 = F_4 ( 1 ) ;
V_150 . V_114 [ 0 ] =
F_4 ( V_5 -> V_21 -> V_22 -> V_115 -> V_116 ) ;
V_35 = F_39 ( V_101 , V_5 , V_155 , V_155 ,
V_156 , true ,
( char * ) & V_150 , sizeof( struct V_149 ) ,
( char * * ) & V_152 , & V_153 ) ;
if ( V_35 != 0 ) {
F_7 ( V_137 , L_15 , V_35 ) ;
return - V_49 ;
}
if ( V_153 != sizeof( struct V_151 ) ) {
F_7 ( V_137 , L_16 ) ;
return - V_49 ;
}
if ( V_152 -> V_157 !=
F_4 ( V_5 -> V_21 -> V_22 -> V_115 -> V_116 ) )
goto V_158;
if ( V_152 -> V_118 != F_4 ( V_5 -> V_21 -> V_22 -> V_146 ) )
goto V_158;
if ( ( F_33 ( V_152 -> V_123 ) | V_147 |
V_148 ) != V_5 -> V_21 -> V_22 -> V_23 )
goto V_158;
F_7 ( V_46 , L_17 ) ;
return 0 ;
V_158:
F_7 ( V_137 , L_18 ) ;
return - V_49 ;
}
int
F_40 ( const unsigned int V_101 , struct V_38 * V_21 ,
const struct V_36 * V_159 )
{
struct V_160 * V_97 ;
struct V_161 * V_103 = NULL ;
struct V_104 V_105 [ 2 ] ;
int V_35 = 0 ;
int V_106 = V_162 ;
T_5 V_163 = V_164 ;
struct V_39 * V_22 = V_21 -> V_22 ;
T_6 V_108 = 0 ;
struct V_165 * V_166 = NULL ;
char * V_109 = NULL ;
unsigned char * V_167 = NULL ;
bool V_168 = false ;
F_7 ( V_46 , L_19 ) ;
if ( ! V_22 ) {
F_28 ( 1 , L_5 , V_112 ) ;
return - V_49 ;
}
F_41 ( V_21 -> V_169 . V_170 ) ;
V_21 -> V_169 . V_170 = NULL ;
V_21 -> V_171 = F_42 ( sizeof( struct V_172 ) , V_173 ) ;
if ( ! V_21 -> V_171 )
return - V_73 ;
V_21 -> V_171 -> V_174 = true ;
if ( V_21 -> V_175 != V_176 && V_21 -> V_175 != V_177 )
V_21 -> V_175 = V_177 ;
V_178:
if ( V_163 == V_179 )
V_163 = V_180 ;
V_35 = F_18 ( V_181 , NULL , ( void * * ) & V_97 ) ;
if ( V_35 )
return V_35 ;
V_97 -> V_2 . V_28 = 0 ;
V_97 -> V_31 = 0 ;
V_97 -> V_2 . V_16 = F_4 ( 3 ) ;
if ( V_22 -> V_30 )
V_97 -> V_118 = V_119 ;
else if ( V_120 & V_121 )
V_97 -> V_118 = V_122 ;
else
V_97 -> V_118 = 0 ;
V_97 -> V_123 = 0 ;
V_97 -> V_182 = 0 ;
V_105 [ 0 ] . V_130 = ( char * ) V_97 ;
V_105 [ 0 ] . V_131 = F_29 ( V_97 ) + 4 - 1 ;
if ( V_21 -> V_175 == V_176 ) {
#ifdef F_43
struct V_183 * V_184 ;
V_166 = F_44 ( V_21 ) ;
if ( F_45 ( V_166 ) ) {
V_35 = F_46 ( V_166 ) ;
V_166 = NULL ;
goto V_185;
}
V_184 = V_166 -> V_186 . V_187 [ 0 ] ;
if ( V_184 -> V_188 != V_189 ) {
F_7 ( V_137 ,
L_20 ,
V_189 , V_184 -> V_188 ) ;
V_35 = - V_190 ;
goto V_185;
}
V_21 -> V_169 . V_170 = F_47 ( V_184 -> V_187 , V_184 -> V_191 ,
V_173 ) ;
if ( ! V_21 -> V_169 . V_170 ) {
F_7 ( V_137 ,
L_21 ,
V_184 -> V_191 ) ;
V_35 = - V_73 ;
goto V_185;
}
V_21 -> V_169 . V_192 = V_184 -> V_191 ;
V_108 = V_184 -> V_193 ;
V_105 [ 1 ] . V_130 = V_184 -> V_187 + V_184 -> V_191 ;
V_105 [ 1 ] . V_131 = V_108 ;
#else
V_35 = - V_194 ;
goto V_185;
#endif
} else if ( V_163 == V_164 ) {
V_167 = F_42 ( sizeof( struct V_195 ) ,
V_173 ) ;
if ( V_167 == NULL ) {
V_35 = - V_73 ;
goto V_185;
}
F_48 ( V_167 , V_21 ) ;
if ( V_168 ) {
F_7 ( V_137 , L_22 ) ;
V_35 = - V_194 ;
F_41 ( V_167 ) ;
goto V_185;
} else {
V_108 = sizeof( struct V_195 ) ;
V_109 = V_167 ;
}
V_105 [ 1 ] . V_130 = V_109 ;
V_105 [ 1 ] . V_131 = V_108 ;
} else if ( V_163 == V_180 ) {
V_97 -> V_2 . V_28 = V_21 -> V_29 ;
V_35 = F_49 ( & V_167 , & V_108 , V_21 ,
V_159 ) ;
if ( V_35 ) {
F_7 ( V_46 , L_23 ,
V_35 ) ;
goto V_185;
}
if ( V_168 ) {
F_7 ( V_137 , L_22 ) ;
V_35 = - V_194 ;
F_41 ( V_167 ) ;
goto V_185;
} else {
V_109 = V_167 ;
}
V_105 [ 1 ] . V_130 = V_109 ;
V_105 [ 1 ] . V_131 = V_108 ;
} else {
F_7 ( V_137 , L_24 ) ;
V_35 = - V_49 ;
goto V_185;
}
V_97 -> V_196 =
F_4 ( sizeof( struct V_160 ) -
1 - 4 ) ;
V_97 -> V_197 = F_4 ( V_108 ) ;
F_26 ( V_97 , V_108 - 1 ) ;
V_35 = F_30 ( V_101 , V_21 , V_105 , 2 , & V_106 ,
V_198 | V_111 ) ;
F_41 ( V_109 ) ;
V_103 = (struct V_161 * ) V_105 [ 0 ] . V_130 ;
V_21 -> V_29 = V_103 -> V_2 . V_28 ;
if ( V_106 != V_162 &&
V_103 -> V_2 . V_199 == V_200 ) {
if ( V_163 != V_164 ) {
F_7 ( V_137 , L_25 ) ;
goto V_185;
}
if ( F_50 ( struct V_161 , V_201 ) - 4 !=
F_2 ( V_103 -> V_196 ) ) {
F_7 ( V_137 , L_26 ,
F_2 ( V_103 -> V_196 ) ) ;
V_35 = - V_49 ;
goto V_185;
}
V_163 = V_179 ;
V_35 = 0 ;
V_35 = F_51 ( V_103 -> V_201 ,
F_2 ( V_103 -> V_197 ) , V_21 ) ;
}
if ( V_35 != 0 )
goto V_185;
V_21 -> V_202 = F_2 ( V_103 -> V_203 ) ;
if ( V_21 -> V_202 & V_204 )
F_7 ( V_137 , L_27 ) ;
V_185:
F_37 ( V_106 , V_103 ) ;
if ( ( V_163 == V_179 ) && ( V_35 == 0 ) )
goto V_178;
if ( ! V_35 ) {
F_10 ( & V_22 -> V_205 ) ;
if ( V_22 -> V_30 && V_22 -> V_206 -> V_207 ) {
V_35 = V_22 -> V_206 -> V_207 ( V_21 ) ;
F_41 ( V_21 -> V_169 . V_170 ) ;
V_21 -> V_169 . V_170 = NULL ;
if ( V_35 ) {
F_7 ( V_46 ,
L_28 ) ;
F_13 ( & V_22 -> V_205 ) ;
goto V_208;
}
}
if ( ! V_22 -> V_209 ) {
V_22 -> V_210 = 0x2 ;
V_22 -> V_209 = true ;
}
F_13 ( & V_22 -> V_205 ) ;
F_7 ( V_46 , L_29 ) ;
F_52 ( & V_211 ) ;
V_21 -> V_48 = V_212 ;
V_21 -> V_60 = false ;
F_53 ( & V_211 ) ;
}
V_208:
if ( ! V_22 -> V_30 ) {
F_41 ( V_21 -> V_169 . V_170 ) ;
V_21 -> V_169 . V_170 = NULL ;
}
if ( V_166 ) {
F_54 ( V_166 ) ;
F_55 ( V_166 ) ;
}
F_41 ( V_21 -> V_171 ) ;
return V_35 ;
}
int
F_56 ( const unsigned int V_101 , struct V_38 * V_21 )
{
struct V_213 * V_97 ;
int V_35 = 0 ;
struct V_39 * V_22 ;
F_7 ( V_46 , L_30 , V_21 ) ;
if ( V_21 && ( V_21 -> V_22 ) )
V_22 = V_21 -> V_22 ;
else
return - V_49 ;
if ( V_21 -> V_60 )
goto V_214;
V_35 = F_18 ( V_215 , NULL , ( void * * ) & V_97 ) ;
if ( V_35 )
return V_35 ;
V_97 -> V_2 . V_28 = V_21 -> V_29 ;
if ( V_22 -> V_30 )
V_97 -> V_2 . V_31 |= V_32 ;
V_35 = F_57 ( V_101 , V_21 , ( char * ) & V_97 -> V_2 , 0 ) ;
V_214:
return V_35 ;
}
static inline void F_58 ( struct V_4 * V_5 , T_3 V_216 )
{
F_21 ( & V_5 -> V_75 . V_76 . V_217 [ V_216 ] ) ;
}
static inline void F_59 ( struct V_4 * V_5 )
{
V_5 -> V_218 = 256 ;
V_5 -> V_219 = 1048576 ;
V_5 -> V_220 = 16777216 ;
}
int
F_15 ( const unsigned int V_101 , struct V_38 * V_21 , const char * V_221 ,
struct V_4 * V_5 , const struct V_36 * V_222 )
{
struct V_223 * V_97 ;
struct V_224 * V_103 = NULL ;
struct V_104 V_105 [ 2 ] ;
int V_35 = 0 ;
int V_106 ;
int V_225 ;
struct V_39 * V_22 ;
T_1 * V_226 = NULL ;
F_7 ( V_46 , L_31 ) ;
if ( ( V_21 -> V_22 ) && V_221 )
V_22 = V_21 -> V_22 ;
else
return - V_49 ;
if ( V_5 && V_5 -> V_227 )
return - V_228 ;
if ( ( V_5 && V_5 -> V_229 ) &&
( ( V_21 -> V_22 -> V_23 & V_230 ) == 0 ) ) {
F_7 ( V_137 , L_32 ) ;
return - V_194 ;
}
V_226 = F_42 ( V_231 * 2 , V_173 ) ;
if ( V_226 == NULL )
return - V_73 ;
V_225 = F_60 ( V_226 , V_221 , strlen ( V_221 ) , V_222 ) + 1 ;
V_225 *= 2 ;
if ( V_225 < 2 ) {
F_41 ( V_226 ) ;
return - V_232 ;
}
V_35 = F_18 ( V_40 , V_5 , ( void * * ) & V_97 ) ;
if ( V_35 ) {
F_41 ( V_226 ) ;
return V_35 ;
}
if ( V_5 == NULL ) {
V_97 -> V_2 . V_28 = V_21 -> V_29 ;
}
V_105 [ 0 ] . V_130 = ( char * ) V_97 ;
V_105 [ 0 ] . V_131 = F_29 ( V_97 ) + 4 - 1 ;
V_97 -> V_233 = F_4 ( sizeof( struct V_223 )
- 1 - 4 ) ;
V_97 -> V_234 = F_4 ( V_225 - 2 ) ;
V_105 [ 1 ] . V_130 = V_226 ;
V_105 [ 1 ] . V_131 = V_225 ;
F_26 ( V_97 , V_225 - 1 ) ;
V_35 = F_30 ( V_101 , V_21 , V_105 , 2 , & V_106 , 0 ) ;
V_103 = (struct V_224 * ) V_105 [ 0 ] . V_130 ;
if ( V_35 != 0 ) {
if ( V_5 ) {
F_58 ( V_5 , V_235 ) ;
V_5 -> V_60 = true ;
}
goto V_236;
}
if ( V_5 == NULL ) {
V_21 -> V_237 = V_103 -> V_2 . V_26 ;
goto V_238;
}
if ( V_103 -> V_239 & V_240 )
F_7 ( V_46 , L_33 ) ;
else if ( V_103 -> V_239 & V_241 ) {
V_5 -> V_242 = true ;
F_7 ( V_46 , L_34 ) ;
} else if ( V_103 -> V_239 & V_243 ) {
V_5 -> V_244 = true ;
F_7 ( V_46 , L_35 ) ;
} else {
F_7 ( V_137 , L_36 , V_103 -> V_239 ) ;
V_35 = - V_194 ;
goto V_236;
}
V_5 -> V_245 = F_33 ( V_103 -> V_246 ) ;
V_5 -> V_23 = V_103 -> V_123 ;
V_5 -> V_247 = F_33 ( V_103 -> V_248 ) ;
V_5 -> V_41 = V_212 ;
V_5 -> V_60 = false ;
V_5 -> V_27 = V_103 -> V_2 . V_26 ;
F_61 ( V_5 -> V_62 , V_221 , sizeof( V_5 -> V_62 ) ) ;
if ( ( V_103 -> V_123 & V_249 ) &&
( ( V_5 -> V_245 & V_250 ) == 0 ) )
F_7 ( V_137 , L_37 ) ;
F_59 ( V_5 ) ;
if ( V_5 -> V_245 & V_251 )
F_7 ( V_137 , L_38 ) ;
if ( V_5 -> V_21 -> V_22 -> V_206 -> V_252 )
V_35 = V_5 -> V_21 -> V_22 -> V_206 -> V_252 ( V_101 , V_5 ) ;
V_238:
F_37 ( V_106 , V_103 ) ;
F_41 ( V_226 ) ;
return V_35 ;
V_236:
if ( V_103 -> V_2 . V_199 == V_253 ) {
F_7 ( V_137 , L_39 , V_221 ) ;
if ( V_5 )
V_5 -> V_227 = true ;
}
goto V_238;
}
int
F_62 ( const unsigned int V_101 , struct V_4 * V_5 )
{
struct V_254 * V_97 ;
int V_35 = 0 ;
struct V_39 * V_22 ;
struct V_38 * V_21 = V_5 -> V_21 ;
F_7 ( V_46 , L_40 ) ;
if ( V_21 && ( V_21 -> V_22 ) )
V_22 = V_21 -> V_22 ;
else
return - V_49 ;
if ( ( V_5 -> V_60 ) || ( V_5 -> V_21 -> V_60 ) )
return 0 ;
V_35 = F_18 ( V_45 , V_5 , ( void * * ) & V_97 ) ;
if ( V_35 )
return V_35 ;
V_35 = F_57 ( V_101 , V_21 , ( char * ) & V_97 -> V_2 , 0 ) ;
if ( V_35 )
F_58 ( V_5 , V_255 ) ;
return V_35 ;
}
static struct V_256 *
F_63 ( void )
{
struct V_256 * V_257 ;
V_257 = F_64 ( sizeof( struct V_256 ) , V_173 ) ;
if ( ! V_257 )
return NULL ;
V_257 -> V_258 . V_259 = F_4 ( F_50
( struct V_256 , V_260 ) ) ;
V_257 -> V_258 . V_83 = F_5 ( 16 ) ;
V_257 -> V_258 . V_261 = F_4 ( F_50
( struct V_256 , V_262 ) ) ;
V_257 -> V_258 . V_263 = F_4 ( 4 ) ;
V_257 -> V_262 [ 0 ] = 'D' ;
V_257 -> V_262 [ 1 ] = 'H' ;
V_257 -> V_262 [ 2 ] = 'n' ;
V_257 -> V_262 [ 3 ] = 'Q' ;
return V_257 ;
}
static struct V_256 *
F_65 ( struct V_264 * V_265 )
{
struct V_256 * V_257 ;
V_257 = F_64 ( sizeof( struct V_256 ) , V_173 ) ;
if ( ! V_257 )
return NULL ;
V_257 -> V_258 . V_259 = F_4 ( F_50
( struct V_256 , V_260 ) ) ;
V_257 -> V_258 . V_83 = F_5 ( 16 ) ;
V_257 -> V_258 . V_261 = F_4 ( F_50
( struct V_256 , V_262 ) ) ;
V_257 -> V_258 . V_263 = F_4 ( 4 ) ;
V_257 -> V_260 . V_266 . V_267 = V_265 -> V_268 ;
V_257 -> V_260 . V_266 . V_269 = V_265 -> V_270 ;
V_257 -> V_262 [ 0 ] = 'D' ;
V_257 -> V_262 [ 1 ] = 'H' ;
V_257 -> V_262 [ 2 ] = 'n' ;
V_257 -> V_262 [ 3 ] = 'C' ;
return V_257 ;
}
static T_7
F_66 ( struct V_39 * V_22 , struct V_271 * V_103 ,
unsigned int * V_272 )
{
char * V_273 ;
struct V_274 * V_275 ;
unsigned int V_276 ;
unsigned int V_277 ;
char * V_278 ;
V_273 = ( char * ) V_103 + 4 + F_33 ( V_103 -> V_279 ) ;
V_277 = F_33 ( V_103 -> V_280 ) ;
V_275 = (struct V_274 * ) V_273 ;
while ( V_277 >= sizeof( struct V_274 ) ) {
V_278 = F_2 ( V_275 -> V_261 ) + ( char * ) V_275 ;
if ( F_2 ( V_275 -> V_263 ) == 4 &&
strncmp ( V_278 , L_41 , 4 ) == 0 )
return V_22 -> V_206 -> V_281 ( V_275 , V_272 ) ;
V_276 = F_33 ( V_275 -> V_282 ) ;
if ( ! V_276 )
break;
V_277 -= V_276 ;
V_275 = (struct V_274 * ) ( ( char * ) V_275 + V_276 ) ;
}
return 0 ;
}
static int
F_67 ( struct V_39 * V_22 , struct V_104 * V_105 ,
unsigned int * V_283 , T_7 * V_284 )
{
struct V_285 * V_97 = V_105 [ 0 ] . V_130 ;
unsigned int V_286 = * V_283 ;
V_105 [ V_286 ] . V_130 = V_22 -> V_206 -> V_287 ( V_284 + 1 , * V_284 ) ;
if ( V_105 [ V_286 ] . V_130 == NULL )
return - V_73 ;
V_105 [ V_286 ] . V_131 = V_22 -> V_115 -> V_288 ;
V_97 -> V_289 = V_290 ;
if ( ! V_97 -> V_279 )
V_97 -> V_279 = F_5 (
sizeof( struct V_285 ) - 4 +
V_105 [ V_286 - 1 ] . V_131 ) ;
F_68 ( & V_97 -> V_280 ,
V_22 -> V_115 -> V_288 ) ;
F_26 ( & V_97 -> V_2 , V_22 -> V_115 -> V_288 ) ;
* V_283 = V_286 + 1 ;
return 0 ;
}
static struct V_291 *
F_69 ( struct V_264 * V_292 )
{
struct V_291 * V_257 ;
V_257 = F_64 ( sizeof( struct V_291 ) , V_173 ) ;
if ( ! V_257 )
return NULL ;
V_257 -> V_258 . V_259 = F_4 ( F_50
( struct V_291 , V_293 ) ) ;
V_257 -> V_258 . V_83 = F_5 ( sizeof( struct V_294 ) ) ;
V_257 -> V_258 . V_261 = F_4 ( F_50
( struct V_291 , V_262 ) ) ;
V_257 -> V_258 . V_263 = F_4 ( 4 ) ;
V_257 -> V_293 . V_295 = 0 ;
V_257 -> V_293 . V_31 = F_5 ( V_296 ) ;
F_23 ( V_257 -> V_293 . V_297 , 16 ) ;
memcpy ( V_292 -> V_298 , V_257 -> V_293 . V_297 , 16 ) ;
V_257 -> V_262 [ 0 ] = 'D' ;
V_257 -> V_262 [ 1 ] = 'H' ;
V_257 -> V_262 [ 2 ] = '2' ;
V_257 -> V_262 [ 3 ] = 'Q' ;
return V_257 ;
}
static struct V_299 *
F_70 ( struct V_264 * V_265 )
{
struct V_299 * V_257 ;
V_257 = F_64 ( sizeof( struct V_299 ) ,
V_173 ) ;
if ( ! V_257 )
return NULL ;
V_257 -> V_258 . V_259 =
F_4 ( F_50 ( struct V_299 ,
V_293 ) ) ;
V_257 -> V_258 . V_83 =
F_5 ( sizeof( struct V_300 ) ) ;
V_257 -> V_258 . V_261 =
F_4 ( F_50 ( struct V_299 ,
V_262 ) ) ;
V_257 -> V_258 . V_263 = F_4 ( 4 ) ;
V_257 -> V_293 . V_266 . V_267 = V_265 -> V_268 ;
V_257 -> V_293 . V_266 . V_269 = V_265 -> V_270 ;
V_257 -> V_293 . V_31 = F_5 ( V_296 ) ;
memcpy ( V_257 -> V_293 . V_297 , V_265 -> V_298 , 16 ) ;
V_257 -> V_262 [ 0 ] = 'D' ;
V_257 -> V_262 [ 1 ] = 'H' ;
V_257 -> V_262 [ 2 ] = '2' ;
V_257 -> V_262 [ 3 ] = 'C' ;
return V_257 ;
}
static int
F_71 ( struct V_104 * V_105 , unsigned int * V_283 ,
struct V_301 * V_302 )
{
struct V_285 * V_97 = V_105 [ 0 ] . V_130 ;
unsigned int V_286 = * V_283 ;
V_105 [ V_286 ] . V_130 = F_69 ( V_302 -> V_265 ) ;
if ( V_105 [ V_286 ] . V_130 == NULL )
return - V_73 ;
V_105 [ V_286 ] . V_131 = sizeof( struct V_291 ) ;
if ( ! V_97 -> V_279 )
V_97 -> V_279 =
F_5 ( sizeof( struct V_285 ) - 4 +
V_105 [ 1 ] . V_131 ) ;
F_68 ( & V_97 -> V_280 , sizeof( struct V_291 ) ) ;
F_26 ( & V_97 -> V_2 , sizeof( struct V_291 ) ) ;
* V_283 = V_286 + 1 ;
return 0 ;
}
static int
F_72 ( struct V_104 * V_105 , unsigned int * V_283 ,
struct V_301 * V_302 )
{
struct V_285 * V_97 = V_105 [ 0 ] . V_130 ;
unsigned int V_286 = * V_283 ;
V_302 -> V_303 = false ;
V_105 [ V_286 ] . V_130 = F_70 ( V_302 -> V_265 ) ;
if ( V_105 [ V_286 ] . V_130 == NULL )
return - V_73 ;
V_105 [ V_286 ] . V_131 = sizeof( struct V_299 ) ;
if ( ! V_97 -> V_279 )
V_97 -> V_279 =
F_5 ( sizeof( struct V_285 ) - 4 +
V_105 [ 1 ] . V_131 ) ;
F_68 ( & V_97 -> V_280 ,
sizeof( struct V_299 ) ) ;
F_26 ( & V_97 -> V_2 ,
sizeof( struct V_299 ) ) ;
* V_283 = V_286 + 1 ;
return 0 ;
}
static int
F_73 ( struct V_104 * V_105 , unsigned int * V_283 ,
struct V_301 * V_302 , bool V_304 )
{
struct V_285 * V_97 = V_105 [ 0 ] . V_130 ;
unsigned int V_286 = * V_283 ;
if ( V_304 ) {
if ( V_302 -> V_303 )
return F_72 ( V_105 , V_283 ,
V_302 ) ;
else
return F_71 ( V_105 , V_283 , V_302 ) ;
}
if ( V_302 -> V_303 ) {
V_105 [ V_286 ] . V_130 = F_65 ( V_302 -> V_265 ) ;
V_302 -> V_303 = false ;
} else
V_105 [ V_286 ] . V_130 = F_63 () ;
if ( V_105 [ V_286 ] . V_130 == NULL )
return - V_73 ;
V_105 [ V_286 ] . V_131 = sizeof( struct V_256 ) ;
if ( ! V_97 -> V_279 )
V_97 -> V_279 =
F_5 ( sizeof( struct V_285 ) - 4 +
V_105 [ 1 ] . V_131 ) ;
F_68 ( & V_97 -> V_280 , sizeof( struct V_256 ) ) ;
F_26 ( & V_97 -> V_2 , sizeof( struct V_256 ) ) ;
* V_283 = V_286 + 1 ;
return 0 ;
}
int
F_74 ( const unsigned int V_101 , struct V_301 * V_302 , T_1 * V_305 ,
T_7 * V_284 , struct V_306 * V_257 ,
struct V_307 * * V_308 )
{
struct V_285 * V_97 ;
struct V_271 * V_103 ;
struct V_39 * V_22 ;
struct V_4 * V_5 = V_302 -> V_5 ;
struct V_38 * V_21 = V_5 -> V_21 ;
struct V_104 V_105 [ 4 ] ;
int V_106 ;
int V_309 ;
T_1 * V_310 = NULL ;
int V_311 ;
int V_35 = 0 ;
unsigned int V_312 = 2 ;
T_8 V_313 = 0 ;
char * V_314 = NULL , * V_315 = NULL ;
F_7 ( V_46 , L_42 ) ;
if ( V_21 && ( V_21 -> V_22 ) )
V_22 = V_21 -> V_22 ;
else
return - V_49 ;
V_35 = F_18 ( V_44 , V_5 , ( void * * ) & V_97 ) ;
if ( V_35 )
return V_35 ;
if ( V_302 -> V_316 & V_317 )
V_313 |= V_318 ;
if ( V_302 -> V_316 & V_319 )
V_313 |= V_320 ;
V_97 -> V_321 = V_322 ;
V_97 -> V_323 = F_5 ( V_302 -> V_324 ) ;
V_97 -> V_325 = F_5 ( V_313 ) ;
V_97 -> V_326 = V_327 ;
V_97 -> V_328 = F_5 ( V_302 -> V_329 ) ;
V_97 -> V_330 = F_5 ( V_302 -> V_316 & V_331 ) ;
V_309 = ( 2 * F_75 ( ( V_332 * ) V_305 , V_333 ) ) + 2 ;
V_97 -> V_261 = F_4 ( sizeof( struct V_285 ) - 4 ) ;
V_105 [ 0 ] . V_130 = ( char * ) V_97 ;
V_105 [ 0 ] . V_131 = F_29 ( V_97 ) + 4 ;
V_97 -> V_263 = F_4 ( V_309 - 2 ) ;
V_105 [ 0 ] . V_131 -- ;
if ( V_309 % 8 != 0 ) {
V_311 = V_309 / 8 * 8 ;
if ( V_311 < V_309 )
V_311 += 8 ;
V_310 = F_64 ( V_311 , V_173 ) ;
if ( ! V_310 )
return - V_73 ;
memcpy ( ( char * ) V_310 , ( const char * ) V_305 ,
V_309 ) ;
V_309 = V_311 ;
V_305 = V_310 ;
}
V_105 [ 1 ] . V_131 = V_309 ;
V_105 [ 1 ] . V_130 = V_305 ;
F_26 ( V_97 , V_309 - 1 ) ;
if ( ! V_22 -> V_334 )
* V_284 = V_335 ;
if ( ! ( V_22 -> V_23 & V_336 ) ||
* V_284 == V_335 )
V_97 -> V_289 = * V_284 ;
else {
V_35 = F_67 ( V_22 , V_105 , & V_312 , V_284 ) ;
if ( V_35 ) {
F_76 ( V_97 ) ;
F_41 ( V_310 ) ;
return V_35 ;
}
V_315 = V_105 [ V_312 - 1 ] . V_130 ;
}
if ( * V_284 == V_337 ) {
if ( V_22 -> V_23 & V_336 ) {
struct V_274 * V_258 =
(struct V_274 * ) V_105 [ V_312 - 1 ] . V_130 ;
V_258 -> V_282 =
F_5 ( V_22 -> V_115 -> V_288 ) ;
}
V_35 = F_73 ( V_105 , & V_312 , V_302 ,
V_5 -> V_304 ) ;
if ( V_35 ) {
F_76 ( V_97 ) ;
F_41 ( V_310 ) ;
F_41 ( V_315 ) ;
return V_35 ;
}
V_314 = V_105 [ V_312 - 1 ] . V_130 ;
}
V_35 = F_30 ( V_101 , V_21 , V_105 , V_312 , & V_106 , 0 ) ;
V_103 = (struct V_271 * ) V_105 [ 0 ] . V_130 ;
if ( V_35 != 0 ) {
F_58 ( V_5 , V_338 ) ;
if ( V_308 )
* V_308 = F_47 ( V_103 , F_29 ( V_103 ) + 4 ,
V_173 ) ;
goto V_339;
}
V_302 -> V_265 -> V_268 = V_103 -> V_267 ;
V_302 -> V_265 -> V_270 = V_103 -> V_269 ;
if ( V_257 ) {
memcpy ( V_257 , & V_103 -> V_340 , 32 ) ;
V_257 -> V_341 = V_103 -> V_341 ;
V_257 -> V_342 = V_103 -> V_343 ;
V_257 -> V_344 = V_103 -> V_325 ;
V_257 -> V_345 = F_5 ( 1 ) ;
V_257 -> V_346 = 0 ;
}
if ( V_103 -> V_347 == V_290 )
* V_284 = F_66 ( V_22 , V_103 , & V_302 -> V_265 -> V_272 ) ;
else
* V_284 = V_103 -> V_347 ;
V_339:
F_41 ( V_310 ) ;
F_41 ( V_315 ) ;
F_41 ( V_314 ) ;
F_37 ( V_106 , V_103 ) ;
return V_35 ;
}
int
F_39 ( const unsigned int V_101 , struct V_4 * V_5 , T_9 V_268 ,
T_9 V_270 , T_4 V_348 , bool V_349 , char * V_350 ,
T_4 V_351 , char * * V_352 , T_4 * V_353 )
{
struct V_354 * V_97 ;
struct V_355 * V_103 ;
struct V_39 * V_22 ;
struct V_38 * V_21 ;
struct V_104 V_105 [ 2 ] ;
int V_106 ;
int V_312 ;
int V_35 = 0 ;
F_7 ( V_46 , L_43 ) ;
if ( V_352 != NULL )
* V_352 = NULL ;
if ( V_353 )
* V_353 = 0 ;
if ( V_5 )
V_21 = V_5 -> V_21 ;
else
return - V_49 ;
if ( V_21 && ( V_21 -> V_22 ) )
V_22 = V_21 -> V_22 ;
else
return - V_49 ;
V_35 = F_18 ( V_67 , V_5 , ( void * * ) & V_97 ) ;
if ( V_35 )
return V_35 ;
V_97 -> V_356 = F_5 ( V_348 ) ;
V_97 -> V_267 = V_268 ;
V_97 -> V_269 = V_270 ;
if ( V_351 ) {
V_97 -> V_357 = F_5 ( V_351 ) ;
V_97 -> V_358 =
F_5 ( F_50 ( struct V_354 , V_201 ) - 4 ) ;
V_105 [ 1 ] . V_130 = V_350 ;
V_105 [ 1 ] . V_131 = V_351 ;
V_312 = 2 ;
} else
V_312 = 1 ;
V_97 -> V_359 = 0 ;
V_97 -> V_360 = 0 ;
V_97 -> V_361 = F_5 ( 0xFF00 ) ;
if ( V_349 )
V_97 -> V_31 = F_5 ( V_362 ) ;
else
V_97 -> V_31 = 0 ;
V_105 [ 0 ] . V_130 = ( char * ) V_97 ;
if ( V_351 ) {
V_105 [ 0 ] . V_131 = F_29 ( V_97 ) + 4 - 1 ;
F_26 ( V_97 , V_351 - 1 ) ;
} else
V_105 [ 0 ] . V_131 = F_29 ( V_97 ) + 4 ;
V_35 = F_30 ( V_101 , V_21 , V_105 , V_312 , & V_106 , 0 ) ;
V_103 = (struct V_355 * ) V_105 [ 0 ] . V_130 ;
if ( ( V_35 != 0 ) && ( V_35 != - V_232 ) ) {
F_58 ( V_5 , V_363 ) ;
goto V_364;
} else if ( V_35 == - V_232 ) {
if ( ( V_348 != V_365 ) &&
( V_348 != V_366 ) ) {
F_58 ( V_5 , V_363 ) ;
goto V_364;
}
}
if ( ( V_353 == NULL ) || ( V_352 == NULL ) )
goto V_364;
* V_353 = F_33 ( V_103 -> V_360 ) ;
if ( * V_353 == 0 )
goto V_364;
else if ( * V_353 > 0xFF00 ) {
F_7 ( V_137 , L_44 , * V_353 ) ;
* V_353 = 0 ;
V_35 = - V_49 ;
goto V_364;
}
if ( F_29 ( V_103 ) < F_33 ( V_103 -> V_359 ) + * V_353 ) {
F_7 ( V_137 , L_45 , * V_353 ,
F_33 ( V_103 -> V_359 ) ) ;
* V_353 = 0 ;
V_35 = - V_49 ;
goto V_364;
}
* V_352 = F_42 ( * V_353 , V_173 ) ;
if ( * V_352 == NULL ) {
V_35 = - V_73 ;
goto V_364;
}
memcpy ( * V_352 ,
( char * ) & V_103 -> V_2 . V_12 + F_33 ( V_103 -> V_359 ) ,
* V_353 ) ;
V_364:
F_37 ( V_106 , V_103 ) ;
return V_35 ;
}
int
F_77 ( const unsigned int V_101 , struct V_4 * V_5 ,
T_9 V_268 , T_9 V_270 )
{
int V_35 ;
struct V_367 V_368 ;
char * V_369 = NULL ;
V_368 . V_370 =
F_4 ( V_371 ) ;
V_35 = F_39 ( V_101 , V_5 , V_268 , V_270 ,
V_372 , true ,
( char * ) & V_368 ,
2 , & V_369 , NULL ) ;
F_7 ( V_46 , L_46 , V_35 ) ;
return V_35 ;
}
int
F_78 ( const unsigned int V_101 , struct V_4 * V_5 ,
T_9 V_268 , T_9 V_270 )
{
struct V_373 * V_97 ;
struct V_374 * V_103 ;
struct V_39 * V_22 ;
struct V_38 * V_21 = V_5 -> V_21 ;
struct V_104 V_105 [ 1 ] ;
int V_106 ;
int V_35 = 0 ;
F_7 ( V_46 , L_47 ) ;
if ( V_21 && ( V_21 -> V_22 ) )
V_22 = V_21 -> V_22 ;
else
return - V_49 ;
V_35 = F_18 ( V_53 , V_5 , ( void * * ) & V_97 ) ;
if ( V_35 )
return V_35 ;
V_97 -> V_267 = V_268 ;
V_97 -> V_269 = V_270 ;
V_105 [ 0 ] . V_130 = ( char * ) V_97 ;
V_105 [ 0 ] . V_131 = F_29 ( V_97 ) + 4 ;
V_35 = F_30 ( V_101 , V_21 , V_105 , 1 , & V_106 , 0 ) ;
V_103 = (struct V_374 * ) V_105 [ 0 ] . V_130 ;
if ( V_35 != 0 ) {
F_58 ( V_5 , V_375 ) ;
goto V_376;
}
V_376:
F_37 ( V_106 , V_103 ) ;
return V_35 ;
}
static int
F_79 ( unsigned int V_377 , unsigned int V_378 ,
struct V_1 * V_2 , unsigned int V_379 )
{
unsigned int V_380 = F_80 ( V_2 -> V_11 ) ;
char * V_381 = V_380 + 4 + ( char * ) V_2 ;
char * V_382 = 4 + V_377 + ( char * ) V_2 ;
char * V_383 = V_382 + V_378 ;
if ( V_378 < V_379 ) {
F_7 ( V_137 , L_48 ,
V_378 , V_379 ) ;
return - V_232 ;
}
if ( ( V_380 > 0x7FFFFF ) || ( V_378 > 0x7FFFFF ) ) {
F_7 ( V_137 , L_49 ,
V_378 , V_380 ) ;
return - V_232 ;
}
if ( ( V_382 > V_381 ) || ( V_383 > V_381 ) ) {
F_7 ( V_137 , L_50 ) ;
return - V_232 ;
}
return 0 ;
}
static int
F_81 ( unsigned int V_377 , unsigned int V_378 ,
struct V_1 * V_2 , unsigned int V_384 ,
char * V_187 )
{
char * V_382 = 4 + V_377 + ( char * ) V_2 ;
int V_35 ;
if ( ! V_187 )
return - V_232 ;
V_35 = F_79 ( V_377 , V_378 , V_2 , V_384 ) ;
if ( V_35 )
return V_35 ;
memcpy ( V_187 , V_382 , V_378 ) ;
return 0 ;
}
static int
F_82 ( const unsigned int V_101 , struct V_4 * V_5 ,
T_9 V_268 , T_9 V_270 , T_10 V_385 ,
T_11 V_386 , T_11 V_387 , void * V_187 )
{
struct V_388 * V_97 ;
struct V_389 * V_103 = NULL ;
struct V_104 V_105 [ 2 ] ;
int V_35 = 0 ;
int V_106 ;
struct V_39 * V_22 ;
struct V_38 * V_21 = V_5 -> V_21 ;
F_7 ( V_46 , L_51 ) ;
if ( V_21 && ( V_21 -> V_22 ) )
V_22 = V_21 -> V_22 ;
else
return - V_49 ;
V_35 = F_18 ( V_70 , V_5 , ( void * * ) & V_97 ) ;
if ( V_35 )
return V_35 ;
V_97 -> V_390 = V_391 ;
V_97 -> V_392 = V_385 ;
V_97 -> V_267 = V_268 ;
V_97 -> V_269 = V_270 ;
V_97 -> V_393 =
F_4 ( sizeof( struct V_388 ) - 1 - 4 ) ;
V_97 -> V_394 = F_5 ( V_386 ) ;
V_105 [ 0 ] . V_130 = ( char * ) V_97 ;
V_105 [ 0 ] . V_131 = F_29 ( V_97 ) + 4 ;
V_35 = F_30 ( V_101 , V_21 , V_105 , 1 , & V_106 , 0 ) ;
V_103 = (struct V_389 * ) V_105 [ 0 ] . V_130 ;
if ( V_35 ) {
F_58 ( V_5 , V_395 ) ;
goto V_396;
}
V_35 = F_81 ( F_2 ( V_103 -> V_397 ) ,
F_33 ( V_103 -> V_394 ) ,
& V_103 -> V_2 , V_387 , V_187 ) ;
V_396:
F_37 ( V_106 , V_103 ) ;
return V_35 ;
}
int
F_83 ( const unsigned int V_101 , struct V_4 * V_5 ,
T_9 V_268 , T_9 V_270 ,
struct V_306 * V_187 )
{
return F_82 ( V_101 , V_5 , V_268 , V_270 ,
V_398 ,
sizeof( struct V_306 ) + V_333 * 2 ,
sizeof( struct V_306 ) , V_187 ) ;
}
int
F_84 ( const unsigned int V_101 , struct V_4 * V_5 ,
T_9 V_268 , T_9 V_270 , T_12 * V_399 )
{
return F_82 ( V_101 , V_5 , V_268 , V_270 ,
V_400 ,
sizeof( struct V_401 ) ,
sizeof( struct V_401 ) , V_399 ) ;
}
static void
F_85 ( struct V_402 * V_403 )
{
struct V_39 * V_22 = V_403 -> V_404 ;
struct V_405 * V_406 = (struct V_405 * ) V_403 -> V_407 ;
unsigned int V_408 = 1 ;
if ( V_403 -> V_409 == V_410 )
V_408 = F_2 ( V_406 -> V_2 . V_16 ) ;
F_10 ( & V_22 -> V_205 ) ;
F_86 ( V_403 ) ;
F_13 ( & V_22 -> V_205 ) ;
F_87 ( V_22 , V_408 , V_411 ) ;
}
int
F_88 ( struct V_39 * V_22 )
{
struct V_412 * V_97 ;
int V_35 = 0 ;
struct V_104 V_105 ;
struct V_413 V_414 = { . V_415 = & V_105 ,
. V_416 = 1 } ;
F_7 ( V_46 , L_52 ) ;
if ( V_22 -> V_50 == V_417 ) {
struct V_418 * V_419 , * V_420 ;
struct V_38 * V_21 ;
struct V_4 * V_5 ;
F_7 ( V_46 , L_53 ) ;
F_52 ( & V_421 ) ;
F_89 (tmp, &server->smb_ses_list) {
V_21 = F_90 ( V_419 , struct V_38 , V_422 ) ;
F_89 (tmp2, &ses->tcon_list) {
V_5 = F_90 ( V_420 , struct V_4 ,
V_423 ) ;
if ( V_5 && V_5 -> V_60 ) {
F_53 ( & V_421 ) ;
V_35 = F_6 ( V_424 , V_5 ) ;
F_52 ( & V_421 ) ;
}
}
}
F_53 ( & V_421 ) ;
}
if ( V_22 -> V_50 == V_417 )
return - V_49 ;
V_35 = F_18 ( V_424 , NULL , ( void * * ) & V_97 ) ;
if ( V_35 )
return V_35 ;
V_97 -> V_2 . V_16 = F_4 ( 1 ) ;
V_105 . V_130 = ( char * ) V_97 ;
V_105 . V_131 = F_29 ( V_97 ) + 4 ;
V_35 = F_91 ( V_22 , & V_414 , NULL , F_85 , V_22 ,
V_411 ) ;
if ( V_35 )
F_7 ( V_46 , L_54 , V_35 ) ;
F_76 ( V_97 ) ;
return V_35 ;
}
int
F_92 ( const unsigned int V_101 , struct V_4 * V_5 , T_9 V_268 ,
T_9 V_270 )
{
struct V_425 * V_97 ;
struct V_39 * V_22 ;
struct V_38 * V_21 = V_5 -> V_21 ;
struct V_104 V_105 [ 1 ] ;
int V_106 ;
int V_35 = 0 ;
F_7 ( V_46 , L_55 ) ;
if ( V_21 && ( V_21 -> V_22 ) )
V_22 = V_21 -> V_22 ;
else
return - V_49 ;
V_35 = F_18 ( V_64 , V_5 , ( void * * ) & V_97 ) ;
if ( V_35 )
return V_35 ;
V_97 -> V_267 = V_268 ;
V_97 -> V_269 = V_270 ;
V_105 [ 0 ] . V_130 = ( char * ) V_97 ;
V_105 [ 0 ] . V_131 = F_29 ( V_97 ) + 4 ;
V_35 = F_30 ( V_101 , V_21 , V_105 , 1 , & V_106 , 0 ) ;
if ( V_35 != 0 )
F_58 ( V_5 , V_426 ) ;
F_37 ( V_106 , V_105 [ 0 ] . V_130 ) ;
return V_35 ;
}
static int
F_93 ( struct V_104 * V_105 , struct V_427 * V_428 ,
unsigned int V_429 , int V_430 )
{
int V_35 = - V_431 ;
struct V_432 * V_97 = NULL ;
V_35 = F_18 ( V_65 , V_428 -> V_5 , ( void * * ) & V_97 ) ;
if ( V_35 )
return V_35 ;
if ( V_428 -> V_5 -> V_21 -> V_22 == NULL )
return - V_433 ;
V_97 -> V_2 . V_17 = F_5 ( V_428 -> V_434 ) ;
V_97 -> V_267 = V_428 -> V_268 ;
V_97 -> V_269 = V_428 -> V_270 ;
V_97 -> V_435 = 0 ;
V_97 -> V_436 = 0 ;
V_97 -> V_182 = 0 ;
V_97 -> V_437 = 0 ;
V_97 -> V_438 = F_5 ( V_428 -> V_439 ) ;
V_97 -> V_440 = F_94 ( V_428 -> V_377 ) ;
if ( V_430 & V_441 ) {
if ( ! ( V_430 & V_442 ) ) {
V_97 -> V_2 . V_443 =
F_5 ( F_29 ( V_97 ) + 4 ) ;
} else
V_97 -> V_2 . V_443 = 0 ;
if ( V_430 & V_444 ) {
V_97 -> V_2 . V_31 |= V_445 ;
V_97 -> V_2 . V_28 = 0xFFFFFFFF ;
V_97 -> V_2 . V_26 = 0xFFFFFFFF ;
V_97 -> V_267 = 0xFFFFFFFF ;
V_97 -> V_269 = 0xFFFFFFFF ;
}
}
if ( V_429 > V_428 -> V_439 )
V_97 -> V_446 = F_5 ( V_429 ) ;
else
V_97 -> V_446 = 0 ;
V_105 [ 0 ] . V_130 = ( char * ) V_97 ;
V_105 [ 0 ] . V_131 = F_29 ( V_97 ) + 4 ;
return V_35 ;
}
static void
F_95 ( struct V_402 * V_403 )
{
struct V_447 * V_448 = V_403 -> V_404 ;
struct V_4 * V_5 = F_96 ( V_448 -> V_449 -> V_450 ) ;
struct V_39 * V_22 = V_5 -> V_21 -> V_22 ;
struct V_1 * V_257 = (struct V_1 * ) V_448 -> V_105 . V_130 ;
unsigned int V_408 = 1 ;
struct V_413 V_414 = { . V_415 = & V_448 -> V_105 ,
. V_416 = 1 ,
. V_451 = V_448 -> V_452 ,
. V_453 = V_448 -> V_454 ,
. V_455 = V_448 -> V_456 ,
. V_457 = V_448 -> V_458 } ;
F_7 ( V_46 , L_56 ,
V_112 , V_403 -> V_403 , V_403 -> V_409 , V_448 -> V_459 ,
V_448 -> V_460 ) ;
switch ( V_403 -> V_409 ) {
case V_410 :
V_408 = F_2 ( V_257 -> V_16 ) ;
if ( V_22 -> V_30 ) {
int V_35 ;
V_35 = F_97 ( & V_414 , V_22 ) ;
if ( V_35 )
F_7 ( V_137 , L_57 ,
V_35 ) ;
}
F_98 ( V_448 -> V_461 ) ;
F_99 ( V_5 , V_448 -> V_461 ) ;
break;
case V_462 :
case V_463 :
V_448 -> V_459 = - V_55 ;
if ( V_22 -> V_30 && V_448 -> V_461 )
V_448 -> V_461 = 0 ;
F_98 ( V_448 -> V_461 ) ;
F_99 ( V_5 , V_448 -> V_461 ) ;
break;
default:
if ( V_448 -> V_459 != - V_464 )
V_448 -> V_459 = - V_49 ;
}
if ( V_448 -> V_459 )
F_58 ( V_5 , V_465 ) ;
F_100 ( V_466 , & V_448 -> V_467 ) ;
F_10 ( & V_22 -> V_205 ) ;
F_86 ( V_403 ) ;
F_13 ( & V_22 -> V_205 ) ;
F_87 ( V_22 , V_408 , 0 ) ;
}
int
F_101 ( struct V_447 * V_448 )
{
int V_35 , V_110 = 0 ;
struct V_1 * V_257 ;
struct V_427 V_428 ;
struct V_413 V_414 = { . V_415 = & V_448 -> V_105 ,
. V_416 = 1 } ;
struct V_39 * V_22 ;
F_7 ( V_46 , L_58 ,
V_112 , V_448 -> V_377 , V_448 -> V_460 ) ;
V_428 . V_5 = F_96 ( V_448 -> V_449 -> V_450 ) ;
V_428 . V_377 = V_448 -> V_377 ;
V_428 . V_439 = V_448 -> V_460 ;
V_428 . V_268 = V_448 -> V_449 -> V_265 . V_268 ;
V_428 . V_270 = V_448 -> V_449 -> V_265 . V_270 ;
V_428 . V_434 = V_448 -> V_434 ;
V_22 = V_428 . V_5 -> V_21 -> V_22 ;
V_35 = F_93 ( & V_448 -> V_105 , & V_428 , 0 , 0 ) ;
if ( V_35 ) {
if ( V_35 == - V_55 && V_448 -> V_468 ) {
V_448 -> V_468 = 0 ;
F_52 ( & V_22 -> V_469 ) ;
V_22 -> V_470 -- ;
F_53 ( & V_22 -> V_469 ) ;
}
return V_35 ;
}
V_257 = (struct V_1 * ) V_448 -> V_105 . V_130 ;
V_448 -> V_105 . V_131 = F_29 ( V_448 -> V_105 . V_130 ) + 4 ;
if ( V_448 -> V_468 ) {
V_257 -> V_25 = F_4 ( F_102 ( V_448 -> V_460 ,
V_471 ) ) ;
F_52 ( & V_22 -> V_469 ) ;
V_22 -> V_468 += V_448 -> V_468 -
F_2 ( V_257 -> V_25 ) ;
F_53 ( & V_22 -> V_469 ) ;
F_103 ( & V_22 -> V_472 ) ;
V_110 = V_473 ;
}
F_104 ( & V_448 -> V_474 ) ;
V_35 = F_91 ( V_428 . V_5 -> V_21 -> V_22 , & V_414 ,
V_475 , F_95 ,
V_448 , V_110 ) ;
if ( V_35 ) {
F_105 ( & V_448 -> V_474 , V_476 ) ;
F_58 ( V_428 . V_5 , V_465 ) ;
}
F_76 ( V_257 ) ;
return V_35 ;
}
int
F_106 ( const unsigned int V_101 , struct V_427 * V_428 ,
unsigned int * V_477 , char * * V_257 , int * V_478 )
{
int V_106 , V_35 = - V_431 ;
struct V_479 * V_103 = NULL ;
struct V_104 V_105 [ 1 ] ;
* V_477 = 0 ;
V_35 = F_93 ( V_105 , V_428 , 0 , 0 ) ;
if ( V_35 )
return V_35 ;
V_35 = F_30 ( V_101 , V_428 -> V_5 -> V_21 , V_105 , 1 ,
& V_106 , V_198 ) ;
V_103 = (struct V_479 * ) V_105 [ 0 ] . V_130 ;
if ( V_103 -> V_2 . V_199 == V_480 ) {
F_37 ( V_106 , V_105 [ 0 ] . V_130 ) ;
return 0 ;
}
if ( V_35 ) {
F_58 ( V_428 -> V_5 , V_465 ) ;
F_7 ( V_137 , L_59 , V_35 ) ;
} else {
* V_477 = F_33 ( V_103 -> V_83 ) ;
if ( ( * V_477 > V_481 ) ||
( * V_477 > V_428 -> V_439 ) ) {
F_7 ( V_46 , L_60 ,
* V_477 , V_428 -> V_439 ) ;
V_35 = - V_49 ;
* V_477 = 0 ;
}
}
if ( * V_257 ) {
memcpy ( * V_257 , ( char * ) & V_103 -> V_2 . V_12 + V_103 -> V_259 ,
* V_477 ) ;
F_37 ( V_106 , V_105 [ 0 ] . V_130 ) ;
} else if ( V_106 != V_162 ) {
* V_257 = V_105 [ 0 ] . V_130 ;
if ( V_106 == V_482 )
* V_478 = V_482 ;
else if ( V_106 == V_483 )
* V_478 = V_483 ;
}
return V_35 ;
}
static void
F_107 ( struct V_402 * V_403 )
{
struct V_484 * V_485 = V_403 -> V_404 ;
struct V_4 * V_5 = F_96 ( V_485 -> V_449 -> V_450 ) ;
struct V_39 * V_22 = V_5 -> V_21 -> V_22 ;
unsigned int V_486 ;
struct V_487 * V_103 = (struct V_487 * ) V_403 -> V_407 ;
unsigned int V_408 = 1 ;
switch ( V_403 -> V_409 ) {
case V_410 :
V_408 = F_2 ( V_103 -> V_2 . V_16 ) ;
V_485 -> V_459 = F_108 ( V_403 , V_5 -> V_21 -> V_22 , 0 ) ;
if ( V_485 -> V_459 != 0 )
break;
V_486 = F_33 ( V_103 -> V_83 ) ;
if ( V_486 > V_485 -> V_460 )
V_486 &= 0xFFFF ;
if ( V_486 < V_485 -> V_460 )
V_485 -> V_459 = - V_488 ;
else
V_485 -> V_460 = V_486 ;
break;
case V_462 :
case V_463 :
V_485 -> V_459 = - V_55 ;
break;
default:
V_485 -> V_459 = - V_49 ;
break;
}
if ( V_485 -> V_459 )
F_58 ( V_5 , V_489 ) ;
F_100 ( V_466 , & V_485 -> V_467 ) ;
F_10 ( & V_22 -> V_205 ) ;
F_86 ( V_403 ) ;
F_13 ( & V_22 -> V_205 ) ;
F_87 ( V_5 -> V_21 -> V_22 , V_408 , 0 ) ;
}
int
F_109 ( struct V_484 * V_485 ,
void (* F_110)( struct V_490 * V_490 ) )
{
int V_35 = - V_431 , V_110 = 0 ;
struct V_491 * V_97 = NULL ;
struct V_4 * V_5 = F_96 ( V_485 -> V_449 -> V_450 ) ;
struct V_39 * V_22 = V_5 -> V_21 -> V_22 ;
struct V_104 V_105 ;
struct V_413 V_414 ;
V_35 = F_18 ( V_43 , V_5 , ( void * * ) & V_97 ) ;
if ( V_35 ) {
if ( V_35 == - V_55 && V_485 -> V_468 ) {
V_485 -> V_468 = 0 ;
F_52 ( & V_22 -> V_469 ) ;
V_22 -> V_470 -- ;
F_53 ( & V_22 -> V_469 ) ;
}
goto V_492;
}
V_97 -> V_2 . V_17 = F_5 ( V_485 -> V_449 -> V_434 ) ;
V_97 -> V_267 = V_485 -> V_449 -> V_265 . V_268 ;
V_97 -> V_269 = V_485 -> V_449 -> V_265 . V_270 ;
V_97 -> V_493 = 0 ;
V_97 -> V_494 = 0 ;
V_97 -> V_182 = 0 ;
V_97 -> V_440 = F_94 ( V_485 -> V_377 ) ;
V_97 -> V_259 = F_4 (
F_50 ( struct V_491 , V_201 ) - 4 ) ;
V_97 -> V_446 = 0 ;
V_105 . V_131 = F_29 ( V_97 ) + 4 - 1 ;
V_105 . V_130 = V_97 ;
V_414 . V_415 = & V_105 ;
V_414 . V_416 = 1 ;
V_414 . V_451 = V_485 -> V_452 ;
V_414 . V_453 = V_485 -> V_454 ;
V_414 . V_455 = V_485 -> V_456 ;
V_414 . V_457 = V_485 -> V_458 ;
F_7 ( V_46 , L_61 ,
V_485 -> V_377 , V_485 -> V_460 ) ;
V_97 -> V_438 = F_5 ( V_485 -> V_460 ) ;
F_26 ( & V_97 -> V_2 , V_485 -> V_460 - 1 ) ;
if ( V_485 -> V_468 ) {
V_97 -> V_2 . V_25 = F_4 ( F_102 ( V_485 -> V_460 ,
V_471 ) ) ;
F_52 ( & V_22 -> V_469 ) ;
V_22 -> V_468 += V_485 -> V_468 -
F_2 ( V_97 -> V_2 . V_25 ) ;
F_53 ( & V_22 -> V_469 ) ;
F_103 ( & V_22 -> V_472 ) ;
V_110 = V_473 ;
}
F_104 ( & V_485 -> V_474 ) ;
V_35 = F_91 ( V_22 , & V_414 , NULL , F_107 , V_485 ,
V_110 ) ;
if ( V_35 ) {
F_105 ( & V_485 -> V_474 , F_110 ) ;
F_58 ( V_5 , V_489 ) ;
}
V_492:
F_76 ( V_97 ) ;
return V_35 ;
}
int
F_111 ( const unsigned int V_101 , struct V_427 * V_428 ,
unsigned int * V_477 , struct V_104 * V_105 , int V_495 )
{
int V_35 = 0 ;
struct V_491 * V_97 = NULL ;
struct V_487 * V_103 = NULL ;
int V_106 ;
* V_477 = 0 ;
if ( V_495 < 1 )
return V_35 ;
V_35 = F_18 ( V_43 , V_428 -> V_5 , ( void * * ) & V_97 ) ;
if ( V_35 )
return V_35 ;
if ( V_428 -> V_5 -> V_21 -> V_22 == NULL )
return - V_433 ;
V_97 -> V_2 . V_17 = F_5 ( V_428 -> V_434 ) ;
V_97 -> V_267 = V_428 -> V_268 ;
V_97 -> V_269 = V_428 -> V_270 ;
V_97 -> V_493 = 0 ;
V_97 -> V_494 = 0 ;
V_97 -> V_182 = 0 ;
V_97 -> V_438 = F_5 ( V_428 -> V_439 ) ;
V_97 -> V_440 = F_94 ( V_428 -> V_377 ) ;
V_97 -> V_259 = F_4 (
F_50 ( struct V_491 , V_201 ) - 4 ) ;
V_97 -> V_446 = 0 ;
V_105 [ 0 ] . V_130 = ( char * ) V_97 ;
V_105 [ 0 ] . V_131 = F_29 ( V_97 ) + 4 - 1 ;
F_26 ( V_97 , V_428 -> V_439 - 1 ) ;
V_35 = F_30 ( V_101 , V_428 -> V_5 -> V_21 , V_105 , V_495 + 1 ,
& V_106 , 0 ) ;
V_103 = (struct V_487 * ) V_105 [ 0 ] . V_130 ;
if ( V_35 ) {
F_58 ( V_428 -> V_5 , V_489 ) ;
F_7 ( V_137 , L_62 , V_35 ) ;
} else
* V_477 = F_33 ( V_103 -> V_83 ) ;
F_37 ( V_106 , V_103 ) ;
return V_35 ;
}
static unsigned int
F_112 ( char * V_496 , char * V_383 , char * * V_497 , T_11 V_498 )
{
int V_192 ;
unsigned int V_499 = 0 ;
unsigned int V_500 = 0 ;
T_13 * V_501 ;
if ( V_496 == NULL )
return 0 ;
V_501 = ( T_13 * ) V_496 ;
while ( 1 ) {
V_501 = ( T_13 * )
( ( char * ) V_501 + V_500 ) ;
if ( ( char * ) V_501 + V_498 > V_383 ) {
F_7 ( V_137 , L_63 ) ;
break;
}
V_192 = F_33 ( V_501 -> V_502 ) ;
if ( ( char * ) V_501 + V_192 + V_498 > V_383 ) {
F_7 ( V_137 , L_64 ,
V_383 ) ;
break;
}
* V_497 = ( char * ) V_501 ;
V_499 ++ ;
V_500 = F_33 ( V_501 -> V_503 ) ;
if ( ! V_500 )
break;
}
return V_499 ;
}
int
F_113 ( const unsigned int V_101 , struct V_4 * V_5 ,
T_9 V_268 , T_9 V_270 , int V_504 ,
struct V_505 * V_506 )
{
struct V_507 * V_97 ;
struct V_508 * V_103 = NULL ;
struct V_104 V_105 [ 2 ] ;
int V_35 = 0 ;
int V_192 ;
int V_106 = V_162 ;
unsigned char * V_509 ;
struct V_39 * V_22 ;
struct V_38 * V_21 = V_5 -> V_21 ;
T_1 V_510 = F_4 ( '*' ) ;
char * V_381 ;
unsigned int V_511 = V_512 ;
T_11 V_513 ;
if ( V_21 && ( V_21 -> V_22 ) )
V_22 = V_21 -> V_22 ;
else
return - V_49 ;
V_35 = F_18 ( V_68 , V_5 , ( void * * ) & V_97 ) ;
if ( V_35 )
return V_35 ;
switch ( V_506 -> V_514 ) {
case V_515 :
V_97 -> V_516 = V_517 ;
V_513 = sizeof( T_13 ) - 1 ;
break;
case V_518 :
V_97 -> V_516 = V_519 ;
V_513 = sizeof( V_520 ) - 1 ;
break;
default:
F_7 ( V_137 , L_65 ,
V_506 -> V_514 ) ;
V_35 = - V_232 ;
goto V_521;
}
V_97 -> V_522 = F_5 ( V_504 ) ;
V_97 -> V_267 = V_268 ;
V_97 -> V_269 = V_270 ;
V_192 = 0x2 ;
V_509 = V_97 -> V_201 ;
memcpy ( V_509 , & V_510 , V_192 ) ;
V_97 -> V_523 =
F_4 ( sizeof( struct V_507 ) - 1 - 4 ) ;
V_97 -> V_502 = F_4 ( V_192 ) ;
V_511 = F_32 (unsigned int, output_size, server->maxBuf) ;
V_511 = F_32 (unsigned int, output_size, 2 << 15 ) ;
V_97 -> V_394 = F_5 ( V_511 ) ;
V_105 [ 0 ] . V_130 = ( char * ) V_97 ;
V_105 [ 0 ] . V_131 = F_29 ( V_97 ) + 4 - 1 ;
V_105 [ 1 ] . V_130 = ( char * ) ( V_97 -> V_201 ) ;
V_105 [ 1 ] . V_131 = V_192 ;
F_26 ( V_97 , V_192 - 1 ) ;
V_35 = F_30 ( V_101 , V_21 , V_105 , 2 , & V_106 , 0 ) ;
V_103 = (struct V_508 * ) V_105 [ 0 ] . V_130 ;
if ( V_35 ) {
if ( V_35 == - V_464 && V_103 -> V_2 . V_199 == V_524 ) {
V_506 -> V_525 = true ;
V_35 = 0 ;
}
F_58 ( V_5 , V_526 ) ;
goto V_521;
}
V_35 = F_79 ( F_2 ( V_103 -> V_397 ) ,
F_33 ( V_103 -> V_394 ) , & V_103 -> V_2 ,
V_513 ) ;
if ( V_35 )
goto V_521;
V_506 -> V_527 = true ;
if ( V_506 -> V_528 ) {
if ( V_506 -> V_529 )
F_76 ( V_506 -> V_528 ) ;
else
F_114 ( V_506 -> V_528 ) ;
}
V_506 -> V_528 = ( char * ) V_103 ;
V_506 -> V_530 = V_506 -> V_531 = 4 +
( char * ) & V_103 -> V_2 + F_2 ( V_103 -> V_397 ) ;
V_381 = F_29 ( V_103 ) + 4 + ( char * ) & V_103 -> V_2 ;
V_506 -> V_532 =
F_112 ( V_506 -> V_530 , V_381 ,
& V_506 -> V_531 , V_513 ) ;
V_506 -> V_533 += V_506 -> V_532 ;
F_7 ( V_46 , L_66 ,
V_506 -> V_532 , V_506 -> V_533 ,
V_506 -> V_530 , V_506 -> V_531 ) ;
if ( V_106 == V_483 )
V_506 -> V_529 = false ;
else if ( V_106 == V_482 )
V_506 -> V_529 = true ;
else
F_7 ( V_137 , L_67 ) ;
return V_35 ;
V_521:
F_37 ( V_106 , V_103 ) ;
return V_35 ;
}
static int
F_115 ( const unsigned int V_101 , struct V_4 * V_5 ,
T_9 V_268 , T_9 V_270 , T_4 V_434 , int V_385 ,
unsigned int V_286 , void * * V_187 , unsigned int * V_498 )
{
struct V_534 * V_97 ;
struct V_535 * V_103 = NULL ;
struct V_104 * V_105 ;
int V_35 = 0 ;
int V_106 ;
unsigned int V_536 ;
struct V_39 * V_22 ;
struct V_38 * V_21 = V_5 -> V_21 ;
if ( V_21 && ( V_21 -> V_22 ) )
V_22 = V_21 -> V_22 ;
else
return - V_49 ;
if ( ! V_286 )
return - V_232 ;
V_105 = F_42 ( sizeof( struct V_104 ) * V_286 , V_173 ) ;
if ( ! V_105 )
return - V_73 ;
V_35 = F_18 ( V_71 , V_5 , ( void * * ) & V_97 ) ;
if ( V_35 ) {
F_41 ( V_105 ) ;
return V_35 ;
}
V_97 -> V_2 . V_17 = F_5 ( V_434 ) ;
V_97 -> V_390 = V_391 ;
V_97 -> V_392 = V_385 ;
V_97 -> V_267 = V_268 ;
V_97 -> V_269 = V_270 ;
V_97 -> V_537 =
F_4 ( sizeof( struct V_534 ) - 1 - 4 ) ;
V_97 -> V_538 = F_5 ( * V_498 ) ;
F_26 ( V_97 , * V_498 - 1 ) ;
memcpy ( V_97 -> V_201 , * V_187 , * V_498 ) ;
V_105 [ 0 ] . V_130 = ( char * ) V_97 ;
V_105 [ 0 ] . V_131 = F_29 ( V_97 ) + 4 ;
for ( V_536 = 1 ; V_536 < V_286 ; V_536 ++ ) {
F_26 ( V_97 , V_498 [ V_536 ] ) ;
F_68 ( & V_97 -> V_538 , V_498 [ V_536 ] ) ;
V_105 [ V_536 ] . V_130 = ( char * ) V_187 [ V_536 ] ;
V_105 [ V_536 ] . V_131 = V_498 [ V_536 ] ;
}
V_35 = F_30 ( V_101 , V_21 , V_105 , V_286 , & V_106 , 0 ) ;
V_103 = (struct V_535 * ) V_105 [ 0 ] . V_130 ;
if ( V_35 != 0 )
F_58 ( V_5 , V_539 ) ;
F_37 ( V_106 , V_103 ) ;
F_41 ( V_105 ) ;
return V_35 ;
}
int
F_116 ( const unsigned int V_101 , struct V_4 * V_5 ,
T_9 V_268 , T_9 V_270 , T_1 * V_540 )
{
struct V_541 V_542 ;
void * * V_187 ;
unsigned int V_498 [ 2 ] ;
int V_35 ;
int V_192 = ( 2 * F_75 ( ( V_332 * ) V_540 , V_333 ) ) ;
V_187 = F_42 ( sizeof( void * ) * 2 , V_173 ) ;
if ( ! V_187 )
return - V_73 ;
V_542 . V_543 = 1 ;
V_542 . V_544 = 0 ;
V_542 . V_502 = F_5 ( V_192 ) ;
V_187 [ 0 ] = & V_542 ;
V_498 [ 0 ] = sizeof( struct V_541 ) ;
V_187 [ 1 ] = V_540 ;
V_498 [ 1 ] = V_192 + 2 ;
V_35 = F_115 ( V_101 , V_5 , V_268 , V_270 ,
V_18 -> V_19 , V_545 , 2 , V_187 ,
V_498 ) ;
F_41 ( V_187 ) ;
return V_35 ;
}
int
F_117 ( const unsigned int V_101 , struct V_4 * V_5 ,
T_9 V_268 , T_9 V_270 )
{
T_7 V_546 = 1 ;
void * V_187 ;
unsigned int V_498 ;
V_187 = & V_546 ;
V_498 = 1 ;
return F_115 ( V_101 , V_5 , V_268 , V_270 ,
V_18 -> V_19 , V_547 , 1 , & V_187 ,
& V_498 ) ;
}
int
F_118 ( const unsigned int V_101 , struct V_4 * V_5 ,
T_9 V_268 , T_9 V_270 , T_1 * V_540 )
{
struct V_548 V_542 ;
void * * V_187 ;
unsigned int V_498 [ 2 ] ;
int V_35 ;
int V_192 = ( 2 * F_75 ( ( V_332 * ) V_540 , V_333 ) ) ;
V_187 = F_42 ( sizeof( void * ) * 2 , V_173 ) ;
if ( ! V_187 )
return - V_73 ;
V_542 . V_543 = 0 ;
V_542 . V_544 = 0 ;
V_542 . V_502 = F_5 ( V_192 ) ;
V_187 [ 0 ] = & V_542 ;
V_498 [ 0 ] = sizeof( struct V_548 ) ;
V_187 [ 1 ] = V_540 ;
V_498 [ 1 ] = V_192 + 2 ;
V_35 = F_115 ( V_101 , V_5 , V_268 , V_270 ,
V_18 -> V_19 , V_549 , 2 , V_187 , V_498 ) ;
F_41 ( V_187 ) ;
return V_35 ;
}
int
F_119 ( const unsigned int V_101 , struct V_4 * V_5 , T_9 V_268 ,
T_9 V_270 , T_4 V_434 , T_12 * V_550 , bool V_551 )
{
struct V_552 V_542 ;
void * V_187 ;
unsigned int V_498 ;
V_542 . V_342 = * V_550 ;
V_187 = & V_542 ;
V_498 = sizeof( struct V_552 ) ;
if ( V_551 )
return F_115 ( V_101 , V_5 , V_268 , V_270 ,
V_434 , V_553 , 1 , & V_187 , & V_498 ) ;
else
return F_115 ( V_101 , V_5 , V_268 , V_270 ,
V_434 , V_554 , 1 , & V_187 , & V_498 ) ;
}
int
F_120 ( const unsigned int V_101 , struct V_4 * V_5 ,
T_9 V_268 , T_9 V_270 , T_14 * V_257 )
{
unsigned int V_498 ;
V_498 = sizeof( T_14 ) ;
return F_115 ( V_101 , V_5 , V_268 , V_270 ,
V_18 -> V_19 , V_555 , 1 ,
( void * * ) & V_257 , & V_498 ) ;
}
int
F_121 ( const unsigned int V_101 , struct V_4 * V_5 ,
const T_9 V_268 , const T_9 V_270 ,
T_7 V_556 )
{
int V_35 ;
struct V_557 * V_97 = NULL ;
F_7 ( V_46 , L_68 ) ;
V_35 = F_18 ( V_54 , V_5 , ( void * * ) & V_97 ) ;
if ( V_35 )
return V_35 ;
V_97 -> V_558 = V_270 ;
V_97 -> V_559 = V_268 ;
V_97 -> V_347 = V_556 ;
V_97 -> V_2 . V_16 = F_4 ( 1 ) ;
V_35 = F_57 ( V_101 , V_5 -> V_21 , ( char * ) V_97 , V_560 ) ;
if ( V_35 ) {
F_58 ( V_5 , V_561 ) ;
F_7 ( V_46 , L_69 , V_35 ) ;
}
return V_35 ;
}
static void
F_122 ( struct V_562 * V_563 ,
struct V_564 * V_565 )
{
V_565 -> V_566 = F_33 ( V_563 -> V_567 ) *
F_33 ( V_563 -> V_568 ) ;
V_565 -> V_569 = F_123 ( V_563 -> V_570 ) ;
V_565 -> V_571 = F_123 ( V_563 -> V_572 ) ;
V_565 -> V_573 = F_123 ( V_563 -> V_574 ) ;
return;
}
static int
F_124 ( struct V_104 * V_105 , struct V_4 * V_5 , int V_575 ,
int V_576 , T_9 V_268 , T_9 V_270 )
{
int V_35 ;
struct V_388 * V_97 ;
F_7 ( V_46 , L_70 , V_575 ) ;
if ( ( V_5 -> V_21 == NULL ) || ( V_5 -> V_21 -> V_22 == NULL ) )
return - V_49 ;
V_35 = F_18 ( V_70 , V_5 , ( void * * ) & V_97 ) ;
if ( V_35 )
return V_35 ;
V_97 -> V_390 = V_577 ;
V_97 -> V_392 = V_575 ;
V_97 -> V_267 = V_268 ;
V_97 -> V_269 = V_270 ;
V_97 -> V_393 =
F_4 ( sizeof( struct V_388 ) - 1 - 4 ) ;
V_97 -> V_394 = F_5 (
V_576 + sizeof( struct V_389 ) - 1 - 4 ) ;
V_105 -> V_130 = ( char * ) V_97 ;
V_105 -> V_131 = F_29 ( V_97 ) + 4 ;
return 0 ;
}
int
F_125 ( const unsigned int V_101 , struct V_4 * V_5 ,
T_9 V_268 , T_9 V_270 , struct V_564 * V_578 )
{
struct V_389 * V_103 = NULL ;
struct V_104 V_105 ;
int V_35 = 0 ;
int V_106 ;
struct V_38 * V_21 = V_5 -> V_21 ;
struct V_562 * V_542 = NULL ;
V_35 = F_124 ( & V_105 , V_5 , V_579 ,
sizeof( struct V_562 ) ,
V_268 , V_270 ) ;
if ( V_35 )
return V_35 ;
V_35 = F_30 ( V_101 , V_21 , & V_105 , 1 , & V_106 , 0 ) ;
if ( V_35 ) {
F_58 ( V_5 , V_395 ) ;
goto V_580;
}
V_103 = (struct V_389 * ) V_105 . V_130 ;
V_542 = (struct V_562 * ) ( 4 +
F_2 ( V_103 -> V_397 ) + ( char * ) & V_103 -> V_2 ) ;
V_35 = F_79 ( F_2 ( V_103 -> V_397 ) ,
F_33 ( V_103 -> V_394 ) , & V_103 -> V_2 ,
sizeof( struct V_562 ) ) ;
if ( ! V_35 )
F_122 ( V_542 , V_578 ) ;
V_580:
F_37 ( V_106 , V_105 . V_130 ) ;
return V_35 ;
}
int
F_126 ( const unsigned int V_101 , struct V_4 * V_5 ,
T_9 V_268 , T_9 V_270 , int V_575 )
{
struct V_389 * V_103 = NULL ;
struct V_104 V_105 ;
int V_35 = 0 ;
int V_106 , V_581 , V_387 ;
struct V_38 * V_21 = V_5 -> V_21 ;
unsigned int V_582 , V_377 ;
if ( V_575 == V_583 ) {
V_581 = sizeof( V_584 ) ;
V_387 = sizeof( V_584 ) ;
} else if ( V_575 == V_585 ) {
V_581 = sizeof( V_586 ) ;
V_387 = V_587 ;
} else if ( V_575 == V_588 ) {
V_581 = sizeof( struct V_589 ) ;
V_387 = sizeof( struct V_589 ) ;
} else {
F_7 ( V_46 , L_71 , V_575 ) ;
return - V_232 ;
}
V_35 = F_124 ( & V_105 , V_5 , V_575 , V_581 ,
V_268 , V_270 ) ;
if ( V_35 )
return V_35 ;
V_35 = F_30 ( V_101 , V_21 , & V_105 , 1 , & V_106 , 0 ) ;
if ( V_35 ) {
F_58 ( V_5 , V_395 ) ;
goto V_590;
}
V_103 = (struct V_389 * ) V_105 . V_130 ;
V_582 = F_33 ( V_103 -> V_394 ) ;
V_377 = F_2 ( V_103 -> V_397 ) ;
V_35 = F_79 ( V_377 , V_582 , & V_103 -> V_2 , V_387 ) ;
if ( V_35 )
goto V_590;
if ( V_575 == V_585 )
memcpy ( & V_5 -> V_591 , 4 + V_377
+ ( char * ) & V_103 -> V_2 , F_32 (unsigned int,
rsp_len, max_len) ) ;
else if ( V_575 == V_583 )
memcpy ( & V_5 -> V_592 , 4 + V_377
+ ( char * ) & V_103 -> V_2 , sizeof( V_584 ) ) ;
else if ( V_575 == V_588 ) {
struct V_589 * V_593 = (struct V_589 * )
( 4 + V_377 + ( char * ) & V_103 -> V_2 ) ;
V_5 -> V_594 = F_33 ( V_593 -> V_31 ) ;
V_5 -> V_595 =
F_33 ( V_593 -> V_596 ) ;
}
V_590:
F_37 ( V_106 , V_105 . V_130 ) ;
return V_35 ;
}
int
F_127 ( const unsigned int V_101 , struct V_4 * V_5 ,
const T_15 V_597 , const T_15 V_270 , const T_8 V_434 ,
const T_8 V_598 , struct V_599 * V_257 )
{
int V_35 = 0 ;
struct V_600 * V_97 = NULL ;
struct V_104 V_105 [ 2 ] ;
int V_601 ;
unsigned int V_602 ;
F_7 ( V_46 , L_72 , V_598 ) ;
V_35 = F_18 ( V_66 , V_5 , ( void * * ) & V_97 ) ;
if ( V_35 )
return V_35 ;
V_97 -> V_2 . V_17 = F_5 ( V_434 ) ;
V_97 -> V_603 = F_4 ( V_598 ) ;
V_97 -> V_267 = V_597 ;
V_97 -> V_269 = V_270 ;
V_602 = V_598 * sizeof( struct V_599 ) ;
F_26 ( V_97 , V_602 - sizeof( struct V_599 ) ) ;
V_105 [ 0 ] . V_130 = ( char * ) V_97 ;
V_105 [ 0 ] . V_131 = F_29 ( V_97 ) + 4 - V_602 ;
V_105 [ 1 ] . V_130 = ( char * ) V_257 ;
V_105 [ 1 ] . V_131 = V_602 ;
F_21 ( & V_5 -> V_75 . V_604 . V_605 ) ;
V_35 = F_30 ( V_101 , V_5 -> V_21 , V_105 , 2 , & V_601 , V_606 ) ;
if ( V_35 ) {
F_7 ( V_46 , L_73 , V_35 ) ;
F_58 ( V_5 , V_607 ) ;
}
return V_35 ;
}
int
F_128 ( const unsigned int V_101 , struct V_4 * V_5 ,
const T_15 V_597 , const T_15 V_270 , const T_8 V_434 ,
const T_15 V_439 , const T_15 V_377 , const T_8 V_608 ,
const bool V_609 )
{
struct V_599 V_610 ;
V_610 . V_440 = F_94 ( V_377 ) ;
V_610 . V_438 = F_94 ( V_439 ) ;
V_610 . V_31 = F_5 ( V_608 ) ;
if ( ! V_609 && V_608 != V_611 )
V_610 . V_31 |= F_5 ( V_612 ) ;
return F_127 ( V_101 , V_5 , V_597 , V_270 , V_434 , 1 , & V_610 ) ;
}
int
F_129 ( const unsigned int V_101 , struct V_4 * V_5 ,
T_7 * V_613 , const T_5 V_614 )
{
int V_35 ;
struct V_615 * V_97 = NULL ;
F_7 ( V_46 , L_74 ) ;
V_35 = F_18 ( V_54 , V_5 , ( void * * ) & V_97 ) ;
if ( V_35 )
return V_35 ;
V_97 -> V_2 . V_16 = F_4 ( 1 ) ;
V_97 -> V_14 = F_4 ( 36 ) ;
F_26 ( V_97 , 12 ) ;
memcpy ( V_97 -> V_616 , V_613 , 16 ) ;
V_97 -> V_617 = V_614 ;
V_35 = F_57 ( V_101 , V_5 -> V_21 , ( char * ) V_97 , V_560 ) ;
if ( V_35 ) {
F_58 ( V_5 , V_561 ) ;
F_7 ( V_46 , L_75 , V_35 ) ;
}
return V_35 ;
}
