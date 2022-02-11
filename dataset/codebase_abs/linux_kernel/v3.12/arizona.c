static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
int V_5 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_8 = F_2 ( V_7 -> V_9 -> V_10 ) ;
struct V_11 * V_12 = F_3 ( V_7 ) ;
bool V_13 = false ;
int V_14 ;
switch ( V_8 -> type ) {
case V_15 :
switch ( V_8 -> V_16 ) {
case 0 :
break;
default:
V_13 = true ;
break;
}
default:
break;
}
switch ( V_5 ) {
case V_17 :
if ( ! V_12 -> V_18 && V_13 ) {
F_4 ( V_7 , 0x4f5 , 0x25a ) ;
V_12 -> V_19 = true ;
}
break;
case V_20 :
V_14 = F_5 ( V_7 , V_21 ) ;
if ( V_14 & V_22 ) {
F_6 ( V_8 -> V_9 ,
L_1 ) ;
return - V_23 ;
}
F_7 ( V_7 , V_24 ,
1 << V_2 -> V_25 , 1 << V_2 -> V_25 ) ;
if ( V_12 -> V_19 ) {
F_8 ( 75 ) ;
F_4 ( V_7 , 0x4f5 , 0xda ) ;
V_12 -> V_19 = false ;
V_12 -> V_18 ++ ;
}
break;
case V_26 :
if ( V_13 ) {
V_12 -> V_18 -- ;
if ( ! V_12 -> V_18 )
F_4 ( V_7 , 0x4f5 , 0x25a ) ;
}
F_7 ( V_7 , V_24 ,
1 << V_2 -> V_25 , 0 ) ;
break;
case V_27 :
if ( V_13 ) {
if ( ! V_12 -> V_18 )
F_4 ( V_7 , 0x4f5 , 0x0da ) ;
}
break;
}
return 0 ;
}
static T_1 F_9 ( int V_28 , void * V_29 )
{
struct V_8 * V_8 = V_29 ;
unsigned int V_14 ;
int V_30 ;
V_30 = F_10 ( V_8 -> V_31 , V_21 ,
& V_14 ) ;
if ( V_30 != 0 ) {
F_11 ( V_8 -> V_9 , L_2 ,
V_30 ) ;
} else if ( V_14 & V_32 ) {
F_6 ( V_8 -> V_9 , L_3 ) ;
}
return V_33 ;
}
static T_1 F_12 ( int V_28 , void * V_29 )
{
struct V_8 * V_8 = V_29 ;
unsigned int V_14 ;
int V_30 ;
V_30 = F_10 ( V_8 -> V_31 , V_21 ,
& V_14 ) ;
if ( V_30 != 0 ) {
F_11 ( V_8 -> V_9 , L_2 ,
V_30 ) ;
} else if ( V_14 & V_22 ) {
F_6 ( V_8 -> V_9 , L_4 ) ;
V_30 = F_13 ( V_8 -> V_31 ,
V_24 ,
V_34 |
V_35 , 0 ) ;
if ( V_30 != 0 )
F_6 ( V_8 -> V_9 ,
L_5 ,
V_30 ) ;
}
return V_33 ;
}
int F_14 ( struct V_6 * V_7 )
{
struct V_11 * V_12 = F_3 ( V_7 ) ;
struct V_8 * V_8 = V_12 -> V_8 ;
int V_30 ;
V_30 = F_15 ( & V_7 -> V_36 , & V_37 , 1 ) ;
if ( V_30 != 0 )
return V_30 ;
switch ( V_8 -> type ) {
case V_38 :
break;
default:
V_30 = F_15 ( & V_7 -> V_36 ,
& V_39 , 1 ) ;
if ( V_30 != 0 )
return V_30 ;
break;
}
V_30 = F_16 ( V_8 , V_40 ,
L_6 , F_9 ,
V_8 ) ;
if ( V_30 != 0 )
F_11 ( V_8 -> V_9 ,
L_7 ,
V_30 ) ;
V_30 = F_16 ( V_8 , V_41 ,
L_8 , F_12 ,
V_8 ) ;
if ( V_30 != 0 )
F_11 ( V_8 -> V_9 ,
L_9 ,
V_30 ) ;
return 0 ;
}
int F_17 ( struct V_6 * V_7 )
{
struct V_11 * V_12 = F_3 ( V_7 ) ;
struct V_8 * V_8 = V_12 -> V_8 ;
int V_42 ;
switch ( V_8 -> type ) {
case V_43 :
F_18 ( & V_7 -> V_36 , L_10 ) ;
break;
default:
break;
}
F_18 ( & V_7 -> V_36 , L_11 ) ;
for ( V_42 = 0 ; V_42 < F_19 ( V_8 -> V_44 . V_45 ) ; V_42 ++ ) {
switch ( V_8 -> V_44 . V_45 [ V_42 ] & V_46 ) {
case V_47 :
F_20 ( & V_7 -> V_36 ,
L_11 ) ;
break;
case V_48 :
F_20 ( & V_7 -> V_36 ,
L_10 ) ;
break;
default:
break;
}
}
return 0 ;
}
static void F_21 ( struct V_6 * V_7 , int V_49 )
{
struct V_11 * V_12 = F_3 ( V_7 ) ;
unsigned int V_14 ;
int V_42 ;
if ( V_49 )
V_14 = V_50 ;
else
V_14 = 0 ;
for ( V_42 = 0 ; V_42 < V_12 -> V_51 ; V_42 ++ )
F_7 ( V_7 ,
V_52 + ( V_42 * 4 ) ,
V_50 , V_14 ) ;
}
int F_22 ( struct V_1 * V_2 , struct V_3 * V_4 ,
int V_5 )
{
struct V_11 * V_12 = F_3 ( V_2 -> V_7 ) ;
unsigned int V_53 ;
if ( V_2 -> V_25 % 2 )
V_53 = V_52 + ( ( V_2 -> V_25 / 2 ) * 8 ) ;
else
V_53 = V_54 + ( ( V_2 -> V_25 / 2 ) * 8 ) ;
switch ( V_5 ) {
case V_17 :
V_12 -> V_55 ++ ;
break;
case V_20 :
F_7 ( V_2 -> V_7 , V_53 , V_56 , 0 ) ;
V_12 -> V_55 -- ;
if ( V_12 -> V_55 == 0 ) {
F_8 ( 1 ) ;
F_21 ( V_2 -> V_7 , 1 ) ;
}
break;
case V_26 :
F_7 ( V_2 -> V_7 , V_53 ,
V_56 | V_50 ,
V_56 | V_50 ) ;
break;
case V_27 :
V_53 = F_5 ( V_2 -> V_7 , V_57 ) ;
if ( V_53 == 0 )
F_21 ( V_2 -> V_7 , 0 ) ;
}
return 0 ;
}
int F_23 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
int V_5 )
{
switch ( V_5 ) {
case V_20 :
switch ( V_2 -> V_25 ) {
case V_58 :
case V_59 :
case V_60 :
case V_61 :
case V_62 :
case V_63 :
F_8 ( 17 ) ;
break;
default:
break;
}
break;
}
return 0 ;
}
int F_24 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
int V_5 )
{
struct V_11 * V_12 = F_3 ( V_2 -> V_7 ) ;
unsigned int V_64 = 1 << V_2 -> V_25 ;
unsigned int V_14 ;
switch ( V_5 ) {
case V_20 :
V_14 = V_64 ;
break;
case V_26 :
V_14 = 0 ;
break;
default:
return - V_65 ;
}
V_12 -> V_8 -> V_66 &= ~ V_64 ;
V_12 -> V_8 -> V_66 |= V_14 ;
if ( V_12 -> V_8 -> V_67 )
V_14 = 0 ;
F_7 ( V_2 -> V_7 , V_24 , V_64 , V_14 ) ;
return F_23 ( V_2 , V_4 , V_5 ) ;
}
static int F_25 ( struct V_6 * V_7 , unsigned int V_68 ,
unsigned int V_69 )
{
struct V_11 * V_12 = F_3 ( V_7 ) ;
unsigned int V_53 ;
unsigned int * V_70 ;
int V_71 , div , V_72 ;
switch ( V_68 ) {
case V_73 :
V_53 = V_74 ;
V_72 = V_12 -> V_75 ;
break;
case V_76 :
V_53 = V_77 ;
V_72 = V_12 -> V_78 ;
break;
default:
return - V_65 ;
}
if ( V_72 % 8000 )
V_70 = V_79 ;
else
V_70 = V_80 ;
for ( V_71 = 0 ; V_71 < F_19 ( V_80 ) &&
V_70 [ V_71 ] <= V_72 ; V_71 ++ ) {
div = 1 ;
while ( V_70 [ V_71 ] / div >= V_69 && div < 32 ) {
if ( V_70 [ V_71 ] / div == V_69 ) {
F_26 ( V_7 -> V_9 , L_12 ,
V_69 ) ;
F_7 ( V_7 , V_53 ,
V_81 |
V_82 ,
( div <<
V_83 ) |
V_71 ) ;
return 0 ;
}
div ++ ;
}
}
F_11 ( V_7 -> V_9 , L_13 , V_69 ) ;
return - V_65 ;
}
int F_27 ( struct V_6 * V_7 , int V_84 ,
int V_85 , unsigned int V_69 , int V_86 )
{
struct V_11 * V_12 = F_3 ( V_7 ) ;
struct V_8 * V_8 = V_12 -> V_8 ;
char * V_87 ;
unsigned int V_53 ;
unsigned int V_64 = V_88 | V_89 ;
unsigned int V_14 = V_85 << V_90 ;
unsigned int * V_68 ;
switch ( V_84 ) {
case V_91 :
V_87 = L_14 ;
V_53 = V_92 ;
V_68 = & V_12 -> V_75 ;
V_64 |= V_93 ;
break;
case V_94 :
V_87 = L_15 ;
V_53 = V_95 ;
V_68 = & V_12 -> V_78 ;
break;
case V_73 :
case V_76 :
return F_25 ( V_7 , V_84 , V_69 ) ;
default:
return - V_65 ;
}
switch ( V_69 ) {
case 5644800 :
case 6144000 :
break;
case 11289600 :
case 12288000 :
V_14 |= V_96 << V_97 ;
break;
case 22579200 :
case 24576000 :
V_14 |= V_98 << V_97 ;
break;
case 45158400 :
case 49152000 :
V_14 |= V_99 << V_97 ;
break;
case 67737600 :
case 73728000 :
V_14 |= V_100 << V_97 ;
break;
case 90316800 :
case 98304000 :
V_14 |= V_101 << V_97 ;
break;
case 135475200 :
case 147456000 :
V_14 |= V_102 << V_97 ;
break;
case 0 :
F_26 ( V_8 -> V_9 , L_16 , V_87 ) ;
* V_68 = V_69 ;
return 0 ;
default:
return - V_65 ;
}
* V_68 = V_69 ;
if ( V_69 % 6144000 )
V_14 |= V_93 ;
F_26 ( V_8 -> V_9 , L_17 , V_87 , V_69 ) ;
return F_13 ( V_8 -> V_31 , V_53 , V_64 , V_14 ) ;
}
static int F_28 ( struct V_103 * V_104 , unsigned int V_105 )
{
struct V_6 * V_7 = V_104 -> V_7 ;
int V_106 , V_107 , V_108 , V_109 ;
V_109 = V_104 -> V_110 -> V_109 ;
V_106 = 0 ;
V_107 = 0 ;
switch ( V_105 & V_111 ) {
case V_112 :
V_108 = 0 ;
break;
case V_113 :
V_108 = 2 ;
break;
default:
F_29 ( V_104 , L_18 ,
V_105 & V_111 ) ;
return - V_65 ;
}
switch ( V_105 & V_114 ) {
case V_115 :
break;
case V_116 :
V_106 |= V_117 ;
break;
case V_118 :
V_107 |= V_119 ;
break;
case V_120 :
V_107 |= V_119 ;
V_106 |= V_117 ;
break;
default:
F_29 ( V_104 , L_19 ,
V_105 & V_114 ) ;
return - V_65 ;
}
switch ( V_105 & V_121 ) {
case V_122 :
break;
case V_123 :
V_107 |= V_124 ;
V_106 |= V_125 ;
break;
case V_126 :
V_107 |= V_124 ;
break;
case V_127 :
V_106 |= V_125 ;
break;
default:
return - V_65 ;
}
F_7 ( V_7 , V_109 + V_128 ,
V_124 | V_119 ,
V_107 ) ;
F_7 ( V_7 , V_109 + V_129 ,
V_125 |
V_117 , V_106 ) ;
F_7 ( V_7 , V_109 + V_130 ,
V_131 |
V_132 , V_106 ) ;
F_7 ( V_7 , V_109 + V_133 ,
V_134 , V_108 ) ;
return 0 ;
}
static int F_30 ( struct V_135 * V_136 ,
struct V_103 * V_104 )
{
struct V_6 * V_7 = V_104 -> V_7 ;
struct V_11 * V_12 = F_3 ( V_7 ) ;
struct V_137 * V_138 = & V_12 -> V_104 [ V_104 -> V_139 - 1 ] ;
const struct V_140 * V_141 ;
unsigned int V_142 ;
switch ( V_138 -> V_68 ) {
case V_91 :
V_142 = V_12 -> V_75 ;
break;
case V_94 :
V_142 = V_12 -> V_78 ;
break;
default:
return 0 ;
}
if ( V_142 == 0 )
return 0 ;
if ( V_142 % 8000 )
V_141 = & V_143 ;
else
V_141 = & V_144 ;
return V_140 ( V_136 -> V_145 , 0 ,
V_146 ,
V_141 ) ;
}
static int F_31 ( struct V_135 * V_136 ,
struct V_147 * V_148 ,
struct V_103 * V_104 )
{
struct V_6 * V_7 = V_104 -> V_7 ;
struct V_11 * V_12 = F_3 ( V_7 ) ;
struct V_137 * V_138 = & V_12 -> V_104 [ V_104 -> V_139 - 1 ] ;
int V_109 = V_104 -> V_110 -> V_109 ;
int V_42 , V_149 ;
for ( V_42 = 0 ; V_42 < F_19 ( V_150 ) ; V_42 ++ )
if ( V_150 [ V_42 ] == F_32 ( V_148 ) )
break;
if ( V_42 == F_19 ( V_150 ) ) {
F_29 ( V_104 , L_20 ,
F_32 ( V_148 ) ) ;
return - V_65 ;
}
V_149 = V_42 ;
switch ( V_138 -> V_68 ) {
case V_91 :
F_7 ( V_7 , V_151 ,
V_152 , V_149 ) ;
if ( V_109 )
F_7 ( V_7 , V_109 + V_153 ,
V_154 , 0 ) ;
break;
case V_94 :
F_7 ( V_7 , V_155 ,
V_156 , V_149 ) ;
if ( V_109 )
F_7 ( V_7 , V_109 + V_153 ,
V_154 ,
8 << V_157 ) ;
break;
default:
F_29 ( V_104 , L_21 , V_138 -> V_68 ) ;
return - V_65 ;
}
return 0 ;
}
static int F_33 ( struct V_135 * V_136 ,
struct V_147 * V_148 ,
struct V_103 * V_104 )
{
struct V_6 * V_7 = V_104 -> V_7 ;
struct V_11 * V_12 = F_3 ( V_7 ) ;
struct V_8 * V_8 = V_12 -> V_8 ;
int V_109 = V_104 -> V_110 -> V_109 ;
const int * V_70 ;
int V_42 , V_30 , V_14 ;
int V_158 = V_8 -> V_44 . V_159 [ V_104 -> V_139 - 1 ] ;
int V_107 , V_106 , V_160 , V_161 , V_162 ;
if ( F_32 ( V_148 ) % 8000 )
V_70 = & V_163 [ 0 ] ;
else
V_70 = & V_164 [ 0 ] ;
V_162 = F_34 ( V_148 ) ;
if ( V_158 && V_158 < F_35 ( V_148 ) ) {
F_36 ( V_104 , L_22 , V_158 ) ;
V_162 /= F_35 ( V_148 ) ;
V_162 *= V_158 ;
}
V_14 = F_5 ( V_7 , V_109 + V_133 ) ;
if ( F_35 ( V_148 ) == 1 && ( V_14 & V_134 ) ) {
F_36 ( V_104 , L_23 ) ;
V_162 *= 2 ;
}
for ( V_42 = 0 ; V_42 < F_19 ( V_163 ) ; V_42 ++ ) {
if ( V_70 [ V_42 ] >= V_162 &&
V_70 [ V_42 ] % F_32 ( V_148 ) == 0 ) {
V_107 = V_42 ;
break;
}
}
if ( V_42 == F_19 ( V_163 ) ) {
F_29 ( V_104 , L_20 ,
F_32 ( V_148 ) ) ;
return - V_65 ;
}
V_106 = V_70 [ V_107 ] / F_32 ( V_148 ) ;
F_36 ( V_104 , L_24 ,
V_70 [ V_107 ] , V_70 [ V_107 ] / V_106 ) ;
V_160 = F_37 ( F_38 ( V_148 ) ) ;
V_161 = V_160 << V_165 | V_160 ;
V_30 = F_31 ( V_136 , V_148 , V_104 ) ;
if ( V_30 != 0 )
return V_30 ;
F_7 ( V_7 , V_109 + V_128 ,
V_166 , V_107 ) ;
F_7 ( V_7 , V_109 + V_167 ,
V_168 , V_106 ) ;
F_7 ( V_7 , V_109 + V_169 ,
V_170 , V_106 ) ;
F_7 ( V_7 , V_109 + V_171 ,
V_172 |
V_173 , V_161 ) ;
F_7 ( V_7 , V_109 + V_174 ,
V_175 |
V_176 , V_161 ) ;
return 0 ;
}
static const char * F_39 ( int V_84 )
{
switch ( V_84 ) {
case V_91 :
return L_14 ;
case V_94 :
return L_15 ;
default:
return L_25 ;
}
}
static int F_40 ( struct V_103 * V_104 ,
int V_84 , unsigned int V_69 , int V_86 )
{
struct V_6 * V_7 = V_104 -> V_7 ;
struct V_11 * V_12 = F_3 ( V_7 ) ;
struct V_137 * V_138 = & V_12 -> V_104 [ V_104 -> V_139 - 1 ] ;
struct V_177 V_178 [ 2 ] ;
switch ( V_84 ) {
case V_91 :
case V_94 :
break;
default:
return - V_65 ;
}
if ( V_84 == V_138 -> V_68 )
return 0 ;
if ( V_104 -> V_179 ) {
F_11 ( V_7 -> V_9 , L_26 ,
V_104 -> V_139 ) ;
return - V_23 ;
}
F_26 ( V_7 -> V_9 , L_27 , V_104 -> V_139 + 1 ,
F_39 ( V_84 ) ) ;
memset ( & V_178 , 0 , sizeof( V_178 ) ) ;
V_178 [ 0 ] . V_180 = V_104 -> V_110 -> V_181 . V_182 ;
V_178 [ 1 ] . V_180 = V_104 -> V_110 -> V_183 . V_182 ;
V_178 [ 0 ] . V_85 = F_39 ( V_138 -> V_68 ) ;
V_178 [ 1 ] . V_85 = F_39 ( V_138 -> V_68 ) ;
F_41 ( & V_7 -> V_36 , V_178 , F_19 ( V_178 ) ) ;
V_178 [ 0 ] . V_85 = F_39 ( V_84 ) ;
V_178 [ 1 ] . V_85 = F_39 ( V_84 ) ;
F_42 ( & V_7 -> V_36 , V_178 , F_19 ( V_178 ) ) ;
V_138 -> V_68 = V_84 ;
return F_43 ( & V_7 -> V_36 ) ;
}
static int F_44 ( struct V_103 * V_104 , int V_184 )
{
struct V_6 * V_7 = V_104 -> V_7 ;
int V_109 = V_104 -> V_110 -> V_109 ;
unsigned int V_53 ;
if ( V_184 )
V_53 = V_185 ;
else
V_53 = 0 ;
return F_7 ( V_7 , V_109 + V_153 ,
V_185 , V_53 ) ;
}
int F_45 ( struct V_11 * V_12 , int V_139 )
{
struct V_137 * V_138 = & V_12 -> V_104 [ V_139 ] ;
V_138 -> V_68 = V_91 ;
return 0 ;
}
static T_1 F_46 ( int V_28 , void * V_29 )
{
struct V_186 * V_187 = V_29 ;
F_47 ( V_187 , L_28 ) ;
F_48 ( & V_187 -> V_188 ) ;
return V_33 ;
}
static int F_49 ( struct V_186 * V_187 ,
struct V_189 * V_190 ,
unsigned int V_191 ,
unsigned int V_192 )
{
unsigned int V_193 , div , V_194 ;
int V_42 , V_195 ;
F_47 ( V_187 , L_29 , V_191 , V_192 ) ;
div = 1 ;
V_190 -> V_196 = 0 ;
while ( ( V_191 / div ) > 13500000 ) {
div *= 2 ;
V_190 -> V_196 ++ ;
if ( div > 8 ) {
F_50 ( V_187 ,
L_30 ,
V_191 ) ;
return - V_65 ;
}
}
V_191 /= div ;
div = 1 ;
while ( V_192 * div < 90000000 * V_187 -> V_197 ) {
div ++ ;
if ( div > 7 ) {
F_50 ( V_187 , L_31 ,
V_192 ) ;
return - V_65 ;
}
}
V_193 = V_192 * div / V_187 -> V_197 ;
V_190 -> V_198 = div ;
F_47 ( V_187 , L_32 , V_193 ) ;
for ( V_42 = 0 ; V_42 < F_19 ( V_199 ) ; V_42 ++ ) {
if ( V_199 [ V_42 ] . V_200 <= V_191 && V_191 <= V_199 [ V_42 ] . V_201 ) {
V_190 -> V_202 = V_199 [ V_42 ] . V_202 ;
V_195 = V_199 [ V_42 ] . V_195 ;
break;
}
}
if ( V_42 == F_19 ( V_199 ) ) {
F_50 ( V_187 , L_33 ,
V_191 ) ;
return - V_65 ;
}
for ( V_42 = 0 ; V_42 < F_19 ( V_203 ) ; V_42 ++ ) {
if ( V_203 [ V_42 ] . V_200 <= V_191 && V_191 <= V_203 [ V_42 ] . V_201 ) {
V_190 -> V_204 = V_203 [ V_42 ] . V_204 ;
break;
}
}
if ( V_42 == F_19 ( V_203 ) ) {
F_50 ( V_187 , L_34 ,
V_191 ) ;
return - V_65 ;
}
V_190 -> V_205 = V_193 / ( V_195 * V_191 ) ;
if ( V_193 % ( V_195 * V_191 ) ) {
V_194 = F_51 ( V_193 , V_195 * V_191 ) ;
F_47 ( V_187 , L_35 , V_194 ) ;
V_190 -> V_206 = ( V_193 - ( V_190 -> V_205 * V_195 * V_191 ) )
/ V_194 ;
V_190 -> V_207 = ( V_195 * V_191 ) / V_194 ;
} else {
V_190 -> V_206 = 0 ;
V_190 -> V_207 = 0 ;
}
while ( V_190 -> V_207 >= ( 1 << 16 ) ) {
V_190 -> V_206 >>= 1 ;
V_190 -> V_207 >>= 1 ;
}
F_47 ( V_187 , L_36 ,
V_190 -> V_205 , V_190 -> V_206 , V_190 -> V_207 ) ;
F_47 ( V_187 , L_37 ,
V_190 -> V_202 , V_190 -> V_202 , V_190 -> V_198 , V_190 -> V_196 ) ;
F_47 ( V_187 , L_38 , V_190 -> V_204 ) ;
return 0 ;
}
static void F_52 ( struct V_8 * V_8 , unsigned int V_109 ,
struct V_189 * V_190 , int V_85 ,
bool V_208 )
{
F_13 ( V_8 -> V_31 , V_109 + 3 ,
V_209 , V_190 -> V_206 ) ;
F_13 ( V_8 -> V_31 , V_109 + 4 ,
V_210 , V_190 -> V_207 ) ;
F_13 ( V_8 -> V_31 , V_109 + 5 ,
V_211 ,
V_190 -> V_202 << V_212 ) ;
F_13 ( V_8 -> V_31 , V_109 + 6 ,
V_213 |
V_214 ,
V_190 -> V_196 << V_215 |
V_85 << V_216 ) ;
if ( V_208 )
F_13 ( V_8 -> V_31 , V_109 + 0x7 ,
V_217 ,
V_190 -> V_204 << V_218 ) ;
else
F_13 ( V_8 -> V_31 , V_109 + 0x9 ,
V_217 ,
V_190 -> V_204 << V_218 ) ;
F_13 ( V_8 -> V_31 , V_109 + 2 ,
V_219 | V_220 ,
V_219 | V_190 -> V_205 ) ;
}
static bool F_53 ( struct V_186 * V_187 )
{
struct V_8 * V_8 = V_187 -> V_8 ;
unsigned int V_53 ;
int V_30 ;
V_30 = F_10 ( V_8 -> V_31 , V_187 -> V_109 + 1 , & V_53 ) ;
if ( V_30 != 0 ) {
F_50 ( V_187 , L_39 ,
V_30 ) ;
return V_30 ;
}
return V_53 & V_221 ;
}
static void F_54 ( struct V_186 * V_187 ,
struct V_189 * V_71 ,
struct V_189 * V_208 )
{
struct V_8 * V_8 = V_187 -> V_8 ;
int V_30 ;
if ( V_187 -> V_222 >= 0 && V_187 -> V_222 != V_187 -> V_223 ) {
F_13 ( V_8 -> V_31 , V_187 -> V_109 + 5 ,
V_224 ,
V_71 -> V_198 << V_225 ) ;
F_52 ( V_8 , V_187 -> V_109 , V_71 , V_187 -> V_222 ,
false ) ;
if ( V_187 -> V_223 >= 0 )
F_52 ( V_8 , V_187 -> V_109 + 0x10 , V_208 ,
V_187 -> V_223 , true ) ;
} else if ( V_187 -> V_223 >= 0 ) {
F_13 ( V_8 -> V_31 , V_187 -> V_109 + 5 ,
V_224 ,
V_208 -> V_198 << V_225 ) ;
F_52 ( V_8 , V_187 -> V_109 , V_208 ,
V_187 -> V_223 , false ) ;
F_13 ( V_8 -> V_31 , V_187 -> V_109 + 0x11 ,
V_226 , 0 ) ;
} else {
F_50 ( V_187 , L_40 ) ;
return;
}
if ( V_187 -> V_223 >= 0 && V_187 -> V_227 > 100000 )
F_13 ( V_8 -> V_31 , V_187 -> V_109 + 0x17 ,
V_228 , 0 ) ;
else
F_13 ( V_8 -> V_31 , V_187 -> V_109 + 0x17 ,
V_228 , V_228 ) ;
if ( ! F_53 ( V_187 ) )
F_55 ( V_8 -> V_9 ) ;
F_56 ( & V_187 -> V_188 ) ;
F_13 ( V_8 -> V_31 , V_187 -> V_109 + 1 ,
V_221 , V_221 ) ;
if ( V_187 -> V_222 >= 0 && V_187 -> V_223 >= 0 &&
V_187 -> V_222 != V_187 -> V_223 )
F_13 ( V_8 -> V_31 , V_187 -> V_109 + 0x11 ,
V_226 ,
V_226 ) ;
V_30 = F_57 ( & V_187 -> V_188 ,
F_58 ( 250 ) ) ;
if ( V_30 == 0 )
F_59 ( V_187 , L_41 ) ;
}
static void F_60 ( struct V_186 * V_187 )
{
struct V_8 * V_8 = V_187 -> V_8 ;
bool V_229 ;
F_61 ( V_8 -> V_31 , V_187 -> V_109 + 1 ,
V_221 , 0 , & V_229 ) ;
F_13 ( V_8 -> V_31 , V_187 -> V_109 + 0x11 ,
V_226 , 0 ) ;
if ( V_229 )
F_62 ( V_8 -> V_9 ) ;
}
int F_63 ( struct V_186 * V_187 , int V_85 ,
unsigned int V_191 , unsigned int V_192 )
{
struct V_189 V_71 , V_208 ;
int V_30 ;
if ( V_187 -> V_222 == V_85 && V_187 -> V_230 == V_191 )
return 0 ;
if ( V_187 -> V_231 && V_191 > 0 ) {
V_30 = F_49 ( V_187 , & V_71 , V_191 , V_187 -> V_231 ) ;
if ( V_30 != 0 )
return V_30 ;
if ( V_187 -> V_223 >= 0 ) {
V_30 = F_49 ( V_187 , & V_208 , V_187 -> V_227 ,
V_187 -> V_231 ) ;
if ( V_30 != 0 )
return V_30 ;
}
}
V_187 -> V_222 = V_85 ;
V_187 -> V_230 = V_191 ;
if ( V_187 -> V_231 && V_191 > 0 ) {
F_54 ( V_187 , & V_71 , & V_208 ) ;
}
return 0 ;
}
int F_64 ( struct V_186 * V_187 , int V_85 ,
unsigned int V_191 , unsigned int V_192 )
{
struct V_189 V_71 , V_208 ;
int V_30 ;
if ( V_187 -> V_223 == V_85 &&
V_187 -> V_227 == V_191 && V_187 -> V_231 == V_192 )
return 0 ;
if ( V_192 ) {
if ( V_187 -> V_222 >= 0 ) {
V_30 = F_49 ( V_187 , & V_71 , V_187 -> V_230 ,
V_192 ) ;
if ( V_30 != 0 )
return V_30 ;
}
V_30 = F_49 ( V_187 , & V_208 , V_191 , V_192 ) ;
if ( V_30 != 0 )
return V_30 ;
}
V_187 -> V_223 = V_85 ;
V_187 -> V_227 = V_191 ;
V_187 -> V_231 = V_192 ;
if ( V_192 ) {
F_54 ( V_187 , & V_71 , & V_208 ) ;
} else {
F_60 ( V_187 ) ;
}
return 0 ;
}
int F_65 ( struct V_8 * V_8 , int V_139 , int V_109 , int V_232 ,
int V_233 , struct V_186 * V_187 )
{
int V_30 ;
unsigned int V_14 ;
F_66 ( & V_187 -> V_188 ) ;
V_187 -> V_139 = V_139 ;
V_187 -> V_109 = V_109 ;
V_187 -> V_8 = V_8 ;
V_187 -> V_223 = V_234 ;
F_10 ( V_8 -> V_31 , V_235 , & V_14 ) ;
switch ( V_14 & V_236 ) {
case V_237 :
case V_238 :
V_187 -> V_222 = V_14 & V_236 ;
break;
default:
V_187 -> V_222 = V_234 ;
}
V_187 -> V_230 = 32768 ;
snprintf ( V_187 -> V_239 , sizeof( V_187 -> V_239 ) , L_42 , V_139 ) ;
snprintf ( V_187 -> V_240 , sizeof( V_187 -> V_240 ) ,
L_43 , V_139 ) ;
V_30 = F_16 ( V_8 , V_233 , V_187 -> V_240 ,
F_46 , V_187 ) ;
if ( V_30 != 0 ) {
F_11 ( V_8 -> V_9 , L_44 ,
V_139 , V_30 ) ;
}
F_13 ( V_8 -> V_31 , V_187 -> V_109 + 1 ,
V_241 , 0 ) ;
return 0 ;
}
int F_67 ( struct V_6 * V_7 , int V_242 , bool V_243 )
{
unsigned int V_53 , V_14 ;
if ( V_242 < 1 || V_242 > 6 )
return - V_65 ;
V_53 = V_244 + ( V_242 - 1 ) * 8 ;
if ( V_243 )
V_14 = V_245 ;
else
V_14 = 0 ;
return F_7 ( V_7 , V_53 , V_245 , V_14 ) ;
}
