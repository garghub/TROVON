int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
int V_5 )
{
return 0 ;
}
int F_2 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
int V_5 )
{
return 0 ;
}
static int F_3 ( struct V_6 * V_7 , unsigned int V_8 ,
unsigned int V_9 )
{
struct V_10 * V_11 = F_4 ( V_7 ) ;
unsigned int V_12 ;
unsigned int * V_13 ;
int V_14 , div , V_15 ;
switch ( V_8 ) {
case V_16 :
V_12 = V_17 ;
V_15 = V_11 -> V_18 ;
break;
case V_19 :
V_12 = V_20 ;
V_15 = V_11 -> V_21 ;
break;
default:
return - V_22 ;
}
if ( V_15 % 8000 )
V_13 = V_23 ;
else
V_13 = V_24 ;
for ( V_14 = 0 ; V_14 < F_5 ( V_24 ) &&
V_13 [ V_14 ] <= V_15 ; V_14 ++ ) {
div = 1 ;
while ( V_13 [ V_14 ] / div >= V_9 && div < 32 ) {
if ( V_13 [ V_14 ] / div == V_9 ) {
F_6 ( V_7 -> V_25 , L_1 ,
V_9 ) ;
F_7 ( V_7 , V_12 ,
V_26 |
V_27 ,
( div <<
V_28 ) |
V_14 ) ;
return 0 ;
}
div ++ ;
}
}
F_8 ( V_7 -> V_25 , L_2 , V_9 ) ;
return - V_22 ;
}
int F_9 ( struct V_6 * V_7 , int V_29 ,
int V_30 , unsigned int V_9 , int V_31 )
{
struct V_10 * V_11 = F_4 ( V_7 ) ;
struct V_32 * V_32 = V_11 -> V_32 ;
char * V_33 ;
unsigned int V_12 ;
unsigned int V_34 = V_35 | V_36 ;
unsigned int V_37 = V_30 << V_38 ;
unsigned int * V_8 ;
switch ( V_29 ) {
case V_39 :
V_33 = L_3 ;
V_12 = V_40 ;
V_8 = & V_11 -> V_18 ;
V_34 |= V_41 ;
break;
case V_42 :
V_33 = L_4 ;
V_12 = V_43 ;
V_8 = & V_11 -> V_21 ;
break;
case V_16 :
case V_19 :
return F_3 ( V_7 , V_29 , V_9 ) ;
default:
return - V_22 ;
}
switch ( V_9 ) {
case 5644800 :
case 6144000 :
break;
case 11289600 :
case 12288000 :
V_37 |= 1 << V_44 ;
break;
case 22579200 :
case 24576000 :
V_37 |= 2 << V_44 ;
break;
case 45158400 :
case 49152000 :
V_37 |= 3 << V_44 ;
break;
case 67737600 :
case 73728000 :
V_37 |= 4 << V_44 ;
break;
case 90316800 :
case 98304000 :
V_37 |= 5 << V_44 ;
break;
case 135475200 :
case 147456000 :
V_37 |= 6 << V_44 ;
break;
default:
return - V_22 ;
}
* V_8 = V_9 ;
if ( V_9 % 6144000 )
V_37 |= V_41 ;
F_6 ( V_32 -> V_25 , L_5 , V_33 , V_9 ) ;
return F_10 ( V_32 -> V_45 , V_12 , V_34 , V_37 ) ;
}
static int F_11 ( struct V_46 * V_47 , unsigned int V_48 )
{
struct V_6 * V_7 = V_47 -> V_7 ;
int V_49 , V_50 , V_51 , V_52 ;
V_52 = V_47 -> V_53 -> V_52 ;
V_49 = 0 ;
V_50 = 0 ;
switch ( V_48 & V_54 ) {
case V_55 :
V_51 = 0 ;
break;
case V_56 :
V_51 = 2 ;
break;
default:
F_12 ( V_47 , L_6 ,
V_48 & V_54 ) ;
return - V_22 ;
}
switch ( V_48 & V_57 ) {
case V_58 :
break;
case V_59 :
V_49 |= V_60 ;
break;
case V_61 :
V_50 |= V_62 ;
break;
case V_63 :
V_50 |= V_62 ;
V_49 |= V_60 ;
break;
default:
F_12 ( V_47 , L_7 ,
V_48 & V_57 ) ;
return - V_22 ;
}
switch ( V_48 & V_64 ) {
case V_65 :
break;
case V_66 :
V_50 |= V_67 ;
V_49 |= V_68 ;
break;
case V_69 :
V_50 |= V_67 ;
break;
case V_70 :
V_49 |= V_68 ;
break;
default:
return - V_22 ;
}
F_7 ( V_7 , V_52 + V_71 ,
V_67 | V_62 ,
V_50 ) ;
F_7 ( V_7 , V_52 + V_72 ,
V_68 |
V_60 , V_49 ) ;
F_7 ( V_7 , V_52 + V_73 ,
V_74 |
V_75 , V_49 ) ;
F_7 ( V_7 , V_52 + V_76 ,
V_77 , V_51 ) ;
return 0 ;
}
static int F_13 ( struct V_78 * V_79 ,
struct V_46 * V_47 )
{
struct V_6 * V_7 = V_47 -> V_7 ;
struct V_10 * V_11 = F_4 ( V_7 ) ;
struct V_80 * V_81 = & V_11 -> V_47 [ V_47 -> V_82 - 1 ] ;
const struct V_83 * V_84 ;
unsigned int V_85 ;
switch ( V_81 -> V_8 ) {
case V_39 :
V_85 = V_11 -> V_18 ;
break;
case V_42 :
V_85 = V_11 -> V_21 ;
break;
default:
return 0 ;
}
if ( V_85 % 8000 )
V_84 = & V_86 ;
else
V_84 = & V_87 ;
return V_83 ( V_79 -> V_88 , 0 ,
V_89 ,
V_84 ) ;
}
static int F_14 ( struct V_78 * V_79 ,
struct V_90 * V_91 ,
struct V_46 * V_47 )
{
struct V_6 * V_7 = V_47 -> V_7 ;
struct V_10 * V_11 = F_4 ( V_7 ) ;
struct V_80 * V_81 = & V_11 -> V_47 [ V_47 -> V_82 - 1 ] ;
int V_52 = V_47 -> V_53 -> V_52 ;
const int * V_13 ;
int V_92 ;
int V_50 , V_49 , V_93 , V_94 , V_95 ;
if ( F_15 ( V_91 ) % 8000 )
V_13 = & V_96 [ 0 ] ;
else
V_13 = & V_97 [ 0 ] ;
for ( V_92 = 0 ; V_92 < F_5 ( V_96 ) ; V_92 ++ ) {
if ( V_13 [ V_92 ] >= F_16 ( V_91 ) &&
V_13 [ V_92 ] % F_15 ( V_91 ) == 0 ) {
V_50 = V_92 ;
break;
}
}
if ( V_92 == F_5 ( V_96 ) ) {
F_12 ( V_47 , L_8 ,
F_15 ( V_91 ) ) ;
return - V_22 ;
}
for ( V_92 = 0 ; V_92 < F_5 ( V_98 ) ; V_92 ++ )
if ( V_98 [ V_92 ] == F_15 ( V_91 ) )
break;
if ( V_92 == F_5 ( V_98 ) ) {
F_12 ( V_47 , L_8 ,
F_15 ( V_91 ) ) ;
return - V_22 ;
}
V_95 = V_92 ;
V_49 = V_13 [ V_50 ] / F_15 ( V_91 ) ;
F_17 ( V_47 , L_9 ,
V_13 [ V_50 ] , V_13 [ V_50 ] / V_49 ) ;
V_93 = F_18 ( F_19 ( V_91 ) ) ;
V_94 = V_93 << V_99 | V_93 ;
switch ( V_81 -> V_8 ) {
case V_39 :
F_7 ( V_7 , V_100 ,
V_101 , V_95 ) ;
F_7 ( V_7 , V_52 + V_102 ,
V_103 , 0 ) ;
break;
case V_42 :
F_7 ( V_7 , V_104 ,
V_105 , V_95 ) ;
F_7 ( V_7 , V_52 + V_102 ,
V_103 ,
8 << V_106 ) ;
break;
default:
F_12 ( V_47 , L_10 , V_81 -> V_8 ) ;
return - V_22 ;
}
F_7 ( V_7 , V_52 + V_71 ,
V_107 , V_50 ) ;
F_7 ( V_7 , V_52 + V_108 ,
V_109 , V_49 ) ;
F_7 ( V_7 , V_52 + V_110 ,
V_111 , V_49 ) ;
F_7 ( V_7 , V_52 + V_112 ,
V_113 |
V_114 , V_94 ) ;
F_7 ( V_7 , V_52 + V_115 ,
V_116 |
V_117 , V_94 ) ;
return 0 ;
}
static const char * F_20 ( int V_29 )
{
switch ( V_29 ) {
case V_39 :
return L_3 ;
case V_42 :
return L_4 ;
default:
return L_11 ;
}
}
static int F_21 ( struct V_46 * V_47 ,
int V_29 , unsigned int V_9 , int V_31 )
{
struct V_6 * V_7 = V_47 -> V_7 ;
struct V_10 * V_11 = F_4 ( V_7 ) ;
struct V_80 * V_81 = & V_11 -> V_47 [ V_47 -> V_82 - 1 ] ;
struct V_118 V_119 [ 2 ] ;
switch ( V_29 ) {
case V_39 :
case V_42 :
break;
default:
return - V_22 ;
}
if ( V_29 == V_81 -> V_8 )
return 0 ;
if ( V_47 -> V_120 ) {
F_8 ( V_7 -> V_25 , L_12 ,
V_47 -> V_82 ) ;
return - V_121 ;
}
F_6 ( V_7 -> V_25 , L_13 , V_47 -> V_82 + 1 ,
F_20 ( V_29 ) ) ;
memset ( & V_119 , 0 , sizeof( V_119 ) ) ;
V_119 [ 0 ] . V_122 = V_47 -> V_53 -> V_123 . V_124 ;
V_119 [ 1 ] . V_122 = V_47 -> V_53 -> V_125 . V_124 ;
V_119 [ 0 ] . V_30 = F_20 ( V_81 -> V_8 ) ;
V_119 [ 1 ] . V_30 = F_20 ( V_81 -> V_8 ) ;
F_22 ( & V_7 -> V_126 , V_119 , F_5 ( V_119 ) ) ;
V_119 [ 0 ] . V_30 = F_20 ( V_29 ) ;
V_119 [ 1 ] . V_30 = F_20 ( V_29 ) ;
F_23 ( & V_7 -> V_126 , V_119 , F_5 ( V_119 ) ) ;
V_81 -> V_8 = V_29 ;
return F_24 ( & V_7 -> V_126 ) ;
}
int F_25 ( struct V_10 * V_11 , int V_82 )
{
struct V_80 * V_81 = & V_11 -> V_47 [ V_82 ] ;
V_81 -> V_8 = V_39 ;
return 0 ;
}
static T_1 F_26 ( int V_127 , void * V_128 )
{
struct V_129 * V_130 = V_128 ;
F_27 ( V_130 , L_14 ) ;
F_28 ( & V_130 -> V_131 ) ;
return V_132 ;
}
static T_1 F_29 ( int V_127 , void * V_128 )
{
struct V_129 * V_130 = V_128 ;
F_27 ( V_130 , L_15 ) ;
F_28 ( & V_130 -> V_133 ) ;
return V_132 ;
}
static int F_30 ( struct V_129 * V_130 ,
struct V_134 * V_135 ,
unsigned int V_136 ,
unsigned int V_137 )
{
unsigned int V_138 , div , V_139 ;
int V_92 , V_140 ;
F_27 ( V_130 , L_16 , V_136 , V_137 ) ;
div = 1 ;
V_135 -> V_141 = 0 ;
while ( ( V_136 / div ) > 13500000 ) {
div *= 2 ;
V_135 -> V_141 ++ ;
if ( div > 8 ) {
F_31 ( V_130 ,
L_17 ,
V_136 ) ;
return - V_22 ;
}
}
V_136 /= div ;
div = 1 ;
while ( V_137 * div < 90000000 * V_130 -> V_142 ) {
div ++ ;
if ( div > 7 ) {
F_31 ( V_130 , L_18 ,
V_137 ) ;
return - V_22 ;
}
}
V_138 = V_137 * div / V_130 -> V_142 ;
V_135 -> V_143 = div ;
F_27 ( V_130 , L_19 , V_138 ) ;
for ( V_92 = 0 ; V_92 < F_5 ( V_144 ) ; V_92 ++ ) {
if ( V_144 [ V_92 ] . V_145 <= V_136 && V_136 <= V_144 [ V_92 ] . V_146 ) {
V_135 -> V_147 = V_144 [ V_92 ] . V_147 ;
V_140 = V_144 [ V_92 ] . V_140 ;
break;
}
}
if ( V_92 == F_5 ( V_144 ) ) {
F_31 ( V_130 , L_20 ,
V_136 ) ;
return - V_22 ;
}
V_135 -> V_148 = V_138 / ( V_140 * V_136 ) ;
if ( V_138 % V_136 ) {
V_139 = F_32 ( V_138 , V_140 * V_136 ) ;
F_27 ( V_130 , L_21 , V_139 ) ;
V_135 -> V_149 = ( V_138 - ( V_135 -> V_148 * V_140 * V_136 ) )
/ V_139 ;
V_135 -> V_150 = ( V_140 * V_136 ) / V_139 ;
} else {
V_135 -> V_149 = 0 ;
V_135 -> V_150 = 0 ;
}
F_27 ( V_130 , L_22 ,
V_135 -> V_148 , V_135 -> V_149 , V_135 -> V_150 ) ;
F_27 ( V_130 , L_23 ,
V_135 -> V_147 , V_135 -> V_147 , V_135 -> V_143 , V_135 -> V_141 ) ;
return 0 ;
}
static void F_33 ( struct V_32 * V_32 , unsigned int V_52 ,
struct V_134 * V_135 , int V_30 )
{
F_10 ( V_32 -> V_45 , V_52 + 3 ,
V_151 , V_135 -> V_149 ) ;
F_10 ( V_32 -> V_45 , V_52 + 4 ,
V_152 , V_135 -> V_150 ) ;
F_10 ( V_32 -> V_45 , V_52 + 5 ,
V_153 ,
V_135 -> V_147 << V_154 ) ;
F_10 ( V_32 -> V_45 , V_52 + 6 ,
V_155 |
V_156 ,
V_135 -> V_141 << V_157 |
V_30 << V_158 ) ;
F_10 ( V_32 -> V_45 , V_52 + 2 ,
V_159 | V_160 ,
V_159 | V_135 -> V_148 ) ;
}
int F_34 ( struct V_129 * V_130 , int V_30 ,
unsigned int V_136 , unsigned int V_137 )
{
struct V_32 * V_32 = V_130 -> V_32 ;
struct V_134 V_135 , V_161 ;
unsigned int V_12 , V_37 ;
int V_162 ;
bool V_163 ;
int V_164 ;
if ( V_130 -> V_165 == V_136 && V_130 -> V_166 == V_137 )
return 0 ;
V_164 = F_35 ( V_32 -> V_45 , V_130 -> V_52 + 1 , & V_12 ) ;
if ( V_164 != 0 ) {
F_31 ( V_130 , L_24 ,
V_164 ) ;
return V_164 ;
}
V_163 = V_12 & V_167 ;
if ( V_137 ) {
F_35 ( V_32 -> V_45 , V_168 , & V_37 ) ;
switch ( V_37 & V_169 ) {
case V_170 :
case V_171 :
V_162 = V_37 & V_169 ;
break;
default:
V_162 = - 1 ;
}
if ( V_30 == V_162 )
V_162 = - 1 ;
if ( V_162 >= 0 ) {
V_164 = F_30 ( V_130 , & V_161 , V_136 , V_137 ) ;
if ( V_164 != 0 )
return V_164 ;
V_164 = F_30 ( V_130 , & V_135 , 32768 , V_137 ) ;
if ( V_164 != 0 )
return V_164 ;
} else {
V_164 = F_30 ( V_130 , & V_135 , V_136 , V_137 ) ;
if ( V_164 != 0 )
return V_164 ;
}
} else {
F_10 ( V_32 -> V_45 , V_130 -> V_52 + 1 ,
V_167 , 0 ) ;
F_10 ( V_32 -> V_45 , V_130 -> V_52 + 0x11 ,
V_172 , 0 ) ;
if ( V_163 )
F_36 ( V_32 -> V_25 ) ;
V_130 -> V_165 = V_136 ;
V_130 -> V_166 = V_137 ;
return 0 ;
}
F_10 ( V_32 -> V_45 , V_130 -> V_52 + 5 ,
V_173 ,
V_135 . V_143 << V_174 ) ;
if ( V_162 >= 0 ) {
F_33 ( V_32 , V_130 -> V_52 , & V_135 , V_162 ) ;
F_33 ( V_32 , V_130 -> V_52 + 0x10 , & V_161 , V_30 ) ;
} else {
F_33 ( V_32 , V_130 -> V_52 , & V_135 , V_30 ) ;
}
if ( ! V_163 )
F_37 ( V_32 -> V_25 ) ;
F_38 ( & V_130 -> V_133 ) ;
F_10 ( V_32 -> V_45 , V_130 -> V_52 + 1 ,
V_167 , V_167 ) ;
if ( V_162 >= 0 )
F_10 ( V_32 -> V_45 , V_130 -> V_52 + 0x11 ,
V_172 ,
V_172 ) ;
V_164 = F_39 ( & V_130 -> V_133 ,
F_40 ( 250 ) ) ;
if ( V_164 == 0 )
F_41 ( V_130 , L_25 ) ;
V_130 -> V_165 = V_136 ;
V_130 -> V_166 = V_137 ;
return 0 ;
}
int F_42 ( struct V_32 * V_32 , int V_82 , int V_52 , int V_175 ,
int V_176 , struct V_129 * V_130 )
{
int V_164 ;
F_43 ( & V_130 -> V_131 ) ;
F_43 ( & V_130 -> V_133 ) ;
V_130 -> V_82 = V_82 ;
V_130 -> V_52 = V_52 ;
V_130 -> V_32 = V_32 ;
snprintf ( V_130 -> V_177 , sizeof( V_130 -> V_177 ) , L_26 , V_82 ) ;
snprintf ( V_130 -> V_178 , sizeof( V_130 -> V_178 ) ,
L_27 , V_82 ) ;
V_164 = F_44 ( V_32 , V_175 , V_130 -> V_177 ,
F_26 , V_130 ) ;
if ( V_164 != 0 ) {
F_8 ( V_32 -> V_25 , L_28 ,
V_82 , V_164 ) ;
}
V_164 = F_44 ( V_32 , V_176 , V_130 -> V_178 ,
F_29 , V_130 ) ;
if ( V_164 != 0 ) {
F_8 ( V_32 -> V_25 , L_29 ,
V_82 , V_164 ) ;
}
F_10 ( V_32 -> V_45 , V_130 -> V_52 + 1 ,
V_179 , 0 ) ;
return 0 ;
}
