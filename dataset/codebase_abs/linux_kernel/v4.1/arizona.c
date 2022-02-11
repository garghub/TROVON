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
case V_48 :
F_21 ( & V_7 -> V_8 , L_10 ) ;
break;
default:
break;
}
F_21 ( & V_7 -> V_8 , L_11 ) ;
for ( V_42 = 0 ; V_42 < F_22 ( V_9 -> V_44 . V_49 ) ; V_42 ++ ) {
switch ( V_9 -> V_44 . V_49 [ V_42 ] & V_50 ) {
case V_51 :
F_23 ( & V_7 -> V_8 ,
L_11 ) ;
break;
case V_52 :
F_23 ( & V_7 -> V_8 ,
L_10 ) ;
break;
default:
break;
}
}
return 0 ;
}
static void F_24 ( struct V_6 * V_7 , int V_53 )
{
struct V_12 * V_13 = F_4 ( V_7 ) ;
unsigned int V_15 ;
int V_42 ;
if ( V_53 )
V_15 = V_54 ;
else
V_15 = 0 ;
for ( V_42 = 0 ; V_42 < V_13 -> V_55 ; V_42 ++ )
F_25 ( V_7 ,
V_56 + ( V_42 * 4 ) ,
V_54 , V_15 ) ;
}
int F_26 ( struct V_1 * V_2 , struct V_3 * V_4 ,
int V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 -> V_8 ) ;
struct V_12 * V_13 = F_4 ( V_7 ) ;
unsigned int V_57 ;
if ( V_2 -> V_27 % 2 )
V_57 = V_56 + ( ( V_2 -> V_27 / 2 ) * 8 ) ;
else
V_57 = V_58 + ( ( V_2 -> V_27 / 2 ) * 8 ) ;
switch ( V_5 ) {
case V_18 :
V_13 -> V_59 ++ ;
break;
case V_22 :
F_25 ( V_7 , V_57 , V_60 , 0 ) ;
V_13 -> V_59 -- ;
if ( V_13 -> V_59 == 0 ) {
F_9 ( 1 ) ;
F_24 ( V_7 , 1 ) ;
}
break;
case V_28 :
F_25 ( V_7 , V_57 ,
V_60 | V_54 ,
V_60 | V_54 ) ;
break;
case V_29 :
V_57 = F_6 ( V_7 , V_61 ) ;
if ( V_57 == 0 )
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
case V_62 :
case V_63 :
case V_64 :
case V_65 :
case V_66 :
case V_67 :
V_13 -> V_68 ++ ;
V_13 -> V_69 += 17 ;
break;
default:
break;
}
break;
case V_22 :
switch ( V_2 -> V_27 ) {
case V_62 :
case V_63 :
case V_64 :
case V_65 :
case V_66 :
case V_67 :
V_13 -> V_68 -- ;
if ( ! V_13 -> V_68 ) {
F_9 ( V_13 -> V_69 ) ;
V_13 -> V_69 = 0 ;
}
break;
default:
break;
}
break;
case V_28 :
switch ( V_2 -> V_27 ) {
case V_62 :
case V_63 :
case V_64 :
case V_65 :
case V_66 :
case V_67 :
V_13 -> V_70 ++ ;
V_13 -> V_71 ++ ;
break;
default:
break;
}
break;
case V_29 :
switch ( V_2 -> V_27 ) {
case V_62 :
case V_63 :
case V_64 :
case V_65 :
case V_66 :
case V_67 :
V_13 -> V_70 -- ;
if ( ! V_13 -> V_70 ) {
F_9 ( V_13 -> V_71 ) ;
V_13 -> V_71 = 0 ;
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
unsigned int V_72 = 1 << V_2 -> V_27 ;
unsigned int V_15 ;
switch ( V_5 ) {
case V_22 :
V_15 = V_72 ;
break;
case V_28 :
V_15 = 0 ;
break;
case V_18 :
case V_29 :
return F_27 ( V_2 , V_4 , V_5 ) ;
default:
return - V_73 ;
}
V_13 -> V_9 -> V_74 &= ~ V_72 ;
V_13 -> V_9 -> V_74 |= V_15 ;
if ( V_13 -> V_9 -> V_75 )
V_15 = 0 ;
F_8 ( V_9 -> V_20 , V_26 ,
V_72 , V_15 ) ;
return F_27 ( V_2 , V_4 , V_5 ) ;
}
static int F_29 ( struct V_6 * V_7 , unsigned int V_76 ,
unsigned int V_77 )
{
struct V_12 * V_13 = F_4 ( V_7 ) ;
unsigned int V_57 ;
unsigned int * V_78 ;
int V_79 , div , V_80 ;
switch ( V_76 ) {
case V_81 :
V_57 = V_82 ;
V_80 = V_13 -> V_83 ;
break;
case V_84 :
V_57 = V_85 ;
V_80 = V_13 -> V_86 ;
break;
default:
return - V_73 ;
}
if ( V_80 % 8000 )
V_78 = V_87 ;
else
V_78 = V_88 ;
for ( V_79 = 0 ; V_79 < F_22 ( V_88 ) &&
V_78 [ V_79 ] <= V_80 ; V_79 ++ ) {
div = 1 ;
while ( V_78 [ V_79 ] / div >= V_77 && div < 32 ) {
if ( V_78 [ V_79 ] / div == V_77 ) {
F_30 ( V_7 -> V_10 , L_12 ,
V_77 ) ;
F_25 ( V_7 , V_57 ,
V_89 |
V_90 ,
( div <<
V_91 ) |
V_79 ) ;
return 0 ;
}
div ++ ;
}
}
F_12 ( V_7 -> V_10 , L_13 , V_77 ) ;
return - V_73 ;
}
int F_31 ( struct V_6 * V_7 , int V_92 ,
int V_93 , unsigned int V_77 , int V_94 )
{
struct V_12 * V_13 = F_4 ( V_7 ) ;
struct V_9 * V_9 = V_13 -> V_9 ;
char * V_95 ;
unsigned int V_57 ;
unsigned int V_72 = V_96 | V_97 ;
unsigned int V_15 = V_93 << V_98 ;
unsigned int * V_76 ;
switch ( V_92 ) {
case V_99 :
V_95 = L_14 ;
V_57 = V_100 ;
V_76 = & V_13 -> V_83 ;
V_72 |= V_101 ;
break;
case V_102 :
V_95 = L_15 ;
V_57 = V_103 ;
V_76 = & V_13 -> V_86 ;
break;
case V_81 :
case V_84 :
return F_29 ( V_7 , V_92 , V_77 ) ;
default:
return - V_73 ;
}
switch ( V_77 ) {
case 5644800 :
case 6144000 :
break;
case 11289600 :
case 12288000 :
V_15 |= V_104 << V_105 ;
break;
case 22579200 :
case 24576000 :
V_15 |= V_106 << V_105 ;
break;
case 45158400 :
case 49152000 :
V_15 |= V_107 << V_105 ;
break;
case 67737600 :
case 73728000 :
V_15 |= V_108 << V_105 ;
break;
case 90316800 :
case 98304000 :
V_15 |= V_109 << V_105 ;
break;
case 135475200 :
case 147456000 :
V_15 |= V_110 << V_105 ;
break;
case 0 :
F_30 ( V_9 -> V_10 , L_16 , V_95 ) ;
* V_76 = V_77 ;
return 0 ;
default:
return - V_73 ;
}
* V_76 = V_77 ;
if ( V_77 % 6144000 )
V_15 |= V_101 ;
F_30 ( V_9 -> V_10 , L_17 , V_95 , V_77 ) ;
return F_14 ( V_9 -> V_20 , V_57 , V_72 , V_15 ) ;
}
static int F_32 ( struct V_111 * V_112 , unsigned int V_113 )
{
struct V_6 * V_7 = V_112 -> V_7 ;
struct V_12 * V_13 = F_4 ( V_7 ) ;
struct V_9 * V_9 = V_13 -> V_9 ;
int V_114 , V_115 , V_116 , V_117 ;
V_117 = V_112 -> V_118 -> V_117 ;
V_114 = 0 ;
V_115 = 0 ;
switch ( V_113 & V_119 ) {
case V_120 :
V_116 = V_121 ;
break;
case V_122 :
if ( ( V_113 & V_123 )
!= V_124 ) {
F_33 ( V_112 , L_18 ) ;
return - V_73 ;
}
V_116 = V_125 ;
break;
case V_126 :
V_116 = V_127 ;
break;
case V_128 :
if ( ( V_113 & V_123 )
!= V_124 ) {
F_33 ( V_112 , L_19 ) ;
return - V_73 ;
}
V_116 = V_129 ;
break;
default:
F_33 ( V_112 , L_20 ,
V_113 & V_119 ) ;
return - V_73 ;
}
switch ( V_113 & V_123 ) {
case V_130 :
break;
case V_131 :
V_114 |= V_132 ;
break;
case V_133 :
V_115 |= V_134 ;
break;
case V_124 :
V_115 |= V_134 ;
V_114 |= V_132 ;
break;
default:
F_33 ( V_112 , L_21 ,
V_113 & V_123 ) ;
return - V_73 ;
}
switch ( V_113 & V_135 ) {
case V_136 :
break;
case V_137 :
V_115 |= V_138 ;
V_114 |= V_139 ;
break;
case V_140 :
V_115 |= V_138 ;
break;
case V_141 :
V_114 |= V_139 ;
break;
default:
return - V_73 ;
}
F_8 ( V_9 -> V_20 , V_117 + V_142 ,
V_138 |
V_134 ,
V_115 ) ;
F_8 ( V_9 -> V_20 , V_117 + V_143 ,
V_139 |
V_132 , V_114 ) ;
F_8 ( V_9 -> V_20 ,
V_117 + V_144 ,
V_145 |
V_146 , V_114 ) ;
F_14 ( V_9 -> V_20 , V_117 + V_147 ,
V_148 , V_116 ) ;
return 0 ;
}
static int F_34 ( struct V_149 * V_150 ,
struct V_111 * V_112 )
{
struct V_6 * V_7 = V_112 -> V_7 ;
struct V_12 * V_13 = F_4 ( V_7 ) ;
struct V_151 * V_152 = & V_13 -> V_112 [ V_112 -> V_153 - 1 ] ;
const struct V_154 * V_155 ;
unsigned int V_156 ;
switch ( V_152 -> V_76 ) {
case V_99 :
V_156 = V_13 -> V_83 ;
break;
case V_102 :
V_156 = V_13 -> V_86 ;
break;
default:
return 0 ;
}
if ( V_156 == 0 )
return 0 ;
if ( V_156 % 8000 )
V_155 = & V_157 ;
else
V_155 = & V_158 ;
return V_154 ( V_150 -> V_159 , 0 ,
V_160 ,
V_155 ) ;
}
static void F_35 ( struct V_6 * V_7 ,
unsigned int V_161 )
{
struct V_12 * V_13 = F_4 ( V_7 ) ;
struct V_9 * V_9 = V_13 -> V_9 ;
struct V_162 V_163 [] = {
{ 0x80 , 0x3 } ,
{ V_164 , 0 } ,
{ V_165 , 0 } ,
{ 0x80 , 0x0 } ,
} ;
F_36 ( & V_9 -> V_166 ) ;
V_163 [ 1 ] . V_167 = V_9 -> V_168 ;
if ( V_161 >= 176400 )
V_163 [ 2 ] . V_167 = V_9 -> V_169 ;
F_37 ( & V_9 -> V_166 ) ;
F_38 ( V_9 -> V_20 ,
V_163 ,
F_22 ( V_163 ) ) ;
}
static int F_39 ( struct V_149 * V_150 ,
struct V_170 * V_171 ,
struct V_111 * V_112 )
{
struct V_6 * V_7 = V_112 -> V_7 ;
struct V_12 * V_13 = F_4 ( V_7 ) ;
struct V_151 * V_152 = & V_13 -> V_112 [ V_112 -> V_153 - 1 ] ;
int V_117 = V_112 -> V_118 -> V_117 ;
int V_42 , V_172 ;
for ( V_42 = 0 ; V_42 < F_22 ( V_173 ) ; V_42 ++ )
if ( V_173 [ V_42 ] == F_40 ( V_171 ) )
break;
if ( V_42 == F_22 ( V_173 ) ) {
F_33 ( V_112 , L_22 ,
F_40 ( V_171 ) ) ;
return - V_73 ;
}
V_172 = V_42 ;
switch ( V_152 -> V_76 ) {
case V_99 :
switch ( V_13 -> V_9 -> type ) {
case V_16 :
F_35 ( V_7 ,
F_40 ( V_171 ) ) ;
break;
default:
break;
}
F_25 ( V_7 , V_174 ,
V_175 , V_172 ) ;
if ( V_117 )
F_25 ( V_7 , V_117 + V_176 ,
V_177 , 0 ) ;
break;
case V_102 :
F_25 ( V_7 , V_178 ,
V_179 , V_172 ) ;
if ( V_117 )
F_25 ( V_7 , V_117 + V_176 ,
V_177 ,
8 << V_180 ) ;
break;
default:
F_33 ( V_112 , L_23 , V_152 -> V_76 ) ;
return - V_73 ;
}
return 0 ;
}
static bool F_41 ( struct V_6 * V_7 ,
int V_117 , int V_115 , int V_114 , int V_181 )
{
int V_15 ;
V_15 = F_6 ( V_7 , V_117 + V_142 ) ;
if ( V_115 != ( V_15 & V_182 ) )
return true ;
V_15 = F_6 ( V_7 , V_117 + V_183 ) ;
if ( V_114 != ( V_15 & V_184 ) )
return true ;
V_15 = F_6 ( V_7 , V_117 + V_185 ) ;
if ( V_181 != ( V_15 & ( V_186 |
V_187 ) ) )
return true ;
return false ;
}
static int F_42 ( struct V_149 * V_150 ,
struct V_170 * V_171 ,
struct V_111 * V_112 )
{
struct V_6 * V_7 = V_112 -> V_7 ;
struct V_12 * V_13 = F_4 ( V_7 ) ;
struct V_9 * V_9 = V_13 -> V_9 ;
int V_117 = V_112 -> V_118 -> V_117 ;
const int * V_78 ;
int V_42 , V_32 , V_15 ;
int V_188 = F_43 ( V_171 ) ;
int V_189 = V_9 -> V_44 . V_190 [ V_112 -> V_153 - 1 ] ;
int V_191 = V_9 -> V_191 [ V_112 -> V_153 - 1 ] ;
int V_192 = V_9 -> V_192 [ V_112 -> V_153 - 1 ] ;
int V_115 , V_114 , V_193 , V_181 , V_194 ;
bool V_195 ;
unsigned int V_196 , V_197 ;
if ( F_40 ( V_171 ) % 8000 )
V_78 = & V_198 [ 0 ] ;
else
V_78 = & V_199 [ 0 ] ;
V_193 = F_44 ( F_45 ( V_171 ) ) ;
if ( V_192 ) {
F_46 ( V_112 , L_24 ,
V_192 , V_191 ) ;
V_194 = V_192 * V_191 * F_40 ( V_171 ) ;
V_188 = V_192 ;
} else {
V_194 = F_47 ( V_171 ) ;
V_191 = V_193 ;
}
if ( V_189 && V_189 < V_188 ) {
F_46 ( V_112 , L_25 , V_189 ) ;
V_194 /= V_188 ;
V_194 *= V_189 ;
}
V_15 = F_6 ( V_7 , V_117 + V_147 ) ;
V_15 &= V_148 ;
if ( ( V_188 & 1 ) && ( V_15 == V_127 ) ) {
F_46 ( V_112 , L_26 ) ;
V_194 /= V_188 ;
V_194 *= V_188 + 1 ;
}
for ( V_42 = 0 ; V_42 < F_22 ( V_198 ) ; V_42 ++ ) {
if ( V_78 [ V_42 ] >= V_194 &&
V_78 [ V_42 ] % F_40 ( V_171 ) == 0 ) {
V_115 = V_42 ;
break;
}
}
if ( V_42 == F_22 ( V_198 ) ) {
F_33 ( V_112 , L_22 ,
F_40 ( V_171 ) ) ;
return - V_73 ;
}
V_114 = V_78 [ V_115 ] / F_40 ( V_171 ) ;
F_46 ( V_112 , L_27 ,
V_78 [ V_115 ] , V_78 [ V_115 ] / V_114 ) ;
V_181 = V_193 << V_200 | V_191 ;
V_195 = F_41 ( V_7 , V_117 , V_115 , V_114 , V_181 ) ;
if ( V_195 ) {
V_196 = F_6 ( V_7 ,
V_117 + V_201 ) ;
V_197 = F_6 ( V_7 ,
V_117 + V_202 ) ;
F_8 ( V_9 -> V_20 ,
V_117 + V_201 , 0xff , 0x0 ) ;
F_14 ( V_9 -> V_20 ,
V_117 + V_202 , 0xff , 0x0 ) ;
}
V_32 = F_39 ( V_150 , V_171 , V_112 ) ;
if ( V_32 != 0 )
goto V_203;
if ( V_195 ) {
F_8 ( V_9 -> V_20 ,
V_117 + V_142 ,
V_182 , V_115 ) ;
F_8 ( V_9 -> V_20 ,
V_117 + V_183 ,
V_184 , V_114 ) ;
F_8 ( V_9 -> V_20 ,
V_117 + V_204 ,
V_205 , V_114 ) ;
F_8 ( V_9 -> V_20 ,
V_117 + V_185 ,
V_186 |
V_187 , V_181 ) ;
F_14 ( V_9 -> V_20 ,
V_117 + V_206 ,
V_207 |
V_208 , V_181 ) ;
}
V_203:
if ( V_195 ) {
F_8 ( V_9 -> V_20 ,
V_117 + V_201 ,
0xff , V_196 ) ;
F_14 ( V_9 -> V_20 ,
V_117 + V_202 ,
0xff , V_197 ) ;
}
return V_32 ;
}
static const char * F_48 ( int V_92 )
{
switch ( V_92 ) {
case V_99 :
return L_14 ;
case V_102 :
return L_15 ;
default:
return L_28 ;
}
}
static int F_49 ( struct V_111 * V_112 ,
int V_92 , unsigned int V_77 , int V_94 )
{
struct V_6 * V_7 = V_112 -> V_7 ;
struct V_12 * V_13 = F_4 ( V_7 ) ;
struct V_151 * V_152 = & V_13 -> V_112 [ V_112 -> V_153 - 1 ] ;
struct V_209 V_210 [ 2 ] ;
switch ( V_92 ) {
case V_99 :
case V_102 :
break;
default:
return - V_73 ;
}
if ( V_92 == V_152 -> V_76 )
return 0 ;
if ( V_112 -> V_211 ) {
F_12 ( V_7 -> V_10 , L_29 ,
V_112 -> V_153 ) ;
return - V_25 ;
}
F_30 ( V_7 -> V_10 , L_30 , V_112 -> V_153 + 1 ,
F_48 ( V_92 ) ) ;
memset ( & V_210 , 0 , sizeof( V_210 ) ) ;
V_210 [ 0 ] . V_212 = V_112 -> V_118 -> V_213 . V_214 ;
V_210 [ 1 ] . V_212 = V_112 -> V_118 -> V_215 . V_214 ;
V_210 [ 0 ] . V_93 = F_48 ( V_152 -> V_76 ) ;
V_210 [ 1 ] . V_93 = F_48 ( V_152 -> V_76 ) ;
F_50 ( & V_7 -> V_8 , V_210 , F_22 ( V_210 ) ) ;
V_210 [ 0 ] . V_93 = F_48 ( V_92 ) ;
V_210 [ 1 ] . V_93 = F_48 ( V_92 ) ;
F_19 ( & V_7 -> V_8 , V_210 , F_22 ( V_210 ) ) ;
V_152 -> V_76 = V_92 ;
return F_51 ( & V_7 -> V_8 ) ;
}
static int F_52 ( struct V_111 * V_112 , int V_216 )
{
struct V_6 * V_7 = V_112 -> V_7 ;
int V_117 = V_112 -> V_118 -> V_117 ;
unsigned int V_57 ;
if ( V_216 )
V_57 = V_217 ;
else
V_57 = 0 ;
return F_25 ( V_7 , V_117 + V_176 ,
V_217 , V_57 ) ;
}
static void F_53 ( struct V_111 * V_112 ,
unsigned int V_117 ,
int V_188 , unsigned int V_72 )
{
struct V_6 * V_7 = V_112 -> V_7 ;
struct V_12 * V_13 = F_4 ( V_7 ) ;
struct V_9 * V_9 = V_13 -> V_9 ;
int V_218 , V_42 ;
for ( V_42 = 0 ; V_42 < V_188 ; ++ V_42 ) {
V_218 = F_54 ( V_72 ) - 1 ;
if ( V_218 < 0 )
return;
F_55 ( V_9 -> V_20 , V_117 + V_42 , V_218 ) ;
V_72 &= ~ ( 1 << V_218 ) ;
}
if ( V_72 )
F_56 ( V_112 , L_31 ) ;
}
static int F_57 ( struct V_111 * V_112 , unsigned int V_219 ,
unsigned int V_220 , int V_221 , int V_222 )
{
struct V_6 * V_7 = V_112 -> V_7 ;
struct V_12 * V_13 = F_4 ( V_7 ) ;
struct V_9 * V_9 = V_13 -> V_9 ;
int V_117 = V_112 -> V_118 -> V_117 ;
int V_223 = V_112 -> V_118 -> V_215 . V_224 ;
int V_225 = V_112 -> V_118 -> V_213 . V_224 ;
if ( V_112 -> V_153 > V_226 )
return - V_227 ;
if ( V_221 == 0 ) {
V_219 = ( 1 << V_225 ) - 1 ;
V_220 = ( 1 << V_223 ) - 1 ;
}
F_53 ( V_112 , V_117 + V_228 ,
V_225 , V_219 ) ;
F_53 ( V_112 , V_117 + V_229 ,
V_223 , V_220 ) ;
V_9 -> V_191 [ V_112 -> V_153 - 1 ] = V_222 ;
V_9 -> V_192 [ V_112 -> V_153 - 1 ] = V_221 ;
return 0 ;
}
int F_58 ( struct V_12 * V_13 , int V_153 )
{
struct V_151 * V_152 = & V_13 -> V_112 [ V_153 ] ;
V_152 -> V_76 = V_99 ;
return 0 ;
}
static T_1 F_59 ( int V_30 , void * V_31 )
{
struct V_230 * V_231 = V_31 ;
F_60 ( V_231 , L_32 ) ;
F_61 ( & V_231 -> V_232 ) ;
return V_34 ;
}
static int F_62 ( struct V_230 * V_231 ,
unsigned int V_233 ,
unsigned int V_234 )
{
unsigned int V_235 ;
if ( V_231 -> V_236 && V_234 != V_231 -> V_236 ) {
F_63 ( V_231 ,
L_33 ) ;
return - V_73 ;
}
if ( V_233 / V_237 > V_238 ) {
F_63 ( V_231 ,
L_34 ,
V_233 ) ;
return - V_73 ;
}
V_235 = V_239 * V_231 -> V_240 ;
if ( V_234 * V_241 < V_235 ) {
F_63 ( V_231 , L_35 ,
V_234 ) ;
return - V_73 ;
}
return 0 ;
}
static int F_64 ( unsigned int V_233 , int * V_242 )
{
int V_42 ;
for ( V_42 = 0 ; V_42 < F_22 ( V_243 ) ; V_42 ++ ) {
if ( V_243 [ V_42 ] . V_244 <= V_233 && V_233 <= V_243 [ V_42 ] . V_245 ) {
if ( V_242 )
* V_242 = V_243 [ V_42 ] . V_242 ;
return V_243 [ V_42 ] . V_246 ;
}
}
return - V_73 ;
}
static int F_65 ( struct V_230 * V_231 ,
struct V_247 * V_248 ,
unsigned int V_249 ,
unsigned int V_233 , bool V_250 )
{
int V_251 , V_246 ;
int V_252 , div ;
div = 1 ;
V_248 -> V_252 = 0 ;
while ( V_233 > V_238 ) {
div *= 2 ;
V_233 /= 2 ;
V_248 -> V_252 ++ ;
if ( div > V_237 )
return - V_73 ;
}
V_251 = F_64 ( V_233 , & V_248 -> V_242 ) ;
if ( V_251 < 0 ) {
F_63 ( V_231 , L_36 ,
V_233 ) ;
return V_251 ;
}
switch ( V_231 -> V_9 -> type ) {
case V_47 :
case V_48 :
if ( V_231 -> V_9 -> V_17 < 3 || V_250 )
return V_251 ;
break;
default:
return V_251 ;
}
V_248 -> V_242 = V_251 - 1 ;
V_252 = V_248 -> V_252 ;
while ( div <= V_237 ) {
for ( V_246 = V_251 ; V_246 <= V_253 ;
V_246 ++ ) {
if ( ( V_254 / 2 ) /
( V_231 -> V_240 * V_246 ) < V_233 )
break;
if ( V_249 % ( V_246 * V_233 ) ) {
V_248 -> V_252 = V_252 ;
V_248 -> V_242 = V_246 - 1 ;
return V_246 ;
}
}
for ( V_246 = V_251 - 1 ; V_246 > 0 ; V_246 -- ) {
if ( V_249 % ( V_246 * V_233 ) ) {
V_248 -> V_252 = V_252 ;
V_248 -> V_242 = V_246 - 1 ;
return V_246 ;
}
}
div *= 2 ;
V_233 /= 2 ;
V_252 ++ ;
V_251 = F_64 ( V_233 , NULL ) ;
}
F_66 ( V_231 , L_37 ) ;
return V_248 -> V_242 + 1 ;
}
static int F_67 ( struct V_230 * V_231 ,
struct V_247 * V_248 ,
unsigned int V_233 , bool V_250 )
{
unsigned int V_249 , div , V_255 ;
int V_42 , V_246 ;
F_60 ( V_231 , L_38 , V_233 , V_231 -> V_236 ) ;
div = V_256 ;
while ( V_231 -> V_236 * div < V_239 * V_231 -> V_240 ) {
div ++ ;
if ( div > V_241 )
return - V_73 ;
}
V_249 = V_231 -> V_236 * div / V_231 -> V_240 ;
V_248 -> V_257 = div ;
F_60 ( V_231 , L_39 , V_249 ) ;
V_246 = F_65 ( V_231 , V_248 , V_249 , V_233 , V_250 ) ;
if ( V_246 < 0 )
return V_246 ;
V_233 = V_233 / ( 1 << V_248 -> V_252 ) ;
V_248 -> V_258 = V_249 / ( V_246 * V_233 ) ;
if ( V_249 % ( V_246 * V_233 ) ) {
V_255 = F_68 ( V_249 , V_246 * V_233 ) ;
F_60 ( V_231 , L_40 , V_255 ) ;
V_248 -> V_259 = ( V_249 - ( V_248 -> V_258 * V_246 * V_233 ) )
/ V_255 ;
V_248 -> V_260 = ( V_246 * V_233 ) / V_255 ;
} else {
V_248 -> V_259 = 0 ;
V_248 -> V_260 = 0 ;
}
while ( V_248 -> V_260 >= ( 1 << 16 ) ) {
V_248 -> V_259 >>= 1 ;
V_248 -> V_260 >>= 1 ;
}
for ( V_42 = 0 ; V_42 < F_22 ( V_261 ) ; V_42 ++ ) {
if ( V_261 [ V_42 ] . V_244 <= V_233 && V_233 <= V_261 [ V_42 ] . V_245 ) {
V_248 -> V_262 = V_261 [ V_42 ] . V_262 ;
break;
}
}
if ( V_42 == F_22 ( V_261 ) ) {
F_63 ( V_231 , L_41 ,
V_233 ) ;
return - V_73 ;
}
F_60 ( V_231 , L_42 ,
V_248 -> V_258 , V_248 -> V_259 , V_248 -> V_260 ) ;
F_60 ( V_231 , L_43 ,
V_248 -> V_242 , V_248 -> V_242 , V_248 -> V_257 , V_248 -> V_252 ) ;
F_60 ( V_231 , L_44 , V_248 -> V_262 ) ;
return 0 ;
}
static void F_69 ( struct V_9 * V_9 , unsigned int V_117 ,
struct V_247 * V_248 , int V_93 ,
bool V_250 )
{
F_8 ( V_9 -> V_20 , V_117 + 3 ,
V_263 , V_248 -> V_259 ) ;
F_8 ( V_9 -> V_20 , V_117 + 4 ,
V_264 , V_248 -> V_260 ) ;
F_8 ( V_9 -> V_20 , V_117 + 5 ,
V_265 ,
V_248 -> V_242 << V_266 ) ;
F_8 ( V_9 -> V_20 , V_117 + 6 ,
V_267 |
V_268 ,
V_248 -> V_252 << V_269 |
V_93 << V_270 ) ;
if ( V_250 ) {
F_14 ( V_9 -> V_20 , V_117 + 0x7 ,
V_271 ,
V_248 -> V_262 << V_272 ) ;
} else {
F_14 ( V_9 -> V_20 , V_117 + 0x5 ,
V_273 ,
V_248 -> V_257 << V_274 ) ;
F_14 ( V_9 -> V_20 , V_117 + 0x9 ,
V_271 ,
V_248 -> V_262 << V_272 ) ;
}
F_8 ( V_9 -> V_20 , V_117 + 2 ,
V_275 | V_276 ,
V_275 | V_248 -> V_258 ) ;
}
static int F_70 ( struct V_230 * V_231 )
{
struct V_9 * V_9 = V_231 -> V_9 ;
unsigned int V_57 ;
int V_32 ;
V_32 = F_11 ( V_9 -> V_20 , V_231 -> V_117 + 1 , & V_57 ) ;
if ( V_32 != 0 ) {
F_63 ( V_231 , L_45 ,
V_32 ) ;
return V_32 ;
}
return V_57 & V_277 ;
}
static int F_71 ( struct V_230 * V_231 )
{
struct V_9 * V_9 = V_231 -> V_9 ;
unsigned long V_278 ;
bool V_279 = false ;
int V_280 = F_70 ( V_231 ) ;
struct V_247 V_248 ;
if ( V_280 < 0 )
return V_280 ;
if ( V_280 ) {
F_8 ( V_231 -> V_9 -> V_20 , V_231 -> V_117 + 0x7 ,
V_271 , 0 ) ;
F_8 ( V_231 -> V_9 -> V_20 , V_231 -> V_117 + 1 ,
V_281 ,
V_281 ) ;
}
if ( V_231 -> V_282 >= 0 && V_231 -> V_283 &&
V_231 -> V_282 != V_231 -> V_284 ) {
F_67 ( V_231 , & V_248 , V_231 -> V_283 , false ) ;
F_69 ( V_9 , V_231 -> V_117 , & V_248 , V_231 -> V_282 ,
false ) ;
if ( V_231 -> V_284 >= 0 ) {
F_67 ( V_231 , & V_248 , V_231 -> V_285 , true ) ;
F_69 ( V_9 , V_231 -> V_117 + 0x10 , & V_248 ,
V_231 -> V_284 , true ) ;
V_279 = true ;
}
} else if ( V_231 -> V_284 >= 0 ) {
F_67 ( V_231 , & V_248 , V_231 -> V_285 , false ) ;
F_69 ( V_9 , V_231 -> V_117 , & V_248 ,
V_231 -> V_284 , false ) ;
F_8 ( V_9 -> V_20 , V_231 -> V_117 + 0x11 ,
V_286 , 0 ) ;
} else {
F_63 ( V_231 , L_46 ) ;
return - V_73 ;
}
if ( V_279 && V_231 -> V_285 > 100000 )
F_8 ( V_9 -> V_20 , V_231 -> V_117 + 0x17 ,
V_287 , 0 ) ;
else
F_8 ( V_9 -> V_20 , V_231 -> V_117 + 0x17 ,
V_287 ,
V_287 ) ;
if ( ! V_280 )
F_72 ( V_9 -> V_10 ) ;
F_73 ( & V_231 -> V_232 ) ;
F_8 ( V_9 -> V_20 , V_231 -> V_117 + 1 ,
V_277 , V_277 ) ;
if ( V_279 )
F_8 ( V_9 -> V_20 , V_231 -> V_117 + 0x11 ,
V_286 ,
V_286 ) ;
if ( V_280 )
F_8 ( V_9 -> V_20 , V_231 -> V_117 + 1 ,
V_281 , 0 ) ;
V_278 = F_74 ( & V_231 -> V_232 ,
F_75 ( 250 ) ) ;
if ( V_278 == 0 )
F_66 ( V_231 , L_47 ) ;
return 0 ;
}
static void F_76 ( struct V_230 * V_231 )
{
struct V_9 * V_9 = V_231 -> V_9 ;
bool V_288 ;
F_8 ( V_9 -> V_20 , V_231 -> V_117 + 1 ,
V_281 , V_281 ) ;
F_77 ( V_9 -> V_20 , V_231 -> V_117 + 1 ,
V_277 , 0 , & V_288 ) ;
F_14 ( V_9 -> V_20 , V_231 -> V_117 + 0x11 ,
V_286 , 0 ) ;
F_8 ( V_9 -> V_20 , V_231 -> V_117 + 1 ,
V_281 , 0 ) ;
if ( V_288 )
F_78 ( V_9 -> V_10 ) ;
}
int F_79 ( struct V_230 * V_231 , int V_93 ,
unsigned int V_233 , unsigned int V_234 )
{
int V_32 = 0 ;
if ( V_231 -> V_282 == V_93 && V_231 -> V_283 == V_233 )
return 0 ;
if ( V_231 -> V_236 && V_233 > 0 ) {
V_32 = F_62 ( V_231 , V_233 , V_231 -> V_236 ) ;
if ( V_32 != 0 )
return V_32 ;
}
V_231 -> V_282 = V_93 ;
V_231 -> V_283 = V_233 ;
if ( V_231 -> V_236 && V_233 > 0 ) {
V_32 = F_71 ( V_231 ) ;
}
return V_32 ;
}
int F_80 ( struct V_230 * V_231 , int V_93 ,
unsigned int V_233 , unsigned int V_234 )
{
int V_32 = 0 ;
if ( V_231 -> V_284 == V_93 &&
V_231 -> V_285 == V_233 && V_231 -> V_236 == V_234 )
return 0 ;
if ( V_234 ) {
if ( V_231 -> V_282 >= 0 ) {
V_32 = F_62 ( V_231 , V_231 -> V_283 , V_234 ) ;
if ( V_32 != 0 )
return V_32 ;
}
V_32 = F_62 ( V_231 , V_233 , V_234 ) ;
if ( V_32 != 0 )
return V_32 ;
}
V_231 -> V_284 = V_93 ;
V_231 -> V_285 = V_233 ;
V_231 -> V_236 = V_234 ;
if ( V_234 )
V_32 = F_71 ( V_231 ) ;
else
F_76 ( V_231 ) ;
return V_32 ;
}
int F_81 ( struct V_9 * V_9 , int V_153 , int V_117 , int V_289 ,
int V_290 , struct V_230 * V_231 )
{
int V_32 ;
unsigned int V_15 ;
F_82 ( & V_231 -> V_232 ) ;
V_231 -> V_153 = V_153 ;
V_231 -> V_117 = V_117 ;
V_231 -> V_9 = V_9 ;
V_231 -> V_284 = V_291 ;
F_11 ( V_9 -> V_20 , V_292 , & V_15 ) ;
switch ( V_15 & V_293 ) {
case V_294 :
case V_295 :
V_231 -> V_282 = V_15 & V_293 ;
break;
default:
V_231 -> V_282 = V_291 ;
}
V_231 -> V_283 = 32768 ;
snprintf ( V_231 -> V_296 , sizeof( V_231 -> V_296 ) , L_48 , V_153 ) ;
snprintf ( V_231 -> V_297 , sizeof( V_231 -> V_297 ) ,
L_49 , V_153 ) ;
V_32 = F_17 ( V_9 , V_290 , V_231 -> V_297 ,
F_59 , V_231 ) ;
if ( V_32 != 0 ) {
F_12 ( V_9 -> V_10 , L_50 ,
V_153 , V_32 ) ;
}
F_14 ( V_9 -> V_20 , V_231 -> V_117 + 1 ,
V_281 , 0 ) ;
return 0 ;
}
int F_83 ( struct V_6 * V_7 , int V_298 , bool V_299 )
{
unsigned int V_57 , V_15 ;
if ( V_298 < 1 || V_298 > 6 )
return - V_73 ;
V_57 = V_300 + ( V_298 - 1 ) * 8 ;
if ( V_299 )
V_15 = V_301 ;
else
V_15 = 0 ;
return F_25 ( V_7 , V_57 , V_301 , V_15 ) ;
}
