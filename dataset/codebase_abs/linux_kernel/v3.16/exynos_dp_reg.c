void F_1 ( struct V_1 * V_2 , bool V_3 )
{
T_1 V_4 ;
if ( V_3 ) {
V_4 = F_2 ( V_2 -> V_5 + V_6 ) ;
V_4 |= V_7 ;
F_3 ( V_4 , V_2 -> V_5 + V_6 ) ;
} else {
V_4 = F_2 ( V_2 -> V_5 + V_6 ) ;
V_4 &= ~ V_7 ;
F_3 ( V_4 , V_2 -> V_5 + V_6 ) ;
}
}
void F_4 ( struct V_1 * V_2 )
{
T_1 V_4 ;
V_4 = F_2 ( V_2 -> V_5 + V_6 ) ;
V_4 &= ~ V_8 ;
F_3 ( V_4 , V_2 -> V_5 + V_6 ) ;
}
void F_5 ( struct V_1 * V_2 , bool V_3 )
{
T_1 V_4 ;
if ( V_3 )
V_4 = V_9 | V_10 |
V_11 | V_12 ;
else
V_4 = V_13 | V_14 |
V_15 | V_16 ;
F_3 ( V_4 , V_2 -> V_5 + V_17 ) ;
}
void F_6 ( struct V_1 * V_2 )
{
T_1 V_4 ;
V_4 = V_18 ;
F_3 ( V_4 , V_2 -> V_5 + V_19 ) ;
V_4 = V_20 | V_21 ;
F_3 ( V_4 , V_2 -> V_5 + V_22 ) ;
V_4 = V_23 | V_24 ;
F_3 ( V_4 , V_2 -> V_5 + V_25 ) ;
V_4 = V_26 | V_27 |
V_28 | V_29 ;
F_3 ( V_4 , V_2 -> V_5 + V_30 ) ;
V_4 = V_31 | V_32 |
V_33 | V_34 ;
F_3 ( V_4 , V_2 -> V_5 + V_35 ) ;
}
void F_7 ( struct V_1 * V_2 )
{
F_3 ( V_36 | V_37 , V_2 -> V_5 + V_38 ) ;
F_3 ( 0xff , V_2 -> V_5 + V_39 ) ;
F_3 ( 0x4f , V_2 -> V_5 + V_40 ) ;
F_3 ( 0xe0 , V_2 -> V_5 + V_41 ) ;
F_3 ( 0xe7 , V_2 -> V_5 + V_42 ) ;
F_3 ( 0x63 , V_2 -> V_5 + V_43 ) ;
F_3 ( 0x00 , V_2 -> V_5 + V_44 ) ;
F_3 ( 0x00 , V_2 -> V_5 + V_45 ) ;
F_3 ( 0x00 , V_2 -> V_5 + V_46 ) ;
F_3 ( 0x00 , V_2 -> V_5 + V_47 ) ;
F_3 ( 0x00 , V_2 -> V_5 + V_48 ) ;
}
void F_8 ( struct V_1 * V_2 )
{
T_1 V_4 ;
F_4 ( V_2 ) ;
F_1 ( V_2 , 0 ) ;
V_4 = V_49 | V_50 |
V_51 | V_52 |
V_53 | V_54 ;
F_3 ( V_4 , V_2 -> V_5 + V_55 ) ;
V_4 = V_56 | V_57 |
V_58 |
V_59 ;
F_3 ( V_4 , V_2 -> V_5 + V_60 ) ;
F_9 ( 20 , 30 ) ;
F_5 ( V_2 , 0 ) ;
F_3 ( 0x0 , V_2 -> V_5 + V_61 ) ;
F_3 ( 0x40 , V_2 -> V_5 + V_62 ) ;
F_3 ( 0x0 , V_2 -> V_5 + V_63 ) ;
F_3 ( 0x0 , V_2 -> V_5 + V_64 ) ;
F_3 ( 0x0 , V_2 -> V_5 + V_65 ) ;
F_3 ( 0x0 , V_2 -> V_5 + V_66 ) ;
F_3 ( 0x5e , V_2 -> V_5 + V_67 ) ;
F_3 ( 0x1a , V_2 -> V_5 + V_68 ) ;
F_3 ( 0x10 , V_2 -> V_5 + V_69 ) ;
F_3 ( 0x0 , V_2 -> V_5 + V_70 ) ;
F_3 ( 0x0 , V_2 -> V_5 + V_71 ) ;
F_3 ( 0x20 , V_2 -> V_5 + V_72 ) ;
F_3 ( 0x4 , V_2 -> V_5 + V_73 ) ;
F_3 ( 0x2 , V_2 -> V_5 + V_74 ) ;
F_3 ( 0x00000101 , V_2 -> V_5 + V_75 ) ;
}
void F_10 ( struct V_1 * V_2 )
{
F_3 ( V_76 , V_2 -> V_5 + V_77 ) ;
}
void F_11 ( struct V_1 * V_2 )
{
T_1 V_4 ;
V_4 = V_78 ;
F_3 ( V_4 , V_2 -> V_5 + V_44 ) ;
V_4 = V_79 ;
F_3 ( V_4 , V_2 -> V_5 + V_45 ) ;
V_4 = V_80 ;
F_3 ( V_4 , V_2 -> V_5 + V_46 ) ;
V_4 = V_81 ;
F_3 ( V_4 , V_2 -> V_5 + V_47 ) ;
V_4 = V_82 ;
F_3 ( V_4 , V_2 -> V_5 + V_48 ) ;
}
enum V_83 F_12 ( struct V_1 * V_2 )
{
T_1 V_4 ;
V_4 = F_2 ( V_2 -> V_5 + V_84 ) ;
if ( V_4 & V_85 )
return V_86 ;
else
return V_87 ;
}
void F_13 ( struct V_1 * V_2 , bool V_3 )
{
T_1 V_4 ;
if ( V_3 ) {
V_4 = F_2 ( V_2 -> V_5 + V_88 ) ;
V_4 |= V_89 ;
F_3 ( V_4 , V_2 -> V_5 + V_88 ) ;
} else {
V_4 = F_2 ( V_2 -> V_5 + V_88 ) ;
V_4 &= ~ V_89 ;
F_3 ( V_4 , V_2 -> V_5 + V_88 ) ;
}
}
void F_14 ( struct V_1 * V_2 ,
enum V_90 V_91 ,
bool V_3 )
{
T_1 V_4 ;
switch ( V_91 ) {
case V_92 :
if ( V_3 ) {
V_4 = F_2 ( V_2 -> V_5 + V_93 ) ;
V_4 |= V_94 ;
F_3 ( V_4 , V_2 -> V_5 + V_93 ) ;
} else {
V_4 = F_2 ( V_2 -> V_5 + V_93 ) ;
V_4 &= ~ V_94 ;
F_3 ( V_4 , V_2 -> V_5 + V_93 ) ;
}
break;
case V_95 :
if ( V_3 ) {
V_4 = F_2 ( V_2 -> V_5 + V_93 ) ;
V_4 |= V_96 ;
F_3 ( V_4 , V_2 -> V_5 + V_93 ) ;
} else {
V_4 = F_2 ( V_2 -> V_5 + V_93 ) ;
V_4 &= ~ V_96 ;
F_3 ( V_4 , V_2 -> V_5 + V_93 ) ;
}
break;
case V_97 :
if ( V_3 ) {
V_4 = F_2 ( V_2 -> V_5 + V_93 ) ;
V_4 |= V_98 ;
F_3 ( V_4 , V_2 -> V_5 + V_93 ) ;
} else {
V_4 = F_2 ( V_2 -> V_5 + V_93 ) ;
V_4 &= ~ V_98 ;
F_3 ( V_4 , V_2 -> V_5 + V_93 ) ;
}
break;
case V_99 :
if ( V_3 ) {
V_4 = F_2 ( V_2 -> V_5 + V_93 ) ;
V_4 |= V_100 ;
F_3 ( V_4 , V_2 -> V_5 + V_93 ) ;
} else {
V_4 = F_2 ( V_2 -> V_5 + V_93 ) ;
V_4 &= ~ V_100 ;
F_3 ( V_4 , V_2 -> V_5 + V_93 ) ;
}
break;
case V_101 :
if ( V_3 ) {
V_4 = F_2 ( V_2 -> V_5 + V_93 ) ;
V_4 |= V_102 ;
F_3 ( V_4 , V_2 -> V_5 + V_93 ) ;
} else {
V_4 = F_2 ( V_2 -> V_5 + V_93 ) ;
V_4 &= ~ V_102 ;
F_3 ( V_4 , V_2 -> V_5 + V_93 ) ;
}
break;
case V_103 :
if ( V_3 ) {
V_4 = F_2 ( V_2 -> V_5 + V_93 ) ;
V_4 |= V_104 ;
F_3 ( V_4 , V_2 -> V_5 + V_93 ) ;
} else {
V_4 = F_2 ( V_2 -> V_5 + V_93 ) ;
V_4 &= ~ V_104 ;
F_3 ( V_4 , V_2 -> V_5 + V_93 ) ;
}
break;
case V_105 :
if ( V_3 ) {
V_4 = V_104 | V_94 | V_102 | V_100 |
V_98 | V_96 ;
F_3 ( V_4 , V_2 -> V_5 + V_93 ) ;
} else {
F_3 ( 0x00 , V_2 -> V_5 + V_93 ) ;
}
break;
default:
break;
}
}
void F_15 ( struct V_1 * V_2 )
{
T_1 V_4 ;
int V_106 = 0 ;
F_14 ( V_2 , V_105 , 0 ) ;
V_4 = V_107 ;
F_3 ( V_4 , V_2 -> V_5 + V_39 ) ;
V_4 = F_2 ( V_2 -> V_5 + V_84 ) ;
V_4 &= ~ ( V_108 | V_109 ) ;
F_3 ( V_4 , V_2 -> V_5 + V_84 ) ;
if ( F_12 ( V_2 ) == V_87 ) {
F_13 ( V_2 , 0 ) ;
while ( F_12 ( V_2 ) == V_87 ) {
V_106 ++ ;
if ( V_110 < V_106 ) {
F_16 ( V_2 -> V_111 , L_1 ) ;
return;
}
F_9 ( 10 , 20 ) ;
}
}
V_4 = F_2 ( V_2 -> V_5 + V_60 ) ;
V_4 &= ~ ( V_58 | V_59
| V_57 ) ;
F_3 ( V_4 , V_2 -> V_5 + V_60 ) ;
}
void F_17 ( struct V_1 * V_2 )
{
T_1 V_4 ;
if ( F_18 ( V_2 -> V_112 ) )
return;
V_4 = V_113 | V_114 | V_115 ;
F_3 ( V_4 , V_2 -> V_5 + V_42 ) ;
V_4 = V_116 ;
F_3 ( V_4 , V_2 -> V_5 + V_43 ) ;
}
void F_19 ( struct V_1 * V_2 )
{
T_1 V_4 ;
if ( F_18 ( V_2 -> V_112 ) )
return;
F_17 ( V_2 ) ;
V_4 = F_2 ( V_2 -> V_5 + V_63 ) ;
V_4 &= ~ ( V_117 | V_118 ) ;
F_3 ( V_4 , V_2 -> V_5 + V_63 ) ;
}
enum V_119 F_20 ( struct V_1 * V_2 )
{
T_1 V_4 ;
if ( F_18 ( V_2 -> V_112 ) ) {
V_4 = F_21 ( V_2 -> V_112 ) ;
if ( V_4 )
return V_120 ;
else
return V_121 ;
} else {
V_4 = F_2 ( V_2 -> V_5 + V_42 ) ;
if ( V_4 & V_115 )
return V_120 ;
if ( V_4 & V_114 )
return V_121 ;
if ( V_4 & V_113 )
return V_122 ;
return V_123 ;
}
}
void F_22 ( struct V_1 * V_2 )
{
T_1 V_4 ;
V_4 = F_2 ( V_2 -> V_5 + V_60 ) ;
V_4 |= V_57 ;
F_3 ( V_4 , V_2 -> V_5 + V_60 ) ;
}
void F_23 ( struct V_1 * V_2 )
{
T_1 V_4 ;
V_4 = V_124 | V_125 ;
F_3 ( V_4 , V_2 -> V_5 + V_43 ) ;
F_22 ( V_2 ) ;
V_4 = F_24 ( 3 ) | F_25 ( 0 ) |
V_126 ;
F_3 ( V_4 , V_2 -> V_5 + V_127 ) ;
V_4 = V_128 | F_26 ( 1 ) ;
F_3 ( V_4 , V_2 -> V_5 + V_129 ) ;
V_4 = F_2 ( V_2 -> V_5 + V_60 ) ;
V_4 &= ~ V_57 ;
F_3 ( V_4 , V_2 -> V_5 + V_60 ) ;
}
int F_27 ( struct V_1 * V_2 )
{
T_1 V_4 ;
if ( F_18 ( V_2 -> V_112 ) ) {
if ( F_21 ( V_2 -> V_112 ) )
return 0 ;
} else {
V_4 = F_2 ( V_2 -> V_5 + V_63 ) ;
if ( V_4 & V_130 )
return 0 ;
}
return - V_131 ;
}
void F_28 ( struct V_1 * V_2 )
{
T_1 V_4 ;
V_4 = F_2 ( V_2 -> V_5 + V_55 ) ;
V_4 &= ~ V_54 ;
F_3 ( V_4 , V_2 -> V_5 + V_55 ) ;
}
int F_29 ( struct V_1 * V_2 )
{
int V_4 ;
int V_132 = 0 ;
int V_106 = 0 ;
V_4 = F_2 ( V_2 -> V_5 + V_133 ) ;
V_4 |= V_134 ;
F_3 ( V_4 , V_2 -> V_5 + V_133 ) ;
V_4 = F_2 ( V_2 -> V_5 + V_43 ) ;
while ( ! ( V_4 & V_124 ) ) {
V_106 ++ ;
if ( V_110 < V_106 ) {
F_16 ( V_2 -> V_111 , L_2 ) ;
return - V_135 ;
}
V_4 = F_2 ( V_2 -> V_5 + V_43 ) ;
F_9 ( 10 , 11 ) ;
}
F_3 ( V_124 , V_2 -> V_5 + V_43 ) ;
V_4 = F_2 ( V_2 -> V_5 + V_43 ) ;
if ( V_4 & V_125 ) {
F_3 ( V_125 , V_2 -> V_5 + V_43 ) ;
return - V_136 ;
}
V_4 = F_2 ( V_2 -> V_5 + V_137 ) ;
if ( ( V_4 & V_138 ) != 0 ) {
F_16 ( V_2 -> V_111 , L_3 ,
V_4 & V_138 ) ;
return - V_136 ;
}
return V_132 ;
}
int F_30 ( struct V_1 * V_2 ,
unsigned int V_139 ,
unsigned char V_140 )
{
T_1 V_4 ;
int V_141 ;
int V_132 ;
for ( V_141 = 0 ; V_141 < 3 ; V_141 ++ ) {
V_4 = V_142 ;
F_3 ( V_4 , V_2 -> V_5 + V_143 ) ;
V_4 = F_31 ( V_139 ) ;
F_3 ( V_4 , V_2 -> V_5 + V_144 ) ;
V_4 = F_32 ( V_139 ) ;
F_3 ( V_4 , V_2 -> V_5 + V_145 ) ;
V_4 = F_33 ( V_139 ) ;
F_3 ( V_4 , V_2 -> V_5 + V_146 ) ;
V_4 = ( unsigned int ) V_140 ;
F_3 ( V_4 , V_2 -> V_5 + V_147 ) ;
V_4 = V_148 | V_149 ;
F_3 ( V_4 , V_2 -> V_5 + V_150 ) ;
V_132 = F_29 ( V_2 ) ;
if ( V_132 == 0 )
break;
else
F_34 ( V_2 -> V_111 , L_4 ,
V_151 ) ;
}
return V_132 ;
}
int F_35 ( struct V_1 * V_2 ,
unsigned int V_139 ,
unsigned char * V_140 )
{
T_1 V_4 ;
int V_141 ;
int V_132 ;
for ( V_141 = 0 ; V_141 < 3 ; V_141 ++ ) {
V_4 = V_142 ;
F_3 ( V_4 , V_2 -> V_5 + V_143 ) ;
V_4 = F_31 ( V_139 ) ;
F_3 ( V_4 , V_2 -> V_5 + V_144 ) ;
V_4 = F_32 ( V_139 ) ;
F_3 ( V_4 , V_2 -> V_5 + V_145 ) ;
V_4 = F_33 ( V_139 ) ;
F_3 ( V_4 , V_2 -> V_5 + V_146 ) ;
V_4 = V_148 | V_152 ;
F_3 ( V_4 , V_2 -> V_5 + V_150 ) ;
V_132 = F_29 ( V_2 ) ;
if ( V_132 == 0 )
break;
else
F_34 ( V_2 -> V_111 , L_4 ,
V_151 ) ;
}
V_4 = F_2 ( V_2 -> V_5 + V_147 ) ;
* V_140 = ( unsigned char ) ( V_4 & 0xff ) ;
return V_132 ;
}
int F_36 ( struct V_1 * V_2 ,
unsigned int V_139 ,
unsigned int V_153 ,
unsigned char V_140 [] )
{
T_1 V_4 ;
unsigned int V_154 ;
unsigned int V_155 ;
unsigned int V_156 ;
int V_141 ;
int V_132 = 0 ;
V_4 = V_142 ;
F_3 ( V_4 , V_2 -> V_5 + V_143 ) ;
V_154 = 0 ;
while ( V_154 < V_153 ) {
if ( ( V_153 - V_154 ) > 16 )
V_155 = 16 ;
else
V_155 = V_153 - V_154 ;
for ( V_141 = 0 ; V_141 < 3 ; V_141 ++ ) {
V_4 = F_31 ( V_139 + V_154 ) ;
F_3 ( V_4 , V_2 -> V_5 + V_144 ) ;
V_4 = F_32 ( V_139 + V_154 ) ;
F_3 ( V_4 , V_2 -> V_5 + V_145 ) ;
V_4 = F_33 ( V_139 + V_154 ) ;
F_3 ( V_4 , V_2 -> V_5 + V_146 ) ;
for ( V_156 = 0 ; V_156 < V_155 ;
V_156 ++ ) {
V_4 = V_140 [ V_154 + V_156 ] ;
F_3 ( V_4 , V_2 -> V_5 + V_147
+ 4 * V_156 ) ;
}
V_4 = F_37 ( V_155 ) |
V_148 | V_149 ;
F_3 ( V_4 , V_2 -> V_5 + V_150 ) ;
V_132 = F_29 ( V_2 ) ;
if ( V_132 == 0 )
break;
else
F_34 ( V_2 -> V_111 , L_4 ,
V_151 ) ;
}
V_154 += V_155 ;
}
return V_132 ;
}
int F_38 ( struct V_1 * V_2 ,
unsigned int V_139 ,
unsigned int V_153 ,
unsigned char V_140 [] )
{
T_1 V_4 ;
unsigned int V_154 ;
unsigned int V_155 ;
unsigned int V_156 ;
int V_141 ;
int V_132 = 0 ;
V_4 = V_142 ;
F_3 ( V_4 , V_2 -> V_5 + V_143 ) ;
V_154 = 0 ;
while ( V_154 < V_153 ) {
if ( ( V_153 - V_154 ) > 16 )
V_155 = 16 ;
else
V_155 = V_153 - V_154 ;
for ( V_141 = 0 ; V_141 < 3 ; V_141 ++ ) {
V_4 = F_31 ( V_139 + V_154 ) ;
F_3 ( V_4 , V_2 -> V_5 + V_144 ) ;
V_4 = F_32 ( V_139 + V_154 ) ;
F_3 ( V_4 , V_2 -> V_5 + V_145 ) ;
V_4 = F_33 ( V_139 + V_154 ) ;
F_3 ( V_4 , V_2 -> V_5 + V_146 ) ;
V_4 = F_37 ( V_155 ) |
V_148 | V_152 ;
F_3 ( V_4 , V_2 -> V_5 + V_150 ) ;
V_132 = F_29 ( V_2 ) ;
if ( V_132 == 0 )
break;
else
F_34 ( V_2 -> V_111 , L_4 ,
V_151 ) ;
}
for ( V_156 = 0 ; V_156 < V_155 ;
V_156 ++ ) {
V_4 = F_2 ( V_2 -> V_5 + V_147
+ 4 * V_156 ) ;
V_140 [ V_154 + V_156 ] =
( unsigned char ) V_4 ;
}
V_154 += V_155 ;
}
return V_132 ;
}
int F_39 ( struct V_1 * V_2 ,
unsigned int V_157 ,
unsigned int V_139 )
{
T_1 V_4 ;
int V_132 ;
V_4 = V_157 ;
F_3 ( V_4 , V_2 -> V_5 + V_144 ) ;
F_3 ( 0x0 , V_2 -> V_5 + V_145 ) ;
F_3 ( 0x0 , V_2 -> V_5 + V_146 ) ;
F_3 ( V_139 , V_2 -> V_5 + V_147 ) ;
V_4 = V_158 | V_159 |
V_149 ;
F_3 ( V_4 , V_2 -> V_5 + V_150 ) ;
V_132 = F_29 ( V_2 ) ;
if ( V_132 != 0 )
F_34 ( V_2 -> V_111 , L_4 , V_151 ) ;
return V_132 ;
}
int F_40 ( struct V_1 * V_2 ,
unsigned int V_157 ,
unsigned int V_139 ,
unsigned int * V_140 )
{
T_1 V_4 ;
int V_141 ;
int V_132 ;
for ( V_141 = 0 ; V_141 < 3 ; V_141 ++ ) {
V_4 = V_142 ;
F_3 ( V_4 , V_2 -> V_5 + V_143 ) ;
V_132 = F_39 ( V_2 , V_157 , V_139 ) ;
if ( V_132 != 0 )
continue;
V_4 = V_158 |
V_152 ;
F_3 ( V_4 , V_2 -> V_5 + V_150 ) ;
V_132 = F_29 ( V_2 ) ;
if ( V_132 == 0 )
break;
else
F_34 ( V_2 -> V_111 , L_4 ,
V_151 ) ;
}
if ( V_132 == 0 )
* V_140 = F_2 ( V_2 -> V_5 + V_147 ) ;
return V_132 ;
}
int F_41 ( struct V_1 * V_2 ,
unsigned int V_157 ,
unsigned int V_139 ,
unsigned int V_153 ,
unsigned char V_160 [] )
{
T_1 V_4 ;
unsigned int V_141 , V_161 ;
unsigned int V_156 ;
unsigned int V_162 = 0 ;
int V_132 = 0 ;
for ( V_141 = 0 ; V_141 < V_153 ; V_141 += 16 ) {
for ( V_161 = 0 ; V_161 < 3 ; V_161 ++ ) {
V_4 = V_142 ;
F_3 ( V_4 , V_2 -> V_5 + V_143 ) ;
V_4 = F_2 ( V_2 -> V_5 + V_133 ) ;
V_4 &= ~ V_163 ;
F_3 ( V_4 , V_2 -> V_5 + V_133 ) ;
if ( ! V_162 )
V_132 = F_39 ( V_2 ,
V_157 , V_139 + V_141 ) ;
else
V_162 = 0 ;
if ( V_132 == 0 ) {
V_4 = F_37 ( 16 ) |
V_158 |
V_152 ;
F_3 ( V_4 , V_2 -> V_5 +
V_150 ) ;
V_132 = F_29 ( V_2 ) ;
if ( V_132 == 0 )
break;
else
F_34 ( V_2 -> V_111 ,
L_4 ,
V_151 ) ;
}
V_4 = F_2 ( V_2 -> V_5 + V_164 ) ;
if ( V_4 == V_165 ||
V_4 == V_166 ) {
F_16 ( V_2 -> V_111 , L_5 , V_4 ) ;
V_162 = 1 ;
}
}
for ( V_156 = 0 ; V_156 < 16 ; V_156 ++ ) {
V_4 = F_2 ( V_2 -> V_5 + V_147
+ 4 * V_156 ) ;
V_160 [ V_141 + V_156 ] = ( unsigned char ) V_4 ;
}
}
return V_132 ;
}
void F_42 ( struct V_1 * V_2 , T_1 V_167 )
{
T_1 V_4 ;
V_4 = V_167 ;
if ( ( V_167 == V_168 ) || ( V_167 == V_169 ) )
F_3 ( V_4 , V_2 -> V_5 + V_170 ) ;
}
void F_43 ( struct V_1 * V_2 , T_1 * V_167 )
{
T_1 V_4 ;
V_4 = F_2 ( V_2 -> V_5 + V_170 ) ;
* V_167 = V_4 ;
}
void F_44 ( struct V_1 * V_2 , T_1 V_153 )
{
T_1 V_4 ;
V_4 = V_153 ;
F_3 ( V_4 , V_2 -> V_5 + V_171 ) ;
}
void F_45 ( struct V_1 * V_2 , T_1 * V_153 )
{
T_1 V_4 ;
V_4 = F_2 ( V_2 -> V_5 + V_171 ) ;
* V_153 = V_4 ;
}
void F_46 ( struct V_1 * V_2 , bool V_3 )
{
T_1 V_4 ;
if ( V_3 ) {
V_4 = F_2 ( V_2 -> V_5 + V_64 ) ;
V_4 |= V_172 ;
F_3 ( V_4 , V_2 -> V_5 + V_64 ) ;
} else {
V_4 = F_2 ( V_2 -> V_5 + V_64 ) ;
V_4 &= ~ V_172 ;
F_3 ( V_4 , V_2 -> V_5 + V_64 ) ;
}
}
void F_47 ( struct V_1 * V_2 ,
enum V_173 V_174 )
{
T_1 V_4 ;
switch ( V_174 ) {
case V_175 :
V_4 = V_176 | V_177 ;
F_3 ( V_4 , V_2 -> V_5 + V_178 ) ;
break;
case V_179 :
V_4 = V_176 | V_180 ;
F_3 ( V_4 , V_2 -> V_5 + V_178 ) ;
break;
case V_181 :
V_4 = V_182 | V_183 ;
F_3 ( V_4 , V_2 -> V_5 + V_178 ) ;
break;
case V_184 :
V_4 = V_182 | V_185 ;
F_3 ( V_4 , V_2 -> V_5 + V_178 ) ;
break;
case V_186 :
V_4 = V_176 |
V_187 |
V_188 ;
F_3 ( V_4 , V_2 -> V_5 + V_178 ) ;
break;
default:
break;
}
}
void F_48 ( struct V_1 * V_2 , T_1 V_189 )
{
T_1 V_4 ;
V_4 = F_2 ( V_2 -> V_5 + V_190 ) ;
V_4 &= ~ V_191 ;
V_4 |= V_189 << V_192 ;
F_3 ( V_4 , V_2 -> V_5 + V_190 ) ;
}
void F_49 ( struct V_1 * V_2 , T_1 V_189 )
{
T_1 V_4 ;
V_4 = F_2 ( V_2 -> V_5 + V_193 ) ;
V_4 &= ~ V_191 ;
V_4 |= V_189 << V_192 ;
F_3 ( V_4 , V_2 -> V_5 + V_193 ) ;
}
void F_50 ( struct V_1 * V_2 , T_1 V_189 )
{
T_1 V_4 ;
V_4 = F_2 ( V_2 -> V_5 + V_194 ) ;
V_4 &= ~ V_191 ;
V_4 |= V_189 << V_192 ;
F_3 ( V_4 , V_2 -> V_5 + V_194 ) ;
}
void F_51 ( struct V_1 * V_2 , T_1 V_189 )
{
T_1 V_4 ;
V_4 = F_2 ( V_2 -> V_5 + V_195 ) ;
V_4 &= ~ V_191 ;
V_4 |= V_189 << V_192 ;
F_3 ( V_4 , V_2 -> V_5 + V_195 ) ;
}
void F_52 ( struct V_1 * V_2 ,
T_1 V_196 )
{
T_1 V_4 ;
V_4 = V_196 ;
F_3 ( V_4 , V_2 -> V_5 + V_190 ) ;
}
void F_53 ( struct V_1 * V_2 ,
T_1 V_196 )
{
T_1 V_4 ;
V_4 = V_196 ;
F_3 ( V_4 , V_2 -> V_5 + V_193 ) ;
}
void F_54 ( struct V_1 * V_2 ,
T_1 V_196 )
{
T_1 V_4 ;
V_4 = V_196 ;
F_3 ( V_4 , V_2 -> V_5 + V_194 ) ;
}
void F_55 ( struct V_1 * V_2 ,
T_1 V_196 )
{
T_1 V_4 ;
V_4 = V_196 ;
F_3 ( V_4 , V_2 -> V_5 + V_195 ) ;
}
T_1 F_56 ( struct V_1 * V_2 )
{
T_1 V_4 ;
V_4 = F_2 ( V_2 -> V_5 + V_190 ) ;
return V_4 ;
}
T_1 F_57 ( struct V_1 * V_2 )
{
T_1 V_4 ;
V_4 = F_2 ( V_2 -> V_5 + V_193 ) ;
return V_4 ;
}
T_1 F_58 ( struct V_1 * V_2 )
{
T_1 V_4 ;
V_4 = F_2 ( V_2 -> V_5 + V_194 ) ;
return V_4 ;
}
T_1 F_59 ( struct V_1 * V_2 )
{
T_1 V_4 ;
V_4 = F_2 ( V_2 -> V_5 + V_195 ) ;
return V_4 ;
}
void F_60 ( struct V_1 * V_2 )
{
T_1 V_4 ;
V_4 = F_2 ( V_2 -> V_5 + V_70 ) ;
V_4 |= V_197 ;
F_3 ( V_4 , V_2 -> V_5 + V_70 ) ;
F_9 ( 10 , 20 ) ;
V_4 &= ~ V_197 ;
F_3 ( V_4 , V_2 -> V_5 + V_70 ) ;
}
void F_61 ( struct V_1 * V_2 )
{
T_1 V_4 ;
V_4 = V_198 | V_199 | V_200 ;
F_3 ( V_4 , V_2 -> V_5 + V_39 ) ;
V_4 = 0x0 ;
F_3 ( V_4 , V_2 -> V_5 + V_61 ) ;
V_4 = F_62 ( 4 ) | V_201 ;
F_3 ( V_4 , V_2 -> V_5 + V_62 ) ;
V_4 = 0x0 ;
F_3 ( V_4 , V_2 -> V_5 + V_63 ) ;
V_4 = F_63 ( 2 ) | F_64 ( 0 ) ;
F_3 ( V_4 , V_2 -> V_5 + V_202 ) ;
}
void F_65 ( struct V_1 * V_2 )
{
T_1 V_4 ;
V_4 = ( V_2 -> V_203 -> V_204 << V_205 ) |
( V_2 -> V_203 -> V_206 << V_207 ) |
( V_2 -> V_203 -> V_208 << V_209 ) ;
F_3 ( V_4 , V_2 -> V_5 + V_210 ) ;
V_4 = F_2 ( V_2 -> V_5 + V_211 ) ;
V_4 &= ~ V_212 ;
if ( V_2 -> V_203 -> V_213 )
V_4 |= V_214 ;
else
V_4 |= V_215 ;
F_3 ( V_4 , V_2 -> V_5 + V_211 ) ;
}
int F_66 ( struct V_1 * V_2 )
{
T_1 V_4 ;
V_4 = F_2 ( V_2 -> V_5 + V_61 ) ;
F_3 ( V_4 , V_2 -> V_5 + V_61 ) ;
V_4 = F_2 ( V_2 -> V_5 + V_61 ) ;
if ( ! ( V_4 & V_216 ) ) {
F_34 ( V_2 -> V_111 , L_6 ) ;
return - V_131 ;
}
V_4 = F_2 ( V_2 -> V_5 + V_62 ) ;
F_3 ( V_4 , V_2 -> V_5 + V_62 ) ;
V_4 = F_2 ( V_2 -> V_5 + V_62 ) ;
F_34 ( V_2 -> V_111 , L_7 ) ;
if ( V_4 & V_217 ) {
F_34 ( V_2 -> V_111 , L_8 ) ;
return - V_131 ;
}
return 0 ;
}
void F_67 ( struct V_1 * V_2 ,
enum V_218 type ,
T_1 V_219 ,
T_1 V_220 )
{
T_1 V_4 ;
if ( type == V_221 ) {
V_4 = F_2 ( V_2 -> V_5 + V_64 ) ;
V_4 |= V_222 ;
F_3 ( V_4 , V_2 -> V_5 + V_64 ) ;
V_4 = V_219 & 0xff ;
F_3 ( V_4 , V_2 -> V_5 + V_223 ) ;
V_4 = ( V_219 >> 8 ) & 0xff ;
F_3 ( V_4 , V_2 -> V_5 + V_224 ) ;
V_4 = ( V_219 >> 16 ) & 0xff ;
F_3 ( V_4 , V_2 -> V_5 + V_225 ) ;
V_4 = V_220 & 0xff ;
F_3 ( V_4 , V_2 -> V_5 + V_226 ) ;
V_4 = ( V_220 >> 8 ) & 0xff ;
F_3 ( V_4 , V_2 -> V_5 + V_227 ) ;
V_4 = ( V_220 >> 16 ) & 0xff ;
F_3 ( V_4 , V_2 -> V_5 + V_228 ) ;
} else {
V_4 = F_2 ( V_2 -> V_5 + V_64 ) ;
V_4 &= ~ V_222 ;
F_3 ( V_4 , V_2 -> V_5 + V_64 ) ;
F_3 ( 0x00 , V_2 -> V_5 + V_226 ) ;
F_3 ( 0x80 , V_2 -> V_5 + V_227 ) ;
F_3 ( 0x00 , V_2 -> V_5 + V_228 ) ;
}
}
void F_68 ( struct V_1 * V_2 , T_1 type )
{
T_1 V_4 ;
if ( type == V_229 ) {
V_4 = F_2 ( V_2 -> V_5 + V_230 ) ;
V_4 &= ~ V_231 ;
F_3 ( V_4 , V_2 -> V_5 + V_230 ) ;
} else {
V_4 = F_2 ( V_2 -> V_5 + V_230 ) ;
V_4 |= V_231 ;
F_3 ( V_4 , V_2 -> V_5 + V_230 ) ;
}
}
void F_69 ( struct V_1 * V_2 , bool V_3 )
{
T_1 V_4 ;
if ( V_3 ) {
V_4 = F_2 ( V_2 -> V_5 + V_75 ) ;
V_4 &= ~ V_232 ;
V_4 |= V_233 | V_234 ;
F_3 ( V_4 , V_2 -> V_5 + V_75 ) ;
} else {
V_4 = F_2 ( V_2 -> V_5 + V_75 ) ;
V_4 &= ~ V_232 ;
V_4 |= V_235 ;
F_3 ( V_4 , V_2 -> V_5 + V_75 ) ;
}
}
void F_70 ( struct V_1 * V_2 )
{
T_1 V_4 ;
V_4 = F_2 ( V_2 -> V_5 + V_6 ) ;
V_4 |= V_8 ;
F_3 ( V_4 , V_2 -> V_5 + V_6 ) ;
}
int F_71 ( struct V_1 * V_2 )
{
T_1 V_4 ;
V_4 = F_2 ( V_2 -> V_5 + V_63 ) ;
F_3 ( V_4 , V_2 -> V_5 + V_63 ) ;
V_4 = F_2 ( V_2 -> V_5 + V_63 ) ;
if ( ! ( V_4 & V_236 ) ) {
F_34 ( V_2 -> V_111 , L_9 ) ;
return - V_131 ;
}
return 0 ;
}
void F_72 ( struct V_1 * V_2 )
{
T_1 V_4 ;
V_4 = F_2 ( V_2 -> V_5 + V_55 ) ;
V_4 &= ~ ( V_49 | V_50 ) ;
V_4 |= V_49 ;
F_3 ( V_4 , V_2 -> V_5 + V_55 ) ;
V_4 = F_2 ( V_2 -> V_5 + V_230 ) ;
V_4 &= ~ V_237 ;
V_4 |= ( V_2 -> V_203 -> V_238 << 2 ) ;
F_3 ( V_4 , V_2 -> V_5 + V_230 ) ;
V_4 = F_2 ( V_2 -> V_5 + V_230 ) ;
V_4 &= ~ V_239 ;
V_4 |= ( V_2 -> V_203 -> V_240 << 1 ) ;
F_3 ( V_4 , V_2 -> V_5 + V_230 ) ;
V_4 = F_2 ( V_2 -> V_5 + V_230 ) ;
V_4 &= ~ V_241 ;
V_4 |= ( V_2 -> V_203 -> V_242 << 0 ) ;
F_3 ( V_4 , V_2 -> V_5 + V_230 ) ;
V_4 = V_243 | V_235 ;
F_3 ( V_4 , V_2 -> V_5 + V_75 ) ;
}
void F_73 ( struct V_1 * V_2 )
{
T_1 V_4 ;
V_4 = F_2 ( V_2 -> V_5 + V_178 ) ;
V_4 &= ~ V_182 ;
F_3 ( V_4 , V_2 -> V_5 + V_178 ) ;
}
void F_74 ( struct V_1 * V_2 )
{
T_1 V_4 ;
V_4 = F_2 ( V_2 -> V_5 + V_178 ) ;
V_4 |= V_182 ;
F_3 ( V_4 , V_2 -> V_5 + V_178 ) ;
}
