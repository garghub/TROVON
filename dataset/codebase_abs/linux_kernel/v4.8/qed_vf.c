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
static void F_14 ( struct V_1 * V_2 ,
struct V_43 * V_22 ,
struct V_44 * V_45 )
{
F_3 ( V_2 ,
V_9 ,
L_5 ,
V_22 -> V_46 ,
V_45 -> V_46 ,
V_22 -> V_46 ,
V_45 -> V_47 ,
V_22 -> V_48 ,
V_45 -> V_48 ,
V_22 -> V_49 ,
V_45 -> V_49 ,
V_22 -> V_50 ,
V_45 -> V_50 ,
V_22 -> V_51 , V_45 -> V_51 ) ;
V_22 -> V_47 = V_45 -> V_47 ;
V_22 -> V_46 = V_45 -> V_46 ;
V_22 -> V_48 = V_45 -> V_48 ;
V_22 -> V_49 = V_45 -> V_49 ;
V_22 -> V_50 = V_45 -> V_50 ;
V_22 -> V_51 = V_45 -> V_51 ;
}
static int F_15 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_52 * V_53 = & V_5 -> V_14 -> V_54 ;
struct V_55 * V_56 = & V_53 -> V_56 ;
struct V_43 * V_57 ;
bool V_58 = false ;
struct V_59 * V_60 ;
int V_27 = 0 , V_61 = 0 ;
V_60 = F_1 ( V_2 , V_62 , sizeof( * V_60 ) ) ;
V_57 = & V_60 -> V_63 ;
V_60 -> V_64 . V_65 = V_2 -> V_31 . V_65 ;
V_57 -> V_46 = V_66 ;
V_57 -> V_47 = V_66 ;
V_57 -> V_48 = V_66 ;
V_57 -> V_49 = V_67 ;
V_57 -> V_50 = V_68 ;
V_60 -> V_64 . V_69 = V_70 ;
V_60 -> V_64 . V_71 = V_72 ;
V_60 -> V_64 . V_73 = V_74 ;
V_60 -> V_64 . V_75 = V_76 ;
V_60 -> V_64 . V_77 = V_78 ;
V_60 -> V_64 . V_79 = V_80 ;
V_60 -> V_64 . V_81 = V_82 ;
V_60 -> V_64 . V_83 |= V_84 ;
V_60 -> V_85 = V_5 -> V_86 . V_87 ;
V_60 -> V_88 = V_5 -> V_86 . V_89 ;
F_4 ( V_2 , & V_5 -> V_10 ,
V_90 , sizeof( struct V_29 ) ) ;
while ( ! V_58 ) {
F_3 ( V_2 ,
V_9 , L_6 ) ;
V_27 = F_5 ( V_2 , & V_53 -> V_91 . V_92 , sizeof( * V_53 ) ) ;
if ( V_27 )
return V_27 ;
memcpy ( & V_5 -> V_54 , V_53 , sizeof( V_5 -> V_54 ) ) ;
V_61 ++ ;
if ( V_53 -> V_91 . V_92 == V_93 ) {
if ( ! ( V_53 -> V_56 . V_83 &
V_94 ) ) {
F_16 ( V_2 ,
L_7 ) ;
return - V_95 ;
}
F_3 ( V_2 , V_9 , L_8 ) ;
V_58 = true ;
} else if ( V_53 -> V_91 . V_92 == V_96 &&
V_61 < V_97 ) {
F_14 ( V_2 , V_57 ,
& V_53 -> V_98 ) ;
memset ( V_5 -> V_14 , 0 , sizeof( union V_15 ) ) ;
} else if ( ( V_53 -> V_91 . V_92 == V_99 ) &&
V_56 -> V_100 &&
( V_56 -> V_100 != V_80 ) ) {
F_17 ( V_2 ,
L_9 ,
V_56 -> V_100 ,
V_56 -> V_101 ,
V_80 ,
V_82 , V_56 -> V_100 ) ;
return - V_95 ;
} else {
F_18 ( V_2 ,
L_10 ,
V_53 -> V_91 . V_92 ) ;
return - V_102 ;
}
}
V_5 -> V_86 . V_89 = V_53 -> V_88 ;
V_2 -> V_103 -> type = V_53 -> V_56 . V_104 ;
V_2 -> V_103 -> V_105 = V_53 -> V_56 . V_105 ;
V_2 -> V_103 -> V_106 = V_56 -> V_106 & 0xffff ;
if ( F_19 ( V_2 ) ) {
if ( V_53 -> V_56 . V_83 & V_107 ) {
F_17 ( V_2 , L_11 ) ;
V_2 -> V_103 -> V_108 = 2 ;
}
}
if ( V_82 &&
( V_53 -> V_56 . V_101 < V_82 ) ) {
F_16 ( V_2 ,
L_12 ,
V_80 , V_53 -> V_56 . V_101 ) ;
}
return 0 ;
}
int F_20 ( struct V_1 * V_2 )
{
struct V_4 * V_5 ;
T_2 V_109 ;
if ( F_19 ( V_2 ) )
V_2 -> V_103 -> V_108 = 1 ;
V_2 -> V_110 = ( V_11 V_111 * ) V_2 -> V_112 +
V_113 ;
V_109 = V_114 ;
V_2 -> V_31 . V_65 = ( T_1 ) F_21 ( V_2 , V_109 ) ;
V_109 = V_115 ;
V_2 -> V_31 . V_32 = F_21 ( V_2 , V_109 ) ;
V_5 = F_22 ( sizeof( * V_5 ) , V_116 ) ;
if ( ! V_5 ) {
F_17 ( V_2 , L_13 ) ;
return - V_117 ;
}
V_5 -> V_12 = F_23 ( & V_2 -> V_103 -> V_118 -> V_119 ,
sizeof( union V_13 ) ,
& V_5 -> V_34 ,
V_116 ) ;
if ( ! V_5 -> V_12 ) {
F_17 ( V_2 ,
L_14 ) ;
goto V_120;
}
V_5 -> V_14 = F_23 ( & V_2 -> V_103 -> V_118 -> V_119 ,
sizeof( union V_15 ) ,
& V_5 -> V_19 ,
V_116 ) ;
if ( ! V_5 -> V_14 ) {
F_17 ( V_2 ,
L_15 ) ;
goto V_121;
}
F_3 ( V_2 ,
V_9 ,
L_16 ,
V_5 -> V_12 ,
( V_18 ) V_5 -> V_34 ,
V_5 -> V_14 , ( V_18 ) V_5 -> V_19 ) ;
V_5 -> V_86 . V_89 = sizeof( struct V_122 ) ;
V_5 -> V_86 . V_123 = F_23 ( & V_2 -> V_103 -> V_118 -> V_119 ,
V_5 -> V_86 . V_89 ,
& V_5 -> V_86 . V_87 ,
V_116 ) ;
F_3 ( V_2 , V_9 ,
L_17 ,
V_5 -> V_86 . V_123 ,
( V_18 ) V_5 -> V_86 . V_87 , V_5 -> V_86 . V_89 ) ;
F_24 ( & V_5 -> V_8 ) ;
V_2 -> V_6 = V_5 ;
V_2 -> V_31 . V_124 = V_125 ;
return F_15 ( V_2 ) ;
V_121:
F_25 ( & V_2 -> V_103 -> V_118 -> V_119 ,
sizeof( union V_13 ) ,
V_5 -> V_12 , V_5 -> V_34 ) ;
V_120:
F_26 ( V_5 ) ;
return - V_117 ;
}
int F_27 ( struct V_1 * V_2 ,
V_11 V_126 ,
T_1 V_127 ,
V_11 V_128 ,
T_1 V_129 ,
T_3 V_130 ,
T_3 V_131 ,
T_1 V_132 , void V_111 * * V_133 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_134 * V_53 ;
struct V_135 * V_60 ;
int V_27 ;
V_60 = F_1 ( V_2 , V_136 , sizeof( * V_60 ) ) ;
V_60 -> V_126 = V_126 ;
V_60 -> V_131 = V_131 ;
V_60 -> V_132 = V_132 ;
V_60 -> V_137 = V_130 ;
V_60 -> V_138 = V_127 ;
V_60 -> V_128 = V_128 ;
V_60 -> V_129 = V_129 ;
V_60 -> V_139 = - 1 ;
F_4 ( V_2 , & V_5 -> V_10 ,
V_90 , sizeof( struct V_29 ) ) ;
V_53 = & V_5 -> V_14 -> V_140 ;
V_27 = F_5 ( V_2 , & V_53 -> V_91 . V_92 , sizeof( * V_53 ) ) ;
if ( V_27 )
return V_27 ;
if ( V_53 -> V_91 . V_92 != V_93 )
return - V_95 ;
if ( V_133 ) {
T_2 V_141 = 0 ;
* V_133 = ( V_11 V_111 * ) V_2 -> V_112 + V_53 -> V_10 ;
F_3 ( V_2 , V_9 ,
L_18 ,
V_126 , * V_133 , V_53 -> V_10 ) ;
F_28 ( V_2 , * V_133 , sizeof( T_2 ) ,
( T_2 * ) & V_141 ) ;
}
return V_27 ;
}
int F_29 ( struct V_1 * V_2 , T_1 V_126 , bool V_142 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_143 * V_60 ;
struct V_144 * V_53 ;
int V_27 ;
V_60 = F_1 ( V_2 , V_145 , sizeof( * V_60 ) ) ;
V_60 -> V_126 = V_126 ;
V_60 -> V_46 = 1 ;
V_60 -> V_142 = V_142 ;
F_4 ( V_2 , & V_5 -> V_10 ,
V_90 , sizeof( struct V_29 ) ) ;
V_53 = & V_5 -> V_14 -> V_146 ;
V_27 = F_5 ( V_2 , & V_53 -> V_91 . V_92 , sizeof( * V_53 ) ) ;
if ( V_27 )
return V_27 ;
if ( V_53 -> V_91 . V_92 != V_93 )
return - V_95 ;
return V_27 ;
}
int F_30 ( struct V_1 * V_2 ,
T_1 V_147 ,
T_1 V_127 ,
V_11 V_128 ,
T_3 V_148 ,
T_1 V_149 , void V_111 * * V_150 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_134 * V_53 ;
struct V_151 * V_60 ;
int V_27 ;
V_60 = F_1 ( V_2 , V_152 , sizeof( * V_60 ) ) ;
V_60 -> V_153 = V_147 ;
V_60 -> V_148 = V_148 ;
V_60 -> V_149 = V_149 ;
V_60 -> V_138 = V_127 ;
V_60 -> V_128 = V_128 ;
F_4 ( V_2 , & V_5 -> V_10 ,
V_90 , sizeof( struct V_29 ) ) ;
V_53 = & V_5 -> V_14 -> V_140 ;
V_27 = F_5 ( V_2 , & V_53 -> V_91 . V_92 , sizeof( * V_53 ) ) ;
if ( V_27 )
goto exit;
if ( V_53 -> V_91 . V_92 != V_93 ) {
V_27 = - V_95 ;
goto exit;
}
if ( V_150 ) {
* V_150 = ( V_11 V_111 * ) V_2 -> V_110 + V_53 -> V_10 ;
F_3 ( V_2 , V_9 ,
L_19 ,
V_147 , * V_150 , V_53 -> V_10 ) ;
}
exit:
return V_27 ;
}
int F_31 ( struct V_1 * V_2 , T_1 V_153 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_154 * V_60 ;
struct V_144 * V_53 ;
int V_27 ;
V_60 = F_1 ( V_2 , V_155 , sizeof( * V_60 ) ) ;
V_60 -> V_153 = V_153 ;
V_60 -> V_47 = 1 ;
F_4 ( V_2 , & V_5 -> V_10 ,
V_90 , sizeof( struct V_29 ) ) ;
V_53 = & V_5 -> V_14 -> V_146 ;
V_27 = F_5 ( V_2 , & V_53 -> V_91 . V_92 , sizeof( * V_53 ) ) ;
if ( V_27 )
return V_27 ;
if ( V_53 -> V_91 . V_92 != V_93 )
return - V_95 ;
return V_27 ;
}
int F_32 ( struct V_1 * V_2 ,
V_11 V_156 ,
T_1 V_157 ,
V_11 V_158 ,
enum V_159 V_160 ,
V_11 V_161 , V_11 V_162 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_163 * V_60 ;
struct V_144 * V_53 ;
int V_27 , V_164 ;
V_60 = F_1 ( V_2 , V_165 , sizeof( * V_60 ) ) ;
V_60 -> V_157 = V_157 ;
V_60 -> V_156 = V_156 ;
V_60 -> V_158 = V_158 ;
V_60 -> V_160 = V_160 ;
V_60 -> V_161 = V_161 ;
V_60 -> V_162 = V_162 ;
for ( V_164 = 0 ; V_164 < V_2 -> V_6 -> V_54 . V_98 . V_48 ; V_164 ++ )
if ( V_2 -> V_166 [ V_164 ] )
V_60 -> V_167 [ V_164 ] = V_2 -> V_166 [ V_164 ] -> V_168 ;
F_4 ( V_2 , & V_5 -> V_10 ,
V_90 , sizeof( struct V_29 ) ) ;
V_53 = & V_5 -> V_14 -> V_146 ;
V_27 = F_5 ( V_2 , & V_53 -> V_91 . V_92 , sizeof( * V_53 ) ) ;
if ( V_27 )
return V_27 ;
if ( V_53 -> V_91 . V_92 != V_93 )
return - V_95 ;
return V_27 ;
}
int F_33 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_144 * V_53 = & V_5 -> V_14 -> V_146 ;
int V_27 ;
F_1 ( V_2 , V_169 ,
sizeof( struct V_16 ) ) ;
F_4 ( V_2 , & V_5 -> V_10 ,
V_90 , sizeof( struct V_29 ) ) ;
V_27 = F_5 ( V_2 , & V_53 -> V_91 . V_92 , sizeof( * V_53 ) ) ;
if ( V_27 )
return V_27 ;
if ( V_53 -> V_91 . V_92 != V_93 )
return - V_95 ;
return V_27 ;
}
static bool
F_34 ( struct V_1 * V_2 ,
struct V_170 * V_171 ,
T_1 V_172 )
{
switch ( V_172 ) {
case V_173 :
return ! ! ( V_171 -> V_174 ||
V_171 -> V_175 ) ;
case V_176 :
return ! ! V_171 -> V_177 ;
case V_178 :
return ! ! V_171 -> V_179 ;
case V_180 :
return ! ! V_171 -> V_181 ;
case V_182 :
return ! ! V_171 -> V_183 ;
case V_184 :
return ! ! ( V_171 -> V_185 . V_186 ||
V_171 -> V_185 . V_187 ) ;
case V_188 :
return ! ! V_171 -> V_189 ;
case V_190 :
return ! ! V_171 -> V_191 ;
default:
F_16 ( V_2 , L_20 ,
V_172 ) ;
return false ;
}
}
static void
F_35 ( struct V_1 * V_2 ,
struct V_170 * V_171 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_144 * V_45 ;
T_1 V_172 ;
for ( V_172 = V_173 ;
V_172 < V_192 ; V_172 ++ ) {
if ( ! F_34 ( V_2 , V_171 , V_172 ) )
continue;
V_45 = (struct V_144 * )
F_36 ( V_2 , V_5 -> V_14 ,
V_172 ) ;
if ( V_45 && V_45 -> V_91 . V_92 )
F_3 ( V_2 , V_9 ,
L_21 ,
V_172 ,
( V_45 && V_45 -> V_91 . V_92 ) ? L_22
: L_23 ) ;
}
}
int F_37 ( struct V_1 * V_2 ,
struct V_170 * V_193 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_194 * V_60 ;
struct V_144 * V_53 ;
V_11 V_195 , V_196 ;
T_2 V_21 = 0 ;
T_1 V_89 , V_172 ;
int V_27 ;
V_53 = & V_5 -> V_14 -> V_146 ;
V_21 = sizeof( * V_53 ) ;
V_195 = V_193 -> V_174 ;
V_196 = V_193 -> V_175 ;
F_1 ( V_2 , V_197 , sizeof( * V_60 ) ) ;
if ( V_195 || V_196 ) {
struct V_198 * V_199 ;
V_89 = sizeof( struct V_198 ) ;
V_199 = F_4 ( V_2 , & V_5 -> V_10 ,
V_173 ,
V_89 ) ;
V_21 += sizeof( struct V_144 ) ;
if ( V_195 ) {
V_199 -> V_195 = V_195 ;
V_199 -> V_200 = V_193 -> V_201 ;
}
if ( V_196 ) {
V_199 -> V_196 = V_196 ;
V_199 -> V_202 = V_193 -> V_203 ;
}
}
if ( V_193 -> V_177 ) {
struct V_204 * V_205 ;
V_89 = sizeof( struct V_204 ) ;
V_172 = V_176 ;
V_205 = F_4 ( V_2 , & V_5 -> V_10 ,
V_172 , V_89 ) ;
V_21 += sizeof( struct V_144 ) ;
V_205 -> V_206 = V_193 -> V_207 ;
}
if ( V_193 -> V_183 ) {
struct V_208 * V_209 ;
V_89 = sizeof( struct V_208 ) ;
V_209 = F_4 ( V_2 , & V_5 -> V_10 ,
V_182 , V_89 ) ;
V_21 += sizeof( struct V_144 ) ;
memcpy ( V_209 -> V_210 , V_193 -> V_210 ,
sizeof( unsigned long ) * V_211 ) ;
}
V_195 = V_193 -> V_185 . V_186 ;
V_196 = V_193 -> V_185 . V_187 ;
if ( V_195 || V_196 ) {
struct V_212 * V_213 ;
V_172 = V_184 ;
V_89 = sizeof( struct V_212 ) ;
V_213 = F_4 ( V_2 , & V_5 -> V_10 , V_172 , V_89 ) ;
V_21 += sizeof( struct V_144 ) ;
if ( V_195 ) {
V_213 -> V_214 = V_195 ;
V_213 -> V_215 =
V_193 -> V_185 . V_215 ;
}
if ( V_196 ) {
V_213 -> V_216 = V_196 ;
V_213 -> V_217 =
V_193 -> V_185 . V_217 ;
}
}
if ( V_193 -> V_189 ) {
struct V_218 * V_189 = V_193 -> V_189 ;
struct V_219 * V_220 ;
V_89 = sizeof( struct V_219 ) ;
V_220 = F_4 ( V_2 ,
& V_5 -> V_10 ,
V_188 , V_89 ) ;
V_21 += sizeof( struct V_144 ) ;
if ( V_189 -> V_221 )
V_220 -> V_222 |=
V_223 ;
if ( V_189 -> V_224 )
V_220 -> V_222 |=
V_225 ;
if ( V_189 -> V_226 )
V_220 -> V_222 |=
V_227 ;
if ( V_189 -> V_228 )
V_220 -> V_222 |= V_229 ;
V_220 -> V_230 = V_189 -> V_230 ;
V_220 -> V_231 = V_189 -> V_231 ;
V_220 -> V_232 = V_189 -> V_232 ;
memcpy ( V_220 -> V_233 , V_189 -> V_233 ,
sizeof( V_189 -> V_233 ) ) ;
memcpy ( V_220 -> V_234 , V_189 -> V_234 ,
sizeof( V_189 -> V_234 ) ) ;
}
if ( V_193 -> V_181 ) {
struct V_235 * V_236 ;
V_89 = sizeof( struct V_235 ) ;
V_172 = V_180 ;
V_236 = F_4 ( V_2 , & V_5 -> V_10 , V_172 , V_89 ) ;
V_21 += sizeof( struct V_144 ) ;
V_236 -> V_237 = V_193 -> V_237 ;
V_236 -> V_181 =
V_193 -> V_181 ;
}
F_4 ( V_2 , & V_5 -> V_10 ,
V_90 , sizeof( struct V_29 ) ) ;
V_27 = F_5 ( V_2 , & V_53 -> V_91 . V_92 , V_21 ) ;
if ( V_27 )
return V_27 ;
if ( V_53 -> V_91 . V_92 != V_93 )
return - V_95 ;
F_35 ( V_2 , V_193 ) ;
return V_27 ;
}
int F_38 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_144 * V_53 ;
struct V_16 * V_60 ;
int V_27 ;
V_60 = F_1 ( V_2 , V_238 , sizeof( * V_60 ) ) ;
F_4 ( V_2 , & V_5 -> V_10 ,
V_90 , sizeof( struct V_29 ) ) ;
V_53 = & V_5 -> V_14 -> V_146 ;
V_27 = F_5 ( V_2 , & V_53 -> V_91 . V_92 , sizeof( * V_53 ) ) ;
if ( V_27 )
return V_27 ;
if ( V_53 -> V_91 . V_92 != V_93 )
return - V_102 ;
V_2 -> V_239 = 0 ;
return 0 ;
}
int F_39 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_144 * V_53 ;
struct V_16 * V_60 ;
T_2 V_89 ;
int V_27 ;
V_60 = F_1 ( V_2 , V_240 , sizeof( * V_60 ) ) ;
F_4 ( V_2 , & V_5 -> V_10 ,
V_90 , sizeof( struct V_29 ) ) ;
V_53 = & V_5 -> V_14 -> V_146 ;
V_27 = F_5 ( V_2 , & V_53 -> V_91 . V_92 , sizeof( * V_53 ) ) ;
if ( ! V_27 && V_53 -> V_91 . V_92 != V_93 )
V_27 = - V_102 ;
V_2 -> V_239 = 0 ;
if ( V_5 -> V_12 )
F_25 ( & V_2 -> V_103 -> V_118 -> V_119 ,
sizeof( union V_13 ) ,
V_5 -> V_12 ,
V_5 -> V_34 ) ;
if ( V_5 -> V_14 )
F_25 ( & V_2 -> V_103 -> V_118 -> V_119 ,
sizeof( union V_15 ) ,
V_5 -> V_14 , V_5 -> V_19 ) ;
if ( V_5 -> V_86 . V_123 ) {
V_89 = sizeof( struct V_122 ) ;
F_25 ( & V_2 -> V_103 -> V_118 -> V_119 ,
V_89 ,
V_5 -> V_86 . V_123 , V_5 -> V_86 . V_87 ) ;
}
F_26 ( V_2 -> V_6 ) ;
V_2 -> V_6 = NULL ;
return V_27 ;
}
void F_40 ( struct V_1 * V_2 ,
struct V_241 * V_242 )
{
struct V_170 V_243 ;
int V_164 ;
memset ( & V_243 , 0 , sizeof( V_243 ) ) ;
V_243 . V_183 = 1 ;
if ( V_242 -> V_244 == V_245 ) {
for ( V_164 = 0 ; V_164 < V_242 -> V_246 ; V_164 ++ ) {
T_2 V_247 ;
V_247 = F_41 ( V_242 -> V_248 [ V_164 ] ) ;
F_42 ( V_247 , V_243 . V_210 ) ;
}
}
F_37 ( V_2 , & V_243 ) ;
}
int F_43 ( struct V_1 * V_2 ,
struct V_249 * V_250 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_251 * V_60 ;
struct V_144 * V_53 ;
int V_27 ;
V_60 = F_1 ( V_2 , V_252 , sizeof( * V_60 ) ) ;
V_60 -> V_244 = ( V_11 ) V_250 -> V_244 ;
V_60 -> type = ( V_11 ) V_250 -> type ;
memcpy ( V_60 -> V_248 , V_250 -> V_248 , V_253 ) ;
V_60 -> V_254 = V_250 -> V_254 ;
F_4 ( V_2 , & V_5 -> V_10 ,
V_90 , sizeof( struct V_29 ) ) ;
V_53 = & V_5 -> V_14 -> V_146 ;
V_27 = F_5 ( V_2 , & V_53 -> V_91 . V_92 , sizeof( * V_53 ) ) ;
if ( V_27 )
return V_27 ;
if ( V_53 -> V_91 . V_92 != V_93 )
return - V_102 ;
return 0 ;
}
int F_44 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_144 * V_53 = & V_5 -> V_14 -> V_146 ;
int V_27 ;
F_1 ( V_2 , V_255 ,
sizeof( struct V_16 ) ) ;
F_4 ( V_2 , & V_5 -> V_10 ,
V_90 , sizeof( struct V_29 ) ) ;
V_27 = F_5 ( V_2 , & V_53 -> V_91 . V_92 , sizeof( * V_53 ) ) ;
if ( V_27 )
return V_27 ;
if ( V_53 -> V_91 . V_92 != V_93 )
return - V_95 ;
return 0 ;
}
T_1 F_45 ( struct V_1 * V_2 , T_1 V_256 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
if ( ! V_5 ) {
F_17 ( V_2 , L_24 ) ;
return 0 ;
}
return V_5 -> V_54 . V_98 . V_257 [ V_256 ] . V_258 ;
}
int F_46 ( struct V_1 * V_2 , V_11 * V_259 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_122 V_260 ;
T_2 V_261 , V_262 ;
V_262 = sizeof( V_5 -> V_86 . V_123 -> V_261 ) ;
* V_259 = 0 ;
memcpy ( & V_260 , V_5 -> V_86 . V_123 , V_5 -> V_86 . V_89 ) ;
if ( V_260 . V_263 == V_5 -> V_264 . V_263 )
return 0 ;
V_261 = F_47 ( 0 , ( V_11 * ) & V_260 + V_262 ,
V_5 -> V_86 . V_89 - V_262 ) ;
if ( V_261 != V_260 . V_261 )
return - V_102 ;
memcpy ( & V_5 -> V_264 , & V_260 , V_5 -> V_86 . V_89 ) ;
F_3 ( V_2 , V_9 ,
L_25 , V_260 . V_263 ) ;
* V_259 = 1 ;
return 0 ;
}
void F_48 ( struct V_1 * V_2 ,
struct V_265 * V_193 ,
struct V_122 * V_266 )
{
memset ( V_193 , 0 , sizeof( * V_193 ) ) ;
V_193 -> V_267 . V_268 = V_266 -> V_269 ;
V_193 -> V_267 . V_270 = V_266 -> V_271 ;
V_193 -> V_267 . V_272 = V_266 -> V_273 ;
V_193 -> V_274 . V_268 = V_266 -> V_275 ;
V_193 -> V_274 . V_276 = V_266 -> V_277 ;
V_193 -> V_274 . V_278 = V_266 -> V_279 ;
V_193 -> V_280 = V_266 -> V_281 ;
}
void F_49 ( struct V_1 * V_2 ,
struct V_265 * V_282 )
{
F_48 ( V_2 , V_282 ,
& ( V_2 -> V_6 -> V_264 ) ) ;
}
void F_50 ( struct V_1 * V_2 ,
struct V_283 * V_284 ,
struct V_122 * V_266 )
{
memset ( V_284 , 0 , sizeof( * V_284 ) ) ;
V_284 -> V_285 = V_266 -> V_285 ;
V_284 -> V_267 = V_266 -> V_267 ;
V_284 -> V_286 = V_266 -> V_286 ;
V_284 -> V_287 = V_266 -> V_268 ;
V_284 -> V_288 = V_266 -> V_289 ;
V_284 -> V_290 = V_266 -> V_290 ;
V_284 -> V_291 = V_266 -> V_291 ;
V_284 -> V_292 = V_266 -> V_292 ;
V_284 -> V_293 = V_266 -> V_293 ;
V_284 -> V_294 = V_266 -> V_294 ;
V_284 -> V_295 = V_266 -> V_295 ;
V_284 -> V_296 = V_266 -> V_296 ;
}
void F_51 ( struct V_1 * V_2 ,
struct V_283 * V_297 )
{
F_50 ( V_2 , V_297 ,
& ( V_2 -> V_6 -> V_264 ) ) ;
}
void F_52 ( struct V_1 * V_2 ,
struct V_298 * V_299 ,
struct V_122 * V_266 )
{
memset ( V_299 , 0 , sizeof( * V_299 ) ) ;
V_299 -> V_300 = V_266 -> V_301 ;
}
void F_53 ( struct V_1 * V_2 ,
struct V_298 * V_299 )
{
F_52 ( V_2 , V_299 ,
& ( V_2 -> V_6 -> V_264 ) ) ;
}
void F_54 ( struct V_1 * V_2 , V_11 * V_46 )
{
* V_46 = V_2 -> V_6 -> V_54 . V_98 . V_46 ;
}
void F_55 ( struct V_1 * V_2 , V_11 * V_302 )
{
memcpy ( V_302 ,
V_2 -> V_6 -> V_54 . V_56 . V_302 , V_253 ) ;
}
void F_56 ( struct V_1 * V_2 , V_11 * V_50 )
{
struct V_4 * V_303 ;
V_303 = V_2 -> V_6 ;
* V_50 = V_303 -> V_54 . V_98 . V_50 ;
}
bool F_57 ( struct V_1 * V_2 , V_11 * V_248 )
{
struct V_122 * V_86 ;
V_86 = & V_2 -> V_6 -> V_264 ;
if ( ! ( V_86 -> V_304 & ( 1 << V_305 ) ) )
return true ;
if ( F_58 ( V_86 -> V_248 , V_248 ) )
return false ;
return false ;
}
bool F_59 ( struct V_1 * V_306 ,
V_11 * V_307 , V_11 * V_308 )
{
struct V_122 * V_86 ;
V_86 = & V_306 -> V_6 -> V_264 ;
if ( V_86 -> V_304 & ( 1 << V_305 ) ) {
if ( V_308 )
* V_308 = 1 ;
} else if ( V_86 -> V_304 & ( 1 << V_309 ) ) {
if ( V_308 )
* V_308 = 0 ;
} else {
return false ;
}
F_60 ( V_307 , V_86 -> V_248 ) ;
return true ;
}
void F_61 ( struct V_1 * V_2 ,
T_1 * V_71 , T_1 * V_73 ,
T_1 * V_310 , T_1 * V_311 )
{
struct V_55 * V_312 ;
V_312 = & V_2 -> V_6 -> V_54 . V_56 ;
* V_71 = V_312 -> V_71 ;
* V_73 = V_312 -> V_73 ;
* V_310 = V_312 -> V_310 ;
* V_311 = V_312 -> V_311 ;
}
static void F_62 ( struct V_1 * V_306 )
{
struct V_313 * V_314 = V_306 -> V_103 -> V_315 . V_316 ;
V_11 V_248 [ V_253 ] , V_317 , V_318 ;
void * V_319 = V_306 -> V_103 -> V_320 ;
V_317 = F_59 ( V_306 , V_248 ,
& V_318 ) ;
if ( V_317 && V_318 && V_319 )
V_314 -> V_321 ( V_319 , V_248 ) ;
F_63 ( V_306 ) ;
}
void F_64 ( struct V_322 * V_323 )
{
struct V_1 * V_306 = F_65 ( V_323 , struct V_1 ,
V_324 . V_323 ) ;
V_11 V_325 = 0 ;
if ( F_66 ( V_326 , & V_306 -> V_327 ) )
return;
F_46 ( V_306 , & V_325 ) ;
if ( V_325 )
F_62 ( V_306 ) ;
F_67 ( V_306 -> V_328 , & V_306 -> V_324 , V_329 ) ;
}
