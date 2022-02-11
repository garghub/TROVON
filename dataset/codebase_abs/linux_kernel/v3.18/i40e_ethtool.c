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
default:
V_4 -> V_24 = V_38 |
V_39 ;
V_4 -> V_28 = V_40 |
V_41 ;
break;
}
goto V_42;
}
switch ( V_14 -> V_43 ) {
case V_44 :
case V_45 :
V_4 -> V_24 = V_46 |
V_26 ;
V_4 -> V_28 = V_47 |
V_30 ;
break;
case V_48 :
V_4 -> V_24 = V_46 |
V_33 ;
V_4 -> V_28 = V_47 |
V_34 ;
break;
case V_49 :
case V_50 :
case V_51 :
V_4 -> V_24 = V_25 ;
break;
case V_52 :
V_4 -> V_24 = V_27 ;
break;
case V_53 :
V_4 -> V_24 = V_46 |
V_54 ;
V_4 -> V_28 = V_47 |
V_55 ;
break;
case V_56 :
V_4 -> V_24 = V_46 |
V_36 ;
V_4 -> V_28 = V_47 |
V_37 ;
break;
case V_57 :
case V_58 :
case V_59 :
case V_60 :
V_4 -> V_24 = V_38 ;
V_4 -> V_24 |= V_39 ;
break;
case V_61 :
case V_62 :
case V_63 :
V_4 -> V_24 = V_46 |
V_38 ;
V_4 -> V_28 = V_47 |
V_40 ;
break;
case V_64 :
case V_65 :
case V_66 :
case V_67 :
V_4 -> V_24 = V_38 ;
break;
case V_68 :
case V_69 :
V_4 -> V_24 = V_46 |
V_39 ;
V_4 -> V_28 = V_47 |
V_41 ;
break;
case V_70 :
V_4 -> V_24 = V_46 |
V_71 ;
V_4 -> V_28 = V_47 |
V_72 ;
break;
case V_73 :
V_4 -> V_24 = V_46 |
V_39 |
V_71 ;
V_4 -> V_28 = V_47 |
V_41 |
V_72 ;
break;
default:
F_3 ( V_2 , L_1 ,
V_14 -> V_43 ) ;
}
V_42:
V_4 -> V_74 = ( ( V_14 -> V_75 & V_76 ) ?
V_77 : V_78 ) ;
switch ( V_12 -> V_15 . V_79 ) {
case V_80 :
V_4 -> V_24 |= V_46 |
V_81 ;
V_4 -> V_28 |= V_47 |
V_82 ;
V_4 -> V_83 = V_84 ;
break;
case V_85 :
V_4 -> V_24 |= V_86 ;
V_4 -> V_28 |= V_87 ;
V_4 -> V_83 = V_88 ;
break;
case V_89 :
case V_90 :
V_4 -> V_24 |= V_91 ;
V_4 -> V_28 |= V_92 ;
V_4 -> V_83 = V_93 ;
break;
case V_94 :
V_4 -> V_24 |= V_91 ;
V_4 -> V_83 = V_95 ;
break;
case V_96 :
default:
V_4 -> V_83 = V_97 ;
break;
}
V_4 -> V_98 = V_99 ;
V_4 -> V_24 |= V_100 ;
switch ( V_12 -> V_101 . V_102 ) {
case V_103 :
V_4 -> V_28 |= V_104 ;
break;
case V_105 :
V_4 -> V_28 |= V_106 ;
break;
case V_107 :
V_4 -> V_28 |= ( V_104 |
V_106 ) ;
break;
default:
V_4 -> V_28 &= ~ ( V_104 |
V_106 ) ;
break;
}
if ( V_17 ) {
switch ( V_19 ) {
case V_108 :
F_4 ( V_4 , 40000 ) ;
break;
case V_109 :
F_4 ( V_4 , V_110 ) ;
break;
case V_111 :
F_4 ( V_4 , V_112 ) ;
break;
default:
break;
}
V_4 -> V_113 = V_114 ;
} else {
F_4 ( V_4 , V_115 ) ;
V_4 -> V_113 = V_116 ;
}
return 0 ;
}
static int F_5 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_117 V_118 ;
struct V_119 V_120 ;
struct V_7 * V_8 = V_6 -> V_9 -> V_10 ;
struct V_121 * V_9 = V_6 -> V_9 ;
struct V_11 * V_12 = & V_8 -> V_12 ;
struct V_3 V_122 ;
T_2 V_123 = 0 ;
bool V_124 = false ;
int V_125 = 0 ;
T_3 V_74 ;
T_1 V_126 ;
if ( V_9 != V_8 -> V_9 [ V_8 -> V_127 ] )
return - V_128 ;
if ( V_12 -> V_15 . V_79 != V_85 &&
V_12 -> V_15 . V_79 != V_94 &&
V_12 -> V_15 . V_79 != V_80 &&
V_12 -> V_15 . V_16 . V_16 & V_18 )
return - V_128 ;
memset ( & V_122 , 0 , sizeof( struct V_3 ) ) ;
F_1 ( V_2 , & V_122 ) ;
V_74 = V_4 -> V_74 ;
V_126 = V_4 -> V_28 ;
V_4 -> V_74 = V_122 . V_74 ;
V_4 -> V_28 = V_122 . V_28 ;
V_4 -> V_129 = V_122 . V_129 ;
if ( memcmp ( V_4 , & V_122 , sizeof( struct V_3 ) ) )
return - V_128 ;
while ( F_6 ( V_130 , & V_9 -> V_131 ) )
F_7 ( 1000 , 2000 ) ;
V_123 = F_8 ( V_12 , false , false , & V_118 ,
NULL ) ;
if ( V_123 )
return - V_132 ;
memset ( & V_120 , 0 , sizeof( struct V_119 ) ) ;
V_120 . V_118 = V_118 . V_118 ;
if ( V_74 == V_77 ) {
if ( ! ( V_122 . V_24 & V_46 ) ) {
F_3 ( V_2 , L_2 ) ;
return - V_133 ;
}
if ( ! ( V_12 -> V_15 . V_16 . V_75 & V_76 ) ) {
V_120 . V_118 = V_118 . V_118 |
V_134 ;
V_124 = true ;
}
} else {
if ( V_122 . V_24 & V_46 &&
V_12 -> V_15 . V_16 . V_43 != V_63 ) {
F_3 ( V_2 , L_3 ) ;
return - V_133 ;
}
if ( V_12 -> V_15 . V_16 . V_75 & V_76 ) {
V_120 . V_118 = V_118 . V_118 |
~ V_134 ;
V_124 = true ;
}
}
if ( V_126 & ~ V_122 . V_24 )
return - V_133 ;
if ( V_126 & V_72 )
V_120 . V_19 |= V_135 ;
if ( V_126 & V_41 ||
V_126 & V_136 )
V_120 . V_19 |= V_111 ;
if ( V_126 & V_40 ||
V_126 & V_55 ||
V_126 & V_37 )
V_120 . V_19 |= V_109 ;
if ( V_126 & V_34 ||
V_126 & V_30 ||
V_126 & V_29 ||
V_126 & V_31 )
V_120 . V_19 |= V_108 ;
if ( V_124 || ( V_118 . V_19 != V_120 . V_19 ) ) {
V_120 . V_43 = V_118 . V_43 ;
V_120 . V_137 = V_118 . V_137 ;
V_120 . V_138 = V_118 . V_139 ;
V_120 . V_140 = V_118 . V_141 ;
V_120 . V_118 |= V_142 ;
if ( V_12 -> V_15 . V_16 . V_16 & V_18 ) {
F_3 ( V_2 , L_4 ) ;
F_9 ( V_2 ) ;
F_10 ( V_2 ) ;
}
V_123 = V_119 ( V_12 , & V_120 , NULL ) ;
if ( V_123 ) {
F_3 ( V_2 , L_5 ,
V_123 ) ;
return - V_132 ;
}
V_123 = F_11 ( V_12 , true ) ;
if ( V_123 )
F_3 ( V_2 , L_6 ,
V_123 ) ;
} else {
F_3 ( V_2 , L_7 ) ;
}
return V_125 ;
}
static int F_12 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_9 -> V_10 ;
struct V_11 * V_12 = & V_8 -> V_12 ;
bool V_17 = V_12 -> V_15 . V_16 . V_16 & V_18 ;
T_2 V_143 = 0 ;
V_143 = F_13 ( V_12 , V_17 , NULL ) ;
if ( V_143 ) {
F_3 ( V_2 , L_8 ,
V_8 -> V_12 . V_144 . V_145 ) ;
return - V_146 ;
}
return 0 ;
}
static void F_14 ( struct V_1 * V_2 ,
struct V_147 * V_148 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_9 -> V_10 ;
struct V_11 * V_12 = & V_8 -> V_12 ;
struct V_13 * V_14 = & V_12 -> V_15 . V_16 ;
V_148 -> V_74 =
( ( V_14 -> V_75 & V_76 ) ?
V_77 : V_78 ) ;
if ( V_12 -> V_101 . V_102 == V_107 ) {
V_148 -> V_149 = 1 ;
} else if ( V_12 -> V_101 . V_102 == V_105 ) {
V_148 -> V_150 = 1 ;
} else if ( V_12 -> V_101 . V_102 == V_103 ) {
V_148 -> V_149 = 1 ;
V_148 -> V_150 = 1 ;
}
}
static int F_15 ( struct V_1 * V_2 ,
struct V_147 * V_148 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_9 -> V_10 ;
struct V_121 * V_9 = V_6 -> V_9 ;
struct V_11 * V_12 = & V_8 -> V_12 ;
struct V_13 * V_14 = & V_12 -> V_15 . V_16 ;
bool V_17 = V_14 -> V_16 & V_18 ;
T_2 V_123 ;
T_3 V_151 ;
int V_125 = 0 ;
if ( V_9 != V_8 -> V_9 [ V_8 -> V_127 ] )
return - V_128 ;
if ( V_148 -> V_74 != ( ( V_14 -> V_75 & V_76 ) ?
V_77 : V_78 ) ) {
F_3 ( V_2 , L_9 ) ;
return - V_128 ;
}
if ( ! F_6 ( V_152 , & V_8 -> V_131 ) &&
! ( V_14 -> V_75 & V_76 ) ) {
F_3 ( V_2 , L_10 ) ;
}
if ( V_12 -> V_101 . V_102 == V_153 ) {
F_3 ( V_2 , L_11 ) ;
return - V_128 ;
}
if ( V_148 -> V_149 && V_148 -> V_150 )
V_12 -> V_101 . V_154 = V_103 ;
else if ( V_148 -> V_149 && ! V_148 -> V_150 )
V_12 -> V_101 . V_154 = V_107 ;
else if ( ! V_148 -> V_149 && V_148 -> V_150 )
V_12 -> V_101 . V_154 = V_105 ;
else if ( ! V_148 -> V_149 && ! V_148 -> V_150 )
V_12 -> V_101 . V_154 = V_155 ;
else
return - V_133 ;
F_3 ( V_2 , L_12 ) ;
F_9 ( V_2 ) ;
F_10 ( V_2 ) ;
V_123 = F_16 ( V_12 , & V_151 , V_17 ) ;
if ( V_151 & V_156 ) {
F_3 ( V_2 , L_13 ,
V_123 , V_12 -> V_144 . V_145 ) ;
V_125 = - V_132 ;
}
if ( V_151 & V_157 ) {
F_3 ( V_2 , L_14 ,
V_123 , V_12 -> V_144 . V_145 ) ;
V_125 = - V_132 ;
}
if ( V_151 & V_158 ) {
F_3 ( V_2 , L_15 ,
V_123 , V_12 -> V_144 . V_145 ) ;
V_125 = - V_132 ;
}
if ( ! F_6 ( V_152 , & V_8 -> V_131 ) ) {
F_17 ( 75 ) ;
if ( ! F_6 ( V_152 , & V_8 -> V_131 ) )
return F_12 ( V_2 ) ;
}
return V_125 ;
}
static T_1 F_18 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_9 -> V_10 ;
return V_8 -> V_159 ;
}
static void F_19 ( struct V_1 * V_2 , T_1 V_160 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_9 -> V_10 ;
if ( V_161 & V_160 )
V_8 -> V_12 . V_162 = V_160 ;
V_8 -> V_159 = V_160 ;
}
static int F_20 ( struct V_1 * V_2 )
{
int V_163 = 0 ;
int V_164 ;
for ( V_164 = 0 ; V_165 [ V_164 ] . V_166 != 0 ; V_164 ++ )
V_163 += V_165 [ V_164 ] . V_167 ;
return V_163 * sizeof( T_1 ) ;
}
static void F_21 ( struct V_1 * V_2 , struct V_168 * V_169 ,
void * V_170 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_9 -> V_10 ;
struct V_11 * V_12 = & V_8 -> V_12 ;
T_1 * V_171 = V_170 ;
int V_164 , V_172 , V_173 ;
T_1 V_174 ;
V_169 -> V_175 = 1 ;
V_173 = 0 ;
for ( V_164 = 0 ; V_165 [ V_164 ] . V_166 != 0 ; V_164 ++ ) {
for ( V_172 = 0 ; V_172 < V_165 [ V_164 ] . V_167 ; V_172 ++ ) {
V_174 = V_165 [ V_164 ] . V_166
+ ( V_172 * V_165 [ V_164 ] . V_176 ) ;
V_171 [ V_173 ++ ] = F_22 ( V_12 , V_174 ) ;
}
}
}
static int F_23 ( struct V_1 * V_2 ,
struct V_177 * V_178 , T_3 * V_179 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_11 * V_12 = & V_6 -> V_9 -> V_10 -> V_12 ;
struct V_7 * V_8 = V_6 -> V_9 -> V_10 ;
int V_180 = 0 , V_181 ;
T_3 * V_182 ;
T_4 V_164 , V_183 ;
bool V_184 ;
T_1 V_185 ;
#define F_24 4096
if ( V_178 -> V_181 == 0 )
return - V_133 ;
V_185 = V_12 -> V_186 | ( V_12 -> V_20 << 16 ) ;
if ( V_178 -> V_185 && V_178 -> V_185 != V_185 ) {
int V_187 ;
if ( ( V_178 -> V_185 >> 16 ) != V_12 -> V_20 )
return - V_133 ;
V_180 = F_25 ( V_12 ,
(struct V_188 * ) V_178 ,
V_179 , & V_187 ) ;
if ( V_180 )
F_26 ( & V_8 -> V_189 -> V_190 ,
L_16 ,
V_180 , V_12 -> V_144 . V_145 ) ;
return V_187 ;
}
V_178 -> V_185 = V_12 -> V_186 | ( V_12 -> V_20 << 16 ) ;
V_182 = F_27 ( V_178 -> V_181 , V_191 ) ;
if ( ! V_182 )
return - V_192 ;
V_180 = F_28 ( V_12 , V_193 ) ;
if ( V_180 ) {
F_26 ( & V_8 -> V_189 -> V_190 ,
L_17 ,
V_180 , V_12 -> V_144 . V_145 ) ;
goto V_194;
}
V_183 = V_178 -> V_181 / F_24 ;
V_183 += ( V_178 -> V_181 % F_24 ) ? 1 : 0 ;
V_181 = F_24 ;
V_184 = false ;
for ( V_164 = 0 ; V_164 < V_183 ; V_164 ++ ) {
if ( V_164 == ( V_183 - 1 ) ) {
V_181 = V_178 -> V_181 - ( F_24 * V_164 ) ;
V_184 = true ;
}
V_180 = F_29 ( V_12 , 0x0 ,
V_178 -> V_166 + ( F_24 * V_164 ) ,
V_181 ,
( T_3 * ) V_182 + ( F_24 * V_164 ) ,
V_184 , NULL ) ;
if ( V_180 ) {
F_26 ( & V_8 -> V_189 -> V_190 ,
L_18 ,
V_180 , V_12 -> V_144 . V_145 ) ;
goto V_195;
}
}
V_195:
F_30 ( V_12 ) ;
memcpy ( V_179 , ( T_3 * ) V_182 , V_178 -> V_181 ) ;
V_194:
F_31 ( V_182 ) ;
return V_180 ;
}
static int F_32 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_11 * V_12 = & V_6 -> V_9 -> V_10 -> V_12 ;
T_1 V_196 ;
V_196 = ( F_22 ( V_12 , V_197 )
& V_198 )
>> V_199 ;
V_196 = ( 64 * 1024 ) * ( 1 << V_196 ) ;
return V_196 ;
}
static int F_33 ( struct V_1 * V_2 ,
struct V_177 * V_178 , T_3 * V_179 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_11 * V_12 = & V_6 -> V_9 -> V_10 -> V_12 ;
struct V_7 * V_8 = V_6 -> V_9 -> V_10 ;
int V_180 = 0 ;
int V_187 ;
T_1 V_185 ;
V_185 = V_12 -> V_186 | ( V_12 -> V_20 << 16 ) ;
if ( V_178 -> V_185 == V_185 )
return - V_128 ;
if ( ! V_178 -> V_185 || ( V_178 -> V_185 >> 16 ) != V_12 -> V_20 )
return - V_133 ;
if ( F_6 ( V_200 , & V_8 -> V_131 ) ||
F_6 ( V_201 , & V_8 -> V_131 ) )
return - V_202 ;
V_180 = F_25 ( V_12 , (struct V_188 * ) V_178 ,
V_179 , & V_187 ) ;
if ( V_180 )
F_26 ( & V_8 -> V_189 -> V_190 ,
L_19 ,
V_180 , V_12 -> V_144 . V_145 ) ;
return V_187 ;
}
static void F_34 ( struct V_1 * V_2 ,
struct V_203 * V_204 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_121 * V_9 = V_6 -> V_9 ;
struct V_7 * V_8 = V_9 -> V_10 ;
F_35 ( V_204 -> V_205 , V_206 , sizeof( V_204 -> V_205 ) ) ;
F_35 ( V_204 -> V_175 , V_207 ,
sizeof( V_204 -> V_175 ) ) ;
F_35 ( V_204 -> V_208 , F_36 ( & V_8 -> V_12 ) ,
sizeof( V_204 -> V_208 ) ) ;
F_35 ( V_204 -> V_209 , F_37 ( V_8 -> V_189 ) ,
sizeof( V_204 -> V_209 ) ) ;
}
static void F_38 ( struct V_1 * V_2 ,
struct V_210 * V_211 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_9 -> V_10 ;
struct V_121 * V_9 = V_8 -> V_9 [ V_8 -> V_127 ] ;
V_211 -> V_212 = V_213 ;
V_211 -> V_214 = V_213 ;
V_211 -> V_215 = 0 ;
V_211 -> V_216 = 0 ;
V_211 -> V_217 = V_9 -> V_218 [ 0 ] -> V_219 ;
V_211 -> V_220 = V_9 -> V_221 [ 0 ] -> V_219 ;
V_211 -> V_222 = 0 ;
V_211 -> V_223 = 0 ;
}
static int F_39 ( struct V_1 * V_2 ,
struct V_210 * V_211 )
{
struct V_224 * V_221 = NULL , * V_218 = NULL ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_121 * V_9 = V_6 -> V_9 ;
struct V_7 * V_8 = V_9 -> V_10 ;
T_1 V_225 , V_226 ;
int V_164 , V_125 = 0 ;
if ( ( V_211 -> V_222 ) || ( V_211 -> V_223 ) )
return - V_133 ;
if ( V_211 -> V_220 > V_213 ||
V_211 -> V_220 < V_227 ||
V_211 -> V_217 > V_213 ||
V_211 -> V_217 < V_227 ) {
F_3 ( V_2 ,
L_20 ,
V_211 -> V_220 , V_211 -> V_217 ,
V_227 , V_213 ) ;
return - V_133 ;
}
V_226 = F_40 ( V_211 -> V_220 , V_228 ) ;
V_225 = F_40 ( V_211 -> V_217 , V_228 ) ;
if ( ( V_226 == V_9 -> V_221 [ 0 ] -> V_219 ) &&
( V_225 == V_9 -> V_218 [ 0 ] -> V_219 ) )
return 0 ;
while ( F_41 ( V_130 , & V_8 -> V_131 ) )
F_7 ( 1000 , 2000 ) ;
if ( ! F_42 ( V_9 -> V_2 ) ) {
for ( V_164 = 0 ; V_164 < V_9 -> V_229 ; V_164 ++ ) {
V_9 -> V_221 [ V_164 ] -> V_219 = V_226 ;
V_9 -> V_218 [ V_164 ] -> V_219 = V_225 ;
}
goto V_230;
}
if ( V_226 != V_9 -> V_221 [ 0 ] -> V_219 ) {
F_3 ( V_2 ,
L_21 ,
V_9 -> V_221 [ 0 ] -> V_219 , V_226 ) ;
V_221 = F_43 ( V_9 -> V_231 ,
sizeof( struct V_224 ) , V_191 ) ;
if ( ! V_221 ) {
V_125 = - V_192 ;
goto V_230;
}
for ( V_164 = 0 ; V_164 < V_9 -> V_229 ; V_164 ++ ) {
V_221 [ V_164 ] = * V_9 -> V_221 [ V_164 ] ;
V_221 [ V_164 ] . V_219 = V_226 ;
V_125 = F_44 ( & V_221 [ V_164 ] ) ;
if ( V_125 ) {
while ( V_164 ) {
V_164 -- ;
F_45 ( & V_221 [ V_164 ] ) ;
}
F_31 ( V_221 ) ;
V_221 = NULL ;
goto V_230;
}
}
}
if ( V_225 != V_9 -> V_218 [ 0 ] -> V_219 ) {
F_3 ( V_2 ,
L_22 ,
V_9 -> V_218 [ 0 ] -> V_219 , V_225 ) ;
V_218 = F_43 ( V_9 -> V_231 ,
sizeof( struct V_224 ) , V_191 ) ;
if ( ! V_218 ) {
V_125 = - V_192 ;
goto V_232;
}
for ( V_164 = 0 ; V_164 < V_9 -> V_229 ; V_164 ++ ) {
V_218 [ V_164 ] = * V_9 -> V_218 [ V_164 ] ;
V_218 [ V_164 ] . V_219 = V_225 ;
V_125 = F_46 ( & V_218 [ V_164 ] ) ;
if ( V_125 ) {
while ( V_164 ) {
V_164 -- ;
F_47 ( & V_218 [ V_164 ] ) ;
}
F_31 ( V_218 ) ;
V_218 = NULL ;
goto V_232;
}
}
}
F_48 ( V_9 ) ;
if ( V_221 ) {
for ( V_164 = 0 ; V_164 < V_9 -> V_229 ; V_164 ++ ) {
F_45 ( V_9 -> V_221 [ V_164 ] ) ;
* V_9 -> V_221 [ V_164 ] = V_221 [ V_164 ] ;
}
F_31 ( V_221 ) ;
V_221 = NULL ;
}
if ( V_218 ) {
for ( V_164 = 0 ; V_164 < V_9 -> V_229 ; V_164 ++ ) {
F_47 ( V_9 -> V_218 [ V_164 ] ) ;
* V_9 -> V_218 [ V_164 ] = V_218 [ V_164 ] ;
}
F_31 ( V_218 ) ;
V_218 = NULL ;
}
F_49 ( V_9 ) ;
V_232:
if ( V_221 ) {
for ( V_164 = 0 ; V_164 < V_9 -> V_229 ; V_164 ++ )
F_45 ( & V_221 [ V_164 ] ) ;
F_31 ( V_221 ) ;
V_221 = NULL ;
}
V_230:
F_50 ( V_130 , & V_8 -> V_131 ) ;
return V_125 ;
}
static int F_51 ( struct V_1 * V_2 , int V_233 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_121 * V_9 = V_6 -> V_9 ;
struct V_7 * V_8 = V_9 -> V_10 ;
switch ( V_233 ) {
case V_234 :
return V_235 ;
case V_236 :
if ( V_9 == V_8 -> V_9 [ V_8 -> V_127 ] ) {
int V_181 = F_52 ( V_2 ) ;
if ( V_8 -> V_237 != V_238 )
V_181 += V_239 ;
return V_181 ;
} else {
return F_53 ( V_2 ) ;
}
default:
return - V_128 ;
}
}
static void F_54 ( struct V_1 * V_2 ,
struct V_240 * V_241 , T_5 * V_160 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_224 * V_242 , * V_243 ;
struct V_121 * V_9 = V_6 -> V_9 ;
struct V_7 * V_8 = V_9 -> V_10 ;
int V_164 = 0 ;
char * V_170 ;
int V_172 ;
struct V_244 * V_245 = F_55 ( V_9 ) ;
unsigned int V_246 ;
F_56 ( V_9 ) ;
for ( V_172 = 0 ; V_172 < V_247 ; V_172 ++ ) {
V_170 = ( char * ) V_245 + V_248 [ V_172 ] . V_249 ;
V_160 [ V_164 ++ ] = ( V_248 [ V_172 ] . V_250 ==
sizeof( T_5 ) ) ? * ( T_5 * ) V_170 : * ( T_1 * ) V_170 ;
}
for ( V_172 = 0 ; V_172 < V_251 ; V_172 ++ ) {
V_170 = ( char * ) V_9 + V_252 [ V_172 ] . V_249 ;
V_160 [ V_164 ++ ] = ( V_252 [ V_172 ] . V_250 ==
sizeof( T_5 ) ) ? * ( T_5 * ) V_170 : * ( T_1 * ) V_170 ;
}
#ifdef F_57
for ( V_172 = 0 ; V_172 < V_253 ; V_172 ++ ) {
V_170 = ( char * ) V_9 + V_254 [ V_172 ] . V_249 ;
V_160 [ V_164 ++ ] = ( V_254 [ V_172 ] . V_250 ==
sizeof( T_5 ) ) ? * ( T_5 * ) V_170 : * ( T_1 * ) V_170 ;
}
#endif
F_58 () ;
for ( V_172 = 0 ; V_172 < V_9 -> V_229 ; V_172 ++ ) {
V_242 = F_59 ( V_9 -> V_221 [ V_172 ] ) ;
if ( ! V_242 )
continue;
do {
V_246 = F_60 ( & V_242 -> V_255 ) ;
V_160 [ V_164 ] = V_242 -> V_241 . V_256 ;
V_160 [ V_164 + 1 ] = V_242 -> V_241 . V_179 ;
} while ( F_61 ( & V_242 -> V_255 , V_246 ) );
V_164 += 2 ;
V_243 = & V_242 [ 1 ] ;
do {
V_246 = F_60 ( & V_243 -> V_255 ) ;
V_160 [ V_164 ] = V_243 -> V_241 . V_256 ;
V_160 [ V_164 + 1 ] = V_243 -> V_241 . V_179 ;
} while ( F_61 ( & V_243 -> V_255 , V_246 ) );
V_164 += 2 ;
}
F_62 () ;
if ( V_9 != V_8 -> V_9 [ V_8 -> V_127 ] )
return;
if ( V_8 -> V_237 != V_238 ) {
struct V_257 * V_258 = V_8 -> V_258 [ V_8 -> V_237 ] ;
for ( V_172 = 0 ; V_172 < V_239 ; V_172 ++ ) {
V_170 = ( char * ) V_258 ;
V_170 += V_259 [ V_172 ] . V_249 ;
V_160 [ V_164 ++ ] = ( V_259 [ V_172 ] . V_250 ==
sizeof( T_5 ) ) ? * ( T_5 * ) V_170 : * ( T_1 * ) V_170 ;
}
}
for ( V_172 = 0 ; V_172 < V_260 ; V_172 ++ ) {
V_170 = ( char * ) V_8 + V_261 [ V_172 ] . V_249 ;
V_160 [ V_164 ++ ] = ( V_261 [ V_172 ] . V_250 ==
sizeof( T_5 ) ) ? * ( T_5 * ) V_170 : * ( T_1 * ) V_170 ;
}
for ( V_172 = 0 ; V_172 < V_262 ; V_172 ++ ) {
V_160 [ V_164 ++ ] = V_8 -> V_241 . V_263 [ V_172 ] ;
V_160 [ V_164 ++ ] = V_8 -> V_241 . V_264 [ V_172 ] ;
}
for ( V_172 = 0 ; V_172 < V_262 ; V_172 ++ ) {
V_160 [ V_164 ++ ] = V_8 -> V_241 . V_265 [ V_172 ] ;
V_160 [ V_164 ++ ] = V_8 -> V_241 . V_266 [ V_172 ] ;
}
for ( V_172 = 0 ; V_172 < V_262 ; V_172 ++ )
V_160 [ V_164 ++ ] = V_8 -> V_241 . V_267 [ V_172 ] ;
}
static void F_63 ( struct V_1 * V_2 , T_1 V_268 ,
T_3 * V_160 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_121 * V_9 = V_6 -> V_9 ;
struct V_7 * V_8 = V_9 -> V_10 ;
char * V_170 = ( char * ) V_160 ;
int V_164 ;
switch ( V_268 ) {
case V_234 :
for ( V_164 = 0 ; V_164 < V_235 ; V_164 ++ ) {
memcpy ( V_160 , V_269 [ V_164 ] , V_270 ) ;
V_160 += V_270 ;
}
break;
case V_236 :
for ( V_164 = 0 ; V_164 < V_247 ; V_164 ++ ) {
snprintf ( V_170 , V_270 , L_23 ,
V_248 [ V_164 ] . V_271 ) ;
V_170 += V_270 ;
}
for ( V_164 = 0 ; V_164 < V_251 ; V_164 ++ ) {
snprintf ( V_170 , V_270 , L_23 ,
V_252 [ V_164 ] . V_271 ) ;
V_170 += V_270 ;
}
#ifdef F_57
for ( V_164 = 0 ; V_164 < V_253 ; V_164 ++ ) {
snprintf ( V_170 , V_270 , L_23 ,
V_254 [ V_164 ] . V_271 ) ;
V_170 += V_270 ;
}
#endif
for ( V_164 = 0 ; V_164 < V_9 -> V_229 ; V_164 ++ ) {
snprintf ( V_170 , V_270 , L_24 , V_164 ) ;
V_170 += V_270 ;
snprintf ( V_170 , V_270 , L_25 , V_164 ) ;
V_170 += V_270 ;
snprintf ( V_170 , V_270 , L_26 , V_164 ) ;
V_170 += V_270 ;
snprintf ( V_170 , V_270 , L_27 , V_164 ) ;
V_170 += V_270 ;
}
if ( V_9 != V_8 -> V_9 [ V_8 -> V_127 ] )
return;
if ( V_8 -> V_237 != V_238 ) {
for ( V_164 = 0 ; V_164 < V_239 ; V_164 ++ ) {
snprintf ( V_170 , V_270 , L_28 ,
V_259 [ V_164 ] . V_271 ) ;
V_170 += V_270 ;
}
}
for ( V_164 = 0 ; V_164 < V_260 ; V_164 ++ ) {
snprintf ( V_170 , V_270 , L_29 ,
V_261 [ V_164 ] . V_271 ) ;
V_170 += V_270 ;
}
for ( V_164 = 0 ; V_164 < V_262 ; V_164 ++ ) {
snprintf ( V_170 , V_270 ,
L_30 , V_164 ) ;
V_170 += V_270 ;
snprintf ( V_170 , V_270 ,
L_31 , V_164 ) ;
V_170 += V_270 ;
}
for ( V_164 = 0 ; V_164 < V_262 ; V_164 ++ ) {
snprintf ( V_170 , V_270 ,
L_32 , V_164 ) ;
V_170 += V_270 ;
snprintf ( V_170 , V_270 ,
L_33 , V_164 ) ;
V_170 += V_270 ;
}
for ( V_164 = 0 ; V_164 < V_262 ; V_164 ++ ) {
snprintf ( V_170 , V_270 ,
L_34 , V_164 ) ;
V_170 += V_270 ;
}
break;
}
}
static int F_64 ( struct V_1 * V_190 ,
struct V_272 * V_273 )
{
struct V_7 * V_8 = F_65 ( V_190 ) ;
V_273 -> V_274 = V_275 |
V_276 |
V_277 |
V_278 |
V_279 |
V_280 ;
if ( V_8 -> V_281 )
V_273 -> V_282 = F_66 ( V_8 -> V_281 ) ;
else
V_273 -> V_282 = - 1 ;
V_273 -> V_283 = ( 1 << V_284 ) | ( 1 << V_285 ) ;
V_273 -> V_286 = ( 1 << V_287 ) |
( 1 << V_288 ) |
( 1 << V_289 ) |
( 1 << V_290 ) |
( 1 << V_291 ) |
( 1 << V_292 ) |
( 1 << V_293 ) |
( 1 << V_294 ) |
( 1 << V_295 ) |
( 1 << V_296 ) |
( 1 << V_297 ) |
( 1 << V_298 ) ;
return 0 ;
}
static int F_67 ( struct V_1 * V_2 , T_5 * V_160 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_9 -> V_10 ;
F_68 ( V_8 , V_12 , V_2 , L_35 ) ;
if ( F_69 ( & V_8 -> V_12 ) )
* V_160 = 0 ;
else
* V_160 = 1 ;
return * V_160 ;
}
static int F_70 ( struct V_1 * V_2 , T_5 * V_160 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_9 -> V_10 ;
F_68 ( V_8 , V_12 , V_2 , L_36 ) ;
* V_160 = F_71 ( & V_8 -> V_12 ) ;
return * V_160 ;
}
static int F_72 ( struct V_1 * V_2 , T_5 * V_160 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_9 -> V_10 ;
F_68 ( V_8 , V_12 , V_2 , L_37 ) ;
* V_160 = F_73 ( & V_8 -> V_12 ) ;
return * V_160 ;
}
static int F_74 ( struct V_1 * V_2 , T_5 * V_160 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_9 -> V_10 ;
T_4 V_299 = V_8 -> V_300 ;
F_68 ( V_8 , V_12 , V_2 , L_38 ) ;
F_75 ( & V_8 -> V_12 , V_301 ,
( V_302 |
V_303 ) ) ;
F_7 ( 1000 , 2000 ) ;
* V_160 = ( V_299 == V_8 -> V_300 ) ;
return * V_160 ;
}
static int F_76 ( struct V_1 * V_2 , T_5 * V_160 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_9 -> V_10 ;
F_68 ( V_8 , V_12 , V_2 , L_39 ) ;
* V_160 = 0 ;
return * V_160 ;
}
static void F_77 ( struct V_1 * V_2 ,
struct V_304 * V_305 , T_5 * V_160 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_9 -> V_10 ;
if ( V_305 -> V_306 == V_307 ) {
F_68 ( V_8 , V_308 , V_2 , L_40 ) ;
F_78 ( V_309 , & V_8 -> V_131 ) ;
if ( F_67 ( V_2 , & V_160 [ V_310 ] ) )
V_305 -> V_306 |= V_311 ;
if ( F_72 ( V_2 , & V_160 [ V_312 ] ) )
V_305 -> V_306 |= V_311 ;
if ( F_74 ( V_2 , & V_160 [ V_313 ] ) )
V_305 -> V_306 |= V_311 ;
if ( F_76 ( V_2 , & V_160 [ V_314 ] ) )
V_305 -> V_306 |= V_311 ;
if ( F_70 ( V_2 , & V_160 [ V_315 ] ) )
V_305 -> V_306 |= V_311 ;
F_50 ( V_309 , & V_8 -> V_131 ) ;
F_79 ( V_8 , ( 1 << V_316 ) ) ;
} else {
F_68 ( V_8 , V_308 , V_2 , L_41 ) ;
if ( F_67 ( V_2 , & V_160 [ V_310 ] ) )
V_305 -> V_306 |= V_311 ;
V_160 [ V_315 ] = 0 ;
V_160 [ V_312 ] = 0 ;
V_160 [ V_313 ] = 0 ;
V_160 [ V_314 ] = 0 ;
}
F_68 ( V_8 , V_308 , V_2 , L_42 ) ;
}
static void F_80 ( struct V_1 * V_2 ,
struct V_317 * V_318 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_9 -> V_10 ;
struct V_11 * V_12 = & V_8 -> V_12 ;
T_4 V_319 ;
F_81 ( V_12 , V_320 , & V_319 ) ;
if ( ( 1 << V_12 -> V_83 ) & V_319 ) {
V_318 -> V_24 = 0 ;
V_318 -> V_321 = 0 ;
} else {
V_318 -> V_24 = V_322 ;
V_318 -> V_321 = ( V_8 -> V_323 ? V_322 : 0 ) ;
}
}
static int F_82 ( struct V_1 * V_2 , struct V_317 * V_318 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_9 -> V_10 ;
struct V_11 * V_12 = & V_8 -> V_12 ;
T_4 V_319 ;
F_81 ( V_12 , V_320 , & V_319 ) ;
if ( ( ( 1 << V_12 -> V_83 ) & V_319 ) )
return - V_128 ;
if ( V_318 -> V_321 && ( V_318 -> V_321 != V_322 ) )
return - V_128 ;
if ( V_8 -> V_323 != ! ! V_318 -> V_321 ) {
V_8 -> V_323 = ! ! V_318 -> V_321 ;
F_83 ( & V_8 -> V_189 -> V_190 , V_8 -> V_323 ) ;
}
return 0 ;
}
static int F_84 ( struct V_1 * V_2 ,
enum V_324 V_131 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_9 -> V_10 ;
struct V_11 * V_12 = & V_8 -> V_12 ;
int V_325 = 2 ;
switch ( V_131 ) {
case V_326 :
V_8 -> V_327 = F_85 ( V_12 ) ;
return V_325 ;
case V_328 :
F_86 ( V_12 , 0xF , false ) ;
break;
case V_329 :
F_86 ( V_12 , 0x0 , false ) ;
break;
case V_330 :
F_86 ( V_12 , V_8 -> V_327 , false ) ;
break;
}
return 0 ;
}
static int F_87 ( struct V_1 * V_2 ,
struct V_331 * V_332 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_121 * V_9 = V_6 -> V_9 ;
V_332 -> V_333 = V_9 -> V_334 ;
V_332 -> V_335 = V_9 -> V_334 ;
if ( F_88 ( V_9 -> V_336 ) )
V_332 -> V_337 = 1 ;
if ( F_88 ( V_9 -> V_338 ) )
V_332 -> V_339 = 1 ;
V_332 -> V_340 = V_9 -> V_336 & ~ V_341 ;
V_332 -> V_342 = V_9 -> V_338 & ~ V_341 ;
return 0 ;
}
static int F_89 ( struct V_1 * V_2 ,
struct V_331 * V_332 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_343 * V_344 ;
struct V_121 * V_9 = V_6 -> V_9 ;
struct V_7 * V_8 = V_9 -> V_10 ;
struct V_11 * V_12 = & V_8 -> V_12 ;
T_4 V_345 ;
int V_164 ;
if ( V_332 -> V_333 || V_332 -> V_335 )
V_9 -> V_334 = V_332 -> V_333 ;
V_345 = V_9 -> V_346 ;
if ( ( V_332 -> V_340 >= ( V_347 << 1 ) ) &&
( V_332 -> V_340 <= ( V_348 << 1 ) ) ) {
V_9 -> V_336 = V_332 -> V_340 ;
} else if ( V_332 -> V_340 == 0 ) {
V_9 -> V_336 = V_332 -> V_340 ;
F_90 ( V_9 , V_345 ) ;
if ( V_332 -> V_337 )
F_68 ( V_8 , V_308 , V_2 ,
L_43 ) ;
} else {
F_68 ( V_8 , V_308 , V_2 ,
L_44 ) ;
return - V_133 ;
}
if ( ( V_332 -> V_342 >= ( V_347 << 1 ) ) &&
( V_332 -> V_342 <= ( V_348 << 1 ) ) ) {
V_9 -> V_338 = V_332 -> V_342 ;
} else if ( V_332 -> V_342 == 0 ) {
V_9 -> V_338 = V_332 -> V_342 ;
F_90 ( V_9 , V_345 ) ;
if ( V_332 -> V_339 )
F_68 ( V_8 , V_308 , V_2 ,
L_45 ) ;
} else {
F_68 ( V_8 , V_308 , V_2 ,
L_46 ) ;
return - V_133 ;
}
if ( V_332 -> V_337 )
V_9 -> V_336 |= V_341 ;
else
V_9 -> V_336 &= ~ V_341 ;
if ( V_332 -> V_339 )
V_9 -> V_338 |= V_341 ;
else
V_9 -> V_338 &= ~ V_341 ;
for ( V_164 = 0 ; V_164 < V_9 -> V_349 ; V_164 ++ , V_345 ++ ) {
V_344 = V_9 -> V_350 [ V_164 ] ;
V_344 -> V_351 . V_352 = F_91 ( V_9 -> V_336 ) ;
F_75 ( V_12 , F_92 ( 0 , V_345 - 1 ) , V_344 -> V_351 . V_352 ) ;
V_344 -> V_353 . V_352 = F_91 ( V_9 -> V_338 ) ;
F_75 ( V_12 , F_92 ( 1 , V_345 - 1 ) , V_344 -> V_353 . V_352 ) ;
F_93 ( V_12 ) ;
}
return 0 ;
}
static int F_94 ( struct V_7 * V_8 , struct V_354 * V_129 )
{
V_129 -> V_160 = 0 ;
switch ( V_129 -> V_355 ) {
case V_356 :
case V_357 :
V_129 -> V_160 |= V_358 | V_359 ;
case V_360 :
case V_361 :
case V_362 :
case V_363 :
case V_364 :
V_129 -> V_160 |= V_365 | V_366 ;
break;
case V_367 :
case V_368 :
V_129 -> V_160 |= V_358 | V_359 ;
case V_369 :
case V_370 :
case V_371 :
case V_372 :
case V_373 :
V_129 -> V_160 |= V_365 | V_366 ;
break;
default:
return - V_133 ;
}
return 0 ;
}
static int F_95 ( struct V_7 * V_8 ,
struct V_354 * V_129 ,
T_1 * V_374 )
{
struct V_375 * V_376 ;
struct V_377 * V_378 ;
int V_379 = 0 ;
V_129 -> V_160 = F_96 ( V_8 ) ;
F_97 (rule, node2,
&pf->fdir_filter_list, fdir_node) {
if ( V_379 == V_129 -> V_380 )
return - V_381 ;
V_374 [ V_379 ] = V_376 -> V_382 ;
V_379 ++ ;
}
V_129 -> V_380 = V_379 ;
return 0 ;
}
static int F_98 ( struct V_7 * V_8 ,
struct V_354 * V_129 )
{
struct V_383 * V_384 =
(struct V_383 * ) & V_129 -> V_385 ;
struct V_375 * V_376 = NULL ;
struct V_377 * V_378 ;
F_97 (rule, node2,
&pf->fdir_filter_list, fdir_node) {
if ( V_384 -> V_386 <= V_376 -> V_382 )
break;
}
if ( ! V_376 || V_384 -> V_386 != V_376 -> V_382 )
return - V_133 ;
V_384 -> V_355 = V_376 -> V_355 ;
if ( V_384 -> V_355 == V_387 ) {
V_384 -> V_388 . V_389 . V_390 = V_391 ;
V_384 -> V_388 . V_389 . V_392 = 0 ;
V_384 -> V_393 . V_389 . V_392 = 0 ;
}
V_384 -> V_388 . V_394 . V_395 = V_376 -> V_396 ;
V_384 -> V_388 . V_394 . V_397 = V_376 -> V_398 ;
V_384 -> V_388 . V_394 . V_399 = V_376 -> V_400 [ 0 ] ;
V_384 -> V_388 . V_394 . V_401 = V_376 -> V_402 [ 0 ] ;
if ( V_376 -> V_403 == V_404 )
V_384 -> V_405 = V_406 ;
else
V_384 -> V_405 = V_376 -> V_407 ;
return 0 ;
}
static int F_99 ( struct V_1 * V_2 , struct V_354 * V_129 ,
T_1 * V_374 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_121 * V_9 = V_6 -> V_9 ;
struct V_7 * V_8 = V_9 -> V_10 ;
int V_143 = - V_128 ;
switch ( V_129 -> V_129 ) {
case V_408 :
V_129 -> V_160 = V_9 -> V_231 ;
V_143 = 0 ;
break;
case V_409 :
V_143 = F_94 ( V_8 , V_129 ) ;
break;
case V_410 :
V_129 -> V_380 = V_8 -> V_411 ;
V_129 -> V_160 = F_96 ( V_8 ) ;
V_143 = 0 ;
break;
case V_412 :
V_143 = F_98 ( V_8 , V_129 ) ;
break;
case V_413 :
V_143 = F_95 ( V_8 , V_129 , V_374 ) ;
break;
default:
break;
}
return V_143 ;
}
static int F_100 ( struct V_7 * V_8 , struct V_354 * V_414 )
{
struct V_11 * V_12 = & V_8 -> V_12 ;
T_5 V_415 = ( T_5 ) F_22 ( V_12 , F_101 ( 0 ) ) |
( ( T_5 ) F_22 ( V_12 , F_101 ( 1 ) ) << 32 ) ;
if ( V_414 -> V_160 & ~ ( V_365 | V_366 |
V_358 | V_359 ) )
return - V_133 ;
if ( ! ( V_414 -> V_160 & V_365 ) ||
! ( V_414 -> V_160 & V_366 ) )
return - V_133 ;
switch ( V_414 -> V_355 ) {
case V_356 :
switch ( V_414 -> V_160 & ( V_358 | V_359 ) ) {
case 0 :
V_415 &= ~ ( ( T_5 ) 1 << V_416 ) ;
break;
case ( V_358 | V_359 ) :
V_415 |= ( ( T_5 ) 1 << V_416 ) ;
break;
default:
return - V_133 ;
}
break;
case V_367 :
switch ( V_414 -> V_160 & ( V_358 | V_359 ) ) {
case 0 :
V_415 &= ~ ( ( T_5 ) 1 << V_417 ) ;
break;
case ( V_358 | V_359 ) :
V_415 |= ( ( T_5 ) 1 << V_417 ) ;
break;
default:
return - V_133 ;
}
break;
case V_357 :
switch ( V_414 -> V_160 & ( V_358 | V_359 ) ) {
case 0 :
V_415 &= ~ ( ( ( T_5 ) 1 << V_418 ) |
( ( T_5 ) 1 << V_419 ) ) ;
break;
case ( V_358 | V_359 ) :
V_415 |= ( ( ( T_5 ) 1 << V_418 ) |
( ( T_5 ) 1 << V_419 ) ) ;
break;
default:
return - V_133 ;
}
break;
case V_368 :
switch ( V_414 -> V_160 & ( V_358 | V_359 ) ) {
case 0 :
V_415 &= ~ ( ( ( T_5 ) 1 << V_420 ) |
( ( T_5 ) 1 << V_421 ) ) ;
break;
case ( V_358 | V_359 ) :
V_415 |= ( ( ( T_5 ) 1 << V_420 ) |
( ( T_5 ) 1 << V_421 ) ) ;
break;
default:
return - V_133 ;
}
break;
case V_361 :
case V_362 :
case V_363 :
case V_360 :
if ( ( V_414 -> V_160 & V_358 ) ||
( V_414 -> V_160 & V_359 ) )
return - V_133 ;
V_415 |= ( ( T_5 ) 1 << V_422 ) ;
break;
case V_370 :
case V_371 :
case V_372 :
case V_369 :
if ( ( V_414 -> V_160 & V_358 ) ||
( V_414 -> V_160 & V_359 ) )
return - V_133 ;
V_415 |= ( ( T_5 ) 1 << V_423 ) ;
break;
case V_364 :
V_415 |= ( ( T_5 ) 1 << V_422 ) |
( ( T_5 ) 1 << V_419 ) ;
break;
case V_373 :
V_415 |= ( ( T_5 ) 1 << V_423 ) |
( ( T_5 ) 1 << V_421 ) ;
break;
default:
return - V_133 ;
}
F_75 ( V_12 , F_101 ( 0 ) , ( T_1 ) V_415 ) ;
F_75 ( V_12 , F_101 ( 1 ) , ( T_1 ) ( V_415 >> 32 ) ) ;
F_93 ( V_12 ) ;
return 0 ;
}
static bool F_102 ( struct V_375 * V_376 ,
struct V_375 * V_424 )
{
if ( ( V_376 -> V_400 [ 0 ] != V_424 -> V_400 [ 0 ] ) ||
( V_376 -> V_402 [ 0 ] != V_424 -> V_402 [ 0 ] ) ||
( V_376 -> V_396 != V_424 -> V_396 ) ||
( V_376 -> V_398 != V_424 -> V_398 ) )
return false ;
return true ;
}
static int F_103 ( struct V_121 * V_9 ,
struct V_375 * V_424 ,
T_4 V_425 ,
struct V_354 * V_129 )
{
struct V_375 * V_376 , * V_426 ;
struct V_7 * V_8 = V_9 -> V_10 ;
struct V_377 * V_378 ;
int V_125 = - V_133 ;
V_426 = NULL ;
V_376 = NULL ;
F_97 (rule, node2,
&pf->fdir_filter_list, fdir_node) {
if ( V_376 -> V_382 >= V_425 )
break;
V_426 = V_376 ;
}
if ( V_376 && ( V_376 -> V_382 == V_425 ) ) {
if ( V_424 && ! F_102 ( V_376 , V_424 ) )
V_125 = F_104 ( V_9 , V_376 , false ) ;
else if ( ! V_424 )
V_125 = F_104 ( V_9 , V_376 , false ) ;
F_105 ( & V_376 -> V_427 ) ;
F_31 ( V_376 ) ;
V_8 -> V_411 -- ;
}
if ( ! V_424 )
return V_125 ;
F_106 ( & V_424 -> V_427 ) ;
if ( V_426 )
F_107 ( & V_424 -> V_427 , & V_426 -> V_427 ) ;
else
F_108 ( & V_424 -> V_427 ,
& V_8 -> V_428 ) ;
V_8 -> V_411 ++ ;
return 0 ;
}
static int F_109 ( struct V_121 * V_9 ,
struct V_354 * V_129 )
{
struct V_383 * V_384 =
(struct V_383 * ) & V_129 -> V_385 ;
struct V_7 * V_8 = V_9 -> V_10 ;
int V_143 = 0 ;
if ( F_6 ( V_200 , & V_8 -> V_131 ) ||
F_6 ( V_201 , & V_8 -> V_131 ) )
return - V_202 ;
if ( F_6 ( V_429 , & V_8 -> V_131 ) )
return - V_202 ;
V_143 = F_103 ( V_9 , NULL , V_384 -> V_386 , V_129 ) ;
F_110 ( V_8 ) ;
return V_143 ;
}
static int F_111 ( struct V_121 * V_9 ,
struct V_354 * V_129 )
{
struct V_383 * V_384 ;
struct V_375 * V_424 ;
struct V_7 * V_8 ;
int V_143 = - V_133 ;
if ( ! V_9 )
return - V_133 ;
V_8 = V_9 -> V_10 ;
if ( ! ( V_8 -> V_306 & V_430 ) )
return - V_128 ;
if ( V_8 -> V_431 & V_430 )
return - V_432 ;
if ( F_6 ( V_200 , & V_8 -> V_131 ) ||
F_6 ( V_201 , & V_8 -> V_131 ) )
return - V_202 ;
if ( F_6 ( V_429 , & V_8 -> V_131 ) )
return - V_202 ;
V_384 = (struct V_383 * ) & V_129 -> V_385 ;
if ( V_384 -> V_386 >= ( V_8 -> V_12 . V_433 . V_434 +
V_8 -> V_12 . V_433 . V_435 ) ) {
return - V_133 ;
}
if ( ( V_384 -> V_405 != V_406 ) &&
( V_384 -> V_405 >= V_9 -> V_229 ) )
return - V_133 ;
V_424 = F_27 ( sizeof( * V_424 ) , V_191 ) ;
if ( ! V_424 )
return - V_192 ;
V_424 -> V_382 = V_384 -> V_386 ;
if ( V_384 -> V_405 == V_406 )
V_424 -> V_403 = V_404 ;
else
V_424 -> V_403 =
V_436 ;
V_424 -> V_407 = V_384 -> V_405 ;
V_424 -> V_437 = 0 ;
V_424 -> V_438 = 0 ;
V_424 -> V_439 = V_9 -> V_440 ;
V_424 -> V_441 = V_442 ;
V_424 -> V_443 = V_8 -> V_444 ;
V_424 -> V_355 = V_384 -> V_355 ;
V_424 -> V_445 = V_384 -> V_388 . V_389 . V_392 ;
V_424 -> V_396 = V_384 -> V_388 . V_394 . V_395 ;
V_424 -> V_398 = V_384 -> V_388 . V_394 . V_397 ;
V_424 -> V_400 [ 0 ] = V_384 -> V_388 . V_394 . V_399 ;
V_424 -> V_402 [ 0 ] = V_384 -> V_388 . V_394 . V_401 ;
V_143 = F_104 ( V_9 , V_424 , true ) ;
if ( V_143 )
F_31 ( V_424 ) ;
else
F_103 ( V_9 , V_424 , V_384 -> V_386 , NULL ) ;
return V_143 ;
}
static int F_112 ( struct V_1 * V_2 , struct V_354 * V_129 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_121 * V_9 = V_6 -> V_9 ;
struct V_7 * V_8 = V_9 -> V_10 ;
int V_143 = - V_128 ;
switch ( V_129 -> V_129 ) {
case V_446 :
V_143 = F_100 ( V_8 , V_129 ) ;
break;
case V_447 :
V_143 = F_111 ( V_9 , V_129 ) ;
break;
case V_448 :
V_143 = F_109 ( V_9 , V_129 ) ;
break;
default:
break;
}
return V_143 ;
}
static unsigned int F_113 ( struct V_121 * V_9 )
{
return V_9 -> V_231 ;
}
static void F_114 ( struct V_1 * V_190 ,
struct V_449 * V_450 )
{
struct V_5 * V_6 = F_2 ( V_190 ) ;
struct V_121 * V_9 = V_6 -> V_9 ;
struct V_7 * V_8 = V_9 -> V_10 ;
V_450 -> V_451 = F_113 ( V_9 ) ;
V_450 -> V_452 = ( V_8 -> V_306 & V_430 ) ? 1 : 0 ;
V_450 -> V_453 = V_450 -> V_452 ;
V_450 -> V_454 = V_9 -> V_229 ;
}
static int F_115 ( struct V_1 * V_190 ,
struct V_449 * V_450 )
{
struct V_5 * V_6 = F_2 ( V_190 ) ;
unsigned int V_219 = V_450 -> V_454 ;
struct V_121 * V_9 = V_6 -> V_9 ;
struct V_7 * V_8 = V_9 -> V_10 ;
int V_455 ;
if ( V_9 -> type != V_456 )
return - V_133 ;
if ( ! V_219 || V_450 -> V_457 || V_450 -> V_458 )
return - V_133 ;
if ( V_450 -> V_452 != ( ( V_8 -> V_306 & V_430 ) ? 1 : 0 ) )
return - V_133 ;
if ( V_219 > F_113 ( V_9 ) )
return - V_133 ;
if ( V_219 > V_8 -> V_459 )
V_219 = V_8 -> V_459 ;
V_455 = F_116 ( V_8 , V_219 ) ;
if ( V_455 > 0 )
return 0 ;
else
return - V_133 ;
}
void F_117 ( struct V_1 * V_2 )
{
V_2 -> V_460 = & V_461 ;
}
