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
bool V_13 = false ;
int V_14 ;
struct V_15 * V_16 ;
if ( ! V_12 -> V_16 )
return 0 ;
V_16 = V_12 -> V_16 ;
V_12 -> V_16 = NULL ;
F_4 ( V_12 -> V_4 , L_1 ) ;
F_5 ( & V_12 -> V_17 ) ;
F_6 ( V_12 -> V_18 . V_19 ,
* ( V_16 -> V_20 ) ) ;
if ( ! * ( V_16 -> V_20 ) )
V_13 = true ;
if ( V_13 ) {
F_7 ( V_12 ) ;
F_4 ( V_12 -> V_4 , L_2 ) ;
}
V_14 = V_12 -> V_18 . V_14 ;
V_12 -> V_18 . V_14 = 0 ;
return V_14 ;
}
int F_8 ( struct V_21 * V_22 ,
struct V_1 * V_23 )
{
int V_24 = 0 ;
T_1 V_25 ;
V_25 = V_22 -> V_26 ;
if ( V_23 -> V_27 == V_28 ) {
F_4 ( V_22 -> V_12 -> V_4 , L_3 ) ;
V_22 -> V_26 |= V_29 ;
V_22 -> V_26 &=
~ V_30 ;
} else {
V_22 -> V_26 &= ~ V_29 ;
if ( V_23 -> V_27 == V_31 ) {
F_4 ( V_22 -> V_12 -> V_4 ,
L_4 ) ;
V_22 -> V_26 |=
V_30 ;
} else {
V_22 -> V_26 &=
~ V_30 ;
if ( V_23 -> V_32 ) {
F_4 ( V_22 -> V_12 -> V_4 ,
L_5 ,
V_23 -> V_32 ) ;
if ( V_25 == V_22 -> V_26 ) {
V_24 = F_9 ( V_22 ,
V_33 ,
V_34 , 0 ,
V_23 ) ;
} else {
V_24 = F_9 ( V_22 ,
V_33 ,
V_34 , 0 ,
V_23 ) ;
}
}
}
}
F_4 ( V_22 -> V_12 -> V_4 ,
L_6 ,
V_25 , V_22 -> V_26 ) ;
if ( V_25 != V_22 -> V_26 ) {
V_24 = F_9 ( V_22 , V_35 ,
V_34 ,
0 , & V_22 -> V_26 ) ;
}
return V_24 ;
}
int F_10 ( struct V_21 * V_22 ,
struct V_36 * V_37 ,
struct V_38 * V_39 )
{
int V_24 ;
T_2 * V_40 ;
struct V_41 * V_42 = ( void * ) V_37 -> V_22 ;
V_40 = F_11 ( V_37 -> V_43 , V_37 -> V_44 ,
V_45 ) ;
if ( ! V_40 ) {
F_12 ( V_22 -> V_12 -> V_4 , L_7 ) ;
return - V_46 ;
}
memcpy ( V_39 -> V_47 , V_37 -> V_48 , V_10 ) ;
V_39 -> V_49 = V_37 -> signal ;
V_39 -> V_50 = V_40 ;
V_39 -> V_51 = V_37 -> V_44 ;
V_39 -> V_52 = V_37 -> V_53 ;
V_39 -> V_54 = V_37 -> V_55 ;
V_39 -> V_56 = V_42 -> V_57 ;
V_39 -> V_58 = V_42 -> V_58 ;
V_39 -> V_59 = V_37 -> V_60 ;
if ( V_39 -> V_54 & V_61 ) {
F_4 ( V_22 -> V_12 -> V_4 , L_8 ) ;
V_39 -> V_62 = V_63 ;
} else {
V_39 -> V_62 = V_64 ;
}
if ( V_39 -> V_54 & V_65 )
V_39 -> V_66 = V_67 ;
else
V_39 -> V_66 = V_68 ;
V_24 = F_13 ( V_22 -> V_12 , V_39 ) ;
F_14 ( V_40 ) ;
return V_24 ;
}
static int F_15 ( struct V_21 * V_22 ,
struct V_36 * V_37 )
{
T_2 * V_69 , V_70 ;
struct V_71 * V_72 =
& V_22 -> V_12 -> V_73 ;
V_69 = ( T_2 * ) F_16 ( V_37 , V_74 ) ;
if ( ! V_69 )
return 0 ;
V_70 = V_69 [ 1 ] ;
if ( V_70 < V_75 )
return 0 ;
V_72 -> V_76 [ 0 ] = V_69 [ 2 ] ;
V_72 -> V_76 [ 1 ] = V_69 [ 3 ] ;
V_72 -> V_76 [ 2 ] = ' ' ;
V_70 -= V_77 ;
V_72 -> V_78 =
V_70 / sizeof( struct V_79 ) ;
memcpy ( ( T_2 * ) V_72 -> V_80 ,
& V_69 [ 2 ] + V_77 , V_70 ) ;
if ( F_9 ( V_22 , V_81 ,
V_34 , 0 , NULL ) ) {
F_17 ( V_22 -> V_12 -> V_82 ,
L_9 ) ;
return - 1 ;
}
return 0 ;
}
int F_18 ( struct V_21 * V_22 , struct V_36 * V_37 ,
struct V_83 * V_84 )
{
int V_24 ;
struct V_11 * V_12 = V_22 -> V_12 ;
struct V_38 * V_39 = NULL ;
V_22 -> V_85 = false ;
if ( V_37 ) {
F_15 ( V_22 , V_37 ) ;
V_39 = F_19 ( sizeof( struct V_38 ) ,
V_45 ) ;
if ( ! V_39 ) {
F_12 ( V_22 -> V_12 -> V_4 , L_10 ) ;
return - V_46 ;
}
V_24 = F_10 ( V_22 , V_37 , V_39 ) ;
if ( V_24 )
goto V_86;
}
if ( V_22 -> V_66 == V_68 ) {
V_24 = F_20 ( V_22 , NULL ) ;
if ( V_24 )
goto V_86;
V_24 = F_21 ( V_22 , V_39 ) ;
if ( V_24 )
goto V_86;
F_4 ( V_12 -> V_4 , L_11
L_12 ) ;
if ( ! F_22 ( V_22 -> V_87 ) )
F_23 ( V_22 -> V_87 , V_12 ) ;
if ( F_24 ( V_22 -> V_87 ) )
F_25 ( V_22 -> V_87 ) ;
V_22 -> V_88 = 0 ;
V_24 = F_26 ( V_22 , V_39 ) ;
if ( V_24 == V_89 &&
V_22 -> V_90 . V_91 &&
V_22 -> V_90 . V_92 ) {
V_22 -> V_90 . V_93 =
V_94 ;
V_24 = F_26 ( V_22 , V_39 ) ;
}
if ( V_37 )
F_27 ( V_37 ) ;
} else {
if ( V_39 && V_39 -> V_95 . V_96 &&
( ! F_28 ( & V_22 -> V_97 . V_98 .
V_95 , & V_39 -> V_95 ) ) ) {
F_14 ( V_39 ) ;
return 0 ;
}
F_4 ( V_12 -> V_4 , L_13 ) ;
V_24 = F_20 ( V_22 , NULL ) ;
if ( V_24 )
goto V_86;
V_22 -> V_99 = false ;
V_24 = F_21 ( V_22 , V_39 ) ;
if ( ! F_22 ( V_22 -> V_87 ) )
F_23 ( V_22 -> V_87 , V_12 ) ;
if ( F_24 ( V_22 -> V_87 ) )
F_25 ( V_22 -> V_87 ) ;
if ( ! V_24 ) {
F_4 ( V_12 -> V_4 , L_14
L_15 ) ;
V_24 = F_29 ( V_22 , V_39 ) ;
if ( V_37 )
F_27 ( V_37 ) ;
} else {
F_4 ( V_12 -> V_4 , L_16
L_17 ,
V_84 -> V_95 ) ;
V_24 = F_30 ( V_22 , V_84 ) ;
}
}
V_86:
F_14 ( V_39 ) ;
return V_24 ;
}
static int F_31 ( struct V_21 * V_22 , T_1 V_100 ,
int V_101 , struct V_102 * V_103 )
{
struct V_11 * V_12 = V_22 -> V_12 ;
int V_14 = 0 ;
T_3 V_104 = 0 ;
if ( ! V_103 )
return - V_46 ;
switch ( V_100 ) {
case V_34 :
if ( V_12 -> V_105 ) {
F_4 ( V_12 -> V_4 , L_18
L_19 ) ;
V_14 = - 1 ;
break;
}
if ( V_103 -> V_106 ) {
if ( V_103 -> V_107 == V_108 ) {
if ( ! V_12 -> V_109 )
break;
V_104 = F_32 ( V_12 -> V_103
. V_107 ) ;
V_12 -> V_103 . V_107 =
F_33 ( V_103 -> V_107 ) ;
} else if ( V_103 -> V_107 ) {
V_12 -> V_103 . V_107 =
F_33 ( V_103 -> V_107 ) ;
V_12 -> V_103 . V_110 = ( T_2 ) V_103 -> V_110 ;
if ( V_103 -> V_111 )
V_12 -> V_103 . V_111 = ( T_2 ) V_103 -> V_111 ;
} else if ( V_12 -> V_103 . V_107
== F_33 ( V_108 ) ) {
V_14 = - 1 ;
break;
}
if ( V_101 == V_112 )
V_14 = F_34 ( V_22 ,
V_113 ,
V_34 , 0 ,
& V_12 -> V_103 ) ;
else
V_14 = F_9 ( V_22 ,
V_113 ,
V_34 , 0 ,
& V_12 -> V_103 ) ;
if ( V_103 -> V_107 == V_108 )
V_12 -> V_103 . V_107 =
F_33 ( V_104 ) ;
} else {
V_12 -> V_103 . V_107 =
F_33 ( V_103 -> V_107 ) ;
V_12 -> V_103 . V_110 = ( T_2 ) V_103 -> V_110 ;
V_12 -> V_103 . V_111 = ( T_2 ) V_103 -> V_111 ;
}
break;
case V_114 :
V_103 -> V_107 = F_32 ( V_12 -> V_103 . V_107 ) ;
V_103 -> V_110 = V_12 -> V_103 . V_110 ;
V_103 -> V_111 = V_12 -> V_103 . V_111 ;
break;
default:
V_14 = - 1 ;
break;
}
return V_14 ;
}
int F_35 ( struct V_21 * V_22 , int V_101 )
{
struct V_102 V_115 ;
V_115 . V_107 = V_108 ;
V_115 . V_106 = true ;
return F_31 ( V_22 , V_34 ,
V_101 , & V_115 ) ;
}
int F_36 ( struct V_11 * V_12 )
{
struct V_102 V_115 ;
struct V_21 * V_22 ;
int V_5 ;
if ( V_116 ) {
for ( V_5 = 0 ; V_5 < V_12 -> V_117 ; V_5 ++ ) {
V_22 = V_12 -> V_22 [ V_5 ] ;
if ( V_22 )
F_20 ( V_22 , NULL ) ;
}
}
if ( V_12 -> V_118 ) {
F_4 ( V_12 -> V_4 , L_20 ) ;
return true ;
}
V_12 -> V_119 = false ;
memset ( & V_115 , 0 , sizeof( struct V_102 ) ) ;
V_115 . V_106 = true ;
if ( F_31 ( F_37 ( V_12 ,
V_120 ) ,
V_34 , V_112 ,
& V_115 ) ) {
F_12 ( V_12 -> V_4 , L_21 ) ;
return false ;
}
F_6 ( V_12 -> V_121 ,
V_12 -> V_119 ) ;
return true ;
}
int F_38 ( struct V_21 * V_22 ,
struct V_122 * V_123 )
{
struct V_11 * V_12 = V_22 -> V_12 ;
struct V_38 * V_39 ;
if ( ! V_123 )
return - 1 ;
V_39 = & V_22 -> V_97 . V_98 ;
V_123 -> V_66 = V_22 -> V_66 ;
memcpy ( & V_123 -> V_95 , & V_39 -> V_95 , sizeof( struct V_83 ) ) ;
memcpy ( & V_123 -> V_48 , & V_39 -> V_47 , V_10 ) ;
V_123 -> V_124 = V_39 -> V_125 ;
memcpy ( V_123 -> V_76 , V_12 -> V_76 ,
V_77 ) ;
V_123 -> V_126 = V_22 -> V_126 ;
V_123 -> V_127 = V_22 -> V_128 ;
V_123 -> V_129 = V_22 -> V_130 ;
V_123 -> V_131 = V_22 -> V_131 ;
V_123 -> V_132 = V_22 -> V_132 ;
if ( V_22 -> V_90 . V_92 )
V_123 -> V_133 = true ;
else
V_123 -> V_133 = false ;
V_123 -> V_109 = V_12 -> V_109 ;
V_123 -> V_134 = V_12 -> V_134 ;
return 0 ;
}
int F_39 ( struct V_21 * V_22 )
{
struct V_135 V_136 ;
V_136 . V_136 = V_137 ;
return F_34 ( V_22 , V_138 ,
V_139 , V_140 , & V_136 ) ;
}
int F_40 ( struct V_21 * V_22 , T_3 * V_141 )
{
int V_24 ;
V_24 = F_34 ( V_22 , V_142 ,
V_114 , 0 , NULL ) ;
if ( ! V_24 ) {
if ( V_22 -> V_143 )
* V_141 = F_41 ( V_22 , V_22 -> V_144 ,
V_22 -> V_145 ) ;
else
* V_141 = V_22 -> V_146 ;
}
return V_24 ;
}
int F_42 ( struct V_21 * V_22 ,
struct V_147 * V_148 )
{
int V_24 ;
struct V_149 * V_150 ;
struct V_151 * V_152 ;
struct V_153 * V_154 ;
T_2 * V_155 ;
T_1 V_156 = 0 ;
if ( ! V_148 -> V_157 ) {
V_156 = ( T_1 ) V_148 -> V_158 ;
if ( ( V_156 < V_22 -> V_130 ) ||
( V_156 > V_22 -> V_128 ) ) {
F_12 ( V_22 -> V_12 -> V_4 , L_22
L_23 ,
V_156 , V_22 -> V_130 ,
V_22 -> V_128 ) ;
return - 1 ;
}
}
V_155 = F_19 ( V_159 , V_45 ) ;
if ( ! V_155 ) {
F_12 ( V_22 -> V_12 -> V_4 , L_24 ,
V_160 ) ;
return - V_46 ;
}
V_150 = (struct V_149 * ) V_155 ;
V_150 -> V_100 = F_43 ( V_34 ) ;
if ( ! V_148 -> V_157 ) {
V_150 -> V_27 = F_33 ( 1 ) ;
V_152 = (struct V_151 * )
( V_155 + sizeof( struct V_149 ) ) ;
V_152 -> type = V_161 ;
V_152 -> V_162 = 4 * sizeof( struct V_153 ) ;
V_154 = (struct V_153 * )
( V_155 + sizeof( struct V_149 )
+ sizeof( struct V_151 ) ) ;
V_154 -> V_163 = 0x00 ;
V_154 -> V_164 = 0x03 ;
V_154 -> V_165 = V_166 ;
V_154 -> V_167 = 0 ;
V_154 -> V_168 = ( V_169 ) V_156 ;
V_154 -> V_170 = ( V_169 ) V_156 ;
V_154 ++ ;
V_154 -> V_163 = 0x00 ;
V_154 -> V_164 = 0x07 ;
V_154 -> V_165 = V_171 ;
V_154 -> V_167 = 0 ;
V_154 -> V_168 = ( V_169 ) V_156 ;
V_154 -> V_170 = ( V_169 ) V_156 ;
V_154 ++ ;
V_154 -> V_163 = 0x00 ;
V_154 -> V_164 = 0x20 ;
V_154 -> V_165 = V_172 ;
V_154 -> V_167 = 0 ;
V_154 -> V_168 = ( V_169 ) V_156 ;
V_154 -> V_170 = ( V_169 ) V_156 ;
V_154 -> V_173 = V_174 ;
V_154 ++ ;
V_154 -> V_163 = 0x00 ;
V_154 -> V_164 = 0x20 ;
V_154 -> V_165 = V_172 ;
V_154 -> V_167 = 0 ;
V_154 -> V_168 = ( V_169 ) V_156 ;
V_154 -> V_170 = ( V_169 ) V_156 ;
V_154 -> V_173 = V_175 ;
}
V_24 = F_34 ( V_22 , V_176 ,
V_34 , 0 , V_155 ) ;
F_14 ( V_155 ) ;
return V_24 ;
}
int F_44 ( struct V_21 * V_22 , T_3 * V_177 )
{
int V_24 ;
struct V_11 * V_12 = V_22 -> V_12 ;
T_1 V_178 ;
if ( * V_177 )
V_12 -> V_177 = V_179 ;
else
V_12 -> V_177 = V_180 ;
V_178 = ( * V_177 ) ? V_181 : V_139 ;
V_24 = F_34 ( V_22 , V_138 ,
V_178 , V_182 , NULL ) ;
if ( ( ! V_24 ) && ( V_178 == V_139 ) )
V_24 = F_9 ( V_22 ,
V_138 ,
V_183 , 0 , NULL ) ;
return V_24 ;
}
static int F_45 ( struct V_21 * V_22 ,
T_2 * V_184 , T_1 V_185 )
{
if ( V_185 ) {
if ( V_185 > sizeof( V_22 -> V_186 ) ) {
F_12 ( V_22 -> V_12 -> V_4 ,
L_25 ) ;
return - 1 ;
}
memcpy ( V_22 -> V_186 , V_184 , V_185 ) ;
V_22 -> V_187 = ( T_2 ) V_185 ;
F_4 ( V_22 -> V_12 -> V_4 , L_26 ,
V_22 -> V_187 , V_22 -> V_186 [ 0 ] ) ;
if ( V_22 -> V_186 [ 0 ] == V_188 ) {
V_22 -> V_90 . V_189 = true ;
} else if ( V_22 -> V_186 [ 0 ] == V_190 ) {
V_22 -> V_90 . V_191 = true ;
} else {
V_22 -> V_90 . V_189 = false ;
V_22 -> V_90 . V_191 = false ;
}
} else {
memset ( V_22 -> V_186 , 0 , sizeof( V_22 -> V_186 ) ) ;
V_22 -> V_187 = 0 ;
F_4 ( V_22 -> V_12 -> V_4 , L_27 ,
V_22 -> V_187 , V_22 -> V_186 [ 0 ] ) ;
V_22 -> V_90 . V_189 = false ;
V_22 -> V_90 . V_191 = false ;
}
return 0 ;
}
static int F_46 ( struct V_21 * V_22 ,
T_2 * V_184 , T_1 V_185 )
{
if ( V_185 ) {
if ( V_185 > sizeof( V_22 -> V_192 ) ) {
F_4 ( V_22 -> V_12 -> V_4 ,
L_28 ) ;
return - 1 ;
}
memcpy ( V_22 -> V_192 , V_184 , V_185 ) ;
V_22 -> V_193 = V_185 ;
F_4 ( V_22 -> V_12 -> V_4 , L_29 ,
V_22 -> V_193 , V_22 -> V_192 [ 0 ] ) ;
if ( V_22 -> V_192 [ 0 ] == V_194 )
V_22 -> V_90 . V_195 = true ;
} else {
memset ( V_22 -> V_192 , 0 , sizeof( V_22 -> V_192 ) ) ;
V_22 -> V_193 = V_185 ;
F_4 ( V_22 -> V_12 -> V_4 ,
L_30 ,
V_22 -> V_193 , V_22 -> V_192 [ 0 ] ) ;
V_22 -> V_90 . V_195 = false ;
}
return 0 ;
}
static int F_47 ( struct V_21 * V_22 ,
T_2 * V_184 , T_1 V_185 )
{
if ( V_185 ) {
V_22 -> V_196 = F_19 ( V_197 , V_45 ) ;
if ( ! V_22 -> V_196 )
return - V_46 ;
if ( V_185 > sizeof( V_22 -> V_196 ) ) {
F_4 ( V_22 -> V_12 -> V_4 ,
L_31 ) ;
F_14 ( V_22 -> V_196 ) ;
return - 1 ;
}
memcpy ( V_22 -> V_196 , V_184 , V_185 ) ;
V_22 -> V_198 = V_185 ;
F_4 ( V_22 -> V_12 -> V_4 , L_32 ,
V_22 -> V_198 , V_22 -> V_196 [ 0 ] ) ;
} else {
F_14 ( V_22 -> V_196 ) ;
V_22 -> V_198 = V_185 ;
F_4 ( V_22 -> V_12 -> V_4 ,
L_33 , V_22 -> V_198 ) ;
}
return 0 ;
}
static int F_48 ( struct V_21 * V_22 ,
struct V_199 * V_200 )
{
return F_34 ( V_22 , V_201 ,
V_34 , V_202 ,
V_200 ) ;
}
static int F_49 ( struct V_21 * V_22 ,
struct V_199 * V_200 )
{
int V_24 ;
struct V_203 * V_204 ;
int V_205 ;
if ( V_22 -> V_206 >= V_207 )
V_22 -> V_206 = 0 ;
V_204 = & V_22 -> V_204 [ V_22 -> V_206 ] ;
V_205 = V_200 -> V_208 ;
if ( V_200 -> V_209 ) {
V_22 -> V_90 . V_92 = 0 ;
} else if ( ! V_200 -> V_210 ) {
V_204 = & V_22 -> V_204 [ V_205 ] ;
if ( ! V_204 -> V_211 ) {
F_12 ( V_22 -> V_12 -> V_4 ,
L_34 ) ;
return - 1 ;
}
V_22 -> V_206 = ( T_1 ) V_205 ;
V_22 -> V_90 . V_92 = 1 ;
} else {
V_204 = & V_22 -> V_204 [ V_205 ] ;
memset ( V_204 , 0 , sizeof( struct V_203 ) ) ;
memcpy ( V_204 -> V_212 ,
V_200 -> V_212 ,
V_200 -> V_210 ) ;
V_204 -> V_208 = V_205 ;
V_204 -> V_211 = V_200 -> V_210 ;
V_22 -> V_90 . V_92 = 1 ;
}
if ( V_204 -> V_211 ) {
V_24 = F_9 ( V_22 ,
V_201 ,
V_34 , 0 , NULL ) ;
if ( V_24 )
return V_24 ;
}
if ( V_22 -> V_90 . V_92 )
V_22 -> V_26 |= V_213 ;
else
V_22 -> V_26 &= ~ V_213 ;
V_24 = F_34 ( V_22 , V_35 ,
V_34 , 0 ,
& V_22 -> V_26 ) ;
return V_24 ;
}
static int F_50 ( struct V_21 * V_22 ,
struct V_199 * V_200 )
{
int V_24 ;
T_2 V_214 = false ;
struct V_215 * V_216 ;
if ( V_200 -> V_210 > V_217 ) {
F_12 ( V_22 -> V_12 -> V_4 , L_35 ) ;
return - 1 ;
}
if ( V_22 -> V_66 == V_67 ) {
V_200 -> V_208 = V_218 ;
V_24 = F_9 ( V_22 ,
V_201 ,
V_34 ,
V_202 , V_200 ) ;
if ( V_24 )
return V_24 ;
V_216 = & V_22 -> V_219 ;
memset ( V_216 , 0 ,
sizeof( struct V_215 ) ) ;
memcpy ( V_216 -> V_220 . V_221 , V_200 -> V_212 ,
V_200 -> V_210 ) ;
memcpy ( & V_216 -> V_220 . V_210 , & V_200 -> V_210 ,
sizeof( V_216 -> V_220 . V_210 ) ) ;
V_216 -> V_220 . V_222
= F_43 ( V_223 ) ;
V_216 -> V_220 . V_224 = F_43 ( V_225 ) ;
V_200 -> V_208 = ~ V_218 ;
}
if ( ! V_200 -> V_208 )
V_200 -> V_208 = V_218 ;
if ( V_214 )
V_24 = F_34 ( V_22 ,
V_201 ,
V_34 ,
! V_202 , V_200 ) ;
else
V_24 = F_34 ( V_22 ,
V_201 ,
V_34 ,
V_202 , V_200 ) ;
return V_24 ;
}
static int
F_51 ( struct V_21 * V_22 ,
struct V_199 * V_200 )
{
int V_14 ;
if ( V_200 -> V_226 )
V_14 = F_48 ( V_22 , V_200 ) ;
else if ( V_200 -> V_210 > V_227 )
V_14 = F_50 ( V_22 , V_200 ) ;
else
V_14 = F_49 ( V_22 , V_200 ) ;
return V_14 ;
}
int
F_52 ( struct V_11 * V_12 , char * V_228 ,
int V_229 )
{
union {
T_3 V_230 ;
T_2 V_231 [ 4 ] ;
} V_232 ;
char V_233 [ 32 ] ;
V_232 . V_230 = V_12 -> V_234 ;
sprintf ( V_233 , L_36 , V_232 . V_231 [ 2 ] , V_232 . V_231 [ 1 ] , V_232 . V_231 [ 0 ] , V_232 . V_231 [ 3 ] ) ;
snprintf ( V_228 , V_229 , V_235 , V_233 ) ;
F_4 ( V_12 -> V_4 , L_37 , V_228 ) ;
return 0 ;
}
int F_53 ( struct V_21 * V_22 , struct V_236 * V_237 ,
const T_2 * V_221 , int V_210 , T_2 V_208 ,
const T_2 * V_238 , int V_239 )
{
struct V_199 V_200 ;
memset ( & V_200 , 0 , sizeof( struct V_199 ) ) ;
V_200 . V_210 = V_210 ;
if ( V_237 && V_237 -> V_240 == V_241 )
V_200 . V_242 = true ;
if ( ! V_239 ) {
V_200 . V_208 = V_208 ;
if ( V_210 )
memcpy ( V_200 . V_212 , V_221 , V_210 ) ;
if ( V_238 )
memcpy ( V_200 . V_238 , V_238 , V_10 ) ;
if ( V_237 && V_237 -> V_243 && V_237 -> V_244 )
memcpy ( V_200 . V_245 , V_237 -> V_243 , V_237 -> V_244 ) ;
} else {
V_200 . V_209 = true ;
if ( V_238 )
memcpy ( V_200 . V_238 , V_238 , V_10 ) ;
}
return F_51 ( V_22 , & V_200 ) ;
}
int
F_54 ( struct V_21 * V_22 )
{
struct V_246 V_247 ;
memset ( & V_247 , 0 , sizeof( struct V_248 ) ) ;
if ( F_34 ( V_22 , V_249 ,
V_114 , 0 , & V_247 ) )
return - 1 ;
return 0 ;
}
int
F_55 ( struct V_21 * V_22 , T_1 V_100 ,
struct V_250 * V_251 ,
enum V_252 * V_253 ,
unsigned int V_254 )
{
struct V_255 V_256 ;
T_2 V_257 ;
memset ( & V_256 , 0 , sizeof( V_256 ) ) ;
V_256 . V_100 = F_43 ( V_100 ) ;
if ( V_100 == V_34 ) {
V_256 . V_258 = V_251 -> V_57 ;
V_257 = F_56 ( * V_253 ) ;
V_256 . V_258 |= ( V_257 << 2 ) ;
V_256 . V_125 =
F_57 ( V_251 -> V_259 ) ;
V_256 . V_254 = F_33 ( V_254 ) ;
}
if ( F_34 ( V_22 , V_260 ,
V_100 , 0 , & V_256 ) ) {
F_12 ( V_22 -> V_12 -> V_4 , L_38 ) ;
return - 1 ;
}
return V_256 . V_14 ;
}
int
F_58 ( struct V_21 * V_22 , T_2 V_261 )
{
if ( F_59 ( V_22 ) == V_261 ) {
F_4 ( V_22 -> V_12 -> V_4 ,
L_39 ) ;
return 0 ;
}
F_60 ( V_22 ) ;
F_61 ( V_22 ) ;
V_22 -> V_261 = V_261 ;
switch ( V_261 ) {
case V_262 :
V_22 -> V_66 = V_263 ;
break;
case V_120 :
case V_264 :
default:
V_22 -> V_66 = V_68 ;
break;
}
F_34 ( V_22 , V_265 ,
V_34 , 0 , NULL ) ;
return F_62 ( V_22 , false ) ;
}
int
F_63 ( struct V_21 * V_22 ,
struct V_266 * log )
{
return F_34 ( V_22 , V_267 ,
V_114 , 0 , log ) ;
}
static int F_64 ( struct V_21 * V_22 ,
struct V_268 * V_269 ,
T_1 V_100 )
{
T_1 V_270 ;
switch ( F_32 ( V_269 -> type ) ) {
case V_271 :
V_270 = V_272 ;
break;
case V_273 :
V_270 = V_274 ;
break;
case V_275 :
V_270 = V_276 ;
break;
case V_277 :
V_270 = V_278 ;
break;
case V_279 :
V_270 = V_280 ;
break;
default:
return - 1 ;
}
return F_34 ( V_22 , V_270 , V_100 , 0 , V_269 ) ;
}
int
F_65 ( struct V_21 * V_22 , T_3 V_281 ,
T_3 V_282 , T_3 V_283 )
{
struct V_268 V_269 ;
V_269 . type = F_33 ( V_281 ) ;
V_269 . V_284 = F_33 ( V_282 ) ;
V_269 . V_285 = F_33 ( V_283 ) ;
return F_64 ( V_22 , & V_269 , V_34 ) ;
}
int
F_66 ( struct V_21 * V_22 , T_3 V_281 ,
T_3 V_282 , T_3 * V_285 )
{
int V_24 ;
struct V_268 V_269 ;
V_269 . type = F_33 ( V_281 ) ;
V_269 . V_284 = F_33 ( V_282 ) ;
V_24 = F_64 ( V_22 , & V_269 , V_114 ) ;
if ( V_24 )
goto V_86;
* V_285 = F_32 ( V_269 . V_285 ) ;
V_86:
return V_24 ;
}
int
F_67 ( struct V_21 * V_22 , T_1 V_284 , T_1 V_286 ,
T_2 * V_285 )
{
int V_24 ;
struct V_287 V_288 ;
V_288 . V_284 = F_43 ( ( T_1 ) V_284 ) ;
V_288 . V_289 = F_43 ( ( T_1 ) V_286 ) ;
V_24 = F_34 ( V_22 , V_290 ,
V_114 , 0 , & V_288 ) ;
if ( ! V_24 )
memcpy ( V_285 , V_288 . V_285 , V_291 ) ;
return V_24 ;
}
static int
F_68 ( struct V_21 * V_22 , T_2 * V_184 ,
T_1 V_185 )
{
int V_24 = 0 ;
struct V_292 * V_293 ;
const T_2 V_294 [] = { 0x00 , 0x50 , 0xf2 , 0x01 } ;
const T_2 V_295 [] = { 0x00 , 0x50 , 0xf2 , 0x04 } ;
if ( ! V_185 ) {
V_22 -> V_296 = 0 ;
V_22 -> V_297 . V_298 = false ;
return 0 ;
} else if ( ! V_184 ) {
return - 1 ;
}
V_293 = (struct V_292 * ) V_184 ;
if ( ( ( V_293 -> V_299 == V_188 ) &&
( ! memcmp ( V_293 -> V_300 , V_294 , sizeof( V_294 ) ) ) ) ||
( V_293 -> V_299 == V_190 ) ) {
V_24 = F_45 ( V_22 , V_184 , V_185 ) ;
V_22 -> V_297 . V_298 = false ;
return V_24 ;
} else if ( V_293 -> V_299 == V_194 ) {
V_24 = F_46 ( V_22 , V_184 , V_185 ) ;
return V_24 ;
}
if ( V_185 < ( sizeof( V_22 -> V_301 ) - V_22 -> V_296 ) ) {
V_293 = (struct V_292 * ) V_184 ;
if ( ( V_293 -> V_299 == V_302 ) &&
( ! memcmp ( V_293 -> V_300 , V_295 , sizeof( V_295 ) ) ) ) {
V_22 -> V_297 . V_298 = true ;
F_4 ( V_22 -> V_12 -> V_4 ,
L_40 ) ;
V_24 = F_47 ( V_22 , V_184 , V_185 ) ;
}
memcpy ( V_22 -> V_301 + V_22 -> V_296 , V_184 ,
V_185 ) ;
V_22 -> V_296 += V_185 ;
} else {
V_24 = - 1 ;
}
return V_24 ;
}
static int F_69 ( struct V_21 * V_22 ,
struct V_303 * V_304 ,
T_1 V_100 )
{
struct V_11 * V_12 = V_22 -> V_12 ;
switch ( V_304 -> type ) {
case V_305 :
if ( V_100 == V_114 ) {
V_304 -> V_306 = V_22 -> V_187 ;
memcpy ( V_304 -> V_307 , V_22 -> V_186 , V_304 -> V_306 ) ;
} else {
F_68 ( V_22 , V_304 -> V_307 ,
( T_1 ) V_304 -> V_306 ) ;
}
break;
case V_308 :
memset ( V_12 -> V_309 , 0 , sizeof( V_12 -> V_309 ) ) ;
if ( V_304 -> V_306 > V_310 ) {
V_12 -> V_311 = 0 ;
F_12 ( V_12 -> V_4 , L_41 ) ;
return - 1 ;
} else {
memcpy ( V_12 -> V_309 , V_304 -> V_307 ,
V_304 -> V_306 ) ;
V_12 -> V_311 = V_304 -> V_306 ;
}
break;
default:
F_12 ( V_12 -> V_4 , L_42 ) ;
return - 1 ;
}
return 0 ;
}
int
F_70 ( struct V_21 * V_22 , T_2 * V_312 , int V_185 )
{
struct V_303 V_304 ;
if ( V_185 > V_313 )
return - V_314 ;
V_304 . type = V_305 ;
V_304 . V_306 = V_185 ;
memcpy ( V_304 . V_307 , V_312 , V_185 ) ;
if ( F_69 ( V_22 , & V_304 , V_34 ) )
return - V_314 ;
return 0 ;
}
