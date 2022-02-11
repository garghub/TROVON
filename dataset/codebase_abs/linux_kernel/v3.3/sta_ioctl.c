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
if ( V_60 )
F_25 ( V_60 ) ;
} else {
if ( V_46 && V_46 -> V_74 . V_75 &&
( ! F_26
( & V_24 -> V_76 . V_77 . V_74 ,
& V_46 -> V_74 ) ) ) {
F_17 ( V_46 ) ;
F_17 ( V_63 ) ;
return 0 ;
}
F_4 ( V_12 -> V_4 , L_12 ) ;
V_26 = F_18 ( V_24 , NULL ) ;
if ( V_26 )
goto V_71;
V_24 -> V_78 = false ;
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
V_62 -> V_74 ) ;
V_26 = F_28 ( V_24 , V_62 ) ;
}
}
V_71:
F_17 ( V_46 ) ;
F_17 ( V_63 ) ;
return V_26 ;
}
static int F_29 ( struct V_23 * V_24 , T_1 V_79 ,
int V_80 , struct V_81 * V_82 )
{
struct V_11 * V_12 = V_24 -> V_12 ;
int V_14 = 0 ;
T_5 V_83 = 0 ;
if ( ! V_82 )
return - V_66 ;
switch ( V_79 ) {
case V_36 :
if ( V_12 -> V_84 ) {
F_4 ( V_12 -> V_4 , L_17
L_18 ) ;
V_14 = - 1 ;
break;
}
if ( V_82 -> V_85 ) {
if ( V_82 -> V_86 == V_87 ) {
if ( ! V_12 -> V_88 )
break;
V_83 = F_30 ( V_12 -> V_82
. V_86 ) ;
V_12 -> V_82 . V_86 =
F_31 ( V_82 -> V_86 ) ;
} else if ( V_82 -> V_86 ) {
V_12 -> V_82 . V_86 =
F_31 ( V_82 -> V_86 ) ;
V_12 -> V_82 . V_89 = ( T_2 ) V_82 -> V_89 ;
if ( V_82 -> V_90 )
V_12 -> V_82 . V_90 = ( T_2 ) V_82 -> V_90 ;
} else if ( V_12 -> V_82 . V_86 ==
F_31 (
V_87 ) ) {
V_14 = - 1 ;
break;
}
if ( V_80 == V_91 )
V_14 = F_32 ( V_24 ,
V_92 ,
V_36 , 0 ,
& V_12 -> V_82 ) ;
else
V_14 = F_10 ( V_24 ,
V_92 ,
V_36 , 0 ,
& V_12 -> V_82 ) ;
if ( V_82 -> V_86 == V_87 )
V_12 -> V_82 . V_86 =
F_31 ( V_83 ) ;
} else {
V_12 -> V_82 . V_86 =
F_31 ( V_82 -> V_86 ) ;
V_12 -> V_82 . V_89 = ( T_2 ) V_82 -> V_89 ;
V_12 -> V_82 . V_90 = ( T_2 ) V_82 -> V_90 ;
}
break;
case V_93 :
V_82 -> V_86 = F_30 ( V_12 -> V_82 . V_86 ) ;
V_82 -> V_89 = V_12 -> V_82 . V_89 ;
V_82 -> V_90 = V_12 -> V_82 . V_90 ;
break;
default:
V_14 = - 1 ;
break;
}
return V_14 ;
}
int F_33 ( struct V_23 * V_24 , int V_80 )
{
struct V_81 V_94 ;
V_94 . V_86 = V_87 ;
V_94 . V_85 = true ;
return F_29 ( V_24 , V_36 ,
V_80 , & V_94 ) ;
}
int F_34 ( struct V_11 * V_12 )
{
struct V_81 V_94 ;
if ( V_12 -> V_95 ) {
F_4 ( V_12 -> V_4 , L_19 ) ;
return true ;
}
V_12 -> V_96 = false ;
memset ( & V_94 , 0 , sizeof( struct V_97 ) ) ;
V_94 . V_85 = true ;
if ( F_29 ( F_35 ( V_12 ,
V_98 ) ,
V_36 , V_91 ,
& V_94 ) ) {
F_15 ( V_12 -> V_4 , L_20 ) ;
return false ;
}
F_7 ( V_12 -> V_99 ,
V_12 -> V_96 ) ;
return true ;
}
int F_36 ( struct V_23 * V_24 ,
struct V_100 * V_101 )
{
struct V_11 * V_12 = V_24 -> V_12 ;
struct V_45 * V_46 ;
if ( ! V_101 )
return - 1 ;
V_46 = & V_24 -> V_76 . V_77 ;
V_101 -> V_56 = V_24 -> V_56 ;
memcpy ( & V_101 -> V_74 , & V_46 -> V_74 ,
sizeof( struct V_61 ) ) ;
memcpy ( & V_101 -> V_38 , & V_46 -> V_47 , V_10 ) ;
V_101 -> V_102 = V_46 -> V_103 ;
V_101 -> V_104 = V_12 -> V_104 ;
V_101 -> V_105 = V_24 -> V_105 ;
V_101 -> V_106 = V_24 -> V_107 ;
V_101 -> V_108 = V_24 -> V_109 ;
V_101 -> V_110 = V_24 -> V_110 ;
V_101 -> V_111 = V_24 -> V_111 ;
if ( V_24 -> V_112 . V_113 == V_114 )
V_101 -> V_113 = true ;
else
V_101 -> V_113 = false ;
V_101 -> V_88 = V_12 -> V_88 ;
V_101 -> V_115 = V_12 -> V_115 ;
return 0 ;
}
int F_37 ( struct V_23 * V_24 )
{
struct V_116 V_117 ;
V_117 . V_117 = V_118 ;
return F_32 ( V_24 , V_119 ,
V_120 , V_121 , & V_117 ) ;
}
int F_38 ( struct V_23 * V_24 ,
struct V_122 * V_123 )
{
struct V_11 * V_12 = V_24 -> V_12 ;
struct V_122 * V_124 = NULL ;
if ( ! V_123 )
return - 1 ;
if ( ! V_123 -> V_103 && ! V_123 -> V_125 )
return - 1 ;
if ( V_12 -> V_126 & V_127 )
V_12 -> V_126 = V_128 | V_129 | V_130 ;
else if ( V_12 -> V_126 & V_131 )
V_12 -> V_126 = V_128 | V_129 ;
if ( V_123 -> V_103 ) {
if ( V_123 -> V_103 <= V_132 )
V_124 = F_39
( V_24 , 0 , ( T_1 ) V_123 -> V_103 ) ;
if ( ! V_124 ) {
V_124 = F_39
( V_24 , V_131 , ( T_1 ) V_123 -> V_103 ) ;
if ( V_124 ) {
if ( V_12 -> V_133 )
V_12 -> V_126 = V_131
| V_127 ;
else
V_12 -> V_126 = V_131 ;
}
}
} else {
if ( V_123 -> V_125 <= V_134 )
V_124 = F_40 (
V_24 , 0 , V_123 -> V_125 ) ;
if ( ! V_124 ) {
V_124 = F_40
( V_24 , V_131 , V_123 -> V_125 ) ;
if ( V_124 ) {
if ( V_12 -> V_133 )
V_12 -> V_126 = V_131
| V_127 ;
else
V_12 -> V_126 = V_131 ;
}
}
}
if ( ! V_124 || ! V_124 -> V_103 ) {
F_15 ( V_12 -> V_4 , L_21 ) ;
return - 1 ;
}
V_24 -> V_135 = ( T_2 ) V_124 -> V_103 ;
V_123 -> V_103 = V_124 -> V_103 ;
V_123 -> V_125 = V_124 -> V_125 ;
return 0 ;
}
static int F_41 ( struct V_23 * V_24 ,
T_1 V_79 , T_1 * V_103 )
{
if ( V_79 == V_93 ) {
if ( ! V_24 -> V_105 ) {
* V_103 = V_24 -> V_135 ;
return 0 ;
}
} else {
V_24 -> V_135 = ( T_2 ) * V_103 ;
}
return F_32 ( V_24 , V_136 ,
V_79 , 0 , V_103 ) ;
}
int
F_42 ( struct V_23 * V_24 , int V_103 )
{
int V_26 ;
struct V_100 V_137 ;
struct V_138 V_139 ;
T_1 V_140 = 0 ;
struct V_59 * V_60 = NULL ;
struct V_141 * V_123 ;
enum V_142 V_44 ;
memset ( & V_137 , 0 , sizeof( V_137 ) ) ;
if ( F_36 ( V_24 , & V_137 ) )
return - 1 ;
V_26 = F_41 ( V_24 , V_93 ,
& V_140 ) ;
if ( V_140 == V_103 ) {
V_26 = 0 ;
goto V_71;
}
F_4 ( V_24 -> V_12 -> V_4 , L_22 ,
V_140 , V_103 ) ;
if ( ! V_137 . V_105 ) {
V_26 = 0 ;
goto V_71;
}
memset ( & V_139 , 0 , V_10 ) ;
V_26 = F_18 ( V_24 , V_139 . V_38 ) ;
V_26 = F_41 ( V_24 , V_36 ,
( T_1 * ) & V_103 ) ;
if ( F_43 ( V_24 , & V_137 . V_74 ) ) {
V_26 = - 1 ;
goto V_71;
}
V_44 = F_44 ( V_24 -> V_76 . V_44 ) ;
V_123 = F_45 ( V_24 -> V_143 -> V_144 ,
F_46 ( V_103 , V_44 ) ) ;
V_60 = F_47 ( V_24 -> V_143 -> V_144 , V_123 , V_137 . V_38 ,
V_137 . V_74 . V_74 , V_137 . V_74 . V_75 ,
V_145 , V_145 ) ;
if ( ! V_60 )
F_48 ( V_24 -> V_143 -> V_144 , L_23 ,
V_137 . V_38 ) ;
V_26 = F_13 ( V_24 , V_60 , & V_137 . V_74 ) ;
V_71:
return V_26 ;
}
static int F_49 ( struct V_23 * V_24 ,
struct V_146 * V_147 )
{
V_147 -> V_148 = V_24 -> V_149 ;
return F_32 ( V_24 , V_150 ,
V_93 , 0 , NULL ) ;
}
static int F_50 ( struct V_23 * V_24 ,
struct V_146 * V_147 )
{
T_2 V_151 [ V_152 ] ;
T_2 * V_153 ;
int V_154 , V_26 ;
T_1 V_155 [ V_156 ] ;
T_5 V_5 ;
struct V_11 * V_12 = V_24 -> V_12 ;
if ( V_147 -> V_148 ) {
memset ( V_155 , 0 , sizeof( V_155 ) ) ;
V_155 [ 0 ] = 0x000F ;
V_155 [ 1 ] = 0x00FF ;
for ( V_5 = 0 ; V_5 < F_51 ( V_24 -> V_155 ) - 3 ; V_5 ++ )
V_155 [ V_5 + 2 ] = 0xFFFF ;
V_155 [ 9 ] = 0x3FFF ;
} else {
memset ( V_151 , 0 , sizeof( V_151 ) ) ;
F_52 ( V_24 , V_151 ) ;
V_153 = V_151 ;
for ( V_5 = 0 ; ( V_153 [ V_5 ] && V_5 < V_152 ) ; V_5 ++ ) {
F_4 ( V_12 -> V_4 , L_24 ,
V_153 [ V_5 ] , V_147 -> V_153 ) ;
if ( ( V_153 [ V_5 ] & 0x7f ) == ( V_147 -> V_153 & 0x7f ) )
break;
}
if ( ( V_5 == V_152 ) || ! V_153 [ V_5 ] ) {
F_15 ( V_12 -> V_4 , L_25
L_26 , V_147 -> V_153 ) ;
return - 1 ;
}
memset ( V_155 , 0 , sizeof( V_155 ) ) ;
V_154 = F_53 ( V_147 -> V_153 ) ;
if ( V_154 >= V_157 &&
V_154 <= V_158 ) {
V_155 [ 0 ] = 1 << V_154 ;
} else {
V_154 -= 1 ;
if ( V_154 >= V_159 &&
V_154 <= V_160 )
V_155 [ 1 ] = 1 << ( V_154 -
V_159 ) ;
}
}
V_26 = F_32 ( V_24 , V_161 ,
V_36 , 0 , V_155 ) ;
return V_26 ;
}
static int F_54 ( struct V_23 * V_24 ,
struct V_146 * V_147 )
{
int V_14 ;
if ( ! V_147 )
return - 1 ;
if ( V_147 -> V_79 == V_93 )
V_14 = F_49 ( V_24 , V_147 ) ;
else
V_14 = F_50 ( V_24 , V_147 ) ;
return V_14 ;
}
int F_55 ( struct V_23 * V_24 ,
struct V_146 * V_153 )
{
int V_26 ;
memset ( V_153 , 0 , sizeof( struct V_146 ) ) ;
V_153 -> V_79 = V_93 ;
V_26 = F_54 ( V_24 , V_153 ) ;
if ( ! V_26 ) {
if ( V_153 -> V_148 )
V_153 -> V_153 = F_56 ( V_24 ,
V_24 -> V_162 , V_24 -> V_163 ) ;
else
V_153 -> V_153 = V_24 -> V_164 ;
} else {
V_26 = - 1 ;
}
return V_26 ;
}
int F_57 ( struct V_23 * V_24 ,
struct V_165 * V_166 )
{
int V_26 ;
struct V_167 * V_168 ;
struct V_169 * V_170 ;
struct V_171 * V_172 ;
T_2 * V_173 ;
T_1 V_174 = 0 ;
if ( ! V_166 -> V_175 ) {
V_174 = ( T_1 ) V_166 -> V_176 ;
if ( ( V_174 < V_24 -> V_109 ) ||
( V_174 > V_24 -> V_107 ) ) {
F_15 ( V_24 -> V_12 -> V_4 , L_27
L_28 ,
V_174 , V_24 -> V_109 ,
V_24 -> V_107 ) ;
return - 1 ;
}
}
V_173 = F_14 ( V_177 , V_65 ) ;
if ( ! V_173 ) {
F_15 ( V_24 -> V_12 -> V_4 , L_29 ,
V_178 ) ;
return - V_66 ;
}
V_168 = (struct V_167 * ) V_173 ;
V_168 -> V_79 = F_58 ( V_36 ) ;
if ( ! V_166 -> V_175 ) {
V_168 -> V_29 = F_31 ( 1 ) ;
V_170 = (struct V_169 * ) ( V_173 +
sizeof( struct V_167 ) ) ;
V_170 -> type = V_179 ;
V_170 -> V_180 = 4 * sizeof( struct V_171 ) ;
V_172 = (struct V_171 * ) ( V_173 +
sizeof( struct V_167 ) +
sizeof( struct V_169 ) ) ;
V_172 -> V_181 = 0x00 ;
V_172 -> V_182 = 0x03 ;
V_172 -> V_183 = V_184 ;
V_172 -> V_185 = 0 ;
V_172 -> V_186 = ( V_187 ) V_174 ;
V_172 -> V_188 = ( V_187 ) V_174 ;
V_172 ++ ;
V_172 -> V_181 = 0x00 ;
V_172 -> V_182 = 0x07 ;
V_172 -> V_183 = V_189 ;
V_172 -> V_185 = 0 ;
V_172 -> V_186 = ( V_187 ) V_174 ;
V_172 -> V_188 = ( V_187 ) V_174 ;
V_172 ++ ;
V_172 -> V_181 = 0x00 ;
V_172 -> V_182 = 0x20 ;
V_172 -> V_183 = V_190 ;
V_172 -> V_185 = 0 ;
V_172 -> V_186 = ( V_187 ) V_174 ;
V_172 -> V_188 = ( V_187 ) V_174 ;
V_172 -> V_191 = V_192 ;
V_172 ++ ;
V_172 -> V_181 = 0x00 ;
V_172 -> V_182 = 0x20 ;
V_172 -> V_183 = V_190 ;
V_172 -> V_185 = 0 ;
V_172 -> V_186 = ( V_187 ) V_174 ;
V_172 -> V_188 = ( V_187 ) V_174 ;
V_172 -> V_191 = V_193 ;
}
V_26 = F_32 ( V_24 , V_194 ,
V_36 , 0 , V_173 ) ;
F_17 ( V_173 ) ;
return V_26 ;
}
int F_59 ( struct V_23 * V_24 , T_5 * V_195 )
{
int V_26 ;
struct V_11 * V_12 = V_24 -> V_12 ;
T_1 V_196 ;
if ( * V_195 )
V_12 -> V_195 = V_197 ;
else
V_12 -> V_195 = V_198 ;
V_196 = ( * V_195 ) ? V_199 : V_120 ;
V_26 = F_32 ( V_24 , V_119 ,
V_196 , V_200 , NULL ) ;
if ( ( ! V_26 ) && ( V_196 == V_120 ) )
V_26 = F_10 ( V_24 ,
V_119 , V_201 ,
0 , NULL ) ;
return V_26 ;
}
static int F_60 ( struct V_23 * V_24 ,
T_2 * V_202 , T_1 V_41 )
{
if ( V_41 ) {
if ( V_41 > sizeof( V_24 -> V_203 ) ) {
F_15 ( V_24 -> V_12 -> V_4 ,
L_30 ) ;
return - 1 ;
}
memcpy ( V_24 -> V_203 , V_202 , V_41 ) ;
V_24 -> V_204 = ( T_2 ) V_41 ;
F_4 ( V_24 -> V_12 -> V_4 , L_31 ,
V_24 -> V_204 , V_24 -> V_203 [ 0 ] ) ;
if ( V_24 -> V_203 [ 0 ] == V_205 ) {
V_24 -> V_112 . V_206 = true ;
} else if ( V_24 -> V_203 [ 0 ] == V_207 ) {
V_24 -> V_112 . V_208 = true ;
} else {
V_24 -> V_112 . V_206 = false ;
V_24 -> V_112 . V_208 = false ;
}
} else {
memset ( V_24 -> V_203 , 0 , sizeof( V_24 -> V_203 ) ) ;
V_24 -> V_204 = 0 ;
F_4 ( V_24 -> V_12 -> V_4 , L_32 ,
V_24 -> V_204 , V_24 -> V_203 [ 0 ] ) ;
V_24 -> V_112 . V_206 = false ;
V_24 -> V_112 . V_208 = false ;
}
return 0 ;
}
static int F_61 ( struct V_23 * V_24 ,
T_2 * V_202 , T_1 V_41 )
{
if ( V_41 ) {
if ( V_41 > sizeof( V_24 -> V_209 ) ) {
F_4 ( V_24 -> V_12 -> V_4 ,
L_33 ) ;
return - 1 ;
}
memcpy ( V_24 -> V_209 , V_202 , V_41 ) ;
V_24 -> V_210 = V_41 ;
F_4 ( V_24 -> V_12 -> V_4 , L_34 ,
V_24 -> V_210 , V_24 -> V_209 [ 0 ] ) ;
if ( V_24 -> V_209 [ 0 ] == V_211 )
V_24 -> V_112 . V_212 = true ;
} else {
memset ( V_24 -> V_209 , 0 , sizeof( V_24 -> V_209 ) ) ;
V_24 -> V_210 = V_41 ;
F_4 ( V_24 -> V_12 -> V_4 ,
L_35 ,
V_24 -> V_210 , V_24 -> V_209 [ 0 ] ) ;
V_24 -> V_112 . V_212 = false ;
}
return 0 ;
}
static int F_62 ( struct V_23 * V_24 ,
struct V_213 * V_214 )
{
return F_32 ( V_24 , V_215 ,
V_36 , V_216 ,
V_214 ) ;
}
static int F_63 ( struct V_23 * V_24 ,
struct V_213 * V_214 )
{
int V_26 ;
struct V_217 * V_218 ;
int V_219 ;
if ( V_24 -> V_220 >= V_221 )
V_24 -> V_220 = 0 ;
V_218 = & V_24 -> V_218 [ V_24 -> V_220 ] ;
V_219 = V_214 -> V_222 ;
if ( V_214 -> V_223 ) {
V_24 -> V_112 . V_113 = V_224 ;
} else if ( ! V_214 -> V_225 ) {
V_218 = & V_24 -> V_218 [ V_219 ] ;
if ( ! V_218 -> V_226 ) {
F_15 ( V_24 -> V_12 -> V_4 ,
L_36 ) ;
return - 1 ;
}
V_24 -> V_220 = ( T_1 ) V_219 ;
V_24 -> V_112 . V_113 = V_114 ;
} else {
V_218 = & V_24 -> V_218 [ V_219 ] ;
memset ( V_218 , 0 , sizeof( struct V_217 ) ) ;
memcpy ( V_218 -> V_227 ,
V_214 -> V_227 ,
V_214 -> V_225 ) ;
V_218 -> V_222 = V_219 ;
V_218 -> V_226 = V_214 -> V_225 ;
V_24 -> V_112 . V_113 = V_114 ;
}
if ( V_218 -> V_226 ) {
V_26 = F_10 ( V_24 ,
V_215 ,
V_36 , 0 , NULL ) ;
if ( V_26 )
return V_26 ;
}
if ( V_24 -> V_112 . V_113 == V_114 )
V_24 -> V_28 |= V_228 ;
else
V_24 -> V_28 &= ~ V_228 ;
V_26 = F_32 ( V_24 , V_37 ,
V_36 , 0 ,
& V_24 -> V_28 ) ;
return V_26 ;
}
static int F_64 ( struct V_23 * V_24 ,
struct V_213 * V_214 )
{
int V_26 ;
T_2 V_229 = false ;
struct V_230 * V_231 ;
if ( V_214 -> V_225 > V_232 ) {
F_15 ( V_24 -> V_12 -> V_4 , L_37 ) ;
return - 1 ;
}
if ( V_24 -> V_56 == V_57 ) {
V_214 -> V_222 = V_233 ;
V_26 = F_10 ( V_24 ,
V_215 ,
V_36 , V_216 ,
V_214 ) ;
if ( V_26 )
return V_26 ;
V_231 = & V_24 -> V_234 ;
memset ( V_231 , 0 ,
sizeof( struct V_230 ) ) ;
memcpy ( V_231 -> V_235 . V_236 , V_214 -> V_227 ,
V_214 -> V_225 ) ;
memcpy ( & V_231 -> V_235 . V_225 , & V_214 -> V_225 ,
sizeof( V_231 -> V_235 . V_225 ) ) ;
V_231 -> V_235 . V_237
= F_58 ( V_238 ) ;
V_231 -> V_235 . V_239 = F_58 ( V_240 ) ;
V_214 -> V_222 = ~ V_233 ;
}
if ( ! V_214 -> V_222 )
V_214 -> V_222 = V_233 ;
if ( V_229 )
V_26 = F_32 ( V_24 ,
V_215 ,
V_36 , ! ( V_216 ) ,
V_214 ) ;
else
V_26 = F_32 ( V_24 ,
V_215 ,
V_36 , V_216 ,
V_214 ) ;
return V_26 ;
}
static int
F_65 ( struct V_23 * V_24 ,
struct V_213 * V_214 )
{
int V_14 ;
if ( V_214 -> V_241 )
V_14 = F_62 ( V_24 , V_214 ) ;
else if ( V_214 -> V_225 > V_242 )
V_14 = F_64 ( V_24 , V_214 ) ;
else
V_14 = F_63 ( V_24 , V_214 ) ;
return V_14 ;
}
int
F_66 ( struct V_11 * V_12 , char * V_243 ,
int V_244 )
{
union {
T_5 V_245 ;
T_2 V_246 [ 4 ] ;
} V_247 ;
char V_248 [ 32 ] ;
V_247 . V_245 = V_12 -> V_249 ;
sprintf ( V_248 , L_38 , V_247 . V_246 [ 2 ] , V_247 . V_246 [ 1 ] , V_247 . V_246 [ 0 ] , V_247 . V_246 [ 3 ] ) ;
snprintf ( V_243 , V_244 , V_250 , V_248 ) ;
F_4 ( V_12 -> V_4 , L_39 , V_243 ) ;
return 0 ;
}
int F_67 ( struct V_23 * V_24 ,
struct V_251 * signal )
{
int V_14 ;
signal -> V_252 = V_253 ;
if ( ! V_24 -> V_105 ) {
F_4 ( V_24 -> V_12 -> V_4 ,
L_40 ) ;
return - 1 ;
}
V_14 = F_32 ( V_24 , V_254 ,
V_93 , 0 , signal ) ;
if ( ! V_14 ) {
if ( signal -> V_252 & V_255 )
V_24 -> V_256 = signal -> V_257 ;
if ( signal -> V_252 & V_258 )
V_24 -> V_259 = signal -> V_260 ;
}
return V_14 ;
}
int F_68 ( struct V_23 * V_24 , const T_2 * V_236 ,
int V_225 , T_2 V_222 , int V_261 )
{
struct V_213 V_214 ;
memset ( & V_214 , 0 , sizeof( struct V_213 ) ) ;
V_214 . V_225 = V_225 ;
if ( ! V_261 ) {
V_214 . V_222 = V_222 ;
if ( V_225 )
memcpy ( V_214 . V_227 , V_236 , V_225 ) ;
} else {
V_214 . V_223 = true ;
}
return F_65 ( V_24 , & V_214 ) ;
}
int
F_69 ( struct V_23 * V_24 )
{
struct V_262 V_263 ;
memset ( & V_263 , 0 , sizeof( struct V_264 ) ) ;
if ( F_32 ( V_24 , V_265 ,
V_93 , 0 , & V_263 ) )
return - 1 ;
return 0 ;
}
int
F_70 ( struct V_23 * V_24 ,
struct V_266 * log )
{
return F_32 ( V_24 , V_267 ,
V_93 , 0 , log ) ;
}
static int F_71 ( struct V_23 * V_24 ,
struct V_268 * V_269 ,
T_1 V_79 )
{
T_1 V_270 ;
switch ( F_30 ( V_269 -> type ) ) {
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
return F_32 ( V_24 , V_270 , V_79 , 0 , V_269 ) ;
}
int
F_72 ( struct V_23 * V_24 , T_5 V_281 ,
T_5 V_282 , T_5 V_283 )
{
struct V_268 V_269 ;
V_269 . type = F_31 ( V_281 ) ;
V_269 . V_284 = F_31 ( V_282 ) ;
V_269 . V_285 = F_31 ( V_283 ) ;
return F_71 ( V_24 , & V_269 , V_36 ) ;
}
int
F_73 ( struct V_23 * V_24 , T_5 V_281 ,
T_5 V_282 , T_5 * V_285 )
{
int V_26 ;
struct V_268 V_269 ;
V_269 . type = F_31 ( V_281 ) ;
V_269 . V_284 = F_31 ( V_282 ) ;
V_26 = F_71 ( V_24 , & V_269 , V_93 ) ;
if ( V_26 )
goto V_71;
* V_285 = F_30 ( V_269 . V_285 ) ;
V_71:
return V_26 ;
}
int
F_74 ( struct V_23 * V_24 , T_1 V_284 , T_1 V_286 ,
T_2 * V_285 )
{
int V_26 ;
struct V_287 V_288 ;
V_288 . V_284 = F_58 ( ( T_1 ) V_284 ) ;
V_288 . V_289 = F_58 ( ( T_1 ) V_286 ) ;
V_26 = F_32 ( V_24 , V_290 ,
V_93 , 0 , & V_288 ) ;
if ( ! V_26 )
memcpy ( V_285 , V_288 . V_285 , V_291 ) ;
return V_26 ;
}
static int
F_75 ( struct V_23 * V_24 , T_2 * V_202 ,
T_1 V_41 )
{
int V_26 = 0 ;
struct V_292 * V_293 ;
const T_2 V_294 [] = { 0x00 , 0x50 , 0xf2 , 0x01 } ;
const T_2 V_295 [] = { 0x00 , 0x50 , 0xf2 , 0x04 } ;
if ( ! V_41 ) {
V_24 -> V_296 = 0 ;
V_24 -> V_297 . V_298 = false ;
return 0 ;
} else if ( ! V_202 ) {
return - 1 ;
}
V_293 = (struct V_292 * ) V_202 ;
if ( ( ( V_293 -> V_299 == V_205 )
&& ( ! memcmp ( V_293 -> V_300 , V_294 , sizeof( V_294 ) ) ) )
|| ( V_293 -> V_299 == V_207 ) ) {
V_26 = F_60 ( V_24 , V_202 , V_41 ) ;
V_24 -> V_297 . V_298 = false ;
return V_26 ;
} else if ( V_293 -> V_299 == V_211 ) {
V_26 = F_61 ( V_24 , V_202 , V_41 ) ;
return V_26 ;
}
if ( V_41 < ( sizeof( V_24 -> V_301 ) - V_24 -> V_296 ) ) {
V_293 = (struct V_292 * ) V_202 ;
if ( ( V_293 -> V_299 == V_302 )
&& ( ! memcmp ( V_293 -> V_300 , V_295 ,
sizeof( V_295 ) ) ) ) {
V_24 -> V_297 . V_298 = true ;
F_4 ( V_24 -> V_12 -> V_4 ,
L_41 ) ;
}
memcpy ( V_24 -> V_301 + V_24 -> V_296 , V_202 ,
V_41 ) ;
V_24 -> V_296 += V_41 ;
} else {
V_26 = - 1 ;
}
return V_26 ;
}
static int F_76 ( struct V_23 * V_24 ,
struct V_303 * V_304 ,
T_1 V_79 )
{
struct V_11 * V_12 = V_24 -> V_12 ;
switch ( V_304 -> type ) {
case V_305 :
if ( V_79 == V_93 ) {
V_304 -> V_306 = V_24 -> V_204 ;
memcpy ( V_304 -> V_307 , V_24 -> V_203 , V_304 -> V_306 ) ;
} else {
F_75 ( V_24 , V_304 -> V_307 ,
( T_1 ) V_304 -> V_306 ) ;
}
break;
case V_308 :
memset ( V_12 -> V_309 , 0 , sizeof( V_12 -> V_309 ) ) ;
if ( V_304 -> V_306 > V_310 ) {
V_12 -> V_311 = 0 ;
F_15 ( V_12 -> V_4 , L_42 ) ;
return - 1 ;
} else {
memcpy ( V_12 -> V_309 , V_304 -> V_307 ,
V_304 -> V_306 ) ;
V_12 -> V_311 = V_304 -> V_306 ;
}
break;
default:
F_15 ( V_12 -> V_4 , L_43 ) ;
return - 1 ;
}
return 0 ;
}
int
F_77 ( struct V_23 * V_24 , T_2 * V_312 , int V_41 )
{
struct V_303 V_304 ;
if ( V_41 > V_313 )
return - V_314 ;
V_304 . type = V_305 ;
V_304 . V_306 = V_41 ;
memcpy ( V_304 . V_307 , V_312 , V_41 ) ;
if ( F_76 ( V_24 , & V_304 , V_36 ) )
return - V_314 ;
return 0 ;
}
