static void F_1 ( struct V_1 * V_2 )
{
F_2 ( & V_2 -> V_3 -> V_4 ,
L_1 ) ;
}
static int F_3 ( struct V_5 * V_6 ,
struct V_7 * V_8 )
{
struct V_9 * V_10 = F_4 ( V_6 ) ;
struct V_1 * V_2 = V_10 -> V_11 -> V_12 ;
struct V_13 * V_14 = & V_2 -> V_14 ;
struct V_15 * V_16 = & V_14 -> V_17 . V_18 ;
bool V_19 = V_16 -> V_18 & V_20 ;
T_1 V_21 = V_16 -> V_21 ;
if ( ! V_19 ) {
switch ( V_14 -> V_22 ) {
case V_23 :
case V_24 :
case V_25 :
V_8 -> V_26 = V_27 |
V_28 |
V_29 ;
V_8 -> V_30 = V_31 |
V_32 |
V_33 ;
break;
case V_34 :
V_8 -> V_26 = V_35 ;
V_8 -> V_30 = V_36 ;
break;
case V_37 :
V_8 -> V_26 = V_38 ;
V_8 -> V_30 = V_39 ;
break;
case V_40 :
V_8 -> V_26 = V_41 |
V_42 |
V_43 ;
V_8 -> V_30 = V_44 |
V_45 |
V_46 ;
break;
default:
V_8 -> V_26 = V_41 |
V_42 ;
V_8 -> V_30 = V_44 |
V_45 ;
break;
}
goto V_47;
}
switch ( V_16 -> V_48 ) {
case V_49 :
case V_50 :
V_8 -> V_26 = V_51 |
V_28 ;
V_8 -> V_30 = V_52 |
V_32 ;
break;
case V_53 :
V_8 -> V_26 = V_51 |
V_35 ;
V_8 -> V_30 = V_52 |
V_36 ;
break;
case V_54 :
case V_55 :
case V_56 :
V_8 -> V_26 = V_27 ;
break;
case V_57 :
V_8 -> V_26 = V_29 ;
break;
case V_58 :
V_8 -> V_26 = V_51 |
V_59 ;
V_8 -> V_30 = V_52 |
V_60 ;
break;
case V_61 :
V_8 -> V_26 = V_51 |
V_38 ;
V_8 -> V_30 = V_52 |
V_39 ;
break;
case V_62 :
case V_63 :
case V_64 :
case V_65 :
V_8 -> V_26 = V_41 ;
V_8 -> V_26 |= V_42 ;
break;
case V_66 :
case V_67 :
case V_68 :
V_8 -> V_26 = V_51 |
V_41 |
V_42 |
V_43 ;
V_8 -> V_30 = V_52 |
V_44 |
V_45 |
V_46 ;
break;
case V_69 :
case V_70 :
case V_71 :
case V_72 :
V_8 -> V_26 = V_41 ;
break;
case V_73 :
case V_74 :
V_8 -> V_26 = V_51 |
V_41 |
V_42 |
V_43 ;
V_8 -> V_30 = V_52 |
V_44 |
V_45 |
V_46 ;
break;
case V_75 :
V_8 -> V_26 = V_51 |
V_41 |
V_42 |
V_43 ;
V_8 -> V_30 = V_52 |
V_44 |
V_45 |
V_46 ;
break;
case V_76 :
V_8 -> V_26 = V_51 |
V_42 |
V_43 ;
V_8 -> V_30 = V_52 |
V_45 |
V_46 ;
break;
default:
F_5 ( V_6 , L_2 ,
V_16 -> V_48 ) ;
}
V_47:
V_8 -> V_77 = ( ( V_16 -> V_78 & V_79 ) ?
V_80 : V_81 ) ;
switch ( V_14 -> V_17 . V_82 ) {
case V_83 :
V_8 -> V_26 |= V_51 |
V_84 ;
V_8 -> V_30 |= V_52 |
V_85 ;
V_8 -> V_86 = V_87 ;
break;
case V_88 :
V_8 -> V_26 |= V_89 ;
V_8 -> V_30 |= V_90 ;
V_8 -> V_86 = V_91 ;
break;
case V_92 :
case V_93 :
V_8 -> V_26 |= V_94 ;
V_8 -> V_30 |= V_95 ;
V_8 -> V_86 = V_96 ;
break;
case V_97 :
V_8 -> V_26 |= V_94 ;
V_8 -> V_86 = V_98 ;
break;
case V_99 :
default:
V_8 -> V_86 = V_100 ;
break;
}
V_8 -> V_101 = V_102 ;
V_8 -> V_26 |= V_103 ;
switch ( V_14 -> V_104 . V_105 ) {
case V_106 :
V_8 -> V_30 |= V_107 ;
break;
case V_108 :
V_8 -> V_30 |= V_109 ;
break;
case V_110 :
V_8 -> V_30 |= ( V_107 |
V_109 ) ;
break;
default:
V_8 -> V_30 &= ~ ( V_107 |
V_109 ) ;
break;
}
if ( V_19 ) {
switch ( V_21 ) {
case V_111 :
F_6 ( V_8 , 40000 ) ;
break;
case V_112 :
F_6 ( V_8 , V_113 ) ;
break;
case V_114 :
F_6 ( V_8 , V_115 ) ;
break;
case V_116 :
F_6 ( V_8 , V_117 ) ;
break;
default:
break;
}
V_8 -> V_118 = V_119 ;
} else {
F_6 ( V_8 , V_120 ) ;
V_8 -> V_118 = V_121 ;
}
return 0 ;
}
static int F_7 ( struct V_5 * V_6 ,
struct V_7 * V_8 )
{
struct V_9 * V_10 = F_4 ( V_6 ) ;
struct V_122 V_123 ;
struct V_124 V_125 ;
struct V_1 * V_2 = V_10 -> V_11 -> V_12 ;
struct V_126 * V_11 = V_10 -> V_11 ;
struct V_13 * V_14 = & V_2 -> V_14 ;
struct V_7 V_127 ;
T_2 V_128 = 0 ;
bool V_129 = false ;
int V_130 = 0 ;
T_3 V_77 ;
T_1 V_131 ;
if ( V_14 -> V_132 != 1 ) {
F_1 ( V_2 ) ;
return - V_133 ;
}
if ( V_11 != V_2 -> V_11 [ V_2 -> V_134 ] )
return - V_133 ;
if ( V_14 -> V_17 . V_82 != V_88 &&
V_14 -> V_17 . V_82 != V_97 &&
V_14 -> V_17 . V_82 != V_83 &&
V_14 -> V_17 . V_18 . V_18 & V_20 )
return - V_133 ;
memset ( & V_127 , 0 , sizeof( struct V_7 ) ) ;
F_3 ( V_6 , & V_127 ) ;
V_77 = V_8 -> V_77 ;
V_131 = V_8 -> V_30 ;
V_8 -> V_77 = V_127 . V_77 ;
V_8 -> V_30 = V_127 . V_30 ;
V_8 -> V_135 = V_127 . V_135 ;
if ( memcmp ( V_8 , & V_127 , sizeof( struct V_7 ) ) )
return - V_133 ;
while ( F_8 ( V_136 , & V_11 -> V_137 ) )
F_9 ( 1000 , 2000 ) ;
V_128 = F_10 ( V_14 , false , false , & V_123 ,
NULL ) ;
if ( V_128 )
return - V_138 ;
memset ( & V_125 , 0 , sizeof( struct V_124 ) ) ;
V_125 . V_123 = V_123 . V_123 ;
if ( V_77 == V_80 ) {
if ( ! ( V_127 . V_26 & V_51 ) ) {
F_5 ( V_6 , L_3 ) ;
return - V_139 ;
}
if ( ! ( V_14 -> V_17 . V_18 . V_78 & V_79 ) ) {
V_125 . V_123 = V_123 . V_123 |
V_140 ;
V_129 = true ;
}
} else {
if ( V_127 . V_26 & V_51 &&
V_14 -> V_17 . V_18 . V_48 != V_68 ) {
F_5 ( V_6 , L_4 ) ;
return - V_139 ;
}
if ( V_14 -> V_17 . V_18 . V_78 & V_79 ) {
V_125 . V_123 = V_123 . V_123 &
~ V_140 ;
V_129 = true ;
}
}
if ( V_131 & ~ V_127 . V_26 )
return - V_139 ;
if ( V_131 & V_46 )
V_125 . V_21 |= V_116 ;
if ( V_131 & V_45 ||
V_131 & V_141 )
V_125 . V_21 |= V_114 ;
if ( V_131 & V_44 ||
V_131 & V_60 ||
V_131 & V_39 )
V_125 . V_21 |= V_112 ;
if ( V_131 & V_36 ||
V_131 & V_32 ||
V_131 & V_31 ||
V_131 & V_33 )
V_125 . V_21 |= V_111 ;
if ( V_129 || ( V_123 . V_21 != V_125 . V_21 ) ) {
V_125 . V_48 = V_123 . V_48 ;
V_125 . V_142 = V_123 . V_142 ;
V_125 . V_143 = V_123 . V_144 ;
V_125 . V_145 = V_123 . V_146 ;
V_125 . V_123 |= V_147 ;
if ( V_14 -> V_17 . V_18 . V_18 & V_20 ) {
F_5 ( V_6 , L_5 ) ;
F_11 ( V_6 ) ;
F_12 ( V_6 ) ;
}
V_128 = V_124 ( V_14 , & V_125 , NULL ) ;
if ( V_128 ) {
F_5 ( V_6 , L_6 ,
V_128 ) ;
return - V_138 ;
}
V_128 = F_13 ( V_14 , true ) ;
if ( V_128 )
F_5 ( V_6 , L_7 ,
V_128 ) ;
} else {
F_5 ( V_6 , L_8 ) ;
}
return V_130 ;
}
static int F_14 ( struct V_5 * V_6 )
{
struct V_9 * V_10 = F_4 ( V_6 ) ;
struct V_1 * V_2 = V_10 -> V_11 -> V_12 ;
struct V_13 * V_14 = & V_2 -> V_14 ;
bool V_19 = V_14 -> V_17 . V_18 . V_18 & V_20 ;
T_2 V_148 = 0 ;
V_148 = F_15 ( V_14 , V_19 , NULL ) ;
if ( V_148 ) {
F_5 ( V_6 , L_9 ,
V_2 -> V_14 . V_149 . V_150 ) ;
return - V_151 ;
}
return 0 ;
}
static void F_16 ( struct V_5 * V_6 ,
struct V_152 * V_153 )
{
struct V_9 * V_10 = F_4 ( V_6 ) ;
struct V_1 * V_2 = V_10 -> V_11 -> V_12 ;
struct V_13 * V_14 = & V_2 -> V_14 ;
struct V_15 * V_16 = & V_14 -> V_17 . V_18 ;
struct V_154 * V_155 = & V_14 -> V_156 ;
V_153 -> V_77 =
( ( V_16 -> V_78 & V_79 ) ?
V_80 : V_81 ) ;
if ( V_155 -> V_157 . V_158 ) {
V_153 -> V_159 = 0 ;
V_153 -> V_160 = 0 ;
return;
}
if ( V_14 -> V_104 . V_105 == V_110 ) {
V_153 -> V_159 = 1 ;
} else if ( V_14 -> V_104 . V_105 == V_108 ) {
V_153 -> V_160 = 1 ;
} else if ( V_14 -> V_104 . V_105 == V_106 ) {
V_153 -> V_159 = 1 ;
V_153 -> V_160 = 1 ;
}
}
static int F_17 ( struct V_5 * V_6 ,
struct V_152 * V_153 )
{
struct V_9 * V_10 = F_4 ( V_6 ) ;
struct V_1 * V_2 = V_10 -> V_11 -> V_12 ;
struct V_126 * V_11 = V_10 -> V_11 ;
struct V_13 * V_14 = & V_2 -> V_14 ;
struct V_15 * V_16 = & V_14 -> V_17 . V_18 ;
struct V_154 * V_155 = & V_14 -> V_156 ;
bool V_19 = V_16 -> V_18 & V_20 ;
T_2 V_128 ;
T_3 V_161 ;
int V_130 = 0 ;
if ( V_14 -> V_132 != 1 ) {
F_1 ( V_2 ) ;
return - V_133 ;
}
if ( V_11 != V_2 -> V_11 [ V_2 -> V_134 ] )
return - V_133 ;
if ( V_153 -> V_77 != ( ( V_16 -> V_78 & V_79 ) ?
V_80 : V_81 ) ) {
F_5 ( V_6 , L_10 ) ;
return - V_133 ;
}
if ( ! F_8 ( V_162 , & V_2 -> V_137 ) &&
! ( V_16 -> V_78 & V_79 ) ) {
F_5 ( V_6 , L_11 ) ;
}
if ( V_155 -> V_157 . V_158 ) {
F_5 ( V_6 ,
L_12 ) ;
return - V_133 ;
}
if ( V_153 -> V_159 && V_153 -> V_160 )
V_14 -> V_104 . V_163 = V_106 ;
else if ( V_153 -> V_159 && ! V_153 -> V_160 )
V_14 -> V_104 . V_163 = V_110 ;
else if ( ! V_153 -> V_159 && V_153 -> V_160 )
V_14 -> V_104 . V_163 = V_108 ;
else if ( ! V_153 -> V_159 && ! V_153 -> V_160 )
V_14 -> V_104 . V_163 = V_164 ;
else
return - V_139 ;
F_5 ( V_6 , L_13 ) ;
F_11 ( V_6 ) ;
F_12 ( V_6 ) ;
V_128 = F_18 ( V_14 , & V_161 , V_19 ) ;
if ( V_161 & V_165 ) {
F_5 ( V_6 , L_14 ,
V_128 , V_14 -> V_149 . V_150 ) ;
V_130 = - V_138 ;
}
if ( V_161 & V_166 ) {
F_5 ( V_6 , L_15 ,
V_128 , V_14 -> V_149 . V_150 ) ;
V_130 = - V_138 ;
}
if ( V_161 & V_167 ) {
F_5 ( V_6 , L_16 ,
V_128 , V_14 -> V_149 . V_150 ) ;
V_130 = - V_138 ;
}
if ( ! F_8 ( V_162 , & V_2 -> V_137 ) ) {
F_19 ( 75 ) ;
if ( ! F_8 ( V_162 , & V_2 -> V_137 ) )
return F_14 ( V_6 ) ;
}
return V_130 ;
}
static T_1 F_20 ( struct V_5 * V_6 )
{
struct V_9 * V_10 = F_4 ( V_6 ) ;
struct V_1 * V_2 = V_10 -> V_11 -> V_12 ;
return V_2 -> V_168 ;
}
static void F_21 ( struct V_5 * V_6 , T_1 V_169 )
{
struct V_9 * V_10 = F_4 ( V_6 ) ;
struct V_1 * V_2 = V_10 -> V_11 -> V_12 ;
if ( V_170 & V_169 )
V_2 -> V_14 . V_171 = V_169 ;
V_2 -> V_168 = V_169 ;
}
static int F_22 ( struct V_5 * V_6 )
{
int V_172 = 0 ;
int V_173 ;
for ( V_173 = 0 ; V_174 [ V_173 ] . V_175 != 0 ; V_173 ++ )
V_172 += V_174 [ V_173 ] . V_176 ;
return V_172 * sizeof( T_1 ) ;
}
static void F_23 ( struct V_5 * V_6 , struct V_177 * V_178 ,
void * V_179 )
{
struct V_9 * V_10 = F_4 ( V_6 ) ;
struct V_1 * V_2 = V_10 -> V_11 -> V_12 ;
struct V_13 * V_14 = & V_2 -> V_14 ;
T_1 * V_180 = V_179 ;
int V_173 , V_181 , V_182 ;
T_1 V_183 ;
V_178 -> V_184 = 1 ;
V_182 = 0 ;
for ( V_173 = 0 ; V_174 [ V_173 ] . V_175 != 0 ; V_173 ++ ) {
for ( V_181 = 0 ; V_181 < V_174 [ V_173 ] . V_176 ; V_181 ++ ) {
V_183 = V_174 [ V_173 ] . V_175
+ ( V_181 * V_174 [ V_173 ] . V_185 ) ;
V_180 [ V_182 ++ ] = F_24 ( V_14 , V_183 ) ;
}
}
}
static int F_25 ( struct V_5 * V_6 ,
struct V_186 * V_187 , T_3 * V_188 )
{
struct V_9 * V_10 = F_4 ( V_6 ) ;
struct V_13 * V_14 = & V_10 -> V_11 -> V_12 -> V_14 ;
struct V_1 * V_2 = V_10 -> V_11 -> V_12 ;
int V_189 = 0 , V_190 , V_175 ;
T_3 * V_191 ;
T_4 V_173 , V_192 ;
bool V_193 ;
T_1 V_194 ;
#define F_26 4096
if ( V_187 -> V_190 == 0 )
return - V_139 ;
V_194 = V_14 -> V_195 | ( V_14 -> V_22 << 16 ) ;
if ( V_187 -> V_194 && V_187 -> V_194 != V_194 ) {
struct V_196 * V_135 ;
int V_197 ;
if ( ( V_187 -> V_194 >> 16 ) != V_14 -> V_22 )
return - V_139 ;
V_135 = (struct V_196 * ) V_187 ;
V_189 = F_27 ( V_14 , V_135 , V_188 , & V_197 ) ;
if ( V_189 )
F_2 ( & V_2 -> V_3 -> V_4 ,
L_17 ,
V_189 , V_14 -> V_149 . V_150 , V_197 ,
( T_3 ) ( V_135 -> V_125 & V_198 ) ,
V_135 -> V_175 , V_135 -> V_199 ) ;
return V_197 ;
}
V_187 -> V_194 = V_14 -> V_195 | ( V_14 -> V_22 << 16 ) ;
V_191 = F_28 ( V_187 -> V_190 , V_200 ) ;
if ( ! V_191 )
return - V_201 ;
V_189 = F_29 ( V_14 , V_202 ) ;
if ( V_189 ) {
F_2 ( & V_2 -> V_3 -> V_4 ,
L_18 ,
V_189 , V_14 -> V_149 . V_150 ) ;
goto V_203;
}
V_192 = V_187 -> V_190 / F_26 ;
V_192 += ( V_187 -> V_190 % F_26 ) ? 1 : 0 ;
V_190 = F_26 ;
V_193 = false ;
for ( V_173 = 0 ; V_173 < V_192 ; V_173 ++ ) {
if ( V_173 == ( V_192 - 1 ) ) {
V_190 = V_187 -> V_190 - ( F_26 * V_173 ) ;
V_193 = true ;
}
V_175 = V_187 -> V_175 + ( F_26 * V_173 ) ,
V_189 = F_30 ( V_14 , 0x0 , V_175 , V_190 ,
( T_3 * ) V_191 + ( F_26 * V_173 ) ,
V_193 , NULL ) ;
if ( V_189 && V_14 -> V_149 . V_150 == V_204 ) {
F_2 ( & V_2 -> V_3 -> V_4 ,
L_19 ,
V_175 ) ;
break;
} else if ( V_189 &&
V_14 -> V_149 . V_150 == V_205 ) {
F_2 ( & V_2 -> V_3 -> V_4 ,
L_20 ,
V_175 ) ;
break;
} else if ( V_189 ) {
F_2 ( & V_2 -> V_3 -> V_4 ,
L_21 ,
V_175 , V_189 , V_14 -> V_149 . V_150 ) ;
break;
}
}
F_31 ( V_14 ) ;
memcpy ( V_188 , ( T_3 * ) V_191 , V_187 -> V_190 ) ;
V_203:
F_32 ( V_191 ) ;
return V_189 ;
}
static int F_33 ( struct V_5 * V_6 )
{
struct V_9 * V_10 = F_4 ( V_6 ) ;
struct V_13 * V_14 = & V_10 -> V_11 -> V_12 -> V_14 ;
T_1 V_206 ;
V_206 = ( F_24 ( V_14 , V_207 )
& V_208 )
>> V_209 ;
V_206 = ( 64 * 1024 ) * ( 1 << V_206 ) ;
return V_206 ;
}
static int F_34 ( struct V_5 * V_6 ,
struct V_186 * V_187 , T_3 * V_188 )
{
struct V_9 * V_10 = F_4 ( V_6 ) ;
struct V_13 * V_14 = & V_10 -> V_11 -> V_12 -> V_14 ;
struct V_1 * V_2 = V_10 -> V_11 -> V_12 ;
struct V_196 * V_135 ;
int V_189 = 0 ;
int V_197 ;
T_1 V_194 ;
V_194 = V_14 -> V_195 | ( V_14 -> V_22 << 16 ) ;
if ( V_187 -> V_194 == V_194 )
return - V_133 ;
if ( ! V_187 -> V_194 || ( V_187 -> V_194 >> 16 ) != V_14 -> V_22 )
return - V_139 ;
if ( F_8 ( V_210 , & V_2 -> V_137 ) ||
F_8 ( V_211 , & V_2 -> V_137 ) )
return - V_212 ;
V_135 = (struct V_196 * ) V_187 ;
V_189 = F_27 ( V_14 , V_135 , V_188 , & V_197 ) ;
if ( V_189 && V_14 -> V_149 . V_150 != V_213 )
F_2 ( & V_2 -> V_3 -> V_4 ,
L_22 ,
V_189 , V_14 -> V_149 . V_150 , V_197 ,
( T_3 ) ( V_135 -> V_125 & V_198 ) ,
V_135 -> V_175 , V_135 -> V_199 ) ;
return V_197 ;
}
static void F_35 ( struct V_5 * V_6 ,
struct V_214 * V_215 )
{
struct V_9 * V_10 = F_4 ( V_6 ) ;
struct V_126 * V_11 = V_10 -> V_11 ;
struct V_1 * V_2 = V_11 -> V_12 ;
F_36 ( V_215 -> V_216 , V_217 , sizeof( V_215 -> V_216 ) ) ;
F_36 ( V_215 -> V_184 , V_218 ,
sizeof( V_215 -> V_184 ) ) ;
F_36 ( V_215 -> V_219 , F_37 ( & V_2 -> V_14 ) ,
sizeof( V_215 -> V_219 ) ) ;
F_36 ( V_215 -> V_220 , F_38 ( V_2 -> V_3 ) ,
sizeof( V_215 -> V_220 ) ) ;
}
static void F_39 ( struct V_5 * V_6 ,
struct V_221 * V_222 )
{
struct V_9 * V_10 = F_4 ( V_6 ) ;
struct V_1 * V_2 = V_10 -> V_11 -> V_12 ;
struct V_126 * V_11 = V_2 -> V_11 [ V_2 -> V_134 ] ;
V_222 -> V_223 = V_224 ;
V_222 -> V_225 = V_224 ;
V_222 -> V_226 = 0 ;
V_222 -> V_227 = 0 ;
V_222 -> V_228 = V_11 -> V_229 [ 0 ] -> V_230 ;
V_222 -> V_231 = V_11 -> V_232 [ 0 ] -> V_230 ;
V_222 -> V_233 = 0 ;
V_222 -> V_234 = 0 ;
}
static int F_40 ( struct V_5 * V_6 ,
struct V_221 * V_222 )
{
struct V_235 * V_232 = NULL , * V_229 = NULL ;
struct V_9 * V_10 = F_4 ( V_6 ) ;
struct V_126 * V_11 = V_10 -> V_11 ;
struct V_1 * V_2 = V_11 -> V_12 ;
T_1 V_236 , V_237 ;
int V_173 , V_130 = 0 ;
if ( ( V_222 -> V_233 ) || ( V_222 -> V_234 ) )
return - V_139 ;
if ( V_222 -> V_231 > V_224 ||
V_222 -> V_231 < V_238 ||
V_222 -> V_228 > V_224 ||
V_222 -> V_228 < V_238 ) {
F_5 ( V_6 ,
L_23 ,
V_222 -> V_231 , V_222 -> V_228 ,
V_238 , V_224 ) ;
return - V_139 ;
}
V_237 = F_41 ( V_222 -> V_231 , V_239 ) ;
V_236 = F_41 ( V_222 -> V_228 , V_239 ) ;
if ( ( V_237 == V_11 -> V_232 [ 0 ] -> V_230 ) &&
( V_236 == V_11 -> V_229 [ 0 ] -> V_230 ) )
return 0 ;
while ( F_42 ( V_136 , & V_2 -> V_137 ) )
F_9 ( 1000 , 2000 ) ;
if ( ! F_43 ( V_11 -> V_6 ) ) {
for ( V_173 = 0 ; V_173 < V_11 -> V_240 ; V_173 ++ ) {
V_11 -> V_232 [ V_173 ] -> V_230 = V_237 ;
V_11 -> V_229 [ V_173 ] -> V_230 = V_236 ;
}
goto V_241;
}
if ( V_237 != V_11 -> V_232 [ 0 ] -> V_230 ) {
F_5 ( V_6 ,
L_24 ,
V_11 -> V_232 [ 0 ] -> V_230 , V_237 ) ;
V_232 = F_44 ( V_11 -> V_242 ,
sizeof( struct V_235 ) , V_200 ) ;
if ( ! V_232 ) {
V_130 = - V_201 ;
goto V_241;
}
for ( V_173 = 0 ; V_173 < V_11 -> V_240 ; V_173 ++ ) {
V_232 [ V_173 ] = * V_11 -> V_232 [ V_173 ] ;
V_232 [ V_173 ] . V_230 = V_237 ;
V_130 = F_45 ( & V_232 [ V_173 ] ) ;
if ( V_130 ) {
while ( V_173 ) {
V_173 -- ;
F_46 ( & V_232 [ V_173 ] ) ;
}
F_32 ( V_232 ) ;
V_232 = NULL ;
goto V_241;
}
}
}
if ( V_236 != V_11 -> V_229 [ 0 ] -> V_230 ) {
F_5 ( V_6 ,
L_25 ,
V_11 -> V_229 [ 0 ] -> V_230 , V_236 ) ;
V_229 = F_44 ( V_11 -> V_242 ,
sizeof( struct V_235 ) , V_200 ) ;
if ( ! V_229 ) {
V_130 = - V_201 ;
goto V_243;
}
for ( V_173 = 0 ; V_173 < V_11 -> V_240 ; V_173 ++ ) {
V_229 [ V_173 ] = * V_11 -> V_229 [ V_173 ] ;
V_229 [ V_173 ] . V_230 = V_236 ;
V_130 = F_47 ( & V_229 [ V_173 ] ) ;
if ( V_130 ) {
while ( V_173 ) {
V_173 -- ;
F_48 ( & V_229 [ V_173 ] ) ;
}
F_32 ( V_229 ) ;
V_229 = NULL ;
goto V_243;
}
}
}
F_49 ( V_11 ) ;
if ( V_232 ) {
for ( V_173 = 0 ; V_173 < V_11 -> V_240 ; V_173 ++ ) {
F_46 ( V_11 -> V_232 [ V_173 ] ) ;
* V_11 -> V_232 [ V_173 ] = V_232 [ V_173 ] ;
}
F_32 ( V_232 ) ;
V_232 = NULL ;
}
if ( V_229 ) {
for ( V_173 = 0 ; V_173 < V_11 -> V_240 ; V_173 ++ ) {
F_48 ( V_11 -> V_229 [ V_173 ] ) ;
* V_11 -> V_229 [ V_173 ] = V_229 [ V_173 ] ;
}
F_32 ( V_229 ) ;
V_229 = NULL ;
}
F_50 ( V_11 ) ;
V_243:
if ( V_232 ) {
for ( V_173 = 0 ; V_173 < V_11 -> V_240 ; V_173 ++ )
F_46 ( & V_232 [ V_173 ] ) ;
F_32 ( V_232 ) ;
V_232 = NULL ;
}
V_241:
F_51 ( V_136 , & V_2 -> V_137 ) ;
return V_130 ;
}
static int F_52 ( struct V_5 * V_6 , int V_244 )
{
struct V_9 * V_10 = F_4 ( V_6 ) ;
struct V_126 * V_11 = V_10 -> V_11 ;
struct V_1 * V_2 = V_11 -> V_12 ;
switch ( V_244 ) {
case V_245 :
return V_246 ;
case V_247 :
if ( V_11 == V_2 -> V_11 [ V_2 -> V_134 ] ) {
int V_190 = F_53 ( V_6 ) ;
if ( V_2 -> V_248 != V_249 )
V_190 += V_250 ;
return V_190 ;
} else {
return F_54 ( V_6 ) ;
}
default:
return - V_133 ;
}
}
static void F_55 ( struct V_5 * V_6 ,
struct V_251 * V_252 , T_5 * V_169 )
{
struct V_9 * V_10 = F_4 ( V_6 ) ;
struct V_235 * V_253 , * V_254 ;
struct V_126 * V_11 = V_10 -> V_11 ;
struct V_1 * V_2 = V_11 -> V_12 ;
int V_173 = 0 ;
char * V_179 ;
int V_181 ;
struct V_255 * V_256 = F_56 ( V_11 ) ;
unsigned int V_257 ;
F_57 ( V_11 ) ;
for ( V_181 = 0 ; V_181 < V_258 ; V_181 ++ ) {
V_179 = ( char * ) V_256 + V_259 [ V_181 ] . V_260 ;
V_169 [ V_173 ++ ] = ( V_259 [ V_181 ] . V_261 ==
sizeof( T_5 ) ) ? * ( T_5 * ) V_179 : * ( T_1 * ) V_179 ;
}
for ( V_181 = 0 ; V_181 < V_262 ; V_181 ++ ) {
V_179 = ( char * ) V_11 + V_263 [ V_181 ] . V_260 ;
V_169 [ V_173 ++ ] = ( V_263 [ V_181 ] . V_261 ==
sizeof( T_5 ) ) ? * ( T_5 * ) V_179 : * ( T_1 * ) V_179 ;
}
#ifdef F_58
for ( V_181 = 0 ; V_181 < V_264 ; V_181 ++ ) {
V_179 = ( char * ) V_11 + V_265 [ V_181 ] . V_260 ;
V_169 [ V_173 ++ ] = ( V_265 [ V_181 ] . V_261 ==
sizeof( T_5 ) ) ? * ( T_5 * ) V_179 : * ( T_1 * ) V_179 ;
}
#endif
F_59 () ;
for ( V_181 = 0 ; V_181 < V_11 -> V_240 ; V_181 ++ ) {
V_253 = F_60 ( V_11 -> V_232 [ V_181 ] ) ;
if ( ! V_253 )
continue;
do {
V_257 = F_61 ( & V_253 -> V_266 ) ;
V_169 [ V_173 ] = V_253 -> V_252 . V_267 ;
V_169 [ V_173 + 1 ] = V_253 -> V_252 . V_188 ;
} while ( F_62 ( & V_253 -> V_266 , V_257 ) );
V_173 += 2 ;
V_254 = & V_253 [ 1 ] ;
do {
V_257 = F_61 ( & V_254 -> V_266 ) ;
V_169 [ V_173 ] = V_254 -> V_252 . V_267 ;
V_169 [ V_173 + 1 ] = V_254 -> V_252 . V_188 ;
} while ( F_62 ( & V_254 -> V_266 , V_257 ) );
V_173 += 2 ;
}
F_63 () ;
if ( V_11 != V_2 -> V_11 [ V_2 -> V_134 ] )
return;
if ( V_2 -> V_248 != V_249 ) {
struct V_268 * V_269 = V_2 -> V_269 [ V_2 -> V_248 ] ;
for ( V_181 = 0 ; V_181 < V_250 ; V_181 ++ ) {
V_179 = ( char * ) V_269 ;
V_179 += V_270 [ V_181 ] . V_260 ;
V_169 [ V_173 ++ ] = ( V_270 [ V_181 ] . V_261 ==
sizeof( T_5 ) ) ? * ( T_5 * ) V_179 : * ( T_1 * ) V_179 ;
}
}
for ( V_181 = 0 ; V_181 < V_271 ; V_181 ++ ) {
V_179 = ( char * ) V_2 + V_272 [ V_181 ] . V_260 ;
V_169 [ V_173 ++ ] = ( V_272 [ V_181 ] . V_261 ==
sizeof( T_5 ) ) ? * ( T_5 * ) V_179 : * ( T_1 * ) V_179 ;
}
for ( V_181 = 0 ; V_181 < V_273 ; V_181 ++ ) {
V_169 [ V_173 ++ ] = V_2 -> V_252 . V_274 [ V_181 ] ;
V_169 [ V_173 ++ ] = V_2 -> V_252 . V_275 [ V_181 ] ;
}
for ( V_181 = 0 ; V_181 < V_273 ; V_181 ++ ) {
V_169 [ V_173 ++ ] = V_2 -> V_252 . V_276 [ V_181 ] ;
V_169 [ V_173 ++ ] = V_2 -> V_252 . V_277 [ V_181 ] ;
}
for ( V_181 = 0 ; V_181 < V_273 ; V_181 ++ )
V_169 [ V_173 ++ ] = V_2 -> V_252 . V_278 [ V_181 ] ;
}
static void F_64 ( struct V_5 * V_6 , T_1 V_279 ,
T_3 * V_169 )
{
struct V_9 * V_10 = F_4 ( V_6 ) ;
struct V_126 * V_11 = V_10 -> V_11 ;
struct V_1 * V_2 = V_11 -> V_12 ;
char * V_179 = ( char * ) V_169 ;
int V_173 ;
switch ( V_279 ) {
case V_245 :
for ( V_173 = 0 ; V_173 < V_246 ; V_173 ++ ) {
memcpy ( V_169 , V_280 [ V_173 ] , V_281 ) ;
V_169 += V_281 ;
}
break;
case V_247 :
for ( V_173 = 0 ; V_173 < V_258 ; V_173 ++ ) {
snprintf ( V_179 , V_281 , L_26 ,
V_259 [ V_173 ] . V_282 ) ;
V_179 += V_281 ;
}
for ( V_173 = 0 ; V_173 < V_262 ; V_173 ++ ) {
snprintf ( V_179 , V_281 , L_26 ,
V_263 [ V_173 ] . V_282 ) ;
V_179 += V_281 ;
}
#ifdef F_58
for ( V_173 = 0 ; V_173 < V_264 ; V_173 ++ ) {
snprintf ( V_179 , V_281 , L_26 ,
V_265 [ V_173 ] . V_282 ) ;
V_179 += V_281 ;
}
#endif
for ( V_173 = 0 ; V_173 < V_11 -> V_240 ; V_173 ++ ) {
snprintf ( V_179 , V_281 , L_27 , V_173 ) ;
V_179 += V_281 ;
snprintf ( V_179 , V_281 , L_28 , V_173 ) ;
V_179 += V_281 ;
snprintf ( V_179 , V_281 , L_29 , V_173 ) ;
V_179 += V_281 ;
snprintf ( V_179 , V_281 , L_30 , V_173 ) ;
V_179 += V_281 ;
}
if ( V_11 != V_2 -> V_11 [ V_2 -> V_134 ] )
return;
if ( V_2 -> V_248 != V_249 ) {
for ( V_173 = 0 ; V_173 < V_250 ; V_173 ++ ) {
snprintf ( V_179 , V_281 , L_31 ,
V_270 [ V_173 ] . V_282 ) ;
V_179 += V_281 ;
}
}
for ( V_173 = 0 ; V_173 < V_271 ; V_173 ++ ) {
snprintf ( V_179 , V_281 , L_32 ,
V_272 [ V_173 ] . V_282 ) ;
V_179 += V_281 ;
}
for ( V_173 = 0 ; V_173 < V_273 ; V_173 ++ ) {
snprintf ( V_179 , V_281 ,
L_33 , V_173 ) ;
V_179 += V_281 ;
snprintf ( V_179 , V_281 ,
L_34 , V_173 ) ;
V_179 += V_281 ;
}
for ( V_173 = 0 ; V_173 < V_273 ; V_173 ++ ) {
snprintf ( V_179 , V_281 ,
L_35 , V_173 ) ;
V_179 += V_281 ;
snprintf ( V_179 , V_281 ,
L_36 , V_173 ) ;
V_179 += V_281 ;
}
for ( V_173 = 0 ; V_173 < V_273 ; V_173 ++ ) {
snprintf ( V_179 , V_281 ,
L_37 , V_173 ) ;
V_179 += V_281 ;
}
break;
}
}
static int F_65 ( struct V_5 * V_4 ,
struct V_283 * V_284 )
{
struct V_1 * V_2 = F_66 ( V_4 ) ;
if ( ! ( V_2 -> V_285 & V_286 ) )
return F_67 ( V_4 , V_284 ) ;
V_284 -> V_287 = V_288 |
V_289 |
V_290 |
V_291 |
V_292 |
V_293 ;
if ( V_2 -> V_294 )
V_284 -> V_295 = F_68 ( V_2 -> V_294 ) ;
else
V_284 -> V_295 = - 1 ;
V_284 -> V_296 = ( 1 << V_297 ) | ( 1 << V_298 ) ;
V_284 -> V_299 = ( 1 << V_300 ) |
( 1 << V_301 ) |
( 1 << V_302 ) |
( 1 << V_303 ) |
( 1 << V_304 ) |
( 1 << V_305 ) |
( 1 << V_306 ) |
( 1 << V_307 ) |
( 1 << V_308 ) |
( 1 << V_309 ) |
( 1 << V_310 ) |
( 1 << V_311 ) ;
return 0 ;
}
static int F_69 ( struct V_5 * V_6 , T_5 * V_169 )
{
struct V_9 * V_10 = F_4 ( V_6 ) ;
struct V_1 * V_2 = V_10 -> V_11 -> V_12 ;
F_70 ( V_2 , V_14 , V_6 , L_38 ) ;
if ( F_71 ( & V_2 -> V_14 ) )
* V_169 = 0 ;
else
* V_169 = 1 ;
return * V_169 ;
}
static int F_72 ( struct V_5 * V_6 , T_5 * V_169 )
{
struct V_9 * V_10 = F_4 ( V_6 ) ;
struct V_1 * V_2 = V_10 -> V_11 -> V_12 ;
F_70 ( V_2 , V_14 , V_6 , L_39 ) ;
* V_169 = F_73 ( & V_2 -> V_14 ) ;
return * V_169 ;
}
static int F_74 ( struct V_5 * V_6 , T_5 * V_169 )
{
struct V_9 * V_10 = F_4 ( V_6 ) ;
struct V_1 * V_2 = V_10 -> V_11 -> V_12 ;
F_70 ( V_2 , V_14 , V_6 , L_40 ) ;
* V_169 = F_75 ( & V_2 -> V_14 ) ;
V_2 -> V_14 . V_312 = V_313 ;
return * V_169 ;
}
static int F_76 ( struct V_5 * V_6 , T_5 * V_169 )
{
struct V_9 * V_10 = F_4 ( V_6 ) ;
struct V_1 * V_2 = V_10 -> V_11 -> V_12 ;
T_4 V_314 = V_2 -> V_315 ;
F_70 ( V_2 , V_14 , V_6 , L_41 ) ;
F_77 ( & V_2 -> V_14 , V_316 ,
( V_317 |
V_318 |
V_319 |
V_320 |
V_321 ) ) ;
F_9 ( 1000 , 2000 ) ;
* V_169 = ( V_314 == V_2 -> V_315 ) ;
return * V_169 ;
}
static int F_78 ( struct V_5 * V_6 , T_5 * V_169 )
{
struct V_9 * V_10 = F_4 ( V_6 ) ;
struct V_1 * V_2 = V_10 -> V_11 -> V_12 ;
F_70 ( V_2 , V_14 , V_6 , L_42 ) ;
* V_169 = 0 ;
return * V_169 ;
}
static void F_79 ( struct V_5 * V_6 ,
struct V_322 * V_323 , T_5 * V_169 )
{
struct V_9 * V_10 = F_4 ( V_6 ) ;
struct V_1 * V_2 = V_10 -> V_11 -> V_12 ;
if ( V_323 -> V_285 == V_324 ) {
F_70 ( V_2 , V_325 , V_6 , L_43 ) ;
F_80 ( V_326 , & V_2 -> V_137 ) ;
if ( F_69 ( V_6 , & V_169 [ V_327 ] ) )
V_323 -> V_285 |= V_328 ;
if ( F_74 ( V_6 , & V_169 [ V_329 ] ) )
V_323 -> V_285 |= V_328 ;
if ( F_76 ( V_6 , & V_169 [ V_330 ] ) )
V_323 -> V_285 |= V_328 ;
if ( F_78 ( V_6 , & V_169 [ V_331 ] ) )
V_323 -> V_285 |= V_328 ;
if ( F_72 ( V_6 , & V_169 [ V_332 ] ) )
V_323 -> V_285 |= V_328 ;
F_51 ( V_326 , & V_2 -> V_137 ) ;
F_81 ( V_2 , ( 1 << V_333 ) ) ;
} else {
F_70 ( V_2 , V_325 , V_6 , L_44 ) ;
if ( F_69 ( V_6 , & V_169 [ V_327 ] ) )
V_323 -> V_285 |= V_328 ;
V_169 [ V_332 ] = 0 ;
V_169 [ V_329 ] = 0 ;
V_169 [ V_330 ] = 0 ;
V_169 [ V_331 ] = 0 ;
}
F_70 ( V_2 , V_325 , V_6 , L_45 ) ;
}
static void F_82 ( struct V_5 * V_6 ,
struct V_334 * V_335 )
{
struct V_9 * V_10 = F_4 ( V_6 ) ;
struct V_1 * V_2 = V_10 -> V_11 -> V_12 ;
struct V_13 * V_14 = & V_2 -> V_14 ;
T_4 V_336 ;
F_83 ( V_14 , V_337 , & V_336 ) ;
if ( ( 1 << V_14 -> V_86 ) & V_336 || V_14 -> V_132 != 1 ) {
V_335 -> V_26 = 0 ;
V_335 -> V_338 = 0 ;
} else {
V_335 -> V_26 = V_339 ;
V_335 -> V_338 = ( V_2 -> V_340 ? V_339 : 0 ) ;
}
}
static int F_84 ( struct V_5 * V_6 , struct V_334 * V_335 )
{
struct V_9 * V_10 = F_4 ( V_6 ) ;
struct V_1 * V_2 = V_10 -> V_11 -> V_12 ;
struct V_126 * V_11 = V_10 -> V_11 ;
struct V_13 * V_14 = & V_2 -> V_14 ;
T_4 V_336 ;
if ( V_14 -> V_132 != 1 ) {
F_1 ( V_2 ) ;
return - V_133 ;
}
if ( V_11 != V_2 -> V_11 [ V_2 -> V_134 ] )
return - V_133 ;
F_83 ( V_14 , V_337 , & V_336 ) ;
if ( ( ( 1 << V_14 -> V_86 ) & V_336 ) )
return - V_133 ;
if ( V_335 -> V_338 && ( V_335 -> V_338 != V_339 ) )
return - V_133 ;
if ( V_2 -> V_340 != ! ! V_335 -> V_338 ) {
V_2 -> V_340 = ! ! V_335 -> V_338 ;
F_85 ( & V_2 -> V_3 -> V_4 , V_2 -> V_340 ) ;
}
return 0 ;
}
static int F_86 ( struct V_5 * V_6 ,
enum V_341 V_137 )
{
struct V_9 * V_10 = F_4 ( V_6 ) ;
struct V_1 * V_2 = V_10 -> V_11 -> V_12 ;
struct V_13 * V_14 = & V_2 -> V_14 ;
int V_342 = 2 ;
switch ( V_137 ) {
case V_343 :
V_2 -> V_344 = F_87 ( V_14 ) ;
return V_342 ;
case V_345 :
F_88 ( V_14 , 0xF , false ) ;
break;
case V_346 :
F_88 ( V_14 , 0x0 , false ) ;
break;
case V_347 :
F_88 ( V_14 , V_2 -> V_344 , false ) ;
break;
}
return 0 ;
}
static int F_89 ( struct V_5 * V_6 ,
struct V_348 * V_349 )
{
struct V_9 * V_10 = F_4 ( V_6 ) ;
struct V_126 * V_11 = V_10 -> V_11 ;
V_349 -> V_350 = V_11 -> V_351 ;
V_349 -> V_352 = V_11 -> V_351 ;
if ( F_90 ( V_11 -> V_353 ) )
V_349 -> V_354 = 1 ;
if ( F_90 ( V_11 -> V_355 ) )
V_349 -> V_356 = 1 ;
V_349 -> V_357 = V_11 -> V_353 & ~ V_358 ;
V_349 -> V_359 = V_11 -> V_355 & ~ V_358 ;
return 0 ;
}
static int F_91 ( struct V_5 * V_6 ,
struct V_348 * V_349 )
{
struct V_9 * V_10 = F_4 ( V_6 ) ;
struct V_360 * V_361 ;
struct V_126 * V_11 = V_10 -> V_11 ;
struct V_1 * V_2 = V_11 -> V_12 ;
struct V_13 * V_14 = & V_2 -> V_14 ;
T_4 V_362 ;
int V_173 ;
if ( V_349 -> V_350 || V_349 -> V_352 )
V_11 -> V_351 = V_349 -> V_350 ;
V_362 = V_11 -> V_363 ;
if ( ( V_349 -> V_357 >= ( V_364 << 1 ) ) &&
( V_349 -> V_357 <= ( V_365 << 1 ) ) ) {
V_11 -> V_353 = V_349 -> V_357 ;
} else if ( V_349 -> V_357 == 0 ) {
V_11 -> V_353 = V_349 -> V_357 ;
if ( V_349 -> V_354 )
F_70 ( V_2 , V_325 , V_6 , L_46 ) ;
} else {
F_70 ( V_2 , V_325 , V_6 , L_47 ) ;
return - V_139 ;
}
if ( ( V_349 -> V_359 >= ( V_364 << 1 ) ) &&
( V_349 -> V_359 <= ( V_365 << 1 ) ) ) {
V_11 -> V_355 = V_349 -> V_359 ;
} else if ( V_349 -> V_359 == 0 ) {
V_11 -> V_355 = V_349 -> V_359 ;
if ( V_349 -> V_356 )
F_70 ( V_2 , V_325 , V_6 , L_48 ) ;
} else {
F_70 ( V_2 , V_325 , V_6 ,
L_49 ) ;
return - V_139 ;
}
if ( V_349 -> V_354 )
V_11 -> V_353 |= V_358 ;
else
V_11 -> V_353 &= ~ V_358 ;
if ( V_349 -> V_356 )
V_11 -> V_355 |= V_358 ;
else
V_11 -> V_355 &= ~ V_358 ;
for ( V_173 = 0 ; V_173 < V_11 -> V_366 ; V_173 ++ , V_362 ++ ) {
V_361 = V_11 -> V_367 [ V_173 ] ;
V_361 -> V_368 . V_369 = F_92 ( V_11 -> V_353 ) ;
F_77 ( V_14 , F_93 ( 0 , V_362 - 1 ) , V_361 -> V_368 . V_369 ) ;
V_361 -> V_370 . V_369 = F_92 ( V_11 -> V_355 ) ;
F_77 ( V_14 , F_93 ( 1 , V_362 - 1 ) , V_361 -> V_370 . V_369 ) ;
F_94 ( V_14 ) ;
}
return 0 ;
}
static int F_95 ( struct V_1 * V_2 , struct V_371 * V_135 )
{
V_135 -> V_169 = 0 ;
switch ( V_135 -> V_372 ) {
case V_373 :
case V_374 :
V_135 -> V_169 |= V_375 | V_376 ;
case V_377 :
case V_378 :
case V_379 :
case V_380 :
case V_381 :
V_135 -> V_169 |= V_382 | V_383 ;
break;
case V_384 :
case V_385 :
V_135 -> V_169 |= V_375 | V_376 ;
case V_386 :
case V_387 :
case V_388 :
case V_389 :
case V_390 :
V_135 -> V_169 |= V_382 | V_383 ;
break;
default:
return - V_139 ;
}
return 0 ;
}
static int F_96 ( struct V_1 * V_2 ,
struct V_371 * V_135 ,
T_1 * V_391 )
{
struct V_392 * V_393 ;
struct V_394 * V_395 ;
int V_396 = 0 ;
V_135 -> V_169 = F_97 ( V_2 ) ;
F_98 (rule, node2,
&pf->fdir_filter_list, fdir_node) {
if ( V_396 == V_135 -> V_397 )
return - V_398 ;
V_391 [ V_396 ] = V_393 -> V_399 ;
V_396 ++ ;
}
V_135 -> V_397 = V_396 ;
return 0 ;
}
static int F_99 ( struct V_1 * V_2 ,
struct V_371 * V_135 )
{
struct V_400 * V_401 =
(struct V_400 * ) & V_135 -> V_402 ;
struct V_392 * V_393 = NULL ;
struct V_394 * V_395 ;
F_98 (rule, node2,
&pf->fdir_filter_list, fdir_node) {
if ( V_401 -> V_403 <= V_393 -> V_399 )
break;
}
if ( ! V_393 || V_401 -> V_403 != V_393 -> V_399 )
return - V_139 ;
V_401 -> V_372 = V_393 -> V_372 ;
if ( V_401 -> V_372 == V_404 ) {
V_401 -> V_405 . V_406 . V_407 = V_408 ;
V_401 -> V_405 . V_406 . V_409 = 0 ;
V_401 -> V_410 . V_406 . V_409 = 0 ;
}
V_401 -> V_405 . V_411 . V_412 = V_393 -> V_413 ;
V_401 -> V_405 . V_411 . V_414 = V_393 -> V_415 ;
V_401 -> V_405 . V_411 . V_416 = V_393 -> V_417 [ 0 ] ;
V_401 -> V_405 . V_411 . V_418 = V_393 -> V_419 [ 0 ] ;
if ( V_393 -> V_420 == V_421 )
V_401 -> V_422 = V_423 ;
else
V_401 -> V_422 = V_393 -> V_424 ;
return 0 ;
}
static int F_100 ( struct V_5 * V_6 , struct V_371 * V_135 ,
T_1 * V_391 )
{
struct V_9 * V_10 = F_4 ( V_6 ) ;
struct V_126 * V_11 = V_10 -> V_11 ;
struct V_1 * V_2 = V_11 -> V_12 ;
int V_148 = - V_133 ;
switch ( V_135 -> V_135 ) {
case V_425 :
V_135 -> V_169 = V_11 -> V_242 ;
V_148 = 0 ;
break;
case V_426 :
V_148 = F_95 ( V_2 , V_135 ) ;
break;
case V_427 :
V_135 -> V_397 = V_2 -> V_428 ;
V_135 -> V_169 = F_97 ( V_2 ) ;
V_148 = 0 ;
break;
case V_429 :
V_148 = F_99 ( V_2 , V_135 ) ;
break;
case V_430 :
V_148 = F_96 ( V_2 , V_135 , V_391 ) ;
break;
default:
break;
}
return V_148 ;
}
static int F_101 ( struct V_1 * V_2 , struct V_371 * V_431 )
{
struct V_13 * V_14 = & V_2 -> V_14 ;
T_5 V_432 = ( T_5 ) F_24 ( V_14 , F_102 ( 0 ) ) |
( ( T_5 ) F_24 ( V_14 , F_102 ( 1 ) ) << 32 ) ;
if ( V_431 -> V_169 & ~ ( V_382 | V_383 |
V_375 | V_376 ) )
return - V_139 ;
if ( ! ( V_431 -> V_169 & V_382 ) ||
! ( V_431 -> V_169 & V_383 ) )
return - V_139 ;
switch ( V_431 -> V_372 ) {
case V_373 :
switch ( V_431 -> V_169 & ( V_375 | V_376 ) ) {
case 0 :
V_432 &= ~ ( ( T_5 ) 1 << V_433 ) ;
break;
case ( V_375 | V_376 ) :
V_432 |= ( ( T_5 ) 1 << V_433 ) ;
break;
default:
return - V_139 ;
}
break;
case V_384 :
switch ( V_431 -> V_169 & ( V_375 | V_376 ) ) {
case 0 :
V_432 &= ~ ( ( T_5 ) 1 << V_434 ) ;
break;
case ( V_375 | V_376 ) :
V_432 |= ( ( T_5 ) 1 << V_434 ) ;
break;
default:
return - V_139 ;
}
break;
case V_374 :
switch ( V_431 -> V_169 & ( V_375 | V_376 ) ) {
case 0 :
V_432 &= ~ ( ( ( T_5 ) 1 << V_435 ) |
( ( T_5 ) 1 << V_436 ) ) ;
break;
case ( V_375 | V_376 ) :
V_432 |= ( ( ( T_5 ) 1 << V_435 ) |
( ( T_5 ) 1 << V_436 ) ) ;
break;
default:
return - V_139 ;
}
break;
case V_385 :
switch ( V_431 -> V_169 & ( V_375 | V_376 ) ) {
case 0 :
V_432 &= ~ ( ( ( T_5 ) 1 << V_437 ) |
( ( T_5 ) 1 << V_438 ) ) ;
break;
case ( V_375 | V_376 ) :
V_432 |= ( ( ( T_5 ) 1 << V_437 ) |
( ( T_5 ) 1 << V_438 ) ) ;
break;
default:
return - V_139 ;
}
break;
case V_378 :
case V_379 :
case V_380 :
case V_377 :
if ( ( V_431 -> V_169 & V_375 ) ||
( V_431 -> V_169 & V_376 ) )
return - V_139 ;
V_432 |= ( ( T_5 ) 1 << V_439 ) ;
break;
case V_387 :
case V_388 :
case V_389 :
case V_386 :
if ( ( V_431 -> V_169 & V_375 ) ||
( V_431 -> V_169 & V_376 ) )
return - V_139 ;
V_432 |= ( ( T_5 ) 1 << V_440 ) ;
break;
case V_381 :
V_432 |= ( ( T_5 ) 1 << V_439 ) |
( ( T_5 ) 1 << V_436 ) ;
break;
case V_390 :
V_432 |= ( ( T_5 ) 1 << V_440 ) |
( ( T_5 ) 1 << V_438 ) ;
break;
default:
return - V_139 ;
}
F_77 ( V_14 , F_102 ( 0 ) , ( T_1 ) V_432 ) ;
F_77 ( V_14 , F_102 ( 1 ) , ( T_1 ) ( V_432 >> 32 ) ) ;
F_94 ( V_14 ) ;
return 0 ;
}
static bool F_103 ( struct V_392 * V_393 ,
struct V_392 * V_441 )
{
if ( ( V_393 -> V_417 [ 0 ] != V_441 -> V_417 [ 0 ] ) ||
( V_393 -> V_419 [ 0 ] != V_441 -> V_419 [ 0 ] ) ||
( V_393 -> V_413 != V_441 -> V_413 ) ||
( V_393 -> V_415 != V_441 -> V_415 ) )
return false ;
return true ;
}
static int F_104 ( struct V_126 * V_11 ,
struct V_392 * V_441 ,
T_4 V_442 ,
struct V_371 * V_135 )
{
struct V_392 * V_393 , * V_443 ;
struct V_1 * V_2 = V_11 -> V_12 ;
struct V_394 * V_395 ;
int V_130 = - V_139 ;
V_443 = NULL ;
V_393 = NULL ;
F_98 (rule, node2,
&pf->fdir_filter_list, fdir_node) {
if ( V_393 -> V_399 >= V_442 )
break;
V_443 = V_393 ;
}
if ( V_393 && ( V_393 -> V_399 == V_442 ) ) {
if ( V_441 && ! F_103 ( V_393 , V_441 ) )
V_130 = F_105 ( V_11 , V_393 , false ) ;
else if ( ! V_441 )
V_130 = F_105 ( V_11 , V_393 , false ) ;
F_106 ( & V_393 -> V_444 ) ;
F_32 ( V_393 ) ;
V_2 -> V_428 -- ;
}
if ( ! V_441 )
return V_130 ;
F_107 ( & V_441 -> V_444 ) ;
if ( V_443 )
F_108 ( & V_441 -> V_444 , & V_443 -> V_444 ) ;
else
F_109 ( & V_441 -> V_444 ,
& V_2 -> V_445 ) ;
V_2 -> V_428 ++ ;
return 0 ;
}
static int F_110 ( struct V_126 * V_11 ,
struct V_371 * V_135 )
{
struct V_400 * V_401 =
(struct V_400 * ) & V_135 -> V_402 ;
struct V_1 * V_2 = V_11 -> V_12 ;
int V_148 = 0 ;
if ( F_8 ( V_210 , & V_2 -> V_137 ) ||
F_8 ( V_211 , & V_2 -> V_137 ) )
return - V_212 ;
if ( F_8 ( V_446 , & V_2 -> V_137 ) )
return - V_212 ;
V_148 = F_104 ( V_11 , NULL , V_401 -> V_403 , V_135 ) ;
F_111 ( V_2 ) ;
return V_148 ;
}
static int F_112 ( struct V_126 * V_11 ,
struct V_371 * V_135 )
{
struct V_400 * V_401 ;
struct V_392 * V_441 ;
struct V_1 * V_2 ;
int V_148 = - V_139 ;
if ( ! V_11 )
return - V_139 ;
V_2 = V_11 -> V_12 ;
if ( ! ( V_2 -> V_285 & V_447 ) )
return - V_133 ;
if ( V_2 -> V_448 & V_447 )
return - V_449 ;
if ( F_8 ( V_210 , & V_2 -> V_137 ) ||
F_8 ( V_211 , & V_2 -> V_137 ) )
return - V_212 ;
if ( F_8 ( V_446 , & V_2 -> V_137 ) )
return - V_212 ;
V_401 = (struct V_400 * ) & V_135 -> V_402 ;
if ( V_401 -> V_403 >= ( V_2 -> V_14 . V_450 . V_451 +
V_2 -> V_14 . V_450 . V_452 ) ) {
return - V_139 ;
}
if ( ( V_401 -> V_422 != V_423 ) &&
( V_401 -> V_422 >= V_11 -> V_240 ) )
return - V_139 ;
V_441 = F_28 ( sizeof( * V_441 ) , V_200 ) ;
if ( ! V_441 )
return - V_201 ;
V_441 -> V_399 = V_401 -> V_403 ;
if ( V_401 -> V_422 == V_423 )
V_441 -> V_420 = V_421 ;
else
V_441 -> V_420 =
V_453 ;
V_441 -> V_424 = V_401 -> V_422 ;
V_441 -> V_454 = 0 ;
V_441 -> V_455 = 0 ;
V_441 -> V_456 = V_11 -> V_457 ;
V_441 -> V_458 = V_459 ;
V_441 -> V_460 = V_2 -> V_461 ;
V_441 -> V_372 = V_401 -> V_372 ;
V_441 -> V_462 = V_401 -> V_405 . V_406 . V_409 ;
V_441 -> V_413 = V_401 -> V_405 . V_411 . V_412 ;
V_441 -> V_415 = V_401 -> V_405 . V_411 . V_414 ;
V_441 -> V_417 [ 0 ] = V_401 -> V_405 . V_411 . V_416 ;
V_441 -> V_419 [ 0 ] = V_401 -> V_405 . V_411 . V_418 ;
V_148 = F_105 ( V_11 , V_441 , true ) ;
if ( V_148 )
F_32 ( V_441 ) ;
else
F_104 ( V_11 , V_441 , V_401 -> V_403 , NULL ) ;
return V_148 ;
}
static int F_113 ( struct V_5 * V_6 , struct V_371 * V_135 )
{
struct V_9 * V_10 = F_4 ( V_6 ) ;
struct V_126 * V_11 = V_10 -> V_11 ;
struct V_1 * V_2 = V_11 -> V_12 ;
int V_148 = - V_133 ;
switch ( V_135 -> V_135 ) {
case V_463 :
V_148 = F_101 ( V_2 , V_135 ) ;
break;
case V_464 :
V_148 = F_112 ( V_11 , V_135 ) ;
break;
case V_465 :
V_148 = F_110 ( V_11 , V_135 ) ;
break;
default:
break;
}
return V_148 ;
}
static unsigned int F_114 ( struct V_126 * V_11 )
{
return V_11 -> V_242 ;
}
static void F_115 ( struct V_5 * V_4 ,
struct V_466 * V_467 )
{
struct V_9 * V_10 = F_4 ( V_4 ) ;
struct V_126 * V_11 = V_10 -> V_11 ;
struct V_1 * V_2 = V_11 -> V_12 ;
V_467 -> V_468 = F_114 ( V_11 ) ;
V_467 -> V_469 = ( V_2 -> V_285 & V_447 ) ? 1 : 0 ;
V_467 -> V_470 = V_467 -> V_469 ;
V_467 -> V_471 = V_11 -> V_240 ;
}
static int F_116 ( struct V_5 * V_4 ,
struct V_466 * V_467 )
{
struct V_9 * V_10 = F_4 ( V_4 ) ;
unsigned int V_230 = V_467 -> V_471 ;
struct V_126 * V_11 = V_10 -> V_11 ;
struct V_1 * V_2 = V_11 -> V_12 ;
int V_472 ;
if ( V_11 -> type != V_473 )
return - V_139 ;
if ( ! V_230 || V_467 -> V_474 || V_467 -> V_475 )
return - V_139 ;
if ( V_467 -> V_469 != ( ( V_2 -> V_285 & V_447 ) ? 1 : 0 ) )
return - V_139 ;
if ( V_230 > F_114 ( V_11 ) )
return - V_139 ;
if ( V_230 > V_2 -> V_476 )
V_230 = V_2 -> V_476 ;
V_472 = F_117 ( V_2 , V_230 ) ;
if ( V_472 > 0 )
return 0 ;
else
return - V_139 ;
}
void F_118 ( struct V_5 * V_6 )
{
V_6 -> V_477 = & V_478 ;
}
