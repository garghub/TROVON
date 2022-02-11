enum V_1 F_1 ( struct V_2 * V_3 )
{
switch ( V_3 -> type ) {
case V_4 :
return F_2 ( & V_3 -> V_5 ) -> V_6 -> V_1 ;
case V_7 :
case V_8 :
case V_9 :
case V_10 :
return F_3 ( & V_3 -> V_5 ) -> V_1 ;
case V_11 :
return V_12 ;
default:
F_4 ( V_3 -> type ) ;
return V_13 ;
}
}
static const struct V_14 *
F_5 ( struct V_15 * V_16 , int * V_17 )
{
if ( V_16 -> V_18 . V_19 . V_20 ) {
* V_17 = F_6 ( V_21 ) ;
return V_21 ;
} else {
* V_17 = F_6 ( V_22 ) ;
return V_22 ;
}
}
static const struct V_14 *
F_7 ( struct V_15 * V_16 , int * V_17 )
{
if ( F_8 ( V_16 ) ) {
* V_17 = F_6 ( V_23 ) ;
return V_23 ;
} else if ( F_9 ( V_16 ) ) {
* V_17 = F_6 ( V_24 ) ;
return V_24 ;
} else {
* V_17 = F_6 ( V_25 ) ;
return V_25 ;
}
}
static const struct V_14 *
F_10 ( struct V_15 * V_16 , int * V_17 )
{
if ( F_11 ( V_16 ) ) {
* V_17 = F_6 ( V_26 ) ;
return V_26 ;
} else if ( F_12 ( V_16 ) ) {
* V_17 = F_6 ( V_27 ) ;
return V_27 ;
} else {
* V_17 = F_6 ( V_28 ) ;
return V_28 ;
}
}
static const struct V_14 *
F_13 ( struct V_15 * V_16 , int * V_17 )
{
if ( V_16 -> V_18 . V_19 . V_20 ) {
if ( F_8 ( V_16 ) || F_11 ( V_16 ) ) {
* V_17 = F_6 ( V_29 ) ;
return V_29 ;
} else if ( F_9 ( V_16 ) || F_12 ( V_16 ) ) {
* V_17 = F_6 ( V_30 ) ;
return V_30 ;
} else {
* V_17 = F_6 ( V_31 ) ;
return V_31 ;
}
}
if ( F_14 ( V_16 ) )
return F_10 ( V_16 , V_17 ) ;
else
return F_7 ( V_16 , V_17 ) ;
}
static const struct V_14 *
F_15 ( struct V_15 * V_16 , int * V_17 )
{
if ( F_8 ( V_16 ) || F_11 ( V_16 ) ) {
* V_17 = F_6 ( V_32 ) ;
return V_32 ;
} else {
* V_17 = F_6 ( V_33 ) ;
return V_33 ;
}
}
static int F_16 ( struct V_15 * V_16 , enum V_1 V_1 )
{
int V_34 ;
int V_35 ;
int V_36 ;
V_35 = V_16 -> V_18 . V_37 [ V_1 ] . V_38 ;
if ( F_17 ( V_16 ) )
return V_35 ;
if ( F_18 ( V_16 ) || F_14 ( V_16 ) ) {
F_15 ( V_16 , & V_34 ) ;
V_36 = 8 ;
} else if ( F_19 ( V_16 ) ) {
V_34 = F_6 ( V_39 ) ;
V_36 = 7 ;
} else if ( F_20 ( V_16 ) ) {
V_34 = F_6 ( V_40 ) ;
V_36 = 6 ;
} else {
F_21 ( 1 , L_1 ) ;
V_34 = F_6 ( V_39 ) ;
V_36 = 7 ;
}
if ( V_35 == V_41 ||
V_35 >= V_34 )
V_35 = V_36 ;
return V_35 ;
}
void F_22 ( struct V_2 * V_3 )
{
struct V_15 * V_16 = F_23 ( V_3 -> V_5 . V_42 ) ;
T_1 V_43 = 0 ;
int V_44 , V_45 , V_46 , V_47 ;
enum V_1 V_1 = F_1 ( V_3 ) ;
const struct V_14 * V_48 ;
const struct V_14 * V_49 ;
const struct V_14 * V_50 ;
const struct V_14 * V_51 ;
if ( F_17 ( V_16 ) )
return;
if ( F_14 ( V_16 ) ) {
V_48 = NULL ;
V_49 =
F_10 ( V_16 , & V_45 ) ;
V_50 =
F_13 ( V_16 , & V_46 ) ;
} else if ( F_18 ( V_16 ) ) {
V_48 = NULL ;
V_49 =
F_7 ( V_16 , & V_45 ) ;
V_50 =
F_13 ( V_16 , & V_46 ) ;
} else if ( F_19 ( V_16 ) ) {
V_48 = V_52 ;
V_49 = V_22 ;
V_50 = F_5 ( V_16 , & V_46 ) ;
V_45 = F_6 ( V_22 ) ;
} else if ( F_20 ( V_16 ) ) {
V_48 = V_53 ;
V_49 = V_54 ;
V_50 = V_54 ;
V_45 = V_46 = F_6 ( V_54 ) ;
} else {
F_21 ( 1 , L_1 ) ;
V_50 = V_22 ;
V_48 = V_52 ;
V_49 = V_22 ;
V_46 = F_6 ( V_21 ) ;
V_45 = F_6 ( V_22 ) ;
}
if ( F_18 ( V_16 ) || F_14 ( V_16 ) ) {
if ( V_16 -> V_18 . V_37 [ V_1 ] . V_55 )
V_43 = V_56 ;
if ( F_24 ( V_3 -> type == V_8 &&
V_1 != V_13 && V_1 != V_12 &&
V_46 > 9 ) )
V_46 = 9 ;
}
switch ( V_3 -> type ) {
case V_8 :
V_51 = V_50 ;
V_47 = V_46 ;
break;
case V_7 :
V_51 = V_49 ;
V_47 = V_45 ;
break;
case V_11 :
V_51 = V_48 ;
V_47 = V_45 ;
break;
default:
F_25 () ;
}
for ( V_44 = 0 ; V_44 < V_47 ; V_44 ++ ) {
F_26 ( F_27 ( V_1 , V_44 ) ,
V_51 [ V_44 ] . V_57 | V_43 ) ;
F_26 ( F_28 ( V_1 , V_44 ) ,
V_51 [ V_44 ] . V_58 ) ;
}
}
static void F_29 ( struct V_2 * V_3 )
{
struct V_15 * V_16 = F_23 ( V_3 -> V_5 . V_42 ) ;
T_1 V_43 = 0 ;
int V_34 , V_35 ;
enum V_1 V_1 = F_1 ( V_3 ) ;
const struct V_14 * V_59 ;
if ( F_17 ( V_16 ) )
return;
V_35 = F_16 ( V_16 , V_1 ) ;
if ( F_18 ( V_16 ) || F_14 ( V_16 ) ) {
V_59 = F_15 ( V_16 , & V_34 ) ;
if ( V_16 -> V_18 . V_37 [ V_1 ] . V_60 )
V_43 = V_56 ;
} else if ( F_19 ( V_16 ) ) {
V_59 = V_39 ;
V_34 = F_6 ( V_39 ) ;
} else if ( F_20 ( V_16 ) ) {
V_59 = V_40 ;
V_34 = F_6 ( V_40 ) ;
} else {
F_21 ( 1 , L_1 ) ;
V_59 = V_39 ;
V_34 = F_6 ( V_39 ) ;
}
F_26 ( F_27 ( V_1 , 9 ) ,
V_59 [ V_35 ] . V_57 | V_43 ) ;
F_26 ( F_28 ( V_1 , 9 ) ,
V_59 [ V_35 ] . V_58 ) ;
}
static void F_30 ( struct V_15 * V_16 ,
enum V_1 V_1 )
{
T_2 V_61 = F_31 ( V_1 ) ;
int V_44 ;
for ( V_44 = 0 ; V_44 < 16 ; V_44 ++ ) {
F_32 ( 1 ) ;
if ( F_33 ( V_61 ) & V_62 )
return;
}
F_34 ( L_2 , F_35 ( V_1 ) ) ;
}
static T_3 F_36 ( struct V_63 * V_64 )
{
switch ( V_64 -> V_65 ) {
case V_66 :
return V_67 ;
case V_68 :
return V_69 ;
case V_70 :
return V_71 ;
case V_72 :
return V_73 ;
case V_74 :
return V_75 ;
case V_76 :
return V_77 ;
default:
F_4 ( V_64 -> V_65 ) ;
return V_78 ;
}
}
void F_37 ( struct V_79 * V_80 )
{
struct V_81 * V_42 = V_80 -> V_42 ;
struct V_15 * V_16 = F_23 ( V_42 ) ;
struct V_82 * V_82 = F_38 ( V_80 ) ;
struct V_2 * V_3 ;
T_1 V_83 , V_44 , V_84 , V_85 ;
F_39 (dev, crtc, encoder) {
F_24 ( V_3 -> type != V_11 ) ;
F_22 ( V_3 ) ;
}
F_26 ( F_40 ( V_86 ) , F_41 ( 2 ) |
F_42 ( 2 ) |
V_87 | V_88 ) ;
V_84 = V_16 -> V_89 | V_90 |
V_91 |
F_43 ( V_82 -> V_92 -> V_93 ) ;
F_26 ( F_44 ( V_86 ) , V_84 ) ;
F_45 ( F_44 ( V_86 ) ) ;
F_32 ( 220 ) ;
V_84 |= V_94 ;
F_26 ( F_44 ( V_86 ) , V_84 ) ;
V_85 = F_36 ( V_82 -> V_92 -> V_95 ) ;
F_26 ( F_46 ( V_12 ) , V_85 ) ;
F_24 ( V_85 != V_71 ) ;
for ( V_44 = 0 ; V_44 < F_6 ( V_53 ) * 2 ; V_44 ++ ) {
F_26 ( F_47 ( V_12 ) ,
V_96 |
V_97 |
V_98 |
V_99 ) ;
F_26 ( F_31 ( V_12 ) ,
V_100 |
( ( V_82 -> V_92 -> V_93 - 1 ) << 1 ) |
F_48 ( V_44 / 2 ) ) ;
F_45 ( F_31 ( V_12 ) ) ;
F_32 ( 600 ) ;
F_26 ( F_49 ( V_86 ) , F_50 ( 64 ) ) ;
V_84 |= V_101 | V_102 ;
F_26 ( F_44 ( V_86 ) , V_84 ) ;
F_45 ( F_44 ( V_86 ) ) ;
F_32 ( 30 ) ;
V_83 = F_33 ( F_40 ( V_86 ) ) ;
V_83 &= ~ ( V_103 | V_104 ) ;
F_26 ( F_40 ( V_86 ) , V_83 ) ;
F_45 ( F_40 ( V_86 ) ) ;
F_32 ( 5 ) ;
V_83 = F_33 ( F_51 ( V_12 ) ) ;
if ( V_83 & V_105 ) {
F_52 ( L_3 , V_44 ) ;
break;
}
if ( V_44 == F_6 ( V_53 ) * 2 - 1 ) {
F_34 ( L_4 ) ;
break;
}
V_84 &= ~ V_101 ;
F_26 ( F_44 ( V_86 ) , V_84 ) ;
F_45 ( F_44 ( V_86 ) ) ;
V_83 = F_33 ( F_31 ( V_12 ) ) ;
V_83 &= ~ V_100 ;
F_26 ( F_31 ( V_12 ) , V_83 ) ;
F_45 ( F_31 ( V_12 ) ) ;
V_83 = F_33 ( F_47 ( V_12 ) ) ;
V_83 &= ~ ( V_99 | V_106 ) ;
V_83 |= V_98 ;
F_26 ( F_47 ( V_12 ) , V_83 ) ;
F_45 ( F_47 ( V_12 ) ) ;
F_30 ( V_16 , V_12 ) ;
V_83 = F_33 ( F_40 ( V_86 ) ) ;
V_83 &= ~ ( V_103 | V_104 ) ;
V_83 |= F_41 ( 2 ) | F_42 ( 2 ) ;
F_26 ( F_40 ( V_86 ) , V_83 ) ;
F_45 ( F_40 ( V_86 ) ) ;
}
F_26 ( F_47 ( V_12 ) ,
V_96 |
V_107 |
V_97 |
V_99 ) ;
}
void F_53 ( struct V_2 * V_3 )
{
struct V_108 * V_108 = F_54 ( & V_3 -> V_5 ) ;
struct V_109 * V_110 =
F_3 ( & V_3 -> V_5 ) ;
V_108 -> V_111 = V_110 -> V_112 |
V_100 | F_48 ( 0 ) ;
V_108 -> V_111 |= F_55 ( V_108 -> V_113 ) ;
}
static struct V_2 *
F_56 ( struct V_79 * V_80 )
{
struct V_81 * V_42 = V_80 -> V_42 ;
struct V_82 * V_82 = F_38 ( V_80 ) ;
struct V_2 * V_2 , * V_114 = NULL ;
int V_115 = 0 ;
F_39 (dev, crtc, intel_encoder) {
V_114 = V_2 ;
V_115 ++ ;
}
if ( V_115 != 1 )
F_21 ( 1 , L_5 , V_115 ,
F_57 ( V_82 -> V_116 ) ) ;
F_58 ( V_114 == NULL ) ;
return V_114 ;
}
struct V_2 *
F_59 ( struct V_117 * V_118 )
{
struct V_82 * V_80 = F_38 ( V_118 -> V_5 . V_80 ) ;
struct V_2 * V_114 = NULL ;
struct V_119 * V_120 ;
struct V_121 * V_122 ;
struct V_123 * V_124 ;
int V_115 = 0 ;
int V_44 ;
V_120 = V_118 -> V_5 . V_120 ;
F_60 (state, connector, connector_state, i) {
if ( V_124 -> V_80 != V_118 -> V_5 . V_80 )
continue;
V_114 = F_61 ( V_124 -> V_125 ) ;
V_115 ++ ;
}
F_21 ( V_115 != 1 , L_5 , V_115 ,
F_57 ( V_80 -> V_116 ) ) ;
F_58 ( V_114 == NULL ) ;
return V_114 ;
}
static int F_62 ( struct V_15 * V_16 ,
T_2 V_61 )
{
int V_126 = V_127 ;
int V_128 , V_129 , V_130 ;
T_1 V_131 ;
V_131 = F_33 ( V_61 ) ;
switch ( V_131 & V_132 ) {
case V_133 :
case V_134 :
V_126 = 135 ;
break;
case V_135 :
V_126 = V_127 ;
break;
default:
F_21 ( 1 , L_6 ) ;
return 0 ;
}
V_130 = V_131 & V_136 ;
V_129 = ( V_131 & V_137 ) >> V_138 ;
V_128 = ( V_131 & V_139 ) >> V_140 ;
return ( V_126 * V_128 * 100 ) / ( V_129 * V_130 ) ;
}
static int F_63 ( struct V_15 * V_16 ,
T_3 V_141 )
{
T_2 V_142 , V_143 ;
T_3 V_144 , V_145 ;
T_3 V_146 , V_147 , V_148 , V_149 ;
V_142 = F_64 ( V_141 ) ;
V_143 = F_65 ( V_141 ) ;
V_144 = F_33 ( V_142 ) ;
V_145 = F_33 ( V_143 ) ;
V_146 = V_145 & V_150 ;
V_148 = V_145 & V_151 ;
if ( V_145 & F_66 ( 1 ) )
V_147 = ( V_145 & V_152 ) >> 8 ;
else
V_147 = 1 ;
switch ( V_146 ) {
case V_153 :
V_146 = 1 ;
break;
case V_154 :
V_146 = 2 ;
break;
case V_155 :
V_146 = 3 ;
break;
case V_156 :
V_146 = 7 ;
break;
}
switch ( V_148 ) {
case V_157 :
V_148 = 5 ;
break;
case V_158 :
V_148 = 2 ;
break;
case V_159 :
V_148 = 3 ;
break;
case V_160 :
V_148 = 1 ;
break;
}
V_149 = ( V_144 & V_161 ) * 24 * 1000 ;
V_149 += ( ( ( V_144 & V_162 ) >> 9 ) * 24 *
1000 ) / 0x8000 ;
return V_149 / ( V_146 * V_147 * V_148 * 5 ) ;
}
static void F_67 ( struct V_117 * V_163 )
{
int V_164 ;
if ( V_163 -> V_165 )
V_164 = F_68 ( V_163 -> V_166 ,
& V_163 -> V_167 ) ;
else if ( F_69 ( V_163 ) )
V_164 = F_68 ( V_163 -> V_166 ,
& V_163 -> V_168 ) ;
else if ( V_163 -> V_169 && V_163 -> V_170 == 36 )
V_164 = V_163 -> V_166 * 2 / 3 ;
else
V_164 = V_163 -> V_166 ;
if ( V_163 -> V_171 )
V_164 /= V_163 -> V_171 ;
V_163 -> V_5 . V_172 . V_173 = V_164 ;
}
static void F_70 ( struct V_2 * V_3 ,
struct V_117 * V_163 )
{
struct V_15 * V_16 = F_23 ( V_3 -> V_5 . V_42 ) ;
int V_174 = 0 ;
T_3 V_175 , V_141 ;
V_141 = F_71 ( V_16 , V_163 -> V_95 ) ;
V_175 = F_33 ( V_176 ) ;
if ( V_175 & F_72 ( V_141 ) ) {
V_174 = F_63 ( V_16 , V_141 ) ;
} else {
V_174 = V_175 & F_73 ( V_141 ) ;
V_174 >>= F_74 ( V_141 ) ;
switch ( V_174 ) {
case V_177 :
V_174 = 81000 ;
break;
case V_178 :
V_174 = 108000 ;
break;
case V_179 :
V_174 = 135000 ;
break;
case V_180 :
V_174 = 162000 ;
break;
case V_181 :
V_174 = 216000 ;
break;
case V_182 :
V_174 = 270000 ;
break;
default:
F_21 ( 1 , L_7 ) ;
break;
}
V_174 *= 2 ;
}
V_163 -> V_166 = V_174 ;
F_67 ( V_163 ) ;
}
static void F_75 ( struct V_2 * V_3 ,
struct V_117 * V_163 )
{
struct V_15 * V_16 = F_23 ( V_3 -> V_5 . V_42 ) ;
int V_174 = 0 ;
T_1 V_183 , V_64 ;
V_183 = F_36 ( V_163 -> V_95 ) ;
switch ( V_183 & V_184 ) {
case V_73 :
V_174 = 81000 ;
break;
case V_75 :
V_174 = 135000 ;
break;
case V_77 :
V_174 = 270000 ;
break;
case V_67 :
V_174 = F_62 ( V_16 , F_76 ( 0 ) ) ;
break;
case V_69 :
V_174 = F_62 ( V_16 , F_76 ( 1 ) ) ;
break;
case V_71 :
V_64 = F_33 ( V_185 ) & V_186 ;
if ( V_64 == V_187 )
V_174 = 81000 ;
else if ( V_64 == V_188 )
V_174 = 135000 ;
else if ( V_64 == V_189 )
V_174 = 270000 ;
else {
F_21 ( 1 , L_8 ) ;
return;
}
break;
default:
F_21 ( 1 , L_9 ) ;
return;
}
V_163 -> V_166 = V_174 * 2 ;
F_67 ( V_163 ) ;
}
static int F_77 ( struct V_15 * V_16 ,
enum V_190 V_141 )
{
struct V_63 * V_64 ;
struct V_191 * V_120 ;
struct V_141 clock ;
if ( F_24 ( V_141 == V_192 ) )
return 0 ;
V_64 = & V_16 -> V_193 [ V_141 ] ;
V_120 = & V_64 -> V_92 . V_194 ;
clock . V_195 = 2 ;
clock . V_196 = ( V_120 -> V_197 & V_198 ) << 22 ;
if ( V_120 -> V_199 & V_200 )
clock . V_196 |= V_120 -> V_201 & V_202 ;
clock . V_128 = ( V_120 -> V_203 & V_204 ) >> V_205 ;
clock . V_147 = ( V_120 -> V_206 & V_207 ) >> V_208 ;
clock . V_148 = ( V_120 -> V_206 & V_209 ) >> V_210 ;
return F_78 ( 100000 , & clock ) ;
}
static void F_79 ( struct V_2 * V_3 ,
struct V_117 * V_163 )
{
struct V_15 * V_16 = F_23 ( V_3 -> V_5 . V_42 ) ;
enum V_1 V_1 = F_1 ( V_3 ) ;
T_3 V_141 = V_1 ;
V_163 -> V_166 = F_77 ( V_16 , V_141 ) ;
F_67 ( V_163 ) ;
}
void F_80 ( struct V_2 * V_3 ,
struct V_117 * V_163 )
{
struct V_15 * V_16 = F_23 ( V_3 -> V_5 . V_42 ) ;
if ( F_81 ( V_16 ) <= 8 )
F_75 ( V_3 , V_163 ) ;
else if ( F_18 ( V_16 ) || F_14 ( V_16 ) )
F_70 ( V_3 , V_163 ) ;
else if ( F_17 ( V_16 ) )
F_79 ( V_3 , V_163 ) ;
}
static bool
F_82 ( struct V_82 * V_82 ,
struct V_117 * V_118 ,
struct V_2 * V_2 )
{
struct V_63 * V_64 ;
V_64 = F_83 ( V_82 , V_118 ,
V_2 ) ;
if ( ! V_64 )
F_84 ( L_10 ,
F_57 ( V_82 -> V_116 ) ) ;
return V_64 ;
}
static bool
F_85 ( struct V_82 * V_82 ,
struct V_117 * V_118 ,
struct V_2 * V_2 )
{
struct V_63 * V_64 ;
V_64 = F_83 ( V_82 , V_118 , V_2 ) ;
if ( V_64 == NULL ) {
F_84 ( L_10 ,
F_57 ( V_82 -> V_116 ) ) ;
return false ;
}
return true ;
}
static bool
F_86 ( struct V_82 * V_82 ,
struct V_117 * V_118 ,
struct V_2 * V_2 )
{
return ! ! F_83 ( V_82 , V_118 , V_2 ) ;
}
bool F_87 ( struct V_82 * V_82 ,
struct V_117 * V_118 )
{
struct V_15 * V_16 = F_23 ( V_82 -> V_5 . V_42 ) ;
struct V_2 * V_2 =
F_59 ( V_118 ) ;
if ( F_18 ( V_16 ) || F_14 ( V_16 ) )
return F_85 ( V_82 , V_118 ,
V_2 ) ;
else if ( F_17 ( V_16 ) )
return F_86 ( V_82 , V_118 ,
V_2 ) ;
else
return F_82 ( V_82 , V_118 ,
V_2 ) ;
}
void F_88 ( struct V_79 * V_80 )
{
struct V_15 * V_16 = F_23 ( V_80 -> V_42 ) ;
struct V_82 * V_82 = F_38 ( V_80 ) ;
struct V_2 * V_2 = F_56 ( V_80 ) ;
enum V_211 V_212 = V_82 -> V_92 -> V_212 ;
int type = V_2 -> type ;
T_3 V_83 ;
if ( type == V_7 || type == V_8 || type == V_4 ) {
F_24 ( F_89 ( V_212 ) ) ;
V_83 = V_213 ;
switch ( V_82 -> V_92 -> V_170 ) {
case 18 :
V_83 |= V_214 ;
break;
case 24 :
V_83 |= V_215 ;
break;
case 30 :
V_83 |= V_216 ;
break;
case 36 :
V_83 |= V_217 ;
break;
default:
F_25 () ;
}
F_26 ( F_90 ( V_212 ) , V_83 ) ;
}
}
void F_91 ( struct V_79 * V_80 , bool V_120 )
{
struct V_82 * V_82 = F_38 ( V_80 ) ;
struct V_81 * V_42 = V_80 -> V_42 ;
struct V_15 * V_16 = F_23 ( V_42 ) ;
enum V_211 V_212 = V_82 -> V_92 -> V_212 ;
T_3 V_83 ;
V_83 = F_33 ( F_92 ( V_212 ) ) ;
if ( V_120 == true )
V_83 |= V_218 ;
else
V_83 &= ~ V_218 ;
F_26 ( F_92 ( V_212 ) , V_83 ) ;
}
void F_93 ( struct V_79 * V_80 )
{
struct V_82 * V_82 = F_38 ( V_80 ) ;
struct V_2 * V_2 = F_56 ( V_80 ) ;
struct V_81 * V_42 = V_80 -> V_42 ;
struct V_15 * V_16 = F_23 ( V_42 ) ;
enum V_116 V_116 = V_82 -> V_116 ;
enum V_211 V_212 = V_82 -> V_92 -> V_212 ;
enum V_1 V_1 = F_1 ( V_2 ) ;
int type = V_2 -> type ;
T_3 V_83 ;
V_83 = V_219 ;
V_83 |= F_94 ( V_1 ) ;
switch ( V_82 -> V_92 -> V_170 ) {
case 18 :
V_83 |= V_220 ;
break;
case 24 :
V_83 |= V_221 ;
break;
case 30 :
V_83 |= V_222 ;
break;
case 36 :
V_83 |= V_223 ;
break;
default:
F_25 () ;
}
if ( V_82 -> V_92 -> V_5 . V_172 . V_224 & V_225 )
V_83 |= V_226 ;
if ( V_82 -> V_92 -> V_5 . V_172 . V_224 & V_227 )
V_83 |= V_228 ;
if ( V_212 == V_229 ) {
switch ( V_116 ) {
case V_86 :
if ( F_20 ( V_16 ) &&
( V_82 -> V_92 -> V_230 . V_231 ||
V_82 -> V_92 -> V_230 . V_232 ) )
V_83 |= V_233 ;
else
V_83 |= V_234 ;
break;
case V_235 :
V_83 |= V_236 ;
break;
case V_237 :
V_83 |= V_238 ;
break;
default:
F_25 () ;
break;
}
}
if ( type == V_9 ) {
if ( V_82 -> V_92 -> V_169 )
V_83 |= V_239 ;
else
V_83 |= V_240 ;
} else if ( type == V_11 ) {
V_83 |= V_241 ;
V_83 |= ( V_82 -> V_92 -> V_93 - 1 ) << 1 ;
} else if ( type == V_7 ||
type == V_8 ) {
V_83 |= V_242 ;
V_83 |= F_55 ( V_82 -> V_92 -> V_113 ) ;
} else if ( type == V_4 ) {
V_83 |= V_243 ;
V_83 |= F_55 ( V_82 -> V_92 -> V_113 ) ;
} else {
F_21 ( 1 , L_11 ,
V_2 -> type , F_57 ( V_116 ) ) ;
}
F_26 ( F_92 ( V_212 ) , V_83 ) ;
}
void F_95 ( struct V_15 * V_16 ,
enum V_211 V_212 )
{
T_2 V_61 = F_92 ( V_212 ) ;
T_3 V_183 = F_33 ( V_61 ) ;
V_183 &= ~ ( V_219 | V_244 | V_218 ) ;
V_183 |= V_245 ;
F_26 ( V_61 , V_183 ) ;
}
bool F_96 ( struct V_246 * V_246 )
{
struct V_81 * V_42 = V_246 -> V_5 . V_42 ;
struct V_15 * V_16 = F_23 ( V_42 ) ;
struct V_2 * V_2 = V_246 -> V_3 ;
int type = V_246 -> V_5 . V_247 ;
enum V_1 V_1 = F_1 ( V_2 ) ;
enum V_116 V_116 = 0 ;
enum V_211 V_212 ;
enum V_248 V_249 ;
T_3 V_250 ;
bool V_114 ;
V_249 = F_97 ( V_2 ) ;
if ( ! F_98 ( V_16 , V_249 ) )
return false ;
if ( ! V_2 -> V_251 ( V_2 , & V_116 ) ) {
V_114 = false ;
goto V_252;
}
if ( V_1 == V_13 )
V_212 = V_229 ;
else
V_212 = (enum V_211 ) V_116 ;
V_250 = F_33 ( F_92 ( V_212 ) ) ;
switch ( V_250 & V_253 ) {
case V_239 :
case V_240 :
V_114 = type == V_254 ;
break;
case V_242 :
V_114 = type == V_255 ||
type == V_256 ;
break;
case V_243 :
V_114 = false ;
break;
case V_241 :
V_114 = type == V_257 ;
break;
default:
V_114 = false ;
break;
}
V_252:
F_99 ( V_16 , V_249 ) ;
return V_114 ;
}
bool F_100 ( struct V_2 * V_3 ,
enum V_116 * V_116 )
{
struct V_81 * V_42 = V_3 -> V_5 . V_42 ;
struct V_15 * V_16 = F_23 ( V_42 ) ;
enum V_1 V_1 = F_1 ( V_3 ) ;
enum V_248 V_249 ;
T_1 V_250 ;
int V_44 ;
bool V_114 ;
V_249 = F_97 ( V_3 ) ;
if ( ! F_98 ( V_16 , V_249 ) )
return false ;
V_114 = false ;
V_250 = F_33 ( F_31 ( V_1 ) ) ;
if ( ! ( V_250 & V_100 ) )
goto V_252;
if ( V_1 == V_13 ) {
V_250 = F_33 ( F_92 ( V_229 ) ) ;
switch ( V_250 & V_258 ) {
case V_234 :
case V_233 :
* V_116 = V_86 ;
break;
case V_236 :
* V_116 = V_235 ;
break;
case V_238 :
* V_116 = V_237 ;
break;
}
V_114 = true ;
goto V_252;
}
for ( V_44 = V_259 ; V_44 <= V_260 ; V_44 ++ ) {
V_250 = F_33 ( F_92 ( V_44 ) ) ;
if ( ( V_250 & V_244 ) == F_94 ( V_1 ) ) {
if ( ( V_250 & V_253 ) ==
V_243 )
goto V_252;
* V_116 = V_44 ;
V_114 = true ;
goto V_252;
}
}
F_52 ( L_12 , F_35 ( V_1 ) ) ;
V_252:
if ( V_114 && F_17 ( V_16 ) ) {
V_250 = F_33 ( F_101 ( V_1 ) ) ;
if ( ( V_250 & ( V_261 |
V_262 ) ) != V_262 )
F_34 ( L_13
L_14 , F_35 ( V_1 ) , V_250 ) ;
}
F_99 ( V_16 , V_249 ) ;
return V_114 ;
}
void F_102 ( struct V_82 * V_82 )
{
struct V_79 * V_80 = & V_82 -> V_5 ;
struct V_81 * V_42 = V_80 -> V_42 ;
struct V_15 * V_16 = F_23 ( V_42 ) ;
struct V_2 * V_2 = F_56 ( V_80 ) ;
enum V_1 V_1 = F_1 ( V_2 ) ;
enum V_211 V_212 = V_82 -> V_92 -> V_212 ;
if ( V_212 != V_229 )
F_26 ( F_103 ( V_212 ) ,
F_104 ( V_1 ) ) ;
}
void F_105 ( struct V_82 * V_82 )
{
struct V_15 * V_16 = F_23 ( V_82 -> V_5 . V_42 ) ;
enum V_211 V_212 = V_82 -> V_92 -> V_212 ;
if ( V_212 != V_229 )
F_26 ( F_103 ( V_212 ) ,
V_263 ) ;
}
static void F_106 ( struct V_15 * V_16 ,
enum V_1 V_1 , T_4 V_264 )
{
T_1 V_250 ;
V_250 = F_33 ( V_265 ) ;
V_250 &= ~ ( F_107 ( V_1 ) | F_108 ( V_1 ) ) ;
if ( V_264 )
V_250 |= V_264 << F_109 ( V_1 ) ;
else
V_250 |= F_108 ( V_1 ) ;
F_26 ( V_265 , V_250 ) ;
}
static void F_110 ( struct V_2 * V_3 , T_1 V_266 )
{
struct V_109 * V_110 = F_3 ( & V_3 -> V_5 ) ;
struct V_15 * V_16 = F_23 ( V_110 -> V_5 . V_5 . V_42 ) ;
enum V_1 V_1 = V_110 -> V_1 ;
int type = V_3 -> type ;
const struct V_14 * V_51 ;
T_4 V_264 ;
T_4 V_267 , V_268 ;
int V_17 ;
V_267 = V_16 -> V_18 . V_37 [ V_1 ] . V_55 ;
V_268 = V_16 -> V_18 . V_37 [ V_1 ] . V_60 ;
if ( type == V_7 ) {
if ( V_267 ) {
V_264 = V_267 ;
} else {
if ( F_14 ( V_16 ) )
V_51 = F_10 ( V_16 ,
& V_17 ) ;
else
V_51 = F_7 ( V_16 ,
& V_17 ) ;
V_264 = V_51 [ V_266 ] . V_269 ;
}
} else if ( type == V_8 ) {
if ( V_267 ) {
V_264 = V_267 ;
} else {
V_51 = F_13 ( V_16 , & V_17 ) ;
if ( F_24 ( V_1 != V_13 &&
V_1 != V_12 && V_17 > 9 ) )
V_17 = 9 ;
V_264 = V_51 [ V_266 ] . V_269 ;
}
} else if ( type == V_9 ) {
if ( V_268 ) {
V_264 = V_268 ;
} else {
V_51 = F_15 ( V_16 , & V_17 ) ;
V_264 = V_51 [ V_266 ] . V_269 ;
}
} else {
return;
}
if ( V_264 && V_264 != 0x1 && V_264 != 0x3 && V_264 != 0x7 ) {
F_34 ( L_15 , V_264 ) ;
return;
}
F_106 ( V_16 , V_1 , V_264 ) ;
if ( V_1 == V_13 && V_110 -> V_270 == 4 )
F_106 ( V_16 , V_12 , V_264 ) ;
}
static void F_111 ( struct V_15 * V_16 ,
T_1 V_266 , enum V_1 V_1 , int type )
{
const struct V_271 * V_51 ;
T_1 V_17 , V_44 ;
if ( type == V_8 && V_16 -> V_18 . V_19 . V_20 ) {
V_17 = F_6 ( V_272 ) ;
V_51 = V_272 ;
} else if ( type == V_7
|| type == V_8 ) {
V_17 = F_6 ( V_273 ) ;
V_51 = V_273 ;
} else if ( type == V_9 ) {
V_17 = F_6 ( V_274 ) ;
V_51 = V_274 ;
} else {
F_52 ( L_16 ,
type ) ;
return;
}
if ( V_266 >= V_17 ||
( type == V_9 && V_266 == V_41 ) ) {
for ( V_44 = 0 ; V_44 < V_17 ; V_44 ++ ) {
if ( V_51 [ V_44 ] . V_275 ) {
V_266 = V_44 ;
break;
}
}
}
F_112 ( V_16 , V_1 ,
V_51 [ V_266 ] . V_276 ,
V_51 [ V_266 ] . V_277 ,
V_51 [ V_266 ] . V_278 ,
V_51 [ V_266 ] . V_279 ) ;
}
static T_3 F_113 ( int V_280 )
{
T_3 V_266 ;
switch ( V_280 ) {
default:
F_52 ( L_17 ,
V_280 ) ;
case V_281 | V_282 :
V_266 = 0 ;
break;
case V_281 | V_283 :
V_266 = 1 ;
break;
case V_281 | V_284 :
V_266 = 2 ;
break;
case V_281 | V_285 :
V_266 = 3 ;
break;
case V_286 | V_282 :
V_266 = 4 ;
break;
case V_286 | V_283 :
V_266 = 5 ;
break;
case V_286 | V_284 :
V_266 = 6 ;
break;
case V_287 | V_282 :
V_266 = 7 ;
break;
case V_287 | V_283 :
V_266 = 8 ;
break;
case V_288 | V_282 :
V_266 = 9 ;
break;
}
return V_266 ;
}
T_3 F_114 ( struct V_108 * V_108 )
{
struct V_109 * V_289 = F_115 ( V_108 ) ;
struct V_15 * V_16 = F_23 ( V_289 -> V_5 . V_5 . V_42 ) ;
struct V_2 * V_3 = & V_289 -> V_5 ;
T_4 V_290 = V_108 -> V_290 [ 0 ] ;
int V_280 = V_290 & ( V_291 |
V_292 ) ;
enum V_1 V_1 = V_289 -> V_1 ;
T_3 V_266 ;
V_266 = F_113 ( V_280 ) ;
if ( F_18 ( V_16 ) || F_14 ( V_16 ) )
F_110 ( V_3 , V_266 ) ;
else if ( F_17 ( V_16 ) )
F_111 ( V_16 , V_266 , V_1 , V_3 -> type ) ;
return F_48 ( V_266 ) ;
}
void F_116 ( struct V_2 * V_3 ,
struct V_63 * V_64 )
{
struct V_15 * V_16 = F_23 ( V_3 -> V_5 . V_42 ) ;
enum V_1 V_1 = F_1 ( V_3 ) ;
if ( F_24 ( ! V_64 ) )
return;
if ( F_18 ( V_16 ) || F_14 ( V_16 ) ) {
T_3 V_183 ;
V_183 = F_33 ( V_293 ) ;
V_183 &= ~ ( F_117 ( V_1 ) |
F_118 ( V_1 ) ) ;
V_183 |= ( F_119 ( V_64 -> V_65 , V_1 ) |
F_120 ( V_1 ) ) ;
F_26 ( V_293 , V_183 ) ;
} else if ( F_121 ( V_16 ) -> V_294 < 9 ) {
F_26 ( F_46 ( V_1 ) , F_36 ( V_64 ) ) ;
}
}
static void F_122 ( struct V_2 * V_3 ,
int V_295 , T_3 V_113 ,
struct V_63 * V_64 ,
bool V_296 )
{
struct V_108 * V_108 = F_54 ( & V_3 -> V_5 ) ;
struct V_15 * V_16 = F_23 ( V_3 -> V_5 . V_42 ) ;
enum V_1 V_1 = F_1 ( V_3 ) ;
F_123 ( V_108 , V_295 , V_113 ,
V_296 ) ;
if ( V_3 -> type == V_8 )
F_124 ( V_108 ) ;
F_116 ( V_3 , V_64 ) ;
F_22 ( V_3 ) ;
F_53 ( V_3 ) ;
F_125 ( V_108 , V_297 ) ;
F_126 ( V_108 ) ;
if ( V_1 != V_13 || F_81 ( V_16 ) >= 9 )
F_127 ( V_108 ) ;
}
static void F_128 ( struct V_2 * V_3 ,
bool V_169 ,
struct V_298 * V_172 ,
struct V_63 * V_64 )
{
struct V_299 * V_299 = F_129 ( & V_3 -> V_5 ) ;
struct V_15 * V_16 = F_23 ( V_3 -> V_5 . V_42 ) ;
struct V_300 * V_300 = & V_3 -> V_5 ;
enum V_1 V_1 = F_1 ( V_3 ) ;
int V_266 = F_16 ( V_16 , V_1 ) ;
F_130 ( V_299 , true ) ;
F_116 ( V_3 , V_64 ) ;
F_29 ( V_3 ) ;
if ( F_18 ( V_16 ) || F_14 ( V_16 ) )
F_110 ( V_3 , V_266 ) ;
else if ( F_17 ( V_16 ) )
F_111 ( V_16 , V_266 , V_1 ,
V_9 ) ;
V_299 -> V_301 ( V_300 ,
V_169 ,
V_172 ) ;
}
static void F_131 ( struct V_2 * V_2 ,
struct V_117 * V_163 ,
struct V_123 * V_302 )
{
struct V_300 * V_3 = & V_2 -> V_5 ;
struct V_82 * V_80 = F_38 ( V_3 -> V_80 ) ;
int type = V_2 -> type ;
if ( type == V_7 || type == V_8 ) {
F_122 ( V_2 ,
V_80 -> V_92 -> V_166 ,
V_80 -> V_92 -> V_113 ,
V_80 -> V_92 -> V_95 ,
F_132 ( V_80 -> V_92 ,
V_4 ) ) ;
}
if ( type == V_9 ) {
F_128 ( V_2 ,
V_80 -> V_92 -> V_169 ,
& V_80 -> V_92 -> V_5 . V_172 ,
V_80 -> V_92 -> V_95 ) ;
}
}
static void F_133 ( struct V_2 * V_2 ,
struct V_117 * V_303 ,
struct V_123 * V_304 )
{
struct V_300 * V_3 = & V_2 -> V_5 ;
struct V_15 * V_16 = F_23 ( V_3 -> V_42 ) ;
enum V_1 V_1 = F_1 ( V_2 ) ;
int type = V_2 -> type ;
T_3 V_183 ;
bool V_305 = false ;
V_183 = F_33 ( F_31 ( V_1 ) ) ;
if ( V_183 & V_100 ) {
V_183 &= ~ V_100 ;
F_26 ( F_31 ( V_1 ) , V_183 ) ;
V_305 = true ;
}
V_183 = F_33 ( F_47 ( V_1 ) ) ;
V_183 &= ~ ( V_99 | V_106 ) ;
V_183 |= V_98 ;
F_26 ( F_47 ( V_1 ) , V_183 ) ;
if ( V_305 )
F_30 ( V_16 , V_1 ) ;
if ( type == V_7 || type == V_8 ) {
struct V_108 * V_108 = F_54 ( V_3 ) ;
F_125 ( V_108 , V_306 ) ;
F_134 ( V_108 ) ;
F_135 ( V_108 ) ;
}
if ( F_18 ( V_16 ) || F_14 ( V_16 ) )
F_26 ( V_293 , ( F_33 ( V_293 ) |
F_117 ( V_1 ) ) ) ;
else if ( F_81 ( V_16 ) < 9 )
F_26 ( F_46 ( V_1 ) , V_78 ) ;
if ( type == V_9 ) {
struct V_299 * V_299 = F_129 ( V_3 ) ;
F_130 ( V_299 , false ) ;
}
}
void F_136 ( struct V_2 * V_2 ,
struct V_117 * V_303 ,
struct V_123 * V_304 )
{
struct V_15 * V_16 = F_23 ( V_2 -> V_5 . V_42 ) ;
T_3 V_183 ;
V_183 = F_33 ( F_44 ( V_86 ) ) ;
V_183 &= ~ V_101 ;
F_26 ( F_44 ( V_86 ) , V_183 ) ;
F_133 ( V_2 , V_303 , V_304 ) ;
V_183 = F_33 ( F_40 ( V_86 ) ) ;
V_183 &= ~ ( V_103 | V_104 ) ;
V_183 |= F_41 ( 2 ) | F_42 ( 2 ) ;
F_26 ( F_40 ( V_86 ) , V_183 ) ;
V_183 = F_33 ( F_44 ( V_86 ) ) ;
V_183 &= ~ V_94 ;
F_26 ( F_44 ( V_86 ) , V_183 ) ;
V_183 = F_33 ( F_44 ( V_86 ) ) ;
V_183 &= ~ V_91 ;
F_26 ( F_44 ( V_86 ) , V_183 ) ;
}
static void F_137 ( struct V_2 * V_2 ,
struct V_117 * V_163 ,
struct V_123 * V_302 )
{
struct V_300 * V_3 = & V_2 -> V_5 ;
struct V_79 * V_80 = V_3 -> V_80 ;
struct V_82 * V_82 = F_38 ( V_80 ) ;
struct V_15 * V_16 = F_23 ( V_3 -> V_42 ) ;
enum V_1 V_1 = F_1 ( V_2 ) ;
int type = V_2 -> type ;
if ( type == V_9 ) {
struct V_109 * V_110 =
F_3 ( V_3 ) ;
F_26 ( F_31 ( V_1 ) ,
V_110 -> V_112 |
V_100 ) ;
} else if ( type == V_8 ) {
struct V_108 * V_108 = F_54 ( V_3 ) ;
if ( V_1 == V_13 && F_81 ( V_16 ) < 9 )
F_127 ( V_108 ) ;
F_138 ( V_108 ) ;
F_139 ( V_108 ) ;
F_140 ( V_108 , V_163 ) ;
}
if ( V_82 -> V_92 -> V_307 ) {
F_141 ( V_16 , V_308 ) ;
F_142 ( V_2 , V_163 , V_302 ) ;
}
}
static void F_143 ( struct V_2 * V_2 ,
struct V_117 * V_303 ,
struct V_123 * V_304 )
{
struct V_300 * V_3 = & V_2 -> V_5 ;
struct V_79 * V_80 = V_3 -> V_80 ;
struct V_82 * V_82 = F_38 ( V_80 ) ;
int type = V_2 -> type ;
struct V_81 * V_42 = V_3 -> V_42 ;
struct V_15 * V_16 = F_23 ( V_42 ) ;
if ( V_82 -> V_92 -> V_307 ) {
F_144 ( V_2 ) ;
F_99 ( V_16 , V_308 ) ;
}
if ( type == V_8 ) {
struct V_108 * V_108 = F_54 ( V_3 ) ;
F_145 ( V_108 , V_303 ) ;
F_146 ( V_108 ) ;
F_147 ( V_108 ) ;
}
}
static void F_148 ( struct V_2 * V_3 ,
struct V_117 * V_163 ,
struct V_123 * V_302 )
{
struct V_82 * V_82 = F_38 ( V_3 -> V_5 . V_80 ) ;
T_4 V_309 = V_82 -> V_92 -> V_310 ;
F_149 ( V_3 , V_309 ) ;
}
void F_150 ( struct V_108 * V_108 )
{
struct V_109 * V_110 = F_115 ( V_108 ) ;
struct V_15 * V_16 =
F_23 ( V_110 -> V_5 . V_5 . V_42 ) ;
enum V_1 V_1 = V_110 -> V_1 ;
T_3 V_183 ;
bool V_305 = false ;
if ( F_33 ( F_47 ( V_1 ) ) & V_99 ) {
V_183 = F_33 ( F_31 ( V_1 ) ) ;
if ( V_183 & V_100 ) {
V_183 &= ~ V_100 ;
F_26 ( F_31 ( V_1 ) , V_183 ) ;
V_305 = true ;
}
V_183 = F_33 ( F_47 ( V_1 ) ) ;
V_183 &= ~ ( V_99 | V_106 ) ;
V_183 |= V_98 ;
F_26 ( F_47 ( V_1 ) , V_183 ) ;
F_45 ( F_47 ( V_1 ) ) ;
if ( V_305 )
F_30 ( V_16 , V_1 ) ;
}
V_183 = V_99 |
V_98 | V_311 ;
if ( V_108 -> V_296 )
V_183 |= V_312 ;
else {
V_183 |= V_313 ;
if ( F_151 ( V_108 -> V_314 ) )
V_183 |= V_97 ;
}
F_26 ( F_47 ( V_1 ) , V_183 ) ;
F_45 ( F_47 ( V_1 ) ) ;
V_108 -> V_111 |= V_100 ;
F_26 ( F_31 ( V_1 ) , V_108 -> V_111 ) ;
F_45 ( F_31 ( V_1 ) ) ;
F_32 ( 600 ) ;
}
void F_152 ( struct V_2 * V_3 ,
struct V_117 * V_163 )
{
struct V_15 * V_16 = F_23 ( V_3 -> V_5 . V_42 ) ;
struct V_82 * V_82 = F_38 ( V_3 -> V_5 . V_80 ) ;
enum V_211 V_212 = V_163 -> V_212 ;
struct V_299 * V_299 ;
T_1 V_83 , V_224 = 0 ;
if ( F_24 ( F_89 ( V_212 ) ) )
return;
V_83 = F_33 ( F_92 ( V_212 ) ) ;
if ( V_83 & V_228 )
V_224 |= V_227 ;
else
V_224 |= V_315 ;
if ( V_83 & V_226 )
V_224 |= V_225 ;
else
V_224 |= V_316 ;
V_163 -> V_5 . V_172 . V_224 |= V_224 ;
switch ( V_83 & V_317 ) {
case V_220 :
V_163 -> V_170 = 18 ;
break;
case V_221 :
V_163 -> V_170 = 24 ;
break;
case V_222 :
V_163 -> V_170 = 30 ;
break;
case V_223 :
V_163 -> V_170 = 36 ;
break;
default:
break;
}
switch ( V_83 & V_253 ) {
case V_239 :
V_163 -> V_169 = true ;
V_299 = F_129 ( & V_3 -> V_5 ) ;
if ( V_299 -> V_318 ( & V_3 -> V_5 , V_163 ) )
V_163 -> V_319 = true ;
case V_240 :
V_163 -> V_113 = 4 ;
break;
case V_241 :
break;
case V_242 :
case V_243 :
V_163 -> V_113 =
( ( V_83 & V_320 ) >> V_321 ) + 1 ;
F_153 ( V_82 , V_163 ) ;
break;
default:
break;
}
if ( F_154 ( V_16 , V_308 ) ) {
V_83 = F_33 ( V_322 ) ;
if ( V_83 & F_155 ( V_82 -> V_116 ) )
V_163 -> V_307 = true ;
}
if ( V_3 -> type == V_8 && V_16 -> V_18 . V_19 . V_323 &&
V_163 -> V_170 > V_16 -> V_18 . V_19 . V_323 ) {
F_52 ( L_18 ,
V_163 -> V_170 , V_16 -> V_18 . V_19 . V_323 ) ;
V_16 -> V_18 . V_19 . V_323 = V_163 -> V_170 ;
}
F_80 ( V_3 , V_163 ) ;
if ( F_17 ( V_16 ) )
V_163 -> V_310 =
F_156 ( V_3 ) ;
}
static bool F_157 ( struct V_2 * V_3 ,
struct V_117 * V_163 ,
struct V_123 * V_302 )
{
struct V_15 * V_16 = F_23 ( V_3 -> V_5 . V_42 ) ;
int type = V_3 -> type ;
int V_1 = F_1 ( V_3 ) ;
int V_114 ;
F_21 ( type == V_10 , L_19 ) ;
if ( V_1 == V_13 )
V_163 -> V_212 = V_229 ;
if ( type == V_9 )
V_114 = F_158 ( V_3 , V_163 , V_302 ) ;
else
V_114 = F_159 ( V_3 , V_163 , V_302 ) ;
if ( F_17 ( V_16 ) && V_114 )
V_163 -> V_310 =
F_160 ( V_3 ,
V_163 -> V_113 ) ;
return V_114 ;
}
static struct V_246 *
F_161 ( struct V_109 * V_110 )
{
struct V_246 * V_122 ;
enum V_1 V_1 = V_110 -> V_1 ;
V_122 = F_162 () ;
if ( ! V_122 )
return NULL ;
V_110 -> V_324 . V_325 = F_31 ( V_1 ) ;
if ( ! F_163 ( V_110 , V_122 ) ) {
F_164 ( V_122 ) ;
return NULL ;
}
return V_122 ;
}
static struct V_246 *
F_165 ( struct V_109 * V_110 )
{
struct V_246 * V_122 ;
enum V_1 V_1 = V_110 -> V_1 ;
V_122 = F_162 () ;
if ( ! V_122 )
return NULL ;
V_110 -> V_326 . V_327 = F_31 ( V_1 ) ;
F_166 ( V_110 , V_122 ) ;
return V_122 ;
}
struct V_63 *
F_167 ( struct V_108 * V_108 , int clock )
{
struct V_246 * V_122 = V_108 -> V_328 ;
struct V_2 * V_3 = V_122 -> V_3 ;
struct V_15 * V_16 = F_23 ( V_3 -> V_5 . V_42 ) ;
struct V_109 * V_329 = F_115 ( V_108 ) ;
struct V_63 * V_64 = NULL ;
struct V_330 V_331 ;
enum V_190 V_332 ;
if ( F_17 ( V_16 ) ) {
V_332 = (enum V_190 ) V_329 -> V_1 ;
V_64 = & V_16 -> V_193 [ V_332 ] ;
if ( F_24 ( V_64 -> V_333 ) ) {
F_34 ( L_20 ,
V_64 -> V_333 ) ;
return NULL ;
}
V_331 = V_64 -> V_92 ;
if ( ! F_168 ( clock ,
& V_64 -> V_92 . V_194 ) ) {
F_34 ( L_21 ) ;
V_64 -> V_92 = V_331 ;
return NULL ;
}
} else if ( F_18 ( V_16 ) || F_14 ( V_16 ) ) {
V_64 = F_169 ( V_16 , clock ) ;
} else if ( F_20 ( V_16 ) || F_19 ( V_16 ) ) {
V_64 = F_170 ( V_3 , clock ) ;
}
return V_64 ;
}
void F_171 ( struct V_81 * V_42 , enum V_1 V_1 )
{
struct V_15 * V_16 = F_23 ( V_42 ) ;
struct V_109 * V_110 ;
struct V_2 * V_2 ;
struct V_300 * V_3 ;
bool V_334 , V_335 , V_336 = false ;
int V_270 ;
if ( F_33 ( F_31 ( V_13 ) ) & V_337 ) {
switch ( V_1 ) {
case V_13 :
V_270 = 4 ;
break;
case V_12 :
V_270 = 0 ;
break;
default:
V_270 = 4 ;
break;
}
} else {
switch ( V_1 ) {
case V_13 :
V_270 = 2 ;
break;
case V_12 :
V_270 = 2 ;
break;
default:
V_270 = 4 ;
break;
}
}
V_334 = ( V_16 -> V_18 . V_37 [ V_1 ] . V_338 ||
V_16 -> V_18 . V_37 [ V_1 ] . V_339 ) ;
V_335 = V_16 -> V_18 . V_37 [ V_1 ] . V_340 ;
if ( F_172 ( V_16 , V_1 ) ) {
V_335 = true ;
V_336 = true ;
V_334 = false ;
F_52 ( L_22 , F_35 ( V_1 ) ) ;
}
if ( ! V_335 && ! V_334 ) {
F_52 ( L_23 ,
F_35 ( V_1 ) ) ;
return;
}
V_110 = F_173 ( sizeof( * V_110 ) , V_341 ) ;
if ( ! V_110 )
return;
V_2 = & V_110 -> V_5 ;
V_3 = & V_2 -> V_5 ;
F_174 ( V_42 , V_3 , & V_342 ,
V_343 , L_24 , F_35 ( V_1 ) ) ;
V_2 -> V_344 = F_157 ;
V_2 -> V_278 = F_137 ;
if ( F_17 ( V_16 ) )
V_2 -> V_345 = F_148 ;
V_2 -> V_346 = F_131 ;
V_2 -> V_347 = F_143 ;
V_2 -> V_348 = F_133 ;
V_2 -> V_251 = F_100 ;
V_2 -> V_349 = F_152 ;
V_2 -> V_350 = V_351 ;
V_110 -> V_1 = V_1 ;
V_110 -> V_112 = F_33 ( F_31 ( V_1 ) ) &
( V_352 |
V_337 ) ;
if ( F_17 ( V_16 ) && V_1 == V_13 ) {
if ( ! ( V_110 -> V_112 & V_337 ) ) {
F_52 ( L_25 ) ;
V_110 -> V_112 |= V_337 ;
V_270 = 4 ;
}
}
V_110 -> V_270 = V_270 ;
V_2 -> type = V_10 ;
V_2 -> V_1 = V_1 ;
V_2 -> V_353 = ( 1 << 0 ) | ( 1 << 1 ) | ( 1 << 2 ) ;
V_2 -> V_354 = 0 ;
if ( V_335 ) {
if ( ! F_161 ( V_110 ) )
goto V_355;
V_110 -> V_356 = V_357 ;
if ( F_175 ( V_16 , 0 , V_358 ) && V_1 == V_359 )
V_16 -> V_360 . V_361 [ V_13 ] = V_110 ;
else
V_16 -> V_360 . V_361 [ V_1 ] = V_110 ;
}
if ( V_2 -> type != V_8 && V_334 ) {
if ( ! F_165 ( V_110 ) )
goto V_355;
}
if ( V_336 ) {
if ( F_176 ( V_110 ) )
F_52 ( L_26 ,
F_35 ( V_1 ) ) ;
else
F_34 ( L_27 ,
F_35 ( V_1 ) ) ;
}
return;
V_355:
F_177 ( V_3 ) ;
F_164 ( V_110 ) ;
}
