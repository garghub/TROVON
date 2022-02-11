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
V_2 -> V_12 [ 0 ] = 0xFE ;
V_2 -> V_12 [ 1 ] = 'S' ;
V_2 -> V_12 [ 2 ] = 'M' ;
V_2 -> V_12 [ 3 ] = 'B' ;
V_2 -> V_13 = F_4 ( 64 ) ;
V_2 -> V_14 = V_3 ;
V_2 -> V_15 = F_4 ( 2 ) ;
V_2 -> V_16 = F_5 ( ( T_2 ) V_17 -> V_18 ) ;
if ( ! V_5 )
goto V_19;
if ( ( V_5 -> V_20 ) && ( V_5 -> V_20 -> V_21 ) &&
( V_5 -> V_20 -> V_21 -> V_22 & V_23 ) )
V_2 -> V_24 = F_4 ( 1 ) ;
V_2 -> V_25 = V_5 -> V_26 ;
if ( V_5 -> V_20 )
V_2 -> V_27 = V_5 -> V_20 -> V_28 ;
if ( V_5 -> V_20 && V_5 -> V_20 -> V_21 && V_5 -> V_20 -> V_21 -> V_29 )
V_2 -> V_30 |= V_31 ;
V_19:
V_7 -> V_32 = F_4 ( V_9 ) ;
return;
}
static int
F_6 ( T_1 V_33 , struct V_4 * V_5 )
{
int V_34 = 0 ;
struct V_35 * V_36 ;
struct V_37 * V_20 ;
struct V_38 * V_21 ;
if ( V_5 == NULL )
return V_34 ;
if ( V_33 == V_39 )
return V_34 ;
if ( V_5 -> V_40 == V_41 ) {
if ( ( V_33 != V_42 ) &&
( V_33 != V_43 ) &&
( V_33 != V_44 ) ) {
F_7 ( V_45 , L_1 ,
V_33 ) ;
return - V_46 ;
}
}
if ( ( ! V_5 -> V_20 ) || ( V_5 -> V_20 -> V_47 == V_41 ) ||
( ! V_5 -> V_20 -> V_21 ) )
return - V_48 ;
V_20 = V_5 -> V_20 ;
V_21 = V_20 -> V_21 ;
while ( V_21 -> V_49 == V_50 ) {
switch ( V_33 ) {
case V_44 :
case V_51 :
case V_52 :
case V_53 :
return - V_54 ;
}
F_8 ( V_21 -> V_55 ,
( V_21 -> V_49 != V_50 ) , 10 * V_56 ) ;
if ( V_21 -> V_49 != V_50 )
break;
if ( ! V_5 -> V_57 ) {
F_7 ( V_45 , L_2 ) ;
return - V_58 ;
}
}
if ( ! V_5 -> V_20 -> V_59 && ! V_5 -> V_59 )
return V_34 ;
V_36 = F_9 () ;
F_10 ( & V_5 -> V_20 -> V_60 ) ;
V_34 = F_11 ( 0 , V_5 -> V_20 ) ;
if ( ! V_34 && V_5 -> V_20 -> V_59 )
V_34 = F_12 ( 0 , V_5 -> V_20 , V_36 ) ;
if ( V_34 || ! V_5 -> V_59 ) {
F_13 ( & V_5 -> V_20 -> V_60 ) ;
goto V_19;
}
F_14 ( V_5 ) ;
V_34 = F_15 ( 0 , V_5 -> V_20 , V_5 -> V_61 , V_5 , V_36 ) ;
F_13 ( & V_5 -> V_20 -> V_60 ) ;
F_7 ( V_45 , L_3 , V_34 ) ;
if ( V_34 )
goto V_19;
F_16 ( & V_62 ) ;
V_19:
switch ( V_33 ) {
case V_63 :
case V_64 :
case V_42 :
case V_65 :
case V_66 :
case V_67 :
case V_68 :
case V_69 :
case V_70 :
return - V_54 ;
}
F_17 ( V_36 ) ;
return V_34 ;
}
static int
F_18 ( T_1 V_33 , struct V_4 * V_5 ,
void * * V_71 )
{
int V_34 = 0 ;
V_34 = F_6 ( V_33 , V_5 ) ;
if ( V_34 )
return V_34 ;
* V_71 = F_19 () ;
if ( * V_71 == NULL ) {
return - V_72 ;
}
F_1 ( (struct V_1 * ) * V_71 , V_33 , V_5 ) ;
if ( V_5 != NULL ) {
#ifdef F_20
T_3 V_73 = F_2 ( V_33 ) ;
F_21 ( & V_5 -> V_74 . V_75 . V_76 [ V_73 ] ) ;
#endif
F_21 ( & V_5 -> V_77 ) ;
}
return V_34 ;
}
static void
F_22 ( struct V_78 * V_79 )
{
V_79 -> V_80 = V_81 ;
V_79 -> V_82 = F_4 ( 38 ) ;
V_79 -> V_83 = F_4 ( 1 ) ;
V_79 -> V_84 = F_4 ( V_85 ) ;
F_23 ( V_79 -> V_86 , V_85 ) ;
V_79 -> V_87 = V_88 ;
}
static void
F_24 ( struct V_89 * V_79 )
{
V_79 -> V_80 = V_90 ;
V_79 -> V_82 = F_4 ( 6 ) ;
V_79 -> V_91 = F_4 ( 2 ) ;
V_79 -> V_92 [ 0 ] = V_93 ;
V_79 -> V_92 [ 1 ] = V_94 ;
}
static void
F_25 ( struct V_95 * V_96 )
{
char * V_79 = ( char * ) V_96 + V_97 + 4 ;
F_22 ( (struct V_78 * ) V_79 ) ;
V_79 += 2 + sizeof( struct V_78 ) ;
F_24 ( (struct V_89 * ) V_79 ) ;
V_96 -> V_98 = F_5 ( V_97 ) ;
V_96 -> V_99 = F_4 ( 2 ) ;
F_26 ( V_96 , 4 + sizeof( struct V_78 ) + 2
+ sizeof( struct V_89 ) ) ;
}
static void F_25 ( struct V_95 * V_96 )
{
return;
}
int
F_27 ( const unsigned int V_100 , struct V_37 * V_20 )
{
struct V_95 * V_96 ;
struct V_101 * V_102 ;
struct V_103 V_104 [ 1 ] ;
int V_34 = 0 ;
int V_105 ;
struct V_38 * V_21 = V_20 -> V_21 ;
int V_106 , V_107 ;
char * V_108 ;
int V_109 = V_110 ;
F_7 ( V_45 , L_4 ) ;
if ( ! V_21 ) {
F_28 ( 1 , L_5 , V_111 ) ;
return - V_48 ;
}
V_34 = F_18 ( V_112 , NULL , ( void * * ) & V_96 ) ;
if ( V_34 )
return V_34 ;
V_96 -> V_2 . V_27 = 0 ;
V_96 -> V_113 [ 0 ] = F_4 ( V_20 -> V_21 -> V_114 -> V_115 ) ;
V_96 -> V_116 = F_4 ( 1 ) ;
F_26 ( V_96 , 2 ) ;
if ( V_20 -> V_29 )
V_96 -> V_117 = F_4 ( V_118 ) ;
else if ( V_119 & V_120 )
V_96 -> V_117 = F_4 ( V_121 ) ;
else
V_96 -> V_117 = 0 ;
V_96 -> V_122 = F_5 ( V_20 -> V_21 -> V_114 -> V_123 ) ;
if ( V_20 -> V_21 -> V_114 -> V_115 == V_124 )
memset ( V_96 -> V_125 , 0 , V_126 ) ;
else {
memcpy ( V_96 -> V_125 , V_21 -> V_127 ,
V_126 ) ;
if ( V_20 -> V_21 -> V_114 -> V_115 == V_128 )
F_25 ( V_96 ) ;
}
V_104 [ 0 ] . V_129 = ( char * ) V_96 ;
V_104 [ 0 ] . V_130 = F_29 ( V_96 ) + 4 ;
V_34 = F_30 ( V_100 , V_20 , V_104 , 1 , & V_105 , V_109 ) ;
V_102 = (struct V_101 * ) V_104 [ 0 ] . V_129 ;
if ( V_34 != 0 )
goto V_131;
F_7 ( V_45 , L_6 , V_102 -> V_117 ) ;
if ( V_102 -> V_132 == F_4 ( V_124 ) )
F_7 ( V_45 , L_7 ) ;
else if ( V_102 -> V_132 == F_4 ( V_133 ) )
F_7 ( V_45 , L_8 ) ;
else if ( V_102 -> V_132 == F_4 ( V_134 ) )
F_7 ( V_45 , L_9 ) ;
else if ( V_102 -> V_132 == F_4 ( V_135 ) )
F_7 ( V_45 , L_10 ) ;
#ifdef F_31
else if ( V_102 -> V_132 == F_4 ( V_128 ) )
F_7 ( V_45 , L_11 ) ;
#endif
else {
F_7 ( V_136 , L_12 ,
F_2 ( V_102 -> V_132 ) ) ;
V_34 = - V_48 ;
goto V_131;
}
V_21 -> V_137 = F_2 ( V_102 -> V_132 ) ;
V_21 -> V_138 = V_139 ;
V_21 -> V_140 = F_32 (unsigned int, le32_to_cpu(rsp->MaxTransactSize),
SMB2_MAX_BUFFER_SIZE) ;
V_21 -> V_141 = F_33 ( V_102 -> V_142 ) ;
V_21 -> V_143 = F_33 ( V_102 -> V_144 ) ;
V_21 -> V_145 = F_2 ( V_102 -> V_117 ) ;
V_21 -> V_22 = F_33 ( V_102 -> V_122 ) ;
V_21 -> V_22 |= V_146 | V_147 ;
V_108 = F_34 ( & V_106 , & V_107 ,
& V_102 -> V_2 ) ;
if ( V_107 == 0 )
F_7 ( V_45 , L_13 ) ;
V_34 = F_35 ( V_21 , V_20 -> V_29 ) ;
if ( V_34 )
goto V_131;
if ( V_107 ) {
V_34 = F_36 ( V_108 , V_107 , V_21 ) ;
if ( V_34 == 1 )
V_34 = 0 ;
else if ( V_34 == 0 )
V_34 = - V_48 ;
}
V_131:
F_37 ( V_105 , V_102 ) ;
return V_34 ;
}
int F_38 ( const unsigned int V_100 , struct V_4 * V_5 )
{
int V_34 = 0 ;
struct V_148 V_149 ;
struct V_150 * V_151 ;
T_4 V_152 ;
F_7 ( V_45 , L_14 ) ;
if ( V_5 -> V_20 -> V_21 -> V_29 == false )
return 0 ;
V_149 . V_122 =
F_5 ( V_5 -> V_20 -> V_21 -> V_114 -> V_123 ) ;
memcpy ( V_149 . V_153 , V_5 -> V_20 -> V_21 -> V_127 ,
V_126 ) ;
if ( V_5 -> V_20 -> V_29 )
V_149 . V_117 =
F_4 ( V_118 ) ;
else if ( V_119 & V_120 )
V_149 . V_117 =
F_4 ( V_121 ) ;
else
V_149 . V_117 = 0 ;
V_149 . V_116 = F_4 ( 1 ) ;
V_149 . V_113 [ 0 ] =
F_4 ( V_5 -> V_20 -> V_21 -> V_114 -> V_115 ) ;
V_34 = F_39 ( V_100 , V_5 , V_154 , V_154 ,
V_155 , true ,
( char * ) & V_149 , sizeof( struct V_148 ) ,
( char * * ) & V_151 , & V_152 ) ;
if ( V_34 != 0 ) {
F_7 ( V_136 , L_15 , V_34 ) ;
return - V_48 ;
}
if ( V_152 != sizeof( struct V_150 ) ) {
F_7 ( V_136 , L_16 ) ;
return - V_48 ;
}
if ( V_151 -> V_156 !=
F_4 ( V_5 -> V_20 -> V_21 -> V_114 -> V_115 ) )
goto V_157;
if ( V_151 -> V_117 != F_4 ( V_5 -> V_20 -> V_21 -> V_145 ) )
goto V_157;
if ( ( F_33 ( V_151 -> V_122 ) | V_146 |
V_147 ) != V_5 -> V_20 -> V_21 -> V_22 )
goto V_157;
F_7 ( V_45 , L_17 ) ;
return 0 ;
V_157:
F_7 ( V_136 , L_18 ) ;
return - V_48 ;
}
int
F_40 ( const unsigned int V_100 , struct V_37 * V_20 ,
const struct V_35 * V_158 )
{
struct V_159 * V_96 ;
struct V_160 * V_102 = NULL ;
struct V_103 V_104 [ 2 ] ;
int V_34 = 0 ;
int V_105 = V_161 ;
T_5 V_162 = V_163 ;
struct V_38 * V_21 = V_20 -> V_21 ;
T_6 V_107 = 0 ;
struct V_164 * V_165 = NULL ;
char * V_108 = NULL ;
char * V_166 = NULL ;
bool V_167 = false ;
F_7 ( V_45 , L_19 ) ;
if ( ! V_21 ) {
F_28 ( 1 , L_5 , V_111 ) ;
return - V_48 ;
}
F_41 ( V_20 -> V_168 . V_169 ) ;
V_20 -> V_168 . V_169 = NULL ;
V_20 -> V_170 = F_42 ( sizeof( struct V_171 ) , V_172 ) ;
if ( ! V_20 -> V_170 )
return - V_72 ;
V_20 -> V_170 -> V_173 = true ;
if ( V_20 -> V_174 != V_175 && V_20 -> V_174 != V_176 )
V_20 -> V_174 = V_176 ;
V_177:
if ( V_162 == V_178 )
V_162 = V_179 ;
V_34 = F_18 ( V_180 , NULL , ( void * * ) & V_96 ) ;
if ( V_34 )
return V_34 ;
V_96 -> V_2 . V_27 = 0 ;
V_96 -> V_30 = 0 ;
V_96 -> V_2 . V_15 = F_4 ( 3 ) ;
if ( V_21 -> V_29 )
V_96 -> V_117 = V_118 ;
else if ( V_119 & V_120 )
V_96 -> V_117 = V_121 ;
else
V_96 -> V_117 = 0 ;
V_96 -> V_122 = 0 ;
V_96 -> V_181 = 0 ;
V_104 [ 0 ] . V_129 = ( char * ) V_96 ;
V_104 [ 0 ] . V_130 = F_29 ( V_96 ) + 4 - 1 ;
if ( V_20 -> V_174 == V_175 ) {
#ifdef F_43
struct V_182 * V_183 ;
V_165 = F_44 ( V_20 ) ;
if ( F_45 ( V_165 ) ) {
V_34 = F_46 ( V_165 ) ;
V_165 = NULL ;
goto V_184;
}
V_183 = V_165 -> V_185 . V_186 [ 0 ] ;
if ( V_183 -> V_187 != V_188 ) {
F_7 ( V_136 ,
L_20 ,
V_188 , V_183 -> V_187 ) ;
V_34 = - V_189 ;
goto V_184;
}
V_20 -> V_168 . V_169 = F_47 ( V_183 -> V_186 , V_183 -> V_190 ,
V_172 ) ;
if ( ! V_20 -> V_168 . V_169 ) {
F_7 ( V_136 ,
L_21 ,
V_183 -> V_190 ) ;
V_34 = - V_72 ;
goto V_184;
}
V_20 -> V_168 . V_191 = V_183 -> V_190 ;
V_107 = V_183 -> V_192 ;
V_104 [ 1 ] . V_129 = V_183 -> V_186 + V_183 -> V_190 ;
V_104 [ 1 ] . V_130 = V_107 ;
#else
V_34 = - V_193 ;
goto V_184;
#endif
} else if ( V_162 == V_163 ) {
V_166 = F_42 ( sizeof( struct V_194 ) ,
V_172 ) ;
if ( V_166 == NULL ) {
V_34 = - V_72 ;
goto V_184;
}
F_48 ( V_166 , V_20 ) ;
if ( V_167 ) {
F_7 ( V_136 , L_22 ) ;
V_34 = - V_193 ;
F_41 ( V_166 ) ;
goto V_184;
} else {
V_107 = sizeof( struct V_194 ) ;
V_108 = V_166 ;
}
V_104 [ 1 ] . V_129 = V_108 ;
V_104 [ 1 ] . V_130 = V_107 ;
} else if ( V_162 == V_179 ) {
V_96 -> V_2 . V_27 = V_20 -> V_28 ;
V_166 = F_49 ( sizeof( struct V_194 ) + 500 ,
V_172 ) ;
if ( V_166 == NULL ) {
V_34 = - V_72 ;
goto V_184;
}
V_34 = F_50 ( V_166 , & V_107 , V_20 ,
V_158 ) ;
if ( V_34 ) {
F_7 ( V_45 , L_23 ,
V_34 ) ;
goto V_184;
}
if ( V_167 ) {
F_7 ( V_136 , L_22 ) ;
V_34 = - V_193 ;
F_41 ( V_166 ) ;
goto V_184;
} else {
V_108 = V_166 ;
}
V_104 [ 1 ] . V_129 = V_108 ;
V_104 [ 1 ] . V_130 = V_107 ;
} else {
F_7 ( V_136 , L_24 ) ;
V_34 = - V_48 ;
goto V_184;
}
V_96 -> V_195 =
F_4 ( sizeof( struct V_159 ) -
1 - 4 ) ;
V_96 -> V_196 = F_4 ( V_107 ) ;
F_26 ( V_96 , V_107 - 1 ) ;
V_34 = F_30 ( V_100 , V_20 , V_104 , 2 , & V_105 ,
V_197 | V_110 ) ;
F_41 ( V_108 ) ;
V_102 = (struct V_160 * ) V_104 [ 0 ] . V_129 ;
V_20 -> V_28 = V_102 -> V_2 . V_27 ;
if ( V_105 != V_161 &&
V_102 -> V_2 . V_198 == V_199 ) {
if ( V_162 != V_163 ) {
F_7 ( V_136 , L_25 ) ;
goto V_184;
}
if ( F_51 ( struct V_160 , V_200 ) - 4 !=
F_2 ( V_102 -> V_195 ) ) {
F_7 ( V_136 , L_26 ,
F_2 ( V_102 -> V_195 ) ) ;
V_34 = - V_48 ;
goto V_184;
}
V_162 = V_178 ;
V_34 = 0 ;
V_34 = F_52 ( V_102 -> V_200 ,
F_2 ( V_102 -> V_196 ) , V_20 ) ;
}
if ( V_34 != 0 )
goto V_184;
V_20 -> V_201 = F_2 ( V_102 -> V_202 ) ;
if ( V_20 -> V_201 & V_203 )
F_7 ( V_136 , L_27 ) ;
V_184:
F_37 ( V_105 , V_102 ) ;
if ( ( V_162 == V_178 ) && ( V_34 == 0 ) )
goto V_177;
if ( ! V_34 ) {
F_10 ( & V_21 -> V_204 ) ;
if ( V_21 -> V_29 && V_21 -> V_205 -> V_206 ) {
V_34 = V_21 -> V_205 -> V_206 ( V_20 ) ;
F_41 ( V_20 -> V_168 . V_169 ) ;
V_20 -> V_168 . V_169 = NULL ;
if ( V_34 ) {
F_7 ( V_45 ,
L_28 ) ;
F_13 ( & V_21 -> V_204 ) ;
goto V_207;
}
}
if ( ! V_21 -> V_208 ) {
V_21 -> V_209 = 0x2 ;
V_21 -> V_208 = true ;
}
F_13 ( & V_21 -> V_204 ) ;
F_7 ( V_45 , L_29 ) ;
F_53 ( & V_210 ) ;
V_20 -> V_47 = V_211 ;
V_20 -> V_59 = false ;
F_54 ( & V_210 ) ;
}
V_207:
if ( ! V_21 -> V_29 ) {
F_41 ( V_20 -> V_168 . V_169 ) ;
V_20 -> V_168 . V_169 = NULL ;
}
if ( V_165 ) {
F_55 ( V_165 ) ;
F_56 ( V_165 ) ;
}
F_41 ( V_20 -> V_170 ) ;
return V_34 ;
}
int
F_57 ( const unsigned int V_100 , struct V_37 * V_20 )
{
struct V_212 * V_96 ;
int V_34 = 0 ;
struct V_38 * V_21 ;
F_7 ( V_45 , L_30 , V_20 ) ;
if ( V_20 && ( V_20 -> V_21 ) )
V_21 = V_20 -> V_21 ;
else
return - V_48 ;
if ( V_20 -> V_59 )
goto V_213;
V_34 = F_18 ( V_214 , NULL , ( void * * ) & V_96 ) ;
if ( V_34 )
return V_34 ;
V_96 -> V_2 . V_27 = V_20 -> V_28 ;
if ( V_21 -> V_29 )
V_96 -> V_2 . V_30 |= V_31 ;
V_34 = F_58 ( V_100 , V_20 , ( char * ) & V_96 -> V_2 , 0 ) ;
V_213:
return V_34 ;
}
static inline void F_59 ( struct V_4 * V_5 , T_3 V_215 )
{
F_21 ( & V_5 -> V_74 . V_75 . V_216 [ V_215 ] ) ;
}
static inline void F_60 ( struct V_4 * V_5 )
{
V_5 -> V_217 = 256 ;
V_5 -> V_218 = 1048576 ;
V_5 -> V_219 = 16777216 ;
}
int
F_15 ( const unsigned int V_100 , struct V_37 * V_20 , const char * V_220 ,
struct V_4 * V_5 , const struct V_35 * V_221 )
{
struct V_222 * V_96 ;
struct V_223 * V_102 = NULL ;
struct V_103 V_104 [ 2 ] ;
int V_34 = 0 ;
int V_105 ;
int V_224 ;
struct V_38 * V_21 ;
T_1 * V_225 = NULL ;
F_7 ( V_45 , L_31 ) ;
if ( ( V_20 -> V_21 ) && V_220 )
V_21 = V_20 -> V_21 ;
else
return - V_48 ;
if ( V_5 && V_5 -> V_226 )
return - V_227 ;
if ( ( V_5 && V_5 -> V_228 ) &&
( ( V_20 -> V_21 -> V_22 & V_229 ) == 0 ) ) {
F_7 ( V_136 , L_32 ) ;
return - V_193 ;
}
V_225 = F_42 ( V_230 * 2 , V_172 ) ;
if ( V_225 == NULL )
return - V_72 ;
V_224 = F_61 ( V_225 , V_220 , strlen ( V_220 ) , V_221 ) + 1 ;
V_224 *= 2 ;
if ( V_224 < 2 ) {
F_41 ( V_225 ) ;
return - V_231 ;
}
V_34 = F_18 ( V_39 , V_5 , ( void * * ) & V_96 ) ;
if ( V_34 ) {
F_41 ( V_225 ) ;
return V_34 ;
}
if ( V_5 == NULL ) {
V_96 -> V_2 . V_27 = V_20 -> V_28 ;
}
V_104 [ 0 ] . V_129 = ( char * ) V_96 ;
V_104 [ 0 ] . V_130 = F_29 ( V_96 ) + 4 - 1 ;
V_96 -> V_232 = F_4 ( sizeof( struct V_222 )
- 1 - 4 ) ;
V_96 -> V_233 = F_4 ( V_224 - 2 ) ;
V_104 [ 1 ] . V_129 = V_225 ;
V_104 [ 1 ] . V_130 = V_224 ;
F_26 ( V_96 , V_224 - 1 ) ;
V_34 = F_30 ( V_100 , V_20 , V_104 , 2 , & V_105 , 0 ) ;
V_102 = (struct V_223 * ) V_104 [ 0 ] . V_129 ;
if ( V_34 != 0 ) {
if ( V_5 ) {
F_59 ( V_5 , V_234 ) ;
V_5 -> V_59 = true ;
}
goto V_235;
}
if ( V_5 == NULL ) {
V_20 -> V_236 = V_102 -> V_2 . V_25 ;
goto V_237;
}
if ( V_102 -> V_238 & V_239 )
F_7 ( V_45 , L_33 ) ;
else if ( V_102 -> V_238 & V_240 ) {
V_5 -> V_241 = true ;
F_7 ( V_45 , L_34 ) ;
} else if ( V_102 -> V_238 & V_242 ) {
V_5 -> V_243 = true ;
F_7 ( V_45 , L_35 ) ;
} else {
F_7 ( V_136 , L_36 , V_102 -> V_238 ) ;
V_34 = - V_193 ;
goto V_235;
}
V_5 -> V_244 = F_33 ( V_102 -> V_245 ) ;
V_5 -> V_22 = V_102 -> V_122 ;
V_5 -> V_246 = F_33 ( V_102 -> V_247 ) ;
V_5 -> V_40 = V_211 ;
V_5 -> V_59 = false ;
V_5 -> V_26 = V_102 -> V_2 . V_25 ;
F_62 ( V_5 -> V_61 , V_220 , sizeof( V_5 -> V_61 ) ) ;
if ( ( V_102 -> V_122 & V_248 ) &&
( ( V_5 -> V_244 & V_249 ) == 0 ) )
F_7 ( V_136 , L_37 ) ;
F_60 ( V_5 ) ;
if ( V_5 -> V_244 & V_250 )
F_7 ( V_136 , L_38 ) ;
if ( V_5 -> V_20 -> V_21 -> V_205 -> V_251 )
V_34 = V_5 -> V_20 -> V_21 -> V_205 -> V_251 ( V_100 , V_5 ) ;
V_237:
F_37 ( V_105 , V_102 ) ;
F_41 ( V_225 ) ;
return V_34 ;
V_235:
if ( V_102 -> V_2 . V_198 == V_252 ) {
F_7 ( V_136 , L_39 , V_220 ) ;
if ( V_5 )
V_5 -> V_226 = true ;
}
goto V_237;
}
int
F_63 ( const unsigned int V_100 , struct V_4 * V_5 )
{
struct V_253 * V_96 ;
int V_34 = 0 ;
struct V_38 * V_21 ;
struct V_37 * V_20 = V_5 -> V_20 ;
F_7 ( V_45 , L_40 ) ;
if ( V_20 && ( V_20 -> V_21 ) )
V_21 = V_20 -> V_21 ;
else
return - V_48 ;
if ( ( V_5 -> V_59 ) || ( V_5 -> V_20 -> V_59 ) )
return 0 ;
V_34 = F_18 ( V_44 , V_5 , ( void * * ) & V_96 ) ;
if ( V_34 )
return V_34 ;
V_34 = F_58 ( V_100 , V_20 , ( char * ) & V_96 -> V_2 , 0 ) ;
if ( V_34 )
F_59 ( V_5 , V_254 ) ;
return V_34 ;
}
static struct V_255 *
F_64 ( void )
{
struct V_255 * V_256 ;
V_256 = F_49 ( sizeof( struct V_255 ) , V_172 ) ;
if ( ! V_256 )
return NULL ;
V_256 -> V_257 . V_258 = F_4 ( F_51
( struct V_255 , V_259 ) ) ;
V_256 -> V_257 . V_82 = F_5 ( 16 ) ;
V_256 -> V_257 . V_260 = F_4 ( F_51
( struct V_255 , V_261 ) ) ;
V_256 -> V_257 . V_262 = F_4 ( 4 ) ;
V_256 -> V_261 [ 0 ] = 'D' ;
V_256 -> V_261 [ 1 ] = 'H' ;
V_256 -> V_261 [ 2 ] = 'n' ;
V_256 -> V_261 [ 3 ] = 'Q' ;
return V_256 ;
}
static struct V_255 *
F_65 ( struct V_263 * V_264 )
{
struct V_255 * V_256 ;
V_256 = F_49 ( sizeof( struct V_255 ) , V_172 ) ;
if ( ! V_256 )
return NULL ;
V_256 -> V_257 . V_258 = F_4 ( F_51
( struct V_255 , V_259 ) ) ;
V_256 -> V_257 . V_82 = F_5 ( 16 ) ;
V_256 -> V_257 . V_260 = F_4 ( F_51
( struct V_255 , V_261 ) ) ;
V_256 -> V_257 . V_262 = F_4 ( 4 ) ;
V_256 -> V_259 . V_265 . V_266 = V_264 -> V_267 ;
V_256 -> V_259 . V_265 . V_268 = V_264 -> V_269 ;
V_256 -> V_261 [ 0 ] = 'D' ;
V_256 -> V_261 [ 1 ] = 'H' ;
V_256 -> V_261 [ 2 ] = 'n' ;
V_256 -> V_261 [ 3 ] = 'C' ;
return V_256 ;
}
static T_7
F_66 ( struct V_38 * V_21 , struct V_270 * V_102 ,
unsigned int * V_271 )
{
char * V_272 ;
struct V_273 * V_274 ;
unsigned int V_275 = 0 ;
char * V_276 ;
V_272 = ( char * ) V_102 + 4 + F_33 ( V_102 -> V_277 ) ;
V_274 = (struct V_273 * ) V_272 ;
do {
V_274 = (struct V_273 * ) ( ( char * ) V_274 + V_275 ) ;
V_276 = F_2 ( V_274 -> V_260 ) + ( char * ) V_274 ;
if ( F_2 ( V_274 -> V_262 ) != 4 ||
strncmp ( V_276 , L_41 , 4 ) ) {
V_275 = F_33 ( V_274 -> V_278 ) ;
continue;
}
return V_21 -> V_205 -> V_279 ( V_274 , V_271 ) ;
} while ( V_275 != 0 );
return 0 ;
}
static int
F_67 ( struct V_38 * V_21 , struct V_103 * V_104 ,
unsigned int * V_280 , T_7 * V_281 )
{
struct V_282 * V_96 = V_104 [ 0 ] . V_129 ;
unsigned int V_283 = * V_280 ;
V_104 [ V_283 ] . V_129 = V_21 -> V_205 -> V_284 ( V_281 + 1 , * V_281 ) ;
if ( V_104 [ V_283 ] . V_129 == NULL )
return - V_72 ;
V_104 [ V_283 ] . V_130 = V_21 -> V_114 -> V_285 ;
V_96 -> V_286 = V_287 ;
if ( ! V_96 -> V_277 )
V_96 -> V_277 = F_5 (
sizeof( struct V_282 ) - 4 +
V_104 [ V_283 - 1 ] . V_130 ) ;
F_68 ( & V_96 -> V_288 ,
V_21 -> V_114 -> V_285 ) ;
F_26 ( & V_96 -> V_2 , V_21 -> V_114 -> V_285 ) ;
* V_280 = V_283 + 1 ;
return 0 ;
}
static struct V_289 *
F_69 ( struct V_263 * V_290 )
{
struct V_289 * V_256 ;
V_256 = F_49 ( sizeof( struct V_289 ) , V_172 ) ;
if ( ! V_256 )
return NULL ;
V_256 -> V_257 . V_258 = F_4 ( F_51
( struct V_289 , V_291 ) ) ;
V_256 -> V_257 . V_82 = F_5 ( sizeof( struct V_292 ) ) ;
V_256 -> V_257 . V_260 = F_4 ( F_51
( struct V_289 , V_261 ) ) ;
V_256 -> V_257 . V_262 = F_4 ( 4 ) ;
V_256 -> V_291 . V_293 = 0 ;
V_256 -> V_291 . V_30 = F_5 ( V_294 ) ;
F_23 ( V_256 -> V_291 . V_295 , 16 ) ;
memcpy ( V_290 -> V_296 , V_256 -> V_291 . V_295 , 16 ) ;
V_256 -> V_261 [ 0 ] = 'D' ;
V_256 -> V_261 [ 1 ] = 'H' ;
V_256 -> V_261 [ 2 ] = '2' ;
V_256 -> V_261 [ 3 ] = 'Q' ;
return V_256 ;
}
static struct V_297 *
F_70 ( struct V_263 * V_264 )
{
struct V_297 * V_256 ;
V_256 = F_49 ( sizeof( struct V_297 ) ,
V_172 ) ;
if ( ! V_256 )
return NULL ;
V_256 -> V_257 . V_258 =
F_4 ( F_51 ( struct V_297 ,
V_291 ) ) ;
V_256 -> V_257 . V_82 =
F_5 ( sizeof( struct V_298 ) ) ;
V_256 -> V_257 . V_260 =
F_4 ( F_51 ( struct V_297 ,
V_261 ) ) ;
V_256 -> V_257 . V_262 = F_4 ( 4 ) ;
V_256 -> V_291 . V_265 . V_266 = V_264 -> V_267 ;
V_256 -> V_291 . V_265 . V_268 = V_264 -> V_269 ;
V_256 -> V_291 . V_30 = F_5 ( V_294 ) ;
memcpy ( V_256 -> V_291 . V_295 , V_264 -> V_296 , 16 ) ;
V_256 -> V_261 [ 0 ] = 'D' ;
V_256 -> V_261 [ 1 ] = 'H' ;
V_256 -> V_261 [ 2 ] = '2' ;
V_256 -> V_261 [ 3 ] = 'C' ;
return V_256 ;
}
static int
F_71 ( struct V_103 * V_104 , unsigned int * V_280 ,
struct V_299 * V_300 )
{
struct V_282 * V_96 = V_104 [ 0 ] . V_129 ;
unsigned int V_283 = * V_280 ;
V_104 [ V_283 ] . V_129 = F_69 ( V_300 -> V_264 ) ;
if ( V_104 [ V_283 ] . V_129 == NULL )
return - V_72 ;
V_104 [ V_283 ] . V_130 = sizeof( struct V_289 ) ;
if ( ! V_96 -> V_277 )
V_96 -> V_277 =
F_5 ( sizeof( struct V_282 ) - 4 +
V_104 [ 1 ] . V_130 ) ;
F_68 ( & V_96 -> V_288 , sizeof( struct V_289 ) ) ;
F_26 ( & V_96 -> V_2 , sizeof( struct V_289 ) ) ;
* V_280 = V_283 + 1 ;
return 0 ;
}
static int
F_72 ( struct V_103 * V_104 , unsigned int * V_280 ,
struct V_299 * V_300 )
{
struct V_282 * V_96 = V_104 [ 0 ] . V_129 ;
unsigned int V_283 = * V_280 ;
V_300 -> V_301 = false ;
V_104 [ V_283 ] . V_129 = F_70 ( V_300 -> V_264 ) ;
if ( V_104 [ V_283 ] . V_129 == NULL )
return - V_72 ;
V_104 [ V_283 ] . V_130 = sizeof( struct V_297 ) ;
if ( ! V_96 -> V_277 )
V_96 -> V_277 =
F_5 ( sizeof( struct V_282 ) - 4 +
V_104 [ 1 ] . V_130 ) ;
F_68 ( & V_96 -> V_288 ,
sizeof( struct V_297 ) ) ;
F_26 ( & V_96 -> V_2 ,
sizeof( struct V_297 ) ) ;
* V_280 = V_283 + 1 ;
return 0 ;
}
static int
F_73 ( struct V_103 * V_104 , unsigned int * V_280 ,
struct V_299 * V_300 , bool V_302 )
{
struct V_282 * V_96 = V_104 [ 0 ] . V_129 ;
unsigned int V_283 = * V_280 ;
if ( V_302 ) {
if ( V_300 -> V_301 )
return F_72 ( V_104 , V_280 ,
V_300 ) ;
else
return F_71 ( V_104 , V_280 , V_300 ) ;
}
if ( V_300 -> V_301 ) {
V_104 [ V_283 ] . V_129 = F_65 ( V_300 -> V_264 ) ;
V_300 -> V_301 = false ;
} else
V_104 [ V_283 ] . V_129 = F_64 () ;
if ( V_104 [ V_283 ] . V_129 == NULL )
return - V_72 ;
V_104 [ V_283 ] . V_130 = sizeof( struct V_255 ) ;
if ( ! V_96 -> V_277 )
V_96 -> V_277 =
F_5 ( sizeof( struct V_282 ) - 4 +
V_104 [ 1 ] . V_130 ) ;
F_68 ( & V_96 -> V_288 , sizeof( struct V_255 ) ) ;
F_26 ( & V_96 -> V_2 , sizeof( struct V_255 ) ) ;
* V_280 = V_283 + 1 ;
return 0 ;
}
int
F_74 ( const unsigned int V_100 , struct V_299 * V_300 , T_1 * V_303 ,
T_7 * V_281 , struct V_304 * V_256 ,
struct V_305 * * V_306 )
{
struct V_282 * V_96 ;
struct V_270 * V_102 ;
struct V_38 * V_21 ;
struct V_4 * V_5 = V_300 -> V_5 ;
struct V_37 * V_20 = V_5 -> V_20 ;
struct V_103 V_104 [ 4 ] ;
int V_105 ;
int V_307 ;
T_1 * V_308 = NULL ;
int V_309 ;
int V_34 = 0 ;
unsigned int V_310 = 2 ;
T_8 V_311 = 0 ;
char * V_312 = NULL , * V_313 = NULL ;
F_7 ( V_45 , L_42 ) ;
if ( V_20 && ( V_20 -> V_21 ) )
V_21 = V_20 -> V_21 ;
else
return - V_48 ;
V_34 = F_18 ( V_43 , V_5 , ( void * * ) & V_96 ) ;
if ( V_34 )
return V_34 ;
if ( V_300 -> V_314 & V_315 )
V_311 |= V_316 ;
if ( V_300 -> V_314 & V_317 )
V_311 |= V_318 ;
V_96 -> V_319 = V_320 ;
V_96 -> V_321 = F_5 ( V_300 -> V_322 ) ;
V_96 -> V_323 = F_5 ( V_311 ) ;
V_96 -> V_324 = V_325 ;
V_96 -> V_326 = F_5 ( V_300 -> V_327 ) ;
V_96 -> V_328 = F_5 ( V_300 -> V_314 & V_329 ) ;
V_307 = ( 2 * F_75 ( ( V_330 * ) V_303 , V_331 ) ) + 2 ;
V_96 -> V_260 = F_4 ( sizeof( struct V_282 ) - 4 ) ;
V_104 [ 0 ] . V_129 = ( char * ) V_96 ;
V_104 [ 0 ] . V_130 = F_29 ( V_96 ) + 4 ;
V_96 -> V_262 = F_4 ( V_307 - 2 ) ;
V_104 [ 0 ] . V_130 -- ;
if ( V_307 % 8 != 0 ) {
V_309 = V_307 / 8 * 8 ;
if ( V_309 < V_307 )
V_309 += 8 ;
V_308 = F_49 ( V_309 , V_172 ) ;
if ( ! V_308 )
return - V_72 ;
memcpy ( ( char * ) V_308 , ( const char * ) V_303 ,
V_307 ) ;
V_307 = V_309 ;
V_303 = V_308 ;
}
V_104 [ 1 ] . V_130 = V_307 ;
V_104 [ 1 ] . V_129 = V_303 ;
F_26 ( V_96 , V_307 - 1 ) ;
if ( ! V_21 -> V_332 )
* V_281 = V_333 ;
if ( ! ( V_21 -> V_22 & V_334 ) ||
* V_281 == V_333 )
V_96 -> V_286 = * V_281 ;
else {
V_34 = F_67 ( V_21 , V_104 , & V_310 , V_281 ) ;
if ( V_34 ) {
F_76 ( V_96 ) ;
F_41 ( V_308 ) ;
return V_34 ;
}
V_313 = V_104 [ V_310 - 1 ] . V_129 ;
}
if ( * V_281 == V_335 ) {
if ( V_21 -> V_22 & V_334 ) {
struct V_273 * V_257 =
(struct V_273 * ) V_104 [ V_310 - 1 ] . V_129 ;
V_257 -> V_278 =
F_5 ( V_21 -> V_114 -> V_285 ) ;
}
V_34 = F_73 ( V_104 , & V_310 , V_300 ,
V_5 -> V_302 ) ;
if ( V_34 ) {
F_76 ( V_96 ) ;
F_41 ( V_308 ) ;
F_41 ( V_313 ) ;
return V_34 ;
}
V_312 = V_104 [ V_310 - 1 ] . V_129 ;
}
V_34 = F_30 ( V_100 , V_20 , V_104 , V_310 , & V_105 , 0 ) ;
V_102 = (struct V_270 * ) V_104 [ 0 ] . V_129 ;
if ( V_34 != 0 ) {
F_59 ( V_5 , V_336 ) ;
if ( V_306 )
* V_306 = F_47 ( V_102 , F_29 ( V_102 ) + 4 ,
V_172 ) ;
goto V_337;
}
V_300 -> V_264 -> V_267 = V_102 -> V_266 ;
V_300 -> V_264 -> V_269 = V_102 -> V_268 ;
if ( V_256 ) {
memcpy ( V_256 , & V_102 -> V_338 , 32 ) ;
V_256 -> V_339 = V_102 -> V_339 ;
V_256 -> V_340 = V_102 -> V_341 ;
V_256 -> V_342 = V_102 -> V_323 ;
V_256 -> V_343 = F_5 ( 1 ) ;
V_256 -> V_344 = 0 ;
}
if ( V_102 -> V_345 == V_287 )
* V_281 = F_66 ( V_21 , V_102 , & V_300 -> V_264 -> V_271 ) ;
else
* V_281 = V_102 -> V_345 ;
V_337:
F_41 ( V_308 ) ;
F_41 ( V_313 ) ;
F_41 ( V_312 ) ;
F_37 ( V_105 , V_102 ) ;
return V_34 ;
}
int
F_39 ( const unsigned int V_100 , struct V_4 * V_5 , T_9 V_267 ,
T_9 V_269 , T_4 V_346 , bool V_347 , char * V_348 ,
T_4 V_349 , char * * V_350 , T_4 * V_351 )
{
struct V_352 * V_96 ;
struct V_353 * V_102 ;
struct V_38 * V_21 ;
struct V_37 * V_20 ;
struct V_103 V_104 [ 2 ] ;
int V_105 ;
int V_310 ;
int V_34 = 0 ;
F_7 ( V_45 , L_43 ) ;
if ( V_350 != NULL )
* V_350 = NULL ;
if ( V_351 )
* V_351 = 0 ;
if ( V_5 )
V_20 = V_5 -> V_20 ;
else
return - V_48 ;
if ( V_20 && ( V_20 -> V_21 ) )
V_21 = V_20 -> V_21 ;
else
return - V_48 ;
V_34 = F_18 ( V_66 , V_5 , ( void * * ) & V_96 ) ;
if ( V_34 )
return V_34 ;
V_96 -> V_354 = F_5 ( V_346 ) ;
V_96 -> V_266 = V_267 ;
V_96 -> V_268 = V_269 ;
if ( V_349 ) {
V_96 -> V_355 = F_5 ( V_349 ) ;
V_96 -> V_356 =
F_5 ( F_51 ( struct V_352 , V_200 ) - 4 ) ;
V_104 [ 1 ] . V_129 = V_348 ;
V_104 [ 1 ] . V_130 = V_349 ;
V_310 = 2 ;
} else
V_310 = 1 ;
V_96 -> V_357 = 0 ;
V_96 -> V_358 = 0 ;
V_96 -> V_359 = F_5 ( 0xFF00 ) ;
if ( V_347 )
V_96 -> V_30 = F_5 ( V_360 ) ;
else
V_96 -> V_30 = 0 ;
V_104 [ 0 ] . V_129 = ( char * ) V_96 ;
if ( V_349 ) {
V_104 [ 0 ] . V_130 = F_29 ( V_96 ) + 4 - 1 ;
F_26 ( V_96 , V_349 - 1 ) ;
} else
V_104 [ 0 ] . V_130 = F_29 ( V_96 ) + 4 ;
V_34 = F_30 ( V_100 , V_20 , V_104 , V_310 , & V_105 , 0 ) ;
V_102 = (struct V_353 * ) V_104 [ 0 ] . V_129 ;
if ( ( V_34 != 0 ) && ( V_34 != - V_231 ) ) {
F_59 ( V_5 , V_361 ) ;
goto V_362;
} else if ( V_34 == - V_231 ) {
if ( ( V_346 != V_363 ) &&
( V_346 != V_364 ) ) {
F_59 ( V_5 , V_361 ) ;
goto V_362;
}
}
if ( ( V_351 == NULL ) || ( V_350 == NULL ) )
goto V_362;
* V_351 = F_33 ( V_102 -> V_358 ) ;
if ( * V_351 == 0 )
goto V_362;
else if ( * V_351 > 0xFF00 ) {
F_7 ( V_136 , L_44 , * V_351 ) ;
* V_351 = 0 ;
V_34 = - V_48 ;
goto V_362;
}
if ( F_29 ( V_102 ) < F_33 ( V_102 -> V_357 ) + * V_351 ) {
F_7 ( V_136 , L_45 , * V_351 ,
F_33 ( V_102 -> V_357 ) ) ;
* V_351 = 0 ;
V_34 = - V_48 ;
goto V_362;
}
* V_350 = F_42 ( * V_351 , V_172 ) ;
if ( * V_350 == NULL ) {
V_34 = - V_72 ;
goto V_362;
}
memcpy ( * V_350 , V_102 -> V_2 . V_12 + F_33 ( V_102 -> V_357 ) ,
* V_351 ) ;
V_362:
F_37 ( V_105 , V_102 ) ;
return V_34 ;
}
int
F_77 ( const unsigned int V_100 , struct V_4 * V_5 ,
T_9 V_267 , T_9 V_269 )
{
int V_34 ;
struct V_365 V_366 ;
char * V_367 = NULL ;
V_366 . V_368 =
F_4 ( V_369 ) ;
V_34 = F_39 ( V_100 , V_5 , V_267 , V_269 ,
V_370 , true ,
( char * ) & V_366 ,
2 , & V_367 , NULL ) ;
F_7 ( V_45 , L_46 , V_34 ) ;
return V_34 ;
}
int
F_78 ( const unsigned int V_100 , struct V_4 * V_5 ,
T_9 V_267 , T_9 V_269 )
{
struct V_371 * V_96 ;
struct V_372 * V_102 ;
struct V_38 * V_21 ;
struct V_37 * V_20 = V_5 -> V_20 ;
struct V_103 V_104 [ 1 ] ;
int V_105 ;
int V_34 = 0 ;
F_7 ( V_45 , L_47 ) ;
if ( V_20 && ( V_20 -> V_21 ) )
V_21 = V_20 -> V_21 ;
else
return - V_48 ;
V_34 = F_18 ( V_52 , V_5 , ( void * * ) & V_96 ) ;
if ( V_34 )
return V_34 ;
V_96 -> V_266 = V_267 ;
V_96 -> V_268 = V_269 ;
V_104 [ 0 ] . V_129 = ( char * ) V_96 ;
V_104 [ 0 ] . V_130 = F_29 ( V_96 ) + 4 ;
V_34 = F_30 ( V_100 , V_20 , V_104 , 1 , & V_105 , 0 ) ;
V_102 = (struct V_372 * ) V_104 [ 0 ] . V_129 ;
if ( V_34 != 0 ) {
F_59 ( V_5 , V_373 ) ;
goto V_374;
}
V_374:
F_37 ( V_105 , V_102 ) ;
return V_34 ;
}
static int
F_79 ( unsigned int V_375 , unsigned int V_376 ,
struct V_1 * V_2 , unsigned int V_377 )
{
unsigned int V_378 = F_80 ( V_2 -> V_11 ) ;
char * V_379 = V_378 + 4 + ( char * ) V_2 ;
char * V_380 = 4 + V_375 + ( char * ) V_2 ;
char * V_381 = V_380 + V_376 ;
if ( V_376 < V_377 ) {
F_7 ( V_136 , L_48 ,
V_376 , V_377 ) ;
return - V_231 ;
}
if ( ( V_378 > 0x7FFFFF ) || ( V_376 > 0x7FFFFF ) ) {
F_7 ( V_136 , L_49 ,
V_376 , V_378 ) ;
return - V_231 ;
}
if ( ( V_380 > V_379 ) || ( V_381 > V_379 ) ) {
F_7 ( V_136 , L_50 ) ;
return - V_231 ;
}
return 0 ;
}
static int
F_81 ( unsigned int V_375 , unsigned int V_376 ,
struct V_1 * V_2 , unsigned int V_382 ,
char * V_186 )
{
char * V_380 = 4 + V_375 + ( char * ) V_2 ;
int V_34 ;
if ( ! V_186 )
return - V_231 ;
V_34 = F_79 ( V_375 , V_376 , V_2 , V_382 ) ;
if ( V_34 )
return V_34 ;
memcpy ( V_186 , V_380 , V_376 ) ;
return 0 ;
}
static int
F_82 ( const unsigned int V_100 , struct V_4 * V_5 ,
T_9 V_267 , T_9 V_269 , T_10 V_383 ,
T_11 V_384 , T_11 V_385 , void * V_186 )
{
struct V_386 * V_96 ;
struct V_387 * V_102 = NULL ;
struct V_103 V_104 [ 2 ] ;
int V_34 = 0 ;
int V_105 ;
struct V_38 * V_21 ;
struct V_37 * V_20 = V_5 -> V_20 ;
F_7 ( V_45 , L_51 ) ;
if ( V_20 && ( V_20 -> V_21 ) )
V_21 = V_20 -> V_21 ;
else
return - V_48 ;
V_34 = F_18 ( V_69 , V_5 , ( void * * ) & V_96 ) ;
if ( V_34 )
return V_34 ;
V_96 -> V_388 = V_389 ;
V_96 -> V_390 = V_383 ;
V_96 -> V_266 = V_267 ;
V_96 -> V_268 = V_269 ;
V_96 -> V_391 =
F_4 ( sizeof( struct V_386 ) - 1 - 4 ) ;
V_96 -> V_392 = F_5 ( V_384 ) ;
V_104 [ 0 ] . V_129 = ( char * ) V_96 ;
V_104 [ 0 ] . V_130 = F_29 ( V_96 ) + 4 ;
V_34 = F_30 ( V_100 , V_20 , V_104 , 1 , & V_105 , 0 ) ;
V_102 = (struct V_387 * ) V_104 [ 0 ] . V_129 ;
if ( V_34 ) {
F_59 ( V_5 , V_393 ) ;
goto V_394;
}
V_34 = F_81 ( F_2 ( V_102 -> V_395 ) ,
F_33 ( V_102 -> V_392 ) ,
& V_102 -> V_2 , V_385 , V_186 ) ;
V_394:
F_37 ( V_105 , V_102 ) ;
return V_34 ;
}
int
F_83 ( const unsigned int V_100 , struct V_4 * V_5 ,
T_9 V_267 , T_9 V_269 ,
struct V_304 * V_186 )
{
return F_82 ( V_100 , V_5 , V_267 , V_269 ,
V_396 ,
sizeof( struct V_304 ) + V_331 * 2 ,
sizeof( struct V_304 ) , V_186 ) ;
}
int
F_84 ( const unsigned int V_100 , struct V_4 * V_5 ,
T_9 V_267 , T_9 V_269 , T_12 * V_397 )
{
return F_82 ( V_100 , V_5 , V_267 , V_269 ,
V_398 ,
sizeof( struct V_399 ) ,
sizeof( struct V_399 ) , V_397 ) ;
}
static void
F_85 ( struct V_400 * V_401 )
{
struct V_38 * V_21 = V_401 -> V_402 ;
struct V_403 * V_404 = (struct V_403 * ) V_401 -> V_405 ;
unsigned int V_406 = 1 ;
if ( V_401 -> V_407 == V_408 )
V_406 = F_2 ( V_404 -> V_2 . V_15 ) ;
F_10 ( & V_21 -> V_204 ) ;
F_86 ( V_401 ) ;
F_13 ( & V_21 -> V_204 ) ;
F_87 ( V_21 , V_406 , V_409 ) ;
}
int
F_88 ( struct V_38 * V_21 )
{
struct V_410 * V_96 ;
int V_34 = 0 ;
struct V_103 V_104 ;
struct V_411 V_412 = { . V_413 = & V_104 ,
. V_414 = 1 } ;
F_7 ( V_45 , L_52 ) ;
V_34 = F_18 ( V_415 , NULL , ( void * * ) & V_96 ) ;
if ( V_34 )
return V_34 ;
V_96 -> V_2 . V_15 = F_4 ( 1 ) ;
V_104 . V_129 = ( char * ) V_96 ;
V_104 . V_130 = F_29 ( V_96 ) + 4 ;
V_34 = F_89 ( V_21 , & V_412 , NULL , F_85 , V_21 ,
V_409 ) ;
if ( V_34 )
F_7 ( V_45 , L_53 , V_34 ) ;
F_76 ( V_96 ) ;
return V_34 ;
}
int
F_90 ( const unsigned int V_100 , struct V_4 * V_5 , T_9 V_267 ,
T_9 V_269 )
{
struct V_416 * V_96 ;
struct V_38 * V_21 ;
struct V_37 * V_20 = V_5 -> V_20 ;
struct V_103 V_104 [ 1 ] ;
int V_105 ;
int V_34 = 0 ;
F_7 ( V_45 , L_54 ) ;
if ( V_20 && ( V_20 -> V_21 ) )
V_21 = V_20 -> V_21 ;
else
return - V_48 ;
V_34 = F_18 ( V_63 , V_5 , ( void * * ) & V_96 ) ;
if ( V_34 )
return V_34 ;
V_96 -> V_266 = V_267 ;
V_96 -> V_268 = V_269 ;
V_104 [ 0 ] . V_129 = ( char * ) V_96 ;
V_104 [ 0 ] . V_130 = F_29 ( V_96 ) + 4 ;
V_34 = F_30 ( V_100 , V_20 , V_104 , 1 , & V_105 , 0 ) ;
if ( V_34 != 0 )
F_59 ( V_5 , V_417 ) ;
F_37 ( V_105 , V_104 [ 0 ] . V_129 ) ;
return V_34 ;
}
static int
F_91 ( struct V_103 * V_104 , struct V_418 * V_419 ,
unsigned int V_420 , int V_421 )
{
int V_34 = - V_422 ;
struct V_423 * V_96 = NULL ;
V_34 = F_18 ( V_64 , V_419 -> V_5 , ( void * * ) & V_96 ) ;
if ( V_34 )
return V_34 ;
if ( V_419 -> V_5 -> V_20 -> V_21 == NULL )
return - V_424 ;
V_96 -> V_2 . V_16 = F_5 ( V_419 -> V_425 ) ;
V_96 -> V_266 = V_419 -> V_267 ;
V_96 -> V_268 = V_419 -> V_269 ;
V_96 -> V_426 = 0 ;
V_96 -> V_427 = 0 ;
V_96 -> V_181 = 0 ;
V_96 -> V_428 = 0 ;
V_96 -> V_429 = F_5 ( V_419 -> V_430 ) ;
V_96 -> V_431 = F_92 ( V_419 -> V_375 ) ;
if ( V_421 & V_432 ) {
if ( ! ( V_421 & V_433 ) ) {
V_96 -> V_2 . V_434 =
F_5 ( F_29 ( V_96 ) + 4 ) ;
} else
V_96 -> V_2 . V_434 = 0 ;
if ( V_421 & V_435 ) {
V_96 -> V_2 . V_30 |= V_436 ;
V_96 -> V_2 . V_27 = 0xFFFFFFFF ;
V_96 -> V_2 . V_25 = 0xFFFFFFFF ;
V_96 -> V_266 = 0xFFFFFFFF ;
V_96 -> V_268 = 0xFFFFFFFF ;
}
}
if ( V_420 > V_419 -> V_430 )
V_96 -> V_437 = F_5 ( V_420 ) ;
else
V_96 -> V_437 = 0 ;
V_104 [ 0 ] . V_129 = ( char * ) V_96 ;
V_104 [ 0 ] . V_130 = F_29 ( V_96 ) + 4 ;
return V_34 ;
}
static void
F_93 ( struct V_400 * V_401 )
{
struct V_438 * V_439 = V_401 -> V_402 ;
struct V_4 * V_5 = F_94 ( V_439 -> V_440 -> V_441 ) ;
struct V_38 * V_21 = V_5 -> V_20 -> V_21 ;
struct V_1 * V_256 = (struct V_1 * ) V_439 -> V_104 . V_129 ;
unsigned int V_406 = 1 ;
struct V_411 V_412 = { . V_413 = & V_439 -> V_104 ,
. V_414 = 1 ,
. V_442 = V_439 -> V_443 ,
. V_444 = V_439 -> V_445 ,
. V_446 = V_439 -> V_447 ,
. V_448 = V_439 -> V_449 } ;
F_7 ( V_45 , L_55 ,
V_111 , V_401 -> V_401 , V_401 -> V_407 , V_439 -> V_450 ,
V_439 -> V_451 ) ;
switch ( V_401 -> V_407 ) {
case V_408 :
V_406 = F_2 ( V_256 -> V_15 ) ;
if ( V_21 -> V_29 ) {
int V_34 ;
V_34 = F_95 ( & V_412 , V_21 ) ;
if ( V_34 )
F_7 ( V_136 , L_56 ,
V_34 ) ;
}
F_96 ( V_439 -> V_452 ) ;
F_97 ( V_5 , V_439 -> V_452 ) ;
break;
case V_453 :
case V_454 :
V_439 -> V_450 = - V_54 ;
if ( V_21 -> V_29 && V_439 -> V_452 )
V_439 -> V_452 = 0 ;
F_96 ( V_439 -> V_452 ) ;
F_97 ( V_5 , V_439 -> V_452 ) ;
break;
default:
if ( V_439 -> V_450 != - V_455 )
V_439 -> V_450 = - V_48 ;
}
if ( V_439 -> V_450 )
F_59 ( V_5 , V_456 ) ;
F_98 ( V_457 , & V_439 -> V_458 ) ;
F_10 ( & V_21 -> V_204 ) ;
F_86 ( V_401 ) ;
F_13 ( & V_21 -> V_204 ) ;
F_87 ( V_21 , V_406 , 0 ) ;
}
int
F_99 ( struct V_438 * V_439 )
{
int V_34 , V_109 = 0 ;
struct V_1 * V_256 ;
struct V_418 V_419 ;
struct V_411 V_412 = { . V_413 = & V_439 -> V_104 ,
. V_414 = 1 } ;
struct V_38 * V_21 ;
F_7 ( V_45 , L_57 ,
V_111 , V_439 -> V_375 , V_439 -> V_451 ) ;
V_419 . V_5 = F_94 ( V_439 -> V_440 -> V_441 ) ;
V_419 . V_375 = V_439 -> V_375 ;
V_419 . V_430 = V_439 -> V_451 ;
V_419 . V_267 = V_439 -> V_440 -> V_264 . V_267 ;
V_419 . V_269 = V_439 -> V_440 -> V_264 . V_269 ;
V_419 . V_425 = V_439 -> V_425 ;
V_21 = V_419 . V_5 -> V_20 -> V_21 ;
V_34 = F_91 ( & V_439 -> V_104 , & V_419 , 0 , 0 ) ;
if ( V_34 ) {
if ( V_34 == - V_54 && V_439 -> V_459 ) {
V_439 -> V_459 = 0 ;
F_53 ( & V_21 -> V_460 ) ;
V_21 -> V_461 -- ;
F_54 ( & V_21 -> V_460 ) ;
}
return V_34 ;
}
V_256 = (struct V_1 * ) V_439 -> V_104 . V_129 ;
V_439 -> V_104 . V_130 = F_29 ( V_439 -> V_104 . V_129 ) + 4 ;
if ( V_439 -> V_459 ) {
V_256 -> V_24 = F_4 ( F_100 ( V_439 -> V_451 ,
V_462 ) ) ;
F_53 ( & V_21 -> V_460 ) ;
V_21 -> V_459 += V_439 -> V_459 -
F_2 ( V_256 -> V_24 ) ;
F_54 ( & V_21 -> V_460 ) ;
F_101 ( & V_21 -> V_463 ) ;
V_109 = V_464 ;
}
F_102 ( & V_439 -> V_465 ) ;
V_34 = F_89 ( V_419 . V_5 -> V_20 -> V_21 , & V_412 ,
V_466 , F_93 ,
V_439 , V_109 ) ;
if ( V_34 ) {
F_103 ( & V_439 -> V_465 , V_467 ) ;
F_59 ( V_419 . V_5 , V_456 ) ;
}
F_76 ( V_256 ) ;
return V_34 ;
}
int
F_104 ( const unsigned int V_100 , struct V_418 * V_419 ,
unsigned int * V_468 , char * * V_256 , int * V_469 )
{
int V_105 , V_34 = - V_422 ;
struct V_470 * V_102 = NULL ;
struct V_103 V_104 [ 1 ] ;
* V_468 = 0 ;
V_34 = F_91 ( V_104 , V_419 , 0 , 0 ) ;
if ( V_34 )
return V_34 ;
V_34 = F_30 ( V_100 , V_419 -> V_5 -> V_20 , V_104 , 1 ,
& V_105 , V_197 ) ;
V_102 = (struct V_470 * ) V_104 [ 0 ] . V_129 ;
if ( V_102 -> V_2 . V_198 == V_471 ) {
F_37 ( V_105 , V_104 [ 0 ] . V_129 ) ;
return 0 ;
}
if ( V_34 ) {
F_59 ( V_419 -> V_5 , V_456 ) ;
F_7 ( V_136 , L_58 , V_34 ) ;
} else {
* V_468 = F_33 ( V_102 -> V_82 ) ;
if ( ( * V_468 > V_472 ) ||
( * V_468 > V_419 -> V_430 ) ) {
F_7 ( V_45 , L_59 ,
* V_468 , V_419 -> V_430 ) ;
V_34 = - V_48 ;
* V_468 = 0 ;
}
}
if ( * V_256 ) {
memcpy ( * V_256 , ( char * ) V_102 -> V_2 . V_12 + V_102 -> V_258 ,
* V_468 ) ;
F_37 ( V_105 , V_104 [ 0 ] . V_129 ) ;
} else if ( V_105 != V_161 ) {
* V_256 = V_104 [ 0 ] . V_129 ;
if ( V_105 == V_473 )
* V_469 = V_473 ;
else if ( V_105 == V_474 )
* V_469 = V_474 ;
}
return V_34 ;
}
static void
F_105 ( struct V_400 * V_401 )
{
struct V_475 * V_476 = V_401 -> V_402 ;
struct V_4 * V_5 = F_94 ( V_476 -> V_440 -> V_441 ) ;
struct V_38 * V_21 = V_5 -> V_20 -> V_21 ;
unsigned int V_477 ;
struct V_478 * V_102 = (struct V_478 * ) V_401 -> V_405 ;
unsigned int V_406 = 1 ;
switch ( V_401 -> V_407 ) {
case V_408 :
V_406 = F_2 ( V_102 -> V_2 . V_15 ) ;
V_476 -> V_450 = F_106 ( V_401 , V_5 -> V_20 -> V_21 , 0 ) ;
if ( V_476 -> V_450 != 0 )
break;
V_477 = F_33 ( V_102 -> V_82 ) ;
if ( V_477 > V_476 -> V_451 )
V_477 &= 0xFFFF ;
if ( V_477 < V_476 -> V_451 )
V_476 -> V_450 = - V_479 ;
else
V_476 -> V_451 = V_477 ;
break;
case V_453 :
case V_454 :
V_476 -> V_450 = - V_54 ;
break;
default:
V_476 -> V_450 = - V_48 ;
break;
}
if ( V_476 -> V_450 )
F_59 ( V_5 , V_480 ) ;
F_98 ( V_457 , & V_476 -> V_458 ) ;
F_10 ( & V_21 -> V_204 ) ;
F_86 ( V_401 ) ;
F_13 ( & V_21 -> V_204 ) ;
F_87 ( V_5 -> V_20 -> V_21 , V_406 , 0 ) ;
}
int
F_107 ( struct V_475 * V_476 ,
void (* F_108)( struct V_481 * V_481 ) )
{
int V_34 = - V_422 , V_109 = 0 ;
struct V_482 * V_96 = NULL ;
struct V_4 * V_5 = F_94 ( V_476 -> V_440 -> V_441 ) ;
struct V_38 * V_21 = V_5 -> V_20 -> V_21 ;
struct V_103 V_104 ;
struct V_411 V_412 ;
V_34 = F_18 ( V_42 , V_5 , ( void * * ) & V_96 ) ;
if ( V_34 ) {
if ( V_34 == - V_54 && V_476 -> V_459 ) {
V_476 -> V_459 = 0 ;
F_53 ( & V_21 -> V_460 ) ;
V_21 -> V_461 -- ;
F_54 ( & V_21 -> V_460 ) ;
}
goto V_483;
}
V_96 -> V_2 . V_16 = F_5 ( V_476 -> V_440 -> V_425 ) ;
V_96 -> V_266 = V_476 -> V_440 -> V_264 . V_267 ;
V_96 -> V_268 = V_476 -> V_440 -> V_264 . V_269 ;
V_96 -> V_484 = 0 ;
V_96 -> V_485 = 0 ;
V_96 -> V_181 = 0 ;
V_96 -> V_431 = F_92 ( V_476 -> V_375 ) ;
V_96 -> V_258 = F_4 (
F_51 ( struct V_482 , V_200 ) - 4 ) ;
V_96 -> V_437 = 0 ;
V_104 . V_130 = F_29 ( V_96 ) + 4 - 1 ;
V_104 . V_129 = V_96 ;
V_412 . V_413 = & V_104 ;
V_412 . V_414 = 1 ;
V_412 . V_442 = V_476 -> V_443 ;
V_412 . V_444 = V_476 -> V_445 ;
V_412 . V_446 = V_476 -> V_447 ;
V_412 . V_448 = V_476 -> V_449 ;
F_7 ( V_45 , L_60 ,
V_476 -> V_375 , V_476 -> V_451 ) ;
V_96 -> V_429 = F_5 ( V_476 -> V_451 ) ;
F_26 ( & V_96 -> V_2 , V_476 -> V_451 - 1 ) ;
if ( V_476 -> V_459 ) {
V_96 -> V_2 . V_24 = F_4 ( F_100 ( V_476 -> V_451 ,
V_462 ) ) ;
F_53 ( & V_21 -> V_460 ) ;
V_21 -> V_459 += V_476 -> V_459 -
F_2 ( V_96 -> V_2 . V_24 ) ;
F_54 ( & V_21 -> V_460 ) ;
F_101 ( & V_21 -> V_463 ) ;
V_109 = V_464 ;
}
F_102 ( & V_476 -> V_465 ) ;
V_34 = F_89 ( V_21 , & V_412 , NULL , F_105 , V_476 ,
V_109 ) ;
if ( V_34 ) {
F_103 ( & V_476 -> V_465 , F_108 ) ;
F_59 ( V_5 , V_480 ) ;
}
V_483:
F_76 ( V_96 ) ;
return V_34 ;
}
int
F_109 ( const unsigned int V_100 , struct V_418 * V_419 ,
unsigned int * V_468 , struct V_103 * V_104 , int V_486 )
{
int V_34 = 0 ;
struct V_482 * V_96 = NULL ;
struct V_478 * V_102 = NULL ;
int V_105 ;
* V_468 = 0 ;
if ( V_486 < 1 )
return V_34 ;
V_34 = F_18 ( V_42 , V_419 -> V_5 , ( void * * ) & V_96 ) ;
if ( V_34 )
return V_34 ;
if ( V_419 -> V_5 -> V_20 -> V_21 == NULL )
return - V_424 ;
V_96 -> V_2 . V_16 = F_5 ( V_419 -> V_425 ) ;
V_96 -> V_266 = V_419 -> V_267 ;
V_96 -> V_268 = V_419 -> V_269 ;
V_96 -> V_484 = 0 ;
V_96 -> V_485 = 0 ;
V_96 -> V_181 = 0 ;
V_96 -> V_429 = F_5 ( V_419 -> V_430 ) ;
V_96 -> V_431 = F_92 ( V_419 -> V_375 ) ;
V_96 -> V_258 = F_4 (
F_51 ( struct V_482 , V_200 ) - 4 ) ;
V_96 -> V_437 = 0 ;
V_104 [ 0 ] . V_129 = ( char * ) V_96 ;
V_104 [ 0 ] . V_130 = F_29 ( V_96 ) + 4 - 1 ;
F_26 ( V_96 , V_419 -> V_430 - 1 ) ;
V_34 = F_30 ( V_100 , V_419 -> V_5 -> V_20 , V_104 , V_486 + 1 ,
& V_105 , 0 ) ;
V_102 = (struct V_478 * ) V_104 [ 0 ] . V_129 ;
if ( V_34 ) {
F_59 ( V_419 -> V_5 , V_480 ) ;
F_7 ( V_136 , L_61 , V_34 ) ;
} else
* V_468 = F_33 ( V_102 -> V_82 ) ;
F_37 ( V_105 , V_102 ) ;
return V_34 ;
}
static unsigned int
F_110 ( char * V_487 , char * V_381 , char * * V_488 , T_11 V_489 )
{
int V_191 ;
unsigned int V_490 = 0 ;
unsigned int V_491 = 0 ;
T_13 * V_492 ;
if ( V_487 == NULL )
return 0 ;
V_492 = ( T_13 * ) V_487 ;
while ( 1 ) {
V_492 = ( T_13 * )
( ( char * ) V_492 + V_491 ) ;
if ( ( char * ) V_492 + V_489 > V_381 ) {
F_7 ( V_136 , L_62 ) ;
break;
}
V_191 = F_33 ( V_492 -> V_493 ) ;
if ( ( char * ) V_492 + V_191 + V_489 > V_381 ) {
F_7 ( V_136 , L_63 ,
V_381 ) ;
break;
}
* V_488 = ( char * ) V_492 ;
V_490 ++ ;
V_491 = F_33 ( V_492 -> V_494 ) ;
if ( ! V_491 )
break;
}
return V_490 ;
}
int
F_111 ( const unsigned int V_100 , struct V_4 * V_5 ,
T_9 V_267 , T_9 V_269 , int V_495 ,
struct V_496 * V_497 )
{
struct V_498 * V_96 ;
struct V_499 * V_102 = NULL ;
struct V_103 V_104 [ 2 ] ;
int V_34 = 0 ;
int V_191 ;
int V_105 = V_161 ;
unsigned char * V_500 ;
struct V_38 * V_21 ;
struct V_37 * V_20 = V_5 -> V_20 ;
T_1 V_501 = F_4 ( '*' ) ;
char * V_379 ;
unsigned int V_502 = V_503 ;
T_11 V_504 ;
if ( V_20 && ( V_20 -> V_21 ) )
V_21 = V_20 -> V_21 ;
else
return - V_48 ;
V_34 = F_18 ( V_67 , V_5 , ( void * * ) & V_96 ) ;
if ( V_34 )
return V_34 ;
switch ( V_497 -> V_505 ) {
case V_506 :
V_96 -> V_507 = V_508 ;
V_504 = sizeof( T_13 ) - 1 ;
break;
case V_509 :
V_96 -> V_507 = V_510 ;
V_504 = sizeof( V_511 ) - 1 ;
break;
default:
F_7 ( V_136 , L_64 ,
V_497 -> V_505 ) ;
V_34 = - V_231 ;
goto V_512;
}
V_96 -> V_513 = F_5 ( V_495 ) ;
V_96 -> V_266 = V_267 ;
V_96 -> V_268 = V_269 ;
V_191 = 0x2 ;
V_500 = V_96 -> V_200 ;
memcpy ( V_500 , & V_501 , V_191 ) ;
V_96 -> V_514 =
F_4 ( sizeof( struct V_498 ) - 1 - 4 ) ;
V_96 -> V_493 = F_4 ( V_191 ) ;
V_502 = F_32 (unsigned int, output_size, server->maxBuf) ;
V_502 = F_32 (unsigned int, output_size, 2 << 15 ) ;
V_96 -> V_392 = F_5 ( V_502 ) ;
V_104 [ 0 ] . V_129 = ( char * ) V_96 ;
V_104 [ 0 ] . V_130 = F_29 ( V_96 ) + 4 - 1 ;
V_104 [ 1 ] . V_129 = ( char * ) ( V_96 -> V_200 ) ;
V_104 [ 1 ] . V_130 = V_191 ;
F_26 ( V_96 , V_191 - 1 ) ;
V_34 = F_30 ( V_100 , V_20 , V_104 , 2 , & V_105 , 0 ) ;
V_102 = (struct V_499 * ) V_104 [ 0 ] . V_129 ;
if ( V_34 ) {
if ( V_34 == - V_455 && V_102 -> V_2 . V_198 == V_515 ) {
V_497 -> V_516 = true ;
V_34 = 0 ;
}
F_59 ( V_5 , V_517 ) ;
goto V_512;
}
V_34 = F_79 ( F_2 ( V_102 -> V_395 ) ,
F_33 ( V_102 -> V_392 ) , & V_102 -> V_2 ,
V_504 ) ;
if ( V_34 )
goto V_512;
V_497 -> V_518 = true ;
if ( V_497 -> V_519 ) {
if ( V_497 -> V_520 )
F_76 ( V_497 -> V_519 ) ;
else
F_112 ( V_497 -> V_519 ) ;
}
V_497 -> V_519 = ( char * ) V_102 ;
V_497 -> V_521 = V_497 -> V_522 = 4 +
( char * ) & V_102 -> V_2 + F_2 ( V_102 -> V_395 ) ;
V_379 = F_29 ( V_102 ) + 4 + ( char * ) & V_102 -> V_2 ;
V_497 -> V_523 =
F_110 ( V_497 -> V_521 , V_379 ,
& V_497 -> V_522 , V_504 ) ;
V_497 -> V_524 += V_497 -> V_523 ;
F_7 ( V_45 , L_65 ,
V_497 -> V_523 , V_497 -> V_524 ,
V_497 -> V_521 , V_497 -> V_522 ) ;
if ( V_105 == V_474 )
V_497 -> V_520 = false ;
else if ( V_105 == V_473 )
V_497 -> V_520 = true ;
else
F_7 ( V_136 , L_66 ) ;
return V_34 ;
V_512:
F_37 ( V_105 , V_102 ) ;
return V_34 ;
}
static int
F_113 ( const unsigned int V_100 , struct V_4 * V_5 ,
T_9 V_267 , T_9 V_269 , T_4 V_425 , int V_383 ,
unsigned int V_283 , void * * V_186 , unsigned int * V_489 )
{
struct V_525 * V_96 ;
struct V_526 * V_102 = NULL ;
struct V_103 * V_104 ;
int V_34 = 0 ;
int V_105 ;
unsigned int V_527 ;
struct V_38 * V_21 ;
struct V_37 * V_20 = V_5 -> V_20 ;
if ( V_20 && ( V_20 -> V_21 ) )
V_21 = V_20 -> V_21 ;
else
return - V_48 ;
if ( ! V_283 )
return - V_231 ;
V_104 = F_42 ( sizeof( struct V_103 ) * V_283 , V_172 ) ;
if ( ! V_104 )
return - V_72 ;
V_34 = F_18 ( V_70 , V_5 , ( void * * ) & V_96 ) ;
if ( V_34 ) {
F_41 ( V_104 ) ;
return V_34 ;
}
V_96 -> V_2 . V_16 = F_5 ( V_425 ) ;
V_96 -> V_388 = V_389 ;
V_96 -> V_390 = V_383 ;
V_96 -> V_266 = V_267 ;
V_96 -> V_268 = V_269 ;
V_96 -> V_528 =
F_4 ( sizeof( struct V_525 ) - 1 - 4 ) ;
V_96 -> V_529 = F_5 ( * V_489 ) ;
F_26 ( V_96 , * V_489 - 1 ) ;
memcpy ( V_96 -> V_200 , * V_186 , * V_489 ) ;
V_104 [ 0 ] . V_129 = ( char * ) V_96 ;
V_104 [ 0 ] . V_130 = F_29 ( V_96 ) + 4 ;
for ( V_527 = 1 ; V_527 < V_283 ; V_527 ++ ) {
F_26 ( V_96 , V_489 [ V_527 ] ) ;
F_68 ( & V_96 -> V_529 , V_489 [ V_527 ] ) ;
V_104 [ V_527 ] . V_129 = ( char * ) V_186 [ V_527 ] ;
V_104 [ V_527 ] . V_130 = V_489 [ V_527 ] ;
}
V_34 = F_30 ( V_100 , V_20 , V_104 , V_283 , & V_105 , 0 ) ;
V_102 = (struct V_526 * ) V_104 [ 0 ] . V_129 ;
if ( V_34 != 0 )
F_59 ( V_5 , V_530 ) ;
F_37 ( V_105 , V_102 ) ;
F_41 ( V_104 ) ;
return V_34 ;
}
int
F_114 ( const unsigned int V_100 , struct V_4 * V_5 ,
T_9 V_267 , T_9 V_269 , T_1 * V_531 )
{
struct V_532 V_533 ;
void * * V_186 ;
unsigned int V_489 [ 2 ] ;
int V_34 ;
int V_191 = ( 2 * F_75 ( ( V_330 * ) V_531 , V_331 ) ) ;
V_186 = F_42 ( sizeof( void * ) * 2 , V_172 ) ;
if ( ! V_186 )
return - V_72 ;
V_533 . V_534 = 1 ;
V_533 . V_535 = 0 ;
V_533 . V_493 = F_5 ( V_191 ) ;
V_186 [ 0 ] = & V_533 ;
V_489 [ 0 ] = sizeof( struct V_532 ) ;
V_186 [ 1 ] = V_531 ;
V_489 [ 1 ] = V_191 + 2 ;
V_34 = F_113 ( V_100 , V_5 , V_267 , V_269 ,
V_17 -> V_18 , V_536 , 2 , V_186 ,
V_489 ) ;
F_41 ( V_186 ) ;
return V_34 ;
}
int
F_115 ( const unsigned int V_100 , struct V_4 * V_5 ,
T_9 V_267 , T_9 V_269 , T_1 * V_531 )
{
struct V_537 V_533 ;
void * * V_186 ;
unsigned int V_489 [ 2 ] ;
int V_34 ;
int V_191 = ( 2 * F_75 ( ( V_330 * ) V_531 , V_331 ) ) ;
V_186 = F_42 ( sizeof( void * ) * 2 , V_172 ) ;
if ( ! V_186 )
return - V_72 ;
V_533 . V_534 = 0 ;
V_533 . V_535 = 0 ;
V_533 . V_493 = F_5 ( V_191 ) ;
V_186 [ 0 ] = & V_533 ;
V_489 [ 0 ] = sizeof( struct V_537 ) ;
V_186 [ 1 ] = V_531 ;
V_489 [ 1 ] = V_191 + 2 ;
V_34 = F_113 ( V_100 , V_5 , V_267 , V_269 ,
V_17 -> V_18 , V_538 , 2 , V_186 , V_489 ) ;
F_41 ( V_186 ) ;
return V_34 ;
}
int
F_116 ( const unsigned int V_100 , struct V_4 * V_5 , T_9 V_267 ,
T_9 V_269 , T_4 V_425 , T_12 * V_539 , bool V_540 )
{
struct V_541 V_533 ;
void * V_186 ;
unsigned int V_489 ;
V_533 . V_340 = * V_539 ;
V_186 = & V_533 ;
V_489 = sizeof( struct V_541 ) ;
if ( V_540 )
return F_113 ( V_100 , V_5 , V_267 , V_269 ,
V_425 , V_542 , 1 , & V_186 , & V_489 ) ;
else
return F_113 ( V_100 , V_5 , V_267 , V_269 ,
V_425 , V_543 , 1 , & V_186 , & V_489 ) ;
}
int
F_117 ( const unsigned int V_100 , struct V_4 * V_5 ,
T_9 V_267 , T_9 V_269 , T_14 * V_256 )
{
unsigned int V_489 ;
V_489 = sizeof( T_14 ) ;
return F_113 ( V_100 , V_5 , V_267 , V_269 ,
V_17 -> V_18 , V_544 , 1 ,
( void * * ) & V_256 , & V_489 ) ;
}
int
F_118 ( const unsigned int V_100 , struct V_4 * V_5 ,
const T_9 V_267 , const T_9 V_269 ,
T_7 V_545 )
{
int V_34 ;
struct V_546 * V_96 = NULL ;
F_7 ( V_45 , L_67 ) ;
V_34 = F_18 ( V_53 , V_5 , ( void * * ) & V_96 ) ;
if ( V_34 )
return V_34 ;
V_96 -> V_547 = V_269 ;
V_96 -> V_548 = V_267 ;
V_96 -> V_345 = V_545 ;
V_96 -> V_2 . V_15 = F_4 ( 1 ) ;
V_34 = F_58 ( V_100 , V_5 -> V_20 , ( char * ) V_96 , V_549 ) ;
if ( V_34 ) {
F_59 ( V_5 , V_550 ) ;
F_7 ( V_45 , L_68 , V_34 ) ;
}
return V_34 ;
}
static void
F_119 ( struct V_551 * V_552 ,
struct V_553 * V_554 )
{
V_554 -> V_555 = F_33 ( V_552 -> V_556 ) *
F_33 ( V_552 -> V_557 ) ;
V_554 -> V_558 = F_120 ( V_552 -> V_559 ) ;
V_554 -> V_560 = F_120 ( V_552 -> V_561 ) ;
V_554 -> V_562 = F_120 ( V_552 -> V_563 ) ;
return;
}
static int
F_121 ( struct V_103 * V_104 , struct V_4 * V_5 , int V_564 ,
int V_565 , T_9 V_267 , T_9 V_269 )
{
int V_34 ;
struct V_386 * V_96 ;
F_7 ( V_45 , L_69 , V_564 ) ;
if ( ( V_5 -> V_20 == NULL ) || ( V_5 -> V_20 -> V_21 == NULL ) )
return - V_48 ;
V_34 = F_18 ( V_69 , V_5 , ( void * * ) & V_96 ) ;
if ( V_34 )
return V_34 ;
V_96 -> V_388 = V_566 ;
V_96 -> V_390 = V_564 ;
V_96 -> V_266 = V_267 ;
V_96 -> V_268 = V_269 ;
V_96 -> V_391 =
F_4 ( sizeof( struct V_386 ) - 1 - 4 ) ;
V_96 -> V_392 = F_5 (
V_565 + sizeof( struct V_387 ) - 1 - 4 ) ;
V_104 -> V_129 = ( char * ) V_96 ;
V_104 -> V_130 = F_29 ( V_96 ) + 4 ;
return 0 ;
}
int
F_122 ( const unsigned int V_100 , struct V_4 * V_5 ,
T_9 V_267 , T_9 V_269 , struct V_553 * V_567 )
{
struct V_387 * V_102 = NULL ;
struct V_103 V_104 ;
int V_34 = 0 ;
int V_105 ;
struct V_37 * V_20 = V_5 -> V_20 ;
struct V_551 * V_533 = NULL ;
V_34 = F_121 ( & V_104 , V_5 , V_568 ,
sizeof( struct V_551 ) ,
V_267 , V_269 ) ;
if ( V_34 )
return V_34 ;
V_34 = F_30 ( V_100 , V_20 , & V_104 , 1 , & V_105 , 0 ) ;
if ( V_34 ) {
F_59 ( V_5 , V_393 ) ;
goto V_569;
}
V_102 = (struct V_387 * ) V_104 . V_129 ;
V_533 = (struct V_551 * ) ( 4 +
F_2 ( V_102 -> V_395 ) + ( char * ) & V_102 -> V_2 ) ;
V_34 = F_79 ( F_2 ( V_102 -> V_395 ) ,
F_33 ( V_102 -> V_392 ) , & V_102 -> V_2 ,
sizeof( struct V_551 ) ) ;
if ( ! V_34 )
F_119 ( V_533 , V_567 ) ;
V_569:
F_37 ( V_105 , V_104 . V_129 ) ;
return V_34 ;
}
int
F_123 ( const unsigned int V_100 , struct V_4 * V_5 ,
T_9 V_267 , T_9 V_269 , int V_564 )
{
struct V_387 * V_102 = NULL ;
struct V_103 V_104 ;
int V_34 = 0 ;
int V_105 , V_570 , V_385 ;
struct V_37 * V_20 = V_5 -> V_20 ;
unsigned int V_571 , V_375 ;
if ( V_564 == V_572 ) {
V_570 = sizeof( V_573 ) ;
V_385 = sizeof( V_573 ) ;
} else if ( V_564 == V_574 ) {
V_570 = sizeof( V_575 ) ;
V_385 = V_576 ;
} else if ( V_564 == V_577 ) {
V_570 = sizeof( struct V_578 ) ;
V_385 = sizeof( struct V_578 ) ;
} else {
F_7 ( V_45 , L_70 , V_564 ) ;
return - V_231 ;
}
V_34 = F_121 ( & V_104 , V_5 , V_564 , V_570 ,
V_267 , V_269 ) ;
if ( V_34 )
return V_34 ;
V_34 = F_30 ( V_100 , V_20 , & V_104 , 1 , & V_105 , 0 ) ;
if ( V_34 ) {
F_59 ( V_5 , V_393 ) ;
goto V_579;
}
V_102 = (struct V_387 * ) V_104 . V_129 ;
V_571 = F_33 ( V_102 -> V_392 ) ;
V_375 = F_2 ( V_102 -> V_395 ) ;
V_34 = F_79 ( V_375 , V_571 , & V_102 -> V_2 , V_385 ) ;
if ( V_34 )
goto V_579;
if ( V_564 == V_574 )
memcpy ( & V_5 -> V_580 , 4 + V_375
+ ( char * ) & V_102 -> V_2 , F_32 (unsigned int,
rsp_len, max_len) ) ;
else if ( V_564 == V_572 )
memcpy ( & V_5 -> V_581 , 4 + V_375
+ ( char * ) & V_102 -> V_2 , sizeof( V_573 ) ) ;
else if ( V_564 == V_577 ) {
struct V_578 * V_582 = (struct V_578 * )
( 4 + V_375 + ( char * ) & V_102 -> V_2 ) ;
V_5 -> V_583 = F_33 ( V_582 -> V_30 ) ;
V_5 -> V_584 =
F_33 ( V_582 -> V_585 ) ;
}
V_579:
F_37 ( V_105 , V_104 . V_129 ) ;
return V_34 ;
}
int
F_124 ( const unsigned int V_100 , struct V_4 * V_5 ,
const T_15 V_586 , const T_15 V_269 , const T_8 V_425 ,
const T_8 V_587 , struct V_588 * V_256 )
{
int V_34 = 0 ;
struct V_589 * V_96 = NULL ;
struct V_103 V_104 [ 2 ] ;
int V_590 ;
unsigned int V_591 ;
F_7 ( V_45 , L_71 , V_587 ) ;
V_34 = F_18 ( V_65 , V_5 , ( void * * ) & V_96 ) ;
if ( V_34 )
return V_34 ;
V_96 -> V_2 . V_16 = F_5 ( V_425 ) ;
V_96 -> V_592 = F_4 ( V_587 ) ;
V_96 -> V_266 = V_586 ;
V_96 -> V_268 = V_269 ;
V_591 = V_587 * sizeof( struct V_588 ) ;
F_26 ( V_96 , V_591 - sizeof( struct V_588 ) ) ;
V_104 [ 0 ] . V_129 = ( char * ) V_96 ;
V_104 [ 0 ] . V_130 = F_29 ( V_96 ) + 4 - V_591 ;
V_104 [ 1 ] . V_129 = ( char * ) V_256 ;
V_104 [ 1 ] . V_130 = V_591 ;
F_21 ( & V_5 -> V_74 . V_593 . V_594 ) ;
V_34 = F_30 ( V_100 , V_5 -> V_20 , V_104 , 2 , & V_590 , V_595 ) ;
if ( V_34 ) {
F_7 ( V_45 , L_72 , V_34 ) ;
F_59 ( V_5 , V_596 ) ;
}
return V_34 ;
}
int
F_125 ( const unsigned int V_100 , struct V_4 * V_5 ,
const T_15 V_586 , const T_15 V_269 , const T_8 V_425 ,
const T_15 V_430 , const T_15 V_375 , const T_8 V_597 ,
const bool V_598 )
{
struct V_588 V_599 ;
V_599 . V_431 = F_92 ( V_375 ) ;
V_599 . V_429 = F_92 ( V_430 ) ;
V_599 . V_30 = F_5 ( V_597 ) ;
if ( ! V_598 && V_597 != V_600 )
V_599 . V_30 |= F_5 ( V_601 ) ;
return F_124 ( V_100 , V_5 , V_586 , V_269 , V_425 , 1 , & V_599 ) ;
}
int
F_126 ( const unsigned int V_100 , struct V_4 * V_5 ,
T_7 * V_602 , const T_5 V_603 )
{
int V_34 ;
struct V_604 * V_96 = NULL ;
F_7 ( V_45 , L_73 ) ;
V_34 = F_18 ( V_53 , V_5 , ( void * * ) & V_96 ) ;
if ( V_34 )
return V_34 ;
V_96 -> V_2 . V_15 = F_4 ( 1 ) ;
V_96 -> V_13 = F_4 ( 36 ) ;
F_26 ( V_96 , 12 ) ;
memcpy ( V_96 -> V_605 , V_602 , 16 ) ;
V_96 -> V_606 = V_603 ;
V_34 = F_58 ( V_100 , V_5 -> V_20 , ( char * ) V_96 , V_549 ) ;
if ( V_34 ) {
F_59 ( V_5 , V_550 ) ;
F_7 ( V_45 , L_74 , V_34 ) ;
}
return V_34 ;
}
