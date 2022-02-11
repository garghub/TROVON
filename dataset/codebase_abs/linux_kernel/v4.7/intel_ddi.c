static void F_1 ( struct V_1 * V_1 ,
struct V_2 * * V_3 ,
enum V_4 * V_4 )
{
struct V_5 * V_6 = & V_1 -> V_7 ;
switch ( V_1 -> type ) {
case V_8 :
* V_3 = F_2 ( V_6 ) -> V_9 ;
* V_4 = ( * V_3 ) -> V_4 ;
break;
default:
F_3 ( 1 , L_1 , V_1 -> type ) ;
case V_10 :
case V_11 :
case V_12 :
case V_13 :
* V_3 = F_4 ( V_6 ) ;
* V_4 = ( * V_3 ) -> V_4 ;
break;
case V_14 :
* V_3 = NULL ;
* V_4 = V_15 ;
break;
}
}
enum V_4 F_5 ( struct V_1 * V_1 )
{
struct V_2 * V_3 ;
enum V_4 V_4 ;
F_1 ( V_1 , & V_3 , & V_4 ) ;
return V_4 ;
}
static const struct V_16 *
F_6 ( struct V_17 * V_18 , int * V_19 )
{
if ( F_7 ( V_18 ) || F_8 ( V_18 ) ) {
* V_19 = F_9 ( V_20 ) ;
return V_20 ;
} else if ( F_10 ( V_18 ) || F_11 ( V_18 ) ) {
* V_19 = F_9 ( V_21 ) ;
return V_21 ;
} else {
* V_19 = F_9 ( V_22 ) ;
return V_22 ;
}
}
static const struct V_16 *
F_12 ( struct V_17 * V_18 , int * V_19 )
{
if ( V_18 -> V_23 . V_24 . V_25 ) {
if ( F_7 ( V_18 ) || F_8 ( V_18 ) ) {
* V_19 = F_9 ( V_26 ) ;
return V_26 ;
} else if ( F_10 ( V_18 ) || F_11 ( V_18 ) ) {
* V_19 = F_9 ( V_27 ) ;
return V_27 ;
} else {
* V_19 = F_9 ( V_28 ) ;
return V_28 ;
}
}
return F_6 ( V_18 , V_19 ) ;
}
static const struct V_16 *
F_13 ( struct V_17 * V_18 , int * V_19 )
{
if ( F_7 ( V_18 ) || F_8 ( V_18 ) ) {
* V_19 = F_9 ( V_29 ) ;
return V_29 ;
} else {
* V_19 = F_9 ( V_30 ) ;
return V_30 ;
}
}
void F_14 ( struct V_1 * V_6 )
{
struct V_17 * V_18 = F_15 ( V_6 -> V_7 . V_31 ) ;
T_1 V_32 = 0 ;
int V_33 , V_34 , V_35 , V_36 , V_37 ,
V_38 ;
int V_39 ;
enum V_4 V_4 ;
const struct V_16 * V_40 ;
const struct V_16 * V_41 ;
const struct V_16 * V_42 ;
const struct V_16 * V_43 ;
const struct V_16 * V_44 ;
V_4 = F_5 ( V_6 ) ;
V_39 = V_18 -> V_23 . V_45 [ V_4 ] . V_46 ;
if ( F_16 ( V_18 ) ) {
if ( V_6 -> type != V_12 )
return;
F_17 ( V_18 , V_39 , V_4 ,
V_12 ) ;
return;
}
if ( F_18 ( V_18 ) || F_19 ( V_18 ) ) {
V_40 = NULL ;
V_41 =
F_6 ( V_18 , & V_35 ) ;
V_42 =
F_12 ( V_18 , & V_36 ) ;
V_43 =
F_13 ( V_18 , & V_34 ) ;
V_37 = 8 ;
if ( V_18 -> V_23 . V_45 [ V_4 ] . V_47 ||
V_18 -> V_23 . V_45 [ V_4 ] . V_48 )
V_32 = 1 << 31 ;
if ( F_20 ( V_6 -> type == V_11 &&
V_4 != V_49 && V_4 != V_15 &&
V_36 > 9 ) )
V_36 = 9 ;
} else if ( F_21 ( V_18 ) ) {
V_40 = V_50 ;
V_41 = V_51 ;
if ( V_18 -> V_23 . V_24 . V_25 ) {
V_42 = V_52 ;
V_36 = F_9 ( V_52 ) ;
} else {
V_42 = V_51 ;
V_36 = F_9 ( V_51 ) ;
}
V_43 = V_53 ;
V_35 = F_9 ( V_51 ) ;
V_34 = F_9 ( V_53 ) ;
V_37 = 7 ;
} else if ( F_22 ( V_18 ) ) {
V_40 = V_54 ;
V_41 = V_55 ;
V_42 = V_55 ;
V_43 = V_56 ;
V_35 = V_36 = F_9 ( V_55 ) ;
V_34 = F_9 ( V_56 ) ;
V_37 = 6 ;
} else {
F_3 ( 1 , L_2 ) ;
V_42 = V_51 ;
V_40 = V_50 ;
V_41 = V_51 ;
V_43 = V_53 ;
V_36 = F_9 ( V_52 ) ;
V_35 = F_9 ( V_51 ) ;
V_34 = F_9 ( V_53 ) ;
V_37 = 7 ;
}
switch ( V_6 -> type ) {
case V_11 :
V_44 = V_42 ;
V_38 = V_36 ;
break;
case V_10 :
case V_12 :
V_44 = V_41 ;
V_38 = V_35 ;
break;
case V_14 :
V_44 = V_40 ;
V_38 = V_35 ;
break;
default:
F_23 () ;
}
for ( V_33 = 0 ; V_33 < V_38 ; V_33 ++ ) {
F_24 ( F_25 ( V_4 , V_33 ) ,
V_44 [ V_33 ] . V_57 | V_32 ) ;
F_24 ( F_26 ( V_4 , V_33 ) ,
V_44 [ V_33 ] . V_58 ) ;
}
if ( V_6 -> type != V_12 )
return;
if ( V_39 == V_59 ||
V_39 >= V_34 )
V_39 = V_37 ;
F_24 ( F_25 ( V_4 , V_33 ) ,
V_43 [ V_39 ] . V_57 | V_32 ) ;
F_24 ( F_26 ( V_4 , V_33 ) ,
V_43 [ V_39 ] . V_58 ) ;
}
static void F_27 ( struct V_17 * V_18 ,
enum V_4 V_4 )
{
T_2 V_60 = F_28 ( V_4 ) ;
int V_33 ;
for ( V_33 = 0 ; V_33 < 16 ; V_33 ++ ) {
F_29 ( 1 ) ;
if ( F_30 ( V_60 ) & V_61 )
return;
}
F_31 ( L_3 , F_32 ( V_4 ) ) ;
}
void F_33 ( struct V_62 * V_63 )
{
struct V_64 * V_31 = V_63 -> V_31 ;
struct V_17 * V_18 = V_31 -> V_65 ;
struct V_66 * V_66 = F_34 ( V_63 ) ;
struct V_1 * V_6 ;
T_1 V_67 , V_33 , V_68 ;
F_35 (dev, crtc, encoder) {
F_20 ( V_6 -> type != V_14 ) ;
F_14 ( V_6 ) ;
}
F_24 ( F_36 ( V_69 ) , F_37 ( 2 ) |
F_38 ( 2 ) |
V_70 | V_71 ) ;
V_68 = V_18 -> V_72 | V_73 |
V_74 |
F_39 ( V_66 -> V_75 -> V_76 ) ;
F_24 ( F_40 ( V_69 ) , V_68 ) ;
F_41 ( F_40 ( V_69 ) ) ;
F_29 ( 220 ) ;
V_68 |= V_77 ;
F_24 ( F_40 ( V_69 ) , V_68 ) ;
F_24 ( F_42 ( V_15 ) , V_66 -> V_75 -> V_78 ) ;
F_20 ( V_66 -> V_75 -> V_78 != V_79 ) ;
for ( V_33 = 0 ; V_33 < F_9 ( V_54 ) * 2 ; V_33 ++ ) {
F_24 ( F_43 ( V_15 ) ,
V_80 |
V_81 |
V_82 |
V_83 ) ;
F_24 ( F_28 ( V_15 ) ,
V_84 |
( ( V_66 -> V_75 -> V_76 - 1 ) << 1 ) |
F_44 ( V_33 / 2 ) ) ;
F_41 ( F_28 ( V_15 ) ) ;
F_29 ( 600 ) ;
F_24 ( F_45 ( V_69 ) , F_46 ( 64 ) ) ;
V_68 |= V_85 | V_86 ;
F_24 ( F_40 ( V_69 ) , V_68 ) ;
F_41 ( F_40 ( V_69 ) ) ;
F_29 ( 30 ) ;
V_67 = F_30 ( F_36 ( V_69 ) ) ;
V_67 &= ~ ( V_87 | V_88 ) ;
F_24 ( F_36 ( V_69 ) , V_67 ) ;
F_41 ( F_36 ( V_69 ) ) ;
F_29 ( 5 ) ;
V_67 = F_30 ( F_47 ( V_15 ) ) ;
if ( V_67 & V_89 ) {
F_48 ( L_4 , V_33 ) ;
break;
}
if ( V_33 == F_9 ( V_54 ) * 2 - 1 ) {
F_31 ( L_5 ) ;
break;
}
V_68 &= ~ V_85 ;
F_24 ( F_40 ( V_69 ) , V_68 ) ;
F_41 ( F_40 ( V_69 ) ) ;
V_67 = F_30 ( F_28 ( V_15 ) ) ;
V_67 &= ~ V_84 ;
F_24 ( F_28 ( V_15 ) , V_67 ) ;
F_41 ( F_28 ( V_15 ) ) ;
V_67 = F_30 ( F_43 ( V_15 ) ) ;
V_67 &= ~ ( V_83 | V_90 ) ;
V_67 |= V_82 ;
F_24 ( F_43 ( V_15 ) , V_67 ) ;
F_41 ( F_43 ( V_15 ) ) ;
F_27 ( V_18 , V_15 ) ;
V_67 = F_30 ( F_36 ( V_69 ) ) ;
V_67 &= ~ ( V_87 | V_88 ) ;
V_67 |= F_37 ( 2 ) | F_38 ( 2 ) ;
F_24 ( F_36 ( V_69 ) , V_67 ) ;
F_41 ( F_36 ( V_69 ) ) ;
}
F_24 ( F_43 ( V_15 ) ,
V_80 |
V_91 |
V_81 |
V_83 ) ;
}
void F_49 ( struct V_1 * V_6 )
{
struct V_92 * V_92 = F_50 ( & V_6 -> V_7 ) ;
struct V_2 * V_93 =
F_4 ( & V_6 -> V_7 ) ;
V_92 -> V_94 = V_93 -> V_95 |
V_84 | F_44 ( 0 ) ;
V_92 -> V_94 |= F_51 ( V_92 -> V_96 ) ;
}
static struct V_1 *
F_52 ( struct V_62 * V_63 )
{
struct V_64 * V_31 = V_63 -> V_31 ;
struct V_66 * V_66 = F_34 ( V_63 ) ;
struct V_1 * V_1 , * V_97 = NULL ;
int V_98 = 0 ;
F_35 (dev, crtc, intel_encoder) {
V_97 = V_1 ;
V_98 ++ ;
}
if ( V_98 != 1 )
F_3 ( 1 , L_6 , V_98 ,
F_53 ( V_66 -> V_99 ) ) ;
F_54 ( V_97 == NULL ) ;
return V_97 ;
}
struct V_1 *
F_55 ( struct V_100 * V_101 )
{
struct V_66 * V_63 = F_34 ( V_101 -> V_7 . V_63 ) ;
struct V_1 * V_97 = NULL ;
struct V_102 * V_103 ;
struct V_104 * V_105 ;
struct V_106 * V_107 ;
int V_98 = 0 ;
int V_33 ;
V_103 = V_101 -> V_7 . V_103 ;
F_56 (state, connector, connector_state, i) {
if ( V_107 -> V_63 != V_101 -> V_7 . V_63 )
continue;
V_97 = F_57 ( V_107 -> V_108 ) ;
V_98 ++ ;
}
F_3 ( V_98 != 1 , L_6 , V_98 ,
F_53 ( V_63 -> V_99 ) ) ;
F_54 ( V_97 == NULL ) ;
return V_97 ;
}
static int F_58 ( struct V_17 * V_18 ,
T_2 V_60 )
{
int V_109 = V_110 ;
int V_111 , V_112 , V_113 ;
T_1 V_114 ;
V_114 = F_30 ( V_60 ) ;
switch ( V_114 & V_115 ) {
case V_116 :
case V_117 :
V_109 = 135 ;
break;
case V_118 :
V_109 = V_110 ;
break;
default:
F_3 ( 1 , L_7 ) ;
return 0 ;
}
V_113 = V_114 & V_119 ;
V_112 = ( V_114 & V_120 ) >> V_121 ;
V_111 = ( V_114 & V_122 ) >> V_123 ;
return ( V_109 * V_111 * 100 ) / ( V_112 * V_113 ) ;
}
static int F_59 ( struct V_17 * V_18 ,
T_3 V_124 )
{
T_2 V_125 , V_126 ;
T_3 V_127 , V_128 ;
T_3 V_129 , V_130 , V_131 , V_132 ;
V_125 = F_60 ( V_124 ) ;
V_126 = F_61 ( V_124 ) ;
V_127 = F_30 ( V_125 ) ;
V_128 = F_30 ( V_126 ) ;
V_129 = V_128 & V_133 ;
V_131 = V_128 & V_134 ;
if ( V_128 & F_62 ( 1 ) )
V_130 = ( V_128 & V_135 ) >> 8 ;
else
V_130 = 1 ;
switch ( V_129 ) {
case V_136 :
V_129 = 1 ;
break;
case V_137 :
V_129 = 2 ;
break;
case V_138 :
V_129 = 3 ;
break;
case V_139 :
V_129 = 7 ;
break;
}
switch ( V_131 ) {
case V_140 :
V_131 = 5 ;
break;
case V_141 :
V_131 = 2 ;
break;
case V_142 :
V_131 = 3 ;
break;
case V_143 :
V_131 = 1 ;
break;
}
V_132 = ( V_127 & V_144 ) * 24 * 1000 ;
V_132 += ( ( ( V_127 & V_145 ) >> 9 ) * 24 *
1000 ) / 0x8000 ;
return V_132 / ( V_129 * V_130 * V_131 * 5 ) ;
}
static void F_63 ( struct V_100 * V_146 )
{
int V_147 ;
if ( V_146 -> V_148 )
V_147 = F_64 ( V_146 -> V_149 ,
& V_146 -> V_150 ) ;
else if ( V_146 -> V_151 )
V_147 = F_64 ( V_146 -> V_149 ,
& V_146 -> V_152 ) ;
else if ( V_146 -> V_153 && V_146 -> V_154 == 36 )
V_147 = V_146 -> V_149 * 2 / 3 ;
else
V_147 = V_146 -> V_149 ;
if ( V_146 -> V_155 )
V_147 /= V_146 -> V_155 ;
V_146 -> V_7 . V_156 . V_157 = V_147 ;
}
static void F_65 ( struct V_1 * V_6 ,
struct V_100 * V_146 )
{
struct V_17 * V_18 = V_6 -> V_7 . V_31 -> V_65 ;
int V_158 = 0 ;
T_3 V_159 , V_124 ;
V_124 = V_146 -> V_78 ;
V_159 = F_30 ( V_160 ) ;
if ( V_159 & F_66 ( V_124 ) ) {
V_158 = F_59 ( V_18 , V_124 ) ;
} else {
V_158 = V_159 & F_67 ( V_124 ) ;
V_158 >>= F_68 ( V_124 ) ;
switch ( V_158 ) {
case V_161 :
V_158 = 81000 ;
break;
case V_162 :
V_158 = 108000 ;
break;
case V_163 :
V_158 = 135000 ;
break;
case V_164 :
V_158 = 162000 ;
break;
case V_165 :
V_158 = 216000 ;
break;
case V_166 :
V_158 = 270000 ;
break;
default:
F_3 ( 1 , L_8 ) ;
break;
}
V_158 *= 2 ;
}
V_146 -> V_149 = V_158 ;
F_63 ( V_146 ) ;
}
static void F_69 ( struct V_1 * V_6 ,
struct V_100 * V_146 )
{
struct V_17 * V_18 = V_6 -> V_7 . V_31 -> V_65 ;
int V_158 = 0 ;
T_1 V_167 , V_168 ;
V_167 = V_146 -> V_78 ;
switch ( V_167 & V_169 ) {
case V_170 :
V_158 = 81000 ;
break;
case V_171 :
V_158 = 135000 ;
break;
case V_172 :
V_158 = 270000 ;
break;
case V_173 :
V_158 = F_58 ( V_18 , F_70 ( 0 ) ) ;
break;
case V_174 :
V_158 = F_58 ( V_18 , F_70 ( 1 ) ) ;
break;
case V_79 :
V_168 = F_30 ( V_175 ) & V_176 ;
if ( V_168 == V_177 )
V_158 = 81000 ;
else if ( V_168 == V_178 )
V_158 = 135000 ;
else if ( V_168 == V_179 )
V_158 = 270000 ;
else {
F_3 ( 1 , L_9 ) ;
return;
}
break;
default:
F_3 ( 1 , L_10 ) ;
return;
}
V_146 -> V_149 = V_158 * 2 ;
F_63 ( V_146 ) ;
}
static int F_71 ( struct V_17 * V_18 ,
enum V_180 V_124 )
{
struct V_181 * V_168 ;
struct V_182 * V_103 ;
T_4 clock ;
if ( F_20 ( V_124 == V_183 ) )
return 0 ;
V_168 = & V_18 -> V_184 [ V_124 ] ;
V_103 = & V_168 -> V_75 . V_185 ;
clock . V_186 = 2 ;
clock . V_187 = ( V_103 -> V_188 & V_189 ) << 22 ;
if ( V_103 -> V_190 & V_191 )
clock . V_187 |= V_103 -> V_192 & V_193 ;
clock . V_111 = ( V_103 -> V_194 & V_195 ) >> V_196 ;
clock . V_130 = ( V_103 -> V_197 & V_198 ) >> V_199 ;
clock . V_131 = ( V_103 -> V_197 & V_200 ) >> V_201 ;
return F_72 ( 100000 , & clock ) ;
}
static void F_73 ( struct V_1 * V_6 ,
struct V_100 * V_146 )
{
struct V_17 * V_18 = V_6 -> V_7 . V_31 -> V_65 ;
enum V_4 V_4 = F_5 ( V_6 ) ;
T_3 V_124 = V_4 ;
V_146 -> V_149 = F_71 ( V_18 , V_124 ) ;
F_63 ( V_146 ) ;
}
void F_74 ( struct V_1 * V_6 ,
struct V_100 * V_146 )
{
struct V_64 * V_31 = V_6 -> V_7 . V_31 ;
if ( F_75 ( V_31 ) -> V_202 <= 8 )
F_69 ( V_6 , V_146 ) ;
else if ( F_18 ( V_31 ) || F_19 ( V_31 ) )
F_65 ( V_6 , V_146 ) ;
else if ( F_16 ( V_31 ) )
F_73 ( V_6 , V_146 ) ;
}
static bool
F_76 ( struct V_66 * V_66 ,
struct V_100 * V_101 ,
struct V_1 * V_1 )
{
struct V_181 * V_168 ;
V_168 = F_77 ( V_66 , V_101 ,
V_1 ) ;
if ( ! V_168 )
F_78 ( L_11 ,
F_53 ( V_66 -> V_99 ) ) ;
return V_168 ;
}
static bool
F_79 ( struct V_66 * V_66 ,
struct V_100 * V_101 ,
struct V_1 * V_1 )
{
struct V_181 * V_168 ;
V_168 = F_77 ( V_66 , V_101 , V_1 ) ;
if ( V_168 == NULL ) {
F_78 ( L_11 ,
F_53 ( V_66 -> V_99 ) ) ;
return false ;
}
return true ;
}
static bool
F_80 ( struct V_66 * V_66 ,
struct V_100 * V_101 ,
struct V_1 * V_1 )
{
return ! ! F_77 ( V_66 , V_101 , V_1 ) ;
}
bool F_81 ( struct V_66 * V_66 ,
struct V_100 * V_101 )
{
struct V_64 * V_31 = V_66 -> V_7 . V_31 ;
struct V_1 * V_1 =
F_55 ( V_101 ) ;
if ( F_18 ( V_31 ) || F_19 ( V_31 ) )
return F_79 ( V_66 , V_101 ,
V_1 ) ;
else if ( F_16 ( V_31 ) )
return F_80 ( V_66 , V_101 ,
V_1 ) ;
else
return F_76 ( V_66 , V_101 ,
V_1 ) ;
}
void F_82 ( struct V_62 * V_63 )
{
struct V_17 * V_18 = V_63 -> V_31 -> V_65 ;
struct V_66 * V_66 = F_34 ( V_63 ) ;
struct V_1 * V_1 = F_52 ( V_63 ) ;
enum V_203 V_204 = V_66 -> V_75 -> V_204 ;
int type = V_1 -> type ;
T_3 V_67 ;
if ( type == V_10 || type == V_11 || type == V_8 ) {
F_20 ( F_83 ( V_204 ) ) ;
V_67 = V_205 ;
switch ( V_66 -> V_75 -> V_154 ) {
case 18 :
V_67 |= V_206 ;
break;
case 24 :
V_67 |= V_207 ;
break;
case 30 :
V_67 |= V_208 ;
break;
case 36 :
V_67 |= V_209 ;
break;
default:
F_23 () ;
}
F_24 ( F_84 ( V_204 ) , V_67 ) ;
}
}
void F_85 ( struct V_62 * V_63 , bool V_103 )
{
struct V_66 * V_66 = F_34 ( V_63 ) ;
struct V_64 * V_31 = V_63 -> V_31 ;
struct V_17 * V_18 = V_31 -> V_65 ;
enum V_203 V_204 = V_66 -> V_75 -> V_204 ;
T_3 V_67 ;
V_67 = F_30 ( F_86 ( V_204 ) ) ;
if ( V_103 == true )
V_67 |= V_210 ;
else
V_67 &= ~ V_210 ;
F_24 ( F_86 ( V_204 ) , V_67 ) ;
}
void F_87 ( struct V_62 * V_63 )
{
struct V_66 * V_66 = F_34 ( V_63 ) ;
struct V_1 * V_1 = F_52 ( V_63 ) ;
struct V_5 * V_6 = & V_1 -> V_7 ;
struct V_64 * V_31 = V_63 -> V_31 ;
struct V_17 * V_18 = V_31 -> V_65 ;
enum V_99 V_99 = V_66 -> V_99 ;
enum V_203 V_204 = V_66 -> V_75 -> V_204 ;
enum V_4 V_4 = F_5 ( V_1 ) ;
int type = V_1 -> type ;
T_3 V_67 ;
V_67 = V_211 ;
V_67 |= F_88 ( V_4 ) ;
switch ( V_66 -> V_75 -> V_154 ) {
case 18 :
V_67 |= V_212 ;
break;
case 24 :
V_67 |= V_213 ;
break;
case 30 :
V_67 |= V_214 ;
break;
case 36 :
V_67 |= V_215 ;
break;
default:
F_23 () ;
}
if ( V_66 -> V_75 -> V_7 . V_156 . V_216 & V_217 )
V_67 |= V_218 ;
if ( V_66 -> V_75 -> V_7 . V_156 . V_216 & V_219 )
V_67 |= V_220 ;
if ( V_204 == V_221 ) {
switch ( V_99 ) {
case V_69 :
if ( F_22 ( V_31 ) &&
( V_66 -> V_75 -> V_222 . V_223 ||
V_66 -> V_75 -> V_222 . V_224 ) )
V_67 |= V_225 ;
else
V_67 |= V_226 ;
break;
case V_227 :
V_67 |= V_228 ;
break;
case V_229 :
V_67 |= V_230 ;
break;
default:
F_23 () ;
break;
}
}
if ( type == V_12 ) {
if ( V_66 -> V_75 -> V_153 )
V_67 |= V_231 ;
else
V_67 |= V_232 ;
} else if ( type == V_14 ) {
V_67 |= V_233 ;
V_67 |= ( V_66 -> V_75 -> V_76 - 1 ) << 1 ;
} else if ( type == V_10 ||
type == V_11 ) {
struct V_92 * V_92 = F_50 ( V_6 ) ;
if ( V_92 -> V_234 ) {
V_67 |= V_235 ;
} else
V_67 |= V_236 ;
V_67 |= F_51 ( V_66 -> V_75 -> V_96 ) ;
} else if ( type == V_8 ) {
struct V_92 * V_92 = & F_2 ( V_6 ) -> V_9 -> V_237 ;
if ( V_92 -> V_234 ) {
V_67 |= V_235 ;
} else
V_67 |= V_236 ;
V_67 |= F_51 ( V_66 -> V_75 -> V_96 ) ;
} else {
F_3 ( 1 , L_12 ,
V_1 -> type , F_53 ( V_99 ) ) ;
}
F_24 ( F_86 ( V_204 ) , V_67 ) ;
}
void F_89 ( struct V_17 * V_18 ,
enum V_203 V_204 )
{
T_2 V_60 = F_86 ( V_204 ) ;
T_3 V_167 = F_30 ( V_60 ) ;
V_167 &= ~ ( V_211 | V_238 | V_210 ) ;
V_167 |= V_239 ;
F_24 ( V_60 , V_167 ) ;
}
bool F_90 ( struct V_240 * V_240 )
{
struct V_64 * V_31 = V_240 -> V_7 . V_31 ;
struct V_17 * V_18 = V_31 -> V_65 ;
struct V_1 * V_1 = V_240 -> V_6 ;
int type = V_240 -> V_7 . V_241 ;
enum V_4 V_4 = F_5 ( V_1 ) ;
enum V_99 V_99 = 0 ;
enum V_203 V_204 ;
enum V_242 V_243 ;
T_3 V_244 ;
bool V_97 ;
V_243 = F_91 ( V_1 ) ;
if ( ! F_92 ( V_18 , V_243 ) )
return false ;
if ( ! V_1 -> V_245 ( V_1 , & V_99 ) ) {
V_97 = false ;
goto V_246;
}
if ( V_4 == V_49 )
V_204 = V_221 ;
else
V_204 = (enum V_203 ) V_99 ;
V_244 = F_30 ( F_86 ( V_204 ) ) ;
switch ( V_244 & V_247 ) {
case V_231 :
case V_232 :
V_97 = type == V_248 ;
break;
case V_236 :
V_97 = type == V_249 ||
type == V_250 ;
break;
case V_235 :
V_97 = false ;
break;
case V_233 :
V_97 = type == V_251 ;
break;
default:
V_97 = false ;
break;
}
V_246:
F_93 ( V_18 , V_243 ) ;
return V_97 ;
}
bool F_94 ( struct V_1 * V_6 ,
enum V_99 * V_99 )
{
struct V_64 * V_31 = V_6 -> V_7 . V_31 ;
struct V_17 * V_18 = V_31 -> V_65 ;
enum V_4 V_4 = F_5 ( V_6 ) ;
enum V_242 V_243 ;
T_1 V_244 ;
int V_33 ;
bool V_97 ;
V_243 = F_91 ( V_6 ) ;
if ( ! F_92 ( V_18 , V_243 ) )
return false ;
V_97 = false ;
V_244 = F_30 ( F_28 ( V_4 ) ) ;
if ( ! ( V_244 & V_84 ) )
goto V_246;
if ( V_4 == V_49 ) {
V_244 = F_30 ( F_86 ( V_221 ) ) ;
switch ( V_244 & V_252 ) {
case V_226 :
case V_225 :
* V_99 = V_69 ;
break;
case V_228 :
* V_99 = V_227 ;
break;
case V_230 :
* V_99 = V_229 ;
break;
}
V_97 = true ;
goto V_246;
}
for ( V_33 = V_253 ; V_33 <= V_254 ; V_33 ++ ) {
V_244 = F_30 ( F_86 ( V_33 ) ) ;
if ( ( V_244 & V_238 ) == F_88 ( V_4 ) ) {
if ( ( V_244 & V_247 ) ==
V_235 )
goto V_246;
* V_99 = V_33 ;
V_97 = true ;
goto V_246;
}
}
F_48 ( L_13 , F_32 ( V_4 ) ) ;
V_246:
F_93 ( V_18 , V_243 ) ;
return V_97 ;
}
void F_95 ( struct V_66 * V_66 )
{
struct V_62 * V_63 = & V_66 -> V_7 ;
struct V_64 * V_31 = V_63 -> V_31 ;
struct V_17 * V_18 = V_31 -> V_65 ;
struct V_1 * V_1 = F_52 ( V_63 ) ;
enum V_4 V_4 = F_5 ( V_1 ) ;
enum V_203 V_204 = V_66 -> V_75 -> V_204 ;
if ( V_204 != V_221 )
F_24 ( F_96 ( V_204 ) ,
F_97 ( V_4 ) ) ;
}
void F_98 ( struct V_66 * V_66 )
{
struct V_17 * V_18 = V_66 -> V_7 . V_31 -> V_65 ;
enum V_203 V_204 = V_66 -> V_75 -> V_204 ;
if ( V_204 != V_221 )
F_24 ( F_96 ( V_204 ) ,
V_255 ) ;
}
static void F_99 ( struct V_17 * V_18 ,
T_1 V_256 , enum V_4 V_4 , int type )
{
const struct V_16 * V_44 ;
T_5 V_257 ;
T_5 V_258 , V_259 ;
int V_19 ;
T_1 V_60 ;
V_258 = V_18 -> V_23 . V_45 [ V_4 ] . V_48 ;
V_259 = V_18 -> V_23 . V_45 [ V_4 ] . V_47 ;
if ( type == V_10 ) {
if ( V_258 ) {
V_257 = V_258 ;
} else {
V_44 = F_6 ( V_18 , & V_19 ) ;
V_257 = V_44 [ V_256 ] . V_260 ;
}
} else if ( type == V_11 ) {
if ( V_258 ) {
V_257 = V_258 ;
} else {
V_44 = F_12 ( V_18 , & V_19 ) ;
if ( F_20 ( V_4 != V_49 &&
V_4 != V_15 && V_19 > 9 ) )
V_19 = 9 ;
V_257 = V_44 [ V_256 ] . V_260 ;
}
} else if ( type == V_12 ) {
if ( V_259 ) {
V_257 = V_259 ;
} else {
V_44 = F_13 ( V_18 , & V_19 ) ;
V_257 = V_44 [ V_256 ] . V_260 ;
}
} else {
return;
}
if ( V_257 && V_257 != 0x1 && V_257 != 0x3 && V_257 != 0x7 ) {
F_31 ( L_14 , V_257 ) ;
return;
}
V_60 = F_30 ( V_261 ) ;
V_60 &= ~ F_100 ( V_4 ) ;
V_60 &= ~ ( 1 << ( V_262 + V_4 ) ) ;
if ( V_257 )
V_60 |= V_257 << F_101 ( V_4 ) ;
else
V_60 |= 1 << ( V_262 + V_4 ) ;
F_24 ( V_261 , V_60 ) ;
}
static void F_17 ( struct V_17 * V_18 ,
T_1 V_256 , enum V_4 V_4 , int type )
{
const struct V_263 * V_44 ;
T_1 V_19 , V_33 ;
T_3 V_167 ;
if ( type == V_11 && V_18 -> V_23 . V_24 . V_25 ) {
V_19 = F_9 ( V_264 ) ;
V_44 = V_264 ;
} else if ( type == V_10
|| type == V_11 ) {
V_19 = F_9 ( V_265 ) ;
V_44 = V_265 ;
} else if ( type == V_12 ) {
V_19 = F_9 ( V_266 ) ;
V_44 = V_266 ;
} else {
F_48 ( L_15 ,
type ) ;
return;
}
if ( V_256 >= V_19 ||
( type == V_12 && V_256 == V_59 ) ) {
for ( V_33 = 0 ; V_33 < V_19 ; V_33 ++ ) {
if ( V_44 [ V_33 ] . V_267 ) {
V_256 = V_33 ;
break;
}
}
}
V_167 = F_30 ( F_102 ( V_4 ) ) ;
V_167 &= ~ ( V_268 | V_269 ) ;
F_24 ( F_103 ( V_4 ) , V_167 ) ;
V_167 = F_30 ( F_104 ( V_4 ) ) ;
V_167 &= ~ ( V_270 | V_271 ) ;
V_167 |= V_44 [ V_256 ] . V_272 << V_273 |
V_44 [ V_256 ] . V_274 << V_275 ;
F_24 ( F_105 ( V_4 ) , V_167 ) ;
V_167 = F_30 ( F_106 ( V_4 ) ) ;
V_167 &= ~ V_276 ;
if ( V_44 [ V_256 ] . V_277 )
V_167 |= V_276 ;
if ( ( V_167 & V_278 ) && ! ( V_167 & V_276 ) )
F_31 ( L_16 ) ;
F_24 ( F_107 ( V_4 ) , V_167 ) ;
V_167 = F_30 ( F_108 ( V_4 ) ) ;
V_167 &= ~ V_279 ;
V_167 |= V_44 [ V_256 ] . V_280 << V_281 ;
F_24 ( F_109 ( V_4 ) , V_167 ) ;
V_167 = F_30 ( F_102 ( V_4 ) ) ;
V_167 |= V_268 | V_269 ;
F_24 ( F_103 ( V_4 ) , V_167 ) ;
}
static T_3 F_110 ( int V_282 )
{
T_3 V_256 ;
switch ( V_282 ) {
default:
F_48 ( L_17 ,
V_282 ) ;
case V_283 | V_284 :
V_256 = 0 ;
break;
case V_283 | V_285 :
V_256 = 1 ;
break;
case V_283 | V_286 :
V_256 = 2 ;
break;
case V_283 | V_287 :
V_256 = 3 ;
break;
case V_288 | V_284 :
V_256 = 4 ;
break;
case V_288 | V_285 :
V_256 = 5 ;
break;
case V_288 | V_286 :
V_256 = 6 ;
break;
case V_289 | V_284 :
V_256 = 7 ;
break;
case V_289 | V_285 :
V_256 = 8 ;
break;
case V_290 | V_284 :
V_256 = 9 ;
break;
}
return V_256 ;
}
T_3 F_111 ( struct V_92 * V_92 )
{
struct V_2 * V_291 = F_112 ( V_92 ) ;
struct V_17 * V_18 = F_15 ( V_291 -> V_7 . V_7 . V_31 ) ;
struct V_1 * V_6 = & V_291 -> V_7 ;
T_5 V_292 = V_92 -> V_292 [ 0 ] ;
int V_282 = V_292 & ( V_293 |
V_294 ) ;
enum V_4 V_4 = V_291 -> V_4 ;
T_3 V_256 ;
V_256 = F_110 ( V_282 ) ;
if ( F_18 ( V_18 ) || F_19 ( V_18 ) )
F_99 ( V_18 , V_256 , V_4 , V_6 -> type ) ;
else if ( F_16 ( V_18 ) )
F_17 ( V_18 , V_256 , V_4 , V_6 -> type ) ;
return F_44 ( V_256 ) ;
}
void F_113 ( struct V_1 * V_6 ,
const struct V_100 * V_146 )
{
struct V_17 * V_18 = F_15 ( V_6 -> V_7 . V_31 ) ;
enum V_4 V_4 = F_5 ( V_6 ) ;
if ( F_18 ( V_18 ) || F_19 ( V_18 ) ) {
T_3 V_124 = V_146 -> V_78 ;
T_3 V_167 ;
V_167 = F_30 ( V_295 ) ;
V_167 &= ~ ( F_114 ( V_4 ) |
F_115 ( V_4 ) ) ;
V_167 |= ( F_116 ( V_124 , V_4 ) |
F_117 ( V_4 ) ) ;
F_24 ( V_295 , V_167 ) ;
} else if ( F_75 ( V_18 ) -> V_202 < 9 ) {
F_20 ( V_146 -> V_78 == V_296 ) ;
F_24 ( F_42 ( V_4 ) , V_146 -> V_78 ) ;
}
}
static void F_118 ( struct V_1 * V_1 )
{
struct V_5 * V_6 = & V_1 -> V_7 ;
struct V_17 * V_18 = F_15 ( V_6 -> V_31 ) ;
struct V_66 * V_63 = F_34 ( V_6 -> V_63 ) ;
enum V_4 V_4 = F_5 ( V_1 ) ;
int type = V_1 -> type ;
if ( type == V_12 ) {
struct V_297 * V_297 = F_119 ( V_6 ) ;
F_120 ( V_297 , true ) ;
}
F_14 ( V_1 ) ;
if ( type == V_11 ) {
struct V_92 * V_92 = F_50 ( V_6 ) ;
F_121 ( V_92 ) ;
}
F_113 ( V_1 , V_63 -> V_75 ) ;
if ( type == V_10 || type == V_11 ) {
struct V_92 * V_92 = F_50 ( V_6 ) ;
F_122 ( V_92 , V_63 -> V_75 ) ;
F_49 ( V_1 ) ;
F_123 ( V_92 , V_298 ) ;
F_124 ( V_92 ) ;
if ( V_4 != V_49 || F_75 ( V_18 ) -> V_202 >= 9 )
F_125 ( V_92 ) ;
} else if ( type == V_12 ) {
struct V_297 * V_297 = F_119 ( V_6 ) ;
V_297 -> V_299 ( V_6 ,
V_63 -> V_75 -> V_153 ,
& V_63 -> V_75 -> V_7 . V_156 ) ;
}
}
static void F_126 ( struct V_1 * V_1 )
{
struct V_5 * V_6 = & V_1 -> V_7 ;
struct V_64 * V_31 = V_6 -> V_31 ;
struct V_17 * V_18 = V_31 -> V_65 ;
enum V_4 V_4 = F_5 ( V_1 ) ;
int type = V_1 -> type ;
T_3 V_167 ;
bool V_300 = false ;
V_167 = F_30 ( F_28 ( V_4 ) ) ;
if ( V_167 & V_84 ) {
V_167 &= ~ V_84 ;
F_24 ( F_28 ( V_4 ) , V_167 ) ;
V_300 = true ;
}
V_167 = F_30 ( F_43 ( V_4 ) ) ;
V_167 &= ~ ( V_83 | V_90 ) ;
V_167 |= V_82 ;
F_24 ( F_43 ( V_4 ) , V_167 ) ;
if ( V_300 )
F_27 ( V_18 , V_4 ) ;
if ( type == V_10 || type == V_11 ) {
struct V_92 * V_92 = F_50 ( V_6 ) ;
F_123 ( V_92 , V_301 ) ;
F_127 ( V_92 ) ;
F_128 ( V_92 ) ;
}
if ( F_18 ( V_31 ) || F_19 ( V_31 ) )
F_24 ( V_295 , ( F_30 ( V_295 ) |
F_114 ( V_4 ) ) ) ;
else if ( F_75 ( V_31 ) -> V_202 < 9 )
F_24 ( F_42 ( V_4 ) , V_296 ) ;
if ( type == V_12 ) {
struct V_297 * V_297 = F_119 ( V_6 ) ;
F_120 ( V_297 , false ) ;
}
}
static void F_129 ( struct V_1 * V_1 )
{
struct V_5 * V_6 = & V_1 -> V_7 ;
struct V_62 * V_63 = V_6 -> V_63 ;
struct V_66 * V_66 = F_34 ( V_63 ) ;
struct V_64 * V_31 = V_6 -> V_31 ;
struct V_17 * V_18 = V_31 -> V_65 ;
enum V_4 V_4 = F_5 ( V_1 ) ;
int type = V_1 -> type ;
if ( type == V_12 ) {
struct V_2 * V_93 =
F_4 ( V_6 ) ;
F_24 ( F_28 ( V_4 ) ,
V_93 -> V_95 |
V_84 ) ;
} else if ( type == V_11 ) {
struct V_92 * V_92 = F_50 ( V_6 ) ;
if ( V_4 == V_49 && F_75 ( V_31 ) -> V_202 < 9 )
F_125 ( V_92 ) ;
F_130 ( V_92 ) ;
F_131 ( V_92 ) ;
F_132 ( V_92 ) ;
}
if ( V_66 -> V_75 -> V_302 ) {
F_133 ( V_18 , V_303 ) ;
F_134 ( V_1 ) ;
}
}
static void F_135 ( struct V_1 * V_1 )
{
struct V_5 * V_6 = & V_1 -> V_7 ;
struct V_62 * V_63 = V_6 -> V_63 ;
struct V_66 * V_66 = F_34 ( V_63 ) ;
int type = V_1 -> type ;
struct V_64 * V_31 = V_6 -> V_31 ;
struct V_17 * V_18 = V_31 -> V_65 ;
if ( V_66 -> V_75 -> V_302 ) {
F_136 ( V_1 ) ;
F_93 ( V_18 , V_303 ) ;
}
if ( type == V_11 ) {
struct V_92 * V_92 = F_50 ( V_6 ) ;
F_137 ( V_92 ) ;
F_138 ( V_92 ) ;
F_139 ( V_92 ) ;
}
}
static bool F_140 ( struct V_17 * V_18 ,
enum V_304 V_305 )
{
if ( ! ( F_30 ( V_306 ) & F_141 ( V_305 ) ) )
return false ;
if ( ( F_30 ( F_142 ( V_305 ) ) &
( V_307 | V_308 ) ) != V_307 ) {
F_78 ( L_18 ,
V_305 ) ;
return false ;
}
if ( V_305 == V_309 &&
! ( F_30 ( F_143 ( V_309 ) ) & V_310 ) ) {
F_78 ( L_19 ) ;
return false ;
}
if ( ! ( F_30 ( F_144 ( V_305 ) ) & V_311 ) ) {
F_78 ( L_20 ,
V_305 ) ;
return false ;
}
return true ;
}
static T_1 F_145 ( struct V_17 * V_18 , enum V_304 V_305 )
{
T_1 V_167 = F_30 ( F_146 ( V_305 ) ) ;
return ( V_167 & V_312 ) >> V_313 ;
}
static void F_147 ( struct V_17 * V_18 ,
enum V_304 V_305 )
{
if ( F_148 ( F_30 ( F_143 ( V_305 ) ) & V_310 , 10 ) )
F_31 ( L_21 , V_305 ) ;
}
static void F_149 ( struct V_17 * V_18 ,
enum V_304 V_305 )
{
enum V_4 V_4 ;
T_1 V_314 , V_167 ;
if ( F_140 ( V_18 , V_305 ) ) {
if ( V_305 == V_315 )
V_18 -> V_316 = F_145 ( V_18 , V_305 ) ;
if ( F_150 ( V_18 , V_305 ) ) {
F_78 ( L_22
L_23 , V_305 ) ;
return;
}
F_78 ( L_24
L_25 , V_305 ) ;
} else {
F_78 ( L_26 , V_305 ) ;
}
V_167 = F_30 ( V_306 ) ;
V_167 |= F_141 ( V_305 ) ;
F_24 ( V_306 , V_167 ) ;
if ( F_151 ( ( ( F_30 ( F_142 ( V_305 ) ) &
( V_308 | V_307 ) ) == V_307 ) , 100 ) ) {
F_31 ( L_27 , V_305 ) ;
}
if ( V_305 == V_315 )
V_314 = F_152 ( V_317 ) | F_152 ( V_318 ) ;
else
V_314 = F_152 ( V_49 ) ;
F_153 (port, ports) {
int V_319 ;
for ( V_319 = 0 ; V_319 < 4 ; V_319 ++ ) {
V_167 = F_30 ( F_154 ( V_4 , V_319 ) ) ;
V_167 &= ~ V_320 ;
if ( V_319 != 1 )
V_167 |= V_320 ;
F_24 ( F_154 ( V_4 , V_319 ) , V_167 ) ;
}
}
V_167 = F_30 ( F_155 ( V_305 ) ) ;
V_167 &= ~ V_321 ;
V_167 |= 0xE4 << V_322 ;
F_24 ( F_155 ( V_305 ) , V_167 ) ;
V_167 = F_30 ( F_156 ( V_305 ) ) ;
V_167 &= ~ V_323 ;
V_167 |= 0xE4 << V_324 ;
F_24 ( F_156 ( V_305 ) , V_167 ) ;
V_167 = F_30 ( F_157 ( V_305 ) ) ;
V_167 |= V_325 | V_326 |
V_327 ;
F_24 ( F_157 ( V_305 ) , V_167 ) ;
if ( V_305 == V_315 ) {
V_167 = F_30 ( V_328 ) ;
V_167 |= V_329 ;
F_24 ( V_328 , V_167 ) ;
}
V_167 = F_30 ( F_158 ( V_305 ) ) ;
V_167 &= ~ V_330 ;
if ( V_305 == V_309 )
V_167 |= V_330 ;
F_24 ( F_158 ( V_305 ) , V_167 ) ;
if ( V_305 == V_315 ) {
T_3 V_331 ;
F_147 ( V_18 , V_309 ) ;
V_167 = V_18 -> V_316 = F_145 ( V_18 ,
V_309 ) ;
V_331 = V_167 << V_332 |
V_167 << V_333 |
V_167 ;
F_24 ( F_146 ( V_315 ) , V_331 ) ;
V_167 = F_30 ( F_159 ( V_315 ) ) ;
V_167 |= V_334 | V_335 ;
F_24 ( F_159 ( V_315 ) , V_167 ) ;
}
V_167 = F_30 ( F_144 ( V_305 ) ) ;
V_167 |= V_311 ;
F_24 ( F_144 ( V_305 ) , V_167 ) ;
}
void F_160 ( struct V_17 * V_18 )
{
F_149 ( V_18 , V_309 ) ;
F_149 ( V_18 , V_315 ) ;
F_147 ( V_18 , V_309 ) ;
}
static void F_161 ( struct V_17 * V_18 ,
enum V_304 V_305 )
{
T_3 V_167 ;
V_167 = F_30 ( F_144 ( V_305 ) ) ;
V_167 &= ~ V_311 ;
F_24 ( F_144 ( V_305 ) , V_167 ) ;
V_167 = F_30 ( V_306 ) ;
V_167 &= ~ F_141 ( V_305 ) ;
F_24 ( V_306 , V_167 ) ;
}
void F_162 ( struct V_17 * V_18 )
{
F_161 ( V_18 , V_309 ) ;
F_161 ( V_18 , V_315 ) ;
}
static bool F_150 ( struct V_17 * V_18 ,
enum V_304 V_305 )
{
enum V_4 V_4 ;
T_1 V_314 ;
T_3 V_336 ;
bool V_337 ;
#define F_163 ( V_60 , V_336 , exp , T_6 , ... ) \
__phy_reg_verify_state(dev_priv, phy, reg, mask, exp, fmt, \
## __VA_ARGS__)
if ( ! F_140 ( V_18 , V_305 ) )
return false ;
V_337 = true ;
if ( V_305 == V_315 )
V_314 = F_152 ( V_317 ) | F_152 ( V_318 ) ;
else
V_314 = F_152 ( V_49 ) ;
F_153 (port, ports) {
int V_319 ;
for ( V_319 = 0 ; V_319 < 4 ; V_319 ++ )
V_337 &= F_163 ( F_154 ( V_4 , V_319 ) ,
V_320 ,
V_319 != 1 ? V_320 : 0 ,
L_28 , V_4 , V_319 ) ;
}
V_337 &= F_163 ( F_155 ( V_305 ) ,
V_321 , 0xe4 << V_322 ,
L_29 , V_305 ) ;
V_337 &= F_163 ( F_156 ( V_305 ) ,
V_323 , 0xe4 << V_324 ,
L_30 , V_305 ) ;
V_336 = V_325 | V_326 | V_327 ;
V_337 &= F_163 ( F_157 ( V_305 ) , V_336 , V_336 ,
L_31 , V_305 ) ;
if ( V_305 == V_315 )
V_337 &= F_163 ( V_328 ,
V_329 , V_329 ,
L_32 ) ;
if ( V_305 == V_315 ) {
T_1 V_331 = V_18 -> V_316 ;
V_331 = V_331 << V_332 |
V_331 << V_333 |
V_331 ;
V_336 = V_338 | V_339 |
V_340 ;
V_337 &= F_163 ( F_146 ( V_315 ) , V_336 , V_331 ,
L_33 , V_315 ) ;
V_336 = V_334 | V_335 ;
V_337 &= F_163 ( F_159 ( V_315 ) , V_336 , V_336 ,
L_34 , V_315 ) ;
}
return V_337 ;
#undef F_163
}
void F_164 ( struct V_17 * V_18 )
{
if ( ! F_150 ( V_18 , V_315 ) ||
! F_150 ( V_18 , V_309 ) )
F_165 ( V_18 , L_35 ) ;
}
void F_166 ( struct V_92 * V_92 )
{
struct V_2 * V_93 = F_112 ( V_92 ) ;
struct V_17 * V_18 =
F_15 ( V_93 -> V_7 . V_7 . V_31 ) ;
enum V_4 V_4 = V_93 -> V_4 ;
T_3 V_167 ;
bool V_300 = false ;
if ( F_30 ( F_43 ( V_4 ) ) & V_83 ) {
V_167 = F_30 ( F_28 ( V_4 ) ) ;
if ( V_167 & V_84 ) {
V_167 &= ~ V_84 ;
F_24 ( F_28 ( V_4 ) , V_167 ) ;
V_300 = true ;
}
V_167 = F_30 ( F_43 ( V_4 ) ) ;
V_167 &= ~ ( V_83 | V_90 ) ;
V_167 |= V_82 ;
F_24 ( F_43 ( V_4 ) , V_167 ) ;
F_41 ( F_43 ( V_4 ) ) ;
if ( V_300 )
F_27 ( V_18 , V_4 ) ;
}
V_167 = V_83 |
V_82 | V_341 ;
if ( V_92 -> V_234 )
V_167 |= V_342 ;
else {
V_167 |= V_343 ;
if ( F_167 ( V_92 -> V_344 ) )
V_167 |= V_81 ;
}
F_24 ( F_43 ( V_4 ) , V_167 ) ;
F_41 ( F_43 ( V_4 ) ) ;
V_92 -> V_94 |= V_84 ;
F_24 ( F_28 ( V_4 ) , V_92 -> V_94 ) ;
F_41 ( F_28 ( V_4 ) ) ;
F_29 ( 600 ) ;
}
void F_168 ( struct V_62 * V_63 )
{
struct V_17 * V_18 = V_63 -> V_31 -> V_65 ;
struct V_1 * V_1 = F_52 ( V_63 ) ;
T_3 V_167 ;
V_167 = F_30 ( F_40 ( V_69 ) ) ;
V_167 &= ~ V_85 ;
F_24 ( F_40 ( V_69 ) , V_167 ) ;
F_126 ( V_1 ) ;
V_167 = F_30 ( F_36 ( V_69 ) ) ;
V_167 &= ~ ( V_87 | V_88 ) ;
V_167 |= F_37 ( 2 ) | F_38 ( 2 ) ;
F_24 ( F_36 ( V_69 ) , V_167 ) ;
V_167 = F_30 ( F_40 ( V_69 ) ) ;
V_167 &= ~ V_77 ;
F_24 ( F_40 ( V_69 ) , V_167 ) ;
V_167 = F_30 ( F_40 ( V_69 ) ) ;
V_167 &= ~ V_74 ;
F_24 ( F_40 ( V_69 ) , V_167 ) ;
}
void F_169 ( struct V_1 * V_6 ,
struct V_100 * V_146 )
{
struct V_17 * V_18 = V_6 -> V_7 . V_31 -> V_65 ;
struct V_66 * V_66 = F_34 ( V_6 -> V_7 . V_63 ) ;
enum V_203 V_204 = V_146 -> V_204 ;
struct V_297 * V_297 ;
T_1 V_67 , V_216 = 0 ;
if ( F_20 ( F_83 ( V_204 ) ) )
return;
V_67 = F_30 ( F_86 ( V_204 ) ) ;
if ( V_67 & V_220 )
V_216 |= V_219 ;
else
V_216 |= V_345 ;
if ( V_67 & V_218 )
V_216 |= V_217 ;
else
V_216 |= V_346 ;
V_146 -> V_7 . V_156 . V_216 |= V_216 ;
switch ( V_67 & V_347 ) {
case V_212 :
V_146 -> V_154 = 18 ;
break;
case V_213 :
V_146 -> V_154 = 24 ;
break;
case V_214 :
V_146 -> V_154 = 30 ;
break;
case V_215 :
V_146 -> V_154 = 36 ;
break;
default:
break;
}
switch ( V_67 & V_247 ) {
case V_231 :
V_146 -> V_153 = true ;
V_297 = F_119 ( & V_6 -> V_7 ) ;
if ( V_297 -> V_348 ( & V_6 -> V_7 , V_146 ) )
V_146 -> V_349 = true ;
case V_232 :
V_146 -> V_96 = 4 ;
break;
case V_233 :
break;
case V_236 :
case V_235 :
V_146 -> V_151 = true ;
V_146 -> V_96 =
( ( V_67 & V_350 ) >> V_351 ) + 1 ;
F_170 ( V_66 , V_146 ) ;
break;
default:
break;
}
if ( F_171 ( V_18 , V_303 ) ) {
V_67 = F_30 ( V_352 ) ;
if ( V_67 & F_172 ( V_66 -> V_99 ) )
V_146 -> V_302 = true ;
}
if ( V_6 -> type == V_11 && V_18 -> V_23 . V_24 . V_353 &&
V_146 -> V_154 > V_18 -> V_23 . V_24 . V_353 ) {
F_48 ( L_36 ,
V_146 -> V_154 , V_18 -> V_23 . V_24 . V_353 ) ;
V_18 -> V_23 . V_24 . V_353 = V_146 -> V_154 ;
}
F_74 ( V_6 , V_146 ) ;
}
static bool F_173 ( struct V_1 * V_6 ,
struct V_100 * V_146 )
{
int type = V_6 -> type ;
int V_4 = F_5 ( V_6 ) ;
F_3 ( type == V_13 , L_37 ) ;
if ( V_4 == V_49 )
V_146 -> V_204 = V_221 ;
if ( type == V_12 )
return F_174 ( V_6 , V_146 ) ;
else
return F_175 ( V_6 , V_146 ) ;
}
static struct V_240 *
F_176 ( struct V_2 * V_93 )
{
struct V_240 * V_105 ;
enum V_4 V_4 = V_93 -> V_4 ;
V_105 = F_177 () ;
if ( ! V_105 )
return NULL ;
V_93 -> V_237 . V_354 = F_28 ( V_4 ) ;
if ( ! F_178 ( V_93 , V_105 ) ) {
F_179 ( V_105 ) ;
return NULL ;
}
return V_105 ;
}
static struct V_240 *
F_180 ( struct V_2 * V_93 )
{
struct V_240 * V_105 ;
enum V_4 V_4 = V_93 -> V_4 ;
V_105 = F_177 () ;
if ( ! V_105 )
return NULL ;
V_93 -> V_355 . V_356 = F_28 ( V_4 ) ;
F_181 ( V_93 , V_105 ) ;
return V_105 ;
}
void F_182 ( struct V_64 * V_31 , enum V_4 V_4 )
{
struct V_17 * V_18 = V_31 -> V_65 ;
struct V_2 * V_93 ;
struct V_1 * V_1 ;
struct V_5 * V_6 ;
bool V_357 , V_358 ;
int V_359 ;
if ( F_30 ( F_28 ( V_49 ) ) & V_360 ) {
switch ( V_4 ) {
case V_49 :
V_359 = 4 ;
break;
case V_15 :
V_359 = 0 ;
break;
default:
V_359 = 4 ;
break;
}
} else {
switch ( V_4 ) {
case V_49 :
V_359 = 2 ;
break;
case V_15 :
V_359 = 2 ;
break;
default:
V_359 = 4 ;
break;
}
}
V_357 = ( V_18 -> V_23 . V_45 [ V_4 ] . V_361 ||
V_18 -> V_23 . V_45 [ V_4 ] . V_362 ) ;
V_358 = V_18 -> V_23 . V_45 [ V_4 ] . V_363 ;
if ( ! V_358 && ! V_357 ) {
F_48 ( L_38 ,
F_32 ( V_4 ) ) ;
return;
}
V_93 = F_183 ( sizeof( * V_93 ) , V_364 ) ;
if ( ! V_93 )
return;
V_1 = & V_93 -> V_7 ;
V_6 = & V_1 -> V_7 ;
F_184 ( V_31 , V_6 , & V_365 ,
V_366 , NULL ) ;
V_1 -> V_367 = F_173 ;
V_1 -> V_277 = F_129 ;
V_1 -> V_368 = F_118 ;
V_1 -> V_369 = F_135 ;
V_1 -> V_370 = F_126 ;
V_1 -> V_245 = F_94 ;
V_1 -> V_371 = F_169 ;
V_1 -> V_372 = V_373 ;
V_93 -> V_4 = V_4 ;
V_93 -> V_95 = F_30 ( F_28 ( V_4 ) ) &
( V_374 |
V_360 ) ;
if ( F_16 ( V_31 ) && V_4 == V_49 ) {
if ( ! ( V_93 -> V_95 & V_360 ) ) {
F_48 ( L_39 ) ;
V_93 -> V_95 |= V_360 ;
V_359 = 4 ;
}
}
V_93 -> V_359 = V_359 ;
V_1 -> type = V_13 ;
V_1 -> V_375 = ( 1 << 0 ) | ( 1 << 1 ) | ( 1 << 2 ) ;
V_1 -> V_376 = 0 ;
if ( V_358 ) {
if ( ! F_176 ( V_93 ) )
goto V_377;
V_93 -> V_378 = V_379 ;
if ( F_185 ( V_31 , 0 , V_380 ) && V_4 == V_317 )
V_18 -> V_381 . V_382 [ V_49 ] = V_93 ;
else
V_18 -> V_381 . V_382 [ V_4 ] = V_93 ;
}
if ( V_1 -> type != V_11 && V_357 ) {
if ( ! F_180 ( V_93 ) )
goto V_377;
}
return;
V_377:
F_186 ( V_6 ) ;
F_179 ( V_93 ) ;
}
