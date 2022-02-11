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
static void F_25 ( struct V_6 * V_7 , int V_54 )
{
struct V_12 * V_13 = F_4 ( V_7 ) ;
unsigned int V_15 ;
int V_43 ;
if ( V_54 )
V_15 = V_55 ;
else
V_15 = 0 ;
for ( V_43 = 0 ; V_43 < V_13 -> V_56 ; V_43 ++ )
F_26 ( V_7 ,
V_57 + ( V_43 * 4 ) ,
V_55 , V_15 ) ;
}
int F_27 ( struct V_1 * V_2 , struct V_3 * V_4 ,
int V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 -> V_8 ) ;
struct V_12 * V_13 = F_4 ( V_7 ) ;
unsigned int V_58 ;
if ( V_2 -> V_27 % 2 )
V_58 = V_57 + ( ( V_2 -> V_27 / 2 ) * 8 ) ;
else
V_58 = V_59 + ( ( V_2 -> V_27 / 2 ) * 8 ) ;
switch ( V_5 ) {
case V_18 :
V_13 -> V_60 ++ ;
break;
case V_22 :
F_26 ( V_7 , V_58 , V_61 , 0 ) ;
V_13 -> V_60 -- ;
if ( V_13 -> V_60 == 0 ) {
F_9 ( 1 ) ;
F_25 ( V_7 , 1 ) ;
}
break;
case V_28 :
F_26 ( V_7 , V_58 ,
V_61 | V_55 ,
V_61 | V_55 ) ;
break;
case V_29 :
V_58 = F_6 ( V_7 , V_62 ) ;
if ( V_58 == 0 )
F_25 ( V_7 , 0 ) ;
}
return 0 ;
}
int F_28 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
int V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 -> V_8 ) ;
struct V_12 * V_13 = F_4 ( V_7 ) ;
switch ( V_5 ) {
case V_18 :
switch ( V_2 -> V_27 ) {
case V_63 :
case V_64 :
case V_65 :
case V_66 :
case V_67 :
case V_68 :
V_13 -> V_69 ++ ;
V_13 -> V_70 += 17 ;
break;
default:
break;
}
break;
case V_22 :
switch ( V_2 -> V_27 ) {
case V_63 :
case V_64 :
case V_65 :
case V_66 :
case V_67 :
case V_68 :
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
case V_28 :
switch ( V_2 -> V_27 ) {
case V_63 :
case V_64 :
case V_65 :
case V_66 :
case V_67 :
case V_68 :
V_13 -> V_71 ++ ;
V_13 -> V_72 ++ ;
break;
default:
break;
}
break;
case V_29 :
switch ( V_2 -> V_27 ) {
case V_63 :
case V_64 :
case V_65 :
case V_66 :
case V_67 :
case V_68 :
V_13 -> V_71 -- ;
if ( ! V_13 -> V_71 ) {
F_9 ( V_13 -> V_72 ) ;
V_13 -> V_72 = 0 ;
}
break;
default:
break;
}
break;
}
return 0 ;
}
int F_29 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
int V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 -> V_8 ) ;
struct V_12 * V_13 = F_4 ( V_7 ) ;
struct V_9 * V_9 = V_13 -> V_9 ;
unsigned int V_73 = 1 << V_2 -> V_27 ;
unsigned int V_15 ;
switch ( V_5 ) {
case V_22 :
V_15 = V_73 ;
break;
case V_28 :
V_15 = 0 ;
break;
case V_18 :
case V_29 :
return F_28 ( V_2 , V_4 , V_5 ) ;
default:
return - V_74 ;
}
V_13 -> V_9 -> V_75 &= ~ V_73 ;
V_13 -> V_9 -> V_75 |= V_15 ;
if ( V_13 -> V_9 -> V_76 )
V_15 = 0 ;
F_8 ( V_9 -> V_20 , V_26 ,
V_73 , V_15 ) ;
return F_28 ( V_2 , V_4 , V_5 ) ;
}
static int F_30 ( struct V_6 * V_7 )
{
const struct V_12 * V_13 = F_4 ( V_7 ) ;
struct V_9 * V_9 = V_13 -> V_9 ;
int V_32 ;
V_32 = F_31 ( V_9 -> V_77 , 1800000 , 1800000 ) ;
if ( V_32 ) {
F_12 ( V_7 -> V_10 , L_12 , V_32 ) ;
return V_32 ;
}
V_32 = F_14 ( V_9 -> V_20 ,
V_78 ,
V_79 ,
V_79 ) ;
if ( V_32 ) {
F_12 ( V_7 -> V_10 , L_13 , V_32 ) ;
F_31 ( V_9 -> V_77 , 1200000 , 1800000 ) ;
return V_32 ;
}
return 0 ;
}
static int F_32 ( struct V_6 * V_7 )
{
const struct V_12 * V_13 = F_4 ( V_7 ) ;
struct V_9 * V_9 = V_13 -> V_9 ;
int V_32 ;
V_32 = F_14 ( V_9 -> V_20 ,
V_78 ,
V_79 , 0 ) ;
if ( V_32 ) {
F_12 ( V_7 -> V_10 , L_14 , V_32 ) ;
return V_32 ;
}
V_32 = F_31 ( V_9 -> V_77 , 1200000 , 1800000 ) ;
if ( V_32 ) {
F_12 ( V_7 -> V_10 , L_15 , V_32 ) ;
return V_32 ;
}
return 0 ;
}
int F_33 ( struct V_6 * V_7 , unsigned int V_80 )
{
struct V_12 * V_13 = F_4 ( V_7 ) ;
int V_32 = 0 ;
F_34 ( & V_13 -> V_81 ) ;
if ( ! V_13 -> V_82 && ! V_13 -> V_83 ) {
V_32 = F_30 ( V_7 ) ;
if ( V_32 )
goto V_84;
}
V_13 -> V_83 |= V_80 ;
V_84:
F_35 ( & V_13 -> V_81 ) ;
return V_32 ;
}
int F_36 ( struct V_6 * V_7 , unsigned int V_80 )
{
struct V_12 * V_13 = F_4 ( V_7 ) ;
unsigned int V_85 ;
int V_32 = 0 ;
F_34 ( & V_13 -> V_81 ) ;
V_85 = V_13 -> V_83 ;
V_13 -> V_83 &= ~ V_80 ;
if ( ! V_13 -> V_82 && V_85 && ! V_13 -> V_83 )
V_32 = F_32 ( V_7 ) ;
F_35 ( & V_13 -> V_81 ) ;
return V_32 ;
}
int F_37 ( struct V_1 * V_2 ,
struct V_3 * V_4 , int V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 -> V_8 ) ;
struct V_12 * V_13 = F_4 ( V_7 ) ;
int V_32 = 0 ;
F_34 ( & V_13 -> V_81 ) ;
switch ( V_5 ) {
case V_22 :
if ( V_13 -> V_83 )
V_32 = F_30 ( V_7 ) ;
V_13 -> V_82 = false ;
break;
case V_28 :
V_13 -> V_82 = true ;
if ( V_13 -> V_83 )
V_32 = F_32 ( V_7 ) ;
break;
default:
break;
}
F_35 ( & V_13 -> V_81 ) ;
return V_32 ;
}
void F_38 ( struct V_12 * V_13 )
{
F_39 ( & V_13 -> V_81 ) ;
}
static int F_40 ( struct V_6 * V_7 , unsigned int V_86 ,
unsigned int V_87 )
{
struct V_12 * V_13 = F_4 ( V_7 ) ;
unsigned int V_58 ;
unsigned int * V_88 ;
int V_89 , div , V_90 ;
switch ( V_86 ) {
case V_91 :
V_58 = V_92 ;
V_90 = V_13 -> V_93 ;
break;
case V_94 :
V_58 = V_95 ;
V_90 = V_13 -> V_96 ;
break;
default:
return - V_74 ;
}
if ( V_90 % 8000 )
V_88 = V_97 ;
else
V_88 = V_98 ;
for ( V_89 = 0 ; V_89 < F_23 ( V_98 ) &&
V_88 [ V_89 ] <= V_90 ; V_89 ++ ) {
div = 1 ;
while ( V_88 [ V_89 ] / div >= V_87 && div < 32 ) {
if ( V_88 [ V_89 ] / div == V_87 ) {
F_41 ( V_7 -> V_10 , L_16 ,
V_87 ) ;
F_26 ( V_7 , V_58 ,
V_99 |
V_100 ,
( div <<
V_101 ) |
V_89 ) ;
return 0 ;
}
div ++ ;
}
}
F_12 ( V_7 -> V_10 , L_17 , V_87 ) ;
return - V_74 ;
}
int F_42 ( struct V_6 * V_7 , int V_102 ,
int V_103 , unsigned int V_87 , int V_104 )
{
struct V_12 * V_13 = F_4 ( V_7 ) ;
struct V_9 * V_9 = V_13 -> V_9 ;
char * V_105 ;
unsigned int V_58 ;
unsigned int V_73 = V_106 | V_107 ;
unsigned int V_15 = V_103 << V_108 ;
unsigned int * V_86 ;
switch ( V_102 ) {
case V_109 :
V_105 = L_18 ;
V_58 = V_110 ;
V_86 = & V_13 -> V_93 ;
V_73 |= V_111 ;
break;
case V_112 :
V_105 = L_19 ;
V_58 = V_113 ;
V_86 = & V_13 -> V_96 ;
break;
case V_91 :
case V_94 :
return F_40 ( V_7 , V_102 , V_87 ) ;
default:
return - V_74 ;
}
switch ( V_87 ) {
case 5644800 :
case 6144000 :
break;
case 11289600 :
case 12288000 :
V_15 |= V_114 << V_115 ;
break;
case 22579200 :
case 24576000 :
V_15 |= V_116 << V_115 ;
break;
case 45158400 :
case 49152000 :
V_15 |= V_117 << V_115 ;
break;
case 67737600 :
case 73728000 :
V_15 |= V_118 << V_115 ;
break;
case 90316800 :
case 98304000 :
V_15 |= V_119 << V_115 ;
break;
case 135475200 :
case 147456000 :
V_15 |= V_120 << V_115 ;
break;
case 0 :
F_41 ( V_9 -> V_10 , L_20 , V_105 ) ;
* V_86 = V_87 ;
return 0 ;
default:
return - V_74 ;
}
* V_86 = V_87 ;
if ( V_87 % 6144000 )
V_15 |= V_111 ;
F_41 ( V_9 -> V_10 , L_21 , V_105 , V_87 ) ;
return F_14 ( V_9 -> V_20 , V_58 , V_73 , V_15 ) ;
}
static int F_43 ( struct V_121 * V_122 , unsigned int V_123 )
{
struct V_6 * V_7 = V_122 -> V_7 ;
struct V_12 * V_13 = F_4 ( V_7 ) ;
struct V_9 * V_9 = V_13 -> V_9 ;
int V_124 , V_125 , V_126 , V_127 ;
V_127 = V_122 -> V_128 -> V_127 ;
V_124 = 0 ;
V_125 = 0 ;
switch ( V_123 & V_129 ) {
case V_130 :
V_126 = V_131 ;
break;
case V_132 :
if ( ( V_123 & V_133 )
!= V_134 ) {
F_44 ( V_122 , L_22 ) ;
return - V_74 ;
}
V_126 = V_135 ;
break;
case V_136 :
V_126 = V_137 ;
break;
case V_138 :
if ( ( V_123 & V_133 )
!= V_134 ) {
F_44 ( V_122 , L_23 ) ;
return - V_74 ;
}
V_126 = V_139 ;
break;
default:
F_44 ( V_122 , L_24 ,
V_123 & V_129 ) ;
return - V_74 ;
}
switch ( V_123 & V_133 ) {
case V_140 :
break;
case V_141 :
V_124 |= V_142 ;
break;
case V_143 :
V_125 |= V_144 ;
break;
case V_134 :
V_125 |= V_144 ;
V_124 |= V_142 ;
break;
default:
F_44 ( V_122 , L_25 ,
V_123 & V_133 ) ;
return - V_74 ;
}
switch ( V_123 & V_145 ) {
case V_146 :
break;
case V_147 :
V_125 |= V_148 ;
V_124 |= V_149 ;
break;
case V_150 :
V_125 |= V_148 ;
break;
case V_151 :
V_124 |= V_149 ;
break;
default:
return - V_74 ;
}
F_8 ( V_9 -> V_20 , V_127 + V_152 ,
V_148 |
V_144 ,
V_125 ) ;
F_8 ( V_9 -> V_20 , V_127 + V_153 ,
V_149 |
V_142 , V_124 ) ;
F_8 ( V_9 -> V_20 ,
V_127 + V_154 ,
V_155 |
V_156 , V_124 ) ;
F_14 ( V_9 -> V_20 , V_127 + V_157 ,
V_158 , V_126 ) ;
return 0 ;
}
static int F_45 ( struct V_159 * V_160 ,
struct V_121 * V_122 )
{
struct V_6 * V_7 = V_122 -> V_7 ;
struct V_12 * V_13 = F_4 ( V_7 ) ;
struct V_161 * V_162 = & V_13 -> V_122 [ V_122 -> V_163 - 1 ] ;
const struct V_164 * V_165 ;
unsigned int V_166 ;
switch ( V_162 -> V_86 ) {
case V_109 :
V_166 = V_13 -> V_93 ;
break;
case V_112 :
V_166 = V_13 -> V_96 ;
break;
default:
return 0 ;
}
if ( V_166 == 0 )
return 0 ;
if ( V_166 % 8000 )
V_165 = & V_167 ;
else
V_165 = & V_168 ;
return V_164 ( V_160 -> V_169 , 0 ,
V_170 ,
V_165 ) ;
}
static void F_46 ( struct V_6 * V_7 ,
unsigned int V_171 )
{
struct V_12 * V_13 = F_4 ( V_7 ) ;
struct V_9 * V_9 = V_13 -> V_9 ;
struct V_172 V_173 [] = {
{ 0x80 , 0x3 } ,
{ V_174 , 0 } ,
{ V_175 , 0 } ,
{ 0x80 , 0x0 } ,
} ;
F_34 ( & V_9 -> V_176 ) ;
V_173 [ 1 ] . V_177 = V_9 -> V_178 ;
if ( V_171 >= 176400 )
V_173 [ 2 ] . V_177 = V_9 -> V_179 ;
F_35 ( & V_9 -> V_176 ) ;
F_47 ( V_9 -> V_20 ,
V_173 ,
F_23 ( V_173 ) ) ;
}
static int F_48 ( struct V_159 * V_160 ,
struct V_180 * V_181 ,
struct V_121 * V_122 )
{
struct V_6 * V_7 = V_122 -> V_7 ;
struct V_12 * V_13 = F_4 ( V_7 ) ;
struct V_161 * V_162 = & V_13 -> V_122 [ V_122 -> V_163 - 1 ] ;
int V_127 = V_122 -> V_128 -> V_127 ;
int V_43 , V_182 , V_32 ;
for ( V_43 = 0 ; V_43 < F_23 ( V_183 ) ; V_43 ++ )
if ( V_183 [ V_43 ] == F_49 ( V_181 ) )
break;
if ( V_43 == F_23 ( V_183 ) ) {
F_44 ( V_122 , L_26 ,
F_49 ( V_181 ) ) ;
return - V_74 ;
}
V_182 = V_43 ;
switch ( V_13 -> V_9 -> type ) {
case V_16 :
case V_39 :
if ( V_183 [ V_182 ] >= 88200 )
V_32 = F_33 ( V_7 , V_184 ) ;
else
V_32 = F_36 ( V_7 , V_184 ) ;
if ( V_32 ) {
F_44 ( V_122 , L_27 , V_32 ) ;
return V_32 ;
}
break;
default:
break;
}
switch ( V_162 -> V_86 ) {
case V_109 :
switch ( V_13 -> V_9 -> type ) {
case V_16 :
F_46 ( V_7 ,
F_49 ( V_181 ) ) ;
break;
default:
break;
}
F_26 ( V_7 , V_185 ,
V_186 , V_182 ) ;
if ( V_127 )
F_26 ( V_7 , V_127 + V_187 ,
V_188 , 0 ) ;
break;
case V_112 :
F_26 ( V_7 , V_189 ,
V_190 , V_182 ) ;
if ( V_127 )
F_26 ( V_7 , V_127 + V_187 ,
V_188 ,
8 << V_191 ) ;
break;
default:
F_44 ( V_122 , L_28 , V_162 -> V_86 ) ;
return - V_74 ;
}
return 0 ;
}
static bool F_50 ( struct V_6 * V_7 ,
int V_127 , int V_125 , int V_124 , int V_192 )
{
int V_15 ;
V_15 = F_6 ( V_7 , V_127 + V_152 ) ;
if ( V_125 != ( V_15 & V_193 ) )
return true ;
V_15 = F_6 ( V_7 , V_127 + V_194 ) ;
if ( V_124 != ( V_15 & V_195 ) )
return true ;
V_15 = F_6 ( V_7 , V_127 + V_196 ) ;
if ( V_192 != ( V_15 & ( V_197 |
V_198 ) ) )
return true ;
return false ;
}
static int F_51 ( struct V_159 * V_160 ,
struct V_180 * V_181 ,
struct V_121 * V_122 )
{
struct V_6 * V_7 = V_122 -> V_7 ;
struct V_12 * V_13 = F_4 ( V_7 ) ;
struct V_9 * V_9 = V_13 -> V_9 ;
int V_127 = V_122 -> V_128 -> V_127 ;
const int * V_88 ;
int V_43 , V_32 , V_15 ;
int V_199 = F_52 ( V_181 ) ;
int V_200 = V_9 -> V_45 . V_201 [ V_122 -> V_163 - 1 ] ;
int V_202 = V_9 -> V_202 [ V_122 -> V_163 - 1 ] ;
int V_203 = V_9 -> V_203 [ V_122 -> V_163 - 1 ] ;
int V_125 , V_124 , V_204 , V_192 , V_205 ;
bool V_206 ;
unsigned int V_207 , V_208 ;
if ( F_49 ( V_181 ) % 8000 )
V_88 = & V_209 [ 0 ] ;
else
V_88 = & V_210 [ 0 ] ;
V_204 = F_53 ( F_54 ( V_181 ) ) ;
if ( V_203 ) {
F_55 ( V_122 , L_29 ,
V_203 , V_202 ) ;
V_205 = V_203 * V_202 * F_49 ( V_181 ) ;
V_199 = V_203 ;
} else {
V_205 = F_56 ( V_181 ) ;
V_202 = V_204 ;
}
if ( V_200 && V_200 < V_199 ) {
F_55 ( V_122 , L_30 , V_200 ) ;
V_205 /= V_199 ;
V_205 *= V_200 ;
}
V_15 = F_6 ( V_7 , V_127 + V_157 ) ;
V_15 &= V_158 ;
if ( ( V_199 & 1 ) && ( V_15 == V_137 ) ) {
F_55 ( V_122 , L_31 ) ;
V_205 /= V_199 ;
V_205 *= V_199 + 1 ;
}
for ( V_43 = 0 ; V_43 < F_23 ( V_209 ) ; V_43 ++ ) {
if ( V_88 [ V_43 ] >= V_205 &&
V_88 [ V_43 ] % F_49 ( V_181 ) == 0 ) {
V_125 = V_43 ;
break;
}
}
if ( V_43 == F_23 ( V_209 ) ) {
F_44 ( V_122 , L_26 ,
F_49 ( V_181 ) ) ;
return - V_74 ;
}
V_124 = V_88 [ V_125 ] / F_49 ( V_181 ) ;
F_55 ( V_122 , L_32 ,
V_88 [ V_125 ] , V_88 [ V_125 ] / V_124 ) ;
V_192 = V_204 << V_211 | V_202 ;
V_206 = F_50 ( V_7 , V_127 , V_125 , V_124 , V_192 ) ;
if ( V_206 ) {
V_207 = F_6 ( V_7 ,
V_127 + V_212 ) ;
V_208 = F_6 ( V_7 ,
V_127 + V_213 ) ;
F_8 ( V_9 -> V_20 ,
V_127 + V_212 , 0xff , 0x0 ) ;
F_14 ( V_9 -> V_20 ,
V_127 + V_213 , 0xff , 0x0 ) ;
}
V_32 = F_48 ( V_160 , V_181 , V_122 ) ;
if ( V_32 != 0 )
goto V_214;
if ( V_206 ) {
F_8 ( V_9 -> V_20 ,
V_127 + V_152 ,
V_193 , V_125 ) ;
F_8 ( V_9 -> V_20 ,
V_127 + V_194 ,
V_195 , V_124 ) ;
F_8 ( V_9 -> V_20 ,
V_127 + V_215 ,
V_216 , V_124 ) ;
F_8 ( V_9 -> V_20 ,
V_127 + V_196 ,
V_197 |
V_198 , V_192 ) ;
F_14 ( V_9 -> V_20 ,
V_127 + V_217 ,
V_218 |
V_219 , V_192 ) ;
}
V_214:
if ( V_206 ) {
F_8 ( V_9 -> V_20 ,
V_127 + V_212 ,
0xff , V_207 ) ;
F_14 ( V_9 -> V_20 ,
V_127 + V_213 ,
0xff , V_208 ) ;
}
return V_32 ;
}
static const char * F_57 ( int V_102 )
{
switch ( V_102 ) {
case V_109 :
return L_18 ;
case V_112 :
return L_19 ;
default:
return L_33 ;
}
}
static int F_58 ( struct V_121 * V_122 ,
int V_102 , unsigned int V_87 , int V_104 )
{
struct V_6 * V_7 = V_122 -> V_7 ;
struct V_37 * V_8 = F_16 ( V_7 ) ;
struct V_12 * V_13 = F_4 ( V_7 ) ;
struct V_161 * V_162 = & V_13 -> V_122 [ V_122 -> V_163 - 1 ] ;
struct V_220 V_221 [ 2 ] ;
switch ( V_102 ) {
case V_109 :
case V_112 :
break;
default:
return - V_74 ;
}
if ( V_102 == V_162 -> V_86 )
return 0 ;
if ( V_122 -> V_222 ) {
F_12 ( V_7 -> V_10 , L_34 ,
V_122 -> V_163 ) ;
return - V_25 ;
}
F_41 ( V_7 -> V_10 , L_35 , V_122 -> V_163 + 1 ,
F_57 ( V_102 ) ) ;
memset ( & V_221 , 0 , sizeof( V_221 ) ) ;
V_221 [ 0 ] . V_223 = V_122 -> V_128 -> V_224 . V_225 ;
V_221 [ 1 ] . V_223 = V_122 -> V_128 -> V_226 . V_225 ;
V_221 [ 0 ] . V_103 = F_57 ( V_162 -> V_86 ) ;
V_221 [ 1 ] . V_103 = F_57 ( V_162 -> V_86 ) ;
F_59 ( V_8 , V_221 , F_23 ( V_221 ) ) ;
V_221 [ 0 ] . V_103 = F_57 ( V_102 ) ;
V_221 [ 1 ] . V_103 = F_57 ( V_102 ) ;
F_20 ( V_8 , V_221 , F_23 ( V_221 ) ) ;
V_162 -> V_86 = V_102 ;
return F_60 ( V_8 ) ;
}
static int F_61 ( struct V_121 * V_122 , int V_227 )
{
struct V_6 * V_7 = V_122 -> V_7 ;
int V_127 = V_122 -> V_128 -> V_127 ;
unsigned int V_58 ;
if ( V_227 )
V_58 = V_228 ;
else
V_58 = 0 ;
return F_26 ( V_7 , V_127 + V_187 ,
V_228 , V_58 ) ;
}
static void F_62 ( struct V_121 * V_122 ,
unsigned int V_127 ,
int V_199 , unsigned int V_73 )
{
struct V_6 * V_7 = V_122 -> V_7 ;
struct V_12 * V_13 = F_4 ( V_7 ) ;
struct V_9 * V_9 = V_13 -> V_9 ;
int V_229 , V_43 ;
for ( V_43 = 0 ; V_43 < V_199 ; ++ V_43 ) {
V_229 = F_63 ( V_73 ) - 1 ;
if ( V_229 < 0 )
return;
F_64 ( V_9 -> V_20 , V_127 + V_43 , V_229 ) ;
V_73 &= ~ ( 1 << V_229 ) ;
}
if ( V_73 )
F_65 ( V_122 , L_36 ) ;
}
static int F_66 ( struct V_121 * V_122 , unsigned int V_230 ,
unsigned int V_231 , int V_232 , int V_233 )
{
struct V_6 * V_7 = V_122 -> V_7 ;
struct V_12 * V_13 = F_4 ( V_7 ) ;
struct V_9 * V_9 = V_13 -> V_9 ;
int V_127 = V_122 -> V_128 -> V_127 ;
int V_234 = V_122 -> V_128 -> V_226 . V_235 ;
int V_236 = V_122 -> V_128 -> V_224 . V_235 ;
if ( V_122 -> V_163 > V_237 )
return - V_238 ;
if ( V_232 == 0 ) {
V_230 = ( 1 << V_236 ) - 1 ;
V_231 = ( 1 << V_234 ) - 1 ;
}
F_62 ( V_122 , V_127 + V_239 ,
V_236 , V_230 ) ;
F_62 ( V_122 , V_127 + V_240 ,
V_234 , V_231 ) ;
V_9 -> V_202 [ V_122 -> V_163 - 1 ] = V_233 ;
V_9 -> V_203 [ V_122 -> V_163 - 1 ] = V_232 ;
return 0 ;
}
int F_67 ( struct V_12 * V_13 , int V_163 )
{
struct V_161 * V_162 = & V_13 -> V_122 [ V_163 ] ;
V_162 -> V_86 = V_109 ;
return 0 ;
}
static T_1 F_68 ( int V_30 , void * V_31 )
{
struct V_241 * V_242 = V_31 ;
F_69 ( V_242 , L_37 ) ;
F_70 ( & V_242 -> V_243 ) ;
return V_34 ;
}
static int F_71 ( struct V_241 * V_242 ,
unsigned int V_244 ,
unsigned int V_245 )
{
unsigned int V_246 ;
if ( V_242 -> V_247 && V_245 != V_242 -> V_247 ) {
F_72 ( V_242 ,
L_38 ) ;
return - V_74 ;
}
if ( V_244 / V_248 > V_249 ) {
F_72 ( V_242 ,
L_39 ,
V_244 ) ;
return - V_74 ;
}
V_246 = V_250 * V_242 -> V_251 ;
if ( V_245 * V_252 < V_246 ) {
F_72 ( V_242 , L_40 ,
V_245 ) ;
return - V_74 ;
}
return 0 ;
}
static int F_73 ( unsigned int V_244 , int * V_253 )
{
int V_43 ;
for ( V_43 = 0 ; V_43 < F_23 ( V_254 ) ; V_43 ++ ) {
if ( V_254 [ V_43 ] . V_255 <= V_244 && V_244 <= V_254 [ V_43 ] . V_256 ) {
if ( V_253 )
* V_253 = V_254 [ V_43 ] . V_253 ;
return V_254 [ V_43 ] . V_257 ;
}
}
return - V_74 ;
}
static int F_74 ( struct V_241 * V_242 ,
struct V_258 * V_259 ,
unsigned int V_260 ,
unsigned int V_244 , bool V_261 )
{
int V_262 , V_257 ;
int V_263 , div ;
div = 1 ;
V_259 -> V_263 = 0 ;
while ( V_244 > V_249 ) {
div *= 2 ;
V_244 /= 2 ;
V_259 -> V_263 ++ ;
if ( div > V_248 )
return - V_74 ;
}
V_262 = F_73 ( V_244 , & V_259 -> V_253 ) ;
if ( V_262 < 0 ) {
F_72 ( V_242 , L_41 ,
V_244 ) ;
return V_262 ;
}
switch ( V_242 -> V_9 -> type ) {
case V_48 :
case V_49 :
if ( V_242 -> V_9 -> V_17 < 3 || V_261 )
return V_262 ;
break;
default:
return V_262 ;
}
V_259 -> V_253 = V_262 - 1 ;
V_263 = V_259 -> V_263 ;
while ( div <= V_248 ) {
for ( V_257 = V_262 ; V_257 <= V_264 ;
V_257 ++ ) {
if ( ( V_265 / 2 ) /
( V_242 -> V_251 * V_257 ) < V_244 )
break;
if ( V_260 % ( V_257 * V_244 ) ) {
V_259 -> V_263 = V_263 ;
V_259 -> V_253 = V_257 - 1 ;
return V_257 ;
}
}
for ( V_257 = V_262 - 1 ; V_257 > 0 ; V_257 -- ) {
if ( V_260 % ( V_257 * V_244 ) ) {
V_259 -> V_263 = V_263 ;
V_259 -> V_253 = V_257 - 1 ;
return V_257 ;
}
}
div *= 2 ;
V_244 /= 2 ;
V_263 ++ ;
V_262 = F_73 ( V_244 , NULL ) ;
}
F_75 ( V_242 , L_42 ) ;
return V_259 -> V_253 + 1 ;
}
static int F_76 ( struct V_241 * V_242 ,
struct V_258 * V_259 ,
unsigned int V_244 , bool V_261 )
{
unsigned int V_260 , div , V_266 ;
int V_43 , V_257 ;
F_69 ( V_242 , L_43 , V_244 , V_242 -> V_247 ) ;
div = V_267 ;
while ( V_242 -> V_247 * div < V_250 * V_242 -> V_251 ) {
div ++ ;
if ( div > V_252 )
return - V_74 ;
}
V_260 = V_242 -> V_247 * div / V_242 -> V_251 ;
V_259 -> V_268 = div ;
F_69 ( V_242 , L_44 , V_260 ) ;
V_257 = F_74 ( V_242 , V_259 , V_260 , V_244 , V_261 ) ;
if ( V_257 < 0 )
return V_257 ;
V_244 = V_244 / ( 1 << V_259 -> V_263 ) ;
V_259 -> V_269 = V_260 / ( V_257 * V_244 ) ;
if ( V_260 % ( V_257 * V_244 ) ) {
V_266 = F_77 ( V_260 , V_257 * V_244 ) ;
F_69 ( V_242 , L_45 , V_266 ) ;
V_259 -> V_270 = ( V_260 - ( V_259 -> V_269 * V_257 * V_244 ) )
/ V_266 ;
V_259 -> V_271 = ( V_257 * V_244 ) / V_266 ;
} else {
V_259 -> V_270 = 0 ;
V_259 -> V_271 = 0 ;
}
while ( V_259 -> V_271 >= ( 1 << 16 ) ) {
V_259 -> V_270 >>= 1 ;
V_259 -> V_271 >>= 1 ;
}
for ( V_43 = 0 ; V_43 < F_23 ( V_272 ) ; V_43 ++ ) {
if ( V_272 [ V_43 ] . V_255 <= V_244 && V_244 <= V_272 [ V_43 ] . V_256 ) {
V_259 -> V_273 = V_272 [ V_43 ] . V_273 ;
break;
}
}
if ( V_43 == F_23 ( V_272 ) ) {
F_72 ( V_242 , L_46 ,
V_244 ) ;
return - V_74 ;
}
F_69 ( V_242 , L_47 ,
V_259 -> V_269 , V_259 -> V_270 , V_259 -> V_271 ) ;
F_69 ( V_242 , L_48 ,
V_259 -> V_253 , V_259 -> V_253 , V_259 -> V_268 , V_259 -> V_263 ) ;
F_69 ( V_242 , L_49 , V_259 -> V_273 ) ;
return 0 ;
}
static void F_78 ( struct V_9 * V_9 , unsigned int V_127 ,
struct V_258 * V_259 , int V_103 ,
bool V_261 )
{
F_8 ( V_9 -> V_20 , V_127 + 3 ,
V_274 , V_259 -> V_270 ) ;
F_8 ( V_9 -> V_20 , V_127 + 4 ,
V_275 , V_259 -> V_271 ) ;
F_8 ( V_9 -> V_20 , V_127 + 5 ,
V_276 ,
V_259 -> V_253 << V_277 ) ;
F_8 ( V_9 -> V_20 , V_127 + 6 ,
V_278 |
V_279 ,
V_259 -> V_263 << V_280 |
V_103 << V_281 ) ;
if ( V_261 ) {
F_14 ( V_9 -> V_20 , V_127 + 0x7 ,
V_282 ,
V_259 -> V_273 << V_283 ) ;
} else {
F_14 ( V_9 -> V_20 , V_127 + 0x5 ,
V_284 ,
V_259 -> V_268 << V_285 ) ;
F_14 ( V_9 -> V_20 , V_127 + 0x9 ,
V_282 ,
V_259 -> V_273 << V_283 ) ;
}
F_8 ( V_9 -> V_20 , V_127 + 2 ,
V_286 | V_287 ,
V_286 | V_259 -> V_269 ) ;
}
static int F_79 ( struct V_241 * V_242 )
{
struct V_9 * V_9 = V_242 -> V_9 ;
unsigned int V_58 ;
int V_32 ;
V_32 = F_11 ( V_9 -> V_20 , V_242 -> V_127 + 1 , & V_58 ) ;
if ( V_32 != 0 ) {
F_72 ( V_242 , L_50 ,
V_32 ) ;
return V_32 ;
}
return V_58 & V_288 ;
}
static int F_80 ( struct V_241 * V_242 )
{
struct V_9 * V_9 = V_242 -> V_9 ;
unsigned long V_289 ;
bool V_290 = false ;
int V_291 = F_79 ( V_242 ) ;
struct V_258 V_259 ;
if ( V_291 < 0 )
return V_291 ;
if ( V_291 ) {
F_8 ( V_242 -> V_9 -> V_20 , V_242 -> V_127 + 0x7 ,
V_282 , 0 ) ;
F_8 ( V_242 -> V_9 -> V_20 , V_242 -> V_127 + 1 ,
V_292 ,
V_292 ) ;
}
if ( V_242 -> V_293 >= 0 && V_242 -> V_294 &&
V_242 -> V_293 != V_242 -> V_295 ) {
F_76 ( V_242 , & V_259 , V_242 -> V_294 , false ) ;
F_78 ( V_9 , V_242 -> V_127 , & V_259 , V_242 -> V_293 ,
false ) ;
if ( V_242 -> V_295 >= 0 ) {
F_76 ( V_242 , & V_259 , V_242 -> V_296 , true ) ;
F_78 ( V_9 , V_242 -> V_127 + 0x10 , & V_259 ,
V_242 -> V_295 , true ) ;
V_290 = true ;
}
} else if ( V_242 -> V_295 >= 0 ) {
F_76 ( V_242 , & V_259 , V_242 -> V_296 , false ) ;
F_78 ( V_9 , V_242 -> V_127 , & V_259 ,
V_242 -> V_295 , false ) ;
F_8 ( V_9 -> V_20 , V_242 -> V_127 + 0x11 ,
V_297 , 0 ) ;
} else {
F_72 ( V_242 , L_51 ) ;
return - V_74 ;
}
if ( V_290 && V_242 -> V_296 > 100000 )
F_8 ( V_9 -> V_20 , V_242 -> V_127 + 0x17 ,
V_298 , 0 ) ;
else
F_8 ( V_9 -> V_20 , V_242 -> V_127 + 0x17 ,
V_298 ,
V_298 ) ;
if ( ! V_291 )
F_81 ( V_9 -> V_10 ) ;
F_82 ( & V_242 -> V_243 ) ;
F_8 ( V_9 -> V_20 , V_242 -> V_127 + 1 ,
V_288 , V_288 ) ;
if ( V_290 )
F_8 ( V_9 -> V_20 , V_242 -> V_127 + 0x11 ,
V_297 ,
V_297 ) ;
if ( V_291 )
F_8 ( V_9 -> V_20 , V_242 -> V_127 + 1 ,
V_292 , 0 ) ;
V_289 = F_83 ( & V_242 -> V_243 ,
F_84 ( 250 ) ) ;
if ( V_289 == 0 )
F_75 ( V_242 , L_52 ) ;
return 0 ;
}
static void F_85 ( struct V_241 * V_242 )
{
struct V_9 * V_9 = V_242 -> V_9 ;
bool V_299 ;
F_8 ( V_9 -> V_20 , V_242 -> V_127 + 1 ,
V_292 , V_292 ) ;
F_86 ( V_9 -> V_20 , V_242 -> V_127 + 1 ,
V_288 , 0 , & V_299 ) ;
F_14 ( V_9 -> V_20 , V_242 -> V_127 + 0x11 ,
V_297 , 0 ) ;
F_8 ( V_9 -> V_20 , V_242 -> V_127 + 1 ,
V_292 , 0 ) ;
if ( V_299 )
F_87 ( V_9 -> V_10 ) ;
}
int F_88 ( struct V_241 * V_242 , int V_103 ,
unsigned int V_244 , unsigned int V_245 )
{
int V_32 = 0 ;
if ( V_242 -> V_293 == V_103 && V_242 -> V_294 == V_244 )
return 0 ;
if ( V_242 -> V_247 && V_244 > 0 ) {
V_32 = F_71 ( V_242 , V_244 , V_242 -> V_247 ) ;
if ( V_32 != 0 )
return V_32 ;
}
V_242 -> V_293 = V_103 ;
V_242 -> V_294 = V_244 ;
if ( V_242 -> V_247 && V_244 > 0 ) {
V_32 = F_80 ( V_242 ) ;
}
return V_32 ;
}
int F_89 ( struct V_241 * V_242 , int V_103 ,
unsigned int V_244 , unsigned int V_245 )
{
int V_32 = 0 ;
if ( V_242 -> V_295 == V_103 &&
V_242 -> V_296 == V_244 && V_242 -> V_247 == V_245 )
return 0 ;
if ( V_245 ) {
if ( V_242 -> V_293 >= 0 ) {
V_32 = F_71 ( V_242 , V_242 -> V_294 , V_245 ) ;
if ( V_32 != 0 )
return V_32 ;
}
V_32 = F_71 ( V_242 , V_244 , V_245 ) ;
if ( V_32 != 0 )
return V_32 ;
}
V_242 -> V_295 = V_103 ;
V_242 -> V_296 = V_244 ;
V_242 -> V_247 = V_245 ;
if ( V_245 )
V_32 = F_80 ( V_242 ) ;
else
F_85 ( V_242 ) ;
return V_32 ;
}
int F_90 ( struct V_9 * V_9 , int V_163 , int V_127 , int V_300 ,
int V_301 , struct V_241 * V_242 )
{
int V_32 ;
unsigned int V_15 ;
F_91 ( & V_242 -> V_243 ) ;
V_242 -> V_163 = V_163 ;
V_242 -> V_127 = V_127 ;
V_242 -> V_9 = V_9 ;
V_242 -> V_295 = V_302 ;
F_11 ( V_9 -> V_20 , V_303 , & V_15 ) ;
switch ( V_15 & V_304 ) {
case V_305 :
case V_306 :
V_242 -> V_293 = V_15 & V_304 ;
break;
default:
V_242 -> V_293 = V_302 ;
}
V_242 -> V_294 = 32768 ;
snprintf ( V_242 -> V_307 , sizeof( V_242 -> V_307 ) , L_53 , V_163 ) ;
snprintf ( V_242 -> V_308 , sizeof( V_242 -> V_308 ) ,
L_54 , V_163 ) ;
V_32 = F_18 ( V_9 , V_301 , V_242 -> V_308 ,
F_68 , V_242 ) ;
if ( V_32 != 0 ) {
F_12 ( V_9 -> V_10 , L_55 ,
V_163 , V_32 ) ;
}
F_14 ( V_9 -> V_20 , V_242 -> V_127 + 1 ,
V_292 , 0 ) ;
return 0 ;
}
int F_92 ( struct V_6 * V_7 , int V_309 , bool V_310 )
{
unsigned int V_58 , V_15 ;
if ( V_309 < 1 || V_309 > 6 )
return - V_74 ;
V_58 = V_311 + ( V_309 - 1 ) * 8 ;
if ( V_310 )
V_15 = V_312 ;
else
V_15 = 0 ;
return F_26 ( V_7 , V_58 , V_312 , V_15 ) ;
}
