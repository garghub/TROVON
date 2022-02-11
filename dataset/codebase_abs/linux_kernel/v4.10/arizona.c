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
return 0 ;
}
int F_17 ( struct V_9 * V_9 )
{
int V_23 ;
V_23 = F_18 ( V_9 , V_36 ,
L_6 , F_8 ,
V_9 ) ;
if ( V_23 != 0 )
F_10 ( V_9 -> V_10 ,
L_7 ,
V_23 ) ;
V_23 = F_18 ( V_9 , V_37 ,
L_8 , F_11 ,
V_9 ) ;
if ( V_23 != 0 )
F_10 ( V_9 -> V_10 ,
L_9 ,
V_23 ) ;
return 0 ;
}
int F_19 ( struct V_9 * V_9 )
{
F_20 ( V_9 , V_36 , V_9 ) ;
F_20 ( V_9 , V_37 , V_9 ) ;
return 0 ;
}
int F_21 ( struct V_6 * V_7 )
{
struct V_28 * V_8 = F_14 ( V_7 ) ;
struct V_29 * V_30 = F_15 ( V_7 ) ;
struct V_9 * V_9 = V_30 -> V_9 ;
int V_38 ;
for ( V_38 = 0 ; V_38 < V_39 ; ++ V_38 ) {
if ( V_9 -> V_40 . V_41 [ V_38 ] )
F_22 ( V_8 ,
& V_42 [ V_38 ] , 1 ) ;
}
return 0 ;
}
int F_23 ( struct V_6 * V_7 )
{
struct V_28 * V_8 = F_14 ( V_7 ) ;
struct V_43 * V_44 = F_24 ( V_8 ) ;
struct V_29 * V_30 = F_15 ( V_7 ) ;
struct V_9 * V_9 = V_30 -> V_9 ;
int V_38 ;
switch ( V_9 -> type ) {
case V_45 :
case V_46 :
F_25 ( V_44 ,
L_10 ) ;
break;
default:
break;
}
F_25 ( V_44 , L_11 ) ;
for ( V_38 = 0 ; V_38 < F_26 ( V_9 -> V_40 . V_47 ) ; V_38 ++ ) {
switch ( V_9 -> V_40 . V_47 [ V_38 ] & V_48 ) {
case V_49 :
F_27 ( V_44 ,
L_11 ) ;
break;
case V_50 :
F_27 ( V_44 ,
L_10 ) ;
break;
default:
break;
}
}
return 0 ;
}
int F_28 ( struct V_6 * V_7 )
{
struct V_29 * V_30 = F_15 ( V_7 ) ;
struct V_9 * V_9 = V_30 -> V_9 ;
F_29 ( & V_9 -> V_51 ) ;
return 0 ;
}
const char * F_30 ( unsigned int V_52 )
{
int V_38 ;
for ( V_38 = 0 ; V_38 < F_26 ( V_53 ) ; ++ V_38 ) {
if ( V_53 [ V_38 ] == V_52 )
return V_54 [ V_38 ] ;
}
return L_12 ;
}
static void F_31 ( struct V_6 * V_7 , int V_55 )
{
struct V_29 * V_30 = F_15 ( V_7 ) ;
unsigned int V_12 ;
int V_38 ;
if ( V_55 )
V_12 = V_56 ;
else
V_12 = 0 ;
for ( V_38 = 0 ; V_38 < V_30 -> V_57 ; V_38 ++ )
F_32 ( V_7 ,
V_58 + ( V_38 * 4 ) ,
V_56 , V_12 ) ;
}
bool F_33 ( struct V_6 * V_7 , int V_19 )
{
unsigned int V_59 = V_60 + ( ( V_19 / 2 ) * 8 ) ;
unsigned int V_12 = F_4 ( V_7 , V_59 ) ;
return ! ( V_12 & V_61 ) ;
}
int F_34 ( struct V_1 * V_2 , struct V_3 * V_4 ,
int V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 -> V_8 ) ;
struct V_29 * V_30 = F_15 ( V_7 ) ;
unsigned int V_59 ;
if ( V_2 -> V_19 % 2 )
V_59 = V_58 + ( ( V_2 -> V_19 / 2 ) * 8 ) ;
else
V_59 = V_62 + ( ( V_2 -> V_19 / 2 ) * 8 ) ;
switch ( V_5 ) {
case V_63 :
V_30 -> V_64 ++ ;
break;
case V_13 :
F_32 ( V_7 , V_59 , V_65 , 0 ) ;
V_30 -> V_64 -- ;
if ( V_30 -> V_64 == 0 ) {
F_35 ( 1 ) ;
F_31 ( V_7 , 1 ) ;
}
break;
case V_20 :
F_32 ( V_7 , V_59 ,
V_65 | V_56 ,
V_65 | V_56 ) ;
break;
case V_66 :
V_59 = F_4 ( V_7 , V_67 ) ;
if ( V_59 == 0 )
F_31 ( V_7 , 0 ) ;
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
case V_63 :
switch ( V_2 -> V_19 ) {
case V_68 :
case V_69 :
case V_70 :
case V_71 :
case V_72 :
case V_73 :
V_30 -> V_74 ++ ;
V_30 -> V_75 += 17 ;
break;
case V_76 :
case V_77 :
V_30 -> V_74 ++ ;
switch ( V_9 -> type ) {
case V_78 :
case V_32 :
break;
default:
V_30 -> V_75 += 10 ;
break;
}
break;
default:
break;
}
break;
case V_13 :
switch ( V_2 -> V_19 ) {
case V_68 :
case V_69 :
case V_70 :
case V_71 :
case V_72 :
case V_73 :
case V_76 :
case V_77 :
V_30 -> V_74 -- ;
if ( ! V_30 -> V_74 && V_30 -> V_75 ) {
F_36 ( V_7 -> V_10 , L_13 ,
V_30 -> V_75 ) ;
F_35 ( V_30 -> V_75 ) ;
V_30 -> V_75 = 0 ;
}
break;
default:
break;
}
break;
case V_20 :
switch ( V_2 -> V_19 ) {
case V_68 :
case V_69 :
case V_70 :
case V_71 :
case V_72 :
case V_73 :
V_30 -> V_79 ++ ;
V_30 -> V_80 ++ ;
break;
case V_76 :
case V_77 :
V_30 -> V_79 ++ ;
switch ( V_9 -> type ) {
case V_78 :
case V_32 :
break;
case V_81 :
case V_82 :
V_30 -> V_80 += 5 ;
break;
default:
V_30 -> V_80 ++ ;
break;
}
default:
break;
}
break;
case V_66 :
switch ( V_2 -> V_19 ) {
case V_68 :
case V_69 :
case V_70 :
case V_71 :
case V_72 :
case V_73 :
case V_76 :
case V_77 :
V_30 -> V_79 -- ;
if ( ! V_30 -> V_79 && V_30 -> V_80 ) {
F_36 ( V_7 -> V_10 , L_14 ,
V_30 -> V_80 ) ;
F_35 ( V_30 -> V_80 ) ;
V_30 -> V_80 = 0 ;
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
int F_37 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
int V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 -> V_8 ) ;
struct V_29 * V_30 = F_15 ( V_7 ) ;
struct V_9 * V_9 = V_30 -> V_9 ;
unsigned int V_83 = 1 << V_2 -> V_19 ;
unsigned int V_12 ;
switch ( V_5 ) {
case V_13 :
V_12 = V_83 ;
break;
case V_20 :
V_12 = 0 ;
break;
case V_63 :
case V_66 :
return F_7 ( V_2 , V_4 , V_5 ) ;
default:
return - V_84 ;
}
V_30 -> V_9 -> V_85 &= ~ V_83 ;
V_30 -> V_9 -> V_85 |= V_12 ;
if ( V_30 -> V_9 -> V_86 )
V_12 = 0 ;
F_6 ( V_9 -> V_17 , V_18 ,
V_83 , V_12 ) ;
return F_7 ( V_2 , V_4 , V_5 ) ;
}
static int F_38 ( struct V_6 * V_7 )
{
const struct V_29 * V_30 = F_15 ( V_7 ) ;
struct V_9 * V_9 = V_30 -> V_9 ;
int V_23 ;
V_23 = F_39 ( V_9 -> V_87 , 1800000 , 1800000 ) ;
if ( V_23 ) {
F_10 ( V_7 -> V_10 , L_15 , V_23 ) ;
return V_23 ;
}
V_23 = F_12 ( V_9 -> V_17 ,
V_88 ,
V_89 ,
V_89 ) ;
if ( V_23 ) {
F_10 ( V_7 -> V_10 , L_16 , V_23 ) ;
F_39 ( V_9 -> V_87 , 1200000 , 1800000 ) ;
return V_23 ;
}
return 0 ;
}
static int F_40 ( struct V_6 * V_7 )
{
const struct V_29 * V_30 = F_15 ( V_7 ) ;
struct V_9 * V_9 = V_30 -> V_9 ;
int V_23 ;
V_23 = F_12 ( V_9 -> V_17 ,
V_88 ,
V_89 , 0 ) ;
if ( V_23 ) {
F_10 ( V_7 -> V_10 , L_17 , V_23 ) ;
return V_23 ;
}
V_23 = F_39 ( V_9 -> V_87 , 1200000 , 1800000 ) ;
if ( V_23 ) {
F_10 ( V_7 -> V_10 , L_18 , V_23 ) ;
return V_23 ;
}
return 0 ;
}
int F_41 ( struct V_6 * V_7 , unsigned int V_90 )
{
struct V_29 * V_30 = F_15 ( V_7 ) ;
int V_23 = 0 ;
F_42 ( & V_30 -> V_91 ) ;
if ( ! V_30 -> V_92 && ! V_30 -> V_93 ) {
V_23 = F_38 ( V_7 ) ;
if ( V_23 )
goto V_94;
}
V_30 -> V_93 |= V_90 ;
V_94:
F_43 ( & V_30 -> V_91 ) ;
return V_23 ;
}
int F_44 ( struct V_6 * V_7 , unsigned int V_90 )
{
struct V_29 * V_30 = F_15 ( V_7 ) ;
unsigned int V_95 ;
int V_23 = 0 ;
F_42 ( & V_30 -> V_91 ) ;
V_95 = V_30 -> V_93 ;
V_30 -> V_93 &= ~ V_90 ;
if ( ! V_30 -> V_92 && V_95 && ! V_30 -> V_93 )
V_23 = F_40 ( V_7 ) ;
F_43 ( & V_30 -> V_91 ) ;
return V_23 ;
}
int F_45 ( struct V_1 * V_2 ,
struct V_3 * V_4 , int V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 -> V_8 ) ;
struct V_29 * V_30 = F_15 ( V_7 ) ;
int V_23 = 0 ;
F_42 ( & V_30 -> V_91 ) ;
switch ( V_5 ) {
case V_13 :
if ( V_30 -> V_93 )
V_23 = F_38 ( V_7 ) ;
V_30 -> V_92 = false ;
break;
case V_20 :
V_30 -> V_92 = true ;
if ( V_30 -> V_93 )
V_23 = F_40 ( V_7 ) ;
break;
default:
break;
}
F_43 ( & V_30 -> V_91 ) ;
return V_23 ;
}
void F_46 ( struct V_29 * V_30 )
{
F_47 ( & V_30 -> V_91 ) ;
}
int F_48 ( struct V_1 * V_2 ,
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
F_49 ( V_7 , V_96 , V_12 ) ;
return 0 ;
}
static int F_50 ( struct V_6 * V_7 , unsigned int V_97 ,
unsigned int V_98 )
{
struct V_29 * V_30 = F_15 ( V_7 ) ;
unsigned int V_59 ;
unsigned int * V_99 ;
int V_100 , div , V_101 ;
switch ( V_97 ) {
case V_102 :
V_59 = V_103 ;
V_101 = V_30 -> V_104 ;
break;
case V_105 :
V_59 = V_106 ;
V_101 = V_30 -> V_107 ;
break;
default:
return - V_84 ;
}
if ( V_101 % 8000 )
V_99 = V_108 ;
else
V_99 = V_109 ;
for ( V_100 = 0 ; V_100 < F_26 ( V_109 ) &&
V_99 [ V_100 ] <= V_101 ; V_100 ++ ) {
div = 1 ;
while ( V_99 [ V_100 ] / div >= V_98 && div < 32 ) {
if ( V_99 [ V_100 ] / div == V_98 ) {
F_36 ( V_7 -> V_10 , L_19 ,
V_98 ) ;
F_32 ( V_7 , V_59 ,
V_110 |
V_111 ,
( div <<
V_112 ) |
V_100 ) ;
return 0 ;
}
div ++ ;
}
}
F_10 ( V_7 -> V_10 , L_20 , V_98 ) ;
return - V_84 ;
}
int F_51 ( struct V_1 * V_2 ,
struct V_3 * V_4 , int V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 -> V_8 ) ;
struct V_9 * V_9 = F_3 ( V_7 -> V_10 -> V_11 ) ;
unsigned int V_12 ;
int V_113 ;
int V_23 ;
V_23 = F_9 ( V_9 -> V_17 , V_2 -> V_59 , & V_12 ) ;
if ( V_23 ) {
F_10 ( V_7 -> V_10 , L_21 , V_23 ) ;
return V_23 ;
}
V_12 = ( V_12 & V_114 ) >> V_115 ;
switch ( V_12 ) {
case V_116 :
V_113 = V_117 ;
break;
case V_118 :
V_113 = V_119 ;
break;
default:
return 0 ;
}
switch ( V_5 ) {
case V_63 :
return F_52 ( V_9 -> V_120 [ V_113 ] ) ;
case V_66 :
F_53 ( V_9 -> V_120 [ V_113 ] ) ;
return 0 ;
default:
return 0 ;
}
}
int F_54 ( struct V_6 * V_7 , int V_121 ,
int V_122 , unsigned int V_98 , int V_123 )
{
struct V_29 * V_30 = F_15 ( V_7 ) ;
struct V_9 * V_9 = V_30 -> V_9 ;
char * V_124 ;
unsigned int V_59 ;
unsigned int V_83 = V_125 | V_114 ;
unsigned int V_12 = V_122 << V_115 ;
int * V_97 ;
switch ( V_121 ) {
case V_126 :
V_124 = L_22 ;
V_59 = V_127 ;
V_97 = & V_30 -> V_104 ;
V_83 |= V_128 ;
break;
case V_129 :
V_124 = L_23 ;
V_59 = V_130 ;
V_97 = & V_30 -> V_107 ;
break;
case V_102 :
case V_105 :
return F_50 ( V_7 , V_121 , V_98 ) ;
default:
return - V_84 ;
}
switch ( V_98 ) {
case 5644800 :
case 6144000 :
break;
case 11289600 :
case 12288000 :
V_12 |= V_131 << V_132 ;
break;
case 22579200 :
case 24576000 :
V_12 |= V_133 << V_132 ;
break;
case 45158400 :
case 49152000 :
V_12 |= V_134 << V_132 ;
break;
case 67737600 :
case 73728000 :
V_12 |= V_135 << V_132 ;
break;
case 90316800 :
case 98304000 :
V_12 |= V_136 << V_132 ;
break;
case 135475200 :
case 147456000 :
V_12 |= V_137 << V_132 ;
break;
case 0 :
F_36 ( V_9 -> V_10 , L_24 , V_124 ) ;
* V_97 = V_98 ;
return 0 ;
default:
return - V_84 ;
}
* V_97 = V_98 ;
if ( V_98 % 6144000 )
V_12 |= V_128 ;
F_36 ( V_9 -> V_10 , L_25 , V_124 , V_98 ) ;
return F_12 ( V_9 -> V_17 , V_59 , V_83 , V_12 ) ;
}
static int F_55 ( struct V_138 * V_139 , unsigned int V_140 )
{
struct V_6 * V_7 = V_139 -> V_7 ;
struct V_29 * V_30 = F_15 ( V_7 ) ;
struct V_9 * V_9 = V_30 -> V_9 ;
int V_141 , V_142 , V_143 , V_144 ;
V_144 = V_139 -> V_145 -> V_144 ;
V_141 = 0 ;
V_142 = 0 ;
switch ( V_140 & V_146 ) {
case V_147 :
V_143 = V_148 ;
break;
case V_149 :
if ( ( V_140 & V_150 )
!= V_151 ) {
F_56 ( V_139 , L_26 ) ;
return - V_84 ;
}
V_143 = V_152 ;
break;
case V_153 :
V_143 = V_154 ;
break;
case V_155 :
if ( ( V_140 & V_150 )
!= V_151 ) {
F_56 ( V_139 , L_27 ) ;
return - V_84 ;
}
V_143 = V_156 ;
break;
default:
F_56 ( V_139 , L_28 ,
V_140 & V_146 ) ;
return - V_84 ;
}
switch ( V_140 & V_150 ) {
case V_157 :
break;
case V_158 :
V_141 |= V_159 ;
break;
case V_160 :
V_142 |= V_161 ;
break;
case V_151 :
V_142 |= V_161 ;
V_141 |= V_159 ;
break;
default:
F_56 ( V_139 , L_29 ,
V_140 & V_150 ) ;
return - V_84 ;
}
switch ( V_140 & V_162 ) {
case V_163 :
break;
case V_164 :
V_142 |= V_165 ;
V_141 |= V_166 ;
break;
case V_167 :
V_142 |= V_165 ;
break;
case V_168 :
V_141 |= V_166 ;
break;
default:
return - V_84 ;
}
F_6 ( V_9 -> V_17 , V_144 + V_169 ,
V_165 |
V_161 ,
V_142 ) ;
F_6 ( V_9 -> V_17 , V_144 + V_170 ,
V_166 |
V_159 , V_141 ) ;
F_6 ( V_9 -> V_17 ,
V_144 + V_171 ,
V_172 |
V_173 , V_141 ) ;
F_12 ( V_9 -> V_17 , V_144 + V_174 ,
V_175 , V_143 ) ;
return 0 ;
}
static int F_57 ( struct V_176 * V_177 ,
struct V_138 * V_139 )
{
struct V_6 * V_7 = V_139 -> V_7 ;
struct V_29 * V_30 = F_15 ( V_7 ) ;
struct V_178 * V_179 = & V_30 -> V_139 [ V_139 -> V_180 - 1 ] ;
unsigned int V_181 ;
if ( ! V_177 -> V_182 )
return 0 ;
switch ( V_179 -> V_97 ) {
case V_126 :
V_181 = V_30 -> V_104 ;
break;
case V_129 :
V_181 = V_30 -> V_107 ;
break;
default:
return 0 ;
}
if ( V_181 == 0 )
V_179 -> V_183 . V_83 = V_184 ;
else if ( V_181 % 8000 )
V_179 -> V_183 . V_83 = V_185 ;
else
V_179 -> V_183 . V_83 = V_186 ;
return F_58 ( V_177 -> V_182 , 0 ,
V_187 ,
& V_179 -> V_183 ) ;
}
static void F_59 ( struct V_6 * V_7 ,
unsigned int V_188 )
{
struct V_29 * V_30 = F_15 ( V_7 ) ;
struct V_9 * V_9 = V_30 -> V_9 ;
struct V_189 V_190 [] = {
{ 0x80 , 0x3 } ,
{ V_191 , 0 } ,
{ V_192 , 0 } ,
{ 0x80 , 0x0 } ,
} ;
F_42 ( & V_9 -> V_193 ) ;
V_190 [ 1 ] . V_194 = V_9 -> V_195 ;
if ( V_188 >= 176400 )
V_190 [ 2 ] . V_194 = V_9 -> V_196 ;
F_43 ( & V_9 -> V_193 ) ;
F_60 ( V_9 -> V_17 ,
V_190 ,
F_26 ( V_190 ) ) ;
}
static int F_61 ( struct V_176 * V_177 ,
struct V_197 * V_198 ,
struct V_138 * V_139 )
{
struct V_6 * V_7 = V_139 -> V_7 ;
struct V_29 * V_30 = F_15 ( V_7 ) ;
struct V_178 * V_179 = & V_30 -> V_139 [ V_139 -> V_180 - 1 ] ;
int V_144 = V_139 -> V_145 -> V_144 ;
int V_38 , V_199 , V_23 ;
for ( V_38 = 0 ; V_38 < F_26 ( V_200 ) ; V_38 ++ )
if ( V_200 [ V_38 ] == F_62 ( V_198 ) )
break;
if ( V_38 == F_26 ( V_200 ) ) {
F_56 ( V_139 , L_30 ,
F_62 ( V_198 ) ) ;
return - V_84 ;
}
V_199 = V_38 ;
switch ( V_30 -> V_9 -> type ) {
case V_78 :
case V_32 :
if ( V_200 [ V_199 ] >= 88200 )
V_23 = F_41 ( V_7 , V_201 ) ;
else
V_23 = F_44 ( V_7 , V_201 ) ;
if ( V_23 ) {
F_56 ( V_139 , L_31 , V_23 ) ;
return V_23 ;
}
break;
default:
break;
}
switch ( V_179 -> V_97 ) {
case V_126 :
switch ( V_30 -> V_9 -> type ) {
case V_78 :
F_59 ( V_7 ,
F_62 ( V_198 ) ) ;
break;
default:
break;
}
F_32 ( V_7 , V_202 ,
V_203 , V_199 ) ;
if ( V_144 )
F_32 ( V_7 , V_144 + V_204 ,
V_205 , 0 ) ;
break;
case V_129 :
F_32 ( V_7 , V_206 ,
V_207 , V_199 ) ;
if ( V_144 )
F_32 ( V_7 , V_144 + V_204 ,
V_205 ,
8 << V_208 ) ;
break;
default:
F_56 ( V_139 , L_32 , V_179 -> V_97 ) ;
return - V_84 ;
}
return 0 ;
}
static bool F_63 ( struct V_6 * V_7 ,
int V_144 , int V_142 , int V_141 , int V_209 )
{
int V_12 ;
V_12 = F_4 ( V_7 , V_144 + V_169 ) ;
if ( V_142 != ( V_12 & V_210 ) )
return true ;
V_12 = F_4 ( V_7 , V_144 + V_211 ) ;
if ( V_141 != ( V_12 & V_212 ) )
return true ;
V_12 = F_4 ( V_7 , V_144 + V_213 ) ;
if ( V_209 != ( V_12 & ( V_214 |
V_215 ) ) )
return true ;
return false ;
}
static int F_64 ( struct V_176 * V_177 ,
struct V_197 * V_198 ,
struct V_138 * V_139 )
{
struct V_6 * V_7 = V_139 -> V_7 ;
struct V_29 * V_30 = F_15 ( V_7 ) ;
struct V_9 * V_9 = V_30 -> V_9 ;
int V_144 = V_139 -> V_145 -> V_144 ;
const int * V_99 ;
int V_38 , V_23 , V_12 ;
int V_216 = F_65 ( V_198 ) ;
int V_217 = V_9 -> V_40 . V_218 [ V_139 -> V_180 - 1 ] ;
int V_219 = V_9 -> V_219 [ V_139 -> V_180 - 1 ] ;
int V_220 = V_9 -> V_220 [ V_139 -> V_180 - 1 ] ;
int V_142 , V_141 , V_221 , V_209 , V_222 ;
bool V_223 ;
unsigned int V_224 , V_225 ;
if ( F_62 ( V_198 ) % 4000 )
V_99 = & V_226 [ 0 ] ;
else
V_99 = & V_227 [ 0 ] ;
V_221 = F_66 ( V_198 ) ;
if ( V_220 ) {
F_67 ( V_139 , L_33 ,
V_220 , V_219 ) ;
V_222 = V_220 * V_219 * F_62 ( V_198 ) ;
V_216 = V_220 ;
} else {
V_222 = F_68 ( V_198 ) ;
V_219 = V_221 ;
}
if ( V_217 && V_217 < V_216 ) {
F_67 ( V_139 , L_34 , V_217 ) ;
V_222 /= V_216 ;
V_222 *= V_217 ;
}
V_12 = F_4 ( V_7 , V_144 + V_174 ) ;
V_12 &= V_175 ;
if ( ( V_216 & 1 ) && ( V_12 == V_154 ) ) {
F_67 ( V_139 , L_35 ) ;
V_222 /= V_216 ;
V_222 *= V_216 + 1 ;
}
for ( V_38 = 0 ; V_38 < F_26 ( V_226 ) ; V_38 ++ ) {
if ( V_99 [ V_38 ] >= V_222 &&
V_99 [ V_38 ] % F_62 ( V_198 ) == 0 ) {
V_142 = V_38 ;
break;
}
}
if ( V_38 == F_26 ( V_226 ) ) {
F_56 ( V_139 , L_30 ,
F_62 ( V_198 ) ) ;
return - V_84 ;
}
V_141 = V_99 [ V_142 ] / F_62 ( V_198 ) ;
F_67 ( V_139 , L_36 ,
V_99 [ V_142 ] , V_99 [ V_142 ] / V_141 ) ;
V_209 = V_221 << V_228 | V_219 ;
V_223 = F_63 ( V_7 , V_144 , V_142 , V_141 , V_209 ) ;
if ( V_223 ) {
V_224 = F_4 ( V_7 ,
V_144 + V_229 ) ;
V_225 = F_4 ( V_7 ,
V_144 + V_230 ) ;
F_6 ( V_9 -> V_17 ,
V_144 + V_229 , 0xff , 0x0 ) ;
F_12 ( V_9 -> V_17 ,
V_144 + V_230 , 0xff , 0x0 ) ;
}
V_23 = F_61 ( V_177 , V_198 , V_139 ) ;
if ( V_23 != 0 )
goto V_231;
if ( V_223 ) {
F_6 ( V_9 -> V_17 ,
V_144 + V_169 ,
V_210 , V_142 ) ;
F_6 ( V_9 -> V_17 ,
V_144 + V_211 ,
V_212 , V_141 ) ;
F_6 ( V_9 -> V_17 ,
V_144 + V_232 ,
V_233 , V_141 ) ;
F_6 ( V_9 -> V_17 ,
V_144 + V_213 ,
V_214 |
V_215 , V_209 ) ;
F_12 ( V_9 -> V_17 ,
V_144 + V_234 ,
V_235 |
V_236 , V_209 ) ;
}
V_231:
if ( V_223 ) {
F_6 ( V_9 -> V_17 ,
V_144 + V_229 ,
0xff , V_224 ) ;
F_12 ( V_9 -> V_17 ,
V_144 + V_230 ,
0xff , V_225 ) ;
}
return V_23 ;
}
static const char * F_69 ( int V_121 )
{
switch ( V_121 ) {
case V_126 :
return L_22 ;
case V_129 :
return L_23 ;
default:
return L_37 ;
}
}
static int F_70 ( struct V_138 * V_139 ,
int V_121 , unsigned int V_98 , int V_123 )
{
struct V_6 * V_7 = V_139 -> V_7 ;
struct V_28 * V_8 = F_14 ( V_7 ) ;
struct V_29 * V_30 = F_15 ( V_7 ) ;
struct V_178 * V_179 = & V_30 -> V_139 [ V_139 -> V_180 - 1 ] ;
struct V_237 V_238 [ 2 ] ;
switch ( V_121 ) {
case V_126 :
case V_129 :
break;
default:
return - V_84 ;
}
if ( V_121 == V_179 -> V_97 )
return 0 ;
if ( V_139 -> V_239 ) {
F_10 ( V_7 -> V_10 , L_38 ,
V_139 -> V_180 ) ;
return - V_16 ;
}
F_36 ( V_7 -> V_10 , L_39 , V_139 -> V_180 + 1 ,
F_69 ( V_121 ) ) ;
memset ( & V_238 , 0 , sizeof( V_238 ) ) ;
V_238 [ 0 ] . V_240 = V_139 -> V_145 -> V_241 . V_242 ;
V_238 [ 1 ] . V_240 = V_139 -> V_145 -> V_243 . V_242 ;
V_238 [ 0 ] . V_122 = F_69 ( V_179 -> V_97 ) ;
V_238 [ 1 ] . V_122 = F_69 ( V_179 -> V_97 ) ;
F_71 ( V_8 , V_238 , F_26 ( V_238 ) ) ;
V_238 [ 0 ] . V_122 = F_69 ( V_121 ) ;
V_238 [ 1 ] . V_122 = F_69 ( V_121 ) ;
F_22 ( V_8 , V_238 , F_26 ( V_238 ) ) ;
V_179 -> V_97 = V_121 ;
return F_72 ( V_8 ) ;
}
static int F_73 ( struct V_138 * V_139 , int V_244 )
{
struct V_6 * V_7 = V_139 -> V_7 ;
int V_144 = V_139 -> V_145 -> V_144 ;
unsigned int V_59 ;
if ( V_244 )
V_59 = V_245 ;
else
V_59 = 0 ;
return F_32 ( V_7 , V_144 + V_204 ,
V_245 , V_59 ) ;
}
static void F_74 ( struct V_138 * V_139 ,
unsigned int V_144 ,
int V_216 , unsigned int V_83 )
{
struct V_6 * V_7 = V_139 -> V_7 ;
struct V_29 * V_30 = F_15 ( V_7 ) ;
struct V_9 * V_9 = V_30 -> V_9 ;
int V_246 , V_38 ;
for ( V_38 = 0 ; V_38 < V_216 ; ++ V_38 ) {
V_246 = F_75 ( V_83 ) - 1 ;
if ( V_246 < 0 )
return;
F_76 ( V_9 -> V_17 , V_144 + V_38 , V_246 ) ;
V_83 &= ~ ( 1 << V_246 ) ;
}
if ( V_83 )
F_77 ( V_139 , L_40 ) ;
}
static int F_78 ( struct V_138 * V_139 , unsigned int V_247 ,
unsigned int V_248 , int V_249 , int V_250 )
{
struct V_6 * V_7 = V_139 -> V_7 ;
struct V_29 * V_30 = F_15 ( V_7 ) ;
struct V_9 * V_9 = V_30 -> V_9 ;
int V_144 = V_139 -> V_145 -> V_144 ;
int V_251 = V_139 -> V_145 -> V_243 . V_252 ;
int V_253 = V_139 -> V_145 -> V_241 . V_252 ;
if ( V_139 -> V_180 > V_254 )
return - V_255 ;
if ( V_249 == 0 ) {
V_247 = ( 1 << V_253 ) - 1 ;
V_248 = ( 1 << V_251 ) - 1 ;
}
F_74 ( V_139 , V_144 + V_256 ,
V_253 , V_247 ) ;
F_74 ( V_139 , V_144 + V_257 ,
V_251 , V_248 ) ;
V_9 -> V_219 [ V_139 -> V_180 - 1 ] = V_250 ;
V_9 -> V_220 [ V_139 -> V_180 - 1 ] = V_249 ;
return 0 ;
}
int F_79 ( struct V_29 * V_30 , int V_180 )
{
struct V_178 * V_179 = & V_30 -> V_139 [ V_180 ] ;
V_179 -> V_97 = V_126 ;
V_179 -> V_183 = V_258 ;
return 0 ;
}
static int F_80 ( struct V_259 * V_260 ,
unsigned int V_261 ,
unsigned int V_262 )
{
unsigned int V_263 ;
if ( V_260 -> V_264 && V_262 != V_260 -> V_264 ) {
F_81 ( V_260 ,
L_41 ) ;
return - V_84 ;
}
if ( V_261 / V_265 > V_266 ) {
F_81 ( V_260 ,
L_42 ,
V_261 ) ;
return - V_84 ;
}
V_263 = V_267 * V_260 -> V_268 ;
if ( V_262 * V_269 < V_263 ) {
F_81 ( V_260 , L_43 ,
V_262 ) ;
return - V_84 ;
}
return 0 ;
}
static int F_82 ( unsigned int V_261 , int * V_270 )
{
int V_38 ;
for ( V_38 = 0 ; V_38 < F_26 ( V_271 ) ; V_38 ++ ) {
if ( V_271 [ V_38 ] . V_272 <= V_261 && V_261 <= V_271 [ V_38 ] . V_273 ) {
if ( V_270 )
* V_270 = V_271 [ V_38 ] . V_270 ;
return V_271 [ V_38 ] . V_274 ;
}
}
return - V_84 ;
}
static int F_83 ( struct V_259 * V_260 ,
struct V_275 * V_276 ,
unsigned int V_277 ,
unsigned int V_261 , bool V_278 )
{
int V_279 , V_274 ;
int V_280 , div ;
div = 1 ;
V_276 -> V_280 = 0 ;
while ( V_261 > V_266 ) {
div *= 2 ;
V_261 /= 2 ;
V_276 -> V_280 ++ ;
if ( div > V_265 )
return - V_84 ;
}
V_279 = F_82 ( V_261 , & V_276 -> V_270 ) ;
if ( V_279 < 0 ) {
F_81 ( V_260 , L_44 ,
V_261 ) ;
return V_279 ;
}
switch ( V_260 -> V_9 -> type ) {
case V_78 :
case V_32 :
return V_279 ;
case V_45 :
case V_46 :
if ( V_260 -> V_9 -> V_281 < 3 || V_278 )
return V_279 ;
break;
default:
if ( V_278 )
return V_279 ;
break;
}
V_276 -> V_270 = V_279 - 1 ;
V_280 = V_276 -> V_280 ;
F_84 ( V_260 , L_45 ,
V_279 , V_261 , V_280 ) ;
while ( div <= V_265 ) {
for ( V_274 = V_279 ; V_274 > 0 ; V_274 -- ) {
if ( V_277 % ( V_274 * V_261 ) ) {
V_276 -> V_280 = V_280 ;
V_276 -> V_270 = V_274 - 1 ;
F_84 ( V_260 ,
L_46 ,
V_261 , V_280 , div , V_274 ) ;
return V_274 ;
}
}
for ( V_274 = V_279 + 1 ; V_274 <= V_282 ;
V_274 ++ ) {
if ( ( V_283 / 2 ) /
( V_260 -> V_268 * V_274 ) < V_261 ) {
F_84 ( V_260 , L_47 ) ;
break;
}
if ( V_261 > V_284 [ V_274 - 1 ] ) {
F_84 ( V_260 ,
L_48 ,
V_284 [ V_274 - 1 ] ,
V_274 ) ;
break;
}
if ( V_277 % ( V_274 * V_261 ) ) {
V_276 -> V_280 = V_280 ;
V_276 -> V_270 = V_274 - 1 ;
F_84 ( V_260 ,
L_46 ,
V_261 , V_280 , div , V_274 ) ;
return V_274 ;
}
}
div *= 2 ;
V_261 /= 2 ;
V_280 ++ ;
V_279 = F_82 ( V_261 , NULL ) ;
F_84 ( V_260 ,
L_49 ,
V_261 , V_280 , div , V_279 ) ;
}
F_85 ( V_260 , L_50 ) ;
return V_276 -> V_270 + 1 ;
}
static int F_86 ( struct V_259 * V_260 ,
struct V_275 * V_276 ,
unsigned int V_261 , bool V_278 )
{
unsigned int V_277 , div , V_285 ;
int V_38 , V_274 ;
F_84 ( V_260 , L_51 , V_261 , V_260 -> V_264 ) ;
div = V_286 ;
while ( V_260 -> V_264 * div < V_267 * V_260 -> V_268 ) {
div ++ ;
if ( div > V_269 )
return - V_84 ;
}
V_277 = V_260 -> V_264 * div / V_260 -> V_268 ;
V_276 -> V_287 = div ;
F_84 ( V_260 , L_52 , V_277 ) ;
V_274 = F_83 ( V_260 , V_276 , V_277 , V_261 , V_278 ) ;
if ( V_274 < 0 )
return V_274 ;
V_261 = V_261 / ( 1 << V_276 -> V_280 ) ;
V_276 -> V_288 = V_277 / ( V_274 * V_261 ) ;
if ( V_277 % ( V_274 * V_261 ) ) {
V_285 = F_87 ( V_277 , V_274 * V_261 ) ;
F_84 ( V_260 , L_53 , V_285 ) ;
V_276 -> V_289 = ( V_277 - ( V_276 -> V_288 * V_274 * V_261 ) )
/ V_285 ;
V_276 -> V_290 = ( V_274 * V_261 ) / V_285 ;
} else {
V_276 -> V_289 = 0 ;
V_276 -> V_290 = 0 ;
}
while ( V_276 -> V_290 >= ( 1 << 16 ) ) {
V_276 -> V_289 >>= 1 ;
V_276 -> V_290 >>= 1 ;
}
for ( V_38 = 0 ; V_38 < F_26 ( V_291 ) ; V_38 ++ ) {
if ( V_291 [ V_38 ] . V_272 <= V_261 && V_261 <= V_291 [ V_38 ] . V_273 ) {
V_276 -> V_292 = V_291 [ V_38 ] . V_292 ;
break;
}
}
if ( V_38 == F_26 ( V_291 ) ) {
F_81 ( V_260 , L_54 ,
V_261 ) ;
return - V_84 ;
}
F_84 ( V_260 , L_55 ,
V_276 -> V_288 , V_276 -> V_289 , V_276 -> V_290 ) ;
F_84 ( V_260 , L_56 ,
V_276 -> V_270 , V_274 , V_276 -> V_287 ,
V_276 -> V_280 , 1 << V_276 -> V_280 ) ;
F_84 ( V_260 , L_57 , V_276 -> V_292 , 1 << V_276 -> V_292 ) ;
return 0 ;
}
static void F_88 ( struct V_9 * V_9 , unsigned int V_144 ,
struct V_275 * V_276 , int V_122 ,
bool V_278 )
{
F_6 ( V_9 -> V_17 , V_144 + 3 ,
V_293 , V_276 -> V_289 ) ;
F_6 ( V_9 -> V_17 , V_144 + 4 ,
V_294 , V_276 -> V_290 ) ;
F_6 ( V_9 -> V_17 , V_144 + 5 ,
V_295 ,
V_276 -> V_270 << V_296 ) ;
F_6 ( V_9 -> V_17 , V_144 + 6 ,
V_297 |
V_298 ,
V_276 -> V_280 << V_299 |
V_122 << V_300 ) ;
if ( V_278 ) {
F_12 ( V_9 -> V_17 , V_144 + 0x7 ,
V_301 ,
V_276 -> V_292 << V_302 ) ;
} else {
F_12 ( V_9 -> V_17 , V_144 + 0x5 ,
V_303 ,
V_276 -> V_287 << V_304 ) ;
F_12 ( V_9 -> V_17 , V_144 + 0x9 ,
V_301 ,
V_276 -> V_292 << V_302 ) ;
}
F_6 ( V_9 -> V_17 , V_144 + 2 ,
V_305 | V_306 ,
V_305 | V_276 -> V_288 ) ;
}
static int F_89 ( struct V_259 * V_260 , int V_144 )
{
struct V_9 * V_9 = V_260 -> V_9 ;
unsigned int V_59 ;
int V_23 ;
V_23 = F_9 ( V_9 -> V_17 , V_144 + 1 , & V_59 ) ;
if ( V_23 != 0 ) {
F_81 ( V_260 , L_58 ,
V_23 ) ;
return V_23 ;
}
return V_59 & V_307 ;
}
static int F_90 ( struct V_259 * V_260 , int V_144 , bool V_55 )
{
struct V_9 * V_9 = V_260 -> V_9 ;
unsigned int V_12 ;
struct V_97 * V_97 ;
int V_23 ;
V_23 = F_9 ( V_9 -> V_17 , V_144 + 6 , & V_12 ) ;
if ( V_23 != 0 ) {
F_81 ( V_260 , L_59 ,
V_23 ) ;
return V_23 ;
}
V_12 &= V_298 ;
V_12 >>= V_300 ;
switch ( V_12 ) {
case V_308 :
V_97 = V_9 -> V_120 [ V_117 ] ;
break;
case V_309 :
V_97 = V_9 -> V_120 [ V_119 ] ;
break;
default:
return 0 ;
}
if ( V_55 ) {
return F_52 ( V_97 ) ;
} else {
F_53 ( V_97 ) ;
return 0 ;
}
}
static int F_91 ( struct V_259 * V_260 )
{
struct V_9 * V_9 = V_260 -> V_9 ;
bool V_310 = false ;
int V_311 = F_89 ( V_260 , V_260 -> V_144 ) ;
int V_312 = F_89 ( V_260 , V_260 -> V_144 + 0x10 ) ;
struct V_275 V_276 ;
int V_38 ;
unsigned int V_12 ;
if ( V_311 < 0 )
return V_311 ;
if ( V_312 < 0 )
return V_312 ;
if ( V_311 ) {
F_12 ( V_260 -> V_9 -> V_17 , V_260 -> V_144 + 1 ,
V_313 , V_313 ) ;
F_92 ( 32 ) ;
F_6 ( V_260 -> V_9 -> V_17 , V_260 -> V_144 + 0x9 ,
V_301 , 0 ) ;
if ( F_89 ( V_260 , V_260 -> V_144 + 0x10 ) > 0 )
F_90 ( V_260 , V_260 -> V_144 + 0x10 , false ) ;
F_90 ( V_260 , V_260 -> V_144 , false ) ;
}
if ( V_260 -> V_314 >= 0 && V_260 -> V_315 &&
V_260 -> V_314 != V_260 -> V_316 ) {
F_86 ( V_260 , & V_276 , V_260 -> V_315 , false ) ;
if ( V_260 -> V_316 >= 0 && V_276 . V_290 )
V_276 . V_289 = ( V_276 . V_289 * ( 1 << 16 ) ) / V_276 . V_290 ;
F_88 ( V_9 , V_260 -> V_144 , & V_276 , V_260 -> V_314 ,
false ) ;
if ( V_260 -> V_316 >= 0 ) {
F_86 ( V_260 , & V_276 , V_260 -> V_317 , true ) ;
F_88 ( V_9 , V_260 -> V_144 + 0x10 , & V_276 ,
V_260 -> V_316 , true ) ;
V_310 = true ;
}
} else if ( V_260 -> V_316 >= 0 ) {
F_86 ( V_260 , & V_276 , V_260 -> V_317 , false ) ;
F_88 ( V_9 , V_260 -> V_144 , & V_276 ,
V_260 -> V_316 , false ) ;
F_6 ( V_9 -> V_17 , V_260 -> V_144 + 0x11 ,
V_318 , 0 ) ;
} else {
F_81 ( V_260 , L_60 ) ;
return - V_84 ;
}
if ( V_311 && ! ! V_312 != V_310 )
F_85 ( V_260 , L_61 ) ;
if ( V_310 && V_260 -> V_317 > 100000 )
F_6 ( V_9 -> V_17 , V_260 -> V_144 + 0x17 ,
V_319 , 0 ) ;
else
F_6 ( V_9 -> V_17 , V_260 -> V_144 + 0x17 ,
V_319 ,
V_319 ) ;
if ( ! V_311 )
F_93 ( V_9 -> V_10 ) ;
if ( V_310 ) {
F_90 ( V_260 , V_260 -> V_144 + 0x10 , true ) ;
F_6 ( V_9 -> V_17 , V_260 -> V_144 + 0x11 ,
V_318 ,
V_318 ) ;
}
F_90 ( V_260 , V_260 -> V_144 , true ) ;
F_6 ( V_9 -> V_17 , V_260 -> V_144 + 1 ,
V_307 , V_307 ) ;
if ( V_311 )
F_6 ( V_9 -> V_17 , V_260 -> V_144 + 1 ,
V_313 , 0 ) ;
F_84 ( V_260 , L_62 ) ;
V_12 = 0 ;
for ( V_38 = 0 ; V_38 < 15 ; V_38 ++ ) {
if ( V_38 < 5 )
F_94 ( 200 , 400 ) ;
else
F_35 ( 20 ) ;
F_9 ( V_9 -> V_17 ,
V_320 ,
& V_12 ) ;
if ( V_12 & ( V_321 << ( V_260 -> V_180 - 1 ) ) )
break;
}
if ( V_38 == 15 )
F_85 ( V_260 , L_63 ) ;
else
F_84 ( V_260 , L_64 , V_38 ) ;
return 0 ;
}
static void F_95 ( struct V_259 * V_260 )
{
struct V_9 * V_9 = V_260 -> V_9 ;
bool V_322 , V_323 ;
F_6 ( V_9 -> V_17 , V_260 -> V_144 + 1 ,
V_313 , V_313 ) ;
F_96 ( V_9 -> V_17 , V_260 -> V_144 + 1 ,
V_307 , 0 , & V_322 ) ;
F_96 ( V_9 -> V_17 , V_260 -> V_144 + 0x11 ,
V_318 , 0 , & V_323 ) ;
F_6 ( V_9 -> V_17 , V_260 -> V_144 + 1 ,
V_313 , 0 ) ;
if ( V_323 )
F_90 ( V_260 , V_260 -> V_144 + 0x10 , false ) ;
if ( V_322 ) {
F_90 ( V_260 , V_260 -> V_144 , false ) ;
F_97 ( V_9 -> V_10 ) ;
}
}
int F_98 ( struct V_259 * V_260 , int V_122 ,
unsigned int V_261 , unsigned int V_262 )
{
int V_23 = 0 ;
if ( V_260 -> V_314 == V_122 && V_260 -> V_315 == V_261 )
return 0 ;
if ( V_260 -> V_264 && V_261 > 0 ) {
V_23 = F_80 ( V_260 , V_261 , V_260 -> V_264 ) ;
if ( V_23 != 0 )
return V_23 ;
}
V_260 -> V_314 = V_122 ;
V_260 -> V_315 = V_261 ;
if ( V_260 -> V_264 && V_261 > 0 ) {
V_23 = F_91 ( V_260 ) ;
}
return V_23 ;
}
int F_99 ( struct V_259 * V_260 , int V_122 ,
unsigned int V_261 , unsigned int V_262 )
{
int V_23 = 0 ;
if ( V_260 -> V_316 == V_122 &&
V_260 -> V_317 == V_261 && V_260 -> V_264 == V_262 )
return 0 ;
if ( V_262 ) {
if ( V_260 -> V_314 >= 0 ) {
V_23 = F_80 ( V_260 , V_260 -> V_315 , V_262 ) ;
if ( V_23 != 0 )
return V_23 ;
}
V_23 = F_80 ( V_260 , V_261 , V_262 ) ;
if ( V_23 != 0 )
return V_23 ;
}
V_260 -> V_316 = V_122 ;
V_260 -> V_317 = V_261 ;
V_260 -> V_264 = V_262 ;
if ( V_262 )
V_23 = F_91 ( V_260 ) ;
else
F_95 ( V_260 ) ;
return V_23 ;
}
int F_100 ( struct V_9 * V_9 , int V_180 , int V_144 , int V_324 ,
int V_325 , struct V_259 * V_260 )
{
unsigned int V_12 ;
V_260 -> V_180 = V_180 ;
V_260 -> V_144 = V_144 ;
V_260 -> V_9 = V_9 ;
V_260 -> V_316 = V_326 ;
F_9 ( V_9 -> V_17 , V_327 , & V_12 ) ;
switch ( V_12 & V_328 ) {
case V_116 :
case V_118 :
V_260 -> V_314 = V_12 & V_328 ;
break;
default:
V_260 -> V_314 = V_326 ;
}
V_260 -> V_315 = 32768 ;
snprintf ( V_260 -> V_329 , sizeof( V_260 -> V_329 ) , L_65 , V_180 ) ;
snprintf ( V_260 -> V_330 , sizeof( V_260 -> V_330 ) ,
L_66 , V_180 ) ;
F_12 ( V_9 -> V_17 , V_260 -> V_144 + 1 ,
V_313 , 0 ) ;
return 0 ;
}
int F_101 ( struct V_6 * V_7 , int V_331 , bool V_332 )
{
unsigned int V_59 , V_12 ;
if ( V_331 < 1 || V_331 > 6 )
return - V_84 ;
V_59 = V_333 + ( V_331 - 1 ) * 8 ;
if ( V_332 )
V_12 = V_334 ;
else
V_12 = 0 ;
return F_32 ( V_7 , V_59 , V_334 , V_12 ) ;
}
static bool F_102 ( bool V_143 , T_2 V_335 , T_2 V_336 )
{
T_3 V_337 = F_103 ( V_335 ) ;
T_3 V_338 = F_103 ( V_336 ) ;
if ( ! V_143 ) {
return abs ( V_337 ) >= 4096 ;
} else {
if ( abs ( V_338 ) >= 4096 )
return true ;
return ( abs ( ( V_337 << 16 ) / ( 4096 - V_338 ) ) >= 4096 << 4 ) ;
}
}
int F_104 ( struct V_3 * V_4 ,
struct V_339 * V_340 )
{
struct V_6 * V_7 = F_105 ( V_4 ) ;
struct V_9 * V_9 = F_3 ( V_7 -> V_10 -> V_11 ) ;
struct V_341 * V_198 = ( void * ) V_4 -> V_342 ;
unsigned int V_12 ;
T_2 * V_22 ;
int V_343 ;
int V_23 ;
V_343 = V_198 -> V_344 * F_106 ( V_9 -> V_17 ) ;
V_22 = F_107 ( V_340 -> V_345 . V_346 . V_22 , V_343 , V_347 | V_348 ) ;
if ( ! V_22 )
return - V_349 ;
V_22 [ 0 ] &= F_108 ( V_350 ) ;
if ( F_102 ( ! ! V_22 [ 0 ] , V_22 [ 1 ] , V_22 [ 2 ] ) ||
F_102 ( true , V_22 [ 4 ] , V_22 [ 5 ] ) ||
F_102 ( true , V_22 [ 8 ] , V_22 [ 9 ] ) ||
F_102 ( true , V_22 [ 12 ] , V_22 [ 13 ] ) ||
F_102 ( false , V_22 [ 16 ] , V_22 [ 17 ] ) ) {
F_10 ( V_9 -> V_10 , L_67 ) ;
V_23 = - V_84 ;
goto V_351;
}
V_23 = F_9 ( V_9 -> V_17 , V_198 -> V_144 , & V_12 ) ;
if ( V_23 != 0 )
goto V_351;
V_12 &= ~ V_350 ;
V_22 [ 0 ] |= F_108 ( V_12 ) ;
V_23 = F_109 ( V_9 -> V_17 , V_198 -> V_144 , V_22 , V_343 ) ;
V_351:
F_110 ( V_22 ) ;
return V_23 ;
}
int F_111 ( struct V_3 * V_4 ,
struct V_339 * V_340 )
{
struct V_6 * V_7 = F_105 ( V_4 ) ;
struct V_9 * V_9 = F_3 ( V_7 -> V_10 -> V_11 ) ;
T_2 * V_22 = ( T_2 * ) V_340 -> V_345 . V_346 . V_22 ;
T_3 V_12 = F_103 ( * V_22 ) ;
if ( abs ( V_12 ) >= 4096 ) {
F_10 ( V_9 -> V_10 , L_68 ) ;
return - V_84 ;
}
return F_112 ( V_4 , V_340 ) ;
}
