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
V_44 -> V_64 , V_44 -> V_39 , V_44 -> V_65 ,
V_44 -> V_66 ) ;
break;
case V_67 :
case V_68 :
V_46 = & V_19 -> V_57 . V_69 ;
F_7 ( L_12
L_16
L_17
L_18 ,
V_46 -> V_58 , V_46 -> V_59 ,
( V_46 -> V_40 & 0xff ) ,
( V_46 -> V_40 >> 8 ) & 0xff ,
( V_46 -> V_40 >> 16 ) & 0xff ,
( V_46 -> V_40 >> 24 ) & 0xff ,
F_13 ( V_46 -> V_60 , V_61 ) ,
V_46 -> V_64 , V_46 -> V_70 , V_46 -> V_39 ,
V_46 -> V_65 , V_46 -> V_66 ) ;
for ( V_3 = 0 ; V_3 < V_46 -> V_70 ; V_3 ++ )
F_15 ( V_71 L_19 , V_3 ,
V_46 -> V_72 [ V_3 ] . V_62 ,
V_46 -> V_72 [ V_3 ] . V_63 ) ;
break;
case V_73 :
case V_74 :
V_52 = & V_19 -> V_57 . V_52 ;
F_7 ( L_20 ,
V_52 -> V_75 . V_58 , V_52 -> V_75 . V_59 , V_52 -> V_75 . V_76 , V_52 -> V_75 . V_77 ,
F_13 ( V_52 -> V_60 , V_61 ) ,
V_52 -> V_78 , V_52 -> V_79 , V_52 -> V_80 ,
V_52 -> V_81 , V_52 -> V_82 ) ;
break;
case V_83 :
case V_84 :
V_48 = & V_19 -> V_57 . V_48 ;
F_7 ( L_21
L_22 ,
V_48 -> V_85 , V_48 -> V_86 ,
V_48 -> V_87 ,
( V_48 -> V_88 & 0xff ) ,
( V_48 -> V_88 >> 8 ) & 0xff ,
( V_48 -> V_88 >> 16 ) & 0xff ,
( V_48 -> V_88 >> 24 ) & 0xff ,
V_48 -> V_89 [ 0 ] , V_48 -> V_89 [ 1 ] ,
V_48 -> V_90 [ 0 ] , V_48 -> V_90 [ 1 ] ) ;
break;
case V_91 :
case V_92 :
V_50 = & V_19 -> V_57 . V_50 ;
F_7 ( L_23 ,
V_50 -> V_93 , V_50 -> V_94 ) ;
for ( V_3 = 0 ; V_3 < 24 ; V_3 ++ )
F_15 ( V_71 L_24 , V_3 ,
V_50 -> V_95 [ 0 ] [ V_3 ] ,
V_50 -> V_95 [ 1 ] [ V_3 ] ) ;
break;
case V_96 :
V_54 = & V_19 -> V_57 . V_54 ;
F_7 ( L_25 ,
( V_54 -> V_40 >> 0 ) & 0xff ,
( V_54 -> V_40 >> 8 ) & 0xff ,
( V_54 -> V_40 >> 16 ) & 0xff ,
( V_54 -> V_40 >> 24 ) & 0xff ) ;
break;
}
}
static void F_16 ( const void * V_16 , bool V_17 )
{
const struct V_97 * V_19 = V_16 ;
F_7 ( L_26
L_27
L_28 ,
V_19 -> V_35 , V_19 -> V_39 , V_19 -> V_98 ,
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
F_7 ( L_29 , F_13 ( * ( T_2 * ) V_16 , V_38 ) ) ;
}
static void F_18 ( const void * V_16 , bool V_17 )
{
const struct V_99 * V_19 = V_16 ;
if ( V_17 )
F_7 ( L_30 , V_19 -> V_27 , V_19 -> V_100 ) ;
else
F_7 ( L_31
L_32 ,
V_19 -> V_27 , ( int ) sizeof( V_19 -> V_14 ) , V_19 -> V_14 , V_19 -> V_35 ,
V_19 -> V_101 , V_19 -> V_102 , V_19 -> V_100 ) ;
}
static void F_19 ( const void * V_16 , bool V_17 )
{
const struct V_103 * V_19 = V_16 ;
if ( V_17 )
F_7 ( L_33 , V_19 -> V_27 , V_19 -> V_104 ) ;
else
F_7 ( L_34
L_35
L_36 ,
V_19 -> V_27 , ( int ) sizeof( V_19 -> V_14 ) , V_19 -> V_14 , V_19 -> type ,
V_19 -> V_35 , V_19 -> V_101 ,
V_19 -> V_102 , V_19 -> signal , V_19 -> V_105 ,
V_19 -> V_106 , V_19 -> V_104 ) ;
}
static void F_20 ( const void * V_16 , bool V_17 )
{
const struct V_107 * V_19 = V_16 ;
F_7 ( L_37 ,
V_19 -> V_29 , V_19 -> type , V_19 -> V_108 ) ;
}
static void F_21 ( const void * V_16 , bool V_17 )
{
const struct V_12 * V_19 = V_16 ;
F_7 ( L_38
L_39 , V_19 -> V_27 ,
( unsigned long long ) V_19 -> V_1 , ( int ) sizeof( V_19 -> V_14 ) , V_19 -> V_14 ,
V_19 -> V_8 . V_10 ,
V_19 -> V_8 . V_11 ,
V_19 -> V_15 ) ;
}
static void F_22 ( const void * V_16 , bool V_17 )
{
F_7 ( L_40 , * ( const long long unsigned * ) V_16 ) ;
}
static void F_23 ( const void * V_16 , bool V_17 )
{
const struct V_109 * V_19 = V_16 ;
F_7 ( L_41
L_42 ,
V_19 -> V_29 , V_19 -> type , V_19 -> V_110 , V_19 -> V_111 , V_19 -> V_112 ,
V_19 -> V_101 , V_19 -> V_102 ) ;
}
static void F_24 ( const void * V_16 , bool V_17 )
{
const struct V_113 * V_19 = V_16 ;
F_7 ( L_43 ,
V_19 -> V_90 ,
F_13 ( V_19 -> type , V_38 ) ,
F_13 ( V_19 -> V_114 , V_115 ) ) ;
}
static void F_25 ( const void * V_16 , bool V_17 )
{
const struct V_116 * V_19 = V_16 ;
const struct V_117 * V_118 = & V_19 -> V_119 ;
const struct V_120 * V_121 ;
int V_3 ;
F_7 ( L_44
L_45 ,
V_19 -> V_122 . V_123 / 3600 ,
( int ) ( V_19 -> V_122 . V_123 / 60 ) % 60 ,
( int ) ( V_19 -> V_122 . V_123 % 60 ) ,
( long ) V_19 -> V_122 . V_124 ,
V_19 -> V_27 ,
F_13 ( V_19 -> type , V_38 ) ,
V_19 -> V_39 , F_13 ( V_19 -> V_60 , V_61 ) ,
V_19 -> V_125 , F_13 ( V_19 -> V_114 , V_115 ) ) ;
if ( F_26 ( V_19 -> type ) && V_19 -> V_126 . V_127 ) {
F_7 ( L_46 ) ;
for ( V_3 = 0 ; V_3 < V_19 -> V_128 ; ++ V_3 ) {
V_121 = & V_19 -> V_126 . V_127 [ V_3 ] ;
F_15 ( V_71
L_47
L_48 ,
V_3 , V_121 -> V_129 , V_121 -> V_130 ,
V_121 -> V_126 . V_131 , V_121 -> V_128 ) ;
}
} else {
F_7 ( L_49 ,
V_19 -> V_129 , V_19 -> V_126 . V_131 , V_19 -> V_128 ) ;
}
F_15 ( V_71 L_50
L_51 ,
V_118 -> V_132 , V_118 -> V_133 , V_118 -> V_134 ,
V_118 -> type , V_118 -> V_39 , V_118 -> V_135 , * ( V_136 * ) V_118 -> V_137 ) ;
}
static void F_27 ( const void * V_16 , bool V_17 )
{
const struct V_138 * V_19 = V_16 ;
F_7 ( L_52 ,
V_19 -> V_139 , F_13 ( V_19 -> type , V_38 ) ,
V_19 -> V_27 , V_19 -> V_121 , V_19 -> V_39 ) ;
}
static void F_28 ( const void * V_16 , bool V_17 )
{
const struct V_140 * V_19 = V_16 ;
F_7 ( L_53 ,
V_19 -> V_27 , V_19 -> V_90 ,
F_13 ( V_19 -> V_114 , V_115 ) ) ;
F_14 ( & V_19 -> V_141 , V_17 ) ;
}
static void F_29 ( const void * V_16 , bool V_17 )
{
const struct V_142 * V_19 = V_16 ;
F_7 ( L_11 , F_13 ( V_19 -> type , V_38 ) ) ;
if ( V_19 -> type == V_55 ||
V_19 -> type == V_67 ) {
const struct V_143 * V_144 = & V_19 -> V_145 . V_146 ;
F_7 ( L_54
L_55 ,
V_144 -> V_35 , V_144 -> V_147 ,
V_144 -> V_148 . V_10 , V_144 -> V_148 . V_11 ,
V_144 -> V_149 , V_144 -> V_150 ) ;
} else if ( V_19 -> type == V_56 ||
V_19 -> type == V_68 ) {
const struct V_151 * V_144 = & V_19 -> V_145 . V_152 ;
F_7 ( L_56
L_57 ,
V_144 -> V_35 , V_144 -> V_153 ,
V_144 -> V_148 . V_10 , V_144 -> V_148 . V_11 ,
V_144 -> V_149 , V_144 -> V_154 ) ;
} else {
F_7 ( L_46 ) ;
}
}
static void F_30 ( const void * V_16 , bool V_17 )
{
const struct V_155 * V_19 = V_16 ;
F_7 ( L_58
L_59 ,
V_19 -> V_1 , V_19 -> type , ( int ) sizeof( V_19 -> V_14 ) , V_19 -> V_14 ,
V_19 -> V_156 , V_19 -> V_157 ,
V_19 -> V_158 , V_19 -> V_159 , V_19 -> V_39 ) ;
}
static void F_31 ( const void * V_16 , bool V_17 )
{
const struct V_160 * V_19 = V_16 ;
F_7 ( L_60
L_61
L_62 ,
V_19 -> V_1 , V_19 -> type , ( int ) sizeof( V_19 -> V_14 ) , V_19 -> V_14 ,
V_19 -> V_156 , V_19 -> V_157 ,
V_19 -> V_158 , V_19 -> V_159 , V_19 -> V_39 ,
V_19 -> V_161 , V_19 -> V_162 , V_19 -> V_163 ,
V_19 -> V_164 [ 0 ] , V_19 -> V_164 [ 1 ] , V_19 -> V_164 [ 2 ] , V_19 -> V_164 [ 3 ] ) ;
}
static void F_32 ( const void * V_16 , bool V_17 )
{
const struct V_165 * V_19 = V_16 ;
F_7 ( L_63 , V_19 -> V_1 , V_19 -> V_27 ) ;
}
static void F_33 ( const void * V_16 , bool V_17 )
{
const struct V_166 * V_19 = V_16 ;
F_7 ( L_64 , V_19 -> V_1 , V_19 -> V_167 ) ;
}
static void F_34 ( const void * V_16 , bool V_17 )
{
const struct V_168 * V_19 = V_16 ;
int V_3 ;
F_7 ( L_65 ,
V_19 -> V_169 , V_19 -> V_90 , V_19 -> V_170 ) ;
for ( V_3 = 0 ; V_3 < V_19 -> V_90 ; V_3 ++ ) {
if ( ! V_19 -> V_171 [ V_3 ] . V_172 )
F_7 ( L_66 ,
V_19 -> V_171 [ V_3 ] . V_1 , V_19 -> V_171 [ V_3 ] . V_167 ) ;
else
F_7 ( L_67 ,
V_19 -> V_171 [ V_3 ] . V_1 , V_19 -> V_171 [ V_3 ] . V_172 ) ;
}
F_7 ( L_46 ) ;
}
static void F_35 ( const void * V_16 , bool V_17 )
{
const struct V_173 * V_19 = V_16 ;
F_7 ( L_68
L_69
L_70 ,
F_13 ( V_19 -> type , V_38 ) ,
V_19 -> V_174 . V_58 , V_19 -> V_174 . V_59 ,
V_19 -> V_174 . V_76 , V_19 -> V_174 . V_77 ,
V_19 -> V_175 . V_58 , V_19 -> V_175 . V_59 ,
V_19 -> V_175 . V_76 , V_19 -> V_175 . V_77 ,
V_19 -> V_176 . V_10 , V_19 -> V_176 . V_11 ) ;
}
static void F_36 ( const void * V_16 , bool V_17 )
{
const struct V_177 * V_19 = V_16 ;
F_7 ( L_71 ,
F_13 ( V_19 -> type , V_38 ) ,
V_19 -> V_144 . V_58 , V_19 -> V_144 . V_59 ,
V_19 -> V_144 . V_76 , V_19 -> V_144 . V_77 ) ;
}
static void F_37 ( const void * V_16 , bool V_17 )
{
const struct V_178 * V_19 = V_16 ;
F_7 ( L_72 ,
F_13 ( V_19 -> type , V_38 ) ,
V_19 -> V_179 , V_19 -> V_39 ,
V_19 -> V_180 . V_58 , V_19 -> V_180 . V_59 , V_19 -> V_180 . V_76 , V_19 -> V_180 . V_77 ) ;
}
static void F_38 ( const void * V_16 , bool V_17 )
{
const struct V_181 * V_19 = V_16 ;
F_7 ( L_73
L_74 ,
V_19 -> V_182 , V_19 -> V_183 , V_19 -> V_184 ,
V_19 -> V_185 , V_19 -> V_186 ) ;
}
static void F_39 ( const void * V_16 , bool V_17 )
{
const struct V_187 * V_19 = V_16 ;
F_7 ( L_75 ,
V_19 -> V_188 , V_19 -> V_189 ) ;
}
static void F_40 ( const void * V_16 , bool V_17 )
{
const struct V_190 * V_19 = V_16 ;
F_7 ( L_76 ,
V_19 -> V_191 , V_19 -> V_39 ) ;
}
static void F_41 ( const void * V_16 , bool V_17 )
{
const struct V_192 * V_19 = V_16 ;
F_7 ( L_76 , V_19 -> V_191 , V_19 -> V_39 ) ;
if ( V_19 -> V_191 == V_193 )
F_42 ( L_77 ,
V_19 -> V_89 . V_194 , V_19 -> V_89 . V_141 ) ;
else if ( V_19 -> V_191 == V_195 )
F_42 ( L_78 , V_19 -> V_196 . V_197 ) ;
}
static void F_43 ( const void * V_16 , bool V_17 )
{
const struct V_198 * V_19 = V_16 ;
F_7 ( L_79 , V_19 -> V_199 . type ) ;
if ( V_19 -> V_199 . type == V_200 )
F_7 ( L_80 ,
( int ) sizeof( V_19 -> V_199 . V_14 ) , V_19 -> V_199 . V_14 ) ;
else
F_7 ( L_81 , V_19 -> V_199 . V_201 ) ;
F_7 ( L_82 , ( int ) sizeof( V_19 -> V_14 ) , V_19 -> V_14 ) ;
}
static void F_44 ( const void * V_16 , bool V_17 )
{
const struct V_202 * V_19 = V_16 ;
F_7 ( L_79 , V_19 -> V_199 . type ) ;
if ( V_19 -> V_199 . type == V_200 )
F_7 ( L_80 ,
( int ) sizeof( V_19 -> V_199 . V_14 ) , V_19 -> V_199 . V_14 ) ;
else
F_7 ( L_81 , V_19 -> V_199 . V_201 ) ;
F_7 ( L_83 ,
V_19 -> V_203 , V_19 -> V_204 ) ;
}
static void F_45 ( const void * V_16 , bool V_17 )
{
const struct V_205 * V_19 = V_16 ;
switch ( V_19 -> type ) {
case V_206 :
F_7 ( L_84
L_85
L_86
L_87
L_88
L_89
L_90
L_91 ,
V_19 -> V_207 . V_208 , V_19 -> V_207 . V_209 ,
V_19 -> V_207 . V_58 , V_19 -> V_207 . V_59 ,
V_19 -> V_207 . V_210 , V_19 -> V_207 . V_211 ,
V_19 -> V_207 . V_212 , V_19 -> V_207 . V_213 ,
V_19 -> V_207 . V_214 , V_19 -> V_207 . V_215 ,
V_19 -> V_207 . V_216 , V_19 -> V_207 . V_217 ,
V_19 -> V_207 . V_218 , V_19 -> V_207 . V_219 ,
V_19 -> V_207 . V_4 , V_19 -> V_207 . V_39 ) ;
break;
default:
F_7 ( L_92 , V_19 -> type ) ;
break;
}
}
static void F_46 ( const void * V_16 , bool V_17 )
{
const struct V_220 * V_19 = V_16 ;
F_7 ( L_93 , V_19 -> V_27 ) ;
F_45 ( & V_19 -> V_221 , V_17 ) ;
}
static void F_47 ( const void * V_16 , bool V_17 )
{
const struct V_222 * V_19 = V_16 ;
switch ( V_19 -> type ) {
case V_206 :
F_7 ( L_94
L_95 ,
V_19 -> V_207 . V_223 , V_19 -> V_207 . V_224 ,
V_19 -> V_207 . V_225 , V_19 -> V_207 . V_226 ,
V_19 -> V_207 . V_227 , V_19 -> V_207 . V_228 ,
V_19 -> V_207 . V_4 , V_19 -> V_207 . V_24 ) ;
break;
default:
F_7 ( L_96 , V_19 -> type ) ;
break;
}
}
static void F_48 ( const void * V_16 , bool V_17 )
{
const struct V_229 * V_19 = V_16 ;
F_7 ( L_97 ,
V_19 -> V_27 ,
( V_19 -> V_230 & 0xff ) ,
( V_19 -> V_230 >> 8 ) & 0xff ,
( V_19 -> V_230 >> 16 ) & 0xff ,
( V_19 -> V_230 >> 24 ) & 0xff ,
V_19 -> type ) ;
switch ( V_19 -> type ) {
case V_231 :
F_7 ( L_98 ,
V_19 -> V_232 . V_58 , V_19 -> V_232 . V_59 ) ;
break;
case V_233 :
F_7 ( L_99 ,
V_19 -> V_234 . V_223 , V_19 -> V_234 . V_225 ,
V_19 -> V_234 . V_235 , V_19 -> V_234 . V_236 ,
V_19 -> V_234 . V_224 , V_19 -> V_234 . V_226 ) ;
break;
case V_237 :
default:
F_7 ( L_46 ) ;
break;
}
}
static void F_49 ( const void * V_16 , bool V_17 )
{
const struct V_238 * V_19 = V_16 ;
F_7 ( L_100 ,
V_19 -> V_27 ,
( V_19 -> V_230 & 0xff ) ,
( V_19 -> V_230 >> 8 ) & 0xff ,
( V_19 -> V_230 >> 16 ) & 0xff ,
( V_19 -> V_230 >> 24 ) & 0xff ,
V_19 -> V_58 , V_19 -> V_59 , V_19 -> type ) ;
switch ( V_19 -> type ) {
case V_239 :
F_7 ( L_101 ,
V_19 -> V_232 . V_10 ,
V_19 -> V_232 . V_11 ) ;
break;
case V_240 :
F_7 ( L_102 ,
V_19 -> V_234 . V_241 . V_10 ,
V_19 -> V_234 . V_241 . V_11 ,
V_19 -> V_234 . V_242 . V_10 ,
V_19 -> V_234 . V_242 . V_11 ,
V_19 -> V_234 . V_158 . V_10 ,
V_19 -> V_234 . V_158 . V_11 ) ;
break;
case V_243 :
default:
F_7 ( L_46 ) ;
break;
}
}
static void F_50 ( const void * V_16 , bool V_17 )
{
const struct V_244 * V_19 = V_16 ;
const struct V_245 * V_144 ;
F_7 ( L_103
L_104 ,
V_19 -> type , V_19 -> V_246 , V_19 -> V_125 , V_19 -> V_1 ,
V_19 -> V_122 . V_123 , V_19 -> V_122 . V_247 ) ;
switch ( V_19 -> type ) {
case V_248 :
F_15 ( V_71 L_105 ,
F_13 ( V_19 -> V_249 . V_215 . V_60 , V_61 ) ) ;
break;
case V_250 :
V_144 = & V_19 -> V_249 . V_251 ;
F_15 ( V_71 L_106 ,
V_144 -> V_252 , V_144 -> type ) ;
if ( V_144 -> type == V_253 )
F_7 ( L_107 , V_144 -> V_254 ) ;
else
F_7 ( L_108 , V_144 -> V_167 ) ;
F_7 ( L_109
L_110 ,
V_144 -> V_39 , V_144 -> V_156 , V_144 -> V_157 ,
V_144 -> V_158 , V_144 -> V_159 ) ;
break;
case V_255 :
F_7 ( L_111 ,
V_19 -> V_249 . V_256 . V_257 ) ;
break;
}
}
static void F_51 ( const void * V_16 , bool V_17 )
{
const struct V_258 * V_19 = V_16 ;
F_7 ( L_112 ,
V_19 -> type , V_19 -> V_1 , V_19 -> V_39 ) ;
}
static void F_52 ( const void * V_16 , bool V_17 )
{
const struct V_259 * V_19 = V_16 ;
int V_3 ;
F_7 ( L_113 ,
F_13 ( V_19 -> type , V_38 ) , V_19 -> V_93 ) ;
for ( V_3 = 0 ; V_3 < 24 ; V_3 ++ )
F_15 ( V_71 L_24 , V_3 ,
V_19 -> V_95 [ 0 ] [ V_3 ] ,
V_19 -> V_95 [ 1 ] [ V_3 ] ) ;
}
static void F_53 ( const void * V_16 , bool V_17 )
{
const struct V_260 * V_19 = V_16 ;
F_7 ( L_114
L_115 ,
V_19 -> V_29 , V_19 -> type , V_19 -> V_27 ,
V_19 -> V_35 , V_19 -> V_101 ,
V_19 -> V_102 , V_19 -> V_261 ) ;
}
static void F_54 ( const void * V_16 , bool V_17 )
{
const struct V_262 * V_19 = V_16 ;
F_7 ( L_116 ,
V_19 -> V_263 , V_19 -> V_264 , V_19 -> V_265 ) ;
}
static void F_55 ( const void * V_16 , bool V_17 )
{
F_7 ( L_117 , * ( const T_2 * ) V_16 ) ;
}
static void F_56 ( const void * V_16 , bool V_17 )
{
F_7 ( L_46 ) ;
}
static void F_57 ( const void * V_16 , bool V_17 )
{
F_7 ( L_118 ) ;
}
static int F_58 ( struct V_168 * V_144 , int V_266 )
{
V_136 V_3 ;
V_144 -> V_267 [ 0 ] = V_144 -> V_267 [ 1 ] = 0 ;
for ( V_3 = 0 ; V_3 < V_144 -> V_90 ; V_3 ++ )
V_144 -> V_171 [ V_3 ] . V_268 [ 0 ] = 0 ;
if ( ! V_266 && V_144 -> V_169 == V_269 )
return 0 ;
for ( V_3 = 0 ; V_3 < V_144 -> V_90 ; V_3 ++ ) {
if ( F_59 ( V_144 -> V_171 [ V_3 ] . V_1 ) != V_144 -> V_169 ) {
V_144 -> V_170 = V_3 ;
return 0 ;
}
}
return 1 ;
}
static int F_60 ( struct V_270 * V_270 , enum V_271 type )
{
struct V_272 * V_273 = F_61 ( V_270 ) ;
const struct V_274 * V_275 = V_273 -> V_276 ;
bool V_277 = V_273 -> V_278 == V_279 ;
bool V_280 = V_273 -> V_278 == V_281 ;
bool V_282 = V_273 -> V_278 == V_283 ;
bool V_284 = V_273 -> V_285 != V_286 ;
bool V_287 = V_273 -> V_285 != V_288 ;
if ( V_275 == NULL )
return - V_289 ;
switch ( type ) {
case V_55 :
if ( V_277 && V_284 &&
( V_275 -> V_290 || V_275 -> V_291 ) )
return 0 ;
break;
case V_67 :
if ( V_277 && V_284 && V_275 -> V_291 )
return 0 ;
break;
case V_73 :
if ( V_277 && V_284 && V_275 -> V_292 )
return 0 ;
break;
case V_56 :
if ( V_277 && V_287 &&
( V_275 -> V_293 || V_275 -> V_294 ) )
return 0 ;
break;
case V_68 :
if ( V_277 && V_287 && V_275 -> V_294 )
return 0 ;
break;
case V_74 :
if ( V_277 && V_287 && V_275 -> V_295 )
return 0 ;
break;
case V_83 :
if ( V_280 && V_284 && V_275 -> V_296 )
return 0 ;
break;
case V_84 :
if ( V_280 && V_287 && V_275 -> V_297 )
return 0 ;
break;
case V_91 :
if ( V_280 && V_284 && V_275 -> V_298 )
return 0 ;
break;
case V_92 :
if ( V_280 && V_287 && V_275 -> V_299 )
return 0 ;
break;
case V_96 :
if ( V_282 && V_284 && V_275 -> V_300 )
return 0 ;
break;
default:
break;
}
return - V_289 ;
}
static void F_62 ( struct V_42 * V_57 )
{
unsigned int V_86 ;
if ( V_57 -> type != V_55 &&
V_57 -> type != V_56 )
return;
if ( V_57 -> V_57 . V_44 . V_301 == V_302 )
return;
V_57 -> V_57 . V_44 . V_301 = V_302 ;
V_86 = F_63 ( struct V_43 , V_301 )
+ sizeof( V_57 -> V_57 . V_44 . V_301 ) ;
memset ( ( ( void * ) & V_57 -> V_57 . V_44 ) + V_86 , 0 ,
sizeof( V_57 -> V_57 . V_44 ) - V_86 ) ;
}
static int F_64 ( const struct V_274 * V_275 ,
struct V_270 * V_270 , void * V_303 , void * V_16 )
{
struct V_18 * V_304 = (struct V_18 * ) V_16 ;
int V_305 ;
V_304 -> V_23 = V_306 ;
V_305 = V_275 -> V_307 ( V_270 , V_303 , V_304 ) ;
V_304 -> V_24 |= V_308 ;
F_65 ( ! ( V_304 -> V_24 & V_309 ) ||
! V_304 -> V_25 ) ;
V_304 -> V_25 |= V_308 ;
return V_305 ;
}
static int F_66 ( const struct V_274 * V_275 ,
struct V_270 * V_270 , void * V_303 , void * V_16 )
{
return V_275 -> V_310 ( V_270 , V_303 , * ( unsigned int * ) V_16 ) ;
}
static int F_67 ( const struct V_274 * V_275 ,
struct V_270 * V_270 , void * V_303 , void * V_16 )
{
return V_275 -> V_311 ( V_270 , V_303 , * ( unsigned int * ) V_16 ) ;
}
static int F_68 ( const struct V_274 * V_275 ,
struct V_270 * V_270 , void * V_303 , void * V_16 )
{
struct V_272 * V_273 ;
T_2 * V_19 = V_16 ;
if ( V_275 -> V_312 )
return V_275 -> V_312 ( V_270 , V_303 , V_16 ) ;
V_273 = F_61 ( V_270 ) ;
* V_19 = F_69 ( V_273 -> V_313 ) ;
return 0 ;
}
static int F_70 ( const struct V_274 * V_275 ,
struct V_270 * V_270 , void * V_303 , void * V_16 )
{
struct V_272 * V_273 ;
struct V_314 * V_315 ;
T_2 * V_19 = V_16 ;
if ( V_275 -> V_316 )
return V_275 -> V_316 ( V_270 , V_303 , * V_19 ) ;
V_273 = F_61 ( V_270 ) ;
V_315 = V_270 -> V_317 ;
return F_71 ( V_273 -> V_313 , & V_315 -> V_313 , * V_19 ) ;
}
static int F_72 ( const struct V_274 * V_275 ,
struct V_270 * V_270 , void * V_303 , void * V_16 )
{
struct V_272 * V_273 = F_61 ( V_270 ) ;
struct V_26 * V_19 = V_16 ;
if ( F_73 ( V_273 , V_318 ) )
V_19 -> V_24 |= V_319 ;
return V_275 -> V_320 ( V_270 , V_303 , V_19 ) ;
}
static int F_74 ( const struct V_274 * V_275 ,
struct V_270 * V_270 , void * V_303 , void * V_16 )
{
struct V_272 * V_273 = F_61 ( V_270 ) ;
struct V_31 * V_19 = V_16 ;
if ( F_73 ( V_273 , V_318 ) )
V_19 -> V_24 |= V_321 ;
return V_275 -> V_322 ( V_270 , V_303 , V_19 ) ;
}
static int F_75 ( const struct V_274 * V_275 ,
struct V_270 * V_270 , void * V_303 , void * V_16 )
{
struct V_37 * V_19 = V_16 ;
struct V_272 * V_273 = F_61 ( V_270 ) ;
bool V_277 = V_273 -> V_278 == V_279 ;
bool V_282 = V_273 -> V_278 == V_283 ;
bool V_284 = V_273 -> V_285 != V_286 ;
bool V_287 = V_273 -> V_285 != V_288 ;
switch ( V_19 -> type ) {
case V_55 :
if ( F_76 ( ! V_284 || ! V_277 || ! V_275 -> V_323 ) )
break;
return V_275 -> V_323 ( V_270 , V_303 , V_16 ) ;
case V_67 :
if ( F_76 ( ! V_284 || ! V_277 || ! V_275 -> V_324 ) )
break;
return V_275 -> V_324 ( V_270 , V_303 , V_16 ) ;
case V_73 :
if ( F_76 ( ! V_284 || ! V_277 || ! V_275 -> V_325 ) )
break;
return V_275 -> V_325 ( V_270 , V_303 , V_16 ) ;
case V_56 :
if ( F_76 ( ! V_287 || ! V_277 || ! V_275 -> V_326 ) )
break;
return V_275 -> V_326 ( V_270 , V_303 , V_16 ) ;
case V_68 :
if ( F_76 ( ! V_287 || ! V_277 || ! V_275 -> V_327 ) )
break;
return V_275 -> V_327 ( V_270 , V_303 , V_16 ) ;
case V_96 :
if ( F_76 ( ! V_284 || ! V_282 || ! V_275 -> V_328 ) )
break;
return V_275 -> V_328 ( V_270 , V_303 , V_16 ) ;
}
return - V_289 ;
}
static int F_77 ( const struct V_274 * V_275 ,
struct V_270 * V_270 , void * V_303 , void * V_16 )
{
struct V_42 * V_19 = V_16 ;
struct V_272 * V_273 = F_61 ( V_270 ) ;
bool V_277 = V_273 -> V_278 == V_279 ;
bool V_282 = V_273 -> V_278 == V_283 ;
bool V_284 = V_273 -> V_285 != V_286 ;
bool V_287 = V_273 -> V_285 != V_288 ;
int V_305 ;
switch ( V_19 -> type ) {
case V_73 :
case V_74 : {
struct V_329 T_3 * V_80 = V_19 -> V_57 . V_52 . V_80 ;
T_2 V_79 = V_19 -> V_57 . V_52 . V_79 ;
void T_3 * V_81 = V_19 -> V_57 . V_52 . V_81 ;
memset ( & V_19 -> V_57 , 0 , sizeof( V_19 -> V_57 ) ) ;
V_19 -> V_57 . V_52 . V_80 = V_80 ;
V_19 -> V_57 . V_52 . V_79 = V_79 ;
V_19 -> V_57 . V_52 . V_81 = V_81 ;
break;
}
default:
memset ( & V_19 -> V_57 , 0 , sizeof( V_19 -> V_57 ) ) ;
break;
}
switch ( V_19 -> type ) {
case V_55 :
if ( F_76 ( ! V_284 || ! V_277 || ! V_275 -> V_290 ) )
break;
V_19 -> V_57 . V_44 . V_301 = V_302 ;
V_305 = V_275 -> V_290 ( V_270 , V_303 , V_16 ) ;
V_19 -> V_57 . V_44 . V_301 = V_302 ;
return V_305 ;
case V_67 :
if ( F_76 ( ! V_284 || ! V_277 || ! V_275 -> V_291 ) )
break;
return V_275 -> V_291 ( V_270 , V_303 , V_16 ) ;
case V_73 :
if ( F_76 ( ! V_284 || ! V_277 || ! V_275 -> V_292 ) )
break;
return V_275 -> V_292 ( V_270 , V_303 , V_16 ) ;
case V_83 :
if ( F_76 ( ! V_284 || V_277 || ! V_275 -> V_296 ) )
break;
return V_275 -> V_296 ( V_270 , V_303 , V_16 ) ;
case V_91 :
if ( F_76 ( ! V_284 || V_277 || ! V_275 -> V_298 ) )
break;
return V_275 -> V_298 ( V_270 , V_303 , V_16 ) ;
case V_56 :
if ( F_76 ( ! V_287 || ! V_277 || ! V_275 -> V_293 ) )
break;
V_19 -> V_57 . V_44 . V_301 = V_302 ;
V_305 = V_275 -> V_293 ( V_270 , V_303 , V_16 ) ;
V_19 -> V_57 . V_44 . V_301 = V_302 ;
return V_305 ;
case V_68 :
if ( F_76 ( ! V_287 || ! V_277 || ! V_275 -> V_294 ) )
break;
return V_275 -> V_294 ( V_270 , V_303 , V_16 ) ;
case V_74 :
if ( F_76 ( ! V_287 || ! V_277 || ! V_275 -> V_295 ) )
break;
return V_275 -> V_295 ( V_270 , V_303 , V_16 ) ;
case V_84 :
if ( F_76 ( ! V_287 || V_277 || ! V_275 -> V_297 ) )
break;
return V_275 -> V_297 ( V_270 , V_303 , V_16 ) ;
case V_92 :
if ( F_76 ( ! V_287 || V_277 || ! V_275 -> V_299 ) )
break;
return V_275 -> V_299 ( V_270 , V_303 , V_16 ) ;
case V_96 :
if ( F_76 ( ! V_284 || ! V_282 || ! V_275 -> V_300 ) )
break;
return V_275 -> V_300 ( V_270 , V_303 , V_16 ) ;
}
return - V_289 ;
}
static int F_78 ( const struct V_274 * V_275 ,
struct V_270 * V_270 , void * V_303 , void * V_16 )
{
struct V_42 * V_19 = V_16 ;
struct V_272 * V_273 = F_61 ( V_270 ) ;
bool V_277 = V_273 -> V_278 == V_279 ;
bool V_282 = V_273 -> V_278 == V_283 ;
bool V_284 = V_273 -> V_285 != V_286 ;
bool V_287 = V_273 -> V_285 != V_288 ;
int V_305 ;
F_62 ( V_19 ) ;
switch ( V_19 -> type ) {
case V_55 :
if ( F_76 ( ! V_284 || ! V_277 || ! V_275 -> V_330 ) )
break;
F_79 ( V_19 , V_57 . V_44 ) ;
V_305 = V_275 -> V_330 ( V_270 , V_303 , V_16 ) ;
V_19 -> V_57 . V_44 . V_301 = V_302 ;
return V_305 ;
case V_67 :
if ( F_76 ( ! V_284 || ! V_277 || ! V_275 -> V_331 ) )
break;
F_79 ( V_19 , V_57 . V_69 ) ;
return V_275 -> V_331 ( V_270 , V_303 , V_16 ) ;
case V_73 :
if ( F_76 ( ! V_284 || ! V_277 || ! V_275 -> V_332 ) )
break;
F_79 ( V_19 , V_57 . V_52 ) ;
return V_275 -> V_332 ( V_270 , V_303 , V_16 ) ;
case V_83 :
if ( F_76 ( ! V_284 || V_277 || ! V_275 -> V_333 ) )
break;
F_79 ( V_19 , V_57 . V_48 ) ;
return V_275 -> V_333 ( V_270 , V_303 , V_16 ) ;
case V_91 :
if ( F_76 ( ! V_284 || V_277 || ! V_275 -> V_334 ) )
break;
F_79 ( V_19 , V_57 . V_50 ) ;
return V_275 -> V_334 ( V_270 , V_303 , V_16 ) ;
case V_56 :
if ( F_76 ( ! V_287 || ! V_277 || ! V_275 -> V_335 ) )
break;
F_79 ( V_19 , V_57 . V_44 ) ;
V_305 = V_275 -> V_335 ( V_270 , V_303 , V_16 ) ;
V_19 -> V_57 . V_44 . V_301 = V_302 ;
return V_305 ;
case V_68 :
if ( F_76 ( ! V_287 || ! V_277 || ! V_275 -> V_336 ) )
break;
F_79 ( V_19 , V_57 . V_69 ) ;
return V_275 -> V_336 ( V_270 , V_303 , V_16 ) ;
case V_74 :
if ( F_76 ( ! V_287 || ! V_277 || ! V_275 -> V_337 ) )
break;
F_79 ( V_19 , V_57 . V_52 ) ;
return V_275 -> V_337 ( V_270 , V_303 , V_16 ) ;
case V_84 :
if ( F_76 ( ! V_287 || V_277 || ! V_275 -> V_338 ) )
break;
F_79 ( V_19 , V_57 . V_48 ) ;
return V_275 -> V_338 ( V_270 , V_303 , V_16 ) ;
case V_92 :
if ( F_76 ( ! V_287 || V_277 || ! V_275 -> V_339 ) )
break;
F_79 ( V_19 , V_57 . V_50 ) ;
return V_275 -> V_339 ( V_270 , V_303 , V_16 ) ;
case V_96 :
if ( F_76 ( ! V_284 || ! V_282 || ! V_275 -> V_340 ) )
break;
F_79 ( V_19 , V_57 . V_54 ) ;
return V_275 -> V_340 ( V_270 , V_303 , V_16 ) ;
}
return - V_289 ;
}
static int F_80 ( const struct V_274 * V_275 ,
struct V_270 * V_270 , void * V_303 , void * V_16 )
{
struct V_42 * V_19 = V_16 ;
struct V_272 * V_273 = F_61 ( V_270 ) ;
bool V_277 = V_273 -> V_278 == V_279 ;
bool V_282 = V_273 -> V_278 == V_283 ;
bool V_284 = V_273 -> V_285 != V_286 ;
bool V_287 = V_273 -> V_285 != V_288 ;
int V_305 ;
F_62 ( V_19 ) ;
switch ( V_19 -> type ) {
case V_55 :
if ( F_76 ( ! V_284 || ! V_277 || ! V_275 -> V_341 ) )
break;
F_79 ( V_19 , V_57 . V_44 ) ;
V_305 = V_275 -> V_341 ( V_270 , V_303 , V_16 ) ;
V_19 -> V_57 . V_44 . V_301 = V_302 ;
return V_305 ;
case V_67 :
if ( F_76 ( ! V_284 || ! V_277 || ! V_275 -> V_342 ) )
break;
F_79 ( V_19 , V_57 . V_69 ) ;
return V_275 -> V_342 ( V_270 , V_303 , V_16 ) ;
case V_73 :
if ( F_76 ( ! V_284 || ! V_277 || ! V_275 -> V_343 ) )
break;
F_79 ( V_19 , V_57 . V_52 ) ;
return V_275 -> V_343 ( V_270 , V_303 , V_16 ) ;
case V_83 :
if ( F_76 ( ! V_284 || V_277 || ! V_275 -> V_344 ) )
break;
F_79 ( V_19 , V_57 . V_48 ) ;
return V_275 -> V_344 ( V_270 , V_303 , V_16 ) ;
case V_91 :
if ( F_76 ( ! V_284 || V_277 || ! V_275 -> V_345 ) )
break;
F_79 ( V_19 , V_57 . V_50 ) ;
return V_275 -> V_345 ( V_270 , V_303 , V_16 ) ;
case V_56 :
if ( F_76 ( ! V_287 || ! V_277 || ! V_275 -> V_346 ) )
break;
F_79 ( V_19 , V_57 . V_44 ) ;
V_305 = V_275 -> V_346 ( V_270 , V_303 , V_16 ) ;
V_19 -> V_57 . V_44 . V_301 = V_302 ;
return V_305 ;
case V_68 :
if ( F_76 ( ! V_287 || ! V_277 || ! V_275 -> V_347 ) )
break;
F_79 ( V_19 , V_57 . V_69 ) ;
return V_275 -> V_347 ( V_270 , V_303 , V_16 ) ;
case V_74 :
if ( F_76 ( ! V_287 || ! V_277 || ! V_275 -> V_348 ) )
break;
F_79 ( V_19 , V_57 . V_52 ) ;
return V_275 -> V_348 ( V_270 , V_303 , V_16 ) ;
case V_84 :
if ( F_76 ( ! V_287 || V_277 || ! V_275 -> V_349 ) )
break;
F_79 ( V_19 , V_57 . V_48 ) ;
return V_275 -> V_349 ( V_270 , V_303 , V_16 ) ;
case V_92 :
if ( F_76 ( ! V_287 || V_277 || ! V_275 -> V_350 ) )
break;
F_79 ( V_19 , V_57 . V_50 ) ;
return V_275 -> V_350 ( V_270 , V_303 , V_16 ) ;
case V_96 :
if ( F_76 ( ! V_284 || ! V_282 || ! V_275 -> V_351 ) )
break;
F_79 ( V_19 , V_57 . V_54 ) ;
return V_275 -> V_351 ( V_270 , V_303 , V_16 ) ;
}
return - V_289 ;
}
static int F_81 ( const struct V_274 * V_275 ,
struct V_270 * V_270 , void * V_303 , void * V_16 )
{
return V_275 -> V_352 ( V_270 , V_303 , * ( unsigned int * ) V_16 ) ;
}
static int F_82 ( const struct V_274 * V_275 ,
struct V_270 * V_270 , void * V_303 , void * V_16 )
{
return V_275 -> V_353 ( V_270 , V_303 , * ( unsigned int * ) V_16 ) ;
}
static int F_83 ( const struct V_274 * V_275 ,
struct V_270 * V_270 , void * V_303 , void * V_16 )
{
struct V_272 * V_273 = F_61 ( V_270 ) ;
struct V_103 * V_19 = V_16 ;
int V_354 ;
V_19 -> type = ( V_273 -> V_278 == V_355 ) ?
V_356 : V_357 ;
V_354 = V_275 -> V_358 ( V_270 , V_303 , V_19 ) ;
if ( ! V_354 )
V_19 -> V_35 |= V_359 ;
return V_354 ;
}
static int F_84 ( const struct V_274 * V_275 ,
struct V_270 * V_270 , void * V_303 , void * V_16 )
{
struct V_272 * V_273 = F_61 ( V_270 ) ;
struct V_103 * V_19 = V_16 ;
V_19 -> type = ( V_273 -> V_278 == V_355 ) ?
V_356 : V_357 ;
return V_275 -> V_360 ( V_270 , V_303 , V_19 ) ;
}
static int F_85 ( const struct V_274 * V_275 ,
struct V_270 * V_270 , void * V_303 , void * V_16 )
{
struct V_99 * V_19 = V_16 ;
int V_354 ;
V_354 = V_275 -> V_361 ( V_270 , V_303 , V_19 ) ;
if ( ! V_354 )
V_19 -> V_35 |= V_359 ;
return V_354 ;
}
static int F_86 ( const struct V_274 * V_275 ,
struct V_270 * V_270 , void * V_303 , void * V_16 )
{
struct V_272 * V_273 = F_61 ( V_270 ) ;
struct V_107 * V_19 = V_16 ;
if ( V_273 -> V_278 == V_283 )
V_19 -> type = V_362 ;
else
V_19 -> type = ( V_273 -> V_278 == V_355 ) ?
V_356 : V_357 ;
return V_275 -> V_363 ( V_270 , V_303 , V_19 ) ;
}
static int F_87 ( const struct V_274 * V_275 ,
struct V_270 * V_270 , void * V_303 , void * V_16 )
{
struct V_272 * V_273 = F_61 ( V_270 ) ;
const struct V_107 * V_19 = V_16 ;
enum V_364 type ;
if ( V_273 -> V_278 == V_283 ) {
if ( V_19 -> type != V_362 && V_19 -> type != V_365 )
return - V_289 ;
} else {
type = ( V_273 -> V_278 == V_355 ) ?
V_356 : V_357 ;
if ( type != V_19 -> type )
return - V_289 ;
}
return V_275 -> V_366 ( V_270 , V_303 , V_19 ) ;
}
static int F_88 ( const struct V_274 * V_275 ,
struct V_270 * V_270 , void * V_303 , void * V_16 )
{
struct V_272 * V_273 = F_61 ( V_270 ) ;
struct V_12 * V_19 = V_16 ;
T_1 V_1 = V_273 -> V_367 , V_368 = 0 ;
unsigned int V_27 = V_19 -> V_27 , V_3 , V_369 = 0 ;
const char * V_6 = L_119 ;
if ( V_1 == 0 )
return - V_370 ;
for ( V_3 = 0 ; V_3 <= V_27 && V_1 ; V_3 ++ ) {
while ( ( V_1 & V_4 [ V_369 ] . V_5 ) != V_4 [ V_369 ] . V_5 )
V_369 ++ ;
V_368 = V_4 [ V_369 ] . V_5 ;
V_6 = V_4 [ V_369 ] . V_6 ;
V_369 ++ ;
if ( V_368 == 0 )
break;
if ( V_368 != V_371 &&
V_368 != V_372 &&
V_368 != V_373 )
V_1 &= ~ V_368 ;
}
if ( V_3 <= V_27 )
return - V_289 ;
F_4 ( V_19 , V_368 , V_6 ) ;
return 0 ;
}
static int F_89 ( const struct V_274 * V_275 ,
struct V_270 * V_270 , void * V_303 , void * V_16 )
{
struct V_272 * V_273 = F_61 ( V_270 ) ;
T_1 V_1 = * ( T_1 * ) V_16 , V_374 ;
V_374 = V_1 & V_273 -> V_367 ;
if ( V_273 -> V_367 && ! V_374 )
return - V_289 ;
return V_275 -> V_375 ( V_270 , V_303 , V_374 ) ;
}
static int F_90 ( const struct V_274 * V_275 ,
struct V_270 * V_270 , void * V_303 , void * V_16 )
{
struct V_272 * V_273 = F_61 ( V_270 ) ;
T_1 * V_19 = V_16 ;
* V_19 = V_273 -> V_367 ;
return V_275 -> V_376 ( V_270 , V_303 , V_16 ) ;
}
static int F_91 ( const struct V_274 * V_275 ,
struct V_270 * V_270 , void * V_303 , void * V_16 )
{
struct V_272 * V_273 = F_61 ( V_270 ) ;
struct V_109 * V_19 = V_16 ;
enum V_364 type ;
if ( V_273 -> V_278 == V_283 )
return - V_289 ;
type = ( V_273 -> V_278 == V_355 ) ?
V_356 : V_357 ;
if ( V_19 -> type != type )
return - V_289 ;
return V_275 -> V_377 ( V_270 , V_303 , V_19 ) ;
}
static int F_92 ( const struct V_274 * V_275 ,
struct V_270 * V_270 , void * V_303 , void * V_16 )
{
return V_275 -> V_378 ( V_270 , V_303 , * ( unsigned int * ) V_16 ) ;
}
static int F_93 ( const struct V_274 * V_275 ,
struct V_270 * V_270 , void * V_303 , void * V_16 )
{
struct V_113 * V_19 = V_16 ;
int V_305 = F_60 ( V_270 , V_19 -> type ) ;
if ( V_305 )
return V_305 ;
F_79 ( V_19 , V_114 ) ;
return V_275 -> V_379 ( V_270 , V_303 , V_19 ) ;
}
static int F_94 ( const struct V_274 * V_275 ,
struct V_270 * V_270 , void * V_303 , void * V_16 )
{
struct V_116 * V_19 = V_16 ;
int V_305 = F_60 ( V_270 , V_19 -> type ) ;
return V_305 ? V_305 : V_275 -> V_380 ( V_270 , V_303 , V_19 ) ;
}
static int F_95 ( const struct V_274 * V_275 ,
struct V_270 * V_270 , void * V_303 , void * V_16 )
{
struct V_116 * V_19 = V_16 ;
int V_305 = F_60 ( V_270 , V_19 -> type ) ;
return V_305 ? V_305 : V_275 -> V_381 ( V_270 , V_303 , V_19 ) ;
}
static int F_96 ( const struct V_274 * V_275 ,
struct V_270 * V_270 , void * V_303 , void * V_16 )
{
struct V_116 * V_19 = V_16 ;
int V_305 = F_60 ( V_270 , V_19 -> type ) ;
return V_305 ? V_305 : V_275 -> V_382 ( V_270 , V_303 , V_19 ) ;
}
static int F_97 ( const struct V_274 * V_275 ,
struct V_270 * V_270 , void * V_303 , void * V_16 )
{
struct V_140 * V_383 = V_16 ;
int V_305 = F_60 ( V_270 , V_383 -> V_141 . type ) ;
if ( V_305 )
return V_305 ;
F_62 ( & V_383 -> V_141 ) ;
V_305 = V_275 -> V_384 ( V_270 , V_303 , V_383 ) ;
if ( V_383 -> V_141 . type == V_55 ||
V_383 -> V_141 . type == V_56 )
V_383 -> V_141 . V_57 . V_44 . V_301 = V_302 ;
return V_305 ;
}
static int F_98 ( const struct V_274 * V_275 ,
struct V_270 * V_270 , void * V_303 , void * V_16 )
{
struct V_116 * V_385 = V_16 ;
int V_305 = F_60 ( V_270 , V_385 -> type ) ;
return V_305 ? V_305 : V_275 -> V_386 ( V_270 , V_303 , V_385 ) ;
}
static int F_99 ( const struct V_274 * V_275 ,
struct V_270 * V_270 , void * V_303 , void * V_16 )
{
struct V_142 * V_19 = V_16 ;
T_1 V_5 ;
int V_305 = F_60 ( V_270 , V_19 -> type ) ;
if ( V_305 )
return V_305 ;
if ( V_275 -> V_387 )
return V_275 -> V_387 ( V_270 , V_303 , V_19 ) ;
if ( V_19 -> type != V_55 &&
V_19 -> type != V_67 )
return - V_289 ;
V_19 -> V_145 . V_146 . V_150 = 2 ;
V_305 = V_275 -> V_388 ( V_270 , V_303 , & V_5 ) ;
if ( V_305 == 0 )
F_3 ( V_5 , & V_19 -> V_145 . V_146 . V_148 ) ;
return V_305 ;
}
static int F_100 ( const struct V_274 * V_275 ,
struct V_270 * V_270 , void * V_303 , void * V_16 )
{
struct V_142 * V_19 = V_16 ;
int V_305 = F_60 ( V_270 , V_19 -> type ) ;
return V_305 ? V_305 : V_275 -> V_389 ( V_270 , V_303 , V_19 ) ;
}
static int F_101 ( const struct V_274 * V_275 ,
struct V_270 * V_270 , void * V_303 , void * V_16 )
{
struct V_272 * V_273 = F_61 ( V_270 ) ;
struct V_155 * V_19 = V_16 ;
struct V_314 * V_315 =
F_102 ( V_390 , & V_273 -> V_39 ) ? V_303 : NULL ;
if ( V_315 && V_315 -> V_391 )
return V_155 ( V_315 -> V_391 , V_19 ) ;
if ( V_273 -> V_391 )
return V_155 ( V_273 -> V_391 , V_19 ) ;
if ( V_275 -> V_392 )
return V_275 -> V_392 ( V_270 , V_303 , V_19 ) ;
return - V_393 ;
}
static int F_103 ( const struct V_274 * V_275 ,
struct V_270 * V_270 , void * V_303 , void * V_16 )
{
struct V_272 * V_273 = F_61 ( V_270 ) ;
struct V_160 * V_19 = V_16 ;
struct V_314 * V_315 =
F_102 ( V_390 , & V_273 -> V_39 ) ? V_303 : NULL ;
if ( V_315 && V_315 -> V_391 )
return V_160 ( V_315 -> V_391 , V_19 ) ;
if ( V_273 -> V_391 )
return V_160 ( V_273 -> V_391 , V_19 ) ;
if ( V_275 -> V_394 )
return V_275 -> V_394 ( V_270 , V_303 , V_19 ) ;
return - V_393 ;
}
static int F_104 ( const struct V_274 * V_275 ,
struct V_270 * V_270 , void * V_303 , void * V_16 )
{
struct V_272 * V_273 = F_61 ( V_270 ) ;
struct V_165 * V_19 = V_16 ;
struct V_314 * V_315 =
F_102 ( V_390 , & V_273 -> V_39 ) ? V_303 : NULL ;
if ( V_315 && V_315 -> V_391 )
return V_165 ( V_315 -> V_391 , V_19 ) ;
if ( V_273 -> V_391 )
return V_165 ( V_273 -> V_391 , V_19 ) ;
if ( V_275 -> V_395 )
return V_275 -> V_395 ( V_270 , V_303 , V_19 ) ;
return - V_393 ;
}
static int F_105 ( const struct V_274 * V_275 ,
struct V_270 * V_270 , void * V_303 , void * V_16 )
{
struct V_272 * V_273 = F_61 ( V_270 ) ;
struct V_166 * V_19 = V_16 ;
struct V_314 * V_315 =
F_102 ( V_390 , & V_273 -> V_39 ) ? V_303 : NULL ;
struct V_168 V_396 ;
struct V_397 V_251 ;
if ( V_315 && V_315 -> V_391 )
return F_106 ( V_315 -> V_391 , V_19 ) ;
if ( V_273 -> V_391 )
return F_106 ( V_273 -> V_391 , V_19 ) ;
if ( V_275 -> V_398 )
return V_275 -> V_398 ( V_270 , V_303 , V_19 ) ;
if ( V_275 -> V_399 == NULL )
return - V_393 ;
V_396 . V_169 = F_59 ( V_19 -> V_1 ) ;
V_396 . V_90 = 1 ;
V_396 . V_171 = & V_251 ;
V_251 . V_1 = V_19 -> V_1 ;
V_251 . V_167 = V_19 -> V_167 ;
if ( F_58 ( & V_396 , 1 ) ) {
int V_305 = V_275 -> V_399 ( V_270 , V_303 , & V_396 ) ;
if ( V_305 == 0 )
V_19 -> V_167 = V_251 . V_167 ;
return V_305 ;
}
return - V_289 ;
}
static int F_107 ( const struct V_274 * V_275 ,
struct V_270 * V_270 , void * V_303 , void * V_16 )
{
struct V_272 * V_273 = F_61 ( V_270 ) ;
struct V_166 * V_19 = V_16 ;
struct V_314 * V_315 =
F_102 ( V_390 , & V_273 -> V_39 ) ? V_303 : NULL ;
struct V_168 V_396 ;
struct V_397 V_251 ;
if ( V_315 && V_315 -> V_391 )
return F_108 ( V_315 , V_315 -> V_391 , V_19 ) ;
if ( V_273 -> V_391 )
return F_108 ( NULL , V_273 -> V_391 , V_19 ) ;
if ( V_275 -> V_400 )
return V_275 -> V_400 ( V_270 , V_303 , V_19 ) ;
if ( V_275 -> V_401 == NULL )
return - V_393 ;
V_396 . V_169 = F_59 ( V_19 -> V_1 ) ;
V_396 . V_90 = 1 ;
V_396 . V_171 = & V_251 ;
V_251 . V_1 = V_19 -> V_1 ;
V_251 . V_167 = V_19 -> V_167 ;
if ( F_58 ( & V_396 , 1 ) )
return V_275 -> V_401 ( V_270 , V_303 , & V_396 ) ;
return - V_289 ;
}
static int F_109 ( const struct V_274 * V_275 ,
struct V_270 * V_270 , void * V_303 , void * V_16 )
{
struct V_272 * V_273 = F_61 ( V_270 ) ;
struct V_168 * V_19 = V_16 ;
struct V_314 * V_315 =
F_102 ( V_390 , & V_273 -> V_39 ) ? V_303 : NULL ;
V_19 -> V_170 = V_19 -> V_90 ;
if ( V_315 && V_315 -> V_391 )
return F_110 ( V_315 -> V_391 , V_19 ) ;
if ( V_273 -> V_391 )
return F_110 ( V_273 -> V_391 , V_19 ) ;
if ( V_275 -> V_399 == NULL )
return - V_393 ;
return F_58 ( V_19 , 0 ) ? V_275 -> V_399 ( V_270 , V_303 , V_19 ) :
- V_289 ;
}
static int F_111 ( const struct V_274 * V_275 ,
struct V_270 * V_270 , void * V_303 , void * V_16 )
{
struct V_272 * V_273 = F_61 ( V_270 ) ;
struct V_168 * V_19 = V_16 ;
struct V_314 * V_315 =
F_102 ( V_390 , & V_273 -> V_39 ) ? V_303 : NULL ;
V_19 -> V_170 = V_19 -> V_90 ;
if ( V_315 && V_315 -> V_391 )
return F_112 ( V_315 , V_315 -> V_391 , V_19 ) ;
if ( V_273 -> V_391 )
return F_112 ( NULL , V_273 -> V_391 , V_19 ) ;
if ( V_275 -> V_401 == NULL )
return - V_393 ;
return F_58 ( V_19 , 0 ) ? V_275 -> V_401 ( V_270 , V_303 , V_19 ) :
- V_289 ;
}
static int F_113 ( const struct V_274 * V_275 ,
struct V_270 * V_270 , void * V_303 , void * V_16 )
{
struct V_272 * V_273 = F_61 ( V_270 ) ;
struct V_168 * V_19 = V_16 ;
struct V_314 * V_315 =
F_102 ( V_390 , & V_273 -> V_39 ) ? V_303 : NULL ;
V_19 -> V_170 = V_19 -> V_90 ;
if ( V_315 && V_315 -> V_391 )
return F_114 ( V_315 -> V_391 , V_19 ) ;
if ( V_273 -> V_391 )
return F_114 ( V_273 -> V_391 , V_19 ) ;
if ( V_275 -> V_402 == NULL )
return - V_393 ;
return F_58 ( V_19 , 0 ) ? V_275 -> V_402 ( V_270 , V_303 , V_19 ) :
- V_289 ;
}
static int F_115 ( const struct V_274 * V_275 ,
struct V_270 * V_270 , void * V_303 , void * V_16 )
{
struct V_177 * V_19 = V_16 ;
struct V_178 V_403 = {
. type = V_19 -> type ,
} ;
int V_305 ;
if ( V_275 -> V_404 )
return V_275 -> V_404 ( V_270 , V_303 , V_19 ) ;
if ( F_116 ( V_19 -> type ) )
V_403 . V_179 = V_405 ;
else
V_403 . V_179 = V_406 ;
V_305 = V_275 -> V_407 ( V_270 , V_303 , & V_403 ) ;
if ( ! V_305 )
V_19 -> V_144 = V_403 . V_180 ;
return V_305 ;
}
static int F_117 ( const struct V_274 * V_275 ,
struct V_270 * V_270 , void * V_303 , void * V_16 )
{
struct V_177 * V_19 = V_16 ;
struct V_178 V_403 = {
. type = V_19 -> type ,
. V_180 = V_19 -> V_144 ,
} ;
if ( V_275 -> V_408 )
return V_275 -> V_408 ( V_270 , V_303 , V_19 ) ;
if ( F_116 ( V_19 -> type ) )
V_403 . V_179 = V_405 ;
else
V_403 . V_179 = V_406 ;
return V_275 -> V_409 ( V_270 , V_303 , & V_403 ) ;
}
static int F_118 ( const struct V_274 * V_275 ,
struct V_270 * V_270 , void * V_303 , void * V_16 )
{
struct V_173 * V_19 = V_16 ;
if ( V_275 -> V_407 ) {
struct V_178 V_403 = { . type = V_19 -> type } ;
int V_305 ;
if ( F_116 ( V_19 -> type ) )
V_403 . V_179 = V_410 ;
else
V_403 . V_179 = V_411 ;
V_305 = V_275 -> V_407 ( V_270 , V_303 , & V_403 ) ;
if ( V_305 )
return V_305 ;
V_19 -> V_174 = V_403 . V_180 ;
if ( F_116 ( V_19 -> type ) )
V_403 . V_179 = V_412 ;
else
V_403 . V_179 = V_413 ;
V_305 = V_275 -> V_407 ( V_270 , V_303 , & V_403 ) ;
if ( V_305 )
return V_305 ;
V_19 -> V_175 = V_403 . V_180 ;
}
V_19 -> V_176 . V_10 = 1 ;
V_19 -> V_176 . V_11 = 1 ;
if ( V_275 -> V_414 )
return V_275 -> V_414 ( V_270 , V_303 , V_19 ) ;
return 0 ;
}
static int F_119 ( const struct V_274 * V_275 ,
struct V_270 * V_270 , void * V_303 , void * V_16 )
{
struct V_272 * V_273 = F_61 ( V_270 ) ;
int V_305 ;
if ( V_273 -> V_415 )
F_42 ( L_120 ,
V_273 -> V_415 -> V_14 ) ;
V_305 = V_275 -> V_416 ( V_270 , V_303 ) ;
if ( V_273 -> V_415 )
F_42 ( L_121 ,
V_273 -> V_415 -> V_14 ) ;
return V_305 ;
}
static int F_120 ( const struct V_274 * V_275 ,
struct V_270 * V_270 , void * V_303 , void * V_16 )
{
#ifdef F_121
struct V_202 * V_19 = V_16 ;
struct V_272 * V_273 = F_61 ( V_270 ) ;
struct V_417 * V_418 ;
int V_419 = 0 ;
if ( ! F_122 ( V_420 ) )
return - V_421 ;
if ( V_19 -> V_199 . type == V_422 ) {
if ( V_273 -> V_415 == NULL )
return - V_289 ;
F_123 (sd, vfd->v4l2_dev)
if ( V_19 -> V_199 . V_201 == V_419 ++ )
return F_124 ( V_418 , V_423 , V_424 , V_19 ) ;
return - V_289 ;
}
if ( V_275 -> V_425 && V_19 -> V_199 . type == V_426 &&
( V_275 -> V_427 || V_19 -> V_199 . V_201 == 0 ) )
return V_275 -> V_425 ( V_270 , V_303 , V_19 ) ;
return - V_289 ;
#else
return - V_393 ;
#endif
}
static int F_125 ( const struct V_274 * V_275 ,
struct V_270 * V_270 , void * V_303 , void * V_16 )
{
#ifdef F_121
const struct V_202 * V_19 = V_16 ;
struct V_272 * V_273 = F_61 ( V_270 ) ;
struct V_417 * V_418 ;
int V_419 = 0 ;
if ( ! F_122 ( V_420 ) )
return - V_421 ;
if ( V_19 -> V_199 . type == V_422 ) {
if ( V_273 -> V_415 == NULL )
return - V_289 ;
F_123 (sd, vfd->v4l2_dev)
if ( V_19 -> V_199 . V_201 == V_419 ++ )
return F_124 ( V_418 , V_423 , V_428 , V_19 ) ;
return - V_289 ;
}
if ( V_275 -> V_429 && V_19 -> V_199 . type == V_426 &&
( V_275 -> V_427 || V_19 -> V_199 . V_201 == 0 ) )
return V_275 -> V_429 ( V_270 , V_303 , V_19 ) ;
return - V_289 ;
#else
return - V_393 ;
#endif
}
static int F_126 ( const struct V_274 * V_275 ,
struct V_270 * V_270 , void * V_303 , void * V_16 )
{
#ifdef F_121
struct V_272 * V_273 = F_61 ( V_270 ) ;
struct V_198 * V_19 = V_16 ;
struct V_417 * V_418 ;
int V_419 = 0 ;
switch ( V_19 -> V_199 . type ) {
case V_426 :
if ( V_275 -> V_429 )
V_19 -> V_39 |= V_430 ;
if ( V_275 -> V_425 )
V_19 -> V_39 |= V_431 ;
F_5 ( V_19 -> V_14 , V_273 -> V_415 -> V_14 , sizeof( V_19 -> V_14 ) ) ;
if ( V_275 -> V_427 )
return V_275 -> V_427 ( V_270 , V_303 , V_16 ) ;
if ( V_19 -> V_199 . V_201 )
return - V_289 ;
return 0 ;
case V_422 :
if ( V_273 -> V_415 == NULL )
break;
F_123 (sd, vfd->v4l2_dev) {
if ( V_19 -> V_199 . V_201 != V_419 ++ )
continue;
if ( V_418 -> V_275 -> V_423 && V_418 -> V_275 -> V_423 -> V_428 )
V_19 -> V_39 |= V_430 ;
if ( V_418 -> V_275 -> V_423 && V_418 -> V_275 -> V_423 -> V_424 )
V_19 -> V_39 |= V_431 ;
F_5 ( V_19 -> V_14 , V_418 -> V_14 , sizeof( V_19 -> V_14 ) ) ;
return 0 ;
}
break;
}
return - V_289 ;
#else
return - V_393 ;
#endif
}
static int F_127 ( const struct V_274 * V_275 ,
struct V_270 * V_270 , void * V_303 , void * V_16 )
{
return F_128 ( V_303 , V_16 , V_270 -> V_432 & V_433 ) ;
}
static int F_129 ( const struct V_274 * V_275 ,
struct V_270 * V_270 , void * V_303 , void * V_16 )
{
return V_275 -> V_434 ( V_303 , V_16 ) ;
}
static int F_130 ( const struct V_274 * V_275 ,
struct V_270 * V_270 , void * V_303 , void * V_16 )
{
return V_275 -> V_435 ( V_303 , V_16 ) ;
}
static int F_131 ( const struct V_274 * V_275 ,
struct V_270 * V_270 , void * V_303 , void * V_16 )
{
struct V_259 * V_19 = V_16 ;
int V_305 = F_60 ( V_270 , V_19 -> type ) ;
if ( V_305 )
return V_305 ;
memset ( V_19 , 0 , F_63 ( struct V_259 , type ) ) ;
return V_275 -> V_436 ( V_270 , V_303 , V_19 ) ;
}
static int F_132 ( const struct V_274 * V_275 ,
struct V_270 * V_270 , void * V_303 , void * V_16 )
{
struct V_272 * V_273 = F_61 ( V_270 ) ;
struct V_260 * V_19 = V_16 ;
enum V_364 type ;
int V_354 ;
if ( V_273 -> V_278 == V_283 ) {
if ( V_19 -> type != V_362 && V_19 -> type != V_365 )
return - V_289 ;
type = V_19 -> type ;
} else {
type = ( V_273 -> V_278 == V_355 ) ?
V_356 : V_357 ;
if ( type != V_19 -> type )
return - V_289 ;
}
if ( V_275 -> V_437 ) {
V_354 = V_275 -> V_437 ( V_270 , V_303 , V_19 ) ;
if ( V_354 != - V_393 )
return V_354 ;
}
if ( F_73 ( V_273 , V_438 ) ) {
struct V_103 V_439 = {
. V_27 = V_19 -> V_29 ,
. type = type ,
} ;
if ( V_19 -> V_27 )
return - V_289 ;
V_354 = V_275 -> V_358 ( V_270 , V_303 , & V_439 ) ;
if ( V_354 )
return V_354 ;
V_19 -> V_35 = V_439 . V_35 | V_359 ;
V_19 -> V_101 = V_439 . V_101 ;
V_19 -> V_102 = V_439 . V_102 ;
V_19 -> V_261 = ( type == V_356 ) ?
V_440 : V_441 ;
return 0 ;
}
if ( F_73 ( V_273 , V_442 ) ) {
struct V_99 V_126 = {
. V_27 = V_19 -> V_29 ,
} ;
if ( type != V_356 )
return - V_289 ;
if ( V_19 -> V_27 )
return - V_289 ;
V_354 = V_275 -> V_361 ( V_270 , V_303 , & V_126 ) ;
if ( V_354 )
return V_354 ;
V_19 -> V_35 = V_126 . V_35 | V_359 ;
V_19 -> V_101 = V_126 . V_101 ;
V_19 -> V_102 = V_126 . V_102 ;
V_19 -> V_261 = ( type == V_356 ) ?
V_440 : V_441 ;
return 0 ;
}
return - V_393 ;
}
bool F_133 ( unsigned int V_191 )
{
if ( F_134 ( V_191 ) >= V_443 )
return false ;
return V_444 [ F_134 ( V_191 ) ] . V_445 == V_191 ;
}
struct V_446 * F_135 ( struct V_272 * V_447 , unsigned V_191 )
{
if ( F_134 ( V_191 ) >= V_443 )
return V_447 -> V_448 ;
if ( F_102 ( F_134 ( V_191 ) , V_447 -> V_449 ) )
return NULL ;
if ( V_447 -> V_450 && V_447 -> V_450 -> V_448 &&
( V_444 [ F_134 ( V_191 ) ] . V_39 & V_451 ) )
return V_447 -> V_450 -> V_448 ;
return V_447 -> V_448 ;
}
void F_136 ( const char * V_452 , unsigned int V_191 )
{
const char * V_453 , * type ;
if ( V_452 )
F_15 ( V_71 L_122 , V_452 ) ;
switch ( F_137 ( V_191 ) ) {
case 'd' :
type = L_123 ;
break;
case 'V' :
if ( F_134 ( V_191 ) >= V_443 ) {
type = L_124 ;
break;
}
F_7 ( L_125 , V_444 [ F_134 ( V_191 ) ] . V_14 ) ;
return;
default:
type = L_126 ;
break;
}
switch ( F_138 ( V_191 ) ) {
case V_454 : V_453 = L_127 ; break;
case V_455 : V_453 = L_128 ; break;
case V_456 : V_453 = L_129 ; break;
case V_455 | V_456 : V_453 = L_130 ; break;
default: V_453 = L_131 ; break;
}
F_7 ( L_132 ,
type , F_137 ( V_191 ) , V_453 , F_134 ( V_191 ) , V_191 ) ;
}
static long F_139 ( struct V_270 * V_270 ,
unsigned int V_191 , void * V_16 )
{
struct V_272 * V_273 = F_61 ( V_270 ) ;
const struct V_274 * V_275 = V_273 -> V_276 ;
bool V_17 = false ;
struct V_457 V_458 ;
const struct V_457 * V_459 ;
void * V_303 = V_270 -> V_317 ;
struct V_314 * V_315 = NULL ;
int V_460 = V_273 -> V_460 ;
long V_305 = - V_393 ;
if ( V_275 == NULL ) {
F_140 ( L_133 ,
F_141 ( V_273 ) ) ;
return V_305 ;
}
if ( F_102 ( V_390 , & V_273 -> V_39 ) )
V_315 = V_270 -> V_317 ;
if ( F_133 ( V_191 ) ) {
V_459 = & V_444 [ F_134 ( V_191 ) ] ;
if ( ! F_102 ( F_134 ( V_191 ) , V_273 -> V_461 ) &&
! ( ( V_459 -> V_39 & V_462 ) && V_315 && V_315 -> V_391 ) )
goto V_463;
if ( V_315 && ( V_459 -> V_39 & V_464 ) ) {
V_305 = F_142 ( V_273 -> V_313 , V_315 -> V_313 ) ;
if ( V_305 )
goto V_463;
}
} else {
V_458 . V_445 = V_191 ;
V_458 . V_39 = 0 ;
V_458 . V_465 = F_57 ;
V_459 = & V_458 ;
}
V_17 = F_138 ( V_191 ) == V_456 ;
if ( V_459 -> V_39 & V_466 ) {
typedef int (* F_143)( struct V_270 * V_270 , void * V_303 , void * V_19 );
const void * V_19 = V_273 -> V_276 ;
const F_143 * V_467 = V_19 + V_459 -> V_249 . V_86 ;
V_305 = (* V_467)( V_270 , V_303 , V_16 ) ;
} else if ( V_459 -> V_39 & V_468 ) {
V_305 = V_459 -> V_249 . V_469 ( V_275 , V_270 , V_303 , V_16 ) ;
} else if ( ! V_275 -> V_470 ) {
V_305 = - V_393 ;
} else {
V_305 = V_275 -> V_470 ( V_270 , V_303 ,
V_315 ? F_142 ( V_273 -> V_313 , V_315 -> V_313 ) >= 0 : 0 ,
V_191 , V_16 ) ;
}
V_463:
if ( V_460 & ( V_471 | V_472 ) ) {
if ( ! ( V_460 & V_473 ) &&
( V_191 == V_474 || V_191 == V_475 ) )
return V_305 ;
F_136 ( F_141 ( V_273 ) , V_191 ) ;
if ( V_305 < 0 )
F_7 ( L_134 , V_305 ) ;
if ( ! ( V_460 & V_472 ) )
F_7 ( L_46 ) ;
else if ( F_138 ( V_191 ) == V_454 )
V_459 -> V_465 ( V_16 , V_17 ) ;
else {
F_7 ( L_135 ) ;
V_459 -> V_465 ( V_16 , V_17 ) ;
}
}
return V_305 ;
}
static int F_144 ( unsigned int V_191 , void * V_476 , T_4 * V_477 ,
void T_3 * * V_478 , void * * * V_479 )
{
int V_305 = 0 ;
switch ( V_191 ) {
case V_480 :
case V_481 :
case V_474 :
case V_475 : {
struct V_116 * V_482 = V_476 ;
if ( F_26 ( V_482 -> type ) && V_482 -> V_128 > 0 ) {
if ( V_482 -> V_128 > V_483 ) {
V_305 = - V_289 ;
break;
}
* V_478 = ( void T_3 * ) V_482 -> V_126 . V_127 ;
* V_479 = ( void * * ) & V_482 -> V_126 . V_127 ;
* V_477 = sizeof( struct V_120 ) * V_482 -> V_128 ;
V_305 = 1 ;
}
break;
}
case V_484 :
case V_485 : {
struct V_262 * V_486 = V_476 ;
if ( V_486 -> V_265 ) {
if ( V_486 -> V_265 > 256 ) {
V_305 = - V_289 ;
break;
}
* V_478 = ( void T_3 * ) V_486 -> V_486 ;
* V_479 = ( void * * ) & V_486 -> V_486 ;
* V_477 = V_486 -> V_265 * 128 ;
V_305 = 1 ;
}
break;
}
case V_487 :
case V_488 :
case V_489 : {
struct V_168 * V_396 = V_476 ;
if ( V_396 -> V_90 != 0 ) {
if ( V_396 -> V_90 > V_490 ) {
V_305 = - V_289 ;
break;
}
* V_478 = ( void T_3 * ) V_396 -> V_171 ;
* V_479 = ( void * * ) & V_396 -> V_171 ;
* V_477 = sizeof( struct V_397 )
* V_396 -> V_90 ;
V_305 = 1 ;
}
break;
}
}
return V_305 ;
}
long
F_145 ( struct V_270 * V_270 , unsigned int V_191 , unsigned long V_16 ,
T_5 V_469 )
{
char V_491 [ 128 ] ;
void * V_492 = NULL ;
void * V_476 = ( void * ) V_16 ;
long V_354 = - V_289 ;
bool V_493 ;
T_4 V_477 = 0 ;
void T_3 * V_478 = NULL ;
void * * V_479 = NULL ;
if ( F_138 ( V_191 ) != V_454 ) {
if ( F_146 ( V_191 ) <= sizeof( V_491 ) ) {
V_476 = V_491 ;
} else {
V_492 = F_147 ( F_146 ( V_191 ) , V_494 ) ;
if ( NULL == V_492 )
return - V_495 ;
V_476 = V_492 ;
}
V_354 = - V_496 ;
if ( F_138 ( V_191 ) & V_456 ) {
unsigned int V_497 = F_146 ( V_191 ) ;
if ( F_133 ( V_191 ) ) {
T_2 V_39 = V_444 [ F_134 ( V_191 ) ] . V_39 ;
if ( V_39 & V_498 )
V_497 = ( V_39 & V_498 ) >> 16 ;
}
if ( F_148 ( V_476 , ( void T_3 * ) V_16 , V_497 ) )
goto V_499;
if ( V_497 < F_146 ( V_191 ) )
memset ( ( V_500 * ) V_476 + V_497 , 0 , F_146 ( V_191 ) - V_497 ) ;
} else {
memset ( V_476 , 0 , F_146 ( V_191 ) ) ;
}
}
V_354 = F_144 ( V_191 , V_476 , & V_477 , & V_478 , & V_479 ) ;
if ( V_354 < 0 )
goto V_499;
V_493 = V_354 ;
if ( V_493 ) {
V_492 = F_147 ( V_477 , V_494 ) ;
V_354 = - V_495 ;
if ( NULL == V_492 )
goto V_501;
V_354 = - V_496 ;
if ( F_148 ( V_492 , V_478 , V_477 ) )
goto V_501;
* V_479 = V_492 ;
}
V_354 = V_469 ( V_270 , V_191 , V_476 ) ;
if ( V_354 == - V_502 )
V_354 = - V_393 ;
if ( V_354 == 0 ) {
if ( V_191 == V_475 )
F_149 ( F_61 ( V_270 ) -> V_503 , V_476 ) ;
else if ( V_191 == V_474 )
F_150 ( F_61 ( V_270 ) -> V_503 , V_476 ) ;
}
if ( V_493 ) {
* V_479 = ( void V_504 * ) V_478 ;
if ( F_151 ( V_478 , V_492 , V_477 ) )
V_354 = - V_496 ;
goto V_501;
}
if ( V_354 < 0 && V_191 != V_505 )
goto V_499;
V_501:
switch ( F_138 ( V_191 ) ) {
case V_455 :
case ( V_456 | V_455 ) :
if ( F_151 ( ( void T_3 * ) V_16 , V_476 , F_146 ( V_191 ) ) )
V_354 = - V_496 ;
break;
}
V_499:
F_152 ( V_492 ) ;
return V_354 ;
}
long F_153 ( struct V_270 * V_270 ,
unsigned int V_191 , unsigned long V_16 )
{
return F_145 ( V_270 , V_191 , V_16 , F_139 ) ;
}
