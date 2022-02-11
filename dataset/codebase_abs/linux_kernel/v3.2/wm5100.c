static int F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_6 , V_7 , V_8 ;
for ( V_8 = 0 ; V_8 < F_3 ( V_9 ) ; V_8 ++ )
if ( V_9 [ V_8 ] == V_3 )
break;
if ( V_8 == F_3 ( V_9 ) ) {
F_4 ( V_2 -> V_10 , L_1 , V_3 ) ;
return - V_11 ;
}
V_6 = V_8 ;
if ( ( V_5 -> V_12 % V_3 ) == 0 ) {
V_7 = - 1 ;
for ( V_8 = 0 ; V_8 < F_3 ( V_13 ) ; V_8 ++ ) {
if ( ! V_5 -> V_14 [ V_8 ] && V_7 == - 1 ) {
V_7 = V_8 ;
continue;
}
if ( ( F_5 ( V_2 , V_13 [ V_8 ] ) &
V_15 ) == V_6 )
break;
}
if ( V_8 < F_3 ( V_13 ) ) {
V_5 -> V_14 [ V_8 ] ++ ;
F_6 ( V_2 -> V_10 , L_2 ,
V_3 , V_8 , V_5 -> V_14 [ V_8 ] ) ;
return V_8 ;
}
if ( V_7 == - 1 ) {
F_4 ( V_2 -> V_10 , L_3 ) ;
return - V_16 ;
}
F_6 ( V_2 -> V_10 , L_4 ,
V_7 , V_3 ) ;
V_5 -> V_14 [ V_7 ] ++ ;
F_7 ( V_2 , V_13 [ V_7 ] ,
V_15 ,
V_6 ) ;
return V_7 ;
} else {
F_4 ( V_2 -> V_10 ,
L_5 ,
V_3 , V_5 -> V_12 , V_5 -> V_17 ) ;
return - V_11 ;
}
}
static void F_8 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_8 , V_6 ;
for ( V_8 = 0 ; V_8 < F_3 ( V_9 ) ; V_8 ++ )
if ( V_9 [ V_8 ] == V_3 )
break;
if ( V_8 == F_3 ( V_9 ) ) {
F_4 ( V_2 -> V_10 , L_1 , V_3 ) ;
return;
}
V_6 = V_9 [ V_8 ] ;
for ( V_8 = 0 ; V_8 < F_3 ( V_13 ) ; V_8 ++ ) {
if ( ! V_5 -> V_14 [ V_8 ] )
continue;
if ( ( F_5 ( V_2 , V_13 [ V_8 ] ) &
V_15 ) == V_6 )
break;
}
if ( V_8 < F_3 ( V_13 ) ) {
V_5 -> V_14 [ V_8 ] -- ;
F_6 ( V_2 -> V_10 , L_6 ,
V_3 , V_5 -> V_14 [ V_8 ] ) ;
} else {
F_9 ( V_2 -> V_10 , L_7 ,
V_3 ) ;
}
}
static int F_10 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
if ( V_5 -> V_18 . V_19 ) {
F_11 ( V_5 -> V_18 . V_19 , 0 ) ;
F_11 ( V_5 -> V_18 . V_19 , 1 ) ;
return 0 ;
} else {
return F_12 ( V_2 , V_20 , 0 ) ;
}
}
static void F_13 ( struct V_21 * V_22 ,
enum V_23 V_24 , int V_25 )
{
struct V_1 * V_2 = F_14 ( V_22 ,
struct V_1 , V_22 ) ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
T_1 V_26 , V_27 , V_8 ;
if ( V_5 -> V_28 [ 0 ] ) {
V_27 = F_5 ( V_2 , V_29 ) ;
for ( V_8 = 0 ; V_8 < 200 ; V_8 ++ ) {
V_26 = F_5 ( V_2 , V_30 ) ;
if ( V_26 == V_27 ) {
V_5 -> V_28 [ 0 ] = false ;
break;
}
}
if ( V_8 == 200 ) {
F_4 ( V_2 -> V_10 , L_8 ,
V_27 ) ;
}
}
if ( V_5 -> V_28 [ 1 ] ) {
V_27 = F_5 ( V_2 , V_31 ) ;
for ( V_8 = 0 ; V_8 < 200 ; V_8 ++ ) {
V_26 = F_5 ( V_2 , V_32 ) ;
if ( V_26 == V_27 ) {
V_5 -> V_28 [ 1 ] = false ;
break;
}
}
if ( V_8 == 200 ) {
F_4 ( V_2 -> V_10 , L_9 ,
V_27 ) ;
}
}
}
static int F_15 ( struct V_33 * V_34 ,
struct V_35 * V_36 ,
int V_24 )
{
struct V_4 * V_5 = F_2 ( V_34 -> V_2 ) ;
switch ( V_34 -> V_37 ) {
case V_29 :
V_5 -> V_28 [ 0 ] = true ;
break;
case V_31 :
V_5 -> V_28 [ 0 ] = true ;
break;
default:
break;
}
return 0 ;
}
static int F_16 ( struct V_33 * V_34 ,
struct V_35 * V_36 ,
int V_24 )
{
struct V_1 * V_2 = V_34 -> V_2 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_38 ;
switch ( V_24 ) {
case V_39 :
V_38 = F_17 ( V_5 -> V_40 ) ;
if ( V_38 != 0 ) {
F_4 ( V_2 -> V_10 , L_10 ,
V_38 ) ;
return V_38 ;
}
return V_38 ;
case V_41 :
V_38 = F_18 ( V_5 -> V_40 , 20 ) ;
if ( V_38 != 0 ) {
F_4 ( V_2 -> V_10 , L_11 ,
V_38 ) ;
return V_38 ;
}
return V_38 ;
default:
F_19 () ;
return 0 ;
}
}
static int F_20 ( struct V_33 * V_34 ,
struct V_35 * V_36 ,
int V_24 )
{
struct V_1 * V_2 = V_34 -> V_2 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_42 * V_42 ;
int V_38 ;
switch ( V_34 -> V_43 ) {
case 2 :
V_42 = V_5 -> V_44 ;
break;
case 3 :
V_42 = V_5 -> V_45 ;
break;
default:
F_19 () ;
return 0 ;
}
switch ( V_24 ) {
case V_39 :
V_38 = F_17 ( V_42 ) ;
if ( V_38 != 0 ) {
F_4 ( V_2 -> V_10 , L_12 ,
V_34 -> V_43 , V_38 ) ;
return V_38 ;
}
return V_38 ;
case V_41 :
V_38 = F_21 ( V_42 ) ;
if ( V_38 != 0 ) {
F_4 ( V_2 -> V_10 , L_12 ,
V_34 -> V_43 , V_38 ) ;
return V_38 ;
}
return V_38 ;
default:
F_19 () ;
return 0 ;
}
}
static void F_22 ( struct V_1 * V_2 , int V_26 )
{
if ( V_26 & V_46 )
F_23 ( V_2 -> V_10 , L_13 ) ;
if ( V_26 & V_47 )
F_23 ( V_2 -> V_10 , L_14 ) ;
if ( V_26 & V_48 )
F_23 ( V_2 -> V_10 , L_15 ) ;
if ( V_26 & V_49 )
F_23 ( V_2 -> V_10 , L_16 ) ;
}
static void F_24 ( struct V_1 * V_2 , int V_26 )
{
if ( V_26 & V_50 )
F_4 ( V_2 -> V_10 , L_17 ) ;
if ( V_26 & V_51 )
F_4 ( V_2 -> V_10 , L_18 ) ;
if ( V_26 & V_52 )
F_4 ( V_2 -> V_10 , L_19 ) ;
if ( V_26 & V_53 )
F_4 ( V_2 -> V_10 , L_20 ) ;
if ( V_26 & V_54 )
F_4 ( V_2 -> V_10 , L_21 ) ;
if ( V_26 & V_55 )
F_4 ( V_2 -> V_10 , L_22 ) ;
if ( V_26 & V_56 )
F_4 ( V_2 -> V_10 , L_23 ) ;
if ( V_26 & V_57 )
F_4 ( V_2 -> V_10 , L_24 ) ;
if ( V_26 & V_58 )
F_4 ( V_2 -> V_10 , L_25 ) ;
if ( V_26 & V_59 )
F_4 ( V_2 -> V_10 , L_26 ) ;
if ( V_26 & V_60 )
F_4 ( V_2 -> V_10 , L_27 ) ;
if ( V_26 & V_61 )
F_4 ( V_2 -> V_10 , L_28 ) ;
if ( V_26 & V_62 )
F_4 ( V_2 -> V_10 , L_29 ) ;
if ( V_26 & V_63 )
F_4 ( V_2 -> V_10 , L_30 ) ;
}
static int F_25 ( struct V_33 * V_34 ,
struct V_35 * V_36 ,
int V_24 )
{
struct V_1 * V_2 = V_34 -> V_2 ;
int V_38 ;
V_38 = F_5 ( V_2 , V_64 ) ;
V_38 &= V_65 |
V_66 | V_67 |
V_68 ;
F_22 ( V_2 , V_38 ) ;
V_38 = F_5 ( V_2 , V_69 ) ;
F_24 ( V_2 , V_38 ) ;
return 0 ;
}
static int F_26 ( struct V_1 * V_2 ,
enum V_70 V_71 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_38 , V_8 ;
switch ( V_71 ) {
case V_72 :
break;
case V_73 :
break;
case V_74 :
if ( V_2 -> V_22 . V_75 == V_76 ) {
V_38 = F_27 ( F_3 ( V_5 -> V_77 ) ,
V_5 -> V_77 ) ;
if ( V_38 != 0 ) {
F_4 ( V_2 -> V_10 ,
L_31 ,
V_38 ) ;
return V_38 ;
}
if ( V_5 -> V_18 . V_78 ) {
F_11 ( V_5 -> V_18 . V_78 ,
1 ) ;
F_28 ( 2 ) ;
}
V_2 -> V_79 = false ;
switch ( V_5 -> V_80 ) {
case 0 :
F_12 ( V_2 , 0x11 , 0x3 ) ;
F_12 ( V_2 , 0x203 , 0xc ) ;
F_12 ( V_2 , 0x206 , 0 ) ;
F_12 ( V_2 , 0x207 , 0xf0 ) ;
F_12 ( V_2 , 0x208 , 0x3c ) ;
F_12 ( V_2 , 0x209 , 0 ) ;
F_12 ( V_2 , 0x211 , 0x20d8 ) ;
F_12 ( V_2 , 0x11 , 0 ) ;
for ( V_8 = 0 ;
V_8 < F_3 ( V_81 ) ;
V_8 ++ )
F_12 ( V_2 ,
V_81 [ V_8 ] . V_37 ,
V_81 [ V_8 ] . V_26 ) ;
break;
default:
break;
}
F_29 ( V_2 ) ;
}
break;
case V_76 :
if ( V_5 -> V_18 . V_78 )
F_11 ( V_5 -> V_18 . V_78 , 0 ) ;
F_30 ( F_3 ( V_5 -> V_77 ) ,
V_5 -> V_77 ) ;
break;
}
V_2 -> V_22 . V_75 = V_71 ;
return 0 ;
}
static int F_31 ( struct V_82 * V_83 )
{
switch ( V_83 -> V_84 ) {
case 0 :
return V_85 - 1 ;
case 1 :
return V_86 - 1 ;
case 2 :
return V_87 - 1 ;
default:
F_19 () ;
return - V_11 ;
}
}
static int F_32 ( struct V_82 * V_83 , unsigned int V_88 )
{
struct V_1 * V_2 = V_83 -> V_2 ;
int V_89 , V_90 , V_91 , V_92 ;
V_92 = F_31 ( V_83 ) ;
if ( V_92 < 0 )
return V_92 ;
V_89 = 0 ;
V_90 = 0 ;
switch ( V_88 & V_93 ) {
case V_94 :
V_91 = 0 ;
break;
case V_95 :
V_91 = 1 ;
break;
case V_96 :
V_91 = 2 ;
break;
case V_97 :
V_91 = 3 ;
break;
default:
F_4 ( V_2 -> V_10 , L_32 ,
V_88 & V_93 ) ;
return - V_11 ;
}
switch ( V_88 & V_98 ) {
case V_99 :
break;
case V_100 :
V_89 |= V_101 ;
break;
case V_102 :
V_90 |= V_103 ;
break;
case V_104 :
V_89 |= V_101 ;
V_90 |= V_103 ;
break;
default:
F_4 ( V_2 -> V_10 , L_33 ,
V_88 & V_98 ) ;
return - V_11 ;
}
switch ( V_88 & V_105 ) {
case V_106 :
break;
case V_107 :
V_90 |= V_108 ;
V_89 |= V_109 ;
break;
case V_110 :
V_90 |= V_108 ;
break;
case V_111 :
V_89 |= V_109 ;
break;
default:
return - V_11 ;
}
F_7 ( V_2 , V_92 + 1 , V_103 |
V_108 , V_90 ) ;
F_7 ( V_2 , V_92 + 2 , V_101 |
V_109 , V_89 ) ;
F_7 ( V_2 , V_92 + 3 , V_101 |
V_109 , V_89 ) ;
F_7 ( V_2 , V_92 + 5 , V_112 , V_91 ) ;
return 0 ;
}
static int F_33 ( struct V_113 * V_114 ,
struct V_115 * V_116 ,
struct V_82 * V_83 )
{
struct V_1 * V_2 = V_83 -> V_2 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
bool V_117 = V_5 -> V_118 [ V_83 -> V_84 ] ;
int V_8 , V_92 , V_90 , V_119 , V_89 , V_120 , V_121 , V_122 ;
int * V_123 ;
V_92 = F_31 ( V_83 ) ;
if ( V_92 < 0 )
return V_92 ;
V_120 = F_34 ( F_35 ( V_116 ) ) ;
if ( V_120 < 0 )
return V_120 ;
V_121 = F_36 ( V_116 ) ;
if ( V_121 < 0 )
return V_121 ;
F_6 ( V_2 -> V_10 , L_34 ,
V_120 , V_121 ) ;
V_90 = F_37 ( V_116 ) ;
if ( V_90 < 0 )
return V_90 ;
if ( ! V_117 ) {
V_119 = V_5 -> V_12 ;
V_122 = F_1 ( V_2 , F_38 ( V_116 ) ) ;
if ( V_122 < 0 )
return V_122 ;
} else {
V_119 = V_5 -> V_17 ;
V_122 = 3 ;
for ( V_8 = 0 ; V_8 < F_3 ( V_9 ) ; V_8 ++ )
if ( F_38 ( V_116 ) == V_9 [ V_8 ] )
break;
if ( V_8 == F_3 ( V_9 ) ) {
F_4 ( V_2 -> V_10 , L_35 ,
F_38 ( V_116 ) ) ;
return - V_11 ;
}
F_7 ( V_2 , V_124 ,
V_125 , V_8 ) ;
}
if ( ! V_119 ) {
F_4 ( V_2 -> V_10 , L_36 ,
V_117 ? L_37 : L_38 ) ;
return - V_11 ;
}
F_6 ( V_2 -> V_10 , L_39 ,
V_90 , V_119 , V_117 ? L_37 : L_38 ) ;
if ( V_119 % 4000 )
V_123 = V_126 ;
else
V_123 = V_127 ;
for ( V_8 = 0 ; V_8 < V_128 ; V_8 ++ )
if ( V_123 [ V_8 ] >= V_90 && ( V_123 [ V_8 ] % V_90 == 0 ) )
break;
if ( V_8 == V_128 ) {
F_4 ( V_2 -> V_10 ,
L_40 ,
V_90 , V_119 , V_117 ? L_37 : L_38 ) ;
return - V_11 ;
}
V_90 = V_8 ;
F_6 ( V_2 -> V_10 , L_41 , V_123 [ V_90 ] ) ;
F_7 ( V_2 , V_92 + 1 , V_129 , V_90 ) ;
V_89 = V_123 [ V_90 ] / F_38 ( V_116 ) ;
F_6 ( V_2 -> V_10 , L_42 , V_123 [ V_90 ] / V_89 ) ;
if ( V_114 -> V_130 == V_131 ||
V_5 -> V_132 [ V_83 -> V_84 ] )
F_7 ( V_2 , V_92 + 7 ,
V_133 , V_89 ) ;
else
F_7 ( V_2 , V_92 + 6 ,
V_134 , V_89 ) ;
V_8 = ( V_120 << V_135 ) | V_121 ;
if ( V_114 -> V_130 == V_131 )
F_7 ( V_2 , V_92 + 9 ,
V_136 |
V_137 , V_8 ) ;
else
F_7 ( V_2 , V_92 + 8 ,
V_138 |
V_139 , V_8 ) ;
F_7 ( V_2 , V_92 + 4 , V_140 , V_122 ) ;
return 0 ;
}
static int F_39 ( struct V_1 * V_2 , int V_141 ,
int V_142 , unsigned int V_143 , int V_144 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
int * V_145 ;
int V_146 , V_147 , V_38 , V_37 ;
switch ( V_141 ) {
case V_148 :
V_37 = V_149 ;
V_145 = & V_5 -> V_12 ;
break;
case V_150 :
V_37 = V_151 ;
V_145 = & V_5 -> V_17 ;
break;
case V_152 :
switch ( V_142 ) {
case V_153 :
case V_154 :
case V_155 :
F_7 ( V_2 , V_156 ,
V_157 ,
V_142 ) ;
break;
default:
return - V_11 ;
}
return 0 ;
case V_158 :
case V_159 :
case V_160 :
switch ( V_142 ) {
case V_155 :
V_5 -> V_118 [ V_141 - 1 ] = false ;
break;
case V_161 :
V_5 -> V_118 [ V_141 - 1 ] = true ;
break;
default:
F_4 ( V_2 -> V_10 , L_43 , V_142 ) ;
return - V_11 ;
}
return 0 ;
case V_162 :
switch ( V_143 ) {
case 5644800 :
case 6144000 :
F_7 ( V_2 , V_163 ,
V_164 , 0 ) ;
break;
case 11289600 :
case 12288000 :
F_7 ( V_2 , V_163 ,
V_164 , 0 ) ;
break;
case 22579200 :
case 24576000 :
F_7 ( V_2 , V_163 ,
V_164 , 0 ) ;
break;
default:
F_4 ( V_2 -> V_10 , L_44 ,
V_143 ) ;
return - V_11 ;
}
return 0 ;
default:
F_4 ( V_2 -> V_10 , L_45 , V_141 ) ;
return - V_11 ;
}
switch ( V_142 ) {
case V_155 :
case V_161 :
F_4 ( V_2 -> V_10 , L_43 , V_142 ) ;
return - V_11 ;
}
switch ( V_143 ) {
case 5644800 :
case 6144000 :
V_146 = 0 ;
break;
case 11289600 :
case 12288000 :
V_146 = 1 ;
break;
case 22579200 :
case 24576000 :
V_146 = 2 ;
break;
default:
F_4 ( V_2 -> V_10 , L_46 , V_143 ) ;
return - V_11 ;
}
switch ( V_143 ) {
case 5644800 :
case 11289600 :
case 22579200 :
V_147 = 44100 ;
break;
case 6144000 :
case 12288000 :
case 24576000 :
V_147 = 48000 ;
break;
default:
F_19 () ;
V_147 = 0 ;
break;
}
F_7 ( V_2 , V_37 , V_165 |
V_166 ,
V_146 << V_167 | V_142 ) ;
if ( V_141 == V_148 ) {
F_6 ( V_2 -> V_10 , L_47 ,
V_147 ) ;
if ( 0 && * V_145 )
F_8 ( V_2 , V_147 ) ;
V_38 = F_1 ( V_2 , V_147 ) ;
if ( V_38 != 0 )
F_9 ( V_2 -> V_10 , L_48 ,
V_38 ) ;
}
* V_145 = V_143 ;
return 0 ;
}
static int F_40 ( struct V_168 * V_169 , unsigned int V_170 ,
unsigned int V_171 )
{
unsigned int V_172 ;
unsigned int div ;
unsigned int V_173 , V_174 ;
int V_8 ;
div = 1 ;
V_169 -> V_175 = 0 ;
while ( ( V_170 / div ) > 13500000 ) {
div *= 2 ;
V_169 -> V_175 ++ ;
if ( div > 8 ) {
F_41 ( L_49 ,
V_170 ) ;
return - V_11 ;
}
}
F_42 ( L_50 , V_170 , V_171 ) ;
V_170 /= div ;
div = 2 ;
while ( V_171 * div < 90000000 ) {
div ++ ;
if ( div > 64 ) {
F_41 ( L_51 ,
V_171 ) ;
return - V_11 ;
}
}
V_172 = V_171 * div ;
V_169 -> V_176 = div - 1 ;
F_42 ( L_52 , V_172 ) ;
for ( V_8 = 0 ; V_8 < F_3 ( V_177 ) ; V_8 ++ ) {
if ( V_177 [ V_8 ] . V_178 <= V_170 && V_170 <= V_177 [ V_8 ] . V_179 ) {
V_169 -> V_180 = V_177 [ V_8 ] . V_180 ;
V_173 = V_177 [ V_8 ] . V_181 ;
break;
}
}
if ( V_8 == F_3 ( V_177 ) ) {
F_41 ( L_53 , V_170 ) ;
return - V_11 ;
}
V_169 -> V_182 = V_172 / ( V_173 * V_170 ) ;
if ( V_172 % V_170 == 0 ) {
V_169 -> V_183 = 0 ;
V_169 -> V_184 = 0 ;
} else {
V_174 = F_43 ( V_172 , V_173 * V_170 ) ;
V_169 -> V_183 = ( V_172 - ( V_169 -> V_182 * V_173 * V_170 ) )
/ V_174 ;
V_169 -> V_184 = ( V_173 * V_170 ) / V_174 ;
}
F_42 ( L_54 ,
V_169 -> V_182 , V_169 -> V_183 , V_169 -> V_184 ) ;
F_42 ( L_55 ,
V_169 -> V_180 , V_173 , V_169 -> V_176 ,
V_169 -> V_175 ) ;
return 0 ;
}
static int F_44 ( struct V_1 * V_2 , int V_185 , int V_142 ,
unsigned int V_170 , unsigned int V_171 )
{
struct V_186 * V_187 = F_45 ( V_2 -> V_10 ) ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_168 V_188 ;
struct V_189 * V_190 ;
int V_38 , V_92 , V_191 , V_8 , V_192 ;
switch ( V_185 ) {
case V_193 :
V_190 = & V_5 -> V_190 [ 0 ] ;
V_92 = V_194 - 1 ;
V_191 = V_195 ;
break;
case V_196 :
V_190 = & V_5 -> V_190 [ 1 ] ;
V_92 = V_197 - 1 ;
V_191 = V_198 ;
break;
default:
F_4 ( V_2 -> V_10 , L_56 , V_185 ) ;
return - V_11 ;
}
if ( ! V_171 ) {
F_6 ( V_2 -> V_10 , L_57 , V_185 ) ;
V_190 -> V_199 = 0 ;
F_7 ( V_2 , V_92 + 1 , V_200 , 0 ) ;
return 0 ;
}
switch ( V_142 ) {
case V_201 :
case V_202 :
case V_203 :
case V_204 :
case V_205 :
case V_206 :
case V_207 :
break;
default:
F_4 ( V_2 -> V_10 , L_58 , V_142 ) ;
return - V_11 ;
}
V_38 = F_40 ( & V_188 , V_170 , V_171 ) ;
if ( V_38 < 0 )
return V_38 ;
F_7 ( V_2 , V_92 + 1 , V_200 , 0 ) ;
F_7 ( V_2 , V_92 + 2 ,
V_208 | V_209 ,
( V_188 . V_176 << V_210 ) |
V_188 . V_180 ) ;
F_7 ( V_2 , V_92 + 3 , V_211 ,
V_188 . V_183 ) ;
F_7 ( V_2 , V_92 + 5 , V_212 , V_188 . V_182 ) ;
F_7 ( V_2 , V_92 + 6 ,
V_213 |
V_214 ,
( V_188 . V_175
<< V_215 ) | V_142 ) ;
F_7 ( V_2 , V_92 + 7 , V_216 ,
V_188 . V_184 ) ;
F_46 ( & V_190 -> V_191 ) ;
F_7 ( V_2 , V_92 + 1 , V_200 , V_200 ) ;
if ( V_187 -> V_217 )
V_192 = 2 ;
else
V_192 = 50 ;
for ( V_8 = 0 ; V_8 < V_192 ; V_8 ++ ) {
if ( V_187 -> V_217 ) {
V_38 = F_47 ( & V_190 -> V_191 ,
F_48 ( 25 ) ) ;
if ( V_38 > 0 )
break;
} else {
F_28 ( 1 ) ;
}
V_38 = F_5 ( V_2 ,
V_64 ) ;
if ( V_38 < 0 ) {
F_4 ( V_2 -> V_10 ,
L_59 ,
V_38 ) ;
continue;
}
if ( V_38 & V_191 )
break;
}
if ( V_8 == V_192 ) {
F_4 ( V_2 -> V_10 , L_60 , V_185 ) ;
return - V_218 ;
}
V_190 -> V_219 = V_142 ;
V_190 -> V_220 = V_170 ;
V_190 -> V_199 = V_171 ;
F_6 ( V_2 -> V_10 , L_61 , V_185 ,
V_170 , V_171 ) ;
return 0 ;
}
static void F_49 ( struct V_1 * V_2 , int V_221 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_222 * V_223 = & V_5 -> V_18 . V_224 [ V_221 ] ;
F_50 ( V_221 >= F_3 ( V_5 -> V_18 . V_224 ) ) ;
F_11 ( V_5 -> V_18 . V_225 , V_223 -> V_225 ) ;
F_7 ( V_2 , V_226 ,
V_227 |
V_228 ,
( V_223 -> V_229 << V_230 ) |
V_223 -> V_231 << V_232 ) ;
F_7 ( V_2 , V_233 ,
V_234 ,
V_223 -> V_231 << V_235 ) ;
V_5 -> V_236 = V_221 ;
F_6 ( V_2 -> V_10 , L_62 ,
V_5 -> V_236 ) ;
}
static void F_51 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_26 ;
V_26 = F_5 ( V_2 , V_237 ) ;
F_6 ( V_2 -> V_10 , L_63 , V_26 ) ;
if ( ! ( V_26 & V_238 ) ) {
F_9 ( V_2 -> V_10 , L_64 ) ;
return;
}
if ( ! ( V_26 & V_239 ) ) {
F_6 ( V_2 -> V_10 , L_65 ) ;
V_5 -> V_240 = false ;
V_5 -> V_241 = true ;
F_52 ( V_5 -> V_242 , 0 ,
V_243 | V_244 |
V_245 ) ;
F_7 ( V_2 , V_246 ,
V_247 ,
V_247 ) ;
return;
}
if ( V_26 & 0x400 ) {
if ( V_5 -> V_241 ) {
F_6 ( V_2 -> V_10 , L_66 ) ;
V_5 -> V_240 = true ;
F_52 ( V_5 -> V_242 ,
V_244 ,
V_244 | V_245 ) ;
F_7 ( V_2 , V_246 ,
V_247 ,
5 << V_248 ) ;
} else {
F_6 ( V_2 -> V_10 , L_67 ) ;
F_52 ( V_5 -> V_242 , 0 , V_245 ) ;
}
return;
}
if ( V_5 -> V_241 && ( V_26 & 0x3f8 ) ) {
F_49 ( V_2 , ! V_5 -> V_236 ) ;
return;
}
if ( V_26 & 0x3fc ) {
if ( V_5 -> V_240 ) {
F_6 ( V_2 -> V_10 , L_68 ) ;
F_52 ( V_5 -> V_242 , V_245 ,
V_245 ) ;
} else if ( V_5 -> V_241 ) {
F_6 ( V_2 -> V_10 , L_69 ) ;
F_52 ( V_5 -> V_242 , V_249 ,
V_249 ) ;
F_7 ( V_2 , V_246 ,
V_247 ,
7 << V_248 ) ;
}
}
}
int F_53 ( struct V_1 * V_2 , struct V_250 * V_242 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
if ( V_242 ) {
V_5 -> V_242 = V_242 ;
V_5 -> V_241 = true ;
F_49 ( V_2 , 0 ) ;
F_7 ( V_2 , V_246 ,
V_251 |
V_247 ,
( 7 << V_252 ) |
V_247 ) ;
F_54 ( & V_2 -> V_22 , L_70 ) ;
F_54 ( & V_2 -> V_22 , L_38 ) ;
F_55 ( & V_2 -> V_22 ) ;
F_7 ( V_2 , V_246 ,
V_253 , V_253 ) ;
F_7 ( V_2 , V_254 ,
V_255 , 0 ) ;
} else {
F_7 ( V_2 , V_254 ,
V_256 |
V_255 ,
V_256 |
V_255 ) ;
F_7 ( V_2 , V_246 ,
V_253 , 0 ) ;
V_5 -> V_242 = NULL ;
}
return 0 ;
}
static T_2 F_56 ( int V_217 , void * V_257 )
{
struct V_1 * V_2 = V_257 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
T_2 V_258 = V_259 ;
int V_260 ;
V_260 = F_5 ( V_2 , V_261 ) ;
if ( V_260 < 0 ) {
F_4 ( V_2 -> V_10 , L_71 ,
V_260 ) ;
V_260 = 0 ;
}
V_260 &= ~ F_5 ( V_2 , V_254 ) ;
F_12 ( V_2 , V_261 , V_260 ) ;
if ( V_260 )
V_258 = V_262 ;
F_22 ( V_2 , V_260 ) ;
if ( V_260 & V_263 ) {
F_6 ( V_2 -> V_10 , L_72 ) ;
F_57 ( & V_5 -> V_190 [ 0 ] . V_191 ) ;
}
if ( V_260 & V_264 ) {
F_6 ( V_2 -> V_10 , L_73 ) ;
F_57 ( & V_5 -> V_190 [ 1 ] . V_191 ) ;
}
if ( V_260 & V_265 )
F_51 ( V_2 ) ;
V_260 = F_5 ( V_2 , V_266 ) ;
if ( V_260 < 0 ) {
F_4 ( V_2 -> V_10 , L_74 ,
V_260 ) ;
V_260 = 0 ;
}
V_260 &= ~ F_5 ( V_2 , V_267 ) ;
if ( V_260 )
V_258 = V_262 ;
F_12 ( V_2 , V_266 , V_260 ) ;
F_24 ( V_2 , V_260 ) ;
return V_258 ;
}
static T_2 F_58 ( int V_217 , void * V_257 )
{
T_2 V_38 = V_259 ;
T_2 V_26 ;
do {
V_26 = F_56 ( V_217 , V_257 ) ;
if ( V_26 != V_259 )
V_38 = V_26 ;
} while ( V_26 != V_259 );
return V_38 ;
}
static inline struct V_4 * F_59 ( struct V_268 * V_269 )
{
return F_14 ( V_269 , struct V_4 , V_268 ) ;
}
static void F_60 ( struct V_268 * V_269 , unsigned V_270 , int V_271 )
{
struct V_4 * V_5 = F_59 ( V_269 ) ;
struct V_1 * V_2 = V_5 -> V_2 ;
F_7 ( V_2 , V_272 + V_270 ,
V_273 , ! ! V_271 << V_274 ) ;
}
static int F_61 ( struct V_268 * V_269 ,
unsigned V_270 , int V_271 )
{
struct V_4 * V_5 = F_59 ( V_269 ) ;
struct V_1 * V_2 = V_5 -> V_2 ;
int V_26 , V_38 ;
V_26 = ( 1 << V_275 ) | ( ! ! V_271 << V_274 ) ;
V_38 = F_7 ( V_2 , V_272 + V_270 ,
V_276 | V_277 |
V_273 , V_26 ) ;
if ( V_38 < 0 )
return V_38 ;
else
return 0 ;
}
static int F_62 ( struct V_268 * V_269 , unsigned V_270 )
{
struct V_4 * V_5 = F_59 ( V_269 ) ;
struct V_1 * V_2 = V_5 -> V_2 ;
int V_38 ;
V_38 = F_5 ( V_2 , V_272 + V_270 ) ;
if ( V_38 < 0 )
return V_38 ;
return ( V_38 & V_273 ) != 0 ;
}
static int F_63 ( struct V_268 * V_269 , unsigned V_270 )
{
struct V_4 * V_5 = F_59 ( V_269 ) ;
struct V_1 * V_2 = V_5 -> V_2 ;
return F_7 ( V_2 , V_272 + V_270 ,
V_276 | V_277 ,
( 1 << V_275 ) |
( 1 << V_278 ) ) ;
}
static void F_64 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_38 ;
V_5 -> V_268 = V_279 ;
V_5 -> V_268 . V_280 = 6 ;
V_5 -> V_268 . V_10 = V_2 -> V_10 ;
if ( V_5 -> V_18 . V_281 )
V_5 -> V_268 . V_92 = V_5 -> V_18 . V_281 ;
else
V_5 -> V_268 . V_92 = - 1 ;
V_38 = F_65 ( & V_5 -> V_268 ) ;
if ( V_38 != 0 )
F_4 ( V_2 -> V_10 , L_75 , V_38 ) ;
}
static void F_66 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_38 ;
V_38 = F_67 ( & V_5 -> V_268 ) ;
if ( V_38 != 0 )
F_4 ( V_2 -> V_10 , L_76 , V_38 ) ;
}
static void F_64 ( struct V_1 * V_2 )
{
}
static void F_66 ( struct V_1 * V_2 )
{
}
static int F_68 ( struct V_1 * V_2 )
{
struct V_186 * V_187 = F_45 ( V_2 -> V_10 ) ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_38 , V_8 , V_282 ;
V_5 -> V_2 = V_2 ;
V_38 = F_69 ( V_2 , 16 , 16 , V_283 ) ;
if ( V_38 != 0 ) {
F_4 ( V_2 -> V_10 , L_77 , V_38 ) ;
return V_38 ;
}
for ( V_8 = 0 ; V_8 < F_3 ( V_5 -> V_77 ) ; V_8 ++ )
V_5 -> V_77 [ V_8 ] . V_284 = V_285 [ V_8 ] ;
V_38 = F_70 ( & V_187 -> V_10 , F_3 ( V_5 -> V_77 ) ,
V_5 -> V_77 ) ;
if ( V_38 != 0 ) {
F_4 ( V_2 -> V_10 , L_78 ,
V_38 ) ;
return V_38 ;
}
V_5 -> V_40 = F_71 ( & V_187 -> V_10 , L_79 ) ;
if ( F_72 ( V_5 -> V_40 ) ) {
V_38 = F_73 ( V_5 -> V_40 ) ;
F_4 ( & V_187 -> V_10 , L_80 , V_38 ) ;
goto V_286;
}
V_5 -> V_44 = F_71 ( & V_187 -> V_10 , L_81 ) ;
if ( F_72 ( V_5 -> V_44 ) ) {
V_38 = F_73 ( V_5 -> V_44 ) ;
F_4 ( & V_187 -> V_10 , L_82 , V_38 ) ;
goto V_287;
}
V_5 -> V_45 = F_71 ( & V_187 -> V_10 , L_83 ) ;
if ( F_72 ( V_5 -> V_45 ) ) {
V_38 = F_73 ( V_5 -> V_45 ) ;
F_4 ( & V_187 -> V_10 , L_82 , V_38 ) ;
goto V_288;
}
V_38 = F_27 ( F_3 ( V_5 -> V_77 ) ,
V_5 -> V_77 ) ;
if ( V_38 != 0 ) {
F_4 ( V_2 -> V_10 , L_84 ,
V_38 ) ;
goto V_289;
}
if ( V_5 -> V_18 . V_78 ) {
V_38 = F_74 ( V_5 -> V_18 . V_78 ,
V_290 , L_85 ) ;
if ( V_38 < 0 ) {
F_4 ( & V_187 -> V_10 , L_86 ,
V_5 -> V_18 . V_78 , V_38 ) ;
goto V_291;
}
F_28 ( 2 ) ;
}
if ( V_5 -> V_18 . V_19 ) {
V_38 = F_74 ( V_5 -> V_18 . V_19 ,
V_290 , L_87 ) ;
if ( V_38 < 0 ) {
F_4 ( & V_187 -> V_10 , L_88 ,
V_5 -> V_18 . V_19 , V_38 ) ;
goto V_292;
}
}
V_38 = F_5 ( V_2 , V_20 ) ;
if ( V_38 < 0 ) {
F_4 ( V_2 -> V_10 , L_89 ) ;
goto V_293;
}
switch ( V_38 ) {
case 0x8997 :
case 0x5100 :
break;
default:
F_4 ( V_2 -> V_10 , L_90 , V_38 ) ;
V_38 = - V_11 ;
goto V_293;
}
V_38 = F_5 ( V_2 , V_294 ) ;
if ( V_38 < 0 ) {
F_4 ( V_2 -> V_10 , L_91 ) ;
goto V_293;
}
V_5 -> V_80 = V_38 & V_295 ;
F_75 ( V_2 -> V_10 , L_92 , V_5 -> V_80 + 'A' ) ;
V_38 = F_10 ( V_2 ) ;
if ( V_38 < 0 ) {
F_4 ( V_2 -> V_10 , L_93 ) ;
goto V_293;
}
V_2 -> V_79 = true ;
F_64 ( V_2 ) ;
for ( V_8 = 0 ; V_8 < F_3 ( V_296 ) ; V_8 ++ )
F_7 ( V_2 , V_296 [ V_8 ] , V_297 ,
V_297 ) ;
for ( V_8 = 0 ; V_8 < F_3 ( V_5 -> V_18 . V_298 ) ; V_8 ++ ) {
F_7 ( V_2 , V_299 ,
V_300 |
V_301 ,
( V_5 -> V_18 . V_298 [ V_8 ] <<
V_302 ) |
( V_5 -> V_18 . V_303 [ V_8 ] <<
V_304 ) ) ;
}
for ( V_8 = 0 ; V_8 < F_3 ( V_5 -> V_18 . V_305 ) ; V_8 ++ ) {
if ( ! V_5 -> V_18 . V_305 [ V_8 ] )
continue;
F_12 ( V_2 , V_272 + V_8 ,
V_5 -> V_18 . V_305 [ V_8 ] ) ;
}
F_12 ( V_2 , V_306 , 0 ) ;
F_12 ( V_2 , V_307 , 0 ) ;
if ( V_187 -> V_217 ) {
if ( V_5 -> V_18 . V_282 )
V_282 = V_5 -> V_18 . V_282 ;
else
V_282 = V_308 ;
V_282 |= V_309 ;
if ( V_282 & ( V_310 | V_311 ) )
V_38 = F_76 ( V_187 -> V_217 , NULL ,
F_58 ,
V_282 , L_94 , V_2 ) ;
else
V_38 = F_76 ( V_187 -> V_217 , NULL , F_56 ,
V_282 , L_94 , V_2 ) ;
if ( V_38 != 0 ) {
F_4 ( V_2 -> V_10 , L_95 ,
V_187 -> V_217 , V_38 ) ;
} else {
F_7 ( V_2 ,
V_254 ,
V_312 |
V_313 |
V_314 |
V_315 |
V_316 |
V_317 |
V_48 |
V_49 , 0 ) ;
F_7 ( V_2 ,
V_267 ,
V_50 |
V_51 |
V_52 |
V_53 |
V_54 |
V_55 |
V_56 |
V_57 |
V_58 |
V_59 |
V_60 |
V_61 |
V_62 |
V_63 , 0 ) ;
}
} else {
F_77 ( & V_2 -> V_22 ,
V_318 ,
F_3 ( V_318 ) ) ;
}
if ( V_5 -> V_18 . V_225 ) {
V_38 = F_74 ( V_5 -> V_18 . V_225 ,
V_290 , L_96 ) ;
if ( V_38 < 0 ) {
F_4 ( & V_187 -> V_10 , L_97 ,
V_5 -> V_18 . V_225 , V_38 ) ;
goto V_319;
}
}
if ( V_5 -> V_18 . V_78 )
F_11 ( V_5 -> V_18 . V_78 , 0 ) ;
F_30 ( F_3 ( V_5 -> V_77 ) ,
V_5 -> V_77 ) ;
return 0 ;
V_319:
if ( V_187 -> V_217 )
F_78 ( V_187 -> V_217 , V_2 ) ;
F_66 ( V_2 ) ;
V_293:
if ( V_5 -> V_18 . V_19 ) {
F_11 ( V_5 -> V_18 . V_19 , 1 ) ;
F_79 ( V_5 -> V_18 . V_19 ) ;
}
V_292:
if ( V_5 -> V_18 . V_78 ) {
F_11 ( V_5 -> V_18 . V_78 , 0 ) ;
F_79 ( V_5 -> V_18 . V_78 ) ;
}
V_291:
F_30 ( F_3 ( V_5 -> V_77 ) ,
V_5 -> V_77 ) ;
V_289:
F_80 ( V_5 -> V_45 ) ;
V_288:
F_80 ( V_5 -> V_44 ) ;
V_287:
F_80 ( V_5 -> V_40 ) ;
V_286:
F_81 ( F_3 ( V_5 -> V_77 ) ,
V_5 -> V_77 ) ;
return V_38 ;
}
static int F_82 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_186 * V_187 = F_45 ( V_2 -> V_10 ) ;
F_26 ( V_2 , V_76 ) ;
if ( V_5 -> V_18 . V_225 ) {
F_79 ( V_5 -> V_18 . V_225 ) ;
}
if ( V_187 -> V_217 )
F_78 ( V_187 -> V_217 , V_2 ) ;
F_66 ( V_2 ) ;
if ( V_5 -> V_18 . V_19 ) {
F_11 ( V_5 -> V_18 . V_19 , 1 ) ;
F_79 ( V_5 -> V_18 . V_19 ) ;
}
if ( V_5 -> V_18 . V_78 ) {
F_11 ( V_5 -> V_18 . V_78 , 0 ) ;
F_79 ( V_5 -> V_18 . V_78 ) ;
}
F_80 ( V_5 -> V_45 ) ;
F_80 ( V_5 -> V_44 ) ;
F_80 ( V_5 -> V_40 ) ;
F_81 ( F_3 ( V_5 -> V_77 ) ,
V_5 -> V_77 ) ;
return 0 ;
}
static T_3 int F_83 ( struct V_186 * V_187 ,
const struct V_320 * V_84 )
{
struct V_321 * V_18 = F_84 ( & V_187 -> V_10 ) ;
struct V_4 * V_5 ;
int V_38 , V_8 ;
V_5 = F_85 ( sizeof( struct V_4 ) , V_322 ) ;
if ( V_5 == NULL )
return - V_323 ;
for ( V_8 = 0 ; V_8 < F_3 ( V_5 -> V_190 ) ; V_8 ++ )
F_86 ( & V_5 -> V_190 [ V_8 ] . V_191 ) ;
if ( V_18 )
V_5 -> V_18 = * V_18 ;
F_87 ( V_187 , V_5 ) ;
V_38 = F_88 ( & V_187 -> V_10 ,
& V_324 , V_325 ,
F_3 ( V_325 ) ) ;
if ( V_38 < 0 ) {
F_4 ( & V_187 -> V_10 , L_98 , V_38 ) ;
F_89 ( V_5 ) ;
}
return V_38 ;
}
static T_4 int F_90 ( struct V_186 * V_326 )
{
F_91 ( & V_326 -> V_10 ) ;
F_89 ( F_92 ( V_326 ) ) ;
return 0 ;
}
static int T_5 F_93 ( void )
{
return F_94 ( & V_327 ) ;
}
static void T_6 F_95 ( void )
{
F_96 ( & V_327 ) ;
}
