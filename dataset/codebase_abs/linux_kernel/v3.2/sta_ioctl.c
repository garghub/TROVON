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
int V_14 = V_12 -> V_15 . V_14 ;
struct V_16 * V_17 ;
if ( ! V_12 -> V_17 )
return 0 ;
V_17 = V_12 -> V_17 ;
V_12 -> V_17 = NULL ;
F_4 ( V_12 -> V_4 , L_1 ) ;
F_5 ( & V_12 -> V_18 ) ;
F_6 ( V_12 -> V_19 , & V_12 -> V_20 ) ;
F_7 ( V_12 -> V_15 . V_21 ,
* ( V_17 -> V_22 ) ) ;
if ( ! * ( V_17 -> V_22 ) )
V_13 = true ;
if ( V_13 ) {
F_8 ( V_12 ) ;
F_4 ( V_12 -> V_4 , L_2 ) ;
}
V_12 -> V_15 . V_14 = 0 ;
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
F_21 ( V_24 -> V_72 ) ;
V_24 -> V_73 = 0 ;
V_26 = F_22 ( V_24 , V_46 ) ;
if ( V_60 )
F_23 ( V_60 ) ;
} else {
if ( V_46 && V_46 -> V_74 . V_75 &&
( ! F_24
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
F_21 ( V_24 -> V_72 ) ;
if ( ! V_26 ) {
F_4 ( V_12 -> V_4 , L_13
L_14 ) ;
V_26 = F_25 ( V_24 , V_46 ) ;
if ( V_60 )
F_23 ( V_60 ) ;
} else {
F_4 ( V_12 -> V_4 , L_15
L_16 ,
V_62 -> V_74 ) ;
V_26 = F_26 ( V_24 , V_62 ) ;
}
}
V_71:
F_17 ( V_46 ) ;
F_17 ( V_63 ) ;
return V_26 ;
}
static int F_27 ( struct V_23 * V_24 , T_1 V_79 ,
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
V_83 = F_28 ( V_12 -> V_82
. V_86 ) ;
V_12 -> V_82 . V_86 =
F_29 ( V_82 -> V_86 ) ;
} else if ( V_82 -> V_86 ) {
V_12 -> V_82 . V_86 =
F_29 ( V_82 -> V_86 ) ;
V_12 -> V_82 . V_89 = ( T_2 ) V_82 -> V_89 ;
if ( V_82 -> V_90 )
V_12 -> V_82 . V_90 = ( T_2 ) V_82 -> V_90 ;
} else if ( V_12 -> V_82 . V_86 ==
F_29 (
V_87 ) ) {
V_14 = - 1 ;
break;
}
if ( V_80 == V_91 )
V_14 = F_30 ( V_24 ,
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
F_29 ( V_83 ) ;
} else {
V_12 -> V_82 . V_86 =
F_29 ( V_82 -> V_86 ) ;
V_12 -> V_82 . V_89 = ( T_2 ) V_82 -> V_89 ;
V_12 -> V_82 . V_90 = ( T_2 ) V_82 -> V_90 ;
}
break;
case V_93 :
V_82 -> V_86 = F_28 ( V_12 -> V_82 . V_86 ) ;
V_82 -> V_89 = V_12 -> V_82 . V_89 ;
V_82 -> V_90 = V_12 -> V_82 . V_90 ;
break;
default:
V_14 = - 1 ;
break;
}
return V_14 ;
}
int F_31 ( struct V_23 * V_24 , int V_80 )
{
struct V_81 V_94 ;
V_94 . V_86 = V_87 ;
V_94 . V_85 = true ;
return F_27 ( V_24 , V_36 ,
V_80 , & V_94 ) ;
}
int F_32 ( struct V_11 * V_12 )
{
struct V_81 V_94 ;
if ( V_12 -> V_95 ) {
F_4 ( V_12 -> V_4 , L_19 ) ;
return true ;
}
V_12 -> V_96 = false ;
memset ( & V_94 , 0 , sizeof( struct V_97 ) ) ;
V_94 . V_85 = true ;
if ( F_27 ( F_33 ( V_12 ,
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
int F_34 ( struct V_23 * V_24 ,
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
int F_35 ( struct V_23 * V_24 ,
struct V_116 * V_117 )
{
struct V_11 * V_12 = V_24 -> V_12 ;
T_2 V_118 , V_119 ;
T_5 V_120 ;
V_118 = ( T_2 ) V_117 -> V_121 ;
V_119 = ( T_2 ) V_117 -> V_122 ;
V_120 = V_117 -> V_120 ;
if ( ( V_118 | V_12 -> V_123 ) & ~ V_12 -> V_123 )
return - 1 ;
V_12 -> V_121 = V_118 ;
if ( ( V_119 | V_12 -> V_123 ) & ~ V_12 -> V_123 )
return - 1 ;
if ( V_119 )
V_12 -> V_122 = V_119 ;
V_12 -> V_124 = ( T_2 ) V_117 -> V_125 ;
if ( ! V_120 ) {
if ( ! F_36
( V_24 , V_12 -> V_122 ,
V_24 -> V_120 ) ) {
V_117 -> V_120 = V_126 ;
if ( ( V_12 -> V_122 & V_127 )
|| ( V_12 -> V_122 & V_128 ) )
V_117 -> V_120 =
V_129 ;
}
} else {
if ( ! F_36
( V_24 , V_12 -> V_122 , ( T_1 ) V_120 ) )
return - 1 ;
V_24 -> V_120 = ( T_2 ) V_120 ;
}
if ( ( V_119 & V_130 ) || ( V_119 & V_128 ) )
V_12 -> V_131 = true ;
else
V_12 -> V_131 = false ;
return 0 ;
}
int F_37 ( struct V_23 * V_24 )
{
struct V_132 V_133 ;
V_133 . V_133 = V_134 ;
return F_30 ( V_24 , V_135 ,
V_136 , V_137 , & V_133 ) ;
}
int F_38 ( struct V_23 * V_24 ,
struct V_138 * V_139 )
{
struct V_11 * V_12 = V_24 -> V_12 ;
struct V_138 * V_140 = NULL ;
if ( ! V_139 )
return - 1 ;
if ( ! V_139 -> V_103 && ! V_139 -> V_141 )
return - 1 ;
if ( V_12 -> V_122 & V_128 )
V_12 -> V_122 = V_142 | V_143 | V_130 ;
else if ( V_12 -> V_122 & V_127 )
V_12 -> V_122 = V_142 | V_143 ;
if ( V_139 -> V_103 ) {
if ( V_139 -> V_103 <= V_144 )
V_140 = F_36
( V_24 , 0 , ( T_1 ) V_139 -> V_103 ) ;
if ( ! V_140 ) {
V_140 = F_36
( V_24 , V_127 , ( T_1 ) V_139 -> V_103 ) ;
if ( V_140 ) {
if ( V_12 -> V_131 )
V_12 -> V_122 = V_127
| V_128 ;
else
V_12 -> V_122 = V_127 ;
}
}
} else {
if ( V_139 -> V_141 <= V_145 )
V_140 = F_39 (
V_24 , 0 , V_139 -> V_141 ) ;
if ( ! V_140 ) {
V_140 = F_39
( V_24 , V_127 , V_139 -> V_141 ) ;
if ( V_140 ) {
if ( V_12 -> V_131 )
V_12 -> V_122 = V_127
| V_128 ;
else
V_12 -> V_122 = V_127 ;
}
}
}
if ( ! V_140 || ! V_140 -> V_103 ) {
F_15 ( V_12 -> V_4 , L_21 ) ;
return - 1 ;
}
V_24 -> V_120 = ( T_2 ) V_140 -> V_103 ;
V_139 -> V_103 = V_140 -> V_103 ;
V_139 -> V_141 = V_140 -> V_141 ;
return 0 ;
}
static int F_40 ( struct V_23 * V_24 ,
T_1 V_79 , T_1 * V_103 )
{
if ( V_79 == V_93 ) {
if ( ! V_24 -> V_105 ) {
* V_103 = V_24 -> V_120 ;
return 0 ;
}
} else {
V_24 -> V_120 = ( T_2 ) * V_103 ;
}
return F_30 ( V_24 , V_146 ,
V_79 , 0 , V_103 ) ;
}
int
F_41 ( struct V_23 * V_24 , int V_103 )
{
int V_26 ;
struct V_100 V_147 ;
struct V_148 V_149 ;
T_1 V_150 = 0 ;
struct V_59 * V_60 = NULL ;
struct V_151 * V_139 ;
enum V_152 V_44 ;
memset ( & V_147 , 0 , sizeof( V_147 ) ) ;
if ( F_34 ( V_24 , & V_147 ) )
return - 1 ;
V_26 = F_40 ( V_24 , V_93 ,
& V_150 ) ;
if ( V_150 == V_103 ) {
V_26 = 0 ;
goto V_71;
}
F_4 ( V_24 -> V_12 -> V_4 , L_22 ,
V_150 , V_103 ) ;
if ( ! V_147 . V_105 ) {
V_26 = 0 ;
goto V_71;
}
memset ( & V_149 , 0 , V_10 ) ;
V_26 = F_18 ( V_24 , V_149 . V_38 ) ;
V_26 = F_40 ( V_24 , V_36 ,
( T_1 * ) & V_103 ) ;
if ( F_42 ( V_24 , & V_147 . V_74 ) ) {
V_26 = - 1 ;
goto V_71;
}
V_44 = F_43 ( V_24 -> V_76 . V_44 ) ;
V_139 = F_44 ( V_24 -> V_153 -> V_154 ,
F_45 ( V_103 , V_44 ) ) ;
V_60 = F_46 ( V_24 -> V_153 -> V_154 , V_139 , V_147 . V_38 ,
V_147 . V_74 . V_74 , V_147 . V_74 . V_75 ,
V_155 , V_155 ) ;
if ( ! V_60 )
F_47 ( V_24 -> V_153 -> V_154 , L_23 ,
V_147 . V_38 ) ;
V_26 = F_13 ( V_24 , V_60 , & V_147 . V_74 ) ;
V_71:
return V_26 ;
}
static int F_48 ( struct V_23 * V_24 ,
struct V_156 * V_157 )
{
V_157 -> V_158 = V_24 -> V_159 ;
return F_30 ( V_24 , V_160 ,
V_93 , 0 , NULL ) ;
}
static int F_49 ( struct V_23 * V_24 ,
struct V_156 * V_157 )
{
T_2 V_161 [ V_162 ] ;
T_2 * V_163 ;
int V_164 , V_26 ;
T_1 V_165 [ V_166 ] ;
T_5 V_5 ;
struct V_11 * V_12 = V_24 -> V_12 ;
if ( V_157 -> V_158 ) {
memset ( V_165 , 0 , sizeof( V_165 ) ) ;
V_165 [ 0 ] = 0x000F ;
V_165 [ 1 ] = 0x00FF ;
for ( V_5 = 0 ; V_5 < F_50 ( V_24 -> V_165 ) - 3 ; V_5 ++ )
V_165 [ V_5 + 2 ] = 0xFFFF ;
V_165 [ 9 ] = 0x3FFF ;
} else {
memset ( V_161 , 0 , sizeof( V_161 ) ) ;
F_51 ( V_24 , V_161 ) ;
V_163 = V_161 ;
for ( V_5 = 0 ; ( V_163 [ V_5 ] && V_5 < V_162 ) ; V_5 ++ ) {
F_4 ( V_12 -> V_4 , L_24 ,
V_163 [ V_5 ] , V_157 -> V_163 ) ;
if ( ( V_163 [ V_5 ] & 0x7f ) == ( V_157 -> V_163 & 0x7f ) )
break;
}
if ( ( V_5 == V_162 ) || ! V_163 [ V_5 ] ) {
F_15 ( V_12 -> V_4 , L_25
L_26 , V_157 -> V_163 ) ;
return - 1 ;
}
memset ( V_165 , 0 , sizeof( V_165 ) ) ;
V_164 = F_52 ( V_157 -> V_163 ) ;
if ( V_164 >= V_167 &&
V_164 <= V_168 ) {
V_165 [ 0 ] = 1 << V_164 ;
} else {
V_164 -= 1 ;
if ( V_164 >= V_169 &&
V_164 <= V_170 )
V_165 [ 1 ] = 1 << ( V_164 -
V_169 ) ;
}
}
V_26 = F_30 ( V_24 , V_171 ,
V_36 , 0 , V_165 ) ;
return V_26 ;
}
static int F_53 ( struct V_23 * V_24 ,
struct V_156 * V_157 )
{
int V_14 ;
if ( ! V_157 )
return - 1 ;
if ( V_157 -> V_79 == V_93 )
V_14 = F_48 ( V_24 , V_157 ) ;
else
V_14 = F_49 ( V_24 , V_157 ) ;
return V_14 ;
}
int F_54 ( struct V_23 * V_24 ,
struct V_156 * V_163 )
{
int V_26 ;
memset ( V_163 , 0 , sizeof( struct V_156 ) ) ;
V_163 -> V_79 = V_93 ;
V_26 = F_53 ( V_24 , V_163 ) ;
if ( ! V_26 ) {
if ( V_163 -> V_158 )
V_163 -> V_163 = F_55 ( V_24 -> V_172 ,
V_24 -> V_173 ) ;
else
V_163 -> V_163 = V_24 -> V_174 ;
} else {
V_26 = - 1 ;
}
return V_26 ;
}
int F_56 ( struct V_23 * V_24 ,
struct V_175 * V_176 )
{
int V_26 ;
struct V_177 * V_178 ;
struct V_179 * V_180 ;
struct V_181 * V_182 ;
T_2 * V_183 ;
T_1 V_184 = 0 ;
if ( ! V_176 -> V_185 ) {
V_184 = ( T_1 ) V_176 -> V_186 ;
if ( ( V_184 < V_24 -> V_109 ) ||
( V_184 > V_24 -> V_107 ) ) {
F_15 ( V_24 -> V_12 -> V_4 , L_27
L_28 ,
V_184 , V_24 -> V_109 ,
V_24 -> V_107 ) ;
return - 1 ;
}
}
V_183 = F_14 ( V_187 , V_65 ) ;
if ( ! V_183 ) {
F_15 ( V_24 -> V_12 -> V_4 , L_29 ,
V_188 ) ;
return - V_66 ;
}
V_178 = (struct V_177 * ) V_183 ;
V_178 -> V_79 = F_57 ( V_36 ) ;
if ( ! V_176 -> V_185 ) {
V_178 -> V_29 = F_29 ( 1 ) ;
V_180 = (struct V_179 * ) ( V_183 +
sizeof( struct V_177 ) ) ;
V_180 -> type = V_189 ;
V_180 -> V_190 = 4 * sizeof( struct V_181 ) ;
V_182 = (struct V_181 * ) ( V_183 +
sizeof( struct V_177 ) +
sizeof( struct V_179 ) ) ;
V_182 -> V_191 = 0x00 ;
V_182 -> V_192 = 0x03 ;
V_182 -> V_193 = V_194 ;
V_182 -> V_195 = 0 ;
V_182 -> V_196 = ( V_197 ) V_184 ;
V_182 -> V_198 = ( V_197 ) V_184 ;
V_182 ++ ;
V_182 -> V_191 = 0x00 ;
V_182 -> V_192 = 0x07 ;
V_182 -> V_193 = V_199 ;
V_182 -> V_195 = 0 ;
V_182 -> V_196 = ( V_197 ) V_184 ;
V_182 -> V_198 = ( V_197 ) V_184 ;
V_182 ++ ;
V_182 -> V_191 = 0x00 ;
V_182 -> V_192 = 0x20 ;
V_182 -> V_193 = V_200 ;
V_182 -> V_195 = 0 ;
V_182 -> V_196 = ( V_197 ) V_184 ;
V_182 -> V_198 = ( V_197 ) V_184 ;
V_182 -> V_201 = V_202 ;
V_182 ++ ;
V_182 -> V_191 = 0x00 ;
V_182 -> V_192 = 0x20 ;
V_182 -> V_193 = V_200 ;
V_182 -> V_195 = 0 ;
V_182 -> V_196 = ( V_197 ) V_184 ;
V_182 -> V_198 = ( V_197 ) V_184 ;
V_182 -> V_201 = V_203 ;
}
V_26 = F_30 ( V_24 , V_204 ,
V_36 , 0 , V_183 ) ;
F_17 ( V_183 ) ;
return V_26 ;
}
int F_58 ( struct V_23 * V_24 , T_5 * V_205 )
{
int V_26 ;
struct V_11 * V_12 = V_24 -> V_12 ;
T_1 V_206 ;
if ( * V_205 )
V_12 -> V_205 = V_207 ;
else
V_12 -> V_205 = V_208 ;
V_206 = ( * V_205 ) ? V_209 : V_136 ;
V_26 = F_30 ( V_24 , V_135 ,
V_206 , V_210 , NULL ) ;
if ( ( ! V_26 ) && ( V_206 == V_136 ) )
V_26 = F_10 ( V_24 ,
V_135 , V_211 ,
0 , NULL ) ;
return V_26 ;
}
static int F_59 ( struct V_23 * V_24 ,
T_2 * V_212 , T_1 V_41 )
{
if ( V_41 ) {
if ( V_41 > sizeof( V_24 -> V_213 ) ) {
F_15 ( V_24 -> V_12 -> V_4 ,
L_30 ) ;
return - 1 ;
}
memcpy ( V_24 -> V_213 , V_212 , V_41 ) ;
V_24 -> V_214 = ( T_2 ) V_41 ;
F_4 ( V_24 -> V_12 -> V_4 , L_31 ,
V_24 -> V_214 , V_24 -> V_213 [ 0 ] ) ;
if ( V_24 -> V_213 [ 0 ] == V_215 ) {
V_24 -> V_112 . V_216 = true ;
} else if ( V_24 -> V_213 [ 0 ] == V_217 ) {
V_24 -> V_112 . V_218 = true ;
} else {
V_24 -> V_112 . V_216 = false ;
V_24 -> V_112 . V_218 = false ;
}
} else {
memset ( V_24 -> V_213 , 0 , sizeof( V_24 -> V_213 ) ) ;
V_24 -> V_214 = 0 ;
F_4 ( V_24 -> V_12 -> V_4 , L_32 ,
V_24 -> V_214 , V_24 -> V_213 [ 0 ] ) ;
V_24 -> V_112 . V_216 = false ;
V_24 -> V_112 . V_218 = false ;
}
return 0 ;
}
static int F_60 ( struct V_23 * V_24 ,
T_2 * V_212 , T_1 V_41 )
{
if ( V_41 ) {
if ( V_41 > sizeof( V_24 -> V_219 ) ) {
F_4 ( V_24 -> V_12 -> V_4 ,
L_33 ) ;
return - 1 ;
}
memcpy ( V_24 -> V_219 , V_212 , V_41 ) ;
V_24 -> V_220 = V_41 ;
F_4 ( V_24 -> V_12 -> V_4 , L_34 ,
V_24 -> V_220 , V_24 -> V_219 [ 0 ] ) ;
if ( V_24 -> V_219 [ 0 ] == V_221 )
V_24 -> V_112 . V_222 = true ;
} else {
memset ( V_24 -> V_219 , 0 , sizeof( V_24 -> V_219 ) ) ;
V_24 -> V_220 = V_41 ;
F_4 ( V_24 -> V_12 -> V_4 ,
L_35 ,
V_24 -> V_220 , V_24 -> V_219 [ 0 ] ) ;
V_24 -> V_112 . V_222 = false ;
}
return 0 ;
}
static int F_61 ( struct V_23 * V_24 ,
struct V_223 * V_224 )
{
return F_30 ( V_24 , V_225 ,
V_36 , V_226 ,
V_224 ) ;
}
static int F_62 ( struct V_23 * V_24 ,
struct V_223 * V_224 )
{
int V_26 ;
struct V_227 * V_228 ;
int V_229 ;
if ( V_24 -> V_230 >= V_231 )
V_24 -> V_230 = 0 ;
V_228 = & V_24 -> V_228 [ V_24 -> V_230 ] ;
V_229 = V_224 -> V_232 ;
if ( V_224 -> V_233 ) {
V_24 -> V_112 . V_113 = V_234 ;
} else if ( ! V_224 -> V_235 ) {
V_228 = & V_24 -> V_228 [ V_229 ] ;
if ( ! V_228 -> V_236 ) {
F_15 ( V_24 -> V_12 -> V_4 ,
L_36 ) ;
return - 1 ;
}
V_24 -> V_230 = ( T_1 ) V_229 ;
V_24 -> V_112 . V_113 = V_114 ;
} else {
V_228 = & V_24 -> V_228 [ V_229 ] ;
memset ( V_228 , 0 , sizeof( struct V_227 ) ) ;
memcpy ( V_228 -> V_237 ,
V_224 -> V_237 ,
V_224 -> V_235 ) ;
V_228 -> V_232 = V_229 ;
V_228 -> V_236 = V_224 -> V_235 ;
V_24 -> V_112 . V_113 = V_114 ;
}
if ( V_228 -> V_236 ) {
V_26 = F_10 ( V_24 ,
V_225 ,
V_36 , 0 , NULL ) ;
if ( V_26 )
return V_26 ;
}
if ( V_24 -> V_112 . V_113 == V_114 )
V_24 -> V_28 |= V_238 ;
else
V_24 -> V_28 &= ~ V_238 ;
V_26 = F_30 ( V_24 , V_37 ,
V_36 , 0 ,
& V_24 -> V_28 ) ;
return V_26 ;
}
static int F_63 ( struct V_23 * V_24 ,
struct V_223 * V_224 )
{
int V_26 ;
T_2 V_239 = false ;
struct V_240 * V_241 ;
if ( V_224 -> V_235 > V_242 ) {
F_15 ( V_24 -> V_12 -> V_4 , L_37 ) ;
return - 1 ;
}
if ( V_24 -> V_56 == V_57 ) {
V_224 -> V_232 = V_243 ;
V_26 = F_10 ( V_24 ,
V_225 ,
V_36 , V_226 ,
V_224 ) ;
if ( V_26 )
return V_26 ;
V_241 = & V_24 -> V_244 ;
memset ( V_241 , 0 ,
sizeof( struct V_240 ) ) ;
memcpy ( V_241 -> V_245 . V_246 , V_224 -> V_237 ,
V_224 -> V_235 ) ;
memcpy ( & V_241 -> V_245 . V_235 , & V_224 -> V_235 ,
sizeof( V_241 -> V_245 . V_235 ) ) ;
V_241 -> V_245 . V_247
= F_57 ( V_248 ) ;
V_241 -> V_245 . V_249 = F_57 ( V_250 ) ;
V_224 -> V_232 = ~ V_243 ;
}
if ( ! V_224 -> V_232 )
V_224 -> V_232 = V_243 ;
if ( V_239 )
V_26 = F_30 ( V_24 ,
V_225 ,
V_36 , ! ( V_226 ) ,
V_224 ) ;
else
V_26 = F_30 ( V_24 ,
V_225 ,
V_36 , V_226 ,
V_224 ) ;
return V_26 ;
}
static int
F_64 ( struct V_23 * V_24 ,
struct V_223 * V_224 )
{
int V_14 ;
if ( V_224 -> V_251 )
V_14 = F_61 ( V_24 , V_224 ) ;
else if ( V_224 -> V_235 > V_252 )
V_14 = F_63 ( V_24 , V_224 ) ;
else
V_14 = F_62 ( V_24 , V_224 ) ;
return V_14 ;
}
int
F_65 ( struct V_11 * V_12 , char * V_253 ,
int V_254 )
{
union {
T_5 V_255 ;
T_2 V_256 [ 4 ] ;
} V_257 ;
char V_258 [ 32 ] ;
V_257 . V_255 = V_12 -> V_259 ;
sprintf ( V_258 , L_38 , V_257 . V_256 [ 2 ] , V_257 . V_256 [ 1 ] , V_257 . V_256 [ 0 ] , V_257 . V_256 [ 3 ] ) ;
snprintf ( V_253 , V_254 , V_260 , V_258 ) ;
F_4 ( V_12 -> V_4 , L_39 , V_253 ) ;
return 0 ;
}
int F_66 ( struct V_23 * V_24 ,
struct V_261 * signal )
{
int V_14 ;
signal -> V_262 = V_263 ;
if ( ! V_24 -> V_105 ) {
F_4 ( V_24 -> V_12 -> V_4 ,
L_40 ) ;
return - 1 ;
}
V_14 = F_30 ( V_24 , V_264 ,
V_93 , 0 , signal ) ;
if ( ! V_14 ) {
if ( signal -> V_262 & V_265 )
V_24 -> V_266 = signal -> V_267 ;
if ( signal -> V_262 & V_268 )
V_24 -> V_269 = signal -> V_270 ;
}
return V_14 ;
}
int F_67 ( struct V_23 * V_24 , const T_2 * V_246 ,
int V_235 , T_2 V_232 , int V_271 )
{
struct V_223 V_224 ;
memset ( & V_224 , 0 , sizeof( struct V_223 ) ) ;
V_224 . V_235 = V_235 ;
if ( ! V_271 ) {
V_224 . V_232 = V_232 ;
if ( V_235 )
memcpy ( V_224 . V_237 , V_246 , V_235 ) ;
} else {
V_224 . V_233 = true ;
}
return F_64 ( V_24 , & V_224 ) ;
}
int
F_68 ( struct V_23 * V_24 )
{
struct V_272 V_273 ;
memset ( & V_273 , 0 , sizeof( struct V_274 ) ) ;
if ( F_30 ( V_24 , V_275 ,
V_93 , 0 , & V_273 ) )
return - 1 ;
return 0 ;
}
int
F_69 ( struct V_23 * V_24 ,
struct V_276 * log )
{
return F_30 ( V_24 , V_277 ,
V_93 , 0 , log ) ;
}
static int F_70 ( struct V_23 * V_24 ,
struct V_278 * V_279 ,
T_1 V_79 )
{
T_1 V_280 ;
switch ( F_28 ( V_279 -> type ) ) {
case V_281 :
V_280 = V_282 ;
break;
case V_283 :
V_280 = V_284 ;
break;
case V_285 :
V_280 = V_286 ;
break;
case V_287 :
V_280 = V_288 ;
break;
case V_289 :
V_280 = V_290 ;
break;
default:
return - 1 ;
}
return F_30 ( V_24 , V_280 , V_79 , 0 , V_279 ) ;
}
int
F_71 ( struct V_23 * V_24 , T_5 V_291 ,
T_5 V_292 , T_5 V_293 )
{
struct V_278 V_279 ;
V_279 . type = F_29 ( V_291 ) ;
V_279 . V_294 = F_29 ( V_292 ) ;
V_279 . V_295 = F_29 ( V_293 ) ;
return F_70 ( V_24 , & V_279 , V_36 ) ;
}
int
F_72 ( struct V_23 * V_24 , T_5 V_291 ,
T_5 V_292 , T_5 * V_295 )
{
int V_26 ;
struct V_278 V_279 ;
V_279 . type = F_29 ( V_291 ) ;
V_279 . V_294 = F_29 ( V_292 ) ;
V_26 = F_70 ( V_24 , & V_279 , V_93 ) ;
if ( V_26 )
goto V_71;
* V_295 = F_28 ( V_279 . V_295 ) ;
V_71:
return V_26 ;
}
int
F_73 ( struct V_23 * V_24 , T_1 V_294 , T_1 V_296 ,
T_2 * V_295 )
{
int V_26 ;
struct V_297 V_298 ;
V_298 . V_294 = F_57 ( ( T_1 ) V_294 ) ;
V_298 . V_299 = F_57 ( ( T_1 ) V_296 ) ;
V_26 = F_30 ( V_24 , V_300 ,
V_93 , 0 , & V_298 ) ;
if ( ! V_26 )
memcpy ( V_295 , V_298 . V_295 , V_301 ) ;
return V_26 ;
}
static int
F_74 ( struct V_23 * V_24 , T_2 * V_212 ,
T_1 V_41 )
{
int V_26 = 0 ;
struct V_302 * V_303 ;
const T_2 V_304 [] = { 0x00 , 0x50 , 0xf2 , 0x01 } ;
const T_2 V_305 [] = { 0x00 , 0x50 , 0xf2 , 0x04 } ;
if ( ! V_41 ) {
V_24 -> V_306 = 0 ;
V_24 -> V_307 . V_308 = false ;
return 0 ;
} else if ( ! V_212 ) {
return - 1 ;
}
V_303 = (struct V_302 * ) V_212 ;
if ( ( ( V_303 -> V_309 == V_215 )
&& ( ! memcmp ( V_303 -> V_310 , V_304 , sizeof( V_304 ) ) ) )
|| ( V_303 -> V_309 == V_217 ) ) {
V_26 = F_59 ( V_24 , V_212 , V_41 ) ;
V_24 -> V_307 . V_308 = false ;
return V_26 ;
} else if ( V_303 -> V_309 == V_221 ) {
V_26 = F_60 ( V_24 , V_212 , V_41 ) ;
return V_26 ;
}
if ( V_41 < ( sizeof( V_24 -> V_311 ) - V_24 -> V_306 ) ) {
V_303 = (struct V_302 * ) V_212 ;
if ( ( V_303 -> V_309 == V_312 )
&& ( ! memcmp ( V_303 -> V_310 , V_305 ,
sizeof( V_305 ) ) ) ) {
V_24 -> V_307 . V_308 = true ;
F_4 ( V_24 -> V_12 -> V_4 ,
L_41 ) ;
}
memcpy ( V_24 -> V_311 + V_24 -> V_306 , V_212 ,
V_41 ) ;
V_24 -> V_306 += V_41 ;
} else {
V_26 = - 1 ;
}
return V_26 ;
}
static int F_75 ( struct V_23 * V_24 ,
struct V_313 * V_314 ,
T_1 V_79 )
{
struct V_11 * V_12 = V_24 -> V_12 ;
switch ( V_314 -> type ) {
case V_315 :
if ( V_79 == V_93 ) {
V_314 -> V_316 = V_24 -> V_214 ;
memcpy ( V_314 -> V_317 , V_24 -> V_213 , V_314 -> V_316 ) ;
} else {
F_74 ( V_24 , V_314 -> V_317 ,
( T_1 ) V_314 -> V_316 ) ;
}
break;
case V_318 :
memset ( V_12 -> V_319 , 0 , sizeof( V_12 -> V_319 ) ) ;
if ( V_314 -> V_316 > V_320 ) {
V_12 -> V_321 = 0 ;
F_15 ( V_12 -> V_4 , L_42 ) ;
return - 1 ;
} else {
memcpy ( V_12 -> V_319 , V_314 -> V_317 ,
V_314 -> V_316 ) ;
V_12 -> V_321 = V_314 -> V_316 ;
}
break;
default:
F_15 ( V_12 -> V_4 , L_43 ) ;
return - 1 ;
}
return 0 ;
}
int
F_76 ( struct V_23 * V_24 , T_2 * V_322 , int V_41 )
{
struct V_313 V_314 ;
if ( V_41 > V_323 )
return - V_324 ;
V_314 . type = V_315 ;
V_314 . V_316 = V_41 ;
memcpy ( V_314 . V_317 , V_322 , V_41 ) ;
if ( F_75 ( V_24 , & V_314 , V_36 ) )
return - V_324 ;
return 0 ;
}
