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
return 0 ;
}
static T_1 F_7 ( int V_21 , void * V_22 )
{
struct V_9 * V_9 = V_22 ;
unsigned int V_12 ;
int V_23 ;
V_23 = F_8 ( V_9 -> V_17 , V_14 ,
& V_12 ) ;
if ( V_23 != 0 ) {
F_9 ( V_9 -> V_10 , L_2 ,
V_23 ) ;
} else if ( V_12 & V_24 ) {
F_5 ( V_9 -> V_10 , L_3 ) ;
}
return V_25 ;
}
static T_1 F_10 ( int V_21 , void * V_22 )
{
struct V_9 * V_9 = V_22 ;
unsigned int V_12 ;
int V_23 ;
V_23 = F_8 ( V_9 -> V_17 , V_14 ,
& V_12 ) ;
if ( V_23 != 0 ) {
F_9 ( V_9 -> V_10 , L_2 ,
V_23 ) ;
} else if ( V_12 & V_15 ) {
F_5 ( V_9 -> V_10 , L_4 ) ;
V_23 = F_11 ( V_9 -> V_17 ,
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
int F_12 ( struct V_6 * V_7 )
{
struct V_28 * V_8 = F_13 ( V_7 ) ;
struct V_29 * V_30 = F_14 ( V_7 ) ;
struct V_9 * V_9 = V_30 -> V_9 ;
int V_23 ;
V_23 = F_15 ( V_8 , & V_31 , 1 ) ;
if ( V_23 != 0 )
return V_23 ;
switch ( V_9 -> type ) {
case V_32 :
case V_33 :
case V_34 :
break;
default:
V_23 = F_15 ( V_8 , & V_35 , 1 ) ;
if ( V_23 != 0 )
return V_23 ;
break;
}
V_23 = F_16 ( V_9 , V_36 ,
L_6 , F_7 ,
V_9 ) ;
if ( V_23 != 0 )
F_9 ( V_9 -> V_10 ,
L_7 ,
V_23 ) ;
V_23 = F_16 ( V_9 , V_37 ,
L_8 , F_10 ,
V_9 ) ;
if ( V_23 != 0 )
F_9 ( V_9 -> V_10 ,
L_9 ,
V_23 ) ;
return 0 ;
}
int F_17 ( struct V_6 * V_7 )
{
struct V_29 * V_30 = F_14 ( V_7 ) ;
struct V_9 * V_9 = V_30 -> V_9 ;
F_18 ( V_9 , V_36 , V_9 ) ;
F_18 ( V_9 , V_37 , V_9 ) ;
return 0 ;
}
int F_19 ( struct V_6 * V_7 )
{
struct V_28 * V_8 = F_13 ( V_7 ) ;
struct V_29 * V_30 = F_14 ( V_7 ) ;
struct V_9 * V_9 = V_30 -> V_9 ;
int V_38 ;
for ( V_38 = 0 ; V_38 < V_39 ; ++ V_38 ) {
if ( V_9 -> V_40 . V_41 [ V_38 ] )
F_20 ( V_8 ,
& V_42 [ V_38 ] , 1 ) ;
}
return 0 ;
}
int F_21 ( struct V_6 * V_7 )
{
struct V_28 * V_8 = F_13 ( V_7 ) ;
struct V_29 * V_30 = F_14 ( V_7 ) ;
struct V_9 * V_9 = V_30 -> V_9 ;
int V_38 ;
switch ( V_9 -> type ) {
case V_43 :
case V_44 :
F_22 ( V_8 , L_10 ) ;
break;
default:
break;
}
F_22 ( V_8 , L_11 ) ;
for ( V_38 = 0 ; V_38 < F_23 ( V_9 -> V_40 . V_45 ) ; V_38 ++ ) {
switch ( V_9 -> V_40 . V_45 [ V_38 ] & V_46 ) {
case V_47 :
F_24 ( V_8 , L_11 ) ;
break;
case V_48 :
F_24 ( V_8 , L_10 ) ;
break;
default:
break;
}
}
return 0 ;
}
int F_25 ( struct V_6 * V_7 )
{
struct V_29 * V_30 = F_14 ( V_7 ) ;
struct V_9 * V_9 = V_30 -> V_9 ;
F_26 ( & V_9 -> V_49 ) ;
return 0 ;
}
const char * F_27 ( unsigned int V_50 )
{
int V_38 ;
for ( V_38 = 0 ; V_38 < F_23 ( V_51 ) ; ++ V_38 ) {
if ( V_51 [ V_38 ] == V_50 )
return V_52 [ V_38 ] ;
}
return L_12 ;
}
static void F_28 ( struct V_6 * V_7 , int V_53 )
{
struct V_29 * V_30 = F_14 ( V_7 ) ;
unsigned int V_12 ;
int V_38 ;
if ( V_53 )
V_12 = V_54 ;
else
V_12 = 0 ;
for ( V_38 = 0 ; V_38 < V_30 -> V_55 ; V_38 ++ )
F_29 ( V_7 ,
V_56 + ( V_38 * 4 ) ,
V_54 , V_12 ) ;
}
bool F_30 ( struct V_6 * V_7 , int V_19 )
{
unsigned int V_57 = V_58 + ( ( V_19 / 2 ) * 8 ) ;
unsigned int V_12 = F_4 ( V_7 , V_57 ) ;
return ! ( V_12 & V_59 ) ;
}
int F_31 ( struct V_1 * V_2 , struct V_3 * V_4 ,
int V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 -> V_8 ) ;
struct V_29 * V_30 = F_14 ( V_7 ) ;
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
F_29 ( V_7 , V_57 , V_63 , 0 ) ;
V_30 -> V_62 -- ;
if ( V_30 -> V_62 == 0 ) {
F_32 ( 1 ) ;
F_28 ( V_7 , 1 ) ;
}
break;
case V_20 :
F_29 ( V_7 , V_57 ,
V_63 | V_54 ,
V_63 | V_54 ) ;
break;
case V_64 :
V_57 = F_4 ( V_7 , V_65 ) ;
if ( V_57 == 0 )
F_28 ( V_7 , 0 ) ;
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
struct V_29 * V_30 = F_14 ( V_7 ) ;
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
V_30 -> V_72 -- ;
if ( ! V_30 -> V_72 ) {
F_32 ( V_30 -> V_73 ) ;
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
V_30 -> V_74 ++ ;
V_30 -> V_75 ++ ;
break;
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
V_30 -> V_74 -- ;
if ( ! V_30 -> V_74 ) {
F_32 ( V_30 -> V_75 ) ;
V_30 -> V_75 = 0 ;
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
int F_34 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
int V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 -> V_8 ) ;
struct V_29 * V_30 = F_14 ( V_7 ) ;
struct V_9 * V_9 = V_30 -> V_9 ;
unsigned int V_76 = 1 << V_2 -> V_19 ;
unsigned int V_12 ;
switch ( V_5 ) {
case V_13 :
V_12 = V_76 ;
break;
case V_20 :
V_12 = 0 ;
break;
case V_61 :
case V_64 :
return F_33 ( V_2 , V_4 , V_5 ) ;
default:
return - V_77 ;
}
V_30 -> V_9 -> V_78 &= ~ V_76 ;
V_30 -> V_9 -> V_78 |= V_12 ;
if ( V_30 -> V_9 -> V_79 )
V_12 = 0 ;
F_6 ( V_9 -> V_17 , V_18 ,
V_76 , V_12 ) ;
return F_33 ( V_2 , V_4 , V_5 ) ;
}
static int F_35 ( struct V_6 * V_7 )
{
const struct V_29 * V_30 = F_14 ( V_7 ) ;
struct V_9 * V_9 = V_30 -> V_9 ;
int V_23 ;
V_23 = F_36 ( V_9 -> V_80 , 1800000 , 1800000 ) ;
if ( V_23 ) {
F_9 ( V_7 -> V_10 , L_13 , V_23 ) ;
return V_23 ;
}
V_23 = F_11 ( V_9 -> V_17 ,
V_81 ,
V_82 ,
V_82 ) ;
if ( V_23 ) {
F_9 ( V_7 -> V_10 , L_14 , V_23 ) ;
F_36 ( V_9 -> V_80 , 1200000 , 1800000 ) ;
return V_23 ;
}
return 0 ;
}
static int F_37 ( struct V_6 * V_7 )
{
const struct V_29 * V_30 = F_14 ( V_7 ) ;
struct V_9 * V_9 = V_30 -> V_9 ;
int V_23 ;
V_23 = F_11 ( V_9 -> V_17 ,
V_81 ,
V_82 , 0 ) ;
if ( V_23 ) {
F_9 ( V_7 -> V_10 , L_15 , V_23 ) ;
return V_23 ;
}
V_23 = F_36 ( V_9 -> V_80 , 1200000 , 1800000 ) ;
if ( V_23 ) {
F_9 ( V_7 -> V_10 , L_16 , V_23 ) ;
return V_23 ;
}
return 0 ;
}
int F_38 ( struct V_6 * V_7 , unsigned int V_83 )
{
struct V_29 * V_30 = F_14 ( V_7 ) ;
int V_23 = 0 ;
F_39 ( & V_30 -> V_84 ) ;
if ( ! V_30 -> V_85 && ! V_30 -> V_86 ) {
V_23 = F_35 ( V_7 ) ;
if ( V_23 )
goto V_87;
}
V_30 -> V_86 |= V_83 ;
V_87:
F_40 ( & V_30 -> V_84 ) ;
return V_23 ;
}
int F_41 ( struct V_6 * V_7 , unsigned int V_83 )
{
struct V_29 * V_30 = F_14 ( V_7 ) ;
unsigned int V_88 ;
int V_23 = 0 ;
F_39 ( & V_30 -> V_84 ) ;
V_88 = V_30 -> V_86 ;
V_30 -> V_86 &= ~ V_83 ;
if ( ! V_30 -> V_85 && V_88 && ! V_30 -> V_86 )
V_23 = F_37 ( V_7 ) ;
F_40 ( & V_30 -> V_84 ) ;
return V_23 ;
}
int F_42 ( struct V_1 * V_2 ,
struct V_3 * V_4 , int V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 -> V_8 ) ;
struct V_29 * V_30 = F_14 ( V_7 ) ;
int V_23 = 0 ;
F_39 ( & V_30 -> V_84 ) ;
switch ( V_5 ) {
case V_13 :
if ( V_30 -> V_86 )
V_23 = F_35 ( V_7 ) ;
V_30 -> V_85 = false ;
break;
case V_20 :
V_30 -> V_85 = true ;
if ( V_30 -> V_86 )
V_23 = F_37 ( V_7 ) ;
break;
default:
break;
}
F_40 ( & V_30 -> V_84 ) ;
return V_23 ;
}
void F_43 ( struct V_29 * V_30 )
{
F_44 ( & V_30 -> V_84 ) ;
}
int F_45 ( struct V_1 * V_2 ,
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
F_46 ( V_7 , V_89 , V_12 ) ;
return 0 ;
}
static int F_47 ( struct V_6 * V_7 , unsigned int V_90 ,
unsigned int V_91 )
{
struct V_29 * V_30 = F_14 ( V_7 ) ;
unsigned int V_57 ;
unsigned int * V_92 ;
int V_93 , div , V_94 ;
switch ( V_90 ) {
case V_95 :
V_57 = V_96 ;
V_94 = V_30 -> V_97 ;
break;
case V_98 :
V_57 = V_99 ;
V_94 = V_30 -> V_100 ;
break;
default:
return - V_77 ;
}
if ( V_94 % 8000 )
V_92 = V_101 ;
else
V_92 = V_102 ;
for ( V_93 = 0 ; V_93 < F_23 ( V_102 ) &&
V_92 [ V_93 ] <= V_94 ; V_93 ++ ) {
div = 1 ;
while ( V_92 [ V_93 ] / div >= V_91 && div < 32 ) {
if ( V_92 [ V_93 ] / div == V_91 ) {
F_48 ( V_7 -> V_10 , L_17 ,
V_91 ) ;
F_29 ( V_7 , V_57 ,
V_103 |
V_104 ,
( div <<
V_105 ) |
V_93 ) ;
return 0 ;
}
div ++ ;
}
}
F_9 ( V_7 -> V_10 , L_18 , V_91 ) ;
return - V_77 ;
}
int F_49 ( struct V_6 * V_7 , int V_106 ,
int V_107 , unsigned int V_91 , int V_108 )
{
struct V_29 * V_30 = F_14 ( V_7 ) ;
struct V_9 * V_9 = V_30 -> V_9 ;
char * V_109 ;
unsigned int V_57 ;
unsigned int V_76 = V_110 | V_111 ;
unsigned int V_12 = V_107 << V_112 ;
int * V_90 ;
switch ( V_106 ) {
case V_113 :
V_109 = L_19 ;
V_57 = V_114 ;
V_90 = & V_30 -> V_97 ;
V_76 |= V_115 ;
break;
case V_116 :
V_109 = L_20 ;
V_57 = V_117 ;
V_90 = & V_30 -> V_100 ;
break;
case V_95 :
case V_98 :
return F_47 ( V_7 , V_106 , V_91 ) ;
default:
return - V_77 ;
}
switch ( V_91 ) {
case 5644800 :
case 6144000 :
break;
case 11289600 :
case 12288000 :
V_12 |= V_118 << V_119 ;
break;
case 22579200 :
case 24576000 :
V_12 |= V_120 << V_119 ;
break;
case 45158400 :
case 49152000 :
V_12 |= V_121 << V_119 ;
break;
case 67737600 :
case 73728000 :
V_12 |= V_122 << V_119 ;
break;
case 90316800 :
case 98304000 :
V_12 |= V_123 << V_119 ;
break;
case 135475200 :
case 147456000 :
V_12 |= V_124 << V_119 ;
break;
case 0 :
F_48 ( V_9 -> V_10 , L_21 , V_109 ) ;
* V_90 = V_91 ;
return 0 ;
default:
return - V_77 ;
}
* V_90 = V_91 ;
if ( V_91 % 6144000 )
V_12 |= V_115 ;
F_48 ( V_9 -> V_10 , L_22 , V_109 , V_91 ) ;
return F_11 ( V_9 -> V_17 , V_57 , V_76 , V_12 ) ;
}
static int F_50 ( struct V_125 * V_126 , unsigned int V_127 )
{
struct V_6 * V_7 = V_126 -> V_7 ;
struct V_29 * V_30 = F_14 ( V_7 ) ;
struct V_9 * V_9 = V_30 -> V_9 ;
int V_128 , V_129 , V_130 , V_131 ;
V_131 = V_126 -> V_132 -> V_131 ;
V_128 = 0 ;
V_129 = 0 ;
switch ( V_127 & V_133 ) {
case V_134 :
V_130 = V_135 ;
break;
case V_136 :
if ( ( V_127 & V_137 )
!= V_138 ) {
F_51 ( V_126 , L_23 ) ;
return - V_77 ;
}
V_130 = V_139 ;
break;
case V_140 :
V_130 = V_141 ;
break;
case V_142 :
if ( ( V_127 & V_137 )
!= V_138 ) {
F_51 ( V_126 , L_24 ) ;
return - V_77 ;
}
V_130 = V_143 ;
break;
default:
F_51 ( V_126 , L_25 ,
V_127 & V_133 ) ;
return - V_77 ;
}
switch ( V_127 & V_137 ) {
case V_144 :
break;
case V_145 :
V_128 |= V_146 ;
break;
case V_147 :
V_129 |= V_148 ;
break;
case V_138 :
V_129 |= V_148 ;
V_128 |= V_146 ;
break;
default:
F_51 ( V_126 , L_26 ,
V_127 & V_137 ) ;
return - V_77 ;
}
switch ( V_127 & V_149 ) {
case V_150 :
break;
case V_151 :
V_129 |= V_152 ;
V_128 |= V_153 ;
break;
case V_154 :
V_129 |= V_152 ;
break;
case V_155 :
V_128 |= V_153 ;
break;
default:
return - V_77 ;
}
F_6 ( V_9 -> V_17 , V_131 + V_156 ,
V_152 |
V_148 ,
V_129 ) ;
F_6 ( V_9 -> V_17 , V_131 + V_157 ,
V_153 |
V_146 , V_128 ) ;
F_6 ( V_9 -> V_17 ,
V_131 + V_158 ,
V_159 |
V_160 , V_128 ) ;
F_11 ( V_9 -> V_17 , V_131 + V_161 ,
V_162 , V_130 ) ;
return 0 ;
}
static int F_52 ( struct V_163 * V_164 ,
struct V_125 * V_126 )
{
struct V_6 * V_7 = V_126 -> V_7 ;
struct V_29 * V_30 = F_14 ( V_7 ) ;
struct V_165 * V_166 = & V_30 -> V_126 [ V_126 -> V_167 - 1 ] ;
unsigned int V_168 ;
if ( ! V_164 -> V_169 )
return 0 ;
switch ( V_166 -> V_90 ) {
case V_113 :
V_168 = V_30 -> V_97 ;
break;
case V_116 :
V_168 = V_30 -> V_100 ;
break;
default:
return 0 ;
}
if ( V_168 == 0 )
V_166 -> V_170 . V_76 = V_171 ;
else if ( V_168 % 8000 )
V_166 -> V_170 . V_76 = V_172 ;
else
V_166 -> V_170 . V_76 = V_173 ;
return F_53 ( V_164 -> V_169 , 0 ,
V_174 ,
& V_166 -> V_170 ) ;
}
static void F_54 ( struct V_6 * V_7 ,
unsigned int V_175 )
{
struct V_29 * V_30 = F_14 ( V_7 ) ;
struct V_9 * V_9 = V_30 -> V_9 ;
struct V_176 V_177 [] = {
{ 0x80 , 0x3 } ,
{ V_178 , 0 } ,
{ V_179 , 0 } ,
{ 0x80 , 0x0 } ,
} ;
F_39 ( & V_9 -> V_180 ) ;
V_177 [ 1 ] . V_181 = V_9 -> V_182 ;
if ( V_175 >= 176400 )
V_177 [ 2 ] . V_181 = V_9 -> V_183 ;
F_40 ( & V_9 -> V_180 ) ;
F_55 ( V_9 -> V_17 ,
V_177 ,
F_23 ( V_177 ) ) ;
}
static int F_56 ( struct V_163 * V_164 ,
struct V_184 * V_185 ,
struct V_125 * V_126 )
{
struct V_6 * V_7 = V_126 -> V_7 ;
struct V_29 * V_30 = F_14 ( V_7 ) ;
struct V_165 * V_166 = & V_30 -> V_126 [ V_126 -> V_167 - 1 ] ;
int V_131 = V_126 -> V_132 -> V_131 ;
int V_38 , V_186 , V_23 ;
for ( V_38 = 0 ; V_38 < F_23 ( V_187 ) ; V_38 ++ )
if ( V_187 [ V_38 ] == F_57 ( V_185 ) )
break;
if ( V_38 == F_23 ( V_187 ) ) {
F_51 ( V_126 , L_27 ,
F_57 ( V_185 ) ) ;
return - V_77 ;
}
V_186 = V_38 ;
switch ( V_30 -> V_9 -> type ) {
case V_188 :
case V_32 :
if ( V_187 [ V_186 ] >= 88200 )
V_23 = F_38 ( V_7 , V_189 ) ;
else
V_23 = F_41 ( V_7 , V_189 ) ;
if ( V_23 ) {
F_51 ( V_126 , L_28 , V_23 ) ;
return V_23 ;
}
break;
default:
break;
}
switch ( V_166 -> V_90 ) {
case V_113 :
switch ( V_30 -> V_9 -> type ) {
case V_188 :
F_54 ( V_7 ,
F_57 ( V_185 ) ) ;
break;
default:
break;
}
F_29 ( V_7 , V_190 ,
V_191 , V_186 ) ;
if ( V_131 )
F_29 ( V_7 , V_131 + V_192 ,
V_193 , 0 ) ;
break;
case V_116 :
F_29 ( V_7 , V_194 ,
V_195 , V_186 ) ;
if ( V_131 )
F_29 ( V_7 , V_131 + V_192 ,
V_193 ,
8 << V_196 ) ;
break;
default:
F_51 ( V_126 , L_29 , V_166 -> V_90 ) ;
return - V_77 ;
}
return 0 ;
}
static bool F_58 ( struct V_6 * V_7 ,
int V_131 , int V_129 , int V_128 , int V_197 )
{
int V_12 ;
V_12 = F_4 ( V_7 , V_131 + V_156 ) ;
if ( V_129 != ( V_12 & V_198 ) )
return true ;
V_12 = F_4 ( V_7 , V_131 + V_199 ) ;
if ( V_128 != ( V_12 & V_200 ) )
return true ;
V_12 = F_4 ( V_7 , V_131 + V_201 ) ;
if ( V_197 != ( V_12 & ( V_202 |
V_203 ) ) )
return true ;
return false ;
}
static int F_59 ( struct V_163 * V_164 ,
struct V_184 * V_185 ,
struct V_125 * V_126 )
{
struct V_6 * V_7 = V_126 -> V_7 ;
struct V_29 * V_30 = F_14 ( V_7 ) ;
struct V_9 * V_9 = V_30 -> V_9 ;
int V_131 = V_126 -> V_132 -> V_131 ;
const int * V_92 ;
int V_38 , V_23 , V_12 ;
int V_204 = F_60 ( V_185 ) ;
int V_205 = V_9 -> V_40 . V_206 [ V_126 -> V_167 - 1 ] ;
int V_207 = V_9 -> V_207 [ V_126 -> V_167 - 1 ] ;
int V_208 = V_9 -> V_208 [ V_126 -> V_167 - 1 ] ;
int V_129 , V_128 , V_209 , V_197 , V_210 ;
bool V_211 ;
unsigned int V_212 , V_213 ;
if ( F_57 ( V_185 ) % 4000 )
V_92 = & V_214 [ 0 ] ;
else
V_92 = & V_215 [ 0 ] ;
V_209 = F_61 ( V_185 ) ;
if ( V_208 ) {
F_62 ( V_126 , L_30 ,
V_208 , V_207 ) ;
V_210 = V_208 * V_207 * F_57 ( V_185 ) ;
V_204 = V_208 ;
} else {
V_210 = F_63 ( V_185 ) ;
V_207 = V_209 ;
}
if ( V_205 && V_205 < V_204 ) {
F_62 ( V_126 , L_31 , V_205 ) ;
V_210 /= V_204 ;
V_210 *= V_205 ;
}
V_12 = F_4 ( V_7 , V_131 + V_161 ) ;
V_12 &= V_162 ;
if ( ( V_204 & 1 ) && ( V_12 == V_141 ) ) {
F_62 ( V_126 , L_32 ) ;
V_210 /= V_204 ;
V_210 *= V_204 + 1 ;
}
for ( V_38 = 0 ; V_38 < F_23 ( V_214 ) ; V_38 ++ ) {
if ( V_92 [ V_38 ] >= V_210 &&
V_92 [ V_38 ] % F_57 ( V_185 ) == 0 ) {
V_129 = V_38 ;
break;
}
}
if ( V_38 == F_23 ( V_214 ) ) {
F_51 ( V_126 , L_27 ,
F_57 ( V_185 ) ) ;
return - V_77 ;
}
V_128 = V_92 [ V_129 ] / F_57 ( V_185 ) ;
F_62 ( V_126 , L_33 ,
V_92 [ V_129 ] , V_92 [ V_129 ] / V_128 ) ;
V_197 = V_209 << V_216 | V_207 ;
V_211 = F_58 ( V_7 , V_131 , V_129 , V_128 , V_197 ) ;
if ( V_211 ) {
V_212 = F_4 ( V_7 ,
V_131 + V_217 ) ;
V_213 = F_4 ( V_7 ,
V_131 + V_218 ) ;
F_6 ( V_9 -> V_17 ,
V_131 + V_217 , 0xff , 0x0 ) ;
F_11 ( V_9 -> V_17 ,
V_131 + V_218 , 0xff , 0x0 ) ;
}
V_23 = F_56 ( V_164 , V_185 , V_126 ) ;
if ( V_23 != 0 )
goto V_219;
if ( V_211 ) {
F_6 ( V_9 -> V_17 ,
V_131 + V_156 ,
V_198 , V_129 ) ;
F_6 ( V_9 -> V_17 ,
V_131 + V_199 ,
V_200 , V_128 ) ;
F_6 ( V_9 -> V_17 ,
V_131 + V_220 ,
V_221 , V_128 ) ;
F_6 ( V_9 -> V_17 ,
V_131 + V_201 ,
V_202 |
V_203 , V_197 ) ;
F_11 ( V_9 -> V_17 ,
V_131 + V_222 ,
V_223 |
V_224 , V_197 ) ;
}
V_219:
if ( V_211 ) {
F_6 ( V_9 -> V_17 ,
V_131 + V_217 ,
0xff , V_212 ) ;
F_11 ( V_9 -> V_17 ,
V_131 + V_218 ,
0xff , V_213 ) ;
}
return V_23 ;
}
static const char * F_64 ( int V_106 )
{
switch ( V_106 ) {
case V_113 :
return L_19 ;
case V_116 :
return L_20 ;
default:
return L_34 ;
}
}
static int F_65 ( struct V_125 * V_126 ,
int V_106 , unsigned int V_91 , int V_108 )
{
struct V_6 * V_7 = V_126 -> V_7 ;
struct V_28 * V_8 = F_13 ( V_7 ) ;
struct V_29 * V_30 = F_14 ( V_7 ) ;
struct V_165 * V_166 = & V_30 -> V_126 [ V_126 -> V_167 - 1 ] ;
struct V_225 V_226 [ 2 ] ;
switch ( V_106 ) {
case V_113 :
case V_116 :
break;
default:
return - V_77 ;
}
if ( V_106 == V_166 -> V_90 )
return 0 ;
if ( V_126 -> V_227 ) {
F_9 ( V_7 -> V_10 , L_35 ,
V_126 -> V_167 ) ;
return - V_16 ;
}
F_48 ( V_7 -> V_10 , L_36 , V_126 -> V_167 + 1 ,
F_64 ( V_106 ) ) ;
memset ( & V_226 , 0 , sizeof( V_226 ) ) ;
V_226 [ 0 ] . V_228 = V_126 -> V_132 -> V_229 . V_230 ;
V_226 [ 1 ] . V_228 = V_126 -> V_132 -> V_231 . V_230 ;
V_226 [ 0 ] . V_107 = F_64 ( V_166 -> V_90 ) ;
V_226 [ 1 ] . V_107 = F_64 ( V_166 -> V_90 ) ;
F_66 ( V_8 , V_226 , F_23 ( V_226 ) ) ;
V_226 [ 0 ] . V_107 = F_64 ( V_106 ) ;
V_226 [ 1 ] . V_107 = F_64 ( V_106 ) ;
F_20 ( V_8 , V_226 , F_23 ( V_226 ) ) ;
V_166 -> V_90 = V_106 ;
return F_67 ( V_8 ) ;
}
static int F_68 ( struct V_125 * V_126 , int V_232 )
{
struct V_6 * V_7 = V_126 -> V_7 ;
int V_131 = V_126 -> V_132 -> V_131 ;
unsigned int V_57 ;
if ( V_232 )
V_57 = V_233 ;
else
V_57 = 0 ;
return F_29 ( V_7 , V_131 + V_192 ,
V_233 , V_57 ) ;
}
static void F_69 ( struct V_125 * V_126 ,
unsigned int V_131 ,
int V_204 , unsigned int V_76 )
{
struct V_6 * V_7 = V_126 -> V_7 ;
struct V_29 * V_30 = F_14 ( V_7 ) ;
struct V_9 * V_9 = V_30 -> V_9 ;
int V_234 , V_38 ;
for ( V_38 = 0 ; V_38 < V_204 ; ++ V_38 ) {
V_234 = F_70 ( V_76 ) - 1 ;
if ( V_234 < 0 )
return;
F_71 ( V_9 -> V_17 , V_131 + V_38 , V_234 ) ;
V_76 &= ~ ( 1 << V_234 ) ;
}
if ( V_76 )
F_72 ( V_126 , L_37 ) ;
}
static int F_73 ( struct V_125 * V_126 , unsigned int V_235 ,
unsigned int V_236 , int V_237 , int V_238 )
{
struct V_6 * V_7 = V_126 -> V_7 ;
struct V_29 * V_30 = F_14 ( V_7 ) ;
struct V_9 * V_9 = V_30 -> V_9 ;
int V_131 = V_126 -> V_132 -> V_131 ;
int V_239 = V_126 -> V_132 -> V_231 . V_240 ;
int V_241 = V_126 -> V_132 -> V_229 . V_240 ;
if ( V_126 -> V_167 > V_242 )
return - V_243 ;
if ( V_237 == 0 ) {
V_235 = ( 1 << V_241 ) - 1 ;
V_236 = ( 1 << V_239 ) - 1 ;
}
F_69 ( V_126 , V_131 + V_244 ,
V_241 , V_235 ) ;
F_69 ( V_126 , V_131 + V_245 ,
V_239 , V_236 ) ;
V_9 -> V_207 [ V_126 -> V_167 - 1 ] = V_238 ;
V_9 -> V_208 [ V_126 -> V_167 - 1 ] = V_237 ;
return 0 ;
}
int F_74 ( struct V_29 * V_30 , int V_167 )
{
struct V_165 * V_166 = & V_30 -> V_126 [ V_167 ] ;
V_166 -> V_90 = V_113 ;
V_166 -> V_170 = V_246 ;
return 0 ;
}
static int F_75 ( struct V_247 * V_248 ,
unsigned int V_249 ,
unsigned int V_250 )
{
unsigned int V_251 ;
if ( V_248 -> V_252 && V_250 != V_248 -> V_252 ) {
F_76 ( V_248 ,
L_38 ) ;
return - V_77 ;
}
if ( V_249 / V_253 > V_254 ) {
F_76 ( V_248 ,
L_39 ,
V_249 ) ;
return - V_77 ;
}
V_251 = V_255 * V_248 -> V_256 ;
if ( V_250 * V_257 < V_251 ) {
F_76 ( V_248 , L_40 ,
V_250 ) ;
return - V_77 ;
}
return 0 ;
}
static int F_77 ( unsigned int V_249 , int * V_258 )
{
int V_38 ;
for ( V_38 = 0 ; V_38 < F_23 ( V_259 ) ; V_38 ++ ) {
if ( V_259 [ V_38 ] . V_260 <= V_249 && V_249 <= V_259 [ V_38 ] . V_261 ) {
if ( V_258 )
* V_258 = V_259 [ V_38 ] . V_258 ;
return V_259 [ V_38 ] . V_262 ;
}
}
return - V_77 ;
}
static int F_78 ( struct V_247 * V_248 ,
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
return - V_77 ;
}
V_267 = F_77 ( V_249 , & V_264 -> V_258 ) ;
if ( V_267 < 0 ) {
F_76 ( V_248 , L_41 ,
V_249 ) ;
return V_267 ;
}
switch ( V_248 -> V_9 -> type ) {
case V_188 :
case V_32 :
return V_267 ;
case V_43 :
case V_44 :
if ( V_248 -> V_9 -> V_269 < 3 || V_266 )
return V_267 ;
break;
default:
if ( V_266 )
return V_267 ;
break;
}
V_264 -> V_258 = V_267 - 1 ;
V_268 = V_264 -> V_268 ;
F_79 ( V_248 , L_42 ,
V_267 , V_249 , V_268 ) ;
while ( div <= V_253 ) {
for ( V_262 = V_267 ; V_262 > 0 ; V_262 -- ) {
if ( V_265 % ( V_262 * V_249 ) ) {
V_264 -> V_268 = V_268 ;
V_264 -> V_258 = V_262 - 1 ;
F_79 ( V_248 ,
L_43 ,
V_249 , V_268 , div , V_262 ) ;
return V_262 ;
}
}
for ( V_262 = V_267 + 1 ; V_262 <= V_270 ;
V_262 ++ ) {
if ( ( V_271 / 2 ) /
( V_248 -> V_256 * V_262 ) < V_249 ) {
F_79 ( V_248 , L_44 ) ;
break;
}
if ( V_249 > V_272 [ V_262 - 1 ] ) {
F_79 ( V_248 ,
L_45 ,
V_272 [ V_262 - 1 ] ,
V_262 ) ;
break;
}
if ( V_265 % ( V_262 * V_249 ) ) {
V_264 -> V_268 = V_268 ;
V_264 -> V_258 = V_262 - 1 ;
F_79 ( V_248 ,
L_43 ,
V_249 , V_268 , div , V_262 ) ;
return V_262 ;
}
}
div *= 2 ;
V_249 /= 2 ;
V_268 ++ ;
V_267 = F_77 ( V_249 , NULL ) ;
F_79 ( V_248 ,
L_46 ,
V_249 , V_268 , div , V_267 ) ;
}
F_80 ( V_248 , L_47 ) ;
return V_264 -> V_258 + 1 ;
}
static int F_81 ( struct V_247 * V_248 ,
struct V_263 * V_264 ,
unsigned int V_249 , bool V_266 )
{
unsigned int V_265 , div , V_273 ;
int V_38 , V_262 ;
F_79 ( V_248 , L_48 , V_249 , V_248 -> V_252 ) ;
div = V_274 ;
while ( V_248 -> V_252 * div < V_255 * V_248 -> V_256 ) {
div ++ ;
if ( div > V_257 )
return - V_77 ;
}
V_265 = V_248 -> V_252 * div / V_248 -> V_256 ;
V_264 -> V_275 = div ;
F_79 ( V_248 , L_49 , V_265 ) ;
V_262 = F_78 ( V_248 , V_264 , V_265 , V_249 , V_266 ) ;
if ( V_262 < 0 )
return V_262 ;
V_249 = V_249 / ( 1 << V_264 -> V_268 ) ;
V_264 -> V_276 = V_265 / ( V_262 * V_249 ) ;
if ( V_265 % ( V_262 * V_249 ) ) {
V_273 = F_82 ( V_265 , V_262 * V_249 ) ;
F_79 ( V_248 , L_50 , V_273 ) ;
V_264 -> V_277 = ( V_265 - ( V_264 -> V_276 * V_262 * V_249 ) )
/ V_273 ;
V_264 -> V_278 = ( V_262 * V_249 ) / V_273 ;
} else {
V_264 -> V_277 = 0 ;
V_264 -> V_278 = 0 ;
}
while ( V_264 -> V_278 >= ( 1 << 16 ) ) {
V_264 -> V_277 >>= 1 ;
V_264 -> V_278 >>= 1 ;
}
for ( V_38 = 0 ; V_38 < F_23 ( V_279 ) ; V_38 ++ ) {
if ( V_279 [ V_38 ] . V_260 <= V_249 && V_249 <= V_279 [ V_38 ] . V_261 ) {
V_264 -> V_280 = V_279 [ V_38 ] . V_280 ;
break;
}
}
if ( V_38 == F_23 ( V_279 ) ) {
F_76 ( V_248 , L_51 ,
V_249 ) ;
return - V_77 ;
}
F_79 ( V_248 , L_52 ,
V_264 -> V_276 , V_264 -> V_277 , V_264 -> V_278 ) ;
F_79 ( V_248 , L_53 ,
V_264 -> V_258 , V_262 , V_264 -> V_275 ,
V_264 -> V_268 , 1 << V_264 -> V_268 ) ;
F_79 ( V_248 , L_54 , V_264 -> V_280 , 1 << V_264 -> V_280 ) ;
return 0 ;
}
static void F_83 ( struct V_9 * V_9 , unsigned int V_131 ,
struct V_263 * V_264 , int V_107 ,
bool V_266 )
{
F_6 ( V_9 -> V_17 , V_131 + 3 ,
V_281 , V_264 -> V_277 ) ;
F_6 ( V_9 -> V_17 , V_131 + 4 ,
V_282 , V_264 -> V_278 ) ;
F_6 ( V_9 -> V_17 , V_131 + 5 ,
V_283 ,
V_264 -> V_258 << V_284 ) ;
F_6 ( V_9 -> V_17 , V_131 + 6 ,
V_285 |
V_286 ,
V_264 -> V_268 << V_287 |
V_107 << V_288 ) ;
if ( V_266 ) {
F_11 ( V_9 -> V_17 , V_131 + 0x7 ,
V_289 ,
V_264 -> V_280 << V_290 ) ;
} else {
F_11 ( V_9 -> V_17 , V_131 + 0x5 ,
V_291 ,
V_264 -> V_275 << V_292 ) ;
F_11 ( V_9 -> V_17 , V_131 + 0x9 ,
V_289 ,
V_264 -> V_280 << V_290 ) ;
}
F_6 ( V_9 -> V_17 , V_131 + 2 ,
V_293 | V_294 ,
V_293 | V_264 -> V_276 ) ;
}
static int F_84 ( struct V_247 * V_248 )
{
struct V_9 * V_9 = V_248 -> V_9 ;
unsigned int V_57 ;
int V_23 ;
V_23 = F_8 ( V_9 -> V_17 , V_248 -> V_131 + 1 , & V_57 ) ;
if ( V_23 != 0 ) {
F_76 ( V_248 , L_55 ,
V_23 ) ;
return V_23 ;
}
return V_57 & V_295 ;
}
static int F_85 ( struct V_247 * V_248 )
{
struct V_9 * V_9 = V_248 -> V_9 ;
bool V_296 = false ;
int V_297 = F_84 ( V_248 ) ;
struct V_263 V_264 ;
int V_38 ;
unsigned int V_12 ;
if ( V_297 < 0 )
return V_297 ;
if ( V_297 ) {
F_6 ( V_248 -> V_9 -> V_17 , V_248 -> V_131 + 0x9 ,
V_289 , 0 ) ;
F_11 ( V_248 -> V_9 -> V_17 , V_248 -> V_131 + 1 ,
V_298 , V_298 ) ;
F_86 ( 32 ) ;
}
if ( V_248 -> V_299 >= 0 && V_248 -> V_300 &&
V_248 -> V_299 != V_248 -> V_301 ) {
F_81 ( V_248 , & V_264 , V_248 -> V_300 , false ) ;
F_83 ( V_9 , V_248 -> V_131 , & V_264 , V_248 -> V_299 ,
false ) ;
if ( V_248 -> V_301 >= 0 ) {
F_81 ( V_248 , & V_264 , V_248 -> V_302 , true ) ;
F_83 ( V_9 , V_248 -> V_131 + 0x10 , & V_264 ,
V_248 -> V_301 , true ) ;
V_296 = true ;
}
} else if ( V_248 -> V_301 >= 0 ) {
F_81 ( V_248 , & V_264 , V_248 -> V_302 , false ) ;
F_83 ( V_9 , V_248 -> V_131 , & V_264 ,
V_248 -> V_301 , false ) ;
F_6 ( V_9 -> V_17 , V_248 -> V_131 + 0x11 ,
V_303 , 0 ) ;
} else {
F_76 ( V_248 , L_56 ) ;
return - V_77 ;
}
if ( V_296 && V_248 -> V_302 > 100000 )
F_6 ( V_9 -> V_17 , V_248 -> V_131 + 0x17 ,
V_304 , 0 ) ;
else
F_6 ( V_9 -> V_17 , V_248 -> V_131 + 0x17 ,
V_304 ,
V_304 ) ;
if ( ! V_297 )
F_87 ( V_9 -> V_10 ) ;
F_6 ( V_9 -> V_17 , V_248 -> V_131 + 1 ,
V_295 , V_295 ) ;
if ( V_296 )
F_6 ( V_9 -> V_17 , V_248 -> V_131 + 0x11 ,
V_303 ,
V_303 ) ;
if ( V_297 )
F_6 ( V_9 -> V_17 , V_248 -> V_131 + 1 ,
V_298 , 0 ) ;
F_79 ( V_248 , L_57 ) ;
V_12 = 0 ;
for ( V_38 = 0 ; V_38 < 15 ; V_38 ++ ) {
if ( V_38 < 5 )
F_88 ( 200 , 400 ) ;
else
F_32 ( 20 ) ;
F_8 ( V_9 -> V_17 ,
V_305 ,
& V_12 ) ;
if ( V_12 & ( V_306 << ( V_248 -> V_167 - 1 ) ) )
break;
}
if ( V_38 == 15 )
F_80 ( V_248 , L_58 ) ;
else
F_79 ( V_248 , L_59 , V_38 ) ;
return 0 ;
}
static void F_89 ( struct V_247 * V_248 )
{
struct V_9 * V_9 = V_248 -> V_9 ;
bool V_307 ;
F_6 ( V_9 -> V_17 , V_248 -> V_131 + 1 ,
V_298 , V_298 ) ;
F_90 ( V_9 -> V_17 , V_248 -> V_131 + 1 ,
V_295 , 0 , & V_307 ) ;
F_11 ( V_9 -> V_17 , V_248 -> V_131 + 0x11 ,
V_303 , 0 ) ;
F_6 ( V_9 -> V_17 , V_248 -> V_131 + 1 ,
V_298 , 0 ) ;
if ( V_307 )
F_91 ( V_9 -> V_10 ) ;
}
int F_92 ( struct V_247 * V_248 , int V_107 ,
unsigned int V_249 , unsigned int V_250 )
{
int V_23 = 0 ;
if ( V_248 -> V_299 == V_107 && V_248 -> V_300 == V_249 )
return 0 ;
if ( V_248 -> V_252 && V_249 > 0 ) {
V_23 = F_75 ( V_248 , V_249 , V_248 -> V_252 ) ;
if ( V_23 != 0 )
return V_23 ;
}
V_248 -> V_299 = V_107 ;
V_248 -> V_300 = V_249 ;
if ( V_248 -> V_252 && V_249 > 0 ) {
V_23 = F_85 ( V_248 ) ;
}
return V_23 ;
}
int F_93 ( struct V_247 * V_248 , int V_107 ,
unsigned int V_249 , unsigned int V_250 )
{
int V_23 = 0 ;
if ( V_248 -> V_301 == V_107 &&
V_248 -> V_302 == V_249 && V_248 -> V_252 == V_250 )
return 0 ;
if ( V_250 ) {
if ( V_248 -> V_299 >= 0 ) {
V_23 = F_75 ( V_248 , V_248 -> V_300 , V_250 ) ;
if ( V_23 != 0 )
return V_23 ;
}
V_23 = F_75 ( V_248 , V_249 , V_250 ) ;
if ( V_23 != 0 )
return V_23 ;
}
V_248 -> V_301 = V_107 ;
V_248 -> V_302 = V_249 ;
V_248 -> V_252 = V_250 ;
if ( V_250 )
V_23 = F_85 ( V_248 ) ;
else
F_89 ( V_248 ) ;
return V_23 ;
}
int F_94 ( struct V_9 * V_9 , int V_167 , int V_131 , int V_308 ,
int V_309 , struct V_247 * V_248 )
{
unsigned int V_12 ;
V_248 -> V_167 = V_167 ;
V_248 -> V_131 = V_131 ;
V_248 -> V_9 = V_9 ;
V_248 -> V_301 = V_310 ;
F_8 ( V_9 -> V_17 , V_311 , & V_12 ) ;
switch ( V_12 & V_312 ) {
case V_313 :
case V_314 :
V_248 -> V_299 = V_12 & V_312 ;
break;
default:
V_248 -> V_299 = V_310 ;
}
V_248 -> V_300 = 32768 ;
snprintf ( V_248 -> V_315 , sizeof( V_248 -> V_315 ) , L_60 , V_167 ) ;
snprintf ( V_248 -> V_316 , sizeof( V_248 -> V_316 ) ,
L_61 , V_167 ) ;
F_11 ( V_9 -> V_17 , V_248 -> V_131 + 1 ,
V_298 , 0 ) ;
return 0 ;
}
int F_95 ( struct V_6 * V_7 , int V_317 , bool V_318 )
{
unsigned int V_57 , V_12 ;
if ( V_317 < 1 || V_317 > 6 )
return - V_77 ;
V_57 = V_319 + ( V_317 - 1 ) * 8 ;
if ( V_318 )
V_12 = V_320 ;
else
V_12 = 0 ;
return F_29 ( V_7 , V_57 , V_320 , V_12 ) ;
}
static bool F_96 ( bool V_130 , T_2 V_321 , T_2 V_322 )
{
T_3 V_323 = F_97 ( V_321 ) ;
T_3 V_324 = F_97 ( V_322 ) ;
if ( ! V_130 ) {
return abs ( V_323 ) >= 4096 ;
} else {
if ( abs ( V_324 ) >= 4096 )
return true ;
return ( abs ( ( V_323 << 16 ) / ( 4096 - V_324 ) ) >= 4096 << 4 ) ;
}
}
int F_98 ( struct V_3 * V_4 ,
struct V_325 * V_326 )
{
struct V_6 * V_7 = F_99 ( V_4 ) ;
struct V_9 * V_9 = F_3 ( V_7 -> V_10 -> V_11 ) ;
struct V_327 * V_185 = ( void * ) V_4 -> V_328 ;
unsigned int V_12 ;
T_2 * V_22 ;
int V_329 ;
int V_23 ;
V_329 = V_185 -> V_330 * F_100 ( V_9 -> V_17 ) ;
V_22 = F_101 ( V_326 -> V_331 . V_332 . V_22 , V_329 , V_333 | V_334 ) ;
if ( ! V_22 )
return - V_335 ;
V_22 [ 0 ] &= F_102 ( V_336 ) ;
if ( F_96 ( ! ! V_22 [ 0 ] , V_22 [ 1 ] , V_22 [ 2 ] ) ||
F_96 ( true , V_22 [ 4 ] , V_22 [ 5 ] ) ||
F_96 ( true , V_22 [ 8 ] , V_22 [ 9 ] ) ||
F_96 ( true , V_22 [ 12 ] , V_22 [ 13 ] ) ||
F_96 ( false , V_22 [ 16 ] , V_22 [ 17 ] ) ) {
F_9 ( V_9 -> V_10 , L_62 ) ;
V_23 = - V_77 ;
goto V_337;
}
V_23 = F_8 ( V_9 -> V_17 , V_185 -> V_131 , & V_12 ) ;
if ( V_23 != 0 )
goto V_337;
V_12 &= ~ V_336 ;
V_22 [ 0 ] |= F_102 ( V_12 ) ;
V_23 = F_103 ( V_9 -> V_17 , V_185 -> V_131 , V_22 , V_329 ) ;
V_337:
F_104 ( V_22 ) ;
return V_23 ;
}
int F_105 ( struct V_3 * V_4 ,
struct V_325 * V_326 )
{
struct V_6 * V_7 = F_99 ( V_4 ) ;
struct V_9 * V_9 = F_3 ( V_7 -> V_10 -> V_11 ) ;
T_2 * V_22 = ( T_2 * ) V_326 -> V_331 . V_332 . V_22 ;
T_3 V_12 = F_97 ( * V_22 ) ;
if ( abs ( V_12 ) >= 4096 ) {
F_9 ( V_9 -> V_10 , L_63 ) ;
return - V_77 ;
}
return F_106 ( V_4 , V_326 ) ;
}
int F_107 ( struct V_6 * V_7 ,
struct V_338 * V_339 ,
int (* F_108)( struct V_338 * V_339 ,
unsigned long V_340 , void * V_22 ) )
{
struct V_29 * V_30 = F_14 ( V_7 ) ;
struct V_9 * V_9 = V_30 -> V_9 ;
V_339 -> V_341 = F_108 ;
return F_109 ( & V_9 -> V_49 , V_339 ) ;
}
int F_110 ( struct V_6 * V_7 ,
struct V_338 * V_339 )
{
struct V_29 * V_30 = F_14 ( V_7 ) ;
struct V_9 * V_9 = V_30 -> V_9 ;
return F_111 ( & V_9 -> V_49 , V_339 ) ;
}
