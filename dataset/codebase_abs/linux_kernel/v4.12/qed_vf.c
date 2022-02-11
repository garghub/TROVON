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
static void F_5 ( struct V_1 * V_2 , int V_20 )
{
union V_15 * V_21 = V_2 -> V_6 -> V_14 ;
F_3 ( V_2 , V_9 ,
L_2 ,
V_20 , V_21 -> V_22 . V_23 . V_24 ) ;
F_6 ( & ( V_2 -> V_6 -> V_8 ) ) ;
}
static int F_7 ( struct V_1 * V_2 , V_11 * V_25 , T_2 V_26 )
{
union V_13 * V_27 = V_2 -> V_6 -> V_12 ;
struct V_28 V_29 ;
struct V_30 * V_31 ;
int V_32 = 0 , time = 100 ;
V_31 = (struct V_30 * ) V_33 ;
F_8 ( V_2 , V_27 ) ;
V_26 += sizeof( struct V_34 ) ;
memset ( & V_29 , 0 , sizeof( struct V_28 ) ) ;
V_29 . V_35 = 1 ;
F_3 ( V_2 ,
V_9 ,
L_3 ,
F_9 ( V_2 -> V_36 . V_37 ,
V_38 ) ,
F_10 ( V_2 -> V_6 -> V_39 ) ,
F_11 ( V_2 -> V_6 -> V_39 ) ,
& V_31 -> V_40 . V_41 ,
* ( ( T_2 * ) & V_29 ) , & V_31 -> V_29 ) ;
F_12 ( V_2 ,
( V_42 ) & V_31 -> V_40 . V_41 . V_43 ,
F_11 ( V_2 -> V_6 -> V_39 ) ) ;
F_12 ( V_2 ,
( V_42 ) & V_31 -> V_40 . V_41 . V_44 ,
F_10 ( V_2 -> V_6 -> V_39 ) ) ;
F_13 () ;
F_12 ( V_2 , ( V_42 ) & V_31 -> V_29 , * ( ( T_2 * ) & V_29 ) ) ;
while ( ( ! * V_25 ) && time ) {
F_14 ( 25 ) ;
time -- ;
}
if ( ! * V_25 ) {
F_15 ( V_2 ,
L_4 ,
V_27 -> V_45 . V_46 . type ) ;
V_32 = - V_47 ;
} else {
if ( ( * V_25 != V_48 ) &&
( * V_25 != V_49 ) )
F_15 ( V_2 ,
L_5 ,
* V_25 , V_27 -> V_45 . V_46 . type ) ;
else
F_3 ( V_2 , V_9 ,
L_5 ,
* V_25 , V_27 -> V_45 . V_46 . type ) ;
}
return V_32 ;
}
static void F_16 ( struct V_1 * V_2 ,
struct V_50 * V_27 ,
struct V_51 * V_52 )
{
F_3 ( V_2 ,
V_9 ,
L_6 ,
V_27 -> V_53 ,
V_52 -> V_53 ,
V_27 -> V_53 ,
V_52 -> V_54 ,
V_27 -> V_55 ,
V_52 -> V_55 ,
V_27 -> V_56 ,
V_52 -> V_56 ,
V_27 -> V_57 ,
V_52 -> V_57 ,
V_27 -> V_58 , V_52 -> V_58 ) ;
V_27 -> V_54 = V_52 -> V_54 ;
V_27 -> V_53 = V_52 -> V_53 ;
V_27 -> V_55 = V_52 -> V_55 ;
V_27 -> V_56 = V_52 -> V_56 ;
V_27 -> V_57 = V_52 -> V_57 ;
V_27 -> V_58 = V_52 -> V_58 ;
}
static int F_17 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_59 * V_21 = & V_5 -> V_14 -> V_60 ;
struct V_61 * V_62 = & V_21 -> V_62 ;
struct V_50 * V_63 ;
bool V_64 = false ;
struct V_65 * V_66 ;
int V_32 = 0 , V_67 = 0 ;
V_66 = F_1 ( V_2 , V_68 , sizeof( * V_66 ) ) ;
V_63 = & V_66 -> V_69 ;
V_66 -> V_70 . V_71 = V_2 -> V_36 . V_71 ;
V_63 -> V_53 = V_72 ;
V_63 -> V_54 = V_72 ;
V_63 -> V_55 = V_72 ;
V_63 -> V_56 = V_73 ;
V_63 -> V_57 = V_74 ;
V_66 -> V_70 . V_75 = V_76 ;
V_66 -> V_70 . V_77 = V_78 ;
V_66 -> V_70 . V_79 = V_80 ;
V_66 -> V_70 . V_81 = V_82 ;
V_66 -> V_70 . V_83 = V_84 ;
V_66 -> V_70 . V_85 = V_86 ;
V_66 -> V_70 . V_87 = V_88 ;
V_66 -> V_70 . V_89 |= V_90 ;
V_66 -> V_91 = V_5 -> V_92 . V_93 ;
V_66 -> V_94 = V_5 -> V_92 . V_95 ;
F_4 ( V_2 , & V_5 -> V_10 ,
V_96 , sizeof( struct V_34 ) ) ;
while ( ! V_64 ) {
F_3 ( V_2 ,
V_9 , L_7 ) ;
memset ( V_5 -> V_14 , 0 , sizeof( union V_15 ) ) ;
V_32 = F_7 ( V_2 , & V_21 -> V_23 . V_24 , sizeof( * V_21 ) ) ;
if ( V_32 )
goto exit;
memcpy ( & V_5 -> V_60 , V_21 , sizeof( V_5 -> V_60 ) ) ;
V_67 ++ ;
if ( V_21 -> V_23 . V_24 == V_48 ) {
if ( ! ( V_21 -> V_62 . V_89 &
V_97 ) ) {
V_66 -> V_70 . V_89 |=
V_98 ;
}
F_3 ( V_2 , V_9 , L_8 ) ;
V_64 = true ;
} else if ( V_21 -> V_23 . V_24 == V_49 &&
V_67 < V_99 ) {
F_16 ( V_2 , V_63 ,
& V_21 -> V_100 ) ;
} else if ( V_21 -> V_23 . V_24 == V_101 ) {
if ( V_62 -> V_102 &&
( V_62 -> V_102 != V_86 ) ) {
F_15 ( V_2 ,
L_9 ,
V_62 -> V_102 ,
V_62 -> V_103 ,
V_86 ,
V_88 ,
V_62 -> V_102 ) ;
V_32 = - V_104 ;
goto exit;
}
if ( ! V_62 -> V_102 ) {
if ( V_66 -> V_70 . V_89 &
V_98 ) {
F_15 ( V_2 ,
L_10 ) ;
V_32 = - V_104 ;
goto exit;
} else {
F_18 ( V_2 ,
L_11 ) ;
V_66 -> V_70 . V_89 |=
V_98 ;
continue;
}
}
F_15 ( V_2 , L_12 ) ;
V_32 = - V_104 ;
goto exit;
} else {
F_19 ( V_2 ,
L_13 ,
V_21 -> V_23 . V_24 ) ;
V_32 = - V_105 ;
goto exit;
}
}
if ( V_66 -> V_70 . V_89 & V_98 )
V_5 -> V_106 = true ;
V_5 -> V_92 . V_95 = V_21 -> V_94 ;
V_2 -> V_107 -> type = V_21 -> V_62 . V_108 ;
V_2 -> V_107 -> V_109 = V_21 -> V_62 . V_109 ;
V_2 -> V_107 -> V_110 = V_62 -> V_110 & 0xffff ;
if ( F_20 ( V_2 ) ) {
if ( V_21 -> V_62 . V_89 & V_111 ) {
F_15 ( V_2 , L_14 ) ;
V_2 -> V_107 -> V_112 = 2 ;
}
}
if ( ! V_5 -> V_106 &&
V_88 &&
( V_21 -> V_62 . V_103 < V_88 ) ) {
F_18 ( V_2 ,
L_15 ,
V_86 , V_21 -> V_62 . V_103 ) ;
}
exit:
F_5 ( V_2 , V_32 ) ;
return V_32 ;
}
int F_21 ( struct V_1 * V_2 )
{
struct V_4 * V_5 ;
T_2 V_113 ;
if ( F_20 ( V_2 ) )
V_2 -> V_107 -> V_112 = 1 ;
V_2 -> V_114 = ( V_11 V_115 * ) V_2 -> V_116 +
V_117 ;
V_113 = V_118 ;
V_2 -> V_36 . V_71 = ( T_1 ) F_22 ( V_2 , V_113 ) ;
V_113 = V_119 ;
V_2 -> V_36 . V_37 = F_22 ( V_2 , V_113 ) ;
V_5 = F_23 ( sizeof( * V_5 ) , V_120 ) ;
if ( ! V_5 )
return - V_121 ;
V_5 -> V_12 = F_24 ( & V_2 -> V_107 -> V_122 -> V_123 ,
sizeof( union V_13 ) ,
& V_5 -> V_39 ,
V_120 ) ;
if ( ! V_5 -> V_12 )
goto V_124;
V_5 -> V_14 = F_24 ( & V_2 -> V_107 -> V_122 -> V_123 ,
sizeof( union V_15 ) ,
& V_5 -> V_19 ,
V_120 ) ;
if ( ! V_5 -> V_14 )
goto V_125;
F_3 ( V_2 ,
V_9 ,
L_16 ,
V_5 -> V_12 ,
( V_18 ) V_5 -> V_39 ,
V_5 -> V_14 , ( V_18 ) V_5 -> V_19 ) ;
V_5 -> V_92 . V_95 = sizeof( struct V_126 ) ;
V_5 -> V_92 . V_127 = F_24 ( & V_2 -> V_107 -> V_122 -> V_123 ,
V_5 -> V_92 . V_95 ,
& V_5 -> V_92 . V_93 ,
V_120 ) ;
F_3 ( V_2 , V_9 ,
L_17 ,
V_5 -> V_92 . V_127 ,
( V_18 ) V_5 -> V_92 . V_93 , V_5 -> V_92 . V_95 ) ;
F_25 ( & V_5 -> V_8 ) ;
V_2 -> V_6 = V_5 ;
V_2 -> V_36 . V_128 = V_129 ;
return F_17 ( V_2 ) ;
V_125:
F_26 ( & V_2 -> V_107 -> V_122 -> V_123 ,
sizeof( union V_13 ) ,
V_5 -> V_12 , V_5 -> V_39 ) ;
V_124:
F_27 ( V_5 ) ;
return - V_121 ;
}
static void
F_28 ( struct V_130 * V_27 ,
struct V_131 * V_132 ,
enum V_133 V_134 , V_11 * V_135 )
{
if ( V_132 -> V_136 ) {
V_27 -> V_137 |= F_29 ( V_134 ) ;
if ( V_132 -> V_138 )
V_27 -> V_139 |= F_29 ( V_134 ) ;
}
* V_135 = V_132 -> V_140 ;
}
static void
F_30 ( struct V_130 * V_27 ,
struct V_131 * V_132 ,
enum V_133 V_134 ,
V_11 * V_135 , struct V_141 * V_142 ,
V_11 * V_143 , T_1 * V_144 )
{
if ( V_142 -> V_145 ) {
* V_143 = 1 ;
* V_144 = V_142 -> V_146 ;
}
F_28 ( V_27 , V_132 , V_134 , V_135 ) ;
}
void F_31 ( struct V_147 * V_148 )
{
if ( V_148 -> V_149 . V_138 )
V_148 -> V_149 . V_136 = true ;
if ( V_148 -> V_150 . V_138 )
V_148 -> V_150 . V_136 = true ;
if ( V_148 -> V_151 . V_138 )
V_148 -> V_151 . V_136 = true ;
if ( V_148 -> V_152 . V_138 )
V_148 -> V_152 . V_136 = true ;
if ( V_148 -> V_153 . V_138 )
V_148 -> V_153 . V_136 = true ;
V_148 -> V_154 = true ;
V_148 -> V_155 = true ;
}
static void
F_32 ( struct V_131 * V_148 ,
T_1 V_156 , V_11 V_139 ,
V_11 V_157 , enum V_158 V_159 )
{
if ( V_156 & F_29 ( V_159 ) ) {
V_148 -> V_138 = V_139 ;
V_148 -> V_140 = V_157 ;
} else {
V_148 -> V_138 = false ;
}
}
static void F_33 ( struct V_1 * V_2 ,
struct V_147 * V_148 ,
struct V_160 * V_52 )
{
T_1 V_161 = V_52 -> V_162 ;
F_32 ( & V_148 -> V_149 , V_161 ,
V_52 -> V_163 , V_52 -> V_164 ,
V_165 ) ;
F_32 ( & V_148 -> V_150 , V_161 ,
V_52 -> V_166 ,
V_52 -> V_167 ,
V_168 ) ;
F_32 ( & V_148 -> V_151 , V_161 ,
V_52 -> V_169 ,
V_52 -> V_170 ,
V_171 ) ;
F_32 ( & V_148 -> V_152 , V_161 ,
V_52 -> V_172 , V_52 -> V_173 ,
V_174 ) ;
F_32 ( & V_148 -> V_153 , V_161 ,
V_52 -> V_175 , V_52 -> V_176 ,
V_177 ) ;
V_148 -> V_178 . V_146 = V_52 -> V_179 ;
V_148 -> V_180 . V_146 = V_52 -> V_181 ;
F_3 ( V_2 , V_9 ,
L_18 ,
V_148 -> V_149 . V_138 , V_148 -> V_150 . V_138 ,
V_148 -> V_151 . V_138 ,
V_148 -> V_152 . V_138 , V_148 -> V_153 . V_138 ) ;
}
int F_34 ( struct V_1 * V_2 ,
struct V_147 * V_132 )
{
struct V_147 * V_148 = & V_2 -> V_107 -> V_182 ;
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_160 * V_52 ;
struct V_130 * V_27 ;
int V_32 ;
V_27 = F_1 ( V_2 , V_183 ,
sizeof( * V_27 ) ) ;
if ( V_132 -> V_154 && V_132 -> V_155 )
V_27 -> V_184 = 1 ;
F_30 ( V_27 , & V_132 -> V_149 , V_165 ,
& V_27 -> V_164 , & V_132 -> V_180 ,
& V_27 -> V_185 ,
& V_27 -> V_180 ) ;
F_30 ( V_27 , & V_132 -> V_150 ,
V_168 ,
& V_27 -> V_167 , & V_132 -> V_178 ,
& V_27 -> V_186 ,
& V_27 -> V_178 ) ;
F_28 ( V_27 , & V_132 -> V_151 ,
V_171 ,
& V_27 -> V_170 ) ;
F_28 ( V_27 , & V_132 -> V_152 ,
V_174 , & V_27 -> V_173 ) ;
F_28 ( V_27 , & V_132 -> V_153 ,
V_177 , & V_27 -> V_176 ) ;
F_4 ( V_2 , & V_5 -> V_10 ,
V_96 ,
sizeof( struct V_34 ) ) ;
V_52 = & V_5 -> V_14 -> V_187 ;
V_32 = F_7 ( V_2 , & V_52 -> V_23 . V_24 , sizeof( * V_52 ) ) ;
if ( V_32 )
goto exit;
if ( V_52 -> V_23 . V_24 != V_48 ) {
F_3 ( V_2 , V_9 ,
L_19 ) ;
V_32 = - V_104 ;
}
F_33 ( V_2 , V_148 , V_52 ) ;
exit:
F_5 ( V_2 , V_32 ) ;
return V_32 ;
}
int
F_35 ( struct V_1 * V_2 ,
struct V_188 * V_189 ,
T_1 V_190 ,
T_3 V_191 ,
T_3 V_192 ,
T_1 V_193 , void V_115 * * V_194 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_195 * V_21 ;
struct V_196 * V_66 ;
V_11 V_197 = V_189 -> V_198 . V_199 ;
int V_32 ;
V_66 = F_1 ( V_2 , V_200 , sizeof( * V_66 ) ) ;
V_66 -> V_197 = V_197 ;
V_66 -> V_192 = V_192 ;
V_66 -> V_193 = V_193 ;
V_66 -> V_201 = V_191 ;
V_66 -> V_202 = V_189 -> V_198 . V_203 ;
V_66 -> V_204 = V_189 -> V_198 . V_205 ;
V_66 -> V_190 = V_190 ;
V_66 -> V_206 = - 1 ;
if ( V_5 -> V_106 ) {
V_11 V_207 = V_5 -> V_60 . V_100 . V_207 [ V_197 ] ;
T_2 V_208 = 0 ;
* V_194 = ( V_11 V_115 * )
V_2 -> V_116 +
F_36 ( V_2 -> V_107 ) +
V_207 * V_209 ;
F_37 ( V_2 , * V_194 , sizeof( T_2 ) ,
( T_2 * ) ( & V_208 ) ) ;
}
F_4 ( V_2 , & V_5 -> V_10 ,
V_96 , sizeof( struct V_34 ) ) ;
V_21 = & V_5 -> V_14 -> V_210 ;
V_32 = F_7 ( V_2 , & V_21 -> V_23 . V_24 , sizeof( * V_21 ) ) ;
if ( V_32 )
goto exit;
if ( V_21 -> V_23 . V_24 != V_48 ) {
V_32 = - V_104 ;
goto exit;
}
if ( ! V_5 -> V_106 ) {
T_2 V_208 = 0 ;
* V_194 = ( V_11 V_115 * ) V_2 -> V_116 + V_21 -> V_10 ;
F_3 ( V_2 , V_9 ,
L_20 ,
V_197 , * V_194 , V_21 -> V_10 ) ;
F_37 ( V_2 , * V_194 , sizeof( T_2 ) ,
( T_2 * ) & V_208 ) ;
}
exit:
F_5 ( V_2 , V_32 ) ;
return V_32 ;
}
int F_38 ( struct V_1 * V_2 ,
struct V_188 * V_189 , bool V_211 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_212 * V_66 ;
struct V_213 * V_21 ;
int V_32 ;
V_66 = F_1 ( V_2 , V_214 , sizeof( * V_66 ) ) ;
V_66 -> V_197 = V_189 -> V_198 . V_199 ;
V_66 -> V_53 = 1 ;
V_66 -> V_211 = V_211 ;
F_4 ( V_2 , & V_5 -> V_10 ,
V_96 , sizeof( struct V_34 ) ) ;
V_21 = & V_5 -> V_14 -> V_22 ;
V_32 = F_7 ( V_2 , & V_21 -> V_23 . V_24 , sizeof( * V_21 ) ) ;
if ( V_32 )
goto exit;
if ( V_21 -> V_23 . V_24 != V_48 ) {
V_32 = - V_104 ;
goto exit;
}
exit:
F_5 ( V_2 , V_32 ) ;
return V_32 ;
}
int
F_39 ( struct V_1 * V_2 ,
struct V_188 * V_189 ,
T_3 V_215 ,
T_1 V_216 , void V_115 * * V_217 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_195 * V_21 ;
struct V_218 * V_66 ;
T_1 V_219 = V_189 -> V_198 . V_199 ;
int V_32 ;
V_66 = F_1 ( V_2 , V_220 , sizeof( * V_66 ) ) ;
V_66 -> V_221 = V_219 ;
V_66 -> V_215 = V_215 ;
V_66 -> V_216 = V_216 ;
V_66 -> V_202 = V_189 -> V_198 . V_203 ;
V_66 -> V_204 = V_189 -> V_198 . V_205 ;
F_4 ( V_2 , & V_5 -> V_10 ,
V_96 , sizeof( struct V_34 ) ) ;
V_21 = & V_5 -> V_14 -> V_210 ;
V_32 = F_7 ( V_2 , & V_21 -> V_23 . V_24 , sizeof( * V_21 ) ) ;
if ( V_32 )
goto exit;
if ( V_21 -> V_23 . V_24 != V_48 ) {
V_32 = - V_104 ;
goto exit;
}
if ( ! V_5 -> V_106 ) {
* V_217 = ( V_11 V_115 * ) V_2 -> V_114 + V_21 -> V_10 ;
} else {
V_11 V_222 = V_5 -> V_60 . V_100 . V_222 [ V_219 ] ;
* V_217 = ( V_11 V_115 * ) V_2 -> V_114 +
F_40 ( V_222 ,
V_223 ) ;
}
F_3 ( V_2 , V_9 ,
L_21 ,
V_219 , * V_217 , V_21 -> V_10 ) ;
exit:
F_5 ( V_2 , V_32 ) ;
return V_32 ;
}
int F_41 ( struct V_1 * V_2 , struct V_188 * V_189 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_224 * V_66 ;
struct V_213 * V_21 ;
int V_32 ;
V_66 = F_1 ( V_2 , V_225 , sizeof( * V_66 ) ) ;
V_66 -> V_221 = V_189 -> V_198 . V_199 ;
V_66 -> V_54 = 1 ;
F_4 ( V_2 , & V_5 -> V_10 ,
V_96 , sizeof( struct V_34 ) ) ;
V_21 = & V_5 -> V_14 -> V_22 ;
V_32 = F_7 ( V_2 , & V_21 -> V_23 . V_24 , sizeof( * V_21 ) ) ;
if ( V_32 )
goto exit;
if ( V_21 -> V_23 . V_24 != V_48 ) {
V_32 = - V_104 ;
goto exit;
}
exit:
F_5 ( V_2 , V_32 ) ;
return V_32 ;
}
int F_42 ( struct V_1 * V_2 ,
V_11 V_226 ,
T_1 V_227 ,
V_11 V_228 ,
enum V_229 V_230 ,
V_11 V_231 , V_11 V_232 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_233 * V_66 ;
struct V_213 * V_21 ;
int V_32 , V_234 ;
V_66 = F_1 ( V_2 , V_235 , sizeof( * V_66 ) ) ;
V_66 -> V_227 = V_227 ;
V_66 -> V_226 = V_226 ;
V_66 -> V_228 = V_228 ;
V_66 -> V_230 = V_230 ;
V_66 -> V_231 = V_231 ;
V_66 -> V_232 = V_232 ;
for ( V_234 = 0 ; V_234 < V_2 -> V_6 -> V_60 . V_100 . V_55 ; V_234 ++ )
if ( V_2 -> V_236 [ V_234 ] )
V_66 -> V_237 [ V_234 ] = V_2 -> V_236 [ V_234 ] -> V_238 ;
F_4 ( V_2 , & V_5 -> V_10 ,
V_96 , sizeof( struct V_34 ) ) ;
V_21 = & V_5 -> V_14 -> V_22 ;
V_32 = F_7 ( V_2 , & V_21 -> V_23 . V_24 , sizeof( * V_21 ) ) ;
if ( V_32 )
goto exit;
if ( V_21 -> V_23 . V_24 != V_48 ) {
V_32 = - V_104 ;
goto exit;
}
exit:
F_5 ( V_2 , V_32 ) ;
return V_32 ;
}
int F_43 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_213 * V_21 = & V_5 -> V_14 -> V_22 ;
int V_32 ;
F_1 ( V_2 , V_239 ,
sizeof( struct V_16 ) ) ;
F_4 ( V_2 , & V_5 -> V_10 ,
V_96 , sizeof( struct V_34 ) ) ;
V_32 = F_7 ( V_2 , & V_21 -> V_23 . V_24 , sizeof( * V_21 ) ) ;
if ( V_32 )
goto exit;
if ( V_21 -> V_23 . V_24 != V_48 ) {
V_32 = - V_104 ;
goto exit;
}
exit:
F_5 ( V_2 , V_32 ) ;
return V_32 ;
}
static bool
F_44 ( struct V_1 * V_2 ,
struct V_240 * V_241 ,
T_1 V_242 )
{
switch ( V_242 ) {
case V_243 :
return ! ! ( V_241 -> V_244 ||
V_241 -> V_245 ) ;
case V_246 :
return ! ! V_241 -> V_247 ;
case V_248 :
return ! ! V_241 -> V_249 ;
case V_250 :
return ! ! V_241 -> V_251 ;
case V_252 :
return ! ! V_241 -> V_253 ;
case V_254 :
return ! ! ( V_241 -> V_255 . V_256 ||
V_241 -> V_255 . V_257 ) ;
case V_258 :
return ! ! V_241 -> V_259 ;
case V_260 :
return ! ! V_241 -> V_261 ;
default:
F_18 ( V_2 , L_22 ,
V_242 ) ;
return false ;
}
}
static void
F_45 ( struct V_1 * V_2 ,
struct V_240 * V_241 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_213 * V_52 ;
T_1 V_242 ;
for ( V_242 = V_243 ;
V_242 < V_262 ; V_242 ++ ) {
if ( ! F_44 ( V_2 , V_241 , V_242 ) )
continue;
V_52 = (struct V_213 * )
F_46 ( V_2 , V_5 -> V_14 ,
V_242 ) ;
if ( V_52 && V_52 -> V_23 . V_24 )
F_3 ( V_2 , V_9 ,
L_23 ,
V_242 ,
( V_52 && V_52 -> V_23 . V_24 ) ? L_24
: L_25 ) ;
}
}
int F_47 ( struct V_1 * V_2 ,
struct V_240 * V_263 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_264 * V_66 ;
struct V_213 * V_21 ;
V_11 V_265 , V_266 ;
T_2 V_26 = 0 ;
T_1 V_95 , V_242 ;
int V_32 ;
V_21 = & V_5 -> V_14 -> V_22 ;
V_26 = sizeof( * V_21 ) ;
V_265 = V_263 -> V_244 ;
V_266 = V_263 -> V_245 ;
F_1 ( V_2 , V_267 , sizeof( * V_66 ) ) ;
if ( V_265 || V_266 ) {
struct V_268 * V_269 ;
V_95 = sizeof( struct V_268 ) ;
V_269 = F_4 ( V_2 , & V_5 -> V_10 ,
V_243 ,
V_95 ) ;
V_26 += sizeof( struct V_213 ) ;
if ( V_265 ) {
V_269 -> V_265 = V_265 ;
V_269 -> V_270 = V_263 -> V_271 ;
}
if ( V_266 ) {
V_269 -> V_266 = V_266 ;
V_269 -> V_272 = V_263 -> V_273 ;
}
}
if ( V_263 -> V_247 ) {
struct V_274 * V_275 ;
V_95 = sizeof( struct V_274 ) ;
V_242 = V_246 ;
V_275 = F_4 ( V_2 , & V_5 -> V_10 ,
V_242 , V_95 ) ;
V_26 += sizeof( struct V_213 ) ;
V_275 -> V_276 = V_263 -> V_277 ;
}
if ( V_263 -> V_253 ) {
struct V_278 * V_279 ;
V_95 = sizeof( struct V_278 ) ;
V_279 = F_4 ( V_2 , & V_5 -> V_10 ,
V_252 , V_95 ) ;
V_26 += sizeof( struct V_213 ) ;
memcpy ( V_279 -> V_280 , V_263 -> V_280 ,
sizeof( unsigned long ) * V_281 ) ;
}
V_265 = V_263 -> V_255 . V_256 ;
V_266 = V_263 -> V_255 . V_257 ;
if ( V_265 || V_266 ) {
struct V_282 * V_283 ;
V_242 = V_254 ;
V_95 = sizeof( struct V_282 ) ;
V_283 = F_4 ( V_2 , & V_5 -> V_10 , V_242 , V_95 ) ;
V_26 += sizeof( struct V_213 ) ;
if ( V_265 ) {
V_283 -> V_284 = V_265 ;
V_283 -> V_285 =
V_263 -> V_255 . V_285 ;
}
if ( V_266 ) {
V_283 -> V_286 = V_266 ;
V_283 -> V_287 =
V_263 -> V_255 . V_287 ;
}
}
if ( V_263 -> V_259 ) {
struct V_288 * V_259 = V_263 -> V_259 ;
struct V_289 * V_290 ;
int V_234 , V_291 ;
V_95 = sizeof( struct V_289 ) ;
V_290 = F_4 ( V_2 ,
& V_5 -> V_10 ,
V_258 , V_95 ) ;
V_26 += sizeof( struct V_213 ) ;
if ( V_259 -> V_292 )
V_290 -> V_293 |=
V_294 ;
if ( V_259 -> V_295 )
V_290 -> V_293 |=
V_296 ;
if ( V_259 -> V_297 )
V_290 -> V_293 |=
V_298 ;
if ( V_259 -> V_299 )
V_290 -> V_293 |= V_300 ;
V_290 -> V_301 = V_259 -> V_301 ;
V_290 -> V_302 = V_259 -> V_302 ;
V_290 -> V_303 = V_259 -> V_303 ;
V_291 = F_48 ( int , V_304 ,
1 << V_290 -> V_303 ) ;
for ( V_234 = 0 ; V_234 < V_291 ; V_234 ++ ) {
struct V_188 * V_305 ;
V_305 = V_259 -> V_306 [ V_234 ] ;
V_290 -> V_306 [ V_234 ] = V_305 -> V_198 . V_199 ;
}
memcpy ( V_290 -> V_307 , V_259 -> V_307 ,
sizeof( V_259 -> V_307 ) ) ;
}
if ( V_263 -> V_251 ) {
struct V_308 * V_309 ;
V_95 = sizeof( struct V_308 ) ;
V_242 = V_250 ;
V_309 = F_4 ( V_2 , & V_5 -> V_10 , V_242 , V_95 ) ;
V_26 += sizeof( struct V_213 ) ;
V_309 -> V_310 = V_263 -> V_310 ;
V_309 -> V_251 =
V_263 -> V_251 ;
}
F_4 ( V_2 , & V_5 -> V_10 ,
V_96 , sizeof( struct V_34 ) ) ;
V_32 = F_7 ( V_2 , & V_21 -> V_23 . V_24 , V_26 ) ;
if ( V_32 )
goto exit;
if ( V_21 -> V_23 . V_24 != V_48 ) {
V_32 = - V_104 ;
goto exit;
}
F_45 ( V_2 , V_263 ) ;
exit:
F_5 ( V_2 , V_32 ) ;
return V_32 ;
}
int F_49 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_213 * V_21 ;
struct V_16 * V_66 ;
int V_32 ;
V_66 = F_1 ( V_2 , V_311 , sizeof( * V_66 ) ) ;
F_4 ( V_2 , & V_5 -> V_10 ,
V_96 , sizeof( struct V_34 ) ) ;
V_21 = & V_5 -> V_14 -> V_22 ;
V_32 = F_7 ( V_2 , & V_21 -> V_23 . V_24 , sizeof( * V_21 ) ) ;
if ( V_32 )
goto exit;
if ( V_21 -> V_23 . V_24 != V_48 ) {
V_32 = - V_105 ;
goto exit;
}
V_2 -> V_312 = 0 ;
exit:
F_5 ( V_2 , V_32 ) ;
return V_32 ;
}
int F_50 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_213 * V_21 ;
struct V_16 * V_66 ;
T_2 V_95 ;
int V_32 ;
V_66 = F_1 ( V_2 , V_313 , sizeof( * V_66 ) ) ;
F_4 ( V_2 , & V_5 -> V_10 ,
V_96 , sizeof( struct V_34 ) ) ;
V_21 = & V_5 -> V_14 -> V_22 ;
V_32 = F_7 ( V_2 , & V_21 -> V_23 . V_24 , sizeof( * V_21 ) ) ;
if ( ! V_32 && V_21 -> V_23 . V_24 != V_48 )
V_32 = - V_105 ;
F_5 ( V_2 , V_32 ) ;
V_2 -> V_312 = 0 ;
if ( V_5 -> V_12 )
F_26 ( & V_2 -> V_107 -> V_122 -> V_123 ,
sizeof( union V_13 ) ,
V_5 -> V_12 ,
V_5 -> V_39 ) ;
if ( V_5 -> V_14 )
F_26 ( & V_2 -> V_107 -> V_122 -> V_123 ,
sizeof( union V_15 ) ,
V_5 -> V_14 , V_5 -> V_19 ) ;
if ( V_5 -> V_92 . V_127 ) {
V_95 = sizeof( struct V_126 ) ;
F_26 ( & V_2 -> V_107 -> V_122 -> V_123 ,
V_95 ,
V_5 -> V_92 . V_127 , V_5 -> V_92 . V_93 ) ;
}
F_27 ( V_2 -> V_6 ) ;
V_2 -> V_6 = NULL ;
return V_32 ;
}
void F_51 ( struct V_1 * V_2 ,
struct V_314 * V_315 )
{
struct V_240 V_316 ;
int V_234 ;
memset ( & V_316 , 0 , sizeof( V_316 ) ) ;
V_316 . V_253 = 1 ;
if ( V_315 -> V_317 == V_318 ) {
for ( V_234 = 0 ; V_234 < V_315 -> V_319 ; V_234 ++ ) {
T_2 V_320 ;
V_320 = F_52 ( V_315 -> V_321 [ V_234 ] ) ;
F_53 ( V_320 , V_316 . V_280 ) ;
}
}
F_47 ( V_2 , & V_316 ) ;
}
int F_54 ( struct V_1 * V_2 ,
struct V_322 * V_323 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_324 * V_66 ;
struct V_213 * V_21 ;
int V_32 ;
V_66 = F_1 ( V_2 , V_325 , sizeof( * V_66 ) ) ;
V_66 -> V_317 = ( V_11 ) V_323 -> V_317 ;
V_66 -> type = ( V_11 ) V_323 -> type ;
memcpy ( V_66 -> V_321 , V_323 -> V_321 , V_326 ) ;
V_66 -> V_327 = V_323 -> V_327 ;
F_4 ( V_2 , & V_5 -> V_10 ,
V_96 , sizeof( struct V_34 ) ) ;
V_21 = & V_5 -> V_14 -> V_22 ;
V_32 = F_7 ( V_2 , & V_21 -> V_23 . V_24 , sizeof( * V_21 ) ) ;
if ( V_32 )
goto exit;
if ( V_21 -> V_23 . V_24 != V_48 ) {
V_32 = - V_105 ;
goto exit;
}
exit:
F_5 ( V_2 , V_32 ) ;
return V_32 ;
}
int F_55 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_213 * V_21 = & V_5 -> V_14 -> V_22 ;
int V_32 ;
F_1 ( V_2 , V_328 ,
sizeof( struct V_16 ) ) ;
F_4 ( V_2 , & V_5 -> V_10 ,
V_96 , sizeof( struct V_34 ) ) ;
V_32 = F_7 ( V_2 , & V_21 -> V_23 . V_24 , sizeof( * V_21 ) ) ;
if ( V_32 )
goto exit;
if ( V_21 -> V_23 . V_24 != V_48 ) {
V_32 = - V_104 ;
goto exit;
}
exit:
F_5 ( V_2 , V_32 ) ;
return V_32 ;
}
T_1 F_56 ( struct V_1 * V_2 , T_1 V_329 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
if ( ! V_5 ) {
F_15 ( V_2 , L_26 ) ;
return 0 ;
}
return V_5 -> V_60 . V_100 . V_330 [ V_329 ] . V_331 ;
}
int F_57 ( struct V_1 * V_2 , V_11 * V_332 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_126 V_333 ;
T_2 V_334 , V_335 ;
V_335 = sizeof( V_5 -> V_92 . V_127 -> V_334 ) ;
* V_332 = 0 ;
memcpy ( & V_333 , V_5 -> V_92 . V_127 , V_5 -> V_92 . V_95 ) ;
if ( V_333 . V_336 == V_5 -> V_337 . V_336 )
return 0 ;
V_334 = F_58 ( 0 , ( V_11 * ) & V_333 + V_335 ,
V_5 -> V_92 . V_95 - V_335 ) ;
if ( V_334 != V_333 . V_334 )
return - V_105 ;
memcpy ( & V_5 -> V_337 , & V_333 , V_5 -> V_92 . V_95 ) ;
F_3 ( V_2 , V_9 ,
L_27 , V_333 . V_336 ) ;
* V_332 = 1 ;
return 0 ;
}
void F_59 ( struct V_1 * V_2 ,
struct V_338 * V_263 ,
struct V_126 * V_339 )
{
memset ( V_263 , 0 , sizeof( * V_263 ) ) ;
V_263 -> V_340 . V_341 = V_339 -> V_342 ;
V_263 -> V_340 . V_343 = V_339 -> V_344 ;
V_263 -> V_340 . V_345 = V_339 -> V_346 ;
V_263 -> V_347 . V_341 = V_339 -> V_348 ;
V_263 -> V_347 . V_349 = V_339 -> V_350 ;
V_263 -> V_347 . V_351 = V_339 -> V_352 ;
V_263 -> V_353 = V_339 -> V_354 ;
}
void F_60 ( struct V_1 * V_2 ,
struct V_338 * V_355 )
{
F_59 ( V_2 , V_355 ,
& ( V_2 -> V_6 -> V_337 ) ) ;
}
void F_61 ( struct V_1 * V_2 ,
struct V_356 * V_357 ,
struct V_126 * V_339 )
{
memset ( V_357 , 0 , sizeof( * V_357 ) ) ;
V_357 -> V_358 = V_339 -> V_358 ;
V_357 -> V_340 = V_339 -> V_340 ;
V_357 -> V_359 = V_339 -> V_359 ;
V_357 -> V_360 = V_339 -> V_341 ;
V_357 -> V_361 = V_339 -> V_362 ;
V_357 -> V_363 = V_339 -> V_363 ;
V_357 -> V_364 = V_339 -> V_364 ;
V_357 -> V_365 = V_339 -> V_365 ;
V_357 -> V_366 = V_339 -> V_366 ;
V_357 -> V_367 = V_339 -> V_367 ;
V_357 -> V_368 = V_339 -> V_368 ;
V_357 -> V_369 = V_339 -> V_369 ;
}
void F_62 ( struct V_1 * V_2 ,
struct V_356 * V_370 )
{
F_61 ( V_2 , V_370 ,
& ( V_2 -> V_6 -> V_337 ) ) ;
}
void F_63 ( struct V_1 * V_2 ,
struct V_371 * V_372 ,
struct V_126 * V_339 )
{
memset ( V_372 , 0 , sizeof( * V_372 ) ) ;
V_372 -> V_373 = V_339 -> V_374 ;
}
void F_64 ( struct V_1 * V_2 ,
struct V_371 * V_372 )
{
F_63 ( V_2 , V_372 ,
& ( V_2 -> V_6 -> V_337 ) ) ;
}
void F_65 ( struct V_1 * V_2 , V_11 * V_53 )
{
* V_53 = V_2 -> V_6 -> V_60 . V_100 . V_53 ;
}
void F_66 ( struct V_1 * V_2 , V_11 * V_375 )
{
memcpy ( V_375 ,
V_2 -> V_6 -> V_60 . V_62 . V_375 , V_326 ) ;
}
void F_67 ( struct V_1 * V_2 , V_11 * V_57 )
{
struct V_4 * V_376 ;
V_376 = V_2 -> V_6 ;
* V_57 = V_376 -> V_60 . V_100 . V_57 ;
}
void F_68 ( struct V_1 * V_2 , V_11 * V_56 )
{
struct V_4 * V_376 = V_2 -> V_6 ;
* V_56 = V_376 -> V_60 . V_100 . V_56 ;
}
bool F_69 ( struct V_1 * V_2 , V_11 * V_321 )
{
struct V_126 * V_92 ;
V_92 = & V_2 -> V_6 -> V_337 ;
if ( ! ( V_92 -> V_377 & ( 1 << V_378 ) ) )
return true ;
if ( F_70 ( V_92 -> V_321 , V_321 ) )
return false ;
return false ;
}
static bool F_71 ( struct V_1 * V_379 ,
V_11 * V_380 , V_11 * V_381 )
{
struct V_126 * V_92 ;
V_92 = & V_379 -> V_6 -> V_337 ;
if ( V_92 -> V_377 & ( 1 << V_378 ) ) {
if ( V_381 )
* V_381 = 1 ;
} else if ( V_92 -> V_377 & ( 1 << V_382 ) ) {
if ( V_381 )
* V_381 = 0 ;
} else {
return false ;
}
F_72 ( V_380 , V_92 -> V_321 ) ;
return true ;
}
static void
F_73 ( struct V_1 * V_2 ,
T_1 * V_383 , T_1 * V_384 )
{
struct V_126 * V_339 ;
V_339 = & V_2 -> V_6 -> V_337 ;
* V_383 = V_339 -> V_181 ;
* V_384 = V_339 -> V_179 ;
}
void F_74 ( struct V_1 * V_2 ,
T_1 * V_77 , T_1 * V_79 ,
T_1 * V_385 , T_1 * V_386 )
{
struct V_61 * V_387 ;
V_387 = & V_2 -> V_6 -> V_60 . V_62 ;
* V_77 = V_387 -> V_77 ;
* V_79 = V_387 -> V_79 ;
* V_385 = V_387 -> V_385 ;
* V_386 = V_387 -> V_386 ;
}
static void F_75 ( struct V_1 * V_379 )
{
struct V_388 * V_389 = V_379 -> V_107 -> V_390 . V_391 ;
V_11 V_321 [ V_326 ] , V_392 , V_393 ;
void * V_394 = V_379 -> V_107 -> V_395 ;
T_1 V_180 , V_178 ;
F_73 ( V_379 , & V_180 , & V_178 ) ;
V_392 = F_71 ( V_379 , V_321 ,
& V_393 ) ;
if ( V_392 && V_394 )
V_389 -> V_396 ( V_394 , V_321 , ! ! V_393 ) ;
V_389 -> V_397 ( V_394 , V_180 , V_178 ) ;
F_76 ( V_379 ) ;
}
void F_77 ( struct V_398 * V_399 )
{
struct V_1 * V_379 = F_78 ( V_399 , struct V_1 ,
V_400 . V_399 ) ;
V_11 V_401 = 0 ;
if ( F_79 ( V_402 , & V_379 -> V_403 ) )
return;
F_57 ( V_379 , & V_401 ) ;
if ( F_79 ( V_404 ,
& V_379 -> V_403 ) )
V_401 = 1 ;
if ( V_401 )
F_75 ( V_379 ) ;
F_80 ( V_379 -> V_405 , & V_379 -> V_400 , V_406 ) ;
}
