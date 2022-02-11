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
#ifdef F_36
if ( V_34 )
goto V_131;
if ( V_107 )
V_34 = F_37 ( V_108 , V_107 , V_21 ) ;
if ( V_34 == 1 )
V_34 = 0 ;
else if ( V_34 == 0 ) {
V_34 = - V_48 ;
goto V_131;
}
#endif
V_131:
F_38 ( V_105 , V_102 ) ;
return V_34 ;
}
int F_39 ( const unsigned int V_100 , struct V_4 * V_5 )
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
V_34 = F_40 ( V_100 , V_5 , V_154 , V_154 ,
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
F_41 ( const unsigned int V_100 , struct V_37 * V_20 ,
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
char * V_108 ;
char * V_164 = NULL ;
bool V_165 = false ;
F_7 ( V_45 , L_19 ) ;
if ( ! V_21 ) {
F_28 ( 1 , L_5 , V_111 ) ;
return - V_48 ;
}
F_42 ( V_20 -> V_166 . V_167 ) ;
V_20 -> V_166 . V_167 = NULL ;
V_20 -> V_168 = F_43 ( sizeof( struct V_169 ) , V_170 ) ;
if ( ! V_20 -> V_168 )
return - V_72 ;
V_20 -> V_168 -> V_171 = true ;
V_20 -> V_172 = V_173 ;
V_174:
if ( V_162 == V_175 )
V_162 = V_176 ;
V_34 = F_18 ( V_177 , NULL , ( void * * ) & V_96 ) ;
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
V_96 -> V_178 = 0 ;
V_104 [ 0 ] . V_129 = ( char * ) V_96 ;
V_104 [ 0 ] . V_130 = F_29 ( V_96 ) + 4 - 1 ;
if ( V_162 == V_163 ) {
V_164 = F_43 ( sizeof( struct V_179 ) ,
V_170 ) ;
if ( V_164 == NULL ) {
V_34 = - V_72 ;
goto V_180;
}
F_44 ( V_164 , V_20 ) ;
if ( V_165 ) {
F_7 ( V_136 , L_20 ) ;
V_34 = - V_181 ;
F_42 ( V_164 ) ;
goto V_180;
} else {
V_107 = sizeof( struct V_179 ) ;
V_108 = V_164 ;
}
} else if ( V_162 == V_176 ) {
V_96 -> V_2 . V_27 = V_20 -> V_28 ;
V_164 = F_45 ( sizeof( struct V_179 ) + 500 ,
V_170 ) ;
if ( V_164 == NULL ) {
V_34 = - V_72 ;
goto V_180;
}
V_34 = F_46 ( V_164 , & V_107 , V_20 ,
V_158 ) ;
if ( V_34 ) {
F_7 ( V_45 , L_21 ,
V_34 ) ;
goto V_180;
}
if ( V_165 ) {
F_7 ( V_136 , L_20 ) ;
V_34 = - V_181 ;
F_42 ( V_164 ) ;
goto V_180;
} else {
V_108 = V_164 ;
}
} else {
F_7 ( V_136 , L_22 ) ;
V_34 = - V_48 ;
goto V_180;
}
V_96 -> V_182 =
F_4 ( sizeof( struct V_159 ) -
1 - 4 ) ;
V_96 -> V_183 = F_4 ( V_107 ) ;
V_104 [ 1 ] . V_129 = V_108 ;
V_104 [ 1 ] . V_130 = V_107 ;
F_26 ( V_96 , V_107 - 1 ) ;
V_34 = F_30 ( V_100 , V_20 , V_104 , 2 , & V_105 ,
V_184 | V_110 ) ;
F_42 ( V_108 ) ;
V_102 = (struct V_160 * ) V_104 [ 0 ] . V_129 ;
if ( V_105 != V_161 &&
V_102 -> V_2 . V_185 == V_186 ) {
if ( V_162 != V_163 ) {
F_7 ( V_136 , L_23 ) ;
goto V_180;
}
if ( F_47 ( struct V_160 , V_187 ) - 4 !=
F_2 ( V_102 -> V_182 ) ) {
F_7 ( V_136 , L_24 ,
F_2 ( V_102 -> V_182 ) ) ;
V_34 = - V_48 ;
goto V_180;
}
V_162 = V_175 ;
V_34 = 0 ;
V_20 -> V_28 = V_102 -> V_2 . V_27 ;
V_34 = F_48 ( V_102 -> V_187 ,
F_2 ( V_102 -> V_183 ) , V_20 ) ;
}
if ( V_34 != 0 )
goto V_180;
V_20 -> V_188 = F_2 ( V_102 -> V_189 ) ;
if ( V_20 -> V_188 & V_190 )
F_7 ( V_136 , L_25 ) ;
V_180:
F_38 ( V_105 , V_102 ) ;
if ( ( V_162 == V_175 ) && ( V_34 == 0 ) )
goto V_174;
if ( ! V_34 ) {
F_10 ( & V_21 -> V_191 ) ;
if ( V_21 -> V_29 && V_21 -> V_192 -> V_193 ) {
V_34 = V_21 -> V_192 -> V_193 ( V_20 ) ;
F_42 ( V_20 -> V_166 . V_167 ) ;
V_20 -> V_166 . V_167 = NULL ;
if ( V_34 ) {
F_7 ( V_45 ,
L_26 ) ;
F_13 ( & V_21 -> V_191 ) ;
goto V_194;
}
}
if ( ! V_21 -> V_195 ) {
V_21 -> V_196 = 0x2 ;
V_21 -> V_195 = true ;
}
F_13 ( & V_21 -> V_191 ) ;
F_7 ( V_45 , L_27 ) ;
F_49 ( & V_197 ) ;
V_20 -> V_47 = V_198 ;
V_20 -> V_59 = false ;
F_50 ( & V_197 ) ;
}
V_194:
if ( ! V_21 -> V_29 ) {
F_42 ( V_20 -> V_166 . V_167 ) ;
V_20 -> V_166 . V_167 = NULL ;
}
F_42 ( V_20 -> V_168 ) ;
return V_34 ;
}
int
F_51 ( const unsigned int V_100 , struct V_37 * V_20 )
{
struct V_199 * V_96 ;
int V_34 = 0 ;
struct V_38 * V_21 ;
F_7 ( V_45 , L_28 , V_20 ) ;
if ( V_20 && ( V_20 -> V_21 ) )
V_21 = V_20 -> V_21 ;
else
return - V_48 ;
if ( V_20 -> V_59 )
goto V_200;
V_34 = F_18 ( V_201 , NULL , ( void * * ) & V_96 ) ;
if ( V_34 )
return V_34 ;
V_96 -> V_2 . V_27 = V_20 -> V_28 ;
if ( V_21 -> V_29 )
V_96 -> V_2 . V_30 |= V_31 ;
V_34 = F_52 ( V_100 , V_20 , ( char * ) & V_96 -> V_2 , 0 ) ;
V_200:
return V_34 ;
}
static inline void F_53 ( struct V_4 * V_5 , T_3 V_202 )
{
F_21 ( & V_5 -> V_74 . V_75 . V_203 [ V_202 ] ) ;
}
static inline void F_54 ( struct V_4 * V_5 )
{
V_5 -> V_204 = 256 ;
V_5 -> V_205 = 1048576 ;
V_5 -> V_206 = 16777216 ;
}
int
F_15 ( const unsigned int V_100 , struct V_37 * V_20 , const char * V_207 ,
struct V_4 * V_5 , const struct V_35 * V_208 )
{
struct V_209 * V_96 ;
struct V_210 * V_102 = NULL ;
struct V_103 V_104 [ 2 ] ;
int V_34 = 0 ;
int V_105 ;
int V_211 ;
struct V_38 * V_21 ;
T_1 * V_212 = NULL ;
F_7 ( V_45 , L_29 ) ;
if ( ( V_20 -> V_21 ) && V_207 )
V_21 = V_20 -> V_21 ;
else
return - V_48 ;
if ( V_5 && V_5 -> V_213 )
return - V_214 ;
V_212 = F_43 ( V_215 * 2 , V_170 ) ;
if ( V_212 == NULL )
return - V_72 ;
V_211 = F_55 ( V_212 , V_207 , strlen ( V_207 ) , V_208 ) + 1 ;
V_211 *= 2 ;
if ( V_211 < 2 ) {
F_42 ( V_212 ) ;
return - V_216 ;
}
V_34 = F_18 ( V_39 , V_5 , ( void * * ) & V_96 ) ;
if ( V_34 ) {
F_42 ( V_212 ) ;
return V_34 ;
}
if ( V_5 == NULL ) {
V_96 -> V_2 . V_27 = V_20 -> V_28 ;
}
V_104 [ 0 ] . V_129 = ( char * ) V_96 ;
V_104 [ 0 ] . V_130 = F_29 ( V_96 ) + 4 - 1 ;
V_96 -> V_217 = F_4 ( sizeof( struct V_209 )
- 1 - 4 ) ;
V_96 -> V_218 = F_4 ( V_211 - 2 ) ;
V_104 [ 1 ] . V_129 = V_212 ;
V_104 [ 1 ] . V_130 = V_211 ;
F_26 ( V_96 , V_211 - 1 ) ;
V_34 = F_30 ( V_100 , V_20 , V_104 , 2 , & V_105 , 0 ) ;
V_102 = (struct V_210 * ) V_104 [ 0 ] . V_129 ;
if ( V_34 != 0 ) {
if ( V_5 ) {
F_53 ( V_5 , V_219 ) ;
V_5 -> V_59 = true ;
}
goto V_220;
}
if ( V_5 == NULL ) {
V_20 -> V_221 = V_102 -> V_2 . V_25 ;
goto V_222;
}
if ( V_102 -> V_223 & V_224 )
F_7 ( V_45 , L_30 ) ;
else if ( V_102 -> V_223 & V_225 ) {
V_5 -> V_226 = true ;
F_7 ( V_45 , L_31 ) ;
} else if ( V_102 -> V_223 & V_227 ) {
V_5 -> V_228 = true ;
F_7 ( V_45 , L_32 ) ;
} else {
F_7 ( V_136 , L_33 , V_102 -> V_223 ) ;
V_34 = - V_181 ;
goto V_220;
}
V_5 -> V_229 = F_33 ( V_102 -> V_230 ) ;
V_5 -> V_22 = V_102 -> V_122 ;
V_5 -> V_231 = F_33 ( V_102 -> V_232 ) ;
V_5 -> V_40 = V_198 ;
V_5 -> V_59 = false ;
V_5 -> V_26 = V_102 -> V_2 . V_25 ;
F_56 ( V_5 -> V_61 , V_207 , sizeof( V_5 -> V_61 ) ) ;
if ( ( V_102 -> V_122 & V_233 ) &&
( ( V_5 -> V_229 & V_234 ) == 0 ) )
F_7 ( V_136 , L_34 ) ;
F_54 ( V_5 ) ;
if ( V_5 -> V_20 -> V_21 -> V_192 -> V_235 )
V_34 = V_5 -> V_20 -> V_21 -> V_192 -> V_235 ( V_100 , V_5 ) ;
V_222:
F_38 ( V_105 , V_102 ) ;
F_42 ( V_212 ) ;
return V_34 ;
V_220:
if ( V_102 -> V_2 . V_185 == V_236 ) {
F_7 ( V_136 , L_35 , V_207 ) ;
if ( V_5 )
V_5 -> V_213 = true ;
}
goto V_222;
}
int
F_57 ( const unsigned int V_100 , struct V_4 * V_5 )
{
struct V_237 * V_96 ;
int V_34 = 0 ;
struct V_38 * V_21 ;
struct V_37 * V_20 = V_5 -> V_20 ;
F_7 ( V_45 , L_36 ) ;
if ( V_20 && ( V_20 -> V_21 ) )
V_21 = V_20 -> V_21 ;
else
return - V_48 ;
if ( ( V_5 -> V_59 ) || ( V_5 -> V_20 -> V_59 ) )
return 0 ;
V_34 = F_18 ( V_44 , V_5 , ( void * * ) & V_96 ) ;
if ( V_34 )
return V_34 ;
V_34 = F_52 ( V_100 , V_20 , ( char * ) & V_96 -> V_2 , 0 ) ;
if ( V_34 )
F_53 ( V_5 , V_238 ) ;
return V_34 ;
}
static struct V_239 *
F_58 ( void )
{
struct V_239 * V_240 ;
V_240 = F_45 ( sizeof( struct V_239 ) , V_170 ) ;
if ( ! V_240 )
return NULL ;
V_240 -> V_241 . V_242 = F_4 ( F_47
( struct V_239 , V_243 ) ) ;
V_240 -> V_241 . V_82 = F_5 ( 16 ) ;
V_240 -> V_241 . V_244 = F_4 ( F_47
( struct V_239 , V_245 ) ) ;
V_240 -> V_241 . V_246 = F_4 ( 4 ) ;
V_240 -> V_245 [ 0 ] = 'D' ;
V_240 -> V_245 [ 1 ] = 'H' ;
V_240 -> V_245 [ 2 ] = 'n' ;
V_240 -> V_245 [ 3 ] = 'Q' ;
return V_240 ;
}
static struct V_239 *
F_59 ( struct V_247 * V_248 )
{
struct V_239 * V_240 ;
V_240 = F_45 ( sizeof( struct V_239 ) , V_170 ) ;
if ( ! V_240 )
return NULL ;
V_240 -> V_241 . V_242 = F_4 ( F_47
( struct V_239 , V_243 ) ) ;
V_240 -> V_241 . V_82 = F_5 ( 16 ) ;
V_240 -> V_241 . V_244 = F_4 ( F_47
( struct V_239 , V_245 ) ) ;
V_240 -> V_241 . V_246 = F_4 ( 4 ) ;
V_240 -> V_243 . V_249 . V_250 = V_248 -> V_251 ;
V_240 -> V_243 . V_249 . V_252 = V_248 -> V_253 ;
V_240 -> V_245 [ 0 ] = 'D' ;
V_240 -> V_245 [ 1 ] = 'H' ;
V_240 -> V_245 [ 2 ] = 'n' ;
V_240 -> V_245 [ 3 ] = 'C' ;
return V_240 ;
}
static T_7
F_60 ( struct V_38 * V_21 , struct V_254 * V_102 ,
unsigned int * V_255 )
{
char * V_256 ;
struct V_257 * V_258 ;
unsigned int V_259 = 0 ;
char * V_260 ;
V_256 = ( char * ) V_102 + 4 + F_33 ( V_102 -> V_261 ) ;
V_258 = (struct V_257 * ) V_256 ;
do {
V_258 = (struct V_257 * ) ( ( char * ) V_258 + V_259 ) ;
V_260 = F_2 ( V_258 -> V_244 ) + ( char * ) V_258 ;
if ( F_2 ( V_258 -> V_246 ) != 4 ||
strncmp ( V_260 , L_37 , 4 ) ) {
V_259 = F_33 ( V_258 -> V_262 ) ;
continue;
}
return V_21 -> V_192 -> V_263 ( V_258 , V_255 ) ;
} while ( V_259 != 0 );
return 0 ;
}
static int
F_61 ( struct V_38 * V_21 , struct V_103 * V_104 ,
unsigned int * V_264 , T_7 * V_265 )
{
struct V_266 * V_96 = V_104 [ 0 ] . V_129 ;
unsigned int V_267 = * V_264 ;
V_104 [ V_267 ] . V_129 = V_21 -> V_192 -> V_268 ( V_265 + 1 , * V_265 ) ;
if ( V_104 [ V_267 ] . V_129 == NULL )
return - V_72 ;
V_104 [ V_267 ] . V_130 = V_21 -> V_114 -> V_269 ;
V_96 -> V_270 = V_271 ;
if ( ! V_96 -> V_261 )
V_96 -> V_261 = F_5 (
sizeof( struct V_266 ) - 4 +
V_104 [ V_267 - 1 ] . V_130 ) ;
F_62 ( & V_96 -> V_272 ,
V_21 -> V_114 -> V_269 ) ;
F_26 ( & V_96 -> V_2 , V_21 -> V_114 -> V_269 ) ;
* V_264 = V_267 + 1 ;
return 0 ;
}
static int
F_63 ( struct V_103 * V_104 , unsigned int * V_264 ,
struct V_273 * V_274 )
{
struct V_266 * V_96 = V_104 [ 0 ] . V_129 ;
unsigned int V_267 = * V_264 ;
if ( V_274 -> V_275 ) {
V_104 [ V_267 ] . V_129 = F_59 ( V_274 -> V_248 ) ;
V_274 -> V_275 = false ;
} else
V_104 [ V_267 ] . V_129 = F_58 () ;
if ( V_104 [ V_267 ] . V_129 == NULL )
return - V_72 ;
V_104 [ V_267 ] . V_130 = sizeof( struct V_239 ) ;
if ( ! V_96 -> V_261 )
V_96 -> V_261 =
F_5 ( sizeof( struct V_266 ) - 4 +
V_104 [ 1 ] . V_130 ) ;
F_62 ( & V_96 -> V_272 , sizeof( struct V_239 ) ) ;
F_26 ( & V_96 -> V_2 , sizeof( struct V_239 ) ) ;
* V_264 = V_267 + 1 ;
return 0 ;
}
int
F_64 ( const unsigned int V_100 , struct V_273 * V_274 , T_1 * V_276 ,
T_7 * V_265 , struct V_277 * V_240 ,
struct V_278 * * V_279 )
{
struct V_266 * V_96 ;
struct V_254 * V_102 ;
struct V_38 * V_21 ;
struct V_4 * V_5 = V_274 -> V_5 ;
struct V_37 * V_20 = V_5 -> V_20 ;
struct V_103 V_104 [ 4 ] ;
int V_105 ;
int V_280 ;
T_1 * V_281 = NULL ;
int V_282 ;
int V_34 = 0 ;
unsigned int V_283 = 2 ;
T_8 V_284 = 0 ;
char * V_285 = NULL , * V_286 = NULL ;
F_7 ( V_45 , L_38 ) ;
if ( V_20 && ( V_20 -> V_21 ) )
V_21 = V_20 -> V_21 ;
else
return - V_48 ;
V_34 = F_18 ( V_43 , V_5 , ( void * * ) & V_96 ) ;
if ( V_34 )
return V_34 ;
if ( V_274 -> V_287 & V_288 )
V_284 |= V_289 ;
if ( V_274 -> V_287 & V_290 )
V_284 |= V_291 ;
V_96 -> V_292 = V_293 ;
V_96 -> V_294 = F_5 ( V_274 -> V_295 ) ;
V_96 -> V_296 = F_5 ( V_284 ) ;
V_96 -> V_297 = V_298 ;
V_96 -> V_299 = F_5 ( V_274 -> V_300 ) ;
V_96 -> V_301 = F_5 ( V_274 -> V_287 & V_302 ) ;
V_280 = ( 2 * F_65 ( ( V_303 * ) V_276 , V_304 ) ) + 2 ;
V_96 -> V_244 = F_4 ( sizeof( struct V_266 ) - 4 ) ;
V_104 [ 0 ] . V_129 = ( char * ) V_96 ;
V_104 [ 0 ] . V_130 = F_29 ( V_96 ) + 4 ;
V_96 -> V_246 = F_4 ( V_280 - 2 ) ;
V_104 [ 0 ] . V_130 -- ;
if ( V_280 % 8 != 0 ) {
V_282 = V_280 / 8 * 8 ;
if ( V_282 < V_280 )
V_282 += 8 ;
V_281 = F_45 ( V_282 , V_170 ) ;
if ( ! V_281 )
return - V_72 ;
memcpy ( ( char * ) V_281 , ( const char * ) V_276 ,
V_280 ) ;
V_280 = V_282 ;
V_276 = V_281 ;
}
V_104 [ 1 ] . V_130 = V_280 ;
V_104 [ 1 ] . V_129 = V_276 ;
F_26 ( V_96 , V_280 - 1 ) ;
if ( ! V_21 -> V_305 )
* V_265 = V_306 ;
if ( ! ( V_21 -> V_22 & V_307 ) ||
* V_265 == V_306 )
V_96 -> V_270 = * V_265 ;
else {
V_34 = F_61 ( V_21 , V_104 , & V_283 , V_265 ) ;
if ( V_34 ) {
F_66 ( V_96 ) ;
F_42 ( V_281 ) ;
return V_34 ;
}
V_286 = V_104 [ V_283 - 1 ] . V_129 ;
}
if ( * V_265 == V_308 ) {
if ( V_21 -> V_22 & V_307 ) {
struct V_257 * V_241 =
(struct V_257 * ) V_104 [ V_283 - 1 ] . V_129 ;
V_241 -> V_262 =
F_5 ( V_21 -> V_114 -> V_269 ) ;
}
V_34 = F_63 ( V_104 , & V_283 , V_274 ) ;
if ( V_34 ) {
F_66 ( V_96 ) ;
F_42 ( V_281 ) ;
F_42 ( V_286 ) ;
return V_34 ;
}
V_285 = V_104 [ V_283 - 1 ] . V_129 ;
}
V_34 = F_30 ( V_100 , V_20 , V_104 , V_283 , & V_105 , 0 ) ;
V_102 = (struct V_254 * ) V_104 [ 0 ] . V_129 ;
if ( V_34 != 0 ) {
F_53 ( V_5 , V_309 ) ;
if ( V_279 )
* V_279 = F_67 ( V_102 , F_29 ( V_102 ) + 4 ,
V_170 ) ;
goto V_310;
}
V_274 -> V_248 -> V_251 = V_102 -> V_250 ;
V_274 -> V_248 -> V_253 = V_102 -> V_252 ;
if ( V_240 ) {
memcpy ( V_240 , & V_102 -> V_311 , 32 ) ;
V_240 -> V_312 = V_102 -> V_312 ;
V_240 -> V_313 = V_102 -> V_314 ;
V_240 -> V_315 = V_102 -> V_296 ;
V_240 -> V_316 = F_5 ( 1 ) ;
V_240 -> V_317 = 0 ;
}
if ( V_102 -> V_318 == V_271 )
* V_265 = F_60 ( V_21 , V_102 , & V_274 -> V_248 -> V_255 ) ;
else
* V_265 = V_102 -> V_318 ;
V_310:
F_42 ( V_281 ) ;
F_42 ( V_286 ) ;
F_42 ( V_285 ) ;
F_38 ( V_105 , V_102 ) ;
return V_34 ;
}
int
F_40 ( const unsigned int V_100 , struct V_4 * V_5 , T_9 V_251 ,
T_9 V_253 , T_4 V_319 , bool V_320 , char * V_321 ,
T_4 V_322 , char * * V_323 , T_4 * V_324 )
{
struct V_325 * V_96 ;
struct V_326 * V_102 ;
struct V_38 * V_21 ;
struct V_37 * V_20 ;
struct V_103 V_104 [ 2 ] ;
int V_105 ;
int V_283 ;
int V_34 = 0 ;
F_7 ( V_45 , L_39 ) ;
if ( V_323 != NULL )
* V_323 = NULL ;
if ( V_324 )
* V_324 = 0 ;
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
V_96 -> V_327 = F_5 ( V_319 ) ;
V_96 -> V_250 = V_251 ;
V_96 -> V_252 = V_253 ;
if ( V_322 ) {
V_96 -> V_328 = F_5 ( V_322 ) ;
V_96 -> V_329 =
F_5 ( F_47 ( struct V_325 , V_187 ) - 4 ) ;
V_104 [ 1 ] . V_129 = V_321 ;
V_104 [ 1 ] . V_130 = V_322 ;
V_283 = 2 ;
} else
V_283 = 1 ;
V_96 -> V_330 = 0 ;
V_96 -> V_331 = 0 ;
V_96 -> V_332 = F_5 ( 0xFF00 ) ;
if ( V_320 )
V_96 -> V_30 = F_5 ( V_333 ) ;
else
V_96 -> V_30 = 0 ;
V_104 [ 0 ] . V_129 = ( char * ) V_96 ;
if ( V_322 ) {
V_104 [ 0 ] . V_130 = F_29 ( V_96 ) + 4 - 1 ;
F_26 ( V_96 , V_322 - 1 ) ;
} else
V_104 [ 0 ] . V_130 = F_29 ( V_96 ) + 4 ;
V_34 = F_30 ( V_100 , V_20 , V_104 , V_283 , & V_105 , 0 ) ;
V_102 = (struct V_326 * ) V_104 [ 0 ] . V_129 ;
if ( ( V_34 != 0 ) && ( V_34 != - V_216 ) ) {
F_53 ( V_5 , V_334 ) ;
goto V_335;
} else if ( V_34 == - V_216 ) {
if ( ( V_319 != V_336 ) &&
( V_319 != V_337 ) ) {
F_53 ( V_5 , V_334 ) ;
goto V_335;
}
}
if ( ( V_324 == NULL ) || ( V_323 == NULL ) )
goto V_335;
* V_324 = F_33 ( V_102 -> V_331 ) ;
if ( * V_324 == 0 )
goto V_335;
else if ( * V_324 > 0xFF00 ) {
F_7 ( V_136 , L_40 , * V_324 ) ;
* V_324 = 0 ;
V_34 = - V_48 ;
goto V_335;
}
if ( F_29 ( V_102 ) < F_33 ( V_102 -> V_330 ) + * V_324 ) {
F_7 ( V_136 , L_41 , * V_324 ,
F_33 ( V_102 -> V_330 ) ) ;
* V_324 = 0 ;
V_34 = - V_48 ;
goto V_335;
}
* V_323 = F_43 ( * V_324 , V_170 ) ;
if ( * V_323 == NULL ) {
V_34 = - V_72 ;
goto V_335;
}
memcpy ( * V_323 , V_102 -> V_2 . V_12 + F_33 ( V_102 -> V_330 ) ,
* V_324 ) ;
V_335:
F_38 ( V_105 , V_102 ) ;
return V_34 ;
}
int
F_68 ( const unsigned int V_100 , struct V_4 * V_5 ,
T_9 V_251 , T_9 V_253 )
{
int V_34 ;
struct V_338 V_339 ;
char * V_340 = NULL ;
V_339 . V_341 =
F_4 ( V_342 ) ;
V_34 = F_40 ( V_100 , V_5 , V_251 , V_253 ,
V_343 , true ,
( char * ) & V_339 ,
2 , & V_340 , NULL ) ;
F_7 ( V_45 , L_42 , V_34 ) ;
return V_34 ;
}
int
F_69 ( const unsigned int V_100 , struct V_4 * V_5 ,
T_9 V_251 , T_9 V_253 )
{
struct V_344 * V_96 ;
struct V_345 * V_102 ;
struct V_38 * V_21 ;
struct V_37 * V_20 = V_5 -> V_20 ;
struct V_103 V_104 [ 1 ] ;
int V_105 ;
int V_34 = 0 ;
F_7 ( V_45 , L_43 ) ;
if ( V_20 && ( V_20 -> V_21 ) )
V_21 = V_20 -> V_21 ;
else
return - V_48 ;
V_34 = F_18 ( V_52 , V_5 , ( void * * ) & V_96 ) ;
if ( V_34 )
return V_34 ;
V_96 -> V_250 = V_251 ;
V_96 -> V_252 = V_253 ;
V_104 [ 0 ] . V_129 = ( char * ) V_96 ;
V_104 [ 0 ] . V_130 = F_29 ( V_96 ) + 4 ;
V_34 = F_30 ( V_100 , V_20 , V_104 , 1 , & V_105 , 0 ) ;
V_102 = (struct V_345 * ) V_104 [ 0 ] . V_129 ;
if ( V_34 != 0 ) {
F_53 ( V_5 , V_346 ) ;
goto V_347;
}
V_347:
F_38 ( V_105 , V_102 ) ;
return V_34 ;
}
static int
F_70 ( unsigned int V_348 , unsigned int V_349 ,
struct V_1 * V_2 , unsigned int V_350 )
{
unsigned int V_351 = F_71 ( V_2 -> V_11 ) ;
char * V_352 = V_351 + 4 + ( char * ) V_2 ;
char * V_353 = 4 + V_348 + ( char * ) V_2 ;
char * V_354 = V_353 + V_349 ;
if ( V_349 < V_350 ) {
F_7 ( V_136 , L_44 ,
V_349 , V_350 ) ;
return - V_216 ;
}
if ( ( V_351 > 0x7FFFFF ) || ( V_349 > 0x7FFFFF ) ) {
F_7 ( V_136 , L_45 ,
V_349 , V_351 ) ;
return - V_216 ;
}
if ( ( V_353 > V_352 ) || ( V_354 > V_352 ) ) {
F_7 ( V_136 , L_46 ) ;
return - V_216 ;
}
return 0 ;
}
static int
F_72 ( unsigned int V_348 , unsigned int V_349 ,
struct V_1 * V_2 , unsigned int V_355 ,
char * V_356 )
{
char * V_353 = 4 + V_348 + ( char * ) V_2 ;
int V_34 ;
if ( ! V_356 )
return - V_216 ;
V_34 = F_70 ( V_348 , V_349 , V_2 , V_355 ) ;
if ( V_34 )
return V_34 ;
memcpy ( V_356 , V_353 , V_349 ) ;
return 0 ;
}
static int
F_73 ( const unsigned int V_100 , struct V_4 * V_5 ,
T_9 V_251 , T_9 V_253 , T_10 V_357 ,
T_11 V_358 , T_11 V_359 , void * V_356 )
{
struct V_360 * V_96 ;
struct V_361 * V_102 = NULL ;
struct V_103 V_104 [ 2 ] ;
int V_34 = 0 ;
int V_105 ;
struct V_38 * V_21 ;
struct V_37 * V_20 = V_5 -> V_20 ;
F_7 ( V_45 , L_47 ) ;
if ( V_20 && ( V_20 -> V_21 ) )
V_21 = V_20 -> V_21 ;
else
return - V_48 ;
V_34 = F_18 ( V_69 , V_5 , ( void * * ) & V_96 ) ;
if ( V_34 )
return V_34 ;
V_96 -> V_362 = V_363 ;
V_96 -> V_364 = V_357 ;
V_96 -> V_250 = V_251 ;
V_96 -> V_252 = V_253 ;
V_96 -> V_365 =
F_4 ( sizeof( struct V_360 ) - 1 - 4 ) ;
V_96 -> V_366 = F_5 ( V_358 ) ;
V_104 [ 0 ] . V_129 = ( char * ) V_96 ;
V_104 [ 0 ] . V_130 = F_29 ( V_96 ) + 4 ;
V_34 = F_30 ( V_100 , V_20 , V_104 , 1 , & V_105 , 0 ) ;
V_102 = (struct V_361 * ) V_104 [ 0 ] . V_129 ;
if ( V_34 ) {
F_53 ( V_5 , V_367 ) ;
goto V_368;
}
V_34 = F_72 ( F_2 ( V_102 -> V_369 ) ,
F_33 ( V_102 -> V_366 ) ,
& V_102 -> V_2 , V_359 , V_356 ) ;
V_368:
F_38 ( V_105 , V_102 ) ;
return V_34 ;
}
int
F_74 ( const unsigned int V_100 , struct V_4 * V_5 ,
T_9 V_251 , T_9 V_253 ,
struct V_277 * V_356 )
{
return F_73 ( V_100 , V_5 , V_251 , V_253 ,
V_370 ,
sizeof( struct V_277 ) + V_304 * 2 ,
sizeof( struct V_277 ) , V_356 ) ;
}
int
F_75 ( const unsigned int V_100 , struct V_4 * V_5 ,
T_9 V_251 , T_9 V_253 , T_12 * V_371 )
{
return F_73 ( V_100 , V_5 , V_251 , V_253 ,
V_372 ,
sizeof( struct V_373 ) ,
sizeof( struct V_373 ) , V_371 ) ;
}
static void
F_76 ( struct V_374 * V_375 )
{
struct V_38 * V_21 = V_375 -> V_376 ;
struct V_377 * V_378 = (struct V_377 * ) V_375 -> V_379 ;
unsigned int V_380 = 1 ;
if ( V_375 -> V_381 == V_382 )
V_380 = F_2 ( V_378 -> V_2 . V_15 ) ;
F_77 ( V_375 ) ;
F_78 ( V_21 , V_380 , V_383 ) ;
}
int
F_79 ( struct V_38 * V_21 )
{
struct V_384 * V_96 ;
int V_34 = 0 ;
struct V_103 V_104 ;
struct V_385 V_386 = { . V_387 = & V_104 ,
. V_388 = 1 } ;
F_7 ( V_45 , L_48 ) ;
V_34 = F_18 ( V_389 , NULL , ( void * * ) & V_96 ) ;
if ( V_34 )
return V_34 ;
V_96 -> V_2 . V_15 = F_4 ( 1 ) ;
V_104 . V_129 = ( char * ) V_96 ;
V_104 . V_130 = F_29 ( V_96 ) + 4 ;
V_34 = F_80 ( V_21 , & V_386 , NULL , F_76 , V_21 ,
V_383 ) ;
if ( V_34 )
F_7 ( V_45 , L_49 , V_34 ) ;
F_66 ( V_96 ) ;
return V_34 ;
}
int
F_81 ( const unsigned int V_100 , struct V_4 * V_5 , T_9 V_251 ,
T_9 V_253 )
{
struct V_390 * V_96 ;
struct V_38 * V_21 ;
struct V_37 * V_20 = V_5 -> V_20 ;
struct V_103 V_104 [ 1 ] ;
int V_105 ;
int V_34 = 0 ;
F_7 ( V_45 , L_50 ) ;
if ( V_20 && ( V_20 -> V_21 ) )
V_21 = V_20 -> V_21 ;
else
return - V_48 ;
V_34 = F_18 ( V_63 , V_5 , ( void * * ) & V_96 ) ;
if ( V_34 )
return V_34 ;
V_96 -> V_250 = V_251 ;
V_96 -> V_252 = V_253 ;
V_104 [ 0 ] . V_129 = ( char * ) V_96 ;
V_104 [ 0 ] . V_130 = F_29 ( V_96 ) + 4 ;
V_34 = F_30 ( V_100 , V_20 , V_104 , 1 , & V_105 , 0 ) ;
if ( V_34 != 0 )
F_53 ( V_5 , V_391 ) ;
F_38 ( V_105 , V_104 [ 0 ] . V_129 ) ;
return V_34 ;
}
static int
F_82 ( struct V_103 * V_104 , struct V_392 * V_393 ,
unsigned int V_394 , int V_395 )
{
int V_34 = - V_396 ;
struct V_397 * V_96 = NULL ;
V_34 = F_18 ( V_64 , V_393 -> V_5 , ( void * * ) & V_96 ) ;
if ( V_34 )
return V_34 ;
if ( V_393 -> V_5 -> V_20 -> V_21 == NULL )
return - V_398 ;
V_96 -> V_2 . V_16 = F_5 ( V_393 -> V_399 ) ;
V_96 -> V_250 = V_393 -> V_251 ;
V_96 -> V_252 = V_393 -> V_253 ;
V_96 -> V_400 = 0 ;
V_96 -> V_401 = 0 ;
V_96 -> V_178 = 0 ;
V_96 -> V_402 = 0 ;
V_96 -> V_403 = F_5 ( V_393 -> V_404 ) ;
V_96 -> V_405 = F_83 ( V_393 -> V_348 ) ;
if ( V_395 & V_406 ) {
if ( ! ( V_395 & V_407 ) ) {
V_96 -> V_2 . V_408 =
F_5 ( F_29 ( V_96 ) + 4 ) ;
} else
V_96 -> V_2 . V_408 = 0 ;
if ( V_395 & V_409 ) {
V_96 -> V_2 . V_30 |= V_410 ;
V_96 -> V_2 . V_27 = 0xFFFFFFFF ;
V_96 -> V_2 . V_25 = 0xFFFFFFFF ;
V_96 -> V_250 = 0xFFFFFFFF ;
V_96 -> V_252 = 0xFFFFFFFF ;
}
}
if ( V_394 > V_393 -> V_404 )
V_96 -> V_411 = F_5 ( V_394 ) ;
else
V_96 -> V_411 = 0 ;
V_104 [ 0 ] . V_129 = ( char * ) V_96 ;
V_104 [ 0 ] . V_130 = F_29 ( V_96 ) + 4 ;
return V_34 ;
}
static void
F_84 ( struct V_374 * V_375 )
{
struct V_412 * V_413 = V_375 -> V_376 ;
struct V_4 * V_5 = F_85 ( V_413 -> V_414 -> V_415 ) ;
struct V_38 * V_21 = V_5 -> V_20 -> V_21 ;
struct V_1 * V_240 = (struct V_1 * ) V_413 -> V_104 . V_129 ;
unsigned int V_380 = 1 ;
struct V_385 V_386 = { . V_387 = & V_413 -> V_104 ,
. V_388 = 1 ,
. V_416 = V_413 -> V_417 ,
. V_418 = V_413 -> V_419 ,
. V_420 = V_413 -> V_421 ,
. V_422 = V_413 -> V_423 } ;
F_7 ( V_45 , L_51 ,
V_111 , V_375 -> V_375 , V_375 -> V_381 , V_413 -> V_424 ,
V_413 -> V_425 ) ;
switch ( V_375 -> V_381 ) {
case V_382 :
V_380 = F_2 ( V_240 -> V_15 ) ;
if ( V_21 -> V_29 ) {
int V_34 ;
V_34 = F_86 ( & V_386 , V_21 ) ;
if ( V_34 )
F_7 ( V_136 , L_52 ,
V_34 ) ;
}
F_87 ( V_413 -> V_426 ) ;
F_88 ( V_5 , V_413 -> V_426 ) ;
break;
case V_427 :
case V_428 :
V_413 -> V_424 = - V_54 ;
if ( V_21 -> V_29 && V_413 -> V_426 )
V_413 -> V_426 = 0 ;
F_87 ( V_413 -> V_426 ) ;
F_88 ( V_5 , V_413 -> V_426 ) ;
break;
default:
if ( V_413 -> V_424 != - V_429 )
V_413 -> V_424 = - V_48 ;
}
if ( V_413 -> V_424 )
F_53 ( V_5 , V_430 ) ;
F_89 ( V_431 , & V_413 -> V_432 ) ;
F_77 ( V_375 ) ;
F_78 ( V_21 , V_380 , 0 ) ;
}
int
F_90 ( struct V_412 * V_413 )
{
int V_34 , V_109 = 0 ;
struct V_1 * V_240 ;
struct V_392 V_393 ;
struct V_385 V_386 = { . V_387 = & V_413 -> V_104 ,
. V_388 = 1 } ;
struct V_38 * V_21 ;
F_7 ( V_45 , L_53 ,
V_111 , V_413 -> V_348 , V_413 -> V_425 ) ;
V_393 . V_5 = F_85 ( V_413 -> V_414 -> V_415 ) ;
V_393 . V_348 = V_413 -> V_348 ;
V_393 . V_404 = V_413 -> V_425 ;
V_393 . V_251 = V_413 -> V_414 -> V_248 . V_251 ;
V_393 . V_253 = V_413 -> V_414 -> V_248 . V_253 ;
V_393 . V_399 = V_413 -> V_399 ;
V_21 = V_393 . V_5 -> V_20 -> V_21 ;
V_34 = F_82 ( & V_413 -> V_104 , & V_393 , 0 , 0 ) ;
if ( V_34 ) {
if ( V_34 == - V_54 && V_413 -> V_433 ) {
V_413 -> V_433 = 0 ;
F_49 ( & V_21 -> V_434 ) ;
V_21 -> V_435 -- ;
F_50 ( & V_21 -> V_434 ) ;
}
return V_34 ;
}
V_240 = (struct V_1 * ) V_413 -> V_104 . V_129 ;
V_413 -> V_104 . V_130 = F_29 ( V_413 -> V_104 . V_129 ) + 4 ;
if ( V_413 -> V_433 ) {
V_240 -> V_24 = F_4 ( F_91 ( V_413 -> V_425 ,
V_436 ) ) ;
F_49 ( & V_21 -> V_434 ) ;
V_21 -> V_433 += V_413 -> V_433 -
F_2 ( V_240 -> V_24 ) ;
F_50 ( & V_21 -> V_434 ) ;
F_92 ( & V_21 -> V_437 ) ;
V_109 = V_438 ;
}
F_93 ( & V_413 -> V_439 ) ;
V_34 = F_80 ( V_393 . V_5 -> V_20 -> V_21 , & V_386 ,
V_440 , F_84 ,
V_413 , V_109 ) ;
if ( V_34 ) {
F_94 ( & V_413 -> V_439 , V_441 ) ;
F_53 ( V_393 . V_5 , V_430 ) ;
}
F_66 ( V_240 ) ;
return V_34 ;
}
int
F_95 ( const unsigned int V_100 , struct V_392 * V_393 ,
unsigned int * V_442 , char * * V_240 , int * V_443 )
{
int V_105 , V_34 = - V_396 ;
struct V_444 * V_102 = NULL ;
struct V_103 V_104 [ 1 ] ;
* V_442 = 0 ;
V_34 = F_82 ( V_104 , V_393 , 0 , 0 ) ;
if ( V_34 )
return V_34 ;
V_34 = F_30 ( V_100 , V_393 -> V_5 -> V_20 , V_104 , 1 ,
& V_105 , V_184 ) ;
V_102 = (struct V_444 * ) V_104 [ 0 ] . V_129 ;
if ( V_102 -> V_2 . V_185 == V_445 ) {
F_38 ( V_105 , V_104 [ 0 ] . V_129 ) ;
return 0 ;
}
if ( V_34 ) {
F_53 ( V_393 -> V_5 , V_430 ) ;
F_7 ( V_136 , L_54 , V_34 ) ;
} else {
* V_442 = F_33 ( V_102 -> V_82 ) ;
if ( ( * V_442 > V_446 ) ||
( * V_442 > V_393 -> V_404 ) ) {
F_7 ( V_45 , L_55 ,
* V_442 , V_393 -> V_404 ) ;
V_34 = - V_48 ;
* V_442 = 0 ;
}
}
if ( * V_240 ) {
memcpy ( * V_240 , ( char * ) V_102 -> V_2 . V_12 + V_102 -> V_242 ,
* V_442 ) ;
F_38 ( V_105 , V_104 [ 0 ] . V_129 ) ;
} else if ( V_105 != V_161 ) {
* V_240 = V_104 [ 0 ] . V_129 ;
if ( V_105 == V_447 )
* V_443 = V_447 ;
else if ( V_105 == V_448 )
* V_443 = V_448 ;
}
return V_34 ;
}
static void
F_96 ( struct V_374 * V_375 )
{
struct V_449 * V_450 = V_375 -> V_376 ;
struct V_4 * V_5 = F_85 ( V_450 -> V_414 -> V_415 ) ;
unsigned int V_451 ;
struct V_452 * V_102 = (struct V_452 * ) V_375 -> V_379 ;
unsigned int V_380 = 1 ;
switch ( V_375 -> V_381 ) {
case V_382 :
V_380 = F_2 ( V_102 -> V_2 . V_15 ) ;
V_450 -> V_424 = F_97 ( V_375 , V_5 -> V_20 -> V_21 , 0 ) ;
if ( V_450 -> V_424 != 0 )
break;
V_451 = F_33 ( V_102 -> V_82 ) ;
if ( V_451 > V_450 -> V_425 )
V_451 &= 0xFFFF ;
if ( V_451 < V_450 -> V_425 )
V_450 -> V_424 = - V_453 ;
else
V_450 -> V_425 = V_451 ;
break;
case V_427 :
case V_428 :
V_450 -> V_424 = - V_54 ;
break;
default:
V_450 -> V_424 = - V_48 ;
break;
}
if ( V_450 -> V_424 )
F_53 ( V_5 , V_454 ) ;
F_89 ( V_431 , & V_450 -> V_432 ) ;
F_77 ( V_375 ) ;
F_78 ( V_5 -> V_20 -> V_21 , V_380 , 0 ) ;
}
int
F_98 ( struct V_449 * V_450 ,
void (* F_99)( struct V_455 * V_455 ) )
{
int V_34 = - V_396 , V_109 = 0 ;
struct V_456 * V_96 = NULL ;
struct V_4 * V_5 = F_85 ( V_450 -> V_414 -> V_415 ) ;
struct V_38 * V_21 = V_5 -> V_20 -> V_21 ;
struct V_103 V_104 ;
struct V_385 V_386 ;
V_34 = F_18 ( V_42 , V_5 , ( void * * ) & V_96 ) ;
if ( V_34 ) {
if ( V_34 == - V_54 && V_450 -> V_433 ) {
V_450 -> V_433 = 0 ;
F_49 ( & V_21 -> V_434 ) ;
V_21 -> V_435 -- ;
F_50 ( & V_21 -> V_434 ) ;
}
goto V_457;
}
V_96 -> V_2 . V_16 = F_5 ( V_450 -> V_414 -> V_399 ) ;
V_96 -> V_250 = V_450 -> V_414 -> V_248 . V_251 ;
V_96 -> V_252 = V_450 -> V_414 -> V_248 . V_253 ;
V_96 -> V_458 = 0 ;
V_96 -> V_459 = 0 ;
V_96 -> V_178 = 0 ;
V_96 -> V_405 = F_83 ( V_450 -> V_348 ) ;
V_96 -> V_242 = F_4 (
F_47 ( struct V_456 , V_187 ) - 4 ) ;
V_96 -> V_411 = 0 ;
V_104 . V_130 = F_29 ( V_96 ) + 4 - 1 ;
V_104 . V_129 = V_96 ;
V_386 . V_387 = & V_104 ;
V_386 . V_388 = 1 ;
V_386 . V_416 = V_450 -> V_417 ;
V_386 . V_418 = V_450 -> V_419 ;
V_386 . V_420 = V_450 -> V_421 ;
V_386 . V_422 = V_450 -> V_423 ;
F_7 ( V_45 , L_56 ,
V_450 -> V_348 , V_450 -> V_425 ) ;
V_96 -> V_403 = F_5 ( V_450 -> V_425 ) ;
F_26 ( & V_96 -> V_2 , V_450 -> V_425 - 1 ) ;
if ( V_450 -> V_433 ) {
V_96 -> V_2 . V_24 = F_4 ( F_91 ( V_450 -> V_425 ,
V_436 ) ) ;
F_49 ( & V_21 -> V_434 ) ;
V_21 -> V_433 += V_450 -> V_433 -
F_2 ( V_96 -> V_2 . V_24 ) ;
F_50 ( & V_21 -> V_434 ) ;
F_92 ( & V_21 -> V_437 ) ;
V_109 = V_438 ;
}
F_93 ( & V_450 -> V_439 ) ;
V_34 = F_80 ( V_21 , & V_386 , NULL , F_96 , V_450 ,
V_109 ) ;
if ( V_34 ) {
F_94 ( & V_450 -> V_439 , F_99 ) ;
F_53 ( V_5 , V_454 ) ;
}
V_457:
F_66 ( V_96 ) ;
return V_34 ;
}
int
F_100 ( const unsigned int V_100 , struct V_392 * V_393 ,
unsigned int * V_442 , struct V_103 * V_104 , int V_460 )
{
int V_34 = 0 ;
struct V_456 * V_96 = NULL ;
struct V_452 * V_102 = NULL ;
int V_105 ;
* V_442 = 0 ;
if ( V_460 < 1 )
return V_34 ;
V_34 = F_18 ( V_42 , V_393 -> V_5 , ( void * * ) & V_96 ) ;
if ( V_34 )
return V_34 ;
if ( V_393 -> V_5 -> V_20 -> V_21 == NULL )
return - V_398 ;
V_96 -> V_2 . V_16 = F_5 ( V_393 -> V_399 ) ;
V_96 -> V_250 = V_393 -> V_251 ;
V_96 -> V_252 = V_393 -> V_253 ;
V_96 -> V_458 = 0 ;
V_96 -> V_459 = 0 ;
V_96 -> V_178 = 0 ;
V_96 -> V_403 = F_5 ( V_393 -> V_404 ) ;
V_96 -> V_405 = F_83 ( V_393 -> V_348 ) ;
V_96 -> V_242 = F_4 (
F_47 ( struct V_456 , V_187 ) - 4 ) ;
V_96 -> V_411 = 0 ;
V_104 [ 0 ] . V_129 = ( char * ) V_96 ;
V_104 [ 0 ] . V_130 = F_29 ( V_96 ) + 4 - 1 ;
F_26 ( V_96 , V_393 -> V_404 - 1 ) ;
V_34 = F_30 ( V_100 , V_393 -> V_5 -> V_20 , V_104 , V_460 + 1 ,
& V_105 , 0 ) ;
V_102 = (struct V_452 * ) V_104 [ 0 ] . V_129 ;
if ( V_34 ) {
F_53 ( V_393 -> V_5 , V_454 ) ;
F_7 ( V_136 , L_57 , V_34 ) ;
} else
* V_442 = F_33 ( V_102 -> V_82 ) ;
F_38 ( V_105 , V_102 ) ;
return V_34 ;
}
static unsigned int
F_101 ( char * V_461 , char * V_354 , char * * V_462 , T_11 V_463 )
{
int V_464 ;
unsigned int V_465 = 0 ;
unsigned int V_466 = 0 ;
T_13 * V_467 ;
if ( V_461 == NULL )
return 0 ;
V_467 = ( T_13 * ) V_461 ;
while ( 1 ) {
V_467 = ( T_13 * )
( ( char * ) V_467 + V_466 ) ;
if ( ( char * ) V_467 + V_463 > V_354 ) {
F_7 ( V_136 , L_58 ) ;
break;
}
V_464 = F_33 ( V_467 -> V_468 ) ;
if ( ( char * ) V_467 + V_464 + V_463 > V_354 ) {
F_7 ( V_136 , L_59 ,
V_354 ) ;
break;
}
* V_462 = ( char * ) V_467 ;
V_465 ++ ;
V_466 = F_33 ( V_467 -> V_469 ) ;
if ( ! V_466 )
break;
}
return V_465 ;
}
int
F_102 ( const unsigned int V_100 , struct V_4 * V_5 ,
T_9 V_251 , T_9 V_253 , int V_470 ,
struct V_471 * V_472 )
{
struct V_473 * V_96 ;
struct V_474 * V_102 = NULL ;
struct V_103 V_104 [ 2 ] ;
int V_34 = 0 ;
int V_464 ;
int V_105 = V_161 ;
unsigned char * V_475 ;
struct V_38 * V_21 ;
struct V_37 * V_20 = V_5 -> V_20 ;
T_1 V_476 = F_4 ( '*' ) ;
char * V_352 ;
unsigned int V_477 = V_478 ;
T_11 V_479 ;
if ( V_20 && ( V_20 -> V_21 ) )
V_21 = V_20 -> V_21 ;
else
return - V_48 ;
V_34 = F_18 ( V_67 , V_5 , ( void * * ) & V_96 ) ;
if ( V_34 )
return V_34 ;
switch ( V_472 -> V_480 ) {
case V_481 :
V_96 -> V_482 = V_483 ;
V_479 = sizeof( T_13 ) - 1 ;
break;
case V_484 :
V_96 -> V_482 = V_485 ;
V_479 = sizeof( V_486 ) - 1 ;
break;
default:
F_7 ( V_136 , L_60 ,
V_472 -> V_480 ) ;
V_34 = - V_216 ;
goto V_487;
}
V_96 -> V_488 = F_5 ( V_470 ) ;
V_96 -> V_250 = V_251 ;
V_96 -> V_252 = V_253 ;
V_464 = 0x2 ;
V_475 = V_96 -> V_187 ;
memcpy ( V_475 , & V_476 , V_464 ) ;
V_96 -> V_489 =
F_4 ( sizeof( struct V_473 ) - 1 - 4 ) ;
V_96 -> V_468 = F_4 ( V_464 ) ;
V_477 = F_32 (unsigned int, output_size, server->maxBuf) ;
V_477 = F_32 (unsigned int, output_size, 2 << 15 ) ;
V_96 -> V_366 = F_5 ( V_477 ) ;
V_104 [ 0 ] . V_129 = ( char * ) V_96 ;
V_104 [ 0 ] . V_130 = F_29 ( V_96 ) + 4 - 1 ;
V_104 [ 1 ] . V_129 = ( char * ) ( V_96 -> V_187 ) ;
V_104 [ 1 ] . V_130 = V_464 ;
F_26 ( V_96 , V_464 - 1 ) ;
V_34 = F_30 ( V_100 , V_20 , V_104 , 2 , & V_105 , 0 ) ;
V_102 = (struct V_474 * ) V_104 [ 0 ] . V_129 ;
if ( V_34 ) {
if ( V_34 == - V_429 && V_102 -> V_2 . V_185 == V_490 ) {
V_472 -> V_491 = true ;
V_34 = 0 ;
}
F_53 ( V_5 , V_492 ) ;
goto V_487;
}
V_34 = F_70 ( F_2 ( V_102 -> V_369 ) ,
F_33 ( V_102 -> V_366 ) , & V_102 -> V_2 ,
V_479 ) ;
if ( V_34 )
goto V_487;
V_472 -> V_493 = true ;
if ( V_472 -> V_494 ) {
if ( V_472 -> V_495 )
F_66 ( V_472 -> V_494 ) ;
else
F_103 ( V_472 -> V_494 ) ;
}
V_472 -> V_494 = ( char * ) V_102 ;
V_472 -> V_496 = V_472 -> V_497 = 4 +
( char * ) & V_102 -> V_2 + F_2 ( V_102 -> V_369 ) ;
V_352 = F_29 ( V_102 ) + 4 + ( char * ) & V_102 -> V_2 ;
V_472 -> V_498 =
F_101 ( V_472 -> V_496 , V_352 ,
& V_472 -> V_497 , V_479 ) ;
V_472 -> V_499 += V_472 -> V_498 ;
F_7 ( V_45 , L_61 ,
V_472 -> V_498 , V_472 -> V_499 ,
V_472 -> V_496 , V_472 -> V_497 ) ;
if ( V_105 == V_448 )
V_472 -> V_495 = false ;
else if ( V_105 == V_447 )
V_472 -> V_495 = true ;
else
F_7 ( V_136 , L_62 ) ;
return V_34 ;
V_487:
F_38 ( V_105 , V_102 ) ;
return V_34 ;
}
static int
F_104 ( const unsigned int V_100 , struct V_4 * V_5 ,
T_9 V_251 , T_9 V_253 , T_4 V_399 , int V_357 ,
unsigned int V_267 , void * * V_356 , unsigned int * V_463 )
{
struct V_500 * V_96 ;
struct V_501 * V_102 = NULL ;
struct V_103 * V_104 ;
int V_34 = 0 ;
int V_105 ;
unsigned int V_502 ;
struct V_38 * V_21 ;
struct V_37 * V_20 = V_5 -> V_20 ;
if ( V_20 && ( V_20 -> V_21 ) )
V_21 = V_20 -> V_21 ;
else
return - V_48 ;
if ( ! V_267 )
return - V_216 ;
V_104 = F_43 ( sizeof( struct V_103 ) * V_267 , V_170 ) ;
if ( ! V_104 )
return - V_72 ;
V_34 = F_18 ( V_70 , V_5 , ( void * * ) & V_96 ) ;
if ( V_34 ) {
F_42 ( V_104 ) ;
return V_34 ;
}
V_96 -> V_2 . V_16 = F_5 ( V_399 ) ;
V_96 -> V_362 = V_363 ;
V_96 -> V_364 = V_357 ;
V_96 -> V_250 = V_251 ;
V_96 -> V_252 = V_253 ;
V_96 -> V_503 =
F_4 ( sizeof( struct V_500 ) - 1 - 4 ) ;
V_96 -> V_504 = F_5 ( * V_463 ) ;
F_26 ( V_96 , * V_463 - 1 ) ;
memcpy ( V_96 -> V_187 , * V_356 , * V_463 ) ;
V_104 [ 0 ] . V_129 = ( char * ) V_96 ;
V_104 [ 0 ] . V_130 = F_29 ( V_96 ) + 4 ;
for ( V_502 = 1 ; V_502 < V_267 ; V_502 ++ ) {
F_26 ( V_96 , V_463 [ V_502 ] ) ;
F_62 ( & V_96 -> V_504 , V_463 [ V_502 ] ) ;
V_104 [ V_502 ] . V_129 = ( char * ) V_356 [ V_502 ] ;
V_104 [ V_502 ] . V_130 = V_463 [ V_502 ] ;
}
V_34 = F_30 ( V_100 , V_20 , V_104 , V_267 , & V_105 , 0 ) ;
V_102 = (struct V_501 * ) V_104 [ 0 ] . V_129 ;
if ( V_34 != 0 )
F_53 ( V_5 , V_505 ) ;
F_38 ( V_105 , V_102 ) ;
F_42 ( V_104 ) ;
return V_34 ;
}
int
F_105 ( const unsigned int V_100 , struct V_4 * V_5 ,
T_9 V_251 , T_9 V_253 , T_1 * V_506 )
{
struct V_507 V_508 ;
void * * V_356 ;
unsigned int V_463 [ 2 ] ;
int V_34 ;
int V_464 = ( 2 * F_65 ( ( V_303 * ) V_506 , V_304 ) ) ;
V_356 = F_43 ( sizeof( void * ) * 2 , V_170 ) ;
if ( ! V_356 )
return - V_72 ;
V_508 . V_509 = 1 ;
V_508 . V_510 = 0 ;
V_508 . V_468 = F_5 ( V_464 ) ;
V_356 [ 0 ] = & V_508 ;
V_463 [ 0 ] = sizeof( struct V_507 ) ;
V_356 [ 1 ] = V_506 ;
V_463 [ 1 ] = V_464 + 2 ;
V_34 = F_104 ( V_100 , V_5 , V_251 , V_253 ,
V_17 -> V_18 , V_511 , 2 , V_356 ,
V_463 ) ;
F_42 ( V_356 ) ;
return V_34 ;
}
int
F_106 ( const unsigned int V_100 , struct V_4 * V_5 ,
T_9 V_251 , T_9 V_253 , T_1 * V_506 )
{
struct V_512 V_508 ;
void * * V_356 ;
unsigned int V_463 [ 2 ] ;
int V_34 ;
int V_464 = ( 2 * F_65 ( ( V_303 * ) V_506 , V_304 ) ) ;
V_356 = F_43 ( sizeof( void * ) * 2 , V_170 ) ;
if ( ! V_356 )
return - V_72 ;
V_508 . V_509 = 0 ;
V_508 . V_510 = 0 ;
V_508 . V_468 = F_5 ( V_464 ) ;
V_356 [ 0 ] = & V_508 ;
V_463 [ 0 ] = sizeof( struct V_512 ) ;
V_356 [ 1 ] = V_506 ;
V_463 [ 1 ] = V_464 + 2 ;
V_34 = F_104 ( V_100 , V_5 , V_251 , V_253 ,
V_17 -> V_18 , V_513 , 2 , V_356 , V_463 ) ;
F_42 ( V_356 ) ;
return V_34 ;
}
int
F_107 ( const unsigned int V_100 , struct V_4 * V_5 , T_9 V_251 ,
T_9 V_253 , T_4 V_399 , T_12 * V_514 , bool V_515 )
{
struct V_516 V_508 ;
void * V_356 ;
unsigned int V_463 ;
V_508 . V_313 = * V_514 ;
V_356 = & V_508 ;
V_463 = sizeof( struct V_516 ) ;
if ( V_515 )
return F_104 ( V_100 , V_5 , V_251 , V_253 ,
V_399 , V_517 , 1 , & V_356 , & V_463 ) ;
else
return F_104 ( V_100 , V_5 , V_251 , V_253 ,
V_399 , V_518 , 1 , & V_356 , & V_463 ) ;
}
int
F_108 ( const unsigned int V_100 , struct V_4 * V_5 ,
T_9 V_251 , T_9 V_253 , T_14 * V_240 )
{
unsigned int V_463 ;
V_463 = sizeof( T_14 ) ;
return F_104 ( V_100 , V_5 , V_251 , V_253 ,
V_17 -> V_18 , V_519 , 1 ,
( void * * ) & V_240 , & V_463 ) ;
}
int
F_109 ( const unsigned int V_100 , struct V_4 * V_5 ,
const T_9 V_251 , const T_9 V_253 ,
T_7 V_520 )
{
int V_34 ;
struct V_521 * V_96 = NULL ;
F_7 ( V_45 , L_63 ) ;
V_34 = F_18 ( V_53 , V_5 , ( void * * ) & V_96 ) ;
if ( V_34 )
return V_34 ;
V_96 -> V_522 = V_253 ;
V_96 -> V_523 = V_251 ;
V_96 -> V_318 = V_520 ;
V_96 -> V_2 . V_15 = F_4 ( 1 ) ;
V_34 = F_52 ( V_100 , V_5 -> V_20 , ( char * ) V_96 , V_524 ) ;
if ( V_34 ) {
F_53 ( V_5 , V_525 ) ;
F_7 ( V_45 , L_64 , V_34 ) ;
}
return V_34 ;
}
static void
F_110 ( struct V_526 * V_527 ,
struct V_528 * V_529 )
{
V_529 -> V_530 = F_33 ( V_527 -> V_531 ) *
F_33 ( V_527 -> V_532 ) ;
V_529 -> V_533 = F_111 ( V_527 -> V_534 ) ;
V_529 -> V_535 = F_111 ( V_527 -> V_536 ) ;
V_529 -> V_537 = F_111 ( V_527 -> V_538 ) ;
return;
}
static int
F_112 ( struct V_103 * V_104 , struct V_4 * V_5 , int V_539 ,
int V_540 , T_9 V_251 , T_9 V_253 )
{
int V_34 ;
struct V_360 * V_96 ;
F_7 ( V_45 , L_65 , V_539 ) ;
if ( ( V_5 -> V_20 == NULL ) || ( V_5 -> V_20 -> V_21 == NULL ) )
return - V_48 ;
V_34 = F_18 ( V_69 , V_5 , ( void * * ) & V_96 ) ;
if ( V_34 )
return V_34 ;
V_96 -> V_362 = V_541 ;
V_96 -> V_364 = V_539 ;
V_96 -> V_250 = V_251 ;
V_96 -> V_252 = V_253 ;
V_96 -> V_365 =
F_4 ( sizeof( struct V_360 ) - 1 - 4 ) ;
V_96 -> V_366 = F_5 (
V_540 + sizeof( struct V_361 ) - 1 - 4 ) ;
V_104 -> V_129 = ( char * ) V_96 ;
V_104 -> V_130 = F_29 ( V_96 ) + 4 ;
return 0 ;
}
int
F_113 ( const unsigned int V_100 , struct V_4 * V_5 ,
T_9 V_251 , T_9 V_253 , struct V_528 * V_542 )
{
struct V_361 * V_102 = NULL ;
struct V_103 V_104 ;
int V_34 = 0 ;
int V_105 ;
struct V_37 * V_20 = V_5 -> V_20 ;
struct V_526 * V_508 = NULL ;
V_34 = F_112 ( & V_104 , V_5 , V_543 ,
sizeof( struct V_526 ) ,
V_251 , V_253 ) ;
if ( V_34 )
return V_34 ;
V_34 = F_30 ( V_100 , V_20 , & V_104 , 1 , & V_105 , 0 ) ;
if ( V_34 ) {
F_53 ( V_5 , V_367 ) ;
goto V_544;
}
V_102 = (struct V_361 * ) V_104 . V_129 ;
V_508 = (struct V_526 * ) ( 4 +
F_2 ( V_102 -> V_369 ) + ( char * ) & V_102 -> V_2 ) ;
V_34 = F_70 ( F_2 ( V_102 -> V_369 ) ,
F_33 ( V_102 -> V_366 ) , & V_102 -> V_2 ,
sizeof( struct V_526 ) ) ;
if ( ! V_34 )
F_110 ( V_508 , V_542 ) ;
V_544:
F_38 ( V_105 , V_104 . V_129 ) ;
return V_34 ;
}
int
F_114 ( const unsigned int V_100 , struct V_4 * V_5 ,
T_9 V_251 , T_9 V_253 , int V_539 )
{
struct V_361 * V_102 = NULL ;
struct V_103 V_104 ;
int V_34 = 0 ;
int V_105 , V_545 , V_359 ;
struct V_37 * V_20 = V_5 -> V_20 ;
unsigned int V_546 , V_348 ;
if ( V_539 == V_547 ) {
V_545 = sizeof( V_548 ) ;
V_359 = sizeof( V_548 ) ;
} else if ( V_539 == V_549 ) {
V_545 = sizeof( V_550 ) ;
V_359 = V_551 ;
} else if ( V_539 == V_552 ) {
V_545 = sizeof( struct V_553 ) ;
V_359 = sizeof( struct V_553 ) ;
} else {
F_7 ( V_45 , L_66 , V_539 ) ;
return - V_216 ;
}
V_34 = F_112 ( & V_104 , V_5 , V_539 , V_545 ,
V_251 , V_253 ) ;
if ( V_34 )
return V_34 ;
V_34 = F_30 ( V_100 , V_20 , & V_104 , 1 , & V_105 , 0 ) ;
if ( V_34 ) {
F_53 ( V_5 , V_367 ) ;
goto V_554;
}
V_102 = (struct V_361 * ) V_104 . V_129 ;
V_546 = F_33 ( V_102 -> V_366 ) ;
V_348 = F_2 ( V_102 -> V_369 ) ;
V_34 = F_70 ( V_348 , V_546 , & V_102 -> V_2 , V_359 ) ;
if ( V_34 )
goto V_554;
if ( V_539 == V_549 )
memcpy ( & V_5 -> V_555 , 4 + V_348
+ ( char * ) & V_102 -> V_2 , F_32 (unsigned int,
rsp_len, max_len) ) ;
else if ( V_539 == V_547 )
memcpy ( & V_5 -> V_556 , 4 + V_348
+ ( char * ) & V_102 -> V_2 , sizeof( V_548 ) ) ;
else if ( V_539 == V_552 ) {
struct V_553 * V_557 = (struct V_553 * )
( 4 + V_348 + ( char * ) & V_102 -> V_2 ) ;
V_5 -> V_558 = F_33 ( V_557 -> V_30 ) ;
V_5 -> V_559 =
F_33 ( V_557 -> V_560 ) ;
}
V_554:
F_38 ( V_105 , V_104 . V_129 ) ;
return V_34 ;
}
int
F_115 ( const unsigned int V_100 , struct V_4 * V_5 ,
const T_15 V_561 , const T_15 V_253 , const T_8 V_399 ,
const T_8 V_562 , struct V_563 * V_240 )
{
int V_34 = 0 ;
struct V_564 * V_96 = NULL ;
struct V_103 V_104 [ 2 ] ;
int V_565 ;
unsigned int V_566 ;
F_7 ( V_45 , L_67 , V_562 ) ;
V_34 = F_18 ( V_65 , V_5 , ( void * * ) & V_96 ) ;
if ( V_34 )
return V_34 ;
V_96 -> V_2 . V_16 = F_5 ( V_399 ) ;
V_96 -> V_567 = F_4 ( V_562 ) ;
V_96 -> V_250 = V_561 ;
V_96 -> V_252 = V_253 ;
V_566 = V_562 * sizeof( struct V_563 ) ;
F_26 ( V_96 , V_566 - sizeof( struct V_563 ) ) ;
V_104 [ 0 ] . V_129 = ( char * ) V_96 ;
V_104 [ 0 ] . V_130 = F_29 ( V_96 ) + 4 - V_566 ;
V_104 [ 1 ] . V_129 = ( char * ) V_240 ;
V_104 [ 1 ] . V_130 = V_566 ;
F_21 ( & V_5 -> V_74 . V_568 . V_569 ) ;
V_34 = F_30 ( V_100 , V_5 -> V_20 , V_104 , 2 , & V_565 , V_570 ) ;
if ( V_34 ) {
F_7 ( V_45 , L_68 , V_34 ) ;
F_53 ( V_5 , V_571 ) ;
}
return V_34 ;
}
int
F_116 ( const unsigned int V_100 , struct V_4 * V_5 ,
const T_15 V_561 , const T_15 V_253 , const T_8 V_399 ,
const T_15 V_404 , const T_15 V_348 , const T_8 V_572 ,
const bool V_573 )
{
struct V_563 V_574 ;
V_574 . V_405 = F_83 ( V_348 ) ;
V_574 . V_403 = F_83 ( V_404 ) ;
V_574 . V_30 = F_5 ( V_572 ) ;
if ( ! V_573 && V_572 != V_575 )
V_574 . V_30 |= F_5 ( V_576 ) ;
return F_115 ( V_100 , V_5 , V_561 , V_253 , V_399 , 1 , & V_574 ) ;
}
int
F_117 ( const unsigned int V_100 , struct V_4 * V_5 ,
T_7 * V_577 , const T_5 V_578 )
{
int V_34 ;
struct V_579 * V_96 = NULL ;
F_7 ( V_45 , L_69 ) ;
V_34 = F_18 ( V_53 , V_5 , ( void * * ) & V_96 ) ;
if ( V_34 )
return V_34 ;
V_96 -> V_2 . V_15 = F_4 ( 1 ) ;
V_96 -> V_13 = F_4 ( 36 ) ;
F_26 ( V_96 , 12 ) ;
memcpy ( V_96 -> V_580 , V_577 , 16 ) ;
V_96 -> V_581 = V_578 ;
V_34 = F_52 ( V_100 , V_5 -> V_20 , ( char * ) V_96 , V_524 ) ;
if ( V_34 ) {
F_53 ( V_5 , V_525 ) ;
F_7 ( V_45 , L_70 , V_34 ) ;
}
return V_34 ;
}
