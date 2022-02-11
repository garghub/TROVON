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
static int F_42 ( struct V_6 * V_7 , unsigned int V_91 ,
unsigned int V_92 )
{
struct V_12 * V_13 = F_4 ( V_7 ) ;
unsigned int V_61 ;
unsigned int * V_93 ;
int V_94 , div , V_95 ;
switch ( V_91 ) {
case V_96 :
V_61 = V_97 ;
V_95 = V_13 -> V_98 ;
break;
case V_99 :
V_61 = V_100 ;
V_95 = V_13 -> V_101 ;
break;
default:
return - V_79 ;
}
if ( V_95 % 8000 )
V_93 = V_102 ;
else
V_93 = V_103 ;
for ( V_94 = 0 ; V_94 < F_23 ( V_103 ) &&
V_93 [ V_94 ] <= V_95 ; V_94 ++ ) {
div = 1 ;
while ( V_93 [ V_94 ] / div >= V_92 && div < 32 ) {
if ( V_93 [ V_94 ] / div == V_92 ) {
F_43 ( V_7 -> V_10 , L_17 ,
V_92 ) ;
F_27 ( V_7 , V_61 ,
V_104 |
V_105 ,
( div <<
V_106 ) |
V_94 ) ;
return 0 ;
}
div ++ ;
}
}
F_12 ( V_7 -> V_10 , L_18 , V_92 ) ;
return - V_79 ;
}
int F_44 ( struct V_6 * V_7 , int V_107 ,
int V_108 , unsigned int V_92 , int V_109 )
{
struct V_12 * V_13 = F_4 ( V_7 ) ;
struct V_9 * V_9 = V_13 -> V_9 ;
char * V_110 ;
unsigned int V_61 ;
unsigned int V_78 = V_111 | V_112 ;
unsigned int V_15 = V_108 << V_113 ;
unsigned int * V_91 ;
switch ( V_107 ) {
case V_114 :
V_110 = L_19 ;
V_61 = V_115 ;
V_91 = & V_13 -> V_98 ;
V_78 |= V_116 ;
break;
case V_117 :
V_110 = L_20 ;
V_61 = V_118 ;
V_91 = & V_13 -> V_101 ;
break;
case V_96 :
case V_99 :
return F_42 ( V_7 , V_107 , V_92 ) ;
default:
return - V_79 ;
}
switch ( V_92 ) {
case 5644800 :
case 6144000 :
break;
case 11289600 :
case 12288000 :
V_15 |= V_119 << V_120 ;
break;
case 22579200 :
case 24576000 :
V_15 |= V_121 << V_120 ;
break;
case 45158400 :
case 49152000 :
V_15 |= V_122 << V_120 ;
break;
case 67737600 :
case 73728000 :
V_15 |= V_123 << V_120 ;
break;
case 90316800 :
case 98304000 :
V_15 |= V_124 << V_120 ;
break;
case 135475200 :
case 147456000 :
V_15 |= V_125 << V_120 ;
break;
case 0 :
F_43 ( V_9 -> V_10 , L_21 , V_110 ) ;
* V_91 = V_92 ;
return 0 ;
default:
return - V_79 ;
}
* V_91 = V_92 ;
if ( V_92 % 6144000 )
V_15 |= V_116 ;
F_43 ( V_9 -> V_10 , L_22 , V_110 , V_92 ) ;
return F_14 ( V_9 -> V_20 , V_61 , V_78 , V_15 ) ;
}
static int F_45 ( struct V_126 * V_127 , unsigned int V_128 )
{
struct V_6 * V_7 = V_127 -> V_7 ;
struct V_12 * V_13 = F_4 ( V_7 ) ;
struct V_9 * V_9 = V_13 -> V_9 ;
int V_129 , V_130 , V_131 , V_132 ;
V_132 = V_127 -> V_133 -> V_132 ;
V_129 = 0 ;
V_130 = 0 ;
switch ( V_128 & V_134 ) {
case V_135 :
V_131 = V_136 ;
break;
case V_137 :
if ( ( V_128 & V_138 )
!= V_139 ) {
F_46 ( V_127 , L_23 ) ;
return - V_79 ;
}
V_131 = V_140 ;
break;
case V_141 :
V_131 = V_142 ;
break;
case V_143 :
if ( ( V_128 & V_138 )
!= V_139 ) {
F_46 ( V_127 , L_24 ) ;
return - V_79 ;
}
V_131 = V_144 ;
break;
default:
F_46 ( V_127 , L_25 ,
V_128 & V_134 ) ;
return - V_79 ;
}
switch ( V_128 & V_138 ) {
case V_145 :
break;
case V_146 :
V_129 |= V_147 ;
break;
case V_148 :
V_130 |= V_149 ;
break;
case V_139 :
V_130 |= V_149 ;
V_129 |= V_147 ;
break;
default:
F_46 ( V_127 , L_26 ,
V_128 & V_138 ) ;
return - V_79 ;
}
switch ( V_128 & V_150 ) {
case V_151 :
break;
case V_152 :
V_130 |= V_153 ;
V_129 |= V_154 ;
break;
case V_155 :
V_130 |= V_153 ;
break;
case V_156 :
V_129 |= V_154 ;
break;
default:
return - V_79 ;
}
F_8 ( V_9 -> V_20 , V_132 + V_157 ,
V_153 |
V_149 ,
V_130 ) ;
F_8 ( V_9 -> V_20 , V_132 + V_158 ,
V_154 |
V_147 , V_129 ) ;
F_8 ( V_9 -> V_20 ,
V_132 + V_159 ,
V_160 |
V_161 , V_129 ) ;
F_14 ( V_9 -> V_20 , V_132 + V_162 ,
V_163 , V_131 ) ;
return 0 ;
}
static int F_47 ( struct V_164 * V_165 ,
struct V_126 * V_127 )
{
struct V_6 * V_7 = V_127 -> V_7 ;
struct V_12 * V_13 = F_4 ( V_7 ) ;
struct V_166 * V_167 = & V_13 -> V_127 [ V_127 -> V_168 - 1 ] ;
const struct V_169 * V_170 ;
unsigned int V_171 ;
switch ( V_167 -> V_91 ) {
case V_114 :
V_171 = V_13 -> V_98 ;
break;
case V_117 :
V_171 = V_13 -> V_101 ;
break;
default:
return 0 ;
}
if ( V_171 == 0 )
return 0 ;
if ( V_171 % 8000 )
V_170 = & V_172 ;
else
V_170 = & V_173 ;
return V_169 ( V_165 -> V_174 , 0 ,
V_175 ,
V_170 ) ;
}
static void F_48 ( struct V_6 * V_7 ,
unsigned int V_176 )
{
struct V_12 * V_13 = F_4 ( V_7 ) ;
struct V_9 * V_9 = V_13 -> V_9 ;
struct V_177 V_178 [] = {
{ 0x80 , 0x3 } ,
{ V_179 , 0 } ,
{ V_180 , 0 } ,
{ 0x80 , 0x0 } ,
} ;
F_36 ( & V_9 -> V_181 ) ;
V_178 [ 1 ] . V_182 = V_9 -> V_183 ;
if ( V_176 >= 176400 )
V_178 [ 2 ] . V_182 = V_9 -> V_184 ;
F_37 ( & V_9 -> V_181 ) ;
F_49 ( V_9 -> V_20 ,
V_178 ,
F_23 ( V_178 ) ) ;
}
static int F_50 ( struct V_164 * V_165 ,
struct V_185 * V_186 ,
struct V_126 * V_127 )
{
struct V_6 * V_7 = V_127 -> V_7 ;
struct V_12 * V_13 = F_4 ( V_7 ) ;
struct V_166 * V_167 = & V_13 -> V_127 [ V_127 -> V_168 - 1 ] ;
int V_132 = V_127 -> V_133 -> V_132 ;
int V_43 , V_187 , V_32 ;
for ( V_43 = 0 ; V_43 < F_23 ( V_188 ) ; V_43 ++ )
if ( V_188 [ V_43 ] == F_51 ( V_186 ) )
break;
if ( V_43 == F_23 ( V_188 ) ) {
F_46 ( V_127 , L_27 ,
F_51 ( V_186 ) ) ;
return - V_79 ;
}
V_187 = V_43 ;
switch ( V_13 -> V_9 -> type ) {
case V_16 :
case V_39 :
if ( V_188 [ V_187 ] >= 88200 )
V_32 = F_35 ( V_7 , V_189 ) ;
else
V_32 = F_38 ( V_7 , V_189 ) ;
if ( V_32 ) {
F_46 ( V_127 , L_28 , V_32 ) ;
return V_32 ;
}
break;
default:
break;
}
switch ( V_167 -> V_91 ) {
case V_114 :
switch ( V_13 -> V_9 -> type ) {
case V_16 :
F_48 ( V_7 ,
F_51 ( V_186 ) ) ;
break;
default:
break;
}
F_27 ( V_7 , V_190 ,
V_191 , V_187 ) ;
if ( V_132 )
F_27 ( V_7 , V_132 + V_192 ,
V_193 , 0 ) ;
break;
case V_117 :
F_27 ( V_7 , V_194 ,
V_195 , V_187 ) ;
if ( V_132 )
F_27 ( V_7 , V_132 + V_192 ,
V_193 ,
8 << V_196 ) ;
break;
default:
F_46 ( V_127 , L_29 , V_167 -> V_91 ) ;
return - V_79 ;
}
return 0 ;
}
static bool F_52 ( struct V_6 * V_7 ,
int V_132 , int V_130 , int V_129 , int V_197 )
{
int V_15 ;
V_15 = F_6 ( V_7 , V_132 + V_157 ) ;
if ( V_130 != ( V_15 & V_198 ) )
return true ;
V_15 = F_6 ( V_7 , V_132 + V_199 ) ;
if ( V_129 != ( V_15 & V_200 ) )
return true ;
V_15 = F_6 ( V_7 , V_132 + V_201 ) ;
if ( V_197 != ( V_15 & ( V_202 |
V_203 ) ) )
return true ;
return false ;
}
static int F_53 ( struct V_164 * V_165 ,
struct V_185 * V_186 ,
struct V_126 * V_127 )
{
struct V_6 * V_7 = V_127 -> V_7 ;
struct V_12 * V_13 = F_4 ( V_7 ) ;
struct V_9 * V_9 = V_13 -> V_9 ;
int V_132 = V_127 -> V_133 -> V_132 ;
const int * V_93 ;
int V_43 , V_32 , V_15 ;
int V_204 = F_54 ( V_186 ) ;
int V_205 = V_9 -> V_45 . V_206 [ V_127 -> V_168 - 1 ] ;
int V_207 = V_9 -> V_207 [ V_127 -> V_168 - 1 ] ;
int V_208 = V_9 -> V_208 [ V_127 -> V_168 - 1 ] ;
int V_130 , V_129 , V_209 , V_197 , V_210 ;
bool V_211 ;
unsigned int V_212 , V_213 ;
if ( F_51 ( V_186 ) % 4000 )
V_93 = & V_214 [ 0 ] ;
else
V_93 = & V_215 [ 0 ] ;
V_209 = F_55 ( V_186 ) ;
if ( V_208 ) {
F_56 ( V_127 , L_30 ,
V_208 , V_207 ) ;
V_210 = V_208 * V_207 * F_51 ( V_186 ) ;
V_204 = V_208 ;
} else {
V_210 = F_57 ( V_186 ) ;
V_207 = V_209 ;
}
if ( V_205 && V_205 < V_204 ) {
F_56 ( V_127 , L_31 , V_205 ) ;
V_210 /= V_204 ;
V_210 *= V_205 ;
}
V_15 = F_6 ( V_7 , V_132 + V_162 ) ;
V_15 &= V_163 ;
if ( ( V_204 & 1 ) && ( V_15 == V_142 ) ) {
F_56 ( V_127 , L_32 ) ;
V_210 /= V_204 ;
V_210 *= V_204 + 1 ;
}
for ( V_43 = 0 ; V_43 < F_23 ( V_214 ) ; V_43 ++ ) {
if ( V_93 [ V_43 ] >= V_210 &&
V_93 [ V_43 ] % F_51 ( V_186 ) == 0 ) {
V_130 = V_43 ;
break;
}
}
if ( V_43 == F_23 ( V_214 ) ) {
F_46 ( V_127 , L_27 ,
F_51 ( V_186 ) ) ;
return - V_79 ;
}
V_129 = V_93 [ V_130 ] / F_51 ( V_186 ) ;
F_56 ( V_127 , L_33 ,
V_93 [ V_130 ] , V_93 [ V_130 ] / V_129 ) ;
V_197 = V_209 << V_216 | V_207 ;
V_211 = F_52 ( V_7 , V_132 , V_130 , V_129 , V_197 ) ;
if ( V_211 ) {
V_212 = F_6 ( V_7 ,
V_132 + V_217 ) ;
V_213 = F_6 ( V_7 ,
V_132 + V_218 ) ;
F_8 ( V_9 -> V_20 ,
V_132 + V_217 , 0xff , 0x0 ) ;
F_14 ( V_9 -> V_20 ,
V_132 + V_218 , 0xff , 0x0 ) ;
}
V_32 = F_50 ( V_165 , V_186 , V_127 ) ;
if ( V_32 != 0 )
goto V_219;
if ( V_211 ) {
F_8 ( V_9 -> V_20 ,
V_132 + V_157 ,
V_198 , V_130 ) ;
F_8 ( V_9 -> V_20 ,
V_132 + V_199 ,
V_200 , V_129 ) ;
F_8 ( V_9 -> V_20 ,
V_132 + V_220 ,
V_221 , V_129 ) ;
F_8 ( V_9 -> V_20 ,
V_132 + V_201 ,
V_202 |
V_203 , V_197 ) ;
F_14 ( V_9 -> V_20 ,
V_132 + V_222 ,
V_223 |
V_224 , V_197 ) ;
}
V_219:
if ( V_211 ) {
F_8 ( V_9 -> V_20 ,
V_132 + V_217 ,
0xff , V_212 ) ;
F_14 ( V_9 -> V_20 ,
V_132 + V_218 ,
0xff , V_213 ) ;
}
return V_32 ;
}
static const char * F_58 ( int V_107 )
{
switch ( V_107 ) {
case V_114 :
return L_19 ;
case V_117 :
return L_20 ;
default:
return L_34 ;
}
}
static int F_59 ( struct V_126 * V_127 ,
int V_107 , unsigned int V_92 , int V_109 )
{
struct V_6 * V_7 = V_127 -> V_7 ;
struct V_37 * V_8 = F_16 ( V_7 ) ;
struct V_12 * V_13 = F_4 ( V_7 ) ;
struct V_166 * V_167 = & V_13 -> V_127 [ V_127 -> V_168 - 1 ] ;
struct V_225 V_226 [ 2 ] ;
switch ( V_107 ) {
case V_114 :
case V_117 :
break;
default:
return - V_79 ;
}
if ( V_107 == V_167 -> V_91 )
return 0 ;
if ( V_127 -> V_227 ) {
F_12 ( V_7 -> V_10 , L_35 ,
V_127 -> V_168 ) ;
return - V_25 ;
}
F_43 ( V_7 -> V_10 , L_36 , V_127 -> V_168 + 1 ,
F_58 ( V_107 ) ) ;
memset ( & V_226 , 0 , sizeof( V_226 ) ) ;
V_226 [ 0 ] . V_228 = V_127 -> V_133 -> V_229 . V_230 ;
V_226 [ 1 ] . V_228 = V_127 -> V_133 -> V_231 . V_230 ;
V_226 [ 0 ] . V_108 = F_58 ( V_167 -> V_91 ) ;
V_226 [ 1 ] . V_108 = F_58 ( V_167 -> V_91 ) ;
F_60 ( V_8 , V_226 , F_23 ( V_226 ) ) ;
V_226 [ 0 ] . V_108 = F_58 ( V_107 ) ;
V_226 [ 1 ] . V_108 = F_58 ( V_107 ) ;
F_20 ( V_8 , V_226 , F_23 ( V_226 ) ) ;
V_167 -> V_91 = V_107 ;
return F_61 ( V_8 ) ;
}
static int F_62 ( struct V_126 * V_127 , int V_232 )
{
struct V_6 * V_7 = V_127 -> V_7 ;
int V_132 = V_127 -> V_133 -> V_132 ;
unsigned int V_61 ;
if ( V_232 )
V_61 = V_233 ;
else
V_61 = 0 ;
return F_27 ( V_7 , V_132 + V_192 ,
V_233 , V_61 ) ;
}
static void F_63 ( struct V_126 * V_127 ,
unsigned int V_132 ,
int V_204 , unsigned int V_78 )
{
struct V_6 * V_7 = V_127 -> V_7 ;
struct V_12 * V_13 = F_4 ( V_7 ) ;
struct V_9 * V_9 = V_13 -> V_9 ;
int V_234 , V_43 ;
for ( V_43 = 0 ; V_43 < V_204 ; ++ V_43 ) {
V_234 = F_64 ( V_78 ) - 1 ;
if ( V_234 < 0 )
return;
F_65 ( V_9 -> V_20 , V_132 + V_43 , V_234 ) ;
V_78 &= ~ ( 1 << V_234 ) ;
}
if ( V_78 )
F_66 ( V_127 , L_37 ) ;
}
static int F_67 ( struct V_126 * V_127 , unsigned int V_235 ,
unsigned int V_236 , int V_237 , int V_238 )
{
struct V_6 * V_7 = V_127 -> V_7 ;
struct V_12 * V_13 = F_4 ( V_7 ) ;
struct V_9 * V_9 = V_13 -> V_9 ;
int V_132 = V_127 -> V_133 -> V_132 ;
int V_239 = V_127 -> V_133 -> V_231 . V_240 ;
int V_241 = V_127 -> V_133 -> V_229 . V_240 ;
if ( V_127 -> V_168 > V_242 )
return - V_243 ;
if ( V_237 == 0 ) {
V_235 = ( 1 << V_241 ) - 1 ;
V_236 = ( 1 << V_239 ) - 1 ;
}
F_63 ( V_127 , V_132 + V_244 ,
V_241 , V_235 ) ;
F_63 ( V_127 , V_132 + V_245 ,
V_239 , V_236 ) ;
V_9 -> V_207 [ V_127 -> V_168 - 1 ] = V_238 ;
V_9 -> V_208 [ V_127 -> V_168 - 1 ] = V_237 ;
return 0 ;
}
int F_68 ( struct V_12 * V_13 , int V_168 )
{
struct V_166 * V_167 = & V_13 -> V_127 [ V_168 ] ;
V_167 -> V_91 = V_114 ;
return 0 ;
}
static int F_69 ( struct V_246 * V_247 ,
unsigned int V_248 ,
unsigned int V_249 )
{
unsigned int V_250 ;
if ( V_247 -> V_251 && V_249 != V_247 -> V_251 ) {
F_70 ( V_247 ,
L_38 ) ;
return - V_79 ;
}
if ( V_248 / V_252 > V_253 ) {
F_70 ( V_247 ,
L_39 ,
V_248 ) ;
return - V_79 ;
}
V_250 = V_254 * V_247 -> V_255 ;
if ( V_249 * V_256 < V_250 ) {
F_70 ( V_247 , L_40 ,
V_249 ) ;
return - V_79 ;
}
return 0 ;
}
static int F_71 ( unsigned int V_248 , int * V_257 )
{
int V_43 ;
for ( V_43 = 0 ; V_43 < F_23 ( V_258 ) ; V_43 ++ ) {
if ( V_258 [ V_43 ] . V_259 <= V_248 && V_248 <= V_258 [ V_43 ] . V_260 ) {
if ( V_257 )
* V_257 = V_258 [ V_43 ] . V_257 ;
return V_258 [ V_43 ] . V_261 ;
}
}
return - V_79 ;
}
static int F_72 ( struct V_246 * V_247 ,
struct V_262 * V_263 ,
unsigned int V_264 ,
unsigned int V_248 , bool V_265 )
{
int V_266 , V_261 ;
int V_267 , div ;
div = 1 ;
V_263 -> V_267 = 0 ;
while ( V_248 > V_253 ) {
div *= 2 ;
V_248 /= 2 ;
V_263 -> V_267 ++ ;
if ( div > V_252 )
return - V_79 ;
}
V_266 = F_71 ( V_248 , & V_263 -> V_257 ) ;
if ( V_266 < 0 ) {
F_70 ( V_247 , L_41 ,
V_248 ) ;
return V_266 ;
}
switch ( V_247 -> V_9 -> type ) {
case V_48 :
case V_49 :
if ( V_247 -> V_9 -> V_17 < 3 || V_265 )
return V_266 ;
break;
case V_268 :
case V_269 :
if ( V_265 )
return V_266 ;
break;
default:
return V_266 ;
}
V_263 -> V_257 = V_266 - 1 ;
V_267 = V_263 -> V_267 ;
while ( div <= V_252 ) {
for ( V_261 = V_266 ; V_261 <= V_270 ;
V_261 ++ ) {
if ( ( V_271 / 2 ) /
( V_247 -> V_255 * V_261 ) < V_248 )
break;
if ( V_264 % ( V_261 * V_248 ) ) {
V_263 -> V_267 = V_267 ;
V_263 -> V_257 = V_261 - 1 ;
return V_261 ;
}
}
for ( V_261 = V_266 - 1 ; V_261 > 0 ; V_261 -- ) {
if ( V_264 % ( V_261 * V_248 ) ) {
V_263 -> V_267 = V_267 ;
V_263 -> V_257 = V_261 - 1 ;
return V_261 ;
}
}
div *= 2 ;
V_248 /= 2 ;
V_267 ++ ;
V_266 = F_71 ( V_248 , NULL ) ;
}
F_73 ( V_247 , L_42 ) ;
return V_263 -> V_257 + 1 ;
}
static int F_74 ( struct V_246 * V_247 ,
struct V_262 * V_263 ,
unsigned int V_248 , bool V_265 )
{
unsigned int V_264 , div , V_272 ;
int V_43 , V_261 ;
F_75 ( V_247 , L_43 , V_248 , V_247 -> V_251 ) ;
div = V_273 ;
while ( V_247 -> V_251 * div < V_254 * V_247 -> V_255 ) {
div ++ ;
if ( div > V_256 )
return - V_79 ;
}
V_264 = V_247 -> V_251 * div / V_247 -> V_255 ;
V_263 -> V_274 = div ;
F_75 ( V_247 , L_44 , V_264 ) ;
V_261 = F_72 ( V_247 , V_263 , V_264 , V_248 , V_265 ) ;
if ( V_261 < 0 )
return V_261 ;
V_248 = V_248 / ( 1 << V_263 -> V_267 ) ;
V_263 -> V_275 = V_264 / ( V_261 * V_248 ) ;
if ( V_264 % ( V_261 * V_248 ) ) {
V_272 = F_76 ( V_264 , V_261 * V_248 ) ;
F_75 ( V_247 , L_45 , V_272 ) ;
V_263 -> V_276 = ( V_264 - ( V_263 -> V_275 * V_261 * V_248 ) )
/ V_272 ;
V_263 -> V_277 = ( V_261 * V_248 ) / V_272 ;
} else {
V_263 -> V_276 = 0 ;
V_263 -> V_277 = 0 ;
}
while ( V_263 -> V_277 >= ( 1 << 16 ) ) {
V_263 -> V_276 >>= 1 ;
V_263 -> V_277 >>= 1 ;
}
for ( V_43 = 0 ; V_43 < F_23 ( V_278 ) ; V_43 ++ ) {
if ( V_278 [ V_43 ] . V_259 <= V_248 && V_248 <= V_278 [ V_43 ] . V_260 ) {
V_263 -> V_279 = V_278 [ V_43 ] . V_279 ;
break;
}
}
if ( V_43 == F_23 ( V_278 ) ) {
F_70 ( V_247 , L_46 ,
V_248 ) ;
return - V_79 ;
}
F_75 ( V_247 , L_47 ,
V_263 -> V_275 , V_263 -> V_276 , V_263 -> V_277 ) ;
F_75 ( V_247 , L_48 ,
V_263 -> V_257 , V_263 -> V_257 , V_263 -> V_274 , V_263 -> V_267 ) ;
F_75 ( V_247 , L_49 , V_263 -> V_279 ) ;
return 0 ;
}
static void F_77 ( struct V_9 * V_9 , unsigned int V_132 ,
struct V_262 * V_263 , int V_108 ,
bool V_265 )
{
F_8 ( V_9 -> V_20 , V_132 + 3 ,
V_280 , V_263 -> V_276 ) ;
F_8 ( V_9 -> V_20 , V_132 + 4 ,
V_281 , V_263 -> V_277 ) ;
F_8 ( V_9 -> V_20 , V_132 + 5 ,
V_282 ,
V_263 -> V_257 << V_283 ) ;
F_8 ( V_9 -> V_20 , V_132 + 6 ,
V_284 |
V_285 ,
V_263 -> V_267 << V_286 |
V_108 << V_287 ) ;
if ( V_265 ) {
F_14 ( V_9 -> V_20 , V_132 + 0x7 ,
V_288 ,
V_263 -> V_279 << V_289 ) ;
} else {
F_14 ( V_9 -> V_20 , V_132 + 0x5 ,
V_290 ,
V_263 -> V_274 << V_291 ) ;
F_14 ( V_9 -> V_20 , V_132 + 0x9 ,
V_288 ,
V_263 -> V_279 << V_289 ) ;
}
F_8 ( V_9 -> V_20 , V_132 + 2 ,
V_292 | V_293 ,
V_292 | V_263 -> V_275 ) ;
}
static int F_78 ( struct V_246 * V_247 )
{
struct V_9 * V_9 = V_247 -> V_9 ;
unsigned int V_61 ;
int V_32 ;
V_32 = F_11 ( V_9 -> V_20 , V_247 -> V_132 + 1 , & V_61 ) ;
if ( V_32 != 0 ) {
F_70 ( V_247 , L_50 ,
V_32 ) ;
return V_32 ;
}
return V_61 & V_294 ;
}
static int F_79 ( struct V_246 * V_247 )
{
struct V_9 * V_9 = V_247 -> V_9 ;
bool V_295 = false ;
int V_296 = F_78 ( V_247 ) ;
struct V_262 V_263 ;
int V_43 ;
unsigned int V_15 ;
if ( V_296 < 0 )
return V_296 ;
if ( V_296 ) {
F_8 ( V_247 -> V_9 -> V_20 , V_247 -> V_132 + 0x9 ,
V_288 , 0 ) ;
F_8 ( V_247 -> V_9 -> V_20 , V_247 -> V_132 + 1 ,
V_297 ,
V_297 ) ;
}
if ( V_247 -> V_298 >= 0 && V_247 -> V_299 &&
V_247 -> V_298 != V_247 -> V_300 ) {
F_74 ( V_247 , & V_263 , V_247 -> V_299 , false ) ;
F_77 ( V_9 , V_247 -> V_132 , & V_263 , V_247 -> V_298 ,
false ) ;
if ( V_247 -> V_300 >= 0 ) {
F_74 ( V_247 , & V_263 , V_247 -> V_301 , true ) ;
F_77 ( V_9 , V_247 -> V_132 + 0x10 , & V_263 ,
V_247 -> V_300 , true ) ;
V_295 = true ;
}
} else if ( V_247 -> V_300 >= 0 ) {
F_74 ( V_247 , & V_263 , V_247 -> V_301 , false ) ;
F_77 ( V_9 , V_247 -> V_132 , & V_263 ,
V_247 -> V_300 , false ) ;
F_8 ( V_9 -> V_20 , V_247 -> V_132 + 0x11 ,
V_302 , 0 ) ;
} else {
F_70 ( V_247 , L_51 ) ;
return - V_79 ;
}
if ( V_295 && V_247 -> V_301 > 100000 )
F_8 ( V_9 -> V_20 , V_247 -> V_132 + 0x17 ,
V_303 , 0 ) ;
else
F_8 ( V_9 -> V_20 , V_247 -> V_132 + 0x17 ,
V_303 ,
V_303 ) ;
if ( ! V_296 )
F_80 ( V_9 -> V_10 ) ;
F_8 ( V_9 -> V_20 , V_247 -> V_132 + 1 ,
V_294 , V_294 ) ;
if ( V_295 )
F_8 ( V_9 -> V_20 , V_247 -> V_132 + 0x11 ,
V_302 ,
V_302 ) ;
if ( V_296 )
F_8 ( V_9 -> V_20 , V_247 -> V_132 + 1 ,
V_297 , 0 ) ;
F_75 ( V_247 , L_52 ) ;
V_15 = 0 ;
for ( V_43 = 0 ; V_43 < 15 ; V_43 ++ ) {
if ( V_43 < 5 )
F_81 ( 200 , 400 ) ;
else
F_9 ( 20 ) ;
F_11 ( V_9 -> V_20 ,
V_304 ,
& V_15 ) ;
if ( V_15 & ( V_305 << ( V_247 -> V_168 - 1 ) ) )
break;
}
if ( V_43 == 15 )
F_73 ( V_247 , L_53 ) ;
else
F_75 ( V_247 , L_54 , V_43 ) ;
return 0 ;
}
static void F_82 ( struct V_246 * V_247 )
{
struct V_9 * V_9 = V_247 -> V_9 ;
bool V_306 ;
F_8 ( V_9 -> V_20 , V_247 -> V_132 + 1 ,
V_297 , V_297 ) ;
F_83 ( V_9 -> V_20 , V_247 -> V_132 + 1 ,
V_294 , 0 , & V_306 ) ;
F_14 ( V_9 -> V_20 , V_247 -> V_132 + 0x11 ,
V_302 , 0 ) ;
F_8 ( V_9 -> V_20 , V_247 -> V_132 + 1 ,
V_297 , 0 ) ;
if ( V_306 )
F_84 ( V_9 -> V_10 ) ;
}
int F_85 ( struct V_246 * V_247 , int V_108 ,
unsigned int V_248 , unsigned int V_249 )
{
int V_32 = 0 ;
if ( V_247 -> V_298 == V_108 && V_247 -> V_299 == V_248 )
return 0 ;
if ( V_247 -> V_251 && V_248 > 0 ) {
V_32 = F_69 ( V_247 , V_248 , V_247 -> V_251 ) ;
if ( V_32 != 0 )
return V_32 ;
}
V_247 -> V_298 = V_108 ;
V_247 -> V_299 = V_248 ;
if ( V_247 -> V_251 && V_248 > 0 ) {
V_32 = F_79 ( V_247 ) ;
}
return V_32 ;
}
int F_86 ( struct V_246 * V_247 , int V_108 ,
unsigned int V_248 , unsigned int V_249 )
{
int V_32 = 0 ;
if ( V_247 -> V_300 == V_108 &&
V_247 -> V_301 == V_248 && V_247 -> V_251 == V_249 )
return 0 ;
if ( V_249 ) {
if ( V_247 -> V_298 >= 0 ) {
V_32 = F_69 ( V_247 , V_247 -> V_299 , V_249 ) ;
if ( V_32 != 0 )
return V_32 ;
}
V_32 = F_69 ( V_247 , V_248 , V_249 ) ;
if ( V_32 != 0 )
return V_32 ;
}
V_247 -> V_300 = V_108 ;
V_247 -> V_301 = V_248 ;
V_247 -> V_251 = V_249 ;
if ( V_249 )
V_32 = F_79 ( V_247 ) ;
else
F_82 ( V_247 ) ;
return V_32 ;
}
int F_87 ( struct V_9 * V_9 , int V_168 , int V_132 , int V_307 ,
int V_308 , struct V_246 * V_247 )
{
unsigned int V_15 ;
V_247 -> V_168 = V_168 ;
V_247 -> V_132 = V_132 ;
V_247 -> V_9 = V_9 ;
V_247 -> V_300 = V_309 ;
F_11 ( V_9 -> V_20 , V_310 , & V_15 ) ;
switch ( V_15 & V_311 ) {
case V_312 :
case V_313 :
V_247 -> V_298 = V_15 & V_311 ;
break;
default:
V_247 -> V_298 = V_309 ;
}
V_247 -> V_299 = 32768 ;
snprintf ( V_247 -> V_314 , sizeof( V_247 -> V_314 ) , L_55 , V_168 ) ;
snprintf ( V_247 -> V_315 , sizeof( V_247 -> V_315 ) ,
L_56 , V_168 ) ;
F_14 ( V_9 -> V_20 , V_247 -> V_132 + 1 ,
V_297 , 0 ) ;
return 0 ;
}
int F_88 ( struct V_6 * V_7 , int V_316 , bool V_317 )
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
static bool F_89 ( bool V_131 , T_2 V_320 , T_2 V_321 )
{
T_3 V_322 = F_90 ( V_320 ) ;
T_3 V_323 = F_90 ( V_321 ) ;
if ( ! V_131 ) {
return abs ( V_322 ) >= 4096 ;
} else {
if ( abs ( V_323 ) >= 4096 )
return true ;
return ( abs ( ( V_322 << 16 ) / ( 4096 - V_323 ) ) >= 4096 << 4 ) ;
}
}
int F_91 ( struct V_3 * V_4 ,
struct V_324 * V_325 )
{
struct V_6 * V_7 = F_92 ( V_4 ) ;
struct V_9 * V_9 = F_3 ( V_7 -> V_10 -> V_11 ) ;
struct V_326 * V_186 = ( void * ) V_4 -> V_327 ;
unsigned int V_15 ;
T_2 * V_31 ;
int V_328 ;
int V_32 ;
V_328 = V_186 -> V_329 * F_93 ( V_9 -> V_20 ) ;
V_31 = F_94 ( V_325 -> V_330 . V_331 . V_31 , V_328 , V_332 | V_333 ) ;
if ( ! V_31 )
return - V_334 ;
V_31 [ 0 ] &= F_95 ( V_335 ) ;
if ( F_89 ( ! ! V_31 [ 0 ] , V_31 [ 1 ] , V_31 [ 2 ] ) ||
F_89 ( true , V_31 [ 4 ] , V_31 [ 5 ] ) ||
F_89 ( true , V_31 [ 8 ] , V_31 [ 9 ] ) ||
F_89 ( true , V_31 [ 12 ] , V_31 [ 13 ] ) ||
F_89 ( false , V_31 [ 16 ] , V_31 [ 17 ] ) ) {
F_12 ( V_9 -> V_10 , L_57 ) ;
V_32 = - V_79 ;
goto V_336;
}
V_32 = F_11 ( V_9 -> V_20 , V_186 -> V_132 , & V_15 ) ;
if ( V_32 != 0 )
goto V_336;
V_15 &= ~ V_335 ;
V_31 [ 0 ] |= F_95 ( V_15 ) ;
V_32 = F_96 ( V_9 -> V_20 , V_186 -> V_132 , V_31 , V_328 ) ;
V_336:
F_97 ( V_31 ) ;
return V_32 ;
}
int F_98 ( struct V_3 * V_4 ,
struct V_324 * V_325 )
{
struct V_6 * V_7 = F_92 ( V_4 ) ;
struct V_9 * V_9 = F_3 ( V_7 -> V_10 -> V_11 ) ;
T_2 * V_31 = ( T_2 * ) V_325 -> V_330 . V_331 . V_31 ;
T_3 V_15 = F_90 ( * V_31 ) ;
if ( abs ( V_15 ) >= 4096 ) {
F_12 ( V_9 -> V_10 , L_58 ) ;
return - V_79 ;
}
return F_99 ( V_4 , V_325 ) ;
}
