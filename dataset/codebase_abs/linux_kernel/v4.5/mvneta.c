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
V_12 = F_3 ( V_2 , V_15 ) ;
V_12 = F_3 ( V_2 , V_16 ) ;
}
struct V_17 * F_8 ( struct V_18 * V_19 ,
struct V_17 * V_20 )
{
struct V_1 * V_2 = F_9 ( V_19 ) ;
unsigned int V_21 ;
int V_22 ;
F_10 (cpu) {
struct V_23 * V_24 ;
T_2 V_25 ;
T_2 V_26 ;
T_2 V_27 ;
T_2 V_28 ;
V_24 = F_11 ( V_2 -> V_20 , V_22 ) ;
do {
V_21 = F_12 ( & V_24 -> V_29 ) ;
V_25 = V_24 -> V_25 ;
V_26 = V_24 -> V_26 ;
V_27 = V_24 -> V_27 ;
V_28 = V_24 -> V_28 ;
} while ( F_13 ( & V_24 -> V_29 , V_21 ) );
V_20 -> V_25 += V_25 ;
V_20 -> V_26 += V_26 ;
V_20 -> V_27 += V_27 ;
V_20 -> V_28 += V_28 ;
}
V_20 -> V_30 = V_19 -> V_20 . V_30 ;
V_20 -> V_31 = V_19 -> V_20 . V_31 ;
V_20 -> V_32 = V_19 -> V_20 . V_32 ;
return V_20 ;
}
static int F_14 ( T_1 V_33 )
{
return ( V_33 & V_34 ) ==
V_34 ;
}
static void F_15 ( struct V_1 * V_2 ,
struct V_35 * V_36 ,
int V_37 )
{
while ( V_37 > V_38 ) {
F_1 ( V_2 , F_16 ( V_36 -> V_39 ) ,
( V_38 <<
V_40 ) ) ;
V_37 -= V_38 ;
}
F_1 ( V_2 , F_16 ( V_36 -> V_39 ) ,
( V_37 << V_40 ) ) ;
}
static int F_17 ( struct V_1 * V_2 ,
struct V_35 * V_36 )
{
T_1 V_41 ;
V_41 = F_3 ( V_2 , F_18 ( V_36 -> V_39 ) ) ;
return V_41 & V_42 ;
}
static void F_19 ( struct V_1 * V_2 ,
struct V_35 * V_36 ,
int V_43 , int V_44 )
{
T_1 V_41 ;
if ( ( V_43 <= 0xff ) && ( V_44 <= 0xff ) ) {
V_41 = V_43 |
( V_44 << V_40 ) ;
F_1 ( V_2 , F_16 ( V_36 -> V_39 ) , V_41 ) ;
return;
}
while ( ( V_43 > 0 ) || ( V_44 > 0 ) ) {
if ( V_43 <= 0xff ) {
V_41 = V_43 ;
V_43 = 0 ;
} else {
V_41 = 0xff ;
V_43 -= 0xff ;
}
if ( V_44 <= 0xff ) {
V_41 |= V_44 << V_40 ;
V_44 = 0 ;
} else {
V_41 |= 0xff << V_40 ;
V_44 -= 0xff ;
}
F_1 ( V_2 , F_16 ( V_36 -> V_39 ) , V_41 ) ;
}
}
static struct V_45 *
F_20 ( struct V_35 * V_36 )
{
int V_46 = V_36 -> V_47 ;
V_36 -> V_47 = F_21 ( V_36 , V_46 ) ;
F_22 ( V_36 -> V_48 + V_36 -> V_47 ) ;
return V_36 -> V_48 + V_46 ;
}
static void F_23 ( struct V_1 * V_2 , int V_49 )
{
T_1 V_41 ;
V_41 = F_3 ( V_2 , V_50 ) ;
V_41 &= ~ V_51 ;
V_41 |= ( ( V_49 - V_52 ) / 2 ) <<
V_53 ;
F_1 ( V_2 , V_50 , V_41 ) ;
}
static void F_24 ( struct V_1 * V_2 ,
struct V_35 * V_36 ,
int V_3 )
{
T_1 V_41 ;
V_41 = F_3 ( V_2 , F_25 ( V_36 -> V_39 ) ) ;
V_41 &= ~ V_54 ;
V_41 |= F_26 ( V_3 >> 3 ) ;
F_1 ( V_2 , F_25 ( V_36 -> V_39 ) , V_41 ) ;
}
static void F_27 ( struct V_1 * V_2 ,
struct V_6 * V_7 ,
int V_55 )
{
T_1 V_41 ;
V_41 = V_55 ;
F_1 ( V_2 , F_28 ( V_7 -> V_39 ) , V_41 ) ;
}
static struct V_56 *
F_29 ( struct V_6 * V_7 )
{
int V_57 = V_7 -> V_47 ;
V_7 -> V_47 = F_21 ( V_7 , V_57 ) ;
return V_7 -> V_48 + V_57 ;
}
static void F_30 ( struct V_6 * V_7 )
{
if ( V_7 -> V_47 == 0 )
V_7 -> V_47 = V_7 -> V_58 - 1 ;
else
V_7 -> V_47 -- ;
}
static void F_31 ( struct V_1 * V_2 ,
struct V_35 * V_36 ,
int V_59 )
{
T_1 V_41 ;
V_41 = F_3 ( V_2 , F_32 ( V_36 -> V_39 ) ) ;
V_41 &= ~ V_60 ;
V_41 |= ( ( V_59 >> 3 ) << V_61 ) ;
F_1 ( V_2 , F_32 ( V_36 -> V_39 ) , V_41 ) ;
}
static void F_33 ( struct V_1 * V_2 ,
struct V_35 * V_36 )
{
T_1 V_41 ;
V_41 = F_3 ( V_2 , F_25 ( V_36 -> V_39 ) ) ;
V_41 &= ~ V_62 ;
F_1 ( V_2 , F_25 ( V_36 -> V_39 ) , V_41 ) ;
}
static void F_34 ( struct V_1 * V_2 )
{
int V_63 ;
T_1 V_64 ;
V_64 = 0 ;
for ( V_63 = 0 ; V_63 < V_65 ; V_63 ++ ) {
struct V_6 * V_7 = & V_2 -> V_66 [ V_63 ] ;
if ( V_7 -> V_48 != NULL )
V_64 |= ( 1 << V_63 ) ;
}
F_1 ( V_2 , V_67 , V_64 ) ;
for ( V_63 = 0 ; V_63 < V_68 ; V_63 ++ ) {
struct V_35 * V_36 = & V_2 -> V_69 [ V_63 ] ;
if ( V_36 -> V_48 != NULL )
V_64 |= ( 1 << V_63 ) ;
}
F_1 ( V_2 , V_70 , V_64 ) ;
}
static void F_35 ( struct V_1 * V_2 )
{
T_1 V_41 ;
int V_71 ;
V_41 = F_3 ( V_2 , V_70 ) & V_72 ;
if ( V_41 != 0 )
F_1 ( V_2 , V_70 ,
V_41 << V_73 ) ;
V_71 = 0 ;
do {
if ( V_71 ++ >= V_74 ) {
F_36 ( V_2 -> V_19 ,
L_1 ,
V_41 ) ;
break;
}
F_37 ( 1 ) ;
V_41 = F_3 ( V_2 , V_70 ) ;
} while ( V_41 & 0xff );
V_41 = ( F_3 ( V_2 , V_67 ) ) & V_75 ;
if ( V_41 != 0 )
F_1 ( V_2 , V_67 ,
( V_41 << V_76 ) ) ;
V_71 = 0 ;
do {
if ( V_71 ++ >= V_77 ) {
F_36 ( V_2 -> V_19 ,
L_2 ,
V_41 ) ;
break;
}
F_37 ( 1 ) ;
V_41 = F_3 ( V_2 , V_67 ) ;
} while ( V_41 & 0xff );
V_71 = 0 ;
do {
if ( V_71 ++ >= V_78 ) {
F_36 ( V_2 -> V_19 ,
L_3 ,
V_41 ) ;
break;
}
F_37 ( 1 ) ;
V_41 = F_3 ( V_2 , V_79 ) ;
} while ( ! ( V_41 & V_80 ) &&
( V_41 & V_81 ) );
F_38 ( 200 ) ;
}
static void F_39 ( struct V_1 * V_2 )
{
T_1 V_41 ;
V_41 = F_3 ( V_2 , V_50 ) ;
V_41 |= V_82 ;
F_1 ( V_2 , V_50 , V_41 ) ;
}
static void F_40 ( struct V_1 * V_2 )
{
T_1 V_41 ;
V_41 = F_3 ( V_2 , V_50 ) ;
V_41 &= ~ V_82 ;
F_1 ( V_2 , V_50 , V_41 ) ;
F_38 ( 200 ) ;
}
static void F_41 ( struct V_1 * V_2 , int V_63 )
{
int V_3 ;
T_1 V_41 ;
if ( V_63 == - 1 ) {
V_41 = 0 ;
} else {
V_41 = 0x1 | ( V_63 << 1 ) ;
V_41 |= ( V_41 << 24 ) | ( V_41 << 16 ) | ( V_41 << 8 ) ;
}
for ( V_3 = 0 ; V_3 <= 0xc ; V_3 += 4 )
F_1 ( V_2 , V_83 + V_3 , V_41 ) ;
}
static void F_42 ( struct V_1 * V_2 , int V_63 )
{
int V_3 ;
T_1 V_41 ;
if ( V_63 == - 1 ) {
V_41 = 0 ;
} else {
V_41 = 0x1 | ( V_63 << 1 ) ;
V_41 |= ( V_41 << 24 ) | ( V_41 << 16 ) | ( V_41 << 8 ) ;
}
for ( V_3 = 0 ; V_3 <= 0xfc ; V_3 += 4 )
F_1 ( V_2 , V_84 + V_3 , V_41 ) ;
}
static void F_43 ( struct V_1 * V_2 , int V_63 )
{
int V_3 ;
T_1 V_41 ;
if ( V_63 == - 1 ) {
memset ( V_2 -> V_85 , 0 , sizeof( V_2 -> V_85 ) ) ;
V_41 = 0 ;
} else {
memset ( V_2 -> V_85 , 1 , sizeof( V_2 -> V_85 ) ) ;
V_41 = 0x1 | ( V_63 << 1 ) ;
V_41 |= ( V_41 << 24 ) | ( V_41 << 16 ) | ( V_41 << 8 ) ;
}
for ( V_3 = 0 ; V_3 <= 0xfc ; V_3 += 4 )
F_1 ( V_2 , V_86 + V_3 , V_41 ) ;
}
static void F_44 ( struct V_1 * V_2 , int V_87 )
{
T_1 V_41 ;
if ( V_87 ) {
V_41 = F_3 ( V_2 , V_88 ) ;
V_41 &= ~ ( V_89 |
V_90 |
V_91 ) ;
V_41 |= V_92 |
V_93 |
V_94 ;
F_1 ( V_2 , V_88 , V_41 ) ;
V_41 = F_3 ( V_2 , V_95 ) ;
V_41 |= V_96 ;
F_1 ( V_2 , V_95 , V_41 ) ;
V_41 = F_3 ( V_2 , V_97 ) ;
V_41 |= V_98 ;
F_1 ( V_2 , V_97 , V_41 ) ;
} else {
V_41 = F_3 ( V_2 , V_88 ) ;
V_41 &= ~ ( V_92 |
V_93 |
V_94 ) ;
F_1 ( V_2 , V_88 , V_41 ) ;
V_41 = F_3 ( V_2 , V_95 ) ;
V_41 &= ~ V_96 ;
F_1 ( V_2 , V_95 , V_41 ) ;
V_41 = F_3 ( V_2 , V_97 ) ;
V_41 &= ~ V_98 ;
F_1 ( V_2 , V_97 , V_41 ) ;
}
}
static void F_45 ( void * V_99 )
{
struct V_1 * V_2 = V_99 ;
F_1 ( V_2 , V_100 ,
V_101 |
V_102 |
V_103 ) ;
}
static void F_46 ( void * V_99 )
{
struct V_1 * V_2 = V_99 ;
F_1 ( V_2 , V_100 , 0 ) ;
F_1 ( V_2 , V_104 , 0 ) ;
F_1 ( V_2 , V_105 , 0 ) ;
}
static void F_47 ( void * V_99 )
{
struct V_1 * V_2 = V_99 ;
F_1 ( V_2 , V_106 , 0 ) ;
F_1 ( V_2 , V_107 , 0 ) ;
F_1 ( V_2 , V_108 , 0 ) ;
}
static void F_48 ( struct V_1 * V_2 )
{
int V_22 ;
int V_63 ;
T_1 V_41 ;
int V_109 = F_49 () ;
F_50 ( F_47 , V_2 , true ) ;
F_50 ( F_46 , V_2 , true ) ;
F_1 ( V_2 , V_110 , 0 ) ;
F_1 ( V_2 , V_111 , 0x20 ) ;
F_51 (cpu) {
int V_112 = 0 , V_113 = 0 ;
int V_36 , V_7 ;
for ( V_36 = 0 ; V_36 < V_68 ; V_36 ++ )
if ( ( V_36 % V_109 ) == V_22 )
V_112 |= F_52 ( V_36 ) ;
for ( V_7 = 0 ; V_7 < V_65 ; V_7 ++ )
if ( ( V_7 % V_109 ) == V_22 )
V_113 |= F_53 ( V_7 ) ;
if ( V_65 == 1 )
V_113 = ( V_22 == V_2 -> V_114 ) ?
F_53 ( 1 ) : 0 ;
F_1 ( V_2 , F_54 ( V_22 ) , V_112 | V_113 ) ;
}
F_1 ( V_2 , V_115 , V_116 ) ;
F_1 ( V_2 , V_117 , V_118 ) ;
F_1 ( V_2 , V_119 , 0 ) ;
for ( V_63 = 0 ; V_63 < V_65 ; V_63 ++ ) {
F_1 ( V_2 , F_55 ( V_63 ) , 0 ) ;
F_1 ( V_2 , F_56 ( V_63 ) , 0 ) ;
}
F_1 ( V_2 , V_117 , 0 ) ;
F_1 ( V_2 , V_115 , 0 ) ;
V_41 = V_120 ;
F_1 ( V_2 , V_121 , V_41 ) ;
V_41 = F_57 ( V_2 -> V_114 ) ;
F_1 ( V_2 , V_122 , V_41 ) ;
V_41 = 0 ;
F_1 ( V_2 , V_123 , V_41 ) ;
F_1 ( V_2 , V_124 , 64 ) ;
V_41 = 0 ;
V_41 |= F_58 ( V_125 ) ;
V_41 |= F_59 ( V_125 ) ;
V_41 |= V_126 | V_127 ;
#if F_60 ( V_128 )
V_41 |= V_129 ;
#endif
F_1 ( V_2 , V_130 , V_41 ) ;
V_41 = F_3 ( V_2 , V_131 ) ;
V_41 &= ~ V_132 ;
F_1 ( V_2 , V_131 , V_41 ) ;
F_44 ( V_2 , V_2 -> V_133 ) ;
F_41 ( V_2 , - 1 ) ;
F_42 ( V_2 , - 1 ) ;
F_43 ( V_2 , - 1 ) ;
F_1 ( V_2 , V_110 ,
( V_134
| V_135 ) ) ;
F_7 ( V_2 ) ;
}
static void F_61 ( struct V_1 * V_2 , int V_136 )
{
T_1 V_41 , V_9 , V_137 ;
int V_63 ;
V_137 = V_136 * 8 ;
if ( V_137 > V_138 )
V_137 = V_138 ;
V_41 = F_3 ( V_2 , V_139 ) ;
V_41 &= ~ V_138 ;
V_41 |= V_137 ;
F_1 ( V_2 , V_139 , V_41 ) ;
V_41 = F_3 ( V_2 , V_140 ) ;
V_9 = V_41 & V_141 ;
if ( V_9 < V_137 ) {
V_9 = V_137 ;
V_41 &= ~ V_141 ;
V_41 |= V_9 ;
F_1 ( V_2 , V_140 , V_41 ) ;
}
for ( V_63 = 0 ; V_63 < V_65 ; V_63 ++ ) {
V_41 = F_3 ( V_2 , F_62 ( V_63 ) ) ;
V_9 = V_41 & V_142 ;
if ( V_9 < V_137 ) {
V_9 = V_137 ;
V_41 &= ~ V_142 ;
V_41 |= V_9 ;
F_1 ( V_2 , F_62 ( V_63 ) , V_41 ) ;
}
}
}
static void F_63 ( struct V_1 * V_2 , T_3 V_143 ,
int V_63 )
{
unsigned int V_144 ;
unsigned int V_145 ;
unsigned int V_146 ;
V_143 = ( 0xf & V_143 ) ;
V_145 = ( V_143 / 4 ) * 4 ;
V_146 = V_143 % 4 ;
V_144 = F_3 ( V_2 , ( V_83 + V_145 ) ) ;
if ( V_63 == - 1 ) {
V_144 &= ~ ( 0xff << ( 8 * V_146 ) ) ;
} else {
V_144 &= ~ ( 0xff << ( 8 * V_146 ) ) ;
V_144 |= ( ( 0x01 | ( V_63 << 1 ) ) << ( 8 * V_146 ) ) ;
}
F_1 ( V_2 , ( V_83 + V_145 ) , V_144 ) ;
}
static void F_64 ( struct V_1 * V_2 , unsigned char * V_147 ,
int V_63 )
{
unsigned int V_148 ;
unsigned int V_149 ;
if ( V_63 != - 1 ) {
V_149 = ( V_147 [ 4 ] << 8 ) | ( V_147 [ 5 ] ) ;
V_148 = ( V_147 [ 0 ] << 24 ) | ( V_147 [ 1 ] << 16 ) |
( V_147 [ 2 ] << 8 ) | ( V_147 [ 3 ] << 0 ) ;
F_1 ( V_2 , V_150 , V_149 ) ;
F_1 ( V_2 , V_151 , V_148 ) ;
}
F_63 ( V_2 , V_147 [ 5 ] , V_63 ) ;
}
static void F_65 ( struct V_1 * V_2 ,
struct V_35 * V_36 , T_1 V_152 )
{
F_1 ( V_2 , F_66 ( V_36 -> V_39 ) ,
V_152 | F_67 ( 0 ) ) ;
V_36 -> V_153 = V_152 ;
}
static void F_68 ( struct V_1 * V_2 ,
struct V_35 * V_36 , T_1 V_152 )
{
T_1 V_41 ;
unsigned long V_154 ;
V_154 = F_69 ( V_2 -> V_155 ) ;
V_41 = ( V_154 / 1000000 ) * V_152 ;
F_1 ( V_2 , F_70 ( V_36 -> V_39 ) , V_41 ) ;
V_36 -> V_156 = V_152 ;
}
static void F_71 ( struct V_1 * V_2 ,
struct V_6 * V_7 , T_1 V_152 )
{
T_1 V_41 ;
V_41 = F_3 ( V_2 , F_72 ( V_7 -> V_39 ) ) ;
V_41 &= ~ V_157 ;
V_41 |= F_73 ( V_152 ) ;
F_1 ( V_2 , F_72 ( V_7 -> V_39 ) , V_41 ) ;
V_7 -> V_158 = V_152 ;
}
static void F_74 ( struct V_45 * V_46 ,
T_1 V_159 , T_1 V_160 )
{
V_46 -> V_161 = V_160 ;
V_46 -> V_162 = V_159 ;
}
static void F_75 ( struct V_1 * V_2 ,
struct V_6 * V_7 ,
int V_163 )
{
T_1 V_41 ;
while ( V_163 > 0xff ) {
V_41 = 0xff << V_164 ;
F_1 ( V_2 , F_28 ( V_7 -> V_39 ) , V_41 ) ;
V_163 = V_163 - 0xff ;
}
V_41 = V_163 << V_164 ;
F_1 ( V_2 , F_28 ( V_7 -> V_39 ) , V_41 ) ;
}
static int F_76 ( struct V_1 * V_2 ,
struct V_6 * V_7 )
{
T_1 V_41 ;
int V_163 ;
V_41 = F_3 ( V_2 , F_77 ( V_7 -> V_39 ) ) ;
V_163 = ( V_41 & V_165 ) >>
V_166 ;
return V_163 ;
}
static int F_78 ( struct V_1 * V_2 ,
struct V_6 * V_7 )
{
int V_163 ;
V_163 = F_76 ( V_2 , V_7 ) ;
if ( V_163 )
F_75 ( V_2 , V_7 , V_163 ) ;
return V_163 ;
}
static T_1 F_79 ( int V_167 , int V_168 ,
int V_169 , int V_170 )
{
T_1 V_171 ;
V_171 = V_167 << V_172 ;
V_171 |= V_169 << V_173 ;
if ( V_168 == F_80 ( V_174 ) )
V_171 |= V_175 ;
else
V_171 |= V_176 ;
if ( V_170 == V_177 )
V_171 |= V_178 ;
else if ( V_170 == V_179 )
V_171 |= V_180 | V_178 ;
else
V_171 |= V_181 ;
return V_171 ;
}
static void F_81 ( struct V_1 * V_2 ,
struct V_45 * V_46 )
{
T_1 V_33 = V_46 -> V_33 ;
if ( ! F_14 ( V_33 ) ) {
F_82 ( V_2 -> V_19 ,
L_4 ,
V_33 , V_46 -> V_182 ) ;
return;
}
switch ( V_33 & V_183 ) {
case V_184 :
F_82 ( V_2 -> V_19 , L_5 ,
V_33 , V_46 -> V_182 ) ;
break;
case V_185 :
F_82 ( V_2 -> V_19 , L_6 ,
V_33 , V_46 -> V_182 ) ;
break;
case V_186 :
F_82 ( V_2 -> V_19 , L_7 ,
V_33 , V_46 -> V_182 ) ;
break;
case V_187 :
F_82 ( V_2 -> V_19 , L_8 ,
V_33 , V_46 -> V_182 ) ;
break;
}
}
static void F_83 ( struct V_1 * V_2 , T_1 V_33 ,
struct V_188 * V_189 )
{
if ( ( V_33 & V_190 ) &&
( V_33 & V_191 ) ) {
V_189 -> V_192 = 0 ;
V_189 -> V_193 = V_194 ;
return;
}
V_189 -> V_193 = V_195 ;
}
static struct V_6 * F_84 ( struct V_1 * V_2 ,
T_1 V_196 )
{
int V_63 = F_85 ( V_196 ) - 1 ;
return & V_2 -> V_66 [ V_63 ] ;
}
static void F_86 ( struct V_1 * V_2 ,
struct V_6 * V_7 , int V_197 )
{
int V_11 ;
for ( V_11 = 0 ; V_11 < V_197 ; V_11 ++ ) {
struct V_56 * V_57 = V_7 -> V_48 +
V_7 -> V_8 ;
struct V_188 * V_189 = V_7 -> V_198 [ V_7 -> V_8 ] ;
F_5 ( V_7 ) ;
if ( ! F_87 ( V_7 , V_57 -> V_162 ) )
F_88 ( V_2 -> V_19 -> V_19 . V_199 ,
V_57 -> V_162 ,
V_57 -> V_182 , V_200 ) ;
if ( ! V_189 )
continue;
F_89 ( V_189 ) ;
}
}
static void F_90 ( struct V_1 * V_2 ,
struct V_6 * V_7 )
{
struct V_201 * V_202 = F_91 ( V_2 -> V_19 , V_7 -> V_39 ) ;
int V_203 ;
V_203 = F_78 ( V_2 , V_7 ) ;
if ( ! V_203 )
return;
F_86 ( V_2 , V_7 , V_203 ) ;
V_7 -> V_71 -= V_203 ;
if ( F_92 ( V_202 ) ) {
if ( V_7 -> V_71 <= V_7 -> V_204 )
F_93 ( V_202 ) ;
}
}
static void * F_94 ( const struct V_1 * V_2 )
{
if ( F_95 ( V_2 -> V_205 <= V_206 ) )
return F_96 ( V_2 -> V_205 ) ;
else
return F_97 ( V_2 -> V_205 , V_207 ) ;
}
static void F_98 ( const struct V_1 * V_2 , void * V_4 )
{
if ( F_95 ( V_2 -> V_205 <= V_206 ) )
F_99 ( V_4 ) ;
else
F_100 ( V_4 ) ;
}
static int F_101 ( struct V_1 * V_2 ,
struct V_45 * V_46 )
{
T_4 V_159 ;
void * V_4 ;
V_4 = F_94 ( V_2 ) ;
if ( ! V_4 )
return - V_208 ;
V_159 = F_102 ( V_2 -> V_19 -> V_19 . V_199 , V_4 ,
F_103 ( V_2 -> V_209 ) ,
V_210 ) ;
if ( F_104 ( F_105 ( V_2 -> V_19 -> V_19 . V_199 , V_159 ) ) ) {
F_98 ( V_2 , V_4 ) ;
return - V_208 ;
}
F_74 ( V_46 , V_159 , ( T_1 ) V_4 ) ;
return 0 ;
}
static T_1 F_106 ( struct V_1 * V_2 , struct V_188 * V_189 )
{
if ( V_189 -> V_193 == V_211 ) {
int V_169 = 0 ;
T_5 V_168 = F_107 ( V_189 ) ;
T_3 V_170 ;
if ( V_168 == F_80 ( V_174 ) ) {
struct V_212 * V_213 = F_108 ( V_189 ) ;
V_169 = V_213 -> V_214 ;
V_170 = V_213 -> V_215 ;
} else if ( V_168 == F_80 ( V_216 ) ) {
struct V_217 * V_218 = F_109 ( V_189 ) ;
if ( F_110 ( V_189 ) > 0 )
V_169 = ( F_110 ( V_189 ) >> 2 ) ;
V_170 = V_218 -> V_219 ;
} else
return V_181 ;
return F_79 ( F_111 ( V_189 ) ,
V_168 , V_169 , V_170 ) ;
}
return V_181 ;
}
static void F_112 ( struct V_1 * V_2 ,
struct V_35 * V_36 )
{
int V_43 , V_11 ;
V_43 = F_17 ( V_2 , V_36 ) ;
for ( V_11 = 0 ; V_11 < V_36 -> V_9 ; V_11 ++ ) {
struct V_45 * V_46 = V_36 -> V_48 + V_11 ;
void * V_4 = ( void * ) V_46 -> V_161 ;
F_88 ( V_2 -> V_19 -> V_19 . V_199 , V_46 -> V_162 ,
F_103 ( V_2 -> V_209 ) , V_210 ) ;
F_98 ( V_2 , V_4 ) ;
}
if ( V_43 )
F_19 ( V_2 , V_36 , V_43 , V_43 ) ;
}
static int F_113 ( struct V_1 * V_2 , int V_220 ,
struct V_35 * V_36 )
{
struct V_221 * V_222 = F_114 ( V_2 -> V_223 ) ;
struct V_18 * V_19 = V_2 -> V_19 ;
int V_43 ;
T_1 V_224 = 0 ;
T_1 V_225 = 0 ;
V_43 = F_17 ( V_2 , V_36 ) ;
if ( V_220 > V_43 )
V_220 = V_43 ;
V_43 = 0 ;
while ( V_43 < V_220 ) {
struct V_45 * V_46 = F_20 ( V_36 ) ;
struct V_188 * V_189 ;
unsigned char * V_4 ;
T_4 V_159 ;
T_1 V_226 ;
int V_26 , V_227 ;
V_43 ++ ;
V_226 = V_46 -> V_33 ;
V_26 = V_46 -> V_182 - ( V_228 + V_52 ) ;
V_4 = ( unsigned char * ) V_46 -> V_161 ;
V_159 = V_46 -> V_162 ;
if ( ! F_14 ( V_226 ) ||
( V_226 & V_229 ) ) {
V_230:
V_19 -> V_20 . V_30 ++ ;
F_81 ( V_2 , V_46 ) ;
continue;
}
if ( V_26 <= V_231 ) {
V_189 = F_115 ( V_19 , V_26 ) ;
if ( F_104 ( ! V_189 ) )
goto V_230;
F_116 ( V_19 -> V_19 . V_199 ,
V_46 -> V_162 ,
V_52 + V_232 ,
V_26 ,
V_210 ) ;
memcpy ( F_117 ( V_189 , V_26 ) ,
V_4 + V_52 + V_232 ,
V_26 ) ;
V_189 -> V_215 = F_118 ( V_189 , V_19 ) ;
F_83 ( V_2 , V_226 , V_189 ) ;
F_119 ( & V_222 -> V_233 , V_189 ) ;
V_224 ++ ;
V_225 += V_26 ;
continue;
}
V_227 = F_101 ( V_2 , V_46 ) ;
if ( V_227 ) {
F_82 ( V_19 , L_9 ) ;
V_36 -> V_234 ++ ;
goto V_230;
}
V_189 = F_120 ( V_4 , V_2 -> V_205 > V_206 ? 0 : V_2 -> V_205 ) ;
F_88 ( V_19 -> V_19 . V_199 , V_159 ,
F_103 ( V_2 -> V_209 ) , V_210 ) ;
if ( ! V_189 )
goto V_230;
V_224 ++ ;
V_225 += V_26 ;
F_121 ( V_189 , V_52 + V_232 ) ;
F_117 ( V_189 , V_26 ) ;
V_189 -> V_215 = F_118 ( V_189 , V_19 ) ;
F_83 ( V_2 , V_226 , V_189 ) ;
F_119 ( & V_222 -> V_233 , V_189 ) ;
}
if ( V_224 ) {
struct V_23 * V_20 = F_114 ( V_2 -> V_20 ) ;
F_122 ( & V_20 -> V_29 ) ;
V_20 -> V_25 += V_224 ;
V_20 -> V_26 += V_225 ;
F_123 ( & V_20 -> V_29 ) ;
}
F_19 ( V_2 , V_36 , V_43 , V_43 ) ;
return V_43 ;
}
static inline void
F_124 ( struct V_188 * V_189 ,
struct V_1 * V_2 , struct V_6 * V_7 )
{
struct V_56 * V_57 ;
int V_235 = F_125 ( V_189 ) + F_126 ( V_189 ) ;
V_7 -> V_198 [ V_7 -> V_10 ] = NULL ;
V_57 = F_29 ( V_7 ) ;
V_57 -> V_182 = V_235 ;
V_57 -> V_171 = F_106 ( V_2 , V_189 ) ;
V_57 -> V_171 |= V_236 ;
V_57 -> V_162 = V_7 -> V_237 +
V_7 -> V_10 * V_238 ;
F_6 ( V_7 ) ;
}
static inline int
F_127 ( struct V_18 * V_19 , struct V_6 * V_7 ,
struct V_188 * V_189 , char * V_4 , int V_9 ,
bool V_239 , bool V_240 )
{
struct V_56 * V_57 ;
V_57 = F_29 ( V_7 ) ;
V_57 -> V_182 = V_9 ;
V_57 -> V_162 = F_102 ( V_19 -> V_19 . V_199 , V_4 ,
V_9 , V_200 ) ;
if ( F_104 ( F_105 ( V_19 -> V_19 . V_199 ,
V_57 -> V_162 ) ) ) {
F_30 ( V_7 ) ;
return - V_208 ;
}
V_57 -> V_171 = 0 ;
V_7 -> V_198 [ V_7 -> V_10 ] = NULL ;
if ( V_239 ) {
V_57 -> V_171 = V_241 ;
if ( V_240 )
V_7 -> V_198 [ V_7 -> V_10 ] = V_189 ;
}
F_6 ( V_7 ) ;
return 0 ;
}
static int F_128 ( struct V_188 * V_189 , struct V_18 * V_19 ,
struct V_6 * V_7 )
{
int V_242 , V_243 ;
int V_244 = 0 ;
struct V_1 * V_2 = F_9 ( V_19 ) ;
struct V_245 V_246 ;
int V_235 = F_125 ( V_189 ) + F_126 ( V_189 ) ;
int V_11 ;
if ( ( V_7 -> V_71 + F_129 ( V_189 ) ) >= V_7 -> V_9 )
return 0 ;
if ( F_130 ( V_189 ) < ( F_125 ( V_189 ) + F_126 ( V_189 ) ) ) {
F_131 ( L_10 ) ;
return 0 ;
}
F_132 ( V_189 , & V_246 ) ;
V_242 = V_189 -> V_247 - V_235 ;
while ( V_242 > 0 ) {
char * V_248 ;
V_243 = F_133 ( int , F_134 ( V_189 ) -> V_249 , V_242 ) ;
V_242 -= V_243 ;
V_244 ++ ;
V_248 = V_7 -> V_250 + V_7 -> V_10 * V_238 ;
F_135 ( V_189 , V_248 , & V_246 , V_243 , V_242 == 0 ) ;
F_124 ( V_189 , V_2 , V_7 ) ;
while ( V_243 > 0 ) {
int V_9 ;
V_244 ++ ;
V_9 = F_133 ( int , V_246 . V_9 , V_243 ) ;
if ( F_127 ( V_19 , V_7 , V_189 ,
V_246 . V_4 , V_9 ,
V_9 == V_243 ,
V_242 == 0 ) )
goto V_251;
V_243 -= V_9 ;
F_136 ( V_189 , & V_246 , V_9 ) ;
}
}
return V_244 ;
V_251:
for ( V_11 = V_244 - 1 ; V_11 >= 0 ; V_11 -- ) {
struct V_56 * V_57 = V_7 -> V_48 + V_11 ;
if ( ! F_87 ( V_7 , V_57 -> V_162 ) )
F_88 ( V_2 -> V_19 -> V_19 . V_199 ,
V_57 -> V_162 ,
V_57 -> V_182 ,
V_200 ) ;
F_30 ( V_7 ) ;
}
return 0 ;
}
static int F_137 ( struct V_1 * V_2 , struct V_188 * V_189 ,
struct V_6 * V_7 )
{
struct V_56 * V_57 ;
int V_11 , V_252 = F_134 ( V_189 ) -> V_252 ;
for ( V_11 = 0 ; V_11 < V_252 ; V_11 ++ ) {
T_6 * V_253 = & F_134 ( V_189 ) -> V_254 [ V_11 ] ;
void * V_147 = F_138 ( V_253 -> V_255 . V_256 ) + V_253 -> V_257 ;
V_57 = F_29 ( V_7 ) ;
V_57 -> V_182 = V_253 -> V_9 ;
V_57 -> V_162 =
F_102 ( V_2 -> V_19 -> V_19 . V_199 , V_147 ,
V_57 -> V_182 , V_200 ) ;
if ( F_105 ( V_2 -> V_19 -> V_19 . V_199 ,
V_57 -> V_162 ) ) {
F_30 ( V_7 ) ;
goto error;
}
if ( V_11 == V_252 - 1 ) {
V_57 -> V_171 = V_241 | V_258 ;
V_7 -> V_198 [ V_7 -> V_10 ] = V_189 ;
} else {
V_57 -> V_171 = 0 ;
V_7 -> V_198 [ V_7 -> V_10 ] = NULL ;
}
F_6 ( V_7 ) ;
}
return 0 ;
error:
for ( V_11 = V_11 - 1 ; V_11 >= 0 ; V_11 -- ) {
V_57 = V_7 -> V_48 + V_11 ;
F_88 ( V_2 -> V_19 -> V_19 . V_199 ,
V_57 -> V_162 ,
V_57 -> V_182 ,
V_200 ) ;
F_30 ( V_7 ) ;
}
return - V_208 ;
}
static int F_139 ( struct V_188 * V_189 , struct V_18 * V_19 )
{
struct V_1 * V_2 = F_9 ( V_19 ) ;
T_7 V_259 = F_140 ( V_189 ) ;
struct V_6 * V_7 = & V_2 -> V_66 [ V_259 ] ;
struct V_56 * V_57 ;
int V_247 = V_189 -> V_247 ;
int V_254 = 0 ;
T_1 V_260 ;
if ( ! F_141 ( V_19 ) )
goto V_261;
if ( F_142 ( V_189 ) ) {
V_254 = F_128 ( V_189 , V_19 , V_7 ) ;
goto V_261;
}
V_254 = F_134 ( V_189 ) -> V_252 + 1 ;
V_57 = F_29 ( V_7 ) ;
V_260 = F_106 ( V_2 , V_189 ) ;
V_57 -> V_182 = F_130 ( V_189 ) ;
V_57 -> V_162 = F_102 ( V_19 -> V_19 . V_199 , V_189 -> V_4 ,
V_57 -> V_182 ,
V_200 ) ;
if ( F_104 ( F_105 ( V_19 -> V_19 . V_199 ,
V_57 -> V_162 ) ) ) {
F_30 ( V_7 ) ;
V_254 = 0 ;
goto V_261;
}
if ( V_254 == 1 ) {
V_260 |= V_262 ;
V_57 -> V_171 = V_260 ;
V_7 -> V_198 [ V_7 -> V_10 ] = V_189 ;
F_6 ( V_7 ) ;
} else {
V_260 |= V_236 ;
V_7 -> V_198 [ V_7 -> V_10 ] = NULL ;
F_6 ( V_7 ) ;
V_57 -> V_171 = V_260 ;
if ( F_137 ( V_2 , V_189 , V_7 ) ) {
F_88 ( V_19 -> V_19 . V_199 ,
V_57 -> V_162 ,
V_57 -> V_182 ,
V_200 ) ;
F_30 ( V_7 ) ;
V_254 = 0 ;
goto V_261;
}
}
V_261:
if ( V_254 > 0 ) {
struct V_23 * V_20 = F_114 ( V_2 -> V_20 ) ;
struct V_201 * V_202 = F_91 ( V_19 , V_259 ) ;
V_7 -> V_71 += V_254 ;
F_27 ( V_2 , V_7 , V_254 ) ;
if ( V_7 -> V_71 >= V_7 -> V_263 )
F_143 ( V_202 ) ;
F_122 ( & V_20 -> V_29 ) ;
V_20 -> V_27 ++ ;
V_20 -> V_28 += V_247 ;
F_123 ( & V_20 -> V_29 ) ;
} else {
V_19 -> V_20 . V_32 ++ ;
F_89 ( V_189 ) ;
}
return V_264 ;
}
static void F_144 ( struct V_1 * V_2 ,
struct V_6 * V_7 )
{
int V_203 = V_7 -> V_71 ;
F_86 ( V_2 , V_7 , V_203 ) ;
V_7 -> V_71 = 0 ;
V_7 -> V_10 = 0 ;
V_7 -> V_8 = 0 ;
}
static void F_145 ( struct V_1 * V_2 , T_1 V_265 )
{
struct V_6 * V_7 ;
struct V_201 * V_202 ;
while ( V_265 ) {
V_7 = F_84 ( V_2 , V_265 ) ;
V_202 = F_91 ( V_2 -> V_19 , V_7 -> V_39 ) ;
F_146 ( V_202 , F_147 () ) ;
if ( V_7 -> V_71 )
F_90 ( V_2 , V_7 ) ;
F_148 ( V_202 ) ;
V_265 &= ~ ( ( 1 << V_7 -> V_39 ) ) ;
}
}
static int F_149 ( unsigned char * V_147 )
{
int V_266 = 0 ;
int V_11 ;
for ( V_11 = 0 ; V_11 < V_267 ; V_11 ++ ) {
int V_268 ;
V_266 = ( V_266 ^ V_147 [ V_11 ] ) << 8 ;
for ( V_268 = 7 ; V_268 >= 0 ; V_268 -- ) {
if ( V_266 & ( 0x100 << V_268 ) )
V_266 ^= 0x107 << V_268 ;
}
}
return V_266 ;
}
static void F_150 ( struct V_1 * V_2 ,
unsigned char V_269 ,
int V_63 )
{
unsigned int V_270 ;
unsigned int V_145 ;
unsigned int V_146 ;
V_145 = ( V_269 / 4 ) ;
V_146 = V_269 % 4 ;
V_270 = F_3 ( V_2 , ( V_84
+ V_145 * 4 ) ) ;
if ( V_63 == - 1 )
V_270 &= ~ ( 0xff << ( 8 * V_146 ) ) ;
else {
V_270 &= ~ ( 0xff << ( 8 * V_146 ) ) ;
V_270 |= ( ( 0x01 | ( V_63 << 1 ) ) << ( 8 * V_146 ) ) ;
}
F_1 ( V_2 , V_84 + V_145 * 4 ,
V_270 ) ;
}
static void F_151 ( struct V_1 * V_2 ,
unsigned char V_271 ,
int V_63 )
{
unsigned int V_272 ;
unsigned int V_145 ;
unsigned int V_146 ;
V_145 = ( V_271 / 4 ) * 4 ;
V_146 = V_271 % 4 ;
V_272 = F_3 ( V_2 , V_86 + V_145 ) ;
if ( V_63 == - 1 ) {
V_272 &= ~ ( 0xff << ( 8 * V_146 ) ) ;
} else {
V_272 &= ~ ( 0xff << ( 8 * V_146 ) ) ;
V_272 |= ( ( 0x01 | ( V_63 << 1 ) ) << ( 8 * V_146 ) ) ;
}
F_1 ( V_2 , V_86 + V_145 , V_272 ) ;
}
static int F_152 ( struct V_1 * V_2 , unsigned char * V_273 ,
int V_63 )
{
unsigned char V_274 = 0 ;
if ( memcmp ( V_273 , L_11 , 5 ) == 0 ) {
F_150 ( V_2 , V_273 [ 5 ] , V_63 ) ;
return 0 ;
}
V_274 = F_149 ( V_273 ) ;
if ( V_63 == - 1 ) {
if ( V_2 -> V_85 [ V_274 ] == 0 ) {
F_153 ( V_2 -> V_19 , L_12 ,
V_274 ) ;
return - V_275 ;
}
V_2 -> V_85 [ V_274 ] -- ;
if ( V_2 -> V_85 [ V_274 ] != 0 ) {
F_153 ( V_2 -> V_19 ,
L_13 ,
V_2 -> V_85 [ V_274 ] , V_274 ) ;
return - V_275 ;
}
} else
V_2 -> V_85 [ V_274 ] ++ ;
F_151 ( V_2 , V_274 , V_63 ) ;
return 0 ;
}
static void F_154 ( struct V_1 * V_2 ,
int V_276 )
{
T_1 V_277 , V_41 ;
V_277 = F_3 ( V_2 , V_122 ) ;
V_41 = F_3 ( V_2 , V_278 ) ;
if ( V_276 ) {
V_277 |= V_279 ;
V_41 |= V_280 ;
F_1 ( V_2 , V_150 , 0xffff ) ;
F_1 ( V_2 , V_151 , 0xffffffff ) ;
} else {
V_277 &= ~ V_279 ;
V_41 &= ~ V_280 ;
}
F_1 ( V_2 , V_122 , V_277 ) ;
F_1 ( V_2 , V_278 , V_41 ) ;
}
static void F_155 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = F_9 ( V_19 ) ;
struct V_281 * V_282 ;
if ( V_19 -> V_283 & V_284 ) {
F_154 ( V_2 , 1 ) ;
F_41 ( V_2 , V_2 -> V_114 ) ;
F_42 ( V_2 , V_2 -> V_114 ) ;
F_43 ( V_2 , V_2 -> V_114 ) ;
} else {
F_154 ( V_2 , 0 ) ;
F_41 ( V_2 , - 1 ) ;
F_64 ( V_2 , V_19 -> V_285 , V_2 -> V_114 ) ;
if ( V_19 -> V_283 & V_286 ) {
F_42 ( V_2 , V_2 -> V_114 ) ;
F_43 ( V_2 , V_2 -> V_114 ) ;
} else {
F_42 ( V_2 , - 1 ) ;
F_43 ( V_2 , - 1 ) ;
if ( ! F_156 ( V_19 ) ) {
F_157 (ha, dev) {
F_152 ( V_2 , V_282 -> V_147 ,
V_2 -> V_114 ) ;
}
}
}
}
}
static T_8 F_158 ( int V_287 , void * V_288 )
{
struct V_221 * V_222 = (struct V_221 * ) V_288 ;
F_159 ( V_222 -> V_2 -> V_19 -> V_287 ) ;
F_160 ( & V_222 -> V_233 ) ;
return V_289 ;
}
static int F_161 ( struct V_1 * V_2 ,
struct V_290 * V_291 )
{
struct V_292 V_33 ;
struct V_292 V_293 = {} ;
T_1 V_294 = F_3 ( V_2 , V_295 ) ;
V_33 . V_296 = ! ! ( V_294 & V_297 ) ;
if ( V_294 & V_298 )
V_33 . V_299 = V_300 ;
else if ( V_294 & V_301 )
V_33 . V_299 = V_302 ;
else
V_33 . V_299 = V_303 ;
V_33 . V_304 = ! ! ( V_294 & V_305 ) ;
V_293 . V_296 = 1 ;
V_293 . V_299 = 1 ;
V_293 . V_304 = 1 ;
F_162 ( V_291 , & V_33 , & V_293 ) ;
return 0 ;
}
static int F_163 ( struct V_306 * V_233 , int V_307 )
{
int V_43 = 0 ;
T_1 V_308 ;
int V_309 ;
struct V_1 * V_2 = F_9 ( V_233 -> V_19 ) ;
struct V_221 * V_222 = F_114 ( V_2 -> V_223 ) ;
if ( ! F_141 ( V_2 -> V_19 ) ) {
F_164 ( & V_222 -> V_233 ) ;
return V_43 ;
}
V_308 = F_3 ( V_2 , V_106 ) ;
if ( V_308 & V_103 ) {
T_1 V_310 = F_3 ( V_2 , V_107 ) ;
F_1 ( V_2 , V_107 , 0 ) ;
if ( V_2 -> V_133 && ( V_310 &
( V_311 |
V_312 |
V_313 ) ) ) {
F_161 ( V_2 , V_2 -> V_314 ) ;
}
}
if ( V_308 & V_102 ) {
F_145 ( V_2 , ( V_308 & V_102 ) ) ;
V_308 &= ~ V_102 ;
}
V_309 = F_85 ( ( ( V_308 >> 8 ) & 0xff ) ) ;
V_308 |= V_222 -> V_308 ;
if ( V_309 ) {
V_309 = V_309 - 1 ;
V_43 = F_113 ( V_2 , V_307 , & V_2 -> V_69 [ V_309 ] ) ;
}
V_307 -= V_43 ;
if ( V_307 > 0 ) {
V_308 = 0 ;
F_164 ( & V_222 -> V_233 ) ;
F_165 ( V_2 -> V_19 -> V_287 , 0 ) ;
}
V_222 -> V_308 = V_308 ;
return V_43 ;
}
static int F_166 ( struct V_1 * V_2 , struct V_35 * V_36 ,
int V_197 )
{
int V_11 ;
for ( V_11 = 0 ; V_11 < V_197 ; V_11 ++ ) {
memset ( V_36 -> V_48 + V_11 , 0 , sizeof( struct V_45 ) ) ;
if ( F_101 ( V_2 , V_36 -> V_48 + V_11 ) != 0 ) {
F_82 ( V_2 -> V_19 , L_14 ,
V_315 , V_36 -> V_39 , V_11 , V_197 ) ;
break;
}
}
F_15 ( V_2 , V_36 , V_11 ) ;
return V_11 ;
}
static void F_167 ( struct V_1 * V_2 )
{
int V_63 ;
for ( V_63 = 0 ; V_63 < V_65 ; V_63 ++ )
F_144 ( V_2 , & V_2 -> V_66 [ V_63 ] ) ;
F_1 ( V_2 , V_117 , V_118 ) ;
F_1 ( V_2 , V_117 , 0 ) ;
}
static void F_168 ( struct V_1 * V_2 )
{
F_1 ( V_2 , V_115 , V_116 ) ;
F_1 ( V_2 , V_115 , 0 ) ;
}
static int F_169 ( struct V_1 * V_2 ,
struct V_35 * V_36 )
{
V_36 -> V_9 = V_2 -> V_316 ;
V_36 -> V_48 = F_170 ( V_2 -> V_19 -> V_19 . V_199 ,
V_36 -> V_9 * V_317 ,
& V_36 -> V_318 , V_319 ) ;
if ( V_36 -> V_48 == NULL )
return - V_208 ;
F_171 ( V_36 -> V_48 !=
F_172 ( V_36 -> V_48 , V_320 ) ) ;
V_36 -> V_58 = V_36 -> V_9 - 1 ;
F_1 ( V_2 , F_173 ( V_36 -> V_39 ) , V_36 -> V_318 ) ;
F_1 ( V_2 , F_32 ( V_36 -> V_39 ) , V_36 -> V_9 ) ;
F_24 ( V_2 , V_36 , V_232 ) ;
F_65 ( V_2 , V_36 , V_36 -> V_153 ) ;
F_68 ( V_2 , V_36 , V_36 -> V_156 ) ;
F_31 ( V_2 , V_36 , F_103 ( V_2 -> V_209 ) ) ;
F_33 ( V_2 , V_36 ) ;
F_166 ( V_2 , V_36 , V_36 -> V_9 ) ;
return 0 ;
}
static void F_174 ( struct V_1 * V_2 ,
struct V_35 * V_36 )
{
F_112 ( V_2 , V_36 ) ;
if ( V_36 -> V_48 )
F_175 ( V_2 -> V_19 -> V_19 . V_199 ,
V_36 -> V_9 * V_317 ,
V_36 -> V_48 ,
V_36 -> V_318 ) ;
V_36 -> V_48 = NULL ;
V_36 -> V_58 = 0 ;
V_36 -> V_47 = 0 ;
V_36 -> V_318 = 0 ;
}
static int F_176 ( struct V_1 * V_2 ,
struct V_6 * V_7 )
{
int V_22 ;
V_7 -> V_9 = V_2 -> V_321 ;
V_7 -> V_263 = V_7 -> V_9 - V_322 ;
V_7 -> V_204 = V_7 -> V_263 / 2 ;
V_7 -> V_48 = F_170 ( V_2 -> V_19 -> V_19 . V_199 ,
V_7 -> V_9 * V_317 ,
& V_7 -> V_318 , V_319 ) ;
if ( V_7 -> V_48 == NULL )
return - V_208 ;
F_171 ( V_7 -> V_48 !=
F_172 ( V_7 -> V_48 , V_320 ) ) ;
V_7 -> V_58 = V_7 -> V_9 - 1 ;
F_1 ( V_2 , F_56 ( V_7 -> V_39 ) , 0x03ffffff ) ;
F_1 ( V_2 , F_55 ( V_7 -> V_39 ) , 0x3fffffff ) ;
F_1 ( V_2 , F_177 ( V_7 -> V_39 ) , V_7 -> V_318 ) ;
F_1 ( V_2 , F_72 ( V_7 -> V_39 ) , V_7 -> V_9 ) ;
V_7 -> V_198 = F_97 ( V_7 -> V_9 * sizeof( * V_7 -> V_198 ) , V_319 ) ;
if ( V_7 -> V_198 == NULL ) {
F_175 ( V_2 -> V_19 -> V_19 . V_199 ,
V_7 -> V_9 * V_317 ,
V_7 -> V_48 , V_7 -> V_318 ) ;
return - V_208 ;
}
V_7 -> V_250 = F_170 ( V_2 -> V_19 -> V_19 . V_199 ,
V_7 -> V_9 * V_238 ,
& V_7 -> V_237 , V_319 ) ;
if ( V_7 -> V_250 == NULL ) {
F_100 ( V_7 -> V_198 ) ;
F_175 ( V_2 -> V_19 -> V_19 . V_199 ,
V_7 -> V_9 * V_317 ,
V_7 -> V_48 , V_7 -> V_318 ) ;
return - V_208 ;
}
F_71 ( V_2 , V_7 , V_7 -> V_158 ) ;
if ( V_65 > 1 )
V_22 = V_7 -> V_39 % F_49 () ;
else
V_22 = V_2 -> V_114 % F_49 () ;
F_178 ( V_22 , & V_7 -> V_323 ) ;
F_179 ( V_2 -> V_19 , & V_7 -> V_323 , V_7 -> V_39 ) ;
return 0 ;
}
static void F_180 ( struct V_1 * V_2 ,
struct V_6 * V_7 )
{
F_100 ( V_7 -> V_198 ) ;
if ( V_7 -> V_250 )
F_175 ( V_2 -> V_19 -> V_19 . V_199 ,
V_7 -> V_9 * V_238 ,
V_7 -> V_250 , V_7 -> V_237 ) ;
if ( V_7 -> V_48 )
F_175 ( V_2 -> V_19 -> V_19 . V_199 ,
V_7 -> V_9 * V_317 ,
V_7 -> V_48 , V_7 -> V_318 ) ;
V_7 -> V_48 = NULL ;
V_7 -> V_58 = 0 ;
V_7 -> V_47 = 0 ;
V_7 -> V_318 = 0 ;
F_1 ( V_2 , F_56 ( V_7 -> V_39 ) , 0 ) ;
F_1 ( V_2 , F_55 ( V_7 -> V_39 ) , 0 ) ;
F_1 ( V_2 , F_177 ( V_7 -> V_39 ) , 0 ) ;
F_1 ( V_2 , F_72 ( V_7 -> V_39 ) , 0 ) ;
}
static void F_181 ( struct V_1 * V_2 )
{
int V_63 ;
for ( V_63 = 0 ; V_63 < V_65 ; V_63 ++ )
F_180 ( V_2 , & V_2 -> V_66 [ V_63 ] ) ;
}
static void F_182 ( struct V_1 * V_2 )
{
int V_63 ;
for ( V_63 = 0 ; V_63 < V_65 ; V_63 ++ )
F_174 ( V_2 , & V_2 -> V_69 [ V_63 ] ) ;
}
static int F_183 ( struct V_1 * V_2 )
{
int V_63 ;
for ( V_63 = 0 ; V_63 < V_68 ; V_63 ++ ) {
int V_227 = F_169 ( V_2 , & V_2 -> V_69 [ V_63 ] ) ;
if ( V_227 ) {
F_82 ( V_2 -> V_19 , L_15 ,
V_315 , V_63 ) ;
F_182 ( V_2 ) ;
return V_227 ;
}
}
return 0 ;
}
static int F_184 ( struct V_1 * V_2 )
{
int V_63 ;
for ( V_63 = 0 ; V_63 < V_65 ; V_63 ++ ) {
int V_227 = F_176 ( V_2 , & V_2 -> V_66 [ V_63 ] ) ;
if ( V_227 ) {
F_82 ( V_2 -> V_19 , L_16 ,
V_315 , V_63 ) ;
F_181 ( V_2 ) ;
return V_227 ;
}
}
return 0 ;
}
static void F_185 ( struct V_1 * V_2 )
{
int V_22 ;
F_23 ( V_2 , V_2 -> V_209 ) ;
F_61 ( V_2 , V_2 -> V_209 ) ;
F_39 ( V_2 ) ;
F_186 (cpu) {
struct V_221 * V_222 = F_11 ( V_2 -> V_223 , V_22 ) ;
F_187 ( & V_222 -> V_233 ) ;
}
F_50 ( F_45 , V_2 , true ) ;
F_1 ( V_2 , V_105 ,
V_311 |
V_312 |
V_313 ) ;
F_188 ( V_2 -> V_314 ) ;
F_189 ( V_2 -> V_19 ) ;
}
static void F_190 ( struct V_1 * V_2 )
{
unsigned int V_22 ;
F_191 ( V_2 -> V_314 ) ;
F_186 (cpu) {
struct V_221 * V_222 = F_11 ( V_2 -> V_223 , V_22 ) ;
F_192 ( & V_222 -> V_233 ) ;
}
F_193 ( V_2 -> V_19 ) ;
F_35 ( V_2 ) ;
F_194 ( V_2 -> V_19 ) ;
F_40 ( V_2 ) ;
F_50 ( F_47 , V_2 , true ) ;
F_50 ( F_46 , V_2 , true ) ;
F_167 ( V_2 ) ;
F_168 ( V_2 ) ;
}
static int F_195 ( struct V_18 * V_19 , int V_137 )
{
if ( V_137 < 68 ) {
F_82 ( V_19 , L_17 ) ;
return - V_275 ;
}
if ( V_137 > 9676 ) {
F_153 ( V_19 , L_18 , V_137 ) ;
V_137 = 9676 ;
}
if ( ! F_196 ( F_197 ( V_137 ) , 8 ) ) {
F_153 ( V_19 , L_19 ,
V_137 , F_198 ( F_197 ( V_137 ) , 8 ) ) ;
V_137 = F_198 ( F_197 ( V_137 ) , 8 ) ;
}
return V_137 ;
}
static int F_199 ( struct V_18 * V_19 , int V_137 )
{
struct V_1 * V_2 = F_9 ( V_19 ) ;
int V_324 ;
V_137 = F_195 ( V_19 , V_137 ) ;
if ( V_137 < 0 )
return - V_275 ;
V_19 -> V_137 = V_137 ;
if ( ! F_141 ( V_19 ) ) {
F_200 ( V_19 ) ;
return 0 ;
}
F_190 ( V_2 ) ;
F_181 ( V_2 ) ;
F_182 ( V_2 ) ;
V_2 -> V_209 = F_197 ( V_19 -> V_137 ) ;
V_2 -> V_205 = F_201 ( F_103 ( V_2 -> V_209 ) ) +
F_201 ( sizeof( struct V_325 ) ) ;
V_324 = F_183 ( V_2 ) ;
if ( V_324 ) {
F_82 ( V_19 , L_20 ) ;
return V_324 ;
}
V_324 = F_184 ( V_2 ) ;
if ( V_324 ) {
F_82 ( V_19 , L_21 ) ;
return V_324 ;
}
F_185 ( V_2 ) ;
F_34 ( V_2 ) ;
F_200 ( V_19 ) ;
return 0 ;
}
static T_9 F_202 ( struct V_18 * V_19 ,
T_9 V_326 )
{
struct V_1 * V_2 = F_9 ( V_19 ) ;
if ( V_2 -> V_327 && V_19 -> V_137 > V_2 -> V_327 ) {
V_326 &= ~ ( V_328 | V_329 ) ;
F_153 ( V_19 ,
L_22 ,
V_2 -> V_327 ) ;
}
return V_326 ;
}
static void F_203 ( struct V_1 * V_2 , unsigned char * V_147 )
{
T_1 V_330 , V_331 ;
V_330 = F_3 ( V_2 , V_150 ) ;
V_331 = F_3 ( V_2 , V_151 ) ;
V_147 [ 0 ] = ( V_331 >> 24 ) & 0xFF ;
V_147 [ 1 ] = ( V_331 >> 16 ) & 0xFF ;
V_147 [ 2 ] = ( V_331 >> 8 ) & 0xFF ;
V_147 [ 3 ] = V_331 & 0xFF ;
V_147 [ 4 ] = ( V_330 >> 8 ) & 0xFF ;
V_147 [ 5 ] = V_330 & 0xFF ;
}
static int F_204 ( struct V_18 * V_19 , void * V_147 )
{
struct V_1 * V_2 = F_9 ( V_19 ) ;
struct V_332 * V_332 = V_147 ;
int V_324 ;
V_324 = F_205 ( V_19 , V_147 ) ;
if ( V_324 < 0 )
return V_324 ;
F_64 ( V_2 , V_19 -> V_285 , - 1 ) ;
F_64 ( V_2 , V_332 -> V_333 , V_2 -> V_114 ) ;
F_206 ( V_19 , V_147 ) ;
return 0 ;
}
static void F_207 ( struct V_18 * V_334 )
{
struct V_1 * V_2 = F_9 ( V_334 ) ;
struct V_290 * V_335 = V_2 -> V_314 ;
int V_336 = 0 ;
if ( V_335 -> V_296 ) {
if ( ( V_2 -> V_299 != V_335 -> V_299 ) ||
( V_2 -> V_304 != V_335 -> V_304 ) ) {
T_1 V_41 ;
V_41 = F_3 ( V_2 , V_88 ) ;
V_41 &= ~ ( V_337 |
V_338 |
V_339 ) ;
if ( V_335 -> V_304 )
V_41 |= V_339 ;
if ( V_335 -> V_299 == V_300 )
V_41 |= V_338 ;
else if ( V_335 -> V_299 == V_302 )
V_41 |= V_337 ;
F_1 ( V_2 , V_88 , V_41 ) ;
V_2 -> V_304 = V_335 -> V_304 ;
V_2 -> V_299 = V_335 -> V_299 ;
}
}
if ( V_335 -> V_296 != V_2 -> V_296 ) {
if ( ! V_335 -> V_296 ) {
V_2 -> V_304 = - 1 ;
V_2 -> V_299 = 0 ;
}
V_2 -> V_296 = V_335 -> V_296 ;
V_336 = 1 ;
}
if ( V_336 ) {
if ( V_335 -> V_296 ) {
if ( ! V_2 -> V_133 ) {
T_1 V_41 = F_3 ( V_2 ,
V_88 ) ;
V_41 &= ~ V_90 ;
V_41 |= V_89 ;
F_1 ( V_2 , V_88 ,
V_41 ) ;
}
F_34 ( V_2 ) ;
} else {
if ( ! V_2 -> V_133 ) {
T_1 V_41 = F_3 ( V_2 ,
V_88 ) ;
V_41 &= ~ V_89 ;
V_41 |= V_90 ;
F_1 ( V_2 , V_88 ,
V_41 ) ;
}
F_35 ( V_2 ) ;
}
F_208 ( V_335 ) ;
}
}
static int F_209 ( struct V_1 * V_2 )
{
struct V_290 * V_314 ;
V_314 = F_210 ( V_2 -> V_19 , V_2 -> V_340 , F_207 , 0 ,
V_2 -> V_341 ) ;
if ( ! V_314 ) {
F_82 ( V_2 -> V_19 , L_23 ) ;
return - V_342 ;
}
V_314 -> V_343 &= V_344 ;
V_314 -> V_345 = V_314 -> V_343 ;
V_2 -> V_314 = V_314 ;
V_2 -> V_296 = 0 ;
V_2 -> V_304 = 0 ;
V_2 -> V_299 = 0 ;
return 0 ;
}
static void F_211 ( struct V_1 * V_2 )
{
F_212 ( V_2 -> V_314 ) ;
V_2 -> V_314 = NULL ;
}
static void F_213 ( void * V_99 )
{
struct V_1 * V_2 = V_99 ;
F_165 ( V_2 -> V_19 -> V_287 , V_346 ) ;
}
static void F_214 ( void * V_99 )
{
struct V_1 * V_2 = V_99 ;
F_159 ( V_2 -> V_19 -> V_287 ) ;
}
static void F_215 ( struct V_1 * V_2 )
{
int V_347 = 0 , V_109 , V_22 , V_11 = 0 ;
if ( F_216 ( V_2 -> V_114 ) )
V_347 = V_2 -> V_114 ;
V_109 = F_49 () ;
F_186 (cpu) {
int V_112 = 0 , V_113 = 0 ;
int V_36 ;
for ( V_36 = 0 ; V_36 < V_68 ; V_36 ++ )
if ( ( V_36 % V_109 ) == V_22 )
V_112 |= F_52 ( V_36 ) ;
if ( V_22 == V_347 )
V_112 |= F_52 ( V_2 -> V_114 ) ;
if ( V_65 == 1 )
V_113 = ( V_22 == V_347 ) ?
F_53 ( 1 ) : 0 ;
else
V_113 = F_3 ( V_2 , F_54 ( V_22 ) ) &
V_348 ;
F_1 ( V_2 , F_54 ( V_22 ) , V_112 | V_113 ) ;
F_217 ( V_22 , F_45 ,
V_2 , true ) ;
V_11 ++ ;
}
}
static int F_218 ( struct V_349 * V_350 ,
unsigned long V_351 , void * V_352 )
{
struct V_1 * V_2 = F_219 ( V_350 , struct V_1 ,
V_353 ) ;
int V_22 = ( unsigned long ) V_352 , V_354 ;
struct V_221 * V_222 = F_11 ( V_2 -> V_223 , V_22 ) ;
switch ( V_351 ) {
case V_355 :
case V_356 :
F_220 ( & V_2 -> V_357 ) ;
if ( V_2 -> V_358 ) {
F_221 ( & V_2 -> V_357 ) ;
break;
}
F_194 ( V_2 -> V_19 ) ;
F_186 (other_cpu) {
if ( V_354 != V_22 ) {
struct V_221 * V_359 =
F_11 ( V_2 -> V_223 , V_354 ) ;
F_222 ( & V_359 -> V_233 ) ;
}
}
F_50 ( F_46 , V_2 , true ) ;
F_187 ( & V_222 -> V_233 ) ;
F_217 ( V_22 , F_213 ,
V_2 , true ) ;
F_215 ( V_2 ) ;
F_50 ( F_45 , V_2 , true ) ;
F_1 ( V_2 , V_105 ,
V_311 |
V_312 |
V_313 ) ;
F_189 ( V_2 -> V_19 ) ;
F_221 ( & V_2 -> V_357 ) ;
break;
case V_360 :
case V_361 :
F_194 ( V_2 -> V_19 ) ;
F_220 ( & V_2 -> V_357 ) ;
F_50 ( F_46 , V_2 , true ) ;
F_221 ( & V_2 -> V_357 ) ;
F_222 ( & V_222 -> V_233 ) ;
F_192 ( & V_222 -> V_233 ) ;
F_217 ( V_22 , F_214 ,
V_2 , true ) ;
break;
case V_362 :
case V_363 :
F_220 ( & V_2 -> V_357 ) ;
F_215 ( V_2 ) ;
F_221 ( & V_2 -> V_357 ) ;
F_50 ( F_45 , V_2 , true ) ;
F_1 ( V_2 , V_105 ,
V_311 |
V_312 |
V_313 ) ;
F_189 ( V_2 -> V_19 ) ;
break;
}
return V_364 ;
}
static int F_223 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = F_9 ( V_19 ) ;
int V_324 ;
V_2 -> V_209 = F_197 ( V_2 -> V_19 -> V_137 ) ;
V_2 -> V_205 = F_201 ( F_103 ( V_2 -> V_209 ) ) +
F_201 ( sizeof( struct V_325 ) ) ;
V_324 = F_183 ( V_2 ) ;
if ( V_324 )
return V_324 ;
V_324 = F_184 ( V_2 ) ;
if ( V_324 )
goto V_365;
V_324 = F_224 ( V_2 -> V_19 -> V_287 , F_158 ,
V_366 , V_2 -> V_223 ) ;
if ( V_324 ) {
F_82 ( V_2 -> V_19 , L_24 , V_2 -> V_19 -> V_287 ) ;
goto V_367;
}
F_50 ( F_213 , V_2 , true ) ;
V_2 -> V_358 = false ;
F_225 ( & V_2 -> V_353 ) ;
F_193 ( V_2 -> V_19 ) ;
V_324 = F_209 ( V_2 ) ;
if ( V_324 < 0 ) {
F_82 ( V_19 , L_25 ) ;
goto V_368;
}
F_185 ( V_2 ) ;
return 0 ;
V_368:
F_226 ( V_2 -> V_19 -> V_287 , V_2 -> V_223 ) ;
V_367:
F_181 ( V_2 ) ;
V_365:
F_182 ( V_2 ) ;
return V_324 ;
}
static int F_227 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = F_9 ( V_19 ) ;
F_220 ( & V_2 -> V_357 ) ;
V_2 -> V_358 = true ;
F_190 ( V_2 ) ;
F_211 ( V_2 ) ;
F_228 ( & V_2 -> V_353 ) ;
F_221 ( & V_2 -> V_357 ) ;
F_50 ( F_214 , V_2 , true ) ;
F_226 ( V_19 -> V_287 , V_2 -> V_223 ) ;
F_182 ( V_2 ) ;
F_181 ( V_2 ) ;
return 0 ;
}
static int F_229 ( struct V_18 * V_19 , struct V_369 * V_370 , int V_371 )
{
struct V_1 * V_2 = F_9 ( V_19 ) ;
if ( ! V_2 -> V_314 )
return - V_372 ;
return F_230 ( V_2 -> V_314 , V_370 , V_371 ) ;
}
int F_231 ( struct V_18 * V_19 , struct V_373 * V_371 )
{
struct V_1 * V_2 = F_9 ( V_19 ) ;
if ( ! V_2 -> V_314 )
return - V_342 ;
return F_232 ( V_2 -> V_314 , V_371 ) ;
}
int F_233 ( struct V_18 * V_19 , struct V_373 * V_371 )
{
struct V_1 * V_2 = F_9 ( V_19 ) ;
struct V_290 * V_335 = V_2 -> V_314 ;
if ( ! V_335 )
return - V_342 ;
if ( ( V_371 -> V_374 == V_375 ) != V_2 -> V_133 ) {
T_1 V_41 ;
F_44 ( V_2 , V_371 -> V_374 == V_375 ) ;
if ( V_371 -> V_374 == V_376 ) {
V_41 = F_3 ( V_2 , V_88 ) ;
V_41 &= ~ ( V_337 |
V_338 |
V_339 ) ;
if ( V_335 -> V_304 )
V_41 |= V_339 ;
if ( V_335 -> V_299 == V_300 )
V_41 |= V_338 ;
else if ( V_335 -> V_299 == V_302 )
V_41 |= V_337 ;
F_1 ( V_2 , V_88 , V_41 ) ;
}
V_2 -> V_133 = ( V_371 -> V_374 == V_375 ) ;
F_153 ( V_2 -> V_19 , L_26 ,
V_2 -> V_133 ) ;
if ( F_141 ( V_19 ) ) {
F_35 ( V_2 ) ;
F_34 ( V_2 ) ;
}
}
return F_234 ( V_2 -> V_314 , V_371 ) ;
}
static int F_235 ( struct V_18 * V_19 ,
struct V_377 * V_378 )
{
struct V_1 * V_2 = F_9 ( V_19 ) ;
int V_63 ;
for ( V_63 = 0 ; V_63 < V_68 ; V_63 ++ ) {
struct V_35 * V_36 = & V_2 -> V_69 [ V_63 ] ;
V_36 -> V_156 = V_378 -> V_379 ;
V_36 -> V_153 = V_378 -> V_380 ;
F_65 ( V_2 , V_36 , V_36 -> V_153 ) ;
F_68 ( V_2 , V_36 , V_36 -> V_156 ) ;
}
for ( V_63 = 0 ; V_63 < V_65 ; V_63 ++ ) {
struct V_6 * V_7 = & V_2 -> V_66 [ V_63 ] ;
V_7 -> V_158 = V_378 -> V_381 ;
F_71 ( V_2 , V_7 , V_7 -> V_158 ) ;
}
return 0 ;
}
static int F_236 ( struct V_18 * V_19 ,
struct V_377 * V_378 )
{
struct V_1 * V_2 = F_9 ( V_19 ) ;
V_378 -> V_379 = V_2 -> V_69 [ 0 ] . V_156 ;
V_378 -> V_380 = V_2 -> V_69 [ 0 ] . V_153 ;
V_378 -> V_381 = V_2 -> V_66 [ 0 ] . V_158 ;
return 0 ;
}
static void F_237 ( struct V_18 * V_19 ,
struct V_382 * V_383 )
{
F_238 ( V_383 -> V_384 , V_366 ,
sizeof( V_383 -> V_384 ) ) ;
F_238 ( V_383 -> V_385 , V_386 ,
sizeof( V_383 -> V_385 ) ) ;
F_238 ( V_383 -> V_387 , F_239 ( & V_19 -> V_19 ) ,
sizeof( V_383 -> V_387 ) ) ;
}
static void F_240 ( struct V_18 * V_388 ,
struct V_389 * V_390 )
{
struct V_1 * V_2 = F_9 ( V_388 ) ;
V_390 -> V_391 = V_392 ;
V_390 -> V_393 = V_394 ;
V_390 -> V_395 = V_2 -> V_316 ;
V_390 -> V_396 = V_2 -> V_321 ;
}
static int F_241 ( struct V_18 * V_19 ,
struct V_389 * V_390 )
{
struct V_1 * V_2 = F_9 ( V_19 ) ;
if ( ( V_390 -> V_395 == 0 ) || ( V_390 -> V_396 == 0 ) )
return - V_275 ;
V_2 -> V_316 = V_390 -> V_395 < V_392 ?
V_390 -> V_395 : V_392 ;
V_2 -> V_321 = F_242 ( T_7 , V_390 -> V_396 ,
V_322 * 2 , V_394 ) ;
if ( V_2 -> V_321 != V_390 -> V_396 )
F_36 ( V_19 , L_27 ,
V_2 -> V_321 , V_390 -> V_396 ) ;
if ( F_141 ( V_19 ) ) {
F_227 ( V_19 ) ;
if ( F_223 ( V_19 ) ) {
F_82 ( V_19 ,
L_28 ) ;
return - V_208 ;
}
}
return 0 ;
}
static void F_243 ( struct V_18 * V_388 , T_1 V_397 ,
T_3 * V_4 )
{
if ( V_397 == V_398 ) {
int V_11 ;
for ( V_11 = 0 ; V_11 < F_244 ( V_399 ) ; V_11 ++ )
memcpy ( V_4 + V_11 * V_400 ,
V_399 [ V_11 ] . V_401 , V_400 ) ;
}
}
static void F_245 ( struct V_1 * V_2 )
{
const struct V_402 * V_403 ;
void T_10 * V_5 = V_2 -> V_5 ;
T_1 V_404 , V_405 , V_41 ;
T_2 V_406 ;
int V_11 ;
for ( V_11 = 0 , V_403 = V_399 ;
V_403 < V_399 + F_244 ( V_399 ) ;
V_403 ++ , V_11 ++ ) {
switch ( V_403 -> type ) {
case V_407 :
V_41 = F_246 ( V_5 + V_403 -> V_3 ) ;
V_2 -> V_408 [ V_11 ] += V_41 ;
break;
case V_409 :
V_405 = F_246 ( V_5 + V_403 -> V_3 ) ;
V_404 = F_246 ( V_5 + V_403 -> V_3 + 4 ) ;
V_406 = ( T_2 ) V_404 << 32 | V_405 ;
V_2 -> V_408 [ V_11 ] += V_406 ;
break;
}
}
}
static void F_247 ( struct V_18 * V_19 ,
struct V_408 * V_20 , T_2 * V_4 )
{
struct V_1 * V_2 = F_9 ( V_19 ) ;
int V_11 ;
F_245 ( V_2 ) ;
for ( V_11 = 0 ; V_11 < F_244 ( V_399 ) ; V_11 ++ )
* V_4 ++ = V_2 -> V_408 [ V_11 ] ;
}
static int F_248 ( struct V_18 * V_19 , int V_397 )
{
if ( V_397 == V_398 )
return F_244 ( V_399 ) ;
return - V_410 ;
}
static T_1 F_249 ( struct V_18 * V_19 )
{
return V_411 ;
}
static int F_250 ( struct V_18 * V_19 ,
struct V_412 * V_413 ,
T_1 * T_11 V_414 )
{
switch ( V_413 -> V_371 ) {
case V_415 :
V_413 -> V_4 = V_68 ;
return 0 ;
case V_416 :
return - V_410 ;
default:
return - V_410 ;
}
}
static int F_251 ( struct V_1 * V_2 )
{
int V_22 ;
T_1 V_41 ;
F_194 ( V_2 -> V_19 ) ;
F_50 ( F_46 , V_2 , true ) ;
F_186 (cpu) {
struct V_221 * V_417 =
F_11 ( V_2 -> V_223 , V_22 ) ;
F_222 ( & V_417 -> V_233 ) ;
F_192 ( & V_417 -> V_233 ) ;
}
V_2 -> V_114 = V_2 -> V_418 [ 0 ] ;
F_155 ( V_2 -> V_19 ) ;
V_41 = F_57 ( V_2 -> V_114 ) ;
F_1 ( V_2 , V_122 , V_41 ) ;
F_220 ( & V_2 -> V_357 ) ;
F_215 ( V_2 ) ;
F_221 ( & V_2 -> V_357 ) ;
F_186 (cpu) {
struct V_221 * V_417 =
F_11 ( V_2 -> V_223 , V_22 ) ;
F_187 ( & V_417 -> V_233 ) ;
}
F_189 ( V_2 -> V_19 ) ;
return 0 ;
}
static int F_252 ( struct V_18 * V_19 , const T_1 * V_418 ,
const T_3 * V_419 , const T_3 V_420 )
{
struct V_1 * V_2 = F_9 ( V_19 ) ;
if ( V_419 ||
( V_420 != V_421 && V_420 != V_422 ) )
return - V_410 ;
if ( ! V_418 )
return 0 ;
memcpy ( V_2 -> V_418 , V_418 , V_411 ) ;
return F_251 ( V_2 ) ;
}
static int F_253 ( struct V_18 * V_19 , T_1 * V_418 , T_3 * V_419 ,
T_3 * V_420 )
{
struct V_1 * V_2 = F_9 ( V_19 ) ;
if ( V_420 )
* V_420 = V_422 ;
if ( ! V_418 )
return 0 ;
memcpy ( V_418 , V_2 -> V_418 , V_411 ) ;
return 0 ;
}
static int F_254 ( struct V_423 * V_19 , struct V_1 * V_2 )
{
int V_63 ;
F_40 ( V_2 ) ;
F_48 ( V_2 ) ;
V_2 -> V_66 = F_255 ( V_19 , V_65 , sizeof( struct V_6 ) ,
V_319 ) ;
if ( ! V_2 -> V_66 )
return - V_208 ;
for ( V_63 = 0 ; V_63 < V_65 ; V_63 ++ ) {
struct V_6 * V_7 = & V_2 -> V_66 [ V_63 ] ;
V_7 -> V_39 = V_63 ;
V_7 -> V_9 = V_2 -> V_321 ;
V_7 -> V_158 = V_424 ;
}
V_2 -> V_69 = F_255 ( V_19 , V_68 , sizeof( struct V_35 ) ,
V_319 ) ;
if ( ! V_2 -> V_69 )
return - V_208 ;
for ( V_63 = 0 ; V_63 < V_68 ; V_63 ++ ) {
struct V_35 * V_36 = & V_2 -> V_69 [ V_63 ] ;
V_36 -> V_39 = V_63 ;
V_36 -> V_9 = V_2 -> V_316 ;
V_36 -> V_153 = V_425 ;
V_36 -> V_156 = V_426 ;
}
return 0 ;
}
static void F_256 ( struct V_1 * V_2 ,
const struct V_427 * V_428 )
{
T_1 V_429 ;
T_1 V_430 ;
int V_11 ;
for ( V_11 = 0 ; V_11 < 6 ; V_11 ++ ) {
F_1 ( V_2 , F_257 ( V_11 ) , 0 ) ;
F_1 ( V_2 , F_258 ( V_11 ) , 0 ) ;
if ( V_11 < 4 )
F_1 ( V_2 , F_259 ( V_11 ) , 0 ) ;
}
V_429 = 0x3f ;
V_430 = 0 ;
for ( V_11 = 0 ; V_11 < V_428 -> V_431 ; V_11 ++ ) {
const struct V_432 * V_433 = V_428 -> V_433 + V_11 ;
F_1 ( V_2 , F_257 ( V_11 ) , ( V_433 -> V_5 & 0xffff0000 ) |
( V_433 -> V_434 << 8 ) | V_428 -> V_435 ) ;
F_1 ( V_2 , F_258 ( V_11 ) ,
( V_433 -> V_9 - 1 ) & 0xffff0000 ) ;
V_429 &= ~ ( 1 << V_11 ) ;
V_430 |= 3 << ( 2 * V_11 ) ;
}
F_1 ( V_2 , V_436 , V_429 ) ;
F_1 ( V_2 , V_437 , V_430 ) ;
}
static int F_260 ( struct V_1 * V_2 , int V_438 )
{
T_1 V_439 ;
F_1 ( V_2 , V_440 , 0 ) ;
V_439 = F_3 ( V_2 , V_97 ) ;
switch( V_438 ) {
case V_441 :
F_1 ( V_2 , V_442 , V_443 ) ;
V_439 |= V_444 | V_445 ;
break;
case V_446 :
F_1 ( V_2 , V_442 , V_447 ) ;
V_439 |= V_444 | V_445 ;
break;
case V_448 :
case V_449 :
V_439 |= V_445 ;
break;
default:
return - V_275 ;
}
V_439 &= ~ V_450 ;
F_1 ( V_2 , V_97 , V_439 ) ;
while ( ( F_3 ( V_2 , V_97 ) &
V_450 ) != 0 )
continue;
return 0 ;
}
static int F_261 ( struct V_451 * V_452 )
{
const struct V_427 * V_453 ;
struct V_454 * V_455 ;
struct V_456 * V_457 = V_452 -> V_19 . V_458 ;
struct V_456 * V_340 ;
struct V_1 * V_2 ;
struct V_18 * V_19 ;
const char * V_459 ;
char V_460 [ V_267 ] ;
const char * V_461 ;
const char * V_462 ;
int V_327 ;
int V_438 ;
int V_227 ;
int V_22 ;
V_19 = F_262 ( sizeof( struct V_1 ) , V_65 , V_68 ) ;
if ( ! V_19 )
return - V_208 ;
V_19 -> V_287 = F_263 ( V_457 , 0 ) ;
if ( V_19 -> V_287 == 0 ) {
V_227 = - V_275 ;
goto V_463;
}
V_340 = F_264 ( V_457 , L_29 , 0 ) ;
if ( ! V_340 ) {
if ( ! F_265 ( V_457 ) ) {
F_266 ( & V_452 -> V_19 , L_30 ) ;
V_227 = - V_342 ;
goto V_368;
}
V_227 = F_267 ( V_457 ) ;
if ( V_227 < 0 ) {
F_266 ( & V_452 -> V_19 , L_31 ) ;
goto V_368;
}
V_340 = F_268 ( V_457 ) ;
}
V_438 = F_269 ( V_457 ) ;
if ( V_438 < 0 ) {
F_266 ( & V_452 -> V_19 , L_32 ) ;
V_227 = - V_275 ;
goto V_464;
}
V_19 -> V_465 = V_394 ;
V_19 -> V_466 = 5 * V_467 ;
V_19 -> V_468 = & V_469 ;
V_19 -> V_470 = & V_471 ;
V_2 = F_9 ( V_19 ) ;
V_2 -> V_340 = V_340 ;
V_2 -> V_341 = V_438 ;
V_227 = F_270 ( V_457 , L_33 , & V_462 ) ;
V_2 -> V_133 = ( V_227 == 0 &&
strcmp ( V_462 , L_34 ) == 0 ) ;
V_2 -> V_353 . V_472 = F_218 ;
V_2 -> V_114 = V_114 ;
V_2 -> V_418 [ 0 ] = V_114 ;
V_2 -> V_155 = F_271 ( & V_452 -> V_19 , L_35 ) ;
if ( F_272 ( V_2 -> V_155 ) )
V_2 -> V_155 = F_271 ( & V_452 -> V_19 , NULL ) ;
if ( F_272 ( V_2 -> V_155 ) ) {
V_227 = F_273 ( V_2 -> V_155 ) ;
goto V_464;
}
F_274 ( V_2 -> V_155 ) ;
V_2 -> V_473 = F_271 ( & V_452 -> V_19 , L_36 ) ;
if ( ! F_272 ( V_2 -> V_473 ) )
F_274 ( V_2 -> V_473 ) ;
V_455 = F_275 ( V_452 , V_474 , 0 ) ;
V_2 -> V_5 = F_276 ( & V_452 -> V_19 , V_455 ) ;
if ( F_272 ( V_2 -> V_5 ) ) {
V_227 = F_273 ( V_2 -> V_5 ) ;
goto V_475;
}
V_2 -> V_223 = F_277 ( struct V_221 ) ;
if ( ! V_2 -> V_223 ) {
V_227 = - V_208 ;
goto V_475;
}
V_2 -> V_20 = F_278 ( struct V_23 ) ;
if ( ! V_2 -> V_20 ) {
V_227 = - V_208 ;
goto V_476;
}
V_459 = F_279 ( V_457 ) ;
if ( V_459 ) {
V_461 = L_37 ;
memcpy ( V_19 -> V_285 , V_459 , V_267 ) ;
} else {
F_203 ( V_2 , V_460 ) ;
if ( F_280 ( V_460 ) ) {
V_461 = L_38 ;
memcpy ( V_19 -> V_285 , V_460 , V_267 ) ;
} else {
V_461 = L_39 ;
F_281 ( V_19 ) ;
}
}
if ( ! F_282 ( V_457 , L_40 , & V_327 ) ) {
if ( V_327 < 0 ||
V_327 > V_477 ) {
V_327 = V_478 ;
F_283 ( & V_452 -> V_19 ,
L_41 ,
V_478 ) ;
}
} else if ( F_284 ( V_457 , L_42 ) ) {
V_327 = V_478 ;
} else {
V_327 = V_477 ;
}
V_2 -> V_327 = V_327 ;
V_2 -> V_321 = V_394 ;
V_2 -> V_316 = V_392 ;
V_2 -> V_19 = V_19 ;
F_285 ( V_19 , & V_452 -> V_19 ) ;
V_227 = F_254 ( & V_452 -> V_19 , V_2 ) ;
if ( V_227 < 0 )
goto V_479;
V_227 = F_260 ( V_2 , V_438 ) ;
if ( V_227 < 0 ) {
F_266 ( & V_452 -> V_19 , L_43 ) ;
goto V_479;
}
V_453 = F_286 () ;
if ( V_453 )
F_256 ( V_2 , V_453 ) ;
F_51 (cpu) {
struct V_221 * V_222 = F_11 ( V_2 -> V_223 , V_22 ) ;
F_287 ( V_19 , & V_222 -> V_233 , F_163 , V_480 ) ;
V_222 -> V_2 = V_2 ;
}
V_19 -> V_326 = V_481 | V_328 | V_329 ;
V_19 -> V_482 |= V_19 -> V_326 ;
V_19 -> V_483 |= V_19 -> V_326 ;
V_19 -> V_484 |= V_485 ;
V_19 -> V_486 = V_487 ;
V_227 = F_288 ( V_19 ) ;
if ( V_227 < 0 ) {
F_266 ( & V_452 -> V_19 , L_44 ) ;
goto V_479;
}
F_153 ( V_19 , L_45 , V_461 ,
V_19 -> V_285 ) ;
F_289 ( V_452 , V_2 -> V_19 ) ;
if ( V_2 -> V_133 ) {
struct V_290 * V_291 = F_290 ( V_457 ) ;
F_161 ( V_2 , V_291 ) ;
F_291 ( & V_291 -> V_488 . V_19 ) ;
}
return 0 ;
V_479:
F_292 ( V_2 -> V_20 ) ;
V_476:
F_292 ( V_2 -> V_223 ) ;
V_475:
F_293 ( V_2 -> V_473 ) ;
F_293 ( V_2 -> V_155 ) ;
V_464:
F_294 ( V_340 ) ;
V_368:
F_295 ( V_19 -> V_287 ) ;
V_463:
F_296 ( V_19 ) ;
return V_227 ;
}
static int F_297 ( struct V_451 * V_452 )
{
struct V_18 * V_19 = F_298 ( V_452 ) ;
struct V_1 * V_2 = F_9 ( V_19 ) ;
F_299 ( V_19 ) ;
F_293 ( V_2 -> V_473 ) ;
F_293 ( V_2 -> V_155 ) ;
F_292 ( V_2 -> V_223 ) ;
F_292 ( V_2 -> V_20 ) ;
F_295 ( V_19 -> V_287 ) ;
F_294 ( V_2 -> V_340 ) ;
F_296 ( V_19 ) ;
return 0 ;
}
