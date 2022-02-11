static void F_1 ( struct V_1 * V_2 )
{
F_2 ( & V_2 -> V_3 -> V_4 ,
L_1 ) ;
}
static void F_3 ( struct V_5 * V_6 ,
struct V_7 * V_8 ,
struct V_9 * V_10 )
{
struct V_11 * V_12 = & V_6 -> V_13 . V_14 ;
T_1 V_15 = V_12 -> V_15 ;
switch ( V_12 -> V_16 ) {
case V_17 :
case V_18 :
V_8 -> V_19 = V_20 |
V_21 ;
V_8 -> V_22 = V_23 |
V_24 ;
break;
case V_25 :
case V_26 :
case V_27 :
V_8 -> V_19 = V_21 ;
break;
case V_28 :
V_8 -> V_19 = V_20 |
V_29 ;
V_8 -> V_22 = V_23 |
V_30 ;
break;
case V_31 :
V_8 -> V_19 = V_32 ;
break;
case V_33 :
V_8 -> V_19 = V_34 ;
break;
case V_35 :
V_8 -> V_19 = V_20 |
V_36 ;
V_8 -> V_22 = V_23 |
V_37 ;
break;
case V_38 :
V_8 -> V_19 = V_20 |
V_39 ;
V_8 -> V_22 = V_23 |
V_40 ;
break;
case V_41 :
V_8 -> V_19 = V_20 |
V_42 ;
V_8 -> V_22 = V_23 |
V_43 ;
break;
case V_44 :
case V_45 :
case V_46 :
case V_47 :
V_8 -> V_19 = V_48 |
V_49 ;
if ( V_12 -> V_50 & V_51 )
V_8 -> V_22 |= V_52 ;
if ( V_12 -> V_50 & V_53 )
V_8 -> V_22 |= V_54 ;
break;
case V_55 :
V_8 -> V_19 = V_20 |
V_56 ;
V_8 -> V_22 = V_23 |
V_57 ;
break;
case V_58 :
case V_59 :
case V_60 :
V_8 -> V_19 = V_20 |
V_48 |
V_49 |
V_61 ;
V_8 -> V_22 = V_23 ;
if ( V_12 -> V_50 & V_51 )
V_8 -> V_22 |= V_52 ;
if ( V_12 -> V_50 & V_53 )
V_8 -> V_22 |= V_54 ;
if ( V_12 -> V_50 & V_62 )
V_8 -> V_22 |= V_63 ;
break;
case V_64 :
case V_65 :
V_8 -> V_19 = V_20 |
V_48 ;
V_8 -> V_22 = V_23 |
V_52 ;
break;
case V_66 :
case V_67 :
case V_68 :
case V_69 :
case V_70 :
V_8 -> V_19 = V_48 ;
break;
case V_71 :
V_8 -> V_19 = V_20 |
V_49 |
V_61 ;
if ( V_12 -> V_50 & V_53 )
V_8 -> V_22 |= V_54 ;
if ( V_12 -> V_50 & V_62 )
V_8 -> V_22 |= V_63 ;
break;
default:
F_4 ( V_10 , L_2 ,
V_12 -> V_16 ) ;
}
switch ( V_15 ) {
case V_72 :
F_5 ( V_8 , V_73 ) ;
break;
case V_74 :
F_5 ( V_8 , V_75 ) ;
break;
case V_51 :
F_5 ( V_8 , V_76 ) ;
break;
case V_53 :
F_5 ( V_8 , V_77 ) ;
break;
case V_62 :
F_5 ( V_8 , V_78 ) ;
break;
default:
break;
}
V_8 -> V_79 = V_80 ;
}
static void F_6 ( struct V_5 * V_6 ,
struct V_7 * V_8 )
{
struct V_11 * V_12 = & V_6 -> V_13 . V_14 ;
switch ( V_6 -> V_81 ) {
case V_82 :
case V_83 :
case V_84 :
V_8 -> V_19 = V_32 |
V_21 |
V_34 ;
V_8 -> V_22 = V_85 |
V_24 |
V_86 ;
break;
case V_87 :
V_8 -> V_19 = V_29 ;
V_8 -> V_22 = V_30 ;
break;
case V_88 :
V_8 -> V_19 = V_42 ;
V_8 -> V_22 = V_43 ;
break;
case V_89 :
V_8 -> V_19 = V_48 |
V_49 |
V_61 ;
if ( V_12 -> V_50 & V_51 )
V_8 -> V_22 |= V_52 ;
if ( V_12 -> V_50 & V_53 )
V_8 -> V_22 |= V_54 ;
if ( V_12 -> V_50 & V_62 )
V_8 -> V_22 |= V_63 ;
break;
case V_90 :
V_8 -> V_19 = V_36 ;
V_8 -> V_22 = V_37 ;
break;
default:
V_8 -> V_19 = V_48 |
V_49 ;
if ( V_12 -> V_50 & V_51 )
V_8 -> V_22 |= V_52 ;
if ( V_12 -> V_50 & V_53 )
V_8 -> V_22 |= V_54 ;
break;
}
F_5 ( V_8 , V_91 ) ;
V_8 -> V_79 = V_92 ;
}
static int F_7 ( struct V_9 * V_10 ,
struct V_7 * V_8 )
{
struct V_93 * V_94 = F_8 ( V_10 ) ;
struct V_1 * V_2 = V_94 -> V_95 -> V_96 ;
struct V_5 * V_6 = & V_2 -> V_6 ;
struct V_11 * V_12 = & V_6 -> V_13 . V_14 ;
bool V_97 = V_12 -> V_14 & V_98 ;
if ( V_97 )
F_3 ( V_6 , V_8 , V_10 ) ;
else
F_6 ( V_6 , V_8 ) ;
V_8 -> V_99 = ( ( V_12 -> V_100 & V_101 ) ?
V_102 : V_103 ) ;
switch ( V_6 -> V_13 . V_104 ) {
case V_105 :
V_8 -> V_19 |= V_20 |
V_106 ;
V_8 -> V_22 |= V_23 |
V_107 ;
V_8 -> V_108 = V_109 ;
break;
case V_110 :
V_8 -> V_19 |= V_111 ;
V_8 -> V_22 |= V_112 ;
V_8 -> V_108 = V_113 ;
break;
case V_114 :
case V_115 :
V_8 -> V_19 |= V_116 ;
V_8 -> V_22 |= V_117 ;
V_8 -> V_108 = V_118 ;
break;
case V_119 :
V_8 -> V_19 |= V_116 ;
V_8 -> V_108 = V_120 ;
break;
case V_121 :
default:
V_8 -> V_108 = V_122 ;
break;
}
V_8 -> V_123 = V_124 ;
V_8 -> V_19 |= V_125 ;
switch ( V_6 -> V_126 . V_127 ) {
case V_128 :
V_8 -> V_22 |= V_129 ;
break;
case V_130 :
V_8 -> V_22 |= V_131 ;
break;
case V_132 :
V_8 -> V_22 |= ( V_129 |
V_131 ) ;
break;
default:
V_8 -> V_22 &= ~ ( V_129 |
V_131 ) ;
break;
}
return 0 ;
}
static int F_9 ( struct V_9 * V_10 ,
struct V_7 * V_8 )
{
struct V_93 * V_94 = F_8 ( V_10 ) ;
struct V_133 V_134 ;
struct V_135 V_136 ;
struct V_1 * V_2 = V_94 -> V_95 -> V_96 ;
struct V_137 * V_95 = V_94 -> V_95 ;
struct V_5 * V_6 = & V_2 -> V_6 ;
struct V_7 V_138 ;
T_2 V_139 = 0 ;
bool V_140 = false ;
int V_141 = 0 ;
T_3 V_99 ;
T_1 V_142 ;
if ( V_6 -> V_143 != 1 ) {
F_1 ( V_2 ) ;
return - V_144 ;
}
if ( V_95 != V_2 -> V_95 [ V_2 -> V_145 ] )
return - V_144 ;
if ( V_6 -> V_13 . V_104 != V_110 &&
V_6 -> V_13 . V_104 != V_119 &&
V_6 -> V_13 . V_104 != V_105 &&
V_6 -> V_13 . V_14 . V_14 & V_98 )
return - V_144 ;
memset ( & V_138 , 0 , sizeof( struct V_7 ) ) ;
F_7 ( V_10 , & V_138 ) ;
V_99 = V_8 -> V_99 ;
V_142 = V_8 -> V_22 ;
V_8 -> V_99 = V_138 . V_99 ;
V_8 -> V_22 = V_138 . V_22 ;
V_8 -> V_146 = V_138 . V_146 ;
if ( memcmp ( V_8 , & V_138 , sizeof( struct V_7 ) ) )
return - V_144 ;
while ( F_10 ( V_147 , & V_95 -> V_148 ) )
F_11 ( 1000 , 2000 ) ;
V_139 = F_12 ( V_6 , false , false , & V_134 ,
NULL ) ;
if ( V_139 )
return - V_149 ;
memset ( & V_136 , 0 , sizeof( struct V_135 ) ) ;
V_136 . V_134 = V_134 . V_134 ;
if ( V_99 == V_102 ) {
if ( ! ( V_138 . V_19 & V_20 ) ) {
F_4 ( V_10 , L_3 ) ;
return - V_150 ;
}
if ( ! ( V_6 -> V_13 . V_14 . V_100 & V_101 ) ) {
V_136 . V_134 = V_134 . V_134 |
V_151 ;
V_140 = true ;
}
} else {
if ( V_138 . V_19 & V_20 &&
V_6 -> V_13 . V_14 . V_16 != V_58 ) {
F_4 ( V_10 , L_4 ) ;
return - V_150 ;
}
if ( V_6 -> V_13 . V_14 . V_100 & V_101 ) {
V_136 . V_134 = V_134 . V_134 &
~ V_151 ;
V_140 = true ;
}
}
if ( V_142 & ~ V_138 . V_19 )
return - V_150 ;
if ( V_142 & V_63 )
V_136 . V_15 |= V_62 ;
if ( V_142 & V_54 ||
V_142 & V_57 )
V_136 . V_15 |= V_53 ;
if ( V_142 & V_52 ||
V_142 & V_40 ||
V_142 & V_43 )
V_136 . V_15 |= V_51 ;
if ( V_142 & V_37 )
V_136 . V_15 |= V_74 ;
if ( V_142 & V_30 ||
V_142 & V_24 ||
V_142 & V_85 ||
V_142 & V_86 )
V_136 . V_15 |= V_72 ;
if ( V_140 || ( V_134 . V_15 != V_136 . V_15 ) ) {
V_136 . V_16 = V_134 . V_16 ;
V_136 . V_152 = V_134 . V_152 ;
V_136 . V_153 = V_134 . V_154 ;
V_136 . V_155 = V_134 . V_156 ;
V_6 -> V_13 . V_14 . V_50 = V_136 . V_15 ;
V_136 . V_134 |= V_157 ;
if ( V_6 -> V_13 . V_14 . V_14 & V_98 ) {
F_4 ( V_10 , L_5 ) ;
F_13 ( V_10 ) ;
F_14 ( V_10 ) ;
}
V_139 = V_135 ( V_6 , & V_136 , NULL ) ;
if ( V_139 ) {
F_4 ( V_10 , L_6 ,
V_139 ) ;
return - V_149 ;
}
V_139 = F_15 ( V_6 , true , NULL , NULL ) ;
if ( V_139 )
F_4 ( V_10 , L_7 ,
V_139 ) ;
} else {
F_4 ( V_10 , L_8 ) ;
}
return V_141 ;
}
static int F_16 ( struct V_9 * V_10 )
{
struct V_93 * V_94 = F_8 ( V_10 ) ;
struct V_1 * V_2 = V_94 -> V_95 -> V_96 ;
struct V_5 * V_6 = & V_2 -> V_6 ;
bool V_97 = V_6 -> V_13 . V_14 . V_14 & V_98 ;
T_2 V_158 = 0 ;
V_158 = F_17 ( V_6 , V_97 , NULL ) ;
if ( V_158 ) {
F_4 ( V_10 , L_9 ,
V_2 -> V_6 . V_159 . V_160 ) ;
return - V_161 ;
}
return 0 ;
}
static void F_18 ( struct V_9 * V_10 ,
struct V_162 * V_163 )
{
struct V_93 * V_94 = F_8 ( V_10 ) ;
struct V_1 * V_2 = V_94 -> V_95 -> V_96 ;
struct V_5 * V_6 = & V_2 -> V_6 ;
struct V_11 * V_12 = & V_6 -> V_13 . V_14 ;
struct V_164 * V_165 = & V_6 -> V_166 ;
V_163 -> V_99 =
( ( V_12 -> V_100 & V_101 ) ?
V_102 : V_103 ) ;
if ( V_165 -> V_167 . V_168 ) {
V_163 -> V_169 = 0 ;
V_163 -> V_170 = 0 ;
return;
}
if ( V_6 -> V_126 . V_171 == V_132 ) {
V_163 -> V_169 = 1 ;
} else if ( V_6 -> V_126 . V_171 == V_130 ) {
V_163 -> V_170 = 1 ;
} else if ( V_6 -> V_126 . V_171 == V_128 ) {
V_163 -> V_169 = 1 ;
V_163 -> V_170 = 1 ;
}
}
static int F_19 ( struct V_9 * V_10 ,
struct V_162 * V_163 )
{
struct V_93 * V_94 = F_8 ( V_10 ) ;
struct V_1 * V_2 = V_94 -> V_95 -> V_96 ;
struct V_137 * V_95 = V_94 -> V_95 ;
struct V_5 * V_6 = & V_2 -> V_6 ;
struct V_11 * V_12 = & V_6 -> V_13 . V_14 ;
struct V_164 * V_165 = & V_6 -> V_166 ;
bool V_97 = V_12 -> V_14 & V_98 ;
T_2 V_139 ;
T_3 V_172 ;
int V_141 = 0 ;
if ( V_6 -> V_143 != 1 ) {
F_1 ( V_2 ) ;
return - V_144 ;
}
if ( V_95 != V_2 -> V_95 [ V_2 -> V_145 ] )
return - V_144 ;
if ( V_163 -> V_99 != ( ( V_12 -> V_100 & V_101 ) ?
V_102 : V_103 ) ) {
F_4 ( V_10 , L_10 ) ;
return - V_144 ;
}
if ( ! F_10 ( V_173 , & V_2 -> V_148 ) &&
! ( V_12 -> V_100 & V_101 ) ) {
F_4 ( V_10 , L_11 ) ;
}
if ( V_165 -> V_167 . V_168 ) {
F_4 ( V_10 ,
L_12 ) ;
return - V_144 ;
}
if ( V_163 -> V_169 && V_163 -> V_170 )
V_6 -> V_126 . V_127 = V_128 ;
else if ( V_163 -> V_169 && ! V_163 -> V_170 )
V_6 -> V_126 . V_127 = V_132 ;
else if ( ! V_163 -> V_169 && V_163 -> V_170 )
V_6 -> V_126 . V_127 = V_130 ;
else if ( ! V_163 -> V_169 && ! V_163 -> V_170 )
V_6 -> V_126 . V_127 = V_174 ;
else
return - V_150 ;
F_4 ( V_10 , L_13 ) ;
F_13 ( V_10 ) ;
F_14 ( V_10 ) ;
V_139 = F_20 ( V_6 , & V_172 , V_97 ) ;
if ( V_172 & V_175 ) {
F_4 ( V_10 , L_14 ,
V_139 , V_6 -> V_159 . V_160 ) ;
V_141 = - V_149 ;
}
if ( V_172 & V_176 ) {
F_4 ( V_10 , L_15 ,
V_139 , V_6 -> V_159 . V_160 ) ;
V_141 = - V_149 ;
}
if ( V_172 & V_177 ) {
F_4 ( V_10 , L_16 ,
V_139 , V_6 -> V_159 . V_160 ) ;
V_141 = - V_149 ;
}
if ( ! F_10 ( V_173 , & V_2 -> V_148 ) ) {
F_21 ( 75 ) ;
if ( ! F_10 ( V_173 , & V_2 -> V_148 ) )
return F_16 ( V_10 ) ;
}
return V_141 ;
}
static T_1 F_22 ( struct V_9 * V_10 )
{
struct V_93 * V_94 = F_8 ( V_10 ) ;
struct V_1 * V_2 = V_94 -> V_95 -> V_96 ;
return V_2 -> V_178 ;
}
static void F_23 ( struct V_9 * V_10 , T_1 V_179 )
{
struct V_93 * V_94 = F_8 ( V_10 ) ;
struct V_1 * V_2 = V_94 -> V_95 -> V_96 ;
if ( V_180 & V_179 )
V_2 -> V_6 . V_181 = V_179 ;
V_2 -> V_178 = V_179 ;
}
static int F_24 ( struct V_9 * V_10 )
{
int V_182 = 0 ;
int V_183 ;
for ( V_183 = 0 ; V_184 [ V_183 ] . V_185 != 0 ; V_183 ++ )
V_182 += V_184 [ V_183 ] . V_186 ;
return V_182 * sizeof( T_1 ) ;
}
static void F_25 ( struct V_9 * V_10 , struct V_187 * V_188 ,
void * V_189 )
{
struct V_93 * V_94 = F_8 ( V_10 ) ;
struct V_1 * V_2 = V_94 -> V_95 -> V_96 ;
struct V_5 * V_6 = & V_2 -> V_6 ;
T_1 * V_190 = V_189 ;
int V_183 , V_191 , V_192 ;
T_1 V_193 ;
V_188 -> V_194 = 1 ;
V_192 = 0 ;
for ( V_183 = 0 ; V_184 [ V_183 ] . V_185 != 0 ; V_183 ++ ) {
for ( V_191 = 0 ; V_191 < V_184 [ V_183 ] . V_186 ; V_191 ++ ) {
V_193 = V_184 [ V_183 ] . V_185
+ ( V_191 * V_184 [ V_183 ] . V_195 ) ;
V_190 [ V_192 ++ ] = F_26 ( V_6 , V_193 ) ;
}
}
}
static int F_27 ( struct V_9 * V_10 ,
struct V_196 * V_197 , T_3 * V_198 )
{
struct V_93 * V_94 = F_8 ( V_10 ) ;
struct V_5 * V_6 = & V_94 -> V_95 -> V_96 -> V_6 ;
struct V_1 * V_2 = V_94 -> V_95 -> V_96 ;
int V_199 = 0 , V_200 , V_185 ;
T_3 * V_201 ;
T_4 V_183 , V_202 ;
bool V_203 ;
T_1 V_204 ;
#define F_28 4096
if ( V_197 -> V_200 == 0 )
return - V_150 ;
V_204 = V_6 -> V_205 | ( V_6 -> V_81 << 16 ) ;
if ( V_197 -> V_204 && V_197 -> V_204 != V_204 ) {
struct V_206 * V_146 ;
int V_207 ;
if ( ( V_197 -> V_204 >> 16 ) != V_6 -> V_81 )
return - V_150 ;
V_146 = (struct V_206 * ) V_197 ;
V_199 = F_29 ( V_6 , V_146 , V_198 , & V_207 ) ;
if ( V_199 &&
( ( V_6 -> V_159 . V_160 != V_208 ) ||
( V_6 -> V_181 & V_209 ) ) )
F_2 ( & V_2 -> V_3 -> V_4 ,
L_17 ,
V_199 , V_6 -> V_159 . V_160 , V_207 ,
( T_3 ) ( V_146 -> V_136 & V_210 ) ,
V_146 -> V_185 , V_146 -> V_211 ) ;
return V_207 ;
}
V_197 -> V_204 = V_6 -> V_205 | ( V_6 -> V_81 << 16 ) ;
V_201 = F_30 ( V_197 -> V_200 , V_212 ) ;
if ( ! V_201 )
return - V_213 ;
V_199 = F_31 ( V_6 , V_214 ) ;
if ( V_199 ) {
F_2 ( & V_2 -> V_3 -> V_4 ,
L_18 ,
V_199 , V_6 -> V_159 . V_160 ) ;
goto V_215;
}
V_202 = V_197 -> V_200 / F_28 ;
V_202 += ( V_197 -> V_200 % F_28 ) ? 1 : 0 ;
V_200 = F_28 ;
V_203 = false ;
for ( V_183 = 0 ; V_183 < V_202 ; V_183 ++ ) {
if ( V_183 == ( V_202 - 1 ) ) {
V_200 = V_197 -> V_200 - ( F_28 * V_183 ) ;
V_203 = true ;
}
V_185 = V_197 -> V_185 + ( F_28 * V_183 ) ,
V_199 = F_32 ( V_6 , 0x0 , V_185 , V_200 ,
( T_3 * ) V_201 + ( F_28 * V_183 ) ,
V_203 , NULL ) ;
if ( V_199 && V_6 -> V_159 . V_160 == V_216 ) {
F_2 ( & V_2 -> V_3 -> V_4 ,
L_19 ,
V_185 ) ;
break;
} else if ( V_199 &&
V_6 -> V_159 . V_160 == V_208 ) {
F_2 ( & V_2 -> V_3 -> V_4 ,
L_20 ,
V_185 ) ;
break;
} else if ( V_199 ) {
F_2 ( & V_2 -> V_3 -> V_4 ,
L_21 ,
V_185 , V_199 , V_6 -> V_159 . V_160 ) ;
break;
}
}
F_33 ( V_6 ) ;
memcpy ( V_198 , ( T_3 * ) V_201 , V_197 -> V_200 ) ;
V_215:
F_34 ( V_201 ) ;
return V_199 ;
}
static int F_35 ( struct V_9 * V_10 )
{
struct V_93 * V_94 = F_8 ( V_10 ) ;
struct V_5 * V_6 = & V_94 -> V_95 -> V_96 -> V_6 ;
T_1 V_217 ;
V_217 = ( F_26 ( V_6 , V_218 )
& V_219 )
>> V_220 ;
V_217 = ( 64 * 1024 ) * ( 1 << V_217 ) ;
return V_217 ;
}
static int F_36 ( struct V_9 * V_10 ,
struct V_196 * V_197 , T_3 * V_198 )
{
struct V_93 * V_94 = F_8 ( V_10 ) ;
struct V_5 * V_6 = & V_94 -> V_95 -> V_96 -> V_6 ;
struct V_1 * V_2 = V_94 -> V_95 -> V_96 ;
struct V_206 * V_146 ;
int V_199 = 0 ;
int V_207 ;
T_1 V_204 ;
V_204 = V_6 -> V_205 | ( V_6 -> V_81 << 16 ) ;
if ( V_197 -> V_204 == V_204 )
return - V_144 ;
if ( ! V_197 -> V_204 || ( V_197 -> V_204 >> 16 ) != V_6 -> V_81 )
return - V_150 ;
if ( F_10 ( V_221 , & V_2 -> V_148 ) ||
F_10 ( V_222 , & V_2 -> V_148 ) )
return - V_223 ;
V_146 = (struct V_206 * ) V_197 ;
V_199 = F_29 ( V_6 , V_146 , V_198 , & V_207 ) ;
if ( V_199 &&
( ( V_6 -> V_159 . V_160 != V_216 &&
V_6 -> V_159 . V_160 != V_224 ) ||
( V_6 -> V_181 & V_209 ) ) )
F_2 ( & V_2 -> V_3 -> V_4 ,
L_22 ,
V_199 , V_6 -> V_159 . V_160 , V_207 ,
( T_3 ) ( V_146 -> V_136 & V_210 ) ,
V_146 -> V_185 , V_146 -> V_211 ) ;
return V_207 ;
}
static void F_37 ( struct V_9 * V_10 ,
struct V_225 * V_226 )
{
struct V_93 * V_94 = F_8 ( V_10 ) ;
struct V_137 * V_95 = V_94 -> V_95 ;
struct V_1 * V_2 = V_95 -> V_96 ;
F_38 ( V_226 -> V_227 , V_228 , sizeof( V_226 -> V_227 ) ) ;
F_38 ( V_226 -> V_194 , V_229 ,
sizeof( V_226 -> V_194 ) ) ;
F_38 ( V_226 -> V_230 , F_39 ( & V_2 -> V_6 ) ,
sizeof( V_226 -> V_230 ) ) ;
F_38 ( V_226 -> V_231 , F_40 ( V_2 -> V_3 ) ,
sizeof( V_226 -> V_231 ) ) ;
V_226 -> V_232 = V_233 ;
}
static void F_41 ( struct V_9 * V_10 ,
struct V_234 * V_235 )
{
struct V_93 * V_94 = F_8 ( V_10 ) ;
struct V_1 * V_2 = V_94 -> V_95 -> V_96 ;
struct V_137 * V_95 = V_2 -> V_95 [ V_2 -> V_145 ] ;
V_235 -> V_236 = V_237 ;
V_235 -> V_238 = V_237 ;
V_235 -> V_239 = 0 ;
V_235 -> V_240 = 0 ;
V_235 -> V_241 = V_95 -> V_242 [ 0 ] -> V_243 ;
V_235 -> V_244 = V_95 -> V_245 [ 0 ] -> V_243 ;
V_235 -> V_246 = 0 ;
V_235 -> V_247 = 0 ;
}
static int F_42 ( struct V_9 * V_10 ,
struct V_234 * V_235 )
{
struct V_248 * V_245 = NULL , * V_242 = NULL ;
struct V_93 * V_94 = F_8 ( V_10 ) ;
struct V_137 * V_95 = V_94 -> V_95 ;
struct V_1 * V_2 = V_95 -> V_96 ;
T_1 V_249 , V_250 ;
int V_183 , V_141 = 0 ;
if ( ( V_235 -> V_246 ) || ( V_235 -> V_247 ) )
return - V_150 ;
if ( V_235 -> V_244 > V_237 ||
V_235 -> V_244 < V_251 ||
V_235 -> V_241 > V_237 ||
V_235 -> V_241 < V_251 ) {
F_4 ( V_10 ,
L_23 ,
V_235 -> V_244 , V_235 -> V_241 ,
V_251 , V_237 ) ;
return - V_150 ;
}
V_250 = F_43 ( V_235 -> V_244 , V_252 ) ;
V_249 = F_43 ( V_235 -> V_241 , V_252 ) ;
if ( ( V_250 == V_95 -> V_245 [ 0 ] -> V_243 ) &&
( V_249 == V_95 -> V_242 [ 0 ] -> V_243 ) )
return 0 ;
while ( F_44 ( V_147 , & V_2 -> V_148 ) )
F_11 ( 1000 , 2000 ) ;
if ( ! F_45 ( V_95 -> V_10 ) ) {
for ( V_183 = 0 ; V_183 < V_95 -> V_253 ; V_183 ++ ) {
V_95 -> V_245 [ V_183 ] -> V_243 = V_250 ;
V_95 -> V_242 [ V_183 ] -> V_243 = V_249 ;
}
goto V_254;
}
if ( V_250 != V_95 -> V_245 [ 0 ] -> V_243 ) {
F_4 ( V_10 ,
L_24 ,
V_95 -> V_245 [ 0 ] -> V_243 , V_250 ) ;
V_245 = F_46 ( V_95 -> V_255 ,
sizeof( struct V_248 ) , V_212 ) ;
if ( ! V_245 ) {
V_141 = - V_213 ;
goto V_254;
}
for ( V_183 = 0 ; V_183 < V_95 -> V_253 ; V_183 ++ ) {
V_245 [ V_183 ] = * V_95 -> V_245 [ V_183 ] ;
V_245 [ V_183 ] . V_243 = V_250 ;
V_141 = F_47 ( & V_245 [ V_183 ] ) ;
if ( V_141 ) {
while ( V_183 ) {
V_183 -- ;
F_48 ( & V_245 [ V_183 ] ) ;
}
F_34 ( V_245 ) ;
V_245 = NULL ;
goto V_254;
}
}
}
if ( V_249 != V_95 -> V_242 [ 0 ] -> V_243 ) {
F_4 ( V_10 ,
L_25 ,
V_95 -> V_242 [ 0 ] -> V_243 , V_249 ) ;
V_242 = F_46 ( V_95 -> V_255 ,
sizeof( struct V_248 ) , V_212 ) ;
if ( ! V_242 ) {
V_141 = - V_213 ;
goto V_256;
}
for ( V_183 = 0 ; V_183 < V_95 -> V_253 ; V_183 ++ ) {
V_242 [ V_183 ] = * V_95 -> V_242 [ V_183 ] ;
V_242 [ V_183 ] . V_243 = V_249 ;
V_141 = F_49 ( & V_242 [ V_183 ] ) ;
if ( V_141 ) {
while ( V_183 ) {
V_183 -- ;
F_50 ( & V_242 [ V_183 ] ) ;
}
F_34 ( V_242 ) ;
V_242 = NULL ;
goto V_256;
}
}
}
F_51 ( V_95 ) ;
if ( V_245 ) {
for ( V_183 = 0 ; V_183 < V_95 -> V_253 ; V_183 ++ ) {
F_48 ( V_95 -> V_245 [ V_183 ] ) ;
* V_95 -> V_245 [ V_183 ] = V_245 [ V_183 ] ;
}
F_34 ( V_245 ) ;
V_245 = NULL ;
}
if ( V_242 ) {
for ( V_183 = 0 ; V_183 < V_95 -> V_253 ; V_183 ++ ) {
F_50 ( V_95 -> V_242 [ V_183 ] ) ;
* V_95 -> V_242 [ V_183 ] = V_242 [ V_183 ] ;
}
F_34 ( V_242 ) ;
V_242 = NULL ;
}
F_52 ( V_95 ) ;
V_256:
if ( V_245 ) {
for ( V_183 = 0 ; V_183 < V_95 -> V_253 ; V_183 ++ )
F_48 ( & V_245 [ V_183 ] ) ;
F_34 ( V_245 ) ;
V_245 = NULL ;
}
V_254:
F_53 ( V_147 , & V_2 -> V_148 ) ;
return V_141 ;
}
static int F_54 ( struct V_9 * V_10 , int V_257 )
{
struct V_93 * V_94 = F_8 ( V_10 ) ;
struct V_137 * V_95 = V_94 -> V_95 ;
struct V_1 * V_2 = V_95 -> V_96 ;
switch ( V_257 ) {
case V_258 :
return V_259 ;
case V_260 :
if ( V_95 == V_2 -> V_95 [ V_2 -> V_145 ] && V_2 -> V_6 . V_143 == 1 ) {
int V_200 = F_55 ( V_10 ) ;
if ( V_2 -> V_261 != V_262 )
V_200 += V_263 ;
return V_200 ;
} else {
return F_56 ( V_10 ) ;
}
case V_264 :
return V_233 ;
default:
return - V_144 ;
}
}
static void F_57 ( struct V_9 * V_10 ,
struct V_265 * V_266 , T_5 * V_179 )
{
struct V_93 * V_94 = F_8 ( V_10 ) ;
struct V_248 * V_267 , * V_268 ;
struct V_137 * V_95 = V_94 -> V_95 ;
struct V_1 * V_2 = V_95 -> V_96 ;
int V_183 = 0 ;
char * V_189 ;
int V_191 ;
struct V_269 * V_270 = F_58 ( V_95 ) ;
unsigned int V_271 ;
F_59 ( V_95 ) ;
for ( V_191 = 0 ; V_191 < V_272 ; V_191 ++ ) {
V_189 = ( char * ) V_270 + V_273 [ V_191 ] . V_274 ;
V_179 [ V_183 ++ ] = ( V_273 [ V_191 ] . V_275 ==
sizeof( T_5 ) ) ? * ( T_5 * ) V_189 : * ( T_1 * ) V_189 ;
}
for ( V_191 = 0 ; V_191 < V_276 ; V_191 ++ ) {
V_189 = ( char * ) V_95 + V_277 [ V_191 ] . V_274 ;
V_179 [ V_183 ++ ] = ( V_277 [ V_191 ] . V_275 ==
sizeof( T_5 ) ) ? * ( T_5 * ) V_189 : * ( T_1 * ) V_189 ;
}
#ifdef F_60
for ( V_191 = 0 ; V_191 < V_278 ; V_191 ++ ) {
V_189 = ( char * ) V_95 + V_279 [ V_191 ] . V_274 ;
V_179 [ V_183 ++ ] = ( V_279 [ V_191 ] . V_275 ==
sizeof( T_5 ) ) ? * ( T_5 * ) V_189 : * ( T_1 * ) V_189 ;
}
#endif
F_61 () ;
for ( V_191 = 0 ; V_191 < V_95 -> V_253 ; V_191 ++ ) {
V_267 = F_62 ( V_95 -> V_245 [ V_191 ] ) ;
if ( ! V_267 )
continue;
do {
V_271 = F_63 ( & V_267 -> V_280 ) ;
V_179 [ V_183 ] = V_267 -> V_266 . V_281 ;
V_179 [ V_183 + 1 ] = V_267 -> V_266 . V_198 ;
} while ( F_64 ( & V_267 -> V_280 , V_271 ) );
V_183 += 2 ;
V_268 = & V_267 [ 1 ] ;
do {
V_271 = F_63 ( & V_268 -> V_280 ) ;
V_179 [ V_183 ] = V_268 -> V_266 . V_281 ;
V_179 [ V_183 + 1 ] = V_268 -> V_266 . V_198 ;
} while ( F_64 ( & V_268 -> V_280 , V_271 ) );
V_183 += 2 ;
}
F_65 () ;
if ( V_95 != V_2 -> V_95 [ V_2 -> V_145 ] || V_2 -> V_6 . V_143 != 1 )
return;
if ( V_2 -> V_261 != V_262 ) {
struct V_282 * V_283 = V_2 -> V_283 [ V_2 -> V_261 ] ;
for ( V_191 = 0 ; V_191 < V_263 ; V_191 ++ ) {
V_189 = ( char * ) V_283 ;
V_189 += V_284 [ V_191 ] . V_274 ;
V_179 [ V_183 ++ ] = ( V_284 [ V_191 ] . V_275 ==
sizeof( T_5 ) ) ? * ( T_5 * ) V_189 : * ( T_1 * ) V_189 ;
}
}
for ( V_191 = 0 ; V_191 < V_285 ; V_191 ++ ) {
V_189 = ( char * ) V_2 + V_286 [ V_191 ] . V_274 ;
V_179 [ V_183 ++ ] = ( V_286 [ V_191 ] . V_275 ==
sizeof( T_5 ) ) ? * ( T_5 * ) V_189 : * ( T_1 * ) V_189 ;
}
for ( V_191 = 0 ; V_191 < V_287 ; V_191 ++ ) {
V_179 [ V_183 ++ ] = V_2 -> V_266 . V_288 [ V_191 ] ;
V_179 [ V_183 ++ ] = V_2 -> V_266 . V_289 [ V_191 ] ;
}
for ( V_191 = 0 ; V_191 < V_287 ; V_191 ++ ) {
V_179 [ V_183 ++ ] = V_2 -> V_266 . V_290 [ V_191 ] ;
V_179 [ V_183 ++ ] = V_2 -> V_266 . V_291 [ V_191 ] ;
}
for ( V_191 = 0 ; V_191 < V_287 ; V_191 ++ )
V_179 [ V_183 ++ ] = V_2 -> V_266 . V_292 [ V_191 ] ;
}
static void F_66 ( struct V_9 * V_10 , T_1 V_293 ,
T_3 * V_179 )
{
struct V_93 * V_94 = F_8 ( V_10 ) ;
struct V_137 * V_95 = V_94 -> V_95 ;
struct V_1 * V_2 = V_95 -> V_96 ;
char * V_189 = ( char * ) V_179 ;
int V_183 ;
switch ( V_293 ) {
case V_258 :
for ( V_183 = 0 ; V_183 < V_259 ; V_183 ++ ) {
memcpy ( V_179 , V_294 [ V_183 ] , V_295 ) ;
V_179 += V_295 ;
}
break;
case V_260 :
for ( V_183 = 0 ; V_183 < V_272 ; V_183 ++ ) {
snprintf ( V_189 , V_295 , L_26 ,
V_273 [ V_183 ] . V_296 ) ;
V_189 += V_295 ;
}
for ( V_183 = 0 ; V_183 < V_276 ; V_183 ++ ) {
snprintf ( V_189 , V_295 , L_26 ,
V_277 [ V_183 ] . V_296 ) ;
V_189 += V_295 ;
}
#ifdef F_60
for ( V_183 = 0 ; V_183 < V_278 ; V_183 ++ ) {
snprintf ( V_189 , V_295 , L_26 ,
V_279 [ V_183 ] . V_296 ) ;
V_189 += V_295 ;
}
#endif
for ( V_183 = 0 ; V_183 < V_95 -> V_253 ; V_183 ++ ) {
snprintf ( V_189 , V_295 , L_27 , V_183 ) ;
V_189 += V_295 ;
snprintf ( V_189 , V_295 , L_28 , V_183 ) ;
V_189 += V_295 ;
snprintf ( V_189 , V_295 , L_29 , V_183 ) ;
V_189 += V_295 ;
snprintf ( V_189 , V_295 , L_30 , V_183 ) ;
V_189 += V_295 ;
}
if ( V_95 != V_2 -> V_95 [ V_2 -> V_145 ] || V_2 -> V_6 . V_143 != 1 )
return;
if ( V_2 -> V_261 != V_262 ) {
for ( V_183 = 0 ; V_183 < V_263 ; V_183 ++ ) {
snprintf ( V_189 , V_295 , L_31 ,
V_284 [ V_183 ] . V_296 ) ;
V_189 += V_295 ;
}
}
for ( V_183 = 0 ; V_183 < V_285 ; V_183 ++ ) {
snprintf ( V_189 , V_295 , L_32 ,
V_286 [ V_183 ] . V_296 ) ;
V_189 += V_295 ;
}
for ( V_183 = 0 ; V_183 < V_287 ; V_183 ++ ) {
snprintf ( V_189 , V_295 ,
L_33 , V_183 ) ;
V_189 += V_295 ;
snprintf ( V_189 , V_295 ,
L_34 , V_183 ) ;
V_189 += V_295 ;
}
for ( V_183 = 0 ; V_183 < V_287 ; V_183 ++ ) {
snprintf ( V_189 , V_295 ,
L_35 , V_183 ) ;
V_189 += V_295 ;
snprintf ( V_189 , V_295 ,
L_36 , V_183 ) ;
V_189 += V_295 ;
}
for ( V_183 = 0 ; V_183 < V_287 ; V_183 ++ ) {
snprintf ( V_189 , V_295 ,
L_37 , V_183 ) ;
V_189 += V_295 ;
}
break;
case V_264 :
for ( V_183 = 0 ; V_183 < V_233 ; V_183 ++ ) {
memcpy ( V_179 , V_297 [ V_183 ] ,
V_295 ) ;
V_179 += V_295 ;
}
break;
default:
break;
}
}
static int F_67 ( struct V_9 * V_4 ,
struct V_298 * V_299 )
{
struct V_1 * V_2 = F_68 ( V_4 ) ;
if ( ! ( V_2 -> V_300 & V_301 ) )
return F_69 ( V_4 , V_299 ) ;
V_299 -> V_302 = V_303 |
V_304 |
V_305 |
V_306 |
V_307 |
V_308 ;
if ( V_2 -> V_309 )
V_299 -> V_310 = F_70 ( V_2 -> V_309 ) ;
else
V_299 -> V_310 = - 1 ;
V_299 -> V_311 = ( 1 << V_312 ) | ( 1 << V_313 ) ;
V_299 -> V_314 = ( 1 << V_315 ) |
( 1 << V_316 ) |
( 1 << V_317 ) |
( 1 << V_318 ) |
( 1 << V_319 ) |
( 1 << V_320 ) |
( 1 << V_321 ) |
( 1 << V_322 ) |
( 1 << V_323 ) |
( 1 << V_324 ) |
( 1 << V_325 ) |
( 1 << V_326 ) ;
return 0 ;
}
static int F_71 ( struct V_9 * V_10 , T_5 * V_179 )
{
struct V_93 * V_94 = F_8 ( V_10 ) ;
struct V_1 * V_2 = V_94 -> V_95 -> V_96 ;
F_72 ( V_2 , V_6 , V_10 , L_38 ) ;
if ( F_73 ( & V_2 -> V_6 ) )
* V_179 = 0 ;
else
* V_179 = 1 ;
return * V_179 ;
}
static int F_74 ( struct V_9 * V_10 , T_5 * V_179 )
{
struct V_93 * V_94 = F_8 ( V_10 ) ;
struct V_1 * V_2 = V_94 -> V_95 -> V_96 ;
F_72 ( V_2 , V_6 , V_10 , L_39 ) ;
* V_179 = F_75 ( & V_2 -> V_6 ) ;
return * V_179 ;
}
static int F_76 ( struct V_9 * V_10 , T_5 * V_179 )
{
struct V_93 * V_94 = F_8 ( V_10 ) ;
struct V_1 * V_2 = V_94 -> V_95 -> V_96 ;
F_72 ( V_2 , V_6 , V_10 , L_40 ) ;
* V_179 = F_77 ( & V_2 -> V_6 ) ;
V_2 -> V_6 . V_327 = V_328 ;
return * V_179 ;
}
static int F_78 ( struct V_9 * V_10 , T_5 * V_179 )
{
struct V_93 * V_94 = F_8 ( V_10 ) ;
struct V_1 * V_2 = V_94 -> V_95 -> V_96 ;
T_4 V_329 = V_2 -> V_330 ;
F_72 ( V_2 , V_6 , V_10 , L_41 ) ;
F_79 ( & V_2 -> V_6 , V_331 ,
( V_332 |
V_333 |
V_334 |
V_335 |
V_336 ) ) ;
F_11 ( 1000 , 2000 ) ;
* V_179 = ( V_329 == V_2 -> V_330 ) ;
return * V_179 ;
}
static int F_80 ( struct V_9 * V_10 , T_5 * V_179 )
{
struct V_93 * V_94 = F_8 ( V_10 ) ;
struct V_1 * V_2 = V_94 -> V_95 -> V_96 ;
F_72 ( V_2 , V_6 , V_10 , L_42 ) ;
* V_179 = 0 ;
return * V_179 ;
}
static void F_81 ( struct V_9 * V_10 ,
struct V_337 * V_338 , T_5 * V_179 )
{
struct V_93 * V_94 = F_8 ( V_10 ) ;
bool V_339 = F_45 ( V_10 ) ;
struct V_1 * V_2 = V_94 -> V_95 -> V_96 ;
if ( V_338 -> V_300 == V_340 ) {
F_72 ( V_2 , V_341 , V_10 , L_43 ) ;
F_82 ( V_342 , & V_2 -> V_148 ) ;
if ( V_339 )
F_83 ( V_10 ) ;
else
F_84 ( V_2 , ( 1 << V_343 ) ) ;
if ( F_71 ( V_10 , & V_179 [ V_344 ] ) )
V_338 -> V_300 |= V_345 ;
if ( F_76 ( V_10 , & V_179 [ V_346 ] ) )
V_338 -> V_300 |= V_345 ;
if ( F_78 ( V_10 , & V_179 [ V_347 ] ) )
V_338 -> V_300 |= V_345 ;
if ( F_80 ( V_10 , & V_179 [ V_348 ] ) )
V_338 -> V_300 |= V_345 ;
if ( F_74 ( V_10 , & V_179 [ V_349 ] ) )
V_338 -> V_300 |= V_345 ;
F_53 ( V_342 , & V_2 -> V_148 ) ;
F_84 ( V_2 , ( 1 << V_343 ) ) ;
if ( V_339 )
F_85 ( V_10 ) ;
} else {
F_72 ( V_2 , V_341 , V_10 , L_44 ) ;
if ( F_71 ( V_10 , & V_179 [ V_344 ] ) )
V_338 -> V_300 |= V_345 ;
V_179 [ V_349 ] = 0 ;
V_179 [ V_346 ] = 0 ;
V_179 [ V_347 ] = 0 ;
V_179 [ V_348 ] = 0 ;
}
F_72 ( V_2 , V_341 , V_10 , L_45 ) ;
}
static void F_86 ( struct V_9 * V_10 ,
struct V_350 * V_351 )
{
struct V_93 * V_94 = F_8 ( V_10 ) ;
struct V_1 * V_2 = V_94 -> V_95 -> V_96 ;
struct V_5 * V_6 = & V_2 -> V_6 ;
T_4 V_352 ;
F_87 ( V_6 , V_353 , & V_352 ) ;
if ( ( 1 << V_6 -> V_108 ) & V_352 || V_6 -> V_143 != 1 ) {
V_351 -> V_19 = 0 ;
V_351 -> V_354 = 0 ;
} else {
V_351 -> V_19 = V_355 ;
V_351 -> V_354 = ( V_2 -> V_356 ? V_355 : 0 ) ;
}
}
static int F_88 ( struct V_9 * V_10 , struct V_350 * V_351 )
{
struct V_93 * V_94 = F_8 ( V_10 ) ;
struct V_1 * V_2 = V_94 -> V_95 -> V_96 ;
struct V_137 * V_95 = V_94 -> V_95 ;
struct V_5 * V_6 = & V_2 -> V_6 ;
T_4 V_352 ;
if ( V_6 -> V_143 != 1 ) {
F_1 ( V_2 ) ;
return - V_144 ;
}
if ( V_95 != V_2 -> V_95 [ V_2 -> V_145 ] )
return - V_144 ;
F_87 ( V_6 , V_353 , & V_352 ) ;
if ( ( ( 1 << V_6 -> V_108 ) & V_352 ) )
return - V_144 ;
if ( V_351 -> V_354 && ( V_351 -> V_354 != V_355 ) )
return - V_144 ;
if ( V_2 -> V_356 != ! ! V_351 -> V_354 ) {
V_2 -> V_356 = ! ! V_351 -> V_354 ;
F_89 ( & V_2 -> V_3 -> V_4 , V_2 -> V_356 ) ;
}
return 0 ;
}
static int F_90 ( struct V_9 * V_10 ,
enum V_357 V_148 )
{
struct V_93 * V_94 = F_8 ( V_10 ) ;
struct V_1 * V_2 = V_94 -> V_95 -> V_96 ;
struct V_5 * V_6 = & V_2 -> V_6 ;
int V_358 = 2 ;
switch ( V_148 ) {
case V_359 :
V_2 -> V_360 = F_91 ( V_6 ) ;
return V_358 ;
case V_361 :
F_92 ( V_6 , 0xF , false ) ;
break;
case V_362 :
F_92 ( V_6 , 0x0 , false ) ;
break;
case V_363 :
F_92 ( V_6 , V_2 -> V_360 , false ) ;
break;
default:
break;
}
return 0 ;
}
static int F_93 ( struct V_9 * V_10 ,
struct V_364 * V_365 )
{
struct V_93 * V_94 = F_8 ( V_10 ) ;
struct V_137 * V_95 = V_94 -> V_95 ;
V_365 -> V_366 = V_95 -> V_367 ;
V_365 -> V_368 = V_95 -> V_367 ;
if ( F_94 ( V_95 -> V_369 ) )
V_365 -> V_370 = 1 ;
if ( F_94 ( V_95 -> V_371 ) )
V_365 -> V_372 = 1 ;
V_365 -> V_373 = V_95 -> V_369 & ~ V_374 ;
V_365 -> V_375 = V_95 -> V_371 & ~ V_374 ;
return 0 ;
}
static int F_95 ( struct V_9 * V_10 ,
struct V_364 * V_365 )
{
struct V_93 * V_94 = F_8 ( V_10 ) ;
struct V_376 * V_377 ;
struct V_137 * V_95 = V_94 -> V_95 ;
struct V_1 * V_2 = V_95 -> V_96 ;
struct V_5 * V_6 = & V_2 -> V_6 ;
T_4 V_378 ;
int V_183 ;
if ( V_365 -> V_366 || V_365 -> V_368 )
V_95 -> V_367 = V_365 -> V_366 ;
V_378 = V_95 -> V_379 ;
if ( ( V_365 -> V_373 >= ( V_380 << 1 ) ) &&
( V_365 -> V_373 <= ( V_381 << 1 ) ) ) {
V_95 -> V_369 = V_365 -> V_373 ;
} else if ( V_365 -> V_373 == 0 ) {
V_95 -> V_369 = V_365 -> V_373 ;
if ( V_365 -> V_370 )
F_72 ( V_2 , V_341 , V_10 , L_46 ) ;
} else {
F_72 ( V_2 , V_341 , V_10 , L_47 ) ;
return - V_150 ;
}
if ( ( V_365 -> V_375 >= ( V_380 << 1 ) ) &&
( V_365 -> V_375 <= ( V_381 << 1 ) ) ) {
V_95 -> V_371 = V_365 -> V_375 ;
} else if ( V_365 -> V_375 == 0 ) {
V_95 -> V_371 = V_365 -> V_375 ;
if ( V_365 -> V_372 )
F_72 ( V_2 , V_341 , V_10 , L_48 ) ;
} else {
F_72 ( V_2 , V_341 , V_10 ,
L_49 ) ;
return - V_150 ;
}
if ( V_365 -> V_370 )
V_95 -> V_369 |= V_374 ;
else
V_95 -> V_369 &= ~ V_374 ;
if ( V_365 -> V_372 )
V_95 -> V_371 |= V_374 ;
else
V_95 -> V_371 &= ~ V_374 ;
for ( V_183 = 0 ; V_183 < V_95 -> V_382 ; V_183 ++ , V_378 ++ ) {
V_377 = V_95 -> V_383 [ V_183 ] ;
V_377 -> V_384 . V_385 = F_96 ( V_95 -> V_369 ) ;
F_79 ( V_6 , F_97 ( 0 , V_378 - 1 ) , V_377 -> V_384 . V_385 ) ;
V_377 -> V_386 . V_385 = F_96 ( V_95 -> V_371 ) ;
F_79 ( V_6 , F_97 ( 1 , V_378 - 1 ) , V_377 -> V_386 . V_385 ) ;
F_98 ( V_6 ) ;
}
return 0 ;
}
static int F_99 ( struct V_1 * V_2 , struct V_387 * V_146 )
{
V_146 -> V_179 = 0 ;
if ( V_2 -> V_95 [ V_2 -> V_145 ] -> V_388 . V_179 != 0 ) {
V_146 -> V_179 = V_2 -> V_95 [ V_2 -> V_145 ] -> V_388 . V_179 ;
V_146 -> V_389 = V_2 -> V_95 [ V_2 -> V_145 ] -> V_388 . V_389 ;
return 0 ;
}
switch ( V_146 -> V_389 ) {
case V_390 :
case V_391 :
V_146 -> V_179 |= V_392 | V_393 ;
case V_394 :
case V_395 :
case V_396 :
case V_397 :
case V_398 :
V_146 -> V_179 |= V_399 | V_400 ;
break;
case V_401 :
case V_402 :
V_146 -> V_179 |= V_392 | V_393 ;
case V_403 :
case V_404 :
case V_405 :
case V_406 :
case V_407 :
V_146 -> V_179 |= V_399 | V_400 ;
break;
default:
return - V_150 ;
}
return 0 ;
}
static int F_100 ( struct V_1 * V_2 ,
struct V_387 * V_146 ,
T_1 * V_408 )
{
struct V_409 * V_410 ;
struct V_411 * V_412 ;
int V_413 = 0 ;
V_146 -> V_179 = F_101 ( V_2 ) ;
F_102 (rule, node2,
&pf->fdir_filter_list, fdir_node) {
if ( V_413 == V_146 -> V_414 )
return - V_415 ;
V_408 [ V_413 ] = V_410 -> V_416 ;
V_413 ++ ;
}
V_146 -> V_414 = V_413 ;
return 0 ;
}
static int F_103 ( struct V_1 * V_2 ,
struct V_387 * V_146 )
{
struct V_417 * V_418 =
(struct V_417 * ) & V_146 -> V_419 ;
struct V_409 * V_410 = NULL ;
struct V_411 * V_412 ;
F_102 (rule, node2,
&pf->fdir_filter_list, fdir_node) {
if ( V_418 -> V_420 <= V_410 -> V_416 )
break;
}
if ( ! V_410 || V_418 -> V_420 != V_410 -> V_416 )
return - V_150 ;
V_418 -> V_389 = V_410 -> V_389 ;
if ( V_418 -> V_389 == V_421 ) {
V_418 -> V_422 . V_423 . V_424 = V_425 ;
V_418 -> V_422 . V_423 . V_426 = 0 ;
V_418 -> V_427 . V_423 . V_426 = 0 ;
}
V_418 -> V_422 . V_428 . V_429 = V_410 -> V_430 ;
V_418 -> V_422 . V_428 . V_431 = V_410 -> V_432 ;
V_418 -> V_422 . V_428 . V_433 = V_410 -> V_434 [ 0 ] ;
V_418 -> V_422 . V_428 . V_435 = V_410 -> V_436 [ 0 ] ;
if ( V_410 -> V_437 == V_438 )
V_418 -> V_439 = V_440 ;
else
V_418 -> V_439 = V_410 -> V_441 ;
if ( V_410 -> V_442 != V_2 -> V_95 [ V_2 -> V_145 ] -> V_443 ) {
struct V_137 * V_95 ;
V_95 = F_104 ( V_2 , V_410 -> V_442 ) ;
if ( V_95 && V_95 -> type == V_444 ) {
V_418 -> V_445 . V_179 [ 1 ] = F_105 ( V_95 -> V_446 ) ;
V_418 -> V_447 . V_179 [ 1 ] = F_105 ( 0x1 ) ;
}
}
return 0 ;
}
static int F_106 ( struct V_9 * V_10 , struct V_387 * V_146 ,
T_1 * V_408 )
{
struct V_93 * V_94 = F_8 ( V_10 ) ;
struct V_137 * V_95 = V_94 -> V_95 ;
struct V_1 * V_2 = V_95 -> V_96 ;
int V_158 = - V_144 ;
switch ( V_146 -> V_146 ) {
case V_448 :
V_146 -> V_179 = V_95 -> V_255 ;
V_158 = 0 ;
break;
case V_449 :
V_158 = F_99 ( V_2 , V_146 ) ;
break;
case V_450 :
V_146 -> V_414 = V_2 -> V_451 ;
V_146 -> V_179 = F_101 ( V_2 ) ;
V_158 = 0 ;
break;
case V_452 :
V_158 = F_103 ( V_2 , V_146 ) ;
break;
case V_453 :
V_158 = F_100 ( V_2 , V_146 , V_408 ) ;
break;
default:
break;
}
return V_158 ;
}
static int F_107 ( struct V_1 * V_2 , struct V_387 * V_454 )
{
struct V_5 * V_6 = & V_2 -> V_6 ;
T_5 V_455 = ( T_5 ) F_26 ( V_6 , F_108 ( 0 ) ) |
( ( T_5 ) F_26 ( V_6 , F_108 ( 1 ) ) << 32 ) ;
if ( V_454 -> V_179 & ~ ( V_399 | V_400 |
V_392 | V_393 ) )
return - V_150 ;
if ( ! ( V_454 -> V_179 & V_399 ) ||
! ( V_454 -> V_179 & V_400 ) )
return - V_150 ;
switch ( V_454 -> V_389 ) {
case V_390 :
switch ( V_454 -> V_179 & ( V_392 | V_393 ) ) {
case 0 :
V_455 &= ~ ( ( T_5 ) 1 << V_456 ) ;
break;
case ( V_392 | V_393 ) :
V_455 |= ( ( T_5 ) 1 << V_456 ) ;
break;
default:
return - V_150 ;
}
break;
case V_401 :
switch ( V_454 -> V_179 & ( V_392 | V_393 ) ) {
case 0 :
V_455 &= ~ ( ( T_5 ) 1 << V_457 ) ;
break;
case ( V_392 | V_393 ) :
V_455 |= ( ( T_5 ) 1 << V_457 ) ;
break;
default:
return - V_150 ;
}
break;
case V_391 :
switch ( V_454 -> V_179 & ( V_392 | V_393 ) ) {
case 0 :
V_455 &= ~ ( ( ( T_5 ) 1 << V_458 ) |
( ( T_5 ) 1 << V_459 ) ) ;
break;
case ( V_392 | V_393 ) :
V_455 |= ( ( ( T_5 ) 1 << V_458 ) |
( ( T_5 ) 1 << V_459 ) ) ;
break;
default:
return - V_150 ;
}
break;
case V_402 :
switch ( V_454 -> V_179 & ( V_392 | V_393 ) ) {
case 0 :
V_455 &= ~ ( ( ( T_5 ) 1 << V_460 ) |
( ( T_5 ) 1 << V_461 ) ) ;
break;
case ( V_392 | V_393 ) :
V_455 |= ( ( ( T_5 ) 1 << V_460 ) |
( ( T_5 ) 1 << V_461 ) ) ;
break;
default:
return - V_150 ;
}
break;
case V_395 :
case V_396 :
case V_397 :
case V_394 :
if ( ( V_454 -> V_179 & V_392 ) ||
( V_454 -> V_179 & V_393 ) )
return - V_150 ;
V_455 |= ( ( T_5 ) 1 << V_462 ) ;
break;
case V_404 :
case V_405 :
case V_406 :
case V_403 :
if ( ( V_454 -> V_179 & V_392 ) ||
( V_454 -> V_179 & V_393 ) )
return - V_150 ;
V_455 |= ( ( T_5 ) 1 << V_463 ) ;
break;
case V_398 :
V_455 |= ( ( T_5 ) 1 << V_462 ) |
( ( T_5 ) 1 << V_459 ) ;
break;
case V_407 :
V_455 |= ( ( T_5 ) 1 << V_463 ) |
( ( T_5 ) 1 << V_461 ) ;
break;
default:
return - V_150 ;
}
F_79 ( V_6 , F_108 ( 0 ) , ( T_1 ) V_455 ) ;
F_79 ( V_6 , F_108 ( 1 ) , ( T_1 ) ( V_455 >> 32 ) ) ;
F_98 ( V_6 ) ;
V_2 -> V_95 [ V_2 -> V_145 ] -> V_388 = * V_454 ;
return 0 ;
}
static bool F_109 ( struct V_409 * V_410 ,
struct V_409 * V_464 )
{
if ( ( V_410 -> V_434 [ 0 ] != V_464 -> V_434 [ 0 ] ) ||
( V_410 -> V_436 [ 0 ] != V_464 -> V_436 [ 0 ] ) ||
( V_410 -> V_430 != V_464 -> V_430 ) ||
( V_410 -> V_432 != V_464 -> V_432 ) )
return false ;
return true ;
}
static int F_110 ( struct V_137 * V_95 ,
struct V_409 * V_464 ,
T_4 V_465 ,
struct V_387 * V_146 )
{
struct V_409 * V_410 , * V_466 ;
struct V_1 * V_2 = V_95 -> V_96 ;
struct V_411 * V_412 ;
int V_141 = - V_150 ;
V_466 = NULL ;
V_410 = NULL ;
F_102 (rule, node2,
&pf->fdir_filter_list, fdir_node) {
if ( V_410 -> V_416 >= V_465 )
break;
V_466 = V_410 ;
}
if ( V_410 && ( V_410 -> V_416 == V_465 ) ) {
if ( V_464 && ! F_109 ( V_410 , V_464 ) )
V_141 = F_111 ( V_95 , V_410 , false ) ;
else if ( ! V_464 )
V_141 = F_111 ( V_95 , V_410 , false ) ;
F_112 ( & V_410 -> V_467 ) ;
F_34 ( V_410 ) ;
V_2 -> V_451 -- ;
}
if ( ! V_464 )
return V_141 ;
F_113 ( & V_464 -> V_467 ) ;
if ( V_466 )
F_114 ( & V_464 -> V_467 , & V_466 -> V_467 ) ;
else
F_115 ( & V_464 -> V_467 ,
& V_2 -> V_468 ) ;
V_2 -> V_451 ++ ;
return 0 ;
}
static int F_116 ( struct V_137 * V_95 ,
struct V_387 * V_146 )
{
struct V_417 * V_418 =
(struct V_417 * ) & V_146 -> V_419 ;
struct V_1 * V_2 = V_95 -> V_96 ;
int V_158 = 0 ;
if ( F_10 ( V_221 , & V_2 -> V_148 ) ||
F_10 ( V_222 , & V_2 -> V_148 ) )
return - V_223 ;
if ( F_10 ( V_469 , & V_2 -> V_148 ) )
return - V_223 ;
V_158 = F_110 ( V_95 , NULL , V_418 -> V_420 , V_146 ) ;
F_117 ( V_2 ) ;
return V_158 ;
}
static int F_118 ( struct V_137 * V_95 ,
struct V_387 * V_146 )
{
struct V_417 * V_418 ;
struct V_409 * V_464 ;
struct V_1 * V_2 ;
int V_158 = - V_150 ;
T_4 V_446 ;
if ( ! V_95 )
return - V_150 ;
V_2 = V_95 -> V_96 ;
if ( ! ( V_2 -> V_300 & V_470 ) )
return - V_144 ;
if ( V_2 -> V_471 & V_470 )
return - V_472 ;
if ( F_10 ( V_221 , & V_2 -> V_148 ) ||
F_10 ( V_222 , & V_2 -> V_148 ) )
return - V_223 ;
if ( F_10 ( V_469 , & V_2 -> V_148 ) )
return - V_223 ;
V_418 = (struct V_417 * ) & V_146 -> V_419 ;
if ( V_418 -> V_420 >= ( V_2 -> V_6 . V_473 . V_474 +
V_2 -> V_6 . V_473 . V_475 ) ) {
return - V_150 ;
}
if ( ( V_418 -> V_439 != V_440 ) &&
( V_418 -> V_439 >= V_95 -> V_253 ) )
return - V_150 ;
V_464 = F_30 ( sizeof( * V_464 ) , V_212 ) ;
if ( ! V_464 )
return - V_213 ;
V_464 -> V_416 = V_418 -> V_420 ;
if ( V_418 -> V_439 == V_440 )
V_464 -> V_437 = V_438 ;
else
V_464 -> V_437 =
V_476 ;
V_464 -> V_441 = V_418 -> V_439 ;
V_464 -> V_477 = 0 ;
V_464 -> V_478 = 0 ;
V_464 -> V_442 = V_95 -> V_443 ;
V_464 -> V_479 = V_480 ;
V_464 -> V_481 = V_2 -> V_482 ;
V_464 -> V_389 = V_418 -> V_389 ;
V_464 -> V_483 = V_418 -> V_422 . V_423 . V_426 ;
V_464 -> V_430 = V_418 -> V_422 . V_428 . V_429 ;
V_464 -> V_432 = V_418 -> V_422 . V_428 . V_431 ;
V_464 -> V_434 [ 0 ] = V_418 -> V_422 . V_428 . V_433 ;
V_464 -> V_436 [ 0 ] = V_418 -> V_422 . V_428 . V_435 ;
if ( F_119 ( V_418 -> V_447 . V_179 [ 1 ] ) ) {
if ( F_119 ( V_418 -> V_445 . V_179 [ 1 ] ) >= V_2 -> V_484 ) {
F_72 ( V_2 , V_341 , V_95 -> V_10 , L_50 ) ;
goto V_485;
}
V_446 = F_119 ( V_418 -> V_445 . V_179 [ 1 ] ) ;
V_464 -> V_442 = V_2 -> V_486 [ V_446 ] . V_487 ;
if ( V_464 -> V_441 >= V_2 -> V_486 [ V_446 ] . V_253 ) {
F_72 ( V_2 , V_341 , V_95 -> V_10 , L_51 ) ;
goto V_485;
}
}
V_158 = F_111 ( V_95 , V_464 , true ) ;
V_485:
if ( V_158 )
F_34 ( V_464 ) ;
else
F_110 ( V_95 , V_464 , V_418 -> V_420 , NULL ) ;
return V_158 ;
}
static int F_120 ( struct V_9 * V_10 , struct V_387 * V_146 )
{
struct V_93 * V_94 = F_8 ( V_10 ) ;
struct V_137 * V_95 = V_94 -> V_95 ;
struct V_1 * V_2 = V_95 -> V_96 ;
int V_158 = - V_144 ;
switch ( V_146 -> V_146 ) {
case V_488 :
V_158 = F_107 ( V_2 , V_146 ) ;
break;
case V_489 :
V_158 = F_118 ( V_95 , V_146 ) ;
break;
case V_490 :
V_158 = F_116 ( V_95 , V_146 ) ;
break;
default:
break;
}
return V_158 ;
}
static unsigned int F_121 ( struct V_137 * V_95 )
{
return V_95 -> V_255 ;
}
static void F_122 ( struct V_9 * V_4 ,
struct V_491 * V_492 )
{
struct V_93 * V_94 = F_8 ( V_4 ) ;
struct V_137 * V_95 = V_94 -> V_95 ;
struct V_1 * V_2 = V_95 -> V_96 ;
V_492 -> V_493 = F_121 ( V_95 ) ;
V_492 -> V_494 = ( V_2 -> V_300 & V_470 ) ? 1 : 0 ;
V_492 -> V_495 = V_492 -> V_494 ;
V_492 -> V_496 = V_95 -> V_253 ;
}
static int F_123 ( struct V_9 * V_4 ,
struct V_491 * V_492 )
{
struct V_93 * V_94 = F_8 ( V_4 ) ;
unsigned int V_243 = V_492 -> V_496 ;
struct V_137 * V_95 = V_94 -> V_95 ;
struct V_1 * V_2 = V_95 -> V_96 ;
int V_497 ;
if ( V_95 -> type != V_498 )
return - V_150 ;
if ( ! V_243 || V_492 -> V_499 || V_492 -> V_500 )
return - V_150 ;
if ( V_492 -> V_494 != ( ( V_2 -> V_300 & V_470 ) ? 1 : 0 ) )
return - V_150 ;
if ( V_243 > F_121 ( V_95 ) )
return - V_150 ;
V_497 = F_124 ( V_2 , V_243 ) ;
if ( V_497 > 0 )
return 0 ;
else
return - V_150 ;
}
static T_1 F_125 ( struct V_9 * V_10 )
{
return V_501 ;
}
static T_1 F_126 ( struct V_9 * V_10 )
{
return V_502 ;
}
static int F_127 ( struct V_9 * V_10 , T_1 * V_503 , T_3 * V_504 ,
T_3 * V_505 )
{
struct V_93 * V_94 = F_8 ( V_10 ) ;
struct V_137 * V_95 = V_94 -> V_95 ;
struct V_1 * V_2 = V_95 -> V_96 ;
struct V_5 * V_6 = & V_2 -> V_6 ;
T_1 V_506 ;
int V_183 , V_191 ;
if ( V_505 )
* V_505 = V_507 ;
if ( ! V_503 )
return 0 ;
for ( V_183 = 0 , V_191 = 0 ; V_183 <= V_508 ; V_183 ++ ) {
V_506 = F_26 ( V_6 , F_128 ( V_183 ) ) ;
V_503 [ V_191 ++ ] = V_506 & 0xff ;
V_503 [ V_191 ++ ] = ( V_506 >> 8 ) & 0xff ;
V_503 [ V_191 ++ ] = ( V_506 >> 16 ) & 0xff ;
V_503 [ V_191 ++ ] = ( V_506 >> 24 ) & 0xff ;
}
if ( V_504 ) {
for ( V_183 = 0 , V_191 = 0 ; V_183 <= V_509 ; V_183 ++ ) {
V_506 = F_26 ( V_6 , F_129 ( V_183 ) ) ;
V_504 [ V_191 ++ ] = ( T_3 ) ( V_506 & 0xff ) ;
V_504 [ V_191 ++ ] = ( T_3 ) ( ( V_506 >> 8 ) & 0xff ) ;
V_504 [ V_191 ++ ] = ( T_3 ) ( ( V_506 >> 16 ) & 0xff ) ;
V_504 [ V_191 ++ ] = ( T_3 ) ( ( V_506 >> 24 ) & 0xff ) ;
}
}
return 0 ;
}
static int F_130 ( struct V_9 * V_10 , const T_1 * V_503 ,
const T_3 * V_504 , const T_3 V_505 )
{
struct V_93 * V_94 = F_8 ( V_10 ) ;
struct V_137 * V_95 = V_94 -> V_95 ;
struct V_1 * V_2 = V_95 -> V_96 ;
struct V_5 * V_6 = & V_2 -> V_6 ;
T_1 V_506 ;
int V_183 , V_191 ;
if ( V_505 != V_510 && V_505 != V_507 )
return - V_144 ;
if ( ! V_503 )
return 0 ;
for ( V_183 = 0 , V_191 = 0 ; V_183 <= V_508 ; V_183 ++ ) {
V_506 = V_503 [ V_191 ++ ] ;
V_506 |= V_503 [ V_191 ++ ] << 8 ;
V_506 |= V_503 [ V_191 ++ ] << 16 ;
V_506 |= V_503 [ V_191 ++ ] << 24 ;
F_79 ( V_6 , F_128 ( V_183 ) , V_506 ) ;
}
if ( V_504 ) {
for ( V_183 = 0 , V_191 = 0 ; V_183 <= V_509 ; V_183 ++ ) {
V_506 = V_504 [ V_191 ++ ] ;
V_506 |= V_504 [ V_191 ++ ] << 8 ;
V_506 |= V_504 [ V_191 ++ ] << 16 ;
V_506 |= V_504 [ V_191 ++ ] << 24 ;
F_79 ( V_6 , F_129 ( V_183 ) , V_506 ) ;
}
}
return 0 ;
}
static T_1 F_131 ( struct V_9 * V_4 )
{
struct V_93 * V_94 = F_8 ( V_4 ) ;
struct V_137 * V_95 = V_94 -> V_95 ;
struct V_1 * V_2 = V_95 -> V_96 ;
T_1 V_511 = 0 ;
V_511 |= V_2 -> V_6 . V_473 . V_512 ?
V_513 : 0 ;
return V_511 ;
}
void F_132 ( struct V_9 * V_10 )
{
V_10 -> V_514 = & V_515 ;
}
