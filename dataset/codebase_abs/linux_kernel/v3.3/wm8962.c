static bool F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
if ( V_4 [ V_3 ] . V_5 )
return 1 ;
else
return 0 ;
}
static bool F_2 ( struct V_1 * V_2 , unsigned int V_3 )
{
if ( V_4 [ V_3 ] . V_6 )
return 1 ;
else
return 0 ;
}
static int F_3 ( struct V_7 * V_8 )
{
int V_9 ;
V_9 = F_4 ( V_8 -> V_10 , V_11 , 0x6243 ) ;
if ( V_9 != 0 )
return V_9 ;
return F_4 ( V_8 -> V_10 , V_12 , 0 ) ;
}
static int F_5 ( struct V_13 * V_14 )
{
return 0 ;
}
static int F_6 ( struct V_13 * V_14 , T_1 V_15 )
{
T_1 V_16 = F_7 ( V_14 , V_17 ) ;
T_1 V_18 = F_7 ( V_14 , V_19 ) ;
T_1 V_20 = F_7 ( V_14 , V_21 ) ;
F_8 ( V_14 , V_17 , 0 ) ;
F_8 ( V_14 , V_19 , V_22 ) ;
F_9 ( V_14 , V_21 ,
V_23 , V_23 ) ;
F_8 ( V_14 , V_24 , V_15 ) ;
F_8 ( V_14 , V_17 , V_16 ) ;
F_8 ( V_14 , V_19 , V_18 ) ;
F_9 ( V_14 , V_21 ,
V_23 , V_20 ) ;
return 0 ;
}
static int F_10 ( struct V_13 * V_14 )
{
struct V_7 * V_8 = F_11 ( V_14 ) ;
F_5 ( V_14 ) ;
F_8 ( V_14 , V_25 , V_26 ) ;
F_6 ( V_14 , V_8 -> V_27 ) ;
return 0 ;
}
static int F_12 ( struct V_13 * V_14 )
{
F_6 ( V_14 , 0 ) ;
F_8 ( V_14 , V_25 , V_28 ) ;
return 0 ;
}
static int F_13 ( struct V_29 * V_30 ,
struct V_31 * V_32 )
{
V_32 -> type = V_33 ;
V_32 -> V_34 = 1 ;
V_32 -> V_35 . integer . V_36 = 0 ;
V_32 -> V_35 . integer . V_37 = 1 ;
return 0 ;
}
static int F_14 ( struct V_29 * V_30 ,
struct V_38 * V_39 )
{
int V_40 = V_30 -> V_41 ;
struct V_13 * V_14 = F_15 ( V_30 ) ;
struct V_7 * V_8 = F_11 ( V_14 ) ;
V_39 -> V_35 . integer . V_35 [ 0 ] = ! ! ( V_8 -> V_27 & 1 << V_40 ) ;
return 0 ;
}
static int F_16 ( struct V_29 * V_30 ,
struct V_38 * V_39 )
{
int V_40 = V_30 -> V_41 ;
struct V_13 * V_14 = F_15 ( V_30 ) ;
struct V_7 * V_8 = F_11 ( V_14 ) ;
int V_42 = V_8 -> V_27 ;
int V_9 = 0 ;
int V_43 = F_7 ( V_14 , V_44 ) &
V_45 ;
F_17 ( & V_14 -> V_46 ) ;
if ( V_39 -> V_35 . integer . V_35 [ 0 ] )
V_8 -> V_27 |= 1 << V_40 ;
else
V_8 -> V_27 &= ~ ( 1 << V_40 ) ;
if ( V_8 -> V_27 == V_42 )
goto V_47;
V_9 = 1 ;
if ( V_43 ) {
if ( V_8 -> V_27 )
F_6 ( V_14 , V_8 -> V_27 ) ;
else
F_12 ( V_14 ) ;
}
V_47:
F_18 ( & V_14 -> V_46 ) ;
return V_9 ;
}
static int F_19 ( struct V_29 * V_30 ,
struct V_38 * V_39 )
{
struct V_13 * V_14 = F_15 ( V_30 ) ;
T_1 * V_48 = V_14 -> V_48 ;
int V_9 ;
V_9 = F_20 ( V_30 , V_39 ) ;
if ( V_9 == 0 )
return 0 ;
if ( F_7 ( V_14 , V_49 ) & V_50 )
return F_8 ( V_14 , V_51 ,
V_48 [ V_51 ] ) ;
if ( F_7 ( V_14 , V_49 ) & V_52 )
return F_8 ( V_14 , V_53 ,
V_48 [ V_53 ] ) ;
return 0 ;
}
static int F_21 ( struct V_29 * V_30 ,
struct V_38 * V_39 )
{
struct V_13 * V_14 = F_15 ( V_30 ) ;
int V_9 ;
V_9 = F_20 ( V_30 , V_39 ) ;
if ( V_9 == 0 )
return 0 ;
V_9 = F_7 ( V_14 , V_49 ) ;
if ( V_9 & V_54 ) {
F_8 ( V_14 , V_55 ,
F_7 ( V_14 , V_55 ) ) ;
return 1 ;
}
if ( V_9 & V_56 )
F_8 ( V_14 , V_57 ,
F_7 ( V_14 , V_57 ) ) ;
return 1 ;
}
static int F_22 ( struct V_58 * V_59 ,
struct V_29 * V_30 , int V_60 )
{
struct V_13 * V_14 = V_59 -> V_14 ;
struct V_7 * V_8 = F_11 ( V_14 ) ;
unsigned long V_61 ;
int V_62 ;
int V_63 ;
if ( V_14 -> V_64 . V_65 == V_66 )
return 0 ;
V_62 = F_7 ( V_14 , V_67 ) & V_68 ;
switch ( V_62 ) {
case 0 :
V_63 = 0 ;
break;
case 0x200 :
V_63 = 1 ;
break;
default:
F_23 ( V_14 -> V_2 , L_1 , V_62 ) ;
return - V_69 ;
}
switch ( V_60 ) {
case V_70 :
if ( V_63 ) {
F_24 ( & V_8 -> V_71 ) ;
F_9 ( V_14 , V_72 ,
V_73 , V_73 ) ;
V_61 = F_25 ( 5 ) ;
V_61 = F_26 ( & V_8 -> V_71 ,
V_61 ) ;
if ( V_8 -> V_74 && V_61 == 0 )
F_23 ( V_14 -> V_2 ,
L_2 ) ;
}
break;
case V_75 :
if ( V_63 )
F_9 ( V_14 , V_72 ,
V_73 , 0 ) ;
break;
default:
F_27 () ;
return - V_69 ;
}
return 0 ;
}
static int F_28 ( struct V_58 * V_59 ,
struct V_29 * V_30 , int V_60 )
{
switch ( V_60 ) {
case V_76 :
F_29 ( 5 ) ;
break;
default:
F_27 () ;
return - V_69 ;
}
return 0 ;
}
static int F_30 ( struct V_58 * V_59 ,
struct V_29 * V_30 , int V_60 )
{
struct V_13 * V_14 = V_59 -> V_14 ;
int V_61 ;
int V_3 ;
int V_77 = ( V_78 |
V_79 ) ;
switch ( V_60 ) {
case V_76 :
F_9 ( V_14 , V_80 ,
V_81 | V_82 ,
V_81 | V_82 ) ;
F_31 ( 20 ) ;
F_9 ( V_14 , V_80 ,
V_83 | V_84 ,
V_83 | V_84 ) ;
F_9 ( V_14 , V_85 ,
V_86 | V_87 |
V_88 |
V_89 ,
V_86 | V_87 |
V_88 |
V_89 ) ;
V_61 = 0 ;
do {
F_29 ( 1 ) ;
V_3 = F_7 ( V_14 , V_90 ) ;
if ( V_3 < 0 ) {
F_23 ( V_14 -> V_2 ,
L_3 ,
V_3 ) ;
continue;
}
F_32 ( V_14 -> V_2 , L_4 , V_3 ) ;
} while ( ++ V_61 < 200 && ( V_3 & V_77 ) != V_77 );
if ( ( V_3 & V_77 ) != V_77 )
F_23 ( V_14 -> V_2 , L_5 ) ;
else
F_32 ( V_14 -> V_2 , L_6 ,
V_61 ) ;
F_9 ( V_14 , V_80 ,
V_91 |
V_92 ,
V_91 |
V_92 ) ;
F_31 ( 20 ) ;
F_9 ( V_14 , V_80 ,
V_93 |
V_94 ,
V_93 |
V_94 ) ;
break;
case V_95 :
F_9 ( V_14 , V_80 ,
V_93 |
V_94 , 0 ) ;
F_31 ( 20 ) ;
F_9 ( V_14 , V_85 ,
V_86 | V_87 |
V_88 |
V_89 ,
0 ) ;
F_9 ( V_14 , V_80 ,
V_81 | V_82 |
V_83 | V_84 |
V_91 |
V_92 , 0 ) ;
break;
default:
F_27 () ;
return - V_69 ;
}
return 0 ;
}
static int F_33 ( struct V_58 * V_59 ,
struct V_29 * V_30 , int V_60 )
{
struct V_13 * V_14 = V_59 -> V_14 ;
int V_3 ;
switch ( V_59 -> V_40 ) {
case V_96 :
V_3 = V_53 ;
break;
case V_97 :
V_3 = V_51 ;
break;
case V_98 :
V_3 = V_57 ;
break;
case V_99 :
V_3 = V_55 ;
break;
default:
F_27 () ;
return - V_69 ;
}
switch ( V_60 ) {
case V_76 :
return F_8 ( V_14 , V_3 , F_7 ( V_14 , V_3 ) ) ;
default:
F_27 () ;
return - V_69 ;
}
}
static int F_34 ( struct V_58 * V_59 ,
struct V_29 * V_30 , int V_60 )
{
struct V_13 * V_14 = V_59 -> V_14 ;
struct V_7 * V_8 = F_11 ( V_14 ) ;
switch ( V_60 ) {
case V_76 :
if ( V_8 -> V_27 )
F_10 ( V_14 ) ;
break;
case V_95 :
if ( V_8 -> V_27 )
F_12 ( V_14 ) ;
break;
default:
F_27 () ;
return - V_69 ;
}
return 0 ;
}
static int F_35 ( struct V_13 * V_14 )
{
struct V_100 * V_101 = F_36 ( V_14 -> V_2 ) ;
struct V_102 * V_64 = & V_14 -> V_64 ;
F_37 ( V_14 , V_103 ,
F_38 ( V_103 ) ) ;
if ( V_101 && V_101 -> V_104 )
F_37 ( V_14 , V_105 ,
F_38 ( V_105 ) ) ;
else
F_37 ( V_14 , V_106 ,
F_38 ( V_106 ) ) ;
F_39 ( V_64 , V_107 ,
F_38 ( V_107 ) ) ;
if ( V_101 && V_101 -> V_104 )
F_39 ( V_64 , V_108 ,
F_38 ( V_108 ) ) ;
else
F_39 ( V_64 , V_109 ,
F_38 ( V_109 ) ) ;
F_40 ( V_64 , V_110 ,
F_38 ( V_110 ) ) ;
if ( V_101 && V_101 -> V_104 )
F_40 ( V_64 , V_111 ,
F_38 ( V_111 ) ) ;
else
F_40 ( V_64 , V_112 ,
F_38 ( V_112 ) ) ;
F_41 ( V_64 , L_7 ) ;
return 0 ;
}
static void F_42 ( struct V_13 * V_14 )
{
struct V_7 * V_8 = F_11 ( V_14 ) ;
int V_113 , V_114 ;
int V_115 = 0 ;
int V_116 = 0 ;
int V_117 = 0 ;
if ( ! V_8 -> V_118 ) {
F_32 ( V_14 -> V_2 , L_8 ) ;
return;
}
if ( ! V_8 -> V_119 || ! V_8 -> V_120 ) {
F_32 ( V_14 -> V_2 , L_9 ) ;
return;
}
for ( V_114 = 0 ; V_114 < F_38 ( V_121 ) ; V_114 ++ ) {
if ( V_121 [ V_114 ] == V_8 -> V_118 / V_8 -> V_120 ) {
V_116 |= V_114 << V_122 ;
break;
}
}
if ( V_114 == F_38 ( V_121 ) ) {
F_23 ( V_14 -> V_2 , L_10 ,
V_8 -> V_118 / V_8 -> V_120 ) ;
return;
}
F_9 ( V_14 , V_123 ,
V_124 , V_116 ) ;
V_113 = F_7 ( V_14 , V_125 ) ;
if ( V_113 < 0 ) {
F_23 ( V_14 -> V_2 , L_11 , V_113 ) ;
return;
}
V_113 = ( V_113 & V_126 ) >> V_127 ;
switch ( V_113 ) {
case 0 :
V_113 = V_8 -> V_118 ;
break;
case 1 :
V_113 = V_8 -> V_118 / 2 ;
break;
case 2 :
V_113 = V_8 -> V_118 / 4 ;
break;
default:
F_43 ( V_14 -> V_2 , L_12 ) ;
V_113 = V_8 -> V_128 ;
}
F_32 ( V_14 -> V_2 , L_13 , V_113 , V_8 -> V_119 ) ;
for ( V_114 = 0 ; V_114 < F_38 ( V_129 ) ; V_114 ++ ) {
if ( V_129 [ V_114 ] < 0 )
continue;
if ( V_113 / V_129 [ V_114 ] == V_8 -> V_119 ) {
F_32 ( V_14 -> V_2 , L_14 ,
V_129 [ V_114 ] , V_8 -> V_119 ) ;
V_115 |= V_114 ;
break;
}
}
if ( V_114 == F_38 ( V_129 ) ) {
F_23 ( V_14 -> V_2 , L_15 ,
V_113 / V_8 -> V_119 ) ;
return;
}
V_117 |= V_8 -> V_119 / V_8 -> V_120 ;
F_32 ( V_14 -> V_2 , L_16 ,
V_8 -> V_119 / V_8 -> V_120 , V_8 -> V_120 ) ;
F_9 ( V_14 , V_67 ,
V_130 , V_115 ) ;
F_9 ( V_14 , V_131 ,
V_132 , V_117 ) ;
}
static int F_44 ( struct V_13 * V_14 ,
enum V_133 V_134 )
{
struct V_7 * V_8 = F_11 ( V_14 ) ;
int V_9 ;
if ( V_134 == V_14 -> V_64 . V_65 )
return 0 ;
switch ( V_134 ) {
case V_135 :
break;
case V_136 :
F_9 ( V_14 , V_137 ,
V_138 , 0x80 ) ;
F_42 ( V_14 ) ;
break;
case V_139 :
if ( V_14 -> V_64 . V_65 == V_66 ) {
V_9 = F_45 ( F_38 ( V_8 -> V_140 ) ,
V_8 -> V_140 ) ;
if ( V_9 != 0 ) {
F_23 ( V_14 -> V_2 ,
L_17 ,
V_9 ) ;
return V_9 ;
}
F_46 ( V_8 -> V_10 , false ) ;
F_47 ( V_8 -> V_10 ) ;
F_9 ( V_14 , V_141 ,
V_142 |
V_143 ,
V_142 |
V_143 ) ;
F_9 ( V_14 , V_137 ,
V_138 |
V_144 ,
V_144 | 0x180 ) ;
F_29 ( 5 ) ;
}
F_9 ( V_14 , V_137 ,
V_138 , 0x100 ) ;
break;
case V_66 :
F_9 ( V_14 , V_137 ,
V_138 | V_144 , 0 ) ;
F_9 ( V_14 , V_141 ,
V_142 |
V_143 , 0 ) ;
F_48 ( F_38 ( V_8 -> V_140 ) ,
V_8 -> V_140 ) ;
break;
}
V_14 -> V_64 . V_65 = V_134 ;
return 0 ;
}
static int F_49 ( struct V_145 * V_146 ,
struct V_147 * V_148 ,
struct V_149 * V_150 )
{
struct V_151 * V_152 = V_146 -> V_153 ;
struct V_13 * V_14 = V_152 -> V_14 ;
struct V_7 * V_8 = F_11 ( V_14 ) ;
int V_114 ;
int V_154 = 0 ;
int V_155 = 0 ;
V_8 -> V_119 = F_50 ( V_148 ) ;
V_8 -> V_120 = F_51 ( V_148 ) ;
for ( V_114 = 0 ; V_114 < F_38 ( V_156 ) ; V_114 ++ ) {
if ( V_156 [ V_114 ] . V_157 == V_8 -> V_120 ) {
V_155 |= V_156 [ V_114 ] . V_3 ;
break;
}
}
if ( V_114 == F_38 ( V_156 ) ) {
F_23 ( V_14 -> V_2 , L_18 , V_8 -> V_120 ) ;
return - V_69 ;
}
if ( V_8 -> V_120 % 8000 == 0 )
V_155 |= V_158 ;
switch ( F_52 ( V_148 ) ) {
case V_159 :
break;
case V_160 :
V_154 |= 0x4 ;
break;
case V_161 :
V_154 |= 0x8 ;
break;
case V_162 :
V_154 |= 0xc ;
break;
default:
return - V_69 ;
}
F_9 ( V_14 , V_163 ,
V_164 , V_154 ) ;
F_9 ( V_14 , V_165 ,
V_158 |
V_166 , V_155 ) ;
F_42 ( V_14 ) ;
return 0 ;
}
static int F_53 ( struct V_149 * V_150 , int V_167 ,
unsigned int V_168 , int V_169 )
{
struct V_13 * V_14 = V_150 -> V_14 ;
struct V_7 * V_8 = F_11 ( V_14 ) ;
int V_62 ;
switch ( V_167 ) {
case V_170 :
V_8 -> V_128 = V_170 ;
V_62 = 0 ;
break;
case V_171 :
V_8 -> V_128 = V_171 ;
V_62 = 1 << V_172 ;
break;
default:
return - V_69 ;
}
F_9 ( V_14 , V_67 , V_68 ,
V_62 ) ;
V_8 -> V_118 = V_168 ;
return 0 ;
}
static int F_54 ( struct V_149 * V_150 , unsigned int V_173 )
{
struct V_13 * V_14 = V_150 -> V_14 ;
int V_154 = 0 ;
switch ( V_173 & V_174 ) {
case V_175 :
V_154 |= V_176 | 3 ;
case V_177 :
V_154 |= 3 ;
switch ( V_173 & V_178 ) {
case V_179 :
case V_180 :
break;
default:
return - V_69 ;
}
break;
case V_181 :
break;
case V_182 :
V_154 |= 1 ;
break;
case V_183 :
V_154 |= 2 ;
break;
default:
return - V_69 ;
}
switch ( V_173 & V_178 ) {
case V_179 :
break;
case V_180 :
V_154 |= V_184 ;
break;
case V_185 :
V_154 |= V_176 ;
break;
case V_186 :
V_154 |= V_184 | V_176 ;
break;
default:
return - V_69 ;
}
switch ( V_173 & V_187 ) {
case V_188 :
V_154 |= V_189 ;
break;
case V_190 :
break;
default:
return - V_69 ;
}
F_9 ( V_14 , V_163 ,
V_191 | V_184 | V_189 |
V_176 , V_154 ) ;
return 0 ;
}
static int F_55 ( struct V_192 * V_193 , unsigned int V_194 ,
unsigned int V_195 )
{
unsigned int V_196 ;
unsigned int div ;
unsigned int V_197 , V_198 ;
int V_114 ;
div = 1 ;
V_193 -> V_199 = 0 ;
while ( ( V_194 / div ) > 13500000 ) {
div *= 2 ;
V_193 -> V_199 ++ ;
if ( div > 4 ) {
F_56 ( L_19 ,
V_194 ) ;
return - V_69 ;
}
}
F_57 ( L_20 , V_194 , V_195 ) ;
V_194 /= div ;
div = 2 ;
while ( V_195 * div < 90000000 ) {
div ++ ;
if ( div > 64 ) {
F_56 ( L_21 ,
V_195 ) ;
return - V_69 ;
}
}
V_196 = V_195 * div ;
V_193 -> V_200 = div - 1 ;
F_57 ( L_22 , V_196 ) ;
for ( V_114 = 0 ; V_114 < F_38 ( V_201 ) ; V_114 ++ ) {
if ( V_201 [ V_114 ] . V_36 <= V_194 && V_194 <= V_201 [ V_114 ] . V_37 ) {
V_193 -> V_202 = V_201 [ V_114 ] . V_202 ;
V_197 = V_201 [ V_114 ] . V_203 ;
break;
}
}
if ( V_114 == F_38 ( V_201 ) ) {
F_56 ( L_23 , V_194 ) ;
return - V_69 ;
}
V_193 -> V_204 = V_196 / ( V_197 * V_194 ) ;
if ( V_196 % V_194 == 0 ) {
V_193 -> V_205 = 0 ;
V_193 -> V_206 = 0 ;
} else {
V_198 = F_58 ( V_196 , V_197 * V_194 ) ;
V_193 -> V_205 = ( V_196 - ( V_193 -> V_204 * V_197 * V_194 ) )
/ V_198 ;
V_193 -> V_206 = ( V_197 * V_194 ) / V_198 ;
}
F_57 ( L_24 ,
V_193 -> V_204 , V_193 -> V_205 , V_193 -> V_206 ) ;
F_57 ( L_25 ,
V_193 -> V_202 , V_193 -> V_200 ,
V_193 -> V_199 ) ;
return 0 ;
}
static int F_59 ( struct V_13 * V_14 , int V_207 , int V_208 ,
unsigned int V_194 , unsigned int V_195 )
{
struct V_7 * V_8 = F_11 ( V_14 ) ;
struct V_192 V_193 ;
unsigned long V_61 ;
int V_9 ;
int V_209 = F_7 ( V_14 , V_72 ) & V_73 ;
int V_128 = F_7 ( V_14 , V_67 ) & V_210 ;
if ( V_208 == V_8 -> V_211 && V_194 == V_8 -> V_212 &&
V_195 == V_8 -> V_213 )
return 0 ;
if ( V_195 == 0 ) {
F_32 ( V_14 -> V_2 , L_26 ) ;
V_8 -> V_212 = 0 ;
V_8 -> V_213 = 0 ;
F_9 ( V_14 , V_72 ,
V_73 , 0 ) ;
return 0 ;
}
V_9 = F_55 ( & V_193 , V_194 , V_195 ) ;
if ( V_9 != 0 )
return V_9 ;
switch ( V_207 ) {
case V_214 :
case V_215 :
case V_216 :
V_209 |= ( V_207 - 1 ) << V_217 ;
break;
case V_218 :
F_9 ( V_14 , V_72 ,
V_219 , V_219 ) ;
F_9 ( V_14 , V_220 ,
V_221 , V_221 ) ;
break;
default:
F_23 ( V_14 -> V_2 , L_27 , V_9 ) ;
return - V_69 ;
}
if ( V_193 . V_205 || V_193 . V_206 )
V_209 |= V_222 ;
F_9 ( V_14 , V_72 , V_73 , 0 ) ;
F_9 ( V_14 , V_223 ,
V_224 |
V_225 ,
( V_193 . V_200 << V_226 ) |
( V_193 . V_199 ) ) ;
F_9 ( V_14 , V_227 ,
V_228 , V_193 . V_202 ) ;
F_8 ( V_14 , V_229 , V_193 . V_205 ) ;
F_8 ( V_14 , V_230 , V_193 . V_206 ) ;
F_8 ( V_14 , V_231 , V_193 . V_204 ) ;
F_24 ( & V_8 -> V_71 ) ;
if ( V_128 )
V_209 |= V_73 ;
F_9 ( V_14 , V_72 ,
V_222 | V_232 |
V_73 , V_209 ) ;
F_32 ( V_14 -> V_2 , L_28 , V_194 , V_195 ) ;
V_9 = 0 ;
if ( V_209 & V_73 ) {
if ( V_8 -> V_74 )
V_61 = F_25 ( 5 ) ;
else
V_61 = F_25 ( 1 ) ;
V_61 = F_26 ( & V_8 -> V_71 ,
V_61 ) ;
if ( V_61 == 0 && V_8 -> V_74 ) {
F_23 ( V_14 -> V_2 , L_29 ) ;
V_9 = - V_233 ;
}
}
V_8 -> V_212 = V_194 ;
V_8 -> V_213 = V_195 ;
V_8 -> V_211 = V_208 ;
return V_9 ;
}
static int F_60 ( struct V_149 * V_150 , int V_234 )
{
struct V_13 * V_14 = V_150 -> V_14 ;
int V_15 ;
if ( V_234 )
V_15 = V_23 ;
else
V_15 = 0 ;
return F_9 ( V_14 , V_21 ,
V_23 , V_15 ) ;
}
static void F_61 ( struct V_235 * V_236 )
{
struct V_7 * V_8 = F_62 ( V_236 ,
struct V_7 ,
V_237 . V_236 ) ;
struct V_13 * V_14 = V_8 -> V_14 ;
int V_238 = 0 ;
int V_239 = 0 ;
int V_3 ;
V_3 = F_7 ( V_14 , V_240 ) ;
if ( V_3 & V_241 ) {
V_238 |= V_242 ;
V_239 |= V_243 ;
}
if ( V_3 & V_244 ) {
V_238 |= V_245 ;
V_239 |= V_246 ;
}
F_63 ( V_8 -> V_247 , V_238 ,
V_242 | V_245 ) ;
F_9 ( V_14 , V_248 ,
V_246 |
V_243 , V_239 ) ;
}
static T_2 F_64 ( int V_74 , void * V_249 )
{
struct V_13 * V_14 = V_249 ;
struct V_7 * V_8 = F_11 ( V_14 ) ;
int V_250 ;
int V_251 ;
int V_3 ;
V_250 = F_7 ( V_14 , V_252 ) ;
V_251 = F_7 ( V_14 , V_253 ) ;
V_251 &= ~ V_250 ;
if ( ! V_251 )
return V_254 ;
F_8 ( V_14 , V_253 , V_251 ) ;
if ( V_251 & V_255 ) {
F_32 ( V_14 -> V_2 , L_30 ) ;
F_65 ( & V_8 -> V_71 ) ;
}
if ( V_251 & V_256 )
F_23 ( V_14 -> V_2 , L_31 ) ;
if ( V_251 & V_257 ) {
F_66 ( V_14 -> V_2 , L_32 ) ;
V_3 = F_7 ( V_14 , V_258 ) ;
if ( V_3 & V_259 )
F_66 ( V_14 -> V_2 , L_33 ) ;
if ( V_3 & V_260 )
F_66 ( V_14 -> V_2 , L_34 ) ;
if ( V_3 & V_261 )
F_66 ( V_14 -> V_2 , L_35 ) ;
if ( V_3 & V_262 )
F_66 ( V_14 -> V_2 , L_36 ) ;
}
if ( V_251 & ( V_263 | V_264 ) ) {
F_32 ( V_14 -> V_2 , L_37 ) ;
#ifndef F_67
F_68 ( F_69 ( V_14 -> V_2 ) ) ;
#endif
F_70 ( V_14 -> V_2 , 300 ) ;
F_71 ( & V_8 -> V_237 ,
F_25 ( 250 ) ) ;
}
return V_265 ;
}
int F_72 ( struct V_13 * V_14 , struct V_266 * V_247 )
{
struct V_7 * V_8 = F_11 ( V_14 ) ;
int V_267 , V_268 ;
V_8 -> V_247 = V_247 ;
if ( V_247 ) {
V_267 = 0 ;
V_268 = V_269 ;
} else {
V_267 = V_264 | V_263 ;
V_268 = 0 ;
}
F_9 ( V_14 , V_252 ,
V_264 | V_263 , V_267 ) ;
F_9 ( V_14 , V_240 ,
V_269 , V_268 ) ;
F_63 ( V_8 -> V_247 , 0 ,
V_242 | V_245 ) ;
if ( V_247 ) {
F_73 ( & V_14 -> V_64 , L_38 ) ;
F_73 ( & V_14 -> V_64 , L_39 ) ;
} else {
F_41 ( & V_14 -> V_64 , L_38 ) ;
F_41 ( & V_14 -> V_64 , L_39 ) ;
}
return 0 ;
}
static void F_74 ( struct V_235 * V_236 )
{
struct V_7 * V_8 =
F_62 ( V_236 , struct V_7 , V_270 ) ;
struct V_13 * V_14 = V_8 -> V_14 ;
struct V_102 * V_64 = & V_14 -> V_64 ;
int V_114 ;
int V_3 = 0 ;
int V_271 = 0 ;
if ( V_8 -> V_272 ) {
for ( V_114 = 0 ; V_114 < F_38 ( V_273 ) ; V_114 ++ ) {
if ( abs ( V_8 -> V_272 - V_273 [ V_114 ] ) <
abs ( V_8 -> V_272 - V_273 [ V_271 ] ) )
V_271 = V_114 ;
}
F_32 ( V_14 -> V_2 , L_40 ,
V_273 [ V_271 ] , V_8 -> V_272 ) ;
V_3 = V_274 | ( V_271 << V_275 ) ;
F_75 ( V_64 , L_7 ) ;
} else {
F_32 ( V_14 -> V_2 , L_41 ) ;
F_41 ( V_64 , L_7 ) ;
}
F_9 ( V_14 , V_276 ,
V_274 | V_277 , V_3 ) ;
F_76 ( V_64 ) ;
}
static int F_77 ( struct V_278 * V_2 , unsigned int type ,
unsigned int V_279 , int V_280 )
{
struct V_13 * V_14 = F_78 ( V_2 ) ;
struct V_7 * V_8 = F_11 ( V_14 ) ;
F_32 ( V_14 -> V_2 , L_42 , V_279 , V_280 ) ;
switch ( V_279 ) {
case V_281 :
if ( V_280 )
V_280 = 1000 ;
case V_282 :
break;
default:
return - 1 ;
}
V_8 -> V_272 = V_280 ;
F_79 ( & V_8 -> V_270 ) ;
return 0 ;
}
static T_3 F_80 ( struct V_1 * V_2 ,
struct V_283 * V_284 ,
const char * V_285 , T_4 V_34 )
{
struct V_7 * V_8 = F_81 ( V_2 ) ;
long int time ;
int V_9 ;
V_9 = F_82 ( V_285 , 10 , & time ) ;
if ( V_9 != 0 )
return V_9 ;
F_83 ( V_8 -> V_286 , V_287 , V_282 , time ) ;
return V_34 ;
}
static void F_84 ( struct V_13 * V_14 )
{
struct V_7 * V_8 = F_11 ( V_14 ) ;
int V_9 ;
V_8 -> V_286 = F_85 () ;
if ( ! V_8 -> V_286 ) {
F_23 ( V_14 -> V_2 , L_43 ) ;
return;
}
F_86 ( & V_8 -> V_270 , F_74 ) ;
V_8 -> V_272 = 0 ;
V_8 -> V_286 -> V_288 = L_44 ;
V_8 -> V_286 -> V_289 = F_69 ( V_14 -> V_2 ) ;
V_8 -> V_286 -> V_290 . V_291 = V_292 ;
V_8 -> V_286 -> V_293 [ 0 ] = F_87 ( V_287 ) ;
V_8 -> V_286 -> V_294 [ 0 ] = F_87 ( V_281 ) | F_87 ( V_282 ) ;
V_8 -> V_286 -> V_60 = F_77 ;
V_8 -> V_286 -> V_2 . V_295 = V_14 -> V_2 ;
F_88 ( V_8 -> V_286 , V_14 ) ;
V_9 = F_89 ( V_8 -> V_286 ) ;
if ( V_9 != 0 ) {
F_90 ( V_8 -> V_286 ) ;
V_8 -> V_286 = NULL ;
F_23 ( V_14 -> V_2 , L_45 ) ;
}
V_9 = F_91 ( V_14 -> V_2 , & V_296 ) ;
if ( V_9 != 0 ) {
F_23 ( V_14 -> V_2 , L_46 ,
V_9 ) ;
}
}
static void F_92 ( struct V_13 * V_14 )
{
struct V_7 * V_8 = F_11 ( V_14 ) ;
F_93 ( V_14 -> V_2 , & V_296 ) ;
F_94 ( V_8 -> V_286 ) ;
F_95 ( & V_8 -> V_270 ) ;
V_8 -> V_286 = NULL ;
F_9 ( V_14 , V_276 , V_274 , 0 ) ;
}
static void F_84 ( struct V_13 * V_14 )
{
}
static void F_92 ( struct V_13 * V_14 )
{
}
static void F_96 ( struct V_13 * V_14 , int V_297 )
{
int V_250 = 0 ;
int V_15 = 0 ;
switch ( V_297 ) {
case 2 :
V_250 = V_298 ;
V_15 = 1 << V_299 ;
break;
case 3 :
V_250 = V_300 ;
V_15 = 1 << V_301 ;
break;
default:
break;
}
if ( V_250 )
F_9 ( V_14 , V_302 ,
V_250 , V_15 ) ;
}
static inline struct V_7 * F_97 ( struct V_303 * V_304 )
{
return F_62 ( V_304 , struct V_7 , V_303 ) ;
}
static int F_98 ( struct V_303 * V_304 , unsigned V_305 )
{
struct V_7 * V_8 = F_97 ( V_304 ) ;
struct V_13 * V_14 = V_8 -> V_14 ;
switch ( V_305 + 1 ) {
case 2 :
case 3 :
case 5 :
case 6 :
break;
default:
return - V_69 ;
}
F_96 ( V_14 , V_305 + 1 ) ;
return 0 ;
}
static void F_99 ( struct V_303 * V_304 , unsigned V_305 , int V_35 )
{
struct V_7 * V_8 = F_97 ( V_304 ) ;
struct V_13 * V_14 = V_8 -> V_14 ;
F_9 ( V_14 , V_306 + V_305 ,
V_307 , ! ! V_35 << V_308 ) ;
}
static int F_100 ( struct V_303 * V_304 ,
unsigned V_305 , int V_35 )
{
struct V_7 * V_8 = F_97 ( V_304 ) ;
struct V_13 * V_14 = V_8 -> V_14 ;
int V_9 , V_15 ;
V_15 = ( 1 << V_309 ) | ( V_35 << V_308 ) ;
V_9 = F_9 ( V_14 , V_306 + V_305 ,
V_310 | V_307 , V_15 ) ;
if ( V_9 < 0 )
return V_9 ;
return 0 ;
}
static void F_101 ( struct V_13 * V_14 )
{
struct V_7 * V_8 = F_11 ( V_14 ) ;
struct V_100 * V_101 = F_36 ( V_14 -> V_2 ) ;
int V_9 ;
V_8 -> V_303 = V_311 ;
V_8 -> V_303 . V_312 = V_313 ;
V_8 -> V_303 . V_2 = V_14 -> V_2 ;
if ( V_101 && V_101 -> V_314 )
V_8 -> V_303 . V_315 = V_101 -> V_314 ;
else
V_8 -> V_303 . V_315 = - 1 ;
V_9 = F_102 ( & V_8 -> V_303 ) ;
if ( V_9 != 0 )
F_23 ( V_14 -> V_2 , L_47 , V_9 ) ;
}
static void F_103 ( struct V_13 * V_14 )
{
struct V_7 * V_8 = F_11 ( V_14 ) ;
int V_9 ;
V_9 = F_104 ( & V_8 -> V_303 ) ;
if ( V_9 != 0 )
F_23 ( V_14 -> V_2 , L_48 , V_9 ) ;
}
static void F_101 ( struct V_13 * V_14 )
{
}
static void F_103 ( struct V_13 * V_14 )
{
}
static int F_105 ( struct V_13 * V_14 )
{
int V_9 ;
struct V_7 * V_8 = F_11 ( V_14 ) ;
struct V_100 * V_101 = F_36 ( V_14 -> V_2 ) ;
T_1 * V_48 = V_14 -> V_48 ;
int V_114 , V_316 , V_239 ;
bool V_317 , V_318 ;
V_8 -> V_14 = V_14 ;
V_14 -> V_319 = V_8 -> V_10 ;
V_9 = F_106 ( V_14 , 16 , 16 , V_320 ) ;
if ( V_9 != 0 ) {
F_23 ( V_14 -> V_2 , L_49 , V_9 ) ;
return V_9 ;
}
V_8 -> V_321 [ 0 ] . V_322 = V_323 ;
V_8 -> V_321 [ 1 ] . V_322 = V_324 ;
V_8 -> V_321 [ 2 ] . V_322 = V_325 ;
V_8 -> V_321 [ 3 ] . V_322 = V_326 ;
V_8 -> V_321 [ 4 ] . V_322 = V_327 ;
V_8 -> V_321 [ 5 ] . V_322 = V_328 ;
V_8 -> V_321 [ 6 ] . V_322 = V_329 ;
V_8 -> V_321 [ 7 ] . V_322 = V_330 ;
for ( V_114 = 0 ; V_114 < F_38 ( V_8 -> V_140 ) ; V_114 ++ ) {
V_9 = F_107 ( V_8 -> V_140 [ V_114 ] . V_331 ,
& V_8 -> V_321 [ V_114 ] ) ;
if ( V_9 != 0 ) {
F_23 ( V_14 -> V_2 ,
L_50 ,
V_9 ) ;
}
}
F_9 ( V_14 , V_67 , V_210 , 0 ) ;
F_9 ( V_14 , V_67 ,
V_332 , V_332 ) ;
F_9 ( V_14 , V_333 ,
V_334 | V_335 | V_336 ,
0 ) ;
if ( V_101 ) {
for ( V_114 = 0 ; V_114 < F_38 ( V_101 -> V_337 ) ; V_114 ++ )
if ( V_101 -> V_337 [ V_114 ] ) {
F_96 ( V_14 , V_114 + 1 ) ;
F_8 ( V_14 , 0x200 + V_114 ,
V_101 -> V_337 [ V_114 ] & 0xffff ) ;
}
if ( V_101 -> V_104 )
V_48 [ V_338 ]
|= V_339 ;
if ( V_101 -> V_340 )
F_9 ( V_14 , V_240 ,
V_269 |
V_341 |
V_342 |
V_343 ,
V_101 -> V_340 ) ;
}
F_9 ( V_14 , V_344 ,
V_345 , V_345 ) ;
F_9 ( V_14 , V_346 ,
V_345 , V_345 ) ;
F_9 ( V_14 , V_17 ,
V_22 , V_22 ) ;
F_9 ( V_14 , V_19 ,
V_22 , V_22 ) ;
F_9 ( V_14 , V_347 ,
V_348 , V_348 ) ;
F_9 ( V_14 , V_349 ,
V_348 , V_348 ) ;
F_9 ( V_14 , V_55 ,
V_350 , V_350 ) ;
F_9 ( V_14 , V_57 ,
V_350 , V_350 ) ;
F_9 ( V_14 , V_51 ,
V_351 , V_351 ) ;
F_9 ( V_14 , V_53 ,
V_351 , V_351 ) ;
F_9 ( V_14 , V_352 , V_353 , 0 ) ;
F_9 ( V_14 , V_354 ,
V_355 | V_356 |
V_357 | V_358 ,
0 ) ;
F_35 ( V_14 ) ;
V_317 = false ;
V_318 = false ;
for ( V_114 = 0 ; V_114 < V_313 ; V_114 ++ ) {
switch ( F_7 ( V_14 , V_306 + V_114 )
& V_310 ) {
case V_359 :
V_317 = true ;
break;
case V_360 :
V_318 = true ;
break;
default:
break;
}
}
if ( ! V_317 || ! V_318 ) {
F_32 ( V_14 -> V_2 , L_51 ) ;
F_108 ( & V_14 -> V_64 , L_52 ) ;
}
if ( V_317 != V_318 )
F_43 ( V_14 -> V_2 , L_53 ) ;
F_84 ( V_14 ) ;
F_101 ( V_14 ) ;
if ( V_8 -> V_74 ) {
if ( V_101 && V_101 -> V_361 ) {
V_316 = V_362 ;
V_239 = V_363 ;
} else {
V_316 = V_364 ;
V_239 = 0 ;
}
F_9 ( V_14 , V_365 ,
V_363 , V_239 ) ;
V_9 = F_109 ( V_8 -> V_74 , NULL , F_64 ,
V_316 | V_366 ,
L_54 , V_14 ) ;
if ( V_9 != 0 ) {
F_23 ( V_14 -> V_2 , L_55 ,
V_8 -> V_74 , V_9 ) ;
V_8 -> V_74 = 0 ;
} else {
F_9 ( V_14 ,
V_252 ,
V_255 |
V_257 |
V_256 , 0 ) ;
}
}
return 0 ;
}
static int F_110 ( struct V_13 * V_14 )
{
struct V_7 * V_8 = F_11 ( V_14 ) ;
int V_114 ;
if ( V_8 -> V_74 )
F_111 ( V_8 -> V_74 , V_14 ) ;
F_112 ( & V_8 -> V_237 ) ;
F_103 ( V_14 ) ;
F_92 ( V_14 ) ;
for ( V_114 = 0 ; V_114 < F_38 ( V_8 -> V_140 ) ; V_114 ++ )
F_113 ( V_8 -> V_140 [ V_114 ] . V_331 ,
& V_8 -> V_321 [ V_114 ] ) ;
return 0 ;
}
static int F_114 ( struct V_13 * V_14 ,
unsigned int V_3 )
{
return true ;
}
static T_5 int F_115 ( struct V_367 * V_368 ,
const struct V_369 * V_290 )
{
struct V_7 * V_8 ;
unsigned int V_3 ;
int V_9 , V_114 ;
V_8 = F_116 ( & V_368 -> V_2 , sizeof( struct V_7 ) ,
V_370 ) ;
if ( V_8 == NULL )
return - V_371 ;
F_117 ( V_368 , V_8 ) ;
F_118 ( & V_8 -> V_237 , F_61 ) ;
F_119 ( & V_8 -> V_71 ) ;
V_8 -> V_74 = V_368 -> V_74 ;
for ( V_114 = 0 ; V_114 < F_38 ( V_8 -> V_140 ) ; V_114 ++ )
V_8 -> V_140 [ V_114 ] . V_372 = V_373 [ V_114 ] ;
V_9 = F_120 ( & V_368 -> V_2 , F_38 ( V_8 -> V_140 ) ,
V_8 -> V_140 ) ;
if ( V_9 != 0 ) {
F_23 ( & V_368 -> V_2 , L_56 , V_9 ) ;
goto V_374;
}
V_9 = F_45 ( F_38 ( V_8 -> V_140 ) ,
V_8 -> V_140 ) ;
if ( V_9 != 0 ) {
F_23 ( & V_368 -> V_2 , L_17 , V_9 ) ;
goto V_375;
}
V_8 -> V_10 = F_121 ( V_368 , & V_376 ) ;
if ( F_122 ( V_8 -> V_10 ) ) {
V_9 = F_123 ( V_8 -> V_10 ) ;
F_23 ( & V_368 -> V_2 , L_57 , V_9 ) ;
goto V_377;
}
F_124 ( V_8 -> V_10 , true ) ;
V_9 = F_125 ( V_8 -> V_10 , V_11 , & V_3 ) ;
if ( V_9 < 0 ) {
F_23 ( & V_368 -> V_2 , L_58 ) ;
goto V_378;
}
if ( V_3 != 0x6243 ) {
F_23 ( & V_368 -> V_2 ,
L_59 , V_9 ) ;
V_9 = - V_69 ;
goto V_378;
}
V_9 = F_125 ( V_8 -> V_10 , V_346 , & V_3 ) ;
if ( V_9 < 0 ) {
F_23 ( & V_368 -> V_2 , L_60 ,
V_9 ) ;
goto V_378;
}
F_126 ( & V_368 -> V_2 , L_61 ,
( V_3 & V_379 ) >> V_380 ,
( ( V_3 & V_381 ) >> V_382 )
+ 'A' ) ;
F_124 ( V_8 -> V_10 , false ) ;
V_9 = F_3 ( V_8 ) ;
if ( V_9 < 0 ) {
F_23 ( & V_368 -> V_2 , L_62 ) ;
goto V_378;
}
F_46 ( V_8 -> V_10 , true ) ;
V_9 = F_127 ( & V_368 -> V_2 ,
& V_383 , & V_384 , 1 ) ;
if ( V_9 < 0 )
goto V_378;
F_48 ( F_38 ( V_8 -> V_140 ) , V_8 -> V_140 ) ;
return 0 ;
V_378:
F_128 ( V_8 -> V_10 ) ;
V_377:
F_48 ( F_38 ( V_8 -> V_140 ) , V_8 -> V_140 ) ;
V_375:
F_129 ( F_38 ( V_8 -> V_140 ) , V_8 -> V_140 ) ;
V_374:
return V_9 ;
}
static T_6 int F_130 ( struct V_367 * V_385 )
{
struct V_7 * V_8 = F_81 ( & V_385 -> V_2 ) ;
F_131 ( & V_385 -> V_2 ) ;
F_128 ( V_8 -> V_10 ) ;
F_129 ( F_38 ( V_8 -> V_140 ) , V_8 -> V_140 ) ;
return 0 ;
}
static int T_7 F_132 ( void )
{
int V_9 ;
#if F_133 ( V_386 ) || F_133 ( V_387 )
V_9 = F_134 ( & V_388 ) ;
if ( V_9 != 0 ) {
F_135 ( V_389 L_63 ,
V_9 ) ;
}
#endif
return 0 ;
}
static void T_8 F_136 ( void )
{
#if F_133 ( V_386 ) || F_133 ( V_387 )
F_137 ( & V_388 ) ;
#endif
}
