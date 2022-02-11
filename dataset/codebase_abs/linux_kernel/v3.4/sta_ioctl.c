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
T_2 * V_38 , T_3 V_39 , T_2 * V_40 ,
T_4 V_41 , T_1 V_42 ,
T_1 V_43 , T_2 V_44 ,
struct V_45 * V_46 )
{
int V_26 ;
memcpy ( V_46 -> V_47 , V_38 , V_10 ) ;
V_46 -> V_39 = V_39 ;
V_46 -> V_48 = V_40 ;
V_46 -> V_49 = V_41 ;
V_46 -> V_42 = V_42 ;
V_46 -> V_43 = V_43 ;
V_46 -> V_50 = V_44 ;
if ( V_46 -> V_43 & V_51 ) {
F_4 ( V_24 -> V_12 -> V_4 , L_7 ) ;
V_46 -> V_52 = V_53 ;
} else {
V_46 -> V_52 = V_54 ;
}
if ( V_46 -> V_43 & V_55 )
V_46 -> V_56 = V_57 ;
else
V_46 -> V_56 = V_58 ;
V_26 = F_12 ( V_24 -> V_12 , V_46 ,
V_40 , V_41 ) ;
return V_26 ;
}
int F_13 ( struct V_23 * V_24 , struct V_59 * V_60 ,
struct V_61 * V_62 )
{
int V_26 ;
struct V_11 * V_12 = V_24 -> V_12 ;
struct V_45 * V_46 = NULL ;
T_2 * V_63 = NULL ;
V_24 -> V_64 = false ;
if ( V_60 ) {
V_46 = F_14 ( sizeof( struct V_45 ) ,
V_65 ) ;
if ( ! V_46 ) {
F_15 ( V_24 -> V_12 -> V_4 , L_8 ) ;
return - V_66 ;
}
V_63 = F_16 ( V_60 -> V_67 ,
V_60 -> V_68 , V_65 ) ;
if ( ! V_63 ) {
F_17 ( V_46 ) ;
F_15 ( V_24 -> V_12 -> V_4 , L_9 ) ;
return - V_66 ;
}
V_26 = F_11 ( V_24 , V_60 -> V_38 , V_60 -> signal ,
V_63 , V_60 -> V_68 ,
V_60 -> V_69 ,
V_60 -> V_70 ,
* ( T_2 * ) V_60 -> V_24 , V_46 ) ;
if ( V_26 )
goto V_71;
}
if ( V_24 -> V_56 == V_58 ) {
V_26 = F_18 ( V_24 , NULL ) ;
if ( V_26 )
goto V_71;
V_26 = F_19 ( V_24 , V_46 ) ;
if ( V_26 )
goto V_71;
F_4 ( V_12 -> V_4 , L_10
L_11 ) ;
if ( ! F_20 ( V_24 -> V_72 ) )
F_21 ( V_24 -> V_72 , V_12 ) ;
if ( F_22 ( V_24 -> V_72 ) )
F_23 ( V_24 -> V_72 ) ;
V_24 -> V_73 = 0 ;
V_26 = F_24 ( V_24 , V_46 ) ;
if ( V_26 == V_74 &&
V_24 -> V_75 . V_76 &&
V_24 -> V_75 . V_77 ) {
V_24 -> V_75 . V_78 =
V_79 ;
V_26 = F_24 ( V_24 , V_46 ) ;
}
if ( V_60 )
F_25 ( V_60 ) ;
} else {
if ( V_46 && V_46 -> V_80 . V_81 &&
( ! F_26 ( & V_24 -> V_82 . V_83 .
V_80 , & V_46 -> V_80 ) ) ) {
F_17 ( V_46 ) ;
F_17 ( V_63 ) ;
return 0 ;
}
F_4 ( V_12 -> V_4 , L_12 ) ;
V_26 = F_18 ( V_24 , NULL ) ;
if ( V_26 )
goto V_71;
V_24 -> V_84 = false ;
V_26 = F_19 ( V_24 , V_46 ) ;
if ( ! F_20 ( V_24 -> V_72 ) )
F_21 ( V_24 -> V_72 , V_12 ) ;
if ( F_22 ( V_24 -> V_72 ) )
F_23 ( V_24 -> V_72 ) ;
if ( ! V_26 ) {
F_4 ( V_12 -> V_4 , L_13
L_14 ) ;
V_26 = F_27 ( V_24 , V_46 ) ;
if ( V_60 )
F_25 ( V_60 ) ;
} else {
F_4 ( V_12 -> V_4 , L_15
L_16 ,
V_62 -> V_80 ) ;
V_26 = F_28 ( V_24 , V_62 ) ;
}
}
V_71:
F_17 ( V_46 ) ;
F_17 ( V_63 ) ;
return V_26 ;
}
static int F_29 ( struct V_23 * V_24 , T_1 V_85 ,
int V_86 , struct V_87 * V_88 )
{
struct V_11 * V_12 = V_24 -> V_12 ;
int V_14 = 0 ;
T_5 V_89 = 0 ;
if ( ! V_88 )
return - V_66 ;
switch ( V_85 ) {
case V_36 :
if ( V_12 -> V_90 ) {
F_4 ( V_12 -> V_4 , L_17
L_18 ) ;
V_14 = - 1 ;
break;
}
if ( V_88 -> V_91 ) {
if ( V_88 -> V_92 == V_93 ) {
if ( ! V_12 -> V_94 )
break;
V_89 = F_30 ( V_12 -> V_88
. V_92 ) ;
V_12 -> V_88 . V_92 =
F_31 ( V_88 -> V_92 ) ;
} else if ( V_88 -> V_92 ) {
V_12 -> V_88 . V_92 =
F_31 ( V_88 -> V_92 ) ;
V_12 -> V_88 . V_95 = ( T_2 ) V_88 -> V_95 ;
if ( V_88 -> V_96 )
V_12 -> V_88 . V_96 = ( T_2 ) V_88 -> V_96 ;
} else if ( V_12 -> V_88 . V_92
== F_31 ( V_93 ) ) {
V_14 = - 1 ;
break;
}
if ( V_86 == V_97 )
V_14 = F_32 ( V_24 ,
V_98 ,
V_36 , 0 ,
& V_12 -> V_88 ) ;
else
V_14 = F_10 ( V_24 ,
V_98 ,
V_36 , 0 ,
& V_12 -> V_88 ) ;
if ( V_88 -> V_92 == V_93 )
V_12 -> V_88 . V_92 =
F_31 ( V_89 ) ;
} else {
V_12 -> V_88 . V_92 =
F_31 ( V_88 -> V_92 ) ;
V_12 -> V_88 . V_95 = ( T_2 ) V_88 -> V_95 ;
V_12 -> V_88 . V_96 = ( T_2 ) V_88 -> V_96 ;
}
break;
case V_99 :
V_88 -> V_92 = F_30 ( V_12 -> V_88 . V_92 ) ;
V_88 -> V_95 = V_12 -> V_88 . V_95 ;
V_88 -> V_96 = V_12 -> V_88 . V_96 ;
break;
default:
V_14 = - 1 ;
break;
}
return V_14 ;
}
int F_33 ( struct V_23 * V_24 , int V_86 )
{
struct V_87 V_100 ;
V_100 . V_92 = V_93 ;
V_100 . V_91 = true ;
return F_29 ( V_24 , V_36 ,
V_86 , & V_100 ) ;
}
int F_34 ( struct V_11 * V_12 )
{
struct V_87 V_100 ;
if ( V_12 -> V_101 ) {
F_4 ( V_12 -> V_4 , L_19 ) ;
return true ;
}
V_12 -> V_102 = false ;
memset ( & V_100 , 0 , sizeof( struct V_87 ) ) ;
V_100 . V_91 = true ;
if ( F_29 ( F_35 ( V_12 ,
V_103 ) ,
V_36 , V_97 ,
& V_100 ) ) {
F_15 ( V_12 -> V_4 , L_20 ) ;
return false ;
}
F_7 ( V_12 -> V_104 ,
V_12 -> V_102 ) ;
return true ;
}
int F_36 ( struct V_23 * V_24 ,
struct V_105 * V_106 )
{
struct V_11 * V_12 = V_24 -> V_12 ;
struct V_45 * V_46 ;
if ( ! V_106 )
return - 1 ;
V_46 = & V_24 -> V_82 . V_83 ;
V_106 -> V_56 = V_24 -> V_56 ;
memcpy ( & V_106 -> V_80 , & V_46 -> V_80 , sizeof( struct V_61 ) ) ;
memcpy ( & V_106 -> V_38 , & V_46 -> V_47 , V_10 ) ;
V_106 -> V_107 = V_46 -> V_108 ;
V_106 -> V_109 = V_12 -> V_109 ;
V_106 -> V_110 = V_24 -> V_110 ;
V_106 -> V_111 = V_24 -> V_112 ;
V_106 -> V_113 = V_24 -> V_114 ;
V_106 -> V_115 = V_24 -> V_115 ;
V_106 -> V_116 = V_24 -> V_116 ;
if ( V_24 -> V_75 . V_77 )
V_106 -> V_117 = true ;
else
V_106 -> V_117 = false ;
V_106 -> V_94 = V_12 -> V_94 ;
V_106 -> V_118 = V_12 -> V_118 ;
return 0 ;
}
int F_37 ( struct V_23 * V_24 )
{
struct V_119 V_120 ;
V_120 . V_120 = V_121 ;
return F_32 ( V_24 , V_122 ,
V_123 , V_124 , & V_120 ) ;
}
int F_38 ( struct V_23 * V_24 ,
struct V_125 * V_126 )
{
struct V_11 * V_12 = V_24 -> V_12 ;
struct V_125 * V_127 = NULL ;
if ( ! V_126 )
return - 1 ;
if ( ! V_126 -> V_108 && ! V_126 -> V_128 )
return - 1 ;
if ( V_12 -> V_129 & V_130 )
V_12 -> V_129 = V_131 | V_132 | V_133 ;
else if ( V_12 -> V_129 & V_134 )
V_12 -> V_129 = V_131 | V_132 ;
if ( V_126 -> V_108 ) {
if ( V_126 -> V_108 <= V_135 )
V_127 = F_39 ( V_24 , 0 , ( T_1 ) V_126 -> V_108 , 0 ) ;
if ( ! V_127 ) {
V_127 = F_39 ( V_24 , V_134 ,
( T_1 ) V_126 -> V_108 , 0 ) ;
if ( V_127 ) {
if ( V_12 -> V_136 )
V_12 -> V_129 = V_134
| V_130 ;
else
V_12 -> V_129 = V_134 ;
}
}
} else {
if ( V_126 -> V_128 <= V_137 )
V_127 = F_39 ( V_24 , 0 , 0 , V_126 -> V_128 ) ;
if ( ! V_127 ) {
V_127 = F_39 ( V_24 , V_134 , 0 , V_126 -> V_128 ) ;
if ( V_127 ) {
if ( V_12 -> V_136 )
V_12 -> V_129 = V_134
| V_130 ;
else
V_12 -> V_129 = V_134 ;
}
}
}
if ( ! V_127 || ! V_127 -> V_108 ) {
F_15 ( V_12 -> V_4 , L_21 ) ;
return - 1 ;
}
V_24 -> V_138 = ( T_2 ) V_127 -> V_108 ;
V_126 -> V_108 = V_127 -> V_108 ;
V_126 -> V_128 = V_127 -> V_128 ;
return 0 ;
}
static int F_40 ( struct V_23 * V_24 ,
T_1 V_85 , T_1 * V_108 )
{
if ( V_85 == V_99 ) {
if ( ! V_24 -> V_110 ) {
* V_108 = V_24 -> V_138 ;
return 0 ;
}
} else {
V_24 -> V_138 = ( T_2 ) * V_108 ;
}
return F_32 ( V_24 , V_139 ,
V_85 , 0 , V_108 ) ;
}
int
F_41 ( struct V_23 * V_24 , T_1 V_108 )
{
int V_26 ;
struct V_105 V_140 ;
struct V_141 V_142 ;
T_1 V_143 = 0 ;
struct V_59 * V_60 = NULL ;
struct V_144 * V_126 ;
enum V_145 V_44 ;
memset ( & V_140 , 0 , sizeof( V_140 ) ) ;
if ( F_36 ( V_24 , & V_140 ) )
return - 1 ;
V_26 = F_40 ( V_24 , V_99 ,
& V_143 ) ;
if ( V_143 == V_108 ) {
V_26 = 0 ;
goto V_71;
}
F_4 ( V_24 -> V_12 -> V_4 , L_22 ,
V_143 , V_108 ) ;
if ( ! V_140 . V_110 ) {
V_26 = 0 ;
goto V_71;
}
memset ( & V_142 , 0 , V_10 ) ;
V_26 = F_18 ( V_24 , V_142 . V_38 ) ;
V_26 = F_40 ( V_24 , V_36 ,
& V_108 ) ;
if ( F_42 ( V_24 , & V_140 . V_80 ) ) {
V_26 = - 1 ;
goto V_71;
}
V_44 = F_43 ( V_24 -> V_82 . V_44 ) ;
V_126 = F_44 ( V_24 -> V_146 -> V_147 ,
F_45 ( V_108 ,
V_44 ) ) ;
V_60 = F_46 ( V_24 -> V_146 -> V_147 , V_126 , V_140 . V_38 ,
V_140 . V_80 . V_80 , V_140 . V_80 . V_81 ,
V_148 , V_148 ) ;
if ( ! V_60 )
F_47 ( V_24 -> V_146 -> V_147 , L_23 ,
V_140 . V_38 ) ;
V_26 = F_13 ( V_24 , V_60 , & V_140 . V_80 ) ;
V_71:
return V_26 ;
}
static int F_48 ( struct V_23 * V_24 ,
struct V_149 * V_150 )
{
V_150 -> V_151 = V_24 -> V_152 ;
return F_32 ( V_24 , V_153 ,
V_99 , 0 , NULL ) ;
}
static int F_49 ( struct V_23 * V_24 ,
struct V_149 * V_150 )
{
T_2 V_154 [ V_155 ] ;
T_2 * V_156 ;
int V_157 , V_26 ;
T_1 V_158 [ V_159 ] ;
T_5 V_5 ;
struct V_11 * V_12 = V_24 -> V_12 ;
if ( V_150 -> V_151 ) {
memset ( V_158 , 0 , sizeof( V_158 ) ) ;
V_158 [ 0 ] = 0x000F ;
V_158 [ 1 ] = 0x00FF ;
for ( V_5 = 0 ; V_5 < F_50 ( V_24 -> V_158 ) - 3 ; V_5 ++ )
V_158 [ V_5 + 2 ] = 0xFFFF ;
V_158 [ 9 ] = 0x3FFF ;
} else {
memset ( V_154 , 0 , sizeof( V_154 ) ) ;
F_51 ( V_24 , V_154 ) ;
V_156 = V_154 ;
for ( V_5 = 0 ; ( V_156 [ V_5 ] && V_5 < V_155 ) ; V_5 ++ ) {
F_4 ( V_12 -> V_4 , L_24 ,
V_156 [ V_5 ] , V_150 -> V_156 ) ;
if ( ( V_156 [ V_5 ] & 0x7f ) == ( V_150 -> V_156 & 0x7f ) )
break;
}
if ( ( V_5 == V_155 ) || ! V_156 [ V_5 ] ) {
F_15 ( V_12 -> V_4 , L_25
L_26 , V_150 -> V_156 ) ;
return - 1 ;
}
memset ( V_158 , 0 , sizeof( V_158 ) ) ;
V_157 = F_52 ( V_150 -> V_156 ) ;
if ( V_157 >= V_160 &&
V_157 <= V_161 ) {
V_158 [ 0 ] = 1 << V_157 ;
} else {
V_157 -= 1 ;
if ( V_157 >= V_162 &&
V_157 <= V_163 )
V_158 [ 1 ] = 1 << ( V_157 -
V_162 ) ;
}
}
V_26 = F_32 ( V_24 , V_164 ,
V_36 , 0 , V_158 ) ;
return V_26 ;
}
static int F_53 ( struct V_23 * V_24 ,
struct V_149 * V_150 )
{
int V_14 ;
if ( ! V_150 )
return - 1 ;
if ( V_150 -> V_85 == V_99 )
V_14 = F_48 ( V_24 , V_150 ) ;
else
V_14 = F_49 ( V_24 , V_150 ) ;
return V_14 ;
}
int F_54 ( struct V_23 * V_24 ,
struct V_149 * V_156 )
{
int V_26 ;
memset ( V_156 , 0 , sizeof( struct V_149 ) ) ;
V_156 -> V_85 = V_99 ;
V_26 = F_53 ( V_24 , V_156 ) ;
if ( ! V_26 ) {
if ( V_156 -> V_151 )
V_156 -> V_156 = F_55 ( V_24 ,
V_24 -> V_165 ,
V_24 -> V_166
) ;
else
V_156 -> V_156 = V_24 -> V_167 ;
} else {
V_26 = - 1 ;
}
return V_26 ;
}
int F_56 ( struct V_23 * V_24 ,
struct V_168 * V_169 )
{
int V_26 ;
struct V_170 * V_171 ;
struct V_172 * V_173 ;
struct V_174 * V_175 ;
T_2 * V_176 ;
T_1 V_177 = 0 ;
if ( ! V_169 -> V_178 ) {
V_177 = ( T_1 ) V_169 -> V_179 ;
if ( ( V_177 < V_24 -> V_114 ) ||
( V_177 > V_24 -> V_112 ) ) {
F_15 ( V_24 -> V_12 -> V_4 , L_27
L_28 ,
V_177 , V_24 -> V_114 ,
V_24 -> V_112 ) ;
return - 1 ;
}
}
V_176 = F_14 ( V_180 , V_65 ) ;
if ( ! V_176 ) {
F_15 ( V_24 -> V_12 -> V_4 , L_29 ,
V_181 ) ;
return - V_66 ;
}
V_171 = (struct V_170 * ) V_176 ;
V_171 -> V_85 = F_57 ( V_36 ) ;
if ( ! V_169 -> V_178 ) {
V_171 -> V_29 = F_31 ( 1 ) ;
V_173 = (struct V_172 * )
( V_176 + sizeof( struct V_170 ) ) ;
V_173 -> type = V_182 ;
V_173 -> V_183 = 4 * sizeof( struct V_174 ) ;
V_175 = (struct V_174 * )
( V_176 + sizeof( struct V_170 )
+ sizeof( struct V_172 ) ) ;
V_175 -> V_184 = 0x00 ;
V_175 -> V_185 = 0x03 ;
V_175 -> V_186 = V_187 ;
V_175 -> V_188 = 0 ;
V_175 -> V_189 = ( V_190 ) V_177 ;
V_175 -> V_191 = ( V_190 ) V_177 ;
V_175 ++ ;
V_175 -> V_184 = 0x00 ;
V_175 -> V_185 = 0x07 ;
V_175 -> V_186 = V_192 ;
V_175 -> V_188 = 0 ;
V_175 -> V_189 = ( V_190 ) V_177 ;
V_175 -> V_191 = ( V_190 ) V_177 ;
V_175 ++ ;
V_175 -> V_184 = 0x00 ;
V_175 -> V_185 = 0x20 ;
V_175 -> V_186 = V_193 ;
V_175 -> V_188 = 0 ;
V_175 -> V_189 = ( V_190 ) V_177 ;
V_175 -> V_191 = ( V_190 ) V_177 ;
V_175 -> V_194 = V_195 ;
V_175 ++ ;
V_175 -> V_184 = 0x00 ;
V_175 -> V_185 = 0x20 ;
V_175 -> V_186 = V_193 ;
V_175 -> V_188 = 0 ;
V_175 -> V_189 = ( V_190 ) V_177 ;
V_175 -> V_191 = ( V_190 ) V_177 ;
V_175 -> V_194 = V_196 ;
}
V_26 = F_32 ( V_24 , V_197 ,
V_36 , 0 , V_176 ) ;
F_17 ( V_176 ) ;
return V_26 ;
}
int F_58 ( struct V_23 * V_24 , T_5 * V_198 )
{
int V_26 ;
struct V_11 * V_12 = V_24 -> V_12 ;
T_1 V_199 ;
if ( * V_198 )
V_12 -> V_198 = V_200 ;
else
V_12 -> V_198 = V_201 ;
V_199 = ( * V_198 ) ? V_202 : V_123 ;
V_26 = F_32 ( V_24 , V_122 ,
V_199 , V_203 , NULL ) ;
if ( ( ! V_26 ) && ( V_199 == V_123 ) )
V_26 = F_10 ( V_24 ,
V_122 ,
V_204 , 0 , NULL ) ;
return V_26 ;
}
static int F_59 ( struct V_23 * V_24 ,
T_2 * V_205 , T_1 V_41 )
{
if ( V_41 ) {
if ( V_41 > sizeof( V_24 -> V_206 ) ) {
F_15 ( V_24 -> V_12 -> V_4 ,
L_30 ) ;
return - 1 ;
}
memcpy ( V_24 -> V_206 , V_205 , V_41 ) ;
V_24 -> V_207 = ( T_2 ) V_41 ;
F_4 ( V_24 -> V_12 -> V_4 , L_31 ,
V_24 -> V_207 , V_24 -> V_206 [ 0 ] ) ;
if ( V_24 -> V_206 [ 0 ] == V_208 ) {
V_24 -> V_75 . V_209 = true ;
} else if ( V_24 -> V_206 [ 0 ] == V_210 ) {
V_24 -> V_75 . V_211 = true ;
} else {
V_24 -> V_75 . V_209 = false ;
V_24 -> V_75 . V_211 = false ;
}
} else {
memset ( V_24 -> V_206 , 0 , sizeof( V_24 -> V_206 ) ) ;
V_24 -> V_207 = 0 ;
F_4 ( V_24 -> V_12 -> V_4 , L_32 ,
V_24 -> V_207 , V_24 -> V_206 [ 0 ] ) ;
V_24 -> V_75 . V_209 = false ;
V_24 -> V_75 . V_211 = false ;
}
return 0 ;
}
static int F_60 ( struct V_23 * V_24 ,
T_2 * V_205 , T_1 V_41 )
{
if ( V_41 ) {
if ( V_41 > sizeof( V_24 -> V_212 ) ) {
F_4 ( V_24 -> V_12 -> V_4 ,
L_33 ) ;
return - 1 ;
}
memcpy ( V_24 -> V_212 , V_205 , V_41 ) ;
V_24 -> V_213 = V_41 ;
F_4 ( V_24 -> V_12 -> V_4 , L_34 ,
V_24 -> V_213 , V_24 -> V_212 [ 0 ] ) ;
if ( V_24 -> V_212 [ 0 ] == V_214 )
V_24 -> V_75 . V_215 = true ;
} else {
memset ( V_24 -> V_212 , 0 , sizeof( V_24 -> V_212 ) ) ;
V_24 -> V_213 = V_41 ;
F_4 ( V_24 -> V_12 -> V_4 ,
L_35 ,
V_24 -> V_213 , V_24 -> V_212 [ 0 ] ) ;
V_24 -> V_75 . V_215 = false ;
}
return 0 ;
}
static int F_61 ( struct V_23 * V_24 ,
struct V_216 * V_217 )
{
return F_32 ( V_24 , V_218 ,
V_36 , V_219 ,
V_217 ) ;
}
static int F_62 ( struct V_23 * V_24 ,
struct V_216 * V_217 )
{
int V_26 ;
struct V_220 * V_221 ;
int V_222 ;
if ( V_24 -> V_223 >= V_224 )
V_24 -> V_223 = 0 ;
V_221 = & V_24 -> V_221 [ V_24 -> V_223 ] ;
V_222 = V_217 -> V_225 ;
if ( V_217 -> V_226 ) {
V_24 -> V_75 . V_77 = 0 ;
} else if ( ! V_217 -> V_227 ) {
V_221 = & V_24 -> V_221 [ V_222 ] ;
if ( ! V_221 -> V_228 ) {
F_15 ( V_24 -> V_12 -> V_4 ,
L_36 ) ;
return - 1 ;
}
V_24 -> V_223 = ( T_1 ) V_222 ;
V_24 -> V_75 . V_77 = 1 ;
} else {
V_221 = & V_24 -> V_221 [ V_222 ] ;
memset ( V_221 , 0 , sizeof( struct V_220 ) ) ;
memcpy ( V_221 -> V_229 ,
V_217 -> V_229 ,
V_217 -> V_227 ) ;
V_221 -> V_225 = V_222 ;
V_221 -> V_228 = V_217 -> V_227 ;
V_24 -> V_75 . V_77 = 1 ;
}
if ( V_221 -> V_228 ) {
V_26 = F_10 ( V_24 ,
V_218 ,
V_36 , 0 , NULL ) ;
if ( V_26 )
return V_26 ;
}
if ( V_24 -> V_75 . V_77 )
V_24 -> V_28 |= V_230 ;
else
V_24 -> V_28 &= ~ V_230 ;
V_26 = F_32 ( V_24 , V_37 ,
V_36 , 0 ,
& V_24 -> V_28 ) ;
return V_26 ;
}
static int F_63 ( struct V_23 * V_24 ,
struct V_216 * V_217 )
{
int V_26 ;
T_2 V_231 = false ;
struct V_232 * V_233 ;
if ( V_217 -> V_227 > V_234 ) {
F_15 ( V_24 -> V_12 -> V_4 , L_37 ) ;
return - 1 ;
}
if ( V_24 -> V_56 == V_57 ) {
V_217 -> V_225 = V_235 ;
V_26 = F_10 ( V_24 ,
V_218 ,
V_36 ,
V_219 , V_217 ) ;
if ( V_26 )
return V_26 ;
V_233 = & V_24 -> V_236 ;
memset ( V_233 , 0 ,
sizeof( struct V_232 ) ) ;
memcpy ( V_233 -> V_237 . V_238 , V_217 -> V_229 ,
V_217 -> V_227 ) ;
memcpy ( & V_233 -> V_237 . V_227 , & V_217 -> V_227 ,
sizeof( V_233 -> V_237 . V_227 ) ) ;
V_233 -> V_237 . V_239
= F_57 ( V_240 ) ;
V_233 -> V_237 . V_241 = F_57 ( V_242 ) ;
V_217 -> V_225 = ~ V_235 ;
}
if ( ! V_217 -> V_225 )
V_217 -> V_225 = V_235 ;
if ( V_231 )
V_26 = F_32 ( V_24 ,
V_218 ,
V_36 ,
! V_219 , V_217 ) ;
else
V_26 = F_32 ( V_24 ,
V_218 ,
V_36 ,
V_219 , V_217 ) ;
return V_26 ;
}
static int
F_64 ( struct V_23 * V_24 ,
struct V_216 * V_217 )
{
int V_14 ;
if ( V_217 -> V_243 )
V_14 = F_61 ( V_24 , V_217 ) ;
else if ( V_217 -> V_227 > V_244 )
V_14 = F_63 ( V_24 , V_217 ) ;
else
V_14 = F_62 ( V_24 , V_217 ) ;
return V_14 ;
}
int
F_65 ( struct V_11 * V_12 , char * V_245 ,
int V_246 )
{
union {
T_5 V_247 ;
T_2 V_248 [ 4 ] ;
} V_249 ;
char V_250 [ 32 ] ;
V_249 . V_247 = V_12 -> V_251 ;
sprintf ( V_250 , L_38 , V_249 . V_248 [ 2 ] , V_249 . V_248 [ 1 ] , V_249 . V_248 [ 0 ] , V_249 . V_248 [ 3 ] ) ;
snprintf ( V_245 , V_246 , V_252 , V_250 ) ;
F_4 ( V_12 -> V_4 , L_39 , V_245 ) ;
return 0 ;
}
int F_66 ( struct V_23 * V_24 ,
struct V_253 * signal )
{
int V_14 ;
signal -> V_254 = V_255 ;
if ( ! V_24 -> V_110 ) {
F_4 ( V_24 -> V_12 -> V_4 ,
L_40 ) ;
return - 1 ;
}
V_14 = F_32 ( V_24 , V_256 ,
V_99 , 0 , signal ) ;
if ( ! V_14 ) {
if ( signal -> V_254 & V_257 )
V_24 -> V_258 = signal -> V_259 ;
if ( signal -> V_254 & V_260 )
V_24 -> V_261 = signal -> V_262 ;
}
return V_14 ;
}
int F_67 ( struct V_23 * V_24 , const T_2 * V_238 ,
int V_227 , T_2 V_225 , int V_263 )
{
struct V_216 V_217 ;
memset ( & V_217 , 0 , sizeof( struct V_216 ) ) ;
V_217 . V_227 = V_227 ;
if ( ! V_263 ) {
V_217 . V_225 = V_225 ;
if ( V_227 )
memcpy ( V_217 . V_229 , V_238 , V_227 ) ;
} else {
V_217 . V_226 = true ;
}
return F_64 ( V_24 , & V_217 ) ;
}
int
F_68 ( struct V_23 * V_24 )
{
struct V_264 V_265 ;
memset ( & V_265 , 0 , sizeof( struct V_266 ) ) ;
if ( F_32 ( V_24 , V_267 ,
V_99 , 0 , & V_265 ) )
return - 1 ;
return 0 ;
}
int
F_69 ( struct V_23 * V_24 ,
struct V_268 * log )
{
return F_32 ( V_24 , V_269 ,
V_99 , 0 , log ) ;
}
static int F_70 ( struct V_23 * V_24 ,
struct V_270 * V_271 ,
T_1 V_85 )
{
T_1 V_272 ;
switch ( F_30 ( V_271 -> type ) ) {
case V_273 :
V_272 = V_274 ;
break;
case V_275 :
V_272 = V_276 ;
break;
case V_277 :
V_272 = V_278 ;
break;
case V_279 :
V_272 = V_280 ;
break;
case V_281 :
V_272 = V_282 ;
break;
default:
return - 1 ;
}
return F_32 ( V_24 , V_272 , V_85 , 0 , V_271 ) ;
}
int
F_71 ( struct V_23 * V_24 , T_5 V_283 ,
T_5 V_284 , T_5 V_285 )
{
struct V_270 V_271 ;
V_271 . type = F_31 ( V_283 ) ;
V_271 . V_286 = F_31 ( V_284 ) ;
V_271 . V_287 = F_31 ( V_285 ) ;
return F_70 ( V_24 , & V_271 , V_36 ) ;
}
int
F_72 ( struct V_23 * V_24 , T_5 V_283 ,
T_5 V_284 , T_5 * V_287 )
{
int V_26 ;
struct V_270 V_271 ;
V_271 . type = F_31 ( V_283 ) ;
V_271 . V_286 = F_31 ( V_284 ) ;
V_26 = F_70 ( V_24 , & V_271 , V_99 ) ;
if ( V_26 )
goto V_71;
* V_287 = F_30 ( V_271 . V_287 ) ;
V_71:
return V_26 ;
}
int
F_73 ( struct V_23 * V_24 , T_1 V_286 , T_1 V_288 ,
T_2 * V_287 )
{
int V_26 ;
struct V_289 V_290 ;
V_290 . V_286 = F_57 ( ( T_1 ) V_286 ) ;
V_290 . V_291 = F_57 ( ( T_1 ) V_288 ) ;
V_26 = F_32 ( V_24 , V_292 ,
V_99 , 0 , & V_290 ) ;
if ( ! V_26 )
memcpy ( V_287 , V_290 . V_287 , V_293 ) ;
return V_26 ;
}
static int
F_74 ( struct V_23 * V_24 , T_2 * V_205 ,
T_1 V_41 )
{
int V_26 = 0 ;
struct V_294 * V_295 ;
const T_2 V_296 [] = { 0x00 , 0x50 , 0xf2 , 0x01 } ;
const T_2 V_297 [] = { 0x00 , 0x50 , 0xf2 , 0x04 } ;
if ( ! V_41 ) {
V_24 -> V_298 = 0 ;
V_24 -> V_299 . V_300 = false ;
return 0 ;
} else if ( ! V_205 ) {
return - 1 ;
}
V_295 = (struct V_294 * ) V_205 ;
if ( ( ( V_295 -> V_301 == V_208 ) &&
( ! memcmp ( V_295 -> V_302 , V_296 , sizeof( V_296 ) ) ) ) ||
( V_295 -> V_301 == V_210 ) ) {
V_26 = F_59 ( V_24 , V_205 , V_41 ) ;
V_24 -> V_299 . V_300 = false ;
return V_26 ;
} else if ( V_295 -> V_301 == V_214 ) {
V_26 = F_60 ( V_24 , V_205 , V_41 ) ;
return V_26 ;
}
if ( V_41 < ( sizeof( V_24 -> V_303 ) - V_24 -> V_298 ) ) {
V_295 = (struct V_294 * ) V_205 ;
if ( ( V_295 -> V_301 == V_304 ) &&
( ! memcmp ( V_295 -> V_302 , V_297 , sizeof( V_297 ) ) ) ) {
V_24 -> V_299 . V_300 = true ;
F_4 ( V_24 -> V_12 -> V_4 ,
L_41 ) ;
}
memcpy ( V_24 -> V_303 + V_24 -> V_298 , V_205 ,
V_41 ) ;
V_24 -> V_298 += V_41 ;
} else {
V_26 = - 1 ;
}
return V_26 ;
}
static int F_75 ( struct V_23 * V_24 ,
struct V_305 * V_306 ,
T_1 V_85 )
{
struct V_11 * V_12 = V_24 -> V_12 ;
switch ( V_306 -> type ) {
case V_307 :
if ( V_85 == V_99 ) {
V_306 -> V_308 = V_24 -> V_207 ;
memcpy ( V_306 -> V_309 , V_24 -> V_206 , V_306 -> V_308 ) ;
} else {
F_74 ( V_24 , V_306 -> V_309 ,
( T_1 ) V_306 -> V_308 ) ;
}
break;
case V_310 :
memset ( V_12 -> V_311 , 0 , sizeof( V_12 -> V_311 ) ) ;
if ( V_306 -> V_308 > V_312 ) {
V_12 -> V_313 = 0 ;
F_15 ( V_12 -> V_4 , L_42 ) ;
return - 1 ;
} else {
memcpy ( V_12 -> V_311 , V_306 -> V_309 ,
V_306 -> V_308 ) ;
V_12 -> V_313 = V_306 -> V_308 ;
}
break;
default:
F_15 ( V_12 -> V_4 , L_43 ) ;
return - 1 ;
}
return 0 ;
}
int
F_76 ( struct V_23 * V_24 , T_2 * V_314 , int V_41 )
{
struct V_305 V_306 ;
if ( V_41 > V_315 )
return - V_316 ;
V_306 . type = V_307 ;
V_306 . V_308 = V_41 ;
memcpy ( V_306 . V_309 , V_314 , V_41 ) ;
if ( F_75 ( V_24 , & V_306 , V_36 ) )
return - V_316 ;
return 0 ;
}
