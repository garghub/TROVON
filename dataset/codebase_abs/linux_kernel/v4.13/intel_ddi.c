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
} else if ( F_12 ( V_16 ) || F_13 ( V_16 ) ) {
* V_17 = F_6 ( V_27 ) ;
return V_27 ;
} else {
* V_17 = F_6 ( V_28 ) ;
return V_28 ;
}
}
static const struct V_14 *
F_14 ( struct V_15 * V_16 , int * V_17 )
{
if ( V_16 -> V_18 . V_19 . V_20 ) {
if ( F_8 ( V_16 ) || F_11 ( V_16 ) ) {
* V_17 = F_6 ( V_29 ) ;
return V_29 ;
} else if ( F_9 ( V_16 ) || F_12 ( V_16 ) ||
F_13 ( V_16 ) ) {
* V_17 = F_6 ( V_30 ) ;
return V_30 ;
} else {
* V_17 = F_6 ( V_31 ) ;
return V_31 ;
}
}
if ( F_15 ( V_16 ) || F_16 ( V_16 ) )
return F_10 ( V_16 , V_17 ) ;
else
return F_7 ( V_16 , V_17 ) ;
}
static const struct V_14 *
F_17 ( struct V_15 * V_16 , int * V_17 )
{
if ( F_8 ( V_16 ) || F_11 ( V_16 ) ) {
* V_17 = F_6 ( V_32 ) ;
return V_32 ;
} else {
* V_17 = F_6 ( V_33 ) ;
return V_33 ;
}
}
static int F_18 ( struct V_15 * V_16 , enum V_1 V_1 )
{
int V_34 ;
int V_35 ;
int V_36 ;
V_35 = V_16 -> V_18 . V_37 [ V_1 ] . V_38 ;
if ( F_19 ( V_16 ) )
return V_35 ;
if ( F_20 ( V_16 ) ) {
F_17 ( V_16 , & V_34 ) ;
V_36 = 8 ;
} else if ( F_21 ( V_16 ) ) {
V_34 = F_6 ( V_39 ) ;
V_36 = 7 ;
} else if ( F_22 ( V_16 ) ) {
V_34 = F_6 ( V_40 ) ;
V_36 = 6 ;
} else {
F_23 ( 1 , L_1 ) ;
V_34 = F_6 ( V_39 ) ;
V_36 = 7 ;
}
if ( V_35 == V_41 ||
V_35 >= V_34 )
V_35 = V_36 ;
return V_35 ;
}
static const struct V_14 *
F_24 ( struct V_15 * V_16 ,
int * V_17 )
{
if ( F_15 ( V_16 ) || F_16 ( V_16 ) ) {
return F_10 ( V_16 , V_17 ) ;
} else if ( F_25 ( V_16 ) ) {
return F_7 ( V_16 , V_17 ) ;
} else if ( F_21 ( V_16 ) ) {
* V_17 = F_6 ( V_22 ) ;
return V_22 ;
} else if ( F_22 ( V_16 ) ) {
* V_17 = F_6 ( V_42 ) ;
return V_42 ;
}
* V_17 = 0 ;
return NULL ;
}
static const struct V_14 *
F_26 ( struct V_15 * V_16 ,
int * V_17 )
{
if ( F_20 ( V_16 ) ) {
return F_14 ( V_16 , V_17 ) ;
} else if ( F_21 ( V_16 ) ) {
return F_5 ( V_16 , V_17 ) ;
} else if ( F_22 ( V_16 ) ) {
* V_17 = F_6 ( V_42 ) ;
return V_42 ;
}
* V_17 = 0 ;
return NULL ;
}
static const struct V_14 *
F_27 ( struct V_15 * V_16 ,
int * V_17 )
{
if ( F_21 ( V_16 ) ) {
* V_17 = F_6 ( V_43 ) ;
return V_43 ;
} else if ( F_22 ( V_16 ) ) {
* V_17 = F_6 ( V_43 ) ;
return V_43 ;
}
* V_17 = 0 ;
return NULL ;
}
static void F_28 ( struct V_2 * V_3 )
{
struct V_15 * V_16 = F_29 ( V_3 -> V_5 . V_44 ) ;
T_1 V_45 = 0 ;
int V_46 , V_17 ;
enum V_1 V_1 = F_1 ( V_3 ) ;
const struct V_14 * V_47 ;
if ( F_19 ( V_16 ) )
return;
switch ( V_3 -> type ) {
case V_8 :
V_47 = F_26 ( V_16 ,
& V_17 ) ;
break;
case V_7 :
V_47 = F_24 ( V_16 ,
& V_17 ) ;
break;
case V_11 :
V_47 = F_27 ( V_16 ,
& V_17 ) ;
break;
default:
F_4 ( V_3 -> type ) ;
return;
}
if ( F_20 ( V_16 ) ) {
if ( V_16 -> V_18 . V_37 [ V_1 ] . V_48 )
V_45 = V_49 ;
if ( F_30 ( V_3 -> type == V_8 &&
V_1 != V_13 && V_1 != V_12 &&
V_17 > 9 ) )
V_17 = 9 ;
}
for ( V_46 = 0 ; V_46 < V_17 ; V_46 ++ ) {
F_31 ( F_32 ( V_1 , V_46 ) ,
V_47 [ V_46 ] . V_50 | V_45 ) ;
F_31 ( F_33 ( V_1 , V_46 ) ,
V_47 [ V_46 ] . V_51 ) ;
}
}
static void F_34 ( struct V_2 * V_3 )
{
struct V_15 * V_16 = F_29 ( V_3 -> V_5 . V_44 ) ;
T_1 V_45 = 0 ;
int V_34 , V_35 ;
enum V_1 V_1 = F_1 ( V_3 ) ;
const struct V_14 * V_52 ;
if ( F_19 ( V_16 ) )
return;
V_35 = F_18 ( V_16 , V_1 ) ;
if ( F_20 ( V_16 ) ) {
V_52 = F_17 ( V_16 , & V_34 ) ;
if ( V_16 -> V_18 . V_37 [ V_1 ] . V_53 )
V_45 = V_49 ;
} else if ( F_21 ( V_16 ) ) {
V_52 = V_39 ;
V_34 = F_6 ( V_39 ) ;
} else if ( F_22 ( V_16 ) ) {
V_52 = V_40 ;
V_34 = F_6 ( V_40 ) ;
} else {
F_23 ( 1 , L_1 ) ;
V_52 = V_39 ;
V_34 = F_6 ( V_39 ) ;
}
F_31 ( F_32 ( V_1 , 9 ) ,
V_52 [ V_35 ] . V_50 | V_45 ) ;
F_31 ( F_33 ( V_1 , 9 ) ,
V_52 [ V_35 ] . V_51 ) ;
}
static void F_35 ( struct V_15 * V_16 ,
enum V_1 V_1 )
{
T_2 V_54 = F_36 ( V_1 ) ;
int V_46 ;
for ( V_46 = 0 ; V_46 < 16 ; V_46 ++ ) {
F_37 ( 1 ) ;
if ( F_38 ( V_54 ) & V_55 )
return;
}
F_39 ( L_2 , F_40 ( V_1 ) ) ;
}
static T_3 F_41 ( struct V_56 * V_57 )
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
void F_42 ( struct V_72 * V_73 ,
const struct V_74 * V_75 )
{
struct V_76 * V_44 = V_73 -> V_5 . V_44 ;
struct V_15 * V_16 = F_29 ( V_44 ) ;
struct V_2 * V_3 ;
T_1 V_77 , V_46 , V_78 , V_79 ;
F_43 (dev, &crtc->base, encoder) {
F_30 ( V_3 -> type != V_11 ) ;
F_28 ( V_3 ) ;
}
F_31 ( F_44 ( V_80 ) , F_45 ( 2 ) |
F_46 ( 2 ) |
V_81 | V_82 ) ;
V_78 = V_16 -> V_83 | V_84 |
V_85 |
F_47 ( V_75 -> V_86 ) ;
F_31 ( F_48 ( V_80 ) , V_78 ) ;
F_49 ( F_48 ( V_80 ) ) ;
F_37 ( 220 ) ;
V_78 |= V_87 ;
F_31 ( F_48 ( V_80 ) , V_78 ) ;
V_79 = F_41 ( V_75 -> V_88 ) ;
F_31 ( F_50 ( V_12 ) , V_79 ) ;
F_30 ( V_79 != V_64 ) ;
for ( V_46 = 0 ; V_46 < F_6 ( V_43 ) * 2 ; V_46 ++ ) {
F_31 ( F_51 ( V_12 ) ,
V_89 |
V_90 |
V_91 |
V_92 ) ;
F_31 ( F_36 ( V_12 ) ,
V_93 |
( ( V_75 -> V_86 - 1 ) << 1 ) |
F_52 ( V_46 / 2 ) ) ;
F_49 ( F_36 ( V_12 ) ) ;
F_37 ( 600 ) ;
F_31 ( F_53 ( V_80 ) , F_54 ( 64 ) ) ;
V_78 |= V_94 | V_95 ;
F_31 ( F_48 ( V_80 ) , V_78 ) ;
F_49 ( F_48 ( V_80 ) ) ;
F_37 ( 30 ) ;
V_77 = F_38 ( F_44 ( V_80 ) ) ;
V_77 &= ~ ( V_96 | V_97 ) ;
F_31 ( F_44 ( V_80 ) , V_77 ) ;
F_49 ( F_44 ( V_80 ) ) ;
F_37 ( 5 ) ;
V_77 = F_38 ( F_55 ( V_12 ) ) ;
if ( V_77 & V_98 ) {
F_56 ( L_3 , V_46 ) ;
break;
}
if ( V_46 == F_6 ( V_43 ) * 2 - 1 ) {
F_39 ( L_4 ) ;
break;
}
V_78 &= ~ V_94 ;
F_31 ( F_48 ( V_80 ) , V_78 ) ;
F_49 ( F_48 ( V_80 ) ) ;
V_77 = F_38 ( F_36 ( V_12 ) ) ;
V_77 &= ~ V_93 ;
F_31 ( F_36 ( V_12 ) , V_77 ) ;
F_49 ( F_36 ( V_12 ) ) ;
V_77 = F_38 ( F_51 ( V_12 ) ) ;
V_77 &= ~ ( V_92 | V_99 ) ;
V_77 |= V_91 ;
F_31 ( F_51 ( V_12 ) , V_77 ) ;
F_49 ( F_51 ( V_12 ) ) ;
F_35 ( V_16 , V_12 ) ;
V_77 = F_38 ( F_44 ( V_80 ) ) ;
V_77 &= ~ ( V_96 | V_97 ) ;
V_77 |= F_45 ( 2 ) | F_46 ( 2 ) ;
F_31 ( F_44 ( V_80 ) , V_77 ) ;
F_49 ( F_44 ( V_80 ) ) ;
}
F_31 ( F_51 ( V_12 ) ,
V_89 |
V_100 |
V_90 |
V_92 ) ;
}
static void F_57 ( struct V_2 * V_3 )
{
struct V_101 * V_101 = F_58 ( & V_3 -> V_5 ) ;
struct V_102 * V_103 =
F_3 ( & V_3 -> V_5 ) ;
V_101 -> V_104 = V_103 -> V_105 |
V_93 | F_52 ( 0 ) ;
V_101 -> V_104 |= F_59 ( V_101 -> V_106 ) ;
}
static struct V_2 *
F_60 ( struct V_72 * V_73 )
{
struct V_76 * V_44 = V_73 -> V_5 . V_44 ;
struct V_2 * V_3 , * V_107 = NULL ;
int V_108 = 0 ;
F_43 (dev, &crtc->base, encoder) {
V_107 = V_3 ;
V_108 ++ ;
}
if ( V_108 != 1 )
F_23 ( 1 , L_5 , V_108 ,
F_61 ( V_73 -> V_109 ) ) ;
F_62 ( V_107 == NULL ) ;
return V_107 ;
}
struct V_2 *
F_63 ( struct V_74 * V_75 )
{
struct V_72 * V_73 = F_64 ( V_75 -> V_5 . V_73 ) ;
struct V_2 * V_107 = NULL ;
struct V_110 * V_111 ;
struct V_112 * V_113 ;
struct V_114 * V_115 ;
int V_108 = 0 ;
int V_46 ;
V_111 = V_75 -> V_5 . V_111 ;
F_65 (state, connector, connector_state, i) {
if ( V_115 -> V_73 != V_75 -> V_5 . V_73 )
continue;
V_107 = F_66 ( V_115 -> V_116 ) ;
V_108 ++ ;
}
F_23 ( V_108 != 1 , L_5 , V_108 ,
F_61 ( V_73 -> V_109 ) ) ;
F_62 ( V_107 == NULL ) ;
return V_107 ;
}
static int F_67 ( struct V_15 * V_16 ,
T_2 V_54 )
{
int V_117 = V_118 ;
int V_119 , V_120 , V_121 ;
T_1 V_122 ;
V_122 = F_38 ( V_54 ) ;
switch ( V_122 & V_123 ) {
case V_124 :
case V_125 :
V_117 = 135 ;
break;
case V_126 :
V_117 = V_118 ;
break;
default:
F_23 ( 1 , L_6 ) ;
return 0 ;
}
V_121 = V_122 & V_127 ;
V_120 = ( V_122 & V_128 ) >> V_129 ;
V_119 = ( V_122 & V_130 ) >> V_131 ;
return ( V_117 * V_119 * 100 ) / ( V_120 * V_121 ) ;
}
static int F_68 ( struct V_15 * V_16 ,
T_3 V_132 )
{
T_2 V_133 , V_134 ;
T_3 V_135 , V_136 ;
T_3 V_137 , V_138 , V_139 , V_140 ;
V_133 = F_69 ( V_132 ) ;
V_134 = F_70 ( V_132 ) ;
V_135 = F_38 ( V_133 ) ;
V_136 = F_38 ( V_134 ) ;
V_137 = V_136 & V_141 ;
V_139 = V_136 & V_142 ;
if ( V_136 & F_71 ( 1 ) )
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
static void F_72 ( struct V_74 * V_154 )
{
int V_155 ;
if ( V_154 -> V_156 )
V_155 = F_73 ( V_154 -> V_157 ,
& V_154 -> V_158 ) ;
else if ( F_74 ( V_154 ) )
V_155 = F_73 ( V_154 -> V_157 ,
& V_154 -> V_159 ) ;
else if ( V_154 -> V_160 && V_154 -> V_161 == 36 )
V_155 = V_154 -> V_157 * 2 / 3 ;
else
V_155 = V_154 -> V_157 ;
if ( V_154 -> V_162 )
V_155 /= V_154 -> V_162 ;
V_154 -> V_5 . V_163 . V_164 = V_155 ;
}
static void F_75 ( struct V_2 * V_3 ,
struct V_74 * V_154 )
{
struct V_15 * V_16 = F_29 ( V_3 -> V_5 . V_44 ) ;
int V_165 = 0 ;
T_3 V_166 , V_132 ;
V_132 = F_76 ( V_16 , V_154 -> V_88 ) ;
V_166 = F_38 ( V_167 ) ;
if ( V_166 & F_77 ( V_132 ) ) {
V_165 = F_68 ( V_16 , V_132 ) ;
} else {
V_165 = V_166 & F_78 ( V_132 ) ;
V_165 >>= F_79 ( V_132 ) ;
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
F_23 ( 1 , L_7 ) ;
break;
}
V_165 *= 2 ;
}
V_154 -> V_157 = V_165 ;
F_72 ( V_154 ) ;
}
static void F_80 ( struct V_2 * V_3 ,
struct V_74 * V_154 )
{
struct V_15 * V_16 = F_29 ( V_3 -> V_5 . V_44 ) ;
int V_165 = 0 ;
T_1 V_174 , V_57 ;
V_174 = F_41 ( V_154 -> V_88 ) ;
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
V_165 = F_67 ( V_16 , F_81 ( 0 ) ) ;
break;
case V_62 :
V_165 = F_67 ( V_16 , F_81 ( 1 ) ) ;
break;
case V_64 :
V_57 = F_38 ( V_176 ) & V_177 ;
if ( V_57 == V_178 )
V_165 = 81000 ;
else if ( V_57 == V_179 )
V_165 = 135000 ;
else if ( V_57 == V_180 )
V_165 = 270000 ;
else {
F_23 ( 1 , L_8 ) ;
return;
}
break;
default:
F_23 ( 1 , L_9 ) ;
return;
}
V_154 -> V_157 = V_165 * 2 ;
F_72 ( V_154 ) ;
}
static int F_82 ( struct V_15 * V_16 ,
enum V_181 V_132 )
{
struct V_56 * V_57 ;
struct V_182 * V_111 ;
struct V_132 clock ;
if ( F_30 ( V_132 == V_183 ) )
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
return F_83 ( 100000 , & clock ) ;
}
static void F_84 ( struct V_2 * V_3 ,
struct V_74 * V_154 )
{
struct V_15 * V_16 = F_29 ( V_3 -> V_5 . V_44 ) ;
enum V_1 V_1 = F_1 ( V_3 ) ;
T_3 V_132 = V_1 ;
V_154 -> V_157 = F_82 ( V_16 , V_132 ) ;
F_72 ( V_154 ) ;
}
void F_85 ( struct V_2 * V_3 ,
struct V_74 * V_154 )
{
struct V_15 * V_16 = F_29 ( V_3 -> V_5 . V_44 ) ;
if ( F_86 ( V_16 ) <= 8 )
F_80 ( V_3 , V_154 ) ;
else if ( F_20 ( V_16 ) )
F_75 ( V_3 , V_154 ) ;
else if ( F_19 ( V_16 ) )
F_84 ( V_3 , V_154 ) ;
}
void F_87 ( const struct V_74 * V_75 )
{
struct V_72 * V_73 = F_64 ( V_75 -> V_5 . V_73 ) ;
struct V_15 * V_16 = F_29 ( V_73 -> V_5 . V_44 ) ;
struct V_2 * V_3 = F_60 ( V_73 ) ;
enum V_202 V_203 = V_75 -> V_203 ;
int type = V_3 -> type ;
T_3 V_77 ;
if ( type == V_7 || type == V_8 || type == V_4 ) {
F_30 ( F_88 ( V_203 ) ) ;
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
F_89 () ;
}
F_31 ( F_90 ( V_203 ) , V_77 ) ;
}
}
void F_91 ( const struct V_74 * V_75 ,
bool V_111 )
{
struct V_72 * V_73 = F_64 ( V_75 -> V_5 . V_73 ) ;
struct V_15 * V_16 = F_29 ( V_73 -> V_5 . V_44 ) ;
enum V_202 V_203 = V_75 -> V_203 ;
T_3 V_77 ;
V_77 = F_38 ( F_92 ( V_203 ) ) ;
if ( V_111 == true )
V_77 |= V_209 ;
else
V_77 &= ~ V_209 ;
F_31 ( F_92 ( V_203 ) , V_77 ) ;
}
void F_93 ( const struct V_74 * V_75 )
{
struct V_72 * V_73 = F_64 ( V_75 -> V_5 . V_73 ) ;
struct V_2 * V_3 = F_60 ( V_73 ) ;
struct V_15 * V_16 = F_29 ( V_73 -> V_5 . V_44 ) ;
enum V_109 V_109 = V_73 -> V_109 ;
enum V_202 V_203 = V_75 -> V_203 ;
enum V_1 V_1 = F_1 ( V_3 ) ;
int type = V_3 -> type ;
T_3 V_77 ;
V_77 = V_210 ;
V_77 |= F_94 ( V_1 ) ;
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
F_89 () ;
}
if ( V_75 -> V_5 . V_163 . V_215 & V_216 )
V_77 |= V_217 ;
if ( V_75 -> V_5 . V_163 . V_215 & V_218 )
V_77 |= V_219 ;
if ( V_203 == V_220 ) {
switch ( V_109 ) {
case V_80 :
if ( F_22 ( V_16 ) &&
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
F_89 () ;
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
V_77 |= F_59 ( V_75 -> V_106 ) ;
} else if ( type == V_4 ) {
V_77 |= V_238 ;
V_77 |= F_59 ( V_75 -> V_106 ) ;
} else {
F_23 ( 1 , L_10 ,
V_3 -> type , F_61 ( V_109 ) ) ;
}
F_31 ( F_92 ( V_203 ) , V_77 ) ;
}
void F_95 ( struct V_15 * V_16 ,
enum V_202 V_203 )
{
T_2 V_54 = F_92 ( V_203 ) ;
T_3 V_174 = F_38 ( V_54 ) ;
V_174 &= ~ ( V_210 | V_239 | V_209 ) ;
V_174 |= V_240 ;
F_31 ( V_54 , V_174 ) ;
}
bool F_96 ( struct V_241 * V_241 )
{
struct V_76 * V_44 = V_241 -> V_5 . V_44 ;
struct V_15 * V_16 = F_29 ( V_44 ) ;
struct V_2 * V_3 = V_241 -> V_3 ;
int type = V_241 -> V_5 . V_242 ;
enum V_1 V_1 = F_1 ( V_3 ) ;
enum V_109 V_109 = 0 ;
enum V_202 V_203 ;
T_3 V_243 ;
bool V_107 ;
if ( ! F_97 ( V_16 ,
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
V_243 = F_38 ( F_92 ( V_203 ) ) ;
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
F_98 ( V_16 , V_3 -> V_244 ) ;
return V_107 ;
}
bool F_99 ( struct V_2 * V_3 ,
enum V_109 * V_109 )
{
struct V_76 * V_44 = V_3 -> V_5 . V_44 ;
struct V_15 * V_16 = F_29 ( V_44 ) ;
enum V_1 V_1 = F_1 ( V_3 ) ;
T_1 V_243 ;
int V_46 ;
bool V_107 ;
if ( ! F_97 ( V_16 ,
V_3 -> V_244 ) )
return false ;
V_107 = false ;
V_243 = F_38 ( F_36 ( V_1 ) ) ;
if ( ! ( V_243 & V_93 ) )
goto V_246;
if ( V_1 == V_13 ) {
V_243 = F_38 ( F_92 ( V_220 ) ) ;
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
V_243 = F_38 ( F_92 ( V_46 ) ) ;
if ( ( V_243 & V_239 ) == F_94 ( V_1 ) ) {
if ( ( V_243 & V_247 ) ==
V_238 )
goto V_246;
* V_109 = V_46 ;
V_107 = true ;
goto V_246;
}
}
F_56 ( L_11 , F_40 ( V_1 ) ) ;
V_246:
if ( V_107 && F_19 ( V_16 ) ) {
V_243 = F_38 ( F_100 ( V_1 ) ) ;
if ( ( V_243 & ( V_255 |
V_256 ) ) != V_256 )
F_39 ( L_12
L_13 , F_40 ( V_1 ) , V_243 ) ;
}
F_98 ( V_16 , V_3 -> V_244 ) ;
return V_107 ;
}
static T_4 F_101 ( struct V_2 * V_3 )
{
struct V_102 * V_257 = F_3 ( & V_3 -> V_5 ) ;
enum V_109 V_109 ;
if ( F_99 ( V_3 , & V_109 ) )
return F_102 ( V_257 -> V_258 ) ;
return 0 ;
}
void F_103 ( const struct V_74 * V_75 )
{
struct V_72 * V_73 = F_64 ( V_75 -> V_5 . V_73 ) ;
struct V_15 * V_16 = F_29 ( V_73 -> V_5 . V_44 ) ;
struct V_2 * V_3 = F_60 ( V_73 ) ;
enum V_1 V_1 = F_1 ( V_3 ) ;
enum V_202 V_203 = V_75 -> V_203 ;
if ( V_203 != V_220 )
F_31 ( F_104 ( V_203 ) ,
F_105 ( V_1 ) ) ;
}
void F_106 ( const struct V_74 * V_75 )
{
struct V_15 * V_16 = F_29 ( V_75 -> V_5 . V_73 -> V_44 ) ;
enum V_202 V_203 = V_75 -> V_203 ;
if ( V_203 != V_220 )
F_31 ( F_104 ( V_203 ) ,
V_259 ) ;
}
static void F_107 ( struct V_15 * V_16 ,
enum V_1 V_1 , T_5 V_260 )
{
T_1 V_243 ;
V_243 = F_38 ( V_261 ) ;
V_243 &= ~ ( F_108 ( V_1 ) | F_109 ( V_1 ) ) ;
if ( V_260 )
V_243 |= V_260 << F_110 ( V_1 ) ;
else
V_243 |= F_109 ( V_1 ) ;
F_31 ( V_261 , V_243 ) ;
}
static void F_111 ( struct V_2 * V_3 , T_1 V_262 )
{
struct V_102 * V_103 = F_3 ( & V_3 -> V_5 ) ;
struct V_15 * V_16 = F_29 ( V_103 -> V_5 . V_5 . V_44 ) ;
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
if ( F_15 ( V_16 ) || F_16 ( V_16 ) )
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
V_47 = F_14 ( V_16 , & V_17 ) ;
if ( F_30 ( V_1 != V_13 &&
V_1 != V_12 && V_17 > 9 ) )
V_17 = 9 ;
V_260 = V_47 [ V_262 ] . V_265 ;
}
} else if ( type == V_9 ) {
if ( V_264 ) {
V_260 = V_264 ;
} else {
V_47 = F_17 ( V_16 , & V_17 ) ;
V_260 = V_47 [ V_262 ] . V_265 ;
}
} else {
return;
}
if ( V_260 && V_260 != 0x1 && V_260 != 0x3 && V_260 != 0x7 ) {
F_39 ( L_14 , V_260 ) ;
return;
}
F_107 ( V_16 , V_1 , V_260 ) ;
if ( V_1 == V_13 && V_103 -> V_266 == 4 )
F_107 ( V_16 , V_12 , V_260 ) ;
}
static void F_112 ( struct V_15 * V_16 ,
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
F_56 ( L_15 ,
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
F_113 ( V_16 , V_1 ,
V_47 [ V_262 ] . V_272 ,
V_47 [ V_262 ] . V_273 ,
V_47 [ V_262 ] . V_274 ,
V_47 [ V_262 ] . V_275 ) ;
}
T_6 F_114 ( struct V_2 * V_3 )
{
struct V_15 * V_16 = F_29 ( V_3 -> V_5 . V_44 ) ;
int V_17 ;
if ( V_3 -> type == V_8 )
F_26 ( V_16 , & V_17 ) ;
else
F_24 ( V_16 , & V_17 ) ;
if ( F_30 ( V_17 < 1 ) )
V_17 = 1 ;
if ( F_30 ( V_17 > F_6 ( V_276 ) ) )
V_17 = F_6 ( V_276 ) ;
return V_276 [ V_17 - 1 ] &
V_277 ;
}
static const struct V_278 *
F_115 ( struct V_15 * V_16 ,
T_1 V_279 , int * V_17 )
{
if ( V_279 == V_280 ) {
* V_17 = F_6 ( V_281 ) ;
return V_281 ;
} else if ( V_279 == V_282 ) {
* V_17 = F_6 ( V_283 ) ;
return V_283 ;
} else if ( V_279 == V_284 ) {
* V_17 = F_6 ( V_285 ) ;
return V_285 ;
}
return NULL ;
}
static const struct V_278 *
F_116 ( struct V_15 * V_16 ,
T_1 V_279 , int * V_17 )
{
if ( V_279 == V_280 ) {
* V_17 = F_6 ( V_286 ) ;
return V_286 ;
} else if ( V_279 == V_282 ) {
* V_17 = F_6 ( V_287 ) ;
return V_287 ;
} else if ( V_279 == V_284 ) {
* V_17 = F_6 ( V_288 ) ;
return V_288 ;
}
return NULL ;
}
static const struct V_278 *
F_117 ( struct V_15 * V_16 ,
T_1 V_279 , int * V_17 )
{
if ( V_16 -> V_18 . V_19 . V_20 ) {
if ( V_279 == V_280 ) {
* V_17 = F_6 ( V_289 ) ;
return V_289 ;
} else if ( V_279 == V_282 ) {
* V_17 = F_6 ( V_290 ) ;
return V_290 ;
} else if ( V_279 == V_284 ) {
* V_17 = F_6 ( V_291 ) ;
return V_291 ;
}
return NULL ;
} else {
return F_116 ( V_16 , V_279 , V_17 ) ;
}
}
static void F_118 ( struct V_15 * V_16 ,
T_1 V_262 , enum V_1 V_1 , int type )
{
const struct V_278 * V_47 = NULL ;
T_1 V_17 , V_174 , V_279 ;
int V_292 ;
V_279 = F_38 ( V_293 ) & V_294 ;
if ( type == V_9 ) {
V_47 = F_115 ( V_16 ,
V_279 , & V_17 ) ;
} else if ( type == V_7 ) {
V_47 = F_116 ( V_16 ,
V_279 , & V_17 ) ;
} else if ( type == V_8 ) {
V_47 = F_117 ( V_16 ,
V_279 , & V_17 ) ;
}
if ( V_47 == NULL ) {
F_4 ( V_279 ) ;
return;
}
if ( V_262 >= V_17 ) {
F_56 ( L_16 , V_262 , V_17 - 1 ) ;
V_262 = V_17 - 1 ;
}
V_174 = F_38 ( F_119 ( V_1 ) ) ;
V_174 &= ~ V_295 ;
V_174 |= F_120 ( 2 ) ;
F_31 ( F_121 ( V_1 ) , V_174 ) ;
V_174 = F_38 ( F_122 ( V_1 ) ) ;
V_174 &= ~ ( V_296 | V_297 |
V_298 ) ;
V_174 |= F_123 ( V_47 [ V_262 ] . V_299 ) ;
V_174 |= F_124 ( V_47 [ V_262 ] . V_299 ) ;
V_174 |= F_125 ( 0x98 ) ;
F_31 ( F_126 ( V_1 ) , V_174 ) ;
for ( V_292 = 0 ; V_292 < 4 ; V_292 ++ ) {
V_174 = F_38 ( F_127 ( V_1 , V_292 ) ) ;
V_174 &= ~ ( V_300 | V_301 |
V_302 ) ;
V_174 |= F_128 ( V_47 [ V_262 ] . V_303 ) ;
V_174 |= F_129 ( V_47 [ V_262 ] . V_304 ) ;
V_174 |= F_130 ( V_47 [ V_262 ] . V_305 ) ;
F_31 ( F_127 ( V_1 , V_292 ) , V_174 ) ;
}
V_174 = F_38 ( F_119 ( V_1 ) ) ;
V_174 &= ~ V_306 ;
V_174 |= F_131 ( 6 ) ;
V_174 |= V_307 ;
F_31 ( F_121 ( V_1 ) , V_174 ) ;
V_174 = F_38 ( F_132 ( V_1 ) ) ;
V_174 &= ~ V_308 ;
V_174 |= F_133 ( V_47 [ V_262 ] . V_309 ) ;
F_31 ( F_134 ( V_1 ) , V_174 ) ;
}
static void F_135 ( struct V_2 * V_3 , T_1 V_262 )
{
struct V_15 * V_16 = F_29 ( V_3 -> V_5 . V_44 ) ;
struct V_101 * V_101 = F_58 ( & V_3 -> V_5 ) ;
enum V_1 V_1 = F_1 ( V_3 ) ;
int type = V_3 -> type ;
int V_310 = 0 ;
int V_311 = 0 ;
T_1 V_174 ;
int V_292 = 0 ;
if ( ( V_101 ) && ( type == V_8 || type == V_7 ) ) {
V_310 = V_101 -> V_106 ;
V_311 = V_101 -> V_312 ;
} else {
V_310 = 4 ;
}
V_174 = F_38 ( F_136 ( V_1 ) ) ;
if ( type == V_8 || type == V_7 )
V_174 |= V_313 ;
else
V_174 &= ~ V_313 ;
F_31 ( F_137 ( V_1 ) , V_174 ) ;
for ( V_292 = 0 ; V_292 <= 3 ; V_292 ++ ) {
V_174 = F_38 ( F_127 ( V_1 , V_292 ) ) ;
V_174 &= ~ V_314 ;
if ( ( V_311 <= 600000 && V_310 == 4 && V_292 >= 1 ) ||
( V_311 <= 600000 && V_310 < 4 && ( V_292 == 1 || V_292 == 2 ) ) ) {
V_174 |= V_314 ;
}
F_31 ( F_127 ( V_1 , V_292 ) , V_174 ) ;
}
V_174 = F_38 ( V_315 ) ;
V_174 |= V_316 ;
F_31 ( V_315 , V_174 ) ;
V_174 = F_38 ( F_119 ( V_1 ) ) ;
V_174 &= ~ V_317 ;
F_31 ( F_121 ( V_1 ) , V_174 ) ;
F_118 ( V_16 , V_262 , V_1 , type ) ;
V_174 = F_38 ( F_119 ( V_1 ) ) ;
V_174 |= V_317 ;
F_31 ( F_121 ( V_1 ) , V_174 ) ;
}
static T_3 F_138 ( int V_318 )
{
int V_46 ;
for ( V_46 = 0 ; V_46 < F_6 ( V_276 ) ; V_46 ++ ) {
if ( V_276 [ V_46 ] == V_318 )
return V_46 ;
}
F_23 ( 1 , L_17 ,
V_318 ) ;
return 0 ;
}
T_3 F_139 ( struct V_101 * V_101 )
{
struct V_102 * V_319 = F_140 ( V_101 ) ;
struct V_15 * V_16 = F_29 ( V_319 -> V_5 . V_5 . V_44 ) ;
struct V_2 * V_3 = & V_319 -> V_5 ;
T_5 V_320 = V_101 -> V_320 [ 0 ] ;
int V_318 = V_320 & ( V_277 |
V_321 ) ;
enum V_1 V_1 = V_319 -> V_1 ;
T_3 V_262 ;
V_262 = F_138 ( V_318 ) ;
if ( F_20 ( V_16 ) )
F_111 ( V_3 , V_262 ) ;
else if ( F_19 ( V_16 ) )
F_112 ( V_16 , V_262 , V_1 , V_3 -> type ) ;
else if ( F_141 ( V_16 ) ) {
F_135 ( V_3 , V_262 ) ;
return 0 ;
}
return F_52 ( V_262 ) ;
}
static void F_142 ( struct V_2 * V_3 ,
struct V_56 * V_57 )
{
struct V_15 * V_16 = F_29 ( V_3 -> V_5 . V_44 ) ;
enum V_1 V_1 = F_1 ( V_3 ) ;
T_3 V_174 ;
if ( F_30 ( ! V_57 ) )
return;
if ( F_141 ( V_16 ) ) {
V_174 = F_38 ( V_322 ) ;
V_174 |= F_143 ( V_57 -> V_58 , V_1 ) ;
F_31 ( V_322 , V_174 ) ;
V_174 = F_38 ( V_322 ) ;
V_174 &= ~ ( F_144 ( V_1 ) |
F_145 ( V_1 ) ) ;
F_31 ( V_322 , V_174 ) ;
} else if ( F_20 ( V_16 ) ) {
V_174 = F_38 ( V_323 ) ;
V_174 &= ~ ( F_146 ( V_1 ) |
F_147 ( V_1 ) ) ;
V_174 |= ( F_148 ( V_57 -> V_58 , V_1 ) |
F_149 ( V_1 ) ) ;
F_31 ( V_323 , V_174 ) ;
} else if ( F_150 ( V_16 ) -> V_324 < 9 ) {
F_31 ( F_50 ( V_1 ) , F_41 ( V_57 ) ) ;
}
}
static void F_151 ( struct V_2 * V_3 ,
int V_312 , T_3 V_106 ,
struct V_56 * V_57 ,
bool V_325 )
{
struct V_101 * V_101 = F_58 ( & V_3 -> V_5 ) ;
struct V_15 * V_16 = F_29 ( V_3 -> V_5 . V_44 ) ;
enum V_1 V_1 = F_1 ( V_3 ) ;
struct V_102 * V_257 = F_3 ( & V_3 -> V_5 ) ;
F_30 ( V_325 && ( V_1 == V_13 || V_1 == V_12 ) ) ;
F_152 ( V_101 , V_312 , V_106 ,
V_325 ) ;
if ( V_3 -> type == V_8 )
F_153 ( V_101 ) ;
F_142 ( V_3 , V_57 ) ;
F_154 ( V_16 , V_257 -> V_258 ) ;
F_28 ( V_3 ) ;
F_57 ( V_3 ) ;
F_155 ( V_101 , V_326 ) ;
F_156 ( V_101 ) ;
if ( V_1 != V_13 || F_86 ( V_16 ) >= 9 )
F_157 ( V_101 ) ;
}
static void F_158 ( struct V_2 * V_3 ,
bool V_160 ,
const struct V_74 * V_75 ,
const struct V_114 * V_327 ,
struct V_56 * V_57 )
{
struct V_328 * V_328 = F_159 ( & V_3 -> V_5 ) ;
struct V_15 * V_16 = F_29 ( V_3 -> V_5 . V_44 ) ;
struct V_329 * V_329 = & V_3 -> V_5 ;
enum V_1 V_1 = F_1 ( V_3 ) ;
int V_262 = F_18 ( V_16 , V_1 ) ;
struct V_102 * V_257 = F_3 ( & V_3 -> V_5 ) ;
F_160 ( V_328 , true ) ;
F_142 ( V_3 , V_57 ) ;
F_154 ( V_16 , V_257 -> V_258 ) ;
F_34 ( V_3 ) ;
if ( F_20 ( V_16 ) )
F_111 ( V_3 , V_262 ) ;
else if ( F_19 ( V_16 ) )
F_112 ( V_16 , V_262 , V_1 ,
V_9 ) ;
else if ( F_141 ( V_16 ) )
F_135 ( V_3 , V_262 ) ;
V_328 -> V_330 ( V_329 ,
V_160 ,
V_75 , V_327 ) ;
}
static void F_161 ( struct V_2 * V_3 ,
struct V_74 * V_154 ,
struct V_114 * V_327 )
{
int type = V_3 -> type ;
if ( type == V_7 || type == V_8 ) {
F_151 ( V_3 ,
V_154 -> V_157 ,
V_154 -> V_106 ,
V_154 -> V_88 ,
F_162 ( V_154 ,
V_4 ) ) ;
}
if ( type == V_9 ) {
F_158 ( V_3 ,
V_154 -> V_160 ,
V_154 , V_327 ,
V_154 -> V_88 ) ;
}
}
static void F_163 ( struct V_2 * V_2 ,
struct V_74 * V_331 ,
struct V_114 * V_332 )
{
struct V_329 * V_3 = & V_2 -> V_5 ;
struct V_15 * V_16 = F_29 ( V_3 -> V_44 ) ;
enum V_1 V_1 = F_1 ( V_2 ) ;
struct V_102 * V_257 = F_3 ( V_3 ) ;
struct V_101 * V_101 = NULL ;
int type = V_2 -> type ;
T_3 V_174 ;
bool V_333 = false ;
if ( type == V_7 || type == V_8 ) {
V_101 = F_58 ( V_3 ) ;
F_155 ( V_101 , V_334 ) ;
}
V_174 = F_38 ( F_36 ( V_1 ) ) ;
if ( V_174 & V_93 ) {
V_174 &= ~ V_93 ;
F_31 ( F_36 ( V_1 ) , V_174 ) ;
V_333 = true ;
}
V_174 = F_38 ( F_51 ( V_1 ) ) ;
V_174 &= ~ ( V_92 | V_99 ) ;
V_174 |= V_91 ;
F_31 ( F_51 ( V_1 ) , V_174 ) ;
if ( V_333 )
F_35 ( V_16 , V_1 ) ;
if ( V_101 ) {
F_164 ( V_101 ) ;
F_165 ( V_101 ) ;
}
if ( V_257 )
F_98 ( V_16 , V_257 -> V_258 ) ;
if ( F_141 ( V_16 ) )
F_31 ( V_322 , F_38 ( V_322 ) |
F_144 ( V_1 ) ) ;
else if ( F_20 ( V_16 ) )
F_31 ( V_323 , ( F_38 ( V_323 ) |
F_146 ( V_1 ) ) ) ;
else if ( F_86 ( V_16 ) < 9 )
F_31 ( F_50 ( V_1 ) , V_71 ) ;
if ( type == V_9 ) {
struct V_328 * V_328 = F_159 ( V_3 ) ;
F_160 ( V_328 , false ) ;
}
}
void F_166 ( struct V_2 * V_3 ,
struct V_74 * V_331 ,
struct V_114 * V_332 )
{
struct V_15 * V_16 = F_29 ( V_3 -> V_5 . V_44 ) ;
T_3 V_174 ;
V_174 = F_38 ( F_48 ( V_80 ) ) ;
V_174 &= ~ V_94 ;
F_31 ( F_48 ( V_80 ) , V_174 ) ;
F_163 ( V_3 , V_331 , V_332 ) ;
V_174 = F_38 ( F_44 ( V_80 ) ) ;
V_174 &= ~ ( V_96 | V_97 ) ;
V_174 |= F_45 ( 2 ) | F_46 ( 2 ) ;
F_31 ( F_44 ( V_80 ) , V_174 ) ;
V_174 = F_38 ( F_48 ( V_80 ) ) ;
V_174 &= ~ V_87 ;
F_31 ( F_48 ( V_80 ) , V_174 ) ;
V_174 = F_38 ( F_48 ( V_80 ) ) ;
V_174 &= ~ V_85 ;
F_31 ( F_48 ( V_80 ) , V_174 ) ;
}
static void F_167 ( struct V_2 * V_2 ,
struct V_74 * V_154 ,
struct V_114 * V_327 )
{
struct V_329 * V_3 = & V_2 -> V_5 ;
struct V_15 * V_16 = F_29 ( V_3 -> V_44 ) ;
enum V_1 V_1 = F_1 ( V_2 ) ;
int type = V_2 -> type ;
if ( type == V_9 ) {
struct V_102 * V_103 =
F_3 ( V_3 ) ;
bool V_335 = V_154 -> V_234 ;
bool V_336 = V_154 -> V_232 ;
F_168 ( V_2 ,
V_327 -> V_113 ,
V_335 , V_336 ) ;
F_31 ( F_36 ( V_1 ) ,
V_103 -> V_105 |
V_93 ) ;
} else if ( type == V_8 ) {
struct V_101 * V_101 = F_58 ( V_3 ) ;
if ( V_1 == V_13 && F_86 ( V_16 ) < 9 )
F_157 ( V_101 ) ;
F_169 ( V_154 , V_327 ) ;
F_170 ( V_101 ) ;
F_171 ( V_101 , V_154 ) ;
}
if ( V_154 -> V_337 )
F_172 ( V_2 , V_154 , V_327 ) ;
}
static void F_173 ( struct V_2 * V_2 ,
struct V_74 * V_331 ,
struct V_114 * V_332 )
{
struct V_329 * V_3 = & V_2 -> V_5 ;
int type = V_2 -> type ;
if ( V_331 -> V_337 )
F_174 ( V_2 ) ;
if ( type == V_9 ) {
F_168 ( V_2 ,
V_332 -> V_113 ,
false , false ) ;
}
if ( type == V_8 ) {
struct V_101 * V_101 = F_58 ( V_3 ) ;
F_175 ( V_101 , V_331 ) ;
F_176 ( V_101 ) ;
F_177 ( V_332 ) ;
}
}
static void F_178 ( struct V_2 * V_3 ,
struct V_74 * V_154 ,
struct V_114 * V_327 )
{
T_5 V_338 = V_154 -> V_339 ;
F_179 ( V_3 , V_338 ) ;
}
void F_180 ( struct V_101 * V_101 )
{
struct V_102 * V_103 = F_140 ( V_101 ) ;
struct V_15 * V_16 =
F_29 ( V_103 -> V_5 . V_5 . V_44 ) ;
enum V_1 V_1 = V_103 -> V_1 ;
T_3 V_174 ;
bool V_333 = false ;
if ( F_38 ( F_51 ( V_1 ) ) & V_92 ) {
V_174 = F_38 ( F_36 ( V_1 ) ) ;
if ( V_174 & V_93 ) {
V_174 &= ~ V_93 ;
F_31 ( F_36 ( V_1 ) , V_174 ) ;
V_333 = true ;
}
V_174 = F_38 ( F_51 ( V_1 ) ) ;
V_174 &= ~ ( V_92 | V_99 ) ;
V_174 |= V_91 ;
F_31 ( F_51 ( V_1 ) , V_174 ) ;
F_49 ( F_51 ( V_1 ) ) ;
if ( V_333 )
F_35 ( V_16 , V_1 ) ;
}
V_174 = V_92 |
V_91 | V_340 ;
if ( V_101 -> V_325 )
V_174 |= V_341 ;
else {
V_174 |= V_342 ;
if ( F_181 ( V_101 -> V_343 ) )
V_174 |= V_90 ;
}
F_31 ( F_51 ( V_1 ) , V_174 ) ;
F_49 ( F_51 ( V_1 ) ) ;
V_101 -> V_104 |= V_93 ;
F_31 ( F_36 ( V_1 ) , V_101 -> V_104 ) ;
F_49 ( F_36 ( V_1 ) ) ;
F_37 ( 600 ) ;
}
bool F_182 ( struct V_15 * V_16 ,
struct V_72 * V_72 )
{
T_1 V_77 ;
if ( F_183 ( V_16 , V_344 ) ) {
V_77 = F_38 ( V_345 ) ;
if ( V_77 & F_184 ( V_72 -> V_109 ) )
return true ;
}
return false ;
}
void F_185 ( struct V_2 * V_3 ,
struct V_74 * V_154 )
{
struct V_15 * V_16 = F_29 ( V_3 -> V_5 . V_44 ) ;
struct V_72 * V_72 = F_64 ( V_3 -> V_5 . V_73 ) ;
enum V_202 V_203 = V_154 -> V_203 ;
struct V_328 * V_328 ;
T_1 V_77 , V_215 = 0 ;
if ( F_30 ( F_88 ( V_203 ) ) )
return;
V_77 = F_38 ( F_92 ( V_203 ) ) ;
if ( V_77 & V_219 )
V_215 |= V_218 ;
else
V_215 |= V_346 ;
if ( V_77 & V_217 )
V_215 |= V_216 ;
else
V_215 |= V_347 ;
V_154 -> V_5 . V_163 . V_215 |= V_215 ;
switch ( V_77 & V_348 ) {
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
V_328 = F_159 ( & V_3 -> V_5 ) ;
if ( V_328 -> V_349 ( & V_3 -> V_5 , V_154 ) )
V_154 -> V_350 = true ;
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
( ( V_77 & V_351 ) >> V_352 ) + 1 ;
F_186 ( V_72 , V_154 ) ;
break;
default:
break;
}
V_154 -> V_337 =
F_182 ( V_16 , V_72 ) ;
if ( V_3 -> type == V_8 && V_16 -> V_18 . V_19 . V_353 &&
V_154 -> V_161 > V_16 -> V_18 . V_19 . V_353 ) {
F_56 ( L_18 ,
V_154 -> V_161 , V_16 -> V_18 . V_19 . V_353 ) ;
V_16 -> V_18 . V_19 . V_353 = V_154 -> V_161 ;
}
F_85 ( V_3 , V_154 ) ;
if ( F_19 ( V_16 ) )
V_154 -> V_339 =
F_187 ( V_3 ) ;
}
static bool F_188 ( struct V_2 * V_3 ,
struct V_74 * V_154 ,
struct V_114 * V_327 )
{
struct V_15 * V_16 = F_29 ( V_3 -> V_5 . V_44 ) ;
int type = V_3 -> type ;
int V_1 = F_1 ( V_3 ) ;
int V_107 ;
F_23 ( type == V_10 , L_19 ) ;
if ( V_1 == V_13 )
V_154 -> V_203 = V_220 ;
if ( type == V_9 )
V_107 = F_189 ( V_3 , V_154 , V_327 ) ;
else
V_107 = F_190 ( V_3 , V_154 , V_327 ) ;
if ( F_19 ( V_16 ) && V_107 )
V_154 -> V_339 =
F_191 ( V_3 ,
V_154 -> V_106 ) ;
return V_107 ;
}
static struct V_241 *
F_192 ( struct V_102 * V_103 )
{
struct V_241 * V_113 ;
enum V_1 V_1 = V_103 -> V_1 ;
V_113 = F_193 () ;
if ( ! V_113 )
return NULL ;
V_103 -> V_354 . V_355 = F_36 ( V_1 ) ;
if ( ! F_194 ( V_103 , V_113 ) ) {
F_195 ( V_113 ) ;
return NULL ;
}
return V_113 ;
}
static struct V_241 *
F_196 ( struct V_102 * V_103 )
{
struct V_241 * V_113 ;
enum V_1 V_1 = V_103 -> V_1 ;
V_113 = F_193 () ;
if ( ! V_113 )
return NULL ;
V_103 -> V_356 . V_357 = F_36 ( V_1 ) ;
F_197 ( V_103 , V_113 ) ;
return V_113 ;
}
void F_198 ( struct V_15 * V_16 , enum V_1 V_1 )
{
struct V_102 * V_103 ;
struct V_2 * V_2 ;
struct V_329 * V_3 ;
bool V_358 , V_359 , V_360 = false ;
int V_266 ;
if ( F_38 ( F_36 ( V_13 ) ) & V_361 ) {
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
V_358 = ( V_16 -> V_18 . V_37 [ V_1 ] . V_362 ||
V_16 -> V_18 . V_37 [ V_1 ] . V_363 ) ;
V_359 = V_16 -> V_18 . V_37 [ V_1 ] . V_364 ;
if ( F_199 ( V_16 , V_1 ) ) {
V_359 = true ;
V_360 = true ;
V_358 = false ;
F_56 ( L_20 , F_40 ( V_1 ) ) ;
}
if ( ! V_359 && ! V_358 ) {
F_56 ( L_21 ,
F_40 ( V_1 ) ) ;
return;
}
V_103 = F_200 ( sizeof( * V_103 ) , V_365 ) ;
if ( ! V_103 )
return;
V_2 = & V_103 -> V_5 ;
V_3 = & V_2 -> V_5 ;
F_201 ( & V_16 -> V_366 , V_3 , & V_367 ,
V_368 , L_22 , F_40 ( V_1 ) ) ;
V_2 -> V_369 = F_188 ;
V_2 -> V_274 = F_167 ;
if ( F_19 ( V_16 ) )
V_2 -> V_370 = F_178 ;
V_2 -> V_371 = F_161 ;
V_2 -> V_372 = F_173 ;
V_2 -> V_373 = F_163 ;
V_2 -> V_245 = F_99 ;
V_2 -> V_374 = F_185 ;
V_2 -> V_375 = V_376 ;
V_2 -> V_377 = F_101 ;
V_103 -> V_1 = V_1 ;
V_103 -> V_105 = F_38 ( F_36 ( V_1 ) ) &
( V_378 |
V_361 ) ;
switch ( V_1 ) {
case V_13 :
V_103 -> V_258 =
V_379 ;
break;
case V_380 :
V_103 -> V_258 =
V_381 ;
break;
case V_382 :
V_103 -> V_258 =
V_383 ;
break;
case V_384 :
V_103 -> V_258 =
V_385 ;
break;
case V_12 :
V_103 -> V_258 =
V_386 ;
break;
default:
F_4 ( V_1 ) ;
}
if ( F_19 ( V_16 ) && V_1 == V_13 ) {
if ( ! ( V_103 -> V_105 & V_361 ) ) {
F_56 ( L_23 ) ;
V_103 -> V_105 |= V_361 ;
V_266 = 4 ;
}
}
V_103 -> V_266 = V_266 ;
V_2 -> type = V_10 ;
V_2 -> V_244 = F_202 ( V_1 ) ;
V_2 -> V_1 = V_1 ;
V_2 -> V_387 = ( 1 << 0 ) | ( 1 << 1 ) | ( 1 << 2 ) ;
V_2 -> V_388 = 0 ;
if ( V_359 ) {
if ( ! F_192 ( V_103 ) )
goto V_389;
V_103 -> V_390 = V_391 ;
V_16 -> V_392 . V_393 [ V_1 ] = V_103 ;
}
if ( V_2 -> type != V_8 && V_358 ) {
if ( ! F_196 ( V_103 ) )
goto V_389;
}
if ( V_360 ) {
if ( F_203 ( V_103 ) )
F_56 ( L_24 ,
F_40 ( V_1 ) ) ;
else
F_39 ( L_25 ,
F_40 ( V_1 ) ) ;
}
return;
V_389:
F_204 ( V_3 ) ;
F_195 ( V_103 ) ;
}
