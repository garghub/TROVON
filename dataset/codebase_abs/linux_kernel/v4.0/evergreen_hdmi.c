void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_1 V_5 )
{
T_2 V_6 = F_2 ( V_7 ) ;
if ( ! V_4 )
return;
if ( V_5 ) {
V_6 |= V_8 ;
if ( V_5 & 1 )
V_6 |= V_9 ;
if ( V_5 & 2 )
V_6 |= V_10 ;
if ( V_5 & 4 )
V_6 |= V_11 ;
if ( V_5 & 8 )
V_6 |= V_12 ;
} else {
V_6 &= ~ ( V_8 |
V_9 |
V_10 |
V_11 |
V_12 ) ;
}
F_3 ( V_7 , V_6 ) ;
}
void F_4 ( struct V_13 * V_14 , long V_15 ,
const struct V_16 * V_17 )
{
struct V_18 * V_19 = V_14 -> V_19 ;
struct V_1 * V_2 = V_19 -> V_20 ;
int V_21 = 8 ;
if ( V_14 -> V_22 ) {
struct V_23 * V_23 = F_5 ( V_14 -> V_22 ) ;
V_21 = V_23 -> V_21 ;
}
if ( V_21 > 8 )
F_3 ( V_24 + V_15 ,
V_25 ) ;
else
F_3 ( V_24 + V_15 ,
V_26 |
V_25 ) ;
F_3 ( V_27 + V_15 , F_6 ( V_17 -> V_28 ) ) ;
F_3 ( V_29 + V_15 , V_17 -> V_30 ) ;
F_3 ( V_31 + V_15 , F_7 ( V_17 -> V_32 ) ) ;
F_3 ( V_33 + V_15 , V_17 -> V_34 ) ;
F_3 ( V_35 + V_15 , F_8 ( V_17 -> V_36 ) ) ;
F_3 ( V_37 + V_15 , V_17 -> V_38 ) ;
}
void F_9 ( struct V_13 * V_14 ,
struct V_39 * V_40 , struct V_41 * V_42 )
{
struct V_1 * V_2 = V_14 -> V_19 -> V_20 ;
T_2 V_6 = 0 ;
if ( V_42 -> V_43 & V_44 ) {
if ( V_40 -> V_45 [ 1 ] )
V_6 = F_10 ( V_40 -> V_46 [ 1 ] ) |
F_11 ( V_40 -> V_47 [ 1 ] ) ;
else
V_6 = F_10 ( 255 ) | F_11 ( 255 ) ;
} else {
if ( V_40 -> V_45 [ 0 ] )
V_6 = F_10 ( V_40 -> V_46 [ 0 ] ) |
F_11 ( V_40 -> V_47 [ 0 ] ) ;
else
V_6 = F_10 ( 255 ) | F_11 ( 255 ) ;
}
F_12 ( 0 , V_48 , V_6 ) ;
}
void F_13 ( struct V_13 * V_14 ,
T_1 * V_49 , int V_50 )
{
struct V_1 * V_2 = V_14 -> V_19 -> V_20 ;
T_2 V_6 ;
V_6 = F_14 ( 0 , V_51 ) ;
V_6 &= ~ ( V_52 | V_53 ) ;
V_6 |= V_54 ;
if ( V_50 )
V_6 |= F_15 ( V_49 [ 0 ] ) ;
else
V_6 |= F_15 ( 5 ) ;
F_12 ( 0 , V_51 , V_6 ) ;
}
void F_16 ( struct V_13 * V_14 ,
T_1 * V_49 , int V_50 )
{
struct V_1 * V_2 = V_14 -> V_19 -> V_20 ;
T_2 V_6 ;
V_6 = F_14 ( 0 , V_51 ) ;
V_6 &= ~ ( V_54 | V_53 ) ;
V_6 |= V_52 ;
if ( V_50 )
V_6 |= F_15 ( V_49 [ 0 ] ) ;
else
V_6 |= F_15 ( 5 ) ;
F_12 ( 0 , V_51 , V_6 ) ;
}
void F_17 ( struct V_13 * V_14 ,
struct V_55 * V_56 , int V_50 )
{
int V_57 ;
struct V_1 * V_2 = V_14 -> V_19 -> V_20 ;
static const T_3 V_58 [] [ 2 ] = {
{ V_59 , V_60 } ,
{ V_61 , V_62 } ,
{ V_63 , V_64 } ,
{ V_65 , V_66 } ,
{ V_67 , V_68 } ,
{ V_69 , V_70 } ,
{ V_71 , V_72 } ,
{ V_73 , V_74 } ,
{ V_75 , V_76 } ,
{ V_77 , V_78 } ,
{ V_79 , V_80 } ,
{ V_81 , V_82 } ,
} ;
for ( V_57 = 0 ; V_57 < F_18 ( V_58 ) ; V_57 ++ ) {
T_2 V_83 = 0 ;
T_1 V_84 = 0 ;
int V_85 = - 1 ;
int V_86 ;
for ( V_86 = 0 ; V_86 < V_50 ; V_86 ++ ) {
struct V_55 * V_87 = & V_56 [ V_86 ] ;
if ( V_87 -> V_88 == V_58 [ V_57 ] [ 1 ] ) {
if ( V_87 -> V_89 > V_85 ) {
V_83 = F_19 ( V_87 -> V_89 ) |
F_20 ( V_87 -> V_90 ) |
F_21 ( V_87 -> V_91 ) ;
V_85 = V_87 -> V_89 ;
}
if ( V_87 -> V_88 == V_60 )
V_84 |= V_87 -> V_91 ;
else
break;
}
}
V_83 |= F_22 ( V_84 ) ;
F_12 ( 0 , V_58 [ V_57 ] [ 0 ] , V_83 ) ;
}
}
void F_23 ( struct V_1 * V_2 , T_2 V_15 ,
unsigned char * V_92 , T_4 V_93 )
{
T_5 * V_94 = V_92 + 3 ;
F_3 ( V_95 + V_15 ,
V_94 [ 0x0 ] | ( V_94 [ 0x1 ] << 8 ) | ( V_94 [ 0x2 ] << 16 ) | ( V_94 [ 0x3 ] << 24 ) ) ;
F_3 ( V_96 + V_15 ,
V_94 [ 0x4 ] | ( V_94 [ 0x5 ] << 8 ) | ( V_94 [ 0x6 ] << 16 ) | ( V_94 [ 0x7 ] << 24 ) ) ;
F_3 ( V_97 + V_15 ,
V_94 [ 0x8 ] | ( V_94 [ 0x9 ] << 8 ) | ( V_94 [ 0xA ] << 16 ) | ( V_94 [ 0xB ] << 24 ) ) ;
F_3 ( V_98 + V_15 ,
V_94 [ 0xC ] | ( V_94 [ 0xD ] << 8 ) | ( V_92 [ 1 ] << 24 ) ) ;
F_24 ( V_99 + V_15 ,
V_100 |
V_101 ) ;
F_25 ( V_102 + V_15 ,
F_26 ( 2 ) ,
~ V_103 ) ;
}
void F_27 ( struct V_1 * V_2 ,
struct V_23 * V_22 , unsigned int clock )
{
unsigned int V_104 = clock / 24000 ;
T_2 V_105 ;
T_2 V_106 ;
T_2 V_83 ;
if ( V_104 >= 8 ) {
V_105 = 192 * 1000 ;
V_106 = 3 ;
} else if ( V_104 >= 4 ) {
V_105 = 96 * 1000 ;
V_106 = 2 ;
} else if ( V_104 >= 2 ) {
V_105 = 48 * 1000 ;
V_106 = 1 ;
} else {
V_105 = 24 * 1000 ;
V_106 = 0 ;
}
V_83 = F_2 ( V_107 ) & ~ V_108 ;
V_83 |= F_28 ( V_106 ) ;
V_83 &= ~ V_109 ;
F_3 ( V_107 , V_83 ) ;
V_83 = 0 ;
if ( V_22 )
V_83 |= F_29 ( V_22 -> V_110 ) ;
F_3 ( V_111 , V_83 ) ;
F_3 ( V_112 , V_105 ) ;
F_3 ( V_113 , clock ) ;
}
void F_30 ( struct V_1 * V_2 ,
struct V_23 * V_22 , unsigned int clock )
{
T_2 V_83 ;
V_83 = F_2 ( V_114 ) & ~ V_108 ;
V_83 |= V_109 ;
F_3 ( V_114 , V_83 ) ;
V_83 = 0 ;
V_83 |= V_115 ;
if ( V_22 )
V_83 |= F_29 ( V_22 -> V_110 ) ;
F_3 ( V_111 , V_83 ) ;
F_3 ( V_116 , 24000 ) ;
F_3 ( V_117 , clock ) ;
}
void F_31 ( struct V_13 * V_14 , T_2 V_15 )
{
struct V_18 * V_19 = V_14 -> V_19 ;
struct V_1 * V_2 = V_19 -> V_20 ;
F_3 ( V_118 + V_15 ,
V_119 |
V_120 |
V_121 ) ;
}
void F_32 ( struct V_13 * V_14 , T_2 V_15 , int V_21 )
{
struct V_18 * V_19 = V_14 -> V_19 ;
struct V_1 * V_2 = V_19 -> V_20 ;
struct V_39 * V_40 = F_33 ( V_14 ) ;
T_6 V_122 ;
V_122 = F_2 ( V_123 + V_15 ) ;
V_122 &= ~ V_124 ;
V_122 &= ~ V_125 ;
switch ( V_21 ) {
case 0 :
case 6 :
case 8 :
case 16 :
default:
F_34 ( L_1 ,
V_40 -> V_126 , V_21 ) ;
break;
case 10 :
V_122 |= V_124 ;
V_122 |= F_35 ( V_127 ) ;
F_34 ( L_2 ,
V_40 -> V_126 ) ;
break;
case 12 :
V_122 |= V_124 ;
V_122 |= F_35 ( V_128 ) ;
F_34 ( L_3 ,
V_40 -> V_126 ) ;
break;
}
F_3 ( V_123 + V_15 , V_122 ) ;
}
void F_36 ( struct V_13 * V_14 , T_2 V_15 )
{
struct V_18 * V_19 = V_14 -> V_19 ;
struct V_1 * V_2 = V_19 -> V_20 ;
F_3 ( V_129 + V_15 ,
V_130 ) ;
F_3 ( V_131 + V_15 ,
F_37 ( 1 ) ) ;
F_3 ( V_132 + V_15 ,
F_38 ( 2 ) ) ;
F_3 ( V_133 + V_15 ,
F_39 ( 3 ) |
F_40 ( 4 ) |
F_41 ( 5 ) |
F_42 ( 6 ) |
F_43 ( 7 ) |
F_44 ( 8 ) ) ;
F_3 ( V_134 + V_15 ,
F_45 ( 0xff ) ) ;
F_3 ( V_135 + V_15 ,
V_136 | V_137 | V_138 ) ;
}
void F_46 ( struct V_13 * V_14 , T_2 V_15 , bool V_139 )
{
struct V_18 * V_19 = V_14 -> V_19 ;
struct V_1 * V_2 = V_19 -> V_20 ;
if ( V_139 )
F_24 ( V_140 + V_15 , V_141 ) ;
else
F_47 ( V_140 + V_15 , ~ V_141 ) ;
}
void F_48 ( struct V_13 * V_14 , bool V_142 )
{
struct V_18 * V_19 = V_14 -> V_19 ;
struct V_1 * V_2 = V_19 -> V_20 ;
struct V_143 * V_143 = F_49 ( V_14 ) ;
struct V_144 * V_145 = V_143 -> V_146 ;
if ( ! V_145 || ! V_145 -> V_147 )
return;
if ( V_142 ) {
F_3 ( V_102 + V_145 -> V_147 -> V_15 ,
F_50 ( 2 ) ) ;
F_3 ( V_148 + V_145 -> V_147 -> V_15 ,
F_51 ( 1 ) |
F_52 ( 3 ) ) ;
F_3 ( V_99 + V_145 -> V_147 -> V_15 ,
V_149 |
V_150 ) ;
} else {
F_3 ( V_99 + V_145 -> V_147 -> V_15 , 0 ) ;
}
V_145 -> V_147 -> V_151 = V_142 ;
F_34 ( L_4 ,
V_142 ? L_5 : L_6 , V_145 -> V_147 -> V_15 , V_143 -> V_152 ) ;
}
void F_53 ( struct V_13 * V_14 , bool V_142 )
{
struct V_18 * V_19 = V_14 -> V_19 ;
struct V_1 * V_2 = V_19 -> V_20 ;
struct V_143 * V_143 = F_49 ( V_14 ) ;
struct V_144 * V_145 = V_143 -> V_146 ;
if ( ! V_145 || ! V_145 -> V_147 )
return;
if ( V_142 ) {
struct V_39 * V_40 = F_33 ( V_14 ) ;
struct V_153 * V_153 = F_54 ( V_40 ) ;
struct V_154 * V_155 ;
T_6 V_122 ;
F_3 ( V_156 + V_145 -> V_147 -> V_15 ,
F_55 ( 1 ) ) ;
if ( V_153 -> V_157 ) {
V_155 = V_153 -> V_157 ;
V_122 = F_2 ( V_158 + V_145 -> V_147 -> V_15 ) ;
V_122 &= ~ F_56 ( 0xf ) ;
if ( V_155 -> V_159 == 162000 )
V_122 |= F_56 ( 3 ) ;
else
V_122 |= F_56 ( 5 ) ;
F_3 ( V_158 + V_145 -> V_147 -> V_15 , V_122 ) ;
}
F_3 ( V_160 + V_145 -> V_147 -> V_15 ,
V_161 |
V_162 |
V_163 |
V_164 ) ;
} else {
F_3 ( V_160 + V_145 -> V_147 -> V_15 , 0 ) ;
}
V_145 -> V_147 -> V_151 = V_142 ;
}
