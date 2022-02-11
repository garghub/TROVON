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
V_183 = V_165 -> V_185 . V_186 ;
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
static int
F_69 ( struct V_103 * V_104 , unsigned int * V_280 ,
struct V_289 * V_290 )
{
struct V_282 * V_96 = V_104 [ 0 ] . V_129 ;
unsigned int V_283 = * V_280 ;
if ( V_290 -> V_291 ) {
V_104 [ V_283 ] . V_129 = F_65 ( V_290 -> V_264 ) ;
V_290 -> V_291 = false ;
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
F_70 ( const unsigned int V_100 , struct V_289 * V_290 , T_1 * V_292 ,
T_7 * V_281 , struct V_293 * V_256 ,
struct V_294 * * V_295 )
{
struct V_282 * V_96 ;
struct V_270 * V_102 ;
struct V_38 * V_21 ;
struct V_4 * V_5 = V_290 -> V_5 ;
struct V_37 * V_20 = V_5 -> V_20 ;
struct V_103 V_104 [ 4 ] ;
int V_105 ;
int V_296 ;
T_1 * V_297 = NULL ;
int V_298 ;
int V_34 = 0 ;
unsigned int V_299 = 2 ;
T_8 V_300 = 0 ;
char * V_301 = NULL , * V_302 = NULL ;
F_7 ( V_45 , L_42 ) ;
if ( V_20 && ( V_20 -> V_21 ) )
V_21 = V_20 -> V_21 ;
else
return - V_48 ;
V_34 = F_18 ( V_43 , V_5 , ( void * * ) & V_96 ) ;
if ( V_34 )
return V_34 ;
if ( V_290 -> V_303 & V_304 )
V_300 |= V_305 ;
if ( V_290 -> V_303 & V_306 )
V_300 |= V_307 ;
V_96 -> V_308 = V_309 ;
V_96 -> V_310 = F_5 ( V_290 -> V_311 ) ;
V_96 -> V_312 = F_5 ( V_300 ) ;
V_96 -> V_313 = V_314 ;
V_96 -> V_315 = F_5 ( V_290 -> V_316 ) ;
V_96 -> V_317 = F_5 ( V_290 -> V_303 & V_318 ) ;
V_296 = ( 2 * F_71 ( ( V_319 * ) V_292 , V_320 ) ) + 2 ;
V_96 -> V_260 = F_4 ( sizeof( struct V_282 ) - 4 ) ;
V_104 [ 0 ] . V_129 = ( char * ) V_96 ;
V_104 [ 0 ] . V_130 = F_29 ( V_96 ) + 4 ;
V_96 -> V_262 = F_4 ( V_296 - 2 ) ;
V_104 [ 0 ] . V_130 -- ;
if ( V_296 % 8 != 0 ) {
V_298 = V_296 / 8 * 8 ;
if ( V_298 < V_296 )
V_298 += 8 ;
V_297 = F_49 ( V_298 , V_172 ) ;
if ( ! V_297 )
return - V_72 ;
memcpy ( ( char * ) V_297 , ( const char * ) V_292 ,
V_296 ) ;
V_296 = V_298 ;
V_292 = V_297 ;
}
V_104 [ 1 ] . V_130 = V_296 ;
V_104 [ 1 ] . V_129 = V_292 ;
F_26 ( V_96 , V_296 - 1 ) ;
if ( ! V_21 -> V_321 )
* V_281 = V_322 ;
if ( ! ( V_21 -> V_22 & V_323 ) ||
* V_281 == V_322 )
V_96 -> V_286 = * V_281 ;
else {
V_34 = F_67 ( V_21 , V_104 , & V_299 , V_281 ) ;
if ( V_34 ) {
F_72 ( V_96 ) ;
F_41 ( V_297 ) ;
return V_34 ;
}
V_302 = V_104 [ V_299 - 1 ] . V_129 ;
}
if ( * V_281 == V_324 ) {
if ( V_21 -> V_22 & V_323 ) {
struct V_273 * V_257 =
(struct V_273 * ) V_104 [ V_299 - 1 ] . V_129 ;
V_257 -> V_278 =
F_5 ( V_21 -> V_114 -> V_285 ) ;
}
V_34 = F_69 ( V_104 , & V_299 , V_290 ) ;
if ( V_34 ) {
F_72 ( V_96 ) ;
F_41 ( V_297 ) ;
F_41 ( V_302 ) ;
return V_34 ;
}
V_301 = V_104 [ V_299 - 1 ] . V_129 ;
}
V_34 = F_30 ( V_100 , V_20 , V_104 , V_299 , & V_105 , 0 ) ;
V_102 = (struct V_270 * ) V_104 [ 0 ] . V_129 ;
if ( V_34 != 0 ) {
F_59 ( V_5 , V_325 ) ;
if ( V_295 )
* V_295 = F_47 ( V_102 , F_29 ( V_102 ) + 4 ,
V_172 ) ;
goto V_326;
}
V_290 -> V_264 -> V_267 = V_102 -> V_266 ;
V_290 -> V_264 -> V_269 = V_102 -> V_268 ;
if ( V_256 ) {
memcpy ( V_256 , & V_102 -> V_327 , 32 ) ;
V_256 -> V_328 = V_102 -> V_328 ;
V_256 -> V_329 = V_102 -> V_330 ;
V_256 -> V_331 = V_102 -> V_312 ;
V_256 -> V_332 = F_5 ( 1 ) ;
V_256 -> V_333 = 0 ;
}
if ( V_102 -> V_334 == V_287 )
* V_281 = F_66 ( V_21 , V_102 , & V_290 -> V_264 -> V_271 ) ;
else
* V_281 = V_102 -> V_334 ;
V_326:
F_41 ( V_297 ) ;
F_41 ( V_302 ) ;
F_41 ( V_301 ) ;
F_37 ( V_105 , V_102 ) ;
return V_34 ;
}
int
F_39 ( const unsigned int V_100 , struct V_4 * V_5 , T_9 V_267 ,
T_9 V_269 , T_4 V_335 , bool V_336 , char * V_337 ,
T_4 V_338 , char * * V_339 , T_4 * V_340 )
{
struct V_341 * V_96 ;
struct V_342 * V_102 ;
struct V_38 * V_21 ;
struct V_37 * V_20 ;
struct V_103 V_104 [ 2 ] ;
int V_105 ;
int V_299 ;
int V_34 = 0 ;
F_7 ( V_45 , L_43 ) ;
if ( V_339 != NULL )
* V_339 = NULL ;
if ( V_340 )
* V_340 = 0 ;
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
V_96 -> V_343 = F_5 ( V_335 ) ;
V_96 -> V_266 = V_267 ;
V_96 -> V_268 = V_269 ;
if ( V_338 ) {
V_96 -> V_344 = F_5 ( V_338 ) ;
V_96 -> V_345 =
F_5 ( F_51 ( struct V_341 , V_200 ) - 4 ) ;
V_104 [ 1 ] . V_129 = V_337 ;
V_104 [ 1 ] . V_130 = V_338 ;
V_299 = 2 ;
} else
V_299 = 1 ;
V_96 -> V_346 = 0 ;
V_96 -> V_347 = 0 ;
V_96 -> V_348 = F_5 ( 0xFF00 ) ;
if ( V_336 )
V_96 -> V_30 = F_5 ( V_349 ) ;
else
V_96 -> V_30 = 0 ;
V_104 [ 0 ] . V_129 = ( char * ) V_96 ;
if ( V_338 ) {
V_104 [ 0 ] . V_130 = F_29 ( V_96 ) + 4 - 1 ;
F_26 ( V_96 , V_338 - 1 ) ;
} else
V_104 [ 0 ] . V_130 = F_29 ( V_96 ) + 4 ;
V_34 = F_30 ( V_100 , V_20 , V_104 , V_299 , & V_105 , 0 ) ;
V_102 = (struct V_342 * ) V_104 [ 0 ] . V_129 ;
if ( ( V_34 != 0 ) && ( V_34 != - V_231 ) ) {
F_59 ( V_5 , V_350 ) ;
goto V_351;
} else if ( V_34 == - V_231 ) {
if ( ( V_335 != V_352 ) &&
( V_335 != V_353 ) ) {
F_59 ( V_5 , V_350 ) ;
goto V_351;
}
}
if ( ( V_340 == NULL ) || ( V_339 == NULL ) )
goto V_351;
* V_340 = F_33 ( V_102 -> V_347 ) ;
if ( * V_340 == 0 )
goto V_351;
else if ( * V_340 > 0xFF00 ) {
F_7 ( V_136 , L_44 , * V_340 ) ;
* V_340 = 0 ;
V_34 = - V_48 ;
goto V_351;
}
if ( F_29 ( V_102 ) < F_33 ( V_102 -> V_346 ) + * V_340 ) {
F_7 ( V_136 , L_45 , * V_340 ,
F_33 ( V_102 -> V_346 ) ) ;
* V_340 = 0 ;
V_34 = - V_48 ;
goto V_351;
}
* V_339 = F_42 ( * V_340 , V_172 ) ;
if ( * V_339 == NULL ) {
V_34 = - V_72 ;
goto V_351;
}
memcpy ( * V_339 , V_102 -> V_2 . V_12 + F_33 ( V_102 -> V_346 ) ,
* V_340 ) ;
V_351:
F_37 ( V_105 , V_102 ) ;
return V_34 ;
}
int
F_73 ( const unsigned int V_100 , struct V_4 * V_5 ,
T_9 V_267 , T_9 V_269 )
{
int V_34 ;
struct V_354 V_355 ;
char * V_356 = NULL ;
V_355 . V_357 =
F_4 ( V_358 ) ;
V_34 = F_39 ( V_100 , V_5 , V_267 , V_269 ,
V_359 , true ,
( char * ) & V_355 ,
2 , & V_356 , NULL ) ;
F_7 ( V_45 , L_46 , V_34 ) ;
return V_34 ;
}
int
F_74 ( const unsigned int V_100 , struct V_4 * V_5 ,
T_9 V_267 , T_9 V_269 )
{
struct V_360 * V_96 ;
struct V_361 * V_102 ;
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
V_102 = (struct V_361 * ) V_104 [ 0 ] . V_129 ;
if ( V_34 != 0 ) {
F_59 ( V_5 , V_362 ) ;
goto V_363;
}
V_363:
F_37 ( V_105 , V_102 ) ;
return V_34 ;
}
static int
F_75 ( unsigned int V_364 , unsigned int V_365 ,
struct V_1 * V_2 , unsigned int V_366 )
{
unsigned int V_367 = F_76 ( V_2 -> V_11 ) ;
char * V_368 = V_367 + 4 + ( char * ) V_2 ;
char * V_369 = 4 + V_364 + ( char * ) V_2 ;
char * V_370 = V_369 + V_365 ;
if ( V_365 < V_366 ) {
F_7 ( V_136 , L_48 ,
V_365 , V_366 ) ;
return - V_231 ;
}
if ( ( V_367 > 0x7FFFFF ) || ( V_365 > 0x7FFFFF ) ) {
F_7 ( V_136 , L_49 ,
V_365 , V_367 ) ;
return - V_231 ;
}
if ( ( V_369 > V_368 ) || ( V_370 > V_368 ) ) {
F_7 ( V_136 , L_50 ) ;
return - V_231 ;
}
return 0 ;
}
static int
F_77 ( unsigned int V_364 , unsigned int V_365 ,
struct V_1 * V_2 , unsigned int V_371 ,
char * V_186 )
{
char * V_369 = 4 + V_364 + ( char * ) V_2 ;
int V_34 ;
if ( ! V_186 )
return - V_231 ;
V_34 = F_75 ( V_364 , V_365 , V_2 , V_371 ) ;
if ( V_34 )
return V_34 ;
memcpy ( V_186 , V_369 , V_365 ) ;
return 0 ;
}
static int
F_78 ( const unsigned int V_100 , struct V_4 * V_5 ,
T_9 V_267 , T_9 V_269 , T_10 V_372 ,
T_11 V_373 , T_11 V_374 , void * V_186 )
{
struct V_375 * V_96 ;
struct V_376 * V_102 = NULL ;
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
V_96 -> V_377 = V_378 ;
V_96 -> V_379 = V_372 ;
V_96 -> V_266 = V_267 ;
V_96 -> V_268 = V_269 ;
V_96 -> V_380 =
F_4 ( sizeof( struct V_375 ) - 1 - 4 ) ;
V_96 -> V_381 = F_5 ( V_373 ) ;
V_104 [ 0 ] . V_129 = ( char * ) V_96 ;
V_104 [ 0 ] . V_130 = F_29 ( V_96 ) + 4 ;
V_34 = F_30 ( V_100 , V_20 , V_104 , 1 , & V_105 , 0 ) ;
V_102 = (struct V_376 * ) V_104 [ 0 ] . V_129 ;
if ( V_34 ) {
F_59 ( V_5 , V_382 ) ;
goto V_383;
}
V_34 = F_77 ( F_2 ( V_102 -> V_384 ) ,
F_33 ( V_102 -> V_381 ) ,
& V_102 -> V_2 , V_374 , V_186 ) ;
V_383:
F_37 ( V_105 , V_102 ) ;
return V_34 ;
}
int
F_79 ( const unsigned int V_100 , struct V_4 * V_5 ,
T_9 V_267 , T_9 V_269 ,
struct V_293 * V_186 )
{
return F_78 ( V_100 , V_5 , V_267 , V_269 ,
V_385 ,
sizeof( struct V_293 ) + V_320 * 2 ,
sizeof( struct V_293 ) , V_186 ) ;
}
int
F_80 ( const unsigned int V_100 , struct V_4 * V_5 ,
T_9 V_267 , T_9 V_269 , T_12 * V_386 )
{
return F_78 ( V_100 , V_5 , V_267 , V_269 ,
V_387 ,
sizeof( struct V_388 ) ,
sizeof( struct V_388 ) , V_386 ) ;
}
static void
F_81 ( struct V_389 * V_390 )
{
struct V_38 * V_21 = V_390 -> V_391 ;
struct V_392 * V_393 = (struct V_392 * ) V_390 -> V_394 ;
unsigned int V_395 = 1 ;
if ( V_390 -> V_396 == V_397 )
V_395 = F_2 ( V_393 -> V_2 . V_15 ) ;
F_10 ( & V_21 -> V_204 ) ;
F_82 ( V_390 ) ;
F_13 ( & V_21 -> V_204 ) ;
F_83 ( V_21 , V_395 , V_398 ) ;
}
int
F_84 ( struct V_38 * V_21 )
{
struct V_399 * V_96 ;
int V_34 = 0 ;
struct V_103 V_104 ;
struct V_400 V_401 = { . V_402 = & V_104 ,
. V_403 = 1 } ;
F_7 ( V_45 , L_52 ) ;
V_34 = F_18 ( V_404 , NULL , ( void * * ) & V_96 ) ;
if ( V_34 )
return V_34 ;
V_96 -> V_2 . V_15 = F_4 ( 1 ) ;
V_104 . V_129 = ( char * ) V_96 ;
V_104 . V_130 = F_29 ( V_96 ) + 4 ;
V_34 = F_85 ( V_21 , & V_401 , NULL , F_81 , V_21 ,
V_398 ) ;
if ( V_34 )
F_7 ( V_45 , L_53 , V_34 ) ;
F_72 ( V_96 ) ;
return V_34 ;
}
int
F_86 ( const unsigned int V_100 , struct V_4 * V_5 , T_9 V_267 ,
T_9 V_269 )
{
struct V_405 * V_96 ;
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
F_59 ( V_5 , V_406 ) ;
F_37 ( V_105 , V_104 [ 0 ] . V_129 ) ;
return V_34 ;
}
static int
F_87 ( struct V_103 * V_104 , struct V_407 * V_408 ,
unsigned int V_409 , int V_410 )
{
int V_34 = - V_411 ;
struct V_412 * V_96 = NULL ;
V_34 = F_18 ( V_64 , V_408 -> V_5 , ( void * * ) & V_96 ) ;
if ( V_34 )
return V_34 ;
if ( V_408 -> V_5 -> V_20 -> V_21 == NULL )
return - V_413 ;
V_96 -> V_2 . V_16 = F_5 ( V_408 -> V_414 ) ;
V_96 -> V_266 = V_408 -> V_267 ;
V_96 -> V_268 = V_408 -> V_269 ;
V_96 -> V_415 = 0 ;
V_96 -> V_416 = 0 ;
V_96 -> V_181 = 0 ;
V_96 -> V_417 = 0 ;
V_96 -> V_418 = F_5 ( V_408 -> V_419 ) ;
V_96 -> V_420 = F_88 ( V_408 -> V_364 ) ;
if ( V_410 & V_421 ) {
if ( ! ( V_410 & V_422 ) ) {
V_96 -> V_2 . V_423 =
F_5 ( F_29 ( V_96 ) + 4 ) ;
} else
V_96 -> V_2 . V_423 = 0 ;
if ( V_410 & V_424 ) {
V_96 -> V_2 . V_30 |= V_425 ;
V_96 -> V_2 . V_27 = 0xFFFFFFFF ;
V_96 -> V_2 . V_25 = 0xFFFFFFFF ;
V_96 -> V_266 = 0xFFFFFFFF ;
V_96 -> V_268 = 0xFFFFFFFF ;
}
}
if ( V_409 > V_408 -> V_419 )
V_96 -> V_426 = F_5 ( V_409 ) ;
else
V_96 -> V_426 = 0 ;
V_104 [ 0 ] . V_129 = ( char * ) V_96 ;
V_104 [ 0 ] . V_130 = F_29 ( V_96 ) + 4 ;
return V_34 ;
}
static void
F_89 ( struct V_389 * V_390 )
{
struct V_427 * V_428 = V_390 -> V_391 ;
struct V_4 * V_5 = F_90 ( V_428 -> V_429 -> V_430 ) ;
struct V_38 * V_21 = V_5 -> V_20 -> V_21 ;
struct V_1 * V_256 = (struct V_1 * ) V_428 -> V_104 . V_129 ;
unsigned int V_395 = 1 ;
struct V_400 V_401 = { . V_402 = & V_428 -> V_104 ,
. V_403 = 1 ,
. V_431 = V_428 -> V_432 ,
. V_433 = V_428 -> V_434 ,
. V_435 = V_428 -> V_436 ,
. V_437 = V_428 -> V_438 } ;
F_7 ( V_45 , L_55 ,
V_111 , V_390 -> V_390 , V_390 -> V_396 , V_428 -> V_439 ,
V_428 -> V_440 ) ;
switch ( V_390 -> V_396 ) {
case V_397 :
V_395 = F_2 ( V_256 -> V_15 ) ;
if ( V_21 -> V_29 ) {
int V_34 ;
V_34 = F_91 ( & V_401 , V_21 ) ;
if ( V_34 )
F_7 ( V_136 , L_56 ,
V_34 ) ;
}
F_92 ( V_428 -> V_441 ) ;
F_93 ( V_5 , V_428 -> V_441 ) ;
break;
case V_442 :
case V_443 :
V_428 -> V_439 = - V_54 ;
if ( V_21 -> V_29 && V_428 -> V_441 )
V_428 -> V_441 = 0 ;
F_92 ( V_428 -> V_441 ) ;
F_93 ( V_5 , V_428 -> V_441 ) ;
break;
default:
if ( V_428 -> V_439 != - V_444 )
V_428 -> V_439 = - V_48 ;
}
if ( V_428 -> V_439 )
F_59 ( V_5 , V_445 ) ;
F_94 ( V_446 , & V_428 -> V_447 ) ;
F_10 ( & V_21 -> V_204 ) ;
F_82 ( V_390 ) ;
F_13 ( & V_21 -> V_204 ) ;
F_83 ( V_21 , V_395 , 0 ) ;
}
int
F_95 ( struct V_427 * V_428 )
{
int V_34 , V_109 = 0 ;
struct V_1 * V_256 ;
struct V_407 V_408 ;
struct V_400 V_401 = { . V_402 = & V_428 -> V_104 ,
. V_403 = 1 } ;
struct V_38 * V_21 ;
F_7 ( V_45 , L_57 ,
V_111 , V_428 -> V_364 , V_428 -> V_440 ) ;
V_408 . V_5 = F_90 ( V_428 -> V_429 -> V_430 ) ;
V_408 . V_364 = V_428 -> V_364 ;
V_408 . V_419 = V_428 -> V_440 ;
V_408 . V_267 = V_428 -> V_429 -> V_264 . V_267 ;
V_408 . V_269 = V_428 -> V_429 -> V_264 . V_269 ;
V_408 . V_414 = V_428 -> V_414 ;
V_21 = V_408 . V_5 -> V_20 -> V_21 ;
V_34 = F_87 ( & V_428 -> V_104 , & V_408 , 0 , 0 ) ;
if ( V_34 ) {
if ( V_34 == - V_54 && V_428 -> V_448 ) {
V_428 -> V_448 = 0 ;
F_53 ( & V_21 -> V_449 ) ;
V_21 -> V_450 -- ;
F_54 ( & V_21 -> V_449 ) ;
}
return V_34 ;
}
V_256 = (struct V_1 * ) V_428 -> V_104 . V_129 ;
V_428 -> V_104 . V_130 = F_29 ( V_428 -> V_104 . V_129 ) + 4 ;
if ( V_428 -> V_448 ) {
V_256 -> V_24 = F_4 ( F_96 ( V_428 -> V_440 ,
V_451 ) ) ;
F_53 ( & V_21 -> V_449 ) ;
V_21 -> V_448 += V_428 -> V_448 -
F_2 ( V_256 -> V_24 ) ;
F_54 ( & V_21 -> V_449 ) ;
F_97 ( & V_21 -> V_452 ) ;
V_109 = V_453 ;
}
F_98 ( & V_428 -> V_454 ) ;
V_34 = F_85 ( V_408 . V_5 -> V_20 -> V_21 , & V_401 ,
V_455 , F_89 ,
V_428 , V_109 ) ;
if ( V_34 ) {
F_99 ( & V_428 -> V_454 , V_456 ) ;
F_59 ( V_408 . V_5 , V_445 ) ;
}
F_72 ( V_256 ) ;
return V_34 ;
}
int
F_100 ( const unsigned int V_100 , struct V_407 * V_408 ,
unsigned int * V_457 , char * * V_256 , int * V_458 )
{
int V_105 , V_34 = - V_411 ;
struct V_459 * V_102 = NULL ;
struct V_103 V_104 [ 1 ] ;
* V_457 = 0 ;
V_34 = F_87 ( V_104 , V_408 , 0 , 0 ) ;
if ( V_34 )
return V_34 ;
V_34 = F_30 ( V_100 , V_408 -> V_5 -> V_20 , V_104 , 1 ,
& V_105 , V_197 ) ;
V_102 = (struct V_459 * ) V_104 [ 0 ] . V_129 ;
if ( V_102 -> V_2 . V_198 == V_460 ) {
F_37 ( V_105 , V_104 [ 0 ] . V_129 ) ;
return 0 ;
}
if ( V_34 ) {
F_59 ( V_408 -> V_5 , V_445 ) ;
F_7 ( V_136 , L_58 , V_34 ) ;
} else {
* V_457 = F_33 ( V_102 -> V_82 ) ;
if ( ( * V_457 > V_461 ) ||
( * V_457 > V_408 -> V_419 ) ) {
F_7 ( V_45 , L_59 ,
* V_457 , V_408 -> V_419 ) ;
V_34 = - V_48 ;
* V_457 = 0 ;
}
}
if ( * V_256 ) {
memcpy ( * V_256 , ( char * ) V_102 -> V_2 . V_12 + V_102 -> V_258 ,
* V_457 ) ;
F_37 ( V_105 , V_104 [ 0 ] . V_129 ) ;
} else if ( V_105 != V_161 ) {
* V_256 = V_104 [ 0 ] . V_129 ;
if ( V_105 == V_462 )
* V_458 = V_462 ;
else if ( V_105 == V_463 )
* V_458 = V_463 ;
}
return V_34 ;
}
static void
F_101 ( struct V_389 * V_390 )
{
struct V_464 * V_465 = V_390 -> V_391 ;
struct V_4 * V_5 = F_90 ( V_465 -> V_429 -> V_430 ) ;
struct V_38 * V_21 = V_5 -> V_20 -> V_21 ;
unsigned int V_466 ;
struct V_467 * V_102 = (struct V_467 * ) V_390 -> V_394 ;
unsigned int V_395 = 1 ;
switch ( V_390 -> V_396 ) {
case V_397 :
V_395 = F_2 ( V_102 -> V_2 . V_15 ) ;
V_465 -> V_439 = F_102 ( V_390 , V_5 -> V_20 -> V_21 , 0 ) ;
if ( V_465 -> V_439 != 0 )
break;
V_466 = F_33 ( V_102 -> V_82 ) ;
if ( V_466 > V_465 -> V_440 )
V_466 &= 0xFFFF ;
if ( V_466 < V_465 -> V_440 )
V_465 -> V_439 = - V_468 ;
else
V_465 -> V_440 = V_466 ;
break;
case V_442 :
case V_443 :
V_465 -> V_439 = - V_54 ;
break;
default:
V_465 -> V_439 = - V_48 ;
break;
}
if ( V_465 -> V_439 )
F_59 ( V_5 , V_469 ) ;
F_94 ( V_446 , & V_465 -> V_447 ) ;
F_10 ( & V_21 -> V_204 ) ;
F_82 ( V_390 ) ;
F_13 ( & V_21 -> V_204 ) ;
F_83 ( V_5 -> V_20 -> V_21 , V_395 , 0 ) ;
}
int
F_103 ( struct V_464 * V_465 ,
void (* F_104)( struct V_470 * V_470 ) )
{
int V_34 = - V_411 , V_109 = 0 ;
struct V_471 * V_96 = NULL ;
struct V_4 * V_5 = F_90 ( V_465 -> V_429 -> V_430 ) ;
struct V_38 * V_21 = V_5 -> V_20 -> V_21 ;
struct V_103 V_104 ;
struct V_400 V_401 ;
V_34 = F_18 ( V_42 , V_5 , ( void * * ) & V_96 ) ;
if ( V_34 ) {
if ( V_34 == - V_54 && V_465 -> V_448 ) {
V_465 -> V_448 = 0 ;
F_53 ( & V_21 -> V_449 ) ;
V_21 -> V_450 -- ;
F_54 ( & V_21 -> V_449 ) ;
}
goto V_472;
}
V_96 -> V_2 . V_16 = F_5 ( V_465 -> V_429 -> V_414 ) ;
V_96 -> V_266 = V_465 -> V_429 -> V_264 . V_267 ;
V_96 -> V_268 = V_465 -> V_429 -> V_264 . V_269 ;
V_96 -> V_473 = 0 ;
V_96 -> V_474 = 0 ;
V_96 -> V_181 = 0 ;
V_96 -> V_420 = F_88 ( V_465 -> V_364 ) ;
V_96 -> V_258 = F_4 (
F_51 ( struct V_471 , V_200 ) - 4 ) ;
V_96 -> V_426 = 0 ;
V_104 . V_130 = F_29 ( V_96 ) + 4 - 1 ;
V_104 . V_129 = V_96 ;
V_401 . V_402 = & V_104 ;
V_401 . V_403 = 1 ;
V_401 . V_431 = V_465 -> V_432 ;
V_401 . V_433 = V_465 -> V_434 ;
V_401 . V_435 = V_465 -> V_436 ;
V_401 . V_437 = V_465 -> V_438 ;
F_7 ( V_45 , L_60 ,
V_465 -> V_364 , V_465 -> V_440 ) ;
V_96 -> V_418 = F_5 ( V_465 -> V_440 ) ;
F_26 ( & V_96 -> V_2 , V_465 -> V_440 - 1 ) ;
if ( V_465 -> V_448 ) {
V_96 -> V_2 . V_24 = F_4 ( F_96 ( V_465 -> V_440 ,
V_451 ) ) ;
F_53 ( & V_21 -> V_449 ) ;
V_21 -> V_448 += V_465 -> V_448 -
F_2 ( V_96 -> V_2 . V_24 ) ;
F_54 ( & V_21 -> V_449 ) ;
F_97 ( & V_21 -> V_452 ) ;
V_109 = V_453 ;
}
F_98 ( & V_465 -> V_454 ) ;
V_34 = F_85 ( V_21 , & V_401 , NULL , F_101 , V_465 ,
V_109 ) ;
if ( V_34 ) {
F_99 ( & V_465 -> V_454 , F_104 ) ;
F_59 ( V_5 , V_469 ) ;
}
V_472:
F_72 ( V_96 ) ;
return V_34 ;
}
int
F_105 ( const unsigned int V_100 , struct V_407 * V_408 ,
unsigned int * V_457 , struct V_103 * V_104 , int V_475 )
{
int V_34 = 0 ;
struct V_471 * V_96 = NULL ;
struct V_467 * V_102 = NULL ;
int V_105 ;
* V_457 = 0 ;
if ( V_475 < 1 )
return V_34 ;
V_34 = F_18 ( V_42 , V_408 -> V_5 , ( void * * ) & V_96 ) ;
if ( V_34 )
return V_34 ;
if ( V_408 -> V_5 -> V_20 -> V_21 == NULL )
return - V_413 ;
V_96 -> V_2 . V_16 = F_5 ( V_408 -> V_414 ) ;
V_96 -> V_266 = V_408 -> V_267 ;
V_96 -> V_268 = V_408 -> V_269 ;
V_96 -> V_473 = 0 ;
V_96 -> V_474 = 0 ;
V_96 -> V_181 = 0 ;
V_96 -> V_418 = F_5 ( V_408 -> V_419 ) ;
V_96 -> V_420 = F_88 ( V_408 -> V_364 ) ;
V_96 -> V_258 = F_4 (
F_51 ( struct V_471 , V_200 ) - 4 ) ;
V_96 -> V_426 = 0 ;
V_104 [ 0 ] . V_129 = ( char * ) V_96 ;
V_104 [ 0 ] . V_130 = F_29 ( V_96 ) + 4 - 1 ;
F_26 ( V_96 , V_408 -> V_419 - 1 ) ;
V_34 = F_30 ( V_100 , V_408 -> V_5 -> V_20 , V_104 , V_475 + 1 ,
& V_105 , 0 ) ;
V_102 = (struct V_467 * ) V_104 [ 0 ] . V_129 ;
if ( V_34 ) {
F_59 ( V_408 -> V_5 , V_469 ) ;
F_7 ( V_136 , L_61 , V_34 ) ;
} else
* V_457 = F_33 ( V_102 -> V_82 ) ;
F_37 ( V_105 , V_102 ) ;
return V_34 ;
}
static unsigned int
F_106 ( char * V_476 , char * V_370 , char * * V_477 , T_11 V_478 )
{
int V_191 ;
unsigned int V_479 = 0 ;
unsigned int V_480 = 0 ;
T_13 * V_481 ;
if ( V_476 == NULL )
return 0 ;
V_481 = ( T_13 * ) V_476 ;
while ( 1 ) {
V_481 = ( T_13 * )
( ( char * ) V_481 + V_480 ) ;
if ( ( char * ) V_481 + V_478 > V_370 ) {
F_7 ( V_136 , L_62 ) ;
break;
}
V_191 = F_33 ( V_481 -> V_482 ) ;
if ( ( char * ) V_481 + V_191 + V_478 > V_370 ) {
F_7 ( V_136 , L_63 ,
V_370 ) ;
break;
}
* V_477 = ( char * ) V_481 ;
V_479 ++ ;
V_480 = F_33 ( V_481 -> V_483 ) ;
if ( ! V_480 )
break;
}
return V_479 ;
}
int
F_107 ( const unsigned int V_100 , struct V_4 * V_5 ,
T_9 V_267 , T_9 V_269 , int V_484 ,
struct V_485 * V_486 )
{
struct V_487 * V_96 ;
struct V_488 * V_102 = NULL ;
struct V_103 V_104 [ 2 ] ;
int V_34 = 0 ;
int V_191 ;
int V_105 = V_161 ;
unsigned char * V_489 ;
struct V_38 * V_21 ;
struct V_37 * V_20 = V_5 -> V_20 ;
T_1 V_490 = F_4 ( '*' ) ;
char * V_368 ;
unsigned int V_491 = V_492 ;
T_11 V_493 ;
if ( V_20 && ( V_20 -> V_21 ) )
V_21 = V_20 -> V_21 ;
else
return - V_48 ;
V_34 = F_18 ( V_67 , V_5 , ( void * * ) & V_96 ) ;
if ( V_34 )
return V_34 ;
switch ( V_486 -> V_494 ) {
case V_495 :
V_96 -> V_496 = V_497 ;
V_493 = sizeof( T_13 ) - 1 ;
break;
case V_498 :
V_96 -> V_496 = V_499 ;
V_493 = sizeof( V_500 ) - 1 ;
break;
default:
F_7 ( V_136 , L_64 ,
V_486 -> V_494 ) ;
V_34 = - V_231 ;
goto V_501;
}
V_96 -> V_502 = F_5 ( V_484 ) ;
V_96 -> V_266 = V_267 ;
V_96 -> V_268 = V_269 ;
V_191 = 0x2 ;
V_489 = V_96 -> V_200 ;
memcpy ( V_489 , & V_490 , V_191 ) ;
V_96 -> V_503 =
F_4 ( sizeof( struct V_487 ) - 1 - 4 ) ;
V_96 -> V_482 = F_4 ( V_191 ) ;
V_491 = F_32 (unsigned int, output_size, server->maxBuf) ;
V_491 = F_32 (unsigned int, output_size, 2 << 15 ) ;
V_96 -> V_381 = F_5 ( V_491 ) ;
V_104 [ 0 ] . V_129 = ( char * ) V_96 ;
V_104 [ 0 ] . V_130 = F_29 ( V_96 ) + 4 - 1 ;
V_104 [ 1 ] . V_129 = ( char * ) ( V_96 -> V_200 ) ;
V_104 [ 1 ] . V_130 = V_191 ;
F_26 ( V_96 , V_191 - 1 ) ;
V_34 = F_30 ( V_100 , V_20 , V_104 , 2 , & V_105 , 0 ) ;
V_102 = (struct V_488 * ) V_104 [ 0 ] . V_129 ;
if ( V_34 ) {
if ( V_34 == - V_444 && V_102 -> V_2 . V_198 == V_504 ) {
V_486 -> V_505 = true ;
V_34 = 0 ;
}
F_59 ( V_5 , V_506 ) ;
goto V_501;
}
V_34 = F_75 ( F_2 ( V_102 -> V_384 ) ,
F_33 ( V_102 -> V_381 ) , & V_102 -> V_2 ,
V_493 ) ;
if ( V_34 )
goto V_501;
V_486 -> V_507 = true ;
if ( V_486 -> V_508 ) {
if ( V_486 -> V_509 )
F_72 ( V_486 -> V_508 ) ;
else
F_108 ( V_486 -> V_508 ) ;
}
V_486 -> V_508 = ( char * ) V_102 ;
V_486 -> V_510 = V_486 -> V_511 = 4 +
( char * ) & V_102 -> V_2 + F_2 ( V_102 -> V_384 ) ;
V_368 = F_29 ( V_102 ) + 4 + ( char * ) & V_102 -> V_2 ;
V_486 -> V_512 =
F_106 ( V_486 -> V_510 , V_368 ,
& V_486 -> V_511 , V_493 ) ;
V_486 -> V_513 += V_486 -> V_512 ;
F_7 ( V_45 , L_65 ,
V_486 -> V_512 , V_486 -> V_513 ,
V_486 -> V_510 , V_486 -> V_511 ) ;
if ( V_105 == V_463 )
V_486 -> V_509 = false ;
else if ( V_105 == V_462 )
V_486 -> V_509 = true ;
else
F_7 ( V_136 , L_66 ) ;
return V_34 ;
V_501:
F_37 ( V_105 , V_102 ) ;
return V_34 ;
}
static int
F_109 ( const unsigned int V_100 , struct V_4 * V_5 ,
T_9 V_267 , T_9 V_269 , T_4 V_414 , int V_372 ,
unsigned int V_283 , void * * V_186 , unsigned int * V_478 )
{
struct V_514 * V_96 ;
struct V_515 * V_102 = NULL ;
struct V_103 * V_104 ;
int V_34 = 0 ;
int V_105 ;
unsigned int V_516 ;
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
V_96 -> V_2 . V_16 = F_5 ( V_414 ) ;
V_96 -> V_377 = V_378 ;
V_96 -> V_379 = V_372 ;
V_96 -> V_266 = V_267 ;
V_96 -> V_268 = V_269 ;
V_96 -> V_517 =
F_4 ( sizeof( struct V_514 ) - 1 - 4 ) ;
V_96 -> V_518 = F_5 ( * V_478 ) ;
F_26 ( V_96 , * V_478 - 1 ) ;
memcpy ( V_96 -> V_200 , * V_186 , * V_478 ) ;
V_104 [ 0 ] . V_129 = ( char * ) V_96 ;
V_104 [ 0 ] . V_130 = F_29 ( V_96 ) + 4 ;
for ( V_516 = 1 ; V_516 < V_283 ; V_516 ++ ) {
F_26 ( V_96 , V_478 [ V_516 ] ) ;
F_68 ( & V_96 -> V_518 , V_478 [ V_516 ] ) ;
V_104 [ V_516 ] . V_129 = ( char * ) V_186 [ V_516 ] ;
V_104 [ V_516 ] . V_130 = V_478 [ V_516 ] ;
}
V_34 = F_30 ( V_100 , V_20 , V_104 , V_283 , & V_105 , 0 ) ;
V_102 = (struct V_515 * ) V_104 [ 0 ] . V_129 ;
if ( V_34 != 0 )
F_59 ( V_5 , V_519 ) ;
F_37 ( V_105 , V_102 ) ;
F_41 ( V_104 ) ;
return V_34 ;
}
int
F_110 ( const unsigned int V_100 , struct V_4 * V_5 ,
T_9 V_267 , T_9 V_269 , T_1 * V_520 )
{
struct V_521 V_522 ;
void * * V_186 ;
unsigned int V_478 [ 2 ] ;
int V_34 ;
int V_191 = ( 2 * F_71 ( ( V_319 * ) V_520 , V_320 ) ) ;
V_186 = F_42 ( sizeof( void * ) * 2 , V_172 ) ;
if ( ! V_186 )
return - V_72 ;
V_522 . V_523 = 1 ;
V_522 . V_524 = 0 ;
V_522 . V_482 = F_5 ( V_191 ) ;
V_186 [ 0 ] = & V_522 ;
V_478 [ 0 ] = sizeof( struct V_521 ) ;
V_186 [ 1 ] = V_520 ;
V_478 [ 1 ] = V_191 + 2 ;
V_34 = F_109 ( V_100 , V_5 , V_267 , V_269 ,
V_17 -> V_18 , V_525 , 2 , V_186 ,
V_478 ) ;
F_41 ( V_186 ) ;
return V_34 ;
}
int
F_111 ( const unsigned int V_100 , struct V_4 * V_5 ,
T_9 V_267 , T_9 V_269 , T_1 * V_520 )
{
struct V_526 V_522 ;
void * * V_186 ;
unsigned int V_478 [ 2 ] ;
int V_34 ;
int V_191 = ( 2 * F_71 ( ( V_319 * ) V_520 , V_320 ) ) ;
V_186 = F_42 ( sizeof( void * ) * 2 , V_172 ) ;
if ( ! V_186 )
return - V_72 ;
V_522 . V_523 = 0 ;
V_522 . V_524 = 0 ;
V_522 . V_482 = F_5 ( V_191 ) ;
V_186 [ 0 ] = & V_522 ;
V_478 [ 0 ] = sizeof( struct V_526 ) ;
V_186 [ 1 ] = V_520 ;
V_478 [ 1 ] = V_191 + 2 ;
V_34 = F_109 ( V_100 , V_5 , V_267 , V_269 ,
V_17 -> V_18 , V_527 , 2 , V_186 , V_478 ) ;
F_41 ( V_186 ) ;
return V_34 ;
}
int
F_112 ( const unsigned int V_100 , struct V_4 * V_5 , T_9 V_267 ,
T_9 V_269 , T_4 V_414 , T_12 * V_528 , bool V_529 )
{
struct V_530 V_522 ;
void * V_186 ;
unsigned int V_478 ;
V_522 . V_329 = * V_528 ;
V_186 = & V_522 ;
V_478 = sizeof( struct V_530 ) ;
if ( V_529 )
return F_109 ( V_100 , V_5 , V_267 , V_269 ,
V_414 , V_531 , 1 , & V_186 , & V_478 ) ;
else
return F_109 ( V_100 , V_5 , V_267 , V_269 ,
V_414 , V_532 , 1 , & V_186 , & V_478 ) ;
}
int
F_113 ( const unsigned int V_100 , struct V_4 * V_5 ,
T_9 V_267 , T_9 V_269 , T_14 * V_256 )
{
unsigned int V_478 ;
V_478 = sizeof( T_14 ) ;
return F_109 ( V_100 , V_5 , V_267 , V_269 ,
V_17 -> V_18 , V_533 , 1 ,
( void * * ) & V_256 , & V_478 ) ;
}
int
F_114 ( const unsigned int V_100 , struct V_4 * V_5 ,
const T_9 V_267 , const T_9 V_269 ,
T_7 V_534 )
{
int V_34 ;
struct V_535 * V_96 = NULL ;
F_7 ( V_45 , L_67 ) ;
V_34 = F_18 ( V_53 , V_5 , ( void * * ) & V_96 ) ;
if ( V_34 )
return V_34 ;
V_96 -> V_536 = V_269 ;
V_96 -> V_537 = V_267 ;
V_96 -> V_334 = V_534 ;
V_96 -> V_2 . V_15 = F_4 ( 1 ) ;
V_34 = F_58 ( V_100 , V_5 -> V_20 , ( char * ) V_96 , V_538 ) ;
if ( V_34 ) {
F_59 ( V_5 , V_539 ) ;
F_7 ( V_45 , L_68 , V_34 ) ;
}
return V_34 ;
}
static void
F_115 ( struct V_540 * V_541 ,
struct V_542 * V_543 )
{
V_543 -> V_544 = F_33 ( V_541 -> V_545 ) *
F_33 ( V_541 -> V_546 ) ;
V_543 -> V_547 = F_116 ( V_541 -> V_548 ) ;
V_543 -> V_549 = F_116 ( V_541 -> V_550 ) ;
V_543 -> V_551 = F_116 ( V_541 -> V_552 ) ;
return;
}
static int
F_117 ( struct V_103 * V_104 , struct V_4 * V_5 , int V_553 ,
int V_554 , T_9 V_267 , T_9 V_269 )
{
int V_34 ;
struct V_375 * V_96 ;
F_7 ( V_45 , L_69 , V_553 ) ;
if ( ( V_5 -> V_20 == NULL ) || ( V_5 -> V_20 -> V_21 == NULL ) )
return - V_48 ;
V_34 = F_18 ( V_69 , V_5 , ( void * * ) & V_96 ) ;
if ( V_34 )
return V_34 ;
V_96 -> V_377 = V_555 ;
V_96 -> V_379 = V_553 ;
V_96 -> V_266 = V_267 ;
V_96 -> V_268 = V_269 ;
V_96 -> V_380 =
F_4 ( sizeof( struct V_375 ) - 1 - 4 ) ;
V_96 -> V_381 = F_5 (
V_554 + sizeof( struct V_376 ) - 1 - 4 ) ;
V_104 -> V_129 = ( char * ) V_96 ;
V_104 -> V_130 = F_29 ( V_96 ) + 4 ;
return 0 ;
}
int
F_118 ( const unsigned int V_100 , struct V_4 * V_5 ,
T_9 V_267 , T_9 V_269 , struct V_542 * V_556 )
{
struct V_376 * V_102 = NULL ;
struct V_103 V_104 ;
int V_34 = 0 ;
int V_105 ;
struct V_37 * V_20 = V_5 -> V_20 ;
struct V_540 * V_522 = NULL ;
V_34 = F_117 ( & V_104 , V_5 , V_557 ,
sizeof( struct V_540 ) ,
V_267 , V_269 ) ;
if ( V_34 )
return V_34 ;
V_34 = F_30 ( V_100 , V_20 , & V_104 , 1 , & V_105 , 0 ) ;
if ( V_34 ) {
F_59 ( V_5 , V_382 ) ;
goto V_558;
}
V_102 = (struct V_376 * ) V_104 . V_129 ;
V_522 = (struct V_540 * ) ( 4 +
F_2 ( V_102 -> V_384 ) + ( char * ) & V_102 -> V_2 ) ;
V_34 = F_75 ( F_2 ( V_102 -> V_384 ) ,
F_33 ( V_102 -> V_381 ) , & V_102 -> V_2 ,
sizeof( struct V_540 ) ) ;
if ( ! V_34 )
F_115 ( V_522 , V_556 ) ;
V_558:
F_37 ( V_105 , V_104 . V_129 ) ;
return V_34 ;
}
int
F_119 ( const unsigned int V_100 , struct V_4 * V_5 ,
T_9 V_267 , T_9 V_269 , int V_553 )
{
struct V_376 * V_102 = NULL ;
struct V_103 V_104 ;
int V_34 = 0 ;
int V_105 , V_559 , V_374 ;
struct V_37 * V_20 = V_5 -> V_20 ;
unsigned int V_560 , V_364 ;
if ( V_553 == V_561 ) {
V_559 = sizeof( V_562 ) ;
V_374 = sizeof( V_562 ) ;
} else if ( V_553 == V_563 ) {
V_559 = sizeof( V_564 ) ;
V_374 = V_565 ;
} else if ( V_553 == V_566 ) {
V_559 = sizeof( struct V_567 ) ;
V_374 = sizeof( struct V_567 ) ;
} else {
F_7 ( V_45 , L_70 , V_553 ) ;
return - V_231 ;
}
V_34 = F_117 ( & V_104 , V_5 , V_553 , V_559 ,
V_267 , V_269 ) ;
if ( V_34 )
return V_34 ;
V_34 = F_30 ( V_100 , V_20 , & V_104 , 1 , & V_105 , 0 ) ;
if ( V_34 ) {
F_59 ( V_5 , V_382 ) ;
goto V_568;
}
V_102 = (struct V_376 * ) V_104 . V_129 ;
V_560 = F_33 ( V_102 -> V_381 ) ;
V_364 = F_2 ( V_102 -> V_384 ) ;
V_34 = F_75 ( V_364 , V_560 , & V_102 -> V_2 , V_374 ) ;
if ( V_34 )
goto V_568;
if ( V_553 == V_563 )
memcpy ( & V_5 -> V_569 , 4 + V_364
+ ( char * ) & V_102 -> V_2 , F_32 (unsigned int,
rsp_len, max_len) ) ;
else if ( V_553 == V_561 )
memcpy ( & V_5 -> V_570 , 4 + V_364
+ ( char * ) & V_102 -> V_2 , sizeof( V_562 ) ) ;
else if ( V_553 == V_566 ) {
struct V_567 * V_571 = (struct V_567 * )
( 4 + V_364 + ( char * ) & V_102 -> V_2 ) ;
V_5 -> V_572 = F_33 ( V_571 -> V_30 ) ;
V_5 -> V_573 =
F_33 ( V_571 -> V_574 ) ;
}
V_568:
F_37 ( V_105 , V_104 . V_129 ) ;
return V_34 ;
}
int
F_120 ( const unsigned int V_100 , struct V_4 * V_5 ,
const T_15 V_575 , const T_15 V_269 , const T_8 V_414 ,
const T_8 V_576 , struct V_577 * V_256 )
{
int V_34 = 0 ;
struct V_578 * V_96 = NULL ;
struct V_103 V_104 [ 2 ] ;
int V_579 ;
unsigned int V_580 ;
F_7 ( V_45 , L_71 , V_576 ) ;
V_34 = F_18 ( V_65 , V_5 , ( void * * ) & V_96 ) ;
if ( V_34 )
return V_34 ;
V_96 -> V_2 . V_16 = F_5 ( V_414 ) ;
V_96 -> V_581 = F_4 ( V_576 ) ;
V_96 -> V_266 = V_575 ;
V_96 -> V_268 = V_269 ;
V_580 = V_576 * sizeof( struct V_577 ) ;
F_26 ( V_96 , V_580 - sizeof( struct V_577 ) ) ;
V_104 [ 0 ] . V_129 = ( char * ) V_96 ;
V_104 [ 0 ] . V_130 = F_29 ( V_96 ) + 4 - V_580 ;
V_104 [ 1 ] . V_129 = ( char * ) V_256 ;
V_104 [ 1 ] . V_130 = V_580 ;
F_21 ( & V_5 -> V_74 . V_582 . V_583 ) ;
V_34 = F_30 ( V_100 , V_5 -> V_20 , V_104 , 2 , & V_579 , V_584 ) ;
if ( V_34 ) {
F_7 ( V_45 , L_72 , V_34 ) ;
F_59 ( V_5 , V_585 ) ;
}
return V_34 ;
}
int
F_121 ( const unsigned int V_100 , struct V_4 * V_5 ,
const T_15 V_575 , const T_15 V_269 , const T_8 V_414 ,
const T_15 V_419 , const T_15 V_364 , const T_8 V_586 ,
const bool V_587 )
{
struct V_577 V_588 ;
V_588 . V_420 = F_88 ( V_364 ) ;
V_588 . V_418 = F_88 ( V_419 ) ;
V_588 . V_30 = F_5 ( V_586 ) ;
if ( ! V_587 && V_586 != V_589 )
V_588 . V_30 |= F_5 ( V_590 ) ;
return F_120 ( V_100 , V_5 , V_575 , V_269 , V_414 , 1 , & V_588 ) ;
}
int
F_122 ( const unsigned int V_100 , struct V_4 * V_5 ,
T_7 * V_591 , const T_5 V_592 )
{
int V_34 ;
struct V_593 * V_96 = NULL ;
F_7 ( V_45 , L_73 ) ;
V_34 = F_18 ( V_53 , V_5 , ( void * * ) & V_96 ) ;
if ( V_34 )
return V_34 ;
V_96 -> V_2 . V_15 = F_4 ( 1 ) ;
V_96 -> V_13 = F_4 ( 36 ) ;
F_26 ( V_96 , 12 ) ;
memcpy ( V_96 -> V_594 , V_591 , 16 ) ;
V_96 -> V_595 = V_592 ;
V_34 = F_58 ( V_100 , V_5 -> V_20 , ( char * ) V_96 , V_538 ) ;
if ( V_34 ) {
F_59 ( V_5 , V_539 ) ;
F_7 ( V_45 , L_74 , V_34 ) ;
}
return V_34 ;
}
