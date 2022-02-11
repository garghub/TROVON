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
F_41 ( V_2 , - 1 ) ;
F_42 ( V_2 , - 1 ) ;
F_43 ( V_2 , - 1 ) ;
F_1 ( V_2 , V_91 ,
( V_115
| V_116 ) ) ;
}
static void F_52 ( struct V_1 * V_2 , int V_117 )
{
T_1 V_39 , V_9 , V_118 ;
int V_61 ;
V_118 = V_117 * 8 ;
if ( V_118 > V_119 )
V_118 = V_119 ;
V_39 = F_3 ( V_2 , V_120 ) ;
V_39 &= ~ V_119 ;
V_39 |= V_118 ;
F_1 ( V_2 , V_120 , V_39 ) ;
V_39 = F_3 ( V_2 , V_121 ) ;
V_9 = V_39 & V_122 ;
if ( V_9 < V_118 ) {
V_9 = V_118 ;
V_39 &= ~ V_122 ;
V_39 |= V_9 ;
F_1 ( V_2 , V_121 , V_39 ) ;
}
for ( V_61 = 0 ; V_61 < V_63 ; V_61 ++ ) {
V_39 = F_3 ( V_2 , F_53 ( V_61 ) ) ;
V_9 = V_39 & V_123 ;
if ( V_9 < V_118 ) {
V_9 = V_118 ;
V_39 &= ~ V_123 ;
V_39 |= V_9 ;
F_1 ( V_2 , F_53 ( V_61 ) , V_39 ) ;
}
}
}
static void F_54 ( struct V_1 * V_2 , T_3 V_124 ,
int V_61 )
{
unsigned int V_125 ;
unsigned int V_126 ;
unsigned int V_127 ;
V_124 = ( 0xf & V_124 ) ;
V_126 = ( V_124 / 4 ) * 4 ;
V_127 = V_124 % 4 ;
V_125 = F_3 ( V_2 , ( V_81 + V_126 ) ) ;
if ( V_61 == - 1 ) {
V_125 &= ~ ( 0xff << ( 8 * V_127 ) ) ;
} else {
V_125 &= ~ ( 0xff << ( 8 * V_127 ) ) ;
V_125 |= ( ( 0x01 | ( V_61 << 1 ) ) << ( 8 * V_127 ) ) ;
}
F_1 ( V_2 , ( V_81 + V_126 ) , V_125 ) ;
}
static void F_55 ( struct V_1 * V_2 , unsigned char * V_128 ,
int V_61 )
{
unsigned int V_129 ;
unsigned int V_130 ;
if ( V_61 != - 1 ) {
V_130 = ( V_128 [ 4 ] << 8 ) | ( V_128 [ 5 ] ) ;
V_129 = ( V_128 [ 0 ] << 24 ) | ( V_128 [ 1 ] << 16 ) |
( V_128 [ 2 ] << 8 ) | ( V_128 [ 3 ] << 0 ) ;
F_1 ( V_2 , V_131 , V_130 ) ;
F_1 ( V_2 , V_132 , V_129 ) ;
}
F_54 ( V_2 , V_128 [ 5 ] , V_61 ) ;
}
static void F_56 ( struct V_1 * V_2 ,
struct V_33 * V_34 , T_1 V_133 )
{
F_1 ( V_2 , F_57 ( V_34 -> V_37 ) ,
V_133 | F_58 ( 0 ) ) ;
V_34 -> V_134 = V_133 ;
}
static void F_59 ( struct V_1 * V_2 ,
struct V_33 * V_34 , T_1 V_133 )
{
T_1 V_39 ;
unsigned long V_135 ;
V_135 = F_60 ( V_2 -> V_136 ) ;
V_39 = ( V_135 / 1000000 ) * V_133 ;
F_1 ( V_2 , F_61 ( V_34 -> V_37 ) , V_39 ) ;
V_34 -> V_137 = V_133 ;
}
static void F_62 ( struct V_1 * V_2 ,
struct V_6 * V_7 , T_1 V_133 )
{
T_1 V_39 ;
V_39 = F_3 ( V_2 , F_63 ( V_7 -> V_37 ) ) ;
V_39 &= ~ V_138 ;
V_39 |= F_64 ( V_133 ) ;
F_1 ( V_2 , F_63 ( V_7 -> V_37 ) , V_39 ) ;
V_7 -> V_139 = V_133 ;
}
static void F_65 ( struct V_43 * V_44 ,
T_1 V_140 , T_1 V_141 )
{
V_44 -> V_142 = V_141 ;
V_44 -> V_143 = V_140 ;
}
static void F_66 ( struct V_1 * V_2 ,
struct V_6 * V_7 ,
int V_144 )
{
T_1 V_39 ;
while ( V_144 > 0xff ) {
V_39 = 0xff << V_145 ;
F_1 ( V_2 , F_28 ( V_7 -> V_37 ) , V_39 ) ;
V_144 = V_144 - 0xff ;
}
V_39 = V_144 << V_145 ;
F_1 ( V_2 , F_28 ( V_7 -> V_37 ) , V_39 ) ;
}
static int F_67 ( struct V_1 * V_2 ,
struct V_6 * V_7 )
{
T_1 V_39 ;
int V_144 ;
V_39 = F_3 ( V_2 , F_68 ( V_7 -> V_37 ) ) ;
V_144 = ( V_39 & V_146 ) >>
V_147 ;
return V_144 ;
}
static int F_69 ( struct V_1 * V_2 ,
struct V_6 * V_7 )
{
int V_144 ;
V_144 = F_67 ( V_2 , V_7 ) ;
if ( V_144 )
F_66 ( V_2 , V_7 , V_144 ) ;
return V_144 ;
}
static T_1 F_70 ( int V_148 , int V_149 ,
int V_150 , int V_151 )
{
T_1 V_152 ;
V_152 = V_148 << V_153 ;
V_152 |= V_150 << V_154 ;
if ( V_149 == F_71 ( V_155 ) )
V_152 |= V_156 ;
else
V_152 |= V_157 ;
if ( V_151 == V_158 )
V_152 |= V_159 ;
else if ( V_151 == V_160 )
V_152 |= V_161 | V_159 ;
else
V_152 |= V_162 ;
return V_152 ;
}
static void F_72 ( struct V_1 * V_2 ,
struct V_43 * V_44 )
{
T_1 V_31 = V_44 -> V_31 ;
if ( ! F_14 ( V_31 ) ) {
F_73 ( V_2 -> V_17 ,
L_4 ,
V_31 , V_44 -> V_163 ) ;
return;
}
switch ( V_31 & V_164 ) {
case V_165 :
F_73 ( V_2 -> V_17 , L_5 ,
V_31 , V_44 -> V_163 ) ;
break;
case V_166 :
F_73 ( V_2 -> V_17 , L_6 ,
V_31 , V_44 -> V_163 ) ;
break;
case V_167 :
F_73 ( V_2 -> V_17 , L_7 ,
V_31 , V_44 -> V_163 ) ;
break;
case V_168 :
F_73 ( V_2 -> V_17 , L_8 ,
V_31 , V_44 -> V_163 ) ;
break;
}
}
static void F_74 ( struct V_1 * V_2 , T_1 V_31 ,
struct V_169 * V_170 )
{
if ( ( V_31 & V_171 ) &&
( V_31 & V_172 ) ) {
V_170 -> V_173 = 0 ;
V_170 -> V_174 = V_175 ;
return;
}
V_170 -> V_174 = V_176 ;
}
static struct V_6 * F_75 ( struct V_1 * V_2 ,
T_1 V_177 )
{
int V_61 = F_76 ( V_177 ) - 1 ;
return & V_2 -> V_64 [ V_61 ] ;
}
static void F_77 ( struct V_1 * V_2 ,
struct V_6 * V_7 , int V_178 )
{
int V_11 ;
for ( V_11 = 0 ; V_11 < V_178 ; V_11 ++ ) {
struct V_54 * V_55 = V_7 -> V_46 +
V_7 -> V_8 ;
struct V_169 * V_170 = V_7 -> V_179 [ V_7 -> V_8 ] ;
F_5 ( V_7 ) ;
if ( ! F_78 ( V_7 , V_55 -> V_143 ) )
F_79 ( V_2 -> V_17 -> V_17 . V_180 ,
V_55 -> V_143 ,
V_55 -> V_163 , V_181 ) ;
if ( ! V_170 )
continue;
F_80 ( V_170 ) ;
}
}
static void F_81 ( struct V_1 * V_2 ,
struct V_6 * V_7 )
{
struct V_182 * V_183 = F_82 ( V_2 -> V_17 , V_7 -> V_37 ) ;
int V_184 ;
V_184 = F_69 ( V_2 , V_7 ) ;
if ( ! V_184 )
return;
F_77 ( V_2 , V_7 , V_184 ) ;
V_7 -> V_69 -= V_184 ;
if ( F_83 ( V_183 ) ) {
if ( V_7 -> V_69 <= V_7 -> V_185 )
F_84 ( V_183 ) ;
}
}
static void * F_85 ( const struct V_1 * V_2 )
{
if ( F_86 ( V_2 -> V_186 <= V_187 ) )
return F_87 ( V_2 -> V_186 ) ;
else
return F_88 ( V_2 -> V_186 , V_188 ) ;
}
static void F_89 ( const struct V_1 * V_2 , void * V_4 )
{
if ( F_86 ( V_2 -> V_186 <= V_187 ) )
F_90 ( F_91 ( V_4 ) ) ;
else
F_92 ( V_4 ) ;
}
static int F_93 ( struct V_1 * V_2 ,
struct V_43 * V_44 )
{
T_4 V_140 ;
void * V_4 ;
V_4 = F_85 ( V_2 ) ;
if ( ! V_4 )
return - V_189 ;
V_140 = F_94 ( V_2 -> V_17 -> V_17 . V_180 , V_4 ,
F_95 ( V_2 -> V_190 ) ,
V_191 ) ;
if ( F_96 ( F_97 ( V_2 -> V_17 -> V_17 . V_180 , V_140 ) ) ) {
F_89 ( V_2 , V_4 ) ;
return - V_189 ;
}
F_65 ( V_44 , V_140 , ( T_1 ) V_4 ) ;
return 0 ;
}
static T_1 F_98 ( struct V_1 * V_2 , struct V_169 * V_170 )
{
if ( V_170 -> V_174 == V_192 ) {
int V_150 = 0 ;
T_5 V_149 = F_99 ( V_170 ) ;
T_3 V_151 ;
if ( V_149 == F_71 ( V_155 ) ) {
struct V_193 * V_194 = F_100 ( V_170 ) ;
V_150 = V_194 -> V_195 ;
V_151 = V_194 -> V_196 ;
} else if ( V_149 == F_71 ( V_197 ) ) {
struct V_198 * V_199 = F_101 ( V_170 ) ;
if ( F_102 ( V_170 ) > 0 )
V_150 = ( F_102 ( V_170 ) >> 2 ) ;
V_151 = V_199 -> V_200 ;
} else
return V_162 ;
return F_70 ( F_103 ( V_170 ) ,
V_149 , V_150 , V_151 ) ;
}
return V_162 ;
}
static struct V_33 * F_104 ( struct V_1 * V_2 ,
T_1 V_177 )
{
int V_61 = F_76 ( V_177 >> 8 ) - 1 ;
return ( V_61 < 0 || V_61 >= V_66 ) ? NULL : & V_2 -> V_67 [ V_61 ] ;
}
static void F_105 ( struct V_1 * V_2 ,
struct V_33 * V_34 )
{
int V_41 , V_11 ;
V_41 = F_17 ( V_2 , V_34 ) ;
for ( V_11 = 0 ; V_11 < V_34 -> V_9 ; V_11 ++ ) {
struct V_43 * V_44 = V_34 -> V_46 + V_11 ;
void * V_4 = ( void * ) V_44 -> V_142 ;
F_89 ( V_2 , V_4 ) ;
F_79 ( V_2 -> V_17 -> V_17 . V_180 , V_44 -> V_143 ,
F_95 ( V_2 -> V_190 ) , V_191 ) ;
}
if ( V_41 )
F_19 ( V_2 , V_34 , V_41 , V_41 ) ;
}
static int F_106 ( struct V_1 * V_2 , int V_201 ,
struct V_33 * V_34 )
{
struct V_16 * V_17 = V_2 -> V_17 ;
int V_41 , V_42 ;
T_1 V_202 = 0 ;
T_1 V_203 = 0 ;
V_41 = F_17 ( V_2 , V_34 ) ;
if ( V_201 > V_41 )
V_201 = V_41 ;
V_41 = 0 ;
V_42 = 0 ;
while ( V_41 < V_201 ) {
struct V_43 * V_44 = F_20 ( V_34 ) ;
struct V_169 * V_170 ;
unsigned char * V_4 ;
T_1 V_204 ;
int V_24 , V_205 ;
V_41 ++ ;
V_42 ++ ;
V_204 = V_44 -> V_31 ;
V_24 = V_44 -> V_163 - ( V_206 + V_50 ) ;
V_4 = ( unsigned char * ) V_44 -> V_142 ;
if ( ! F_14 ( V_204 ) ||
( V_204 & V_207 ) ) {
V_208:
V_17 -> V_18 . V_28 ++ ;
F_72 ( V_2 , V_44 ) ;
continue;
}
if ( V_24 <= V_209 ) {
V_170 = F_107 ( V_17 , V_24 ) ;
if ( F_96 ( ! V_170 ) )
goto V_208;
F_108 ( V_17 -> V_17 . V_180 ,
V_44 -> V_143 ,
V_50 + V_210 ,
V_24 ,
V_191 ) ;
memcpy ( F_109 ( V_170 , V_24 ) ,
V_4 + V_50 + V_210 ,
V_24 ) ;
V_170 -> V_196 = F_110 ( V_170 , V_17 ) ;
F_74 ( V_2 , V_204 , V_170 ) ;
F_111 ( & V_2 -> V_211 , V_170 ) ;
V_202 ++ ;
V_203 += V_24 ;
continue;
}
V_170 = F_112 ( V_4 , V_2 -> V_186 > V_187 ? 0 : V_2 -> V_186 ) ;
if ( ! V_170 )
goto V_208;
F_79 ( V_17 -> V_17 . V_180 , V_44 -> V_143 ,
F_95 ( V_2 -> V_190 ) , V_191 ) ;
V_202 ++ ;
V_203 += V_24 ;
F_113 ( V_170 , V_50 + V_210 ) ;
F_109 ( V_170 , V_24 ) ;
V_170 -> V_196 = F_110 ( V_170 , V_17 ) ;
F_74 ( V_2 , V_204 , V_170 ) ;
F_111 ( & V_2 -> V_211 , V_170 ) ;
V_205 = F_93 ( V_2 , V_44 ) ;
if ( V_205 ) {
F_73 ( V_17 , L_9 ) ;
V_34 -> V_212 ++ ;
V_42 -- ;
}
}
if ( V_202 ) {
struct V_21 * V_18 = F_114 ( V_2 -> V_18 ) ;
F_115 ( & V_18 -> V_27 ) ;
V_18 -> V_23 += V_202 ;
V_18 -> V_24 += V_203 ;
F_116 ( & V_18 -> V_27 ) ;
}
F_19 ( V_2 , V_34 , V_41 , V_42 ) ;
return V_41 ;
}
static inline void
F_117 ( struct V_169 * V_170 ,
struct V_1 * V_2 , struct V_6 * V_7 )
{
struct V_54 * V_55 ;
int V_213 = F_118 ( V_170 ) + F_119 ( V_170 ) ;
V_7 -> V_179 [ V_7 -> V_10 ] = NULL ;
V_55 = F_29 ( V_7 ) ;
V_55 -> V_163 = V_213 ;
V_55 -> V_152 = F_98 ( V_2 , V_170 ) ;
V_55 -> V_152 |= V_214 ;
V_55 -> V_143 = V_7 -> V_215 +
V_7 -> V_10 * V_216 ;
F_6 ( V_7 ) ;
}
static inline int
F_120 ( struct V_16 * V_17 , struct V_6 * V_7 ,
struct V_169 * V_170 , char * V_4 , int V_9 ,
bool V_217 , bool V_218 )
{
struct V_54 * V_55 ;
V_55 = F_29 ( V_7 ) ;
V_55 -> V_163 = V_9 ;
V_55 -> V_143 = F_94 ( V_17 -> V_17 . V_180 , V_4 ,
V_9 , V_181 ) ;
if ( F_96 ( F_97 ( V_17 -> V_17 . V_180 ,
V_55 -> V_143 ) ) ) {
F_30 ( V_7 ) ;
return - V_189 ;
}
V_55 -> V_152 = 0 ;
V_7 -> V_179 [ V_7 -> V_10 ] = NULL ;
if ( V_217 ) {
V_55 -> V_152 = V_219 ;
if ( V_218 )
V_7 -> V_179 [ V_7 -> V_10 ] = V_170 ;
}
F_6 ( V_7 ) ;
return 0 ;
}
static int F_121 ( struct V_169 * V_170 , struct V_16 * V_17 ,
struct V_6 * V_7 )
{
int V_220 , V_221 ;
int V_222 = 0 ;
struct V_1 * V_2 = F_9 ( V_17 ) ;
struct V_223 V_224 ;
int V_213 = F_118 ( V_170 ) + F_119 ( V_170 ) ;
int V_11 ;
if ( ( V_7 -> V_69 + F_122 ( V_170 ) ) >= V_7 -> V_9 )
return 0 ;
if ( F_123 ( V_170 ) < ( F_118 ( V_170 ) + F_119 ( V_170 ) ) ) {
F_124 ( L_10 ) ;
return 0 ;
}
F_125 ( V_170 , & V_224 ) ;
V_220 = V_170 -> V_225 - V_213 ;
while ( V_220 > 0 ) {
char * V_226 ;
V_221 = F_126 ( int , F_127 ( V_170 ) -> V_227 , V_220 ) ;
V_220 -= V_221 ;
V_222 ++ ;
V_226 = V_7 -> V_228 + V_7 -> V_10 * V_216 ;
F_128 ( V_170 , V_226 , & V_224 , V_221 , V_220 == 0 ) ;
F_117 ( V_170 , V_2 , V_7 ) ;
while ( V_221 > 0 ) {
int V_9 ;
V_222 ++ ;
V_9 = F_126 ( int , V_224 . V_9 , V_221 ) ;
if ( F_120 ( V_17 , V_7 , V_170 ,
V_224 . V_4 , V_9 ,
V_9 == V_221 ,
V_220 == 0 ) )
goto V_229;
V_221 -= V_9 ;
F_129 ( V_170 , & V_224 , V_9 ) ;
}
}
return V_222 ;
V_229:
for ( V_11 = V_222 - 1 ; V_11 >= 0 ; V_11 -- ) {
struct V_54 * V_55 = V_7 -> V_46 + V_11 ;
if ( ! F_78 ( V_7 , V_55 -> V_143 ) )
F_79 ( V_2 -> V_17 -> V_17 . V_180 ,
V_55 -> V_143 ,
V_55 -> V_163 ,
V_181 ) ;
F_30 ( V_7 ) ;
}
return 0 ;
}
static int F_130 ( struct V_1 * V_2 , struct V_169 * V_170 ,
struct V_6 * V_7 )
{
struct V_54 * V_55 ;
int V_11 , V_230 = F_127 ( V_170 ) -> V_230 ;
for ( V_11 = 0 ; V_11 < V_230 ; V_11 ++ ) {
T_6 * V_231 = & F_127 ( V_170 ) -> V_232 [ V_11 ] ;
void * V_128 = F_131 ( V_231 -> V_233 . V_234 ) + V_231 -> V_235 ;
V_55 = F_29 ( V_7 ) ;
V_55 -> V_163 = V_231 -> V_9 ;
V_55 -> V_143 =
F_94 ( V_2 -> V_17 -> V_17 . V_180 , V_128 ,
V_55 -> V_163 , V_181 ) ;
if ( F_97 ( V_2 -> V_17 -> V_17 . V_180 ,
V_55 -> V_143 ) ) {
F_30 ( V_7 ) ;
goto error;
}
if ( V_11 == V_230 - 1 ) {
V_55 -> V_152 = V_219 | V_236 ;
V_7 -> V_179 [ V_7 -> V_10 ] = V_170 ;
} else {
V_55 -> V_152 = 0 ;
V_7 -> V_179 [ V_7 -> V_10 ] = NULL ;
}
F_6 ( V_7 ) ;
}
return 0 ;
error:
for ( V_11 = V_11 - 1 ; V_11 >= 0 ; V_11 -- ) {
V_55 = V_7 -> V_46 + V_11 ;
F_79 ( V_2 -> V_17 -> V_17 . V_180 ,
V_55 -> V_143 ,
V_55 -> V_163 ,
V_181 ) ;
F_30 ( V_7 ) ;
}
return - V_189 ;
}
static int F_132 ( struct V_169 * V_170 , struct V_16 * V_17 )
{
struct V_1 * V_2 = F_9 ( V_17 ) ;
T_7 V_237 = F_133 ( V_170 ) ;
struct V_6 * V_7 = & V_2 -> V_64 [ V_237 ] ;
struct V_54 * V_55 ;
int V_225 = V_170 -> V_225 ;
int V_232 = 0 ;
T_1 V_238 ;
if ( ! F_134 ( V_17 ) )
goto V_239;
if ( F_135 ( V_170 ) ) {
V_232 = F_121 ( V_170 , V_17 , V_7 ) ;
goto V_239;
}
V_232 = F_127 ( V_170 ) -> V_230 + 1 ;
V_55 = F_29 ( V_7 ) ;
V_238 = F_98 ( V_2 , V_170 ) ;
V_55 -> V_163 = F_123 ( V_170 ) ;
V_55 -> V_143 = F_94 ( V_17 -> V_17 . V_180 , V_170 -> V_4 ,
V_55 -> V_163 ,
V_181 ) ;
if ( F_96 ( F_97 ( V_17 -> V_17 . V_180 ,
V_55 -> V_143 ) ) ) {
F_30 ( V_7 ) ;
V_232 = 0 ;
goto V_239;
}
if ( V_232 == 1 ) {
V_238 |= V_240 ;
V_55 -> V_152 = V_238 ;
V_7 -> V_179 [ V_7 -> V_10 ] = V_170 ;
F_6 ( V_7 ) ;
} else {
V_238 |= V_214 ;
V_7 -> V_179 [ V_7 -> V_10 ] = NULL ;
F_6 ( V_7 ) ;
V_55 -> V_152 = V_238 ;
if ( F_130 ( V_2 , V_170 , V_7 ) ) {
F_79 ( V_17 -> V_17 . V_180 ,
V_55 -> V_143 ,
V_55 -> V_163 ,
V_181 ) ;
F_30 ( V_7 ) ;
V_232 = 0 ;
goto V_239;
}
}
V_239:
if ( V_232 > 0 ) {
struct V_21 * V_18 = F_114 ( V_2 -> V_18 ) ;
struct V_182 * V_183 = F_82 ( V_17 , V_237 ) ;
V_7 -> V_69 += V_232 ;
F_27 ( V_2 , V_7 , V_232 ) ;
if ( V_7 -> V_69 >= V_7 -> V_241 )
F_136 ( V_183 ) ;
F_115 ( & V_18 -> V_27 ) ;
V_18 -> V_25 ++ ;
V_18 -> V_26 += V_225 ;
F_116 ( & V_18 -> V_27 ) ;
} else {
V_17 -> V_18 . V_30 ++ ;
F_80 ( V_170 ) ;
}
return V_242 ;
}
static void F_137 ( struct V_1 * V_2 ,
struct V_6 * V_7 )
{
int V_184 = V_7 -> V_69 ;
F_77 ( V_2 , V_7 , V_184 ) ;
V_7 -> V_69 = 0 ;
V_7 -> V_10 = 0 ;
V_7 -> V_8 = 0 ;
}
static void F_138 ( struct V_1 * V_2 , T_1 V_243 )
{
struct V_6 * V_7 ;
struct V_182 * V_183 ;
while ( V_243 ) {
V_7 = F_75 ( V_2 , V_243 ) ;
V_183 = F_82 ( V_2 -> V_17 , V_7 -> V_37 ) ;
F_139 ( V_183 , F_140 () ) ;
if ( V_7 -> V_69 )
F_81 ( V_2 , V_7 ) ;
F_141 ( V_183 ) ;
V_243 &= ~ ( ( 1 << V_7 -> V_37 ) ) ;
}
}
static int F_142 ( unsigned char * V_128 )
{
int V_244 = 0 ;
int V_11 ;
for ( V_11 = 0 ; V_11 < V_245 ; V_11 ++ ) {
int V_246 ;
V_244 = ( V_244 ^ V_128 [ V_11 ] ) << 8 ;
for ( V_246 = 7 ; V_246 >= 0 ; V_246 -- ) {
if ( V_244 & ( 0x100 << V_246 ) )
V_244 ^= 0x107 << V_246 ;
}
}
return V_244 ;
}
static void F_143 ( struct V_1 * V_2 ,
unsigned char V_247 ,
int V_61 )
{
unsigned int V_248 ;
unsigned int V_126 ;
unsigned int V_127 ;
V_126 = ( V_247 / 4 ) ;
V_127 = V_247 % 4 ;
V_248 = F_3 ( V_2 , ( V_82
+ V_126 * 4 ) ) ;
if ( V_61 == - 1 )
V_248 &= ~ ( 0xff << ( 8 * V_127 ) ) ;
else {
V_248 &= ~ ( 0xff << ( 8 * V_127 ) ) ;
V_248 |= ( ( 0x01 | ( V_61 << 1 ) ) << ( 8 * V_127 ) ) ;
}
F_1 ( V_2 , V_82 + V_126 * 4 ,
V_248 ) ;
}
static void F_144 ( struct V_1 * V_2 ,
unsigned char V_249 ,
int V_61 )
{
unsigned int V_250 ;
unsigned int V_126 ;
unsigned int V_127 ;
V_126 = ( V_249 / 4 ) * 4 ;
V_127 = V_249 % 4 ;
V_250 = F_3 ( V_2 , V_84 + V_126 ) ;
if ( V_61 == - 1 ) {
V_250 &= ~ ( 0xff << ( 8 * V_127 ) ) ;
} else {
V_250 &= ~ ( 0xff << ( 8 * V_127 ) ) ;
V_250 |= ( ( 0x01 | ( V_61 << 1 ) ) << ( 8 * V_127 ) ) ;
}
F_1 ( V_2 , V_84 + V_126 , V_250 ) ;
}
static int F_145 ( struct V_1 * V_2 , unsigned char * V_251 ,
int V_61 )
{
unsigned char V_252 = 0 ;
if ( memcmp ( V_251 , L_11 , 5 ) == 0 ) {
F_143 ( V_2 , V_251 [ 5 ] , V_61 ) ;
return 0 ;
}
V_252 = F_142 ( V_251 ) ;
if ( V_61 == - 1 ) {
if ( V_2 -> V_83 [ V_252 ] == 0 ) {
F_146 ( V_2 -> V_17 , L_12 ,
V_252 ) ;
return - V_253 ;
}
V_2 -> V_83 [ V_252 ] -- ;
if ( V_2 -> V_83 [ V_252 ] != 0 ) {
F_146 ( V_2 -> V_17 ,
L_13 ,
V_2 -> V_83 [ V_252 ] , V_252 ) ;
return - V_253 ;
}
} else
V_2 -> V_83 [ V_252 ] ++ ;
F_144 ( V_2 , V_252 , V_61 ) ;
return 0 ;
}
static void F_147 ( struct V_1 * V_2 ,
int V_254 )
{
T_1 V_255 , V_39 ;
V_255 = F_3 ( V_2 , V_104 ) ;
V_39 = F_3 ( V_2 , V_256 ) ;
if ( V_254 ) {
V_255 |= V_257 ;
V_39 |= V_258 ;
F_1 ( V_2 , V_131 , 0xffff ) ;
F_1 ( V_2 , V_132 , 0xffffffff ) ;
} else {
V_255 &= ~ V_257 ;
V_39 &= ~ V_258 ;
}
F_1 ( V_2 , V_104 , V_255 ) ;
F_1 ( V_2 , V_256 , V_39 ) ;
}
static void F_148 ( struct V_16 * V_17 )
{
struct V_1 * V_2 = F_9 ( V_17 ) ;
struct V_259 * V_260 ;
if ( V_17 -> V_261 & V_262 ) {
F_147 ( V_2 , 1 ) ;
F_41 ( V_2 , V_103 ) ;
F_42 ( V_2 , V_103 ) ;
F_43 ( V_2 , V_103 ) ;
} else {
F_147 ( V_2 , 0 ) ;
F_41 ( V_2 , - 1 ) ;
F_55 ( V_2 , V_17 -> V_263 , V_103 ) ;
if ( V_17 -> V_261 & V_264 ) {
F_42 ( V_2 , V_103 ) ;
F_43 ( V_2 , V_103 ) ;
} else {
F_42 ( V_2 , - 1 ) ;
F_43 ( V_2 , - 1 ) ;
if ( ! F_149 ( V_17 ) ) {
F_150 (ha, dev) {
F_145 ( V_2 , V_260 -> V_128 ,
V_103 ) ;
}
}
}
}
}
static T_8 F_151 ( int V_265 , void * V_266 )
{
struct V_1 * V_2 = (struct V_1 * ) V_266 ;
F_1 ( V_2 , V_88 , 0 ) ;
F_152 ( & V_2 -> V_211 ) ;
return V_267 ;
}
static int F_153 ( struct V_268 * V_211 , int V_269 )
{
int V_41 = 0 ;
T_1 V_270 ;
unsigned long V_261 ;
struct V_1 * V_2 = F_9 ( V_211 -> V_17 ) ;
if ( ! F_134 ( V_2 -> V_17 ) ) {
F_154 ( V_211 ) ;
return V_41 ;
}
V_270 = F_3 ( V_2 , V_85 ) &
( F_155 ( V_66 ) | F_156 ( V_63 ) ) ;
if ( V_270 & V_271 ) {
F_138 ( V_2 , ( V_270 & V_271 ) ) ;
V_270 &= ~ V_271 ;
}
V_270 |= V_2 -> V_270 ;
if ( V_66 > 1 ) {
while ( ( V_270 & V_272 ) && ( V_269 > 0 ) ) {
int V_69 ;
struct V_33 * V_34 ;
V_34 = F_104 ( V_2 , V_270 ) ;
if ( ! V_34 )
break;
V_69 = F_106 ( V_2 , V_269 , V_34 ) ;
V_41 += V_69 ;
V_269 -= V_69 ;
if ( V_269 > 0 ) {
V_270 &= ~ ( ( 1 << V_34 -> V_37 ) << 8 ) ;
}
}
} else {
V_41 = F_106 ( V_2 , V_269 , & V_2 -> V_67 [ V_103 ] ) ;
V_269 -= V_41 ;
}
if ( V_269 > 0 ) {
V_270 = 0 ;
F_154 ( V_211 ) ;
F_157 ( V_261 ) ;
F_1 ( V_2 , V_88 ,
F_155 ( V_66 ) | F_156 ( V_63 ) ) ;
F_158 ( V_261 ) ;
}
V_2 -> V_270 = V_270 ;
return V_41 ;
}
static int F_159 ( struct V_1 * V_2 , struct V_33 * V_34 ,
int V_178 )
{
int V_11 ;
for ( V_11 = 0 ; V_11 < V_178 ; V_11 ++ ) {
memset ( V_34 -> V_46 + V_11 , 0 , sizeof( struct V_43 ) ) ;
if ( F_93 ( V_2 , V_34 -> V_46 + V_11 ) != 0 ) {
F_73 ( V_2 -> V_17 , L_14 ,
V_273 , V_34 -> V_37 , V_11 , V_178 ) ;
break;
}
}
F_15 ( V_2 , V_34 , V_11 ) ;
return V_11 ;
}
static void F_160 ( struct V_1 * V_2 )
{
int V_61 ;
for ( V_61 = 0 ; V_61 < V_63 ; V_61 ++ )
F_137 ( V_2 , & V_2 -> V_64 [ V_61 ] ) ;
F_1 ( V_2 , V_98 , V_99 ) ;
F_1 ( V_2 , V_98 , 0 ) ;
}
static void F_161 ( struct V_1 * V_2 )
{
F_1 ( V_2 , V_96 , V_97 ) ;
F_1 ( V_2 , V_96 , 0 ) ;
}
static int F_162 ( struct V_1 * V_2 ,
struct V_33 * V_34 )
{
V_34 -> V_9 = V_2 -> V_274 ;
V_34 -> V_46 = F_163 ( V_2 -> V_17 -> V_17 . V_180 ,
V_34 -> V_9 * V_275 ,
& V_34 -> V_276 , V_277 ) ;
if ( V_34 -> V_46 == NULL )
return - V_189 ;
F_164 ( V_34 -> V_46 !=
F_165 ( V_34 -> V_46 , V_278 ) ) ;
V_34 -> V_56 = V_34 -> V_9 - 1 ;
F_1 ( V_2 , F_166 ( V_34 -> V_37 ) , V_34 -> V_276 ) ;
F_1 ( V_2 , F_32 ( V_34 -> V_37 ) , V_34 -> V_9 ) ;
F_24 ( V_2 , V_34 , V_210 ) ;
F_56 ( V_2 , V_34 , V_34 -> V_134 ) ;
F_59 ( V_2 , V_34 , V_34 -> V_137 ) ;
F_31 ( V_2 , V_34 , F_95 ( V_2 -> V_190 ) ) ;
F_33 ( V_2 , V_34 ) ;
F_159 ( V_2 , V_34 , V_34 -> V_9 ) ;
return 0 ;
}
static void F_167 ( struct V_1 * V_2 ,
struct V_33 * V_34 )
{
F_105 ( V_2 , V_34 ) ;
if ( V_34 -> V_46 )
F_168 ( V_2 -> V_17 -> V_17 . V_180 ,
V_34 -> V_9 * V_275 ,
V_34 -> V_46 ,
V_34 -> V_276 ) ;
V_34 -> V_46 = NULL ;
V_34 -> V_56 = 0 ;
V_34 -> V_45 = 0 ;
V_34 -> V_276 = 0 ;
}
static int F_169 ( struct V_1 * V_2 ,
struct V_6 * V_7 )
{
V_7 -> V_9 = V_2 -> V_279 ;
V_7 -> V_241 = V_7 -> V_9 - V_280 ;
V_7 -> V_185 = V_7 -> V_241 / 2 ;
V_7 -> V_46 = F_163 ( V_2 -> V_17 -> V_17 . V_180 ,
V_7 -> V_9 * V_275 ,
& V_7 -> V_276 , V_277 ) ;
if ( V_7 -> V_46 == NULL )
return - V_189 ;
F_164 ( V_7 -> V_46 !=
F_165 ( V_7 -> V_46 , V_278 ) ) ;
V_7 -> V_56 = V_7 -> V_9 - 1 ;
F_1 ( V_2 , F_47 ( V_7 -> V_37 ) , 0x03ffffff ) ;
F_1 ( V_2 , F_46 ( V_7 -> V_37 ) , 0x3fffffff ) ;
F_1 ( V_2 , F_170 ( V_7 -> V_37 ) , V_7 -> V_276 ) ;
F_1 ( V_2 , F_63 ( V_7 -> V_37 ) , V_7 -> V_9 ) ;
V_7 -> V_179 = F_88 ( V_7 -> V_9 * sizeof( * V_7 -> V_179 ) , V_277 ) ;
if ( V_7 -> V_179 == NULL ) {
F_168 ( V_2 -> V_17 -> V_17 . V_180 ,
V_7 -> V_9 * V_275 ,
V_7 -> V_46 , V_7 -> V_276 ) ;
return - V_189 ;
}
V_7 -> V_228 = F_163 ( V_2 -> V_17 -> V_17 . V_180 ,
V_7 -> V_9 * V_216 ,
& V_7 -> V_215 , V_277 ) ;
if ( V_7 -> V_228 == NULL ) {
F_92 ( V_7 -> V_179 ) ;
F_168 ( V_2 -> V_17 -> V_17 . V_180 ,
V_7 -> V_9 * V_275 ,
V_7 -> V_46 , V_7 -> V_276 ) ;
return - V_189 ;
}
F_62 ( V_2 , V_7 , V_7 -> V_139 ) ;
return 0 ;
}
static void F_171 ( struct V_1 * V_2 ,
struct V_6 * V_7 )
{
F_92 ( V_7 -> V_179 ) ;
if ( V_7 -> V_228 )
F_168 ( V_2 -> V_17 -> V_17 . V_180 ,
V_7 -> V_9 * V_216 ,
V_7 -> V_228 , V_7 -> V_215 ) ;
if ( V_7 -> V_46 )
F_168 ( V_2 -> V_17 -> V_17 . V_180 ,
V_7 -> V_9 * V_275 ,
V_7 -> V_46 , V_7 -> V_276 ) ;
V_7 -> V_46 = NULL ;
V_7 -> V_56 = 0 ;
V_7 -> V_45 = 0 ;
V_7 -> V_276 = 0 ;
F_1 ( V_2 , F_47 ( V_7 -> V_37 ) , 0 ) ;
F_1 ( V_2 , F_46 ( V_7 -> V_37 ) , 0 ) ;
F_1 ( V_2 , F_170 ( V_7 -> V_37 ) , 0 ) ;
F_1 ( V_2 , F_63 ( V_7 -> V_37 ) , 0 ) ;
}
static void F_172 ( struct V_1 * V_2 )
{
int V_61 ;
for ( V_61 = 0 ; V_61 < V_63 ; V_61 ++ )
F_171 ( V_2 , & V_2 -> V_64 [ V_61 ] ) ;
}
static void F_173 ( struct V_1 * V_2 )
{
int V_61 ;
for ( V_61 = 0 ; V_61 < V_66 ; V_61 ++ )
F_167 ( V_2 , & V_2 -> V_67 [ V_61 ] ) ;
}
static int F_174 ( struct V_1 * V_2 )
{
int V_61 ;
for ( V_61 = 0 ; V_61 < V_66 ; V_61 ++ ) {
int V_205 = F_162 ( V_2 , & V_2 -> V_67 [ V_61 ] ) ;
if ( V_205 ) {
F_73 ( V_2 -> V_17 , L_15 ,
V_273 , V_61 ) ;
F_173 ( V_2 ) ;
return V_205 ;
}
}
return 0 ;
}
static int F_175 ( struct V_1 * V_2 )
{
int V_61 ;
for ( V_61 = 0 ; V_61 < V_63 ; V_61 ++ ) {
int V_205 = F_169 ( V_2 , & V_2 -> V_64 [ V_61 ] ) ;
if ( V_205 ) {
F_73 ( V_2 -> V_17 , L_16 ,
V_273 , V_61 ) ;
F_172 ( V_2 ) ;
return V_205 ;
}
}
return 0 ;
}
static void F_176 ( struct V_1 * V_2 )
{
F_23 ( V_2 , V_2 -> V_190 ) ;
F_52 ( V_2 , V_2 -> V_190 ) ;
F_39 ( V_2 ) ;
F_177 ( & V_2 -> V_211 ) ;
F_1 ( V_2 , V_88 ,
F_155 ( V_66 ) | F_156 ( V_63 ) ) ;
F_178 ( V_2 -> V_281 ) ;
F_179 ( V_2 -> V_17 ) ;
}
static void F_180 ( struct V_1 * V_2 )
{
F_181 ( V_2 -> V_281 ) ;
F_182 ( & V_2 -> V_211 ) ;
F_183 ( V_2 -> V_17 ) ;
F_35 ( V_2 ) ;
F_184 ( V_2 -> V_17 ) ;
F_40 ( V_2 ) ;
F_1 ( V_2 , V_87 , 0 ) ;
F_1 ( V_2 , V_86 , 0 ) ;
F_1 ( V_2 , V_88 , 0 ) ;
F_1 ( V_2 , V_89 , 0 ) ;
F_1 ( V_2 , V_90 , 0 ) ;
F_160 ( V_2 ) ;
F_161 ( V_2 ) ;
}
static int F_185 ( struct V_16 * V_17 , int V_118 )
{
if ( V_118 < 68 ) {
F_73 ( V_17 , L_17 ) ;
return - V_253 ;
}
if ( V_118 > 9676 ) {
F_146 ( V_17 , L_18 , V_118 ) ;
V_118 = 9676 ;
}
if ( ! F_186 ( F_187 ( V_118 ) , 8 ) ) {
F_146 ( V_17 , L_19 ,
V_118 , F_188 ( F_187 ( V_118 ) , 8 ) ) ;
V_118 = F_188 ( F_187 ( V_118 ) , 8 ) ;
}
return V_118 ;
}
static int F_189 ( struct V_16 * V_17 , int V_118 )
{
struct V_1 * V_2 = F_9 ( V_17 ) ;
int V_282 ;
V_118 = F_185 ( V_17 , V_118 ) ;
if ( V_118 < 0 )
return - V_253 ;
V_17 -> V_118 = V_118 ;
if ( ! F_134 ( V_17 ) )
return 0 ;
F_180 ( V_2 ) ;
F_172 ( V_2 ) ;
F_173 ( V_2 ) ;
V_2 -> V_190 = F_187 ( V_17 -> V_118 ) ;
V_2 -> V_186 = F_190 ( F_95 ( V_2 -> V_190 ) ) +
F_190 ( sizeof( struct V_283 ) ) ;
V_282 = F_174 ( V_2 ) ;
if ( V_282 ) {
F_73 ( V_17 , L_20 ) ;
return V_282 ;
}
V_282 = F_175 ( V_2 ) ;
if ( V_282 ) {
F_73 ( V_17 , L_21 ) ;
return V_282 ;
}
F_176 ( V_2 ) ;
F_34 ( V_2 ) ;
return 0 ;
}
static void F_191 ( struct V_1 * V_2 , unsigned char * V_128 )
{
T_1 V_284 , V_285 ;
V_284 = F_3 ( V_2 , V_131 ) ;
V_285 = F_3 ( V_2 , V_132 ) ;
V_128 [ 0 ] = ( V_285 >> 24 ) & 0xFF ;
V_128 [ 1 ] = ( V_285 >> 16 ) & 0xFF ;
V_128 [ 2 ] = ( V_285 >> 8 ) & 0xFF ;
V_128 [ 3 ] = V_285 & 0xFF ;
V_128 [ 4 ] = ( V_284 >> 8 ) & 0xFF ;
V_128 [ 5 ] = V_284 & 0xFF ;
}
static int F_192 ( struct V_16 * V_17 , void * V_128 )
{
struct V_1 * V_2 = F_9 ( V_17 ) ;
struct V_286 * V_286 = V_128 ;
int V_282 ;
V_282 = F_193 ( V_17 , V_128 ) ;
if ( V_282 < 0 )
return V_282 ;
F_55 ( V_2 , V_17 -> V_263 , - 1 ) ;
F_55 ( V_2 , V_286 -> V_287 , V_103 ) ;
F_194 ( V_17 , V_128 ) ;
return 0 ;
}
static void F_195 ( struct V_16 * V_288 )
{
struct V_1 * V_2 = F_9 ( V_288 ) ;
struct V_289 * V_290 = V_2 -> V_281 ;
int V_291 = 0 ;
if ( V_290 -> V_292 ) {
if ( ( V_2 -> V_293 != V_290 -> V_293 ) ||
( V_2 -> V_294 != V_290 -> V_294 ) ) {
T_1 V_39 ;
V_39 = F_3 ( V_2 , V_295 ) ;
V_39 &= ~ ( V_296 |
V_297 |
V_298 |
V_299 |
V_300 ) ;
if ( V_290 -> V_294 )
V_39 |= V_298 ;
if ( V_290 -> V_293 == V_301 )
V_39 |= V_297 ;
else if ( V_290 -> V_293 == V_302 )
V_39 |= V_296 ;
F_1 ( V_2 , V_295 , V_39 ) ;
V_2 -> V_294 = V_290 -> V_294 ;
V_2 -> V_293 = V_290 -> V_293 ;
}
}
if ( V_290 -> V_292 != V_2 -> V_292 ) {
if ( ! V_290 -> V_292 ) {
V_2 -> V_294 = - 1 ;
V_2 -> V_293 = 0 ;
}
V_2 -> V_292 = V_290 -> V_292 ;
V_291 = 1 ;
}
if ( V_291 ) {
if ( V_290 -> V_292 ) {
T_1 V_39 = F_3 ( V_2 , V_295 ) ;
V_39 |= ( V_303 |
V_304 ) ;
F_1 ( V_2 , V_295 , V_39 ) ;
F_34 ( V_2 ) ;
} else {
F_35 ( V_2 ) ;
}
F_196 ( V_290 ) ;
}
}
static int F_197 ( struct V_1 * V_2 )
{
struct V_289 * V_281 ;
V_281 = F_198 ( V_2 -> V_17 , V_2 -> V_305 , F_195 , 0 ,
V_2 -> V_306 ) ;
if ( ! V_281 ) {
F_73 ( V_2 -> V_17 , L_22 ) ;
return - V_307 ;
}
V_281 -> V_308 &= V_309 ;
V_281 -> V_310 = V_281 -> V_308 ;
V_2 -> V_281 = V_281 ;
V_2 -> V_292 = 0 ;
V_2 -> V_294 = 0 ;
V_2 -> V_293 = 0 ;
return 0 ;
}
static void F_199 ( struct V_1 * V_2 )
{
F_200 ( V_2 -> V_281 ) ;
V_2 -> V_281 = NULL ;
}
static int F_201 ( struct V_16 * V_17 )
{
struct V_1 * V_2 = F_9 ( V_17 ) ;
int V_282 ;
V_2 -> V_190 = F_187 ( V_2 -> V_17 -> V_118 ) ;
V_2 -> V_186 = F_190 ( F_95 ( V_2 -> V_190 ) ) +
F_190 ( sizeof( struct V_283 ) ) ;
V_282 = F_174 ( V_2 ) ;
if ( V_282 )
return V_282 ;
V_282 = F_175 ( V_2 ) ;
if ( V_282 )
goto V_311;
V_282 = F_202 ( V_2 -> V_17 -> V_265 , F_151 , 0 ,
V_312 , V_2 ) ;
if ( V_282 ) {
F_73 ( V_2 -> V_17 , L_23 , V_2 -> V_17 -> V_265 ) ;
goto V_313;
}
F_183 ( V_2 -> V_17 ) ;
V_282 = F_197 ( V_2 ) ;
if ( V_282 < 0 ) {
F_73 ( V_17 , L_24 ) ;
goto V_314;
}
F_176 ( V_2 ) ;
return 0 ;
V_314:
F_203 ( V_2 -> V_17 -> V_265 , V_2 ) ;
V_313:
F_172 ( V_2 ) ;
V_311:
F_173 ( V_2 ) ;
return V_282 ;
}
static int F_204 ( struct V_16 * V_17 )
{
struct V_1 * V_2 = F_9 ( V_17 ) ;
F_180 ( V_2 ) ;
F_199 ( V_2 ) ;
F_203 ( V_17 -> V_265 , V_2 ) ;
F_173 ( V_2 ) ;
F_172 ( V_2 ) ;
return 0 ;
}
static int F_205 ( struct V_16 * V_17 , struct V_315 * V_316 , int V_317 )
{
struct V_1 * V_2 = F_9 ( V_17 ) ;
int V_282 ;
if ( ! V_2 -> V_281 )
return - V_318 ;
V_282 = F_206 ( V_2 -> V_281 , V_316 , V_317 ) ;
if ( ! V_282 )
F_195 ( V_17 ) ;
return V_282 ;
}
int F_207 ( struct V_16 * V_17 , struct V_319 * V_317 )
{
struct V_1 * V_2 = F_9 ( V_17 ) ;
if ( ! V_2 -> V_281 )
return - V_307 ;
return F_208 ( V_2 -> V_281 , V_317 ) ;
}
int F_209 ( struct V_16 * V_17 , struct V_319 * V_317 )
{
struct V_1 * V_2 = F_9 ( V_17 ) ;
if ( ! V_2 -> V_281 )
return - V_307 ;
return F_210 ( V_2 -> V_281 , V_317 ) ;
}
static int F_211 ( struct V_16 * V_17 ,
struct V_320 * V_321 )
{
struct V_1 * V_2 = F_9 ( V_17 ) ;
int V_61 ;
for ( V_61 = 0 ; V_61 < V_66 ; V_61 ++ ) {
struct V_33 * V_34 = & V_2 -> V_67 [ V_61 ] ;
V_34 -> V_137 = V_321 -> V_322 ;
V_34 -> V_134 = V_321 -> V_323 ;
F_56 ( V_2 , V_34 , V_34 -> V_134 ) ;
F_59 ( V_2 , V_34 , V_34 -> V_137 ) ;
}
for ( V_61 = 0 ; V_61 < V_63 ; V_61 ++ ) {
struct V_6 * V_7 = & V_2 -> V_64 [ V_61 ] ;
V_7 -> V_139 = V_321 -> V_324 ;
F_62 ( V_2 , V_7 , V_7 -> V_139 ) ;
}
return 0 ;
}
static int F_212 ( struct V_16 * V_17 ,
struct V_320 * V_321 )
{
struct V_1 * V_2 = F_9 ( V_17 ) ;
V_321 -> V_322 = V_2 -> V_67 [ 0 ] . V_137 ;
V_321 -> V_323 = V_2 -> V_67 [ 0 ] . V_134 ;
V_321 -> V_324 = V_2 -> V_64 [ 0 ] . V_139 ;
return 0 ;
}
static void F_213 ( struct V_16 * V_17 ,
struct V_325 * V_326 )
{
F_214 ( V_326 -> V_327 , V_312 ,
sizeof( V_326 -> V_327 ) ) ;
F_214 ( V_326 -> V_328 , V_329 ,
sizeof( V_326 -> V_328 ) ) ;
F_214 ( V_326 -> V_330 , F_215 ( & V_17 -> V_17 ) ,
sizeof( V_326 -> V_330 ) ) ;
}
static void F_216 ( struct V_16 * V_331 ,
struct V_332 * V_333 )
{
struct V_1 * V_2 = F_9 ( V_331 ) ;
V_333 -> V_334 = V_335 ;
V_333 -> V_336 = V_337 ;
V_333 -> V_338 = V_2 -> V_274 ;
V_333 -> V_339 = V_2 -> V_279 ;
}
static int F_217 ( struct V_16 * V_17 ,
struct V_332 * V_333 )
{
struct V_1 * V_2 = F_9 ( V_17 ) ;
if ( ( V_333 -> V_338 == 0 ) || ( V_333 -> V_339 == 0 ) )
return - V_253 ;
V_2 -> V_274 = V_333 -> V_338 < V_335 ?
V_333 -> V_338 : V_335 ;
V_2 -> V_279 = F_218 ( T_7 , V_333 -> V_339 ,
V_280 * 2 , V_337 ) ;
if ( V_2 -> V_279 != V_333 -> V_339 )
F_36 ( V_17 , L_25 ,
V_2 -> V_279 , V_333 -> V_339 ) ;
if ( F_134 ( V_17 ) ) {
F_204 ( V_17 ) ;
if ( F_201 ( V_17 ) ) {
F_73 ( V_17 ,
L_26 ) ;
return - V_189 ;
}
}
return 0 ;
}
static int F_219 ( struct V_340 * V_17 , struct V_1 * V_2 )
{
int V_61 ;
F_40 ( V_2 ) ;
F_44 ( V_2 ) ;
V_2 -> V_64 = F_220 ( V_17 , V_63 , sizeof( struct V_6 ) ,
V_277 ) ;
if ( ! V_2 -> V_64 )
return - V_189 ;
for ( V_61 = 0 ; V_61 < V_63 ; V_61 ++ ) {
struct V_6 * V_7 = & V_2 -> V_64 [ V_61 ] ;
V_7 -> V_37 = V_61 ;
V_7 -> V_9 = V_2 -> V_279 ;
V_7 -> V_139 = V_341 ;
}
V_2 -> V_67 = F_220 ( V_17 , V_66 , sizeof( struct V_33 ) ,
V_277 ) ;
if ( ! V_2 -> V_67 )
return - V_189 ;
for ( V_61 = 0 ; V_61 < V_66 ; V_61 ++ ) {
struct V_33 * V_34 = & V_2 -> V_67 [ V_61 ] ;
V_34 -> V_37 = V_61 ;
V_34 -> V_9 = V_2 -> V_274 ;
V_34 -> V_134 = V_342 ;
V_34 -> V_137 = V_343 ;
}
return 0 ;
}
static void F_221 ( struct V_1 * V_2 ,
const struct V_344 * V_345 )
{
T_1 V_346 ;
T_1 V_347 ;
int V_11 ;
for ( V_11 = 0 ; V_11 < 6 ; V_11 ++ ) {
F_1 ( V_2 , F_222 ( V_11 ) , 0 ) ;
F_1 ( V_2 , F_223 ( V_11 ) , 0 ) ;
if ( V_11 < 4 )
F_1 ( V_2 , F_224 ( V_11 ) , 0 ) ;
}
V_346 = 0x3f ;
V_347 = 0 ;
for ( V_11 = 0 ; V_11 < V_345 -> V_348 ; V_11 ++ ) {
const struct V_349 * V_350 = V_345 -> V_350 + V_11 ;
F_1 ( V_2 , F_222 ( V_11 ) , ( V_350 -> V_5 & 0xffff0000 ) |
( V_350 -> V_351 << 8 ) | V_345 -> V_352 ) ;
F_1 ( V_2 , F_223 ( V_11 ) ,
( V_350 -> V_9 - 1 ) & 0xffff0000 ) ;
V_346 &= ~ ( 1 << V_11 ) ;
V_347 |= 3 << ( 2 * V_11 ) ;
}
F_1 ( V_2 , V_353 , V_346 ) ;
}
static int F_225 ( struct V_1 * V_2 , int V_354 )
{
T_1 V_355 ;
F_1 ( V_2 , V_356 , 0 ) ;
V_355 = F_3 ( V_2 , V_357 ) ;
switch( V_354 ) {
case V_358 :
F_1 ( V_2 , V_359 , V_360 ) ;
V_355 |= V_361 | V_362 ;
break;
case V_363 :
F_1 ( V_2 , V_359 , V_364 ) ;
V_355 |= V_361 | V_362 ;
break;
case V_365 :
case V_366 :
V_355 |= V_362 ;
break;
default:
return - V_253 ;
}
V_355 &= ~ V_367 ;
F_1 ( V_2 , V_357 , V_355 ) ;
while ( ( F_3 ( V_2 , V_357 ) &
V_367 ) != 0 )
continue;
return 0 ;
}
static int F_226 ( struct V_368 * V_369 )
{
const struct V_344 * V_370 ;
struct V_371 * V_372 ;
struct V_373 * V_374 = V_369 -> V_17 . V_375 ;
struct V_373 * V_305 ;
struct V_1 * V_2 ;
struct V_16 * V_17 ;
const char * V_376 ;
char V_377 [ V_245 ] ;
const char * V_378 ;
int V_354 ;
int V_205 ;
if ( V_103 != 0 ) {
F_227 ( & V_369 -> V_17 , L_27 , V_103 ) ;
return - V_253 ;
}
V_17 = F_228 ( sizeof( struct V_1 ) , V_63 , V_66 ) ;
if ( ! V_17 )
return - V_189 ;
V_17 -> V_265 = F_229 ( V_374 , 0 ) ;
if ( V_17 -> V_265 == 0 ) {
V_205 = - V_253 ;
goto V_379;
}
V_305 = F_230 ( V_374 , L_28 , 0 ) ;
if ( ! V_305 ) {
if ( ! F_231 ( V_374 ) ) {
F_227 ( & V_369 -> V_17 , L_29 ) ;
V_205 = - V_307 ;
goto V_314;
}
V_205 = F_232 ( V_374 ) ;
if ( V_205 < 0 ) {
F_227 ( & V_369 -> V_17 , L_30 ) ;
goto V_314;
}
V_305 = F_233 ( V_374 ) ;
}
V_354 = F_234 ( V_374 ) ;
if ( V_354 < 0 ) {
F_227 ( & V_369 -> V_17 , L_31 ) ;
V_205 = - V_253 ;
goto V_380;
}
V_17 -> V_381 = V_337 ;
V_17 -> V_382 = 5 * V_383 ;
V_17 -> V_384 = & V_385 ;
V_17 -> V_386 = & V_387 ;
V_2 = F_9 ( V_17 ) ;
V_2 -> V_305 = V_305 ;
V_2 -> V_306 = V_354 ;
V_2 -> V_136 = F_235 ( & V_369 -> V_17 , NULL ) ;
if ( F_236 ( V_2 -> V_136 ) ) {
V_205 = F_237 ( V_2 -> V_136 ) ;
goto V_380;
}
F_238 ( V_2 -> V_136 ) ;
V_372 = F_239 ( V_369 , V_388 , 0 ) ;
V_2 -> V_5 = F_240 ( & V_369 -> V_17 , V_372 ) ;
if ( F_236 ( V_2 -> V_5 ) ) {
V_205 = F_237 ( V_2 -> V_5 ) ;
goto V_389;
}
V_2 -> V_18 = F_241 ( struct V_21 ) ;
if ( ! V_2 -> V_18 ) {
V_205 = - V_189 ;
goto V_389;
}
V_376 = F_242 ( V_374 ) ;
if ( V_376 ) {
V_378 = L_32 ;
memcpy ( V_17 -> V_263 , V_376 , V_245 ) ;
} else {
F_191 ( V_2 , V_377 ) ;
if ( F_243 ( V_377 ) ) {
V_378 = L_33 ;
memcpy ( V_17 -> V_263 , V_377 , V_245 ) ;
} else {
V_378 = L_34 ;
F_244 ( V_17 ) ;
}
}
V_2 -> V_279 = V_337 ;
V_2 -> V_274 = V_335 ;
V_2 -> V_17 = V_17 ;
F_245 ( V_17 , & V_369 -> V_17 ) ;
V_205 = F_219 ( & V_369 -> V_17 , V_2 ) ;
if ( V_205 < 0 )
goto V_390;
V_205 = F_225 ( V_2 , V_354 ) ;
if ( V_205 < 0 ) {
F_227 ( & V_369 -> V_17 , L_35 ) ;
goto V_390;
}
V_370 = F_246 () ;
if ( V_370 )
F_221 ( V_2 , V_370 ) ;
F_247 ( V_17 , & V_2 -> V_211 , F_153 , V_391 ) ;
V_17 -> V_392 = V_393 | V_394 | V_395 ;
V_17 -> V_396 |= V_17 -> V_392 ;
V_17 -> V_397 |= V_17 -> V_392 ;
V_17 -> V_398 |= V_399 ;
V_17 -> V_400 = V_401 ;
V_205 = F_248 ( V_17 ) ;
if ( V_205 < 0 ) {
F_227 ( & V_369 -> V_17 , L_36 ) ;
goto V_390;
}
F_146 ( V_17 , L_37 , V_378 ,
V_17 -> V_263 ) ;
F_249 ( V_369 , V_2 -> V_17 ) ;
return 0 ;
V_390:
F_250 ( V_2 -> V_18 ) ;
V_389:
F_251 ( V_2 -> V_136 ) ;
V_380:
F_252 ( V_305 ) ;
V_314:
F_253 ( V_17 -> V_265 ) ;
V_379:
F_254 ( V_17 ) ;
return V_205 ;
}
static int F_255 ( struct V_368 * V_369 )
{
struct V_16 * V_17 = F_256 ( V_369 ) ;
struct V_1 * V_2 = F_9 ( V_17 ) ;
F_257 ( V_17 ) ;
F_251 ( V_2 -> V_136 ) ;
F_250 ( V_2 -> V_18 ) ;
F_253 ( V_17 -> V_265 ) ;
F_252 ( V_2 -> V_305 ) ;
F_254 ( V_17 ) ;
return 0 ;
}
