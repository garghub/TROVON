int F_1 ( struct V_1 * V_2 , const struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
struct V_7 * V_7 ;
struct V_8 * V_8 ;
T_1 * V_9 = ( T_1 * ) V_4 -> V_9 ;
T_1 * V_10 = ( T_1 * ) V_4 -> V_9 + ( V_4 -> V_11 >> 2 ) ;
T_2 * V_12 = NULL ;
T_3 V_13 ;
int V_14 ;
int V_15 ;
if ( V_6 -> V_16 )
return 0 ;
while ( V_9 < V_10 && * V_9 )
V_9 ++ ;
while ( V_9 < V_10 && ! * V_9 )
V_9 ++ ;
V_8 = (struct V_8 * ) V_9 ;
while ( V_8 -> V_9 <= V_10 && ( V_8 -> V_9 +
( V_13 = F_2 ( V_8 -> V_13 ) ) ) <= V_10 ) {
T_1 V_17 = F_2 ( V_8 -> V_17 ) ;
switch ( V_17 ) {
case V_18 :
V_6 -> V_19 = F_3 ( ( V_20 * )
V_8 -> V_9 ) ;
switch ( V_6 -> V_19 ) {
case V_21 :
case V_22 :
case V_23 : {
char * V_24 = ( char * ) V_8 -> V_9 ;
F_4 ( V_6 -> V_25 -> V_26 ,
L_1 ,
V_24 [ 2 ] , V_24 [ 3 ] ) ;
break;
}
case V_27 :
default:
F_5 ( V_6 -> V_25 -> V_26 ,
L_2 ) ;
return - V_28 ;
}
break;
case V_29 :
if ( F_6 ( ( unsigned char * ) V_8 -> V_9 , 24 ) < 24 )
V_12 = ( unsigned char * ) V_8 -> V_9 ;
break;
case V_30 : {
struct V_31 * V_32 =
(struct V_31 * ) V_8 -> V_9 ;
V_6 -> V_16 = F_2 ( V_32 -> V_16 ) ;
V_6 -> V_33 = F_2 ( V_32 -> V_33 ) - 0x3500 ;
V_6 -> V_34 = V_32 -> V_34 ;
V_6 -> V_35 = V_32 -> V_35 ;
V_6 -> V_36 = V_32 -> V_36 ;
V_6 -> V_37 = V_32 -> V_37 ;
if ( F_2 ( V_8 -> V_13 ) == 11 )
V_6 -> V_38 = F_7 ( V_32 -> V_38 ) ;
else
V_6 -> V_38 = ( T_3 )
0x620 - V_6 -> V_39 ;
V_15 = V_6 -> V_39 +
sizeof( struct V_40 ) +
4 +
V_41 ;
if ( V_6 -> V_38 > V_15 && V_42 == 4096 ) {
F_8 ( V_43 L_3
L_4 , V_6 -> V_38 , V_15 ) ;
V_6 -> V_38 = V_15 ;
}
break;
}
case V_44 :
V_7 = (struct V_7 * ) V_8 -> V_9 ;
for ( V_14 = 0 ; V_14 < ( V_13 * sizeof( * V_7 ) / 4 ) ; V_14 ++ )
if ( V_7 [ V_14 ] . V_45 == F_9 ( V_46 ) )
V_6 -> V_47 = F_7 ( V_7 [ V_14 ] . V_48 ) ;
break;
case V_49 :
break;
case V_50 :
case V_51 :
V_10 = NULL ;
break;
default:
break;
}
V_8 = (struct V_8 * ) & V_8 -> V_9 [ V_13 ] ;
}
if ( V_12 ) {
F_4 ( V_6 -> V_25 -> V_26 ,
L_5 ,
V_12 , V_6 -> V_47 >> 8 , V_6 -> V_47 & 0xff ) ;
snprintf ( V_2 -> V_26 -> V_12 , sizeof( V_2 -> V_26 -> V_12 ) ,
L_6 , V_12 ,
V_6 -> V_47 >> 8 , V_6 -> V_47 & 0xff ) ;
}
if ( V_6 -> V_47 < 0x500 )
F_4 ( V_6 -> V_25 -> V_26 ,
L_7
L_8
L_9 ) ;
if ( V_6 -> V_47 >= 0x300 ) {
if ( V_6 -> V_47 >= 0x500 ) {
V_6 -> V_52 [ V_53 ] . V_54 = 16 ;
V_6 -> V_52 [ V_55 ] . V_54 = 16 ;
V_6 -> V_52 [ V_56 ] . V_54 = 16 ;
V_6 -> V_52 [ V_57 ] . V_54 = 16 ;
} else {
V_6 -> V_52 [ V_53 ] . V_54 = 3 ;
V_6 -> V_52 [ V_55 ] . V_54 = 4 ;
V_6 -> V_52 [ V_56 ] . V_54 = 3 ;
V_6 -> V_52 [ V_57 ] . V_54 = 2 ;
}
V_6 -> V_25 -> V_58 = V_59 ;
}
F_4 ( V_6 -> V_25 -> V_26 ,
L_10 ,
( V_6 -> V_36 & V_60 ) ? L_11 : L_12 ,
( V_6 -> V_36 &
( V_61 | V_62 ) )
? L_11 : L_12 ,
( V_6 -> V_36 & V_63 )
? L_11 : L_12 ) ;
if ( V_6 -> V_37 ) {
V_6 -> V_64 = F_10 ( F_11 (
V_6 -> V_37 ) , V_65 ) ;
if ( ! V_6 -> V_64 )
return - V_66 ;
}
return 0 ;
}
static struct V_67 * F_12 ( struct V_5 * V_6 , T_4 V_68 ,
T_4 V_69 , T_4 type , T_5 V_70 )
{
struct V_71 * V_72 ;
struct V_67 * V_73 ;
T_3 V_74 = sizeof( * V_72 ) + V_69 ;
if ( V_74 > V_75 )
return NULL ;
if ( F_13 ( F_14 ( & V_6 -> V_76 ) > 64 ) )
return NULL ;
V_73 = F_15 ( V_6 -> V_39 + V_74 , V_70 ) ;
if ( ! V_73 )
return NULL ;
F_16 ( V_73 , V_6 -> V_39 ) ;
V_72 = (struct V_71 * ) F_17 ( V_73 , sizeof( * V_72 ) ) ;
V_72 -> V_77 = F_9 ( V_68 ) ;
V_72 -> V_13 = F_9 ( V_69 ) ;
V_72 -> type = F_9 ( type ) ;
V_72 -> V_78 = V_72 -> V_79 = 0 ;
return V_73 ;
}
int F_18 ( struct V_5 * V_6 , void * V_80 ,
T_4 V_81 , T_4 V_13 )
{
struct V_82 * V_83 ;
struct V_67 * V_73 ;
T_3 V_84 ;
int V_85 = 0 ;
long V_86 ;
if ( V_6 -> V_47 >= 0x509 )
V_84 = sizeof( * V_83 ) ;
else
V_84 = 0x4 ;
V_73 = F_12 ( V_6 , V_87 , V_84 +
V_13 , V_88 ,
V_65 ) ;
if ( F_13 ( ! V_73 ) )
return - V_66 ;
F_19 ( & V_6 -> V_89 ) ;
V_6 -> V_90 = V_80 ;
V_83 = (struct V_82 * ) F_17 ( V_73 ,
V_84 + V_13 ) ;
if ( V_6 -> V_47 < 0x509 ) {
V_83 -> V_91 . V_81 = F_9 ( V_81 ) ;
V_83 -> V_91 . V_13 = F_9 ( V_13 ) ;
} else {
V_83 -> V_92 . V_81 = F_20 ( V_81 ) ;
V_83 -> V_92 . V_13 = F_9 ( V_13 ) ;
V_83 -> V_92 . V_93 = 0xf ;
memcpy ( V_83 -> V_92 . V_94 , ( const char * ) L_13 , 4 ) ;
}
F_21 ( V_6 , V_73 ) ;
V_86 = F_22 (
& V_6 -> V_95 , V_96 ) ;
if ( V_86 <= 0 ) {
F_5 ( V_6 -> V_25 -> V_26 ,
L_14 ) ;
V_85 = - V_97 ;
}
V_6 -> V_90 = NULL ;
F_23 ( & V_6 -> V_89 ) ;
return V_85 ;
}
int F_24 ( struct V_5 * V_6 , T_4 V_98 , bool V_99 )
{
struct V_67 * V_73 ;
struct V_100 * V_101 ;
V_73 = F_12 ( V_6 , V_102 , sizeof( * V_101 ) ,
V_103 , V_104 ) ;
if ( F_13 ( ! V_73 ) )
return - V_66 ;
V_101 = (struct V_100 * ) F_17 ( V_73 , sizeof( * V_101 ) ) ;
V_101 -> V_105 = 1 ;
V_101 -> V_106 [ 0 ] = F_9 ( V_99 ? ( V_98 | 0x8000 ) : V_98 ) ;
F_21 ( V_6 , V_73 ) ;
return 0 ;
}
int F_25 ( struct V_5 * V_6 , T_2 * V_107 )
{
struct V_67 * V_73 ;
struct F_25 * V_108 ;
V_73 = F_12 ( V_6 , V_102 , sizeof( * V_108 ) ,
V_109 , V_104 ) ;
if ( F_13 ( ! V_73 ) )
return - V_66 ;
V_108 = (struct F_25 * ) F_17 ( V_73 , sizeof( * V_108 ) ) ;
memcpy ( V_108 -> V_107 , V_107 , V_110 ) ;
F_21 ( V_6 , V_73 ) ;
return 0 ;
}
int F_26 ( struct V_5 * V_6 , T_6 V_111 )
{
struct V_67 * V_73 ;
struct V_112 * V_113 ;
T_1 V_114 = F_2 ( V_111 ) ;
if ( F_13 ( V_114 < V_6 -> V_16 || V_114 > V_6 -> V_33 ) )
return - V_115 ;
V_73 = F_12 ( V_6 , V_102 , sizeof( * V_113 ) ,
V_116 , V_104 ) ;
if ( F_13 ( ! V_73 ) )
return - V_66 ;
V_113 = (struct V_112 * ) F_17 ( V_73 , sizeof( * V_113 ) ) ;
V_113 -> V_111 = V_111 ;
F_21 ( V_6 , V_73 ) ;
return 0 ;
}
int F_27 ( struct V_5 * V_6 )
{
struct V_67 * V_73 ;
struct F_27 * V_117 ;
T_4 V_118 ;
V_73 = F_12 ( V_6 , V_102 , sizeof( * V_117 ) ,
V_119 , V_104 ) ;
if ( ! V_73 )
return - V_66 ;
V_117 = (struct F_27 * ) F_17 ( V_73 , sizeof( * V_117 ) ) ;
if ( ! ( V_6 -> V_25 -> V_120 . V_77 & V_121 ) ) {
switch ( V_6 -> V_118 ) {
case V_122 :
V_118 = V_123 ;
break;
case V_124 :
V_118 = V_125 ;
break;
case V_126 :
case V_127 :
V_118 = V_128 ;
break;
case V_129 :
V_118 = V_130 ;
break;
default:
V_118 = V_131 ;
break;
}
if ( V_6 -> V_132 & V_133 &&
( V_118 != V_130 ) )
V_118 |= V_134 ;
} else {
V_118 = V_131 ;
}
V_117 -> V_135 = F_9 ( V_118 ) ;
memcpy ( V_117 -> V_136 , V_6 -> V_136 , V_110 ) ;
memcpy ( V_117 -> V_137 , V_6 -> V_137 , V_110 ) ;
V_117 -> V_138 = 2 & V_6 -> V_139 ;
V_117 -> V_140 = 0 ;
if ( V_6 -> V_47 < 0x500 ) {
V_117 -> V_91 . V_141 = F_20 ( V_6 -> V_141 ) ;
memset ( V_117 -> V_91 . V_142 , 0 , 8 ) ;
V_117 -> V_91 . V_143 = F_20 ( V_6 -> V_33 ) ;
V_117 -> V_91 . V_144 = F_9 ( V_6 -> V_38 ) ;
V_117 -> V_91 . V_145 = F_9 ( V_6 -> V_145 ) ;
V_117 -> V_91 . V_146 = F_9 ( V_6 -> V_146 ) ;
V_117 -> V_91 . V_147 = F_9 ( 0 ) ;
} else {
V_117 -> V_92 . V_143 = F_20 ( V_6 -> V_33 ) ;
V_117 -> V_92 . V_144 = F_9 ( V_6 -> V_38 ) ;
V_117 -> V_92 . V_145 = F_9 ( V_6 -> V_145 ) ;
V_117 -> V_92 . V_148 = F_9 ( V_6 -> V_146 ) ;
V_117 -> V_92 . V_149 = F_9 ( 48896 ) ;
V_117 -> V_92 . V_141 = F_20 ( V_6 -> V_141 ) ;
V_117 -> V_92 . V_150 = 0 ;
V_117 -> V_92 . V_151 = 0 ;
V_117 -> V_92 . V_152 = 0 ;
V_117 -> V_92 . V_153 = 0 ;
V_117 -> V_92 . V_154 = F_20 ( 644245094 ) ;
V_117 -> V_92 . V_155 = F_9 ( 65535 ) ;
V_117 -> V_92 . V_156 = F_9 ( 65535 ) ;
}
F_21 ( V_6 , V_73 ) ;
V_6 -> V_157 = V_118 == V_131 ;
return 0 ;
}
int F_28 ( struct V_5 * V_6 , T_4 V_118 , T_4 V_158 )
{
struct V_67 * V_73 ;
struct V_71 * V_72 ;
struct V_159 * V_160 ;
struct V_161 * V_162 ;
union V_163 * V_164 ;
struct V_165 * V_166 ;
struct V_167 * V_168 ;
struct V_169 * V_170 ;
unsigned int V_14 ;
void * V_106 ;
T_7 V_171 = F_9 ( V_6 -> V_25 -> V_120 . V_172 . V_173 -> V_174 ) ;
V_73 = F_12 ( V_6 , V_102 , sizeof( * V_160 ) +
2 + sizeof( * V_162 ) + sizeof( * V_164 ) +
sizeof( * V_166 ) + 2 * sizeof( * V_168 ) ,
V_175 , V_104 ) ;
if ( ! V_73 )
return - V_66 ;
V_160 = (struct V_159 * ) F_17 ( V_73 , sizeof( * V_160 ) ) ;
memset ( V_160 -> V_176 , 0 , sizeof( V_160 -> V_176 ) ) ;
V_160 -> V_118 = F_9 ( V_118 ) ;
V_160 -> V_158 = F_9 ( V_158 ) ;
V_160 -> V_171 = V_171 ;
if ( V_6 -> V_145 == V_177 ) {
T_7 * V_178 = ( T_7 * ) F_17 ( V_73 , 2 ) ;
* V_178 = F_9 ( 0x0c ) ;
}
V_162 = ( void * ) F_17 ( V_73 , sizeof( * V_162 ) ) ;
for ( V_14 = 0 ; V_14 < V_6 -> V_179 ; V_14 ++ ) {
if ( V_6 -> V_162 [ V_14 ] . V_171 != V_171 )
continue;
memcpy ( V_162 , & V_6 -> V_162 [ V_14 ] . V_180 ,
sizeof( struct V_161 ) ) ;
break;
}
if ( V_14 == V_6 -> V_179 )
goto V_181;
if ( V_6 -> V_145 == V_177 )
V_164 = ( void * ) F_17 ( V_73 , sizeof( V_164 -> V_182 ) ) ;
else
V_164 = ( void * ) F_17 ( V_73 , sizeof( V_164 -> V_183 ) ) ;
for ( V_14 = 0 ; V_14 < V_6 -> V_184 -> V_185 ; V_14 ++ ) {
T_7 * V_186 = ( void * ) ( V_6 -> V_184 -> V_9 +
V_6 -> V_184 -> V_187 * V_14 ) ;
if ( * V_186 != V_171 )
continue;
if ( V_6 -> V_145 == V_177 ) {
memcpy ( & V_164 -> V_182 . V_188 ,
( void * ) V_186 + sizeof( T_7 ) ,
V_6 -> V_184 -> V_187 ) ;
} else {
struct V_189 * V_190 =
( void * ) V_186 ;
V_164 -> V_183 . V_191 = 0x38 ;
V_164 -> V_183 . V_192 = V_164 -> V_183 . V_193 =
V_190 -> V_192 ;
V_164 -> V_183 . V_194 = V_164 -> V_183 . V_195 =
V_190 -> V_194 ;
V_164 -> V_183 . V_196 = V_164 -> V_183 . V_197 =
V_190 -> V_196 ;
V_164 -> V_183 . V_198 = V_164 -> V_183 . V_199 =
V_190 -> V_198 ;
}
break;
}
if ( V_14 == V_6 -> V_184 -> V_185 )
goto V_181;
V_106 = ( void * ) ( V_6 -> V_200 -> V_9 + V_6 -> V_200 -> V_81 ) ;
for ( V_14 = 0 ; V_14 < V_6 -> V_200 -> V_185 ; V_14 ++ ) {
if ( * ( ( T_7 * ) V_106 ) != V_171 ) {
V_106 += V_6 -> V_200 -> V_187 ;
continue;
}
if ( V_6 -> V_145 == V_177 ) {
memcpy ( & V_164 -> V_182 . V_200 ,
V_106 + sizeof( T_7 ) ,
V_6 -> V_200 -> V_187 ) ;
} else {
struct V_201 * V_173 = & V_164 -> V_183 ;
struct V_202 * V_200 =
( void * ) V_6 -> V_200 -> V_9 ;
V_106 += sizeof( T_7 ) ;
V_173 -> V_203 = 8 ;
memset ( V_173 -> V_200 , 0 , sizeof( V_173 -> V_200 ) ) ;
memcpy ( V_173 -> V_200 , V_106 ,
sizeof( struct V_204 ) *
F_29 ( ( T_2 ) 8 , V_200 -> V_205 ) ) ;
}
break;
}
if ( V_14 == V_6 -> V_200 -> V_185 )
goto V_181;
if ( ( V_6 -> V_47 >= 0x500 ) && ( V_6 -> V_47 < 0x509 ) ) {
V_166 = ( void * ) F_17 ( V_73 , sizeof( * V_166 ) ) ;
V_166 -> V_141 = F_20 ( V_6 -> V_141 ) ;
for ( V_14 = 0 ; V_14 < sizeof( V_166 -> V_142 ) ; V_14 ++ )
V_166 -> V_142 [ V_14 ] = V_14 ;
}
V_168 = (struct V_167 * ) F_17 ( V_73 , sizeof( * V_168 ) ) ;
V_170 = F_30 ( V_6 , F_7 ( V_171 ) ) ;
V_168 -> V_206 = F_9 ( V_170 -> V_206 ) ;
V_168 -> V_207 = F_9 ( V_170 -> V_207 ) ;
if ( V_6 -> V_145 == V_177 ) {
V_168 = ( void * ) F_17 ( V_73 , sizeof( * V_168 ) ) ;
V_168 -> V_206 = F_9 ( V_170 -> V_208 ) ;
V_168 -> V_207 = F_9 ( V_170 -> V_209 ) ;
}
if ( V_6 -> V_47 >= 0x509 ) {
V_166 = ( void * ) F_17 ( V_73 , sizeof( * V_166 ) ) ;
V_166 -> V_141 = F_20 ( V_6 -> V_141 ) ;
for ( V_14 = 0 ; V_14 < sizeof( V_166 -> V_142 ) ; V_14 ++ )
V_166 -> V_142 [ V_14 ] = V_14 ;
}
V_72 = (struct V_71 * ) V_73 -> V_9 ;
V_72 -> V_13 = F_9 ( V_73 -> V_13 - sizeof( * V_72 ) ) ;
F_21 ( V_6 , V_73 ) ;
V_6 -> V_210 = V_170 ;
return 0 ;
V_181:
F_5 ( V_6 -> V_25 -> V_26 , L_15 ,
F_31 (
V_6 -> V_25 -> V_120 . V_172 . V_173 -> V_174 ) ) ;
F_32 ( V_73 ) ;
return - V_115 ;
}
int F_33 ( struct V_5 * V_6 )
{
struct V_67 * V_73 ;
struct V_211 * V_212 ;
V_73 = F_12 ( V_6 , V_102 , sizeof( * V_212 ) ,
V_213 , V_104 ) ;
if ( F_13 ( ! V_73 ) )
return - V_66 ;
V_212 = (struct V_211 * ) F_17 ( V_73 , sizeof( * V_212 ) ) ;
V_212 -> V_77 = F_9 ( 0x0003 ) ;
V_212 -> V_214 [ 0 ] = V_212 -> V_214 [ 1 ] = F_9 ( V_6 -> V_215 ) ;
V_212 -> V_216 [ 0 ] = F_9 ( 1 ) ;
V_212 -> V_216 [ 1 ] = F_9 ( 0 ) ;
F_21 ( V_6 , V_73 ) ;
return 0 ;
}
int F_34 ( struct V_5 * V_6 )
{
struct V_67 * V_73 ;
struct V_217 * V_218 ;
T_2 V_219 ;
V_73 = F_12 ( V_6 , V_102 , sizeof( * V_218 ) ,
V_220 , V_104 ) ;
if ( F_13 ( ! V_73 ) )
return - V_66 ;
V_218 = (struct V_217 * ) F_17 ( V_73 , sizeof( * V_218 ) ) ;
if ( V_6 -> V_221 ) {
V_218 -> V_222 = 9 ;
V_218 -> V_223 = 0x10 ;
V_218 -> V_224 = 0x00 ;
} else {
V_218 -> V_222 = 20 ;
V_218 -> V_223 = 0x0a ;
V_218 -> V_224 = 0x06 ;
}
V_219 = 3 * V_6 -> V_225 ;
V_218 -> V_222 += V_219 ;
V_218 -> V_226 = F_9 ( V_219 ) ;
V_218 -> V_227 = F_9 ( 0 ) ;
V_218 -> V_77 = 0 ;
memset ( V_218 -> V_228 , 0 , sizeof( V_218 -> V_228 ) ) ;
memcpy ( V_218 -> V_229 , V_6 -> V_230 , sizeof( V_218 -> V_229 ) ) ;
F_21 ( V_6 , V_73 ) ;
return 0 ;
}
int F_35 ( struct V_5 * V_6 )
{
struct V_67 * V_73 ;
struct V_231 * V_232 ;
unsigned int V_14 ;
T_4 V_118 ;
if ( V_6 -> V_25 -> V_120 . V_77 & V_233 &&
! V_6 -> V_234 )
V_118 = V_235 | V_236 | V_237 |
V_238 | V_239 ;
else
V_118 = V_240 ;
V_73 = F_12 ( V_6 , V_102 , sizeof( * V_232 ) ,
V_241 , V_104 ) ;
if ( ! V_73 )
return - V_66 ;
V_232 = (struct V_231 * ) F_17 ( V_73 , sizeof( * V_232 ) ) ;
V_232 -> V_118 = F_9 ( V_118 ) ;
V_232 -> V_98 = F_9 ( V_6 -> V_98 ) ;
for ( V_14 = 0 ; V_14 < F_36 ( V_232 -> V_242 ) ; V_14 ++ ) {
V_232 -> V_242 [ V_14 ] . V_243 =
F_9 ( V_6 -> V_25 -> V_120 . V_244 ) ;
V_232 -> V_242 [ V_14 ] . V_245 = F_9 ( 1 ) ;
}
V_232 -> V_246 = 200 ;
V_232 -> V_247 = 0 ;
V_232 -> V_248 = 1 ;
V_232 -> V_249 [ 0 ] = V_250 ;
F_21 ( V_6 , V_73 ) ;
V_6 -> V_251 = V_118 != V_240 ;
return 0 ;
}
int F_37 ( struct V_5 * V_6 )
{
struct V_67 * V_73 ;
struct V_252 * V_253 ;
V_73 = F_12 ( V_6 , V_102 , sizeof( * V_253 ) ,
V_254 , V_65 ) ;
if ( F_13 ( ! V_73 ) )
return - V_66 ;
V_253 = (struct V_252 * ) F_17 ( V_73 , sizeof( * V_253 ) ) ;
V_253 -> V_255 = F_9 ( 0x1 ) ;
V_253 -> V_93 = F_9 ( 0x2 ) ;
V_253 -> V_171 = F_9 ( 5390 ) ;
memset ( V_253 -> V_256 , 0 , sizeof( V_253 -> V_256 ) ) ;
F_21 ( V_6 , V_73 ) ;
return 0 ;
}
int F_38 ( struct V_5 * V_6 , T_2 V_257 , int V_258 , T_2 V_259 , T_2 V_13 ,
T_2 * V_107 , T_2 * V_260 )
{
struct V_67 * V_73 ;
struct V_261 * V_262 ;
V_73 = F_12 ( V_6 , V_102 , sizeof( * V_262 ) ,
V_263 , V_65 ) ;
if ( F_13 ( ! V_73 ) )
return - V_66 ;
V_262 = (struct V_261 * ) F_17 ( V_73 , sizeof( * V_262 ) ) ;
V_262 -> V_106 = V_258 ;
V_262 -> V_264 = V_259 ;
V_262 -> V_265 = V_257 ;
if ( V_107 )
memcpy ( V_262 -> V_266 , V_107 , V_110 ) ;
else
F_39 ( V_262 -> V_266 ) ;
switch ( V_257 ) {
case V_267 :
case V_268 :
V_262 -> V_269 = F_40 ( T_2 , 16 , V_13 ) ;
memcpy ( V_262 -> V_260 , V_260 , V_262 -> V_269 ) ;
break;
case V_270 :
V_262 -> V_269 = 24 ;
memcpy ( V_262 -> V_260 , V_260 , 16 ) ;
memcpy ( & ( V_262 -> V_260 [ 16 ] ) , & ( V_260
[ V_271 ] ) , 8 ) ;
break;
case V_272 :
V_262 -> V_269 = 0 ;
memset ( V_262 -> V_260 , 0 , sizeof( V_262 -> V_260 ) ) ;
break;
default:
F_5 ( V_6 -> V_25 -> V_26 ,
L_16 , V_257 ) ;
F_41 ( V_73 ) ;
return - V_115 ;
}
F_21 ( V_6 , V_73 ) ;
return 0 ;
}
int F_42 ( struct V_5 * V_6 )
{
struct V_273 * V_274 ;
struct V_275 * V_276 ;
struct V_67 * V_73 ;
V_73 = F_12 ( V_6 , V_87 ,
sizeof( struct V_277 ) ,
V_278 , V_65 ) ;
if ( ! V_73 )
return - V_66 ;
V_274 = F_43 ( V_73 ) ;
V_276 = ( void * ) V_274 -> V_279 ;
V_276 -> V_280 = sizeof( struct V_277 ) ;
F_21 ( V_6 , V_73 ) ;
return 0 ;
}
int F_44 ( struct V_5 * V_6 )
{
struct V_281 * V_282 ;
struct V_67 * V_73 ;
bool V_283 = false ;
V_73 = F_12 ( V_6 , V_102 , sizeof( * V_282 ) ,
V_284 , V_65 ) ;
if ( ! V_73 )
return - V_66 ;
V_282 = (struct V_281 * ) F_17 ( V_73 , sizeof( * V_282 ) ) ;
V_283 = ! ( V_6 -> V_132 & V_285 ) &&
( V_6 -> V_286 > 0 &&
V_6 -> V_286 <= V_287 ) ;
if ( V_283 ) {
V_282 -> V_288 = F_9 ( 1 ) ;
V_282 -> V_289 = F_9 ( V_6 -> V_286 ) ;
memcpy ( V_282 -> V_290 , V_6 -> V_291 , sizeof( V_282 -> V_290 ) ) ;
} else {
V_282 -> V_288 = F_9 ( 0 ) ;
V_282 -> V_289 = F_9 ( 0 ) ;
memset ( V_282 -> V_290 , 0 , sizeof( V_282 -> V_290 ) ) ;
}
F_21 ( V_6 , V_73 ) ;
return 0 ;
}
