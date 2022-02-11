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
const struct V_98 * V_19 = V_16 ;
F_7 ( L_27
L_28
L_29 ,
V_19 -> V_35 , V_19 -> V_39 , V_19 -> V_99 ,
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
const struct V_100 * V_19 = V_16 ;
if ( V_17 )
F_7 ( L_31 , V_19 -> V_27 , V_19 -> V_101 ) ;
else
F_7 ( L_32
L_33 ,
V_19 -> V_27 , ( int ) sizeof( V_19 -> V_14 ) , V_19 -> V_14 , V_19 -> V_35 ,
V_19 -> V_102 , V_19 -> V_103 , V_19 -> V_101 ) ;
}
static void F_19 ( const void * V_16 , bool V_17 )
{
const struct V_104 * V_19 = V_16 ;
if ( V_17 )
F_7 ( L_34 , V_19 -> V_27 , V_19 -> V_105 ) ;
else
F_7 ( L_35
L_36
L_37 ,
V_19 -> V_27 , ( int ) sizeof( V_19 -> V_14 ) , V_19 -> V_14 , V_19 -> type ,
V_19 -> V_35 , V_19 -> V_102 ,
V_19 -> V_103 , V_19 -> signal , V_19 -> V_106 ,
V_19 -> V_107 , V_19 -> V_105 ) ;
}
static void F_20 ( const void * V_16 , bool V_17 )
{
const struct V_108 * V_19 = V_16 ;
F_7 ( L_38 ,
V_19 -> V_29 , V_19 -> type , V_19 -> V_109 ) ;
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
const struct V_110 * V_19 = V_16 ;
F_7 ( L_42
L_43 ,
V_19 -> V_29 , V_19 -> type , V_19 -> V_111 , V_19 -> V_112 , V_19 -> V_113 ,
V_19 -> V_102 , V_19 -> V_103 ) ;
}
static void F_24 ( const void * V_16 , bool V_17 )
{
const struct V_114 * V_19 = V_16 ;
F_7 ( L_44 ,
V_19 -> V_91 ,
F_13 ( V_19 -> type , V_38 ) ,
F_13 ( V_19 -> V_115 , V_116 ) ) ;
}
static void F_25 ( const void * V_16 , bool V_17 )
{
const struct V_117 * V_19 = V_16 ;
const struct V_118 * V_119 = & V_19 -> V_120 ;
const struct V_121 * V_122 ;
int V_3 ;
F_7 ( L_45
L_46 ,
V_19 -> V_123 . V_124 / 3600 ,
( int ) ( V_19 -> V_123 . V_124 / 60 ) % 60 ,
( int ) ( V_19 -> V_123 . V_124 % 60 ) ,
( long ) V_19 -> V_123 . V_125 ,
V_19 -> V_27 ,
F_13 ( V_19 -> type , V_38 ) ,
V_19 -> V_39 , F_13 ( V_19 -> V_60 , V_61 ) ,
V_19 -> V_126 , F_13 ( V_19 -> V_115 , V_116 ) ) ;
if ( F_26 ( V_19 -> type ) && V_19 -> V_127 . V_128 ) {
F_7 ( L_47 ) ;
for ( V_3 = 0 ; V_3 < V_19 -> V_129 ; ++ V_3 ) {
V_122 = & V_19 -> V_127 . V_128 [ V_3 ] ;
F_15 ( V_72
L_48
L_49 ,
V_3 , V_122 -> V_130 , V_122 -> V_131 ,
V_122 -> V_127 . V_132 , V_122 -> V_129 ) ;
}
} else {
F_7 ( L_50 ,
V_19 -> V_130 , V_19 -> V_127 . V_132 , V_19 -> V_129 ) ;
}
F_15 ( V_72 L_51
L_52 ,
V_119 -> V_133 , V_119 -> V_134 , V_119 -> V_135 ,
V_119 -> type , V_119 -> V_39 , V_119 -> V_136 , * ( V_137 * ) V_119 -> V_138 ) ;
}
static void F_27 ( const void * V_16 , bool V_17 )
{
const struct V_139 * V_19 = V_16 ;
F_7 ( L_53 ,
V_19 -> V_140 , F_13 ( V_19 -> type , V_38 ) ,
V_19 -> V_27 , V_19 -> V_122 , V_19 -> V_39 ) ;
}
static void F_28 ( const void * V_16 , bool V_17 )
{
const struct V_141 * V_19 = V_16 ;
F_7 ( L_54 ,
V_19 -> V_27 , V_19 -> V_91 ,
F_13 ( V_19 -> V_115 , V_116 ) ) ;
F_14 ( & V_19 -> V_142 , V_17 ) ;
}
static void F_29 ( const void * V_16 , bool V_17 )
{
const struct V_143 * V_19 = V_16 ;
F_7 ( L_11 , F_13 ( V_19 -> type , V_38 ) ) ;
if ( V_19 -> type == V_55 ||
V_19 -> type == V_68 ) {
const struct V_144 * V_145 = & V_19 -> V_146 . V_147 ;
F_7 ( L_55
L_56 ,
V_145 -> V_35 , V_145 -> V_148 ,
V_145 -> V_149 . V_10 , V_145 -> V_149 . V_11 ,
V_145 -> V_150 , V_145 -> V_151 ) ;
} else if ( V_19 -> type == V_56 ||
V_19 -> type == V_69 ) {
const struct V_152 * V_145 = & V_19 -> V_146 . V_153 ;
F_7 ( L_57
L_58 ,
V_145 -> V_35 , V_145 -> V_154 ,
V_145 -> V_149 . V_10 , V_145 -> V_149 . V_11 ,
V_145 -> V_150 , V_145 -> V_155 ) ;
} else {
F_7 ( L_47 ) ;
}
}
static void F_30 ( const void * V_16 , bool V_17 )
{
const struct V_156 * V_19 = V_16 ;
F_7 ( L_59
L_60 ,
V_19 -> V_1 , V_19 -> type , ( int ) sizeof( V_19 -> V_14 ) , V_19 -> V_14 ,
V_19 -> V_157 , V_19 -> V_158 ,
V_19 -> V_159 , V_19 -> V_160 , V_19 -> V_39 ) ;
}
static void F_31 ( const void * V_16 , bool V_17 )
{
const struct V_161 * V_19 = V_16 ;
F_7 ( L_61
L_62
L_63 ,
V_19 -> V_1 , V_19 -> type , ( int ) sizeof( V_19 -> V_14 ) , V_19 -> V_14 ,
V_19 -> V_157 , V_19 -> V_158 ,
V_19 -> V_159 , V_19 -> V_160 , V_19 -> V_39 ,
V_19 -> V_162 , V_19 -> V_163 , V_19 -> V_164 ,
V_19 -> V_165 [ 0 ] , V_19 -> V_165 [ 1 ] , V_19 -> V_165 [ 2 ] , V_19 -> V_165 [ 3 ] ) ;
}
static void F_32 ( const void * V_16 , bool V_17 )
{
const struct V_166 * V_19 = V_16 ;
F_7 ( L_64 , V_19 -> V_1 , V_19 -> V_27 ) ;
}
static void F_33 ( const void * V_16 , bool V_17 )
{
const struct V_167 * V_19 = V_16 ;
F_7 ( L_65 , V_19 -> V_1 , V_19 -> V_168 ) ;
}
static void F_34 ( const void * V_16 , bool V_17 )
{
const struct V_169 * V_19 = V_16 ;
int V_3 ;
F_7 ( L_66 ,
V_19 -> V_170 , V_19 -> V_91 , V_19 -> V_171 ) ;
for ( V_3 = 0 ; V_3 < V_19 -> V_91 ; V_3 ++ ) {
if ( ! V_19 -> V_172 [ V_3 ] . V_173 )
F_7 ( L_67 ,
V_19 -> V_172 [ V_3 ] . V_1 , V_19 -> V_172 [ V_3 ] . V_168 ) ;
else
F_7 ( L_68 ,
V_19 -> V_172 [ V_3 ] . V_1 , V_19 -> V_172 [ V_3 ] . V_173 ) ;
}
F_7 ( L_47 ) ;
}
static void F_35 ( const void * V_16 , bool V_17 )
{
const struct V_174 * V_19 = V_16 ;
F_7 ( L_69
L_70
L_71 ,
F_13 ( V_19 -> type , V_38 ) ,
V_19 -> V_175 . V_58 , V_19 -> V_175 . V_59 ,
V_19 -> V_175 . V_77 , V_19 -> V_175 . V_78 ,
V_19 -> V_176 . V_58 , V_19 -> V_176 . V_59 ,
V_19 -> V_176 . V_77 , V_19 -> V_176 . V_78 ,
V_19 -> V_177 . V_10 , V_19 -> V_177 . V_11 ) ;
}
static void F_36 ( const void * V_16 , bool V_17 )
{
const struct V_178 * V_19 = V_16 ;
F_7 ( L_72 ,
F_13 ( V_19 -> type , V_38 ) ,
V_19 -> V_145 . V_58 , V_19 -> V_145 . V_59 ,
V_19 -> V_145 . V_77 , V_19 -> V_145 . V_78 ) ;
}
static void F_37 ( const void * V_16 , bool V_17 )
{
const struct V_179 * V_19 = V_16 ;
F_7 ( L_73 ,
F_13 ( V_19 -> type , V_38 ) ,
V_19 -> V_180 , V_19 -> V_39 ,
V_19 -> V_181 . V_58 , V_19 -> V_181 . V_59 , V_19 -> V_181 . V_77 , V_19 -> V_181 . V_78 ) ;
}
static void F_38 ( const void * V_16 , bool V_17 )
{
const struct V_182 * V_19 = V_16 ;
F_7 ( L_74
L_75 ,
V_19 -> V_183 , V_19 -> V_184 , V_19 -> V_185 ,
V_19 -> V_186 , V_19 -> V_187 ) ;
}
static void F_39 ( const void * V_16 , bool V_17 )
{
const struct V_188 * V_19 = V_16 ;
F_7 ( L_76 ,
V_19 -> V_189 , V_19 -> V_190 ) ;
}
static void F_40 ( const void * V_16 , bool V_17 )
{
const struct V_191 * V_19 = V_16 ;
F_7 ( L_77 ,
V_19 -> V_192 , V_19 -> V_39 ) ;
}
static void F_41 ( const void * V_16 , bool V_17 )
{
const struct V_193 * V_19 = V_16 ;
F_7 ( L_77 , V_19 -> V_192 , V_19 -> V_39 ) ;
if ( V_19 -> V_192 == V_194 )
F_42 ( L_78 ,
V_19 -> V_90 . V_195 , V_19 -> V_90 . V_142 ) ;
else if ( V_19 -> V_192 == V_196 )
F_42 ( L_79 , V_19 -> V_197 . V_198 ) ;
}
static void F_43 ( const void * V_16 , bool V_17 )
{
const struct V_199 * V_19 = V_16 ;
F_7 ( L_80 , V_19 -> V_200 . type ) ;
if ( V_19 -> V_200 . type == V_201 )
F_7 ( L_81 ,
( int ) sizeof( V_19 -> V_200 . V_14 ) , V_19 -> V_200 . V_14 ) ;
else
F_7 ( L_82 , V_19 -> V_200 . V_202 ) ;
F_7 ( L_83 , ( int ) sizeof( V_19 -> V_14 ) , V_19 -> V_14 ) ;
}
static void F_44 ( const void * V_16 , bool V_17 )
{
const struct V_203 * V_19 = V_16 ;
F_7 ( L_80 , V_19 -> V_200 . type ) ;
if ( V_19 -> V_200 . type == V_201 )
F_7 ( L_81 ,
( int ) sizeof( V_19 -> V_200 . V_14 ) , V_19 -> V_200 . V_14 ) ;
else
F_7 ( L_82 , V_19 -> V_200 . V_202 ) ;
F_7 ( L_84 ,
V_19 -> V_204 , V_19 -> V_205 ) ;
}
static void F_45 ( const void * V_16 , bool V_17 )
{
const struct V_206 * V_19 = V_16 ;
switch ( V_19 -> type ) {
case V_207 :
F_7 ( L_85
L_86
L_87
L_88
L_89
L_90
L_91
L_92 ,
V_19 -> V_208 . V_209 , V_19 -> V_208 . V_210 ,
V_19 -> V_208 . V_58 , V_19 -> V_208 . V_59 ,
V_19 -> V_208 . V_211 , V_19 -> V_208 . V_212 ,
V_19 -> V_208 . V_213 , V_19 -> V_208 . V_214 ,
V_19 -> V_208 . V_215 , V_19 -> V_208 . V_216 ,
V_19 -> V_208 . V_217 , V_19 -> V_208 . V_218 ,
V_19 -> V_208 . V_219 , V_19 -> V_208 . V_220 ,
V_19 -> V_208 . V_4 , V_19 -> V_208 . V_39 ) ;
break;
default:
F_7 ( L_93 , V_19 -> type ) ;
break;
}
}
static void F_46 ( const void * V_16 , bool V_17 )
{
const struct V_221 * V_19 = V_16 ;
F_7 ( L_94 , V_19 -> V_27 ) ;
F_45 ( & V_19 -> V_222 , V_17 ) ;
}
static void F_47 ( const void * V_16 , bool V_17 )
{
const struct V_223 * V_19 = V_16 ;
switch ( V_19 -> type ) {
case V_207 :
F_7 ( L_95
L_96 ,
V_19 -> V_208 . V_224 , V_19 -> V_208 . V_225 ,
V_19 -> V_208 . V_226 , V_19 -> V_208 . V_227 ,
V_19 -> V_208 . V_228 , V_19 -> V_208 . V_229 ,
V_19 -> V_208 . V_4 , V_19 -> V_208 . V_24 ) ;
break;
default:
F_7 ( L_97 , V_19 -> type ) ;
break;
}
}
static void F_48 ( const void * V_16 , bool V_17 )
{
const struct V_230 * V_19 = V_16 ;
F_7 ( L_98 ,
V_19 -> V_27 ,
( V_19 -> V_231 & 0xff ) ,
( V_19 -> V_231 >> 8 ) & 0xff ,
( V_19 -> V_231 >> 16 ) & 0xff ,
( V_19 -> V_231 >> 24 ) & 0xff ,
V_19 -> type ) ;
switch ( V_19 -> type ) {
case V_232 :
F_7 ( L_99 ,
V_19 -> V_233 . V_58 , V_19 -> V_233 . V_59 ) ;
break;
case V_234 :
F_7 ( L_100 ,
V_19 -> V_235 . V_224 , V_19 -> V_235 . V_226 ,
V_19 -> V_235 . V_236 , V_19 -> V_235 . V_237 ,
V_19 -> V_235 . V_225 , V_19 -> V_235 . V_227 ) ;
break;
case V_238 :
default:
F_7 ( L_47 ) ;
break;
}
}
static void F_49 ( const void * V_16 , bool V_17 )
{
const struct V_239 * V_19 = V_16 ;
F_7 ( L_101 ,
V_19 -> V_27 ,
( V_19 -> V_231 & 0xff ) ,
( V_19 -> V_231 >> 8 ) & 0xff ,
( V_19 -> V_231 >> 16 ) & 0xff ,
( V_19 -> V_231 >> 24 ) & 0xff ,
V_19 -> V_58 , V_19 -> V_59 , V_19 -> type ) ;
switch ( V_19 -> type ) {
case V_240 :
F_7 ( L_102 ,
V_19 -> V_233 . V_10 ,
V_19 -> V_233 . V_11 ) ;
break;
case V_241 :
F_7 ( L_103 ,
V_19 -> V_235 . V_242 . V_10 ,
V_19 -> V_235 . V_242 . V_11 ,
V_19 -> V_235 . V_243 . V_10 ,
V_19 -> V_235 . V_243 . V_11 ,
V_19 -> V_235 . V_159 . V_10 ,
V_19 -> V_235 . V_159 . V_11 ) ;
break;
case V_244 :
default:
F_7 ( L_47 ) ;
break;
}
}
static void F_50 ( const void * V_16 , bool V_17 )
{
const struct V_245 * V_19 = V_16 ;
const struct V_246 * V_145 ;
F_7 ( L_104
L_105 ,
V_19 -> type , V_19 -> V_247 , V_19 -> V_126 , V_19 -> V_1 ,
V_19 -> V_123 . V_124 , V_19 -> V_123 . V_248 ) ;
switch ( V_19 -> type ) {
case V_249 :
F_15 ( V_72 L_106 ,
F_13 ( V_19 -> V_250 . V_216 . V_60 , V_61 ) ) ;
break;
case V_251 :
V_145 = & V_19 -> V_250 . V_252 ;
F_15 ( V_72 L_107 ,
V_145 -> V_253 , V_145 -> type ) ;
if ( V_145 -> type == V_254 )
F_7 ( L_108 , V_145 -> V_255 ) ;
else
F_7 ( L_109 , V_145 -> V_168 ) ;
F_7 ( L_110
L_111 ,
V_145 -> V_39 , V_145 -> V_157 , V_145 -> V_158 ,
V_145 -> V_159 , V_145 -> V_160 ) ;
break;
case V_256 :
F_7 ( L_112 ,
V_19 -> V_250 . V_257 . V_258 ) ;
break;
}
}
static void F_51 ( const void * V_16 , bool V_17 )
{
const struct V_259 * V_19 = V_16 ;
F_7 ( L_113 ,
V_19 -> type , V_19 -> V_1 , V_19 -> V_39 ) ;
}
static void F_52 ( const void * V_16 , bool V_17 )
{
const struct V_260 * V_19 = V_16 ;
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
const struct V_261 * V_19 = V_16 ;
F_7 ( L_115
L_116 ,
V_19 -> V_29 , V_19 -> type , V_19 -> V_27 ,
V_19 -> V_35 , V_19 -> V_102 ,
V_19 -> V_103 , V_19 -> V_262 ) ;
}
static void F_54 ( const void * V_16 , bool V_17 )
{
const struct V_263 * V_19 = V_16 ;
F_7 ( L_117 ,
V_19 -> V_264 , V_19 -> V_265 , V_19 -> V_266 ) ;
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
static int F_58 ( struct V_169 * V_145 , int V_267 )
{
V_137 V_3 ;
V_145 -> V_268 [ 0 ] = V_145 -> V_268 [ 1 ] = 0 ;
for ( V_3 = 0 ; V_3 < V_145 -> V_91 ; V_3 ++ )
V_145 -> V_172 [ V_3 ] . V_269 [ 0 ] = 0 ;
if ( ! V_267 && V_145 -> V_170 == V_270 )
return 0 ;
if ( V_145 -> V_170 == 0 )
return 1 ;
for ( V_3 = 0 ; V_3 < V_145 -> V_91 ; V_3 ++ ) {
if ( F_59 ( V_145 -> V_172 [ V_3 ] . V_1 ) != V_145 -> V_170 ) {
V_145 -> V_171 = V_3 ;
return 0 ;
}
}
return 1 ;
}
static int F_60 ( struct V_271 * V_271 , enum V_272 type )
{
struct V_273 * V_274 = F_61 ( V_271 ) ;
const struct V_275 * V_276 = V_274 -> V_277 ;
bool V_278 = V_274 -> V_279 == V_280 ;
bool V_281 = V_274 -> V_279 == V_282 ;
bool V_283 = V_274 -> V_279 == V_284 ;
bool V_285 = V_274 -> V_286 != V_287 ;
bool V_288 = V_274 -> V_286 != V_289 ;
if ( V_276 == NULL )
return - V_290 ;
switch ( type ) {
case V_55 :
if ( V_278 && V_285 &&
( V_276 -> V_291 || V_276 -> V_292 ) )
return 0 ;
break;
case V_68 :
if ( V_278 && V_285 && V_276 -> V_292 )
return 0 ;
break;
case V_74 :
if ( V_278 && V_285 && V_276 -> V_293 )
return 0 ;
break;
case V_56 :
if ( V_278 && V_288 &&
( V_276 -> V_294 || V_276 -> V_295 ) )
return 0 ;
break;
case V_69 :
if ( V_278 && V_288 && V_276 -> V_295 )
return 0 ;
break;
case V_75 :
if ( V_278 && V_288 && V_276 -> V_296 )
return 0 ;
break;
case V_84 :
if ( V_281 && V_285 && V_276 -> V_297 )
return 0 ;
break;
case V_85 :
if ( V_281 && V_288 && V_276 -> V_298 )
return 0 ;
break;
case V_92 :
if ( V_281 && V_285 && V_276 -> V_299 )
return 0 ;
break;
case V_93 :
if ( V_281 && V_288 && V_276 -> V_300 )
return 0 ;
break;
case V_97 :
if ( V_283 && V_285 && V_276 -> V_301 )
return 0 ;
break;
default:
break;
}
return - V_290 ;
}
static void F_62 ( struct V_42 * V_57 )
{
unsigned int V_87 ;
if ( V_57 -> type != V_55 &&
V_57 -> type != V_56 )
return;
if ( V_57 -> V_57 . V_44 . V_302 == V_303 )
return;
V_57 -> V_57 . V_44 . V_302 = V_303 ;
V_87 = F_63 ( struct V_43 , V_302 )
+ sizeof( V_57 -> V_57 . V_44 . V_302 ) ;
memset ( ( ( void * ) & V_57 -> V_57 . V_44 ) + V_87 , 0 ,
sizeof( V_57 -> V_57 . V_44 ) - V_87 ) ;
}
static int F_64 ( const struct V_275 * V_276 ,
struct V_271 * V_271 , void * V_304 , void * V_16 )
{
struct V_18 * V_305 = (struct V_18 * ) V_16 ;
int V_306 ;
V_305 -> V_23 = V_307 ;
V_306 = V_276 -> V_308 ( V_271 , V_304 , V_305 ) ;
V_305 -> V_24 |= V_309 ;
F_65 ( ! ( V_305 -> V_24 & V_310 ) ||
! V_305 -> V_25 ) ;
V_305 -> V_25 |= V_309 ;
return V_306 ;
}
static int F_66 ( const struct V_275 * V_276 ,
struct V_271 * V_271 , void * V_304 , void * V_16 )
{
return V_276 -> V_311 ( V_271 , V_304 , * ( unsigned int * ) V_16 ) ;
}
static int F_67 ( const struct V_275 * V_276 ,
struct V_271 * V_271 , void * V_304 , void * V_16 )
{
return V_276 -> V_312 ( V_271 , V_304 , * ( unsigned int * ) V_16 ) ;
}
static int F_68 ( const struct V_275 * V_276 ,
struct V_271 * V_271 , void * V_304 , void * V_16 )
{
struct V_273 * V_274 ;
T_2 * V_19 = V_16 ;
V_274 = F_61 ( V_271 ) ;
* V_19 = F_69 ( V_274 -> V_313 ) ;
return 0 ;
}
static int F_70 ( const struct V_275 * V_276 ,
struct V_271 * V_271 , void * V_304 , void * V_16 )
{
struct V_273 * V_274 ;
struct V_314 * V_315 ;
T_2 * V_19 = V_16 ;
V_274 = F_61 ( V_271 ) ;
if ( ! F_71 ( V_316 , & V_274 -> V_39 ) )
return - V_317 ;
V_315 = V_271 -> V_318 ;
return F_72 ( V_274 -> V_313 , & V_315 -> V_313 , * V_19 ) ;
}
static int F_73 ( const struct V_275 * V_276 ,
struct V_271 * V_271 , void * V_304 , void * V_16 )
{
struct V_273 * V_274 = F_61 ( V_271 ) ;
struct V_26 * V_19 = V_16 ;
if ( F_74 ( V_274 , V_319 ) )
V_19 -> V_24 |= V_320 ;
return V_276 -> V_321 ( V_271 , V_304 , V_19 ) ;
}
static int F_75 ( const struct V_275 * V_276 ,
struct V_271 * V_271 , void * V_304 , void * V_16 )
{
struct V_273 * V_274 = F_61 ( V_271 ) ;
struct V_31 * V_19 = V_16 ;
if ( F_74 ( V_274 , V_319 ) )
V_19 -> V_24 |= V_322 ;
return V_276 -> V_323 ( V_271 , V_304 , V_19 ) ;
}
static void F_76 ( struct V_37 * V_57 )
{
const unsigned V_324 = sizeof( V_57 -> V_41 ) ;
const char * V_6 = NULL ;
T_2 V_39 = 0 ;
switch ( V_57 -> V_40 ) {
case V_325 : V_6 = L_120 ; break;
case V_326 : V_6 = L_121 ; break;
case V_327 : V_6 = L_122 ; break;
case V_328 : V_6 = L_123 ; break;
case V_329 : V_6 = L_124 ; break;
case V_330 : V_6 = L_125 ; break;
case V_331 : V_6 = L_126 ; break;
case V_332 : V_6 = L_127 ; break;
case V_333 : V_6 = L_128 ; break;
case V_334 : V_6 = L_129 ; break;
case V_335 : V_6 = L_130 ; break;
case V_336 : V_6 = L_131 ; break;
case V_337 : V_6 = L_132 ; break;
case V_338 : V_6 = L_133 ; break;
case V_339 : V_6 = L_134 ; break;
case V_340 : V_6 = L_135 ; break;
case V_341 : V_6 = L_136 ; break;
case V_342 : V_6 = L_137 ; break;
case V_343 : V_6 = L_138 ; break;
case V_344 : V_6 = L_139 ; break;
case V_345 : V_6 = L_140 ; break;
case V_346 : V_6 = L_141 ; break;
case V_347 : V_6 = L_142 ; break;
case V_348 : V_6 = L_143 ; break;
case V_349 : V_6 = L_144 ; break;
case V_350 : V_6 = L_145 ; break;
case V_351 : V_6 = L_146 ; break;
case V_352 : V_6 = L_147 ; break;
case V_353 : V_6 = L_148 ; break;
case V_354 : V_6 = L_149 ; break;
case V_355 : V_6 = L_150 ; break;
case V_356 : V_6 = L_151 ; break;
case V_357 : V_6 = L_152 ; break;
case V_358 : V_6 = L_153 ; break;
case V_359 : V_6 = L_154 ; break;
case V_360 : V_6 = L_155 ; break;
case V_361 : V_6 = L_156 ; break;
case V_362 : V_6 = L_157 ; break;
case V_363 : V_6 = L_158 ; break;
case V_364 : V_6 = L_159 ; break;
case V_365 : V_6 = L_160 ; break;
case V_366 : V_6 = L_161 ; break;
case V_367 : V_6 = L_162 ; break;
case V_368 : V_6 = L_163 ; break;
case V_369 : V_6 = L_164 ; break;
case V_370 : V_6 = L_165 ; break;
case V_371 : V_6 = L_166 ; break;
case V_372 : V_6 = L_167 ; break;
case V_373 : V_6 = L_168 ; break;
case V_374 : V_6 = L_169 ; break;
case V_375 : V_6 = L_170 ; break;
case V_376 : V_6 = L_171 ; break;
case V_377 : V_6 = L_172 ; break;
case V_378 : V_6 = L_173 ; break;
case V_379 : V_6 = L_174 ; break;
case V_380 : V_6 = L_175 ; break;
case V_381 : V_6 = L_176 ; break;
case V_382 : V_6 = L_177 ; break;
case V_383 : V_6 = L_178 ; break;
case V_384 : V_6 = L_179 ; break;
case V_385 : V_6 = L_180 ; break;
case V_386 : V_6 = L_181 ; break;
case V_387 : V_6 = L_182 ; break;
case V_388 : V_6 = L_183 ; break;
case V_389 : V_6 = L_184 ; break;
case V_390 : V_6 = L_185 ; break;
case V_391 : V_6 = L_186 ; break;
case V_392 : V_6 = L_187 ; break;
case V_393 : V_6 = L_188 ; break;
case V_394 : V_6 = L_189 ; break;
case V_395 : V_6 = L_190 ; break;
case V_396 : V_6 = L_191 ; break;
case V_397 : V_6 = L_192 ; break;
case V_398 : V_6 = L_193 ; break;
case V_399 : V_6 = L_194 ; break;
case V_400 : V_6 = L_195 ; break;
case V_401 : V_6 = L_196 ; break;
case V_402 : V_6 = L_197 ; break;
case V_403 : V_6 = L_198 ; break;
case V_404 : V_6 = L_199 ; break;
case V_405 : V_6 = L_200 ; break;
case V_406 : V_6 = L_201 ; break;
case V_407 : V_6 = L_202 ; break;
case V_408 : V_6 = L_203 ; break;
case V_409 : V_6 = L_204 ; break;
case V_410 : V_6 = L_205 ; break;
case V_411 : V_6 = L_206 ; break;
case V_412 : V_6 = L_207 ; break;
case V_413 : V_6 = L_208 ; break;
case V_414 : V_6 = L_209 ; break;
case V_415 : V_6 = L_210 ; break;
case V_416 : V_6 = L_211 ; break;
case V_417 : V_6 = L_212 ; break;
case V_418 : V_6 = L_213 ; break;
case V_419 : V_6 = L_214 ; break;
case V_420 : V_6 = L_215 ; break;
case V_421 : V_6 = L_216 ; break;
case V_422 : V_6 = L_217 ; break;
case V_423 : V_6 = L_218 ; break;
case V_424 : V_6 = L_219 ; break;
case V_425 : V_6 = L_220 ; break;
case V_426 : V_6 = L_221 ; break;
default:
V_39 = V_427 ;
switch ( V_57 -> V_40 ) {
case V_428 : V_6 = L_222 ; break;
case V_429 : V_6 = L_223 ; break;
case V_430 : V_6 = L_224 ; break;
case V_431 : V_6 = L_225 ; break;
case V_432 : V_6 = L_226 ; break;
case V_433 : V_6 = L_227 ; break;
case V_434 : V_6 = L_228 ; break;
case V_435 : V_6 = L_229 ; break;
case V_436 : V_6 = L_230 ; break;
case V_437 : V_6 = L_231 ; break;
case V_438 : V_6 = L_232 ; break;
case V_439 : V_6 = L_233 ; break;
case V_440 : V_6 = L_234 ; break;
case V_441 : V_6 = L_235 ; break;
case V_442 : V_6 = L_236 ; break;
case V_443 : V_6 = L_237 ; break;
case V_444 : V_6 = L_238 ; break;
case V_445 : V_6 = L_239 ; break;
case V_446 : V_6 = L_240 ; break;
case V_447 : V_6 = L_241 ; break;
case V_448 : V_6 = L_242 ; break;
case V_449 : V_6 = L_243 ; break;
case V_450 : V_6 = L_244 ; break;
case V_451 : V_6 = L_245 ; break;
case V_452 : V_6 = L_246 ; break;
case V_453 : V_6 = L_247 ; break;
case V_454 : V_6 = L_248 ; break;
case V_455 : V_6 = L_249 ; break;
case V_456 : V_6 = L_250 ; break;
case V_457 : V_6 = L_251 ; break;
case V_458 : V_6 = L_252 ; break;
case V_459 : V_6 = L_253 ; break;
case V_460 : V_6 = L_254 ; break;
default:
F_77 ( 1 , L_255 , V_57 -> V_40 ) ;
if ( V_57 -> V_41 [ 0 ] )
return;
V_39 = 0 ;
snprintf ( V_57 -> V_41 , V_324 , L_256 ,
( char ) ( V_57 -> V_40 & 0x7f ) ,
( char ) ( ( V_57 -> V_40 >> 8 ) & 0x7f ) ,
( char ) ( ( V_57 -> V_40 >> 16 ) & 0x7f ) ,
( char ) ( ( V_57 -> V_40 >> 24 ) & 0x7f ) ,
( V_57 -> V_40 & ( 1 << 31 ) ) ? L_257 : L_258 ) ;
break;
}
}
if ( V_6 )
F_65 ( F_5 ( V_57 -> V_41 , V_6 , V_324 ) >= V_324 ) ;
V_57 -> V_39 = V_39 ;
}
static int F_78 ( const struct V_275 * V_276 ,
struct V_271 * V_271 , void * V_304 , void * V_16 )
{
struct V_37 * V_19 = V_16 ;
struct V_273 * V_274 = F_61 ( V_271 ) ;
bool V_278 = V_274 -> V_279 == V_280 ;
bool V_283 = V_274 -> V_279 == V_284 ;
bool V_285 = V_274 -> V_286 != V_287 ;
bool V_288 = V_274 -> V_286 != V_289 ;
int V_306 = - V_290 ;
switch ( V_19 -> type ) {
case V_55 :
if ( F_79 ( ! V_285 || ! V_278 || ! V_276 -> V_461 ) )
break;
V_306 = V_276 -> V_461 ( V_271 , V_304 , V_16 ) ;
break;
case V_68 :
if ( F_79 ( ! V_285 || ! V_278 || ! V_276 -> V_462 ) )
break;
V_306 = V_276 -> V_462 ( V_271 , V_304 , V_16 ) ;
break;
case V_74 :
if ( F_79 ( ! V_285 || ! V_278 || ! V_276 -> V_463 ) )
break;
V_306 = V_276 -> V_463 ( V_271 , V_304 , V_16 ) ;
break;
case V_56 :
if ( F_79 ( ! V_288 || ! V_278 || ! V_276 -> V_464 ) )
break;
V_306 = V_276 -> V_464 ( V_271 , V_304 , V_16 ) ;
break;
case V_69 :
if ( F_79 ( ! V_288 || ! V_278 || ! V_276 -> V_465 ) )
break;
V_306 = V_276 -> V_465 ( V_271 , V_304 , V_16 ) ;
break;
case V_97 :
if ( F_79 ( ! V_285 || ! V_283 || ! V_276 -> V_466 ) )
break;
V_306 = V_276 -> V_466 ( V_271 , V_304 , V_16 ) ;
break;
}
if ( V_306 == 0 )
F_76 ( V_19 ) ;
return V_306 ;
}
static int F_80 ( const struct V_275 * V_276 ,
struct V_271 * V_271 , void * V_304 , void * V_16 )
{
struct V_42 * V_19 = V_16 ;
struct V_273 * V_274 = F_61 ( V_271 ) ;
bool V_278 = V_274 -> V_279 == V_280 ;
bool V_283 = V_274 -> V_279 == V_284 ;
bool V_285 = V_274 -> V_286 != V_287 ;
bool V_288 = V_274 -> V_286 != V_289 ;
int V_306 ;
switch ( V_19 -> type ) {
case V_74 :
case V_75 : {
struct V_467 T_3 * V_81 = V_19 -> V_57 . V_52 . V_81 ;
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
if ( F_79 ( ! V_285 || ! V_278 || ! V_276 -> V_291 ) )
break;
V_19 -> V_57 . V_44 . V_302 = V_303 ;
V_306 = V_276 -> V_291 ( V_271 , V_304 , V_16 ) ;
V_19 -> V_57 . V_44 . V_302 = V_303 ;
return V_306 ;
case V_68 :
if ( F_79 ( ! V_285 || ! V_278 || ! V_276 -> V_292 ) )
break;
return V_276 -> V_292 ( V_271 , V_304 , V_16 ) ;
case V_74 :
if ( F_79 ( ! V_285 || ! V_278 || ! V_276 -> V_293 ) )
break;
return V_276 -> V_293 ( V_271 , V_304 , V_16 ) ;
case V_84 :
if ( F_79 ( ! V_285 || V_278 || ! V_276 -> V_297 ) )
break;
return V_276 -> V_297 ( V_271 , V_304 , V_16 ) ;
case V_92 :
if ( F_79 ( ! V_285 || V_278 || ! V_276 -> V_299 ) )
break;
return V_276 -> V_299 ( V_271 , V_304 , V_16 ) ;
case V_56 :
if ( F_79 ( ! V_288 || ! V_278 || ! V_276 -> V_294 ) )
break;
V_19 -> V_57 . V_44 . V_302 = V_303 ;
V_306 = V_276 -> V_294 ( V_271 , V_304 , V_16 ) ;
V_19 -> V_57 . V_44 . V_302 = V_303 ;
return V_306 ;
case V_69 :
if ( F_79 ( ! V_288 || ! V_278 || ! V_276 -> V_295 ) )
break;
return V_276 -> V_295 ( V_271 , V_304 , V_16 ) ;
case V_75 :
if ( F_79 ( ! V_288 || ! V_278 || ! V_276 -> V_296 ) )
break;
return V_276 -> V_296 ( V_271 , V_304 , V_16 ) ;
case V_85 :
if ( F_79 ( ! V_288 || V_278 || ! V_276 -> V_298 ) )
break;
return V_276 -> V_298 ( V_271 , V_304 , V_16 ) ;
case V_93 :
if ( F_79 ( ! V_288 || V_278 || ! V_276 -> V_300 ) )
break;
return V_276 -> V_300 ( V_271 , V_304 , V_16 ) ;
case V_97 :
if ( F_79 ( ! V_285 || ! V_283 || ! V_276 -> V_301 ) )
break;
return V_276 -> V_301 ( V_271 , V_304 , V_16 ) ;
}
return - V_290 ;
}
static int F_81 ( const struct V_275 * V_276 ,
struct V_271 * V_271 , void * V_304 , void * V_16 )
{
struct V_42 * V_19 = V_16 ;
struct V_273 * V_274 = F_61 ( V_271 ) ;
bool V_278 = V_274 -> V_279 == V_280 ;
bool V_283 = V_274 -> V_279 == V_284 ;
bool V_285 = V_274 -> V_286 != V_287 ;
bool V_288 = V_274 -> V_286 != V_289 ;
int V_306 ;
F_62 ( V_19 ) ;
switch ( V_19 -> type ) {
case V_55 :
if ( F_79 ( ! V_285 || ! V_278 || ! V_276 -> V_468 ) )
break;
F_82 ( V_19 , V_57 . V_44 ) ;
V_306 = V_276 -> V_468 ( V_271 , V_304 , V_16 ) ;
V_19 -> V_57 . V_44 . V_302 = V_303 ;
return V_306 ;
case V_68 :
if ( F_79 ( ! V_285 || ! V_278 || ! V_276 -> V_469 ) )
break;
F_82 ( V_19 , V_57 . V_70 ) ;
return V_276 -> V_469 ( V_271 , V_304 , V_16 ) ;
case V_74 :
if ( F_79 ( ! V_285 || ! V_278 || ! V_276 -> V_470 ) )
break;
F_82 ( V_19 , V_57 . V_52 ) ;
return V_276 -> V_470 ( V_271 , V_304 , V_16 ) ;
case V_84 :
if ( F_79 ( ! V_285 || V_278 || ! V_276 -> V_471 ) )
break;
F_82 ( V_19 , V_57 . V_48 ) ;
return V_276 -> V_471 ( V_271 , V_304 , V_16 ) ;
case V_92 :
if ( F_79 ( ! V_285 || V_278 || ! V_276 -> V_472 ) )
break;
F_82 ( V_19 , V_57 . V_50 ) ;
return V_276 -> V_472 ( V_271 , V_304 , V_16 ) ;
case V_56 :
if ( F_79 ( ! V_288 || ! V_278 || ! V_276 -> V_473 ) )
break;
F_82 ( V_19 , V_57 . V_44 ) ;
V_306 = V_276 -> V_473 ( V_271 , V_304 , V_16 ) ;
V_19 -> V_57 . V_44 . V_302 = V_303 ;
return V_306 ;
case V_69 :
if ( F_79 ( ! V_288 || ! V_278 || ! V_276 -> V_474 ) )
break;
F_82 ( V_19 , V_57 . V_70 ) ;
return V_276 -> V_474 ( V_271 , V_304 , V_16 ) ;
case V_75 :
if ( F_79 ( ! V_288 || ! V_278 || ! V_276 -> V_475 ) )
break;
F_82 ( V_19 , V_57 . V_52 ) ;
return V_276 -> V_475 ( V_271 , V_304 , V_16 ) ;
case V_85 :
if ( F_79 ( ! V_288 || V_278 || ! V_276 -> V_476 ) )
break;
F_82 ( V_19 , V_57 . V_48 ) ;
return V_276 -> V_476 ( V_271 , V_304 , V_16 ) ;
case V_93 :
if ( F_79 ( ! V_288 || V_278 || ! V_276 -> V_477 ) )
break;
F_82 ( V_19 , V_57 . V_50 ) ;
return V_276 -> V_477 ( V_271 , V_304 , V_16 ) ;
case V_97 :
if ( F_79 ( ! V_285 || ! V_283 || ! V_276 -> V_478 ) )
break;
F_82 ( V_19 , V_57 . V_54 ) ;
return V_276 -> V_478 ( V_271 , V_304 , V_16 ) ;
}
return - V_290 ;
}
static int F_83 ( const struct V_275 * V_276 ,
struct V_271 * V_271 , void * V_304 , void * V_16 )
{
struct V_42 * V_19 = V_16 ;
struct V_273 * V_274 = F_61 ( V_271 ) ;
bool V_278 = V_274 -> V_279 == V_280 ;
bool V_283 = V_274 -> V_279 == V_284 ;
bool V_285 = V_274 -> V_286 != V_287 ;
bool V_288 = V_274 -> V_286 != V_289 ;
int V_306 ;
F_62 ( V_19 ) ;
switch ( V_19 -> type ) {
case V_55 :
if ( F_79 ( ! V_285 || ! V_278 || ! V_276 -> V_479 ) )
break;
F_82 ( V_19 , V_57 . V_44 ) ;
V_306 = V_276 -> V_479 ( V_271 , V_304 , V_16 ) ;
V_19 -> V_57 . V_44 . V_302 = V_303 ;
return V_306 ;
case V_68 :
if ( F_79 ( ! V_285 || ! V_278 || ! V_276 -> V_480 ) )
break;
F_82 ( V_19 , V_57 . V_70 ) ;
return V_276 -> V_480 ( V_271 , V_304 , V_16 ) ;
case V_74 :
if ( F_79 ( ! V_285 || ! V_278 || ! V_276 -> V_481 ) )
break;
F_82 ( V_19 , V_57 . V_52 ) ;
return V_276 -> V_481 ( V_271 , V_304 , V_16 ) ;
case V_84 :
if ( F_79 ( ! V_285 || V_278 || ! V_276 -> V_482 ) )
break;
F_82 ( V_19 , V_57 . V_48 ) ;
return V_276 -> V_482 ( V_271 , V_304 , V_16 ) ;
case V_92 :
if ( F_79 ( ! V_285 || V_278 || ! V_276 -> V_483 ) )
break;
F_82 ( V_19 , V_57 . V_50 ) ;
return V_276 -> V_483 ( V_271 , V_304 , V_16 ) ;
case V_56 :
if ( F_79 ( ! V_288 || ! V_278 || ! V_276 -> V_484 ) )
break;
F_82 ( V_19 , V_57 . V_44 ) ;
V_306 = V_276 -> V_484 ( V_271 , V_304 , V_16 ) ;
V_19 -> V_57 . V_44 . V_302 = V_303 ;
return V_306 ;
case V_69 :
if ( F_79 ( ! V_288 || ! V_278 || ! V_276 -> V_485 ) )
break;
F_82 ( V_19 , V_57 . V_70 ) ;
return V_276 -> V_485 ( V_271 , V_304 , V_16 ) ;
case V_75 :
if ( F_79 ( ! V_288 || ! V_278 || ! V_276 -> V_486 ) )
break;
F_82 ( V_19 , V_57 . V_52 ) ;
return V_276 -> V_486 ( V_271 , V_304 , V_16 ) ;
case V_85 :
if ( F_79 ( ! V_288 || V_278 || ! V_276 -> V_487 ) )
break;
F_82 ( V_19 , V_57 . V_48 ) ;
return V_276 -> V_487 ( V_271 , V_304 , V_16 ) ;
case V_93 :
if ( F_79 ( ! V_288 || V_278 || ! V_276 -> V_488 ) )
break;
F_82 ( V_19 , V_57 . V_50 ) ;
return V_276 -> V_488 ( V_271 , V_304 , V_16 ) ;
case V_97 :
if ( F_79 ( ! V_285 || ! V_283 || ! V_276 -> V_489 ) )
break;
F_82 ( V_19 , V_57 . V_54 ) ;
return V_276 -> V_489 ( V_271 , V_304 , V_16 ) ;
}
return - V_290 ;
}
static int F_84 ( const struct V_275 * V_276 ,
struct V_271 * V_271 , void * V_304 , void * V_16 )
{
return V_276 -> V_490 ( V_271 , V_304 , * ( unsigned int * ) V_16 ) ;
}
static int F_85 ( const struct V_275 * V_276 ,
struct V_271 * V_271 , void * V_304 , void * V_16 )
{
return V_276 -> V_491 ( V_271 , V_304 , * ( unsigned int * ) V_16 ) ;
}
static int F_86 ( const struct V_275 * V_276 ,
struct V_271 * V_271 , void * V_304 , void * V_16 )
{
struct V_273 * V_274 = F_61 ( V_271 ) ;
struct V_104 * V_19 = V_16 ;
int V_492 ;
V_19 -> type = ( V_274 -> V_279 == V_493 ) ?
V_494 : V_495 ;
V_492 = V_276 -> V_496 ( V_271 , V_304 , V_19 ) ;
if ( ! V_492 )
V_19 -> V_35 |= V_497 ;
return V_492 ;
}
static int F_87 ( const struct V_275 * V_276 ,
struct V_271 * V_271 , void * V_304 , void * V_16 )
{
struct V_273 * V_274 = F_61 ( V_271 ) ;
struct V_104 * V_19 = V_16 ;
V_19 -> type = ( V_274 -> V_279 == V_493 ) ?
V_494 : V_495 ;
return V_276 -> V_498 ( V_271 , V_304 , V_19 ) ;
}
static int F_88 ( const struct V_275 * V_276 ,
struct V_271 * V_271 , void * V_304 , void * V_16 )
{
struct V_100 * V_19 = V_16 ;
int V_492 ;
V_492 = V_276 -> V_499 ( V_271 , V_304 , V_19 ) ;
if ( ! V_492 )
V_19 -> V_35 |= V_497 ;
return V_492 ;
}
static int F_89 ( const struct V_275 * V_276 ,
struct V_271 * V_271 , void * V_304 , void * V_16 )
{
struct V_273 * V_274 = F_61 ( V_271 ) ;
struct V_108 * V_19 = V_16 ;
if ( V_274 -> V_279 == V_284 )
V_19 -> type = V_500 ;
else
V_19 -> type = ( V_274 -> V_279 == V_493 ) ?
V_494 : V_495 ;
return V_276 -> V_501 ( V_271 , V_304 , V_19 ) ;
}
static int F_90 ( const struct V_275 * V_276 ,
struct V_271 * V_271 , void * V_304 , void * V_16 )
{
struct V_273 * V_274 = F_61 ( V_271 ) ;
const struct V_108 * V_19 = V_16 ;
enum V_502 type ;
if ( V_274 -> V_279 == V_284 ) {
if ( V_19 -> type != V_500 && V_19 -> type != V_503 )
return - V_290 ;
} else {
type = ( V_274 -> V_279 == V_493 ) ?
V_494 : V_495 ;
if ( type != V_19 -> type )
return - V_290 ;
}
return V_276 -> V_504 ( V_271 , V_304 , V_19 ) ;
}
static int F_91 ( const struct V_275 * V_276 ,
struct V_271 * V_271 , void * V_304 , void * V_16 )
{
struct V_273 * V_274 = F_61 ( V_271 ) ;
struct V_12 * V_19 = V_16 ;
T_1 V_1 = V_274 -> V_505 , V_506 = 0 ;
unsigned int V_27 = V_19 -> V_27 , V_3 , V_507 = 0 ;
const char * V_6 = L_258 ;
if ( V_1 == 0 )
return - V_508 ;
for ( V_3 = 0 ; V_3 <= V_27 && V_1 ; V_3 ++ ) {
while ( ( V_1 & V_4 [ V_507 ] . V_5 ) != V_4 [ V_507 ] . V_5 )
V_507 ++ ;
V_506 = V_4 [ V_507 ] . V_5 ;
V_6 = V_4 [ V_507 ] . V_6 ;
V_507 ++ ;
if ( V_506 == 0 )
break;
if ( V_506 != V_509 &&
V_506 != V_510 &&
V_506 != V_511 )
V_1 &= ~ V_506 ;
}
if ( V_3 <= V_27 )
return - V_290 ;
F_4 ( V_19 , V_506 , V_6 ) ;
return 0 ;
}
static int F_92 ( const struct V_275 * V_276 ,
struct V_271 * V_271 , void * V_304 , void * V_16 )
{
struct V_273 * V_274 = F_61 ( V_271 ) ;
T_1 V_1 = * ( T_1 * ) V_16 , V_512 ;
V_512 = V_1 & V_274 -> V_505 ;
if ( V_274 -> V_505 && ! V_512 )
return - V_290 ;
return V_276 -> V_513 ( V_271 , V_304 , V_512 ) ;
}
static int F_93 ( const struct V_275 * V_276 ,
struct V_271 * V_271 , void * V_304 , void * V_16 )
{
struct V_273 * V_274 = F_61 ( V_271 ) ;
T_1 * V_19 = V_16 ;
* V_19 = V_274 -> V_505 ;
return V_276 -> V_514 ( V_271 , V_304 , V_16 ) ;
}
static int F_94 ( const struct V_275 * V_276 ,
struct V_271 * V_271 , void * V_304 , void * V_16 )
{
struct V_273 * V_274 = F_61 ( V_271 ) ;
struct V_110 * V_19 = V_16 ;
enum V_502 type ;
if ( V_274 -> V_279 == V_284 )
return - V_290 ;
type = ( V_274 -> V_279 == V_493 ) ?
V_494 : V_495 ;
if ( V_19 -> type != type )
return - V_290 ;
return V_276 -> V_515 ( V_271 , V_304 , V_19 ) ;
}
static int F_95 ( const struct V_275 * V_276 ,
struct V_271 * V_271 , void * V_304 , void * V_16 )
{
return V_276 -> V_516 ( V_271 , V_304 , * ( unsigned int * ) V_16 ) ;
}
static int F_96 ( const struct V_275 * V_276 ,
struct V_271 * V_271 , void * V_304 , void * V_16 )
{
struct V_114 * V_19 = V_16 ;
int V_306 = F_60 ( V_271 , V_19 -> type ) ;
if ( V_306 )
return V_306 ;
F_82 ( V_19 , V_115 ) ;
return V_276 -> V_517 ( V_271 , V_304 , V_19 ) ;
}
static int F_97 ( const struct V_275 * V_276 ,
struct V_271 * V_271 , void * V_304 , void * V_16 )
{
struct V_117 * V_19 = V_16 ;
int V_306 = F_60 ( V_271 , V_19 -> type ) ;
return V_306 ? V_306 : V_276 -> V_518 ( V_271 , V_304 , V_19 ) ;
}
static int F_98 ( const struct V_275 * V_276 ,
struct V_271 * V_271 , void * V_304 , void * V_16 )
{
struct V_117 * V_19 = V_16 ;
int V_306 = F_60 ( V_271 , V_19 -> type ) ;
return V_306 ? V_306 : V_276 -> V_519 ( V_271 , V_304 , V_19 ) ;
}
static int F_99 ( const struct V_275 * V_276 ,
struct V_271 * V_271 , void * V_304 , void * V_16 )
{
struct V_117 * V_19 = V_16 ;
int V_306 = F_60 ( V_271 , V_19 -> type ) ;
return V_306 ? V_306 : V_276 -> V_520 ( V_271 , V_304 , V_19 ) ;
}
static int F_100 ( const struct V_275 * V_276 ,
struct V_271 * V_271 , void * V_304 , void * V_16 )
{
struct V_141 * V_521 = V_16 ;
int V_306 = F_60 ( V_271 , V_521 -> V_142 . type ) ;
if ( V_306 )
return V_306 ;
F_82 ( V_521 , V_142 ) ;
F_62 ( & V_521 -> V_142 ) ;
V_306 = V_276 -> V_522 ( V_271 , V_304 , V_521 ) ;
if ( V_521 -> V_142 . type == V_55 ||
V_521 -> V_142 . type == V_56 )
V_521 -> V_142 . V_57 . V_44 . V_302 = V_303 ;
return V_306 ;
}
static int F_101 ( const struct V_275 * V_276 ,
struct V_271 * V_271 , void * V_304 , void * V_16 )
{
struct V_117 * V_523 = V_16 ;
int V_306 = F_60 ( V_271 , V_523 -> type ) ;
return V_306 ? V_306 : V_276 -> V_524 ( V_271 , V_304 , V_523 ) ;
}
static int F_102 ( const struct V_275 * V_276 ,
struct V_271 * V_271 , void * V_304 , void * V_16 )
{
struct V_143 * V_19 = V_16 ;
T_1 V_5 ;
int V_306 = F_60 ( V_271 , V_19 -> type ) ;
if ( V_306 )
return V_306 ;
if ( V_276 -> V_525 )
return V_276 -> V_525 ( V_271 , V_304 , V_19 ) ;
if ( V_19 -> type != V_55 &&
V_19 -> type != V_68 )
return - V_290 ;
V_19 -> V_146 . V_147 . V_151 = 2 ;
V_306 = V_276 -> V_526 ( V_271 , V_304 , & V_5 ) ;
if ( V_306 == 0 )
F_3 ( V_5 , & V_19 -> V_146 . V_147 . V_149 ) ;
return V_306 ;
}
static int F_103 ( const struct V_275 * V_276 ,
struct V_271 * V_271 , void * V_304 , void * V_16 )
{
struct V_143 * V_19 = V_16 ;
int V_306 = F_60 ( V_271 , V_19 -> type ) ;
return V_306 ? V_306 : V_276 -> V_527 ( V_271 , V_304 , V_19 ) ;
}
static int F_104 ( const struct V_275 * V_276 ,
struct V_271 * V_271 , void * V_304 , void * V_16 )
{
struct V_273 * V_274 = F_61 ( V_271 ) ;
struct V_156 * V_19 = V_16 ;
struct V_314 * V_315 =
F_71 ( V_316 , & V_274 -> V_39 ) ? V_304 : NULL ;
if ( V_315 && V_315 -> V_528 )
return V_156 ( V_315 -> V_528 , V_19 ) ;
if ( V_274 -> V_528 )
return V_156 ( V_274 -> V_528 , V_19 ) ;
if ( V_276 -> V_529 )
return V_276 -> V_529 ( V_271 , V_304 , V_19 ) ;
return - V_317 ;
}
static int F_105 ( const struct V_275 * V_276 ,
struct V_271 * V_271 , void * V_304 , void * V_16 )
{
struct V_273 * V_274 = F_61 ( V_271 ) ;
struct V_161 * V_19 = V_16 ;
struct V_314 * V_315 =
F_71 ( V_316 , & V_274 -> V_39 ) ? V_304 : NULL ;
if ( V_315 && V_315 -> V_528 )
return V_161 ( V_315 -> V_528 , V_19 ) ;
if ( V_274 -> V_528 )
return V_161 ( V_274 -> V_528 , V_19 ) ;
if ( V_276 -> V_530 )
return V_276 -> V_530 ( V_271 , V_304 , V_19 ) ;
return - V_317 ;
}
static int F_106 ( const struct V_275 * V_276 ,
struct V_271 * V_271 , void * V_304 , void * V_16 )
{
struct V_273 * V_274 = F_61 ( V_271 ) ;
struct V_166 * V_19 = V_16 ;
struct V_314 * V_315 =
F_71 ( V_316 , & V_274 -> V_39 ) ? V_304 : NULL ;
if ( V_315 && V_315 -> V_528 )
return V_166 ( V_315 -> V_528 , V_19 ) ;
if ( V_274 -> V_528 )
return V_166 ( V_274 -> V_528 , V_19 ) ;
if ( V_276 -> V_531 )
return V_276 -> V_531 ( V_271 , V_304 , V_19 ) ;
return - V_317 ;
}
static int F_107 ( const struct V_275 * V_276 ,
struct V_271 * V_271 , void * V_304 , void * V_16 )
{
struct V_273 * V_274 = F_61 ( V_271 ) ;
struct V_167 * V_19 = V_16 ;
struct V_314 * V_315 =
F_71 ( V_316 , & V_274 -> V_39 ) ? V_304 : NULL ;
struct V_169 V_532 ;
struct V_533 V_252 ;
if ( V_315 && V_315 -> V_528 )
return F_108 ( V_315 -> V_528 , V_19 ) ;
if ( V_274 -> V_528 )
return F_108 ( V_274 -> V_528 , V_19 ) ;
if ( V_276 -> V_534 )
return V_276 -> V_534 ( V_271 , V_304 , V_19 ) ;
if ( V_276 -> V_535 == NULL )
return - V_317 ;
V_532 . V_170 = F_59 ( V_19 -> V_1 ) ;
V_532 . V_91 = 1 ;
V_532 . V_172 = & V_252 ;
V_252 . V_1 = V_19 -> V_1 ;
V_252 . V_168 = V_19 -> V_168 ;
if ( F_58 ( & V_532 , 1 ) ) {
int V_306 = V_276 -> V_535 ( V_271 , V_304 , & V_532 ) ;
if ( V_306 == 0 )
V_19 -> V_168 = V_252 . V_168 ;
return V_306 ;
}
return - V_290 ;
}
static int F_109 ( const struct V_275 * V_276 ,
struct V_271 * V_271 , void * V_304 , void * V_16 )
{
struct V_273 * V_274 = F_61 ( V_271 ) ;
struct V_167 * V_19 = V_16 ;
struct V_314 * V_315 =
F_71 ( V_316 , & V_274 -> V_39 ) ? V_304 : NULL ;
struct V_169 V_532 ;
struct V_533 V_252 ;
if ( V_315 && V_315 -> V_528 )
return F_110 ( V_315 , V_315 -> V_528 , V_19 ) ;
if ( V_274 -> V_528 )
return F_110 ( NULL , V_274 -> V_528 , V_19 ) ;
if ( V_276 -> V_536 )
return V_276 -> V_536 ( V_271 , V_304 , V_19 ) ;
if ( V_276 -> V_537 == NULL )
return - V_317 ;
V_532 . V_170 = F_59 ( V_19 -> V_1 ) ;
V_532 . V_91 = 1 ;
V_532 . V_172 = & V_252 ;
V_252 . V_1 = V_19 -> V_1 ;
V_252 . V_168 = V_19 -> V_168 ;
if ( F_58 ( & V_532 , 1 ) )
return V_276 -> V_537 ( V_271 , V_304 , & V_532 ) ;
return - V_290 ;
}
static int F_111 ( const struct V_275 * V_276 ,
struct V_271 * V_271 , void * V_304 , void * V_16 )
{
struct V_273 * V_274 = F_61 ( V_271 ) ;
struct V_169 * V_19 = V_16 ;
struct V_314 * V_315 =
F_71 ( V_316 , & V_274 -> V_39 ) ? V_304 : NULL ;
V_19 -> V_171 = V_19 -> V_91 ;
if ( V_315 && V_315 -> V_528 )
return F_112 ( V_315 -> V_528 , V_19 ) ;
if ( V_274 -> V_528 )
return F_112 ( V_274 -> V_528 , V_19 ) ;
if ( V_276 -> V_535 == NULL )
return - V_317 ;
return F_58 ( V_19 , 0 ) ? V_276 -> V_535 ( V_271 , V_304 , V_19 ) :
- V_290 ;
}
static int F_113 ( const struct V_275 * V_276 ,
struct V_271 * V_271 , void * V_304 , void * V_16 )
{
struct V_273 * V_274 = F_61 ( V_271 ) ;
struct V_169 * V_19 = V_16 ;
struct V_314 * V_315 =
F_71 ( V_316 , & V_274 -> V_39 ) ? V_304 : NULL ;
V_19 -> V_171 = V_19 -> V_91 ;
if ( V_315 && V_315 -> V_528 )
return F_114 ( V_315 , V_315 -> V_528 , V_19 ) ;
if ( V_274 -> V_528 )
return F_114 ( NULL , V_274 -> V_528 , V_19 ) ;
if ( V_276 -> V_537 == NULL )
return - V_317 ;
return F_58 ( V_19 , 0 ) ? V_276 -> V_537 ( V_271 , V_304 , V_19 ) :
- V_290 ;
}
static int F_115 ( const struct V_275 * V_276 ,
struct V_271 * V_271 , void * V_304 , void * V_16 )
{
struct V_273 * V_274 = F_61 ( V_271 ) ;
struct V_169 * V_19 = V_16 ;
struct V_314 * V_315 =
F_71 ( V_316 , & V_274 -> V_39 ) ? V_304 : NULL ;
V_19 -> V_171 = V_19 -> V_91 ;
if ( V_315 && V_315 -> V_528 )
return F_116 ( V_315 -> V_528 , V_19 ) ;
if ( V_274 -> V_528 )
return F_116 ( V_274 -> V_528 , V_19 ) ;
if ( V_276 -> V_538 == NULL )
return - V_317 ;
return F_58 ( V_19 , 0 ) ? V_276 -> V_538 ( V_271 , V_304 , V_19 ) :
- V_290 ;
}
static int F_117 ( const struct V_275 * V_276 ,
struct V_271 * V_271 , void * V_304 , void * V_16 )
{
struct V_178 * V_19 = V_16 ;
struct V_179 V_539 = {
. type = V_19 -> type ,
} ;
int V_306 ;
if ( V_276 -> V_540 )
return V_276 -> V_540 ( V_271 , V_304 , V_19 ) ;
if ( F_118 ( V_19 -> type ) )
V_539 . V_180 = V_541 ;
else
V_539 . V_180 = V_542 ;
V_306 = V_276 -> V_543 ( V_271 , V_304 , & V_539 ) ;
if ( ! V_306 )
V_19 -> V_145 = V_539 . V_181 ;
return V_306 ;
}
static int F_119 ( const struct V_275 * V_276 ,
struct V_271 * V_271 , void * V_304 , void * V_16 )
{
struct V_178 * V_19 = V_16 ;
struct V_179 V_539 = {
. type = V_19 -> type ,
. V_181 = V_19 -> V_145 ,
} ;
if ( V_276 -> V_544 )
return V_276 -> V_544 ( V_271 , V_304 , V_19 ) ;
if ( F_118 ( V_19 -> type ) )
V_539 . V_180 = V_541 ;
else
V_539 . V_180 = V_542 ;
return V_276 -> V_545 ( V_271 , V_304 , & V_539 ) ;
}
static int F_120 ( const struct V_275 * V_276 ,
struct V_271 * V_271 , void * V_304 , void * V_16 )
{
struct V_174 * V_19 = V_16 ;
if ( V_276 -> V_543 ) {
struct V_179 V_539 = { . type = V_19 -> type } ;
int V_306 ;
if ( F_118 ( V_19 -> type ) )
V_539 . V_180 = V_546 ;
else
V_539 . V_180 = V_547 ;
V_306 = V_276 -> V_543 ( V_271 , V_304 , & V_539 ) ;
if ( V_306 )
return V_306 ;
V_19 -> V_175 = V_539 . V_181 ;
if ( F_118 ( V_19 -> type ) )
V_539 . V_180 = V_548 ;
else
V_539 . V_180 = V_549 ;
V_306 = V_276 -> V_543 ( V_271 , V_304 , & V_539 ) ;
if ( V_306 )
return V_306 ;
V_19 -> V_176 = V_539 . V_181 ;
}
V_19 -> V_177 . V_10 = 1 ;
V_19 -> V_177 . V_11 = 1 ;
if ( V_276 -> V_550 )
return V_276 -> V_550 ( V_271 , V_304 , V_19 ) ;
return 0 ;
}
static int F_121 ( const struct V_275 * V_276 ,
struct V_271 * V_271 , void * V_304 , void * V_16 )
{
struct V_273 * V_274 = F_61 ( V_271 ) ;
int V_306 ;
if ( V_274 -> V_551 )
F_42 ( L_259 ,
V_274 -> V_551 -> V_14 ) ;
V_306 = V_276 -> V_552 ( V_271 , V_304 ) ;
if ( V_274 -> V_551 )
F_42 ( L_260 ,
V_274 -> V_551 -> V_14 ) ;
return V_306 ;
}
static int F_122 ( const struct V_275 * V_276 ,
struct V_271 * V_271 , void * V_304 , void * V_16 )
{
#ifdef F_123
struct V_203 * V_19 = V_16 ;
struct V_273 * V_274 = F_61 ( V_271 ) ;
struct V_553 * V_554 ;
int V_555 = 0 ;
if ( ! F_124 ( V_556 ) )
return - V_557 ;
if ( V_19 -> V_200 . type == V_558 ) {
if ( V_274 -> V_551 == NULL )
return - V_290 ;
F_125 (sd, vfd->v4l2_dev)
if ( V_19 -> V_200 . V_202 == V_555 ++ )
return F_126 ( V_554 , V_559 , V_560 , V_19 ) ;
return - V_290 ;
}
if ( V_276 -> V_561 && V_19 -> V_200 . type == V_562 &&
( V_276 -> V_563 || V_19 -> V_200 . V_202 == 0 ) )
return V_276 -> V_561 ( V_271 , V_304 , V_19 ) ;
return - V_290 ;
#else
return - V_317 ;
#endif
}
static int F_127 ( const struct V_275 * V_276 ,
struct V_271 * V_271 , void * V_304 , void * V_16 )
{
#ifdef F_123
const struct V_203 * V_19 = V_16 ;
struct V_273 * V_274 = F_61 ( V_271 ) ;
struct V_553 * V_554 ;
int V_555 = 0 ;
if ( ! F_124 ( V_556 ) )
return - V_557 ;
if ( V_19 -> V_200 . type == V_558 ) {
if ( V_274 -> V_551 == NULL )
return - V_290 ;
F_125 (sd, vfd->v4l2_dev)
if ( V_19 -> V_200 . V_202 == V_555 ++ )
return F_126 ( V_554 , V_559 , V_564 , V_19 ) ;
return - V_290 ;
}
if ( V_276 -> V_565 && V_19 -> V_200 . type == V_562 &&
( V_276 -> V_563 || V_19 -> V_200 . V_202 == 0 ) )
return V_276 -> V_565 ( V_271 , V_304 , V_19 ) ;
return - V_290 ;
#else
return - V_317 ;
#endif
}
static int F_128 ( const struct V_275 * V_276 ,
struct V_271 * V_271 , void * V_304 , void * V_16 )
{
#ifdef F_123
struct V_273 * V_274 = F_61 ( V_271 ) ;
struct V_199 * V_19 = V_16 ;
struct V_553 * V_554 ;
int V_555 = 0 ;
switch ( V_19 -> V_200 . type ) {
case V_562 :
if ( V_276 -> V_565 )
V_19 -> V_39 |= V_566 ;
if ( V_276 -> V_561 )
V_19 -> V_39 |= V_567 ;
F_5 ( V_19 -> V_14 , V_274 -> V_551 -> V_14 , sizeof( V_19 -> V_14 ) ) ;
if ( V_276 -> V_563 )
return V_276 -> V_563 ( V_271 , V_304 , V_16 ) ;
if ( V_19 -> V_200 . V_202 )
return - V_290 ;
return 0 ;
case V_558 :
if ( V_274 -> V_551 == NULL )
break;
F_125 (sd, vfd->v4l2_dev) {
if ( V_19 -> V_200 . V_202 != V_555 ++ )
continue;
if ( V_554 -> V_276 -> V_559 && V_554 -> V_276 -> V_559 -> V_564 )
V_19 -> V_39 |= V_566 ;
if ( V_554 -> V_276 -> V_559 && V_554 -> V_276 -> V_559 -> V_560 )
V_19 -> V_39 |= V_567 ;
F_5 ( V_19 -> V_14 , V_554 -> V_14 , sizeof( V_19 -> V_14 ) ) ;
return 0 ;
}
break;
}
return - V_290 ;
#else
return - V_317 ;
#endif
}
static int F_129 ( const struct V_275 * V_276 ,
struct V_271 * V_271 , void * V_304 , void * V_16 )
{
return F_130 ( V_304 , V_16 , V_271 -> V_568 & V_569 ) ;
}
static int F_131 ( const struct V_275 * V_276 ,
struct V_271 * V_271 , void * V_304 , void * V_16 )
{
return V_276 -> V_570 ( V_304 , V_16 ) ;
}
static int F_132 ( const struct V_275 * V_276 ,
struct V_271 * V_271 , void * V_304 , void * V_16 )
{
return V_276 -> V_571 ( V_304 , V_16 ) ;
}
static int F_133 ( const struct V_275 * V_276 ,
struct V_271 * V_271 , void * V_304 , void * V_16 )
{
struct V_260 * V_19 = V_16 ;
int V_306 = F_60 ( V_271 , V_19 -> type ) ;
if ( V_306 )
return V_306 ;
memset ( V_19 , 0 , F_63 ( struct V_260 , type ) ) ;
return V_276 -> V_572 ( V_271 , V_304 , V_19 ) ;
}
static int F_134 ( const struct V_275 * V_276 ,
struct V_271 * V_271 , void * V_304 , void * V_16 )
{
struct V_273 * V_274 = F_61 ( V_271 ) ;
struct V_261 * V_19 = V_16 ;
enum V_502 type ;
int V_492 ;
if ( V_274 -> V_279 == V_284 ) {
if ( V_19 -> type != V_500 && V_19 -> type != V_503 )
return - V_290 ;
type = V_19 -> type ;
} else {
type = ( V_274 -> V_279 == V_493 ) ?
V_494 : V_495 ;
if ( type != V_19 -> type )
return - V_290 ;
}
if ( V_276 -> V_573 ) {
V_492 = V_276 -> V_573 ( V_271 , V_304 , V_19 ) ;
if ( V_492 != - V_317 )
return V_492 ;
}
if ( F_74 ( V_274 , V_574 ) ) {
struct V_104 V_575 = {
. V_27 = V_19 -> V_29 ,
. type = type ,
} ;
if ( V_19 -> V_27 )
return - V_290 ;
V_492 = V_276 -> V_496 ( V_271 , V_304 , & V_575 ) ;
if ( V_492 )
return V_492 ;
V_19 -> V_35 = V_575 . V_35 | V_497 ;
V_19 -> V_102 = V_575 . V_102 ;
V_19 -> V_103 = V_575 . V_103 ;
V_19 -> V_262 = ( type == V_494 ) ?
V_576 : V_577 ;
return 0 ;
}
if ( F_74 ( V_274 , V_578 ) ) {
struct V_100 V_127 = {
. V_27 = V_19 -> V_29 ,
} ;
if ( type != V_494 )
return - V_290 ;
if ( V_19 -> V_27 )
return - V_290 ;
V_492 = V_276 -> V_499 ( V_271 , V_304 , & V_127 ) ;
if ( V_492 )
return V_492 ;
V_19 -> V_35 = V_127 . V_35 | V_497 ;
V_19 -> V_102 = V_127 . V_102 ;
V_19 -> V_103 = V_127 . V_103 ;
V_19 -> V_262 = ( type == V_494 ) ?
V_576 : V_577 ;
return 0 ;
}
return - V_317 ;
}
bool F_135 ( unsigned int V_192 )
{
if ( F_136 ( V_192 ) >= V_579 )
return false ;
return V_580 [ F_136 ( V_192 ) ] . V_581 == V_192 ;
}
struct V_582 * F_137 ( struct V_273 * V_583 , unsigned V_192 )
{
if ( F_136 ( V_192 ) >= V_579 )
return V_583 -> V_584 ;
if ( F_71 ( F_136 ( V_192 ) , V_583 -> V_585 ) )
return NULL ;
if ( V_583 -> V_586 && V_583 -> V_586 -> V_584 &&
( V_580 [ F_136 ( V_192 ) ] . V_39 & V_587 ) )
return V_583 -> V_586 -> V_584 ;
return V_583 -> V_584 ;
}
void F_138 ( const char * V_588 , unsigned int V_192 )
{
const char * V_589 , * type ;
if ( V_588 )
F_15 ( V_72 L_261 , V_588 ) ;
switch ( F_139 ( V_192 ) ) {
case 'd' :
type = L_262 ;
break;
case 'V' :
if ( F_136 ( V_192 ) >= V_579 ) {
type = L_263 ;
break;
}
F_7 ( L_264 , V_580 [ F_136 ( V_192 ) ] . V_14 ) ;
return;
default:
type = L_265 ;
break;
}
switch ( F_140 ( V_192 ) ) {
case V_590 : V_589 = L_266 ; break;
case V_591 : V_589 = L_267 ; break;
case V_592 : V_589 = L_268 ; break;
case V_591 | V_592 : V_589 = L_269 ; break;
default: V_589 = L_270 ; break;
}
F_7 ( L_271 ,
type , F_139 ( V_192 ) , V_589 , F_136 ( V_192 ) , V_192 ) ;
}
static long F_141 ( struct V_271 * V_271 ,
unsigned int V_192 , void * V_16 )
{
struct V_273 * V_274 = F_61 ( V_271 ) ;
const struct V_275 * V_276 = V_274 -> V_277 ;
bool V_17 = false ;
struct V_593 V_594 ;
const struct V_593 * V_595 ;
void * V_304 = V_271 -> V_318 ;
struct V_314 * V_315 = NULL ;
int V_596 = V_274 -> V_596 ;
long V_306 = - V_317 ;
if ( V_276 == NULL ) {
F_142 ( L_272 ,
F_143 ( V_274 ) ) ;
return V_306 ;
}
if ( F_71 ( V_316 , & V_274 -> V_39 ) )
V_315 = V_271 -> V_318 ;
if ( F_135 ( V_192 ) ) {
V_595 = & V_580 [ F_136 ( V_192 ) ] ;
if ( ! F_71 ( F_136 ( V_192 ) , V_274 -> V_597 ) &&
! ( ( V_595 -> V_39 & V_598 ) && V_315 && V_315 -> V_528 ) )
goto V_599;
if ( V_315 && ( V_595 -> V_39 & V_600 ) ) {
V_306 = F_144 ( V_274 -> V_313 , V_315 -> V_313 ) ;
if ( V_306 )
goto V_599;
}
} else {
V_594 . V_581 = V_192 ;
V_594 . V_39 = 0 ;
V_594 . V_601 = F_57 ;
V_595 = & V_594 ;
}
V_17 = F_140 ( V_192 ) == V_592 ;
if ( V_595 -> V_39 & V_602 ) {
typedef int (* F_145)( struct V_271 * V_271 , void * V_304 , void * V_19 );
const void * V_19 = V_274 -> V_277 ;
const F_145 * V_603 = V_19 + V_595 -> V_250 . V_87 ;
V_306 = (* V_603)( V_271 , V_304 , V_16 ) ;
} else if ( V_595 -> V_39 & V_604 ) {
V_306 = V_595 -> V_250 . V_605 ( V_276 , V_271 , V_304 , V_16 ) ;
} else if ( ! V_276 -> V_606 ) {
V_306 = - V_317 ;
} else {
V_306 = V_276 -> V_606 ( V_271 , V_304 ,
V_315 ? F_144 ( V_274 -> V_313 , V_315 -> V_313 ) >= 0 : 0 ,
V_192 , V_16 ) ;
}
V_599:
if ( V_596 & ( V_607 | V_608 ) ) {
if ( ! ( V_596 & V_609 ) &&
( V_192 == V_610 || V_192 == V_611 ) )
return V_306 ;
F_138 ( F_143 ( V_274 ) , V_192 ) ;
if ( V_306 < 0 )
F_7 ( L_273 , V_306 ) ;
if ( ! ( V_596 & V_608 ) )
F_7 ( L_47 ) ;
else if ( F_140 ( V_192 ) == V_590 )
V_595 -> V_601 ( V_16 , V_17 ) ;
else {
F_7 ( L_274 ) ;
V_595 -> V_601 ( V_16 , V_17 ) ;
}
}
return V_306 ;
}
static int F_146 ( unsigned int V_192 , void * V_612 , T_4 * V_613 ,
void T_3 * * V_614 , void * * * V_615 )
{
int V_306 = 0 ;
switch ( V_192 ) {
case V_616 :
case V_617 :
case V_610 :
case V_611 : {
struct V_117 * V_618 = V_612 ;
if ( F_26 ( V_618 -> type ) && V_618 -> V_129 > 0 ) {
if ( V_618 -> V_129 > V_619 ) {
V_306 = - V_290 ;
break;
}
* V_614 = ( void T_3 * ) V_618 -> V_127 . V_128 ;
* V_615 = ( void * * ) & V_618 -> V_127 . V_128 ;
* V_613 = sizeof( struct V_121 ) * V_618 -> V_129 ;
V_306 = 1 ;
}
break;
}
case V_620 :
case V_621 : {
struct V_263 * V_622 = V_612 ;
if ( V_622 -> V_266 ) {
if ( V_622 -> V_266 > 256 ) {
V_306 = - V_290 ;
break;
}
* V_614 = ( void T_3 * ) V_622 -> V_622 ;
* V_615 = ( void * * ) & V_622 -> V_622 ;
* V_613 = V_622 -> V_266 * 128 ;
V_306 = 1 ;
}
break;
}
case V_623 :
case V_624 :
case V_625 : {
struct V_169 * V_532 = V_612 ;
if ( V_532 -> V_91 != 0 ) {
if ( V_532 -> V_91 > V_626 ) {
V_306 = - V_290 ;
break;
}
* V_614 = ( void T_3 * ) V_532 -> V_172 ;
* V_615 = ( void * * ) & V_532 -> V_172 ;
* V_613 = sizeof( struct V_533 )
* V_532 -> V_91 ;
V_306 = 1 ;
}
break;
}
}
return V_306 ;
}
long
F_147 ( struct V_271 * V_271 , unsigned int V_192 , unsigned long V_16 ,
T_5 V_605 )
{
char V_627 [ 128 ] ;
void * V_628 = NULL ;
void * V_612 = ( void * ) V_16 ;
long V_492 = - V_290 ;
bool V_629 ;
T_4 V_613 = 0 ;
void T_3 * V_614 = NULL ;
void * * V_615 = NULL ;
if ( F_140 ( V_192 ) != V_590 ) {
if ( F_148 ( V_192 ) <= sizeof( V_627 ) ) {
V_612 = V_627 ;
} else {
V_628 = F_149 ( F_148 ( V_192 ) , V_630 ) ;
if ( NULL == V_628 )
return - V_631 ;
V_612 = V_628 ;
}
V_492 = - V_632 ;
if ( F_140 ( V_192 ) & V_592 ) {
unsigned int V_633 = F_148 ( V_192 ) ;
if ( F_135 ( V_192 ) ) {
T_2 V_39 = V_580 [ F_136 ( V_192 ) ] . V_39 ;
if ( V_39 & V_634 )
V_633 = ( V_39 & V_634 ) >> 16 ;
}
if ( F_150 ( V_612 , ( void T_3 * ) V_16 , V_633 ) )
goto V_635;
if ( V_633 < F_148 ( V_192 ) )
memset ( ( V_636 * ) V_612 + V_633 , 0 , F_148 ( V_192 ) - V_633 ) ;
} else {
memset ( V_612 , 0 , F_148 ( V_192 ) ) ;
}
}
V_492 = F_146 ( V_192 , V_612 , & V_613 , & V_614 , & V_615 ) ;
if ( V_492 < 0 )
goto V_635;
V_629 = V_492 ;
if ( V_629 ) {
V_628 = F_149 ( V_613 , V_630 ) ;
V_492 = - V_631 ;
if ( NULL == V_628 )
goto V_637;
V_492 = - V_632 ;
if ( F_150 ( V_628 , V_614 , V_613 ) )
goto V_637;
* V_615 = V_628 ;
}
V_492 = V_605 ( V_271 , V_192 , V_612 ) ;
if ( V_492 == - V_638 )
V_492 = - V_317 ;
if ( V_492 == 0 ) {
if ( V_192 == V_611 )
F_151 ( F_61 ( V_271 ) -> V_639 , V_612 ) ;
else if ( V_192 == V_610 )
F_152 ( F_61 ( V_271 ) -> V_639 , V_612 ) ;
}
if ( V_629 ) {
* V_615 = ( void V_640 * ) V_614 ;
if ( F_153 ( V_614 , V_628 , V_613 ) )
V_492 = - V_632 ;
goto V_637;
}
if ( V_492 < 0 && V_192 != V_641 )
goto V_635;
V_637:
switch ( F_140 ( V_192 ) ) {
case V_591 :
case ( V_592 | V_591 ) :
if ( F_153 ( ( void T_3 * ) V_16 , V_612 , F_148 ( V_192 ) ) )
V_492 = - V_632 ;
break;
}
V_635:
F_154 ( V_628 ) ;
return V_492 ;
}
long F_155 ( struct V_271 * V_271 ,
unsigned int V_192 , unsigned long V_16 )
{
return F_147 ( V_271 , V_192 , V_16 , F_141 ) ;
}
