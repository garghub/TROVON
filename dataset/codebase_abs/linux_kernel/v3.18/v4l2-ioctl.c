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
L_14
L_15 ,
V_44 -> V_58 , V_44 -> V_59 ,
( V_44 -> V_40 & 0xff ) ,
( V_44 -> V_40 >> 8 ) & 0xff ,
( V_44 -> V_40 >> 16 ) & 0xff ,
( V_44 -> V_40 >> 24 ) & 0xff ,
F_13 ( V_44 -> V_60 , V_61 ) ,
V_44 -> V_62 , V_44 -> V_63 ,
V_44 -> V_64 , V_44 -> V_39 ) ;
break;
case V_65 :
case V_66 :
V_46 = & V_19 -> V_57 . V_67 ;
F_7 ( L_12
L_16
L_17 ,
V_46 -> V_58 , V_46 -> V_59 ,
( V_46 -> V_40 & 0xff ) ,
( V_46 -> V_40 >> 8 ) & 0xff ,
( V_46 -> V_40 >> 16 ) & 0xff ,
( V_46 -> V_40 >> 24 ) & 0xff ,
F_13 ( V_46 -> V_60 , V_61 ) ,
V_46 -> V_64 , V_46 -> V_68 ) ;
for ( V_3 = 0 ; V_3 < V_46 -> V_68 ; V_3 ++ )
F_15 ( V_69 L_18 , V_3 ,
V_46 -> V_70 [ V_3 ] . V_62 ,
V_46 -> V_70 [ V_3 ] . V_63 ) ;
break;
case V_71 :
case V_72 :
V_52 = & V_19 -> V_57 . V_52 ;
F_7 ( L_19 ,
V_52 -> V_73 . V_58 , V_52 -> V_73 . V_59 , V_52 -> V_73 . V_74 , V_52 -> V_73 . V_75 ,
F_13 ( V_52 -> V_60 , V_61 ) ,
V_52 -> V_76 , V_52 -> V_77 , V_52 -> V_78 ,
V_52 -> V_79 , V_52 -> V_80 ) ;
break;
case V_81 :
case V_82 :
V_48 = & V_19 -> V_57 . V_48 ;
F_7 ( L_20
L_21 ,
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
F_7 ( L_22 ,
V_50 -> V_91 , V_50 -> V_92 ) ;
for ( V_3 = 0 ; V_3 < 24 ; V_3 ++ )
F_15 ( V_69 L_23 , V_3 ,
V_50 -> V_93 [ 0 ] [ V_3 ] ,
V_50 -> V_93 [ 1 ] [ V_3 ] ) ;
break;
case V_94 :
V_54 = & V_19 -> V_57 . V_54 ;
F_7 ( L_24 ,
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
F_7 ( L_25
L_26
L_27 ,
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
F_7 ( L_28 , F_13 ( * ( T_2 * ) V_16 , V_38 ) ) ;
}
static void F_18 ( const void * V_16 , bool V_17 )
{
const struct V_97 * V_19 = V_16 ;
if ( V_17 )
F_7 ( L_29 , V_19 -> V_27 , V_19 -> V_98 ) ;
else
F_7 ( L_30
L_31 ,
V_19 -> V_27 , ( int ) sizeof( V_19 -> V_14 ) , V_19 -> V_14 , V_19 -> V_35 ,
V_19 -> V_99 , V_19 -> V_100 , V_19 -> V_98 ) ;
}
static void F_19 ( const void * V_16 , bool V_17 )
{
const struct V_101 * V_19 = V_16 ;
if ( V_17 )
F_7 ( L_32 , V_19 -> V_27 , V_19 -> V_102 ) ;
else
F_7 ( L_33
L_34
L_35 ,
V_19 -> V_27 , ( int ) sizeof( V_19 -> V_14 ) , V_19 -> V_14 , V_19 -> type ,
V_19 -> V_35 , V_19 -> V_99 ,
V_19 -> V_100 , V_19 -> signal , V_19 -> V_103 ,
V_19 -> V_104 , V_19 -> V_102 ) ;
}
static void F_20 ( const void * V_16 , bool V_17 )
{
const struct V_105 * V_19 = V_16 ;
F_7 ( L_36 ,
V_19 -> V_29 , V_19 -> type , V_19 -> V_106 ) ;
}
static void F_21 ( const void * V_16 , bool V_17 )
{
const struct V_12 * V_19 = V_16 ;
F_7 ( L_37
L_38 , V_19 -> V_27 ,
( unsigned long long ) V_19 -> V_1 , ( int ) sizeof( V_19 -> V_14 ) , V_19 -> V_14 ,
V_19 -> V_8 . V_10 ,
V_19 -> V_8 . V_11 ,
V_19 -> V_15 ) ;
}
static void F_22 ( const void * V_16 , bool V_17 )
{
F_7 ( L_39 , * ( const long long unsigned * ) V_16 ) ;
}
static void F_23 ( const void * V_16 , bool V_17 )
{
const struct V_107 * V_19 = V_16 ;
F_7 ( L_40
L_41 ,
V_19 -> V_29 , V_19 -> type , V_19 -> V_108 , V_19 -> V_109 , V_19 -> V_110 ,
V_19 -> V_99 , V_19 -> V_100 ) ;
}
static void F_24 ( const void * V_16 , bool V_17 )
{
const struct V_111 * V_19 = V_16 ;
F_7 ( L_42 ,
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
F_7 ( L_43
L_44 ,
V_19 -> V_120 . V_121 / 3600 ,
( int ) ( V_19 -> V_120 . V_121 / 60 ) % 60 ,
( int ) ( V_19 -> V_120 . V_121 % 60 ) ,
( long ) V_19 -> V_120 . V_122 ,
V_19 -> V_27 ,
F_13 ( V_19 -> type , V_38 ) ,
V_19 -> V_39 , F_13 ( V_19 -> V_60 , V_61 ) ,
V_19 -> V_123 , F_13 ( V_19 -> V_112 , V_113 ) ) ;
if ( F_26 ( V_19 -> type ) && V_19 -> V_124 . V_125 ) {
F_7 ( L_45 ) ;
for ( V_3 = 0 ; V_3 < V_19 -> V_126 ; ++ V_3 ) {
V_119 = & V_19 -> V_124 . V_125 [ V_3 ] ;
F_15 ( V_69
L_46
L_47 ,
V_3 , V_119 -> V_127 , V_119 -> V_128 ,
V_119 -> V_124 . V_129 , V_119 -> V_126 ) ;
}
} else {
F_7 ( L_48 ,
V_19 -> V_127 , V_19 -> V_124 . V_129 , V_19 -> V_126 ) ;
}
F_15 ( V_69 L_49
L_50 ,
V_116 -> V_130 , V_116 -> V_131 , V_116 -> V_132 ,
V_116 -> type , V_116 -> V_39 , V_116 -> V_133 , * ( V_134 * ) V_116 -> V_135 ) ;
}
static void F_27 ( const void * V_16 , bool V_17 )
{
const struct V_136 * V_19 = V_16 ;
F_7 ( L_51 ,
V_19 -> V_137 , F_13 ( V_19 -> type , V_38 ) ,
V_19 -> V_27 , V_19 -> V_119 , V_19 -> V_39 ) ;
}
static void F_28 ( const void * V_16 , bool V_17 )
{
const struct V_138 * V_19 = V_16 ;
F_7 ( L_52 ,
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
F_7 ( L_53
L_54 ,
V_142 -> V_35 , V_142 -> V_145 ,
V_142 -> V_146 . V_10 , V_142 -> V_146 . V_11 ,
V_142 -> V_147 , V_142 -> V_148 ) ;
} else if ( V_19 -> type == V_56 ||
V_19 -> type == V_66 ) {
const struct V_149 * V_142 = & V_19 -> V_143 . V_150 ;
F_7 ( L_55
L_56 ,
V_142 -> V_35 , V_142 -> V_151 ,
V_142 -> V_146 . V_10 , V_142 -> V_146 . V_11 ,
V_142 -> V_147 , V_142 -> V_152 ) ;
} else {
F_7 ( L_45 ) ;
}
}
static void F_30 ( const void * V_16 , bool V_17 )
{
const struct V_153 * V_19 = V_16 ;
F_7 ( L_57
L_58 ,
V_19 -> V_1 , V_19 -> type , ( int ) sizeof( V_19 -> V_14 ) , V_19 -> V_14 ,
V_19 -> V_154 , V_19 -> V_155 ,
V_19 -> V_156 , V_19 -> V_157 , V_19 -> V_39 ) ;
}
static void F_31 ( const void * V_16 , bool V_17 )
{
const struct V_158 * V_19 = V_16 ;
F_7 ( L_59
L_60
L_61 ,
V_19 -> V_1 , V_19 -> type , ( int ) sizeof( V_19 -> V_14 ) , V_19 -> V_14 ,
V_19 -> V_154 , V_19 -> V_155 ,
V_19 -> V_156 , V_19 -> V_157 , V_19 -> V_39 ,
V_19 -> V_159 , V_19 -> V_160 , V_19 -> V_161 ,
V_19 -> V_162 [ 0 ] , V_19 -> V_162 [ 1 ] , V_19 -> V_162 [ 2 ] , V_19 -> V_162 [ 3 ] ) ;
}
static void F_32 ( const void * V_16 , bool V_17 )
{
const struct V_163 * V_19 = V_16 ;
F_7 ( L_62 , V_19 -> V_1 , V_19 -> V_27 ) ;
}
static void F_33 ( const void * V_16 , bool V_17 )
{
const struct V_164 * V_19 = V_16 ;
F_7 ( L_63 , V_19 -> V_1 , V_19 -> V_165 ) ;
}
static void F_34 ( const void * V_16 , bool V_17 )
{
const struct V_166 * V_19 = V_16 ;
int V_3 ;
F_7 ( L_64 ,
V_19 -> V_167 , V_19 -> V_88 , V_19 -> V_168 ) ;
for ( V_3 = 0 ; V_3 < V_19 -> V_88 ; V_3 ++ ) {
if ( ! V_19 -> V_169 [ V_3 ] . V_170 )
F_7 ( L_65 ,
V_19 -> V_169 [ V_3 ] . V_1 , V_19 -> V_169 [ V_3 ] . V_165 ) ;
else
F_7 ( L_66 ,
V_19 -> V_169 [ V_3 ] . V_1 , V_19 -> V_169 [ V_3 ] . V_170 ) ;
}
F_7 ( L_45 ) ;
}
static void F_35 ( const void * V_16 , bool V_17 )
{
const struct V_171 * V_19 = V_16 ;
F_7 ( L_67
L_68
L_69 ,
F_13 ( V_19 -> type , V_38 ) ,
V_19 -> V_172 . V_58 , V_19 -> V_172 . V_59 ,
V_19 -> V_172 . V_74 , V_19 -> V_172 . V_75 ,
V_19 -> V_173 . V_58 , V_19 -> V_173 . V_59 ,
V_19 -> V_173 . V_74 , V_19 -> V_173 . V_75 ,
V_19 -> V_174 . V_10 , V_19 -> V_174 . V_11 ) ;
}
static void F_36 ( const void * V_16 , bool V_17 )
{
const struct V_175 * V_19 = V_16 ;
F_7 ( L_70 ,
F_13 ( V_19 -> type , V_38 ) ,
V_19 -> V_142 . V_58 , V_19 -> V_142 . V_59 ,
V_19 -> V_142 . V_74 , V_19 -> V_142 . V_75 ) ;
}
static void F_37 ( const void * V_16 , bool V_17 )
{
const struct V_176 * V_19 = V_16 ;
F_7 ( L_71 ,
F_13 ( V_19 -> type , V_38 ) ,
V_19 -> V_177 , V_19 -> V_39 ,
V_19 -> V_178 . V_58 , V_19 -> V_178 . V_59 , V_19 -> V_178 . V_74 , V_19 -> V_178 . V_75 ) ;
}
static void F_38 ( const void * V_16 , bool V_17 )
{
const struct V_179 * V_19 = V_16 ;
F_7 ( L_72
L_73 ,
V_19 -> V_180 , V_19 -> V_181 , V_19 -> V_182 ,
V_19 -> V_183 , V_19 -> V_184 ) ;
}
static void F_39 ( const void * V_16 , bool V_17 )
{
const struct V_185 * V_19 = V_16 ;
F_7 ( L_74 ,
V_19 -> V_186 , V_19 -> V_187 ) ;
}
static void F_40 ( const void * V_16 , bool V_17 )
{
const struct V_188 * V_19 = V_16 ;
F_7 ( L_75 ,
V_19 -> V_189 , V_19 -> V_39 ) ;
}
static void F_41 ( const void * V_16 , bool V_17 )
{
const struct V_190 * V_19 = V_16 ;
F_7 ( L_75 , V_19 -> V_189 , V_19 -> V_39 ) ;
if ( V_19 -> V_189 == V_191 )
F_42 ( L_76 ,
V_19 -> V_87 . V_192 , V_19 -> V_87 . V_139 ) ;
else if ( V_19 -> V_189 == V_193 )
F_42 ( L_77 , V_19 -> V_194 . V_195 ) ;
}
static void F_43 ( const void * V_16 , bool V_17 )
{
const struct V_196 * V_19 = V_16 ;
F_7 ( L_78 , V_19 -> V_197 . type ) ;
if ( V_19 -> V_197 . type == V_198 )
F_7 ( L_79 ,
( int ) sizeof( V_19 -> V_197 . V_14 ) , V_19 -> V_197 . V_14 ) ;
else
F_7 ( L_80 , V_19 -> V_197 . V_199 ) ;
F_7 ( L_81 , ( int ) sizeof( V_19 -> V_14 ) , V_19 -> V_14 ) ;
}
static void F_44 ( const void * V_16 , bool V_17 )
{
const struct V_200 * V_19 = V_16 ;
F_7 ( L_78 , V_19 -> V_197 . type ) ;
if ( V_19 -> V_197 . type == V_198 )
F_7 ( L_79 ,
( int ) sizeof( V_19 -> V_197 . V_14 ) , V_19 -> V_197 . V_14 ) ;
else
F_7 ( L_80 , V_19 -> V_197 . V_199 ) ;
F_7 ( L_82 ,
V_19 -> V_201 , V_19 -> V_202 ) ;
}
static void F_45 ( const void * V_16 , bool V_17 )
{
const struct V_203 * V_19 = V_16 ;
switch ( V_19 -> type ) {
case V_204 :
F_7 ( L_83
L_84
L_85
L_86
L_87
L_88
L_89
L_90 ,
V_19 -> V_205 . V_206 , V_19 -> V_205 . V_207 ,
V_19 -> V_205 . V_58 , V_19 -> V_205 . V_59 ,
V_19 -> V_205 . V_208 , V_19 -> V_205 . V_209 ,
V_19 -> V_205 . V_210 , V_19 -> V_205 . V_211 ,
V_19 -> V_205 . V_212 , V_19 -> V_205 . V_213 ,
V_19 -> V_205 . V_214 , V_19 -> V_205 . V_215 ,
V_19 -> V_205 . V_216 , V_19 -> V_205 . V_217 ,
V_19 -> V_205 . V_4 , V_19 -> V_205 . V_39 ) ;
break;
default:
F_7 ( L_91 , V_19 -> type ) ;
break;
}
}
static void F_46 ( const void * V_16 , bool V_17 )
{
const struct V_218 * V_19 = V_16 ;
F_7 ( L_92 , V_19 -> V_27 ) ;
F_45 ( & V_19 -> V_219 , V_17 ) ;
}
static void F_47 ( const void * V_16 , bool V_17 )
{
const struct V_220 * V_19 = V_16 ;
switch ( V_19 -> type ) {
case V_204 :
F_7 ( L_93
L_94 ,
V_19 -> V_205 . V_221 , V_19 -> V_205 . V_222 ,
V_19 -> V_205 . V_223 , V_19 -> V_205 . V_224 ,
V_19 -> V_205 . V_225 , V_19 -> V_205 . V_226 ,
V_19 -> V_205 . V_4 , V_19 -> V_205 . V_24 ) ;
break;
default:
F_7 ( L_95 , V_19 -> type ) ;
break;
}
}
static void F_48 ( const void * V_16 , bool V_17 )
{
const struct V_227 * V_19 = V_16 ;
F_7 ( L_96 ,
V_19 -> V_27 ,
( V_19 -> V_228 & 0xff ) ,
( V_19 -> V_228 >> 8 ) & 0xff ,
( V_19 -> V_228 >> 16 ) & 0xff ,
( V_19 -> V_228 >> 24 ) & 0xff ,
V_19 -> type ) ;
switch ( V_19 -> type ) {
case V_229 :
F_7 ( L_97 ,
V_19 -> V_230 . V_58 , V_19 -> V_230 . V_59 ) ;
break;
case V_231 :
F_7 ( L_98 ,
V_19 -> V_232 . V_221 , V_19 -> V_232 . V_223 ,
V_19 -> V_232 . V_233 , V_19 -> V_232 . V_234 ,
V_19 -> V_232 . V_222 , V_19 -> V_232 . V_224 ) ;
break;
case V_235 :
default:
F_7 ( L_45 ) ;
break;
}
}
static void F_49 ( const void * V_16 , bool V_17 )
{
const struct V_236 * V_19 = V_16 ;
F_7 ( L_99 ,
V_19 -> V_27 ,
( V_19 -> V_228 & 0xff ) ,
( V_19 -> V_228 >> 8 ) & 0xff ,
( V_19 -> V_228 >> 16 ) & 0xff ,
( V_19 -> V_228 >> 24 ) & 0xff ,
V_19 -> V_58 , V_19 -> V_59 , V_19 -> type ) ;
switch ( V_19 -> type ) {
case V_237 :
F_7 ( L_100 ,
V_19 -> V_230 . V_10 ,
V_19 -> V_230 . V_11 ) ;
break;
case V_238 :
F_7 ( L_101 ,
V_19 -> V_232 . V_239 . V_10 ,
V_19 -> V_232 . V_239 . V_11 ,
V_19 -> V_232 . V_240 . V_10 ,
V_19 -> V_232 . V_240 . V_11 ,
V_19 -> V_232 . V_156 . V_10 ,
V_19 -> V_232 . V_156 . V_11 ) ;
break;
case V_241 :
default:
F_7 ( L_45 ) ;
break;
}
}
static void F_50 ( const void * V_16 , bool V_17 )
{
const struct V_242 * V_19 = V_16 ;
const struct V_243 * V_142 ;
F_7 ( L_102
L_103 ,
V_19 -> type , V_19 -> V_244 , V_19 -> V_123 , V_19 -> V_1 ,
V_19 -> V_120 . V_121 , V_19 -> V_120 . V_245 ) ;
switch ( V_19 -> type ) {
case V_246 :
F_15 ( V_69 L_104 ,
F_13 ( V_19 -> V_247 . V_213 . V_60 , V_61 ) ) ;
break;
case V_248 :
V_142 = & V_19 -> V_247 . V_249 ;
F_15 ( V_69 L_105 ,
V_142 -> V_250 , V_142 -> type ) ;
if ( V_142 -> type == V_251 )
F_7 ( L_106 , V_142 -> V_252 ) ;
else
F_7 ( L_107 , V_142 -> V_165 ) ;
F_7 ( L_108
L_109 ,
V_142 -> V_39 , V_142 -> V_154 , V_142 -> V_155 ,
V_142 -> V_156 , V_142 -> V_157 ) ;
break;
case V_253 :
F_7 ( L_110 ,
V_19 -> V_247 . V_254 . V_255 ) ;
break;
}
}
static void F_51 ( const void * V_16 , bool V_17 )
{
const struct V_256 * V_19 = V_16 ;
F_7 ( L_111 ,
V_19 -> type , V_19 -> V_1 , V_19 -> V_39 ) ;
}
static void F_52 ( const void * V_16 , bool V_17 )
{
const struct V_257 * V_19 = V_16 ;
int V_3 ;
F_7 ( L_112 ,
F_13 ( V_19 -> type , V_38 ) , V_19 -> V_91 ) ;
for ( V_3 = 0 ; V_3 < 24 ; V_3 ++ )
F_15 ( V_69 L_23 , V_3 ,
V_19 -> V_93 [ 0 ] [ V_3 ] ,
V_19 -> V_93 [ 1 ] [ V_3 ] ) ;
}
static void F_53 ( const void * V_16 , bool V_17 )
{
const struct V_258 * V_19 = V_16 ;
F_7 ( L_113
L_114 ,
V_19 -> V_29 , V_19 -> type , V_19 -> V_27 ,
V_19 -> V_35 , V_19 -> V_99 ,
V_19 -> V_100 , V_19 -> V_259 ) ;
}
static void F_54 ( const void * V_16 , bool V_17 )
{
const struct V_260 * V_19 = V_16 ;
F_7 ( L_115 ,
V_19 -> V_261 , V_19 -> V_262 , V_19 -> V_263 ) ;
}
static void F_55 ( const void * V_16 , bool V_17 )
{
F_7 ( L_116 , * ( const T_2 * ) V_16 ) ;
}
static void F_56 ( const void * V_16 , bool V_17 )
{
F_7 ( L_45 ) ;
}
static void F_57 ( const void * V_16 , bool V_17 )
{
F_7 ( L_117 ) ;
}
static int F_58 ( struct V_166 * V_142 , int V_264 )
{
V_134 V_3 ;
V_142 -> V_265 [ 0 ] = V_142 -> V_265 [ 1 ] = 0 ;
for ( V_3 = 0 ; V_3 < V_142 -> V_88 ; V_3 ++ )
V_142 -> V_169 [ V_3 ] . V_266 [ 0 ] = 0 ;
if ( ! V_264 && V_142 -> V_167 == V_267 )
return 0 ;
for ( V_3 = 0 ; V_3 < V_142 -> V_88 ; V_3 ++ ) {
if ( F_59 ( V_142 -> V_169 [ V_3 ] . V_1 ) != V_142 -> V_167 ) {
V_142 -> V_168 = V_3 ;
return 0 ;
}
}
return 1 ;
}
static int F_60 ( struct V_268 * V_268 , enum V_269 type )
{
struct V_270 * V_271 = F_61 ( V_268 ) ;
const struct V_272 * V_273 = V_271 -> V_274 ;
bool V_275 = V_271 -> V_276 == V_277 ;
bool V_278 = V_271 -> V_276 == V_279 ;
bool V_280 = V_271 -> V_276 == V_281 ;
bool V_282 = V_271 -> V_283 != V_284 ;
bool V_285 = V_271 -> V_283 != V_286 ;
if ( V_273 == NULL )
return - V_287 ;
switch ( type ) {
case V_55 :
if ( V_275 && V_282 &&
( V_273 -> V_288 || V_273 -> V_289 ) )
return 0 ;
break;
case V_65 :
if ( V_275 && V_282 && V_273 -> V_289 )
return 0 ;
break;
case V_71 :
if ( V_275 && V_282 && V_273 -> V_290 )
return 0 ;
break;
case V_56 :
if ( V_275 && V_285 &&
( V_273 -> V_291 || V_273 -> V_292 ) )
return 0 ;
break;
case V_66 :
if ( V_275 && V_285 && V_273 -> V_292 )
return 0 ;
break;
case V_72 :
if ( V_275 && V_285 && V_273 -> V_293 )
return 0 ;
break;
case V_81 :
if ( V_278 && V_282 && V_273 -> V_294 )
return 0 ;
break;
case V_82 :
if ( V_278 && V_285 && V_273 -> V_295 )
return 0 ;
break;
case V_89 :
if ( V_278 && V_282 && V_273 -> V_296 )
return 0 ;
break;
case V_90 :
if ( V_278 && V_285 && V_273 -> V_297 )
return 0 ;
break;
case V_94 :
if ( V_280 && V_282 && V_273 -> V_298 )
return 0 ;
break;
default:
break;
}
return - V_287 ;
}
static void F_62 ( struct V_42 * V_57 )
{
unsigned int V_84 ;
if ( V_57 -> type != V_55 &&
V_57 -> type != V_56 )
return;
if ( V_57 -> V_57 . V_44 . V_299 == V_300 )
return;
V_57 -> V_57 . V_44 . V_299 = V_300 ;
V_84 = F_63 ( struct V_43 , V_299 )
+ sizeof( V_57 -> V_57 . V_44 . V_299 ) ;
memset ( ( ( void * ) & V_57 -> V_57 . V_44 ) + V_84 , 0 ,
sizeof( V_57 -> V_57 . V_44 ) - V_84 ) ;
}
static int F_64 ( const struct V_272 * V_273 ,
struct V_268 * V_268 , void * V_301 , void * V_16 )
{
struct V_18 * V_302 = (struct V_18 * ) V_16 ;
int V_303 ;
V_302 -> V_23 = V_304 ;
V_303 = V_273 -> V_305 ( V_268 , V_301 , V_302 ) ;
V_302 -> V_24 |= V_306 ;
V_302 -> V_25 |= V_306 ;
return V_303 ;
}
static int F_65 ( const struct V_272 * V_273 ,
struct V_268 * V_268 , void * V_301 , void * V_16 )
{
return V_273 -> V_307 ( V_268 , V_301 , * ( unsigned int * ) V_16 ) ;
}
static int F_66 ( const struct V_272 * V_273 ,
struct V_268 * V_268 , void * V_301 , void * V_16 )
{
return V_273 -> V_308 ( V_268 , V_301 , * ( unsigned int * ) V_16 ) ;
}
static int F_67 ( const struct V_272 * V_273 ,
struct V_268 * V_268 , void * V_301 , void * V_16 )
{
struct V_270 * V_271 ;
T_2 * V_19 = V_16 ;
if ( V_273 -> V_309 )
return V_273 -> V_309 ( V_268 , V_301 , V_16 ) ;
V_271 = F_61 ( V_268 ) ;
* V_19 = F_68 ( & V_271 -> V_310 -> V_311 ) ;
return 0 ;
}
static int F_69 ( const struct V_272 * V_273 ,
struct V_268 * V_268 , void * V_301 , void * V_16 )
{
struct V_270 * V_271 ;
struct V_312 * V_313 ;
T_2 * V_19 = V_16 ;
if ( V_273 -> V_314 )
return V_273 -> V_314 ( V_268 , V_301 , * V_19 ) ;
V_271 = F_61 ( V_268 ) ;
V_313 = V_268 -> V_315 ;
return F_70 ( & V_271 -> V_310 -> V_311 , & V_313 -> V_311 , * V_19 ) ;
}
static int F_71 ( const struct V_272 * V_273 ,
struct V_268 * V_268 , void * V_301 , void * V_16 )
{
struct V_270 * V_271 = F_61 ( V_268 ) ;
struct V_26 * V_19 = V_16 ;
if ( F_72 ( V_271 , V_316 ) )
V_19 -> V_24 |= V_317 ;
return V_273 -> V_318 ( V_268 , V_301 , V_19 ) ;
}
static int F_73 ( const struct V_272 * V_273 ,
struct V_268 * V_268 , void * V_301 , void * V_16 )
{
struct V_270 * V_271 = F_61 ( V_268 ) ;
struct V_31 * V_19 = V_16 ;
if ( F_72 ( V_271 , V_316 ) )
V_19 -> V_24 |= V_319 ;
return V_273 -> V_320 ( V_268 , V_301 , V_19 ) ;
}
static int F_74 ( const struct V_272 * V_273 ,
struct V_268 * V_268 , void * V_301 , void * V_16 )
{
struct V_37 * V_19 = V_16 ;
struct V_270 * V_271 = F_61 ( V_268 ) ;
bool V_275 = V_271 -> V_276 == V_277 ;
bool V_280 = V_271 -> V_276 == V_281 ;
bool V_282 = V_271 -> V_283 != V_284 ;
bool V_285 = V_271 -> V_283 != V_286 ;
switch ( V_19 -> type ) {
case V_55 :
if ( F_75 ( ! V_282 || ! V_275 || ! V_273 -> V_321 ) )
break;
return V_273 -> V_321 ( V_268 , V_301 , V_16 ) ;
case V_65 :
if ( F_75 ( ! V_282 || ! V_275 || ! V_273 -> V_322 ) )
break;
return V_273 -> V_322 ( V_268 , V_301 , V_16 ) ;
case V_71 :
if ( F_75 ( ! V_282 || ! V_275 || ! V_273 -> V_323 ) )
break;
return V_273 -> V_323 ( V_268 , V_301 , V_16 ) ;
case V_56 :
if ( F_75 ( ! V_285 || ! V_275 || ! V_273 -> V_324 ) )
break;
return V_273 -> V_324 ( V_268 , V_301 , V_16 ) ;
case V_66 :
if ( F_75 ( ! V_285 || ! V_275 || ! V_273 -> V_325 ) )
break;
return V_273 -> V_325 ( V_268 , V_301 , V_16 ) ;
case V_94 :
if ( F_75 ( ! V_282 || ! V_280 || ! V_273 -> V_326 ) )
break;
return V_273 -> V_326 ( V_268 , V_301 , V_16 ) ;
}
return - V_287 ;
}
static int F_76 ( const struct V_272 * V_273 ,
struct V_268 * V_268 , void * V_301 , void * V_16 )
{
struct V_42 * V_19 = V_16 ;
struct V_270 * V_271 = F_61 ( V_268 ) ;
bool V_275 = V_271 -> V_276 == V_277 ;
bool V_280 = V_271 -> V_276 == V_281 ;
bool V_282 = V_271 -> V_283 != V_284 ;
bool V_285 = V_271 -> V_283 != V_286 ;
int V_303 ;
switch ( V_19 -> type ) {
case V_71 :
case V_72 : {
struct V_327 T_3 * V_78 = V_19 -> V_57 . V_52 . V_78 ;
T_2 V_77 = V_19 -> V_57 . V_52 . V_77 ;
void T_3 * V_79 = V_19 -> V_57 . V_52 . V_79 ;
memset ( & V_19 -> V_57 , 0 , sizeof( V_19 -> V_57 ) ) ;
V_19 -> V_57 . V_52 . V_78 = V_78 ;
V_19 -> V_57 . V_52 . V_77 = V_77 ;
V_19 -> V_57 . V_52 . V_79 = V_79 ;
break;
}
default:
memset ( & V_19 -> V_57 , 0 , sizeof( V_19 -> V_57 ) ) ;
break;
}
switch ( V_19 -> type ) {
case V_55 :
if ( F_75 ( ! V_282 || ! V_275 || ! V_273 -> V_288 ) )
break;
V_19 -> V_57 . V_44 . V_299 = V_300 ;
V_303 = V_273 -> V_288 ( V_268 , V_301 , V_16 ) ;
V_19 -> V_57 . V_44 . V_299 = V_300 ;
return V_303 ;
case V_65 :
if ( F_75 ( ! V_282 || ! V_275 || ! V_273 -> V_289 ) )
break;
return V_273 -> V_289 ( V_268 , V_301 , V_16 ) ;
case V_71 :
if ( F_75 ( ! V_282 || ! V_275 || ! V_273 -> V_290 ) )
break;
return V_273 -> V_290 ( V_268 , V_301 , V_16 ) ;
case V_81 :
if ( F_75 ( ! V_282 || V_275 || ! V_273 -> V_294 ) )
break;
return V_273 -> V_294 ( V_268 , V_301 , V_16 ) ;
case V_89 :
if ( F_75 ( ! V_282 || V_275 || ! V_273 -> V_296 ) )
break;
return V_273 -> V_296 ( V_268 , V_301 , V_16 ) ;
case V_56 :
if ( F_75 ( ! V_285 || ! V_275 || ! V_273 -> V_291 ) )
break;
V_19 -> V_57 . V_44 . V_299 = V_300 ;
V_303 = V_273 -> V_291 ( V_268 , V_301 , V_16 ) ;
V_19 -> V_57 . V_44 . V_299 = V_300 ;
return V_303 ;
case V_66 :
if ( F_75 ( ! V_285 || ! V_275 || ! V_273 -> V_292 ) )
break;
return V_273 -> V_292 ( V_268 , V_301 , V_16 ) ;
case V_72 :
if ( F_75 ( ! V_285 || ! V_275 || ! V_273 -> V_293 ) )
break;
return V_273 -> V_293 ( V_268 , V_301 , V_16 ) ;
case V_82 :
if ( F_75 ( ! V_285 || V_275 || ! V_273 -> V_295 ) )
break;
return V_273 -> V_295 ( V_268 , V_301 , V_16 ) ;
case V_90 :
if ( F_75 ( ! V_285 || V_275 || ! V_273 -> V_297 ) )
break;
return V_273 -> V_297 ( V_268 , V_301 , V_16 ) ;
case V_94 :
if ( F_75 ( ! V_282 || ! V_280 || ! V_273 -> V_298 ) )
break;
return V_273 -> V_298 ( V_268 , V_301 , V_16 ) ;
}
return - V_287 ;
}
static int F_77 ( const struct V_272 * V_273 ,
struct V_268 * V_268 , void * V_301 , void * V_16 )
{
struct V_42 * V_19 = V_16 ;
struct V_270 * V_271 = F_61 ( V_268 ) ;
bool V_275 = V_271 -> V_276 == V_277 ;
bool V_280 = V_271 -> V_276 == V_281 ;
bool V_282 = V_271 -> V_283 != V_284 ;
bool V_285 = V_271 -> V_283 != V_286 ;
int V_303 ;
F_62 ( V_19 ) ;
switch ( V_19 -> type ) {
case V_55 :
if ( F_75 ( ! V_282 || ! V_275 || ! V_273 -> V_328 ) )
break;
F_78 ( V_19 , V_57 . V_44 ) ;
V_303 = V_273 -> V_328 ( V_268 , V_301 , V_16 ) ;
V_19 -> V_57 . V_44 . V_299 = V_300 ;
return V_303 ;
case V_65 :
if ( F_75 ( ! V_282 || ! V_275 || ! V_273 -> V_329 ) )
break;
F_78 ( V_19 , V_57 . V_67 ) ;
return V_273 -> V_329 ( V_268 , V_301 , V_16 ) ;
case V_71 :
if ( F_75 ( ! V_282 || ! V_275 || ! V_273 -> V_330 ) )
break;
F_78 ( V_19 , V_57 . V_52 ) ;
return V_273 -> V_330 ( V_268 , V_301 , V_16 ) ;
case V_81 :
if ( F_75 ( ! V_282 || V_275 || ! V_273 -> V_331 ) )
break;
F_78 ( V_19 , V_57 . V_48 ) ;
return V_273 -> V_331 ( V_268 , V_301 , V_16 ) ;
case V_89 :
if ( F_75 ( ! V_282 || V_275 || ! V_273 -> V_332 ) )
break;
F_78 ( V_19 , V_57 . V_50 ) ;
return V_273 -> V_332 ( V_268 , V_301 , V_16 ) ;
case V_56 :
if ( F_75 ( ! V_285 || ! V_275 || ! V_273 -> V_333 ) )
break;
F_78 ( V_19 , V_57 . V_44 ) ;
V_303 = V_273 -> V_333 ( V_268 , V_301 , V_16 ) ;
V_19 -> V_57 . V_44 . V_299 = V_300 ;
return V_303 ;
case V_66 :
if ( F_75 ( ! V_285 || ! V_275 || ! V_273 -> V_334 ) )
break;
F_78 ( V_19 , V_57 . V_67 ) ;
return V_273 -> V_334 ( V_268 , V_301 , V_16 ) ;
case V_72 :
if ( F_75 ( ! V_285 || ! V_275 || ! V_273 -> V_335 ) )
break;
F_78 ( V_19 , V_57 . V_52 ) ;
return V_273 -> V_335 ( V_268 , V_301 , V_16 ) ;
case V_82 :
if ( F_75 ( ! V_285 || V_275 || ! V_273 -> V_336 ) )
break;
F_78 ( V_19 , V_57 . V_48 ) ;
return V_273 -> V_336 ( V_268 , V_301 , V_16 ) ;
case V_90 :
if ( F_75 ( ! V_285 || V_275 || ! V_273 -> V_337 ) )
break;
F_78 ( V_19 , V_57 . V_50 ) ;
return V_273 -> V_337 ( V_268 , V_301 , V_16 ) ;
case V_94 :
if ( F_75 ( ! V_282 || ! V_280 || ! V_273 -> V_338 ) )
break;
F_78 ( V_19 , V_57 . V_54 ) ;
return V_273 -> V_338 ( V_268 , V_301 , V_16 ) ;
}
return - V_287 ;
}
static int F_79 ( const struct V_272 * V_273 ,
struct V_268 * V_268 , void * V_301 , void * V_16 )
{
struct V_42 * V_19 = V_16 ;
struct V_270 * V_271 = F_61 ( V_268 ) ;
bool V_275 = V_271 -> V_276 == V_277 ;
bool V_280 = V_271 -> V_276 == V_281 ;
bool V_282 = V_271 -> V_283 != V_284 ;
bool V_285 = V_271 -> V_283 != V_286 ;
int V_303 ;
F_62 ( V_19 ) ;
switch ( V_19 -> type ) {
case V_55 :
if ( F_75 ( ! V_282 || ! V_275 || ! V_273 -> V_339 ) )
break;
F_78 ( V_19 , V_57 . V_44 ) ;
V_303 = V_273 -> V_339 ( V_268 , V_301 , V_16 ) ;
V_19 -> V_57 . V_44 . V_299 = V_300 ;
return V_303 ;
case V_65 :
if ( F_75 ( ! V_282 || ! V_275 || ! V_273 -> V_340 ) )
break;
F_78 ( V_19 , V_57 . V_67 ) ;
return V_273 -> V_340 ( V_268 , V_301 , V_16 ) ;
case V_71 :
if ( F_75 ( ! V_282 || ! V_275 || ! V_273 -> V_341 ) )
break;
F_78 ( V_19 , V_57 . V_52 ) ;
return V_273 -> V_341 ( V_268 , V_301 , V_16 ) ;
case V_81 :
if ( F_75 ( ! V_282 || V_275 || ! V_273 -> V_342 ) )
break;
F_78 ( V_19 , V_57 . V_48 ) ;
return V_273 -> V_342 ( V_268 , V_301 , V_16 ) ;
case V_89 :
if ( F_75 ( ! V_282 || V_275 || ! V_273 -> V_343 ) )
break;
F_78 ( V_19 , V_57 . V_50 ) ;
return V_273 -> V_343 ( V_268 , V_301 , V_16 ) ;
case V_56 :
if ( F_75 ( ! V_285 || ! V_275 || ! V_273 -> V_344 ) )
break;
F_78 ( V_19 , V_57 . V_44 ) ;
V_303 = V_273 -> V_344 ( V_268 , V_301 , V_16 ) ;
V_19 -> V_57 . V_44 . V_299 = V_300 ;
return V_303 ;
case V_66 :
if ( F_75 ( ! V_285 || ! V_275 || ! V_273 -> V_345 ) )
break;
F_78 ( V_19 , V_57 . V_67 ) ;
return V_273 -> V_345 ( V_268 , V_301 , V_16 ) ;
case V_72 :
if ( F_75 ( ! V_285 || ! V_275 || ! V_273 -> V_346 ) )
break;
F_78 ( V_19 , V_57 . V_52 ) ;
return V_273 -> V_346 ( V_268 , V_301 , V_16 ) ;
case V_82 :
if ( F_75 ( ! V_285 || V_275 || ! V_273 -> V_347 ) )
break;
F_78 ( V_19 , V_57 . V_48 ) ;
return V_273 -> V_347 ( V_268 , V_301 , V_16 ) ;
case V_90 :
if ( F_75 ( ! V_285 || V_275 || ! V_273 -> V_348 ) )
break;
F_78 ( V_19 , V_57 . V_50 ) ;
return V_273 -> V_348 ( V_268 , V_301 , V_16 ) ;
case V_94 :
if ( F_75 ( ! V_282 || ! V_280 || ! V_273 -> V_349 ) )
break;
F_78 ( V_19 , V_57 . V_54 ) ;
return V_273 -> V_349 ( V_268 , V_301 , V_16 ) ;
}
return - V_287 ;
}
static int F_80 ( const struct V_272 * V_273 ,
struct V_268 * V_268 , void * V_301 , void * V_16 )
{
return V_273 -> V_350 ( V_268 , V_301 , * ( unsigned int * ) V_16 ) ;
}
static int F_81 ( const struct V_272 * V_273 ,
struct V_268 * V_268 , void * V_301 , void * V_16 )
{
return V_273 -> V_351 ( V_268 , V_301 , * ( unsigned int * ) V_16 ) ;
}
static int F_82 ( const struct V_272 * V_273 ,
struct V_268 * V_268 , void * V_301 , void * V_16 )
{
struct V_270 * V_271 = F_61 ( V_268 ) ;
struct V_101 * V_19 = V_16 ;
int V_352 ;
V_19 -> type = ( V_271 -> V_276 == V_353 ) ?
V_354 : V_355 ;
V_352 = V_273 -> V_356 ( V_268 , V_301 , V_19 ) ;
if ( ! V_352 )
V_19 -> V_35 |= V_357 ;
return V_352 ;
}
static int F_83 ( const struct V_272 * V_273 ,
struct V_268 * V_268 , void * V_301 , void * V_16 )
{
struct V_270 * V_271 = F_61 ( V_268 ) ;
struct V_101 * V_19 = V_16 ;
V_19 -> type = ( V_271 -> V_276 == V_353 ) ?
V_354 : V_355 ;
return V_273 -> V_358 ( V_268 , V_301 , V_19 ) ;
}
static int F_84 ( const struct V_272 * V_273 ,
struct V_268 * V_268 , void * V_301 , void * V_16 )
{
struct V_97 * V_19 = V_16 ;
int V_352 ;
V_352 = V_273 -> V_359 ( V_268 , V_301 , V_19 ) ;
if ( ! V_352 )
V_19 -> V_35 |= V_357 ;
return V_352 ;
}
static int F_85 ( const struct V_272 * V_273 ,
struct V_268 * V_268 , void * V_301 , void * V_16 )
{
struct V_270 * V_271 = F_61 ( V_268 ) ;
struct V_105 * V_19 = V_16 ;
if ( V_271 -> V_276 == V_281 )
V_19 -> type = V_360 ;
else
V_19 -> type = ( V_271 -> V_276 == V_353 ) ?
V_354 : V_355 ;
return V_273 -> V_361 ( V_268 , V_301 , V_19 ) ;
}
static int F_86 ( const struct V_272 * V_273 ,
struct V_268 * V_268 , void * V_301 , void * V_16 )
{
struct V_270 * V_271 = F_61 ( V_268 ) ;
const struct V_105 * V_19 = V_16 ;
enum V_362 type ;
if ( V_271 -> V_276 == V_281 ) {
if ( V_19 -> type != V_360 && V_19 -> type != V_363 )
return - V_287 ;
} else {
type = ( V_271 -> V_276 == V_353 ) ?
V_354 : V_355 ;
if ( type != V_19 -> type )
return - V_287 ;
}
return V_273 -> V_364 ( V_268 , V_301 , V_19 ) ;
}
static int F_87 ( const struct V_272 * V_273 ,
struct V_268 * V_268 , void * V_301 , void * V_16 )
{
struct V_270 * V_271 = F_61 ( V_268 ) ;
struct V_12 * V_19 = V_16 ;
T_1 V_1 = V_271 -> V_365 , V_366 = 0 ;
unsigned int V_27 = V_19 -> V_27 , V_3 , V_367 = 0 ;
const char * V_6 = L_118 ;
if ( V_1 == 0 )
return - V_368 ;
for ( V_3 = 0 ; V_3 <= V_27 && V_1 ; V_3 ++ ) {
while ( ( V_1 & V_4 [ V_367 ] . V_5 ) != V_4 [ V_367 ] . V_5 )
V_367 ++ ;
V_366 = V_4 [ V_367 ] . V_5 ;
V_6 = V_4 [ V_367 ] . V_6 ;
V_367 ++ ;
if ( V_366 == 0 )
break;
if ( V_366 != V_369 &&
V_366 != V_370 &&
V_366 != V_371 )
V_1 &= ~ V_366 ;
}
if ( V_3 <= V_27 )
return - V_287 ;
F_4 ( V_19 , V_366 , V_6 ) ;
return 0 ;
}
static int F_88 ( const struct V_272 * V_273 ,
struct V_268 * V_268 , void * V_301 , void * V_16 )
{
struct V_270 * V_271 = F_61 ( V_268 ) ;
T_1 V_1 = * ( T_1 * ) V_16 , V_372 ;
V_372 = V_1 & V_271 -> V_365 ;
if ( V_271 -> V_365 && ! V_372 )
return - V_287 ;
return V_273 -> V_373 ( V_268 , V_301 , V_372 ) ;
}
static int F_89 ( const struct V_272 * V_273 ,
struct V_268 * V_268 , void * V_301 , void * V_16 )
{
struct V_270 * V_271 = F_61 ( V_268 ) ;
T_1 * V_19 = V_16 ;
* V_19 = V_271 -> V_365 ;
return V_273 -> V_374 ( V_268 , V_301 , V_16 ) ;
}
static int F_90 ( const struct V_272 * V_273 ,
struct V_268 * V_268 , void * V_301 , void * V_16 )
{
struct V_270 * V_271 = F_61 ( V_268 ) ;
struct V_107 * V_19 = V_16 ;
enum V_362 type ;
if ( V_271 -> V_276 == V_281 )
return - V_287 ;
type = ( V_271 -> V_276 == V_353 ) ?
V_354 : V_355 ;
if ( V_19 -> type != type )
return - V_287 ;
return V_273 -> V_375 ( V_268 , V_301 , V_19 ) ;
}
static int F_91 ( const struct V_272 * V_273 ,
struct V_268 * V_268 , void * V_301 , void * V_16 )
{
return V_273 -> V_376 ( V_268 , V_301 , * ( unsigned int * ) V_16 ) ;
}
static int F_92 ( const struct V_272 * V_273 ,
struct V_268 * V_268 , void * V_301 , void * V_16 )
{
struct V_111 * V_19 = V_16 ;
int V_303 = F_60 ( V_268 , V_19 -> type ) ;
if ( V_303 )
return V_303 ;
F_78 ( V_19 , V_112 ) ;
return V_273 -> V_377 ( V_268 , V_301 , V_19 ) ;
}
static int F_93 ( const struct V_272 * V_273 ,
struct V_268 * V_268 , void * V_301 , void * V_16 )
{
struct V_114 * V_19 = V_16 ;
int V_303 = F_60 ( V_268 , V_19 -> type ) ;
return V_303 ? V_303 : V_273 -> V_378 ( V_268 , V_301 , V_19 ) ;
}
static int F_94 ( const struct V_272 * V_273 ,
struct V_268 * V_268 , void * V_301 , void * V_16 )
{
struct V_114 * V_19 = V_16 ;
int V_303 = F_60 ( V_268 , V_19 -> type ) ;
return V_303 ? V_303 : V_273 -> V_379 ( V_268 , V_301 , V_19 ) ;
}
static int F_95 ( const struct V_272 * V_273 ,
struct V_268 * V_268 , void * V_301 , void * V_16 )
{
struct V_114 * V_19 = V_16 ;
int V_303 = F_60 ( V_268 , V_19 -> type ) ;
return V_303 ? V_303 : V_273 -> V_380 ( V_268 , V_301 , V_19 ) ;
}
static int F_96 ( const struct V_272 * V_273 ,
struct V_268 * V_268 , void * V_301 , void * V_16 )
{
struct V_138 * V_381 = V_16 ;
int V_303 = F_60 ( V_268 , V_381 -> V_139 . type ) ;
if ( V_303 )
return V_303 ;
F_62 ( & V_381 -> V_139 ) ;
V_303 = V_273 -> V_382 ( V_268 , V_301 , V_381 ) ;
if ( V_381 -> V_139 . type == V_55 ||
V_381 -> V_139 . type == V_56 )
V_381 -> V_139 . V_57 . V_44 . V_299 = V_300 ;
return V_303 ;
}
static int F_97 ( const struct V_272 * V_273 ,
struct V_268 * V_268 , void * V_301 , void * V_16 )
{
struct V_114 * V_383 = V_16 ;
int V_303 = F_60 ( V_268 , V_383 -> type ) ;
return V_303 ? V_303 : V_273 -> V_384 ( V_268 , V_301 , V_383 ) ;
}
static int F_98 ( const struct V_272 * V_273 ,
struct V_268 * V_268 , void * V_301 , void * V_16 )
{
struct V_140 * V_19 = V_16 ;
T_1 V_5 ;
int V_303 = F_60 ( V_268 , V_19 -> type ) ;
if ( V_303 )
return V_303 ;
if ( V_273 -> V_385 )
return V_273 -> V_385 ( V_268 , V_301 , V_19 ) ;
if ( V_19 -> type != V_55 &&
V_19 -> type != V_65 )
return - V_287 ;
V_19 -> V_143 . V_144 . V_148 = 2 ;
V_303 = V_273 -> V_386 ( V_268 , V_301 , & V_5 ) ;
if ( V_303 == 0 )
F_3 ( V_5 , & V_19 -> V_143 . V_144 . V_146 ) ;
return V_303 ;
}
static int F_99 ( const struct V_272 * V_273 ,
struct V_268 * V_268 , void * V_301 , void * V_16 )
{
struct V_140 * V_19 = V_16 ;
int V_303 = F_60 ( V_268 , V_19 -> type ) ;
return V_303 ? V_303 : V_273 -> V_387 ( V_268 , V_301 , V_19 ) ;
}
static int F_100 ( const struct V_272 * V_273 ,
struct V_268 * V_268 , void * V_301 , void * V_16 )
{
struct V_270 * V_271 = F_61 ( V_268 ) ;
struct V_153 * V_19 = V_16 ;
struct V_312 * V_313 =
F_101 ( V_388 , & V_271 -> V_39 ) ? V_301 : NULL ;
if ( V_313 && V_313 -> V_389 )
return V_153 ( V_313 -> V_389 , V_19 ) ;
if ( V_271 -> V_389 )
return V_153 ( V_271 -> V_389 , V_19 ) ;
if ( V_273 -> V_390 )
return V_273 -> V_390 ( V_268 , V_301 , V_19 ) ;
return - V_391 ;
}
static int F_102 ( const struct V_272 * V_273 ,
struct V_268 * V_268 , void * V_301 , void * V_16 )
{
struct V_270 * V_271 = F_61 ( V_268 ) ;
struct V_158 * V_19 = V_16 ;
struct V_312 * V_313 =
F_101 ( V_388 , & V_271 -> V_39 ) ? V_301 : NULL ;
if ( V_313 && V_313 -> V_389 )
return V_158 ( V_313 -> V_389 , V_19 ) ;
if ( V_271 -> V_389 )
return V_158 ( V_271 -> V_389 , V_19 ) ;
if ( V_273 -> V_392 )
return V_273 -> V_392 ( V_268 , V_301 , V_19 ) ;
return - V_391 ;
}
static int F_103 ( const struct V_272 * V_273 ,
struct V_268 * V_268 , void * V_301 , void * V_16 )
{
struct V_270 * V_271 = F_61 ( V_268 ) ;
struct V_163 * V_19 = V_16 ;
struct V_312 * V_313 =
F_101 ( V_388 , & V_271 -> V_39 ) ? V_301 : NULL ;
if ( V_313 && V_313 -> V_389 )
return V_163 ( V_313 -> V_389 , V_19 ) ;
if ( V_271 -> V_389 )
return V_163 ( V_271 -> V_389 , V_19 ) ;
if ( V_273 -> V_393 )
return V_273 -> V_393 ( V_268 , V_301 , V_19 ) ;
return - V_391 ;
}
static int F_104 ( const struct V_272 * V_273 ,
struct V_268 * V_268 , void * V_301 , void * V_16 )
{
struct V_270 * V_271 = F_61 ( V_268 ) ;
struct V_164 * V_19 = V_16 ;
struct V_312 * V_313 =
F_101 ( V_388 , & V_271 -> V_39 ) ? V_301 : NULL ;
struct V_166 V_394 ;
struct V_395 V_249 ;
if ( V_313 && V_313 -> V_389 )
return F_105 ( V_313 -> V_389 , V_19 ) ;
if ( V_271 -> V_389 )
return F_105 ( V_271 -> V_389 , V_19 ) ;
if ( V_273 -> V_396 )
return V_273 -> V_396 ( V_268 , V_301 , V_19 ) ;
if ( V_273 -> V_397 == NULL )
return - V_391 ;
V_394 . V_167 = F_59 ( V_19 -> V_1 ) ;
V_394 . V_88 = 1 ;
V_394 . V_169 = & V_249 ;
V_249 . V_1 = V_19 -> V_1 ;
V_249 . V_165 = V_19 -> V_165 ;
if ( F_58 ( & V_394 , 1 ) ) {
int V_303 = V_273 -> V_397 ( V_268 , V_301 , & V_394 ) ;
if ( V_303 == 0 )
V_19 -> V_165 = V_249 . V_165 ;
return V_303 ;
}
return - V_287 ;
}
static int F_106 ( const struct V_272 * V_273 ,
struct V_268 * V_268 , void * V_301 , void * V_16 )
{
struct V_270 * V_271 = F_61 ( V_268 ) ;
struct V_164 * V_19 = V_16 ;
struct V_312 * V_313 =
F_101 ( V_388 , & V_271 -> V_39 ) ? V_301 : NULL ;
struct V_166 V_394 ;
struct V_395 V_249 ;
if ( V_313 && V_313 -> V_389 )
return F_107 ( V_313 , V_313 -> V_389 , V_19 ) ;
if ( V_271 -> V_389 )
return F_107 ( NULL , V_271 -> V_389 , V_19 ) ;
if ( V_273 -> V_398 )
return V_273 -> V_398 ( V_268 , V_301 , V_19 ) ;
if ( V_273 -> V_399 == NULL )
return - V_391 ;
V_394 . V_167 = F_59 ( V_19 -> V_1 ) ;
V_394 . V_88 = 1 ;
V_394 . V_169 = & V_249 ;
V_249 . V_1 = V_19 -> V_1 ;
V_249 . V_165 = V_19 -> V_165 ;
if ( F_58 ( & V_394 , 1 ) )
return V_273 -> V_399 ( V_268 , V_301 , & V_394 ) ;
return - V_287 ;
}
static int F_108 ( const struct V_272 * V_273 ,
struct V_268 * V_268 , void * V_301 , void * V_16 )
{
struct V_270 * V_271 = F_61 ( V_268 ) ;
struct V_166 * V_19 = V_16 ;
struct V_312 * V_313 =
F_101 ( V_388 , & V_271 -> V_39 ) ? V_301 : NULL ;
V_19 -> V_168 = V_19 -> V_88 ;
if ( V_313 && V_313 -> V_389 )
return F_109 ( V_313 -> V_389 , V_19 ) ;
if ( V_271 -> V_389 )
return F_109 ( V_271 -> V_389 , V_19 ) ;
if ( V_273 -> V_397 == NULL )
return - V_391 ;
return F_58 ( V_19 , 0 ) ? V_273 -> V_397 ( V_268 , V_301 , V_19 ) :
- V_287 ;
}
static int F_110 ( const struct V_272 * V_273 ,
struct V_268 * V_268 , void * V_301 , void * V_16 )
{
struct V_270 * V_271 = F_61 ( V_268 ) ;
struct V_166 * V_19 = V_16 ;
struct V_312 * V_313 =
F_101 ( V_388 , & V_271 -> V_39 ) ? V_301 : NULL ;
V_19 -> V_168 = V_19 -> V_88 ;
if ( V_313 && V_313 -> V_389 )
return F_111 ( V_313 , V_313 -> V_389 , V_19 ) ;
if ( V_271 -> V_389 )
return F_111 ( NULL , V_271 -> V_389 , V_19 ) ;
if ( V_273 -> V_399 == NULL )
return - V_391 ;
return F_58 ( V_19 , 0 ) ? V_273 -> V_399 ( V_268 , V_301 , V_19 ) :
- V_287 ;
}
static int F_112 ( const struct V_272 * V_273 ,
struct V_268 * V_268 , void * V_301 , void * V_16 )
{
struct V_270 * V_271 = F_61 ( V_268 ) ;
struct V_166 * V_19 = V_16 ;
struct V_312 * V_313 =
F_101 ( V_388 , & V_271 -> V_39 ) ? V_301 : NULL ;
V_19 -> V_168 = V_19 -> V_88 ;
if ( V_313 && V_313 -> V_389 )
return F_113 ( V_313 -> V_389 , V_19 ) ;
if ( V_271 -> V_389 )
return F_113 ( V_271 -> V_389 , V_19 ) ;
if ( V_273 -> V_400 == NULL )
return - V_391 ;
return F_58 ( V_19 , 0 ) ? V_273 -> V_400 ( V_268 , V_301 , V_19 ) :
- V_287 ;
}
static int F_114 ( const struct V_272 * V_273 ,
struct V_268 * V_268 , void * V_301 , void * V_16 )
{
struct V_175 * V_19 = V_16 ;
struct V_176 V_401 = {
. type = V_19 -> type ,
} ;
int V_303 ;
if ( V_273 -> V_402 )
return V_273 -> V_402 ( V_268 , V_301 , V_19 ) ;
if ( F_115 ( V_19 -> type ) )
V_401 . V_177 = V_403 ;
else
V_401 . V_177 = V_404 ;
V_303 = V_273 -> V_405 ( V_268 , V_301 , & V_401 ) ;
if ( ! V_303 )
V_19 -> V_142 = V_401 . V_178 ;
return V_303 ;
}
static int F_116 ( const struct V_272 * V_273 ,
struct V_268 * V_268 , void * V_301 , void * V_16 )
{
struct V_175 * V_19 = V_16 ;
struct V_176 V_401 = {
. type = V_19 -> type ,
. V_178 = V_19 -> V_142 ,
} ;
if ( V_273 -> V_406 )
return V_273 -> V_406 ( V_268 , V_301 , V_19 ) ;
if ( F_115 ( V_19 -> type ) )
V_401 . V_177 = V_403 ;
else
V_401 . V_177 = V_404 ;
return V_273 -> V_407 ( V_268 , V_301 , & V_401 ) ;
}
static int F_117 ( const struct V_272 * V_273 ,
struct V_268 * V_268 , void * V_301 , void * V_16 )
{
struct V_171 * V_19 = V_16 ;
if ( V_273 -> V_405 ) {
struct V_176 V_401 = { . type = V_19 -> type } ;
int V_303 ;
if ( F_115 ( V_19 -> type ) )
V_401 . V_177 = V_408 ;
else
V_401 . V_177 = V_409 ;
V_303 = V_273 -> V_405 ( V_268 , V_301 , & V_401 ) ;
if ( V_303 )
return V_303 ;
V_19 -> V_172 = V_401 . V_178 ;
if ( F_115 ( V_19 -> type ) )
V_401 . V_177 = V_410 ;
else
V_401 . V_177 = V_411 ;
V_303 = V_273 -> V_405 ( V_268 , V_301 , & V_401 ) ;
if ( V_303 )
return V_303 ;
V_19 -> V_173 = V_401 . V_178 ;
}
V_19 -> V_174 . V_10 = 1 ;
V_19 -> V_174 . V_11 = 1 ;
if ( V_273 -> V_412 )
return V_273 -> V_412 ( V_268 , V_301 , V_19 ) ;
return 0 ;
}
static int F_118 ( const struct V_272 * V_273 ,
struct V_268 * V_268 , void * V_301 , void * V_16 )
{
struct V_270 * V_271 = F_61 ( V_268 ) ;
int V_303 ;
if ( V_271 -> V_310 )
F_42 ( L_119 ,
V_271 -> V_310 -> V_14 ) ;
V_303 = V_273 -> V_413 ( V_268 , V_301 ) ;
if ( V_271 -> V_310 )
F_42 ( L_120 ,
V_271 -> V_310 -> V_14 ) ;
return V_303 ;
}
static int F_119 ( const struct V_272 * V_273 ,
struct V_268 * V_268 , void * V_301 , void * V_16 )
{
#ifdef F_120
struct V_200 * V_19 = V_16 ;
struct V_270 * V_271 = F_61 ( V_268 ) ;
struct V_414 * V_415 ;
int V_416 = 0 ;
if ( ! F_121 ( V_417 ) )
return - V_418 ;
if ( V_19 -> V_197 . type == V_419 ) {
if ( V_271 -> V_310 == NULL )
return - V_287 ;
F_122 (sd, vfd->v4l2_dev)
if ( V_19 -> V_197 . V_199 == V_416 ++ )
return F_123 ( V_415 , V_420 , V_421 , V_19 ) ;
return - V_287 ;
}
if ( V_273 -> V_422 && V_19 -> V_197 . type == V_423 &&
( V_273 -> V_424 || V_19 -> V_197 . V_199 == 0 ) )
return V_273 -> V_422 ( V_268 , V_301 , V_19 ) ;
return - V_287 ;
#else
return - V_391 ;
#endif
}
static int F_124 ( const struct V_272 * V_273 ,
struct V_268 * V_268 , void * V_301 , void * V_16 )
{
#ifdef F_120
const struct V_200 * V_19 = V_16 ;
struct V_270 * V_271 = F_61 ( V_268 ) ;
struct V_414 * V_415 ;
int V_416 = 0 ;
if ( ! F_121 ( V_417 ) )
return - V_418 ;
if ( V_19 -> V_197 . type == V_419 ) {
if ( V_271 -> V_310 == NULL )
return - V_287 ;
F_122 (sd, vfd->v4l2_dev)
if ( V_19 -> V_197 . V_199 == V_416 ++ )
return F_123 ( V_415 , V_420 , V_425 , V_19 ) ;
return - V_287 ;
}
if ( V_273 -> V_426 && V_19 -> V_197 . type == V_423 &&
( V_273 -> V_424 || V_19 -> V_197 . V_199 == 0 ) )
return V_273 -> V_426 ( V_268 , V_301 , V_19 ) ;
return - V_287 ;
#else
return - V_391 ;
#endif
}
static int F_125 ( const struct V_272 * V_273 ,
struct V_268 * V_268 , void * V_301 , void * V_16 )
{
#ifdef F_120
struct V_270 * V_271 = F_61 ( V_268 ) ;
struct V_196 * V_19 = V_16 ;
struct V_414 * V_415 ;
int V_416 = 0 ;
switch ( V_19 -> V_197 . type ) {
case V_423 :
if ( V_273 -> V_426 )
V_19 -> V_39 |= V_427 ;
if ( V_273 -> V_422 )
V_19 -> V_39 |= V_428 ;
F_5 ( V_19 -> V_14 , V_271 -> V_310 -> V_14 , sizeof( V_19 -> V_14 ) ) ;
if ( V_273 -> V_424 )
return V_273 -> V_424 ( V_268 , V_301 , V_16 ) ;
if ( V_19 -> V_197 . V_199 )
return - V_287 ;
return 0 ;
case V_419 :
if ( V_271 -> V_310 == NULL )
break;
F_122 (sd, vfd->v4l2_dev) {
if ( V_19 -> V_197 . V_199 != V_416 ++ )
continue;
if ( V_415 -> V_273 -> V_420 && V_415 -> V_273 -> V_420 -> V_425 )
V_19 -> V_39 |= V_427 ;
if ( V_415 -> V_273 -> V_420 && V_415 -> V_273 -> V_420 -> V_421 )
V_19 -> V_39 |= V_428 ;
F_5 ( V_19 -> V_14 , V_415 -> V_14 , sizeof( V_19 -> V_14 ) ) ;
return 0 ;
}
break;
}
return - V_287 ;
#else
return - V_391 ;
#endif
}
static int F_126 ( const struct V_272 * V_273 ,
struct V_268 * V_268 , void * V_301 , void * V_16 )
{
return F_127 ( V_301 , V_16 , V_268 -> V_429 & V_430 ) ;
}
static int F_128 ( const struct V_272 * V_273 ,
struct V_268 * V_268 , void * V_301 , void * V_16 )
{
return V_273 -> V_431 ( V_301 , V_16 ) ;
}
static int F_129 ( const struct V_272 * V_273 ,
struct V_268 * V_268 , void * V_301 , void * V_16 )
{
return V_273 -> V_432 ( V_301 , V_16 ) ;
}
static int F_130 ( const struct V_272 * V_273 ,
struct V_268 * V_268 , void * V_301 , void * V_16 )
{
struct V_257 * V_19 = V_16 ;
int V_303 = F_60 ( V_268 , V_19 -> type ) ;
if ( V_303 )
return V_303 ;
memset ( V_19 , 0 , F_63 ( struct V_257 , type ) ) ;
return V_273 -> V_433 ( V_268 , V_301 , V_19 ) ;
}
static int F_131 ( const struct V_272 * V_273 ,
struct V_268 * V_268 , void * V_301 , void * V_16 )
{
struct V_270 * V_271 = F_61 ( V_268 ) ;
struct V_258 * V_19 = V_16 ;
enum V_362 type ;
int V_352 ;
if ( V_271 -> V_276 == V_281 ) {
if ( V_19 -> type != V_360 && V_19 -> type != V_363 )
return - V_287 ;
type = V_19 -> type ;
} else {
type = ( V_271 -> V_276 == V_353 ) ?
V_354 : V_355 ;
if ( type != V_19 -> type )
return - V_287 ;
}
if ( V_273 -> V_434 ) {
V_352 = V_273 -> V_434 ( V_268 , V_301 , V_19 ) ;
if ( V_352 != - V_391 )
return V_352 ;
}
if ( F_72 ( V_271 , V_435 ) ) {
struct V_101 V_436 = {
. V_27 = V_19 -> V_29 ,
. type = type ,
} ;
if ( V_19 -> V_27 )
return - V_287 ;
V_352 = V_273 -> V_356 ( V_268 , V_301 , & V_436 ) ;
if ( V_352 )
return V_352 ;
V_19 -> V_35 = V_436 . V_35 | V_357 ;
V_19 -> V_99 = V_436 . V_99 ;
V_19 -> V_100 = V_436 . V_100 ;
V_19 -> V_259 = ( type == V_354 ) ?
V_437 : V_438 ;
return 0 ;
}
if ( F_72 ( V_271 , V_439 ) ) {
struct V_97 V_124 = {
. V_27 = V_19 -> V_29 ,
} ;
if ( type != V_354 )
return - V_287 ;
if ( V_19 -> V_27 )
return - V_287 ;
V_352 = V_273 -> V_359 ( V_268 , V_301 , & V_124 ) ;
if ( V_352 )
return V_352 ;
V_19 -> V_35 = V_124 . V_35 | V_357 ;
V_19 -> V_99 = V_124 . V_99 ;
V_19 -> V_100 = V_124 . V_100 ;
V_19 -> V_259 = ( type == V_354 ) ?
V_437 : V_438 ;
return 0 ;
}
return - V_391 ;
}
bool F_132 ( unsigned int V_189 )
{
if ( F_133 ( V_189 ) >= V_440 )
return false ;
return V_441 [ F_133 ( V_189 ) ] . V_442 == V_189 ;
}
struct V_443 * F_134 ( struct V_270 * V_444 , unsigned V_189 )
{
if ( F_133 ( V_189 ) >= V_440 )
return V_444 -> V_445 ;
if ( F_101 ( F_133 ( V_189 ) , V_444 -> V_446 ) )
return NULL ;
if ( V_444 -> V_447 && V_444 -> V_447 -> V_445 &&
( V_441 [ F_133 ( V_189 ) ] . V_39 & V_448 ) )
return V_444 -> V_447 -> V_445 ;
return V_444 -> V_445 ;
}
void F_135 ( const char * V_449 , unsigned int V_189 )
{
const char * V_450 , * type ;
if ( V_449 )
F_15 ( V_69 L_121 , V_449 ) ;
switch ( F_136 ( V_189 ) ) {
case 'd' :
type = L_122 ;
break;
case 'V' :
if ( F_133 ( V_189 ) >= V_440 ) {
type = L_123 ;
break;
}
F_7 ( L_124 , V_441 [ F_133 ( V_189 ) ] . V_14 ) ;
return;
default:
type = L_125 ;
break;
}
switch ( F_137 ( V_189 ) ) {
case V_451 : V_450 = L_126 ; break;
case V_452 : V_450 = L_127 ; break;
case V_453 : V_450 = L_128 ; break;
case V_452 | V_453 : V_450 = L_129 ; break;
default: V_450 = L_130 ; break;
}
F_7 ( L_131 ,
type , F_136 ( V_189 ) , V_450 , F_133 ( V_189 ) , V_189 ) ;
}
static long F_138 ( struct V_268 * V_268 ,
unsigned int V_189 , void * V_16 )
{
struct V_270 * V_271 = F_61 ( V_268 ) ;
const struct V_272 * V_273 = V_271 -> V_274 ;
bool V_17 = false ;
struct V_454 V_455 ;
const struct V_454 * V_456 ;
void * V_301 = V_268 -> V_315 ;
struct V_312 * V_313 = NULL ;
int V_457 = V_271 -> V_457 ;
long V_303 = - V_391 ;
if ( V_273 == NULL ) {
F_139 ( L_132 ,
F_140 ( V_271 ) ) ;
return V_303 ;
}
if ( F_101 ( V_388 , & V_271 -> V_39 ) )
V_313 = V_268 -> V_315 ;
if ( F_132 ( V_189 ) ) {
V_456 = & V_441 [ F_133 ( V_189 ) ] ;
if ( ! F_101 ( F_133 ( V_189 ) , V_271 -> V_458 ) &&
! ( ( V_456 -> V_39 & V_459 ) && V_313 && V_313 -> V_389 ) )
goto V_460;
if ( V_313 && ( V_456 -> V_39 & V_461 ) ) {
V_303 = F_141 ( V_271 -> V_311 , V_313 -> V_311 ) ;
if ( V_303 )
goto V_460;
}
} else {
V_455 . V_442 = V_189 ;
V_455 . V_39 = 0 ;
V_455 . V_457 = F_57 ;
V_456 = & V_455 ;
}
V_17 = F_137 ( V_189 ) == V_453 ;
if ( V_456 -> V_39 & V_462 ) {
typedef int (* F_142)( struct V_268 * V_268 , void * V_301 , void * V_19 );
const void * V_19 = V_271 -> V_274 ;
const F_142 * V_463 = V_19 + V_456 -> V_247 . V_84 ;
V_303 = (* V_463)( V_268 , V_301 , V_16 ) ;
} else if ( V_456 -> V_39 & V_464 ) {
V_303 = V_456 -> V_247 . V_465 ( V_273 , V_268 , V_301 , V_16 ) ;
} else if ( ! V_273 -> V_466 ) {
V_303 = - V_391 ;
} else {
V_303 = V_273 -> V_466 ( V_268 , V_301 ,
V_313 ? F_141 ( V_271 -> V_311 , V_313 -> V_311 ) >= 0 : 0 ,
V_189 , V_16 ) ;
}
V_460:
if ( V_457 ) {
F_135 ( F_140 ( V_271 ) , V_189 ) ;
if ( V_303 < 0 )
F_7 ( L_133 , V_303 ) ;
if ( V_457 == V_467 )
F_7 ( L_45 ) ;
else if ( F_137 ( V_189 ) == V_451 )
V_456 -> V_457 ( V_16 , V_17 ) ;
else {
F_7 ( L_134 ) ;
V_456 -> V_457 ( V_16 , V_17 ) ;
}
}
return V_303 ;
}
static int F_143 ( unsigned int V_189 , void * V_468 , T_4 * V_469 ,
void T_3 * * V_470 , void * * * V_471 )
{
int V_303 = 0 ;
switch ( V_189 ) {
case V_472 :
case V_473 :
case V_474 :
case V_475 : {
struct V_114 * V_476 = V_468 ;
if ( F_26 ( V_476 -> type ) && V_476 -> V_126 > 0 ) {
if ( V_476 -> V_126 > V_477 ) {
V_303 = - V_287 ;
break;
}
* V_470 = ( void T_3 * ) V_476 -> V_124 . V_125 ;
* V_471 = ( void * * ) & V_476 -> V_124 . V_125 ;
* V_469 = sizeof( struct V_118 ) * V_476 -> V_126 ;
V_303 = 1 ;
}
break;
}
case V_478 :
case V_479 : {
struct V_260 * V_480 = V_468 ;
if ( V_480 -> V_263 ) {
if ( V_480 -> V_263 > 256 ) {
V_303 = - V_287 ;
break;
}
* V_470 = ( void T_3 * ) V_480 -> V_480 ;
* V_471 = ( void * * ) & V_480 -> V_480 ;
* V_469 = V_480 -> V_263 * 128 ;
V_303 = 1 ;
}
break;
}
case V_481 :
case V_482 :
case V_483 : {
struct V_166 * V_394 = V_468 ;
if ( V_394 -> V_88 != 0 ) {
if ( V_394 -> V_88 > V_484 ) {
V_303 = - V_287 ;
break;
}
* V_470 = ( void T_3 * ) V_394 -> V_169 ;
* V_471 = ( void * * ) & V_394 -> V_169 ;
* V_469 = sizeof( struct V_395 )
* V_394 -> V_88 ;
V_303 = 1 ;
}
break;
}
}
return V_303 ;
}
long
F_144 ( struct V_268 * V_268 , unsigned int V_189 , unsigned long V_16 ,
T_5 V_465 )
{
char V_485 [ 128 ] ;
void * V_486 = NULL ;
void * V_468 = ( void * ) V_16 ;
long V_352 = - V_287 ;
bool V_487 ;
T_4 V_469 = 0 ;
void T_3 * V_470 = NULL ;
void * * V_471 = NULL ;
if ( F_137 ( V_189 ) != V_451 ) {
if ( F_145 ( V_189 ) <= sizeof( V_485 ) ) {
V_468 = V_485 ;
} else {
V_486 = F_146 ( F_145 ( V_189 ) , V_488 ) ;
if ( NULL == V_486 )
return - V_489 ;
V_468 = V_486 ;
}
V_352 = - V_490 ;
if ( F_137 ( V_189 ) & V_453 ) {
unsigned int V_491 = F_145 ( V_189 ) ;
if ( F_132 ( V_189 ) ) {
T_2 V_39 = V_441 [ F_133 ( V_189 ) ] . V_39 ;
if ( V_39 & V_492 )
V_491 = ( V_39 & V_492 ) >> 16 ;
}
if ( F_147 ( V_468 , ( void T_3 * ) V_16 , V_491 ) )
goto V_493;
if ( V_491 < F_145 ( V_189 ) )
memset ( ( V_494 * ) V_468 + V_491 , 0 , F_145 ( V_189 ) - V_491 ) ;
} else {
memset ( V_468 , 0 , F_145 ( V_189 ) ) ;
}
}
V_352 = F_143 ( V_189 , V_468 , & V_469 , & V_470 , & V_471 ) ;
if ( V_352 < 0 )
goto V_493;
V_487 = V_352 ;
if ( V_487 ) {
V_486 = F_146 ( V_469 , V_488 ) ;
V_352 = - V_489 ;
if ( NULL == V_486 )
goto V_495;
V_352 = - V_490 ;
if ( F_147 ( V_486 , V_470 , V_469 ) )
goto V_495;
* V_471 = V_486 ;
}
V_352 = V_465 ( V_268 , V_189 , V_468 ) ;
if ( V_352 == - V_496 )
V_352 = - V_391 ;
if ( V_352 == 0 ) {
if ( V_189 == V_475 )
F_148 ( F_61 ( V_268 ) -> V_497 , V_468 ) ;
else if ( V_189 == V_474 )
F_149 ( F_61 ( V_268 ) -> V_497 , V_468 ) ;
}
if ( V_487 ) {
* V_471 = ( void V_498 * ) V_470 ;
if ( F_150 ( V_470 , V_486 , V_469 ) )
V_352 = - V_490 ;
goto V_495;
}
if ( V_352 < 0 && V_189 != V_499 )
goto V_493;
V_495:
switch ( F_137 ( V_189 ) ) {
case V_452 :
case ( V_453 | V_452 ) :
if ( F_150 ( ( void T_3 * ) V_16 , V_468 , F_145 ( V_189 ) ) )
V_352 = - V_490 ;
break;
}
V_493:
F_151 ( V_486 ) ;
return V_352 ;
}
long F_152 ( struct V_268 * V_268 ,
unsigned int V_189 , unsigned long V_16 )
{
return F_144 ( V_268 , V_189 , V_16 , F_138 ) ;
}
