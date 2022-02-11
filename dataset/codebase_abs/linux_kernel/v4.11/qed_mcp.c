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
F_19 ( & V_22 -> V_43 ) ;
return 0 ;
V_41:
F_11 ( V_2 ) ;
return - V_44 ;
}
static int F_20 ( struct V_1 * V_2 , T_1 V_45 )
{
F_21 ( & V_2 -> V_3 -> V_42 ) ;
if ( V_45 == V_46 || V_45 == V_47 )
V_2 -> V_3 -> V_48 = false ;
if ( V_2 -> V_3 -> V_48 ) {
F_18 ( V_2 ,
L_4 ,
V_45 ) ;
F_22 ( & V_2 -> V_3 -> V_42 ) ;
return - V_49 ;
}
if ( V_45 == V_50 || V_45 == V_51 ) {
V_2 -> V_3 -> V_48 = true ;
F_22 ( & V_2 -> V_3 -> V_42 ) ;
}
return 0 ;
}
static void F_23 ( struct V_1 * V_2 , T_1 V_45 )
{
if ( V_45 != V_50 && V_45 != V_51 )
F_22 ( & V_2 -> V_3 -> V_42 ) ;
}
int F_24 ( struct V_1 * V_2 , struct V_5 * V_6 )
{
T_1 V_52 = ++ V_2 -> V_3 -> V_31 ;
T_2 V_53 = V_54 ;
T_1 V_55 , V_56 = 0 ;
int V_57 = 0 ;
V_57 = F_20 ( V_2 , V_58 ) ;
if ( V_57 != 0 )
return V_57 ;
V_55 = F_4 ( V_2 , V_6 , V_38 ) ;
F_25 ( V_2 , V_6 , V_32 ,
( V_58 | V_52 ) ) ;
do {
F_26 ( V_53 ) ;
} while ( ( V_55 == F_4 ( V_2 , V_6 ,
V_38 ) ) &&
( V_56 ++ < V_59 ) );
if ( V_55 !=
F_4 ( V_2 , V_6 , V_38 ) ) {
F_7 ( V_2 , V_11 ,
L_5 , V_56 * V_53 ) ;
} else {
F_27 ( V_2 , L_6 ) ;
V_57 = - V_60 ;
}
F_23 ( V_2 , V_58 ) ;
return V_57 ;
}
static int F_28 ( struct V_1 * V_2 ,
struct V_5 * V_6 ,
T_1 V_45 ,
T_1 V_61 ,
T_1 * V_62 ,
T_1 * V_63 )
{
T_2 V_53 = V_54 ;
T_1 V_52 , V_56 = 1 , V_64 ;
int V_57 = 0 ;
V_64 = F_15 ( V_2 , V_6 , V_32 ) &
V_33 ;
if ( V_2 -> V_3 -> V_37 !=
F_4 ( V_2 , V_6 , V_38 ) ) {
F_7 ( V_2 , V_11 , L_7 ) ;
F_13 ( V_2 , V_6 ) ;
F_2 ( V_2 , V_6 ) ;
}
V_52 = ++ V_2 -> V_3 -> V_31 ;
F_25 ( V_2 , V_6 , V_65 , V_61 ) ;
F_25 ( V_2 , V_6 , V_32 , ( V_45 | V_52 ) ) ;
F_7 ( V_2 , V_11 ,
L_8 ,
( V_45 | V_52 ) , V_61 ) ;
do {
F_26 ( V_53 ) ;
* V_62 = F_15 ( V_2 , V_6 , V_66 ) ;
} while ( ( V_52 != ( * V_62 & V_67 ) ) &&
( V_56 ++ < V_68 ) );
F_7 ( V_2 , V_11 ,
L_9 ,
V_56 * V_53 , * V_62 , V_52 ) ;
if ( V_52 == ( * V_62 & V_67 ) ) {
* V_62 &= V_69 ;
* V_63 = F_15 ( V_2 , V_6 , V_70 ) ;
} else {
F_27 ( V_2 , L_10 ,
V_45 , V_61 ) ;
* V_62 = 0 ;
V_57 = - V_60 ;
}
return V_57 ;
}
static int F_29 ( struct V_1 * V_2 ,
struct V_5 * V_6 ,
struct V_71 * V_72 )
{
T_1 V_73 ;
int V_57 ;
if ( ! F_1 ( V_2 ) ) {
F_18 ( V_2 , L_11 ) ;
return - V_49 ;
}
V_73 = V_2 -> V_3 -> V_28 +
F_30 ( struct V_74 , V_75 ) ;
V_57 = F_20 ( V_2 , V_72 -> V_45 ) ;
if ( V_57 )
return V_57 ;
if ( V_72 -> V_76 != NULL )
F_31 ( V_2 , V_6 , V_73 ,
V_72 -> V_76 ,
sizeof( * V_72 -> V_76 ) ) ;
V_57 = F_28 ( V_2 , V_6 , V_72 -> V_45 ,
V_72 -> V_61 , & V_72 -> V_77 ,
& V_72 -> V_78 ) ;
if ( V_72 -> V_79 != NULL )
F_32 ( V_2 , V_6 , V_72 -> V_79 ,
V_73 ,
sizeof( * V_72 -> V_79 ) ) ;
F_23 ( V_2 , V_72 -> V_45 ) ;
return V_57 ;
}
int F_33 ( struct V_1 * V_2 ,
struct V_5 * V_6 ,
T_1 V_45 ,
T_1 V_61 ,
T_1 * V_62 ,
T_1 * V_63 )
{
struct V_71 V_80 ;
union V_81 V_82 ;
int V_57 ;
memset ( & V_80 , 0 , sizeof( V_80 ) ) ;
memset ( & V_82 , 0 , sizeof( V_82 ) ) ;
V_80 . V_45 = V_45 ;
V_80 . V_61 = V_61 ;
if ( ( V_45 == V_47 ) &&
( V_2 -> V_83 -> V_84 == V_85 ) ) {
T_2 * V_86 = V_2 -> V_83 -> V_87 ;
V_82 . V_87 . V_88 = V_86 [ 0 ] << 8 | V_86 [ 1 ] ;
V_82 . V_87 . V_89 = V_86 [ 2 ] << 24 | V_86 [ 3 ] << 16 |
V_86 [ 4 ] << 8 | V_86 [ 5 ] ;
F_7 ( V_2 ,
( V_11 | V_90 ) ,
L_12 ,
V_86 , V_82 . V_87 . V_88 ,
V_82 . V_87 . V_89 ) ;
V_80 . V_76 = & V_82 ;
}
V_57 = F_29 ( V_2 , V_6 , & V_80 ) ;
if ( V_57 )
return V_57 ;
* V_62 = V_80 . V_77 ;
* V_63 = V_80 . V_78 ;
return 0 ;
}
int F_34 ( struct V_1 * V_2 ,
struct V_5 * V_6 ,
T_1 V_45 ,
T_1 V_61 ,
T_1 * V_62 ,
T_1 * V_63 , T_1 * V_91 , T_1 * V_92 )
{
struct V_71 V_80 ;
union V_81 V_75 ;
int V_57 ;
memset ( & V_80 , 0 , sizeof( V_80 ) ) ;
V_80 . V_45 = V_45 ;
V_80 . V_61 = V_61 ;
V_80 . V_79 = & V_75 ;
V_57 = F_29 ( V_2 , V_6 , & V_80 ) ;
if ( V_57 )
return V_57 ;
* V_62 = V_80 . V_77 ;
* V_63 = V_80 . V_78 ;
* V_91 = * V_63 ;
memcpy ( V_92 , & V_75 . V_93 , * V_91 ) ;
return 0 ;
}
int F_35 ( struct V_1 * V_2 ,
struct V_5 * V_6 , T_1 * V_94 )
{
struct V_95 * V_83 = V_2 -> V_83 ;
struct V_71 V_80 ;
union V_81 V_75 ;
int V_57 ;
memset ( & V_80 , 0 , sizeof( V_80 ) ) ;
V_80 . V_45 = V_50 ;
V_80 . V_61 = V_96 | V_97 |
V_83 -> V_98 ;
memcpy ( & V_75 . V_99 , V_83 -> V_99 , V_100 ) ;
V_80 . V_76 = & V_75 ;
V_57 = F_29 ( V_2 , V_6 , & V_80 ) ;
if ( V_57 ) {
F_27 ( V_2 , L_13 ) ;
return V_57 ;
}
* V_94 = V_80 . V_77 ;
if ( ! ( * V_94 ) ||
( ( * V_94 ) == V_101 ) ||
( ( * V_94 ) == V_102 ) ||
( ( * V_94 ) == V_103 ) ) {
F_27 ( V_2 , L_14 ) ;
return - V_49 ;
}
return 0 ;
}
static void F_36 ( struct V_1 * V_2 ,
struct V_5 * V_6 )
{
T_1 V_7 = F_3 ( V_2 -> V_3 -> V_4 ,
V_104 ) ;
T_1 V_105 = F_4 ( V_2 , V_6 , V_7 ) ;
T_1 V_106 = F_5 ( V_105 ,
F_37 ( V_2 ) ) ;
T_1 V_107 [ V_108 / 32 ] ;
int V_15 ;
F_7 ( V_2 ,
V_11 ,
L_15 ,
V_105 , V_106 ) ;
for ( V_15 = 0 ; V_15 < ( V_108 / 32 ) ; V_15 ++ ) {
V_107 [ V_15 ] = F_4 ( V_2 , V_6 ,
V_106 +
F_30 ( struct V_109 ,
V_110 ) +
sizeof( T_1 ) * V_15 ) ;
F_7 ( V_2 , ( V_11 | V_111 ) ,
L_16 ,
V_15 * 32 , ( V_15 + 1 ) * 32 - 1 , V_107 [ V_15 ] ) ;
}
if ( F_38 ( V_2 , V_107 ) )
F_39 ( V_2 , V_112 ) ;
}
int F_40 ( struct V_1 * V_2 ,
struct V_5 * V_6 , T_1 * V_113 )
{
T_1 V_7 = F_3 ( V_2 -> V_3 -> V_4 ,
V_114 ) ;
T_1 V_115 = F_4 ( V_2 , V_6 , V_7 ) ;
T_1 V_116 = F_5 ( V_115 ,
F_14 ( V_2 ) ) ;
struct V_71 V_80 ;
union V_81 V_75 ;
int V_57 ;
int V_15 ;
for ( V_15 = 0 ; V_15 < ( V_108 / 32 ) ; V_15 ++ )
F_7 ( V_2 , ( V_11 | V_111 ) ,
L_17 ,
V_15 * 32 , ( V_15 + 1 ) * 32 - 1 , V_113 [ V_15 ] ) ;
memset ( & V_80 , 0 , sizeof( V_80 ) ) ;
V_80 . V_45 = V_117 ;
memcpy ( & V_75 . V_118 , V_113 , V_108 / 8 ) ;
V_80 . V_76 = & V_75 ;
V_57 = F_29 ( V_2 , V_6 , & V_80 ) ;
if ( V_57 ) {
F_18 ( V_2 , L_18 ) ;
return - V_49 ;
}
for ( V_15 = 0 ; V_15 < ( V_108 / 32 ) ; V_15 ++ )
F_41 ( V_2 , V_6 ,
V_116 +
F_30 ( struct V_119 , V_120 ) +
V_15 * sizeof( T_1 ) , 0 ) ;
return V_57 ;
}
static void F_42 ( struct V_1 * V_2 ,
struct V_5 * V_6 )
{
T_1 V_121 ;
V_121 = F_4 ( V_2 , V_6 ,
V_2 -> V_3 -> V_10 +
F_30 ( struct V_122 ,
V_123 ) ) ;
F_7 ( V_2 ,
( V_124 | V_11 ) ,
L_19 ,
V_121 ,
( T_1 ) ( V_2 -> V_3 -> V_10 +
F_30 ( struct V_122 , V_123 ) ) ) ;
V_121 = F_43 ( V_121 ,
V_125 ) ;
if ( V_121 == V_126 )
F_18 ( V_2 , L_20 ) ;
else
F_18 ( V_2 , L_21 ) ;
}
static void F_44 ( struct V_1 * V_2 ,
struct V_5 * V_6 , bool V_127 )
{
struct V_128 * V_129 ;
T_2 V_130 , V_131 ;
T_1 V_132 = 0 ;
F_21 ( & V_2 -> V_3 -> V_43 ) ;
V_129 = & V_2 -> V_3 -> V_133 ;
memset ( V_129 , 0 , sizeof( * V_129 ) ) ;
if ( ! V_127 ) {
V_132 = F_4 ( V_2 , V_6 ,
V_2 -> V_3 -> V_10 +
F_30 ( struct V_122 , V_134 ) ) ;
F_7 ( V_2 , ( V_135 | V_11 ) ,
L_22 ,
V_132 ,
( T_1 ) ( V_2 -> V_3 -> V_10 +
F_30 ( struct V_122 , V_134 ) ) ) ;
} else {
F_7 ( V_2 , V_135 ,
L_23 ) ;
goto V_136;
}
if ( V_2 -> V_137 )
V_129 -> V_138 = ! ! ( V_132 & V_139 ) ;
else
V_129 -> V_138 = false ;
V_129 -> V_140 = true ;
switch ( ( V_132 & V_141 ) ) {
case V_142 :
V_129 -> V_143 = 100000 ;
break;
case V_144 :
V_129 -> V_143 = 50000 ;
break;
case V_145 :
V_129 -> V_143 = 40000 ;
break;
case V_146 :
V_129 -> V_143 = 25000 ;
break;
case V_147 :
V_129 -> V_143 = 20000 ;
break;
case V_148 :
V_129 -> V_143 = 10000 ;
break;
case V_149 :
V_129 -> V_140 = false ;
case V_150 :
V_129 -> V_143 = 1000 ;
break;
default:
V_129 -> V_143 = 0 ;
}
if ( V_129 -> V_138 && V_129 -> V_143 )
V_129 -> V_151 = V_129 -> V_143 ;
else
V_129 -> V_151 = 0 ;
V_130 = V_2 -> V_3 -> V_152 . V_153 ;
V_131 = V_2 -> V_3 -> V_152 . V_154 ;
F_45 ( V_2 , V_6 , V_129 , V_130 ) ;
F_46 ( V_2 , V_6 , V_129 , V_131 ) ;
F_47 ( V_2 -> V_83 , V_6 ,
V_129 -> V_155 ) ;
V_129 -> V_156 = ! ! ( V_132 & V_157 ) ;
V_129 -> V_158 = ! ! ( V_132 &
V_159 ) ;
V_129 -> V_160 = ! ! ( V_132 &
V_161 ) ;
V_129 -> V_162 = ! ! ( V_132 & V_163 ) ;
V_129 -> V_164 |=
( V_132 & V_165 ) ?
V_166 : 0 ;
V_129 -> V_164 |=
( V_132 & V_167 ) ?
V_168 : 0 ;
V_129 -> V_164 |=
( V_132 & V_169 ) ?
V_170 : 0 ;
V_129 -> V_164 |=
( V_132 & V_171 ) ?
V_172 : 0 ;
V_129 -> V_164 |=
( V_132 & V_173 ) ?
V_174 : 0 ;
V_129 -> V_164 |=
( V_132 & V_175 ) ?
V_176 : 0 ;
V_129 -> V_164 |=
( V_132 & V_177 ) ?
V_178 : 0 ;
V_129 -> V_164 |=
( V_132 & V_179 ) ?
V_180 : 0 ;
V_129 -> V_181 =
! ! ( V_132 & V_182 ) ;
V_129 -> V_183 =
! ! ( V_132 & V_184 ) ;
switch ( V_132 & V_185 ) {
case V_186 :
V_129 -> V_187 = V_188 ;
break;
case V_189 :
V_129 -> V_187 = V_190 ;
break;
case V_191 :
V_129 -> V_187 = V_192 ;
break;
default:
V_129 -> V_187 = 0 ;
}
V_129 -> V_193 = ! ! ( V_132 & V_194 ) ;
F_48 ( V_2 ) ;
V_136:
F_22 ( & V_2 -> V_3 -> V_43 ) ;
}
int F_49 ( struct V_1 * V_2 , struct V_5 * V_6 , bool V_195 )
{
struct V_196 * V_197 = & V_2 -> V_3 -> V_198 ;
struct V_71 V_80 ;
union V_81 V_75 ;
struct V_199 * V_200 ;
int V_57 = 0 ;
T_1 V_45 ;
V_200 = & V_75 . V_201 ;
memset ( V_200 , 0 , sizeof( * V_200 ) ) ;
V_45 = V_195 ? V_202 : V_203 ;
if ( ! V_197 -> V_143 . V_204 )
V_200 -> V_143 = V_197 -> V_143 . V_205 ;
V_200 -> V_206 |= ( V_197 -> V_206 . V_204 ) ? V_207 : 0 ;
V_200 -> V_206 |= ( V_197 -> V_206 . V_208 ) ? V_209 : 0 ;
V_200 -> V_206 |= ( V_197 -> V_206 . V_210 ) ? V_211 : 0 ;
V_200 -> V_212 = V_197 -> V_143 . V_213 ;
V_200 -> V_214 = V_197 -> V_214 ;
V_2 -> V_137 = V_195 ;
if ( V_195 ) {
F_7 ( V_2 , V_135 ,
L_24 ,
V_200 -> V_143 ,
V_200 -> V_206 ,
V_200 -> V_212 ,
V_200 -> V_214 ,
V_200 -> V_215 ) ;
} else {
F_7 ( V_2 , V_135 ,
L_25 ) ;
}
memset ( & V_80 , 0 , sizeof( V_80 ) ) ;
V_80 . V_45 = V_45 ;
V_80 . V_76 = & V_75 ;
V_57 = F_29 ( V_2 , V_6 , & V_80 ) ;
if ( V_57 ) {
F_27 ( V_2 , L_13 ) ;
return V_57 ;
}
F_44 ( V_2 , V_6 , ! V_195 ) ;
return 0 ;
}
static void F_50 ( struct V_1 * V_2 ,
struct V_5 * V_6 ,
enum V_216 type )
{
enum V_217 V_218 ;
union V_219 V_220 ;
struct V_71 V_80 ;
union V_81 V_75 ;
T_1 V_221 ;
switch ( type ) {
case V_222 :
V_218 = V_223 ;
V_221 = V_224 ;
break;
case V_225 :
V_218 = V_226 ;
V_221 = V_227 ;
break;
case V_228 :
V_218 = V_229 ;
V_221 = V_230 ;
break;
case V_231 :
V_218 = V_232 ;
V_221 = V_233 ;
break;
default:
F_18 ( V_2 , L_26 , type ) ;
return;
}
F_51 ( V_2 -> V_83 , V_218 , & V_220 ) ;
memset ( & V_80 , 0 , sizeof( V_80 ) ) ;
V_80 . V_45 = V_234 ;
V_80 . V_61 = V_221 ;
memcpy ( & V_75 , & V_220 , sizeof( V_220 ) ) ;
V_80 . V_76 = & V_75 ;
F_29 ( V_2 , V_6 , & V_80 ) ;
}
static void F_52 ( struct V_1 * V_2 ,
struct V_119 * V_235 )
{
struct V_236 * V_22 ;
V_22 = & V_2 -> V_3 -> V_152 ;
V_22 -> V_154 = ( V_235 -> V_237 &
V_238 ) >>
V_239 ;
if ( V_22 -> V_154 < 1 || V_22 -> V_154 > 100 ) {
F_53 ( V_2 ,
L_27 ,
V_22 -> V_154 ) ;
V_22 -> V_154 = 1 ;
}
V_22 -> V_153 = ( V_235 -> V_237 &
V_240 ) >>
V_241 ;
if ( V_22 -> V_153 < 1 || V_22 -> V_153 > 100 ) {
F_53 ( V_2 ,
L_28 ,
V_22 -> V_153 ) ;
V_22 -> V_153 = 100 ;
}
}
static T_1 F_54 ( struct V_1 * V_2 ,
struct V_5 * V_6 ,
struct V_119 * V_242 , int V_243 )
{
T_1 V_7 = F_3 ( V_2 -> V_3 -> V_4 ,
V_114 ) ;
T_1 V_105 = F_4 ( V_2 , V_6 , V_7 ) ;
T_1 V_116 = F_5 ( V_105 , V_243 ) ;
T_1 V_15 , V_39 ;
memset ( V_242 , 0 , sizeof( * V_242 ) ) ;
V_39 = F_55 ( T_1 , sizeof( * V_242 ) , F_56 ( V_105 ) ) ;
for ( V_15 = 0 ; V_15 < V_39 / sizeof( T_1 ) ; V_15 ++ )
( ( T_1 * ) V_242 ) [ V_15 ] = F_4 ( V_2 , V_6 ,
V_116 + ( V_15 << 2 ) ) ;
return V_39 ;
}
static void F_57 ( struct V_1 * V_2 , struct V_5 * V_6 )
{
struct V_236 * V_22 ;
struct V_119 V_244 ;
T_1 V_245 = 0 , V_61 = 0 ;
F_54 ( V_2 , V_6 , & V_244 , F_14 ( V_2 ) ) ;
F_52 ( V_2 , & V_244 ) ;
V_22 = & V_2 -> V_3 -> V_152 ;
F_58 ( V_2 -> V_83 , V_22 -> V_154 ) ;
F_59 ( V_2 -> V_83 , V_22 -> V_153 ) ;
F_33 ( V_2 , V_6 , V_246 , 0 , & V_245 ,
& V_61 ) ;
}
int F_60 ( struct V_1 * V_2 ,
struct V_5 * V_6 )
{
struct V_21 * V_247 = V_2 -> V_3 ;
int V_57 = 0 ;
bool V_248 = false ;
V_30 V_15 ;
F_7 ( V_2 , V_11 , L_29 ) ;
F_8 ( V_2 , V_6 ) ;
for ( V_15 = 0 ; V_15 < V_247 -> V_13 ; V_15 ++ ) {
if ( V_247 -> V_17 [ V_15 ] == V_247 -> V_20 [ V_15 ] )
continue;
V_248 = true ;
F_7 ( V_2 , V_135 ,
L_30 ,
V_15 , V_247 -> V_20 [ V_15 ] , V_247 -> V_17 [ V_15 ] ) ;
switch ( V_15 ) {
case V_249 :
F_44 ( V_2 , V_6 , false ) ;
break;
case V_250 :
F_36 ( V_2 , V_6 ) ;
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
F_61 ( V_2 , V_6 ,
V_256 ) ;
break;
case V_257 :
F_42 ( V_2 , V_6 ) ;
break;
case V_222 :
case V_225 :
case V_228 :
case V_231 :
F_50 ( V_2 , V_6 , V_15 ) ;
break;
case V_258 :
F_57 ( V_2 , V_6 ) ;
break;
default:
F_18 ( V_2 , L_31 , V_15 ) ;
V_57 = - V_259 ;
}
}
for ( V_15 = 0 ; V_15 < F_9 ( V_247 -> V_13 ) ; V_15 ++ ) {
V_19 V_260 = F_62 ( ( ( T_1 * ) V_247 -> V_17 ) [ V_15 ] ) ;
F_41 ( V_2 , V_6 ,
V_247 -> V_16 + sizeof( T_1 ) +
F_9 ( V_247 -> V_13 ) *
sizeof( T_1 ) + V_15 * sizeof( T_1 ) ,
( V_18 T_1 ) V_260 ) ;
}
if ( ! V_248 ) {
F_18 ( V_2 ,
L_32 ) ;
V_57 = - V_259 ;
}
memcpy ( V_247 -> V_20 , V_247 -> V_17 , V_247 -> V_13 ) ;
return V_57 ;
}
int F_63 ( struct V_1 * V_2 ,
struct V_5 * V_6 ,
T_1 * V_261 , T_1 * V_262 )
{
T_1 V_263 ;
if ( F_64 ( V_2 -> V_83 ) ) {
if ( V_2 -> V_264 ) {
struct V_265 * V_266 ;
V_266 = & V_2 -> V_264 -> V_267 ;
* V_261 = V_266 -> V_268 . V_269 ;
return 0 ;
} else {
F_7 ( V_2 ,
V_111 ,
L_33 ) ;
return - V_259 ;
}
}
V_263 = F_4 ( V_2 , V_6 ,
F_3 ( V_2 ->
V_3 -> V_4 ,
V_270 ) ) ;
* V_261 =
F_4 ( V_2 , V_6 ,
F_5 ( V_263 ,
0 ) + F_30 ( struct V_271 , V_269 ) ) ;
if ( V_262 != NULL ) {
* V_262 = F_4 ( V_2 , V_6 ,
F_5 ( V_263 , 0 ) +
F_30 ( struct V_271 ,
V_272 ) ) ;
}
return 0 ;
}
int F_65 ( struct V_95 * V_83 , T_1 * V_273 )
{
struct V_1 * V_2 = & V_83 -> V_274 [ 0 ] ;
struct V_5 * V_6 ;
if ( F_64 ( V_83 ) )
return - V_259 ;
if ( ! F_1 ( V_2 ) ) {
F_18 ( V_2 , L_11 ) ;
return - V_49 ;
}
* V_273 = V_275 ;
V_6 = F_66 ( V_2 ) ;
if ( ! V_6 )
return - V_49 ;
* V_273 = F_4 ( V_2 , V_6 , V_2 -> V_3 -> V_10 +
F_30 ( struct V_122 , V_276 ) ) ;
F_67 ( V_2 , V_6 ) ;
return 0 ;
}
static void
F_68 ( struct V_1 * V_2 ,
enum V_277 * V_278 )
{
if ( F_69 ( V_279 , & V_2 -> V_280 . V_281 ) )
* V_278 = V_282 ;
else
* V_278 = V_283 ;
F_7 ( V_2 , V_284 ,
L_34 ,
( T_1 ) * V_278 ) ;
}
static int
F_70 ( struct V_1 * V_2 ,
struct V_5 * V_6 ,
enum V_277 * V_278 )
{
T_1 V_245 = 0 , V_61 = 0 ;
int V_57 ;
V_57 = F_33 ( V_2 , V_6 ,
V_285 , 0 , & V_245 , & V_61 ) ;
if ( V_57 )
return V_57 ;
if ( V_245 != V_286 ) {
F_7 ( V_2 , V_284 ,
L_35 ,
V_245 ) ;
return - V_259 ;
}
switch ( V_61 ) {
case V_287 :
* V_278 = V_283 ;
break;
case V_288 :
* V_278 = V_282 ;
break;
case V_289 :
F_18 ( V_2 ,
L_36 ) ;
* V_278 = V_282 ;
break;
case V_290 :
default:
F_18 ( V_2 ,
L_37 ,
V_61 ) ;
return - V_259 ;
}
F_7 ( V_2 ,
V_284 ,
L_38 ,
( T_1 ) * V_278 , V_245 , V_61 ) ;
return 0 ;
}
static int
F_71 ( struct V_1 * V_2 ,
struct V_119 * V_22 ,
struct V_5 * V_6 ,
enum V_277 * V_278 )
{
int V_57 = 0 ;
switch ( V_22 -> V_237 & V_291 ) {
case V_292 :
if ( ! F_72 ( V_293 ) )
* V_278 = V_283 ;
else if ( F_70 ( V_2 , V_6 , V_278 ) )
F_68 ( V_2 , V_278 ) ;
break;
case V_294 :
* V_278 = V_295 ;
break;
case V_296 :
* V_278 = V_297 ;
break;
case V_298 :
F_18 ( V_2 , L_39 ) ;
default:
V_57 = - V_259 ;
}
return V_57 ;
}
int F_73 ( struct V_1 * V_2 ,
struct V_5 * V_6 )
{
struct V_236 * V_247 ;
struct V_119 V_244 ;
F_54 ( V_2 , V_6 , & V_244 , F_14 ( V_2 ) ) ;
V_247 = & V_2 -> V_3 -> V_152 ;
V_247 -> V_299 = ( V_244 . V_237 &
V_300 ) ? 1 : 0 ;
if ( F_71 ( V_2 , & V_244 , V_6 ,
& V_247 -> V_301 ) ) {
F_27 ( V_2 , L_40 ,
( T_1 ) ( V_244 . V_237 & V_291 ) ) ;
return - V_259 ;
}
F_52 ( V_2 , & V_244 ) ;
if ( V_244 . V_88 || V_244 . V_89 ) {
V_247 -> V_302 [ 0 ] = ( T_2 ) ( V_244 . V_88 >> 8 ) ;
V_247 -> V_302 [ 1 ] = ( T_2 ) ( V_244 . V_88 ) ;
V_247 -> V_302 [ 2 ] = ( T_2 ) ( V_244 . V_89 >> 24 ) ;
V_247 -> V_302 [ 3 ] = ( T_2 ) ( V_244 . V_89 >> 16 ) ;
V_247 -> V_302 [ 4 ] = ( T_2 ) ( V_244 . V_89 >> 8 ) ;
V_247 -> V_302 [ 5 ] = ( T_2 ) ( V_244 . V_89 ) ;
memcpy ( & V_2 -> V_83 -> V_87 , V_247 -> V_302 , V_303 ) ;
} else {
F_18 ( V_2 , L_41 ) ;
}
V_247 -> V_304 = ( V_305 ) V_244 . V_306 |
( ( ( V_305 ) V_244 . V_307 ) << 32 ) ;
V_247 -> V_308 = ( V_305 ) V_244 . V_309 |
( ( ( V_305 ) V_244 . V_310 ) << 32 ) ;
V_247 -> V_311 = ( V_30 ) ( V_244 . V_312 & V_313 ) ;
V_247 -> V_314 = ( V_30 ) V_244 . V_315 ;
V_2 -> V_280 . V_316 = V_317 ;
V_2 -> V_83 -> V_84 = ( T_2 ) V_318 ;
if ( F_1 ( V_2 ) ) {
T_1 V_245 = 0 , V_61 = 0 ;
int V_57 ;
V_57 = F_33 ( V_2 , V_6 ,
V_319 , 0 , & V_245 , & V_61 ) ;
if ( V_57 )
return V_57 ;
if ( V_245 == V_320 )
V_2 -> V_280 . V_316 = V_321 ;
}
F_7 ( V_2 , ( V_11 | V_284 ) ,
L_42 ,
V_247 -> V_299 , V_247 -> V_301 ,
V_247 -> V_154 , V_247 -> V_153 ,
V_247 -> V_302 [ 0 ] , V_247 -> V_302 [ 1 ] , V_247 -> V_302 [ 2 ] ,
V_247 -> V_302 [ 3 ] , V_247 -> V_302 [ 4 ] , V_247 -> V_302 [ 5 ] ,
V_247 -> V_304 , V_247 -> V_308 ,
V_247 -> V_311 , ( T_2 ) V_2 -> V_280 . V_316 ) ;
return 0 ;
}
struct V_196
* F_74 ( struct V_1 * V_2 )
{
if ( ! V_2 || ! V_2 -> V_3 )
return NULL ;
return & V_2 -> V_3 -> V_198 ;
}
struct V_128
* F_75 ( struct V_1 * V_2 )
{
if ( ! V_2 || ! V_2 -> V_3 )
return NULL ;
return & V_2 -> V_3 -> V_133 ;
}
struct V_322
* F_76 ( struct V_1 * V_2 )
{
if ( ! V_2 || ! V_2 -> V_3 )
return NULL ;
return & V_2 -> V_3 -> V_323 ;
}
int F_77 ( struct V_1 * V_2 , struct V_5 * V_6 )
{
T_1 V_245 = 0 , V_61 = 0 ;
int V_57 ;
V_57 = F_33 ( V_2 , V_6 ,
V_324 , 1000 , & V_245 , & V_61 ) ;
F_78 ( 1020 ) ;
return V_57 ;
}
int F_79 ( struct V_1 * V_2 ,
struct V_5 * V_6 , T_1 * V_325 )
{
T_1 V_326 ;
if ( F_64 ( V_2 -> V_83 ) )
return - V_259 ;
V_326 = F_4 ( V_2 , V_6 , V_327 ) ;
V_326 = ( V_326 & V_328 ) >>
V_329 ;
V_326 = ( 1 << ( V_326 + V_330 ) ) ;
* V_325 = V_326 ;
return 0 ;
}
int F_80 ( struct V_1 * V_2 ,
struct V_5 * V_6 , T_2 V_331 , T_2 V_332 )
{
T_1 V_245 = 0 , V_61 = 0 , V_333 = 0 ;
int V_57 ;
if ( ! F_81 ( V_2 ) )
return 0 ;
V_332 *= V_2 -> V_83 -> V_334 ;
V_61 |= ( V_331 << V_335 ) &
V_336 ;
V_61 |= ( V_332 << V_337 ) &
V_338 ;
V_57 = F_33 ( V_2 , V_6 , V_339 , V_61 ,
& V_245 , & V_333 ) ;
if ( V_245 != V_340 ) {
F_18 ( V_2 , L_43 , V_331 ) ;
V_57 = - V_259 ;
} else {
F_7 ( V_2 , V_111 ,
L_44 ,
V_332 , V_331 ) ;
}
return V_57 ;
}
int
F_82 ( struct V_1 * V_2 ,
struct V_5 * V_6 ,
struct V_341 * V_342 )
{
struct V_343 * V_344 ;
struct V_71 V_80 ;
union V_81 V_75 ;
V_19 V_260 ;
T_1 V_15 ;
int V_57 ;
V_344 = & V_75 . V_345 ;
V_344 -> V_346 = V_342 -> V_346 ;
for ( V_15 = 0 ; V_15 < ( V_100 - 4 ) / sizeof( T_1 ) ; V_15 ++ ) {
V_260 = F_62 ( * ( ( T_1 * ) & V_342 -> V_347 [ V_15 * sizeof( T_1 ) ] ) ) ;
* ( V_19 * ) & V_344 -> V_347 [ V_15 * sizeof( T_1 ) ] = V_260 ;
}
memset ( & V_80 , 0 , sizeof( V_80 ) ) ;
V_80 . V_45 = V_348 ;
V_80 . V_76 = & V_75 ;
V_57 = F_29 ( V_2 , V_6 , & V_80 ) ;
if ( V_57 )
F_27 ( V_2 , L_13 ) ;
return V_57 ;
}
int F_83 ( struct V_1 * V_2 , struct V_5 * V_6 )
{
T_1 V_245 = 0 , V_61 = 0 ;
int V_57 ;
V_57 = F_33 ( V_2 , V_6 , V_349 , 0 , & V_245 ,
& V_61 ) ;
if ( V_57 )
F_27 ( V_2 , L_13 ) ;
return V_57 ;
}
int F_84 ( struct V_1 * V_2 , struct V_5 * V_6 )
{
T_1 V_350 , V_351 ;
F_41 ( V_2 , V_6 , V_352 , 0xffffffff ) ;
V_350 = F_4 ( V_2 , V_6 , V_353 ) ;
V_350 &= ~ V_354 ;
F_41 ( V_2 , V_6 , V_353 , V_350 ) ;
V_351 = F_4 ( V_2 , V_6 , V_353 ) ;
return ( V_351 & V_354 ) ? - V_60 : 0 ;
}
int F_85 ( struct V_1 * V_2 ,
struct V_5 * V_6 ,
enum V_355 V_356 )
{
T_1 V_245 = 0 , V_61 = 0 ;
T_1 V_65 ;
int V_57 ;
switch ( V_356 ) {
case V_357 :
V_65 = V_358 ;
break;
case V_359 :
V_65 = V_360 ;
break;
case V_361 :
V_65 = V_362 ;
break;
default:
F_18 ( V_2 , L_45 , V_356 ) ;
return - V_259 ;
}
V_57 = F_33 ( V_2 , V_6 , V_363 ,
V_65 , & V_245 , & V_61 ) ;
if ( V_57 )
F_27 ( V_2 , L_13 ) ;
return V_57 ;
}
int F_86 ( struct V_1 * V_2 ,
struct V_5 * V_6 ,
enum V_364 V_365 )
{
T_1 V_245 = 0 , V_61 = 0 ;
T_1 V_65 ;
int V_57 ;
switch ( V_365 ) {
case V_366 :
V_65 = V_367 ;
break;
case V_368 :
V_65 = V_369 ;
break;
case V_370 :
V_65 = V_371 ;
break;
default:
F_18 ( V_2 , L_46 , V_365 ) ;
return - V_259 ;
}
V_57 = F_33 ( V_2 , V_6 , V_372 ,
V_65 , & V_245 , & V_61 ) ;
if ( V_57 )
F_27 ( V_2 , L_47 ) ;
return V_57 ;
}
int F_87 ( struct V_1 * V_2 ,
struct V_5 * V_6 , V_30 V_314 )
{
T_1 V_245 = 0 , V_61 = 0 ;
T_1 V_65 ;
int V_57 ;
V_65 = ( T_1 ) V_314 << V_373 ;
V_57 = F_33 ( V_2 , V_6 , V_374 ,
V_65 , & V_245 , & V_61 ) ;
if ( V_57 )
F_27 ( V_2 , L_48 , V_57 ) ;
return V_57 ;
}
int F_88 ( struct V_1 * V_2 ,
struct V_5 * V_6 , T_2 * V_302 )
{
struct V_71 V_80 ;
union V_81 V_75 ;
int V_57 ;
memset ( & V_80 , 0 , sizeof( V_80 ) ) ;
V_80 . V_45 = V_375 ;
V_80 . V_61 = V_376 <<
V_377 ;
V_80 . V_61 |= F_14 ( V_2 ) ;
F_89 ( & V_75 . V_93 [ 0 ] , V_302 ) ;
V_80 . V_76 = & V_75 ;
V_57 = F_29 ( V_2 , V_6 , & V_80 ) ;
if ( V_57 )
F_27 ( V_2 , L_49 , V_57 ) ;
memcpy ( V_2 -> V_83 -> V_87 , V_302 , V_303 ) ;
return V_57 ;
}
int F_90 ( struct V_1 * V_2 ,
struct V_5 * V_6 , enum V_378 V_379 )
{
T_1 V_245 = 0 , V_61 = 0 ;
T_1 V_65 ;
int V_57 ;
if ( V_2 -> V_280 . V_316 == V_317 ) {
F_7 ( V_2 , V_11 ,
L_50 ) ;
return - V_259 ;
}
switch ( V_379 ) {
case V_318 :
V_65 = V_380 ;
break;
case V_381 :
V_65 = V_382 ;
break;
case V_85 :
V_65 = V_383 ;
break;
default:
F_27 ( V_2 , L_51 , V_379 ) ;
return - V_259 ;
}
V_57 = F_33 ( V_2 , V_6 , V_384 ,
V_65 , & V_245 , & V_61 ) ;
if ( V_57 )
F_27 ( V_2 , L_52 , V_57 ) ;
V_2 -> V_83 -> V_84 = ( T_2 ) V_379 ;
return V_57 ;
}
int F_91 ( struct V_1 * V_2 ,
struct V_5 * V_6 ,
enum V_385 V_386 )
{
T_1 V_245 = 0 , V_61 = 0 ;
T_1 V_65 ;
int V_57 ;
switch ( V_386 ) {
case V_387 :
V_65 = V_388 ;
break;
case V_389 :
V_65 = V_390 ;
break;
case V_391 :
V_65 = V_392 ;
break;
default:
F_27 ( V_2 , L_53 , V_386 ) ;
return - V_259 ;
}
V_57 = F_33 ( V_2 , V_6 , V_393 ,
V_65 , & V_245 , & V_61 ) ;
if ( V_57 )
F_27 ( V_2 , L_54 , V_57 ) ;
return V_57 ;
}
int F_92 ( struct V_1 * V_2 ,
struct V_5 * V_6 , enum V_394 V_395 )
{
T_1 V_245 = 0 , V_61 = 0 , V_65 ;
int V_57 ;
switch ( V_395 ) {
case V_396 :
V_65 = V_397 ;
break;
case V_398 :
V_65 = V_399 ;
break;
case V_400 :
V_65 = V_401 ;
break;
default:
F_18 ( V_2 , L_55 , V_395 ) ;
return - V_259 ;
}
V_57 = F_33 ( V_2 , V_6 , V_402 ,
V_65 , & V_245 , & V_61 ) ;
return V_57 ;
}
int F_93 ( struct V_1 * V_2 ,
struct V_5 * V_6 , T_1 V_403 )
{
T_1 V_245 = 0 , V_61 = 0 ;
int V_57 ;
V_57 = F_33 ( V_2 , V_6 , V_404 ,
V_403 , & V_245 , & V_61 ) ;
if ( V_57 ) {
F_27 ( V_2 ,
L_56 ) ;
} else if ( V_245 != V_286 ) {
F_27 ( V_2 ,
L_57 ) ;
V_57 = - V_259 ;
}
return V_57 ;
}
int F_94 ( struct V_95 * V_83 , T_1 V_7 , T_2 * V_405 , T_1 V_406 )
{
T_1 V_407 = V_406 , V_408 = 0 , V_409 , V_410 = 0 ;
struct V_1 * V_2 = F_95 ( V_83 ) ;
T_1 V_245 = 0 , V_411 = 0 ;
struct V_5 * V_6 ;
int V_57 = 0 ;
V_6 = F_66 ( V_2 ) ;
if ( ! V_6 )
return - V_49 ;
while ( V_407 > 0 ) {
V_409 = F_55 ( T_1 , V_407 , V_412 ) ;
V_57 = F_34 ( V_2 , V_6 ,
V_413 ,
V_7 + V_408 +
( V_409 <<
V_414 ) ,
& V_245 , & V_411 ,
& V_410 ,
( T_1 * ) ( V_405 + V_408 ) ) ;
if ( V_57 || ( V_245 != V_415 ) ) {
F_18 ( V_83 , L_58 , V_57 ) ;
break;
}
if ( V_407 % 0x1000 <
( V_407 - V_410 ) % 0x1000 )
F_96 ( 1000 , 2000 ) ;
V_408 += V_410 ;
V_407 -= V_410 ;
}
V_83 -> V_416 = V_245 ;
F_67 ( V_2 , V_6 ) ;
return V_57 ;
}
int F_97 ( struct V_1 * V_2 , struct V_5 * V_6 )
{
T_1 V_65 = 0 , V_417 , V_61 ;
int V_57 = 0 ;
V_65 = ( V_418 <<
V_419 ) ;
V_57 = F_33 ( V_2 , V_6 , V_420 ,
V_65 , & V_417 , & V_61 ) ;
if ( V_57 )
return V_57 ;
if ( ( ( V_417 & V_69 ) != V_286 ) ||
( V_61 != V_421 ) )
V_57 = - V_60 ;
return V_57 ;
}
int F_98 ( struct V_1 * V_2 , struct V_5 * V_6 )
{
T_1 V_65 , V_417 , V_61 ;
int V_57 = 0 ;
V_65 = ( V_422 <<
V_419 ) ;
V_57 = F_33 ( V_2 , V_6 , V_420 ,
V_65 , & V_417 , & V_61 ) ;
if ( V_57 )
return V_57 ;
if ( ( ( V_417 & V_69 ) != V_286 ) ||
( V_61 != V_421 ) )
V_57 = - V_60 ;
return V_57 ;
}
int F_99 ( struct V_1 * V_2 ,
struct V_5 * V_6 ,
T_1 * V_423 )
{
T_1 V_65 = 0 , V_417 ;
int V_57 = 0 ;
V_65 = ( V_424 <<
V_419 ) ;
V_57 = F_33 ( V_2 , V_6 , V_420 ,
V_65 , & V_417 , V_423 ) ;
if ( V_57 )
return V_57 ;
if ( ( ( V_417 & V_69 ) != V_286 ) )
V_57 = - V_259 ;
return V_57 ;
}
int F_100 ( struct V_1 * V_2 ,
struct V_5 * V_6 ,
struct V_425 * V_426 ,
T_1 V_427 )
{
T_1 V_428 = 0 , V_61 , V_245 = 0 , V_411 = 0 ;
int V_57 ;
V_61 = V_429 <<
V_419 ;
V_61 |= V_427 << V_430 ;
V_57 = F_34 ( V_2 , V_6 ,
V_420 , V_61 ,
& V_245 , & V_411 ,
& V_428 ,
( T_1 * ) V_426 ) ;
if ( V_57 )
return V_57 ;
if ( ( ( V_245 & V_69 ) != V_286 ) ||
( V_426 -> V_431 != 1 ) )
V_57 = - V_259 ;
return V_57 ;
}
int F_101 ( struct V_1 * V_2 ,
struct V_5 * V_6 ,
struct V_432 * V_433 ,
T_1 * V_434 , T_1 * V_435 )
{
struct V_71 V_80 ;
union V_81 V_75 ;
int V_57 ;
memset ( & V_80 , 0 , sizeof( V_80 ) ) ;
memset ( & V_75 , 0 , sizeof( V_75 ) ) ;
V_80 . V_45 = V_436 ;
V_80 . V_61 = V_437 ;
memcpy ( & V_75 . V_438 , V_433 , sizeof( * V_433 ) ) ;
V_80 . V_76 = & V_75 ;
V_80 . V_79 = & V_75 ;
V_57 = F_29 ( V_2 , V_6 , & V_80 ) ;
if ( V_57 )
return V_57 ;
memcpy ( V_433 , & V_75 . V_438 , sizeof( * V_433 ) ) ;
* V_434 = V_80 . V_77 ;
* V_435 = V_80 . V_78 ;
F_7 ( V_2 ,
V_11 ,
L_59 ,
* V_435 ,
V_433 -> V_439 ,
V_433 -> V_39 ,
V_433 -> V_408 ,
V_433 -> V_440 ,
V_433 -> V_441 , V_433 -> V_442 ) ;
return 0 ;
}
