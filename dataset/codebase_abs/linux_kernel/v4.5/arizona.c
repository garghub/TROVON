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
break;
default:
V_32 = F_17 ( V_8 , & V_40 , 1 ) ;
if ( V_32 != 0 )
return V_32 ;
break;
}
V_32 = F_18 ( V_9 , V_41 ,
L_6 , F_10 ,
V_9 ) ;
if ( V_32 != 0 )
F_12 ( V_9 -> V_10 ,
L_7 ,
V_32 ) ;
V_32 = F_18 ( V_9 , V_42 ,
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
struct V_37 * V_8 = F_16 ( V_7 ) ;
struct V_12 * V_13 = F_4 ( V_7 ) ;
struct V_9 * V_9 = V_13 -> V_9 ;
int V_43 ;
for ( V_43 = 0 ; V_43 < V_44 ; ++ V_43 ) {
if ( V_9 -> V_45 . V_46 [ V_43 ] )
F_20 ( V_8 ,
& V_47 [ V_43 ] , 1 ) ;
}
return 0 ;
}
int F_21 ( struct V_6 * V_7 )
{
struct V_37 * V_8 = F_16 ( V_7 ) ;
struct V_12 * V_13 = F_4 ( V_7 ) ;
struct V_9 * V_9 = V_13 -> V_9 ;
int V_43 ;
switch ( V_9 -> type ) {
case V_48 :
case V_49 :
F_22 ( V_8 , L_10 ) ;
break;
default:
break;
}
F_22 ( V_8 , L_11 ) ;
for ( V_43 = 0 ; V_43 < F_23 ( V_9 -> V_45 . V_50 ) ; V_43 ++ ) {
switch ( V_9 -> V_45 . V_50 [ V_43 ] & V_51 ) {
case V_52 :
F_24 ( V_8 , L_11 ) ;
break;
case V_53 :
F_24 ( V_8 , L_10 ) ;
break;
default:
break;
}
}
return 0 ;
}
const char * F_25 ( unsigned int V_54 )
{
int V_43 ;
for ( V_43 = 0 ; V_43 < F_23 ( V_55 ) ; ++ V_43 ) {
if ( V_55 [ V_43 ] == V_54 )
return V_56 [ V_43 ] ;
}
return L_12 ;
}
static void F_26 ( struct V_6 * V_7 , int V_57 )
{
struct V_12 * V_13 = F_4 ( V_7 ) ;
unsigned int V_15 ;
int V_43 ;
if ( V_57 )
V_15 = V_58 ;
else
V_15 = 0 ;
for ( V_43 = 0 ; V_43 < V_13 -> V_59 ; V_43 ++ )
F_27 ( V_7 ,
V_60 + ( V_43 * 4 ) ,
V_58 , V_15 ) ;
}
bool F_28 ( struct V_6 * V_7 , int V_27 )
{
unsigned int V_61 = V_62 + ( ( V_27 / 2 ) * 8 ) ;
unsigned int V_15 = F_6 ( V_7 , V_61 ) ;
return ! ( V_15 & V_63 ) ;
}
int F_29 ( struct V_1 * V_2 , struct V_3 * V_4 ,
int V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 -> V_8 ) ;
struct V_12 * V_13 = F_4 ( V_7 ) ;
unsigned int V_61 ;
if ( V_2 -> V_27 % 2 )
V_61 = V_60 + ( ( V_2 -> V_27 / 2 ) * 8 ) ;
else
V_61 = V_64 + ( ( V_2 -> V_27 / 2 ) * 8 ) ;
switch ( V_5 ) {
case V_18 :
V_13 -> V_65 ++ ;
break;
case V_22 :
F_27 ( V_7 , V_61 , V_66 , 0 ) ;
V_13 -> V_65 -- ;
if ( V_13 -> V_65 == 0 ) {
F_9 ( 1 ) ;
F_26 ( V_7 , 1 ) ;
}
break;
case V_28 :
F_27 ( V_7 , V_61 ,
V_66 | V_58 ,
V_66 | V_58 ) ;
break;
case V_29 :
V_61 = F_6 ( V_7 , V_67 ) ;
if ( V_61 == 0 )
F_26 ( V_7 , 0 ) ;
break;
default:
break;
}
return 0 ;
}
int F_30 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
int V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 -> V_8 ) ;
struct V_12 * V_13 = F_4 ( V_7 ) ;
switch ( V_5 ) {
case V_18 :
switch ( V_2 -> V_27 ) {
case V_68 :
case V_69 :
case V_70 :
case V_71 :
case V_72 :
case V_73 :
V_13 -> V_74 ++ ;
V_13 -> V_75 += 17 ;
break;
default:
break;
}
break;
case V_22 :
switch ( V_2 -> V_27 ) {
case V_68 :
case V_69 :
case V_70 :
case V_71 :
case V_72 :
case V_73 :
V_13 -> V_74 -- ;
if ( ! V_13 -> V_74 ) {
F_9 ( V_13 -> V_75 ) ;
V_13 -> V_75 = 0 ;
}
break;
default:
break;
}
break;
case V_28 :
switch ( V_2 -> V_27 ) {
case V_68 :
case V_69 :
case V_70 :
case V_71 :
case V_72 :
case V_73 :
V_13 -> V_76 ++ ;
V_13 -> V_77 ++ ;
break;
default:
break;
}
break;
case V_29 :
switch ( V_2 -> V_27 ) {
case V_68 :
case V_69 :
case V_70 :
case V_71 :
case V_72 :
case V_73 :
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
default:
break;
}
return 0 ;
}
int F_31 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
int V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 -> V_8 ) ;
struct V_12 * V_13 = F_4 ( V_7 ) ;
struct V_9 * V_9 = V_13 -> V_9 ;
unsigned int V_78 = 1 << V_2 -> V_27 ;
unsigned int V_15 ;
switch ( V_5 ) {
case V_22 :
V_15 = V_78 ;
break;
case V_28 :
V_15 = 0 ;
break;
case V_18 :
case V_29 :
return F_30 ( V_2 , V_4 , V_5 ) ;
default:
return - V_79 ;
}
V_13 -> V_9 -> V_80 &= ~ V_78 ;
V_13 -> V_9 -> V_80 |= V_15 ;
if ( V_13 -> V_9 -> V_81 )
V_15 = 0 ;
F_8 ( V_9 -> V_20 , V_26 ,
V_78 , V_15 ) ;
return F_30 ( V_2 , V_4 , V_5 ) ;
}
static int F_32 ( struct V_6 * V_7 )
{
const struct V_12 * V_13 = F_4 ( V_7 ) ;
struct V_9 * V_9 = V_13 -> V_9 ;
int V_32 ;
V_32 = F_33 ( V_9 -> V_82 , 1800000 , 1800000 ) ;
if ( V_32 ) {
F_12 ( V_7 -> V_10 , L_13 , V_32 ) ;
return V_32 ;
}
V_32 = F_14 ( V_9 -> V_20 ,
V_83 ,
V_84 ,
V_84 ) ;
if ( V_32 ) {
F_12 ( V_7 -> V_10 , L_14 , V_32 ) ;
F_33 ( V_9 -> V_82 , 1200000 , 1800000 ) ;
return V_32 ;
}
return 0 ;
}
static int F_34 ( struct V_6 * V_7 )
{
const struct V_12 * V_13 = F_4 ( V_7 ) ;
struct V_9 * V_9 = V_13 -> V_9 ;
int V_32 ;
V_32 = F_14 ( V_9 -> V_20 ,
V_83 ,
V_84 , 0 ) ;
if ( V_32 ) {
F_12 ( V_7 -> V_10 , L_15 , V_32 ) ;
return V_32 ;
}
V_32 = F_33 ( V_9 -> V_82 , 1200000 , 1800000 ) ;
if ( V_32 ) {
F_12 ( V_7 -> V_10 , L_16 , V_32 ) ;
return V_32 ;
}
return 0 ;
}
int F_35 ( struct V_6 * V_7 , unsigned int V_85 )
{
struct V_12 * V_13 = F_4 ( V_7 ) ;
int V_32 = 0 ;
F_36 ( & V_13 -> V_86 ) ;
if ( ! V_13 -> V_87 && ! V_13 -> V_88 ) {
V_32 = F_32 ( V_7 ) ;
if ( V_32 )
goto V_89;
}
V_13 -> V_88 |= V_85 ;
V_89:
F_37 ( & V_13 -> V_86 ) ;
return V_32 ;
}
int F_38 ( struct V_6 * V_7 , unsigned int V_85 )
{
struct V_12 * V_13 = F_4 ( V_7 ) ;
unsigned int V_90 ;
int V_32 = 0 ;
F_36 ( & V_13 -> V_86 ) ;
V_90 = V_13 -> V_88 ;
V_13 -> V_88 &= ~ V_85 ;
if ( ! V_13 -> V_87 && V_90 && ! V_13 -> V_88 )
V_32 = F_34 ( V_7 ) ;
F_37 ( & V_13 -> V_86 ) ;
return V_32 ;
}
int F_39 ( struct V_1 * V_2 ,
struct V_3 * V_4 , int V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 -> V_8 ) ;
struct V_12 * V_13 = F_4 ( V_7 ) ;
int V_32 = 0 ;
F_36 ( & V_13 -> V_86 ) ;
switch ( V_5 ) {
case V_22 :
if ( V_13 -> V_88 )
V_32 = F_32 ( V_7 ) ;
V_13 -> V_87 = false ;
break;
case V_28 :
V_13 -> V_87 = true ;
if ( V_13 -> V_88 )
V_32 = F_34 ( V_7 ) ;
break;
default:
break;
}
F_37 ( & V_13 -> V_86 ) ;
return V_32 ;
}
void F_40 ( struct V_12 * V_13 )
{
F_41 ( & V_13 -> V_86 ) ;
}
int F_42 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
int V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 -> V_8 ) ;
unsigned int V_78 = 0x3 << V_2 -> V_27 ;
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
F_27 ( V_7 , V_91 , V_78 , V_15 ) ;
return 0 ;
}
static int F_43 ( struct V_6 * V_7 , unsigned int V_92 ,
unsigned int V_93 )
{
struct V_12 * V_13 = F_4 ( V_7 ) ;
unsigned int V_61 ;
unsigned int * V_94 ;
int V_95 , div , V_96 ;
switch ( V_92 ) {
case V_97 :
V_61 = V_98 ;
V_96 = V_13 -> V_99 ;
break;
case V_100 :
V_61 = V_101 ;
V_96 = V_13 -> V_102 ;
break;
default:
return - V_79 ;
}
if ( V_96 % 8000 )
V_94 = V_103 ;
else
V_94 = V_104 ;
for ( V_95 = 0 ; V_95 < F_23 ( V_104 ) &&
V_94 [ V_95 ] <= V_96 ; V_95 ++ ) {
div = 1 ;
while ( V_94 [ V_95 ] / div >= V_93 && div < 32 ) {
if ( V_94 [ V_95 ] / div == V_93 ) {
F_44 ( V_7 -> V_10 , L_17 ,
V_93 ) ;
F_27 ( V_7 , V_61 ,
V_105 |
V_106 ,
( div <<
V_107 ) |
V_95 ) ;
return 0 ;
}
div ++ ;
}
}
F_12 ( V_7 -> V_10 , L_18 , V_93 ) ;
return - V_79 ;
}
int F_45 ( struct V_6 * V_7 , int V_108 ,
int V_109 , unsigned int V_93 , int V_110 )
{
struct V_12 * V_13 = F_4 ( V_7 ) ;
struct V_9 * V_9 = V_13 -> V_9 ;
char * V_111 ;
unsigned int V_61 ;
unsigned int V_78 = V_112 | V_113 ;
unsigned int V_15 = V_109 << V_114 ;
int * V_92 ;
switch ( V_108 ) {
case V_115 :
V_111 = L_19 ;
V_61 = V_116 ;
V_92 = & V_13 -> V_99 ;
V_78 |= V_117 ;
break;
case V_118 :
V_111 = L_20 ;
V_61 = V_119 ;
V_92 = & V_13 -> V_102 ;
break;
case V_97 :
case V_100 :
return F_43 ( V_7 , V_108 , V_93 ) ;
default:
return - V_79 ;
}
switch ( V_93 ) {
case 5644800 :
case 6144000 :
break;
case 11289600 :
case 12288000 :
V_15 |= V_120 << V_121 ;
break;
case 22579200 :
case 24576000 :
V_15 |= V_122 << V_121 ;
break;
case 45158400 :
case 49152000 :
V_15 |= V_123 << V_121 ;
break;
case 67737600 :
case 73728000 :
V_15 |= V_124 << V_121 ;
break;
case 90316800 :
case 98304000 :
V_15 |= V_125 << V_121 ;
break;
case 135475200 :
case 147456000 :
V_15 |= V_126 << V_121 ;
break;
case 0 :
F_44 ( V_9 -> V_10 , L_21 , V_111 ) ;
* V_92 = V_93 ;
return 0 ;
default:
return - V_79 ;
}
* V_92 = V_93 ;
if ( V_93 % 6144000 )
V_15 |= V_117 ;
F_44 ( V_9 -> V_10 , L_22 , V_111 , V_93 ) ;
return F_14 ( V_9 -> V_20 , V_61 , V_78 , V_15 ) ;
}
static int F_46 ( struct V_127 * V_128 , unsigned int V_129 )
{
struct V_6 * V_7 = V_128 -> V_7 ;
struct V_12 * V_13 = F_4 ( V_7 ) ;
struct V_9 * V_9 = V_13 -> V_9 ;
int V_130 , V_131 , V_132 , V_133 ;
V_133 = V_128 -> V_134 -> V_133 ;
V_130 = 0 ;
V_131 = 0 ;
switch ( V_129 & V_135 ) {
case V_136 :
V_132 = V_137 ;
break;
case V_138 :
if ( ( V_129 & V_139 )
!= V_140 ) {
F_47 ( V_128 , L_23 ) ;
return - V_79 ;
}
V_132 = V_141 ;
break;
case V_142 :
V_132 = V_143 ;
break;
case V_144 :
if ( ( V_129 & V_139 )
!= V_140 ) {
F_47 ( V_128 , L_24 ) ;
return - V_79 ;
}
V_132 = V_145 ;
break;
default:
F_47 ( V_128 , L_25 ,
V_129 & V_135 ) ;
return - V_79 ;
}
switch ( V_129 & V_139 ) {
case V_146 :
break;
case V_147 :
V_130 |= V_148 ;
break;
case V_149 :
V_131 |= V_150 ;
break;
case V_140 :
V_131 |= V_150 ;
V_130 |= V_148 ;
break;
default:
F_47 ( V_128 , L_26 ,
V_129 & V_139 ) ;
return - V_79 ;
}
switch ( V_129 & V_151 ) {
case V_152 :
break;
case V_153 :
V_131 |= V_154 ;
V_130 |= V_155 ;
break;
case V_156 :
V_131 |= V_154 ;
break;
case V_157 :
V_130 |= V_155 ;
break;
default:
return - V_79 ;
}
F_8 ( V_9 -> V_20 , V_133 + V_158 ,
V_154 |
V_150 ,
V_131 ) ;
F_8 ( V_9 -> V_20 , V_133 + V_159 ,
V_155 |
V_148 , V_130 ) ;
F_8 ( V_9 -> V_20 ,
V_133 + V_160 ,
V_161 |
V_162 , V_130 ) ;
F_14 ( V_9 -> V_20 , V_133 + V_163 ,
V_164 , V_132 ) ;
return 0 ;
}
static int F_48 ( struct V_165 * V_166 ,
struct V_127 * V_128 )
{
struct V_6 * V_7 = V_128 -> V_7 ;
struct V_12 * V_13 = F_4 ( V_7 ) ;
struct V_167 * V_168 = & V_13 -> V_128 [ V_128 -> V_169 - 1 ] ;
const struct V_170 * V_171 ;
unsigned int V_172 ;
if ( ! V_166 -> V_173 )
return 0 ;
switch ( V_168 -> V_92 ) {
case V_115 :
V_172 = V_13 -> V_99 ;
break;
case V_118 :
V_172 = V_13 -> V_102 ;
break;
default:
return 0 ;
}
if ( V_172 == 0 )
return 0 ;
if ( V_172 % 8000 )
V_171 = & V_174 ;
else
V_171 = & V_175 ;
return V_170 ( V_166 -> V_173 , 0 ,
V_176 ,
V_171 ) ;
}
static void F_49 ( struct V_6 * V_7 ,
unsigned int V_177 )
{
struct V_12 * V_13 = F_4 ( V_7 ) ;
struct V_9 * V_9 = V_13 -> V_9 ;
struct V_178 V_179 [] = {
{ 0x80 , 0x3 } ,
{ V_180 , 0 } ,
{ V_181 , 0 } ,
{ 0x80 , 0x0 } ,
} ;
F_36 ( & V_9 -> V_182 ) ;
V_179 [ 1 ] . V_183 = V_9 -> V_184 ;
if ( V_177 >= 176400 )
V_179 [ 2 ] . V_183 = V_9 -> V_185 ;
F_37 ( & V_9 -> V_182 ) ;
F_50 ( V_9 -> V_20 ,
V_179 ,
F_23 ( V_179 ) ) ;
}
static int F_51 ( struct V_165 * V_166 ,
struct V_186 * V_187 ,
struct V_127 * V_128 )
{
struct V_6 * V_7 = V_128 -> V_7 ;
struct V_12 * V_13 = F_4 ( V_7 ) ;
struct V_167 * V_168 = & V_13 -> V_128 [ V_128 -> V_169 - 1 ] ;
int V_133 = V_128 -> V_134 -> V_133 ;
int V_43 , V_188 , V_32 ;
for ( V_43 = 0 ; V_43 < F_23 ( V_189 ) ; V_43 ++ )
if ( V_189 [ V_43 ] == F_52 ( V_187 ) )
break;
if ( V_43 == F_23 ( V_189 ) ) {
F_47 ( V_128 , L_27 ,
F_52 ( V_187 ) ) ;
return - V_79 ;
}
V_188 = V_43 ;
switch ( V_13 -> V_9 -> type ) {
case V_16 :
case V_39 :
if ( V_189 [ V_188 ] >= 88200 )
V_32 = F_35 ( V_7 , V_190 ) ;
else
V_32 = F_38 ( V_7 , V_190 ) ;
if ( V_32 ) {
F_47 ( V_128 , L_28 , V_32 ) ;
return V_32 ;
}
break;
default:
break;
}
switch ( V_168 -> V_92 ) {
case V_115 :
switch ( V_13 -> V_9 -> type ) {
case V_16 :
F_49 ( V_7 ,
F_52 ( V_187 ) ) ;
break;
default:
break;
}
F_27 ( V_7 , V_191 ,
V_192 , V_188 ) ;
if ( V_133 )
F_27 ( V_7 , V_133 + V_193 ,
V_194 , 0 ) ;
break;
case V_118 :
F_27 ( V_7 , V_195 ,
V_196 , V_188 ) ;
if ( V_133 )
F_27 ( V_7 , V_133 + V_193 ,
V_194 ,
8 << V_197 ) ;
break;
default:
F_47 ( V_128 , L_29 , V_168 -> V_92 ) ;
return - V_79 ;
}
return 0 ;
}
static bool F_53 ( struct V_6 * V_7 ,
int V_133 , int V_131 , int V_130 , int V_198 )
{
int V_15 ;
V_15 = F_6 ( V_7 , V_133 + V_158 ) ;
if ( V_131 != ( V_15 & V_199 ) )
return true ;
V_15 = F_6 ( V_7 , V_133 + V_200 ) ;
if ( V_130 != ( V_15 & V_201 ) )
return true ;
V_15 = F_6 ( V_7 , V_133 + V_202 ) ;
if ( V_198 != ( V_15 & ( V_203 |
V_204 ) ) )
return true ;
return false ;
}
static int F_54 ( struct V_165 * V_166 ,
struct V_186 * V_187 ,
struct V_127 * V_128 )
{
struct V_6 * V_7 = V_128 -> V_7 ;
struct V_12 * V_13 = F_4 ( V_7 ) ;
struct V_9 * V_9 = V_13 -> V_9 ;
int V_133 = V_128 -> V_134 -> V_133 ;
const int * V_94 ;
int V_43 , V_32 , V_15 ;
int V_205 = F_55 ( V_187 ) ;
int V_206 = V_9 -> V_45 . V_207 [ V_128 -> V_169 - 1 ] ;
int V_208 = V_9 -> V_208 [ V_128 -> V_169 - 1 ] ;
int V_209 = V_9 -> V_209 [ V_128 -> V_169 - 1 ] ;
int V_131 , V_130 , V_210 , V_198 , V_211 ;
bool V_212 ;
unsigned int V_213 , V_214 ;
if ( F_52 ( V_187 ) % 4000 )
V_94 = & V_215 [ 0 ] ;
else
V_94 = & V_216 [ 0 ] ;
V_210 = F_56 ( V_187 ) ;
if ( V_209 ) {
F_57 ( V_128 , L_30 ,
V_209 , V_208 ) ;
V_211 = V_209 * V_208 * F_52 ( V_187 ) ;
V_205 = V_209 ;
} else {
V_211 = F_58 ( V_187 ) ;
V_208 = V_210 ;
}
if ( V_206 && V_206 < V_205 ) {
F_57 ( V_128 , L_31 , V_206 ) ;
V_211 /= V_205 ;
V_211 *= V_206 ;
}
V_15 = F_6 ( V_7 , V_133 + V_163 ) ;
V_15 &= V_164 ;
if ( ( V_205 & 1 ) && ( V_15 == V_143 ) ) {
F_57 ( V_128 , L_32 ) ;
V_211 /= V_205 ;
V_211 *= V_205 + 1 ;
}
for ( V_43 = 0 ; V_43 < F_23 ( V_215 ) ; V_43 ++ ) {
if ( V_94 [ V_43 ] >= V_211 &&
V_94 [ V_43 ] % F_52 ( V_187 ) == 0 ) {
V_131 = V_43 ;
break;
}
}
if ( V_43 == F_23 ( V_215 ) ) {
F_47 ( V_128 , L_27 ,
F_52 ( V_187 ) ) ;
return - V_79 ;
}
V_130 = V_94 [ V_131 ] / F_52 ( V_187 ) ;
F_57 ( V_128 , L_33 ,
V_94 [ V_131 ] , V_94 [ V_131 ] / V_130 ) ;
V_198 = V_210 << V_217 | V_208 ;
V_212 = F_53 ( V_7 , V_133 , V_131 , V_130 , V_198 ) ;
if ( V_212 ) {
V_213 = F_6 ( V_7 ,
V_133 + V_218 ) ;
V_214 = F_6 ( V_7 ,
V_133 + V_219 ) ;
F_8 ( V_9 -> V_20 ,
V_133 + V_218 , 0xff , 0x0 ) ;
F_14 ( V_9 -> V_20 ,
V_133 + V_219 , 0xff , 0x0 ) ;
}
V_32 = F_51 ( V_166 , V_187 , V_128 ) ;
if ( V_32 != 0 )
goto V_220;
if ( V_212 ) {
F_8 ( V_9 -> V_20 ,
V_133 + V_158 ,
V_199 , V_131 ) ;
F_8 ( V_9 -> V_20 ,
V_133 + V_200 ,
V_201 , V_130 ) ;
F_8 ( V_9 -> V_20 ,
V_133 + V_221 ,
V_222 , V_130 ) ;
F_8 ( V_9 -> V_20 ,
V_133 + V_202 ,
V_203 |
V_204 , V_198 ) ;
F_14 ( V_9 -> V_20 ,
V_133 + V_223 ,
V_224 |
V_225 , V_198 ) ;
}
V_220:
if ( V_212 ) {
F_8 ( V_9 -> V_20 ,
V_133 + V_218 ,
0xff , V_213 ) ;
F_14 ( V_9 -> V_20 ,
V_133 + V_219 ,
0xff , V_214 ) ;
}
return V_32 ;
}
static const char * F_59 ( int V_108 )
{
switch ( V_108 ) {
case V_115 :
return L_19 ;
case V_118 :
return L_20 ;
default:
return L_34 ;
}
}
static int F_60 ( struct V_127 * V_128 ,
int V_108 , unsigned int V_93 , int V_110 )
{
struct V_6 * V_7 = V_128 -> V_7 ;
struct V_37 * V_8 = F_16 ( V_7 ) ;
struct V_12 * V_13 = F_4 ( V_7 ) ;
struct V_167 * V_168 = & V_13 -> V_128 [ V_128 -> V_169 - 1 ] ;
struct V_226 V_227 [ 2 ] ;
switch ( V_108 ) {
case V_115 :
case V_118 :
break;
default:
return - V_79 ;
}
if ( V_108 == V_168 -> V_92 )
return 0 ;
if ( V_128 -> V_228 ) {
F_12 ( V_7 -> V_10 , L_35 ,
V_128 -> V_169 ) ;
return - V_25 ;
}
F_44 ( V_7 -> V_10 , L_36 , V_128 -> V_169 + 1 ,
F_59 ( V_108 ) ) ;
memset ( & V_227 , 0 , sizeof( V_227 ) ) ;
V_227 [ 0 ] . V_229 = V_128 -> V_134 -> V_230 . V_231 ;
V_227 [ 1 ] . V_229 = V_128 -> V_134 -> V_232 . V_231 ;
V_227 [ 0 ] . V_109 = F_59 ( V_168 -> V_92 ) ;
V_227 [ 1 ] . V_109 = F_59 ( V_168 -> V_92 ) ;
F_61 ( V_8 , V_227 , F_23 ( V_227 ) ) ;
V_227 [ 0 ] . V_109 = F_59 ( V_108 ) ;
V_227 [ 1 ] . V_109 = F_59 ( V_108 ) ;
F_20 ( V_8 , V_227 , F_23 ( V_227 ) ) ;
V_168 -> V_92 = V_108 ;
return F_62 ( V_8 ) ;
}
static int F_63 ( struct V_127 * V_128 , int V_233 )
{
struct V_6 * V_7 = V_128 -> V_7 ;
int V_133 = V_128 -> V_134 -> V_133 ;
unsigned int V_61 ;
if ( V_233 )
V_61 = V_234 ;
else
V_61 = 0 ;
return F_27 ( V_7 , V_133 + V_193 ,
V_234 , V_61 ) ;
}
static void F_64 ( struct V_127 * V_128 ,
unsigned int V_133 ,
int V_205 , unsigned int V_78 )
{
struct V_6 * V_7 = V_128 -> V_7 ;
struct V_12 * V_13 = F_4 ( V_7 ) ;
struct V_9 * V_9 = V_13 -> V_9 ;
int V_235 , V_43 ;
for ( V_43 = 0 ; V_43 < V_205 ; ++ V_43 ) {
V_235 = F_65 ( V_78 ) - 1 ;
if ( V_235 < 0 )
return;
F_66 ( V_9 -> V_20 , V_133 + V_43 , V_235 ) ;
V_78 &= ~ ( 1 << V_235 ) ;
}
if ( V_78 )
F_67 ( V_128 , L_37 ) ;
}
static int F_68 ( struct V_127 * V_128 , unsigned int V_236 ,
unsigned int V_237 , int V_238 , int V_239 )
{
struct V_6 * V_7 = V_128 -> V_7 ;
struct V_12 * V_13 = F_4 ( V_7 ) ;
struct V_9 * V_9 = V_13 -> V_9 ;
int V_133 = V_128 -> V_134 -> V_133 ;
int V_240 = V_128 -> V_134 -> V_232 . V_241 ;
int V_242 = V_128 -> V_134 -> V_230 . V_241 ;
if ( V_128 -> V_169 > V_243 )
return - V_244 ;
if ( V_238 == 0 ) {
V_236 = ( 1 << V_242 ) - 1 ;
V_237 = ( 1 << V_240 ) - 1 ;
}
F_64 ( V_128 , V_133 + V_245 ,
V_242 , V_236 ) ;
F_64 ( V_128 , V_133 + V_246 ,
V_240 , V_237 ) ;
V_9 -> V_208 [ V_128 -> V_169 - 1 ] = V_239 ;
V_9 -> V_209 [ V_128 -> V_169 - 1 ] = V_238 ;
return 0 ;
}
int F_69 ( struct V_12 * V_13 , int V_169 )
{
struct V_167 * V_168 = & V_13 -> V_128 [ V_169 ] ;
V_168 -> V_92 = V_115 ;
return 0 ;
}
static int F_70 ( struct V_247 * V_248 ,
unsigned int V_249 ,
unsigned int V_250 )
{
unsigned int V_251 ;
if ( V_248 -> V_252 && V_250 != V_248 -> V_252 ) {
F_71 ( V_248 ,
L_38 ) ;
return - V_79 ;
}
if ( V_249 / V_253 > V_254 ) {
F_71 ( V_248 ,
L_39 ,
V_249 ) ;
return - V_79 ;
}
V_251 = V_255 * V_248 -> V_256 ;
if ( V_250 * V_257 < V_251 ) {
F_71 ( V_248 , L_40 ,
V_250 ) ;
return - V_79 ;
}
return 0 ;
}
static int F_72 ( unsigned int V_249 , int * V_258 )
{
int V_43 ;
for ( V_43 = 0 ; V_43 < F_23 ( V_259 ) ; V_43 ++ ) {
if ( V_259 [ V_43 ] . V_260 <= V_249 && V_249 <= V_259 [ V_43 ] . V_261 ) {
if ( V_258 )
* V_258 = V_259 [ V_43 ] . V_258 ;
return V_259 [ V_43 ] . V_262 ;
}
}
return - V_79 ;
}
static int F_73 ( struct V_247 * V_248 ,
struct V_263 * V_264 ,
unsigned int V_265 ,
unsigned int V_249 , bool V_266 )
{
int V_267 , V_262 ;
int V_268 , div ;
div = 1 ;
V_264 -> V_268 = 0 ;
while ( V_249 > V_254 ) {
div *= 2 ;
V_249 /= 2 ;
V_264 -> V_268 ++ ;
if ( div > V_253 )
return - V_79 ;
}
V_267 = F_72 ( V_249 , & V_264 -> V_258 ) ;
if ( V_267 < 0 ) {
F_71 ( V_248 , L_41 ,
V_249 ) ;
return V_267 ;
}
switch ( V_248 -> V_9 -> type ) {
case V_16 :
case V_39 :
return V_267 ;
case V_48 :
case V_49 :
if ( V_248 -> V_9 -> V_17 < 3 || V_266 )
return V_267 ;
break;
default:
if ( V_266 )
return V_267 ;
break;
}
V_264 -> V_258 = V_267 - 1 ;
V_268 = V_264 -> V_268 ;
F_74 ( V_248 , L_42 ,
V_267 , V_249 , V_268 ) ;
while ( div <= V_253 ) {
for ( V_262 = V_267 ; V_262 <= V_269 ;
V_262 ++ ) {
if ( ( V_270 / 2 ) /
( V_248 -> V_256 * V_262 ) < V_249 ) {
F_74 ( V_248 , L_43 ) ;
break;
}
if ( V_249 > V_271 [ V_262 - 1 ] ) {
F_74 ( V_248 ,
L_44 ,
V_271 [ V_262 - 1 ] ,
V_262 ) ;
break;
}
if ( V_265 % ( V_262 * V_249 ) ) {
V_264 -> V_268 = V_268 ;
V_264 -> V_258 = V_262 - 1 ;
F_74 ( V_248 ,
L_45 ,
V_249 , V_268 , div , V_262 ) ;
return V_262 ;
}
}
for ( V_262 = V_267 - 1 ; V_262 > 0 ; V_262 -- ) {
if ( V_265 % ( V_262 * V_249 ) ) {
V_264 -> V_268 = V_268 ;
V_264 -> V_258 = V_262 - 1 ;
F_74 ( V_248 ,
L_45 ,
V_249 , V_268 , div , V_262 ) ;
return V_262 ;
}
}
div *= 2 ;
V_249 /= 2 ;
V_268 ++ ;
V_267 = F_72 ( V_249 , NULL ) ;
F_74 ( V_248 ,
L_46 ,
V_249 , V_268 , div , V_267 ) ;
}
F_75 ( V_248 , L_47 ) ;
return V_264 -> V_258 + 1 ;
}
static int F_76 ( struct V_247 * V_248 ,
struct V_263 * V_264 ,
unsigned int V_249 , bool V_266 )
{
unsigned int V_265 , div , V_272 ;
int V_43 , V_262 ;
F_74 ( V_248 , L_48 , V_249 , V_248 -> V_252 ) ;
div = V_273 ;
while ( V_248 -> V_252 * div < V_255 * V_248 -> V_256 ) {
div ++ ;
if ( div > V_257 )
return - V_79 ;
}
V_265 = V_248 -> V_252 * div / V_248 -> V_256 ;
V_264 -> V_274 = div ;
F_74 ( V_248 , L_49 , V_265 ) ;
V_262 = F_73 ( V_248 , V_264 , V_265 , V_249 , V_266 ) ;
if ( V_262 < 0 )
return V_262 ;
V_249 = V_249 / ( 1 << V_264 -> V_268 ) ;
V_264 -> V_275 = V_265 / ( V_262 * V_249 ) ;
if ( V_265 % ( V_262 * V_249 ) ) {
V_272 = F_77 ( V_265 , V_262 * V_249 ) ;
F_74 ( V_248 , L_50 , V_272 ) ;
V_264 -> V_276 = ( V_265 - ( V_264 -> V_275 * V_262 * V_249 ) )
/ V_272 ;
V_264 -> V_277 = ( V_262 * V_249 ) / V_272 ;
} else {
V_264 -> V_276 = 0 ;
V_264 -> V_277 = 0 ;
}
while ( V_264 -> V_277 >= ( 1 << 16 ) ) {
V_264 -> V_276 >>= 1 ;
V_264 -> V_277 >>= 1 ;
}
for ( V_43 = 0 ; V_43 < F_23 ( V_278 ) ; V_43 ++ ) {
if ( V_278 [ V_43 ] . V_260 <= V_249 && V_249 <= V_278 [ V_43 ] . V_261 ) {
V_264 -> V_279 = V_278 [ V_43 ] . V_279 ;
break;
}
}
if ( V_43 == F_23 ( V_278 ) ) {
F_71 ( V_248 , L_51 ,
V_249 ) ;
return - V_79 ;
}
F_74 ( V_248 , L_52 ,
V_264 -> V_275 , V_264 -> V_276 , V_264 -> V_277 ) ;
F_74 ( V_248 , L_53 ,
V_264 -> V_258 , V_264 -> V_258 , V_264 -> V_274 , V_264 -> V_268 ) ;
F_74 ( V_248 , L_54 , V_264 -> V_279 ) ;
return 0 ;
}
static void F_78 ( struct V_9 * V_9 , unsigned int V_133 ,
struct V_263 * V_264 , int V_109 ,
bool V_266 )
{
F_8 ( V_9 -> V_20 , V_133 + 3 ,
V_280 , V_264 -> V_276 ) ;
F_8 ( V_9 -> V_20 , V_133 + 4 ,
V_281 , V_264 -> V_277 ) ;
F_8 ( V_9 -> V_20 , V_133 + 5 ,
V_282 ,
V_264 -> V_258 << V_283 ) ;
F_8 ( V_9 -> V_20 , V_133 + 6 ,
V_284 |
V_285 ,
V_264 -> V_268 << V_286 |
V_109 << V_287 ) ;
if ( V_266 ) {
F_14 ( V_9 -> V_20 , V_133 + 0x7 ,
V_288 ,
V_264 -> V_279 << V_289 ) ;
} else {
F_14 ( V_9 -> V_20 , V_133 + 0x5 ,
V_290 ,
V_264 -> V_274 << V_291 ) ;
F_14 ( V_9 -> V_20 , V_133 + 0x9 ,
V_288 ,
V_264 -> V_279 << V_289 ) ;
}
F_8 ( V_9 -> V_20 , V_133 + 2 ,
V_292 | V_293 ,
V_292 | V_264 -> V_275 ) ;
}
static int F_79 ( struct V_247 * V_248 )
{
struct V_9 * V_9 = V_248 -> V_9 ;
unsigned int V_61 ;
int V_32 ;
V_32 = F_11 ( V_9 -> V_20 , V_248 -> V_133 + 1 , & V_61 ) ;
if ( V_32 != 0 ) {
F_71 ( V_248 , L_55 ,
V_32 ) ;
return V_32 ;
}
return V_61 & V_294 ;
}
static int F_80 ( struct V_247 * V_248 )
{
struct V_9 * V_9 = V_248 -> V_9 ;
bool V_295 = false ;
int V_296 = F_79 ( V_248 ) ;
struct V_263 V_264 ;
int V_43 ;
unsigned int V_15 ;
if ( V_296 < 0 )
return V_296 ;
if ( V_296 ) {
F_8 ( V_248 -> V_9 -> V_20 , V_248 -> V_133 + 0x9 ,
V_288 , 0 ) ;
F_14 ( V_248 -> V_9 -> V_20 , V_248 -> V_133 + 1 ,
V_297 , V_297 ) ;
F_81 ( 32 ) ;
}
if ( V_248 -> V_298 >= 0 && V_248 -> V_299 &&
V_248 -> V_298 != V_248 -> V_300 ) {
F_76 ( V_248 , & V_264 , V_248 -> V_299 , false ) ;
F_78 ( V_9 , V_248 -> V_133 , & V_264 , V_248 -> V_298 ,
false ) ;
if ( V_248 -> V_300 >= 0 ) {
F_76 ( V_248 , & V_264 , V_248 -> V_301 , true ) ;
F_78 ( V_9 , V_248 -> V_133 + 0x10 , & V_264 ,
V_248 -> V_300 , true ) ;
V_295 = true ;
}
} else if ( V_248 -> V_300 >= 0 ) {
F_76 ( V_248 , & V_264 , V_248 -> V_301 , false ) ;
F_78 ( V_9 , V_248 -> V_133 , & V_264 ,
V_248 -> V_300 , false ) ;
F_8 ( V_9 -> V_20 , V_248 -> V_133 + 0x11 ,
V_302 , 0 ) ;
} else {
F_71 ( V_248 , L_56 ) ;
return - V_79 ;
}
if ( V_295 && V_248 -> V_301 > 100000 )
F_8 ( V_9 -> V_20 , V_248 -> V_133 + 0x17 ,
V_303 , 0 ) ;
else
F_8 ( V_9 -> V_20 , V_248 -> V_133 + 0x17 ,
V_303 ,
V_303 ) ;
if ( ! V_296 )
F_82 ( V_9 -> V_10 ) ;
F_8 ( V_9 -> V_20 , V_248 -> V_133 + 1 ,
V_294 , V_294 ) ;
if ( V_295 )
F_8 ( V_9 -> V_20 , V_248 -> V_133 + 0x11 ,
V_302 ,
V_302 ) ;
if ( V_296 )
F_8 ( V_9 -> V_20 , V_248 -> V_133 + 1 ,
V_297 , 0 ) ;
F_74 ( V_248 , L_57 ) ;
V_15 = 0 ;
for ( V_43 = 0 ; V_43 < 15 ; V_43 ++ ) {
if ( V_43 < 5 )
F_83 ( 200 , 400 ) ;
else
F_9 ( 20 ) ;
F_11 ( V_9 -> V_20 ,
V_304 ,
& V_15 ) ;
if ( V_15 & ( V_305 << ( V_248 -> V_169 - 1 ) ) )
break;
}
if ( V_43 == 15 )
F_75 ( V_248 , L_58 ) ;
else
F_74 ( V_248 , L_59 , V_43 ) ;
return 0 ;
}
static void F_84 ( struct V_247 * V_248 )
{
struct V_9 * V_9 = V_248 -> V_9 ;
bool V_306 ;
F_8 ( V_9 -> V_20 , V_248 -> V_133 + 1 ,
V_297 , V_297 ) ;
F_85 ( V_9 -> V_20 , V_248 -> V_133 + 1 ,
V_294 , 0 , & V_306 ) ;
F_14 ( V_9 -> V_20 , V_248 -> V_133 + 0x11 ,
V_302 , 0 ) ;
F_8 ( V_9 -> V_20 , V_248 -> V_133 + 1 ,
V_297 , 0 ) ;
if ( V_306 )
F_86 ( V_9 -> V_10 ) ;
}
int F_87 ( struct V_247 * V_248 , int V_109 ,
unsigned int V_249 , unsigned int V_250 )
{
int V_32 = 0 ;
if ( V_248 -> V_298 == V_109 && V_248 -> V_299 == V_249 )
return 0 ;
if ( V_248 -> V_252 && V_249 > 0 ) {
V_32 = F_70 ( V_248 , V_249 , V_248 -> V_252 ) ;
if ( V_32 != 0 )
return V_32 ;
}
V_248 -> V_298 = V_109 ;
V_248 -> V_299 = V_249 ;
if ( V_248 -> V_252 && V_249 > 0 ) {
V_32 = F_80 ( V_248 ) ;
}
return V_32 ;
}
int F_88 ( struct V_247 * V_248 , int V_109 ,
unsigned int V_249 , unsigned int V_250 )
{
int V_32 = 0 ;
if ( V_248 -> V_300 == V_109 &&
V_248 -> V_301 == V_249 && V_248 -> V_252 == V_250 )
return 0 ;
if ( V_250 ) {
if ( V_248 -> V_298 >= 0 ) {
V_32 = F_70 ( V_248 , V_248 -> V_299 , V_250 ) ;
if ( V_32 != 0 )
return V_32 ;
}
V_32 = F_70 ( V_248 , V_249 , V_250 ) ;
if ( V_32 != 0 )
return V_32 ;
}
V_248 -> V_300 = V_109 ;
V_248 -> V_301 = V_249 ;
V_248 -> V_252 = V_250 ;
if ( V_250 )
V_32 = F_80 ( V_248 ) ;
else
F_84 ( V_248 ) ;
return V_32 ;
}
int F_89 ( struct V_9 * V_9 , int V_169 , int V_133 , int V_307 ,
int V_308 , struct V_247 * V_248 )
{
unsigned int V_15 ;
V_248 -> V_169 = V_169 ;
V_248 -> V_133 = V_133 ;
V_248 -> V_9 = V_9 ;
V_248 -> V_300 = V_309 ;
F_11 ( V_9 -> V_20 , V_310 , & V_15 ) ;
switch ( V_15 & V_311 ) {
case V_312 :
case V_313 :
V_248 -> V_298 = V_15 & V_311 ;
break;
default:
V_248 -> V_298 = V_309 ;
}
V_248 -> V_299 = 32768 ;
snprintf ( V_248 -> V_314 , sizeof( V_248 -> V_314 ) , L_60 , V_169 ) ;
snprintf ( V_248 -> V_315 , sizeof( V_248 -> V_315 ) ,
L_61 , V_169 ) ;
F_14 ( V_9 -> V_20 , V_248 -> V_133 + 1 ,
V_297 , 0 ) ;
return 0 ;
}
int F_90 ( struct V_6 * V_7 , int V_316 , bool V_317 )
{
unsigned int V_61 , V_15 ;
if ( V_316 < 1 || V_316 > 6 )
return - V_79 ;
V_61 = V_318 + ( V_316 - 1 ) * 8 ;
if ( V_317 )
V_15 = V_319 ;
else
V_15 = 0 ;
return F_27 ( V_7 , V_61 , V_319 , V_15 ) ;
}
static bool F_91 ( bool V_132 , T_2 V_320 , T_2 V_321 )
{
T_3 V_322 = F_92 ( V_320 ) ;
T_3 V_323 = F_92 ( V_321 ) ;
if ( ! V_132 ) {
return abs ( V_322 ) >= 4096 ;
} else {
if ( abs ( V_323 ) >= 4096 )
return true ;
return ( abs ( ( V_322 << 16 ) / ( 4096 - V_323 ) ) >= 4096 << 4 ) ;
}
}
int F_93 ( struct V_3 * V_4 ,
struct V_324 * V_325 )
{
struct V_6 * V_7 = F_94 ( V_4 ) ;
struct V_9 * V_9 = F_3 ( V_7 -> V_10 -> V_11 ) ;
struct V_326 * V_187 = ( void * ) V_4 -> V_327 ;
unsigned int V_15 ;
T_2 * V_31 ;
int V_328 ;
int V_32 ;
V_328 = V_187 -> V_329 * F_95 ( V_9 -> V_20 ) ;
V_31 = F_96 ( V_325 -> V_330 . V_331 . V_31 , V_328 , V_332 | V_333 ) ;
if ( ! V_31 )
return - V_334 ;
V_31 [ 0 ] &= F_97 ( V_335 ) ;
if ( F_91 ( ! ! V_31 [ 0 ] , V_31 [ 1 ] , V_31 [ 2 ] ) ||
F_91 ( true , V_31 [ 4 ] , V_31 [ 5 ] ) ||
F_91 ( true , V_31 [ 8 ] , V_31 [ 9 ] ) ||
F_91 ( true , V_31 [ 12 ] , V_31 [ 13 ] ) ||
F_91 ( false , V_31 [ 16 ] , V_31 [ 17 ] ) ) {
F_12 ( V_9 -> V_10 , L_62 ) ;
V_32 = - V_79 ;
goto V_336;
}
V_32 = F_11 ( V_9 -> V_20 , V_187 -> V_133 , & V_15 ) ;
if ( V_32 != 0 )
goto V_336;
V_15 &= ~ V_335 ;
V_31 [ 0 ] |= F_97 ( V_15 ) ;
V_32 = F_98 ( V_9 -> V_20 , V_187 -> V_133 , V_31 , V_328 ) ;
V_336:
F_99 ( V_31 ) ;
return V_32 ;
}
int F_100 ( struct V_3 * V_4 ,
struct V_324 * V_325 )
{
struct V_6 * V_7 = F_94 ( V_4 ) ;
struct V_9 * V_9 = F_3 ( V_7 -> V_10 -> V_11 ) ;
T_2 * V_31 = ( T_2 * ) V_325 -> V_330 . V_331 . V_31 ;
T_3 V_15 = F_92 ( * V_31 ) ;
if ( abs ( V_15 ) >= 4096 ) {
F_12 ( V_9 -> V_10 , L_63 ) ;
return - V_79 ;
}
return F_101 ( V_4 , V_325 ) ;
}
