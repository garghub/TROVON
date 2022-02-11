int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_5 = 0 ;
struct V_6 * V_7 ;
F_2 (ha, dev)
memcpy ( & V_2 -> V_8 [ V_5 ++ ] , V_7 -> V_9 , V_10 ) ;
return V_5 ;
}
int F_3 ( struct V_11 * V_12 ,
struct V_13 * V_14 )
{
int V_15 ;
V_15 = F_4 ( V_12 -> V_16 . V_17 ,
* ( V_14 -> V_18 ) ) ;
if ( V_15 ) {
F_5 ( V_12 -> V_4 , L_1 , V_15 ) ;
return V_15 ;
}
V_15 = V_12 -> V_16 . V_15 ;
V_12 -> V_16 . V_15 = 0 ;
return V_15 ;
}
int F_6 ( struct V_19 * V_20 ,
struct V_1 * V_21 )
{
int V_22 = 0 ;
T_1 V_23 ;
V_23 = V_20 -> V_24 ;
if ( V_21 -> V_25 == V_26 ) {
F_7 ( V_20 -> V_12 -> V_4 , L_2 ) ;
V_20 -> V_24 |= V_27 ;
V_20 -> V_24 &=
~ V_28 ;
} else {
V_20 -> V_24 &= ~ V_27 ;
if ( V_21 -> V_25 == V_29 ) {
F_7 ( V_20 -> V_12 -> V_4 ,
L_3 ) ;
V_20 -> V_24 |=
V_28 ;
} else {
V_20 -> V_24 &=
~ V_28 ;
if ( V_21 -> V_30 ) {
F_7 ( V_20 -> V_12 -> V_4 ,
L_4 ,
V_21 -> V_30 ) ;
V_22 = F_8 ( V_20 ,
V_31 ,
V_32 , 0 ,
V_21 ) ;
}
}
}
F_7 ( V_20 -> V_12 -> V_4 ,
L_5 ,
V_23 , V_20 -> V_24 ) ;
if ( V_23 != V_20 -> V_24 ) {
V_22 = F_8 ( V_20 , V_33 ,
V_32 ,
0 , & V_20 -> V_24 ) ;
}
return V_22 ;
}
int F_9 ( struct V_19 * V_20 ,
struct V_34 * V_35 ,
struct V_36 * V_37 )
{
T_2 * V_38 ;
T_3 V_39 ;
struct V_40 * V_41 = ( void * ) V_35 -> V_20 ;
const struct V_42 * V_43 ;
F_10 () ;
V_43 = F_11 ( V_35 -> V_43 ) ;
V_38 = F_12 ( V_43 -> V_44 , V_43 -> V_45 , V_46 ) ;
V_39 = V_43 -> V_45 ;
V_37 -> V_47 = V_43 -> V_48 ;
F_13 () ;
if ( ! V_38 ) {
F_5 ( V_20 -> V_12 -> V_4 , L_6 ) ;
return - V_49 ;
}
memcpy ( V_37 -> V_50 , V_35 -> V_51 , V_10 ) ;
V_37 -> V_52 = V_35 -> signal ;
V_37 -> V_53 = V_38 ;
V_37 -> V_54 = V_39 ;
V_37 -> V_55 = V_35 -> V_56 ;
V_37 -> V_57 = V_35 -> V_58 ;
V_37 -> V_59 = V_41 -> V_60 ;
V_37 -> V_61 = V_41 -> V_61 ;
if ( V_37 -> V_57 & V_62 ) {
F_7 ( V_20 -> V_12 -> V_4 , L_7 ) ;
V_37 -> V_63 = V_64 ;
} else {
V_37 -> V_63 = V_65 ;
}
if ( V_37 -> V_57 & V_66 )
V_37 -> V_67 = V_68 ;
else
V_37 -> V_67 = V_69 ;
V_37 -> V_70 = true ;
return F_14 ( V_20 -> V_12 , V_37 ) ;
}
static int F_15 ( struct V_19 * V_20 ,
struct V_34 * V_35 )
{
const T_2 * V_71 ;
T_2 V_72 ;
struct V_73 * V_74 =
& V_20 -> V_12 -> V_75 ;
F_10 () ;
V_71 = F_16 ( V_35 , V_76 ) ;
if ( ! V_71 ) {
F_13 () ;
return 0 ;
}
V_72 = V_71 [ 1 ] ;
if ( V_72 < V_77 ) {
F_13 () ;
return 0 ;
}
V_74 -> V_78 [ 0 ] = V_71 [ 2 ] ;
V_74 -> V_78 [ 1 ] = V_71 [ 3 ] ;
V_74 -> V_78 [ 2 ] = ' ' ;
V_72 -= V_79 ;
V_74 -> V_80 =
V_72 / sizeof( struct V_81 ) ;
memcpy ( ( T_2 * ) V_74 -> V_82 ,
& V_71 [ 2 ] + V_79 , V_72 ) ;
F_13 () ;
if ( F_8 ( V_20 , V_83 ,
V_32 , 0 , NULL ) ) {
F_17 ( V_20 -> V_12 -> V_84 ,
L_8 ) ;
return - 1 ;
}
return 0 ;
}
int F_18 ( struct V_19 * V_20 , struct V_34 * V_35 ,
struct V_85 * V_86 )
{
int V_22 ;
struct V_11 * V_12 = V_20 -> V_12 ;
struct V_36 * V_37 = NULL ;
V_20 -> V_87 = false ;
if ( V_35 ) {
F_15 ( V_20 , V_35 ) ;
V_37 = F_19 ( sizeof( struct V_36 ) ,
V_88 ) ;
if ( ! V_37 )
return - V_49 ;
V_22 = F_9 ( V_20 , V_35 , V_37 ) ;
if ( V_22 )
goto V_89;
}
if ( V_20 -> V_67 == V_69 ) {
V_22 = F_20 ( V_20 , NULL ) ;
if ( V_22 )
goto V_89;
if ( V_37 ) {
T_2 V_90 = 0 ;
if ( F_21 ( ( T_2 ) V_37 -> V_59 )
== V_91 )
V_90 = V_92 | V_93 | V_94 |
V_95 ;
else
V_90 = V_96 | V_97 | V_98 ;
if ( ! ( ( V_90 | V_12 -> V_99 ) &
~ V_12 -> V_99 ) )
V_12 -> V_90 = V_90 ;
}
V_22 = F_22 ( V_20 , V_37 ) ;
if ( V_22 )
goto V_89;
F_7 ( V_12 -> V_4 , L_9
L_10 ) ;
F_23 ( V_20 -> V_100 , V_12 ) ;
if ( F_24 ( V_20 -> V_100 ) )
F_25 ( V_20 -> V_100 ) ;
V_20 -> V_101 = 0 ;
V_22 = F_26 ( V_20 , V_37 ) ;
if ( V_22 == V_102 &&
V_20 -> V_103 . V_104 &&
V_20 -> V_103 . V_105 ) {
V_20 -> V_103 . V_106 =
V_107 ;
V_22 = F_26 ( V_20 , V_37 ) ;
}
if ( V_35 )
F_27 ( V_20 -> V_12 -> V_84 , V_35 ) ;
} else {
if ( V_37 && V_37 -> V_108 . V_109 &&
( ! F_28 ( & V_20 -> V_110 . V_111 .
V_108 , & V_37 -> V_108 ) ) ) {
F_29 ( V_37 ) ;
return 0 ;
}
F_7 ( V_12 -> V_4 , L_11 ) ;
V_22 = F_20 ( V_20 , NULL ) ;
if ( V_22 )
goto V_89;
V_20 -> V_112 = false ;
V_22 = F_22 ( V_20 , V_37 ) ;
F_23 ( V_20 -> V_100 , V_12 ) ;
if ( F_24 ( V_20 -> V_100 ) )
F_25 ( V_20 -> V_100 ) ;
if ( ! V_22 ) {
F_7 ( V_12 -> V_4 , L_12
L_13 ) ;
V_22 = F_30 ( V_20 , V_37 ) ;
if ( V_35 )
F_27 ( V_20 -> V_12 -> V_84 , V_35 ) ;
} else {
F_7 ( V_12 -> V_4 , L_14
L_15 ,
V_86 -> V_108 ) ;
V_22 = F_31 ( V_20 , V_86 ) ;
}
}
V_89:
if ( V_37 )
F_29 ( V_37 -> V_53 ) ;
F_29 ( V_37 ) ;
return V_22 ;
}
static int F_32 ( struct V_19 * V_20 , T_1 V_113 ,
int V_114 , struct V_115 * V_116 )
{
struct V_11 * V_12 = V_20 -> V_12 ;
int V_15 = 0 ;
T_4 V_117 = 0 ;
if ( ! V_116 )
return - V_49 ;
switch ( V_113 ) {
case V_32 :
if ( V_12 -> V_118 ) {
F_7 ( V_12 -> V_4 , L_16
L_17 ) ;
V_15 = - 1 ;
break;
}
if ( V_116 -> V_119 ) {
if ( V_116 -> V_120 == V_121 ) {
if ( ! V_12 -> V_122 )
break;
V_117 = F_33 ( V_12 -> V_116
. V_120 ) ;
V_12 -> V_116 . V_120 =
F_34 ( V_116 -> V_120 ) ;
} else if ( V_116 -> V_120 ) {
V_12 -> V_116 . V_120 =
F_34 ( V_116 -> V_120 ) ;
V_12 -> V_116 . V_123 = ( T_2 ) V_116 -> V_123 ;
if ( V_116 -> V_124 )
V_12 -> V_116 . V_124 = ( T_2 ) V_116 -> V_124 ;
} else if ( V_12 -> V_116 . V_120 ==
F_34 ( V_121 ) ) {
V_15 = - 1 ;
break;
}
if ( V_114 == V_125 )
V_15 = F_35 ( V_20 ,
V_126 ,
V_32 , 0 ,
& V_12 -> V_116 ) ;
else
V_15 = F_8 ( V_20 ,
V_126 ,
V_32 , 0 ,
& V_12 -> V_116 ) ;
if ( V_116 -> V_120 == V_121 )
V_12 -> V_116 . V_120 =
F_34 ( V_117 ) ;
} else {
V_12 -> V_116 . V_120 =
F_34 ( V_116 -> V_120 ) ;
V_12 -> V_116 . V_123 = ( T_2 ) V_116 -> V_123 ;
V_12 -> V_116 . V_124 = ( T_2 ) V_116 -> V_124 ;
}
break;
case V_127 :
V_116 -> V_120 = F_33 ( V_12 -> V_116 . V_120 ) ;
V_116 -> V_123 = V_12 -> V_116 . V_123 ;
V_116 -> V_124 = V_12 -> V_116 . V_124 ;
break;
default:
V_15 = - 1 ;
break;
}
return V_15 ;
}
int F_36 ( struct V_19 * V_20 , int V_114 )
{
struct V_115 V_128 ;
V_128 . V_120 = V_121 ;
V_128 . V_119 = true ;
return F_32 ( V_20 , V_32 ,
V_114 , & V_128 ) ;
}
int F_37 ( struct V_11 * V_12 )
{
struct V_115 V_128 ;
struct V_19 * V_20 ;
int V_5 ;
if ( V_129 ) {
for ( V_5 = 0 ; V_5 < V_12 -> V_130 ; V_5 ++ ) {
V_20 = V_12 -> V_20 [ V_5 ] ;
if ( V_20 )
F_20 ( V_20 , NULL ) ;
}
}
if ( V_12 -> V_131 ) {
F_7 ( V_12 -> V_4 , L_18 ) ;
return true ;
}
V_12 -> V_132 = false ;
memset ( & V_128 , 0 , sizeof( struct V_115 ) ) ;
V_128 . V_119 = true ;
if ( F_32 ( F_38 ( V_12 ,
V_133 ) ,
V_32 , V_125 ,
& V_128 ) ) {
F_5 ( V_12 -> V_4 , L_19 ) ;
return false ;
}
if ( F_4 ( V_12 -> V_134 ,
V_12 -> V_132 ) ) {
F_5 ( V_12 -> V_4 , L_20 ) ;
return false ;
}
return true ;
}
int F_39 ( struct V_19 * V_20 ,
struct V_135 * V_136 )
{
struct V_11 * V_12 = V_20 -> V_12 ;
struct V_36 * V_37 ;
if ( ! V_136 )
return - 1 ;
V_37 = & V_20 -> V_110 . V_111 ;
V_136 -> V_67 = V_20 -> V_67 ;
memcpy ( & V_136 -> V_108 , & V_37 -> V_108 , sizeof( struct V_85 ) ) ;
memcpy ( & V_136 -> V_51 , & V_37 -> V_50 , V_10 ) ;
V_136 -> V_137 = V_37 -> V_138 ;
memcpy ( V_136 -> V_78 , V_12 -> V_78 ,
V_79 ) ;
V_136 -> V_139 = V_20 -> V_139 ;
V_136 -> V_140 = V_20 -> V_141 ;
V_136 -> V_142 = V_20 -> V_143 ;
V_136 -> V_144 = V_20 -> V_144 ;
V_136 -> V_145 = V_20 -> V_145 ;
if ( V_20 -> V_103 . V_105 )
V_136 -> V_146 = true ;
else
V_136 -> V_146 = false ;
V_136 -> V_122 = V_12 -> V_122 ;
V_136 -> V_147 = V_12 -> V_147 ;
return 0 ;
}
int F_40 ( struct V_19 * V_20 )
{
struct V_148 V_149 ;
V_149 . V_149 = V_150 ;
return F_35 ( V_20 , V_151 ,
V_152 , V_153 , & V_149 ) ;
}
int F_41 ( struct V_19 * V_20 , T_4 * V_154 )
{
int V_22 ;
V_22 = F_35 ( V_20 , V_155 ,
V_127 , 0 , NULL ) ;
if ( ! V_22 ) {
if ( V_20 -> V_156 )
* V_154 = F_42 ( V_20 , V_20 -> V_157 ,
V_20 -> V_158 ) ;
else
* V_154 = V_20 -> V_159 ;
}
return V_22 ;
}
int F_43 ( struct V_19 * V_20 ,
struct V_160 * V_161 )
{
int V_22 ;
struct V_162 * V_163 ;
struct V_164 * V_165 ;
struct V_166 * V_167 ;
T_2 * V_168 ;
T_1 V_169 = 0 ;
if ( ! V_161 -> V_170 ) {
V_169 = ( T_1 ) V_161 -> V_171 ;
if ( ( V_169 < V_20 -> V_143 ) ||
( V_169 > V_20 -> V_141 ) ) {
F_5 ( V_20 -> V_12 -> V_4 , L_21
L_22 ,
V_169 , V_20 -> V_143 ,
V_20 -> V_141 ) ;
return - 1 ;
}
}
V_168 = F_19 ( V_172 , V_88 ) ;
if ( ! V_168 )
return - V_49 ;
V_163 = (struct V_162 * ) V_168 ;
V_163 -> V_113 = F_44 ( V_32 ) ;
if ( ! V_161 -> V_170 ) {
V_163 -> V_25 = F_34 ( 1 ) ;
V_165 = (struct V_164 * )
( V_168 + sizeof( struct V_162 ) ) ;
V_165 -> type = V_173 ;
V_165 -> V_174 = 4 * sizeof( struct V_166 ) ;
V_167 = (struct V_166 * )
( V_168 + sizeof( struct V_162 )
+ sizeof( struct V_164 ) ) ;
V_167 -> V_175 = 0x00 ;
V_167 -> V_176 = 0x03 ;
V_167 -> V_177 = V_178 ;
V_167 -> V_179 = 0 ;
V_167 -> V_180 = ( V_181 ) V_169 ;
V_167 -> V_182 = ( V_181 ) V_169 ;
V_167 ++ ;
V_167 -> V_175 = 0x00 ;
V_167 -> V_176 = 0x07 ;
V_167 -> V_177 = V_183 ;
V_167 -> V_179 = 0 ;
V_167 -> V_180 = ( V_181 ) V_169 ;
V_167 -> V_182 = ( V_181 ) V_169 ;
V_167 ++ ;
V_167 -> V_175 = 0x00 ;
V_167 -> V_176 = 0x20 ;
V_167 -> V_177 = V_184 ;
V_167 -> V_179 = 0 ;
V_167 -> V_180 = ( V_181 ) V_169 ;
V_167 -> V_182 = ( V_181 ) V_169 ;
V_167 -> V_185 = V_186 ;
V_167 ++ ;
V_167 -> V_175 = 0x00 ;
V_167 -> V_176 = 0x20 ;
V_167 -> V_177 = V_184 ;
V_167 -> V_179 = 0 ;
V_167 -> V_180 = ( V_181 ) V_169 ;
V_167 -> V_182 = ( V_181 ) V_169 ;
V_167 -> V_185 = V_187 ;
}
V_22 = F_35 ( V_20 , V_188 ,
V_32 , 0 , V_168 ) ;
F_29 ( V_168 ) ;
return V_22 ;
}
int F_45 ( struct V_19 * V_20 , T_4 * V_189 )
{
int V_22 ;
struct V_11 * V_12 = V_20 -> V_12 ;
T_1 V_190 ;
if ( * V_189 )
V_12 -> V_189 = V_191 ;
else
V_12 -> V_189 = V_192 ;
V_190 = ( * V_189 ) ? V_193 : V_152 ;
V_22 = F_35 ( V_20 , V_151 ,
V_190 , V_194 , NULL ) ;
if ( ( ! V_22 ) && ( V_190 == V_152 ) )
V_22 = F_8 ( V_20 ,
V_151 ,
V_195 , 0 , NULL ) ;
return V_22 ;
}
static int F_46 ( struct V_19 * V_20 ,
T_2 * V_196 , T_1 V_197 )
{
if ( V_197 ) {
if ( V_197 > sizeof( V_20 -> V_198 ) ) {
F_5 ( V_20 -> V_12 -> V_4 ,
L_23 ) ;
return - 1 ;
}
memcpy ( V_20 -> V_198 , V_196 , V_197 ) ;
V_20 -> V_199 = ( T_2 ) V_197 ;
F_7 ( V_20 -> V_12 -> V_4 , L_24 ,
V_20 -> V_199 , V_20 -> V_198 [ 0 ] ) ;
if ( V_20 -> V_198 [ 0 ] == V_200 ) {
V_20 -> V_103 . V_201 = true ;
} else if ( V_20 -> V_198 [ 0 ] == V_202 ) {
V_20 -> V_103 . V_203 = true ;
} else {
V_20 -> V_103 . V_201 = false ;
V_20 -> V_103 . V_203 = false ;
}
} else {
memset ( V_20 -> V_198 , 0 , sizeof( V_20 -> V_198 ) ) ;
V_20 -> V_199 = 0 ;
F_7 ( V_20 -> V_12 -> V_4 , L_25 ,
V_20 -> V_199 , V_20 -> V_198 [ 0 ] ) ;
V_20 -> V_103 . V_201 = false ;
V_20 -> V_103 . V_203 = false ;
}
return 0 ;
}
static int F_47 ( struct V_19 * V_20 ,
T_2 * V_196 , T_1 V_197 )
{
if ( V_197 ) {
if ( V_197 > sizeof( V_20 -> V_204 ) ) {
F_7 ( V_20 -> V_12 -> V_4 ,
L_26 ) ;
return - 1 ;
}
memcpy ( V_20 -> V_204 , V_196 , V_197 ) ;
V_20 -> V_205 = V_197 ;
F_7 ( V_20 -> V_12 -> V_4 , L_27 ,
V_20 -> V_205 , V_20 -> V_204 [ 0 ] ) ;
if ( V_20 -> V_204 [ 0 ] == V_206 )
V_20 -> V_103 . V_207 = true ;
} else {
memset ( V_20 -> V_204 , 0 , sizeof( V_20 -> V_204 ) ) ;
V_20 -> V_205 = V_197 ;
F_7 ( V_20 -> V_12 -> V_4 ,
L_28 ,
V_20 -> V_205 , V_20 -> V_204 [ 0 ] ) ;
V_20 -> V_103 . V_207 = false ;
}
return 0 ;
}
static int F_48 ( struct V_19 * V_20 ,
T_2 * V_196 , T_1 V_197 )
{
if ( V_197 ) {
V_20 -> V_208 = F_19 ( V_209 , V_88 ) ;
if ( ! V_20 -> V_208 )
return - V_49 ;
if ( V_197 > sizeof( V_20 -> V_208 ) ) {
F_7 ( V_20 -> V_12 -> V_4 ,
L_29 ) ;
F_29 ( V_20 -> V_208 ) ;
return - 1 ;
}
memcpy ( V_20 -> V_208 , V_196 , V_197 ) ;
V_20 -> V_210 = V_197 ;
F_7 ( V_20 -> V_12 -> V_4 , L_30 ,
V_20 -> V_210 , V_20 -> V_208 [ 0 ] ) ;
} else {
F_29 ( V_20 -> V_208 ) ;
V_20 -> V_210 = V_197 ;
F_7 ( V_20 -> V_12 -> V_4 ,
L_31 , V_20 -> V_210 ) ;
}
return 0 ;
}
static int F_49 ( struct V_19 * V_20 ,
struct V_211 * V_212 )
{
return F_35 ( V_20 , V_213 ,
V_32 , V_214 ,
V_212 ) ;
}
static int F_50 ( struct V_19 * V_20 ,
struct V_211 * V_212 )
{
int V_22 ;
struct V_215 * V_216 ;
int V_217 ;
if ( V_20 -> V_218 >= V_219 )
V_20 -> V_218 = 0 ;
V_216 = & V_20 -> V_216 [ V_20 -> V_218 ] ;
V_217 = V_212 -> V_220 ;
if ( V_212 -> V_221 ) {
V_20 -> V_103 . V_105 = 0 ;
} else if ( ! V_212 -> V_222 ) {
V_216 = & V_20 -> V_216 [ V_217 ] ;
if ( ! V_216 -> V_223 ) {
F_5 ( V_20 -> V_12 -> V_4 ,
L_32 ) ;
return - 1 ;
}
V_20 -> V_218 = ( T_1 ) V_217 ;
V_20 -> V_103 . V_105 = 1 ;
} else {
V_216 = & V_20 -> V_216 [ V_217 ] ;
memset ( V_216 , 0 , sizeof( struct V_215 ) ) ;
memcpy ( V_216 -> V_224 ,
V_212 -> V_224 ,
V_212 -> V_222 ) ;
V_216 -> V_220 = V_217 ;
V_216 -> V_223 = V_212 -> V_222 ;
V_20 -> V_103 . V_105 = 1 ;
}
if ( V_216 -> V_223 ) {
V_22 = F_8 ( V_20 ,
V_213 ,
V_32 , 0 , NULL ) ;
if ( V_22 )
return V_22 ;
}
if ( V_20 -> V_103 . V_105 )
V_20 -> V_24 |= V_225 ;
else
V_20 -> V_24 &= ~ V_225 ;
V_22 = F_35 ( V_20 , V_33 ,
V_32 , 0 ,
& V_20 -> V_24 ) ;
return V_22 ;
}
static int F_51 ( struct V_19 * V_20 ,
struct V_211 * V_212 )
{
int V_22 ;
T_2 V_226 = false ;
struct V_227 * V_228 ;
if ( V_212 -> V_222 > V_229 ) {
F_5 ( V_20 -> V_12 -> V_4 , L_33 ) ;
return - 1 ;
}
if ( V_20 -> V_67 == V_68 ) {
V_212 -> V_220 = V_230 ;
V_22 = F_8 ( V_20 ,
V_213 ,
V_32 ,
V_214 , V_212 ) ;
if ( V_22 )
return V_22 ;
V_228 = & V_20 -> V_231 ;
memset ( V_228 , 0 ,
sizeof( struct V_227 ) ) ;
memcpy ( V_228 -> V_232 . V_233 , V_212 -> V_224 ,
V_212 -> V_222 ) ;
memcpy ( & V_228 -> V_232 . V_222 , & V_212 -> V_222 ,
sizeof( V_228 -> V_232 . V_222 ) ) ;
V_228 -> V_232 . V_234
= F_44 ( V_235 ) ;
V_228 -> V_232 . V_236 = F_44 ( V_237 ) ;
V_212 -> V_220 = ~ V_230 ;
}
if ( ! V_212 -> V_220 )
V_212 -> V_220 = V_230 ;
if ( V_226 )
V_22 = F_35 ( V_20 ,
V_213 ,
V_32 ,
! V_214 , V_212 ) ;
else
V_22 = F_35 ( V_20 ,
V_213 ,
V_32 ,
V_214 , V_212 ) ;
return V_22 ;
}
static int
F_52 ( struct V_19 * V_20 ,
struct V_211 * V_212 )
{
int V_15 ;
if ( V_212 -> V_238 )
V_15 = F_49 ( V_20 , V_212 ) ;
else if ( V_212 -> V_222 > V_239 )
V_15 = F_51 ( V_20 , V_212 ) ;
else
V_15 = F_50 ( V_20 , V_212 ) ;
return V_15 ;
}
int
F_53 ( struct V_11 * V_12 , char * V_240 ,
int V_241 )
{
union {
T_4 V_242 ;
T_2 V_243 [ 4 ] ;
} V_244 ;
char V_245 [ 32 ] ;
V_244 . V_242 = V_12 -> V_246 ;
sprintf ( V_245 , L_34 , V_244 . V_243 [ 2 ] , V_244 . V_243 [ 1 ] , V_244 . V_243 [ 0 ] , V_244 . V_243 [ 3 ] ) ;
snprintf ( V_240 , V_241 , V_247 , V_245 ) ;
F_7 ( V_12 -> V_4 , L_35 , V_240 ) ;
return 0 ;
}
int F_54 ( struct V_19 * V_20 , struct V_248 * V_249 ,
const T_2 * V_233 , int V_222 , T_2 V_220 ,
const T_2 * V_250 , int V_251 )
{
struct V_211 V_212 ;
memset ( & V_212 , 0 , sizeof( struct V_211 ) ) ;
V_212 . V_222 = V_222 ;
if ( V_249 && V_249 -> V_252 == V_253 )
V_212 . V_254 = true ;
if ( ! V_251 ) {
V_212 . V_220 = V_220 ;
if ( V_222 )
memcpy ( V_212 . V_224 , V_233 , V_222 ) ;
if ( V_250 )
memcpy ( V_212 . V_250 , V_250 , V_10 ) ;
if ( V_249 && V_249 -> V_255 && V_249 -> V_256 )
memcpy ( V_212 . V_257 , V_249 -> V_255 , V_249 -> V_256 ) ;
} else {
V_212 . V_221 = true ;
if ( V_250 )
memcpy ( V_212 . V_250 , V_250 , V_10 ) ;
}
return F_52 ( V_20 , & V_212 ) ;
}
int
F_55 ( struct V_19 * V_20 )
{
struct V_258 V_259 ;
memset ( & V_259 , 0 , sizeof( struct V_260 ) ) ;
if ( F_35 ( V_20 , V_261 ,
V_127 , 0 , & V_259 ) )
return - 1 ;
return 0 ;
}
int
F_56 ( struct V_19 * V_20 , T_1 V_113 ,
struct V_262 * V_263 ,
unsigned int V_264 )
{
struct V_265 V_266 ;
T_2 V_267 ;
memset ( & V_266 , 0 , sizeof( V_266 ) ) ;
V_266 . V_113 = F_44 ( V_113 ) ;
if ( V_113 == V_32 ) {
V_266 . V_268 = V_263 -> V_60 ;
V_267 = F_57 ( V_269 ) ;
V_266 . V_268 |= ( V_267 << 2 ) ;
V_266 . V_138 =
F_58 ( V_263 -> V_270 ) ;
V_266 . V_264 = F_34 ( V_264 ) ;
}
if ( F_35 ( V_20 , V_271 ,
V_113 , 0 , & V_266 ) ) {
F_5 ( V_20 -> V_12 -> V_4 , L_36 ) ;
return - 1 ;
}
return V_266 . V_15 ;
}
int
F_59 ( struct V_19 * V_20 , T_2 V_272 )
{
if ( F_60 ( V_20 ) == V_272 ) {
F_7 ( V_20 -> V_12 -> V_4 ,
L_37 ) ;
return 0 ;
}
F_61 ( V_20 ) ;
F_62 ( V_20 ) ;
V_20 -> V_272 = V_272 ;
switch ( V_272 ) {
case V_273 :
V_20 -> V_67 = V_274 ;
break;
case V_133 :
case V_275 :
default:
V_20 -> V_67 = V_69 ;
break;
}
F_35 ( V_20 , V_276 ,
V_32 , 0 , NULL ) ;
return F_63 ( V_20 , false ) ;
}
int
F_64 ( struct V_19 * V_20 ,
struct V_277 * log )
{
return F_35 ( V_20 , V_278 ,
V_127 , 0 , log ) ;
}
static int F_65 ( struct V_19 * V_20 ,
struct V_279 * V_280 ,
T_1 V_113 )
{
T_1 V_281 ;
switch ( F_33 ( V_280 -> type ) ) {
case V_282 :
V_281 = V_283 ;
break;
case V_284 :
V_281 = V_285 ;
break;
case V_286 :
V_281 = V_287 ;
break;
case V_288 :
V_281 = V_289 ;
break;
case V_290 :
V_281 = V_291 ;
break;
default:
return - 1 ;
}
return F_35 ( V_20 , V_281 , V_113 , 0 , V_280 ) ;
}
int
F_66 ( struct V_19 * V_20 , T_4 V_292 ,
T_4 V_293 , T_4 V_294 )
{
struct V_279 V_280 ;
V_280 . type = F_34 ( V_292 ) ;
V_280 . V_295 = F_34 ( V_293 ) ;
V_280 . V_296 = F_34 ( V_294 ) ;
return F_65 ( V_20 , & V_280 , V_32 ) ;
}
int
F_67 ( struct V_19 * V_20 , T_4 V_292 ,
T_4 V_293 , T_4 * V_296 )
{
int V_22 ;
struct V_279 V_280 ;
V_280 . type = F_34 ( V_292 ) ;
V_280 . V_295 = F_34 ( V_293 ) ;
V_22 = F_65 ( V_20 , & V_280 , V_127 ) ;
if ( V_22 )
goto V_89;
* V_296 = F_33 ( V_280 . V_296 ) ;
V_89:
return V_22 ;
}
int
F_68 ( struct V_19 * V_20 , T_1 V_295 , T_1 V_297 ,
T_2 * V_296 )
{
int V_22 ;
struct V_298 V_299 ;
V_299 . V_295 = F_44 ( ( T_1 ) V_295 ) ;
V_299 . V_300 = F_44 ( ( T_1 ) V_297 ) ;
V_22 = F_35 ( V_20 , V_301 ,
V_127 , 0 , & V_299 ) ;
if ( ! V_22 )
memcpy ( V_296 , V_299 . V_296 , V_302 ) ;
return V_22 ;
}
static int
F_69 ( struct V_19 * V_20 , T_2 * V_196 ,
T_1 V_197 )
{
int V_22 = 0 ;
struct V_303 * V_304 ;
const T_2 V_305 [] = { 0x00 , 0x50 , 0xf2 , 0x01 } ;
const T_2 V_306 [] = { 0x00 , 0x50 , 0xf2 , 0x04 } ;
if ( ! V_197 ) {
V_20 -> V_307 = 0 ;
V_20 -> V_308 . V_309 = false ;
return 0 ;
} else if ( ! V_196 ) {
return - 1 ;
}
V_304 = (struct V_303 * ) V_196 ;
if ( ( ( V_304 -> V_310 == V_200 ) &&
( ! memcmp ( V_304 -> V_311 , V_305 , sizeof( V_305 ) ) ) ) ||
( V_304 -> V_310 == V_202 ) ) {
V_22 = F_46 ( V_20 , V_196 , V_197 ) ;
V_20 -> V_308 . V_309 = false ;
return V_22 ;
} else if ( V_304 -> V_310 == V_206 ) {
V_22 = F_47 ( V_20 , V_196 , V_197 ) ;
return V_22 ;
}
if ( V_197 < ( sizeof( V_20 -> V_312 ) - V_20 -> V_307 ) ) {
V_304 = (struct V_303 * ) V_196 ;
if ( ( V_304 -> V_310 == V_200 ) &&
( ! memcmp ( V_304 -> V_311 , V_306 , sizeof( V_306 ) ) ) ) {
V_20 -> V_308 . V_309 = true ;
F_7 ( V_20 -> V_12 -> V_4 ,
L_38 ) ;
V_22 = F_48 ( V_20 , V_196 , V_197 ) ;
}
memcpy ( V_20 -> V_312 + V_20 -> V_307 , V_196 ,
V_197 ) ;
V_20 -> V_307 += V_197 ;
} else {
V_22 = - 1 ;
}
return V_22 ;
}
static int F_70 ( struct V_19 * V_20 ,
struct V_313 * V_314 ,
T_1 V_113 )
{
struct V_11 * V_12 = V_20 -> V_12 ;
switch ( V_314 -> type ) {
case V_315 :
if ( V_113 == V_127 ) {
V_314 -> V_45 = V_20 -> V_199 ;
memcpy ( V_314 -> V_316 , V_20 -> V_198 , V_314 -> V_45 ) ;
} else {
F_69 ( V_20 , V_314 -> V_316 ,
( T_1 ) V_314 -> V_45 ) ;
}
break;
case V_317 :
memset ( V_12 -> V_318 , 0 , sizeof( V_12 -> V_318 ) ) ;
if ( V_314 -> V_45 > V_319 ) {
V_12 -> V_320 = 0 ;
F_5 ( V_12 -> V_4 , L_39 ) ;
return - 1 ;
} else {
memcpy ( V_12 -> V_318 , V_314 -> V_316 ,
V_314 -> V_45 ) ;
V_12 -> V_320 = V_314 -> V_45 ;
}
break;
default:
F_5 ( V_12 -> V_4 , L_40 ) ;
return - 1 ;
}
return 0 ;
}
int
F_71 ( struct V_19 * V_20 , T_2 * V_321 , int V_197 )
{
struct V_313 V_314 ;
if ( V_197 > V_322 )
return - V_323 ;
V_314 . type = V_315 ;
V_314 . V_45 = V_197 ;
memcpy ( V_314 . V_316 , V_321 , V_197 ) ;
if ( F_70 ( V_20 , & V_314 , V_32 ) )
return - V_323 ;
return 0 ;
}
