static int F_1 ( struct V_1 * V_2 ,
T_1 V_3 ,
T_2 V_4 ,
T_3 V_5 ,
T_2 V_6 ,
T_3 V_7 ,
T_3 V_8 )
{
struct V_9 V_10 ;
struct V_11 * V_12 = NULL ;
struct V_13 * V_14 = NULL ;
int V_15 = - V_16 ;
T_2 V_17 = 0 ;
T_3 V_18 = 0 ;
V_15 = F_2 ( V_2 , V_5 , & V_18 ) ;
if ( V_15 != 0 )
return V_15 ;
memset ( & V_10 , 0 , sizeof( V_10 ) ) ;
V_10 . V_19 = sizeof( * V_12 ) ;
V_10 . V_20 = V_21 ;
V_15 = F_3 ( V_2 , & V_14 ,
F_4 ( V_2 ) ,
V_4 ,
V_22 ,
V_23 ,
& V_10 ) ;
if ( V_15 )
return V_15 ;
V_12 = & V_14 -> V_24 . V_25 ;
V_12 -> V_5 = V_18 ;
V_12 -> V_6 = F_5 ( V_6 ) ;
V_12 -> V_26 = V_8 ;
V_12 -> V_27 = V_7 ;
F_6 ( V_17 , V_28 , 1 ) ;
F_6 ( V_17 , V_29 , 1 ) ;
V_12 -> V_17 . V_30 = F_5 ( V_17 ) ;
memset ( & V_12 -> V_31 , 0 ,
sizeof( struct V_32 ) ) ;
V_12 -> V_33 = F_7 ( V_2 -> V_34 ,
V_3 ) ;
return F_8 ( V_2 , V_14 , NULL ) ;
}
static int
F_9 ( struct V_1 * V_2 ,
struct V_35 * V_12 ,
struct V_36 * V_37 )
{
struct V_38 * V_39 = & V_12 -> V_40 ;
T_2 V_41 = 0 , V_42 = 0 ;
int V_15 = 0 , V_43 ;
if ( ! V_37 ) {
V_12 -> V_44 . V_45 = 0 ;
return V_15 ;
}
F_10 ( V_46 !=
V_47 ) ;
V_15 = F_11 ( V_2 , V_37 -> V_48 , & V_39 -> V_49 ) ;
if ( V_15 )
return V_15 ;
V_12 -> V_44 . V_45 = V_37 -> V_50 ;
V_39 -> V_51 = V_37 -> V_51 ;
V_39 -> V_52 = V_37 -> V_52 ;
V_39 -> V_53 = V_37 -> V_53 ;
V_39 -> V_54 = V_37 -> V_55 ?
V_56 :
V_57 ;
F_6 ( V_42 ,
V_58 ,
! ! ( V_37 -> V_59 & V_60 ) ) ;
F_6 ( V_42 ,
V_61 ,
! ! ( V_37 -> V_59 & V_62 ) ) ;
F_6 ( V_42 ,
V_63 ,
! ! ( V_37 -> V_59 & V_64 ) ) ;
F_6 ( V_42 ,
V_65 ,
! ! ( V_37 -> V_59 & V_66 ) ) ;
F_6 ( V_42 ,
V_67 ,
! ! ( V_37 -> V_59 & V_68 ) ) ;
F_6 ( V_42 ,
V_69 ,
! ! ( V_37 -> V_59 & V_70 ) ) ;
V_39 -> V_71 = V_37 -> V_72 ;
V_39 -> V_42 = F_5 ( V_42 ) ;
F_12 ( V_2 , V_73 ,
L_1 ,
V_12 -> V_44 . V_45 ,
V_39 -> V_54 , V_39 -> V_51 ,
V_42 , V_39 -> V_52 ,
V_39 -> V_53 ) ;
for ( V_43 = 0 ; V_43 < V_46 ; V_43 ++ ) {
V_15 = F_13 ( V_2 ,
( T_3 ) V_37 -> V_74 [ V_43 ] ,
& V_41 ) ;
if ( V_15 )
return V_15 ;
V_39 -> V_75 [ V_43 ] = F_5 ( V_41 ) ;
F_12 ( V_2 , V_73 , L_2 ,
V_43 , V_39 -> V_75 [ V_43 ] ) ;
}
for ( V_43 = 0 ; V_43 < 10 ; V_43 ++ )
V_39 -> V_76 [ V_43 ] = F_14 ( V_37 -> V_76 [ V_43 ] ) ;
return V_15 ;
}
static void
F_15 ( struct V_1 * V_2 ,
struct V_35 * V_12 ,
struct V_77 V_78 )
{
V_12 -> V_44 . V_79 =
V_78 . V_80 ;
V_12 -> V_44 . V_81 =
V_78 . V_82 ;
if ( V_12 -> V_44 . V_79 ) {
T_3 V_83 = V_78 . V_84 ;
T_2 V_30 = 0 ;
F_6 ( V_30 , V_28 ,
! ( ! ! ( V_83 & V_85 ) ||
! ! ( V_83 & V_86 ) ) ) ;
F_6 ( V_30 , V_87 ,
! ! ( V_83 & V_86 ) ) ;
F_6 ( V_30 , V_29 ,
! ( ! ! ( V_83 & V_88 ) ||
! ! ( V_83 & V_89 ) ) ) ;
F_6 ( V_30 , V_90 ,
( ! ! ( V_83 & V_88 ) &&
! ! ( V_83 & V_89 ) ) ) ;
F_6 ( V_30 , V_91 ,
! ! ( V_83 & V_92 ) ) ;
V_12 -> V_17 . V_30 = F_5 ( V_30 ) ;
F_12 ( V_2 , V_93 ,
L_3 , V_30 ) ;
}
if ( V_12 -> V_44 . V_81 ) {
T_3 V_83 = V_78 . V_94 ;
T_2 V_30 = 0 ;
F_6 ( V_30 , V_95 ,
! ! ( V_83 & V_96 ) ) ;
F_6 ( V_30 , V_97 ,
( ! ! ( V_83 & V_85 ) &&
! ! ( V_83 & V_86 ) ) ) ;
F_6 ( V_30 , V_98 ,
! ! ( V_83 & V_96 ) ) ;
F_6 ( V_30 , V_99 ,
( ! ! ( V_83 & V_88 ) &&
! ! ( V_83 & V_89 ) ) ) ;
F_6 ( V_30 , V_100 ,
! ! ( V_83 & V_92 ) ) ;
V_12 -> V_101 . V_30 = F_5 ( V_30 ) ;
F_12 ( V_2 , V_93 ,
L_4 , V_30 ) ;
}
}
static void
F_16 ( struct V_1 * V_2 ,
struct V_35 * V_12 ,
struct V_102 * V_37 )
{
int V_43 ;
memset ( & V_12 -> V_103 . V_104 , 0 ,
sizeof( V_12 -> V_103 . V_104 ) ) ;
if ( V_37 -> V_105 ) {
V_12 -> V_44 . V_105 = 1 ;
for ( V_43 = 0 ; V_43 < V_106 ; V_43 ++ ) {
T_1 * V_107 = ( T_1 * ) V_37 -> V_104 ;
T_4 V_108 = F_14 ( V_107 [ V_43 ] ) ;
V_12 -> V_103 . V_104 [ V_43 ] = V_108 ;
}
}
}
static int
F_17 ( struct V_1 * V_2 ,
struct V_102 * V_37 ,
enum V_109 V_20 ,
struct V_110 * V_111 )
{
struct V_36 * V_112 = V_37 -> V_113 ;
struct V_114 * V_115 ;
struct V_9 V_116 ;
struct V_35 * V_12 = NULL ;
struct V_13 * V_14 = NULL ;
T_3 V_18 = 0 ;
int V_15 = - V_16 ;
V_15 = F_2 ( V_2 , V_37 -> V_5 , & V_18 ) ;
if ( V_15 != 0 )
return V_15 ;
memset ( & V_116 , 0 , sizeof( V_116 ) ) ;
V_116 . V_19 = sizeof( * V_12 ) ;
V_116 . V_20 = V_20 ;
V_116 . V_111 = V_111 ;
V_15 = F_3 ( V_2 , & V_14 ,
F_4 ( V_2 ) ,
V_37 -> V_4 ,
V_117 ,
V_23 ,
& V_116 ) ;
if ( V_15 )
return V_15 ;
V_12 = & V_14 -> V_24 . V_118 ;
V_115 = & V_12 -> V_44 ;
V_115 -> V_5 = V_18 ;
V_115 -> V_119 = V_37 -> V_120 ;
V_115 -> V_121 = V_37 -> V_122 ;
V_115 -> V_123 = V_37 -> V_124 ;
V_115 -> V_125 = V_37 -> V_126 ;
V_15 = F_9 ( V_2 , V_12 , V_112 ) ;
if ( V_15 ) {
F_18 ( V_2 , V_14 ) ;
return V_15 ;
}
F_16 ( V_2 , V_12 , V_37 ) ;
F_15 ( V_2 , V_12 , V_37 -> V_78 ) ;
return F_8 ( V_2 , V_14 , NULL ) ;
}
static int F_19 ( struct V_1 * V_2 ,
T_2 V_4 ,
T_3 V_5 )
{
struct V_9 V_116 ;
struct V_127 * V_12 ;
struct V_13 * V_14 ;
T_3 V_18 = 0 ;
int V_15 ;
V_15 = F_2 ( V_2 , V_5 , & V_18 ) ;
if ( V_15 != 0 )
return V_15 ;
memset ( & V_116 , 0 , sizeof( V_116 ) ) ;
V_116 . V_19 = sizeof( * V_12 ) ;
V_116 . V_20 = V_21 ;
V_15 = F_3 ( V_2 , & V_14 ,
F_4 ( V_2 ) ,
V_4 ,
V_128 ,
V_23 ,
& V_116 ) ;
if ( V_15 )
return V_15 ;
V_12 = & V_14 -> V_24 . V_129 ;
V_12 -> V_5 = V_18 ;
return F_8 ( V_2 , V_14 , NULL ) ;
}
static int F_20 ( struct V_130 * V_34 ,
T_3 V_131 ,
struct V_77 V_78 ,
enum V_109 V_20 ,
struct V_110 * V_111 )
{
struct V_102 V_132 ;
int V_43 , V_15 ;
memset ( & V_132 , 0 , sizeof( V_132 ) ) ;
V_132 . V_5 = V_131 ;
V_132 . V_78 = V_78 ;
F_21 (cdev, i) {
struct V_1 * V_2 = & V_34 -> V_133 [ V_43 ] ;
V_132 . V_4 = V_2 -> V_134 . V_4 ;
V_15 = F_17 ( V_2 , & V_132 ,
V_20 , V_111 ) ;
if ( V_15 != 0 ) {
F_22 ( V_34 , L_5 , V_15 ) ;
return V_15 ;
}
F_12 ( V_2 , V_93 ,
L_6 ,
V_78 . V_84 ,
V_78 . V_94 ) ;
}
return 0 ;
}
static int F_23 (
struct V_1 * V_2 ,
struct V_135 * V_136 )
{
if ( ! V_136 -> V_137 )
return 0 ;
F_24 ( V_2 , V_136 -> V_138 ) ;
V_136 -> V_137 = false ;
return 0 ;
}
static int
F_25 ( struct V_1 * V_2 ,
T_2 V_4 ,
T_1 V_138 ,
struct V_139 * V_10 ,
T_3 V_140 ,
T_2 V_141 ,
T_5 V_142 ,
T_5 V_143 ,
T_2 V_144 )
{
struct V_145 * V_12 = NULL ;
struct V_9 V_116 ;
struct V_13 * V_14 = NULL ;
struct V_135 * V_146 ;
T_2 V_147 = 0 ;
T_3 V_18 = 0 ;
int V_15 = - V_16 ;
V_146 = & V_2 -> V_148 [ V_10 -> V_149 ] ;
V_146 -> V_138 = V_138 ;
V_146 -> V_4 = V_4 ;
V_146 -> V_5 = V_10 -> V_5 ;
V_15 = F_2 ( V_2 , V_10 -> V_5 , & V_18 ) ;
if ( V_15 != 0 )
return V_15 ;
V_15 = F_13 ( V_2 , V_10 -> V_149 , & V_147 ) ;
if ( V_15 != 0 )
return V_15 ;
F_12 ( V_2 , V_93 ,
L_7 ,
V_4 , V_138 , V_10 -> V_149 , V_10 -> V_5 ,
V_10 -> V_150 ) ;
memset ( & V_116 , 0 , sizeof( V_10 ) ) ;
V_116 . V_20 = V_21 ;
V_116 . V_19 = sizeof( * V_12 ) ;
V_15 = F_3 ( V_2 , & V_14 ,
V_138 , V_4 ,
V_151 ,
V_23 ,
& V_116 ) ;
if ( V_15 )
return V_15 ;
V_12 = & V_14 -> V_24 . V_152 ;
V_12 -> V_153 = F_5 ( V_10 -> V_150 ) ;
V_12 -> V_154 = V_10 -> V_155 ;
V_12 -> V_5 = V_18 ;
V_12 -> V_156 = V_140 ;
V_12 -> V_157 = F_5 ( V_147 ) ;
V_12 -> V_158 = 0 ;
V_12 -> V_159 = 1 ;
V_12 -> V_141 = F_5 ( V_141 ) ;
V_12 -> V_160 . V_161 = F_26 ( V_142 ) ;
V_12 -> V_160 . V_162 = F_27 ( V_142 ) ;
V_12 -> V_163 = F_5 ( V_144 ) ;
V_12 -> V_143 . V_161 = F_26 ( V_143 ) ;
V_12 -> V_143 . V_162 = F_27 ( V_143 ) ;
V_15 = F_8 ( V_2 , V_14 , NULL ) ;
return V_15 ;
}
static int
F_28 ( struct V_1 * V_2 ,
T_2 V_4 ,
struct V_139 * V_10 ,
T_2 V_141 ,
T_5 V_142 ,
T_5 V_143 ,
T_2 V_144 ,
void T_6 * * V_164 )
{
struct V_135 * V_146 ;
T_7 V_165 = 0 ;
T_2 V_41 = 0 ;
T_3 V_166 = 0 ;
int V_15 ;
V_15 = F_13 ( V_2 , V_10 -> V_149 , & V_41 ) ;
if ( V_15 != 0 )
return V_15 ;
V_15 = F_2 ( V_2 , V_10 -> V_5 , & V_166 ) ;
if ( V_15 != 0 )
return V_15 ;
* V_164 = ( T_3 T_6 * ) V_2 -> V_167 +
V_168 +
F_29 ( V_41 ) ;
F_30 ( V_2 , * V_164 , sizeof( T_7 ) ,
( T_1 * ) ( & V_165 ) ) ;
V_146 = & V_2 -> V_148 [ V_10 -> V_149 ] ;
V_15 = F_31 ( V_2 , V_23 ,
& V_146 -> V_138 ) ;
if ( V_15 ) {
F_32 ( V_2 , L_8 ) ;
return V_15 ;
}
V_146 -> V_137 = true ;
V_15 = F_25 ( V_2 ,
V_4 ,
V_146 -> V_138 ,
V_10 ,
V_166 ,
V_141 ,
V_142 ,
V_143 ,
V_144 ) ;
if ( V_15 != 0 )
F_23 ( V_2 , V_146 ) ;
return V_15 ;
}
static int F_33 ( struct V_1 * V_2 ,
T_2 V_157 ,
bool V_169 ,
bool V_170 )
{
struct V_135 * V_146 = & V_2 -> V_148 [ V_157 ] ;
struct V_171 * V_12 = NULL ;
struct V_9 V_116 ;
struct V_13 * V_14 = NULL ;
T_2 V_147 = 0 ;
int V_15 = - V_16 ;
memset ( & V_116 , 0 , sizeof( V_116 ) ) ;
V_116 . V_19 = sizeof( * V_12 ) ;
V_116 . V_20 = V_21 ;
V_15 = F_3 ( V_2 , & V_14 ,
V_146 -> V_138 ,
V_146 -> V_4 ,
V_172 ,
V_23 ,
& V_116 ) ;
if ( V_15 )
return V_15 ;
V_12 = & V_14 -> V_24 . V_173 ;
F_2 ( V_2 , V_146 -> V_5 , & V_12 -> V_5 ) ;
F_13 ( V_2 , V_157 , & V_147 ) ;
V_12 -> V_157 = F_5 ( V_147 ) ;
V_12 -> V_158 =
( ! ! ( V_146 -> V_4 == V_2 -> V_134 . V_4 ) &&
! V_169 ) || V_170 ;
V_12 -> V_159 =
! ( V_146 -> V_4 == V_2 -> V_134 . V_4 ) ||
V_169 ;
V_15 = F_8 ( V_2 , V_14 , NULL ) ;
if ( V_15 )
return V_15 ;
return F_23 ( V_2 , V_146 ) ;
}
static int
F_34 ( struct V_1 * V_2 ,
T_2 V_4 ,
T_1 V_138 ,
struct V_139 * V_37 ,
T_3 V_140 ,
T_5 V_174 ,
T_2 V_175 ,
union V_176 * V_177 )
{
struct V_178 * V_12 = NULL ;
struct V_9 V_116 ;
struct V_13 * V_14 = NULL ;
struct V_135 * V_179 ;
T_3 V_18 ;
int V_15 = - V_16 ;
T_2 V_180 ;
V_179 = & V_2 -> V_181 [ V_37 -> V_149 ] ;
V_179 -> V_138 = V_138 ;
V_179 -> V_4 = V_4 ;
V_15 = F_2 ( V_2 , V_37 -> V_5 , & V_18 ) ;
if ( V_15 )
return V_15 ;
memset ( & V_116 , 0 , sizeof( V_116 ) ) ;
V_116 . V_19 = sizeof( * V_12 ) ;
V_116 . V_20 = V_21 ;
V_15 = F_3 ( V_2 , & V_14 , V_138 ,
V_4 ,
V_182 ,
V_23 ,
& V_116 ) ;
if ( V_15 )
return V_15 ;
V_12 = & V_14 -> V_24 . V_183 ;
V_12 -> V_5 = V_18 ;
V_12 -> V_153 = F_5 ( V_37 -> V_150 ) ;
V_12 -> V_154 = V_37 -> V_155 ;
V_12 -> V_156 = V_140 ;
V_12 -> V_184 = V_177 -> V_185 . V_184 ;
V_12 -> V_175 = F_5 ( V_175 ) ;
V_12 -> V_186 . V_161 = F_26 ( V_174 ) ;
V_12 -> V_186 . V_162 = F_27 ( V_174 ) ;
V_180 = F_35 ( V_2 ,
V_23 ,
V_177 ) ;
V_12 -> V_187 = F_5 ( V_180 ) ;
return F_8 ( V_2 , V_14 , NULL ) ;
}
static int
F_36 ( struct V_1 * V_2 ,
T_2 V_4 ,
struct V_139 * V_37 ,
T_5 V_174 ,
T_2 V_175 ,
void T_6 * * V_188 )
{
struct V_135 * V_179 ;
union V_176 V_189 ;
T_3 V_166 = 0 ;
int V_15 ;
V_15 = F_2 ( V_2 , V_37 -> V_5 , & V_166 ) ;
if ( V_15 )
return V_15 ;
V_179 = & V_2 -> V_181 [ V_37 -> V_149 ] ;
memset ( V_179 , 0 , sizeof( * V_179 ) ) ;
memset ( & V_189 , 0 , sizeof( V_189 ) ) ;
V_15 = F_31 ( V_2 , V_23 ,
& V_179 -> V_138 ) ;
if ( V_15 ) {
F_32 ( V_2 , L_8 ) ;
return V_15 ;
}
V_179 -> V_137 = true ;
F_12 ( V_2 , V_93 ,
L_9 ,
V_4 , V_179 -> V_138 ,
V_37 -> V_149 , V_37 -> V_5 , V_37 -> V_150 ) ;
V_15 = F_34 ( V_2 ,
V_4 ,
V_179 -> V_138 ,
V_37 ,
V_166 ,
V_174 ,
V_175 ,
& V_189 ) ;
* V_188 = ( T_3 T_6 * ) V_2 -> V_190 +
F_37 ( V_179 -> V_138 , V_191 ) ;
if ( V_15 )
F_23 ( V_2 , V_179 ) ;
return V_15 ;
}
static int F_38 ( struct V_1 * V_2 ,
T_2 V_192 )
{
struct V_135 * V_179 = & V_2 -> V_181 [ V_192 ] ;
struct V_9 V_116 ;
struct V_13 * V_14 = NULL ;
int V_15 = - V_16 ;
memset ( & V_116 , 0 , sizeof( V_116 ) ) ;
V_116 . V_19 = sizeof( struct V_193 ) ;
V_116 . V_20 = V_21 ;
V_15 = F_3 ( V_2 , & V_14 ,
V_179 -> V_138 ,
V_179 -> V_4 ,
V_194 ,
V_23 ,
& V_116 ) ;
if ( V_15 )
return V_15 ;
V_15 = F_8 ( V_2 , V_14 , NULL ) ;
if ( V_15 )
return V_15 ;
return F_23 ( V_2 , V_179 ) ;
}
static enum V_195
F_39 ( enum V_196 V_197 )
{
enum V_195 V_198 = V_199 ;
switch ( V_197 ) {
case V_200 :
V_198 = V_201 ;
break;
case V_202 :
V_198 = V_203 ;
break;
case V_204 :
case V_205 :
V_198 = V_206 ;
break;
default:
V_198 = V_199 ;
}
return V_198 ;
}
static void F_40 ( T_8 * V_207 ,
T_8 * V_208 ,
T_8 * V_209 ,
T_3 * V_210 )
{
( ( T_3 * ) V_207 ) [ 0 ] = V_210 [ 1 ] ;
( ( T_3 * ) V_207 ) [ 1 ] = V_210 [ 0 ] ;
( ( T_3 * ) V_208 ) [ 0 ] = V_210 [ 3 ] ;
( ( T_3 * ) V_208 ) [ 1 ] = V_210 [ 2 ] ;
( ( T_3 * ) V_209 ) [ 0 ] = V_210 [ 5 ] ;
( ( T_3 * ) V_209 ) [ 1 ] = V_210 [ 4 ] ;
}
static int
F_41 ( struct V_1 * V_2 ,
T_2 V_4 ,
struct V_211 * V_212 ,
struct V_213 * * V_214 ,
struct V_13 * * V_215 ,
enum V_109 V_20 ,
struct V_110 * V_111 )
{
T_3 V_216 = 0 , V_217 = 0 ;
struct V_213 * V_12 ;
struct V_9 V_116 ;
struct V_218 * V_219 ;
struct V_218 * V_220 ;
enum V_195 V_198 ;
int V_15 ;
V_15 = F_2 ( V_2 , V_212 -> V_217 ,
& V_217 ) ;
if ( V_15 )
return V_15 ;
V_15 = F_2 ( V_2 , V_212 -> V_216 ,
& V_216 ) ;
if ( V_15 )
return V_15 ;
memset ( & V_116 , 0 , sizeof( V_116 ) ) ;
V_116 . V_19 = sizeof( * * V_214 ) ;
V_116 . V_20 = V_20 ;
V_116 . V_111 = V_111 ;
V_15 = F_3 ( V_2 , V_215 ,
F_4 ( V_2 ) ,
V_4 ,
V_221 ,
V_23 ,
& V_116 ) ;
if ( V_15 )
return V_15 ;
* V_214 = & ( * V_215 ) -> V_24 . V_222 ;
V_12 = * V_214 ;
V_12 -> V_223 . V_224 = V_212 -> V_225 ? 1 : 0 ;
V_12 -> V_223 . V_226 = V_212 -> V_227 ? 1 : 0 ;
switch ( V_212 -> V_197 ) {
case V_205 :
V_12 -> V_223 . V_228 = 0 ; break;
case V_229 :
V_12 -> V_223 . V_228 = 2 ; break;
default:
V_12 -> V_223 . V_228 = 1 ; break;
}
V_219 = & V_12 -> V_230 [ 0 ] ;
V_220 = & V_12 -> V_230 [ 1 ] ;
switch ( V_212 -> type ) {
case V_231 :
V_219 -> type = V_232 ; break;
case V_233 :
V_219 -> type = V_234 ; break;
case V_235 :
V_219 -> type = V_236 ; break;
case V_237 :
V_219 -> type = V_238 ; break;
case V_239 :
V_219 -> type = V_240 ; break;
case V_241 :
V_219 -> type = V_242 ; break;
case V_243 :
V_219 -> type = V_244 ;
break;
case V_245 :
V_219 -> type = V_246 ; break;
case V_247 :
V_219 -> type = V_248 ; break;
}
if ( ( V_219 -> type == V_232 ) ||
( V_219 -> type == V_236 ) ||
( V_219 -> type == V_238 ) ||
( V_219 -> type == V_242 ) ||
( V_219 -> type == V_244 ) ||
( V_219 -> type == V_246 ) ) {
F_40 ( & V_219 -> V_249 ,
& V_219 -> V_250 ,
& V_219 -> V_251 ,
( T_3 * ) V_212 -> V_210 ) ;
}
if ( ( V_219 -> type == V_234 ) ||
( V_219 -> type == V_236 ) ||
( V_219 -> type == V_240 ) ||
( V_219 -> type == V_242 ) )
V_219 -> V_252 = F_5 ( V_212 -> V_253 ) ;
if ( ( V_219 -> type == V_244 ) ||
( V_219 -> type == V_246 ) ||
( V_219 -> type == V_248 ) )
V_219 -> V_254 = F_14 ( V_212 -> V_254 ) ;
if ( V_212 -> V_197 == V_229 ) {
V_220 -> type = V_219 -> type ;
V_220 -> V_249 = V_219 -> V_249 ;
V_220 -> V_250 = V_219 -> V_250 ;
V_220 -> V_251 = V_219 -> V_251 ;
V_220 -> V_252 = V_219 -> V_252 ;
V_220 -> V_254 = V_219 -> V_254 ;
V_219 -> V_198 = V_203 ;
V_219 -> V_5 = V_217 ;
V_220 -> V_198 = V_201 ;
V_220 -> V_5 = V_216 ;
} else {
V_198 = F_39 ( V_212 -> V_197 ) ;
if ( V_198 == V_199 ) {
F_32 ( V_2 ,
L_10 ,
V_212 -> V_197 ) ;
return - V_16 ;
}
V_219 -> V_198 = V_198 ;
V_219 -> V_5 = ( V_212 -> V_197 ==
V_202 ) ?
V_217 :
V_216 ;
}
return 0 ;
}
static int F_42 ( struct V_1 * V_2 ,
T_2 V_4 ,
struct V_211 * V_212 ,
enum V_109 V_20 ,
struct V_110 * V_111 )
{
struct V_213 * V_12 = NULL ;
struct V_13 * V_14 = NULL ;
struct V_255 * V_256 ;
int V_15 ;
V_15 = F_41 ( V_2 , V_4 , V_212 ,
& V_12 , & V_14 ,
V_20 , V_111 ) ;
if ( V_15 != 0 ) {
F_22 ( V_2 , L_11 , V_15 ) ;
return V_15 ;
}
V_256 = & V_12 -> V_223 ;
V_256 -> V_257 = V_212 -> V_257 ;
V_15 = F_8 ( V_2 , V_14 , NULL ) ;
if ( V_15 != 0 ) {
F_22 ( V_2 ,
L_12 ,
V_15 ) ;
return V_15 ;
}
F_12 ( V_2 , V_93 ,
L_13 ,
( V_212 -> V_197 == V_200 ) ? L_14 :
( ( V_212 -> V_197 == V_202 ) ?
L_15 :
( ( V_212 -> V_197 == V_229 ) ?
L_16 : L_17 ) ) ,
( V_212 -> type == V_231 ) ? L_18 :
( ( V_212 -> type == V_233 ) ?
L_19 : L_20 ) ,
V_12 -> V_223 . V_228 ,
V_212 -> V_225 ,
V_212 -> V_227 ) ;
F_12 ( V_2 , V_93 ,
L_21 ,
V_212 -> V_216 ,
V_212 -> V_217 ,
V_212 -> V_210 [ 0 ] ,
V_212 -> V_210 [ 1 ] ,
V_212 -> V_210 [ 2 ] ,
V_212 -> V_210 [ 3 ] ,
V_212 -> V_210 [ 4 ] ,
V_212 -> V_210 [ 5 ] ,
V_212 -> V_253 ) ;
return 0 ;
}
static T_1 F_43 ( T_3 * V_258 ,
T_1 V_259 ,
T_1 V_260 ,
T_3 V_261 )
{
T_1 V_262 = 0 ;
T_1 V_263 = 0 ;
T_3 V_264 = 0 ;
T_3 V_265 = 0 ;
T_1 V_266 = V_260 ;
if ( ( ! V_258 ) ||
( V_259 == 0 ) ||
( ( V_259 % 8 ) != 0 ) )
return V_266 ;
for ( V_262 = 0 ; V_262 < V_259 ; V_262 ++ ) {
V_265 = V_258 [ V_262 ] ;
for ( V_263 = 0 ; V_263 < 8 ; V_263 ++ ) {
V_264 = ( T_3 ) ( V_266 >> 31 ) ;
V_266 = V_266 << 1 ;
if ( V_264 != ( 0x1 & ( V_265 >> V_263 ) ) ) {
V_266 = V_266 ^ V_267 ;
V_266 |= 1 ;
}
}
}
return V_266 ;
}
static inline T_1 F_44 ( T_1 V_268 ,
T_3 * V_210 ,
T_1 V_269 )
{
T_1 V_270 [ 2 ] = { 0 } ;
memcpy ( ( T_3 * ) ( & V_270 [ 0 ] ) , & V_210 [ 0 ] , 6 ) ;
return F_43 ( ( T_3 * ) V_270 , 8 , V_268 , 0 ) ;
}
static T_3 F_45 ( T_3 * V_210 )
{
T_1 V_271 = F_44 ( V_272 ,
V_210 , V_273 ) ;
return V_271 & 0xff ;
}
static int
F_46 ( struct V_1 * V_2 ,
T_2 V_4 ,
struct V_274 * V_212 ,
enum V_109 V_20 ,
struct V_110 * V_111 )
{
unsigned long V_104 [ V_106 ] ;
struct V_35 * V_12 = NULL ;
struct V_9 V_116 ;
struct V_13 * V_14 = NULL ;
T_3 V_18 = 0 ;
int V_15 , V_43 ;
if ( V_212 -> V_197 == V_200 ) {
V_15 = F_2 ( V_2 , V_212 -> V_216 ,
& V_18 ) ;
if ( V_15 )
return V_15 ;
} else {
V_15 = F_2 ( V_2 , V_212 -> V_217 ,
& V_18 ) ;
if ( V_15 )
return V_15 ;
}
memset ( & V_116 , 0 , sizeof( V_116 ) ) ;
V_116 . V_19 = sizeof( * V_12 ) ;
V_116 . V_20 = V_20 ;
V_116 . V_111 = V_111 ;
V_15 = F_3 ( V_2 , & V_14 ,
F_4 ( V_2 ) ,
V_2 -> V_134 . V_4 ,
V_117 ,
V_23 ,
& V_116 ) ;
if ( V_15 ) {
F_22 ( V_2 , L_22 , V_15 ) ;
return V_15 ;
}
V_12 = & V_14 -> V_24 . V_118 ;
V_12 -> V_44 . V_105 = 1 ;
memset ( & V_12 -> V_103 . V_104 , 0 ,
sizeof( V_12 -> V_103 . V_104 ) ) ;
memset ( V_104 , 0 , sizeof( unsigned long ) *
V_106 ) ;
if ( V_212 -> V_197 == V_200 ) {
for ( V_43 = 0 ; V_43 < V_212 -> V_275 ; V_43 ++ ) {
T_1 V_263 ;
V_263 = F_45 ( V_212 -> V_210 [ V_43 ] ) ;
F_47 ( V_263 , V_104 ) ;
}
for ( V_43 = 0 ; V_43 < V_106 ; V_43 ++ ) {
T_1 * V_107 = ( T_1 * ) V_104 ;
struct V_276 * V_103 ;
V_103 = & V_12 -> V_103 ;
V_103 -> V_104 [ V_43 ] = F_14 ( V_107 [ V_43 ] ) ;
}
}
V_12 -> V_44 . V_5 = V_18 ;
return F_8 ( V_2 , V_14 , NULL ) ;
}
static int
F_48 ( struct V_130 * V_34 ,
struct V_274 * V_212 ,
enum V_109 V_20 ,
struct V_110 * V_111 )
{
int V_15 = 0 ;
int V_43 ;
if ( ( V_212 -> V_197 != V_200 &&
( V_212 -> V_197 != V_202 ) ) ||
( V_212 -> V_275 > V_277 ) )
return - V_16 ;
F_21 (cdev, i) {
struct V_1 * V_2 = & V_34 -> V_133 [ V_43 ] ;
T_2 V_4 ;
if ( V_15 != 0 )
break;
V_4 = V_2 -> V_134 . V_4 ;
V_15 = F_46 ( V_2 ,
V_4 ,
V_212 ,
V_20 ,
V_111 ) ;
}
return V_15 ;
}
static int F_49 ( struct V_130 * V_34 ,
struct V_211 * V_212 ,
enum V_109 V_20 ,
struct V_110 * V_111 )
{
int V_15 = 0 ;
int V_43 ;
F_21 (cdev, i) {
struct V_1 * V_2 = & V_34 -> V_133 [ V_43 ] ;
T_2 V_4 ;
if ( V_15 != 0 )
break;
V_4 = V_2 -> V_134 . V_4 ;
V_15 = F_42 ( V_2 ,
V_4 ,
V_212 ,
V_20 ,
V_111 ) ;
}
return V_15 ;
}
static int F_50 ( struct V_130 * V_34 ,
struct V_278 * V_279 )
{
int V_43 ;
memset ( V_279 , 0 , sizeof( * V_279 ) ) ;
V_279 -> V_280 = 1 ;
if ( V_34 -> V_281 . V_282 . V_283 == V_284 ) {
F_21 (cdev, i)
V_279 -> V_285 += F_51 ( & V_34 -> V_133 [ V_43 ] ,
V_286 ) ;
if ( V_34 -> V_281 . V_287 )
V_279 -> V_285 = F_52 ( T_3 , V_279 -> V_285 ,
V_34 -> V_281 . V_287 ) ;
} else {
V_279 -> V_285 = V_34 -> V_288 ;
}
V_279 -> V_289 = F_53 ( & V_34 -> V_133 [ 0 ] , V_290 ) ;
F_54 ( V_279 -> V_291 ,
V_34 -> V_133 [ 0 ] . V_134 . V_292 ) ;
F_55 ( V_34 , & V_279 -> V_44 ) ;
return 0 ;
}
static void F_56 ( struct V_130 * V_34 ,
struct V_293 * V_294 ,
void * V_295 )
{
V_34 -> V_296 . V_185 = V_294 ;
V_34 -> V_297 = V_295 ;
}
static int F_57 ( struct V_130 * V_34 ,
T_3 V_5 ,
T_2 V_6 ,
T_3 V_7 ,
T_3 V_8 )
{
int V_15 , V_43 ;
F_21 (cdev, i) {
struct V_1 * V_2 = & V_34 -> V_133 [ V_43 ] ;
V_15 = F_1 ( V_2 ,
V_2 -> V_134 . V_3 ,
V_2 -> V_134 . V_4 ,
V_5 ,
V_6 ,
V_7 ,
V_8 ) ;
if ( V_15 ) {
F_22 ( V_34 , L_23 ) ;
return V_15 ;
}
F_58 ( V_2 ) ;
F_12 ( V_34 , ( V_298 | V_73 ) ,
L_24 ,
V_5 , V_6 ) ;
}
F_59 ( V_34 ) ;
return 0 ;
}
static int F_60 ( struct V_130 * V_34 ,
T_3 V_5 )
{
int V_15 , V_43 ;
F_21 (cdev, i) {
struct V_1 * V_2 = & V_34 -> V_133 [ V_43 ] ;
V_15 = F_19 ( V_2 ,
V_2 -> V_134 . V_4 ,
V_5 ) ;
if ( V_15 ) {
F_22 ( V_34 , L_25 ) ;
return V_15 ;
}
}
return 0 ;
}
static int F_61 ( struct V_130 * V_34 ,
struct V_299 * V_10 )
{
struct V_102 V_116 ;
struct V_36 V_300 ;
int V_15 , V_43 ;
if ( ! V_34 )
return - V_301 ;
memset ( & V_116 , 0 , sizeof( V_116 ) ) ;
memset ( & V_300 , 0 , sizeof( V_300 ) ) ;
V_116 . V_5 = V_10 -> V_5 ;
V_116 . V_122 =
V_10 -> V_302 ;
V_116 . V_126 =
V_10 -> V_302 ;
V_116 . V_120 = V_10 -> V_303 ;
V_116 . V_124 = V_10 -> V_303 ;
if ( V_34 -> V_288 > 1 && V_10 -> V_45 ) {
struct V_304 * V_39 =
& V_10 -> V_113 ;
int V_305 , V_306 = 0 ;
for ( V_305 = 0 ; V_305 < V_46 ; V_305 ++ )
V_306 = ( V_306 > V_39 -> V_74 [ V_305 ] ) ?
V_306 : V_39 -> V_74 [ V_305 ] ;
if ( V_34 -> V_288 < V_306 + 1 ) {
int V_307 = ( V_306 + V_34 -> V_288 - 1 ) /
V_34 -> V_288 ;
F_12 ( V_34 , ( V_298 | V_73 ) ,
L_26 ,
V_307 ) ;
for ( V_305 = 0 ; V_305 < V_46 ; V_305 ++ )
V_39 -> V_74 [ V_305 ] =
V_39 -> V_74 [ V_305 ] % V_307 ;
} else {
F_12 ( V_34 , ( V_298 | V_73 ) ,
L_27 ) ;
V_10 -> V_45 = 0 ;
}
}
if ( V_10 -> V_45 ) {
V_300 . V_50 = 1 ;
V_300 . V_55 = 1 ;
V_300 . V_51 = 1 ;
V_300 . V_52 = 1 ;
V_300 . V_53 = 1 ;
V_300 . V_59 = V_60 |
V_62 |
V_64 | V_66 ;
V_300 . V_72 = 7 ;
memcpy ( V_300 . V_74 ,
V_10 -> V_113 . V_74 ,
V_46 * sizeof( T_2 ) ) ;
memcpy ( V_300 . V_76 , V_10 -> V_113 . V_76 ,
V_308 * sizeof( T_1 ) ) ;
}
V_116 . V_113 = & V_300 ;
F_21 (cdev, i) {
struct V_1 * V_2 = & V_34 -> V_133 [ V_43 ] ;
V_116 . V_4 = V_2 -> V_134 . V_4 ;
V_15 = F_17 ( V_2 , & V_116 ,
V_21 ,
NULL ) ;
if ( V_15 ) {
F_22 ( V_34 , L_28 ) ;
return V_15 ;
}
F_12 ( V_34 , ( V_298 | V_73 ) ,
L_29 ,
V_10 -> V_5 , V_10 -> V_303 ,
V_10 -> V_302 ) ;
}
return 0 ;
}
static int F_62 ( struct V_130 * V_34 ,
struct V_139 * V_10 ,
T_2 V_141 ,
T_5 V_142 ,
T_5 V_143 ,
T_2 V_144 ,
void T_6 * * V_164 )
{
int V_15 , V_309 ;
struct V_1 * V_2 ;
V_309 = V_10 -> V_49 % V_34 -> V_288 ;
V_2 = & V_34 -> V_133 [ V_309 ] ;
V_10 -> V_149 /= V_34 -> V_288 ;
V_15 = F_28 ( V_2 ,
V_2 -> V_134 . V_4 ,
V_10 ,
V_141 ,
V_142 ,
V_143 ,
V_144 ,
V_164 ) ;
if ( V_15 ) {
F_22 ( V_34 , L_30 , V_10 -> V_149 ) ;
return V_15 ;
}
F_12 ( V_34 , ( V_298 | V_73 ) ,
L_31 ,
V_10 -> V_149 , V_10 -> V_49 , V_10 -> V_5 ,
V_10 -> V_150 ) ;
return 0 ;
}
static int F_63 ( struct V_130 * V_34 ,
struct V_310 * V_10 )
{
int V_15 , V_309 ;
struct V_1 * V_2 ;
V_309 = V_10 -> V_49 % V_34 -> V_288 ;
V_2 = & V_34 -> V_133 [ V_309 ] ;
V_15 = F_33 ( V_2 ,
V_10 -> V_157 / V_34 -> V_288 ,
V_10 -> V_169 ,
false ) ;
if ( V_15 ) {
F_22 ( V_34 , L_32 , V_10 -> V_157 ) ;
return V_15 ;
}
return 0 ;
}
static int F_64 ( struct V_130 * V_34 ,
struct V_139 * V_37 ,
T_5 V_174 ,
T_2 V_175 ,
void T_6 * * V_188 )
{
struct V_1 * V_2 ;
int V_15 , V_309 ;
V_309 = V_37 -> V_49 % V_34 -> V_288 ;
V_2 = & V_34 -> V_133 [ V_309 ] ;
V_37 -> V_149 /= V_34 -> V_288 ;
V_15 = F_36 ( V_2 ,
V_2 -> V_134 . V_4 ,
V_37 ,
V_174 ,
V_175 ,
V_188 ) ;
if ( V_15 ) {
F_22 ( V_34 , L_33 , V_37 -> V_149 ) ;
return V_15 ;
}
F_12 ( V_34 , ( V_298 | V_73 ) ,
L_34 ,
V_37 -> V_149 , V_37 -> V_49 , V_37 -> V_5 ,
V_37 -> V_150 ) ;
return 0 ;
}
static int F_65 ( struct V_130 * V_34 )
{
F_66 ( V_34 ) ;
return 0 ;
}
static int F_67 ( struct V_130 * V_34 ,
struct V_311 * V_10 )
{
struct V_1 * V_2 ;
int V_15 , V_309 ;
V_309 = V_10 -> V_49 % V_34 -> V_288 ;
V_2 = & V_34 -> V_133 [ V_309 ] ;
V_15 = F_38 ( V_2 ,
V_10 -> V_192 / V_34 -> V_288 ) ;
if ( V_15 ) {
F_22 ( V_34 , L_35 , V_10 -> V_192 ) ;
return V_15 ;
}
return 0 ;
}
static int F_68 ( struct V_130 * V_34 ,
enum V_312 type )
{
struct V_77 V_78 ;
memset ( & V_78 , 0 , sizeof( V_78 ) ) ;
V_78 . V_80 = 1 ;
V_78 . V_82 = 1 ;
V_78 . V_84 = V_85 |
V_88 |
V_92 ;
V_78 . V_94 = V_85 |
V_88 |
V_92 ;
if ( type == V_313 )
V_78 . V_84 |= V_86 |
V_89 ;
else if ( type == V_314 )
V_78 . V_84 |= V_89 ;
return F_20 ( V_34 , 0 , V_78 ,
V_315 , NULL ) ;
}
static int F_69 ( struct V_130 * V_34 ,
struct V_316 * V_10 )
{
struct V_211 V_317 ;
if ( ! V_10 -> V_318 && ! V_10 -> V_319 ) {
F_32 (
V_34 ,
L_36 ) ;
return - V_16 ;
}
memset ( & V_317 , 0 , sizeof( V_317 ) ) ;
switch ( V_10 -> type ) {
case V_320 :
V_317 . V_197 = V_200 ;
break;
case V_321 :
V_317 . V_197 = V_202 ;
break;
case V_322 :
V_317 . V_197 = V_204 ;
break;
default:
F_32 ( V_34 , L_37 ,
V_10 -> type ) ;
}
if ( V_10 -> V_318 && V_10 -> V_319 ) {
V_317 . type = V_235 ;
F_54 ( V_317 . V_210 , V_10 -> V_210 ) ;
V_317 . V_253 = V_10 -> V_253 ;
} else if ( V_10 -> V_319 ) {
V_317 . type = V_231 ;
F_54 ( V_317 . V_210 , V_10 -> V_210 ) ;
} else {
V_317 . type = V_233 ;
V_317 . V_253 = V_10 -> V_253 ;
}
V_317 . V_225 = true ;
V_317 . V_227 = true ;
return F_49 ( V_34 , & V_317 , V_315 , NULL ) ;
}
static int F_70 ( struct V_130 * V_34 ,
struct V_323 * V_10 )
{
struct V_274 V_324 ;
int V_43 ;
memset ( & V_324 , 0 , sizeof( V_324 ) ) ;
switch ( V_10 -> type ) {
case V_320 :
V_324 . V_197 = V_200 ;
break;
case V_321 :
V_324 . V_197 = V_202 ;
break;
default:
F_32 ( V_34 , L_38 ,
V_10 -> type ) ;
}
V_324 . V_275 = V_10 -> V_325 ;
for ( V_43 = 0 ; V_43 < V_324 . V_275 ; V_43 ++ )
F_54 ( V_324 . V_210 [ V_43 ] , V_10 -> V_210 [ V_43 ] ) ;
return F_48 ( V_34 , & V_324 ,
V_315 , NULL ) ;
}
static int F_71 ( struct V_130 * V_34 ,
struct V_326 * V_10 )
{
enum V_312 V_78 ;
switch ( V_10 -> type ) {
case V_327 :
return F_69 ( V_34 , & V_10 -> V_328 . V_317 ) ;
case V_329 :
return F_70 ( V_34 , & V_10 -> V_328 . V_324 ) ;
case V_330 :
V_78 = V_10 -> V_328 . V_78 ;
return F_68 ( V_34 , V_78 ) ;
default:
F_32 ( V_34 , L_39 ,
( int ) V_10 -> type ) ;
return - V_16 ;
}
}
static int F_72 ( struct V_130 * V_331 ,
T_3 V_49 ,
struct V_332 * V_333 )
{
return F_73 ( & V_331 -> V_133 [ V_49 % V_331 -> V_288 ] ,
V_333 ) ;
}
const struct V_334 * F_74 ( T_1 V_335 )
{
if ( V_335 != V_336 ) {
F_75 ( L_40 ,
V_335 , V_336 ) ;
return NULL ;
}
return & V_337 ;
}
void F_76 ( void )
{
}
