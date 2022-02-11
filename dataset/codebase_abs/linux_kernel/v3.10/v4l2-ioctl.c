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
unsigned V_3 ;
F_7 ( L_11 , F_13 ( V_19 -> type , V_38 ) ) ;
switch ( V_19 -> type ) {
case V_53 :
case V_54 :
V_44 = & V_19 -> V_55 . V_44 ;
F_7 ( L_12
L_13
L_14 ,
V_44 -> V_56 , V_44 -> V_57 ,
( V_44 -> V_40 & 0xff ) ,
( V_44 -> V_40 >> 8 ) & 0xff ,
( V_44 -> V_40 >> 16 ) & 0xff ,
( V_44 -> V_40 >> 24 ) & 0xff ,
F_13 ( V_44 -> V_58 , V_59 ) ,
V_44 -> V_60 , V_44 -> V_61 ,
V_44 -> V_62 ) ;
break;
case V_63 :
case V_64 :
V_46 = & V_19 -> V_55 . V_65 ;
F_7 ( L_12
L_15
L_16 ,
V_46 -> V_56 , V_46 -> V_57 ,
( V_46 -> V_40 & 0xff ) ,
( V_46 -> V_40 >> 8 ) & 0xff ,
( V_46 -> V_40 >> 16 ) & 0xff ,
( V_46 -> V_40 >> 24 ) & 0xff ,
F_13 ( V_46 -> V_58 , V_59 ) ,
V_46 -> V_62 , V_46 -> V_66 ) ;
for ( V_3 = 0 ; V_3 < V_46 -> V_66 ; V_3 ++ )
F_15 ( V_67 L_17 , V_3 ,
V_46 -> V_68 [ V_3 ] . V_60 ,
V_46 -> V_68 [ V_3 ] . V_61 ) ;
break;
case V_69 :
case V_70 :
V_52 = & V_19 -> V_55 . V_52 ;
F_7 ( L_18 ,
V_52 -> V_71 . V_56 , V_52 -> V_71 . V_57 , V_52 -> V_71 . V_72 , V_52 -> V_71 . V_73 ,
F_13 ( V_52 -> V_58 , V_59 ) ,
V_52 -> V_74 , V_52 -> V_75 , V_52 -> V_76 ,
V_52 -> V_77 , V_52 -> V_78 ) ;
break;
case V_79 :
case V_80 :
V_48 = & V_19 -> V_55 . V_48 ;
F_7 ( L_19
L_20 ,
V_48 -> V_81 , V_48 -> V_82 ,
V_48 -> V_83 ,
( V_48 -> V_84 & 0xff ) ,
( V_48 -> V_84 >> 8 ) & 0xff ,
( V_48 -> V_84 >> 16 ) & 0xff ,
( V_48 -> V_84 >> 24 ) & 0xff ,
V_48 -> V_85 [ 0 ] , V_48 -> V_85 [ 1 ] ,
V_48 -> V_86 [ 0 ] , V_48 -> V_86 [ 1 ] ) ;
break;
case V_87 :
case V_88 :
V_50 = & V_19 -> V_55 . V_50 ;
F_7 ( L_21 ,
V_50 -> V_89 , V_50 -> V_90 ) ;
for ( V_3 = 0 ; V_3 < 24 ; V_3 ++ )
F_15 ( V_67 L_22 , V_3 ,
V_50 -> V_91 [ 0 ] [ V_3 ] ,
V_50 -> V_91 [ 1 ] [ V_3 ] ) ;
break;
}
}
static void F_16 ( const void * V_16 , bool V_17 )
{
const struct V_92 * V_19 = V_16 ;
F_7 ( L_23
L_24
L_14 ,
V_19 -> V_35 , V_19 -> V_39 , V_19 -> V_93 ,
V_19 -> V_55 . V_56 , V_19 -> V_55 . V_57 ,
( V_19 -> V_55 . V_40 & 0xff ) ,
( V_19 -> V_55 . V_40 >> 8 ) & 0xff ,
( V_19 -> V_55 . V_40 >> 16 ) & 0xff ,
( V_19 -> V_55 . V_40 >> 24 ) & 0xff ,
V_19 -> V_55 . V_60 , V_19 -> V_55 . V_61 ,
V_19 -> V_55 . V_62 ) ;
}
static void F_17 ( const void * V_16 , bool V_17 )
{
F_7 ( L_25 , F_13 ( * ( T_2 * ) V_16 , V_38 ) ) ;
}
static void F_18 ( const void * V_16 , bool V_17 )
{
const struct V_94 * V_19 = V_16 ;
if ( V_17 )
F_7 ( L_26 , V_19 -> V_27 , V_19 -> V_95 ) ;
else
F_7 ( L_27
L_28 ,
V_19 -> V_27 , ( int ) sizeof( V_19 -> V_14 ) , V_19 -> V_14 , V_19 -> V_35 ,
V_19 -> V_96 , V_19 -> V_97 , V_19 -> V_95 ) ;
}
static void F_19 ( const void * V_16 , bool V_17 )
{
const struct V_98 * V_19 = V_16 ;
if ( V_17 )
F_7 ( L_29 , V_19 -> V_27 , V_19 -> V_99 ) ;
else
F_7 ( L_30
L_31
L_32 ,
V_19 -> V_27 , ( int ) sizeof( V_19 -> V_14 ) , V_19 -> V_14 , V_19 -> type ,
V_19 -> V_35 , V_19 -> V_96 ,
V_19 -> V_97 , V_19 -> signal , V_19 -> V_100 ,
V_19 -> V_101 , V_19 -> V_99 ) ;
}
static void F_20 ( const void * V_16 , bool V_17 )
{
const struct V_102 * V_19 = V_16 ;
F_7 ( L_33 ,
V_19 -> V_29 , V_19 -> type , V_19 -> V_103 ) ;
}
static void F_21 ( const void * V_16 , bool V_17 )
{
const struct V_12 * V_19 = V_16 ;
F_7 ( L_34
L_35 , V_19 -> V_27 ,
( unsigned long long ) V_19 -> V_1 , ( int ) sizeof( V_19 -> V_14 ) , V_19 -> V_14 ,
V_19 -> V_8 . V_10 ,
V_19 -> V_8 . V_11 ,
V_19 -> V_15 ) ;
}
static void F_22 ( const void * V_16 , bool V_17 )
{
F_7 ( L_36 , * ( const long long unsigned * ) V_16 ) ;
}
static void F_23 ( const void * V_16 , bool V_17 )
{
const struct V_104 * V_19 = V_16 ;
F_7 ( L_37
L_38 ,
V_19 -> V_29 , V_19 -> type , V_19 -> V_105 , V_19 -> V_106 , V_19 -> V_107 ,
V_19 -> V_96 , V_19 -> V_97 ) ;
}
static void F_24 ( const void * V_16 , bool V_17 )
{
const struct V_108 * V_19 = V_16 ;
F_7 ( L_39 ,
V_19 -> V_86 ,
F_13 ( V_19 -> type , V_38 ) ,
F_13 ( V_19 -> V_109 , V_110 ) ) ;
}
static void F_25 ( const void * V_16 , bool V_17 )
{
const struct V_111 * V_19 = V_16 ;
const struct V_112 * V_113 = & V_19 -> V_114 ;
const struct V_115 * V_116 ;
int V_3 ;
F_7 ( L_40
L_41 ,
V_19 -> V_117 . V_118 / 3600 ,
( int ) ( V_19 -> V_117 . V_118 / 60 ) % 60 ,
( int ) ( V_19 -> V_117 . V_118 % 60 ) ,
( long ) V_19 -> V_117 . V_119 ,
V_19 -> V_27 ,
F_13 ( V_19 -> type , V_38 ) ,
V_19 -> V_39 , F_13 ( V_19 -> V_58 , V_59 ) ,
V_19 -> V_120 , F_13 ( V_19 -> V_109 , V_110 ) ) ;
if ( F_26 ( V_19 -> type ) && V_19 -> V_121 . V_122 ) {
F_7 ( L_42 ) ;
for ( V_3 = 0 ; V_3 < V_19 -> V_123 ; ++ V_3 ) {
V_116 = & V_19 -> V_121 . V_122 [ V_3 ] ;
F_15 ( V_67
L_43
L_44 ,
V_3 , V_116 -> V_124 , V_116 -> V_125 ,
V_116 -> V_121 . V_126 , V_116 -> V_123 ) ;
}
} else {
F_7 ( L_45 ,
V_19 -> V_124 , V_19 -> V_121 . V_126 , V_19 -> V_123 ) ;
}
F_15 ( V_67 L_46
L_47 ,
V_113 -> V_127 , V_113 -> V_128 , V_113 -> V_129 ,
V_113 -> type , V_113 -> V_39 , V_113 -> V_130 , * ( V_131 * ) V_113 -> V_132 ) ;
}
static void F_27 ( const void * V_16 , bool V_17 )
{
const struct V_133 * V_19 = V_16 ;
F_7 ( L_48 ,
V_19 -> V_134 , F_13 ( V_19 -> type , V_38 ) ,
V_19 -> V_27 , V_19 -> V_116 , V_19 -> V_39 ) ;
}
static void F_28 ( const void * V_16 , bool V_17 )
{
const struct V_135 * V_19 = V_16 ;
F_7 ( L_49 ,
V_19 -> V_27 , V_19 -> V_86 ,
F_13 ( V_19 -> V_109 , V_110 ) ) ;
F_14 ( & V_19 -> V_136 , V_17 ) ;
}
static void F_29 ( const void * V_16 , bool V_17 )
{
const struct V_137 * V_19 = V_16 ;
F_7 ( L_11 , F_13 ( V_19 -> type , V_38 ) ) ;
if ( V_19 -> type == V_53 ||
V_19 -> type == V_63 ) {
const struct V_138 * V_139 = & V_19 -> V_140 . V_141 ;
F_7 ( L_50
L_51 ,
V_139 -> V_35 , V_139 -> V_142 ,
V_139 -> V_143 . V_10 , V_139 -> V_143 . V_11 ,
V_139 -> V_144 , V_139 -> V_145 ) ;
} else if ( V_19 -> type == V_54 ||
V_19 -> type == V_64 ) {
const struct V_146 * V_139 = & V_19 -> V_140 . V_147 ;
F_7 ( L_52
L_53 ,
V_139 -> V_35 , V_139 -> V_148 ,
V_139 -> V_143 . V_10 , V_139 -> V_143 . V_11 ,
V_139 -> V_144 , V_139 -> V_149 ) ;
} else {
F_7 ( L_42 ) ;
}
}
static void F_30 ( const void * V_16 , bool V_17 )
{
const struct V_150 * V_19 = V_16 ;
F_7 ( L_54
L_55 ,
V_19 -> V_1 , V_19 -> type , ( int ) sizeof( V_19 -> V_14 ) , V_19 -> V_14 ,
V_19 -> V_151 , V_19 -> V_152 ,
V_19 -> V_153 , V_19 -> V_154 , V_19 -> V_39 ) ;
}
static void F_31 ( const void * V_16 , bool V_17 )
{
const struct V_155 * V_19 = V_16 ;
F_7 ( L_56 , V_19 -> V_1 , V_19 -> V_27 ) ;
}
static void F_32 ( const void * V_16 , bool V_17 )
{
const struct V_156 * V_19 = V_16 ;
F_7 ( L_57 , V_19 -> V_1 , V_19 -> V_157 ) ;
}
static void F_33 ( const void * V_16 , bool V_17 )
{
const struct V_158 * V_19 = V_16 ;
int V_3 ;
F_7 ( L_58 ,
V_19 -> V_159 , V_19 -> V_86 , V_19 -> V_160 ) ;
for ( V_3 = 0 ; V_3 < V_19 -> V_86 ; V_3 ++ ) {
if ( V_19 -> V_161 [ V_3 ] . V_162 )
F_7 ( L_59 ,
V_19 -> V_161 [ V_3 ] . V_1 , V_19 -> V_161 [ V_3 ] . V_157 ) ;
else
F_7 ( L_60 ,
V_19 -> V_161 [ V_3 ] . V_1 , V_19 -> V_161 [ V_3 ] . V_162 ) ;
}
F_7 ( L_42 ) ;
}
static void F_34 ( const void * V_16 , bool V_17 )
{
const struct V_163 * V_19 = V_16 ;
F_7 ( L_61
L_62
L_63 ,
F_13 ( V_19 -> type , V_38 ) ,
V_19 -> V_164 . V_56 , V_19 -> V_164 . V_57 ,
V_19 -> V_164 . V_72 , V_19 -> V_164 . V_73 ,
V_19 -> V_165 . V_56 , V_19 -> V_165 . V_57 ,
V_19 -> V_165 . V_72 , V_19 -> V_165 . V_73 ,
V_19 -> V_166 . V_10 , V_19 -> V_166 . V_11 ) ;
}
static void F_35 ( const void * V_16 , bool V_17 )
{
const struct V_167 * V_19 = V_16 ;
F_7 ( L_64 ,
F_13 ( V_19 -> type , V_38 ) ,
V_19 -> V_139 . V_56 , V_19 -> V_139 . V_57 ,
V_19 -> V_139 . V_72 , V_19 -> V_139 . V_73 ) ;
}
static void F_36 ( const void * V_16 , bool V_17 )
{
const struct V_168 * V_19 = V_16 ;
F_7 ( L_65 ,
F_13 ( V_19 -> type , V_38 ) ,
V_19 -> V_169 , V_19 -> V_39 ,
V_19 -> V_170 . V_56 , V_19 -> V_170 . V_57 , V_19 -> V_170 . V_72 , V_19 -> V_170 . V_73 ) ;
}
static void F_37 ( const void * V_16 , bool V_17 )
{
const struct V_171 * V_19 = V_16 ;
F_7 ( L_66
L_67 ,
V_19 -> V_172 , V_19 -> V_173 , V_19 -> V_174 ,
V_19 -> V_175 , V_19 -> V_176 ) ;
}
static void F_38 ( const void * V_16 , bool V_17 )
{
const struct V_177 * V_19 = V_16 ;
F_7 ( L_68 ,
V_19 -> V_178 , V_19 -> V_179 ) ;
}
static void F_39 ( const void * V_16 , bool V_17 )
{
const struct V_180 * V_19 = V_16 ;
F_7 ( L_69 ,
V_19 -> V_181 , V_19 -> V_39 ) ;
}
static void F_40 ( const void * V_16 , bool V_17 )
{
const struct V_182 * V_19 = V_16 ;
F_7 ( L_69 , V_19 -> V_181 , V_19 -> V_39 ) ;
if ( V_19 -> V_181 == V_183 )
F_41 ( L_70 ,
V_19 -> V_85 . V_184 , V_19 -> V_85 . V_136 ) ;
else if ( V_19 -> V_181 == V_185 )
F_41 ( L_71 , V_19 -> V_186 . V_187 ) ;
}
static void F_42 ( const void * V_16 , bool V_17 )
{
const struct V_188 * V_19 = V_16 ;
F_7 ( L_72 , V_19 -> V_189 . type ) ;
if ( V_19 -> V_189 . type == V_190 )
F_7 ( L_73 ,
( int ) sizeof( V_19 -> V_189 . V_14 ) , V_19 -> V_189 . V_14 ) ;
else
F_7 ( L_74 , V_19 -> V_189 . V_191 ) ;
F_7 ( L_75 ,
V_19 -> V_192 , V_19 -> V_193 ) ;
}
static void F_43 ( const void * V_16 , bool V_17 )
{
const struct V_194 * V_19 = V_16 ;
F_7 ( L_72 , V_19 -> V_189 . type ) ;
if ( V_19 -> V_189 . type == V_190 )
F_7 ( L_73 ,
( int ) sizeof( V_19 -> V_189 . V_14 ) , V_19 -> V_189 . V_14 ) ;
else
F_7 ( L_74 , V_19 -> V_189 . V_191 ) ;
F_7 ( L_76 , ( int ) sizeof( V_19 -> V_14 ) , V_19 -> V_14 ) ;
}
static void F_44 ( const void * V_16 , bool V_17 )
{
const struct V_195 * V_19 = V_16 ;
F_7 ( L_72 , V_19 -> V_189 . type ) ;
if ( V_19 -> V_189 . type == V_190 )
F_7 ( L_73 ,
( int ) sizeof( V_19 -> V_189 . V_14 ) , V_19 -> V_189 . V_14 ) ;
else
F_7 ( L_74 , V_19 -> V_189 . V_191 ) ;
F_7 ( L_77 ,
V_19 -> V_196 , V_19 -> V_197 ) ;
}
static void F_45 ( const void * V_16 , bool V_17 )
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
V_19 -> V_200 . V_56 , V_19 -> V_200 . V_57 ,
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
static void F_46 ( const void * V_16 , bool V_17 )
{
const struct V_213 * V_19 = V_16 ;
F_7 ( L_87 , V_19 -> V_27 ) ;
F_45 ( & V_19 -> V_214 , V_17 ) ;
}
static void F_47 ( const void * V_16 , bool V_17 )
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
static void F_48 ( const void * V_16 , bool V_17 )
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
V_19 -> V_225 . V_56 , V_19 -> V_225 . V_57 ) ;
break;
case V_226 :
F_7 ( L_93 ,
V_19 -> V_227 . V_216 , V_19 -> V_227 . V_218 ,
V_19 -> V_227 . V_228 , V_19 -> V_227 . V_229 ,
V_19 -> V_227 . V_217 , V_19 -> V_227 . V_219 ) ;
break;
case V_230 :
default:
F_7 ( L_42 ) ;
break;
}
}
static void F_49 ( const void * V_16 , bool V_17 )
{
const struct V_231 * V_19 = V_16 ;
F_7 ( L_94 ,
V_19 -> V_27 ,
( V_19 -> V_223 & 0xff ) ,
( V_19 -> V_223 >> 8 ) & 0xff ,
( V_19 -> V_223 >> 16 ) & 0xff ,
( V_19 -> V_223 >> 24 ) & 0xff ,
V_19 -> V_56 , V_19 -> V_57 , V_19 -> type ) ;
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
V_19 -> V_227 . V_153 . V_10 ,
V_19 -> V_227 . V_153 . V_11 ) ;
break;
case V_236 :
default:
F_7 ( L_42 ) ;
break;
}
}
static void F_50 ( const void * V_16 , bool V_17 )
{
const struct V_237 * V_19 = V_16 ;
const struct V_238 * V_139 ;
F_7 ( L_97
L_98 ,
V_19 -> type , V_19 -> V_239 , V_19 -> V_120 , V_19 -> V_1 ,
V_19 -> V_117 . V_118 , V_19 -> V_117 . V_240 ) ;
switch ( V_19 -> type ) {
case V_241 :
F_15 ( V_67 L_99 ,
F_13 ( V_19 -> V_242 . V_208 . V_58 , V_59 ) ) ;
break;
case V_243 :
V_139 = & V_19 -> V_242 . V_244 ;
F_15 ( V_67 L_100 ,
V_139 -> V_245 , V_139 -> type ) ;
if ( V_139 -> type == V_246 )
F_7 ( L_101 , V_139 -> V_247 ) ;
else
F_7 ( L_102 , V_139 -> V_157 ) ;
F_7 ( L_103
L_104 ,
V_139 -> V_39 , V_139 -> V_151 , V_139 -> V_152 ,
V_139 -> V_153 , V_139 -> V_154 ) ;
break;
case V_248 :
F_7 ( L_105 ,
V_19 -> V_242 . V_249 . V_250 ) ;
break;
}
}
static void F_51 ( const void * V_16 , bool V_17 )
{
const struct V_251 * V_19 = V_16 ;
F_7 ( L_106 ,
V_19 -> type , V_19 -> V_1 , V_19 -> V_39 ) ;
}
static void F_52 ( const void * V_16 , bool V_17 )
{
const struct V_252 * V_19 = V_16 ;
int V_3 ;
F_7 ( L_107 ,
F_13 ( V_19 -> type , V_38 ) , V_19 -> V_89 ) ;
for ( V_3 = 0 ; V_3 < 24 ; V_3 ++ )
F_15 ( V_67 L_22 , V_3 ,
V_19 -> V_91 [ 0 ] [ V_3 ] ,
V_19 -> V_91 [ 1 ] [ V_3 ] ) ;
}
static void F_53 ( const void * V_16 , bool V_17 )
{
const struct V_253 * V_19 = V_16 ;
F_7 ( L_108
L_109 ,
V_19 -> V_29 , V_19 -> type , V_19 -> V_27 ,
V_19 -> V_35 , V_19 -> V_96 ,
V_19 -> V_97 , V_19 -> V_254 ) ;
}
static void F_54 ( const void * V_16 , bool V_17 )
{
F_7 ( L_110 , * ( const T_2 * ) V_16 ) ;
}
static void F_55 ( const void * V_16 , bool V_17 )
{
F_7 ( L_42 ) ;
}
static void F_56 ( const void * V_16 , bool V_17 )
{
F_7 ( L_111 ) ;
}
static int F_57 ( struct V_158 * V_139 , int V_255 )
{
V_131 V_3 ;
V_139 -> V_256 [ 0 ] = V_139 -> V_256 [ 1 ] = 0 ;
for ( V_3 = 0 ; V_3 < V_139 -> V_86 ; V_3 ++ )
V_139 -> V_161 [ V_3 ] . V_257 [ 0 ] = 0 ;
if ( ! V_255 && V_139 -> V_159 == V_258 )
return 0 ;
for ( V_3 = 0 ; V_3 < V_139 -> V_86 ; V_3 ++ ) {
if ( F_58 ( V_139 -> V_161 [ V_3 ] . V_1 ) != V_139 -> V_159 ) {
V_139 -> V_160 = V_3 ;
return 0 ;
}
}
return 1 ;
}
static int F_59 ( struct V_259 * V_259 , enum V_260 type )
{
struct V_261 * V_262 = F_60 ( V_259 ) ;
const struct V_263 * V_264 = V_262 -> V_265 ;
bool V_266 = V_262 -> V_267 == V_268 ;
bool V_269 = V_262 -> V_267 == V_270 ;
bool V_271 = V_262 -> V_272 != V_273 ;
bool V_274 = V_262 -> V_272 != V_275 ;
if ( V_264 == NULL )
return - V_276 ;
switch ( type ) {
case V_53 :
if ( V_266 && V_271 &&
( V_264 -> V_277 || V_264 -> V_278 ) )
return 0 ;
break;
case V_63 :
if ( V_266 && V_271 && V_264 -> V_278 )
return 0 ;
break;
case V_69 :
if ( V_266 && V_271 && V_264 -> V_279 )
return 0 ;
break;
case V_54 :
if ( V_266 && V_274 &&
( V_264 -> V_280 || V_264 -> V_281 ) )
return 0 ;
break;
case V_64 :
if ( V_266 && V_274 && V_264 -> V_281 )
return 0 ;
break;
case V_70 :
if ( V_266 && V_274 && V_264 -> V_282 )
return 0 ;
break;
case V_79 :
if ( V_269 && V_271 && V_264 -> V_283 )
return 0 ;
break;
case V_80 :
if ( V_269 && V_274 && V_264 -> V_284 )
return 0 ;
break;
case V_87 :
if ( V_269 && V_271 && V_264 -> V_285 )
return 0 ;
break;
case V_88 :
if ( V_269 && V_274 && V_264 -> V_286 )
return 0 ;
break;
default:
break;
}
return - V_276 ;
}
static int F_61 ( const struct V_263 * V_264 ,
struct V_259 * V_259 , void * V_287 , void * V_16 )
{
struct V_18 * V_288 = (struct V_18 * ) V_16 ;
V_288 -> V_23 = V_289 ;
return V_264 -> V_290 ( V_259 , V_287 , V_288 ) ;
}
static int F_62 ( const struct V_263 * V_264 ,
struct V_259 * V_259 , void * V_287 , void * V_16 )
{
return V_264 -> V_291 ( V_259 , V_287 , * ( unsigned int * ) V_16 ) ;
}
static int F_63 ( const struct V_263 * V_264 ,
struct V_259 * V_259 , void * V_287 , void * V_16 )
{
return V_264 -> V_292 ( V_259 , V_287 , * ( unsigned int * ) V_16 ) ;
}
static int F_64 ( const struct V_263 * V_264 ,
struct V_259 * V_259 , void * V_287 , void * V_16 )
{
struct V_261 * V_262 ;
T_2 * V_19 = V_16 ;
if ( V_264 -> V_293 )
return V_264 -> V_293 ( V_259 , V_287 , V_16 ) ;
V_262 = F_60 ( V_259 ) ;
* V_19 = F_65 ( & V_262 -> V_294 -> V_295 ) ;
return 0 ;
}
static int F_66 ( const struct V_263 * V_264 ,
struct V_259 * V_259 , void * V_287 , void * V_16 )
{
struct V_261 * V_262 ;
struct V_296 * V_297 ;
T_2 * V_19 = V_16 ;
if ( V_264 -> V_298 )
return V_264 -> V_298 ( V_259 , V_287 , * V_19 ) ;
V_262 = F_60 ( V_259 ) ;
V_297 = V_259 -> V_299 ;
return F_67 ( & V_262 -> V_294 -> V_295 , & V_297 -> V_295 , * V_19 ) ;
}
static int F_68 ( const struct V_263 * V_264 ,
struct V_259 * V_259 , void * V_287 , void * V_16 )
{
struct V_261 * V_262 = F_60 ( V_259 ) ;
struct V_26 * V_19 = V_16 ;
if ( F_69 ( V_262 , V_300 ) )
V_19 -> V_24 |= V_301 ;
return V_264 -> V_302 ( V_259 , V_287 , V_19 ) ;
}
static int F_70 ( const struct V_263 * V_264 ,
struct V_259 * V_259 , void * V_287 , void * V_16 )
{
struct V_261 * V_262 = F_60 ( V_259 ) ;
struct V_31 * V_19 = V_16 ;
if ( F_69 ( V_262 , V_300 ) )
V_19 -> V_24 |= V_303 ;
return V_264 -> V_304 ( V_259 , V_287 , V_19 ) ;
}
static int F_71 ( const struct V_263 * V_264 ,
struct V_259 * V_259 , void * V_287 , void * V_16 )
{
struct V_37 * V_19 = V_16 ;
struct V_261 * V_262 = F_60 ( V_259 ) ;
bool V_271 = V_262 -> V_272 != V_273 ;
bool V_274 = V_262 -> V_272 != V_275 ;
switch ( V_19 -> type ) {
case V_53 :
if ( F_72 ( ! V_271 || ! V_264 -> V_305 ) )
break;
return V_264 -> V_305 ( V_259 , V_287 , V_16 ) ;
case V_63 :
if ( F_72 ( ! V_271 || ! V_264 -> V_306 ) )
break;
return V_264 -> V_306 ( V_259 , V_287 , V_16 ) ;
case V_69 :
if ( F_72 ( ! V_271 || ! V_264 -> V_307 ) )
break;
return V_264 -> V_307 ( V_259 , V_287 , V_16 ) ;
case V_54 :
if ( F_72 ( ! V_274 || ! V_264 -> V_308 ) )
break;
return V_264 -> V_308 ( V_259 , V_287 , V_16 ) ;
case V_64 :
if ( F_72 ( ! V_274 || ! V_264 -> V_309 ) )
break;
return V_264 -> V_309 ( V_259 , V_287 , V_16 ) ;
}
return - V_276 ;
}
static int F_73 ( const struct V_263 * V_264 ,
struct V_259 * V_259 , void * V_287 , void * V_16 )
{
struct V_42 * V_19 = V_16 ;
struct V_261 * V_262 = F_60 ( V_259 ) ;
bool V_266 = V_262 -> V_267 == V_268 ;
bool V_271 = V_262 -> V_272 != V_273 ;
bool V_274 = V_262 -> V_272 != V_275 ;
switch ( V_19 -> type ) {
case V_53 :
if ( F_72 ( ! V_271 || ! V_266 || ! V_264 -> V_277 ) )
break;
return V_264 -> V_277 ( V_259 , V_287 , V_16 ) ;
case V_63 :
if ( F_72 ( ! V_271 || ! V_266 || ! V_264 -> V_278 ) )
break;
return V_264 -> V_278 ( V_259 , V_287 , V_16 ) ;
case V_69 :
if ( F_72 ( ! V_271 || ! V_266 || ! V_264 -> V_279 ) )
break;
return V_264 -> V_279 ( V_259 , V_287 , V_16 ) ;
case V_79 :
if ( F_72 ( ! V_271 || V_266 || ! V_264 -> V_283 ) )
break;
return V_264 -> V_283 ( V_259 , V_287 , V_16 ) ;
case V_87 :
if ( F_72 ( ! V_271 || V_266 || ! V_264 -> V_285 ) )
break;
return V_264 -> V_285 ( V_259 , V_287 , V_16 ) ;
case V_54 :
if ( F_72 ( ! V_274 || ! V_266 || ! V_264 -> V_280 ) )
break;
return V_264 -> V_280 ( V_259 , V_287 , V_16 ) ;
case V_64 :
if ( F_72 ( ! V_274 || ! V_266 || ! V_264 -> V_281 ) )
break;
return V_264 -> V_281 ( V_259 , V_287 , V_16 ) ;
case V_70 :
if ( F_72 ( ! V_274 || ! V_266 || ! V_264 -> V_282 ) )
break;
return V_264 -> V_282 ( V_259 , V_287 , V_16 ) ;
case V_80 :
if ( F_72 ( ! V_274 || V_266 || ! V_264 -> V_284 ) )
break;
return V_264 -> V_284 ( V_259 , V_287 , V_16 ) ;
case V_88 :
if ( F_72 ( ! V_274 || V_266 || ! V_264 -> V_286 ) )
break;
return V_264 -> V_286 ( V_259 , V_287 , V_16 ) ;
}
return - V_276 ;
}
static int F_74 ( const struct V_263 * V_264 ,
struct V_259 * V_259 , void * V_287 , void * V_16 )
{
struct V_42 * V_19 = V_16 ;
struct V_261 * V_262 = F_60 ( V_259 ) ;
bool V_266 = V_262 -> V_267 == V_268 ;
bool V_271 = V_262 -> V_272 != V_273 ;
bool V_274 = V_262 -> V_272 != V_275 ;
switch ( V_19 -> type ) {
case V_53 :
if ( F_72 ( ! V_271 || ! V_266 || ! V_264 -> V_310 ) )
break;
F_75 ( V_19 , V_55 . V_44 ) ;
return V_264 -> V_310 ( V_259 , V_287 , V_16 ) ;
case V_63 :
if ( F_72 ( ! V_271 || ! V_266 || ! V_264 -> V_311 ) )
break;
F_75 ( V_19 , V_55 . V_65 ) ;
return V_264 -> V_311 ( V_259 , V_287 , V_16 ) ;
case V_69 :
if ( F_72 ( ! V_271 || ! V_266 || ! V_264 -> V_312 ) )
break;
F_75 ( V_19 , V_55 . V_52 ) ;
return V_264 -> V_312 ( V_259 , V_287 , V_16 ) ;
case V_79 :
if ( F_72 ( ! V_271 || V_266 || ! V_264 -> V_313 ) )
break;
F_75 ( V_19 , V_55 . V_48 ) ;
return V_264 -> V_313 ( V_259 , V_287 , V_16 ) ;
case V_87 :
if ( F_72 ( ! V_271 || V_266 || ! V_264 -> V_314 ) )
break;
F_75 ( V_19 , V_55 . V_50 ) ;
return V_264 -> V_314 ( V_259 , V_287 , V_16 ) ;
case V_54 :
if ( F_72 ( ! V_274 || ! V_266 || ! V_264 -> V_315 ) )
break;
F_75 ( V_19 , V_55 . V_44 ) ;
return V_264 -> V_315 ( V_259 , V_287 , V_16 ) ;
case V_64 :
if ( F_72 ( ! V_274 || ! V_266 || ! V_264 -> V_316 ) )
break;
F_75 ( V_19 , V_55 . V_65 ) ;
return V_264 -> V_316 ( V_259 , V_287 , V_16 ) ;
case V_70 :
if ( F_72 ( ! V_274 || ! V_266 || ! V_264 -> V_317 ) )
break;
F_75 ( V_19 , V_55 . V_52 ) ;
return V_264 -> V_317 ( V_259 , V_287 , V_16 ) ;
case V_80 :
if ( F_72 ( ! V_274 || V_266 || ! V_264 -> V_318 ) )
break;
F_75 ( V_19 , V_55 . V_48 ) ;
return V_264 -> V_318 ( V_259 , V_287 , V_16 ) ;
case V_88 :
if ( F_72 ( ! V_274 || V_266 || ! V_264 -> V_319 ) )
break;
F_75 ( V_19 , V_55 . V_50 ) ;
return V_264 -> V_319 ( V_259 , V_287 , V_16 ) ;
}
return - V_276 ;
}
static int F_76 ( const struct V_263 * V_264 ,
struct V_259 * V_259 , void * V_287 , void * V_16 )
{
struct V_42 * V_19 = V_16 ;
struct V_261 * V_262 = F_60 ( V_259 ) ;
bool V_266 = V_262 -> V_267 == V_268 ;
bool V_271 = V_262 -> V_272 != V_273 ;
bool V_274 = V_262 -> V_272 != V_275 ;
switch ( V_19 -> type ) {
case V_53 :
if ( F_72 ( ! V_271 || ! V_266 || ! V_264 -> V_320 ) )
break;
F_75 ( V_19 , V_55 . V_44 ) ;
return V_264 -> V_320 ( V_259 , V_287 , V_16 ) ;
case V_63 :
if ( F_72 ( ! V_271 || ! V_266 || ! V_264 -> V_321 ) )
break;
F_75 ( V_19 , V_55 . V_65 ) ;
return V_264 -> V_321 ( V_259 , V_287 , V_16 ) ;
case V_69 :
if ( F_72 ( ! V_271 || ! V_266 || ! V_264 -> V_322 ) )
break;
F_75 ( V_19 , V_55 . V_52 ) ;
return V_264 -> V_322 ( V_259 , V_287 , V_16 ) ;
case V_79 :
if ( F_72 ( ! V_271 || V_266 || ! V_264 -> V_323 ) )
break;
F_75 ( V_19 , V_55 . V_48 ) ;
return V_264 -> V_323 ( V_259 , V_287 , V_16 ) ;
case V_87 :
if ( F_72 ( ! V_271 || V_266 || ! V_264 -> V_324 ) )
break;
F_75 ( V_19 , V_55 . V_50 ) ;
return V_264 -> V_324 ( V_259 , V_287 , V_16 ) ;
case V_54 :
if ( F_72 ( ! V_274 || ! V_266 || ! V_264 -> V_325 ) )
break;
F_75 ( V_19 , V_55 . V_44 ) ;
return V_264 -> V_325 ( V_259 , V_287 , V_16 ) ;
case V_64 :
if ( F_72 ( ! V_274 || ! V_266 || ! V_264 -> V_326 ) )
break;
F_75 ( V_19 , V_55 . V_65 ) ;
return V_264 -> V_326 ( V_259 , V_287 , V_16 ) ;
case V_70 :
if ( F_72 ( ! V_274 || ! V_266 || ! V_264 -> V_327 ) )
break;
F_75 ( V_19 , V_55 . V_52 ) ;
return V_264 -> V_327 ( V_259 , V_287 , V_16 ) ;
case V_80 :
if ( F_72 ( ! V_274 || V_266 || ! V_264 -> V_328 ) )
break;
F_75 ( V_19 , V_55 . V_48 ) ;
return V_264 -> V_328 ( V_259 , V_287 , V_16 ) ;
case V_88 :
if ( F_72 ( ! V_274 || V_266 || ! V_264 -> V_329 ) )
break;
F_75 ( V_19 , V_55 . V_50 ) ;
return V_264 -> V_329 ( V_259 , V_287 , V_16 ) ;
}
return - V_276 ;
}
static int F_77 ( const struct V_263 * V_264 ,
struct V_259 * V_259 , void * V_287 , void * V_16 )
{
return V_264 -> V_330 ( V_259 , V_287 , * ( unsigned int * ) V_16 ) ;
}
static int F_78 ( const struct V_263 * V_264 ,
struct V_259 * V_259 , void * V_287 , void * V_16 )
{
return V_264 -> V_331 ( V_259 , V_287 , * ( unsigned int * ) V_16 ) ;
}
static int F_79 ( const struct V_263 * V_264 ,
struct V_259 * V_259 , void * V_287 , void * V_16 )
{
struct V_261 * V_262 = F_60 ( V_259 ) ;
struct V_98 * V_19 = V_16 ;
int V_332 ;
V_19 -> type = ( V_262 -> V_267 == V_333 ) ?
V_334 : V_335 ;
V_332 = V_264 -> V_336 ( V_259 , V_287 , V_19 ) ;
if ( ! V_332 )
V_19 -> V_35 |= V_337 ;
return V_332 ;
}
static int F_80 ( const struct V_263 * V_264 ,
struct V_259 * V_259 , void * V_287 , void * V_16 )
{
struct V_261 * V_262 = F_60 ( V_259 ) ;
struct V_98 * V_19 = V_16 ;
V_19 -> type = ( V_262 -> V_267 == V_333 ) ?
V_334 : V_335 ;
return V_264 -> V_338 ( V_259 , V_287 , V_19 ) ;
}
static int F_81 ( const struct V_263 * V_264 ,
struct V_259 * V_259 , void * V_287 , void * V_16 )
{
struct V_94 * V_19 = V_16 ;
int V_332 ;
V_332 = V_264 -> V_339 ( V_259 , V_287 , V_19 ) ;
if ( ! V_332 )
V_19 -> V_35 |= V_337 ;
return V_332 ;
}
static int F_82 ( const struct V_263 * V_264 ,
struct V_259 * V_259 , void * V_287 , void * V_16 )
{
struct V_261 * V_262 = F_60 ( V_259 ) ;
struct V_102 * V_19 = V_16 ;
V_19 -> type = ( V_262 -> V_267 == V_333 ) ?
V_334 : V_335 ;
return V_264 -> V_340 ( V_259 , V_287 , V_19 ) ;
}
static int F_83 ( const struct V_263 * V_264 ,
struct V_259 * V_259 , void * V_287 , void * V_16 )
{
struct V_261 * V_262 = F_60 ( V_259 ) ;
const struct V_102 * V_19 = V_16 ;
enum V_341 type ;
type = ( V_262 -> V_267 == V_333 ) ?
V_334 : V_335 ;
if ( V_19 -> type != type )
return - V_276 ;
return V_264 -> V_342 ( V_259 , V_287 , V_19 ) ;
}
static int F_84 ( const struct V_263 * V_264 ,
struct V_259 * V_259 , void * V_287 , void * V_16 )
{
struct V_261 * V_262 = F_60 ( V_259 ) ;
struct V_12 * V_19 = V_16 ;
T_1 V_1 = V_262 -> V_343 , V_344 = 0 ;
unsigned int V_27 = V_19 -> V_27 , V_3 , V_345 = 0 ;
const char * V_6 = L_112 ;
if ( V_1 == 0 )
return - V_346 ;
for ( V_3 = 0 ; V_3 <= V_27 && V_1 ; V_3 ++ ) {
while ( ( V_1 & V_4 [ V_345 ] . V_5 ) != V_4 [ V_345 ] . V_5 )
V_345 ++ ;
V_344 = V_4 [ V_345 ] . V_5 ;
V_6 = V_4 [ V_345 ] . V_6 ;
V_345 ++ ;
if ( V_344 == 0 )
break;
if ( V_344 != V_347 &&
V_344 != V_348 &&
V_344 != V_349 )
V_1 &= ~ V_344 ;
}
if ( V_3 <= V_27 )
return - V_276 ;
F_4 ( V_19 , V_344 , V_6 ) ;
return 0 ;
}
static int F_85 ( const struct V_263 * V_264 ,
struct V_259 * V_259 , void * V_287 , void * V_16 )
{
struct V_261 * V_262 = F_60 ( V_259 ) ;
T_1 * V_1 = V_16 ;
if ( V_264 -> V_350 )
return V_264 -> V_350 ( V_259 , V_287 , V_16 ) ;
if ( V_262 -> V_351 ) {
* V_1 = V_262 -> V_351 ;
return 0 ;
}
return - V_352 ;
}
static int F_86 ( const struct V_263 * V_264 ,
struct V_259 * V_259 , void * V_287 , void * V_16 )
{
struct V_261 * V_262 = F_60 ( V_259 ) ;
T_1 V_1 = * ( T_1 * ) V_16 , V_353 ;
int V_354 ;
V_353 = V_1 & V_262 -> V_343 ;
if ( V_262 -> V_343 && ! V_353 )
return - V_276 ;
V_354 = V_264 -> V_355 ( V_259 , V_287 , V_353 ) ;
if ( V_354 >= 0 )
V_262 -> V_351 = V_353 ;
return V_354 ;
}
static int F_87 ( const struct V_263 * V_264 ,
struct V_259 * V_259 , void * V_287 , void * V_16 )
{
struct V_261 * V_262 = F_60 ( V_259 ) ;
T_1 * V_19 = V_16 ;
* V_19 = V_262 -> V_343 ;
return V_264 -> V_356 ( V_259 , V_287 , V_16 ) ;
}
static int F_88 ( const struct V_263 * V_264 ,
struct V_259 * V_259 , void * V_287 , void * V_16 )
{
struct V_261 * V_262 = F_60 ( V_259 ) ;
struct V_104 * V_19 = V_16 ;
enum V_341 type ;
type = ( V_262 -> V_267 == V_333 ) ?
V_334 : V_335 ;
if ( V_19 -> type != type )
return - V_276 ;
return V_264 -> V_357 ( V_259 , V_287 , V_19 ) ;
}
static int F_89 ( const struct V_263 * V_264 ,
struct V_259 * V_259 , void * V_287 , void * V_16 )
{
return V_264 -> V_358 ( V_259 , V_287 , * ( unsigned int * ) V_16 ) ;
}
static int F_90 ( const struct V_263 * V_264 ,
struct V_259 * V_259 , void * V_287 , void * V_16 )
{
struct V_108 * V_19 = V_16 ;
int V_354 = F_59 ( V_259 , V_19 -> type ) ;
if ( V_354 )
return V_354 ;
F_75 ( V_19 , V_109 ) ;
return V_264 -> V_359 ( V_259 , V_287 , V_19 ) ;
}
static int F_91 ( const struct V_263 * V_264 ,
struct V_259 * V_259 , void * V_287 , void * V_16 )
{
struct V_111 * V_19 = V_16 ;
int V_354 = F_59 ( V_259 , V_19 -> type ) ;
return V_354 ? V_354 : V_264 -> V_360 ( V_259 , V_287 , V_19 ) ;
}
static int F_92 ( const struct V_263 * V_264 ,
struct V_259 * V_259 , void * V_287 , void * V_16 )
{
struct V_111 * V_19 = V_16 ;
int V_354 = F_59 ( V_259 , V_19 -> type ) ;
return V_354 ? V_354 : V_264 -> V_361 ( V_259 , V_287 , V_19 ) ;
}
static int F_93 ( const struct V_263 * V_264 ,
struct V_259 * V_259 , void * V_287 , void * V_16 )
{
struct V_111 * V_19 = V_16 ;
int V_354 = F_59 ( V_259 , V_19 -> type ) ;
return V_354 ? V_354 : V_264 -> V_362 ( V_259 , V_287 , V_19 ) ;
}
static int F_94 ( const struct V_263 * V_264 ,
struct V_259 * V_259 , void * V_287 , void * V_16 )
{
struct V_135 * V_363 = V_16 ;
int V_354 = F_59 ( V_259 , V_363 -> V_136 . type ) ;
return V_354 ? V_354 : V_264 -> V_364 ( V_259 , V_287 , V_363 ) ;
}
static int F_95 ( const struct V_263 * V_264 ,
struct V_259 * V_259 , void * V_287 , void * V_16 )
{
struct V_111 * V_365 = V_16 ;
int V_354 = F_59 ( V_259 , V_365 -> type ) ;
return V_354 ? V_354 : V_264 -> V_366 ( V_259 , V_287 , V_365 ) ;
}
static int F_96 ( const struct V_263 * V_264 ,
struct V_259 * V_259 , void * V_287 , void * V_16 )
{
struct V_261 * V_262 = F_60 ( V_259 ) ;
struct V_137 * V_19 = V_16 ;
T_1 V_5 ;
int V_354 = F_59 ( V_259 , V_19 -> type ) ;
if ( V_354 )
return V_354 ;
if ( V_264 -> V_367 )
return V_264 -> V_367 ( V_259 , V_287 , V_19 ) ;
V_5 = V_262 -> V_351 ;
if ( V_19 -> type != V_53 &&
V_19 -> type != V_63 )
return - V_276 ;
V_19 -> V_140 . V_141 . V_145 = 2 ;
if ( F_69 ( V_262 , V_368 ) && V_264 -> V_350 )
V_354 = V_264 -> V_350 ( V_259 , V_287 , & V_5 ) ;
if ( V_354 == 0 )
F_3 ( V_5 ,
& V_19 -> V_140 . V_141 . V_143 ) ;
return V_354 ;
}
static int F_97 ( const struct V_263 * V_264 ,
struct V_259 * V_259 , void * V_287 , void * V_16 )
{
struct V_137 * V_19 = V_16 ;
int V_354 = F_59 ( V_259 , V_19 -> type ) ;
return V_354 ? V_354 : V_264 -> V_369 ( V_259 , V_287 , V_19 ) ;
}
static int F_98 ( const struct V_263 * V_264 ,
struct V_259 * V_259 , void * V_287 , void * V_16 )
{
struct V_261 * V_262 = F_60 ( V_259 ) ;
struct V_150 * V_19 = V_16 ;
struct V_296 * V_297 =
F_99 ( V_370 , & V_262 -> V_39 ) ? V_287 : NULL ;
if ( V_297 && V_297 -> V_371 )
return V_150 ( V_297 -> V_371 , V_19 ) ;
if ( V_262 -> V_371 )
return V_150 ( V_262 -> V_371 , V_19 ) ;
if ( V_264 -> V_372 )
return V_264 -> V_372 ( V_259 , V_287 , V_19 ) ;
return - V_352 ;
}
static int F_100 ( const struct V_263 * V_264 ,
struct V_259 * V_259 , void * V_287 , void * V_16 )
{
struct V_261 * V_262 = F_60 ( V_259 ) ;
struct V_155 * V_19 = V_16 ;
struct V_296 * V_297 =
F_99 ( V_370 , & V_262 -> V_39 ) ? V_287 : NULL ;
if ( V_297 && V_297 -> V_371 )
return V_155 ( V_297 -> V_371 , V_19 ) ;
if ( V_262 -> V_371 )
return V_155 ( V_262 -> V_371 , V_19 ) ;
if ( V_264 -> V_373 )
return V_264 -> V_373 ( V_259 , V_287 , V_19 ) ;
return - V_352 ;
}
static int F_101 ( const struct V_263 * V_264 ,
struct V_259 * V_259 , void * V_287 , void * V_16 )
{
struct V_261 * V_262 = F_60 ( V_259 ) ;
struct V_156 * V_19 = V_16 ;
struct V_296 * V_297 =
F_99 ( V_370 , & V_262 -> V_39 ) ? V_287 : NULL ;
struct V_158 V_374 ;
struct V_375 V_244 ;
if ( V_297 && V_297 -> V_371 )
return F_102 ( V_297 -> V_371 , V_19 ) ;
if ( V_262 -> V_371 )
return F_102 ( V_262 -> V_371 , V_19 ) ;
if ( V_264 -> V_376 )
return V_264 -> V_376 ( V_259 , V_287 , V_19 ) ;
if ( V_264 -> V_377 == NULL )
return - V_352 ;
V_374 . V_159 = F_58 ( V_19 -> V_1 ) ;
V_374 . V_86 = 1 ;
V_374 . V_161 = & V_244 ;
V_244 . V_1 = V_19 -> V_1 ;
V_244 . V_157 = V_19 -> V_157 ;
if ( F_57 ( & V_374 , 1 ) ) {
int V_354 = V_264 -> V_377 ( V_259 , V_287 , & V_374 ) ;
if ( V_354 == 0 )
V_19 -> V_157 = V_244 . V_157 ;
return V_354 ;
}
return - V_276 ;
}
static int F_103 ( const struct V_263 * V_264 ,
struct V_259 * V_259 , void * V_287 , void * V_16 )
{
struct V_261 * V_262 = F_60 ( V_259 ) ;
struct V_156 * V_19 = V_16 ;
struct V_296 * V_297 =
F_99 ( V_370 , & V_262 -> V_39 ) ? V_287 : NULL ;
struct V_158 V_374 ;
struct V_375 V_244 ;
if ( V_297 && V_297 -> V_371 )
return F_104 ( V_297 , V_297 -> V_371 , V_19 ) ;
if ( V_262 -> V_371 )
return F_104 ( NULL , V_262 -> V_371 , V_19 ) ;
if ( V_264 -> V_378 )
return V_264 -> V_378 ( V_259 , V_287 , V_19 ) ;
if ( V_264 -> V_379 == NULL )
return - V_352 ;
V_374 . V_159 = F_58 ( V_19 -> V_1 ) ;
V_374 . V_86 = 1 ;
V_374 . V_161 = & V_244 ;
V_244 . V_1 = V_19 -> V_1 ;
V_244 . V_157 = V_19 -> V_157 ;
if ( F_57 ( & V_374 , 1 ) )
return V_264 -> V_379 ( V_259 , V_287 , & V_374 ) ;
return - V_276 ;
}
static int F_105 ( const struct V_263 * V_264 ,
struct V_259 * V_259 , void * V_287 , void * V_16 )
{
struct V_261 * V_262 = F_60 ( V_259 ) ;
struct V_158 * V_19 = V_16 ;
struct V_296 * V_297 =
F_99 ( V_370 , & V_262 -> V_39 ) ? V_287 : NULL ;
V_19 -> V_160 = V_19 -> V_86 ;
if ( V_297 && V_297 -> V_371 )
return F_106 ( V_297 -> V_371 , V_19 ) ;
if ( V_262 -> V_371 )
return F_106 ( V_262 -> V_371 , V_19 ) ;
if ( V_264 -> V_377 == NULL )
return - V_352 ;
return F_57 ( V_19 , 0 ) ? V_264 -> V_377 ( V_259 , V_287 , V_19 ) :
- V_276 ;
}
static int F_107 ( const struct V_263 * V_264 ,
struct V_259 * V_259 , void * V_287 , void * V_16 )
{
struct V_261 * V_262 = F_60 ( V_259 ) ;
struct V_158 * V_19 = V_16 ;
struct V_296 * V_297 =
F_99 ( V_370 , & V_262 -> V_39 ) ? V_287 : NULL ;
V_19 -> V_160 = V_19 -> V_86 ;
if ( V_297 && V_297 -> V_371 )
return F_108 ( V_297 , V_297 -> V_371 , V_19 ) ;
if ( V_262 -> V_371 )
return F_108 ( NULL , V_262 -> V_371 , V_19 ) ;
if ( V_264 -> V_379 == NULL )
return - V_352 ;
return F_57 ( V_19 , 0 ) ? V_264 -> V_379 ( V_259 , V_287 , V_19 ) :
- V_276 ;
}
static int F_109 ( const struct V_263 * V_264 ,
struct V_259 * V_259 , void * V_287 , void * V_16 )
{
struct V_261 * V_262 = F_60 ( V_259 ) ;
struct V_158 * V_19 = V_16 ;
struct V_296 * V_297 =
F_99 ( V_370 , & V_262 -> V_39 ) ? V_287 : NULL ;
V_19 -> V_160 = V_19 -> V_86 ;
if ( V_297 && V_297 -> V_371 )
return F_110 ( V_297 -> V_371 , V_19 ) ;
if ( V_262 -> V_371 )
return F_110 ( V_262 -> V_371 , V_19 ) ;
if ( V_264 -> V_380 == NULL )
return - V_352 ;
return F_57 ( V_19 , 0 ) ? V_264 -> V_380 ( V_259 , V_287 , V_19 ) :
- V_276 ;
}
static int F_111 ( const struct V_263 * V_264 ,
struct V_259 * V_259 , void * V_287 , void * V_16 )
{
struct V_167 * V_19 = V_16 ;
struct V_168 V_381 = {
. type = V_19 -> type ,
} ;
int V_354 ;
if ( V_264 -> V_382 )
return V_264 -> V_382 ( V_259 , V_287 , V_19 ) ;
if ( F_112 ( V_19 -> type ) )
V_381 . V_169 = V_383 ;
else
V_381 . V_169 = V_384 ;
V_354 = V_264 -> V_385 ( V_259 , V_287 , & V_381 ) ;
if ( ! V_354 )
V_19 -> V_139 = V_381 . V_170 ;
return V_354 ;
}
static int F_113 ( const struct V_263 * V_264 ,
struct V_259 * V_259 , void * V_287 , void * V_16 )
{
struct V_167 * V_19 = V_16 ;
struct V_168 V_381 = {
. type = V_19 -> type ,
. V_170 = V_19 -> V_139 ,
} ;
if ( V_264 -> V_386 )
return V_264 -> V_386 ( V_259 , V_287 , V_19 ) ;
if ( F_112 ( V_19 -> type ) )
V_381 . V_169 = V_383 ;
else
V_381 . V_169 = V_384 ;
return V_264 -> V_387 ( V_259 , V_287 , & V_381 ) ;
}
static int F_114 ( const struct V_263 * V_264 ,
struct V_259 * V_259 , void * V_287 , void * V_16 )
{
struct V_163 * V_19 = V_16 ;
struct V_168 V_381 = { . type = V_19 -> type } ;
int V_354 ;
if ( V_264 -> V_388 )
return V_264 -> V_388 ( V_259 , V_287 , V_19 ) ;
if ( F_112 ( V_19 -> type ) )
V_381 . V_169 = V_389 ;
else
V_381 . V_169 = V_390 ;
V_354 = V_264 -> V_385 ( V_259 , V_287 , & V_381 ) ;
if ( V_354 )
return V_354 ;
V_19 -> V_164 = V_381 . V_170 ;
if ( F_112 ( V_19 -> type ) )
V_381 . V_169 = V_391 ;
else
V_381 . V_169 = V_392 ;
V_354 = V_264 -> V_385 ( V_259 , V_287 , & V_381 ) ;
if ( V_354 )
return V_354 ;
V_19 -> V_165 = V_381 . V_170 ;
V_19 -> V_166 . V_10 = 1 ;
V_19 -> V_166 . V_11 = 1 ;
return 0 ;
}
static int F_115 ( const struct V_263 * V_264 ,
struct V_259 * V_259 , void * V_287 , void * V_16 )
{
struct V_261 * V_262 = F_60 ( V_259 ) ;
int V_354 ;
if ( V_262 -> V_294 )
F_41 ( L_113 ,
V_262 -> V_294 -> V_14 ) ;
V_354 = V_264 -> V_393 ( V_259 , V_287 ) ;
if ( V_262 -> V_294 )
F_41 ( L_114 ,
V_262 -> V_294 -> V_14 ) ;
return V_354 ;
}
static int F_116 ( const struct V_263 * V_264 ,
struct V_259 * V_259 , void * V_287 , void * V_16 )
{
#ifdef F_117
struct V_195 * V_19 = V_16 ;
struct V_261 * V_262 = F_60 ( V_259 ) ;
struct V_394 * V_395 ;
int V_396 = 0 ;
if ( ! F_118 ( V_397 ) )
return - V_398 ;
if ( V_19 -> V_189 . type == V_399 ) {
if ( V_262 -> V_294 == NULL )
return - V_276 ;
F_119 (sd, vfd->v4l2_dev)
if ( V_19 -> V_189 . V_191 == V_396 ++ )
return F_120 ( V_395 , V_400 , V_401 , V_19 ) ;
return - V_276 ;
}
if ( V_264 -> V_402 )
return V_264 -> V_402 ( V_259 , V_287 , V_19 ) ;
return - V_276 ;
#else
return - V_352 ;
#endif
}
static int F_121 ( const struct V_263 * V_264 ,
struct V_259 * V_259 , void * V_287 , void * V_16 )
{
#ifdef F_117
const struct V_195 * V_19 = V_16 ;
struct V_261 * V_262 = F_60 ( V_259 ) ;
struct V_394 * V_395 ;
int V_396 = 0 ;
if ( ! F_118 ( V_397 ) )
return - V_398 ;
if ( V_19 -> V_189 . type == V_399 ) {
if ( V_262 -> V_294 == NULL )
return - V_276 ;
F_119 (sd, vfd->v4l2_dev)
if ( V_19 -> V_189 . V_191 == V_396 ++ )
return F_120 ( V_395 , V_400 , V_403 , V_19 ) ;
return - V_276 ;
}
if ( V_264 -> V_404 )
return V_264 -> V_404 ( V_259 , V_287 , V_19 ) ;
return - V_276 ;
#else
return - V_352 ;
#endif
}
static int F_122 ( const struct V_263 * V_264 ,
struct V_259 * V_259 , void * V_287 , void * V_16 )
{
struct V_188 * V_19 = V_16 ;
V_19 -> V_192 = V_405 ;
V_19 -> V_193 = 0 ;
if ( V_19 -> V_189 . type == V_399 )
return - V_276 ;
return V_264 -> V_406 ( V_259 , V_287 , V_19 ) ;
}
static int F_123 ( const struct V_263 * V_264 ,
struct V_259 * V_259 , void * V_287 , void * V_16 )
{
#ifdef F_117
struct V_261 * V_262 = F_60 ( V_259 ) ;
struct V_194 * V_19 = V_16 ;
struct V_394 * V_395 ;
int V_396 = 0 ;
switch ( V_19 -> V_189 . type ) {
case V_407 :
if ( V_264 -> V_404 )
V_19 -> V_39 |= V_408 ;
if ( V_264 -> V_402 )
V_19 -> V_39 |= V_409 ;
if ( V_262 -> V_294 )
F_5 ( V_19 -> V_14 , V_262 -> V_294 -> V_14 , sizeof( V_19 -> V_14 ) ) ;
else if ( V_262 -> V_410 )
F_5 ( V_19 -> V_14 , V_262 -> V_410 -> V_20 -> V_14 , sizeof( V_19 -> V_14 ) ) ;
else
F_5 ( V_19 -> V_14 , L_115 , sizeof( V_19 -> V_14 ) ) ;
if ( V_264 -> V_411 )
return V_264 -> V_411 ( V_259 , V_287 , V_16 ) ;
if ( V_19 -> V_189 . V_191 )
return - V_276 ;
return 0 ;
case V_399 :
if ( V_262 -> V_294 == NULL )
break;
F_119 (sd, vfd->v4l2_dev) {
if ( V_19 -> V_189 . V_191 != V_396 ++ )
continue;
if ( V_395 -> V_264 -> V_400 && V_395 -> V_264 -> V_400 -> V_403 )
V_19 -> V_39 |= V_408 ;
if ( V_395 -> V_264 -> V_400 && V_395 -> V_264 -> V_400 -> V_401 )
V_19 -> V_39 |= V_409 ;
F_5 ( V_19 -> V_14 , V_395 -> V_14 , sizeof( V_19 -> V_14 ) ) ;
return 0 ;
}
break;
}
return - V_276 ;
#else
return - V_352 ;
#endif
}
static int F_124 ( const struct V_263 * V_264 ,
struct V_259 * V_259 , void * V_287 , void * V_16 )
{
return F_125 ( V_287 , V_16 , V_259 -> V_412 & V_413 ) ;
}
static int F_126 ( const struct V_263 * V_264 ,
struct V_259 * V_259 , void * V_287 , void * V_16 )
{
return V_264 -> V_414 ( V_287 , V_16 ) ;
}
static int F_127 ( const struct V_263 * V_264 ,
struct V_259 * V_259 , void * V_287 , void * V_16 )
{
return V_264 -> V_415 ( V_287 , V_16 ) ;
}
static int F_128 ( const struct V_263 * V_264 ,
struct V_259 * V_259 , void * V_287 , void * V_16 )
{
struct V_252 * V_19 = V_16 ;
int V_354 = F_59 ( V_259 , V_19 -> type ) ;
if ( V_354 )
return V_354 ;
memset ( V_19 , 0 , F_129 ( struct V_252 , type ) ) ;
return V_264 -> V_416 ( V_259 , V_287 , V_19 ) ;
}
static int F_130 ( const struct V_263 * V_264 ,
struct V_259 * V_259 , void * V_287 , void * V_16 )
{
struct V_261 * V_262 = F_60 ( V_259 ) ;
struct V_253 * V_19 = V_16 ;
enum V_341 type ;
int V_332 ;
type = ( V_262 -> V_267 == V_333 ) ?
V_334 : V_335 ;
if ( type != V_19 -> type )
return - V_276 ;
if ( V_264 -> V_417 )
return V_264 -> V_417 ( V_259 , V_287 , V_19 ) ;
if ( F_69 ( V_262 , V_418 ) ) {
struct V_98 V_419 = {
. V_27 = V_19 -> V_29 ,
. type = type ,
} ;
if ( V_19 -> V_27 )
return - V_276 ;
V_332 = V_264 -> V_336 ( V_259 , V_287 , & V_419 ) ;
if ( V_332 )
return V_332 ;
V_19 -> V_35 = V_419 . V_35 | V_337 ;
V_19 -> V_96 = V_419 . V_96 ;
V_19 -> V_97 = V_419 . V_97 ;
V_19 -> V_254 = ( type == V_334 ) ?
V_420 : V_421 ;
return 0 ;
}
if ( F_69 ( V_262 , V_422 ) ) {
struct V_94 V_121 = {
. V_27 = V_19 -> V_29 ,
} ;
if ( type != V_334 )
return - V_276 ;
if ( V_19 -> V_27 )
return - V_276 ;
V_332 = V_264 -> V_339 ( V_259 , V_287 , & V_121 ) ;
if ( V_332 )
return V_332 ;
V_19 -> V_35 = V_121 . V_35 | V_337 ;
V_19 -> V_96 = V_121 . V_96 ;
V_19 -> V_97 = V_121 . V_97 ;
V_19 -> V_254 = ( type == V_334 ) ?
V_420 : V_421 ;
return 0 ;
}
return - V_352 ;
}
bool F_131 ( unsigned int V_181 )
{
if ( F_132 ( V_181 ) >= V_423 )
return false ;
return V_424 [ F_132 ( V_181 ) ] . V_425 == V_181 ;
}
struct V_426 * F_133 ( struct V_261 * V_427 , unsigned V_181 )
{
if ( F_132 ( V_181 ) >= V_423 )
return V_427 -> V_428 ;
if ( F_99 ( F_132 ( V_181 ) , V_427 -> V_429 ) )
return NULL ;
if ( V_427 -> V_430 && V_427 -> V_430 -> V_428 &&
( V_424 [ F_132 ( V_181 ) ] . V_39 & V_431 ) )
return V_427 -> V_430 -> V_428 ;
return V_427 -> V_428 ;
}
void F_134 ( const char * V_432 , unsigned int V_181 )
{
const char * V_433 , * type ;
if ( V_432 )
F_15 ( V_67 L_116 , V_432 ) ;
switch ( F_135 ( V_181 ) ) {
case 'd' :
type = L_117 ;
break;
case 'V' :
if ( F_132 ( V_181 ) >= V_423 ) {
type = L_118 ;
break;
}
F_7 ( L_119 , V_424 [ F_132 ( V_181 ) ] . V_14 ) ;
return;
default:
type = L_120 ;
break;
}
switch ( F_136 ( V_181 ) ) {
case V_434 : V_433 = L_121 ; break;
case V_435 : V_433 = L_122 ; break;
case V_436 : V_433 = L_123 ; break;
case V_435 | V_436 : V_433 = L_124 ; break;
default: V_433 = L_125 ; break;
}
F_7 ( L_126 ,
type , F_135 ( V_181 ) , V_433 , F_132 ( V_181 ) , V_181 ) ;
}
static long F_137 ( struct V_259 * V_259 ,
unsigned int V_181 , void * V_16 )
{
struct V_261 * V_262 = F_60 ( V_259 ) ;
const struct V_263 * V_264 = V_262 -> V_265 ;
bool V_17 = false ;
struct V_437 V_438 ;
const struct V_437 * V_439 ;
void * V_287 = V_259 -> V_299 ;
struct V_296 * V_297 = NULL ;
int V_440 = 0 ;
int V_441 = V_262 -> V_441 ;
long V_354 = - V_352 ;
if ( V_264 == NULL ) {
F_138 ( L_127 ,
F_139 ( V_262 ) ) ;
return V_354 ;
}
if ( F_99 ( V_370 , & V_262 -> V_39 ) ) {
V_297 = V_259 -> V_299 ;
V_440 = F_99 ( V_442 , & V_262 -> V_39 ) ;
}
if ( F_131 ( V_181 ) ) {
V_439 = & V_424 [ F_132 ( V_181 ) ] ;
if ( ! F_99 ( F_132 ( V_181 ) , V_262 -> V_443 ) &&
! ( ( V_439 -> V_39 & V_444 ) && V_297 && V_297 -> V_371 ) )
goto V_445;
if ( V_440 && ( V_439 -> V_39 & V_446 ) ) {
V_354 = F_140 ( V_262 -> V_295 , V_297 -> V_295 ) ;
if ( V_354 )
goto V_445;
}
} else {
V_438 . V_425 = V_181 ;
V_438 . V_39 = 0 ;
V_438 . V_441 = F_56 ;
V_439 = & V_438 ;
}
V_17 = F_136 ( V_181 ) == V_436 ;
if ( V_439 -> V_39 & V_447 ) {
typedef int (* F_141)( struct V_259 * V_259 , void * V_287 , void * V_19 );
const void * V_19 = V_262 -> V_265 ;
const F_141 * V_448 = V_19 + V_439 -> V_242 . V_82 ;
V_354 = (* V_448)( V_259 , V_287 , V_16 ) ;
} else if ( V_439 -> V_39 & V_449 ) {
V_354 = V_439 -> V_242 . V_450 ( V_264 , V_259 , V_287 , V_16 ) ;
} else if ( ! V_264 -> V_451 ) {
V_354 = - V_352 ;
} else {
V_354 = V_264 -> V_451 ( V_259 , V_287 ,
V_440 ? F_140 ( V_262 -> V_295 , V_297 -> V_295 ) >= 0 : 0 ,
V_181 , V_16 ) ;
}
V_445:
if ( V_441 ) {
F_134 ( F_139 ( V_262 ) , V_181 ) ;
if ( V_354 < 0 )
F_7 ( L_128 , V_354 ) ;
if ( V_441 == V_452 )
F_7 ( L_42 ) ;
else if ( F_136 ( V_181 ) == V_434 )
V_439 -> V_441 ( V_16 , V_17 ) ;
else {
F_7 ( L_129 ) ;
V_439 -> V_441 ( V_16 , V_17 ) ;
}
}
return V_354 ;
}
static int F_142 ( unsigned int V_181 , void * V_453 , T_3 * V_454 ,
void * T_4 * V_455 , void * * * V_456 )
{
int V_354 = 0 ;
switch ( V_181 ) {
case V_457 :
case V_458 :
case V_459 :
case V_460 : {
struct V_111 * V_461 = V_453 ;
if ( F_26 ( V_461 -> type ) && V_461 -> V_123 > 0 ) {
if ( V_461 -> V_123 > V_462 ) {
V_354 = - V_276 ;
break;
}
* V_455 = ( void T_4 * ) V_461 -> V_121 . V_122 ;
* V_456 = ( void * ) & V_461 -> V_121 . V_122 ;
* V_454 = sizeof( struct V_115 ) * V_461 -> V_123 ;
V_354 = 1 ;
}
break;
}
case V_463 :
case V_464 : {
struct V_465 * V_466 = V_453 ;
if ( V_466 -> V_467 ) {
if ( V_466 -> V_467 > 256 ) {
V_354 = - V_276 ;
break;
}
* V_455 = ( void T_4 * ) V_466 -> V_466 ;
* V_456 = ( void * ) & V_466 -> V_466 ;
* V_454 = V_466 -> V_467 * 128 ;
V_354 = 1 ;
}
break;
}
case V_468 :
case V_469 :
case V_470 : {
struct V_158 * V_374 = V_453 ;
if ( V_374 -> V_86 != 0 ) {
if ( V_374 -> V_86 > V_471 ) {
V_354 = - V_276 ;
break;
}
* V_455 = ( void T_4 * ) V_374 -> V_161 ;
* V_456 = ( void * ) & V_374 -> V_161 ;
* V_454 = sizeof( struct V_375 )
* V_374 -> V_86 ;
V_354 = 1 ;
}
break;
}
}
return V_354 ;
}
long
F_143 ( struct V_259 * V_259 , unsigned int V_181 , unsigned long V_16 ,
T_5 V_450 )
{
char V_472 [ 128 ] ;
void * V_473 = NULL ;
void * V_453 = ( void * ) V_16 ;
long V_332 = - V_276 ;
bool V_474 ;
T_3 V_454 = 0 ;
void T_4 * V_455 = NULL ;
void * * V_456 = NULL ;
if ( F_136 ( V_181 ) != V_434 ) {
if ( F_144 ( V_181 ) <= sizeof( V_472 ) ) {
V_453 = V_472 ;
} else {
V_473 = F_145 ( F_144 ( V_181 ) , V_475 ) ;
if ( NULL == V_473 )
return - V_476 ;
V_453 = V_473 ;
}
V_332 = - V_477 ;
if ( F_136 ( V_181 ) & V_436 ) {
unsigned int V_478 = F_144 ( V_181 ) ;
if ( F_131 ( V_181 ) ) {
T_2 V_39 = V_424 [ F_132 ( V_181 ) ] . V_39 ;
if ( V_39 & V_479 )
V_478 = ( V_39 & V_479 ) >> 16 ;
}
if ( F_146 ( V_453 , ( void T_4 * ) V_16 , V_478 ) )
goto V_480;
if ( V_478 < F_144 ( V_181 ) )
memset ( ( V_481 * ) V_453 + V_478 , 0 , F_144 ( V_181 ) - V_478 ) ;
} else {
memset ( V_453 , 0 , F_144 ( V_181 ) ) ;
}
}
V_332 = F_142 ( V_181 , V_453 , & V_454 , & V_455 , & V_456 ) ;
if ( V_332 < 0 )
goto V_480;
V_474 = V_332 ;
if ( V_474 ) {
V_473 = F_145 ( V_454 , V_475 ) ;
V_332 = - V_476 ;
if ( NULL == V_473 )
goto V_482;
V_332 = - V_477 ;
if ( F_146 ( V_473 , V_455 , V_454 ) )
goto V_482;
* V_456 = V_473 ;
}
V_332 = V_450 ( V_259 , V_181 , V_453 ) ;
if ( V_332 == - V_483 )
V_332 = - V_352 ;
if ( V_474 ) {
* V_456 = V_455 ;
if ( F_147 ( V_455 , V_473 , V_454 ) )
V_332 = - V_477 ;
goto V_482;
}
if ( V_332 < 0 && V_181 != V_484 )
goto V_480;
V_482:
switch ( F_136 ( V_181 ) ) {
case V_435 :
case ( V_436 | V_435 ) :
if ( F_147 ( ( void T_4 * ) V_16 , V_453 , F_144 ( V_181 ) ) )
V_332 = - V_477 ;
break;
}
V_480:
F_148 ( V_473 ) ;
return V_332 ;
}
long F_149 ( struct V_259 * V_259 ,
unsigned int V_181 , unsigned long V_16 )
{
return F_143 ( V_259 , V_181 , V_16 , F_137 ) ;
}
