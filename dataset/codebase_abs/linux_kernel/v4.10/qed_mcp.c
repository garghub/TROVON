bool F_1 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_3 || ! V_2 -> V_3 -> V_4 )
return false ;
return true ;
}
void F_2 ( struct V_1 * V_2 , struct V_5 * V_6 )
{
T_1 V_7 = F_3 ( V_2 -> V_3 -> V_4 ,
V_8 ) ;
T_1 V_9 = F_4 ( V_2 , V_6 , V_7 ) ;
V_2 -> V_3 -> V_10 = F_5 ( V_9 ,
F_6 ( V_2 ) ) ;
F_7 ( V_2 , V_11 ,
L_1 ,
V_2 -> V_3 -> V_10 , F_6 ( V_2 ) ) ;
}
void F_8 ( struct V_1 * V_2 , struct V_5 * V_6 )
{
T_1 V_12 = F_9 ( V_2 -> V_3 -> V_13 ) ;
T_1 V_14 , V_15 ;
if ( ! V_2 -> V_3 -> V_4 )
return;
for ( V_15 = 0 ; V_15 < V_12 ; V_15 ++ ) {
V_14 = F_4 ( V_2 , V_6 ,
V_2 -> V_3 -> V_16 +
( V_15 << 2 ) + sizeof( T_1 ) ) ;
( ( T_1 * ) V_2 -> V_3 -> V_17 ) [ V_15 ] =
F_10 ( ( V_18 V_19 ) V_14 ) ;
}
}
int F_11 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 ) {
F_12 ( V_2 -> V_3 -> V_17 ) ;
F_12 ( V_2 -> V_3 -> V_20 ) ;
}
F_12 ( V_2 -> V_3 ) ;
return 0 ;
}
static int F_13 ( struct V_1 * V_2 , struct V_5 * V_6 )
{
struct V_21 * V_22 = V_2 -> V_3 ;
T_1 V_23 , V_9 ;
T_1 V_24 = F_14 ( V_2 ) ;
V_22 -> V_4 = F_4 ( V_2 , V_6 , V_25 ) ;
if ( ! V_22 -> V_4 )
return 0 ;
V_22 -> V_4 |= V_26 ;
V_23 = F_4 ( V_2 , V_6 ,
F_3 ( V_22 -> V_4 ,
V_27 ) ) ;
V_22 -> V_28 = F_5 ( V_23 , V_24 ) ;
F_7 ( V_2 , V_11 ,
L_2 ,
V_23 , V_22 -> V_28 , V_24 ) ;
V_9 = F_4 ( V_2 , V_6 ,
F_3 ( V_22 -> V_4 ,
V_29 ) ) ;
V_22 -> V_16 = F_5 ( V_9 , V_24 ) ;
V_22 -> V_13 = ( V_30 ) F_4 ( V_2 , V_6 , V_22 -> V_16 ) ;
V_22 -> V_31 = F_15 ( V_2 , V_6 , V_32 ) &
V_33 ;
V_22 -> V_34 = F_15 ( V_2 , V_6 , V_35 ) &
V_36 ;
V_22 -> V_37 = ( V_30 ) F_4 ( V_2 , V_6 , V_38 ) ;
return 0 ;
}
int F_16 ( struct V_1 * V_2 , struct V_5 * V_6 )
{
struct V_21 * V_22 ;
T_1 V_39 ;
V_2 -> V_3 = F_17 ( sizeof( * V_2 -> V_3 ) , V_40 ) ;
if ( ! V_2 -> V_3 )
goto V_41;
V_22 = V_2 -> V_3 ;
if ( F_13 ( V_2 , V_6 ) != 0 ) {
F_18 ( V_2 , L_3 ) ;
return 0 ;
}
V_39 = F_9 ( V_22 -> V_13 ) * sizeof( T_1 ) ;
V_22 -> V_17 = F_17 ( V_39 , V_40 ) ;
V_22 -> V_20 = F_17 ( V_39 , V_40 ) ;
if ( ! V_22 -> V_20 || ! V_22 -> V_16 )
goto V_41;
F_19 ( & V_22 -> V_42 ) ;
return 0 ;
V_41:
F_11 ( V_2 ) ;
return - V_43 ;
}
static int F_20 ( struct V_1 * V_2 , T_1 V_44 )
{
F_21 ( & V_2 -> V_3 -> V_42 ) ;
if ( V_44 == V_45 || V_44 == V_46 )
V_2 -> V_3 -> V_47 = false ;
if ( V_2 -> V_3 -> V_47 ) {
F_18 ( V_2 ,
L_4 ,
V_44 ) ;
F_22 ( & V_2 -> V_3 -> V_42 ) ;
return - V_48 ;
}
if ( V_44 == V_49 || V_44 == V_50 ) {
V_2 -> V_3 -> V_47 = true ;
F_22 ( & V_2 -> V_3 -> V_42 ) ;
}
return 0 ;
}
static void F_23 ( struct V_1 * V_2 , T_1 V_44 )
{
if ( V_44 != V_49 && V_44 != V_50 )
F_22 ( & V_2 -> V_3 -> V_42 ) ;
}
int F_24 ( struct V_1 * V_2 , struct V_5 * V_6 )
{
T_1 V_51 = ++ V_2 -> V_3 -> V_31 ;
T_2 V_52 = V_53 ;
T_1 V_54 , V_55 = 0 ;
int V_56 = 0 ;
V_56 = F_20 ( V_2 , V_57 ) ;
if ( V_56 != 0 )
return V_56 ;
V_54 = F_4 ( V_2 , V_6 , V_38 ) ;
F_25 ( V_2 , V_6 , V_32 ,
( V_57 | V_51 ) ) ;
do {
F_26 ( V_52 ) ;
} while ( ( V_54 == F_4 ( V_2 , V_6 ,
V_38 ) ) &&
( V_55 ++ < V_58 ) );
if ( V_54 !=
F_4 ( V_2 , V_6 , V_38 ) ) {
F_7 ( V_2 , V_11 ,
L_5 , V_55 * V_52 ) ;
} else {
F_27 ( V_2 , L_6 ) ;
V_56 = - V_59 ;
}
F_23 ( V_2 , V_57 ) ;
return V_56 ;
}
static int F_28 ( struct V_1 * V_2 ,
struct V_5 * V_6 ,
T_1 V_44 ,
T_1 V_60 ,
T_1 * V_61 ,
T_1 * V_62 )
{
T_2 V_52 = V_53 ;
T_1 V_51 , V_55 = 1 , V_63 ;
int V_56 = 0 ;
V_63 = F_15 ( V_2 , V_6 , V_32 ) &
V_33 ;
if ( V_2 -> V_3 -> V_37 !=
F_4 ( V_2 , V_6 , V_38 ) ) {
F_7 ( V_2 , V_11 , L_7 ) ;
F_13 ( V_2 , V_6 ) ;
F_2 ( V_2 , V_6 ) ;
}
V_51 = ++ V_2 -> V_3 -> V_31 ;
F_25 ( V_2 , V_6 , V_64 , V_60 ) ;
F_25 ( V_2 , V_6 , V_32 , ( V_44 | V_51 ) ) ;
F_7 ( V_2 , V_11 ,
L_8 ,
( V_44 | V_51 ) , V_60 ) ;
do {
F_26 ( V_52 ) ;
* V_61 = F_15 ( V_2 , V_6 , V_65 ) ;
} while ( ( V_51 != ( * V_61 & V_66 ) ) &&
( V_55 ++ < V_67 ) );
F_7 ( V_2 , V_11 ,
L_9 ,
V_55 * V_52 , * V_61 , V_51 ) ;
if ( V_51 == ( * V_61 & V_66 ) ) {
* V_61 &= V_68 ;
* V_62 = F_15 ( V_2 , V_6 , V_69 ) ;
} else {
F_27 ( V_2 , L_10 ,
V_44 , V_60 ) ;
* V_61 = 0 ;
V_56 = - V_59 ;
}
return V_56 ;
}
static int F_29 ( struct V_1 * V_2 ,
struct V_5 * V_6 ,
struct V_70 * V_71 )
{
T_1 V_72 ;
int V_56 ;
if ( ! F_1 ( V_2 ) ) {
F_18 ( V_2 , L_11 ) ;
return - V_48 ;
}
V_72 = V_2 -> V_3 -> V_28 +
F_30 ( struct V_73 , V_74 ) ;
V_56 = F_20 ( V_2 , V_71 -> V_44 ) ;
if ( V_56 )
return V_56 ;
if ( V_71 -> V_75 != NULL )
F_31 ( V_2 , V_6 , V_72 ,
V_71 -> V_75 ,
sizeof( * V_71 -> V_75 ) ) ;
V_56 = F_28 ( V_2 , V_6 , V_71 -> V_44 ,
V_71 -> V_60 , & V_71 -> V_76 ,
& V_71 -> V_77 ) ;
if ( V_71 -> V_78 != NULL )
F_32 ( V_2 , V_6 , V_71 -> V_78 ,
V_72 ,
sizeof( * V_71 -> V_78 ) ) ;
F_23 ( V_2 , V_71 -> V_44 ) ;
return V_56 ;
}
int F_33 ( struct V_1 * V_2 ,
struct V_5 * V_6 ,
T_1 V_44 ,
T_1 V_60 ,
T_1 * V_61 ,
T_1 * V_62 )
{
struct V_70 V_79 ;
union V_80 V_81 ;
int V_56 ;
memset ( & V_79 , 0 , sizeof( V_79 ) ) ;
memset ( & V_81 , 0 , sizeof( V_81 ) ) ;
V_79 . V_44 = V_44 ;
V_79 . V_60 = V_60 ;
if ( ( V_44 == V_46 ) &&
( V_2 -> V_82 -> V_83 == V_84 ) ) {
T_2 * V_85 = V_2 -> V_82 -> V_86 ;
V_81 . V_86 . V_87 = V_85 [ 0 ] << 8 | V_85 [ 1 ] ;
V_81 . V_86 . V_88 = V_85 [ 2 ] << 24 | V_85 [ 3 ] << 16 |
V_85 [ 4 ] << 8 | V_85 [ 5 ] ;
F_7 ( V_2 ,
( V_11 | V_89 ) ,
L_12 ,
V_85 , V_81 . V_86 . V_87 ,
V_81 . V_86 . V_88 ) ;
V_79 . V_75 = & V_81 ;
}
V_56 = F_29 ( V_2 , V_6 , & V_79 ) ;
if ( V_56 )
return V_56 ;
* V_61 = V_79 . V_76 ;
* V_62 = V_79 . V_77 ;
return 0 ;
}
int F_34 ( struct V_1 * V_2 ,
struct V_5 * V_6 ,
T_1 V_44 ,
T_1 V_60 ,
T_1 * V_61 ,
T_1 * V_62 , T_1 * V_90 , T_1 * V_91 )
{
struct V_70 V_79 ;
union V_80 V_74 ;
int V_56 ;
memset ( & V_79 , 0 , sizeof( V_79 ) ) ;
V_79 . V_44 = V_44 ;
V_79 . V_60 = V_60 ;
V_79 . V_78 = & V_74 ;
V_56 = F_29 ( V_2 , V_6 , & V_79 ) ;
if ( V_56 )
return V_56 ;
* V_61 = V_79 . V_76 ;
* V_62 = V_79 . V_77 ;
* V_90 = * V_62 ;
memcpy ( V_91 , & V_74 . V_92 , * V_90 ) ;
return 0 ;
}
int F_35 ( struct V_1 * V_2 ,
struct V_5 * V_6 , T_1 * V_93 )
{
struct V_94 * V_82 = V_2 -> V_82 ;
struct V_70 V_79 ;
union V_80 V_74 ;
int V_56 ;
memset ( & V_79 , 0 , sizeof( V_79 ) ) ;
V_79 . V_44 = V_49 ;
V_79 . V_60 = V_95 | V_96 |
V_82 -> V_97 ;
memcpy ( & V_74 . V_98 , V_82 -> V_98 , V_99 ) ;
V_79 . V_75 = & V_74 ;
V_56 = F_29 ( V_2 , V_6 , & V_79 ) ;
if ( V_56 ) {
F_27 ( V_2 , L_13 ) ;
return V_56 ;
}
* V_93 = V_79 . V_76 ;
if ( ! ( * V_93 ) ||
( ( * V_93 ) == V_100 ) ||
( ( * V_93 ) == V_101 ) ||
( ( * V_93 ) == V_102 ) ) {
F_27 ( V_2 , L_14 ) ;
return - V_48 ;
}
return 0 ;
}
static void F_36 ( struct V_1 * V_2 ,
struct V_5 * V_6 )
{
T_1 V_7 = F_3 ( V_2 -> V_3 -> V_4 ,
V_103 ) ;
T_1 V_104 = F_4 ( V_2 , V_6 , V_7 ) ;
T_1 V_105 = F_5 ( V_104 ,
F_37 ( V_2 ) ) ;
T_1 V_106 [ V_107 / 32 ] ;
int V_15 ;
F_7 ( V_2 ,
V_11 ,
L_15 ,
V_104 , V_105 ) ;
for ( V_15 = 0 ; V_15 < ( V_107 / 32 ) ; V_15 ++ ) {
V_106 [ V_15 ] = F_4 ( V_2 , V_6 ,
V_105 +
F_30 ( struct V_108 ,
V_109 ) +
sizeof( T_1 ) * V_15 ) ;
F_7 ( V_2 , ( V_11 | V_110 ) ,
L_16 ,
V_15 * 32 , ( V_15 + 1 ) * 32 - 1 , V_106 [ V_15 ] ) ;
}
if ( F_38 ( V_2 , V_106 ) )
F_39 ( V_2 , V_111 ) ;
}
int F_40 ( struct V_1 * V_2 ,
struct V_5 * V_6 , T_1 * V_112 )
{
T_1 V_7 = F_3 ( V_2 -> V_3 -> V_4 ,
V_113 ) ;
T_1 V_114 = F_4 ( V_2 , V_6 , V_7 ) ;
T_1 V_115 = F_5 ( V_114 ,
F_14 ( V_2 ) ) ;
struct V_70 V_79 ;
union V_80 V_74 ;
int V_56 ;
int V_15 ;
for ( V_15 = 0 ; V_15 < ( V_107 / 32 ) ; V_15 ++ )
F_7 ( V_2 , ( V_11 | V_110 ) ,
L_17 ,
V_15 * 32 , ( V_15 + 1 ) * 32 - 1 , V_112 [ V_15 ] ) ;
memset ( & V_79 , 0 , sizeof( V_79 ) ) ;
V_79 . V_44 = V_116 ;
memcpy ( & V_74 . V_117 , V_112 , V_107 / 8 ) ;
V_79 . V_75 = & V_74 ;
V_56 = F_29 ( V_2 , V_6 , & V_79 ) ;
if ( V_56 ) {
F_18 ( V_2 , L_18 ) ;
return - V_48 ;
}
for ( V_15 = 0 ; V_15 < ( V_107 / 32 ) ; V_15 ++ )
F_41 ( V_2 , V_6 ,
V_115 +
F_30 ( struct V_118 , V_119 ) +
V_15 * sizeof( T_1 ) , 0 ) ;
return V_56 ;
}
static void F_42 ( struct V_1 * V_2 ,
struct V_5 * V_6 )
{
T_1 V_120 ;
V_120 = F_4 ( V_2 , V_6 ,
V_2 -> V_3 -> V_10 +
F_30 ( struct V_121 ,
V_122 ) ) ;
F_7 ( V_2 ,
( V_123 | V_11 ) ,
L_19 ,
V_120 ,
( T_1 ) ( V_2 -> V_3 -> V_10 +
F_30 ( struct V_121 , V_122 ) ) ) ;
V_120 = F_43 ( V_120 ,
V_124 ) ;
if ( V_120 == V_125 )
F_18 ( V_2 , L_20 ) ;
else
F_18 ( V_2 , L_21 ) ;
}
static void F_44 ( struct V_1 * V_2 ,
struct V_5 * V_6 , bool V_126 )
{
struct V_127 * V_128 ;
T_2 V_129 , V_130 ;
T_1 V_131 = 0 ;
V_128 = & V_2 -> V_3 -> V_132 ;
memset ( V_128 , 0 , sizeof( * V_128 ) ) ;
if ( ! V_126 ) {
V_131 = F_4 ( V_2 , V_6 ,
V_2 -> V_3 -> V_10 +
F_30 ( struct V_121 , V_133 ) ) ;
F_7 ( V_2 , ( V_134 | V_11 ) ,
L_22 ,
V_131 ,
( T_1 ) ( V_2 -> V_3 -> V_10 +
F_30 ( struct V_121 , V_133 ) ) ) ;
} else {
F_7 ( V_2 , V_134 ,
L_23 ) ;
return;
}
if ( V_2 -> V_135 )
V_128 -> V_136 = ! ! ( V_131 & V_137 ) ;
else
V_128 -> V_136 = false ;
V_128 -> V_138 = true ;
switch ( ( V_131 & V_139 ) ) {
case V_140 :
V_128 -> V_141 = 100000 ;
break;
case V_142 :
V_128 -> V_141 = 50000 ;
break;
case V_143 :
V_128 -> V_141 = 40000 ;
break;
case V_144 :
V_128 -> V_141 = 25000 ;
break;
case V_145 :
V_128 -> V_141 = 20000 ;
break;
case V_146 :
V_128 -> V_141 = 10000 ;
break;
case V_147 :
V_128 -> V_138 = false ;
case V_148 :
V_128 -> V_141 = 1000 ;
break;
default:
V_128 -> V_141 = 0 ;
}
if ( V_128 -> V_136 && V_128 -> V_141 )
V_128 -> V_149 = V_128 -> V_141 ;
else
V_128 -> V_149 = 0 ;
V_129 = V_2 -> V_3 -> V_150 . V_151 ;
V_130 = V_2 -> V_3 -> V_150 . V_152 ;
F_45 ( V_2 , V_6 , V_128 , V_129 ) ;
F_46 ( V_2 , V_6 , V_128 , V_130 ) ;
F_47 ( V_2 -> V_82 , V_128 -> V_153 ) ;
V_128 -> V_154 = ! ! ( V_131 & V_155 ) ;
V_128 -> V_156 = ! ! ( V_131 &
V_157 ) ;
V_128 -> V_158 = ! ! ( V_131 &
V_159 ) ;
V_128 -> V_160 = ! ! ( V_131 & V_161 ) ;
V_128 -> V_162 |=
( V_131 & V_163 ) ?
V_164 : 0 ;
V_128 -> V_162 |=
( V_131 & V_165 ) ?
V_166 : 0 ;
V_128 -> V_162 |=
( V_131 & V_167 ) ?
V_168 : 0 ;
V_128 -> V_162 |=
( V_131 & V_169 ) ?
V_170 : 0 ;
V_128 -> V_162 |=
( V_131 & V_171 ) ?
V_172 : 0 ;
V_128 -> V_162 |=
( V_131 & V_173 ) ?
V_174 : 0 ;
V_128 -> V_162 |=
( V_131 & V_175 ) ?
V_176 : 0 ;
V_128 -> V_162 |=
( V_131 & V_177 ) ?
V_178 : 0 ;
V_128 -> V_179 =
! ! ( V_131 & V_180 ) ;
V_128 -> V_181 =
! ! ( V_131 & V_182 ) ;
switch ( V_131 & V_183 ) {
case V_184 :
V_128 -> V_185 = V_186 ;
break;
case V_187 :
V_128 -> V_185 = V_188 ;
break;
case V_189 :
V_128 -> V_185 = V_190 ;
break;
default:
V_128 -> V_185 = 0 ;
}
V_128 -> V_191 = ! ! ( V_131 & V_192 ) ;
F_48 ( V_2 ) ;
}
int F_49 ( struct V_1 * V_2 , struct V_5 * V_6 , bool V_193 )
{
struct V_194 * V_195 = & V_2 -> V_3 -> V_196 ;
struct V_70 V_79 ;
union V_80 V_74 ;
struct V_197 * V_198 ;
int V_56 = 0 ;
T_1 V_44 ;
V_198 = & V_74 . V_199 ;
memset ( V_198 , 0 , sizeof( * V_198 ) ) ;
V_44 = V_193 ? V_200 : V_201 ;
if ( ! V_195 -> V_141 . V_202 )
V_198 -> V_141 = V_195 -> V_141 . V_203 ;
V_198 -> V_204 |= ( V_195 -> V_204 . V_202 ) ? V_205 : 0 ;
V_198 -> V_204 |= ( V_195 -> V_204 . V_206 ) ? V_207 : 0 ;
V_198 -> V_204 |= ( V_195 -> V_204 . V_208 ) ? V_209 : 0 ;
V_198 -> V_210 = V_195 -> V_141 . V_211 ;
V_198 -> V_212 = V_195 -> V_212 ;
V_2 -> V_135 = V_193 ;
if ( V_193 ) {
F_7 ( V_2 , V_134 ,
L_24 ,
V_198 -> V_141 ,
V_198 -> V_204 ,
V_198 -> V_210 ,
V_198 -> V_212 ,
V_198 -> V_213 ) ;
} else {
F_7 ( V_2 , V_134 ,
L_25 ) ;
}
memset ( & V_79 , 0 , sizeof( V_79 ) ) ;
V_79 . V_44 = V_44 ;
V_79 . V_75 = & V_74 ;
V_56 = F_29 ( V_2 , V_6 , & V_79 ) ;
if ( V_56 ) {
F_27 ( V_2 , L_13 ) ;
return V_56 ;
}
if ( ! V_193 )
F_44 ( V_2 , V_6 , true ) ;
return 0 ;
}
static void F_50 ( struct V_1 * V_2 ,
struct V_5 * V_6 ,
enum V_214 type )
{
enum V_215 V_216 ;
union V_217 V_218 ;
struct V_70 V_79 ;
union V_80 V_74 ;
T_1 V_219 ;
switch ( type ) {
case V_220 :
V_216 = V_221 ;
V_219 = V_222 ;
break;
case V_223 :
V_216 = V_224 ;
V_219 = V_225 ;
break;
case V_226 :
V_216 = V_227 ;
V_219 = V_228 ;
break;
case V_229 :
V_216 = V_230 ;
V_219 = V_231 ;
break;
default:
F_18 ( V_2 , L_26 , type ) ;
return;
}
F_51 ( V_2 -> V_82 , V_216 , & V_218 ) ;
memset ( & V_79 , 0 , sizeof( V_79 ) ) ;
V_79 . V_44 = V_232 ;
V_79 . V_60 = V_219 ;
memcpy ( & V_74 , & V_218 , sizeof( V_218 ) ) ;
V_79 . V_75 = & V_74 ;
F_29 ( V_2 , V_6 , & V_79 ) ;
}
static void F_52 ( struct V_1 * V_2 ,
struct V_118 * V_233 )
{
struct V_234 * V_22 ;
V_22 = & V_2 -> V_3 -> V_150 ;
V_22 -> V_152 = ( V_233 -> V_235 &
V_236 ) >>
V_237 ;
if ( V_22 -> V_152 < 1 || V_22 -> V_152 > 100 ) {
F_53 ( V_2 ,
L_27 ,
V_22 -> V_152 ) ;
V_22 -> V_152 = 1 ;
}
V_22 -> V_151 = ( V_233 -> V_235 &
V_238 ) >>
V_239 ;
if ( V_22 -> V_151 < 1 || V_22 -> V_151 > 100 ) {
F_53 ( V_2 ,
L_28 ,
V_22 -> V_151 ) ;
V_22 -> V_151 = 100 ;
}
}
static T_1 F_54 ( struct V_1 * V_2 ,
struct V_5 * V_6 ,
struct V_118 * V_240 , int V_241 )
{
T_1 V_7 = F_3 ( V_2 -> V_3 -> V_4 ,
V_113 ) ;
T_1 V_104 = F_4 ( V_2 , V_6 , V_7 ) ;
T_1 V_115 = F_5 ( V_104 , V_241 ) ;
T_1 V_15 , V_39 ;
memset ( V_240 , 0 , sizeof( * V_240 ) ) ;
V_39 = F_55 ( T_1 , sizeof( * V_240 ) , F_56 ( V_104 ) ) ;
for ( V_15 = 0 ; V_15 < V_39 / sizeof( T_1 ) ; V_15 ++ )
( ( T_1 * ) V_240 ) [ V_15 ] = F_4 ( V_2 , V_6 ,
V_115 + ( V_15 << 2 ) ) ;
return V_39 ;
}
static void F_57 ( struct V_1 * V_2 , struct V_5 * V_6 )
{
struct V_234 * V_22 ;
struct V_118 V_242 ;
T_1 V_243 = 0 , V_60 = 0 ;
F_54 ( V_2 , V_6 , & V_242 , F_14 ( V_2 ) ) ;
F_52 ( V_2 , & V_242 ) ;
V_22 = & V_2 -> V_3 -> V_150 ;
F_58 ( V_2 -> V_82 , V_22 -> V_152 ) ;
F_59 ( V_2 -> V_82 , V_22 -> V_151 ) ;
F_33 ( V_2 , V_6 , V_244 , 0 , & V_243 ,
& V_60 ) ;
}
int F_60 ( struct V_1 * V_2 ,
struct V_5 * V_6 )
{
struct V_21 * V_245 = V_2 -> V_3 ;
int V_56 = 0 ;
bool V_246 = false ;
V_30 V_15 ;
F_7 ( V_2 , V_11 , L_29 ) ;
F_8 ( V_2 , V_6 ) ;
for ( V_15 = 0 ; V_15 < V_245 -> V_13 ; V_15 ++ ) {
if ( V_245 -> V_17 [ V_15 ] == V_245 -> V_20 [ V_15 ] )
continue;
V_246 = true ;
F_7 ( V_2 , V_134 ,
L_30 ,
V_15 , V_245 -> V_20 [ V_15 ] , V_245 -> V_17 [ V_15 ] ) ;
switch ( V_15 ) {
case V_247 :
F_44 ( V_2 , V_6 , false ) ;
break;
case V_248 :
F_36 ( V_2 , V_6 ) ;
break;
case V_249 :
F_61 ( V_2 , V_6 ,
V_250 ) ;
break;
case V_251 :
F_61 ( V_2 , V_6 ,
V_252 ) ;
break;
case V_253 :
F_61 ( V_2 , V_6 ,
V_254 ) ;
break;
case V_255 :
F_42 ( V_2 , V_6 ) ;
break;
case V_220 :
case V_223 :
case V_226 :
case V_229 :
F_50 ( V_2 , V_6 , V_15 ) ;
break;
case V_256 :
F_57 ( V_2 , V_6 ) ;
break;
default:
F_18 ( V_2 , L_31 , V_15 ) ;
V_56 = - V_257 ;
}
}
for ( V_15 = 0 ; V_15 < F_9 ( V_245 -> V_13 ) ; V_15 ++ ) {
V_19 V_258 = F_62 ( ( ( T_1 * ) V_245 -> V_17 ) [ V_15 ] ) ;
F_41 ( V_2 , V_6 ,
V_245 -> V_16 + sizeof( T_1 ) +
F_9 ( V_245 -> V_13 ) *
sizeof( T_1 ) + V_15 * sizeof( T_1 ) ,
( V_18 T_1 ) V_258 ) ;
}
if ( ! V_246 ) {
F_18 ( V_2 ,
L_32 ) ;
V_56 = - V_257 ;
}
memcpy ( V_245 -> V_20 , V_245 -> V_17 , V_245 -> V_13 ) ;
return V_56 ;
}
int F_63 ( struct V_1 * V_2 ,
struct V_5 * V_6 ,
T_1 * V_259 , T_1 * V_260 )
{
T_1 V_261 ;
if ( F_64 ( V_2 -> V_82 ) ) {
if ( V_2 -> V_262 ) {
struct V_263 * V_264 ;
V_264 = & V_2 -> V_262 -> V_265 ;
* V_259 = V_264 -> V_266 . V_267 ;
return 0 ;
} else {
F_7 ( V_2 ,
V_110 ,
L_33 ) ;
return - V_257 ;
}
}
V_261 = F_4 ( V_2 , V_6 ,
F_3 ( V_2 ->
V_3 -> V_4 ,
V_268 ) ) ;
* V_259 =
F_4 ( V_2 , V_6 ,
F_5 ( V_261 ,
0 ) + F_30 ( struct V_269 , V_267 ) ) ;
if ( V_260 != NULL ) {
* V_260 = F_4 ( V_2 , V_6 ,
F_5 ( V_261 , 0 ) +
F_30 ( struct V_269 ,
V_270 ) ) ;
}
return 0 ;
}
int F_65 ( struct V_94 * V_82 , T_1 * V_271 )
{
struct V_1 * V_2 = & V_82 -> V_272 [ 0 ] ;
struct V_5 * V_6 ;
if ( F_64 ( V_82 ) )
return - V_257 ;
if ( ! F_1 ( V_2 ) ) {
F_18 ( V_2 , L_11 ) ;
return - V_48 ;
}
* V_271 = V_273 ;
V_6 = F_66 ( V_2 ) ;
if ( ! V_6 )
return - V_48 ;
* V_271 = F_4 ( V_2 , V_6 , V_2 -> V_3 -> V_10 +
F_30 ( struct V_121 , V_274 ) ) ;
F_67 ( V_2 , V_6 ) ;
return 0 ;
}
static void
F_68 ( struct V_1 * V_2 ,
enum V_275 * V_276 )
{
if ( F_69 ( V_277 , & V_2 -> V_278 . V_279 ) )
* V_276 = V_280 ;
else
* V_276 = V_281 ;
F_7 ( V_2 , V_282 ,
L_34 ,
( T_1 ) * V_276 ) ;
}
static int
F_70 ( struct V_1 * V_2 ,
struct V_5 * V_6 ,
enum V_275 * V_276 )
{
T_1 V_243 = 0 , V_60 = 0 ;
int V_56 ;
V_56 = F_33 ( V_2 , V_6 ,
V_283 , 0 , & V_243 , & V_60 ) ;
if ( V_56 )
return V_56 ;
if ( V_243 != V_284 ) {
F_7 ( V_2 , V_282 ,
L_35 ,
V_243 ) ;
return - V_257 ;
}
switch ( V_60 ) {
case V_285 :
* V_276 = V_281 ;
break;
case V_286 :
* V_276 = V_280 ;
break;
case V_287 :
F_18 ( V_2 ,
L_36 ) ;
* V_276 = V_280 ;
break;
case V_288 :
default:
F_18 ( V_2 ,
L_37 ,
V_60 ) ;
return - V_257 ;
}
F_7 ( V_2 ,
V_282 ,
L_38 ,
( T_1 ) * V_276 , V_243 , V_60 ) ;
return 0 ;
}
static int
F_71 ( struct V_1 * V_2 ,
struct V_118 * V_22 ,
struct V_5 * V_6 ,
enum V_275 * V_276 )
{
int V_56 = 0 ;
switch ( V_22 -> V_235 & V_289 ) {
case V_290 :
if ( F_70 ( V_2 , V_6 , V_276 ) )
F_68 ( V_2 , V_276 ) ;
break;
case V_291 :
* V_276 = V_292 ;
break;
case V_293 :
F_18 ( V_2 , L_39 ) ;
default:
V_56 = - V_257 ;
}
return V_56 ;
}
int F_72 ( struct V_1 * V_2 ,
struct V_5 * V_6 )
{
struct V_234 * V_245 ;
struct V_118 V_242 ;
F_54 ( V_2 , V_6 , & V_242 , F_14 ( V_2 ) ) ;
V_245 = & V_2 -> V_3 -> V_150 ;
V_245 -> V_294 = ( V_242 . V_235 &
V_295 ) ? 1 : 0 ;
if ( F_71 ( V_2 , & V_242 , V_6 ,
& V_245 -> V_296 ) ) {
F_27 ( V_2 , L_40 ,
( T_1 ) ( V_242 . V_235 & V_289 ) ) ;
return - V_257 ;
}
F_52 ( V_2 , & V_242 ) ;
if ( V_242 . V_87 || V_242 . V_88 ) {
V_245 -> V_297 [ 0 ] = ( T_2 ) ( V_242 . V_87 >> 8 ) ;
V_245 -> V_297 [ 1 ] = ( T_2 ) ( V_242 . V_87 ) ;
V_245 -> V_297 [ 2 ] = ( T_2 ) ( V_242 . V_88 >> 24 ) ;
V_245 -> V_297 [ 3 ] = ( T_2 ) ( V_242 . V_88 >> 16 ) ;
V_245 -> V_297 [ 4 ] = ( T_2 ) ( V_242 . V_88 >> 8 ) ;
V_245 -> V_297 [ 5 ] = ( T_2 ) ( V_242 . V_88 ) ;
memcpy ( & V_2 -> V_82 -> V_86 , V_245 -> V_297 , V_298 ) ;
} else {
F_18 ( V_2 , L_41 ) ;
}
V_245 -> V_299 = ( V_300 ) V_242 . V_301 |
( ( ( V_300 ) V_242 . V_302 ) << 32 ) ;
V_245 -> V_303 = ( V_300 ) V_242 . V_304 |
( ( ( V_300 ) V_242 . V_305 ) << 32 ) ;
V_245 -> V_306 = ( V_30 ) ( V_242 . V_307 & V_308 ) ;
V_245 -> V_309 = ( V_30 ) V_242 . V_310 ;
V_2 -> V_278 . V_311 = V_312 ;
V_2 -> V_82 -> V_83 = ( T_2 ) V_313 ;
if ( F_1 ( V_2 ) ) {
T_1 V_243 = 0 , V_60 = 0 ;
int V_56 ;
V_56 = F_33 ( V_2 , V_6 ,
V_314 , 0 , & V_243 , & V_60 ) ;
if ( V_56 )
return V_56 ;
if ( V_243 == V_315 )
V_2 -> V_278 . V_311 = V_316 ;
}
F_7 ( V_2 , ( V_11 | V_282 ) ,
L_42 ,
V_245 -> V_294 , V_245 -> V_296 ,
V_245 -> V_152 , V_245 -> V_151 ,
V_245 -> V_297 [ 0 ] , V_245 -> V_297 [ 1 ] , V_245 -> V_297 [ 2 ] ,
V_245 -> V_297 [ 3 ] , V_245 -> V_297 [ 4 ] , V_245 -> V_297 [ 5 ] ,
V_245 -> V_299 , V_245 -> V_303 ,
V_245 -> V_306 , ( T_2 ) V_2 -> V_278 . V_311 ) ;
return 0 ;
}
struct V_194
* F_73 ( struct V_1 * V_2 )
{
if ( ! V_2 || ! V_2 -> V_3 )
return NULL ;
return & V_2 -> V_3 -> V_196 ;
}
struct V_127
* F_74 ( struct V_1 * V_2 )
{
if ( ! V_2 || ! V_2 -> V_3 )
return NULL ;
return & V_2 -> V_3 -> V_132 ;
}
struct V_317
* F_75 ( struct V_1 * V_2 )
{
if ( ! V_2 || ! V_2 -> V_3 )
return NULL ;
return & V_2 -> V_3 -> V_318 ;
}
int F_76 ( struct V_1 * V_2 , struct V_5 * V_6 )
{
T_1 V_243 = 0 , V_60 = 0 ;
int V_56 ;
V_56 = F_33 ( V_2 , V_6 ,
V_319 , 1000 , & V_243 , & V_60 ) ;
F_77 ( 1020 ) ;
return V_56 ;
}
int F_78 ( struct V_1 * V_2 ,
struct V_5 * V_6 , T_1 * V_320 )
{
T_1 V_321 ;
if ( F_64 ( V_2 -> V_82 ) )
return - V_257 ;
V_321 = F_4 ( V_2 , V_6 , V_322 ) ;
V_321 = ( V_321 & V_323 ) >>
V_324 ;
V_321 = ( 1 << ( V_321 + V_325 ) ) ;
* V_320 = V_321 ;
return 0 ;
}
int F_79 ( struct V_1 * V_2 ,
struct V_5 * V_6 , T_2 V_326 , T_2 V_327 )
{
T_1 V_243 = 0 , V_60 = 0 , V_328 = 0 ;
int V_56 ;
if ( ! F_80 ( V_2 ) )
return 0 ;
V_327 *= V_2 -> V_82 -> V_329 ;
V_60 |= ( V_326 << V_330 ) &
V_331 ;
V_60 |= ( V_327 << V_332 ) &
V_333 ;
V_56 = F_33 ( V_2 , V_6 , V_334 , V_60 ,
& V_243 , & V_328 ) ;
if ( V_243 != V_335 ) {
F_18 ( V_2 , L_43 , V_326 ) ;
V_56 = - V_257 ;
} else {
F_7 ( V_2 , V_110 ,
L_44 ,
V_327 , V_326 ) ;
}
return V_56 ;
}
int
F_81 ( struct V_1 * V_2 ,
struct V_5 * V_6 ,
struct V_336 * V_337 )
{
struct V_338 * V_339 ;
struct V_70 V_79 ;
union V_80 V_74 ;
V_19 V_258 ;
T_1 V_15 ;
int V_56 ;
V_339 = & V_74 . V_340 ;
V_339 -> V_341 = V_337 -> V_341 ;
for ( V_15 = 0 ; V_15 < ( V_99 - 4 ) / sizeof( T_1 ) ; V_15 ++ ) {
V_258 = F_62 ( * ( ( T_1 * ) & V_337 -> V_342 [ V_15 * sizeof( T_1 ) ] ) ) ;
* ( V_19 * ) & V_339 -> V_342 [ V_15 * sizeof( T_1 ) ] = V_258 ;
}
memset ( & V_79 , 0 , sizeof( V_79 ) ) ;
V_79 . V_44 = V_343 ;
V_79 . V_75 = & V_74 ;
V_56 = F_29 ( V_2 , V_6 , & V_79 ) ;
if ( V_56 )
F_27 ( V_2 , L_13 ) ;
return V_56 ;
}
int F_82 ( struct V_1 * V_2 , struct V_5 * V_6 )
{
T_1 V_243 = 0 , V_60 = 0 ;
int V_56 ;
V_56 = F_33 ( V_2 , V_6 , V_344 , 0 , & V_243 ,
& V_60 ) ;
if ( V_56 )
F_27 ( V_2 , L_13 ) ;
return V_56 ;
}
int F_83 ( struct V_1 * V_2 , struct V_5 * V_6 )
{
T_1 V_345 , V_346 ;
F_41 ( V_2 , V_6 , V_347 , 0xffffffff ) ;
V_345 = F_4 ( V_2 , V_6 , V_348 ) ;
V_345 &= ~ V_349 ;
F_41 ( V_2 , V_6 , V_348 , V_345 ) ;
V_346 = F_4 ( V_2 , V_6 , V_348 ) ;
return ( V_346 & V_349 ) ? - V_59 : 0 ;
}
int F_84 ( struct V_1 * V_2 ,
struct V_5 * V_6 ,
enum V_350 V_351 )
{
T_1 V_243 = 0 , V_60 = 0 ;
T_1 V_64 ;
int V_56 ;
switch ( V_351 ) {
case V_352 :
V_64 = V_353 ;
break;
case V_354 :
V_64 = V_355 ;
break;
case V_356 :
V_64 = V_357 ;
break;
default:
F_18 ( V_2 , L_45 , V_351 ) ;
return - V_257 ;
}
V_56 = F_33 ( V_2 , V_6 , V_358 ,
V_64 , & V_243 , & V_60 ) ;
if ( V_56 )
F_27 ( V_2 , L_13 ) ;
return V_56 ;
}
int F_85 ( struct V_1 * V_2 ,
struct V_5 * V_6 ,
enum V_359 V_360 )
{
T_1 V_243 = 0 , V_60 = 0 ;
T_1 V_64 ;
int V_56 ;
switch ( V_360 ) {
case V_361 :
V_64 = V_362 ;
break;
case V_363 :
V_64 = V_364 ;
break;
case V_365 :
V_64 = V_366 ;
break;
default:
F_18 ( V_2 , L_46 , V_360 ) ;
return - V_257 ;
}
V_56 = F_33 ( V_2 , V_6 , V_367 ,
V_64 , & V_243 , & V_60 ) ;
if ( V_56 )
F_27 ( V_2 , L_47 ) ;
return V_56 ;
}
int F_86 ( struct V_1 * V_2 ,
struct V_5 * V_6 , V_30 V_309 )
{
T_1 V_243 = 0 , V_60 = 0 ;
T_1 V_64 ;
int V_56 ;
V_64 = ( T_1 ) V_309 << V_368 ;
V_56 = F_33 ( V_2 , V_6 , V_369 ,
V_64 , & V_243 , & V_60 ) ;
if ( V_56 )
F_27 ( V_2 , L_48 , V_56 ) ;
return V_56 ;
}
int F_87 ( struct V_1 * V_2 ,
struct V_5 * V_6 , T_2 * V_297 )
{
struct V_70 V_79 ;
union V_80 V_74 ;
int V_56 ;
memset ( & V_79 , 0 , sizeof( V_79 ) ) ;
V_79 . V_44 = V_370 ;
V_79 . V_60 = V_371 <<
V_372 ;
V_79 . V_60 |= F_14 ( V_2 ) ;
F_88 ( & V_74 . V_92 [ 0 ] , V_297 ) ;
V_79 . V_75 = & V_74 ;
V_56 = F_29 ( V_2 , V_6 , & V_79 ) ;
if ( V_56 )
F_27 ( V_2 , L_49 , V_56 ) ;
memcpy ( V_2 -> V_82 -> V_86 , V_297 , V_298 ) ;
return V_56 ;
}
int F_89 ( struct V_1 * V_2 ,
struct V_5 * V_6 , enum V_373 V_374 )
{
T_1 V_243 = 0 , V_60 = 0 ;
T_1 V_64 ;
int V_56 ;
if ( V_2 -> V_278 . V_311 == V_312 ) {
F_7 ( V_2 , V_11 ,
L_50 ) ;
return - V_257 ;
}
switch ( V_374 ) {
case V_313 :
V_64 = V_375 ;
break;
case V_376 :
V_64 = V_377 ;
break;
case V_84 :
V_64 = V_378 ;
break;
default:
F_27 ( V_2 , L_51 , V_374 ) ;
return - V_257 ;
}
V_56 = F_33 ( V_2 , V_6 , V_379 ,
V_64 , & V_243 , & V_60 ) ;
if ( V_56 )
F_27 ( V_2 , L_52 , V_56 ) ;
V_2 -> V_82 -> V_83 = ( T_2 ) V_374 ;
return V_56 ;
}
int F_90 ( struct V_1 * V_2 ,
struct V_5 * V_6 ,
enum V_380 V_381 )
{
T_1 V_243 = 0 , V_60 = 0 ;
T_1 V_64 ;
int V_56 ;
switch ( V_381 ) {
case V_382 :
V_64 = V_383 ;
break;
case V_384 :
V_64 = V_385 ;
break;
case V_386 :
V_64 = V_387 ;
break;
default:
F_27 ( V_2 , L_53 , V_381 ) ;
return - V_257 ;
}
V_56 = F_33 ( V_2 , V_6 , V_388 ,
V_64 , & V_243 , & V_60 ) ;
if ( V_56 )
F_27 ( V_2 , L_54 , V_56 ) ;
return V_56 ;
}
int F_91 ( struct V_1 * V_2 ,
struct V_5 * V_6 , enum V_389 V_390 )
{
T_1 V_243 = 0 , V_60 = 0 , V_64 ;
int V_56 ;
switch ( V_390 ) {
case V_391 :
V_64 = V_392 ;
break;
case V_393 :
V_64 = V_394 ;
break;
case V_395 :
V_64 = V_396 ;
break;
default:
F_18 ( V_2 , L_55 , V_390 ) ;
return - V_257 ;
}
V_56 = F_33 ( V_2 , V_6 , V_397 ,
V_64 , & V_243 , & V_60 ) ;
return V_56 ;
}
int F_92 ( struct V_1 * V_2 ,
struct V_5 * V_6 , T_1 V_398 )
{
T_1 V_243 = 0 , V_60 = 0 ;
int V_56 ;
V_56 = F_33 ( V_2 , V_6 , V_399 ,
V_398 , & V_243 , & V_60 ) ;
if ( V_56 ) {
F_27 ( V_2 ,
L_56 ) ;
} else if ( V_243 != V_284 ) {
F_27 ( V_2 ,
L_57 ) ;
V_56 = - V_257 ;
}
return V_56 ;
}
int F_93 ( struct V_94 * V_82 , T_1 V_7 , T_2 * V_400 , T_1 V_401 )
{
T_1 V_402 = V_401 , V_403 = 0 , V_404 , V_405 = 0 ;
struct V_1 * V_2 = F_94 ( V_82 ) ;
T_1 V_243 = 0 , V_406 = 0 ;
struct V_5 * V_6 ;
int V_56 = 0 ;
V_6 = F_66 ( V_2 ) ;
if ( ! V_6 )
return - V_48 ;
while ( V_402 > 0 ) {
V_404 = F_55 ( T_1 , V_402 , V_407 ) ;
V_56 = F_34 ( V_2 , V_6 ,
V_408 ,
V_7 + V_403 +
( V_404 <<
V_409 ) ,
& V_243 , & V_406 ,
& V_405 ,
( T_1 * ) ( V_400 + V_403 ) ) ;
if ( V_56 || ( V_243 != V_410 ) ) {
F_18 ( V_82 , L_58 , V_56 ) ;
break;
}
if ( V_402 % 0x1000 <
( V_402 - V_405 ) % 0x1000 )
F_95 ( 1000 , 2000 ) ;
V_403 += V_405 ;
V_402 -= V_405 ;
}
V_82 -> V_411 = V_243 ;
F_67 ( V_2 , V_6 ) ;
return V_56 ;
}
int F_96 ( struct V_1 * V_2 , struct V_5 * V_6 )
{
T_1 V_64 = 0 , V_412 , V_60 ;
int V_56 = 0 ;
V_64 = ( V_413 <<
V_414 ) ;
V_56 = F_33 ( V_2 , V_6 , V_415 ,
V_64 , & V_412 , & V_60 ) ;
if ( V_56 )
return V_56 ;
if ( ( ( V_412 & V_68 ) != V_284 ) ||
( V_60 != V_416 ) )
V_56 = - V_59 ;
return V_56 ;
}
int F_97 ( struct V_1 * V_2 , struct V_5 * V_6 )
{
T_1 V_64 , V_412 , V_60 ;
int V_56 = 0 ;
V_64 = ( V_417 <<
V_414 ) ;
V_56 = F_33 ( V_2 , V_6 , V_415 ,
V_64 , & V_412 , & V_60 ) ;
if ( V_56 )
return V_56 ;
if ( ( ( V_412 & V_68 ) != V_284 ) ||
( V_60 != V_416 ) )
V_56 = - V_59 ;
return V_56 ;
}
int F_98 ( struct V_1 * V_2 ,
struct V_5 * V_6 ,
T_1 * V_418 )
{
T_1 V_64 = 0 , V_412 ;
int V_56 = 0 ;
V_64 = ( V_419 <<
V_414 ) ;
V_56 = F_33 ( V_2 , V_6 , V_415 ,
V_64 , & V_412 , V_418 ) ;
if ( V_56 )
return V_56 ;
if ( ( ( V_412 & V_68 ) != V_284 ) )
V_56 = - V_257 ;
return V_56 ;
}
int F_99 ( struct V_1 * V_2 ,
struct V_5 * V_6 ,
struct V_420 * V_421 ,
T_1 V_422 )
{
T_1 V_423 = 0 , V_60 , V_243 = 0 , V_406 = 0 ;
int V_56 ;
V_60 = V_424 <<
V_414 ;
V_60 |= V_422 << V_425 ;
V_56 = F_34 ( V_2 , V_6 ,
V_415 , V_60 ,
& V_243 , & V_406 ,
& V_423 ,
( T_1 * ) V_421 ) ;
if ( V_56 )
return V_56 ;
if ( ( ( V_243 & V_68 ) != V_284 ) ||
( V_421 -> V_426 != 1 ) )
V_56 = - V_257 ;
return V_56 ;
}
int F_100 ( struct V_1 * V_2 ,
struct V_5 * V_6 ,
struct V_427 * V_428 ,
T_1 * V_429 , T_1 * V_430 )
{
struct V_70 V_79 ;
union V_80 V_74 ;
int V_56 ;
memset ( & V_79 , 0 , sizeof( V_79 ) ) ;
memset ( & V_74 , 0 , sizeof( V_74 ) ) ;
V_79 . V_44 = V_431 ;
V_79 . V_60 = V_432 ;
memcpy ( & V_74 . V_433 , V_428 , sizeof( * V_428 ) ) ;
V_79 . V_75 = & V_74 ;
V_79 . V_78 = & V_74 ;
V_56 = F_29 ( V_2 , V_6 , & V_79 ) ;
if ( V_56 )
return V_56 ;
memcpy ( V_428 , & V_74 . V_433 , sizeof( * V_428 ) ) ;
* V_429 = V_79 . V_76 ;
* V_430 = V_79 . V_77 ;
F_7 ( V_2 ,
V_11 ,
L_59 ,
* V_430 ,
V_428 -> V_434 ,
V_428 -> V_39 ,
V_428 -> V_403 ,
V_428 -> V_435 ,
V_428 -> V_436 , V_428 -> V_437 ) ;
return 0 ;
}
