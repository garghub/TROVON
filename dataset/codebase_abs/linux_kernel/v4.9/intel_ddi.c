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
if ( F_8 ( V_16 ) || F_9 ( V_16 ) ) {
* V_17 = F_6 ( V_23 ) ;
return V_23 ;
} else if ( F_10 ( V_16 ) || F_11 ( V_16 ) ) {
* V_17 = F_6 ( V_24 ) ;
return V_24 ;
} else {
* V_17 = F_6 ( V_25 ) ;
return V_25 ;
}
}
static const struct V_14 *
F_12 ( struct V_15 * V_16 , int * V_17 )
{
if ( V_16 -> V_18 . V_19 . V_20 ) {
if ( F_8 ( V_16 ) || F_9 ( V_16 ) ) {
* V_17 = F_6 ( V_26 ) ;
return V_26 ;
} else if ( F_10 ( V_16 ) || F_11 ( V_16 ) ) {
* V_17 = F_6 ( V_27 ) ;
return V_27 ;
} else {
* V_17 = F_6 ( V_28 ) ;
return V_28 ;
}
}
return F_7 ( V_16 , V_17 ) ;
}
static const struct V_14 *
F_13 ( struct V_15 * V_16 , int * V_17 )
{
if ( F_8 ( V_16 ) || F_9 ( V_16 ) ) {
* V_17 = F_6 ( V_29 ) ;
return V_29 ;
} else {
* V_17 = F_6 ( V_30 ) ;
return V_30 ;
}
}
static int F_14 ( struct V_15 * V_16 , enum V_1 V_1 )
{
int V_31 ;
int V_32 ;
int V_33 ;
V_32 = V_16 -> V_18 . V_34 [ V_1 ] . V_35 ;
if ( F_15 ( V_16 ) )
return V_32 ;
if ( F_16 ( V_16 ) || F_17 ( V_16 ) ) {
F_13 ( V_16 , & V_31 ) ;
V_33 = 8 ;
} else if ( F_18 ( V_16 ) ) {
V_31 = F_6 ( V_36 ) ;
V_33 = 7 ;
} else if ( F_19 ( V_16 ) ) {
V_31 = F_6 ( V_37 ) ;
V_33 = 6 ;
} else {
F_20 ( 1 , L_1 ) ;
V_31 = F_6 ( V_36 ) ;
V_33 = 7 ;
}
if ( V_32 == V_38 ||
V_32 >= V_31 )
V_32 = V_33 ;
return V_32 ;
}
void F_21 ( struct V_2 * V_3 )
{
struct V_15 * V_16 = F_22 ( V_3 -> V_5 . V_39 ) ;
T_1 V_40 = 0 ;
int V_41 , V_42 , V_43 , V_44 ;
enum V_1 V_1 = F_1 ( V_3 ) ;
const struct V_14 * V_45 ;
const struct V_14 * V_46 ;
const struct V_14 * V_47 ;
const struct V_14 * V_48 ;
if ( F_15 ( V_16 ) )
return;
if ( F_16 ( V_16 ) || F_17 ( V_16 ) ) {
V_45 = NULL ;
V_46 =
F_7 ( V_16 , & V_42 ) ;
V_47 =
F_12 ( V_16 , & V_43 ) ;
if ( V_16 -> V_18 . V_34 [ V_1 ] . V_49 )
V_40 = V_50 ;
if ( F_23 ( V_3 -> type == V_8 &&
V_1 != V_13 && V_1 != V_12 &&
V_43 > 9 ) )
V_43 = 9 ;
} else if ( F_18 ( V_16 ) ) {
V_45 = V_51 ;
V_46 = V_22 ;
V_47 = F_5 ( V_16 , & V_43 ) ;
V_42 = F_6 ( V_22 ) ;
} else if ( F_19 ( V_16 ) ) {
V_45 = V_52 ;
V_46 = V_53 ;
V_47 = V_53 ;
V_42 = V_43 = F_6 ( V_53 ) ;
} else {
F_20 ( 1 , L_1 ) ;
V_47 = V_22 ;
V_45 = V_51 ;
V_46 = V_22 ;
V_43 = F_6 ( V_21 ) ;
V_42 = F_6 ( V_22 ) ;
}
switch ( V_3 -> type ) {
case V_8 :
V_48 = V_47 ;
V_44 = V_43 ;
break;
case V_7 :
V_48 = V_46 ;
V_44 = V_42 ;
break;
case V_11 :
V_48 = V_45 ;
V_44 = V_42 ;
break;
default:
F_24 () ;
}
for ( V_41 = 0 ; V_41 < V_44 ; V_41 ++ ) {
F_25 ( F_26 ( V_1 , V_41 ) ,
V_48 [ V_41 ] . V_54 | V_40 ) ;
F_25 ( F_27 ( V_1 , V_41 ) ,
V_48 [ V_41 ] . V_55 ) ;
}
}
static void F_28 ( struct V_2 * V_3 )
{
struct V_15 * V_16 = F_22 ( V_3 -> V_5 . V_39 ) ;
T_1 V_40 = 0 ;
int V_31 , V_32 ;
enum V_1 V_1 = F_1 ( V_3 ) ;
const struct V_14 * V_56 ;
if ( F_15 ( V_16 ) )
return;
V_32 = F_14 ( V_16 , V_1 ) ;
if ( F_16 ( V_16 ) || F_17 ( V_16 ) ) {
V_56 = F_13 ( V_16 , & V_31 ) ;
if ( V_16 -> V_18 . V_34 [ V_1 ] . V_57 )
V_40 = V_50 ;
} else if ( F_18 ( V_16 ) ) {
V_56 = V_36 ;
V_31 = F_6 ( V_36 ) ;
} else if ( F_19 ( V_16 ) ) {
V_56 = V_37 ;
V_31 = F_6 ( V_37 ) ;
} else {
F_20 ( 1 , L_1 ) ;
V_56 = V_36 ;
V_31 = F_6 ( V_36 ) ;
}
F_25 ( F_26 ( V_1 , 9 ) ,
V_56 [ V_32 ] . V_54 | V_40 ) ;
F_25 ( F_27 ( V_1 , 9 ) ,
V_56 [ V_32 ] . V_55 ) ;
}
static void F_29 ( struct V_15 * V_16 ,
enum V_1 V_1 )
{
T_2 V_58 = F_30 ( V_1 ) ;
int V_41 ;
for ( V_41 = 0 ; V_41 < 16 ; V_41 ++ ) {
F_31 ( 1 ) ;
if ( F_32 ( V_58 ) & V_59 )
return;
}
F_33 ( L_2 , F_34 ( V_1 ) ) ;
}
static T_3 F_35 ( struct V_60 * V_61 )
{
switch ( V_61 -> V_62 ) {
case V_63 :
return V_64 ;
case V_65 :
return V_66 ;
case V_67 :
return V_68 ;
case V_69 :
return V_70 ;
case V_71 :
return V_72 ;
case V_73 :
return V_74 ;
default:
F_4 ( V_61 -> V_62 ) ;
return V_75 ;
}
}
void F_36 ( struct V_76 * V_77 )
{
struct V_78 * V_39 = V_77 -> V_39 ;
struct V_15 * V_16 = F_22 ( V_39 ) ;
struct V_79 * V_79 = F_37 ( V_77 ) ;
struct V_2 * V_3 ;
T_1 V_80 , V_41 , V_81 , V_82 ;
F_38 (dev, crtc, encoder) {
F_23 ( V_3 -> type != V_11 ) ;
F_21 ( V_3 ) ;
}
F_25 ( F_39 ( V_83 ) , F_40 ( 2 ) |
F_41 ( 2 ) |
V_84 | V_85 ) ;
V_81 = V_16 -> V_86 | V_87 |
V_88 |
F_42 ( V_79 -> V_89 -> V_90 ) ;
F_25 ( F_43 ( V_83 ) , V_81 ) ;
F_44 ( F_43 ( V_83 ) ) ;
F_31 ( 220 ) ;
V_81 |= V_91 ;
F_25 ( F_43 ( V_83 ) , V_81 ) ;
V_82 = F_35 ( V_79 -> V_89 -> V_92 ) ;
F_25 ( F_45 ( V_12 ) , V_82 ) ;
F_23 ( V_82 != V_68 ) ;
for ( V_41 = 0 ; V_41 < F_6 ( V_52 ) * 2 ; V_41 ++ ) {
F_25 ( F_46 ( V_12 ) ,
V_93 |
V_94 |
V_95 |
V_96 ) ;
F_25 ( F_30 ( V_12 ) ,
V_97 |
( ( V_79 -> V_89 -> V_90 - 1 ) << 1 ) |
F_47 ( V_41 / 2 ) ) ;
F_44 ( F_30 ( V_12 ) ) ;
F_31 ( 600 ) ;
F_25 ( F_48 ( V_83 ) , F_49 ( 64 ) ) ;
V_81 |= V_98 | V_99 ;
F_25 ( F_43 ( V_83 ) , V_81 ) ;
F_44 ( F_43 ( V_83 ) ) ;
F_31 ( 30 ) ;
V_80 = F_32 ( F_39 ( V_83 ) ) ;
V_80 &= ~ ( V_100 | V_101 ) ;
F_25 ( F_39 ( V_83 ) , V_80 ) ;
F_44 ( F_39 ( V_83 ) ) ;
F_31 ( 5 ) ;
V_80 = F_32 ( F_50 ( V_12 ) ) ;
if ( V_80 & V_102 ) {
F_51 ( L_3 , V_41 ) ;
break;
}
if ( V_41 == F_6 ( V_52 ) * 2 - 1 ) {
F_33 ( L_4 ) ;
break;
}
V_81 &= ~ V_98 ;
F_25 ( F_43 ( V_83 ) , V_81 ) ;
F_44 ( F_43 ( V_83 ) ) ;
V_80 = F_32 ( F_30 ( V_12 ) ) ;
V_80 &= ~ V_97 ;
F_25 ( F_30 ( V_12 ) , V_80 ) ;
F_44 ( F_30 ( V_12 ) ) ;
V_80 = F_32 ( F_46 ( V_12 ) ) ;
V_80 &= ~ ( V_96 | V_103 ) ;
V_80 |= V_95 ;
F_25 ( F_46 ( V_12 ) , V_80 ) ;
F_44 ( F_46 ( V_12 ) ) ;
F_29 ( V_16 , V_12 ) ;
V_80 = F_32 ( F_39 ( V_83 ) ) ;
V_80 &= ~ ( V_100 | V_101 ) ;
V_80 |= F_40 ( 2 ) | F_41 ( 2 ) ;
F_25 ( F_39 ( V_83 ) , V_80 ) ;
F_44 ( F_39 ( V_83 ) ) ;
}
F_25 ( F_46 ( V_12 ) ,
V_93 |
V_104 |
V_94 |
V_96 ) ;
}
void F_52 ( struct V_2 * V_3 )
{
struct V_105 * V_105 = F_53 ( & V_3 -> V_5 ) ;
struct V_106 * V_107 =
F_3 ( & V_3 -> V_5 ) ;
V_105 -> V_108 = V_107 -> V_109 |
V_97 | F_47 ( 0 ) ;
V_105 -> V_108 |= F_54 ( V_105 -> V_110 ) ;
}
static struct V_2 *
F_55 ( struct V_76 * V_77 )
{
struct V_78 * V_39 = V_77 -> V_39 ;
struct V_79 * V_79 = F_37 ( V_77 ) ;
struct V_2 * V_2 , * V_111 = NULL ;
int V_112 = 0 ;
F_38 (dev, crtc, intel_encoder) {
V_111 = V_2 ;
V_112 ++ ;
}
if ( V_112 != 1 )
F_20 ( 1 , L_5 , V_112 ,
F_56 ( V_79 -> V_113 ) ) ;
F_57 ( V_111 == NULL ) ;
return V_111 ;
}
struct V_2 *
F_58 ( struct V_114 * V_115 )
{
struct V_79 * V_77 = F_37 ( V_115 -> V_5 . V_77 ) ;
struct V_2 * V_111 = NULL ;
struct V_116 * V_117 ;
struct V_118 * V_119 ;
struct V_120 * V_121 ;
int V_112 = 0 ;
int V_41 ;
V_117 = V_115 -> V_5 . V_117 ;
F_59 (state, connector, connector_state, i) {
if ( V_121 -> V_77 != V_115 -> V_5 . V_77 )
continue;
V_111 = F_60 ( V_121 -> V_122 ) ;
V_112 ++ ;
}
F_20 ( V_112 != 1 , L_5 , V_112 ,
F_56 ( V_77 -> V_113 ) ) ;
F_57 ( V_111 == NULL ) ;
return V_111 ;
}
static int F_61 ( struct V_15 * V_16 ,
T_2 V_58 )
{
int V_123 = V_124 ;
int V_125 , V_126 , V_127 ;
T_1 V_128 ;
V_128 = F_32 ( V_58 ) ;
switch ( V_128 & V_129 ) {
case V_130 :
case V_131 :
V_123 = 135 ;
break;
case V_132 :
V_123 = V_124 ;
break;
default:
F_20 ( 1 , L_6 ) ;
return 0 ;
}
V_127 = V_128 & V_133 ;
V_126 = ( V_128 & V_134 ) >> V_135 ;
V_125 = ( V_128 & V_136 ) >> V_137 ;
return ( V_123 * V_125 * 100 ) / ( V_126 * V_127 ) ;
}
static int F_62 ( struct V_15 * V_16 ,
T_3 V_138 )
{
T_2 V_139 , V_140 ;
T_3 V_141 , V_142 ;
T_3 V_143 , V_144 , V_145 , V_146 ;
V_139 = F_63 ( V_138 ) ;
V_140 = F_64 ( V_138 ) ;
V_141 = F_32 ( V_139 ) ;
V_142 = F_32 ( V_140 ) ;
V_143 = V_142 & V_147 ;
V_145 = V_142 & V_148 ;
if ( V_142 & F_65 ( 1 ) )
V_144 = ( V_142 & V_149 ) >> 8 ;
else
V_144 = 1 ;
switch ( V_143 ) {
case V_150 :
V_143 = 1 ;
break;
case V_151 :
V_143 = 2 ;
break;
case V_152 :
V_143 = 3 ;
break;
case V_153 :
V_143 = 7 ;
break;
}
switch ( V_145 ) {
case V_154 :
V_145 = 5 ;
break;
case V_155 :
V_145 = 2 ;
break;
case V_156 :
V_145 = 3 ;
break;
case V_157 :
V_145 = 1 ;
break;
}
V_146 = ( V_141 & V_158 ) * 24 * 1000 ;
V_146 += ( ( ( V_141 & V_159 ) >> 9 ) * 24 *
1000 ) / 0x8000 ;
return V_146 / ( V_143 * V_144 * V_145 * 5 ) ;
}
static void F_66 ( struct V_114 * V_160 )
{
int V_161 ;
if ( V_160 -> V_162 )
V_161 = F_67 ( V_160 -> V_163 ,
& V_160 -> V_164 ) ;
else if ( F_68 ( V_160 ) )
V_161 = F_67 ( V_160 -> V_163 ,
& V_160 -> V_165 ) ;
else if ( V_160 -> V_166 && V_160 -> V_167 == 36 )
V_161 = V_160 -> V_163 * 2 / 3 ;
else
V_161 = V_160 -> V_163 ;
if ( V_160 -> V_168 )
V_161 /= V_160 -> V_168 ;
V_160 -> V_5 . V_169 . V_170 = V_161 ;
}
static void F_69 ( struct V_2 * V_3 ,
struct V_114 * V_160 )
{
struct V_15 * V_16 = F_22 ( V_3 -> V_5 . V_39 ) ;
int V_171 = 0 ;
T_3 V_172 , V_138 ;
V_138 = F_70 ( V_16 , V_160 -> V_92 ) ;
V_172 = F_32 ( V_173 ) ;
if ( V_172 & F_71 ( V_138 ) ) {
V_171 = F_62 ( V_16 , V_138 ) ;
} else {
V_171 = V_172 & F_72 ( V_138 ) ;
V_171 >>= F_73 ( V_138 ) ;
switch ( V_171 ) {
case V_174 :
V_171 = 81000 ;
break;
case V_175 :
V_171 = 108000 ;
break;
case V_176 :
V_171 = 135000 ;
break;
case V_177 :
V_171 = 162000 ;
break;
case V_178 :
V_171 = 216000 ;
break;
case V_179 :
V_171 = 270000 ;
break;
default:
F_20 ( 1 , L_7 ) ;
break;
}
V_171 *= 2 ;
}
V_160 -> V_163 = V_171 ;
F_66 ( V_160 ) ;
}
static void F_74 ( struct V_2 * V_3 ,
struct V_114 * V_160 )
{
struct V_15 * V_16 = F_22 ( V_3 -> V_5 . V_39 ) ;
int V_171 = 0 ;
T_1 V_180 , V_61 ;
V_180 = F_35 ( V_160 -> V_92 ) ;
switch ( V_180 & V_181 ) {
case V_70 :
V_171 = 81000 ;
break;
case V_72 :
V_171 = 135000 ;
break;
case V_74 :
V_171 = 270000 ;
break;
case V_64 :
V_171 = F_61 ( V_16 , F_75 ( 0 ) ) ;
break;
case V_66 :
V_171 = F_61 ( V_16 , F_75 ( 1 ) ) ;
break;
case V_68 :
V_61 = F_32 ( V_182 ) & V_183 ;
if ( V_61 == V_184 )
V_171 = 81000 ;
else if ( V_61 == V_185 )
V_171 = 135000 ;
else if ( V_61 == V_186 )
V_171 = 270000 ;
else {
F_20 ( 1 , L_8 ) ;
return;
}
break;
default:
F_20 ( 1 , L_9 ) ;
return;
}
V_160 -> V_163 = V_171 * 2 ;
F_66 ( V_160 ) ;
}
static int F_76 ( struct V_15 * V_16 ,
enum V_187 V_138 )
{
struct V_60 * V_61 ;
struct V_188 * V_117 ;
struct V_138 clock ;
if ( F_23 ( V_138 == V_189 ) )
return 0 ;
V_61 = & V_16 -> V_190 [ V_138 ] ;
V_117 = & V_61 -> V_89 . V_191 ;
clock . V_192 = 2 ;
clock . V_193 = ( V_117 -> V_194 & V_195 ) << 22 ;
if ( V_117 -> V_196 & V_197 )
clock . V_193 |= V_117 -> V_198 & V_199 ;
clock . V_125 = ( V_117 -> V_200 & V_201 ) >> V_202 ;
clock . V_144 = ( V_117 -> V_203 & V_204 ) >> V_205 ;
clock . V_145 = ( V_117 -> V_203 & V_206 ) >> V_207 ;
return F_77 ( 100000 , & clock ) ;
}
static void F_78 ( struct V_2 * V_3 ,
struct V_114 * V_160 )
{
struct V_15 * V_16 = F_22 ( V_3 -> V_5 . V_39 ) ;
enum V_1 V_1 = F_1 ( V_3 ) ;
T_3 V_138 = V_1 ;
V_160 -> V_163 = F_76 ( V_16 , V_138 ) ;
F_66 ( V_160 ) ;
}
void F_79 ( struct V_2 * V_3 ,
struct V_114 * V_160 )
{
struct V_78 * V_39 = V_3 -> V_5 . V_39 ;
if ( F_80 ( V_39 ) -> V_208 <= 8 )
F_74 ( V_3 , V_160 ) ;
else if ( F_16 ( V_39 ) || F_17 ( V_39 ) )
F_69 ( V_3 , V_160 ) ;
else if ( F_15 ( V_39 ) )
F_78 ( V_3 , V_160 ) ;
}
static bool
F_81 ( struct V_79 * V_79 ,
struct V_114 * V_115 ,
struct V_2 * V_2 )
{
struct V_60 * V_61 ;
V_61 = F_82 ( V_79 , V_115 ,
V_2 ) ;
if ( ! V_61 )
F_83 ( L_10 ,
F_56 ( V_79 -> V_113 ) ) ;
return V_61 ;
}
static bool
F_84 ( struct V_79 * V_79 ,
struct V_114 * V_115 ,
struct V_2 * V_2 )
{
struct V_60 * V_61 ;
V_61 = F_82 ( V_79 , V_115 , V_2 ) ;
if ( V_61 == NULL ) {
F_83 ( L_10 ,
F_56 ( V_79 -> V_113 ) ) ;
return false ;
}
return true ;
}
static bool
F_85 ( struct V_79 * V_79 ,
struct V_114 * V_115 ,
struct V_2 * V_2 )
{
return ! ! F_82 ( V_79 , V_115 , V_2 ) ;
}
bool F_86 ( struct V_79 * V_79 ,
struct V_114 * V_115 )
{
struct V_78 * V_39 = V_79 -> V_5 . V_39 ;
struct V_2 * V_2 =
F_58 ( V_115 ) ;
if ( F_16 ( V_39 ) || F_17 ( V_39 ) )
return F_84 ( V_79 , V_115 ,
V_2 ) ;
else if ( F_15 ( V_39 ) )
return F_85 ( V_79 , V_115 ,
V_2 ) ;
else
return F_81 ( V_79 , V_115 ,
V_2 ) ;
}
void F_87 ( struct V_76 * V_77 )
{
struct V_15 * V_16 = F_22 ( V_77 -> V_39 ) ;
struct V_79 * V_79 = F_37 ( V_77 ) ;
struct V_2 * V_2 = F_55 ( V_77 ) ;
enum V_209 V_210 = V_79 -> V_89 -> V_210 ;
int type = V_2 -> type ;
T_3 V_80 ;
if ( type == V_7 || type == V_8 || type == V_4 ) {
F_23 ( F_88 ( V_210 ) ) ;
V_80 = V_211 ;
switch ( V_79 -> V_89 -> V_167 ) {
case 18 :
V_80 |= V_212 ;
break;
case 24 :
V_80 |= V_213 ;
break;
case 30 :
V_80 |= V_214 ;
break;
case 36 :
V_80 |= V_215 ;
break;
default:
F_24 () ;
}
F_25 ( F_89 ( V_210 ) , V_80 ) ;
}
}
void F_90 ( struct V_76 * V_77 , bool V_117 )
{
struct V_79 * V_79 = F_37 ( V_77 ) ;
struct V_78 * V_39 = V_77 -> V_39 ;
struct V_15 * V_16 = F_22 ( V_39 ) ;
enum V_209 V_210 = V_79 -> V_89 -> V_210 ;
T_3 V_80 ;
V_80 = F_32 ( F_91 ( V_210 ) ) ;
if ( V_117 == true )
V_80 |= V_216 ;
else
V_80 &= ~ V_216 ;
F_25 ( F_91 ( V_210 ) , V_80 ) ;
}
void F_92 ( struct V_76 * V_77 )
{
struct V_79 * V_79 = F_37 ( V_77 ) ;
struct V_2 * V_2 = F_55 ( V_77 ) ;
struct V_78 * V_39 = V_77 -> V_39 ;
struct V_15 * V_16 = F_22 ( V_39 ) ;
enum V_113 V_113 = V_79 -> V_113 ;
enum V_209 V_210 = V_79 -> V_89 -> V_210 ;
enum V_1 V_1 = F_1 ( V_2 ) ;
int type = V_2 -> type ;
T_3 V_80 ;
V_80 = V_217 ;
V_80 |= F_93 ( V_1 ) ;
switch ( V_79 -> V_89 -> V_167 ) {
case 18 :
V_80 |= V_218 ;
break;
case 24 :
V_80 |= V_219 ;
break;
case 30 :
V_80 |= V_220 ;
break;
case 36 :
V_80 |= V_221 ;
break;
default:
F_24 () ;
}
if ( V_79 -> V_89 -> V_5 . V_169 . V_222 & V_223 )
V_80 |= V_224 ;
if ( V_79 -> V_89 -> V_5 . V_169 . V_222 & V_225 )
V_80 |= V_226 ;
if ( V_210 == V_227 ) {
switch ( V_113 ) {
case V_83 :
if ( F_19 ( V_39 ) &&
( V_79 -> V_89 -> V_228 . V_229 ||
V_79 -> V_89 -> V_228 . V_230 ) )
V_80 |= V_231 ;
else
V_80 |= V_232 ;
break;
case V_233 :
V_80 |= V_234 ;
break;
case V_235 :
V_80 |= V_236 ;
break;
default:
F_24 () ;
break;
}
}
if ( type == V_9 ) {
if ( V_79 -> V_89 -> V_166 )
V_80 |= V_237 ;
else
V_80 |= V_238 ;
} else if ( type == V_11 ) {
V_80 |= V_239 ;
V_80 |= ( V_79 -> V_89 -> V_90 - 1 ) << 1 ;
} else if ( type == V_7 ||
type == V_8 ) {
V_80 |= V_240 ;
V_80 |= F_54 ( V_79 -> V_89 -> V_110 ) ;
} else if ( type == V_4 ) {
V_80 |= V_241 ;
V_80 |= F_54 ( V_79 -> V_89 -> V_110 ) ;
} else {
F_20 ( 1 , L_11 ,
V_2 -> type , F_56 ( V_113 ) ) ;
}
F_25 ( F_91 ( V_210 ) , V_80 ) ;
}
void F_94 ( struct V_15 * V_16 ,
enum V_209 V_210 )
{
T_2 V_58 = F_91 ( V_210 ) ;
T_3 V_180 = F_32 ( V_58 ) ;
V_180 &= ~ ( V_217 | V_242 | V_216 ) ;
V_180 |= V_243 ;
F_25 ( V_58 , V_180 ) ;
}
bool F_95 ( struct V_244 * V_244 )
{
struct V_78 * V_39 = V_244 -> V_5 . V_39 ;
struct V_15 * V_16 = F_22 ( V_39 ) ;
struct V_2 * V_2 = V_244 -> V_3 ;
int type = V_244 -> V_5 . V_245 ;
enum V_1 V_1 = F_1 ( V_2 ) ;
enum V_113 V_113 = 0 ;
enum V_209 V_210 ;
enum V_246 V_247 ;
T_3 V_248 ;
bool V_111 ;
V_247 = F_96 ( V_2 ) ;
if ( ! F_97 ( V_16 , V_247 ) )
return false ;
if ( ! V_2 -> V_249 ( V_2 , & V_113 ) ) {
V_111 = false ;
goto V_250;
}
if ( V_1 == V_13 )
V_210 = V_227 ;
else
V_210 = (enum V_209 ) V_113 ;
V_248 = F_32 ( F_91 ( V_210 ) ) ;
switch ( V_248 & V_251 ) {
case V_237 :
case V_238 :
V_111 = type == V_252 ;
break;
case V_240 :
V_111 = type == V_253 ||
type == V_254 ;
break;
case V_241 :
V_111 = false ;
break;
case V_239 :
V_111 = type == V_255 ;
break;
default:
V_111 = false ;
break;
}
V_250:
F_98 ( V_16 , V_247 ) ;
return V_111 ;
}
bool F_99 ( struct V_2 * V_3 ,
enum V_113 * V_113 )
{
struct V_78 * V_39 = V_3 -> V_5 . V_39 ;
struct V_15 * V_16 = F_22 ( V_39 ) ;
enum V_1 V_1 = F_1 ( V_3 ) ;
enum V_246 V_247 ;
T_1 V_248 ;
int V_41 ;
bool V_111 ;
V_247 = F_96 ( V_3 ) ;
if ( ! F_97 ( V_16 , V_247 ) )
return false ;
V_111 = false ;
V_248 = F_32 ( F_30 ( V_1 ) ) ;
if ( ! ( V_248 & V_97 ) )
goto V_250;
if ( V_1 == V_13 ) {
V_248 = F_32 ( F_91 ( V_227 ) ) ;
switch ( V_248 & V_256 ) {
case V_232 :
case V_231 :
* V_113 = V_83 ;
break;
case V_234 :
* V_113 = V_233 ;
break;
case V_236 :
* V_113 = V_235 ;
break;
}
V_111 = true ;
goto V_250;
}
for ( V_41 = V_257 ; V_41 <= V_258 ; V_41 ++ ) {
V_248 = F_32 ( F_91 ( V_41 ) ) ;
if ( ( V_248 & V_242 ) == F_93 ( V_1 ) ) {
if ( ( V_248 & V_251 ) ==
V_241 )
goto V_250;
* V_113 = V_41 ;
V_111 = true ;
goto V_250;
}
}
F_51 ( L_12 , F_34 ( V_1 ) ) ;
V_250:
if ( V_111 && F_15 ( V_16 ) ) {
V_248 = F_32 ( F_100 ( V_1 ) ) ;
if ( ( V_248 & ( V_259 |
V_260 ) ) != V_260 )
F_33 ( L_13
L_14 , F_34 ( V_1 ) , V_248 ) ;
}
F_98 ( V_16 , V_247 ) ;
return V_111 ;
}
void F_101 ( struct V_79 * V_79 )
{
struct V_76 * V_77 = & V_79 -> V_5 ;
struct V_78 * V_39 = V_77 -> V_39 ;
struct V_15 * V_16 = F_22 ( V_39 ) ;
struct V_2 * V_2 = F_55 ( V_77 ) ;
enum V_1 V_1 = F_1 ( V_2 ) ;
enum V_209 V_210 = V_79 -> V_89 -> V_210 ;
if ( V_210 != V_227 )
F_25 ( F_102 ( V_210 ) ,
F_103 ( V_1 ) ) ;
}
void F_104 ( struct V_79 * V_79 )
{
struct V_15 * V_16 = F_22 ( V_79 -> V_5 . V_39 ) ;
enum V_209 V_210 = V_79 -> V_89 -> V_210 ;
if ( V_210 != V_227 )
F_25 ( F_102 ( V_210 ) ,
V_261 ) ;
}
static void F_105 ( struct V_15 * V_16 ,
enum V_1 V_1 , T_4 V_262 )
{
T_1 V_248 ;
V_248 = F_32 ( V_263 ) ;
V_248 &= ~ ( F_106 ( V_1 ) | F_107 ( V_1 ) ) ;
if ( V_262 )
V_248 |= V_262 << F_108 ( V_1 ) ;
else
V_248 |= F_107 ( V_1 ) ;
F_25 ( V_263 , V_248 ) ;
}
static void F_109 ( struct V_2 * V_3 , T_1 V_264 )
{
struct V_106 * V_107 = F_3 ( & V_3 -> V_5 ) ;
struct V_15 * V_16 = F_22 ( V_107 -> V_5 . V_5 . V_39 ) ;
enum V_1 V_1 = V_107 -> V_1 ;
int type = V_3 -> type ;
const struct V_14 * V_48 ;
T_4 V_262 ;
T_4 V_265 , V_266 ;
int V_17 ;
V_265 = V_16 -> V_18 . V_34 [ V_1 ] . V_49 ;
V_266 = V_16 -> V_18 . V_34 [ V_1 ] . V_57 ;
if ( type == V_7 ) {
if ( V_265 ) {
V_262 = V_265 ;
} else {
V_48 = F_7 ( V_16 , & V_17 ) ;
V_262 = V_48 [ V_264 ] . V_267 ;
}
} else if ( type == V_8 ) {
if ( V_265 ) {
V_262 = V_265 ;
} else {
V_48 = F_12 ( V_16 , & V_17 ) ;
if ( F_23 ( V_1 != V_13 &&
V_1 != V_12 && V_17 > 9 ) )
V_17 = 9 ;
V_262 = V_48 [ V_264 ] . V_267 ;
}
} else if ( type == V_9 ) {
if ( V_266 ) {
V_262 = V_266 ;
} else {
V_48 = F_13 ( V_16 , & V_17 ) ;
V_262 = V_48 [ V_264 ] . V_267 ;
}
} else {
return;
}
if ( V_262 && V_262 != 0x1 && V_262 != 0x3 && V_262 != 0x7 ) {
F_33 ( L_15 , V_262 ) ;
return;
}
F_105 ( V_16 , V_1 , V_262 ) ;
if ( V_1 == V_13 && V_107 -> V_268 == 4 )
F_105 ( V_16 , V_12 , V_262 ) ;
}
static void F_110 ( struct V_15 * V_16 ,
T_1 V_264 , enum V_1 V_1 , int type )
{
const struct V_269 * V_48 ;
T_1 V_17 , V_41 ;
T_3 V_180 ;
if ( type == V_8 && V_16 -> V_18 . V_19 . V_20 ) {
V_17 = F_6 ( V_270 ) ;
V_48 = V_270 ;
} else if ( type == V_7
|| type == V_8 ) {
V_17 = F_6 ( V_271 ) ;
V_48 = V_271 ;
} else if ( type == V_9 ) {
V_17 = F_6 ( V_272 ) ;
V_48 = V_272 ;
} else {
F_51 ( L_16 ,
type ) ;
return;
}
if ( V_264 >= V_17 ||
( type == V_9 && V_264 == V_38 ) ) {
for ( V_41 = 0 ; V_41 < V_17 ; V_41 ++ ) {
if ( V_48 [ V_41 ] . V_273 ) {
V_264 = V_41 ;
break;
}
}
}
V_180 = F_32 ( F_111 ( V_1 ) ) ;
V_180 &= ~ ( V_274 | V_275 ) ;
F_25 ( F_112 ( V_1 ) , V_180 ) ;
V_180 = F_32 ( F_113 ( V_1 ) ) ;
V_180 &= ~ ( V_276 | V_277 ) ;
V_180 |= V_48 [ V_264 ] . V_278 << V_279 |
V_48 [ V_264 ] . V_280 << V_281 ;
F_25 ( F_114 ( V_1 ) , V_180 ) ;
V_180 = F_32 ( F_115 ( V_1 ) ) ;
V_180 &= ~ V_282 ;
if ( V_48 [ V_264 ] . V_283 )
V_180 |= V_282 ;
if ( ( V_180 & V_284 ) && ! ( V_180 & V_282 ) )
F_33 ( L_17 ) ;
F_25 ( F_116 ( V_1 ) , V_180 ) ;
V_180 = F_32 ( F_117 ( V_1 ) ) ;
V_180 &= ~ V_285 ;
V_180 |= V_48 [ V_264 ] . V_286 << V_287 ;
F_25 ( F_118 ( V_1 ) , V_180 ) ;
V_180 = F_32 ( F_111 ( V_1 ) ) ;
V_180 |= V_274 | V_275 ;
F_25 ( F_112 ( V_1 ) , V_180 ) ;
}
static T_3 F_119 ( int V_288 )
{
T_3 V_264 ;
switch ( V_288 ) {
default:
F_51 ( L_18 ,
V_288 ) ;
case V_289 | V_290 :
V_264 = 0 ;
break;
case V_289 | V_291 :
V_264 = 1 ;
break;
case V_289 | V_292 :
V_264 = 2 ;
break;
case V_289 | V_293 :
V_264 = 3 ;
break;
case V_294 | V_290 :
V_264 = 4 ;
break;
case V_294 | V_291 :
V_264 = 5 ;
break;
case V_294 | V_292 :
V_264 = 6 ;
break;
case V_295 | V_290 :
V_264 = 7 ;
break;
case V_295 | V_291 :
V_264 = 8 ;
break;
case V_296 | V_290 :
V_264 = 9 ;
break;
}
return V_264 ;
}
T_3 F_120 ( struct V_105 * V_105 )
{
struct V_106 * V_297 = F_121 ( V_105 ) ;
struct V_15 * V_16 = F_22 ( V_297 -> V_5 . V_5 . V_39 ) ;
struct V_2 * V_3 = & V_297 -> V_5 ;
T_4 V_298 = V_105 -> V_298 [ 0 ] ;
int V_288 = V_298 & ( V_299 |
V_300 ) ;
enum V_1 V_1 = V_297 -> V_1 ;
T_3 V_264 ;
V_264 = F_119 ( V_288 ) ;
if ( F_16 ( V_16 ) || F_17 ( V_16 ) )
F_109 ( V_3 , V_264 ) ;
else if ( F_15 ( V_16 ) )
F_110 ( V_16 , V_264 , V_1 , V_3 -> type ) ;
return F_47 ( V_264 ) ;
}
void F_122 ( struct V_2 * V_3 ,
struct V_60 * V_61 )
{
struct V_15 * V_16 = F_22 ( V_3 -> V_5 . V_39 ) ;
enum V_1 V_1 = F_1 ( V_3 ) ;
if ( F_23 ( ! V_61 ) )
return;
if ( F_16 ( V_16 ) || F_17 ( V_16 ) ) {
T_3 V_180 ;
V_180 = F_32 ( V_301 ) ;
V_180 &= ~ ( F_123 ( V_1 ) |
F_124 ( V_1 ) ) ;
V_180 |= ( F_125 ( V_61 -> V_62 , V_1 ) |
F_126 ( V_1 ) ) ;
F_25 ( V_301 , V_180 ) ;
} else if ( F_80 ( V_16 ) -> V_208 < 9 ) {
F_25 ( F_45 ( V_1 ) , F_35 ( V_61 ) ) ;
}
}
static void F_127 ( struct V_2 * V_3 ,
int V_302 , T_3 V_110 ,
struct V_60 * V_61 ,
bool V_303 )
{
struct V_105 * V_105 = F_53 ( & V_3 -> V_5 ) ;
struct V_15 * V_16 = F_22 ( V_3 -> V_5 . V_39 ) ;
enum V_1 V_1 = F_1 ( V_3 ) ;
F_128 ( V_105 , V_302 , V_110 ,
V_303 ) ;
if ( V_3 -> type == V_8 )
F_129 ( V_105 ) ;
F_122 ( V_3 , V_61 ) ;
F_21 ( V_3 ) ;
F_52 ( V_3 ) ;
F_130 ( V_105 , V_304 ) ;
F_131 ( V_105 ) ;
if ( V_1 != V_13 || F_132 ( V_16 ) >= 9 )
F_133 ( V_105 ) ;
}
static void F_134 ( struct V_2 * V_3 ,
bool V_166 ,
struct V_305 * V_169 ,
struct V_60 * V_61 )
{
struct V_306 * V_306 = F_135 ( & V_3 -> V_5 ) ;
struct V_15 * V_16 = F_22 ( V_3 -> V_5 . V_39 ) ;
struct V_307 * V_307 = & V_3 -> V_5 ;
enum V_1 V_1 = F_1 ( V_3 ) ;
int V_264 = F_14 ( V_16 , V_1 ) ;
F_136 ( V_306 , true ) ;
F_122 ( V_3 , V_61 ) ;
F_28 ( V_3 ) ;
if ( F_16 ( V_16 ) || F_17 ( V_16 ) )
F_109 ( V_3 , V_264 ) ;
else if ( F_15 ( V_16 ) )
F_110 ( V_16 , V_264 , V_1 ,
V_9 ) ;
V_306 -> V_308 ( V_307 ,
V_166 ,
V_169 ) ;
}
static void F_137 ( struct V_2 * V_2 ,
struct V_114 * V_160 ,
struct V_120 * V_309 )
{
struct V_307 * V_3 = & V_2 -> V_5 ;
struct V_79 * V_77 = F_37 ( V_3 -> V_77 ) ;
int type = V_2 -> type ;
if ( type == V_7 || type == V_8 ) {
F_127 ( V_2 ,
V_77 -> V_89 -> V_163 ,
V_77 -> V_89 -> V_110 ,
V_77 -> V_89 -> V_92 ,
F_138 ( V_77 -> V_89 ,
V_4 ) ) ;
}
if ( type == V_9 ) {
F_134 ( V_2 ,
V_77 -> V_89 -> V_166 ,
& V_77 -> V_89 -> V_5 . V_169 ,
V_77 -> V_89 -> V_92 ) ;
}
}
static void F_139 ( struct V_2 * V_2 ,
struct V_114 * V_310 ,
struct V_120 * V_311 )
{
struct V_307 * V_3 = & V_2 -> V_5 ;
struct V_78 * V_39 = V_3 -> V_39 ;
struct V_15 * V_16 = F_22 ( V_39 ) ;
enum V_1 V_1 = F_1 ( V_2 ) ;
int type = V_2 -> type ;
T_3 V_180 ;
bool V_312 = false ;
V_180 = F_32 ( F_30 ( V_1 ) ) ;
if ( V_180 & V_97 ) {
V_180 &= ~ V_97 ;
F_25 ( F_30 ( V_1 ) , V_180 ) ;
V_312 = true ;
}
V_180 = F_32 ( F_46 ( V_1 ) ) ;
V_180 &= ~ ( V_96 | V_103 ) ;
V_180 |= V_95 ;
F_25 ( F_46 ( V_1 ) , V_180 ) ;
if ( V_312 )
F_29 ( V_16 , V_1 ) ;
if ( type == V_7 || type == V_8 ) {
struct V_105 * V_105 = F_53 ( V_3 ) ;
F_130 ( V_105 , V_313 ) ;
F_140 ( V_105 ) ;
F_141 ( V_105 ) ;
}
if ( F_16 ( V_39 ) || F_17 ( V_39 ) )
F_25 ( V_301 , ( F_32 ( V_301 ) |
F_123 ( V_1 ) ) ) ;
else if ( F_80 ( V_39 ) -> V_208 < 9 )
F_25 ( F_45 ( V_1 ) , V_75 ) ;
if ( type == V_9 ) {
struct V_306 * V_306 = F_135 ( V_3 ) ;
F_136 ( V_306 , false ) ;
}
}
void F_142 ( struct V_2 * V_2 ,
struct V_114 * V_310 ,
struct V_120 * V_311 )
{
struct V_15 * V_16 = F_22 ( V_2 -> V_5 . V_39 ) ;
T_3 V_180 ;
V_180 = F_32 ( F_43 ( V_83 ) ) ;
V_180 &= ~ V_98 ;
F_25 ( F_43 ( V_83 ) , V_180 ) ;
F_139 ( V_2 , V_310 , V_311 ) ;
V_180 = F_32 ( F_39 ( V_83 ) ) ;
V_180 &= ~ ( V_100 | V_101 ) ;
V_180 |= F_40 ( 2 ) | F_41 ( 2 ) ;
F_25 ( F_39 ( V_83 ) , V_180 ) ;
V_180 = F_32 ( F_43 ( V_83 ) ) ;
V_180 &= ~ V_91 ;
F_25 ( F_43 ( V_83 ) , V_180 ) ;
V_180 = F_32 ( F_43 ( V_83 ) ) ;
V_180 &= ~ V_88 ;
F_25 ( F_43 ( V_83 ) , V_180 ) ;
}
static void F_143 ( struct V_2 * V_2 ,
struct V_114 * V_160 ,
struct V_120 * V_309 )
{
struct V_307 * V_3 = & V_2 -> V_5 ;
struct V_76 * V_77 = V_3 -> V_77 ;
struct V_79 * V_79 = F_37 ( V_77 ) ;
struct V_78 * V_39 = V_3 -> V_39 ;
struct V_15 * V_16 = F_22 ( V_39 ) ;
enum V_1 V_1 = F_1 ( V_2 ) ;
int type = V_2 -> type ;
if ( type == V_9 ) {
struct V_106 * V_107 =
F_3 ( V_3 ) ;
F_25 ( F_30 ( V_1 ) ,
V_107 -> V_109 |
V_97 ) ;
} else if ( type == V_8 ) {
struct V_105 * V_105 = F_53 ( V_3 ) ;
if ( V_1 == V_13 && F_80 ( V_39 ) -> V_208 < 9 )
F_133 ( V_105 ) ;
F_144 ( V_105 ) ;
F_145 ( V_105 ) ;
F_146 ( V_105 , V_160 ) ;
}
if ( V_79 -> V_89 -> V_314 ) {
F_147 ( V_16 , V_315 ) ;
F_148 ( V_2 ) ;
}
}
static void F_149 ( struct V_2 * V_2 ,
struct V_114 * V_310 ,
struct V_120 * V_311 )
{
struct V_307 * V_3 = & V_2 -> V_5 ;
struct V_76 * V_77 = V_3 -> V_77 ;
struct V_79 * V_79 = F_37 ( V_77 ) ;
int type = V_2 -> type ;
struct V_78 * V_39 = V_3 -> V_39 ;
struct V_15 * V_16 = F_22 ( V_39 ) ;
if ( V_79 -> V_89 -> V_314 ) {
F_150 ( V_2 ) ;
F_98 ( V_16 , V_315 ) ;
}
if ( type == V_8 ) {
struct V_105 * V_105 = F_53 ( V_3 ) ;
F_151 ( V_105 , V_310 ) ;
F_152 ( V_105 ) ;
F_153 ( V_105 ) ;
}
}
bool F_154 ( struct V_15 * V_16 ,
enum V_316 V_317 )
{
enum V_1 V_1 ;
if ( ! ( F_32 ( V_318 ) & F_155 ( V_317 ) ) )
return false ;
if ( ( F_32 ( F_156 ( V_317 ) ) &
( V_319 | V_320 ) ) != V_319 ) {
F_83 ( L_19 ,
V_317 ) ;
return false ;
}
if ( V_317 == V_321 &&
! ( F_32 ( F_157 ( V_321 ) ) & V_322 ) ) {
F_83 ( L_20 ) ;
return false ;
}
if ( ! ( F_32 ( F_158 ( V_317 ) ) & V_323 ) ) {
F_83 ( L_21 ,
V_317 ) ;
return false ;
}
F_159 (port,
phy == DPIO_PHY0 ? BIT(PORT_B) | BIT(PORT_C) :
BIT(PORT_A)) {
T_1 V_248 = F_32 ( F_100 ( V_1 ) ) ;
if ( V_248 & V_324 ) {
F_83 ( L_22
L_23
L_14 ,
V_317 , F_34 ( V_1 ) , V_248 ) ;
return false ;
}
}
return true ;
}
static T_1 F_160 ( struct V_15 * V_16 , enum V_316 V_317 )
{
T_1 V_180 = F_32 ( F_161 ( V_317 ) ) ;
return ( V_180 & V_325 ) >> V_326 ;
}
static void F_162 ( struct V_15 * V_16 ,
enum V_316 V_317 )
{
if ( F_163 ( V_16 ,
F_157 ( V_317 ) ,
V_322 , V_322 ,
10 ) )
F_33 ( L_24 , V_317 ) ;
}
void F_164 ( struct V_15 * V_16 , enum V_316 V_317 )
{
T_1 V_180 ;
if ( F_154 ( V_16 , V_317 ) ) {
if ( V_317 == V_327 )
V_16 -> V_328 = F_160 ( V_16 , V_317 ) ;
if ( F_165 ( V_16 , V_317 ) ) {
F_83 ( L_25
L_26 , V_317 ) ;
return;
}
F_83 ( L_27
L_28 , V_317 ) ;
}
V_180 = F_32 ( V_318 ) ;
V_180 |= F_155 ( V_317 ) ;
F_25 ( V_318 , V_180 ) ;
if ( F_166 ( ( ( F_32 ( F_156 ( V_317 ) ) &
( V_320 | V_319 ) ) == V_319 ) , 100 ) ) {
F_33 ( L_29 , V_317 ) ;
}
V_180 = F_32 ( F_167 ( V_317 ) ) ;
V_180 &= ~ V_329 ;
V_180 |= 0xE4 << V_330 ;
F_25 ( F_167 ( V_317 ) , V_180 ) ;
V_180 = F_32 ( F_168 ( V_317 ) ) ;
V_180 &= ~ V_331 ;
V_180 |= 0xE4 << V_332 ;
F_25 ( F_168 ( V_317 ) , V_180 ) ;
V_180 = F_32 ( F_169 ( V_317 ) ) ;
V_180 |= V_333 | V_334 |
V_335 ;
F_25 ( F_169 ( V_317 ) , V_180 ) ;
if ( V_317 == V_327 ) {
V_180 = F_32 ( V_336 ) ;
V_180 |= V_337 ;
F_25 ( V_336 , V_180 ) ;
}
V_180 = F_32 ( F_170 ( V_317 ) ) ;
V_180 &= ~ V_338 ;
if ( V_317 == V_321 )
V_180 |= V_338 ;
F_25 ( F_170 ( V_317 ) , V_180 ) ;
if ( V_317 == V_327 ) {
T_3 V_339 ;
V_180 = V_16 -> V_328 = F_160 ( V_16 , V_321 ) ;
V_339 = V_180 << V_340 |
V_180 << V_341 |
V_180 ;
F_25 ( F_161 ( V_327 ) , V_339 ) ;
V_180 = F_32 ( F_171 ( V_327 ) ) ;
V_180 |= V_342 | V_343 ;
F_25 ( F_171 ( V_327 ) , V_180 ) ;
}
V_180 = F_32 ( F_158 ( V_317 ) ) ;
V_180 |= V_323 ;
F_25 ( F_158 ( V_317 ) , V_180 ) ;
if ( V_317 == V_321 )
F_162 ( V_16 , V_321 ) ;
}
void F_172 ( struct V_15 * V_16 , enum V_316 V_317 )
{
T_3 V_180 ;
V_180 = F_32 ( F_158 ( V_317 ) ) ;
V_180 &= ~ V_323 ;
F_25 ( F_158 ( V_317 ) , V_180 ) ;
V_180 = F_32 ( V_318 ) ;
V_180 &= ~ F_155 ( V_317 ) ;
F_25 ( V_318 , V_180 ) ;
}
bool F_165 ( struct V_15 * V_16 ,
enum V_316 V_317 )
{
T_3 V_344 ;
bool V_345 ;
#define F_173 ( V_58 , V_344 , exp , T_5 , ... ) \
__phy_reg_verify_state(dev_priv, phy, reg, mask, exp, fmt, \
## __VA_ARGS__)
if ( ! F_154 ( V_16 , V_317 ) )
return false ;
V_345 = true ;
V_345 &= F_173 ( F_167 ( V_317 ) ,
V_329 , 0xe4 << V_330 ,
L_30 , V_317 ) ;
V_345 &= F_173 ( F_168 ( V_317 ) ,
V_331 , 0xe4 << V_332 ,
L_31 , V_317 ) ;
V_344 = V_333 | V_334 | V_335 ;
V_345 &= F_173 ( F_169 ( V_317 ) , V_344 , V_344 ,
L_32 , V_317 ) ;
if ( V_317 == V_327 )
V_345 &= F_173 ( V_336 ,
V_337 , V_337 ,
L_33 ) ;
if ( V_317 == V_327 ) {
T_1 V_339 = V_16 -> V_328 ;
V_339 = V_339 << V_340 |
V_339 << V_341 |
V_339 ;
V_344 = V_346 | V_347 |
V_348 ;
V_345 &= F_173 ( F_161 ( V_327 ) , V_344 , V_339 ,
L_34 , V_327 ) ;
V_344 = V_342 | V_343 ;
V_345 &= F_173 ( F_171 ( V_327 ) , V_344 , V_344 ,
L_35 , V_327 ) ;
}
return V_345 ;
#undef F_173
}
static T_4
F_174 ( struct V_2 * V_3 ,
struct V_114 * V_160 )
{
switch ( V_160 -> V_110 ) {
case 1 :
return 0 ;
case 2 :
return F_175 ( 2 ) | F_175 ( 0 ) ;
case 4 :
return F_175 ( 3 ) | F_175 ( 2 ) | F_175 ( 0 ) ;
default:
F_4 ( V_160 -> V_110 ) ;
return 0 ;
}
}
static void F_176 ( struct V_2 * V_3 ,
struct V_114 * V_160 ,
struct V_120 * V_309 )
{
struct V_106 * V_297 = F_3 ( & V_3 -> V_5 ) ;
struct V_15 * V_16 = F_22 ( V_297 -> V_5 . V_5 . V_39 ) ;
enum V_1 V_1 = V_297 -> V_1 ;
struct V_79 * V_79 = F_37 ( V_3 -> V_5 . V_77 ) ;
int V_349 ;
for ( V_349 = 0 ; V_349 < 4 ; V_349 ++ ) {
T_1 V_180 = F_32 ( F_177 ( V_1 , V_349 ) ) ;
V_180 &= ~ V_350 ;
if ( V_79 -> V_89 -> V_351 & F_175 ( V_349 ) )
V_180 |= V_350 ;
F_25 ( F_177 ( V_1 , V_349 ) , V_180 ) ;
}
}
static T_4
F_178 ( struct V_2 * V_3 )
{
struct V_106 * V_297 = F_3 ( & V_3 -> V_5 ) ;
struct V_15 * V_16 = F_22 ( V_297 -> V_5 . V_5 . V_39 ) ;
enum V_1 V_1 = V_297 -> V_1 ;
int V_349 ;
T_4 V_344 ;
V_344 = 0 ;
for ( V_349 = 0 ; V_349 < 4 ; V_349 ++ ) {
T_1 V_180 = F_32 ( F_177 ( V_1 , V_349 ) ) ;
if ( V_180 & V_350 )
V_344 |= F_175 ( V_349 ) ;
}
return V_344 ;
}
void F_179 ( struct V_105 * V_105 )
{
struct V_106 * V_107 = F_121 ( V_105 ) ;
struct V_15 * V_16 =
F_22 ( V_107 -> V_5 . V_5 . V_39 ) ;
enum V_1 V_1 = V_107 -> V_1 ;
T_3 V_180 ;
bool V_312 = false ;
if ( F_32 ( F_46 ( V_1 ) ) & V_96 ) {
V_180 = F_32 ( F_30 ( V_1 ) ) ;
if ( V_180 & V_97 ) {
V_180 &= ~ V_97 ;
F_25 ( F_30 ( V_1 ) , V_180 ) ;
V_312 = true ;
}
V_180 = F_32 ( F_46 ( V_1 ) ) ;
V_180 &= ~ ( V_96 | V_103 ) ;
V_180 |= V_95 ;
F_25 ( F_46 ( V_1 ) , V_180 ) ;
F_44 ( F_46 ( V_1 ) ) ;
if ( V_312 )
F_29 ( V_16 , V_1 ) ;
}
V_180 = V_96 |
V_95 | V_352 ;
if ( V_105 -> V_303 )
V_180 |= V_353 ;
else {
V_180 |= V_354 ;
if ( F_180 ( V_105 -> V_355 ) )
V_180 |= V_94 ;
}
F_25 ( F_46 ( V_1 ) , V_180 ) ;
F_44 ( F_46 ( V_1 ) ) ;
V_105 -> V_108 |= V_97 ;
F_25 ( F_30 ( V_1 ) , V_105 -> V_108 ) ;
F_44 ( F_30 ( V_1 ) ) ;
F_31 ( 600 ) ;
}
void F_181 ( struct V_2 * V_3 ,
struct V_114 * V_160 )
{
struct V_15 * V_16 = F_22 ( V_3 -> V_5 . V_39 ) ;
struct V_79 * V_79 = F_37 ( V_3 -> V_5 . V_77 ) ;
enum V_209 V_210 = V_160 -> V_210 ;
struct V_306 * V_306 ;
T_1 V_80 , V_222 = 0 ;
if ( F_23 ( F_88 ( V_210 ) ) )
return;
V_80 = F_32 ( F_91 ( V_210 ) ) ;
if ( V_80 & V_226 )
V_222 |= V_225 ;
else
V_222 |= V_356 ;
if ( V_80 & V_224 )
V_222 |= V_223 ;
else
V_222 |= V_357 ;
V_160 -> V_5 . V_169 . V_222 |= V_222 ;
switch ( V_80 & V_358 ) {
case V_218 :
V_160 -> V_167 = 18 ;
break;
case V_219 :
V_160 -> V_167 = 24 ;
break;
case V_220 :
V_160 -> V_167 = 30 ;
break;
case V_221 :
V_160 -> V_167 = 36 ;
break;
default:
break;
}
switch ( V_80 & V_251 ) {
case V_237 :
V_160 -> V_166 = true ;
V_306 = F_135 ( & V_3 -> V_5 ) ;
if ( V_306 -> V_359 ( & V_3 -> V_5 , V_160 ) )
V_160 -> V_360 = true ;
case V_238 :
V_160 -> V_110 = 4 ;
break;
case V_239 :
break;
case V_240 :
case V_241 :
V_160 -> V_110 =
( ( V_80 & V_361 ) >> V_362 ) + 1 ;
F_182 ( V_79 , V_160 ) ;
break;
default:
break;
}
if ( F_183 ( V_16 , V_315 ) ) {
V_80 = F_32 ( V_363 ) ;
if ( V_80 & F_184 ( V_79 -> V_113 ) )
V_160 -> V_314 = true ;
}
if ( V_3 -> type == V_8 && V_16 -> V_18 . V_19 . V_364 &&
V_160 -> V_167 > V_16 -> V_18 . V_19 . V_364 ) {
F_51 ( L_36 ,
V_160 -> V_167 , V_16 -> V_18 . V_19 . V_364 ) ;
V_16 -> V_18 . V_19 . V_364 = V_160 -> V_167 ;
}
F_79 ( V_3 , V_160 ) ;
if ( F_15 ( V_16 ) )
V_160 -> V_351 =
F_178 ( V_3 ) ;
}
static bool F_185 ( struct V_2 * V_3 ,
struct V_114 * V_160 ,
struct V_120 * V_309 )
{
struct V_15 * V_16 = F_22 ( V_3 -> V_5 . V_39 ) ;
int type = V_3 -> type ;
int V_1 = F_1 ( V_3 ) ;
int V_111 ;
F_20 ( type == V_10 , L_37 ) ;
if ( V_1 == V_13 )
V_160 -> V_210 = V_227 ;
if ( type == V_9 )
V_111 = F_186 ( V_3 , V_160 , V_309 ) ;
else
V_111 = F_187 ( V_3 , V_160 , V_309 ) ;
if ( F_15 ( V_16 ) && V_111 )
V_160 -> V_351 =
F_174 ( V_3 ,
V_160 ) ;
return V_111 ;
}
static struct V_244 *
F_188 ( struct V_106 * V_107 )
{
struct V_244 * V_119 ;
enum V_1 V_1 = V_107 -> V_1 ;
V_119 = F_189 () ;
if ( ! V_119 )
return NULL ;
V_107 -> V_365 . V_366 = F_30 ( V_1 ) ;
if ( ! F_190 ( V_107 , V_119 ) ) {
F_191 ( V_119 ) ;
return NULL ;
}
return V_119 ;
}
static struct V_244 *
F_192 ( struct V_106 * V_107 )
{
struct V_244 * V_119 ;
enum V_1 V_1 = V_107 -> V_1 ;
V_119 = F_189 () ;
if ( ! V_119 )
return NULL ;
V_107 -> V_367 . V_368 = F_30 ( V_1 ) ;
F_193 ( V_107 , V_119 ) ;
return V_119 ;
}
struct V_60 *
F_194 ( struct V_105 * V_105 , int clock )
{
struct V_244 * V_119 = V_105 -> V_369 ;
struct V_2 * V_3 = V_119 -> V_3 ;
struct V_15 * V_16 = F_22 ( V_3 -> V_5 . V_39 ) ;
struct V_106 * V_370 = F_121 ( V_105 ) ;
struct V_60 * V_61 = NULL ;
struct V_371 V_372 ;
enum V_187 V_373 ;
if ( F_15 ( V_16 ) ) {
V_373 = (enum V_187 ) V_370 -> V_1 ;
V_61 = & V_16 -> V_190 [ V_373 ] ;
if ( F_23 ( V_61 -> V_374 ) ) {
F_33 ( L_38 ,
V_61 -> V_374 ) ;
return NULL ;
}
V_372 = V_61 -> V_89 ;
if ( ! F_195 ( clock ,
& V_61 -> V_89 . V_191 ) ) {
F_33 ( L_39 ) ;
V_61 -> V_89 = V_372 ;
return NULL ;
}
} else if ( F_16 ( V_16 ) || F_17 ( V_16 ) ) {
V_61 = F_196 ( V_16 , clock ) ;
} else if ( F_19 ( V_16 ) || F_18 ( V_16 ) ) {
V_61 = F_197 ( V_3 , clock ) ;
}
return V_61 ;
}
void F_198 ( struct V_78 * V_39 , enum V_1 V_1 )
{
struct V_15 * V_16 = F_22 ( V_39 ) ;
struct V_106 * V_107 ;
struct V_2 * V_2 ;
struct V_307 * V_3 ;
bool V_375 , V_376 ;
int V_268 ;
if ( F_32 ( F_30 ( V_13 ) ) & V_377 ) {
switch ( V_1 ) {
case V_13 :
V_268 = 4 ;
break;
case V_12 :
V_268 = 0 ;
break;
default:
V_268 = 4 ;
break;
}
} else {
switch ( V_1 ) {
case V_13 :
V_268 = 2 ;
break;
case V_12 :
V_268 = 2 ;
break;
default:
V_268 = 4 ;
break;
}
}
V_375 = ( V_16 -> V_18 . V_34 [ V_1 ] . V_378 ||
V_16 -> V_18 . V_34 [ V_1 ] . V_379 ) ;
V_376 = V_16 -> V_18 . V_34 [ V_1 ] . V_380 ;
if ( ! V_376 && ! V_375 ) {
F_51 ( L_40 ,
F_34 ( V_1 ) ) ;
return;
}
V_107 = F_199 ( sizeof( * V_107 ) , V_381 ) ;
if ( ! V_107 )
return;
V_2 = & V_107 -> V_5 ;
V_3 = & V_2 -> V_5 ;
F_200 ( V_39 , V_3 , & V_382 ,
V_383 , L_41 , F_34 ( V_1 ) ) ;
V_2 -> V_384 = F_185 ;
V_2 -> V_283 = F_143 ;
if ( F_15 ( V_16 ) )
V_2 -> V_385 = F_176 ;
V_2 -> V_386 = F_137 ;
V_2 -> V_387 = F_149 ;
V_2 -> V_388 = F_139 ;
V_2 -> V_249 = F_99 ;
V_2 -> V_389 = F_181 ;
V_2 -> V_390 = V_391 ;
V_107 -> V_1 = V_1 ;
V_107 -> V_109 = F_32 ( F_30 ( V_1 ) ) &
( V_392 |
V_377 ) ;
if ( F_15 ( V_39 ) && V_1 == V_13 ) {
if ( ! ( V_107 -> V_109 & V_377 ) ) {
F_51 ( L_42 ) ;
V_107 -> V_109 |= V_377 ;
V_268 = 4 ;
}
}
V_107 -> V_268 = V_268 ;
V_2 -> type = V_10 ;
V_2 -> V_393 = ( 1 << 0 ) | ( 1 << 1 ) | ( 1 << 2 ) ;
V_2 -> V_394 = 0 ;
if ( V_376 ) {
if ( ! F_188 ( V_107 ) )
goto V_395;
V_107 -> V_396 = V_397 ;
if ( F_201 ( V_39 , 0 , V_398 ) && V_1 == V_399 )
V_16 -> V_400 . V_401 [ V_13 ] = V_107 ;
else
V_16 -> V_400 . V_401 [ V_1 ] = V_107 ;
}
if ( V_2 -> type != V_8 && V_375 ) {
if ( ! F_192 ( V_107 ) )
goto V_395;
}
return;
V_395:
F_202 ( V_3 ) ;
F_191 ( V_107 ) ;
}
