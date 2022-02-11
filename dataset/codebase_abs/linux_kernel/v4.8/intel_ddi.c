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
static int F_14 ( struct V_17 * V_18 , enum V_4 V_4 )
{
int V_31 ;
int V_32 ;
int V_33 ;
V_32 = V_18 -> V_23 . V_34 [ V_4 ] . V_35 ;
if ( F_15 ( V_18 ) )
return V_32 ;
if ( F_16 ( V_18 ) || F_17 ( V_18 ) ) {
F_13 ( V_18 , & V_31 ) ;
V_33 = 8 ;
} else if ( F_18 ( V_18 ) ) {
V_31 = F_9 ( V_36 ) ;
V_33 = 7 ;
} else if ( F_19 ( V_18 ) ) {
V_31 = F_9 ( V_37 ) ;
V_33 = 6 ;
} else {
F_3 ( 1 , L_2 ) ;
V_31 = F_9 ( V_36 ) ;
V_33 = 7 ;
}
if ( V_32 == V_38 ||
V_32 >= V_31 )
V_32 = V_33 ;
return V_32 ;
}
void F_20 ( struct V_1 * V_6 )
{
struct V_17 * V_18 = F_21 ( V_6 -> V_7 . V_39 ) ;
T_1 V_40 = 0 ;
int V_41 , V_31 , V_42 , V_43 ,
V_44 ;
int V_32 ;
enum V_4 V_4 ;
const struct V_16 * V_45 ;
const struct V_16 * V_46 ;
const struct V_16 * V_47 ;
const struct V_16 * V_48 ;
const struct V_16 * V_49 ;
V_4 = F_5 ( V_6 ) ;
V_32 = F_14 ( V_18 , V_4 ) ;
if ( F_15 ( V_18 ) ) {
if ( V_6 -> type != V_12 )
return;
F_22 ( V_18 , V_32 , V_4 ,
V_12 ) ;
return;
}
if ( F_16 ( V_18 ) || F_17 ( V_18 ) ) {
V_45 = NULL ;
V_46 =
F_6 ( V_18 , & V_42 ) ;
V_47 =
F_12 ( V_18 , & V_43 ) ;
V_48 =
F_13 ( V_18 , & V_31 ) ;
if ( V_18 -> V_23 . V_34 [ V_4 ] . V_50 ||
V_18 -> V_23 . V_34 [ V_4 ] . V_51 )
V_40 = 1 << 31 ;
if ( F_23 ( V_6 -> type == V_11 &&
V_4 != V_52 && V_4 != V_15 &&
V_43 > 9 ) )
V_43 = 9 ;
} else if ( F_18 ( V_18 ) ) {
V_45 = V_53 ;
V_46 = V_54 ;
if ( V_18 -> V_23 . V_24 . V_25 ) {
V_47 = V_55 ;
V_43 = F_9 ( V_55 ) ;
} else {
V_47 = V_54 ;
V_43 = F_9 ( V_54 ) ;
}
V_48 = V_36 ;
V_42 = F_9 ( V_54 ) ;
V_31 = F_9 ( V_36 ) ;
} else if ( F_19 ( V_18 ) ) {
V_45 = V_56 ;
V_46 = V_57 ;
V_47 = V_57 ;
V_48 = V_37 ;
V_42 = V_43 = F_9 ( V_57 ) ;
V_31 = F_9 ( V_37 ) ;
} else {
F_3 ( 1 , L_2 ) ;
V_47 = V_54 ;
V_45 = V_53 ;
V_46 = V_54 ;
V_48 = V_36 ;
V_43 = F_9 ( V_55 ) ;
V_42 = F_9 ( V_54 ) ;
V_31 = F_9 ( V_36 ) ;
}
switch ( V_6 -> type ) {
case V_11 :
V_49 = V_47 ;
V_44 = V_43 ;
break;
case V_10 :
case V_12 :
V_49 = V_46 ;
V_44 = V_42 ;
break;
case V_14 :
V_49 = V_45 ;
V_44 = V_42 ;
break;
default:
F_24 () ;
}
for ( V_41 = 0 ; V_41 < V_44 ; V_41 ++ ) {
F_25 ( F_26 ( V_4 , V_41 ) ,
V_49 [ V_41 ] . V_58 | V_40 ) ;
F_25 ( F_27 ( V_4 , V_41 ) ,
V_49 [ V_41 ] . V_59 ) ;
}
if ( V_6 -> type != V_12 )
return;
F_25 ( F_26 ( V_4 , V_41 ) ,
V_48 [ V_32 ] . V_58 | V_40 ) ;
F_25 ( F_27 ( V_4 , V_41 ) ,
V_48 [ V_32 ] . V_59 ) ;
}
static void F_28 ( struct V_17 * V_18 ,
enum V_4 V_4 )
{
T_2 V_60 = F_29 ( V_4 ) ;
int V_41 ;
for ( V_41 = 0 ; V_41 < 16 ; V_41 ++ ) {
F_30 ( 1 ) ;
if ( F_31 ( V_60 ) & V_61 )
return;
}
F_32 ( L_3 , F_33 ( V_4 ) ) ;
}
void F_34 ( struct V_62 * V_63 )
{
struct V_64 * V_39 = V_63 -> V_39 ;
struct V_17 * V_18 = F_21 ( V_39 ) ;
struct V_65 * V_65 = F_35 ( V_63 ) ;
struct V_1 * V_6 ;
T_1 V_66 , V_41 , V_67 ;
F_36 (dev, crtc, encoder) {
F_23 ( V_6 -> type != V_14 ) ;
F_20 ( V_6 ) ;
}
F_25 ( F_37 ( V_68 ) , F_38 ( 2 ) |
F_39 ( 2 ) |
V_69 | V_70 ) ;
V_67 = V_18 -> V_71 | V_72 |
V_73 |
F_40 ( V_65 -> V_74 -> V_75 ) ;
F_25 ( F_41 ( V_68 ) , V_67 ) ;
F_42 ( F_41 ( V_68 ) ) ;
F_30 ( 220 ) ;
V_67 |= V_76 ;
F_25 ( F_41 ( V_68 ) , V_67 ) ;
F_25 ( F_43 ( V_15 ) , V_65 -> V_74 -> V_77 ) ;
F_23 ( V_65 -> V_74 -> V_77 != V_78 ) ;
for ( V_41 = 0 ; V_41 < F_9 ( V_56 ) * 2 ; V_41 ++ ) {
F_25 ( F_44 ( V_15 ) ,
V_79 |
V_80 |
V_81 |
V_82 ) ;
F_25 ( F_29 ( V_15 ) ,
V_83 |
( ( V_65 -> V_74 -> V_75 - 1 ) << 1 ) |
F_45 ( V_41 / 2 ) ) ;
F_42 ( F_29 ( V_15 ) ) ;
F_30 ( 600 ) ;
F_25 ( F_46 ( V_68 ) , F_47 ( 64 ) ) ;
V_67 |= V_84 | V_85 ;
F_25 ( F_41 ( V_68 ) , V_67 ) ;
F_42 ( F_41 ( V_68 ) ) ;
F_30 ( 30 ) ;
V_66 = F_31 ( F_37 ( V_68 ) ) ;
V_66 &= ~ ( V_86 | V_87 ) ;
F_25 ( F_37 ( V_68 ) , V_66 ) ;
F_42 ( F_37 ( V_68 ) ) ;
F_30 ( 5 ) ;
V_66 = F_31 ( F_48 ( V_15 ) ) ;
if ( V_66 & V_88 ) {
F_49 ( L_4 , V_41 ) ;
break;
}
if ( V_41 == F_9 ( V_56 ) * 2 - 1 ) {
F_32 ( L_5 ) ;
break;
}
V_67 &= ~ V_84 ;
F_25 ( F_41 ( V_68 ) , V_67 ) ;
F_42 ( F_41 ( V_68 ) ) ;
V_66 = F_31 ( F_29 ( V_15 ) ) ;
V_66 &= ~ V_83 ;
F_25 ( F_29 ( V_15 ) , V_66 ) ;
F_42 ( F_29 ( V_15 ) ) ;
V_66 = F_31 ( F_44 ( V_15 ) ) ;
V_66 &= ~ ( V_82 | V_89 ) ;
V_66 |= V_81 ;
F_25 ( F_44 ( V_15 ) , V_66 ) ;
F_42 ( F_44 ( V_15 ) ) ;
F_28 ( V_18 , V_15 ) ;
V_66 = F_31 ( F_37 ( V_68 ) ) ;
V_66 &= ~ ( V_86 | V_87 ) ;
V_66 |= F_38 ( 2 ) | F_39 ( 2 ) ;
F_25 ( F_37 ( V_68 ) , V_66 ) ;
F_42 ( F_37 ( V_68 ) ) ;
}
F_25 ( F_44 ( V_15 ) ,
V_79 |
V_90 |
V_80 |
V_82 ) ;
}
void F_50 ( struct V_1 * V_6 )
{
struct V_91 * V_91 = F_51 ( & V_6 -> V_7 ) ;
struct V_2 * V_92 =
F_4 ( & V_6 -> V_7 ) ;
V_91 -> V_93 = V_92 -> V_94 |
V_83 | F_45 ( 0 ) ;
V_91 -> V_93 |= F_52 ( V_91 -> V_95 ) ;
}
static struct V_1 *
F_53 ( struct V_62 * V_63 )
{
struct V_64 * V_39 = V_63 -> V_39 ;
struct V_65 * V_65 = F_35 ( V_63 ) ;
struct V_1 * V_1 , * V_96 = NULL ;
int V_97 = 0 ;
F_36 (dev, crtc, intel_encoder) {
V_96 = V_1 ;
V_97 ++ ;
}
if ( V_97 != 1 )
F_3 ( 1 , L_6 , V_97 ,
F_54 ( V_65 -> V_98 ) ) ;
F_55 ( V_96 == NULL ) ;
return V_96 ;
}
struct V_1 *
F_56 ( struct V_99 * V_100 )
{
struct V_65 * V_63 = F_35 ( V_100 -> V_7 . V_63 ) ;
struct V_1 * V_96 = NULL ;
struct V_101 * V_102 ;
struct V_103 * V_104 ;
struct V_105 * V_106 ;
int V_97 = 0 ;
int V_41 ;
V_102 = V_100 -> V_7 . V_102 ;
F_57 (state, connector, connector_state, i) {
if ( V_106 -> V_63 != V_100 -> V_7 . V_63 )
continue;
V_96 = F_58 ( V_106 -> V_107 ) ;
V_97 ++ ;
}
F_3 ( V_97 != 1 , L_6 , V_97 ,
F_54 ( V_63 -> V_98 ) ) ;
F_55 ( V_96 == NULL ) ;
return V_96 ;
}
static int F_59 ( struct V_17 * V_18 ,
T_2 V_60 )
{
int V_108 = V_109 ;
int V_110 , V_111 , V_112 ;
T_1 V_113 ;
V_113 = F_31 ( V_60 ) ;
switch ( V_113 & V_114 ) {
case V_115 :
case V_116 :
V_108 = 135 ;
break;
case V_117 :
V_108 = V_109 ;
break;
default:
F_3 ( 1 , L_7 ) ;
return 0 ;
}
V_112 = V_113 & V_118 ;
V_111 = ( V_113 & V_119 ) >> V_120 ;
V_110 = ( V_113 & V_121 ) >> V_122 ;
return ( V_108 * V_110 * 100 ) / ( V_111 * V_112 ) ;
}
static int F_60 ( struct V_17 * V_18 ,
T_3 V_123 )
{
T_2 V_124 , V_125 ;
T_3 V_126 , V_127 ;
T_3 V_128 , V_129 , V_130 , V_131 ;
V_124 = F_61 ( V_123 ) ;
V_125 = F_62 ( V_123 ) ;
V_126 = F_31 ( V_124 ) ;
V_127 = F_31 ( V_125 ) ;
V_128 = V_127 & V_132 ;
V_130 = V_127 & V_133 ;
if ( V_127 & F_63 ( 1 ) )
V_129 = ( V_127 & V_134 ) >> 8 ;
else
V_129 = 1 ;
switch ( V_128 ) {
case V_135 :
V_128 = 1 ;
break;
case V_136 :
V_128 = 2 ;
break;
case V_137 :
V_128 = 3 ;
break;
case V_138 :
V_128 = 7 ;
break;
}
switch ( V_130 ) {
case V_139 :
V_130 = 5 ;
break;
case V_140 :
V_130 = 2 ;
break;
case V_141 :
V_130 = 3 ;
break;
case V_142 :
V_130 = 1 ;
break;
}
V_131 = ( V_126 & V_143 ) * 24 * 1000 ;
V_131 += ( ( ( V_126 & V_144 ) >> 9 ) * 24 *
1000 ) / 0x8000 ;
return V_131 / ( V_128 * V_129 * V_130 * 5 ) ;
}
static void F_64 ( struct V_99 * V_145 )
{
int V_146 ;
if ( V_145 -> V_147 )
V_146 = F_65 ( V_145 -> V_148 ,
& V_145 -> V_149 ) ;
else if ( F_66 ( V_145 ) )
V_146 = F_65 ( V_145 -> V_148 ,
& V_145 -> V_150 ) ;
else if ( V_145 -> V_151 && V_145 -> V_152 == 36 )
V_146 = V_145 -> V_148 * 2 / 3 ;
else
V_146 = V_145 -> V_148 ;
if ( V_145 -> V_153 )
V_146 /= V_145 -> V_153 ;
V_145 -> V_7 . V_154 . V_155 = V_146 ;
}
static void F_67 ( struct V_1 * V_6 ,
struct V_99 * V_145 )
{
struct V_17 * V_18 = F_21 ( V_6 -> V_7 . V_39 ) ;
int V_156 = 0 ;
T_3 V_157 , V_123 ;
V_123 = V_145 -> V_77 ;
V_157 = F_31 ( V_158 ) ;
if ( V_157 & F_68 ( V_123 ) ) {
V_156 = F_60 ( V_18 , V_123 ) ;
} else {
V_156 = V_157 & F_69 ( V_123 ) ;
V_156 >>= F_70 ( V_123 ) ;
switch ( V_156 ) {
case V_159 :
V_156 = 81000 ;
break;
case V_160 :
V_156 = 108000 ;
break;
case V_161 :
V_156 = 135000 ;
break;
case V_162 :
V_156 = 162000 ;
break;
case V_163 :
V_156 = 216000 ;
break;
case V_164 :
V_156 = 270000 ;
break;
default:
F_3 ( 1 , L_8 ) ;
break;
}
V_156 *= 2 ;
}
V_145 -> V_148 = V_156 ;
F_64 ( V_145 ) ;
}
static void F_71 ( struct V_1 * V_6 ,
struct V_99 * V_145 )
{
struct V_17 * V_18 = F_21 ( V_6 -> V_7 . V_39 ) ;
int V_156 = 0 ;
T_1 V_165 , V_166 ;
V_165 = V_145 -> V_77 ;
switch ( V_165 & V_167 ) {
case V_168 :
V_156 = 81000 ;
break;
case V_169 :
V_156 = 135000 ;
break;
case V_170 :
V_156 = 270000 ;
break;
case V_171 :
V_156 = F_59 ( V_18 , F_72 ( 0 ) ) ;
break;
case V_172 :
V_156 = F_59 ( V_18 , F_72 ( 1 ) ) ;
break;
case V_78 :
V_166 = F_31 ( V_173 ) & V_174 ;
if ( V_166 == V_175 )
V_156 = 81000 ;
else if ( V_166 == V_176 )
V_156 = 135000 ;
else if ( V_166 == V_177 )
V_156 = 270000 ;
else {
F_3 ( 1 , L_9 ) ;
return;
}
break;
default:
F_3 ( 1 , L_10 ) ;
return;
}
V_145 -> V_148 = V_156 * 2 ;
F_64 ( V_145 ) ;
}
static int F_73 ( struct V_17 * V_18 ,
enum V_178 V_123 )
{
struct V_179 * V_166 ;
struct V_180 * V_102 ;
struct V_123 clock ;
if ( F_23 ( V_123 == V_181 ) )
return 0 ;
V_166 = & V_18 -> V_182 [ V_123 ] ;
V_102 = & V_166 -> V_74 . V_183 ;
clock . V_184 = 2 ;
clock . V_185 = ( V_102 -> V_186 & V_187 ) << 22 ;
if ( V_102 -> V_188 & V_189 )
clock . V_185 |= V_102 -> V_190 & V_191 ;
clock . V_110 = ( V_102 -> V_192 & V_193 ) >> V_194 ;
clock . V_129 = ( V_102 -> V_195 & V_196 ) >> V_197 ;
clock . V_130 = ( V_102 -> V_195 & V_198 ) >> V_199 ;
return F_74 ( 100000 , & clock ) ;
}
static void F_75 ( struct V_1 * V_6 ,
struct V_99 * V_145 )
{
struct V_17 * V_18 = F_21 ( V_6 -> V_7 . V_39 ) ;
enum V_4 V_4 = F_5 ( V_6 ) ;
T_3 V_123 = V_4 ;
V_145 -> V_148 = F_73 ( V_18 , V_123 ) ;
F_64 ( V_145 ) ;
}
void F_76 ( struct V_1 * V_6 ,
struct V_99 * V_145 )
{
struct V_64 * V_39 = V_6 -> V_7 . V_39 ;
if ( F_77 ( V_39 ) -> V_200 <= 8 )
F_71 ( V_6 , V_145 ) ;
else if ( F_16 ( V_39 ) || F_17 ( V_39 ) )
F_67 ( V_6 , V_145 ) ;
else if ( F_15 ( V_39 ) )
F_75 ( V_6 , V_145 ) ;
}
static bool
F_78 ( struct V_65 * V_65 ,
struct V_99 * V_100 ,
struct V_1 * V_1 )
{
struct V_179 * V_166 ;
V_166 = F_79 ( V_65 , V_100 ,
V_1 ) ;
if ( ! V_166 )
F_80 ( L_11 ,
F_54 ( V_65 -> V_98 ) ) ;
return V_166 ;
}
static bool
F_81 ( struct V_65 * V_65 ,
struct V_99 * V_100 ,
struct V_1 * V_1 )
{
struct V_179 * V_166 ;
V_166 = F_79 ( V_65 , V_100 , V_1 ) ;
if ( V_166 == NULL ) {
F_80 ( L_11 ,
F_54 ( V_65 -> V_98 ) ) ;
return false ;
}
return true ;
}
static bool
F_82 ( struct V_65 * V_65 ,
struct V_99 * V_100 ,
struct V_1 * V_1 )
{
return ! ! F_79 ( V_65 , V_100 , V_1 ) ;
}
bool F_83 ( struct V_65 * V_65 ,
struct V_99 * V_100 )
{
struct V_64 * V_39 = V_65 -> V_7 . V_39 ;
struct V_1 * V_1 =
F_56 ( V_100 ) ;
if ( F_16 ( V_39 ) || F_17 ( V_39 ) )
return F_81 ( V_65 , V_100 ,
V_1 ) ;
else if ( F_15 ( V_39 ) )
return F_82 ( V_65 , V_100 ,
V_1 ) ;
else
return F_78 ( V_65 , V_100 ,
V_1 ) ;
}
void F_84 ( struct V_62 * V_63 )
{
struct V_17 * V_18 = F_21 ( V_63 -> V_39 ) ;
struct V_65 * V_65 = F_35 ( V_63 ) ;
struct V_1 * V_1 = F_53 ( V_63 ) ;
enum V_201 V_202 = V_65 -> V_74 -> V_202 ;
int type = V_1 -> type ;
T_3 V_66 ;
if ( type == V_10 || type == V_11 || type == V_8 ) {
F_23 ( F_85 ( V_202 ) ) ;
V_66 = V_203 ;
switch ( V_65 -> V_74 -> V_152 ) {
case 18 :
V_66 |= V_204 ;
break;
case 24 :
V_66 |= V_205 ;
break;
case 30 :
V_66 |= V_206 ;
break;
case 36 :
V_66 |= V_207 ;
break;
default:
F_24 () ;
}
F_25 ( F_86 ( V_202 ) , V_66 ) ;
}
}
void F_87 ( struct V_62 * V_63 , bool V_102 )
{
struct V_65 * V_65 = F_35 ( V_63 ) ;
struct V_64 * V_39 = V_63 -> V_39 ;
struct V_17 * V_18 = F_21 ( V_39 ) ;
enum V_201 V_202 = V_65 -> V_74 -> V_202 ;
T_3 V_66 ;
V_66 = F_31 ( F_88 ( V_202 ) ) ;
if ( V_102 == true )
V_66 |= V_208 ;
else
V_66 &= ~ V_208 ;
F_25 ( F_88 ( V_202 ) , V_66 ) ;
}
void F_89 ( struct V_62 * V_63 )
{
struct V_65 * V_65 = F_35 ( V_63 ) ;
struct V_1 * V_1 = F_53 ( V_63 ) ;
struct V_5 * V_6 = & V_1 -> V_7 ;
struct V_64 * V_39 = V_63 -> V_39 ;
struct V_17 * V_18 = F_21 ( V_39 ) ;
enum V_98 V_98 = V_65 -> V_98 ;
enum V_201 V_202 = V_65 -> V_74 -> V_202 ;
enum V_4 V_4 = F_5 ( V_1 ) ;
int type = V_1 -> type ;
T_3 V_66 ;
V_66 = V_209 ;
V_66 |= F_90 ( V_4 ) ;
switch ( V_65 -> V_74 -> V_152 ) {
case 18 :
V_66 |= V_210 ;
break;
case 24 :
V_66 |= V_211 ;
break;
case 30 :
V_66 |= V_212 ;
break;
case 36 :
V_66 |= V_213 ;
break;
default:
F_24 () ;
}
if ( V_65 -> V_74 -> V_7 . V_154 . V_214 & V_215 )
V_66 |= V_216 ;
if ( V_65 -> V_74 -> V_7 . V_154 . V_214 & V_217 )
V_66 |= V_218 ;
if ( V_202 == V_219 ) {
switch ( V_98 ) {
case V_68 :
if ( F_19 ( V_39 ) &&
( V_65 -> V_74 -> V_220 . V_221 ||
V_65 -> V_74 -> V_220 . V_222 ) )
V_66 |= V_223 ;
else
V_66 |= V_224 ;
break;
case V_225 :
V_66 |= V_226 ;
break;
case V_227 :
V_66 |= V_228 ;
break;
default:
F_24 () ;
break;
}
}
if ( type == V_12 ) {
if ( V_65 -> V_74 -> V_151 )
V_66 |= V_229 ;
else
V_66 |= V_230 ;
} else if ( type == V_14 ) {
V_66 |= V_231 ;
V_66 |= ( V_65 -> V_74 -> V_75 - 1 ) << 1 ;
} else if ( type == V_10 ||
type == V_11 ) {
struct V_91 * V_91 = F_51 ( V_6 ) ;
if ( V_91 -> V_232 ) {
V_66 |= V_233 ;
} else
V_66 |= V_234 ;
V_66 |= F_52 ( V_65 -> V_74 -> V_95 ) ;
} else if ( type == V_8 ) {
struct V_91 * V_91 = & F_2 ( V_6 ) -> V_9 -> V_235 ;
if ( V_91 -> V_232 ) {
V_66 |= V_233 ;
} else
V_66 |= V_234 ;
V_66 |= F_52 ( V_65 -> V_74 -> V_95 ) ;
} else {
F_3 ( 1 , L_12 ,
V_1 -> type , F_54 ( V_98 ) ) ;
}
F_25 ( F_88 ( V_202 ) , V_66 ) ;
}
void F_91 ( struct V_17 * V_18 ,
enum V_201 V_202 )
{
T_2 V_60 = F_88 ( V_202 ) ;
T_3 V_165 = F_31 ( V_60 ) ;
V_165 &= ~ ( V_209 | V_236 | V_208 ) ;
V_165 |= V_237 ;
F_25 ( V_60 , V_165 ) ;
}
bool F_92 ( struct V_238 * V_238 )
{
struct V_64 * V_39 = V_238 -> V_7 . V_39 ;
struct V_17 * V_18 = F_21 ( V_39 ) ;
struct V_1 * V_1 = V_238 -> V_6 ;
int type = V_238 -> V_7 . V_239 ;
enum V_4 V_4 = F_5 ( V_1 ) ;
enum V_98 V_98 = 0 ;
enum V_201 V_202 ;
enum V_240 V_241 ;
T_3 V_242 ;
bool V_96 ;
V_241 = F_93 ( V_1 ) ;
if ( ! F_94 ( V_18 , V_241 ) )
return false ;
if ( ! V_1 -> V_243 ( V_1 , & V_98 ) ) {
V_96 = false ;
goto V_244;
}
if ( V_4 == V_52 )
V_202 = V_219 ;
else
V_202 = (enum V_201 ) V_98 ;
V_242 = F_31 ( F_88 ( V_202 ) ) ;
switch ( V_242 & V_245 ) {
case V_229 :
case V_230 :
V_96 = type == V_246 ;
break;
case V_234 :
V_96 = type == V_247 ||
type == V_248 ;
break;
case V_233 :
V_96 = false ;
break;
case V_231 :
V_96 = type == V_249 ;
break;
default:
V_96 = false ;
break;
}
V_244:
F_95 ( V_18 , V_241 ) ;
return V_96 ;
}
bool F_96 ( struct V_1 * V_6 ,
enum V_98 * V_98 )
{
struct V_64 * V_39 = V_6 -> V_7 . V_39 ;
struct V_17 * V_18 = F_21 ( V_39 ) ;
enum V_4 V_4 = F_5 ( V_6 ) ;
enum V_240 V_241 ;
T_1 V_242 ;
int V_41 ;
bool V_96 ;
V_241 = F_93 ( V_6 ) ;
if ( ! F_94 ( V_18 , V_241 ) )
return false ;
V_96 = false ;
V_242 = F_31 ( F_29 ( V_4 ) ) ;
if ( ! ( V_242 & V_83 ) )
goto V_244;
if ( V_4 == V_52 ) {
V_242 = F_31 ( F_88 ( V_219 ) ) ;
switch ( V_242 & V_250 ) {
case V_224 :
case V_223 :
* V_98 = V_68 ;
break;
case V_226 :
* V_98 = V_225 ;
break;
case V_228 :
* V_98 = V_227 ;
break;
}
V_96 = true ;
goto V_244;
}
for ( V_41 = V_251 ; V_41 <= V_252 ; V_41 ++ ) {
V_242 = F_31 ( F_88 ( V_41 ) ) ;
if ( ( V_242 & V_236 ) == F_90 ( V_4 ) ) {
if ( ( V_242 & V_245 ) ==
V_233 )
goto V_244;
* V_98 = V_41 ;
V_96 = true ;
goto V_244;
}
}
F_49 ( L_13 , F_33 ( V_4 ) ) ;
V_244:
if ( V_96 && F_15 ( V_18 ) ) {
V_242 = F_31 ( F_97 ( V_4 ) ) ;
if ( ( V_242 & ( V_253 |
V_254 ) ) != V_254 )
F_32 ( L_14
L_15 , F_33 ( V_4 ) , V_242 ) ;
}
F_95 ( V_18 , V_241 ) ;
return V_96 ;
}
void F_98 ( struct V_65 * V_65 )
{
struct V_62 * V_63 = & V_65 -> V_7 ;
struct V_64 * V_39 = V_63 -> V_39 ;
struct V_17 * V_18 = F_21 ( V_39 ) ;
struct V_1 * V_1 = F_53 ( V_63 ) ;
enum V_4 V_4 = F_5 ( V_1 ) ;
enum V_201 V_202 = V_65 -> V_74 -> V_202 ;
if ( V_202 != V_219 )
F_25 ( F_99 ( V_202 ) ,
F_100 ( V_4 ) ) ;
}
void F_101 ( struct V_65 * V_65 )
{
struct V_17 * V_18 = F_21 ( V_65 -> V_7 . V_39 ) ;
enum V_201 V_202 = V_65 -> V_74 -> V_202 ;
if ( V_202 != V_219 )
F_25 ( F_99 ( V_202 ) ,
V_255 ) ;
}
static void F_102 ( struct V_17 * V_18 ,
enum V_4 V_4 , T_4 V_256 )
{
T_1 V_242 ;
V_242 = F_31 ( V_257 ) ;
V_242 &= ~ ( F_103 ( V_4 ) | F_104 ( V_4 ) ) ;
if ( V_256 )
V_242 |= V_256 << F_105 ( V_4 ) ;
else
V_242 |= F_104 ( V_4 ) ;
F_25 ( V_257 , V_242 ) ;
}
static void F_106 ( struct V_1 * V_6 , T_1 V_258 )
{
struct V_2 * V_92 = F_4 ( & V_6 -> V_7 ) ;
struct V_17 * V_18 = F_21 ( V_92 -> V_7 . V_7 . V_39 ) ;
enum V_4 V_4 = V_92 -> V_4 ;
int type = V_6 -> type ;
const struct V_16 * V_49 ;
T_4 V_256 ;
T_4 V_259 , V_260 ;
int V_19 ;
V_259 = V_18 -> V_23 . V_34 [ V_4 ] . V_51 ;
V_260 = V_18 -> V_23 . V_34 [ V_4 ] . V_50 ;
if ( type == V_10 ) {
if ( V_259 ) {
V_256 = V_259 ;
} else {
V_49 = F_6 ( V_18 , & V_19 ) ;
V_256 = V_49 [ V_258 ] . V_261 ;
}
} else if ( type == V_11 ) {
if ( V_259 ) {
V_256 = V_259 ;
} else {
V_49 = F_12 ( V_18 , & V_19 ) ;
if ( F_23 ( V_4 != V_52 &&
V_4 != V_15 && V_19 > 9 ) )
V_19 = 9 ;
V_256 = V_49 [ V_258 ] . V_261 ;
}
} else if ( type == V_12 ) {
if ( V_260 ) {
V_256 = V_260 ;
} else {
V_49 = F_13 ( V_18 , & V_19 ) ;
V_256 = V_49 [ V_258 ] . V_261 ;
}
} else {
return;
}
if ( V_256 && V_256 != 0x1 && V_256 != 0x3 && V_256 != 0x7 ) {
F_32 ( L_16 , V_256 ) ;
return;
}
F_102 ( V_18 , V_4 , V_256 ) ;
if ( V_4 == V_52 && V_92 -> V_262 == 4 )
F_102 ( V_18 , V_15 , V_256 ) ;
}
static void F_22 ( struct V_17 * V_18 ,
T_1 V_258 , enum V_4 V_4 , int type )
{
const struct V_263 * V_49 ;
T_1 V_19 , V_41 ;
T_3 V_165 ;
if ( type == V_11 && V_18 -> V_23 . V_24 . V_25 ) {
V_19 = F_9 ( V_264 ) ;
V_49 = V_264 ;
} else if ( type == V_10
|| type == V_11 ) {
V_19 = F_9 ( V_265 ) ;
V_49 = V_265 ;
} else if ( type == V_12 ) {
V_19 = F_9 ( V_266 ) ;
V_49 = V_266 ;
} else {
F_49 ( L_17 ,
type ) ;
return;
}
if ( V_258 >= V_19 ||
( type == V_12 && V_258 == V_38 ) ) {
for ( V_41 = 0 ; V_41 < V_19 ; V_41 ++ ) {
if ( V_49 [ V_41 ] . V_267 ) {
V_258 = V_41 ;
break;
}
}
}
V_165 = F_31 ( F_107 ( V_4 ) ) ;
V_165 &= ~ ( V_268 | V_269 ) ;
F_25 ( F_108 ( V_4 ) , V_165 ) ;
V_165 = F_31 ( F_109 ( V_4 ) ) ;
V_165 &= ~ ( V_270 | V_271 ) ;
V_165 |= V_49 [ V_258 ] . V_272 << V_273 |
V_49 [ V_258 ] . V_274 << V_275 ;
F_25 ( F_110 ( V_4 ) , V_165 ) ;
V_165 = F_31 ( F_111 ( V_4 ) ) ;
V_165 &= ~ V_276 ;
if ( V_49 [ V_258 ] . V_277 )
V_165 |= V_276 ;
if ( ( V_165 & V_278 ) && ! ( V_165 & V_276 ) )
F_32 ( L_18 ) ;
F_25 ( F_112 ( V_4 ) , V_165 ) ;
V_165 = F_31 ( F_113 ( V_4 ) ) ;
V_165 &= ~ V_279 ;
V_165 |= V_49 [ V_258 ] . V_280 << V_281 ;
F_25 ( F_114 ( V_4 ) , V_165 ) ;
V_165 = F_31 ( F_107 ( V_4 ) ) ;
V_165 |= V_268 | V_269 ;
F_25 ( F_108 ( V_4 ) , V_165 ) ;
}
static T_3 F_115 ( int V_282 )
{
T_3 V_258 ;
switch ( V_282 ) {
default:
F_49 ( L_19 ,
V_282 ) ;
case V_283 | V_284 :
V_258 = 0 ;
break;
case V_283 | V_285 :
V_258 = 1 ;
break;
case V_283 | V_286 :
V_258 = 2 ;
break;
case V_283 | V_287 :
V_258 = 3 ;
break;
case V_288 | V_284 :
V_258 = 4 ;
break;
case V_288 | V_285 :
V_258 = 5 ;
break;
case V_288 | V_286 :
V_258 = 6 ;
break;
case V_289 | V_284 :
V_258 = 7 ;
break;
case V_289 | V_285 :
V_258 = 8 ;
break;
case V_290 | V_284 :
V_258 = 9 ;
break;
}
return V_258 ;
}
T_3 F_116 ( struct V_91 * V_91 )
{
struct V_2 * V_291 = F_117 ( V_91 ) ;
struct V_17 * V_18 = F_21 ( V_291 -> V_7 . V_7 . V_39 ) ;
struct V_1 * V_6 = & V_291 -> V_7 ;
T_4 V_292 = V_91 -> V_292 [ 0 ] ;
int V_282 = V_292 & ( V_293 |
V_294 ) ;
enum V_4 V_4 = V_291 -> V_4 ;
T_3 V_258 ;
V_258 = F_115 ( V_282 ) ;
if ( F_16 ( V_18 ) || F_17 ( V_18 ) )
F_106 ( V_6 , V_258 ) ;
else if ( F_15 ( V_18 ) )
F_22 ( V_18 , V_258 , V_4 , V_6 -> type ) ;
return F_45 ( V_258 ) ;
}
void F_118 ( struct V_1 * V_6 ,
const struct V_99 * V_145 )
{
struct V_17 * V_18 = F_21 ( V_6 -> V_7 . V_39 ) ;
enum V_4 V_4 = F_5 ( V_6 ) ;
if ( F_16 ( V_18 ) || F_17 ( V_18 ) ) {
T_3 V_123 = V_145 -> V_77 ;
T_3 V_165 ;
V_165 = F_31 ( V_295 ) ;
V_165 &= ~ ( F_119 ( V_4 ) |
F_120 ( V_4 ) ) ;
V_165 |= ( F_121 ( V_123 , V_4 ) |
F_122 ( V_4 ) ) ;
F_25 ( V_295 , V_165 ) ;
} else if ( F_77 ( V_18 ) -> V_200 < 9 ) {
F_23 ( V_145 -> V_77 == V_296 ) ;
F_25 ( F_43 ( V_4 ) , V_145 -> V_77 ) ;
}
}
static void F_123 ( struct V_1 * V_1 )
{
struct V_5 * V_6 = & V_1 -> V_7 ;
struct V_17 * V_18 = F_21 ( V_6 -> V_39 ) ;
struct V_65 * V_63 = F_35 ( V_6 -> V_63 ) ;
enum V_4 V_4 = F_5 ( V_1 ) ;
int type = V_1 -> type ;
if ( type == V_12 ) {
struct V_297 * V_297 = F_124 ( V_6 ) ;
F_125 ( V_297 , true ) ;
}
F_20 ( V_1 ) ;
if ( type == V_11 ) {
struct V_91 * V_91 = F_51 ( V_6 ) ;
F_126 ( V_91 ) ;
}
F_118 ( V_1 , V_63 -> V_74 ) ;
if ( type == V_10 || type == V_11 ) {
struct V_91 * V_91 = F_51 ( V_6 ) ;
F_127 ( V_91 , V_63 -> V_74 ) ;
F_50 ( V_1 ) ;
F_128 ( V_91 , V_298 ) ;
F_129 ( V_91 ) ;
if ( V_4 != V_52 || F_77 ( V_18 ) -> V_200 >= 9 )
F_130 ( V_91 ) ;
} else if ( type == V_12 ) {
struct V_297 * V_297 = F_124 ( V_6 ) ;
int V_258 = F_14 ( V_18 , V_4 ) ;
if ( F_16 ( V_18 ) || F_17 ( V_18 ) )
F_106 ( V_1 , V_258 ) ;
V_297 -> V_299 ( V_6 ,
V_63 -> V_74 -> V_151 ,
& V_63 -> V_74 -> V_7 . V_154 ) ;
}
}
static void F_131 ( struct V_1 * V_1 )
{
struct V_5 * V_6 = & V_1 -> V_7 ;
struct V_64 * V_39 = V_6 -> V_39 ;
struct V_17 * V_18 = F_21 ( V_39 ) ;
enum V_4 V_4 = F_5 ( V_1 ) ;
int type = V_1 -> type ;
T_3 V_165 ;
bool V_300 = false ;
V_165 = F_31 ( F_29 ( V_4 ) ) ;
if ( V_165 & V_83 ) {
V_165 &= ~ V_83 ;
F_25 ( F_29 ( V_4 ) , V_165 ) ;
V_300 = true ;
}
V_165 = F_31 ( F_44 ( V_4 ) ) ;
V_165 &= ~ ( V_82 | V_89 ) ;
V_165 |= V_81 ;
F_25 ( F_44 ( V_4 ) , V_165 ) ;
if ( V_300 )
F_28 ( V_18 , V_4 ) ;
if ( type == V_10 || type == V_11 ) {
struct V_91 * V_91 = F_51 ( V_6 ) ;
F_128 ( V_91 , V_301 ) ;
F_132 ( V_91 ) ;
F_133 ( V_91 ) ;
}
if ( F_16 ( V_39 ) || F_17 ( V_39 ) )
F_25 ( V_295 , ( F_31 ( V_295 ) |
F_119 ( V_4 ) ) ) ;
else if ( F_77 ( V_39 ) -> V_200 < 9 )
F_25 ( F_43 ( V_4 ) , V_296 ) ;
if ( type == V_12 ) {
struct V_297 * V_297 = F_124 ( V_6 ) ;
F_125 ( V_297 , false ) ;
}
}
static void F_134 ( struct V_1 * V_1 )
{
struct V_5 * V_6 = & V_1 -> V_7 ;
struct V_62 * V_63 = V_6 -> V_63 ;
struct V_65 * V_65 = F_35 ( V_63 ) ;
struct V_64 * V_39 = V_6 -> V_39 ;
struct V_17 * V_18 = F_21 ( V_39 ) ;
enum V_4 V_4 = F_5 ( V_1 ) ;
int type = V_1 -> type ;
if ( type == V_12 ) {
struct V_2 * V_92 =
F_4 ( V_6 ) ;
F_25 ( F_29 ( V_4 ) ,
V_92 -> V_94 |
V_83 ) ;
} else if ( type == V_11 ) {
struct V_91 * V_91 = F_51 ( V_6 ) ;
if ( V_4 == V_52 && F_77 ( V_39 ) -> V_200 < 9 )
F_130 ( V_91 ) ;
F_135 ( V_91 ) ;
F_136 ( V_91 ) ;
F_137 ( V_91 ) ;
}
if ( V_65 -> V_74 -> V_302 ) {
F_138 ( V_18 , V_303 ) ;
F_139 ( V_1 ) ;
}
}
static void F_140 ( struct V_1 * V_1 )
{
struct V_5 * V_6 = & V_1 -> V_7 ;
struct V_62 * V_63 = V_6 -> V_63 ;
struct V_65 * V_65 = F_35 ( V_63 ) ;
int type = V_1 -> type ;
struct V_64 * V_39 = V_6 -> V_39 ;
struct V_17 * V_18 = F_21 ( V_39 ) ;
if ( V_65 -> V_74 -> V_302 ) {
F_141 ( V_1 ) ;
F_95 ( V_18 , V_303 ) ;
}
if ( type == V_11 ) {
struct V_91 * V_91 = F_51 ( V_6 ) ;
F_142 ( V_91 ) ;
F_143 ( V_91 ) ;
F_144 ( V_91 ) ;
}
}
bool F_145 ( struct V_17 * V_18 ,
enum V_304 V_305 )
{
enum V_4 V_4 ;
if ( ! ( F_31 ( V_306 ) & F_146 ( V_305 ) ) )
return false ;
if ( ( F_31 ( F_147 ( V_305 ) ) &
( V_307 | V_308 ) ) != V_307 ) {
F_80 ( L_20 ,
V_305 ) ;
return false ;
}
if ( V_305 == V_309 &&
! ( F_31 ( F_148 ( V_309 ) ) & V_310 ) ) {
F_80 ( L_21 ) ;
return false ;
}
if ( ! ( F_31 ( F_149 ( V_305 ) ) & V_311 ) ) {
F_80 ( L_22 ,
V_305 ) ;
return false ;
}
F_150 (port,
phy == DPIO_PHY0 ? BIT(PORT_B) | BIT(PORT_C) :
BIT(PORT_A)) {
T_1 V_242 = F_31 ( F_97 ( V_4 ) ) ;
if ( V_242 & V_312 ) {
F_80 ( L_23
L_24
L_15 ,
V_305 , F_33 ( V_4 ) , V_242 ) ;
return false ;
}
}
return true ;
}
static T_1 F_151 ( struct V_17 * V_18 , enum V_304 V_305 )
{
T_1 V_165 = F_31 ( F_152 ( V_305 ) ) ;
return ( V_165 & V_313 ) >> V_314 ;
}
static void F_153 ( struct V_17 * V_18 ,
enum V_304 V_305 )
{
if ( F_154 ( V_18 ,
F_148 ( V_305 ) ,
V_310 , V_310 ,
10 ) )
F_32 ( L_25 , V_305 ) ;
}
void F_155 ( struct V_17 * V_18 , enum V_304 V_305 )
{
T_1 V_165 ;
if ( F_145 ( V_18 , V_305 ) ) {
if ( V_305 == V_315 )
V_18 -> V_316 = F_151 ( V_18 , V_305 ) ;
if ( F_156 ( V_18 , V_305 ) ) {
F_80 ( L_26
L_27 , V_305 ) ;
return;
}
F_80 ( L_28
L_29 , V_305 ) ;
}
V_165 = F_31 ( V_306 ) ;
V_165 |= F_146 ( V_305 ) ;
F_25 ( V_306 , V_165 ) ;
if ( F_157 ( ( ( F_31 ( F_147 ( V_305 ) ) &
( V_308 | V_307 ) ) == V_307 ) , 100 ) ) {
F_32 ( L_30 , V_305 ) ;
}
V_165 = F_31 ( F_158 ( V_305 ) ) ;
V_165 &= ~ V_317 ;
V_165 |= 0xE4 << V_318 ;
F_25 ( F_158 ( V_305 ) , V_165 ) ;
V_165 = F_31 ( F_159 ( V_305 ) ) ;
V_165 &= ~ V_319 ;
V_165 |= 0xE4 << V_320 ;
F_25 ( F_159 ( V_305 ) , V_165 ) ;
V_165 = F_31 ( F_160 ( V_305 ) ) ;
V_165 |= V_321 | V_322 |
V_323 ;
F_25 ( F_160 ( V_305 ) , V_165 ) ;
if ( V_305 == V_315 ) {
V_165 = F_31 ( V_324 ) ;
V_165 |= V_325 ;
F_25 ( V_324 , V_165 ) ;
}
V_165 = F_31 ( F_161 ( V_305 ) ) ;
V_165 &= ~ V_326 ;
if ( V_305 == V_309 )
V_165 |= V_326 ;
F_25 ( F_161 ( V_305 ) , V_165 ) ;
if ( V_305 == V_315 ) {
T_3 V_327 ;
V_165 = V_18 -> V_316 = F_151 ( V_18 , V_309 ) ;
V_327 = V_165 << V_328 |
V_165 << V_329 |
V_165 ;
F_25 ( F_152 ( V_315 ) , V_327 ) ;
V_165 = F_31 ( F_162 ( V_315 ) ) ;
V_165 |= V_330 | V_331 ;
F_25 ( F_162 ( V_315 ) , V_165 ) ;
}
V_165 = F_31 ( F_149 ( V_305 ) ) ;
V_165 |= V_311 ;
F_25 ( F_149 ( V_305 ) , V_165 ) ;
if ( V_305 == V_309 )
F_153 ( V_18 , V_309 ) ;
}
void F_163 ( struct V_17 * V_18 , enum V_304 V_305 )
{
T_3 V_165 ;
V_165 = F_31 ( F_149 ( V_305 ) ) ;
V_165 &= ~ V_311 ;
F_25 ( F_149 ( V_305 ) , V_165 ) ;
V_165 = F_31 ( V_306 ) ;
V_165 &= ~ F_146 ( V_305 ) ;
F_25 ( V_306 , V_165 ) ;
}
bool F_156 ( struct V_17 * V_18 ,
enum V_304 V_305 )
{
T_3 V_332 ;
bool V_333 ;
#define F_164 ( V_60 , V_332 , exp , T_5 , ... ) \
__phy_reg_verify_state(dev_priv, phy, reg, mask, exp, fmt, \
## __VA_ARGS__)
if ( ! F_145 ( V_18 , V_305 ) )
return false ;
V_333 = true ;
V_333 &= F_164 ( F_158 ( V_305 ) ,
V_317 , 0xe4 << V_318 ,
L_31 , V_305 ) ;
V_333 &= F_164 ( F_159 ( V_305 ) ,
V_319 , 0xe4 << V_320 ,
L_32 , V_305 ) ;
V_332 = V_321 | V_322 | V_323 ;
V_333 &= F_164 ( F_160 ( V_305 ) , V_332 , V_332 ,
L_33 , V_305 ) ;
if ( V_305 == V_315 )
V_333 &= F_164 ( V_324 ,
V_325 , V_325 ,
L_34 ) ;
if ( V_305 == V_315 ) {
T_1 V_327 = V_18 -> V_316 ;
V_327 = V_327 << V_328 |
V_327 << V_329 |
V_327 ;
V_332 = V_334 | V_335 |
V_336 ;
V_333 &= F_164 ( F_152 ( V_315 ) , V_332 , V_327 ,
L_35 , V_315 ) ;
V_332 = V_330 | V_331 ;
V_333 &= F_164 ( F_162 ( V_315 ) , V_332 , V_332 ,
L_36 , V_315 ) ;
}
return V_333 ;
#undef F_164
}
static T_4
F_165 ( struct V_1 * V_6 ,
struct V_99 * V_145 )
{
switch ( V_145 -> V_95 ) {
case 1 :
return 0 ;
case 2 :
return F_166 ( 2 ) | F_166 ( 0 ) ;
case 4 :
return F_166 ( 3 ) | F_166 ( 2 ) | F_166 ( 0 ) ;
default:
F_167 ( V_145 -> V_95 ) ;
return 0 ;
}
}
static void F_168 ( struct V_1 * V_6 )
{
struct V_2 * V_291 = F_4 ( & V_6 -> V_7 ) ;
struct V_17 * V_18 = F_21 ( V_291 -> V_7 . V_7 . V_39 ) ;
enum V_4 V_4 = V_291 -> V_4 ;
struct V_65 * V_65 = F_35 ( V_6 -> V_7 . V_63 ) ;
int V_337 ;
for ( V_337 = 0 ; V_337 < 4 ; V_337 ++ ) {
T_1 V_165 = F_31 ( F_169 ( V_4 , V_337 ) ) ;
V_165 &= ~ V_338 ;
if ( V_65 -> V_74 -> V_339 & F_166 ( V_337 ) )
V_165 |= V_338 ;
F_25 ( F_169 ( V_4 , V_337 ) , V_165 ) ;
}
}
static T_4
F_170 ( struct V_1 * V_6 )
{
struct V_2 * V_291 = F_4 ( & V_6 -> V_7 ) ;
struct V_17 * V_18 = F_21 ( V_291 -> V_7 . V_7 . V_39 ) ;
enum V_4 V_4 = V_291 -> V_4 ;
int V_337 ;
T_4 V_332 ;
V_332 = 0 ;
for ( V_337 = 0 ; V_337 < 4 ; V_337 ++ ) {
T_1 V_165 = F_31 ( F_169 ( V_4 , V_337 ) ) ;
if ( V_165 & V_338 )
V_332 |= F_166 ( V_337 ) ;
}
return V_332 ;
}
void F_171 ( struct V_91 * V_91 )
{
struct V_2 * V_92 = F_117 ( V_91 ) ;
struct V_17 * V_18 =
F_21 ( V_92 -> V_7 . V_7 . V_39 ) ;
enum V_4 V_4 = V_92 -> V_4 ;
T_3 V_165 ;
bool V_300 = false ;
if ( F_31 ( F_44 ( V_4 ) ) & V_82 ) {
V_165 = F_31 ( F_29 ( V_4 ) ) ;
if ( V_165 & V_83 ) {
V_165 &= ~ V_83 ;
F_25 ( F_29 ( V_4 ) , V_165 ) ;
V_300 = true ;
}
V_165 = F_31 ( F_44 ( V_4 ) ) ;
V_165 &= ~ ( V_82 | V_89 ) ;
V_165 |= V_81 ;
F_25 ( F_44 ( V_4 ) , V_165 ) ;
F_42 ( F_44 ( V_4 ) ) ;
if ( V_300 )
F_28 ( V_18 , V_4 ) ;
}
V_165 = V_82 |
V_81 | V_340 ;
if ( V_91 -> V_232 )
V_165 |= V_341 ;
else {
V_165 |= V_342 ;
if ( F_172 ( V_91 -> V_343 ) )
V_165 |= V_80 ;
}
F_25 ( F_44 ( V_4 ) , V_165 ) ;
F_42 ( F_44 ( V_4 ) ) ;
V_91 -> V_93 |= V_83 ;
F_25 ( F_29 ( V_4 ) , V_91 -> V_93 ) ;
F_42 ( F_29 ( V_4 ) ) ;
F_30 ( 600 ) ;
}
void F_173 ( struct V_62 * V_63 )
{
struct V_17 * V_18 = F_21 ( V_63 -> V_39 ) ;
struct V_1 * V_1 = F_53 ( V_63 ) ;
T_3 V_165 ;
V_165 = F_31 ( F_41 ( V_68 ) ) ;
V_165 &= ~ V_84 ;
F_25 ( F_41 ( V_68 ) , V_165 ) ;
F_131 ( V_1 ) ;
V_165 = F_31 ( F_37 ( V_68 ) ) ;
V_165 &= ~ ( V_86 | V_87 ) ;
V_165 |= F_38 ( 2 ) | F_39 ( 2 ) ;
F_25 ( F_37 ( V_68 ) , V_165 ) ;
V_165 = F_31 ( F_41 ( V_68 ) ) ;
V_165 &= ~ V_76 ;
F_25 ( F_41 ( V_68 ) , V_165 ) ;
V_165 = F_31 ( F_41 ( V_68 ) ) ;
V_165 &= ~ V_73 ;
F_25 ( F_41 ( V_68 ) , V_165 ) ;
}
void F_174 ( struct V_1 * V_6 ,
struct V_99 * V_145 )
{
struct V_17 * V_18 = F_21 ( V_6 -> V_7 . V_39 ) ;
struct V_65 * V_65 = F_35 ( V_6 -> V_7 . V_63 ) ;
enum V_201 V_202 = V_145 -> V_202 ;
struct V_297 * V_297 ;
T_1 V_66 , V_214 = 0 ;
if ( F_23 ( F_85 ( V_202 ) ) )
return;
V_66 = F_31 ( F_88 ( V_202 ) ) ;
if ( V_66 & V_218 )
V_214 |= V_217 ;
else
V_214 |= V_344 ;
if ( V_66 & V_216 )
V_214 |= V_215 ;
else
V_214 |= V_345 ;
V_145 -> V_7 . V_154 . V_214 |= V_214 ;
switch ( V_66 & V_346 ) {
case V_210 :
V_145 -> V_152 = 18 ;
break;
case V_211 :
V_145 -> V_152 = 24 ;
break;
case V_212 :
V_145 -> V_152 = 30 ;
break;
case V_213 :
V_145 -> V_152 = 36 ;
break;
default:
break;
}
switch ( V_66 & V_245 ) {
case V_229 :
V_145 -> V_151 = true ;
V_297 = F_124 ( & V_6 -> V_7 ) ;
if ( V_297 -> V_347 ( & V_6 -> V_7 , V_145 ) )
V_145 -> V_348 = true ;
case V_230 :
V_145 -> V_95 = 4 ;
break;
case V_231 :
break;
case V_234 :
case V_233 :
V_145 -> V_95 =
( ( V_66 & V_349 ) >> V_350 ) + 1 ;
F_175 ( V_65 , V_145 ) ;
break;
default:
break;
}
if ( F_176 ( V_18 , V_303 ) ) {
V_66 = F_31 ( V_351 ) ;
if ( V_66 & F_177 ( V_65 -> V_98 ) )
V_145 -> V_302 = true ;
}
if ( V_6 -> type == V_11 && V_18 -> V_23 . V_24 . V_352 &&
V_145 -> V_152 > V_18 -> V_23 . V_24 . V_352 ) {
F_49 ( L_37 ,
V_145 -> V_152 , V_18 -> V_23 . V_24 . V_352 ) ;
V_18 -> V_23 . V_24 . V_352 = V_145 -> V_152 ;
}
F_76 ( V_6 , V_145 ) ;
if ( F_15 ( V_18 ) )
V_145 -> V_339 =
F_170 ( V_6 ) ;
}
static bool F_178 ( struct V_1 * V_6 ,
struct V_99 * V_145 )
{
struct V_17 * V_18 = F_21 ( V_6 -> V_7 . V_39 ) ;
int type = V_6 -> type ;
int V_4 = F_5 ( V_6 ) ;
int V_96 ;
F_3 ( type == V_13 , L_38 ) ;
if ( V_4 == V_52 )
V_145 -> V_202 = V_219 ;
if ( type == V_12 )
V_96 = F_179 ( V_6 , V_145 ) ;
else
V_96 = F_180 ( V_6 , V_145 ) ;
if ( F_15 ( V_18 ) && V_96 )
V_145 -> V_339 =
F_165 ( V_6 ,
V_145 ) ;
return V_96 ;
}
static struct V_238 *
F_181 ( struct V_2 * V_92 )
{
struct V_238 * V_104 ;
enum V_4 V_4 = V_92 -> V_4 ;
V_104 = F_182 () ;
if ( ! V_104 )
return NULL ;
V_92 -> V_235 . V_353 = F_29 ( V_4 ) ;
if ( ! F_183 ( V_92 , V_104 ) ) {
F_184 ( V_104 ) ;
return NULL ;
}
return V_104 ;
}
static struct V_238 *
F_185 ( struct V_2 * V_92 )
{
struct V_238 * V_104 ;
enum V_4 V_4 = V_92 -> V_4 ;
V_104 = F_182 () ;
if ( ! V_104 )
return NULL ;
V_92 -> V_354 . V_355 = F_29 ( V_4 ) ;
F_186 ( V_92 , V_104 ) ;
return V_104 ;
}
void F_187 ( struct V_64 * V_39 , enum V_4 V_4 )
{
struct V_17 * V_18 = F_21 ( V_39 ) ;
struct V_2 * V_92 ;
struct V_1 * V_1 ;
struct V_5 * V_6 ;
bool V_356 , V_357 ;
int V_262 ;
if ( F_31 ( F_29 ( V_52 ) ) & V_358 ) {
switch ( V_4 ) {
case V_52 :
V_262 = 4 ;
break;
case V_15 :
V_262 = 0 ;
break;
default:
V_262 = 4 ;
break;
}
} else {
switch ( V_4 ) {
case V_52 :
V_262 = 2 ;
break;
case V_15 :
V_262 = 2 ;
break;
default:
V_262 = 4 ;
break;
}
}
V_356 = ( V_18 -> V_23 . V_34 [ V_4 ] . V_359 ||
V_18 -> V_23 . V_34 [ V_4 ] . V_360 ) ;
V_357 = V_18 -> V_23 . V_34 [ V_4 ] . V_361 ;
if ( ! V_357 && ! V_356 ) {
F_49 ( L_39 ,
F_33 ( V_4 ) ) ;
return;
}
V_92 = F_188 ( sizeof( * V_92 ) , V_362 ) ;
if ( ! V_92 )
return;
V_1 = & V_92 -> V_7 ;
V_6 = & V_1 -> V_7 ;
F_189 ( V_39 , V_6 , & V_363 ,
V_364 , L_40 , F_33 ( V_4 ) ) ;
V_1 -> V_365 = F_178 ;
V_1 -> V_277 = F_134 ;
if ( F_15 ( V_18 ) )
V_1 -> V_366 = F_168 ;
V_1 -> V_367 = F_123 ;
V_1 -> V_368 = F_140 ;
V_1 -> V_369 = F_131 ;
V_1 -> V_243 = F_96 ;
V_1 -> V_370 = F_174 ;
V_1 -> V_371 = V_372 ;
V_92 -> V_4 = V_4 ;
V_92 -> V_94 = F_31 ( F_29 ( V_4 ) ) &
( V_373 |
V_358 ) ;
if ( F_15 ( V_39 ) && V_4 == V_52 ) {
if ( ! ( V_92 -> V_94 & V_358 ) ) {
F_49 ( L_41 ) ;
V_92 -> V_94 |= V_358 ;
V_262 = 4 ;
}
}
V_92 -> V_262 = V_262 ;
V_1 -> type = V_13 ;
V_1 -> V_374 = ( 1 << 0 ) | ( 1 << 1 ) | ( 1 << 2 ) ;
V_1 -> V_375 = 0 ;
if ( V_357 ) {
if ( ! F_181 ( V_92 ) )
goto V_376;
V_92 -> V_377 = V_378 ;
if ( F_190 ( V_39 , 0 , V_379 ) && V_4 == V_380 )
V_18 -> V_381 . V_382 [ V_52 ] = V_92 ;
else
V_18 -> V_381 . V_382 [ V_4 ] = V_92 ;
}
if ( V_1 -> type != V_11 && V_356 ) {
if ( ! F_185 ( V_92 ) )
goto V_376;
}
return;
V_376:
F_191 ( V_6 ) ;
F_184 ( V_92 ) ;
}
