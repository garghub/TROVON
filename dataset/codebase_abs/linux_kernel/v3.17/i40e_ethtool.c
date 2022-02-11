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
V_4 -> V_24 = V_38 ;
break;
case V_59 :
case V_60 :
case V_61 :
V_4 -> V_24 = V_46 |
V_38 ;
V_4 -> V_28 = V_47 |
V_40 ;
break;
case V_62 :
case V_63 :
case V_64 :
case V_65 :
V_4 -> V_24 = V_38 ;
break;
case V_66 :
case V_67 :
V_4 -> V_24 = V_46 |
V_39 ;
V_4 -> V_28 = V_47 |
V_41 ;
break;
case V_68 :
V_4 -> V_24 = V_46 |
V_69 ;
V_4 -> V_28 = V_47 |
V_70 ;
break;
case V_71 :
V_4 -> V_24 = V_46 |
V_39 |
V_69 ;
V_4 -> V_28 = V_47 |
V_41 |
V_70 ;
break;
default:
F_3 ( V_17 ) ;
}
V_42:
V_4 -> V_72 = ( ( V_14 -> V_73 & V_74 ) ?
V_75 : V_76 ) ;
switch ( V_12 -> V_15 . V_77 ) {
case V_78 :
V_4 -> V_24 |= V_46 |
V_79 ;
V_4 -> V_28 |= V_47 |
V_80 ;
V_4 -> V_81 = V_82 ;
break;
case V_83 :
V_4 -> V_24 |= V_84 ;
V_4 -> V_28 |= V_85 ;
V_4 -> V_81 = V_86 ;
break;
case V_87 :
case V_88 :
V_4 -> V_24 |= V_89 ;
V_4 -> V_28 |= V_90 ;
V_4 -> V_81 = V_91 ;
break;
case V_92 :
V_4 -> V_24 |= V_89 ;
V_4 -> V_81 = V_93 ;
break;
case V_94 :
default:
V_4 -> V_81 = V_95 ;
break;
}
V_4 -> V_96 = V_97 ;
V_4 -> V_24 |= V_98 ;
switch ( V_12 -> V_99 . V_100 ) {
case V_101 :
V_4 -> V_28 |= V_102 ;
break;
case V_103 :
V_4 -> V_28 |= V_104 ;
break;
case V_105 :
V_4 -> V_28 |= ( V_102 |
V_104 ) ;
break;
default:
V_4 -> V_28 &= ~ ( V_102 |
V_104 ) ;
break;
}
if ( V_17 ) {
switch ( V_19 ) {
case V_106 :
F_4 ( V_4 , 40000 ) ;
break;
case V_107 :
F_4 ( V_4 , V_108 ) ;
break;
case V_109 :
F_4 ( V_4 , V_110 ) ;
break;
default:
break;
}
V_4 -> V_111 = V_112 ;
} else {
F_4 ( V_4 , V_113 ) ;
V_4 -> V_111 = V_114 ;
}
return 0 ;
}
static int F_5 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_115 V_116 ;
struct V_117 V_118 ;
struct V_7 * V_8 = V_6 -> V_9 -> V_10 ;
struct V_119 * V_9 = V_6 -> V_9 ;
struct V_11 * V_12 = & V_8 -> V_12 ;
struct V_3 V_120 ;
T_2 V_121 = 0 ;
bool V_122 = false ;
int V_123 = 0 ;
T_3 V_72 ;
T_1 V_124 ;
if ( V_9 != V_8 -> V_9 [ V_8 -> V_125 ] )
return - V_126 ;
if ( V_12 -> V_15 . V_77 != V_83 &&
V_12 -> V_15 . V_77 != V_92 &&
V_12 -> V_15 . V_77 != V_78 )
return - V_126 ;
memset ( & V_120 , 0 , sizeof( struct V_3 ) ) ;
F_1 ( V_2 , & V_120 ) ;
V_72 = V_4 -> V_72 ;
V_124 = V_4 -> V_28 ;
V_4 -> V_72 = V_120 . V_72 ;
V_4 -> V_28 = V_120 . V_28 ;
V_4 -> V_127 = V_120 . V_127 ;
if ( memcmp ( V_4 , & V_120 , sizeof( struct V_3 ) ) )
return - V_126 ;
while ( F_6 ( V_128 , & V_9 -> V_129 ) )
F_7 ( 1000 , 2000 ) ;
V_121 = F_8 ( V_12 , false , false , & V_116 ,
NULL ) ;
if ( V_121 )
return - V_130 ;
memset ( & V_118 , 0 , sizeof( struct V_117 ) ) ;
V_118 . V_19 = V_116 . V_19 ;
V_118 . V_116 = V_116 . V_116 ;
if ( V_72 == V_75 ) {
if ( ! ( V_120 . V_24 & V_46 ) ) {
F_9 ( V_2 , L_1 ) ;
return - V_131 ;
}
if ( ! ( V_12 -> V_15 . V_16 . V_73 & V_74 ) ) {
V_118 . V_116 = V_116 . V_116 |
V_132 ;
V_122 = true ;
}
} else {
if ( V_120 . V_24 & V_46 &&
V_12 -> V_15 . V_16 . V_43 != V_61 ) {
F_9 ( V_2 , L_2 ) ;
return - V_131 ;
}
if ( V_12 -> V_15 . V_16 . V_73 & V_74 ) {
V_118 . V_116 = V_116 . V_116 |
~ V_132 ;
V_122 = true ;
}
}
if ( V_124 & ~ V_120 . V_24 )
return - V_131 ;
if ( V_124 & V_70 )
if ( ! ( V_116 . V_19 & V_133 ) ) {
V_118 . V_19 |= V_133 ;
V_122 = true ;
}
if ( V_124 & V_41 ||
V_124 & V_134 )
if ( ! ( V_116 . V_19 & V_109 ) ) {
V_118 . V_19 |= V_109 ;
V_122 = true ;
}
if ( V_124 & V_40 ||
V_124 & V_55 ||
V_124 & V_37 )
if ( ! ( V_116 . V_19 & V_107 ) ) {
V_118 . V_19 |= V_107 ;
V_122 = true ;
}
if ( V_124 & V_34 ||
V_124 & V_30 ||
V_124 & V_29 ||
V_124 & V_31 )
if ( ! ( V_116 . V_19 & V_106 ) ) {
V_118 . V_19 |= V_106 ;
V_122 = true ;
}
if ( V_122 ) {
V_118 . V_43 = V_116 . V_43 ;
V_118 . V_135 = V_116 . V_135 ;
V_118 . V_136 = V_116 . V_137 ;
V_118 . V_138 = V_116 . V_139 ;
if ( V_12 -> V_15 . V_16 . V_16 & V_18 )
V_118 . V_116 |= V_140 ;
V_121 = V_117 ( V_12 , & V_118 , NULL ) ;
if ( V_121 ) {
F_9 ( V_2 , L_3 ,
V_121 ) ;
return - V_130 ;
}
V_121 = F_10 ( V_12 , true ) ;
if ( V_121 )
F_9 ( V_2 , L_4 ,
V_121 ) ;
} else {
F_9 ( V_2 , L_5 ) ;
}
return V_123 ;
}
static int F_11 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_9 -> V_10 ;
struct V_11 * V_12 = & V_8 -> V_12 ;
bool V_17 = V_12 -> V_15 . V_16 . V_16 & V_18 ;
T_2 V_141 = 0 ;
V_141 = F_12 ( V_12 , V_17 , NULL ) ;
if ( V_141 ) {
F_9 ( V_2 , L_6 ,
V_8 -> V_12 . V_142 . V_143 ) ;
return - V_144 ;
}
return 0 ;
}
static void F_13 ( struct V_1 * V_2 ,
struct V_145 * V_146 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_9 -> V_10 ;
struct V_11 * V_12 = & V_8 -> V_12 ;
struct V_13 * V_14 = & V_12 -> V_15 . V_16 ;
V_146 -> V_72 =
( ( V_14 -> V_73 & V_74 ) ?
V_75 : V_76 ) ;
if ( V_12 -> V_99 . V_100 == V_105 ) {
V_146 -> V_147 = 1 ;
} else if ( V_12 -> V_99 . V_100 == V_103 ) {
V_146 -> V_148 = 1 ;
} else if ( V_12 -> V_99 . V_100 == V_101 ) {
V_146 -> V_147 = 1 ;
V_146 -> V_148 = 1 ;
}
}
static int F_14 ( struct V_1 * V_2 ,
struct V_145 * V_146 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_9 -> V_10 ;
struct V_119 * V_9 = V_6 -> V_9 ;
struct V_11 * V_12 = & V_8 -> V_12 ;
struct V_13 * V_14 = & V_12 -> V_15 . V_16 ;
bool V_17 = V_14 -> V_16 & V_18 ;
T_2 V_121 ;
T_3 V_149 ;
int V_123 = 0 ;
if ( V_9 != V_8 -> V_9 [ V_8 -> V_125 ] )
return - V_126 ;
if ( V_146 -> V_72 != ( ( V_14 -> V_73 & V_74 ) ?
V_75 : V_76 ) ) {
F_9 ( V_2 , L_7 ) ;
return - V_126 ;
}
if ( ! F_6 ( V_150 , & V_8 -> V_129 ) &&
! ( V_14 -> V_73 & V_74 ) ) {
F_9 ( V_2 , L_8 ) ;
}
if ( V_12 -> V_99 . V_100 == V_151 ) {
F_9 ( V_2 , L_9 ) ;
return - V_126 ;
}
if ( V_146 -> V_147 && V_146 -> V_148 )
V_12 -> V_99 . V_152 = V_101 ;
else if ( V_146 -> V_147 && ! V_146 -> V_148 )
V_12 -> V_99 . V_152 = V_105 ;
else if ( ! V_146 -> V_147 && V_146 -> V_148 )
V_12 -> V_99 . V_152 = V_103 ;
else if ( ! V_146 -> V_147 && ! V_146 -> V_148 )
V_12 -> V_99 . V_152 = V_153 ;
else
return - V_131 ;
V_121 = F_15 ( V_12 , & V_149 , V_17 ) ;
if ( V_149 & V_154 ) {
F_9 ( V_2 , L_10 ,
V_121 , V_12 -> V_142 . V_143 ) ;
V_123 = - V_130 ;
}
if ( V_149 & V_155 ) {
F_9 ( V_2 , L_11 ,
V_121 , V_12 -> V_142 . V_143 ) ;
V_123 = - V_130 ;
}
if ( V_149 & V_156 ) {
F_9 ( V_2 , L_12 ,
V_121 , V_12 -> V_142 . V_143 ) ;
V_123 = - V_130 ;
}
if ( ! F_6 ( V_150 , & V_8 -> V_129 ) ) {
F_16 ( 75 ) ;
if ( ! F_6 ( V_150 , & V_8 -> V_129 ) )
return F_11 ( V_2 ) ;
}
return V_123 ;
}
static T_1 F_17 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_9 -> V_10 ;
return V_8 -> V_157 ;
}
static void F_18 ( struct V_1 * V_2 , T_1 V_158 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_9 -> V_10 ;
if ( V_159 & V_158 )
V_8 -> V_12 . V_160 = V_158 ;
V_8 -> V_157 = V_158 ;
}
static int F_19 ( struct V_1 * V_2 )
{
int V_161 = 0 ;
int V_162 ;
for ( V_162 = 0 ; V_163 [ V_162 ] . V_164 != 0 ; V_162 ++ )
V_161 += V_163 [ V_162 ] . V_165 ;
return V_161 * sizeof( T_1 ) ;
}
static void F_20 ( struct V_1 * V_2 , struct V_166 * V_167 ,
void * V_168 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_9 -> V_10 ;
struct V_11 * V_12 = & V_8 -> V_12 ;
T_1 * V_169 = V_168 ;
int V_162 , V_170 , V_171 ;
T_1 V_172 ;
V_167 -> V_173 = 1 ;
V_171 = 0 ;
for ( V_162 = 0 ; V_163 [ V_162 ] . V_164 != 0 ; V_162 ++ ) {
for ( V_170 = 0 ; V_170 < V_163 [ V_162 ] . V_165 ; V_170 ++ ) {
V_172 = V_163 [ V_162 ] . V_164
+ ( V_170 * V_163 [ V_162 ] . V_174 ) ;
V_169 [ V_171 ++ ] = F_21 ( V_12 , V_172 ) ;
}
}
}
static int F_22 ( struct V_1 * V_2 ,
struct V_175 * V_176 , T_3 * V_177 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_11 * V_12 = & V_6 -> V_9 -> V_10 -> V_12 ;
struct V_7 * V_8 = V_6 -> V_9 -> V_10 ;
int V_178 = 0 , V_179 ;
T_3 * V_180 ;
T_4 V_162 , V_181 ;
bool V_182 ;
T_1 V_183 ;
#define F_23 4096
if ( V_176 -> V_179 == 0 )
return - V_131 ;
V_183 = V_12 -> V_184 | ( V_12 -> V_20 << 16 ) ;
if ( V_176 -> V_183 && V_176 -> V_183 != V_183 ) {
int V_185 ;
if ( ( V_176 -> V_183 >> 16 ) != V_12 -> V_20 )
return - V_131 ;
V_178 = F_24 ( V_12 ,
(struct V_186 * ) V_176 ,
V_177 , & V_185 ) ;
if ( V_178 )
F_25 ( & V_8 -> V_187 -> V_188 ,
L_13 ,
V_178 , V_12 -> V_142 . V_143 ) ;
return V_185 ;
}
V_176 -> V_183 = V_12 -> V_184 | ( V_12 -> V_20 << 16 ) ;
V_180 = F_26 ( V_176 -> V_179 , V_189 ) ;
if ( ! V_180 )
return - V_190 ;
V_178 = F_27 ( V_12 , V_191 ) ;
if ( V_178 ) {
F_25 ( & V_8 -> V_187 -> V_188 ,
L_14 ,
V_178 , V_12 -> V_142 . V_143 ) ;
goto V_192;
}
V_181 = V_176 -> V_179 / F_23 ;
V_181 += ( V_176 -> V_179 % F_23 ) ? 1 : 0 ;
V_179 = F_23 ;
V_182 = false ;
for ( V_162 = 0 ; V_162 < V_181 ; V_162 ++ ) {
if ( V_162 == ( V_181 - 1 ) ) {
V_179 = V_176 -> V_179 - ( F_23 * V_162 ) ;
V_182 = true ;
}
V_178 = F_28 ( V_12 , 0x0 ,
V_176 -> V_164 + ( F_23 * V_162 ) ,
V_179 ,
( T_3 * ) V_180 + ( F_23 * V_162 ) ,
V_182 , NULL ) ;
if ( V_178 ) {
F_25 ( & V_8 -> V_187 -> V_188 ,
L_15 ,
V_178 , V_12 -> V_142 . V_143 ) ;
goto V_193;
}
}
V_193:
F_29 ( V_12 ) ;
memcpy ( V_177 , ( T_3 * ) V_180 , V_176 -> V_179 ) ;
V_192:
F_30 ( V_180 ) ;
return V_178 ;
}
static int F_31 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_11 * V_12 = & V_6 -> V_9 -> V_10 -> V_12 ;
T_1 V_194 ;
V_194 = ( F_21 ( V_12 , V_195 )
& V_196 )
>> V_197 ;
V_194 = ( 64 * 1024 ) * ( 1 << V_194 ) ;
return V_194 ;
}
static int F_32 ( struct V_1 * V_2 ,
struct V_175 * V_176 , T_3 * V_177 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_11 * V_12 = & V_6 -> V_9 -> V_10 -> V_12 ;
struct V_7 * V_8 = V_6 -> V_9 -> V_10 ;
int V_178 = 0 ;
int V_185 ;
T_1 V_183 ;
V_183 = V_12 -> V_184 | ( V_12 -> V_20 << 16 ) ;
if ( V_176 -> V_183 == V_183 )
return - V_126 ;
if ( ! V_176 -> V_183 || ( V_176 -> V_183 >> 16 ) != V_12 -> V_20 )
return - V_131 ;
if ( F_6 ( V_198 , & V_8 -> V_129 ) ||
F_6 ( V_199 , & V_8 -> V_129 ) )
return - V_200 ;
V_178 = F_24 ( V_12 , (struct V_186 * ) V_176 ,
V_177 , & V_185 ) ;
if ( V_178 )
F_25 ( & V_8 -> V_187 -> V_188 ,
L_16 ,
V_178 , V_12 -> V_142 . V_143 ) ;
return V_185 ;
}
static void F_33 ( struct V_1 * V_2 ,
struct V_201 * V_202 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_119 * V_9 = V_6 -> V_9 ;
struct V_7 * V_8 = V_9 -> V_10 ;
F_34 ( V_202 -> V_203 , V_204 , sizeof( V_202 -> V_203 ) ) ;
F_34 ( V_202 -> V_173 , V_205 ,
sizeof( V_202 -> V_173 ) ) ;
F_34 ( V_202 -> V_206 , F_35 ( & V_8 -> V_12 ) ,
sizeof( V_202 -> V_206 ) ) ;
F_34 ( V_202 -> V_207 , F_36 ( V_8 -> V_187 ) ,
sizeof( V_202 -> V_207 ) ) ;
}
static void F_37 ( struct V_1 * V_2 ,
struct V_208 * V_209 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_9 -> V_10 ;
struct V_119 * V_9 = V_8 -> V_9 [ V_8 -> V_125 ] ;
V_209 -> V_210 = V_211 ;
V_209 -> V_212 = V_211 ;
V_209 -> V_213 = 0 ;
V_209 -> V_214 = 0 ;
V_209 -> V_215 = V_9 -> V_216 [ 0 ] -> V_217 ;
V_209 -> V_218 = V_9 -> V_219 [ 0 ] -> V_217 ;
V_209 -> V_220 = 0 ;
V_209 -> V_221 = 0 ;
}
static int F_38 ( struct V_1 * V_2 ,
struct V_208 * V_209 )
{
struct V_222 * V_219 = NULL , * V_216 = NULL ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_119 * V_9 = V_6 -> V_9 ;
struct V_7 * V_8 = V_9 -> V_10 ;
T_1 V_223 , V_224 ;
int V_162 , V_123 = 0 ;
if ( ( V_209 -> V_220 ) || ( V_209 -> V_221 ) )
return - V_131 ;
if ( V_209 -> V_218 > V_211 ||
V_209 -> V_218 < V_225 ||
V_209 -> V_215 > V_211 ||
V_209 -> V_215 < V_225 ) {
F_9 ( V_2 ,
L_17 ,
V_209 -> V_218 , V_209 -> V_215 ,
V_225 , V_211 ) ;
return - V_131 ;
}
V_224 = F_39 ( V_209 -> V_218 , V_226 ) ;
V_223 = F_39 ( V_209 -> V_215 , V_226 ) ;
if ( ( V_224 == V_9 -> V_219 [ 0 ] -> V_217 ) &&
( V_223 == V_9 -> V_216 [ 0 ] -> V_217 ) )
return 0 ;
while ( F_40 ( V_128 , & V_8 -> V_129 ) )
F_7 ( 1000 , 2000 ) ;
if ( ! F_41 ( V_9 -> V_2 ) ) {
for ( V_162 = 0 ; V_162 < V_9 -> V_227 ; V_162 ++ ) {
V_9 -> V_219 [ V_162 ] -> V_217 = V_224 ;
V_9 -> V_216 [ V_162 ] -> V_217 = V_223 ;
}
goto V_228;
}
if ( V_224 != V_9 -> V_219 [ 0 ] -> V_217 ) {
F_9 ( V_2 ,
L_18 ,
V_9 -> V_219 [ 0 ] -> V_217 , V_224 ) ;
V_219 = F_42 ( V_9 -> V_229 ,
sizeof( struct V_222 ) , V_189 ) ;
if ( ! V_219 ) {
V_123 = - V_190 ;
goto V_228;
}
for ( V_162 = 0 ; V_162 < V_9 -> V_227 ; V_162 ++ ) {
V_219 [ V_162 ] = * V_9 -> V_219 [ V_162 ] ;
V_219 [ V_162 ] . V_217 = V_224 ;
V_123 = F_43 ( & V_219 [ V_162 ] ) ;
if ( V_123 ) {
while ( V_162 ) {
V_162 -- ;
F_44 ( & V_219 [ V_162 ] ) ;
}
F_30 ( V_219 ) ;
V_219 = NULL ;
goto V_228;
}
}
}
if ( V_223 != V_9 -> V_216 [ 0 ] -> V_217 ) {
F_9 ( V_2 ,
L_19 ,
V_9 -> V_216 [ 0 ] -> V_217 , V_223 ) ;
V_216 = F_42 ( V_9 -> V_229 ,
sizeof( struct V_222 ) , V_189 ) ;
if ( ! V_216 ) {
V_123 = - V_190 ;
goto V_230;
}
for ( V_162 = 0 ; V_162 < V_9 -> V_227 ; V_162 ++ ) {
V_216 [ V_162 ] = * V_9 -> V_216 [ V_162 ] ;
V_216 [ V_162 ] . V_217 = V_223 ;
V_123 = F_45 ( & V_216 [ V_162 ] ) ;
if ( V_123 ) {
while ( V_162 ) {
V_162 -- ;
F_46 ( & V_216 [ V_162 ] ) ;
}
F_30 ( V_216 ) ;
V_216 = NULL ;
goto V_230;
}
}
}
F_47 ( V_9 ) ;
if ( V_219 ) {
for ( V_162 = 0 ; V_162 < V_9 -> V_227 ; V_162 ++ ) {
F_44 ( V_9 -> V_219 [ V_162 ] ) ;
* V_9 -> V_219 [ V_162 ] = V_219 [ V_162 ] ;
}
F_30 ( V_219 ) ;
V_219 = NULL ;
}
if ( V_216 ) {
for ( V_162 = 0 ; V_162 < V_9 -> V_227 ; V_162 ++ ) {
F_46 ( V_9 -> V_216 [ V_162 ] ) ;
* V_9 -> V_216 [ V_162 ] = V_216 [ V_162 ] ;
}
F_30 ( V_216 ) ;
V_216 = NULL ;
}
F_48 ( V_9 ) ;
V_230:
if ( V_219 ) {
for ( V_162 = 0 ; V_162 < V_9 -> V_227 ; V_162 ++ )
F_44 ( & V_219 [ V_162 ] ) ;
F_30 ( V_219 ) ;
V_219 = NULL ;
}
V_228:
F_49 ( V_128 , & V_8 -> V_129 ) ;
return V_123 ;
}
static int F_50 ( struct V_1 * V_2 , int V_231 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_119 * V_9 = V_6 -> V_9 ;
struct V_7 * V_8 = V_9 -> V_10 ;
switch ( V_231 ) {
case V_232 :
return V_233 ;
case V_234 :
if ( V_9 == V_8 -> V_9 [ V_8 -> V_125 ] ) {
int V_179 = F_51 ( V_2 ) ;
if ( V_8 -> V_235 != V_236 )
V_179 += V_237 ;
return V_179 ;
} else {
return F_52 ( V_2 ) ;
}
default:
return - V_126 ;
}
}
static void F_53 ( struct V_1 * V_2 ,
struct V_238 * V_239 , T_5 * V_158 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_222 * V_240 , * V_241 ;
struct V_119 * V_9 = V_6 -> V_9 ;
struct V_7 * V_8 = V_9 -> V_10 ;
int V_162 = 0 ;
char * V_168 ;
int V_170 ;
struct V_242 * V_243 = F_54 ( V_9 ) ;
unsigned int V_244 ;
F_55 ( V_9 ) ;
for ( V_170 = 0 ; V_170 < V_245 ; V_170 ++ ) {
V_168 = ( char * ) V_243 + V_246 [ V_170 ] . V_247 ;
V_158 [ V_162 ++ ] = ( V_246 [ V_170 ] . V_248 ==
sizeof( T_5 ) ) ? * ( T_5 * ) V_168 : * ( T_1 * ) V_168 ;
}
for ( V_170 = 0 ; V_170 < V_249 ; V_170 ++ ) {
V_168 = ( char * ) V_9 + V_250 [ V_170 ] . V_247 ;
V_158 [ V_162 ++ ] = ( V_250 [ V_170 ] . V_248 ==
sizeof( T_5 ) ) ? * ( T_5 * ) V_168 : * ( T_1 * ) V_168 ;
}
#ifdef F_56
for ( V_170 = 0 ; V_170 < V_251 ; V_170 ++ ) {
V_168 = ( char * ) V_9 + V_252 [ V_170 ] . V_247 ;
V_158 [ V_162 ++ ] = ( V_252 [ V_170 ] . V_248 ==
sizeof( T_5 ) ) ? * ( T_5 * ) V_168 : * ( T_1 * ) V_168 ;
}
#endif
F_57 () ;
for ( V_170 = 0 ; V_170 < V_9 -> V_227 ; V_170 ++ ) {
V_240 = F_58 ( V_9 -> V_219 [ V_170 ] ) ;
if ( ! V_240 )
continue;
do {
V_244 = F_59 ( & V_240 -> V_253 ) ;
V_158 [ V_162 ] = V_240 -> V_239 . V_254 ;
V_158 [ V_162 + 1 ] = V_240 -> V_239 . V_177 ;
} while ( F_60 ( & V_240 -> V_253 , V_244 ) );
V_162 += 2 ;
V_241 = & V_240 [ 1 ] ;
do {
V_244 = F_59 ( & V_241 -> V_253 ) ;
V_158 [ V_162 ] = V_241 -> V_239 . V_254 ;
V_158 [ V_162 + 1 ] = V_241 -> V_239 . V_177 ;
} while ( F_60 ( & V_241 -> V_253 , V_244 ) );
V_162 += 2 ;
}
F_61 () ;
if ( V_9 != V_8 -> V_9 [ V_8 -> V_125 ] )
return;
if ( V_8 -> V_235 != V_236 ) {
struct V_255 * V_256 = V_8 -> V_256 [ V_8 -> V_235 ] ;
for ( V_170 = 0 ; V_170 < V_237 ; V_170 ++ ) {
V_168 = ( char * ) V_256 ;
V_168 += V_257 [ V_170 ] . V_247 ;
V_158 [ V_162 ++ ] = ( V_257 [ V_170 ] . V_248 ==
sizeof( T_5 ) ) ? * ( T_5 * ) V_168 : * ( T_1 * ) V_168 ;
}
}
for ( V_170 = 0 ; V_170 < V_258 ; V_170 ++ ) {
V_168 = ( char * ) V_8 + V_259 [ V_170 ] . V_247 ;
V_158 [ V_162 ++ ] = ( V_259 [ V_170 ] . V_248 ==
sizeof( T_5 ) ) ? * ( T_5 * ) V_168 : * ( T_1 * ) V_168 ;
}
for ( V_170 = 0 ; V_170 < V_260 ; V_170 ++ ) {
V_158 [ V_162 ++ ] = V_8 -> V_239 . V_261 [ V_170 ] ;
V_158 [ V_162 ++ ] = V_8 -> V_239 . V_262 [ V_170 ] ;
}
for ( V_170 = 0 ; V_170 < V_260 ; V_170 ++ ) {
V_158 [ V_162 ++ ] = V_8 -> V_239 . V_263 [ V_170 ] ;
V_158 [ V_162 ++ ] = V_8 -> V_239 . V_264 [ V_170 ] ;
}
for ( V_170 = 0 ; V_170 < V_260 ; V_170 ++ )
V_158 [ V_162 ++ ] = V_8 -> V_239 . V_265 [ V_170 ] ;
}
static void F_62 ( struct V_1 * V_2 , T_1 V_266 ,
T_3 * V_158 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_119 * V_9 = V_6 -> V_9 ;
struct V_7 * V_8 = V_9 -> V_10 ;
char * V_168 = ( char * ) V_158 ;
int V_162 ;
switch ( V_266 ) {
case V_232 :
for ( V_162 = 0 ; V_162 < V_233 ; V_162 ++ ) {
memcpy ( V_158 , V_267 [ V_162 ] , V_268 ) ;
V_158 += V_268 ;
}
break;
case V_234 :
for ( V_162 = 0 ; V_162 < V_245 ; V_162 ++ ) {
snprintf ( V_168 , V_268 , L_20 ,
V_246 [ V_162 ] . V_269 ) ;
V_168 += V_268 ;
}
for ( V_162 = 0 ; V_162 < V_249 ; V_162 ++ ) {
snprintf ( V_168 , V_268 , L_20 ,
V_250 [ V_162 ] . V_269 ) ;
V_168 += V_268 ;
}
#ifdef F_56
for ( V_162 = 0 ; V_162 < V_251 ; V_162 ++ ) {
snprintf ( V_168 , V_268 , L_20 ,
V_252 [ V_162 ] . V_269 ) ;
V_168 += V_268 ;
}
#endif
for ( V_162 = 0 ; V_162 < V_9 -> V_227 ; V_162 ++ ) {
snprintf ( V_168 , V_268 , L_21 , V_162 ) ;
V_168 += V_268 ;
snprintf ( V_168 , V_268 , L_22 , V_162 ) ;
V_168 += V_268 ;
snprintf ( V_168 , V_268 , L_23 , V_162 ) ;
V_168 += V_268 ;
snprintf ( V_168 , V_268 , L_24 , V_162 ) ;
V_168 += V_268 ;
}
if ( V_9 != V_8 -> V_9 [ V_8 -> V_125 ] )
return;
if ( V_8 -> V_235 != V_236 ) {
for ( V_162 = 0 ; V_162 < V_237 ; V_162 ++ ) {
snprintf ( V_168 , V_268 , L_25 ,
V_257 [ V_162 ] . V_269 ) ;
V_168 += V_268 ;
}
}
for ( V_162 = 0 ; V_162 < V_258 ; V_162 ++ ) {
snprintf ( V_168 , V_268 , L_26 ,
V_259 [ V_162 ] . V_269 ) ;
V_168 += V_268 ;
}
for ( V_162 = 0 ; V_162 < V_260 ; V_162 ++ ) {
snprintf ( V_168 , V_268 ,
L_27 , V_162 ) ;
V_168 += V_268 ;
snprintf ( V_168 , V_268 ,
L_28 , V_162 ) ;
V_168 += V_268 ;
}
for ( V_162 = 0 ; V_162 < V_260 ; V_162 ++ ) {
snprintf ( V_168 , V_268 ,
L_29 , V_162 ) ;
V_168 += V_268 ;
snprintf ( V_168 , V_268 ,
L_30 , V_162 ) ;
V_168 += V_268 ;
}
for ( V_162 = 0 ; V_162 < V_260 ; V_162 ++ ) {
snprintf ( V_168 , V_268 ,
L_31 , V_162 ) ;
V_168 += V_268 ;
}
break;
}
}
static int F_63 ( struct V_1 * V_188 ,
struct V_270 * V_271 )
{
struct V_7 * V_8 = F_64 ( V_188 ) ;
V_271 -> V_272 = V_273 |
V_274 |
V_275 |
V_276 |
V_277 |
V_278 ;
if ( V_8 -> V_279 )
V_271 -> V_280 = F_65 ( V_8 -> V_279 ) ;
else
V_271 -> V_280 = - 1 ;
V_271 -> V_281 = ( 1 << V_282 ) | ( 1 << V_283 ) ;
V_271 -> V_284 = ( 1 << V_285 ) |
( 1 << V_286 ) |
( 1 << V_287 ) |
( 1 << V_288 ) |
( 1 << V_289 ) |
( 1 << V_290 ) |
( 1 << V_291 ) |
( 1 << V_292 ) |
( 1 << V_293 ) |
( 1 << V_294 ) |
( 1 << V_295 ) |
( 1 << V_296 ) ;
return 0 ;
}
static int F_66 ( struct V_1 * V_2 , T_5 * V_158 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_9 -> V_10 ;
F_67 ( V_8 , V_12 , V_2 , L_32 ) ;
if ( F_68 ( & V_8 -> V_12 ) )
* V_158 = 0 ;
else
* V_158 = 1 ;
return * V_158 ;
}
static int F_69 ( struct V_1 * V_2 , T_5 * V_158 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_9 -> V_10 ;
F_67 ( V_8 , V_12 , V_2 , L_33 ) ;
* V_158 = F_70 ( & V_8 -> V_12 ) ;
return * V_158 ;
}
static int F_71 ( struct V_1 * V_2 , T_5 * V_158 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_9 -> V_10 ;
F_67 ( V_8 , V_12 , V_2 , L_34 ) ;
* V_158 = F_72 ( & V_8 -> V_12 ) ;
return * V_158 ;
}
static int F_73 ( struct V_1 * V_2 , T_5 * V_158 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_9 -> V_10 ;
T_4 V_297 = V_8 -> V_298 ;
F_67 ( V_8 , V_12 , V_2 , L_35 ) ;
F_74 ( & V_8 -> V_12 , V_299 ,
( V_300 |
V_301 ) ) ;
F_7 ( 1000 , 2000 ) ;
* V_158 = ( V_297 == V_8 -> V_298 ) ;
return * V_158 ;
}
static int F_75 ( struct V_1 * V_2 , T_5 * V_158 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_9 -> V_10 ;
F_67 ( V_8 , V_12 , V_2 , L_36 ) ;
* V_158 = 0 ;
return * V_158 ;
}
static void F_76 ( struct V_1 * V_2 ,
struct V_302 * V_303 , T_5 * V_158 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_9 -> V_10 ;
if ( V_303 -> V_304 == V_305 ) {
F_67 ( V_8 , V_306 , V_2 , L_37 ) ;
F_77 ( V_307 , & V_8 -> V_129 ) ;
if ( F_66 ( V_2 , & V_158 [ V_308 ] ) )
V_303 -> V_304 |= V_309 ;
if ( F_71 ( V_2 , & V_158 [ V_310 ] ) )
V_303 -> V_304 |= V_309 ;
if ( F_73 ( V_2 , & V_158 [ V_311 ] ) )
V_303 -> V_304 |= V_309 ;
if ( F_75 ( V_2 , & V_158 [ V_312 ] ) )
V_303 -> V_304 |= V_309 ;
if ( F_69 ( V_2 , & V_158 [ V_313 ] ) )
V_303 -> V_304 |= V_309 ;
F_49 ( V_307 , & V_8 -> V_129 ) ;
F_78 ( V_8 , ( 1 << V_314 ) ) ;
} else {
F_67 ( V_8 , V_306 , V_2 , L_38 ) ;
if ( F_66 ( V_2 , & V_158 [ V_308 ] ) )
V_303 -> V_304 |= V_309 ;
V_158 [ V_313 ] = 0 ;
V_158 [ V_310 ] = 0 ;
V_158 [ V_311 ] = 0 ;
V_158 [ V_312 ] = 0 ;
}
F_67 ( V_8 , V_306 , V_2 , L_39 ) ;
}
static void F_79 ( struct V_1 * V_2 ,
struct V_315 * V_316 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_9 -> V_10 ;
struct V_11 * V_12 = & V_8 -> V_12 ;
T_4 V_317 ;
F_80 ( V_12 , V_318 , & V_317 ) ;
if ( ( 1 << V_12 -> V_81 ) & V_317 ) {
V_316 -> V_24 = 0 ;
V_316 -> V_319 = 0 ;
} else {
V_316 -> V_24 = V_320 ;
V_316 -> V_319 = ( V_8 -> V_321 ? V_320 : 0 ) ;
}
}
static int F_81 ( struct V_1 * V_2 , struct V_315 * V_316 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_9 -> V_10 ;
struct V_11 * V_12 = & V_8 -> V_12 ;
T_4 V_317 ;
F_80 ( V_12 , V_318 , & V_317 ) ;
if ( ( ( 1 << V_12 -> V_81 ) & V_317 ) )
return - V_126 ;
if ( V_316 -> V_319 && ( V_316 -> V_319 != V_320 ) )
return - V_126 ;
if ( V_8 -> V_321 != ! ! V_316 -> V_319 ) {
V_8 -> V_321 = ! ! V_316 -> V_319 ;
F_82 ( & V_8 -> V_187 -> V_188 , V_8 -> V_321 ) ;
}
return 0 ;
}
static int F_83 ( struct V_1 * V_2 ,
enum V_322 V_129 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_9 -> V_10 ;
struct V_11 * V_12 = & V_8 -> V_12 ;
int V_323 = 2 ;
switch ( V_129 ) {
case V_324 :
V_8 -> V_325 = F_84 ( V_12 ) ;
return V_323 ;
case V_326 :
F_85 ( V_12 , 0xF , false ) ;
break;
case V_327 :
F_85 ( V_12 , 0x0 , false ) ;
break;
case V_328 :
F_85 ( V_12 , V_8 -> V_325 , false ) ;
break;
}
return 0 ;
}
static int F_86 ( struct V_1 * V_2 ,
struct V_329 * V_330 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_119 * V_9 = V_6 -> V_9 ;
V_330 -> V_331 = V_9 -> V_332 ;
V_330 -> V_333 = V_9 -> V_332 ;
if ( F_87 ( V_9 -> V_334 ) )
V_330 -> V_335 = 1 ;
if ( F_87 ( V_9 -> V_336 ) )
V_330 -> V_337 = 1 ;
V_330 -> V_338 = V_9 -> V_334 & ~ V_339 ;
V_330 -> V_340 = V_9 -> V_336 & ~ V_339 ;
return 0 ;
}
static int F_88 ( struct V_1 * V_2 ,
struct V_329 * V_330 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_341 * V_342 ;
struct V_119 * V_9 = V_6 -> V_9 ;
struct V_7 * V_8 = V_9 -> V_10 ;
struct V_11 * V_12 = & V_8 -> V_12 ;
T_4 V_343 ;
int V_162 ;
if ( V_330 -> V_331 || V_330 -> V_333 )
V_9 -> V_332 = V_330 -> V_331 ;
V_343 = V_9 -> V_344 ;
if ( ( V_330 -> V_338 >= ( V_345 << 1 ) ) &&
( V_330 -> V_338 <= ( V_346 << 1 ) ) ) {
V_9 -> V_334 = V_330 -> V_338 ;
} else if ( V_330 -> V_338 == 0 ) {
V_9 -> V_334 = V_330 -> V_338 ;
F_89 ( V_9 , V_343 ) ;
if ( V_330 -> V_335 )
F_67 ( V_8 , V_306 , V_2 ,
L_40 ) ;
} else {
F_67 ( V_8 , V_306 , V_2 ,
L_41 ) ;
return - V_131 ;
}
if ( ( V_330 -> V_340 >= ( V_345 << 1 ) ) &&
( V_330 -> V_340 <= ( V_346 << 1 ) ) ) {
V_9 -> V_336 = V_330 -> V_340 ;
} else if ( V_330 -> V_340 == 0 ) {
V_9 -> V_336 = V_330 -> V_340 ;
F_89 ( V_9 , V_343 ) ;
if ( V_330 -> V_337 )
F_67 ( V_8 , V_306 , V_2 ,
L_42 ) ;
} else {
F_67 ( V_8 , V_306 , V_2 ,
L_43 ) ;
return - V_131 ;
}
if ( V_330 -> V_335 )
V_9 -> V_334 |= V_339 ;
else
V_9 -> V_334 &= ~ V_339 ;
if ( V_330 -> V_337 )
V_9 -> V_336 |= V_339 ;
else
V_9 -> V_336 &= ~ V_339 ;
for ( V_162 = 0 ; V_162 < V_9 -> V_347 ; V_162 ++ , V_343 ++ ) {
V_342 = V_9 -> V_348 [ V_162 ] ;
V_342 -> V_349 . V_350 = F_90 ( V_9 -> V_334 ) ;
F_74 ( V_12 , F_91 ( 0 , V_343 - 1 ) , V_342 -> V_349 . V_350 ) ;
V_342 -> V_351 . V_350 = F_90 ( V_9 -> V_336 ) ;
F_74 ( V_12 , F_91 ( 1 , V_343 - 1 ) , V_342 -> V_351 . V_350 ) ;
F_92 ( V_12 ) ;
}
return 0 ;
}
static int F_93 ( struct V_7 * V_8 , struct V_352 * V_127 )
{
V_127 -> V_158 = 0 ;
switch ( V_127 -> V_353 ) {
case V_354 :
case V_355 :
V_127 -> V_158 |= V_356 | V_357 ;
case V_358 :
case V_359 :
case V_360 :
case V_361 :
case V_362 :
V_127 -> V_158 |= V_363 | V_364 ;
break;
case V_365 :
case V_366 :
V_127 -> V_158 |= V_356 | V_357 ;
case V_367 :
case V_368 :
case V_369 :
case V_370 :
case V_371 :
V_127 -> V_158 |= V_363 | V_364 ;
break;
default:
return - V_131 ;
}
return 0 ;
}
static int F_94 ( struct V_7 * V_8 ,
struct V_352 * V_127 ,
T_1 * V_372 )
{
struct V_373 * V_374 ;
struct V_375 * V_376 ;
int V_377 = 0 ;
V_127 -> V_158 = F_95 ( V_8 ) ;
F_96 (rule, node2,
&pf->fdir_filter_list, fdir_node) {
if ( V_377 == V_127 -> V_378 )
return - V_379 ;
V_372 [ V_377 ] = V_374 -> V_380 ;
V_377 ++ ;
}
V_127 -> V_378 = V_377 ;
return 0 ;
}
static int F_97 ( struct V_7 * V_8 ,
struct V_352 * V_127 )
{
struct V_381 * V_382 =
(struct V_381 * ) & V_127 -> V_383 ;
struct V_373 * V_374 = NULL ;
struct V_375 * V_376 ;
F_96 (rule, node2,
&pf->fdir_filter_list, fdir_node) {
if ( V_382 -> V_384 <= V_374 -> V_380 )
break;
}
if ( ! V_374 || V_382 -> V_384 != V_374 -> V_380 )
return - V_131 ;
V_382 -> V_353 = V_374 -> V_353 ;
if ( V_382 -> V_353 == V_385 ) {
V_382 -> V_386 . V_387 . V_388 = V_389 ;
V_382 -> V_386 . V_387 . V_390 = 0 ;
V_382 -> V_391 . V_387 . V_390 = 0 ;
}
V_382 -> V_386 . V_392 . V_393 = V_374 -> V_394 ;
V_382 -> V_386 . V_392 . V_395 = V_374 -> V_396 ;
V_382 -> V_386 . V_392 . V_397 = V_374 -> V_398 [ 0 ] ;
V_382 -> V_386 . V_392 . V_399 = V_374 -> V_400 [ 0 ] ;
if ( V_374 -> V_401 == V_402 )
V_382 -> V_403 = V_404 ;
else
V_382 -> V_403 = V_374 -> V_405 ;
return 0 ;
}
static int F_98 ( struct V_1 * V_2 , struct V_352 * V_127 ,
T_1 * V_372 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_119 * V_9 = V_6 -> V_9 ;
struct V_7 * V_8 = V_9 -> V_10 ;
int V_141 = - V_126 ;
switch ( V_127 -> V_127 ) {
case V_406 :
V_127 -> V_158 = V_9 -> V_229 ;
V_141 = 0 ;
break;
case V_407 :
V_141 = F_93 ( V_8 , V_127 ) ;
break;
case V_408 :
V_127 -> V_378 = V_8 -> V_409 ;
V_127 -> V_158 = F_95 ( V_8 ) ;
V_141 = 0 ;
break;
case V_410 :
V_141 = F_97 ( V_8 , V_127 ) ;
break;
case V_411 :
V_141 = F_94 ( V_8 , V_127 , V_372 ) ;
break;
default:
break;
}
return V_141 ;
}
static int F_99 ( struct V_7 * V_8 , struct V_352 * V_412 )
{
struct V_11 * V_12 = & V_8 -> V_12 ;
T_5 V_413 = ( T_5 ) F_21 ( V_12 , F_100 ( 0 ) ) |
( ( T_5 ) F_21 ( V_12 , F_100 ( 1 ) ) << 32 ) ;
if ( V_412 -> V_158 & ~ ( V_363 | V_364 |
V_356 | V_357 ) )
return - V_131 ;
if ( ! ( V_412 -> V_158 & V_363 ) ||
! ( V_412 -> V_158 & V_364 ) )
return - V_131 ;
switch ( V_412 -> V_353 ) {
case V_354 :
switch ( V_412 -> V_158 & ( V_356 | V_357 ) ) {
case 0 :
V_413 &= ~ ( ( T_5 ) 1 << V_414 ) ;
break;
case ( V_356 | V_357 ) :
V_413 |= ( ( T_5 ) 1 << V_414 ) ;
break;
default:
return - V_131 ;
}
break;
case V_365 :
switch ( V_412 -> V_158 & ( V_356 | V_357 ) ) {
case 0 :
V_413 &= ~ ( ( T_5 ) 1 << V_415 ) ;
break;
case ( V_356 | V_357 ) :
V_413 |= ( ( T_5 ) 1 << V_415 ) ;
break;
default:
return - V_131 ;
}
break;
case V_355 :
switch ( V_412 -> V_158 & ( V_356 | V_357 ) ) {
case 0 :
V_413 &= ~ ( ( ( T_5 ) 1 << V_416 ) |
( ( T_5 ) 1 << V_417 ) ) ;
break;
case ( V_356 | V_357 ) :
V_413 |= ( ( ( T_5 ) 1 << V_416 ) |
( ( T_5 ) 1 << V_417 ) ) ;
break;
default:
return - V_131 ;
}
break;
case V_366 :
switch ( V_412 -> V_158 & ( V_356 | V_357 ) ) {
case 0 :
V_413 &= ~ ( ( ( T_5 ) 1 << V_418 ) |
( ( T_5 ) 1 << V_419 ) ) ;
break;
case ( V_356 | V_357 ) :
V_413 |= ( ( ( T_5 ) 1 << V_418 ) |
( ( T_5 ) 1 << V_419 ) ) ;
break;
default:
return - V_131 ;
}
break;
case V_359 :
case V_360 :
case V_361 :
case V_358 :
if ( ( V_412 -> V_158 & V_356 ) ||
( V_412 -> V_158 & V_357 ) )
return - V_131 ;
V_413 |= ( ( T_5 ) 1 << V_420 ) ;
break;
case V_368 :
case V_369 :
case V_370 :
case V_367 :
if ( ( V_412 -> V_158 & V_356 ) ||
( V_412 -> V_158 & V_357 ) )
return - V_131 ;
V_413 |= ( ( T_5 ) 1 << V_421 ) ;
break;
case V_362 :
V_413 |= ( ( T_5 ) 1 << V_420 ) |
( ( T_5 ) 1 << V_417 ) ;
break;
case V_371 :
V_413 |= ( ( T_5 ) 1 << V_421 ) |
( ( T_5 ) 1 << V_419 ) ;
break;
default:
return - V_131 ;
}
F_74 ( V_12 , F_100 ( 0 ) , ( T_1 ) V_413 ) ;
F_74 ( V_12 , F_100 ( 1 ) , ( T_1 ) ( V_413 >> 32 ) ) ;
F_92 ( V_12 ) ;
return 0 ;
}
static bool F_101 ( struct V_373 * V_374 ,
struct V_373 * V_422 )
{
if ( ( V_374 -> V_398 [ 0 ] != V_422 -> V_398 [ 0 ] ) ||
( V_374 -> V_400 [ 0 ] != V_422 -> V_400 [ 0 ] ) ||
( V_374 -> V_394 != V_422 -> V_394 ) ||
( V_374 -> V_396 != V_422 -> V_396 ) )
return false ;
return true ;
}
static int F_102 ( struct V_119 * V_9 ,
struct V_373 * V_422 ,
T_4 V_423 ,
struct V_352 * V_127 )
{
struct V_373 * V_374 , * V_424 ;
struct V_7 * V_8 = V_9 -> V_10 ;
struct V_375 * V_376 ;
int V_123 = - V_131 ;
V_424 = NULL ;
V_374 = NULL ;
F_96 (rule, node2,
&pf->fdir_filter_list, fdir_node) {
if ( V_374 -> V_380 >= V_423 )
break;
V_424 = V_374 ;
}
if ( V_374 && ( V_374 -> V_380 == V_423 ) ) {
if ( V_422 && ! F_101 ( V_374 , V_422 ) )
V_123 = F_103 ( V_9 , V_374 , false ) ;
else if ( ! V_422 )
V_123 = F_103 ( V_9 , V_374 , false ) ;
F_104 ( & V_374 -> V_425 ) ;
F_30 ( V_374 ) ;
V_8 -> V_409 -- ;
}
if ( ! V_422 )
return V_123 ;
F_105 ( & V_422 -> V_425 ) ;
if ( V_424 )
F_106 ( & V_422 -> V_425 , & V_424 -> V_425 ) ;
else
F_107 ( & V_422 -> V_425 ,
& V_8 -> V_426 ) ;
V_8 -> V_409 ++ ;
return 0 ;
}
static int F_108 ( struct V_119 * V_9 ,
struct V_352 * V_127 )
{
struct V_381 * V_382 =
(struct V_381 * ) & V_127 -> V_383 ;
struct V_7 * V_8 = V_9 -> V_10 ;
int V_141 = 0 ;
V_141 = F_102 ( V_9 , NULL , V_382 -> V_384 , V_127 ) ;
F_109 ( V_8 ) ;
return V_141 ;
}
static int F_110 ( struct V_119 * V_9 ,
struct V_352 * V_127 )
{
struct V_381 * V_382 ;
struct V_373 * V_422 ;
struct V_7 * V_8 ;
int V_141 = - V_131 ;
if ( ! V_9 )
return - V_131 ;
V_8 = V_9 -> V_10 ;
if ( ! ( V_8 -> V_304 & V_427 ) )
return - V_126 ;
if ( V_8 -> V_428 & V_427 )
return - V_429 ;
V_382 = (struct V_381 * ) & V_127 -> V_383 ;
if ( V_382 -> V_384 >= ( V_8 -> V_12 . V_430 . V_431 +
V_8 -> V_12 . V_430 . V_432 ) ) {
return - V_131 ;
}
if ( ( V_382 -> V_403 != V_404 ) &&
( V_382 -> V_403 >= V_9 -> V_227 ) )
return - V_131 ;
V_422 = F_26 ( sizeof( * V_422 ) , V_189 ) ;
if ( ! V_422 )
return - V_190 ;
V_422 -> V_380 = V_382 -> V_384 ;
if ( V_382 -> V_403 == V_404 )
V_422 -> V_401 = V_402 ;
else
V_422 -> V_401 =
V_433 ;
V_422 -> V_405 = V_382 -> V_403 ;
V_422 -> V_434 = 0 ;
V_422 -> V_435 = 0 ;
V_422 -> V_436 = V_9 -> V_437 ;
V_422 -> V_438 = V_439 ;
V_422 -> V_440 = V_8 -> V_441 ;
V_422 -> V_353 = V_382 -> V_353 ;
V_422 -> V_442 = V_382 -> V_386 . V_387 . V_390 ;
V_422 -> V_394 = V_382 -> V_386 . V_392 . V_393 ;
V_422 -> V_396 = V_382 -> V_386 . V_392 . V_395 ;
V_422 -> V_398 [ 0 ] = V_382 -> V_386 . V_392 . V_397 ;
V_422 -> V_400 [ 0 ] = V_382 -> V_386 . V_392 . V_399 ;
V_141 = F_103 ( V_9 , V_422 , true ) ;
if ( V_141 )
F_30 ( V_422 ) ;
else
F_102 ( V_9 , V_422 , V_382 -> V_384 , NULL ) ;
return V_141 ;
}
static int F_111 ( struct V_1 * V_2 , struct V_352 * V_127 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_119 * V_9 = V_6 -> V_9 ;
struct V_7 * V_8 = V_9 -> V_10 ;
int V_141 = - V_126 ;
switch ( V_127 -> V_127 ) {
case V_443 :
V_141 = F_99 ( V_8 , V_127 ) ;
break;
case V_444 :
V_141 = F_110 ( V_9 , V_127 ) ;
break;
case V_445 :
V_141 = F_108 ( V_9 , V_127 ) ;
break;
default:
break;
}
return V_141 ;
}
static unsigned int F_112 ( struct V_119 * V_9 )
{
return V_9 -> V_229 ;
}
static void F_113 ( struct V_1 * V_188 ,
struct V_446 * V_447 )
{
struct V_5 * V_6 = F_2 ( V_188 ) ;
struct V_119 * V_9 = V_6 -> V_9 ;
struct V_7 * V_8 = V_9 -> V_10 ;
V_447 -> V_448 = F_112 ( V_9 ) ;
V_447 -> V_449 = ( V_8 -> V_304 & V_427 ) ? 1 : 0 ;
V_447 -> V_450 = V_447 -> V_449 ;
V_447 -> V_451 = V_9 -> V_227 ;
}
static int F_114 ( struct V_1 * V_188 ,
struct V_446 * V_447 )
{
struct V_5 * V_6 = F_2 ( V_188 ) ;
unsigned int V_217 = V_447 -> V_451 ;
struct V_119 * V_9 = V_6 -> V_9 ;
struct V_7 * V_8 = V_9 -> V_10 ;
int V_452 ;
if ( V_9 -> type != V_453 )
return - V_131 ;
if ( ! V_217 || V_447 -> V_454 || V_447 -> V_455 )
return - V_131 ;
if ( V_447 -> V_449 != ( ( V_8 -> V_304 & V_427 ) ? 1 : 0 ) )
return - V_131 ;
if ( V_217 > F_112 ( V_9 ) )
return - V_131 ;
if ( V_217 > V_8 -> V_456 )
V_217 = V_8 -> V_456 ;
V_452 = F_115 ( V_8 , V_217 ) ;
if ( V_452 > 0 )
return 0 ;
else
return - V_131 ;
}
void F_116 ( struct V_1 * V_2 )
{
V_2 -> V_457 = & V_458 ;
}
