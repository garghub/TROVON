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
L_15
L_16 ,
V_44 -> V_58 , V_44 -> V_59 ,
( V_44 -> V_40 & 0xff ) ,
( V_44 -> V_40 >> 8 ) & 0xff ,
( V_44 -> V_40 >> 16 ) & 0xff ,
( V_44 -> V_40 >> 24 ) & 0xff ,
F_13 ( V_44 -> V_60 , V_61 ) ,
V_44 -> V_62 , V_44 -> V_63 ,
V_44 -> V_64 , V_44 -> V_39 , V_44 -> V_65 ,
V_44 -> V_66 , V_44 -> V_67 ) ;
break;
case V_68 :
case V_69 :
V_46 = & V_19 -> V_57 . V_70 ;
F_7 ( L_12
L_17
L_18
L_19 ,
V_46 -> V_58 , V_46 -> V_59 ,
( V_46 -> V_40 & 0xff ) ,
( V_46 -> V_40 >> 8 ) & 0xff ,
( V_46 -> V_40 >> 16 ) & 0xff ,
( V_46 -> V_40 >> 24 ) & 0xff ,
F_13 ( V_46 -> V_60 , V_61 ) ,
V_46 -> V_64 , V_46 -> V_71 , V_46 -> V_39 ,
V_46 -> V_65 , V_46 -> V_66 , V_46 -> V_67 ) ;
for ( V_3 = 0 ; V_3 < V_46 -> V_71 ; V_3 ++ )
F_15 ( V_72 L_20 , V_3 ,
V_46 -> V_73 [ V_3 ] . V_62 ,
V_46 -> V_73 [ V_3 ] . V_63 ) ;
break;
case V_74 :
case V_75 :
V_52 = & V_19 -> V_57 . V_52 ;
F_7 ( L_21 ,
V_52 -> V_76 . V_58 , V_52 -> V_76 . V_59 , V_52 -> V_76 . V_77 , V_52 -> V_76 . V_78 ,
F_13 ( V_52 -> V_60 , V_61 ) ,
V_52 -> V_79 , V_52 -> V_80 , V_52 -> V_81 ,
V_52 -> V_82 , V_52 -> V_83 ) ;
break;
case V_84 :
case V_85 :
V_48 = & V_19 -> V_57 . V_48 ;
F_7 ( L_22
L_23 ,
V_48 -> V_86 , V_48 -> V_87 ,
V_48 -> V_88 ,
( V_48 -> V_89 & 0xff ) ,
( V_48 -> V_89 >> 8 ) & 0xff ,
( V_48 -> V_89 >> 16 ) & 0xff ,
( V_48 -> V_89 >> 24 ) & 0xff ,
V_48 -> V_90 [ 0 ] , V_48 -> V_90 [ 1 ] ,
V_48 -> V_91 [ 0 ] , V_48 -> V_91 [ 1 ] ) ;
break;
case V_92 :
case V_93 :
V_50 = & V_19 -> V_57 . V_50 ;
F_7 ( L_24 ,
V_50 -> V_94 , V_50 -> V_95 ) ;
for ( V_3 = 0 ; V_3 < 24 ; V_3 ++ )
F_15 ( V_72 L_25 , V_3 ,
V_50 -> V_96 [ 0 ] [ V_3 ] ,
V_50 -> V_96 [ 1 ] [ V_3 ] ) ;
break;
case V_97 :
case V_98 :
V_54 = & V_19 -> V_57 . V_54 ;
F_7 ( L_26 ,
( V_54 -> V_40 >> 0 ) & 0xff ,
( V_54 -> V_40 >> 8 ) & 0xff ,
( V_54 -> V_40 >> 16 ) & 0xff ,
( V_54 -> V_40 >> 24 ) & 0xff ) ;
break;
}
}
static void F_16 ( const void * V_16 , bool V_17 )
{
const struct V_99 * V_19 = V_16 ;
F_7 ( L_27
L_28
L_29 ,
V_19 -> V_35 , V_19 -> V_39 , V_19 -> V_100 ,
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
F_7 ( L_30 , F_13 ( * ( T_2 * ) V_16 , V_38 ) ) ;
}
static void F_18 ( const void * V_16 , bool V_17 )
{
const struct V_101 * V_19 = V_16 ;
if ( V_17 )
F_7 ( L_31 , V_19 -> V_27 , V_19 -> V_102 ) ;
else
F_7 ( L_32
L_33 ,
V_19 -> V_27 , ( int ) sizeof( V_19 -> V_14 ) , V_19 -> V_14 , V_19 -> V_35 ,
V_19 -> V_103 , V_19 -> V_104 , V_19 -> V_102 ) ;
}
static void F_19 ( const void * V_16 , bool V_17 )
{
const struct V_105 * V_19 = V_16 ;
if ( V_17 )
F_7 ( L_34 , V_19 -> V_27 , V_19 -> V_106 ) ;
else
F_7 ( L_35
L_36
L_37 ,
V_19 -> V_27 , ( int ) sizeof( V_19 -> V_14 ) , V_19 -> V_14 , V_19 -> type ,
V_19 -> V_35 , V_19 -> V_103 ,
V_19 -> V_104 , V_19 -> signal , V_19 -> V_107 ,
V_19 -> V_108 , V_19 -> V_106 ) ;
}
static void F_20 ( const void * V_16 , bool V_17 )
{
const struct V_109 * V_19 = V_16 ;
F_7 ( L_38 ,
V_19 -> V_29 , V_19 -> type , V_19 -> V_110 ) ;
}
static void F_21 ( const void * V_16 , bool V_17 )
{
const struct V_12 * V_19 = V_16 ;
F_7 ( L_39
L_40 , V_19 -> V_27 ,
( unsigned long long ) V_19 -> V_1 , ( int ) sizeof( V_19 -> V_14 ) , V_19 -> V_14 ,
V_19 -> V_8 . V_10 ,
V_19 -> V_8 . V_11 ,
V_19 -> V_15 ) ;
}
static void F_22 ( const void * V_16 , bool V_17 )
{
F_7 ( L_41 , * ( const long long unsigned * ) V_16 ) ;
}
static void F_23 ( const void * V_16 , bool V_17 )
{
const struct V_111 * V_19 = V_16 ;
F_7 ( L_42
L_43 ,
V_19 -> V_29 , V_19 -> type , V_19 -> V_112 , V_19 -> V_113 , V_19 -> V_114 ,
V_19 -> V_103 , V_19 -> V_104 ) ;
}
static void F_24 ( const void * V_16 , bool V_17 )
{
const struct V_115 * V_19 = V_16 ;
F_7 ( L_44 ,
V_19 -> V_91 ,
F_13 ( V_19 -> type , V_38 ) ,
F_13 ( V_19 -> V_116 , V_117 ) ) ;
}
static void F_25 ( const void * V_16 , bool V_17 )
{
const struct V_118 * V_19 = V_16 ;
const struct V_119 * V_120 = & V_19 -> V_121 ;
const struct V_122 * V_123 ;
int V_3 ;
F_7 ( L_45
L_46 ,
V_19 -> V_124 . V_125 / 3600 ,
( int ) ( V_19 -> V_124 . V_125 / 60 ) % 60 ,
( int ) ( V_19 -> V_124 . V_125 % 60 ) ,
( long ) V_19 -> V_124 . V_126 ,
V_19 -> V_27 ,
F_13 ( V_19 -> type , V_38 ) ,
V_19 -> V_39 , F_13 ( V_19 -> V_60 , V_61 ) ,
V_19 -> V_127 , F_13 ( V_19 -> V_116 , V_117 ) ) ;
if ( F_26 ( V_19 -> type ) && V_19 -> V_128 . V_129 ) {
F_7 ( L_47 ) ;
for ( V_3 = 0 ; V_3 < V_19 -> V_130 ; ++ V_3 ) {
V_123 = & V_19 -> V_128 . V_129 [ V_3 ] ;
F_15 ( V_72
L_48
L_49 ,
V_3 , V_123 -> V_131 , V_123 -> V_132 ,
V_123 -> V_128 . V_133 , V_123 -> V_130 ) ;
}
} else {
F_7 ( L_50 ,
V_19 -> V_131 , V_19 -> V_128 . V_133 , V_19 -> V_130 ) ;
}
F_15 ( V_72 L_51
L_52 ,
V_120 -> V_134 , V_120 -> V_135 , V_120 -> V_136 ,
V_120 -> type , V_120 -> V_39 , V_120 -> V_137 , * ( V_138 * ) V_120 -> V_139 ) ;
}
static void F_27 ( const void * V_16 , bool V_17 )
{
const struct V_140 * V_19 = V_16 ;
F_7 ( L_53 ,
V_19 -> V_141 , F_13 ( V_19 -> type , V_38 ) ,
V_19 -> V_27 , V_19 -> V_123 , V_19 -> V_39 ) ;
}
static void F_28 ( const void * V_16 , bool V_17 )
{
const struct V_142 * V_19 = V_16 ;
F_7 ( L_54 ,
V_19 -> V_27 , V_19 -> V_91 ,
F_13 ( V_19 -> V_116 , V_117 ) ) ;
F_14 ( & V_19 -> V_143 , V_17 ) ;
}
static void F_29 ( const void * V_16 , bool V_17 )
{
const struct V_144 * V_19 = V_16 ;
F_7 ( L_11 , F_13 ( V_19 -> type , V_38 ) ) ;
if ( V_19 -> type == V_55 ||
V_19 -> type == V_68 ) {
const struct V_145 * V_146 = & V_19 -> V_147 . V_148 ;
F_7 ( L_55
L_56 ,
V_146 -> V_35 , V_146 -> V_149 ,
V_146 -> V_150 . V_10 , V_146 -> V_150 . V_11 ,
V_146 -> V_151 , V_146 -> V_152 ) ;
} else if ( V_19 -> type == V_56 ||
V_19 -> type == V_69 ) {
const struct V_153 * V_146 = & V_19 -> V_147 . V_154 ;
F_7 ( L_57
L_58 ,
V_146 -> V_35 , V_146 -> V_155 ,
V_146 -> V_150 . V_10 , V_146 -> V_150 . V_11 ,
V_146 -> V_151 , V_146 -> V_156 ) ;
} else {
F_7 ( L_47 ) ;
}
}
static void F_30 ( const void * V_16 , bool V_17 )
{
const struct V_157 * V_19 = V_16 ;
F_7 ( L_59
L_60 ,
V_19 -> V_1 , V_19 -> type , ( int ) sizeof( V_19 -> V_14 ) , V_19 -> V_14 ,
V_19 -> V_158 , V_19 -> V_159 ,
V_19 -> V_160 , V_19 -> V_161 , V_19 -> V_39 ) ;
}
static void F_31 ( const void * V_16 , bool V_17 )
{
const struct V_162 * V_19 = V_16 ;
F_7 ( L_61
L_62
L_63 ,
V_19 -> V_1 , V_19 -> type , ( int ) sizeof( V_19 -> V_14 ) , V_19 -> V_14 ,
V_19 -> V_158 , V_19 -> V_159 ,
V_19 -> V_160 , V_19 -> V_161 , V_19 -> V_39 ,
V_19 -> V_163 , V_19 -> V_164 , V_19 -> V_165 ,
V_19 -> V_166 [ 0 ] , V_19 -> V_166 [ 1 ] , V_19 -> V_166 [ 2 ] , V_19 -> V_166 [ 3 ] ) ;
}
static void F_32 ( const void * V_16 , bool V_17 )
{
const struct V_167 * V_19 = V_16 ;
F_7 ( L_64 , V_19 -> V_1 , V_19 -> V_27 ) ;
}
static void F_33 ( const void * V_16 , bool V_17 )
{
const struct V_168 * V_19 = V_16 ;
F_7 ( L_65 , V_19 -> V_1 , V_19 -> V_169 ) ;
}
static void F_34 ( const void * V_16 , bool V_17 )
{
const struct V_170 * V_19 = V_16 ;
int V_3 ;
F_7 ( L_66 ,
V_19 -> V_171 , V_19 -> V_91 , V_19 -> V_172 ) ;
for ( V_3 = 0 ; V_3 < V_19 -> V_91 ; V_3 ++ ) {
if ( ! V_19 -> V_173 [ V_3 ] . V_174 )
F_7 ( L_67 ,
V_19 -> V_173 [ V_3 ] . V_1 , V_19 -> V_173 [ V_3 ] . V_169 ) ;
else
F_7 ( L_68 ,
V_19 -> V_173 [ V_3 ] . V_1 , V_19 -> V_173 [ V_3 ] . V_174 ) ;
}
F_7 ( L_47 ) ;
}
static void F_35 ( const void * V_16 , bool V_17 )
{
const struct V_175 * V_19 = V_16 ;
F_7 ( L_69
L_70
L_71 ,
F_13 ( V_19 -> type , V_38 ) ,
V_19 -> V_176 . V_58 , V_19 -> V_176 . V_59 ,
V_19 -> V_176 . V_77 , V_19 -> V_176 . V_78 ,
V_19 -> V_177 . V_58 , V_19 -> V_177 . V_59 ,
V_19 -> V_177 . V_77 , V_19 -> V_177 . V_78 ,
V_19 -> V_178 . V_10 , V_19 -> V_178 . V_11 ) ;
}
static void F_36 ( const void * V_16 , bool V_17 )
{
const struct V_179 * V_19 = V_16 ;
F_7 ( L_72 ,
F_13 ( V_19 -> type , V_38 ) ,
V_19 -> V_146 . V_58 , V_19 -> V_146 . V_59 ,
V_19 -> V_146 . V_77 , V_19 -> V_146 . V_78 ) ;
}
static void F_37 ( const void * V_16 , bool V_17 )
{
const struct V_180 * V_19 = V_16 ;
F_7 ( L_73 ,
F_13 ( V_19 -> type , V_38 ) ,
V_19 -> V_181 , V_19 -> V_39 ,
V_19 -> V_182 . V_58 , V_19 -> V_182 . V_59 , V_19 -> V_182 . V_77 , V_19 -> V_182 . V_78 ) ;
}
static void F_38 ( const void * V_16 , bool V_17 )
{
const struct V_183 * V_19 = V_16 ;
F_7 ( L_74
L_75 ,
V_19 -> V_184 , V_19 -> V_185 , V_19 -> V_186 ,
V_19 -> V_187 , V_19 -> V_188 ) ;
}
static void F_39 ( const void * V_16 , bool V_17 )
{
const struct V_189 * V_19 = V_16 ;
F_7 ( L_76 ,
V_19 -> V_190 , V_19 -> V_191 ) ;
}
static void F_40 ( const void * V_16 , bool V_17 )
{
const struct V_192 * V_19 = V_16 ;
F_7 ( L_77 ,
V_19 -> V_193 , V_19 -> V_39 ) ;
}
static void F_41 ( const void * V_16 , bool V_17 )
{
const struct V_194 * V_19 = V_16 ;
F_7 ( L_77 , V_19 -> V_193 , V_19 -> V_39 ) ;
if ( V_19 -> V_193 == V_195 )
F_42 ( L_78 ,
V_19 -> V_90 . V_196 , V_19 -> V_90 . V_143 ) ;
else if ( V_19 -> V_193 == V_197 )
F_42 ( L_79 , V_19 -> V_198 . V_199 ) ;
}
static void F_43 ( const void * V_16 , bool V_17 )
{
const struct V_200 * V_19 = V_16 ;
F_7 ( L_80 , V_19 -> V_201 . type ) ;
if ( V_19 -> V_201 . type == V_202 )
F_7 ( L_81 ,
( int ) sizeof( V_19 -> V_201 . V_14 ) , V_19 -> V_201 . V_14 ) ;
else
F_7 ( L_82 , V_19 -> V_201 . V_203 ) ;
F_7 ( L_83 , ( int ) sizeof( V_19 -> V_14 ) , V_19 -> V_14 ) ;
}
static void F_44 ( const void * V_16 , bool V_17 )
{
const struct V_204 * V_19 = V_16 ;
F_7 ( L_80 , V_19 -> V_201 . type ) ;
if ( V_19 -> V_201 . type == V_202 )
F_7 ( L_81 ,
( int ) sizeof( V_19 -> V_201 . V_14 ) , V_19 -> V_201 . V_14 ) ;
else
F_7 ( L_82 , V_19 -> V_201 . V_203 ) ;
F_7 ( L_84 ,
V_19 -> V_205 , V_19 -> V_206 ) ;
}
static void F_45 ( const void * V_16 , bool V_17 )
{
const struct V_207 * V_19 = V_16 ;
switch ( V_19 -> type ) {
case V_208 :
F_7 ( L_85
L_86
L_87
L_88
L_89
L_90
L_91
L_92 ,
V_19 -> V_209 . V_210 , V_19 -> V_209 . V_211 ,
V_19 -> V_209 . V_58 , V_19 -> V_209 . V_59 ,
V_19 -> V_209 . V_212 , V_19 -> V_209 . V_213 ,
V_19 -> V_209 . V_214 , V_19 -> V_209 . V_215 ,
V_19 -> V_209 . V_216 , V_19 -> V_209 . V_217 ,
V_19 -> V_209 . V_218 , V_19 -> V_209 . V_219 ,
V_19 -> V_209 . V_220 , V_19 -> V_209 . V_221 ,
V_19 -> V_209 . V_4 , V_19 -> V_209 . V_39 ) ;
break;
default:
F_7 ( L_93 , V_19 -> type ) ;
break;
}
}
static void F_46 ( const void * V_16 , bool V_17 )
{
const struct V_222 * V_19 = V_16 ;
F_7 ( L_94 , V_19 -> V_27 ) ;
F_45 ( & V_19 -> V_223 , V_17 ) ;
}
static void F_47 ( const void * V_16 , bool V_17 )
{
const struct V_224 * V_19 = V_16 ;
switch ( V_19 -> type ) {
case V_208 :
F_7 ( L_95
L_96 ,
V_19 -> V_209 . V_225 , V_19 -> V_209 . V_226 ,
V_19 -> V_209 . V_227 , V_19 -> V_209 . V_228 ,
V_19 -> V_209 . V_229 , V_19 -> V_209 . V_230 ,
V_19 -> V_209 . V_4 , V_19 -> V_209 . V_24 ) ;
break;
default:
F_7 ( L_97 , V_19 -> type ) ;
break;
}
}
static void F_48 ( const void * V_16 , bool V_17 )
{
const struct V_231 * V_19 = V_16 ;
F_7 ( L_98 ,
V_19 -> V_27 ,
( V_19 -> V_232 & 0xff ) ,
( V_19 -> V_232 >> 8 ) & 0xff ,
( V_19 -> V_232 >> 16 ) & 0xff ,
( V_19 -> V_232 >> 24 ) & 0xff ,
V_19 -> type ) ;
switch ( V_19 -> type ) {
case V_233 :
F_7 ( L_99 ,
V_19 -> V_234 . V_58 , V_19 -> V_234 . V_59 ) ;
break;
case V_235 :
F_7 ( L_100 ,
V_19 -> V_236 . V_225 , V_19 -> V_236 . V_227 ,
V_19 -> V_236 . V_237 , V_19 -> V_236 . V_238 ,
V_19 -> V_236 . V_226 , V_19 -> V_236 . V_228 ) ;
break;
case V_239 :
default:
F_7 ( L_47 ) ;
break;
}
}
static void F_49 ( const void * V_16 , bool V_17 )
{
const struct V_240 * V_19 = V_16 ;
F_7 ( L_101 ,
V_19 -> V_27 ,
( V_19 -> V_232 & 0xff ) ,
( V_19 -> V_232 >> 8 ) & 0xff ,
( V_19 -> V_232 >> 16 ) & 0xff ,
( V_19 -> V_232 >> 24 ) & 0xff ,
V_19 -> V_58 , V_19 -> V_59 , V_19 -> type ) ;
switch ( V_19 -> type ) {
case V_241 :
F_7 ( L_102 ,
V_19 -> V_234 . V_10 ,
V_19 -> V_234 . V_11 ) ;
break;
case V_242 :
F_7 ( L_103 ,
V_19 -> V_236 . V_243 . V_10 ,
V_19 -> V_236 . V_243 . V_11 ,
V_19 -> V_236 . V_244 . V_10 ,
V_19 -> V_236 . V_244 . V_11 ,
V_19 -> V_236 . V_160 . V_10 ,
V_19 -> V_236 . V_160 . V_11 ) ;
break;
case V_245 :
default:
F_7 ( L_47 ) ;
break;
}
}
static void F_50 ( const void * V_16 , bool V_17 )
{
const struct V_246 * V_19 = V_16 ;
const struct V_247 * V_146 ;
F_7 ( L_104
L_105 ,
V_19 -> type , V_19 -> V_248 , V_19 -> V_127 , V_19 -> V_1 ,
V_19 -> V_124 . V_125 , V_19 -> V_124 . V_249 ) ;
switch ( V_19 -> type ) {
case V_250 :
F_15 ( V_72 L_106 ,
F_13 ( V_19 -> V_251 . V_217 . V_60 , V_61 ) ) ;
break;
case V_252 :
V_146 = & V_19 -> V_251 . V_253 ;
F_15 ( V_72 L_107 ,
V_146 -> V_254 , V_146 -> type ) ;
if ( V_146 -> type == V_255 )
F_7 ( L_108 , V_146 -> V_256 ) ;
else
F_7 ( L_109 , V_146 -> V_169 ) ;
F_7 ( L_110
L_111 ,
V_146 -> V_39 , V_146 -> V_158 , V_146 -> V_159 ,
V_146 -> V_160 , V_146 -> V_161 ) ;
break;
case V_257 :
F_7 ( L_112 ,
V_19 -> V_251 . V_258 . V_259 ) ;
break;
}
}
static void F_51 ( const void * V_16 , bool V_17 )
{
const struct V_260 * V_19 = V_16 ;
F_7 ( L_113 ,
V_19 -> type , V_19 -> V_1 , V_19 -> V_39 ) ;
}
static void F_52 ( const void * V_16 , bool V_17 )
{
const struct V_261 * V_19 = V_16 ;
int V_3 ;
F_7 ( L_114 ,
F_13 ( V_19 -> type , V_38 ) , V_19 -> V_94 ) ;
for ( V_3 = 0 ; V_3 < 24 ; V_3 ++ )
F_15 ( V_72 L_25 , V_3 ,
V_19 -> V_96 [ 0 ] [ V_3 ] ,
V_19 -> V_96 [ 1 ] [ V_3 ] ) ;
}
static void F_53 ( const void * V_16 , bool V_17 )
{
const struct V_262 * V_19 = V_16 ;
F_7 ( L_115
L_116 ,
V_19 -> V_29 , V_19 -> type , V_19 -> V_27 ,
V_19 -> V_35 , V_19 -> V_103 ,
V_19 -> V_104 , V_19 -> V_263 ) ;
}
static void F_54 ( const void * V_16 , bool V_17 )
{
const struct V_264 * V_19 = V_16 ;
F_7 ( L_117 ,
V_19 -> V_265 , V_19 -> V_266 , V_19 -> V_267 ) ;
}
static void F_55 ( const void * V_16 , bool V_17 )
{
F_7 ( L_118 , * ( const T_2 * ) V_16 ) ;
}
static void F_56 ( const void * V_16 , bool V_17 )
{
F_7 ( L_47 ) ;
}
static void F_57 ( const void * V_16 , bool V_17 )
{
F_7 ( L_119 ) ;
}
static int F_58 ( struct V_170 * V_146 , int V_268 )
{
V_138 V_3 ;
V_146 -> V_269 [ 0 ] = V_146 -> V_269 [ 1 ] = 0 ;
for ( V_3 = 0 ; V_3 < V_146 -> V_91 ; V_3 ++ )
V_146 -> V_173 [ V_3 ] . V_270 [ 0 ] = 0 ;
if ( ! V_268 && V_146 -> V_171 == V_271 )
return 0 ;
if ( ! V_146 -> V_171 )
return 1 ;
for ( V_3 = 0 ; V_3 < V_146 -> V_91 ; V_3 ++ ) {
if ( F_59 ( V_146 -> V_173 [ V_3 ] . V_1 ) != V_146 -> V_171 ) {
V_146 -> V_172 = V_3 ;
return 0 ;
}
}
return 1 ;
}
static int F_60 ( struct V_272 * V_272 , enum V_273 type )
{
struct V_274 * V_275 = F_61 ( V_272 ) ;
const struct V_276 * V_277 = V_275 -> V_278 ;
bool V_279 = V_275 -> V_280 == V_281 ;
bool V_282 = V_275 -> V_280 == V_283 ;
bool V_284 = V_275 -> V_280 == V_285 ;
bool V_286 = V_275 -> V_280 == V_287 ;
bool V_288 = V_275 -> V_289 != V_290 ;
bool V_291 = V_275 -> V_289 != V_292 ;
if ( V_277 == NULL )
return - V_293 ;
switch ( type ) {
case V_55 :
if ( ( V_279 || V_286 ) && V_288 &&
( V_277 -> V_294 || V_277 -> V_295 ) )
return 0 ;
break;
case V_68 :
if ( V_279 && V_288 && V_277 -> V_295 )
return 0 ;
break;
case V_74 :
if ( V_279 && V_288 && V_277 -> V_296 )
return 0 ;
break;
case V_56 :
if ( V_279 && V_291 &&
( V_277 -> V_297 || V_277 -> V_298 ) )
return 0 ;
break;
case V_69 :
if ( V_279 && V_291 && V_277 -> V_298 )
return 0 ;
break;
case V_75 :
if ( V_279 && V_291 && V_277 -> V_299 )
return 0 ;
break;
case V_84 :
if ( V_282 && V_288 && V_277 -> V_300 )
return 0 ;
break;
case V_85 :
if ( V_282 && V_291 && V_277 -> V_301 )
return 0 ;
break;
case V_92 :
if ( V_282 && V_288 && V_277 -> V_302 )
return 0 ;
break;
case V_93 :
if ( V_282 && V_291 && V_277 -> V_303 )
return 0 ;
break;
case V_97 :
if ( V_284 && V_288 && V_277 -> V_304 )
return 0 ;
break;
case V_98 :
if ( V_284 && V_291 && V_277 -> V_305 )
return 0 ;
break;
default:
break;
}
return - V_293 ;
}
static void F_62 ( struct V_42 * V_57 )
{
unsigned int V_87 ;
if ( V_57 -> type != V_55 &&
V_57 -> type != V_56 )
return;
if ( V_57 -> V_57 . V_44 . V_306 == V_307 )
return;
V_57 -> V_57 . V_44 . V_306 = V_307 ;
V_87 = F_63 ( struct V_43 , V_306 )
+ sizeof( V_57 -> V_57 . V_44 . V_306 ) ;
memset ( ( ( void * ) & V_57 -> V_57 . V_44 ) + V_87 , 0 ,
sizeof( V_57 -> V_57 . V_44 ) - V_87 ) ;
}
static int F_64 ( const struct V_276 * V_277 ,
struct V_272 * V_272 , void * V_308 , void * V_16 )
{
struct V_18 * V_309 = (struct V_18 * ) V_16 ;
struct V_274 * V_275 = F_61 ( V_272 ) ;
int V_310 ;
V_309 -> V_23 = V_311 ;
V_309 -> V_25 = V_275 -> V_25 ;
V_309 -> V_24 = V_275 -> V_25 | V_312 ;
V_310 = V_277 -> V_313 ( V_272 , V_308 , V_309 ) ;
V_309 -> V_24 |= V_314 ;
F_65 ( ! ( V_309 -> V_24 & V_312 ) ||
! V_309 -> V_25 , L_120 ,
V_309 -> V_20 , V_309 -> V_24 , V_309 -> V_25 ) ;
V_309 -> V_25 |= V_314 ;
return V_310 ;
}
static int F_66 ( const struct V_276 * V_277 ,
struct V_272 * V_272 , void * V_308 , void * V_16 )
{
struct V_274 * V_275 = F_61 ( V_272 ) ;
int V_310 ;
V_310 = F_67 ( V_275 ) ;
if ( V_310 )
return V_310 ;
return V_277 -> V_315 ( V_272 , V_308 , * ( unsigned int * ) V_16 ) ;
}
static int F_68 ( const struct V_276 * V_277 ,
struct V_272 * V_272 , void * V_308 , void * V_16 )
{
return V_277 -> V_316 ( V_272 , V_308 , * ( unsigned int * ) V_16 ) ;
}
static int F_69 ( const struct V_276 * V_277 ,
struct V_272 * V_272 , void * V_308 , void * V_16 )
{
struct V_274 * V_275 ;
T_2 * V_19 = V_16 ;
V_275 = F_61 ( V_272 ) ;
* V_19 = F_70 ( V_275 -> V_317 ) ;
return 0 ;
}
static int F_71 ( const struct V_276 * V_277 ,
struct V_272 * V_272 , void * V_308 , void * V_16 )
{
struct V_274 * V_275 ;
struct V_318 * V_319 ;
T_2 * V_19 = V_16 ;
V_275 = F_61 ( V_272 ) ;
if ( ! F_72 ( V_320 , & V_275 -> V_39 ) )
return - V_321 ;
V_319 = V_272 -> V_322 ;
return F_73 ( V_275 -> V_317 , & V_319 -> V_317 , * V_19 ) ;
}
static int F_74 ( const struct V_276 * V_277 ,
struct V_272 * V_272 , void * V_308 , void * V_16 )
{
struct V_274 * V_275 = F_61 ( V_272 ) ;
struct V_26 * V_19 = V_16 ;
if ( F_75 ( V_275 , V_323 ) )
V_19 -> V_24 |= V_324 ;
return V_277 -> V_325 ( V_272 , V_308 , V_19 ) ;
}
static int F_76 ( const struct V_276 * V_277 ,
struct V_272 * V_272 , void * V_308 , void * V_16 )
{
struct V_274 * V_275 = F_61 ( V_272 ) ;
struct V_31 * V_19 = V_16 ;
if ( F_75 ( V_275 , V_323 ) )
V_19 -> V_24 |= V_326 ;
return V_277 -> V_327 ( V_272 , V_308 , V_19 ) ;
}
static void F_77 ( struct V_37 * V_57 )
{
const unsigned V_328 = sizeof( V_57 -> V_41 ) ;
const char * V_6 = NULL ;
T_2 V_39 = 0 ;
switch ( V_57 -> V_40 ) {
case V_329 : V_6 = L_121 ; break;
case V_330 : V_6 = L_122 ; break;
case V_331 : V_6 = L_123 ; break;
case V_332 : V_6 = L_124 ; break;
case V_333 : V_6 = L_125 ; break;
case V_334 : V_6 = L_126 ; break;
case V_335 : V_6 = L_127 ; break;
case V_336 : V_6 = L_128 ; break;
case V_337 : V_6 = L_129 ; break;
case V_338 : V_6 = L_130 ; break;
case V_339 : V_6 = L_131 ; break;
case V_340 : V_6 = L_132 ; break;
case V_341 : V_6 = L_133 ; break;
case V_342 : V_6 = L_134 ; break;
case V_343 : V_6 = L_135 ; break;
case V_344 : V_6 = L_136 ; break;
case V_345 : V_6 = L_137 ; break;
case V_346 : V_6 = L_138 ; break;
case V_347 : V_6 = L_139 ; break;
case V_348 : V_6 = L_140 ; break;
case V_349 : V_6 = L_141 ; break;
case V_350 : V_6 = L_142 ; break;
case V_351 : V_6 = L_143 ; break;
case V_352 : V_6 = L_144 ; break;
case V_353 : V_6 = L_145 ; break;
case V_354 : V_6 = L_146 ; break;
case V_355 : V_6 = L_147 ; break;
case V_356 : V_6 = L_148 ; break;
case V_357 : V_6 = L_149 ; break;
case V_358 : V_6 = L_150 ; break;
case V_359 : V_6 = L_151 ; break;
case V_360 : V_6 = L_152 ; break;
case V_361 : V_6 = L_153 ; break;
case V_362 : V_6 = L_154 ; break;
case V_363 : V_6 = L_155 ; break;
case V_364 : V_6 = L_156 ; break;
case V_365 : V_6 = L_157 ; break;
case V_366 : V_6 = L_158 ; break;
case V_367 : V_6 = L_159 ; break;
case V_368 : V_6 = L_160 ; break;
case V_369 : V_6 = L_161 ; break;
case V_370 : V_6 = L_162 ; break;
case V_371 : V_6 = L_163 ; break;
case V_372 : V_6 = L_164 ; break;
case V_373 : V_6 = L_165 ; break;
case V_374 : V_6 = L_166 ; break;
case V_375 : V_6 = L_167 ; break;
case V_376 : V_6 = L_168 ; break;
case V_377 : V_6 = L_169 ; break;
case V_378 : V_6 = L_170 ; break;
case V_379 : V_6 = L_171 ; break;
case V_380 : V_6 = L_172 ; break;
case V_381 : V_6 = L_173 ; break;
case V_382 : V_6 = L_174 ; break;
case V_383 : V_6 = L_175 ; break;
case V_384 : V_6 = L_176 ; break;
case V_385 : V_6 = L_177 ; break;
case V_386 : V_6 = L_178 ; break;
case V_387 : V_6 = L_179 ; break;
case V_388 : V_6 = L_180 ; break;
case V_389 : V_6 = L_181 ; break;
case V_390 : V_6 = L_182 ; break;
case V_391 : V_6 = L_183 ; break;
case V_392 : V_6 = L_184 ; break;
case V_393 : V_6 = L_185 ; break;
case V_394 : V_6 = L_186 ; break;
case V_395 : V_6 = L_187 ; break;
case V_396 : V_6 = L_188 ; break;
case V_397 : V_6 = L_189 ; break;
case V_398 : V_6 = L_190 ; break;
case V_399 : V_6 = L_191 ; break;
case V_400 : V_6 = L_192 ; break;
case V_401 : V_6 = L_193 ; break;
case V_402 : V_6 = L_194 ; break;
case V_403 : V_6 = L_195 ; break;
case V_404 : V_6 = L_196 ; break;
case V_405 : V_6 = L_197 ; break;
case V_406 : V_6 = L_198 ; break;
case V_407 : V_6 = L_199 ; break;
case V_408 : V_6 = L_200 ; break;
case V_409 : V_6 = L_201 ; break;
case V_410 : V_6 = L_202 ; break;
case V_411 : V_6 = L_203 ; break;
case V_412 : V_6 = L_204 ; break;
case V_413 : V_6 = L_205 ; break;
case V_414 : V_6 = L_206 ; break;
case V_415 : V_6 = L_207 ; break;
case V_416 : V_6 = L_208 ; break;
case V_417 : V_6 = L_209 ; break;
case V_418 : V_6 = L_210 ; break;
case V_419 : V_6 = L_211 ; break;
case V_420 : V_6 = L_212 ; break;
case V_421 : V_6 = L_213 ; break;
case V_422 : V_6 = L_214 ; break;
case V_423 : V_6 = L_215 ; break;
case V_424 : V_6 = L_216 ; break;
case V_425 : V_6 = L_217 ; break;
case V_426 : V_6 = L_218 ; break;
case V_427 : V_6 = L_219 ; break;
case V_428 : V_6 = L_220 ; break;
case V_429 : V_6 = L_221 ; break;
case V_430 : V_6 = L_222 ; break;
case V_431 : V_6 = L_223 ; break;
case V_432 : V_6 = L_224 ; break;
case V_433 : V_6 = L_225 ; break;
case V_434 : V_6 = L_226 ; break;
case V_435 : V_6 = L_227 ; break;
case V_436 : V_6 = L_228 ; break;
case V_437 : V_6 = L_229 ; break;
case V_438 : V_6 = L_230 ; break;
default:
V_39 = V_439 ;
switch ( V_57 -> V_40 ) {
case V_440 : V_6 = L_231 ; break;
case V_441 : V_6 = L_232 ; break;
case V_442 : V_6 = L_233 ; break;
case V_443 : V_6 = L_234 ; break;
case V_444 : V_6 = L_235 ; break;
case V_445 : V_6 = L_236 ; break;
case V_446 : V_6 = L_237 ; break;
case V_447 : V_6 = L_238 ; break;
case V_448 : V_6 = L_239 ; break;
case V_449 : V_6 = L_240 ; break;
case V_450 : V_6 = L_241 ; break;
case V_451 : V_6 = L_242 ; break;
case V_452 : V_6 = L_243 ; break;
case V_453 : V_6 = L_244 ; break;
case V_454 : V_6 = L_245 ; break;
case V_455 : V_6 = L_246 ; break;
case V_456 : V_6 = L_247 ; break;
case V_457 : V_6 = L_248 ; break;
case V_458 : V_6 = L_249 ; break;
case V_459 : V_6 = L_250 ; break;
case V_460 : V_6 = L_251 ; break;
case V_461 : V_6 = L_252 ; break;
case V_462 : V_6 = L_253 ; break;
case V_463 : V_6 = L_254 ; break;
case V_464 : V_6 = L_255 ; break;
case V_465 : V_6 = L_256 ; break;
case V_466 : V_6 = L_257 ; break;
case V_467 : V_6 = L_258 ; break;
case V_468 : V_6 = L_259 ; break;
case V_469 : V_6 = L_260 ; break;
case V_470 : V_6 = L_261 ; break;
case V_471 : V_6 = L_262 ; break;
case V_472 : V_6 = L_263 ; break;
default:
F_65 ( 1 , L_264 , V_57 -> V_40 ) ;
if ( V_57 -> V_41 [ 0 ] )
return;
V_39 = 0 ;
snprintf ( V_57 -> V_41 , V_328 , L_265 ,
( char ) ( V_57 -> V_40 & 0x7f ) ,
( char ) ( ( V_57 -> V_40 >> 8 ) & 0x7f ) ,
( char ) ( ( V_57 -> V_40 >> 16 ) & 0x7f ) ,
( char ) ( ( V_57 -> V_40 >> 24 ) & 0x7f ) ,
( V_57 -> V_40 & ( 1 << 31 ) ) ? L_266 : L_267 ) ;
break;
}
}
if ( V_6 )
F_78 ( F_5 ( V_57 -> V_41 , V_6 , V_328 ) >= V_328 ) ;
V_57 -> V_39 = V_39 ;
}
static int F_79 ( const struct V_276 * V_277 ,
struct V_272 * V_272 , void * V_308 , void * V_16 )
{
struct V_37 * V_19 = V_16 ;
struct V_274 * V_275 = F_61 ( V_272 ) ;
bool V_279 = V_275 -> V_280 == V_281 ;
bool V_284 = V_275 -> V_280 == V_285 ;
bool V_286 = V_275 -> V_280 == V_287 ;
bool V_288 = V_275 -> V_289 != V_290 ;
bool V_291 = V_275 -> V_289 != V_292 ;
int V_310 = - V_293 ;
switch ( V_19 -> type ) {
case V_55 :
if ( F_80 ( ! V_288 || ( ! V_279 && ! V_286 ) || ! V_277 -> V_473 ) )
break;
V_310 = V_277 -> V_473 ( V_272 , V_308 , V_16 ) ;
break;
case V_68 :
if ( F_80 ( ! V_288 || ! V_279 || ! V_277 -> V_474 ) )
break;
V_310 = V_277 -> V_474 ( V_272 , V_308 , V_16 ) ;
break;
case V_74 :
if ( F_80 ( ! V_288 || ! V_279 || ! V_277 -> V_475 ) )
break;
V_310 = V_277 -> V_475 ( V_272 , V_308 , V_16 ) ;
break;
case V_56 :
if ( F_80 ( ! V_291 || ! V_279 || ! V_277 -> V_476 ) )
break;
V_310 = V_277 -> V_476 ( V_272 , V_308 , V_16 ) ;
break;
case V_69 :
if ( F_80 ( ! V_291 || ! V_279 || ! V_277 -> V_477 ) )
break;
V_310 = V_277 -> V_477 ( V_272 , V_308 , V_16 ) ;
break;
case V_97 :
if ( F_80 ( ! V_288 || ! V_284 || ! V_277 -> V_478 ) )
break;
V_310 = V_277 -> V_478 ( V_272 , V_308 , V_16 ) ;
break;
case V_98 :
if ( F_80 ( ! V_291 || ! V_284 || ! V_277 -> V_479 ) )
break;
V_310 = V_277 -> V_479 ( V_272 , V_308 , V_16 ) ;
break;
}
if ( V_310 == 0 )
F_77 ( V_19 ) ;
return V_310 ;
}
static int F_81 ( const struct V_276 * V_277 ,
struct V_272 * V_272 , void * V_308 , void * V_16 )
{
struct V_42 * V_19 = V_16 ;
struct V_274 * V_275 = F_61 ( V_272 ) ;
bool V_279 = V_275 -> V_280 == V_281 ;
bool V_284 = V_275 -> V_280 == V_285 ;
bool V_286 = V_275 -> V_280 == V_287 ;
bool V_288 = V_275 -> V_289 != V_290 ;
bool V_291 = V_275 -> V_289 != V_292 ;
int V_310 ;
switch ( V_19 -> type ) {
case V_74 :
case V_75 : {
struct V_480 T_3 * V_81 = V_19 -> V_57 . V_52 . V_81 ;
T_2 V_80 = V_19 -> V_57 . V_52 . V_80 ;
void T_3 * V_82 = V_19 -> V_57 . V_52 . V_82 ;
memset ( & V_19 -> V_57 , 0 , sizeof( V_19 -> V_57 ) ) ;
V_19 -> V_57 . V_52 . V_81 = V_81 ;
V_19 -> V_57 . V_52 . V_80 = V_80 ;
V_19 -> V_57 . V_52 . V_82 = V_82 ;
break;
}
default:
memset ( & V_19 -> V_57 , 0 , sizeof( V_19 -> V_57 ) ) ;
break;
}
switch ( V_19 -> type ) {
case V_55 :
if ( F_80 ( ! V_288 || ( ! V_279 && ! V_286 ) || ! V_277 -> V_294 ) )
break;
V_19 -> V_57 . V_44 . V_306 = V_307 ;
V_310 = V_277 -> V_294 ( V_272 , V_308 , V_16 ) ;
V_19 -> V_57 . V_44 . V_306 = V_307 ;
return V_310 ;
case V_68 :
if ( F_80 ( ! V_288 || ! V_279 || ! V_277 -> V_295 ) )
break;
return V_277 -> V_295 ( V_272 , V_308 , V_16 ) ;
case V_74 :
if ( F_80 ( ! V_288 || ! V_279 || ! V_277 -> V_296 ) )
break;
return V_277 -> V_296 ( V_272 , V_308 , V_16 ) ;
case V_84 :
if ( F_80 ( ! V_288 || V_279 || ! V_277 -> V_300 ) )
break;
return V_277 -> V_300 ( V_272 , V_308 , V_16 ) ;
case V_92 :
if ( F_80 ( ! V_288 || V_279 || ! V_277 -> V_302 ) )
break;
return V_277 -> V_302 ( V_272 , V_308 , V_16 ) ;
case V_56 :
if ( F_80 ( ! V_291 || ! V_279 || ! V_277 -> V_297 ) )
break;
V_19 -> V_57 . V_44 . V_306 = V_307 ;
V_310 = V_277 -> V_297 ( V_272 , V_308 , V_16 ) ;
V_19 -> V_57 . V_44 . V_306 = V_307 ;
return V_310 ;
case V_69 :
if ( F_80 ( ! V_291 || ! V_279 || ! V_277 -> V_298 ) )
break;
return V_277 -> V_298 ( V_272 , V_308 , V_16 ) ;
case V_75 :
if ( F_80 ( ! V_291 || ! V_279 || ! V_277 -> V_299 ) )
break;
return V_277 -> V_299 ( V_272 , V_308 , V_16 ) ;
case V_85 :
if ( F_80 ( ! V_291 || V_279 || ! V_277 -> V_301 ) )
break;
return V_277 -> V_301 ( V_272 , V_308 , V_16 ) ;
case V_93 :
if ( F_80 ( ! V_291 || V_279 || ! V_277 -> V_303 ) )
break;
return V_277 -> V_303 ( V_272 , V_308 , V_16 ) ;
case V_97 :
if ( F_80 ( ! V_288 || ! V_284 || ! V_277 -> V_304 ) )
break;
return V_277 -> V_304 ( V_272 , V_308 , V_16 ) ;
case V_98 :
if ( F_80 ( ! V_291 || ! V_284 || ! V_277 -> V_305 ) )
break;
return V_277 -> V_305 ( V_272 , V_308 , V_16 ) ;
}
return - V_293 ;
}
static void F_82 ( struct V_43 * V_19 )
{
V_19 -> V_60 = V_481 ;
V_19 -> V_64 = V_482 ;
V_19 -> V_39 = 0 ;
V_19 -> V_65 = 0 ;
V_19 -> V_66 = 0 ;
V_19 -> V_67 = 0 ;
}
static int F_83 ( const struct V_276 * V_277 ,
struct V_272 * V_272 , void * V_308 , void * V_16 )
{
struct V_42 * V_19 = V_16 ;
struct V_274 * V_275 = F_61 ( V_272 ) ;
bool V_279 = V_275 -> V_280 == V_281 ;
bool V_284 = V_275 -> V_280 == V_285 ;
bool V_286 = V_275 -> V_280 == V_287 ;
bool V_288 = V_275 -> V_289 != V_290 ;
bool V_291 = V_275 -> V_289 != V_292 ;
int V_310 ;
V_310 = F_67 ( V_275 ) ;
if ( V_310 )
return V_310 ;
F_62 ( V_19 ) ;
switch ( V_19 -> type ) {
case V_55 :
if ( F_80 ( ! V_288 || ( ! V_279 && ! V_286 ) || ! V_277 -> V_483 ) )
break;
F_84 ( V_19 , V_57 . V_44 ) ;
V_310 = V_277 -> V_483 ( V_272 , V_308 , V_16 ) ;
V_19 -> V_57 . V_44 . V_306 = V_307 ;
if ( V_286 )
F_82 ( & V_19 -> V_57 . V_44 ) ;
return V_310 ;
case V_68 :
if ( F_80 ( ! V_288 || ! V_279 || ! V_277 -> V_484 ) )
break;
F_84 ( V_19 , V_57 . V_70 . V_67 ) ;
return V_277 -> V_484 ( V_272 , V_308 , V_16 ) ;
case V_74 :
if ( F_80 ( ! V_288 || ! V_279 || ! V_277 -> V_485 ) )
break;
F_84 ( V_19 , V_57 . V_52 ) ;
return V_277 -> V_485 ( V_272 , V_308 , V_16 ) ;
case V_84 :
if ( F_80 ( ! V_288 || V_279 || ! V_277 -> V_486 ) )
break;
F_84 ( V_19 , V_57 . V_48 ) ;
return V_277 -> V_486 ( V_272 , V_308 , V_16 ) ;
case V_92 :
if ( F_80 ( ! V_288 || V_279 || ! V_277 -> V_487 ) )
break;
F_84 ( V_19 , V_57 . V_50 ) ;
return V_277 -> V_487 ( V_272 , V_308 , V_16 ) ;
case V_56 :
if ( F_80 ( ! V_291 || ! V_279 || ! V_277 -> V_488 ) )
break;
F_84 ( V_19 , V_57 . V_44 ) ;
V_310 = V_277 -> V_488 ( V_272 , V_308 , V_16 ) ;
V_19 -> V_57 . V_44 . V_306 = V_307 ;
return V_310 ;
case V_69 :
if ( F_80 ( ! V_291 || ! V_279 || ! V_277 -> V_489 ) )
break;
F_84 ( V_19 , V_57 . V_70 . V_67 ) ;
return V_277 -> V_489 ( V_272 , V_308 , V_16 ) ;
case V_75 :
if ( F_80 ( ! V_291 || ! V_279 || ! V_277 -> V_490 ) )
break;
F_84 ( V_19 , V_57 . V_52 ) ;
return V_277 -> V_490 ( V_272 , V_308 , V_16 ) ;
case V_85 :
if ( F_80 ( ! V_291 || V_279 || ! V_277 -> V_491 ) )
break;
F_84 ( V_19 , V_57 . V_48 ) ;
return V_277 -> V_491 ( V_272 , V_308 , V_16 ) ;
case V_93 :
if ( F_80 ( ! V_291 || V_279 || ! V_277 -> V_492 ) )
break;
F_84 ( V_19 , V_57 . V_50 ) ;
return V_277 -> V_492 ( V_272 , V_308 , V_16 ) ;
case V_97 :
if ( F_80 ( ! V_288 || ! V_284 || ! V_277 -> V_493 ) )
break;
F_84 ( V_19 , V_57 . V_54 ) ;
return V_277 -> V_493 ( V_272 , V_308 , V_16 ) ;
case V_98 :
if ( F_80 ( ! V_291 || ! V_284 || ! V_277 -> V_494 ) )
break;
F_84 ( V_19 , V_57 . V_54 ) ;
return V_277 -> V_494 ( V_272 , V_308 , V_16 ) ;
}
return - V_293 ;
}
static int F_85 ( const struct V_276 * V_277 ,
struct V_272 * V_272 , void * V_308 , void * V_16 )
{
struct V_42 * V_19 = V_16 ;
struct V_274 * V_275 = F_61 ( V_272 ) ;
bool V_279 = V_275 -> V_280 == V_281 ;
bool V_284 = V_275 -> V_280 == V_285 ;
bool V_286 = V_275 -> V_280 == V_287 ;
bool V_288 = V_275 -> V_289 != V_290 ;
bool V_291 = V_275 -> V_289 != V_292 ;
int V_310 ;
F_62 ( V_19 ) ;
switch ( V_19 -> type ) {
case V_55 :
if ( F_80 ( ! V_288 || ( ! V_279 && ! V_286 ) || ! V_277 -> V_495 ) )
break;
F_84 ( V_19 , V_57 . V_44 ) ;
V_310 = V_277 -> V_495 ( V_272 , V_308 , V_16 ) ;
V_19 -> V_57 . V_44 . V_306 = V_307 ;
return V_310 ;
case V_68 :
if ( F_80 ( ! V_288 || ! V_279 || ! V_277 -> V_496 ) )
break;
F_84 ( V_19 , V_57 . V_70 . V_67 ) ;
return V_277 -> V_496 ( V_272 , V_308 , V_16 ) ;
case V_74 :
if ( F_80 ( ! V_288 || ! V_279 || ! V_277 -> V_497 ) )
break;
F_84 ( V_19 , V_57 . V_52 ) ;
return V_277 -> V_497 ( V_272 , V_308 , V_16 ) ;
case V_84 :
if ( F_80 ( ! V_288 || V_279 || ! V_277 -> V_498 ) )
break;
F_84 ( V_19 , V_57 . V_48 ) ;
return V_277 -> V_498 ( V_272 , V_308 , V_16 ) ;
case V_92 :
if ( F_80 ( ! V_288 || V_279 || ! V_277 -> V_499 ) )
break;
F_84 ( V_19 , V_57 . V_50 ) ;
return V_277 -> V_499 ( V_272 , V_308 , V_16 ) ;
case V_56 :
if ( F_80 ( ! V_291 || ! V_279 || ! V_277 -> V_500 ) )
break;
F_84 ( V_19 , V_57 . V_44 ) ;
V_310 = V_277 -> V_500 ( V_272 , V_308 , V_16 ) ;
V_19 -> V_57 . V_44 . V_306 = V_307 ;
return V_310 ;
case V_69 :
if ( F_80 ( ! V_291 || ! V_279 || ! V_277 -> V_501 ) )
break;
F_84 ( V_19 , V_57 . V_70 . V_67 ) ;
return V_277 -> V_501 ( V_272 , V_308 , V_16 ) ;
case V_75 :
if ( F_80 ( ! V_291 || ! V_279 || ! V_277 -> V_502 ) )
break;
F_84 ( V_19 , V_57 . V_52 ) ;
return V_277 -> V_502 ( V_272 , V_308 , V_16 ) ;
case V_85 :
if ( F_80 ( ! V_291 || V_279 || ! V_277 -> V_503 ) )
break;
F_84 ( V_19 , V_57 . V_48 ) ;
return V_277 -> V_503 ( V_272 , V_308 , V_16 ) ;
case V_93 :
if ( F_80 ( ! V_291 || V_279 || ! V_277 -> V_504 ) )
break;
F_84 ( V_19 , V_57 . V_50 ) ;
return V_277 -> V_504 ( V_272 , V_308 , V_16 ) ;
case V_97 :
if ( F_80 ( ! V_288 || ! V_284 || ! V_277 -> V_505 ) )
break;
F_84 ( V_19 , V_57 . V_54 ) ;
return V_277 -> V_505 ( V_272 , V_308 , V_16 ) ;
case V_98 :
if ( F_80 ( ! V_291 || ! V_284 || ! V_277 -> V_506 ) )
break;
F_84 ( V_19 , V_57 . V_54 ) ;
return V_277 -> V_506 ( V_272 , V_308 , V_16 ) ;
}
return - V_293 ;
}
static int F_86 ( const struct V_276 * V_277 ,
struct V_272 * V_272 , void * V_308 , void * V_16 )
{
return V_277 -> V_507 ( V_272 , V_308 , * ( unsigned int * ) V_16 ) ;
}
static int F_87 ( const struct V_276 * V_277 ,
struct V_272 * V_272 , void * V_308 , void * V_16 )
{
return V_277 -> V_508 ( V_272 , V_308 , * ( unsigned int * ) V_16 ) ;
}
static int F_88 ( const struct V_276 * V_277 ,
struct V_272 * V_272 , void * V_308 , void * V_16 )
{
struct V_274 * V_275 = F_61 ( V_272 ) ;
struct V_105 * V_19 = V_16 ;
int V_509 ;
V_19 -> type = ( V_275 -> V_280 == V_510 ) ?
V_511 : V_512 ;
V_509 = V_277 -> V_513 ( V_272 , V_308 , V_19 ) ;
if ( ! V_509 )
V_19 -> V_35 |= V_514 ;
return V_509 ;
}
static int F_89 ( const struct V_276 * V_277 ,
struct V_272 * V_272 , void * V_308 , void * V_16 )
{
struct V_274 * V_275 = F_61 ( V_272 ) ;
struct V_105 * V_19 = V_16 ;
int V_310 ;
V_310 = F_67 ( V_275 ) ;
if ( V_310 )
return V_310 ;
V_19 -> type = ( V_275 -> V_280 == V_510 ) ?
V_511 : V_512 ;
return V_277 -> V_515 ( V_272 , V_308 , V_19 ) ;
}
static int F_90 ( const struct V_276 * V_277 ,
struct V_272 * V_272 , void * V_308 , void * V_16 )
{
struct V_274 * V_275 = F_61 ( V_272 ) ;
struct V_101 * V_19 = V_16 ;
int V_509 ;
if ( V_275 -> V_280 == V_510 )
V_19 -> type = V_511 ;
V_509 = V_277 -> V_516 ( V_272 , V_308 , V_19 ) ;
if ( ! V_509 )
V_19 -> V_35 |= V_514 ;
return V_509 ;
}
static int F_91 ( const struct V_276 * V_277 ,
struct V_272 * V_272 , void * V_308 , void * V_16 )
{
struct V_274 * V_275 = F_61 ( V_272 ) ;
struct V_101 * V_19 = V_16 ;
if ( V_275 -> V_280 == V_510 )
V_19 -> type = V_511 ;
return V_277 -> V_517 ( V_272 , V_308 , V_19 ) ;
}
static int F_92 ( const struct V_276 * V_277 ,
struct V_272 * V_272 , void * V_308 , void * V_16 )
{
struct V_274 * V_275 = F_61 ( V_272 ) ;
struct V_109 * V_19 = V_16 ;
if ( V_275 -> V_280 == V_285 )
V_19 -> type = V_518 ;
else
V_19 -> type = ( V_275 -> V_280 == V_510 ) ?
V_511 : V_512 ;
return V_277 -> V_519 ( V_272 , V_308 , V_19 ) ;
}
static int F_93 ( const struct V_276 * V_277 ,
struct V_272 * V_272 , void * V_308 , void * V_16 )
{
struct V_274 * V_275 = F_61 ( V_272 ) ;
const struct V_109 * V_19 = V_16 ;
enum V_520 type ;
int V_310 ;
V_310 = F_67 ( V_275 ) ;
if ( V_310 )
return V_310 ;
if ( V_275 -> V_280 == V_285 ) {
if ( V_19 -> type != V_518 && V_19 -> type != V_521 )
return - V_293 ;
} else {
type = ( V_275 -> V_280 == V_510 ) ?
V_511 : V_512 ;
if ( type != V_19 -> type )
return - V_293 ;
}
return V_277 -> V_522 ( V_272 , V_308 , V_19 ) ;
}
static int F_94 ( const struct V_276 * V_277 ,
struct V_272 * V_272 , void * V_308 , void * V_16 )
{
struct V_274 * V_275 = F_61 ( V_272 ) ;
struct V_12 * V_19 = V_16 ;
T_1 V_1 = V_275 -> V_523 , V_524 = 0 ;
unsigned int V_27 = V_19 -> V_27 , V_3 , V_525 = 0 ;
const char * V_6 = L_267 ;
if ( V_1 == 0 )
return - V_526 ;
for ( V_3 = 0 ; V_3 <= V_27 && V_1 ; V_3 ++ ) {
while ( ( V_1 & V_4 [ V_525 ] . V_5 ) != V_4 [ V_525 ] . V_5 )
V_525 ++ ;
V_524 = V_4 [ V_525 ] . V_5 ;
V_6 = V_4 [ V_525 ] . V_6 ;
V_525 ++ ;
if ( V_524 == 0 )
break;
if ( V_524 != V_527 &&
V_524 != V_528 &&
V_524 != V_529 )
V_1 &= ~ V_524 ;
}
if ( V_3 <= V_27 )
return - V_293 ;
F_4 ( V_19 , V_524 , V_6 ) ;
return 0 ;
}
static int F_95 ( const struct V_276 * V_277 ,
struct V_272 * V_272 , void * V_308 , void * V_16 )
{
struct V_274 * V_275 = F_61 ( V_272 ) ;
T_1 V_1 = * ( T_1 * ) V_16 , V_530 ;
int V_310 ;
V_310 = F_67 ( V_275 ) ;
if ( V_310 )
return V_310 ;
V_530 = V_1 & V_275 -> V_523 ;
if ( V_275 -> V_523 && ! V_530 )
return - V_293 ;
return V_277 -> V_531 ( V_272 , V_308 , V_530 ) ;
}
static int F_96 ( const struct V_276 * V_277 ,
struct V_272 * V_272 , void * V_308 , void * V_16 )
{
struct V_274 * V_275 = F_61 ( V_272 ) ;
T_1 * V_19 = V_16 ;
int V_310 ;
V_310 = F_67 ( V_275 ) ;
if ( V_310 )
return V_310 ;
* V_19 = V_275 -> V_523 ;
return V_277 -> V_532 ( V_272 , V_308 , V_16 ) ;
}
static int F_97 ( const struct V_276 * V_277 ,
struct V_272 * V_272 , void * V_308 , void * V_16 )
{
struct V_274 * V_275 = F_61 ( V_272 ) ;
struct V_111 * V_19 = V_16 ;
enum V_520 type ;
int V_310 ;
V_310 = F_67 ( V_275 ) ;
if ( V_310 )
return V_310 ;
if ( V_275 -> V_280 == V_285 )
return - V_293 ;
type = ( V_275 -> V_280 == V_510 ) ?
V_511 : V_512 ;
if ( V_19 -> type != type )
return - V_293 ;
return V_277 -> V_533 ( V_272 , V_308 , V_19 ) ;
}
static int F_98 ( const struct V_276 * V_277 ,
struct V_272 * V_272 , void * V_308 , void * V_16 )
{
return V_277 -> V_534 ( V_272 , V_308 , * ( unsigned int * ) V_16 ) ;
}
static int F_99 ( const struct V_276 * V_277 ,
struct V_272 * V_272 , void * V_308 , void * V_16 )
{
struct V_115 * V_19 = V_16 ;
int V_310 = F_60 ( V_272 , V_19 -> type ) ;
if ( V_310 )
return V_310 ;
F_84 ( V_19 , V_116 ) ;
return V_277 -> V_535 ( V_272 , V_308 , V_19 ) ;
}
static int F_100 ( const struct V_276 * V_277 ,
struct V_272 * V_272 , void * V_308 , void * V_16 )
{
struct V_118 * V_19 = V_16 ;
int V_310 = F_60 ( V_272 , V_19 -> type ) ;
return V_310 ? V_310 : V_277 -> V_536 ( V_272 , V_308 , V_19 ) ;
}
static int F_101 ( const struct V_276 * V_277 ,
struct V_272 * V_272 , void * V_308 , void * V_16 )
{
struct V_118 * V_19 = V_16 ;
int V_310 = F_60 ( V_272 , V_19 -> type ) ;
return V_310 ? V_310 : V_277 -> V_537 ( V_272 , V_308 , V_19 ) ;
}
static int F_102 ( const struct V_276 * V_277 ,
struct V_272 * V_272 , void * V_308 , void * V_16 )
{
struct V_118 * V_19 = V_16 ;
int V_310 = F_60 ( V_272 , V_19 -> type ) ;
return V_310 ? V_310 : V_277 -> V_538 ( V_272 , V_308 , V_19 ) ;
}
static int F_103 ( const struct V_276 * V_277 ,
struct V_272 * V_272 , void * V_308 , void * V_16 )
{
struct V_142 * V_539 = V_16 ;
int V_310 = F_60 ( V_272 , V_539 -> V_143 . type ) ;
if ( V_310 )
return V_310 ;
F_84 ( V_539 , V_143 ) ;
F_62 ( & V_539 -> V_143 ) ;
V_310 = V_277 -> V_540 ( V_272 , V_308 , V_539 ) ;
if ( V_539 -> V_143 . type == V_55 ||
V_539 -> V_143 . type == V_56 )
V_539 -> V_143 . V_57 . V_44 . V_306 = V_307 ;
return V_310 ;
}
static int F_104 ( const struct V_276 * V_277 ,
struct V_272 * V_272 , void * V_308 , void * V_16 )
{
struct V_118 * V_541 = V_16 ;
int V_310 = F_60 ( V_272 , V_541 -> type ) ;
return V_310 ? V_310 : V_277 -> V_542 ( V_272 , V_308 , V_541 ) ;
}
static int F_105 ( const struct V_276 * V_277 ,
struct V_272 * V_272 , void * V_308 , void * V_16 )
{
struct V_144 * V_19 = V_16 ;
T_1 V_5 ;
int V_310 = F_60 ( V_272 , V_19 -> type ) ;
if ( V_310 )
return V_310 ;
if ( V_277 -> V_543 )
return V_277 -> V_543 ( V_272 , V_308 , V_19 ) ;
if ( V_19 -> type != V_55 &&
V_19 -> type != V_68 )
return - V_293 ;
V_19 -> V_147 . V_148 . V_152 = 2 ;
V_310 = V_277 -> V_544 ( V_272 , V_308 , & V_5 ) ;
if ( V_310 == 0 )
F_3 ( V_5 , & V_19 -> V_147 . V_148 . V_150 ) ;
return V_310 ;
}
static int F_106 ( const struct V_276 * V_277 ,
struct V_272 * V_272 , void * V_308 , void * V_16 )
{
struct V_144 * V_19 = V_16 ;
int V_310 = F_60 ( V_272 , V_19 -> type ) ;
return V_310 ? V_310 : V_277 -> V_545 ( V_272 , V_308 , V_19 ) ;
}
static int F_107 ( const struct V_276 * V_277 ,
struct V_272 * V_272 , void * V_308 , void * V_16 )
{
struct V_274 * V_275 = F_61 ( V_272 ) ;
struct V_157 * V_19 = V_16 ;
struct V_318 * V_319 =
F_72 ( V_320 , & V_275 -> V_39 ) ? V_308 : NULL ;
if ( V_319 && V_319 -> V_546 )
return V_157 ( V_319 -> V_546 , V_19 ) ;
if ( V_275 -> V_546 )
return V_157 ( V_275 -> V_546 , V_19 ) ;
if ( V_277 -> V_547 )
return V_277 -> V_547 ( V_272 , V_308 , V_19 ) ;
return - V_321 ;
}
static int F_108 ( const struct V_276 * V_277 ,
struct V_272 * V_272 , void * V_308 , void * V_16 )
{
struct V_274 * V_275 = F_61 ( V_272 ) ;
struct V_162 * V_19 = V_16 ;
struct V_318 * V_319 =
F_72 ( V_320 , & V_275 -> V_39 ) ? V_308 : NULL ;
if ( V_319 && V_319 -> V_546 )
return V_162 ( V_319 -> V_546 , V_19 ) ;
if ( V_275 -> V_546 )
return V_162 ( V_275 -> V_546 , V_19 ) ;
if ( V_277 -> V_548 )
return V_277 -> V_548 ( V_272 , V_308 , V_19 ) ;
return - V_321 ;
}
static int F_109 ( const struct V_276 * V_277 ,
struct V_272 * V_272 , void * V_308 , void * V_16 )
{
struct V_274 * V_275 = F_61 ( V_272 ) ;
struct V_167 * V_19 = V_16 ;
struct V_318 * V_319 =
F_72 ( V_320 , & V_275 -> V_39 ) ? V_308 : NULL ;
if ( V_319 && V_319 -> V_546 )
return V_167 ( V_319 -> V_546 , V_19 ) ;
if ( V_275 -> V_546 )
return V_167 ( V_275 -> V_546 , V_19 ) ;
if ( V_277 -> V_549 )
return V_277 -> V_549 ( V_272 , V_308 , V_19 ) ;
return - V_321 ;
}
static int F_110 ( const struct V_276 * V_277 ,
struct V_272 * V_272 , void * V_308 , void * V_16 )
{
struct V_274 * V_275 = F_61 ( V_272 ) ;
struct V_168 * V_19 = V_16 ;
struct V_318 * V_319 =
F_72 ( V_320 , & V_275 -> V_39 ) ? V_308 : NULL ;
struct V_170 V_550 ;
struct V_551 V_253 ;
if ( V_319 && V_319 -> V_546 )
return F_111 ( V_319 -> V_546 , V_19 ) ;
if ( V_275 -> V_546 )
return F_111 ( V_275 -> V_546 , V_19 ) ;
if ( V_277 -> V_552 )
return V_277 -> V_552 ( V_272 , V_308 , V_19 ) ;
if ( V_277 -> V_553 == NULL )
return - V_321 ;
V_550 . V_171 = F_59 ( V_19 -> V_1 ) ;
V_550 . V_91 = 1 ;
V_550 . V_173 = & V_253 ;
V_253 . V_1 = V_19 -> V_1 ;
V_253 . V_169 = V_19 -> V_169 ;
if ( F_58 ( & V_550 , 1 ) ) {
int V_310 = V_277 -> V_553 ( V_272 , V_308 , & V_550 ) ;
if ( V_310 == 0 )
V_19 -> V_169 = V_253 . V_169 ;
return V_310 ;
}
return - V_293 ;
}
static int F_112 ( const struct V_276 * V_277 ,
struct V_272 * V_272 , void * V_308 , void * V_16 )
{
struct V_274 * V_275 = F_61 ( V_272 ) ;
struct V_168 * V_19 = V_16 ;
struct V_318 * V_319 =
F_72 ( V_320 , & V_275 -> V_39 ) ? V_308 : NULL ;
struct V_170 V_550 ;
struct V_551 V_253 ;
if ( V_319 && V_319 -> V_546 )
return F_113 ( V_319 , V_319 -> V_546 , V_19 ) ;
if ( V_275 -> V_546 )
return F_113 ( NULL , V_275 -> V_546 , V_19 ) ;
if ( V_277 -> V_554 )
return V_277 -> V_554 ( V_272 , V_308 , V_19 ) ;
if ( V_277 -> V_555 == NULL )
return - V_321 ;
V_550 . V_171 = F_59 ( V_19 -> V_1 ) ;
V_550 . V_91 = 1 ;
V_550 . V_173 = & V_253 ;
V_253 . V_1 = V_19 -> V_1 ;
V_253 . V_169 = V_19 -> V_169 ;
if ( F_58 ( & V_550 , 1 ) )
return V_277 -> V_555 ( V_272 , V_308 , & V_550 ) ;
return - V_293 ;
}
static int F_114 ( const struct V_276 * V_277 ,
struct V_272 * V_272 , void * V_308 , void * V_16 )
{
struct V_274 * V_275 = F_61 ( V_272 ) ;
struct V_170 * V_19 = V_16 ;
struct V_318 * V_319 =
F_72 ( V_320 , & V_275 -> V_39 ) ? V_308 : NULL ;
V_19 -> V_172 = V_19 -> V_91 ;
if ( V_319 && V_319 -> V_546 )
return F_115 ( V_319 -> V_546 , V_19 ) ;
if ( V_275 -> V_546 )
return F_115 ( V_275 -> V_546 , V_19 ) ;
if ( V_277 -> V_553 == NULL )
return - V_321 ;
return F_58 ( V_19 , 0 ) ? V_277 -> V_553 ( V_272 , V_308 , V_19 ) :
- V_293 ;
}
static int F_116 ( const struct V_276 * V_277 ,
struct V_272 * V_272 , void * V_308 , void * V_16 )
{
struct V_274 * V_275 = F_61 ( V_272 ) ;
struct V_170 * V_19 = V_16 ;
struct V_318 * V_319 =
F_72 ( V_320 , & V_275 -> V_39 ) ? V_308 : NULL ;
V_19 -> V_172 = V_19 -> V_91 ;
if ( V_319 && V_319 -> V_546 )
return F_117 ( V_319 , V_319 -> V_546 , V_19 ) ;
if ( V_275 -> V_546 )
return F_117 ( NULL , V_275 -> V_546 , V_19 ) ;
if ( V_277 -> V_555 == NULL )
return - V_321 ;
return F_58 ( V_19 , 0 ) ? V_277 -> V_555 ( V_272 , V_308 , V_19 ) :
- V_293 ;
}
static int F_118 ( const struct V_276 * V_277 ,
struct V_272 * V_272 , void * V_308 , void * V_16 )
{
struct V_274 * V_275 = F_61 ( V_272 ) ;
struct V_170 * V_19 = V_16 ;
struct V_318 * V_319 =
F_72 ( V_320 , & V_275 -> V_39 ) ? V_308 : NULL ;
V_19 -> V_172 = V_19 -> V_91 ;
if ( V_319 && V_319 -> V_546 )
return F_119 ( V_319 -> V_546 , V_19 ) ;
if ( V_275 -> V_546 )
return F_119 ( V_275 -> V_546 , V_19 ) ;
if ( V_277 -> V_556 == NULL )
return - V_321 ;
return F_58 ( V_19 , 0 ) ? V_277 -> V_556 ( V_272 , V_308 , V_19 ) :
- V_293 ;
}
static int F_120 ( const struct V_276 * V_277 ,
struct V_272 * V_272 , void * V_308 , void * V_16 )
{
struct V_179 * V_19 = V_16 ;
struct V_180 V_557 = {
. type = V_19 -> type ,
} ;
int V_310 ;
if ( V_277 -> V_558 )
return V_277 -> V_558 ( V_272 , V_308 , V_19 ) ;
if ( F_121 ( V_19 -> type ) )
V_557 . V_181 = V_559 ;
else
V_557 . V_181 = V_560 ;
V_310 = V_277 -> V_561 ( V_272 , V_308 , & V_557 ) ;
if ( ! V_310 )
V_19 -> V_146 = V_557 . V_182 ;
return V_310 ;
}
static int F_122 ( const struct V_276 * V_277 ,
struct V_272 * V_272 , void * V_308 , void * V_16 )
{
struct V_179 * V_19 = V_16 ;
struct V_180 V_557 = {
. type = V_19 -> type ,
. V_182 = V_19 -> V_146 ,
} ;
if ( V_277 -> V_562 )
return V_277 -> V_562 ( V_272 , V_308 , V_19 ) ;
if ( F_121 ( V_19 -> type ) )
V_557 . V_181 = V_559 ;
else
V_557 . V_181 = V_560 ;
return V_277 -> V_563 ( V_272 , V_308 , & V_557 ) ;
}
static int F_123 ( const struct V_276 * V_277 ,
struct V_272 * V_272 , void * V_308 , void * V_16 )
{
struct V_175 * V_19 = V_16 ;
struct V_180 V_557 = { . type = V_19 -> type } ;
int V_310 = 0 ;
V_19 -> V_178 . V_10 = 1 ;
V_19 -> V_178 . V_11 = 1 ;
if ( F_78 ( ! V_277 -> V_564 && ! V_277 -> V_561 ) )
return - V_321 ;
if ( V_277 -> V_564 )
V_310 = V_277 -> V_564 ( V_272 , V_308 , V_19 ) ;
if ( ! V_277 -> V_561 )
return V_310 ;
if ( V_310 && V_310 != - V_321 && V_310 != - V_565 )
return V_310 ;
if ( F_121 ( V_19 -> type ) )
V_557 . V_181 = V_566 ;
else
V_557 . V_181 = V_567 ;
V_310 = V_277 -> V_561 ( V_272 , V_308 , & V_557 ) ;
if ( V_310 )
return V_310 ;
V_19 -> V_176 = V_557 . V_182 ;
if ( F_121 ( V_19 -> type ) )
V_557 . V_181 = V_568 ;
else
V_557 . V_181 = V_569 ;
V_310 = V_277 -> V_561 ( V_272 , V_308 , & V_557 ) ;
if ( V_310 )
return V_310 ;
V_19 -> V_177 = V_557 . V_182 ;
return 0 ;
}
static int F_124 ( const struct V_276 * V_277 ,
struct V_272 * V_272 , void * V_308 , void * V_16 )
{
struct V_274 * V_275 = F_61 ( V_272 ) ;
int V_310 ;
if ( V_275 -> V_570 )
F_42 ( L_268 ,
V_275 -> V_570 -> V_14 ) ;
V_310 = V_277 -> V_571 ( V_272 , V_308 ) ;
if ( V_275 -> V_570 )
F_42 ( L_269 ,
V_275 -> V_570 -> V_14 ) ;
return V_310 ;
}
static int F_125 ( const struct V_276 * V_277 ,
struct V_272 * V_272 , void * V_308 , void * V_16 )
{
#ifdef F_126
struct V_204 * V_19 = V_16 ;
struct V_274 * V_275 = F_61 ( V_272 ) ;
struct V_572 * V_573 ;
int V_574 = 0 ;
if ( ! F_127 ( V_575 ) )
return - V_576 ;
if ( V_19 -> V_201 . type == V_577 ) {
if ( V_275 -> V_570 == NULL )
return - V_293 ;
F_128 (sd, vfd->v4l2_dev)
if ( V_19 -> V_201 . V_203 == V_574 ++ )
return F_129 ( V_573 , V_578 , V_579 , V_19 ) ;
return - V_293 ;
}
if ( V_277 -> V_580 && V_19 -> V_201 . type == V_581 &&
( V_277 -> V_582 || V_19 -> V_201 . V_203 == 0 ) )
return V_277 -> V_580 ( V_272 , V_308 , V_19 ) ;
return - V_293 ;
#else
return - V_321 ;
#endif
}
static int F_130 ( const struct V_276 * V_277 ,
struct V_272 * V_272 , void * V_308 , void * V_16 )
{
#ifdef F_126
const struct V_204 * V_19 = V_16 ;
struct V_274 * V_275 = F_61 ( V_272 ) ;
struct V_572 * V_573 ;
int V_574 = 0 ;
if ( ! F_127 ( V_575 ) )
return - V_576 ;
if ( V_19 -> V_201 . type == V_577 ) {
if ( V_275 -> V_570 == NULL )
return - V_293 ;
F_128 (sd, vfd->v4l2_dev)
if ( V_19 -> V_201 . V_203 == V_574 ++ )
return F_129 ( V_573 , V_578 , V_583 , V_19 ) ;
return - V_293 ;
}
if ( V_277 -> V_584 && V_19 -> V_201 . type == V_581 &&
( V_277 -> V_582 || V_19 -> V_201 . V_203 == 0 ) )
return V_277 -> V_584 ( V_272 , V_308 , V_19 ) ;
return - V_293 ;
#else
return - V_321 ;
#endif
}
static int F_131 ( const struct V_276 * V_277 ,
struct V_272 * V_272 , void * V_308 , void * V_16 )
{
#ifdef F_126
struct V_274 * V_275 = F_61 ( V_272 ) ;
struct V_200 * V_19 = V_16 ;
struct V_572 * V_573 ;
int V_574 = 0 ;
switch ( V_19 -> V_201 . type ) {
case V_581 :
if ( V_277 -> V_584 )
V_19 -> V_39 |= V_585 ;
if ( V_277 -> V_580 )
V_19 -> V_39 |= V_586 ;
F_5 ( V_19 -> V_14 , V_275 -> V_570 -> V_14 , sizeof( V_19 -> V_14 ) ) ;
if ( V_277 -> V_582 )
return V_277 -> V_582 ( V_272 , V_308 , V_16 ) ;
if ( V_19 -> V_201 . V_203 )
return - V_293 ;
return 0 ;
case V_577 :
if ( V_275 -> V_570 == NULL )
break;
F_128 (sd, vfd->v4l2_dev) {
if ( V_19 -> V_201 . V_203 != V_574 ++ )
continue;
if ( V_573 -> V_277 -> V_578 && V_573 -> V_277 -> V_578 -> V_583 )
V_19 -> V_39 |= V_585 ;
if ( V_573 -> V_277 -> V_578 && V_573 -> V_277 -> V_578 -> V_579 )
V_19 -> V_39 |= V_586 ;
F_5 ( V_19 -> V_14 , V_573 -> V_14 , sizeof( V_19 -> V_14 ) ) ;
return 0 ;
}
break;
}
return - V_293 ;
#else
return - V_321 ;
#endif
}
static int F_132 ( const struct V_276 * V_277 ,
struct V_272 * V_272 , void * V_308 , void * V_16 )
{
return F_133 ( V_308 , V_16 , V_272 -> V_587 & V_588 ) ;
}
static int F_134 ( const struct V_276 * V_277 ,
struct V_272 * V_272 , void * V_308 , void * V_16 )
{
return V_277 -> V_589 ( V_308 , V_16 ) ;
}
static int F_135 ( const struct V_276 * V_277 ,
struct V_272 * V_272 , void * V_308 , void * V_16 )
{
return V_277 -> V_590 ( V_308 , V_16 ) ;
}
static int F_136 ( const struct V_276 * V_277 ,
struct V_272 * V_272 , void * V_308 , void * V_16 )
{
struct V_261 * V_19 = V_16 ;
int V_310 = F_60 ( V_272 , V_19 -> type ) ;
if ( V_310 )
return V_310 ;
memset ( V_19 , 0 , F_63 ( struct V_261 , type ) ) ;
return V_277 -> V_591 ( V_272 , V_308 , V_19 ) ;
}
static int F_137 ( const struct V_276 * V_277 ,
struct V_272 * V_272 , void * V_308 , void * V_16 )
{
struct V_274 * V_275 = F_61 ( V_272 ) ;
struct V_262 * V_19 = V_16 ;
enum V_520 type ;
int V_509 ;
if ( V_275 -> V_280 == V_285 ) {
if ( V_19 -> type != V_518 && V_19 -> type != V_521 )
return - V_293 ;
type = V_19 -> type ;
} else {
type = ( V_275 -> V_280 == V_510 ) ?
V_511 : V_512 ;
if ( type != V_19 -> type )
return - V_293 ;
}
if ( V_277 -> V_592 ) {
V_509 = V_277 -> V_592 ( V_272 , V_308 , V_19 ) ;
if ( V_509 != - V_321 )
return V_509 ;
}
if ( F_75 ( V_275 , V_593 ) ) {
struct V_105 V_594 = {
. V_27 = V_19 -> V_29 ,
. type = type ,
} ;
if ( V_19 -> V_27 )
return - V_293 ;
V_509 = V_277 -> V_513 ( V_272 , V_308 , & V_594 ) ;
if ( V_509 )
return V_509 ;
V_19 -> V_35 = V_594 . V_35 | V_514 ;
V_19 -> V_103 = V_594 . V_103 ;
V_19 -> V_104 = V_594 . V_104 ;
V_19 -> V_263 = ( type == V_511 ) ?
V_595 : V_596 ;
return 0 ;
}
if ( F_75 ( V_275 , V_597 ) ) {
struct V_101 V_128 = {
. V_27 = V_19 -> V_29 ,
} ;
if ( type != V_511 )
return - V_293 ;
if ( V_19 -> V_27 )
return - V_293 ;
V_509 = V_277 -> V_516 ( V_272 , V_308 , & V_128 ) ;
if ( V_509 )
return V_509 ;
V_19 -> V_35 = V_128 . V_35 | V_514 ;
V_19 -> V_103 = V_128 . V_103 ;
V_19 -> V_104 = V_128 . V_104 ;
V_19 -> V_263 = ( type == V_511 ) ?
V_595 : V_596 ;
return 0 ;
}
return - V_321 ;
}
bool F_138 ( unsigned int V_193 )
{
if ( F_139 ( V_193 ) >= V_598 )
return false ;
return V_599 [ F_139 ( V_193 ) ] . V_600 == V_193 ;
}
struct V_601 * F_140 ( struct V_274 * V_602 , unsigned V_193 )
{
if ( F_139 ( V_193 ) >= V_598 )
return V_602 -> V_603 ;
if ( F_72 ( F_139 ( V_193 ) , V_602 -> V_604 ) )
return NULL ;
if ( V_602 -> V_605 && V_602 -> V_605 -> V_603 &&
( V_599 [ F_139 ( V_193 ) ] . V_39 & V_606 ) )
return V_602 -> V_605 -> V_603 ;
return V_602 -> V_603 ;
}
void F_141 ( const char * V_607 , unsigned int V_193 )
{
const char * V_608 , * type ;
if ( V_607 )
F_15 ( V_72 L_270 , V_607 ) ;
switch ( F_142 ( V_193 ) ) {
case 'd' :
type = L_271 ;
break;
case 'V' :
if ( F_139 ( V_193 ) >= V_598 ) {
type = L_272 ;
break;
}
F_7 ( L_273 , V_599 [ F_139 ( V_193 ) ] . V_14 ) ;
return;
default:
type = L_274 ;
break;
}
switch ( F_143 ( V_193 ) ) {
case V_609 : V_608 = L_275 ; break;
case V_610 : V_608 = L_276 ; break;
case V_611 : V_608 = L_277 ; break;
case V_610 | V_611 : V_608 = L_278 ; break;
default: V_608 = L_279 ; break;
}
F_7 ( L_280 ,
type , F_142 ( V_193 ) , V_608 , F_139 ( V_193 ) , V_193 ) ;
}
static long F_144 ( struct V_272 * V_272 ,
unsigned int V_193 , void * V_16 )
{
struct V_274 * V_275 = F_61 ( V_272 ) ;
const struct V_276 * V_277 = V_275 -> V_278 ;
bool V_17 = false ;
struct V_612 V_613 ;
const struct V_612 * V_614 ;
void * V_308 = V_272 -> V_322 ;
struct V_318 * V_319 = NULL ;
int V_615 = V_275 -> V_615 ;
long V_310 = - V_321 ;
if ( V_277 == NULL ) {
F_145 ( L_281 ,
F_146 ( V_275 ) ) ;
return V_310 ;
}
if ( F_72 ( V_320 , & V_275 -> V_39 ) )
V_319 = V_272 -> V_322 ;
if ( F_138 ( V_193 ) ) {
V_614 = & V_599 [ F_139 ( V_193 ) ] ;
if ( ! F_72 ( F_139 ( V_193 ) , V_275 -> V_616 ) &&
! ( ( V_614 -> V_39 & V_617 ) && V_319 && V_319 -> V_546 ) )
goto V_618;
if ( V_319 && ( V_614 -> V_39 & V_619 ) ) {
V_310 = F_147 ( V_275 -> V_317 , V_319 -> V_317 ) ;
if ( V_310 )
goto V_618;
}
} else {
V_613 . V_600 = V_193 ;
V_613 . V_39 = 0 ;
V_613 . V_620 = F_57 ;
V_614 = & V_613 ;
}
V_17 = F_143 ( V_193 ) == V_611 ;
if ( V_614 -> V_39 & V_621 ) {
typedef int (* F_148)( struct V_272 * V_272 , void * V_308 , void * V_19 );
const void * V_19 = V_275 -> V_278 ;
const F_148 * V_622 = V_19 + V_614 -> V_251 . V_87 ;
V_310 = (* V_622)( V_272 , V_308 , V_16 ) ;
} else if ( V_614 -> V_39 & V_623 ) {
V_310 = V_614 -> V_251 . V_624 ( V_277 , V_272 , V_308 , V_16 ) ;
} else if ( ! V_277 -> V_625 ) {
V_310 = - V_321 ;
} else {
V_310 = V_277 -> V_625 ( V_272 , V_308 ,
V_319 ? F_147 ( V_275 -> V_317 , V_319 -> V_317 ) >= 0 : 0 ,
V_193 , V_16 ) ;
}
V_618:
if ( V_615 & ( V_626 | V_627 ) ) {
if ( ! ( V_615 & V_628 ) &&
( V_193 == V_629 || V_193 == V_630 ) )
return V_310 ;
F_141 ( F_146 ( V_275 ) , V_193 ) ;
if ( V_310 < 0 )
F_7 ( L_282 , V_310 ) ;
if ( ! ( V_615 & V_627 ) )
F_7 ( L_47 ) ;
else if ( F_143 ( V_193 ) == V_609 )
V_614 -> V_620 ( V_16 , V_17 ) ;
else {
F_7 ( L_283 ) ;
V_614 -> V_620 ( V_16 , V_17 ) ;
}
}
return V_310 ;
}
static int F_149 ( unsigned int V_193 , void * V_631 , T_4 * V_632 ,
void T_3 * * V_633 , void * * * V_634 )
{
int V_310 = 0 ;
switch ( V_193 ) {
case V_635 :
case V_636 :
case V_629 :
case V_630 : {
struct V_118 * V_637 = V_631 ;
if ( F_26 ( V_637 -> type ) && V_637 -> V_130 > 0 ) {
if ( V_637 -> V_130 > V_638 ) {
V_310 = - V_293 ;
break;
}
* V_633 = ( void T_3 * ) V_637 -> V_128 . V_129 ;
* V_634 = ( void * * ) & V_637 -> V_128 . V_129 ;
* V_632 = sizeof( struct V_122 ) * V_637 -> V_130 ;
V_310 = 1 ;
}
break;
}
case V_639 :
case V_640 : {
struct V_264 * V_641 = V_631 ;
if ( V_641 -> V_267 ) {
if ( V_641 -> V_267 > 256 ) {
V_310 = - V_293 ;
break;
}
* V_633 = ( void T_3 * ) V_641 -> V_641 ;
* V_634 = ( void * * ) & V_641 -> V_641 ;
* V_632 = V_641 -> V_267 * 128 ;
V_310 = 1 ;
}
break;
}
case V_642 :
case V_643 :
case V_644 : {
struct V_170 * V_550 = V_631 ;
if ( V_550 -> V_91 != 0 ) {
if ( V_550 -> V_91 > V_645 ) {
V_310 = - V_293 ;
break;
}
* V_633 = ( void T_3 * ) V_550 -> V_173 ;
* V_634 = ( void * * ) & V_550 -> V_173 ;
* V_632 = sizeof( struct V_551 )
* V_550 -> V_91 ;
V_310 = 1 ;
}
break;
}
}
return V_310 ;
}
long
F_150 ( struct V_272 * V_272 , unsigned int V_193 , unsigned long V_16 ,
T_5 V_624 )
{
char V_646 [ 128 ] ;
void * V_647 = NULL ;
void * V_631 = ( void * ) V_16 ;
long V_509 = - V_293 ;
bool V_648 ;
T_4 V_632 = 0 ;
void T_3 * V_633 = NULL ;
void * * V_634 = NULL ;
if ( F_143 ( V_193 ) != V_609 ) {
if ( F_151 ( V_193 ) <= sizeof( V_646 ) ) {
V_631 = V_646 ;
} else {
V_647 = F_152 ( F_151 ( V_193 ) , V_649 ) ;
if ( NULL == V_647 )
return - V_650 ;
V_631 = V_647 ;
}
V_509 = - V_651 ;
if ( F_143 ( V_193 ) & V_611 ) {
unsigned int V_652 = F_151 ( V_193 ) ;
if ( F_138 ( V_193 ) ) {
T_2 V_39 = V_599 [ F_139 ( V_193 ) ] . V_39 ;
if ( V_39 & V_653 )
V_652 = ( V_39 & V_653 ) >> 16 ;
}
if ( F_153 ( V_631 , ( void T_3 * ) V_16 , V_652 ) )
goto V_654;
if ( V_652 < F_151 ( V_193 ) )
memset ( ( V_655 * ) V_631 + V_652 , 0 , F_151 ( V_193 ) - V_652 ) ;
} else {
memset ( V_631 , 0 , F_151 ( V_193 ) ) ;
}
}
V_509 = F_149 ( V_193 , V_631 , & V_632 , & V_633 , & V_634 ) ;
if ( V_509 < 0 )
goto V_654;
V_648 = V_509 ;
if ( V_648 ) {
V_647 = F_152 ( V_632 , V_649 ) ;
V_509 = - V_650 ;
if ( NULL == V_647 )
goto V_656;
V_509 = - V_651 ;
if ( F_153 ( V_647 , V_633 , V_632 ) )
goto V_656;
* V_634 = V_647 ;
}
V_509 = V_624 ( V_272 , V_193 , V_631 ) ;
if ( V_509 == - V_565 )
V_509 = - V_321 ;
if ( V_509 == 0 ) {
if ( V_193 == V_630 )
F_154 ( F_61 ( V_272 ) -> V_657 , V_631 ) ;
else if ( V_193 == V_629 )
F_155 ( F_61 ( V_272 ) -> V_657 , V_631 ) ;
}
if ( V_648 ) {
* V_634 = ( void V_658 * ) V_633 ;
if ( F_156 ( V_633 , V_647 , V_632 ) )
V_509 = - V_651 ;
goto V_656;
}
if ( V_509 < 0 && V_193 != V_659 )
goto V_654;
V_656:
switch ( F_143 ( V_193 ) ) {
case V_610 :
case ( V_611 | V_610 ) :
if ( F_156 ( ( void T_3 * ) V_16 , V_631 , F_151 ( V_193 ) ) )
V_509 = - V_651 ;
break;
}
V_654:
F_157 ( V_647 ) ;
return V_509 ;
}
long F_158 ( struct V_272 * V_272 ,
unsigned int V_193 , unsigned long V_16 )
{
return F_150 ( V_272 , V_193 , V_16 , F_144 ) ;
}
