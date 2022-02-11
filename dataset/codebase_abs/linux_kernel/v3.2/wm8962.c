static int F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
if ( V_4 [ V_3 ] . V_5 )
return 1 ;
else
return 0 ;
}
static int F_2 ( struct V_1 * V_2 , unsigned int V_3 )
{
if ( V_4 [ V_3 ] . V_6 )
return 1 ;
else
return 0 ;
}
static int F_3 ( struct V_1 * V_2 )
{
int V_7 ;
V_7 = F_4 ( V_2 , V_8 , 0x6243 ) ;
if ( V_7 != 0 )
return V_7 ;
return F_4 ( V_2 , V_9 , 0 ) ;
}
static int F_5 ( struct V_1 * V_2 )
{
return 0 ;
}
static int F_6 ( struct V_1 * V_2 , T_1 V_10 )
{
T_1 V_11 = F_7 ( V_2 , V_12 ) ;
T_1 V_13 = F_7 ( V_2 , V_14 ) ;
T_1 V_15 = F_7 ( V_2 , V_16 ) ;
F_4 ( V_2 , V_12 , 0 ) ;
F_4 ( V_2 , V_14 , V_17 ) ;
F_8 ( V_2 , V_16 ,
V_18 , V_18 ) ;
F_4 ( V_2 , V_19 , V_10 ) ;
F_4 ( V_2 , V_12 , V_11 ) ;
F_4 ( V_2 , V_14 , V_13 ) ;
F_8 ( V_2 , V_16 ,
V_18 , V_15 ) ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 )
{
struct V_20 * V_21 = F_10 ( V_2 ) ;
F_5 ( V_2 ) ;
F_4 ( V_2 , V_22 , V_23 ) ;
F_6 ( V_2 , V_21 -> V_24 ) ;
return 0 ;
}
static int F_11 ( struct V_1 * V_2 )
{
F_6 ( V_2 , 0 ) ;
F_4 ( V_2 , V_22 , V_25 ) ;
return 0 ;
}
static int F_12 ( struct V_26 * V_27 ,
struct V_28 * V_29 )
{
V_29 -> type = V_30 ;
V_29 -> V_31 = 1 ;
V_29 -> V_32 . integer . V_33 = 0 ;
V_29 -> V_32 . integer . V_34 = 1 ;
return 0 ;
}
static int F_13 ( struct V_26 * V_27 ,
struct V_35 * V_36 )
{
int V_37 = V_27 -> V_38 ;
struct V_1 * V_2 = F_14 ( V_27 ) ;
struct V_20 * V_21 = F_10 ( V_2 ) ;
V_36 -> V_32 . integer . V_32 [ 0 ] = ! ! ( V_21 -> V_24 & 1 << V_37 ) ;
return 0 ;
}
static int F_15 ( struct V_26 * V_27 ,
struct V_35 * V_36 )
{
int V_37 = V_27 -> V_38 ;
struct V_1 * V_2 = F_14 ( V_27 ) ;
struct V_20 * V_21 = F_10 ( V_2 ) ;
int V_39 = V_21 -> V_24 ;
int V_7 = 0 ;
int V_40 = F_7 ( V_2 , V_41 ) &
V_42 ;
F_16 ( & V_2 -> V_43 ) ;
if ( V_36 -> V_32 . integer . V_32 [ 0 ] )
V_21 -> V_24 |= 1 << V_37 ;
else
V_21 -> V_24 &= ~ ( 1 << V_37 ) ;
if ( V_21 -> V_24 == V_39 )
goto V_44;
V_7 = 1 ;
if ( V_40 ) {
if ( V_21 -> V_24 )
F_6 ( V_2 , V_21 -> V_24 ) ;
else
F_11 ( V_2 ) ;
}
V_44:
F_17 ( & V_2 -> V_43 ) ;
return V_7 ;
}
static int F_18 ( struct V_26 * V_27 ,
struct V_35 * V_36 )
{
struct V_1 * V_2 = F_14 ( V_27 ) ;
T_1 * V_45 = V_2 -> V_45 ;
int V_7 ;
V_7 = F_19 ( V_27 , V_36 ) ;
if ( V_7 == 0 )
return 0 ;
if ( F_7 ( V_2 , V_46 ) & V_47 )
return F_4 ( V_2 , V_48 ,
V_45 [ V_48 ] ) ;
if ( F_7 ( V_2 , V_46 ) & V_49 )
return F_4 ( V_2 , V_50 ,
V_45 [ V_50 ] ) ;
return 0 ;
}
static int F_20 ( struct V_26 * V_27 ,
struct V_35 * V_36 )
{
struct V_1 * V_2 = F_14 ( V_27 ) ;
int V_7 ;
V_7 = F_19 ( V_27 , V_36 ) ;
if ( V_7 == 0 )
return 0 ;
V_7 = F_7 ( V_2 , V_46 ) ;
if ( V_7 & V_51 ) {
F_4 ( V_2 , V_52 ,
F_7 ( V_2 , V_52 ) ) ;
return 1 ;
}
if ( V_7 & V_53 )
F_4 ( V_2 , V_54 ,
F_7 ( V_2 , V_54 ) ) ;
return 1 ;
}
static int F_21 ( struct V_55 * V_56 ,
struct V_26 * V_27 , int V_57 )
{
struct V_1 * V_2 = V_56 -> V_2 ;
struct V_20 * V_21 = F_10 ( V_2 ) ;
unsigned long V_58 ;
int V_59 ;
int V_60 ;
V_59 = F_7 ( V_2 , V_61 ) & V_62 ;
switch ( V_59 ) {
case 0 :
V_60 = 0 ;
break;
case 0x200 :
V_60 = 1 ;
break;
default:
F_22 ( V_2 -> V_63 , L_1 , V_59 ) ;
return - V_64 ;
}
switch ( V_57 ) {
case V_65 :
if ( V_60 ) {
F_23 ( & V_21 -> V_66 ) ;
F_8 ( V_2 , V_67 ,
V_68 , V_68 ) ;
V_58 = F_24 ( 5 ) ;
V_58 = F_25 ( & V_21 -> V_66 ,
V_58 ) ;
if ( V_21 -> V_69 && V_58 == 0 )
F_22 ( V_2 -> V_63 ,
L_2 ) ;
}
break;
case V_70 :
if ( V_60 )
F_8 ( V_2 , V_67 ,
V_68 , 0 ) ;
break;
default:
F_26 () ;
return - V_64 ;
}
return 0 ;
}
static int F_27 ( struct V_55 * V_56 ,
struct V_26 * V_27 , int V_57 )
{
switch ( V_57 ) {
case V_71 :
F_28 ( 5 ) ;
break;
default:
F_26 () ;
return - V_64 ;
}
return 0 ;
}
static int F_29 ( struct V_55 * V_56 ,
struct V_26 * V_27 , int V_57 )
{
struct V_1 * V_2 = V_56 -> V_2 ;
int V_58 ;
int V_3 ;
int V_72 = ( V_73 |
V_74 ) ;
switch ( V_57 ) {
case V_71 :
F_8 ( V_2 , V_75 ,
V_76 | V_77 ,
V_76 | V_77 ) ;
F_30 ( 20 ) ;
F_8 ( V_2 , V_75 ,
V_78 | V_79 ,
V_78 | V_79 ) ;
F_8 ( V_2 , V_80 ,
V_81 | V_82 |
V_83 |
V_84 ,
V_81 | V_82 |
V_83 |
V_84 ) ;
V_58 = 0 ;
do {
F_28 ( 1 ) ;
V_3 = F_7 ( V_2 , V_85 ) ;
if ( V_3 < 0 ) {
F_22 ( V_2 -> V_63 ,
L_3 ,
V_3 ) ;
continue;
}
F_31 ( V_2 -> V_63 , L_4 , V_3 ) ;
} while ( ++ V_58 < 200 && ( V_3 & V_72 ) != V_72 );
if ( ( V_3 & V_72 ) != V_72 )
F_22 ( V_2 -> V_63 , L_5 ) ;
else
F_31 ( V_2 -> V_63 , L_6 ,
V_58 ) ;
F_8 ( V_2 , V_75 ,
V_86 |
V_87 ,
V_86 |
V_87 ) ;
F_30 ( 20 ) ;
F_8 ( V_2 , V_75 ,
V_88 |
V_89 ,
V_88 |
V_89 ) ;
break;
case V_90 :
F_8 ( V_2 , V_75 ,
V_88 |
V_89 , 0 ) ;
F_30 ( 20 ) ;
F_8 ( V_2 , V_80 ,
V_81 | V_82 |
V_83 |
V_84 ,
0 ) ;
F_8 ( V_2 , V_75 ,
V_76 | V_77 |
V_78 | V_79 |
V_86 |
V_87 , 0 ) ;
break;
default:
F_26 () ;
return - V_64 ;
}
return 0 ;
}
static int F_32 ( struct V_55 * V_56 ,
struct V_26 * V_27 , int V_57 )
{
struct V_1 * V_2 = V_56 -> V_2 ;
int V_3 ;
switch ( V_56 -> V_37 ) {
case V_91 :
V_3 = V_50 ;
break;
case V_92 :
V_3 = V_48 ;
break;
case V_93 :
V_3 = V_54 ;
break;
case V_94 :
V_3 = V_52 ;
break;
default:
F_26 () ;
return - V_64 ;
}
switch ( V_57 ) {
case V_71 :
return F_4 ( V_2 , V_3 , F_7 ( V_2 , V_3 ) ) ;
default:
F_26 () ;
return - V_64 ;
}
}
static int F_33 ( struct V_55 * V_56 ,
struct V_26 * V_27 , int V_57 )
{
struct V_1 * V_2 = V_56 -> V_2 ;
struct V_20 * V_21 = F_10 ( V_2 ) ;
switch ( V_57 ) {
case V_71 :
if ( V_21 -> V_24 )
F_9 ( V_2 ) ;
break;
case V_90 :
if ( V_21 -> V_24 )
F_11 ( V_2 ) ;
break;
default:
F_26 () ;
return - V_64 ;
}
return 0 ;
}
static int F_34 ( struct V_1 * V_2 )
{
struct V_95 * V_96 = F_35 ( V_2 -> V_63 ) ;
struct V_97 * V_98 = & V_2 -> V_98 ;
F_36 ( V_2 , V_99 ,
F_37 ( V_99 ) ) ;
if ( V_96 && V_96 -> V_100 )
F_36 ( V_2 , V_101 ,
F_37 ( V_101 ) ) ;
else
F_36 ( V_2 , V_102 ,
F_37 ( V_102 ) ) ;
F_38 ( V_98 , V_103 ,
F_37 ( V_103 ) ) ;
if ( V_96 && V_96 -> V_100 )
F_38 ( V_98 , V_104 ,
F_37 ( V_104 ) ) ;
else
F_38 ( V_98 , V_105 ,
F_37 ( V_105 ) ) ;
F_39 ( V_98 , V_106 ,
F_37 ( V_106 ) ) ;
if ( V_96 && V_96 -> V_100 )
F_39 ( V_98 , V_107 ,
F_37 ( V_107 ) ) ;
else
F_39 ( V_98 , V_108 ,
F_37 ( V_108 ) ) ;
F_40 ( V_98 , L_7 ) ;
return 0 ;
}
static void F_41 ( struct V_1 * V_2 )
{
T_1 * V_45 = V_2 -> V_45 ;
int V_109 ;
if ( ! V_2 -> V_110 )
return;
F_31 ( V_2 -> V_63 , L_8 ) ;
V_2 -> V_111 = 0 ;
for ( V_109 = 1 ; V_109 < V_2 -> V_112 -> V_113 ; V_109 ++ ) {
if ( V_109 == V_8 )
continue;
if ( V_45 [ V_109 ] == V_114 [ V_109 ] )
continue;
F_4 ( V_2 , V_109 , V_45 [ V_109 ] ) ;
}
V_2 -> V_110 = 0 ;
}
static void F_42 ( struct V_1 * V_2 )
{
struct V_20 * V_21 = F_10 ( V_2 ) ;
int V_115 , V_109 ;
int V_116 = 0 ;
int V_117 = 0 ;
int V_118 = 0 ;
if ( ! V_21 -> V_119 ) {
F_31 ( V_2 -> V_63 , L_9 ) ;
return;
}
if ( ! V_21 -> V_120 || ! V_21 -> V_121 ) {
F_31 ( V_2 -> V_63 , L_10 ) ;
return;
}
for ( V_109 = 0 ; V_109 < F_37 ( V_122 ) ; V_109 ++ ) {
if ( V_122 [ V_109 ] == V_21 -> V_119 / V_21 -> V_121 ) {
V_117 |= V_109 << V_123 ;
break;
}
}
if ( V_109 == F_37 ( V_122 ) ) {
F_22 ( V_2 -> V_63 , L_11 ,
V_21 -> V_119 / V_21 -> V_121 ) ;
return;
}
F_8 ( V_2 , V_124 ,
V_125 , V_117 ) ;
V_115 = F_7 ( V_2 , V_126 ) ;
if ( V_115 < 0 ) {
F_22 ( V_2 -> V_63 , L_12 , V_115 ) ;
return;
}
V_115 = ( V_115 & V_127 ) >> V_128 ;
switch ( V_115 ) {
case 0 :
V_115 = V_21 -> V_119 ;
break;
case 1 :
V_115 = V_21 -> V_119 / 2 ;
break;
case 2 :
V_115 = V_21 -> V_119 / 4 ;
break;
default:
F_43 ( V_2 -> V_63 , L_13 ) ;
V_115 = V_21 -> V_129 ;
}
F_31 ( V_2 -> V_63 , L_14 , V_115 , V_21 -> V_120 ) ;
for ( V_109 = 0 ; V_109 < F_37 ( V_130 ) ; V_109 ++ ) {
if ( V_130 [ V_109 ] < 0 )
continue;
if ( V_115 / V_130 [ V_109 ] == V_21 -> V_120 ) {
F_31 ( V_2 -> V_63 , L_15 ,
V_130 [ V_109 ] , V_21 -> V_120 ) ;
V_116 |= V_109 ;
break;
}
}
if ( V_109 == F_37 ( V_130 ) ) {
F_22 ( V_2 -> V_63 , L_16 ,
V_115 / V_21 -> V_120 ) ;
return;
}
V_118 |= V_21 -> V_120 / V_21 -> V_121 ;
F_31 ( V_2 -> V_63 , L_17 ,
V_21 -> V_120 / V_21 -> V_121 , V_21 -> V_121 ) ;
F_8 ( V_2 , V_61 ,
V_131 , V_116 ) ;
F_8 ( V_2 , V_132 ,
V_133 , V_118 ) ;
}
static int F_44 ( struct V_1 * V_2 ,
enum V_134 V_135 )
{
struct V_20 * V_21 = F_10 ( V_2 ) ;
int V_7 ;
if ( V_135 == V_2 -> V_98 . V_136 )
return 0 ;
switch ( V_135 ) {
case V_137 :
break;
case V_138 :
F_8 ( V_2 , V_139 ,
V_140 , 0x80 ) ;
F_42 ( V_2 ) ;
break;
case V_141 :
if ( V_2 -> V_98 . V_136 == V_142 ) {
V_7 = F_45 ( F_37 ( V_21 -> V_143 ) ,
V_21 -> V_143 ) ;
if ( V_7 != 0 ) {
F_22 ( V_2 -> V_63 ,
L_18 ,
V_7 ) ;
return V_7 ;
}
F_41 ( V_2 ) ;
F_8 ( V_2 , V_144 ,
V_145 |
V_146 ,
V_145 |
V_146 ) ;
F_8 ( V_2 , V_139 ,
V_140 |
V_147 ,
V_147 | 0x180 ) ;
F_28 ( 5 ) ;
}
F_8 ( V_2 , V_139 ,
V_140 , 0x100 ) ;
break;
case V_142 :
F_8 ( V_2 , V_139 ,
V_140 | V_147 , 0 ) ;
F_8 ( V_2 , V_144 ,
V_145 |
V_146 , 0 ) ;
F_46 ( F_37 ( V_21 -> V_143 ) ,
V_21 -> V_143 ) ;
break;
}
V_2 -> V_98 . V_136 = V_135 ;
return 0 ;
}
static int F_47 ( struct V_148 * V_149 ,
struct V_150 * V_151 ,
struct V_152 * V_153 )
{
struct V_154 * V_155 = V_149 -> V_156 ;
struct V_1 * V_2 = V_155 -> V_2 ;
struct V_20 * V_21 = F_10 ( V_2 ) ;
int V_109 ;
int V_157 = 0 ;
int V_158 = 0 ;
V_21 -> V_120 = F_48 ( V_151 ) ;
V_21 -> V_121 = F_49 ( V_151 ) ;
for ( V_109 = 0 ; V_109 < F_37 ( V_159 ) ; V_109 ++ ) {
if ( V_159 [ V_109 ] . V_160 == V_21 -> V_121 ) {
V_158 |= V_159 [ V_109 ] . V_3 ;
break;
}
}
if ( V_109 == F_37 ( V_159 ) ) {
F_22 ( V_2 -> V_63 , L_19 , V_21 -> V_121 ) ;
return - V_64 ;
}
if ( V_21 -> V_121 % 8000 == 0 )
V_158 |= V_161 ;
switch ( F_50 ( V_151 ) ) {
case V_162 :
break;
case V_163 :
V_157 |= 0x40 ;
break;
case V_164 :
V_157 |= 0x80 ;
break;
case V_165 :
V_157 |= 0xc0 ;
break;
default:
return - V_64 ;
}
F_8 ( V_2 , V_166 ,
V_167 , V_157 ) ;
F_8 ( V_2 , V_168 ,
V_161 |
V_169 , V_158 ) ;
F_42 ( V_2 ) ;
return 0 ;
}
static int F_51 ( struct V_152 * V_153 , int V_170 ,
unsigned int V_171 , int V_172 )
{
struct V_1 * V_2 = V_153 -> V_2 ;
struct V_20 * V_21 = F_10 ( V_2 ) ;
int V_59 ;
switch ( V_170 ) {
case V_173 :
V_21 -> V_129 = V_173 ;
V_59 = 0 ;
break;
case V_174 :
V_21 -> V_129 = V_174 ;
V_59 = 1 << V_175 ;
break;
default:
return - V_64 ;
}
F_8 ( V_2 , V_61 , V_62 ,
V_59 ) ;
V_21 -> V_119 = V_171 ;
return 0 ;
}
static int F_52 ( struct V_152 * V_153 , unsigned int V_176 )
{
struct V_1 * V_2 = V_153 -> V_2 ;
int V_157 = 0 ;
switch ( V_176 & V_177 ) {
case V_178 :
V_157 |= V_179 | 3 ;
case V_180 :
V_157 |= 3 ;
switch ( V_176 & V_181 ) {
case V_182 :
case V_183 :
break;
default:
return - V_64 ;
}
break;
case V_184 :
break;
case V_185 :
V_157 |= 1 ;
break;
case V_186 :
V_157 |= 2 ;
break;
default:
return - V_64 ;
}
switch ( V_176 & V_181 ) {
case V_182 :
break;
case V_183 :
V_157 |= V_187 ;
break;
case V_188 :
V_157 |= V_179 ;
break;
case V_189 :
V_157 |= V_187 | V_179 ;
break;
default:
return - V_64 ;
}
switch ( V_176 & V_190 ) {
case V_191 :
V_157 |= V_192 ;
break;
case V_193 :
break;
default:
return - V_64 ;
}
F_8 ( V_2 , V_166 ,
V_194 | V_187 | V_192 |
V_179 , V_157 ) ;
return 0 ;
}
static int F_53 ( struct V_195 * V_196 , unsigned int V_197 ,
unsigned int V_198 )
{
unsigned int V_199 ;
unsigned int div ;
unsigned int V_200 , V_201 ;
int V_109 ;
div = 1 ;
V_196 -> V_202 = 0 ;
while ( ( V_197 / div ) > 13500000 ) {
div *= 2 ;
V_196 -> V_202 ++ ;
if ( div > 4 ) {
F_54 ( L_20 ,
V_197 ) ;
return - V_64 ;
}
}
F_55 ( L_21 , V_197 , V_198 ) ;
V_197 /= div ;
div = 2 ;
while ( V_198 * div < 90000000 ) {
div ++ ;
if ( div > 64 ) {
F_54 ( L_22 ,
V_198 ) ;
return - V_64 ;
}
}
V_199 = V_198 * div ;
V_196 -> V_203 = div - 1 ;
F_55 ( L_23 , V_199 ) ;
for ( V_109 = 0 ; V_109 < F_37 ( V_204 ) ; V_109 ++ ) {
if ( V_204 [ V_109 ] . V_33 <= V_197 && V_197 <= V_204 [ V_109 ] . V_34 ) {
V_196 -> V_205 = V_204 [ V_109 ] . V_205 ;
V_200 = V_204 [ V_109 ] . V_206 ;
break;
}
}
if ( V_109 == F_37 ( V_204 ) ) {
F_54 ( L_24 , V_197 ) ;
return - V_64 ;
}
V_196 -> V_207 = V_199 / ( V_200 * V_197 ) ;
if ( V_199 % V_197 == 0 ) {
V_196 -> V_208 = 0 ;
V_196 -> V_209 = 0 ;
} else {
V_201 = F_56 ( V_199 , V_200 * V_197 ) ;
V_196 -> V_208 = ( V_199 - ( V_196 -> V_207 * V_200 * V_197 ) )
/ V_201 ;
V_196 -> V_209 = ( V_200 * V_197 ) / V_201 ;
}
F_55 ( L_25 ,
V_196 -> V_207 , V_196 -> V_208 , V_196 -> V_209 ) ;
F_55 ( L_26 ,
V_196 -> V_205 , V_196 -> V_203 ,
V_196 -> V_202 ) ;
return 0 ;
}
static int F_57 ( struct V_1 * V_2 , int V_210 , int V_211 ,
unsigned int V_197 , unsigned int V_198 )
{
struct V_20 * V_21 = F_10 ( V_2 ) ;
struct V_195 V_196 ;
unsigned long V_58 ;
int V_7 ;
int V_212 = F_7 ( V_2 , V_67 ) & V_68 ;
if ( V_211 == V_21 -> V_213 && V_197 == V_21 -> V_214 &&
V_198 == V_21 -> V_215 )
return 0 ;
if ( V_198 == 0 ) {
F_31 ( V_2 -> V_63 , L_27 ) ;
V_21 -> V_214 = 0 ;
V_21 -> V_215 = 0 ;
F_8 ( V_2 , V_67 ,
V_68 , 0 ) ;
return 0 ;
}
V_7 = F_53 ( & V_196 , V_197 , V_198 ) ;
if ( V_7 != 0 )
return V_7 ;
switch ( V_210 ) {
case V_216 :
case V_217 :
case V_218 :
V_212 |= ( V_210 - 1 ) << V_219 ;
break;
case V_220 :
F_8 ( V_2 , V_67 ,
V_221 , V_221 ) ;
F_8 ( V_2 , V_222 ,
V_223 , V_223 ) ;
break;
default:
F_22 ( V_2 -> V_63 , L_28 , V_7 ) ;
return - V_64 ;
}
if ( V_196 . V_208 || V_196 . V_209 )
V_212 |= V_224 ;
F_8 ( V_2 , V_67 , V_68 , 0 ) ;
F_8 ( V_2 , V_225 ,
V_226 |
V_227 ,
( V_196 . V_203 << V_228 ) |
( V_196 . V_202 ) ) ;
F_8 ( V_2 , V_229 ,
V_230 , V_196 . V_205 ) ;
F_4 ( V_2 , V_231 , V_196 . V_208 ) ;
F_4 ( V_2 , V_232 , V_196 . V_209 ) ;
F_4 ( V_2 , V_233 , V_196 . V_207 ) ;
F_23 ( & V_21 -> V_66 ) ;
F_8 ( V_2 , V_67 ,
V_224 | V_234 |
V_68 , V_212 ) ;
F_31 ( V_2 -> V_63 , L_29 , V_197 , V_198 ) ;
V_7 = 0 ;
if ( V_212 & V_68 ) {
if ( V_21 -> V_69 )
V_58 = F_24 ( 5 ) ;
else
V_58 = F_24 ( 1 ) ;
V_58 = F_25 ( & V_21 -> V_66 ,
V_58 ) ;
if ( V_58 == 0 && V_21 -> V_69 ) {
F_22 ( V_2 -> V_63 , L_30 ) ;
V_7 = - V_235 ;
}
}
V_21 -> V_214 = V_197 ;
V_21 -> V_215 = V_198 ;
V_21 -> V_213 = V_211 ;
return V_7 ;
}
static int F_58 ( struct V_152 * V_153 , int V_236 )
{
struct V_1 * V_2 = V_153 -> V_2 ;
int V_10 ;
if ( V_236 )
V_10 = V_18 ;
else
V_10 = 0 ;
return F_8 ( V_2 , V_16 ,
V_18 , V_10 ) ;
}
static void F_59 ( struct V_237 * V_238 )
{
struct V_20 * V_21 = F_60 ( V_238 ,
struct V_20 ,
V_239 . V_238 ) ;
struct V_1 * V_2 = V_21 -> V_2 ;
int V_240 = 0 ;
int V_241 = 0 ;
int V_3 ;
V_3 = F_7 ( V_2 , V_242 ) ;
if ( V_3 & V_243 ) {
V_240 |= V_244 ;
V_241 |= V_245 ;
}
if ( V_3 & V_246 ) {
V_240 |= V_247 ;
V_241 |= V_248 ;
}
F_61 ( V_21 -> V_249 , V_240 ,
V_244 | V_247 ) ;
F_8 ( V_2 , V_250 ,
V_248 |
V_245 , V_241 ) ;
}
static T_2 F_62 ( int V_69 , void * V_251 )
{
struct V_1 * V_2 = V_251 ;
struct V_20 * V_21 = F_10 ( V_2 ) ;
int V_252 ;
int V_253 ;
int V_3 ;
V_252 = F_7 ( V_2 , V_254 ) ;
V_253 = F_7 ( V_2 , V_255 ) ;
V_253 &= ~ V_252 ;
if ( ! V_253 )
return V_256 ;
F_4 ( V_2 , V_255 , V_253 ) ;
if ( V_253 & V_257 ) {
F_31 ( V_2 -> V_63 , L_31 ) ;
F_63 ( & V_21 -> V_66 ) ;
}
if ( V_253 & V_258 )
F_22 ( V_2 -> V_63 , L_32 ) ;
if ( V_253 & V_259 ) {
F_64 ( V_2 -> V_63 , L_33 ) ;
V_3 = F_7 ( V_2 , V_260 ) ;
if ( V_3 & V_261 )
F_64 ( V_2 -> V_63 , L_34 ) ;
if ( V_3 & V_262 )
F_64 ( V_2 -> V_63 , L_35 ) ;
if ( V_3 & V_263 )
F_64 ( V_2 -> V_63 , L_36 ) ;
if ( V_3 & V_264 )
F_64 ( V_2 -> V_63 , L_37 ) ;
}
if ( V_253 & ( V_265 | V_266 ) ) {
F_31 ( V_2 -> V_63 , L_38 ) ;
#ifndef F_65
F_66 ( F_67 ( V_2 -> V_63 ) ) ;
#endif
F_68 ( V_2 -> V_63 , 300 ) ;
F_69 ( & V_21 -> V_239 ,
F_24 ( 250 ) ) ;
}
return V_267 ;
}
int F_70 ( struct V_1 * V_2 , struct V_268 * V_249 )
{
struct V_20 * V_21 = F_10 ( V_2 ) ;
int V_269 , V_270 ;
V_21 -> V_249 = V_249 ;
if ( V_249 ) {
V_269 = 0 ;
V_270 = V_271 ;
} else {
V_269 = V_266 | V_265 ;
V_270 = 0 ;
}
F_8 ( V_2 , V_254 ,
V_266 | V_265 , V_269 ) ;
F_8 ( V_2 , V_242 ,
V_271 , V_270 ) ;
F_61 ( V_21 -> V_249 , 0 ,
V_244 | V_247 ) ;
return 0 ;
}
static void F_71 ( struct V_237 * V_238 )
{
struct V_20 * V_21 =
F_60 ( V_238 , struct V_20 , V_272 ) ;
struct V_1 * V_2 = V_21 -> V_2 ;
struct V_97 * V_98 = & V_2 -> V_98 ;
int V_109 ;
int V_3 = 0 ;
int V_273 = 0 ;
if ( V_21 -> V_274 ) {
for ( V_109 = 0 ; V_109 < F_37 ( V_275 ) ; V_109 ++ ) {
if ( abs ( V_21 -> V_274 - V_275 [ V_109 ] ) <
abs ( V_21 -> V_274 - V_275 [ V_273 ] ) )
V_273 = V_109 ;
}
F_31 ( V_2 -> V_63 , L_39 ,
V_275 [ V_273 ] , V_21 -> V_274 ) ;
V_3 = V_276 | ( V_273 << V_277 ) ;
F_72 ( V_98 , L_7 ) ;
} else {
F_31 ( V_2 -> V_63 , L_40 ) ;
F_40 ( V_98 , L_7 ) ;
}
F_8 ( V_2 , V_278 ,
V_276 | V_279 , V_3 ) ;
F_73 ( V_98 ) ;
}
static int F_74 ( struct V_280 * V_63 , unsigned int type ,
unsigned int V_281 , int V_282 )
{
struct V_1 * V_2 = F_75 ( V_63 ) ;
struct V_20 * V_21 = F_10 ( V_2 ) ;
F_31 ( V_2 -> V_63 , L_41 , V_281 , V_282 ) ;
switch ( V_281 ) {
case V_283 :
if ( V_282 )
V_282 = 1000 ;
case V_284 :
break;
default:
return - 1 ;
}
V_21 -> V_274 = V_282 ;
F_76 ( & V_21 -> V_272 ) ;
return 0 ;
}
static T_3 F_77 ( struct V_285 * V_63 ,
struct V_286 * V_287 ,
const char * V_288 , T_4 V_31 )
{
struct V_20 * V_21 = F_78 ( V_63 ) ;
long int time ;
int V_7 ;
V_7 = F_79 ( V_288 , 10 , & time ) ;
if ( V_7 != 0 )
return V_7 ;
F_80 ( V_21 -> V_289 , V_290 , V_284 , time ) ;
return V_31 ;
}
static void F_81 ( struct V_1 * V_2 )
{
struct V_20 * V_21 = F_10 ( V_2 ) ;
int V_7 ;
V_21 -> V_289 = F_82 () ;
if ( ! V_21 -> V_289 ) {
F_22 ( V_2 -> V_63 , L_42 ) ;
return;
}
F_83 ( & V_21 -> V_272 , F_71 ) ;
V_21 -> V_274 = 0 ;
V_21 -> V_289 -> V_291 = L_43 ;
V_21 -> V_289 -> V_292 = F_67 ( V_2 -> V_63 ) ;
V_21 -> V_289 -> V_293 . V_294 = V_295 ;
V_21 -> V_289 -> V_296 [ 0 ] = F_84 ( V_290 ) ;
V_21 -> V_289 -> V_297 [ 0 ] = F_84 ( V_283 ) | F_84 ( V_284 ) ;
V_21 -> V_289 -> V_57 = F_74 ;
V_21 -> V_289 -> V_63 . V_298 = V_2 -> V_63 ;
F_85 ( V_21 -> V_289 , V_2 ) ;
V_7 = F_86 ( V_21 -> V_289 ) ;
if ( V_7 != 0 ) {
F_87 ( V_21 -> V_289 ) ;
V_21 -> V_289 = NULL ;
F_22 ( V_2 -> V_63 , L_44 ) ;
}
V_7 = F_88 ( V_2 -> V_63 , & V_299 ) ;
if ( V_7 != 0 ) {
F_22 ( V_2 -> V_63 , L_45 ,
V_7 ) ;
}
}
static void F_89 ( struct V_1 * V_2 )
{
struct V_20 * V_21 = F_10 ( V_2 ) ;
F_90 ( V_2 -> V_63 , & V_299 ) ;
F_91 ( V_21 -> V_289 ) ;
F_92 ( & V_21 -> V_272 ) ;
V_21 -> V_289 = NULL ;
F_8 ( V_2 , V_278 , V_276 , 0 ) ;
}
static void F_81 ( struct V_1 * V_2 )
{
}
static void F_89 ( struct V_1 * V_2 )
{
}
static void F_93 ( struct V_1 * V_2 , int V_300 )
{
int V_252 = 0 ;
int V_10 = 0 ;
switch ( V_300 ) {
case 2 :
V_252 = V_301 ;
V_10 = 1 << V_302 ;
break;
case 3 :
V_252 = V_303 ;
V_10 = 1 << V_304 ;
break;
default:
break;
}
if ( V_252 )
F_8 ( V_2 , V_305 ,
V_252 , V_10 ) ;
}
static inline struct V_20 * F_94 ( struct V_306 * V_307 )
{
return F_60 ( V_307 , struct V_20 , V_306 ) ;
}
static int F_95 ( struct V_306 * V_307 , unsigned V_308 )
{
struct V_20 * V_21 = F_94 ( V_307 ) ;
struct V_1 * V_2 = V_21 -> V_2 ;
switch ( V_308 + 1 ) {
case 2 :
case 3 :
case 5 :
case 6 :
break;
default:
return - V_64 ;
}
F_93 ( V_2 , V_308 + 1 ) ;
return 0 ;
}
static void F_96 ( struct V_306 * V_307 , unsigned V_308 , int V_32 )
{
struct V_20 * V_21 = F_94 ( V_307 ) ;
struct V_1 * V_2 = V_21 -> V_2 ;
F_8 ( V_2 , V_309 + V_308 ,
V_310 , ! ! V_32 << V_311 ) ;
}
static int F_97 ( struct V_306 * V_307 ,
unsigned V_308 , int V_32 )
{
struct V_20 * V_21 = F_94 ( V_307 ) ;
struct V_1 * V_2 = V_21 -> V_2 ;
int V_10 ;
V_10 = ( 1 << V_312 ) | ( V_32 << V_311 ) ;
return F_8 ( V_2 , V_309 + V_308 ,
V_313 | V_310 , V_10 ) ;
}
static void F_98 ( struct V_1 * V_2 )
{
struct V_20 * V_21 = F_10 ( V_2 ) ;
struct V_95 * V_96 = F_35 ( V_2 -> V_63 ) ;
int V_7 ;
V_21 -> V_306 = V_314 ;
V_21 -> V_306 . V_315 = V_316 ;
V_21 -> V_306 . V_63 = V_2 -> V_63 ;
if ( V_96 && V_96 -> V_317 )
V_21 -> V_306 . V_318 = V_96 -> V_317 ;
else
V_21 -> V_306 . V_318 = - 1 ;
V_7 = F_99 ( & V_21 -> V_306 ) ;
if ( V_7 != 0 )
F_22 ( V_2 -> V_63 , L_46 , V_7 ) ;
}
static void F_100 ( struct V_1 * V_2 )
{
struct V_20 * V_21 = F_10 ( V_2 ) ;
int V_7 ;
V_7 = F_101 ( & V_21 -> V_306 ) ;
if ( V_7 != 0 )
F_22 ( V_2 -> V_63 , L_47 , V_7 ) ;
}
static void F_98 ( struct V_1 * V_2 )
{
}
static void F_100 ( struct V_1 * V_2 )
{
}
static int F_102 ( struct V_1 * V_2 )
{
int V_7 ;
struct V_20 * V_21 = F_10 ( V_2 ) ;
struct V_95 * V_96 = F_35 ( V_2 -> V_63 ) ;
T_1 * V_45 = V_2 -> V_45 ;
int V_109 , V_319 , V_241 ;
bool V_320 , V_321 ;
V_21 -> V_2 = V_2 ;
F_103 ( & V_21 -> V_239 , F_59 ) ;
F_104 ( & V_21 -> V_66 ) ;
V_2 -> V_110 = 1 ;
V_2 -> V_98 . V_322 = 1 ;
V_7 = F_105 ( V_2 , 16 , 16 , V_323 ) ;
if ( V_7 != 0 ) {
F_22 ( V_2 -> V_63 , L_48 , V_7 ) ;
goto V_324;
}
for ( V_109 = 0 ; V_109 < F_37 ( V_21 -> V_143 ) ; V_109 ++ )
V_21 -> V_143 [ V_109 ] . V_325 = V_326 [ V_109 ] ;
V_7 = F_106 ( V_2 -> V_63 , F_37 ( V_21 -> V_143 ) ,
V_21 -> V_143 ) ;
if ( V_7 != 0 ) {
F_22 ( V_2 -> V_63 , L_49 , V_7 ) ;
goto V_324;
}
V_21 -> V_327 [ 0 ] . V_328 = V_329 ;
V_21 -> V_327 [ 1 ] . V_328 = V_330 ;
V_21 -> V_327 [ 2 ] . V_328 = V_331 ;
V_21 -> V_327 [ 3 ] . V_328 = V_332 ;
V_21 -> V_327 [ 4 ] . V_328 = V_333 ;
V_21 -> V_327 [ 5 ] . V_328 = V_334 ;
V_21 -> V_327 [ 6 ] . V_328 = V_335 ;
V_21 -> V_327 [ 7 ] . V_328 = V_336 ;
for ( V_109 = 0 ; V_109 < F_37 ( V_21 -> V_143 ) ; V_109 ++ ) {
V_7 = F_107 ( V_21 -> V_143 [ V_109 ] . V_337 ,
& V_21 -> V_327 [ V_109 ] ) ;
if ( V_7 != 0 ) {
F_22 ( V_2 -> V_63 ,
L_50 ,
V_7 ) ;
}
}
V_7 = F_45 ( F_37 ( V_21 -> V_143 ) ,
V_21 -> V_143 ) ;
if ( V_7 != 0 ) {
F_22 ( V_2 -> V_63 , L_18 , V_7 ) ;
goto V_338;
}
V_7 = F_7 ( V_2 , V_8 ) ;
if ( V_7 < 0 ) {
F_22 ( V_2 -> V_63 , L_51 ) ;
goto V_339;
}
if ( V_7 != V_114 [ V_8 ] ) {
F_22 ( V_2 -> V_63 , L_52 ,
V_7 , V_114 [ V_8 ] ) ;
V_7 = - V_64 ;
goto V_339;
}
V_7 = F_7 ( V_2 , V_340 ) ;
if ( V_7 < 0 ) {
F_22 ( V_2 -> V_63 , L_53 ,
V_7 ) ;
goto V_339;
}
F_108 ( V_2 -> V_63 , L_54 ,
( V_7 & V_341 ) >> V_342 ,
( ( V_7 & V_343 ) >> V_344 )
+ 'A' ) ;
V_7 = F_3 ( V_2 ) ;
if ( V_7 < 0 ) {
F_22 ( V_2 -> V_63 , L_55 ) ;
goto V_339;
}
F_8 ( V_2 , V_61 , V_345 , 0 ) ;
F_8 ( V_2 , V_61 ,
V_346 , V_346 ) ;
F_8 ( V_2 , V_347 ,
V_348 | V_349 | V_350 ,
0 ) ;
F_46 ( F_37 ( V_21 -> V_143 ) , V_21 -> V_143 ) ;
if ( V_96 ) {
for ( V_109 = 0 ; V_109 < F_37 ( V_96 -> V_351 ) ; V_109 ++ )
if ( V_96 -> V_351 [ V_109 ] ) {
F_93 ( V_2 , V_109 + 1 ) ;
F_4 ( V_2 , 0x200 + V_109 ,
V_96 -> V_351 [ V_109 ] & 0xffff ) ;
}
if ( V_96 -> V_100 )
V_45 [ V_352 ]
|= V_353 ;
if ( V_96 -> V_354 )
F_8 ( V_2 , V_242 ,
V_271 |
V_355 |
V_356 |
V_357 ,
V_96 -> V_354 ) ;
}
F_8 ( V_2 , V_358 ,
V_359 , V_359 ) ;
F_8 ( V_2 , V_340 ,
V_359 , V_359 ) ;
F_8 ( V_2 , V_12 ,
V_17 , V_17 ) ;
F_8 ( V_2 , V_14 ,
V_17 , V_17 ) ;
F_8 ( V_2 , V_360 ,
V_361 , V_361 ) ;
F_8 ( V_2 , V_362 ,
V_361 , V_361 ) ;
F_8 ( V_2 , V_52 ,
V_363 , V_363 ) ;
F_8 ( V_2 , V_54 ,
V_363 , V_363 ) ;
F_8 ( V_2 , V_48 ,
V_364 , V_364 ) ;
F_8 ( V_2 , V_50 ,
V_364 , V_364 ) ;
F_8 ( V_2 , V_365 , V_366 , 0 ) ;
F_34 ( V_2 ) ;
V_320 = false ;
V_321 = false ;
for ( V_109 = 0 ; V_109 < V_316 ; V_109 ++ ) {
switch ( F_7 ( V_2 , V_309 + V_109 )
& V_313 ) {
case V_367 :
V_320 = true ;
break;
case V_368 :
V_321 = true ;
break;
default:
break;
}
}
if ( ! V_320 || ! V_321 ) {
F_31 ( V_2 -> V_63 , L_56 ) ;
F_109 ( & V_2 -> V_98 , L_57 ) ;
}
if ( V_320 != V_321 )
F_43 ( V_2 -> V_63 , L_58 ) ;
F_81 ( V_2 ) ;
F_98 ( V_2 ) ;
if ( V_21 -> V_69 ) {
if ( V_96 && V_96 -> V_369 ) {
V_319 = V_370 ;
V_241 = V_371 ;
} else {
V_319 = V_372 ;
V_241 = 0 ;
}
F_8 ( V_2 , V_373 ,
V_371 , V_241 ) ;
V_7 = F_110 ( V_21 -> V_69 , NULL , F_62 ,
V_319 | V_374 ,
L_59 , V_2 ) ;
if ( V_7 != 0 ) {
F_22 ( V_2 -> V_63 , L_60 ,
V_21 -> V_69 , V_7 ) ;
V_21 -> V_69 = 0 ;
} else {
F_8 ( V_2 ,
V_254 ,
V_257 |
V_259 |
V_258 , 0 ) ;
}
}
return 0 ;
V_339:
F_46 ( F_37 ( V_21 -> V_143 ) , V_21 -> V_143 ) ;
V_338:
F_111 ( F_37 ( V_21 -> V_143 ) , V_21 -> V_143 ) ;
V_324:
return V_7 ;
}
static int F_112 ( struct V_1 * V_2 )
{
struct V_20 * V_21 = F_10 ( V_2 ) ;
int V_109 ;
if ( V_21 -> V_69 )
F_113 ( V_21 -> V_69 , V_2 ) ;
F_114 ( & V_21 -> V_239 ) ;
F_100 ( V_2 ) ;
F_89 ( V_2 ) ;
for ( V_109 = 0 ; V_109 < F_37 ( V_21 -> V_143 ) ; V_109 ++ )
F_115 ( V_21 -> V_143 [ V_109 ] . V_337 ,
& V_21 -> V_327 [ V_109 ] ) ;
F_111 ( F_37 ( V_21 -> V_143 ) , V_21 -> V_143 ) ;
return 0 ;
}
static T_5 int F_116 ( struct V_375 * V_376 ,
const struct V_377 * V_293 )
{
struct V_20 * V_21 ;
int V_7 ;
V_21 = F_117 ( sizeof( struct V_20 ) , V_378 ) ;
if ( V_21 == NULL )
return - V_379 ;
F_118 ( V_376 , V_21 ) ;
V_21 -> V_69 = V_376 -> V_69 ;
V_7 = F_119 ( & V_376 -> V_63 ,
& V_380 , & V_381 , 1 ) ;
if ( V_7 < 0 )
F_120 ( V_21 ) ;
return V_7 ;
}
static T_6 int F_121 ( struct V_375 * V_382 )
{
F_122 ( & V_382 -> V_63 ) ;
F_120 ( F_123 ( V_382 ) ) ;
return 0 ;
}
static int T_7 F_124 ( void )
{
int V_7 ;
#if F_125 ( V_383 ) || F_125 ( V_384 )
V_7 = F_126 ( & V_385 ) ;
if ( V_7 != 0 ) {
F_127 ( V_386 L_61 ,
V_7 ) ;
}
#endif
return 0 ;
}
static void T_8 F_128 ( void )
{
#if F_125 ( V_383 ) || F_125 ( V_384 )
F_129 ( & V_385 ) ;
#endif
}
