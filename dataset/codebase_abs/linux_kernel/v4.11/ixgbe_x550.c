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
struct V_3 * V_4 = & V_2 -> V_4 ;
struct V_5 * V_6 = & V_2 -> V_6 ;
F_2 ( V_2 ) ;
if ( V_4 -> V_9 . V_10 ( V_2 ) != V_11 )
V_6 -> V_9 . V_12 = NULL ;
return 0 ;
}
static T_1 F_4 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = & V_2 -> V_6 ;
F_2 ( V_2 ) ;
V_6 -> V_9 . V_12 = NULL ;
return 0 ;
}
static void F_5 ( struct V_1 * V_2 )
{
T_2 V_15 = F_6 ( V_2 , V_16 ) ;
if ( V_2 -> V_17 . V_18 ) {
V_15 &= ~ ( V_19 | V_20 ) ;
V_15 |= V_21 ;
}
V_15 &= ~ ( V_22 | V_23 ) ;
F_7 ( V_2 , V_16 , V_15 ) ;
F_8 ( V_2 ) ;
}
static T_1 F_9 ( struct V_1 * V_2 , T_3 V_24 , T_3 * V_25 )
{
return V_2 -> V_8 . V_9 . V_26 ( V_2 , V_2 -> V_8 . V_13 , V_24 , V_25 ) ;
}
static T_1 F_10 ( struct V_1 * V_2 , T_3 V_24 , T_3 V_25 )
{
return V_2 -> V_8 . V_9 . V_27 ( V_2 , V_2 -> V_8 . V_13 , V_24 , V_25 ) ;
}
static T_1 F_11 ( struct V_1 * V_2 , T_4 V_24 , T_4 * V_25 )
{
T_1 V_28 ;
V_28 = F_12 ( V_2 , V_24 , V_29 , V_25 ) ;
if ( V_28 )
F_13 ( V_2 , L_1 , V_28 ) ;
return V_28 ;
}
static T_1 F_14 ( struct V_1 * V_2 , T_4 V_24 , T_4 V_25 )
{
T_1 V_28 ;
V_28 = F_15 ( V_2 , V_24 , V_29 ,
V_25 ) ;
if ( V_28 )
F_13 ( V_2 , L_1 , V_28 ) ;
return V_28 ;
}
static T_1 F_16 ( struct V_1 * V_2 )
{
T_1 V_28 ;
T_2 V_30 ;
T_3 V_25 ;
T_4 V_24 ;
V_28 = F_11 ( V_2 , V_31 , & V_24 ) ;
if ( V_28 )
return V_28 ;
V_24 |= V_32 ;
V_28 = F_14 ( V_2 , V_31 , V_24 ) ;
if ( V_28 )
return V_28 ;
V_28 = F_11 ( V_2 , V_33 , & V_24 ) ;
if ( V_28 )
return V_28 ;
V_24 &= ~ V_32 ;
V_28 = F_14 ( V_2 , V_33 , V_24 ) ;
if ( V_28 )
return V_28 ;
V_28 = F_11 ( V_2 , V_31 , & V_24 ) ;
if ( V_28 )
return V_28 ;
V_24 &= ~ V_32 ;
V_28 = F_14 ( V_2 , V_31 , V_24 ) ;
if ( V_28 )
return V_28 ;
F_17 ( V_34 , V_34 + 100 ) ;
V_28 = F_11 ( V_2 , V_31 , & V_24 ) ;
if ( V_28 )
return V_28 ;
V_24 |= V_32 ;
V_28 = F_14 ( V_2 , V_31 , V_24 ) ;
if ( V_28 )
return V_28 ;
F_18 ( V_35 ) ;
for ( V_30 = 0 ; V_30 < V_36 ; V_30 ++ ) {
V_28 = F_9 ( V_2 , V_37 ,
& V_25 ) ;
if ( ! V_28 && V_25 == V_38 )
break;
F_18 ( V_39 ) ;
}
if ( V_30 == V_36 ) {
F_13 ( V_2 , L_2 ) ;
return V_40 ;
}
V_28 = F_9 ( V_2 , V_41 , & V_25 ) ;
if ( V_28 || ! ( V_25 & V_38 ) ) {
F_13 ( V_2 , L_3 ) ;
return V_40 ;
}
return 0 ;
}
static void F_19 ( struct V_1 * V_2 )
{
T_2 V_42 = V_2 -> V_6 . V_43 ;
T_1 V_28 ;
T_3 V_25 ;
T_4 V_30 ;
for ( V_30 = 0 ; V_30 < V_36 ; V_30 ++ ) {
V_28 = V_2 -> V_4 . V_9 . V_44 ( V_2 , V_42 ) ;
if ( V_28 ) {
F_13 ( V_2 , L_4 , V_28 ) ;
F_18 ( V_39 ) ;
continue;
}
V_28 = F_9 ( V_2 , V_45 , & V_25 ) ;
if ( ! V_28 && V_25 == V_46 )
goto V_47;
if ( V_28 || V_25 != V_48 )
break;
V_2 -> V_4 . V_9 . V_49 ( V_2 , V_42 ) ;
F_18 ( V_39 ) ;
}
if ( V_30 == V_36 ) {
V_28 = V_2 -> V_4 . V_9 . V_44 ( V_2 , V_42 ) ;
if ( V_28 ) {
F_13 ( V_2 , L_4 , V_28 ) ;
return;
}
}
V_28 = F_16 ( V_2 ) ;
if ( V_28 ) {
F_13 ( V_2 , L_5 , V_28 ) ;
goto V_47;
}
F_10 ( V_2 , V_45 ,
V_48 ) ;
V_2 -> V_4 . V_9 . V_49 ( V_2 , V_42 ) ;
F_17 ( 10000 , 12000 ) ;
V_28 = V_2 -> V_4 . V_9 . V_44 ( V_2 , V_42 ) ;
if ( V_28 ) {
F_13 ( V_2 , L_6 , V_28 ) ;
return;
}
V_28 = F_10 ( V_2 , V_45 ,
V_46 ) ;
V_47:
V_2 -> V_4 . V_9 . V_49 ( V_2 , V_42 ) ;
F_18 ( V_2 -> V_50 . V_51 ) ;
}
static T_1 F_20 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_52 ) {
case V_53 :
if ( V_2 -> V_17 . V_18 )
V_2 -> V_6 . V_43 = V_54 ;
else
V_2 -> V_6 . V_43 = V_55 ;
return F_21 ( V_2 ) ;
case V_56 :
V_2 -> V_6 . V_43 = V_57 ;
F_5 ( V_2 ) ;
F_19 ( V_2 ) ;
case V_58 :
return F_21 ( V_2 ) ;
case V_59 :
V_2 -> V_6 . type = V_60 ;
break;
case V_61 :
case V_62 :
case V_63 :
V_2 -> V_6 . type = V_64 ;
break;
case V_65 :
if ( V_2 -> V_17 . V_18 )
V_2 -> V_6 . V_43 = V_54 ;
else
V_2 -> V_6 . V_43 = V_55 ;
case V_66 :
case V_67 :
return F_22 ( V_2 ) ;
default:
break;
}
return 0 ;
}
static T_1 F_23 ( struct V_1 * V_2 , T_2 V_68 ,
T_2 V_69 , T_3 * V_70 )
{
return V_71 ;
}
static T_1 F_24 ( struct V_1 * V_2 , T_2 V_68 ,
T_2 V_69 , T_3 V_70 )
{
return V_71 ;
}
static T_1 F_25 ( struct V_1 * V_2 , T_4 V_13 ,
T_3 V_24 , T_3 * V_72 )
{
return F_26 ( V_2 , V_13 , V_24 , V_72 , true ) ;
}
static T_1
F_27 ( struct V_1 * V_2 , T_4 V_13 ,
T_3 V_24 , T_3 * V_72 )
{
return F_26 ( V_2 , V_13 , V_24 , V_72 , false ) ;
}
static T_1 F_28 ( struct V_1 * V_2 ,
T_4 V_13 , T_3 V_24 , T_3 V_72 )
{
return F_29 ( V_2 , V_13 , V_24 , V_72 , true ) ;
}
static T_1
F_30 ( struct V_1 * V_2 ,
T_4 V_13 , T_3 V_24 , T_3 V_72 )
{
return F_29 ( V_2 , V_13 , V_24 , V_72 , false ) ;
}
static T_1 F_31 ( struct V_1 * V_2 )
{
T_2 V_73 [ V_74 ] = { 0 } ;
T_3 V_75 ;
T_3 V_76 ;
T_1 V_77 ;
T_3 V_78 ;
if ( V_2 -> V_6 . V_79 )
return 0 ;
V_77 = F_32 ( V_2 , V_80 , & V_73 ) ;
if ( V_77 )
return V_77 ;
V_2 -> V_6 . V_81 = 0 ;
V_75 = V_73 [ 0 ] & V_82 ;
for ( V_78 = 0 ; V_78 < F_33 ( V_83 ) ; ++ V_78 ) {
if ( V_75 & V_83 [ V_78 ] . V_84 )
V_2 -> V_6 . V_81 |= V_83 [ V_78 ] . V_85 ;
}
V_2 -> V_6 . V_79 = V_73 [ 0 ] & V_86 ;
V_76 = V_73 [ 1 ] & V_87 ;
V_2 -> V_6 . V_79 |= V_76 & V_88 ;
V_2 -> V_6 . V_89 = V_76 & ~ V_88 ;
if ( ! V_2 -> V_6 . V_79 || V_2 -> V_6 . V_79 == V_88 )
return V_90 ;
V_2 -> V_6 . V_91 = V_2 -> V_6 . V_81 ;
V_2 -> V_6 . V_92 = V_93 |
V_94 ;
V_2 -> V_6 . V_95 = V_2 -> V_6 . V_92 ;
return 0 ;
}
static T_1 F_34 ( struct V_1 * V_2 )
{
if ( V_2 -> V_17 . V_18 )
V_2 -> V_6 . V_43 = V_54 ;
else
V_2 -> V_6 . V_43 = V_55 ;
V_2 -> V_6 . type = V_96 ;
V_2 -> V_6 . V_9 . V_97 = NULL ;
V_2 -> V_6 . V_9 . V_98 = NULL ;
return F_31 ( V_2 ) ;
}
static T_1 F_35 ( struct V_1 * V_2 )
{
T_2 V_99 [ V_74 ] = { 0 } ;
V_99 [ 0 ] = V_100 ;
return F_32 ( V_2 , V_101 , & V_99 ) ;
}
static T_1 F_36 ( struct V_1 * V_2 )
{
T_2 V_99 [ V_74 ] = { 0 } ;
T_1 V_77 ;
T_3 V_78 ;
if ( V_2 -> V_6 . V_102 || F_37 ( V_2 ) )
return 0 ;
if ( V_2 -> V_103 . V_104 && V_2 -> V_103 . V_105 == V_106 ) {
F_13 ( V_2 , L_7 ) ;
return V_107 ;
}
switch ( V_2 -> V_103 . V_105 ) {
case V_108 :
V_99 [ 0 ] |= V_109 <<
V_110 ;
break;
case V_106 :
V_99 [ 0 ] |= V_111 <<
V_110 ;
break;
case V_112 :
V_99 [ 0 ] |= V_113 <<
V_110 ;
break;
default:
break;
}
for ( V_78 = 0 ; V_78 < F_33 ( V_83 ) ; ++ V_78 ) {
if ( V_2 -> V_6 . V_91 & V_83 [ V_78 ] . V_85 )
V_99 [ 0 ] |= V_83 [ V_78 ] . V_84 ;
}
V_99 [ 0 ] |= V_114 | V_115 ;
if ( V_2 -> V_6 . V_95 )
V_99 [ 0 ] |= V_116 ;
V_77 = F_32 ( V_2 , V_117 , & V_99 ) ;
if ( V_77 )
return V_77 ;
if ( V_99 [ 0 ] == V_118 )
return V_119 ;
return 0 ;
}
static T_1 F_38 ( struct V_1 * V_2 )
{
if ( V_2 -> V_103 . V_105 == V_120 )
V_2 -> V_103 . V_105 = V_108 ;
return F_36 ( V_2 ) ;
}
static T_1 F_39 ( struct V_1 * V_2 )
{
struct V_121 * V_50 = & V_2 -> V_50 ;
T_2 V_122 ;
T_3 V_123 ;
if ( V_50 -> type == V_124 ) {
V_50 -> V_51 = 10 ;
V_50 -> type = V_125 ;
V_122 = F_6 ( V_2 , F_40 ( V_2 ) ) ;
V_123 = ( T_3 ) ( ( V_122 & V_126 ) >>
V_127 ) ;
V_50 -> V_128 = F_41 ( V_123 +
V_129 ) ;
F_42 ( V_2 , L_8 ,
V_50 -> type , V_50 -> V_128 ) ;
}
return 0 ;
}
static T_1 F_43 ( struct V_1 * V_2 , T_2 * V_130 )
{
T_2 V_78 , V_131 ;
for ( V_78 = 0 ; V_78 < V_132 ; V_78 ++ ) {
V_131 = F_6 ( V_2 , V_133 ) ;
if ( ! ( V_131 & V_134 ) )
break;
F_44 ( 10 ) ;
}
if ( V_130 )
* V_130 = V_131 ;
if ( V_78 == V_132 ) {
F_42 ( V_2 , L_9 ) ;
return V_40 ;
}
return 0 ;
}
static T_1 F_45 ( struct V_1 * V_2 , T_2 V_68 ,
T_2 V_69 , T_2 * V_135 )
{
T_2 V_136 = V_54 | V_55 ;
T_2 V_131 , error ;
T_1 V_137 ;
V_137 = V_2 -> V_4 . V_9 . V_44 ( V_2 , V_136 ) ;
if ( V_137 )
return V_137 ;
V_137 = F_43 ( V_2 , NULL ) ;
if ( V_137 )
goto V_47;
V_131 = ( ( V_68 << V_138 ) |
( V_69 << V_139 ) ) ;
F_7 ( V_2 , V_133 , V_131 ) ;
V_137 = F_43 ( V_2 , & V_131 ) ;
if ( ( V_131 & V_140 ) != 0 ) {
error = ( V_131 & V_141 ) >>
V_142 ;
F_42 ( V_2 , L_10 , error ) ;
return V_40 ;
}
if ( ! V_137 )
* V_135 = F_6 ( V_2 , V_143 ) ;
V_47:
V_2 -> V_4 . V_9 . V_49 ( V_2 , V_136 ) ;
return V_137 ;
}
static T_1 F_46 ( struct V_1 * V_2 )
{
struct V_144 V_145 ;
T_1 V_28 ;
V_145 . V_146 . V_147 = V_148 ;
V_145 . V_146 . V_149 = V_150 ;
V_145 . V_146 . V_151 . V_152 = 0 ;
V_145 . V_146 . V_153 = V_154 ;
V_145 . V_155 = V_2 -> V_17 . V_18 ;
V_145 . V_156 = V_157 ;
V_145 . V_158 = 0 ;
V_28 = F_47 ( V_2 , & V_145 , sizeof( V_145 ) ,
V_159 ,
true ) ;
if ( V_28 )
return V_28 ;
if ( V_145 . V_146 . V_151 . V_160 == V_161 )
return 0 ;
if ( V_145 . V_146 . V_151 . V_160 != V_162 )
return V_163 ;
return V_164 ;
}
static T_1 F_48 ( struct V_1 * V_2 )
{
struct V_144 V_145 ;
T_1 V_28 ;
V_145 . V_146 . V_147 = V_148 ;
V_145 . V_146 . V_149 = V_150 ;
V_145 . V_146 . V_151 . V_152 = 0 ;
V_145 . V_146 . V_153 = V_154 ;
V_145 . V_155 = V_2 -> V_17 . V_18 ;
V_145 . V_156 = V_165 ;
V_145 . V_158 = 0 ;
V_28 = F_47 ( V_2 , & V_145 , sizeof( V_145 ) ,
V_159 ,
true ) ;
if ( V_28 )
return V_28 ;
if ( V_145 . V_146 . V_151 . V_160 == V_161 )
return 0 ;
return V_163 ;
}
static T_1 F_49 ( struct V_1 * V_2 , T_2 V_68 ,
T_5 T_2 V_69 ,
T_2 V_135 )
{
struct V_166 V_167 ;
memset ( & V_167 , 0 , sizeof( V_167 ) ) ;
V_167 . V_146 . V_147 = V_168 ;
V_167 . V_146 . V_149 = V_169 ;
V_167 . V_146 . V_153 = V_154 ;
V_167 . V_155 = V_2 -> V_17 . V_18 ;
V_167 . V_156 = V_170 ;
V_167 . V_171 = F_50 ( V_68 ) ;
V_167 . V_172 = F_51 ( V_135 ) ;
return F_47 ( V_2 , & V_167 , sizeof( V_167 ) ,
V_159 , false ) ;
}
static T_1 F_52 ( struct V_1 * V_2 , T_2 V_68 ,
T_5 T_2 V_69 ,
T_2 * V_135 )
{
union {
struct V_166 V_147 ;
struct V_173 V_174 ;
} V_175 ;
T_1 V_28 ;
memset ( & V_175 , 0 , sizeof( V_175 ) ) ;
V_175 . V_147 . V_146 . V_147 = V_168 ;
V_175 . V_147 . V_146 . V_149 = V_169 ;
V_175 . V_147 . V_146 . V_153 = V_154 ;
V_175 . V_147 . V_155 = V_2 -> V_17 . V_18 ;
V_175 . V_147 . V_156 = V_176 ;
V_175 . V_147 . V_171 = F_50 ( V_68 ) ;
V_28 = F_47 ( V_2 , & V_175 . V_147 , sizeof( V_175 . V_147 ) ,
V_159 , true ) ;
* V_135 = F_53 ( V_175 . V_174 . V_177 ) ;
return V_28 ;
}
static T_1 F_54 ( struct V_1 * V_2 ,
T_3 V_178 , T_3 V_179 , T_3 * V_135 )
{
const T_2 V_180 = V_181 | V_182 ;
struct V_183 V_184 ;
T_2 V_185 = 0 ;
T_3 V_186 ;
T_1 V_28 ;
T_2 V_78 ;
V_28 = V_2 -> V_4 . V_9 . V_44 ( V_2 , V_180 ) ;
if ( V_28 ) {
F_42 ( V_2 , L_11 ) ;
return V_28 ;
}
while ( V_179 ) {
if ( V_179 > V_187 / 2 )
V_186 = V_187 / 2 ;
else
V_186 = V_179 ;
V_184 . V_146 . V_188 . V_147 = V_189 ;
V_184 . V_146 . V_188 . V_190 = 0 ;
V_184 . V_146 . V_188 . V_191 = V_192 ;
V_184 . V_146 . V_188 . V_153 = V_154 ;
V_184 . V_171 = F_51 ( ( V_178 + V_185 ) * 2 ) ;
V_184 . V_193 = F_50 ( V_186 * 2 ) ;
V_28 = F_55 ( V_2 , ( T_2 * ) & V_184 , sizeof( V_184 ) ,
V_159 ) ;
if ( V_28 ) {
F_42 ( V_2 , L_12 ) ;
goto V_47;
}
for ( V_78 = 0 ; V_78 < V_186 ; V_78 ++ ) {
T_2 V_24 = V_194 + ( V_195 << 2 ) +
2 * V_78 ;
T_2 V_25 = F_6 ( V_2 , V_24 ) ;
V_135 [ V_185 ] = ( T_3 ) ( V_25 & 0xffff ) ;
V_185 ++ ;
V_78 ++ ;
if ( V_78 < V_186 ) {
V_25 >>= 16 ;
V_135 [ V_185 ] = ( T_3 ) ( V_25 & 0xffff ) ;
V_185 ++ ;
}
}
V_179 -= V_186 ;
}
V_47:
V_2 -> V_4 . V_9 . V_49 ( V_2 , V_180 ) ;
return V_28 ;
}
static T_1 F_56 ( struct V_1 * V_2 , T_3 V_196 ,
T_3 V_197 , T_3 * V_198 , T_3 * V_184 ,
T_2 V_199 )
{
T_3 V_200 [ 256 ] ;
T_1 V_28 ;
T_3 V_193 , V_201 , V_78 , V_202 ;
T_3 * V_203 ;
V_201 = sizeof( V_200 ) / sizeof( V_200 [ 0 ] ) ;
if ( ! V_184 ) {
V_28 = F_54 ( V_2 , V_196 , V_201 , V_200 ) ;
if ( V_28 ) {
F_42 ( V_2 , L_13 ) ;
return V_28 ;
}
V_203 = V_200 ;
} else {
if ( V_199 < V_196 )
return V_204 ;
V_203 = & V_184 [ V_196 ] ;
}
if ( V_197 ) {
V_202 = 0 ;
V_193 = V_197 ;
} else {
V_202 = 1 ;
V_193 = V_203 [ 0 ] ;
if ( V_193 == 0xFFFF || V_193 == 0 ||
( V_196 + V_193 ) >= V_2 -> V_50 . V_128 )
return 0 ;
}
if ( V_184 && ( ( T_2 ) V_202 + ( T_2 ) V_193 > V_199 ) )
return V_204 ;
for ( V_78 = V_202 ; V_193 ; V_78 ++ , V_193 -- ) {
if ( V_78 == V_201 && ! V_184 ) {
V_196 += V_201 ;
V_78 = 0 ;
if ( V_193 < V_201 )
V_201 = V_193 ;
V_28 = F_54 ( V_2 , V_196 ,
V_201 , V_200 ) ;
if ( V_28 ) {
F_42 ( V_2 , L_13 ) ;
return V_28 ;
}
}
* V_198 += V_203 [ V_78 ] ;
}
return 0 ;
}
static T_1 F_57 ( struct V_1 * V_2 , T_3 * V_184 ,
T_2 V_199 )
{
T_3 V_205 [ V_206 + 1 ] ;
T_3 * V_203 ;
T_1 V_28 ;
T_3 V_153 = 0 ;
T_3 V_207 , V_78 , V_197 ;
V_2 -> V_50 . V_9 . V_208 ( V_2 ) ;
if ( ! V_184 ) {
V_28 = F_54 ( V_2 , 0 ,
V_206 + 1 ,
V_205 ) ;
if ( V_28 ) {
F_42 ( V_2 , L_13 ) ;
return V_28 ;
}
V_203 = V_205 ;
} else {
if ( V_199 < V_206 )
return V_204 ;
V_203 = V_184 ;
}
for ( V_78 = 0 ; V_78 <= V_206 ; V_78 ++ )
if ( V_78 != V_209 )
V_153 += V_203 [ V_78 ] ;
for ( V_78 = V_210 ; V_78 < V_211 ; V_78 ++ ) {
if ( V_78 == V_212 || V_78 == V_213 )
continue;
V_207 = V_203 [ V_78 ] ;
if ( V_207 == 0xFFFF || V_207 == 0 ||
V_207 >= V_2 -> V_50 . V_128 )
continue;
switch ( V_78 ) {
case V_214 :
V_197 = V_215 ;
break;
case V_216 :
case V_217 :
V_197 = V_218 ;
break;
default:
V_197 = 0 ;
break;
}
V_28 = F_56 ( V_2 , V_207 , V_197 , & V_153 ,
V_184 , V_199 ) ;
if ( V_28 )
return V_28 ;
}
V_153 = ( T_3 ) V_219 - V_153 ;
return ( T_1 ) V_153 ;
}
static T_1 F_58 ( struct V_1 * V_2 )
{
return F_57 ( V_2 , NULL , 0 ) ;
}
static T_1 F_59 ( struct V_1 * V_2 , T_3 V_178 , T_3 * V_135 )
{
const T_2 V_180 = V_181 | V_182 ;
struct V_183 V_184 ;
T_1 V_28 ;
V_184 . V_146 . V_188 . V_147 = V_189 ;
V_184 . V_146 . V_188 . V_190 = 0 ;
V_184 . V_146 . V_188 . V_191 = V_192 ;
V_184 . V_146 . V_188 . V_153 = V_154 ;
V_184 . V_171 = F_51 ( V_178 * 2 ) ;
V_184 . V_193 = F_50 ( sizeof( T_3 ) ) ;
V_28 = V_2 -> V_4 . V_9 . V_44 ( V_2 , V_180 ) ;
if ( V_28 )
return V_28 ;
V_28 = F_55 ( V_2 , ( T_2 * ) & V_184 , sizeof( V_184 ) ,
V_159 ) ;
if ( ! V_28 ) {
* V_135 = ( T_3 ) F_60 ( V_2 , V_194 ,
V_195 ) ;
}
V_2 -> V_4 . V_9 . V_49 ( V_2 , V_180 ) ;
return V_28 ;
}
static T_1 F_61 ( struct V_1 * V_2 ,
T_3 * V_220 )
{
T_1 V_28 ;
T_3 V_153 ;
T_3 V_221 = 0 ;
V_28 = V_2 -> V_50 . V_9 . V_222 ( V_2 , 0 , & V_153 ) ;
if ( V_28 ) {
F_42 ( V_2 , L_14 ) ;
return V_28 ;
}
V_28 = V_2 -> V_50 . V_9 . V_223 ( V_2 ) ;
if ( V_28 < 0 )
return V_28 ;
V_153 = ( T_3 ) ( V_28 & 0xffff ) ;
V_28 = F_59 ( V_2 , V_209 ,
& V_221 ) ;
if ( V_28 )
return V_28 ;
if ( V_221 != V_153 ) {
V_28 = V_224 ;
F_42 ( V_2 , L_15 ) ;
}
if ( V_220 )
* V_220 = V_153 ;
return V_28 ;
}
static T_1 F_62 ( struct V_1 * V_2 , T_3 V_178 ,
T_3 V_135 )
{
T_1 V_28 ;
struct V_225 V_184 ;
V_184 . V_146 . V_188 . V_147 = V_226 ;
V_184 . V_146 . V_188 . V_190 = 0 ;
V_184 . V_146 . V_188 . V_191 = V_227 ;
V_184 . V_146 . V_188 . V_153 = V_154 ;
V_184 . V_193 = F_50 ( sizeof( T_3 ) ) ;
V_184 . V_135 = V_135 ;
V_184 . V_171 = F_51 ( V_178 * 2 ) ;
V_28 = F_47 ( V_2 , & V_184 , sizeof( V_184 ) ,
V_159 , false ) ;
return V_28 ;
}
static T_1 F_63 ( struct V_1 * V_2 , T_3 V_178 , T_3 V_135 )
{
T_1 V_28 = 0 ;
if ( V_2 -> V_4 . V_9 . V_44 ( V_2 , V_182 ) == 0 ) {
V_28 = F_62 ( V_2 , V_178 , V_135 ) ;
V_2 -> V_4 . V_9 . V_49 ( V_2 , V_182 ) ;
} else {
F_42 ( V_2 , L_16 ) ;
V_28 = V_228 ;
}
return V_28 ;
}
static T_1 F_64 ( struct V_1 * V_2 )
{
T_1 V_28 = 0 ;
union V_229 V_184 ;
V_184 . V_188 . V_147 = V_230 ;
V_184 . V_188 . V_190 = 0 ;
V_184 . V_188 . V_191 = V_231 ;
V_184 . V_188 . V_153 = V_154 ;
V_28 = F_47 ( V_2 , & V_184 , sizeof( V_184 ) ,
V_159 , false ) ;
return V_28 ;
}
static T_1 F_65 ( struct V_1 * V_2 )
{
V_2 -> V_17 . type = V_232 ;
V_2 -> V_17 . V_233 = V_234 ;
V_2 -> V_17 . V_235 = V_236 ;
V_2 -> V_4 . V_9 . V_237 ( V_2 ) ;
return 0 ;
}
static void F_66 ( struct V_1 * V_2 )
{
T_2 V_238 , V_239 ;
T_1 V_28 ;
struct V_240 V_241 ;
V_238 = F_6 ( V_2 , V_242 ) ;
if ( V_238 & V_243 ) {
V_239 = F_6 ( V_2 , V_244 ) ;
if ( V_239 & V_245 ) {
V_239 &= ~ V_245 ;
F_7 ( V_2 , V_244 , V_239 ) ;
V_2 -> V_4 . V_246 = true ;
} else {
V_2 -> V_4 . V_246 = false ;
}
V_241 . V_146 . V_147 = V_247 ;
V_241 . V_146 . V_149 = V_248 ;
V_241 . V_146 . V_153 = V_154 ;
V_241 . V_155 = V_2 -> V_17 . V_18 ;
V_28 = F_47 ( V_2 , & V_241 ,
sizeof( struct V_240 ) ,
V_159 , true ) ;
if ( V_28 ) {
V_238 = F_6 ( V_2 , V_242 ) ;
if ( V_238 & V_243 ) {
V_238 &= ~ V_243 ;
F_7 ( V_2 , V_242 , V_238 ) ;
}
}
}
}
static T_1 F_67 ( struct V_1 * V_2 )
{
T_1 V_28 ;
T_3 V_153 = 0 ;
V_28 = F_59 ( V_2 , 0 , & V_153 ) ;
if ( V_28 ) {
F_42 ( V_2 , L_14 ) ;
return V_28 ;
}
V_28 = F_58 ( V_2 ) ;
if ( V_28 < 0 )
return V_28 ;
V_153 = ( T_3 ) ( V_28 & 0xffff ) ;
V_28 = F_63 ( V_2 , V_209 ,
V_153 ) ;
if ( V_28 )
return V_28 ;
V_28 = F_64 ( V_2 ) ;
return V_28 ;
}
static T_1 F_68 ( struct V_1 * V_2 ,
T_3 V_178 , T_3 V_179 ,
T_3 * V_135 )
{
T_1 V_28 = 0 ;
T_2 V_78 = 0 ;
V_28 = V_2 -> V_4 . V_9 . V_44 ( V_2 , V_182 ) ;
if ( V_28 ) {
F_42 ( V_2 , L_17 ) ;
return V_28 ;
}
for ( V_78 = 0 ; V_78 < V_179 ; V_78 ++ ) {
V_28 = F_62 ( V_2 , V_178 + V_78 ,
V_135 [ V_78 ] ) ;
if ( V_28 ) {
F_42 ( V_2 , L_18 ) ;
break;
}
}
V_2 -> V_4 . V_9 . V_49 ( V_2 , V_182 ) ;
return V_28 ;
}
static T_1 F_69 ( struct V_1 * V_2 , T_2 V_68 ,
T_2 V_69 , T_2 V_135 )
{
T_2 V_136 = V_54 | V_55 ;
T_2 V_131 , error ;
T_1 V_137 ;
V_137 = V_2 -> V_4 . V_9 . V_44 ( V_2 , V_136 ) ;
if ( V_137 )
return V_137 ;
V_137 = F_43 ( V_2 , NULL ) ;
if ( V_137 )
goto V_47;
V_131 = ( ( V_68 << V_138 ) |
( V_69 << V_139 ) ) ;
F_7 ( V_2 , V_133 , V_131 ) ;
F_7 ( V_2 , V_143 , V_135 ) ;
V_137 = F_43 ( V_2 , & V_131 ) ;
if ( ( V_131 & V_140 ) != 0 ) {
error = ( V_131 & V_141 ) >>
V_142 ;
F_42 ( V_2 , L_19 , error ) ;
return V_40 ;
}
V_47:
V_2 -> V_4 . V_9 . V_49 ( V_2 , V_136 ) ;
return V_137 ;
}
static T_1 F_70 ( struct V_1 * V_2 )
{
T_1 V_28 ;
T_2 V_249 ;
V_28 = F_45 ( V_2 ,
F_71 ( V_2 -> V_17 . V_18 ) ,
V_250 , & V_249 ) ;
if ( V_28 )
return V_28 ;
V_249 |= V_251 ;
V_28 = F_69 ( V_2 ,
F_71 ( V_2 -> V_17 . V_18 ) ,
V_250 , V_249 ) ;
if ( V_28 )
return V_28 ;
V_28 = F_45 ( V_2 ,
F_72 ( V_2 -> V_17 . V_18 ) ,
V_250 , & V_249 ) ;
if ( V_28 )
return V_28 ;
V_249 &= ~ V_252 ;
V_249 &= ~ V_253 ;
V_249 &= ~ V_254 ;
V_28 = F_69 ( V_2 ,
F_72 ( V_2 -> V_17 . V_18 ) ,
V_250 , V_249 ) ;
if ( V_28 )
return V_28 ;
V_28 = F_45 ( V_2 ,
F_73 ( V_2 -> V_17 . V_18 ) ,
V_250 , & V_249 ) ;
if ( V_28 )
return V_28 ;
V_249 &= ~ V_252 ;
V_249 &= ~ V_253 ;
V_249 &= ~ V_254 ;
V_28 = F_69 ( V_2 ,
F_73 ( V_2 -> V_17 . V_18 ) ,
V_250 , V_249 ) ;
if ( V_28 )
return V_28 ;
V_28 = F_45 ( V_2 ,
F_74 ( V_2 -> V_17 . V_18 ) ,
V_250 , & V_249 ) ;
if ( V_28 )
return V_28 ;
V_249 |= V_255 ;
V_249 |= V_256 ;
V_249 |= V_257 ;
V_249 |= V_258 ;
V_28 = F_69 ( V_2 ,
F_74 ( V_2 -> V_17 . V_18 ) ,
V_250 , V_249 ) ;
return V_28 ;
}
static T_1 F_75 ( struct V_1 * V_2 )
{
T_1 V_28 ;
T_2 V_259 ;
V_28 = V_2 -> V_4 . V_9 . V_260 ( V_2 ,
F_76 ( V_2 -> V_17 . V_18 ) ,
V_250 , & V_259 ) ;
if ( V_28 ) {
F_42 ( V_2 , L_20 ) ;
return V_28 ;
}
V_259 |= V_261 ;
V_28 = V_2 -> V_4 . V_9 . V_262 ( V_2 ,
F_76 ( V_2 -> V_17 . V_18 ) ,
V_250 , V_259 ) ;
if ( V_2 -> V_4 . type == V_263 ) {
T_2 V_264 ;
V_28 = V_2 -> V_4 . V_9 . V_260 ( V_2 ,
F_77 ( V_2 -> V_17 . V_18 ) ,
V_250 , & V_264 ) ;
if ( V_28 ) {
F_42 ( V_2 , L_20 ) ;
return V_28 ;
}
V_264 |= V_265 ;
V_28 = V_2 -> V_4 . V_9 . V_262 ( V_2 ,
F_77 ( V_2 -> V_17 . V_18 ) ,
V_250 , V_264 ) ;
}
return V_28 ;
}
static T_1 F_78 ( struct V_1 * V_2 , T_6 * V_235 )
{
T_1 V_28 ;
T_2 V_249 ;
V_28 = F_45 ( V_2 ,
F_76 ( V_2 -> V_17 . V_18 ) ,
V_250 , & V_249 ) ;
if ( V_28 )
return V_28 ;
V_249 &= ~ V_266 ;
V_249 &= ~ V_267 ;
switch ( * V_235 ) {
case V_268 :
V_249 |= V_269 ;
break;
case V_94 :
V_249 |= V_270 ;
break;
default:
return V_271 ;
}
V_28 = F_69 ( V_2 ,
F_76 ( V_2 -> V_17 . V_18 ) ,
V_250 , V_249 ) ;
if ( V_28 )
return V_28 ;
if ( V_2 -> V_4 . type == V_272 ) {
V_28 = F_70 ( V_2 ) ;
if ( V_28 )
return V_28 ;
}
V_28 = F_75 ( V_2 ) ;
return V_28 ;
}
static T_1 F_79 ( struct V_1 * V_2 , bool * V_273 )
{
switch ( V_2 -> V_6 . V_274 ) {
case V_275 :
return V_276 ;
case V_277 :
case V_278 :
* V_273 = true ;
break;
case V_279 :
case V_280 :
case V_281 :
case V_282 :
case V_283 :
case V_284 :
case V_285 :
case V_286 :
* V_273 = false ;
break;
case V_287 :
case V_288 :
case V_289 :
default:
return V_290 ;
}
return 0 ;
}
static T_1
F_80 ( struct V_1 * V_2 ,
T_6 V_235 ,
T_5 bool V_291 )
{
T_1 V_28 ;
T_3 V_292 , V_249 ;
bool V_293 = false ;
V_28 = F_79 ( V_2 , & V_293 ) ;
if ( V_28 == V_276 )
return 0 ;
if ( V_28 )
return V_28 ;
F_81 ( V_2 , V_235 ) ;
V_292 = V_294 + ( V_2 -> V_17 . V_18 << 12 ) ;
if ( V_293 )
V_249 = ( V_295 << 1 ) | 0x1 ;
else
V_249 = ( V_296 << 1 ) | 0x1 ;
V_28 = V_2 -> V_8 . V_9 . V_297 ( V_2 , V_2 -> V_8 . V_13 , V_292 ,
V_249 ) ;
return V_28 ;
}
static T_1 F_82 ( struct V_1 * V_2 , T_6 * V_235 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
T_1 V_28 ;
T_2 V_249 ;
V_28 = V_4 -> V_9 . V_260 ( V_2 ,
F_77 ( V_2 -> V_17 . V_18 ) ,
V_250 , & V_249 ) ;
if ( V_28 )
return V_28 ;
V_249 &= ~ V_298 ;
V_249 &= ~ V_299 ;
V_249 &= ~ V_300 ;
V_249 &= ~ V_301 ;
switch ( * V_235 ) {
case V_268 :
V_249 |= V_302 ;
break;
case V_94 :
V_249 |= V_303 ;
break;
default:
return V_271 ;
}
V_28 = V_4 -> V_9 . V_262 ( V_2 ,
F_77 ( V_2 -> V_17 . V_18 ) ,
V_250 , V_249 ) ;
V_28 = F_75 ( V_2 ) ;
return V_28 ;
}
static T_1
F_83 ( struct V_1 * V_2 , T_6 V_235 ,
T_5 bool V_291 )
{
bool V_293 = false ;
T_2 V_304 ;
T_1 V_305 ;
V_305 = F_79 ( V_2 , & V_293 ) ;
if ( V_305 == V_276 )
return 0 ;
if ( ! V_305 )
return V_305 ;
V_305 = V_2 -> V_4 . V_9 . V_260 ( V_2 ,
F_77 ( V_2 -> V_17 . V_18 ) ,
V_250 , & V_304 ) ;
if ( ! V_305 )
return V_305 ;
V_304 &= V_306 ;
if ( ! V_293 )
V_304 |= V_307 ;
V_305 = V_2 -> V_4 . V_9 . V_262 ( V_2 ,
F_77 ( V_2 -> V_17 . V_18 ) ,
V_250 , V_304 ) ;
if ( ! V_305 )
return V_305 ;
return F_82 ( V_2 , & V_235 ) ;
}
static T_1
F_84 ( struct V_1 * V_2 , T_6 V_235 ,
T_5 bool V_291 )
{
T_2 V_292 , V_308 ;
bool V_293 = false ;
T_3 V_309 ;
T_1 V_305 ;
V_305 = F_79 ( V_2 , & V_293 ) ;
if ( V_305 == V_276 )
return 0 ;
if ( ! V_305 )
return V_305 ;
F_81 ( V_2 , V_235 ) ;
if ( V_2 -> V_6 . V_310 . V_311 == V_312 )
return V_90 ;
V_305 = V_2 -> V_6 . V_9 . V_97 ( V_2 , V_313 ,
V_314 , & V_309 ) ;
if ( V_305 )
return V_305 ;
if ( V_309 == V_315 )
V_308 = ( V_2 -> V_17 . V_18 +
( V_2 -> V_17 . V_316 << 1 ) ) << 12 ;
else
V_308 = V_2 -> V_17 . V_18 << 12 ;
V_292 = V_294 + V_308 ;
if ( V_293 )
V_309 = ( V_295 << 1 ) | 1 ;
else
V_309 = ( V_296 << 1 ) | 1 ;
return V_2 -> V_6 . V_9 . V_98 ( V_2 , V_292 , V_314 ,
V_309 ) ;
}
static T_1 F_85 ( struct V_1 * V_2 ,
T_6 V_235 ,
bool V_317 )
{
T_1 V_28 ;
T_6 V_318 ;
if ( V_235 & V_268 )
V_318 = V_268 ;
else
V_318 = V_94 ;
if ( ! ( V_2 -> V_6 . V_319 & V_320 ) ) {
V_28 = F_78 ( V_2 , & V_318 ) ;
if ( V_28 )
return V_28 ;
}
return V_2 -> V_6 . V_9 . V_321 ( V_2 , V_235 , V_317 ) ;
}
static T_1 F_86 ( struct V_1 * V_2 ,
T_6 * V_235 ,
bool * V_322 ,
bool V_323 )
{
T_2 V_28 ;
T_3 V_78 , V_324 ;
if ( V_2 -> V_4 . V_9 . V_10 ( V_2 ) != V_11 )
return V_325 ;
V_28 = F_87 ( V_2 , V_235 , V_322 ,
V_323 ) ;
if ( V_28 || ! ( * V_322 ) )
return V_28 ;
for ( V_78 = 0 ; V_78 < 2 ; V_78 ++ ) {
V_28 = V_2 -> V_6 . V_9 . V_97 ( V_2 , V_326 , V_327 ,
& V_324 ) ;
if ( V_28 )
return V_28 ;
}
if ( ! ( V_324 & V_328 ) )
* V_322 = false ;
return 0 ;
}
static T_1
F_88 ( struct V_1 * V_2 , T_5 T_6 V_235 ,
T_5 bool V_291 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
T_2 V_329 , V_330 , V_331 ;
T_1 V_77 ;
V_77 = V_4 -> V_9 . V_260 ( V_2 ,
F_76 ( V_2 -> V_17 . V_18 ) ,
V_250 , & V_329 ) ;
if ( V_77 )
return V_77 ;
V_329 &= ~ V_266 ;
V_329 &= ~ V_267 ;
V_329 |= V_332 ;
V_329 |= V_333 ;
V_329 |= V_270 ;
V_77 = V_4 -> V_9 . V_262 ( V_2 ,
F_76 ( V_2 -> V_17 . V_18 ) ,
V_250 , V_329 ) ;
if ( V_77 )
return V_77 ;
V_77 = V_4 -> V_9 . V_260 ( V_2 ,
F_89 ( V_2 -> V_17 . V_18 ) ,
V_250 , & V_330 ) ;
if ( V_77 )
return V_77 ;
V_330 |= V_334 ;
V_330 |= V_335 ;
V_77 = V_4 -> V_9 . V_262 ( V_2 ,
F_89 ( V_2 -> V_17 . V_18 ) ,
V_250 , V_330 ) ;
if ( V_77 )
return V_77 ;
V_77 = V_4 -> V_9 . V_260 ( V_2 ,
F_77 ( V_2 -> V_17 . V_18 ) ,
V_250 , & V_331 ) ;
if ( V_77 )
return V_77 ;
V_77 = V_4 -> V_9 . V_260 ( V_2 ,
F_77 ( V_2 -> V_17 . V_18 ) ,
V_250 , & V_331 ) ;
if ( V_77 )
return V_77 ;
V_331 &= ~ V_301 ;
V_331 |= V_303 ;
V_331 &= ~ V_298 ;
V_331 |= V_300 ;
V_331 |= V_299 ;
V_77 = V_4 -> V_9 . V_262 ( V_2 ,
F_77 ( V_2 -> V_17 . V_18 ) ,
V_250 , V_331 ) ;
if ( V_77 )
return V_77 ;
V_77 = F_75 ( V_2 ) ;
return V_77 ;
}
static T_1 F_90 ( struct V_1 * V_2 , T_6 V_235 ,
bool V_317 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
T_2 V_329 , V_330 , V_331 ;
T_1 V_77 ;
V_77 = V_4 -> V_9 . V_260 ( V_2 ,
F_76 ( V_2 -> V_17 . V_18 ) ,
V_250 , & V_329 ) ;
if ( V_77 )
return V_77 ;
V_329 &= ~ V_266 ;
V_329 &= ~ V_267 ;
V_329 |= V_332 ;
V_329 |= V_333 ;
V_329 &= ~ V_270 ;
V_77 = V_4 -> V_9 . V_262 ( V_2 ,
F_76 ( V_2 -> V_17 . V_18 ) ,
V_250 , V_329 ) ;
if ( V_77 )
return V_77 ;
V_77 = V_4 -> V_9 . V_260 ( V_2 ,
F_89 ( V_2 -> V_17 . V_18 ) ,
V_250 , & V_330 ) ;
if ( V_77 )
return V_77 ;
V_330 &= ~ V_334 ;
V_330 &= ~ V_335 ;
V_77 = V_4 -> V_9 . V_262 ( V_2 ,
F_89 ( V_2 -> V_17 . V_18 ) ,
V_250 , V_330 ) ;
if ( V_77 )
return V_77 ;
V_77 = V_4 -> V_9 . V_262 ( V_2 ,
F_76 ( V_2 -> V_17 . V_18 ) ,
V_250 , V_329 ) ;
if ( V_77 )
return V_77 ;
V_77 = V_4 -> V_9 . V_260 ( V_2 ,
F_77 ( V_2 -> V_17 . V_18 ) ,
V_250 , & V_331 ) ;
if ( V_77 )
return V_77 ;
V_331 &= ~ V_301 ;
V_331 |= V_336 ;
V_331 &= ~ V_298 ;
V_331 |= V_300 ;
V_331 |= V_299 ;
V_77 = V_4 -> V_9 . V_262 ( V_2 ,
F_77 ( V_2 -> V_17 . V_18 ) ,
V_250 , V_331 ) ;
if ( V_77 )
return V_77 ;
F_75 ( V_2 ) ;
return V_2 -> V_6 . V_9 . V_321 ( V_2 , V_235 , V_317 ) ;
}
static void F_91 ( struct V_1 * V_2 )
{
T_1 V_28 = V_337 ;
T_2 V_73 [ V_74 ] = { 0 } ;
T_6 V_235 ;
bool V_322 ;
if ( V_2 -> V_103 . V_338 )
goto V_47;
V_2 -> V_4 . V_9 . V_339 ( V_2 , & V_235 , & V_322 , false ) ;
if ( ! V_322 )
goto V_47;
V_28 = F_32 ( V_2 , V_340 , & V_73 ) ;
if ( V_28 || ! ( V_73 [ 0 ] & V_341 ) ) {
V_28 = V_337 ;
goto V_47;
}
V_28 = F_92 ( V_2 , V_73 [ 0 ] , V_73 [ 0 ] ,
V_342 ,
V_343 ,
V_344 ,
V_345 ) ;
V_47:
if ( ! V_28 ) {
V_2 -> V_103 . V_346 = true ;
} else {
V_2 -> V_103 . V_346 = false ;
V_2 -> V_103 . V_347 = V_2 -> V_103 . V_105 ;
}
}
static void F_93 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
switch ( V_4 -> V_9 . V_10 ( V_2 ) ) {
case V_348 :
V_4 -> V_9 . V_349 = NULL ;
V_4 -> V_9 . V_350 = V_351 ;
break;
case V_11 :
if ( V_2 -> V_52 != V_352 &&
V_2 -> V_52 != V_353 ) {
V_4 -> V_9 . V_354 = F_85 ;
break;
}
V_4 -> V_9 . V_350 = F_91 ;
V_4 -> V_9 . V_349 = F_38 ;
V_4 -> V_9 . V_354 = F_90 ;
V_4 -> V_9 . V_339 = F_87 ;
break;
case V_355 :
V_4 -> V_9 . V_350 = V_356 ;
V_4 -> V_9 . V_349 = V_357 ;
break;
default:
break;
}
}
static void F_94 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
V_4 -> V_9 . V_349 = V_358 ;
switch ( V_4 -> V_9 . V_10 ( V_2 ) ) {
case V_348 :
V_4 -> V_9 . V_359 = NULL ;
V_4 -> V_9 . V_360 = NULL ;
V_4 -> V_9 . V_361 = NULL ;
V_4 -> V_9 . V_354 = V_362 ;
switch ( V_2 -> V_52 ) {
case V_58 :
V_4 -> V_9 . V_363 = F_83 ;
break;
case V_53 :
V_4 -> V_9 . V_363 =
F_84 ;
break;
default:
V_4 -> V_9 . V_363 =
F_80 ;
break;
}
V_4 -> V_9 . V_364 =
V_365 ;
break;
case V_11 :
V_4 -> V_9 . V_354 = F_85 ;
V_4 -> V_9 . V_349 = V_366 ;
V_4 -> V_9 . V_339 = F_86 ;
break;
case V_355 :
if ( V_2 -> V_52 == V_367 ||
V_2 -> V_52 == V_368 )
V_4 -> V_9 . V_354 = F_88 ;
break;
default:
break;
}
if ( V_2 -> V_4 . type == V_263 )
F_93 ( V_2 ) ;
}
static T_1 F_95 ( struct V_1 * V_2 )
{
T_1 V_28 ;
bool V_273 ;
V_28 = F_79 ( V_2 , & V_273 ) ;
if ( V_28 )
return V_28 ;
F_94 ( V_2 ) ;
V_2 -> V_6 . V_9 . V_369 = NULL ;
return 0 ;
}
static T_1 F_96 ( struct V_1 * V_2 ,
T_6 * V_235 ,
bool * V_370 )
{
if ( V_2 -> V_6 . type == V_96 ) {
* V_370 = true ;
* V_235 = V_2 -> V_6 . V_81 ;
return 0 ;
}
if ( V_2 -> V_6 . V_371 == V_348 ) {
* V_370 = false ;
if ( V_2 -> V_6 . V_274 == V_283 ||
V_2 -> V_6 . V_274 == V_284 ) {
* V_235 = V_94 ;
return 0 ;
}
if ( V_2 -> V_6 . V_372 )
* V_235 = V_268 |
V_94 ;
else
* V_235 = V_268 ;
} else {
* V_235 = V_268 |
V_94 ;
* V_370 = true ;
}
return 0 ;
}
static T_1 F_97 ( struct V_1 * V_2 , bool * V_373 )
{
T_2 V_28 ;
T_3 V_24 ;
* V_373 = false ;
V_28 = V_2 -> V_6 . V_9 . V_97 ( V_2 , V_374 ,
V_375 ,
& V_24 ) ;
if ( V_28 || ! ( V_24 & V_376 ) )
return V_28 ;
V_28 = V_2 -> V_6 . V_9 . V_97 ( V_2 , V_377 ,
V_375 ,
& V_24 ) ;
if ( V_28 || ! ( V_24 & ( V_378 |
V_379 ) ) )
return V_28 ;
V_28 = V_2 -> V_6 . V_9 . V_97 ( V_2 , V_380 ,
V_375 ,
& V_24 ) ;
if ( V_28 )
return V_28 ;
if ( V_24 & V_381 ) {
F_98 ( V_2 , false ) ;
return V_119 ;
}
if ( V_24 & V_382 ) {
V_28 = V_2 -> V_6 . V_9 . V_97 ( V_2 , V_383 ,
V_375 ,
& V_24 ) ;
if ( V_28 )
return V_28 ;
if ( V_24 == V_384 ) {
F_98 ( V_2 , false ) ;
return V_119 ;
}
}
V_28 = V_2 -> V_6 . V_9 . V_97 ( V_2 , V_374 ,
V_327 , & V_24 ) ;
if ( V_28 || ! ( V_24 & V_385 ) )
return V_28 ;
V_28 = V_2 -> V_6 . V_9 . V_97 ( V_2 , V_386 ,
V_327 , & V_24 ) ;
if ( V_28 )
return V_28 ;
if ( V_24 & V_387 )
* V_373 = true ;
return 0 ;
}
static T_1 F_99 ( struct V_1 * V_2 )
{
T_2 V_28 ;
T_3 V_24 ;
bool V_373 ;
V_28 = F_97 ( V_2 , & V_373 ) ;
V_28 = V_2 -> V_6 . V_9 . V_97 ( V_2 , V_388 ,
V_327 , & V_24 ) ;
if ( V_28 )
return V_28 ;
V_24 |= V_389 ;
V_28 = V_2 -> V_6 . V_9 . V_98 ( V_2 , V_388 ,
V_327 , V_24 ) ;
if ( V_28 )
return V_28 ;
V_28 = V_2 -> V_6 . V_9 . V_97 ( V_2 , V_390 ,
V_375 ,
& V_24 ) ;
if ( V_28 )
return V_28 ;
V_24 |= ( V_391 |
V_392 ) ;
V_28 = V_2 -> V_6 . V_9 . V_98 ( V_2 , V_390 ,
V_375 ,
V_24 ) ;
if ( V_28 )
return V_28 ;
V_28 = V_2 -> V_6 . V_9 . V_97 ( V_2 , V_393 ,
V_375 ,
& V_24 ) ;
if ( V_28 )
return V_28 ;
V_24 |= ( V_378 |
V_379 ) ;
V_28 = V_2 -> V_6 . V_9 . V_98 ( V_2 , V_393 ,
V_375 ,
V_24 ) ;
if ( V_28 )
return V_28 ;
V_28 = V_2 -> V_6 . V_9 . V_97 ( V_2 , V_394 ,
V_375 ,
& V_24 ) ;
if ( V_28 )
return V_28 ;
V_24 |= V_376 ;
V_28 = V_2 -> V_6 . V_9 . V_98 ( V_2 , V_394 ,
V_375 ,
V_24 ) ;
return V_28 ;
}
static T_1 F_100 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = & V_2 -> V_6 ;
bool V_373 ;
T_2 V_28 ;
V_28 = F_97 ( V_2 , & V_373 ) ;
if ( V_28 )
return V_28 ;
if ( V_373 && V_6 -> V_9 . V_395 )
return V_6 -> V_9 . V_395 ( V_2 ) ;
return 0 ;
}
static T_1 F_81 ( struct V_1 * V_2 ,
T_6 V_235 )
{
T_1 V_28 ;
T_2 V_249 ;
V_28 = V_2 -> V_4 . V_9 . V_260 ( V_2 ,
F_76 ( V_2 -> V_17 . V_18 ) ,
V_250 , & V_249 ) ;
if ( V_28 )
return V_28 ;
V_249 |= V_266 ;
V_249 &= ~ ( V_396 |
V_397 ) ;
if ( V_235 & V_268 )
V_249 |= V_396 ;
if ( V_235 & V_94 )
V_249 |= V_397 ;
V_28 = V_2 -> V_4 . V_9 . V_262 ( V_2 ,
F_76 ( V_2 -> V_17 . V_18 ) ,
V_250 , V_249 ) ;
if ( V_2 -> V_4 . type == V_263 ) {
V_28 = V_2 -> V_4 . V_9 . V_260 ( V_2 ,
F_77 ( V_2 -> V_17 . V_18 ) ,
V_250 , & V_249 ) ;
if ( V_28 )
return V_28 ;
V_249 &= ~ V_301 ;
V_249 |= V_336 ;
V_249 |= V_298 ;
V_249 &= ~ V_299 ;
V_249 &= ~ V_300 ;
V_28 = V_2 -> V_4 . V_9 . V_262 ( V_2 ,
F_77 ( V_2 -> V_17 . V_18 ) ,
V_250 , V_249 ) ;
}
return F_75 ( V_2 ) ;
}
static T_1 F_101 ( struct V_1 * V_2 )
{
T_1 V_28 ;
T_2 V_249 ;
V_28 = V_2 -> V_4 . V_9 . V_260 ( V_2 , V_398 ,
V_399 +
V_2 -> V_17 . V_18 , & V_249 ) ;
if ( V_28 )
return V_28 ;
V_249 &= ~ ( V_400 |
V_401 ) ;
V_249 |= V_402 ;
if ( V_2 -> V_6 . V_91 & V_268 )
V_249 |= V_400 ;
if ( V_2 -> V_6 . V_91 & V_94 )
V_249 |= V_401 ;
V_249 |= V_403 ;
V_28 = V_2 -> V_4 . V_9 . V_262 ( V_2 , V_398 ,
V_399 +
V_2 -> V_17 . V_18 , V_249 ) ;
return V_28 ;
}
static T_1 F_102 ( struct V_1 * V_2 )
{
if ( V_2 -> V_6 . V_91 & V_404 )
return 0 ;
return F_81 ( V_2 , V_2 -> V_6 . V_91 ) ;
}
static T_1 F_103 ( struct V_1 * V_2 , bool * V_322 )
{
T_2 V_137 ;
T_3 V_324 ;
* V_322 = false ;
V_137 = V_2 -> V_6 . V_9 . V_97 ( V_2 , V_326 , V_327 ,
& V_324 ) ;
if ( V_137 )
return V_137 ;
V_137 = V_2 -> V_6 . V_9 . V_97 ( V_2 , V_326 , V_327 ,
& V_324 ) ;
if ( V_137 )
return V_137 ;
* V_322 = ! ! ( V_324 & V_328 ) ;
return 0 ;
}
static T_1 F_104 ( struct V_1 * V_2 )
{
T_6 V_318 ;
bool V_322 ;
T_2 V_28 ;
T_3 V_235 ;
if ( V_2 -> V_4 . V_9 . V_10 ( V_2 ) != V_11 )
return V_325 ;
if ( V_2 -> V_6 . V_319 & V_320 ) {
V_235 = V_268 |
V_94 ;
return F_81 ( V_2 , V_235 ) ;
}
V_28 = F_103 ( V_2 , & V_322 ) ;
if ( V_28 )
return V_28 ;
if ( ! V_322 )
return 0 ;
V_28 = V_2 -> V_6 . V_9 . V_97 ( V_2 , V_405 ,
V_327 ,
& V_235 ) ;
if ( V_28 )
return V_28 ;
V_28 = F_103 ( V_2 , & V_322 ) ;
if ( V_28 )
return V_28 ;
if ( ! V_322 )
return 0 ;
V_235 &= V_406 ;
switch ( V_235 ) {
case V_407 :
V_318 = V_268 ;
break;
case V_408 :
V_318 = V_94 ;
break;
default:
return V_107 ;
}
return F_78 ( V_2 , & V_318 ) ;
}
static T_1 F_105 ( struct V_1 * V_2 )
{
T_1 V_28 ;
V_28 = F_106 ( V_2 ) ;
if ( V_28 )
return V_28 ;
return F_99 ( V_2 ) ;
}
static T_1 F_107 ( struct V_1 * V_2 , T_2 V_409 )
{
T_3 V_70 ;
if ( V_409 >= V_410 )
return V_204 ;
V_2 -> V_6 . V_9 . V_97 ( V_2 , V_411 + V_409 ,
V_375 , & V_70 ) ;
V_70 |= V_412 ;
V_2 -> V_6 . V_9 . V_98 ( V_2 , V_411 + V_409 ,
V_375 , V_70 ) ;
return 0 ;
}
static T_1 F_108 ( struct V_1 * V_2 , T_2 V_409 )
{
T_3 V_70 ;
if ( V_409 >= V_410 )
return V_204 ;
V_2 -> V_6 . V_9 . V_97 ( V_2 , V_411 + V_409 ,
V_375 , & V_70 ) ;
V_70 &= ~ V_412 ;
V_2 -> V_6 . V_9 . V_98 ( V_2 , V_411 + V_409 ,
V_375 , V_70 ) ;
return 0 ;
}
static T_1 F_109 ( struct V_1 * V_2 , T_4 V_413 , T_4 V_414 ,
T_4 V_415 , T_4 V_416 , T_3 V_417 ,
const char * V_418 )
{
struct V_419 V_241 ;
T_1 V_305 ;
int V_78 ;
if ( ! V_417 || ! V_418 || ( V_417 > sizeof( V_241 . V_420 ) ) )
return V_421 ;
V_241 . V_146 . V_147 = V_422 ;
V_241 . V_146 . V_149 = V_423 + V_417 ;
V_241 . V_146 . V_151 . V_152 = V_424 ;
V_241 . V_425 = ( T_4 ) V_2 -> V_17 . V_426 ;
V_241 . V_427 = V_413 ;
V_241 . V_428 = V_414 ;
V_241 . V_429 = V_415 ;
V_241 . V_430 = V_416 ;
V_241 . V_146 . V_153 = 0 ;
memcpy ( V_241 . V_420 , V_418 , V_417 ) ;
V_241 . V_146 . V_153 = F_110 ( ( T_4 * ) & V_241 ,
( V_431 + V_241 . V_146 . V_149 ) ) ;
for ( V_78 = 0 ; V_78 <= V_432 ; V_78 ++ ) {
V_305 = F_47 ( V_2 , ( T_2 * ) & V_241 ,
sizeof( V_241 ) ,
V_159 ,
true ) ;
if ( V_305 )
continue;
if ( V_241 . V_146 . V_151 . V_160 !=
V_433 )
return V_434 ;
return 0 ;
}
return V_305 ;
}
static T_1 F_111 ( struct V_1 * V_2 ,
T_6 * V_435 )
{
T_3 V_436 ;
T_1 V_28 ;
T_3 V_437 = V_2 -> V_50 . V_438 ;
* V_435 = V_439 ;
V_28 = V_2 -> V_6 . V_9 . V_97 ( V_2 , V_440 ,
V_327 ,
& V_436 ) ;
if ( V_28 )
return V_28 ;
if ( V_436 & V_441 ) {
* V_435 = V_94 ;
return V_28 ;
}
if ( ( V_2 -> V_17 . V_18 && ( V_437 & V_442 ) ) ||
( V_437 & V_443 ) )
return V_28 ;
* V_435 = V_268 ;
return V_28 ;
}
static T_1 V_358 ( struct V_1 * V_2 )
{
bool V_444 , V_445 ;
T_2 V_249 ;
T_1 V_77 ;
if ( V_2 -> V_103 . V_104 && V_2 -> V_103 . V_105 == V_106 ) {
F_13 ( V_2 , L_21 ) ;
return V_107 ;
}
if ( V_2 -> V_103 . V_105 == V_120 )
V_2 -> V_103 . V_105 = V_108 ;
switch ( V_2 -> V_103 . V_105 ) {
case V_446 :
V_444 = false ;
V_445 = false ;
break;
case V_112 :
V_444 = false ;
V_445 = true ;
break;
case V_106 :
case V_108 :
V_444 = true ;
V_445 = true ;
break;
default:
F_13 ( V_2 , L_22 ) ;
return V_325 ;
}
if ( V_2 -> V_52 != V_61 &&
V_2 -> V_52 != V_62 &&
V_2 -> V_52 != V_63 )
return 0 ;
V_77 = V_2 -> V_4 . V_9 . V_260 ( V_2 ,
F_112 ( V_2 -> V_17 . V_18 ) ,
V_250 ,
& V_249 ) ;
if ( V_77 )
return V_77 ;
V_249 &= ~ ( V_447 |
V_448 ) ;
if ( V_444 )
V_249 |= V_447 ;
if ( V_445 )
V_249 |= V_448 ;
V_77 = V_2 -> V_4 . V_9 . V_262 ( V_2 ,
F_112 ( V_2 -> V_17 . V_18 ) ,
V_250 ,
V_249 ) ;
V_2 -> V_103 . V_338 = true ;
return V_77 ;
}
static void V_356 ( struct V_1 * V_2 )
{
T_2 V_449 , V_450 , V_451 ;
T_1 V_28 = V_337 ;
T_6 V_235 ;
bool V_322 ;
if ( V_2 -> V_103 . V_338 ) {
F_13 ( V_2 , L_23 ) ;
goto V_47;
}
V_2 -> V_4 . V_9 . V_339 ( V_2 , & V_235 , & V_322 , false ) ;
if ( ! V_322 ) {
F_13 ( V_2 , L_24 ) ;
goto V_47;
}
V_28 = V_2 -> V_4 . V_9 . V_260 ( V_2 ,
F_113 ( V_2 -> V_17 . V_18 ) ,
V_250 , & V_449 ) ;
if ( V_28 || ( V_449 & V_452 ) == 0 ) {
F_42 ( V_2 , L_25 ) ;
V_28 = V_337 ;
goto V_47;
}
V_28 = V_2 -> V_4 . V_9 . V_260 ( V_2 ,
F_112 ( V_2 -> V_17 . V_18 ) ,
V_250 , & V_451 ) ;
if ( V_28 ) {
F_42 ( V_2 , L_25 ) ;
goto V_47;
}
V_28 = V_2 -> V_4 . V_9 . V_260 ( V_2 ,
F_114 ( V_2 -> V_17 . V_18 ) ,
V_250 , & V_450 ) ;
if ( V_28 ) {
F_42 ( V_2 , L_25 ) ;
goto V_47;
}
V_28 = F_92 ( V_2 , V_451 , V_450 ,
V_447 ,
V_448 ,
V_453 ,
V_454 ) ;
V_47:
if ( ! V_28 ) {
V_2 -> V_103 . V_346 = true ;
} else {
V_2 -> V_103 . V_346 = false ;
V_2 -> V_103 . V_347 = V_2 -> V_103 . V_105 ;
}
}
static void V_351 ( struct V_1 * V_2 )
{
V_2 -> V_103 . V_346 = false ;
V_2 -> V_103 . V_347 = V_2 -> V_103 . V_105 ;
}
static T_1 F_115 ( struct V_1 * V_2 )
{
T_3 V_455 , V_456 , V_235 ;
T_1 V_28 ;
T_6 V_435 ;
T_2 V_457 ;
bool V_322 ;
if ( F_37 ( V_2 ) )
return 0 ;
V_28 = F_103 ( V_2 , & V_322 ) ;
if ( V_28 )
return V_28 ;
V_28 = V_2 -> V_50 . V_9 . V_222 ( V_2 , V_458 ,
& V_2 -> V_50 . V_438 ) ;
if ( V_28 )
return V_28 ;
if ( ! V_322 || ! ( V_2 -> V_50 . V_438 & V_459 ) ||
! ( V_2 -> V_460 || F_116 ( V_2 ) ) )
return F_98 ( V_2 , false ) ;
V_28 = F_111 ( V_2 , & V_435 ) ;
if ( V_28 )
return V_28 ;
if ( V_435 == V_439 )
return F_98 ( V_2 , false ) ;
V_28 = V_2 -> V_6 . V_9 . V_97 ( V_2 , V_405 ,
V_327 ,
& V_235 ) ;
if ( V_28 )
return V_28 ;
V_28 = F_103 ( V_2 , & V_322 ) ;
if ( V_28 )
return F_98 ( V_2 , false ) ;
V_235 &= V_461 ;
if ( ( ( V_235 == V_462 ) &&
( V_435 == V_94 ) ) ||
( ( V_235 == V_463 ) &&
( V_435 == V_268 ) ) )
return V_28 ;
V_28 = V_2 -> V_6 . V_9 . V_97 ( V_2 , V_464 ,
V_327 ,
& V_456 ) ;
if ( V_28 )
return V_28 ;
V_28 = V_2 -> V_6 . V_9 . V_97 ( V_2 , V_465 ,
V_327 ,
& V_455 ) ;
if ( V_28 )
return V_28 ;
V_28 = V_2 -> V_6 . V_9 . V_97 ( V_2 ,
V_466 ,
V_327 ,
& V_456 ) ;
if ( V_28 )
return V_28 ;
V_457 = V_2 -> V_6 . V_91 ;
V_28 = V_2 -> V_4 . V_9 . V_354 ( V_2 , V_435 , false ) ;
V_2 -> V_6 . V_91 = V_457 ;
return V_28 ;
}
static T_1 F_117 ( struct V_1 * V_2 )
{
T_2 V_467 [ V_74 ] = { 0 } ;
T_1 V_77 ;
if ( V_2 -> V_6 . V_102 || F_37 ( V_2 ) )
return 0 ;
V_77 = F_32 ( V_2 , V_468 , & V_467 ) ;
if ( V_77 )
return V_77 ;
memset ( V_467 , 0 , sizeof( V_467 ) ) ;
V_77 = F_32 ( V_2 , V_469 , & V_467 ) ;
if ( V_77 )
return V_77 ;
return F_36 ( V_2 ) ;
}
static T_1 F_118 ( struct V_1 * V_2 )
{
T_2 V_467 [ V_74 ] = { 0 } ;
T_1 V_77 ;
V_77 = F_32 ( V_2 , V_340 , & V_467 ) ;
if ( V_77 )
return V_77 ;
if ( V_467 [ 0 ] & V_470 ) {
F_35 ( V_2 ) ;
return V_119 ;
}
return 0 ;
}
static void F_119 ( struct V_1 * V_2 )
{
V_2 -> V_6 . V_319 = F_6 ( V_2 , V_471 ) ;
if ( V_2 -> V_4 . type == V_263 &&
V_2 -> V_6 . V_319 & V_472 ) {
V_2 -> V_6 . V_310 . V_311 = ( V_2 -> V_6 . V_319 &
V_473 ) >>
V_474 ;
}
}
static T_1 F_120 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = & V_2 -> V_6 ;
T_1 V_305 ;
V_2 -> V_4 . V_9 . V_237 ( V_2 ) ;
F_119 ( V_2 ) ;
if ( V_2 -> V_4 . V_9 . V_10 ( V_2 ) == V_348 ) {
V_6 -> V_43 = V_57 ;
F_5 ( V_2 ) ;
}
V_305 = V_6 -> V_9 . V_475 ( V_2 ) ;
F_94 ( V_2 ) ;
if ( V_6 -> V_274 != V_287 )
V_6 -> V_9 . V_369 = NULL ;
switch ( V_2 -> V_6 . type ) {
case V_60 :
V_6 -> V_9 . V_354 = F_101 ;
V_6 -> V_9 . V_97 = F_23 ;
V_6 -> V_9 . V_98 = F_24 ;
break;
case V_64 :
V_6 -> V_9 . V_354 = F_102 ;
V_6 -> V_9 . V_97 = F_23 ;
V_6 -> V_9 . V_98 = F_24 ;
break;
case V_476 :
V_6 -> V_319 = F_6 ( V_2 , V_471 ) ;
V_6 -> V_9 . V_395 =
F_104 ;
if ( V_2 -> V_4 . type == V_272 &&
! ( F_6 ( V_2 , F_121 ( 0 ) ) &
V_477 ) )
V_6 -> V_9 . V_478 = F_115 ;
V_6 -> V_9 . V_479 = F_100 ;
V_6 -> V_9 . V_369 = F_105 ;
break;
case V_96 :
V_6 -> V_9 . V_354 = F_36 ;
V_6 -> V_9 . V_369 = F_117 ;
break;
default:
break;
}
return V_305 ;
}
static enum V_480 F_122 ( struct V_1 * V_2 )
{
enum V_480 V_371 ;
switch ( V_2 -> V_52 ) {
case V_367 :
case V_368 :
V_2 -> V_6 . type = V_481 ;
case V_61 :
case V_59 :
case V_62 :
case V_63 :
V_371 = V_355 ;
break;
case V_56 :
case V_53 :
case V_58 :
V_371 = V_348 ;
break;
case V_66 :
case V_67 :
case V_65 :
case V_352 :
case V_353 :
V_371 = V_11 ;
break;
default:
V_371 = V_482 ;
break;
}
return V_371 ;
}
static T_1 F_123 ( struct V_1 * V_2 )
{
T_1 V_28 ;
T_3 V_24 ;
V_28 = V_2 -> V_6 . V_9 . V_97 ( V_2 ,
V_483 ,
V_484 ,
& V_24 ) ;
if ( V_28 )
return V_28 ;
if ( V_24 & V_485 ) {
V_28 = V_2 -> V_6 . V_9 . V_97 ( V_2 ,
V_486 ,
V_375 ,
& V_24 ) ;
if ( V_28 )
return V_28 ;
V_24 &= ~ V_487 ;
V_28 = V_2 -> V_6 . V_9 . V_98 ( V_2 ,
V_486 ,
V_375 ,
V_24 ) ;
if ( V_28 )
return V_28 ;
}
return V_28 ;
}
static void F_124 ( struct V_1 * V_2 )
{
T_2 V_488 ;
switch ( V_2 -> V_52 ) {
case V_67 :
case V_367 :
case V_368 :
case V_65 :
case V_53 :
V_488 = F_6 ( V_2 , V_489 ) ;
V_488 &= ~ V_490 ;
F_7 ( V_2 , V_489 , V_488 ) ;
break;
case V_352 :
case V_353 :
V_488 = F_6 ( V_2 , V_489 ) ;
V_488 |= V_490 ;
F_7 ( V_2 , V_489 , V_488 ) ;
break;
default:
break;
}
}
static T_1 F_125 ( struct V_1 * V_2 )
{
T_6 V_491 ;
T_1 V_28 ;
T_2 V_130 = 0 ;
T_2 V_78 ;
bool V_322 = false ;
V_28 = V_2 -> V_4 . V_9 . V_492 ( V_2 ) ;
if ( V_28 )
return V_28 ;
F_126 ( V_2 ) ;
V_28 = V_2 -> V_6 . V_9 . V_493 ( V_2 ) ;
if ( V_2 -> V_6 . type == V_476 ) {
V_28 = F_123 ( V_2 ) ;
if ( V_28 )
return V_28 ;
}
if ( V_2 -> V_6 . V_494 ) {
V_28 = V_2 -> V_4 . V_9 . V_495 ( V_2 ) ;
V_2 -> V_6 . V_494 = false ;
}
if ( ! V_2 -> V_6 . V_102 && V_2 -> V_6 . V_9 . V_369 )
V_2 -> V_6 . V_9 . V_369 ( V_2 ) ;
V_496:
V_130 = V_497 ;
if ( ! V_2 -> V_498 ) {
V_2 -> V_4 . V_9 . V_339 ( V_2 , & V_491 , & V_322 , false ) ;
if ( V_322 )
V_130 = V_499 ;
}
V_130 |= F_6 ( V_2 , V_500 ) ;
F_7 ( V_2 , V_500 , V_130 ) ;
F_8 ( V_2 ) ;
F_17 ( 1000 , 1200 ) ;
for ( V_78 = 0 ; V_78 < 10 ; V_78 ++ ) {
V_130 = F_6 ( V_2 , V_500 ) ;
if ( ! ( V_130 & V_501 ) )
break;
F_44 ( 1 ) ;
}
if ( V_130 & V_501 ) {
V_28 = V_502 ;
F_42 ( V_2 , L_26 ) ;
}
F_18 ( 50 ) ;
if ( V_2 -> V_4 . V_503 & V_504 ) {
V_2 -> V_4 . V_503 &= ~ V_504 ;
goto V_496;
}
V_2 -> V_4 . V_9 . V_505 ( V_2 , V_2 -> V_4 . V_506 ) ;
V_2 -> V_4 . V_507 = 128 ;
V_2 -> V_4 . V_9 . V_508 ( V_2 ) ;
F_124 ( V_2 ) ;
if ( V_2 -> V_52 == V_56 )
F_5 ( V_2 ) ;
return V_28 ;
}
static void F_127 ( struct V_1 * V_2 ,
bool V_509 , int V_510 )
{
int V_511 = V_510 >> 3 ;
int V_512 = V_510 % 8 + V_513 ;
T_2 V_514 ;
V_514 = F_6 ( V_2 , F_128 ( V_511 ) ) ;
if ( V_509 )
V_514 |= F_41 ( V_512 ) ;
else
V_514 &= ~ F_41 ( V_512 ) ;
F_7 ( V_2 , F_128 ( V_511 ) , V_514 ) ;
}
static void F_129 ( struct V_1 * V_2 ,
bool V_509 ,
unsigned int V_515 )
{
T_7 V_516 ;
if ( V_515 > 63 )
return;
V_516 = ( T_7 ) F_6 ( V_2 , V_517 ) ;
V_516 |= ( T_7 ) F_6 ( V_2 , V_518 ) << 32 ;
if ( V_509 )
V_516 |= ( 1ULL << V_515 ) ;
else
V_516 &= ~ ( 1ULL << V_515 ) ;
F_7 ( V_2 , V_517 , ( T_2 ) V_516 ) ;
F_7 ( V_2 , V_518 , ( T_2 ) ( V_516 >> 32 ) ) ;
}
static T_1 V_357 ( struct V_1 * V_2 )
{
T_1 V_28 = 0 ;
T_2 V_519 = 0 ;
if ( V_2 -> V_103 . V_104 && V_2 -> V_103 . V_105 == V_106 ) {
F_13 ( V_2 , L_21 ) ;
return V_107 ;
}
if ( V_2 -> V_103 . V_105 == V_120 )
V_2 -> V_103 . V_105 = V_108 ;
V_28 = V_2 -> V_4 . V_9 . V_260 ( V_2 ,
F_112 ( V_2 -> V_17 . V_18 ) ,
V_250 , & V_519 ) ;
if ( V_28 ) {
F_42 ( V_2 , L_25 ) ;
return V_28 ;
}
switch ( V_2 -> V_103 . V_105 ) {
case V_446 :
V_519 &= ~ ( V_447 |
V_448 ) ;
break;
case V_112 :
V_519 |= V_448 ;
V_519 &= ~ V_447 ;
break;
case V_106 :
case V_108 :
V_519 |= V_447 |
V_448 ;
break;
default:
F_13 ( V_2 , L_22 ) ;
return V_325 ;
}
V_28 = V_2 -> V_4 . V_9 . V_262 ( V_2 ,
F_112 ( V_2 -> V_17 . V_18 ) ,
V_250 , V_519 ) ;
V_28 = F_75 ( V_2 ) ;
return V_28 ;
}
static void F_130 ( struct V_1 * V_2 , T_4 V_520 )
{
T_2 V_15 ;
if ( ! V_2 -> V_17 . V_18 )
return;
V_15 = F_6 ( V_2 , V_16 ) ;
if ( V_520 )
V_15 |= V_20 ;
else
V_15 &= ~ V_20 ;
F_7 ( V_2 , V_16 , V_15 ) ;
F_8 ( V_2 ) ;
}
static T_1 F_131 ( struct V_1 * V_2 , T_2 V_180 )
{
T_1 V_28 ;
V_28 = F_132 ( V_2 , V_180 ) ;
if ( V_28 )
return V_28 ;
if ( V_180 & V_521 )
F_130 ( V_2 , 1 ) ;
return 0 ;
}
static void F_133 ( struct V_1 * V_2 , T_2 V_180 )
{
if ( V_180 & V_521 )
F_130 ( V_2 , 0 ) ;
F_134 ( V_2 , V_180 ) ;
}
static T_1 F_135 ( struct V_1 * V_2 , T_2 V_180 )
{
T_2 V_522 = V_180 & ~ V_523 ;
int V_524 = V_525 ;
T_1 V_28 ;
while ( -- V_524 ) {
V_28 = 0 ;
if ( V_522 )
V_28 = F_132 ( V_2 , V_522 ) ;
if ( V_28 )
return V_28 ;
if ( ! ( V_180 & V_523 ) )
return 0 ;
V_28 = F_46 ( V_2 ) ;
if ( ! V_28 )
return 0 ;
if ( V_522 )
F_134 ( V_2 , V_522 ) ;
if ( V_28 != V_164 )
return V_28 ;
F_18 ( V_526 ) ;
}
return V_28 ;
}
static void F_136 ( struct V_1 * V_2 , T_2 V_180 )
{
T_2 V_522 = V_180 & ~ V_523 ;
if ( V_180 & V_523 )
F_48 ( V_2 ) ;
if ( V_522 )
F_134 ( V_2 , V_522 ) ;
}
static T_1 F_137 ( struct V_1 * V_2 , T_2 V_68 ,
T_2 V_69 , T_3 * V_70 )
{
T_2 V_180 = V_2 -> V_6 . V_43 | V_523 ;
T_1 V_28 ;
if ( V_2 -> V_4 . V_9 . V_44 ( V_2 , V_180 ) )
return V_228 ;
V_28 = V_2 -> V_6 . V_9 . V_527 ( V_2 , V_68 , V_69 , V_70 ) ;
V_2 -> V_4 . V_9 . V_49 ( V_2 , V_180 ) ;
return V_28 ;
}
static T_1 F_138 ( struct V_1 * V_2 , T_2 V_68 ,
T_2 V_69 , T_3 V_70 )
{
T_2 V_180 = V_2 -> V_6 . V_43 | V_523 ;
T_1 V_28 ;
if ( V_2 -> V_4 . V_9 . V_44 ( V_2 , V_180 ) )
return V_228 ;
V_28 = F_139 ( V_2 , V_68 , V_69 , V_70 ) ;
V_2 -> V_4 . V_9 . V_49 ( V_2 , V_180 ) ;
return V_28 ;
}
