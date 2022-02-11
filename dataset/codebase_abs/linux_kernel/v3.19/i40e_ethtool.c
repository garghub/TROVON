static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_9 -> V_10 ;
struct V_11 * V_12 = & V_8 -> V_12 ;
struct V_13 * V_14 = & V_12 -> V_15 . V_16 ;
bool V_17 = V_14 -> V_16 & V_18 ;
T_1 V_19 = V_14 -> V_19 ;
if ( ! V_17 ) {
switch ( V_12 -> V_20 ) {
case V_21 :
case V_22 :
case V_23 :
V_4 -> V_24 = V_25 |
V_26 |
V_27 ;
V_4 -> V_28 = V_29 |
V_30 |
V_31 ;
break;
case V_32 :
V_4 -> V_24 = V_33 ;
V_4 -> V_28 = V_34 ;
break;
case V_35 :
V_4 -> V_24 = V_36 ;
V_4 -> V_28 = V_37 ;
break;
case V_38 :
V_4 -> V_24 = V_39 |
V_40 |
V_41 ;
V_4 -> V_28 = V_42 |
V_43 |
V_44 ;
break;
default:
V_4 -> V_24 = V_39 |
V_40 ;
V_4 -> V_28 = V_42 |
V_43 ;
break;
}
goto V_45;
}
switch ( V_14 -> V_46 ) {
case V_47 :
case V_48 :
V_4 -> V_24 = V_49 |
V_26 ;
V_4 -> V_28 = V_50 |
V_30 ;
break;
case V_51 :
V_4 -> V_24 = V_49 |
V_33 ;
V_4 -> V_28 = V_50 |
V_34 ;
break;
case V_52 :
case V_53 :
case V_54 :
V_4 -> V_24 = V_25 ;
break;
case V_55 :
V_4 -> V_24 = V_27 ;
break;
case V_56 :
V_4 -> V_24 = V_49 |
V_57 ;
V_4 -> V_28 = V_50 |
V_58 ;
break;
case V_59 :
V_4 -> V_24 = V_49 |
V_36 ;
V_4 -> V_28 = V_50 |
V_37 ;
break;
case V_60 :
case V_61 :
case V_62 :
case V_63 :
V_4 -> V_24 = V_39 ;
V_4 -> V_24 |= V_40 ;
break;
case V_64 :
case V_65 :
case V_66 :
V_4 -> V_24 = V_49 |
V_39 |
V_40 |
V_41 ;
V_4 -> V_28 = V_50 |
V_42 |
V_43 |
V_44 ;
break;
case V_67 :
case V_68 :
case V_69 :
case V_70 :
V_4 -> V_24 = V_39 ;
break;
case V_71 :
case V_72 :
V_4 -> V_24 = V_49 |
V_39 |
V_40 |
V_41 ;
V_4 -> V_28 = V_50 |
V_42 |
V_43 |
V_44 ;
break;
case V_73 :
V_4 -> V_24 = V_49 |
V_39 |
V_40 |
V_41 ;
V_4 -> V_28 = V_50 |
V_42 |
V_43 |
V_44 ;
break;
case V_74 :
V_4 -> V_24 = V_49 |
V_40 |
V_41 ;
V_4 -> V_28 = V_50 |
V_43 |
V_44 ;
break;
default:
F_3 ( V_2 , L_1 ,
V_14 -> V_46 ) ;
}
V_45:
V_4 -> V_75 = ( ( V_14 -> V_76 & V_77 ) ?
V_78 : V_79 ) ;
switch ( V_12 -> V_15 . V_80 ) {
case V_81 :
V_4 -> V_24 |= V_49 |
V_82 ;
V_4 -> V_28 |= V_50 |
V_83 ;
V_4 -> V_84 = V_85 ;
break;
case V_86 :
V_4 -> V_24 |= V_87 ;
V_4 -> V_28 |= V_88 ;
V_4 -> V_84 = V_89 ;
break;
case V_90 :
case V_91 :
V_4 -> V_24 |= V_92 ;
V_4 -> V_28 |= V_93 ;
V_4 -> V_84 = V_94 ;
break;
case V_95 :
V_4 -> V_24 |= V_92 ;
V_4 -> V_84 = V_96 ;
break;
case V_97 :
default:
V_4 -> V_84 = V_98 ;
break;
}
V_4 -> V_99 = V_100 ;
V_4 -> V_24 |= V_101 ;
switch ( V_12 -> V_102 . V_103 ) {
case V_104 :
V_4 -> V_28 |= V_105 ;
break;
case V_106 :
V_4 -> V_28 |= V_107 ;
break;
case V_108 :
V_4 -> V_28 |= ( V_105 |
V_107 ) ;
break;
default:
V_4 -> V_28 &= ~ ( V_105 |
V_107 ) ;
break;
}
if ( V_17 ) {
switch ( V_19 ) {
case V_109 :
F_4 ( V_4 , 40000 ) ;
break;
case V_110 :
F_4 ( V_4 , V_111 ) ;
break;
case V_112 :
F_4 ( V_4 , V_113 ) ;
break;
case V_114 :
F_4 ( V_4 , V_115 ) ;
break;
default:
break;
}
V_4 -> V_116 = V_117 ;
} else {
F_4 ( V_4 , V_118 ) ;
V_4 -> V_116 = V_119 ;
}
return 0 ;
}
static int F_5 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_120 V_121 ;
struct V_122 V_123 ;
struct V_7 * V_8 = V_6 -> V_9 -> V_10 ;
struct V_124 * V_9 = V_6 -> V_9 ;
struct V_11 * V_12 = & V_8 -> V_12 ;
struct V_3 V_125 ;
T_2 V_126 = 0 ;
bool V_127 = false ;
int V_128 = 0 ;
T_3 V_75 ;
T_1 V_129 ;
if ( V_9 != V_8 -> V_9 [ V_8 -> V_130 ] )
return - V_131 ;
if ( V_12 -> V_15 . V_80 != V_86 &&
V_12 -> V_15 . V_80 != V_95 &&
V_12 -> V_15 . V_80 != V_81 &&
V_12 -> V_15 . V_16 . V_16 & V_18 )
return - V_131 ;
memset ( & V_125 , 0 , sizeof( struct V_3 ) ) ;
F_1 ( V_2 , & V_125 ) ;
V_75 = V_4 -> V_75 ;
V_129 = V_4 -> V_28 ;
V_4 -> V_75 = V_125 . V_75 ;
V_4 -> V_28 = V_125 . V_28 ;
V_4 -> V_132 = V_125 . V_132 ;
if ( memcmp ( V_4 , & V_125 , sizeof( struct V_3 ) ) )
return - V_131 ;
while ( F_6 ( V_133 , & V_9 -> V_134 ) )
F_7 ( 1000 , 2000 ) ;
V_126 = F_8 ( V_12 , false , false , & V_121 ,
NULL ) ;
if ( V_126 )
return - V_135 ;
memset ( & V_123 , 0 , sizeof( struct V_122 ) ) ;
V_123 . V_121 = V_121 . V_121 ;
if ( V_75 == V_78 ) {
if ( ! ( V_125 . V_24 & V_49 ) ) {
F_3 ( V_2 , L_2 ) ;
return - V_136 ;
}
if ( ! ( V_12 -> V_15 . V_16 . V_76 & V_77 ) ) {
V_123 . V_121 = V_121 . V_121 |
V_137 ;
V_127 = true ;
}
} else {
if ( V_125 . V_24 & V_49 &&
V_12 -> V_15 . V_16 . V_46 != V_66 ) {
F_3 ( V_2 , L_3 ) ;
return - V_136 ;
}
if ( V_12 -> V_15 . V_16 . V_76 & V_77 ) {
V_123 . V_121 = V_121 . V_121 &
~ V_137 ;
V_127 = true ;
}
}
if ( V_129 & ~ V_125 . V_24 )
return - V_136 ;
if ( V_129 & V_44 )
V_123 . V_19 |= V_114 ;
if ( V_129 & V_43 ||
V_129 & V_138 )
V_123 . V_19 |= V_112 ;
if ( V_129 & V_42 ||
V_129 & V_58 ||
V_129 & V_37 )
V_123 . V_19 |= V_110 ;
if ( V_129 & V_34 ||
V_129 & V_30 ||
V_129 & V_29 ||
V_129 & V_31 )
V_123 . V_19 |= V_109 ;
if ( V_127 || ( V_121 . V_19 != V_123 . V_19 ) ) {
V_123 . V_46 = V_121 . V_46 ;
V_123 . V_139 = V_121 . V_139 ;
V_123 . V_140 = V_121 . V_141 ;
V_123 . V_142 = V_121 . V_143 ;
V_123 . V_121 |= V_144 ;
if ( V_12 -> V_15 . V_16 . V_16 & V_18 ) {
F_3 ( V_2 , L_4 ) ;
F_9 ( V_2 ) ;
F_10 ( V_2 ) ;
}
V_126 = V_122 ( V_12 , & V_123 , NULL ) ;
if ( V_126 ) {
F_3 ( V_2 , L_5 ,
V_126 ) ;
return - V_135 ;
}
V_126 = F_11 ( V_12 , true ) ;
if ( V_126 )
F_3 ( V_2 , L_6 ,
V_126 ) ;
} else {
F_3 ( V_2 , L_7 ) ;
}
return V_128 ;
}
static int F_12 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_9 -> V_10 ;
struct V_11 * V_12 = & V_8 -> V_12 ;
bool V_17 = V_12 -> V_15 . V_16 . V_16 & V_18 ;
T_2 V_145 = 0 ;
V_145 = F_13 ( V_12 , V_17 , NULL ) ;
if ( V_145 ) {
F_3 ( V_2 , L_8 ,
V_8 -> V_12 . V_146 . V_147 ) ;
return - V_148 ;
}
return 0 ;
}
static void F_14 ( struct V_1 * V_2 ,
struct V_149 * V_150 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_9 -> V_10 ;
struct V_11 * V_12 = & V_8 -> V_12 ;
struct V_13 * V_14 = & V_12 -> V_15 . V_16 ;
struct V_151 * V_152 = & V_12 -> V_153 ;
V_150 -> V_75 =
( ( V_14 -> V_76 & V_77 ) ?
V_78 : V_79 ) ;
if ( V_152 -> V_154 . V_155 ) {
V_150 -> V_156 = 0 ;
V_150 -> V_157 = 0 ;
return;
}
if ( V_12 -> V_102 . V_103 == V_108 ) {
V_150 -> V_156 = 1 ;
} else if ( V_12 -> V_102 . V_103 == V_106 ) {
V_150 -> V_157 = 1 ;
} else if ( V_12 -> V_102 . V_103 == V_104 ) {
V_150 -> V_156 = 1 ;
V_150 -> V_157 = 1 ;
}
}
static int F_15 ( struct V_1 * V_2 ,
struct V_149 * V_150 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_9 -> V_10 ;
struct V_124 * V_9 = V_6 -> V_9 ;
struct V_11 * V_12 = & V_8 -> V_12 ;
struct V_13 * V_14 = & V_12 -> V_15 . V_16 ;
struct V_151 * V_152 = & V_12 -> V_153 ;
bool V_17 = V_14 -> V_16 & V_18 ;
T_2 V_126 ;
T_3 V_158 ;
int V_128 = 0 ;
if ( V_9 != V_8 -> V_9 [ V_8 -> V_130 ] )
return - V_131 ;
if ( V_150 -> V_75 != ( ( V_14 -> V_76 & V_77 ) ?
V_78 : V_79 ) ) {
F_3 ( V_2 , L_9 ) ;
return - V_131 ;
}
if ( ! F_6 ( V_159 , & V_8 -> V_134 ) &&
! ( V_14 -> V_76 & V_77 ) ) {
F_3 ( V_2 , L_10 ) ;
}
if ( V_152 -> V_154 . V_155 ) {
F_3 ( V_2 ,
L_11 ) ;
return - V_131 ;
}
if ( V_150 -> V_156 && V_150 -> V_157 )
V_12 -> V_102 . V_160 = V_104 ;
else if ( V_150 -> V_156 && ! V_150 -> V_157 )
V_12 -> V_102 . V_160 = V_108 ;
else if ( ! V_150 -> V_156 && V_150 -> V_157 )
V_12 -> V_102 . V_160 = V_106 ;
else if ( ! V_150 -> V_156 && ! V_150 -> V_157 )
V_12 -> V_102 . V_160 = V_161 ;
else
return - V_136 ;
F_3 ( V_2 , L_12 ) ;
F_9 ( V_2 ) ;
F_10 ( V_2 ) ;
V_126 = F_16 ( V_12 , & V_158 , V_17 ) ;
if ( V_158 & V_162 ) {
F_3 ( V_2 , L_13 ,
V_126 , V_12 -> V_146 . V_147 ) ;
V_128 = - V_135 ;
}
if ( V_158 & V_163 ) {
F_3 ( V_2 , L_14 ,
V_126 , V_12 -> V_146 . V_147 ) ;
V_128 = - V_135 ;
}
if ( V_158 & V_164 ) {
F_3 ( V_2 , L_15 ,
V_126 , V_12 -> V_146 . V_147 ) ;
V_128 = - V_135 ;
}
if ( ! F_6 ( V_159 , & V_8 -> V_134 ) ) {
F_17 ( 75 ) ;
if ( ! F_6 ( V_159 , & V_8 -> V_134 ) )
return F_12 ( V_2 ) ;
}
return V_128 ;
}
static T_1 F_18 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_9 -> V_10 ;
return V_8 -> V_165 ;
}
static void F_19 ( struct V_1 * V_2 , T_1 V_166 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_9 -> V_10 ;
if ( V_167 & V_166 )
V_8 -> V_12 . V_168 = V_166 ;
V_8 -> V_165 = V_166 ;
}
static int F_20 ( struct V_1 * V_2 )
{
int V_169 = 0 ;
int V_170 ;
for ( V_170 = 0 ; V_171 [ V_170 ] . V_172 != 0 ; V_170 ++ )
V_169 += V_171 [ V_170 ] . V_173 ;
return V_169 * sizeof( T_1 ) ;
}
static void F_21 ( struct V_1 * V_2 , struct V_174 * V_175 ,
void * V_176 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_9 -> V_10 ;
struct V_11 * V_12 = & V_8 -> V_12 ;
T_1 * V_177 = V_176 ;
int V_170 , V_178 , V_179 ;
T_1 V_180 ;
V_175 -> V_181 = 1 ;
V_179 = 0 ;
for ( V_170 = 0 ; V_171 [ V_170 ] . V_172 != 0 ; V_170 ++ ) {
for ( V_178 = 0 ; V_178 < V_171 [ V_170 ] . V_173 ; V_178 ++ ) {
V_180 = V_171 [ V_170 ] . V_172
+ ( V_178 * V_171 [ V_170 ] . V_182 ) ;
V_177 [ V_179 ++ ] = F_22 ( V_12 , V_180 ) ;
}
}
}
static int F_23 ( struct V_1 * V_2 ,
struct V_183 * V_184 , T_3 * V_185 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_11 * V_12 = & V_6 -> V_9 -> V_10 -> V_12 ;
struct V_7 * V_8 = V_6 -> V_9 -> V_10 ;
int V_186 = 0 , V_187 , V_172 ;
T_3 * V_188 ;
T_4 V_170 , V_189 ;
bool V_190 ;
T_1 V_191 ;
#define F_24 4096
if ( V_184 -> V_187 == 0 )
return - V_136 ;
V_191 = V_12 -> V_192 | ( V_12 -> V_20 << 16 ) ;
if ( V_184 -> V_191 && V_184 -> V_191 != V_191 ) {
struct V_193 * V_132 ;
int V_194 ;
if ( ( V_184 -> V_191 >> 16 ) != V_12 -> V_20 )
return - V_136 ;
V_132 = (struct V_193 * ) V_184 ;
V_186 = F_25 ( V_12 , V_132 , V_185 , & V_194 ) ;
if ( V_186 )
F_26 ( & V_8 -> V_195 -> V_196 ,
L_16 ,
V_186 , V_12 -> V_146 . V_147 , V_194 ,
( T_3 ) ( V_132 -> V_123 & V_197 ) ,
V_132 -> V_172 , V_132 -> V_198 ) ;
return V_194 ;
}
V_184 -> V_191 = V_12 -> V_192 | ( V_12 -> V_20 << 16 ) ;
V_188 = F_27 ( V_184 -> V_187 , V_199 ) ;
if ( ! V_188 )
return - V_200 ;
V_186 = F_28 ( V_12 , V_201 ) ;
if ( V_186 ) {
F_26 ( & V_8 -> V_195 -> V_196 ,
L_17 ,
V_186 , V_12 -> V_146 . V_147 ) ;
goto V_202;
}
V_189 = V_184 -> V_187 / F_24 ;
V_189 += ( V_184 -> V_187 % F_24 ) ? 1 : 0 ;
V_187 = F_24 ;
V_190 = false ;
for ( V_170 = 0 ; V_170 < V_189 ; V_170 ++ ) {
if ( V_170 == ( V_189 - 1 ) ) {
V_187 = V_184 -> V_187 - ( F_24 * V_170 ) ;
V_190 = true ;
}
V_172 = V_184 -> V_172 + ( F_24 * V_170 ) ,
V_186 = F_29 ( V_12 , 0x0 , V_172 , V_187 ,
( T_3 * ) V_188 + ( F_24 * V_170 ) ,
V_190 , NULL ) ;
if ( V_186 && V_12 -> V_146 . V_147 == V_203 ) {
F_26 ( & V_8 -> V_195 -> V_196 ,
L_18 ,
V_172 ) ;
break;
} else if ( V_186 &&
V_12 -> V_146 . V_147 == V_204 ) {
F_26 ( & V_8 -> V_195 -> V_196 ,
L_19 ,
V_172 ) ;
break;
} else if ( V_186 ) {
F_26 ( & V_8 -> V_195 -> V_196 ,
L_20 ,
V_172 , V_186 , V_12 -> V_146 . V_147 ) ;
break;
}
}
F_30 ( V_12 ) ;
memcpy ( V_185 , ( T_3 * ) V_188 , V_184 -> V_187 ) ;
V_202:
F_31 ( V_188 ) ;
return V_186 ;
}
static int F_32 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_11 * V_12 = & V_6 -> V_9 -> V_10 -> V_12 ;
T_1 V_205 ;
V_205 = ( F_22 ( V_12 , V_206 )
& V_207 )
>> V_208 ;
V_205 = ( 64 * 1024 ) * ( 1 << V_205 ) ;
return V_205 ;
}
static int F_33 ( struct V_1 * V_2 ,
struct V_183 * V_184 , T_3 * V_185 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_11 * V_12 = & V_6 -> V_9 -> V_10 -> V_12 ;
struct V_7 * V_8 = V_6 -> V_9 -> V_10 ;
struct V_193 * V_132 ;
int V_186 = 0 ;
int V_194 ;
T_1 V_191 ;
V_191 = V_12 -> V_192 | ( V_12 -> V_20 << 16 ) ;
if ( V_184 -> V_191 == V_191 )
return - V_131 ;
if ( ! V_184 -> V_191 || ( V_184 -> V_191 >> 16 ) != V_12 -> V_20 )
return - V_136 ;
if ( F_6 ( V_209 , & V_8 -> V_134 ) ||
F_6 ( V_210 , & V_8 -> V_134 ) )
return - V_211 ;
V_132 = (struct V_193 * ) V_184 ;
V_186 = F_25 ( V_12 , V_132 , V_185 , & V_194 ) ;
if ( V_186 && V_12 -> V_146 . V_147 != V_212 )
F_26 ( & V_8 -> V_195 -> V_196 ,
L_21 ,
V_186 , V_12 -> V_146 . V_147 , V_194 ,
( T_3 ) ( V_132 -> V_123 & V_197 ) ,
V_132 -> V_172 , V_132 -> V_198 ) ;
return V_194 ;
}
static void F_34 ( struct V_1 * V_2 ,
struct V_213 * V_214 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_124 * V_9 = V_6 -> V_9 ;
struct V_7 * V_8 = V_9 -> V_10 ;
F_35 ( V_214 -> V_215 , V_216 , sizeof( V_214 -> V_215 ) ) ;
F_35 ( V_214 -> V_181 , V_217 ,
sizeof( V_214 -> V_181 ) ) ;
F_35 ( V_214 -> V_218 , F_36 ( & V_8 -> V_12 ) ,
sizeof( V_214 -> V_218 ) ) ;
F_35 ( V_214 -> V_219 , F_37 ( V_8 -> V_195 ) ,
sizeof( V_214 -> V_219 ) ) ;
}
static void F_38 ( struct V_1 * V_2 ,
struct V_220 * V_221 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_9 -> V_10 ;
struct V_124 * V_9 = V_8 -> V_9 [ V_8 -> V_130 ] ;
V_221 -> V_222 = V_223 ;
V_221 -> V_224 = V_223 ;
V_221 -> V_225 = 0 ;
V_221 -> V_226 = 0 ;
V_221 -> V_227 = V_9 -> V_228 [ 0 ] -> V_229 ;
V_221 -> V_230 = V_9 -> V_231 [ 0 ] -> V_229 ;
V_221 -> V_232 = 0 ;
V_221 -> V_233 = 0 ;
}
static int F_39 ( struct V_1 * V_2 ,
struct V_220 * V_221 )
{
struct V_234 * V_231 = NULL , * V_228 = NULL ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_124 * V_9 = V_6 -> V_9 ;
struct V_7 * V_8 = V_9 -> V_10 ;
T_1 V_235 , V_236 ;
int V_170 , V_128 = 0 ;
if ( ( V_221 -> V_232 ) || ( V_221 -> V_233 ) )
return - V_136 ;
if ( V_221 -> V_230 > V_223 ||
V_221 -> V_230 < V_237 ||
V_221 -> V_227 > V_223 ||
V_221 -> V_227 < V_237 ) {
F_3 ( V_2 ,
L_22 ,
V_221 -> V_230 , V_221 -> V_227 ,
V_237 , V_223 ) ;
return - V_136 ;
}
V_236 = F_40 ( V_221 -> V_230 , V_238 ) ;
V_235 = F_40 ( V_221 -> V_227 , V_238 ) ;
if ( ( V_236 == V_9 -> V_231 [ 0 ] -> V_229 ) &&
( V_235 == V_9 -> V_228 [ 0 ] -> V_229 ) )
return 0 ;
while ( F_41 ( V_133 , & V_8 -> V_134 ) )
F_7 ( 1000 , 2000 ) ;
if ( ! F_42 ( V_9 -> V_2 ) ) {
for ( V_170 = 0 ; V_170 < V_9 -> V_239 ; V_170 ++ ) {
V_9 -> V_231 [ V_170 ] -> V_229 = V_236 ;
V_9 -> V_228 [ V_170 ] -> V_229 = V_235 ;
}
goto V_240;
}
if ( V_236 != V_9 -> V_231 [ 0 ] -> V_229 ) {
F_3 ( V_2 ,
L_23 ,
V_9 -> V_231 [ 0 ] -> V_229 , V_236 ) ;
V_231 = F_43 ( V_9 -> V_241 ,
sizeof( struct V_234 ) , V_199 ) ;
if ( ! V_231 ) {
V_128 = - V_200 ;
goto V_240;
}
for ( V_170 = 0 ; V_170 < V_9 -> V_239 ; V_170 ++ ) {
V_231 [ V_170 ] = * V_9 -> V_231 [ V_170 ] ;
V_231 [ V_170 ] . V_229 = V_236 ;
V_128 = F_44 ( & V_231 [ V_170 ] ) ;
if ( V_128 ) {
while ( V_170 ) {
V_170 -- ;
F_45 ( & V_231 [ V_170 ] ) ;
}
F_31 ( V_231 ) ;
V_231 = NULL ;
goto V_240;
}
}
}
if ( V_235 != V_9 -> V_228 [ 0 ] -> V_229 ) {
F_3 ( V_2 ,
L_24 ,
V_9 -> V_228 [ 0 ] -> V_229 , V_235 ) ;
V_228 = F_43 ( V_9 -> V_241 ,
sizeof( struct V_234 ) , V_199 ) ;
if ( ! V_228 ) {
V_128 = - V_200 ;
goto V_242;
}
for ( V_170 = 0 ; V_170 < V_9 -> V_239 ; V_170 ++ ) {
V_228 [ V_170 ] = * V_9 -> V_228 [ V_170 ] ;
V_228 [ V_170 ] . V_229 = V_235 ;
V_128 = F_46 ( & V_228 [ V_170 ] ) ;
if ( V_128 ) {
while ( V_170 ) {
V_170 -- ;
F_47 ( & V_228 [ V_170 ] ) ;
}
F_31 ( V_228 ) ;
V_228 = NULL ;
goto V_242;
}
}
}
F_48 ( V_9 ) ;
if ( V_231 ) {
for ( V_170 = 0 ; V_170 < V_9 -> V_239 ; V_170 ++ ) {
F_45 ( V_9 -> V_231 [ V_170 ] ) ;
* V_9 -> V_231 [ V_170 ] = V_231 [ V_170 ] ;
}
F_31 ( V_231 ) ;
V_231 = NULL ;
}
if ( V_228 ) {
for ( V_170 = 0 ; V_170 < V_9 -> V_239 ; V_170 ++ ) {
F_47 ( V_9 -> V_228 [ V_170 ] ) ;
* V_9 -> V_228 [ V_170 ] = V_228 [ V_170 ] ;
}
F_31 ( V_228 ) ;
V_228 = NULL ;
}
F_49 ( V_9 ) ;
V_242:
if ( V_231 ) {
for ( V_170 = 0 ; V_170 < V_9 -> V_239 ; V_170 ++ )
F_45 ( & V_231 [ V_170 ] ) ;
F_31 ( V_231 ) ;
V_231 = NULL ;
}
V_240:
F_50 ( V_133 , & V_8 -> V_134 ) ;
return V_128 ;
}
static int F_51 ( struct V_1 * V_2 , int V_243 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_124 * V_9 = V_6 -> V_9 ;
struct V_7 * V_8 = V_9 -> V_10 ;
switch ( V_243 ) {
case V_244 :
return V_245 ;
case V_246 :
if ( V_9 == V_8 -> V_9 [ V_8 -> V_130 ] ) {
int V_187 = F_52 ( V_2 ) ;
if ( V_8 -> V_247 != V_248 )
V_187 += V_249 ;
return V_187 ;
} else {
return F_53 ( V_2 ) ;
}
default:
return - V_131 ;
}
}
static void F_54 ( struct V_1 * V_2 ,
struct V_250 * V_251 , T_5 * V_166 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_234 * V_252 , * V_253 ;
struct V_124 * V_9 = V_6 -> V_9 ;
struct V_7 * V_8 = V_9 -> V_10 ;
int V_170 = 0 ;
char * V_176 ;
int V_178 ;
struct V_254 * V_255 = F_55 ( V_9 ) ;
unsigned int V_256 ;
F_56 ( V_9 ) ;
for ( V_178 = 0 ; V_178 < V_257 ; V_178 ++ ) {
V_176 = ( char * ) V_255 + V_258 [ V_178 ] . V_259 ;
V_166 [ V_170 ++ ] = ( V_258 [ V_178 ] . V_260 ==
sizeof( T_5 ) ) ? * ( T_5 * ) V_176 : * ( T_1 * ) V_176 ;
}
for ( V_178 = 0 ; V_178 < V_261 ; V_178 ++ ) {
V_176 = ( char * ) V_9 + V_262 [ V_178 ] . V_259 ;
V_166 [ V_170 ++ ] = ( V_262 [ V_178 ] . V_260 ==
sizeof( T_5 ) ) ? * ( T_5 * ) V_176 : * ( T_1 * ) V_176 ;
}
#ifdef F_57
for ( V_178 = 0 ; V_178 < V_263 ; V_178 ++ ) {
V_176 = ( char * ) V_9 + V_264 [ V_178 ] . V_259 ;
V_166 [ V_170 ++ ] = ( V_264 [ V_178 ] . V_260 ==
sizeof( T_5 ) ) ? * ( T_5 * ) V_176 : * ( T_1 * ) V_176 ;
}
#endif
F_58 () ;
for ( V_178 = 0 ; V_178 < V_9 -> V_239 ; V_178 ++ ) {
V_252 = F_59 ( V_9 -> V_231 [ V_178 ] ) ;
if ( ! V_252 )
continue;
do {
V_256 = F_60 ( & V_252 -> V_265 ) ;
V_166 [ V_170 ] = V_252 -> V_251 . V_266 ;
V_166 [ V_170 + 1 ] = V_252 -> V_251 . V_185 ;
} while ( F_61 ( & V_252 -> V_265 , V_256 ) );
V_170 += 2 ;
V_253 = & V_252 [ 1 ] ;
do {
V_256 = F_60 ( & V_253 -> V_265 ) ;
V_166 [ V_170 ] = V_253 -> V_251 . V_266 ;
V_166 [ V_170 + 1 ] = V_253 -> V_251 . V_185 ;
} while ( F_61 ( & V_253 -> V_265 , V_256 ) );
V_170 += 2 ;
}
F_62 () ;
if ( V_9 != V_8 -> V_9 [ V_8 -> V_130 ] )
return;
if ( V_8 -> V_247 != V_248 ) {
struct V_267 * V_268 = V_8 -> V_268 [ V_8 -> V_247 ] ;
for ( V_178 = 0 ; V_178 < V_249 ; V_178 ++ ) {
V_176 = ( char * ) V_268 ;
V_176 += V_269 [ V_178 ] . V_259 ;
V_166 [ V_170 ++ ] = ( V_269 [ V_178 ] . V_260 ==
sizeof( T_5 ) ) ? * ( T_5 * ) V_176 : * ( T_1 * ) V_176 ;
}
}
for ( V_178 = 0 ; V_178 < V_270 ; V_178 ++ ) {
V_176 = ( char * ) V_8 + V_271 [ V_178 ] . V_259 ;
V_166 [ V_170 ++ ] = ( V_271 [ V_178 ] . V_260 ==
sizeof( T_5 ) ) ? * ( T_5 * ) V_176 : * ( T_1 * ) V_176 ;
}
for ( V_178 = 0 ; V_178 < V_272 ; V_178 ++ ) {
V_166 [ V_170 ++ ] = V_8 -> V_251 . V_273 [ V_178 ] ;
V_166 [ V_170 ++ ] = V_8 -> V_251 . V_274 [ V_178 ] ;
}
for ( V_178 = 0 ; V_178 < V_272 ; V_178 ++ ) {
V_166 [ V_170 ++ ] = V_8 -> V_251 . V_275 [ V_178 ] ;
V_166 [ V_170 ++ ] = V_8 -> V_251 . V_276 [ V_178 ] ;
}
for ( V_178 = 0 ; V_178 < V_272 ; V_178 ++ )
V_166 [ V_170 ++ ] = V_8 -> V_251 . V_277 [ V_178 ] ;
}
static void F_63 ( struct V_1 * V_2 , T_1 V_278 ,
T_3 * V_166 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_124 * V_9 = V_6 -> V_9 ;
struct V_7 * V_8 = V_9 -> V_10 ;
char * V_176 = ( char * ) V_166 ;
int V_170 ;
switch ( V_278 ) {
case V_244 :
for ( V_170 = 0 ; V_170 < V_245 ; V_170 ++ ) {
memcpy ( V_166 , V_279 [ V_170 ] , V_280 ) ;
V_166 += V_280 ;
}
break;
case V_246 :
for ( V_170 = 0 ; V_170 < V_257 ; V_170 ++ ) {
snprintf ( V_176 , V_280 , L_25 ,
V_258 [ V_170 ] . V_281 ) ;
V_176 += V_280 ;
}
for ( V_170 = 0 ; V_170 < V_261 ; V_170 ++ ) {
snprintf ( V_176 , V_280 , L_25 ,
V_262 [ V_170 ] . V_281 ) ;
V_176 += V_280 ;
}
#ifdef F_57
for ( V_170 = 0 ; V_170 < V_263 ; V_170 ++ ) {
snprintf ( V_176 , V_280 , L_25 ,
V_264 [ V_170 ] . V_281 ) ;
V_176 += V_280 ;
}
#endif
for ( V_170 = 0 ; V_170 < V_9 -> V_239 ; V_170 ++ ) {
snprintf ( V_176 , V_280 , L_26 , V_170 ) ;
V_176 += V_280 ;
snprintf ( V_176 , V_280 , L_27 , V_170 ) ;
V_176 += V_280 ;
snprintf ( V_176 , V_280 , L_28 , V_170 ) ;
V_176 += V_280 ;
snprintf ( V_176 , V_280 , L_29 , V_170 ) ;
V_176 += V_280 ;
}
if ( V_9 != V_8 -> V_9 [ V_8 -> V_130 ] )
return;
if ( V_8 -> V_247 != V_248 ) {
for ( V_170 = 0 ; V_170 < V_249 ; V_170 ++ ) {
snprintf ( V_176 , V_280 , L_30 ,
V_269 [ V_170 ] . V_281 ) ;
V_176 += V_280 ;
}
}
for ( V_170 = 0 ; V_170 < V_270 ; V_170 ++ ) {
snprintf ( V_176 , V_280 , L_31 ,
V_271 [ V_170 ] . V_281 ) ;
V_176 += V_280 ;
}
for ( V_170 = 0 ; V_170 < V_272 ; V_170 ++ ) {
snprintf ( V_176 , V_280 ,
L_32 , V_170 ) ;
V_176 += V_280 ;
snprintf ( V_176 , V_280 ,
L_33 , V_170 ) ;
V_176 += V_280 ;
}
for ( V_170 = 0 ; V_170 < V_272 ; V_170 ++ ) {
snprintf ( V_176 , V_280 ,
L_34 , V_170 ) ;
V_176 += V_280 ;
snprintf ( V_176 , V_280 ,
L_35 , V_170 ) ;
V_176 += V_280 ;
}
for ( V_170 = 0 ; V_170 < V_272 ; V_170 ++ ) {
snprintf ( V_176 , V_280 ,
L_36 , V_170 ) ;
V_176 += V_280 ;
}
break;
}
}
static int F_64 ( struct V_1 * V_196 ,
struct V_282 * V_283 )
{
struct V_7 * V_8 = F_65 ( V_196 ) ;
if ( ! ( V_8 -> V_284 & V_285 ) )
return F_66 ( V_196 , V_283 ) ;
V_283 -> V_286 = V_287 |
V_288 |
V_289 |
V_290 |
V_291 |
V_292 ;
if ( V_8 -> V_293 )
V_283 -> V_294 = F_67 ( V_8 -> V_293 ) ;
else
V_283 -> V_294 = - 1 ;
V_283 -> V_295 = ( 1 << V_296 ) | ( 1 << V_297 ) ;
V_283 -> V_298 = ( 1 << V_299 ) |
( 1 << V_300 ) |
( 1 << V_301 ) |
( 1 << V_302 ) |
( 1 << V_303 ) |
( 1 << V_304 ) |
( 1 << V_305 ) |
( 1 << V_306 ) |
( 1 << V_307 ) |
( 1 << V_308 ) |
( 1 << V_309 ) |
( 1 << V_310 ) ;
return 0 ;
}
static int F_68 ( struct V_1 * V_2 , T_5 * V_166 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_9 -> V_10 ;
F_69 ( V_8 , V_12 , V_2 , L_37 ) ;
if ( F_70 ( & V_8 -> V_12 ) )
* V_166 = 0 ;
else
* V_166 = 1 ;
return * V_166 ;
}
static int F_71 ( struct V_1 * V_2 , T_5 * V_166 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_9 -> V_10 ;
F_69 ( V_8 , V_12 , V_2 , L_38 ) ;
* V_166 = F_72 ( & V_8 -> V_12 ) ;
return * V_166 ;
}
static int F_73 ( struct V_1 * V_2 , T_5 * V_166 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_9 -> V_10 ;
F_69 ( V_8 , V_12 , V_2 , L_39 ) ;
* V_166 = F_74 ( & V_8 -> V_12 ) ;
V_8 -> V_12 . V_311 = V_312 ;
return * V_166 ;
}
static int F_75 ( struct V_1 * V_2 , T_5 * V_166 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_9 -> V_10 ;
T_4 V_313 = V_8 -> V_314 ;
F_69 ( V_8 , V_12 , V_2 , L_40 ) ;
F_76 ( & V_8 -> V_12 , V_315 ,
( V_316 |
V_317 |
V_318 |
V_319 |
V_320 ) ) ;
F_7 ( 1000 , 2000 ) ;
* V_166 = ( V_313 == V_8 -> V_314 ) ;
return * V_166 ;
}
static int F_77 ( struct V_1 * V_2 , T_5 * V_166 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_9 -> V_10 ;
F_69 ( V_8 , V_12 , V_2 , L_41 ) ;
* V_166 = 0 ;
return * V_166 ;
}
static void F_78 ( struct V_1 * V_2 ,
struct V_321 * V_322 , T_5 * V_166 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_9 -> V_10 ;
if ( V_322 -> V_284 == V_323 ) {
F_69 ( V_8 , V_324 , V_2 , L_42 ) ;
F_79 ( V_325 , & V_8 -> V_134 ) ;
if ( F_68 ( V_2 , & V_166 [ V_326 ] ) )
V_322 -> V_284 |= V_327 ;
if ( F_73 ( V_2 , & V_166 [ V_328 ] ) )
V_322 -> V_284 |= V_327 ;
if ( F_75 ( V_2 , & V_166 [ V_329 ] ) )
V_322 -> V_284 |= V_327 ;
if ( F_77 ( V_2 , & V_166 [ V_330 ] ) )
V_322 -> V_284 |= V_327 ;
if ( F_71 ( V_2 , & V_166 [ V_331 ] ) )
V_322 -> V_284 |= V_327 ;
F_50 ( V_325 , & V_8 -> V_134 ) ;
F_80 ( V_8 , ( 1 << V_332 ) ) ;
} else {
F_69 ( V_8 , V_324 , V_2 , L_43 ) ;
if ( F_68 ( V_2 , & V_166 [ V_326 ] ) )
V_322 -> V_284 |= V_327 ;
V_166 [ V_331 ] = 0 ;
V_166 [ V_328 ] = 0 ;
V_166 [ V_329 ] = 0 ;
V_166 [ V_330 ] = 0 ;
}
F_69 ( V_8 , V_324 , V_2 , L_44 ) ;
}
static void F_81 ( struct V_1 * V_2 ,
struct V_333 * V_334 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_9 -> V_10 ;
struct V_11 * V_12 = & V_8 -> V_12 ;
T_4 V_335 ;
F_82 ( V_12 , V_336 , & V_335 ) ;
if ( ( 1 << V_12 -> V_84 ) & V_335 ) {
V_334 -> V_24 = 0 ;
V_334 -> V_337 = 0 ;
} else {
V_334 -> V_24 = V_338 ;
V_334 -> V_337 = ( V_8 -> V_339 ? V_338 : 0 ) ;
}
}
static int F_83 ( struct V_1 * V_2 , struct V_333 * V_334 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_9 -> V_10 ;
struct V_11 * V_12 = & V_8 -> V_12 ;
T_4 V_335 ;
F_82 ( V_12 , V_336 , & V_335 ) ;
if ( ( ( 1 << V_12 -> V_84 ) & V_335 ) )
return - V_131 ;
if ( V_334 -> V_337 && ( V_334 -> V_337 != V_338 ) )
return - V_131 ;
if ( V_8 -> V_339 != ! ! V_334 -> V_337 ) {
V_8 -> V_339 = ! ! V_334 -> V_337 ;
F_84 ( & V_8 -> V_195 -> V_196 , V_8 -> V_339 ) ;
}
return 0 ;
}
static int F_85 ( struct V_1 * V_2 ,
enum V_340 V_134 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_9 -> V_10 ;
struct V_11 * V_12 = & V_8 -> V_12 ;
int V_341 = 2 ;
switch ( V_134 ) {
case V_342 :
V_8 -> V_343 = F_86 ( V_12 ) ;
return V_341 ;
case V_344 :
F_87 ( V_12 , 0xF , false ) ;
break;
case V_345 :
F_87 ( V_12 , 0x0 , false ) ;
break;
case V_346 :
F_87 ( V_12 , V_8 -> V_343 , false ) ;
break;
}
return 0 ;
}
static int F_88 ( struct V_1 * V_2 ,
struct V_347 * V_348 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_124 * V_9 = V_6 -> V_9 ;
V_348 -> V_349 = V_9 -> V_350 ;
V_348 -> V_351 = V_9 -> V_350 ;
if ( F_89 ( V_9 -> V_352 ) )
V_348 -> V_353 = 1 ;
if ( F_89 ( V_9 -> V_354 ) )
V_348 -> V_355 = 1 ;
V_348 -> V_356 = V_9 -> V_352 & ~ V_357 ;
V_348 -> V_358 = V_9 -> V_354 & ~ V_357 ;
return 0 ;
}
static int F_90 ( struct V_1 * V_2 ,
struct V_347 * V_348 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_359 * V_360 ;
struct V_124 * V_9 = V_6 -> V_9 ;
struct V_7 * V_8 = V_9 -> V_10 ;
struct V_11 * V_12 = & V_8 -> V_12 ;
T_4 V_361 ;
int V_170 ;
if ( V_348 -> V_349 || V_348 -> V_351 )
V_9 -> V_350 = V_348 -> V_349 ;
V_361 = V_9 -> V_362 ;
if ( ( V_348 -> V_356 >= ( V_363 << 1 ) ) &&
( V_348 -> V_356 <= ( V_364 << 1 ) ) ) {
V_9 -> V_352 = V_348 -> V_356 ;
} else if ( V_348 -> V_356 == 0 ) {
V_9 -> V_352 = V_348 -> V_356 ;
if ( V_348 -> V_353 )
F_69 ( V_8 , V_324 , V_2 , L_45 ) ;
} else {
F_69 ( V_8 , V_324 , V_2 , L_46 ) ;
return - V_136 ;
}
if ( ( V_348 -> V_358 >= ( V_363 << 1 ) ) &&
( V_348 -> V_358 <= ( V_364 << 1 ) ) ) {
V_9 -> V_354 = V_348 -> V_358 ;
} else if ( V_348 -> V_358 == 0 ) {
V_9 -> V_354 = V_348 -> V_358 ;
if ( V_348 -> V_355 )
F_69 ( V_8 , V_324 , V_2 , L_47 ) ;
} else {
F_69 ( V_8 , V_324 , V_2 ,
L_48 ) ;
return - V_136 ;
}
if ( V_348 -> V_353 )
V_9 -> V_352 |= V_357 ;
else
V_9 -> V_352 &= ~ V_357 ;
if ( V_348 -> V_355 )
V_9 -> V_354 |= V_357 ;
else
V_9 -> V_354 &= ~ V_357 ;
for ( V_170 = 0 ; V_170 < V_9 -> V_365 ; V_170 ++ , V_361 ++ ) {
V_360 = V_9 -> V_366 [ V_170 ] ;
V_360 -> V_367 . V_368 = F_91 ( V_9 -> V_352 ) ;
F_76 ( V_12 , F_92 ( 0 , V_361 - 1 ) , V_360 -> V_367 . V_368 ) ;
V_360 -> V_369 . V_368 = F_91 ( V_9 -> V_354 ) ;
F_76 ( V_12 , F_92 ( 1 , V_361 - 1 ) , V_360 -> V_369 . V_368 ) ;
F_93 ( V_12 ) ;
}
return 0 ;
}
static int F_94 ( struct V_7 * V_8 , struct V_370 * V_132 )
{
V_132 -> V_166 = 0 ;
switch ( V_132 -> V_371 ) {
case V_372 :
case V_373 :
V_132 -> V_166 |= V_374 | V_375 ;
case V_376 :
case V_377 :
case V_378 :
case V_379 :
case V_380 :
V_132 -> V_166 |= V_381 | V_382 ;
break;
case V_383 :
case V_384 :
V_132 -> V_166 |= V_374 | V_375 ;
case V_385 :
case V_386 :
case V_387 :
case V_388 :
case V_389 :
V_132 -> V_166 |= V_381 | V_382 ;
break;
default:
return - V_136 ;
}
return 0 ;
}
static int F_95 ( struct V_7 * V_8 ,
struct V_370 * V_132 ,
T_1 * V_390 )
{
struct V_391 * V_392 ;
struct V_393 * V_394 ;
int V_395 = 0 ;
V_132 -> V_166 = F_96 ( V_8 ) ;
F_97 (rule, node2,
&pf->fdir_filter_list, fdir_node) {
if ( V_395 == V_132 -> V_396 )
return - V_397 ;
V_390 [ V_395 ] = V_392 -> V_398 ;
V_395 ++ ;
}
V_132 -> V_396 = V_395 ;
return 0 ;
}
static int F_98 ( struct V_7 * V_8 ,
struct V_370 * V_132 )
{
struct V_399 * V_400 =
(struct V_399 * ) & V_132 -> V_401 ;
struct V_391 * V_392 = NULL ;
struct V_393 * V_394 ;
F_97 (rule, node2,
&pf->fdir_filter_list, fdir_node) {
if ( V_400 -> V_402 <= V_392 -> V_398 )
break;
}
if ( ! V_392 || V_400 -> V_402 != V_392 -> V_398 )
return - V_136 ;
V_400 -> V_371 = V_392 -> V_371 ;
if ( V_400 -> V_371 == V_403 ) {
V_400 -> V_404 . V_405 . V_406 = V_407 ;
V_400 -> V_404 . V_405 . V_408 = 0 ;
V_400 -> V_409 . V_405 . V_408 = 0 ;
}
V_400 -> V_404 . V_410 . V_411 = V_392 -> V_412 ;
V_400 -> V_404 . V_410 . V_413 = V_392 -> V_414 ;
V_400 -> V_404 . V_410 . V_415 = V_392 -> V_416 [ 0 ] ;
V_400 -> V_404 . V_410 . V_417 = V_392 -> V_418 [ 0 ] ;
if ( V_392 -> V_419 == V_420 )
V_400 -> V_421 = V_422 ;
else
V_400 -> V_421 = V_392 -> V_423 ;
return 0 ;
}
static int F_99 ( struct V_1 * V_2 , struct V_370 * V_132 ,
T_1 * V_390 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_124 * V_9 = V_6 -> V_9 ;
struct V_7 * V_8 = V_9 -> V_10 ;
int V_145 = - V_131 ;
switch ( V_132 -> V_132 ) {
case V_424 :
V_132 -> V_166 = V_9 -> V_241 ;
V_145 = 0 ;
break;
case V_425 :
V_145 = F_94 ( V_8 , V_132 ) ;
break;
case V_426 :
V_132 -> V_396 = V_8 -> V_427 ;
V_132 -> V_166 = F_96 ( V_8 ) ;
V_145 = 0 ;
break;
case V_428 :
V_145 = F_98 ( V_8 , V_132 ) ;
break;
case V_429 :
V_145 = F_95 ( V_8 , V_132 , V_390 ) ;
break;
default:
break;
}
return V_145 ;
}
static int F_100 ( struct V_7 * V_8 , struct V_370 * V_430 )
{
struct V_11 * V_12 = & V_8 -> V_12 ;
T_5 V_431 = ( T_5 ) F_22 ( V_12 , F_101 ( 0 ) ) |
( ( T_5 ) F_22 ( V_12 , F_101 ( 1 ) ) << 32 ) ;
if ( V_430 -> V_166 & ~ ( V_381 | V_382 |
V_374 | V_375 ) )
return - V_136 ;
if ( ! ( V_430 -> V_166 & V_381 ) ||
! ( V_430 -> V_166 & V_382 ) )
return - V_136 ;
switch ( V_430 -> V_371 ) {
case V_372 :
switch ( V_430 -> V_166 & ( V_374 | V_375 ) ) {
case 0 :
V_431 &= ~ ( ( T_5 ) 1 << V_432 ) ;
break;
case ( V_374 | V_375 ) :
V_431 |= ( ( T_5 ) 1 << V_432 ) ;
break;
default:
return - V_136 ;
}
break;
case V_383 :
switch ( V_430 -> V_166 & ( V_374 | V_375 ) ) {
case 0 :
V_431 &= ~ ( ( T_5 ) 1 << V_433 ) ;
break;
case ( V_374 | V_375 ) :
V_431 |= ( ( T_5 ) 1 << V_433 ) ;
break;
default:
return - V_136 ;
}
break;
case V_373 :
switch ( V_430 -> V_166 & ( V_374 | V_375 ) ) {
case 0 :
V_431 &= ~ ( ( ( T_5 ) 1 << V_434 ) |
( ( T_5 ) 1 << V_435 ) ) ;
break;
case ( V_374 | V_375 ) :
V_431 |= ( ( ( T_5 ) 1 << V_434 ) |
( ( T_5 ) 1 << V_435 ) ) ;
break;
default:
return - V_136 ;
}
break;
case V_384 :
switch ( V_430 -> V_166 & ( V_374 | V_375 ) ) {
case 0 :
V_431 &= ~ ( ( ( T_5 ) 1 << V_436 ) |
( ( T_5 ) 1 << V_437 ) ) ;
break;
case ( V_374 | V_375 ) :
V_431 |= ( ( ( T_5 ) 1 << V_436 ) |
( ( T_5 ) 1 << V_437 ) ) ;
break;
default:
return - V_136 ;
}
break;
case V_377 :
case V_378 :
case V_379 :
case V_376 :
if ( ( V_430 -> V_166 & V_374 ) ||
( V_430 -> V_166 & V_375 ) )
return - V_136 ;
V_431 |= ( ( T_5 ) 1 << V_438 ) ;
break;
case V_386 :
case V_387 :
case V_388 :
case V_385 :
if ( ( V_430 -> V_166 & V_374 ) ||
( V_430 -> V_166 & V_375 ) )
return - V_136 ;
V_431 |= ( ( T_5 ) 1 << V_439 ) ;
break;
case V_380 :
V_431 |= ( ( T_5 ) 1 << V_438 ) |
( ( T_5 ) 1 << V_435 ) ;
break;
case V_389 :
V_431 |= ( ( T_5 ) 1 << V_439 ) |
( ( T_5 ) 1 << V_437 ) ;
break;
default:
return - V_136 ;
}
F_76 ( V_12 , F_101 ( 0 ) , ( T_1 ) V_431 ) ;
F_76 ( V_12 , F_101 ( 1 ) , ( T_1 ) ( V_431 >> 32 ) ) ;
F_93 ( V_12 ) ;
return 0 ;
}
static bool F_102 ( struct V_391 * V_392 ,
struct V_391 * V_440 )
{
if ( ( V_392 -> V_416 [ 0 ] != V_440 -> V_416 [ 0 ] ) ||
( V_392 -> V_418 [ 0 ] != V_440 -> V_418 [ 0 ] ) ||
( V_392 -> V_412 != V_440 -> V_412 ) ||
( V_392 -> V_414 != V_440 -> V_414 ) )
return false ;
return true ;
}
static int F_103 ( struct V_124 * V_9 ,
struct V_391 * V_440 ,
T_4 V_441 ,
struct V_370 * V_132 )
{
struct V_391 * V_392 , * V_442 ;
struct V_7 * V_8 = V_9 -> V_10 ;
struct V_393 * V_394 ;
int V_128 = - V_136 ;
V_442 = NULL ;
V_392 = NULL ;
F_97 (rule, node2,
&pf->fdir_filter_list, fdir_node) {
if ( V_392 -> V_398 >= V_441 )
break;
V_442 = V_392 ;
}
if ( V_392 && ( V_392 -> V_398 == V_441 ) ) {
if ( V_440 && ! F_102 ( V_392 , V_440 ) )
V_128 = F_104 ( V_9 , V_392 , false ) ;
else if ( ! V_440 )
V_128 = F_104 ( V_9 , V_392 , false ) ;
F_105 ( & V_392 -> V_443 ) ;
F_31 ( V_392 ) ;
V_8 -> V_427 -- ;
}
if ( ! V_440 )
return V_128 ;
F_106 ( & V_440 -> V_443 ) ;
if ( V_442 )
F_107 ( & V_440 -> V_443 , & V_442 -> V_443 ) ;
else
F_108 ( & V_440 -> V_443 ,
& V_8 -> V_444 ) ;
V_8 -> V_427 ++ ;
return 0 ;
}
static int F_109 ( struct V_124 * V_9 ,
struct V_370 * V_132 )
{
struct V_399 * V_400 =
(struct V_399 * ) & V_132 -> V_401 ;
struct V_7 * V_8 = V_9 -> V_10 ;
int V_145 = 0 ;
if ( F_6 ( V_209 , & V_8 -> V_134 ) ||
F_6 ( V_210 , & V_8 -> V_134 ) )
return - V_211 ;
if ( F_6 ( V_445 , & V_8 -> V_134 ) )
return - V_211 ;
V_145 = F_103 ( V_9 , NULL , V_400 -> V_402 , V_132 ) ;
F_110 ( V_8 ) ;
return V_145 ;
}
static int F_111 ( struct V_124 * V_9 ,
struct V_370 * V_132 )
{
struct V_399 * V_400 ;
struct V_391 * V_440 ;
struct V_7 * V_8 ;
int V_145 = - V_136 ;
if ( ! V_9 )
return - V_136 ;
V_8 = V_9 -> V_10 ;
if ( ! ( V_8 -> V_284 & V_446 ) )
return - V_131 ;
if ( V_8 -> V_447 & V_446 )
return - V_448 ;
if ( F_6 ( V_209 , & V_8 -> V_134 ) ||
F_6 ( V_210 , & V_8 -> V_134 ) )
return - V_211 ;
if ( F_6 ( V_445 , & V_8 -> V_134 ) )
return - V_211 ;
V_400 = (struct V_399 * ) & V_132 -> V_401 ;
if ( V_400 -> V_402 >= ( V_8 -> V_12 . V_449 . V_450 +
V_8 -> V_12 . V_449 . V_451 ) ) {
return - V_136 ;
}
if ( ( V_400 -> V_421 != V_422 ) &&
( V_400 -> V_421 >= V_9 -> V_239 ) )
return - V_136 ;
V_440 = F_27 ( sizeof( * V_440 ) , V_199 ) ;
if ( ! V_440 )
return - V_200 ;
V_440 -> V_398 = V_400 -> V_402 ;
if ( V_400 -> V_421 == V_422 )
V_440 -> V_419 = V_420 ;
else
V_440 -> V_419 =
V_452 ;
V_440 -> V_423 = V_400 -> V_421 ;
V_440 -> V_453 = 0 ;
V_440 -> V_454 = 0 ;
V_440 -> V_455 = V_9 -> V_456 ;
V_440 -> V_457 = V_458 ;
V_440 -> V_459 = V_8 -> V_460 ;
V_440 -> V_371 = V_400 -> V_371 ;
V_440 -> V_461 = V_400 -> V_404 . V_405 . V_408 ;
V_440 -> V_412 = V_400 -> V_404 . V_410 . V_411 ;
V_440 -> V_414 = V_400 -> V_404 . V_410 . V_413 ;
V_440 -> V_416 [ 0 ] = V_400 -> V_404 . V_410 . V_415 ;
V_440 -> V_418 [ 0 ] = V_400 -> V_404 . V_410 . V_417 ;
V_145 = F_104 ( V_9 , V_440 , true ) ;
if ( V_145 )
F_31 ( V_440 ) ;
else
F_103 ( V_9 , V_440 , V_400 -> V_402 , NULL ) ;
return V_145 ;
}
static int F_112 ( struct V_1 * V_2 , struct V_370 * V_132 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_124 * V_9 = V_6 -> V_9 ;
struct V_7 * V_8 = V_9 -> V_10 ;
int V_145 = - V_131 ;
switch ( V_132 -> V_132 ) {
case V_462 :
V_145 = F_100 ( V_8 , V_132 ) ;
break;
case V_463 :
V_145 = F_111 ( V_9 , V_132 ) ;
break;
case V_464 :
V_145 = F_109 ( V_9 , V_132 ) ;
break;
default:
break;
}
return V_145 ;
}
static unsigned int F_113 ( struct V_124 * V_9 )
{
return V_9 -> V_241 ;
}
static void F_114 ( struct V_1 * V_196 ,
struct V_465 * V_466 )
{
struct V_5 * V_6 = F_2 ( V_196 ) ;
struct V_124 * V_9 = V_6 -> V_9 ;
struct V_7 * V_8 = V_9 -> V_10 ;
V_466 -> V_467 = F_113 ( V_9 ) ;
V_466 -> V_468 = ( V_8 -> V_284 & V_446 ) ? 1 : 0 ;
V_466 -> V_469 = V_466 -> V_468 ;
V_466 -> V_470 = V_9 -> V_239 ;
}
static int F_115 ( struct V_1 * V_196 ,
struct V_465 * V_466 )
{
struct V_5 * V_6 = F_2 ( V_196 ) ;
unsigned int V_229 = V_466 -> V_470 ;
struct V_124 * V_9 = V_6 -> V_9 ;
struct V_7 * V_8 = V_9 -> V_10 ;
int V_471 ;
if ( V_9 -> type != V_472 )
return - V_136 ;
if ( ! V_229 || V_466 -> V_473 || V_466 -> V_474 )
return - V_136 ;
if ( V_466 -> V_468 != ( ( V_8 -> V_284 & V_446 ) ? 1 : 0 ) )
return - V_136 ;
if ( V_229 > F_113 ( V_9 ) )
return - V_136 ;
if ( V_229 > V_8 -> V_475 )
V_229 = V_8 -> V_475 ;
V_471 = F_116 ( V_8 , V_229 ) ;
if ( V_471 > 0 )
return 0 ;
else
return - V_136 ;
}
void F_117 ( struct V_1 * V_2 )
{
V_2 -> V_476 = & V_477 ;
}
