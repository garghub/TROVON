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
int F_15 ( struct V_21 * V_22 , struct V_36 * V_37 ,
struct V_69 * V_70 )
{
int V_24 ;
struct V_11 * V_12 = V_22 -> V_12 ;
struct V_38 * V_39 = NULL ;
V_22 -> V_71 = false ;
if ( V_37 ) {
V_39 = F_16 ( sizeof( struct V_38 ) ,
V_45 ) ;
if ( ! V_39 ) {
F_12 ( V_22 -> V_12 -> V_4 , L_9 ) ;
return - V_46 ;
}
V_24 = F_10 ( V_22 , V_37 , V_39 ) ;
if ( V_24 )
goto V_72;
}
if ( V_22 -> V_66 == V_68 ) {
V_24 = F_17 ( V_22 , NULL ) ;
if ( V_24 )
goto V_72;
V_24 = F_18 ( V_22 , V_39 ) ;
if ( V_24 )
goto V_72;
F_4 ( V_12 -> V_4 , L_10
L_11 ) ;
if ( ! F_19 ( V_22 -> V_73 ) )
F_20 ( V_22 -> V_73 , V_12 ) ;
if ( F_21 ( V_22 -> V_73 ) )
F_22 ( V_22 -> V_73 ) ;
V_22 -> V_74 = 0 ;
V_24 = F_23 ( V_22 , V_39 ) ;
if ( V_24 == V_75 &&
V_22 -> V_76 . V_77 &&
V_22 -> V_76 . V_78 ) {
V_22 -> V_76 . V_79 =
V_80 ;
V_24 = F_23 ( V_22 , V_39 ) ;
}
if ( V_37 )
F_24 ( V_37 ) ;
} else {
if ( V_39 && V_39 -> V_81 . V_82 &&
( ! F_25 ( & V_22 -> V_83 . V_84 .
V_81 , & V_39 -> V_81 ) ) ) {
F_14 ( V_39 ) ;
return 0 ;
}
F_4 ( V_12 -> V_4 , L_12 ) ;
V_24 = F_17 ( V_22 , NULL ) ;
if ( V_24 )
goto V_72;
V_22 -> V_85 = false ;
V_24 = F_18 ( V_22 , V_39 ) ;
if ( ! F_19 ( V_22 -> V_73 ) )
F_20 ( V_22 -> V_73 , V_12 ) ;
if ( F_21 ( V_22 -> V_73 ) )
F_22 ( V_22 -> V_73 ) ;
if ( ! V_24 ) {
F_4 ( V_12 -> V_4 , L_13
L_14 ) ;
V_24 = F_26 ( V_22 , V_39 ) ;
if ( V_37 )
F_24 ( V_37 ) ;
} else {
F_4 ( V_12 -> V_4 , L_15
L_16 ,
V_70 -> V_81 ) ;
V_24 = F_27 ( V_22 , V_70 ) ;
}
}
V_72:
F_14 ( V_39 ) ;
return V_24 ;
}
static int F_28 ( struct V_21 * V_22 , T_1 V_86 ,
int V_87 , struct V_88 * V_89 )
{
struct V_11 * V_12 = V_22 -> V_12 ;
int V_14 = 0 ;
T_3 V_90 = 0 ;
if ( ! V_89 )
return - V_46 ;
switch ( V_86 ) {
case V_34 :
if ( V_12 -> V_91 ) {
F_4 ( V_12 -> V_4 , L_17
L_18 ) ;
V_14 = - 1 ;
break;
}
if ( V_89 -> V_92 ) {
if ( V_89 -> V_93 == V_94 ) {
if ( ! V_12 -> V_95 )
break;
V_90 = F_29 ( V_12 -> V_89
. V_93 ) ;
V_12 -> V_89 . V_93 =
F_30 ( V_89 -> V_93 ) ;
} else if ( V_89 -> V_93 ) {
V_12 -> V_89 . V_93 =
F_30 ( V_89 -> V_93 ) ;
V_12 -> V_89 . V_96 = ( T_2 ) V_89 -> V_96 ;
if ( V_89 -> V_97 )
V_12 -> V_89 . V_97 = ( T_2 ) V_89 -> V_97 ;
} else if ( V_12 -> V_89 . V_93
== F_30 ( V_94 ) ) {
V_14 = - 1 ;
break;
}
if ( V_87 == V_98 )
V_14 = F_31 ( V_22 ,
V_99 ,
V_34 , 0 ,
& V_12 -> V_89 ) ;
else
V_14 = F_9 ( V_22 ,
V_99 ,
V_34 , 0 ,
& V_12 -> V_89 ) ;
if ( V_89 -> V_93 == V_94 )
V_12 -> V_89 . V_93 =
F_30 ( V_90 ) ;
} else {
V_12 -> V_89 . V_93 =
F_30 ( V_89 -> V_93 ) ;
V_12 -> V_89 . V_96 = ( T_2 ) V_89 -> V_96 ;
V_12 -> V_89 . V_97 = ( T_2 ) V_89 -> V_97 ;
}
break;
case V_100 :
V_89 -> V_93 = F_29 ( V_12 -> V_89 . V_93 ) ;
V_89 -> V_96 = V_12 -> V_89 . V_96 ;
V_89 -> V_97 = V_12 -> V_89 . V_97 ;
break;
default:
V_14 = - 1 ;
break;
}
return V_14 ;
}
int F_32 ( struct V_21 * V_22 , int V_87 )
{
struct V_88 V_101 ;
V_101 . V_93 = V_94 ;
V_101 . V_92 = true ;
return F_28 ( V_22 , V_34 ,
V_87 , & V_101 ) ;
}
int F_33 ( struct V_11 * V_12 )
{
struct V_88 V_101 ;
if ( V_12 -> V_102 ) {
F_4 ( V_12 -> V_4 , L_19 ) ;
return true ;
}
V_12 -> V_103 = false ;
memset ( & V_101 , 0 , sizeof( struct V_88 ) ) ;
V_101 . V_92 = true ;
if ( F_28 ( F_34 ( V_12 ,
V_104 ) ,
V_34 , V_98 ,
& V_101 ) ) {
F_12 ( V_12 -> V_4 , L_20 ) ;
return false ;
}
F_6 ( V_12 -> V_105 ,
V_12 -> V_103 ) ;
return true ;
}
int F_35 ( struct V_21 * V_22 ,
struct V_106 * V_107 )
{
struct V_11 * V_12 = V_22 -> V_12 ;
struct V_38 * V_39 ;
if ( ! V_107 )
return - 1 ;
V_39 = & V_22 -> V_83 . V_84 ;
V_107 -> V_66 = V_22 -> V_66 ;
memcpy ( & V_107 -> V_81 , & V_39 -> V_81 , sizeof( struct V_69 ) ) ;
memcpy ( & V_107 -> V_48 , & V_39 -> V_47 , V_10 ) ;
V_107 -> V_108 = V_39 -> V_109 ;
memcpy ( V_107 -> V_110 , V_12 -> V_110 ,
V_111 ) ;
V_107 -> V_112 = V_22 -> V_112 ;
V_107 -> V_113 = V_22 -> V_114 ;
V_107 -> V_115 = V_22 -> V_116 ;
V_107 -> V_117 = V_22 -> V_117 ;
V_107 -> V_118 = V_22 -> V_118 ;
if ( V_22 -> V_76 . V_78 )
V_107 -> V_119 = true ;
else
V_107 -> V_119 = false ;
V_107 -> V_95 = V_12 -> V_95 ;
V_107 -> V_120 = V_12 -> V_120 ;
return 0 ;
}
int F_36 ( struct V_21 * V_22 )
{
struct V_121 V_122 ;
V_122 . V_122 = V_123 ;
return F_31 ( V_22 , V_124 ,
V_125 , V_126 , & V_122 ) ;
}
int F_37 ( struct V_21 * V_22 , T_3 * V_127 )
{
int V_24 ;
V_24 = F_31 ( V_22 , V_128 ,
V_100 , 0 , NULL ) ;
if ( ! V_24 ) {
if ( V_22 -> V_129 )
* V_127 = F_38 ( V_22 , V_22 -> V_130 ,
V_22 -> V_131 ) ;
else
* V_127 = V_22 -> V_132 ;
}
return V_24 ;
}
int F_39 ( struct V_21 * V_22 ,
struct V_133 * V_134 )
{
int V_24 ;
struct V_135 * V_136 ;
struct V_137 * V_138 ;
struct V_139 * V_140 ;
T_2 * V_141 ;
T_1 V_142 = 0 ;
if ( ! V_134 -> V_143 ) {
V_142 = ( T_1 ) V_134 -> V_144 ;
if ( ( V_142 < V_22 -> V_116 ) ||
( V_142 > V_22 -> V_114 ) ) {
F_12 ( V_22 -> V_12 -> V_4 , L_21
L_22 ,
V_142 , V_22 -> V_116 ,
V_22 -> V_114 ) ;
return - 1 ;
}
}
V_141 = F_16 ( V_145 , V_45 ) ;
if ( ! V_141 ) {
F_12 ( V_22 -> V_12 -> V_4 , L_23 ,
V_146 ) ;
return - V_46 ;
}
V_136 = (struct V_135 * ) V_141 ;
V_136 -> V_86 = F_40 ( V_34 ) ;
if ( ! V_134 -> V_143 ) {
V_136 -> V_27 = F_30 ( 1 ) ;
V_138 = (struct V_137 * )
( V_141 + sizeof( struct V_135 ) ) ;
V_138 -> type = V_147 ;
V_138 -> V_148 = 4 * sizeof( struct V_139 ) ;
V_140 = (struct V_139 * )
( V_141 + sizeof( struct V_135 )
+ sizeof( struct V_137 ) ) ;
V_140 -> V_149 = 0x00 ;
V_140 -> V_150 = 0x03 ;
V_140 -> V_151 = V_152 ;
V_140 -> V_153 = 0 ;
V_140 -> V_154 = ( V_155 ) V_142 ;
V_140 -> V_156 = ( V_155 ) V_142 ;
V_140 ++ ;
V_140 -> V_149 = 0x00 ;
V_140 -> V_150 = 0x07 ;
V_140 -> V_151 = V_157 ;
V_140 -> V_153 = 0 ;
V_140 -> V_154 = ( V_155 ) V_142 ;
V_140 -> V_156 = ( V_155 ) V_142 ;
V_140 ++ ;
V_140 -> V_149 = 0x00 ;
V_140 -> V_150 = 0x20 ;
V_140 -> V_151 = V_158 ;
V_140 -> V_153 = 0 ;
V_140 -> V_154 = ( V_155 ) V_142 ;
V_140 -> V_156 = ( V_155 ) V_142 ;
V_140 -> V_159 = V_160 ;
V_140 ++ ;
V_140 -> V_149 = 0x00 ;
V_140 -> V_150 = 0x20 ;
V_140 -> V_151 = V_158 ;
V_140 -> V_153 = 0 ;
V_140 -> V_154 = ( V_155 ) V_142 ;
V_140 -> V_156 = ( V_155 ) V_142 ;
V_140 -> V_159 = V_161 ;
}
V_24 = F_31 ( V_22 , V_162 ,
V_34 , 0 , V_141 ) ;
F_14 ( V_141 ) ;
return V_24 ;
}
int F_41 ( struct V_21 * V_22 , T_3 * V_163 )
{
int V_24 ;
struct V_11 * V_12 = V_22 -> V_12 ;
T_1 V_164 ;
if ( * V_163 )
V_12 -> V_163 = V_165 ;
else
V_12 -> V_163 = V_166 ;
V_164 = ( * V_163 ) ? V_167 : V_125 ;
V_24 = F_31 ( V_22 , V_124 ,
V_164 , V_168 , NULL ) ;
if ( ( ! V_24 ) && ( V_164 == V_125 ) )
V_24 = F_9 ( V_22 ,
V_124 ,
V_169 , 0 , NULL ) ;
return V_24 ;
}
static int F_42 ( struct V_21 * V_22 ,
T_2 * V_170 , T_1 V_171 )
{
if ( V_171 ) {
if ( V_171 > sizeof( V_22 -> V_172 ) ) {
F_12 ( V_22 -> V_12 -> V_4 ,
L_24 ) ;
return - 1 ;
}
memcpy ( V_22 -> V_172 , V_170 , V_171 ) ;
V_22 -> V_173 = ( T_2 ) V_171 ;
F_4 ( V_22 -> V_12 -> V_4 , L_25 ,
V_22 -> V_173 , V_22 -> V_172 [ 0 ] ) ;
if ( V_22 -> V_172 [ 0 ] == V_174 ) {
V_22 -> V_76 . V_175 = true ;
} else if ( V_22 -> V_172 [ 0 ] == V_176 ) {
V_22 -> V_76 . V_177 = true ;
} else {
V_22 -> V_76 . V_175 = false ;
V_22 -> V_76 . V_177 = false ;
}
} else {
memset ( V_22 -> V_172 , 0 , sizeof( V_22 -> V_172 ) ) ;
V_22 -> V_173 = 0 ;
F_4 ( V_22 -> V_12 -> V_4 , L_26 ,
V_22 -> V_173 , V_22 -> V_172 [ 0 ] ) ;
V_22 -> V_76 . V_175 = false ;
V_22 -> V_76 . V_177 = false ;
}
return 0 ;
}
static int F_43 ( struct V_21 * V_22 ,
T_2 * V_170 , T_1 V_171 )
{
if ( V_171 ) {
if ( V_171 > sizeof( V_22 -> V_178 ) ) {
F_4 ( V_22 -> V_12 -> V_4 ,
L_27 ) ;
return - 1 ;
}
memcpy ( V_22 -> V_178 , V_170 , V_171 ) ;
V_22 -> V_179 = V_171 ;
F_4 ( V_22 -> V_12 -> V_4 , L_28 ,
V_22 -> V_179 , V_22 -> V_178 [ 0 ] ) ;
if ( V_22 -> V_178 [ 0 ] == V_180 )
V_22 -> V_76 . V_181 = true ;
} else {
memset ( V_22 -> V_178 , 0 , sizeof( V_22 -> V_178 ) ) ;
V_22 -> V_179 = V_171 ;
F_4 ( V_22 -> V_12 -> V_4 ,
L_29 ,
V_22 -> V_179 , V_22 -> V_178 [ 0 ] ) ;
V_22 -> V_76 . V_181 = false ;
}
return 0 ;
}
static int F_44 ( struct V_21 * V_22 ,
T_2 * V_170 , T_1 V_171 )
{
if ( V_171 ) {
V_22 -> V_182 = F_16 ( V_183 , V_45 ) ;
if ( ! V_22 -> V_182 )
return - V_46 ;
if ( V_171 > sizeof( V_22 -> V_182 ) ) {
F_4 ( V_22 -> V_12 -> V_4 ,
L_30 ) ;
F_14 ( V_22 -> V_182 ) ;
return - 1 ;
}
memcpy ( V_22 -> V_182 , V_170 , V_171 ) ;
V_22 -> V_184 = V_171 ;
F_4 ( V_22 -> V_12 -> V_4 , L_31 ,
V_22 -> V_184 , V_22 -> V_182 [ 0 ] ) ;
} else {
F_14 ( V_22 -> V_182 ) ;
V_22 -> V_184 = V_171 ;
F_4 ( V_22 -> V_12 -> V_4 ,
L_32 , V_22 -> V_184 ) ;
}
return 0 ;
}
static int F_45 ( struct V_21 * V_22 ,
struct V_185 * V_186 )
{
return F_31 ( V_22 , V_187 ,
V_34 , V_188 ,
V_186 ) ;
}
static int F_46 ( struct V_21 * V_22 ,
struct V_185 * V_186 )
{
int V_24 ;
struct V_189 * V_190 ;
int V_191 ;
if ( V_22 -> V_192 >= V_193 )
V_22 -> V_192 = 0 ;
V_190 = & V_22 -> V_190 [ V_22 -> V_192 ] ;
V_191 = V_186 -> V_194 ;
if ( V_186 -> V_195 ) {
V_22 -> V_76 . V_78 = 0 ;
} else if ( ! V_186 -> V_196 ) {
V_190 = & V_22 -> V_190 [ V_191 ] ;
if ( ! V_190 -> V_197 ) {
F_12 ( V_22 -> V_12 -> V_4 ,
L_33 ) ;
return - 1 ;
}
V_22 -> V_192 = ( T_1 ) V_191 ;
V_22 -> V_76 . V_78 = 1 ;
} else {
V_190 = & V_22 -> V_190 [ V_191 ] ;
memset ( V_190 , 0 , sizeof( struct V_189 ) ) ;
memcpy ( V_190 -> V_198 ,
V_186 -> V_198 ,
V_186 -> V_196 ) ;
V_190 -> V_194 = V_191 ;
V_190 -> V_197 = V_186 -> V_196 ;
V_22 -> V_76 . V_78 = 1 ;
}
if ( V_190 -> V_197 ) {
V_24 = F_9 ( V_22 ,
V_187 ,
V_34 , 0 , NULL ) ;
if ( V_24 )
return V_24 ;
}
if ( V_22 -> V_76 . V_78 )
V_22 -> V_26 |= V_199 ;
else
V_22 -> V_26 &= ~ V_199 ;
V_24 = F_31 ( V_22 , V_35 ,
V_34 , 0 ,
& V_22 -> V_26 ) ;
return V_24 ;
}
static int F_47 ( struct V_21 * V_22 ,
struct V_185 * V_186 )
{
int V_24 ;
T_2 V_200 = false ;
struct V_201 * V_202 ;
if ( V_186 -> V_196 > V_203 ) {
F_12 ( V_22 -> V_12 -> V_4 , L_34 ) ;
return - 1 ;
}
if ( V_22 -> V_66 == V_67 ) {
V_186 -> V_194 = V_204 ;
V_24 = F_9 ( V_22 ,
V_187 ,
V_34 ,
V_188 , V_186 ) ;
if ( V_24 )
return V_24 ;
V_202 = & V_22 -> V_205 ;
memset ( V_202 , 0 ,
sizeof( struct V_201 ) ) ;
memcpy ( V_202 -> V_206 . V_207 , V_186 -> V_198 ,
V_186 -> V_196 ) ;
memcpy ( & V_202 -> V_206 . V_196 , & V_186 -> V_196 ,
sizeof( V_202 -> V_206 . V_196 ) ) ;
V_202 -> V_206 . V_208
= F_40 ( V_209 ) ;
V_202 -> V_206 . V_210 = F_40 ( V_211 ) ;
V_186 -> V_194 = ~ V_204 ;
}
if ( ! V_186 -> V_194 )
V_186 -> V_194 = V_204 ;
if ( V_200 )
V_24 = F_31 ( V_22 ,
V_187 ,
V_34 ,
! V_188 , V_186 ) ;
else
V_24 = F_31 ( V_22 ,
V_187 ,
V_34 ,
V_188 , V_186 ) ;
return V_24 ;
}
static int
F_48 ( struct V_21 * V_22 ,
struct V_185 * V_186 )
{
int V_14 ;
if ( V_186 -> V_212 )
V_14 = F_45 ( V_22 , V_186 ) ;
else if ( V_186 -> V_196 > V_213 )
V_14 = F_47 ( V_22 , V_186 ) ;
else
V_14 = F_46 ( V_22 , V_186 ) ;
return V_14 ;
}
int
F_49 ( struct V_11 * V_12 , char * V_214 ,
int V_215 )
{
union {
T_3 V_216 ;
T_2 V_217 [ 4 ] ;
} V_218 ;
char V_219 [ 32 ] ;
V_218 . V_216 = V_12 -> V_220 ;
sprintf ( V_219 , L_35 , V_218 . V_217 [ 2 ] , V_218 . V_217 [ 1 ] , V_218 . V_217 [ 0 ] , V_218 . V_217 [ 3 ] ) ;
snprintf ( V_214 , V_215 , V_221 , V_219 ) ;
F_4 ( V_12 -> V_4 , L_36 , V_214 ) ;
return 0 ;
}
int F_50 ( struct V_21 * V_22 , const T_2 * V_207 ,
int V_196 , T_2 V_194 ,
const T_2 * V_222 , int V_223 )
{
struct V_185 V_186 ;
memset ( & V_186 , 0 , sizeof( struct V_185 ) ) ;
V_186 . V_196 = V_196 ;
if ( ! V_223 ) {
V_186 . V_194 = V_194 ;
if ( V_196 )
memcpy ( V_186 . V_198 , V_207 , V_196 ) ;
if ( V_222 )
memcpy ( V_186 . V_222 , V_222 , V_10 ) ;
} else {
V_186 . V_195 = true ;
if ( V_222 )
memcpy ( V_186 . V_222 , V_222 , V_10 ) ;
}
return F_48 ( V_22 , & V_186 ) ;
}
int
F_51 ( struct V_21 * V_22 )
{
struct V_224 V_225 ;
memset ( & V_225 , 0 , sizeof( struct V_226 ) ) ;
if ( F_31 ( V_22 , V_227 ,
V_100 , 0 , & V_225 ) )
return - 1 ;
return 0 ;
}
int
F_52 ( struct V_21 * V_22 ,
struct V_228 * log )
{
return F_31 ( V_22 , V_229 ,
V_100 , 0 , log ) ;
}
static int F_53 ( struct V_21 * V_22 ,
struct V_230 * V_231 ,
T_1 V_86 )
{
T_1 V_232 ;
switch ( F_29 ( V_231 -> type ) ) {
case V_233 :
V_232 = V_234 ;
break;
case V_235 :
V_232 = V_236 ;
break;
case V_237 :
V_232 = V_238 ;
break;
case V_239 :
V_232 = V_240 ;
break;
case V_241 :
V_232 = V_242 ;
break;
default:
return - 1 ;
}
return F_31 ( V_22 , V_232 , V_86 , 0 , V_231 ) ;
}
int
F_54 ( struct V_21 * V_22 , T_3 V_243 ,
T_3 V_244 , T_3 V_245 )
{
struct V_230 V_231 ;
V_231 . type = F_30 ( V_243 ) ;
V_231 . V_246 = F_30 ( V_244 ) ;
V_231 . V_247 = F_30 ( V_245 ) ;
return F_53 ( V_22 , & V_231 , V_34 ) ;
}
int
F_55 ( struct V_21 * V_22 , T_3 V_243 ,
T_3 V_244 , T_3 * V_247 )
{
int V_24 ;
struct V_230 V_231 ;
V_231 . type = F_30 ( V_243 ) ;
V_231 . V_246 = F_30 ( V_244 ) ;
V_24 = F_53 ( V_22 , & V_231 , V_100 ) ;
if ( V_24 )
goto V_72;
* V_247 = F_29 ( V_231 . V_247 ) ;
V_72:
return V_24 ;
}
int
F_56 ( struct V_21 * V_22 , T_1 V_246 , T_1 V_248 ,
T_2 * V_247 )
{
int V_24 ;
struct V_249 V_250 ;
V_250 . V_246 = F_40 ( ( T_1 ) V_246 ) ;
V_250 . V_251 = F_40 ( ( T_1 ) V_248 ) ;
V_24 = F_31 ( V_22 , V_252 ,
V_100 , 0 , & V_250 ) ;
if ( ! V_24 )
memcpy ( V_247 , V_250 . V_247 , V_253 ) ;
return V_24 ;
}
static int
F_57 ( struct V_21 * V_22 , T_2 * V_170 ,
T_1 V_171 )
{
int V_24 = 0 ;
struct V_254 * V_255 ;
const T_2 V_256 [] = { 0x00 , 0x50 , 0xf2 , 0x01 } ;
const T_2 V_257 [] = { 0x00 , 0x50 , 0xf2 , 0x04 } ;
if ( ! V_171 ) {
V_22 -> V_258 = 0 ;
V_22 -> V_259 . V_260 = false ;
return 0 ;
} else if ( ! V_170 ) {
return - 1 ;
}
V_255 = (struct V_254 * ) V_170 ;
if ( ( ( V_255 -> V_261 == V_174 ) &&
( ! memcmp ( V_255 -> V_262 , V_256 , sizeof( V_256 ) ) ) ) ||
( V_255 -> V_261 == V_176 ) ) {
V_24 = F_42 ( V_22 , V_170 , V_171 ) ;
V_22 -> V_259 . V_260 = false ;
return V_24 ;
} else if ( V_255 -> V_261 == V_180 ) {
V_24 = F_43 ( V_22 , V_170 , V_171 ) ;
return V_24 ;
}
if ( V_171 < ( sizeof( V_22 -> V_263 ) - V_22 -> V_258 ) ) {
V_255 = (struct V_254 * ) V_170 ;
if ( ( V_255 -> V_261 == V_264 ) &&
( ! memcmp ( V_255 -> V_262 , V_257 , sizeof( V_257 ) ) ) ) {
V_22 -> V_259 . V_260 = true ;
F_4 ( V_22 -> V_12 -> V_4 ,
L_37 ) ;
V_24 = F_44 ( V_22 , V_170 , V_171 ) ;
}
memcpy ( V_22 -> V_263 + V_22 -> V_258 , V_170 ,
V_171 ) ;
V_22 -> V_258 += V_171 ;
} else {
V_24 = - 1 ;
}
return V_24 ;
}
static int F_58 ( struct V_21 * V_22 ,
struct V_265 * V_266 ,
T_1 V_86 )
{
struct V_11 * V_12 = V_22 -> V_12 ;
switch ( V_266 -> type ) {
case V_267 :
if ( V_86 == V_100 ) {
V_266 -> V_268 = V_22 -> V_173 ;
memcpy ( V_266 -> V_269 , V_22 -> V_172 , V_266 -> V_268 ) ;
} else {
F_57 ( V_22 , V_266 -> V_269 ,
( T_1 ) V_266 -> V_268 ) ;
}
break;
case V_270 :
memset ( V_12 -> V_271 , 0 , sizeof( V_12 -> V_271 ) ) ;
if ( V_266 -> V_268 > V_272 ) {
V_12 -> V_273 = 0 ;
F_12 ( V_12 -> V_4 , L_38 ) ;
return - 1 ;
} else {
memcpy ( V_12 -> V_271 , V_266 -> V_269 ,
V_266 -> V_268 ) ;
V_12 -> V_273 = V_266 -> V_268 ;
}
break;
default:
F_12 ( V_12 -> V_4 , L_39 ) ;
return - 1 ;
}
return 0 ;
}
int
F_59 ( struct V_21 * V_22 , T_2 * V_274 , int V_171 )
{
struct V_265 V_266 ;
if ( V_171 > V_275 )
return - V_276 ;
V_266 . type = V_267 ;
V_266 . V_268 = V_171 ;
memcpy ( V_266 . V_269 , V_274 , V_171 ) ;
if ( F_58 ( V_22 , & V_266 , V_34 ) )
return - V_276 ;
return 0 ;
}
