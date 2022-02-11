static int F_1 ( struct V_1 * V_2 ,
T_1 V_3 ,
const void * V_4 ,
T_2 V_5 ,
T_1 V_6 )
{
struct V_7 V_8 = V_9 ;
struct V_10 V_11 ;
struct V_12 V_13 ;
V_13 . V_14 = V_3 ;
V_11 . V_14 = V_15 ;
V_11 . V_6 = V_6 ;
return F_2 ( V_2 , & V_8 , & V_11 , & V_13 ,
V_4 , V_5 ) ;
}
int F_3 ( struct V_1 * V_2 , void * V_16 , T_2 V_17 ,
bool V_6 )
{
struct V_18 * V_19 = (struct V_18 * ) V_16 ;
struct V_7 V_8 = V_20 ;
struct V_10 V_11 ;
int V_21 ;
T_1 V_22 = V_19 -> V_22 ;
if ( ! F_4 ( V_23 , & V_2 -> V_24 ) ) {
F_5 ( V_2 , L_1 ) ;
return - V_25 ;
}
V_11 . V_14 = V_26 ;
V_11 . V_6 = V_6 ;
V_21 = F_6 ( V_2 , & V_8 , & V_11 ,
V_16 , V_17 ) ;
if ( V_6 ) {
V_21 = F_7 ( V_2 -> V_27 ,
F_8 ( V_22 , & V_2 -> V_28 [ 0 ] ) ,
3 * V_29 ) ;
return V_21 ? 0 : - V_30 ;
}
return V_21 ;
}
int F_9 ( struct V_1 * V_2 )
{
struct V_31 V_32 ;
T_3 V_33 , V_34 ;
memset ( & V_32 , 0 , sizeof( struct V_31 ) ) ;
V_32 . V_35 = V_36 ;
switch ( V_37 ) {
case V_38 :
case V_39 :
V_33 = 1 ;
break;
default:
V_33 = 0 ;
break;
}
switch ( V_2 -> V_40 . V_41 ) {
case V_42 :
case V_43 :
V_34 = 1 ;
break;
default:
V_34 = 0 ;
break;
}
if ( V_33 && V_34 ) {
V_32 . V_35 |= V_44 |
V_45 |
V_46 ;
switch ( V_37 ) {
case V_38 :
memcpy ( V_32 . V_47 , V_48 ,
sizeof( V_48 ) ) ;
break;
case V_39 :
memcpy ( V_32 . V_47 , V_49 ,
sizeof( V_49 ) ) ;
break;
default:
F_5 ( V_2 , L_2 ,
V_37 ) ;
break;
}
} else
F_10 ( V_2 , L_3 ) ;
return F_1 ( V_2 , V_50 ,
& V_32 ,
sizeof( struct V_31 ) , 0 ) ;
}
int F_11 ( struct V_1 * V_2 , T_1 V_51 )
{
struct V_52 V_53 ;
memset ( & V_53 , 0 , sizeof( struct V_52 ) ) ;
V_53 . V_54 . V_55 . V_56 = F_12 ( V_51 ) ;
V_53 . V_54 . V_55 . V_57 = F_12 ( V_51 ) ;
V_53 . V_54 . V_55 . V_58 = F_12 ( V_51 ) ;
V_53 . V_54 . V_35 =
F_12 ( V_59 ) ;
return F_1 ( V_2 , V_60 , & V_53 ,
sizeof( struct V_52 ) , 1 ) ;
}
int F_13 ( struct V_1 * V_2 , T_1 V_51 )
{
struct V_52 V_53 ;
memset ( & V_53 , 0 , sizeof( struct V_52 ) ) ;
V_53 . V_54 . V_61 . V_56 = F_12 ( V_51 ) ;
V_53 . V_54 . V_61 . V_57 = F_12 ( V_51 ) ;
return F_1 ( V_2 , V_60 , & V_53 ,
sizeof( struct V_52 ) , 0 ) ;
}
int F_14 ( struct V_1 * V_2 )
{
struct V_62 * V_63 ;
T_1 * V_64 = F_15 ( V_2 , V_65 ) ;
int V_66 = sizeof( struct V_67 ) ;
V_63 = F_16 ( sizeof( struct V_62 ) , V_68 ) ;
if ( ! V_63 ) {
F_5 ( V_2 , L_4 ) ;
return - V_69 ;
}
V_64 = F_15 ( V_2 , V_65 ) ;
if ( F_17 ( V_64 ) ) {
F_5 ( V_2 , L_5 ) ;
F_18 ( V_63 ) ;
return F_19 ( V_64 ) ;
}
V_2 -> V_70 [ V_71 ] . V_72 = ( T_1 * ) V_63 ;
V_2 -> V_70 [ V_71 ] . V_73 = sizeof( * V_63 ) ;
V_63 -> V_19 . V_74 = V_71 ;
V_63 -> V_19 . V_75 = 0 ;
V_63 -> V_19 . V_76 = 1 ;
V_63 -> V_19 . V_77 = 1 ;
memcpy ( & V_63 -> V_78 [ 0 ] , V_64 , 4 * V_66 ) ;
memcpy ( & V_63 -> V_78 [ 4 ] , V_64 + 6 * V_66 , V_66 ) ;
return 0 ;
}
int F_20 ( struct V_1 * V_2 )
{
int V_79 , V_21 = 0 ;
for ( V_79 = V_80 ; V_79 < V_81 ; V_79 ++ ) {
if ( F_4 ( V_79 - V_80 ,
& V_2 -> V_82 ) ) {
F_21 ( V_2 , V_83 ,
L_6 , V_79 ) ;
V_21 |= F_1 ( V_2 ,
V_84 ,
V_2 -> V_70 [ V_79 ] . V_72 ,
V_2 -> V_70 [ V_79 ] . V_73 , 0 ) ;
F_18 ( V_2 -> V_70 [ V_79 ] . V_72 ) ;
V_2 -> V_70 [ V_79 ] . V_72 = NULL ;
V_2 -> V_70 [ V_79 ] . V_73 = 0 ;
}
}
return V_21 ;
}
int F_22 ( struct V_1 * V_2 , T_1 V_85 , T_1 exit )
{
struct V_86 V_87 ;
V_87 . V_88 = V_85 ;
V_87 . V_89 = exit ;
return F_1 ( V_2 , V_90 , & V_87 ,
sizeof( struct V_86 ) , 0 ) ;
}
int F_23 ( struct V_1 * V_2 , T_4 V_91 , bool V_6 )
{
struct V_7 V_8 = V_20 ;
struct V_10 V_11 ;
struct V_92 V_93 ;
V_93 . V_35 = V_91 ;
V_11 . V_14 = V_94 ;
V_11 . V_6 = V_6 ;
return F_6 ( V_2 , & V_8 , & V_11 , & V_93 ,
sizeof( struct V_92 ) ) ;
}
int F_24 ( struct V_1 * V_2 , T_2 V_95 , T_2 V_96 , T_3 V_97 )
{
struct V_7 V_8 = V_20 ;
struct V_10 V_11 ;
struct V_98 V_99 ;
if ( ( V_95 != V_100 ) &&
( V_95 != V_101 ) )
return - V_102 ;
V_11 . V_14 = V_103 ;
V_11 . V_6 = 0 ;
V_99 . V_95 = F_25 ( V_95 ) ;
V_99 . V_96 = F_25 ( V_96 ) ;
V_99 . V_97 = F_12 ( V_97 ) ;
return F_6 ( V_2 , & V_8 , & V_11 , & V_99 ,
sizeof( struct V_98 ) ) ;
}
int F_26 ( struct V_1 * V_2 , T_2 V_96 ,
void * V_16 , T_2 V_17 )
{
struct V_7 V_8 = V_20 ;
struct V_10 V_11 ;
struct V_104 * V_105 ;
T_1 * V_99 ;
int V_21 ;
V_99 = F_16 ( V_17 +
sizeof( struct V_104 ) , V_68 ) ;
if ( ! V_99 ) {
F_5 ( V_2 , L_7 ) ;
return - V_69 ;
}
V_105 = (struct V_104 * ) V_99 ;
V_11 . V_14 = V_106 ;
V_11 . V_6 = 0 ;
V_105 -> V_95 = F_25 ( V_107 ) ;
V_105 -> V_96 = F_25 ( V_96 ) ;
V_105 -> V_108 = F_25 ( V_17 ) ;
memcpy ( V_99 + sizeof( struct V_104 ) ,
V_16 , V_17 ) ;
V_21 = F_6 ( V_2 , & V_8 , & V_11 , V_99 ,
sizeof( struct V_104 ) +
V_17 ) ;
F_18 ( V_99 ) ;
return V_21 ;
}
int F_27 ( struct V_1 * V_2 , T_4 V_91 )
{
int V_21 ;
V_21 = F_24 ( V_2 , V_100 ,
V_109 , V_2 -> V_40 . V_110 ) ;
if ( V_21 < 0 )
return V_21 ;
V_21 = F_24 ( V_2 , V_101 ,
V_111 ,
V_2 -> V_40 . V_112 ) ;
if ( V_21 < 0 )
return V_21 ;
V_21 = F_24 ( V_2 , V_100 ,
V_113 ,
V_2 -> V_40 . V_114 ) ;
if ( V_21 < 0 )
return V_21 ;
V_21 = F_24 ( V_2 , V_100 ,
V_115 , V_2 -> V_40 . V_116 ) ;
if ( V_21 < 0 )
return V_21 ;
V_21 = F_24 ( V_2 , V_100 ,
V_117 ,
V_2 -> V_40 . V_118 ) ;
if ( V_21 < 0 )
return V_21 ;
V_21 = F_24 ( V_2 , V_100 ,
V_119 , V_37 ) ;
if ( V_21 < 0 )
return V_21 ;
V_21 = F_26 ( V_2 , V_120 ,
F_28 ( V_2 ) -> V_121 , V_122 ) ;
if ( V_21 < 0 )
return V_21 ;
V_21 = F_24 ( V_2 , V_100 ,
V_123 , 0x12C ) ;
if ( V_21 < 0 )
return V_21 ;
V_21 = F_24 ( V_2 , V_100 ,
V_124 , 0x15E ) ;
if ( V_21 < 0 )
return V_21 ;
V_21 = F_24 ( V_2 , V_100 ,
V_125 , 0x1 ) ;
if ( V_21 < 0 )
return V_21 ;
V_21 = F_24 ( V_2 , V_100 ,
V_126 , 0x80 ) ;
if ( V_21 < 0 )
return V_21 ;
V_21 = F_23 ( V_2 , V_91 , 1 ) ;
if ( V_21 < 0 )
return V_21 ;
V_21 = F_29 ( V_2 , V_94 , V_127 ,
V_128 ) ;
if ( V_21 ) {
F_5 ( V_2 , L_8 ) ;
return V_21 ;
}
return V_21 ;
}
int F_30 ( struct V_1 * V_2 , struct V_129 * V_130 , int V_131 )
{
struct V_7 V_8 ;
struct V_10 V_11 ;
struct V_132 * V_133 = F_31 ( V_130 ) ;
V_8 . V_134 = 1 ;
V_8 . V_135 = V_131 ;
V_8 . V_136 = V_133 -> V_137 << 4 | V_133 -> V_138 ;
V_8 . V_139 = 0 ;
V_11 . V_14 = V_140 ;
V_11 . V_141 = V_133 -> V_141 ;
V_11 . V_6 = 0 ;
return F_6 ( V_2 , & V_8 , & V_11 ,
V_130 -> V_142 , V_130 -> V_108 ) ;
}
static int F_32 ( struct V_1 * V_2 , T_4 V_143 ,
T_1 * V_144 , T_3 V_145 )
{
struct V_146 V_147 ;
struct V_148 * V_87 ;
T_2 V_149 ;
int V_21 = 0 ;
V_147 . V_74 = V_150 ;
V_147 . V_151 = V_143 ;
V_147 . V_152 = F_12 ( V_145 ) ;
V_147 . V_153 = 0 ;
V_147 . V_154 = 0 ;
V_147 . V_6 = 1 ;
V_147 . V_134 = 1 ;
V_21 = F_33 ( V_2 , & V_147 , NULL ) ;
if ( V_21 < 0 ) {
F_5 ( V_2 , L_9 ) ;
return V_21 ;
}
V_149 = V_21 ;
V_21 = F_7 ( V_2 -> V_155 ,
( V_87 = F_34 ( V_2 , V_149 ,
V_150 ) ) != NULL ,
2 * V_29 ) ;
if ( ! V_21 ) {
F_5 ( V_2 , L_10 ) ;
return V_21 ;
}
memcpy ( V_144 , V_87 -> V_72 . V_19 + sizeof( struct V_156 ) ,
V_145 ) ;
F_18 ( V_87 ) ;
return 0 ;
}
int F_35 ( struct V_1 * V_2 , T_1 * V_157 )
{
int V_21 ;
T_1 V_158 [ F_36 ( V_122 , 8 ) ] ;
V_21 = F_32 ( V_2 , F_12 ( V_159 ) ,
V_158 , sizeof( V_158 ) ) ;
if ( V_21 )
return V_21 ;
if ( F_37 ( V_158 ) )
memcpy ( V_157 , V_158 , V_122 ) ;
else {
F_5 ( V_2 , L_11 ) ;
memcpy ( V_157 , V_2 -> V_40 . V_160 , V_122 ) ;
F_38 ( & V_157 [ 3 ] , 3 ) ;
}
return 0 ;
}
static int F_39 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_161 )
return - V_25 ;
if ( V_2 -> V_162 -> V_163 . V_164 != V_165 &&
V_2 -> V_162 -> V_163 . V_164 != V_166 &&
V_2 -> V_162 -> V_163 . V_164 != V_167 &&
V_2 -> V_162 -> V_163 . V_164 != V_168 ) {
F_5 ( V_2 , L_12 ,
V_2 -> V_162 -> V_163 . V_164 ) ;
return - V_25 ;
}
if ( V_2 -> V_162 -> V_163 . V_169 != V_165 &&
V_2 -> V_162 -> V_163 . V_169 != V_166 &&
V_2 -> V_162 -> V_163 . V_169 != V_167 &&
V_2 -> V_162 -> V_163 . V_169 != V_168 ) {
F_5 ( V_2 , L_13 ,
V_2 -> V_162 -> V_163 . V_169 ) ;
return - V_25 ;
}
if ( ( V_2 -> V_162 -> V_163 . V_164 == V_165 ||
V_2 -> V_162 -> V_163 . V_164 == V_166 ) &&
( V_2 -> V_162 -> V_163 . V_164 !=
V_2 -> V_162 -> V_163 . V_169 ) ) {
F_5 ( V_2 , L_14 ) ;
}
return 0 ;
}
int F_40 ( struct V_1 * V_2 , T_1 V_170 )
{
struct V_171 V_172 ;
int V_21 ;
V_21 = F_39 ( V_2 ) ;
if ( V_21 < 0 )
return V_21 ;
if ( ( V_2 -> V_162 -> V_163 . V_164 != V_165 &&
V_2 -> V_162 -> V_163 . V_164 != V_166 ) ||
V_2 -> V_162 -> V_163 . V_173 == V_174 ||
V_2 -> V_162 -> V_163 . V_173 == V_175 )
return 0 ;
V_172 . V_19 . V_22 = V_176 ;
V_172 . V_19 . V_177 = F_25 ( sizeof( struct V_171 ) -
sizeof( struct V_18 ) ) ;
V_172 . V_170 = V_170 ;
return F_3 ( V_2 , & V_172 , sizeof( V_172 ) , 1 ) ;
}
int F_41 ( struct V_1 * V_2 , bool remove , struct V_178 * V_96 )
{
int V_21 = 0 ;
T_1 V_87 [ 64 ] , * V_179 , * V_180 , V_181 ;
T_5 V_170 ;
T_2 V_182 = 0 ;
struct V_183 * V_184 = & V_96 -> V_19 ;
struct V_185 * V_186 = (struct V_185 * ) V_87 ;
struct V_187 * V_188 = (struct V_187 * ) V_87 ;
struct V_189 * V_190 = (struct V_189 * ) V_87 ;
struct V_191 * V_192 = (struct V_191 * ) V_87 ;
if ( ! remove ) {
V_21 = F_39 ( V_2 ) ;
if ( V_21 < 0 )
return V_21 ;
}
V_179 = V_96 -> V_19 . V_157 ;
V_180 = V_96 -> V_96 ;
V_181 = V_96 -> V_181 ;
V_170 = V_96 -> V_19 . V_170 ;
if ( ! remove ) {
T_1 V_173 = V_2 -> V_162 -> V_163 . V_173 ;
F_42 ( V_2 , V_83 , L_15 , V_170 ) ;
F_42 ( V_2 , V_83 , L_16 , V_181 ) ;
F_42 ( V_2 , V_83 , L_17 ,
V_184 -> V_157 , V_184 -> V_170 , V_184 -> V_193 ) ;
F_42 ( V_2 , V_83 , L_18 ,
V_2 -> V_162 -> V_163 . V_169 ,
V_2 -> V_162 -> V_163 . V_164 ) ;
F_42 ( V_2 , V_83 , L_19 ,
V_2 -> V_162 -> V_163 . V_173 ,
V_2 -> V_162 -> V_163 . V_35 ) ;
switch ( V_96 -> V_194 ) {
case V_195 :
V_186 -> V_19 . V_22 = V_196 ;
V_186 -> V_19 . V_177 =
F_25 ( sizeof( struct V_185 ) -
sizeof( struct V_18 ) ) ;
memcpy ( & V_186 -> V_184 , V_184 ,
sizeof( struct V_183 ) ) ;
memcpy ( V_186 -> V_96 , V_180 , V_181 ) ;
V_186 -> V_197 =
! ! ( ( V_173 != V_174 ) &&
( V_173 != V_175 ) ) ;
V_182 = sizeof( struct V_185 ) ;
break;
case V_198 :
V_188 -> V_19 . V_22 = V_199 ;
V_188 -> V_19 . V_177 =
F_25 ( sizeof( struct V_187 ) -
sizeof( struct V_18 ) ) ;
memcpy ( & V_188 -> V_184 , V_184 ,
sizeof( struct V_183 ) ) ;
memcpy ( V_188 -> V_96 , V_180 , V_181 ) ;
V_188 -> V_197 =
! ! ( ( V_173 != V_174 ) &&
( V_173 != V_175 ) ) ;
V_182 = sizeof( struct V_187 ) ;
break;
case V_200 :
V_184 -> V_170 ++ ;
V_192 -> V_19 . V_22 = V_201 ;
V_192 -> V_19 . V_177 =
F_25 ( sizeof( struct V_191 ) -
sizeof( struct V_18 ) ) ;
memcpy ( & V_192 -> V_184 , V_184 ,
sizeof( struct V_183 ) ) ;
memcpy ( V_192 -> V_96 , V_180 , V_181 ) ;
if ( V_96 -> V_202 )
memcpy ( V_192 -> V_203 , V_96 -> V_204 , V_96 -> V_202 ) ;
V_182 = sizeof( struct V_191 ) ;
break;
case V_205 :
V_184 -> V_170 ++ ;
V_190 -> V_19 . V_22 = V_206 ;
V_190 -> V_19 . V_177 =
F_25 ( sizeof( struct V_189 ) -
sizeof( struct V_18 ) ) ;
memcpy ( & V_190 -> V_184 , V_184 ,
sizeof( struct V_183 ) ) ;
memcpy ( V_190 -> V_207 , V_180 , V_208 ) ;
memcpy ( V_190 -> V_209 , V_180 + V_208 ,
V_210 ) ;
memcpy ( V_190 -> V_211 ,
V_180 + V_208 + V_210 ,
V_210 ) ;
if ( V_96 -> V_202 )
memcpy ( V_192 -> V_203 , V_96 -> V_204 , V_96 -> V_202 ) ;
V_182 = sizeof( struct V_189 ) ;
break;
default:
return - V_212 ;
}
if ( ( V_96 -> V_194 == V_205 ) ||
( V_96 -> V_194 == V_200 ) )
F_43 ( F_44 ( 300 ) ) ;
V_21 = F_3 ( V_2 , V_87 , V_182 , 1 ) ;
} else {
struct V_213 V_214 ;
F_42 ( V_2 , V_215 , L_20 , V_170 ) ;
V_214 . V_19 . V_22 = V_216 ;
V_214 . V_19 . V_177 =
F_25 ( sizeof( struct V_213 ) -
sizeof( struct V_18 ) ) ;
memcpy ( & V_214 . V_184 , V_184 ,
sizeof( struct V_183 ) ) ;
V_21 = F_3 ( V_2 , & V_214 ,
sizeof( struct V_213 ) ,
1 ) ;
if ( V_21 )
return V_21 ;
V_2 -> V_217 [ V_170 ] . V_181 = 0 ;
}
return V_21 ;
}
int F_45 ( struct V_1 * V_2 )
{
int V_21 ;
struct V_218 V_219 ;
memcpy ( & V_219 , V_2 -> V_162 , sizeof( V_219 ) ) ;
V_219 . V_19 . V_22 = V_220 ;
V_219 . V_19 . V_177 = F_25 ( sizeof( struct V_218 ) -
sizeof( struct V_18 ) ) ;
V_21 = F_3 ( V_2 , & V_219 , sizeof( V_219 ) , 1 ) ;
if ( V_21 ) {
F_5 ( V_2 , L_21 ) ;
return V_21 ;
}
F_46 ( V_221 , & V_2 -> V_24 ) ;
return 0 ;
}
int F_47 ( struct V_1 * V_2 )
{
struct V_222 V_223 ;
V_223 . V_19 . V_22 = V_224 ;
V_223 . V_19 . V_177 =
F_25 ( sizeof( struct V_222 ) -
sizeof( struct V_18 ) ) ;
V_223 . V_225 = V_226 ;
return F_3 ( V_2 , & V_223 , sizeof( V_223 ) , 1 ) ;
}
int F_48 ( struct V_1 * V_2 )
{
int V_21 ;
V_21 = F_47 ( V_2 ) ;
if ( V_21 )
return V_21 ;
V_21 = F_7 ( V_2 -> V_227 ,
( V_2 -> V_161 == 0 ) , 5 * V_29 ) ;
return V_21 ? 0 : - V_30 ;
}
int F_49 ( struct V_1 * V_2 )
{
struct V_228 V_229 ;
V_229 . V_19 . V_22 = V_230 ;
V_229 . V_19 . V_177 =
F_25 ( sizeof( struct V_228 ) -
sizeof( struct V_18 ) ) ;
return F_3 ( V_2 , & V_229 , sizeof( V_229 ) , 1 ) ;
}
int F_50 ( struct V_1 * V_2 , T_3 V_35 )
{
struct V_7 V_8 = V_20 ;
struct V_10 V_11 ;
struct V_231 V_232 ;
V_232 . V_35 = F_12 ( V_35 ) ;
V_11 . V_14 = V_233 ;
V_11 . V_6 = 0 ;
return F_6 ( V_2 , & V_8 , & V_11 , & V_232 ,
sizeof( struct V_231 ) ) ;
}
int F_51 ( struct V_1 * V_2 )
{
struct V_7 V_8 = V_20 ;
struct V_10 V_11 ;
struct V_234 * V_235 ;
int V_73 = sizeof( struct V_234 ) +
sizeof( struct V_236 ) * 4 ;
int V_21 ;
V_235 = F_16 ( V_73 , V_68 ) ;
if ( ! V_235 ) {
F_5 ( V_2 , L_22 ) ;
return - V_69 ;
}
V_235 -> V_237 [ 0 ] . V_238 = V_239 ;
V_235 -> V_237 [ 0 ] . type = V_240 ;
V_235 -> V_237 [ 0 ] . V_35 = V_241 ;
V_235 -> V_237 [ 1 ] . V_238 = V_242 ;
V_235 -> V_237 [ 1 ] . type = V_240 ;
V_235 -> V_237 [ 1 ] . V_35 = V_241 ;
V_235 -> V_237 [ 2 ] . V_238 = V_239 ;
V_235 -> V_237 [ 2 ] . type = V_240 ;
V_235 -> V_237 [ 2 ] . V_35 = V_241 | V_243 ;
V_235 -> V_237 [ 3 ] . V_238 = V_242 ;
V_235 -> V_237 [ 3 ] . type = V_240 ;
V_235 -> V_237 [ 3 ] . V_35 = V_241 | V_243 ;
V_235 -> V_244 = F_25 ( 4 ) ;
V_11 . V_14 = V_245 ;
V_11 . V_6 = 1 ;
V_21 = F_6 ( V_2 , & V_8 , & V_11 , V_235 , V_73 ) ;
F_18 ( V_235 ) ;
return V_21 ;
}
int F_52 ( struct V_1 * V_2 , struct V_246 * V_247 ,
int V_248 )
{
struct V_249 V_250 ;
int V_79 , V_21 ;
memset ( & V_250 , 0 , sizeof( struct V_249 ) ) ;
V_250 . V_19 . V_22 = V_251 ;
V_250 . V_19 . V_177 = F_25 ( sizeof( struct V_249 )
- sizeof( struct V_18 ) ) ;
V_250 . type = V_252 ;
V_250 . V_253 = 2 ;
V_250 . V_149 = V_2 -> V_254 ;
V_250 . V_248 = F_53 ( V_248 , V_255 ) ;
for ( V_79 = 0 ; V_79 < V_250 . V_248 ; V_79 ++ ) {
memcpy ( V_250 . V_247 [ V_79 ] . V_256 , V_247 [ V_79 ] . V_256 , V_247 [ V_79 ] . V_257 ) ;
V_250 . V_247 [ V_79 ] . V_257 = V_247 [ V_79 ] . V_257 ;
}
V_21 = F_3 ( V_2 , & V_250 , sizeof( V_250 ) , 0 ) ;
if ( V_21 ) {
F_5 ( V_2 , L_23 ) ;
return V_21 ;
}
V_2 -> V_254 = ( V_2 -> V_254 + 1 ) % V_258 ;
return 0 ;
}
int F_54 ( struct V_1 * V_2 , T_1 * V_256 , int V_257 )
{
struct V_246 V_259 ;
if ( F_55 ( V_260 , & V_2 -> V_24 ) )
return 0 ;
V_259 . V_257 = F_53 ( V_257 , V_261 ) ;
memcpy ( & V_259 . V_256 , V_256 , V_259 . V_257 ) ;
return F_52 ( V_2 , & V_259 , 1 ) ;
}
int F_56 ( struct V_1 * V_2 )
{
struct V_146 V_147 ;
V_147 . V_74 = V_262 ;
V_147 . V_151 = 0 ;
V_147 . V_152 = 0 ;
V_147 . V_153 = 0 ;
V_147 . V_154 = 0 ;
V_147 . V_6 = 0 ;
V_147 . V_134 = 1 ;
return F_33 ( V_2 , & V_147 , NULL ) ;
}
int F_57 ( struct V_1 * V_2 ,
struct V_263 * V_264 )
{
struct V_7 V_8 = V_20 ;
struct V_10 V_11 ;
struct V_265 V_266 ;
struct V_267 * V_268 ;
T_1 V_269 = F_58 ( V_264 -> V_269 ) ;
int V_79 ;
V_268 = & V_2 -> V_270 [ V_269 ] ;
if ( ! V_268 -> V_271 ) {
F_5 ( V_2 , L_24 , V_269 ) ;
return - V_102 ;
}
V_11 . V_14 = V_272 ;
V_11 . V_6 = 0 ;
V_266 . V_35 = V_264 -> V_35 ;
V_266 . V_269 = V_264 -> V_269 ;
V_266 . V_273 = V_264 -> V_273 ;
for ( V_79 = 0 ; V_79 < V_274 ; V_79 ++ )
V_266 . V_275 [ V_79 ] =
V_268 -> V_276 [ V_79 ] . V_275 ;
return F_6 ( V_2 , & V_8 , & V_11 , & V_266 ,
sizeof( struct V_265 ) ) ;
}
int F_59 ( struct V_1 * V_2 ,
struct V_277 * V_278 , T_3 V_279 )
{
struct V_280 V_281 ;
int V_21 ;
memset ( & V_281 , 0 , sizeof( struct V_280 ) ) ;
V_281 . V_19 . V_22 = V_282 ;
V_281 . V_19 . V_177 = F_25 ( sizeof( struct V_280 ) -
sizeof( struct V_18 ) ) ;
V_281 . V_279 = F_12 ( V_279 ) ;
if ( V_278 -> V_283 )
memcpy ( & V_281 . V_283 , V_278 -> V_283 , V_122 ) ;
if ( V_278 -> V_284 )
memcpy ( & V_281 . V_284 , V_278 -> V_284 , V_285 ) ;
V_21 = F_3 ( V_2 , & V_281 ,
sizeof( struct V_280 ) , 0 ) ;
if ( V_21 ) {
F_5 ( V_2 , L_25 ) ;
return V_21 ;
}
return 0 ;
}
