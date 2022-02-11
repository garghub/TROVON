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
V_111 = 0 ;
break;
case V_116 :
V_111 = 2 ;
break;
default:
F_32 ( V_107 , L_18 ,
V_108 & V_114 ) ;
return - V_68 ;
}
switch ( V_108 & V_117 ) {
case V_118 :
break;
case V_119 :
V_109 |= V_120 ;
break;
case V_121 :
V_110 |= V_122 ;
break;
case V_123 :
V_110 |= V_122 ;
V_109 |= V_120 ;
break;
default:
F_32 ( V_107 , L_19 ,
V_108 & V_117 ) ;
return - V_68 ;
}
switch ( V_108 & V_124 ) {
case V_125 :
break;
case V_126 :
V_110 |= V_127 ;
V_109 |= V_128 ;
break;
case V_129 :
V_110 |= V_127 ;
break;
case V_130 :
V_109 |= V_128 ;
break;
default:
return - V_68 ;
}
F_7 ( V_8 -> V_19 , V_112 + V_131 ,
V_127 |
V_122 ,
V_110 ) ;
F_7 ( V_8 -> V_19 , V_112 + V_132 ,
V_128 |
V_120 , V_109 ) ;
F_7 ( V_8 -> V_19 ,
V_112 + V_133 ,
V_134 |
V_135 , V_109 ) ;
F_13 ( V_8 -> V_19 , V_112 + V_136 ,
V_137 , V_111 ) ;
return 0 ;
}
static int F_33 ( struct V_138 * V_139 ,
struct V_106 * V_107 )
{
struct V_6 * V_7 = V_107 -> V_7 ;
struct V_11 * V_12 = F_3 ( V_7 ) ;
struct V_140 * V_141 = & V_12 -> V_107 [ V_107 -> V_142 - 1 ] ;
const struct V_143 * V_144 ;
unsigned int V_145 ;
switch ( V_141 -> V_71 ) {
case V_94 :
V_145 = V_12 -> V_78 ;
break;
case V_97 :
V_145 = V_12 -> V_81 ;
break;
default:
return 0 ;
}
if ( V_145 == 0 )
return 0 ;
if ( V_145 % 8000 )
V_144 = & V_146 ;
else
V_144 = & V_147 ;
return V_143 ( V_139 -> V_148 , 0 ,
V_149 ,
V_144 ) ;
}
static void F_34 ( struct V_6 * V_7 ,
unsigned int V_150 )
{
struct V_11 * V_12 = F_3 ( V_7 ) ;
struct V_8 * V_8 = V_12 -> V_8 ;
struct V_151 V_152 [] = {
{ 0x80 , 0x3 } ,
{ V_153 , 0 } ,
{ V_154 , 0 } ,
{ 0x80 , 0x0 } ,
} ;
F_35 ( & V_7 -> V_155 ) ;
V_152 [ 1 ] . V_156 = V_8 -> V_157 ;
if ( V_150 >= 176400 )
V_152 [ 2 ] . V_156 = V_8 -> V_158 ;
F_36 ( & V_7 -> V_155 ) ;
F_37 ( V_8 -> V_19 ,
V_152 ,
F_21 ( V_152 ) ) ;
}
static int F_38 ( struct V_138 * V_139 ,
struct V_159 * V_160 ,
struct V_106 * V_107 )
{
struct V_6 * V_7 = V_107 -> V_7 ;
struct V_11 * V_12 = F_3 ( V_7 ) ;
struct V_140 * V_141 = & V_12 -> V_107 [ V_107 -> V_142 - 1 ] ;
int V_112 = V_107 -> V_113 -> V_112 ;
int V_42 , V_161 ;
for ( V_42 = 0 ; V_42 < F_21 ( V_162 ) ; V_42 ++ )
if ( V_162 [ V_42 ] == F_39 ( V_160 ) )
break;
if ( V_42 == F_21 ( V_162 ) ) {
F_32 ( V_107 , L_20 ,
F_39 ( V_160 ) ) ;
return - V_68 ;
}
V_161 = V_42 ;
switch ( V_141 -> V_71 ) {
case V_94 :
switch ( V_12 -> V_8 -> type ) {
case V_15 :
F_34 ( V_7 ,
F_39 ( V_160 ) ) ;
break;
default:
break;
}
F_24 ( V_7 , V_163 ,
V_164 , V_161 ) ;
if ( V_112 )
F_24 ( V_7 , V_112 + V_165 ,
V_166 , 0 ) ;
break;
case V_97 :
F_24 ( V_7 , V_167 ,
V_168 , V_161 ) ;
if ( V_112 )
F_24 ( V_7 , V_112 + V_165 ,
V_166 ,
8 << V_169 ) ;
break;
default:
F_32 ( V_107 , L_21 , V_141 -> V_71 ) ;
return - V_68 ;
}
return 0 ;
}
static bool F_40 ( struct V_6 * V_7 ,
int V_112 , int V_110 , int V_109 , int V_170 )
{
int V_14 ;
V_14 = F_5 ( V_7 , V_112 + V_131 ) ;
if ( V_110 != ( V_14 & V_171 ) )
return true ;
V_14 = F_5 ( V_7 , V_112 + V_172 ) ;
if ( V_109 != ( V_14 & V_173 ) )
return true ;
V_14 = F_5 ( V_7 , V_112 + V_174 ) ;
if ( V_170 != ( V_14 & ( V_175 |
V_176 ) ) )
return true ;
return false ;
}
static int F_41 ( struct V_138 * V_139 ,
struct V_159 * V_160 ,
struct V_106 * V_107 )
{
struct V_6 * V_7 = V_107 -> V_7 ;
struct V_11 * V_12 = F_3 ( V_7 ) ;
struct V_8 * V_8 = V_12 -> V_8 ;
int V_112 = V_107 -> V_113 -> V_112 ;
const int * V_73 ;
int V_42 , V_31 , V_14 ;
int V_177 = F_42 ( V_160 ) ;
int V_178 = V_8 -> V_44 . V_179 [ V_107 -> V_142 - 1 ] ;
int V_180 = V_8 -> V_180 [ V_107 -> V_142 - 1 ] ;
int V_181 = V_8 -> V_181 [ V_107 -> V_142 - 1 ] ;
int V_110 , V_109 , V_182 , V_170 , V_183 ;
bool V_184 ;
unsigned int V_185 , V_186 ;
if ( F_39 ( V_160 ) % 8000 )
V_73 = & V_187 [ 0 ] ;
else
V_73 = & V_188 [ 0 ] ;
V_182 = F_43 ( F_44 ( V_160 ) ) ;
if ( V_181 ) {
F_45 ( V_107 , L_22 ,
V_181 , V_180 ) ;
V_183 = V_181 * V_180 * F_39 ( V_160 ) ;
V_177 = V_181 ;
} else {
V_183 = F_46 ( V_160 ) ;
V_180 = V_182 ;
}
if ( V_178 && V_178 < V_177 ) {
F_45 ( V_107 , L_23 , V_178 ) ;
V_183 /= V_177 ;
V_183 *= V_178 ;
}
V_14 = F_5 ( V_7 , V_112 + V_136 ) ;
if ( ( V_177 & 1 ) && ( V_14 & V_137 ) ) {
F_45 ( V_107 , L_24 ) ;
V_183 /= V_177 ;
V_183 *= V_177 + 1 ;
}
for ( V_42 = 0 ; V_42 < F_21 ( V_187 ) ; V_42 ++ ) {
if ( V_73 [ V_42 ] >= V_183 &&
V_73 [ V_42 ] % F_39 ( V_160 ) == 0 ) {
V_110 = V_42 ;
break;
}
}
if ( V_42 == F_21 ( V_187 ) ) {
F_32 ( V_107 , L_20 ,
F_39 ( V_160 ) ) ;
return - V_68 ;
}
V_109 = V_73 [ V_110 ] / F_39 ( V_160 ) ;
F_45 ( V_107 , L_25 ,
V_73 [ V_110 ] , V_73 [ V_110 ] / V_109 ) ;
V_170 = V_182 << V_189 | V_180 ;
V_184 = F_40 ( V_7 , V_112 , V_110 , V_109 , V_170 ) ;
if ( V_184 ) {
V_185 = F_5 ( V_7 ,
V_112 + V_190 ) ;
V_186 = F_5 ( V_7 ,
V_112 + V_191 ) ;
F_7 ( V_8 -> V_19 ,
V_112 + V_190 , 0xff , 0x0 ) ;
F_13 ( V_8 -> V_19 ,
V_112 + V_191 , 0xff , 0x0 ) ;
}
V_31 = F_38 ( V_139 , V_160 , V_107 ) ;
if ( V_31 != 0 )
goto V_192;
if ( V_184 ) {
F_7 ( V_8 -> V_19 ,
V_112 + V_131 ,
V_171 , V_110 ) ;
F_7 ( V_8 -> V_19 ,
V_112 + V_172 ,
V_173 , V_109 ) ;
F_7 ( V_8 -> V_19 ,
V_112 + V_193 ,
V_194 , V_109 ) ;
F_7 ( V_8 -> V_19 ,
V_112 + V_174 ,
V_175 |
V_176 , V_170 ) ;
F_13 ( V_8 -> V_19 ,
V_112 + V_195 ,
V_196 |
V_197 , V_170 ) ;
}
V_192:
if ( V_184 ) {
F_7 ( V_8 -> V_19 ,
V_112 + V_190 ,
0xff , V_185 ) ;
F_13 ( V_8 -> V_19 ,
V_112 + V_191 ,
0xff , V_186 ) ;
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
return L_26 ;
}
}
static int F_48 ( struct V_106 * V_107 ,
int V_87 , unsigned int V_72 , int V_89 )
{
struct V_6 * V_7 = V_107 -> V_7 ;
struct V_11 * V_12 = F_3 ( V_7 ) ;
struct V_140 * V_141 = & V_12 -> V_107 [ V_107 -> V_142 - 1 ] ;
struct V_198 V_199 [ 2 ] ;
switch ( V_87 ) {
case V_94 :
case V_97 :
break;
default:
return - V_68 ;
}
if ( V_87 == V_141 -> V_71 )
return 0 ;
if ( V_107 -> V_200 ) {
F_11 ( V_7 -> V_9 , L_27 ,
V_107 -> V_142 ) ;
return - V_24 ;
}
F_29 ( V_7 -> V_9 , L_28 , V_107 -> V_142 + 1 ,
F_47 ( V_87 ) ) ;
memset ( & V_199 , 0 , sizeof( V_199 ) ) ;
V_199 [ 0 ] . V_201 = V_107 -> V_113 -> V_202 . V_203 ;
V_199 [ 1 ] . V_201 = V_107 -> V_113 -> V_204 . V_203 ;
V_199 [ 0 ] . V_88 = F_47 ( V_141 -> V_71 ) ;
V_199 [ 1 ] . V_88 = F_47 ( V_141 -> V_71 ) ;
F_49 ( & V_7 -> V_36 , V_199 , F_21 ( V_199 ) ) ;
V_199 [ 0 ] . V_88 = F_47 ( V_87 ) ;
V_199 [ 1 ] . V_88 = F_47 ( V_87 ) ;
F_18 ( & V_7 -> V_36 , V_199 , F_21 ( V_199 ) ) ;
V_141 -> V_71 = V_87 ;
return F_50 ( & V_7 -> V_36 ) ;
}
static int F_51 ( struct V_106 * V_107 , int V_205 )
{
struct V_6 * V_7 = V_107 -> V_7 ;
int V_112 = V_107 -> V_113 -> V_112 ;
unsigned int V_56 ;
if ( V_205 )
V_56 = V_206 ;
else
V_56 = 0 ;
return F_24 ( V_7 , V_112 + V_165 ,
V_206 , V_56 ) ;
}
static void F_52 ( struct V_106 * V_107 ,
unsigned int V_112 ,
int V_177 , unsigned int V_67 )
{
struct V_6 * V_7 = V_107 -> V_7 ;
struct V_11 * V_12 = F_3 ( V_7 ) ;
struct V_8 * V_8 = V_12 -> V_8 ;
int V_207 , V_42 ;
for ( V_42 = 0 ; V_42 < V_177 ; ++ V_42 ) {
V_207 = F_53 ( V_67 ) - 1 ;
if ( V_207 < 0 )
return;
F_54 ( V_8 -> V_19 , V_112 + V_42 , V_207 ) ;
V_67 &= ~ ( 1 << V_207 ) ;
}
if ( V_67 )
F_55 ( V_107 , L_29 ) ;
}
static int F_56 ( struct V_106 * V_107 , unsigned int V_208 ,
unsigned int V_209 , int V_210 , int V_211 )
{
struct V_6 * V_7 = V_107 -> V_7 ;
struct V_11 * V_12 = F_3 ( V_7 ) ;
struct V_8 * V_8 = V_12 -> V_8 ;
int V_112 = V_107 -> V_113 -> V_112 ;
int V_212 = V_107 -> V_113 -> V_204 . V_213 ;
int V_214 = V_107 -> V_113 -> V_202 . V_213 ;
if ( V_107 -> V_142 > V_215 )
return - V_216 ;
if ( V_210 == 0 ) {
V_208 = ( 1 << V_214 ) - 1 ;
V_209 = ( 1 << V_212 ) - 1 ;
}
F_52 ( V_107 , V_112 + V_217 ,
V_214 , V_208 ) ;
F_52 ( V_107 , V_112 + V_218 ,
V_212 , V_209 ) ;
V_8 -> V_180 [ V_107 -> V_142 - 1 ] = V_211 ;
V_8 -> V_181 [ V_107 -> V_142 - 1 ] = V_210 ;
return 0 ;
}
int F_57 ( struct V_11 * V_12 , int V_142 )
{
struct V_140 * V_141 = & V_12 -> V_107 [ V_142 ] ;
V_141 -> V_71 = V_94 ;
return 0 ;
}
static T_1 F_58 ( int V_29 , void * V_30 )
{
struct V_219 * V_220 = V_30 ;
F_59 ( V_220 , L_30 ) ;
F_60 ( & V_220 -> V_221 ) ;
return V_33 ;
}
static int F_61 ( struct V_219 * V_220 ,
unsigned int V_222 ,
unsigned int V_223 )
{
unsigned int V_224 ;
if ( V_220 -> V_225 && V_223 != V_220 -> V_225 ) {
F_62 ( V_220 ,
L_31 ) ;
return - V_68 ;
}
if ( V_222 / V_226 > V_227 ) {
F_62 ( V_220 ,
L_32 ,
V_222 ) ;
return - V_68 ;
}
V_224 = V_228 * V_220 -> V_229 ;
if ( V_223 * V_230 < V_224 ) {
F_62 ( V_220 , L_33 ,
V_223 ) ;
return - V_68 ;
}
return 0 ;
}
static int F_63 ( unsigned int V_222 , int * V_231 )
{
int V_42 ;
for ( V_42 = 0 ; V_42 < F_21 ( V_232 ) ; V_42 ++ ) {
if ( V_232 [ V_42 ] . V_233 <= V_222 && V_222 <= V_232 [ V_42 ] . V_234 ) {
if ( V_231 )
* V_231 = V_232 [ V_42 ] . V_231 ;
return V_232 [ V_42 ] . V_235 ;
}
}
return - V_68 ;
}
static int F_64 ( struct V_219 * V_220 ,
struct V_236 * V_237 ,
unsigned int V_238 ,
unsigned int V_222 , bool V_239 )
{
int V_240 , V_235 ;
int V_241 , div ;
div = 1 ;
V_237 -> V_241 = 0 ;
while ( V_222 > V_227 ) {
div *= 2 ;
V_222 /= 2 ;
V_237 -> V_241 ++ ;
if ( div > V_226 )
return - V_68 ;
}
V_240 = F_63 ( V_222 , & V_237 -> V_231 ) ;
if ( V_240 < 0 ) {
F_62 ( V_220 , L_34 ,
V_222 ) ;
return V_240 ;
}
switch ( V_220 -> V_8 -> type ) {
case V_47 :
if ( V_220 -> V_8 -> V_16 < 3 || V_239 )
return V_240 ;
break;
default:
return V_240 ;
}
V_237 -> V_231 = V_240 - 1 ;
V_241 = V_237 -> V_241 ;
while ( div <= V_226 ) {
for ( V_235 = V_240 ; V_235 <= V_242 ;
V_235 ++ ) {
if ( ( V_243 / 2 ) /
( V_220 -> V_229 * V_235 ) < V_222 )
break;
if ( V_238 % ( V_235 * V_222 ) ) {
V_237 -> V_241 = V_241 ;
V_237 -> V_231 = V_235 - 1 ;
return V_235 ;
}
}
for ( V_235 = V_240 - 1 ; V_235 > 0 ; V_235 -- ) {
if ( V_238 % ( V_235 * V_222 ) ) {
V_237 -> V_241 = V_241 ;
V_237 -> V_231 = V_235 - 1 ;
return V_235 ;
}
}
div *= 2 ;
V_222 /= 2 ;
V_241 ++ ;
V_240 = F_63 ( V_222 , NULL ) ;
}
F_65 ( V_220 , L_35 ) ;
return V_237 -> V_231 + 1 ;
}
static int F_66 ( struct V_219 * V_220 ,
struct V_236 * V_237 ,
unsigned int V_222 , bool V_239 )
{
unsigned int V_238 , div , V_244 ;
int V_42 , V_235 ;
F_59 ( V_220 , L_36 , V_222 , V_220 -> V_225 ) ;
div = V_245 ;
while ( V_220 -> V_225 * div < V_228 * V_220 -> V_229 ) {
div ++ ;
if ( div > V_230 )
return - V_68 ;
}
V_238 = V_220 -> V_225 * div / V_220 -> V_229 ;
V_237 -> V_246 = div ;
F_59 ( V_220 , L_37 , V_238 ) ;
V_235 = F_64 ( V_220 , V_237 , V_238 , V_222 , V_239 ) ;
if ( V_235 < 0 )
return V_235 ;
V_222 = V_222 / ( 1 << V_237 -> V_241 ) ;
V_237 -> V_247 = V_238 / ( V_235 * V_222 ) ;
if ( V_238 % ( V_235 * V_222 ) ) {
V_244 = F_67 ( V_238 , V_235 * V_222 ) ;
F_59 ( V_220 , L_38 , V_244 ) ;
V_237 -> V_248 = ( V_238 - ( V_237 -> V_247 * V_235 * V_222 ) )
/ V_244 ;
V_237 -> V_249 = ( V_235 * V_222 ) / V_244 ;
} else {
V_237 -> V_248 = 0 ;
V_237 -> V_249 = 0 ;
}
while ( V_237 -> V_249 >= ( 1 << 16 ) ) {
V_237 -> V_248 >>= 1 ;
V_237 -> V_249 >>= 1 ;
}
for ( V_42 = 0 ; V_42 < F_21 ( V_250 ) ; V_42 ++ ) {
if ( V_250 [ V_42 ] . V_233 <= V_222 && V_222 <= V_250 [ V_42 ] . V_234 ) {
V_237 -> V_251 = V_250 [ V_42 ] . V_251 ;
break;
}
}
if ( V_42 == F_21 ( V_250 ) ) {
F_62 ( V_220 , L_39 ,
V_222 ) ;
return - V_68 ;
}
F_59 ( V_220 , L_40 ,
V_237 -> V_247 , V_237 -> V_248 , V_237 -> V_249 ) ;
F_59 ( V_220 , L_41 ,
V_237 -> V_231 , V_237 -> V_231 , V_237 -> V_246 , V_237 -> V_241 ) ;
F_59 ( V_220 , L_42 , V_237 -> V_251 ) ;
return 0 ;
}
static void F_68 ( struct V_8 * V_8 , unsigned int V_112 ,
struct V_236 * V_237 , int V_88 ,
bool V_239 )
{
F_7 ( V_8 -> V_19 , V_112 + 3 ,
V_252 , V_237 -> V_248 ) ;
F_7 ( V_8 -> V_19 , V_112 + 4 ,
V_253 , V_237 -> V_249 ) ;
F_7 ( V_8 -> V_19 , V_112 + 5 ,
V_254 ,
V_237 -> V_231 << V_255 ) ;
F_7 ( V_8 -> V_19 , V_112 + 6 ,
V_256 |
V_257 ,
V_237 -> V_241 << V_258 |
V_88 << V_259 ) ;
if ( V_239 ) {
F_13 ( V_8 -> V_19 , V_112 + 0x7 ,
V_260 ,
V_237 -> V_251 << V_261 ) ;
} else {
F_13 ( V_8 -> V_19 , V_112 + 0x5 ,
V_262 ,
V_237 -> V_246 << V_263 ) ;
F_13 ( V_8 -> V_19 , V_112 + 0x9 ,
V_260 ,
V_237 -> V_251 << V_261 ) ;
}
F_7 ( V_8 -> V_19 , V_112 + 2 ,
V_264 | V_265 ,
V_264 | V_237 -> V_247 ) ;
}
static int F_69 ( struct V_219 * V_220 )
{
struct V_8 * V_8 = V_220 -> V_8 ;
unsigned int V_56 ;
int V_31 ;
V_31 = F_10 ( V_8 -> V_19 , V_220 -> V_112 + 1 , & V_56 ) ;
if ( V_31 != 0 ) {
F_62 ( V_220 , L_43 ,
V_31 ) ;
return V_31 ;
}
return V_56 & V_266 ;
}
static int F_70 ( struct V_219 * V_220 )
{
struct V_8 * V_8 = V_220 -> V_8 ;
int V_31 ;
bool V_267 = false ;
int V_268 = F_69 ( V_220 ) ;
struct V_236 V_237 ;
if ( V_268 < 0 )
return V_268 ;
if ( V_268 ) {
F_7 ( V_220 -> V_8 -> V_19 , V_220 -> V_112 + 0x7 ,
V_260 , 0 ) ;
F_7 ( V_220 -> V_8 -> V_19 , V_220 -> V_112 + 1 ,
V_269 ,
V_269 ) ;
}
if ( V_220 -> V_270 >= 0 && V_220 -> V_271 &&
V_220 -> V_270 != V_220 -> V_272 ) {
F_66 ( V_220 , & V_237 , V_220 -> V_271 , false ) ;
F_68 ( V_8 , V_220 -> V_112 , & V_237 , V_220 -> V_270 ,
false ) ;
if ( V_220 -> V_272 >= 0 ) {
F_66 ( V_220 , & V_237 , V_220 -> V_273 , true ) ;
F_68 ( V_8 , V_220 -> V_112 + 0x10 , & V_237 ,
V_220 -> V_272 , true ) ;
V_267 = true ;
}
} else if ( V_220 -> V_272 >= 0 ) {
F_66 ( V_220 , & V_237 , V_220 -> V_273 , false ) ;
F_68 ( V_8 , V_220 -> V_112 , & V_237 ,
V_220 -> V_272 , false ) ;
F_7 ( V_8 -> V_19 , V_220 -> V_112 + 0x11 ,
V_274 , 0 ) ;
} else {
F_62 ( V_220 , L_44 ) ;
return - V_68 ;
}
if ( V_267 && V_220 -> V_273 > 100000 )
F_7 ( V_8 -> V_19 , V_220 -> V_112 + 0x17 ,
V_275 , 0 ) ;
else
F_7 ( V_8 -> V_19 , V_220 -> V_112 + 0x17 ,
V_275 ,
V_275 ) ;
if ( ! V_268 )
F_71 ( V_8 -> V_9 ) ;
F_72 ( & V_220 -> V_221 ) ;
F_7 ( V_8 -> V_19 , V_220 -> V_112 + 1 ,
V_266 , V_266 ) ;
if ( V_267 )
F_7 ( V_8 -> V_19 , V_220 -> V_112 + 0x11 ,
V_274 ,
V_274 ) ;
if ( V_268 )
F_7 ( V_8 -> V_19 , V_220 -> V_112 + 1 ,
V_269 , 0 ) ;
V_31 = F_73 ( & V_220 -> V_221 ,
F_74 ( 250 ) ) ;
if ( V_31 == 0 )
F_65 ( V_220 , L_45 ) ;
return 0 ;
}
static void F_75 ( struct V_219 * V_220 )
{
struct V_8 * V_8 = V_220 -> V_8 ;
bool V_276 ;
F_7 ( V_8 -> V_19 , V_220 -> V_112 + 1 ,
V_269 , V_269 ) ;
F_76 ( V_8 -> V_19 , V_220 -> V_112 + 1 ,
V_266 , 0 , & V_276 ) ;
F_13 ( V_8 -> V_19 , V_220 -> V_112 + 0x11 ,
V_274 , 0 ) ;
F_7 ( V_8 -> V_19 , V_220 -> V_112 + 1 ,
V_269 , 0 ) ;
if ( V_276 )
F_77 ( V_8 -> V_9 ) ;
}
int F_78 ( struct V_219 * V_220 , int V_88 ,
unsigned int V_222 , unsigned int V_223 )
{
int V_31 = 0 ;
if ( V_220 -> V_270 == V_88 && V_220 -> V_271 == V_222 )
return 0 ;
if ( V_220 -> V_225 && V_222 > 0 ) {
V_31 = F_61 ( V_220 , V_222 , V_220 -> V_225 ) ;
if ( V_31 != 0 )
return V_31 ;
}
V_220 -> V_270 = V_88 ;
V_220 -> V_271 = V_222 ;
if ( V_220 -> V_225 && V_222 > 0 ) {
V_31 = F_70 ( V_220 ) ;
}
return V_31 ;
}
int F_79 ( struct V_219 * V_220 , int V_88 ,
unsigned int V_222 , unsigned int V_223 )
{
int V_31 = 0 ;
if ( V_220 -> V_272 == V_88 &&
V_220 -> V_273 == V_222 && V_220 -> V_225 == V_223 )
return 0 ;
if ( V_223 ) {
if ( V_220 -> V_270 >= 0 ) {
V_31 = F_61 ( V_220 , V_220 -> V_271 , V_223 ) ;
if ( V_31 != 0 )
return V_31 ;
}
V_31 = F_61 ( V_220 , V_222 , V_223 ) ;
if ( V_31 != 0 )
return V_31 ;
}
V_220 -> V_272 = V_88 ;
V_220 -> V_273 = V_222 ;
V_220 -> V_225 = V_223 ;
if ( V_223 )
V_31 = F_70 ( V_220 ) ;
else
F_75 ( V_220 ) ;
return V_31 ;
}
int F_80 ( struct V_8 * V_8 , int V_142 , int V_112 , int V_277 ,
int V_278 , struct V_219 * V_220 )
{
int V_31 ;
unsigned int V_14 ;
F_81 ( & V_220 -> V_221 ) ;
V_220 -> V_142 = V_142 ;
V_220 -> V_112 = V_112 ;
V_220 -> V_8 = V_8 ;
V_220 -> V_272 = V_279 ;
F_10 ( V_8 -> V_19 , V_280 , & V_14 ) ;
switch ( V_14 & V_281 ) {
case V_282 :
case V_283 :
V_220 -> V_270 = V_14 & V_281 ;
break;
default:
V_220 -> V_270 = V_279 ;
}
V_220 -> V_271 = 32768 ;
snprintf ( V_220 -> V_284 , sizeof( V_220 -> V_284 ) , L_46 , V_142 ) ;
snprintf ( V_220 -> V_285 , sizeof( V_220 -> V_285 ) ,
L_47 , V_142 ) ;
V_31 = F_16 ( V_8 , V_278 , V_220 -> V_285 ,
F_58 , V_220 ) ;
if ( V_31 != 0 ) {
F_11 ( V_8 -> V_9 , L_48 ,
V_142 , V_31 ) ;
}
F_13 ( V_8 -> V_19 , V_220 -> V_112 + 1 ,
V_269 , 0 ) ;
return 0 ;
}
int F_82 ( struct V_6 * V_7 , int V_286 , bool V_287 )
{
unsigned int V_56 , V_14 ;
if ( V_286 < 1 || V_286 > 6 )
return - V_68 ;
V_56 = V_288 + ( V_286 - 1 ) * 8 ;
if ( V_287 )
V_14 = V_289 ;
else
V_14 = 0 ;
return F_24 ( V_7 , V_56 , V_289 , V_14 ) ;
}
