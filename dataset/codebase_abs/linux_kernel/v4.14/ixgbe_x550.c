static T_1 F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
struct V_5 * V_6 = & V_2 -> V_6 ;
struct V_7 * V_8 = & V_2 -> V_8 ;
F_2 ( V_2 ) ;
if ( V_4 -> V_9 . V_10 ( V_2 ) != V_11 )
V_6 -> V_9 . V_12 = NULL ;
V_8 -> V_13 = V_14 ;
return 0 ;
}
static T_1 F_3 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = & V_2 -> V_6 ;
F_2 ( V_2 ) ;
V_6 -> V_9 . V_12 = NULL ;
return 0 ;
}
static T_1 F_4 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
struct V_5 * V_6 = & V_2 -> V_6 ;
F_2 ( V_2 ) ;
if ( V_4 -> V_9 . V_10 ( V_2 ) != V_11 )
V_6 -> V_9 . V_12 = NULL ;
return 0 ;
}
static T_1 F_5 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = & V_2 -> V_6 ;
F_2 ( V_2 ) ;
V_6 -> V_9 . V_12 = NULL ;
return 0 ;
}
static void F_6 ( struct V_1 * V_2 )
{
T_2 V_15 = F_7 ( V_2 , V_16 ) ;
if ( V_2 -> V_17 . V_18 ) {
V_15 &= ~ ( V_19 | V_20 ) ;
V_15 |= V_21 ;
}
V_15 &= ~ ( V_22 | V_23 ) ;
F_8 ( V_2 , V_16 , V_15 ) ;
F_9 ( V_2 ) ;
}
static T_1 F_10 ( struct V_1 * V_2 , T_3 V_24 , T_3 * V_25 )
{
return V_2 -> V_8 . V_9 . V_26 ( V_2 , V_2 -> V_8 . V_13 , V_24 , V_25 ) ;
}
static T_1 F_11 ( struct V_1 * V_2 , T_3 V_24 , T_3 V_25 )
{
return V_2 -> V_8 . V_9 . V_27 ( V_2 , V_2 -> V_8 . V_13 , V_24 , V_25 ) ;
}
static T_1 F_12 ( struct V_1 * V_2 , T_4 V_24 , T_4 * V_25 )
{
T_1 V_28 ;
V_28 = F_13 ( V_2 , V_24 , V_29 , V_25 ) ;
if ( V_28 )
F_14 ( V_2 , L_1 , V_28 ) ;
return V_28 ;
}
static T_1 F_15 ( struct V_1 * V_2 , T_4 V_24 , T_4 V_25 )
{
T_1 V_28 ;
V_28 = F_16 ( V_2 , V_24 , V_29 ,
V_25 ) ;
if ( V_28 )
F_14 ( V_2 , L_1 , V_28 ) ;
return V_28 ;
}
static T_1 F_17 ( struct V_1 * V_2 )
{
T_1 V_28 ;
T_2 V_30 ;
T_3 V_25 ;
T_4 V_24 ;
V_28 = F_12 ( V_2 , V_31 , & V_24 ) ;
if ( V_28 )
return V_28 ;
V_24 |= V_32 ;
V_28 = F_15 ( V_2 , V_31 , V_24 ) ;
if ( V_28 )
return V_28 ;
V_28 = F_12 ( V_2 , V_33 , & V_24 ) ;
if ( V_28 )
return V_28 ;
V_24 &= ~ V_32 ;
V_28 = F_15 ( V_2 , V_33 , V_24 ) ;
if ( V_28 )
return V_28 ;
V_28 = F_12 ( V_2 , V_31 , & V_24 ) ;
if ( V_28 )
return V_28 ;
V_24 &= ~ V_32 ;
V_28 = F_15 ( V_2 , V_31 , V_24 ) ;
if ( V_28 )
return V_28 ;
F_18 ( V_34 , V_34 + 100 ) ;
V_28 = F_12 ( V_2 , V_31 , & V_24 ) ;
if ( V_28 )
return V_28 ;
V_24 |= V_32 ;
V_28 = F_15 ( V_2 , V_31 , V_24 ) ;
if ( V_28 )
return V_28 ;
F_19 ( V_35 ) ;
for ( V_30 = 0 ; V_30 < V_36 ; V_30 ++ ) {
V_28 = F_10 ( V_2 , V_37 ,
& V_25 ) ;
if ( ! V_28 && V_25 == V_38 )
break;
F_19 ( V_39 ) ;
}
if ( V_30 == V_36 ) {
F_14 ( V_2 , L_2 ) ;
return V_40 ;
}
V_28 = F_10 ( V_2 , V_41 , & V_25 ) ;
if ( V_28 || ! ( V_25 & V_38 ) ) {
F_14 ( V_2 , L_3 ) ;
return V_40 ;
}
return 0 ;
}
static void F_20 ( struct V_1 * V_2 )
{
T_2 V_42 = V_2 -> V_6 . V_43 ;
T_1 V_28 ;
T_3 V_25 ;
T_4 V_30 ;
for ( V_30 = 0 ; V_30 < V_36 ; V_30 ++ ) {
V_28 = V_2 -> V_4 . V_9 . V_44 ( V_2 , V_42 ) ;
if ( V_28 ) {
F_14 ( V_2 , L_4 , V_28 ) ;
F_19 ( V_39 ) ;
continue;
}
V_28 = F_10 ( V_2 , V_45 , & V_25 ) ;
if ( ! V_28 && V_25 == V_46 )
goto V_47;
if ( V_28 || V_25 != V_48 )
break;
V_2 -> V_4 . V_9 . V_49 ( V_2 , V_42 ) ;
F_19 ( V_39 ) ;
}
if ( V_30 == V_36 ) {
V_28 = V_2 -> V_4 . V_9 . V_44 ( V_2 , V_42 ) ;
if ( V_28 ) {
F_14 ( V_2 , L_4 , V_28 ) ;
return;
}
}
V_28 = F_17 ( V_2 ) ;
if ( V_28 ) {
F_14 ( V_2 , L_5 , V_28 ) ;
goto V_47;
}
F_11 ( V_2 , V_45 ,
V_48 ) ;
V_2 -> V_4 . V_9 . V_49 ( V_2 , V_42 ) ;
F_18 ( 10000 , 12000 ) ;
V_28 = V_2 -> V_4 . V_9 . V_44 ( V_2 , V_42 ) ;
if ( V_28 ) {
F_14 ( V_2 , L_6 , V_28 ) ;
return;
}
V_28 = F_11 ( V_2 , V_45 ,
V_46 ) ;
V_47:
V_2 -> V_4 . V_9 . V_49 ( V_2 , V_42 ) ;
F_19 ( V_2 -> V_50 . V_51 ) ;
}
static T_1 F_21 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_52 ) {
case V_53 :
if ( V_2 -> V_17 . V_18 )
V_2 -> V_6 . V_43 = V_54 ;
else
V_2 -> V_6 . V_43 = V_55 ;
return F_22 ( V_2 ) ;
case V_56 :
V_2 -> V_6 . V_43 = V_57 ;
F_6 ( V_2 ) ;
F_20 ( V_2 ) ;
case V_58 :
return F_22 ( V_2 ) ;
case V_59 :
V_2 -> V_6 . type = V_60 ;
break;
case V_61 :
V_2 -> V_6 . type = V_62 ;
break;
case V_63 :
case V_64 :
case V_65 :
V_2 -> V_6 . type = V_66 ;
break;
case V_67 :
if ( V_2 -> V_17 . V_18 )
V_2 -> V_6 . V_43 = V_54 ;
else
V_2 -> V_6 . V_43 = V_55 ;
case V_68 :
return F_23 ( V_2 ) ;
case V_69 :
V_2 -> V_6 . type = V_70 ;
break;
case V_71 :
case V_72 :
V_2 -> V_6 . type = V_73 ;
V_2 -> V_6 . V_9 . V_74 = NULL ;
V_2 -> V_6 . V_9 . V_75 = NULL ;
if ( V_2 -> V_17 . V_18 )
V_2 -> V_6 . V_43 |= V_54 ;
else
V_2 -> V_6 . V_43 |= V_55 ;
break;
default:
break;
}
return 0 ;
}
static T_1 F_24 ( struct V_1 * V_2 , T_2 V_76 ,
T_2 V_77 , T_3 * V_78 )
{
return V_79 ;
}
static T_1 F_25 ( struct V_1 * V_2 , T_2 V_76 ,
T_2 V_77 , T_3 V_78 )
{
return V_79 ;
}
static T_1 F_26 ( struct V_1 * V_2 , T_4 V_13 ,
T_3 V_24 , T_3 * V_80 )
{
return F_27 ( V_2 , V_13 , V_24 , V_80 , true ) ;
}
static T_1
F_28 ( struct V_1 * V_2 , T_4 V_13 ,
T_3 V_24 , T_3 * V_80 )
{
return F_27 ( V_2 , V_13 , V_24 , V_80 , false ) ;
}
static T_1 F_29 ( struct V_1 * V_2 ,
T_4 V_13 , T_3 V_24 , T_3 V_80 )
{
return F_30 ( V_2 , V_13 , V_24 , V_80 , true ) ;
}
static T_1
F_31 ( struct V_1 * V_2 ,
T_4 V_13 , T_3 V_24 , T_3 V_80 )
{
return F_30 ( V_2 , V_13 , V_24 , V_80 , false ) ;
}
static T_1 F_32 ( struct V_1 * V_2 )
{
T_2 V_81 [ V_82 ] = { 0 } ;
T_3 V_83 ;
T_3 V_84 ;
T_1 V_85 ;
T_3 V_86 ;
if ( V_2 -> V_6 . V_87 )
return 0 ;
V_85 = F_33 ( V_2 , V_88 , & V_81 ) ;
if ( V_85 )
return V_85 ;
V_2 -> V_6 . V_89 = 0 ;
V_83 = V_81 [ 0 ] & V_90 ;
for ( V_86 = 0 ; V_86 < F_34 ( V_91 ) ; ++ V_86 ) {
if ( V_83 & V_91 [ V_86 ] . V_92 )
V_2 -> V_6 . V_89 |= V_91 [ V_86 ] . V_93 ;
}
V_2 -> V_6 . V_87 = V_81 [ 0 ] & V_94 ;
V_84 = V_81 [ 1 ] & V_95 ;
V_2 -> V_6 . V_87 |= V_84 & V_96 ;
V_2 -> V_6 . V_97 = V_84 & ~ V_96 ;
if ( ! V_2 -> V_6 . V_87 || V_2 -> V_6 . V_87 == V_96 )
return V_98 ;
V_2 -> V_6 . V_99 = V_2 -> V_6 . V_89 ;
V_2 -> V_6 . V_100 = V_101 |
V_102 ;
V_2 -> V_6 . V_103 = V_2 -> V_6 . V_100 ;
return 0 ;
}
static T_1 F_35 ( struct V_1 * V_2 )
{
if ( V_2 -> V_17 . V_18 )
V_2 -> V_6 . V_43 = V_54 ;
else
V_2 -> V_6 . V_43 = V_55 ;
V_2 -> V_6 . type = V_73 ;
V_2 -> V_6 . V_9 . V_74 = NULL ;
V_2 -> V_6 . V_9 . V_75 = NULL ;
return F_32 ( V_2 ) ;
}
static T_1 F_36 ( struct V_1 * V_2 )
{
T_2 V_104 [ V_82 ] = { 0 } ;
V_104 [ 0 ] = V_105 ;
return F_33 ( V_2 , V_106 , & V_104 ) ;
}
static T_1 F_37 ( struct V_1 * V_2 )
{
T_2 V_104 [ V_82 ] = { 0 } ;
T_1 V_85 ;
T_3 V_86 ;
if ( V_2 -> V_6 . V_107 || F_38 ( V_2 ) )
return 0 ;
if ( V_2 -> V_108 . V_109 && V_2 -> V_108 . V_110 == V_111 ) {
F_14 ( V_2 , L_7 ) ;
return V_112 ;
}
switch ( V_2 -> V_108 . V_110 ) {
case V_113 :
V_104 [ 0 ] |= V_114 <<
V_115 ;
break;
case V_111 :
V_104 [ 0 ] |= V_116 <<
V_115 ;
break;
case V_117 :
V_104 [ 0 ] |= V_118 <<
V_115 ;
break;
default:
break;
}
for ( V_86 = 0 ; V_86 < F_34 ( V_91 ) ; ++ V_86 ) {
if ( V_2 -> V_6 . V_99 & V_91 [ V_86 ] . V_93 )
V_104 [ 0 ] |= V_91 [ V_86 ] . V_92 ;
}
V_104 [ 0 ] |= V_119 | V_120 ;
if ( V_2 -> V_6 . V_103 )
V_104 [ 0 ] |= V_121 ;
V_85 = F_33 ( V_2 , V_122 , & V_104 ) ;
if ( V_85 )
return V_85 ;
if ( V_104 [ 0 ] == V_123 )
return V_124 ;
return 0 ;
}
static T_1 F_39 ( struct V_1 * V_2 )
{
if ( V_2 -> V_108 . V_110 == V_125 )
V_2 -> V_108 . V_110 = V_113 ;
return F_37 ( V_2 ) ;
}
static T_1 F_40 ( struct V_1 * V_2 )
{
struct V_126 * V_50 = & V_2 -> V_50 ;
T_2 V_127 ;
T_3 V_128 ;
if ( V_50 -> type == V_129 ) {
V_50 -> V_51 = 10 ;
V_50 -> type = V_130 ;
V_127 = F_7 ( V_2 , F_41 ( V_2 ) ) ;
V_128 = ( T_3 ) ( ( V_127 & V_131 ) >>
V_132 ) ;
V_50 -> V_133 = F_42 ( V_128 +
V_134 ) ;
F_43 ( V_2 , L_8 ,
V_50 -> type , V_50 -> V_133 ) ;
}
return 0 ;
}
static T_1 F_44 ( struct V_1 * V_2 , T_2 * V_135 )
{
T_2 V_86 , V_136 ;
for ( V_86 = 0 ; V_86 < V_137 ; V_86 ++ ) {
V_136 = F_7 ( V_2 , V_138 ) ;
if ( ! ( V_136 & V_139 ) )
break;
F_45 ( 10 ) ;
}
if ( V_135 )
* V_135 = V_136 ;
if ( V_86 == V_137 ) {
F_43 ( V_2 , L_9 ) ;
return V_40 ;
}
return 0 ;
}
static T_1 F_46 ( struct V_1 * V_2 , T_2 V_76 ,
T_2 V_77 , T_2 * V_140 )
{
T_2 V_141 = V_54 | V_55 ;
T_2 V_136 , error ;
T_1 V_142 ;
V_142 = V_2 -> V_4 . V_9 . V_44 ( V_2 , V_141 ) ;
if ( V_142 )
return V_142 ;
V_142 = F_44 ( V_2 , NULL ) ;
if ( V_142 )
goto V_47;
V_136 = ( ( V_76 << V_143 ) |
( V_77 << V_144 ) ) ;
F_8 ( V_2 , V_138 , V_136 ) ;
V_142 = F_44 ( V_2 , & V_136 ) ;
if ( ( V_136 & V_145 ) != 0 ) {
error = ( V_136 & V_146 ) >>
V_147 ;
F_43 ( V_2 , L_10 , error ) ;
return V_40 ;
}
if ( ! V_142 )
* V_140 = F_7 ( V_2 , V_148 ) ;
V_47:
V_2 -> V_4 . V_9 . V_49 ( V_2 , V_141 ) ;
return V_142 ;
}
static T_1 F_47 ( struct V_1 * V_2 )
{
struct V_149 V_150 ;
T_1 V_28 ;
V_150 . V_151 . V_152 = V_153 ;
V_150 . V_151 . V_154 = V_155 ;
V_150 . V_151 . V_156 . V_157 = 0 ;
V_150 . V_151 . V_158 = V_159 ;
V_150 . V_160 = V_2 -> V_17 . V_18 ;
V_150 . V_161 = V_162 ;
V_150 . V_163 = 0 ;
V_28 = F_48 ( V_2 , & V_150 , sizeof( V_150 ) ,
V_164 ,
true ) ;
if ( V_28 )
return V_28 ;
if ( V_150 . V_151 . V_156 . V_165 == V_166 )
return 0 ;
if ( V_150 . V_151 . V_156 . V_165 != V_167 )
return V_168 ;
return V_169 ;
}
static T_1 F_49 ( struct V_1 * V_2 )
{
struct V_149 V_150 ;
T_1 V_28 ;
V_150 . V_151 . V_152 = V_153 ;
V_150 . V_151 . V_154 = V_155 ;
V_150 . V_151 . V_156 . V_157 = 0 ;
V_150 . V_151 . V_158 = V_159 ;
V_150 . V_160 = V_2 -> V_17 . V_18 ;
V_150 . V_161 = V_170 ;
V_150 . V_163 = 0 ;
V_28 = F_48 ( V_2 , & V_150 , sizeof( V_150 ) ,
V_164 ,
true ) ;
if ( V_28 )
return V_28 ;
if ( V_150 . V_151 . V_156 . V_165 == V_166 )
return 0 ;
return V_168 ;
}
static T_1 F_50 ( struct V_1 * V_2 , T_2 V_76 ,
T_5 T_2 V_77 ,
T_2 V_140 )
{
struct V_171 V_172 ;
memset ( & V_172 , 0 , sizeof( V_172 ) ) ;
V_172 . V_151 . V_152 = V_173 ;
V_172 . V_151 . V_154 = V_174 ;
V_172 . V_151 . V_158 = V_159 ;
V_172 . V_160 = V_2 -> V_17 . V_18 ;
V_172 . V_161 = V_175 ;
V_172 . V_176 = F_51 ( V_76 ) ;
V_172 . V_177 = F_52 ( V_140 ) ;
return F_48 ( V_2 , & V_172 , sizeof( V_172 ) ,
V_164 , false ) ;
}
static T_1 F_53 ( struct V_1 * V_2 , T_2 V_76 ,
T_5 T_2 V_77 ,
T_2 * V_140 )
{
union {
struct V_171 V_152 ;
struct V_178 V_179 ;
} V_180 ;
T_1 V_28 ;
memset ( & V_180 , 0 , sizeof( V_180 ) ) ;
V_180 . V_152 . V_151 . V_152 = V_173 ;
V_180 . V_152 . V_151 . V_154 = V_174 ;
V_180 . V_152 . V_151 . V_158 = V_159 ;
V_180 . V_152 . V_160 = V_2 -> V_17 . V_18 ;
V_180 . V_152 . V_161 = V_181 ;
V_180 . V_152 . V_176 = F_51 ( V_76 ) ;
V_28 = F_48 ( V_2 , & V_180 . V_152 , sizeof( V_180 . V_152 ) ,
V_164 , true ) ;
* V_140 = F_54 ( V_180 . V_179 . V_182 ) ;
return V_28 ;
}
static T_1 F_55 ( struct V_1 * V_2 ,
T_3 V_183 , T_3 V_184 , T_3 * V_140 )
{
const T_2 V_185 = V_186 | V_187 ;
struct V_188 V_189 ;
T_2 V_190 = 0 ;
T_3 V_191 ;
T_1 V_28 ;
T_2 V_86 ;
V_28 = V_2 -> V_4 . V_9 . V_44 ( V_2 , V_185 ) ;
if ( V_28 ) {
F_43 ( V_2 , L_11 ) ;
return V_28 ;
}
while ( V_184 ) {
if ( V_184 > V_192 / 2 )
V_191 = V_192 / 2 ;
else
V_191 = V_184 ;
V_189 . V_151 . V_193 . V_152 = V_194 ;
V_189 . V_151 . V_193 . V_195 = 0 ;
V_189 . V_151 . V_193 . V_196 = V_197 ;
V_189 . V_151 . V_193 . V_158 = V_159 ;
V_189 . V_176 = F_52 ( ( V_183 + V_190 ) * 2 ) ;
V_189 . V_198 = F_51 ( V_191 * 2 ) ;
V_28 = F_56 ( V_2 , ( T_2 * ) & V_189 , sizeof( V_189 ) ,
V_164 ) ;
if ( V_28 ) {
F_43 ( V_2 , L_12 ) ;
goto V_47;
}
for ( V_86 = 0 ; V_86 < V_191 ; V_86 ++ ) {
T_2 V_24 = V_199 + ( V_200 << 2 ) +
2 * V_86 ;
T_2 V_25 = F_7 ( V_2 , V_24 ) ;
V_140 [ V_190 ] = ( T_3 ) ( V_25 & 0xffff ) ;
V_190 ++ ;
V_86 ++ ;
if ( V_86 < V_191 ) {
V_25 >>= 16 ;
V_140 [ V_190 ] = ( T_3 ) ( V_25 & 0xffff ) ;
V_190 ++ ;
}
}
V_184 -= V_191 ;
}
V_47:
V_2 -> V_4 . V_9 . V_49 ( V_2 , V_185 ) ;
return V_28 ;
}
static T_1 F_57 ( struct V_1 * V_2 , T_3 V_201 ,
T_3 V_202 , T_3 * V_203 , T_3 * V_189 ,
T_2 V_204 )
{
T_3 V_205 [ 256 ] ;
T_1 V_28 ;
T_3 V_198 , V_206 , V_86 , V_207 ;
T_3 * V_208 ;
V_206 = sizeof( V_205 ) / sizeof( V_205 [ 0 ] ) ;
if ( ! V_189 ) {
V_28 = F_55 ( V_2 , V_201 , V_206 , V_205 ) ;
if ( V_28 ) {
F_43 ( V_2 , L_13 ) ;
return V_28 ;
}
V_208 = V_205 ;
} else {
if ( V_204 < V_201 )
return V_209 ;
V_208 = & V_189 [ V_201 ] ;
}
if ( V_202 ) {
V_207 = 0 ;
V_198 = V_202 ;
} else {
V_207 = 1 ;
V_198 = V_208 [ 0 ] ;
if ( V_198 == 0xFFFF || V_198 == 0 ||
( V_201 + V_198 ) >= V_2 -> V_50 . V_133 )
return 0 ;
}
if ( V_189 && ( ( T_2 ) V_207 + ( T_2 ) V_198 > V_204 ) )
return V_209 ;
for ( V_86 = V_207 ; V_198 ; V_86 ++ , V_198 -- ) {
if ( V_86 == V_206 && ! V_189 ) {
V_201 += V_206 ;
V_86 = 0 ;
if ( V_198 < V_206 )
V_206 = V_198 ;
V_28 = F_55 ( V_2 , V_201 ,
V_206 , V_205 ) ;
if ( V_28 ) {
F_43 ( V_2 , L_13 ) ;
return V_28 ;
}
}
* V_203 += V_208 [ V_86 ] ;
}
return 0 ;
}
static T_1 F_58 ( struct V_1 * V_2 , T_3 * V_189 ,
T_2 V_204 )
{
T_3 V_210 [ V_211 + 1 ] ;
T_3 * V_208 ;
T_1 V_28 ;
T_3 V_158 = 0 ;
T_3 V_212 , V_86 , V_202 ;
V_2 -> V_50 . V_9 . V_213 ( V_2 ) ;
if ( ! V_189 ) {
V_28 = F_55 ( V_2 , 0 ,
V_211 + 1 ,
V_210 ) ;
if ( V_28 ) {
F_43 ( V_2 , L_13 ) ;
return V_28 ;
}
V_208 = V_210 ;
} else {
if ( V_204 < V_211 )
return V_209 ;
V_208 = V_189 ;
}
for ( V_86 = 0 ; V_86 <= V_211 ; V_86 ++ )
if ( V_86 != V_214 )
V_158 += V_208 [ V_86 ] ;
for ( V_86 = V_215 ; V_86 < V_216 ; V_86 ++ ) {
if ( V_86 == V_217 || V_86 == V_218 )
continue;
V_212 = V_208 [ V_86 ] ;
if ( V_212 == 0xFFFF || V_212 == 0 ||
V_212 >= V_2 -> V_50 . V_133 )
continue;
switch ( V_86 ) {
case V_219 :
V_202 = V_220 ;
break;
case V_221 :
case V_222 :
V_202 = V_223 ;
break;
default:
V_202 = 0 ;
break;
}
V_28 = F_57 ( V_2 , V_212 , V_202 , & V_158 ,
V_189 , V_204 ) ;
if ( V_28 )
return V_28 ;
}
V_158 = ( T_3 ) V_224 - V_158 ;
return ( T_1 ) V_158 ;
}
static T_1 F_59 ( struct V_1 * V_2 )
{
return F_58 ( V_2 , NULL , 0 ) ;
}
static T_1 F_60 ( struct V_1 * V_2 , T_3 V_183 , T_3 * V_140 )
{
const T_2 V_185 = V_186 | V_187 ;
struct V_188 V_189 ;
T_1 V_28 ;
V_189 . V_151 . V_193 . V_152 = V_194 ;
V_189 . V_151 . V_193 . V_195 = 0 ;
V_189 . V_151 . V_193 . V_196 = V_197 ;
V_189 . V_151 . V_193 . V_158 = V_159 ;
V_189 . V_176 = F_52 ( V_183 * 2 ) ;
V_189 . V_198 = F_51 ( sizeof( T_3 ) ) ;
V_28 = V_2 -> V_4 . V_9 . V_44 ( V_2 , V_185 ) ;
if ( V_28 )
return V_28 ;
V_28 = F_56 ( V_2 , ( T_2 * ) & V_189 , sizeof( V_189 ) ,
V_164 ) ;
if ( ! V_28 ) {
* V_140 = ( T_3 ) F_61 ( V_2 , V_199 ,
V_200 ) ;
}
V_2 -> V_4 . V_9 . V_49 ( V_2 , V_185 ) ;
return V_28 ;
}
static T_1 F_62 ( struct V_1 * V_2 ,
T_3 * V_225 )
{
T_1 V_28 ;
T_3 V_158 ;
T_3 V_226 = 0 ;
V_28 = V_2 -> V_50 . V_9 . V_227 ( V_2 , 0 , & V_158 ) ;
if ( V_28 ) {
F_43 ( V_2 , L_14 ) ;
return V_28 ;
}
V_28 = V_2 -> V_50 . V_9 . V_228 ( V_2 ) ;
if ( V_28 < 0 )
return V_28 ;
V_158 = ( T_3 ) ( V_28 & 0xffff ) ;
V_28 = F_60 ( V_2 , V_214 ,
& V_226 ) ;
if ( V_28 )
return V_28 ;
if ( V_226 != V_158 ) {
V_28 = V_229 ;
F_43 ( V_2 , L_15 ) ;
}
if ( V_225 )
* V_225 = V_158 ;
return V_28 ;
}
static T_1 F_63 ( struct V_1 * V_2 , T_3 V_183 ,
T_3 V_140 )
{
T_1 V_28 ;
struct V_230 V_189 ;
V_189 . V_151 . V_193 . V_152 = V_231 ;
V_189 . V_151 . V_193 . V_195 = 0 ;
V_189 . V_151 . V_193 . V_196 = V_232 ;
V_189 . V_151 . V_193 . V_158 = V_159 ;
V_189 . V_198 = F_51 ( sizeof( T_3 ) ) ;
V_189 . V_140 = V_140 ;
V_189 . V_176 = F_52 ( V_183 * 2 ) ;
V_28 = F_48 ( V_2 , & V_189 , sizeof( V_189 ) ,
V_164 , false ) ;
return V_28 ;
}
static T_1 F_64 ( struct V_1 * V_2 , T_3 V_183 , T_3 V_140 )
{
T_1 V_28 = 0 ;
if ( V_2 -> V_4 . V_9 . V_44 ( V_2 , V_187 ) == 0 ) {
V_28 = F_63 ( V_2 , V_183 , V_140 ) ;
V_2 -> V_4 . V_9 . V_49 ( V_2 , V_187 ) ;
} else {
F_43 ( V_2 , L_16 ) ;
V_28 = V_233 ;
}
return V_28 ;
}
static T_1 F_65 ( struct V_1 * V_2 )
{
T_1 V_28 = 0 ;
union V_234 V_189 ;
V_189 . V_193 . V_152 = V_235 ;
V_189 . V_193 . V_195 = 0 ;
V_189 . V_193 . V_196 = V_236 ;
V_189 . V_193 . V_158 = V_159 ;
V_28 = F_48 ( V_2 , & V_189 , sizeof( V_189 ) ,
V_164 , false ) ;
return V_28 ;
}
static T_1 F_66 ( struct V_1 * V_2 )
{
V_2 -> V_17 . type = V_237 ;
V_2 -> V_17 . V_238 = V_239 ;
V_2 -> V_17 . V_240 = V_241 ;
V_2 -> V_4 . V_9 . V_242 ( V_2 ) ;
return 0 ;
}
static void F_67 ( struct V_1 * V_2 )
{
T_2 V_243 , V_244 ;
T_1 V_28 ;
struct V_245 V_246 ;
V_243 = F_7 ( V_2 , V_247 ) ;
if ( V_243 & V_248 ) {
V_244 = F_7 ( V_2 , V_249 ) ;
if ( V_244 & V_250 ) {
V_244 &= ~ V_250 ;
F_8 ( V_2 , V_249 , V_244 ) ;
V_2 -> V_4 . V_251 = true ;
} else {
V_2 -> V_4 . V_251 = false ;
}
V_246 . V_151 . V_152 = V_252 ;
V_246 . V_151 . V_154 = V_253 ;
V_246 . V_151 . V_158 = V_159 ;
V_246 . V_160 = V_2 -> V_17 . V_18 ;
V_28 = F_48 ( V_2 , & V_246 ,
sizeof( struct V_245 ) ,
V_164 , true ) ;
if ( V_28 ) {
V_243 = F_7 ( V_2 , V_247 ) ;
if ( V_243 & V_248 ) {
V_243 &= ~ V_248 ;
F_8 ( V_2 , V_247 , V_243 ) ;
}
}
}
}
static T_1 F_68 ( struct V_1 * V_2 )
{
T_1 V_28 ;
T_3 V_158 = 0 ;
V_28 = F_60 ( V_2 , 0 , & V_158 ) ;
if ( V_28 ) {
F_43 ( V_2 , L_14 ) ;
return V_28 ;
}
V_28 = F_59 ( V_2 ) ;
if ( V_28 < 0 )
return V_28 ;
V_158 = ( T_3 ) ( V_28 & 0xffff ) ;
V_28 = F_64 ( V_2 , V_214 ,
V_158 ) ;
if ( V_28 )
return V_28 ;
V_28 = F_65 ( V_2 ) ;
return V_28 ;
}
static T_1 F_69 ( struct V_1 * V_2 ,
T_3 V_183 , T_3 V_184 ,
T_3 * V_140 )
{
T_1 V_28 = 0 ;
T_2 V_86 = 0 ;
V_28 = V_2 -> V_4 . V_9 . V_44 ( V_2 , V_187 ) ;
if ( V_28 ) {
F_43 ( V_2 , L_17 ) ;
return V_28 ;
}
for ( V_86 = 0 ; V_86 < V_184 ; V_86 ++ ) {
V_28 = F_63 ( V_2 , V_183 + V_86 ,
V_140 [ V_86 ] ) ;
if ( V_28 ) {
F_43 ( V_2 , L_18 ) ;
break;
}
}
V_2 -> V_4 . V_9 . V_49 ( V_2 , V_187 ) ;
return V_28 ;
}
static T_1 F_70 ( struct V_1 * V_2 , T_2 V_76 ,
T_2 V_77 , T_2 V_140 )
{
T_2 V_141 = V_54 | V_55 ;
T_2 V_136 , error ;
T_1 V_142 ;
V_142 = V_2 -> V_4 . V_9 . V_44 ( V_2 , V_141 ) ;
if ( V_142 )
return V_142 ;
V_142 = F_44 ( V_2 , NULL ) ;
if ( V_142 )
goto V_47;
V_136 = ( ( V_76 << V_143 ) |
( V_77 << V_144 ) ) ;
F_8 ( V_2 , V_138 , V_136 ) ;
F_8 ( V_2 , V_148 , V_140 ) ;
V_142 = F_44 ( V_2 , & V_136 ) ;
if ( ( V_136 & V_145 ) != 0 ) {
error = ( V_136 & V_146 ) >>
V_147 ;
F_43 ( V_2 , L_19 , error ) ;
return V_40 ;
}
V_47:
V_2 -> V_4 . V_9 . V_49 ( V_2 , V_141 ) ;
return V_142 ;
}
static T_1 F_71 ( struct V_1 * V_2 )
{
T_1 V_28 ;
T_2 V_254 ;
V_28 = F_46 ( V_2 ,
F_72 ( V_2 -> V_17 . V_18 ) ,
V_255 , & V_254 ) ;
if ( V_28 )
return V_28 ;
V_254 |= V_256 ;
V_28 = F_70 ( V_2 ,
F_72 ( V_2 -> V_17 . V_18 ) ,
V_255 , V_254 ) ;
if ( V_28 )
return V_28 ;
V_28 = F_46 ( V_2 ,
F_73 ( V_2 -> V_17 . V_18 ) ,
V_255 , & V_254 ) ;
if ( V_28 )
return V_28 ;
V_254 &= ~ V_257 ;
V_254 &= ~ V_258 ;
V_254 &= ~ V_259 ;
V_28 = F_70 ( V_2 ,
F_73 ( V_2 -> V_17 . V_18 ) ,
V_255 , V_254 ) ;
if ( V_28 )
return V_28 ;
V_28 = F_46 ( V_2 ,
F_74 ( V_2 -> V_17 . V_18 ) ,
V_255 , & V_254 ) ;
if ( V_28 )
return V_28 ;
V_254 &= ~ V_257 ;
V_254 &= ~ V_258 ;
V_254 &= ~ V_259 ;
V_28 = F_70 ( V_2 ,
F_74 ( V_2 -> V_17 . V_18 ) ,
V_255 , V_254 ) ;
if ( V_28 )
return V_28 ;
V_28 = F_46 ( V_2 ,
F_75 ( V_2 -> V_17 . V_18 ) ,
V_255 , & V_254 ) ;
if ( V_28 )
return V_28 ;
V_254 |= V_260 ;
V_254 |= V_261 ;
V_254 |= V_262 ;
V_254 |= V_263 ;
V_28 = F_70 ( V_2 ,
F_75 ( V_2 -> V_17 . V_18 ) ,
V_255 , V_254 ) ;
return V_28 ;
}
static T_1 F_76 ( struct V_1 * V_2 )
{
T_1 V_28 ;
T_2 V_264 ;
V_28 = V_2 -> V_4 . V_9 . V_265 ( V_2 ,
F_77 ( V_2 -> V_17 . V_18 ) ,
V_255 , & V_264 ) ;
if ( V_28 ) {
F_43 ( V_2 , L_20 ) ;
return V_28 ;
}
V_264 |= V_266 ;
V_28 = V_2 -> V_4 . V_9 . V_267 ( V_2 ,
F_77 ( V_2 -> V_17 . V_18 ) ,
V_255 , V_264 ) ;
if ( V_2 -> V_4 . type == V_268 ) {
T_2 V_269 ;
V_28 = V_2 -> V_4 . V_9 . V_265 ( V_2 ,
F_78 ( V_2 -> V_17 . V_18 ) ,
V_255 , & V_269 ) ;
if ( V_28 ) {
F_43 ( V_2 , L_20 ) ;
return V_28 ;
}
V_269 |= V_270 ;
V_28 = V_2 -> V_4 . V_9 . V_267 ( V_2 ,
F_78 ( V_2 -> V_17 . V_18 ) ,
V_255 , V_269 ) ;
}
return V_28 ;
}
static T_1 F_79 ( struct V_1 * V_2 , T_6 * V_240 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
T_1 V_28 ;
T_2 V_254 ;
if ( V_4 -> type != V_271 )
return V_272 ;
V_28 = F_46 ( V_2 ,
F_77 ( V_2 -> V_17 . V_18 ) ,
V_255 , & V_254 ) ;
if ( V_28 )
return V_28 ;
V_254 &= ~ V_273 ;
V_254 &= ~ V_274 ;
switch ( * V_240 ) {
case V_275 :
V_254 |= V_276 ;
break;
case V_102 :
V_254 |= V_277 ;
break;
default:
return V_272 ;
}
V_28 = F_70 ( V_2 ,
F_77 ( V_2 -> V_17 . V_18 ) ,
V_255 , V_254 ) ;
if ( V_28 )
return V_28 ;
if ( V_2 -> V_4 . type == V_271 ) {
V_28 = F_71 ( V_2 ) ;
if ( V_28 )
return V_28 ;
}
V_28 = F_76 ( V_2 ) ;
return V_28 ;
}
static T_1 F_80 ( struct V_1 * V_2 , bool * V_278 )
{
switch ( V_2 -> V_6 . V_279 ) {
case V_280 :
return V_281 ;
case V_282 :
case V_283 :
* V_278 = true ;
break;
case V_284 :
case V_285 :
case V_286 :
case V_287 :
case V_288 :
case V_289 :
case V_290 :
case V_291 :
* V_278 = false ;
break;
case V_292 :
case V_293 :
case V_294 :
default:
return V_295 ;
}
return 0 ;
}
static T_1
F_81 ( struct V_1 * V_2 ,
T_6 V_240 ,
T_5 bool V_296 )
{
T_1 V_28 ;
T_3 V_297 , V_254 ;
bool V_298 = false ;
V_28 = F_80 ( V_2 , & V_298 ) ;
if ( V_28 == V_281 )
return 0 ;
if ( V_28 )
return V_28 ;
F_82 ( V_2 , V_240 ) ;
V_297 = V_299 + ( V_2 -> V_17 . V_18 << 12 ) ;
if ( V_298 )
V_254 = ( V_300 << 1 ) | 0x1 ;
else
V_254 = ( V_301 << 1 ) | 0x1 ;
V_28 = V_2 -> V_8 . V_9 . V_302 ( V_2 , V_2 -> V_8 . V_13 , V_297 ,
V_254 ) ;
return V_28 ;
}
static T_1 F_83 ( struct V_1 * V_2 , T_6 * V_240 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
T_1 V_28 ;
T_2 V_254 ;
V_28 = V_4 -> V_9 . V_265 ( V_2 ,
F_78 ( V_2 -> V_17 . V_18 ) ,
V_255 , & V_254 ) ;
if ( V_28 )
return V_28 ;
V_254 &= ~ V_303 ;
V_254 &= ~ V_304 ;
V_254 &= ~ V_305 ;
V_254 &= ~ V_306 ;
switch ( * V_240 ) {
case V_275 :
V_254 |= V_307 ;
break;
case V_102 :
V_254 |= V_308 ;
break;
default:
return V_272 ;
}
V_28 = V_4 -> V_9 . V_267 ( V_2 ,
F_78 ( V_2 -> V_17 . V_18 ) ,
V_255 , V_254 ) ;
V_28 = F_76 ( V_2 ) ;
return V_28 ;
}
static T_1
F_84 ( struct V_1 * V_2 , T_6 V_240 ,
T_5 bool V_296 )
{
bool V_298 = false ;
T_2 V_309 ;
T_1 V_310 ;
V_310 = F_80 ( V_2 , & V_298 ) ;
if ( V_310 == V_281 )
return 0 ;
if ( V_310 )
return V_310 ;
V_310 = V_2 -> V_4 . V_9 . V_265 ( V_2 ,
F_78 ( V_2 -> V_17 . V_18 ) ,
V_255 , & V_309 ) ;
if ( V_310 )
return V_310 ;
V_309 &= V_311 ;
if ( ! V_298 )
V_309 |= V_312 ;
V_310 = V_2 -> V_4 . V_9 . V_267 ( V_2 ,
F_78 ( V_2 -> V_17 . V_18 ) ,
V_255 , V_309 ) ;
if ( V_310 )
return V_310 ;
return F_83 ( V_2 , & V_240 ) ;
}
static T_1
F_85 ( struct V_1 * V_2 , T_6 V_240 ,
T_5 bool V_296 )
{
T_2 V_297 , V_313 ;
bool V_298 = false ;
T_3 V_314 ;
T_1 V_310 ;
V_310 = F_80 ( V_2 , & V_298 ) ;
if ( V_310 == V_281 )
return 0 ;
if ( V_310 )
return V_310 ;
F_82 ( V_2 , V_240 ) ;
if ( V_2 -> V_6 . V_315 . V_316 == V_317 )
return V_98 ;
V_310 = V_2 -> V_6 . V_9 . V_74 ( V_2 , V_318 ,
V_319 , & V_314 ) ;
if ( V_310 )
return V_310 ;
if ( V_314 == V_320 )
V_313 = ( V_2 -> V_17 . V_18 +
( V_2 -> V_17 . V_321 << 1 ) ) << 12 ;
else
V_313 = V_2 -> V_17 . V_18 << 12 ;
V_297 = V_299 + V_313 ;
V_310 = V_2 -> V_6 . V_9 . V_74 ( V_2 , V_297 ,
V_319 , & V_314 ) ;
if ( V_310 )
return V_310 ;
V_314 &= ~ ( ( V_300 << 1 ) |
( V_301 << 1 ) ) ;
if ( V_298 )
V_314 = ( V_300 << 1 ) | 1 ;
else
V_314 = ( V_301 << 1 ) | 1 ;
V_310 = V_2 -> V_6 . V_9 . V_75 ( V_2 , V_297 ,
V_319 , V_314 ) ;
if ( V_310 )
return V_310 ;
return V_2 -> V_6 . V_9 . V_74 ( V_2 , V_297 ,
V_319 , & V_314 ) ;
}
static T_1 F_86 ( struct V_1 * V_2 ,
T_6 V_240 ,
bool V_322 )
{
T_1 V_28 ;
T_6 V_323 ;
if ( V_240 & V_275 )
V_323 = V_275 ;
else
V_323 = V_102 ;
if ( V_2 -> V_4 . type == V_271 &&
! ( V_2 -> V_6 . V_324 & V_325 ) ) {
V_28 = F_79 ( V_2 , & V_323 ) ;
if ( V_28 )
return V_28 ;
}
return V_2 -> V_6 . V_9 . V_326 ( V_2 , V_240 , V_322 ) ;
}
static T_1 F_87 ( struct V_1 * V_2 ,
T_6 * V_240 ,
bool * V_327 ,
bool V_328 )
{
T_2 V_28 ;
T_3 V_86 , V_329 ;
if ( V_2 -> V_4 . V_9 . V_10 ( V_2 ) != V_11 )
return V_330 ;
V_28 = F_88 ( V_2 , V_240 , V_327 ,
V_328 ) ;
if ( V_28 || ! ( * V_327 ) )
return V_28 ;
for ( V_86 = 0 ; V_86 < 2 ; V_86 ++ ) {
V_28 = V_2 -> V_6 . V_9 . V_74 ( V_2 , V_331 , V_332 ,
& V_329 ) ;
if ( V_28 )
return V_28 ;
}
if ( ! ( V_329 & V_333 ) )
* V_327 = false ;
return 0 ;
}
static T_1
F_89 ( struct V_1 * V_2 , T_5 T_6 V_240 ,
T_5 bool V_296 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
T_2 V_334 , V_335 , V_336 ;
T_1 V_85 ;
V_85 = V_4 -> V_9 . V_265 ( V_2 ,
F_77 ( V_2 -> V_17 . V_18 ) ,
V_255 , & V_334 ) ;
if ( V_85 )
return V_85 ;
V_334 &= ~ V_273 ;
V_334 &= ~ V_274 ;
V_334 |= V_337 ;
V_334 |= V_338 ;
V_334 |= V_277 ;
V_85 = V_4 -> V_9 . V_267 ( V_2 ,
F_77 ( V_2 -> V_17 . V_18 ) ,
V_255 , V_334 ) ;
if ( V_85 )
return V_85 ;
V_85 = V_4 -> V_9 . V_265 ( V_2 ,
F_90 ( V_2 -> V_17 . V_18 ) ,
V_255 , & V_335 ) ;
if ( V_85 )
return V_85 ;
V_335 |= V_339 ;
V_335 |= V_340 ;
V_85 = V_4 -> V_9 . V_267 ( V_2 ,
F_90 ( V_2 -> V_17 . V_18 ) ,
V_255 , V_335 ) ;
if ( V_85 )
return V_85 ;
V_85 = V_4 -> V_9 . V_265 ( V_2 ,
F_78 ( V_2 -> V_17 . V_18 ) ,
V_255 , & V_336 ) ;
if ( V_85 )
return V_85 ;
V_85 = V_4 -> V_9 . V_265 ( V_2 ,
F_78 ( V_2 -> V_17 . V_18 ) ,
V_255 , & V_336 ) ;
if ( V_85 )
return V_85 ;
V_336 &= ~ V_306 ;
V_336 |= V_308 ;
V_336 &= ~ V_303 ;
V_336 |= V_305 ;
V_336 |= V_304 ;
V_85 = V_4 -> V_9 . V_267 ( V_2 ,
F_78 ( V_2 -> V_17 . V_18 ) ,
V_255 , V_336 ) ;
if ( V_85 )
return V_85 ;
V_85 = F_76 ( V_2 ) ;
return V_85 ;
}
static T_1 F_91 ( struct V_1 * V_2 , T_6 V_240 ,
bool V_322 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
T_2 V_334 , V_335 , V_336 ;
T_1 V_85 ;
V_85 = V_4 -> V_9 . V_265 ( V_2 ,
F_77 ( V_2 -> V_17 . V_18 ) ,
V_255 , & V_334 ) ;
if ( V_85 )
return V_85 ;
V_334 &= ~ V_273 ;
V_334 &= ~ V_274 ;
V_334 |= V_337 ;
V_334 |= V_338 ;
V_334 &= ~ V_277 ;
V_85 = V_4 -> V_9 . V_267 ( V_2 ,
F_77 ( V_2 -> V_17 . V_18 ) ,
V_255 , V_334 ) ;
if ( V_85 )
return V_85 ;
V_85 = V_4 -> V_9 . V_265 ( V_2 ,
F_90 ( V_2 -> V_17 . V_18 ) ,
V_255 , & V_335 ) ;
if ( V_85 )
return V_85 ;
V_335 &= ~ V_339 ;
V_335 &= ~ V_340 ;
V_85 = V_4 -> V_9 . V_267 ( V_2 ,
F_90 ( V_2 -> V_17 . V_18 ) ,
V_255 , V_335 ) ;
if ( V_85 )
return V_85 ;
V_85 = V_4 -> V_9 . V_267 ( V_2 ,
F_77 ( V_2 -> V_17 . V_18 ) ,
V_255 , V_334 ) ;
if ( V_85 )
return V_85 ;
V_85 = V_4 -> V_9 . V_265 ( V_2 ,
F_78 ( V_2 -> V_17 . V_18 ) ,
V_255 , & V_336 ) ;
if ( V_85 )
return V_85 ;
V_336 &= ~ V_306 ;
V_336 |= V_341 ;
V_336 &= ~ V_303 ;
V_336 |= V_305 ;
V_336 |= V_304 ;
V_85 = V_4 -> V_9 . V_267 ( V_2 ,
F_78 ( V_2 -> V_17 . V_18 ) ,
V_255 , V_336 ) ;
if ( V_85 )
return V_85 ;
F_76 ( V_2 ) ;
return V_2 -> V_6 . V_9 . V_326 ( V_2 , V_240 , V_322 ) ;
}
static void F_92 ( struct V_1 * V_2 )
{
T_1 V_28 = V_342 ;
T_2 V_81 [ V_82 ] = { 0 } ;
T_6 V_240 ;
bool V_327 ;
if ( V_2 -> V_108 . V_343 )
goto V_47;
V_2 -> V_4 . V_9 . V_344 ( V_2 , & V_240 , & V_327 , false ) ;
if ( ! V_327 )
goto V_47;
V_28 = F_33 ( V_2 , V_345 , & V_81 ) ;
if ( V_28 || ! ( V_81 [ 0 ] & V_346 ) ) {
V_28 = V_342 ;
goto V_47;
}
V_28 = F_93 ( V_2 , V_81 [ 0 ] , V_81 [ 0 ] ,
V_347 ,
V_348 ,
V_349 ,
V_350 ) ;
V_47:
if ( ! V_28 ) {
V_2 -> V_108 . V_351 = true ;
} else {
V_2 -> V_108 . V_351 = false ;
V_2 -> V_108 . V_352 = V_2 -> V_108 . V_110 ;
}
}
static void F_94 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
switch ( V_4 -> V_9 . V_10 ( V_2 ) ) {
case V_353 :
V_4 -> V_9 . V_354 = NULL ;
V_4 -> V_9 . V_355 = V_356 ;
break;
case V_11 :
if ( V_2 -> V_52 != V_71 &&
V_2 -> V_52 != V_72 ) {
V_4 -> V_9 . V_357 = F_86 ;
break;
}
V_4 -> V_9 . V_355 = F_92 ;
V_4 -> V_9 . V_354 = F_39 ;
V_4 -> V_9 . V_357 = F_91 ;
V_4 -> V_9 . V_344 = F_88 ;
break;
case V_358 :
V_4 -> V_9 . V_355 = V_359 ;
V_4 -> V_9 . V_354 = V_360 ;
break;
default:
break;
}
}
static void F_95 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
V_4 -> V_9 . V_354 = V_361 ;
switch ( V_4 -> V_9 . V_10 ( V_2 ) ) {
case V_353 :
V_4 -> V_9 . V_362 = NULL ;
V_4 -> V_9 . V_363 = NULL ;
V_4 -> V_9 . V_364 = NULL ;
V_4 -> V_9 . V_357 = V_365 ;
switch ( V_2 -> V_52 ) {
case V_58 :
V_4 -> V_9 . V_366 = F_84 ;
break;
case V_53 :
V_4 -> V_9 . V_366 =
F_85 ;
break;
default:
V_4 -> V_9 . V_366 =
F_81 ;
break;
}
V_4 -> V_9 . V_367 =
V_368 ;
break;
case V_11 :
if ( V_2 -> V_52 == V_69 )
break;
V_4 -> V_9 . V_357 = F_86 ;
V_4 -> V_9 . V_354 = V_369 ;
V_4 -> V_9 . V_344 = F_87 ;
break;
case V_358 :
if ( V_2 -> V_52 == V_370 ||
V_2 -> V_52 == V_371 )
V_4 -> V_9 . V_357 = F_89 ;
break;
default:
break;
}
if ( V_2 -> V_4 . type == V_268 )
F_94 ( V_2 ) ;
}
static T_1 F_96 ( struct V_1 * V_2 )
{
T_1 V_28 ;
bool V_278 ;
V_28 = F_80 ( V_2 , & V_278 ) ;
if ( V_28 )
return V_28 ;
F_95 ( V_2 ) ;
V_2 -> V_6 . V_9 . V_372 = NULL ;
return 0 ;
}
static T_1 F_97 ( struct V_1 * V_2 ,
T_6 * V_240 ,
bool * V_373 )
{
if ( V_2 -> V_6 . type == V_73 ) {
* V_373 = true ;
* V_240 = V_2 -> V_6 . V_89 ;
return 0 ;
}
if ( V_2 -> V_6 . V_374 == V_353 ) {
* V_373 = false ;
if ( V_2 -> V_6 . V_279 == V_288 ||
V_2 -> V_6 . V_279 == V_289 ) {
* V_240 = V_102 ;
return 0 ;
}
if ( V_2 -> V_6 . V_375 )
* V_240 = V_275 |
V_102 ;
else
* V_240 = V_275 ;
} else {
switch ( V_2 -> V_6 . type ) {
case V_60 :
* V_240 = V_102 |
V_376 |
V_275 ;
break;
case V_62 :
* V_240 = V_102 |
V_275 ;
break;
case V_70 :
case V_377 :
* V_240 = V_102 ;
break;
case V_66 :
if ( V_2 -> V_4 . type == V_268 ) {
if ( V_2 -> V_6 . V_324 &
V_378 ) {
* V_240 = V_376 ;
break;
} else if ( V_2 -> V_52 ==
V_65 ) {
* V_240 = V_102 ;
break;
}
}
default:
* V_240 = V_275 |
V_102 ;
break;
}
* V_373 = true ;
}
return 0 ;
}
static T_1 F_98 ( struct V_1 * V_2 , bool * V_379 )
{
T_2 V_28 ;
T_3 V_24 ;
* V_379 = false ;
V_28 = V_2 -> V_6 . V_9 . V_74 ( V_2 , V_380 ,
V_381 ,
& V_24 ) ;
if ( V_28 || ! ( V_24 & V_382 ) )
return V_28 ;
V_28 = V_2 -> V_6 . V_9 . V_74 ( V_2 , V_383 ,
V_381 ,
& V_24 ) ;
if ( V_28 || ! ( V_24 & ( V_384 |
V_385 ) ) )
return V_28 ;
V_28 = V_2 -> V_6 . V_9 . V_74 ( V_2 , V_386 ,
V_381 ,
& V_24 ) ;
if ( V_28 )
return V_28 ;
if ( V_24 & V_387 ) {
F_99 ( V_2 , false ) ;
return V_124 ;
}
if ( V_24 & V_388 ) {
V_28 = V_2 -> V_6 . V_9 . V_74 ( V_2 , V_389 ,
V_381 ,
& V_24 ) ;
if ( V_28 )
return V_28 ;
if ( V_24 == V_390 ) {
F_99 ( V_2 , false ) ;
return V_124 ;
}
}
V_28 = V_2 -> V_6 . V_9 . V_74 ( V_2 , V_380 ,
V_332 , & V_24 ) ;
if ( V_28 || ! ( V_24 & V_391 ) )
return V_28 ;
V_28 = V_2 -> V_6 . V_9 . V_74 ( V_2 , V_392 ,
V_332 , & V_24 ) ;
if ( V_28 )
return V_28 ;
if ( V_24 & V_393 )
* V_379 = true ;
return 0 ;
}
static T_1 F_100 ( struct V_1 * V_2 )
{
T_2 V_28 ;
T_3 V_24 ;
bool V_379 ;
V_28 = F_98 ( V_2 , & V_379 ) ;
if ( V_2 -> V_4 . type != V_268 ) {
V_28 = V_2 -> V_6 . V_9 . V_74 ( V_2 ,
V_394 ,
V_332 , & V_24 ) ;
if ( V_28 )
return V_28 ;
V_24 |= V_395 ;
V_28 = V_2 -> V_6 . V_9 . V_75 ( V_2 ,
V_394 ,
V_332 , V_24 ) ;
if ( V_28 )
return V_28 ;
}
V_28 = V_2 -> V_6 . V_9 . V_74 ( V_2 , V_396 ,
V_381 ,
& V_24 ) ;
if ( V_28 )
return V_28 ;
V_24 |= ( V_397 |
V_398 ) ;
V_28 = V_2 -> V_6 . V_9 . V_75 ( V_2 , V_396 ,
V_381 ,
V_24 ) ;
if ( V_28 )
return V_28 ;
V_28 = V_2 -> V_6 . V_9 . V_74 ( V_2 , V_399 ,
V_381 ,
& V_24 ) ;
if ( V_28 )
return V_28 ;
V_24 |= ( V_384 |
V_385 ) ;
V_28 = V_2 -> V_6 . V_9 . V_75 ( V_2 , V_399 ,
V_381 ,
V_24 ) ;
if ( V_28 )
return V_28 ;
V_28 = V_2 -> V_6 . V_9 . V_74 ( V_2 , V_400 ,
V_381 ,
& V_24 ) ;
if ( V_28 )
return V_28 ;
V_24 |= V_382 ;
V_28 = V_2 -> V_6 . V_9 . V_75 ( V_2 , V_400 ,
V_381 ,
V_24 ) ;
return V_28 ;
}
static T_1 F_101 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = & V_2 -> V_6 ;
bool V_379 ;
T_2 V_28 ;
V_28 = F_98 ( V_2 , & V_379 ) ;
if ( V_28 )
return V_28 ;
if ( V_379 && V_6 -> V_9 . V_401 )
return V_6 -> V_9 . V_401 ( V_2 ) ;
return 0 ;
}
static T_1 F_82 ( struct V_1 * V_2 ,
T_6 V_240 )
{
T_1 V_28 ;
T_2 V_254 ;
V_28 = V_2 -> V_4 . V_9 . V_265 ( V_2 ,
F_77 ( V_2 -> V_17 . V_18 ) ,
V_255 , & V_254 ) ;
if ( V_28 )
return V_28 ;
V_254 |= V_273 ;
V_254 &= ~ ( V_402 |
V_403 ) ;
if ( V_240 & V_275 )
V_254 |= V_402 ;
if ( V_240 & V_102 )
V_254 |= V_403 ;
V_28 = V_2 -> V_4 . V_9 . V_267 ( V_2 ,
F_77 ( V_2 -> V_17 . V_18 ) ,
V_255 , V_254 ) ;
if ( V_2 -> V_4 . type == V_268 ) {
V_28 = V_2 -> V_4 . V_9 . V_265 ( V_2 ,
F_78 ( V_2 -> V_17 . V_18 ) ,
V_255 , & V_254 ) ;
if ( V_28 )
return V_28 ;
V_254 &= ~ V_306 ;
V_254 |= V_341 ;
V_254 |= V_303 ;
V_254 &= ~ V_304 ;
V_254 &= ~ V_305 ;
V_28 = V_2 -> V_4 . V_9 . V_267 ( V_2 ,
F_78 ( V_2 -> V_17 . V_18 ) ,
V_255 , V_254 ) ;
}
return F_76 ( V_2 ) ;
}
static T_1 F_102 ( struct V_1 * V_2 )
{
if ( V_2 -> V_6 . V_99 & V_376 )
return 0 ;
if ( F_38 ( V_2 ) )
return 0 ;
return F_82 ( V_2 , V_2 -> V_6 . V_99 ) ;
}
static T_1 F_103 ( struct V_1 * V_2 , bool * V_327 )
{
T_2 V_142 ;
T_3 V_329 ;
* V_327 = false ;
V_142 = V_2 -> V_6 . V_9 . V_74 ( V_2 , V_331 , V_332 ,
& V_329 ) ;
if ( V_142 )
return V_142 ;
V_142 = V_2 -> V_6 . V_9 . V_74 ( V_2 , V_331 , V_332 ,
& V_329 ) ;
if ( V_142 )
return V_142 ;
* V_327 = ! ! ( V_329 & V_333 ) ;
return 0 ;
}
static T_1 F_104 ( struct V_1 * V_2 )
{
T_6 V_323 ;
bool V_327 ;
T_2 V_28 ;
T_3 V_240 ;
if ( V_2 -> V_4 . V_9 . V_10 ( V_2 ) != V_11 )
return V_330 ;
if ( ! ( V_2 -> V_4 . type == V_271 &&
! ( V_2 -> V_6 . V_324 & V_325 ) ) ) {
V_240 = V_275 |
V_102 ;
return F_82 ( V_2 , V_240 ) ;
}
V_28 = F_103 ( V_2 , & V_327 ) ;
if ( V_28 )
return V_28 ;
if ( ! V_327 )
return 0 ;
V_28 = V_2 -> V_6 . V_9 . V_74 ( V_2 , V_404 ,
V_332 ,
& V_240 ) ;
if ( V_28 )
return V_28 ;
V_28 = F_103 ( V_2 , & V_327 ) ;
if ( V_28 )
return V_28 ;
if ( ! V_327 )
return 0 ;
V_240 &= V_405 ;
switch ( V_240 ) {
case V_406 :
V_323 = V_275 ;
break;
case V_407 :
V_323 = V_102 ;
break;
default:
return V_112 ;
}
return F_79 ( V_2 , & V_323 ) ;
}
static T_1 F_105 ( struct V_1 * V_2 )
{
T_1 V_28 ;
V_28 = F_106 ( V_2 ) ;
if ( V_28 )
return V_28 ;
return F_100 ( V_2 ) ;
}
static T_1 F_107 ( struct V_1 * V_2 , T_2 V_408 )
{
T_3 V_78 ;
if ( V_408 >= V_409 )
return V_209 ;
V_2 -> V_6 . V_9 . V_74 ( V_2 , V_410 + V_408 ,
V_381 , & V_78 ) ;
V_78 |= V_411 ;
V_2 -> V_6 . V_9 . V_75 ( V_2 , V_410 + V_408 ,
V_381 , V_78 ) ;
return 0 ;
}
static T_1 F_108 ( struct V_1 * V_2 , T_2 V_408 )
{
T_3 V_78 ;
if ( V_408 >= V_409 )
return V_209 ;
V_2 -> V_6 . V_9 . V_74 ( V_2 , V_410 + V_408 ,
V_381 , & V_78 ) ;
V_78 &= ~ V_411 ;
V_2 -> V_6 . V_9 . V_75 ( V_2 , V_410 + V_408 ,
V_381 , V_78 ) ;
return 0 ;
}
static T_1 F_109 ( struct V_1 * V_2 , T_4 V_412 , T_4 V_413 ,
T_4 V_414 , T_4 V_415 , T_3 V_416 ,
const char * V_417 )
{
struct V_418 V_246 ;
T_1 V_310 ;
int V_86 ;
if ( ! V_416 || ! V_417 || ( V_416 > sizeof( V_246 . V_419 ) ) )
return V_420 ;
V_246 . V_151 . V_152 = V_421 ;
V_246 . V_151 . V_154 = V_422 + V_416 ;
V_246 . V_151 . V_156 . V_157 = V_423 ;
V_246 . V_424 = ( T_4 ) V_2 -> V_17 . V_425 ;
V_246 . V_426 = V_412 ;
V_246 . V_427 = V_413 ;
V_246 . V_428 = V_414 ;
V_246 . V_429 = V_415 ;
V_246 . V_151 . V_158 = 0 ;
memcpy ( V_246 . V_419 , V_417 , V_416 ) ;
V_246 . V_151 . V_158 = F_110 ( ( T_4 * ) & V_246 ,
( V_430 + V_246 . V_151 . V_154 ) ) ;
for ( V_86 = 0 ; V_86 <= V_431 ; V_86 ++ ) {
V_310 = F_48 ( V_2 , ( T_2 * ) & V_246 ,
sizeof( V_246 ) ,
V_164 ,
true ) ;
if ( V_310 )
continue;
if ( V_246 . V_151 . V_156 . V_165 !=
V_432 )
return V_433 ;
return 0 ;
}
return V_310 ;
}
static T_1 F_111 ( struct V_1 * V_2 ,
T_6 * V_434 )
{
T_3 V_435 ;
T_1 V_28 ;
T_3 V_436 = V_2 -> V_50 . V_437 ;
* V_434 = V_438 ;
V_28 = V_2 -> V_6 . V_9 . V_74 ( V_2 , V_439 ,
V_332 ,
& V_435 ) ;
if ( V_28 )
return V_28 ;
if ( V_435 & V_440 ) {
* V_434 = V_102 ;
return V_28 ;
}
if ( ( V_2 -> V_17 . V_18 && ( V_436 & V_441 ) ) ||
( V_436 & V_442 ) )
return V_28 ;
* V_434 = V_275 ;
return V_28 ;
}
static T_1 V_361 ( struct V_1 * V_2 )
{
bool V_443 , V_444 ;
T_2 V_254 ;
T_1 V_85 = 0 ;
if ( V_2 -> V_108 . V_109 && V_2 -> V_108 . V_110 == V_111 ) {
F_14 ( V_2 , L_21 ) ;
return V_112 ;
}
if ( V_2 -> V_108 . V_110 == V_125 )
V_2 -> V_108 . V_110 = V_113 ;
switch ( V_2 -> V_108 . V_110 ) {
case V_445 :
V_443 = false ;
V_444 = false ;
break;
case V_117 :
V_443 = false ;
V_444 = true ;
break;
case V_111 :
case V_113 :
V_443 = true ;
V_444 = true ;
break;
default:
F_14 ( V_2 , L_22 ) ;
return V_330 ;
}
switch ( V_2 -> V_52 ) {
case V_63 :
case V_64 :
case V_65 :
V_85 = V_2 -> V_4 . V_9 . V_265 ( V_2 ,
F_112 ( V_2 -> V_17 . V_18 ) ,
V_255 ,
& V_254 ) ;
if ( V_85 )
return V_85 ;
V_254 &= ~ ( V_446 |
V_447 ) ;
if ( V_443 )
V_254 |= V_446 ;
if ( V_444 )
V_254 |= V_447 ;
V_85 = V_2 -> V_4 . V_9 . V_267 ( V_2 ,
F_112 ( V_2 -> V_17 . V_18 ) ,
V_255 ,
V_254 ) ;
V_2 -> V_108 . V_343 = true ;
break;
case V_61 :
V_2 -> V_108 . V_343 = true ;
break;
default:
break;
}
return V_85 ;
}
static void V_359 ( struct V_1 * V_2 )
{
T_2 V_448 , V_449 , V_450 ;
T_1 V_28 = V_342 ;
T_6 V_240 ;
bool V_327 ;
if ( V_2 -> V_108 . V_343 ) {
F_14 ( V_2 , L_23 ) ;
goto V_47;
}
V_2 -> V_4 . V_9 . V_344 ( V_2 , & V_240 , & V_327 , false ) ;
if ( ! V_327 ) {
F_14 ( V_2 , L_24 ) ;
goto V_47;
}
V_28 = V_2 -> V_4 . V_9 . V_265 ( V_2 ,
F_113 ( V_2 -> V_17 . V_18 ) ,
V_255 , & V_448 ) ;
if ( V_28 || ( V_448 & V_451 ) == 0 ) {
F_43 ( V_2 , L_25 ) ;
V_28 = V_342 ;
goto V_47;
}
V_28 = V_2 -> V_4 . V_9 . V_265 ( V_2 ,
F_112 ( V_2 -> V_17 . V_18 ) ,
V_255 , & V_450 ) ;
if ( V_28 ) {
F_43 ( V_2 , L_25 ) ;
goto V_47;
}
V_28 = V_2 -> V_4 . V_9 . V_265 ( V_2 ,
F_114 ( V_2 -> V_17 . V_18 ) ,
V_255 , & V_449 ) ;
if ( V_28 ) {
F_43 ( V_2 , L_25 ) ;
goto V_47;
}
V_28 = F_93 ( V_2 , V_450 , V_449 ,
V_446 ,
V_447 ,
V_452 ,
V_453 ) ;
V_47:
if ( ! V_28 ) {
V_2 -> V_108 . V_351 = true ;
} else {
V_2 -> V_108 . V_351 = false ;
V_2 -> V_108 . V_352 = V_2 -> V_108 . V_110 ;
}
}
static void V_356 ( struct V_1 * V_2 )
{
V_2 -> V_108 . V_351 = false ;
V_2 -> V_108 . V_352 = V_2 -> V_108 . V_110 ;
}
static T_1 F_115 ( struct V_1 * V_2 )
{
T_3 V_454 , V_455 , V_240 ;
T_1 V_28 ;
T_6 V_434 ;
T_2 V_456 ;
bool V_327 ;
if ( F_38 ( V_2 ) )
return 0 ;
V_28 = F_103 ( V_2 , & V_327 ) ;
if ( V_28 )
return V_28 ;
V_28 = V_2 -> V_50 . V_9 . V_227 ( V_2 , V_457 ,
& V_2 -> V_50 . V_437 ) ;
if ( V_28 )
return V_28 ;
if ( ! V_327 || ! ( V_2 -> V_50 . V_437 & V_458 ) ||
! ( V_2 -> V_459 || F_116 ( V_2 ) ) )
return F_99 ( V_2 , false ) ;
V_28 = F_111 ( V_2 , & V_434 ) ;
if ( V_28 )
return V_28 ;
if ( V_434 == V_438 )
return F_99 ( V_2 , false ) ;
V_28 = V_2 -> V_6 . V_9 . V_74 ( V_2 , V_404 ,
V_332 ,
& V_240 ) ;
if ( V_28 )
return V_28 ;
V_28 = F_103 ( V_2 , & V_327 ) ;
if ( V_28 )
return F_99 ( V_2 , false ) ;
V_240 &= V_460 ;
if ( ( ( V_240 == V_461 ) &&
( V_434 == V_102 ) ) ||
( ( V_240 == V_462 ) &&
( V_434 == V_275 ) ) )
return V_28 ;
V_28 = V_2 -> V_6 . V_9 . V_74 ( V_2 , V_463 ,
V_332 ,
& V_455 ) ;
if ( V_28 )
return V_28 ;
V_28 = V_2 -> V_6 . V_9 . V_74 ( V_2 , V_464 ,
V_332 ,
& V_454 ) ;
if ( V_28 )
return V_28 ;
V_28 = V_2 -> V_6 . V_9 . V_74 ( V_2 ,
V_465 ,
V_332 ,
& V_455 ) ;
if ( V_28 )
return V_28 ;
V_456 = V_2 -> V_6 . V_99 ;
V_28 = V_2 -> V_4 . V_9 . V_357 ( V_2 , V_434 , false ) ;
V_2 -> V_6 . V_99 = V_456 ;
return V_28 ;
}
static T_1 F_117 ( struct V_1 * V_2 )
{
T_2 V_466 [ V_82 ] = { 0 } ;
T_1 V_85 ;
if ( V_2 -> V_6 . V_107 || F_38 ( V_2 ) )
return 0 ;
V_85 = F_33 ( V_2 , V_467 , & V_466 ) ;
if ( V_85 )
return V_85 ;
memset ( V_466 , 0 , sizeof( V_466 ) ) ;
V_85 = F_33 ( V_2 , V_468 , & V_466 ) ;
if ( V_85 )
return V_85 ;
return F_37 ( V_2 ) ;
}
static T_1 F_118 ( struct V_1 * V_2 )
{
T_2 V_466 [ V_82 ] = { 0 } ;
T_1 V_85 ;
V_85 = F_33 ( V_2 , V_345 , & V_466 ) ;
if ( V_85 )
return V_85 ;
if ( V_466 [ 0 ] & V_469 ) {
F_36 ( V_2 ) ;
return V_124 ;
}
return 0 ;
}
static void F_119 ( struct V_1 * V_2 )
{
V_2 -> V_6 . V_324 = F_7 ( V_2 , V_470 ) ;
if ( V_2 -> V_4 . type == V_268 &&
V_2 -> V_6 . V_324 & V_471 ) {
V_2 -> V_6 . V_315 . V_316 = ( V_2 -> V_6 . V_324 &
V_472 ) >>
V_473 ;
}
}
static T_1 F_120 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = & V_2 -> V_6 ;
T_1 V_310 ;
V_2 -> V_4 . V_9 . V_242 ( V_2 ) ;
F_119 ( V_2 ) ;
if ( V_2 -> V_4 . V_9 . V_10 ( V_2 ) == V_353 ) {
V_6 -> V_43 = V_57 ;
F_6 ( V_2 ) ;
}
V_310 = V_6 -> V_9 . V_474 ( V_2 ) ;
F_95 ( V_2 ) ;
if ( V_6 -> V_279 != V_292 )
V_6 -> V_9 . V_372 = NULL ;
switch ( V_2 -> V_6 . type ) {
case V_60 :
V_6 -> V_9 . V_357 = NULL ;
V_6 -> V_9 . V_74 = F_24 ;
V_6 -> V_9 . V_75 = F_25 ;
break;
case V_66 :
V_6 -> V_9 . V_357 = F_102 ;
V_6 -> V_9 . V_74 = F_24 ;
V_6 -> V_9 . V_75 = F_25 ;
break;
case V_62 :
V_6 -> V_9 . V_357 = NULL ;
V_6 -> V_9 . V_74 = F_24 ;
V_6 -> V_9 . V_75 = F_25 ;
break;
case V_475 :
V_6 -> V_324 = F_7 ( V_2 , V_470 ) ;
V_6 -> V_9 . V_401 =
F_104 ;
if ( V_2 -> V_4 . type == V_271 &&
! ( F_7 ( V_2 , F_121 ( 0 ) ) &
V_476 ) )
V_6 -> V_9 . V_477 = F_115 ;
V_6 -> V_9 . V_478 = F_101 ;
V_6 -> V_9 . V_372 = F_105 ;
break;
case V_377 :
V_6 -> V_9 . V_357 = NULL ;
break;
case V_73 :
V_6 -> V_9 . V_357 = F_37 ;
V_6 -> V_9 . V_372 = F_117 ;
break;
case V_70 :
V_6 -> V_9 . V_357 = NULL ;
V_6 -> V_9 . V_74 = NULL ;
V_6 -> V_9 . V_75 = NULL ;
V_6 -> V_9 . V_372 = NULL ;
break;
default:
break;
}
return V_310 ;
}
static enum V_479 F_122 ( struct V_1 * V_2 )
{
enum V_479 V_374 ;
switch ( V_2 -> V_52 ) {
case V_370 :
case V_371 :
V_2 -> V_6 . type = V_377 ;
case V_63 :
case V_59 :
case V_61 :
case V_64 :
case V_65 :
V_374 = V_358 ;
break;
case V_56 :
case V_53 :
case V_58 :
V_374 = V_353 ;
break;
case V_69 :
case V_68 :
case V_67 :
case V_71 :
case V_72 :
V_374 = V_11 ;
break;
default:
V_374 = V_480 ;
break;
}
return V_374 ;
}
static T_1 F_123 ( struct V_1 * V_2 )
{
T_1 V_28 ;
T_3 V_24 ;
V_28 = V_2 -> V_6 . V_9 . V_74 ( V_2 ,
V_481 ,
V_482 ,
& V_24 ) ;
if ( V_28 )
return V_28 ;
if ( V_24 & V_483 ) {
V_28 = V_2 -> V_6 . V_9 . V_74 ( V_2 ,
V_484 ,
V_381 ,
& V_24 ) ;
if ( V_28 )
return V_28 ;
V_24 &= ~ V_485 ;
V_28 = V_2 -> V_6 . V_9 . V_75 ( V_2 ,
V_484 ,
V_381 ,
V_24 ) ;
if ( V_28 )
return V_28 ;
}
return V_28 ;
}
static void F_124 ( struct V_1 * V_2 )
{
T_2 V_486 ;
switch ( V_2 -> V_52 ) {
case V_68 :
case V_370 :
case V_371 :
case V_67 :
case V_53 :
V_486 = F_7 ( V_2 , V_487 ) ;
V_486 &= ~ V_488 ;
F_8 ( V_2 , V_487 , V_486 ) ;
break;
case V_71 :
case V_72 :
V_486 = F_7 ( V_2 , V_487 ) ;
V_486 |= V_488 ;
F_8 ( V_2 , V_487 , V_486 ) ;
break;
default:
break;
}
}
static T_1 F_125 ( struct V_1 * V_2 )
{
T_6 V_489 ;
T_1 V_28 ;
T_2 V_135 = 0 ;
T_2 V_86 ;
bool V_327 = false ;
T_2 V_42 = V_2 -> V_6 . V_43 ;
V_28 = V_2 -> V_4 . V_9 . V_490 ( V_2 ) ;
if ( V_28 )
return V_28 ;
F_126 ( V_2 ) ;
V_28 = V_2 -> V_6 . V_9 . V_491 ( V_2 ) ;
if ( V_2 -> V_6 . type == V_475 ) {
V_28 = F_123 ( V_2 ) ;
if ( V_28 )
return V_28 ;
}
if ( V_2 -> V_6 . V_492 ) {
V_28 = V_2 -> V_4 . V_9 . V_493 ( V_2 ) ;
V_2 -> V_6 . V_492 = false ;
}
if ( ! V_2 -> V_6 . V_107 && V_2 -> V_6 . V_9 . V_372 )
V_2 -> V_6 . V_9 . V_372 ( V_2 ) ;
V_494:
V_135 = V_495 ;
if ( ! V_2 -> V_496 ) {
V_2 -> V_4 . V_9 . V_344 ( V_2 , & V_489 , & V_327 , false ) ;
if ( V_327 )
V_135 = V_497 ;
}
V_28 = V_2 -> V_4 . V_9 . V_44 ( V_2 , V_42 ) ;
if ( V_28 ) {
F_43 ( V_2 , L_6 , V_28 ) ;
return V_233 ;
}
V_135 |= F_7 ( V_2 , V_498 ) ;
F_8 ( V_2 , V_498 , V_135 ) ;
F_9 ( V_2 ) ;
V_2 -> V_4 . V_9 . V_49 ( V_2 , V_42 ) ;
F_18 ( 1000 , 1200 ) ;
for ( V_86 = 0 ; V_86 < 10 ; V_86 ++ ) {
V_135 = F_7 ( V_2 , V_498 ) ;
if ( ! ( V_135 & V_499 ) )
break;
F_45 ( 1 ) ;
}
if ( V_135 & V_499 ) {
V_28 = V_500 ;
F_43 ( V_2 , L_26 ) ;
}
F_19 ( 50 ) ;
if ( V_2 -> V_4 . V_501 & V_502 ) {
V_2 -> V_4 . V_501 &= ~ V_502 ;
goto V_494;
}
V_2 -> V_4 . V_9 . V_503 ( V_2 , V_2 -> V_4 . V_504 ) ;
V_2 -> V_4 . V_505 = 128 ;
V_2 -> V_4 . V_9 . V_506 ( V_2 ) ;
F_124 ( V_2 ) ;
if ( V_2 -> V_52 == V_56 )
F_6 ( V_2 ) ;
return V_28 ;
}
static void F_127 ( struct V_1 * V_2 ,
bool V_507 , int V_508 )
{
int V_509 = V_508 >> 3 ;
int V_510 = V_508 % 8 + V_511 ;
T_2 V_512 ;
V_512 = F_7 ( V_2 , F_128 ( V_509 ) ) ;
if ( V_507 )
V_512 |= F_42 ( V_510 ) ;
else
V_512 &= ~ F_42 ( V_510 ) ;
F_8 ( V_2 , F_128 ( V_509 ) , V_512 ) ;
}
static void F_129 ( struct V_1 * V_2 ,
bool V_507 ,
unsigned int V_513 )
{
T_7 V_514 ;
if ( V_513 > 63 )
return;
V_514 = ( T_7 ) F_7 ( V_2 , V_515 ) ;
V_514 |= ( T_7 ) F_7 ( V_2 , V_516 ) << 32 ;
if ( V_507 )
V_514 |= ( 1ULL << V_513 ) ;
else
V_514 &= ~ ( 1ULL << V_513 ) ;
F_8 ( V_2 , V_515 , ( T_2 ) V_514 ) ;
F_8 ( V_2 , V_516 , ( T_2 ) ( V_514 >> 32 ) ) ;
}
static T_1 V_360 ( struct V_1 * V_2 )
{
T_1 V_28 = 0 ;
T_2 V_517 = 0 ;
if ( V_2 -> V_108 . V_109 && V_2 -> V_108 . V_110 == V_111 ) {
F_14 ( V_2 , L_21 ) ;
return V_112 ;
}
if ( V_2 -> V_108 . V_110 == V_125 )
V_2 -> V_108 . V_110 = V_113 ;
V_28 = V_2 -> V_4 . V_9 . V_265 ( V_2 ,
F_112 ( V_2 -> V_17 . V_18 ) ,
V_255 , & V_517 ) ;
if ( V_28 ) {
F_43 ( V_2 , L_25 ) ;
return V_28 ;
}
switch ( V_2 -> V_108 . V_110 ) {
case V_445 :
V_517 &= ~ ( V_446 |
V_447 ) ;
break;
case V_117 :
V_517 |= V_447 ;
V_517 &= ~ V_446 ;
break;
case V_111 :
case V_113 :
V_517 |= V_446 |
V_447 ;
break;
default:
F_14 ( V_2 , L_22 ) ;
return V_330 ;
}
V_28 = V_2 -> V_4 . V_9 . V_267 ( V_2 ,
F_112 ( V_2 -> V_17 . V_18 ) ,
V_255 , V_517 ) ;
V_28 = F_76 ( V_2 ) ;
return V_28 ;
}
static void F_130 ( struct V_1 * V_2 , T_4 V_518 )
{
T_2 V_15 ;
if ( ! V_2 -> V_17 . V_18 )
return;
V_15 = F_7 ( V_2 , V_16 ) ;
if ( V_518 )
V_15 |= V_20 ;
else
V_15 &= ~ V_20 ;
F_8 ( V_2 , V_16 , V_15 ) ;
F_9 ( V_2 ) ;
}
static T_1 F_131 ( struct V_1 * V_2 , T_2 V_185 )
{
T_1 V_28 ;
V_28 = F_132 ( V_2 , V_185 ) ;
if ( V_28 )
return V_28 ;
if ( V_185 & V_519 )
F_130 ( V_2 , 1 ) ;
return 0 ;
}
static void F_133 ( struct V_1 * V_2 , T_2 V_185 )
{
if ( V_185 & V_519 )
F_130 ( V_2 , 0 ) ;
F_134 ( V_2 , V_185 ) ;
}
static T_1 F_135 ( struct V_1 * V_2 , T_2 V_185 )
{
T_2 V_520 = V_185 & ~ V_521 ;
int V_522 = V_523 ;
T_1 V_28 ;
while ( -- V_522 ) {
V_28 = 0 ;
if ( V_520 )
V_28 = F_132 ( V_2 , V_520 ) ;
if ( V_28 )
return V_28 ;
if ( ! ( V_185 & V_521 ) )
return 0 ;
V_28 = F_47 ( V_2 ) ;
if ( ! V_28 )
return 0 ;
if ( V_520 )
F_134 ( V_2 , V_520 ) ;
if ( V_28 != V_169 )
return V_28 ;
F_19 ( V_524 ) ;
}
return V_28 ;
}
static void F_136 ( struct V_1 * V_2 , T_2 V_185 )
{
T_2 V_520 = V_185 & ~ V_521 ;
if ( V_185 & V_521 )
F_49 ( V_2 ) ;
if ( V_520 )
F_134 ( V_2 , V_520 ) ;
}
static T_1 F_137 ( struct V_1 * V_2 , T_2 V_76 ,
T_2 V_77 , T_3 * V_78 )
{
T_2 V_185 = V_2 -> V_6 . V_43 | V_521 ;
T_1 V_28 ;
if ( V_2 -> V_4 . V_9 . V_44 ( V_2 , V_185 ) )
return V_233 ;
V_28 = V_2 -> V_6 . V_9 . V_525 ( V_2 , V_76 , V_77 , V_78 ) ;
V_2 -> V_4 . V_9 . V_49 ( V_2 , V_185 ) ;
return V_28 ;
}
static T_1 F_138 ( struct V_1 * V_2 , T_2 V_76 ,
T_2 V_77 , T_3 V_78 )
{
T_2 V_185 = V_2 -> V_6 . V_43 | V_521 ;
T_1 V_28 ;
if ( V_2 -> V_4 . V_9 . V_44 ( V_2 , V_185 ) )
return V_233 ;
V_28 = F_139 ( V_2 , V_76 , V_77 , V_78 ) ;
V_2 -> V_4 . V_9 . V_49 ( V_2 , V_185 ) ;
return V_28 ;
}
