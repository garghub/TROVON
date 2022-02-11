static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
int V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 -> V_8 ) ;
struct V_9 * V_9 = F_3 ( V_7 -> V_10 -> V_11 ) ;
int V_12 ;
switch ( V_5 ) {
case V_13 :
V_12 = F_4 ( V_7 , V_14 ) ;
if ( V_12 & V_15 ) {
F_5 ( V_9 -> V_10 ,
L_1 ) ;
return - V_16 ;
}
F_6 ( V_9 -> V_17 ,
V_18 ,
1 << V_2 -> V_19 , 1 << V_2 -> V_19 ) ;
break;
case V_20 :
F_6 ( V_9 -> V_17 ,
V_18 ,
1 << V_2 -> V_19 , 0 ) ;
break;
default:
break;
}
return F_7 ( V_2 , V_4 , V_5 ) ;
}
static T_1 F_8 ( int V_21 , void * V_22 )
{
struct V_9 * V_9 = V_22 ;
unsigned int V_12 ;
int V_23 ;
V_23 = F_9 ( V_9 -> V_17 , V_14 ,
& V_12 ) ;
if ( V_23 != 0 ) {
F_10 ( V_9 -> V_10 , L_2 ,
V_23 ) ;
} else if ( V_12 & V_24 ) {
F_5 ( V_9 -> V_10 , L_3 ) ;
}
return V_25 ;
}
static T_1 F_11 ( int V_21 , void * V_22 )
{
struct V_9 * V_9 = V_22 ;
unsigned int V_12 ;
int V_23 ;
V_23 = F_9 ( V_9 -> V_17 , V_14 ,
& V_12 ) ;
if ( V_23 != 0 ) {
F_10 ( V_9 -> V_10 , L_2 ,
V_23 ) ;
} else if ( V_12 & V_15 ) {
F_5 ( V_9 -> V_10 , L_4 ) ;
V_23 = F_12 ( V_9 -> V_17 ,
V_18 ,
V_26 |
V_27 , 0 ) ;
if ( V_23 != 0 )
F_5 ( V_9 -> V_10 ,
L_5 ,
V_23 ) ;
}
return V_25 ;
}
int F_13 ( struct V_6 * V_7 )
{
struct V_28 * V_8 = F_14 ( V_7 ) ;
struct V_29 * V_30 = F_15 ( V_7 ) ;
struct V_9 * V_9 = V_30 -> V_9 ;
int V_23 ;
V_23 = F_16 ( V_8 , & V_31 , 1 ) ;
if ( V_23 != 0 )
return V_23 ;
switch ( V_9 -> type ) {
case V_32 :
case V_33 :
case V_34 :
break;
default:
V_23 = F_16 ( V_8 , & V_35 , 1 ) ;
if ( V_23 != 0 )
return V_23 ;
break;
}
V_23 = F_17 ( V_9 , V_36 ,
L_6 , F_8 ,
V_9 ) ;
if ( V_23 != 0 )
F_10 ( V_9 -> V_10 ,
L_7 ,
V_23 ) ;
V_23 = F_17 ( V_9 , V_37 ,
L_8 , F_11 ,
V_9 ) ;
if ( V_23 != 0 )
F_10 ( V_9 -> V_10 ,
L_9 ,
V_23 ) ;
return 0 ;
}
int F_18 ( struct V_6 * V_7 )
{
struct V_29 * V_30 = F_15 ( V_7 ) ;
struct V_9 * V_9 = V_30 -> V_9 ;
F_19 ( V_9 , V_36 , V_9 ) ;
F_19 ( V_9 , V_37 , V_9 ) ;
return 0 ;
}
int F_20 ( struct V_6 * V_7 )
{
struct V_28 * V_8 = F_14 ( V_7 ) ;
struct V_29 * V_30 = F_15 ( V_7 ) ;
struct V_9 * V_9 = V_30 -> V_9 ;
int V_38 ;
for ( V_38 = 0 ; V_38 < V_39 ; ++ V_38 ) {
if ( V_9 -> V_40 . V_41 [ V_38 ] )
F_21 ( V_8 ,
& V_42 [ V_38 ] , 1 ) ;
}
return 0 ;
}
int F_22 ( struct V_6 * V_7 )
{
struct V_28 * V_8 = F_14 ( V_7 ) ;
struct V_29 * V_30 = F_15 ( V_7 ) ;
struct V_9 * V_9 = V_30 -> V_9 ;
int V_38 ;
switch ( V_9 -> type ) {
case V_43 :
case V_44 :
F_23 ( V_8 , L_10 ) ;
break;
default:
break;
}
F_23 ( V_8 , L_11 ) ;
for ( V_38 = 0 ; V_38 < F_24 ( V_9 -> V_40 . V_45 ) ; V_38 ++ ) {
switch ( V_9 -> V_40 . V_45 [ V_38 ] & V_46 ) {
case V_47 :
F_25 ( V_8 , L_11 ) ;
break;
case V_48 :
F_25 ( V_8 , L_10 ) ;
break;
default:
break;
}
}
return 0 ;
}
int F_26 ( struct V_6 * V_7 )
{
struct V_29 * V_30 = F_15 ( V_7 ) ;
struct V_9 * V_9 = V_30 -> V_9 ;
F_27 ( & V_9 -> V_49 ) ;
return 0 ;
}
const char * F_28 ( unsigned int V_50 )
{
int V_38 ;
for ( V_38 = 0 ; V_38 < F_24 ( V_51 ) ; ++ V_38 ) {
if ( V_51 [ V_38 ] == V_50 )
return V_52 [ V_38 ] ;
}
return L_12 ;
}
static void F_29 ( struct V_6 * V_7 , int V_53 )
{
struct V_29 * V_30 = F_15 ( V_7 ) ;
unsigned int V_12 ;
int V_38 ;
if ( V_53 )
V_12 = V_54 ;
else
V_12 = 0 ;
for ( V_38 = 0 ; V_38 < V_30 -> V_55 ; V_38 ++ )
F_30 ( V_7 ,
V_56 + ( V_38 * 4 ) ,
V_54 , V_12 ) ;
}
bool F_31 ( struct V_6 * V_7 , int V_19 )
{
unsigned int V_57 = V_58 + ( ( V_19 / 2 ) * 8 ) ;
unsigned int V_12 = F_4 ( V_7 , V_57 ) ;
return ! ( V_12 & V_59 ) ;
}
int F_32 ( struct V_1 * V_2 , struct V_3 * V_4 ,
int V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 -> V_8 ) ;
struct V_29 * V_30 = F_15 ( V_7 ) ;
unsigned int V_57 ;
if ( V_2 -> V_19 % 2 )
V_57 = V_56 + ( ( V_2 -> V_19 / 2 ) * 8 ) ;
else
V_57 = V_60 + ( ( V_2 -> V_19 / 2 ) * 8 ) ;
switch ( V_5 ) {
case V_61 :
V_30 -> V_62 ++ ;
break;
case V_13 :
F_30 ( V_7 , V_57 , V_63 , 0 ) ;
V_30 -> V_62 -- ;
if ( V_30 -> V_62 == 0 ) {
F_33 ( 1 ) ;
F_29 ( V_7 , 1 ) ;
}
break;
case V_20 :
F_30 ( V_7 , V_57 ,
V_63 | V_54 ,
V_63 | V_54 ) ;
break;
case V_64 :
V_57 = F_4 ( V_7 , V_65 ) ;
if ( V_57 == 0 )
F_29 ( V_7 , 0 ) ;
break;
default:
break;
}
return 0 ;
}
int F_7 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
int V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 -> V_8 ) ;
struct V_29 * V_30 = F_15 ( V_7 ) ;
struct V_9 * V_9 = V_30 -> V_9 ;
switch ( V_5 ) {
case V_61 :
switch ( V_2 -> V_19 ) {
case V_66 :
case V_67 :
case V_68 :
case V_69 :
case V_70 :
case V_71 :
V_30 -> V_72 ++ ;
V_30 -> V_73 += 17 ;
break;
case V_74 :
case V_75 :
V_30 -> V_72 ++ ;
switch ( V_9 -> type ) {
case V_76 :
case V_32 :
break;
default:
V_30 -> V_73 += 10 ;
break;
}
break;
default:
break;
}
break;
case V_13 :
switch ( V_2 -> V_19 ) {
case V_66 :
case V_67 :
case V_68 :
case V_69 :
case V_70 :
case V_71 :
case V_74 :
case V_75 :
V_30 -> V_72 -- ;
if ( ! V_30 -> V_72 && V_30 -> V_73 ) {
F_34 ( V_7 -> V_10 , L_13 ,
V_30 -> V_73 ) ;
F_33 ( V_30 -> V_73 ) ;
V_30 -> V_73 = 0 ;
}
break;
default:
break;
}
break;
case V_20 :
switch ( V_2 -> V_19 ) {
case V_66 :
case V_67 :
case V_68 :
case V_69 :
case V_70 :
case V_71 :
V_30 -> V_77 ++ ;
V_30 -> V_78 ++ ;
break;
case V_74 :
case V_75 :
V_30 -> V_77 ++ ;
switch ( V_9 -> type ) {
case V_76 :
case V_32 :
break;
case V_79 :
case V_80 :
V_30 -> V_78 += 5 ;
break;
default:
V_30 -> V_78 ++ ;
break;
}
default:
break;
}
break;
case V_64 :
switch ( V_2 -> V_19 ) {
case V_66 :
case V_67 :
case V_68 :
case V_69 :
case V_70 :
case V_71 :
case V_74 :
case V_75 :
V_30 -> V_77 -- ;
if ( ! V_30 -> V_77 && V_30 -> V_78 ) {
F_34 ( V_7 -> V_10 , L_14 ,
V_30 -> V_78 ) ;
F_33 ( V_30 -> V_78 ) ;
V_30 -> V_78 = 0 ;
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
int F_35 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
int V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 -> V_8 ) ;
struct V_29 * V_30 = F_15 ( V_7 ) ;
struct V_9 * V_9 = V_30 -> V_9 ;
unsigned int V_81 = 1 << V_2 -> V_19 ;
unsigned int V_12 ;
switch ( V_5 ) {
case V_13 :
V_12 = V_81 ;
break;
case V_20 :
V_12 = 0 ;
break;
case V_61 :
case V_64 :
return F_7 ( V_2 , V_4 , V_5 ) ;
default:
return - V_82 ;
}
V_30 -> V_9 -> V_83 &= ~ V_81 ;
V_30 -> V_9 -> V_83 |= V_12 ;
if ( V_30 -> V_9 -> V_84 )
V_12 = 0 ;
F_6 ( V_9 -> V_17 , V_18 ,
V_81 , V_12 ) ;
return F_7 ( V_2 , V_4 , V_5 ) ;
}
static int F_36 ( struct V_6 * V_7 )
{
const struct V_29 * V_30 = F_15 ( V_7 ) ;
struct V_9 * V_9 = V_30 -> V_9 ;
int V_23 ;
V_23 = F_37 ( V_9 -> V_85 , 1800000 , 1800000 ) ;
if ( V_23 ) {
F_10 ( V_7 -> V_10 , L_15 , V_23 ) ;
return V_23 ;
}
V_23 = F_12 ( V_9 -> V_17 ,
V_86 ,
V_87 ,
V_87 ) ;
if ( V_23 ) {
F_10 ( V_7 -> V_10 , L_16 , V_23 ) ;
F_37 ( V_9 -> V_85 , 1200000 , 1800000 ) ;
return V_23 ;
}
return 0 ;
}
static int F_38 ( struct V_6 * V_7 )
{
const struct V_29 * V_30 = F_15 ( V_7 ) ;
struct V_9 * V_9 = V_30 -> V_9 ;
int V_23 ;
V_23 = F_12 ( V_9 -> V_17 ,
V_86 ,
V_87 , 0 ) ;
if ( V_23 ) {
F_10 ( V_7 -> V_10 , L_17 , V_23 ) ;
return V_23 ;
}
V_23 = F_37 ( V_9 -> V_85 , 1200000 , 1800000 ) ;
if ( V_23 ) {
F_10 ( V_7 -> V_10 , L_18 , V_23 ) ;
return V_23 ;
}
return 0 ;
}
int F_39 ( struct V_6 * V_7 , unsigned int V_88 )
{
struct V_29 * V_30 = F_15 ( V_7 ) ;
int V_23 = 0 ;
F_40 ( & V_30 -> V_89 ) ;
if ( ! V_30 -> V_90 && ! V_30 -> V_91 ) {
V_23 = F_36 ( V_7 ) ;
if ( V_23 )
goto V_92;
}
V_30 -> V_91 |= V_88 ;
V_92:
F_41 ( & V_30 -> V_89 ) ;
return V_23 ;
}
int F_42 ( struct V_6 * V_7 , unsigned int V_88 )
{
struct V_29 * V_30 = F_15 ( V_7 ) ;
unsigned int V_93 ;
int V_23 = 0 ;
F_40 ( & V_30 -> V_89 ) ;
V_93 = V_30 -> V_91 ;
V_30 -> V_91 &= ~ V_88 ;
if ( ! V_30 -> V_90 && V_93 && ! V_30 -> V_91 )
V_23 = F_38 ( V_7 ) ;
F_41 ( & V_30 -> V_89 ) ;
return V_23 ;
}
int F_43 ( struct V_1 * V_2 ,
struct V_3 * V_4 , int V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 -> V_8 ) ;
struct V_29 * V_30 = F_15 ( V_7 ) ;
int V_23 = 0 ;
F_40 ( & V_30 -> V_89 ) ;
switch ( V_5 ) {
case V_13 :
if ( V_30 -> V_91 )
V_23 = F_36 ( V_7 ) ;
V_30 -> V_90 = false ;
break;
case V_20 :
V_30 -> V_90 = true ;
if ( V_30 -> V_91 )
V_23 = F_38 ( V_7 ) ;
break;
default:
break;
}
F_41 ( & V_30 -> V_89 ) ;
return V_23 ;
}
void F_44 ( struct V_29 * V_30 )
{
F_45 ( & V_30 -> V_89 ) ;
}
int F_46 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
int V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 -> V_8 ) ;
unsigned int V_12 ;
switch ( V_5 ) {
case V_13 :
V_12 = 1 << V_2 -> V_19 ;
break;
case V_20 :
V_12 = 1 << ( V_2 -> V_19 + 1 ) ;
break;
default:
return 0 ;
}
F_47 ( V_7 , V_94 , V_12 ) ;
return 0 ;
}
static int F_48 ( struct V_6 * V_7 , unsigned int V_95 ,
unsigned int V_96 )
{
struct V_29 * V_30 = F_15 ( V_7 ) ;
unsigned int V_57 ;
unsigned int * V_97 ;
int V_98 , div , V_99 ;
switch ( V_95 ) {
case V_100 :
V_57 = V_101 ;
V_99 = V_30 -> V_102 ;
break;
case V_103 :
V_57 = V_104 ;
V_99 = V_30 -> V_105 ;
break;
default:
return - V_82 ;
}
if ( V_99 % 8000 )
V_97 = V_106 ;
else
V_97 = V_107 ;
for ( V_98 = 0 ; V_98 < F_24 ( V_107 ) &&
V_97 [ V_98 ] <= V_99 ; V_98 ++ ) {
div = 1 ;
while ( V_97 [ V_98 ] / div >= V_96 && div < 32 ) {
if ( V_97 [ V_98 ] / div == V_96 ) {
F_34 ( V_7 -> V_10 , L_19 ,
V_96 ) ;
F_30 ( V_7 , V_57 ,
V_108 |
V_109 ,
( div <<
V_110 ) |
V_98 ) ;
return 0 ;
}
div ++ ;
}
}
F_10 ( V_7 -> V_10 , L_20 , V_96 ) ;
return - V_82 ;
}
int F_49 ( struct V_6 * V_7 , int V_111 ,
int V_112 , unsigned int V_96 , int V_113 )
{
struct V_29 * V_30 = F_15 ( V_7 ) ;
struct V_9 * V_9 = V_30 -> V_9 ;
char * V_114 ;
unsigned int V_57 ;
unsigned int V_81 = V_115 | V_116 ;
unsigned int V_12 = V_112 << V_117 ;
int * V_95 ;
switch ( V_111 ) {
case V_118 :
V_114 = L_21 ;
V_57 = V_119 ;
V_95 = & V_30 -> V_102 ;
V_81 |= V_120 ;
break;
case V_121 :
V_114 = L_22 ;
V_57 = V_122 ;
V_95 = & V_30 -> V_105 ;
break;
case V_100 :
case V_103 :
return F_48 ( V_7 , V_111 , V_96 ) ;
default:
return - V_82 ;
}
switch ( V_96 ) {
case 5644800 :
case 6144000 :
break;
case 11289600 :
case 12288000 :
V_12 |= V_123 << V_124 ;
break;
case 22579200 :
case 24576000 :
V_12 |= V_125 << V_124 ;
break;
case 45158400 :
case 49152000 :
V_12 |= V_126 << V_124 ;
break;
case 67737600 :
case 73728000 :
V_12 |= V_127 << V_124 ;
break;
case 90316800 :
case 98304000 :
V_12 |= V_128 << V_124 ;
break;
case 135475200 :
case 147456000 :
V_12 |= V_129 << V_124 ;
break;
case 0 :
F_34 ( V_9 -> V_10 , L_23 , V_114 ) ;
* V_95 = V_96 ;
return 0 ;
default:
return - V_82 ;
}
* V_95 = V_96 ;
if ( V_96 % 6144000 )
V_12 |= V_120 ;
F_34 ( V_9 -> V_10 , L_24 , V_114 , V_96 ) ;
return F_12 ( V_9 -> V_17 , V_57 , V_81 , V_12 ) ;
}
static int F_50 ( struct V_130 * V_131 , unsigned int V_132 )
{
struct V_6 * V_7 = V_131 -> V_7 ;
struct V_29 * V_30 = F_15 ( V_7 ) ;
struct V_9 * V_9 = V_30 -> V_9 ;
int V_133 , V_134 , V_135 , V_136 ;
V_136 = V_131 -> V_137 -> V_136 ;
V_133 = 0 ;
V_134 = 0 ;
switch ( V_132 & V_138 ) {
case V_139 :
V_135 = V_140 ;
break;
case V_141 :
if ( ( V_132 & V_142 )
!= V_143 ) {
F_51 ( V_131 , L_25 ) ;
return - V_82 ;
}
V_135 = V_144 ;
break;
case V_145 :
V_135 = V_146 ;
break;
case V_147 :
if ( ( V_132 & V_142 )
!= V_143 ) {
F_51 ( V_131 , L_26 ) ;
return - V_82 ;
}
V_135 = V_148 ;
break;
default:
F_51 ( V_131 , L_27 ,
V_132 & V_138 ) ;
return - V_82 ;
}
switch ( V_132 & V_142 ) {
case V_149 :
break;
case V_150 :
V_133 |= V_151 ;
break;
case V_152 :
V_134 |= V_153 ;
break;
case V_143 :
V_134 |= V_153 ;
V_133 |= V_151 ;
break;
default:
F_51 ( V_131 , L_28 ,
V_132 & V_142 ) ;
return - V_82 ;
}
switch ( V_132 & V_154 ) {
case V_155 :
break;
case V_156 :
V_134 |= V_157 ;
V_133 |= V_158 ;
break;
case V_159 :
V_134 |= V_157 ;
break;
case V_160 :
V_133 |= V_158 ;
break;
default:
return - V_82 ;
}
F_6 ( V_9 -> V_17 , V_136 + V_161 ,
V_157 |
V_153 ,
V_134 ) ;
F_6 ( V_9 -> V_17 , V_136 + V_162 ,
V_158 |
V_151 , V_133 ) ;
F_6 ( V_9 -> V_17 ,
V_136 + V_163 ,
V_164 |
V_165 , V_133 ) ;
F_12 ( V_9 -> V_17 , V_136 + V_166 ,
V_167 , V_135 ) ;
return 0 ;
}
static int F_52 ( struct V_168 * V_169 ,
struct V_130 * V_131 )
{
struct V_6 * V_7 = V_131 -> V_7 ;
struct V_29 * V_30 = F_15 ( V_7 ) ;
struct V_170 * V_171 = & V_30 -> V_131 [ V_131 -> V_172 - 1 ] ;
unsigned int V_173 ;
if ( ! V_169 -> V_174 )
return 0 ;
switch ( V_171 -> V_95 ) {
case V_118 :
V_173 = V_30 -> V_102 ;
break;
case V_121 :
V_173 = V_30 -> V_105 ;
break;
default:
return 0 ;
}
if ( V_173 == 0 )
V_171 -> V_175 . V_81 = V_176 ;
else if ( V_173 % 8000 )
V_171 -> V_175 . V_81 = V_177 ;
else
V_171 -> V_175 . V_81 = V_178 ;
return F_53 ( V_169 -> V_174 , 0 ,
V_179 ,
& V_171 -> V_175 ) ;
}
static void F_54 ( struct V_6 * V_7 ,
unsigned int V_180 )
{
struct V_29 * V_30 = F_15 ( V_7 ) ;
struct V_9 * V_9 = V_30 -> V_9 ;
struct V_181 V_182 [] = {
{ 0x80 , 0x3 } ,
{ V_183 , 0 } ,
{ V_184 , 0 } ,
{ 0x80 , 0x0 } ,
} ;
F_40 ( & V_9 -> V_185 ) ;
V_182 [ 1 ] . V_186 = V_9 -> V_187 ;
if ( V_180 >= 176400 )
V_182 [ 2 ] . V_186 = V_9 -> V_188 ;
F_41 ( & V_9 -> V_185 ) ;
F_55 ( V_9 -> V_17 ,
V_182 ,
F_24 ( V_182 ) ) ;
}
static int F_56 ( struct V_168 * V_169 ,
struct V_189 * V_190 ,
struct V_130 * V_131 )
{
struct V_6 * V_7 = V_131 -> V_7 ;
struct V_29 * V_30 = F_15 ( V_7 ) ;
struct V_170 * V_171 = & V_30 -> V_131 [ V_131 -> V_172 - 1 ] ;
int V_136 = V_131 -> V_137 -> V_136 ;
int V_38 , V_191 , V_23 ;
for ( V_38 = 0 ; V_38 < F_24 ( V_192 ) ; V_38 ++ )
if ( V_192 [ V_38 ] == F_57 ( V_190 ) )
break;
if ( V_38 == F_24 ( V_192 ) ) {
F_51 ( V_131 , L_29 ,
F_57 ( V_190 ) ) ;
return - V_82 ;
}
V_191 = V_38 ;
switch ( V_30 -> V_9 -> type ) {
case V_76 :
case V_32 :
if ( V_192 [ V_191 ] >= 88200 )
V_23 = F_39 ( V_7 , V_193 ) ;
else
V_23 = F_42 ( V_7 , V_193 ) ;
if ( V_23 ) {
F_51 ( V_131 , L_30 , V_23 ) ;
return V_23 ;
}
break;
default:
break;
}
switch ( V_171 -> V_95 ) {
case V_118 :
switch ( V_30 -> V_9 -> type ) {
case V_76 :
F_54 ( V_7 ,
F_57 ( V_190 ) ) ;
break;
default:
break;
}
F_30 ( V_7 , V_194 ,
V_195 , V_191 ) ;
if ( V_136 )
F_30 ( V_7 , V_136 + V_196 ,
V_197 , 0 ) ;
break;
case V_121 :
F_30 ( V_7 , V_198 ,
V_199 , V_191 ) ;
if ( V_136 )
F_30 ( V_7 , V_136 + V_196 ,
V_197 ,
8 << V_200 ) ;
break;
default:
F_51 ( V_131 , L_31 , V_171 -> V_95 ) ;
return - V_82 ;
}
return 0 ;
}
static bool F_58 ( struct V_6 * V_7 ,
int V_136 , int V_134 , int V_133 , int V_201 )
{
int V_12 ;
V_12 = F_4 ( V_7 , V_136 + V_161 ) ;
if ( V_134 != ( V_12 & V_202 ) )
return true ;
V_12 = F_4 ( V_7 , V_136 + V_203 ) ;
if ( V_133 != ( V_12 & V_204 ) )
return true ;
V_12 = F_4 ( V_7 , V_136 + V_205 ) ;
if ( V_201 != ( V_12 & ( V_206 |
V_207 ) ) )
return true ;
return false ;
}
static int F_59 ( struct V_168 * V_169 ,
struct V_189 * V_190 ,
struct V_130 * V_131 )
{
struct V_6 * V_7 = V_131 -> V_7 ;
struct V_29 * V_30 = F_15 ( V_7 ) ;
struct V_9 * V_9 = V_30 -> V_9 ;
int V_136 = V_131 -> V_137 -> V_136 ;
const int * V_97 ;
int V_38 , V_23 , V_12 ;
int V_208 = F_60 ( V_190 ) ;
int V_209 = V_9 -> V_40 . V_210 [ V_131 -> V_172 - 1 ] ;
int V_211 = V_9 -> V_211 [ V_131 -> V_172 - 1 ] ;
int V_212 = V_9 -> V_212 [ V_131 -> V_172 - 1 ] ;
int V_134 , V_133 , V_213 , V_201 , V_214 ;
bool V_215 ;
unsigned int V_216 , V_217 ;
if ( F_57 ( V_190 ) % 4000 )
V_97 = & V_218 [ 0 ] ;
else
V_97 = & V_219 [ 0 ] ;
V_213 = F_61 ( V_190 ) ;
if ( V_212 ) {
F_62 ( V_131 , L_32 ,
V_212 , V_211 ) ;
V_214 = V_212 * V_211 * F_57 ( V_190 ) ;
V_208 = V_212 ;
} else {
V_214 = F_63 ( V_190 ) ;
V_211 = V_213 ;
}
if ( V_209 && V_209 < V_208 ) {
F_62 ( V_131 , L_33 , V_209 ) ;
V_214 /= V_208 ;
V_214 *= V_209 ;
}
V_12 = F_4 ( V_7 , V_136 + V_166 ) ;
V_12 &= V_167 ;
if ( ( V_208 & 1 ) && ( V_12 == V_146 ) ) {
F_62 ( V_131 , L_34 ) ;
V_214 /= V_208 ;
V_214 *= V_208 + 1 ;
}
for ( V_38 = 0 ; V_38 < F_24 ( V_218 ) ; V_38 ++ ) {
if ( V_97 [ V_38 ] >= V_214 &&
V_97 [ V_38 ] % F_57 ( V_190 ) == 0 ) {
V_134 = V_38 ;
break;
}
}
if ( V_38 == F_24 ( V_218 ) ) {
F_51 ( V_131 , L_29 ,
F_57 ( V_190 ) ) ;
return - V_82 ;
}
V_133 = V_97 [ V_134 ] / F_57 ( V_190 ) ;
F_62 ( V_131 , L_35 ,
V_97 [ V_134 ] , V_97 [ V_134 ] / V_133 ) ;
V_201 = V_213 << V_220 | V_211 ;
V_215 = F_58 ( V_7 , V_136 , V_134 , V_133 , V_201 ) ;
if ( V_215 ) {
V_216 = F_4 ( V_7 ,
V_136 + V_221 ) ;
V_217 = F_4 ( V_7 ,
V_136 + V_222 ) ;
F_6 ( V_9 -> V_17 ,
V_136 + V_221 , 0xff , 0x0 ) ;
F_12 ( V_9 -> V_17 ,
V_136 + V_222 , 0xff , 0x0 ) ;
}
V_23 = F_56 ( V_169 , V_190 , V_131 ) ;
if ( V_23 != 0 )
goto V_223;
if ( V_215 ) {
F_6 ( V_9 -> V_17 ,
V_136 + V_161 ,
V_202 , V_134 ) ;
F_6 ( V_9 -> V_17 ,
V_136 + V_203 ,
V_204 , V_133 ) ;
F_6 ( V_9 -> V_17 ,
V_136 + V_224 ,
V_225 , V_133 ) ;
F_6 ( V_9 -> V_17 ,
V_136 + V_205 ,
V_206 |
V_207 , V_201 ) ;
F_12 ( V_9 -> V_17 ,
V_136 + V_226 ,
V_227 |
V_228 , V_201 ) ;
}
V_223:
if ( V_215 ) {
F_6 ( V_9 -> V_17 ,
V_136 + V_221 ,
0xff , V_216 ) ;
F_12 ( V_9 -> V_17 ,
V_136 + V_222 ,
0xff , V_217 ) ;
}
return V_23 ;
}
static const char * F_64 ( int V_111 )
{
switch ( V_111 ) {
case V_118 :
return L_21 ;
case V_121 :
return L_22 ;
default:
return L_36 ;
}
}
static int F_65 ( struct V_130 * V_131 ,
int V_111 , unsigned int V_96 , int V_113 )
{
struct V_6 * V_7 = V_131 -> V_7 ;
struct V_28 * V_8 = F_14 ( V_7 ) ;
struct V_29 * V_30 = F_15 ( V_7 ) ;
struct V_170 * V_171 = & V_30 -> V_131 [ V_131 -> V_172 - 1 ] ;
struct V_229 V_230 [ 2 ] ;
switch ( V_111 ) {
case V_118 :
case V_121 :
break;
default:
return - V_82 ;
}
if ( V_111 == V_171 -> V_95 )
return 0 ;
if ( V_131 -> V_231 ) {
F_10 ( V_7 -> V_10 , L_37 ,
V_131 -> V_172 ) ;
return - V_16 ;
}
F_34 ( V_7 -> V_10 , L_38 , V_131 -> V_172 + 1 ,
F_64 ( V_111 ) ) ;
memset ( & V_230 , 0 , sizeof( V_230 ) ) ;
V_230 [ 0 ] . V_232 = V_131 -> V_137 -> V_233 . V_234 ;
V_230 [ 1 ] . V_232 = V_131 -> V_137 -> V_235 . V_234 ;
V_230 [ 0 ] . V_112 = F_64 ( V_171 -> V_95 ) ;
V_230 [ 1 ] . V_112 = F_64 ( V_171 -> V_95 ) ;
F_66 ( V_8 , V_230 , F_24 ( V_230 ) ) ;
V_230 [ 0 ] . V_112 = F_64 ( V_111 ) ;
V_230 [ 1 ] . V_112 = F_64 ( V_111 ) ;
F_21 ( V_8 , V_230 , F_24 ( V_230 ) ) ;
V_171 -> V_95 = V_111 ;
return F_67 ( V_8 ) ;
}
static int F_68 ( struct V_130 * V_131 , int V_236 )
{
struct V_6 * V_7 = V_131 -> V_7 ;
int V_136 = V_131 -> V_137 -> V_136 ;
unsigned int V_57 ;
if ( V_236 )
V_57 = V_237 ;
else
V_57 = 0 ;
return F_30 ( V_7 , V_136 + V_196 ,
V_237 , V_57 ) ;
}
static void F_69 ( struct V_130 * V_131 ,
unsigned int V_136 ,
int V_208 , unsigned int V_81 )
{
struct V_6 * V_7 = V_131 -> V_7 ;
struct V_29 * V_30 = F_15 ( V_7 ) ;
struct V_9 * V_9 = V_30 -> V_9 ;
int V_238 , V_38 ;
for ( V_38 = 0 ; V_38 < V_208 ; ++ V_38 ) {
V_238 = F_70 ( V_81 ) - 1 ;
if ( V_238 < 0 )
return;
F_71 ( V_9 -> V_17 , V_136 + V_38 , V_238 ) ;
V_81 &= ~ ( 1 << V_238 ) ;
}
if ( V_81 )
F_72 ( V_131 , L_39 ) ;
}
static int F_73 ( struct V_130 * V_131 , unsigned int V_239 ,
unsigned int V_240 , int V_241 , int V_242 )
{
struct V_6 * V_7 = V_131 -> V_7 ;
struct V_29 * V_30 = F_15 ( V_7 ) ;
struct V_9 * V_9 = V_30 -> V_9 ;
int V_136 = V_131 -> V_137 -> V_136 ;
int V_243 = V_131 -> V_137 -> V_235 . V_244 ;
int V_245 = V_131 -> V_137 -> V_233 . V_244 ;
if ( V_131 -> V_172 > V_246 )
return - V_247 ;
if ( V_241 == 0 ) {
V_239 = ( 1 << V_245 ) - 1 ;
V_240 = ( 1 << V_243 ) - 1 ;
}
F_69 ( V_131 , V_136 + V_248 ,
V_245 , V_239 ) ;
F_69 ( V_131 , V_136 + V_249 ,
V_243 , V_240 ) ;
V_9 -> V_211 [ V_131 -> V_172 - 1 ] = V_242 ;
V_9 -> V_212 [ V_131 -> V_172 - 1 ] = V_241 ;
return 0 ;
}
int F_74 ( struct V_29 * V_30 , int V_172 )
{
struct V_170 * V_171 = & V_30 -> V_131 [ V_172 ] ;
V_171 -> V_95 = V_118 ;
V_171 -> V_175 = V_250 ;
return 0 ;
}
static int F_75 ( struct V_251 * V_252 ,
unsigned int V_253 ,
unsigned int V_254 )
{
unsigned int V_255 ;
if ( V_252 -> V_256 && V_254 != V_252 -> V_256 ) {
F_76 ( V_252 ,
L_40 ) ;
return - V_82 ;
}
if ( V_253 / V_257 > V_258 ) {
F_76 ( V_252 ,
L_41 ,
V_253 ) ;
return - V_82 ;
}
V_255 = V_259 * V_252 -> V_260 ;
if ( V_254 * V_261 < V_255 ) {
F_76 ( V_252 , L_42 ,
V_254 ) ;
return - V_82 ;
}
return 0 ;
}
static int F_77 ( unsigned int V_253 , int * V_262 )
{
int V_38 ;
for ( V_38 = 0 ; V_38 < F_24 ( V_263 ) ; V_38 ++ ) {
if ( V_263 [ V_38 ] . V_264 <= V_253 && V_253 <= V_263 [ V_38 ] . V_265 ) {
if ( V_262 )
* V_262 = V_263 [ V_38 ] . V_262 ;
return V_263 [ V_38 ] . V_266 ;
}
}
return - V_82 ;
}
static int F_78 ( struct V_251 * V_252 ,
struct V_267 * V_268 ,
unsigned int V_269 ,
unsigned int V_253 , bool V_270 )
{
int V_271 , V_266 ;
int V_272 , div ;
div = 1 ;
V_268 -> V_272 = 0 ;
while ( V_253 > V_258 ) {
div *= 2 ;
V_253 /= 2 ;
V_268 -> V_272 ++ ;
if ( div > V_257 )
return - V_82 ;
}
V_271 = F_77 ( V_253 , & V_268 -> V_262 ) ;
if ( V_271 < 0 ) {
F_76 ( V_252 , L_43 ,
V_253 ) ;
return V_271 ;
}
switch ( V_252 -> V_9 -> type ) {
case V_76 :
case V_32 :
return V_271 ;
case V_43 :
case V_44 :
if ( V_252 -> V_9 -> V_273 < 3 || V_270 )
return V_271 ;
break;
default:
if ( V_270 )
return V_271 ;
break;
}
V_268 -> V_262 = V_271 - 1 ;
V_272 = V_268 -> V_272 ;
F_79 ( V_252 , L_44 ,
V_271 , V_253 , V_272 ) ;
while ( div <= V_257 ) {
for ( V_266 = V_271 ; V_266 > 0 ; V_266 -- ) {
if ( V_269 % ( V_266 * V_253 ) ) {
V_268 -> V_272 = V_272 ;
V_268 -> V_262 = V_266 - 1 ;
F_79 ( V_252 ,
L_45 ,
V_253 , V_272 , div , V_266 ) ;
return V_266 ;
}
}
for ( V_266 = V_271 + 1 ; V_266 <= V_274 ;
V_266 ++ ) {
if ( ( V_275 / 2 ) /
( V_252 -> V_260 * V_266 ) < V_253 ) {
F_79 ( V_252 , L_46 ) ;
break;
}
if ( V_253 > V_276 [ V_266 - 1 ] ) {
F_79 ( V_252 ,
L_47 ,
V_276 [ V_266 - 1 ] ,
V_266 ) ;
break;
}
if ( V_269 % ( V_266 * V_253 ) ) {
V_268 -> V_272 = V_272 ;
V_268 -> V_262 = V_266 - 1 ;
F_79 ( V_252 ,
L_45 ,
V_253 , V_272 , div , V_266 ) ;
return V_266 ;
}
}
div *= 2 ;
V_253 /= 2 ;
V_272 ++ ;
V_271 = F_77 ( V_253 , NULL ) ;
F_79 ( V_252 ,
L_48 ,
V_253 , V_272 , div , V_271 ) ;
}
F_80 ( V_252 , L_49 ) ;
return V_268 -> V_262 + 1 ;
}
static int F_81 ( struct V_251 * V_252 ,
struct V_267 * V_268 ,
unsigned int V_253 , bool V_270 )
{
unsigned int V_269 , div , V_277 ;
int V_38 , V_266 ;
F_79 ( V_252 , L_50 , V_253 , V_252 -> V_256 ) ;
div = V_278 ;
while ( V_252 -> V_256 * div < V_259 * V_252 -> V_260 ) {
div ++ ;
if ( div > V_261 )
return - V_82 ;
}
V_269 = V_252 -> V_256 * div / V_252 -> V_260 ;
V_268 -> V_279 = div ;
F_79 ( V_252 , L_51 , V_269 ) ;
V_266 = F_78 ( V_252 , V_268 , V_269 , V_253 , V_270 ) ;
if ( V_266 < 0 )
return V_266 ;
V_253 = V_253 / ( 1 << V_268 -> V_272 ) ;
V_268 -> V_280 = V_269 / ( V_266 * V_253 ) ;
if ( V_269 % ( V_266 * V_253 ) ) {
V_277 = F_82 ( V_269 , V_266 * V_253 ) ;
F_79 ( V_252 , L_52 , V_277 ) ;
V_268 -> V_281 = ( V_269 - ( V_268 -> V_280 * V_266 * V_253 ) )
/ V_277 ;
V_268 -> V_282 = ( V_266 * V_253 ) / V_277 ;
} else {
V_268 -> V_281 = 0 ;
V_268 -> V_282 = 0 ;
}
while ( V_268 -> V_282 >= ( 1 << 16 ) ) {
V_268 -> V_281 >>= 1 ;
V_268 -> V_282 >>= 1 ;
}
for ( V_38 = 0 ; V_38 < F_24 ( V_283 ) ; V_38 ++ ) {
if ( V_283 [ V_38 ] . V_264 <= V_253 && V_253 <= V_283 [ V_38 ] . V_265 ) {
V_268 -> V_284 = V_283 [ V_38 ] . V_284 ;
break;
}
}
if ( V_38 == F_24 ( V_283 ) ) {
F_76 ( V_252 , L_53 ,
V_253 ) ;
return - V_82 ;
}
F_79 ( V_252 , L_54 ,
V_268 -> V_280 , V_268 -> V_281 , V_268 -> V_282 ) ;
F_79 ( V_252 , L_55 ,
V_268 -> V_262 , V_266 , V_268 -> V_279 ,
V_268 -> V_272 , 1 << V_268 -> V_272 ) ;
F_79 ( V_252 , L_56 , V_268 -> V_284 , 1 << V_268 -> V_284 ) ;
return 0 ;
}
static void F_83 ( struct V_9 * V_9 , unsigned int V_136 ,
struct V_267 * V_268 , int V_112 ,
bool V_270 )
{
F_6 ( V_9 -> V_17 , V_136 + 3 ,
V_285 , V_268 -> V_281 ) ;
F_6 ( V_9 -> V_17 , V_136 + 4 ,
V_286 , V_268 -> V_282 ) ;
F_6 ( V_9 -> V_17 , V_136 + 5 ,
V_287 ,
V_268 -> V_262 << V_288 ) ;
F_6 ( V_9 -> V_17 , V_136 + 6 ,
V_289 |
V_290 ,
V_268 -> V_272 << V_291 |
V_112 << V_292 ) ;
if ( V_270 ) {
F_12 ( V_9 -> V_17 , V_136 + 0x7 ,
V_293 ,
V_268 -> V_284 << V_294 ) ;
} else {
F_12 ( V_9 -> V_17 , V_136 + 0x5 ,
V_295 ,
V_268 -> V_279 << V_296 ) ;
F_12 ( V_9 -> V_17 , V_136 + 0x9 ,
V_293 ,
V_268 -> V_284 << V_294 ) ;
}
F_6 ( V_9 -> V_17 , V_136 + 2 ,
V_297 | V_298 ,
V_297 | V_268 -> V_280 ) ;
}
static int F_84 ( struct V_251 * V_252 , int V_136 )
{
struct V_9 * V_9 = V_252 -> V_9 ;
unsigned int V_57 ;
int V_23 ;
V_23 = F_9 ( V_9 -> V_17 , V_136 + 1 , & V_57 ) ;
if ( V_23 != 0 ) {
F_76 ( V_252 , L_57 ,
V_23 ) ;
return V_23 ;
}
return V_57 & V_299 ;
}
static int F_85 ( struct V_251 * V_252 )
{
struct V_9 * V_9 = V_252 -> V_9 ;
bool V_300 = false ;
int V_301 = F_84 ( V_252 , V_252 -> V_136 ) ;
int V_302 = F_84 ( V_252 , V_252 -> V_136 + 0x10 ) ;
struct V_267 V_268 ;
int V_38 ;
unsigned int V_12 ;
if ( V_301 < 0 )
return V_301 ;
if ( V_302 < 0 )
return V_302 ;
if ( V_301 ) {
F_12 ( V_252 -> V_9 -> V_17 , V_252 -> V_136 + 1 ,
V_303 , V_303 ) ;
F_86 ( 32 ) ;
F_6 ( V_252 -> V_9 -> V_17 , V_252 -> V_136 + 0x9 ,
V_293 , 0 ) ;
}
if ( V_252 -> V_304 >= 0 && V_252 -> V_305 &&
V_252 -> V_304 != V_252 -> V_306 ) {
F_81 ( V_252 , & V_268 , V_252 -> V_305 , false ) ;
if ( V_252 -> V_306 >= 0 && V_268 . V_282 )
V_268 . V_281 = ( V_268 . V_281 * ( 1 << 16 ) ) / V_268 . V_282 ;
F_83 ( V_9 , V_252 -> V_136 , & V_268 , V_252 -> V_304 ,
false ) ;
if ( V_252 -> V_306 >= 0 ) {
F_81 ( V_252 , & V_268 , V_252 -> V_307 , true ) ;
F_83 ( V_9 , V_252 -> V_136 + 0x10 , & V_268 ,
V_252 -> V_306 , true ) ;
V_300 = true ;
}
} else if ( V_252 -> V_306 >= 0 ) {
F_81 ( V_252 , & V_268 , V_252 -> V_307 , false ) ;
F_83 ( V_9 , V_252 -> V_136 , & V_268 ,
V_252 -> V_306 , false ) ;
F_6 ( V_9 -> V_17 , V_252 -> V_136 + 0x11 ,
V_308 , 0 ) ;
} else {
F_76 ( V_252 , L_58 ) ;
return - V_82 ;
}
if ( V_301 && ! ! V_302 != V_300 )
F_80 ( V_252 , L_59 ) ;
if ( V_300 && V_252 -> V_307 > 100000 )
F_6 ( V_9 -> V_17 , V_252 -> V_136 + 0x17 ,
V_309 , 0 ) ;
else
F_6 ( V_9 -> V_17 , V_252 -> V_136 + 0x17 ,
V_309 ,
V_309 ) ;
if ( ! V_301 )
F_87 ( V_9 -> V_10 ) ;
if ( V_300 )
F_6 ( V_9 -> V_17 , V_252 -> V_136 + 0x11 ,
V_308 ,
V_308 ) ;
F_6 ( V_9 -> V_17 , V_252 -> V_136 + 1 ,
V_299 , V_299 ) ;
if ( V_301 )
F_6 ( V_9 -> V_17 , V_252 -> V_136 + 1 ,
V_303 , 0 ) ;
F_79 ( V_252 , L_60 ) ;
V_12 = 0 ;
for ( V_38 = 0 ; V_38 < 15 ; V_38 ++ ) {
if ( V_38 < 5 )
F_88 ( 200 , 400 ) ;
else
F_33 ( 20 ) ;
F_9 ( V_9 -> V_17 ,
V_310 ,
& V_12 ) ;
if ( V_12 & ( V_311 << ( V_252 -> V_172 - 1 ) ) )
break;
}
if ( V_38 == 15 )
F_80 ( V_252 , L_61 ) ;
else
F_79 ( V_252 , L_62 , V_38 ) ;
return 0 ;
}
static void F_89 ( struct V_251 * V_252 )
{
struct V_9 * V_9 = V_252 -> V_9 ;
bool V_312 ;
F_6 ( V_9 -> V_17 , V_252 -> V_136 + 1 ,
V_303 , V_303 ) ;
F_90 ( V_9 -> V_17 , V_252 -> V_136 + 1 ,
V_299 , 0 , & V_312 ) ;
F_12 ( V_9 -> V_17 , V_252 -> V_136 + 0x11 ,
V_308 , 0 ) ;
F_6 ( V_9 -> V_17 , V_252 -> V_136 + 1 ,
V_303 , 0 ) ;
if ( V_312 )
F_91 ( V_9 -> V_10 ) ;
}
int F_92 ( struct V_251 * V_252 , int V_112 ,
unsigned int V_253 , unsigned int V_254 )
{
int V_23 = 0 ;
if ( V_252 -> V_304 == V_112 && V_252 -> V_305 == V_253 )
return 0 ;
if ( V_252 -> V_256 && V_253 > 0 ) {
V_23 = F_75 ( V_252 , V_253 , V_252 -> V_256 ) ;
if ( V_23 != 0 )
return V_23 ;
}
V_252 -> V_304 = V_112 ;
V_252 -> V_305 = V_253 ;
if ( V_252 -> V_256 && V_253 > 0 ) {
V_23 = F_85 ( V_252 ) ;
}
return V_23 ;
}
int F_93 ( struct V_251 * V_252 , int V_112 ,
unsigned int V_253 , unsigned int V_254 )
{
int V_23 = 0 ;
if ( V_252 -> V_306 == V_112 &&
V_252 -> V_307 == V_253 && V_252 -> V_256 == V_254 )
return 0 ;
if ( V_254 ) {
if ( V_252 -> V_304 >= 0 ) {
V_23 = F_75 ( V_252 , V_252 -> V_305 , V_254 ) ;
if ( V_23 != 0 )
return V_23 ;
}
V_23 = F_75 ( V_252 , V_253 , V_254 ) ;
if ( V_23 != 0 )
return V_23 ;
}
V_252 -> V_306 = V_112 ;
V_252 -> V_307 = V_253 ;
V_252 -> V_256 = V_254 ;
if ( V_254 )
V_23 = F_85 ( V_252 ) ;
else
F_89 ( V_252 ) ;
return V_23 ;
}
int F_94 ( struct V_9 * V_9 , int V_172 , int V_136 , int V_313 ,
int V_314 , struct V_251 * V_252 )
{
unsigned int V_12 ;
V_252 -> V_172 = V_172 ;
V_252 -> V_136 = V_136 ;
V_252 -> V_9 = V_9 ;
V_252 -> V_306 = V_315 ;
F_9 ( V_9 -> V_17 , V_316 , & V_12 ) ;
switch ( V_12 & V_317 ) {
case V_318 :
case V_319 :
V_252 -> V_304 = V_12 & V_317 ;
break;
default:
V_252 -> V_304 = V_315 ;
}
V_252 -> V_305 = 32768 ;
snprintf ( V_252 -> V_320 , sizeof( V_252 -> V_320 ) , L_63 , V_172 ) ;
snprintf ( V_252 -> V_321 , sizeof( V_252 -> V_321 ) ,
L_64 , V_172 ) ;
F_12 ( V_9 -> V_17 , V_252 -> V_136 + 1 ,
V_303 , 0 ) ;
return 0 ;
}
int F_95 ( struct V_6 * V_7 , int V_322 , bool V_323 )
{
unsigned int V_57 , V_12 ;
if ( V_322 < 1 || V_322 > 6 )
return - V_82 ;
V_57 = V_324 + ( V_322 - 1 ) * 8 ;
if ( V_323 )
V_12 = V_325 ;
else
V_12 = 0 ;
return F_30 ( V_7 , V_57 , V_325 , V_12 ) ;
}
static bool F_96 ( bool V_135 , T_2 V_326 , T_2 V_327 )
{
T_3 V_328 = F_97 ( V_326 ) ;
T_3 V_329 = F_97 ( V_327 ) ;
if ( ! V_135 ) {
return abs ( V_328 ) >= 4096 ;
} else {
if ( abs ( V_329 ) >= 4096 )
return true ;
return ( abs ( ( V_328 << 16 ) / ( 4096 - V_329 ) ) >= 4096 << 4 ) ;
}
}
int F_98 ( struct V_3 * V_4 ,
struct V_330 * V_331 )
{
struct V_6 * V_7 = F_99 ( V_4 ) ;
struct V_9 * V_9 = F_3 ( V_7 -> V_10 -> V_11 ) ;
struct V_332 * V_190 = ( void * ) V_4 -> V_333 ;
unsigned int V_12 ;
T_2 * V_22 ;
int V_334 ;
int V_23 ;
V_334 = V_190 -> V_335 * F_100 ( V_9 -> V_17 ) ;
V_22 = F_101 ( V_331 -> V_336 . V_337 . V_22 , V_334 , V_338 | V_339 ) ;
if ( ! V_22 )
return - V_340 ;
V_22 [ 0 ] &= F_102 ( V_341 ) ;
if ( F_96 ( ! ! V_22 [ 0 ] , V_22 [ 1 ] , V_22 [ 2 ] ) ||
F_96 ( true , V_22 [ 4 ] , V_22 [ 5 ] ) ||
F_96 ( true , V_22 [ 8 ] , V_22 [ 9 ] ) ||
F_96 ( true , V_22 [ 12 ] , V_22 [ 13 ] ) ||
F_96 ( false , V_22 [ 16 ] , V_22 [ 17 ] ) ) {
F_10 ( V_9 -> V_10 , L_65 ) ;
V_23 = - V_82 ;
goto V_342;
}
V_23 = F_9 ( V_9 -> V_17 , V_190 -> V_136 , & V_12 ) ;
if ( V_23 != 0 )
goto V_342;
V_12 &= ~ V_341 ;
V_22 [ 0 ] |= F_102 ( V_12 ) ;
V_23 = F_103 ( V_9 -> V_17 , V_190 -> V_136 , V_22 , V_334 ) ;
V_342:
F_104 ( V_22 ) ;
return V_23 ;
}
int F_105 ( struct V_3 * V_4 ,
struct V_330 * V_331 )
{
struct V_6 * V_7 = F_99 ( V_4 ) ;
struct V_9 * V_9 = F_3 ( V_7 -> V_10 -> V_11 ) ;
T_2 * V_22 = ( T_2 * ) V_331 -> V_336 . V_337 . V_22 ;
T_3 V_12 = F_97 ( * V_22 ) ;
if ( abs ( V_12 ) >= 4096 ) {
F_10 ( V_9 -> V_10 , L_66 ) ;
return - V_82 ;
}
return F_106 ( V_4 , V_331 ) ;
}
int F_107 ( struct V_6 * V_7 ,
struct V_343 * V_344 ,
int (* F_108)( struct V_343 * V_344 ,
unsigned long V_345 , void * V_22 ) )
{
struct V_29 * V_30 = F_15 ( V_7 ) ;
struct V_9 * V_9 = V_30 -> V_9 ;
V_344 -> V_346 = F_108 ;
return F_109 ( & V_9 -> V_49 , V_344 ) ;
}
int F_110 ( struct V_6 * V_7 ,
struct V_343 * V_344 )
{
struct V_29 * V_30 = F_15 ( V_7 ) ;
struct V_9 * V_9 = V_30 -> V_9 ;
return F_111 ( & V_9 -> V_49 , V_344 ) ;
}
