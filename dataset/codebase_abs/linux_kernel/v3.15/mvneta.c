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
if ( ! V_170 )
continue;
F_78 ( V_2 -> V_17 -> V_17 . V_180 , V_55 -> V_143 ,
V_55 -> V_163 , V_181 ) ;
F_79 ( V_170 ) ;
}
}
static void F_80 ( struct V_1 * V_2 ,
struct V_6 * V_7 )
{
struct V_182 * V_183 = F_81 ( V_2 -> V_17 , V_7 -> V_37 ) ;
int V_184 ;
V_184 = F_69 ( V_2 , V_7 ) ;
if ( ! V_184 )
return;
F_77 ( V_2 , V_7 , V_184 ) ;
V_7 -> V_69 -= V_184 ;
if ( F_82 ( V_183 ) ) {
if ( V_7 -> V_9 - V_7 -> V_69 >= V_185 + 1 )
F_83 ( V_183 ) ;
}
}
static void * F_84 ( const struct V_1 * V_2 )
{
if ( F_85 ( V_2 -> V_186 <= V_187 ) )
return F_86 ( V_2 -> V_186 ) ;
else
return F_87 ( V_2 -> V_186 , V_188 ) ;
}
static void F_88 ( const struct V_1 * V_2 , void * V_4 )
{
if ( F_85 ( V_2 -> V_186 <= V_187 ) )
F_89 ( F_90 ( V_4 ) ) ;
else
F_91 ( V_4 ) ;
}
static int F_92 ( struct V_1 * V_2 ,
struct V_43 * V_44 )
{
T_4 V_140 ;
void * V_4 ;
V_4 = F_84 ( V_2 ) ;
if ( ! V_4 )
return - V_189 ;
V_140 = F_93 ( V_2 -> V_17 -> V_17 . V_180 , V_4 ,
F_94 ( V_2 -> V_190 ) ,
V_191 ) ;
if ( F_95 ( F_96 ( V_2 -> V_17 -> V_17 . V_180 , V_140 ) ) ) {
F_88 ( V_2 , V_4 ) ;
return - V_189 ;
}
F_65 ( V_44 , V_140 , ( T_1 ) V_4 ) ;
return 0 ;
}
static T_1 F_97 ( struct V_1 * V_2 , struct V_169 * V_170 )
{
if ( V_170 -> V_174 == V_192 ) {
int V_150 = 0 ;
T_3 V_151 ;
if ( V_170 -> V_193 == F_98 ( V_155 ) ) {
struct V_194 * V_195 = F_99 ( V_170 ) ;
V_150 = V_195 -> V_196 ;
V_151 = V_195 -> V_193 ;
} else if ( V_170 -> V_193 == F_98 ( V_197 ) ) {
struct V_198 * V_199 = F_100 ( V_170 ) ;
if ( F_101 ( V_170 ) > 0 )
V_150 = ( F_101 ( V_170 ) >> 2 ) ;
V_151 = V_199 -> V_200 ;
} else
return V_162 ;
return F_70 ( F_102 ( V_170 ) ,
V_170 -> V_193 , V_150 , V_151 ) ;
}
return V_162 ;
}
static struct V_33 * F_103 ( struct V_1 * V_2 ,
T_1 V_177 )
{
int V_61 = F_76 ( V_177 >> 8 ) - 1 ;
return ( V_61 < 0 || V_61 >= V_66 ) ? NULL : & V_2 -> V_67 [ V_61 ] ;
}
static void F_104 ( struct V_1 * V_2 ,
struct V_33 * V_34 )
{
int V_41 , V_11 ;
V_41 = F_17 ( V_2 , V_34 ) ;
for ( V_11 = 0 ; V_11 < V_34 -> V_9 ; V_11 ++ ) {
struct V_43 * V_44 = V_34 -> V_46 + V_11 ;
void * V_4 = ( void * ) V_44 -> V_142 ;
F_88 ( V_2 , V_4 ) ;
F_78 ( V_2 -> V_17 -> V_17 . V_180 , V_44 -> V_143 ,
F_94 ( V_2 -> V_190 ) , V_191 ) ;
}
if ( V_41 )
F_19 ( V_2 , V_34 , V_41 , V_41 ) ;
}
static int F_105 ( struct V_1 * V_2 , int V_201 ,
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
V_170 = F_106 ( V_17 , V_24 ) ;
if ( F_95 ( ! V_170 ) )
goto V_208;
F_107 ( V_17 -> V_17 . V_180 ,
V_44 -> V_143 ,
V_50 + V_210 ,
V_24 ,
V_191 ) ;
memcpy ( F_108 ( V_170 , V_24 ) ,
V_4 + V_50 + V_210 ,
V_24 ) ;
V_170 -> V_193 = F_109 ( V_170 , V_17 ) ;
F_74 ( V_2 , V_204 , V_170 ) ;
F_110 ( & V_2 -> V_211 , V_170 ) ;
V_202 ++ ;
V_203 += V_24 ;
continue;
}
V_170 = F_111 ( V_4 , V_2 -> V_186 > V_187 ? 0 : V_2 -> V_186 ) ;
if ( ! V_170 )
goto V_208;
F_78 ( V_17 -> V_17 . V_180 , V_44 -> V_143 ,
F_94 ( V_2 -> V_190 ) , V_191 ) ;
V_202 ++ ;
V_203 += V_24 ;
F_112 ( V_170 , V_50 + V_210 ) ;
F_108 ( V_170 , V_24 ) ;
V_170 -> V_193 = F_109 ( V_170 , V_17 ) ;
F_74 ( V_2 , V_204 , V_170 ) ;
F_110 ( & V_2 -> V_211 , V_170 ) ;
V_205 = F_92 ( V_2 , V_44 ) ;
if ( V_205 ) {
F_73 ( V_17 , L_9 ) ;
V_34 -> V_212 ++ ;
V_42 -- ;
}
}
if ( V_202 ) {
struct V_21 * V_18 = F_113 ( V_2 -> V_18 ) ;
F_114 ( & V_18 -> V_27 ) ;
V_18 -> V_23 += V_202 ;
V_18 -> V_24 += V_203 ;
F_115 ( & V_18 -> V_27 ) ;
}
F_19 ( V_2 , V_34 , V_41 , V_42 ) ;
return V_41 ;
}
static int F_116 ( struct V_1 * V_2 , struct V_169 * V_170 ,
struct V_6 * V_7 )
{
struct V_54 * V_55 ;
int V_11 ;
for ( V_11 = 0 ; V_11 < F_117 ( V_170 ) -> V_213 ; V_11 ++ ) {
T_5 * V_214 = & F_117 ( V_170 ) -> V_215 [ V_11 ] ;
void * V_128 = F_118 ( V_214 -> V_216 . V_217 ) + V_214 -> V_218 ;
V_55 = F_29 ( V_7 ) ;
V_55 -> V_163 = V_214 -> V_9 ;
V_55 -> V_143 =
F_93 ( V_2 -> V_17 -> V_17 . V_180 , V_128 ,
V_55 -> V_163 , V_181 ) ;
if ( F_96 ( V_2 -> V_17 -> V_17 . V_180 ,
V_55 -> V_143 ) ) {
F_30 ( V_7 ) ;
goto error;
}
if ( V_11 == ( F_117 ( V_170 ) -> V_213 - 1 ) ) {
V_55 -> V_152 = V_219 | V_220 ;
V_7 -> V_179 [ V_7 -> V_10 ] = V_170 ;
F_6 ( V_7 ) ;
} else {
V_55 -> V_152 = 0 ;
V_7 -> V_179 [ V_7 -> V_10 ] = NULL ;
F_6 ( V_7 ) ;
}
}
return 0 ;
error:
for ( V_11 = V_11 - 1 ; V_11 >= 0 ; V_11 -- ) {
V_55 = V_7 -> V_46 + V_11 ;
F_78 ( V_2 -> V_17 -> V_17 . V_180 ,
V_55 -> V_143 ,
V_55 -> V_163 ,
V_181 ) ;
F_30 ( V_7 ) ;
}
return - V_189 ;
}
static int F_119 ( struct V_169 * V_170 , struct V_16 * V_17 )
{
struct V_1 * V_2 = F_9 ( V_17 ) ;
T_6 V_221 = F_120 ( V_170 ) ;
struct V_6 * V_7 = & V_2 -> V_64 [ V_221 ] ;
struct V_54 * V_55 ;
struct V_182 * V_183 ;
int V_215 = 0 ;
T_1 V_222 ;
if ( ! F_121 ( V_17 ) )
goto V_223;
V_215 = F_117 ( V_170 ) -> V_213 + 1 ;
V_183 = F_81 ( V_17 , V_221 ) ;
V_55 = F_29 ( V_7 ) ;
V_222 = F_97 ( V_2 , V_170 ) ;
V_55 -> V_163 = F_122 ( V_170 ) ;
V_55 -> V_143 = F_93 ( V_17 -> V_17 . V_180 , V_170 -> V_4 ,
V_55 -> V_163 ,
V_181 ) ;
if ( F_95 ( F_96 ( V_17 -> V_17 . V_180 ,
V_55 -> V_143 ) ) ) {
F_30 ( V_7 ) ;
V_215 = 0 ;
goto V_223;
}
if ( V_215 == 1 ) {
V_222 |= V_224 ;
V_55 -> V_152 = V_222 ;
V_7 -> V_179 [ V_7 -> V_10 ] = V_170 ;
F_6 ( V_7 ) ;
} else {
V_222 |= V_225 ;
V_7 -> V_179 [ V_7 -> V_10 ] = NULL ;
F_6 ( V_7 ) ;
V_55 -> V_152 = V_222 ;
if ( F_116 ( V_2 , V_170 , V_7 ) ) {
F_78 ( V_17 -> V_17 . V_180 ,
V_55 -> V_143 ,
V_55 -> V_163 ,
V_181 ) ;
F_30 ( V_7 ) ;
V_215 = 0 ;
goto V_223;
}
}
V_7 -> V_69 += V_215 ;
F_27 ( V_2 , V_7 , V_215 ) ;
if ( V_7 -> V_9 - V_7 -> V_69 < V_185 + 1 )
F_123 ( V_183 ) ;
V_223:
if ( V_215 > 0 ) {
struct V_21 * V_18 = F_113 ( V_2 -> V_18 ) ;
F_114 ( & V_18 -> V_27 ) ;
V_18 -> V_25 ++ ;
V_18 -> V_26 += V_170 -> V_226 ;
F_115 ( & V_18 -> V_27 ) ;
} else {
V_17 -> V_18 . V_30 ++ ;
F_79 ( V_170 ) ;
}
return V_227 ;
}
static void F_124 ( struct V_1 * V_2 ,
struct V_6 * V_7 )
{
int V_184 = V_7 -> V_69 ;
F_77 ( V_2 , V_7 , V_184 ) ;
V_7 -> V_69 = 0 ;
V_7 -> V_10 = 0 ;
V_7 -> V_8 = 0 ;
}
static void F_125 ( struct V_1 * V_2 , T_1 V_228 )
{
struct V_6 * V_7 ;
struct V_182 * V_183 ;
while ( V_228 ) {
V_7 = F_75 ( V_2 , V_228 ) ;
V_183 = F_81 ( V_2 -> V_17 , V_7 -> V_37 ) ;
F_126 ( V_183 , F_127 () ) ;
if ( V_7 -> V_69 )
F_80 ( V_2 , V_7 ) ;
F_128 ( V_183 ) ;
V_228 &= ~ ( ( 1 << V_7 -> V_37 ) ) ;
}
}
static int F_129 ( unsigned char * V_128 )
{
int V_229 = 0 ;
int V_11 ;
for ( V_11 = 0 ; V_11 < V_230 ; V_11 ++ ) {
int V_231 ;
V_229 = ( V_229 ^ V_128 [ V_11 ] ) << 8 ;
for ( V_231 = 7 ; V_231 >= 0 ; V_231 -- ) {
if ( V_229 & ( 0x100 << V_231 ) )
V_229 ^= 0x107 << V_231 ;
}
}
return V_229 ;
}
static void F_130 ( struct V_1 * V_2 ,
unsigned char V_232 ,
int V_61 )
{
unsigned int V_233 ;
unsigned int V_126 ;
unsigned int V_127 ;
V_126 = ( V_232 / 4 ) ;
V_127 = V_232 % 4 ;
V_233 = F_3 ( V_2 , ( V_82
+ V_126 * 4 ) ) ;
if ( V_61 == - 1 )
V_233 &= ~ ( 0xff << ( 8 * V_127 ) ) ;
else {
V_233 &= ~ ( 0xff << ( 8 * V_127 ) ) ;
V_233 |= ( ( 0x01 | ( V_61 << 1 ) ) << ( 8 * V_127 ) ) ;
}
F_1 ( V_2 , V_82 + V_126 * 4 ,
V_233 ) ;
}
static void F_131 ( struct V_1 * V_2 ,
unsigned char V_234 ,
int V_61 )
{
unsigned int V_235 ;
unsigned int V_126 ;
unsigned int V_127 ;
V_126 = ( V_234 / 4 ) * 4 ;
V_127 = V_234 % 4 ;
V_235 = F_3 ( V_2 , V_84 + V_126 ) ;
if ( V_61 == - 1 ) {
V_235 &= ~ ( 0xff << ( 8 * V_127 ) ) ;
} else {
V_235 &= ~ ( 0xff << ( 8 * V_127 ) ) ;
V_235 |= ( ( 0x01 | ( V_61 << 1 ) ) << ( 8 * V_127 ) ) ;
}
F_1 ( V_2 , V_84 + V_126 , V_235 ) ;
}
static int F_132 ( struct V_1 * V_2 , unsigned char * V_236 ,
int V_61 )
{
unsigned char V_237 = 0 ;
if ( memcmp ( V_236 , L_10 , 5 ) == 0 ) {
F_130 ( V_2 , V_236 [ 5 ] , V_61 ) ;
return 0 ;
}
V_237 = F_129 ( V_236 ) ;
if ( V_61 == - 1 ) {
if ( V_2 -> V_83 [ V_237 ] == 0 ) {
F_133 ( V_2 -> V_17 , L_11 ,
V_237 ) ;
return - V_238 ;
}
V_2 -> V_83 [ V_237 ] -- ;
if ( V_2 -> V_83 [ V_237 ] != 0 ) {
F_133 ( V_2 -> V_17 ,
L_12 ,
V_2 -> V_83 [ V_237 ] , V_237 ) ;
return - V_238 ;
}
} else
V_2 -> V_83 [ V_237 ] ++ ;
F_131 ( V_2 , V_237 , V_61 ) ;
return 0 ;
}
static void F_134 ( struct V_1 * V_2 ,
int V_239 )
{
T_1 V_240 , V_39 ;
V_240 = F_3 ( V_2 , V_104 ) ;
V_39 = F_3 ( V_2 , V_241 ) ;
if ( V_239 ) {
V_240 |= V_242 ;
V_39 |= V_243 ;
F_1 ( V_2 , V_131 , 0xffff ) ;
F_1 ( V_2 , V_132 , 0xffffffff ) ;
} else {
V_240 &= ~ V_242 ;
V_39 &= ~ V_243 ;
}
F_1 ( V_2 , V_104 , V_240 ) ;
F_1 ( V_2 , V_241 , V_39 ) ;
}
static void F_135 ( struct V_16 * V_17 )
{
struct V_1 * V_2 = F_9 ( V_17 ) ;
struct V_244 * V_245 ;
if ( V_17 -> V_246 & V_247 ) {
F_134 ( V_2 , 1 ) ;
F_41 ( V_2 , V_103 ) ;
F_42 ( V_2 , V_103 ) ;
F_43 ( V_2 , V_103 ) ;
} else {
F_134 ( V_2 , 0 ) ;
F_41 ( V_2 , - 1 ) ;
F_55 ( V_2 , V_17 -> V_248 , V_103 ) ;
if ( V_17 -> V_246 & V_249 ) {
F_42 ( V_2 , V_103 ) ;
F_43 ( V_2 , V_103 ) ;
} else {
F_42 ( V_2 , - 1 ) ;
F_43 ( V_2 , - 1 ) ;
if ( ! F_136 ( V_17 ) ) {
F_137 (ha, dev) {
F_132 ( V_2 , V_245 -> V_128 ,
V_103 ) ;
}
}
}
}
}
static T_7 F_138 ( int V_250 , void * V_251 )
{
struct V_1 * V_2 = (struct V_1 * ) V_251 ;
F_1 ( V_2 , V_88 , 0 ) ;
F_139 ( & V_2 -> V_211 ) ;
return V_252 ;
}
static int F_140 ( struct V_253 * V_211 , int V_254 )
{
int V_41 = 0 ;
T_1 V_255 ;
unsigned long V_246 ;
struct V_1 * V_2 = F_9 ( V_211 -> V_17 ) ;
if ( ! F_121 ( V_2 -> V_17 ) ) {
F_141 ( V_211 ) ;
return V_41 ;
}
V_255 = F_3 ( V_2 , V_85 ) &
( F_142 ( V_66 ) | F_143 ( V_63 ) ) ;
if ( V_255 & V_256 ) {
F_125 ( V_2 , ( V_255 & V_256 ) ) ;
V_255 &= ~ V_256 ;
}
V_255 |= V_2 -> V_255 ;
if ( V_66 > 1 ) {
while ( ( V_255 & V_257 ) && ( V_254 > 0 ) ) {
int V_69 ;
struct V_33 * V_34 ;
V_34 = F_103 ( V_2 , V_255 ) ;
if ( ! V_34 )
break;
V_69 = F_105 ( V_2 , V_254 , V_34 ) ;
V_41 += V_69 ;
V_254 -= V_69 ;
if ( V_254 > 0 ) {
V_255 &= ~ ( ( 1 << V_34 -> V_37 ) << 8 ) ;
}
}
} else {
V_41 = F_105 ( V_2 , V_254 , & V_2 -> V_67 [ V_103 ] ) ;
V_254 -= V_41 ;
}
if ( V_254 > 0 ) {
V_255 = 0 ;
F_141 ( V_211 ) ;
F_144 ( V_246 ) ;
F_1 ( V_2 , V_88 ,
F_142 ( V_66 ) | F_143 ( V_63 ) ) ;
F_145 ( V_246 ) ;
}
V_2 -> V_255 = V_255 ;
return V_41 ;
}
static int F_146 ( struct V_1 * V_2 , struct V_33 * V_34 ,
int V_178 )
{
int V_11 ;
for ( V_11 = 0 ; V_11 < V_178 ; V_11 ++ ) {
memset ( V_34 -> V_46 + V_11 , 0 , sizeof( struct V_43 ) ) ;
if ( F_92 ( V_2 , V_34 -> V_46 + V_11 ) != 0 ) {
F_73 ( V_2 -> V_17 , L_13 ,
V_258 , V_34 -> V_37 , V_11 , V_178 ) ;
break;
}
}
F_15 ( V_2 , V_34 , V_11 ) ;
return V_11 ;
}
static void F_147 ( struct V_1 * V_2 )
{
int V_61 ;
for ( V_61 = 0 ; V_61 < V_63 ; V_61 ++ )
F_124 ( V_2 , & V_2 -> V_64 [ V_61 ] ) ;
F_1 ( V_2 , V_98 , V_99 ) ;
F_1 ( V_2 , V_98 , 0 ) ;
}
static void F_148 ( struct V_1 * V_2 )
{
F_1 ( V_2 , V_96 , V_97 ) ;
F_1 ( V_2 , V_96 , 0 ) ;
}
static int F_149 ( struct V_1 * V_2 ,
struct V_33 * V_34 )
{
V_34 -> V_9 = V_2 -> V_259 ;
V_34 -> V_46 = F_150 ( V_2 -> V_17 -> V_17 . V_180 ,
V_34 -> V_9 * V_260 ,
& V_34 -> V_261 , V_262 ) ;
if ( V_34 -> V_46 == NULL )
return - V_189 ;
F_151 ( V_34 -> V_46 !=
F_152 ( V_34 -> V_46 , V_263 ) ) ;
V_34 -> V_56 = V_34 -> V_9 - 1 ;
F_1 ( V_2 , F_153 ( V_34 -> V_37 ) , V_34 -> V_261 ) ;
F_1 ( V_2 , F_32 ( V_34 -> V_37 ) , V_34 -> V_9 ) ;
F_24 ( V_2 , V_34 , V_210 ) ;
F_56 ( V_2 , V_34 , V_34 -> V_134 ) ;
F_59 ( V_2 , V_34 , V_34 -> V_137 ) ;
F_31 ( V_2 , V_34 , F_94 ( V_2 -> V_190 ) ) ;
F_33 ( V_2 , V_34 ) ;
F_146 ( V_2 , V_34 , V_34 -> V_9 ) ;
return 0 ;
}
static void F_154 ( struct V_1 * V_2 ,
struct V_33 * V_34 )
{
F_104 ( V_2 , V_34 ) ;
if ( V_34 -> V_46 )
F_155 ( V_2 -> V_17 -> V_17 . V_180 ,
V_34 -> V_9 * V_260 ,
V_34 -> V_46 ,
V_34 -> V_261 ) ;
V_34 -> V_46 = NULL ;
V_34 -> V_56 = 0 ;
V_34 -> V_45 = 0 ;
V_34 -> V_261 = 0 ;
}
static int F_156 ( struct V_1 * V_2 ,
struct V_6 * V_7 )
{
V_7 -> V_9 = V_2 -> V_264 ;
V_7 -> V_46 = F_150 ( V_2 -> V_17 -> V_17 . V_180 ,
V_7 -> V_9 * V_260 ,
& V_7 -> V_261 , V_262 ) ;
if ( V_7 -> V_46 == NULL )
return - V_189 ;
F_151 ( V_7 -> V_46 !=
F_152 ( V_7 -> V_46 , V_263 ) ) ;
V_7 -> V_56 = V_7 -> V_9 - 1 ;
F_1 ( V_2 , F_47 ( V_7 -> V_37 ) , 0x03ffffff ) ;
F_1 ( V_2 , F_46 ( V_7 -> V_37 ) , 0x3fffffff ) ;
F_1 ( V_2 , F_157 ( V_7 -> V_37 ) , V_7 -> V_261 ) ;
F_1 ( V_2 , F_63 ( V_7 -> V_37 ) , V_7 -> V_9 ) ;
V_7 -> V_179 = F_87 ( V_7 -> V_9 * sizeof( * V_7 -> V_179 ) , V_262 ) ;
if ( V_7 -> V_179 == NULL ) {
F_155 ( V_2 -> V_17 -> V_17 . V_180 ,
V_7 -> V_9 * V_260 ,
V_7 -> V_46 , V_7 -> V_261 ) ;
return - V_189 ;
}
F_62 ( V_2 , V_7 , V_7 -> V_139 ) ;
return 0 ;
}
static void F_158 ( struct V_1 * V_2 ,
struct V_6 * V_7 )
{
F_91 ( V_7 -> V_179 ) ;
if ( V_7 -> V_46 )
F_155 ( V_2 -> V_17 -> V_17 . V_180 ,
V_7 -> V_9 * V_260 ,
V_7 -> V_46 , V_7 -> V_261 ) ;
V_7 -> V_46 = NULL ;
V_7 -> V_56 = 0 ;
V_7 -> V_45 = 0 ;
V_7 -> V_261 = 0 ;
F_1 ( V_2 , F_47 ( V_7 -> V_37 ) , 0 ) ;
F_1 ( V_2 , F_46 ( V_7 -> V_37 ) , 0 ) ;
F_1 ( V_2 , F_157 ( V_7 -> V_37 ) , 0 ) ;
F_1 ( V_2 , F_63 ( V_7 -> V_37 ) , 0 ) ;
}
static void F_159 ( struct V_1 * V_2 )
{
int V_61 ;
for ( V_61 = 0 ; V_61 < V_63 ; V_61 ++ )
F_158 ( V_2 , & V_2 -> V_64 [ V_61 ] ) ;
}
static void F_160 ( struct V_1 * V_2 )
{
int V_61 ;
for ( V_61 = 0 ; V_61 < V_66 ; V_61 ++ )
F_154 ( V_2 , & V_2 -> V_67 [ V_61 ] ) ;
}
static int F_161 ( struct V_1 * V_2 )
{
int V_61 ;
for ( V_61 = 0 ; V_61 < V_66 ; V_61 ++ ) {
int V_205 = F_149 ( V_2 , & V_2 -> V_67 [ V_61 ] ) ;
if ( V_205 ) {
F_73 ( V_2 -> V_17 , L_14 ,
V_258 , V_61 ) ;
F_160 ( V_2 ) ;
return V_205 ;
}
}
return 0 ;
}
static int F_162 ( struct V_1 * V_2 )
{
int V_61 ;
for ( V_61 = 0 ; V_61 < V_63 ; V_61 ++ ) {
int V_205 = F_156 ( V_2 , & V_2 -> V_64 [ V_61 ] ) ;
if ( V_205 ) {
F_73 ( V_2 -> V_17 , L_15 ,
V_258 , V_61 ) ;
F_159 ( V_2 ) ;
return V_205 ;
}
}
return 0 ;
}
static void F_163 ( struct V_1 * V_2 )
{
F_23 ( V_2 , V_2 -> V_190 ) ;
F_52 ( V_2 , V_2 -> V_190 ) ;
F_39 ( V_2 ) ;
F_164 ( & V_2 -> V_211 ) ;
F_1 ( V_2 , V_88 ,
F_142 ( V_66 ) | F_143 ( V_63 ) ) ;
F_165 ( V_2 -> V_265 ) ;
F_166 ( V_2 -> V_17 ) ;
}
static void F_167 ( struct V_1 * V_2 )
{
F_168 ( V_2 -> V_265 ) ;
F_169 ( & V_2 -> V_211 ) ;
F_170 ( V_2 -> V_17 ) ;
F_35 ( V_2 ) ;
F_171 ( V_2 -> V_17 ) ;
F_40 ( V_2 ) ;
F_1 ( V_2 , V_87 , 0 ) ;
F_1 ( V_2 , V_86 , 0 ) ;
F_1 ( V_2 , V_88 , 0 ) ;
F_1 ( V_2 , V_89 , 0 ) ;
F_1 ( V_2 , V_90 , 0 ) ;
F_147 ( V_2 ) ;
F_148 ( V_2 ) ;
}
static int F_172 ( struct V_16 * V_17 , int V_118 )
{
if ( V_118 < 68 ) {
F_73 ( V_17 , L_16 ) ;
return - V_238 ;
}
if ( V_118 > 9676 ) {
F_133 ( V_17 , L_17 , V_118 ) ;
V_118 = 9676 ;
}
if ( ! F_173 ( F_174 ( V_118 ) , 8 ) ) {
F_133 ( V_17 , L_18 ,
V_118 , F_175 ( F_174 ( V_118 ) , 8 ) ) ;
V_118 = F_175 ( F_174 ( V_118 ) , 8 ) ;
}
return V_118 ;
}
static int F_176 ( struct V_16 * V_17 , int V_118 )
{
struct V_1 * V_2 = F_9 ( V_17 ) ;
int V_266 ;
V_118 = F_172 ( V_17 , V_118 ) ;
if ( V_118 < 0 )
return - V_238 ;
V_17 -> V_118 = V_118 ;
if ( ! F_121 ( V_17 ) )
return 0 ;
F_167 ( V_2 ) ;
F_159 ( V_2 ) ;
F_160 ( V_2 ) ;
V_2 -> V_190 = F_174 ( V_2 -> V_17 -> V_118 ) ;
V_2 -> V_186 = F_177 ( F_94 ( V_2 -> V_190 ) ) +
F_177 ( sizeof( struct V_267 ) ) ;
V_266 = F_161 ( V_2 ) ;
if ( V_266 ) {
F_73 ( V_2 -> V_17 , L_19 ) ;
return V_266 ;
}
F_162 ( V_2 ) ;
F_163 ( V_2 ) ;
F_34 ( V_2 ) ;
return 0 ;
}
static void F_178 ( struct V_1 * V_2 , unsigned char * V_128 )
{
T_1 V_268 , V_269 ;
V_268 = F_3 ( V_2 , V_131 ) ;
V_269 = F_3 ( V_2 , V_132 ) ;
V_128 [ 0 ] = ( V_269 >> 24 ) & 0xFF ;
V_128 [ 1 ] = ( V_269 >> 16 ) & 0xFF ;
V_128 [ 2 ] = ( V_269 >> 8 ) & 0xFF ;
V_128 [ 3 ] = V_269 & 0xFF ;
V_128 [ 4 ] = ( V_268 >> 8 ) & 0xFF ;
V_128 [ 5 ] = V_268 & 0xFF ;
}
static int F_179 ( struct V_16 * V_17 , void * V_128 )
{
struct V_1 * V_2 = F_9 ( V_17 ) ;
T_3 * V_270 = V_128 + 2 ;
int V_11 ;
if ( F_121 ( V_17 ) )
return - V_271 ;
F_55 ( V_2 , V_17 -> V_248 , - 1 ) ;
F_55 ( V_2 , V_270 , V_103 ) ;
for ( V_11 = 0 ; V_11 < V_230 ; V_11 ++ )
V_17 -> V_248 [ V_11 ] = V_270 [ V_11 ] ;
return 0 ;
}
static void F_180 ( struct V_16 * V_272 )
{
struct V_1 * V_2 = F_9 ( V_272 ) ;
struct V_273 * V_274 = V_2 -> V_265 ;
int V_275 = 0 ;
if ( V_274 -> V_276 ) {
if ( ( V_2 -> V_277 != V_274 -> V_277 ) ||
( V_2 -> V_278 != V_274 -> V_278 ) ) {
T_1 V_39 ;
V_39 = F_3 ( V_2 , V_279 ) ;
V_39 &= ~ ( V_280 |
V_281 |
V_282 |
V_283 |
V_284 ) ;
if ( V_274 -> V_278 )
V_39 |= V_282 ;
if ( V_274 -> V_277 == V_285 )
V_39 |= V_281 ;
else
V_39 |= V_280 ;
F_1 ( V_2 , V_279 , V_39 ) ;
V_2 -> V_278 = V_274 -> V_278 ;
V_2 -> V_277 = V_274 -> V_277 ;
}
}
if ( V_274 -> V_276 != V_2 -> V_276 ) {
if ( ! V_274 -> V_276 ) {
V_2 -> V_278 = - 1 ;
V_2 -> V_277 = 0 ;
}
V_2 -> V_276 = V_274 -> V_276 ;
V_275 = 1 ;
}
if ( V_275 ) {
if ( V_274 -> V_276 ) {
T_1 V_39 = F_3 ( V_2 , V_279 ) ;
V_39 |= ( V_286 |
V_287 ) ;
F_1 ( V_2 , V_279 , V_39 ) ;
F_34 ( V_2 ) ;
F_133 ( V_2 -> V_17 , L_20 ) ;
} else {
F_35 ( V_2 ) ;
F_133 ( V_2 -> V_17 , L_21 ) ;
}
}
}
static int F_181 ( struct V_1 * V_2 )
{
struct V_273 * V_265 ;
V_265 = F_182 ( V_2 -> V_17 , V_2 -> V_288 , F_180 , 0 ,
V_2 -> V_289 ) ;
if ( ! V_265 ) {
F_73 ( V_2 -> V_17 , L_22 ) ;
return - V_290 ;
}
V_265 -> V_291 &= V_292 ;
V_265 -> V_293 = V_265 -> V_291 ;
V_2 -> V_265 = V_265 ;
V_2 -> V_276 = 0 ;
V_2 -> V_278 = 0 ;
V_2 -> V_277 = 0 ;
return 0 ;
}
static void F_183 ( struct V_1 * V_2 )
{
F_184 ( V_2 -> V_265 ) ;
V_2 -> V_265 = NULL ;
}
static int F_185 ( struct V_16 * V_17 )
{
struct V_1 * V_2 = F_9 ( V_17 ) ;
int V_266 ;
F_55 ( V_2 , V_17 -> V_248 , V_103 ) ;
V_2 -> V_190 = F_174 ( V_2 -> V_17 -> V_118 ) ;
V_2 -> V_186 = F_177 ( F_94 ( V_2 -> V_190 ) ) +
F_177 ( sizeof( struct V_267 ) ) ;
V_266 = F_161 ( V_2 ) ;
if ( V_266 )
return V_266 ;
V_266 = F_162 ( V_2 ) ;
if ( V_266 )
goto V_294;
V_266 = F_186 ( V_2 -> V_17 -> V_250 , F_138 , 0 ,
V_295 , V_2 ) ;
if ( V_266 ) {
F_73 ( V_2 -> V_17 , L_23 , V_2 -> V_17 -> V_250 ) ;
goto V_296;
}
F_170 ( V_2 -> V_17 ) ;
V_266 = F_181 ( V_2 ) ;
if ( V_266 < 0 ) {
F_73 ( V_17 , L_24 ) ;
goto V_297;
}
F_163 ( V_2 ) ;
return 0 ;
V_297:
F_187 ( V_2 -> V_17 -> V_250 , V_2 ) ;
V_296:
F_159 ( V_2 ) ;
V_294:
F_160 ( V_2 ) ;
return V_266 ;
}
static int F_188 ( struct V_16 * V_17 )
{
struct V_1 * V_2 = F_9 ( V_17 ) ;
F_167 ( V_2 ) ;
F_183 ( V_2 ) ;
F_187 ( V_17 -> V_250 , V_2 ) ;
F_160 ( V_2 ) ;
F_159 ( V_2 ) ;
return 0 ;
}
static int F_189 ( struct V_16 * V_17 , struct V_298 * V_299 , int V_300 )
{
struct V_1 * V_2 = F_9 ( V_17 ) ;
int V_266 ;
if ( ! V_2 -> V_265 )
return - V_301 ;
V_266 = F_190 ( V_2 -> V_265 , V_299 , V_300 ) ;
if ( ! V_266 )
F_180 ( V_17 ) ;
return V_266 ;
}
int F_191 ( struct V_16 * V_17 , struct V_302 * V_300 )
{
struct V_1 * V_2 = F_9 ( V_17 ) ;
if ( ! V_2 -> V_265 )
return - V_290 ;
return F_192 ( V_2 -> V_265 , V_300 ) ;
}
int F_193 ( struct V_16 * V_17 , struct V_302 * V_300 )
{
struct V_1 * V_2 = F_9 ( V_17 ) ;
if ( ! V_2 -> V_265 )
return - V_290 ;
return F_194 ( V_2 -> V_265 , V_300 ) ;
}
static int F_195 ( struct V_16 * V_17 ,
struct V_303 * V_304 )
{
struct V_1 * V_2 = F_9 ( V_17 ) ;
int V_61 ;
for ( V_61 = 0 ; V_61 < V_66 ; V_61 ++ ) {
struct V_33 * V_34 = & V_2 -> V_67 [ V_61 ] ;
V_34 -> V_137 = V_304 -> V_305 ;
V_34 -> V_134 = V_304 -> V_306 ;
F_56 ( V_2 , V_34 , V_34 -> V_134 ) ;
F_59 ( V_2 , V_34 , V_34 -> V_137 ) ;
}
for ( V_61 = 0 ; V_61 < V_63 ; V_61 ++ ) {
struct V_6 * V_7 = & V_2 -> V_64 [ V_61 ] ;
V_7 -> V_139 = V_304 -> V_307 ;
F_62 ( V_2 , V_7 , V_7 -> V_139 ) ;
}
return 0 ;
}
static int F_196 ( struct V_16 * V_17 ,
struct V_303 * V_304 )
{
struct V_1 * V_2 = F_9 ( V_17 ) ;
V_304 -> V_305 = V_2 -> V_67 [ 0 ] . V_137 ;
V_304 -> V_306 = V_2 -> V_67 [ 0 ] . V_134 ;
V_304 -> V_307 = V_2 -> V_64 [ 0 ] . V_139 ;
return 0 ;
}
static void F_197 ( struct V_16 * V_17 ,
struct V_308 * V_309 )
{
F_198 ( V_309 -> V_310 , V_295 ,
sizeof( V_309 -> V_310 ) ) ;
F_198 ( V_309 -> V_311 , V_312 ,
sizeof( V_309 -> V_311 ) ) ;
F_198 ( V_309 -> V_313 , F_199 ( & V_17 -> V_17 ) ,
sizeof( V_309 -> V_313 ) ) ;
}
static void F_200 ( struct V_16 * V_314 ,
struct V_315 * V_316 )
{
struct V_1 * V_2 = F_9 ( V_314 ) ;
V_316 -> V_317 = V_318 ;
V_316 -> V_319 = V_320 ;
V_316 -> V_321 = V_2 -> V_259 ;
V_316 -> V_322 = V_2 -> V_264 ;
}
static int F_201 ( struct V_16 * V_17 ,
struct V_315 * V_316 )
{
struct V_1 * V_2 = F_9 ( V_17 ) ;
if ( ( V_316 -> V_321 == 0 ) || ( V_316 -> V_322 == 0 ) )
return - V_238 ;
V_2 -> V_259 = V_316 -> V_321 < V_318 ?
V_316 -> V_321 : V_318 ;
V_2 -> V_264 = V_316 -> V_322 < V_320 ?
V_316 -> V_322 : V_320 ;
if ( F_121 ( V_17 ) ) {
F_188 ( V_17 ) ;
if ( F_185 ( V_17 ) ) {
F_73 ( V_17 ,
L_25 ) ;
return - V_189 ;
}
}
return 0 ;
}
static int F_202 ( struct V_1 * V_2 , int V_323 )
{
int V_61 ;
F_40 ( V_2 ) ;
F_44 ( V_2 ) ;
V_2 -> V_64 = F_203 ( V_63 * sizeof( struct V_6 ) ,
V_262 ) ;
if ( ! V_2 -> V_64 )
return - V_189 ;
for ( V_61 = 0 ; V_61 < V_63 ; V_61 ++ ) {
struct V_6 * V_7 = & V_2 -> V_64 [ V_61 ] ;
V_7 -> V_37 = V_61 ;
V_7 -> V_9 = V_2 -> V_264 ;
V_7 -> V_139 = V_324 ;
}
V_2 -> V_67 = F_203 ( V_66 * sizeof( struct V_33 ) ,
V_262 ) ;
if ( ! V_2 -> V_67 ) {
F_91 ( V_2 -> V_64 ) ;
return - V_189 ;
}
for ( V_61 = 0 ; V_61 < V_66 ; V_61 ++ ) {
struct V_33 * V_34 = & V_2 -> V_67 [ V_61 ] ;
V_34 -> V_37 = V_61 ;
V_34 -> V_9 = V_2 -> V_259 ;
V_34 -> V_134 = V_325 ;
V_34 -> V_137 = V_326 ;
}
return 0 ;
}
static void F_204 ( struct V_1 * V_2 )
{
F_91 ( V_2 -> V_64 ) ;
F_91 ( V_2 -> V_67 ) ;
}
static void F_205 ( struct V_1 * V_2 ,
const struct V_327 * V_328 )
{
T_1 V_329 ;
T_1 V_330 ;
int V_11 ;
for ( V_11 = 0 ; V_11 < 6 ; V_11 ++ ) {
F_1 ( V_2 , F_206 ( V_11 ) , 0 ) ;
F_1 ( V_2 , F_207 ( V_11 ) , 0 ) ;
if ( V_11 < 4 )
F_1 ( V_2 , F_208 ( V_11 ) , 0 ) ;
}
V_329 = 0x3f ;
V_330 = 0 ;
for ( V_11 = 0 ; V_11 < V_328 -> V_331 ; V_11 ++ ) {
const struct V_332 * V_333 = V_328 -> V_333 + V_11 ;
F_1 ( V_2 , F_206 ( V_11 ) , ( V_333 -> V_5 & 0xffff0000 ) |
( V_333 -> V_334 << 8 ) | V_328 -> V_335 ) ;
F_1 ( V_2 , F_207 ( V_11 ) ,
( V_333 -> V_9 - 1 ) & 0xffff0000 ) ;
V_329 &= ~ ( 1 << V_11 ) ;
V_330 |= 3 << ( 2 * V_11 ) ;
}
F_1 ( V_2 , V_336 , V_329 ) ;
}
static int F_209 ( struct V_1 * V_2 , int V_337 )
{
T_1 V_338 ;
F_1 ( V_2 , V_339 , 0 ) ;
V_338 = F_3 ( V_2 , V_340 ) ;
switch( V_337 ) {
case V_341 :
F_1 ( V_2 , V_342 , V_343 ) ;
V_338 |= V_344 | V_345 ;
break;
case V_346 :
F_1 ( V_2 , V_342 , V_347 ) ;
V_338 |= V_344 | V_345 ;
break;
case V_348 :
case V_349 :
V_338 |= V_345 ;
break;
default:
return - V_238 ;
}
V_338 &= ~ V_350 ;
F_1 ( V_2 , V_340 , V_338 ) ;
while ( ( F_3 ( V_2 , V_340 ) &
V_350 ) != 0 )
continue;
return 0 ;
}
static int F_210 ( struct V_351 * V_352 )
{
const struct V_327 * V_353 ;
struct V_354 * V_355 ;
struct V_356 * V_357 = V_352 -> V_17 . V_358 ;
struct V_356 * V_288 ;
T_1 V_323 ;
struct V_1 * V_2 ;
struct V_16 * V_17 ;
const char * V_359 ;
char V_360 [ V_230 ] ;
const char * V_361 ;
int V_337 ;
int V_205 ;
if ( V_103 != 0 ) {
F_211 ( & V_352 -> V_17 , L_26 , V_103 ) ;
return - V_238 ;
}
V_17 = F_212 ( sizeof( struct V_1 ) , V_63 , V_66 ) ;
if ( ! V_17 )
return - V_189 ;
V_17 -> V_250 = F_213 ( V_357 , 0 ) ;
if ( V_17 -> V_250 == 0 ) {
V_205 = - V_238 ;
goto V_362;
}
V_288 = F_214 ( V_357 , L_27 , 0 ) ;
if ( ! V_288 ) {
F_211 ( & V_352 -> V_17 , L_28 ) ;
V_205 = - V_290 ;
goto V_297;
}
V_337 = F_215 ( V_357 ) ;
if ( V_337 < 0 ) {
F_211 ( & V_352 -> V_17 , L_29 ) ;
V_205 = - V_238 ;
goto V_297;
}
V_17 -> V_363 = V_320 ;
V_17 -> V_364 = 5 * V_365 ;
V_17 -> V_366 = & V_367 ;
F_216 ( V_17 , & V_368 ) ;
V_2 = F_9 ( V_17 ) ;
V_2 -> V_369 = V_370 ;
V_2 -> V_288 = V_288 ;
V_2 -> V_289 = V_337 ;
V_2 -> V_136 = F_217 ( & V_352 -> V_17 , NULL ) ;
if ( F_218 ( V_2 -> V_136 ) ) {
V_205 = F_219 ( V_2 -> V_136 ) ;
goto V_297;
}
F_220 ( V_2 -> V_136 ) ;
V_355 = F_221 ( V_352 , V_371 , 0 ) ;
V_2 -> V_5 = F_222 ( & V_352 -> V_17 , V_355 ) ;
if ( F_218 ( V_2 -> V_5 ) ) {
V_205 = F_219 ( V_2 -> V_5 ) ;
goto V_372;
}
V_2 -> V_18 = F_223 ( struct V_21 ) ;
if ( ! V_2 -> V_18 ) {
V_205 = - V_189 ;
goto V_372;
}
V_359 = F_224 ( V_357 ) ;
if ( V_359 ) {
V_361 = L_30 ;
memcpy ( V_17 -> V_248 , V_359 , V_230 ) ;
} else {
F_178 ( V_2 , V_360 ) ;
if ( F_225 ( V_360 ) ) {
V_361 = L_31 ;
memcpy ( V_17 -> V_248 , V_360 , V_230 ) ;
} else {
V_361 = L_32 ;
F_226 ( V_17 ) ;
}
}
V_2 -> V_264 = V_320 ;
V_2 -> V_259 = V_318 ;
V_2 -> V_17 = V_17 ;
F_227 ( V_17 , & V_352 -> V_17 ) ;
V_205 = F_202 ( V_2 , V_323 ) ;
if ( V_205 < 0 ) {
F_211 ( & V_352 -> V_17 , L_33 ) ;
goto V_373;
}
V_205 = F_209 ( V_2 , V_337 ) ;
if ( V_205 < 0 ) {
F_211 ( & V_352 -> V_17 , L_34 ) ;
goto V_374;
}
V_353 = F_228 () ;
if ( V_353 )
F_205 ( V_2 , V_353 ) ;
F_229 ( V_17 , & V_2 -> V_211 , F_140 , V_2 -> V_369 ) ;
V_17 -> V_375 = V_376 | V_377 ;
V_17 -> V_378 |= V_376 | V_377 ;
V_17 -> V_379 |= V_376 | V_377 ;
V_17 -> V_380 |= V_381 ;
V_205 = F_230 ( V_17 ) ;
if ( V_205 < 0 ) {
F_211 ( & V_352 -> V_17 , L_35 ) ;
goto V_374;
}
F_133 ( V_17 , L_36 , V_361 ,
V_17 -> V_248 ) ;
F_231 ( V_352 , V_2 -> V_17 ) ;
return 0 ;
V_374:
F_204 ( V_2 ) ;
V_373:
F_232 ( V_2 -> V_18 ) ;
V_372:
F_233 ( V_2 -> V_136 ) ;
V_297:
F_234 ( V_17 -> V_250 ) ;
V_362:
F_235 ( V_17 ) ;
return V_205 ;
}
static int F_236 ( struct V_351 * V_352 )
{
struct V_16 * V_17 = F_237 ( V_352 ) ;
struct V_1 * V_2 = F_9 ( V_17 ) ;
F_238 ( V_17 ) ;
F_204 ( V_2 ) ;
F_233 ( V_2 -> V_136 ) ;
F_232 ( V_2 -> V_18 ) ;
F_234 ( V_17 -> V_250 ) ;
F_235 ( V_17 ) ;
return 0 ;
}
