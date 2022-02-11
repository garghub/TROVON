static void F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
F_2 ( V_4 , V_2 -> V_5 + V_3 ) ;
}
static T_1 F_3 ( struct V_1 * V_2 , T_1 V_3 )
{
return F_4 ( V_2 -> V_5 + V_3 ) ;
}
static void F_5 ( struct V_6 * V_7 )
{
V_7 -> V_8 ++ ;
if ( V_7 -> V_8 == V_7 -> V_9 )
V_7 -> V_8 = 0 ;
}
static void F_6 ( struct V_6 * V_7 )
{
V_7 -> V_10 ++ ;
if ( V_7 -> V_10 == V_7 -> V_9 )
V_7 -> V_10 = 0 ;
}
static void F_7 ( struct V_1 * V_2 )
{
int V_11 ;
T_1 V_12 ;
for ( V_11 = 0 ; V_11 < V_13 ; V_11 += 4 )
V_12 = F_3 ( V_2 , ( V_14 + V_11 ) ) ;
}
struct V_15 * F_8 ( struct V_16 * V_17 ,
struct V_15 * V_18 )
{
struct V_1 * V_2 = F_9 ( V_17 ) ;
unsigned int V_19 ;
int V_20 ;
F_10 (cpu) {
struct V_21 * V_22 ;
T_2 V_23 ;
T_2 V_24 ;
T_2 V_25 ;
T_2 V_26 ;
V_22 = F_11 ( V_2 -> V_18 , V_20 ) ;
do {
V_19 = F_12 ( & V_22 -> V_27 ) ;
V_23 = V_22 -> V_23 ;
V_24 = V_22 -> V_24 ;
V_25 = V_22 -> V_25 ;
V_26 = V_22 -> V_26 ;
} while ( F_13 ( & V_22 -> V_27 , V_19 ) );
V_18 -> V_23 += V_23 ;
V_18 -> V_24 += V_24 ;
V_18 -> V_25 += V_25 ;
V_18 -> V_26 += V_26 ;
}
V_18 -> V_28 = V_17 -> V_18 . V_28 ;
V_18 -> V_29 = V_17 -> V_18 . V_29 ;
V_18 -> V_30 = V_17 -> V_18 . V_30 ;
return V_18 ;
}
static int F_14 ( T_1 V_31 )
{
return ( V_31 & V_32 ) ==
V_32 ;
}
static void F_15 ( struct V_1 * V_2 ,
struct V_33 * V_34 ,
int V_35 )
{
while ( V_35 > V_36 ) {
F_1 ( V_2 , F_16 ( V_34 -> V_37 ) ,
( V_36 <<
V_38 ) ) ;
V_35 -= V_36 ;
}
F_1 ( V_2 , F_16 ( V_34 -> V_37 ) ,
( V_35 << V_38 ) ) ;
}
static int F_17 ( struct V_1 * V_2 ,
struct V_33 * V_34 )
{
T_1 V_39 ;
V_39 = F_3 ( V_2 , F_18 ( V_34 -> V_37 ) ) ;
return V_39 & V_40 ;
}
static void F_19 ( struct V_1 * V_2 ,
struct V_33 * V_34 ,
int V_41 , int V_42 )
{
T_1 V_39 ;
if ( ( V_41 <= 0xff ) && ( V_42 <= 0xff ) ) {
V_39 = V_41 |
( V_42 << V_38 ) ;
F_1 ( V_2 , F_16 ( V_34 -> V_37 ) , V_39 ) ;
return;
}
while ( ( V_41 > 0 ) || ( V_42 > 0 ) ) {
if ( V_41 <= 0xff ) {
V_39 = V_41 ;
V_41 = 0 ;
} else {
V_39 = 0xff ;
V_41 -= 0xff ;
}
if ( V_42 <= 0xff ) {
V_39 |= V_42 << V_38 ;
V_42 = 0 ;
} else {
V_39 |= 0xff << V_38 ;
V_42 -= 0xff ;
}
F_1 ( V_2 , F_16 ( V_34 -> V_37 ) , V_39 ) ;
}
}
static struct V_43 *
F_20 ( struct V_33 * V_34 )
{
int V_44 = V_34 -> V_45 ;
V_34 -> V_45 = F_21 ( V_34 , V_44 ) ;
F_22 ( V_34 -> V_46 + V_34 -> V_45 ) ;
return V_34 -> V_46 + V_44 ;
}
static void F_23 ( struct V_1 * V_2 , int V_47 )
{
T_1 V_39 ;
V_39 = F_3 ( V_2 , V_48 ) ;
V_39 &= ~ V_49 ;
V_39 |= ( ( V_47 - V_50 ) / 2 ) <<
V_51 ;
F_1 ( V_2 , V_48 , V_39 ) ;
}
static void F_24 ( struct V_1 * V_2 ,
struct V_33 * V_34 ,
int V_3 )
{
T_1 V_39 ;
V_39 = F_3 ( V_2 , F_25 ( V_34 -> V_37 ) ) ;
V_39 &= ~ V_52 ;
V_39 |= F_26 ( V_3 >> 3 ) ;
F_1 ( V_2 , F_25 ( V_34 -> V_37 ) , V_39 ) ;
}
static void F_27 ( struct V_1 * V_2 ,
struct V_6 * V_7 ,
int V_53 )
{
T_1 V_39 ;
V_39 = V_53 ;
F_1 ( V_2 , F_28 ( V_7 -> V_37 ) , V_39 ) ;
}
static struct V_54 *
F_29 ( struct V_6 * V_7 )
{
int V_55 = V_7 -> V_45 ;
V_7 -> V_45 = F_21 ( V_7 , V_55 ) ;
return V_7 -> V_46 + V_55 ;
}
static void F_30 ( struct V_6 * V_7 )
{
if ( V_7 -> V_45 == 0 )
V_7 -> V_45 = V_7 -> V_56 - 1 ;
else
V_7 -> V_45 -- ;
}
static void F_31 ( struct V_1 * V_2 ,
struct V_33 * V_34 ,
int V_57 )
{
T_1 V_39 ;
V_39 = F_3 ( V_2 , F_32 ( V_34 -> V_37 ) ) ;
V_39 &= ~ V_58 ;
V_39 |= ( ( V_57 >> 3 ) << V_59 ) ;
F_1 ( V_2 , F_32 ( V_34 -> V_37 ) , V_39 ) ;
}
static void F_33 ( struct V_1 * V_2 ,
struct V_33 * V_34 )
{
T_1 V_39 ;
V_39 = F_3 ( V_2 , F_25 ( V_34 -> V_37 ) ) ;
V_39 &= ~ V_60 ;
F_1 ( V_2 , F_25 ( V_34 -> V_37 ) , V_39 ) ;
}
static void F_34 ( struct V_1 * V_2 )
{
int V_61 ;
T_1 V_62 ;
F_7 ( V_2 ) ;
V_62 = 0 ;
for ( V_61 = 0 ; V_61 < V_63 ; V_61 ++ ) {
struct V_6 * V_7 = & V_2 -> V_64 [ V_61 ] ;
if ( V_7 -> V_46 != NULL )
V_62 |= ( 1 << V_61 ) ;
}
F_1 ( V_2 , V_65 , V_62 ) ;
V_62 = 0 ;
for ( V_61 = 0 ; V_61 < V_66 ; V_61 ++ ) {
struct V_33 * V_34 = & V_2 -> V_67 [ V_61 ] ;
if ( V_34 -> V_46 != NULL )
V_62 |= ( 1 << V_61 ) ;
}
F_1 ( V_2 , V_68 , V_62 ) ;
}
static void F_35 ( struct V_1 * V_2 )
{
T_1 V_39 ;
int V_69 ;
V_39 = F_3 ( V_2 , V_68 ) & V_70 ;
if ( V_39 != 0 )
F_1 ( V_2 , V_68 ,
V_39 << V_71 ) ;
V_69 = 0 ;
do {
if ( V_69 ++ >= V_72 ) {
F_36 ( V_2 -> V_17 ,
L_1 ,
V_39 ) ;
break;
}
F_37 ( 1 ) ;
V_39 = F_3 ( V_2 , V_68 ) ;
} while ( V_39 & 0xff );
V_39 = ( F_3 ( V_2 , V_65 ) ) & V_73 ;
if ( V_39 != 0 )
F_1 ( V_2 , V_65 ,
( V_39 << V_74 ) ) ;
V_69 = 0 ;
do {
if ( V_69 ++ >= V_75 ) {
F_36 ( V_2 -> V_17 ,
L_2 ,
V_39 ) ;
break;
}
F_37 ( 1 ) ;
V_39 = F_3 ( V_2 , V_65 ) ;
} while ( V_39 & 0xff );
V_69 = 0 ;
do {
if ( V_69 ++ >= V_76 ) {
F_36 ( V_2 -> V_17 ,
L_3 ,
V_39 ) ;
break;
}
F_37 ( 1 ) ;
V_39 = F_3 ( V_2 , V_77 ) ;
} while ( ! ( V_39 & V_78 ) &&
( V_39 & V_79 ) );
F_38 ( 200 ) ;
}
static void F_39 ( struct V_1 * V_2 )
{
T_1 V_39 ;
V_39 = F_3 ( V_2 , V_48 ) ;
V_39 |= V_80 ;
F_1 ( V_2 , V_48 , V_39 ) ;
}
static void F_40 ( struct V_1 * V_2 )
{
T_1 V_39 ;
V_39 = F_3 ( V_2 , V_48 ) ;
V_39 &= ~ V_80 ;
F_1 ( V_2 , V_48 , V_39 ) ;
F_38 ( 200 ) ;
}
static void F_41 ( struct V_1 * V_2 , int V_61 )
{
int V_3 ;
T_1 V_39 ;
if ( V_61 == - 1 ) {
V_39 = 0 ;
} else {
V_39 = 0x1 | ( V_61 << 1 ) ;
V_39 |= ( V_39 << 24 ) | ( V_39 << 16 ) | ( V_39 << 8 ) ;
}
for ( V_3 = 0 ; V_3 <= 0xc ; V_3 += 4 )
F_1 ( V_2 , V_81 + V_3 , V_39 ) ;
}
static void F_42 ( struct V_1 * V_2 , int V_61 )
{
int V_3 ;
T_1 V_39 ;
if ( V_61 == - 1 ) {
V_39 = 0 ;
} else {
V_39 = 0x1 | ( V_61 << 1 ) ;
V_39 |= ( V_39 << 24 ) | ( V_39 << 16 ) | ( V_39 << 8 ) ;
}
for ( V_3 = 0 ; V_3 <= 0xfc ; V_3 += 4 )
F_1 ( V_2 , V_82 + V_3 , V_39 ) ;
}
static void F_43 ( struct V_1 * V_2 , int V_61 )
{
int V_3 ;
T_1 V_39 ;
if ( V_61 == - 1 ) {
memset ( V_2 -> V_83 , 0 , sizeof( V_2 -> V_83 ) ) ;
V_39 = 0 ;
} else {
memset ( V_2 -> V_83 , 1 , sizeof( V_2 -> V_83 ) ) ;
V_39 = 0x1 | ( V_61 << 1 ) ;
V_39 |= ( V_39 << 24 ) | ( V_39 << 16 ) | ( V_39 << 8 ) ;
}
for ( V_3 = 0 ; V_3 <= 0xfc ; V_3 += 4 )
F_1 ( V_2 , V_84 + V_3 , V_39 ) ;
}
static void F_44 ( struct V_1 * V_2 )
{
int V_20 ;
int V_61 ;
T_1 V_39 ;
F_1 ( V_2 , V_85 , 0 ) ;
F_1 ( V_2 , V_86 , 0 ) ;
F_1 ( V_2 , V_87 , 0 ) ;
F_1 ( V_2 , V_88 , 0 ) ;
F_1 ( V_2 , V_89 , 0 ) ;
F_1 ( V_2 , V_90 , 0 ) ;
F_1 ( V_2 , V_91 , 0 ) ;
F_1 ( V_2 , V_92 , 0x20 ) ;
for ( V_20 = 0 ; V_20 < V_93 ; V_20 ++ )
F_1 ( V_2 , F_45 ( V_20 ) ,
( V_94 |
V_95 ) ) ;
F_1 ( V_2 , V_96 , V_97 ) ;
F_1 ( V_2 , V_98 , V_99 ) ;
F_1 ( V_2 , V_100 , 0 ) ;
for ( V_61 = 0 ; V_61 < V_63 ; V_61 ++ ) {
F_1 ( V_2 , F_46 ( V_61 ) , 0 ) ;
F_1 ( V_2 , F_47 ( V_61 ) , 0 ) ;
}
F_1 ( V_2 , V_98 , 0 ) ;
F_1 ( V_2 , V_96 , 0 ) ;
V_39 = V_101 ;
F_1 ( V_2 , V_102 , V_39 ) ;
V_39 = F_48 ( V_103 ) ;
F_1 ( V_2 , V_104 , V_39 ) ;
V_39 = 0 ;
F_1 ( V_2 , V_105 , V_39 ) ;
F_1 ( V_2 , V_106 , 64 ) ;
V_39 = 0 ;
V_39 |= F_49 ( V_107 ) ;
V_39 |= F_50 ( V_107 ) ;
V_39 |= V_108 | V_109 ;
#if F_51 ( V_110 )
V_39 |= V_111 ;
#endif
F_1 ( V_2 , V_112 , V_39 ) ;
V_39 = F_3 ( V_2 , V_113 ) ;
V_39 &= ~ V_114 ;
F_1 ( V_2 , V_113 , V_39 ) ;
if ( V_2 -> V_115 ) {
V_39 = F_3 ( V_2 , V_116 ) ;
V_39 &= ~ ( V_117 |
V_118 |
V_119 ) ;
V_39 |= V_120 |
V_121 |
V_122 ;
F_1 ( V_2 , V_116 , V_39 ) ;
V_39 = F_3 ( V_2 , V_123 ) ;
V_39 |= V_124 ;
F_1 ( V_2 , V_123 , V_39 ) ;
} else {
V_39 = F_3 ( V_2 , V_116 ) ;
V_39 &= ~ ( V_120 |
V_121 |
V_122 ) ;
F_1 ( V_2 , V_116 , V_39 ) ;
}
F_41 ( V_2 , - 1 ) ;
F_42 ( V_2 , - 1 ) ;
F_43 ( V_2 , - 1 ) ;
F_1 ( V_2 , V_91 ,
( V_125
| V_126 ) ) ;
}
static void F_52 ( struct V_1 * V_2 , int V_127 )
{
T_1 V_39 , V_9 , V_128 ;
int V_61 ;
V_128 = V_127 * 8 ;
if ( V_128 > V_129 )
V_128 = V_129 ;
V_39 = F_3 ( V_2 , V_130 ) ;
V_39 &= ~ V_129 ;
V_39 |= V_128 ;
F_1 ( V_2 , V_130 , V_39 ) ;
V_39 = F_3 ( V_2 , V_131 ) ;
V_9 = V_39 & V_132 ;
if ( V_9 < V_128 ) {
V_9 = V_128 ;
V_39 &= ~ V_132 ;
V_39 |= V_9 ;
F_1 ( V_2 , V_131 , V_39 ) ;
}
for ( V_61 = 0 ; V_61 < V_63 ; V_61 ++ ) {
V_39 = F_3 ( V_2 , F_53 ( V_61 ) ) ;
V_9 = V_39 & V_133 ;
if ( V_9 < V_128 ) {
V_9 = V_128 ;
V_39 &= ~ V_133 ;
V_39 |= V_9 ;
F_1 ( V_2 , F_53 ( V_61 ) , V_39 ) ;
}
}
}
static void F_54 ( struct V_1 * V_2 , T_3 V_134 ,
int V_61 )
{
unsigned int V_135 ;
unsigned int V_136 ;
unsigned int V_137 ;
V_134 = ( 0xf & V_134 ) ;
V_136 = ( V_134 / 4 ) * 4 ;
V_137 = V_134 % 4 ;
V_135 = F_3 ( V_2 , ( V_81 + V_136 ) ) ;
if ( V_61 == - 1 ) {
V_135 &= ~ ( 0xff << ( 8 * V_137 ) ) ;
} else {
V_135 &= ~ ( 0xff << ( 8 * V_137 ) ) ;
V_135 |= ( ( 0x01 | ( V_61 << 1 ) ) << ( 8 * V_137 ) ) ;
}
F_1 ( V_2 , ( V_81 + V_136 ) , V_135 ) ;
}
static void F_55 ( struct V_1 * V_2 , unsigned char * V_138 ,
int V_61 )
{
unsigned int V_139 ;
unsigned int V_140 ;
if ( V_61 != - 1 ) {
V_140 = ( V_138 [ 4 ] << 8 ) | ( V_138 [ 5 ] ) ;
V_139 = ( V_138 [ 0 ] << 24 ) | ( V_138 [ 1 ] << 16 ) |
( V_138 [ 2 ] << 8 ) | ( V_138 [ 3 ] << 0 ) ;
F_1 ( V_2 , V_141 , V_140 ) ;
F_1 ( V_2 , V_142 , V_139 ) ;
}
F_54 ( V_2 , V_138 [ 5 ] , V_61 ) ;
}
static void F_56 ( struct V_1 * V_2 ,
struct V_33 * V_34 , T_1 V_143 )
{
F_1 ( V_2 , F_57 ( V_34 -> V_37 ) ,
V_143 | F_58 ( 0 ) ) ;
V_34 -> V_144 = V_143 ;
}
static void F_59 ( struct V_1 * V_2 ,
struct V_33 * V_34 , T_1 V_143 )
{
T_1 V_39 ;
unsigned long V_145 ;
V_145 = F_60 ( V_2 -> V_146 ) ;
V_39 = ( V_145 / 1000000 ) * V_143 ;
F_1 ( V_2 , F_61 ( V_34 -> V_37 ) , V_39 ) ;
V_34 -> V_147 = V_143 ;
}
static void F_62 ( struct V_1 * V_2 ,
struct V_6 * V_7 , T_1 V_143 )
{
T_1 V_39 ;
V_39 = F_3 ( V_2 , F_63 ( V_7 -> V_37 ) ) ;
V_39 &= ~ V_148 ;
V_39 |= F_64 ( V_143 ) ;
F_1 ( V_2 , F_63 ( V_7 -> V_37 ) , V_39 ) ;
V_7 -> V_149 = V_143 ;
}
static void F_65 ( struct V_43 * V_44 ,
T_1 V_150 , T_1 V_151 )
{
V_44 -> V_152 = V_151 ;
V_44 -> V_153 = V_150 ;
}
static void F_66 ( struct V_1 * V_2 ,
struct V_6 * V_7 ,
int V_154 )
{
T_1 V_39 ;
while ( V_154 > 0xff ) {
V_39 = 0xff << V_155 ;
F_1 ( V_2 , F_28 ( V_7 -> V_37 ) , V_39 ) ;
V_154 = V_154 - 0xff ;
}
V_39 = V_154 << V_155 ;
F_1 ( V_2 , F_28 ( V_7 -> V_37 ) , V_39 ) ;
}
static int F_67 ( struct V_1 * V_2 ,
struct V_6 * V_7 )
{
T_1 V_39 ;
int V_154 ;
V_39 = F_3 ( V_2 , F_68 ( V_7 -> V_37 ) ) ;
V_154 = ( V_39 & V_156 ) >>
V_157 ;
return V_154 ;
}
static int F_69 ( struct V_1 * V_2 ,
struct V_6 * V_7 )
{
int V_154 ;
V_154 = F_67 ( V_2 , V_7 ) ;
if ( V_154 )
F_66 ( V_2 , V_7 , V_154 ) ;
return V_154 ;
}
static T_1 F_70 ( int V_158 , int V_159 ,
int V_160 , int V_161 )
{
T_1 V_162 ;
V_162 = V_158 << V_163 ;
V_162 |= V_160 << V_164 ;
if ( V_159 == F_71 ( V_165 ) )
V_162 |= V_166 ;
else
V_162 |= V_167 ;
if ( V_161 == V_168 )
V_162 |= V_169 ;
else if ( V_161 == V_170 )
V_162 |= V_171 | V_169 ;
else
V_162 |= V_172 ;
return V_162 ;
}
static void F_72 ( struct V_1 * V_2 ,
struct V_43 * V_44 )
{
T_1 V_31 = V_44 -> V_31 ;
if ( ! F_14 ( V_31 ) ) {
F_73 ( V_2 -> V_17 ,
L_4 ,
V_31 , V_44 -> V_173 ) ;
return;
}
switch ( V_31 & V_174 ) {
case V_175 :
F_73 ( V_2 -> V_17 , L_5 ,
V_31 , V_44 -> V_173 ) ;
break;
case V_176 :
F_73 ( V_2 -> V_17 , L_6 ,
V_31 , V_44 -> V_173 ) ;
break;
case V_177 :
F_73 ( V_2 -> V_17 , L_7 ,
V_31 , V_44 -> V_173 ) ;
break;
case V_178 :
F_73 ( V_2 -> V_17 , L_8 ,
V_31 , V_44 -> V_173 ) ;
break;
}
}
static void F_74 ( struct V_1 * V_2 , T_1 V_31 ,
struct V_179 * V_180 )
{
if ( ( V_31 & V_181 ) &&
( V_31 & V_182 ) ) {
V_180 -> V_183 = 0 ;
V_180 -> V_184 = V_185 ;
return;
}
V_180 -> V_184 = V_186 ;
}
static struct V_6 * F_75 ( struct V_1 * V_2 ,
T_1 V_187 )
{
int V_61 = F_76 ( V_187 ) - 1 ;
return & V_2 -> V_64 [ V_61 ] ;
}
static void F_77 ( struct V_1 * V_2 ,
struct V_6 * V_7 , int V_188 )
{
int V_11 ;
for ( V_11 = 0 ; V_11 < V_188 ; V_11 ++ ) {
struct V_54 * V_55 = V_7 -> V_46 +
V_7 -> V_8 ;
struct V_179 * V_180 = V_7 -> V_189 [ V_7 -> V_8 ] ;
F_5 ( V_7 ) ;
if ( ! F_78 ( V_7 , V_55 -> V_153 ) )
F_79 ( V_2 -> V_17 -> V_17 . V_190 ,
V_55 -> V_153 ,
V_55 -> V_173 , V_191 ) ;
if ( ! V_180 )
continue;
F_80 ( V_180 ) ;
}
}
static void F_81 ( struct V_1 * V_2 ,
struct V_6 * V_7 )
{
struct V_192 * V_193 = F_82 ( V_2 -> V_17 , V_7 -> V_37 ) ;
int V_194 ;
V_194 = F_69 ( V_2 , V_7 ) ;
if ( ! V_194 )
return;
F_77 ( V_2 , V_7 , V_194 ) ;
V_7 -> V_69 -= V_194 ;
if ( F_83 ( V_193 ) ) {
if ( V_7 -> V_69 <= V_7 -> V_195 )
F_84 ( V_193 ) ;
}
}
static void * F_85 ( const struct V_1 * V_2 )
{
if ( F_86 ( V_2 -> V_196 <= V_197 ) )
return F_87 ( V_2 -> V_196 ) ;
else
return F_88 ( V_2 -> V_196 , V_198 ) ;
}
static void F_89 ( const struct V_1 * V_2 , void * V_4 )
{
if ( F_86 ( V_2 -> V_196 <= V_197 ) )
F_90 ( V_4 ) ;
else
F_91 ( V_4 ) ;
}
static int F_92 ( struct V_1 * V_2 ,
struct V_43 * V_44 )
{
T_4 V_150 ;
void * V_4 ;
V_4 = F_85 ( V_2 ) ;
if ( ! V_4 )
return - V_199 ;
V_150 = F_93 ( V_2 -> V_17 -> V_17 . V_190 , V_4 ,
F_94 ( V_2 -> V_200 ) ,
V_201 ) ;
if ( F_95 ( F_96 ( V_2 -> V_17 -> V_17 . V_190 , V_150 ) ) ) {
F_89 ( V_2 , V_4 ) ;
return - V_199 ;
}
F_65 ( V_44 , V_150 , ( T_1 ) V_4 ) ;
return 0 ;
}
static T_1 F_97 ( struct V_1 * V_2 , struct V_179 * V_180 )
{
if ( V_180 -> V_184 == V_202 ) {
int V_160 = 0 ;
T_5 V_159 = F_98 ( V_180 ) ;
T_3 V_161 ;
if ( V_159 == F_71 ( V_165 ) ) {
struct V_203 * V_204 = F_99 ( V_180 ) ;
V_160 = V_204 -> V_205 ;
V_161 = V_204 -> V_206 ;
} else if ( V_159 == F_71 ( V_207 ) ) {
struct V_208 * V_209 = F_100 ( V_180 ) ;
if ( F_101 ( V_180 ) > 0 )
V_160 = ( F_101 ( V_180 ) >> 2 ) ;
V_161 = V_209 -> V_210 ;
} else
return V_172 ;
return F_70 ( F_102 ( V_180 ) ,
V_159 , V_160 , V_161 ) ;
}
return V_172 ;
}
static struct V_33 * F_103 ( struct V_1 * V_2 ,
T_1 V_187 )
{
int V_61 = F_76 ( V_187 >> 8 ) - 1 ;
return ( V_61 < 0 || V_61 >= V_66 ) ? NULL : & V_2 -> V_67 [ V_61 ] ;
}
static void F_104 ( struct V_1 * V_2 ,
struct V_33 * V_34 )
{
int V_41 , V_11 ;
V_41 = F_17 ( V_2 , V_34 ) ;
for ( V_11 = 0 ; V_11 < V_34 -> V_9 ; V_11 ++ ) {
struct V_43 * V_44 = V_34 -> V_46 + V_11 ;
void * V_4 = ( void * ) V_44 -> V_152 ;
F_89 ( V_2 , V_4 ) ;
F_79 ( V_2 -> V_17 -> V_17 . V_190 , V_44 -> V_153 ,
F_94 ( V_2 -> V_200 ) , V_201 ) ;
}
if ( V_41 )
F_19 ( V_2 , V_34 , V_41 , V_41 ) ;
}
static int F_105 ( struct V_1 * V_2 , int V_211 ,
struct V_33 * V_34 )
{
struct V_16 * V_17 = V_2 -> V_17 ;
int V_41 ;
T_1 V_212 = 0 ;
T_1 V_213 = 0 ;
V_41 = F_17 ( V_2 , V_34 ) ;
if ( V_211 > V_41 )
V_211 = V_41 ;
V_41 = 0 ;
while ( V_41 < V_211 ) {
struct V_43 * V_44 = F_20 ( V_34 ) ;
struct V_179 * V_180 ;
unsigned char * V_4 ;
T_4 V_150 ;
T_1 V_214 ;
int V_24 , V_215 ;
V_41 ++ ;
V_214 = V_44 -> V_31 ;
V_24 = V_44 -> V_173 - ( V_216 + V_50 ) ;
V_4 = ( unsigned char * ) V_44 -> V_152 ;
V_150 = V_44 -> V_153 ;
if ( ! F_14 ( V_214 ) ||
( V_214 & V_217 ) ) {
V_218:
V_17 -> V_18 . V_28 ++ ;
F_72 ( V_2 , V_44 ) ;
continue;
}
if ( V_24 <= V_219 ) {
V_180 = F_106 ( V_17 , V_24 ) ;
if ( F_95 ( ! V_180 ) )
goto V_218;
F_107 ( V_17 -> V_17 . V_190 ,
V_44 -> V_153 ,
V_50 + V_220 ,
V_24 ,
V_201 ) ;
memcpy ( F_108 ( V_180 , V_24 ) ,
V_4 + V_50 + V_220 ,
V_24 ) ;
V_180 -> V_206 = F_109 ( V_180 , V_17 ) ;
F_74 ( V_2 , V_214 , V_180 ) ;
F_110 ( & V_2 -> V_221 , V_180 ) ;
V_212 ++ ;
V_213 += V_24 ;
continue;
}
V_215 = F_92 ( V_2 , V_44 ) ;
if ( V_215 ) {
F_73 ( V_17 , L_9 ) ;
V_34 -> V_222 ++ ;
goto V_218;
}
V_180 = F_111 ( V_4 , V_2 -> V_196 > V_197 ? 0 : V_2 -> V_196 ) ;
if ( ! V_180 )
goto V_218;
F_79 ( V_17 -> V_17 . V_190 , V_150 ,
F_94 ( V_2 -> V_200 ) , V_201 ) ;
V_212 ++ ;
V_213 += V_24 ;
F_112 ( V_180 , V_50 + V_220 ) ;
F_108 ( V_180 , V_24 ) ;
V_180 -> V_206 = F_109 ( V_180 , V_17 ) ;
F_74 ( V_2 , V_214 , V_180 ) ;
F_110 ( & V_2 -> V_221 , V_180 ) ;
}
if ( V_212 ) {
struct V_21 * V_18 = F_113 ( V_2 -> V_18 ) ;
F_114 ( & V_18 -> V_27 ) ;
V_18 -> V_23 += V_212 ;
V_18 -> V_24 += V_213 ;
F_115 ( & V_18 -> V_27 ) ;
}
F_19 ( V_2 , V_34 , V_41 , V_41 ) ;
return V_41 ;
}
static inline void
F_116 ( struct V_179 * V_180 ,
struct V_1 * V_2 , struct V_6 * V_7 )
{
struct V_54 * V_55 ;
int V_223 = F_117 ( V_180 ) + F_118 ( V_180 ) ;
V_7 -> V_189 [ V_7 -> V_10 ] = NULL ;
V_55 = F_29 ( V_7 ) ;
V_55 -> V_173 = V_223 ;
V_55 -> V_162 = F_97 ( V_2 , V_180 ) ;
V_55 -> V_162 |= V_224 ;
V_55 -> V_153 = V_7 -> V_225 +
V_7 -> V_10 * V_226 ;
F_6 ( V_7 ) ;
}
static inline int
F_119 ( struct V_16 * V_17 , struct V_6 * V_7 ,
struct V_179 * V_180 , char * V_4 , int V_9 ,
bool V_227 , bool V_228 )
{
struct V_54 * V_55 ;
V_55 = F_29 ( V_7 ) ;
V_55 -> V_173 = V_9 ;
V_55 -> V_153 = F_93 ( V_17 -> V_17 . V_190 , V_4 ,
V_9 , V_191 ) ;
if ( F_95 ( F_96 ( V_17 -> V_17 . V_190 ,
V_55 -> V_153 ) ) ) {
F_30 ( V_7 ) ;
return - V_199 ;
}
V_55 -> V_162 = 0 ;
V_7 -> V_189 [ V_7 -> V_10 ] = NULL ;
if ( V_227 ) {
V_55 -> V_162 = V_229 ;
if ( V_228 )
V_7 -> V_189 [ V_7 -> V_10 ] = V_180 ;
}
F_6 ( V_7 ) ;
return 0 ;
}
static int F_120 ( struct V_179 * V_180 , struct V_16 * V_17 ,
struct V_6 * V_7 )
{
int V_230 , V_231 ;
int V_232 = 0 ;
struct V_1 * V_2 = F_9 ( V_17 ) ;
struct V_233 V_234 ;
int V_223 = F_117 ( V_180 ) + F_118 ( V_180 ) ;
int V_11 ;
if ( ( V_7 -> V_69 + F_121 ( V_180 ) ) >= V_7 -> V_9 )
return 0 ;
if ( F_122 ( V_180 ) < ( F_117 ( V_180 ) + F_118 ( V_180 ) ) ) {
F_123 ( L_10 ) ;
return 0 ;
}
F_124 ( V_180 , & V_234 ) ;
V_230 = V_180 -> V_235 - V_223 ;
while ( V_230 > 0 ) {
char * V_236 ;
V_231 = F_125 ( int , F_126 ( V_180 ) -> V_237 , V_230 ) ;
V_230 -= V_231 ;
V_232 ++ ;
V_236 = V_7 -> V_238 + V_7 -> V_10 * V_226 ;
F_127 ( V_180 , V_236 , & V_234 , V_231 , V_230 == 0 ) ;
F_116 ( V_180 , V_2 , V_7 ) ;
while ( V_231 > 0 ) {
int V_9 ;
V_232 ++ ;
V_9 = F_125 ( int , V_234 . V_9 , V_231 ) ;
if ( F_119 ( V_17 , V_7 , V_180 ,
V_234 . V_4 , V_9 ,
V_9 == V_231 ,
V_230 == 0 ) )
goto V_239;
V_231 -= V_9 ;
F_128 ( V_180 , & V_234 , V_9 ) ;
}
}
return V_232 ;
V_239:
for ( V_11 = V_232 - 1 ; V_11 >= 0 ; V_11 -- ) {
struct V_54 * V_55 = V_7 -> V_46 + V_11 ;
if ( ! F_78 ( V_7 , V_55 -> V_153 ) )
F_79 ( V_2 -> V_17 -> V_17 . V_190 ,
V_55 -> V_153 ,
V_55 -> V_173 ,
V_191 ) ;
F_30 ( V_7 ) ;
}
return 0 ;
}
static int F_129 ( struct V_1 * V_2 , struct V_179 * V_180 ,
struct V_6 * V_7 )
{
struct V_54 * V_55 ;
int V_11 , V_240 = F_126 ( V_180 ) -> V_240 ;
for ( V_11 = 0 ; V_11 < V_240 ; V_11 ++ ) {
T_6 * V_241 = & F_126 ( V_180 ) -> V_242 [ V_11 ] ;
void * V_138 = F_130 ( V_241 -> V_243 . V_244 ) + V_241 -> V_245 ;
V_55 = F_29 ( V_7 ) ;
V_55 -> V_173 = V_241 -> V_9 ;
V_55 -> V_153 =
F_93 ( V_2 -> V_17 -> V_17 . V_190 , V_138 ,
V_55 -> V_173 , V_191 ) ;
if ( F_96 ( V_2 -> V_17 -> V_17 . V_190 ,
V_55 -> V_153 ) ) {
F_30 ( V_7 ) ;
goto error;
}
if ( V_11 == V_240 - 1 ) {
V_55 -> V_162 = V_229 | V_246 ;
V_7 -> V_189 [ V_7 -> V_10 ] = V_180 ;
} else {
V_55 -> V_162 = 0 ;
V_7 -> V_189 [ V_7 -> V_10 ] = NULL ;
}
F_6 ( V_7 ) ;
}
return 0 ;
error:
for ( V_11 = V_11 - 1 ; V_11 >= 0 ; V_11 -- ) {
V_55 = V_7 -> V_46 + V_11 ;
F_79 ( V_2 -> V_17 -> V_17 . V_190 ,
V_55 -> V_153 ,
V_55 -> V_173 ,
V_191 ) ;
F_30 ( V_7 ) ;
}
return - V_199 ;
}
static int F_131 ( struct V_179 * V_180 , struct V_16 * V_17 )
{
struct V_1 * V_2 = F_9 ( V_17 ) ;
T_7 V_247 = F_132 ( V_180 ) ;
struct V_6 * V_7 = & V_2 -> V_64 [ V_247 ] ;
struct V_54 * V_55 ;
int V_235 = V_180 -> V_235 ;
int V_242 = 0 ;
T_1 V_248 ;
if ( ! F_133 ( V_17 ) )
goto V_249;
if ( F_134 ( V_180 ) ) {
V_242 = F_120 ( V_180 , V_17 , V_7 ) ;
goto V_249;
}
V_242 = F_126 ( V_180 ) -> V_240 + 1 ;
V_55 = F_29 ( V_7 ) ;
V_248 = F_97 ( V_2 , V_180 ) ;
V_55 -> V_173 = F_122 ( V_180 ) ;
V_55 -> V_153 = F_93 ( V_17 -> V_17 . V_190 , V_180 -> V_4 ,
V_55 -> V_173 ,
V_191 ) ;
if ( F_95 ( F_96 ( V_17 -> V_17 . V_190 ,
V_55 -> V_153 ) ) ) {
F_30 ( V_7 ) ;
V_242 = 0 ;
goto V_249;
}
if ( V_242 == 1 ) {
V_248 |= V_250 ;
V_55 -> V_162 = V_248 ;
V_7 -> V_189 [ V_7 -> V_10 ] = V_180 ;
F_6 ( V_7 ) ;
} else {
V_248 |= V_224 ;
V_7 -> V_189 [ V_7 -> V_10 ] = NULL ;
F_6 ( V_7 ) ;
V_55 -> V_162 = V_248 ;
if ( F_129 ( V_2 , V_180 , V_7 ) ) {
F_79 ( V_17 -> V_17 . V_190 ,
V_55 -> V_153 ,
V_55 -> V_173 ,
V_191 ) ;
F_30 ( V_7 ) ;
V_242 = 0 ;
goto V_249;
}
}
V_249:
if ( V_242 > 0 ) {
struct V_21 * V_18 = F_113 ( V_2 -> V_18 ) ;
struct V_192 * V_193 = F_82 ( V_17 , V_247 ) ;
V_7 -> V_69 += V_242 ;
F_27 ( V_2 , V_7 , V_242 ) ;
if ( V_7 -> V_69 >= V_7 -> V_251 )
F_135 ( V_193 ) ;
F_114 ( & V_18 -> V_27 ) ;
V_18 -> V_25 ++ ;
V_18 -> V_26 += V_235 ;
F_115 ( & V_18 -> V_27 ) ;
} else {
V_17 -> V_18 . V_30 ++ ;
F_80 ( V_180 ) ;
}
return V_252 ;
}
static void F_136 ( struct V_1 * V_2 ,
struct V_6 * V_7 )
{
int V_194 = V_7 -> V_69 ;
F_77 ( V_2 , V_7 , V_194 ) ;
V_7 -> V_69 = 0 ;
V_7 -> V_10 = 0 ;
V_7 -> V_8 = 0 ;
}
static void F_137 ( struct V_1 * V_2 , T_1 V_253 )
{
struct V_6 * V_7 ;
struct V_192 * V_193 ;
while ( V_253 ) {
V_7 = F_75 ( V_2 , V_253 ) ;
V_193 = F_82 ( V_2 -> V_17 , V_7 -> V_37 ) ;
F_138 ( V_193 , F_139 () ) ;
if ( V_7 -> V_69 )
F_81 ( V_2 , V_7 ) ;
F_140 ( V_193 ) ;
V_253 &= ~ ( ( 1 << V_7 -> V_37 ) ) ;
}
}
static int F_141 ( unsigned char * V_138 )
{
int V_254 = 0 ;
int V_11 ;
for ( V_11 = 0 ; V_11 < V_255 ; V_11 ++ ) {
int V_256 ;
V_254 = ( V_254 ^ V_138 [ V_11 ] ) << 8 ;
for ( V_256 = 7 ; V_256 >= 0 ; V_256 -- ) {
if ( V_254 & ( 0x100 << V_256 ) )
V_254 ^= 0x107 << V_256 ;
}
}
return V_254 ;
}
static void F_142 ( struct V_1 * V_2 ,
unsigned char V_257 ,
int V_61 )
{
unsigned int V_258 ;
unsigned int V_136 ;
unsigned int V_137 ;
V_136 = ( V_257 / 4 ) ;
V_137 = V_257 % 4 ;
V_258 = F_3 ( V_2 , ( V_82
+ V_136 * 4 ) ) ;
if ( V_61 == - 1 )
V_258 &= ~ ( 0xff << ( 8 * V_137 ) ) ;
else {
V_258 &= ~ ( 0xff << ( 8 * V_137 ) ) ;
V_258 |= ( ( 0x01 | ( V_61 << 1 ) ) << ( 8 * V_137 ) ) ;
}
F_1 ( V_2 , V_82 + V_136 * 4 ,
V_258 ) ;
}
static void F_143 ( struct V_1 * V_2 ,
unsigned char V_259 ,
int V_61 )
{
unsigned int V_260 ;
unsigned int V_136 ;
unsigned int V_137 ;
V_136 = ( V_259 / 4 ) * 4 ;
V_137 = V_259 % 4 ;
V_260 = F_3 ( V_2 , V_84 + V_136 ) ;
if ( V_61 == - 1 ) {
V_260 &= ~ ( 0xff << ( 8 * V_137 ) ) ;
} else {
V_260 &= ~ ( 0xff << ( 8 * V_137 ) ) ;
V_260 |= ( ( 0x01 | ( V_61 << 1 ) ) << ( 8 * V_137 ) ) ;
}
F_1 ( V_2 , V_84 + V_136 , V_260 ) ;
}
static int F_144 ( struct V_1 * V_2 , unsigned char * V_261 ,
int V_61 )
{
unsigned char V_262 = 0 ;
if ( memcmp ( V_261 , L_11 , 5 ) == 0 ) {
F_142 ( V_2 , V_261 [ 5 ] , V_61 ) ;
return 0 ;
}
V_262 = F_141 ( V_261 ) ;
if ( V_61 == - 1 ) {
if ( V_2 -> V_83 [ V_262 ] == 0 ) {
F_145 ( V_2 -> V_17 , L_12 ,
V_262 ) ;
return - V_263 ;
}
V_2 -> V_83 [ V_262 ] -- ;
if ( V_2 -> V_83 [ V_262 ] != 0 ) {
F_145 ( V_2 -> V_17 ,
L_13 ,
V_2 -> V_83 [ V_262 ] , V_262 ) ;
return - V_263 ;
}
} else
V_2 -> V_83 [ V_262 ] ++ ;
F_143 ( V_2 , V_262 , V_61 ) ;
return 0 ;
}
static void F_146 ( struct V_1 * V_2 ,
int V_264 )
{
T_1 V_265 , V_39 ;
V_265 = F_3 ( V_2 , V_104 ) ;
V_39 = F_3 ( V_2 , V_266 ) ;
if ( V_264 ) {
V_265 |= V_267 ;
V_39 |= V_268 ;
F_1 ( V_2 , V_141 , 0xffff ) ;
F_1 ( V_2 , V_142 , 0xffffffff ) ;
} else {
V_265 &= ~ V_267 ;
V_39 &= ~ V_268 ;
}
F_1 ( V_2 , V_104 , V_265 ) ;
F_1 ( V_2 , V_266 , V_39 ) ;
}
static void F_147 ( struct V_16 * V_17 )
{
struct V_1 * V_2 = F_9 ( V_17 ) ;
struct V_269 * V_270 ;
if ( V_17 -> V_271 & V_272 ) {
F_146 ( V_2 , 1 ) ;
F_41 ( V_2 , V_103 ) ;
F_42 ( V_2 , V_103 ) ;
F_43 ( V_2 , V_103 ) ;
} else {
F_146 ( V_2 , 0 ) ;
F_41 ( V_2 , - 1 ) ;
F_55 ( V_2 , V_17 -> V_273 , V_103 ) ;
if ( V_17 -> V_271 & V_274 ) {
F_42 ( V_2 , V_103 ) ;
F_43 ( V_2 , V_103 ) ;
} else {
F_42 ( V_2 , - 1 ) ;
F_43 ( V_2 , - 1 ) ;
if ( ! F_148 ( V_17 ) ) {
F_149 (ha, dev) {
F_144 ( V_2 , V_270 -> V_138 ,
V_103 ) ;
}
}
}
}
}
static T_8 F_150 ( int V_275 , void * V_276 )
{
struct V_1 * V_2 = (struct V_1 * ) V_276 ;
F_1 ( V_2 , V_88 , 0 ) ;
F_151 ( & V_2 -> V_221 ) ;
return V_277 ;
}
static int F_152 ( struct V_1 * V_2 ,
struct V_278 * V_279 )
{
struct V_280 V_31 ;
struct V_280 V_281 = {} ;
T_1 V_282 = F_3 ( V_2 , V_283 ) ;
V_31 . V_284 = ! ! ( V_282 & V_285 ) ;
if ( V_282 & V_286 )
V_31 . V_287 = V_288 ;
else if ( V_282 & V_289 )
V_31 . V_287 = V_290 ;
else
V_31 . V_287 = V_291 ;
V_31 . V_292 = ! ! ( V_282 & V_293 ) ;
V_281 . V_284 = 1 ;
V_281 . V_287 = 1 ;
V_281 . V_292 = 1 ;
F_153 ( V_279 , & V_31 , & V_281 ) ;
return 0 ;
}
static int F_154 ( struct V_294 * V_221 , int V_295 )
{
int V_41 = 0 ;
T_1 V_296 ;
unsigned long V_271 ;
struct V_1 * V_2 = F_9 ( V_221 -> V_17 ) ;
if ( ! F_133 ( V_2 -> V_17 ) ) {
F_155 ( V_221 ) ;
return V_41 ;
}
V_296 = F_3 ( V_2 , V_85 ) ;
if ( V_296 & V_297 ) {
T_1 V_298 = F_3 ( V_2 , V_87 ) ;
F_1 ( V_2 , V_87 , 0 ) ;
if ( V_2 -> V_115 && ( V_298 &
( V_299 |
V_300 |
V_301 ) ) ) {
F_152 ( V_2 , V_2 -> V_302 ) ;
}
}
if ( V_296 & V_303 ) {
F_137 ( V_2 , ( V_296 & V_303 ) ) ;
V_296 &= ~ V_303 ;
}
V_296 |= V_2 -> V_296 ;
if ( V_66 > 1 ) {
while ( ( V_296 & V_304 ) && ( V_295 > 0 ) ) {
int V_69 ;
struct V_33 * V_34 ;
V_34 = F_103 ( V_2 , V_296 ) ;
if ( ! V_34 )
break;
V_69 = F_105 ( V_2 , V_295 , V_34 ) ;
V_41 += V_69 ;
V_295 -= V_69 ;
if ( V_295 > 0 ) {
V_296 &= ~ ( ( 1 << V_34 -> V_37 ) << 8 ) ;
}
}
} else {
V_41 = F_105 ( V_2 , V_295 , & V_2 -> V_67 [ V_103 ] ) ;
V_295 -= V_41 ;
}
if ( V_295 > 0 ) {
V_296 = 0 ;
F_155 ( V_221 ) ;
F_156 ( V_271 ) ;
F_1 ( V_2 , V_88 ,
F_157 ( V_66 ) |
F_158 ( V_63 ) |
V_297 ) ;
F_159 ( V_271 ) ;
}
V_2 -> V_296 = V_296 ;
return V_41 ;
}
static int F_160 ( struct V_1 * V_2 , struct V_33 * V_34 ,
int V_188 )
{
int V_11 ;
for ( V_11 = 0 ; V_11 < V_188 ; V_11 ++ ) {
memset ( V_34 -> V_46 + V_11 , 0 , sizeof( struct V_43 ) ) ;
if ( F_92 ( V_2 , V_34 -> V_46 + V_11 ) != 0 ) {
F_73 ( V_2 -> V_17 , L_14 ,
V_305 , V_34 -> V_37 , V_11 , V_188 ) ;
break;
}
}
F_15 ( V_2 , V_34 , V_11 ) ;
return V_11 ;
}
static void F_161 ( struct V_1 * V_2 )
{
int V_61 ;
for ( V_61 = 0 ; V_61 < V_63 ; V_61 ++ )
F_136 ( V_2 , & V_2 -> V_64 [ V_61 ] ) ;
F_1 ( V_2 , V_98 , V_99 ) ;
F_1 ( V_2 , V_98 , 0 ) ;
}
static void F_162 ( struct V_1 * V_2 )
{
F_1 ( V_2 , V_96 , V_97 ) ;
F_1 ( V_2 , V_96 , 0 ) ;
}
static int F_163 ( struct V_1 * V_2 ,
struct V_33 * V_34 )
{
V_34 -> V_9 = V_2 -> V_306 ;
V_34 -> V_46 = F_164 ( V_2 -> V_17 -> V_17 . V_190 ,
V_34 -> V_9 * V_307 ,
& V_34 -> V_308 , V_309 ) ;
if ( V_34 -> V_46 == NULL )
return - V_199 ;
F_165 ( V_34 -> V_46 !=
F_166 ( V_34 -> V_46 , V_310 ) ) ;
V_34 -> V_56 = V_34 -> V_9 - 1 ;
F_1 ( V_2 , F_167 ( V_34 -> V_37 ) , V_34 -> V_308 ) ;
F_1 ( V_2 , F_32 ( V_34 -> V_37 ) , V_34 -> V_9 ) ;
F_24 ( V_2 , V_34 , V_220 ) ;
F_56 ( V_2 , V_34 , V_34 -> V_144 ) ;
F_59 ( V_2 , V_34 , V_34 -> V_147 ) ;
F_31 ( V_2 , V_34 , F_94 ( V_2 -> V_200 ) ) ;
F_33 ( V_2 , V_34 ) ;
F_160 ( V_2 , V_34 , V_34 -> V_9 ) ;
return 0 ;
}
static void F_168 ( struct V_1 * V_2 ,
struct V_33 * V_34 )
{
F_104 ( V_2 , V_34 ) ;
if ( V_34 -> V_46 )
F_169 ( V_2 -> V_17 -> V_17 . V_190 ,
V_34 -> V_9 * V_307 ,
V_34 -> V_46 ,
V_34 -> V_308 ) ;
V_34 -> V_46 = NULL ;
V_34 -> V_56 = 0 ;
V_34 -> V_45 = 0 ;
V_34 -> V_308 = 0 ;
}
static int F_170 ( struct V_1 * V_2 ,
struct V_6 * V_7 )
{
V_7 -> V_9 = V_2 -> V_311 ;
V_7 -> V_251 = V_7 -> V_9 - V_312 ;
V_7 -> V_195 = V_7 -> V_251 / 2 ;
V_7 -> V_46 = F_164 ( V_2 -> V_17 -> V_17 . V_190 ,
V_7 -> V_9 * V_307 ,
& V_7 -> V_308 , V_309 ) ;
if ( V_7 -> V_46 == NULL )
return - V_199 ;
F_165 ( V_7 -> V_46 !=
F_166 ( V_7 -> V_46 , V_310 ) ) ;
V_7 -> V_56 = V_7 -> V_9 - 1 ;
F_1 ( V_2 , F_47 ( V_7 -> V_37 ) , 0x03ffffff ) ;
F_1 ( V_2 , F_46 ( V_7 -> V_37 ) , 0x3fffffff ) ;
F_1 ( V_2 , F_171 ( V_7 -> V_37 ) , V_7 -> V_308 ) ;
F_1 ( V_2 , F_63 ( V_7 -> V_37 ) , V_7 -> V_9 ) ;
V_7 -> V_189 = F_88 ( V_7 -> V_9 * sizeof( * V_7 -> V_189 ) , V_309 ) ;
if ( V_7 -> V_189 == NULL ) {
F_169 ( V_2 -> V_17 -> V_17 . V_190 ,
V_7 -> V_9 * V_307 ,
V_7 -> V_46 , V_7 -> V_308 ) ;
return - V_199 ;
}
V_7 -> V_238 = F_164 ( V_2 -> V_17 -> V_17 . V_190 ,
V_7 -> V_9 * V_226 ,
& V_7 -> V_225 , V_309 ) ;
if ( V_7 -> V_238 == NULL ) {
F_91 ( V_7 -> V_189 ) ;
F_169 ( V_2 -> V_17 -> V_17 . V_190 ,
V_7 -> V_9 * V_307 ,
V_7 -> V_46 , V_7 -> V_308 ) ;
return - V_199 ;
}
F_62 ( V_2 , V_7 , V_7 -> V_149 ) ;
return 0 ;
}
static void F_172 ( struct V_1 * V_2 ,
struct V_6 * V_7 )
{
F_91 ( V_7 -> V_189 ) ;
if ( V_7 -> V_238 )
F_169 ( V_2 -> V_17 -> V_17 . V_190 ,
V_7 -> V_9 * V_226 ,
V_7 -> V_238 , V_7 -> V_225 ) ;
if ( V_7 -> V_46 )
F_169 ( V_2 -> V_17 -> V_17 . V_190 ,
V_7 -> V_9 * V_307 ,
V_7 -> V_46 , V_7 -> V_308 ) ;
V_7 -> V_46 = NULL ;
V_7 -> V_56 = 0 ;
V_7 -> V_45 = 0 ;
V_7 -> V_308 = 0 ;
F_1 ( V_2 , F_47 ( V_7 -> V_37 ) , 0 ) ;
F_1 ( V_2 , F_46 ( V_7 -> V_37 ) , 0 ) ;
F_1 ( V_2 , F_171 ( V_7 -> V_37 ) , 0 ) ;
F_1 ( V_2 , F_63 ( V_7 -> V_37 ) , 0 ) ;
}
static void F_173 ( struct V_1 * V_2 )
{
int V_61 ;
for ( V_61 = 0 ; V_61 < V_63 ; V_61 ++ )
F_172 ( V_2 , & V_2 -> V_64 [ V_61 ] ) ;
}
static void F_174 ( struct V_1 * V_2 )
{
int V_61 ;
for ( V_61 = 0 ; V_61 < V_66 ; V_61 ++ )
F_168 ( V_2 , & V_2 -> V_67 [ V_61 ] ) ;
}
static int F_175 ( struct V_1 * V_2 )
{
int V_61 ;
for ( V_61 = 0 ; V_61 < V_66 ; V_61 ++ ) {
int V_215 = F_163 ( V_2 , & V_2 -> V_67 [ V_61 ] ) ;
if ( V_215 ) {
F_73 ( V_2 -> V_17 , L_15 ,
V_305 , V_61 ) ;
F_174 ( V_2 ) ;
return V_215 ;
}
}
return 0 ;
}
static int F_176 ( struct V_1 * V_2 )
{
int V_61 ;
for ( V_61 = 0 ; V_61 < V_63 ; V_61 ++ ) {
int V_215 = F_170 ( V_2 , & V_2 -> V_64 [ V_61 ] ) ;
if ( V_215 ) {
F_73 ( V_2 -> V_17 , L_16 ,
V_305 , V_61 ) ;
F_173 ( V_2 ) ;
return V_215 ;
}
}
return 0 ;
}
static void F_177 ( struct V_1 * V_2 )
{
F_23 ( V_2 , V_2 -> V_200 ) ;
F_52 ( V_2 , V_2 -> V_200 ) ;
F_39 ( V_2 ) ;
F_178 ( & V_2 -> V_221 ) ;
F_1 ( V_2 , V_88 ,
F_157 ( V_66 ) |
F_158 ( V_63 ) |
V_297 ) ;
F_1 ( V_2 , V_90 ,
V_299 |
V_300 |
V_301 ) ;
F_179 ( V_2 -> V_302 ) ;
F_180 ( V_2 -> V_17 ) ;
}
static void F_181 ( struct V_1 * V_2 )
{
F_182 ( V_2 -> V_302 ) ;
F_183 ( & V_2 -> V_221 ) ;
F_184 ( V_2 -> V_17 ) ;
F_35 ( V_2 ) ;
F_185 ( V_2 -> V_17 ) ;
F_40 ( V_2 ) ;
F_1 ( V_2 , V_87 , 0 ) ;
F_1 ( V_2 , V_86 , 0 ) ;
F_1 ( V_2 , V_88 , 0 ) ;
F_1 ( V_2 , V_89 , 0 ) ;
F_1 ( V_2 , V_90 , 0 ) ;
F_161 ( V_2 ) ;
F_162 ( V_2 ) ;
}
static int F_186 ( struct V_16 * V_17 , int V_128 )
{
if ( V_128 < 68 ) {
F_73 ( V_17 , L_17 ) ;
return - V_263 ;
}
if ( V_128 > 9676 ) {
F_145 ( V_17 , L_18 , V_128 ) ;
V_128 = 9676 ;
}
if ( ! F_187 ( F_188 ( V_128 ) , 8 ) ) {
F_145 ( V_17 , L_19 ,
V_128 , F_189 ( F_188 ( V_128 ) , 8 ) ) ;
V_128 = F_189 ( F_188 ( V_128 ) , 8 ) ;
}
return V_128 ;
}
static int F_190 ( struct V_16 * V_17 , int V_128 )
{
struct V_1 * V_2 = F_9 ( V_17 ) ;
int V_313 ;
V_128 = F_186 ( V_17 , V_128 ) ;
if ( V_128 < 0 )
return - V_263 ;
V_17 -> V_128 = V_128 ;
if ( ! F_133 ( V_17 ) ) {
F_191 ( V_17 ) ;
return 0 ;
}
F_181 ( V_2 ) ;
F_173 ( V_2 ) ;
F_174 ( V_2 ) ;
V_2 -> V_200 = F_188 ( V_17 -> V_128 ) ;
V_2 -> V_196 = F_192 ( F_94 ( V_2 -> V_200 ) ) +
F_192 ( sizeof( struct V_314 ) ) ;
V_313 = F_175 ( V_2 ) ;
if ( V_313 ) {
F_73 ( V_17 , L_20 ) ;
return V_313 ;
}
V_313 = F_176 ( V_2 ) ;
if ( V_313 ) {
F_73 ( V_17 , L_21 ) ;
return V_313 ;
}
F_177 ( V_2 ) ;
F_34 ( V_2 ) ;
F_191 ( V_17 ) ;
return 0 ;
}
static T_9 F_193 ( struct V_16 * V_17 ,
T_9 V_315 )
{
struct V_1 * V_2 = F_9 ( V_17 ) ;
if ( V_2 -> V_316 && V_17 -> V_128 > V_2 -> V_316 ) {
V_315 &= ~ ( V_317 | V_318 ) ;
F_145 ( V_17 ,
L_22 ,
V_2 -> V_316 ) ;
}
return V_315 ;
}
static void F_194 ( struct V_1 * V_2 , unsigned char * V_138 )
{
T_1 V_319 , V_320 ;
V_319 = F_3 ( V_2 , V_141 ) ;
V_320 = F_3 ( V_2 , V_142 ) ;
V_138 [ 0 ] = ( V_320 >> 24 ) & 0xFF ;
V_138 [ 1 ] = ( V_320 >> 16 ) & 0xFF ;
V_138 [ 2 ] = ( V_320 >> 8 ) & 0xFF ;
V_138 [ 3 ] = V_320 & 0xFF ;
V_138 [ 4 ] = ( V_319 >> 8 ) & 0xFF ;
V_138 [ 5 ] = V_319 & 0xFF ;
}
static int F_195 ( struct V_16 * V_17 , void * V_138 )
{
struct V_1 * V_2 = F_9 ( V_17 ) ;
struct V_321 * V_321 = V_138 ;
int V_313 ;
V_313 = F_196 ( V_17 , V_138 ) ;
if ( V_313 < 0 )
return V_313 ;
F_55 ( V_2 , V_17 -> V_273 , - 1 ) ;
F_55 ( V_2 , V_321 -> V_322 , V_103 ) ;
F_197 ( V_17 , V_138 ) ;
return 0 ;
}
static void F_198 ( struct V_16 * V_323 )
{
struct V_1 * V_2 = F_9 ( V_323 ) ;
struct V_278 * V_324 = V_2 -> V_302 ;
int V_325 = 0 ;
if ( V_324 -> V_284 ) {
if ( ( V_2 -> V_287 != V_324 -> V_287 ) ||
( V_2 -> V_292 != V_324 -> V_292 ) ) {
T_1 V_39 ;
V_39 = F_3 ( V_2 , V_116 ) ;
V_39 &= ~ ( V_326 |
V_327 |
V_328 ) ;
if ( V_324 -> V_292 )
V_39 |= V_328 ;
if ( V_324 -> V_287 == V_288 )
V_39 |= V_327 ;
else if ( V_324 -> V_287 == V_290 )
V_39 |= V_326 ;
F_1 ( V_2 , V_116 , V_39 ) ;
V_2 -> V_292 = V_324 -> V_292 ;
V_2 -> V_287 = V_324 -> V_287 ;
}
}
if ( V_324 -> V_284 != V_2 -> V_284 ) {
if ( ! V_324 -> V_284 ) {
V_2 -> V_292 = - 1 ;
V_2 -> V_287 = 0 ;
}
V_2 -> V_284 = V_324 -> V_284 ;
V_325 = 1 ;
}
if ( V_325 ) {
if ( V_324 -> V_284 ) {
if ( ! V_2 -> V_115 ) {
T_1 V_39 = F_3 ( V_2 ,
V_116 ) ;
V_39 &= ~ V_118 ;
V_39 |= V_117 ;
F_1 ( V_2 , V_116 ,
V_39 ) ;
}
F_34 ( V_2 ) ;
} else {
if ( ! V_2 -> V_115 ) {
T_1 V_39 = F_3 ( V_2 ,
V_116 ) ;
V_39 &= ~ V_117 ;
V_39 |= V_118 ;
F_1 ( V_2 , V_116 ,
V_39 ) ;
}
F_35 ( V_2 ) ;
}
F_199 ( V_324 ) ;
}
}
static int F_200 ( struct V_1 * V_2 )
{
struct V_278 * V_302 ;
V_302 = F_201 ( V_2 -> V_17 , V_2 -> V_329 , F_198 , 0 ,
V_2 -> V_330 ) ;
if ( ! V_302 ) {
F_73 ( V_2 -> V_17 , L_23 ) ;
return - V_331 ;
}
V_302 -> V_332 &= V_333 ;
V_302 -> V_334 = V_302 -> V_332 ;
V_2 -> V_302 = V_302 ;
V_2 -> V_284 = 0 ;
V_2 -> V_292 = 0 ;
V_2 -> V_287 = 0 ;
return 0 ;
}
static void F_202 ( struct V_1 * V_2 )
{
F_203 ( V_2 -> V_302 ) ;
V_2 -> V_302 = NULL ;
}
static int F_204 ( struct V_16 * V_17 )
{
struct V_1 * V_2 = F_9 ( V_17 ) ;
int V_313 ;
V_2 -> V_200 = F_188 ( V_2 -> V_17 -> V_128 ) ;
V_2 -> V_196 = F_192 ( F_94 ( V_2 -> V_200 ) ) +
F_192 ( sizeof( struct V_314 ) ) ;
V_313 = F_175 ( V_2 ) ;
if ( V_313 )
return V_313 ;
V_313 = F_176 ( V_2 ) ;
if ( V_313 )
goto V_335;
V_313 = F_205 ( V_2 -> V_17 -> V_275 , F_150 , 0 ,
V_336 , V_2 ) ;
if ( V_313 ) {
F_73 ( V_2 -> V_17 , L_24 , V_2 -> V_17 -> V_275 ) ;
goto V_337;
}
F_184 ( V_2 -> V_17 ) ;
V_313 = F_200 ( V_2 ) ;
if ( V_313 < 0 ) {
F_73 ( V_17 , L_25 ) ;
goto V_338;
}
F_177 ( V_2 ) ;
return 0 ;
V_338:
F_206 ( V_2 -> V_17 -> V_275 , V_2 ) ;
V_337:
F_173 ( V_2 ) ;
V_335:
F_174 ( V_2 ) ;
return V_313 ;
}
static int F_207 ( struct V_16 * V_17 )
{
struct V_1 * V_2 = F_9 ( V_17 ) ;
F_181 ( V_2 ) ;
F_202 ( V_2 ) ;
F_206 ( V_17 -> V_275 , V_2 ) ;
F_174 ( V_2 ) ;
F_173 ( V_2 ) ;
return 0 ;
}
static int F_208 ( struct V_16 * V_17 , struct V_339 * V_340 , int V_341 )
{
struct V_1 * V_2 = F_9 ( V_17 ) ;
if ( ! V_2 -> V_302 )
return - V_342 ;
return F_209 ( V_2 -> V_302 , V_340 , V_341 ) ;
}
int F_210 ( struct V_16 * V_17 , struct V_343 * V_341 )
{
struct V_1 * V_2 = F_9 ( V_17 ) ;
if ( ! V_2 -> V_302 )
return - V_331 ;
return F_211 ( V_2 -> V_302 , V_341 ) ;
}
int F_212 ( struct V_16 * V_17 , struct V_343 * V_341 )
{
struct V_1 * V_2 = F_9 ( V_17 ) ;
if ( ! V_2 -> V_302 )
return - V_331 ;
return F_213 ( V_2 -> V_302 , V_341 ) ;
}
static int F_214 ( struct V_16 * V_17 ,
struct V_344 * V_345 )
{
struct V_1 * V_2 = F_9 ( V_17 ) ;
int V_61 ;
for ( V_61 = 0 ; V_61 < V_66 ; V_61 ++ ) {
struct V_33 * V_34 = & V_2 -> V_67 [ V_61 ] ;
V_34 -> V_147 = V_345 -> V_346 ;
V_34 -> V_144 = V_345 -> V_347 ;
F_56 ( V_2 , V_34 , V_34 -> V_144 ) ;
F_59 ( V_2 , V_34 , V_34 -> V_147 ) ;
}
for ( V_61 = 0 ; V_61 < V_63 ; V_61 ++ ) {
struct V_6 * V_7 = & V_2 -> V_64 [ V_61 ] ;
V_7 -> V_149 = V_345 -> V_348 ;
F_62 ( V_2 , V_7 , V_7 -> V_149 ) ;
}
return 0 ;
}
static int F_215 ( struct V_16 * V_17 ,
struct V_344 * V_345 )
{
struct V_1 * V_2 = F_9 ( V_17 ) ;
V_345 -> V_346 = V_2 -> V_67 [ 0 ] . V_147 ;
V_345 -> V_347 = V_2 -> V_67 [ 0 ] . V_144 ;
V_345 -> V_348 = V_2 -> V_64 [ 0 ] . V_149 ;
return 0 ;
}
static void F_216 ( struct V_16 * V_17 ,
struct V_349 * V_350 )
{
F_217 ( V_350 -> V_351 , V_336 ,
sizeof( V_350 -> V_351 ) ) ;
F_217 ( V_350 -> V_352 , V_353 ,
sizeof( V_350 -> V_352 ) ) ;
F_217 ( V_350 -> V_354 , F_218 ( & V_17 -> V_17 ) ,
sizeof( V_350 -> V_354 ) ) ;
}
static void F_219 ( struct V_16 * V_355 ,
struct V_356 * V_357 )
{
struct V_1 * V_2 = F_9 ( V_355 ) ;
V_357 -> V_358 = V_359 ;
V_357 -> V_360 = V_361 ;
V_357 -> V_362 = V_2 -> V_306 ;
V_357 -> V_363 = V_2 -> V_311 ;
}
static int F_220 ( struct V_16 * V_17 ,
struct V_356 * V_357 )
{
struct V_1 * V_2 = F_9 ( V_17 ) ;
if ( ( V_357 -> V_362 == 0 ) || ( V_357 -> V_363 == 0 ) )
return - V_263 ;
V_2 -> V_306 = V_357 -> V_362 < V_359 ?
V_357 -> V_362 : V_359 ;
V_2 -> V_311 = F_221 ( T_7 , V_357 -> V_363 ,
V_312 * 2 , V_361 ) ;
if ( V_2 -> V_311 != V_357 -> V_363 )
F_36 ( V_17 , L_26 ,
V_2 -> V_311 , V_357 -> V_363 ) ;
if ( F_133 ( V_17 ) ) {
F_207 ( V_17 ) ;
if ( F_204 ( V_17 ) ) {
F_73 ( V_17 ,
L_27 ) ;
return - V_199 ;
}
}
return 0 ;
}
static int F_222 ( struct V_364 * V_17 , struct V_1 * V_2 )
{
int V_61 ;
F_40 ( V_2 ) ;
F_44 ( V_2 ) ;
V_2 -> V_64 = F_223 ( V_17 , V_63 , sizeof( struct V_6 ) ,
V_309 ) ;
if ( ! V_2 -> V_64 )
return - V_199 ;
for ( V_61 = 0 ; V_61 < V_63 ; V_61 ++ ) {
struct V_6 * V_7 = & V_2 -> V_64 [ V_61 ] ;
V_7 -> V_37 = V_61 ;
V_7 -> V_9 = V_2 -> V_311 ;
V_7 -> V_149 = V_365 ;
}
V_2 -> V_67 = F_223 ( V_17 , V_66 , sizeof( struct V_33 ) ,
V_309 ) ;
if ( ! V_2 -> V_67 )
return - V_199 ;
for ( V_61 = 0 ; V_61 < V_66 ; V_61 ++ ) {
struct V_33 * V_34 = & V_2 -> V_67 [ V_61 ] ;
V_34 -> V_37 = V_61 ;
V_34 -> V_9 = V_2 -> V_306 ;
V_34 -> V_144 = V_366 ;
V_34 -> V_147 = V_367 ;
}
return 0 ;
}
static void F_224 ( struct V_1 * V_2 ,
const struct V_368 * V_369 )
{
T_1 V_370 ;
T_1 V_371 ;
int V_11 ;
for ( V_11 = 0 ; V_11 < 6 ; V_11 ++ ) {
F_1 ( V_2 , F_225 ( V_11 ) , 0 ) ;
F_1 ( V_2 , F_226 ( V_11 ) , 0 ) ;
if ( V_11 < 4 )
F_1 ( V_2 , F_227 ( V_11 ) , 0 ) ;
}
V_370 = 0x3f ;
V_371 = 0 ;
for ( V_11 = 0 ; V_11 < V_369 -> V_372 ; V_11 ++ ) {
const struct V_373 * V_374 = V_369 -> V_374 + V_11 ;
F_1 ( V_2 , F_225 ( V_11 ) , ( V_374 -> V_5 & 0xffff0000 ) |
( V_374 -> V_375 << 8 ) | V_369 -> V_376 ) ;
F_1 ( V_2 , F_226 ( V_11 ) ,
( V_374 -> V_9 - 1 ) & 0xffff0000 ) ;
V_370 &= ~ ( 1 << V_11 ) ;
V_371 |= 3 << ( 2 * V_11 ) ;
}
F_1 ( V_2 , V_377 , V_370 ) ;
}
static int F_228 ( struct V_1 * V_2 , int V_378 )
{
T_1 V_379 ;
F_1 ( V_2 , V_380 , 0 ) ;
V_379 = F_3 ( V_2 , V_381 ) ;
switch( V_378 ) {
case V_382 :
F_1 ( V_2 , V_383 , V_384 ) ;
V_379 |= V_385 | V_386 ;
break;
case V_387 :
F_1 ( V_2 , V_383 , V_388 ) ;
V_379 |= V_385 | V_386 ;
break;
case V_389 :
case V_390 :
V_379 |= V_386 ;
break;
default:
return - V_263 ;
}
if ( V_2 -> V_115 )
V_379 |= V_391 ;
V_379 &= ~ V_392 ;
F_1 ( V_2 , V_381 , V_379 ) ;
while ( ( F_3 ( V_2 , V_381 ) &
V_392 ) != 0 )
continue;
return 0 ;
}
static int F_229 ( struct V_393 * V_394 )
{
const struct V_368 * V_395 ;
struct V_396 * V_397 ;
struct V_398 * V_399 = V_394 -> V_17 . V_400 ;
struct V_398 * V_329 ;
struct V_1 * V_2 ;
struct V_16 * V_17 ;
const char * V_401 ;
char V_402 [ V_255 ] ;
const char * V_403 ;
const char * V_404 ;
int V_378 ;
int V_215 ;
if ( V_103 != 0 ) {
F_230 ( & V_394 -> V_17 , L_28 , V_103 ) ;
return - V_263 ;
}
V_17 = F_231 ( sizeof( struct V_1 ) , V_63 , V_66 ) ;
if ( ! V_17 )
return - V_199 ;
V_17 -> V_275 = F_232 ( V_399 , 0 ) ;
if ( V_17 -> V_275 == 0 ) {
V_215 = - V_263 ;
goto V_405;
}
V_329 = F_233 ( V_399 , L_29 , 0 ) ;
if ( ! V_329 ) {
if ( ! F_234 ( V_399 ) ) {
F_230 ( & V_394 -> V_17 , L_30 ) ;
V_215 = - V_331 ;
goto V_338;
}
V_215 = F_235 ( V_399 ) ;
if ( V_215 < 0 ) {
F_230 ( & V_394 -> V_17 , L_31 ) ;
goto V_338;
}
V_329 = F_236 ( V_399 ) ;
}
V_378 = F_237 ( V_399 ) ;
if ( V_378 < 0 ) {
F_230 ( & V_394 -> V_17 , L_32 ) ;
V_215 = - V_263 ;
goto V_406;
}
V_17 -> V_407 = V_361 ;
V_17 -> V_408 = 5 * V_409 ;
V_17 -> V_410 = & V_411 ;
V_17 -> V_412 = & V_413 ;
V_2 = F_9 ( V_17 ) ;
V_2 -> V_329 = V_329 ;
V_2 -> V_330 = V_378 ;
V_215 = F_238 ( V_399 , L_33 , & V_404 ) ;
V_2 -> V_115 = ( V_215 == 0 &&
strcmp ( V_404 , L_34 ) == 0 ) ;
V_2 -> V_146 = F_239 ( & V_394 -> V_17 , NULL ) ;
if ( F_240 ( V_2 -> V_146 ) ) {
V_215 = F_241 ( V_2 -> V_146 ) ;
goto V_406;
}
F_242 ( V_2 -> V_146 ) ;
V_397 = F_243 ( V_394 , V_414 , 0 ) ;
V_2 -> V_5 = F_244 ( & V_394 -> V_17 , V_397 ) ;
if ( F_240 ( V_2 -> V_5 ) ) {
V_215 = F_241 ( V_2 -> V_5 ) ;
goto V_415;
}
V_2 -> V_18 = F_245 ( struct V_21 ) ;
if ( ! V_2 -> V_18 ) {
V_215 = - V_199 ;
goto V_415;
}
V_401 = F_246 ( V_399 ) ;
if ( V_401 ) {
V_403 = L_35 ;
memcpy ( V_17 -> V_273 , V_401 , V_255 ) ;
} else {
F_194 ( V_2 , V_402 ) ;
if ( F_247 ( V_402 ) ) {
V_403 = L_36 ;
memcpy ( V_17 -> V_273 , V_402 , V_255 ) ;
} else {
V_403 = L_37 ;
F_248 ( V_17 ) ;
}
}
if ( F_249 ( V_399 , L_38 ) )
V_2 -> V_316 = 1600 ;
V_2 -> V_311 = V_361 ;
V_2 -> V_306 = V_359 ;
V_2 -> V_17 = V_17 ;
F_250 ( V_17 , & V_394 -> V_17 ) ;
V_215 = F_222 ( & V_394 -> V_17 , V_2 ) ;
if ( V_215 < 0 )
goto V_416;
V_215 = F_228 ( V_2 , V_378 ) ;
if ( V_215 < 0 ) {
F_230 ( & V_394 -> V_17 , L_39 ) ;
goto V_416;
}
V_395 = F_251 () ;
if ( V_395 )
F_224 ( V_2 , V_395 ) ;
F_252 ( V_17 , & V_2 -> V_221 , F_154 , V_417 ) ;
V_17 -> V_315 = V_418 | V_317 | V_318 ;
V_17 -> V_419 |= V_17 -> V_315 ;
V_17 -> V_420 |= V_17 -> V_315 ;
V_17 -> V_421 |= V_422 ;
V_17 -> V_423 = V_424 ;
V_215 = F_253 ( V_17 ) ;
if ( V_215 < 0 ) {
F_230 ( & V_394 -> V_17 , L_40 ) ;
goto V_416;
}
F_145 ( V_17 , L_41 , V_403 ,
V_17 -> V_273 ) ;
F_254 ( V_394 , V_2 -> V_17 ) ;
if ( V_2 -> V_115 ) {
struct V_278 * V_279 = F_255 ( V_399 ) ;
F_152 ( V_2 , V_279 ) ;
F_256 ( & V_279 -> V_17 ) ;
}
return 0 ;
V_416:
F_257 ( V_2 -> V_18 ) ;
V_415:
F_258 ( V_2 -> V_146 ) ;
V_406:
F_259 ( V_329 ) ;
V_338:
F_260 ( V_17 -> V_275 ) ;
V_405:
F_261 ( V_17 ) ;
return V_215 ;
}
static int F_262 ( struct V_393 * V_394 )
{
struct V_16 * V_17 = F_263 ( V_394 ) ;
struct V_1 * V_2 = F_9 ( V_17 ) ;
F_264 ( V_17 ) ;
F_258 ( V_2 -> V_146 ) ;
F_257 ( V_2 -> V_18 ) ;
F_260 ( V_17 -> V_275 ) ;
F_259 ( V_2 -> V_329 ) ;
F_261 ( V_17 ) ;
return 0 ;
}
