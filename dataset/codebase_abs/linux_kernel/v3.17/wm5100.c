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
struct V_1 * V_2 = F_14 ( V_23 ) ;
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
V_69 = 2 ;
break;
default:
F_4 ( V_2 -> V_10 , L_28 ,
V_66 & V_72 ) ;
return - V_11 ;
}
switch ( V_66 & V_75 ) {
case V_76 :
break;
case V_77 :
V_67 |= V_78 ;
break;
case V_79 :
V_68 |= V_80 ;
break;
case V_81 :
V_67 |= V_78 ;
V_68 |= V_80 ;
break;
default:
F_4 ( V_2 -> V_10 , L_29 ,
V_66 & V_75 ) ;
return - V_11 ;
}
switch ( V_66 & V_82 ) {
case V_83 :
break;
case V_84 :
V_68 |= V_85 ;
V_67 |= V_86 ;
break;
case V_87 :
V_68 |= V_85 ;
break;
case V_88 :
V_67 |= V_86 ;
break;
default:
return - V_11 ;
}
F_7 ( V_2 , V_70 + 1 , V_80 |
V_85 , V_68 ) ;
F_7 ( V_2 , V_70 + 2 , V_78 |
V_86 , V_67 ) ;
F_7 ( V_2 , V_70 + 3 , V_78 |
V_86 , V_67 ) ;
F_7 ( V_2 , V_70 + 5 , V_89 , V_69 ) ;
return 0 ;
}
static int F_21 ( struct V_90 * V_91 ,
struct V_92 * V_93 ,
struct V_64 * V_65 )
{
struct V_1 * V_2 = V_65 -> V_2 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
bool V_94 = V_5 -> V_95 [ V_65 -> V_96 ] ;
int V_8 , V_70 , V_68 , V_97 , V_67 , V_98 , V_99 , V_100 ;
int * V_101 ;
V_70 = V_65 -> V_71 -> V_70 ;
V_98 = F_22 ( F_23 ( V_93 ) ) ;
if ( V_98 < 0 )
return V_98 ;
V_99 = F_24 ( V_93 ) ;
if ( V_99 < 0 )
return V_99 ;
F_6 ( V_2 -> V_10 , L_30 ,
V_98 , V_99 ) ;
V_68 = F_25 ( V_93 ) ;
if ( V_68 < 0 )
return V_68 ;
if ( ! V_94 ) {
V_97 = V_5 -> V_12 ;
V_100 = F_1 ( V_2 , F_26 ( V_93 ) ) ;
if ( V_100 < 0 )
return V_100 ;
} else {
V_97 = V_5 -> V_17 ;
V_100 = 3 ;
for ( V_8 = 0 ; V_8 < F_3 ( V_9 ) ; V_8 ++ )
if ( F_26 ( V_93 ) == V_9 [ V_8 ] )
break;
if ( V_8 == F_3 ( V_9 ) ) {
F_4 ( V_2 -> V_10 , L_31 ,
F_26 ( V_93 ) ) ;
return - V_11 ;
}
F_7 ( V_2 , V_102 ,
V_103 , V_8 ) ;
}
if ( ! V_97 ) {
F_4 ( V_2 -> V_10 , L_32 ,
V_94 ? L_33 : L_34 ) ;
return - V_11 ;
}
F_6 ( V_2 -> V_10 , L_35 ,
V_68 , V_97 , V_94 ? L_33 : L_34 ) ;
if ( V_97 % 4000 )
V_101 = V_104 ;
else
V_101 = V_105 ;
for ( V_8 = 0 ; V_8 < V_106 ; V_8 ++ )
if ( V_101 [ V_8 ] >= V_68 && ( V_101 [ V_8 ] % V_68 == 0 ) )
break;
if ( V_8 == V_106 ) {
F_4 ( V_2 -> V_10 ,
L_36 ,
V_68 , V_97 , V_94 ? L_33 : L_34 ) ;
return - V_11 ;
}
V_68 = V_8 ;
F_6 ( V_2 -> V_10 , L_37 , V_101 [ V_68 ] ) ;
F_7 ( V_2 , V_70 + 1 , V_107 , V_68 ) ;
V_67 = V_101 [ V_68 ] / F_26 ( V_93 ) ;
F_6 ( V_2 -> V_10 , L_38 , V_101 [ V_68 ] / V_67 ) ;
if ( V_91 -> V_108 == V_109 ||
V_5 -> V_110 [ V_65 -> V_96 ] )
F_7 ( V_2 , V_70 + 7 ,
V_111 , V_67 ) ;
else
F_7 ( V_2 , V_70 + 6 ,
V_112 , V_67 ) ;
V_8 = ( V_98 << V_113 ) | V_99 ;
if ( V_91 -> V_108 == V_109 )
F_7 ( V_2 , V_70 + 9 ,
V_114 |
V_115 , V_8 ) ;
else
F_7 ( V_2 , V_70 + 8 ,
V_116 |
V_117 , V_8 ) ;
F_7 ( V_2 , V_70 + 4 , V_118 , V_100 ) ;
return 0 ;
}
static int F_27 ( struct V_1 * V_2 , int V_119 ,
int V_120 , unsigned int V_121 , int V_122 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
int * V_123 ;
int V_124 , V_125 , V_57 , V_38 ;
switch ( V_119 ) {
case V_126 :
V_38 = V_127 ;
V_123 = & V_5 -> V_12 ;
break;
case V_128 :
V_38 = V_129 ;
V_123 = & V_5 -> V_17 ;
break;
case V_130 :
switch ( V_120 ) {
case V_131 :
case V_132 :
case V_133 :
F_7 ( V_2 , V_134 ,
V_135 ,
V_120 ) ;
break;
default:
return - V_11 ;
}
return 0 ;
case V_136 :
case V_137 :
case V_138 :
switch ( V_120 ) {
case V_133 :
V_5 -> V_95 [ V_119 - 1 ] = false ;
break;
case V_139 :
V_5 -> V_95 [ V_119 - 1 ] = true ;
break;
default:
F_4 ( V_2 -> V_10 , L_39 , V_120 ) ;
return - V_11 ;
}
return 0 ;
case V_140 :
switch ( V_121 ) {
case 5644800 :
case 6144000 :
F_7 ( V_2 , V_141 ,
V_142 , 0 ) ;
break;
case 11289600 :
case 12288000 :
F_7 ( V_2 , V_141 ,
V_142 , 0 ) ;
break;
case 22579200 :
case 24576000 :
F_7 ( V_2 , V_141 ,
V_142 , 0 ) ;
break;
default:
F_4 ( V_2 -> V_10 , L_40 ,
V_121 ) ;
return - V_11 ;
}
return 0 ;
default:
F_4 ( V_2 -> V_10 , L_41 , V_119 ) ;
return - V_11 ;
}
switch ( V_120 ) {
case V_133 :
case V_139 :
F_4 ( V_2 -> V_10 , L_39 , V_120 ) ;
return - V_11 ;
}
switch ( V_121 ) {
case 5644800 :
case 6144000 :
V_124 = 0 ;
break;
case 11289600 :
case 12288000 :
V_124 = 1 ;
break;
case 22579200 :
case 24576000 :
V_124 = 2 ;
break;
default:
F_4 ( V_2 -> V_10 , L_42 , V_121 ) ;
return - V_11 ;
}
switch ( V_121 ) {
case 5644800 :
case 11289600 :
case 22579200 :
V_125 = 44100 ;
break;
case 6144000 :
case 12288000 :
case 24576000 :
V_125 = 48000 ;
break;
default:
F_28 () ;
V_125 = 0 ;
break;
}
F_7 ( V_2 , V_38 , V_143 |
V_144 ,
V_124 << V_145 | V_120 ) ;
if ( V_119 == V_126 ) {
F_6 ( V_2 -> V_10 , L_43 ,
V_125 ) ;
if ( 0 && * V_123 )
F_8 ( V_2 , V_125 ) ;
V_57 = F_1 ( V_2 , V_125 ) ;
if ( V_57 != 0 )
F_9 ( V_2 -> V_10 , L_44 ,
V_57 ) ;
}
* V_123 = V_121 ;
return 0 ;
}
static int F_29 ( struct V_146 * V_147 , unsigned int V_148 ,
unsigned int V_149 )
{
unsigned int V_150 ;
unsigned int div ;
unsigned int V_151 , V_152 ;
int V_8 ;
div = 1 ;
V_147 -> V_153 = 0 ;
while ( ( V_148 / div ) > 13500000 ) {
div *= 2 ;
V_147 -> V_153 ++ ;
if ( div > 8 ) {
F_30 ( L_45 ,
V_148 ) ;
return - V_11 ;
}
}
F_31 ( L_46 , V_148 , V_149 ) ;
V_148 /= div ;
div = 2 ;
while ( V_149 * div < 90000000 ) {
div ++ ;
if ( div > 64 ) {
F_30 ( L_47 ,
V_149 ) ;
return - V_11 ;
}
}
V_150 = V_149 * div ;
V_147 -> V_154 = div - 1 ;
F_31 ( L_48 , V_150 ) ;
for ( V_8 = 0 ; V_8 < F_3 ( V_155 ) ; V_8 ++ ) {
if ( V_155 [ V_8 ] . V_156 <= V_148 && V_148 <= V_155 [ V_8 ] . V_157 ) {
V_147 -> V_158 = V_155 [ V_8 ] . V_158 ;
V_151 = V_155 [ V_8 ] . V_159 ;
break;
}
}
if ( V_8 == F_3 ( V_155 ) ) {
F_30 ( L_49 , V_148 ) ;
return - V_11 ;
}
V_147 -> V_160 = V_150 / ( V_151 * V_148 ) ;
if ( V_150 % V_148 == 0 ) {
V_147 -> V_161 = 0 ;
V_147 -> V_162 = 0 ;
} else {
V_152 = F_32 ( V_150 , V_151 * V_148 ) ;
V_147 -> V_161 = ( V_150 - ( V_147 -> V_160 * V_151 * V_148 ) )
/ V_152 ;
V_147 -> V_162 = ( V_151 * V_148 ) / V_152 ;
}
F_31 ( L_50 ,
V_147 -> V_160 , V_147 -> V_161 , V_147 -> V_162 ) ;
F_31 ( L_51 ,
V_147 -> V_158 , V_151 , V_147 -> V_154 ,
V_147 -> V_153 ) ;
return 0 ;
}
static int F_33 ( struct V_1 * V_2 , int V_163 , int V_120 ,
unsigned int V_148 , unsigned int V_149 )
{
struct V_164 * V_165 = F_34 ( V_2 -> V_10 ) ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_146 V_166 ;
struct V_167 * V_168 ;
int V_57 , V_70 , V_169 , V_8 , V_170 ;
switch ( V_163 ) {
case V_171 :
V_168 = & V_5 -> V_168 [ 0 ] ;
V_70 = V_172 - 1 ;
V_169 = V_173 ;
break;
case V_174 :
V_168 = & V_5 -> V_168 [ 1 ] ;
V_70 = V_175 - 1 ;
V_169 = V_176 ;
break;
default:
F_4 ( V_2 -> V_10 , L_52 , V_163 ) ;
return - V_11 ;
}
if ( ! V_149 ) {
F_6 ( V_2 -> V_10 , L_53 , V_163 ) ;
if ( V_168 -> V_177 )
F_35 ( V_2 -> V_10 ) ;
V_168 -> V_177 = 0 ;
F_7 ( V_2 , V_70 + 1 , V_178 , 0 ) ;
return 0 ;
}
switch ( V_120 ) {
case V_179 :
case V_180 :
case V_181 :
case V_182 :
case V_183 :
case V_184 :
case V_185 :
break;
default:
F_4 ( V_2 -> V_10 , L_54 , V_120 ) ;
return - V_11 ;
}
V_57 = F_29 ( & V_166 , V_148 , V_149 ) ;
if ( V_57 < 0 )
return V_57 ;
F_7 ( V_2 , V_70 + 1 , V_178 , 0 ) ;
F_7 ( V_2 , V_70 + 2 ,
V_186 | V_187 ,
( V_166 . V_154 << V_188 ) |
V_166 . V_158 ) ;
F_7 ( V_2 , V_70 + 3 , V_189 ,
V_166 . V_161 ) ;
F_7 ( V_2 , V_70 + 5 , V_190 , V_166 . V_160 ) ;
F_7 ( V_2 , V_70 + 6 ,
V_191 |
V_192 ,
( V_166 . V_153
<< V_193 ) | V_120 ) ;
F_7 ( V_2 , V_70 + 7 , V_194 ,
V_166 . V_162 ) ;
F_36 ( & V_168 -> V_169 ) ;
F_37 ( V_2 -> V_10 ) ;
F_7 ( V_2 , V_70 + 1 , V_178 , V_178 ) ;
if ( V_165 -> V_195 )
V_170 = 2 ;
else
V_170 = 50 ;
F_7 ( V_2 , V_127 , V_196 ,
V_196 ) ;
for ( V_8 = 0 ; V_8 < V_170 ; V_8 ++ ) {
if ( V_165 -> V_195 ) {
V_57 = F_38 ( & V_168 -> V_169 ,
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
if ( V_57 & V_169 )
break;
}
if ( V_8 == V_170 ) {
F_4 ( V_2 -> V_10 , L_56 , V_163 ) ;
F_35 ( V_2 -> V_10 ) ;
return - V_197 ;
}
V_168 -> V_198 = V_120 ;
V_168 -> V_199 = V_148 ;
V_168 -> V_177 = V_149 ;
F_6 ( V_2 -> V_10 , L_57 , V_163 ,
V_148 , V_149 ) ;
return 0 ;
}
static void F_41 ( struct V_4 * V_5 , int V_200 )
{
struct V_201 * V_202 = & V_5 -> V_18 . V_203 [ V_200 ] ;
if ( F_42 ( V_200 >= F_3 ( V_5 -> V_18 . V_203 ) ) )
return;
F_11 ( V_5 -> V_18 . V_204 , V_202 -> V_204 ) ;
F_43 ( V_5 -> V_20 , V_205 ,
V_206 |
V_207 ,
( V_202 -> V_208 << V_209 ) |
V_202 -> V_210 << V_211 ) ;
F_43 ( V_5 -> V_20 , V_212 ,
V_213 ,
V_202 -> V_210 << V_214 ) ;
V_5 -> V_215 = V_200 ;
F_6 ( V_5 -> V_10 , L_58 ,
V_5 -> V_215 ) ;
}
static void F_44 ( struct V_4 * V_5 )
{
F_6 ( V_5 -> V_10 , L_59 ) ;
V_5 -> V_216 = false ;
F_45 ( V_5 -> V_217 , V_218 ,
V_218 ) ;
F_43 ( V_5 -> V_20 , V_219 ,
V_220 ,
7 << V_221 ) ;
}
static void F_46 ( struct V_4 * V_5 )
{
unsigned int V_27 ;
int V_57 ;
V_57 = F_47 ( V_5 -> V_20 , V_222 , & V_27 ) ;
if ( V_57 != 0 ) {
F_4 ( V_5 -> V_10 , L_60 ,
V_57 ) ;
return;
}
F_6 ( V_5 -> V_10 , L_61 , V_27 ) ;
if ( ! ( V_27 & V_223 ) ) {
F_9 ( V_5 -> V_10 , L_62 ) ;
return;
}
if ( ! ( V_27 & V_224 ) ) {
F_6 ( V_5 -> V_10 , L_63 ) ;
V_5 -> V_225 = false ;
V_5 -> V_216 = true ;
V_5 -> V_226 = 0 ;
F_45 ( V_5 -> V_217 , 0 ,
V_227 | V_228 |
V_229 ) ;
F_43 ( V_5 -> V_20 , V_219 ,
V_220 ,
V_220 ) ;
return;
}
if ( V_27 & 0x400 ) {
if ( V_5 -> V_216 ) {
F_6 ( V_5 -> V_10 , L_64 ) ;
V_5 -> V_225 = true ;
V_5 -> V_216 = false ;
F_45 ( V_5 -> V_217 ,
V_228 ,
V_228 | V_229 ) ;
F_43 ( V_5 -> V_20 , V_219 ,
V_220 ,
5 << V_221 ) ;
} else {
F_6 ( V_5 -> V_10 , L_65 ) ;
F_45 ( V_5 -> V_217 , 0 , V_229 ) ;
}
return;
}
if ( V_5 -> V_216 && ( V_27 & 0x3f8 ) ) {
V_5 -> V_226 ++ ;
if ( V_5 -> V_226 > 1 )
F_44 ( V_5 ) ;
else
F_41 ( V_5 , ! V_5 -> V_215 ) ;
return;
}
if ( V_27 & 0x3fc ) {
if ( V_5 -> V_225 ) {
F_6 ( V_5 -> V_10 , L_66 ) ;
F_45 ( V_5 -> V_217 , V_229 ,
V_229 ) ;
} else if ( V_5 -> V_216 ) {
F_44 ( V_5 ) ;
}
}
}
int F_48 ( struct V_1 * V_2 , struct V_230 * V_217 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_22 * V_23 = & V_2 -> V_23 ;
if ( V_217 ) {
V_5 -> V_217 = V_217 ;
V_5 -> V_216 = true ;
V_5 -> V_226 = 0 ;
F_41 ( V_5 , 0 ) ;
F_7 ( V_2 , V_219 ,
V_231 |
V_220 ,
( 7 << V_232 ) |
V_220 ) ;
F_49 ( V_23 ) ;
F_50 ( V_23 , L_67 ) ;
F_50 ( V_23 , L_34 ) ;
F_51 ( V_23 ) ;
F_52 ( V_23 ) ;
F_7 ( V_2 , V_219 ,
V_233 , V_233 ) ;
F_7 ( V_2 , V_234 ,
V_235 , 0 ) ;
} else {
F_7 ( V_2 , V_234 ,
V_236 |
V_235 ,
V_236 |
V_235 ) ;
F_7 ( V_2 , V_219 ,
V_233 , 0 ) ;
V_5 -> V_217 = NULL ;
}
return 0 ;
}
static T_2 F_53 ( int V_195 , void * V_237 )
{
struct V_4 * V_5 = V_237 ;
T_2 V_238 = V_239 ;
unsigned int V_240 , V_241 ;
int V_57 ;
V_57 = F_47 ( V_5 -> V_20 , V_242 , & V_240 ) ;
if ( V_57 < 0 ) {
F_4 ( V_5 -> V_10 , L_68 ,
V_57 ) ;
V_240 = 0 ;
}
V_57 = F_47 ( V_5 -> V_20 , V_234 ,
& V_241 ) ;
if ( V_57 < 0 ) {
F_4 ( V_5 -> V_10 , L_69 ,
V_57 ) ;
V_241 = 0xffff ;
}
V_240 &= ~ V_241 ;
F_12 ( V_5 -> V_20 , V_242 , V_240 ) ;
if ( V_240 )
V_238 = V_243 ;
F_16 ( V_5 , V_240 ) ;
if ( V_240 & V_244 ) {
F_6 ( V_5 -> V_10 , L_70 ) ;
F_54 ( & V_5 -> V_168 [ 0 ] . V_169 ) ;
}
if ( V_240 & V_245 ) {
F_6 ( V_5 -> V_10 , L_71 ) ;
F_54 ( & V_5 -> V_168 [ 1 ] . V_169 ) ;
}
if ( V_240 & V_246 )
F_46 ( V_5 ) ;
V_57 = F_47 ( V_5 -> V_20 , V_247 , & V_240 ) ;
if ( V_57 < 0 ) {
F_4 ( V_5 -> V_10 , L_72 ,
V_57 ) ;
V_240 = 0 ;
}
V_57 = F_47 ( V_5 -> V_20 , V_248 ,
& V_241 ) ;
if ( V_57 < 0 ) {
F_4 ( V_5 -> V_10 , L_73 ,
V_57 ) ;
V_241 = 0xffff ;
}
V_240 &= ~ V_241 ;
if ( V_240 )
V_238 = V_243 ;
F_12 ( V_5 -> V_20 , V_247 , V_240 ) ;
F_18 ( V_5 , V_240 ) ;
return V_238 ;
}
static T_2 F_55 ( int V_195 , void * V_237 )
{
T_2 V_57 = V_239 ;
T_2 V_27 ;
do {
V_27 = F_53 ( V_195 , V_237 ) ;
if ( V_27 != V_239 )
V_57 = V_27 ;
} while ( V_27 != V_239 );
return V_57 ;
}
static inline struct V_4 * F_56 ( struct V_249 * V_250 )
{
return F_57 ( V_250 , struct V_4 , V_249 ) ;
}
static void F_58 ( struct V_249 * V_250 , unsigned V_251 , int V_252 )
{
struct V_4 * V_5 = F_56 ( V_250 ) ;
F_43 ( V_5 -> V_20 , V_253 + V_251 ,
V_254 , ! ! V_252 << V_255 ) ;
}
static int F_59 ( struct V_249 * V_250 ,
unsigned V_251 , int V_252 )
{
struct V_4 * V_5 = F_56 ( V_250 ) ;
int V_27 , V_57 ;
V_27 = ( 1 << V_256 ) | ( ! ! V_252 << V_255 ) ;
V_57 = F_43 ( V_5 -> V_20 , V_253 + V_251 ,
V_257 | V_258 |
V_254 , V_27 ) ;
if ( V_57 < 0 )
return V_57 ;
else
return 0 ;
}
static int F_60 ( struct V_249 * V_250 , unsigned V_251 )
{
struct V_4 * V_5 = F_56 ( V_250 ) ;
unsigned int V_38 ;
int V_57 ;
V_57 = F_47 ( V_5 -> V_20 , V_253 + V_251 , & V_38 ) ;
if ( V_57 < 0 )
return V_57 ;
return ( V_38 & V_254 ) != 0 ;
}
static int F_61 ( struct V_249 * V_250 , unsigned V_251 )
{
struct V_4 * V_5 = F_56 ( V_250 ) ;
return F_43 ( V_5 -> V_20 , V_253 + V_251 ,
V_257 | V_258 ,
( 1 << V_256 ) |
( 1 << V_259 ) ) ;
}
static void F_62 ( struct V_164 * V_165 )
{
struct V_4 * V_5 = F_63 ( V_165 ) ;
int V_57 ;
V_5 -> V_249 = V_260 ;
V_5 -> V_249 . V_261 = 6 ;
V_5 -> V_249 . V_10 = & V_165 -> V_10 ;
if ( V_5 -> V_18 . V_262 )
V_5 -> V_249 . V_70 = V_5 -> V_18 . V_262 ;
else
V_5 -> V_249 . V_70 = - 1 ;
V_57 = F_64 ( & V_5 -> V_249 ) ;
if ( V_57 != 0 )
F_4 ( & V_165 -> V_10 , L_74 , V_57 ) ;
}
static void F_65 ( struct V_164 * V_165 )
{
struct V_4 * V_5 = F_63 ( V_165 ) ;
int V_57 ;
V_57 = F_66 ( & V_5 -> V_249 ) ;
if ( V_57 != 0 )
F_4 ( & V_165 -> V_10 , L_75 , V_57 ) ;
}
static void F_62 ( struct V_164 * V_165 )
{
}
static void F_65 ( struct V_164 * V_165 )
{
}
static int F_67 ( struct V_1 * V_2 )
{
struct V_164 * V_165 = F_34 ( V_2 -> V_10 ) ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_57 , V_8 ;
V_5 -> V_2 = V_2 ;
for ( V_8 = 0 ; V_8 < F_3 ( V_263 ) ; V_8 ++ )
F_7 ( V_2 , V_263 [ V_8 ] , V_264 ,
V_264 ) ;
F_68 ( V_2 , V_265 , 0 ) ;
F_68 ( V_2 , V_266 , 0 ) ;
if ( V_165 -> V_195 )
F_69 ( & V_2 -> V_23 ,
V_267 ,
F_3 ( V_267 ) ) ;
if ( V_5 -> V_18 . V_204 ) {
V_57 = F_70 ( V_5 -> V_18 . V_204 ,
V_268 , L_76 ) ;
if ( V_57 < 0 ) {
F_4 ( & V_165 -> V_10 , L_77 ,
V_5 -> V_18 . V_204 , V_57 ) ;
goto V_269;
}
}
return 0 ;
V_269:
return V_57 ;
}
static int F_71 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
if ( V_5 -> V_18 . V_204 ) {
F_72 ( V_5 -> V_18 . V_204 ) ;
}
return 0 ;
}
static int F_73 ( struct V_164 * V_165 ,
const struct V_270 * V_96 )
{
struct V_271 * V_18 = F_74 ( & V_165 -> V_10 ) ;
struct V_4 * V_5 ;
unsigned int V_38 ;
int V_57 , V_8 , V_272 ;
V_5 = F_75 ( & V_165 -> V_10 , sizeof( struct V_4 ) ,
V_273 ) ;
if ( V_5 == NULL )
return - V_274 ;
V_5 -> V_10 = & V_165 -> V_10 ;
V_5 -> V_20 = F_76 ( V_165 , & V_275 ) ;
if ( F_77 ( V_5 -> V_20 ) ) {
V_57 = F_78 ( V_5 -> V_20 ) ;
F_4 ( & V_165 -> V_10 , L_78 ,
V_57 ) ;
goto V_276;
}
for ( V_8 = 0 ; V_8 < F_3 ( V_5 -> V_168 ) ; V_8 ++ )
F_79 ( & V_5 -> V_168 [ V_8 ] . V_169 ) ;
if ( V_18 )
V_5 -> V_18 = * V_18 ;
F_80 ( V_165 , V_5 ) ;
for ( V_8 = 0 ; V_8 < F_3 ( V_5 -> V_277 ) ; V_8 ++ )
V_5 -> V_277 [ V_8 ] . V_278 = V_279 [ V_8 ] ;
V_57 = F_81 ( & V_165 -> V_10 ,
F_3 ( V_5 -> V_277 ) ,
V_5 -> V_277 ) ;
if ( V_57 != 0 ) {
F_4 ( & V_165 -> V_10 , L_79 ,
V_57 ) ;
goto V_276;
}
V_57 = F_82 ( F_3 ( V_5 -> V_277 ) ,
V_5 -> V_277 ) ;
if ( V_57 != 0 ) {
F_4 ( & V_165 -> V_10 , L_80 ,
V_57 ) ;
goto V_276;
}
if ( V_5 -> V_18 . V_280 ) {
V_57 = F_70 ( V_5 -> V_18 . V_280 ,
V_268 , L_81 ) ;
if ( V_57 < 0 ) {
F_4 ( & V_165 -> V_10 , L_82 ,
V_5 -> V_18 . V_280 , V_57 ) ;
goto V_281;
}
F_40 ( 2 ) ;
}
if ( V_5 -> V_18 . V_19 ) {
V_57 = F_70 ( V_5 -> V_18 . V_19 ,
V_268 , L_83 ) ;
if ( V_57 < 0 ) {
F_4 ( & V_165 -> V_10 , L_84 ,
V_5 -> V_18 . V_19 , V_57 ) ;
goto V_282;
}
}
V_57 = F_47 ( V_5 -> V_20 , V_21 , & V_38 ) ;
if ( V_57 < 0 ) {
F_4 ( & V_165 -> V_10 , L_85 , V_57 ) ;
goto V_283;
}
switch ( V_38 ) {
case 0x8997 :
case 0x5100 :
break;
default:
F_4 ( & V_165 -> V_10 , L_86 , V_38 ) ;
V_57 = - V_11 ;
goto V_283;
}
V_57 = F_47 ( V_5 -> V_20 , V_284 , & V_38 ) ;
if ( V_57 < 0 ) {
F_4 ( & V_165 -> V_10 , L_87 ) ;
goto V_283;
}
V_5 -> V_285 = V_38 & V_286 ;
F_83 ( & V_165 -> V_10 , L_88 , V_5 -> V_285 + 'A' ) ;
V_57 = F_10 ( V_5 ) ;
if ( V_57 < 0 ) {
F_4 ( & V_165 -> V_10 , L_89 ) ;
goto V_283;
}
switch ( V_5 -> V_285 ) {
case 0 :
V_57 = F_84 ( V_5 -> V_20 ,
V_287 ,
F_3 ( V_287 ) ) ;
if ( V_57 != 0 ) {
F_4 ( & V_165 -> V_10 , L_90 ,
V_57 ) ;
goto V_283;
}
break;
default:
break;
}
F_62 ( V_165 ) ;
for ( V_8 = 0 ; V_8 < F_3 ( V_5 -> V_18 . V_288 ) ; V_8 ++ ) {
if ( ! V_5 -> V_18 . V_288 [ V_8 ] )
continue;
F_12 ( V_5 -> V_20 , V_253 + V_8 ,
V_5 -> V_18 . V_288 [ V_8 ] ) ;
}
for ( V_8 = 0 ; V_8 < F_3 ( V_5 -> V_18 . V_289 ) ; V_8 ++ ) {
F_43 ( V_5 -> V_20 , V_290 [ V_8 ] ,
V_291 |
V_292 ,
( V_5 -> V_18 . V_289 [ V_8 ] <<
V_293 ) |
( V_5 -> V_18 . V_294 [ V_8 ] <<
V_295 ) ) ;
}
if ( V_165 -> V_195 ) {
if ( V_5 -> V_18 . V_272 )
V_272 = V_5 -> V_18 . V_272 ;
else
V_272 = V_296 ;
V_272 |= V_297 ;
if ( V_272 & ( V_298 | V_299 ) )
V_57 = F_85 ( V_165 -> V_195 , NULL ,
F_55 , V_272 ,
L_91 , V_5 ) ;
else
V_57 = F_85 ( V_165 -> V_195 , NULL , F_53 ,
V_272 , L_91 ,
V_5 ) ;
if ( V_57 != 0 ) {
F_4 ( & V_165 -> V_10 , L_92 ,
V_165 -> V_195 , V_57 ) ;
} else {
F_43 ( V_5 -> V_20 ,
V_234 ,
V_300 |
V_301 |
V_302 |
V_303 |
V_304 |
V_305 |
V_41 |
V_42 , 0 ) ;
F_43 ( V_5 -> V_20 ,
V_248 ,
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
F_86 ( & V_165 -> V_10 ) ;
F_87 ( & V_165 -> V_10 ) ;
F_88 ( & V_165 -> V_10 ) ;
V_57 = F_89 ( & V_165 -> V_10 ,
& V_306 , V_307 ,
F_3 ( V_307 ) ) ;
if ( V_57 < 0 ) {
F_4 ( & V_165 -> V_10 , L_93 , V_57 ) ;
goto V_283;
}
return V_57 ;
V_283:
if ( V_165 -> V_195 )
F_90 ( V_165 -> V_195 , V_5 ) ;
F_65 ( V_165 ) ;
if ( V_5 -> V_18 . V_19 ) {
F_11 ( V_5 -> V_18 . V_19 , 0 ) ;
F_72 ( V_5 -> V_18 . V_19 ) ;
}
V_282:
if ( V_5 -> V_18 . V_280 ) {
F_11 ( V_5 -> V_18 . V_280 , 0 ) ;
F_72 ( V_5 -> V_18 . V_280 ) ;
}
V_281:
F_91 ( F_3 ( V_5 -> V_277 ) ,
V_5 -> V_277 ) ;
V_276:
return V_57 ;
}
static int F_92 ( struct V_164 * V_165 )
{
struct V_4 * V_5 = F_63 ( V_165 ) ;
F_93 ( & V_165 -> V_10 ) ;
if ( V_165 -> V_195 )
F_90 ( V_165 -> V_195 , V_5 ) ;
F_65 ( V_165 ) ;
if ( V_5 -> V_18 . V_19 ) {
F_11 ( V_5 -> V_18 . V_19 , 0 ) ;
F_72 ( V_5 -> V_18 . V_19 ) ;
}
if ( V_5 -> V_18 . V_280 ) {
F_11 ( V_5 -> V_18 . V_280 , 0 ) ;
F_72 ( V_5 -> V_18 . V_280 ) ;
}
return 0 ;
}
static int F_94 ( struct V_308 * V_10 )
{
struct V_4 * V_5 = F_95 ( V_10 ) ;
F_96 ( V_5 -> V_20 , true ) ;
F_97 ( V_5 -> V_20 ) ;
if ( V_5 -> V_18 . V_280 )
F_11 ( V_5 -> V_18 . V_280 , 0 ) ;
F_91 ( F_3 ( V_5 -> V_277 ) ,
V_5 -> V_277 ) ;
return 0 ;
}
static int F_98 ( struct V_308 * V_10 )
{
struct V_4 * V_5 = F_95 ( V_10 ) ;
int V_57 ;
V_57 = F_82 ( F_3 ( V_5 -> V_277 ) ,
V_5 -> V_277 ) ;
if ( V_57 != 0 ) {
F_4 ( V_10 , L_94 ,
V_57 ) ;
return V_57 ;
}
if ( V_5 -> V_18 . V_280 ) {
F_11 ( V_5 -> V_18 . V_280 , 1 ) ;
F_40 ( 2 ) ;
}
F_96 ( V_5 -> V_20 , false ) ;
F_99 ( V_5 -> V_20 ) ;
return 0 ;
}
