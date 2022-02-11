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
static int F_10 ( struct V_4 * V_5 )
{
if ( V_5 -> V_18 . V_19 ) {
F_11 ( V_5 -> V_18 . V_19 , 0 ) ;
F_11 ( V_5 -> V_18 . V_19 , 1 ) ;
return 0 ;
} else {
return F_12 ( V_5 -> V_20 , V_21 , 0 ) ;
}
}
static void F_13 ( struct V_22 * V_23 ,
enum V_24 V_25 , int V_26 )
{
struct V_1 * V_2 = F_14 ( V_23 ,
struct V_1 , V_23 ) ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
T_1 V_27 , V_28 , V_8 ;
if ( V_5 -> V_29 [ 0 ] ) {
V_28 = F_5 ( V_2 , V_30 ) ;
for ( V_8 = 0 ; V_8 < 200 ; V_8 ++ ) {
V_27 = F_5 ( V_2 , V_31 ) ;
if ( V_27 == V_28 ) {
V_5 -> V_29 [ 0 ] = false ;
break;
}
}
if ( V_8 == 200 ) {
F_4 ( V_2 -> V_10 , L_8 ,
V_28 ) ;
}
}
if ( V_5 -> V_29 [ 1 ] ) {
V_28 = F_5 ( V_2 , V_32 ) ;
for ( V_8 = 0 ; V_8 < 200 ; V_8 ++ ) {
V_27 = F_5 ( V_2 , V_33 ) ;
if ( V_27 == V_28 ) {
V_5 -> V_29 [ 1 ] = false ;
break;
}
}
if ( V_8 == 200 ) {
F_4 ( V_2 -> V_10 , L_9 ,
V_28 ) ;
}
}
}
static int F_15 ( struct V_34 * V_35 ,
struct V_36 * V_37 ,
int V_25 )
{
struct V_4 * V_5 = F_2 ( V_35 -> V_2 ) ;
switch ( V_35 -> V_38 ) {
case V_30 :
V_5 -> V_29 [ 0 ] = true ;
break;
case V_32 :
V_5 -> V_29 [ 0 ] = true ;
break;
default:
break;
}
return 0 ;
}
static int F_16 ( struct V_34 * V_35 ,
struct V_36 * V_37 ,
int V_25 )
{
struct V_1 * V_2 = V_35 -> V_2 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_39 ;
switch ( V_25 ) {
case V_40 :
V_39 = F_17 ( V_5 -> V_41 ) ;
if ( V_39 != 0 ) {
F_4 ( V_2 -> V_10 , L_10 ,
V_39 ) ;
return V_39 ;
}
return V_39 ;
case V_42 :
V_39 = F_18 ( V_5 -> V_41 , 20 ) ;
if ( V_39 != 0 ) {
F_4 ( V_2 -> V_10 , L_11 ,
V_39 ) ;
return V_39 ;
}
return V_39 ;
default:
F_19 () ;
return 0 ;
}
}
static int F_20 ( struct V_34 * V_35 ,
struct V_36 * V_37 ,
int V_25 )
{
struct V_1 * V_2 = V_35 -> V_2 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_43 * V_43 ;
int V_39 ;
switch ( V_35 -> V_44 ) {
case 2 :
V_43 = V_5 -> V_45 ;
break;
case 3 :
V_43 = V_5 -> V_46 ;
break;
default:
F_19 () ;
return 0 ;
}
switch ( V_25 ) {
case V_40 :
V_39 = F_17 ( V_43 ) ;
if ( V_39 != 0 ) {
F_4 ( V_2 -> V_10 , L_12 ,
V_35 -> V_44 , V_39 ) ;
return V_39 ;
}
return V_39 ;
case V_42 :
V_39 = F_21 ( V_43 ) ;
if ( V_39 != 0 ) {
F_4 ( V_2 -> V_10 , L_12 ,
V_35 -> V_44 , V_39 ) ;
return V_39 ;
}
return V_39 ;
default:
F_19 () ;
return 0 ;
}
}
static void F_22 ( struct V_1 * V_2 , int V_27 )
{
if ( V_27 & V_47 )
F_23 ( V_2 -> V_10 , L_13 ) ;
if ( V_27 & V_48 )
F_23 ( V_2 -> V_10 , L_14 ) ;
if ( V_27 & V_49 )
F_23 ( V_2 -> V_10 , L_15 ) ;
if ( V_27 & V_50 )
F_23 ( V_2 -> V_10 , L_16 ) ;
}
static void F_24 ( struct V_1 * V_2 , int V_27 )
{
if ( V_27 & V_51 )
F_4 ( V_2 -> V_10 , L_17 ) ;
if ( V_27 & V_52 )
F_4 ( V_2 -> V_10 , L_18 ) ;
if ( V_27 & V_53 )
F_4 ( V_2 -> V_10 , L_19 ) ;
if ( V_27 & V_54 )
F_4 ( V_2 -> V_10 , L_20 ) ;
if ( V_27 & V_55 )
F_4 ( V_2 -> V_10 , L_21 ) ;
if ( V_27 & V_56 )
F_4 ( V_2 -> V_10 , L_22 ) ;
if ( V_27 & V_57 )
F_4 ( V_2 -> V_10 , L_23 ) ;
if ( V_27 & V_58 )
F_4 ( V_2 -> V_10 , L_24 ) ;
if ( V_27 & V_59 )
F_4 ( V_2 -> V_10 , L_25 ) ;
if ( V_27 & V_60 )
F_4 ( V_2 -> V_10 , L_26 ) ;
if ( V_27 & V_61 )
F_4 ( V_2 -> V_10 , L_27 ) ;
if ( V_27 & V_62 )
F_4 ( V_2 -> V_10 , L_28 ) ;
if ( V_27 & V_63 )
F_4 ( V_2 -> V_10 , L_29 ) ;
if ( V_27 & V_64 )
F_4 ( V_2 -> V_10 , L_30 ) ;
}
static int F_25 ( struct V_34 * V_35 ,
struct V_36 * V_37 ,
int V_25 )
{
struct V_1 * V_2 = V_35 -> V_2 ;
int V_39 ;
V_39 = F_5 ( V_2 , V_65 ) ;
V_39 &= V_66 |
V_67 | V_68 |
V_69 ;
F_22 ( V_2 , V_39 ) ;
V_39 = F_5 ( V_2 , V_70 ) ;
F_24 ( V_2 , V_39 ) ;
return 0 ;
}
static int F_26 ( struct V_1 * V_2 ,
enum V_71 V_72 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_39 , V_8 ;
switch ( V_72 ) {
case V_73 :
break;
case V_74 :
break;
case V_75 :
if ( V_2 -> V_23 . V_76 == V_77 ) {
V_39 = F_27 ( F_3 ( V_5 -> V_78 ) ,
V_5 -> V_78 ) ;
if ( V_39 != 0 ) {
F_4 ( V_2 -> V_10 ,
L_31 ,
V_39 ) ;
return V_39 ;
}
if ( V_5 -> V_18 . V_79 ) {
F_11 ( V_5 -> V_18 . V_79 ,
1 ) ;
F_28 ( 2 ) ;
}
F_29 ( V_5 -> V_20 , false ) ;
switch ( V_5 -> V_80 ) {
case 0 :
F_30 ( V_5 -> V_20 , true ) ;
F_31 ( V_2 , 0x11 , 0x3 ) ;
F_31 ( V_2 , 0x203 , 0xc ) ;
F_31 ( V_2 , 0x206 , 0 ) ;
F_31 ( V_2 , 0x207 , 0xf0 ) ;
F_31 ( V_2 , 0x208 , 0x3c ) ;
F_31 ( V_2 , 0x209 , 0 ) ;
F_31 ( V_2 , 0x211 , 0x20d8 ) ;
F_31 ( V_2 , 0x11 , 0 ) ;
for ( V_8 = 0 ;
V_8 < F_3 ( V_81 ) ;
V_8 ++ )
F_31 ( V_2 ,
V_81 [ V_8 ] . V_38 ,
V_81 [ V_8 ] . V_27 ) ;
F_30 ( V_5 -> V_20 , false ) ;
break;
default:
break;
}
F_32 ( V_5 -> V_20 ) ;
}
break;
case V_77 :
F_29 ( V_5 -> V_20 , true ) ;
F_33 ( V_5 -> V_20 ) ;
if ( V_5 -> V_18 . V_79 )
F_11 ( V_5 -> V_18 . V_79 , 0 ) ;
F_34 ( F_3 ( V_5 -> V_78 ) ,
V_5 -> V_78 ) ;
break;
}
V_2 -> V_23 . V_76 = V_72 ;
return 0 ;
}
static int F_35 ( struct V_82 * V_83 )
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
static int F_36 ( struct V_82 * V_83 , unsigned int V_88 )
{
struct V_1 * V_2 = V_83 -> V_2 ;
int V_89 , V_90 , V_91 , V_92 ;
V_92 = F_35 ( V_83 ) ;
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
static int F_37 ( struct V_113 * V_114 ,
struct V_115 * V_116 ,
struct V_82 * V_83 )
{
struct V_1 * V_2 = V_83 -> V_2 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
bool V_117 = V_5 -> V_118 [ V_83 -> V_84 ] ;
int V_8 , V_92 , V_90 , V_119 , V_89 , V_120 , V_121 , V_122 ;
int * V_123 ;
V_92 = F_35 ( V_83 ) ;
if ( V_92 < 0 )
return V_92 ;
V_120 = F_38 ( F_39 ( V_116 ) ) ;
if ( V_120 < 0 )
return V_120 ;
V_121 = F_40 ( V_116 ) ;
if ( V_121 < 0 )
return V_121 ;
F_6 ( V_2 -> V_10 , L_34 ,
V_120 , V_121 ) ;
V_90 = F_41 ( V_116 ) ;
if ( V_90 < 0 )
return V_90 ;
if ( ! V_117 ) {
V_119 = V_5 -> V_12 ;
V_122 = F_1 ( V_2 , F_42 ( V_116 ) ) ;
if ( V_122 < 0 )
return V_122 ;
} else {
V_119 = V_5 -> V_17 ;
V_122 = 3 ;
for ( V_8 = 0 ; V_8 < F_3 ( V_9 ) ; V_8 ++ )
if ( F_42 ( V_116 ) == V_9 [ V_8 ] )
break;
if ( V_8 == F_3 ( V_9 ) ) {
F_4 ( V_2 -> V_10 , L_35 ,
F_42 ( V_116 ) ) ;
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
V_89 = V_123 [ V_90 ] / F_42 ( V_116 ) ;
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
static int F_43 ( struct V_1 * V_2 , int V_141 ,
int V_142 , unsigned int V_143 , int V_144 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
int * V_145 ;
int V_146 , V_147 , V_39 , V_38 ;
switch ( V_141 ) {
case V_148 :
V_38 = V_149 ;
V_145 = & V_5 -> V_12 ;
break;
case V_150 :
V_38 = V_151 ;
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
F_7 ( V_2 , V_38 , V_165 |
V_166 ,
V_146 << V_167 | V_142 ) ;
if ( V_141 == V_148 ) {
F_6 ( V_2 -> V_10 , L_47 ,
V_147 ) ;
if ( 0 && * V_145 )
F_8 ( V_2 , V_147 ) ;
V_39 = F_1 ( V_2 , V_147 ) ;
if ( V_39 != 0 )
F_9 ( V_2 -> V_10 , L_48 ,
V_39 ) ;
}
* V_145 = V_143 ;
return 0 ;
}
static int F_44 ( struct V_168 * V_169 , unsigned int V_170 ,
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
F_45 ( L_49 ,
V_170 ) ;
return - V_11 ;
}
}
F_46 ( L_50 , V_170 , V_171 ) ;
V_170 /= div ;
div = 2 ;
while ( V_171 * div < 90000000 ) {
div ++ ;
if ( div > 64 ) {
F_45 ( L_51 ,
V_171 ) ;
return - V_11 ;
}
}
V_172 = V_171 * div ;
V_169 -> V_176 = div - 1 ;
F_46 ( L_52 , V_172 ) ;
for ( V_8 = 0 ; V_8 < F_3 ( V_177 ) ; V_8 ++ ) {
if ( V_177 [ V_8 ] . V_178 <= V_170 && V_170 <= V_177 [ V_8 ] . V_179 ) {
V_169 -> V_180 = V_177 [ V_8 ] . V_180 ;
V_173 = V_177 [ V_8 ] . V_181 ;
break;
}
}
if ( V_8 == F_3 ( V_177 ) ) {
F_45 ( L_53 , V_170 ) ;
return - V_11 ;
}
V_169 -> V_182 = V_172 / ( V_173 * V_170 ) ;
if ( V_172 % V_170 == 0 ) {
V_169 -> V_183 = 0 ;
V_169 -> V_184 = 0 ;
} else {
V_174 = F_47 ( V_172 , V_173 * V_170 ) ;
V_169 -> V_183 = ( V_172 - ( V_169 -> V_182 * V_173 * V_170 ) )
/ V_174 ;
V_169 -> V_184 = ( V_173 * V_170 ) / V_174 ;
}
F_46 ( L_54 ,
V_169 -> V_182 , V_169 -> V_183 , V_169 -> V_184 ) ;
F_46 ( L_55 ,
V_169 -> V_180 , V_173 , V_169 -> V_176 ,
V_169 -> V_175 ) ;
return 0 ;
}
static int F_48 ( struct V_1 * V_2 , int V_185 , int V_142 ,
unsigned int V_170 , unsigned int V_171 )
{
struct V_186 * V_187 = F_49 ( V_2 -> V_10 ) ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_168 V_188 ;
struct V_189 * V_190 ;
int V_39 , V_92 , V_191 , V_8 , V_192 ;
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
V_39 = F_44 ( & V_188 , V_170 , V_171 ) ;
if ( V_39 < 0 )
return V_39 ;
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
F_50 ( & V_190 -> V_191 ) ;
F_7 ( V_2 , V_92 + 1 , V_200 , V_200 ) ;
if ( V_187 -> V_217 )
V_192 = 2 ;
else
V_192 = 50 ;
F_7 ( V_2 , V_149 , V_218 ,
V_218 ) ;
for ( V_8 = 0 ; V_8 < V_192 ; V_8 ++ ) {
if ( V_187 -> V_217 ) {
V_39 = F_51 ( & V_190 -> V_191 ,
F_52 ( 25 ) ) ;
if ( V_39 > 0 )
break;
} else {
F_28 ( 1 ) ;
}
V_39 = F_5 ( V_2 ,
V_65 ) ;
if ( V_39 < 0 ) {
F_4 ( V_2 -> V_10 ,
L_59 ,
V_39 ) ;
continue;
}
if ( V_39 & V_191 )
break;
}
if ( V_8 == V_192 ) {
F_4 ( V_2 -> V_10 , L_60 , V_185 ) ;
return - V_219 ;
}
V_190 -> V_220 = V_142 ;
V_190 -> V_221 = V_170 ;
V_190 -> V_199 = V_171 ;
F_6 ( V_2 -> V_10 , L_61 , V_185 ,
V_170 , V_171 ) ;
return 0 ;
}
static void F_53 ( struct V_1 * V_2 , int V_222 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_223 * V_224 = & V_5 -> V_18 . V_225 [ V_222 ] ;
F_54 ( V_222 >= F_3 ( V_5 -> V_18 . V_225 ) ) ;
F_11 ( V_5 -> V_18 . V_226 , V_224 -> V_226 ) ;
F_7 ( V_2 , V_227 ,
V_228 |
V_229 ,
( V_224 -> V_230 << V_231 ) |
V_224 -> V_232 << V_233 ) ;
F_7 ( V_2 , V_234 ,
V_235 ,
V_224 -> V_232 << V_236 ) ;
V_5 -> V_237 = V_222 ;
F_6 ( V_2 -> V_10 , L_62 ,
V_5 -> V_237 ) ;
}
static void F_55 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_27 ;
V_27 = F_5 ( V_2 , V_238 ) ;
F_6 ( V_2 -> V_10 , L_63 , V_27 ) ;
if ( ! ( V_27 & V_239 ) ) {
F_9 ( V_2 -> V_10 , L_64 ) ;
return;
}
if ( ! ( V_27 & V_240 ) ) {
F_6 ( V_2 -> V_10 , L_65 ) ;
V_5 -> V_241 = false ;
V_5 -> V_242 = true ;
F_56 ( V_5 -> V_243 , 0 ,
V_244 | V_245 |
V_246 ) ;
F_7 ( V_2 , V_247 ,
V_248 ,
V_248 ) ;
return;
}
if ( V_27 & 0x400 ) {
if ( V_5 -> V_242 ) {
F_6 ( V_2 -> V_10 , L_66 ) ;
V_5 -> V_241 = true ;
V_5 -> V_242 = false ;
F_56 ( V_5 -> V_243 ,
V_245 ,
V_245 | V_246 ) ;
F_7 ( V_2 , V_247 ,
V_248 ,
5 << V_249 ) ;
} else {
F_6 ( V_2 -> V_10 , L_67 ) ;
F_56 ( V_5 -> V_243 , 0 , V_246 ) ;
}
return;
}
if ( V_5 -> V_242 && ( V_27 & 0x3f8 ) ) {
F_53 ( V_2 , ! V_5 -> V_237 ) ;
return;
}
if ( V_27 & 0x3fc ) {
if ( V_5 -> V_241 ) {
F_6 ( V_2 -> V_10 , L_68 ) ;
F_56 ( V_5 -> V_243 , V_246 ,
V_246 ) ;
} else if ( V_5 -> V_242 ) {
F_6 ( V_2 -> V_10 , L_69 ) ;
V_5 -> V_242 = false ;
F_56 ( V_5 -> V_243 , V_250 ,
V_250 ) ;
F_7 ( V_2 , V_247 ,
V_248 ,
7 << V_249 ) ;
}
}
}
int F_57 ( struct V_1 * V_2 , struct V_251 * V_243 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
if ( V_243 ) {
V_5 -> V_243 = V_243 ;
V_5 -> V_242 = true ;
F_53 ( V_2 , 0 ) ;
F_7 ( V_2 , V_247 ,
V_252 |
V_248 ,
( 7 << V_253 ) |
V_248 ) ;
F_58 ( & V_2 -> V_23 , L_70 ) ;
F_58 ( & V_2 -> V_23 , L_38 ) ;
F_59 ( & V_2 -> V_23 ) ;
F_7 ( V_2 , V_247 ,
V_254 , V_254 ) ;
F_7 ( V_2 , V_255 ,
V_256 , 0 ) ;
} else {
F_7 ( V_2 , V_255 ,
V_257 |
V_256 ,
V_257 |
V_256 ) ;
F_7 ( V_2 , V_247 ,
V_254 , 0 ) ;
V_5 -> V_243 = NULL ;
}
return 0 ;
}
static T_2 F_60 ( int V_217 , void * V_258 )
{
struct V_1 * V_2 = V_258 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
T_2 V_259 = V_260 ;
int V_261 ;
V_261 = F_5 ( V_2 , V_262 ) ;
if ( V_261 < 0 ) {
F_4 ( V_2 -> V_10 , L_71 ,
V_261 ) ;
V_261 = 0 ;
}
V_261 &= ~ F_5 ( V_2 , V_255 ) ;
F_31 ( V_2 , V_262 , V_261 ) ;
if ( V_261 )
V_259 = V_263 ;
F_22 ( V_2 , V_261 ) ;
if ( V_261 & V_264 ) {
F_6 ( V_2 -> V_10 , L_72 ) ;
F_61 ( & V_5 -> V_190 [ 0 ] . V_191 ) ;
}
if ( V_261 & V_265 ) {
F_6 ( V_2 -> V_10 , L_73 ) ;
F_61 ( & V_5 -> V_190 [ 1 ] . V_191 ) ;
}
if ( V_261 & V_266 )
F_55 ( V_2 ) ;
V_261 = F_5 ( V_2 , V_267 ) ;
if ( V_261 < 0 ) {
F_4 ( V_2 -> V_10 , L_74 ,
V_261 ) ;
V_261 = 0 ;
}
V_261 &= ~ F_5 ( V_2 , V_268 ) ;
if ( V_261 )
V_259 = V_263 ;
F_31 ( V_2 , V_267 , V_261 ) ;
F_24 ( V_2 , V_261 ) ;
return V_259 ;
}
static T_2 F_62 ( int V_217 , void * V_258 )
{
T_2 V_39 = V_260 ;
T_2 V_27 ;
do {
V_27 = F_60 ( V_217 , V_258 ) ;
if ( V_27 != V_260 )
V_39 = V_27 ;
} while ( V_27 != V_260 );
return V_39 ;
}
static inline struct V_4 * F_63 ( struct V_269 * V_270 )
{
return F_14 ( V_270 , struct V_4 , V_269 ) ;
}
static void F_64 ( struct V_269 * V_270 , unsigned V_271 , int V_272 )
{
struct V_4 * V_5 = F_63 ( V_270 ) ;
F_65 ( V_5 -> V_20 , V_273 + V_271 ,
V_274 , ! ! V_272 << V_275 ) ;
}
static int F_66 ( struct V_269 * V_270 ,
unsigned V_271 , int V_272 )
{
struct V_4 * V_5 = F_63 ( V_270 ) ;
int V_27 , V_39 ;
V_27 = ( 1 << V_276 ) | ( ! ! V_272 << V_275 ) ;
V_39 = F_65 ( V_5 -> V_20 , V_273 + V_271 ,
V_277 | V_278 |
V_274 , V_27 ) ;
if ( V_39 < 0 )
return V_39 ;
else
return 0 ;
}
static int F_67 ( struct V_269 * V_270 , unsigned V_271 )
{
struct V_4 * V_5 = F_63 ( V_270 ) ;
unsigned int V_38 ;
int V_39 ;
V_39 = F_68 ( V_5 -> V_20 , V_273 + V_271 , & V_38 ) ;
if ( V_39 < 0 )
return V_39 ;
return ( V_38 & V_274 ) != 0 ;
}
static int F_69 ( struct V_269 * V_270 , unsigned V_271 )
{
struct V_4 * V_5 = F_63 ( V_270 ) ;
return F_65 ( V_5 -> V_20 , V_273 + V_271 ,
V_277 | V_278 ,
( 1 << V_276 ) |
( 1 << V_279 ) ) ;
}
static void F_70 ( struct V_186 * V_187 )
{
struct V_4 * V_5 = F_71 ( V_187 ) ;
int V_39 ;
V_5 -> V_269 = V_280 ;
V_5 -> V_269 . V_281 = 6 ;
V_5 -> V_269 . V_10 = & V_187 -> V_10 ;
if ( V_5 -> V_18 . V_282 )
V_5 -> V_269 . V_92 = V_5 -> V_18 . V_282 ;
else
V_5 -> V_269 . V_92 = - 1 ;
V_39 = F_72 ( & V_5 -> V_269 ) ;
if ( V_39 != 0 )
F_4 ( & V_187 -> V_10 , L_75 , V_39 ) ;
}
static void F_73 ( struct V_186 * V_187 )
{
struct V_4 * V_5 = F_71 ( V_187 ) ;
int V_39 ;
V_39 = F_74 ( & V_5 -> V_269 ) ;
if ( V_39 != 0 )
F_4 ( & V_187 -> V_10 , L_76 , V_39 ) ;
}
static void F_70 ( struct V_186 * V_187 )
{
}
static void F_73 ( struct V_186 * V_187 )
{
}
static int F_75 ( struct V_1 * V_2 )
{
struct V_186 * V_187 = F_49 ( V_2 -> V_10 ) ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_39 , V_8 , V_283 ;
V_5 -> V_2 = V_2 ;
V_2 -> V_284 = V_5 -> V_20 ;
V_39 = F_76 ( V_2 , 16 , 16 , V_285 ) ;
if ( V_39 != 0 ) {
F_4 ( V_2 -> V_10 , L_77 , V_39 ) ;
return V_39 ;
}
F_29 ( V_5 -> V_20 , true ) ;
for ( V_8 = 0 ; V_8 < F_3 ( V_286 ) ; V_8 ++ )
F_7 ( V_2 , V_286 [ V_8 ] , V_287 ,
V_287 ) ;
F_31 ( V_2 , V_288 , 0 ) ;
F_31 ( V_2 , V_289 , 0 ) ;
if ( V_187 -> V_217 ) {
if ( V_5 -> V_18 . V_283 )
V_283 = V_5 -> V_18 . V_283 ;
else
V_283 = V_290 ;
V_283 |= V_291 ;
if ( V_283 & ( V_292 | V_293 ) )
V_39 = F_77 ( V_187 -> V_217 , NULL ,
F_62 ,
V_283 , L_78 , V_2 ) ;
else
V_39 = F_77 ( V_187 -> V_217 , NULL , F_60 ,
V_283 , L_78 , V_2 ) ;
if ( V_39 != 0 ) {
F_4 ( V_2 -> V_10 , L_79 ,
V_187 -> V_217 , V_39 ) ;
} else {
F_7 ( V_2 ,
V_255 ,
V_294 |
V_295 |
V_296 |
V_297 |
V_298 |
V_299 |
V_49 |
V_50 , 0 ) ;
F_7 ( V_2 ,
V_268 ,
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
V_63 |
V_64 , 0 ) ;
}
} else {
F_78 ( & V_2 -> V_23 ,
V_300 ,
F_3 ( V_300 ) ) ;
}
if ( V_5 -> V_18 . V_226 ) {
V_39 = F_79 ( V_5 -> V_18 . V_226 ,
V_301 , L_80 ) ;
if ( V_39 < 0 ) {
F_4 ( & V_187 -> V_10 , L_81 ,
V_5 -> V_18 . V_226 , V_39 ) ;
goto V_302;
}
}
if ( V_5 -> V_18 . V_79 )
F_11 ( V_5 -> V_18 . V_79 , 0 ) ;
F_34 ( F_3 ( V_5 -> V_78 ) ,
V_5 -> V_78 ) ;
return 0 ;
V_302:
if ( V_187 -> V_217 )
F_80 ( V_187 -> V_217 , V_2 ) ;
return V_39 ;
}
static int F_81 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_186 * V_187 = F_49 ( V_2 -> V_10 ) ;
F_26 ( V_2 , V_77 ) ;
if ( V_5 -> V_18 . V_226 ) {
F_82 ( V_5 -> V_18 . V_226 ) ;
}
if ( V_187 -> V_217 )
F_80 ( V_187 -> V_217 , V_2 ) ;
return 0 ;
}
static int F_83 ( struct V_1 * V_2 ,
unsigned int V_38 )
{
return true ;
}
static T_3 int F_84 ( struct V_186 * V_187 ,
const struct V_303 * V_84 )
{
struct V_304 * V_18 = F_85 ( & V_187 -> V_10 ) ;
struct V_4 * V_5 ;
unsigned int V_38 ;
int V_39 , V_8 ;
V_5 = F_86 ( & V_187 -> V_10 , sizeof( struct V_4 ) ,
V_305 ) ;
if ( V_5 == NULL )
return - V_306 ;
V_5 -> V_20 = F_87 ( V_187 , & V_307 ) ;
if ( F_88 ( V_5 -> V_20 ) ) {
V_39 = F_89 ( V_5 -> V_20 ) ;
F_4 ( & V_187 -> V_10 , L_82 ,
V_39 ) ;
goto V_308;
}
for ( V_8 = 0 ; V_8 < F_3 ( V_5 -> V_190 ) ; V_8 ++ )
F_90 ( & V_5 -> V_190 [ V_8 ] . V_191 ) ;
if ( V_18 )
V_5 -> V_18 = * V_18 ;
F_91 ( V_187 , V_5 ) ;
for ( V_8 = 0 ; V_8 < F_3 ( V_5 -> V_78 ) ; V_8 ++ )
V_5 -> V_78 [ V_8 ] . V_309 = V_310 [ V_8 ] ;
V_39 = F_92 ( & V_187 -> V_10 , F_3 ( V_5 -> V_78 ) ,
V_5 -> V_78 ) ;
if ( V_39 != 0 ) {
F_4 ( & V_187 -> V_10 , L_83 ,
V_39 ) ;
goto V_311;
}
V_5 -> V_41 = F_93 ( & V_187 -> V_10 , L_84 ) ;
if ( F_88 ( V_5 -> V_41 ) ) {
V_39 = F_89 ( V_5 -> V_41 ) ;
F_4 ( & V_187 -> V_10 , L_85 , V_39 ) ;
goto V_312;
}
V_5 -> V_45 = F_93 ( & V_187 -> V_10 , L_86 ) ;
if ( F_88 ( V_5 -> V_45 ) ) {
V_39 = F_89 ( V_5 -> V_45 ) ;
F_4 ( & V_187 -> V_10 , L_87 , V_39 ) ;
goto V_313;
}
V_5 -> V_46 = F_93 ( & V_187 -> V_10 , L_88 ) ;
if ( F_88 ( V_5 -> V_46 ) ) {
V_39 = F_89 ( V_5 -> V_46 ) ;
F_4 ( & V_187 -> V_10 , L_87 , V_39 ) ;
goto V_314;
}
V_39 = F_27 ( F_3 ( V_5 -> V_78 ) ,
V_5 -> V_78 ) ;
if ( V_39 != 0 ) {
F_4 ( & V_187 -> V_10 , L_89 ,
V_39 ) ;
goto V_315;
}
if ( V_5 -> V_18 . V_79 ) {
V_39 = F_79 ( V_5 -> V_18 . V_79 ,
V_301 , L_90 ) ;
if ( V_39 < 0 ) {
F_4 ( & V_187 -> V_10 , L_91 ,
V_5 -> V_18 . V_79 , V_39 ) ;
goto V_316;
}
F_28 ( 2 ) ;
}
if ( V_5 -> V_18 . V_19 ) {
V_39 = F_79 ( V_5 -> V_18 . V_19 ,
V_301 , L_92 ) ;
if ( V_39 < 0 ) {
F_4 ( & V_187 -> V_10 , L_93 ,
V_5 -> V_18 . V_19 , V_39 ) ;
goto V_317;
}
}
V_39 = F_68 ( V_5 -> V_20 , V_21 , & V_38 ) ;
if ( V_39 < 0 ) {
F_4 ( & V_187 -> V_10 , L_94 ) ;
goto V_318;
}
switch ( V_38 ) {
case 0x8997 :
case 0x5100 :
break;
default:
F_4 ( & V_187 -> V_10 , L_95 , V_38 ) ;
V_39 = - V_11 ;
goto V_318;
}
V_39 = F_68 ( V_5 -> V_20 , V_319 , & V_38 ) ;
if ( V_39 < 0 ) {
F_4 ( & V_187 -> V_10 , L_96 ) ;
goto V_318;
}
V_5 -> V_80 = V_38 & V_320 ;
F_94 ( & V_187 -> V_10 , L_97 , V_5 -> V_80 + 'A' ) ;
V_39 = F_10 ( V_5 ) ;
if ( V_39 < 0 ) {
F_4 ( & V_187 -> V_10 , L_98 ) ;
goto V_318;
}
F_70 ( V_187 ) ;
for ( V_8 = 0 ; V_8 < F_3 ( V_5 -> V_18 . V_321 ) ; V_8 ++ ) {
if ( ! V_5 -> V_18 . V_321 [ V_8 ] )
continue;
F_12 ( V_5 -> V_20 , V_273 + V_8 ,
V_5 -> V_18 . V_321 [ V_8 ] ) ;
}
for ( V_8 = 0 ; V_8 < F_3 ( V_5 -> V_18 . V_322 ) ; V_8 ++ ) {
F_65 ( V_5 -> V_20 , V_323 [ V_8 ] ,
V_324 |
V_325 ,
( V_5 -> V_18 . V_322 [ V_8 ] <<
V_326 ) |
( V_5 -> V_18 . V_327 [ V_8 ] <<
V_328 ) ) ;
}
V_39 = F_95 ( & V_187 -> V_10 ,
& V_329 , V_330 ,
F_3 ( V_330 ) ) ;
if ( V_39 < 0 ) {
F_4 ( & V_187 -> V_10 , L_99 , V_39 ) ;
goto V_318;
}
return V_39 ;
V_318:
F_73 ( V_187 ) ;
if ( V_5 -> V_18 . V_19 ) {
F_11 ( V_5 -> V_18 . V_19 , 1 ) ;
F_82 ( V_5 -> V_18 . V_19 ) ;
}
V_317:
if ( V_5 -> V_18 . V_79 ) {
F_11 ( V_5 -> V_18 . V_79 , 0 ) ;
F_82 ( V_5 -> V_18 . V_79 ) ;
}
V_316:
F_34 ( F_3 ( V_5 -> V_78 ) ,
V_5 -> V_78 ) ;
V_315:
F_96 ( V_5 -> V_46 ) ;
V_314:
F_96 ( V_5 -> V_45 ) ;
V_313:
F_96 ( V_5 -> V_41 ) ;
V_312:
F_97 ( F_3 ( V_5 -> V_78 ) ,
V_5 -> V_78 ) ;
V_311:
F_98 ( V_5 -> V_20 ) ;
V_308:
return V_39 ;
}
static T_4 int F_99 ( struct V_186 * V_331 )
{
struct V_4 * V_5 = F_71 ( V_331 ) ;
F_100 ( & V_331 -> V_10 ) ;
F_73 ( V_331 ) ;
if ( V_5 -> V_18 . V_19 ) {
F_11 ( V_5 -> V_18 . V_19 , 1 ) ;
F_82 ( V_5 -> V_18 . V_19 ) ;
}
if ( V_5 -> V_18 . V_79 ) {
F_11 ( V_5 -> V_18 . V_79 , 0 ) ;
F_82 ( V_5 -> V_18 . V_79 ) ;
}
F_96 ( V_5 -> V_46 ) ;
F_96 ( V_5 -> V_45 ) ;
F_96 ( V_5 -> V_41 ) ;
F_97 ( F_3 ( V_5 -> V_78 ) ,
V_5 -> V_78 ) ;
F_98 ( V_5 -> V_20 ) ;
return 0 ;
}
static int T_5 F_101 ( void )
{
return F_102 ( & V_332 ) ;
}
static void T_6 F_103 ( void )
{
F_104 ( & V_332 ) ;
}
