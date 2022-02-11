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
struct V_12 * V_13 = F_4 ( V_7 ) ;
struct V_9 * V_9 = V_13 -> V_9 ;
F_20 ( V_9 , V_41 , V_9 ) ;
F_20 ( V_9 , V_42 , V_9 ) ;
return 0 ;
}
int F_21 ( struct V_6 * V_7 )
{
struct V_37 * V_8 = F_16 ( V_7 ) ;
struct V_12 * V_13 = F_4 ( V_7 ) ;
struct V_9 * V_9 = V_13 -> V_9 ;
int V_43 ;
for ( V_43 = 0 ; V_43 < V_44 ; ++ V_43 ) {
if ( V_9 -> V_45 . V_46 [ V_43 ] )
F_22 ( V_8 ,
& V_47 [ V_43 ] , 1 ) ;
}
return 0 ;
}
int F_23 ( struct V_6 * V_7 )
{
struct V_37 * V_8 = F_16 ( V_7 ) ;
struct V_12 * V_13 = F_4 ( V_7 ) ;
struct V_9 * V_9 = V_13 -> V_9 ;
int V_43 ;
switch ( V_9 -> type ) {
case V_48 :
case V_49 :
F_24 ( V_8 , L_10 ) ;
break;
default:
break;
}
F_24 ( V_8 , L_11 ) ;
for ( V_43 = 0 ; V_43 < F_25 ( V_9 -> V_45 . V_50 ) ; V_43 ++ ) {
switch ( V_9 -> V_45 . V_50 [ V_43 ] & V_51 ) {
case V_52 :
F_26 ( V_8 , L_11 ) ;
break;
case V_53 :
F_26 ( V_8 , L_10 ) ;
break;
default:
break;
}
}
return 0 ;
}
const char * F_27 ( unsigned int V_54 )
{
int V_43 ;
for ( V_43 = 0 ; V_43 < F_25 ( V_55 ) ; ++ V_43 ) {
if ( V_55 [ V_43 ] == V_54 )
return V_56 [ V_43 ] ;
}
return L_12 ;
}
static void F_28 ( struct V_6 * V_7 , int V_57 )
{
struct V_12 * V_13 = F_4 ( V_7 ) ;
unsigned int V_15 ;
int V_43 ;
if ( V_57 )
V_15 = V_58 ;
else
V_15 = 0 ;
for ( V_43 = 0 ; V_43 < V_13 -> V_59 ; V_43 ++ )
F_29 ( V_7 ,
V_60 + ( V_43 * 4 ) ,
V_58 , V_15 ) ;
}
bool F_30 ( struct V_6 * V_7 , int V_27 )
{
unsigned int V_61 = V_62 + ( ( V_27 / 2 ) * 8 ) ;
unsigned int V_15 = F_6 ( V_7 , V_61 ) ;
return ! ( V_15 & V_63 ) ;
}
int F_31 ( struct V_1 * V_2 , struct V_3 * V_4 ,
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
F_29 ( V_7 , V_61 , V_66 , 0 ) ;
V_13 -> V_65 -- ;
if ( V_13 -> V_65 == 0 ) {
F_9 ( 1 ) ;
F_28 ( V_7 , 1 ) ;
}
break;
case V_28 :
F_29 ( V_7 , V_61 ,
V_66 | V_58 ,
V_66 | V_58 ) ;
break;
case V_29 :
V_61 = F_6 ( V_7 , V_67 ) ;
if ( V_61 == 0 )
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
int F_33 ( struct V_1 * V_2 ,
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
return F_32 ( V_2 , V_4 , V_5 ) ;
default:
return - V_79 ;
}
V_13 -> V_9 -> V_80 &= ~ V_78 ;
V_13 -> V_9 -> V_80 |= V_15 ;
if ( V_13 -> V_9 -> V_81 )
V_15 = 0 ;
F_8 ( V_9 -> V_20 , V_26 ,
V_78 , V_15 ) ;
return F_32 ( V_2 , V_4 , V_5 ) ;
}
static int F_34 ( struct V_6 * V_7 )
{
const struct V_12 * V_13 = F_4 ( V_7 ) ;
struct V_9 * V_9 = V_13 -> V_9 ;
int V_32 ;
V_32 = F_35 ( V_9 -> V_82 , 1800000 , 1800000 ) ;
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
F_35 ( V_9 -> V_82 , 1200000 , 1800000 ) ;
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
V_83 ,
V_84 , 0 ) ;
if ( V_32 ) {
F_12 ( V_7 -> V_10 , L_15 , V_32 ) ;
return V_32 ;
}
V_32 = F_35 ( V_9 -> V_82 , 1200000 , 1800000 ) ;
if ( V_32 ) {
F_12 ( V_7 -> V_10 , L_16 , V_32 ) ;
return V_32 ;
}
return 0 ;
}
int F_37 ( struct V_6 * V_7 , unsigned int V_85 )
{
struct V_12 * V_13 = F_4 ( V_7 ) ;
int V_32 = 0 ;
F_38 ( & V_13 -> V_86 ) ;
if ( ! V_13 -> V_87 && ! V_13 -> V_88 ) {
V_32 = F_34 ( V_7 ) ;
if ( V_32 )
goto V_89;
}
V_13 -> V_88 |= V_85 ;
V_89:
F_39 ( & V_13 -> V_86 ) ;
return V_32 ;
}
int F_40 ( struct V_6 * V_7 , unsigned int V_85 )
{
struct V_12 * V_13 = F_4 ( V_7 ) ;
unsigned int V_90 ;
int V_32 = 0 ;
F_38 ( & V_13 -> V_86 ) ;
V_90 = V_13 -> V_88 ;
V_13 -> V_88 &= ~ V_85 ;
if ( ! V_13 -> V_87 && V_90 && ! V_13 -> V_88 )
V_32 = F_36 ( V_7 ) ;
F_39 ( & V_13 -> V_86 ) ;
return V_32 ;
}
int F_41 ( struct V_1 * V_2 ,
struct V_3 * V_4 , int V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 -> V_8 ) ;
struct V_12 * V_13 = F_4 ( V_7 ) ;
int V_32 = 0 ;
F_38 ( & V_13 -> V_86 ) ;
switch ( V_5 ) {
case V_22 :
if ( V_13 -> V_88 )
V_32 = F_34 ( V_7 ) ;
V_13 -> V_87 = false ;
break;
case V_28 :
V_13 -> V_87 = true ;
if ( V_13 -> V_88 )
V_32 = F_36 ( V_7 ) ;
break;
default:
break;
}
F_39 ( & V_13 -> V_86 ) ;
return V_32 ;
}
void F_42 ( struct V_12 * V_13 )
{
F_43 ( & V_13 -> V_86 ) ;
}
int F_44 ( struct V_1 * V_2 ,
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
F_29 ( V_7 , V_91 , V_78 , V_15 ) ;
return 0 ;
}
static int F_45 ( struct V_6 * V_7 , unsigned int V_92 ,
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
for ( V_95 = 0 ; V_95 < F_25 ( V_104 ) &&
V_94 [ V_95 ] <= V_96 ; V_95 ++ ) {
div = 1 ;
while ( V_94 [ V_95 ] / div >= V_93 && div < 32 ) {
if ( V_94 [ V_95 ] / div == V_93 ) {
F_46 ( V_7 -> V_10 , L_17 ,
V_93 ) ;
F_29 ( V_7 , V_61 ,
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
int F_47 ( struct V_6 * V_7 , int V_108 ,
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
return F_45 ( V_7 , V_108 , V_93 ) ;
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
F_46 ( V_9 -> V_10 , L_21 , V_111 ) ;
* V_92 = V_93 ;
return 0 ;
default:
return - V_79 ;
}
* V_92 = V_93 ;
if ( V_93 % 6144000 )
V_15 |= V_117 ;
F_46 ( V_9 -> V_10 , L_22 , V_111 , V_93 ) ;
return F_14 ( V_9 -> V_20 , V_61 , V_78 , V_15 ) ;
}
static int F_48 ( struct V_127 * V_128 , unsigned int V_129 )
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
F_49 ( V_128 , L_23 ) ;
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
F_49 ( V_128 , L_24 ) ;
return - V_79 ;
}
V_132 = V_145 ;
break;
default:
F_49 ( V_128 , L_25 ,
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
F_49 ( V_128 , L_26 ,
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
static int F_50 ( struct V_165 * V_166 ,
struct V_127 * V_128 )
{
struct V_6 * V_7 = V_128 -> V_7 ;
struct V_12 * V_13 = F_4 ( V_7 ) ;
struct V_167 * V_168 = & V_13 -> V_128 [ V_128 -> V_169 - 1 ] ;
unsigned int V_170 ;
if ( ! V_166 -> V_171 )
return 0 ;
switch ( V_168 -> V_92 ) {
case V_115 :
V_170 = V_13 -> V_99 ;
break;
case V_118 :
V_170 = V_13 -> V_102 ;
break;
default:
return 0 ;
}
if ( V_170 == 0 )
V_168 -> V_172 . V_78 = V_173 ;
else if ( V_170 % 8000 )
V_168 -> V_172 . V_78 = V_174 ;
else
V_168 -> V_172 . V_78 = V_175 ;
return F_51 ( V_166 -> V_171 , 0 ,
V_176 ,
& V_168 -> V_172 ) ;
}
static void F_52 ( struct V_6 * V_7 ,
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
F_38 ( & V_9 -> V_182 ) ;
V_179 [ 1 ] . V_183 = V_9 -> V_184 ;
if ( V_177 >= 176400 )
V_179 [ 2 ] . V_183 = V_9 -> V_185 ;
F_39 ( & V_9 -> V_182 ) ;
F_53 ( V_9 -> V_20 ,
V_179 ,
F_25 ( V_179 ) ) ;
}
static int F_54 ( struct V_165 * V_166 ,
struct V_186 * V_187 ,
struct V_127 * V_128 )
{
struct V_6 * V_7 = V_128 -> V_7 ;
struct V_12 * V_13 = F_4 ( V_7 ) ;
struct V_167 * V_168 = & V_13 -> V_128 [ V_128 -> V_169 - 1 ] ;
int V_133 = V_128 -> V_134 -> V_133 ;
int V_43 , V_188 , V_32 ;
for ( V_43 = 0 ; V_43 < F_25 ( V_189 ) ; V_43 ++ )
if ( V_189 [ V_43 ] == F_55 ( V_187 ) )
break;
if ( V_43 == F_25 ( V_189 ) ) {
F_49 ( V_128 , L_27 ,
F_55 ( V_187 ) ) ;
return - V_79 ;
}
V_188 = V_43 ;
switch ( V_13 -> V_9 -> type ) {
case V_16 :
case V_39 :
if ( V_189 [ V_188 ] >= 88200 )
V_32 = F_37 ( V_7 , V_190 ) ;
else
V_32 = F_40 ( V_7 , V_190 ) ;
if ( V_32 ) {
F_49 ( V_128 , L_28 , V_32 ) ;
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
F_52 ( V_7 ,
F_55 ( V_187 ) ) ;
break;
default:
break;
}
F_29 ( V_7 , V_191 ,
V_192 , V_188 ) ;
if ( V_133 )
F_29 ( V_7 , V_133 + V_193 ,
V_194 , 0 ) ;
break;
case V_118 :
F_29 ( V_7 , V_195 ,
V_196 , V_188 ) ;
if ( V_133 )
F_29 ( V_7 , V_133 + V_193 ,
V_194 ,
8 << V_197 ) ;
break;
default:
F_49 ( V_128 , L_29 , V_168 -> V_92 ) ;
return - V_79 ;
}
return 0 ;
}
static bool F_56 ( struct V_6 * V_7 ,
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
static int F_57 ( struct V_165 * V_166 ,
struct V_186 * V_187 ,
struct V_127 * V_128 )
{
struct V_6 * V_7 = V_128 -> V_7 ;
struct V_12 * V_13 = F_4 ( V_7 ) ;
struct V_9 * V_9 = V_13 -> V_9 ;
int V_133 = V_128 -> V_134 -> V_133 ;
const int * V_94 ;
int V_43 , V_32 , V_15 ;
int V_205 = F_58 ( V_187 ) ;
int V_206 = V_9 -> V_45 . V_207 [ V_128 -> V_169 - 1 ] ;
int V_208 = V_9 -> V_208 [ V_128 -> V_169 - 1 ] ;
int V_209 = V_9 -> V_209 [ V_128 -> V_169 - 1 ] ;
int V_131 , V_130 , V_210 , V_198 , V_211 ;
bool V_212 ;
unsigned int V_213 , V_214 ;
if ( F_55 ( V_187 ) % 4000 )
V_94 = & V_215 [ 0 ] ;
else
V_94 = & V_216 [ 0 ] ;
V_210 = F_59 ( V_187 ) ;
if ( V_209 ) {
F_60 ( V_128 , L_30 ,
V_209 , V_208 ) ;
V_211 = V_209 * V_208 * F_55 ( V_187 ) ;
V_205 = V_209 ;
} else {
V_211 = F_61 ( V_187 ) ;
V_208 = V_210 ;
}
if ( V_206 && V_206 < V_205 ) {
F_60 ( V_128 , L_31 , V_206 ) ;
V_211 /= V_205 ;
V_211 *= V_206 ;
}
V_15 = F_6 ( V_7 , V_133 + V_163 ) ;
V_15 &= V_164 ;
if ( ( V_205 & 1 ) && ( V_15 == V_143 ) ) {
F_60 ( V_128 , L_32 ) ;
V_211 /= V_205 ;
V_211 *= V_205 + 1 ;
}
for ( V_43 = 0 ; V_43 < F_25 ( V_215 ) ; V_43 ++ ) {
if ( V_94 [ V_43 ] >= V_211 &&
V_94 [ V_43 ] % F_55 ( V_187 ) == 0 ) {
V_131 = V_43 ;
break;
}
}
if ( V_43 == F_25 ( V_215 ) ) {
F_49 ( V_128 , L_27 ,
F_55 ( V_187 ) ) ;
return - V_79 ;
}
V_130 = V_94 [ V_131 ] / F_55 ( V_187 ) ;
F_60 ( V_128 , L_33 ,
V_94 [ V_131 ] , V_94 [ V_131 ] / V_130 ) ;
V_198 = V_210 << V_217 | V_208 ;
V_212 = F_56 ( V_7 , V_133 , V_131 , V_130 , V_198 ) ;
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
V_32 = F_54 ( V_166 , V_187 , V_128 ) ;
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
static const char * F_62 ( int V_108 )
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
static int F_63 ( struct V_127 * V_128 ,
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
F_46 ( V_7 -> V_10 , L_36 , V_128 -> V_169 + 1 ,
F_62 ( V_108 ) ) ;
memset ( & V_227 , 0 , sizeof( V_227 ) ) ;
V_227 [ 0 ] . V_229 = V_128 -> V_134 -> V_230 . V_231 ;
V_227 [ 1 ] . V_229 = V_128 -> V_134 -> V_232 . V_231 ;
V_227 [ 0 ] . V_109 = F_62 ( V_168 -> V_92 ) ;
V_227 [ 1 ] . V_109 = F_62 ( V_168 -> V_92 ) ;
F_64 ( V_8 , V_227 , F_25 ( V_227 ) ) ;
V_227 [ 0 ] . V_109 = F_62 ( V_108 ) ;
V_227 [ 1 ] . V_109 = F_62 ( V_108 ) ;
F_22 ( V_8 , V_227 , F_25 ( V_227 ) ) ;
V_168 -> V_92 = V_108 ;
return F_65 ( V_8 ) ;
}
static int F_66 ( struct V_127 * V_128 , int V_233 )
{
struct V_6 * V_7 = V_128 -> V_7 ;
int V_133 = V_128 -> V_134 -> V_133 ;
unsigned int V_61 ;
if ( V_233 )
V_61 = V_234 ;
else
V_61 = 0 ;
return F_29 ( V_7 , V_133 + V_193 ,
V_234 , V_61 ) ;
}
static void F_67 ( struct V_127 * V_128 ,
unsigned int V_133 ,
int V_205 , unsigned int V_78 )
{
struct V_6 * V_7 = V_128 -> V_7 ;
struct V_12 * V_13 = F_4 ( V_7 ) ;
struct V_9 * V_9 = V_13 -> V_9 ;
int V_235 , V_43 ;
for ( V_43 = 0 ; V_43 < V_205 ; ++ V_43 ) {
V_235 = F_68 ( V_78 ) - 1 ;
if ( V_235 < 0 )
return;
F_69 ( V_9 -> V_20 , V_133 + V_43 , V_235 ) ;
V_78 &= ~ ( 1 << V_235 ) ;
}
if ( V_78 )
F_70 ( V_128 , L_37 ) ;
}
static int F_71 ( struct V_127 * V_128 , unsigned int V_236 ,
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
F_67 ( V_128 , V_133 + V_245 ,
V_242 , V_236 ) ;
F_67 ( V_128 , V_133 + V_246 ,
V_240 , V_237 ) ;
V_9 -> V_208 [ V_128 -> V_169 - 1 ] = V_239 ;
V_9 -> V_209 [ V_128 -> V_169 - 1 ] = V_238 ;
return 0 ;
}
int F_72 ( struct V_12 * V_13 , int V_169 )
{
struct V_167 * V_168 = & V_13 -> V_128 [ V_169 ] ;
V_168 -> V_92 = V_115 ;
V_168 -> V_172 = V_247 ;
return 0 ;
}
static int F_73 ( struct V_248 * V_249 ,
unsigned int V_250 ,
unsigned int V_251 )
{
unsigned int V_252 ;
if ( V_249 -> V_253 && V_251 != V_249 -> V_253 ) {
F_74 ( V_249 ,
L_38 ) ;
return - V_79 ;
}
if ( V_250 / V_254 > V_255 ) {
F_74 ( V_249 ,
L_39 ,
V_250 ) ;
return - V_79 ;
}
V_252 = V_256 * V_249 -> V_257 ;
if ( V_251 * V_258 < V_252 ) {
F_74 ( V_249 , L_40 ,
V_251 ) ;
return - V_79 ;
}
return 0 ;
}
static int F_75 ( unsigned int V_250 , int * V_259 )
{
int V_43 ;
for ( V_43 = 0 ; V_43 < F_25 ( V_260 ) ; V_43 ++ ) {
if ( V_260 [ V_43 ] . V_261 <= V_250 && V_250 <= V_260 [ V_43 ] . V_262 ) {
if ( V_259 )
* V_259 = V_260 [ V_43 ] . V_259 ;
return V_260 [ V_43 ] . V_263 ;
}
}
return - V_79 ;
}
static int F_76 ( struct V_248 * V_249 ,
struct V_264 * V_265 ,
unsigned int V_266 ,
unsigned int V_250 , bool V_267 )
{
int V_268 , V_263 ;
int V_269 , div ;
div = 1 ;
V_265 -> V_269 = 0 ;
while ( V_250 > V_255 ) {
div *= 2 ;
V_250 /= 2 ;
V_265 -> V_269 ++ ;
if ( div > V_254 )
return - V_79 ;
}
V_268 = F_75 ( V_250 , & V_265 -> V_259 ) ;
if ( V_268 < 0 ) {
F_74 ( V_249 , L_41 ,
V_250 ) ;
return V_268 ;
}
switch ( V_249 -> V_9 -> type ) {
case V_16 :
case V_39 :
return V_268 ;
case V_48 :
case V_49 :
if ( V_249 -> V_9 -> V_17 < 3 || V_267 )
return V_268 ;
break;
default:
if ( V_267 )
return V_268 ;
break;
}
V_265 -> V_259 = V_268 - 1 ;
V_269 = V_265 -> V_269 ;
F_77 ( V_249 , L_42 ,
V_268 , V_250 , V_269 ) ;
while ( div <= V_254 ) {
for ( V_263 = V_268 ; V_263 <= V_270 ;
V_263 ++ ) {
if ( ( V_271 / 2 ) /
( V_249 -> V_257 * V_263 ) < V_250 ) {
F_77 ( V_249 , L_43 ) ;
break;
}
if ( V_250 > V_272 [ V_263 - 1 ] ) {
F_77 ( V_249 ,
L_44 ,
V_272 [ V_263 - 1 ] ,
V_263 ) ;
break;
}
if ( V_266 % ( V_263 * V_250 ) ) {
V_265 -> V_269 = V_269 ;
V_265 -> V_259 = V_263 - 1 ;
F_77 ( V_249 ,
L_45 ,
V_250 , V_269 , div , V_263 ) ;
return V_263 ;
}
}
for ( V_263 = V_268 - 1 ; V_263 > 0 ; V_263 -- ) {
if ( V_266 % ( V_263 * V_250 ) ) {
V_265 -> V_269 = V_269 ;
V_265 -> V_259 = V_263 - 1 ;
F_77 ( V_249 ,
L_45 ,
V_250 , V_269 , div , V_263 ) ;
return V_263 ;
}
}
div *= 2 ;
V_250 /= 2 ;
V_269 ++ ;
V_268 = F_75 ( V_250 , NULL ) ;
F_77 ( V_249 ,
L_46 ,
V_250 , V_269 , div , V_268 ) ;
}
F_78 ( V_249 , L_47 ) ;
return V_265 -> V_259 + 1 ;
}
static int F_79 ( struct V_248 * V_249 ,
struct V_264 * V_265 ,
unsigned int V_250 , bool V_267 )
{
unsigned int V_266 , div , V_273 ;
int V_43 , V_263 ;
F_77 ( V_249 , L_48 , V_250 , V_249 -> V_253 ) ;
div = V_274 ;
while ( V_249 -> V_253 * div < V_256 * V_249 -> V_257 ) {
div ++ ;
if ( div > V_258 )
return - V_79 ;
}
V_266 = V_249 -> V_253 * div / V_249 -> V_257 ;
V_265 -> V_275 = div ;
F_77 ( V_249 , L_49 , V_266 ) ;
V_263 = F_76 ( V_249 , V_265 , V_266 , V_250 , V_267 ) ;
if ( V_263 < 0 )
return V_263 ;
V_250 = V_250 / ( 1 << V_265 -> V_269 ) ;
V_265 -> V_276 = V_266 / ( V_263 * V_250 ) ;
if ( V_266 % ( V_263 * V_250 ) ) {
V_273 = F_80 ( V_266 , V_263 * V_250 ) ;
F_77 ( V_249 , L_50 , V_273 ) ;
V_265 -> V_277 = ( V_266 - ( V_265 -> V_276 * V_263 * V_250 ) )
/ V_273 ;
V_265 -> V_278 = ( V_263 * V_250 ) / V_273 ;
} else {
V_265 -> V_277 = 0 ;
V_265 -> V_278 = 0 ;
}
while ( V_265 -> V_278 >= ( 1 << 16 ) ) {
V_265 -> V_277 >>= 1 ;
V_265 -> V_278 >>= 1 ;
}
for ( V_43 = 0 ; V_43 < F_25 ( V_279 ) ; V_43 ++ ) {
if ( V_279 [ V_43 ] . V_261 <= V_250 && V_250 <= V_279 [ V_43 ] . V_262 ) {
V_265 -> V_280 = V_279 [ V_43 ] . V_280 ;
break;
}
}
if ( V_43 == F_25 ( V_279 ) ) {
F_74 ( V_249 , L_51 ,
V_250 ) ;
return - V_79 ;
}
F_77 ( V_249 , L_52 ,
V_265 -> V_276 , V_265 -> V_277 , V_265 -> V_278 ) ;
F_77 ( V_249 , L_53 ,
V_265 -> V_259 , V_263 , V_265 -> V_275 ,
V_265 -> V_269 , 1 << V_265 -> V_269 ) ;
F_77 ( V_249 , L_54 , V_265 -> V_280 , 1 << V_265 -> V_280 ) ;
return 0 ;
}
static void F_81 ( struct V_9 * V_9 , unsigned int V_133 ,
struct V_264 * V_265 , int V_109 ,
bool V_267 )
{
F_8 ( V_9 -> V_20 , V_133 + 3 ,
V_281 , V_265 -> V_277 ) ;
F_8 ( V_9 -> V_20 , V_133 + 4 ,
V_282 , V_265 -> V_278 ) ;
F_8 ( V_9 -> V_20 , V_133 + 5 ,
V_283 ,
V_265 -> V_259 << V_284 ) ;
F_8 ( V_9 -> V_20 , V_133 + 6 ,
V_285 |
V_286 ,
V_265 -> V_269 << V_287 |
V_109 << V_288 ) ;
if ( V_267 ) {
F_14 ( V_9 -> V_20 , V_133 + 0x7 ,
V_289 ,
V_265 -> V_280 << V_290 ) ;
} else {
F_14 ( V_9 -> V_20 , V_133 + 0x5 ,
V_291 ,
V_265 -> V_275 << V_292 ) ;
F_14 ( V_9 -> V_20 , V_133 + 0x9 ,
V_289 ,
V_265 -> V_280 << V_290 ) ;
}
F_8 ( V_9 -> V_20 , V_133 + 2 ,
V_293 | V_294 ,
V_293 | V_265 -> V_276 ) ;
}
static int F_82 ( struct V_248 * V_249 )
{
struct V_9 * V_9 = V_249 -> V_9 ;
unsigned int V_61 ;
int V_32 ;
V_32 = F_11 ( V_9 -> V_20 , V_249 -> V_133 + 1 , & V_61 ) ;
if ( V_32 != 0 ) {
F_74 ( V_249 , L_55 ,
V_32 ) ;
return V_32 ;
}
return V_61 & V_295 ;
}
static int F_83 ( struct V_248 * V_249 )
{
struct V_9 * V_9 = V_249 -> V_9 ;
bool V_296 = false ;
int V_297 = F_82 ( V_249 ) ;
struct V_264 V_265 ;
int V_43 ;
unsigned int V_15 ;
if ( V_297 < 0 )
return V_297 ;
if ( V_297 ) {
F_8 ( V_249 -> V_9 -> V_20 , V_249 -> V_133 + 0x9 ,
V_289 , 0 ) ;
F_14 ( V_249 -> V_9 -> V_20 , V_249 -> V_133 + 1 ,
V_298 , V_298 ) ;
F_84 ( 32 ) ;
}
if ( V_249 -> V_299 >= 0 && V_249 -> V_300 &&
V_249 -> V_299 != V_249 -> V_301 ) {
F_79 ( V_249 , & V_265 , V_249 -> V_300 , false ) ;
F_81 ( V_9 , V_249 -> V_133 , & V_265 , V_249 -> V_299 ,
false ) ;
if ( V_249 -> V_301 >= 0 ) {
F_79 ( V_249 , & V_265 , V_249 -> V_302 , true ) ;
F_81 ( V_9 , V_249 -> V_133 + 0x10 , & V_265 ,
V_249 -> V_301 , true ) ;
V_296 = true ;
}
} else if ( V_249 -> V_301 >= 0 ) {
F_79 ( V_249 , & V_265 , V_249 -> V_302 , false ) ;
F_81 ( V_9 , V_249 -> V_133 , & V_265 ,
V_249 -> V_301 , false ) ;
F_8 ( V_9 -> V_20 , V_249 -> V_133 + 0x11 ,
V_303 , 0 ) ;
} else {
F_74 ( V_249 , L_56 ) ;
return - V_79 ;
}
if ( V_296 && V_249 -> V_302 > 100000 )
F_8 ( V_9 -> V_20 , V_249 -> V_133 + 0x17 ,
V_304 , 0 ) ;
else
F_8 ( V_9 -> V_20 , V_249 -> V_133 + 0x17 ,
V_304 ,
V_304 ) ;
if ( ! V_297 )
F_85 ( V_9 -> V_10 ) ;
F_8 ( V_9 -> V_20 , V_249 -> V_133 + 1 ,
V_295 , V_295 ) ;
if ( V_296 )
F_8 ( V_9 -> V_20 , V_249 -> V_133 + 0x11 ,
V_303 ,
V_303 ) ;
if ( V_297 )
F_8 ( V_9 -> V_20 , V_249 -> V_133 + 1 ,
V_298 , 0 ) ;
F_77 ( V_249 , L_57 ) ;
V_15 = 0 ;
for ( V_43 = 0 ; V_43 < 15 ; V_43 ++ ) {
if ( V_43 < 5 )
F_86 ( 200 , 400 ) ;
else
F_9 ( 20 ) ;
F_11 ( V_9 -> V_20 ,
V_305 ,
& V_15 ) ;
if ( V_15 & ( V_306 << ( V_249 -> V_169 - 1 ) ) )
break;
}
if ( V_43 == 15 )
F_78 ( V_249 , L_58 ) ;
else
F_77 ( V_249 , L_59 , V_43 ) ;
return 0 ;
}
static void F_87 ( struct V_248 * V_249 )
{
struct V_9 * V_9 = V_249 -> V_9 ;
bool V_307 ;
F_8 ( V_9 -> V_20 , V_249 -> V_133 + 1 ,
V_298 , V_298 ) ;
F_88 ( V_9 -> V_20 , V_249 -> V_133 + 1 ,
V_295 , 0 , & V_307 ) ;
F_14 ( V_9 -> V_20 , V_249 -> V_133 + 0x11 ,
V_303 , 0 ) ;
F_8 ( V_9 -> V_20 , V_249 -> V_133 + 1 ,
V_298 , 0 ) ;
if ( V_307 )
F_89 ( V_9 -> V_10 ) ;
}
int F_90 ( struct V_248 * V_249 , int V_109 ,
unsigned int V_250 , unsigned int V_251 )
{
int V_32 = 0 ;
if ( V_249 -> V_299 == V_109 && V_249 -> V_300 == V_250 )
return 0 ;
if ( V_249 -> V_253 && V_250 > 0 ) {
V_32 = F_73 ( V_249 , V_250 , V_249 -> V_253 ) ;
if ( V_32 != 0 )
return V_32 ;
}
V_249 -> V_299 = V_109 ;
V_249 -> V_300 = V_250 ;
if ( V_249 -> V_253 && V_250 > 0 ) {
V_32 = F_83 ( V_249 ) ;
}
return V_32 ;
}
int F_91 ( struct V_248 * V_249 , int V_109 ,
unsigned int V_250 , unsigned int V_251 )
{
int V_32 = 0 ;
if ( V_249 -> V_301 == V_109 &&
V_249 -> V_302 == V_250 && V_249 -> V_253 == V_251 )
return 0 ;
if ( V_251 ) {
if ( V_249 -> V_299 >= 0 ) {
V_32 = F_73 ( V_249 , V_249 -> V_300 , V_251 ) ;
if ( V_32 != 0 )
return V_32 ;
}
V_32 = F_73 ( V_249 , V_250 , V_251 ) ;
if ( V_32 != 0 )
return V_32 ;
}
V_249 -> V_301 = V_109 ;
V_249 -> V_302 = V_250 ;
V_249 -> V_253 = V_251 ;
if ( V_251 )
V_32 = F_83 ( V_249 ) ;
else
F_87 ( V_249 ) ;
return V_32 ;
}
int F_92 ( struct V_9 * V_9 , int V_169 , int V_133 , int V_308 ,
int V_309 , struct V_248 * V_249 )
{
unsigned int V_15 ;
V_249 -> V_169 = V_169 ;
V_249 -> V_133 = V_133 ;
V_249 -> V_9 = V_9 ;
V_249 -> V_301 = V_310 ;
F_11 ( V_9 -> V_20 , V_311 , & V_15 ) ;
switch ( V_15 & V_312 ) {
case V_313 :
case V_314 :
V_249 -> V_299 = V_15 & V_312 ;
break;
default:
V_249 -> V_299 = V_310 ;
}
V_249 -> V_300 = 32768 ;
snprintf ( V_249 -> V_315 , sizeof( V_249 -> V_315 ) , L_60 , V_169 ) ;
snprintf ( V_249 -> V_316 , sizeof( V_249 -> V_316 ) ,
L_61 , V_169 ) ;
F_14 ( V_9 -> V_20 , V_249 -> V_133 + 1 ,
V_298 , 0 ) ;
return 0 ;
}
int F_93 ( struct V_6 * V_7 , int V_317 , bool V_318 )
{
unsigned int V_61 , V_15 ;
if ( V_317 < 1 || V_317 > 6 )
return - V_79 ;
V_61 = V_319 + ( V_317 - 1 ) * 8 ;
if ( V_318 )
V_15 = V_320 ;
else
V_15 = 0 ;
return F_29 ( V_7 , V_61 , V_320 , V_15 ) ;
}
static bool F_94 ( bool V_132 , T_2 V_321 , T_2 V_322 )
{
T_3 V_323 = F_95 ( V_321 ) ;
T_3 V_324 = F_95 ( V_322 ) ;
if ( ! V_132 ) {
return abs ( V_323 ) >= 4096 ;
} else {
if ( abs ( V_324 ) >= 4096 )
return true ;
return ( abs ( ( V_323 << 16 ) / ( 4096 - V_324 ) ) >= 4096 << 4 ) ;
}
}
int F_96 ( struct V_3 * V_4 ,
struct V_325 * V_326 )
{
struct V_6 * V_7 = F_97 ( V_4 ) ;
struct V_9 * V_9 = F_3 ( V_7 -> V_10 -> V_11 ) ;
struct V_327 * V_187 = ( void * ) V_4 -> V_328 ;
unsigned int V_15 ;
T_2 * V_31 ;
int V_329 ;
int V_32 ;
V_329 = V_187 -> V_330 * F_98 ( V_9 -> V_20 ) ;
V_31 = F_99 ( V_326 -> V_331 . V_332 . V_31 , V_329 , V_333 | V_334 ) ;
if ( ! V_31 )
return - V_335 ;
V_31 [ 0 ] &= F_100 ( V_336 ) ;
if ( F_94 ( ! ! V_31 [ 0 ] , V_31 [ 1 ] , V_31 [ 2 ] ) ||
F_94 ( true , V_31 [ 4 ] , V_31 [ 5 ] ) ||
F_94 ( true , V_31 [ 8 ] , V_31 [ 9 ] ) ||
F_94 ( true , V_31 [ 12 ] , V_31 [ 13 ] ) ||
F_94 ( false , V_31 [ 16 ] , V_31 [ 17 ] ) ) {
F_12 ( V_9 -> V_10 , L_62 ) ;
V_32 = - V_79 ;
goto V_337;
}
V_32 = F_11 ( V_9 -> V_20 , V_187 -> V_133 , & V_15 ) ;
if ( V_32 != 0 )
goto V_337;
V_15 &= ~ V_336 ;
V_31 [ 0 ] |= F_100 ( V_15 ) ;
V_32 = F_101 ( V_9 -> V_20 , V_187 -> V_133 , V_31 , V_329 ) ;
V_337:
F_102 ( V_31 ) ;
return V_32 ;
}
int F_103 ( struct V_3 * V_4 ,
struct V_325 * V_326 )
{
struct V_6 * V_7 = F_97 ( V_4 ) ;
struct V_9 * V_9 = F_3 ( V_7 -> V_10 -> V_11 ) ;
T_2 * V_31 = ( T_2 * ) V_326 -> V_331 . V_332 . V_31 ;
T_3 V_15 = F_95 ( * V_31 ) ;
if ( abs ( V_15 ) >= 4096 ) {
F_12 ( V_9 -> V_10 , L_63 ) ;
return - V_79 ;
}
return F_104 ( V_4 , V_326 ) ;
}
