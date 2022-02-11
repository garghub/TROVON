const char * F_1 ( T_1 V_1 )
{
T_2 V_2 = V_1 ;
int V_3 ;
F_2 ( V_2 != V_1 ) ;
for ( V_3 = 0 ; V_4 [ V_3 ] . V_5 ; V_3 ++ )
if ( V_2 == V_4 [ V_3 ] . V_5 )
break;
return V_4 [ V_3 ] . V_6 ;
}
void F_3 ( int V_1 , struct V_7 * V_8 )
{
if ( V_1 & V_9 ) {
V_8 -> V_10 = 1001 ;
V_8 -> V_11 = 30000 ;
} else {
V_8 -> V_10 = 1 ;
V_8 -> V_11 = 25 ;
}
}
int F_4 ( struct V_12 * V_13 ,
int V_1 , const char * V_14 )
{
V_13 -> V_1 = V_1 ;
F_3 ( V_1 , & V_13 -> V_8 ) ;
V_13 -> V_15 = ( V_1 & V_9 ) ? 525 : 625 ;
F_5 ( V_13 -> V_14 , V_14 , sizeof( V_13 -> V_14 ) ) ;
return 0 ;
}
static void F_6 ( const void * V_16 , bool V_17 )
{
const struct V_18 * V_19 = V_16 ;
F_7 ( L_1 ,
( int ) sizeof( V_19 -> V_20 ) , V_19 -> V_20 ,
( int ) sizeof( V_19 -> V_21 ) , V_19 -> V_21 ,
( int ) sizeof( V_19 -> V_22 ) , V_19 -> V_22 ,
V_19 -> V_23 , V_19 -> V_24 , V_19 -> V_25 ) ;
}
static void F_8 ( const void * V_16 , bool V_17 )
{
const struct V_26 * V_19 = V_16 ;
F_7 ( L_2 ,
V_19 -> V_27 , ( int ) sizeof( V_19 -> V_14 ) , V_19 -> V_14 , V_19 -> type , V_19 -> V_28 ,
V_19 -> V_29 , ( unsigned long long ) V_19 -> V_5 , V_19 -> V_30 ,
V_19 -> V_24 ) ;
}
static void F_9 ( const void * V_16 , bool V_17 )
{
const struct V_31 * V_19 = V_16 ;
F_7 ( L_3 ,
V_19 -> V_27 , ( int ) sizeof( V_19 -> V_14 ) , V_19 -> V_14 , V_19 -> type , V_19 -> V_28 ,
V_19 -> V_32 , ( unsigned long long ) V_19 -> V_5 , V_19 -> V_24 ) ;
}
static void F_10 ( const void * V_16 , bool V_17 )
{
const struct V_33 * V_19 = V_16 ;
if ( V_17 )
F_7 ( L_4 , V_19 -> V_27 , V_19 -> V_34 ) ;
else
F_7 ( L_5 ,
V_19 -> V_27 , ( int ) sizeof( V_19 -> V_14 ) , V_19 -> V_14 ,
V_19 -> V_35 , V_19 -> V_34 ) ;
}
static void F_11 ( const void * V_16 , bool V_17 )
{
const struct V_36 * V_19 = V_16 ;
if ( V_17 )
F_7 ( L_6 , V_19 -> V_27 ) ;
else
F_7 ( L_5 ,
V_19 -> V_27 , ( int ) sizeof( V_19 -> V_14 ) , V_19 -> V_14 ,
V_19 -> V_35 , V_19 -> V_34 ) ;
}
static void F_12 ( const void * V_16 , bool V_17 )
{
const struct V_37 * V_19 = V_16 ;
F_7 ( L_7 ,
V_19 -> V_27 , F_13 ( V_19 -> type , V_38 ) ,
V_19 -> V_39 , ( V_19 -> V_40 & 0xff ) ,
( V_19 -> V_40 >> 8 ) & 0xff ,
( V_19 -> V_40 >> 16 ) & 0xff ,
( V_19 -> V_40 >> 24 ) & 0xff ,
( int ) sizeof( V_19 -> V_41 ) , V_19 -> V_41 ) ;
}
static void F_14 ( const void * V_16 , bool V_17 )
{
const struct V_42 * V_19 = V_16 ;
const struct V_43 * V_44 ;
const struct V_45 * V_46 ;
const struct V_47 * V_48 ;
const struct V_49 * V_50 ;
const struct V_51 * V_52 ;
const struct V_53 * V_54 ;
const struct V_55 * V_56 ;
unsigned V_3 ;
F_7 ( L_8 , F_13 ( V_19 -> type , V_38 ) ) ;
switch ( V_19 -> type ) {
case V_57 :
case V_58 :
V_44 = & V_19 -> V_59 . V_44 ;
F_7 ( L_9 ,
V_44 -> V_60 , V_44 -> V_61 ,
( V_44 -> V_40 & 0xff ) ,
( V_44 -> V_40 >> 8 ) & 0xff ,
( V_44 -> V_40 >> 16 ) & 0xff ,
( V_44 -> V_40 >> 24 ) & 0xff ,
F_13 ( V_44 -> V_62 , V_63 ) ,
V_44 -> V_64 , V_44 -> V_65 ,
V_44 -> V_66 , V_44 -> V_39 , V_44 -> V_67 ,
V_44 -> V_68 , V_44 -> V_69 ) ;
break;
case V_70 :
case V_71 :
V_46 = & V_19 -> V_59 . V_72 ;
F_7 ( L_10 ,
V_46 -> V_60 , V_46 -> V_61 ,
( V_46 -> V_40 & 0xff ) ,
( V_46 -> V_40 >> 8 ) & 0xff ,
( V_46 -> V_40 >> 16 ) & 0xff ,
( V_46 -> V_40 >> 24 ) & 0xff ,
F_13 ( V_46 -> V_62 , V_63 ) ,
V_46 -> V_66 , V_46 -> V_73 , V_46 -> V_39 ,
V_46 -> V_67 , V_46 -> V_68 , V_46 -> V_69 ) ;
for ( V_3 = 0 ; V_3 < V_46 -> V_73 ; V_3 ++ )
F_15 ( V_74 L_11 , V_3 ,
V_46 -> V_75 [ V_3 ] . V_64 ,
V_46 -> V_75 [ V_3 ] . V_65 ) ;
break;
case V_76 :
case V_77 :
V_52 = & V_19 -> V_59 . V_52 ;
F_7 ( L_12 ,
V_52 -> V_78 . V_60 , V_52 -> V_78 . V_61 , V_52 -> V_78 . V_79 , V_52 -> V_78 . V_80 ,
F_13 ( V_52 -> V_62 , V_63 ) ,
V_52 -> V_81 , V_52 -> V_82 , V_52 -> V_83 ,
V_52 -> V_84 , V_52 -> V_85 ) ;
break;
case V_86 :
case V_87 :
V_48 = & V_19 -> V_59 . V_48 ;
F_7 ( L_13 ,
V_48 -> V_88 , V_48 -> V_89 ,
V_48 -> V_90 ,
( V_48 -> V_91 & 0xff ) ,
( V_48 -> V_91 >> 8 ) & 0xff ,
( V_48 -> V_91 >> 16 ) & 0xff ,
( V_48 -> V_91 >> 24 ) & 0xff ,
V_48 -> V_92 [ 0 ] , V_48 -> V_92 [ 1 ] ,
V_48 -> V_93 [ 0 ] , V_48 -> V_93 [ 1 ] ) ;
break;
case V_94 :
case V_95 :
V_50 = & V_19 -> V_59 . V_50 ;
F_7 ( L_14 ,
V_50 -> V_96 , V_50 -> V_97 ) ;
for ( V_3 = 0 ; V_3 < 24 ; V_3 ++ )
F_15 ( V_74 L_15 , V_3 ,
V_50 -> V_98 [ 0 ] [ V_3 ] ,
V_50 -> V_98 [ 1 ] [ V_3 ] ) ;
break;
case V_99 :
case V_100 :
V_54 = & V_19 -> V_59 . V_54 ;
F_7 ( L_16 ,
( V_54 -> V_40 >> 0 ) & 0xff ,
( V_54 -> V_40 >> 8 ) & 0xff ,
( V_54 -> V_40 >> 16 ) & 0xff ,
( V_54 -> V_40 >> 24 ) & 0xff ) ;
break;
case V_101 :
V_56 = & V_19 -> V_59 . V_56 ;
F_7 ( L_17 ,
( V_56 -> V_102 >> 0 ) & 0xff ,
( V_56 -> V_102 >> 8 ) & 0xff ,
( V_56 -> V_102 >> 16 ) & 0xff ,
( V_56 -> V_102 >> 24 ) & 0xff ,
V_56 -> V_103 ) ;
break;
}
}
static void F_16 ( const void * V_16 , bool V_17 )
{
const struct V_104 * V_19 = V_16 ;
F_7 ( L_18 ,
V_19 -> V_35 , V_19 -> V_39 , V_19 -> V_105 ,
V_19 -> V_59 . V_60 , V_19 -> V_59 . V_61 ,
( V_19 -> V_59 . V_40 & 0xff ) ,
( V_19 -> V_59 . V_40 >> 8 ) & 0xff ,
( V_19 -> V_59 . V_40 >> 16 ) & 0xff ,
( V_19 -> V_59 . V_40 >> 24 ) & 0xff ,
V_19 -> V_59 . V_64 , V_19 -> V_59 . V_65 ,
V_19 -> V_59 . V_66 ) ;
}
static void F_17 ( const void * V_16 , bool V_17 )
{
F_7 ( L_19 , F_13 ( * ( T_2 * ) V_16 , V_38 ) ) ;
}
static void F_18 ( const void * V_16 , bool V_17 )
{
const struct V_106 * V_19 = V_16 ;
if ( V_17 )
F_7 ( L_20 , V_19 -> V_27 , V_19 -> V_107 ) ;
else
F_7 ( L_21 ,
V_19 -> V_27 , ( int ) sizeof( V_19 -> V_14 ) , V_19 -> V_14 , V_19 -> V_35 ,
V_19 -> V_108 , V_19 -> V_109 , V_19 -> V_107 ) ;
}
static void F_19 ( const void * V_16 , bool V_17 )
{
const struct V_110 * V_19 = V_16 ;
if ( V_17 )
F_7 ( L_22 , V_19 -> V_27 , V_19 -> V_111 ) ;
else
F_7 ( L_23 ,
V_19 -> V_27 , ( int ) sizeof( V_19 -> V_14 ) , V_19 -> V_14 , V_19 -> type ,
V_19 -> V_35 , V_19 -> V_108 ,
V_19 -> V_109 , V_19 -> signal , V_19 -> V_112 ,
V_19 -> V_113 , V_19 -> V_111 ) ;
}
static void F_20 ( const void * V_16 , bool V_17 )
{
const struct V_114 * V_19 = V_16 ;
F_7 ( L_24 ,
V_19 -> V_29 , V_19 -> type , V_19 -> V_115 ) ;
}
static void F_21 ( const void * V_16 , bool V_17 )
{
const struct V_12 * V_19 = V_16 ;
F_7 ( L_25 ,
V_19 -> V_27 ,
( unsigned long long ) V_19 -> V_1 , ( int ) sizeof( V_19 -> V_14 ) , V_19 -> V_14 ,
V_19 -> V_8 . V_10 ,
V_19 -> V_8 . V_11 ,
V_19 -> V_15 ) ;
}
static void F_22 ( const void * V_16 , bool V_17 )
{
F_7 ( L_26 , * ( const long long unsigned * ) V_16 ) ;
}
static void F_23 ( const void * V_16 , bool V_17 )
{
const struct V_116 * V_19 = V_16 ;
F_7 ( L_27 ,
V_19 -> V_29 , V_19 -> type , V_19 -> V_117 , V_19 -> V_118 , V_19 -> V_119 ,
V_19 -> V_108 , V_19 -> V_109 ) ;
}
static void F_24 ( const void * V_16 , bool V_17 )
{
const struct V_120 * V_19 = V_16 ;
F_7 ( L_28 ,
V_19 -> V_93 ,
F_13 ( V_19 -> type , V_38 ) ,
F_13 ( V_19 -> V_121 , V_122 ) ) ;
}
static void F_25 ( const void * V_16 , bool V_17 )
{
const struct V_123 * V_19 = V_16 ;
const struct V_124 * V_125 = & V_19 -> V_126 ;
const struct V_127 * V_128 ;
int V_3 ;
F_7 ( L_29 ,
V_19 -> V_129 . V_130 / 3600 ,
( int ) ( V_19 -> V_129 . V_130 / 60 ) % 60 ,
( int ) ( V_19 -> V_129 . V_130 % 60 ) ,
( long ) V_19 -> V_129 . V_131 ,
V_19 -> V_27 ,
F_13 ( V_19 -> type , V_38 ) ,
V_19 -> V_39 , F_13 ( V_19 -> V_62 , V_63 ) ,
V_19 -> V_132 , F_13 ( V_19 -> V_121 , V_122 ) ) ;
if ( F_26 ( V_19 -> type ) && V_19 -> V_133 . V_134 ) {
F_7 ( L_30 ) ;
for ( V_3 = 0 ; V_3 < V_19 -> V_135 ; ++ V_3 ) {
V_128 = & V_19 -> V_133 . V_134 [ V_3 ] ;
F_15 ( V_74
L_31 ,
V_3 , V_128 -> V_136 , V_128 -> V_137 ,
V_128 -> V_133 . V_138 , V_128 -> V_135 ) ;
}
} else {
F_7 ( L_32 ,
V_19 -> V_136 , V_19 -> V_133 . V_138 , V_19 -> V_135 ) ;
}
F_15 ( V_74 L_33 ,
V_125 -> V_139 , V_125 -> V_140 , V_125 -> V_141 ,
V_125 -> type , V_125 -> V_39 , V_125 -> V_142 , * ( V_143 * ) V_125 -> V_144 ) ;
}
static void F_27 ( const void * V_16 , bool V_17 )
{
const struct V_145 * V_19 = V_16 ;
F_7 ( L_34 ,
V_19 -> V_146 , F_13 ( V_19 -> type , V_38 ) ,
V_19 -> V_27 , V_19 -> V_128 , V_19 -> V_39 ) ;
}
static void F_28 ( const void * V_16 , bool V_17 )
{
const struct V_147 * V_19 = V_16 ;
F_7 ( L_35 ,
V_19 -> V_27 , V_19 -> V_93 ,
F_13 ( V_19 -> V_121 , V_122 ) ) ;
F_14 ( & V_19 -> V_148 , V_17 ) ;
}
static void F_29 ( const void * V_16 , bool V_17 )
{
const struct V_149 * V_19 = V_16 ;
F_7 ( L_8 , F_13 ( V_19 -> type , V_38 ) ) ;
if ( V_19 -> type == V_57 ||
V_19 -> type == V_70 ) {
const struct V_150 * V_151 = & V_19 -> V_152 . V_153 ;
F_7 ( L_36 ,
V_151 -> V_35 , V_151 -> V_154 ,
V_151 -> V_155 . V_10 , V_151 -> V_155 . V_11 ,
V_151 -> V_156 , V_151 -> V_157 ) ;
} else if ( V_19 -> type == V_58 ||
V_19 -> type == V_71 ) {
const struct V_158 * V_151 = & V_19 -> V_152 . V_159 ;
F_7 ( L_37 ,
V_151 -> V_35 , V_151 -> V_160 ,
V_151 -> V_155 . V_10 , V_151 -> V_155 . V_11 ,
V_151 -> V_156 , V_151 -> V_161 ) ;
} else {
F_7 ( L_30 ) ;
}
}
static void F_30 ( const void * V_16 , bool V_17 )
{
const struct V_162 * V_19 = V_16 ;
F_7 ( L_38 ,
V_19 -> V_1 , V_19 -> type , ( int ) sizeof( V_19 -> V_14 ) , V_19 -> V_14 ,
V_19 -> V_163 , V_19 -> V_164 ,
V_19 -> V_165 , V_19 -> V_166 , V_19 -> V_39 ) ;
}
static void F_31 ( const void * V_16 , bool V_17 )
{
const struct V_167 * V_19 = V_16 ;
F_7 ( L_39 ,
V_19 -> V_1 , V_19 -> type , ( int ) sizeof( V_19 -> V_14 ) , V_19 -> V_14 ,
V_19 -> V_163 , V_19 -> V_164 ,
V_19 -> V_165 , V_19 -> V_166 , V_19 -> V_39 ,
V_19 -> V_168 , V_19 -> V_169 , V_19 -> V_170 ,
V_19 -> V_171 [ 0 ] , V_19 -> V_171 [ 1 ] , V_19 -> V_171 [ 2 ] , V_19 -> V_171 [ 3 ] ) ;
}
static void F_32 ( const void * V_16 , bool V_17 )
{
const struct V_172 * V_19 = V_16 ;
F_7 ( L_40 , V_19 -> V_1 , V_19 -> V_27 ) ;
}
static void F_33 ( const void * V_16 , bool V_17 )
{
const struct V_173 * V_19 = V_16 ;
F_7 ( L_41 , V_19 -> V_1 , V_19 -> V_174 ) ;
}
static void F_34 ( const void * V_16 , bool V_17 )
{
const struct V_175 * V_19 = V_16 ;
int V_3 ;
F_7 ( L_42 ,
V_19 -> V_176 , V_19 -> V_93 , V_19 -> V_177 ) ;
for ( V_3 = 0 ; V_3 < V_19 -> V_93 ; V_3 ++ ) {
if ( ! V_19 -> V_178 [ V_3 ] . V_179 )
F_7 ( L_43 ,
V_19 -> V_178 [ V_3 ] . V_1 , V_19 -> V_178 [ V_3 ] . V_174 ) ;
else
F_7 ( L_44 ,
V_19 -> V_178 [ V_3 ] . V_1 , V_19 -> V_178 [ V_3 ] . V_179 ) ;
}
F_7 ( L_30 ) ;
}
static void F_35 ( const void * V_16 , bool V_17 )
{
const struct V_180 * V_19 = V_16 ;
F_7 ( L_45 ,
F_13 ( V_19 -> type , V_38 ) ,
V_19 -> V_181 . V_60 , V_19 -> V_181 . V_61 ,
V_19 -> V_181 . V_79 , V_19 -> V_181 . V_80 ,
V_19 -> V_182 . V_60 , V_19 -> V_182 . V_61 ,
V_19 -> V_182 . V_79 , V_19 -> V_182 . V_80 ,
V_19 -> V_183 . V_10 , V_19 -> V_183 . V_11 ) ;
}
static void F_36 ( const void * V_16 , bool V_17 )
{
const struct V_184 * V_19 = V_16 ;
F_7 ( L_46 ,
F_13 ( V_19 -> type , V_38 ) ,
V_19 -> V_151 . V_60 , V_19 -> V_151 . V_61 ,
V_19 -> V_151 . V_79 , V_19 -> V_151 . V_80 ) ;
}
static void F_37 ( const void * V_16 , bool V_17 )
{
const struct V_185 * V_19 = V_16 ;
F_7 ( L_47 ,
F_13 ( V_19 -> type , V_38 ) ,
V_19 -> V_186 , V_19 -> V_39 ,
V_19 -> V_187 . V_60 , V_19 -> V_187 . V_61 , V_19 -> V_187 . V_79 , V_19 -> V_187 . V_80 ) ;
}
static void F_38 ( const void * V_16 , bool V_17 )
{
const struct V_188 * V_19 = V_16 ;
F_7 ( L_48 ,
V_19 -> V_189 , V_19 -> V_190 , V_19 -> V_191 ,
V_19 -> V_192 , V_19 -> V_193 ) ;
}
static void F_39 ( const void * V_16 , bool V_17 )
{
const struct V_194 * V_19 = V_16 ;
F_7 ( L_49 ,
V_19 -> V_195 , V_19 -> V_196 ) ;
}
static void F_40 ( const void * V_16 , bool V_17 )
{
const struct V_197 * V_19 = V_16 ;
F_7 ( L_50 ,
V_19 -> V_198 , V_19 -> V_39 ) ;
}
static void F_41 ( const void * V_16 , bool V_17 )
{
const struct V_199 * V_19 = V_16 ;
F_7 ( L_50 , V_19 -> V_198 , V_19 -> V_39 ) ;
if ( V_19 -> V_198 == V_200 )
F_42 ( L_51 ,
V_19 -> V_92 . V_201 , V_19 -> V_92 . V_148 ) ;
else if ( V_19 -> V_198 == V_202 )
F_42 ( L_52 , V_19 -> V_203 . V_204 ) ;
}
static void F_43 ( const void * V_16 , bool V_17 )
{
const struct V_205 * V_19 = V_16 ;
F_7 ( L_53 , V_19 -> V_206 . type ) ;
if ( V_19 -> V_206 . type == V_207 )
F_7 ( L_54 ,
( int ) sizeof( V_19 -> V_206 . V_14 ) , V_19 -> V_206 . V_14 ) ;
else
F_7 ( L_55 , V_19 -> V_206 . V_208 ) ;
F_7 ( L_56 , ( int ) sizeof( V_19 -> V_14 ) , V_19 -> V_14 ) ;
}
static void F_44 ( const void * V_16 , bool V_17 )
{
const struct V_209 * V_19 = V_16 ;
F_7 ( L_53 , V_19 -> V_206 . type ) ;
if ( V_19 -> V_206 . type == V_207 )
F_7 ( L_54 ,
( int ) sizeof( V_19 -> V_206 . V_14 ) , V_19 -> V_206 . V_14 ) ;
else
F_7 ( L_55 , V_19 -> V_206 . V_208 ) ;
F_7 ( L_57 ,
V_19 -> V_210 , V_19 -> V_211 ) ;
}
static void F_45 ( const void * V_16 , bool V_17 )
{
const struct V_212 * V_19 = V_16 ;
switch ( V_19 -> type ) {
case V_213 :
F_7 ( L_58 ,
V_19 -> V_214 . V_215 , V_19 -> V_214 . V_216 ,
V_19 -> V_214 . V_60 , V_19 -> V_214 . V_61 ,
V_19 -> V_214 . V_217 , V_19 -> V_214 . V_218 ,
V_19 -> V_214 . V_219 , V_19 -> V_214 . V_220 ,
V_19 -> V_214 . V_221 , V_19 -> V_214 . V_222 ,
V_19 -> V_214 . V_223 , V_19 -> V_214 . V_224 ,
V_19 -> V_214 . V_225 , V_19 -> V_214 . V_226 ,
V_19 -> V_214 . V_4 , V_19 -> V_214 . V_39 ) ;
break;
default:
F_7 ( L_59 , V_19 -> type ) ;
break;
}
}
static void F_46 ( const void * V_16 , bool V_17 )
{
const struct V_227 * V_19 = V_16 ;
F_7 ( L_60 , V_19 -> V_27 ) ;
F_45 ( & V_19 -> V_228 , V_17 ) ;
}
static void F_47 ( const void * V_16 , bool V_17 )
{
const struct V_229 * V_19 = V_16 ;
switch ( V_19 -> type ) {
case V_213 :
F_7 ( L_61 ,
V_19 -> V_214 . V_230 , V_19 -> V_214 . V_231 ,
V_19 -> V_214 . V_232 , V_19 -> V_214 . V_233 ,
V_19 -> V_214 . V_234 , V_19 -> V_214 . V_235 ,
V_19 -> V_214 . V_4 , V_19 -> V_214 . V_24 ) ;
break;
default:
F_7 ( L_62 , V_19 -> type ) ;
break;
}
}
static void F_48 ( const void * V_16 , bool V_17 )
{
const struct V_236 * V_19 = V_16 ;
F_7 ( L_63 ,
V_19 -> V_27 ,
( V_19 -> V_237 & 0xff ) ,
( V_19 -> V_237 >> 8 ) & 0xff ,
( V_19 -> V_237 >> 16 ) & 0xff ,
( V_19 -> V_237 >> 24 ) & 0xff ,
V_19 -> type ) ;
switch ( V_19 -> type ) {
case V_238 :
F_7 ( L_64 ,
V_19 -> V_239 . V_60 , V_19 -> V_239 . V_61 ) ;
break;
case V_240 :
F_7 ( L_65 ,
V_19 -> V_241 . V_230 , V_19 -> V_241 . V_232 ,
V_19 -> V_241 . V_242 , V_19 -> V_241 . V_243 ,
V_19 -> V_241 . V_231 , V_19 -> V_241 . V_233 ) ;
break;
case V_244 :
default:
F_7 ( L_30 ) ;
break;
}
}
static void F_49 ( const void * V_16 , bool V_17 )
{
const struct V_245 * V_19 = V_16 ;
F_7 ( L_66 ,
V_19 -> V_27 ,
( V_19 -> V_237 & 0xff ) ,
( V_19 -> V_237 >> 8 ) & 0xff ,
( V_19 -> V_237 >> 16 ) & 0xff ,
( V_19 -> V_237 >> 24 ) & 0xff ,
V_19 -> V_60 , V_19 -> V_61 , V_19 -> type ) ;
switch ( V_19 -> type ) {
case V_246 :
F_7 ( L_67 ,
V_19 -> V_239 . V_10 ,
V_19 -> V_239 . V_11 ) ;
break;
case V_247 :
F_7 ( L_68 ,
V_19 -> V_241 . V_248 . V_10 ,
V_19 -> V_241 . V_248 . V_11 ,
V_19 -> V_241 . V_249 . V_10 ,
V_19 -> V_241 . V_249 . V_11 ,
V_19 -> V_241 . V_165 . V_10 ,
V_19 -> V_241 . V_165 . V_11 ) ;
break;
case V_250 :
default:
F_7 ( L_30 ) ;
break;
}
}
static void F_50 ( const void * V_16 , bool V_17 )
{
const struct V_251 * V_19 = V_16 ;
const struct V_252 * V_151 ;
F_7 ( L_69 ,
V_19 -> type , V_19 -> V_253 , V_19 -> V_132 , V_19 -> V_1 ,
V_19 -> V_129 . V_130 , V_19 -> V_129 . V_254 ) ;
switch ( V_19 -> type ) {
case V_255 :
F_15 ( V_74 L_70 ,
F_13 ( V_19 -> V_256 . V_222 . V_62 , V_63 ) ) ;
break;
case V_257 :
V_151 = & V_19 -> V_256 . V_258 ;
F_15 ( V_74 L_71 ,
V_151 -> V_259 , V_151 -> type ) ;
if ( V_151 -> type == V_260 )
F_7 ( L_72 , V_151 -> V_261 ) ;
else
F_7 ( L_73 , V_151 -> V_174 ) ;
F_7 ( L_74 ,
V_151 -> V_39 , V_151 -> V_163 , V_151 -> V_164 ,
V_151 -> V_165 , V_151 -> V_166 ) ;
break;
case V_262 :
F_7 ( L_75 ,
V_19 -> V_256 . V_263 . V_264 ) ;
break;
}
}
static void F_51 ( const void * V_16 , bool V_17 )
{
const struct V_265 * V_19 = V_16 ;
F_7 ( L_76 ,
V_19 -> type , V_19 -> V_1 , V_19 -> V_39 ) ;
}
static void F_52 ( const void * V_16 , bool V_17 )
{
const struct V_266 * V_19 = V_16 ;
int V_3 ;
F_7 ( L_77 ,
F_13 ( V_19 -> type , V_38 ) , V_19 -> V_96 ) ;
for ( V_3 = 0 ; V_3 < 24 ; V_3 ++ )
F_15 ( V_74 L_15 , V_3 ,
V_19 -> V_98 [ 0 ] [ V_3 ] ,
V_19 -> V_98 [ 1 ] [ V_3 ] ) ;
}
static void F_53 ( const void * V_16 , bool V_17 )
{
const struct V_267 * V_19 = V_16 ;
F_7 ( L_78 ,
V_19 -> V_29 , V_19 -> type , V_19 -> V_27 ,
V_19 -> V_35 , V_19 -> V_108 ,
V_19 -> V_109 , V_19 -> V_268 ) ;
}
static void F_54 ( const void * V_16 , bool V_17 )
{
const struct V_269 * V_19 = V_16 ;
F_7 ( L_79 ,
V_19 -> V_270 , V_19 -> V_271 , V_19 -> V_272 ) ;
}
static void F_55 ( const void * V_16 , bool V_17 )
{
F_7 ( L_80 , * ( const T_2 * ) V_16 ) ;
}
static void F_56 ( const void * V_16 , bool V_17 )
{
F_7 ( L_30 ) ;
}
static void F_57 ( const void * V_16 , bool V_17 )
{
F_7 ( L_81 ) ;
}
static int F_58 ( struct V_175 * V_151 , int V_273 )
{
V_143 V_3 ;
V_151 -> V_274 [ 0 ] = V_151 -> V_274 [ 1 ] = 0 ;
for ( V_3 = 0 ; V_3 < V_151 -> V_93 ; V_3 ++ )
V_151 -> V_178 [ V_3 ] . V_275 [ 0 ] = 0 ;
if ( ! V_273 && V_151 -> V_176 == V_276 )
return 0 ;
if ( ! V_151 -> V_176 )
return 1 ;
for ( V_3 = 0 ; V_3 < V_151 -> V_93 ; V_3 ++ ) {
if ( F_59 ( V_151 -> V_178 [ V_3 ] . V_1 ) != V_151 -> V_176 ) {
V_151 -> V_177 = V_3 ;
return 0 ;
}
}
return 1 ;
}
static int F_60 ( struct V_277 * V_277 , enum V_278 type )
{
struct V_279 * V_280 = F_61 ( V_277 ) ;
const struct V_281 * V_282 = V_280 -> V_283 ;
bool V_284 = V_280 -> V_285 == V_286 ;
bool V_287 = V_280 -> V_285 == V_288 ;
bool V_289 = V_280 -> V_285 == V_290 ;
bool V_291 = V_280 -> V_285 == V_292 ;
bool V_293 = V_280 -> V_294 != V_295 ;
bool V_296 = V_280 -> V_294 != V_297 ;
if ( V_282 == NULL )
return - V_298 ;
switch ( type ) {
case V_57 :
if ( ( V_284 || V_291 ) && V_293 &&
( V_282 -> V_299 || V_282 -> V_300 ) )
return 0 ;
break;
case V_70 :
if ( V_284 && V_293 && V_282 -> V_300 )
return 0 ;
break;
case V_76 :
if ( V_284 && V_293 && V_282 -> V_301 )
return 0 ;
break;
case V_58 :
if ( V_284 && V_296 &&
( V_282 -> V_302 || V_282 -> V_303 ) )
return 0 ;
break;
case V_71 :
if ( V_284 && V_296 && V_282 -> V_303 )
return 0 ;
break;
case V_77 :
if ( V_284 && V_296 && V_282 -> V_304 )
return 0 ;
break;
case V_86 :
if ( V_287 && V_293 && V_282 -> V_305 )
return 0 ;
break;
case V_87 :
if ( V_287 && V_296 && V_282 -> V_306 )
return 0 ;
break;
case V_94 :
if ( V_287 && V_293 && V_282 -> V_307 )
return 0 ;
break;
case V_95 :
if ( V_287 && V_296 && V_282 -> V_308 )
return 0 ;
break;
case V_99 :
if ( V_289 && V_293 && V_282 -> V_309 )
return 0 ;
break;
case V_100 :
if ( V_289 && V_296 && V_282 -> V_310 )
return 0 ;
break;
case V_101 :
if ( V_284 && V_293 && V_282 -> V_311 )
return 0 ;
break;
default:
break;
}
return - V_298 ;
}
static void F_62 ( struct V_42 * V_59 )
{
unsigned int V_89 ;
if ( V_59 -> type != V_57 &&
V_59 -> type != V_58 )
return;
if ( V_59 -> V_59 . V_44 . V_312 == V_313 )
return;
V_59 -> V_59 . V_44 . V_312 = V_313 ;
V_89 = F_63 ( struct V_43 , V_312 )
+ sizeof( V_59 -> V_59 . V_44 . V_312 ) ;
memset ( ( ( void * ) & V_59 -> V_59 . V_44 ) + V_89 , 0 ,
sizeof( V_59 -> V_59 . V_44 ) - V_89 ) ;
}
static int F_64 ( const struct V_281 * V_282 ,
struct V_277 * V_277 , void * V_314 , void * V_16 )
{
struct V_18 * V_315 = (struct V_18 * ) V_16 ;
struct V_279 * V_280 = F_61 ( V_277 ) ;
int V_316 ;
V_315 -> V_23 = V_317 ;
V_315 -> V_25 = V_280 -> V_25 ;
V_315 -> V_24 = V_280 -> V_25 | V_318 ;
V_316 = V_282 -> V_319 ( V_277 , V_314 , V_315 ) ;
V_315 -> V_24 |= V_320 ;
F_65 ( ! ( V_315 -> V_24 & V_318 ) ||
! V_315 -> V_25 , L_82 ,
V_315 -> V_20 , V_315 -> V_24 , V_315 -> V_25 ) ;
V_315 -> V_25 |= V_320 ;
return V_316 ;
}
static int F_66 ( const struct V_281 * V_282 ,
struct V_277 * V_277 , void * V_314 , void * V_16 )
{
struct V_279 * V_280 = F_61 ( V_277 ) ;
int V_316 ;
V_316 = F_67 ( V_280 ) ;
if ( V_316 )
return V_316 ;
return V_282 -> V_321 ( V_277 , V_314 , * ( unsigned int * ) V_16 ) ;
}
static int F_68 ( const struct V_281 * V_282 ,
struct V_277 * V_277 , void * V_314 , void * V_16 )
{
return V_282 -> V_322 ( V_277 , V_314 , * ( unsigned int * ) V_16 ) ;
}
static int F_69 ( const struct V_281 * V_282 ,
struct V_277 * V_277 , void * V_314 , void * V_16 )
{
struct V_279 * V_280 ;
T_2 * V_19 = V_16 ;
V_280 = F_61 ( V_277 ) ;
* V_19 = F_70 ( V_280 -> V_323 ) ;
return 0 ;
}
static int F_71 ( const struct V_281 * V_282 ,
struct V_277 * V_277 , void * V_314 , void * V_16 )
{
struct V_279 * V_280 ;
struct V_324 * V_325 ;
T_2 * V_19 = V_16 ;
V_280 = F_61 ( V_277 ) ;
if ( ! F_72 ( V_326 , & V_280 -> V_39 ) )
return - V_327 ;
V_325 = V_277 -> V_328 ;
return F_73 ( V_280 -> V_323 , & V_325 -> V_323 , * V_19 ) ;
}
static int F_74 ( const struct V_281 * V_282 ,
struct V_277 * V_277 , void * V_314 , void * V_16 )
{
struct V_279 * V_280 = F_61 ( V_277 ) ;
struct V_26 * V_19 = V_16 ;
if ( F_75 ( V_280 , V_329 ) )
V_19 -> V_24 |= V_330 ;
return V_282 -> V_331 ( V_277 , V_314 , V_19 ) ;
}
static int F_76 ( const struct V_281 * V_282 ,
struct V_277 * V_277 , void * V_314 , void * V_16 )
{
struct V_279 * V_280 = F_61 ( V_277 ) ;
struct V_31 * V_19 = V_16 ;
if ( F_75 ( V_280 , V_329 ) )
V_19 -> V_24 |= V_332 ;
return V_282 -> V_333 ( V_277 , V_314 , V_19 ) ;
}
static void F_77 ( struct V_37 * V_59 )
{
const unsigned V_334 = sizeof( V_59 -> V_41 ) ;
const char * V_6 = NULL ;
T_2 V_39 = 0 ;
switch ( V_59 -> V_40 ) {
case V_335 : V_6 = L_83 ; break;
case V_336 : V_6 = L_84 ; break;
case V_337 : V_6 = L_85 ; break;
case V_338 : V_6 = L_86 ; break;
case V_339 : V_6 = L_87 ; break;
case V_340 : V_6 = L_88 ; break;
case V_341 : V_6 = L_89 ; break;
case V_342 : V_6 = L_90 ; break;
case V_343 : V_6 = L_91 ; break;
case V_344 : V_6 = L_92 ; break;
case V_345 : V_6 = L_93 ; break;
case V_346 : V_6 = L_94 ; break;
case V_347 : V_6 = L_95 ; break;
case V_348 : V_6 = L_96 ; break;
case V_349 : V_6 = L_97 ; break;
case V_350 : V_6 = L_98 ; break;
case V_351 : V_6 = L_99 ; break;
case V_352 : V_6 = L_100 ; break;
case V_353 : V_6 = L_101 ; break;
case V_354 : V_6 = L_102 ; break;
case V_355 : V_6 = L_103 ; break;
case V_356 : V_6 = L_104 ; break;
case V_357 : V_6 = L_105 ; break;
case V_358 : V_6 = L_106 ; break;
case V_359 : V_6 = L_107 ; break;
case V_360 : V_6 = L_108 ; break;
case V_361 : V_6 = L_109 ; break;
case V_362 : V_6 = L_110 ; break;
case V_363 : V_6 = L_111 ; break;
case V_364 : V_6 = L_112 ; break;
case V_365 : V_6 = L_113 ; break;
case V_366 : V_6 = L_114 ; break;
case V_367 : V_6 = L_115 ; break;
case V_368 : V_6 = L_116 ; break;
case V_369 : V_6 = L_117 ; break;
case V_370 : V_6 = L_118 ; break;
case V_371 : V_6 = L_119 ; break;
case V_372 : V_6 = L_120 ; break;
case V_373 : V_6 = L_121 ; break;
case V_374 : V_6 = L_122 ; break;
case V_375 : V_6 = L_123 ; break;
case V_376 : V_6 = L_124 ; break;
case V_377 : V_6 = L_125 ; break;
case V_378 : V_6 = L_126 ; break;
case V_379 : V_6 = L_127 ; break;
case V_380 : V_6 = L_128 ; break;
case V_381 : V_6 = L_129 ; break;
case V_382 : V_6 = L_130 ; break;
case V_383 : V_6 = L_131 ; break;
case V_384 : V_6 = L_132 ; break;
case V_385 : V_6 = L_133 ; break;
case V_386 : V_6 = L_134 ; break;
case V_387 : V_6 = L_135 ; break;
case V_388 : V_6 = L_136 ; break;
case V_389 : V_6 = L_137 ; break;
case V_390 : V_6 = L_138 ; break;
case V_391 : V_6 = L_139 ; break;
case V_392 : V_6 = L_140 ; break;
case V_393 : V_6 = L_141 ; break;
case V_394 : V_6 = L_142 ; break;
case V_395 : V_6 = L_143 ; break;
case V_396 : V_6 = L_144 ; break;
case V_397 : V_6 = L_145 ; break;
case V_398 : V_6 = L_146 ; break;
case V_399 : V_6 = L_147 ; break;
case V_400 : V_6 = L_148 ; break;
case V_401 : V_6 = L_149 ; break;
case V_402 : V_6 = L_150 ; break;
case V_403 : V_6 = L_151 ; break;
case V_404 : V_6 = L_152 ; break;
case V_405 : V_6 = L_153 ; break;
case V_406 : V_6 = L_154 ; break;
case V_407 : V_6 = L_155 ; break;
case V_408 : V_6 = L_156 ; break;
case V_409 : V_6 = L_157 ; break;
case V_410 : V_6 = L_158 ; break;
case V_411 : V_6 = L_159 ; break;
case V_412 : V_6 = L_160 ; break;
case V_413 : V_6 = L_161 ; break;
case V_414 : V_6 = L_162 ; break;
case V_415 : V_6 = L_163 ; break;
case V_416 : V_6 = L_164 ; break;
case V_417 : V_6 = L_165 ; break;
case V_418 : V_6 = L_166 ; break;
case V_419 : V_6 = L_167 ; break;
case V_420 : V_6 = L_168 ; break;
case V_421 : V_6 = L_169 ; break;
case V_422 : V_6 = L_170 ; break;
case V_423 : V_6 = L_171 ; break;
case V_424 : V_6 = L_172 ; break;
case V_425 : V_6 = L_173 ; break;
case V_426 : V_6 = L_174 ; break;
case V_427 : V_6 = L_175 ; break;
case V_428 : V_6 = L_176 ; break;
case V_429 : V_6 = L_177 ; break;
case V_430 : V_6 = L_178 ; break;
case V_431 : V_6 = L_179 ; break;
case V_432 : V_6 = L_180 ; break;
case V_433 : V_6 = L_181 ; break;
case V_434 : V_6 = L_182 ; break;
case V_435 : V_6 = L_183 ; break;
case V_436 : V_6 = L_184 ; break;
case V_437 : V_6 = L_185 ; break;
case V_438 : V_6 = L_186 ; break;
case V_439 : V_6 = L_187 ; break;
case V_440 : V_6 = L_188 ; break;
case V_441 : V_6 = L_189 ; break;
case V_442 : V_6 = L_190 ; break;
case V_443 : V_6 = L_191 ; break;
case V_444 : V_6 = L_192 ; break;
case V_445 : V_6 = L_193 ; break;
case V_446 : V_6 = L_194 ; break;
case V_447 : V_6 = L_195 ; break;
case V_448 : V_6 = L_196 ; break;
case V_449 : V_6 = L_197 ; break;
case V_450 : V_6 = L_198 ; break;
case V_451 : V_6 = L_199 ; break;
case V_452 : V_6 = L_200 ; break;
case V_453 : V_6 = L_201 ; break;
case V_454 : V_6 = L_202 ; break;
case V_455 : V_6 = L_203 ; break;
default:
V_39 = V_456 ;
switch ( V_59 -> V_40 ) {
case V_457 : V_6 = L_204 ; break;
case V_458 : V_6 = L_205 ; break;
case V_459 : V_6 = L_206 ; break;
case V_460 : V_6 = L_207 ; break;
case V_461 : V_6 = L_208 ; break;
case V_462 : V_6 = L_209 ; break;
case V_463 : V_6 = L_210 ; break;
case V_464 : V_6 = L_211 ; break;
case V_465 : V_6 = L_212 ; break;
case V_466 : V_6 = L_213 ; break;
case V_467 : V_6 = L_214 ; break;
case V_468 : V_6 = L_215 ; break;
case V_469 : V_6 = L_216 ; break;
case V_470 : V_6 = L_217 ; break;
case V_471 : V_6 = L_218 ; break;
case V_472 : V_6 = L_219 ; break;
case V_473 : V_6 = L_220 ; break;
case V_474 : V_6 = L_221 ; break;
case V_475 : V_6 = L_222 ; break;
case V_476 : V_6 = L_223 ; break;
case V_477 : V_6 = L_224 ; break;
case V_478 : V_6 = L_225 ; break;
case V_479 : V_6 = L_226 ; break;
case V_480 : V_6 = L_227 ; break;
case V_481 : V_6 = L_228 ; break;
case V_482 : V_6 = L_229 ; break;
case V_483 : V_6 = L_230 ; break;
case V_484 : V_6 = L_231 ; break;
case V_485 : V_6 = L_232 ; break;
case V_486 : V_6 = L_233 ; break;
case V_487 : V_6 = L_234 ; break;
case V_488 : V_6 = L_235 ; break;
case V_489 : V_6 = L_236 ; break;
case V_490 : V_6 = L_237 ; break;
case V_491 : V_6 = L_238 ; break;
default:
F_65 ( 1 , L_239 , V_59 -> V_40 ) ;
if ( V_59 -> V_41 [ 0 ] )
return;
V_39 = 0 ;
snprintf ( V_59 -> V_41 , V_334 , L_240 ,
( char ) ( V_59 -> V_40 & 0x7f ) ,
( char ) ( ( V_59 -> V_40 >> 8 ) & 0x7f ) ,
( char ) ( ( V_59 -> V_40 >> 16 ) & 0x7f ) ,
( char ) ( ( V_59 -> V_40 >> 24 ) & 0x7f ) ,
( V_59 -> V_40 & ( 1 << 31 ) ) ? L_241 : L_242 ) ;
break;
}
}
if ( V_6 )
F_78 ( F_5 ( V_59 -> V_41 , V_6 , V_334 ) >= V_334 ) ;
V_59 -> V_39 = V_39 ;
}
static int F_79 ( const struct V_281 * V_282 ,
struct V_277 * V_277 , void * V_314 , void * V_16 )
{
struct V_37 * V_19 = V_16 ;
struct V_279 * V_280 = F_61 ( V_277 ) ;
bool V_284 = V_280 -> V_285 == V_286 ;
bool V_289 = V_280 -> V_285 == V_290 ;
bool V_291 = V_280 -> V_285 == V_292 ;
bool V_293 = V_280 -> V_294 != V_295 ;
bool V_296 = V_280 -> V_294 != V_297 ;
int V_316 = - V_298 ;
switch ( V_19 -> type ) {
case V_57 :
if ( F_80 ( ! V_293 || ( ! V_284 && ! V_291 ) || ! V_282 -> V_492 ) )
break;
V_316 = V_282 -> V_492 ( V_277 , V_314 , V_16 ) ;
break;
case V_70 :
if ( F_80 ( ! V_293 || ! V_284 || ! V_282 -> V_493 ) )
break;
V_316 = V_282 -> V_493 ( V_277 , V_314 , V_16 ) ;
break;
case V_76 :
if ( F_80 ( ! V_293 || ! V_284 || ! V_282 -> V_494 ) )
break;
V_316 = V_282 -> V_494 ( V_277 , V_314 , V_16 ) ;
break;
case V_58 :
if ( F_80 ( ! V_296 || ! V_284 || ! V_282 -> V_495 ) )
break;
V_316 = V_282 -> V_495 ( V_277 , V_314 , V_16 ) ;
break;
case V_71 :
if ( F_80 ( ! V_296 || ! V_284 || ! V_282 -> V_496 ) )
break;
V_316 = V_282 -> V_496 ( V_277 , V_314 , V_16 ) ;
break;
case V_99 :
if ( F_80 ( ! V_293 || ! V_289 || ! V_282 -> V_497 ) )
break;
V_316 = V_282 -> V_497 ( V_277 , V_314 , V_16 ) ;
break;
case V_100 :
if ( F_80 ( ! V_296 || ! V_289 || ! V_282 -> V_498 ) )
break;
V_316 = V_282 -> V_498 ( V_277 , V_314 , V_16 ) ;
break;
case V_101 :
if ( F_80 ( ! V_293 || ! V_284 || ! V_282 -> V_499 ) )
break;
V_316 = V_282 -> V_499 ( V_277 , V_314 , V_16 ) ;
break;
}
if ( V_316 == 0 )
F_77 ( V_19 ) ;
return V_316 ;
}
static int F_81 ( const struct V_281 * V_282 ,
struct V_277 * V_277 , void * V_314 , void * V_16 )
{
struct V_42 * V_19 = V_16 ;
struct V_279 * V_280 = F_61 ( V_277 ) ;
bool V_284 = V_280 -> V_285 == V_286 ;
bool V_289 = V_280 -> V_285 == V_290 ;
bool V_291 = V_280 -> V_285 == V_292 ;
bool V_293 = V_280 -> V_294 != V_295 ;
bool V_296 = V_280 -> V_294 != V_297 ;
int V_316 ;
switch ( V_19 -> type ) {
case V_76 :
case V_77 : {
struct V_500 T_3 * V_83 = V_19 -> V_59 . V_52 . V_83 ;
T_2 V_82 = V_19 -> V_59 . V_52 . V_82 ;
void T_3 * V_84 = V_19 -> V_59 . V_52 . V_84 ;
memset ( & V_19 -> V_59 , 0 , sizeof( V_19 -> V_59 ) ) ;
V_19 -> V_59 . V_52 . V_83 = V_83 ;
V_19 -> V_59 . V_52 . V_82 = V_82 ;
V_19 -> V_59 . V_52 . V_84 = V_84 ;
break;
}
default:
memset ( & V_19 -> V_59 , 0 , sizeof( V_19 -> V_59 ) ) ;
break;
}
switch ( V_19 -> type ) {
case V_57 :
if ( F_80 ( ! V_293 || ( ! V_284 && ! V_291 ) || ! V_282 -> V_299 ) )
break;
V_19 -> V_59 . V_44 . V_312 = V_313 ;
V_316 = V_282 -> V_299 ( V_277 , V_314 , V_16 ) ;
V_19 -> V_59 . V_44 . V_312 = V_313 ;
return V_316 ;
case V_70 :
if ( F_80 ( ! V_293 || ! V_284 || ! V_282 -> V_300 ) )
break;
return V_282 -> V_300 ( V_277 , V_314 , V_16 ) ;
case V_76 :
if ( F_80 ( ! V_293 || ! V_284 || ! V_282 -> V_301 ) )
break;
return V_282 -> V_301 ( V_277 , V_314 , V_16 ) ;
case V_86 :
if ( F_80 ( ! V_293 || V_284 || ! V_282 -> V_305 ) )
break;
return V_282 -> V_305 ( V_277 , V_314 , V_16 ) ;
case V_94 :
if ( F_80 ( ! V_293 || V_284 || ! V_282 -> V_307 ) )
break;
return V_282 -> V_307 ( V_277 , V_314 , V_16 ) ;
case V_58 :
if ( F_80 ( ! V_296 || ! V_284 || ! V_282 -> V_302 ) )
break;
V_19 -> V_59 . V_44 . V_312 = V_313 ;
V_316 = V_282 -> V_302 ( V_277 , V_314 , V_16 ) ;
V_19 -> V_59 . V_44 . V_312 = V_313 ;
return V_316 ;
case V_71 :
if ( F_80 ( ! V_296 || ! V_284 || ! V_282 -> V_303 ) )
break;
return V_282 -> V_303 ( V_277 , V_314 , V_16 ) ;
case V_77 :
if ( F_80 ( ! V_296 || ! V_284 || ! V_282 -> V_304 ) )
break;
return V_282 -> V_304 ( V_277 , V_314 , V_16 ) ;
case V_87 :
if ( F_80 ( ! V_296 || V_284 || ! V_282 -> V_306 ) )
break;
return V_282 -> V_306 ( V_277 , V_314 , V_16 ) ;
case V_95 :
if ( F_80 ( ! V_296 || V_284 || ! V_282 -> V_308 ) )
break;
return V_282 -> V_308 ( V_277 , V_314 , V_16 ) ;
case V_99 :
if ( F_80 ( ! V_293 || ! V_289 || ! V_282 -> V_309 ) )
break;
return V_282 -> V_309 ( V_277 , V_314 , V_16 ) ;
case V_100 :
if ( F_80 ( ! V_296 || ! V_289 || ! V_282 -> V_310 ) )
break;
return V_282 -> V_310 ( V_277 , V_314 , V_16 ) ;
case V_101 :
if ( F_80 ( ! V_293 || ! V_284 || ! V_282 -> V_311 ) )
break;
return V_282 -> V_311 ( V_277 , V_314 , V_16 ) ;
}
return - V_298 ;
}
static void F_82 ( struct V_43 * V_19 )
{
V_19 -> V_62 = V_501 ;
V_19 -> V_66 = V_502 ;
V_19 -> V_39 = 0 ;
V_19 -> V_67 = 0 ;
V_19 -> V_68 = 0 ;
V_19 -> V_69 = 0 ;
}
static int F_83 ( const struct V_281 * V_282 ,
struct V_277 * V_277 , void * V_314 , void * V_16 )
{
struct V_42 * V_19 = V_16 ;
struct V_279 * V_280 = F_61 ( V_277 ) ;
bool V_284 = V_280 -> V_285 == V_286 ;
bool V_289 = V_280 -> V_285 == V_290 ;
bool V_291 = V_280 -> V_285 == V_292 ;
bool V_293 = V_280 -> V_294 != V_295 ;
bool V_296 = V_280 -> V_294 != V_297 ;
int V_316 ;
V_316 = F_67 ( V_280 ) ;
if ( V_316 )
return V_316 ;
F_62 ( V_19 ) ;
switch ( V_19 -> type ) {
case V_57 :
if ( F_80 ( ! V_293 || ( ! V_284 && ! V_291 ) || ! V_282 -> V_503 ) )
break;
F_84 ( V_19 , V_59 . V_44 ) ;
V_316 = V_282 -> V_503 ( V_277 , V_314 , V_16 ) ;
V_19 -> V_59 . V_44 . V_312 = V_313 ;
if ( V_291 )
F_82 ( & V_19 -> V_59 . V_44 ) ;
return V_316 ;
case V_70 :
if ( F_80 ( ! V_293 || ! V_284 || ! V_282 -> V_504 ) )
break;
F_84 ( V_19 , V_59 . V_72 . V_69 ) ;
return V_282 -> V_504 ( V_277 , V_314 , V_16 ) ;
case V_76 :
if ( F_80 ( ! V_293 || ! V_284 || ! V_282 -> V_505 ) )
break;
F_84 ( V_19 , V_59 . V_52 ) ;
return V_282 -> V_505 ( V_277 , V_314 , V_16 ) ;
case V_86 :
if ( F_80 ( ! V_293 || V_284 || ! V_282 -> V_506 ) )
break;
F_84 ( V_19 , V_59 . V_48 ) ;
return V_282 -> V_506 ( V_277 , V_314 , V_16 ) ;
case V_94 :
if ( F_80 ( ! V_293 || V_284 || ! V_282 -> V_507 ) )
break;
F_84 ( V_19 , V_59 . V_50 ) ;
return V_282 -> V_507 ( V_277 , V_314 , V_16 ) ;
case V_58 :
if ( F_80 ( ! V_296 || ! V_284 || ! V_282 -> V_508 ) )
break;
F_84 ( V_19 , V_59 . V_44 ) ;
V_316 = V_282 -> V_508 ( V_277 , V_314 , V_16 ) ;
V_19 -> V_59 . V_44 . V_312 = V_313 ;
return V_316 ;
case V_71 :
if ( F_80 ( ! V_296 || ! V_284 || ! V_282 -> V_509 ) )
break;
F_84 ( V_19 , V_59 . V_72 . V_69 ) ;
return V_282 -> V_509 ( V_277 , V_314 , V_16 ) ;
case V_77 :
if ( F_80 ( ! V_296 || ! V_284 || ! V_282 -> V_510 ) )
break;
F_84 ( V_19 , V_59 . V_52 ) ;
return V_282 -> V_510 ( V_277 , V_314 , V_16 ) ;
case V_87 :
if ( F_80 ( ! V_296 || V_284 || ! V_282 -> V_511 ) )
break;
F_84 ( V_19 , V_59 . V_48 ) ;
return V_282 -> V_511 ( V_277 , V_314 , V_16 ) ;
case V_95 :
if ( F_80 ( ! V_296 || V_284 || ! V_282 -> V_512 ) )
break;
F_84 ( V_19 , V_59 . V_50 ) ;
return V_282 -> V_512 ( V_277 , V_314 , V_16 ) ;
case V_99 :
if ( F_80 ( ! V_293 || ! V_289 || ! V_282 -> V_513 ) )
break;
F_84 ( V_19 , V_59 . V_54 ) ;
return V_282 -> V_513 ( V_277 , V_314 , V_16 ) ;
case V_100 :
if ( F_80 ( ! V_296 || ! V_289 || ! V_282 -> V_514 ) )
break;
F_84 ( V_19 , V_59 . V_54 ) ;
return V_282 -> V_514 ( V_277 , V_314 , V_16 ) ;
case V_101 :
if ( F_80 ( ! V_293 || ! V_284 || ! V_282 -> V_515 ) )
break;
F_84 ( V_19 , V_59 . V_56 ) ;
return V_282 -> V_515 ( V_277 , V_314 , V_16 ) ;
}
return - V_298 ;
}
static int F_85 ( const struct V_281 * V_282 ,
struct V_277 * V_277 , void * V_314 , void * V_16 )
{
struct V_42 * V_19 = V_16 ;
struct V_279 * V_280 = F_61 ( V_277 ) ;
bool V_284 = V_280 -> V_285 == V_286 ;
bool V_289 = V_280 -> V_285 == V_290 ;
bool V_291 = V_280 -> V_285 == V_292 ;
bool V_293 = V_280 -> V_294 != V_295 ;
bool V_296 = V_280 -> V_294 != V_297 ;
int V_316 ;
F_62 ( V_19 ) ;
switch ( V_19 -> type ) {
case V_57 :
if ( F_80 ( ! V_293 || ( ! V_284 && ! V_291 ) || ! V_282 -> V_516 ) )
break;
F_84 ( V_19 , V_59 . V_44 ) ;
V_316 = V_282 -> V_516 ( V_277 , V_314 , V_16 ) ;
V_19 -> V_59 . V_44 . V_312 = V_313 ;
return V_316 ;
case V_70 :
if ( F_80 ( ! V_293 || ! V_284 || ! V_282 -> V_517 ) )
break;
F_84 ( V_19 , V_59 . V_72 . V_69 ) ;
return V_282 -> V_517 ( V_277 , V_314 , V_16 ) ;
case V_76 :
if ( F_80 ( ! V_293 || ! V_284 || ! V_282 -> V_518 ) )
break;
F_84 ( V_19 , V_59 . V_52 ) ;
return V_282 -> V_518 ( V_277 , V_314 , V_16 ) ;
case V_86 :
if ( F_80 ( ! V_293 || V_284 || ! V_282 -> V_519 ) )
break;
F_84 ( V_19 , V_59 . V_48 ) ;
return V_282 -> V_519 ( V_277 , V_314 , V_16 ) ;
case V_94 :
if ( F_80 ( ! V_293 || V_284 || ! V_282 -> V_520 ) )
break;
F_84 ( V_19 , V_59 . V_50 ) ;
return V_282 -> V_520 ( V_277 , V_314 , V_16 ) ;
case V_58 :
if ( F_80 ( ! V_296 || ! V_284 || ! V_282 -> V_521 ) )
break;
F_84 ( V_19 , V_59 . V_44 ) ;
V_316 = V_282 -> V_521 ( V_277 , V_314 , V_16 ) ;
V_19 -> V_59 . V_44 . V_312 = V_313 ;
return V_316 ;
case V_71 :
if ( F_80 ( ! V_296 || ! V_284 || ! V_282 -> V_522 ) )
break;
F_84 ( V_19 , V_59 . V_72 . V_69 ) ;
return V_282 -> V_522 ( V_277 , V_314 , V_16 ) ;
case V_77 :
if ( F_80 ( ! V_296 || ! V_284 || ! V_282 -> V_523 ) )
break;
F_84 ( V_19 , V_59 . V_52 ) ;
return V_282 -> V_523 ( V_277 , V_314 , V_16 ) ;
case V_87 :
if ( F_80 ( ! V_296 || V_284 || ! V_282 -> V_524 ) )
break;
F_84 ( V_19 , V_59 . V_48 ) ;
return V_282 -> V_524 ( V_277 , V_314 , V_16 ) ;
case V_95 :
if ( F_80 ( ! V_296 || V_284 || ! V_282 -> V_525 ) )
break;
F_84 ( V_19 , V_59 . V_50 ) ;
return V_282 -> V_525 ( V_277 , V_314 , V_16 ) ;
case V_99 :
if ( F_80 ( ! V_293 || ! V_289 || ! V_282 -> V_526 ) )
break;
F_84 ( V_19 , V_59 . V_54 ) ;
return V_282 -> V_526 ( V_277 , V_314 , V_16 ) ;
case V_100 :
if ( F_80 ( ! V_296 || ! V_289 || ! V_282 -> V_527 ) )
break;
F_84 ( V_19 , V_59 . V_54 ) ;
return V_282 -> V_527 ( V_277 , V_314 , V_16 ) ;
case V_101 :
if ( F_80 ( ! V_293 || ! V_284 || ! V_282 -> V_528 ) )
break;
F_84 ( V_19 , V_59 . V_56 ) ;
return V_282 -> V_528 ( V_277 , V_314 , V_16 ) ;
}
return - V_298 ;
}
static int F_86 ( const struct V_281 * V_282 ,
struct V_277 * V_277 , void * V_314 , void * V_16 )
{
return V_282 -> V_529 ( V_277 , V_314 , * ( unsigned int * ) V_16 ) ;
}
static int F_87 ( const struct V_281 * V_282 ,
struct V_277 * V_277 , void * V_314 , void * V_16 )
{
return V_282 -> V_530 ( V_277 , V_314 , * ( unsigned int * ) V_16 ) ;
}
static int F_88 ( const struct V_281 * V_282 ,
struct V_277 * V_277 , void * V_314 , void * V_16 )
{
struct V_279 * V_280 = F_61 ( V_277 ) ;
struct V_110 * V_19 = V_16 ;
int V_531 ;
V_19 -> type = ( V_280 -> V_285 == V_532 ) ?
V_533 : V_534 ;
V_531 = V_282 -> V_535 ( V_277 , V_314 , V_19 ) ;
if ( ! V_531 )
V_19 -> V_35 |= V_536 ;
return V_531 ;
}
static int F_89 ( const struct V_281 * V_282 ,
struct V_277 * V_277 , void * V_314 , void * V_16 )
{
struct V_279 * V_280 = F_61 ( V_277 ) ;
struct V_110 * V_19 = V_16 ;
int V_316 ;
V_316 = F_67 ( V_280 ) ;
if ( V_316 )
return V_316 ;
V_19 -> type = ( V_280 -> V_285 == V_532 ) ?
V_533 : V_534 ;
return V_282 -> V_537 ( V_277 , V_314 , V_19 ) ;
}
static int F_90 ( const struct V_281 * V_282 ,
struct V_277 * V_277 , void * V_314 , void * V_16 )
{
struct V_279 * V_280 = F_61 ( V_277 ) ;
struct V_106 * V_19 = V_16 ;
int V_531 ;
if ( V_280 -> V_285 == V_532 )
V_19 -> type = V_533 ;
V_531 = V_282 -> V_538 ( V_277 , V_314 , V_19 ) ;
if ( ! V_531 )
V_19 -> V_35 |= V_536 ;
return V_531 ;
}
static int F_91 ( const struct V_281 * V_282 ,
struct V_277 * V_277 , void * V_314 , void * V_16 )
{
struct V_279 * V_280 = F_61 ( V_277 ) ;
struct V_106 * V_19 = V_16 ;
if ( V_280 -> V_285 == V_532 )
V_19 -> type = V_533 ;
return V_282 -> V_539 ( V_277 , V_314 , V_19 ) ;
}
static int F_92 ( const struct V_281 * V_282 ,
struct V_277 * V_277 , void * V_314 , void * V_16 )
{
struct V_279 * V_280 = F_61 ( V_277 ) ;
struct V_114 * V_19 = V_16 ;
if ( V_280 -> V_285 == V_290 )
V_19 -> type = V_540 ;
else
V_19 -> type = ( V_280 -> V_285 == V_532 ) ?
V_533 : V_534 ;
return V_282 -> V_541 ( V_277 , V_314 , V_19 ) ;
}
static int F_93 ( const struct V_281 * V_282 ,
struct V_277 * V_277 , void * V_314 , void * V_16 )
{
struct V_279 * V_280 = F_61 ( V_277 ) ;
const struct V_114 * V_19 = V_16 ;
enum V_542 type ;
int V_316 ;
V_316 = F_67 ( V_280 ) ;
if ( V_316 )
return V_316 ;
if ( V_280 -> V_285 == V_290 ) {
if ( V_19 -> type != V_540 && V_19 -> type != V_543 )
return - V_298 ;
} else {
type = ( V_280 -> V_285 == V_532 ) ?
V_533 : V_534 ;
if ( type != V_19 -> type )
return - V_298 ;
}
return V_282 -> V_544 ( V_277 , V_314 , V_19 ) ;
}
static int F_94 ( const struct V_281 * V_282 ,
struct V_277 * V_277 , void * V_314 , void * V_16 )
{
struct V_279 * V_280 = F_61 ( V_277 ) ;
struct V_12 * V_19 = V_16 ;
T_1 V_1 = V_280 -> V_545 , V_546 = 0 ;
unsigned int V_27 = V_19 -> V_27 , V_3 , V_547 = 0 ;
const char * V_6 = L_242 ;
if ( V_1 == 0 )
return - V_548 ;
for ( V_3 = 0 ; V_3 <= V_27 && V_1 ; V_3 ++ ) {
while ( ( V_1 & V_4 [ V_547 ] . V_5 ) != V_4 [ V_547 ] . V_5 )
V_547 ++ ;
V_546 = V_4 [ V_547 ] . V_5 ;
V_6 = V_4 [ V_547 ] . V_6 ;
V_547 ++ ;
if ( V_546 == 0 )
break;
if ( V_546 != V_549 &&
V_546 != V_550 &&
V_546 != V_551 )
V_1 &= ~ V_546 ;
}
if ( V_3 <= V_27 )
return - V_298 ;
F_4 ( V_19 , V_546 , V_6 ) ;
return 0 ;
}
static int F_95 ( const struct V_281 * V_282 ,
struct V_277 * V_277 , void * V_314 , void * V_16 )
{
struct V_279 * V_280 = F_61 ( V_277 ) ;
T_1 V_1 = * ( T_1 * ) V_16 , V_552 ;
int V_316 ;
V_316 = F_67 ( V_280 ) ;
if ( V_316 )
return V_316 ;
V_552 = V_1 & V_280 -> V_545 ;
if ( V_280 -> V_545 && ! V_552 )
return - V_298 ;
return V_282 -> V_553 ( V_277 , V_314 , V_552 ) ;
}
static int F_96 ( const struct V_281 * V_282 ,
struct V_277 * V_277 , void * V_314 , void * V_16 )
{
struct V_279 * V_280 = F_61 ( V_277 ) ;
T_1 * V_19 = V_16 ;
int V_316 ;
V_316 = F_67 ( V_280 ) ;
if ( V_316 )
return V_316 ;
* V_19 = V_280 -> V_545 ;
return V_282 -> V_554 ( V_277 , V_314 , V_16 ) ;
}
static int F_97 ( const struct V_281 * V_282 ,
struct V_277 * V_277 , void * V_314 , void * V_16 )
{
struct V_279 * V_280 = F_61 ( V_277 ) ;
struct V_116 * V_19 = V_16 ;
enum V_542 type ;
int V_316 ;
V_316 = F_67 ( V_280 ) ;
if ( V_316 )
return V_316 ;
if ( V_280 -> V_285 == V_290 )
return - V_298 ;
type = ( V_280 -> V_285 == V_532 ) ?
V_533 : V_534 ;
if ( V_19 -> type != type )
return - V_298 ;
return V_282 -> V_555 ( V_277 , V_314 , V_19 ) ;
}
static int F_98 ( const struct V_281 * V_282 ,
struct V_277 * V_277 , void * V_314 , void * V_16 )
{
return V_282 -> V_556 ( V_277 , V_314 , * ( unsigned int * ) V_16 ) ;
}
static int F_99 ( const struct V_281 * V_282 ,
struct V_277 * V_277 , void * V_314 , void * V_16 )
{
struct V_120 * V_19 = V_16 ;
int V_316 = F_60 ( V_277 , V_19 -> type ) ;
if ( V_316 )
return V_316 ;
F_84 ( V_19 , V_121 ) ;
return V_282 -> V_557 ( V_277 , V_314 , V_19 ) ;
}
static int F_100 ( const struct V_281 * V_282 ,
struct V_277 * V_277 , void * V_314 , void * V_16 )
{
struct V_123 * V_19 = V_16 ;
int V_316 = F_60 ( V_277 , V_19 -> type ) ;
return V_316 ? V_316 : V_282 -> V_558 ( V_277 , V_314 , V_19 ) ;
}
static int F_101 ( const struct V_281 * V_282 ,
struct V_277 * V_277 , void * V_314 , void * V_16 )
{
struct V_123 * V_19 = V_16 ;
int V_316 = F_60 ( V_277 , V_19 -> type ) ;
return V_316 ? V_316 : V_282 -> V_559 ( V_277 , V_314 , V_19 ) ;
}
static int F_102 ( const struct V_281 * V_282 ,
struct V_277 * V_277 , void * V_314 , void * V_16 )
{
struct V_123 * V_19 = V_16 ;
int V_316 = F_60 ( V_277 , V_19 -> type ) ;
return V_316 ? V_316 : V_282 -> V_560 ( V_277 , V_314 , V_19 ) ;
}
static int F_103 ( const struct V_281 * V_282 ,
struct V_277 * V_277 , void * V_314 , void * V_16 )
{
struct V_147 * V_561 = V_16 ;
int V_316 = F_60 ( V_277 , V_561 -> V_148 . type ) ;
if ( V_316 )
return V_316 ;
F_84 ( V_561 , V_148 ) ;
F_62 ( & V_561 -> V_148 ) ;
V_316 = V_282 -> V_562 ( V_277 , V_314 , V_561 ) ;
if ( V_561 -> V_148 . type == V_57 ||
V_561 -> V_148 . type == V_58 )
V_561 -> V_148 . V_59 . V_44 . V_312 = V_313 ;
return V_316 ;
}
static int F_104 ( const struct V_281 * V_282 ,
struct V_277 * V_277 , void * V_314 , void * V_16 )
{
struct V_123 * V_563 = V_16 ;
int V_316 = F_60 ( V_277 , V_563 -> type ) ;
return V_316 ? V_316 : V_282 -> V_564 ( V_277 , V_314 , V_563 ) ;
}
static int F_105 ( const struct V_281 * V_282 ,
struct V_277 * V_277 , void * V_314 , void * V_16 )
{
struct V_149 * V_19 = V_16 ;
T_1 V_5 ;
int V_316 = F_60 ( V_277 , V_19 -> type ) ;
if ( V_316 )
return V_316 ;
if ( V_282 -> V_565 )
return V_282 -> V_565 ( V_277 , V_314 , V_19 ) ;
if ( V_19 -> type != V_57 &&
V_19 -> type != V_70 )
return - V_298 ;
V_19 -> V_152 . V_153 . V_157 = 2 ;
V_316 = V_282 -> V_566 ( V_277 , V_314 , & V_5 ) ;
if ( V_316 == 0 )
F_3 ( V_5 , & V_19 -> V_152 . V_153 . V_155 ) ;
return V_316 ;
}
static int F_106 ( const struct V_281 * V_282 ,
struct V_277 * V_277 , void * V_314 , void * V_16 )
{
struct V_149 * V_19 = V_16 ;
int V_316 = F_60 ( V_277 , V_19 -> type ) ;
return V_316 ? V_316 : V_282 -> V_567 ( V_277 , V_314 , V_19 ) ;
}
static int F_107 ( const struct V_281 * V_282 ,
struct V_277 * V_277 , void * V_314 , void * V_16 )
{
struct V_279 * V_280 = F_61 ( V_277 ) ;
struct V_162 * V_19 = V_16 ;
struct V_324 * V_325 =
F_72 ( V_326 , & V_280 -> V_39 ) ? V_314 : NULL ;
if ( V_325 && V_325 -> V_568 )
return V_162 ( V_325 -> V_568 , V_19 ) ;
if ( V_280 -> V_568 )
return V_162 ( V_280 -> V_568 , V_19 ) ;
if ( V_282 -> V_569 )
return V_282 -> V_569 ( V_277 , V_314 , V_19 ) ;
return - V_327 ;
}
static int F_108 ( const struct V_281 * V_282 ,
struct V_277 * V_277 , void * V_314 , void * V_16 )
{
struct V_279 * V_280 = F_61 ( V_277 ) ;
struct V_167 * V_19 = V_16 ;
struct V_324 * V_325 =
F_72 ( V_326 , & V_280 -> V_39 ) ? V_314 : NULL ;
if ( V_325 && V_325 -> V_568 )
return V_167 ( V_325 -> V_568 , V_19 ) ;
if ( V_280 -> V_568 )
return V_167 ( V_280 -> V_568 , V_19 ) ;
if ( V_282 -> V_570 )
return V_282 -> V_570 ( V_277 , V_314 , V_19 ) ;
return - V_327 ;
}
static int F_109 ( const struct V_281 * V_282 ,
struct V_277 * V_277 , void * V_314 , void * V_16 )
{
struct V_279 * V_280 = F_61 ( V_277 ) ;
struct V_172 * V_19 = V_16 ;
struct V_324 * V_325 =
F_72 ( V_326 , & V_280 -> V_39 ) ? V_314 : NULL ;
if ( V_325 && V_325 -> V_568 )
return V_172 ( V_325 -> V_568 , V_19 ) ;
if ( V_280 -> V_568 )
return V_172 ( V_280 -> V_568 , V_19 ) ;
if ( V_282 -> V_571 )
return V_282 -> V_571 ( V_277 , V_314 , V_19 ) ;
return - V_327 ;
}
static int F_110 ( const struct V_281 * V_282 ,
struct V_277 * V_277 , void * V_314 , void * V_16 )
{
struct V_279 * V_280 = F_61 ( V_277 ) ;
struct V_173 * V_19 = V_16 ;
struct V_324 * V_325 =
F_72 ( V_326 , & V_280 -> V_39 ) ? V_314 : NULL ;
struct V_175 V_572 ;
struct V_573 V_258 ;
if ( V_325 && V_325 -> V_568 )
return F_111 ( V_325 -> V_568 , V_19 ) ;
if ( V_280 -> V_568 )
return F_111 ( V_280 -> V_568 , V_19 ) ;
if ( V_282 -> V_574 )
return V_282 -> V_574 ( V_277 , V_314 , V_19 ) ;
if ( V_282 -> V_575 == NULL )
return - V_327 ;
V_572 . V_176 = F_59 ( V_19 -> V_1 ) ;
V_572 . V_93 = 1 ;
V_572 . V_178 = & V_258 ;
V_258 . V_1 = V_19 -> V_1 ;
V_258 . V_174 = V_19 -> V_174 ;
if ( F_58 ( & V_572 , 1 ) ) {
int V_316 = V_282 -> V_575 ( V_277 , V_314 , & V_572 ) ;
if ( V_316 == 0 )
V_19 -> V_174 = V_258 . V_174 ;
return V_316 ;
}
return - V_298 ;
}
static int F_112 ( const struct V_281 * V_282 ,
struct V_277 * V_277 , void * V_314 , void * V_16 )
{
struct V_279 * V_280 = F_61 ( V_277 ) ;
struct V_173 * V_19 = V_16 ;
struct V_324 * V_325 =
F_72 ( V_326 , & V_280 -> V_39 ) ? V_314 : NULL ;
struct V_175 V_572 ;
struct V_573 V_258 ;
if ( V_325 && V_325 -> V_568 )
return F_113 ( V_325 , V_325 -> V_568 , V_19 ) ;
if ( V_280 -> V_568 )
return F_113 ( NULL , V_280 -> V_568 , V_19 ) ;
if ( V_282 -> V_576 )
return V_282 -> V_576 ( V_277 , V_314 , V_19 ) ;
if ( V_282 -> V_577 == NULL )
return - V_327 ;
V_572 . V_176 = F_59 ( V_19 -> V_1 ) ;
V_572 . V_93 = 1 ;
V_572 . V_178 = & V_258 ;
V_258 . V_1 = V_19 -> V_1 ;
V_258 . V_174 = V_19 -> V_174 ;
if ( F_58 ( & V_572 , 1 ) )
return V_282 -> V_577 ( V_277 , V_314 , & V_572 ) ;
return - V_298 ;
}
static int F_114 ( const struct V_281 * V_282 ,
struct V_277 * V_277 , void * V_314 , void * V_16 )
{
struct V_279 * V_280 = F_61 ( V_277 ) ;
struct V_175 * V_19 = V_16 ;
struct V_324 * V_325 =
F_72 ( V_326 , & V_280 -> V_39 ) ? V_314 : NULL ;
V_19 -> V_177 = V_19 -> V_93 ;
if ( V_325 && V_325 -> V_568 )
return F_115 ( V_325 -> V_568 , V_19 ) ;
if ( V_280 -> V_568 )
return F_115 ( V_280 -> V_568 , V_19 ) ;
if ( V_282 -> V_575 == NULL )
return - V_327 ;
return F_58 ( V_19 , 0 ) ? V_282 -> V_575 ( V_277 , V_314 , V_19 ) :
- V_298 ;
}
static int F_116 ( const struct V_281 * V_282 ,
struct V_277 * V_277 , void * V_314 , void * V_16 )
{
struct V_279 * V_280 = F_61 ( V_277 ) ;
struct V_175 * V_19 = V_16 ;
struct V_324 * V_325 =
F_72 ( V_326 , & V_280 -> V_39 ) ? V_314 : NULL ;
V_19 -> V_177 = V_19 -> V_93 ;
if ( V_325 && V_325 -> V_568 )
return F_117 ( V_325 , V_325 -> V_568 , V_19 ) ;
if ( V_280 -> V_568 )
return F_117 ( NULL , V_280 -> V_568 , V_19 ) ;
if ( V_282 -> V_577 == NULL )
return - V_327 ;
return F_58 ( V_19 , 0 ) ? V_282 -> V_577 ( V_277 , V_314 , V_19 ) :
- V_298 ;
}
static int F_118 ( const struct V_281 * V_282 ,
struct V_277 * V_277 , void * V_314 , void * V_16 )
{
struct V_279 * V_280 = F_61 ( V_277 ) ;
struct V_175 * V_19 = V_16 ;
struct V_324 * V_325 =
F_72 ( V_326 , & V_280 -> V_39 ) ? V_314 : NULL ;
V_19 -> V_177 = V_19 -> V_93 ;
if ( V_325 && V_325 -> V_568 )
return F_119 ( V_325 -> V_568 , V_19 ) ;
if ( V_280 -> V_568 )
return F_119 ( V_280 -> V_568 , V_19 ) ;
if ( V_282 -> V_578 == NULL )
return - V_327 ;
return F_58 ( V_19 , 0 ) ? V_282 -> V_578 ( V_277 , V_314 , V_19 ) :
- V_298 ;
}
static int F_120 ( const struct V_281 * V_282 ,
struct V_277 * V_277 , void * V_314 , void * V_16 )
{
struct V_184 * V_19 = V_16 ;
struct V_185 V_579 = {
. type = V_19 -> type ,
} ;
int V_316 ;
if ( V_282 -> V_580 )
return V_282 -> V_580 ( V_277 , V_314 , V_19 ) ;
if ( F_121 ( V_19 -> type ) )
V_579 . V_186 = V_581 ;
else
V_579 . V_186 = V_582 ;
V_316 = V_282 -> V_583 ( V_277 , V_314 , & V_579 ) ;
if ( ! V_316 )
V_19 -> V_151 = V_579 . V_187 ;
return V_316 ;
}
static int F_122 ( const struct V_281 * V_282 ,
struct V_277 * V_277 , void * V_314 , void * V_16 )
{
struct V_184 * V_19 = V_16 ;
struct V_185 V_579 = {
. type = V_19 -> type ,
. V_187 = V_19 -> V_151 ,
} ;
if ( V_282 -> V_584 )
return V_282 -> V_584 ( V_277 , V_314 , V_19 ) ;
if ( F_121 ( V_19 -> type ) )
V_579 . V_186 = V_581 ;
else
V_579 . V_186 = V_582 ;
return V_282 -> V_585 ( V_277 , V_314 , & V_579 ) ;
}
static int F_123 ( const struct V_281 * V_282 ,
struct V_277 * V_277 , void * V_314 , void * V_16 )
{
struct V_180 * V_19 = V_16 ;
struct V_185 V_579 = { . type = V_19 -> type } ;
int V_316 = 0 ;
V_19 -> V_183 . V_10 = 1 ;
V_19 -> V_183 . V_11 = 1 ;
if ( F_78 ( ! V_282 -> V_586 && ! V_282 -> V_583 ) )
return - V_327 ;
if ( V_282 -> V_586 )
V_316 = V_282 -> V_586 ( V_277 , V_314 , V_19 ) ;
if ( ! V_282 -> V_583 )
return V_316 ;
if ( V_316 && V_316 != - V_327 && V_316 != - V_587 )
return V_316 ;
if ( F_121 ( V_19 -> type ) )
V_579 . V_186 = V_588 ;
else
V_579 . V_186 = V_589 ;
V_316 = V_282 -> V_583 ( V_277 , V_314 , & V_579 ) ;
if ( V_316 )
return V_316 ;
V_19 -> V_181 = V_579 . V_187 ;
if ( F_121 ( V_19 -> type ) )
V_579 . V_186 = V_590 ;
else
V_579 . V_186 = V_591 ;
V_316 = V_282 -> V_583 ( V_277 , V_314 , & V_579 ) ;
if ( V_316 )
return V_316 ;
V_19 -> V_182 = V_579 . V_187 ;
return 0 ;
}
static int F_124 ( const struct V_281 * V_282 ,
struct V_277 * V_277 , void * V_314 , void * V_16 )
{
struct V_279 * V_280 = F_61 ( V_277 ) ;
int V_316 ;
if ( V_280 -> V_592 )
F_42 ( L_243 ,
V_280 -> V_592 -> V_14 ) ;
V_316 = V_282 -> V_593 ( V_277 , V_314 ) ;
if ( V_280 -> V_592 )
F_42 ( L_244 ,
V_280 -> V_592 -> V_14 ) ;
return V_316 ;
}
static int F_125 ( const struct V_281 * V_282 ,
struct V_277 * V_277 , void * V_314 , void * V_16 )
{
#ifdef F_126
struct V_209 * V_19 = V_16 ;
struct V_279 * V_280 = F_61 ( V_277 ) ;
struct V_594 * V_595 ;
int V_596 = 0 ;
if ( ! F_127 ( V_597 ) )
return - V_598 ;
if ( V_19 -> V_206 . type == V_599 ) {
if ( V_280 -> V_592 == NULL )
return - V_298 ;
F_128 (sd, vfd->v4l2_dev)
if ( V_19 -> V_206 . V_208 == V_596 ++ )
return F_129 ( V_595 , V_600 , V_601 , V_19 ) ;
return - V_298 ;
}
if ( V_282 -> V_602 && V_19 -> V_206 . type == V_603 &&
( V_282 -> V_604 || V_19 -> V_206 . V_208 == 0 ) )
return V_282 -> V_602 ( V_277 , V_314 , V_19 ) ;
return - V_298 ;
#else
return - V_327 ;
#endif
}
static int F_130 ( const struct V_281 * V_282 ,
struct V_277 * V_277 , void * V_314 , void * V_16 )
{
#ifdef F_126
const struct V_209 * V_19 = V_16 ;
struct V_279 * V_280 = F_61 ( V_277 ) ;
struct V_594 * V_595 ;
int V_596 = 0 ;
if ( ! F_127 ( V_597 ) )
return - V_598 ;
if ( V_19 -> V_206 . type == V_599 ) {
if ( V_280 -> V_592 == NULL )
return - V_298 ;
F_128 (sd, vfd->v4l2_dev)
if ( V_19 -> V_206 . V_208 == V_596 ++ )
return F_129 ( V_595 , V_600 , V_605 , V_19 ) ;
return - V_298 ;
}
if ( V_282 -> V_606 && V_19 -> V_206 . type == V_603 &&
( V_282 -> V_604 || V_19 -> V_206 . V_208 == 0 ) )
return V_282 -> V_606 ( V_277 , V_314 , V_19 ) ;
return - V_298 ;
#else
return - V_327 ;
#endif
}
static int F_131 ( const struct V_281 * V_282 ,
struct V_277 * V_277 , void * V_314 , void * V_16 )
{
#ifdef F_126
struct V_279 * V_280 = F_61 ( V_277 ) ;
struct V_205 * V_19 = V_16 ;
struct V_594 * V_595 ;
int V_596 = 0 ;
switch ( V_19 -> V_206 . type ) {
case V_603 :
if ( V_282 -> V_606 )
V_19 -> V_39 |= V_607 ;
if ( V_282 -> V_602 )
V_19 -> V_39 |= V_608 ;
F_5 ( V_19 -> V_14 , V_280 -> V_592 -> V_14 , sizeof( V_19 -> V_14 ) ) ;
if ( V_282 -> V_604 )
return V_282 -> V_604 ( V_277 , V_314 , V_16 ) ;
if ( V_19 -> V_206 . V_208 )
return - V_298 ;
return 0 ;
case V_599 :
if ( V_280 -> V_592 == NULL )
break;
F_128 (sd, vfd->v4l2_dev) {
if ( V_19 -> V_206 . V_208 != V_596 ++ )
continue;
if ( V_595 -> V_282 -> V_600 && V_595 -> V_282 -> V_600 -> V_605 )
V_19 -> V_39 |= V_607 ;
if ( V_595 -> V_282 -> V_600 && V_595 -> V_282 -> V_600 -> V_601 )
V_19 -> V_39 |= V_608 ;
F_5 ( V_19 -> V_14 , V_595 -> V_14 , sizeof( V_19 -> V_14 ) ) ;
return 0 ;
}
break;
}
return - V_298 ;
#else
return - V_327 ;
#endif
}
static int F_132 ( const struct V_281 * V_282 ,
struct V_277 * V_277 , void * V_314 , void * V_16 )
{
return F_133 ( V_314 , V_16 , V_277 -> V_609 & V_610 ) ;
}
static int F_134 ( const struct V_281 * V_282 ,
struct V_277 * V_277 , void * V_314 , void * V_16 )
{
return V_282 -> V_611 ( V_314 , V_16 ) ;
}
static int F_135 ( const struct V_281 * V_282 ,
struct V_277 * V_277 , void * V_314 , void * V_16 )
{
return V_282 -> V_612 ( V_314 , V_16 ) ;
}
static int F_136 ( const struct V_281 * V_282 ,
struct V_277 * V_277 , void * V_314 , void * V_16 )
{
struct V_266 * V_19 = V_16 ;
int V_316 = F_60 ( V_277 , V_19 -> type ) ;
if ( V_316 )
return V_316 ;
memset ( V_19 , 0 , F_63 ( struct V_266 , type ) ) ;
return V_282 -> V_613 ( V_277 , V_314 , V_19 ) ;
}
static int F_137 ( const struct V_281 * V_282 ,
struct V_277 * V_277 , void * V_314 , void * V_16 )
{
struct V_279 * V_280 = F_61 ( V_277 ) ;
struct V_267 * V_19 = V_16 ;
enum V_542 type ;
int V_531 ;
if ( V_280 -> V_285 == V_290 ) {
if ( V_19 -> type != V_540 && V_19 -> type != V_543 )
return - V_298 ;
type = V_19 -> type ;
} else {
type = ( V_280 -> V_285 == V_532 ) ?
V_533 : V_534 ;
if ( type != V_19 -> type )
return - V_298 ;
}
if ( V_282 -> V_614 ) {
V_531 = V_282 -> V_614 ( V_277 , V_314 , V_19 ) ;
if ( V_531 != - V_327 )
return V_531 ;
}
if ( F_75 ( V_280 , V_615 ) ) {
struct V_110 V_616 = {
. V_27 = V_19 -> V_29 ,
. type = type ,
} ;
if ( V_19 -> V_27 )
return - V_298 ;
V_531 = V_282 -> V_535 ( V_277 , V_314 , & V_616 ) ;
if ( V_531 )
return V_531 ;
V_19 -> V_35 = V_616 . V_35 | V_536 ;
V_19 -> V_108 = V_616 . V_108 ;
V_19 -> V_109 = V_616 . V_109 ;
V_19 -> V_268 = ( type == V_533 ) ?
V_617 : V_618 ;
return 0 ;
}
if ( F_75 ( V_280 , V_619 ) ) {
struct V_106 V_133 = {
. V_27 = V_19 -> V_29 ,
} ;
if ( type != V_533 )
return - V_298 ;
if ( V_19 -> V_27 )
return - V_298 ;
V_531 = V_282 -> V_538 ( V_277 , V_314 , & V_133 ) ;
if ( V_531 )
return V_531 ;
V_19 -> V_35 = V_133 . V_35 | V_536 ;
V_19 -> V_108 = V_133 . V_108 ;
V_19 -> V_109 = V_133 . V_109 ;
V_19 -> V_268 = ( type == V_533 ) ?
V_617 : V_618 ;
return 0 ;
}
return - V_327 ;
}
bool F_138 ( unsigned int V_198 )
{
if ( F_139 ( V_198 ) >= V_620 )
return false ;
return V_621 [ F_139 ( V_198 ) ] . V_622 == V_198 ;
}
struct V_623 * F_140 ( struct V_279 * V_624 , unsigned V_198 )
{
if ( F_139 ( V_198 ) >= V_620 )
return V_624 -> V_625 ;
if ( F_72 ( F_139 ( V_198 ) , V_624 -> V_626 ) )
return NULL ;
if ( V_624 -> V_627 && V_624 -> V_627 -> V_625 &&
( V_621 [ F_139 ( V_198 ) ] . V_39 & V_628 ) )
return V_624 -> V_627 -> V_625 ;
return V_624 -> V_625 ;
}
void F_141 ( const char * V_629 , unsigned int V_198 )
{
const char * V_630 , * type ;
if ( V_629 )
F_15 ( V_74 L_245 , V_629 ) ;
switch ( F_142 ( V_198 ) ) {
case 'd' :
type = L_246 ;
break;
case 'V' :
if ( F_139 ( V_198 ) >= V_620 ) {
type = L_247 ;
break;
}
F_7 ( L_248 , V_621 [ F_139 ( V_198 ) ] . V_14 ) ;
return;
default:
type = L_249 ;
break;
}
switch ( F_143 ( V_198 ) ) {
case V_631 : V_630 = L_250 ; break;
case V_632 : V_630 = L_251 ; break;
case V_633 : V_630 = L_252 ; break;
case V_632 | V_633 : V_630 = L_253 ; break;
default: V_630 = L_254 ; break;
}
F_7 ( L_255 ,
type , F_142 ( V_198 ) , V_630 , F_139 ( V_198 ) , V_198 ) ;
}
static long F_144 ( struct V_277 * V_277 ,
unsigned int V_198 , void * V_16 )
{
struct V_279 * V_280 = F_61 ( V_277 ) ;
const struct V_281 * V_282 = V_280 -> V_283 ;
bool V_17 = false ;
struct V_634 V_635 ;
const struct V_634 * V_636 ;
void * V_314 = V_277 -> V_328 ;
struct V_324 * V_325 = NULL ;
int V_637 = V_280 -> V_637 ;
long V_316 = - V_327 ;
if ( V_282 == NULL ) {
F_145 ( L_256 ,
F_146 ( V_280 ) ) ;
return V_316 ;
}
if ( F_72 ( V_326 , & V_280 -> V_39 ) )
V_325 = V_277 -> V_328 ;
if ( F_138 ( V_198 ) ) {
V_636 = & V_621 [ F_139 ( V_198 ) ] ;
if ( ! F_72 ( F_139 ( V_198 ) , V_280 -> V_638 ) &&
! ( ( V_636 -> V_39 & V_639 ) && V_325 && V_325 -> V_568 ) )
goto V_640;
if ( V_325 && ( V_636 -> V_39 & V_641 ) ) {
V_316 = F_147 ( V_280 -> V_323 , V_325 -> V_323 ) ;
if ( V_316 )
goto V_640;
}
} else {
V_635 . V_622 = V_198 ;
V_635 . V_39 = 0 ;
V_635 . V_642 = F_57 ;
V_636 = & V_635 ;
}
V_17 = F_143 ( V_198 ) == V_633 ;
if ( V_636 -> V_39 & V_643 ) {
typedef int (* F_148)( struct V_277 * V_277 , void * V_314 , void * V_19 );
const void * V_19 = V_280 -> V_283 ;
const F_148 * V_644 = V_19 + V_636 -> V_256 . V_89 ;
V_316 = (* V_644)( V_277 , V_314 , V_16 ) ;
} else if ( V_636 -> V_39 & V_645 ) {
V_316 = V_636 -> V_256 . V_646 ( V_282 , V_277 , V_314 , V_16 ) ;
} else if ( ! V_282 -> V_647 ) {
V_316 = - V_327 ;
} else {
V_316 = V_282 -> V_647 ( V_277 , V_314 ,
V_325 ? F_147 ( V_280 -> V_323 , V_325 -> V_323 ) >= 0 : 0 ,
V_198 , V_16 ) ;
}
V_640:
if ( V_637 & ( V_648 | V_649 ) ) {
if ( ! ( V_637 & V_650 ) &&
( V_198 == V_651 || V_198 == V_652 ) )
return V_316 ;
F_141 ( F_146 ( V_280 ) , V_198 ) ;
if ( V_316 < 0 )
F_7 ( L_257 , V_316 ) ;
if ( ! ( V_637 & V_649 ) )
F_7 ( L_30 ) ;
else if ( F_143 ( V_198 ) == V_631 )
V_636 -> V_642 ( V_16 , V_17 ) ;
else {
F_7 ( L_258 ) ;
V_636 -> V_642 ( V_16 , V_17 ) ;
}
}
return V_316 ;
}
static int F_149 ( unsigned int V_198 , void * V_653 , T_4 * V_654 ,
void T_3 * * V_655 , void * * * V_656 )
{
int V_316 = 0 ;
switch ( V_198 ) {
case V_657 :
case V_658 :
case V_651 :
case V_652 : {
struct V_123 * V_659 = V_653 ;
if ( F_26 ( V_659 -> type ) && V_659 -> V_135 > 0 ) {
if ( V_659 -> V_135 > V_660 ) {
V_316 = - V_298 ;
break;
}
* V_655 = ( void T_3 * ) V_659 -> V_133 . V_134 ;
* V_656 = ( void * * ) & V_659 -> V_133 . V_134 ;
* V_654 = sizeof( struct V_127 ) * V_659 -> V_135 ;
V_316 = 1 ;
}
break;
}
case V_661 :
case V_662 : {
struct V_269 * V_663 = V_653 ;
if ( V_663 -> V_272 ) {
if ( V_663 -> V_272 > 256 ) {
V_316 = - V_298 ;
break;
}
* V_655 = ( void T_3 * ) V_663 -> V_663 ;
* V_656 = ( void * * ) & V_663 -> V_663 ;
* V_654 = V_663 -> V_272 * 128 ;
V_316 = 1 ;
}
break;
}
case V_664 :
case V_665 :
case V_666 : {
struct V_175 * V_572 = V_653 ;
if ( V_572 -> V_93 != 0 ) {
if ( V_572 -> V_93 > V_667 ) {
V_316 = - V_298 ;
break;
}
* V_655 = ( void T_3 * ) V_572 -> V_178 ;
* V_656 = ( void * * ) & V_572 -> V_178 ;
* V_654 = sizeof( struct V_573 )
* V_572 -> V_93 ;
V_316 = 1 ;
}
break;
}
}
return V_316 ;
}
long
F_150 ( struct V_277 * V_277 , unsigned int V_198 , unsigned long V_16 ,
T_5 V_646 )
{
char V_668 [ 128 ] ;
void * V_669 = NULL ;
void * V_653 = ( void * ) V_16 ;
long V_531 = - V_298 ;
bool V_670 ;
T_4 V_654 = 0 ;
void T_3 * V_655 = NULL ;
void * * V_656 = NULL ;
if ( F_143 ( V_198 ) != V_631 ) {
if ( F_151 ( V_198 ) <= sizeof( V_668 ) ) {
V_653 = V_668 ;
} else {
V_669 = F_152 ( F_151 ( V_198 ) , V_671 ) ;
if ( NULL == V_669 )
return - V_672 ;
V_653 = V_669 ;
}
V_531 = - V_673 ;
if ( F_143 ( V_198 ) & V_633 ) {
unsigned int V_674 = F_151 ( V_198 ) ;
if ( F_138 ( V_198 ) ) {
T_2 V_39 = V_621 [ F_139 ( V_198 ) ] . V_39 ;
if ( V_39 & V_675 )
V_674 = ( V_39 & V_675 ) >> 16 ;
}
if ( F_153 ( V_653 , ( void T_3 * ) V_16 , V_674 ) )
goto V_676;
if ( V_674 < F_151 ( V_198 ) )
memset ( ( V_677 * ) V_653 + V_674 , 0 , F_151 ( V_198 ) - V_674 ) ;
} else {
memset ( V_653 , 0 , F_151 ( V_198 ) ) ;
}
}
V_531 = F_149 ( V_198 , V_653 , & V_654 , & V_655 , & V_656 ) ;
if ( V_531 < 0 )
goto V_676;
V_670 = V_531 ;
if ( V_670 ) {
V_669 = F_152 ( V_654 , V_671 ) ;
V_531 = - V_672 ;
if ( NULL == V_669 )
goto V_678;
V_531 = - V_673 ;
if ( F_153 ( V_669 , V_655 , V_654 ) )
goto V_678;
* V_656 = V_669 ;
}
V_531 = V_646 ( V_277 , V_198 , V_653 ) ;
if ( V_531 == - V_587 )
V_531 = - V_327 ;
if ( V_531 == 0 ) {
if ( V_198 == V_652 )
F_154 ( F_61 ( V_277 ) -> V_679 , V_653 ) ;
else if ( V_198 == V_651 )
F_155 ( F_61 ( V_277 ) -> V_679 , V_653 ) ;
}
if ( V_670 ) {
* V_656 = ( void V_680 * ) V_655 ;
if ( F_156 ( V_655 , V_669 , V_654 ) )
V_531 = - V_673 ;
goto V_678;
}
if ( V_531 < 0 && V_198 != V_681 )
goto V_676;
V_678:
switch ( F_143 ( V_198 ) ) {
case V_632 :
case ( V_633 | V_632 ) :
if ( F_156 ( ( void T_3 * ) V_16 , V_653 , F_151 ( V_198 ) ) )
V_531 = - V_673 ;
break;
}
V_676:
F_157 ( V_669 ) ;
return V_531 ;
}
long F_158 ( struct V_277 * V_277 ,
unsigned int V_198 , unsigned long V_16 )
{
return F_150 ( V_277 , V_198 , V_16 , F_144 ) ;
}
