static void * F_1 ( struct V_1 * V_2 , T_1 type , T_1 V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
void * V_7 ;
F_2 ( & ( V_5 -> V_8 ) ) ;
F_3 ( V_2 ,
V_9 ,
L_1 ,
type ) ;
V_5 -> V_10 = ( V_11 * ) V_5 -> V_12 ;
memset ( V_5 -> V_12 , 0 , sizeof( union V_13 ) ) ;
memset ( V_5 -> V_14 , 0 , sizeof( union V_15 ) ) ;
V_7 = F_4 ( V_2 , & V_5 -> V_10 , type , V_3 ) ;
( (struct V_16 * ) V_7 ) -> V_17 =
( V_18 ) V_5 -> V_19 ;
return V_7 ;
}
static int F_5 ( struct V_1 * V_2 , V_11 * V_20 , T_2 V_21 )
{
union V_13 * V_22 = V_2 -> V_6 -> V_12 ;
struct V_23 V_24 ;
struct V_25 * V_26 ;
int V_27 = 0 , time = 100 ;
V_26 = (struct V_25 * ) V_28 ;
F_6 ( V_2 , V_22 ) ;
V_21 += sizeof( struct V_29 ) ;
memset ( & V_24 , 0 , sizeof( struct V_23 ) ) ;
V_24 . V_30 = 1 ;
F_3 ( V_2 ,
V_9 ,
L_2 ,
F_7 ( V_2 -> V_31 . V_32 ,
V_33 ) ,
F_8 ( V_2 -> V_6 -> V_34 ) ,
F_9 ( V_2 -> V_6 -> V_34 ) ,
& V_26 -> V_35 . V_36 ,
* ( ( T_2 * ) & V_24 ) , & V_26 -> V_24 ) ;
F_10 ( V_2 ,
( V_37 ) & V_26 -> V_35 . V_36 . V_38 ,
F_9 ( V_2 -> V_6 -> V_34 ) ) ;
F_10 ( V_2 ,
( V_37 ) & V_26 -> V_35 . V_36 . V_39 ,
F_8 ( V_2 -> V_6 -> V_34 ) ) ;
F_11 () ;
F_10 ( V_2 , ( V_37 ) & V_26 -> V_24 , * ( ( T_2 * ) & V_24 ) ) ;
while ( ( ! * V_20 ) && time ) {
F_12 ( 25 ) ;
time -- ;
}
if ( ! * V_20 ) {
F_3 ( V_2 , V_9 ,
L_3 ,
V_22 -> V_40 . V_41 . type ) ;
V_27 = - V_42 ;
goto exit;
} else {
F_3 ( V_2 , V_9 ,
L_4 ,
* V_20 , V_22 -> V_40 . V_41 . type ) ;
}
exit:
F_13 ( & ( V_2 -> V_6 -> V_8 ) ) ;
return V_27 ;
}
static int F_14 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_43 * V_44 = & V_5 -> V_14 -> V_45 ;
struct V_46 * V_47 = & V_44 -> V_47 ;
V_11 V_48 = 1 , V_49 = 1 , V_50 = 1 ;
V_11 V_51 = V_52 ;
bool V_53 = false ;
struct V_54 * V_55 ;
int V_27 = 0 , V_56 = 0 ;
V_55 = F_1 ( V_2 , V_57 , sizeof( * V_55 ) ) ;
V_55 -> V_58 . V_59 = V_2 -> V_31 . V_59 ;
V_55 -> V_60 . V_61 = V_48 ;
V_55 -> V_60 . V_62 = V_49 ;
V_55 -> V_60 . V_50 = V_50 ;
V_55 -> V_60 . V_63 = V_51 ;
V_55 -> V_60 . V_64 = V_65 ;
V_55 -> V_58 . V_66 = V_67 ;
V_55 -> V_58 . V_68 = V_69 ;
V_55 -> V_58 . V_70 = V_71 ;
V_55 -> V_58 . V_72 = V_73 ;
V_55 -> V_58 . V_74 = V_75 ;
V_55 -> V_58 . V_76 |= V_77 ;
V_55 -> V_78 = V_5 -> V_79 . V_80 ;
V_55 -> V_81 = V_5 -> V_79 . V_82 ;
F_4 ( V_2 , & V_5 -> V_10 ,
V_83 , sizeof( struct V_29 ) ) ;
while ( ! V_53 ) {
F_3 ( V_2 ,
V_9 , L_5 ) ;
V_27 = F_5 ( V_2 , & V_44 -> V_84 . V_85 , sizeof( * V_44 ) ) ;
if ( V_27 )
return V_27 ;
memcpy ( & V_5 -> V_45 , V_44 , sizeof( V_5 -> V_45 ) ) ;
V_56 ++ ;
if ( V_44 -> V_84 . V_85 == V_86 ) {
if ( ! ( V_44 -> V_47 . V_76 &
V_87 ) ) {
F_15 ( V_2 ,
L_6 ) ;
return - V_88 ;
}
F_3 ( V_2 , V_9 , L_7 ) ;
V_53 = true ;
} else if ( V_44 -> V_84 . V_85 == V_89 &&
V_56 < V_90 ) {
F_3 ( V_2 ,
V_9 ,
L_8 ) ;
V_55 -> V_60 . V_62 = V_44 -> V_91 . V_62 ;
V_55 -> V_60 . V_61 = V_44 -> V_91 . V_61 ;
V_55 -> V_60 . V_50 = V_44 -> V_91 . V_50 ;
V_55 -> V_60 . V_63 =
V_44 -> V_91 . V_63 ;
V_55 -> V_60 . V_64 =
V_44 -> V_91 . V_64 ;
memset ( V_5 -> V_14 , 0 , sizeof( union V_15 ) ) ;
} else {
F_16 ( V_2 ,
L_9 ,
V_44 -> V_84 . V_85 ) ;
return - V_92 ;
}
}
V_5 -> V_79 . V_82 = V_44 -> V_81 ;
V_2 -> V_93 -> type = V_44 -> V_47 . V_94 ;
V_2 -> V_93 -> V_95 = V_44 -> V_47 . V_95 ;
V_2 -> V_93 -> V_96 = V_47 -> V_96 & 0xffff ;
if ( F_17 ( V_2 ) ) {
if ( V_44 -> V_47 . V_76 & V_97 ) {
F_18 ( V_2 , L_10 ) ;
V_2 -> V_93 -> V_98 = 2 ;
}
}
return 0 ;
}
int F_19 ( struct V_1 * V_2 )
{
struct V_4 * V_5 ;
T_2 V_99 ;
if ( F_17 ( V_2 ) )
V_2 -> V_93 -> V_98 = 1 ;
V_2 -> V_100 = ( V_11 V_101 * ) V_2 -> V_102 +
V_103 ;
V_99 = V_104 ;
V_2 -> V_31 . V_59 = ( T_1 ) F_20 ( V_2 , V_99 ) ;
V_99 = V_105 ;
V_2 -> V_31 . V_32 = F_20 ( V_2 , V_99 ) ;
V_5 = F_21 ( sizeof( * V_5 ) , V_106 ) ;
if ( ! V_5 ) {
F_18 ( V_2 , L_11 ) ;
return - V_107 ;
}
V_5 -> V_12 = F_22 ( & V_2 -> V_93 -> V_108 -> V_109 ,
sizeof( union V_13 ) ,
& V_5 -> V_34 ,
V_106 ) ;
if ( ! V_5 -> V_12 ) {
F_18 ( V_2 ,
L_12 ) ;
goto V_110;
}
V_5 -> V_14 = F_22 ( & V_2 -> V_93 -> V_108 -> V_109 ,
sizeof( union V_15 ) ,
& V_5 -> V_19 ,
V_106 ) ;
if ( ! V_5 -> V_14 ) {
F_18 ( V_2 ,
L_13 ) ;
goto V_111;
}
F_3 ( V_2 ,
V_9 ,
L_14 ,
V_5 -> V_12 ,
( V_18 ) V_5 -> V_34 ,
V_5 -> V_14 , ( V_18 ) V_5 -> V_19 ) ;
V_5 -> V_79 . V_82 = sizeof( struct V_112 ) ;
V_5 -> V_79 . V_113 = F_22 ( & V_2 -> V_93 -> V_108 -> V_109 ,
V_5 -> V_79 . V_82 ,
& V_5 -> V_79 . V_80 ,
V_106 ) ;
F_3 ( V_2 , V_9 ,
L_15 ,
V_5 -> V_79 . V_113 ,
( V_18 ) V_5 -> V_79 . V_80 , V_5 -> V_79 . V_82 ) ;
F_23 ( & V_5 -> V_8 ) ;
V_2 -> V_6 = V_5 ;
V_2 -> V_31 . V_114 = V_115 ;
return F_14 ( V_2 ) ;
V_111:
F_24 ( & V_2 -> V_93 -> V_108 -> V_109 ,
sizeof( union V_13 ) ,
V_5 -> V_12 , V_5 -> V_34 ) ;
V_110:
F_25 ( V_5 ) ;
return - V_107 ;
}
int F_26 ( struct V_1 * V_2 ,
V_11 V_116 ,
T_1 V_117 ,
V_11 V_118 ,
T_1 V_119 ,
T_3 V_120 ,
T_3 V_121 ,
T_1 V_122 , void V_101 * * V_123 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_124 * V_44 ;
struct V_125 * V_55 ;
int V_27 ;
V_55 = F_1 ( V_2 , V_126 , sizeof( * V_55 ) ) ;
V_55 -> V_116 = V_116 ;
V_55 -> V_121 = V_121 ;
V_55 -> V_122 = V_122 ;
V_55 -> V_127 = V_120 ;
V_55 -> V_128 = V_117 ;
V_55 -> V_118 = V_118 ;
V_55 -> V_119 = V_119 ;
V_55 -> V_129 = - 1 ;
F_4 ( V_2 , & V_5 -> V_10 ,
V_83 , sizeof( struct V_29 ) ) ;
V_44 = & V_5 -> V_14 -> V_130 ;
V_27 = F_5 ( V_2 , & V_44 -> V_84 . V_85 , sizeof( * V_44 ) ) ;
if ( V_27 )
return V_27 ;
if ( V_44 -> V_84 . V_85 != V_86 )
return - V_88 ;
if ( V_123 ) {
V_18 V_131 = 0 ;
* V_123 = ( V_11 V_101 * ) V_2 -> V_102 + V_44 -> V_10 ;
F_3 ( V_2 , V_9 ,
L_16 ,
V_116 , * V_123 , V_44 -> V_10 ) ;
F_27 ( V_2 , * V_123 , sizeof( V_18 ) ,
( T_2 * ) & V_131 ) ;
}
return V_27 ;
}
int F_28 ( struct V_1 * V_2 , T_1 V_116 , bool V_132 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_133 * V_55 ;
struct V_134 * V_44 ;
int V_27 ;
V_55 = F_1 ( V_2 , V_135 , sizeof( * V_55 ) ) ;
V_55 -> V_116 = V_116 ;
V_55 -> V_61 = 1 ;
V_55 -> V_132 = V_132 ;
F_4 ( V_2 , & V_5 -> V_10 ,
V_83 , sizeof( struct V_29 ) ) ;
V_44 = & V_5 -> V_14 -> V_136 ;
V_27 = F_5 ( V_2 , & V_44 -> V_84 . V_85 , sizeof( * V_44 ) ) ;
if ( V_27 )
return V_27 ;
if ( V_44 -> V_84 . V_85 != V_86 )
return - V_88 ;
return V_27 ;
}
int F_29 ( struct V_1 * V_2 ,
T_1 V_137 ,
T_1 V_117 ,
V_11 V_118 ,
T_3 V_138 ,
T_1 V_139 , void V_101 * * V_140 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_141 * V_55 ;
struct V_134 * V_44 ;
int V_27 ;
V_55 = F_1 ( V_2 , V_142 , sizeof( * V_55 ) ) ;
V_55 -> V_143 = V_137 ;
V_55 -> V_138 = V_138 ;
V_55 -> V_139 = V_139 ;
V_55 -> V_128 = V_117 ;
V_55 -> V_118 = V_118 ;
F_4 ( V_2 , & V_5 -> V_10 ,
V_83 , sizeof( struct V_29 ) ) ;
V_44 = & V_5 -> V_14 -> V_136 ;
V_27 = F_5 ( V_2 , & V_44 -> V_84 . V_85 , sizeof( * V_44 ) ) ;
if ( V_27 )
return V_27 ;
if ( V_44 -> V_84 . V_85 != V_86 )
return - V_88 ;
if ( V_140 ) {
V_11 V_144 = V_5 -> V_45 . V_91 . V_144 [ V_137 ] ;
* V_140 = ( V_11 V_101 * ) V_2 -> V_100 +
F_30 ( V_144 , V_145 ) ;
}
return V_27 ;
}
int F_31 ( struct V_1 * V_2 , T_1 V_143 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_146 * V_55 ;
struct V_134 * V_44 ;
int V_27 ;
V_55 = F_1 ( V_2 , V_147 , sizeof( * V_55 ) ) ;
V_55 -> V_143 = V_143 ;
V_55 -> V_62 = 1 ;
F_4 ( V_2 , & V_5 -> V_10 ,
V_83 , sizeof( struct V_29 ) ) ;
V_44 = & V_5 -> V_14 -> V_136 ;
V_27 = F_5 ( V_2 , & V_44 -> V_84 . V_85 , sizeof( * V_44 ) ) ;
if ( V_27 )
return V_27 ;
if ( V_44 -> V_84 . V_85 != V_86 )
return - V_88 ;
return V_27 ;
}
int F_32 ( struct V_1 * V_2 ,
V_11 V_148 ,
T_1 V_149 ,
V_11 V_150 ,
enum V_151 V_152 ,
V_11 V_153 , V_11 V_154 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_155 * V_55 ;
struct V_134 * V_44 ;
int V_27 , V_156 ;
V_55 = F_1 ( V_2 , V_157 , sizeof( * V_55 ) ) ;
V_55 -> V_149 = V_149 ;
V_55 -> V_148 = V_148 ;
V_55 -> V_150 = V_150 ;
V_55 -> V_152 = V_152 ;
V_55 -> V_153 = V_153 ;
V_55 -> V_154 = V_154 ;
for ( V_156 = 0 ; V_156 < V_2 -> V_6 -> V_45 . V_91 . V_50 ; V_156 ++ )
if ( V_2 -> V_158 [ V_156 ] )
V_55 -> V_159 [ V_156 ] = V_2 -> V_158 [ V_156 ] -> V_160 ;
F_4 ( V_2 , & V_5 -> V_10 ,
V_83 , sizeof( struct V_29 ) ) ;
V_44 = & V_5 -> V_14 -> V_136 ;
V_27 = F_5 ( V_2 , & V_44 -> V_84 . V_85 , sizeof( * V_44 ) ) ;
if ( V_27 )
return V_27 ;
if ( V_44 -> V_84 . V_85 != V_86 )
return - V_88 ;
return V_27 ;
}
int F_33 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_134 * V_44 = & V_5 -> V_14 -> V_136 ;
int V_27 ;
F_1 ( V_2 , V_161 ,
sizeof( struct V_16 ) ) ;
F_4 ( V_2 , & V_5 -> V_10 ,
V_83 , sizeof( struct V_29 ) ) ;
V_27 = F_5 ( V_2 , & V_44 -> V_84 . V_85 , sizeof( * V_44 ) ) ;
if ( V_27 )
return V_27 ;
if ( V_44 -> V_84 . V_85 != V_86 )
return - V_88 ;
return V_27 ;
}
static bool
F_34 ( struct V_1 * V_2 ,
struct V_162 * V_163 ,
T_1 V_164 )
{
switch ( V_164 ) {
case V_165 :
return ! ! ( V_163 -> V_166 ||
V_163 -> V_167 ) ;
case V_168 :
return ! ! V_163 -> V_169 ;
case V_170 :
return ! ! V_163 -> V_171 ;
case V_172 :
return ! ! V_163 -> V_173 ;
case V_174 :
return ! ! V_163 -> V_175 ;
case V_176 :
return ! ! ( V_163 -> V_177 . V_178 ||
V_163 -> V_177 . V_179 ) ;
case V_180 :
return ! ! V_163 -> V_181 ;
case V_182 :
return ! ! V_163 -> V_183 ;
default:
F_15 ( V_2 , L_17 ,
V_164 ) ;
return false ;
}
}
static void
F_35 ( struct V_1 * V_2 ,
struct V_162 * V_163 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_134 * V_184 ;
T_1 V_164 ;
for ( V_164 = V_165 ;
V_164 < V_185 ; V_164 ++ ) {
if ( ! F_34 ( V_2 , V_163 , V_164 ) )
continue;
V_184 = (struct V_134 * )
F_36 ( V_2 , V_5 -> V_14 ,
V_164 ) ;
if ( V_184 && V_184 -> V_84 . V_85 )
F_3 ( V_2 , V_9 ,
L_18 ,
V_164 ,
( V_184 && V_184 -> V_84 . V_85 ) ? L_19
: L_20 ) ;
}
}
int F_37 ( struct V_1 * V_2 ,
struct V_162 * V_186 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_187 * V_55 ;
struct V_134 * V_44 ;
V_11 V_188 , V_189 ;
T_2 V_21 = 0 ;
T_1 V_82 , V_164 ;
int V_27 ;
V_44 = & V_5 -> V_14 -> V_136 ;
V_21 = sizeof( * V_44 ) ;
V_188 = V_186 -> V_166 ;
V_189 = V_186 -> V_167 ;
F_1 ( V_2 , V_190 , sizeof( * V_55 ) ) ;
if ( V_188 || V_189 ) {
struct V_191 * V_192 ;
V_82 = sizeof( struct V_191 ) ;
V_192 = F_4 ( V_2 , & V_5 -> V_10 ,
V_165 ,
V_82 ) ;
V_21 += sizeof( struct V_134 ) ;
if ( V_188 ) {
V_192 -> V_188 = V_188 ;
V_192 -> V_193 = V_186 -> V_194 ;
}
if ( V_189 ) {
V_192 -> V_189 = V_189 ;
V_192 -> V_195 = V_186 -> V_196 ;
}
}
if ( V_186 -> V_169 ) {
struct V_197 * V_198 ;
V_82 = sizeof( struct V_197 ) ;
V_164 = V_168 ;
V_198 = F_4 ( V_2 , & V_5 -> V_10 ,
V_164 , V_82 ) ;
V_21 += sizeof( struct V_134 ) ;
V_198 -> V_199 = V_186 -> V_200 ;
}
if ( V_186 -> V_175 ) {
struct V_201 * V_202 ;
V_82 = sizeof( struct V_201 ) ;
V_202 = F_4 ( V_2 , & V_5 -> V_10 ,
V_174 , V_82 ) ;
V_21 += sizeof( struct V_134 ) ;
memcpy ( V_202 -> V_203 , V_186 -> V_203 ,
sizeof( unsigned long ) * V_204 ) ;
}
V_188 = V_186 -> V_177 . V_178 ;
V_189 = V_186 -> V_177 . V_179 ;
if ( V_188 || V_189 ) {
struct V_205 * V_206 ;
V_164 = V_176 ;
V_82 = sizeof( struct V_205 ) ;
V_206 = F_4 ( V_2 , & V_5 -> V_10 , V_164 , V_82 ) ;
V_21 += sizeof( struct V_134 ) ;
if ( V_188 ) {
V_206 -> V_207 = V_188 ;
V_206 -> V_208 =
V_186 -> V_177 . V_208 ;
}
if ( V_189 ) {
V_206 -> V_209 = V_189 ;
V_206 -> V_210 =
V_186 -> V_177 . V_210 ;
}
}
if ( V_186 -> V_181 ) {
struct V_211 * V_181 = V_186 -> V_181 ;
struct V_212 * V_213 ;
V_82 = sizeof( struct V_212 ) ;
V_213 = F_4 ( V_2 ,
& V_5 -> V_10 ,
V_180 , V_82 ) ;
V_21 += sizeof( struct V_134 ) ;
if ( V_181 -> V_214 )
V_213 -> V_215 |=
V_216 ;
if ( V_181 -> V_217 )
V_213 -> V_215 |=
V_218 ;
if ( V_181 -> V_219 )
V_213 -> V_215 |=
V_220 ;
if ( V_181 -> V_221 )
V_213 -> V_215 |= V_222 ;
V_213 -> V_223 = V_181 -> V_223 ;
V_213 -> V_224 = V_181 -> V_224 ;
V_213 -> V_225 = V_181 -> V_225 ;
memcpy ( V_213 -> V_226 , V_181 -> V_226 ,
sizeof( V_181 -> V_226 ) ) ;
memcpy ( V_213 -> V_227 , V_181 -> V_227 ,
sizeof( V_181 -> V_227 ) ) ;
}
if ( V_186 -> V_173 ) {
struct V_228 * V_229 ;
V_82 = sizeof( struct V_228 ) ;
V_164 = V_172 ;
V_229 = F_4 ( V_2 , & V_5 -> V_10 , V_164 , V_82 ) ;
V_21 += sizeof( struct V_134 ) ;
V_229 -> V_230 = V_186 -> V_230 ;
V_229 -> V_173 =
V_186 -> V_173 ;
}
F_4 ( V_2 , & V_5 -> V_10 ,
V_83 , sizeof( struct V_29 ) ) ;
V_27 = F_5 ( V_2 , & V_44 -> V_84 . V_85 , V_21 ) ;
if ( V_27 )
return V_27 ;
if ( V_44 -> V_84 . V_85 != V_86 )
return - V_88 ;
F_35 ( V_2 , V_186 ) ;
return V_27 ;
}
int F_38 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_134 * V_44 ;
struct V_16 * V_55 ;
int V_27 ;
V_55 = F_1 ( V_2 , V_231 , sizeof( * V_55 ) ) ;
F_4 ( V_2 , & V_5 -> V_10 ,
V_83 , sizeof( struct V_29 ) ) ;
V_44 = & V_5 -> V_14 -> V_136 ;
V_27 = F_5 ( V_2 , & V_44 -> V_84 . V_85 , sizeof( * V_44 ) ) ;
if ( V_27 )
return V_27 ;
if ( V_44 -> V_84 . V_85 != V_86 )
return - V_92 ;
V_2 -> V_232 = 0 ;
return 0 ;
}
int F_39 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_134 * V_44 ;
struct V_16 * V_55 ;
T_2 V_82 ;
int V_27 ;
V_55 = F_1 ( V_2 , V_233 , sizeof( * V_55 ) ) ;
F_4 ( V_2 , & V_5 -> V_10 ,
V_83 , sizeof( struct V_29 ) ) ;
V_44 = & V_5 -> V_14 -> V_136 ;
V_27 = F_5 ( V_2 , & V_44 -> V_84 . V_85 , sizeof( * V_44 ) ) ;
if ( ! V_27 && V_44 -> V_84 . V_85 != V_86 )
V_27 = - V_92 ;
V_2 -> V_232 = 0 ;
if ( V_5 -> V_12 )
F_24 ( & V_2 -> V_93 -> V_108 -> V_109 ,
sizeof( union V_13 ) ,
V_5 -> V_12 ,
V_5 -> V_34 ) ;
if ( V_5 -> V_14 )
F_24 ( & V_2 -> V_93 -> V_108 -> V_109 ,
sizeof( union V_15 ) ,
V_5 -> V_14 , V_5 -> V_19 ) ;
if ( V_5 -> V_79 . V_113 ) {
V_82 = sizeof( struct V_112 ) ;
F_24 ( & V_2 -> V_93 -> V_108 -> V_109 ,
V_82 ,
V_5 -> V_79 . V_113 , V_5 -> V_79 . V_80 ) ;
}
F_25 ( V_2 -> V_6 ) ;
V_2 -> V_6 = NULL ;
return V_27 ;
}
void F_40 ( struct V_1 * V_2 ,
struct V_234 * V_235 )
{
struct V_162 V_236 ;
int V_156 ;
memset ( & V_236 , 0 , sizeof( V_236 ) ) ;
V_236 . V_175 = 1 ;
if ( V_235 -> V_237 == V_238 ) {
for ( V_156 = 0 ; V_156 < V_235 -> V_239 ; V_156 ++ ) {
T_2 V_240 ;
V_240 = F_41 ( V_235 -> V_241 [ V_156 ] ) ;
F_42 ( V_240 , V_236 . V_203 ) ;
}
}
F_37 ( V_2 , & V_236 ) ;
}
int F_43 ( struct V_1 * V_2 ,
struct V_242 * V_243 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_244 * V_55 ;
struct V_134 * V_44 ;
int V_27 ;
V_55 = F_1 ( V_2 , V_245 , sizeof( * V_55 ) ) ;
V_55 -> V_237 = ( V_11 ) V_243 -> V_237 ;
V_55 -> type = ( V_11 ) V_243 -> type ;
memcpy ( V_55 -> V_241 , V_243 -> V_241 , V_246 ) ;
V_55 -> V_247 = V_243 -> V_247 ;
F_4 ( V_2 , & V_5 -> V_10 ,
V_83 , sizeof( struct V_29 ) ) ;
V_44 = & V_5 -> V_14 -> V_136 ;
V_27 = F_5 ( V_2 , & V_44 -> V_84 . V_85 , sizeof( * V_44 ) ) ;
if ( V_27 )
return V_27 ;
if ( V_44 -> V_84 . V_85 != V_86 )
return - V_92 ;
return 0 ;
}
int F_44 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_134 * V_44 = & V_5 -> V_14 -> V_136 ;
int V_27 ;
F_1 ( V_2 , V_248 ,
sizeof( struct V_16 ) ) ;
F_4 ( V_2 , & V_5 -> V_10 ,
V_83 , sizeof( struct V_29 ) ) ;
V_27 = F_5 ( V_2 , & V_44 -> V_84 . V_85 , sizeof( * V_44 ) ) ;
if ( V_27 )
return V_27 ;
if ( V_44 -> V_84 . V_85 != V_86 )
return - V_88 ;
return 0 ;
}
T_1 F_45 ( struct V_1 * V_2 , T_1 V_249 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
if ( ! V_5 ) {
F_18 ( V_2 , L_21 ) ;
return 0 ;
}
return V_5 -> V_45 . V_91 . V_250 [ V_249 ] . V_251 ;
}
int F_46 ( struct V_1 * V_2 , V_11 * V_252 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_112 V_253 ;
T_2 V_254 , V_255 ;
V_255 = sizeof( V_5 -> V_79 . V_113 -> V_254 ) ;
* V_252 = 0 ;
memcpy ( & V_253 , V_5 -> V_79 . V_113 , V_5 -> V_79 . V_82 ) ;
if ( V_253 . V_256 == V_5 -> V_257 . V_256 )
return 0 ;
V_254 = F_47 ( 0 , ( V_11 * ) & V_253 + V_255 ,
V_5 -> V_79 . V_82 - V_255 ) ;
if ( V_254 != V_253 . V_254 )
return - V_92 ;
memcpy ( & V_5 -> V_257 , & V_253 , V_5 -> V_79 . V_82 ) ;
F_3 ( V_2 , V_9 ,
L_22 , V_253 . V_256 ) ;
* V_252 = 1 ;
return 0 ;
}
void F_48 ( struct V_1 * V_2 ,
struct V_258 * V_186 ,
struct V_112 * V_259 )
{
memset ( V_186 , 0 , sizeof( * V_186 ) ) ;
V_186 -> V_260 . V_261 = V_259 -> V_262 ;
V_186 -> V_260 . V_263 = V_259 -> V_264 ;
V_186 -> V_260 . V_265 = V_259 -> V_266 ;
V_186 -> V_267 . V_261 = V_259 -> V_268 ;
V_186 -> V_267 . V_269 = V_259 -> V_270 ;
V_186 -> V_267 . V_271 = V_259 -> V_272 ;
V_186 -> V_273 = V_259 -> V_274 ;
}
void F_49 ( struct V_1 * V_2 ,
struct V_258 * V_275 )
{
F_48 ( V_2 , V_275 ,
& ( V_2 -> V_6 -> V_257 ) ) ;
}
void F_50 ( struct V_1 * V_2 ,
struct V_276 * V_277 ,
struct V_112 * V_259 )
{
memset ( V_277 , 0 , sizeof( * V_277 ) ) ;
V_277 -> V_278 = V_259 -> V_278 ;
V_277 -> V_260 = V_259 -> V_260 ;
V_277 -> V_279 = V_259 -> V_279 ;
V_277 -> V_280 = V_259 -> V_261 ;
V_277 -> V_281 = V_259 -> V_282 ;
V_277 -> V_283 = V_259 -> V_283 ;
V_277 -> V_284 = V_259 -> V_284 ;
V_277 -> V_285 = V_259 -> V_285 ;
V_277 -> V_286 = V_259 -> V_286 ;
V_277 -> V_287 = V_259 -> V_287 ;
V_277 -> V_288 = V_259 -> V_288 ;
V_277 -> V_289 = V_259 -> V_289 ;
}
void F_51 ( struct V_1 * V_2 ,
struct V_276 * V_290 )
{
F_50 ( V_2 , V_290 ,
& ( V_2 -> V_6 -> V_257 ) ) ;
}
void F_52 ( struct V_1 * V_2 ,
struct V_291 * V_292 ,
struct V_112 * V_259 )
{
memset ( V_292 , 0 , sizeof( * V_292 ) ) ;
V_292 -> V_293 = V_259 -> V_294 ;
}
void F_53 ( struct V_1 * V_2 ,
struct V_291 * V_292 )
{
F_52 ( V_2 , V_292 ,
& ( V_2 -> V_6 -> V_257 ) ) ;
}
void F_54 ( struct V_1 * V_2 , V_11 * V_61 )
{
* V_61 = V_2 -> V_6 -> V_45 . V_91 . V_61 ;
}
void F_55 ( struct V_1 * V_2 , V_11 * V_295 )
{
memcpy ( V_295 ,
V_2 -> V_6 -> V_45 . V_47 . V_295 , V_246 ) ;
}
void F_56 ( struct V_1 * V_2 , V_11 * V_64 )
{
struct V_4 * V_296 ;
V_296 = V_2 -> V_6 ;
* V_64 = V_296 -> V_45 . V_91 . V_64 ;
}
bool F_57 ( struct V_1 * V_2 , V_11 * V_241 )
{
struct V_112 * V_79 ;
V_79 = & V_2 -> V_6 -> V_257 ;
if ( ! ( V_79 -> V_297 & ( 1 << V_298 ) ) )
return true ;
if ( F_58 ( V_79 -> V_241 , V_241 ) )
return false ;
return false ;
}
bool F_59 ( struct V_1 * V_299 ,
V_11 * V_300 , V_11 * V_301 )
{
struct V_112 * V_79 ;
V_79 = & V_299 -> V_6 -> V_257 ;
if ( V_79 -> V_297 & ( 1 << V_298 ) ) {
if ( V_301 )
* V_301 = 1 ;
} else if ( V_79 -> V_297 & ( 1 << V_302 ) ) {
if ( V_301 )
* V_301 = 0 ;
} else {
return false ;
}
F_60 ( V_300 , V_79 -> V_241 ) ;
return true ;
}
void F_61 ( struct V_1 * V_2 ,
T_1 * V_68 , T_1 * V_70 ,
T_1 * V_303 , T_1 * V_304 )
{
struct V_46 * V_305 ;
V_305 = & V_2 -> V_6 -> V_45 . V_47 ;
* V_68 = V_305 -> V_68 ;
* V_70 = V_305 -> V_70 ;
* V_303 = V_305 -> V_303 ;
* V_304 = V_305 -> V_304 ;
}
static void F_62 ( struct V_1 * V_299 )
{
struct V_306 * V_307 = V_299 -> V_93 -> V_308 . V_309 ;
V_11 V_241 [ V_246 ] , V_310 , V_311 ;
void * V_312 = V_299 -> V_93 -> V_313 ;
V_310 = F_59 ( V_299 , V_241 ,
& V_311 ) ;
if ( V_310 && V_311 && V_312 )
V_307 -> V_314 ( V_312 , V_241 ) ;
F_63 ( V_299 ) ;
}
void F_64 ( struct V_315 * V_316 )
{
struct V_1 * V_299 = F_65 ( V_316 , struct V_1 ,
V_317 . V_316 ) ;
V_11 V_318 = 0 ;
if ( F_66 ( V_319 , & V_299 -> V_320 ) )
return;
F_46 ( V_299 , & V_318 ) ;
if ( V_318 )
F_62 ( V_299 ) ;
F_67 ( V_299 -> V_321 , & V_299 -> V_317 , V_322 ) ;
}
