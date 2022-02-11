static int F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_6 , V_7 , V_8 ;
for ( V_8 = 0 ; V_8 < F_3 ( V_9 ) ; V_8 ++ )
if ( V_9 [ V_8 ] == V_3 )
break;
if ( V_8 == F_3 ( V_9 ) ) {
F_4 ( V_2 -> V_10 , L_1 , V_3 ) ;
return - V_11 ;
}
V_6 = V_8 ;
if ( ( V_5 -> V_12 % V_3 ) == 0 ) {
V_7 = - 1 ;
for ( V_8 = 0 ; V_8 < F_3 ( V_13 ) ; V_8 ++ ) {
if ( ! V_5 -> V_14 [ V_8 ] && V_7 == - 1 ) {
V_7 = V_8 ;
continue;
}
if ( ( F_5 ( V_2 , V_13 [ V_8 ] ) &
V_15 ) == V_6 )
break;
}
if ( V_8 < F_3 ( V_13 ) ) {
V_5 -> V_14 [ V_8 ] ++ ;
F_6 ( V_2 -> V_10 , L_2 ,
V_3 , V_8 , V_5 -> V_14 [ V_8 ] ) ;
return V_8 ;
}
if ( V_7 == - 1 ) {
F_4 ( V_2 -> V_10 , L_3 ) ;
return - V_16 ;
}
F_6 ( V_2 -> V_10 , L_4 ,
V_7 , V_3 ) ;
V_5 -> V_14 [ V_7 ] ++ ;
F_7 ( V_2 , V_13 [ V_7 ] ,
V_15 ,
V_6 ) ;
return V_7 ;
} else {
F_4 ( V_2 -> V_10 ,
L_5 ,
V_3 , V_5 -> V_12 , V_5 -> V_17 ) ;
return - V_11 ;
}
}
static void F_8 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_8 , V_6 ;
for ( V_8 = 0 ; V_8 < F_3 ( V_9 ) ; V_8 ++ )
if ( V_9 [ V_8 ] == V_3 )
break;
if ( V_8 == F_3 ( V_9 ) ) {
F_4 ( V_2 -> V_10 , L_1 , V_3 ) ;
return;
}
V_6 = V_9 [ V_8 ] ;
for ( V_8 = 0 ; V_8 < F_3 ( V_13 ) ; V_8 ++ ) {
if ( ! V_5 -> V_14 [ V_8 ] )
continue;
if ( ( F_5 ( V_2 , V_13 [ V_8 ] ) &
V_15 ) == V_6 )
break;
}
if ( V_8 < F_3 ( V_13 ) ) {
V_5 -> V_14 [ V_8 ] -- ;
F_6 ( V_2 -> V_10 , L_6 ,
V_3 , V_5 -> V_14 [ V_8 ] ) ;
} else {
F_9 ( V_2 -> V_10 , L_7 ,
V_3 ) ;
}
}
static int F_10 ( struct V_4 * V_5 )
{
if ( V_5 -> V_18 . V_19 ) {
F_11 ( V_5 -> V_18 . V_19 , 0 ) ;
F_11 ( V_5 -> V_18 . V_19 , 1 ) ;
return 0 ;
} else {
return F_12 ( V_5 -> V_20 , V_21 , 0 ) ;
}
}
static void F_13 ( struct V_22 * V_23 ,
enum V_24 V_25 , int V_26 )
{
struct V_1 * V_2 = F_14 ( V_23 ,
struct V_1 , V_23 ) ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
T_1 V_27 , V_28 , V_8 ;
if ( V_5 -> V_29 [ 0 ] ) {
V_28 = F_5 ( V_2 , V_30 ) ;
for ( V_8 = 0 ; V_8 < 200 ; V_8 ++ ) {
V_27 = F_5 ( V_2 , V_31 ) ;
if ( V_27 == V_28 ) {
V_5 -> V_29 [ 0 ] = false ;
break;
}
}
if ( V_8 == 200 ) {
F_4 ( V_2 -> V_10 , L_8 ,
V_28 ) ;
}
}
if ( V_5 -> V_29 [ 1 ] ) {
V_28 = F_5 ( V_2 , V_32 ) ;
for ( V_8 = 0 ; V_8 < 200 ; V_8 ++ ) {
V_27 = F_5 ( V_2 , V_33 ) ;
if ( V_27 == V_28 ) {
V_5 -> V_29 [ 1 ] = false ;
break;
}
}
if ( V_8 == 200 ) {
F_4 ( V_2 -> V_10 , L_9 ,
V_28 ) ;
}
}
}
static int F_15 ( struct V_34 * V_35 ,
struct V_36 * V_37 ,
int V_25 )
{
struct V_4 * V_5 = F_2 ( V_35 -> V_2 ) ;
switch ( V_35 -> V_38 ) {
case V_30 :
V_5 -> V_29 [ 0 ] = true ;
break;
case V_32 :
V_5 -> V_29 [ 0 ] = true ;
break;
default:
break;
}
return 0 ;
}
static void F_16 ( struct V_4 * V_5 , int V_27 )
{
if ( V_27 & V_39 )
F_17 ( V_5 -> V_10 , L_10 ) ;
if ( V_27 & V_40 )
F_17 ( V_5 -> V_10 , L_11 ) ;
if ( V_27 & V_41 )
F_17 ( V_5 -> V_10 , L_12 ) ;
if ( V_27 & V_42 )
F_17 ( V_5 -> V_10 , L_13 ) ;
}
static void F_18 ( struct V_4 * V_5 , int V_27 )
{
if ( V_27 & V_43 )
F_4 ( V_5 -> V_10 , L_14 ) ;
if ( V_27 & V_44 )
F_4 ( V_5 -> V_10 , L_15 ) ;
if ( V_27 & V_45 )
F_4 ( V_5 -> V_10 , L_16 ) ;
if ( V_27 & V_46 )
F_4 ( V_5 -> V_10 , L_17 ) ;
if ( V_27 & V_47 )
F_4 ( V_5 -> V_10 , L_18 ) ;
if ( V_27 & V_48 )
F_4 ( V_5 -> V_10 , L_19 ) ;
if ( V_27 & V_49 )
F_4 ( V_5 -> V_10 , L_20 ) ;
if ( V_27 & V_50 )
F_4 ( V_5 -> V_10 , L_21 ) ;
if ( V_27 & V_51 )
F_4 ( V_5 -> V_10 , L_22 ) ;
if ( V_27 & V_52 )
F_4 ( V_5 -> V_10 , L_23 ) ;
if ( V_27 & V_53 )
F_4 ( V_5 -> V_10 , L_24 ) ;
if ( V_27 & V_54 )
F_4 ( V_5 -> V_10 , L_25 ) ;
if ( V_27 & V_55 )
F_4 ( V_5 -> V_10 , L_26 ) ;
if ( V_27 & V_56 )
F_4 ( V_5 -> V_10 , L_27 ) ;
}
static int F_19 ( struct V_34 * V_35 ,
struct V_36 * V_37 ,
int V_25 )
{
struct V_1 * V_2 = V_35 -> V_2 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_57 ;
V_57 = F_5 ( V_2 , V_58 ) ;
V_57 &= V_59 |
V_60 | V_61 |
V_62 ;
F_16 ( V_5 , V_57 ) ;
V_57 = F_5 ( V_2 , V_63 ) ;
F_18 ( V_5 , V_57 ) ;
return 0 ;
}
static int F_20 ( struct V_64 * V_65 , unsigned int V_66 )
{
struct V_1 * V_2 = V_65 -> V_2 ;
int V_67 , V_68 , V_69 , V_70 ;
V_70 = V_65 -> V_71 -> V_70 ;
V_67 = 0 ;
V_68 = 0 ;
switch ( V_66 & V_72 ) {
case V_73 :
V_69 = 0 ;
break;
case V_74 :
V_69 = 1 ;
break;
case V_75 :
V_69 = 2 ;
break;
case V_76 :
V_69 = 3 ;
break;
default:
F_4 ( V_2 -> V_10 , L_28 ,
V_66 & V_72 ) ;
return - V_11 ;
}
switch ( V_66 & V_77 ) {
case V_78 :
break;
case V_79 :
V_67 |= V_80 ;
break;
case V_81 :
V_68 |= V_82 ;
break;
case V_83 :
V_67 |= V_80 ;
V_68 |= V_82 ;
break;
default:
F_4 ( V_2 -> V_10 , L_29 ,
V_66 & V_77 ) ;
return - V_11 ;
}
switch ( V_66 & V_84 ) {
case V_85 :
break;
case V_86 :
V_68 |= V_87 ;
V_67 |= V_88 ;
break;
case V_89 :
V_68 |= V_87 ;
break;
case V_90 :
V_67 |= V_88 ;
break;
default:
return - V_11 ;
}
F_7 ( V_2 , V_70 + 1 , V_82 |
V_87 , V_68 ) ;
F_7 ( V_2 , V_70 + 2 , V_80 |
V_88 , V_67 ) ;
F_7 ( V_2 , V_70 + 3 , V_80 |
V_88 , V_67 ) ;
F_7 ( V_2 , V_70 + 5 , V_91 , V_69 ) ;
return 0 ;
}
static int F_21 ( struct V_92 * V_93 ,
struct V_94 * V_95 ,
struct V_64 * V_65 )
{
struct V_1 * V_2 = V_65 -> V_2 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
bool V_96 = V_5 -> V_97 [ V_65 -> V_98 ] ;
int V_8 , V_70 , V_68 , V_99 , V_67 , V_100 , V_101 , V_102 ;
int * V_103 ;
V_70 = V_65 -> V_71 -> V_70 ;
V_100 = F_22 ( F_23 ( V_95 ) ) ;
if ( V_100 < 0 )
return V_100 ;
V_101 = F_24 ( V_95 ) ;
if ( V_101 < 0 )
return V_101 ;
F_6 ( V_2 -> V_10 , L_30 ,
V_100 , V_101 ) ;
V_68 = F_25 ( V_95 ) ;
if ( V_68 < 0 )
return V_68 ;
if ( ! V_96 ) {
V_99 = V_5 -> V_12 ;
V_102 = F_1 ( V_2 , F_26 ( V_95 ) ) ;
if ( V_102 < 0 )
return V_102 ;
} else {
V_99 = V_5 -> V_17 ;
V_102 = 3 ;
for ( V_8 = 0 ; V_8 < F_3 ( V_9 ) ; V_8 ++ )
if ( F_26 ( V_95 ) == V_9 [ V_8 ] )
break;
if ( V_8 == F_3 ( V_9 ) ) {
F_4 ( V_2 -> V_10 , L_31 ,
F_26 ( V_95 ) ) ;
return - V_11 ;
}
F_7 ( V_2 , V_104 ,
V_105 , V_8 ) ;
}
if ( ! V_99 ) {
F_4 ( V_2 -> V_10 , L_32 ,
V_96 ? L_33 : L_34 ) ;
return - V_11 ;
}
F_6 ( V_2 -> V_10 , L_35 ,
V_68 , V_99 , V_96 ? L_33 : L_34 ) ;
if ( V_99 % 4000 )
V_103 = V_106 ;
else
V_103 = V_107 ;
for ( V_8 = 0 ; V_8 < V_108 ; V_8 ++ )
if ( V_103 [ V_8 ] >= V_68 && ( V_103 [ V_8 ] % V_68 == 0 ) )
break;
if ( V_8 == V_108 ) {
F_4 ( V_2 -> V_10 ,
L_36 ,
V_68 , V_99 , V_96 ? L_33 : L_34 ) ;
return - V_11 ;
}
V_68 = V_8 ;
F_6 ( V_2 -> V_10 , L_37 , V_103 [ V_68 ] ) ;
F_7 ( V_2 , V_70 + 1 , V_109 , V_68 ) ;
V_67 = V_103 [ V_68 ] / F_26 ( V_95 ) ;
F_6 ( V_2 -> V_10 , L_38 , V_103 [ V_68 ] / V_67 ) ;
if ( V_93 -> V_110 == V_111 ||
V_5 -> V_112 [ V_65 -> V_98 ] )
F_7 ( V_2 , V_70 + 7 ,
V_113 , V_67 ) ;
else
F_7 ( V_2 , V_70 + 6 ,
V_114 , V_67 ) ;
V_8 = ( V_100 << V_115 ) | V_101 ;
if ( V_93 -> V_110 == V_111 )
F_7 ( V_2 , V_70 + 9 ,
V_116 |
V_117 , V_8 ) ;
else
F_7 ( V_2 , V_70 + 8 ,
V_118 |
V_119 , V_8 ) ;
F_7 ( V_2 , V_70 + 4 , V_120 , V_102 ) ;
return 0 ;
}
static int F_27 ( struct V_1 * V_2 , int V_121 ,
int V_122 , unsigned int V_123 , int V_124 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
int * V_125 ;
int V_126 , V_127 , V_57 , V_38 ;
switch ( V_121 ) {
case V_128 :
V_38 = V_129 ;
V_125 = & V_5 -> V_12 ;
break;
case V_130 :
V_38 = V_131 ;
V_125 = & V_5 -> V_17 ;
break;
case V_132 :
switch ( V_122 ) {
case V_133 :
case V_134 :
case V_135 :
F_7 ( V_2 , V_136 ,
V_137 ,
V_122 ) ;
break;
default:
return - V_11 ;
}
return 0 ;
case V_138 :
case V_139 :
case V_140 :
switch ( V_122 ) {
case V_135 :
V_5 -> V_97 [ V_121 - 1 ] = false ;
break;
case V_141 :
V_5 -> V_97 [ V_121 - 1 ] = true ;
break;
default:
F_4 ( V_2 -> V_10 , L_39 , V_122 ) ;
return - V_11 ;
}
return 0 ;
case V_142 :
switch ( V_123 ) {
case 5644800 :
case 6144000 :
F_7 ( V_2 , V_143 ,
V_144 , 0 ) ;
break;
case 11289600 :
case 12288000 :
F_7 ( V_2 , V_143 ,
V_144 , 0 ) ;
break;
case 22579200 :
case 24576000 :
F_7 ( V_2 , V_143 ,
V_144 , 0 ) ;
break;
default:
F_4 ( V_2 -> V_10 , L_40 ,
V_123 ) ;
return - V_11 ;
}
return 0 ;
default:
F_4 ( V_2 -> V_10 , L_41 , V_121 ) ;
return - V_11 ;
}
switch ( V_122 ) {
case V_135 :
case V_141 :
F_4 ( V_2 -> V_10 , L_39 , V_122 ) ;
return - V_11 ;
}
switch ( V_123 ) {
case 5644800 :
case 6144000 :
V_126 = 0 ;
break;
case 11289600 :
case 12288000 :
V_126 = 1 ;
break;
case 22579200 :
case 24576000 :
V_126 = 2 ;
break;
default:
F_4 ( V_2 -> V_10 , L_42 , V_123 ) ;
return - V_11 ;
}
switch ( V_123 ) {
case 5644800 :
case 11289600 :
case 22579200 :
V_127 = 44100 ;
break;
case 6144000 :
case 12288000 :
case 24576000 :
V_127 = 48000 ;
break;
default:
F_28 () ;
V_127 = 0 ;
break;
}
F_7 ( V_2 , V_38 , V_145 |
V_146 ,
V_126 << V_147 | V_122 ) ;
if ( V_121 == V_128 ) {
F_6 ( V_2 -> V_10 , L_43 ,
V_127 ) ;
if ( 0 && * V_125 )
F_8 ( V_2 , V_127 ) ;
V_57 = F_1 ( V_2 , V_127 ) ;
if ( V_57 != 0 )
F_9 ( V_2 -> V_10 , L_44 ,
V_57 ) ;
}
* V_125 = V_123 ;
return 0 ;
}
static int F_29 ( struct V_148 * V_149 , unsigned int V_150 ,
unsigned int V_151 )
{
unsigned int V_152 ;
unsigned int div ;
unsigned int V_153 , V_154 ;
int V_8 ;
div = 1 ;
V_149 -> V_155 = 0 ;
while ( ( V_150 / div ) > 13500000 ) {
div *= 2 ;
V_149 -> V_155 ++ ;
if ( div > 8 ) {
F_30 ( L_45 ,
V_150 ) ;
return - V_11 ;
}
}
F_31 ( L_46 , V_150 , V_151 ) ;
V_150 /= div ;
div = 2 ;
while ( V_151 * div < 90000000 ) {
div ++ ;
if ( div > 64 ) {
F_30 ( L_47 ,
V_151 ) ;
return - V_11 ;
}
}
V_152 = V_151 * div ;
V_149 -> V_156 = div - 1 ;
F_31 ( L_48 , V_152 ) ;
for ( V_8 = 0 ; V_8 < F_3 ( V_157 ) ; V_8 ++ ) {
if ( V_157 [ V_8 ] . V_158 <= V_150 && V_150 <= V_157 [ V_8 ] . V_159 ) {
V_149 -> V_160 = V_157 [ V_8 ] . V_160 ;
V_153 = V_157 [ V_8 ] . V_161 ;
break;
}
}
if ( V_8 == F_3 ( V_157 ) ) {
F_30 ( L_49 , V_150 ) ;
return - V_11 ;
}
V_149 -> V_162 = V_152 / ( V_153 * V_150 ) ;
if ( V_152 % V_150 == 0 ) {
V_149 -> V_163 = 0 ;
V_149 -> V_164 = 0 ;
} else {
V_154 = F_32 ( V_152 , V_153 * V_150 ) ;
V_149 -> V_163 = ( V_152 - ( V_149 -> V_162 * V_153 * V_150 ) )
/ V_154 ;
V_149 -> V_164 = ( V_153 * V_150 ) / V_154 ;
}
F_31 ( L_50 ,
V_149 -> V_162 , V_149 -> V_163 , V_149 -> V_164 ) ;
F_31 ( L_51 ,
V_149 -> V_160 , V_153 , V_149 -> V_156 ,
V_149 -> V_155 ) ;
return 0 ;
}
static int F_33 ( struct V_1 * V_2 , int V_165 , int V_122 ,
unsigned int V_150 , unsigned int V_151 )
{
struct V_166 * V_167 = F_34 ( V_2 -> V_10 ) ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_148 V_168 ;
struct V_169 * V_170 ;
int V_57 , V_70 , V_171 , V_8 , V_172 ;
switch ( V_165 ) {
case V_173 :
V_170 = & V_5 -> V_170 [ 0 ] ;
V_70 = V_174 - 1 ;
V_171 = V_175 ;
break;
case V_176 :
V_170 = & V_5 -> V_170 [ 1 ] ;
V_70 = V_177 - 1 ;
V_171 = V_178 ;
break;
default:
F_4 ( V_2 -> V_10 , L_52 , V_165 ) ;
return - V_11 ;
}
if ( ! V_151 ) {
F_6 ( V_2 -> V_10 , L_53 , V_165 ) ;
if ( V_170 -> V_179 )
F_35 ( V_2 -> V_10 ) ;
V_170 -> V_179 = 0 ;
F_7 ( V_2 , V_70 + 1 , V_180 , 0 ) ;
return 0 ;
}
switch ( V_122 ) {
case V_181 :
case V_182 :
case V_183 :
case V_184 :
case V_185 :
case V_186 :
case V_187 :
break;
default:
F_4 ( V_2 -> V_10 , L_54 , V_122 ) ;
return - V_11 ;
}
V_57 = F_29 ( & V_168 , V_150 , V_151 ) ;
if ( V_57 < 0 )
return V_57 ;
F_7 ( V_2 , V_70 + 1 , V_180 , 0 ) ;
F_7 ( V_2 , V_70 + 2 ,
V_188 | V_189 ,
( V_168 . V_156 << V_190 ) |
V_168 . V_160 ) ;
F_7 ( V_2 , V_70 + 3 , V_191 ,
V_168 . V_163 ) ;
F_7 ( V_2 , V_70 + 5 , V_192 , V_168 . V_162 ) ;
F_7 ( V_2 , V_70 + 6 ,
V_193 |
V_194 ,
( V_168 . V_155
<< V_195 ) | V_122 ) ;
F_7 ( V_2 , V_70 + 7 , V_196 ,
V_168 . V_164 ) ;
F_36 ( & V_170 -> V_171 ) ;
F_37 ( V_2 -> V_10 ) ;
F_7 ( V_2 , V_70 + 1 , V_180 , V_180 ) ;
if ( V_167 -> V_197 )
V_172 = 2 ;
else
V_172 = 50 ;
F_7 ( V_2 , V_129 , V_198 ,
V_198 ) ;
for ( V_8 = 0 ; V_8 < V_172 ; V_8 ++ ) {
if ( V_167 -> V_197 ) {
V_57 = F_38 ( & V_170 -> V_171 ,
F_39 ( 25 ) ) ;
if ( V_57 > 0 )
break;
} else {
F_40 ( 1 ) ;
}
V_57 = F_5 ( V_2 ,
V_58 ) ;
if ( V_57 < 0 ) {
F_4 ( V_2 -> V_10 ,
L_55 ,
V_57 ) ;
continue;
}
if ( V_57 & V_171 )
break;
}
if ( V_8 == V_172 ) {
F_4 ( V_2 -> V_10 , L_56 , V_165 ) ;
F_35 ( V_2 -> V_10 ) ;
return - V_199 ;
}
V_170 -> V_200 = V_122 ;
V_170 -> V_201 = V_150 ;
V_170 -> V_179 = V_151 ;
F_6 ( V_2 -> V_10 , L_57 , V_165 ,
V_150 , V_151 ) ;
return 0 ;
}
static void F_41 ( struct V_4 * V_5 , int V_202 )
{
struct V_203 * V_204 = & V_5 -> V_18 . V_205 [ V_202 ] ;
F_42 ( V_202 >= F_3 ( V_5 -> V_18 . V_205 ) ) ;
F_11 ( V_5 -> V_18 . V_206 , V_204 -> V_206 ) ;
F_43 ( V_5 -> V_20 , V_207 ,
V_208 |
V_209 ,
( V_204 -> V_210 << V_211 ) |
V_204 -> V_212 << V_213 ) ;
F_43 ( V_5 -> V_20 , V_214 ,
V_215 ,
V_204 -> V_212 << V_216 ) ;
V_5 -> V_217 = V_202 ;
F_6 ( V_5 -> V_10 , L_58 ,
V_5 -> V_217 ) ;
}
static void F_44 ( struct V_4 * V_5 )
{
F_6 ( V_5 -> V_10 , L_59 ) ;
V_5 -> V_218 = false ;
F_45 ( V_5 -> V_219 , V_220 ,
V_220 ) ;
F_43 ( V_5 -> V_20 , V_221 ,
V_222 ,
7 << V_223 ) ;
}
static void F_46 ( struct V_4 * V_5 )
{
unsigned int V_27 ;
int V_57 ;
V_57 = F_47 ( V_5 -> V_20 , V_224 , & V_27 ) ;
if ( V_57 != 0 ) {
F_4 ( V_5 -> V_10 , L_60 ,
V_57 ) ;
return;
}
F_6 ( V_5 -> V_10 , L_61 , V_27 ) ;
if ( ! ( V_27 & V_225 ) ) {
F_9 ( V_5 -> V_10 , L_62 ) ;
return;
}
if ( ! ( V_27 & V_226 ) ) {
F_6 ( V_5 -> V_10 , L_63 ) ;
V_5 -> V_227 = false ;
V_5 -> V_218 = true ;
V_5 -> V_228 = 0 ;
F_45 ( V_5 -> V_219 , 0 ,
V_229 | V_230 |
V_231 ) ;
F_43 ( V_5 -> V_20 , V_221 ,
V_222 ,
V_222 ) ;
return;
}
if ( V_27 & 0x400 ) {
if ( V_5 -> V_218 ) {
F_6 ( V_5 -> V_10 , L_64 ) ;
V_5 -> V_227 = true ;
V_5 -> V_218 = false ;
F_45 ( V_5 -> V_219 ,
V_230 ,
V_230 | V_231 ) ;
F_43 ( V_5 -> V_20 , V_221 ,
V_222 ,
5 << V_223 ) ;
} else {
F_6 ( V_5 -> V_10 , L_65 ) ;
F_45 ( V_5 -> V_219 , 0 , V_231 ) ;
}
return;
}
if ( V_5 -> V_218 && ( V_27 & 0x3f8 ) ) {
V_5 -> V_228 ++ ;
if ( V_5 -> V_228 > 1 )
F_44 ( V_5 ) ;
else
F_41 ( V_5 , ! V_5 -> V_217 ) ;
return;
}
if ( V_27 & 0x3fc ) {
if ( V_5 -> V_227 ) {
F_6 ( V_5 -> V_10 , L_66 ) ;
F_45 ( V_5 -> V_219 , V_231 ,
V_231 ) ;
} else if ( V_5 -> V_218 ) {
F_44 ( V_5 ) ;
}
}
}
int F_48 ( struct V_1 * V_2 , struct V_232 * V_219 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
if ( V_219 ) {
V_5 -> V_219 = V_219 ;
V_5 -> V_218 = true ;
V_5 -> V_228 = 0 ;
F_41 ( V_5 , 0 ) ;
F_7 ( V_2 , V_221 ,
V_233 |
V_222 ,
( 7 << V_234 ) |
V_222 ) ;
F_49 ( & V_2 -> V_23 , L_67 ) ;
F_49 ( & V_2 -> V_23 , L_34 ) ;
F_50 ( & V_2 -> V_23 ) ;
F_7 ( V_2 , V_221 ,
V_235 , V_235 ) ;
F_7 ( V_2 , V_236 ,
V_237 , 0 ) ;
} else {
F_7 ( V_2 , V_236 ,
V_238 |
V_237 ,
V_238 |
V_237 ) ;
F_7 ( V_2 , V_221 ,
V_235 , 0 ) ;
V_5 -> V_219 = NULL ;
}
return 0 ;
}
static T_2 F_51 ( int V_197 , void * V_239 )
{
struct V_4 * V_5 = V_239 ;
T_2 V_240 = V_241 ;
unsigned int V_242 , V_243 ;
int V_57 ;
V_57 = F_47 ( V_5 -> V_20 , V_244 , & V_242 ) ;
if ( V_57 < 0 ) {
F_4 ( V_5 -> V_10 , L_68 ,
V_57 ) ;
V_242 = 0 ;
}
V_57 = F_47 ( V_5 -> V_20 , V_236 ,
& V_243 ) ;
if ( V_57 < 0 ) {
F_4 ( V_5 -> V_10 , L_69 ,
V_57 ) ;
V_243 = 0xffff ;
}
V_242 &= ~ V_243 ;
F_12 ( V_5 -> V_20 , V_244 , V_242 ) ;
if ( V_242 )
V_240 = V_245 ;
F_16 ( V_5 , V_242 ) ;
if ( V_242 & V_246 ) {
F_6 ( V_5 -> V_10 , L_70 ) ;
F_52 ( & V_5 -> V_170 [ 0 ] . V_171 ) ;
}
if ( V_242 & V_247 ) {
F_6 ( V_5 -> V_10 , L_71 ) ;
F_52 ( & V_5 -> V_170 [ 1 ] . V_171 ) ;
}
if ( V_242 & V_248 )
F_46 ( V_5 ) ;
V_57 = F_47 ( V_5 -> V_20 , V_249 , & V_242 ) ;
if ( V_57 < 0 ) {
F_4 ( V_5 -> V_10 , L_72 ,
V_57 ) ;
V_242 = 0 ;
}
V_57 = F_47 ( V_5 -> V_20 , V_250 ,
& V_243 ) ;
if ( V_57 < 0 ) {
F_4 ( V_5 -> V_10 , L_73 ,
V_57 ) ;
V_243 = 0xffff ;
}
V_242 &= ~ V_243 ;
if ( V_242 )
V_240 = V_245 ;
F_12 ( V_5 -> V_20 , V_249 , V_242 ) ;
F_18 ( V_5 , V_242 ) ;
return V_240 ;
}
static T_2 F_53 ( int V_197 , void * V_239 )
{
T_2 V_57 = V_241 ;
T_2 V_27 ;
do {
V_27 = F_51 ( V_197 , V_239 ) ;
if ( V_27 != V_241 )
V_57 = V_27 ;
} while ( V_27 != V_241 );
return V_57 ;
}
static inline struct V_4 * F_54 ( struct V_251 * V_252 )
{
return F_14 ( V_252 , struct V_4 , V_251 ) ;
}
static void F_55 ( struct V_251 * V_252 , unsigned V_253 , int V_254 )
{
struct V_4 * V_5 = F_54 ( V_252 ) ;
F_43 ( V_5 -> V_20 , V_255 + V_253 ,
V_256 , ! ! V_254 << V_257 ) ;
}
static int F_56 ( struct V_251 * V_252 ,
unsigned V_253 , int V_254 )
{
struct V_4 * V_5 = F_54 ( V_252 ) ;
int V_27 , V_57 ;
V_27 = ( 1 << V_258 ) | ( ! ! V_254 << V_257 ) ;
V_57 = F_43 ( V_5 -> V_20 , V_255 + V_253 ,
V_259 | V_260 |
V_256 , V_27 ) ;
if ( V_57 < 0 )
return V_57 ;
else
return 0 ;
}
static int F_57 ( struct V_251 * V_252 , unsigned V_253 )
{
struct V_4 * V_5 = F_54 ( V_252 ) ;
unsigned int V_38 ;
int V_57 ;
V_57 = F_47 ( V_5 -> V_20 , V_255 + V_253 , & V_38 ) ;
if ( V_57 < 0 )
return V_57 ;
return ( V_38 & V_256 ) != 0 ;
}
static int F_58 ( struct V_251 * V_252 , unsigned V_253 )
{
struct V_4 * V_5 = F_54 ( V_252 ) ;
return F_43 ( V_5 -> V_20 , V_255 + V_253 ,
V_259 | V_260 ,
( 1 << V_258 ) |
( 1 << V_261 ) ) ;
}
static void F_59 ( struct V_166 * V_167 )
{
struct V_4 * V_5 = F_60 ( V_167 ) ;
int V_57 ;
V_5 -> V_251 = V_262 ;
V_5 -> V_251 . V_263 = 6 ;
V_5 -> V_251 . V_10 = & V_167 -> V_10 ;
if ( V_5 -> V_18 . V_264 )
V_5 -> V_251 . V_70 = V_5 -> V_18 . V_264 ;
else
V_5 -> V_251 . V_70 = - 1 ;
V_57 = F_61 ( & V_5 -> V_251 ) ;
if ( V_57 != 0 )
F_4 ( & V_167 -> V_10 , L_74 , V_57 ) ;
}
static void F_62 ( struct V_166 * V_167 )
{
struct V_4 * V_5 = F_60 ( V_167 ) ;
int V_57 ;
V_57 = F_63 ( & V_5 -> V_251 ) ;
if ( V_57 != 0 )
F_4 ( & V_167 -> V_10 , L_75 , V_57 ) ;
}
static void F_59 ( struct V_166 * V_167 )
{
}
static void F_62 ( struct V_166 * V_167 )
{
}
static int F_64 ( struct V_1 * V_2 )
{
struct V_166 * V_167 = F_34 ( V_2 -> V_10 ) ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_57 , V_8 ;
V_5 -> V_2 = V_2 ;
V_2 -> V_265 = V_5 -> V_20 ;
V_57 = F_65 ( V_2 , 16 , 16 , V_266 ) ;
if ( V_57 != 0 ) {
F_4 ( V_2 -> V_10 , L_76 , V_57 ) ;
return V_57 ;
}
for ( V_8 = 0 ; V_8 < F_3 ( V_267 ) ; V_8 ++ )
F_7 ( V_2 , V_267 [ V_8 ] , V_268 ,
V_268 ) ;
F_66 ( V_2 , V_269 , 0 ) ;
F_66 ( V_2 , V_270 , 0 ) ;
if ( V_167 -> V_197 )
F_67 ( & V_2 -> V_23 ,
V_271 ,
F_3 ( V_271 ) ) ;
if ( V_5 -> V_18 . V_206 ) {
V_57 = F_68 ( V_5 -> V_18 . V_206 ,
V_272 , L_77 ) ;
if ( V_57 < 0 ) {
F_4 ( & V_167 -> V_10 , L_78 ,
V_5 -> V_18 . V_206 , V_57 ) ;
goto V_273;
}
}
return 0 ;
V_273:
return V_57 ;
}
static int F_69 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
if ( V_5 -> V_18 . V_206 ) {
F_70 ( V_5 -> V_18 . V_206 ) ;
}
return 0 ;
}
static int F_71 ( struct V_1 * V_2 ,
unsigned int V_38 )
{
return true ;
}
static T_3 int F_72 ( struct V_166 * V_167 ,
const struct V_274 * V_98 )
{
struct V_275 * V_18 = F_73 ( & V_167 -> V_10 ) ;
struct V_4 * V_5 ;
unsigned int V_38 ;
int V_57 , V_8 , V_276 ;
V_5 = F_74 ( & V_167 -> V_10 , sizeof( struct V_4 ) ,
V_277 ) ;
if ( V_5 == NULL )
return - V_278 ;
V_5 -> V_10 = & V_167 -> V_10 ;
V_5 -> V_20 = F_75 ( V_167 , & V_279 ) ;
if ( F_76 ( V_5 -> V_20 ) ) {
V_57 = F_77 ( V_5 -> V_20 ) ;
F_4 ( & V_167 -> V_10 , L_79 ,
V_57 ) ;
goto V_280;
}
for ( V_8 = 0 ; V_8 < F_3 ( V_5 -> V_170 ) ; V_8 ++ )
F_78 ( & V_5 -> V_170 [ V_8 ] . V_171 ) ;
if ( V_18 )
V_5 -> V_18 = * V_18 ;
F_79 ( V_167 , V_5 ) ;
for ( V_8 = 0 ; V_8 < F_3 ( V_5 -> V_281 ) ; V_8 ++ )
V_5 -> V_281 [ V_8 ] . V_282 = V_283 [ V_8 ] ;
V_57 = F_80 ( & V_167 -> V_10 ,
F_3 ( V_5 -> V_281 ) ,
V_5 -> V_281 ) ;
if ( V_57 != 0 ) {
F_4 ( & V_167 -> V_10 , L_80 ,
V_57 ) ;
goto V_280;
}
V_57 = F_81 ( F_3 ( V_5 -> V_281 ) ,
V_5 -> V_281 ) ;
if ( V_57 != 0 ) {
F_4 ( & V_167 -> V_10 , L_81 ,
V_57 ) ;
goto V_280;
}
if ( V_5 -> V_18 . V_284 ) {
V_57 = F_68 ( V_5 -> V_18 . V_284 ,
V_272 , L_82 ) ;
if ( V_57 < 0 ) {
F_4 ( & V_167 -> V_10 , L_83 ,
V_5 -> V_18 . V_284 , V_57 ) ;
goto V_285;
}
F_40 ( 2 ) ;
}
if ( V_5 -> V_18 . V_19 ) {
V_57 = F_68 ( V_5 -> V_18 . V_19 ,
V_272 , L_84 ) ;
if ( V_57 < 0 ) {
F_4 ( & V_167 -> V_10 , L_85 ,
V_5 -> V_18 . V_19 , V_57 ) ;
goto V_286;
}
}
V_57 = F_47 ( V_5 -> V_20 , V_21 , & V_38 ) ;
if ( V_57 < 0 ) {
F_4 ( & V_167 -> V_10 , L_86 , V_57 ) ;
goto V_287;
}
switch ( V_38 ) {
case 0x8997 :
case 0x5100 :
break;
default:
F_4 ( & V_167 -> V_10 , L_87 , V_38 ) ;
V_57 = - V_11 ;
goto V_287;
}
V_57 = F_47 ( V_5 -> V_20 , V_288 , & V_38 ) ;
if ( V_57 < 0 ) {
F_4 ( & V_167 -> V_10 , L_88 ) ;
goto V_287;
}
V_5 -> V_289 = V_38 & V_290 ;
F_82 ( & V_167 -> V_10 , L_89 , V_5 -> V_289 + 'A' ) ;
V_57 = F_10 ( V_5 ) ;
if ( V_57 < 0 ) {
F_4 ( & V_167 -> V_10 , L_90 ) ;
goto V_287;
}
switch ( V_5 -> V_289 ) {
case 0 :
V_57 = F_83 ( V_5 -> V_20 ,
V_291 ,
F_3 ( V_291 ) ) ;
if ( V_57 != 0 ) {
F_4 ( & V_167 -> V_10 , L_91 ,
V_57 ) ;
goto V_287;
}
break;
default:
break;
}
F_59 ( V_167 ) ;
for ( V_8 = 0 ; V_8 < F_3 ( V_5 -> V_18 . V_292 ) ; V_8 ++ ) {
if ( ! V_5 -> V_18 . V_292 [ V_8 ] )
continue;
F_12 ( V_5 -> V_20 , V_255 + V_8 ,
V_5 -> V_18 . V_292 [ V_8 ] ) ;
}
for ( V_8 = 0 ; V_8 < F_3 ( V_5 -> V_18 . V_293 ) ; V_8 ++ ) {
F_43 ( V_5 -> V_20 , V_294 [ V_8 ] ,
V_295 |
V_296 ,
( V_5 -> V_18 . V_293 [ V_8 ] <<
V_297 ) |
( V_5 -> V_18 . V_298 [ V_8 ] <<
V_299 ) ) ;
}
if ( V_167 -> V_197 ) {
if ( V_5 -> V_18 . V_276 )
V_276 = V_5 -> V_18 . V_276 ;
else
V_276 = V_300 ;
V_276 |= V_301 ;
if ( V_276 & ( V_302 | V_303 ) )
V_57 = F_84 ( V_167 -> V_197 , NULL ,
F_53 , V_276 ,
L_92 , V_5 ) ;
else
V_57 = F_84 ( V_167 -> V_197 , NULL , F_51 ,
V_276 , L_92 ,
V_5 ) ;
if ( V_57 != 0 ) {
F_4 ( & V_167 -> V_10 , L_93 ,
V_167 -> V_197 , V_57 ) ;
} else {
F_43 ( V_5 -> V_20 ,
V_236 ,
V_304 |
V_305 |
V_306 |
V_307 |
V_308 |
V_309 |
V_41 |
V_42 , 0 ) ;
F_43 ( V_5 -> V_20 ,
V_250 ,
V_43 |
V_44 |
V_45 |
V_46 |
V_47 |
V_48 |
V_49 |
V_50 |
V_51 |
V_52 |
V_53 |
V_54 |
V_55 |
V_56 , 0 ) ;
}
}
F_85 ( & V_167 -> V_10 ) ;
F_86 ( & V_167 -> V_10 ) ;
F_87 ( & V_167 -> V_10 ) ;
V_57 = F_88 ( & V_167 -> V_10 ,
& V_310 , V_311 ,
F_3 ( V_311 ) ) ;
if ( V_57 < 0 ) {
F_4 ( & V_167 -> V_10 , L_94 , V_57 ) ;
goto V_287;
}
return V_57 ;
V_287:
if ( V_167 -> V_197 )
F_89 ( V_167 -> V_197 , V_5 ) ;
F_62 ( V_167 ) ;
if ( V_5 -> V_18 . V_19 ) {
F_11 ( V_5 -> V_18 . V_19 , 0 ) ;
F_70 ( V_5 -> V_18 . V_19 ) ;
}
V_286:
if ( V_5 -> V_18 . V_284 ) {
F_11 ( V_5 -> V_18 . V_284 , 0 ) ;
F_70 ( V_5 -> V_18 . V_284 ) ;
}
V_285:
F_90 ( F_3 ( V_5 -> V_281 ) ,
V_5 -> V_281 ) ;
V_280:
return V_57 ;
}
static T_4 int F_91 ( struct V_166 * V_167 )
{
struct V_4 * V_5 = F_60 ( V_167 ) ;
F_92 ( & V_167 -> V_10 ) ;
if ( V_167 -> V_197 )
F_89 ( V_167 -> V_197 , V_5 ) ;
F_62 ( V_167 ) ;
if ( V_5 -> V_18 . V_19 ) {
F_11 ( V_5 -> V_18 . V_19 , 0 ) ;
F_70 ( V_5 -> V_18 . V_19 ) ;
}
if ( V_5 -> V_18 . V_284 ) {
F_11 ( V_5 -> V_18 . V_284 , 0 ) ;
F_70 ( V_5 -> V_18 . V_284 ) ;
}
return 0 ;
}
static int F_93 ( struct V_312 * V_10 )
{
struct V_4 * V_5 = F_94 ( V_10 ) ;
F_95 ( V_5 -> V_20 , true ) ;
F_96 ( V_5 -> V_20 ) ;
if ( V_5 -> V_18 . V_284 )
F_11 ( V_5 -> V_18 . V_284 , 0 ) ;
F_90 ( F_3 ( V_5 -> V_281 ) ,
V_5 -> V_281 ) ;
return 0 ;
}
static int F_97 ( struct V_312 * V_10 )
{
struct V_4 * V_5 = F_94 ( V_10 ) ;
int V_57 ;
V_57 = F_81 ( F_3 ( V_5 -> V_281 ) ,
V_5 -> V_281 ) ;
if ( V_57 != 0 ) {
F_4 ( V_10 , L_95 ,
V_57 ) ;
return V_57 ;
}
if ( V_5 -> V_18 . V_284 ) {
F_11 ( V_5 -> V_18 . V_284 , 1 ) ;
F_40 ( 2 ) ;
}
F_95 ( V_5 -> V_20 , false ) ;
F_98 ( V_5 -> V_20 ) ;
return 0 ;
}
