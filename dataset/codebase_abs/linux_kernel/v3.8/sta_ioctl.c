int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_5 = 0 ;
struct V_6 * V_7 ;
F_2 (ha, dev)
memcpy ( & V_2 -> V_8 [ V_5 ++ ] , V_7 -> V_9 , V_10 ) ;
return V_5 ;
}
int F_3 ( struct V_11 * V_12 )
{
int V_13 ;
struct V_14 * V_15 ;
if ( ! V_12 -> V_15 )
return 0 ;
V_15 = V_12 -> V_15 ;
V_12 -> V_15 = NULL ;
F_4 ( V_12 -> V_4 , L_1 ) ;
F_5 ( & V_12 -> V_16 ) ;
V_13 = F_6 ( V_12 -> V_17 . V_18 ,
* ( V_15 -> V_19 ) ) ;
if ( V_13 ) {
F_7 ( V_12 -> V_4 , L_2 , V_13 ) ;
return V_13 ;
}
V_13 = V_12 -> V_17 . V_13 ;
V_12 -> V_17 . V_13 = 0 ;
return V_13 ;
}
int F_8 ( struct V_20 * V_21 ,
struct V_1 * V_22 )
{
int V_23 = 0 ;
T_1 V_24 ;
V_24 = V_21 -> V_25 ;
if ( V_22 -> V_26 == V_27 ) {
F_4 ( V_21 -> V_12 -> V_4 , L_3 ) ;
V_21 -> V_25 |= V_28 ;
V_21 -> V_25 &=
~ V_29 ;
} else {
V_21 -> V_25 &= ~ V_28 ;
if ( V_22 -> V_26 == V_30 ) {
F_4 ( V_21 -> V_12 -> V_4 ,
L_4 ) ;
V_21 -> V_25 |=
V_29 ;
} else {
V_21 -> V_25 &=
~ V_29 ;
if ( V_22 -> V_31 ) {
F_4 ( V_21 -> V_12 -> V_4 ,
L_5 ,
V_22 -> V_31 ) ;
if ( V_24 == V_21 -> V_25 ) {
V_23 = F_9 ( V_21 ,
V_32 ,
V_33 , 0 ,
V_22 ) ;
} else {
V_23 = F_9 ( V_21 ,
V_32 ,
V_33 , 0 ,
V_22 ) ;
}
}
}
}
F_4 ( V_21 -> V_12 -> V_4 ,
L_6 ,
V_24 , V_21 -> V_25 ) ;
if ( V_24 != V_21 -> V_25 ) {
V_23 = F_9 ( V_21 , V_34 ,
V_33 ,
0 , & V_21 -> V_25 ) ;
}
return V_23 ;
}
int F_10 ( struct V_20 * V_21 ,
struct V_35 * V_36 ,
struct V_37 * V_38 )
{
int V_23 ;
T_2 * V_39 ;
T_3 V_40 ;
struct V_41 * V_42 = ( void * ) V_36 -> V_21 ;
const struct V_43 * V_44 ;
F_11 () ;
V_44 = F_12 ( V_36 -> V_44 ) ;
if ( F_13 ( ! V_44 ) ) {
F_14 () ;
return - V_45 ;
}
V_39 = F_15 ( V_44 -> V_46 , V_44 -> V_47 , V_48 ) ;
V_40 = V_44 -> V_47 ;
F_14 () ;
if ( ! V_39 ) {
F_7 ( V_21 -> V_12 -> V_4 , L_7 ) ;
return - V_49 ;
}
memcpy ( V_38 -> V_50 , V_36 -> V_51 , V_10 ) ;
V_38 -> V_52 = V_36 -> signal ;
V_38 -> V_53 = V_39 ;
V_38 -> V_54 = V_40 ;
V_38 -> V_55 = V_36 -> V_56 ;
V_38 -> V_57 = V_36 -> V_58 ;
V_38 -> V_59 = V_42 -> V_60 ;
V_38 -> V_61 = V_42 -> V_61 ;
V_38 -> V_62 = V_36 -> V_63 ;
if ( V_38 -> V_57 & V_64 ) {
F_4 ( V_21 -> V_12 -> V_4 , L_8 ) ;
V_38 -> V_65 = V_66 ;
} else {
V_38 -> V_65 = V_67 ;
}
if ( V_38 -> V_57 & V_68 )
V_38 -> V_69 = V_70 ;
else
V_38 -> V_69 = V_71 ;
V_23 = F_16 ( V_21 -> V_12 , V_38 ) ;
F_17 ( V_39 ) ;
return V_23 ;
}
static int F_18 ( struct V_20 * V_21 ,
struct V_35 * V_36 )
{
const T_2 * V_72 ;
T_2 V_73 ;
struct V_74 * V_75 =
& V_21 -> V_12 -> V_76 ;
F_11 () ;
V_72 = F_19 ( V_36 , V_77 ) ;
if ( ! V_72 ) {
F_14 () ;
return 0 ;
}
V_73 = V_72 [ 1 ] ;
if ( V_73 < V_78 ) {
F_14 () ;
return 0 ;
}
V_75 -> V_79 [ 0 ] = V_72 [ 2 ] ;
V_75 -> V_79 [ 1 ] = V_72 [ 3 ] ;
V_75 -> V_79 [ 2 ] = ' ' ;
V_73 -= V_80 ;
V_75 -> V_81 =
V_73 / sizeof( struct V_82 ) ;
memcpy ( ( T_2 * ) V_75 -> V_83 ,
& V_72 [ 2 ] + V_80 , V_73 ) ;
F_14 () ;
if ( F_9 ( V_21 , V_84 ,
V_33 , 0 , NULL ) ) {
F_20 ( V_21 -> V_12 -> V_85 ,
L_9 ) ;
return - 1 ;
}
return 0 ;
}
int F_21 ( struct V_20 * V_21 , struct V_35 * V_36 ,
struct V_86 * V_87 )
{
int V_23 ;
struct V_11 * V_12 = V_21 -> V_12 ;
struct V_37 * V_38 = NULL ;
V_21 -> V_88 = false ;
if ( V_36 ) {
F_18 ( V_21 , V_36 ) ;
V_38 = F_22 ( sizeof( struct V_37 ) ,
V_89 ) ;
if ( ! V_38 ) {
F_7 ( V_21 -> V_12 -> V_4 , L_10 ) ;
return - V_49 ;
}
V_23 = F_10 ( V_21 , V_36 , V_38 ) ;
if ( V_23 )
goto V_90;
}
if ( V_21 -> V_69 == V_71 ) {
V_23 = F_23 ( V_21 , NULL ) ;
if ( V_23 )
goto V_90;
if ( V_38 ) {
T_2 V_91 = 0 ;
if ( F_24 ( ( T_2 ) V_38 -> V_59 )
== V_92 )
V_91 = V_93 | V_94 | V_95 ;
else
V_91 = V_96 | V_97 ;
if ( ! ( ( V_91 | V_12 -> V_98 ) &
~ V_12 -> V_98 ) )
V_12 -> V_91 = V_91 ;
}
V_23 = F_25 ( V_21 , V_38 ) ;
if ( V_23 )
goto V_90;
F_4 ( V_12 -> V_4 , L_11
L_12 ) ;
F_26 ( V_21 -> V_99 , V_12 ) ;
if ( F_27 ( V_21 -> V_99 ) )
F_28 ( V_21 -> V_99 ) ;
V_21 -> V_100 = 0 ;
V_23 = F_29 ( V_21 , V_38 ) ;
if ( V_23 == V_101 &&
V_21 -> V_102 . V_103 &&
V_21 -> V_102 . V_104 ) {
V_21 -> V_102 . V_105 =
V_106 ;
V_23 = F_29 ( V_21 , V_38 ) ;
}
if ( V_36 )
F_30 ( V_36 ) ;
} else {
if ( V_38 && V_38 -> V_107 . V_108 &&
( ! F_31 ( & V_21 -> V_109 . V_110 .
V_107 , & V_38 -> V_107 ) ) ) {
F_17 ( V_38 ) ;
return 0 ;
}
F_4 ( V_12 -> V_4 , L_13 ) ;
V_23 = F_23 ( V_21 , NULL ) ;
if ( V_23 )
goto V_90;
V_21 -> V_111 = false ;
V_23 = F_25 ( V_21 , V_38 ) ;
F_26 ( V_21 -> V_99 , V_12 ) ;
if ( F_27 ( V_21 -> V_99 ) )
F_28 ( V_21 -> V_99 ) ;
if ( ! V_23 ) {
F_4 ( V_12 -> V_4 , L_14
L_15 ) ;
V_23 = F_32 ( V_21 , V_38 ) ;
if ( V_36 )
F_30 ( V_36 ) ;
} else {
F_4 ( V_12 -> V_4 , L_16
L_17 ,
V_87 -> V_107 ) ;
V_23 = F_33 ( V_21 , V_87 ) ;
}
}
V_90:
F_17 ( V_38 ) ;
return V_23 ;
}
static int F_34 ( struct V_20 * V_21 , T_1 V_112 ,
int V_113 , struct V_114 * V_115 )
{
struct V_11 * V_12 = V_21 -> V_12 ;
int V_13 = 0 ;
T_4 V_116 = 0 ;
if ( ! V_115 )
return - V_49 ;
switch ( V_112 ) {
case V_33 :
if ( V_12 -> V_117 ) {
F_4 ( V_12 -> V_4 , L_18
L_19 ) ;
V_13 = - 1 ;
break;
}
if ( V_115 -> V_118 ) {
if ( V_115 -> V_119 == V_120 ) {
if ( ! V_12 -> V_121 )
break;
V_116 = F_35 ( V_12 -> V_115
. V_119 ) ;
V_12 -> V_115 . V_119 =
F_36 ( V_115 -> V_119 ) ;
} else if ( V_115 -> V_119 ) {
V_12 -> V_115 . V_119 =
F_36 ( V_115 -> V_119 ) ;
V_12 -> V_115 . V_122 = ( T_2 ) V_115 -> V_122 ;
if ( V_115 -> V_123 )
V_12 -> V_115 . V_123 = ( T_2 ) V_115 -> V_123 ;
} else if ( V_12 -> V_115 . V_119
== F_36 ( V_120 ) ) {
V_13 = - 1 ;
break;
}
if ( V_113 == V_124 )
V_13 = F_37 ( V_21 ,
V_125 ,
V_33 , 0 ,
& V_12 -> V_115 ) ;
else
V_13 = F_9 ( V_21 ,
V_125 ,
V_33 , 0 ,
& V_12 -> V_115 ) ;
if ( V_115 -> V_119 == V_120 )
V_12 -> V_115 . V_119 =
F_36 ( V_116 ) ;
} else {
V_12 -> V_115 . V_119 =
F_36 ( V_115 -> V_119 ) ;
V_12 -> V_115 . V_122 = ( T_2 ) V_115 -> V_122 ;
V_12 -> V_115 . V_123 = ( T_2 ) V_115 -> V_123 ;
}
break;
case V_126 :
V_115 -> V_119 = F_35 ( V_12 -> V_115 . V_119 ) ;
V_115 -> V_122 = V_12 -> V_115 . V_122 ;
V_115 -> V_123 = V_12 -> V_115 . V_123 ;
break;
default:
V_13 = - 1 ;
break;
}
return V_13 ;
}
int F_38 ( struct V_20 * V_21 , int V_113 )
{
struct V_114 V_127 ;
V_127 . V_119 = V_120 ;
V_127 . V_118 = true ;
return F_34 ( V_21 , V_33 ,
V_113 , & V_127 ) ;
}
int F_39 ( struct V_11 * V_12 )
{
struct V_114 V_127 ;
struct V_20 * V_21 ;
int V_5 ;
if ( V_128 ) {
for ( V_5 = 0 ; V_5 < V_12 -> V_129 ; V_5 ++ ) {
V_21 = V_12 -> V_21 [ V_5 ] ;
if ( V_21 )
F_23 ( V_21 , NULL ) ;
}
}
if ( V_12 -> V_130 ) {
F_4 ( V_12 -> V_4 , L_20 ) ;
return true ;
}
V_12 -> V_131 = false ;
memset ( & V_127 , 0 , sizeof( struct V_114 ) ) ;
V_127 . V_118 = true ;
if ( F_34 ( F_40 ( V_12 ,
V_132 ) ,
V_33 , V_124 ,
& V_127 ) ) {
F_7 ( V_12 -> V_4 , L_21 ) ;
return false ;
}
if ( F_6 ( V_12 -> V_133 ,
V_12 -> V_131 ) ) {
F_7 ( V_12 -> V_4 , L_22 ) ;
return false ;
}
return true ;
}
int F_41 ( struct V_20 * V_21 ,
struct V_134 * V_135 )
{
struct V_11 * V_12 = V_21 -> V_12 ;
struct V_37 * V_38 ;
if ( ! V_135 )
return - 1 ;
V_38 = & V_21 -> V_109 . V_110 ;
V_135 -> V_69 = V_21 -> V_69 ;
memcpy ( & V_135 -> V_107 , & V_38 -> V_107 , sizeof( struct V_86 ) ) ;
memcpy ( & V_135 -> V_51 , & V_38 -> V_50 , V_10 ) ;
V_135 -> V_136 = V_38 -> V_137 ;
memcpy ( V_135 -> V_79 , V_12 -> V_79 ,
V_80 ) ;
V_135 -> V_138 = V_21 -> V_138 ;
V_135 -> V_139 = V_21 -> V_140 ;
V_135 -> V_141 = V_21 -> V_142 ;
V_135 -> V_143 = V_21 -> V_143 ;
V_135 -> V_144 = V_21 -> V_144 ;
if ( V_21 -> V_102 . V_104 )
V_135 -> V_145 = true ;
else
V_135 -> V_145 = false ;
V_135 -> V_121 = V_12 -> V_121 ;
V_135 -> V_146 = V_12 -> V_146 ;
return 0 ;
}
int F_42 ( struct V_20 * V_21 )
{
struct V_147 V_148 ;
V_148 . V_148 = V_149 ;
return F_37 ( V_21 , V_150 ,
V_151 , V_152 , & V_148 ) ;
}
int F_43 ( struct V_20 * V_21 , T_4 * V_153 )
{
int V_23 ;
V_23 = F_37 ( V_21 , V_154 ,
V_126 , 0 , NULL ) ;
if ( ! V_23 ) {
if ( V_21 -> V_155 )
* V_153 = F_44 ( V_21 , V_21 -> V_156 ,
V_21 -> V_157 ) ;
else
* V_153 = V_21 -> V_158 ;
}
return V_23 ;
}
int F_45 ( struct V_20 * V_21 ,
struct V_159 * V_160 )
{
int V_23 ;
struct V_161 * V_162 ;
struct V_163 * V_164 ;
struct V_165 * V_166 ;
T_2 * V_167 ;
T_1 V_168 = 0 ;
if ( ! V_160 -> V_169 ) {
V_168 = ( T_1 ) V_160 -> V_170 ;
if ( ( V_168 < V_21 -> V_142 ) ||
( V_168 > V_21 -> V_140 ) ) {
F_7 ( V_21 -> V_12 -> V_4 , L_23
L_24 ,
V_168 , V_21 -> V_142 ,
V_21 -> V_140 ) ;
return - 1 ;
}
}
V_167 = F_22 ( V_171 , V_89 ) ;
if ( ! V_167 ) {
F_7 ( V_21 -> V_12 -> V_4 , L_25 ,
V_172 ) ;
return - V_49 ;
}
V_162 = (struct V_161 * ) V_167 ;
V_162 -> V_112 = F_46 ( V_33 ) ;
if ( ! V_160 -> V_169 ) {
V_162 -> V_26 = F_36 ( 1 ) ;
V_164 = (struct V_163 * )
( V_167 + sizeof( struct V_161 ) ) ;
V_164 -> type = V_173 ;
V_164 -> V_174 = 4 * sizeof( struct V_165 ) ;
V_166 = (struct V_165 * )
( V_167 + sizeof( struct V_161 )
+ sizeof( struct V_163 ) ) ;
V_166 -> V_175 = 0x00 ;
V_166 -> V_176 = 0x03 ;
V_166 -> V_177 = V_178 ;
V_166 -> V_179 = 0 ;
V_166 -> V_180 = ( V_181 ) V_168 ;
V_166 -> V_182 = ( V_181 ) V_168 ;
V_166 ++ ;
V_166 -> V_175 = 0x00 ;
V_166 -> V_176 = 0x07 ;
V_166 -> V_177 = V_183 ;
V_166 -> V_179 = 0 ;
V_166 -> V_180 = ( V_181 ) V_168 ;
V_166 -> V_182 = ( V_181 ) V_168 ;
V_166 ++ ;
V_166 -> V_175 = 0x00 ;
V_166 -> V_176 = 0x20 ;
V_166 -> V_177 = V_184 ;
V_166 -> V_179 = 0 ;
V_166 -> V_180 = ( V_181 ) V_168 ;
V_166 -> V_182 = ( V_181 ) V_168 ;
V_166 -> V_185 = V_186 ;
V_166 ++ ;
V_166 -> V_175 = 0x00 ;
V_166 -> V_176 = 0x20 ;
V_166 -> V_177 = V_184 ;
V_166 -> V_179 = 0 ;
V_166 -> V_180 = ( V_181 ) V_168 ;
V_166 -> V_182 = ( V_181 ) V_168 ;
V_166 -> V_185 = V_187 ;
}
V_23 = F_37 ( V_21 , V_188 ,
V_33 , 0 , V_167 ) ;
F_17 ( V_167 ) ;
return V_23 ;
}
int F_47 ( struct V_20 * V_21 , T_4 * V_189 )
{
int V_23 ;
struct V_11 * V_12 = V_21 -> V_12 ;
T_1 V_190 ;
if ( * V_189 )
V_12 -> V_189 = V_191 ;
else
V_12 -> V_189 = V_192 ;
V_190 = ( * V_189 ) ? V_193 : V_151 ;
V_23 = F_37 ( V_21 , V_150 ,
V_190 , V_194 , NULL ) ;
if ( ( ! V_23 ) && ( V_190 == V_151 ) )
V_23 = F_9 ( V_21 ,
V_150 ,
V_195 , 0 , NULL ) ;
return V_23 ;
}
static int F_48 ( struct V_20 * V_21 ,
T_2 * V_196 , T_1 V_197 )
{
if ( V_197 ) {
if ( V_197 > sizeof( V_21 -> V_198 ) ) {
F_7 ( V_21 -> V_12 -> V_4 ,
L_26 ) ;
return - 1 ;
}
memcpy ( V_21 -> V_198 , V_196 , V_197 ) ;
V_21 -> V_199 = ( T_2 ) V_197 ;
F_4 ( V_21 -> V_12 -> V_4 , L_27 ,
V_21 -> V_199 , V_21 -> V_198 [ 0 ] ) ;
if ( V_21 -> V_198 [ 0 ] == V_200 ) {
V_21 -> V_102 . V_201 = true ;
} else if ( V_21 -> V_198 [ 0 ] == V_202 ) {
V_21 -> V_102 . V_203 = true ;
} else {
V_21 -> V_102 . V_201 = false ;
V_21 -> V_102 . V_203 = false ;
}
} else {
memset ( V_21 -> V_198 , 0 , sizeof( V_21 -> V_198 ) ) ;
V_21 -> V_199 = 0 ;
F_4 ( V_21 -> V_12 -> V_4 , L_28 ,
V_21 -> V_199 , V_21 -> V_198 [ 0 ] ) ;
V_21 -> V_102 . V_201 = false ;
V_21 -> V_102 . V_203 = false ;
}
return 0 ;
}
static int F_49 ( struct V_20 * V_21 ,
T_2 * V_196 , T_1 V_197 )
{
if ( V_197 ) {
if ( V_197 > sizeof( V_21 -> V_204 ) ) {
F_4 ( V_21 -> V_12 -> V_4 ,
L_29 ) ;
return - 1 ;
}
memcpy ( V_21 -> V_204 , V_196 , V_197 ) ;
V_21 -> V_205 = V_197 ;
F_4 ( V_21 -> V_12 -> V_4 , L_30 ,
V_21 -> V_205 , V_21 -> V_204 [ 0 ] ) ;
if ( V_21 -> V_204 [ 0 ] == V_206 )
V_21 -> V_102 . V_207 = true ;
} else {
memset ( V_21 -> V_204 , 0 , sizeof( V_21 -> V_204 ) ) ;
V_21 -> V_205 = V_197 ;
F_4 ( V_21 -> V_12 -> V_4 ,
L_31 ,
V_21 -> V_205 , V_21 -> V_204 [ 0 ] ) ;
V_21 -> V_102 . V_207 = false ;
}
return 0 ;
}
static int F_50 ( struct V_20 * V_21 ,
T_2 * V_196 , T_1 V_197 )
{
if ( V_197 ) {
V_21 -> V_208 = F_22 ( V_209 , V_89 ) ;
if ( ! V_21 -> V_208 )
return - V_49 ;
if ( V_197 > sizeof( V_21 -> V_208 ) ) {
F_4 ( V_21 -> V_12 -> V_4 ,
L_32 ) ;
F_17 ( V_21 -> V_208 ) ;
return - 1 ;
}
memcpy ( V_21 -> V_208 , V_196 , V_197 ) ;
V_21 -> V_210 = V_197 ;
F_4 ( V_21 -> V_12 -> V_4 , L_33 ,
V_21 -> V_210 , V_21 -> V_208 [ 0 ] ) ;
} else {
F_17 ( V_21 -> V_208 ) ;
V_21 -> V_210 = V_197 ;
F_4 ( V_21 -> V_12 -> V_4 ,
L_34 , V_21 -> V_210 ) ;
}
return 0 ;
}
static int F_51 ( struct V_20 * V_21 ,
struct V_211 * V_212 )
{
return F_37 ( V_21 , V_213 ,
V_33 , V_214 ,
V_212 ) ;
}
static int F_52 ( struct V_20 * V_21 ,
struct V_211 * V_212 )
{
int V_23 ;
struct V_215 * V_216 ;
int V_217 ;
if ( V_21 -> V_218 >= V_219 )
V_21 -> V_218 = 0 ;
V_216 = & V_21 -> V_216 [ V_21 -> V_218 ] ;
V_217 = V_212 -> V_220 ;
if ( V_212 -> V_221 ) {
V_21 -> V_102 . V_104 = 0 ;
} else if ( ! V_212 -> V_222 ) {
V_216 = & V_21 -> V_216 [ V_217 ] ;
if ( ! V_216 -> V_223 ) {
F_7 ( V_21 -> V_12 -> V_4 ,
L_35 ) ;
return - 1 ;
}
V_21 -> V_218 = ( T_1 ) V_217 ;
V_21 -> V_102 . V_104 = 1 ;
} else {
V_216 = & V_21 -> V_216 [ V_217 ] ;
memset ( V_216 , 0 , sizeof( struct V_215 ) ) ;
memcpy ( V_216 -> V_224 ,
V_212 -> V_224 ,
V_212 -> V_222 ) ;
V_216 -> V_220 = V_217 ;
V_216 -> V_223 = V_212 -> V_222 ;
V_21 -> V_102 . V_104 = 1 ;
}
if ( V_216 -> V_223 ) {
V_23 = F_9 ( V_21 ,
V_213 ,
V_33 , 0 , NULL ) ;
if ( V_23 )
return V_23 ;
}
if ( V_21 -> V_102 . V_104 )
V_21 -> V_25 |= V_225 ;
else
V_21 -> V_25 &= ~ V_225 ;
V_23 = F_37 ( V_21 , V_34 ,
V_33 , 0 ,
& V_21 -> V_25 ) ;
return V_23 ;
}
static int F_53 ( struct V_20 * V_21 ,
struct V_211 * V_212 )
{
int V_23 ;
T_2 V_226 = false ;
struct V_227 * V_228 ;
if ( V_212 -> V_222 > V_229 ) {
F_7 ( V_21 -> V_12 -> V_4 , L_36 ) ;
return - 1 ;
}
if ( V_21 -> V_69 == V_70 ) {
V_212 -> V_220 = V_230 ;
V_23 = F_9 ( V_21 ,
V_213 ,
V_33 ,
V_214 , V_212 ) ;
if ( V_23 )
return V_23 ;
V_228 = & V_21 -> V_231 ;
memset ( V_228 , 0 ,
sizeof( struct V_227 ) ) ;
memcpy ( V_228 -> V_232 . V_233 , V_212 -> V_224 ,
V_212 -> V_222 ) ;
memcpy ( & V_228 -> V_232 . V_222 , & V_212 -> V_222 ,
sizeof( V_228 -> V_232 . V_222 ) ) ;
V_228 -> V_232 . V_234
= F_46 ( V_235 ) ;
V_228 -> V_232 . V_236 = F_46 ( V_237 ) ;
V_212 -> V_220 = ~ V_230 ;
}
if ( ! V_212 -> V_220 )
V_212 -> V_220 = V_230 ;
if ( V_226 )
V_23 = F_37 ( V_21 ,
V_213 ,
V_33 ,
! V_214 , V_212 ) ;
else
V_23 = F_37 ( V_21 ,
V_213 ,
V_33 ,
V_214 , V_212 ) ;
return V_23 ;
}
static int
F_54 ( struct V_20 * V_21 ,
struct V_211 * V_212 )
{
int V_13 ;
if ( V_212 -> V_238 )
V_13 = F_51 ( V_21 , V_212 ) ;
else if ( V_212 -> V_222 > V_239 )
V_13 = F_53 ( V_21 , V_212 ) ;
else
V_13 = F_52 ( V_21 , V_212 ) ;
return V_13 ;
}
int
F_55 ( struct V_11 * V_12 , char * V_240 ,
int V_241 )
{
union {
T_4 V_242 ;
T_2 V_243 [ 4 ] ;
} V_244 ;
char V_245 [ 32 ] ;
V_244 . V_242 = V_12 -> V_246 ;
sprintf ( V_245 , L_37 , V_244 . V_243 [ 2 ] , V_244 . V_243 [ 1 ] , V_244 . V_243 [ 0 ] , V_244 . V_243 [ 3 ] ) ;
snprintf ( V_240 , V_241 , V_247 , V_245 ) ;
F_4 ( V_12 -> V_4 , L_38 , V_240 ) ;
return 0 ;
}
int F_56 ( struct V_20 * V_21 , struct V_248 * V_249 ,
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
return F_54 ( V_21 , & V_212 ) ;
}
int
F_57 ( struct V_20 * V_21 )
{
struct V_258 V_259 ;
memset ( & V_259 , 0 , sizeof( struct V_260 ) ) ;
if ( F_37 ( V_21 , V_261 ,
V_126 , 0 , & V_259 ) )
return - 1 ;
return 0 ;
}
int
F_58 ( struct V_20 * V_21 , T_1 V_112 ,
struct V_262 * V_263 ,
unsigned int V_264 )
{
struct V_265 V_266 ;
T_2 V_267 ;
memset ( & V_266 , 0 , sizeof( V_266 ) ) ;
V_266 . V_112 = F_46 ( V_112 ) ;
if ( V_112 == V_33 ) {
V_266 . V_268 = V_263 -> V_60 ;
V_267 = F_59 ( V_269 ) ;
V_266 . V_268 |= ( V_267 << 2 ) ;
V_266 . V_137 =
F_60 ( V_263 -> V_270 ) ;
V_266 . V_264 = F_36 ( V_264 ) ;
}
if ( F_37 ( V_21 , V_271 ,
V_112 , 0 , & V_266 ) ) {
F_7 ( V_21 -> V_12 -> V_4 , L_39 ) ;
return - 1 ;
}
return V_266 . V_13 ;
}
int
F_61 ( struct V_20 * V_21 , T_2 V_272 )
{
if ( F_62 ( V_21 ) == V_272 ) {
F_4 ( V_21 -> V_12 -> V_4 ,
L_40 ) ;
return 0 ;
}
F_63 ( V_21 ) ;
F_64 ( V_21 ) ;
V_21 -> V_272 = V_272 ;
switch ( V_272 ) {
case V_273 :
V_21 -> V_69 = V_274 ;
break;
case V_132 :
case V_275 :
default:
V_21 -> V_69 = V_71 ;
break;
}
F_37 ( V_21 , V_276 ,
V_33 , 0 , NULL ) ;
return F_65 ( V_21 , false ) ;
}
int
F_66 ( struct V_20 * V_21 ,
struct V_277 * log )
{
return F_37 ( V_21 , V_278 ,
V_126 , 0 , log ) ;
}
static int F_67 ( struct V_20 * V_21 ,
struct V_279 * V_280 ,
T_1 V_112 )
{
T_1 V_281 ;
switch ( F_35 ( V_280 -> type ) ) {
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
return F_37 ( V_21 , V_281 , V_112 , 0 , V_280 ) ;
}
int
F_68 ( struct V_20 * V_21 , T_4 V_292 ,
T_4 V_293 , T_4 V_294 )
{
struct V_279 V_280 ;
V_280 . type = F_36 ( V_292 ) ;
V_280 . V_295 = F_36 ( V_293 ) ;
V_280 . V_296 = F_36 ( V_294 ) ;
return F_67 ( V_21 , & V_280 , V_33 ) ;
}
int
F_69 ( struct V_20 * V_21 , T_4 V_292 ,
T_4 V_293 , T_4 * V_296 )
{
int V_23 ;
struct V_279 V_280 ;
V_280 . type = F_36 ( V_292 ) ;
V_280 . V_295 = F_36 ( V_293 ) ;
V_23 = F_67 ( V_21 , & V_280 , V_126 ) ;
if ( V_23 )
goto V_90;
* V_296 = F_35 ( V_280 . V_296 ) ;
V_90:
return V_23 ;
}
int
F_70 ( struct V_20 * V_21 , T_1 V_295 , T_1 V_297 ,
T_2 * V_296 )
{
int V_23 ;
struct V_298 V_299 ;
V_299 . V_295 = F_46 ( ( T_1 ) V_295 ) ;
V_299 . V_300 = F_46 ( ( T_1 ) V_297 ) ;
V_23 = F_37 ( V_21 , V_301 ,
V_126 , 0 , & V_299 ) ;
if ( ! V_23 )
memcpy ( V_296 , V_299 . V_296 , V_302 ) ;
return V_23 ;
}
static int
F_71 ( struct V_20 * V_21 , T_2 * V_196 ,
T_1 V_197 )
{
int V_23 = 0 ;
struct V_303 * V_304 ;
const T_2 V_305 [] = { 0x00 , 0x50 , 0xf2 , 0x01 } ;
const T_2 V_306 [] = { 0x00 , 0x50 , 0xf2 , 0x04 } ;
if ( ! V_197 ) {
V_21 -> V_307 = 0 ;
V_21 -> V_308 . V_309 = false ;
return 0 ;
} else if ( ! V_196 ) {
return - 1 ;
}
V_304 = (struct V_303 * ) V_196 ;
if ( ( ( V_304 -> V_310 == V_200 ) &&
( ! memcmp ( V_304 -> V_311 , V_305 , sizeof( V_305 ) ) ) ) ||
( V_304 -> V_310 == V_202 ) ) {
V_23 = F_48 ( V_21 , V_196 , V_197 ) ;
V_21 -> V_308 . V_309 = false ;
return V_23 ;
} else if ( V_304 -> V_310 == V_206 ) {
V_23 = F_49 ( V_21 , V_196 , V_197 ) ;
return V_23 ;
}
if ( V_197 < ( sizeof( V_21 -> V_312 ) - V_21 -> V_307 ) ) {
V_304 = (struct V_303 * ) V_196 ;
if ( ( V_304 -> V_310 == V_200 ) &&
( ! memcmp ( V_304 -> V_311 , V_306 , sizeof( V_306 ) ) ) ) {
V_21 -> V_308 . V_309 = true ;
F_4 ( V_21 -> V_12 -> V_4 ,
L_41 ) ;
V_23 = F_50 ( V_21 , V_196 , V_197 ) ;
}
memcpy ( V_21 -> V_312 + V_21 -> V_307 , V_196 ,
V_197 ) ;
V_21 -> V_307 += V_197 ;
} else {
V_23 = - 1 ;
}
return V_23 ;
}
static int F_72 ( struct V_20 * V_21 ,
struct V_313 * V_314 ,
T_1 V_112 )
{
struct V_11 * V_12 = V_21 -> V_12 ;
switch ( V_314 -> type ) {
case V_315 :
if ( V_112 == V_126 ) {
V_314 -> V_47 = V_21 -> V_199 ;
memcpy ( V_314 -> V_316 , V_21 -> V_198 , V_314 -> V_47 ) ;
} else {
F_71 ( V_21 , V_314 -> V_316 ,
( T_1 ) V_314 -> V_47 ) ;
}
break;
case V_317 :
memset ( V_12 -> V_318 , 0 , sizeof( V_12 -> V_318 ) ) ;
if ( V_314 -> V_47 > V_319 ) {
V_12 -> V_320 = 0 ;
F_7 ( V_12 -> V_4 , L_42 ) ;
return - 1 ;
} else {
memcpy ( V_12 -> V_318 , V_314 -> V_316 ,
V_314 -> V_47 ) ;
V_12 -> V_320 = V_314 -> V_47 ;
}
break;
default:
F_7 ( V_12 -> V_4 , L_43 ) ;
return - 1 ;
}
return 0 ;
}
int
F_73 ( struct V_20 * V_21 , T_2 * V_321 , int V_197 )
{
struct V_313 V_314 ;
if ( V_197 > V_322 )
return - V_323 ;
V_314 . type = V_315 ;
V_314 . V_47 = V_197 ;
memcpy ( V_314 . V_316 , V_321 , V_197 ) ;
if ( F_72 ( V_21 , & V_314 , V_33 ) )
return - V_323 ;
return 0 ;
}
