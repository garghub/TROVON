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
F_7 ( L_1
L_2 ,
( int ) sizeof( V_19 -> V_20 ) , V_19 -> V_20 ,
( int ) sizeof( V_19 -> V_21 ) , V_19 -> V_21 ,
( int ) sizeof( V_19 -> V_22 ) , V_19 -> V_22 ,
V_19 -> V_23 , V_19 -> V_24 , V_19 -> V_25 ) ;
}
static void F_8 ( const void * V_16 , bool V_17 )
{
const struct V_26 * V_19 = V_16 ;
F_7 ( L_3
L_4 ,
V_19 -> V_27 , ( int ) sizeof( V_19 -> V_14 ) , V_19 -> V_14 , V_19 -> type , V_19 -> V_28 ,
V_19 -> V_29 , ( unsigned long long ) V_19 -> V_5 , V_19 -> V_30 ,
V_19 -> V_24 ) ;
}
static void F_9 ( const void * V_16 , bool V_17 )
{
const struct V_31 * V_19 = V_16 ;
F_7 ( L_5
L_6 ,
V_19 -> V_27 , ( int ) sizeof( V_19 -> V_14 ) , V_19 -> V_14 , V_19 -> type , V_19 -> V_28 ,
V_19 -> V_32 , ( unsigned long long ) V_19 -> V_5 , V_19 -> V_24 ) ;
}
static void F_10 ( const void * V_16 , bool V_17 )
{
const struct V_33 * V_19 = V_16 ;
if ( V_17 )
F_7 ( L_7 , V_19 -> V_27 , V_19 -> V_34 ) ;
else
F_7 ( L_8 ,
V_19 -> V_27 , ( int ) sizeof( V_19 -> V_14 ) , V_19 -> V_14 ,
V_19 -> V_35 , V_19 -> V_34 ) ;
}
static void F_11 ( const void * V_16 , bool V_17 )
{
const struct V_36 * V_19 = V_16 ;
if ( V_17 )
F_7 ( L_9 , V_19 -> V_27 ) ;
else
F_7 ( L_8 ,
V_19 -> V_27 , ( int ) sizeof( V_19 -> V_14 ) , V_19 -> V_14 ,
V_19 -> V_35 , V_19 -> V_34 ) ;
}
static void F_12 ( const void * V_16 , bool V_17 )
{
const struct V_37 * V_19 = V_16 ;
F_7 ( L_10 ,
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
unsigned V_3 ;
F_7 ( L_11 , F_13 ( V_19 -> type , V_38 ) ) ;
switch ( V_19 -> type ) {
case V_55 :
case V_56 :
V_44 = & V_19 -> V_57 . V_44 ;
F_7 ( L_12
L_13
L_14 ,
V_44 -> V_58 , V_44 -> V_59 ,
( V_44 -> V_40 & 0xff ) ,
( V_44 -> V_40 >> 8 ) & 0xff ,
( V_44 -> V_40 >> 16 ) & 0xff ,
( V_44 -> V_40 >> 24 ) & 0xff ,
F_13 ( V_44 -> V_60 , V_61 ) ,
V_44 -> V_62 , V_44 -> V_63 ,
V_44 -> V_64 ) ;
break;
case V_65 :
case V_66 :
V_46 = & V_19 -> V_57 . V_67 ;
F_7 ( L_12
L_15
L_16 ,
V_46 -> V_58 , V_46 -> V_59 ,
( V_46 -> V_40 & 0xff ) ,
( V_46 -> V_40 >> 8 ) & 0xff ,
( V_46 -> V_40 >> 16 ) & 0xff ,
( V_46 -> V_40 >> 24 ) & 0xff ,
F_13 ( V_46 -> V_60 , V_61 ) ,
V_46 -> V_64 , V_46 -> V_68 ) ;
for ( V_3 = 0 ; V_3 < V_46 -> V_68 ; V_3 ++ )
F_15 ( V_69 L_17 , V_3 ,
V_46 -> V_70 [ V_3 ] . V_62 ,
V_46 -> V_70 [ V_3 ] . V_63 ) ;
break;
case V_71 :
case V_72 :
V_52 = & V_19 -> V_57 . V_52 ;
F_7 ( L_18 ,
V_52 -> V_73 . V_58 , V_52 -> V_73 . V_59 , V_52 -> V_73 . V_74 , V_52 -> V_73 . V_75 ,
F_13 ( V_52 -> V_60 , V_61 ) ,
V_52 -> V_76 , V_52 -> V_77 , V_52 -> V_78 ,
V_52 -> V_79 , V_52 -> V_80 ) ;
break;
case V_81 :
case V_82 :
V_48 = & V_19 -> V_57 . V_48 ;
F_7 ( L_19
L_20 ,
V_48 -> V_83 , V_48 -> V_84 ,
V_48 -> V_85 ,
( V_48 -> V_86 & 0xff ) ,
( V_48 -> V_86 >> 8 ) & 0xff ,
( V_48 -> V_86 >> 16 ) & 0xff ,
( V_48 -> V_86 >> 24 ) & 0xff ,
V_48 -> V_87 [ 0 ] , V_48 -> V_87 [ 1 ] ,
V_48 -> V_88 [ 0 ] , V_48 -> V_88 [ 1 ] ) ;
break;
case V_89 :
case V_90 :
V_50 = & V_19 -> V_57 . V_50 ;
F_7 ( L_21 ,
V_50 -> V_91 , V_50 -> V_92 ) ;
for ( V_3 = 0 ; V_3 < 24 ; V_3 ++ )
F_15 ( V_69 L_22 , V_3 ,
V_50 -> V_93 [ 0 ] [ V_3 ] ,
V_50 -> V_93 [ 1 ] [ V_3 ] ) ;
break;
case V_94 :
V_54 = & V_19 -> V_57 . V_54 ;
F_7 ( L_23 ,
( V_54 -> V_40 >> 0 ) & 0xff ,
( V_54 -> V_40 >> 8 ) & 0xff ,
( V_54 -> V_40 >> 16 ) & 0xff ,
( V_54 -> V_40 >> 24 ) & 0xff ) ;
break;
}
}
static void F_16 ( const void * V_16 , bool V_17 )
{
const struct V_95 * V_19 = V_16 ;
F_7 ( L_24
L_25
L_14 ,
V_19 -> V_35 , V_19 -> V_39 , V_19 -> V_96 ,
V_19 -> V_57 . V_58 , V_19 -> V_57 . V_59 ,
( V_19 -> V_57 . V_40 & 0xff ) ,
( V_19 -> V_57 . V_40 >> 8 ) & 0xff ,
( V_19 -> V_57 . V_40 >> 16 ) & 0xff ,
( V_19 -> V_57 . V_40 >> 24 ) & 0xff ,
V_19 -> V_57 . V_62 , V_19 -> V_57 . V_63 ,
V_19 -> V_57 . V_64 ) ;
}
static void F_17 ( const void * V_16 , bool V_17 )
{
F_7 ( L_26 , F_13 ( * ( T_2 * ) V_16 , V_38 ) ) ;
}
static void F_18 ( const void * V_16 , bool V_17 )
{
const struct V_97 * V_19 = V_16 ;
if ( V_17 )
F_7 ( L_27 , V_19 -> V_27 , V_19 -> V_98 ) ;
else
F_7 ( L_28
L_29 ,
V_19 -> V_27 , ( int ) sizeof( V_19 -> V_14 ) , V_19 -> V_14 , V_19 -> V_35 ,
V_19 -> V_99 , V_19 -> V_100 , V_19 -> V_98 ) ;
}
static void F_19 ( const void * V_16 , bool V_17 )
{
const struct V_101 * V_19 = V_16 ;
if ( V_17 )
F_7 ( L_30 , V_19 -> V_27 , V_19 -> V_102 ) ;
else
F_7 ( L_31
L_32
L_33 ,
V_19 -> V_27 , ( int ) sizeof( V_19 -> V_14 ) , V_19 -> V_14 , V_19 -> type ,
V_19 -> V_35 , V_19 -> V_99 ,
V_19 -> V_100 , V_19 -> signal , V_19 -> V_103 ,
V_19 -> V_104 , V_19 -> V_102 ) ;
}
static void F_20 ( const void * V_16 , bool V_17 )
{
const struct V_105 * V_19 = V_16 ;
F_7 ( L_34 ,
V_19 -> V_29 , V_19 -> type , V_19 -> V_106 ) ;
}
static void F_21 ( const void * V_16 , bool V_17 )
{
const struct V_12 * V_19 = V_16 ;
F_7 ( L_35
L_36 , V_19 -> V_27 ,
( unsigned long long ) V_19 -> V_1 , ( int ) sizeof( V_19 -> V_14 ) , V_19 -> V_14 ,
V_19 -> V_8 . V_10 ,
V_19 -> V_8 . V_11 ,
V_19 -> V_15 ) ;
}
static void F_22 ( const void * V_16 , bool V_17 )
{
F_7 ( L_37 , * ( const long long unsigned * ) V_16 ) ;
}
static void F_23 ( const void * V_16 , bool V_17 )
{
const struct V_107 * V_19 = V_16 ;
F_7 ( L_38
L_39 ,
V_19 -> V_29 , V_19 -> type , V_19 -> V_108 , V_19 -> V_109 , V_19 -> V_110 ,
V_19 -> V_99 , V_19 -> V_100 ) ;
}
static void F_24 ( const void * V_16 , bool V_17 )
{
const struct V_111 * V_19 = V_16 ;
F_7 ( L_40 ,
V_19 -> V_88 ,
F_13 ( V_19 -> type , V_38 ) ,
F_13 ( V_19 -> V_112 , V_113 ) ) ;
}
static void F_25 ( const void * V_16 , bool V_17 )
{
const struct V_114 * V_19 = V_16 ;
const struct V_115 * V_116 = & V_19 -> V_117 ;
const struct V_118 * V_119 ;
int V_3 ;
F_7 ( L_41
L_42 ,
V_19 -> V_120 . V_121 / 3600 ,
( int ) ( V_19 -> V_120 . V_121 / 60 ) % 60 ,
( int ) ( V_19 -> V_120 . V_121 % 60 ) ,
( long ) V_19 -> V_120 . V_122 ,
V_19 -> V_27 ,
F_13 ( V_19 -> type , V_38 ) ,
V_19 -> V_39 , F_13 ( V_19 -> V_60 , V_61 ) ,
V_19 -> V_123 , F_13 ( V_19 -> V_112 , V_113 ) ) ;
if ( F_26 ( V_19 -> type ) && V_19 -> V_124 . V_125 ) {
F_7 ( L_43 ) ;
for ( V_3 = 0 ; V_3 < V_19 -> V_126 ; ++ V_3 ) {
V_119 = & V_19 -> V_124 . V_125 [ V_3 ] ;
F_15 ( V_69
L_44
L_45 ,
V_3 , V_119 -> V_127 , V_119 -> V_128 ,
V_119 -> V_124 . V_129 , V_119 -> V_126 ) ;
}
} else {
F_7 ( L_46 ,
V_19 -> V_127 , V_19 -> V_124 . V_129 , V_19 -> V_126 ) ;
}
F_15 ( V_69 L_47
L_48 ,
V_116 -> V_130 , V_116 -> V_131 , V_116 -> V_132 ,
V_116 -> type , V_116 -> V_39 , V_116 -> V_133 , * ( V_134 * ) V_116 -> V_135 ) ;
}
static void F_27 ( const void * V_16 , bool V_17 )
{
const struct V_136 * V_19 = V_16 ;
F_7 ( L_49 ,
V_19 -> V_137 , F_13 ( V_19 -> type , V_38 ) ,
V_19 -> V_27 , V_19 -> V_119 , V_19 -> V_39 ) ;
}
static void F_28 ( const void * V_16 , bool V_17 )
{
const struct V_138 * V_19 = V_16 ;
F_7 ( L_50 ,
V_19 -> V_27 , V_19 -> V_88 ,
F_13 ( V_19 -> V_112 , V_113 ) ) ;
F_14 ( & V_19 -> V_139 , V_17 ) ;
}
static void F_29 ( const void * V_16 , bool V_17 )
{
const struct V_140 * V_19 = V_16 ;
F_7 ( L_11 , F_13 ( V_19 -> type , V_38 ) ) ;
if ( V_19 -> type == V_55 ||
V_19 -> type == V_65 ) {
const struct V_141 * V_142 = & V_19 -> V_143 . V_144 ;
F_7 ( L_51
L_52 ,
V_142 -> V_35 , V_142 -> V_145 ,
V_142 -> V_146 . V_10 , V_142 -> V_146 . V_11 ,
V_142 -> V_147 , V_142 -> V_148 ) ;
} else if ( V_19 -> type == V_56 ||
V_19 -> type == V_66 ) {
const struct V_149 * V_142 = & V_19 -> V_143 . V_150 ;
F_7 ( L_53
L_54 ,
V_142 -> V_35 , V_142 -> V_151 ,
V_142 -> V_146 . V_10 , V_142 -> V_146 . V_11 ,
V_142 -> V_147 , V_142 -> V_152 ) ;
} else {
F_7 ( L_43 ) ;
}
}
static void F_30 ( const void * V_16 , bool V_17 )
{
const struct V_153 * V_19 = V_16 ;
F_7 ( L_55
L_56 ,
V_19 -> V_1 , V_19 -> type , ( int ) sizeof( V_19 -> V_14 ) , V_19 -> V_14 ,
V_19 -> V_154 , V_19 -> V_155 ,
V_19 -> V_156 , V_19 -> V_157 , V_19 -> V_39 ) ;
}
static void F_31 ( const void * V_16 , bool V_17 )
{
const struct V_158 * V_19 = V_16 ;
F_7 ( L_57 , V_19 -> V_1 , V_19 -> V_27 ) ;
}
static void F_32 ( const void * V_16 , bool V_17 )
{
const struct V_159 * V_19 = V_16 ;
F_7 ( L_58 , V_19 -> V_1 , V_19 -> V_160 ) ;
}
static void F_33 ( const void * V_16 , bool V_17 )
{
const struct V_161 * V_19 = V_16 ;
int V_3 ;
F_7 ( L_59 ,
V_19 -> V_162 , V_19 -> V_88 , V_19 -> V_163 ) ;
for ( V_3 = 0 ; V_3 < V_19 -> V_88 ; V_3 ++ ) {
if ( V_19 -> V_164 [ V_3 ] . V_165 )
F_7 ( L_60 ,
V_19 -> V_164 [ V_3 ] . V_1 , V_19 -> V_164 [ V_3 ] . V_160 ) ;
else
F_7 ( L_61 ,
V_19 -> V_164 [ V_3 ] . V_1 , V_19 -> V_164 [ V_3 ] . V_165 ) ;
}
F_7 ( L_43 ) ;
}
static void F_34 ( const void * V_16 , bool V_17 )
{
const struct V_166 * V_19 = V_16 ;
F_7 ( L_62
L_63
L_64 ,
F_13 ( V_19 -> type , V_38 ) ,
V_19 -> V_167 . V_58 , V_19 -> V_167 . V_59 ,
V_19 -> V_167 . V_74 , V_19 -> V_167 . V_75 ,
V_19 -> V_168 . V_58 , V_19 -> V_168 . V_59 ,
V_19 -> V_168 . V_74 , V_19 -> V_168 . V_75 ,
V_19 -> V_169 . V_10 , V_19 -> V_169 . V_11 ) ;
}
static void F_35 ( const void * V_16 , bool V_17 )
{
const struct V_170 * V_19 = V_16 ;
F_7 ( L_65 ,
F_13 ( V_19 -> type , V_38 ) ,
V_19 -> V_142 . V_58 , V_19 -> V_142 . V_59 ,
V_19 -> V_142 . V_74 , V_19 -> V_142 . V_75 ) ;
}
static void F_36 ( const void * V_16 , bool V_17 )
{
const struct V_171 * V_19 = V_16 ;
F_7 ( L_66 ,
F_13 ( V_19 -> type , V_38 ) ,
V_19 -> V_172 , V_19 -> V_39 ,
V_19 -> V_173 . V_58 , V_19 -> V_173 . V_59 , V_19 -> V_173 . V_74 , V_19 -> V_173 . V_75 ) ;
}
static void F_37 ( const void * V_16 , bool V_17 )
{
const struct V_174 * V_19 = V_16 ;
F_7 ( L_67
L_68 ,
V_19 -> V_175 , V_19 -> V_176 , V_19 -> V_177 ,
V_19 -> V_178 , V_19 -> V_179 ) ;
}
static void F_38 ( const void * V_16 , bool V_17 )
{
const struct V_180 * V_19 = V_16 ;
F_7 ( L_69 ,
V_19 -> V_181 , V_19 -> V_182 ) ;
}
static void F_39 ( const void * V_16 , bool V_17 )
{
const struct V_183 * V_19 = V_16 ;
F_7 ( L_70 ,
V_19 -> V_184 , V_19 -> V_39 ) ;
}
static void F_40 ( const void * V_16 , bool V_17 )
{
const struct V_185 * V_19 = V_16 ;
F_7 ( L_70 , V_19 -> V_184 , V_19 -> V_39 ) ;
if ( V_19 -> V_184 == V_186 )
F_41 ( L_71 ,
V_19 -> V_87 . V_187 , V_19 -> V_87 . V_139 ) ;
else if ( V_19 -> V_184 == V_188 )
F_41 ( L_72 , V_19 -> V_189 . V_190 ) ;
}
static void F_42 ( const void * V_16 , bool V_17 )
{
const struct V_191 * V_19 = V_16 ;
F_7 ( L_73 , V_19 -> V_192 . type ) ;
if ( V_19 -> V_192 . type == V_193 )
F_7 ( L_74 ,
( int ) sizeof( V_19 -> V_192 . V_14 ) , V_19 -> V_192 . V_14 ) ;
else
F_7 ( L_75 , V_19 -> V_192 . V_194 ) ;
F_7 ( L_76 , ( int ) sizeof( V_19 -> V_14 ) , V_19 -> V_14 ) ;
}
static void F_43 ( const void * V_16 , bool V_17 )
{
const struct V_195 * V_19 = V_16 ;
F_7 ( L_73 , V_19 -> V_192 . type ) ;
if ( V_19 -> V_192 . type == V_193 )
F_7 ( L_74 ,
( int ) sizeof( V_19 -> V_192 . V_14 ) , V_19 -> V_192 . V_14 ) ;
else
F_7 ( L_75 , V_19 -> V_192 . V_194 ) ;
F_7 ( L_77 ,
V_19 -> V_196 , V_19 -> V_197 ) ;
}
static void F_44 ( const void * V_16 , bool V_17 )
{
const struct V_198 * V_19 = V_16 ;
switch ( V_19 -> type ) {
case V_199 :
F_7 ( L_78
L_79
L_80
L_81
L_82
L_83
L_84
L_85 ,
V_19 -> V_200 . V_201 , V_19 -> V_200 . V_202 ,
V_19 -> V_200 . V_58 , V_19 -> V_200 . V_59 ,
V_19 -> V_200 . V_203 , V_19 -> V_200 . V_204 ,
V_19 -> V_200 . V_205 , V_19 -> V_200 . V_206 ,
V_19 -> V_200 . V_207 , V_19 -> V_200 . V_208 ,
V_19 -> V_200 . V_209 , V_19 -> V_200 . V_210 ,
V_19 -> V_200 . V_211 , V_19 -> V_200 . V_212 ,
V_19 -> V_200 . V_4 , V_19 -> V_200 . V_39 ) ;
break;
default:
F_7 ( L_86 , V_19 -> type ) ;
break;
}
}
static void F_45 ( const void * V_16 , bool V_17 )
{
const struct V_213 * V_19 = V_16 ;
F_7 ( L_87 , V_19 -> V_27 ) ;
F_44 ( & V_19 -> V_214 , V_17 ) ;
}
static void F_46 ( const void * V_16 , bool V_17 )
{
const struct V_215 * V_19 = V_16 ;
switch ( V_19 -> type ) {
case V_199 :
F_7 ( L_88
L_89 ,
V_19 -> V_200 . V_216 , V_19 -> V_200 . V_217 ,
V_19 -> V_200 . V_218 , V_19 -> V_200 . V_219 ,
V_19 -> V_200 . V_220 , V_19 -> V_200 . V_221 ,
V_19 -> V_200 . V_4 , V_19 -> V_200 . V_24 ) ;
break;
default:
F_7 ( L_90 , V_19 -> type ) ;
break;
}
}
static void F_47 ( const void * V_16 , bool V_17 )
{
const struct V_222 * V_19 = V_16 ;
F_7 ( L_91 ,
V_19 -> V_27 ,
( V_19 -> V_223 & 0xff ) ,
( V_19 -> V_223 >> 8 ) & 0xff ,
( V_19 -> V_223 >> 16 ) & 0xff ,
( V_19 -> V_223 >> 24 ) & 0xff ,
V_19 -> type ) ;
switch ( V_19 -> type ) {
case V_224 :
F_7 ( L_92 ,
V_19 -> V_225 . V_58 , V_19 -> V_225 . V_59 ) ;
break;
case V_226 :
F_7 ( L_93 ,
V_19 -> V_227 . V_216 , V_19 -> V_227 . V_218 ,
V_19 -> V_227 . V_228 , V_19 -> V_227 . V_229 ,
V_19 -> V_227 . V_217 , V_19 -> V_227 . V_219 ) ;
break;
case V_230 :
default:
F_7 ( L_43 ) ;
break;
}
}
static void F_48 ( const void * V_16 , bool V_17 )
{
const struct V_231 * V_19 = V_16 ;
F_7 ( L_94 ,
V_19 -> V_27 ,
( V_19 -> V_223 & 0xff ) ,
( V_19 -> V_223 >> 8 ) & 0xff ,
( V_19 -> V_223 >> 16 ) & 0xff ,
( V_19 -> V_223 >> 24 ) & 0xff ,
V_19 -> V_58 , V_19 -> V_59 , V_19 -> type ) ;
switch ( V_19 -> type ) {
case V_232 :
F_7 ( L_95 ,
V_19 -> V_225 . V_10 ,
V_19 -> V_225 . V_11 ) ;
break;
case V_233 :
F_7 ( L_96 ,
V_19 -> V_227 . V_234 . V_10 ,
V_19 -> V_227 . V_234 . V_11 ,
V_19 -> V_227 . V_235 . V_10 ,
V_19 -> V_227 . V_235 . V_11 ,
V_19 -> V_227 . V_156 . V_10 ,
V_19 -> V_227 . V_156 . V_11 ) ;
break;
case V_236 :
default:
F_7 ( L_43 ) ;
break;
}
}
static void F_49 ( const void * V_16 , bool V_17 )
{
const struct V_237 * V_19 = V_16 ;
const struct V_238 * V_142 ;
F_7 ( L_97
L_98 ,
V_19 -> type , V_19 -> V_239 , V_19 -> V_123 , V_19 -> V_1 ,
V_19 -> V_120 . V_121 , V_19 -> V_120 . V_240 ) ;
switch ( V_19 -> type ) {
case V_241 :
F_15 ( V_69 L_99 ,
F_13 ( V_19 -> V_242 . V_208 . V_60 , V_61 ) ) ;
break;
case V_243 :
V_142 = & V_19 -> V_242 . V_244 ;
F_15 ( V_69 L_100 ,
V_142 -> V_245 , V_142 -> type ) ;
if ( V_142 -> type == V_246 )
F_7 ( L_101 , V_142 -> V_247 ) ;
else
F_7 ( L_102 , V_142 -> V_160 ) ;
F_7 ( L_103
L_104 ,
V_142 -> V_39 , V_142 -> V_154 , V_142 -> V_155 ,
V_142 -> V_156 , V_142 -> V_157 ) ;
break;
case V_248 :
F_7 ( L_105 ,
V_19 -> V_242 . V_249 . V_250 ) ;
break;
}
}
static void F_50 ( const void * V_16 , bool V_17 )
{
const struct V_251 * V_19 = V_16 ;
F_7 ( L_106 ,
V_19 -> type , V_19 -> V_1 , V_19 -> V_39 ) ;
}
static void F_51 ( const void * V_16 , bool V_17 )
{
const struct V_252 * V_19 = V_16 ;
int V_3 ;
F_7 ( L_107 ,
F_13 ( V_19 -> type , V_38 ) , V_19 -> V_91 ) ;
for ( V_3 = 0 ; V_3 < 24 ; V_3 ++ )
F_15 ( V_69 L_22 , V_3 ,
V_19 -> V_93 [ 0 ] [ V_3 ] ,
V_19 -> V_93 [ 1 ] [ V_3 ] ) ;
}
static void F_52 ( const void * V_16 , bool V_17 )
{
const struct V_253 * V_19 = V_16 ;
F_7 ( L_108
L_109 ,
V_19 -> V_29 , V_19 -> type , V_19 -> V_27 ,
V_19 -> V_35 , V_19 -> V_99 ,
V_19 -> V_100 , V_19 -> V_254 ) ;
}
static void F_53 ( const void * V_16 , bool V_17 )
{
const struct V_255 * V_19 = V_16 ;
F_7 ( L_110 ,
V_19 -> V_256 , V_19 -> V_257 , V_19 -> V_258 ) ;
}
static void F_54 ( const void * V_16 , bool V_17 )
{
F_7 ( L_111 , * ( const T_2 * ) V_16 ) ;
}
static void F_55 ( const void * V_16 , bool V_17 )
{
F_7 ( L_43 ) ;
}
static void F_56 ( const void * V_16 , bool V_17 )
{
F_7 ( L_112 ) ;
}
static int F_57 ( struct V_161 * V_142 , int V_259 )
{
V_134 V_3 ;
V_142 -> V_260 [ 0 ] = V_142 -> V_260 [ 1 ] = 0 ;
for ( V_3 = 0 ; V_3 < V_142 -> V_88 ; V_3 ++ )
V_142 -> V_164 [ V_3 ] . V_261 [ 0 ] = 0 ;
if ( ! V_259 && V_142 -> V_162 == V_262 )
return 0 ;
for ( V_3 = 0 ; V_3 < V_142 -> V_88 ; V_3 ++ ) {
if ( F_58 ( V_142 -> V_164 [ V_3 ] . V_1 ) != V_142 -> V_162 ) {
V_142 -> V_163 = V_3 ;
return 0 ;
}
}
return 1 ;
}
static int F_59 ( struct V_263 * V_263 , enum V_264 type )
{
struct V_265 * V_266 = F_60 ( V_263 ) ;
const struct V_267 * V_268 = V_266 -> V_269 ;
bool V_270 = V_266 -> V_271 == V_272 ;
bool V_273 = V_266 -> V_271 == V_274 ;
bool V_275 = V_266 -> V_271 == V_276 ;
bool V_277 = V_266 -> V_278 != V_279 ;
bool V_280 = V_266 -> V_278 != V_281 ;
if ( V_268 == NULL )
return - V_282 ;
switch ( type ) {
case V_55 :
if ( V_270 && V_277 &&
( V_268 -> V_283 || V_268 -> V_284 ) )
return 0 ;
break;
case V_65 :
if ( V_270 && V_277 && V_268 -> V_284 )
return 0 ;
break;
case V_71 :
if ( V_270 && V_277 && V_268 -> V_285 )
return 0 ;
break;
case V_56 :
if ( V_270 && V_280 &&
( V_268 -> V_286 || V_268 -> V_287 ) )
return 0 ;
break;
case V_66 :
if ( V_270 && V_280 && V_268 -> V_287 )
return 0 ;
break;
case V_72 :
if ( V_270 && V_280 && V_268 -> V_288 )
return 0 ;
break;
case V_81 :
if ( V_273 && V_277 && V_268 -> V_289 )
return 0 ;
break;
case V_82 :
if ( V_273 && V_280 && V_268 -> V_290 )
return 0 ;
break;
case V_89 :
if ( V_273 && V_277 && V_268 -> V_291 )
return 0 ;
break;
case V_90 :
if ( V_273 && V_280 && V_268 -> V_292 )
return 0 ;
break;
case V_94 :
if ( V_275 && V_277 && V_268 -> V_293 )
return 0 ;
break;
default:
break;
}
return - V_282 ;
}
static int F_61 ( const struct V_267 * V_268 ,
struct V_263 * V_263 , void * V_294 , void * V_16 )
{
struct V_18 * V_295 = (struct V_18 * ) V_16 ;
V_295 -> V_23 = V_296 ;
return V_268 -> V_297 ( V_263 , V_294 , V_295 ) ;
}
static int F_62 ( const struct V_267 * V_268 ,
struct V_263 * V_263 , void * V_294 , void * V_16 )
{
return V_268 -> V_298 ( V_263 , V_294 , * ( unsigned int * ) V_16 ) ;
}
static int F_63 ( const struct V_267 * V_268 ,
struct V_263 * V_263 , void * V_294 , void * V_16 )
{
return V_268 -> V_299 ( V_263 , V_294 , * ( unsigned int * ) V_16 ) ;
}
static int F_64 ( const struct V_267 * V_268 ,
struct V_263 * V_263 , void * V_294 , void * V_16 )
{
struct V_265 * V_266 ;
T_2 * V_19 = V_16 ;
if ( V_268 -> V_300 )
return V_268 -> V_300 ( V_263 , V_294 , V_16 ) ;
V_266 = F_60 ( V_263 ) ;
* V_19 = F_65 ( & V_266 -> V_301 -> V_302 ) ;
return 0 ;
}
static int F_66 ( const struct V_267 * V_268 ,
struct V_263 * V_263 , void * V_294 , void * V_16 )
{
struct V_265 * V_266 ;
struct V_303 * V_304 ;
T_2 * V_19 = V_16 ;
if ( V_268 -> V_305 )
return V_268 -> V_305 ( V_263 , V_294 , * V_19 ) ;
V_266 = F_60 ( V_263 ) ;
V_304 = V_263 -> V_306 ;
return F_67 ( & V_266 -> V_301 -> V_302 , & V_304 -> V_302 , * V_19 ) ;
}
static int F_68 ( const struct V_267 * V_268 ,
struct V_263 * V_263 , void * V_294 , void * V_16 )
{
struct V_265 * V_266 = F_60 ( V_263 ) ;
struct V_26 * V_19 = V_16 ;
if ( F_69 ( V_266 , V_307 ) )
V_19 -> V_24 |= V_308 ;
return V_268 -> V_309 ( V_263 , V_294 , V_19 ) ;
}
static int F_70 ( const struct V_267 * V_268 ,
struct V_263 * V_263 , void * V_294 , void * V_16 )
{
struct V_265 * V_266 = F_60 ( V_263 ) ;
struct V_31 * V_19 = V_16 ;
if ( F_69 ( V_266 , V_307 ) )
V_19 -> V_24 |= V_310 ;
return V_268 -> V_311 ( V_263 , V_294 , V_19 ) ;
}
static int F_71 ( const struct V_267 * V_268 ,
struct V_263 * V_263 , void * V_294 , void * V_16 )
{
struct V_37 * V_19 = V_16 ;
struct V_265 * V_266 = F_60 ( V_263 ) ;
bool V_277 = V_266 -> V_278 != V_279 ;
bool V_280 = V_266 -> V_278 != V_281 ;
switch ( V_19 -> type ) {
case V_55 :
if ( F_72 ( ! V_277 || ! V_268 -> V_312 ) )
break;
return V_268 -> V_312 ( V_263 , V_294 , V_16 ) ;
case V_65 :
if ( F_72 ( ! V_277 || ! V_268 -> V_313 ) )
break;
return V_268 -> V_313 ( V_263 , V_294 , V_16 ) ;
case V_71 :
if ( F_72 ( ! V_277 || ! V_268 -> V_314 ) )
break;
return V_268 -> V_314 ( V_263 , V_294 , V_16 ) ;
case V_56 :
if ( F_72 ( ! V_280 || ! V_268 -> V_315 ) )
break;
return V_268 -> V_315 ( V_263 , V_294 , V_16 ) ;
case V_66 :
if ( F_72 ( ! V_280 || ! V_268 -> V_316 ) )
break;
return V_268 -> V_316 ( V_263 , V_294 , V_16 ) ;
case V_94 :
if ( F_72 ( ! V_277 || ! V_268 -> V_317 ) )
break;
return V_268 -> V_317 ( V_263 , V_294 , V_16 ) ;
}
return - V_282 ;
}
static int F_73 ( const struct V_267 * V_268 ,
struct V_263 * V_263 , void * V_294 , void * V_16 )
{
struct V_42 * V_19 = V_16 ;
struct V_265 * V_266 = F_60 ( V_263 ) ;
bool V_270 = V_266 -> V_271 == V_272 ;
bool V_275 = V_266 -> V_271 == V_276 ;
bool V_277 = V_266 -> V_278 != V_279 ;
bool V_280 = V_266 -> V_278 != V_281 ;
switch ( V_19 -> type ) {
case V_55 :
if ( F_72 ( ! V_277 || ! V_270 || ! V_268 -> V_283 ) )
break;
return V_268 -> V_283 ( V_263 , V_294 , V_16 ) ;
case V_65 :
if ( F_72 ( ! V_277 || ! V_270 || ! V_268 -> V_284 ) )
break;
return V_268 -> V_284 ( V_263 , V_294 , V_16 ) ;
case V_71 :
if ( F_72 ( ! V_277 || ! V_270 || ! V_268 -> V_285 ) )
break;
return V_268 -> V_285 ( V_263 , V_294 , V_16 ) ;
case V_81 :
if ( F_72 ( ! V_277 || V_270 || ! V_268 -> V_289 ) )
break;
return V_268 -> V_289 ( V_263 , V_294 , V_16 ) ;
case V_89 :
if ( F_72 ( ! V_277 || V_270 || ! V_268 -> V_291 ) )
break;
return V_268 -> V_291 ( V_263 , V_294 , V_16 ) ;
case V_56 :
if ( F_72 ( ! V_280 || ! V_270 || ! V_268 -> V_286 ) )
break;
return V_268 -> V_286 ( V_263 , V_294 , V_16 ) ;
case V_66 :
if ( F_72 ( ! V_280 || ! V_270 || ! V_268 -> V_287 ) )
break;
return V_268 -> V_287 ( V_263 , V_294 , V_16 ) ;
case V_72 :
if ( F_72 ( ! V_280 || ! V_270 || ! V_268 -> V_288 ) )
break;
return V_268 -> V_288 ( V_263 , V_294 , V_16 ) ;
case V_82 :
if ( F_72 ( ! V_280 || V_270 || ! V_268 -> V_290 ) )
break;
return V_268 -> V_290 ( V_263 , V_294 , V_16 ) ;
case V_90 :
if ( F_72 ( ! V_280 || V_270 || ! V_268 -> V_292 ) )
break;
return V_268 -> V_292 ( V_263 , V_294 , V_16 ) ;
case V_94 :
if ( F_72 ( ! V_277 || ! V_275 || ! V_268 -> V_293 ) )
break;
return V_268 -> V_293 ( V_263 , V_294 , V_16 ) ;
}
return - V_282 ;
}
static int F_74 ( const struct V_267 * V_268 ,
struct V_263 * V_263 , void * V_294 , void * V_16 )
{
struct V_42 * V_19 = V_16 ;
struct V_265 * V_266 = F_60 ( V_263 ) ;
bool V_270 = V_266 -> V_271 == V_272 ;
bool V_275 = V_266 -> V_271 == V_276 ;
bool V_277 = V_266 -> V_278 != V_279 ;
bool V_280 = V_266 -> V_278 != V_281 ;
switch ( V_19 -> type ) {
case V_55 :
if ( F_72 ( ! V_277 || ! V_270 || ! V_268 -> V_318 ) )
break;
F_75 ( V_19 , V_57 . V_44 ) ;
return V_268 -> V_318 ( V_263 , V_294 , V_16 ) ;
case V_65 :
if ( F_72 ( ! V_277 || ! V_270 || ! V_268 -> V_319 ) )
break;
F_75 ( V_19 , V_57 . V_67 ) ;
return V_268 -> V_319 ( V_263 , V_294 , V_16 ) ;
case V_71 :
if ( F_72 ( ! V_277 || ! V_270 || ! V_268 -> V_320 ) )
break;
F_75 ( V_19 , V_57 . V_52 ) ;
return V_268 -> V_320 ( V_263 , V_294 , V_16 ) ;
case V_81 :
if ( F_72 ( ! V_277 || V_270 || ! V_268 -> V_321 ) )
break;
F_75 ( V_19 , V_57 . V_48 ) ;
return V_268 -> V_321 ( V_263 , V_294 , V_16 ) ;
case V_89 :
if ( F_72 ( ! V_277 || V_270 || ! V_268 -> V_322 ) )
break;
F_75 ( V_19 , V_57 . V_50 ) ;
return V_268 -> V_322 ( V_263 , V_294 , V_16 ) ;
case V_56 :
if ( F_72 ( ! V_280 || ! V_270 || ! V_268 -> V_323 ) )
break;
F_75 ( V_19 , V_57 . V_44 ) ;
return V_268 -> V_323 ( V_263 , V_294 , V_16 ) ;
case V_66 :
if ( F_72 ( ! V_280 || ! V_270 || ! V_268 -> V_324 ) )
break;
F_75 ( V_19 , V_57 . V_67 ) ;
return V_268 -> V_324 ( V_263 , V_294 , V_16 ) ;
case V_72 :
if ( F_72 ( ! V_280 || ! V_270 || ! V_268 -> V_325 ) )
break;
F_75 ( V_19 , V_57 . V_52 ) ;
return V_268 -> V_325 ( V_263 , V_294 , V_16 ) ;
case V_82 :
if ( F_72 ( ! V_280 || V_270 || ! V_268 -> V_326 ) )
break;
F_75 ( V_19 , V_57 . V_48 ) ;
return V_268 -> V_326 ( V_263 , V_294 , V_16 ) ;
case V_90 :
if ( F_72 ( ! V_280 || V_270 || ! V_268 -> V_327 ) )
break;
F_75 ( V_19 , V_57 . V_50 ) ;
return V_268 -> V_327 ( V_263 , V_294 , V_16 ) ;
case V_94 :
if ( F_72 ( ! V_277 || ! V_275 || ! V_268 -> V_328 ) )
break;
F_75 ( V_19 , V_57 . V_54 ) ;
return V_268 -> V_328 ( V_263 , V_294 , V_16 ) ;
}
return - V_282 ;
}
static int F_76 ( const struct V_267 * V_268 ,
struct V_263 * V_263 , void * V_294 , void * V_16 )
{
struct V_42 * V_19 = V_16 ;
struct V_265 * V_266 = F_60 ( V_263 ) ;
bool V_270 = V_266 -> V_271 == V_272 ;
bool V_275 = V_266 -> V_271 == V_276 ;
bool V_277 = V_266 -> V_278 != V_279 ;
bool V_280 = V_266 -> V_278 != V_281 ;
switch ( V_19 -> type ) {
case V_55 :
if ( F_72 ( ! V_277 || ! V_270 || ! V_268 -> V_329 ) )
break;
F_75 ( V_19 , V_57 . V_44 ) ;
return V_268 -> V_329 ( V_263 , V_294 , V_16 ) ;
case V_65 :
if ( F_72 ( ! V_277 || ! V_270 || ! V_268 -> V_330 ) )
break;
F_75 ( V_19 , V_57 . V_67 ) ;
return V_268 -> V_330 ( V_263 , V_294 , V_16 ) ;
case V_71 :
if ( F_72 ( ! V_277 || ! V_270 || ! V_268 -> V_331 ) )
break;
F_75 ( V_19 , V_57 . V_52 ) ;
return V_268 -> V_331 ( V_263 , V_294 , V_16 ) ;
case V_81 :
if ( F_72 ( ! V_277 || V_270 || ! V_268 -> V_332 ) )
break;
F_75 ( V_19 , V_57 . V_48 ) ;
return V_268 -> V_332 ( V_263 , V_294 , V_16 ) ;
case V_89 :
if ( F_72 ( ! V_277 || V_270 || ! V_268 -> V_333 ) )
break;
F_75 ( V_19 , V_57 . V_50 ) ;
return V_268 -> V_333 ( V_263 , V_294 , V_16 ) ;
case V_56 :
if ( F_72 ( ! V_280 || ! V_270 || ! V_268 -> V_334 ) )
break;
F_75 ( V_19 , V_57 . V_44 ) ;
return V_268 -> V_334 ( V_263 , V_294 , V_16 ) ;
case V_66 :
if ( F_72 ( ! V_280 || ! V_270 || ! V_268 -> V_335 ) )
break;
F_75 ( V_19 , V_57 . V_67 ) ;
return V_268 -> V_335 ( V_263 , V_294 , V_16 ) ;
case V_72 :
if ( F_72 ( ! V_280 || ! V_270 || ! V_268 -> V_336 ) )
break;
F_75 ( V_19 , V_57 . V_52 ) ;
return V_268 -> V_336 ( V_263 , V_294 , V_16 ) ;
case V_82 :
if ( F_72 ( ! V_280 || V_270 || ! V_268 -> V_337 ) )
break;
F_75 ( V_19 , V_57 . V_48 ) ;
return V_268 -> V_337 ( V_263 , V_294 , V_16 ) ;
case V_90 :
if ( F_72 ( ! V_280 || V_270 || ! V_268 -> V_338 ) )
break;
F_75 ( V_19 , V_57 . V_50 ) ;
return V_268 -> V_338 ( V_263 , V_294 , V_16 ) ;
case V_94 :
if ( F_72 ( ! V_277 || ! V_275 || ! V_268 -> V_339 ) )
break;
F_75 ( V_19 , V_57 . V_54 ) ;
return V_268 -> V_339 ( V_263 , V_294 , V_16 ) ;
}
return - V_282 ;
}
static int F_77 ( const struct V_267 * V_268 ,
struct V_263 * V_263 , void * V_294 , void * V_16 )
{
return V_268 -> V_340 ( V_263 , V_294 , * ( unsigned int * ) V_16 ) ;
}
static int F_78 ( const struct V_267 * V_268 ,
struct V_263 * V_263 , void * V_294 , void * V_16 )
{
return V_268 -> V_341 ( V_263 , V_294 , * ( unsigned int * ) V_16 ) ;
}
static int F_79 ( const struct V_267 * V_268 ,
struct V_263 * V_263 , void * V_294 , void * V_16 )
{
struct V_265 * V_266 = F_60 ( V_263 ) ;
struct V_101 * V_19 = V_16 ;
int V_342 ;
V_19 -> type = ( V_266 -> V_271 == V_343 ) ?
V_344 : V_345 ;
V_342 = V_268 -> V_346 ( V_263 , V_294 , V_19 ) ;
if ( ! V_342 )
V_19 -> V_35 |= V_347 ;
return V_342 ;
}
static int F_80 ( const struct V_267 * V_268 ,
struct V_263 * V_263 , void * V_294 , void * V_16 )
{
struct V_265 * V_266 = F_60 ( V_263 ) ;
struct V_101 * V_19 = V_16 ;
V_19 -> type = ( V_266 -> V_271 == V_343 ) ?
V_344 : V_345 ;
return V_268 -> V_348 ( V_263 , V_294 , V_19 ) ;
}
static int F_81 ( const struct V_267 * V_268 ,
struct V_263 * V_263 , void * V_294 , void * V_16 )
{
struct V_97 * V_19 = V_16 ;
int V_342 ;
V_342 = V_268 -> V_349 ( V_263 , V_294 , V_19 ) ;
if ( ! V_342 )
V_19 -> V_35 |= V_347 ;
return V_342 ;
}
static int F_82 ( const struct V_267 * V_268 ,
struct V_263 * V_263 , void * V_294 , void * V_16 )
{
struct V_265 * V_266 = F_60 ( V_263 ) ;
struct V_105 * V_19 = V_16 ;
if ( V_266 -> V_271 == V_276 )
V_19 -> type = V_350 ;
else
V_19 -> type = ( V_266 -> V_271 == V_343 ) ?
V_344 : V_345 ;
return V_268 -> V_351 ( V_263 , V_294 , V_19 ) ;
}
static int F_83 ( const struct V_267 * V_268 ,
struct V_263 * V_263 , void * V_294 , void * V_16 )
{
struct V_265 * V_266 = F_60 ( V_263 ) ;
const struct V_105 * V_19 = V_16 ;
enum V_352 type ;
if ( V_266 -> V_271 == V_276 ) {
if ( V_19 -> type != V_350 && V_19 -> type != V_353 )
return - V_282 ;
} else {
type = ( V_266 -> V_271 == V_343 ) ?
V_344 : V_345 ;
if ( type != V_19 -> type )
return - V_282 ;
}
return V_268 -> V_354 ( V_263 , V_294 , V_19 ) ;
}
static int F_84 ( const struct V_267 * V_268 ,
struct V_263 * V_263 , void * V_294 , void * V_16 )
{
struct V_265 * V_266 = F_60 ( V_263 ) ;
struct V_12 * V_19 = V_16 ;
T_1 V_1 = V_266 -> V_355 , V_356 = 0 ;
unsigned int V_27 = V_19 -> V_27 , V_3 , V_357 = 0 ;
const char * V_6 = L_113 ;
if ( V_1 == 0 )
return - V_358 ;
for ( V_3 = 0 ; V_3 <= V_27 && V_1 ; V_3 ++ ) {
while ( ( V_1 & V_4 [ V_357 ] . V_5 ) != V_4 [ V_357 ] . V_5 )
V_357 ++ ;
V_356 = V_4 [ V_357 ] . V_5 ;
V_6 = V_4 [ V_357 ] . V_6 ;
V_357 ++ ;
if ( V_356 == 0 )
break;
if ( V_356 != V_359 &&
V_356 != V_360 &&
V_356 != V_361 )
V_1 &= ~ V_356 ;
}
if ( V_3 <= V_27 )
return - V_282 ;
F_4 ( V_19 , V_356 , V_6 ) ;
return 0 ;
}
static int F_85 ( const struct V_267 * V_268 ,
struct V_263 * V_263 , void * V_294 , void * V_16 )
{
struct V_265 * V_266 = F_60 ( V_263 ) ;
T_1 V_1 = * ( T_1 * ) V_16 , V_362 ;
V_362 = V_1 & V_266 -> V_355 ;
if ( V_266 -> V_355 && ! V_362 )
return - V_282 ;
return V_268 -> V_363 ( V_263 , V_294 , V_362 ) ;
}
static int F_86 ( const struct V_267 * V_268 ,
struct V_263 * V_263 , void * V_294 , void * V_16 )
{
struct V_265 * V_266 = F_60 ( V_263 ) ;
T_1 * V_19 = V_16 ;
* V_19 = V_266 -> V_355 ;
return V_268 -> V_364 ( V_263 , V_294 , V_16 ) ;
}
static int F_87 ( const struct V_267 * V_268 ,
struct V_263 * V_263 , void * V_294 , void * V_16 )
{
struct V_265 * V_266 = F_60 ( V_263 ) ;
struct V_107 * V_19 = V_16 ;
enum V_352 type ;
if ( V_266 -> V_271 == V_276 )
return - V_282 ;
type = ( V_266 -> V_271 == V_343 ) ?
V_344 : V_345 ;
if ( V_19 -> type != type )
return - V_282 ;
return V_268 -> V_365 ( V_263 , V_294 , V_19 ) ;
}
static int F_88 ( const struct V_267 * V_268 ,
struct V_263 * V_263 , void * V_294 , void * V_16 )
{
return V_268 -> V_366 ( V_263 , V_294 , * ( unsigned int * ) V_16 ) ;
}
static int F_89 ( const struct V_267 * V_268 ,
struct V_263 * V_263 , void * V_294 , void * V_16 )
{
struct V_111 * V_19 = V_16 ;
int V_367 = F_59 ( V_263 , V_19 -> type ) ;
if ( V_367 )
return V_367 ;
F_75 ( V_19 , V_112 ) ;
return V_268 -> V_368 ( V_263 , V_294 , V_19 ) ;
}
static int F_90 ( const struct V_267 * V_268 ,
struct V_263 * V_263 , void * V_294 , void * V_16 )
{
struct V_114 * V_19 = V_16 ;
int V_367 = F_59 ( V_263 , V_19 -> type ) ;
return V_367 ? V_367 : V_268 -> V_369 ( V_263 , V_294 , V_19 ) ;
}
static int F_91 ( const struct V_267 * V_268 ,
struct V_263 * V_263 , void * V_294 , void * V_16 )
{
struct V_114 * V_19 = V_16 ;
int V_367 = F_59 ( V_263 , V_19 -> type ) ;
return V_367 ? V_367 : V_268 -> V_370 ( V_263 , V_294 , V_19 ) ;
}
static int F_92 ( const struct V_267 * V_268 ,
struct V_263 * V_263 , void * V_294 , void * V_16 )
{
struct V_114 * V_19 = V_16 ;
int V_367 = F_59 ( V_263 , V_19 -> type ) ;
return V_367 ? V_367 : V_268 -> V_371 ( V_263 , V_294 , V_19 ) ;
}
static int F_93 ( const struct V_267 * V_268 ,
struct V_263 * V_263 , void * V_294 , void * V_16 )
{
struct V_138 * V_372 = V_16 ;
int V_367 = F_59 ( V_263 , V_372 -> V_139 . type ) ;
return V_367 ? V_367 : V_268 -> V_373 ( V_263 , V_294 , V_372 ) ;
}
static int F_94 ( const struct V_267 * V_268 ,
struct V_263 * V_263 , void * V_294 , void * V_16 )
{
struct V_114 * V_374 = V_16 ;
int V_367 = F_59 ( V_263 , V_374 -> type ) ;
return V_367 ? V_367 : V_268 -> V_375 ( V_263 , V_294 , V_374 ) ;
}
static int F_95 ( const struct V_267 * V_268 ,
struct V_263 * V_263 , void * V_294 , void * V_16 )
{
struct V_140 * V_19 = V_16 ;
T_1 V_5 ;
int V_367 = F_59 ( V_263 , V_19 -> type ) ;
if ( V_367 )
return V_367 ;
if ( V_268 -> V_376 )
return V_268 -> V_376 ( V_263 , V_294 , V_19 ) ;
if ( V_19 -> type != V_55 &&
V_19 -> type != V_65 )
return - V_282 ;
V_19 -> V_143 . V_144 . V_148 = 2 ;
V_367 = V_268 -> V_377 ( V_263 , V_294 , & V_5 ) ;
if ( V_367 == 0 )
F_3 ( V_5 , & V_19 -> V_143 . V_144 . V_146 ) ;
return V_367 ;
}
static int F_96 ( const struct V_267 * V_268 ,
struct V_263 * V_263 , void * V_294 , void * V_16 )
{
struct V_140 * V_19 = V_16 ;
int V_367 = F_59 ( V_263 , V_19 -> type ) ;
return V_367 ? V_367 : V_268 -> V_378 ( V_263 , V_294 , V_19 ) ;
}
static int F_97 ( const struct V_267 * V_268 ,
struct V_263 * V_263 , void * V_294 , void * V_16 )
{
struct V_265 * V_266 = F_60 ( V_263 ) ;
struct V_153 * V_19 = V_16 ;
struct V_303 * V_304 =
F_98 ( V_379 , & V_266 -> V_39 ) ? V_294 : NULL ;
if ( V_304 && V_304 -> V_380 )
return V_153 ( V_304 -> V_380 , V_19 ) ;
if ( V_266 -> V_380 )
return V_153 ( V_266 -> V_380 , V_19 ) ;
if ( V_268 -> V_381 )
return V_268 -> V_381 ( V_263 , V_294 , V_19 ) ;
return - V_382 ;
}
static int F_99 ( const struct V_267 * V_268 ,
struct V_263 * V_263 , void * V_294 , void * V_16 )
{
struct V_265 * V_266 = F_60 ( V_263 ) ;
struct V_158 * V_19 = V_16 ;
struct V_303 * V_304 =
F_98 ( V_379 , & V_266 -> V_39 ) ? V_294 : NULL ;
if ( V_304 && V_304 -> V_380 )
return V_158 ( V_304 -> V_380 , V_19 ) ;
if ( V_266 -> V_380 )
return V_158 ( V_266 -> V_380 , V_19 ) ;
if ( V_268 -> V_383 )
return V_268 -> V_383 ( V_263 , V_294 , V_19 ) ;
return - V_382 ;
}
static int F_100 ( const struct V_267 * V_268 ,
struct V_263 * V_263 , void * V_294 , void * V_16 )
{
struct V_265 * V_266 = F_60 ( V_263 ) ;
struct V_159 * V_19 = V_16 ;
struct V_303 * V_304 =
F_98 ( V_379 , & V_266 -> V_39 ) ? V_294 : NULL ;
struct V_161 V_384 ;
struct V_385 V_244 ;
if ( V_304 && V_304 -> V_380 )
return F_101 ( V_304 -> V_380 , V_19 ) ;
if ( V_266 -> V_380 )
return F_101 ( V_266 -> V_380 , V_19 ) ;
if ( V_268 -> V_386 )
return V_268 -> V_386 ( V_263 , V_294 , V_19 ) ;
if ( V_268 -> V_387 == NULL )
return - V_382 ;
V_384 . V_162 = F_58 ( V_19 -> V_1 ) ;
V_384 . V_88 = 1 ;
V_384 . V_164 = & V_244 ;
V_244 . V_1 = V_19 -> V_1 ;
V_244 . V_160 = V_19 -> V_160 ;
if ( F_57 ( & V_384 , 1 ) ) {
int V_367 = V_268 -> V_387 ( V_263 , V_294 , & V_384 ) ;
if ( V_367 == 0 )
V_19 -> V_160 = V_244 . V_160 ;
return V_367 ;
}
return - V_282 ;
}
static int F_102 ( const struct V_267 * V_268 ,
struct V_263 * V_263 , void * V_294 , void * V_16 )
{
struct V_265 * V_266 = F_60 ( V_263 ) ;
struct V_159 * V_19 = V_16 ;
struct V_303 * V_304 =
F_98 ( V_379 , & V_266 -> V_39 ) ? V_294 : NULL ;
struct V_161 V_384 ;
struct V_385 V_244 ;
if ( V_304 && V_304 -> V_380 )
return F_103 ( V_304 , V_304 -> V_380 , V_19 ) ;
if ( V_266 -> V_380 )
return F_103 ( NULL , V_266 -> V_380 , V_19 ) ;
if ( V_268 -> V_388 )
return V_268 -> V_388 ( V_263 , V_294 , V_19 ) ;
if ( V_268 -> V_389 == NULL )
return - V_382 ;
V_384 . V_162 = F_58 ( V_19 -> V_1 ) ;
V_384 . V_88 = 1 ;
V_384 . V_164 = & V_244 ;
V_244 . V_1 = V_19 -> V_1 ;
V_244 . V_160 = V_19 -> V_160 ;
if ( F_57 ( & V_384 , 1 ) )
return V_268 -> V_389 ( V_263 , V_294 , & V_384 ) ;
return - V_282 ;
}
static int F_104 ( const struct V_267 * V_268 ,
struct V_263 * V_263 , void * V_294 , void * V_16 )
{
struct V_265 * V_266 = F_60 ( V_263 ) ;
struct V_161 * V_19 = V_16 ;
struct V_303 * V_304 =
F_98 ( V_379 , & V_266 -> V_39 ) ? V_294 : NULL ;
V_19 -> V_163 = V_19 -> V_88 ;
if ( V_304 && V_304 -> V_380 )
return F_105 ( V_304 -> V_380 , V_19 ) ;
if ( V_266 -> V_380 )
return F_105 ( V_266 -> V_380 , V_19 ) ;
if ( V_268 -> V_387 == NULL )
return - V_382 ;
return F_57 ( V_19 , 0 ) ? V_268 -> V_387 ( V_263 , V_294 , V_19 ) :
- V_282 ;
}
static int F_106 ( const struct V_267 * V_268 ,
struct V_263 * V_263 , void * V_294 , void * V_16 )
{
struct V_265 * V_266 = F_60 ( V_263 ) ;
struct V_161 * V_19 = V_16 ;
struct V_303 * V_304 =
F_98 ( V_379 , & V_266 -> V_39 ) ? V_294 : NULL ;
V_19 -> V_163 = V_19 -> V_88 ;
if ( V_304 && V_304 -> V_380 )
return F_107 ( V_304 , V_304 -> V_380 , V_19 ) ;
if ( V_266 -> V_380 )
return F_107 ( NULL , V_266 -> V_380 , V_19 ) ;
if ( V_268 -> V_389 == NULL )
return - V_382 ;
return F_57 ( V_19 , 0 ) ? V_268 -> V_389 ( V_263 , V_294 , V_19 ) :
- V_282 ;
}
static int F_108 ( const struct V_267 * V_268 ,
struct V_263 * V_263 , void * V_294 , void * V_16 )
{
struct V_265 * V_266 = F_60 ( V_263 ) ;
struct V_161 * V_19 = V_16 ;
struct V_303 * V_304 =
F_98 ( V_379 , & V_266 -> V_39 ) ? V_294 : NULL ;
V_19 -> V_163 = V_19 -> V_88 ;
if ( V_304 && V_304 -> V_380 )
return F_109 ( V_304 -> V_380 , V_19 ) ;
if ( V_266 -> V_380 )
return F_109 ( V_266 -> V_380 , V_19 ) ;
if ( V_268 -> V_390 == NULL )
return - V_382 ;
return F_57 ( V_19 , 0 ) ? V_268 -> V_390 ( V_263 , V_294 , V_19 ) :
- V_282 ;
}
static int F_110 ( const struct V_267 * V_268 ,
struct V_263 * V_263 , void * V_294 , void * V_16 )
{
struct V_170 * V_19 = V_16 ;
struct V_171 V_391 = {
. type = V_19 -> type ,
} ;
int V_367 ;
if ( V_268 -> V_392 )
return V_268 -> V_392 ( V_263 , V_294 , V_19 ) ;
if ( F_111 ( V_19 -> type ) )
V_391 . V_172 = V_393 ;
else
V_391 . V_172 = V_394 ;
V_367 = V_268 -> V_395 ( V_263 , V_294 , & V_391 ) ;
if ( ! V_367 )
V_19 -> V_142 = V_391 . V_173 ;
return V_367 ;
}
static int F_112 ( const struct V_267 * V_268 ,
struct V_263 * V_263 , void * V_294 , void * V_16 )
{
struct V_170 * V_19 = V_16 ;
struct V_171 V_391 = {
. type = V_19 -> type ,
. V_173 = V_19 -> V_142 ,
} ;
if ( V_268 -> V_396 )
return V_268 -> V_396 ( V_263 , V_294 , V_19 ) ;
if ( F_111 ( V_19 -> type ) )
V_391 . V_172 = V_393 ;
else
V_391 . V_172 = V_394 ;
return V_268 -> V_397 ( V_263 , V_294 , & V_391 ) ;
}
static int F_113 ( const struct V_267 * V_268 ,
struct V_263 * V_263 , void * V_294 , void * V_16 )
{
struct V_166 * V_19 = V_16 ;
struct V_171 V_391 = { . type = V_19 -> type } ;
int V_367 ;
if ( V_268 -> V_398 )
return V_268 -> V_398 ( V_263 , V_294 , V_19 ) ;
if ( F_111 ( V_19 -> type ) )
V_391 . V_172 = V_399 ;
else
V_391 . V_172 = V_400 ;
V_367 = V_268 -> V_395 ( V_263 , V_294 , & V_391 ) ;
if ( V_367 )
return V_367 ;
V_19 -> V_167 = V_391 . V_173 ;
if ( F_111 ( V_19 -> type ) )
V_391 . V_172 = V_401 ;
else
V_391 . V_172 = V_402 ;
V_367 = V_268 -> V_395 ( V_263 , V_294 , & V_391 ) ;
if ( V_367 )
return V_367 ;
V_19 -> V_168 = V_391 . V_173 ;
V_19 -> V_169 . V_10 = 1 ;
V_19 -> V_169 . V_11 = 1 ;
return 0 ;
}
static int F_114 ( const struct V_267 * V_268 ,
struct V_263 * V_263 , void * V_294 , void * V_16 )
{
struct V_265 * V_266 = F_60 ( V_263 ) ;
int V_367 ;
if ( V_266 -> V_301 )
F_41 ( L_114 ,
V_266 -> V_301 -> V_14 ) ;
V_367 = V_268 -> V_403 ( V_263 , V_294 ) ;
if ( V_266 -> V_301 )
F_41 ( L_115 ,
V_266 -> V_301 -> V_14 ) ;
return V_367 ;
}
static int F_115 ( const struct V_267 * V_268 ,
struct V_263 * V_263 , void * V_294 , void * V_16 )
{
#ifdef F_116
struct V_195 * V_19 = V_16 ;
struct V_265 * V_266 = F_60 ( V_263 ) ;
struct V_404 * V_405 ;
int V_406 = 0 ;
if ( ! F_117 ( V_407 ) )
return - V_408 ;
if ( V_19 -> V_192 . type == V_409 ) {
if ( V_266 -> V_301 == NULL )
return - V_282 ;
F_118 (sd, vfd->v4l2_dev)
if ( V_19 -> V_192 . V_194 == V_406 ++ )
return F_119 ( V_405 , V_410 , V_411 , V_19 ) ;
return - V_282 ;
}
if ( V_268 -> V_412 && V_19 -> V_192 . type == V_413 &&
( V_268 -> V_414 || V_19 -> V_192 . V_194 == 0 ) )
return V_268 -> V_412 ( V_263 , V_294 , V_19 ) ;
return - V_282 ;
#else
return - V_382 ;
#endif
}
static int F_120 ( const struct V_267 * V_268 ,
struct V_263 * V_263 , void * V_294 , void * V_16 )
{
#ifdef F_116
const struct V_195 * V_19 = V_16 ;
struct V_265 * V_266 = F_60 ( V_263 ) ;
struct V_404 * V_405 ;
int V_406 = 0 ;
if ( ! F_117 ( V_407 ) )
return - V_408 ;
if ( V_19 -> V_192 . type == V_409 ) {
if ( V_266 -> V_301 == NULL )
return - V_282 ;
F_118 (sd, vfd->v4l2_dev)
if ( V_19 -> V_192 . V_194 == V_406 ++ )
return F_119 ( V_405 , V_410 , V_415 , V_19 ) ;
return - V_282 ;
}
if ( V_268 -> V_416 && V_19 -> V_192 . type == V_413 &&
( V_268 -> V_414 || V_19 -> V_192 . V_194 == 0 ) )
return V_268 -> V_416 ( V_263 , V_294 , V_19 ) ;
return - V_282 ;
#else
return - V_382 ;
#endif
}
static int F_121 ( const struct V_267 * V_268 ,
struct V_263 * V_263 , void * V_294 , void * V_16 )
{
#ifdef F_116
struct V_265 * V_266 = F_60 ( V_263 ) ;
struct V_191 * V_19 = V_16 ;
struct V_404 * V_405 ;
int V_406 = 0 ;
switch ( V_19 -> V_192 . type ) {
case V_413 :
if ( V_268 -> V_416 )
V_19 -> V_39 |= V_417 ;
if ( V_268 -> V_412 )
V_19 -> V_39 |= V_418 ;
F_5 ( V_19 -> V_14 , V_266 -> V_301 -> V_14 , sizeof( V_19 -> V_14 ) ) ;
if ( V_268 -> V_414 )
return V_268 -> V_414 ( V_263 , V_294 , V_16 ) ;
if ( V_19 -> V_192 . V_194 )
return - V_282 ;
return 0 ;
case V_409 :
if ( V_266 -> V_301 == NULL )
break;
F_118 (sd, vfd->v4l2_dev) {
if ( V_19 -> V_192 . V_194 != V_406 ++ )
continue;
if ( V_405 -> V_268 -> V_410 && V_405 -> V_268 -> V_410 -> V_415 )
V_19 -> V_39 |= V_417 ;
if ( V_405 -> V_268 -> V_410 && V_405 -> V_268 -> V_410 -> V_411 )
V_19 -> V_39 |= V_418 ;
F_5 ( V_19 -> V_14 , V_405 -> V_14 , sizeof( V_19 -> V_14 ) ) ;
return 0 ;
}
break;
}
return - V_282 ;
#else
return - V_382 ;
#endif
}
static int F_122 ( const struct V_267 * V_268 ,
struct V_263 * V_263 , void * V_294 , void * V_16 )
{
return F_123 ( V_294 , V_16 , V_263 -> V_419 & V_420 ) ;
}
static int F_124 ( const struct V_267 * V_268 ,
struct V_263 * V_263 , void * V_294 , void * V_16 )
{
return V_268 -> V_421 ( V_294 , V_16 ) ;
}
static int F_125 ( const struct V_267 * V_268 ,
struct V_263 * V_263 , void * V_294 , void * V_16 )
{
return V_268 -> V_422 ( V_294 , V_16 ) ;
}
static int F_126 ( const struct V_267 * V_268 ,
struct V_263 * V_263 , void * V_294 , void * V_16 )
{
struct V_252 * V_19 = V_16 ;
int V_367 = F_59 ( V_263 , V_19 -> type ) ;
if ( V_367 )
return V_367 ;
memset ( V_19 , 0 , F_127 ( struct V_252 , type ) ) ;
return V_268 -> V_423 ( V_263 , V_294 , V_19 ) ;
}
static int F_128 ( const struct V_267 * V_268 ,
struct V_263 * V_263 , void * V_294 , void * V_16 )
{
struct V_265 * V_266 = F_60 ( V_263 ) ;
struct V_253 * V_19 = V_16 ;
enum V_352 type ;
int V_342 ;
if ( V_266 -> V_271 == V_276 ) {
if ( V_19 -> type != V_350 && V_19 -> type != V_353 )
return - V_282 ;
type = V_19 -> type ;
} else {
type = ( V_266 -> V_271 == V_343 ) ?
V_344 : V_345 ;
if ( type != V_19 -> type )
return - V_282 ;
}
if ( V_268 -> V_424 )
return V_268 -> V_424 ( V_263 , V_294 , V_19 ) ;
if ( F_69 ( V_266 , V_425 ) ) {
struct V_101 V_426 = {
. V_27 = V_19 -> V_29 ,
. type = type ,
} ;
if ( V_19 -> V_27 )
return - V_282 ;
V_342 = V_268 -> V_346 ( V_263 , V_294 , & V_426 ) ;
if ( V_342 )
return V_342 ;
V_19 -> V_35 = V_426 . V_35 | V_347 ;
V_19 -> V_99 = V_426 . V_99 ;
V_19 -> V_100 = V_426 . V_100 ;
V_19 -> V_254 = ( type == V_344 ) ?
V_427 : V_428 ;
return 0 ;
}
if ( F_69 ( V_266 , V_429 ) ) {
struct V_97 V_124 = {
. V_27 = V_19 -> V_29 ,
} ;
if ( type != V_344 )
return - V_282 ;
if ( V_19 -> V_27 )
return - V_282 ;
V_342 = V_268 -> V_349 ( V_263 , V_294 , & V_124 ) ;
if ( V_342 )
return V_342 ;
V_19 -> V_35 = V_124 . V_35 | V_347 ;
V_19 -> V_99 = V_124 . V_99 ;
V_19 -> V_100 = V_124 . V_100 ;
V_19 -> V_254 = ( type == V_344 ) ?
V_427 : V_428 ;
return 0 ;
}
return - V_382 ;
}
bool F_129 ( unsigned int V_184 )
{
if ( F_130 ( V_184 ) >= V_430 )
return false ;
return V_431 [ F_130 ( V_184 ) ] . V_432 == V_184 ;
}
struct V_433 * F_131 ( struct V_265 * V_434 , unsigned V_184 )
{
if ( F_130 ( V_184 ) >= V_430 )
return V_434 -> V_435 ;
if ( F_98 ( F_130 ( V_184 ) , V_434 -> V_436 ) )
return NULL ;
if ( V_434 -> V_437 && V_434 -> V_437 -> V_435 &&
( V_431 [ F_130 ( V_184 ) ] . V_39 & V_438 ) )
return V_434 -> V_437 -> V_435 ;
return V_434 -> V_435 ;
}
void F_132 ( const char * V_439 , unsigned int V_184 )
{
const char * V_440 , * type ;
if ( V_439 )
F_15 ( V_69 L_116 , V_439 ) ;
switch ( F_133 ( V_184 ) ) {
case 'd' :
type = L_117 ;
break;
case 'V' :
if ( F_130 ( V_184 ) >= V_430 ) {
type = L_118 ;
break;
}
F_7 ( L_119 , V_431 [ F_130 ( V_184 ) ] . V_14 ) ;
return;
default:
type = L_120 ;
break;
}
switch ( F_134 ( V_184 ) ) {
case V_441 : V_440 = L_121 ; break;
case V_442 : V_440 = L_122 ; break;
case V_443 : V_440 = L_123 ; break;
case V_442 | V_443 : V_440 = L_124 ; break;
default: V_440 = L_125 ; break;
}
F_7 ( L_126 ,
type , F_133 ( V_184 ) , V_440 , F_130 ( V_184 ) , V_184 ) ;
}
static long F_135 ( struct V_263 * V_263 ,
unsigned int V_184 , void * V_16 )
{
struct V_265 * V_266 = F_60 ( V_263 ) ;
const struct V_267 * V_268 = V_266 -> V_269 ;
bool V_17 = false ;
struct V_444 V_445 ;
const struct V_444 * V_446 ;
void * V_294 = V_263 -> V_306 ;
struct V_303 * V_304 = NULL ;
int V_447 = 0 ;
int V_448 = V_266 -> V_448 ;
long V_367 = - V_382 ;
if ( V_268 == NULL ) {
F_136 ( L_127 ,
F_137 ( V_266 ) ) ;
return V_367 ;
}
if ( F_98 ( V_379 , & V_266 -> V_39 ) ) {
V_304 = V_263 -> V_306 ;
V_447 = F_98 ( V_449 , & V_266 -> V_39 ) ;
}
if ( F_129 ( V_184 ) ) {
V_446 = & V_431 [ F_130 ( V_184 ) ] ;
if ( ! F_98 ( F_130 ( V_184 ) , V_266 -> V_450 ) &&
! ( ( V_446 -> V_39 & V_451 ) && V_304 && V_304 -> V_380 ) )
goto V_452;
if ( V_447 && ( V_446 -> V_39 & V_453 ) ) {
V_367 = F_138 ( V_266 -> V_302 , V_304 -> V_302 ) ;
if ( V_367 )
goto V_452;
}
} else {
V_445 . V_432 = V_184 ;
V_445 . V_39 = 0 ;
V_445 . V_448 = F_56 ;
V_446 = & V_445 ;
}
V_17 = F_134 ( V_184 ) == V_443 ;
if ( V_446 -> V_39 & V_454 ) {
typedef int (* F_139)( struct V_263 * V_263 , void * V_294 , void * V_19 );
const void * V_19 = V_266 -> V_269 ;
const F_139 * V_455 = V_19 + V_446 -> V_242 . V_84 ;
V_367 = (* V_455)( V_263 , V_294 , V_16 ) ;
} else if ( V_446 -> V_39 & V_456 ) {
V_367 = V_446 -> V_242 . V_457 ( V_268 , V_263 , V_294 , V_16 ) ;
} else if ( ! V_268 -> V_458 ) {
V_367 = - V_382 ;
} else {
V_367 = V_268 -> V_458 ( V_263 , V_294 ,
V_447 ? F_138 ( V_266 -> V_302 , V_304 -> V_302 ) >= 0 : 0 ,
V_184 , V_16 ) ;
}
V_452:
if ( V_448 ) {
F_132 ( F_137 ( V_266 ) , V_184 ) ;
if ( V_367 < 0 )
F_7 ( L_128 , V_367 ) ;
if ( V_448 == V_459 )
F_7 ( L_43 ) ;
else if ( F_134 ( V_184 ) == V_441 )
V_446 -> V_448 ( V_16 , V_17 ) ;
else {
F_7 ( L_129 ) ;
V_446 -> V_448 ( V_16 , V_17 ) ;
}
}
return V_367 ;
}
static int F_140 ( unsigned int V_184 , void * V_460 , T_3 * V_461 ,
void * T_4 * V_462 , void * * * V_463 )
{
int V_367 = 0 ;
switch ( V_184 ) {
case V_464 :
case V_465 :
case V_466 :
case V_467 : {
struct V_114 * V_468 = V_460 ;
if ( F_26 ( V_468 -> type ) && V_468 -> V_126 > 0 ) {
if ( V_468 -> V_126 > V_469 ) {
V_367 = - V_282 ;
break;
}
* V_462 = ( void T_4 * ) V_468 -> V_124 . V_125 ;
* V_463 = ( void * ) & V_468 -> V_124 . V_125 ;
* V_461 = sizeof( struct V_118 ) * V_468 -> V_126 ;
V_367 = 1 ;
}
break;
}
case V_470 :
case V_471 : {
struct V_255 * V_472 = V_460 ;
if ( V_472 -> V_258 ) {
if ( V_472 -> V_258 > 256 ) {
V_367 = - V_282 ;
break;
}
* V_462 = ( void T_4 * ) V_472 -> V_472 ;
* V_463 = ( void * ) & V_472 -> V_472 ;
* V_461 = V_472 -> V_258 * 128 ;
V_367 = 1 ;
}
break;
}
case V_473 :
case V_474 :
case V_475 : {
struct V_161 * V_384 = V_460 ;
if ( V_384 -> V_88 != 0 ) {
if ( V_384 -> V_88 > V_476 ) {
V_367 = - V_282 ;
break;
}
* V_462 = ( void T_4 * ) V_384 -> V_164 ;
* V_463 = ( void * ) & V_384 -> V_164 ;
* V_461 = sizeof( struct V_385 )
* V_384 -> V_88 ;
V_367 = 1 ;
}
break;
}
}
return V_367 ;
}
long
F_141 ( struct V_263 * V_263 , unsigned int V_184 , unsigned long V_16 ,
T_5 V_457 )
{
char V_477 [ 128 ] ;
void * V_478 = NULL ;
void * V_460 = ( void * ) V_16 ;
long V_342 = - V_282 ;
bool V_479 ;
T_3 V_461 = 0 ;
void T_4 * V_462 = NULL ;
void * * V_463 = NULL ;
if ( F_134 ( V_184 ) != V_441 ) {
if ( F_142 ( V_184 ) <= sizeof( V_477 ) ) {
V_460 = V_477 ;
} else {
V_478 = F_143 ( F_142 ( V_184 ) , V_480 ) ;
if ( NULL == V_478 )
return - V_481 ;
V_460 = V_478 ;
}
V_342 = - V_482 ;
if ( F_134 ( V_184 ) & V_443 ) {
unsigned int V_483 = F_142 ( V_184 ) ;
if ( F_129 ( V_184 ) ) {
T_2 V_39 = V_431 [ F_130 ( V_184 ) ] . V_39 ;
if ( V_39 & V_484 )
V_483 = ( V_39 & V_484 ) >> 16 ;
}
if ( F_144 ( V_460 , ( void T_4 * ) V_16 , V_483 ) )
goto V_485;
if ( V_483 < F_142 ( V_184 ) )
memset ( ( V_486 * ) V_460 + V_483 , 0 , F_142 ( V_184 ) - V_483 ) ;
} else {
memset ( V_460 , 0 , F_142 ( V_184 ) ) ;
}
}
V_342 = F_140 ( V_184 , V_460 , & V_461 , & V_462 , & V_463 ) ;
if ( V_342 < 0 )
goto V_485;
V_479 = V_342 ;
if ( V_479 ) {
V_478 = F_143 ( V_461 , V_480 ) ;
V_342 = - V_481 ;
if ( NULL == V_478 )
goto V_487;
V_342 = - V_482 ;
if ( F_144 ( V_478 , V_462 , V_461 ) )
goto V_487;
* V_463 = V_478 ;
}
V_342 = V_457 ( V_263 , V_184 , V_460 ) ;
if ( V_342 == - V_488 )
V_342 = - V_382 ;
if ( V_342 == 0 ) {
if ( V_184 == V_467 )
F_145 ( F_60 ( V_263 ) -> V_489 , V_460 ) ;
else if ( V_184 == V_466 )
F_146 ( F_60 ( V_263 ) -> V_489 , V_460 ) ;
}
if ( V_479 ) {
* V_463 = V_462 ;
if ( F_147 ( V_462 , V_478 , V_461 ) )
V_342 = - V_482 ;
goto V_487;
}
if ( V_342 < 0 && V_184 != V_490 )
goto V_485;
V_487:
switch ( F_134 ( V_184 ) ) {
case V_442 :
case ( V_443 | V_442 ) :
if ( F_147 ( ( void T_4 * ) V_16 , V_460 , F_142 ( V_184 ) ) )
V_342 = - V_482 ;
break;
}
V_485:
F_148 ( V_478 ) ;
return V_342 ;
}
long F_149 ( struct V_263 * V_263 ,
unsigned int V_184 , unsigned long V_16 )
{
return F_141 ( V_263 , V_184 , V_16 , F_135 ) ;
}
