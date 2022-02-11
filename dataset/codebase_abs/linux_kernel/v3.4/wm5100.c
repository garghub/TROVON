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
static int F_20 ( struct V_64 * V_65 )
{
switch ( V_65 -> V_66 ) {
case 0 :
return V_67 - 1 ;
case 1 :
return V_68 - 1 ;
case 2 :
return V_69 - 1 ;
default:
F_21 () ;
return - V_11 ;
}
}
static int F_22 ( struct V_64 * V_65 , unsigned int V_70 )
{
struct V_1 * V_2 = V_65 -> V_2 ;
int V_71 , V_72 , V_73 , V_74 ;
V_74 = F_20 ( V_65 ) ;
if ( V_74 < 0 )
return V_74 ;
V_71 = 0 ;
V_72 = 0 ;
switch ( V_70 & V_75 ) {
case V_76 :
V_73 = 0 ;
break;
case V_77 :
V_73 = 1 ;
break;
case V_78 :
V_73 = 2 ;
break;
case V_79 :
V_73 = 3 ;
break;
default:
F_4 ( V_2 -> V_10 , L_28 ,
V_70 & V_75 ) ;
return - V_11 ;
}
switch ( V_70 & V_80 ) {
case V_81 :
break;
case V_82 :
V_71 |= V_83 ;
break;
case V_84 :
V_72 |= V_85 ;
break;
case V_86 :
V_71 |= V_83 ;
V_72 |= V_85 ;
break;
default:
F_4 ( V_2 -> V_10 , L_29 ,
V_70 & V_80 ) ;
return - V_11 ;
}
switch ( V_70 & V_87 ) {
case V_88 :
break;
case V_89 :
V_72 |= V_90 ;
V_71 |= V_91 ;
break;
case V_92 :
V_72 |= V_90 ;
break;
case V_93 :
V_71 |= V_91 ;
break;
default:
return - V_11 ;
}
F_7 ( V_2 , V_74 + 1 , V_85 |
V_90 , V_72 ) ;
F_7 ( V_2 , V_74 + 2 , V_83 |
V_91 , V_71 ) ;
F_7 ( V_2 , V_74 + 3 , V_83 |
V_91 , V_71 ) ;
F_7 ( V_2 , V_74 + 5 , V_94 , V_73 ) ;
return 0 ;
}
static int F_23 ( struct V_95 * V_96 ,
struct V_97 * V_98 ,
struct V_64 * V_65 )
{
struct V_1 * V_2 = V_65 -> V_2 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
bool V_99 = V_5 -> V_100 [ V_65 -> V_66 ] ;
int V_8 , V_74 , V_72 , V_101 , V_71 , V_102 , V_103 , V_104 ;
int * V_105 ;
V_74 = F_20 ( V_65 ) ;
if ( V_74 < 0 )
return V_74 ;
V_102 = F_24 ( F_25 ( V_98 ) ) ;
if ( V_102 < 0 )
return V_102 ;
V_103 = F_26 ( V_98 ) ;
if ( V_103 < 0 )
return V_103 ;
F_6 ( V_2 -> V_10 , L_30 ,
V_102 , V_103 ) ;
V_72 = F_27 ( V_98 ) ;
if ( V_72 < 0 )
return V_72 ;
if ( ! V_99 ) {
V_101 = V_5 -> V_12 ;
V_104 = F_1 ( V_2 , F_28 ( V_98 ) ) ;
if ( V_104 < 0 )
return V_104 ;
} else {
V_101 = V_5 -> V_17 ;
V_104 = 3 ;
for ( V_8 = 0 ; V_8 < F_3 ( V_9 ) ; V_8 ++ )
if ( F_28 ( V_98 ) == V_9 [ V_8 ] )
break;
if ( V_8 == F_3 ( V_9 ) ) {
F_4 ( V_2 -> V_10 , L_31 ,
F_28 ( V_98 ) ) ;
return - V_11 ;
}
F_7 ( V_2 , V_106 ,
V_107 , V_8 ) ;
}
if ( ! V_101 ) {
F_4 ( V_2 -> V_10 , L_32 ,
V_99 ? L_33 : L_34 ) ;
return - V_11 ;
}
F_6 ( V_2 -> V_10 , L_35 ,
V_72 , V_101 , V_99 ? L_33 : L_34 ) ;
if ( V_101 % 4000 )
V_105 = V_108 ;
else
V_105 = V_109 ;
for ( V_8 = 0 ; V_8 < V_110 ; V_8 ++ )
if ( V_105 [ V_8 ] >= V_72 && ( V_105 [ V_8 ] % V_72 == 0 ) )
break;
if ( V_8 == V_110 ) {
F_4 ( V_2 -> V_10 ,
L_36 ,
V_72 , V_101 , V_99 ? L_33 : L_34 ) ;
return - V_11 ;
}
V_72 = V_8 ;
F_6 ( V_2 -> V_10 , L_37 , V_105 [ V_72 ] ) ;
F_7 ( V_2 , V_74 + 1 , V_111 , V_72 ) ;
V_71 = V_105 [ V_72 ] / F_28 ( V_98 ) ;
F_6 ( V_2 -> V_10 , L_38 , V_105 [ V_72 ] / V_71 ) ;
if ( V_96 -> V_112 == V_113 ||
V_5 -> V_114 [ V_65 -> V_66 ] )
F_7 ( V_2 , V_74 + 7 ,
V_115 , V_71 ) ;
else
F_7 ( V_2 , V_74 + 6 ,
V_116 , V_71 ) ;
V_8 = ( V_102 << V_117 ) | V_103 ;
if ( V_96 -> V_112 == V_113 )
F_7 ( V_2 , V_74 + 9 ,
V_118 |
V_119 , V_8 ) ;
else
F_7 ( V_2 , V_74 + 8 ,
V_120 |
V_121 , V_8 ) ;
F_7 ( V_2 , V_74 + 4 , V_122 , V_104 ) ;
return 0 ;
}
static int F_29 ( struct V_1 * V_2 , int V_123 ,
int V_124 , unsigned int V_125 , int V_126 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
int * V_127 ;
int V_128 , V_129 , V_57 , V_38 ;
switch ( V_123 ) {
case V_130 :
V_38 = V_131 ;
V_127 = & V_5 -> V_12 ;
break;
case V_132 :
V_38 = V_133 ;
V_127 = & V_5 -> V_17 ;
break;
case V_134 :
switch ( V_124 ) {
case V_135 :
case V_136 :
case V_137 :
F_7 ( V_2 , V_138 ,
V_139 ,
V_124 ) ;
break;
default:
return - V_11 ;
}
return 0 ;
case V_140 :
case V_141 :
case V_142 :
switch ( V_124 ) {
case V_137 :
V_5 -> V_100 [ V_123 - 1 ] = false ;
break;
case V_143 :
V_5 -> V_100 [ V_123 - 1 ] = true ;
break;
default:
F_4 ( V_2 -> V_10 , L_39 , V_124 ) ;
return - V_11 ;
}
return 0 ;
case V_144 :
switch ( V_125 ) {
case 5644800 :
case 6144000 :
F_7 ( V_2 , V_145 ,
V_146 , 0 ) ;
break;
case 11289600 :
case 12288000 :
F_7 ( V_2 , V_145 ,
V_146 , 0 ) ;
break;
case 22579200 :
case 24576000 :
F_7 ( V_2 , V_145 ,
V_146 , 0 ) ;
break;
default:
F_4 ( V_2 -> V_10 , L_40 ,
V_125 ) ;
return - V_11 ;
}
return 0 ;
default:
F_4 ( V_2 -> V_10 , L_41 , V_123 ) ;
return - V_11 ;
}
switch ( V_124 ) {
case V_137 :
case V_143 :
F_4 ( V_2 -> V_10 , L_39 , V_124 ) ;
return - V_11 ;
}
switch ( V_125 ) {
case 5644800 :
case 6144000 :
V_128 = 0 ;
break;
case 11289600 :
case 12288000 :
V_128 = 1 ;
break;
case 22579200 :
case 24576000 :
V_128 = 2 ;
break;
default:
F_4 ( V_2 -> V_10 , L_42 , V_125 ) ;
return - V_11 ;
}
switch ( V_125 ) {
case 5644800 :
case 11289600 :
case 22579200 :
V_129 = 44100 ;
break;
case 6144000 :
case 12288000 :
case 24576000 :
V_129 = 48000 ;
break;
default:
F_21 () ;
V_129 = 0 ;
break;
}
F_7 ( V_2 , V_38 , V_147 |
V_148 ,
V_128 << V_149 | V_124 ) ;
if ( V_123 == V_130 ) {
F_6 ( V_2 -> V_10 , L_43 ,
V_129 ) ;
if ( 0 && * V_127 )
F_8 ( V_2 , V_129 ) ;
V_57 = F_1 ( V_2 , V_129 ) ;
if ( V_57 != 0 )
F_9 ( V_2 -> V_10 , L_44 ,
V_57 ) ;
}
* V_127 = V_125 ;
return 0 ;
}
static int F_30 ( struct V_150 * V_151 , unsigned int V_152 ,
unsigned int V_153 )
{
unsigned int V_154 ;
unsigned int div ;
unsigned int V_155 , V_156 ;
int V_8 ;
div = 1 ;
V_151 -> V_157 = 0 ;
while ( ( V_152 / div ) > 13500000 ) {
div *= 2 ;
V_151 -> V_157 ++ ;
if ( div > 8 ) {
F_31 ( L_45 ,
V_152 ) ;
return - V_11 ;
}
}
F_32 ( L_46 , V_152 , V_153 ) ;
V_152 /= div ;
div = 2 ;
while ( V_153 * div < 90000000 ) {
div ++ ;
if ( div > 64 ) {
F_31 ( L_47 ,
V_153 ) ;
return - V_11 ;
}
}
V_154 = V_153 * div ;
V_151 -> V_158 = div - 1 ;
F_32 ( L_48 , V_154 ) ;
for ( V_8 = 0 ; V_8 < F_3 ( V_159 ) ; V_8 ++ ) {
if ( V_159 [ V_8 ] . V_160 <= V_152 && V_152 <= V_159 [ V_8 ] . V_161 ) {
V_151 -> V_162 = V_159 [ V_8 ] . V_162 ;
V_155 = V_159 [ V_8 ] . V_163 ;
break;
}
}
if ( V_8 == F_3 ( V_159 ) ) {
F_31 ( L_49 , V_152 ) ;
return - V_11 ;
}
V_151 -> V_164 = V_154 / ( V_155 * V_152 ) ;
if ( V_154 % V_152 == 0 ) {
V_151 -> V_165 = 0 ;
V_151 -> V_166 = 0 ;
} else {
V_156 = F_33 ( V_154 , V_155 * V_152 ) ;
V_151 -> V_165 = ( V_154 - ( V_151 -> V_164 * V_155 * V_152 ) )
/ V_156 ;
V_151 -> V_166 = ( V_155 * V_152 ) / V_156 ;
}
F_32 ( L_50 ,
V_151 -> V_164 , V_151 -> V_165 , V_151 -> V_166 ) ;
F_32 ( L_51 ,
V_151 -> V_162 , V_155 , V_151 -> V_158 ,
V_151 -> V_157 ) ;
return 0 ;
}
static int F_34 ( struct V_1 * V_2 , int V_167 , int V_124 ,
unsigned int V_152 , unsigned int V_153 )
{
struct V_168 * V_169 = F_35 ( V_2 -> V_10 ) ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_150 V_170 ;
struct V_171 * V_172 ;
int V_57 , V_74 , V_173 , V_8 , V_174 ;
switch ( V_167 ) {
case V_175 :
V_172 = & V_5 -> V_172 [ 0 ] ;
V_74 = V_176 - 1 ;
V_173 = V_177 ;
break;
case V_178 :
V_172 = & V_5 -> V_172 [ 1 ] ;
V_74 = V_179 - 1 ;
V_173 = V_180 ;
break;
default:
F_4 ( V_2 -> V_10 , L_52 , V_167 ) ;
return - V_11 ;
}
if ( ! V_153 ) {
F_6 ( V_2 -> V_10 , L_53 , V_167 ) ;
if ( V_172 -> V_181 )
F_36 ( V_2 -> V_10 ) ;
V_172 -> V_181 = 0 ;
F_7 ( V_2 , V_74 + 1 , V_182 , 0 ) ;
return 0 ;
}
switch ( V_124 ) {
case V_183 :
case V_184 :
case V_185 :
case V_186 :
case V_187 :
case V_188 :
case V_189 :
break;
default:
F_4 ( V_2 -> V_10 , L_54 , V_124 ) ;
return - V_11 ;
}
V_57 = F_30 ( & V_170 , V_152 , V_153 ) ;
if ( V_57 < 0 )
return V_57 ;
F_7 ( V_2 , V_74 + 1 , V_182 , 0 ) ;
F_7 ( V_2 , V_74 + 2 ,
V_190 | V_191 ,
( V_170 . V_158 << V_192 ) |
V_170 . V_162 ) ;
F_7 ( V_2 , V_74 + 3 , V_193 ,
V_170 . V_165 ) ;
F_7 ( V_2 , V_74 + 5 , V_194 , V_170 . V_164 ) ;
F_7 ( V_2 , V_74 + 6 ,
V_195 |
V_196 ,
( V_170 . V_157
<< V_197 ) | V_124 ) ;
F_7 ( V_2 , V_74 + 7 , V_198 ,
V_170 . V_166 ) ;
F_37 ( & V_172 -> V_173 ) ;
F_38 ( V_2 -> V_10 ) ;
F_7 ( V_2 , V_74 + 1 , V_182 , V_182 ) ;
if ( V_169 -> V_199 )
V_174 = 2 ;
else
V_174 = 50 ;
F_7 ( V_2 , V_131 , V_200 ,
V_200 ) ;
for ( V_8 = 0 ; V_8 < V_174 ; V_8 ++ ) {
if ( V_169 -> V_199 ) {
V_57 = F_39 ( & V_172 -> V_173 ,
F_40 ( 25 ) ) ;
if ( V_57 > 0 )
break;
} else {
F_41 ( 1 ) ;
}
V_57 = F_5 ( V_2 ,
V_58 ) ;
if ( V_57 < 0 ) {
F_4 ( V_2 -> V_10 ,
L_55 ,
V_57 ) ;
continue;
}
if ( V_57 & V_173 )
break;
}
if ( V_8 == V_174 ) {
F_4 ( V_2 -> V_10 , L_56 , V_167 ) ;
F_36 ( V_2 -> V_10 ) ;
return - V_201 ;
}
V_172 -> V_202 = V_124 ;
V_172 -> V_203 = V_152 ;
V_172 -> V_181 = V_153 ;
F_6 ( V_2 -> V_10 , L_57 , V_167 ,
V_152 , V_153 ) ;
return 0 ;
}
static void F_42 ( struct V_4 * V_5 , int V_204 )
{
struct V_205 * V_206 = & V_5 -> V_18 . V_207 [ V_204 ] ;
F_43 ( V_204 >= F_3 ( V_5 -> V_18 . V_207 ) ) ;
F_11 ( V_5 -> V_18 . V_208 , V_206 -> V_208 ) ;
F_44 ( V_5 -> V_20 , V_209 ,
V_210 |
V_211 ,
( V_206 -> V_212 << V_213 ) |
V_206 -> V_214 << V_215 ) ;
F_44 ( V_5 -> V_20 , V_216 ,
V_217 ,
V_206 -> V_214 << V_218 ) ;
V_5 -> V_219 = V_204 ;
F_6 ( V_5 -> V_10 , L_58 ,
V_5 -> V_219 ) ;
}
static void F_45 ( struct V_4 * V_5 )
{
F_6 ( V_5 -> V_10 , L_59 ) ;
V_5 -> V_220 = false ;
F_46 ( V_5 -> V_221 , V_222 ,
V_222 ) ;
F_44 ( V_5 -> V_20 , V_223 ,
V_224 ,
7 << V_225 ) ;
}
static void F_47 ( struct V_4 * V_5 )
{
unsigned int V_27 ;
int V_57 ;
V_57 = F_48 ( V_5 -> V_20 , V_226 , & V_27 ) ;
if ( V_57 != 0 ) {
F_4 ( V_5 -> V_10 , L_60 ,
V_57 ) ;
return;
}
F_6 ( V_5 -> V_10 , L_61 , V_27 ) ;
if ( ! ( V_27 & V_227 ) ) {
F_9 ( V_5 -> V_10 , L_62 ) ;
return;
}
if ( ! ( V_27 & V_228 ) ) {
F_6 ( V_5 -> V_10 , L_63 ) ;
V_5 -> V_229 = false ;
V_5 -> V_220 = true ;
V_5 -> V_230 = 0 ;
F_46 ( V_5 -> V_221 , 0 ,
V_231 | V_232 |
V_233 ) ;
F_44 ( V_5 -> V_20 , V_223 ,
V_224 ,
V_224 ) ;
return;
}
if ( V_27 & 0x400 ) {
if ( V_5 -> V_220 ) {
F_6 ( V_5 -> V_10 , L_64 ) ;
V_5 -> V_229 = true ;
V_5 -> V_220 = false ;
F_46 ( V_5 -> V_221 ,
V_232 ,
V_232 | V_233 ) ;
F_44 ( V_5 -> V_20 , V_223 ,
V_224 ,
5 << V_225 ) ;
} else {
F_6 ( V_5 -> V_10 , L_65 ) ;
F_46 ( V_5 -> V_221 , 0 , V_233 ) ;
}
return;
}
if ( V_5 -> V_220 && ( V_27 & 0x3f8 ) ) {
V_5 -> V_230 ++ ;
if ( V_5 -> V_230 > 1 )
F_45 ( V_5 ) ;
else
F_42 ( V_5 , ! V_5 -> V_219 ) ;
return;
}
if ( V_27 & 0x3fc ) {
if ( V_5 -> V_229 ) {
F_6 ( V_5 -> V_10 , L_66 ) ;
F_46 ( V_5 -> V_221 , V_233 ,
V_233 ) ;
} else if ( V_5 -> V_220 ) {
F_45 ( V_5 ) ;
}
}
}
int F_49 ( struct V_1 * V_2 , struct V_234 * V_221 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
if ( V_221 ) {
V_5 -> V_221 = V_221 ;
V_5 -> V_220 = true ;
V_5 -> V_230 = 0 ;
F_42 ( V_5 , 0 ) ;
F_7 ( V_2 , V_223 ,
V_235 |
V_224 ,
( 7 << V_236 ) |
V_224 ) ;
F_50 ( & V_2 -> V_23 , L_67 ) ;
F_50 ( & V_2 -> V_23 , L_34 ) ;
F_51 ( & V_2 -> V_23 ) ;
F_7 ( V_2 , V_223 ,
V_237 , V_237 ) ;
F_7 ( V_2 , V_238 ,
V_239 , 0 ) ;
} else {
F_7 ( V_2 , V_238 ,
V_240 |
V_239 ,
V_240 |
V_239 ) ;
F_7 ( V_2 , V_223 ,
V_237 , 0 ) ;
V_5 -> V_221 = NULL ;
}
return 0 ;
}
static T_2 F_52 ( int V_199 , void * V_241 )
{
struct V_4 * V_5 = V_241 ;
T_2 V_242 = V_243 ;
unsigned int V_244 , V_245 ;
int V_57 ;
V_57 = F_48 ( V_5 -> V_20 , V_246 , & V_244 ) ;
if ( V_57 < 0 ) {
F_4 ( V_5 -> V_10 , L_68 ,
V_57 ) ;
V_244 = 0 ;
}
V_57 = F_48 ( V_5 -> V_20 , V_238 ,
& V_245 ) ;
if ( V_57 < 0 ) {
F_4 ( V_5 -> V_10 , L_69 ,
V_57 ) ;
V_245 = 0xffff ;
}
V_244 &= ~ V_245 ;
F_12 ( V_5 -> V_20 , V_246 , V_244 ) ;
if ( V_244 )
V_242 = V_247 ;
F_16 ( V_5 , V_244 ) ;
if ( V_244 & V_248 ) {
F_6 ( V_5 -> V_10 , L_70 ) ;
F_53 ( & V_5 -> V_172 [ 0 ] . V_173 ) ;
}
if ( V_244 & V_249 ) {
F_6 ( V_5 -> V_10 , L_71 ) ;
F_53 ( & V_5 -> V_172 [ 1 ] . V_173 ) ;
}
if ( V_244 & V_250 )
F_47 ( V_5 ) ;
V_57 = F_48 ( V_5 -> V_20 , V_251 , & V_244 ) ;
if ( V_57 < 0 ) {
F_4 ( V_5 -> V_10 , L_72 ,
V_57 ) ;
V_244 = 0 ;
}
V_57 = F_48 ( V_5 -> V_20 , V_252 ,
& V_245 ) ;
if ( V_57 < 0 ) {
F_4 ( V_5 -> V_10 , L_73 ,
V_57 ) ;
V_245 = 0xffff ;
}
V_244 &= ~ V_245 ;
if ( V_244 )
V_242 = V_247 ;
F_12 ( V_5 -> V_20 , V_251 , V_244 ) ;
F_18 ( V_5 , V_244 ) ;
return V_242 ;
}
static T_2 F_54 ( int V_199 , void * V_241 )
{
T_2 V_57 = V_243 ;
T_2 V_27 ;
do {
V_27 = F_52 ( V_199 , V_241 ) ;
if ( V_27 != V_243 )
V_57 = V_27 ;
} while ( V_27 != V_243 );
return V_57 ;
}
static inline struct V_4 * F_55 ( struct V_253 * V_254 )
{
return F_14 ( V_254 , struct V_4 , V_253 ) ;
}
static void F_56 ( struct V_253 * V_254 , unsigned V_255 , int V_256 )
{
struct V_4 * V_5 = F_55 ( V_254 ) ;
F_44 ( V_5 -> V_20 , V_257 + V_255 ,
V_258 , ! ! V_256 << V_259 ) ;
}
static int F_57 ( struct V_253 * V_254 ,
unsigned V_255 , int V_256 )
{
struct V_4 * V_5 = F_55 ( V_254 ) ;
int V_27 , V_57 ;
V_27 = ( 1 << V_260 ) | ( ! ! V_256 << V_259 ) ;
V_57 = F_44 ( V_5 -> V_20 , V_257 + V_255 ,
V_261 | V_262 |
V_258 , V_27 ) ;
if ( V_57 < 0 )
return V_57 ;
else
return 0 ;
}
static int F_58 ( struct V_253 * V_254 , unsigned V_255 )
{
struct V_4 * V_5 = F_55 ( V_254 ) ;
unsigned int V_38 ;
int V_57 ;
V_57 = F_48 ( V_5 -> V_20 , V_257 + V_255 , & V_38 ) ;
if ( V_57 < 0 )
return V_57 ;
return ( V_38 & V_258 ) != 0 ;
}
static int F_59 ( struct V_253 * V_254 , unsigned V_255 )
{
struct V_4 * V_5 = F_55 ( V_254 ) ;
return F_44 ( V_5 -> V_20 , V_257 + V_255 ,
V_261 | V_262 ,
( 1 << V_260 ) |
( 1 << V_263 ) ) ;
}
static void F_60 ( struct V_168 * V_169 )
{
struct V_4 * V_5 = F_61 ( V_169 ) ;
int V_57 ;
V_5 -> V_253 = V_264 ;
V_5 -> V_253 . V_265 = 6 ;
V_5 -> V_253 . V_10 = & V_169 -> V_10 ;
if ( V_5 -> V_18 . V_266 )
V_5 -> V_253 . V_74 = V_5 -> V_18 . V_266 ;
else
V_5 -> V_253 . V_74 = - 1 ;
V_57 = F_62 ( & V_5 -> V_253 ) ;
if ( V_57 != 0 )
F_4 ( & V_169 -> V_10 , L_74 , V_57 ) ;
}
static void F_63 ( struct V_168 * V_169 )
{
struct V_4 * V_5 = F_61 ( V_169 ) ;
int V_57 ;
V_57 = F_64 ( & V_5 -> V_253 ) ;
if ( V_57 != 0 )
F_4 ( & V_169 -> V_10 , L_75 , V_57 ) ;
}
static void F_60 ( struct V_168 * V_169 )
{
}
static void F_63 ( struct V_168 * V_169 )
{
}
static int F_65 ( struct V_1 * V_2 )
{
struct V_168 * V_169 = F_35 ( V_2 -> V_10 ) ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_57 , V_8 ;
V_5 -> V_2 = V_2 ;
V_2 -> V_267 = V_5 -> V_20 ;
V_57 = F_66 ( V_2 , 16 , 16 , V_268 ) ;
if ( V_57 != 0 ) {
F_4 ( V_2 -> V_10 , L_76 , V_57 ) ;
return V_57 ;
}
for ( V_8 = 0 ; V_8 < F_3 ( V_269 ) ; V_8 ++ )
F_7 ( V_2 , V_269 [ V_8 ] , V_270 ,
V_270 ) ;
F_67 ( V_2 , V_271 , 0 ) ;
F_67 ( V_2 , V_272 , 0 ) ;
if ( V_169 -> V_199 )
F_68 ( & V_2 -> V_23 ,
V_273 ,
F_3 ( V_273 ) ) ;
if ( V_5 -> V_18 . V_208 ) {
V_57 = F_69 ( V_5 -> V_18 . V_208 ,
V_274 , L_77 ) ;
if ( V_57 < 0 ) {
F_4 ( & V_169 -> V_10 , L_78 ,
V_5 -> V_18 . V_208 , V_57 ) ;
goto V_275;
}
}
return 0 ;
V_275:
return V_57 ;
}
static int F_70 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
if ( V_5 -> V_18 . V_208 ) {
F_71 ( V_5 -> V_18 . V_208 ) ;
}
return 0 ;
}
static int F_72 ( struct V_1 * V_2 ,
unsigned int V_38 )
{
return true ;
}
static T_3 int F_73 ( struct V_168 * V_169 ,
const struct V_276 * V_66 )
{
struct V_277 * V_18 = F_74 ( & V_169 -> V_10 ) ;
struct V_4 * V_5 ;
unsigned int V_38 ;
int V_57 , V_8 , V_278 ;
V_5 = F_75 ( & V_169 -> V_10 , sizeof( struct V_4 ) ,
V_279 ) ;
if ( V_5 == NULL )
return - V_280 ;
V_5 -> V_10 = & V_169 -> V_10 ;
V_5 -> V_20 = F_76 ( V_169 , & V_281 ) ;
if ( F_77 ( V_5 -> V_20 ) ) {
V_57 = F_78 ( V_5 -> V_20 ) ;
F_4 ( & V_169 -> V_10 , L_79 ,
V_57 ) ;
goto V_282;
}
for ( V_8 = 0 ; V_8 < F_3 ( V_5 -> V_172 ) ; V_8 ++ )
F_79 ( & V_5 -> V_172 [ V_8 ] . V_173 ) ;
if ( V_18 )
V_5 -> V_18 = * V_18 ;
F_80 ( V_169 , V_5 ) ;
for ( V_8 = 0 ; V_8 < F_3 ( V_5 -> V_283 ) ; V_8 ++ )
V_5 -> V_283 [ V_8 ] . V_284 = V_285 [ V_8 ] ;
V_57 = F_81 ( & V_169 -> V_10 ,
F_3 ( V_5 -> V_283 ) ,
V_5 -> V_283 ) ;
if ( V_57 != 0 ) {
F_4 ( & V_169 -> V_10 , L_80 ,
V_57 ) ;
goto V_286;
}
V_57 = F_82 ( F_3 ( V_5 -> V_283 ) ,
V_5 -> V_283 ) ;
if ( V_57 != 0 ) {
F_4 ( & V_169 -> V_10 , L_81 ,
V_57 ) ;
goto V_286;
}
if ( V_5 -> V_18 . V_287 ) {
V_57 = F_69 ( V_5 -> V_18 . V_287 ,
V_274 , L_82 ) ;
if ( V_57 < 0 ) {
F_4 ( & V_169 -> V_10 , L_83 ,
V_5 -> V_18 . V_287 , V_57 ) ;
goto V_288;
}
F_41 ( 2 ) ;
}
if ( V_5 -> V_18 . V_19 ) {
V_57 = F_69 ( V_5 -> V_18 . V_19 ,
V_274 , L_84 ) ;
if ( V_57 < 0 ) {
F_4 ( & V_169 -> V_10 , L_85 ,
V_5 -> V_18 . V_19 , V_57 ) ;
goto V_289;
}
}
V_57 = F_48 ( V_5 -> V_20 , V_21 , & V_38 ) ;
if ( V_57 < 0 ) {
F_4 ( & V_169 -> V_10 , L_86 , V_57 ) ;
goto V_290;
}
switch ( V_38 ) {
case 0x8997 :
case 0x5100 :
break;
default:
F_4 ( & V_169 -> V_10 , L_87 , V_38 ) ;
V_57 = - V_11 ;
goto V_290;
}
V_57 = F_48 ( V_5 -> V_20 , V_291 , & V_38 ) ;
if ( V_57 < 0 ) {
F_4 ( & V_169 -> V_10 , L_88 ) ;
goto V_290;
}
V_5 -> V_292 = V_38 & V_293 ;
F_83 ( & V_169 -> V_10 , L_89 , V_5 -> V_292 + 'A' ) ;
V_57 = F_10 ( V_5 ) ;
if ( V_57 < 0 ) {
F_4 ( & V_169 -> V_10 , L_90 ) ;
goto V_290;
}
switch ( V_5 -> V_292 ) {
case 0 :
V_57 = F_84 ( V_5 -> V_20 ,
V_294 ,
F_3 ( V_294 ) ) ;
if ( V_57 != 0 ) {
F_4 ( & V_169 -> V_10 , L_91 ,
V_57 ) ;
goto V_290;
}
break;
default:
break;
}
F_60 ( V_169 ) ;
for ( V_8 = 0 ; V_8 < F_3 ( V_5 -> V_18 . V_295 ) ; V_8 ++ ) {
if ( ! V_5 -> V_18 . V_295 [ V_8 ] )
continue;
F_12 ( V_5 -> V_20 , V_257 + V_8 ,
V_5 -> V_18 . V_295 [ V_8 ] ) ;
}
for ( V_8 = 0 ; V_8 < F_3 ( V_5 -> V_18 . V_296 ) ; V_8 ++ ) {
F_44 ( V_5 -> V_20 , V_297 [ V_8 ] ,
V_298 |
V_299 ,
( V_5 -> V_18 . V_296 [ V_8 ] <<
V_300 ) |
( V_5 -> V_18 . V_301 [ V_8 ] <<
V_302 ) ) ;
}
if ( V_169 -> V_199 ) {
if ( V_5 -> V_18 . V_278 )
V_278 = V_5 -> V_18 . V_278 ;
else
V_278 = V_303 ;
V_278 |= V_304 ;
if ( V_278 & ( V_305 | V_306 ) )
V_57 = F_85 ( V_169 -> V_199 , NULL ,
F_54 , V_278 ,
L_92 , V_5 ) ;
else
V_57 = F_85 ( V_169 -> V_199 , NULL , F_52 ,
V_278 , L_92 ,
V_5 ) ;
if ( V_57 != 0 ) {
F_4 ( & V_169 -> V_10 , L_93 ,
V_169 -> V_199 , V_57 ) ;
} else {
F_44 ( V_5 -> V_20 ,
V_238 ,
V_307 |
V_308 |
V_309 |
V_310 |
V_311 |
V_312 |
V_41 |
V_42 , 0 ) ;
F_44 ( V_5 -> V_20 ,
V_252 ,
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
F_86 ( & V_169 -> V_10 ) ;
F_87 ( & V_169 -> V_10 ) ;
F_88 ( & V_169 -> V_10 ) ;
V_57 = F_89 ( & V_169 -> V_10 ,
& V_313 , V_314 ,
F_3 ( V_314 ) ) ;
if ( V_57 < 0 ) {
F_4 ( & V_169 -> V_10 , L_94 , V_57 ) ;
goto V_290;
}
return V_57 ;
V_290:
if ( V_169 -> V_199 )
F_90 ( V_169 -> V_199 , V_5 ) ;
F_63 ( V_169 ) ;
if ( V_5 -> V_18 . V_19 ) {
F_11 ( V_5 -> V_18 . V_19 , 0 ) ;
F_71 ( V_5 -> V_18 . V_19 ) ;
}
V_289:
if ( V_5 -> V_18 . V_287 ) {
F_11 ( V_5 -> V_18 . V_287 , 0 ) ;
F_71 ( V_5 -> V_18 . V_287 ) ;
}
V_288:
F_91 ( F_3 ( V_5 -> V_283 ) ,
V_5 -> V_283 ) ;
V_286:
F_92 ( V_5 -> V_20 ) ;
V_282:
return V_57 ;
}
static T_4 int F_93 ( struct V_168 * V_169 )
{
struct V_4 * V_5 = F_61 ( V_169 ) ;
F_94 ( & V_169 -> V_10 ) ;
if ( V_169 -> V_199 )
F_90 ( V_169 -> V_199 , V_5 ) ;
F_63 ( V_169 ) ;
if ( V_5 -> V_18 . V_19 ) {
F_11 ( V_5 -> V_18 . V_19 , 0 ) ;
F_71 ( V_5 -> V_18 . V_19 ) ;
}
if ( V_5 -> V_18 . V_287 ) {
F_11 ( V_5 -> V_18 . V_287 , 0 ) ;
F_71 ( V_5 -> V_18 . V_287 ) ;
}
F_92 ( V_5 -> V_20 ) ;
return 0 ;
}
static int F_95 ( struct V_315 * V_10 )
{
struct V_4 * V_5 = F_96 ( V_10 ) ;
F_97 ( V_5 -> V_20 , true ) ;
F_98 ( V_5 -> V_20 ) ;
if ( V_5 -> V_18 . V_287 )
F_11 ( V_5 -> V_18 . V_287 , 0 ) ;
F_91 ( F_3 ( V_5 -> V_283 ) ,
V_5 -> V_283 ) ;
return 0 ;
}
static int F_99 ( struct V_315 * V_10 )
{
struct V_4 * V_5 = F_96 ( V_10 ) ;
int V_57 ;
V_57 = F_82 ( F_3 ( V_5 -> V_283 ) ,
V_5 -> V_283 ) ;
if ( V_57 != 0 ) {
F_4 ( V_10 , L_95 ,
V_57 ) ;
return V_57 ;
}
if ( V_5 -> V_18 . V_287 ) {
F_11 ( V_5 -> V_18 . V_287 , 1 ) ;
F_41 ( 2 ) ;
}
F_97 ( V_5 -> V_20 , false ) ;
F_100 ( V_5 -> V_20 ) ;
return 0 ;
}
static int T_5 F_101 ( void )
{
return F_102 ( & V_316 ) ;
}
static void T_6 F_103 ( void )
{
F_104 ( & V_316 ) ;
}
