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
F_4 ( V_8 -> V_19 , 0x4f5 , 0x25a ) ;
V_12 -> V_20 = true ;
}
break;
case V_21 :
V_14 = F_5 ( V_7 , V_22 ) ;
if ( V_14 & V_23 ) {
F_6 ( V_8 -> V_9 ,
L_1 ) ;
return - V_24 ;
}
F_7 ( V_8 -> V_19 ,
V_25 ,
1 << V_2 -> V_26 , 1 << V_2 -> V_26 ) ;
if ( V_12 -> V_20 ) {
F_8 ( 75 ) ;
F_4 ( V_8 -> V_19 , 0x4f5 , 0xda ) ;
V_12 -> V_20 = false ;
V_12 -> V_18 ++ ;
}
break;
case V_27 :
if ( V_13 ) {
V_12 -> V_18 -- ;
if ( ! V_12 -> V_18 )
F_4 ( V_8 -> V_19 ,
0x4f5 , 0x25a ) ;
}
F_7 ( V_8 -> V_19 ,
V_25 ,
1 << V_2 -> V_26 , 0 ) ;
break;
case V_28 :
if ( V_13 ) {
if ( ! V_12 -> V_18 )
F_4 ( V_8 -> V_19 ,
0x4f5 , 0x0da ) ;
}
break;
}
return 0 ;
}
static T_1 F_9 ( int V_29 , void * V_30 )
{
struct V_8 * V_8 = V_30 ;
unsigned int V_14 ;
int V_31 ;
V_31 = F_10 ( V_8 -> V_19 , V_22 ,
& V_14 ) ;
if ( V_31 != 0 ) {
F_11 ( V_8 -> V_9 , L_2 ,
V_31 ) ;
} else if ( V_14 & V_32 ) {
F_6 ( V_8 -> V_9 , L_3 ) ;
}
return V_33 ;
}
static T_1 F_12 ( int V_29 , void * V_30 )
{
struct V_8 * V_8 = V_30 ;
unsigned int V_14 ;
int V_31 ;
V_31 = F_10 ( V_8 -> V_19 , V_22 ,
& V_14 ) ;
if ( V_31 != 0 ) {
F_11 ( V_8 -> V_9 , L_2 ,
V_31 ) ;
} else if ( V_14 & V_23 ) {
F_6 ( V_8 -> V_9 , L_4 ) ;
V_31 = F_13 ( V_8 -> V_19 ,
V_25 ,
V_34 |
V_35 , 0 ) ;
if ( V_31 != 0 )
F_6 ( V_8 -> V_9 ,
L_5 ,
V_31 ) ;
}
return V_33 ;
}
int F_14 ( struct V_6 * V_7 )
{
struct V_11 * V_12 = F_3 ( V_7 ) ;
struct V_8 * V_8 = V_12 -> V_8 ;
int V_31 ;
V_31 = F_15 ( & V_7 -> V_36 , & V_37 , 1 ) ;
if ( V_31 != 0 )
return V_31 ;
switch ( V_8 -> type ) {
case V_38 :
break;
default:
V_31 = F_15 ( & V_7 -> V_36 ,
& V_39 , 1 ) ;
if ( V_31 != 0 )
return V_31 ;
break;
}
V_31 = F_16 ( V_8 , V_40 ,
L_6 , F_9 ,
V_8 ) ;
if ( V_31 != 0 )
F_11 ( V_8 -> V_9 ,
L_7 ,
V_31 ) ;
V_31 = F_16 ( V_8 , V_41 ,
L_8 , F_12 ,
V_8 ) ;
if ( V_31 != 0 )
F_11 ( V_8 -> V_9 ,
L_9 ,
V_31 ) ;
return 0 ;
}
int F_17 ( struct V_6 * V_7 )
{
struct V_11 * V_12 = F_3 ( V_7 ) ;
struct V_8 * V_8 = V_12 -> V_8 ;
int V_42 ;
for ( V_42 = 0 ; V_42 < V_43 ; ++ V_42 ) {
if ( V_8 -> V_44 . V_45 [ V_42 ] )
F_18 ( & V_7 -> V_36 ,
& V_46 [ V_42 ] , 1 ) ;
}
return 0 ;
}
int F_19 ( struct V_6 * V_7 )
{
struct V_11 * V_12 = F_3 ( V_7 ) ;
struct V_8 * V_8 = V_12 -> V_8 ;
int V_42 ;
switch ( V_8 -> type ) {
case V_47 :
F_20 ( & V_7 -> V_36 , L_10 ) ;
break;
default:
break;
}
F_20 ( & V_7 -> V_36 , L_11 ) ;
for ( V_42 = 0 ; V_42 < F_21 ( V_8 -> V_44 . V_48 ) ; V_42 ++ ) {
switch ( V_8 -> V_44 . V_48 [ V_42 ] & V_49 ) {
case V_50 :
F_22 ( & V_7 -> V_36 ,
L_11 ) ;
break;
case V_51 :
F_22 ( & V_7 -> V_36 ,
L_10 ) ;
break;
default:
break;
}
}
return 0 ;
}
static void F_23 ( struct V_6 * V_7 , int V_52 )
{
struct V_11 * V_12 = F_3 ( V_7 ) ;
unsigned int V_14 ;
int V_42 ;
if ( V_52 )
V_14 = V_53 ;
else
V_14 = 0 ;
for ( V_42 = 0 ; V_42 < V_12 -> V_54 ; V_42 ++ )
F_24 ( V_7 ,
V_55 + ( V_42 * 4 ) ,
V_53 , V_14 ) ;
}
int F_25 ( struct V_1 * V_2 , struct V_3 * V_4 ,
int V_5 )
{
struct V_11 * V_12 = F_3 ( V_2 -> V_7 ) ;
unsigned int V_56 ;
if ( V_2 -> V_26 % 2 )
V_56 = V_55 + ( ( V_2 -> V_26 / 2 ) * 8 ) ;
else
V_56 = V_57 + ( ( V_2 -> V_26 / 2 ) * 8 ) ;
switch ( V_5 ) {
case V_17 :
V_12 -> V_58 ++ ;
break;
case V_21 :
F_24 ( V_2 -> V_7 , V_56 , V_59 , 0 ) ;
V_12 -> V_58 -- ;
if ( V_12 -> V_58 == 0 ) {
F_8 ( 1 ) ;
F_23 ( V_2 -> V_7 , 1 ) ;
}
break;
case V_27 :
F_24 ( V_2 -> V_7 , V_56 ,
V_59 | V_53 ,
V_59 | V_53 ) ;
break;
case V_28 :
V_56 = F_5 ( V_2 -> V_7 , V_60 ) ;
if ( V_56 == 0 )
F_23 ( V_2 -> V_7 , 0 ) ;
}
return 0 ;
}
int F_26 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
int V_5 )
{
switch ( V_5 ) {
case V_21 :
switch ( V_2 -> V_26 ) {
case V_61 :
case V_62 :
case V_63 :
case V_64 :
case V_65 :
case V_66 :
F_8 ( 17 ) ;
break;
default:
break;
}
break;
}
return 0 ;
}
int F_27 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
int V_5 )
{
struct V_11 * V_12 = F_3 ( V_2 -> V_7 ) ;
struct V_8 * V_8 = V_12 -> V_8 ;
unsigned int V_67 = 1 << V_2 -> V_26 ;
unsigned int V_14 ;
switch ( V_5 ) {
case V_21 :
V_14 = V_67 ;
break;
case V_27 :
V_14 = 0 ;
break;
default:
return - V_68 ;
}
V_12 -> V_8 -> V_69 &= ~ V_67 ;
V_12 -> V_8 -> V_69 |= V_14 ;
if ( V_12 -> V_8 -> V_70 )
V_14 = 0 ;
F_7 ( V_8 -> V_19 , V_25 ,
V_67 , V_14 ) ;
return F_26 ( V_2 , V_4 , V_5 ) ;
}
static int F_28 ( struct V_6 * V_7 , unsigned int V_71 ,
unsigned int V_72 )
{
struct V_11 * V_12 = F_3 ( V_7 ) ;
unsigned int V_56 ;
unsigned int * V_73 ;
int V_74 , div , V_75 ;
switch ( V_71 ) {
case V_76 :
V_56 = V_77 ;
V_75 = V_12 -> V_78 ;
break;
case V_79 :
V_56 = V_80 ;
V_75 = V_12 -> V_81 ;
break;
default:
return - V_68 ;
}
if ( V_75 % 8000 )
V_73 = V_82 ;
else
V_73 = V_83 ;
for ( V_74 = 0 ; V_74 < F_21 ( V_83 ) &&
V_73 [ V_74 ] <= V_75 ; V_74 ++ ) {
div = 1 ;
while ( V_73 [ V_74 ] / div >= V_72 && div < 32 ) {
if ( V_73 [ V_74 ] / div == V_72 ) {
F_29 ( V_7 -> V_9 , L_12 ,
V_72 ) ;
F_24 ( V_7 , V_56 ,
V_84 |
V_85 ,
( div <<
V_86 ) |
V_74 ) ;
return 0 ;
}
div ++ ;
}
}
F_11 ( V_7 -> V_9 , L_13 , V_72 ) ;
return - V_68 ;
}
int F_30 ( struct V_6 * V_7 , int V_87 ,
int V_88 , unsigned int V_72 , int V_89 )
{
struct V_11 * V_12 = F_3 ( V_7 ) ;
struct V_8 * V_8 = V_12 -> V_8 ;
char * V_90 ;
unsigned int V_56 ;
unsigned int V_67 = V_91 | V_92 ;
unsigned int V_14 = V_88 << V_93 ;
unsigned int * V_71 ;
switch ( V_87 ) {
case V_94 :
V_90 = L_14 ;
V_56 = V_95 ;
V_71 = & V_12 -> V_78 ;
V_67 |= V_96 ;
break;
case V_97 :
V_90 = L_15 ;
V_56 = V_98 ;
V_71 = & V_12 -> V_81 ;
break;
case V_76 :
case V_79 :
return F_28 ( V_7 , V_87 , V_72 ) ;
default:
return - V_68 ;
}
switch ( V_72 ) {
case 5644800 :
case 6144000 :
break;
case 11289600 :
case 12288000 :
V_14 |= V_99 << V_100 ;
break;
case 22579200 :
case 24576000 :
V_14 |= V_101 << V_100 ;
break;
case 45158400 :
case 49152000 :
V_14 |= V_102 << V_100 ;
break;
case 67737600 :
case 73728000 :
V_14 |= V_103 << V_100 ;
break;
case 90316800 :
case 98304000 :
V_14 |= V_104 << V_100 ;
break;
case 135475200 :
case 147456000 :
V_14 |= V_105 << V_100 ;
break;
case 0 :
F_29 ( V_8 -> V_9 , L_16 , V_90 ) ;
* V_71 = V_72 ;
return 0 ;
default:
return - V_68 ;
}
* V_71 = V_72 ;
if ( V_72 % 6144000 )
V_14 |= V_96 ;
F_29 ( V_8 -> V_9 , L_17 , V_90 , V_72 ) ;
return F_13 ( V_8 -> V_19 , V_56 , V_67 , V_14 ) ;
}
static int F_31 ( struct V_106 * V_107 , unsigned int V_108 )
{
struct V_6 * V_7 = V_107 -> V_7 ;
struct V_11 * V_12 = F_3 ( V_7 ) ;
struct V_8 * V_8 = V_12 -> V_8 ;
int V_109 , V_110 , V_111 , V_112 ;
V_112 = V_107 -> V_113 -> V_112 ;
V_109 = 0 ;
V_110 = 0 ;
switch ( V_108 & V_114 ) {
case V_115 :
V_111 = V_116 ;
break;
case V_117 :
if ( ( V_108 & V_118 )
!= V_119 ) {
F_32 ( V_107 , L_18 ) ;
return - V_68 ;
}
V_111 = V_120 ;
break;
case V_121 :
V_111 = V_122 ;
break;
case V_123 :
if ( ( V_108 & V_118 )
!= V_119 ) {
F_32 ( V_107 , L_19 ) ;
return - V_68 ;
}
V_111 = V_124 ;
break;
default:
F_32 ( V_107 , L_20 ,
V_108 & V_114 ) ;
return - V_68 ;
}
switch ( V_108 & V_118 ) {
case V_125 :
break;
case V_126 :
V_109 |= V_127 ;
break;
case V_128 :
V_110 |= V_129 ;
break;
case V_119 :
V_110 |= V_129 ;
V_109 |= V_127 ;
break;
default:
F_32 ( V_107 , L_21 ,
V_108 & V_118 ) ;
return - V_68 ;
}
switch ( V_108 & V_130 ) {
case V_131 :
break;
case V_132 :
V_110 |= V_133 ;
V_109 |= V_134 ;
break;
case V_135 :
V_110 |= V_133 ;
break;
case V_136 :
V_109 |= V_134 ;
break;
default:
return - V_68 ;
}
F_7 ( V_8 -> V_19 , V_112 + V_137 ,
V_133 |
V_129 ,
V_110 ) ;
F_7 ( V_8 -> V_19 , V_112 + V_138 ,
V_134 |
V_127 , V_109 ) ;
F_7 ( V_8 -> V_19 ,
V_112 + V_139 ,
V_140 |
V_141 , V_109 ) ;
F_13 ( V_8 -> V_19 , V_112 + V_142 ,
V_143 , V_111 ) ;
return 0 ;
}
static int F_33 ( struct V_144 * V_145 ,
struct V_106 * V_107 )
{
struct V_6 * V_7 = V_107 -> V_7 ;
struct V_11 * V_12 = F_3 ( V_7 ) ;
struct V_146 * V_147 = & V_12 -> V_107 [ V_107 -> V_148 - 1 ] ;
const struct V_149 * V_150 ;
unsigned int V_151 ;
switch ( V_147 -> V_71 ) {
case V_94 :
V_151 = V_12 -> V_78 ;
break;
case V_97 :
V_151 = V_12 -> V_81 ;
break;
default:
return 0 ;
}
if ( V_151 == 0 )
return 0 ;
if ( V_151 % 8000 )
V_150 = & V_152 ;
else
V_150 = & V_153 ;
return V_149 ( V_145 -> V_154 , 0 ,
V_155 ,
V_150 ) ;
}
static void F_34 ( struct V_6 * V_7 ,
unsigned int V_156 )
{
struct V_11 * V_12 = F_3 ( V_7 ) ;
struct V_8 * V_8 = V_12 -> V_8 ;
struct V_157 V_158 [] = {
{ 0x80 , 0x3 } ,
{ V_159 , 0 } ,
{ V_160 , 0 } ,
{ 0x80 , 0x0 } ,
} ;
F_35 ( & V_8 -> V_161 ) ;
V_158 [ 1 ] . V_162 = V_8 -> V_163 ;
if ( V_156 >= 176400 )
V_158 [ 2 ] . V_162 = V_8 -> V_164 ;
F_36 ( & V_8 -> V_161 ) ;
F_37 ( V_8 -> V_19 ,
V_158 ,
F_21 ( V_158 ) ) ;
}
static int F_38 ( struct V_144 * V_145 ,
struct V_165 * V_166 ,
struct V_106 * V_107 )
{
struct V_6 * V_7 = V_107 -> V_7 ;
struct V_11 * V_12 = F_3 ( V_7 ) ;
struct V_146 * V_147 = & V_12 -> V_107 [ V_107 -> V_148 - 1 ] ;
int V_112 = V_107 -> V_113 -> V_112 ;
int V_42 , V_167 ;
for ( V_42 = 0 ; V_42 < F_21 ( V_168 ) ; V_42 ++ )
if ( V_168 [ V_42 ] == F_39 ( V_166 ) )
break;
if ( V_42 == F_21 ( V_168 ) ) {
F_32 ( V_107 , L_22 ,
F_39 ( V_166 ) ) ;
return - V_68 ;
}
V_167 = V_42 ;
switch ( V_147 -> V_71 ) {
case V_94 :
switch ( V_12 -> V_8 -> type ) {
case V_15 :
F_34 ( V_7 ,
F_39 ( V_166 ) ) ;
break;
default:
break;
}
F_24 ( V_7 , V_169 ,
V_170 , V_167 ) ;
if ( V_112 )
F_24 ( V_7 , V_112 + V_171 ,
V_172 , 0 ) ;
break;
case V_97 :
F_24 ( V_7 , V_173 ,
V_174 , V_167 ) ;
if ( V_112 )
F_24 ( V_7 , V_112 + V_171 ,
V_172 ,
8 << V_175 ) ;
break;
default:
F_32 ( V_107 , L_23 , V_147 -> V_71 ) ;
return - V_68 ;
}
return 0 ;
}
static bool F_40 ( struct V_6 * V_7 ,
int V_112 , int V_110 , int V_109 , int V_176 )
{
int V_14 ;
V_14 = F_5 ( V_7 , V_112 + V_137 ) ;
if ( V_110 != ( V_14 & V_177 ) )
return true ;
V_14 = F_5 ( V_7 , V_112 + V_178 ) ;
if ( V_109 != ( V_14 & V_179 ) )
return true ;
V_14 = F_5 ( V_7 , V_112 + V_180 ) ;
if ( V_176 != ( V_14 & ( V_181 |
V_182 ) ) )
return true ;
return false ;
}
static int F_41 ( struct V_144 * V_145 ,
struct V_165 * V_166 ,
struct V_106 * V_107 )
{
struct V_6 * V_7 = V_107 -> V_7 ;
struct V_11 * V_12 = F_3 ( V_7 ) ;
struct V_8 * V_8 = V_12 -> V_8 ;
int V_112 = V_107 -> V_113 -> V_112 ;
const int * V_73 ;
int V_42 , V_31 , V_14 ;
int V_183 = F_42 ( V_166 ) ;
int V_184 = V_8 -> V_44 . V_185 [ V_107 -> V_148 - 1 ] ;
int V_186 = V_8 -> V_186 [ V_107 -> V_148 - 1 ] ;
int V_187 = V_8 -> V_187 [ V_107 -> V_148 - 1 ] ;
int V_110 , V_109 , V_188 , V_176 , V_189 ;
bool V_190 ;
unsigned int V_191 , V_192 ;
if ( F_39 ( V_166 ) % 8000 )
V_73 = & V_193 [ 0 ] ;
else
V_73 = & V_194 [ 0 ] ;
V_188 = F_43 ( F_44 ( V_166 ) ) ;
if ( V_187 ) {
F_45 ( V_107 , L_24 ,
V_187 , V_186 ) ;
V_189 = V_187 * V_186 * F_39 ( V_166 ) ;
V_183 = V_187 ;
} else {
V_189 = F_46 ( V_166 ) ;
V_186 = V_188 ;
}
if ( V_184 && V_184 < V_183 ) {
F_45 ( V_107 , L_25 , V_184 ) ;
V_189 /= V_183 ;
V_189 *= V_184 ;
}
V_14 = F_5 ( V_7 , V_112 + V_142 ) ;
V_14 &= V_143 ;
if ( ( V_183 & 1 ) && ( V_14 == V_122 ) ) {
F_45 ( V_107 , L_26 ) ;
V_189 /= V_183 ;
V_189 *= V_183 + 1 ;
}
for ( V_42 = 0 ; V_42 < F_21 ( V_193 ) ; V_42 ++ ) {
if ( V_73 [ V_42 ] >= V_189 &&
V_73 [ V_42 ] % F_39 ( V_166 ) == 0 ) {
V_110 = V_42 ;
break;
}
}
if ( V_42 == F_21 ( V_193 ) ) {
F_32 ( V_107 , L_22 ,
F_39 ( V_166 ) ) ;
return - V_68 ;
}
V_109 = V_73 [ V_110 ] / F_39 ( V_166 ) ;
F_45 ( V_107 , L_27 ,
V_73 [ V_110 ] , V_73 [ V_110 ] / V_109 ) ;
V_176 = V_188 << V_195 | V_186 ;
V_190 = F_40 ( V_7 , V_112 , V_110 , V_109 , V_176 ) ;
if ( V_190 ) {
V_191 = F_5 ( V_7 ,
V_112 + V_196 ) ;
V_192 = F_5 ( V_7 ,
V_112 + V_197 ) ;
F_7 ( V_8 -> V_19 ,
V_112 + V_196 , 0xff , 0x0 ) ;
F_13 ( V_8 -> V_19 ,
V_112 + V_197 , 0xff , 0x0 ) ;
}
V_31 = F_38 ( V_145 , V_166 , V_107 ) ;
if ( V_31 != 0 )
goto V_198;
if ( V_190 ) {
F_7 ( V_8 -> V_19 ,
V_112 + V_137 ,
V_177 , V_110 ) ;
F_7 ( V_8 -> V_19 ,
V_112 + V_178 ,
V_179 , V_109 ) ;
F_7 ( V_8 -> V_19 ,
V_112 + V_199 ,
V_200 , V_109 ) ;
F_7 ( V_8 -> V_19 ,
V_112 + V_180 ,
V_181 |
V_182 , V_176 ) ;
F_13 ( V_8 -> V_19 ,
V_112 + V_201 ,
V_202 |
V_203 , V_176 ) ;
}
V_198:
if ( V_190 ) {
F_7 ( V_8 -> V_19 ,
V_112 + V_196 ,
0xff , V_191 ) ;
F_13 ( V_8 -> V_19 ,
V_112 + V_197 ,
0xff , V_192 ) ;
}
return V_31 ;
}
static const char * F_47 ( int V_87 )
{
switch ( V_87 ) {
case V_94 :
return L_14 ;
case V_97 :
return L_15 ;
default:
return L_28 ;
}
}
static int F_48 ( struct V_106 * V_107 ,
int V_87 , unsigned int V_72 , int V_89 )
{
struct V_6 * V_7 = V_107 -> V_7 ;
struct V_11 * V_12 = F_3 ( V_7 ) ;
struct V_146 * V_147 = & V_12 -> V_107 [ V_107 -> V_148 - 1 ] ;
struct V_204 V_205 [ 2 ] ;
switch ( V_87 ) {
case V_94 :
case V_97 :
break;
default:
return - V_68 ;
}
if ( V_87 == V_147 -> V_71 )
return 0 ;
if ( V_107 -> V_206 ) {
F_11 ( V_7 -> V_9 , L_29 ,
V_107 -> V_148 ) ;
return - V_24 ;
}
F_29 ( V_7 -> V_9 , L_30 , V_107 -> V_148 + 1 ,
F_47 ( V_87 ) ) ;
memset ( & V_205 , 0 , sizeof( V_205 ) ) ;
V_205 [ 0 ] . V_207 = V_107 -> V_113 -> V_208 . V_209 ;
V_205 [ 1 ] . V_207 = V_107 -> V_113 -> V_210 . V_209 ;
V_205 [ 0 ] . V_88 = F_47 ( V_147 -> V_71 ) ;
V_205 [ 1 ] . V_88 = F_47 ( V_147 -> V_71 ) ;
F_49 ( & V_7 -> V_36 , V_205 , F_21 ( V_205 ) ) ;
V_205 [ 0 ] . V_88 = F_47 ( V_87 ) ;
V_205 [ 1 ] . V_88 = F_47 ( V_87 ) ;
F_18 ( & V_7 -> V_36 , V_205 , F_21 ( V_205 ) ) ;
V_147 -> V_71 = V_87 ;
return F_50 ( & V_7 -> V_36 ) ;
}
static int F_51 ( struct V_106 * V_107 , int V_211 )
{
struct V_6 * V_7 = V_107 -> V_7 ;
int V_112 = V_107 -> V_113 -> V_112 ;
unsigned int V_56 ;
if ( V_211 )
V_56 = V_212 ;
else
V_56 = 0 ;
return F_24 ( V_7 , V_112 + V_171 ,
V_212 , V_56 ) ;
}
static void F_52 ( struct V_106 * V_107 ,
unsigned int V_112 ,
int V_183 , unsigned int V_67 )
{
struct V_6 * V_7 = V_107 -> V_7 ;
struct V_11 * V_12 = F_3 ( V_7 ) ;
struct V_8 * V_8 = V_12 -> V_8 ;
int V_213 , V_42 ;
for ( V_42 = 0 ; V_42 < V_183 ; ++ V_42 ) {
V_213 = F_53 ( V_67 ) - 1 ;
if ( V_213 < 0 )
return;
F_54 ( V_8 -> V_19 , V_112 + V_42 , V_213 ) ;
V_67 &= ~ ( 1 << V_213 ) ;
}
if ( V_67 )
F_55 ( V_107 , L_31 ) ;
}
static int F_56 ( struct V_106 * V_107 , unsigned int V_214 ,
unsigned int V_215 , int V_216 , int V_217 )
{
struct V_6 * V_7 = V_107 -> V_7 ;
struct V_11 * V_12 = F_3 ( V_7 ) ;
struct V_8 * V_8 = V_12 -> V_8 ;
int V_112 = V_107 -> V_113 -> V_112 ;
int V_218 = V_107 -> V_113 -> V_210 . V_219 ;
int V_220 = V_107 -> V_113 -> V_208 . V_219 ;
if ( V_107 -> V_148 > V_221 )
return - V_222 ;
if ( V_216 == 0 ) {
V_214 = ( 1 << V_220 ) - 1 ;
V_215 = ( 1 << V_218 ) - 1 ;
}
F_52 ( V_107 , V_112 + V_223 ,
V_220 , V_214 ) ;
F_52 ( V_107 , V_112 + V_224 ,
V_218 , V_215 ) ;
V_8 -> V_186 [ V_107 -> V_148 - 1 ] = V_217 ;
V_8 -> V_187 [ V_107 -> V_148 - 1 ] = V_216 ;
return 0 ;
}
int F_57 ( struct V_11 * V_12 , int V_148 )
{
struct V_146 * V_147 = & V_12 -> V_107 [ V_148 ] ;
V_147 -> V_71 = V_94 ;
return 0 ;
}
static T_1 F_58 ( int V_29 , void * V_30 )
{
struct V_225 * V_226 = V_30 ;
F_59 ( V_226 , L_32 ) ;
F_60 ( & V_226 -> V_227 ) ;
return V_33 ;
}
static int F_61 ( struct V_225 * V_226 ,
unsigned int V_228 ,
unsigned int V_229 )
{
unsigned int V_230 ;
if ( V_226 -> V_231 && V_229 != V_226 -> V_231 ) {
F_62 ( V_226 ,
L_33 ) ;
return - V_68 ;
}
if ( V_228 / V_232 > V_233 ) {
F_62 ( V_226 ,
L_34 ,
V_228 ) ;
return - V_68 ;
}
V_230 = V_234 * V_226 -> V_235 ;
if ( V_229 * V_236 < V_230 ) {
F_62 ( V_226 , L_35 ,
V_229 ) ;
return - V_68 ;
}
return 0 ;
}
static int F_63 ( unsigned int V_228 , int * V_237 )
{
int V_42 ;
for ( V_42 = 0 ; V_42 < F_21 ( V_238 ) ; V_42 ++ ) {
if ( V_238 [ V_42 ] . V_239 <= V_228 && V_228 <= V_238 [ V_42 ] . V_240 ) {
if ( V_237 )
* V_237 = V_238 [ V_42 ] . V_237 ;
return V_238 [ V_42 ] . V_241 ;
}
}
return - V_68 ;
}
static int F_64 ( struct V_225 * V_226 ,
struct V_242 * V_243 ,
unsigned int V_244 ,
unsigned int V_228 , bool V_245 )
{
int V_246 , V_241 ;
int V_247 , div ;
div = 1 ;
V_243 -> V_247 = 0 ;
while ( V_228 > V_233 ) {
div *= 2 ;
V_228 /= 2 ;
V_243 -> V_247 ++ ;
if ( div > V_232 )
return - V_68 ;
}
V_246 = F_63 ( V_228 , & V_243 -> V_237 ) ;
if ( V_246 < 0 ) {
F_62 ( V_226 , L_36 ,
V_228 ) ;
return V_246 ;
}
switch ( V_226 -> V_8 -> type ) {
case V_47 :
if ( V_226 -> V_8 -> V_16 < 3 || V_245 )
return V_246 ;
break;
default:
return V_246 ;
}
V_243 -> V_237 = V_246 - 1 ;
V_247 = V_243 -> V_247 ;
while ( div <= V_232 ) {
for ( V_241 = V_246 ; V_241 <= V_248 ;
V_241 ++ ) {
if ( ( V_249 / 2 ) /
( V_226 -> V_235 * V_241 ) < V_228 )
break;
if ( V_244 % ( V_241 * V_228 ) ) {
V_243 -> V_247 = V_247 ;
V_243 -> V_237 = V_241 - 1 ;
return V_241 ;
}
}
for ( V_241 = V_246 - 1 ; V_241 > 0 ; V_241 -- ) {
if ( V_244 % ( V_241 * V_228 ) ) {
V_243 -> V_247 = V_247 ;
V_243 -> V_237 = V_241 - 1 ;
return V_241 ;
}
}
div *= 2 ;
V_228 /= 2 ;
V_247 ++ ;
V_246 = F_63 ( V_228 , NULL ) ;
}
F_65 ( V_226 , L_37 ) ;
return V_243 -> V_237 + 1 ;
}
static int F_66 ( struct V_225 * V_226 ,
struct V_242 * V_243 ,
unsigned int V_228 , bool V_245 )
{
unsigned int V_244 , div , V_250 ;
int V_42 , V_241 ;
F_59 ( V_226 , L_38 , V_228 , V_226 -> V_231 ) ;
div = V_251 ;
while ( V_226 -> V_231 * div < V_234 * V_226 -> V_235 ) {
div ++ ;
if ( div > V_236 )
return - V_68 ;
}
V_244 = V_226 -> V_231 * div / V_226 -> V_235 ;
V_243 -> V_252 = div ;
F_59 ( V_226 , L_39 , V_244 ) ;
V_241 = F_64 ( V_226 , V_243 , V_244 , V_228 , V_245 ) ;
if ( V_241 < 0 )
return V_241 ;
V_228 = V_228 / ( 1 << V_243 -> V_247 ) ;
V_243 -> V_253 = V_244 / ( V_241 * V_228 ) ;
if ( V_244 % ( V_241 * V_228 ) ) {
V_250 = F_67 ( V_244 , V_241 * V_228 ) ;
F_59 ( V_226 , L_40 , V_250 ) ;
V_243 -> V_254 = ( V_244 - ( V_243 -> V_253 * V_241 * V_228 ) )
/ V_250 ;
V_243 -> V_255 = ( V_241 * V_228 ) / V_250 ;
} else {
V_243 -> V_254 = 0 ;
V_243 -> V_255 = 0 ;
}
while ( V_243 -> V_255 >= ( 1 << 16 ) ) {
V_243 -> V_254 >>= 1 ;
V_243 -> V_255 >>= 1 ;
}
for ( V_42 = 0 ; V_42 < F_21 ( V_256 ) ; V_42 ++ ) {
if ( V_256 [ V_42 ] . V_239 <= V_228 && V_228 <= V_256 [ V_42 ] . V_240 ) {
V_243 -> V_257 = V_256 [ V_42 ] . V_257 ;
break;
}
}
if ( V_42 == F_21 ( V_256 ) ) {
F_62 ( V_226 , L_41 ,
V_228 ) ;
return - V_68 ;
}
F_59 ( V_226 , L_42 ,
V_243 -> V_253 , V_243 -> V_254 , V_243 -> V_255 ) ;
F_59 ( V_226 , L_43 ,
V_243 -> V_237 , V_243 -> V_237 , V_243 -> V_252 , V_243 -> V_247 ) ;
F_59 ( V_226 , L_44 , V_243 -> V_257 ) ;
return 0 ;
}
static void F_68 ( struct V_8 * V_8 , unsigned int V_112 ,
struct V_242 * V_243 , int V_88 ,
bool V_245 )
{
F_7 ( V_8 -> V_19 , V_112 + 3 ,
V_258 , V_243 -> V_254 ) ;
F_7 ( V_8 -> V_19 , V_112 + 4 ,
V_259 , V_243 -> V_255 ) ;
F_7 ( V_8 -> V_19 , V_112 + 5 ,
V_260 ,
V_243 -> V_237 << V_261 ) ;
F_7 ( V_8 -> V_19 , V_112 + 6 ,
V_262 |
V_263 ,
V_243 -> V_247 << V_264 |
V_88 << V_265 ) ;
if ( V_245 ) {
F_13 ( V_8 -> V_19 , V_112 + 0x7 ,
V_266 ,
V_243 -> V_257 << V_267 ) ;
} else {
F_13 ( V_8 -> V_19 , V_112 + 0x5 ,
V_268 ,
V_243 -> V_252 << V_269 ) ;
F_13 ( V_8 -> V_19 , V_112 + 0x9 ,
V_266 ,
V_243 -> V_257 << V_267 ) ;
}
F_7 ( V_8 -> V_19 , V_112 + 2 ,
V_270 | V_271 ,
V_270 | V_243 -> V_253 ) ;
}
static int F_69 ( struct V_225 * V_226 )
{
struct V_8 * V_8 = V_226 -> V_8 ;
unsigned int V_56 ;
int V_31 ;
V_31 = F_10 ( V_8 -> V_19 , V_226 -> V_112 + 1 , & V_56 ) ;
if ( V_31 != 0 ) {
F_62 ( V_226 , L_45 ,
V_31 ) ;
return V_31 ;
}
return V_56 & V_272 ;
}
static int F_70 ( struct V_225 * V_226 )
{
struct V_8 * V_8 = V_226 -> V_8 ;
int V_31 ;
bool V_273 = false ;
int V_274 = F_69 ( V_226 ) ;
struct V_242 V_243 ;
if ( V_274 < 0 )
return V_274 ;
if ( V_274 ) {
F_7 ( V_226 -> V_8 -> V_19 , V_226 -> V_112 + 0x7 ,
V_266 , 0 ) ;
F_7 ( V_226 -> V_8 -> V_19 , V_226 -> V_112 + 1 ,
V_275 ,
V_275 ) ;
}
if ( V_226 -> V_276 >= 0 && V_226 -> V_277 &&
V_226 -> V_276 != V_226 -> V_278 ) {
F_66 ( V_226 , & V_243 , V_226 -> V_277 , false ) ;
F_68 ( V_8 , V_226 -> V_112 , & V_243 , V_226 -> V_276 ,
false ) ;
if ( V_226 -> V_278 >= 0 ) {
F_66 ( V_226 , & V_243 , V_226 -> V_279 , true ) ;
F_68 ( V_8 , V_226 -> V_112 + 0x10 , & V_243 ,
V_226 -> V_278 , true ) ;
V_273 = true ;
}
} else if ( V_226 -> V_278 >= 0 ) {
F_66 ( V_226 , & V_243 , V_226 -> V_279 , false ) ;
F_68 ( V_8 , V_226 -> V_112 , & V_243 ,
V_226 -> V_278 , false ) ;
F_7 ( V_8 -> V_19 , V_226 -> V_112 + 0x11 ,
V_280 , 0 ) ;
} else {
F_62 ( V_226 , L_46 ) ;
return - V_68 ;
}
if ( V_273 && V_226 -> V_279 > 100000 )
F_7 ( V_8 -> V_19 , V_226 -> V_112 + 0x17 ,
V_281 , 0 ) ;
else
F_7 ( V_8 -> V_19 , V_226 -> V_112 + 0x17 ,
V_281 ,
V_281 ) ;
if ( ! V_274 )
F_71 ( V_8 -> V_9 ) ;
F_72 ( & V_226 -> V_227 ) ;
F_7 ( V_8 -> V_19 , V_226 -> V_112 + 1 ,
V_272 , V_272 ) ;
if ( V_273 )
F_7 ( V_8 -> V_19 , V_226 -> V_112 + 0x11 ,
V_280 ,
V_280 ) ;
if ( V_274 )
F_7 ( V_8 -> V_19 , V_226 -> V_112 + 1 ,
V_275 , 0 ) ;
V_31 = F_73 ( & V_226 -> V_227 ,
F_74 ( 250 ) ) ;
if ( V_31 == 0 )
F_65 ( V_226 , L_47 ) ;
return 0 ;
}
static void F_75 ( struct V_225 * V_226 )
{
struct V_8 * V_8 = V_226 -> V_8 ;
bool V_282 ;
F_7 ( V_8 -> V_19 , V_226 -> V_112 + 1 ,
V_275 , V_275 ) ;
F_76 ( V_8 -> V_19 , V_226 -> V_112 + 1 ,
V_272 , 0 , & V_282 ) ;
F_13 ( V_8 -> V_19 , V_226 -> V_112 + 0x11 ,
V_280 , 0 ) ;
F_7 ( V_8 -> V_19 , V_226 -> V_112 + 1 ,
V_275 , 0 ) ;
if ( V_282 )
F_77 ( V_8 -> V_9 ) ;
}
int F_78 ( struct V_225 * V_226 , int V_88 ,
unsigned int V_228 , unsigned int V_229 )
{
int V_31 = 0 ;
if ( V_226 -> V_276 == V_88 && V_226 -> V_277 == V_228 )
return 0 ;
if ( V_226 -> V_231 && V_228 > 0 ) {
V_31 = F_61 ( V_226 , V_228 , V_226 -> V_231 ) ;
if ( V_31 != 0 )
return V_31 ;
}
V_226 -> V_276 = V_88 ;
V_226 -> V_277 = V_228 ;
if ( V_226 -> V_231 && V_228 > 0 ) {
V_31 = F_70 ( V_226 ) ;
}
return V_31 ;
}
int F_79 ( struct V_225 * V_226 , int V_88 ,
unsigned int V_228 , unsigned int V_229 )
{
int V_31 = 0 ;
if ( V_226 -> V_278 == V_88 &&
V_226 -> V_279 == V_228 && V_226 -> V_231 == V_229 )
return 0 ;
if ( V_229 ) {
if ( V_226 -> V_276 >= 0 ) {
V_31 = F_61 ( V_226 , V_226 -> V_277 , V_229 ) ;
if ( V_31 != 0 )
return V_31 ;
}
V_31 = F_61 ( V_226 , V_228 , V_229 ) ;
if ( V_31 != 0 )
return V_31 ;
}
V_226 -> V_278 = V_88 ;
V_226 -> V_279 = V_228 ;
V_226 -> V_231 = V_229 ;
if ( V_229 )
V_31 = F_70 ( V_226 ) ;
else
F_75 ( V_226 ) ;
return V_31 ;
}
int F_80 ( struct V_8 * V_8 , int V_148 , int V_112 , int V_283 ,
int V_284 , struct V_225 * V_226 )
{
int V_31 ;
unsigned int V_14 ;
F_81 ( & V_226 -> V_227 ) ;
V_226 -> V_148 = V_148 ;
V_226 -> V_112 = V_112 ;
V_226 -> V_8 = V_8 ;
V_226 -> V_278 = V_285 ;
F_10 ( V_8 -> V_19 , V_286 , & V_14 ) ;
switch ( V_14 & V_287 ) {
case V_288 :
case V_289 :
V_226 -> V_276 = V_14 & V_287 ;
break;
default:
V_226 -> V_276 = V_285 ;
}
V_226 -> V_277 = 32768 ;
snprintf ( V_226 -> V_290 , sizeof( V_226 -> V_290 ) , L_48 , V_148 ) ;
snprintf ( V_226 -> V_291 , sizeof( V_226 -> V_291 ) ,
L_49 , V_148 ) ;
V_31 = F_16 ( V_8 , V_284 , V_226 -> V_291 ,
F_58 , V_226 ) ;
if ( V_31 != 0 ) {
F_11 ( V_8 -> V_9 , L_50 ,
V_148 , V_31 ) ;
}
F_13 ( V_8 -> V_19 , V_226 -> V_112 + 1 ,
V_275 , 0 ) ;
return 0 ;
}
int F_82 ( struct V_6 * V_7 , int V_292 , bool V_293 )
{
unsigned int V_56 , V_14 ;
if ( V_292 < 1 || V_292 > 6 )
return - V_68 ;
V_56 = V_294 + ( V_292 - 1 ) * 8 ;
if ( V_293 )
V_14 = V_295 ;
else
V_14 = 0 ;
return F_24 ( V_7 , V_56 , V_295 , V_14 ) ;
}
