struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
int V_5 ;
V_4 = F_2 ( sizeof( struct V_1 ) , V_6 ) ;
if ( ! V_4 ) {
F_3 ( V_3 -> V_7 , L_1
L_2 , V_3 -> V_8 -> V_9 ) ;
return NULL ;
}
V_4 -> V_3 = V_3 ;
for ( V_5 = 0 ; V_5 < V_10 ; V_5 ++ )
V_4 -> V_11 [ V_5 ] = true ;
V_4 -> V_11 [ V_12 ] = false ;
V_4 -> V_11 [ V_13 ] = false ;
V_4 -> V_11 [ V_14 ] = false ;
V_4 -> V_11 [ V_15 ] = false ;
V_4 -> V_16 = V_17 ;
V_4 -> V_18 = V_19 ;
V_4 -> V_20 = V_21 ;
V_4 -> V_22 = AUTO ;
V_4 -> V_23 = V_24 ;
V_4 -> V_25 = V_26 ;
V_4 -> V_27 = V_28 ;
if ( F_4 ( V_3 -> V_29 ) && F_5 ( V_3 -> V_29 -> V_30 , 2 ) )
V_4 -> V_31 = V_32 ;
else
V_4 -> V_31 = V_33 ;
V_4 -> V_34 = V_35 ;
V_4 -> V_36 = V_37 ;
for ( V_5 = 0 ; V_5 < V_10 ; V_5 ++ ) {
V_4 -> V_38 [ V_5 ] = V_4 -> V_34 ;
V_4 -> V_39 [ V_5 ] = V_4 -> V_36 ;
}
F_6 ( V_4 , V_4 -> V_23 ) ;
V_4 -> V_40 = false ;
F_7 ( V_4 , V_3 -> V_8 -> V_41 ) ;
V_4 -> V_42 = V_43 ;
F_8 ( V_4 ) ;
return V_4 ;
}
void F_9 ( struct V_1 * V_4 )
{
int V_5 ;
if ( ! V_4 )
return;
for ( V_5 = 0 ; V_5 < V_44 ; V_5 ++ ) {
F_10 ( V_4 -> V_45 [ V_5 ] ) ;
}
F_11 ( V_4 -> V_3 -> V_8 , L_3 , V_4 ) ;
F_10 ( V_4 ) ;
}
static void F_12 ( struct V_1 * V_4 ,
struct V_46 * V_46 )
{
struct V_47 * V_47 = F_13 ( V_4 , V_46 ) ;
int V_5 ;
V_47 -> V_22 = ( V_48 ) V_4 -> V_3 -> V_8 -> V_49 -> V_50 ;
for ( V_5 = 0 ; V_5 < V_51 ; V_5 ++ ) {
if ( V_4 -> V_52 [ V_5 ] . V_53 > V_54 )
V_47 -> V_22 = V_55 ;
}
if ( V_4 -> V_22 != AUTO )
V_47 -> V_22 = ( V_48 ) V_4 -> V_22 ;
V_47 -> V_56 = F_14 ( V_48 , V_47 -> V_22 , V_57 ) ;
if ( V_47 -> V_58 )
V_47 -> V_56 = F_14 ( V_48 , V_47 -> V_56 ,
V_47 -> V_58 / 1600 ) ;
V_47 -> V_56 = F_15 ( V_47 -> V_56 ,
V_4 -> V_52 [ V_59 ] .
V_60 [ V_61 ] ) ;
}
static void F_16 ( struct V_1 * V_4 )
{
F_12 ( V_4 , V_4 -> V_3 -> V_8 -> V_62 ) ;
}
static void F_8 ( struct V_1 * V_4 )
{
int V_5 , V_63 ;
struct V_64 * V_65 ;
for ( V_63 = 0 ; V_63 < V_51 ; V_63 ++ ) {
V_65 = ( V_4 -> V_52 + V_63 ) ;
V_65 -> V_53 = 0 ;
for ( V_5 = 0 ; V_5 <= V_61 ; V_5 ++ )
V_65 -> V_60 [ V_5 ] = 255 ;
V_65 -> V_66 = 0 ;
V_65 -> V_67 = 0 ;
V_65 -> V_68 = 0 ;
V_65 -> V_69 = 0 ;
}
}
static int F_17 ( struct V_2 * V_3 , int V_70 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
T_1 V_71 = F_18 ( V_61 , true , false ) ;
T_1 V_72 ;
V_48 V_73 ;
T_1 V_74 = 0 ;
T_2 V_75 ;
T_1 V_76 ;
struct V_64 * V_65 = ( V_4 -> V_52 + V_70 ) ;
T_3 V_77 ;
T_2 V_78 ;
V_78 = F_19 ( V_3 ,
V_79 +
F_20 ( struct V_80 , V_81 [ V_70 ] ) ) ;
V_76 = ( T_2 ) ( V_78 - V_65 -> V_68 ) ;
if ( V_76 == 0 ) {
F_21 ( V_3 -> V_7 , L_4 ) ;
return - 1 ;
}
V_65 -> V_68 = V_78 ;
if ( ! V_4 -> V_42 )
return 1 ;
if ( F_22 ( V_3 , V_70 , & V_77 ) )
return - 1 ;
if ( ( V_82 * ( T_1 ) V_77 ) <= V_4 -> V_27 )
return 1 ;
V_75 = V_82 * V_77 - V_4 -> V_27 ;
V_65 -> V_69 += V_76 ;
if ( V_65 -> V_69 < 10 )
return 0 ;
F_21 ( V_3 -> V_7 , L_5 ,
V_74 , V_65 -> V_69 ) ;
V_72 = V_74 / V_65 -> V_69 ;
if ( V_72 > V_4 -> V_42 ) {
if ( V_74 >= V_83 ) {
V_65 -> V_69 = 0 ;
}
return 0 ;
}
V_73 =
F_14 ( V_48 , V_65 -> V_60 [ V_61 ] , V_55 ) ;
if ( V_65 -> V_53 >= V_73 * V_84 ) {
V_65 -> V_69 = 0 ;
return 0 ;
}
if ( V_65 -> V_53 < V_75 ) {
V_65 -> V_53 += V_54 ;
if ( V_65 -> V_53 > V_75 )
V_65 -> V_53 = V_75 ;
F_16 ( V_4 ) ;
V_65 -> V_66 =
( ( ( V_71 / 100 ) *
( V_73 * V_84 - V_65 -> V_53 ) )
/ ( V_73 * V_84 ) ) * 100 ;
F_21 ( V_3 -> V_7 , L_6
L_7 ,
V_65 -> V_66 , V_65 -> V_53 ) ;
} else {
if ( V_65 -> V_60 [ V_61 ] > 1 ) {
if ( V_65 -> V_60 [ V_61 ] == 255 )
V_65 -> V_60 [ V_61 ] =
V_55 - 1 ;
else
V_65 -> V_60 [ V_61 ] -= 1 ;
F_23 ( V_4 , V_70 ) ;
F_16 ( V_4 ) ;
}
}
V_65 -> V_69 = 0 ;
return 0 ;
}
static void F_23 ( struct V_1 * V_4 , int V_85 )
{
int V_5 ;
T_1 V_71 , V_86 , V_87 ;
V_48 V_73 ;
struct V_64 * V_65 = ( V_4 -> V_52 + V_85 ) ;
V_73 =
F_14 ( V_48 , V_65 -> V_60 [ V_61 ] , V_55 ) ;
V_71 = F_18 ( V_61 , true , false ) ;
V_86 =
( ( ( V_71 / 100 ) *
( V_73 * V_84 - V_65 -> V_53 ) )
/ ( V_73 * V_84 ) ) * 100 ;
V_65 -> V_66 = V_86 ;
V_86 = V_86 >> 7 ;
for ( V_5 = 0 ; V_5 < V_61 ; V_5 ++ ) {
V_71 = F_18 ( V_5 , true , false ) >> 7 ;
if ( V_71 > V_86 ) {
V_87 = ( ( V_65 -> V_53 * V_71 ) /
( ( V_71 - V_86 ) * V_84 ) ) + 1 ;
V_87 = F_14 ( T_1 , V_87 , 255 ) ;
V_65 -> V_60 [ V_5 ] = ( V_48 ) V_87 ;
}
}
}
void
F_24 ( struct V_2 * V_3 , V_48 V_88 ,
V_48 V_89 ,
T_3 V_58 )
{
struct V_47 * V_47 ;
struct V_90 * V_91 ;
struct V_1 * V_4 = V_3 -> V_4 ;
struct V_46 * V_46 = V_3 -> V_8 -> V_62 ;
V_47 = F_13 ( V_4 , V_46 ) ;
if ( ! V_4 -> V_11 [ V_88 ] ) {
F_3 ( V_4 -> V_3 -> V_7 , L_8 ,
V_92 , V_88 ) ;
return;
}
V_91 = F_25 ( V_47 , V_88 ) ;
V_91 -> V_88 = V_88 ;
V_91 -> V_46 = V_47 -> V_46 ;
V_91 -> V_89 = V_89 ;
V_47 -> V_58 = V_58 ;
}
int
F_26 ( struct V_1 * V_4 , struct V_93 * V_94 ,
struct V_95 * * V_96 , int V_97 )
{
struct V_2 * V_3 ;
struct V_95 * V_98 , * V_99 [ V_100 ] ;
V_48 V_88 , V_101 ;
int V_102 = 0 ;
V_48 V_103 = V_104 ;
V_48 V_105 = V_104 ;
V_48 V_106 = V_107 ;
V_48 V_108 = V_107 ;
bool V_109 = true , V_110 = false ;
T_3 V_5 , V_111 = 0 , V_65 , V_112 = 0 ;
T_2 V_113 , V_114 , V_115 = 0 , V_116 , V_117 , V_118 , V_119 , V_120 = 0 ;
T_1 V_121 , V_122 = 0 ;
struct V_123 * V_124 = NULL ;
V_48 * V_125 ;
struct V_126 * V_127 ;
struct V_46 * V_46 ;
struct V_47 * V_47 ;
struct V_90 * V_91 ;
V_48 V_128 = 0 ;
bool V_129 = false , V_130 = false ;
T_4 V_131 = 0 , V_132 = 0 ;
T_4 V_133 = 0 , V_134 = 0 ;
T_2 V_135 = V_136 ;
struct V_137 * V_138 ;
V_48 V_36 ;
struct V_64 * V_85 ;
bool V_139 ;
struct V_140 * V_141 ;
T_2 V_142 ;
struct V_7 * V_7 ;
V_3 = V_4 -> V_3 ;
V_7 = V_3 -> V_7 ;
V_98 = * V_96 ;
V_88 = ( V_48 ) ( V_98 -> V_143 ) ;
V_85 = V_4 -> V_52 + V_144 [ V_88 ] ;
V_46 = V_3 -> V_8 -> V_62 ;
V_47 = F_13 ( V_4 , V_46 ) ;
V_91 = & V_47 -> V_91 [ V_88 ] ;
V_142 = F_27 ( & V_94 -> V_145 , V_97 ) ;
if ( V_91 -> V_146 > 0 &&
V_142 < F_15 ( V_47 -> V_22 , V_91 -> V_89 ) ) {
return - V_147 ;
}
V_36 = V_4 -> V_39 [ V_88 ] ;
V_121 = 0 ;
V_120 = 0 ;
while ( V_98 ) {
struct V_148 * V_149 ;
V_141 = F_28 ( V_98 ) ;
V_149 = V_141 -> V_150 . V_151 ;
if ( V_141 -> V_152 & V_153 ) {
V_102 = F_29 ( V_3 , V_98 , & V_65 ) ;
} else {
F_3 ( V_7 , L_9 , V_92 ) ;
* V_96 = NULL ;
V_102 = 0 ;
break;
}
if ( V_102 ) {
if ( V_102 == - V_147 ) {
F_3 ( V_7 , L_10
L_11 ,
V_3 -> V_8 -> V_9 , V_115 ) ;
* V_96 = V_98 ;
break;
}
F_3 ( V_7 , L_12
L_13 , V_3 -> V_8 -> V_9 , V_115 ) ;
* V_96 = NULL ;
break;
}
V_124 = (struct V_123 * ) V_98 -> V_154 ;
V_125 = ( V_48 * ) ( V_124 + 1 ) ;
V_127 = (struct V_126 * ) ( V_125 + V_155 ) ;
V_115 = F_30 ( V_127 -> V_156 ) >> V_157 ;
V_118 = F_31 ( V_115 ) ;
V_116 = F_30 ( V_124 -> V_158 ) ;
V_116 &= ~ V_159 ;
V_139 = ! ( F_30 ( V_124 -> V_160 ) & 0x3 ) ;
V_124 -> V_161 = 0 ;
if ( V_149 [ 0 ] . V_111 <= V_36 ) {
V_149 [ 0 ] . V_111 ++ ;
V_109 = true ;
V_110 = false ;
} else {
V_110 = true ;
V_109 = false ;
V_149 [ 1 ] . V_111 ++ ;
}
V_114 = V_139 ? F_32 ( V_124 -> V_162 )
: F_33 ( V_124 -> V_162 ) ;
V_101 = V_124 -> V_163 [ V_164 ] ;
V_112 += 1 ;
F_21 ( V_3 -> V_7 , L_14 ,
V_3 -> V_8 -> V_9 , V_111 , V_114 ) ;
if ( V_111 == 0 ) {
V_116 |= ( V_165 << V_166 ) ;
V_116 |= V_167 ;
V_138 = (struct V_137 * ) & V_124 -> V_168 ;
if ( F_34 ( V_138 -> V_169 ) ) {
V_116 |= V_170 ;
V_129 = true ;
}
if ( F_35 ( V_138 -> V_169 ) ) {
V_116 |= V_171 ;
V_130 = true ;
}
} else {
V_116 |= ( V_172 << V_166 ) ;
V_116 &= ~ ( V_167 | V_170 | V_171 ) ;
}
V_114 = F_36 ( V_114 , 4 ) ;
V_121 += ( V_114 + ( V_101 + 1 ) * V_173 ) ;
V_120 += ( T_2 ) F_37 ( V_98 ) ;
F_21 ( V_3 -> V_7 , L_15
L_16 ,
V_3 -> V_8 -> V_9 , V_121 , V_112 , V_101 ) ;
V_124 -> V_158 = F_38 ( V_116 ) ;
V_99 [ V_111 ++ ] = V_98 ;
if ( V_111 == 1 ) {
V_48 V_174 , V_175 , V_176 , V_177 ;
struct V_178 * V_179 ;
V_179 = V_141 -> V_180 . V_179 ;
if ( V_109 ) {
V_174 = V_125 [ 0 ] ;
V_175 = V_125 [ 3 ] ;
} else {
V_174 = V_124 -> V_162 [ 0 ] ;
V_175 = V_124 -> V_162 [ 3 ] ;
}
V_176 = ( V_174 & V_181 ) ? 1 : 0 ;
V_177 = F_39 ( V_175 ) ? 1 : 0 ;
V_128 = V_174 & ~ V_181 ;
V_122 =
F_15 ( V_47 -> V_58 ,
V_4 -> V_182 [ V_128 ] [ V_176 ] [ V_177 ] ) ;
if ( V_176 )
V_135 =
F_40 ( V_183 )
? V_184 : V_136 ;
V_131 = V_185 ;
V_131 |= V_125 [ 0 ] & ~ V_181 ;
if ( V_125 [ 0 ] & V_181 )
V_131 |= ( V_186 << V_187 ) ;
if ( V_139 )
V_132 =
F_41 ( F_42
( V_124 -> V_162 [ 0 ] ) ) ;
else {
V_132 = V_185 ;
V_132 |=
V_124 -> V_162 [ 0 ] & ~ V_181 ;
if ( V_124 -> V_162 [ 0 ] & V_181 )
V_132 |=
( V_186 <<
V_187 ) ;
}
if ( V_129 || V_130 ) {
V_133 =
F_43 ( V_3 ,
V_131 , false , V_135 ) ;
V_134 =
F_43 ( V_3 ,
V_132 , false , V_135 ) ;
}
}
if ( ( F_18 ( V_128 , true , false ) >= V_85 -> V_66 ) &&
( V_111 == V_85 -> V_60 [ V_128 ] ) ) {
F_21 ( V_3 -> V_7 , L_17
L_18 ,
V_3 -> V_8 -> V_9 , V_111 , V_128 ) ;
break;
}
if ( V_111 == V_47 -> V_22 ) {
break;
}
V_98 = F_44 ( & V_94 -> V_145 , V_97 ) ;
V_141 = F_28 ( V_98 ) ;
if ( V_98 ) {
if ( ( V_141 -> V_152 & V_153 ) &&
( ( V_48 ) ( V_98 -> V_143 ) == V_88 ) ) {
V_113 = F_37 ( V_98 ) +
V_188 ;
V_113 = F_45 ( V_47 -> V_189 , V_113 ) ;
if ( ( V_113 + V_121 ) > V_122 ) {
V_98 = NULL ;
continue;
}
if ( F_46 ( V_3 , V_65 ) <= ( V_112 + 1 ) ) {
F_3 ( V_7 , L_19
L_20 , V_92 ) ;
V_98 = NULL ;
continue;
}
V_98 = F_47 ( & V_94 -> V_145 , V_97 ) ;
} else {
V_98 = NULL ;
}
}
}
V_91 -> V_146 += V_111 ;
if ( V_111 ) {
V_124 = (struct V_123 * ) V_99 [ V_111 - 1 ] -> V_154 ;
V_116 = F_30 ( V_124 -> V_158 ) ;
V_116 &= ~ V_159 ;
V_116 |= ( V_190 << V_166 ) ;
V_124 -> V_158 = F_38 ( V_116 ) ;
V_101 = V_124 -> V_163 [ V_164 ] ;
V_124 -> V_163 [ V_164 ] = 0 ;
V_121 -= V_101 * V_173 ;
V_139 = ( ( F_30 ( V_124 -> V_160 ) & 0x3 ) == 0 ) ;
V_114 = V_139 ? F_32 ( V_124 -> V_162 )
: F_33 ( V_124 -> V_162 ) ;
V_121 -= F_36 ( V_114 , 4 ) - V_114 ;
V_124 = (struct V_123 * ) V_99 [ 0 ] -> V_154 ;
V_125 = ( V_48 * ) ( V_124 + 1 ) ;
F_48 ( V_125 , V_121 ) ;
F_49 ( V_125 ) ;
if ( V_124 -> V_191 ) {
T_2 V_192 =
F_50 ( V_3 , V_131 , V_121 ) ;
V_124 -> V_191 = F_38 ( V_192 ) ;
V_103 = V_193 ;
}
if ( V_124 -> V_194 ) {
T_2 V_195 =
F_50 ( V_3 , V_132 ,
V_121 ) ;
V_124 -> V_194 = F_38 ( V_195 ) ;
V_105 = V_193 ;
}
if ( F_18 ( V_128 , true , false ) >= V_85 -> V_66 ) {
V_120 = F_15 ( V_120 , V_85 -> V_53 ) ;
V_124 -> V_161 = F_38 ( V_120 ) ;
} else
V_124 -> V_161 = 0 ;
V_117 = F_30 ( V_124 -> V_196 ) ;
if ( V_129 || V_130 ) {
T_2 V_197 ;
V_138 = (struct V_137 * ) & V_124 -> V_168 ;
if ( ( V_117 & V_198 ) ==
V_198 )
V_106 = V_199 ;
if ( ( V_117 & V_200 ) ==
V_200 )
V_108 = V_199 ;
V_197 =
F_51 ( V_3 , V_130 , V_133 ,
V_131 , V_106 ,
V_103 , V_121 ,
true ) ;
V_138 -> V_201 = F_38 ( V_197 ) ;
V_197 = F_51 ( V_3 , V_130 ,
V_134 ,
V_132 ,
V_108 ,
V_105 ,
V_121 , true ) ;
V_124 -> V_202 = F_38 ( V_197 ) ;
V_124 -> V_203 = V_138 -> V_201 ;
V_124 -> V_204 = V_124 -> V_202 ;
}
if ( V_110 ) {
V_117 |= V_205 ;
V_124 -> V_196 = F_38 ( V_117 ) ;
F_49 ( V_125 ) ;
F_49 ( V_124 -> V_162 ) ;
}
F_21 ( V_3 -> V_7 , L_21 ,
V_3 -> V_8 -> V_9 , V_111 , V_121 ) ;
V_119 = F_30 ( V_124 -> V_206 ) ;
if ( V_119 & V_207 ) {
F_3 ( V_7 , L_22
L_23 , V_92 ) ;
}
for ( V_5 = 0 ; V_5 < V_111 ; V_5 ++ )
F_52 ( V_3 , V_65 , V_99 [ V_5 ] , V_5 == ( V_111 - 1 ) ,
V_4 -> V_25 ) ;
}
return V_102 ;
}
void
F_53 ( struct V_1 * V_4 , struct V_46 * V_46 ,
struct V_95 * V_98 , struct V_208 * V_209 )
{
struct V_47 * V_47 ;
struct V_2 * V_3 = V_4 -> V_3 ;
struct V_90 * V_91 ;
T_1 V_210 = 0 , V_211 = 0 ;
struct V_140 * V_141 ;
V_141 = F_28 ( V_98 ) ;
if ( V_209 -> V_150 & V_212 ) {
V_48 V_213 = 0 ;
while ( ( ( V_210 = F_54 ( & V_3 -> V_214 -> V_215 ) ) & V_216 ) == 0 ) {
F_55 ( 1 ) ;
V_213 ++ ;
if ( V_213 > 10 ) {
return;
}
}
V_211 = F_54 ( & V_3 -> V_214 -> V_217 ) ;
}
if ( F_56 ( V_46 ) ) {
V_47 = F_13 ( V_4 , V_46 ) ;
V_91 = F_25 ( V_47 , V_98 -> V_143 ) ;
F_57 ( V_4 , V_46 , V_98 , V_209 , V_210 , V_211 ) ;
} else {
V_48 V_218 = V_209 -> V_119 & V_219 ;
struct V_123 * V_124 ;
T_2 V_116 ;
while ( V_98 ) {
V_141 = F_28 ( V_98 ) ;
V_124 = (struct V_123 * ) V_98 -> V_154 ;
V_116 = F_30 ( V_124 -> V_158 ) ;
F_58 ( V_98 ) ;
if ( ( ( V_116 & V_159 ) >> V_166 ) ==
V_190 )
break;
V_98 = F_59 ( V_3 , V_218 ) ;
}
F_60 ( V_3 , V_218 , V_4 -> V_25 ) ;
}
F_61 ( V_3 , V_47 , V_91 ) ;
}
static void
F_62 ( struct V_2 * V_3 ,
struct V_140 * V_141 ,
struct V_208 * V_209 , V_48 V_128 )
{
struct V_148 * V_149 = V_141 -> V_150 . V_151 ;
int V_5 ;
for ( V_5 = 2 ; V_5 < V_220 ; V_5 ++ ) {
V_149 [ V_5 ] . V_221 = - 1 ;
V_149 [ V_5 ] . V_111 = 0 ;
}
}
static void
F_57 ( struct V_1 * V_4 , struct V_46 * V_46 ,
struct V_95 * V_98 , struct V_208 * V_209 ,
T_1 V_210 , T_1 V_211 )
{
struct V_47 * V_47 ;
struct V_2 * V_3 = V_4 -> V_3 ;
struct V_90 * V_91 ;
V_48 V_222 [ 8 ] , V_218 , V_88 ;
struct V_123 * V_124 ;
V_48 * V_125 ;
struct V_126 * V_127 ;
T_2 V_115 , V_223 = 0 , V_224 , V_118 , V_116 ;
V_48 V_128 = 0 ;
bool V_225 = false , V_226 = false ;
V_48 V_227 = 0 , V_228 = 0 ;
T_3 V_229 ;
bool V_230 = true , V_231 = true , V_232 = false ;
T_2 V_233 = 0 ;
V_48 V_234 = 0 ;
V_48 V_34 , V_36 ;
struct V_140 * V_141 = F_28 ( V_98 ) ;
struct V_7 * V_7 = V_3 -> V_7 ;
#ifdef F_63
V_48 V_235 [ V_100 ] ;
memset ( V_235 , 0 , sizeof( V_235 ) ) ;
#endif
V_47 = F_13 ( V_4 , V_46 ) ;
V_88 = ( V_48 ) ( V_98 -> V_143 ) ;
V_91 = F_25 ( V_47 , V_88 ) ;
V_34 = V_4 -> V_38 [ V_88 ] ;
V_36 = V_4 -> V_39 [ V_88 ] ;
memset ( V_222 , 0 , sizeof( V_222 ) ) ;
V_218 = V_209 -> V_119 & V_219 ;
V_229 = V_209 -> V_150 & V_236 ;
if ( V_209 -> V_150 & V_212 ) {
if ( V_237 == V_229 ) {
V_230 = false ;
}
F_64 ( ! ( V_209 -> V_150 & V_238 ) ) ;
V_223 = V_209 -> V_239 >> V_157 ;
V_222 [ 0 ] = ( V_209 -> V_150 & V_240 ) >>
V_241 ;
F_64 ( V_210 & V_238 ) ;
F_64 ( ! ( V_210 & V_242 ) ) ;
V_222 [ 0 ] |=
( V_210 & V_243 ) <<
V_244 ;
V_222 [ 1 ] = ( V_210 >> 8 ) & 0xff ;
V_222 [ 2 ] = ( V_210 >> 16 ) & 0xff ;
V_222 [ 3 ] = ( V_210 >> 24 ) & 0xff ;
V_222 [ 4 ] = V_211 & 0xff ;
V_222 [ 5 ] = ( V_211 >> 8 ) & 0xff ;
V_222 [ 6 ] = ( V_211 >> 16 ) & 0xff ;
V_222 [ 7 ] = ( V_211 >> 24 ) & 0xff ;
V_225 = true ;
} else {
if ( V_229 ) {
V_230 = false ;
if ( V_229 == V_245 ) {
F_3 ( V_7 , L_24
L_25 ,
V_92 , F_65 (
V_3 -> V_246 -> V_247 ) ) ;
} else {
if ( V_229 != V_248 )
F_3 ( V_7 , L_26
L_27 ,
V_92 , V_229 ) ;
}
if ( V_229 == V_245 ||
V_229 == V_249 ) {
V_231 = false ;
} else if ( V_229 == V_249 ) {
} else if ( V_229 == V_248 ) {
if ( F_17 ( V_3 ,
V_144 [ V_88 ] ) > 0 ) {
V_232 = true ;
}
}
} else if ( V_209 -> V_250 ) {
V_230 = false ;
F_3 ( V_7 , L_28
L_29 , V_3 -> V_8 -> V_9 ,
V_209 -> V_250 ) ;
if ( F_66 () ) {
F_67 ( L_30 , V_98 ) ;
F_68 ( (struct V_123 * ) V_98 -> V_154 ) ;
}
F_69 ( V_209 ) ;
}
}
while ( V_98 ) {
V_141 = F_28 ( V_98 ) ;
V_124 = (struct V_123 * ) V_98 -> V_154 ;
V_116 = F_30 ( V_124 -> V_158 ) ;
V_125 = ( V_48 * ) ( V_124 + 1 ) ;
V_127 = (struct V_126 * ) ( V_125 + V_155 ) ;
V_115 = F_30 ( V_127 -> V_156 ) >> V_157 ;
if ( V_228 == 0 ) {
V_128 = V_125 [ 0 ] & V_251 ;
V_233 = F_30 ( V_124 -> V_252 ) ;
}
V_118 = F_31 ( V_115 ) ;
V_226 = false ;
if ( V_225 ) {
V_224 = F_70 ( V_115 , V_223 , V_253 ) ;
F_21 ( V_3 -> V_7 , L_31
L_32 ,
V_88 , V_115 , V_223 , V_224 ,
F_71 ( V_222 , V_224 ) , V_118 ) ;
if ( ( V_224 < V_254 )
&& F_71 ( V_222 , V_224 ) ) {
V_91 -> V_146 -- ;
V_91 -> V_255 [ V_118 ] = 0 ;
F_62 ( V_3 , V_141 , V_209 ,
V_128 ) ;
V_141 -> V_152 |= V_256 ;
V_141 -> V_152 |= V_257 ;
V_141 -> V_150 . V_258 =
V_141 -> V_150 . V_121 = 1 ;
F_72 ( V_98 , V_155 ) ;
F_72 ( V_98 , V_259 ) ;
F_73 ( V_3 -> V_8 -> V_260 ,
V_98 ) ;
V_226 = true ;
V_227 ++ ;
}
}
if ( ! V_226 ) {
struct V_148 * V_149 =
V_141 -> V_150 . V_151 ;
if ( V_231 && ( V_149 [ 0 ] . V_111 < ( int ) V_34 ) ) {
V_91 -> V_255 [ V_118 ] ++ ;
V_91 -> V_146 -- ;
F_74 ( V_3 , V_46 , V_98 ,
F_75 ( V_88 ) ) ;
} else {
V_91 -> V_146 -- ;
F_76 ( V_141 ) ;
V_141 -> V_150 . V_258 = 0 ;
V_141 -> V_150 . V_121 = 1 ;
V_141 -> V_152 |=
V_261 ;
F_72 ( V_98 , V_155 ) ;
F_72 ( V_98 , V_259 ) ;
F_3 ( V_7 , L_33
L_34 , V_262 , V_115 ,
V_91 -> V_146 ) ;
F_73 ( V_3 -> V_8 -> V_260 ,
V_98 ) ;
}
}
V_228 ++ ;
if ( ( ( V_116 & V_159 ) >> V_166 ) ==
V_190 )
break;
V_98 = F_59 ( V_3 , V_218 ) ;
}
F_77 ( V_3 ) ;
V_234 = F_78 ( V_3 -> V_263 , V_233 ) ;
F_60 ( V_3 , V_218 , V_4 -> V_25 ) ;
}
static int F_7 ( struct V_1 * V_4 , bool V_264 )
{
struct V_2 * V_3 = V_4 -> V_3 ;
V_3 -> V_8 -> V_41 = false ;
if ( V_264 ) {
if ( ! F_79 ( V_3 -> V_8 ) ) {
F_3 ( V_4 -> V_3 -> V_7 , L_35
L_36 , V_3 -> V_8 -> V_9 ) ;
return - V_265 ;
}
if ( ! F_80 ( V_4 ) ) {
F_3 ( V_4 -> V_3 -> V_7 , L_37
L_38 , V_3 -> V_8 -> V_9 ) ;
return - V_265 ;
}
V_3 -> V_8 -> V_41 = V_264 ;
}
return 0 ;
}
static bool F_80 ( struct V_1 * V_4 )
{
if ( F_81 ( V_4 -> V_3 -> V_29 ) )
return true ;
else
return false ;
}
static void F_6 ( struct V_1 * V_4 , V_48 V_23 )
{
T_1 V_266 , V_128 ;
for ( V_128 = 0 ; V_128 < V_267 ; V_128 ++ ) {
V_266 = F_18 ( V_128 , false , false ) ;
V_4 -> V_182 [ V_128 ] [ 0 ] [ 0 ] = ( V_266 * V_23 ) >> 3 ;
V_266 = F_18 ( V_128 , true , false ) ;
V_4 -> V_182 [ V_128 ] [ 1 ] [ 0 ] = ( V_266 * V_23 ) >> 3 ;
V_266 = F_18 ( V_128 , false , true ) ;
V_4 -> V_182 [ V_128 ] [ 0 ] [ 1 ] = ( V_266 * V_23 ) >> 3 ;
V_266 = F_18 ( V_128 , true , true ) ;
V_4 -> V_182 [ V_128 ] [ 1 ] [ 1 ] = ( V_266 * V_23 ) >> 3 ;
}
}
void F_82 ( struct V_2 * V_3 )
{
char V_268 [ V_269 * 2 ] ;
memset ( V_268 , 0 , sizeof( V_268 ) ) ;
memcpy ( V_268 , V_3 -> V_8 -> V_270 , V_271 ) ;
F_83 ( V_3 , ( V_272 + 16 ) ,
( V_269 * 2 ) ,
V_268 ) ;
}
bool F_84 ( struct V_2 * V_3 , V_48 V_88 )
{
return V_3 -> V_4 -> V_11 [ V_88 ] ;
}
void F_85 ( struct V_1 * V_4 )
{
struct V_2 * V_3 = V_4 -> V_3 ;
if ( ( V_4 -> V_31 & V_273 ) ==
V_33 ) {
F_86 ( V_3 , V_274 , V_275 ) ;
F_86 ( V_3 , V_276 , V_277 ) ;
} else {
F_86 ( V_3 , V_274 , V_278 ) ;
F_86 ( V_3 , V_276 , V_279 ) ;
}
}
static bool F_87 ( struct V_95 * V_280 , void * V_281 )
{
struct V_140 * V_141 = F_28 ( V_280 ) ;
struct V_282 * V_283 =
(struct V_282 * ) V_281 ;
bool V_284 ;
V_284 = V_141 -> V_152 & V_153 ? true : false ;
V_284 = V_284 && ( V_141 -> V_180 . V_179 == NULL || V_283 -> V_179 == NULL ||
V_141 -> V_180 . V_179 == V_283 -> V_179 ) ;
V_284 = V_284 && ( ( V_48 ) ( V_280 -> V_143 ) == V_283 -> V_88 ) ;
return V_284 ;
}
static void F_88 ( void * V_285 , void * V_281 )
{
struct V_178 * V_179 = V_281 ;
struct V_140 * V_141 = (struct V_140 * ) V_285 ;
if ( ( V_141 -> V_152 & V_153 ) &&
( V_141 -> V_180 . V_179 == V_179 || V_179 == NULL ) )
V_141 -> V_180 . V_179 = NULL ;
}
void F_89 ( struct V_2 * V_3 ,
struct V_178 * V_179 , T_2 V_88 )
{
struct V_93 * V_94 = V_3 -> V_286 ;
struct V_287 * V_288 = & V_94 -> V_145 ;
int V_97 ;
struct V_282 V_283 ;
V_283 . V_179 = V_179 ;
V_283 . V_88 = V_88 ;
for ( V_97 = 0 ; V_97 < V_288 -> V_289 ; V_97 ++ ) {
F_90 ( V_288 , V_97 , true , F_87 ,
( void * ) & V_283 ) ;
}
F_91 ( V_3 -> V_290 , V_179 , F_88 ) ;
}
