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
if ( F_18 ( V_16 ) ) {
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
static const struct V_14 *
F_22 ( struct V_15 * V_16 ,
int * V_17 )
{
if ( F_14 ( V_16 ) ) {
return F_10 ( V_16 , V_17 ) ;
} else if ( F_23 ( V_16 ) ) {
return F_7 ( V_16 , V_17 ) ;
} else if ( F_19 ( V_16 ) ) {
* V_17 = F_6 ( V_22 ) ;
return V_22 ;
} else if ( F_20 ( V_16 ) ) {
* V_17 = F_6 ( V_42 ) ;
return V_42 ;
}
* V_17 = 0 ;
return NULL ;
}
static const struct V_14 *
F_24 ( struct V_15 * V_16 ,
int * V_17 )
{
if ( F_14 ( V_16 ) || F_23 ( V_16 ) ) {
return F_13 ( V_16 , V_17 ) ;
} else if ( F_19 ( V_16 ) ) {
return F_5 ( V_16 , V_17 ) ;
} else if ( F_20 ( V_16 ) ) {
* V_17 = F_6 ( V_42 ) ;
return V_42 ;
}
* V_17 = 0 ;
return NULL ;
}
static const struct V_14 *
F_25 ( struct V_15 * V_16 ,
int * V_17 )
{
if ( F_19 ( V_16 ) ) {
* V_17 = F_6 ( V_43 ) ;
return V_43 ;
} else if ( F_20 ( V_16 ) ) {
* V_17 = F_6 ( V_43 ) ;
return V_43 ;
}
* V_17 = 0 ;
return NULL ;
}
static void F_26 ( struct V_2 * V_3 )
{
struct V_15 * V_16 = F_27 ( V_3 -> V_5 . V_44 ) ;
T_1 V_45 = 0 ;
int V_46 , V_17 ;
enum V_1 V_1 = F_1 ( V_3 ) ;
const struct V_14 * V_47 ;
if ( F_17 ( V_16 ) )
return;
switch ( V_3 -> type ) {
case V_8 :
V_47 = F_24 ( V_16 ,
& V_17 ) ;
break;
case V_7 :
V_47 = F_22 ( V_16 ,
& V_17 ) ;
break;
case V_11 :
V_47 = F_25 ( V_16 ,
& V_17 ) ;
break;
default:
F_4 ( V_3 -> type ) ;
return;
}
if ( F_18 ( V_16 ) ) {
if ( V_16 -> V_18 . V_37 [ V_1 ] . V_48 )
V_45 = V_49 ;
if ( F_28 ( V_3 -> type == V_8 &&
V_1 != V_13 && V_1 != V_12 &&
V_17 > 9 ) )
V_17 = 9 ;
}
for ( V_46 = 0 ; V_46 < V_17 ; V_46 ++ ) {
F_29 ( F_30 ( V_1 , V_46 ) ,
V_47 [ V_46 ] . V_50 | V_45 ) ;
F_29 ( F_31 ( V_1 , V_46 ) ,
V_47 [ V_46 ] . V_51 ) ;
}
}
static void F_32 ( struct V_2 * V_3 )
{
struct V_15 * V_16 = F_27 ( V_3 -> V_5 . V_44 ) ;
T_1 V_45 = 0 ;
int V_34 , V_35 ;
enum V_1 V_1 = F_1 ( V_3 ) ;
const struct V_14 * V_52 ;
if ( F_17 ( V_16 ) )
return;
V_35 = F_16 ( V_16 , V_1 ) ;
if ( F_18 ( V_16 ) ) {
V_52 = F_15 ( V_16 , & V_34 ) ;
if ( V_16 -> V_18 . V_37 [ V_1 ] . V_53 )
V_45 = V_49 ;
} else if ( F_19 ( V_16 ) ) {
V_52 = V_39 ;
V_34 = F_6 ( V_39 ) ;
} else if ( F_20 ( V_16 ) ) {
V_52 = V_40 ;
V_34 = F_6 ( V_40 ) ;
} else {
F_21 ( 1 , L_1 ) ;
V_52 = V_39 ;
V_34 = F_6 ( V_39 ) ;
}
F_29 ( F_30 ( V_1 , 9 ) ,
V_52 [ V_35 ] . V_50 | V_45 ) ;
F_29 ( F_31 ( V_1 , 9 ) ,
V_52 [ V_35 ] . V_51 ) ;
}
static void F_33 ( struct V_15 * V_16 ,
enum V_1 V_1 )
{
T_2 V_54 = F_34 ( V_1 ) ;
int V_46 ;
for ( V_46 = 0 ; V_46 < 16 ; V_46 ++ ) {
F_35 ( 1 ) ;
if ( F_36 ( V_54 ) & V_55 )
return;
}
F_37 ( L_2 , F_38 ( V_1 ) ) ;
}
static T_3 F_39 ( struct V_56 * V_57 )
{
switch ( V_57 -> V_58 ) {
case V_59 :
return V_60 ;
case V_61 :
return V_62 ;
case V_63 :
return V_64 ;
case V_65 :
return V_66 ;
case V_67 :
return V_68 ;
case V_69 :
return V_70 ;
default:
F_4 ( V_57 -> V_58 ) ;
return V_71 ;
}
}
void F_40 ( struct V_72 * V_73 ,
const struct V_74 * V_75 )
{
struct V_76 * V_44 = V_73 -> V_5 . V_44 ;
struct V_15 * V_16 = F_27 ( V_44 ) ;
struct V_2 * V_3 ;
T_1 V_77 , V_46 , V_78 , V_79 ;
F_41 (dev, &crtc->base, encoder) {
F_28 ( V_3 -> type != V_11 ) ;
F_26 ( V_3 ) ;
}
F_29 ( F_42 ( V_80 ) , F_43 ( 2 ) |
F_44 ( 2 ) |
V_81 | V_82 ) ;
V_78 = V_16 -> V_83 | V_84 |
V_85 |
F_45 ( V_75 -> V_86 ) ;
F_29 ( F_46 ( V_80 ) , V_78 ) ;
F_47 ( F_46 ( V_80 ) ) ;
F_35 ( 220 ) ;
V_78 |= V_87 ;
F_29 ( F_46 ( V_80 ) , V_78 ) ;
V_79 = F_39 ( V_75 -> V_88 ) ;
F_29 ( F_48 ( V_12 ) , V_79 ) ;
F_28 ( V_79 != V_64 ) ;
for ( V_46 = 0 ; V_46 < F_6 ( V_43 ) * 2 ; V_46 ++ ) {
F_29 ( F_49 ( V_12 ) ,
V_89 |
V_90 |
V_91 |
V_92 ) ;
F_29 ( F_34 ( V_12 ) ,
V_93 |
( ( V_75 -> V_86 - 1 ) << 1 ) |
F_50 ( V_46 / 2 ) ) ;
F_47 ( F_34 ( V_12 ) ) ;
F_35 ( 600 ) ;
F_29 ( F_51 ( V_80 ) , F_52 ( 64 ) ) ;
V_78 |= V_94 | V_95 ;
F_29 ( F_46 ( V_80 ) , V_78 ) ;
F_47 ( F_46 ( V_80 ) ) ;
F_35 ( 30 ) ;
V_77 = F_36 ( F_42 ( V_80 ) ) ;
V_77 &= ~ ( V_96 | V_97 ) ;
F_29 ( F_42 ( V_80 ) , V_77 ) ;
F_47 ( F_42 ( V_80 ) ) ;
F_35 ( 5 ) ;
V_77 = F_36 ( F_53 ( V_12 ) ) ;
if ( V_77 & V_98 ) {
F_54 ( L_3 , V_46 ) ;
break;
}
if ( V_46 == F_6 ( V_43 ) * 2 - 1 ) {
F_37 ( L_4 ) ;
break;
}
V_78 &= ~ V_94 ;
F_29 ( F_46 ( V_80 ) , V_78 ) ;
F_47 ( F_46 ( V_80 ) ) ;
V_77 = F_36 ( F_34 ( V_12 ) ) ;
V_77 &= ~ V_93 ;
F_29 ( F_34 ( V_12 ) , V_77 ) ;
F_47 ( F_34 ( V_12 ) ) ;
V_77 = F_36 ( F_49 ( V_12 ) ) ;
V_77 &= ~ ( V_92 | V_99 ) ;
V_77 |= V_91 ;
F_29 ( F_49 ( V_12 ) , V_77 ) ;
F_47 ( F_49 ( V_12 ) ) ;
F_33 ( V_16 , V_12 ) ;
V_77 = F_36 ( F_42 ( V_80 ) ) ;
V_77 &= ~ ( V_96 | V_97 ) ;
V_77 |= F_43 ( 2 ) | F_44 ( 2 ) ;
F_29 ( F_42 ( V_80 ) , V_77 ) ;
F_47 ( F_42 ( V_80 ) ) ;
}
F_29 ( F_49 ( V_12 ) ,
V_89 |
V_100 |
V_90 |
V_92 ) ;
}
static void F_55 ( struct V_2 * V_3 )
{
struct V_101 * V_101 = F_56 ( & V_3 -> V_5 ) ;
struct V_102 * V_103 =
F_3 ( & V_3 -> V_5 ) ;
V_101 -> V_104 = V_103 -> V_105 |
V_93 | F_50 ( 0 ) ;
V_101 -> V_104 |= F_57 ( V_101 -> V_106 ) ;
}
static struct V_2 *
F_58 ( struct V_72 * V_73 )
{
struct V_76 * V_44 = V_73 -> V_5 . V_44 ;
struct V_2 * V_3 , * V_107 = NULL ;
int V_108 = 0 ;
F_41 (dev, &crtc->base, encoder) {
V_107 = V_3 ;
V_108 ++ ;
}
if ( V_108 != 1 )
F_21 ( 1 , L_5 , V_108 ,
F_59 ( V_73 -> V_109 ) ) ;
F_60 ( V_107 == NULL ) ;
return V_107 ;
}
struct V_2 *
F_61 ( struct V_74 * V_75 )
{
struct V_72 * V_73 = F_62 ( V_75 -> V_5 . V_73 ) ;
struct V_2 * V_107 = NULL ;
struct V_110 * V_111 ;
struct V_112 * V_113 ;
struct V_114 * V_115 ;
int V_108 = 0 ;
int V_46 ;
V_111 = V_75 -> V_5 . V_111 ;
F_63 (state, connector, connector_state, i) {
if ( V_115 -> V_73 != V_75 -> V_5 . V_73 )
continue;
V_107 = F_64 ( V_115 -> V_116 ) ;
V_108 ++ ;
}
F_21 ( V_108 != 1 , L_5 , V_108 ,
F_59 ( V_73 -> V_109 ) ) ;
F_60 ( V_107 == NULL ) ;
return V_107 ;
}
static int F_65 ( struct V_15 * V_16 ,
T_2 V_54 )
{
int V_117 = V_118 ;
int V_119 , V_120 , V_121 ;
T_1 V_122 ;
V_122 = F_36 ( V_54 ) ;
switch ( V_122 & V_123 ) {
case V_124 :
case V_125 :
V_117 = 135 ;
break;
case V_126 :
V_117 = V_118 ;
break;
default:
F_21 ( 1 , L_6 ) ;
return 0 ;
}
V_121 = V_122 & V_127 ;
V_120 = ( V_122 & V_128 ) >> V_129 ;
V_119 = ( V_122 & V_130 ) >> V_131 ;
return ( V_117 * V_119 * 100 ) / ( V_120 * V_121 ) ;
}
static int F_66 ( struct V_15 * V_16 ,
T_3 V_132 )
{
T_2 V_133 , V_134 ;
T_3 V_135 , V_136 ;
T_3 V_137 , V_138 , V_139 , V_140 ;
V_133 = F_67 ( V_132 ) ;
V_134 = F_68 ( V_132 ) ;
V_135 = F_36 ( V_133 ) ;
V_136 = F_36 ( V_134 ) ;
V_137 = V_136 & V_141 ;
V_139 = V_136 & V_142 ;
if ( V_136 & F_69 ( 1 ) )
V_138 = ( V_136 & V_143 ) >> 8 ;
else
V_138 = 1 ;
switch ( V_137 ) {
case V_144 :
V_137 = 1 ;
break;
case V_145 :
V_137 = 2 ;
break;
case V_146 :
V_137 = 3 ;
break;
case V_147 :
V_137 = 7 ;
break;
}
switch ( V_139 ) {
case V_148 :
V_139 = 5 ;
break;
case V_149 :
V_139 = 2 ;
break;
case V_150 :
V_139 = 3 ;
break;
case V_151 :
V_139 = 1 ;
break;
}
V_140 = ( V_135 & V_152 ) * 24 * 1000 ;
V_140 += ( ( ( V_135 & V_153 ) >> 9 ) * 24 *
1000 ) / 0x8000 ;
return V_140 / ( V_137 * V_138 * V_139 * 5 ) ;
}
static void F_70 ( struct V_74 * V_154 )
{
int V_155 ;
if ( V_154 -> V_156 )
V_155 = F_71 ( V_154 -> V_157 ,
& V_154 -> V_158 ) ;
else if ( F_72 ( V_154 ) )
V_155 = F_71 ( V_154 -> V_157 ,
& V_154 -> V_159 ) ;
else if ( V_154 -> V_160 && V_154 -> V_161 == 36 )
V_155 = V_154 -> V_157 * 2 / 3 ;
else
V_155 = V_154 -> V_157 ;
if ( V_154 -> V_162 )
V_155 /= V_154 -> V_162 ;
V_154 -> V_5 . V_163 . V_164 = V_155 ;
}
static void F_73 ( struct V_2 * V_3 ,
struct V_74 * V_154 )
{
struct V_15 * V_16 = F_27 ( V_3 -> V_5 . V_44 ) ;
int V_165 = 0 ;
T_3 V_166 , V_132 ;
V_132 = F_74 ( V_16 , V_154 -> V_88 ) ;
V_166 = F_36 ( V_167 ) ;
if ( V_166 & F_75 ( V_132 ) ) {
V_165 = F_66 ( V_16 , V_132 ) ;
} else {
V_165 = V_166 & F_76 ( V_132 ) ;
V_165 >>= F_77 ( V_132 ) ;
switch ( V_165 ) {
case V_168 :
V_165 = 81000 ;
break;
case V_169 :
V_165 = 108000 ;
break;
case V_170 :
V_165 = 135000 ;
break;
case V_171 :
V_165 = 162000 ;
break;
case V_172 :
V_165 = 216000 ;
break;
case V_173 :
V_165 = 270000 ;
break;
default:
F_21 ( 1 , L_7 ) ;
break;
}
V_165 *= 2 ;
}
V_154 -> V_157 = V_165 ;
F_70 ( V_154 ) ;
}
static void F_78 ( struct V_2 * V_3 ,
struct V_74 * V_154 )
{
struct V_15 * V_16 = F_27 ( V_3 -> V_5 . V_44 ) ;
int V_165 = 0 ;
T_1 V_174 , V_57 ;
V_174 = F_39 ( V_154 -> V_88 ) ;
switch ( V_174 & V_175 ) {
case V_66 :
V_165 = 81000 ;
break;
case V_68 :
V_165 = 135000 ;
break;
case V_70 :
V_165 = 270000 ;
break;
case V_60 :
V_165 = F_65 ( V_16 , F_79 ( 0 ) ) ;
break;
case V_62 :
V_165 = F_65 ( V_16 , F_79 ( 1 ) ) ;
break;
case V_64 :
V_57 = F_36 ( V_176 ) & V_177 ;
if ( V_57 == V_178 )
V_165 = 81000 ;
else if ( V_57 == V_179 )
V_165 = 135000 ;
else if ( V_57 == V_180 )
V_165 = 270000 ;
else {
F_21 ( 1 , L_8 ) ;
return;
}
break;
default:
F_21 ( 1 , L_9 ) ;
return;
}
V_154 -> V_157 = V_165 * 2 ;
F_70 ( V_154 ) ;
}
static int F_80 ( struct V_15 * V_16 ,
enum V_181 V_132 )
{
struct V_56 * V_57 ;
struct V_182 * V_111 ;
struct V_132 clock ;
if ( F_28 ( V_132 == V_183 ) )
return 0 ;
V_57 = & V_16 -> V_184 [ V_132 ] ;
V_111 = & V_57 -> V_111 . V_185 ;
clock . V_186 = 2 ;
clock . V_187 = ( V_111 -> V_188 & V_189 ) << 22 ;
if ( V_111 -> V_190 & V_191 )
clock . V_187 |= V_111 -> V_192 & V_193 ;
clock . V_119 = ( V_111 -> V_194 & V_195 ) >> V_196 ;
clock . V_138 = ( V_111 -> V_197 & V_198 ) >> V_199 ;
clock . V_139 = ( V_111 -> V_197 & V_200 ) >> V_201 ;
return F_81 ( 100000 , & clock ) ;
}
static void F_82 ( struct V_2 * V_3 ,
struct V_74 * V_154 )
{
struct V_15 * V_16 = F_27 ( V_3 -> V_5 . V_44 ) ;
enum V_1 V_1 = F_1 ( V_3 ) ;
T_3 V_132 = V_1 ;
V_154 -> V_157 = F_80 ( V_16 , V_132 ) ;
F_70 ( V_154 ) ;
}
void F_83 ( struct V_2 * V_3 ,
struct V_74 * V_154 )
{
struct V_15 * V_16 = F_27 ( V_3 -> V_5 . V_44 ) ;
if ( F_84 ( V_16 ) <= 8 )
F_78 ( V_3 , V_154 ) ;
else if ( F_18 ( V_16 ) )
F_73 ( V_3 , V_154 ) ;
else if ( F_17 ( V_16 ) )
F_82 ( V_3 , V_154 ) ;
}
void F_85 ( const struct V_74 * V_75 )
{
struct V_72 * V_73 = F_62 ( V_75 -> V_5 . V_73 ) ;
struct V_15 * V_16 = F_27 ( V_73 -> V_5 . V_44 ) ;
struct V_2 * V_3 = F_58 ( V_73 ) ;
enum V_202 V_203 = V_75 -> V_203 ;
int type = V_3 -> type ;
T_3 V_77 ;
if ( type == V_7 || type == V_8 || type == V_4 ) {
F_28 ( F_86 ( V_203 ) ) ;
V_77 = V_204 ;
switch ( V_75 -> V_161 ) {
case 18 :
V_77 |= V_205 ;
break;
case 24 :
V_77 |= V_206 ;
break;
case 30 :
V_77 |= V_207 ;
break;
case 36 :
V_77 |= V_208 ;
break;
default:
F_87 () ;
}
F_29 ( F_88 ( V_203 ) , V_77 ) ;
}
}
void F_89 ( const struct V_74 * V_75 ,
bool V_111 )
{
struct V_72 * V_73 = F_62 ( V_75 -> V_5 . V_73 ) ;
struct V_15 * V_16 = F_27 ( V_73 -> V_5 . V_44 ) ;
enum V_202 V_203 = V_75 -> V_203 ;
T_3 V_77 ;
V_77 = F_36 ( F_90 ( V_203 ) ) ;
if ( V_111 == true )
V_77 |= V_209 ;
else
V_77 &= ~ V_209 ;
F_29 ( F_90 ( V_203 ) , V_77 ) ;
}
void F_91 ( const struct V_74 * V_75 )
{
struct V_72 * V_73 = F_62 ( V_75 -> V_5 . V_73 ) ;
struct V_2 * V_3 = F_58 ( V_73 ) ;
struct V_15 * V_16 = F_27 ( V_73 -> V_5 . V_44 ) ;
enum V_109 V_109 = V_73 -> V_109 ;
enum V_202 V_203 = V_75 -> V_203 ;
enum V_1 V_1 = F_1 ( V_3 ) ;
int type = V_3 -> type ;
T_3 V_77 ;
V_77 = V_210 ;
V_77 |= F_92 ( V_1 ) ;
switch ( V_75 -> V_161 ) {
case 18 :
V_77 |= V_211 ;
break;
case 24 :
V_77 |= V_212 ;
break;
case 30 :
V_77 |= V_213 ;
break;
case 36 :
V_77 |= V_214 ;
break;
default:
F_87 () ;
}
if ( V_75 -> V_5 . V_163 . V_215 & V_216 )
V_77 |= V_217 ;
if ( V_75 -> V_5 . V_163 . V_215 & V_218 )
V_77 |= V_219 ;
if ( V_203 == V_220 ) {
switch ( V_109 ) {
case V_80 :
if ( F_20 ( V_16 ) &&
( V_75 -> V_221 . V_222 ||
V_75 -> V_221 . V_223 ) )
V_77 |= V_224 ;
else
V_77 |= V_225 ;
break;
case V_226 :
V_77 |= V_227 ;
break;
case V_228 :
V_77 |= V_229 ;
break;
default:
F_87 () ;
break;
}
}
if ( type == V_9 ) {
if ( V_75 -> V_160 )
V_77 |= V_230 ;
else
V_77 |= V_231 ;
if ( V_75 -> V_232 )
V_77 |= V_233 ;
if ( V_75 -> V_234 )
V_77 |= V_235 ;
} else if ( type == V_11 ) {
V_77 |= V_236 ;
V_77 |= ( V_75 -> V_86 - 1 ) << 1 ;
} else if ( type == V_7 ||
type == V_8 ) {
V_77 |= V_237 ;
V_77 |= F_57 ( V_75 -> V_106 ) ;
} else if ( type == V_4 ) {
V_77 |= V_238 ;
V_77 |= F_57 ( V_75 -> V_106 ) ;
} else {
F_21 ( 1 , L_10 ,
V_3 -> type , F_59 ( V_109 ) ) ;
}
F_29 ( F_90 ( V_203 ) , V_77 ) ;
}
void F_93 ( struct V_15 * V_16 ,
enum V_202 V_203 )
{
T_2 V_54 = F_90 ( V_203 ) ;
T_3 V_174 = F_36 ( V_54 ) ;
V_174 &= ~ ( V_210 | V_239 | V_209 ) ;
V_174 |= V_240 ;
F_29 ( V_54 , V_174 ) ;
}
bool F_94 ( struct V_241 * V_241 )
{
struct V_76 * V_44 = V_241 -> V_5 . V_44 ;
struct V_15 * V_16 = F_27 ( V_44 ) ;
struct V_2 * V_3 = V_241 -> V_3 ;
int type = V_241 -> V_5 . V_242 ;
enum V_1 V_1 = F_1 ( V_3 ) ;
enum V_109 V_109 = 0 ;
enum V_202 V_203 ;
T_3 V_243 ;
bool V_107 ;
if ( ! F_95 ( V_16 ,
V_3 -> V_244 ) )
return false ;
if ( ! V_3 -> V_245 ( V_3 , & V_109 ) ) {
V_107 = false ;
goto V_246;
}
if ( V_1 == V_13 )
V_203 = V_220 ;
else
V_203 = (enum V_202 ) V_109 ;
V_243 = F_36 ( F_90 ( V_203 ) ) ;
switch ( V_243 & V_247 ) {
case V_230 :
case V_231 :
V_107 = type == V_248 ;
break;
case V_237 :
V_107 = type == V_249 ||
type == V_250 ;
break;
case V_238 :
V_107 = false ;
break;
case V_236 :
V_107 = type == V_251 ;
break;
default:
V_107 = false ;
break;
}
V_246:
F_96 ( V_16 , V_3 -> V_244 ) ;
return V_107 ;
}
bool F_97 ( struct V_2 * V_3 ,
enum V_109 * V_109 )
{
struct V_76 * V_44 = V_3 -> V_5 . V_44 ;
struct V_15 * V_16 = F_27 ( V_44 ) ;
enum V_1 V_1 = F_1 ( V_3 ) ;
T_1 V_243 ;
int V_46 ;
bool V_107 ;
if ( ! F_95 ( V_16 ,
V_3 -> V_244 ) )
return false ;
V_107 = false ;
V_243 = F_36 ( F_34 ( V_1 ) ) ;
if ( ! ( V_243 & V_93 ) )
goto V_246;
if ( V_1 == V_13 ) {
V_243 = F_36 ( F_90 ( V_220 ) ) ;
switch ( V_243 & V_252 ) {
case V_225 :
case V_224 :
* V_109 = V_80 ;
break;
case V_227 :
* V_109 = V_226 ;
break;
case V_229 :
* V_109 = V_228 ;
break;
}
V_107 = true ;
goto V_246;
}
for ( V_46 = V_253 ; V_46 <= V_254 ; V_46 ++ ) {
V_243 = F_36 ( F_90 ( V_46 ) ) ;
if ( ( V_243 & V_239 ) == F_92 ( V_1 ) ) {
if ( ( V_243 & V_247 ) ==
V_238 )
goto V_246;
* V_109 = V_46 ;
V_107 = true ;
goto V_246;
}
}
F_54 ( L_11 , F_38 ( V_1 ) ) ;
V_246:
if ( V_107 && F_17 ( V_16 ) ) {
V_243 = F_36 ( F_98 ( V_1 ) ) ;
if ( ( V_243 & ( V_255 |
V_256 ) ) != V_256 )
F_37 ( L_12
L_13 , F_38 ( V_1 ) , V_243 ) ;
}
F_96 ( V_16 , V_3 -> V_244 ) ;
return V_107 ;
}
static T_4 F_99 ( struct V_2 * V_3 )
{
struct V_102 * V_257 = F_3 ( & V_3 -> V_5 ) ;
enum V_109 V_109 ;
if ( F_97 ( V_3 , & V_109 ) )
return F_100 ( V_257 -> V_258 ) ;
return 0 ;
}
void F_101 ( const struct V_74 * V_75 )
{
struct V_72 * V_73 = F_62 ( V_75 -> V_5 . V_73 ) ;
struct V_15 * V_16 = F_27 ( V_73 -> V_5 . V_44 ) ;
struct V_2 * V_3 = F_58 ( V_73 ) ;
enum V_1 V_1 = F_1 ( V_3 ) ;
enum V_202 V_203 = V_75 -> V_203 ;
if ( V_203 != V_220 )
F_29 ( F_102 ( V_203 ) ,
F_103 ( V_1 ) ) ;
}
void F_104 ( const struct V_74 * V_75 )
{
struct V_15 * V_16 = F_27 ( V_75 -> V_5 . V_73 -> V_44 ) ;
enum V_202 V_203 = V_75 -> V_203 ;
if ( V_203 != V_220 )
F_29 ( F_102 ( V_203 ) ,
V_259 ) ;
}
static void F_105 ( struct V_15 * V_16 ,
enum V_1 V_1 , T_5 V_260 )
{
T_1 V_243 ;
V_243 = F_36 ( V_261 ) ;
V_243 &= ~ ( F_106 ( V_1 ) | F_107 ( V_1 ) ) ;
if ( V_260 )
V_243 |= V_260 << F_108 ( V_1 ) ;
else
V_243 |= F_107 ( V_1 ) ;
F_29 ( V_261 , V_243 ) ;
}
static void F_109 ( struct V_2 * V_3 , T_1 V_262 )
{
struct V_102 * V_103 = F_3 ( & V_3 -> V_5 ) ;
struct V_15 * V_16 = F_27 ( V_103 -> V_5 . V_5 . V_44 ) ;
enum V_1 V_1 = V_103 -> V_1 ;
int type = V_3 -> type ;
const struct V_14 * V_47 ;
T_5 V_260 ;
T_5 V_263 , V_264 ;
int V_17 ;
V_263 = V_16 -> V_18 . V_37 [ V_1 ] . V_48 ;
V_264 = V_16 -> V_18 . V_37 [ V_1 ] . V_53 ;
if ( type == V_7 ) {
if ( V_263 ) {
V_260 = V_263 ;
} else {
if ( F_14 ( V_16 ) )
V_47 = F_10 ( V_16 ,
& V_17 ) ;
else
V_47 = F_7 ( V_16 ,
& V_17 ) ;
V_260 = V_47 [ V_262 ] . V_265 ;
}
} else if ( type == V_8 ) {
if ( V_263 ) {
V_260 = V_263 ;
} else {
V_47 = F_13 ( V_16 , & V_17 ) ;
if ( F_28 ( V_1 != V_13 &&
V_1 != V_12 && V_17 > 9 ) )
V_17 = 9 ;
V_260 = V_47 [ V_262 ] . V_265 ;
}
} else if ( type == V_9 ) {
if ( V_264 ) {
V_260 = V_264 ;
} else {
V_47 = F_15 ( V_16 , & V_17 ) ;
V_260 = V_47 [ V_262 ] . V_265 ;
}
} else {
return;
}
if ( V_260 && V_260 != 0x1 && V_260 != 0x3 && V_260 != 0x7 ) {
F_37 ( L_14 , V_260 ) ;
return;
}
F_105 ( V_16 , V_1 , V_260 ) ;
if ( V_1 == V_13 && V_103 -> V_266 == 4 )
F_105 ( V_16 , V_12 , V_260 ) ;
}
static void F_110 ( struct V_15 * V_16 ,
T_1 V_262 , enum V_1 V_1 , int type )
{
const struct V_267 * V_47 ;
T_1 V_17 , V_46 ;
if ( type == V_8 && V_16 -> V_18 . V_19 . V_20 ) {
V_17 = F_6 ( V_268 ) ;
V_47 = V_268 ;
} else if ( type == V_7
|| type == V_8 ) {
V_17 = F_6 ( V_269 ) ;
V_47 = V_269 ;
} else if ( type == V_9 ) {
V_17 = F_6 ( V_270 ) ;
V_47 = V_270 ;
} else {
F_54 ( L_15 ,
type ) ;
return;
}
if ( V_262 >= V_17 ||
( type == V_9 && V_262 == V_41 ) ) {
for ( V_46 = 0 ; V_46 < V_17 ; V_46 ++ ) {
if ( V_47 [ V_46 ] . V_271 ) {
V_262 = V_46 ;
break;
}
}
}
F_111 ( V_16 , V_1 ,
V_47 [ V_262 ] . V_272 ,
V_47 [ V_262 ] . V_273 ,
V_47 [ V_262 ] . V_274 ,
V_47 [ V_262 ] . V_275 ) ;
}
T_6 F_112 ( struct V_2 * V_3 )
{
struct V_15 * V_16 = F_27 ( V_3 -> V_5 . V_44 ) ;
int V_17 ;
if ( V_3 -> type == V_8 )
F_24 ( V_16 , & V_17 ) ;
else
F_22 ( V_16 , & V_17 ) ;
if ( F_28 ( V_17 < 1 ) )
V_17 = 1 ;
if ( F_28 ( V_17 > F_6 ( V_276 ) ) )
V_17 = F_6 ( V_276 ) ;
return V_276 [ V_17 - 1 ] &
V_277 ;
}
static T_3 F_113 ( int V_278 )
{
int V_46 ;
for ( V_46 = 0 ; V_46 < F_6 ( V_276 ) ; V_46 ++ ) {
if ( V_276 [ V_46 ] == V_278 )
return V_46 ;
}
F_21 ( 1 , L_16 ,
V_278 ) ;
return 0 ;
}
T_3 F_114 ( struct V_101 * V_101 )
{
struct V_102 * V_279 = F_115 ( V_101 ) ;
struct V_15 * V_16 = F_27 ( V_279 -> V_5 . V_5 . V_44 ) ;
struct V_2 * V_3 = & V_279 -> V_5 ;
T_5 V_280 = V_101 -> V_280 [ 0 ] ;
int V_278 = V_280 & ( V_277 |
V_281 ) ;
enum V_1 V_1 = V_279 -> V_1 ;
T_3 V_262 ;
V_262 = F_113 ( V_278 ) ;
if ( F_18 ( V_16 ) )
F_109 ( V_3 , V_262 ) ;
else if ( F_17 ( V_16 ) )
F_110 ( V_16 , V_262 , V_1 , V_3 -> type ) ;
return F_50 ( V_262 ) ;
}
static void F_116 ( struct V_2 * V_3 ,
struct V_56 * V_57 )
{
struct V_15 * V_16 = F_27 ( V_3 -> V_5 . V_44 ) ;
enum V_1 V_1 = F_1 ( V_3 ) ;
if ( F_28 ( ! V_57 ) )
return;
if ( F_18 ( V_16 ) ) {
T_3 V_174 ;
V_174 = F_36 ( V_282 ) ;
V_174 &= ~ ( F_117 ( V_1 ) |
F_118 ( V_1 ) ) ;
V_174 |= ( F_119 ( V_57 -> V_58 , V_1 ) |
F_120 ( V_1 ) ) ;
F_29 ( V_282 , V_174 ) ;
} else if ( F_121 ( V_16 ) -> V_283 < 9 ) {
F_29 ( F_48 ( V_1 ) , F_39 ( V_57 ) ) ;
}
}
static void F_122 ( struct V_2 * V_3 ,
int V_284 , T_3 V_106 ,
struct V_56 * V_57 ,
bool V_285 )
{
struct V_101 * V_101 = F_56 ( & V_3 -> V_5 ) ;
struct V_15 * V_16 = F_27 ( V_3 -> V_5 . V_44 ) ;
enum V_1 V_1 = F_1 ( V_3 ) ;
struct V_102 * V_257 = F_3 ( & V_3 -> V_5 ) ;
F_28 ( V_285 && ( V_1 == V_13 || V_1 == V_12 ) ) ;
F_123 ( V_101 , V_284 , V_106 ,
V_285 ) ;
if ( V_3 -> type == V_8 )
F_124 ( V_101 ) ;
F_116 ( V_3 , V_57 ) ;
F_125 ( V_16 , V_257 -> V_258 ) ;
F_26 ( V_3 ) ;
F_55 ( V_3 ) ;
F_126 ( V_101 , V_286 ) ;
F_127 ( V_101 ) ;
if ( V_1 != V_13 || F_84 ( V_16 ) >= 9 )
F_128 ( V_101 ) ;
}
static void F_129 ( struct V_2 * V_3 ,
bool V_160 ,
const struct V_74 * V_75 ,
const struct V_114 * V_287 ,
struct V_56 * V_57 )
{
struct V_288 * V_288 = F_130 ( & V_3 -> V_5 ) ;
struct V_15 * V_16 = F_27 ( V_3 -> V_5 . V_44 ) ;
struct V_289 * V_289 = & V_3 -> V_5 ;
enum V_1 V_1 = F_1 ( V_3 ) ;
int V_262 = F_16 ( V_16 , V_1 ) ;
struct V_102 * V_257 = F_3 ( & V_3 -> V_5 ) ;
F_131 ( V_288 , true ) ;
F_116 ( V_3 , V_57 ) ;
F_125 ( V_16 , V_257 -> V_258 ) ;
F_32 ( V_3 ) ;
if ( F_18 ( V_16 ) )
F_109 ( V_3 , V_262 ) ;
else if ( F_17 ( V_16 ) )
F_110 ( V_16 , V_262 , V_1 ,
V_9 ) ;
V_288 -> V_290 ( V_289 ,
V_160 ,
V_75 , V_287 ) ;
}
static void F_132 ( struct V_2 * V_3 ,
struct V_74 * V_154 ,
struct V_114 * V_287 )
{
int type = V_3 -> type ;
if ( type == V_7 || type == V_8 ) {
F_122 ( V_3 ,
V_154 -> V_157 ,
V_154 -> V_106 ,
V_154 -> V_88 ,
F_133 ( V_154 ,
V_4 ) ) ;
}
if ( type == V_9 ) {
F_129 ( V_3 ,
V_154 -> V_160 ,
V_154 , V_287 ,
V_154 -> V_88 ) ;
}
}
static void F_134 ( struct V_2 * V_2 ,
struct V_74 * V_291 ,
struct V_114 * V_292 )
{
struct V_289 * V_3 = & V_2 -> V_5 ;
struct V_15 * V_16 = F_27 ( V_3 -> V_44 ) ;
enum V_1 V_1 = F_1 ( V_2 ) ;
struct V_102 * V_257 = F_3 ( V_3 ) ;
int type = V_2 -> type ;
T_3 V_174 ;
bool V_293 = false ;
V_174 = F_36 ( F_34 ( V_1 ) ) ;
if ( V_174 & V_93 ) {
V_174 &= ~ V_93 ;
F_29 ( F_34 ( V_1 ) , V_174 ) ;
V_293 = true ;
}
V_174 = F_36 ( F_49 ( V_1 ) ) ;
V_174 &= ~ ( V_92 | V_99 ) ;
V_174 |= V_91 ;
F_29 ( F_49 ( V_1 ) , V_174 ) ;
if ( V_293 )
F_33 ( V_16 , V_1 ) ;
if ( type == V_7 || type == V_8 ) {
struct V_101 * V_101 = F_56 ( V_3 ) ;
F_126 ( V_101 , V_294 ) ;
F_135 ( V_101 ) ;
F_136 ( V_101 ) ;
}
if ( V_257 )
F_96 ( V_16 , V_257 -> V_258 ) ;
if ( F_18 ( V_16 ) )
F_29 ( V_282 , ( F_36 ( V_282 ) |
F_117 ( V_1 ) ) ) ;
else if ( F_84 ( V_16 ) < 9 )
F_29 ( F_48 ( V_1 ) , V_71 ) ;
if ( type == V_9 ) {
struct V_288 * V_288 = F_130 ( V_3 ) ;
F_131 ( V_288 , false ) ;
}
}
void F_137 ( struct V_2 * V_3 ,
struct V_74 * V_291 ,
struct V_114 * V_292 )
{
struct V_15 * V_16 = F_27 ( V_3 -> V_5 . V_44 ) ;
T_3 V_174 ;
V_174 = F_36 ( F_46 ( V_80 ) ) ;
V_174 &= ~ V_94 ;
F_29 ( F_46 ( V_80 ) , V_174 ) ;
F_134 ( V_3 , V_291 , V_292 ) ;
V_174 = F_36 ( F_42 ( V_80 ) ) ;
V_174 &= ~ ( V_96 | V_97 ) ;
V_174 |= F_43 ( 2 ) | F_44 ( 2 ) ;
F_29 ( F_42 ( V_80 ) , V_174 ) ;
V_174 = F_36 ( F_46 ( V_80 ) ) ;
V_174 &= ~ V_87 ;
F_29 ( F_46 ( V_80 ) , V_174 ) ;
V_174 = F_36 ( F_46 ( V_80 ) ) ;
V_174 &= ~ V_85 ;
F_29 ( F_46 ( V_80 ) , V_174 ) ;
}
static void F_138 ( struct V_2 * V_2 ,
struct V_74 * V_154 ,
struct V_114 * V_287 )
{
struct V_289 * V_3 = & V_2 -> V_5 ;
struct V_15 * V_16 = F_27 ( V_3 -> V_44 ) ;
enum V_1 V_1 = F_1 ( V_2 ) ;
int type = V_2 -> type ;
if ( type == V_9 ) {
struct V_102 * V_103 =
F_3 ( V_3 ) ;
bool V_295 = V_154 -> V_234 ;
bool V_296 = V_154 -> V_232 ;
F_139 ( V_2 ,
V_287 -> V_113 ,
V_295 , V_296 ) ;
F_29 ( F_34 ( V_1 ) ,
V_103 -> V_105 |
V_93 ) ;
} else if ( type == V_8 ) {
struct V_101 * V_101 = F_56 ( V_3 ) ;
if ( V_1 == V_13 && F_84 ( V_16 ) < 9 )
F_128 ( V_101 ) ;
F_140 ( V_101 ) ;
F_141 ( V_101 ) ;
F_142 ( V_101 , V_154 ) ;
}
if ( V_154 -> V_297 )
F_143 ( V_2 , V_154 , V_287 ) ;
}
static void F_144 ( struct V_2 * V_2 ,
struct V_74 * V_291 ,
struct V_114 * V_292 )
{
struct V_289 * V_3 = & V_2 -> V_5 ;
int type = V_2 -> type ;
if ( V_291 -> V_297 )
F_145 ( V_2 ) ;
if ( type == V_9 ) {
F_139 ( V_2 ,
V_292 -> V_113 ,
false , false ) ;
}
if ( type == V_8 ) {
struct V_101 * V_101 = F_56 ( V_3 ) ;
F_146 ( V_101 , V_291 ) ;
F_147 ( V_101 ) ;
F_148 ( V_101 ) ;
}
}
static void F_149 ( struct V_2 * V_3 ,
struct V_74 * V_154 ,
struct V_114 * V_287 )
{
T_5 V_298 = V_154 -> V_299 ;
F_150 ( V_3 , V_298 ) ;
}
void F_151 ( struct V_101 * V_101 )
{
struct V_102 * V_103 = F_115 ( V_101 ) ;
struct V_15 * V_16 =
F_27 ( V_103 -> V_5 . V_5 . V_44 ) ;
enum V_1 V_1 = V_103 -> V_1 ;
T_3 V_174 ;
bool V_293 = false ;
if ( F_36 ( F_49 ( V_1 ) ) & V_92 ) {
V_174 = F_36 ( F_34 ( V_1 ) ) ;
if ( V_174 & V_93 ) {
V_174 &= ~ V_93 ;
F_29 ( F_34 ( V_1 ) , V_174 ) ;
V_293 = true ;
}
V_174 = F_36 ( F_49 ( V_1 ) ) ;
V_174 &= ~ ( V_92 | V_99 ) ;
V_174 |= V_91 ;
F_29 ( F_49 ( V_1 ) , V_174 ) ;
F_47 ( F_49 ( V_1 ) ) ;
if ( V_293 )
F_33 ( V_16 , V_1 ) ;
}
V_174 = V_92 |
V_91 | V_300 ;
if ( V_101 -> V_285 )
V_174 |= V_301 ;
else {
V_174 |= V_302 ;
if ( F_152 ( V_101 -> V_303 ) )
V_174 |= V_90 ;
}
F_29 ( F_49 ( V_1 ) , V_174 ) ;
F_47 ( F_49 ( V_1 ) ) ;
V_101 -> V_104 |= V_93 ;
F_29 ( F_34 ( V_1 ) , V_101 -> V_104 ) ;
F_47 ( F_34 ( V_1 ) ) ;
F_35 ( 600 ) ;
}
bool F_153 ( struct V_15 * V_16 ,
struct V_72 * V_72 )
{
T_1 V_77 ;
if ( F_154 ( V_16 , V_304 ) ) {
V_77 = F_36 ( V_305 ) ;
if ( V_77 & F_155 ( V_72 -> V_109 ) )
return true ;
}
return false ;
}
void F_156 ( struct V_2 * V_3 ,
struct V_74 * V_154 )
{
struct V_15 * V_16 = F_27 ( V_3 -> V_5 . V_44 ) ;
struct V_72 * V_72 = F_62 ( V_3 -> V_5 . V_73 ) ;
enum V_202 V_203 = V_154 -> V_203 ;
struct V_288 * V_288 ;
T_1 V_77 , V_215 = 0 ;
if ( F_28 ( F_86 ( V_203 ) ) )
return;
V_77 = F_36 ( F_90 ( V_203 ) ) ;
if ( V_77 & V_219 )
V_215 |= V_218 ;
else
V_215 |= V_306 ;
if ( V_77 & V_217 )
V_215 |= V_216 ;
else
V_215 |= V_307 ;
V_154 -> V_5 . V_163 . V_215 |= V_215 ;
switch ( V_77 & V_308 ) {
case V_211 :
V_154 -> V_161 = 18 ;
break;
case V_212 :
V_154 -> V_161 = 24 ;
break;
case V_213 :
V_154 -> V_161 = 30 ;
break;
case V_214 :
V_154 -> V_161 = 36 ;
break;
default:
break;
}
switch ( V_77 & V_247 ) {
case V_230 :
V_154 -> V_160 = true ;
V_288 = F_130 ( & V_3 -> V_5 ) ;
if ( V_288 -> V_309 ( & V_3 -> V_5 , V_154 ) )
V_154 -> V_310 = true ;
if ( ( V_77 & V_233 ) ==
V_233 )
V_154 -> V_232 = true ;
if ( V_77 & V_235 )
V_154 -> V_234 = true ;
case V_231 :
V_154 -> V_106 = 4 ;
break;
case V_236 :
break;
case V_237 :
case V_238 :
V_154 -> V_106 =
( ( V_77 & V_311 ) >> V_312 ) + 1 ;
F_157 ( V_72 , V_154 ) ;
break;
default:
break;
}
V_154 -> V_297 =
F_153 ( V_16 , V_72 ) ;
if ( V_3 -> type == V_8 && V_16 -> V_18 . V_19 . V_313 &&
V_154 -> V_161 > V_16 -> V_18 . V_19 . V_313 ) {
F_54 ( L_17 ,
V_154 -> V_161 , V_16 -> V_18 . V_19 . V_313 ) ;
V_16 -> V_18 . V_19 . V_313 = V_154 -> V_161 ;
}
F_83 ( V_3 , V_154 ) ;
if ( F_17 ( V_16 ) )
V_154 -> V_299 =
F_158 ( V_3 ) ;
}
static bool F_159 ( struct V_2 * V_3 ,
struct V_74 * V_154 ,
struct V_114 * V_287 )
{
struct V_15 * V_16 = F_27 ( V_3 -> V_5 . V_44 ) ;
int type = V_3 -> type ;
int V_1 = F_1 ( V_3 ) ;
int V_107 ;
F_21 ( type == V_10 , L_18 ) ;
if ( V_1 == V_13 )
V_154 -> V_203 = V_220 ;
if ( type == V_9 )
V_107 = F_160 ( V_3 , V_154 , V_287 ) ;
else
V_107 = F_161 ( V_3 , V_154 , V_287 ) ;
if ( F_17 ( V_16 ) && V_107 )
V_154 -> V_299 =
F_162 ( V_3 ,
V_154 -> V_106 ) ;
return V_107 ;
}
static struct V_241 *
F_163 ( struct V_102 * V_103 )
{
struct V_241 * V_113 ;
enum V_1 V_1 = V_103 -> V_1 ;
V_113 = F_164 () ;
if ( ! V_113 )
return NULL ;
V_103 -> V_314 . V_315 = F_34 ( V_1 ) ;
if ( ! F_165 ( V_103 , V_113 ) ) {
F_166 ( V_113 ) ;
return NULL ;
}
return V_113 ;
}
static struct V_241 *
F_167 ( struct V_102 * V_103 )
{
struct V_241 * V_113 ;
enum V_1 V_1 = V_103 -> V_1 ;
V_113 = F_164 () ;
if ( ! V_113 )
return NULL ;
V_103 -> V_316 . V_317 = F_34 ( V_1 ) ;
F_168 ( V_103 , V_113 ) ;
return V_113 ;
}
void F_169 ( struct V_15 * V_16 , enum V_1 V_1 )
{
struct V_102 * V_103 ;
struct V_2 * V_2 ;
struct V_289 * V_3 ;
bool V_318 , V_319 , V_320 = false ;
int V_266 ;
if ( F_36 ( F_34 ( V_13 ) ) & V_321 ) {
switch ( V_1 ) {
case V_13 :
V_266 = 4 ;
break;
case V_12 :
V_266 = 0 ;
break;
default:
V_266 = 4 ;
break;
}
} else {
switch ( V_1 ) {
case V_13 :
V_266 = 2 ;
break;
case V_12 :
V_266 = 2 ;
break;
default:
V_266 = 4 ;
break;
}
}
V_318 = ( V_16 -> V_18 . V_37 [ V_1 ] . V_322 ||
V_16 -> V_18 . V_37 [ V_1 ] . V_323 ) ;
V_319 = V_16 -> V_18 . V_37 [ V_1 ] . V_324 ;
if ( F_170 ( V_16 , V_1 ) ) {
V_319 = true ;
V_320 = true ;
V_318 = false ;
F_54 ( L_19 , F_38 ( V_1 ) ) ;
}
if ( ! V_319 && ! V_318 ) {
F_54 ( L_20 ,
F_38 ( V_1 ) ) ;
return;
}
V_103 = F_171 ( sizeof( * V_103 ) , V_325 ) ;
if ( ! V_103 )
return;
V_2 = & V_103 -> V_5 ;
V_3 = & V_2 -> V_5 ;
F_172 ( & V_16 -> V_326 , V_3 , & V_327 ,
V_328 , L_21 , F_38 ( V_1 ) ) ;
V_2 -> V_329 = F_159 ;
V_2 -> V_274 = F_138 ;
if ( F_17 ( V_16 ) )
V_2 -> V_330 = F_149 ;
V_2 -> V_331 = F_132 ;
V_2 -> V_332 = F_144 ;
V_2 -> V_333 = F_134 ;
V_2 -> V_245 = F_97 ;
V_2 -> V_334 = F_156 ;
V_2 -> V_335 = V_336 ;
V_2 -> V_337 = F_99 ;
V_103 -> V_1 = V_1 ;
V_103 -> V_105 = F_36 ( F_34 ( V_1 ) ) &
( V_338 |
V_321 ) ;
switch ( V_1 ) {
case V_13 :
V_103 -> V_258 =
V_339 ;
break;
case V_340 :
V_103 -> V_258 =
V_341 ;
break;
case V_342 :
V_103 -> V_258 =
V_343 ;
break;
case V_344 :
V_103 -> V_258 =
V_345 ;
break;
case V_12 :
V_103 -> V_258 =
V_346 ;
break;
default:
F_4 ( V_1 ) ;
}
if ( F_17 ( V_16 ) && V_1 == V_13 ) {
if ( ! ( V_103 -> V_105 & V_321 ) ) {
F_54 ( L_22 ) ;
V_103 -> V_105 |= V_321 ;
V_266 = 4 ;
}
}
V_103 -> V_266 = V_266 ;
V_2 -> type = V_10 ;
V_2 -> V_244 = F_173 ( V_1 ) ;
V_2 -> V_1 = V_1 ;
V_2 -> V_347 = ( 1 << 0 ) | ( 1 << 1 ) | ( 1 << 2 ) ;
V_2 -> V_348 = 0 ;
if ( V_319 ) {
if ( ! F_163 ( V_103 ) )
goto V_349;
V_103 -> V_350 = V_351 ;
V_16 -> V_352 . V_353 [ V_1 ] = V_103 ;
}
if ( V_2 -> type != V_8 && V_318 ) {
if ( ! F_167 ( V_103 ) )
goto V_349;
}
if ( V_320 ) {
if ( F_174 ( V_103 ) )
F_54 ( L_23 ,
F_38 ( V_1 ) ) ;
else
F_37 ( L_24 ,
F_38 ( V_1 ) ) ;
}
return;
V_349:
F_175 ( V_3 ) ;
F_166 ( V_103 ) ;
}
