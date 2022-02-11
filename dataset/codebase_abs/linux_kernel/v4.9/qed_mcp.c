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
int V_56 ;
memset ( & V_79 , 0 , sizeof( V_79 ) ) ;
V_79 . V_44 = V_44 ;
V_79 . V_60 = V_60 ;
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
T_1 * V_62 , T_1 * V_80 , T_1 * V_81 )
{
struct V_70 V_79 ;
union V_82 V_74 ;
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
* V_80 = * V_62 ;
memcpy ( V_81 , & V_74 . V_83 , * V_80 ) ;
return 0 ;
}
int F_35 ( struct V_1 * V_2 ,
struct V_5 * V_6 , T_1 * V_84 )
{
struct V_85 * V_86 = V_2 -> V_86 ;
struct V_70 V_79 ;
union V_82 V_74 ;
int V_56 ;
memset ( & V_79 , 0 , sizeof( V_79 ) ) ;
V_79 . V_44 = V_49 ;
V_79 . V_60 = V_87 | V_88 |
V_86 -> V_89 ;
memcpy ( & V_74 . V_90 , V_86 -> V_90 , V_91 ) ;
V_79 . V_75 = & V_74 ;
V_56 = F_29 ( V_2 , V_6 , & V_79 ) ;
if ( V_56 ) {
F_27 ( V_2 , L_12 ) ;
return V_56 ;
}
* V_84 = V_79 . V_76 ;
if ( ! ( * V_84 ) ||
( ( * V_84 ) == V_92 ) ||
( ( * V_84 ) == V_93 ) ||
( ( * V_84 ) == V_94 ) ) {
F_27 ( V_2 , L_13 ) ;
return - V_48 ;
}
return 0 ;
}
static void F_36 ( struct V_1 * V_2 ,
struct V_5 * V_6 )
{
T_1 V_7 = F_3 ( V_2 -> V_3 -> V_4 ,
V_95 ) ;
T_1 V_96 = F_4 ( V_2 , V_6 , V_7 ) ;
T_1 V_97 = F_5 ( V_96 ,
F_37 ( V_2 ) ) ;
T_1 V_98 [ V_99 / 32 ] ;
int V_15 ;
F_7 ( V_2 ,
V_11 ,
L_14 ,
V_96 , V_97 ) ;
for ( V_15 = 0 ; V_15 < ( V_99 / 32 ) ; V_15 ++ ) {
V_98 [ V_15 ] = F_4 ( V_2 , V_6 ,
V_97 +
F_30 ( struct V_100 ,
V_101 ) +
sizeof( T_1 ) * V_15 ) ;
F_7 ( V_2 , ( V_11 | V_102 ) ,
L_15 ,
V_15 * 32 , ( V_15 + 1 ) * 32 - 1 , V_98 [ V_15 ] ) ;
}
if ( F_38 ( V_2 , V_98 ) )
F_39 ( V_2 , V_103 ) ;
}
int F_40 ( struct V_1 * V_2 ,
struct V_5 * V_6 , T_1 * V_104 )
{
T_1 V_7 = F_3 ( V_2 -> V_3 -> V_4 ,
V_105 ) ;
T_1 V_106 = F_4 ( V_2 , V_6 , V_7 ) ;
T_1 V_107 = F_5 ( V_106 ,
F_14 ( V_2 ) ) ;
struct V_70 V_79 ;
union V_82 V_74 ;
int V_56 ;
int V_15 ;
for ( V_15 = 0 ; V_15 < ( V_99 / 32 ) ; V_15 ++ )
F_7 ( V_2 , ( V_11 | V_102 ) ,
L_16 ,
V_15 * 32 , ( V_15 + 1 ) * 32 - 1 , V_104 [ V_15 ] ) ;
memset ( & V_79 , 0 , sizeof( V_79 ) ) ;
V_79 . V_44 = V_108 ;
memcpy ( & V_74 . V_109 , V_104 , V_99 / 8 ) ;
V_79 . V_75 = & V_74 ;
V_56 = F_29 ( V_2 , V_6 , & V_79 ) ;
if ( V_56 ) {
F_18 ( V_2 , L_17 ) ;
return - V_48 ;
}
for ( V_15 = 0 ; V_15 < ( V_99 / 32 ) ; V_15 ++ )
F_41 ( V_2 , V_6 ,
V_107 +
F_30 ( struct V_110 , V_111 ) +
V_15 * sizeof( T_1 ) , 0 ) ;
return V_56 ;
}
static void F_42 ( struct V_1 * V_2 ,
struct V_5 * V_6 )
{
T_1 V_112 ;
V_112 = F_4 ( V_2 , V_6 ,
V_2 -> V_3 -> V_10 +
F_30 ( struct V_113 ,
V_114 ) ) ;
F_7 ( V_2 ,
( V_115 | V_11 ) ,
L_18 ,
V_112 ,
( T_1 ) ( V_2 -> V_3 -> V_10 +
F_30 ( struct V_113 , V_114 ) ) ) ;
V_112 = F_43 ( V_112 ,
V_116 ) ;
if ( V_112 == V_117 )
F_18 ( V_2 , L_19 ) ;
else
F_18 ( V_2 , L_20 ) ;
}
static void F_44 ( struct V_1 * V_2 ,
struct V_5 * V_6 , bool V_118 )
{
struct V_119 * V_120 ;
T_2 V_121 , V_122 ;
T_1 V_123 = 0 ;
V_120 = & V_2 -> V_3 -> V_124 ;
memset ( V_120 , 0 , sizeof( * V_120 ) ) ;
if ( ! V_118 ) {
V_123 = F_4 ( V_2 , V_6 ,
V_2 -> V_3 -> V_10 +
F_30 ( struct V_113 , V_125 ) ) ;
F_7 ( V_2 , ( V_126 | V_11 ) ,
L_21 ,
V_123 ,
( T_1 ) ( V_2 -> V_3 -> V_10 +
F_30 ( struct V_113 , V_125 ) ) ) ;
} else {
F_7 ( V_2 , V_126 ,
L_22 ) ;
return;
}
if ( V_2 -> V_127 )
V_120 -> V_128 = ! ! ( V_123 & V_129 ) ;
else
V_120 -> V_128 = false ;
V_120 -> V_130 = true ;
switch ( ( V_123 & V_131 ) ) {
case V_132 :
V_120 -> V_133 = 100000 ;
break;
case V_134 :
V_120 -> V_133 = 50000 ;
break;
case V_135 :
V_120 -> V_133 = 40000 ;
break;
case V_136 :
V_120 -> V_133 = 25000 ;
break;
case V_137 :
V_120 -> V_133 = 20000 ;
break;
case V_138 :
V_120 -> V_133 = 10000 ;
break;
case V_139 :
V_120 -> V_130 = false ;
case V_140 :
V_120 -> V_133 = 1000 ;
break;
default:
V_120 -> V_133 = 0 ;
}
if ( V_120 -> V_128 && V_120 -> V_133 )
V_120 -> V_141 = V_120 -> V_133 ;
else
V_120 -> V_141 = 0 ;
V_121 = V_2 -> V_3 -> V_142 . V_143 ;
V_122 = V_2 -> V_3 -> V_142 . V_144 ;
F_45 ( V_2 , V_6 , V_120 , V_121 ) ;
F_46 ( V_2 , V_6 , V_120 , V_122 ) ;
F_47 ( V_2 -> V_86 , V_120 -> V_145 ) ;
V_120 -> V_146 = ! ! ( V_123 & V_147 ) ;
V_120 -> V_148 = ! ! ( V_123 &
V_149 ) ;
V_120 -> V_150 = ! ! ( V_123 &
V_151 ) ;
V_120 -> V_152 = ! ! ( V_123 & V_153 ) ;
V_120 -> V_154 |=
( V_123 & V_155 ) ?
V_156 : 0 ;
V_120 -> V_154 |=
( V_123 & V_157 ) ?
V_158 : 0 ;
V_120 -> V_154 |=
( V_123 & V_159 ) ?
V_160 : 0 ;
V_120 -> V_154 |=
( V_123 & V_161 ) ?
V_162 : 0 ;
V_120 -> V_154 |=
( V_123 & V_163 ) ?
V_164 : 0 ;
V_120 -> V_154 |=
( V_123 & V_165 ) ?
V_166 : 0 ;
V_120 -> V_154 |=
( V_123 & V_167 ) ?
V_168 : 0 ;
V_120 -> V_154 |=
( V_123 & V_169 ) ?
V_170 : 0 ;
V_120 -> V_171 =
! ! ( V_123 & V_172 ) ;
V_120 -> V_173 =
! ! ( V_123 & V_174 ) ;
switch ( V_123 & V_175 ) {
case V_176 :
V_120 -> V_177 = V_178 ;
break;
case V_179 :
V_120 -> V_177 = V_180 ;
break;
case V_181 :
V_120 -> V_177 = V_182 ;
break;
default:
V_120 -> V_177 = 0 ;
}
V_120 -> V_183 = ! ! ( V_123 & V_184 ) ;
F_48 ( V_2 ) ;
}
int F_49 ( struct V_1 * V_2 , struct V_5 * V_6 , bool V_185 )
{
struct V_186 * V_187 = & V_2 -> V_3 -> V_188 ;
struct V_70 V_79 ;
union V_82 V_74 ;
struct V_189 * V_190 ;
int V_56 = 0 ;
T_1 V_44 ;
V_190 = & V_74 . V_191 ;
memset ( V_190 , 0 , sizeof( * V_190 ) ) ;
V_44 = V_185 ? V_192 : V_193 ;
if ( ! V_187 -> V_133 . V_194 )
V_190 -> V_133 = V_187 -> V_133 . V_195 ;
V_190 -> V_196 |= ( V_187 -> V_196 . V_194 ) ? V_197 : 0 ;
V_190 -> V_196 |= ( V_187 -> V_196 . V_198 ) ? V_199 : 0 ;
V_190 -> V_196 |= ( V_187 -> V_196 . V_200 ) ? V_201 : 0 ;
V_190 -> V_202 = V_187 -> V_133 . V_203 ;
V_190 -> V_204 = V_187 -> V_204 ;
V_2 -> V_127 = V_185 ;
if ( V_185 ) {
F_7 ( V_2 , V_126 ,
L_23 ,
V_190 -> V_133 ,
V_190 -> V_196 ,
V_190 -> V_202 ,
V_190 -> V_204 ,
V_190 -> V_205 ) ;
} else {
F_7 ( V_2 , V_126 ,
L_24 ) ;
}
memset ( & V_79 , 0 , sizeof( V_79 ) ) ;
V_79 . V_44 = V_44 ;
V_79 . V_75 = & V_74 ;
V_56 = F_29 ( V_2 , V_6 , & V_79 ) ;
if ( V_56 ) {
F_27 ( V_2 , L_12 ) ;
return V_56 ;
}
if ( ! V_185 )
F_44 ( V_2 , V_6 , true ) ;
return 0 ;
}
static void F_50 ( struct V_1 * V_2 ,
struct V_5 * V_6 ,
enum V_206 type )
{
enum V_207 V_208 ;
union V_209 V_210 ;
struct V_70 V_79 ;
union V_82 V_74 ;
T_1 V_211 ;
switch ( type ) {
case V_212 :
V_208 = V_213 ;
V_211 = V_214 ;
break;
case V_215 :
V_208 = V_216 ;
V_211 = V_217 ;
break;
case V_218 :
V_208 = V_219 ;
V_211 = V_220 ;
break;
case V_221 :
V_208 = V_222 ;
V_211 = V_223 ;
break;
default:
F_18 ( V_2 , L_25 , type ) ;
return;
}
F_51 ( V_2 -> V_86 , V_208 , & V_210 ) ;
memset ( & V_79 , 0 , sizeof( V_79 ) ) ;
V_79 . V_44 = V_224 ;
V_79 . V_60 = V_211 ;
memcpy ( & V_74 , & V_210 , sizeof( V_210 ) ) ;
V_79 . V_75 = & V_74 ;
F_29 ( V_2 , V_6 , & V_79 ) ;
}
static void F_52 ( struct V_1 * V_2 ,
struct V_110 * V_225 )
{
struct V_226 * V_22 ;
V_22 = & V_2 -> V_3 -> V_142 ;
V_22 -> V_144 = ( V_225 -> V_227 &
V_228 ) >>
V_229 ;
if ( V_22 -> V_144 < 1 || V_22 -> V_144 > 100 ) {
F_53 ( V_2 ,
L_26 ,
V_22 -> V_144 ) ;
V_22 -> V_144 = 1 ;
}
V_22 -> V_143 = ( V_225 -> V_227 &
V_230 ) >>
V_231 ;
if ( V_22 -> V_143 < 1 || V_22 -> V_143 > 100 ) {
F_53 ( V_2 ,
L_27 ,
V_22 -> V_143 ) ;
V_22 -> V_143 = 100 ;
}
}
static T_1 F_54 ( struct V_1 * V_2 ,
struct V_5 * V_6 ,
struct V_110 * V_232 , int V_233 )
{
T_1 V_7 = F_3 ( V_2 -> V_3 -> V_4 ,
V_105 ) ;
T_1 V_96 = F_4 ( V_2 , V_6 , V_7 ) ;
T_1 V_107 = F_5 ( V_96 , V_233 ) ;
T_1 V_15 , V_39 ;
memset ( V_232 , 0 , sizeof( * V_232 ) ) ;
V_39 = F_55 ( T_1 , sizeof( * V_232 ) , F_56 ( V_96 ) ) ;
for ( V_15 = 0 ; V_15 < V_39 / sizeof( T_1 ) ; V_15 ++ )
( ( T_1 * ) V_232 ) [ V_15 ] = F_4 ( V_2 , V_6 ,
V_107 + ( V_15 << 2 ) ) ;
return V_39 ;
}
static void F_57 ( struct V_1 * V_2 , struct V_5 * V_6 )
{
struct V_226 * V_22 ;
struct V_110 V_234 ;
T_1 V_235 = 0 , V_60 = 0 ;
F_54 ( V_2 , V_6 , & V_234 , F_14 ( V_2 ) ) ;
F_52 ( V_2 , & V_234 ) ;
V_22 = & V_2 -> V_3 -> V_142 ;
F_58 ( V_2 -> V_86 , V_22 -> V_144 ) ;
F_59 ( V_2 -> V_86 , V_22 -> V_143 ) ;
F_33 ( V_2 , V_6 , V_236 , 0 , & V_235 ,
& V_60 ) ;
}
int F_60 ( struct V_1 * V_2 ,
struct V_5 * V_6 )
{
struct V_21 * V_237 = V_2 -> V_3 ;
int V_56 = 0 ;
bool V_238 = false ;
V_30 V_15 ;
F_7 ( V_2 , V_11 , L_28 ) ;
F_8 ( V_2 , V_6 ) ;
for ( V_15 = 0 ; V_15 < V_237 -> V_13 ; V_15 ++ ) {
if ( V_237 -> V_17 [ V_15 ] == V_237 -> V_20 [ V_15 ] )
continue;
V_238 = true ;
F_7 ( V_2 , V_126 ,
L_29 ,
V_15 , V_237 -> V_20 [ V_15 ] , V_237 -> V_17 [ V_15 ] ) ;
switch ( V_15 ) {
case V_239 :
F_44 ( V_2 , V_6 , false ) ;
break;
case V_240 :
F_36 ( V_2 , V_6 ) ;
break;
case V_241 :
F_61 ( V_2 , V_6 ,
V_242 ) ;
break;
case V_243 :
F_61 ( V_2 , V_6 ,
V_244 ) ;
break;
case V_245 :
F_61 ( V_2 , V_6 ,
V_246 ) ;
break;
case V_247 :
F_42 ( V_2 , V_6 ) ;
break;
case V_212 :
case V_215 :
case V_218 :
case V_221 :
F_50 ( V_2 , V_6 , V_15 ) ;
break;
case V_248 :
F_57 ( V_2 , V_6 ) ;
break;
default:
F_18 ( V_2 , L_30 , V_15 ) ;
V_56 = - V_249 ;
}
}
for ( V_15 = 0 ; V_15 < F_9 ( V_237 -> V_13 ) ; V_15 ++ ) {
V_19 V_250 = F_62 ( ( ( T_1 * ) V_237 -> V_17 ) [ V_15 ] ) ;
F_41 ( V_2 , V_6 ,
V_237 -> V_16 + sizeof( T_1 ) +
F_9 ( V_237 -> V_13 ) *
sizeof( T_1 ) + V_15 * sizeof( T_1 ) ,
( V_18 T_1 ) V_250 ) ;
}
if ( ! V_238 ) {
F_18 ( V_2 ,
L_31 ) ;
V_56 = - V_249 ;
}
memcpy ( V_237 -> V_20 , V_237 -> V_17 , V_237 -> V_13 ) ;
return V_56 ;
}
int F_63 ( struct V_1 * V_2 ,
struct V_5 * V_6 ,
T_1 * V_251 , T_1 * V_252 )
{
T_1 V_253 ;
if ( F_64 ( V_2 -> V_86 ) ) {
if ( V_2 -> V_254 ) {
struct V_255 * V_256 ;
V_256 = & V_2 -> V_254 -> V_257 ;
* V_251 = V_256 -> V_258 . V_259 ;
return 0 ;
} else {
F_7 ( V_2 ,
V_102 ,
L_32 ) ;
return - V_249 ;
}
}
V_253 = F_4 ( V_2 , V_6 ,
F_3 ( V_2 ->
V_3 -> V_4 ,
V_260 ) ) ;
* V_251 =
F_4 ( V_2 , V_6 ,
F_5 ( V_253 ,
0 ) + F_30 ( struct V_261 , V_259 ) ) ;
if ( V_252 != NULL ) {
* V_252 = F_4 ( V_2 , V_6 ,
F_5 ( V_253 , 0 ) +
F_30 ( struct V_261 ,
V_262 ) ) ;
}
return 0 ;
}
int F_65 ( struct V_85 * V_86 , T_1 * V_263 )
{
struct V_1 * V_2 = & V_86 -> V_264 [ 0 ] ;
struct V_5 * V_6 ;
if ( F_64 ( V_86 ) )
return - V_249 ;
if ( ! F_1 ( V_2 ) ) {
F_18 ( V_2 , L_11 ) ;
return - V_48 ;
}
* V_263 = V_265 ;
V_6 = F_66 ( V_2 ) ;
if ( ! V_6 )
return - V_48 ;
* V_263 = F_4 ( V_2 , V_6 , V_2 -> V_3 -> V_10 +
F_30 ( struct V_113 , V_266 ) ) ;
F_67 ( V_2 , V_6 ) ;
return 0 ;
}
static int
F_68 ( struct V_1 * V_2 ,
struct V_110 * V_22 ,
enum V_267 * V_268 )
{
int V_56 = 0 ;
switch ( V_22 -> V_227 & V_269 ) {
case V_270 :
if ( F_69 ( V_271 ,
& V_2 -> V_272 . V_273 ) )
* V_268 = V_274 ;
else
* V_268 = V_275 ;
break;
case V_276 :
* V_268 = V_277 ;
break;
case V_278 :
F_18 ( V_2 , L_33 ) ;
V_56 = - V_249 ;
break;
default:
V_56 = - V_249 ;
}
return V_56 ;
}
int F_70 ( struct V_1 * V_2 ,
struct V_5 * V_6 )
{
struct V_226 * V_237 ;
struct V_110 V_234 ;
F_54 ( V_2 , V_6 , & V_234 , F_14 ( V_2 ) ) ;
V_237 = & V_2 -> V_3 -> V_142 ;
V_237 -> V_279 = ( V_234 . V_227 &
V_280 ) ? 1 : 0 ;
if ( F_68 ( V_2 , & V_234 , & V_237 -> V_281 ) ) {
F_27 ( V_2 , L_34 ,
( T_1 ) ( V_234 . V_227 & V_269 ) ) ;
return - V_249 ;
}
F_52 ( V_2 , & V_234 ) ;
if ( V_234 . V_282 || V_234 . V_283 ) {
V_237 -> V_284 [ 0 ] = ( T_2 ) ( V_234 . V_282 >> 8 ) ;
V_237 -> V_284 [ 1 ] = ( T_2 ) ( V_234 . V_282 ) ;
V_237 -> V_284 [ 2 ] = ( T_2 ) ( V_234 . V_283 >> 24 ) ;
V_237 -> V_284 [ 3 ] = ( T_2 ) ( V_234 . V_283 >> 16 ) ;
V_237 -> V_284 [ 4 ] = ( T_2 ) ( V_234 . V_283 >> 8 ) ;
V_237 -> V_284 [ 5 ] = ( T_2 ) ( V_234 . V_283 ) ;
} else {
F_18 ( V_2 , L_35 ) ;
}
V_237 -> V_285 = ( V_286 ) V_234 . V_287 |
( ( ( V_286 ) V_234 . V_288 ) << 32 ) ;
V_237 -> V_289 = ( V_286 ) V_234 . V_290 |
( ( ( V_286 ) V_234 . V_291 ) << 32 ) ;
V_237 -> V_292 = ( V_30 ) ( V_234 . V_293 & V_294 ) ;
F_7 ( V_2 , ( V_11 | V_295 ) ,
L_36 ,
V_237 -> V_279 , V_237 -> V_281 ,
V_237 -> V_144 , V_237 -> V_143 ,
V_237 -> V_284 [ 0 ] , V_237 -> V_284 [ 1 ] , V_237 -> V_284 [ 2 ] ,
V_237 -> V_284 [ 3 ] , V_237 -> V_284 [ 4 ] , V_237 -> V_284 [ 5 ] ,
V_237 -> V_285 , V_237 -> V_289 , V_237 -> V_292 ) ;
return 0 ;
}
struct V_186
* F_71 ( struct V_1 * V_2 )
{
if ( ! V_2 || ! V_2 -> V_3 )
return NULL ;
return & V_2 -> V_3 -> V_188 ;
}
struct V_119
* F_72 ( struct V_1 * V_2 )
{
if ( ! V_2 || ! V_2 -> V_3 )
return NULL ;
return & V_2 -> V_3 -> V_124 ;
}
struct V_296
* F_73 ( struct V_1 * V_2 )
{
if ( ! V_2 || ! V_2 -> V_3 )
return NULL ;
return & V_2 -> V_3 -> V_297 ;
}
int F_74 ( struct V_1 * V_2 , struct V_5 * V_6 )
{
T_1 V_235 = 0 , V_60 = 0 ;
int V_56 ;
V_56 = F_33 ( V_2 , V_6 ,
V_298 , 1000 , & V_235 , & V_60 ) ;
F_75 ( 1020 ) ;
return V_56 ;
}
int F_76 ( struct V_1 * V_2 ,
struct V_5 * V_6 , T_1 * V_299 )
{
T_1 V_300 ;
if ( F_64 ( V_2 -> V_86 ) )
return - V_249 ;
V_300 = F_4 ( V_2 , V_6 , V_301 ) ;
V_300 = ( V_300 & V_302 ) >>
V_303 ;
V_300 = ( 1 << ( V_300 + V_304 ) ) ;
* V_299 = V_300 ;
return 0 ;
}
int F_77 ( struct V_1 * V_2 ,
struct V_5 * V_6 , T_2 V_305 , T_2 V_306 )
{
T_1 V_235 = 0 , V_60 = 0 , V_307 = 0 ;
int V_56 ;
if ( ! F_78 ( V_2 ) )
return 0 ;
V_306 *= V_2 -> V_86 -> V_308 ;
V_60 |= ( V_305 << V_309 ) &
V_310 ;
V_60 |= ( V_306 << V_311 ) &
V_312 ;
V_56 = F_33 ( V_2 , V_6 , V_313 , V_60 ,
& V_235 , & V_307 ) ;
if ( V_235 != V_314 ) {
F_18 ( V_2 , L_37 , V_305 ) ;
V_56 = - V_249 ;
} else {
F_7 ( V_2 , V_102 ,
L_38 ,
V_306 , V_305 ) ;
}
return V_56 ;
}
int
F_79 ( struct V_1 * V_2 ,
struct V_5 * V_6 ,
struct V_315 * V_316 )
{
struct V_317 * V_318 ;
struct V_70 V_79 ;
union V_82 V_74 ;
V_19 V_250 ;
T_1 V_15 ;
int V_56 ;
V_318 = & V_74 . V_319 ;
V_318 -> V_320 = V_316 -> V_320 ;
for ( V_15 = 0 ; V_15 < ( V_91 - 4 ) / sizeof( T_1 ) ; V_15 ++ ) {
V_250 = F_62 ( * ( ( T_1 * ) & V_316 -> V_321 [ V_15 * sizeof( T_1 ) ] ) ) ;
* ( V_19 * ) & V_318 -> V_321 [ V_15 * sizeof( T_1 ) ] = V_250 ;
}
memset ( & V_79 , 0 , sizeof( V_79 ) ) ;
V_79 . V_44 = V_322 ;
V_79 . V_75 = & V_74 ;
V_56 = F_29 ( V_2 , V_6 , & V_79 ) ;
if ( V_56 )
F_27 ( V_2 , L_12 ) ;
return V_56 ;
}
int F_80 ( struct V_1 * V_2 , struct V_5 * V_6 )
{
T_1 V_235 = 0 , V_60 = 0 ;
int V_56 ;
V_56 = F_33 ( V_2 , V_6 , V_323 , 0 , & V_235 ,
& V_60 ) ;
if ( V_56 )
F_27 ( V_2 , L_12 ) ;
return V_56 ;
}
int F_81 ( struct V_1 * V_2 , struct V_5 * V_6 )
{
T_1 V_324 , V_325 ;
F_41 ( V_2 , V_6 , V_326 , 0xffffffff ) ;
V_324 = F_4 ( V_2 , V_6 , V_327 ) ;
V_324 &= ~ V_328 ;
F_41 ( V_2 , V_6 , V_327 , V_324 ) ;
V_325 = F_4 ( V_2 , V_6 , V_327 ) ;
return ( V_325 & V_328 ) ? - V_59 : 0 ;
}
int F_82 ( struct V_1 * V_2 ,
struct V_5 * V_6 , enum V_329 V_330 )
{
T_1 V_235 = 0 , V_60 = 0 , V_64 ;
int V_56 ;
switch ( V_330 ) {
case V_331 :
V_64 = V_332 ;
break;
case V_333 :
V_64 = V_334 ;
break;
case V_335 :
V_64 = V_336 ;
break;
default:
F_18 ( V_2 , L_39 , V_330 ) ;
return - V_249 ;
}
V_56 = F_33 ( V_2 , V_6 , V_337 ,
V_64 , & V_235 , & V_60 ) ;
return V_56 ;
}
int F_83 ( struct V_1 * V_2 ,
struct V_5 * V_6 , T_1 V_338 )
{
T_1 V_235 = 0 , V_60 = 0 ;
int V_56 ;
V_56 = F_33 ( V_2 , V_6 , V_339 ,
V_338 , & V_235 , & V_60 ) ;
if ( V_56 ) {
F_27 ( V_2 ,
L_40 ) ;
} else if ( V_235 != V_340 ) {
F_27 ( V_2 ,
L_41 ) ;
V_56 = - V_249 ;
}
return V_56 ;
}
int F_84 ( struct V_1 * V_2 , struct V_5 * V_6 )
{
T_1 V_64 = 0 , V_341 , V_60 ;
int V_56 = 0 ;
V_64 = ( V_342 <<
V_343 ) ;
V_56 = F_33 ( V_2 , V_6 , V_344 ,
V_64 , & V_341 , & V_60 ) ;
if ( V_56 )
return V_56 ;
if ( ( ( V_341 & V_68 ) != V_340 ) ||
( V_60 != V_345 ) )
V_56 = - V_59 ;
return V_56 ;
}
int F_85 ( struct V_1 * V_2 , struct V_5 * V_6 )
{
T_1 V_64 , V_341 , V_60 ;
int V_56 = 0 ;
V_64 = ( V_346 <<
V_343 ) ;
V_56 = F_33 ( V_2 , V_6 , V_344 ,
V_64 , & V_341 , & V_60 ) ;
if ( V_56 )
return V_56 ;
if ( ( ( V_341 & V_68 ) != V_340 ) ||
( V_60 != V_345 ) )
V_56 = - V_59 ;
return V_56 ;
}
