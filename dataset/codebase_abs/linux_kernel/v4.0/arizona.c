static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
int V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 -> V_8 ) ;
struct V_9 * V_9 = F_3 ( V_7 -> V_10 -> V_11 ) ;
struct V_12 * V_13 = F_4 ( V_7 ) ;
bool V_14 = false ;
int V_15 ;
switch ( V_9 -> type ) {
case V_16 :
switch ( V_9 -> V_17 ) {
case 0 :
break;
default:
V_14 = true ;
break;
}
default:
break;
}
switch ( V_5 ) {
case V_18 :
if ( ! V_13 -> V_19 && V_14 ) {
F_5 ( V_9 -> V_20 , 0x4f5 , 0x25a ) ;
V_13 -> V_21 = true ;
}
break;
case V_22 :
V_15 = F_6 ( V_7 , V_23 ) ;
if ( V_15 & V_24 ) {
F_7 ( V_9 -> V_10 ,
L_1 ) ;
return - V_25 ;
}
F_8 ( V_9 -> V_20 ,
V_26 ,
1 << V_2 -> V_27 , 1 << V_2 -> V_27 ) ;
if ( V_13 -> V_21 ) {
F_9 ( 75 ) ;
F_5 ( V_9 -> V_20 , 0x4f5 , 0xda ) ;
V_13 -> V_21 = false ;
V_13 -> V_19 ++ ;
}
break;
case V_28 :
if ( V_14 ) {
V_13 -> V_19 -- ;
if ( ! V_13 -> V_19 )
F_5 ( V_9 -> V_20 ,
0x4f5 , 0x25a ) ;
}
F_8 ( V_9 -> V_20 ,
V_26 ,
1 << V_2 -> V_27 , 0 ) ;
break;
case V_29 :
if ( V_14 ) {
if ( ! V_13 -> V_19 )
F_5 ( V_9 -> V_20 ,
0x4f5 , 0x0da ) ;
}
break;
}
return 0 ;
}
static T_1 F_10 ( int V_30 , void * V_31 )
{
struct V_9 * V_9 = V_31 ;
unsigned int V_15 ;
int V_32 ;
V_32 = F_11 ( V_9 -> V_20 , V_23 ,
& V_15 ) ;
if ( V_32 != 0 ) {
F_12 ( V_9 -> V_10 , L_2 ,
V_32 ) ;
} else if ( V_15 & V_33 ) {
F_7 ( V_9 -> V_10 , L_3 ) ;
}
return V_34 ;
}
static T_1 F_13 ( int V_30 , void * V_31 )
{
struct V_9 * V_9 = V_31 ;
unsigned int V_15 ;
int V_32 ;
V_32 = F_11 ( V_9 -> V_20 , V_23 ,
& V_15 ) ;
if ( V_32 != 0 ) {
F_12 ( V_9 -> V_10 , L_2 ,
V_32 ) ;
} else if ( V_15 & V_24 ) {
F_7 ( V_9 -> V_10 , L_4 ) ;
V_32 = F_14 ( V_9 -> V_20 ,
V_26 ,
V_35 |
V_36 , 0 ) ;
if ( V_32 != 0 )
F_7 ( V_9 -> V_10 ,
L_5 ,
V_32 ) ;
}
return V_34 ;
}
int F_15 ( struct V_6 * V_7 )
{
struct V_12 * V_13 = F_4 ( V_7 ) ;
struct V_9 * V_9 = V_13 -> V_9 ;
int V_32 ;
V_32 = F_16 ( & V_7 -> V_8 , & V_37 , 1 ) ;
if ( V_32 != 0 )
return V_32 ;
switch ( V_9 -> type ) {
case V_38 :
break;
default:
V_32 = F_16 ( & V_7 -> V_8 ,
& V_39 , 1 ) ;
if ( V_32 != 0 )
return V_32 ;
break;
}
V_32 = F_17 ( V_9 , V_40 ,
L_6 , F_10 ,
V_9 ) ;
if ( V_32 != 0 )
F_12 ( V_9 -> V_10 ,
L_7 ,
V_32 ) ;
V_32 = F_17 ( V_9 , V_41 ,
L_8 , F_13 ,
V_9 ) ;
if ( V_32 != 0 )
F_12 ( V_9 -> V_10 ,
L_9 ,
V_32 ) ;
return 0 ;
}
int F_18 ( struct V_6 * V_7 )
{
struct V_12 * V_13 = F_4 ( V_7 ) ;
struct V_9 * V_9 = V_13 -> V_9 ;
int V_42 ;
for ( V_42 = 0 ; V_42 < V_43 ; ++ V_42 ) {
if ( V_9 -> V_44 . V_45 [ V_42 ] )
F_19 ( & V_7 -> V_8 ,
& V_46 [ V_42 ] , 1 ) ;
}
return 0 ;
}
int F_20 ( struct V_6 * V_7 )
{
struct V_12 * V_13 = F_4 ( V_7 ) ;
struct V_9 * V_9 = V_13 -> V_9 ;
int V_42 ;
switch ( V_9 -> type ) {
case V_47 :
F_21 ( & V_7 -> V_8 , L_10 ) ;
break;
default:
break;
}
F_21 ( & V_7 -> V_8 , L_11 ) ;
for ( V_42 = 0 ; V_42 < F_22 ( V_9 -> V_44 . V_48 ) ; V_42 ++ ) {
switch ( V_9 -> V_44 . V_48 [ V_42 ] & V_49 ) {
case V_50 :
F_23 ( & V_7 -> V_8 ,
L_11 ) ;
break;
case V_51 :
F_23 ( & V_7 -> V_8 ,
L_10 ) ;
break;
default:
break;
}
}
return 0 ;
}
static void F_24 ( struct V_6 * V_7 , int V_52 )
{
struct V_12 * V_13 = F_4 ( V_7 ) ;
unsigned int V_15 ;
int V_42 ;
if ( V_52 )
V_15 = V_53 ;
else
V_15 = 0 ;
for ( V_42 = 0 ; V_42 < V_13 -> V_54 ; V_42 ++ )
F_25 ( V_7 ,
V_55 + ( V_42 * 4 ) ,
V_53 , V_15 ) ;
}
int F_26 ( struct V_1 * V_2 , struct V_3 * V_4 ,
int V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 -> V_8 ) ;
struct V_12 * V_13 = F_4 ( V_7 ) ;
unsigned int V_56 ;
if ( V_2 -> V_27 % 2 )
V_56 = V_55 + ( ( V_2 -> V_27 / 2 ) * 8 ) ;
else
V_56 = V_57 + ( ( V_2 -> V_27 / 2 ) * 8 ) ;
switch ( V_5 ) {
case V_18 :
V_13 -> V_58 ++ ;
break;
case V_22 :
F_25 ( V_7 , V_56 , V_59 , 0 ) ;
V_13 -> V_58 -- ;
if ( V_13 -> V_58 == 0 ) {
F_9 ( 1 ) ;
F_24 ( V_7 , 1 ) ;
}
break;
case V_28 :
F_25 ( V_7 , V_56 ,
V_59 | V_53 ,
V_59 | V_53 ) ;
break;
case V_29 :
V_56 = F_6 ( V_7 , V_60 ) ;
if ( V_56 == 0 )
F_24 ( V_7 , 0 ) ;
}
return 0 ;
}
int F_27 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
int V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 -> V_8 ) ;
struct V_12 * V_13 = F_4 ( V_7 ) ;
switch ( V_5 ) {
case V_18 :
switch ( V_2 -> V_27 ) {
case V_61 :
case V_62 :
case V_63 :
case V_64 :
case V_65 :
case V_66 :
V_13 -> V_67 ++ ;
V_13 -> V_68 += 17 ;
break;
default:
break;
}
break;
case V_22 :
switch ( V_2 -> V_27 ) {
case V_61 :
case V_62 :
case V_63 :
case V_64 :
case V_65 :
case V_66 :
V_13 -> V_67 -- ;
if ( ! V_13 -> V_67 ) {
F_9 ( V_13 -> V_68 ) ;
V_13 -> V_68 = 0 ;
}
break;
default:
break;
}
break;
case V_28 :
switch ( V_2 -> V_27 ) {
case V_61 :
case V_62 :
case V_63 :
case V_64 :
case V_65 :
case V_66 :
V_13 -> V_69 ++ ;
V_13 -> V_70 ++ ;
break;
default:
break;
}
break;
case V_29 :
switch ( V_2 -> V_27 ) {
case V_61 :
case V_62 :
case V_63 :
case V_64 :
case V_65 :
case V_66 :
V_13 -> V_69 -- ;
if ( ! V_13 -> V_69 ) {
F_9 ( V_13 -> V_70 ) ;
V_13 -> V_70 = 0 ;
}
break;
default:
break;
}
break;
}
return 0 ;
}
int F_28 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
int V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 -> V_8 ) ;
struct V_12 * V_13 = F_4 ( V_7 ) ;
struct V_9 * V_9 = V_13 -> V_9 ;
unsigned int V_71 = 1 << V_2 -> V_27 ;
unsigned int V_15 ;
switch ( V_5 ) {
case V_22 :
V_15 = V_71 ;
break;
case V_28 :
V_15 = 0 ;
break;
case V_18 :
case V_29 :
return F_27 ( V_2 , V_4 , V_5 ) ;
default:
return - V_72 ;
}
V_13 -> V_9 -> V_73 &= ~ V_71 ;
V_13 -> V_9 -> V_73 |= V_15 ;
if ( V_13 -> V_9 -> V_74 )
V_15 = 0 ;
F_8 ( V_9 -> V_20 , V_26 ,
V_71 , V_15 ) ;
return F_27 ( V_2 , V_4 , V_5 ) ;
}
static int F_29 ( struct V_6 * V_7 , unsigned int V_75 ,
unsigned int V_76 )
{
struct V_12 * V_13 = F_4 ( V_7 ) ;
unsigned int V_56 ;
unsigned int * V_77 ;
int V_78 , div , V_79 ;
switch ( V_75 ) {
case V_80 :
V_56 = V_81 ;
V_79 = V_13 -> V_82 ;
break;
case V_83 :
V_56 = V_84 ;
V_79 = V_13 -> V_85 ;
break;
default:
return - V_72 ;
}
if ( V_79 % 8000 )
V_77 = V_86 ;
else
V_77 = V_87 ;
for ( V_78 = 0 ; V_78 < F_22 ( V_87 ) &&
V_77 [ V_78 ] <= V_79 ; V_78 ++ ) {
div = 1 ;
while ( V_77 [ V_78 ] / div >= V_76 && div < 32 ) {
if ( V_77 [ V_78 ] / div == V_76 ) {
F_30 ( V_7 -> V_10 , L_12 ,
V_76 ) ;
F_25 ( V_7 , V_56 ,
V_88 |
V_89 ,
( div <<
V_90 ) |
V_78 ) ;
return 0 ;
}
div ++ ;
}
}
F_12 ( V_7 -> V_10 , L_13 , V_76 ) ;
return - V_72 ;
}
int F_31 ( struct V_6 * V_7 , int V_91 ,
int V_92 , unsigned int V_76 , int V_93 )
{
struct V_12 * V_13 = F_4 ( V_7 ) ;
struct V_9 * V_9 = V_13 -> V_9 ;
char * V_94 ;
unsigned int V_56 ;
unsigned int V_71 = V_95 | V_96 ;
unsigned int V_15 = V_92 << V_97 ;
unsigned int * V_75 ;
switch ( V_91 ) {
case V_98 :
V_94 = L_14 ;
V_56 = V_99 ;
V_75 = & V_13 -> V_82 ;
V_71 |= V_100 ;
break;
case V_101 :
V_94 = L_15 ;
V_56 = V_102 ;
V_75 = & V_13 -> V_85 ;
break;
case V_80 :
case V_83 :
return F_29 ( V_7 , V_91 , V_76 ) ;
default:
return - V_72 ;
}
switch ( V_76 ) {
case 5644800 :
case 6144000 :
break;
case 11289600 :
case 12288000 :
V_15 |= V_103 << V_104 ;
break;
case 22579200 :
case 24576000 :
V_15 |= V_105 << V_104 ;
break;
case 45158400 :
case 49152000 :
V_15 |= V_106 << V_104 ;
break;
case 67737600 :
case 73728000 :
V_15 |= V_107 << V_104 ;
break;
case 90316800 :
case 98304000 :
V_15 |= V_108 << V_104 ;
break;
case 135475200 :
case 147456000 :
V_15 |= V_109 << V_104 ;
break;
case 0 :
F_30 ( V_9 -> V_10 , L_16 , V_94 ) ;
* V_75 = V_76 ;
return 0 ;
default:
return - V_72 ;
}
* V_75 = V_76 ;
if ( V_76 % 6144000 )
V_15 |= V_100 ;
F_30 ( V_9 -> V_10 , L_17 , V_94 , V_76 ) ;
return F_14 ( V_9 -> V_20 , V_56 , V_71 , V_15 ) ;
}
static int F_32 ( struct V_110 * V_111 , unsigned int V_112 )
{
struct V_6 * V_7 = V_111 -> V_7 ;
struct V_12 * V_13 = F_4 ( V_7 ) ;
struct V_9 * V_9 = V_13 -> V_9 ;
int V_113 , V_114 , V_115 , V_116 ;
V_116 = V_111 -> V_117 -> V_116 ;
V_113 = 0 ;
V_114 = 0 ;
switch ( V_112 & V_118 ) {
case V_119 :
V_115 = V_120 ;
break;
case V_121 :
if ( ( V_112 & V_122 )
!= V_123 ) {
F_33 ( V_111 , L_18 ) ;
return - V_72 ;
}
V_115 = V_124 ;
break;
case V_125 :
V_115 = V_126 ;
break;
case V_127 :
if ( ( V_112 & V_122 )
!= V_123 ) {
F_33 ( V_111 , L_19 ) ;
return - V_72 ;
}
V_115 = V_128 ;
break;
default:
F_33 ( V_111 , L_20 ,
V_112 & V_118 ) ;
return - V_72 ;
}
switch ( V_112 & V_122 ) {
case V_129 :
break;
case V_130 :
V_113 |= V_131 ;
break;
case V_132 :
V_114 |= V_133 ;
break;
case V_123 :
V_114 |= V_133 ;
V_113 |= V_131 ;
break;
default:
F_33 ( V_111 , L_21 ,
V_112 & V_122 ) ;
return - V_72 ;
}
switch ( V_112 & V_134 ) {
case V_135 :
break;
case V_136 :
V_114 |= V_137 ;
V_113 |= V_138 ;
break;
case V_139 :
V_114 |= V_137 ;
break;
case V_140 :
V_113 |= V_138 ;
break;
default:
return - V_72 ;
}
F_8 ( V_9 -> V_20 , V_116 + V_141 ,
V_137 |
V_133 ,
V_114 ) ;
F_8 ( V_9 -> V_20 , V_116 + V_142 ,
V_138 |
V_131 , V_113 ) ;
F_8 ( V_9 -> V_20 ,
V_116 + V_143 ,
V_144 |
V_145 , V_113 ) ;
F_14 ( V_9 -> V_20 , V_116 + V_146 ,
V_147 , V_115 ) ;
return 0 ;
}
static int F_34 ( struct V_148 * V_149 ,
struct V_110 * V_111 )
{
struct V_6 * V_7 = V_111 -> V_7 ;
struct V_12 * V_13 = F_4 ( V_7 ) ;
struct V_150 * V_151 = & V_13 -> V_111 [ V_111 -> V_152 - 1 ] ;
const struct V_153 * V_154 ;
unsigned int V_155 ;
switch ( V_151 -> V_75 ) {
case V_98 :
V_155 = V_13 -> V_82 ;
break;
case V_101 :
V_155 = V_13 -> V_85 ;
break;
default:
return 0 ;
}
if ( V_155 == 0 )
return 0 ;
if ( V_155 % 8000 )
V_154 = & V_156 ;
else
V_154 = & V_157 ;
return V_153 ( V_149 -> V_158 , 0 ,
V_159 ,
V_154 ) ;
}
static void F_35 ( struct V_6 * V_7 ,
unsigned int V_160 )
{
struct V_12 * V_13 = F_4 ( V_7 ) ;
struct V_9 * V_9 = V_13 -> V_9 ;
struct V_161 V_162 [] = {
{ 0x80 , 0x3 } ,
{ V_163 , 0 } ,
{ V_164 , 0 } ,
{ 0x80 , 0x0 } ,
} ;
F_36 ( & V_9 -> V_165 ) ;
V_162 [ 1 ] . V_166 = V_9 -> V_167 ;
if ( V_160 >= 176400 )
V_162 [ 2 ] . V_166 = V_9 -> V_168 ;
F_37 ( & V_9 -> V_165 ) ;
F_38 ( V_9 -> V_20 ,
V_162 ,
F_22 ( V_162 ) ) ;
}
static int F_39 ( struct V_148 * V_149 ,
struct V_169 * V_170 ,
struct V_110 * V_111 )
{
struct V_6 * V_7 = V_111 -> V_7 ;
struct V_12 * V_13 = F_4 ( V_7 ) ;
struct V_150 * V_151 = & V_13 -> V_111 [ V_111 -> V_152 - 1 ] ;
int V_116 = V_111 -> V_117 -> V_116 ;
int V_42 , V_171 ;
for ( V_42 = 0 ; V_42 < F_22 ( V_172 ) ; V_42 ++ )
if ( V_172 [ V_42 ] == F_40 ( V_170 ) )
break;
if ( V_42 == F_22 ( V_172 ) ) {
F_33 ( V_111 , L_22 ,
F_40 ( V_170 ) ) ;
return - V_72 ;
}
V_171 = V_42 ;
switch ( V_151 -> V_75 ) {
case V_98 :
switch ( V_13 -> V_9 -> type ) {
case V_16 :
F_35 ( V_7 ,
F_40 ( V_170 ) ) ;
break;
default:
break;
}
F_25 ( V_7 , V_173 ,
V_174 , V_171 ) ;
if ( V_116 )
F_25 ( V_7 , V_116 + V_175 ,
V_176 , 0 ) ;
break;
case V_101 :
F_25 ( V_7 , V_177 ,
V_178 , V_171 ) ;
if ( V_116 )
F_25 ( V_7 , V_116 + V_175 ,
V_176 ,
8 << V_179 ) ;
break;
default:
F_33 ( V_111 , L_23 , V_151 -> V_75 ) ;
return - V_72 ;
}
return 0 ;
}
static bool F_41 ( struct V_6 * V_7 ,
int V_116 , int V_114 , int V_113 , int V_180 )
{
int V_15 ;
V_15 = F_6 ( V_7 , V_116 + V_141 ) ;
if ( V_114 != ( V_15 & V_181 ) )
return true ;
V_15 = F_6 ( V_7 , V_116 + V_182 ) ;
if ( V_113 != ( V_15 & V_183 ) )
return true ;
V_15 = F_6 ( V_7 , V_116 + V_184 ) ;
if ( V_180 != ( V_15 & ( V_185 |
V_186 ) ) )
return true ;
return false ;
}
static int F_42 ( struct V_148 * V_149 ,
struct V_169 * V_170 ,
struct V_110 * V_111 )
{
struct V_6 * V_7 = V_111 -> V_7 ;
struct V_12 * V_13 = F_4 ( V_7 ) ;
struct V_9 * V_9 = V_13 -> V_9 ;
int V_116 = V_111 -> V_117 -> V_116 ;
const int * V_77 ;
int V_42 , V_32 , V_15 ;
int V_187 = F_43 ( V_170 ) ;
int V_188 = V_9 -> V_44 . V_189 [ V_111 -> V_152 - 1 ] ;
int V_190 = V_9 -> V_190 [ V_111 -> V_152 - 1 ] ;
int V_191 = V_9 -> V_191 [ V_111 -> V_152 - 1 ] ;
int V_114 , V_113 , V_192 , V_180 , V_193 ;
bool V_194 ;
unsigned int V_195 , V_196 ;
if ( F_40 ( V_170 ) % 8000 )
V_77 = & V_197 [ 0 ] ;
else
V_77 = & V_198 [ 0 ] ;
V_192 = F_44 ( F_45 ( V_170 ) ) ;
if ( V_191 ) {
F_46 ( V_111 , L_24 ,
V_191 , V_190 ) ;
V_193 = V_191 * V_190 * F_40 ( V_170 ) ;
V_187 = V_191 ;
} else {
V_193 = F_47 ( V_170 ) ;
V_190 = V_192 ;
}
if ( V_188 && V_188 < V_187 ) {
F_46 ( V_111 , L_25 , V_188 ) ;
V_193 /= V_187 ;
V_193 *= V_188 ;
}
V_15 = F_6 ( V_7 , V_116 + V_146 ) ;
V_15 &= V_147 ;
if ( ( V_187 & 1 ) && ( V_15 == V_126 ) ) {
F_46 ( V_111 , L_26 ) ;
V_193 /= V_187 ;
V_193 *= V_187 + 1 ;
}
for ( V_42 = 0 ; V_42 < F_22 ( V_197 ) ; V_42 ++ ) {
if ( V_77 [ V_42 ] >= V_193 &&
V_77 [ V_42 ] % F_40 ( V_170 ) == 0 ) {
V_114 = V_42 ;
break;
}
}
if ( V_42 == F_22 ( V_197 ) ) {
F_33 ( V_111 , L_22 ,
F_40 ( V_170 ) ) ;
return - V_72 ;
}
V_113 = V_77 [ V_114 ] / F_40 ( V_170 ) ;
F_46 ( V_111 , L_27 ,
V_77 [ V_114 ] , V_77 [ V_114 ] / V_113 ) ;
V_180 = V_192 << V_199 | V_190 ;
V_194 = F_41 ( V_7 , V_116 , V_114 , V_113 , V_180 ) ;
if ( V_194 ) {
V_195 = F_6 ( V_7 ,
V_116 + V_200 ) ;
V_196 = F_6 ( V_7 ,
V_116 + V_201 ) ;
F_8 ( V_9 -> V_20 ,
V_116 + V_200 , 0xff , 0x0 ) ;
F_14 ( V_9 -> V_20 ,
V_116 + V_201 , 0xff , 0x0 ) ;
}
V_32 = F_39 ( V_149 , V_170 , V_111 ) ;
if ( V_32 != 0 )
goto V_202;
if ( V_194 ) {
F_8 ( V_9 -> V_20 ,
V_116 + V_141 ,
V_181 , V_114 ) ;
F_8 ( V_9 -> V_20 ,
V_116 + V_182 ,
V_183 , V_113 ) ;
F_8 ( V_9 -> V_20 ,
V_116 + V_203 ,
V_204 , V_113 ) ;
F_8 ( V_9 -> V_20 ,
V_116 + V_184 ,
V_185 |
V_186 , V_180 ) ;
F_14 ( V_9 -> V_20 ,
V_116 + V_205 ,
V_206 |
V_207 , V_180 ) ;
}
V_202:
if ( V_194 ) {
F_8 ( V_9 -> V_20 ,
V_116 + V_200 ,
0xff , V_195 ) ;
F_14 ( V_9 -> V_20 ,
V_116 + V_201 ,
0xff , V_196 ) ;
}
return V_32 ;
}
static const char * F_48 ( int V_91 )
{
switch ( V_91 ) {
case V_98 :
return L_14 ;
case V_101 :
return L_15 ;
default:
return L_28 ;
}
}
static int F_49 ( struct V_110 * V_111 ,
int V_91 , unsigned int V_76 , int V_93 )
{
struct V_6 * V_7 = V_111 -> V_7 ;
struct V_12 * V_13 = F_4 ( V_7 ) ;
struct V_150 * V_151 = & V_13 -> V_111 [ V_111 -> V_152 - 1 ] ;
struct V_208 V_209 [ 2 ] ;
switch ( V_91 ) {
case V_98 :
case V_101 :
break;
default:
return - V_72 ;
}
if ( V_91 == V_151 -> V_75 )
return 0 ;
if ( V_111 -> V_210 ) {
F_12 ( V_7 -> V_10 , L_29 ,
V_111 -> V_152 ) ;
return - V_25 ;
}
F_30 ( V_7 -> V_10 , L_30 , V_111 -> V_152 + 1 ,
F_48 ( V_91 ) ) ;
memset ( & V_209 , 0 , sizeof( V_209 ) ) ;
V_209 [ 0 ] . V_211 = V_111 -> V_117 -> V_212 . V_213 ;
V_209 [ 1 ] . V_211 = V_111 -> V_117 -> V_214 . V_213 ;
V_209 [ 0 ] . V_92 = F_48 ( V_151 -> V_75 ) ;
V_209 [ 1 ] . V_92 = F_48 ( V_151 -> V_75 ) ;
F_50 ( & V_7 -> V_8 , V_209 , F_22 ( V_209 ) ) ;
V_209 [ 0 ] . V_92 = F_48 ( V_91 ) ;
V_209 [ 1 ] . V_92 = F_48 ( V_91 ) ;
F_19 ( & V_7 -> V_8 , V_209 , F_22 ( V_209 ) ) ;
V_151 -> V_75 = V_91 ;
return F_51 ( & V_7 -> V_8 ) ;
}
static int F_52 ( struct V_110 * V_111 , int V_215 )
{
struct V_6 * V_7 = V_111 -> V_7 ;
int V_116 = V_111 -> V_117 -> V_116 ;
unsigned int V_56 ;
if ( V_215 )
V_56 = V_216 ;
else
V_56 = 0 ;
return F_25 ( V_7 , V_116 + V_175 ,
V_216 , V_56 ) ;
}
static void F_53 ( struct V_110 * V_111 ,
unsigned int V_116 ,
int V_187 , unsigned int V_71 )
{
struct V_6 * V_7 = V_111 -> V_7 ;
struct V_12 * V_13 = F_4 ( V_7 ) ;
struct V_9 * V_9 = V_13 -> V_9 ;
int V_217 , V_42 ;
for ( V_42 = 0 ; V_42 < V_187 ; ++ V_42 ) {
V_217 = F_54 ( V_71 ) - 1 ;
if ( V_217 < 0 )
return;
F_55 ( V_9 -> V_20 , V_116 + V_42 , V_217 ) ;
V_71 &= ~ ( 1 << V_217 ) ;
}
if ( V_71 )
F_56 ( V_111 , L_31 ) ;
}
static int F_57 ( struct V_110 * V_111 , unsigned int V_218 ,
unsigned int V_219 , int V_220 , int V_221 )
{
struct V_6 * V_7 = V_111 -> V_7 ;
struct V_12 * V_13 = F_4 ( V_7 ) ;
struct V_9 * V_9 = V_13 -> V_9 ;
int V_116 = V_111 -> V_117 -> V_116 ;
int V_222 = V_111 -> V_117 -> V_214 . V_223 ;
int V_224 = V_111 -> V_117 -> V_212 . V_223 ;
if ( V_111 -> V_152 > V_225 )
return - V_226 ;
if ( V_220 == 0 ) {
V_218 = ( 1 << V_224 ) - 1 ;
V_219 = ( 1 << V_222 ) - 1 ;
}
F_53 ( V_111 , V_116 + V_227 ,
V_224 , V_218 ) ;
F_53 ( V_111 , V_116 + V_228 ,
V_222 , V_219 ) ;
V_9 -> V_190 [ V_111 -> V_152 - 1 ] = V_221 ;
V_9 -> V_191 [ V_111 -> V_152 - 1 ] = V_220 ;
return 0 ;
}
int F_58 ( struct V_12 * V_13 , int V_152 )
{
struct V_150 * V_151 = & V_13 -> V_111 [ V_152 ] ;
V_151 -> V_75 = V_98 ;
return 0 ;
}
static T_1 F_59 ( int V_30 , void * V_31 )
{
struct V_229 * V_230 = V_31 ;
F_60 ( V_230 , L_32 ) ;
F_61 ( & V_230 -> V_231 ) ;
return V_34 ;
}
static int F_62 ( struct V_229 * V_230 ,
unsigned int V_232 ,
unsigned int V_233 )
{
unsigned int V_234 ;
if ( V_230 -> V_235 && V_233 != V_230 -> V_235 ) {
F_63 ( V_230 ,
L_33 ) ;
return - V_72 ;
}
if ( V_232 / V_236 > V_237 ) {
F_63 ( V_230 ,
L_34 ,
V_232 ) ;
return - V_72 ;
}
V_234 = V_238 * V_230 -> V_239 ;
if ( V_233 * V_240 < V_234 ) {
F_63 ( V_230 , L_35 ,
V_233 ) ;
return - V_72 ;
}
return 0 ;
}
static int F_64 ( unsigned int V_232 , int * V_241 )
{
int V_42 ;
for ( V_42 = 0 ; V_42 < F_22 ( V_242 ) ; V_42 ++ ) {
if ( V_242 [ V_42 ] . V_243 <= V_232 && V_232 <= V_242 [ V_42 ] . V_244 ) {
if ( V_241 )
* V_241 = V_242 [ V_42 ] . V_241 ;
return V_242 [ V_42 ] . V_245 ;
}
}
return - V_72 ;
}
static int F_65 ( struct V_229 * V_230 ,
struct V_246 * V_247 ,
unsigned int V_248 ,
unsigned int V_232 , bool V_249 )
{
int V_250 , V_245 ;
int V_251 , div ;
div = 1 ;
V_247 -> V_251 = 0 ;
while ( V_232 > V_237 ) {
div *= 2 ;
V_232 /= 2 ;
V_247 -> V_251 ++ ;
if ( div > V_236 )
return - V_72 ;
}
V_250 = F_64 ( V_232 , & V_247 -> V_241 ) ;
if ( V_250 < 0 ) {
F_63 ( V_230 , L_36 ,
V_232 ) ;
return V_250 ;
}
switch ( V_230 -> V_9 -> type ) {
case V_47 :
if ( V_230 -> V_9 -> V_17 < 3 || V_249 )
return V_250 ;
break;
default:
return V_250 ;
}
V_247 -> V_241 = V_250 - 1 ;
V_251 = V_247 -> V_251 ;
while ( div <= V_236 ) {
for ( V_245 = V_250 ; V_245 <= V_252 ;
V_245 ++ ) {
if ( ( V_253 / 2 ) /
( V_230 -> V_239 * V_245 ) < V_232 )
break;
if ( V_248 % ( V_245 * V_232 ) ) {
V_247 -> V_251 = V_251 ;
V_247 -> V_241 = V_245 - 1 ;
return V_245 ;
}
}
for ( V_245 = V_250 - 1 ; V_245 > 0 ; V_245 -- ) {
if ( V_248 % ( V_245 * V_232 ) ) {
V_247 -> V_251 = V_251 ;
V_247 -> V_241 = V_245 - 1 ;
return V_245 ;
}
}
div *= 2 ;
V_232 /= 2 ;
V_251 ++ ;
V_250 = F_64 ( V_232 , NULL ) ;
}
F_66 ( V_230 , L_37 ) ;
return V_247 -> V_241 + 1 ;
}
static int F_67 ( struct V_229 * V_230 ,
struct V_246 * V_247 ,
unsigned int V_232 , bool V_249 )
{
unsigned int V_248 , div , V_254 ;
int V_42 , V_245 ;
F_60 ( V_230 , L_38 , V_232 , V_230 -> V_235 ) ;
div = V_255 ;
while ( V_230 -> V_235 * div < V_238 * V_230 -> V_239 ) {
div ++ ;
if ( div > V_240 )
return - V_72 ;
}
V_248 = V_230 -> V_235 * div / V_230 -> V_239 ;
V_247 -> V_256 = div ;
F_60 ( V_230 , L_39 , V_248 ) ;
V_245 = F_65 ( V_230 , V_247 , V_248 , V_232 , V_249 ) ;
if ( V_245 < 0 )
return V_245 ;
V_232 = V_232 / ( 1 << V_247 -> V_251 ) ;
V_247 -> V_257 = V_248 / ( V_245 * V_232 ) ;
if ( V_248 % ( V_245 * V_232 ) ) {
V_254 = F_68 ( V_248 , V_245 * V_232 ) ;
F_60 ( V_230 , L_40 , V_254 ) ;
V_247 -> V_258 = ( V_248 - ( V_247 -> V_257 * V_245 * V_232 ) )
/ V_254 ;
V_247 -> V_259 = ( V_245 * V_232 ) / V_254 ;
} else {
V_247 -> V_258 = 0 ;
V_247 -> V_259 = 0 ;
}
while ( V_247 -> V_259 >= ( 1 << 16 ) ) {
V_247 -> V_258 >>= 1 ;
V_247 -> V_259 >>= 1 ;
}
for ( V_42 = 0 ; V_42 < F_22 ( V_260 ) ; V_42 ++ ) {
if ( V_260 [ V_42 ] . V_243 <= V_232 && V_232 <= V_260 [ V_42 ] . V_244 ) {
V_247 -> V_261 = V_260 [ V_42 ] . V_261 ;
break;
}
}
if ( V_42 == F_22 ( V_260 ) ) {
F_63 ( V_230 , L_41 ,
V_232 ) ;
return - V_72 ;
}
F_60 ( V_230 , L_42 ,
V_247 -> V_257 , V_247 -> V_258 , V_247 -> V_259 ) ;
F_60 ( V_230 , L_43 ,
V_247 -> V_241 , V_247 -> V_241 , V_247 -> V_256 , V_247 -> V_251 ) ;
F_60 ( V_230 , L_44 , V_247 -> V_261 ) ;
return 0 ;
}
static void F_69 ( struct V_9 * V_9 , unsigned int V_116 ,
struct V_246 * V_247 , int V_92 ,
bool V_249 )
{
F_8 ( V_9 -> V_20 , V_116 + 3 ,
V_262 , V_247 -> V_258 ) ;
F_8 ( V_9 -> V_20 , V_116 + 4 ,
V_263 , V_247 -> V_259 ) ;
F_8 ( V_9 -> V_20 , V_116 + 5 ,
V_264 ,
V_247 -> V_241 << V_265 ) ;
F_8 ( V_9 -> V_20 , V_116 + 6 ,
V_266 |
V_267 ,
V_247 -> V_251 << V_268 |
V_92 << V_269 ) ;
if ( V_249 ) {
F_14 ( V_9 -> V_20 , V_116 + 0x7 ,
V_270 ,
V_247 -> V_261 << V_271 ) ;
} else {
F_14 ( V_9 -> V_20 , V_116 + 0x5 ,
V_272 ,
V_247 -> V_256 << V_273 ) ;
F_14 ( V_9 -> V_20 , V_116 + 0x9 ,
V_270 ,
V_247 -> V_261 << V_271 ) ;
}
F_8 ( V_9 -> V_20 , V_116 + 2 ,
V_274 | V_275 ,
V_274 | V_247 -> V_257 ) ;
}
static int F_70 ( struct V_229 * V_230 )
{
struct V_9 * V_9 = V_230 -> V_9 ;
unsigned int V_56 ;
int V_32 ;
V_32 = F_11 ( V_9 -> V_20 , V_230 -> V_116 + 1 , & V_56 ) ;
if ( V_32 != 0 ) {
F_63 ( V_230 , L_45 ,
V_32 ) ;
return V_32 ;
}
return V_56 & V_276 ;
}
static int F_71 ( struct V_229 * V_230 )
{
struct V_9 * V_9 = V_230 -> V_9 ;
int V_32 ;
bool V_277 = false ;
int V_278 = F_70 ( V_230 ) ;
struct V_246 V_247 ;
if ( V_278 < 0 )
return V_278 ;
if ( V_278 ) {
F_8 ( V_230 -> V_9 -> V_20 , V_230 -> V_116 + 0x7 ,
V_270 , 0 ) ;
F_8 ( V_230 -> V_9 -> V_20 , V_230 -> V_116 + 1 ,
V_279 ,
V_279 ) ;
}
if ( V_230 -> V_280 >= 0 && V_230 -> V_281 &&
V_230 -> V_280 != V_230 -> V_282 ) {
F_67 ( V_230 , & V_247 , V_230 -> V_281 , false ) ;
F_69 ( V_9 , V_230 -> V_116 , & V_247 , V_230 -> V_280 ,
false ) ;
if ( V_230 -> V_282 >= 0 ) {
F_67 ( V_230 , & V_247 , V_230 -> V_283 , true ) ;
F_69 ( V_9 , V_230 -> V_116 + 0x10 , & V_247 ,
V_230 -> V_282 , true ) ;
V_277 = true ;
}
} else if ( V_230 -> V_282 >= 0 ) {
F_67 ( V_230 , & V_247 , V_230 -> V_283 , false ) ;
F_69 ( V_9 , V_230 -> V_116 , & V_247 ,
V_230 -> V_282 , false ) ;
F_8 ( V_9 -> V_20 , V_230 -> V_116 + 0x11 ,
V_284 , 0 ) ;
} else {
F_63 ( V_230 , L_46 ) ;
return - V_72 ;
}
if ( V_277 && V_230 -> V_283 > 100000 )
F_8 ( V_9 -> V_20 , V_230 -> V_116 + 0x17 ,
V_285 , 0 ) ;
else
F_8 ( V_9 -> V_20 , V_230 -> V_116 + 0x17 ,
V_285 ,
V_285 ) ;
if ( ! V_278 )
F_72 ( V_9 -> V_10 ) ;
F_73 ( & V_230 -> V_231 ) ;
F_8 ( V_9 -> V_20 , V_230 -> V_116 + 1 ,
V_276 , V_276 ) ;
if ( V_277 )
F_8 ( V_9 -> V_20 , V_230 -> V_116 + 0x11 ,
V_284 ,
V_284 ) ;
if ( V_278 )
F_8 ( V_9 -> V_20 , V_230 -> V_116 + 1 ,
V_279 , 0 ) ;
V_32 = F_74 ( & V_230 -> V_231 ,
F_75 ( 250 ) ) ;
if ( V_32 == 0 )
F_66 ( V_230 , L_47 ) ;
return 0 ;
}
static void F_76 ( struct V_229 * V_230 )
{
struct V_9 * V_9 = V_230 -> V_9 ;
bool V_286 ;
F_8 ( V_9 -> V_20 , V_230 -> V_116 + 1 ,
V_279 , V_279 ) ;
F_77 ( V_9 -> V_20 , V_230 -> V_116 + 1 ,
V_276 , 0 , & V_286 ) ;
F_14 ( V_9 -> V_20 , V_230 -> V_116 + 0x11 ,
V_284 , 0 ) ;
F_8 ( V_9 -> V_20 , V_230 -> V_116 + 1 ,
V_279 , 0 ) ;
if ( V_286 )
F_78 ( V_9 -> V_10 ) ;
}
int F_79 ( struct V_229 * V_230 , int V_92 ,
unsigned int V_232 , unsigned int V_233 )
{
int V_32 = 0 ;
if ( V_230 -> V_280 == V_92 && V_230 -> V_281 == V_232 )
return 0 ;
if ( V_230 -> V_235 && V_232 > 0 ) {
V_32 = F_62 ( V_230 , V_232 , V_230 -> V_235 ) ;
if ( V_32 != 0 )
return V_32 ;
}
V_230 -> V_280 = V_92 ;
V_230 -> V_281 = V_232 ;
if ( V_230 -> V_235 && V_232 > 0 ) {
V_32 = F_71 ( V_230 ) ;
}
return V_32 ;
}
int F_80 ( struct V_229 * V_230 , int V_92 ,
unsigned int V_232 , unsigned int V_233 )
{
int V_32 = 0 ;
if ( V_230 -> V_282 == V_92 &&
V_230 -> V_283 == V_232 && V_230 -> V_235 == V_233 )
return 0 ;
if ( V_233 ) {
if ( V_230 -> V_280 >= 0 ) {
V_32 = F_62 ( V_230 , V_230 -> V_281 , V_233 ) ;
if ( V_32 != 0 )
return V_32 ;
}
V_32 = F_62 ( V_230 , V_232 , V_233 ) ;
if ( V_32 != 0 )
return V_32 ;
}
V_230 -> V_282 = V_92 ;
V_230 -> V_283 = V_232 ;
V_230 -> V_235 = V_233 ;
if ( V_233 )
V_32 = F_71 ( V_230 ) ;
else
F_76 ( V_230 ) ;
return V_32 ;
}
int F_81 ( struct V_9 * V_9 , int V_152 , int V_116 , int V_287 ,
int V_288 , struct V_229 * V_230 )
{
int V_32 ;
unsigned int V_15 ;
F_82 ( & V_230 -> V_231 ) ;
V_230 -> V_152 = V_152 ;
V_230 -> V_116 = V_116 ;
V_230 -> V_9 = V_9 ;
V_230 -> V_282 = V_289 ;
F_11 ( V_9 -> V_20 , V_290 , & V_15 ) ;
switch ( V_15 & V_291 ) {
case V_292 :
case V_293 :
V_230 -> V_280 = V_15 & V_291 ;
break;
default:
V_230 -> V_280 = V_289 ;
}
V_230 -> V_281 = 32768 ;
snprintf ( V_230 -> V_294 , sizeof( V_230 -> V_294 ) , L_48 , V_152 ) ;
snprintf ( V_230 -> V_295 , sizeof( V_230 -> V_295 ) ,
L_49 , V_152 ) ;
V_32 = F_17 ( V_9 , V_288 , V_230 -> V_295 ,
F_59 , V_230 ) ;
if ( V_32 != 0 ) {
F_12 ( V_9 -> V_10 , L_50 ,
V_152 , V_32 ) ;
}
F_14 ( V_9 -> V_20 , V_230 -> V_116 + 1 ,
V_279 , 0 ) ;
return 0 ;
}
int F_83 ( struct V_6 * V_7 , int V_296 , bool V_297 )
{
unsigned int V_56 , V_15 ;
if ( V_296 < 1 || V_296 > 6 )
return - V_72 ;
V_56 = V_298 + ( V_296 - 1 ) * 8 ;
if ( V_297 )
V_15 = V_299 ;
else
V_15 = 0 ;
return F_25 ( V_7 , V_56 , V_299 , V_15 ) ;
}
