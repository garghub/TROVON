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
F_6 ( V_12 -> V_18 , & V_12 -> V_19 ) ;
F_7 ( V_12 -> V_20 . V_21 ,
* ( V_16 -> V_22 ) ) ;
if ( ! * ( V_16 -> V_22 ) )
V_13 = true ;
if ( V_13 ) {
F_8 ( V_12 ) ;
F_4 ( V_12 -> V_4 , L_2 ) ;
}
V_14 = V_12 -> V_20 . V_14 ;
V_12 -> V_20 . V_14 = 0 ;
return V_14 ;
}
int F_9 ( struct V_23 * V_24 ,
struct V_1 * V_25 )
{
int V_26 = 0 ;
T_1 V_27 ;
V_27 = V_24 -> V_28 ;
if ( V_25 -> V_29 == V_30 ) {
F_4 ( V_24 -> V_12 -> V_4 , L_3 ) ;
V_24 -> V_28 |= V_31 ;
V_24 -> V_28 &=
~ V_32 ;
} else {
V_24 -> V_28 &= ~ V_31 ;
if ( V_25 -> V_29 == V_33 ) {
F_4 ( V_24 -> V_12 -> V_4 ,
L_4 ) ;
V_24 -> V_28 |=
V_32 ;
} else {
V_24 -> V_28 &=
~ V_32 ;
if ( V_25 -> V_34 ) {
F_4 ( V_24 -> V_12 -> V_4 ,
L_5 ,
V_25 -> V_34 ) ;
if ( V_27 == V_24 -> V_28 ) {
V_26 = F_10 ( V_24 ,
V_35 ,
V_36 , 0 ,
V_25 ) ;
} else {
V_26 = F_10 ( V_24 ,
V_35 ,
V_36 , 0 ,
V_25 ) ;
}
}
}
}
F_4 ( V_24 -> V_12 -> V_4 ,
L_6 ,
V_27 , V_24 -> V_28 ) ;
if ( V_27 != V_24 -> V_28 ) {
V_26 = F_10 ( V_24 , V_37 ,
V_36 ,
0 , & V_24 -> V_28 ) ;
}
return V_26 ;
}
int F_11 ( struct V_23 * V_24 ,
struct V_38 * V_39 ,
struct V_40 * V_41 )
{
int V_26 ;
T_2 * V_42 ;
struct V_43 * V_44 = ( void * ) V_39 -> V_24 ;
V_42 = F_12 ( V_39 -> V_45 , V_39 -> V_46 ,
V_47 ) ;
if ( ! V_42 ) {
F_13 ( V_24 -> V_12 -> V_4 , L_7 ) ;
return - V_48 ;
}
memcpy ( V_41 -> V_49 , V_39 -> V_50 , V_10 ) ;
V_41 -> V_51 = V_39 -> signal ;
V_41 -> V_52 = V_42 ;
V_41 -> V_53 = V_39 -> V_46 ;
V_41 -> V_54 = V_39 -> V_55 ;
V_41 -> V_56 = V_39 -> V_57 ;
V_41 -> V_58 = V_44 -> V_59 ;
V_41 -> V_60 = V_44 -> V_60 ;
V_41 -> V_61 = V_39 -> V_62 ;
if ( V_41 -> V_56 & V_63 ) {
F_4 ( V_24 -> V_12 -> V_4 , L_8 ) ;
V_41 -> V_64 = V_65 ;
} else {
V_41 -> V_64 = V_66 ;
}
if ( V_41 -> V_56 & V_67 )
V_41 -> V_68 = V_69 ;
else
V_41 -> V_68 = V_70 ;
V_26 = F_14 ( V_24 -> V_12 , V_41 ) ;
F_15 ( V_42 ) ;
return V_26 ;
}
int F_16 ( struct V_23 * V_24 , struct V_38 * V_39 ,
struct V_71 * V_72 )
{
int V_26 ;
struct V_11 * V_12 = V_24 -> V_12 ;
struct V_40 * V_41 = NULL ;
V_24 -> V_73 = false ;
if ( V_39 ) {
V_41 = F_17 ( sizeof( struct V_40 ) ,
V_47 ) ;
if ( ! V_41 ) {
F_13 ( V_24 -> V_12 -> V_4 , L_9 ) ;
return - V_48 ;
}
V_26 = F_11 ( V_24 , V_39 , V_41 ) ;
if ( V_26 )
goto V_74;
}
if ( V_24 -> V_68 == V_70 ) {
V_26 = F_18 ( V_24 , NULL ) ;
if ( V_26 )
goto V_74;
V_26 = F_19 ( V_24 , V_41 ) ;
if ( V_26 )
goto V_74;
F_4 ( V_12 -> V_4 , L_10
L_11 ) ;
if ( ! F_20 ( V_24 -> V_75 ) )
F_21 ( V_24 -> V_75 , V_12 ) ;
if ( F_22 ( V_24 -> V_75 ) )
F_23 ( V_24 -> V_75 ) ;
V_24 -> V_76 = 0 ;
V_26 = F_24 ( V_24 , V_41 ) ;
if ( V_26 == V_77 &&
V_24 -> V_78 . V_79 &&
V_24 -> V_78 . V_80 ) {
V_24 -> V_78 . V_81 =
V_82 ;
V_26 = F_24 ( V_24 , V_41 ) ;
}
if ( V_39 )
F_25 ( V_39 ) ;
} else {
if ( V_41 && V_41 -> V_83 . V_84 &&
( ! F_26 ( & V_24 -> V_85 . V_86 .
V_83 , & V_41 -> V_83 ) ) ) {
F_15 ( V_41 ) ;
return 0 ;
}
F_4 ( V_12 -> V_4 , L_12 ) ;
V_26 = F_18 ( V_24 , NULL ) ;
if ( V_26 )
goto V_74;
V_24 -> V_87 = false ;
V_26 = F_19 ( V_24 , V_41 ) ;
if ( ! F_20 ( V_24 -> V_75 ) )
F_21 ( V_24 -> V_75 , V_12 ) ;
if ( F_22 ( V_24 -> V_75 ) )
F_23 ( V_24 -> V_75 ) ;
if ( ! V_26 ) {
F_4 ( V_12 -> V_4 , L_13
L_14 ) ;
V_26 = F_27 ( V_24 , V_41 ) ;
if ( V_39 )
F_25 ( V_39 ) ;
} else {
F_4 ( V_12 -> V_4 , L_15
L_16 ,
V_72 -> V_83 ) ;
V_26 = F_28 ( V_24 , V_72 ) ;
}
}
V_74:
F_15 ( V_41 ) ;
return V_26 ;
}
static int F_29 ( struct V_23 * V_24 , T_1 V_88 ,
int V_89 , struct V_90 * V_91 )
{
struct V_11 * V_12 = V_24 -> V_12 ;
int V_14 = 0 ;
T_3 V_92 = 0 ;
if ( ! V_91 )
return - V_48 ;
switch ( V_88 ) {
case V_36 :
if ( V_12 -> V_93 ) {
F_4 ( V_12 -> V_4 , L_17
L_18 ) ;
V_14 = - 1 ;
break;
}
if ( V_91 -> V_94 ) {
if ( V_91 -> V_95 == V_96 ) {
if ( ! V_12 -> V_97 )
break;
V_92 = F_30 ( V_12 -> V_91
. V_95 ) ;
V_12 -> V_91 . V_95 =
F_31 ( V_91 -> V_95 ) ;
} else if ( V_91 -> V_95 ) {
V_12 -> V_91 . V_95 =
F_31 ( V_91 -> V_95 ) ;
V_12 -> V_91 . V_98 = ( T_2 ) V_91 -> V_98 ;
if ( V_91 -> V_99 )
V_12 -> V_91 . V_99 = ( T_2 ) V_91 -> V_99 ;
} else if ( V_12 -> V_91 . V_95
== F_31 ( V_96 ) ) {
V_14 = - 1 ;
break;
}
if ( V_89 == V_100 )
V_14 = F_32 ( V_24 ,
V_101 ,
V_36 , 0 ,
& V_12 -> V_91 ) ;
else
V_14 = F_10 ( V_24 ,
V_101 ,
V_36 , 0 ,
& V_12 -> V_91 ) ;
if ( V_91 -> V_95 == V_96 )
V_12 -> V_91 . V_95 =
F_31 ( V_92 ) ;
} else {
V_12 -> V_91 . V_95 =
F_31 ( V_91 -> V_95 ) ;
V_12 -> V_91 . V_98 = ( T_2 ) V_91 -> V_98 ;
V_12 -> V_91 . V_99 = ( T_2 ) V_91 -> V_99 ;
}
break;
case V_102 :
V_91 -> V_95 = F_30 ( V_12 -> V_91 . V_95 ) ;
V_91 -> V_98 = V_12 -> V_91 . V_98 ;
V_91 -> V_99 = V_12 -> V_91 . V_99 ;
break;
default:
V_14 = - 1 ;
break;
}
return V_14 ;
}
int F_33 ( struct V_23 * V_24 , int V_89 )
{
struct V_90 V_103 ;
V_103 . V_95 = V_96 ;
V_103 . V_94 = true ;
return F_29 ( V_24 , V_36 ,
V_89 , & V_103 ) ;
}
int F_34 ( struct V_11 * V_12 )
{
struct V_90 V_103 ;
if ( V_12 -> V_104 ) {
F_4 ( V_12 -> V_4 , L_19 ) ;
return true ;
}
V_12 -> V_105 = false ;
memset ( & V_103 , 0 , sizeof( struct V_90 ) ) ;
V_103 . V_94 = true ;
if ( F_29 ( F_35 ( V_12 ,
V_106 ) ,
V_36 , V_100 ,
& V_103 ) ) {
F_13 ( V_12 -> V_4 , L_20 ) ;
return false ;
}
F_7 ( V_12 -> V_107 ,
V_12 -> V_105 ) ;
return true ;
}
int F_36 ( struct V_23 * V_24 ,
struct V_108 * V_109 )
{
struct V_11 * V_12 = V_24 -> V_12 ;
struct V_40 * V_41 ;
if ( ! V_109 )
return - 1 ;
V_41 = & V_24 -> V_85 . V_86 ;
V_109 -> V_68 = V_24 -> V_68 ;
memcpy ( & V_109 -> V_83 , & V_41 -> V_83 , sizeof( struct V_71 ) ) ;
memcpy ( & V_109 -> V_50 , & V_41 -> V_49 , V_10 ) ;
V_109 -> V_110 = V_41 -> V_111 ;
memcpy ( V_109 -> V_112 , V_12 -> V_112 ,
V_113 ) ;
V_109 -> V_114 = V_24 -> V_114 ;
V_109 -> V_115 = V_24 -> V_116 ;
V_109 -> V_117 = V_24 -> V_118 ;
V_109 -> V_119 = V_24 -> V_119 ;
V_109 -> V_120 = V_24 -> V_120 ;
if ( V_24 -> V_78 . V_80 )
V_109 -> V_121 = true ;
else
V_109 -> V_121 = false ;
V_109 -> V_97 = V_12 -> V_97 ;
V_109 -> V_122 = V_12 -> V_122 ;
return 0 ;
}
int F_37 ( struct V_23 * V_24 )
{
struct V_123 V_124 ;
V_124 . V_124 = V_125 ;
return F_32 ( V_24 , V_126 ,
V_127 , V_128 , & V_124 ) ;
}
int F_38 ( struct V_23 * V_24 ,
struct V_129 * V_130 )
{
struct V_11 * V_12 = V_24 -> V_12 ;
struct V_129 * V_131 = NULL ;
if ( ! V_130 )
return - 1 ;
if ( ! V_130 -> V_111 && ! V_130 -> V_132 )
return - 1 ;
if ( V_12 -> V_133 & V_134 )
V_12 -> V_133 = V_135 | V_136 | V_137 ;
else if ( V_12 -> V_133 & V_138 )
V_12 -> V_133 = V_135 | V_136 ;
if ( V_130 -> V_111 ) {
if ( V_130 -> V_111 <= V_139 )
V_131 = F_39 ( V_24 , 0 , ( T_1 ) V_130 -> V_111 , 0 ) ;
if ( ! V_131 ) {
V_131 = F_39 ( V_24 , V_138 ,
( T_1 ) V_130 -> V_111 , 0 ) ;
if ( V_131 ) {
if ( V_12 -> V_140 )
V_12 -> V_133 = V_138
| V_134 ;
else
V_12 -> V_133 = V_138 ;
}
}
} else {
if ( V_130 -> V_132 <= V_141 )
V_131 = F_39 ( V_24 , 0 , 0 , V_130 -> V_132 ) ;
if ( ! V_131 ) {
V_131 = F_39 ( V_24 , V_138 , 0 , V_130 -> V_132 ) ;
if ( V_131 ) {
if ( V_12 -> V_140 )
V_12 -> V_133 = V_138
| V_134 ;
else
V_12 -> V_133 = V_138 ;
}
}
}
if ( ! V_131 || ! V_131 -> V_111 ) {
F_13 ( V_12 -> V_4 , L_21 ) ;
return - 1 ;
}
V_24 -> V_142 = ( T_2 ) V_131 -> V_111 ;
V_130 -> V_111 = V_131 -> V_111 ;
V_130 -> V_132 = V_131 -> V_132 ;
return 0 ;
}
static int F_40 ( struct V_23 * V_24 ,
T_1 V_88 , T_1 * V_111 )
{
if ( V_88 == V_102 ) {
if ( ! V_24 -> V_114 ) {
* V_111 = V_24 -> V_142 ;
return 0 ;
}
} else {
V_24 -> V_142 = ( T_2 ) * V_111 ;
}
return F_32 ( V_24 , V_143 ,
V_88 , 0 , V_111 ) ;
}
int
F_41 ( struct V_23 * V_24 , T_1 V_111 )
{
int V_26 ;
struct V_108 V_144 ;
struct V_145 V_146 ;
T_1 V_147 = 0 ;
struct V_38 * V_39 = NULL ;
struct V_148 * V_130 ;
enum V_149 V_59 ;
memset ( & V_144 , 0 , sizeof( V_144 ) ) ;
if ( F_36 ( V_24 , & V_144 ) )
return - 1 ;
V_26 = F_40 ( V_24 , V_102 ,
& V_147 ) ;
if ( V_147 == V_111 ) {
V_26 = 0 ;
goto V_74;
}
F_4 ( V_24 -> V_12 -> V_4 , L_22 ,
V_147 , V_111 ) ;
if ( ! V_144 . V_114 ) {
V_26 = 0 ;
goto V_74;
}
memset ( & V_146 , 0 , V_10 ) ;
V_26 = F_18 ( V_24 , V_146 . V_50 ) ;
V_26 = F_40 ( V_24 , V_36 ,
& V_111 ) ;
if ( F_42 ( V_24 , & V_144 . V_83 ) ) {
V_26 = - 1 ;
goto V_74;
}
V_59 = F_43 ( V_24 -> V_85 . V_59 ) ;
V_130 = F_44 ( V_24 -> V_150 -> V_151 ,
F_45 ( V_111 ,
V_59 ) ) ;
V_39 = F_46 ( V_24 -> V_150 -> V_151 , V_130 , V_144 . V_50 ,
V_144 . V_83 . V_83 , V_144 . V_83 . V_84 ,
V_152 , V_152 ) ;
if ( ! V_39 )
F_47 ( V_24 -> V_150 -> V_151 , L_23 ,
V_144 . V_50 ) ;
V_26 = F_16 ( V_24 , V_39 , & V_144 . V_83 ) ;
V_74:
return V_26 ;
}
static int F_48 ( struct V_23 * V_24 ,
struct V_153 * V_154 )
{
V_154 -> V_155 = V_24 -> V_156 ;
return F_32 ( V_24 , V_157 ,
V_102 , 0 , NULL ) ;
}
static int F_49 ( struct V_23 * V_24 ,
struct V_153 * V_154 )
{
T_2 V_158 [ V_159 ] ;
T_2 * V_160 ;
int V_161 , V_26 ;
T_1 V_162 [ V_163 ] ;
T_3 V_5 ;
struct V_11 * V_12 = V_24 -> V_12 ;
if ( V_154 -> V_155 ) {
memset ( V_162 , 0 , sizeof( V_162 ) ) ;
V_162 [ 0 ] = 0x000F ;
V_162 [ 1 ] = 0x00FF ;
for ( V_5 = 0 ; V_5 < F_50 ( V_24 -> V_162 ) - 3 ; V_5 ++ )
V_162 [ V_5 + 2 ] = 0xFFFF ;
V_162 [ 9 ] = 0x3FFF ;
} else {
memset ( V_158 , 0 , sizeof( V_158 ) ) ;
F_51 ( V_24 , V_158 ) ;
V_160 = V_158 ;
for ( V_5 = 0 ; ( V_160 [ V_5 ] && V_5 < V_159 ) ; V_5 ++ ) {
F_4 ( V_12 -> V_4 , L_24 ,
V_160 [ V_5 ] , V_154 -> V_160 ) ;
if ( ( V_160 [ V_5 ] & 0x7f ) == ( V_154 -> V_160 & 0x7f ) )
break;
}
if ( ( V_5 == V_159 ) || ! V_160 [ V_5 ] ) {
F_13 ( V_12 -> V_4 , L_25
L_26 , V_154 -> V_160 ) ;
return - 1 ;
}
memset ( V_162 , 0 , sizeof( V_162 ) ) ;
V_161 = F_52 ( V_154 -> V_160 ) ;
if ( V_161 >= V_164 &&
V_161 <= V_165 ) {
V_162 [ 0 ] = 1 << V_161 ;
} else {
V_161 -= 1 ;
if ( V_161 >= V_166 &&
V_161 <= V_167 )
V_162 [ 1 ] = 1 << ( V_161 -
V_166 ) ;
}
}
V_26 = F_32 ( V_24 , V_168 ,
V_36 , 0 , V_162 ) ;
return V_26 ;
}
static int F_53 ( struct V_23 * V_24 ,
struct V_153 * V_154 )
{
int V_14 ;
if ( ! V_154 )
return - 1 ;
if ( V_154 -> V_88 == V_102 )
V_14 = F_48 ( V_24 , V_154 ) ;
else
V_14 = F_49 ( V_24 , V_154 ) ;
return V_14 ;
}
int F_54 ( struct V_23 * V_24 ,
struct V_153 * V_160 )
{
int V_26 ;
memset ( V_160 , 0 , sizeof( struct V_153 ) ) ;
V_160 -> V_88 = V_102 ;
V_26 = F_53 ( V_24 , V_160 ) ;
if ( ! V_26 ) {
if ( V_160 -> V_155 )
V_160 -> V_160 = F_55 ( V_24 ,
V_24 -> V_169 ,
V_24 -> V_170
) ;
else
V_160 -> V_160 = V_24 -> V_171 ;
} else {
V_26 = - 1 ;
}
return V_26 ;
}
int F_56 ( struct V_23 * V_24 ,
struct V_172 * V_173 )
{
int V_26 ;
struct V_174 * V_175 ;
struct V_176 * V_177 ;
struct V_178 * V_179 ;
T_2 * V_180 ;
T_1 V_181 = 0 ;
if ( ! V_173 -> V_182 ) {
V_181 = ( T_1 ) V_173 -> V_183 ;
if ( ( V_181 < V_24 -> V_118 ) ||
( V_181 > V_24 -> V_116 ) ) {
F_13 ( V_24 -> V_12 -> V_4 , L_27
L_28 ,
V_181 , V_24 -> V_118 ,
V_24 -> V_116 ) ;
return - 1 ;
}
}
V_180 = F_17 ( V_184 , V_47 ) ;
if ( ! V_180 ) {
F_13 ( V_24 -> V_12 -> V_4 , L_29 ,
V_185 ) ;
return - V_48 ;
}
V_175 = (struct V_174 * ) V_180 ;
V_175 -> V_88 = F_57 ( V_36 ) ;
if ( ! V_173 -> V_182 ) {
V_175 -> V_29 = F_31 ( 1 ) ;
V_177 = (struct V_176 * )
( V_180 + sizeof( struct V_174 ) ) ;
V_177 -> type = V_186 ;
V_177 -> V_187 = 4 * sizeof( struct V_178 ) ;
V_179 = (struct V_178 * )
( V_180 + sizeof( struct V_174 )
+ sizeof( struct V_176 ) ) ;
V_179 -> V_188 = 0x00 ;
V_179 -> V_189 = 0x03 ;
V_179 -> V_190 = V_191 ;
V_179 -> V_192 = 0 ;
V_179 -> V_193 = ( V_194 ) V_181 ;
V_179 -> V_195 = ( V_194 ) V_181 ;
V_179 ++ ;
V_179 -> V_188 = 0x00 ;
V_179 -> V_189 = 0x07 ;
V_179 -> V_190 = V_196 ;
V_179 -> V_192 = 0 ;
V_179 -> V_193 = ( V_194 ) V_181 ;
V_179 -> V_195 = ( V_194 ) V_181 ;
V_179 ++ ;
V_179 -> V_188 = 0x00 ;
V_179 -> V_189 = 0x20 ;
V_179 -> V_190 = V_197 ;
V_179 -> V_192 = 0 ;
V_179 -> V_193 = ( V_194 ) V_181 ;
V_179 -> V_195 = ( V_194 ) V_181 ;
V_179 -> V_198 = V_199 ;
V_179 ++ ;
V_179 -> V_188 = 0x00 ;
V_179 -> V_189 = 0x20 ;
V_179 -> V_190 = V_197 ;
V_179 -> V_192 = 0 ;
V_179 -> V_193 = ( V_194 ) V_181 ;
V_179 -> V_195 = ( V_194 ) V_181 ;
V_179 -> V_198 = V_200 ;
}
V_26 = F_32 ( V_24 , V_201 ,
V_36 , 0 , V_180 ) ;
F_15 ( V_180 ) ;
return V_26 ;
}
int F_58 ( struct V_23 * V_24 , T_3 * V_202 )
{
int V_26 ;
struct V_11 * V_12 = V_24 -> V_12 ;
T_1 V_203 ;
if ( * V_202 )
V_12 -> V_202 = V_204 ;
else
V_12 -> V_202 = V_205 ;
V_203 = ( * V_202 ) ? V_206 : V_127 ;
V_26 = F_32 ( V_24 , V_126 ,
V_203 , V_207 , NULL ) ;
if ( ( ! V_26 ) && ( V_203 == V_127 ) )
V_26 = F_10 ( V_24 ,
V_126 ,
V_208 , 0 , NULL ) ;
return V_26 ;
}
static int F_59 ( struct V_23 * V_24 ,
T_2 * V_209 , T_1 V_210 )
{
if ( V_210 ) {
if ( V_210 > sizeof( V_24 -> V_211 ) ) {
F_13 ( V_24 -> V_12 -> V_4 ,
L_30 ) ;
return - 1 ;
}
memcpy ( V_24 -> V_211 , V_209 , V_210 ) ;
V_24 -> V_212 = ( T_2 ) V_210 ;
F_4 ( V_24 -> V_12 -> V_4 , L_31 ,
V_24 -> V_212 , V_24 -> V_211 [ 0 ] ) ;
if ( V_24 -> V_211 [ 0 ] == V_213 ) {
V_24 -> V_78 . V_214 = true ;
} else if ( V_24 -> V_211 [ 0 ] == V_215 ) {
V_24 -> V_78 . V_216 = true ;
} else {
V_24 -> V_78 . V_214 = false ;
V_24 -> V_78 . V_216 = false ;
}
} else {
memset ( V_24 -> V_211 , 0 , sizeof( V_24 -> V_211 ) ) ;
V_24 -> V_212 = 0 ;
F_4 ( V_24 -> V_12 -> V_4 , L_32 ,
V_24 -> V_212 , V_24 -> V_211 [ 0 ] ) ;
V_24 -> V_78 . V_214 = false ;
V_24 -> V_78 . V_216 = false ;
}
return 0 ;
}
static int F_60 ( struct V_23 * V_24 ,
T_2 * V_209 , T_1 V_210 )
{
if ( V_210 ) {
if ( V_210 > sizeof( V_24 -> V_217 ) ) {
F_4 ( V_24 -> V_12 -> V_4 ,
L_33 ) ;
return - 1 ;
}
memcpy ( V_24 -> V_217 , V_209 , V_210 ) ;
V_24 -> V_218 = V_210 ;
F_4 ( V_24 -> V_12 -> V_4 , L_34 ,
V_24 -> V_218 , V_24 -> V_217 [ 0 ] ) ;
if ( V_24 -> V_217 [ 0 ] == V_219 )
V_24 -> V_78 . V_220 = true ;
} else {
memset ( V_24 -> V_217 , 0 , sizeof( V_24 -> V_217 ) ) ;
V_24 -> V_218 = V_210 ;
F_4 ( V_24 -> V_12 -> V_4 ,
L_35 ,
V_24 -> V_218 , V_24 -> V_217 [ 0 ] ) ;
V_24 -> V_78 . V_220 = false ;
}
return 0 ;
}
static int F_61 ( struct V_23 * V_24 ,
T_2 * V_209 , T_1 V_210 )
{
if ( V_210 ) {
V_24 -> V_221 = F_17 ( V_222 , V_47 ) ;
if ( ! V_24 -> V_221 )
return - V_48 ;
if ( V_210 > sizeof( V_24 -> V_221 ) ) {
F_4 ( V_24 -> V_12 -> V_4 ,
L_36 ) ;
F_15 ( V_24 -> V_221 ) ;
return - 1 ;
}
memcpy ( V_24 -> V_221 , V_209 , V_210 ) ;
V_24 -> V_223 = V_210 ;
F_4 ( V_24 -> V_12 -> V_4 , L_37 ,
V_24 -> V_223 , V_24 -> V_221 [ 0 ] ) ;
} else {
F_15 ( V_24 -> V_221 ) ;
V_24 -> V_223 = V_210 ;
F_4 ( V_24 -> V_12 -> V_4 ,
L_38 , V_24 -> V_223 ) ;
}
return 0 ;
}
static int F_62 ( struct V_23 * V_24 ,
struct V_224 * V_225 )
{
return F_32 ( V_24 , V_226 ,
V_36 , V_227 ,
V_225 ) ;
}
static int F_63 ( struct V_23 * V_24 ,
struct V_224 * V_225 )
{
int V_26 ;
struct V_228 * V_229 ;
int V_230 ;
if ( V_24 -> V_231 >= V_232 )
V_24 -> V_231 = 0 ;
V_229 = & V_24 -> V_229 [ V_24 -> V_231 ] ;
V_230 = V_225 -> V_233 ;
if ( V_225 -> V_234 ) {
V_24 -> V_78 . V_80 = 0 ;
} else if ( ! V_225 -> V_235 ) {
V_229 = & V_24 -> V_229 [ V_230 ] ;
if ( ! V_229 -> V_236 ) {
F_13 ( V_24 -> V_12 -> V_4 ,
L_39 ) ;
return - 1 ;
}
V_24 -> V_231 = ( T_1 ) V_230 ;
V_24 -> V_78 . V_80 = 1 ;
} else {
V_229 = & V_24 -> V_229 [ V_230 ] ;
memset ( V_229 , 0 , sizeof( struct V_228 ) ) ;
memcpy ( V_229 -> V_237 ,
V_225 -> V_237 ,
V_225 -> V_235 ) ;
V_229 -> V_233 = V_230 ;
V_229 -> V_236 = V_225 -> V_235 ;
V_24 -> V_78 . V_80 = 1 ;
}
if ( V_229 -> V_236 ) {
V_26 = F_10 ( V_24 ,
V_226 ,
V_36 , 0 , NULL ) ;
if ( V_26 )
return V_26 ;
}
if ( V_24 -> V_78 . V_80 )
V_24 -> V_28 |= V_238 ;
else
V_24 -> V_28 &= ~ V_238 ;
V_26 = F_32 ( V_24 , V_37 ,
V_36 , 0 ,
& V_24 -> V_28 ) ;
return V_26 ;
}
static int F_64 ( struct V_23 * V_24 ,
struct V_224 * V_225 )
{
int V_26 ;
T_2 V_239 = false ;
struct V_240 * V_241 ;
if ( V_225 -> V_235 > V_242 ) {
F_13 ( V_24 -> V_12 -> V_4 , L_40 ) ;
return - 1 ;
}
if ( V_24 -> V_68 == V_69 ) {
V_225 -> V_233 = V_243 ;
V_26 = F_10 ( V_24 ,
V_226 ,
V_36 ,
V_227 , V_225 ) ;
if ( V_26 )
return V_26 ;
V_241 = & V_24 -> V_244 ;
memset ( V_241 , 0 ,
sizeof( struct V_240 ) ) ;
memcpy ( V_241 -> V_245 . V_246 , V_225 -> V_237 ,
V_225 -> V_235 ) ;
memcpy ( & V_241 -> V_245 . V_235 , & V_225 -> V_235 ,
sizeof( V_241 -> V_245 . V_235 ) ) ;
V_241 -> V_245 . V_247
= F_57 ( V_248 ) ;
V_241 -> V_245 . V_249 = F_57 ( V_250 ) ;
V_225 -> V_233 = ~ V_243 ;
}
if ( ! V_225 -> V_233 )
V_225 -> V_233 = V_243 ;
if ( V_239 )
V_26 = F_32 ( V_24 ,
V_226 ,
V_36 ,
! V_227 , V_225 ) ;
else
V_26 = F_32 ( V_24 ,
V_226 ,
V_36 ,
V_227 , V_225 ) ;
return V_26 ;
}
static int
F_65 ( struct V_23 * V_24 ,
struct V_224 * V_225 )
{
int V_14 ;
if ( V_225 -> V_251 )
V_14 = F_62 ( V_24 , V_225 ) ;
else if ( V_225 -> V_235 > V_252 )
V_14 = F_64 ( V_24 , V_225 ) ;
else
V_14 = F_63 ( V_24 , V_225 ) ;
return V_14 ;
}
int
F_66 ( struct V_11 * V_12 , char * V_253 ,
int V_254 )
{
union {
T_3 V_255 ;
T_2 V_256 [ 4 ] ;
} V_257 ;
char V_258 [ 32 ] ;
V_257 . V_255 = V_12 -> V_259 ;
sprintf ( V_258 , L_41 , V_257 . V_256 [ 2 ] , V_257 . V_256 [ 1 ] , V_257 . V_256 [ 0 ] , V_257 . V_256 [ 3 ] ) ;
snprintf ( V_253 , V_254 , V_260 , V_258 ) ;
F_4 ( V_12 -> V_4 , L_42 , V_253 ) ;
return 0 ;
}
int F_67 ( struct V_23 * V_24 , const T_2 * V_246 ,
int V_235 , T_2 V_233 ,
const T_2 * V_261 , int V_262 )
{
struct V_224 V_225 ;
memset ( & V_225 , 0 , sizeof( struct V_224 ) ) ;
V_225 . V_235 = V_235 ;
if ( ! V_262 ) {
V_225 . V_233 = V_233 ;
if ( V_235 )
memcpy ( V_225 . V_237 , V_246 , V_235 ) ;
if ( V_261 )
memcpy ( V_225 . V_261 , V_261 , V_10 ) ;
} else {
V_225 . V_234 = true ;
if ( V_261 )
memcpy ( V_225 . V_261 , V_261 , V_10 ) ;
}
return F_65 ( V_24 , & V_225 ) ;
}
int
F_68 ( struct V_23 * V_24 )
{
struct V_263 V_264 ;
memset ( & V_264 , 0 , sizeof( struct V_265 ) ) ;
if ( F_32 ( V_24 , V_266 ,
V_102 , 0 , & V_264 ) )
return - 1 ;
return 0 ;
}
int
F_69 ( struct V_23 * V_24 ,
struct V_267 * log )
{
return F_32 ( V_24 , V_268 ,
V_102 , 0 , log ) ;
}
static int F_70 ( struct V_23 * V_24 ,
struct V_269 * V_270 ,
T_1 V_88 )
{
T_1 V_271 ;
switch ( F_30 ( V_270 -> type ) ) {
case V_272 :
V_271 = V_273 ;
break;
case V_274 :
V_271 = V_275 ;
break;
case V_276 :
V_271 = V_277 ;
break;
case V_278 :
V_271 = V_279 ;
break;
case V_280 :
V_271 = V_281 ;
break;
default:
return - 1 ;
}
return F_32 ( V_24 , V_271 , V_88 , 0 , V_270 ) ;
}
int
F_71 ( struct V_23 * V_24 , T_3 V_282 ,
T_3 V_283 , T_3 V_284 )
{
struct V_269 V_270 ;
V_270 . type = F_31 ( V_282 ) ;
V_270 . V_285 = F_31 ( V_283 ) ;
V_270 . V_286 = F_31 ( V_284 ) ;
return F_70 ( V_24 , & V_270 , V_36 ) ;
}
int
F_72 ( struct V_23 * V_24 , T_3 V_282 ,
T_3 V_283 , T_3 * V_286 )
{
int V_26 ;
struct V_269 V_270 ;
V_270 . type = F_31 ( V_282 ) ;
V_270 . V_285 = F_31 ( V_283 ) ;
V_26 = F_70 ( V_24 , & V_270 , V_102 ) ;
if ( V_26 )
goto V_74;
* V_286 = F_30 ( V_270 . V_286 ) ;
V_74:
return V_26 ;
}
int
F_73 ( struct V_23 * V_24 , T_1 V_285 , T_1 V_287 ,
T_2 * V_286 )
{
int V_26 ;
struct V_288 V_289 ;
V_289 . V_285 = F_57 ( ( T_1 ) V_285 ) ;
V_289 . V_290 = F_57 ( ( T_1 ) V_287 ) ;
V_26 = F_32 ( V_24 , V_291 ,
V_102 , 0 , & V_289 ) ;
if ( ! V_26 )
memcpy ( V_286 , V_289 . V_286 , V_292 ) ;
return V_26 ;
}
static int
F_74 ( struct V_23 * V_24 , T_2 * V_209 ,
T_1 V_210 )
{
int V_26 = 0 ;
struct V_293 * V_294 ;
const T_2 V_295 [] = { 0x00 , 0x50 , 0xf2 , 0x01 } ;
const T_2 V_296 [] = { 0x00 , 0x50 , 0xf2 , 0x04 } ;
if ( ! V_210 ) {
V_24 -> V_297 = 0 ;
V_24 -> V_298 . V_299 = false ;
return 0 ;
} else if ( ! V_209 ) {
return - 1 ;
}
V_294 = (struct V_293 * ) V_209 ;
if ( ( ( V_294 -> V_300 == V_213 ) &&
( ! memcmp ( V_294 -> V_301 , V_295 , sizeof( V_295 ) ) ) ) ||
( V_294 -> V_300 == V_215 ) ) {
V_26 = F_59 ( V_24 , V_209 , V_210 ) ;
V_24 -> V_298 . V_299 = false ;
return V_26 ;
} else if ( V_294 -> V_300 == V_219 ) {
V_26 = F_60 ( V_24 , V_209 , V_210 ) ;
return V_26 ;
}
if ( V_210 < ( sizeof( V_24 -> V_302 ) - V_24 -> V_297 ) ) {
V_294 = (struct V_293 * ) V_209 ;
if ( ( V_294 -> V_300 == V_303 ) &&
( ! memcmp ( V_294 -> V_301 , V_296 , sizeof( V_296 ) ) ) ) {
V_24 -> V_298 . V_299 = true ;
F_4 ( V_24 -> V_12 -> V_4 ,
L_43 ) ;
V_26 = F_61 ( V_24 , V_209 , V_210 ) ;
}
memcpy ( V_24 -> V_302 + V_24 -> V_297 , V_209 ,
V_210 ) ;
V_24 -> V_297 += V_210 ;
} else {
V_26 = - 1 ;
}
return V_26 ;
}
static int F_75 ( struct V_23 * V_24 ,
struct V_304 * V_305 ,
T_1 V_88 )
{
struct V_11 * V_12 = V_24 -> V_12 ;
switch ( V_305 -> type ) {
case V_306 :
if ( V_88 == V_102 ) {
V_305 -> V_307 = V_24 -> V_212 ;
memcpy ( V_305 -> V_308 , V_24 -> V_211 , V_305 -> V_307 ) ;
} else {
F_74 ( V_24 , V_305 -> V_308 ,
( T_1 ) V_305 -> V_307 ) ;
}
break;
case V_309 :
memset ( V_12 -> V_310 , 0 , sizeof( V_12 -> V_310 ) ) ;
if ( V_305 -> V_307 > V_311 ) {
V_12 -> V_312 = 0 ;
F_13 ( V_12 -> V_4 , L_44 ) ;
return - 1 ;
} else {
memcpy ( V_12 -> V_310 , V_305 -> V_308 ,
V_305 -> V_307 ) ;
V_12 -> V_312 = V_305 -> V_307 ;
}
break;
default:
F_13 ( V_12 -> V_4 , L_45 ) ;
return - 1 ;
}
return 0 ;
}
int
F_76 ( struct V_23 * V_24 , T_2 * V_313 , int V_210 )
{
struct V_304 V_305 ;
if ( V_210 > V_314 )
return - V_315 ;
V_305 . type = V_306 ;
V_305 . V_307 = V_210 ;
memcpy ( V_305 . V_308 , V_313 , V_210 ) ;
if ( F_75 ( V_24 , & V_305 , V_36 ) )
return - V_315 ;
return 0 ;
}
