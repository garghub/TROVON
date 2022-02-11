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
default:
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
struct V_37 * V_8 = F_16 ( V_7 ) ;
struct V_12 * V_13 = F_4 ( V_7 ) ;
struct V_9 * V_9 = V_13 -> V_9 ;
int V_32 ;
V_32 = F_17 ( V_8 , & V_38 , 1 ) ;
if ( V_32 != 0 )
return V_32 ;
switch ( V_9 -> type ) {
case V_39 :
case V_40 :
case V_41 :
break;
default:
V_32 = F_17 ( V_8 , & V_42 , 1 ) ;
if ( V_32 != 0 )
return V_32 ;
break;
}
V_32 = F_18 ( V_9 , V_43 ,
L_6 , F_10 ,
V_9 ) ;
if ( V_32 != 0 )
F_12 ( V_9 -> V_10 ,
L_7 ,
V_32 ) ;
V_32 = F_18 ( V_9 , V_44 ,
L_8 , F_13 ,
V_9 ) ;
if ( V_32 != 0 )
F_12 ( V_9 -> V_10 ,
L_9 ,
V_32 ) ;
return 0 ;
}
int F_19 ( struct V_6 * V_7 )
{
struct V_12 * V_13 = F_4 ( V_7 ) ;
struct V_9 * V_9 = V_13 -> V_9 ;
F_20 ( V_9 , V_43 , V_9 ) ;
F_20 ( V_9 , V_44 , V_9 ) ;
return 0 ;
}
int F_21 ( struct V_6 * V_7 )
{
struct V_37 * V_8 = F_16 ( V_7 ) ;
struct V_12 * V_13 = F_4 ( V_7 ) ;
struct V_9 * V_9 = V_13 -> V_9 ;
int V_45 ;
for ( V_45 = 0 ; V_45 < V_46 ; ++ V_45 ) {
if ( V_9 -> V_47 . V_48 [ V_45 ] )
F_22 ( V_8 ,
& V_49 [ V_45 ] , 1 ) ;
}
return 0 ;
}
int F_23 ( struct V_6 * V_7 )
{
struct V_37 * V_8 = F_16 ( V_7 ) ;
struct V_12 * V_13 = F_4 ( V_7 ) ;
struct V_9 * V_9 = V_13 -> V_9 ;
int V_45 ;
switch ( V_9 -> type ) {
case V_50 :
case V_51 :
F_24 ( V_8 , L_10 ) ;
break;
default:
break;
}
F_24 ( V_8 , L_11 ) ;
for ( V_45 = 0 ; V_45 < F_25 ( V_9 -> V_47 . V_52 ) ; V_45 ++ ) {
switch ( V_9 -> V_47 . V_52 [ V_45 ] & V_53 ) {
case V_54 :
F_26 ( V_8 , L_11 ) ;
break;
case V_55 :
F_26 ( V_8 , L_10 ) ;
break;
default:
break;
}
}
return 0 ;
}
const char * F_27 ( unsigned int V_56 )
{
int V_45 ;
for ( V_45 = 0 ; V_45 < F_25 ( V_57 ) ; ++ V_45 ) {
if ( V_57 [ V_45 ] == V_56 )
return V_58 [ V_45 ] ;
}
return L_12 ;
}
static void F_28 ( struct V_6 * V_7 , int V_59 )
{
struct V_12 * V_13 = F_4 ( V_7 ) ;
unsigned int V_15 ;
int V_45 ;
if ( V_59 )
V_15 = V_60 ;
else
V_15 = 0 ;
for ( V_45 = 0 ; V_45 < V_13 -> V_61 ; V_45 ++ )
F_29 ( V_7 ,
V_62 + ( V_45 * 4 ) ,
V_60 , V_15 ) ;
}
bool F_30 ( struct V_6 * V_7 , int V_27 )
{
unsigned int V_63 = V_64 + ( ( V_27 / 2 ) * 8 ) ;
unsigned int V_15 = F_6 ( V_7 , V_63 ) ;
return ! ( V_15 & V_65 ) ;
}
int F_31 ( struct V_1 * V_2 , struct V_3 * V_4 ,
int V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 -> V_8 ) ;
struct V_12 * V_13 = F_4 ( V_7 ) ;
unsigned int V_63 ;
if ( V_2 -> V_27 % 2 )
V_63 = V_62 + ( ( V_2 -> V_27 / 2 ) * 8 ) ;
else
V_63 = V_66 + ( ( V_2 -> V_27 / 2 ) * 8 ) ;
switch ( V_5 ) {
case V_18 :
V_13 -> V_67 ++ ;
break;
case V_22 :
F_29 ( V_7 , V_63 , V_68 , 0 ) ;
V_13 -> V_67 -- ;
if ( V_13 -> V_67 == 0 ) {
F_9 ( 1 ) ;
F_28 ( V_7 , 1 ) ;
}
break;
case V_28 :
F_29 ( V_7 , V_63 ,
V_68 | V_60 ,
V_68 | V_60 ) ;
break;
case V_29 :
V_63 = F_6 ( V_7 , V_69 ) ;
if ( V_63 == 0 )
F_28 ( V_7 , 0 ) ;
break;
default:
break;
}
return 0 ;
}
int F_32 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
int V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 -> V_8 ) ;
struct V_12 * V_13 = F_4 ( V_7 ) ;
switch ( V_5 ) {
case V_18 :
switch ( V_2 -> V_27 ) {
case V_70 :
case V_71 :
case V_72 :
case V_73 :
case V_74 :
case V_75 :
V_13 -> V_76 ++ ;
V_13 -> V_77 += 17 ;
break;
default:
break;
}
break;
case V_22 :
switch ( V_2 -> V_27 ) {
case V_70 :
case V_71 :
case V_72 :
case V_73 :
case V_74 :
case V_75 :
V_13 -> V_76 -- ;
if ( ! V_13 -> V_76 ) {
F_9 ( V_13 -> V_77 ) ;
V_13 -> V_77 = 0 ;
}
break;
default:
break;
}
break;
case V_28 :
switch ( V_2 -> V_27 ) {
case V_70 :
case V_71 :
case V_72 :
case V_73 :
case V_74 :
case V_75 :
V_13 -> V_78 ++ ;
V_13 -> V_79 ++ ;
break;
default:
break;
}
break;
case V_29 :
switch ( V_2 -> V_27 ) {
case V_70 :
case V_71 :
case V_72 :
case V_73 :
case V_74 :
case V_75 :
V_13 -> V_78 -- ;
if ( ! V_13 -> V_78 ) {
F_9 ( V_13 -> V_79 ) ;
V_13 -> V_79 = 0 ;
}
break;
default:
break;
}
break;
default:
break;
}
return 0 ;
}
int F_33 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
int V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 -> V_8 ) ;
struct V_12 * V_13 = F_4 ( V_7 ) ;
struct V_9 * V_9 = V_13 -> V_9 ;
unsigned int V_80 = 1 << V_2 -> V_27 ;
unsigned int V_15 ;
switch ( V_5 ) {
case V_22 :
V_15 = V_80 ;
break;
case V_28 :
V_15 = 0 ;
break;
case V_18 :
case V_29 :
return F_32 ( V_2 , V_4 , V_5 ) ;
default:
return - V_81 ;
}
V_13 -> V_9 -> V_82 &= ~ V_80 ;
V_13 -> V_9 -> V_82 |= V_15 ;
if ( V_13 -> V_9 -> V_83 )
V_15 = 0 ;
F_8 ( V_9 -> V_20 , V_26 ,
V_80 , V_15 ) ;
return F_32 ( V_2 , V_4 , V_5 ) ;
}
static int F_34 ( struct V_6 * V_7 )
{
const struct V_12 * V_13 = F_4 ( V_7 ) ;
struct V_9 * V_9 = V_13 -> V_9 ;
int V_32 ;
V_32 = F_35 ( V_9 -> V_84 , 1800000 , 1800000 ) ;
if ( V_32 ) {
F_12 ( V_7 -> V_10 , L_13 , V_32 ) ;
return V_32 ;
}
V_32 = F_14 ( V_9 -> V_20 ,
V_85 ,
V_86 ,
V_86 ) ;
if ( V_32 ) {
F_12 ( V_7 -> V_10 , L_14 , V_32 ) ;
F_35 ( V_9 -> V_84 , 1200000 , 1800000 ) ;
return V_32 ;
}
return 0 ;
}
static int F_36 ( struct V_6 * V_7 )
{
const struct V_12 * V_13 = F_4 ( V_7 ) ;
struct V_9 * V_9 = V_13 -> V_9 ;
int V_32 ;
V_32 = F_14 ( V_9 -> V_20 ,
V_85 ,
V_86 , 0 ) ;
if ( V_32 ) {
F_12 ( V_7 -> V_10 , L_15 , V_32 ) ;
return V_32 ;
}
V_32 = F_35 ( V_9 -> V_84 , 1200000 , 1800000 ) ;
if ( V_32 ) {
F_12 ( V_7 -> V_10 , L_16 , V_32 ) ;
return V_32 ;
}
return 0 ;
}
int F_37 ( struct V_6 * V_7 , unsigned int V_87 )
{
struct V_12 * V_13 = F_4 ( V_7 ) ;
int V_32 = 0 ;
F_38 ( & V_13 -> V_88 ) ;
if ( ! V_13 -> V_89 && ! V_13 -> V_90 ) {
V_32 = F_34 ( V_7 ) ;
if ( V_32 )
goto V_91;
}
V_13 -> V_90 |= V_87 ;
V_91:
F_39 ( & V_13 -> V_88 ) ;
return V_32 ;
}
int F_40 ( struct V_6 * V_7 , unsigned int V_87 )
{
struct V_12 * V_13 = F_4 ( V_7 ) ;
unsigned int V_92 ;
int V_32 = 0 ;
F_38 ( & V_13 -> V_88 ) ;
V_92 = V_13 -> V_90 ;
V_13 -> V_90 &= ~ V_87 ;
if ( ! V_13 -> V_89 && V_92 && ! V_13 -> V_90 )
V_32 = F_36 ( V_7 ) ;
F_39 ( & V_13 -> V_88 ) ;
return V_32 ;
}
int F_41 ( struct V_1 * V_2 ,
struct V_3 * V_4 , int V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 -> V_8 ) ;
struct V_12 * V_13 = F_4 ( V_7 ) ;
int V_32 = 0 ;
F_38 ( & V_13 -> V_88 ) ;
switch ( V_5 ) {
case V_22 :
if ( V_13 -> V_90 )
V_32 = F_34 ( V_7 ) ;
V_13 -> V_89 = false ;
break;
case V_28 :
V_13 -> V_89 = true ;
if ( V_13 -> V_90 )
V_32 = F_36 ( V_7 ) ;
break;
default:
break;
}
F_39 ( & V_13 -> V_88 ) ;
return V_32 ;
}
void F_42 ( struct V_12 * V_13 )
{
F_43 ( & V_13 -> V_88 ) ;
}
int F_44 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
int V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 -> V_8 ) ;
unsigned int V_15 ;
switch ( V_5 ) {
case V_22 :
V_15 = 1 << V_2 -> V_27 ;
break;
case V_28 :
V_15 = 1 << ( V_2 -> V_27 + 1 ) ;
break;
default:
return 0 ;
}
F_45 ( V_7 , V_93 , V_15 ) ;
return 0 ;
}
static int F_46 ( struct V_6 * V_7 , unsigned int V_94 ,
unsigned int V_95 )
{
struct V_12 * V_13 = F_4 ( V_7 ) ;
unsigned int V_63 ;
unsigned int * V_96 ;
int V_97 , div , V_98 ;
switch ( V_94 ) {
case V_99 :
V_63 = V_100 ;
V_98 = V_13 -> V_101 ;
break;
case V_102 :
V_63 = V_103 ;
V_98 = V_13 -> V_104 ;
break;
default:
return - V_81 ;
}
if ( V_98 % 8000 )
V_96 = V_105 ;
else
V_96 = V_106 ;
for ( V_97 = 0 ; V_97 < F_25 ( V_106 ) &&
V_96 [ V_97 ] <= V_98 ; V_97 ++ ) {
div = 1 ;
while ( V_96 [ V_97 ] / div >= V_95 && div < 32 ) {
if ( V_96 [ V_97 ] / div == V_95 ) {
F_47 ( V_7 -> V_10 , L_17 ,
V_95 ) ;
F_29 ( V_7 , V_63 ,
V_107 |
V_108 ,
( div <<
V_109 ) |
V_97 ) ;
return 0 ;
}
div ++ ;
}
}
F_12 ( V_7 -> V_10 , L_18 , V_95 ) ;
return - V_81 ;
}
int F_48 ( struct V_6 * V_7 , int V_110 ,
int V_111 , unsigned int V_95 , int V_112 )
{
struct V_12 * V_13 = F_4 ( V_7 ) ;
struct V_9 * V_9 = V_13 -> V_9 ;
char * V_113 ;
unsigned int V_63 ;
unsigned int V_80 = V_114 | V_115 ;
unsigned int V_15 = V_111 << V_116 ;
int * V_94 ;
switch ( V_110 ) {
case V_117 :
V_113 = L_19 ;
V_63 = V_118 ;
V_94 = & V_13 -> V_101 ;
V_80 |= V_119 ;
break;
case V_120 :
V_113 = L_20 ;
V_63 = V_121 ;
V_94 = & V_13 -> V_104 ;
break;
case V_99 :
case V_102 :
return F_46 ( V_7 , V_110 , V_95 ) ;
default:
return - V_81 ;
}
switch ( V_95 ) {
case 5644800 :
case 6144000 :
break;
case 11289600 :
case 12288000 :
V_15 |= V_122 << V_123 ;
break;
case 22579200 :
case 24576000 :
V_15 |= V_124 << V_123 ;
break;
case 45158400 :
case 49152000 :
V_15 |= V_125 << V_123 ;
break;
case 67737600 :
case 73728000 :
V_15 |= V_126 << V_123 ;
break;
case 90316800 :
case 98304000 :
V_15 |= V_127 << V_123 ;
break;
case 135475200 :
case 147456000 :
V_15 |= V_128 << V_123 ;
break;
case 0 :
F_47 ( V_9 -> V_10 , L_21 , V_113 ) ;
* V_94 = V_95 ;
return 0 ;
default:
return - V_81 ;
}
* V_94 = V_95 ;
if ( V_95 % 6144000 )
V_15 |= V_119 ;
F_47 ( V_9 -> V_10 , L_22 , V_113 , V_95 ) ;
return F_14 ( V_9 -> V_20 , V_63 , V_80 , V_15 ) ;
}
static int F_49 ( struct V_129 * V_130 , unsigned int V_131 )
{
struct V_6 * V_7 = V_130 -> V_7 ;
struct V_12 * V_13 = F_4 ( V_7 ) ;
struct V_9 * V_9 = V_13 -> V_9 ;
int V_132 , V_133 , V_134 , V_135 ;
V_135 = V_130 -> V_136 -> V_135 ;
V_132 = 0 ;
V_133 = 0 ;
switch ( V_131 & V_137 ) {
case V_138 :
V_134 = V_139 ;
break;
case V_140 :
if ( ( V_131 & V_141 )
!= V_142 ) {
F_50 ( V_130 , L_23 ) ;
return - V_81 ;
}
V_134 = V_143 ;
break;
case V_144 :
V_134 = V_145 ;
break;
case V_146 :
if ( ( V_131 & V_141 )
!= V_142 ) {
F_50 ( V_130 , L_24 ) ;
return - V_81 ;
}
V_134 = V_147 ;
break;
default:
F_50 ( V_130 , L_25 ,
V_131 & V_137 ) ;
return - V_81 ;
}
switch ( V_131 & V_141 ) {
case V_148 :
break;
case V_149 :
V_132 |= V_150 ;
break;
case V_151 :
V_133 |= V_152 ;
break;
case V_142 :
V_133 |= V_152 ;
V_132 |= V_150 ;
break;
default:
F_50 ( V_130 , L_26 ,
V_131 & V_141 ) ;
return - V_81 ;
}
switch ( V_131 & V_153 ) {
case V_154 :
break;
case V_155 :
V_133 |= V_156 ;
V_132 |= V_157 ;
break;
case V_158 :
V_133 |= V_156 ;
break;
case V_159 :
V_132 |= V_157 ;
break;
default:
return - V_81 ;
}
F_8 ( V_9 -> V_20 , V_135 + V_160 ,
V_156 |
V_152 ,
V_133 ) ;
F_8 ( V_9 -> V_20 , V_135 + V_161 ,
V_157 |
V_150 , V_132 ) ;
F_8 ( V_9 -> V_20 ,
V_135 + V_162 ,
V_163 |
V_164 , V_132 ) ;
F_14 ( V_9 -> V_20 , V_135 + V_165 ,
V_166 , V_134 ) ;
return 0 ;
}
static int F_51 ( struct V_167 * V_168 ,
struct V_129 * V_130 )
{
struct V_6 * V_7 = V_130 -> V_7 ;
struct V_12 * V_13 = F_4 ( V_7 ) ;
struct V_169 * V_170 = & V_13 -> V_130 [ V_130 -> V_171 - 1 ] ;
unsigned int V_172 ;
if ( ! V_168 -> V_173 )
return 0 ;
switch ( V_170 -> V_94 ) {
case V_117 :
V_172 = V_13 -> V_101 ;
break;
case V_120 :
V_172 = V_13 -> V_104 ;
break;
default:
return 0 ;
}
if ( V_172 == 0 )
V_170 -> V_174 . V_80 = V_175 ;
else if ( V_172 % 8000 )
V_170 -> V_174 . V_80 = V_176 ;
else
V_170 -> V_174 . V_80 = V_177 ;
return F_52 ( V_168 -> V_173 , 0 ,
V_178 ,
& V_170 -> V_174 ) ;
}
static void F_53 ( struct V_6 * V_7 ,
unsigned int V_179 )
{
struct V_12 * V_13 = F_4 ( V_7 ) ;
struct V_9 * V_9 = V_13 -> V_9 ;
struct V_180 V_181 [] = {
{ 0x80 , 0x3 } ,
{ V_182 , 0 } ,
{ V_183 , 0 } ,
{ 0x80 , 0x0 } ,
} ;
F_38 ( & V_9 -> V_184 ) ;
V_181 [ 1 ] . V_185 = V_9 -> V_186 ;
if ( V_179 >= 176400 )
V_181 [ 2 ] . V_185 = V_9 -> V_187 ;
F_39 ( & V_9 -> V_184 ) ;
F_54 ( V_9 -> V_20 ,
V_181 ,
F_25 ( V_181 ) ) ;
}
static int F_55 ( struct V_167 * V_168 ,
struct V_188 * V_189 ,
struct V_129 * V_130 )
{
struct V_6 * V_7 = V_130 -> V_7 ;
struct V_12 * V_13 = F_4 ( V_7 ) ;
struct V_169 * V_170 = & V_13 -> V_130 [ V_130 -> V_171 - 1 ] ;
int V_135 = V_130 -> V_136 -> V_135 ;
int V_45 , V_190 , V_32 ;
for ( V_45 = 0 ; V_45 < F_25 ( V_191 ) ; V_45 ++ )
if ( V_191 [ V_45 ] == F_56 ( V_189 ) )
break;
if ( V_45 == F_25 ( V_191 ) ) {
F_50 ( V_130 , L_27 ,
F_56 ( V_189 ) ) ;
return - V_81 ;
}
V_190 = V_45 ;
switch ( V_13 -> V_9 -> type ) {
case V_16 :
case V_39 :
if ( V_191 [ V_190 ] >= 88200 )
V_32 = F_37 ( V_7 , V_192 ) ;
else
V_32 = F_40 ( V_7 , V_192 ) ;
if ( V_32 ) {
F_50 ( V_130 , L_28 , V_32 ) ;
return V_32 ;
}
break;
default:
break;
}
switch ( V_170 -> V_94 ) {
case V_117 :
switch ( V_13 -> V_9 -> type ) {
case V_16 :
F_53 ( V_7 ,
F_56 ( V_189 ) ) ;
break;
default:
break;
}
F_29 ( V_7 , V_193 ,
V_194 , V_190 ) ;
if ( V_135 )
F_29 ( V_7 , V_135 + V_195 ,
V_196 , 0 ) ;
break;
case V_120 :
F_29 ( V_7 , V_197 ,
V_198 , V_190 ) ;
if ( V_135 )
F_29 ( V_7 , V_135 + V_195 ,
V_196 ,
8 << V_199 ) ;
break;
default:
F_50 ( V_130 , L_29 , V_170 -> V_94 ) ;
return - V_81 ;
}
return 0 ;
}
static bool F_57 ( struct V_6 * V_7 ,
int V_135 , int V_133 , int V_132 , int V_200 )
{
int V_15 ;
V_15 = F_6 ( V_7 , V_135 + V_160 ) ;
if ( V_133 != ( V_15 & V_201 ) )
return true ;
V_15 = F_6 ( V_7 , V_135 + V_202 ) ;
if ( V_132 != ( V_15 & V_203 ) )
return true ;
V_15 = F_6 ( V_7 , V_135 + V_204 ) ;
if ( V_200 != ( V_15 & ( V_205 |
V_206 ) ) )
return true ;
return false ;
}
static int F_58 ( struct V_167 * V_168 ,
struct V_188 * V_189 ,
struct V_129 * V_130 )
{
struct V_6 * V_7 = V_130 -> V_7 ;
struct V_12 * V_13 = F_4 ( V_7 ) ;
struct V_9 * V_9 = V_13 -> V_9 ;
int V_135 = V_130 -> V_136 -> V_135 ;
const int * V_96 ;
int V_45 , V_32 , V_15 ;
int V_207 = F_59 ( V_189 ) ;
int V_208 = V_9 -> V_47 . V_209 [ V_130 -> V_171 - 1 ] ;
int V_210 = V_9 -> V_210 [ V_130 -> V_171 - 1 ] ;
int V_211 = V_9 -> V_211 [ V_130 -> V_171 - 1 ] ;
int V_133 , V_132 , V_212 , V_200 , V_213 ;
bool V_214 ;
unsigned int V_215 , V_216 ;
if ( F_56 ( V_189 ) % 4000 )
V_96 = & V_217 [ 0 ] ;
else
V_96 = & V_218 [ 0 ] ;
V_212 = F_60 ( V_189 ) ;
if ( V_211 ) {
F_61 ( V_130 , L_30 ,
V_211 , V_210 ) ;
V_213 = V_211 * V_210 * F_56 ( V_189 ) ;
V_207 = V_211 ;
} else {
V_213 = F_62 ( V_189 ) ;
V_210 = V_212 ;
}
if ( V_208 && V_208 < V_207 ) {
F_61 ( V_130 , L_31 , V_208 ) ;
V_213 /= V_207 ;
V_213 *= V_208 ;
}
V_15 = F_6 ( V_7 , V_135 + V_165 ) ;
V_15 &= V_166 ;
if ( ( V_207 & 1 ) && ( V_15 == V_145 ) ) {
F_61 ( V_130 , L_32 ) ;
V_213 /= V_207 ;
V_213 *= V_207 + 1 ;
}
for ( V_45 = 0 ; V_45 < F_25 ( V_217 ) ; V_45 ++ ) {
if ( V_96 [ V_45 ] >= V_213 &&
V_96 [ V_45 ] % F_56 ( V_189 ) == 0 ) {
V_133 = V_45 ;
break;
}
}
if ( V_45 == F_25 ( V_217 ) ) {
F_50 ( V_130 , L_27 ,
F_56 ( V_189 ) ) ;
return - V_81 ;
}
V_132 = V_96 [ V_133 ] / F_56 ( V_189 ) ;
F_61 ( V_130 , L_33 ,
V_96 [ V_133 ] , V_96 [ V_133 ] / V_132 ) ;
V_200 = V_212 << V_219 | V_210 ;
V_214 = F_57 ( V_7 , V_135 , V_133 , V_132 , V_200 ) ;
if ( V_214 ) {
V_215 = F_6 ( V_7 ,
V_135 + V_220 ) ;
V_216 = F_6 ( V_7 ,
V_135 + V_221 ) ;
F_8 ( V_9 -> V_20 ,
V_135 + V_220 , 0xff , 0x0 ) ;
F_14 ( V_9 -> V_20 ,
V_135 + V_221 , 0xff , 0x0 ) ;
}
V_32 = F_55 ( V_168 , V_189 , V_130 ) ;
if ( V_32 != 0 )
goto V_222;
if ( V_214 ) {
F_8 ( V_9 -> V_20 ,
V_135 + V_160 ,
V_201 , V_133 ) ;
F_8 ( V_9 -> V_20 ,
V_135 + V_202 ,
V_203 , V_132 ) ;
F_8 ( V_9 -> V_20 ,
V_135 + V_223 ,
V_224 , V_132 ) ;
F_8 ( V_9 -> V_20 ,
V_135 + V_204 ,
V_205 |
V_206 , V_200 ) ;
F_14 ( V_9 -> V_20 ,
V_135 + V_225 ,
V_226 |
V_227 , V_200 ) ;
}
V_222:
if ( V_214 ) {
F_8 ( V_9 -> V_20 ,
V_135 + V_220 ,
0xff , V_215 ) ;
F_14 ( V_9 -> V_20 ,
V_135 + V_221 ,
0xff , V_216 ) ;
}
return V_32 ;
}
static const char * F_63 ( int V_110 )
{
switch ( V_110 ) {
case V_117 :
return L_19 ;
case V_120 :
return L_20 ;
default:
return L_34 ;
}
}
static int F_64 ( struct V_129 * V_130 ,
int V_110 , unsigned int V_95 , int V_112 )
{
struct V_6 * V_7 = V_130 -> V_7 ;
struct V_37 * V_8 = F_16 ( V_7 ) ;
struct V_12 * V_13 = F_4 ( V_7 ) ;
struct V_169 * V_170 = & V_13 -> V_130 [ V_130 -> V_171 - 1 ] ;
struct V_228 V_229 [ 2 ] ;
switch ( V_110 ) {
case V_117 :
case V_120 :
break;
default:
return - V_81 ;
}
if ( V_110 == V_170 -> V_94 )
return 0 ;
if ( V_130 -> V_230 ) {
F_12 ( V_7 -> V_10 , L_35 ,
V_130 -> V_171 ) ;
return - V_25 ;
}
F_47 ( V_7 -> V_10 , L_36 , V_130 -> V_171 + 1 ,
F_63 ( V_110 ) ) ;
memset ( & V_229 , 0 , sizeof( V_229 ) ) ;
V_229 [ 0 ] . V_231 = V_130 -> V_136 -> V_232 . V_233 ;
V_229 [ 1 ] . V_231 = V_130 -> V_136 -> V_234 . V_233 ;
V_229 [ 0 ] . V_111 = F_63 ( V_170 -> V_94 ) ;
V_229 [ 1 ] . V_111 = F_63 ( V_170 -> V_94 ) ;
F_65 ( V_8 , V_229 , F_25 ( V_229 ) ) ;
V_229 [ 0 ] . V_111 = F_63 ( V_110 ) ;
V_229 [ 1 ] . V_111 = F_63 ( V_110 ) ;
F_22 ( V_8 , V_229 , F_25 ( V_229 ) ) ;
V_170 -> V_94 = V_110 ;
return F_66 ( V_8 ) ;
}
static int F_67 ( struct V_129 * V_130 , int V_235 )
{
struct V_6 * V_7 = V_130 -> V_7 ;
int V_135 = V_130 -> V_136 -> V_135 ;
unsigned int V_63 ;
if ( V_235 )
V_63 = V_236 ;
else
V_63 = 0 ;
return F_29 ( V_7 , V_135 + V_195 ,
V_236 , V_63 ) ;
}
static void F_68 ( struct V_129 * V_130 ,
unsigned int V_135 ,
int V_207 , unsigned int V_80 )
{
struct V_6 * V_7 = V_130 -> V_7 ;
struct V_12 * V_13 = F_4 ( V_7 ) ;
struct V_9 * V_9 = V_13 -> V_9 ;
int V_237 , V_45 ;
for ( V_45 = 0 ; V_45 < V_207 ; ++ V_45 ) {
V_237 = F_69 ( V_80 ) - 1 ;
if ( V_237 < 0 )
return;
F_70 ( V_9 -> V_20 , V_135 + V_45 , V_237 ) ;
V_80 &= ~ ( 1 << V_237 ) ;
}
if ( V_80 )
F_71 ( V_130 , L_37 ) ;
}
static int F_72 ( struct V_129 * V_130 , unsigned int V_238 ,
unsigned int V_239 , int V_240 , int V_241 )
{
struct V_6 * V_7 = V_130 -> V_7 ;
struct V_12 * V_13 = F_4 ( V_7 ) ;
struct V_9 * V_9 = V_13 -> V_9 ;
int V_135 = V_130 -> V_136 -> V_135 ;
int V_242 = V_130 -> V_136 -> V_234 . V_243 ;
int V_244 = V_130 -> V_136 -> V_232 . V_243 ;
if ( V_130 -> V_171 > V_245 )
return - V_246 ;
if ( V_240 == 0 ) {
V_238 = ( 1 << V_244 ) - 1 ;
V_239 = ( 1 << V_242 ) - 1 ;
}
F_68 ( V_130 , V_135 + V_247 ,
V_244 , V_238 ) ;
F_68 ( V_130 , V_135 + V_248 ,
V_242 , V_239 ) ;
V_9 -> V_210 [ V_130 -> V_171 - 1 ] = V_241 ;
V_9 -> V_211 [ V_130 -> V_171 - 1 ] = V_240 ;
return 0 ;
}
int F_73 ( struct V_12 * V_13 , int V_171 )
{
struct V_169 * V_170 = & V_13 -> V_130 [ V_171 ] ;
V_170 -> V_94 = V_117 ;
V_170 -> V_174 = V_249 ;
return 0 ;
}
static int F_74 ( struct V_250 * V_251 ,
unsigned int V_252 ,
unsigned int V_253 )
{
unsigned int V_254 ;
if ( V_251 -> V_255 && V_253 != V_251 -> V_255 ) {
F_75 ( V_251 ,
L_38 ) ;
return - V_81 ;
}
if ( V_252 / V_256 > V_257 ) {
F_75 ( V_251 ,
L_39 ,
V_252 ) ;
return - V_81 ;
}
V_254 = V_258 * V_251 -> V_259 ;
if ( V_253 * V_260 < V_254 ) {
F_75 ( V_251 , L_40 ,
V_253 ) ;
return - V_81 ;
}
return 0 ;
}
static int F_76 ( unsigned int V_252 , int * V_261 )
{
int V_45 ;
for ( V_45 = 0 ; V_45 < F_25 ( V_262 ) ; V_45 ++ ) {
if ( V_262 [ V_45 ] . V_263 <= V_252 && V_252 <= V_262 [ V_45 ] . V_264 ) {
if ( V_261 )
* V_261 = V_262 [ V_45 ] . V_261 ;
return V_262 [ V_45 ] . V_265 ;
}
}
return - V_81 ;
}
static int F_77 ( struct V_250 * V_251 ,
struct V_266 * V_267 ,
unsigned int V_268 ,
unsigned int V_252 , bool V_269 )
{
int V_270 , V_265 ;
int V_271 , div ;
div = 1 ;
V_267 -> V_271 = 0 ;
while ( V_252 > V_257 ) {
div *= 2 ;
V_252 /= 2 ;
V_267 -> V_271 ++ ;
if ( div > V_256 )
return - V_81 ;
}
V_270 = F_76 ( V_252 , & V_267 -> V_261 ) ;
if ( V_270 < 0 ) {
F_75 ( V_251 , L_41 ,
V_252 ) ;
return V_270 ;
}
switch ( V_251 -> V_9 -> type ) {
case V_16 :
case V_39 :
return V_270 ;
case V_50 :
case V_51 :
if ( V_251 -> V_9 -> V_17 < 3 || V_269 )
return V_270 ;
break;
default:
if ( V_269 )
return V_270 ;
break;
}
V_267 -> V_261 = V_270 - 1 ;
V_271 = V_267 -> V_271 ;
F_78 ( V_251 , L_42 ,
V_270 , V_252 , V_271 ) ;
while ( div <= V_256 ) {
for ( V_265 = V_270 ; V_265 > 0 ; V_265 -- ) {
if ( V_268 % ( V_265 * V_252 ) ) {
V_267 -> V_271 = V_271 ;
V_267 -> V_261 = V_265 - 1 ;
F_78 ( V_251 ,
L_43 ,
V_252 , V_271 , div , V_265 ) ;
return V_265 ;
}
}
for ( V_265 = V_270 + 1 ; V_265 <= V_272 ;
V_265 ++ ) {
if ( ( V_273 / 2 ) /
( V_251 -> V_259 * V_265 ) < V_252 ) {
F_78 ( V_251 , L_44 ) ;
break;
}
if ( V_252 > V_274 [ V_265 - 1 ] ) {
F_78 ( V_251 ,
L_45 ,
V_274 [ V_265 - 1 ] ,
V_265 ) ;
break;
}
if ( V_268 % ( V_265 * V_252 ) ) {
V_267 -> V_271 = V_271 ;
V_267 -> V_261 = V_265 - 1 ;
F_78 ( V_251 ,
L_43 ,
V_252 , V_271 , div , V_265 ) ;
return V_265 ;
}
}
div *= 2 ;
V_252 /= 2 ;
V_271 ++ ;
V_270 = F_76 ( V_252 , NULL ) ;
F_78 ( V_251 ,
L_46 ,
V_252 , V_271 , div , V_270 ) ;
}
F_79 ( V_251 , L_47 ) ;
return V_267 -> V_261 + 1 ;
}
static int F_80 ( struct V_250 * V_251 ,
struct V_266 * V_267 ,
unsigned int V_252 , bool V_269 )
{
unsigned int V_268 , div , V_275 ;
int V_45 , V_265 ;
F_78 ( V_251 , L_48 , V_252 , V_251 -> V_255 ) ;
div = V_276 ;
while ( V_251 -> V_255 * div < V_258 * V_251 -> V_259 ) {
div ++ ;
if ( div > V_260 )
return - V_81 ;
}
V_268 = V_251 -> V_255 * div / V_251 -> V_259 ;
V_267 -> V_277 = div ;
F_78 ( V_251 , L_49 , V_268 ) ;
V_265 = F_77 ( V_251 , V_267 , V_268 , V_252 , V_269 ) ;
if ( V_265 < 0 )
return V_265 ;
V_252 = V_252 / ( 1 << V_267 -> V_271 ) ;
V_267 -> V_278 = V_268 / ( V_265 * V_252 ) ;
if ( V_268 % ( V_265 * V_252 ) ) {
V_275 = F_81 ( V_268 , V_265 * V_252 ) ;
F_78 ( V_251 , L_50 , V_275 ) ;
V_267 -> V_279 = ( V_268 - ( V_267 -> V_278 * V_265 * V_252 ) )
/ V_275 ;
V_267 -> V_280 = ( V_265 * V_252 ) / V_275 ;
} else {
V_267 -> V_279 = 0 ;
V_267 -> V_280 = 0 ;
}
while ( V_267 -> V_280 >= ( 1 << 16 ) ) {
V_267 -> V_279 >>= 1 ;
V_267 -> V_280 >>= 1 ;
}
for ( V_45 = 0 ; V_45 < F_25 ( V_281 ) ; V_45 ++ ) {
if ( V_281 [ V_45 ] . V_263 <= V_252 && V_252 <= V_281 [ V_45 ] . V_264 ) {
V_267 -> V_282 = V_281 [ V_45 ] . V_282 ;
break;
}
}
if ( V_45 == F_25 ( V_281 ) ) {
F_75 ( V_251 , L_51 ,
V_252 ) ;
return - V_81 ;
}
F_78 ( V_251 , L_52 ,
V_267 -> V_278 , V_267 -> V_279 , V_267 -> V_280 ) ;
F_78 ( V_251 , L_53 ,
V_267 -> V_261 , V_265 , V_267 -> V_277 ,
V_267 -> V_271 , 1 << V_267 -> V_271 ) ;
F_78 ( V_251 , L_54 , V_267 -> V_282 , 1 << V_267 -> V_282 ) ;
return 0 ;
}
static void F_82 ( struct V_9 * V_9 , unsigned int V_135 ,
struct V_266 * V_267 , int V_111 ,
bool V_269 )
{
F_8 ( V_9 -> V_20 , V_135 + 3 ,
V_283 , V_267 -> V_279 ) ;
F_8 ( V_9 -> V_20 , V_135 + 4 ,
V_284 , V_267 -> V_280 ) ;
F_8 ( V_9 -> V_20 , V_135 + 5 ,
V_285 ,
V_267 -> V_261 << V_286 ) ;
F_8 ( V_9 -> V_20 , V_135 + 6 ,
V_287 |
V_288 ,
V_267 -> V_271 << V_289 |
V_111 << V_290 ) ;
if ( V_269 ) {
F_14 ( V_9 -> V_20 , V_135 + 0x7 ,
V_291 ,
V_267 -> V_282 << V_292 ) ;
} else {
F_14 ( V_9 -> V_20 , V_135 + 0x5 ,
V_293 ,
V_267 -> V_277 << V_294 ) ;
F_14 ( V_9 -> V_20 , V_135 + 0x9 ,
V_291 ,
V_267 -> V_282 << V_292 ) ;
}
F_8 ( V_9 -> V_20 , V_135 + 2 ,
V_295 | V_296 ,
V_295 | V_267 -> V_278 ) ;
}
static int F_83 ( struct V_250 * V_251 )
{
struct V_9 * V_9 = V_251 -> V_9 ;
unsigned int V_63 ;
int V_32 ;
V_32 = F_11 ( V_9 -> V_20 , V_251 -> V_135 + 1 , & V_63 ) ;
if ( V_32 != 0 ) {
F_75 ( V_251 , L_55 ,
V_32 ) ;
return V_32 ;
}
return V_63 & V_297 ;
}
static int F_84 ( struct V_250 * V_251 )
{
struct V_9 * V_9 = V_251 -> V_9 ;
bool V_298 = false ;
int V_299 = F_83 ( V_251 ) ;
struct V_266 V_267 ;
int V_45 ;
unsigned int V_15 ;
if ( V_299 < 0 )
return V_299 ;
if ( V_299 ) {
F_8 ( V_251 -> V_9 -> V_20 , V_251 -> V_135 + 0x9 ,
V_291 , 0 ) ;
F_14 ( V_251 -> V_9 -> V_20 , V_251 -> V_135 + 1 ,
V_300 , V_300 ) ;
F_85 ( 32 ) ;
}
if ( V_251 -> V_301 >= 0 && V_251 -> V_302 &&
V_251 -> V_301 != V_251 -> V_303 ) {
F_80 ( V_251 , & V_267 , V_251 -> V_302 , false ) ;
F_82 ( V_9 , V_251 -> V_135 , & V_267 , V_251 -> V_301 ,
false ) ;
if ( V_251 -> V_303 >= 0 ) {
F_80 ( V_251 , & V_267 , V_251 -> V_304 , true ) ;
F_82 ( V_9 , V_251 -> V_135 + 0x10 , & V_267 ,
V_251 -> V_303 , true ) ;
V_298 = true ;
}
} else if ( V_251 -> V_303 >= 0 ) {
F_80 ( V_251 , & V_267 , V_251 -> V_304 , false ) ;
F_82 ( V_9 , V_251 -> V_135 , & V_267 ,
V_251 -> V_303 , false ) ;
F_8 ( V_9 -> V_20 , V_251 -> V_135 + 0x11 ,
V_305 , 0 ) ;
} else {
F_75 ( V_251 , L_56 ) ;
return - V_81 ;
}
if ( V_298 && V_251 -> V_304 > 100000 )
F_8 ( V_9 -> V_20 , V_251 -> V_135 + 0x17 ,
V_306 , 0 ) ;
else
F_8 ( V_9 -> V_20 , V_251 -> V_135 + 0x17 ,
V_306 ,
V_306 ) ;
if ( ! V_299 )
F_86 ( V_9 -> V_10 ) ;
F_8 ( V_9 -> V_20 , V_251 -> V_135 + 1 ,
V_297 , V_297 ) ;
if ( V_298 )
F_8 ( V_9 -> V_20 , V_251 -> V_135 + 0x11 ,
V_305 ,
V_305 ) ;
if ( V_299 )
F_8 ( V_9 -> V_20 , V_251 -> V_135 + 1 ,
V_300 , 0 ) ;
F_78 ( V_251 , L_57 ) ;
V_15 = 0 ;
for ( V_45 = 0 ; V_45 < 15 ; V_45 ++ ) {
if ( V_45 < 5 )
F_87 ( 200 , 400 ) ;
else
F_9 ( 20 ) ;
F_11 ( V_9 -> V_20 ,
V_307 ,
& V_15 ) ;
if ( V_15 & ( V_308 << ( V_251 -> V_171 - 1 ) ) )
break;
}
if ( V_45 == 15 )
F_79 ( V_251 , L_58 ) ;
else
F_78 ( V_251 , L_59 , V_45 ) ;
return 0 ;
}
static void F_88 ( struct V_250 * V_251 )
{
struct V_9 * V_9 = V_251 -> V_9 ;
bool V_309 ;
F_8 ( V_9 -> V_20 , V_251 -> V_135 + 1 ,
V_300 , V_300 ) ;
F_89 ( V_9 -> V_20 , V_251 -> V_135 + 1 ,
V_297 , 0 , & V_309 ) ;
F_14 ( V_9 -> V_20 , V_251 -> V_135 + 0x11 ,
V_305 , 0 ) ;
F_8 ( V_9 -> V_20 , V_251 -> V_135 + 1 ,
V_300 , 0 ) ;
if ( V_309 )
F_90 ( V_9 -> V_10 ) ;
}
int F_91 ( struct V_250 * V_251 , int V_111 ,
unsigned int V_252 , unsigned int V_253 )
{
int V_32 = 0 ;
if ( V_251 -> V_301 == V_111 && V_251 -> V_302 == V_252 )
return 0 ;
if ( V_251 -> V_255 && V_252 > 0 ) {
V_32 = F_74 ( V_251 , V_252 , V_251 -> V_255 ) ;
if ( V_32 != 0 )
return V_32 ;
}
V_251 -> V_301 = V_111 ;
V_251 -> V_302 = V_252 ;
if ( V_251 -> V_255 && V_252 > 0 ) {
V_32 = F_84 ( V_251 ) ;
}
return V_32 ;
}
int F_92 ( struct V_250 * V_251 , int V_111 ,
unsigned int V_252 , unsigned int V_253 )
{
int V_32 = 0 ;
if ( V_251 -> V_303 == V_111 &&
V_251 -> V_304 == V_252 && V_251 -> V_255 == V_253 )
return 0 ;
if ( V_253 ) {
if ( V_251 -> V_301 >= 0 ) {
V_32 = F_74 ( V_251 , V_251 -> V_302 , V_253 ) ;
if ( V_32 != 0 )
return V_32 ;
}
V_32 = F_74 ( V_251 , V_252 , V_253 ) ;
if ( V_32 != 0 )
return V_32 ;
}
V_251 -> V_303 = V_111 ;
V_251 -> V_304 = V_252 ;
V_251 -> V_255 = V_253 ;
if ( V_253 )
V_32 = F_84 ( V_251 ) ;
else
F_88 ( V_251 ) ;
return V_32 ;
}
int F_93 ( struct V_9 * V_9 , int V_171 , int V_135 , int V_310 ,
int V_311 , struct V_250 * V_251 )
{
unsigned int V_15 ;
V_251 -> V_171 = V_171 ;
V_251 -> V_135 = V_135 ;
V_251 -> V_9 = V_9 ;
V_251 -> V_303 = V_312 ;
F_11 ( V_9 -> V_20 , V_313 , & V_15 ) ;
switch ( V_15 & V_314 ) {
case V_315 :
case V_316 :
V_251 -> V_301 = V_15 & V_314 ;
break;
default:
V_251 -> V_301 = V_312 ;
}
V_251 -> V_302 = 32768 ;
snprintf ( V_251 -> V_317 , sizeof( V_251 -> V_317 ) , L_60 , V_171 ) ;
snprintf ( V_251 -> V_318 , sizeof( V_251 -> V_318 ) ,
L_61 , V_171 ) ;
F_14 ( V_9 -> V_20 , V_251 -> V_135 + 1 ,
V_300 , 0 ) ;
return 0 ;
}
int F_94 ( struct V_6 * V_7 , int V_319 , bool V_320 )
{
unsigned int V_63 , V_15 ;
if ( V_319 < 1 || V_319 > 6 )
return - V_81 ;
V_63 = V_321 + ( V_319 - 1 ) * 8 ;
if ( V_320 )
V_15 = V_322 ;
else
V_15 = 0 ;
return F_29 ( V_7 , V_63 , V_322 , V_15 ) ;
}
static bool F_95 ( bool V_134 , T_2 V_323 , T_2 V_324 )
{
T_3 V_325 = F_96 ( V_323 ) ;
T_3 V_326 = F_96 ( V_324 ) ;
if ( ! V_134 ) {
return abs ( V_325 ) >= 4096 ;
} else {
if ( abs ( V_326 ) >= 4096 )
return true ;
return ( abs ( ( V_325 << 16 ) / ( 4096 - V_326 ) ) >= 4096 << 4 ) ;
}
}
int F_97 ( struct V_3 * V_4 ,
struct V_327 * V_328 )
{
struct V_6 * V_7 = F_98 ( V_4 ) ;
struct V_9 * V_9 = F_3 ( V_7 -> V_10 -> V_11 ) ;
struct V_329 * V_189 = ( void * ) V_4 -> V_330 ;
unsigned int V_15 ;
T_2 * V_31 ;
int V_331 ;
int V_32 ;
V_331 = V_189 -> V_332 * F_99 ( V_9 -> V_20 ) ;
V_31 = F_100 ( V_328 -> V_333 . V_334 . V_31 , V_331 , V_335 | V_336 ) ;
if ( ! V_31 )
return - V_337 ;
V_31 [ 0 ] &= F_101 ( V_338 ) ;
if ( F_95 ( ! ! V_31 [ 0 ] , V_31 [ 1 ] , V_31 [ 2 ] ) ||
F_95 ( true , V_31 [ 4 ] , V_31 [ 5 ] ) ||
F_95 ( true , V_31 [ 8 ] , V_31 [ 9 ] ) ||
F_95 ( true , V_31 [ 12 ] , V_31 [ 13 ] ) ||
F_95 ( false , V_31 [ 16 ] , V_31 [ 17 ] ) ) {
F_12 ( V_9 -> V_10 , L_62 ) ;
V_32 = - V_81 ;
goto V_339;
}
V_32 = F_11 ( V_9 -> V_20 , V_189 -> V_135 , & V_15 ) ;
if ( V_32 != 0 )
goto V_339;
V_15 &= ~ V_338 ;
V_31 [ 0 ] |= F_101 ( V_15 ) ;
V_32 = F_102 ( V_9 -> V_20 , V_189 -> V_135 , V_31 , V_331 ) ;
V_339:
F_103 ( V_31 ) ;
return V_32 ;
}
int F_104 ( struct V_3 * V_4 ,
struct V_327 * V_328 )
{
struct V_6 * V_7 = F_98 ( V_4 ) ;
struct V_9 * V_9 = F_3 ( V_7 -> V_10 -> V_11 ) ;
T_2 * V_31 = ( T_2 * ) V_328 -> V_333 . V_334 . V_31 ;
T_3 V_15 = F_96 ( * V_31 ) ;
if ( abs ( V_15 ) >= 4096 ) {
F_12 ( V_9 -> V_10 , L_63 ) ;
return - V_81 ;
}
return F_105 ( V_4 , V_328 ) ;
}
