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
F_1 ( V_2 , V_68 , F_35 ( V_69 ) ) ;
}
static void F_36 ( struct V_1 * V_2 )
{
T_1 V_41 ;
int V_70 ;
V_41 = F_3 ( V_2 , V_68 ) & V_71 ;
if ( V_41 != 0 )
F_1 ( V_2 , V_68 ,
V_41 << V_72 ) ;
V_70 = 0 ;
do {
if ( V_70 ++ >= V_73 ) {
F_37 ( V_2 -> V_19 ,
L_1 ,
V_41 ) ;
break;
}
F_38 ( 1 ) ;
V_41 = F_3 ( V_2 , V_68 ) ;
} while ( V_41 & 0xff );
V_41 = ( F_3 ( V_2 , V_67 ) ) & V_74 ;
if ( V_41 != 0 )
F_1 ( V_2 , V_67 ,
( V_41 << V_75 ) ) ;
V_70 = 0 ;
do {
if ( V_70 ++ >= V_76 ) {
F_37 ( V_2 -> V_19 ,
L_2 ,
V_41 ) ;
break;
}
F_38 ( 1 ) ;
V_41 = F_3 ( V_2 , V_67 ) ;
} while ( V_41 & 0xff );
V_70 = 0 ;
do {
if ( V_70 ++ >= V_77 ) {
F_37 ( V_2 -> V_19 ,
L_3 ,
V_41 ) ;
break;
}
F_38 ( 1 ) ;
V_41 = F_3 ( V_2 , V_78 ) ;
} while ( ! ( V_41 & V_79 ) &&
( V_41 & V_80 ) );
F_39 ( 200 ) ;
}
static void F_40 ( struct V_1 * V_2 )
{
T_1 V_41 ;
V_41 = F_3 ( V_2 , V_50 ) ;
V_41 |= V_81 ;
F_1 ( V_2 , V_50 , V_41 ) ;
}
static void F_41 ( struct V_1 * V_2 )
{
T_1 V_41 ;
V_41 = F_3 ( V_2 , V_50 ) ;
V_41 &= ~ V_81 ;
F_1 ( V_2 , V_50 , V_41 ) ;
F_39 ( 200 ) ;
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
for ( V_3 = 0 ; V_3 <= 0xc ; V_3 += 4 )
F_1 ( V_2 , V_82 + V_3 , V_41 ) ;
}
static void F_43 ( struct V_1 * V_2 , int V_63 )
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
F_1 ( V_2 , V_83 + V_3 , V_41 ) ;
}
static void F_44 ( struct V_1 * V_2 , int V_63 )
{
int V_3 ;
T_1 V_41 ;
if ( V_63 == - 1 ) {
memset ( V_2 -> V_84 , 0 , sizeof( V_2 -> V_84 ) ) ;
V_41 = 0 ;
} else {
memset ( V_2 -> V_84 , 1 , sizeof( V_2 -> V_84 ) ) ;
V_41 = 0x1 | ( V_63 << 1 ) ;
V_41 |= ( V_41 << 24 ) | ( V_41 << 16 ) | ( V_41 << 8 ) ;
}
for ( V_3 = 0 ; V_3 <= 0xfc ; V_3 += 4 )
F_1 ( V_2 , V_85 + V_3 , V_41 ) ;
}
static void F_45 ( struct V_1 * V_2 )
{
int V_22 ;
int V_63 ;
T_1 V_41 ;
F_1 ( V_2 , V_86 , 0 ) ;
F_1 ( V_2 , V_87 , 0 ) ;
F_1 ( V_2 , V_88 , 0 ) ;
F_1 ( V_2 , V_89 , 0 ) ;
F_1 ( V_2 , V_90 , 0 ) ;
F_1 ( V_2 , V_91 , 0 ) ;
F_1 ( V_2 , V_92 , 0 ) ;
F_1 ( V_2 , V_93 , 0x20 ) ;
F_46 (cpu)
F_1 ( V_2 , F_47 ( V_22 ) ,
( V_94 |
V_95 ) ) ;
F_1 ( V_2 , V_96 , V_97 ) ;
F_1 ( V_2 , V_98 , V_99 ) ;
F_1 ( V_2 , V_100 , 0 ) ;
for ( V_63 = 0 ; V_63 < V_65 ; V_63 ++ ) {
F_1 ( V_2 , F_48 ( V_63 ) , 0 ) ;
F_1 ( V_2 , F_49 ( V_63 ) , 0 ) ;
}
F_1 ( V_2 , V_98 , 0 ) ;
F_1 ( V_2 , V_96 , 0 ) ;
V_41 = V_101 ;
F_1 ( V_2 , V_102 , V_41 ) ;
V_41 = F_50 ( V_69 ) ;
F_1 ( V_2 , V_103 , V_41 ) ;
V_41 = 0 ;
F_1 ( V_2 , V_104 , V_41 ) ;
F_1 ( V_2 , V_105 , 64 ) ;
V_41 = 0 ;
V_41 |= F_51 ( V_106 ) ;
V_41 |= F_52 ( V_106 ) ;
V_41 |= V_107 | V_108 ;
#if F_53 ( V_109 )
V_41 |= V_110 ;
#endif
F_1 ( V_2 , V_111 , V_41 ) ;
V_41 = F_3 ( V_2 , V_112 ) ;
V_41 &= ~ V_113 ;
F_1 ( V_2 , V_112 , V_41 ) ;
if ( V_2 -> V_114 ) {
V_41 = F_3 ( V_2 , V_115 ) ;
V_41 &= ~ ( V_116 |
V_117 |
V_118 ) ;
V_41 |= V_119 |
V_120 |
V_121 ;
F_1 ( V_2 , V_115 , V_41 ) ;
V_41 = F_3 ( V_2 , V_122 ) ;
V_41 |= V_123 ;
F_1 ( V_2 , V_122 , V_41 ) ;
} else {
V_41 = F_3 ( V_2 , V_115 ) ;
V_41 &= ~ ( V_119 |
V_120 |
V_121 ) ;
F_1 ( V_2 , V_115 , V_41 ) ;
}
F_42 ( V_2 , - 1 ) ;
F_43 ( V_2 , - 1 ) ;
F_44 ( V_2 , - 1 ) ;
F_1 ( V_2 , V_92 ,
( V_124
| V_125 ) ) ;
F_7 ( V_2 ) ;
}
static void F_54 ( struct V_1 * V_2 , int V_126 )
{
T_1 V_41 , V_9 , V_127 ;
int V_63 ;
V_127 = V_126 * 8 ;
if ( V_127 > V_128 )
V_127 = V_128 ;
V_41 = F_3 ( V_2 , V_129 ) ;
V_41 &= ~ V_128 ;
V_41 |= V_127 ;
F_1 ( V_2 , V_129 , V_41 ) ;
V_41 = F_3 ( V_2 , V_130 ) ;
V_9 = V_41 & V_131 ;
if ( V_9 < V_127 ) {
V_9 = V_127 ;
V_41 &= ~ V_131 ;
V_41 |= V_9 ;
F_1 ( V_2 , V_130 , V_41 ) ;
}
for ( V_63 = 0 ; V_63 < V_65 ; V_63 ++ ) {
V_41 = F_3 ( V_2 , F_55 ( V_63 ) ) ;
V_9 = V_41 & V_132 ;
if ( V_9 < V_127 ) {
V_9 = V_127 ;
V_41 &= ~ V_132 ;
V_41 |= V_9 ;
F_1 ( V_2 , F_55 ( V_63 ) , V_41 ) ;
}
}
}
static void F_56 ( struct V_1 * V_2 , T_3 V_133 ,
int V_63 )
{
unsigned int V_134 ;
unsigned int V_135 ;
unsigned int V_136 ;
V_133 = ( 0xf & V_133 ) ;
V_135 = ( V_133 / 4 ) * 4 ;
V_136 = V_133 % 4 ;
V_134 = F_3 ( V_2 , ( V_82 + V_135 ) ) ;
if ( V_63 == - 1 ) {
V_134 &= ~ ( 0xff << ( 8 * V_136 ) ) ;
} else {
V_134 &= ~ ( 0xff << ( 8 * V_136 ) ) ;
V_134 |= ( ( 0x01 | ( V_63 << 1 ) ) << ( 8 * V_136 ) ) ;
}
F_1 ( V_2 , ( V_82 + V_135 ) , V_134 ) ;
}
static void F_57 ( struct V_1 * V_2 , unsigned char * V_137 ,
int V_63 )
{
unsigned int V_138 ;
unsigned int V_139 ;
if ( V_63 != - 1 ) {
V_139 = ( V_137 [ 4 ] << 8 ) | ( V_137 [ 5 ] ) ;
V_138 = ( V_137 [ 0 ] << 24 ) | ( V_137 [ 1 ] << 16 ) |
( V_137 [ 2 ] << 8 ) | ( V_137 [ 3 ] << 0 ) ;
F_1 ( V_2 , V_140 , V_139 ) ;
F_1 ( V_2 , V_141 , V_138 ) ;
}
F_56 ( V_2 , V_137 [ 5 ] , V_63 ) ;
}
static void F_58 ( struct V_1 * V_2 ,
struct V_35 * V_36 , T_1 V_142 )
{
F_1 ( V_2 , F_59 ( V_36 -> V_39 ) ,
V_142 | F_60 ( 0 ) ) ;
V_36 -> V_143 = V_142 ;
}
static void F_61 ( struct V_1 * V_2 ,
struct V_35 * V_36 , T_1 V_142 )
{
T_1 V_41 ;
unsigned long V_144 ;
V_144 = F_62 ( V_2 -> V_145 ) ;
V_41 = ( V_144 / 1000000 ) * V_142 ;
F_1 ( V_2 , F_63 ( V_36 -> V_39 ) , V_41 ) ;
V_36 -> V_146 = V_142 ;
}
static void F_64 ( struct V_1 * V_2 ,
struct V_6 * V_7 , T_1 V_142 )
{
T_1 V_41 ;
V_41 = F_3 ( V_2 , F_65 ( V_7 -> V_39 ) ) ;
V_41 &= ~ V_147 ;
V_41 |= F_66 ( V_142 ) ;
F_1 ( V_2 , F_65 ( V_7 -> V_39 ) , V_41 ) ;
V_7 -> V_148 = V_142 ;
}
static void F_67 ( struct V_45 * V_46 ,
T_1 V_149 , T_1 V_150 )
{
V_46 -> V_151 = V_150 ;
V_46 -> V_152 = V_149 ;
}
static void F_68 ( struct V_1 * V_2 ,
struct V_6 * V_7 ,
int V_153 )
{
T_1 V_41 ;
while ( V_153 > 0xff ) {
V_41 = 0xff << V_154 ;
F_1 ( V_2 , F_28 ( V_7 -> V_39 ) , V_41 ) ;
V_153 = V_153 - 0xff ;
}
V_41 = V_153 << V_154 ;
F_1 ( V_2 , F_28 ( V_7 -> V_39 ) , V_41 ) ;
}
static int F_69 ( struct V_1 * V_2 ,
struct V_6 * V_7 )
{
T_1 V_41 ;
int V_153 ;
V_41 = F_3 ( V_2 , F_70 ( V_7 -> V_39 ) ) ;
V_153 = ( V_41 & V_155 ) >>
V_156 ;
return V_153 ;
}
static int F_71 ( struct V_1 * V_2 ,
struct V_6 * V_7 )
{
int V_153 ;
V_153 = F_69 ( V_2 , V_7 ) ;
if ( V_153 )
F_68 ( V_2 , V_7 , V_153 ) ;
return V_153 ;
}
static T_1 F_72 ( int V_157 , int V_158 ,
int V_159 , int V_160 )
{
T_1 V_161 ;
V_161 = V_157 << V_162 ;
V_161 |= V_159 << V_163 ;
if ( V_158 == F_73 ( V_164 ) )
V_161 |= V_165 ;
else
V_161 |= V_166 ;
if ( V_160 == V_167 )
V_161 |= V_168 ;
else if ( V_160 == V_169 )
V_161 |= V_170 | V_168 ;
else
V_161 |= V_171 ;
return V_161 ;
}
static void F_74 ( struct V_1 * V_2 ,
struct V_45 * V_46 )
{
T_1 V_33 = V_46 -> V_33 ;
if ( ! F_14 ( V_33 ) ) {
F_75 ( V_2 -> V_19 ,
L_4 ,
V_33 , V_46 -> V_172 ) ;
return;
}
switch ( V_33 & V_173 ) {
case V_174 :
F_75 ( V_2 -> V_19 , L_5 ,
V_33 , V_46 -> V_172 ) ;
break;
case V_175 :
F_75 ( V_2 -> V_19 , L_6 ,
V_33 , V_46 -> V_172 ) ;
break;
case V_176 :
F_75 ( V_2 -> V_19 , L_7 ,
V_33 , V_46 -> V_172 ) ;
break;
case V_177 :
F_75 ( V_2 -> V_19 , L_8 ,
V_33 , V_46 -> V_172 ) ;
break;
}
}
static void F_76 ( struct V_1 * V_2 , T_1 V_33 ,
struct V_178 * V_179 )
{
if ( ( V_33 & V_180 ) &&
( V_33 & V_181 ) ) {
V_179 -> V_182 = 0 ;
V_179 -> V_183 = V_184 ;
return;
}
V_179 -> V_183 = V_185 ;
}
static struct V_6 * F_77 ( struct V_1 * V_2 ,
T_1 V_186 )
{
int V_63 = F_78 ( V_186 ) - 1 ;
return & V_2 -> V_66 [ V_63 ] ;
}
static void F_79 ( struct V_1 * V_2 ,
struct V_6 * V_7 , int V_187 )
{
int V_11 ;
for ( V_11 = 0 ; V_11 < V_187 ; V_11 ++ ) {
struct V_56 * V_57 = V_7 -> V_48 +
V_7 -> V_8 ;
struct V_178 * V_179 = V_7 -> V_188 [ V_7 -> V_8 ] ;
F_5 ( V_7 ) ;
if ( ! F_80 ( V_7 , V_57 -> V_152 ) )
F_81 ( V_2 -> V_19 -> V_19 . V_189 ,
V_57 -> V_152 ,
V_57 -> V_172 , V_190 ) ;
if ( ! V_179 )
continue;
F_82 ( V_179 ) ;
}
}
static void F_83 ( struct V_1 * V_2 ,
struct V_6 * V_7 )
{
struct V_191 * V_192 = F_84 ( V_2 -> V_19 , V_7 -> V_39 ) ;
int V_193 ;
V_193 = F_71 ( V_2 , V_7 ) ;
if ( ! V_193 )
return;
F_79 ( V_2 , V_7 , V_193 ) ;
V_7 -> V_70 -= V_193 ;
if ( F_85 ( V_192 ) ) {
if ( V_7 -> V_70 <= V_7 -> V_194 )
F_86 ( V_192 ) ;
}
}
static void * F_87 ( const struct V_1 * V_2 )
{
if ( F_88 ( V_2 -> V_195 <= V_196 ) )
return F_89 ( V_2 -> V_195 ) ;
else
return F_90 ( V_2 -> V_195 , V_197 ) ;
}
static void F_91 ( const struct V_1 * V_2 , void * V_4 )
{
if ( F_88 ( V_2 -> V_195 <= V_196 ) )
F_92 ( V_4 ) ;
else
F_93 ( V_4 ) ;
}
static int F_94 ( struct V_1 * V_2 ,
struct V_45 * V_46 )
{
T_4 V_149 ;
void * V_4 ;
V_4 = F_87 ( V_2 ) ;
if ( ! V_4 )
return - V_198 ;
V_149 = F_95 ( V_2 -> V_19 -> V_19 . V_189 , V_4 ,
F_96 ( V_2 -> V_199 ) ,
V_200 ) ;
if ( F_97 ( F_98 ( V_2 -> V_19 -> V_19 . V_189 , V_149 ) ) ) {
F_91 ( V_2 , V_4 ) ;
return - V_198 ;
}
F_67 ( V_46 , V_149 , ( T_1 ) V_4 ) ;
return 0 ;
}
static T_1 F_99 ( struct V_1 * V_2 , struct V_178 * V_179 )
{
if ( V_179 -> V_183 == V_201 ) {
int V_159 = 0 ;
T_5 V_158 = F_100 ( V_179 ) ;
T_3 V_160 ;
if ( V_158 == F_73 ( V_164 ) ) {
struct V_202 * V_203 = F_101 ( V_179 ) ;
V_159 = V_203 -> V_204 ;
V_160 = V_203 -> V_205 ;
} else if ( V_158 == F_73 ( V_206 ) ) {
struct V_207 * V_208 = F_102 ( V_179 ) ;
if ( F_103 ( V_179 ) > 0 )
V_159 = ( F_103 ( V_179 ) >> 2 ) ;
V_160 = V_208 -> V_209 ;
} else
return V_171 ;
return F_72 ( F_104 ( V_179 ) ,
V_158 , V_159 , V_160 ) ;
}
return V_171 ;
}
static void F_105 ( struct V_1 * V_2 ,
struct V_35 * V_36 )
{
int V_43 , V_11 ;
V_43 = F_17 ( V_2 , V_36 ) ;
for ( V_11 = 0 ; V_11 < V_36 -> V_9 ; V_11 ++ ) {
struct V_45 * V_46 = V_36 -> V_48 + V_11 ;
void * V_4 = ( void * ) V_46 -> V_151 ;
F_81 ( V_2 -> V_19 -> V_19 . V_189 , V_46 -> V_152 ,
F_96 ( V_2 -> V_199 ) , V_200 ) ;
F_91 ( V_2 , V_4 ) ;
}
if ( V_43 )
F_19 ( V_2 , V_36 , V_43 , V_43 ) ;
}
static int F_106 ( struct V_1 * V_2 , int V_210 ,
struct V_35 * V_36 )
{
struct V_211 * V_212 = F_107 ( V_2 -> V_213 ) ;
struct V_18 * V_19 = V_2 -> V_19 ;
int V_43 ;
T_1 V_214 = 0 ;
T_1 V_215 = 0 ;
V_43 = F_17 ( V_2 , V_36 ) ;
if ( V_210 > V_43 )
V_210 = V_43 ;
V_43 = 0 ;
while ( V_43 < V_210 ) {
struct V_45 * V_46 = F_20 ( V_36 ) ;
struct V_178 * V_179 ;
unsigned char * V_4 ;
T_4 V_149 ;
T_1 V_216 ;
int V_26 , V_217 ;
V_43 ++ ;
V_216 = V_46 -> V_33 ;
V_26 = V_46 -> V_172 - ( V_218 + V_52 ) ;
V_4 = ( unsigned char * ) V_46 -> V_151 ;
V_149 = V_46 -> V_152 ;
if ( ! F_14 ( V_216 ) ||
( V_216 & V_219 ) ) {
V_220:
V_19 -> V_20 . V_30 ++ ;
F_74 ( V_2 , V_46 ) ;
continue;
}
if ( V_26 <= V_221 ) {
V_179 = F_108 ( V_19 , V_26 ) ;
if ( F_97 ( ! V_179 ) )
goto V_220;
F_109 ( V_19 -> V_19 . V_189 ,
V_46 -> V_152 ,
V_52 + V_222 ,
V_26 ,
V_200 ) ;
memcpy ( F_110 ( V_179 , V_26 ) ,
V_4 + V_52 + V_222 ,
V_26 ) ;
V_179 -> V_205 = F_111 ( V_179 , V_19 ) ;
F_76 ( V_2 , V_216 , V_179 ) ;
F_112 ( & V_212 -> V_223 , V_179 ) ;
V_214 ++ ;
V_215 += V_26 ;
continue;
}
V_217 = F_94 ( V_2 , V_46 ) ;
if ( V_217 ) {
F_75 ( V_19 , L_9 ) ;
V_36 -> V_224 ++ ;
goto V_220;
}
V_179 = F_113 ( V_4 , V_2 -> V_195 > V_196 ? 0 : V_2 -> V_195 ) ;
F_81 ( V_19 -> V_19 . V_189 , V_149 ,
F_96 ( V_2 -> V_199 ) , V_200 ) ;
if ( ! V_179 )
goto V_220;
V_214 ++ ;
V_215 += V_26 ;
F_114 ( V_179 , V_52 + V_222 ) ;
F_110 ( V_179 , V_26 ) ;
V_179 -> V_205 = F_111 ( V_179 , V_19 ) ;
F_76 ( V_2 , V_216 , V_179 ) ;
F_112 ( & V_212 -> V_223 , V_179 ) ;
}
if ( V_214 ) {
struct V_23 * V_20 = F_107 ( V_2 -> V_20 ) ;
F_115 ( & V_20 -> V_29 ) ;
V_20 -> V_25 += V_214 ;
V_20 -> V_26 += V_215 ;
F_116 ( & V_20 -> V_29 ) ;
}
F_19 ( V_2 , V_36 , V_43 , V_43 ) ;
return V_43 ;
}
static inline void
F_117 ( struct V_178 * V_179 ,
struct V_1 * V_2 , struct V_6 * V_7 )
{
struct V_56 * V_57 ;
int V_225 = F_118 ( V_179 ) + F_119 ( V_179 ) ;
V_7 -> V_188 [ V_7 -> V_10 ] = NULL ;
V_57 = F_29 ( V_7 ) ;
V_57 -> V_172 = V_225 ;
V_57 -> V_161 = F_99 ( V_2 , V_179 ) ;
V_57 -> V_161 |= V_226 ;
V_57 -> V_152 = V_7 -> V_227 +
V_7 -> V_10 * V_228 ;
F_6 ( V_7 ) ;
}
static inline int
F_120 ( struct V_18 * V_19 , struct V_6 * V_7 ,
struct V_178 * V_179 , char * V_4 , int V_9 ,
bool V_229 , bool V_230 )
{
struct V_56 * V_57 ;
V_57 = F_29 ( V_7 ) ;
V_57 -> V_172 = V_9 ;
V_57 -> V_152 = F_95 ( V_19 -> V_19 . V_189 , V_4 ,
V_9 , V_190 ) ;
if ( F_97 ( F_98 ( V_19 -> V_19 . V_189 ,
V_57 -> V_152 ) ) ) {
F_30 ( V_7 ) ;
return - V_198 ;
}
V_57 -> V_161 = 0 ;
V_7 -> V_188 [ V_7 -> V_10 ] = NULL ;
if ( V_229 ) {
V_57 -> V_161 = V_231 ;
if ( V_230 )
V_7 -> V_188 [ V_7 -> V_10 ] = V_179 ;
}
F_6 ( V_7 ) ;
return 0 ;
}
static int F_121 ( struct V_178 * V_179 , struct V_18 * V_19 ,
struct V_6 * V_7 )
{
int V_232 , V_233 ;
int V_234 = 0 ;
struct V_1 * V_2 = F_9 ( V_19 ) ;
struct V_235 V_236 ;
int V_225 = F_118 ( V_179 ) + F_119 ( V_179 ) ;
int V_11 ;
if ( ( V_7 -> V_70 + F_122 ( V_179 ) ) >= V_7 -> V_9 )
return 0 ;
if ( F_123 ( V_179 ) < ( F_118 ( V_179 ) + F_119 ( V_179 ) ) ) {
F_124 ( L_10 ) ;
return 0 ;
}
F_125 ( V_179 , & V_236 ) ;
V_232 = V_179 -> V_237 - V_225 ;
while ( V_232 > 0 ) {
char * V_238 ;
V_233 = F_126 ( int , F_127 ( V_179 ) -> V_239 , V_232 ) ;
V_232 -= V_233 ;
V_234 ++ ;
V_238 = V_7 -> V_240 + V_7 -> V_10 * V_228 ;
F_128 ( V_179 , V_238 , & V_236 , V_233 , V_232 == 0 ) ;
F_117 ( V_179 , V_2 , V_7 ) ;
while ( V_233 > 0 ) {
int V_9 ;
V_234 ++ ;
V_9 = F_126 ( int , V_236 . V_9 , V_233 ) ;
if ( F_120 ( V_19 , V_7 , V_179 ,
V_236 . V_4 , V_9 ,
V_9 == V_233 ,
V_232 == 0 ) )
goto V_241;
V_233 -= V_9 ;
F_129 ( V_179 , & V_236 , V_9 ) ;
}
}
return V_234 ;
V_241:
for ( V_11 = V_234 - 1 ; V_11 >= 0 ; V_11 -- ) {
struct V_56 * V_57 = V_7 -> V_48 + V_11 ;
if ( ! F_80 ( V_7 , V_57 -> V_152 ) )
F_81 ( V_2 -> V_19 -> V_19 . V_189 ,
V_57 -> V_152 ,
V_57 -> V_172 ,
V_190 ) ;
F_30 ( V_7 ) ;
}
return 0 ;
}
static int F_130 ( struct V_1 * V_2 , struct V_178 * V_179 ,
struct V_6 * V_7 )
{
struct V_56 * V_57 ;
int V_11 , V_242 = F_127 ( V_179 ) -> V_242 ;
for ( V_11 = 0 ; V_11 < V_242 ; V_11 ++ ) {
T_6 * V_243 = & F_127 ( V_179 ) -> V_244 [ V_11 ] ;
void * V_137 = F_131 ( V_243 -> V_245 . V_246 ) + V_243 -> V_247 ;
V_57 = F_29 ( V_7 ) ;
V_57 -> V_172 = V_243 -> V_9 ;
V_57 -> V_152 =
F_95 ( V_2 -> V_19 -> V_19 . V_189 , V_137 ,
V_57 -> V_172 , V_190 ) ;
if ( F_98 ( V_2 -> V_19 -> V_19 . V_189 ,
V_57 -> V_152 ) ) {
F_30 ( V_7 ) ;
goto error;
}
if ( V_11 == V_242 - 1 ) {
V_57 -> V_161 = V_231 | V_248 ;
V_7 -> V_188 [ V_7 -> V_10 ] = V_179 ;
} else {
V_57 -> V_161 = 0 ;
V_7 -> V_188 [ V_7 -> V_10 ] = NULL ;
}
F_6 ( V_7 ) ;
}
return 0 ;
error:
for ( V_11 = V_11 - 1 ; V_11 >= 0 ; V_11 -- ) {
V_57 = V_7 -> V_48 + V_11 ;
F_81 ( V_2 -> V_19 -> V_19 . V_189 ,
V_57 -> V_152 ,
V_57 -> V_172 ,
V_190 ) ;
F_30 ( V_7 ) ;
}
return - V_198 ;
}
static int F_132 ( struct V_178 * V_179 , struct V_18 * V_19 )
{
struct V_1 * V_2 = F_9 ( V_19 ) ;
T_7 V_249 = F_133 ( V_179 ) ;
struct V_6 * V_7 = & V_2 -> V_66 [ V_249 ] ;
struct V_56 * V_57 ;
int V_237 = V_179 -> V_237 ;
int V_244 = 0 ;
T_1 V_250 ;
if ( ! F_134 ( V_19 ) )
goto V_251;
if ( F_135 ( V_179 ) ) {
V_244 = F_121 ( V_179 , V_19 , V_7 ) ;
goto V_251;
}
V_244 = F_127 ( V_179 ) -> V_242 + 1 ;
V_57 = F_29 ( V_7 ) ;
V_250 = F_99 ( V_2 , V_179 ) ;
V_57 -> V_172 = F_123 ( V_179 ) ;
V_57 -> V_152 = F_95 ( V_19 -> V_19 . V_189 , V_179 -> V_4 ,
V_57 -> V_172 ,
V_190 ) ;
if ( F_97 ( F_98 ( V_19 -> V_19 . V_189 ,
V_57 -> V_152 ) ) ) {
F_30 ( V_7 ) ;
V_244 = 0 ;
goto V_251;
}
if ( V_244 == 1 ) {
V_250 |= V_252 ;
V_57 -> V_161 = V_250 ;
V_7 -> V_188 [ V_7 -> V_10 ] = V_179 ;
F_6 ( V_7 ) ;
} else {
V_250 |= V_226 ;
V_7 -> V_188 [ V_7 -> V_10 ] = NULL ;
F_6 ( V_7 ) ;
V_57 -> V_161 = V_250 ;
if ( F_130 ( V_2 , V_179 , V_7 ) ) {
F_81 ( V_19 -> V_19 . V_189 ,
V_57 -> V_152 ,
V_57 -> V_172 ,
V_190 ) ;
F_30 ( V_7 ) ;
V_244 = 0 ;
goto V_251;
}
}
V_251:
if ( V_244 > 0 ) {
struct V_23 * V_20 = F_107 ( V_2 -> V_20 ) ;
struct V_191 * V_192 = F_84 ( V_19 , V_249 ) ;
V_7 -> V_70 += V_244 ;
F_27 ( V_2 , V_7 , V_244 ) ;
if ( V_7 -> V_70 >= V_7 -> V_253 )
F_136 ( V_192 ) ;
F_115 ( & V_20 -> V_29 ) ;
V_20 -> V_27 ++ ;
V_20 -> V_28 += V_237 ;
F_116 ( & V_20 -> V_29 ) ;
} else {
V_19 -> V_20 . V_32 ++ ;
F_82 ( V_179 ) ;
}
return V_254 ;
}
static void F_137 ( struct V_1 * V_2 ,
struct V_6 * V_7 )
{
int V_193 = V_7 -> V_70 ;
F_79 ( V_2 , V_7 , V_193 ) ;
V_7 -> V_70 = 0 ;
V_7 -> V_10 = 0 ;
V_7 -> V_8 = 0 ;
}
static void F_138 ( struct V_1 * V_2 , T_1 V_255 )
{
struct V_6 * V_7 ;
struct V_191 * V_192 ;
while ( V_255 ) {
V_7 = F_77 ( V_2 , V_255 ) ;
V_192 = F_84 ( V_2 -> V_19 , V_7 -> V_39 ) ;
F_139 ( V_192 , F_140 () ) ;
if ( V_7 -> V_70 )
F_83 ( V_2 , V_7 ) ;
F_141 ( V_192 ) ;
V_255 &= ~ ( ( 1 << V_7 -> V_39 ) ) ;
}
}
static int F_142 ( unsigned char * V_137 )
{
int V_256 = 0 ;
int V_11 ;
for ( V_11 = 0 ; V_11 < V_257 ; V_11 ++ ) {
int V_258 ;
V_256 = ( V_256 ^ V_137 [ V_11 ] ) << 8 ;
for ( V_258 = 7 ; V_258 >= 0 ; V_258 -- ) {
if ( V_256 & ( 0x100 << V_258 ) )
V_256 ^= 0x107 << V_258 ;
}
}
return V_256 ;
}
static void F_143 ( struct V_1 * V_2 ,
unsigned char V_259 ,
int V_63 )
{
unsigned int V_260 ;
unsigned int V_135 ;
unsigned int V_136 ;
V_135 = ( V_259 / 4 ) ;
V_136 = V_259 % 4 ;
V_260 = F_3 ( V_2 , ( V_83
+ V_135 * 4 ) ) ;
if ( V_63 == - 1 )
V_260 &= ~ ( 0xff << ( 8 * V_136 ) ) ;
else {
V_260 &= ~ ( 0xff << ( 8 * V_136 ) ) ;
V_260 |= ( ( 0x01 | ( V_63 << 1 ) ) << ( 8 * V_136 ) ) ;
}
F_1 ( V_2 , V_83 + V_135 * 4 ,
V_260 ) ;
}
static void F_144 ( struct V_1 * V_2 ,
unsigned char V_261 ,
int V_63 )
{
unsigned int V_262 ;
unsigned int V_135 ;
unsigned int V_136 ;
V_135 = ( V_261 / 4 ) * 4 ;
V_136 = V_261 % 4 ;
V_262 = F_3 ( V_2 , V_85 + V_135 ) ;
if ( V_63 == - 1 ) {
V_262 &= ~ ( 0xff << ( 8 * V_136 ) ) ;
} else {
V_262 &= ~ ( 0xff << ( 8 * V_136 ) ) ;
V_262 |= ( ( 0x01 | ( V_63 << 1 ) ) << ( 8 * V_136 ) ) ;
}
F_1 ( V_2 , V_85 + V_135 , V_262 ) ;
}
static int F_145 ( struct V_1 * V_2 , unsigned char * V_263 ,
int V_63 )
{
unsigned char V_264 = 0 ;
if ( memcmp ( V_263 , L_11 , 5 ) == 0 ) {
F_143 ( V_2 , V_263 [ 5 ] , V_63 ) ;
return 0 ;
}
V_264 = F_142 ( V_263 ) ;
if ( V_63 == - 1 ) {
if ( V_2 -> V_84 [ V_264 ] == 0 ) {
F_146 ( V_2 -> V_19 , L_12 ,
V_264 ) ;
return - V_265 ;
}
V_2 -> V_84 [ V_264 ] -- ;
if ( V_2 -> V_84 [ V_264 ] != 0 ) {
F_146 ( V_2 -> V_19 ,
L_13 ,
V_2 -> V_84 [ V_264 ] , V_264 ) ;
return - V_265 ;
}
} else
V_2 -> V_84 [ V_264 ] ++ ;
F_144 ( V_2 , V_264 , V_63 ) ;
return 0 ;
}
static void F_147 ( struct V_1 * V_2 ,
int V_266 )
{
T_1 V_267 , V_41 ;
V_267 = F_3 ( V_2 , V_103 ) ;
V_41 = F_3 ( V_2 , V_268 ) ;
if ( V_266 ) {
V_267 |= V_269 ;
V_41 |= V_270 ;
F_1 ( V_2 , V_140 , 0xffff ) ;
F_1 ( V_2 , V_141 , 0xffffffff ) ;
} else {
V_267 &= ~ V_269 ;
V_41 &= ~ V_270 ;
}
F_1 ( V_2 , V_103 , V_267 ) ;
F_1 ( V_2 , V_268 , V_41 ) ;
}
static void F_148 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = F_9 ( V_19 ) ;
struct V_271 * V_272 ;
if ( V_19 -> V_273 & V_274 ) {
F_147 ( V_2 , 1 ) ;
F_42 ( V_2 , V_69 ) ;
F_43 ( V_2 , V_69 ) ;
F_44 ( V_2 , V_69 ) ;
} else {
F_147 ( V_2 , 0 ) ;
F_42 ( V_2 , - 1 ) ;
F_57 ( V_2 , V_19 -> V_275 , V_69 ) ;
if ( V_19 -> V_273 & V_276 ) {
F_43 ( V_2 , V_69 ) ;
F_44 ( V_2 , V_69 ) ;
} else {
F_43 ( V_2 , - 1 ) ;
F_44 ( V_2 , - 1 ) ;
if ( ! F_149 ( V_19 ) ) {
F_150 (ha, dev) {
F_145 ( V_2 , V_272 -> V_137 ,
V_69 ) ;
}
}
}
}
}
static T_8 F_151 ( int V_277 , void * V_278 )
{
struct V_211 * V_212 = (struct V_211 * ) V_278 ;
F_152 ( V_212 -> V_2 -> V_19 -> V_277 ) ;
F_153 ( & V_212 -> V_223 ) ;
return V_279 ;
}
static int F_154 ( struct V_1 * V_2 ,
struct V_280 * V_281 )
{
struct V_282 V_33 ;
struct V_282 V_283 = {} ;
T_1 V_284 = F_3 ( V_2 , V_285 ) ;
V_33 . V_286 = ! ! ( V_284 & V_287 ) ;
if ( V_284 & V_288 )
V_33 . V_289 = V_290 ;
else if ( V_284 & V_291 )
V_33 . V_289 = V_292 ;
else
V_33 . V_289 = V_293 ;
V_33 . V_294 = ! ! ( V_284 & V_295 ) ;
V_283 . V_286 = 1 ;
V_283 . V_289 = 1 ;
V_283 . V_294 = 1 ;
F_155 ( V_281 , & V_33 , & V_283 ) ;
return 0 ;
}
static int F_156 ( struct V_296 * V_223 , int V_297 )
{
int V_43 = 0 ;
T_1 V_298 ;
struct V_1 * V_2 = F_9 ( V_223 -> V_19 ) ;
struct V_211 * V_212 = F_107 ( V_2 -> V_213 ) ;
if ( ! F_134 ( V_2 -> V_19 ) ) {
F_157 ( & V_212 -> V_223 ) ;
return V_43 ;
}
V_298 = F_3 ( V_2 , V_86 ) ;
if ( V_298 & V_299 ) {
T_1 V_300 = F_3 ( V_2 , V_88 ) ;
F_1 ( V_2 , V_88 , 0 ) ;
if ( V_2 -> V_114 && ( V_300 &
( V_301 |
V_302 |
V_303 ) ) ) {
F_154 ( V_2 , V_2 -> V_304 ) ;
}
}
if ( V_298 & V_305 ) {
F_138 ( V_2 , ( V_298 & V_305 ) ) ;
V_298 &= ~ V_305 ;
}
V_298 |= V_212 -> V_298 ;
V_43 = F_106 ( V_2 , V_297 , & V_2 -> V_306 [ V_69 ] ) ;
V_297 -= V_43 ;
if ( V_297 > 0 ) {
V_298 = 0 ;
F_157 ( & V_212 -> V_223 ) ;
F_158 ( V_2 -> V_19 -> V_277 , 0 ) ;
}
V_212 -> V_298 = V_298 ;
return V_43 ;
}
static int F_159 ( struct V_1 * V_2 , struct V_35 * V_36 ,
int V_187 )
{
int V_11 ;
for ( V_11 = 0 ; V_11 < V_187 ; V_11 ++ ) {
memset ( V_36 -> V_48 + V_11 , 0 , sizeof( struct V_45 ) ) ;
if ( F_94 ( V_2 , V_36 -> V_48 + V_11 ) != 0 ) {
F_75 ( V_2 -> V_19 , L_14 ,
V_307 , V_36 -> V_39 , V_11 , V_187 ) ;
break;
}
}
F_15 ( V_2 , V_36 , V_11 ) ;
return V_11 ;
}
static void F_160 ( struct V_1 * V_2 )
{
int V_63 ;
for ( V_63 = 0 ; V_63 < V_65 ; V_63 ++ )
F_137 ( V_2 , & V_2 -> V_66 [ V_63 ] ) ;
F_1 ( V_2 , V_98 , V_99 ) ;
F_1 ( V_2 , V_98 , 0 ) ;
}
static void F_161 ( struct V_1 * V_2 )
{
F_1 ( V_2 , V_96 , V_97 ) ;
F_1 ( V_2 , V_96 , 0 ) ;
}
static int F_162 ( struct V_1 * V_2 ,
struct V_35 * V_36 )
{
V_36 -> V_9 = V_2 -> V_308 ;
V_36 -> V_48 = F_163 ( V_2 -> V_19 -> V_19 . V_189 ,
V_36 -> V_9 * V_309 ,
& V_36 -> V_310 , V_311 ) ;
if ( V_36 -> V_48 == NULL )
return - V_198 ;
F_164 ( V_36 -> V_48 !=
F_165 ( V_36 -> V_48 , V_312 ) ) ;
V_36 -> V_58 = V_36 -> V_9 - 1 ;
F_1 ( V_2 , F_166 ( V_36 -> V_39 ) , V_36 -> V_310 ) ;
F_1 ( V_2 , F_32 ( V_36 -> V_39 ) , V_36 -> V_9 ) ;
F_24 ( V_2 , V_36 , V_222 ) ;
F_58 ( V_2 , V_36 , V_36 -> V_143 ) ;
F_61 ( V_2 , V_36 , V_36 -> V_146 ) ;
F_31 ( V_2 , V_36 , F_96 ( V_2 -> V_199 ) ) ;
F_33 ( V_2 , V_36 ) ;
F_159 ( V_2 , V_36 , V_36 -> V_9 ) ;
return 0 ;
}
static void F_167 ( struct V_1 * V_2 ,
struct V_35 * V_36 )
{
F_105 ( V_2 , V_36 ) ;
if ( V_36 -> V_48 )
F_168 ( V_2 -> V_19 -> V_19 . V_189 ,
V_36 -> V_9 * V_309 ,
V_36 -> V_48 ,
V_36 -> V_310 ) ;
V_36 -> V_48 = NULL ;
V_36 -> V_58 = 0 ;
V_36 -> V_47 = 0 ;
V_36 -> V_310 = 0 ;
}
static int F_169 ( struct V_1 * V_2 ,
struct V_6 * V_7 )
{
V_7 -> V_9 = V_2 -> V_313 ;
V_7 -> V_253 = V_7 -> V_9 - V_314 ;
V_7 -> V_194 = V_7 -> V_253 / 2 ;
V_7 -> V_48 = F_163 ( V_2 -> V_19 -> V_19 . V_189 ,
V_7 -> V_9 * V_309 ,
& V_7 -> V_310 , V_311 ) ;
if ( V_7 -> V_48 == NULL )
return - V_198 ;
F_164 ( V_7 -> V_48 !=
F_165 ( V_7 -> V_48 , V_312 ) ) ;
V_7 -> V_58 = V_7 -> V_9 - 1 ;
F_1 ( V_2 , F_49 ( V_7 -> V_39 ) , 0x03ffffff ) ;
F_1 ( V_2 , F_48 ( V_7 -> V_39 ) , 0x3fffffff ) ;
F_1 ( V_2 , F_170 ( V_7 -> V_39 ) , V_7 -> V_310 ) ;
F_1 ( V_2 , F_65 ( V_7 -> V_39 ) , V_7 -> V_9 ) ;
V_7 -> V_188 = F_90 ( V_7 -> V_9 * sizeof( * V_7 -> V_188 ) , V_311 ) ;
if ( V_7 -> V_188 == NULL ) {
F_168 ( V_2 -> V_19 -> V_19 . V_189 ,
V_7 -> V_9 * V_309 ,
V_7 -> V_48 , V_7 -> V_310 ) ;
return - V_198 ;
}
V_7 -> V_240 = F_163 ( V_2 -> V_19 -> V_19 . V_189 ,
V_7 -> V_9 * V_228 ,
& V_7 -> V_227 , V_311 ) ;
if ( V_7 -> V_240 == NULL ) {
F_93 ( V_7 -> V_188 ) ;
F_168 ( V_2 -> V_19 -> V_19 . V_189 ,
V_7 -> V_9 * V_309 ,
V_7 -> V_48 , V_7 -> V_310 ) ;
return - V_198 ;
}
F_64 ( V_2 , V_7 , V_7 -> V_148 ) ;
return 0 ;
}
static void F_171 ( struct V_1 * V_2 ,
struct V_6 * V_7 )
{
F_93 ( V_7 -> V_188 ) ;
if ( V_7 -> V_240 )
F_168 ( V_2 -> V_19 -> V_19 . V_189 ,
V_7 -> V_9 * V_228 ,
V_7 -> V_240 , V_7 -> V_227 ) ;
if ( V_7 -> V_48 )
F_168 ( V_2 -> V_19 -> V_19 . V_189 ,
V_7 -> V_9 * V_309 ,
V_7 -> V_48 , V_7 -> V_310 ) ;
V_7 -> V_48 = NULL ;
V_7 -> V_58 = 0 ;
V_7 -> V_47 = 0 ;
V_7 -> V_310 = 0 ;
F_1 ( V_2 , F_49 ( V_7 -> V_39 ) , 0 ) ;
F_1 ( V_2 , F_48 ( V_7 -> V_39 ) , 0 ) ;
F_1 ( V_2 , F_170 ( V_7 -> V_39 ) , 0 ) ;
F_1 ( V_2 , F_65 ( V_7 -> V_39 ) , 0 ) ;
}
static void F_172 ( struct V_1 * V_2 )
{
int V_63 ;
for ( V_63 = 0 ; V_63 < V_65 ; V_63 ++ )
F_171 ( V_2 , & V_2 -> V_66 [ V_63 ] ) ;
}
static void F_173 ( struct V_1 * V_2 )
{
F_167 ( V_2 , & V_2 -> V_306 [ V_69 ] ) ;
}
static int F_174 ( struct V_1 * V_2 )
{
int V_217 = F_162 ( V_2 , & V_2 -> V_306 [ V_69 ] ) ;
if ( V_217 ) {
F_75 ( V_2 -> V_19 , L_15 ,
V_307 , V_69 ) ;
F_173 ( V_2 ) ;
return V_217 ;
}
return 0 ;
}
static int F_175 ( struct V_1 * V_2 )
{
int V_63 ;
for ( V_63 = 0 ; V_63 < V_65 ; V_63 ++ ) {
int V_217 = F_169 ( V_2 , & V_2 -> V_66 [ V_63 ] ) ;
if ( V_217 ) {
F_75 ( V_2 -> V_19 , L_16 ,
V_307 , V_63 ) ;
F_172 ( V_2 ) ;
return V_217 ;
}
}
return 0 ;
}
static void F_176 ( struct V_1 * V_2 )
{
unsigned int V_22 ;
F_23 ( V_2 , V_2 -> V_199 ) ;
F_54 ( V_2 , V_2 -> V_199 ) ;
F_40 ( V_2 ) ;
F_46 (cpu) {
struct V_211 * V_212 = F_11 ( V_2 -> V_213 , V_22 ) ;
F_177 ( & V_212 -> V_223 ) ;
}
F_1 ( V_2 , V_89 ,
F_178 ( V_315 ) |
F_179 ( V_65 ) |
V_299 ) ;
F_1 ( V_2 , V_91 ,
V_301 |
V_302 |
V_303 ) ;
F_180 ( V_2 -> V_304 ) ;
F_181 ( V_2 -> V_19 ) ;
}
static void F_182 ( struct V_1 * V_2 )
{
unsigned int V_22 ;
F_183 ( V_2 -> V_304 ) ;
F_46 (cpu) {
struct V_211 * V_212 = F_11 ( V_2 -> V_213 , V_22 ) ;
F_184 ( & V_212 -> V_223 ) ;
}
F_185 ( V_2 -> V_19 ) ;
F_36 ( V_2 ) ;
F_186 ( V_2 -> V_19 ) ;
F_41 ( V_2 ) ;
F_1 ( V_2 , V_88 , 0 ) ;
F_1 ( V_2 , V_87 , 0 ) ;
F_1 ( V_2 , V_89 , 0 ) ;
F_1 ( V_2 , V_90 , 0 ) ;
F_1 ( V_2 , V_91 , 0 ) ;
F_160 ( V_2 ) ;
F_161 ( V_2 ) ;
}
static int F_187 ( struct V_18 * V_19 , int V_127 )
{
if ( V_127 < 68 ) {
F_75 ( V_19 , L_17 ) ;
return - V_265 ;
}
if ( V_127 > 9676 ) {
F_146 ( V_19 , L_18 , V_127 ) ;
V_127 = 9676 ;
}
if ( ! F_188 ( F_189 ( V_127 ) , 8 ) ) {
F_146 ( V_19 , L_19 ,
V_127 , F_190 ( F_189 ( V_127 ) , 8 ) ) ;
V_127 = F_190 ( F_189 ( V_127 ) , 8 ) ;
}
return V_127 ;
}
static int F_191 ( struct V_18 * V_19 , int V_127 )
{
struct V_1 * V_2 = F_9 ( V_19 ) ;
int V_316 ;
V_127 = F_187 ( V_19 , V_127 ) ;
if ( V_127 < 0 )
return - V_265 ;
V_19 -> V_127 = V_127 ;
if ( ! F_134 ( V_19 ) ) {
F_192 ( V_19 ) ;
return 0 ;
}
F_182 ( V_2 ) ;
F_172 ( V_2 ) ;
F_173 ( V_2 ) ;
V_2 -> V_199 = F_189 ( V_19 -> V_127 ) ;
V_2 -> V_195 = F_193 ( F_96 ( V_2 -> V_199 ) ) +
F_193 ( sizeof( struct V_317 ) ) ;
V_316 = F_174 ( V_2 ) ;
if ( V_316 ) {
F_75 ( V_19 , L_20 ) ;
return V_316 ;
}
V_316 = F_175 ( V_2 ) ;
if ( V_316 ) {
F_75 ( V_19 , L_21 ) ;
return V_316 ;
}
F_176 ( V_2 ) ;
F_34 ( V_2 ) ;
F_192 ( V_19 ) ;
return 0 ;
}
static T_9 F_194 ( struct V_18 * V_19 ,
T_9 V_318 )
{
struct V_1 * V_2 = F_9 ( V_19 ) ;
if ( V_2 -> V_319 && V_19 -> V_127 > V_2 -> V_319 ) {
V_318 &= ~ ( V_320 | V_321 ) ;
F_146 ( V_19 ,
L_22 ,
V_2 -> V_319 ) ;
}
return V_318 ;
}
static void F_195 ( struct V_1 * V_2 , unsigned char * V_137 )
{
T_1 V_322 , V_323 ;
V_322 = F_3 ( V_2 , V_140 ) ;
V_323 = F_3 ( V_2 , V_141 ) ;
V_137 [ 0 ] = ( V_323 >> 24 ) & 0xFF ;
V_137 [ 1 ] = ( V_323 >> 16 ) & 0xFF ;
V_137 [ 2 ] = ( V_323 >> 8 ) & 0xFF ;
V_137 [ 3 ] = V_323 & 0xFF ;
V_137 [ 4 ] = ( V_322 >> 8 ) & 0xFF ;
V_137 [ 5 ] = V_322 & 0xFF ;
}
static int F_196 ( struct V_18 * V_19 , void * V_137 )
{
struct V_1 * V_2 = F_9 ( V_19 ) ;
struct V_324 * V_324 = V_137 ;
int V_316 ;
V_316 = F_197 ( V_19 , V_137 ) ;
if ( V_316 < 0 )
return V_316 ;
F_57 ( V_2 , V_19 -> V_275 , - 1 ) ;
F_57 ( V_2 , V_324 -> V_325 , V_69 ) ;
F_198 ( V_19 , V_137 ) ;
return 0 ;
}
static void F_199 ( struct V_18 * V_326 )
{
struct V_1 * V_2 = F_9 ( V_326 ) ;
struct V_280 * V_327 = V_2 -> V_304 ;
int V_328 = 0 ;
if ( V_327 -> V_286 ) {
if ( ( V_2 -> V_289 != V_327 -> V_289 ) ||
( V_2 -> V_294 != V_327 -> V_294 ) ) {
T_1 V_41 ;
V_41 = F_3 ( V_2 , V_115 ) ;
V_41 &= ~ ( V_329 |
V_330 |
V_331 ) ;
if ( V_327 -> V_294 )
V_41 |= V_331 ;
if ( V_327 -> V_289 == V_290 )
V_41 |= V_330 ;
else if ( V_327 -> V_289 == V_292 )
V_41 |= V_329 ;
F_1 ( V_2 , V_115 , V_41 ) ;
V_2 -> V_294 = V_327 -> V_294 ;
V_2 -> V_289 = V_327 -> V_289 ;
}
}
if ( V_327 -> V_286 != V_2 -> V_286 ) {
if ( ! V_327 -> V_286 ) {
V_2 -> V_294 = - 1 ;
V_2 -> V_289 = 0 ;
}
V_2 -> V_286 = V_327 -> V_286 ;
V_328 = 1 ;
}
if ( V_328 ) {
if ( V_327 -> V_286 ) {
if ( ! V_2 -> V_114 ) {
T_1 V_41 = F_3 ( V_2 ,
V_115 ) ;
V_41 &= ~ V_117 ;
V_41 |= V_116 ;
F_1 ( V_2 , V_115 ,
V_41 ) ;
}
F_34 ( V_2 ) ;
} else {
if ( ! V_2 -> V_114 ) {
T_1 V_41 = F_3 ( V_2 ,
V_115 ) ;
V_41 &= ~ V_116 ;
V_41 |= V_117 ;
F_1 ( V_2 , V_115 ,
V_41 ) ;
}
F_36 ( V_2 ) ;
}
F_200 ( V_327 ) ;
}
}
static int F_201 ( struct V_1 * V_2 )
{
struct V_280 * V_304 ;
V_304 = F_202 ( V_2 -> V_19 , V_2 -> V_332 , F_199 , 0 ,
V_2 -> V_333 ) ;
if ( ! V_304 ) {
F_75 ( V_2 -> V_19 , L_23 ) ;
return - V_334 ;
}
V_304 -> V_335 &= V_336 ;
V_304 -> V_337 = V_304 -> V_335 ;
V_2 -> V_304 = V_304 ;
V_2 -> V_286 = 0 ;
V_2 -> V_294 = 0 ;
V_2 -> V_289 = 0 ;
return 0 ;
}
static void F_203 ( struct V_1 * V_2 )
{
F_204 ( V_2 -> V_304 ) ;
V_2 -> V_304 = NULL ;
}
static void F_205 ( void * V_338 )
{
struct V_1 * V_2 = V_338 ;
F_158 ( V_2 -> V_19 -> V_277 , V_339 ) ;
}
static void F_206 ( void * V_338 )
{
struct V_1 * V_2 = V_338 ;
F_152 ( V_2 -> V_19 -> V_277 ) ;
}
static void F_207 ( struct V_1 * V_2 )
{
int V_340 , V_22 , V_11 = 0 ;
V_340 = V_69 % F_208 () ;
F_209 (cpu) {
if ( V_11 == V_340 )
F_210 ( V_22 , F_205 ,
V_2 , true ) ;
else
F_210 ( V_22 , F_206 ,
V_2 , true ) ;
V_11 ++ ;
}
}
static int F_211 ( struct V_341 * V_342 ,
unsigned long V_343 , void * V_344 )
{
struct V_1 * V_2 = F_212 ( V_342 , struct V_1 ,
V_345 ) ;
int V_22 = ( unsigned long ) V_344 , V_346 ;
struct V_211 * V_212 = F_11 ( V_2 -> V_213 , V_22 ) ;
switch ( V_343 ) {
case V_347 :
case V_348 :
F_186 ( V_2 -> V_19 ) ;
F_209 (other_cpu) {
if ( V_346 != V_22 ) {
struct V_211 * V_349 =
F_11 ( V_2 -> V_213 , V_346 ) ;
F_213 ( & V_349 -> V_223 ) ;
}
}
F_1 ( V_2 , V_89 , 0 ) ;
F_1 ( V_2 , V_90 , 0 ) ;
F_1 ( V_2 , V_91 , 0 ) ;
F_177 ( & V_212 -> V_223 ) ;
F_207 ( V_2 ) ;
F_1 ( V_2 , V_89 ,
F_178 ( V_315 ) |
F_179 ( V_65 ) |
V_299 ) ;
F_1 ( V_2 , V_91 ,
V_301 |
V_302 |
V_303 ) ;
F_181 ( V_2 -> V_19 ) ;
break;
case V_350 :
case V_351 :
F_186 ( V_2 -> V_19 ) ;
F_1 ( V_2 , V_89 , 0 ) ;
F_1 ( V_2 , V_90 , 0 ) ;
F_1 ( V_2 , V_91 , 0 ) ;
F_213 ( & V_212 -> V_223 ) ;
F_184 ( & V_212 -> V_223 ) ;
F_210 ( V_22 , F_206 ,
V_2 , true ) ;
break;
case V_352 :
case V_353 :
F_207 ( V_2 ) ;
F_1 ( V_2 , V_89 ,
F_178 ( V_315 ) |
F_179 ( V_65 ) |
V_299 ) ;
F_1 ( V_2 , V_91 ,
V_301 |
V_302 |
V_303 ) ;
F_181 ( V_2 -> V_19 ) ;
break;
}
return V_354 ;
}
static int F_214 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = F_9 ( V_19 ) ;
int V_316 ;
V_2 -> V_199 = F_189 ( V_2 -> V_19 -> V_127 ) ;
V_2 -> V_195 = F_193 ( F_96 ( V_2 -> V_199 ) ) +
F_193 ( sizeof( struct V_317 ) ) ;
V_316 = F_174 ( V_2 ) ;
if ( V_316 )
return V_316 ;
V_316 = F_175 ( V_2 ) ;
if ( V_316 )
goto V_355;
V_316 = F_215 ( V_2 -> V_19 -> V_277 , F_151 ,
V_356 , V_2 -> V_213 ) ;
if ( V_316 ) {
F_75 ( V_2 -> V_19 , L_24 , V_2 -> V_19 -> V_277 ) ;
goto V_357;
}
F_206 ( V_2 ) ;
F_207 ( V_2 ) ;
F_216 ( & V_2 -> V_345 ) ;
F_185 ( V_2 -> V_19 ) ;
V_316 = F_201 ( V_2 ) ;
if ( V_316 < 0 ) {
F_75 ( V_19 , L_25 ) ;
goto V_358;
}
F_176 ( V_2 ) ;
return 0 ;
V_358:
F_217 ( V_2 -> V_19 -> V_277 , V_2 -> V_213 ) ;
V_357:
F_172 ( V_2 ) ;
V_355:
F_173 ( V_2 ) ;
return V_316 ;
}
static int F_218 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = F_9 ( V_19 ) ;
int V_22 ;
F_182 ( V_2 ) ;
F_203 ( V_2 ) ;
F_219 ( & V_2 -> V_345 ) ;
F_46 (cpu)
F_210 ( V_22 , F_206 , V_2 , true ) ;
F_217 ( V_19 -> V_277 , V_2 -> V_213 ) ;
F_173 ( V_2 ) ;
F_172 ( V_2 ) ;
return 0 ;
}
static int F_220 ( struct V_18 * V_19 , struct V_359 * V_360 , int V_361 )
{
struct V_1 * V_2 = F_9 ( V_19 ) ;
if ( ! V_2 -> V_304 )
return - V_362 ;
return F_221 ( V_2 -> V_304 , V_360 , V_361 ) ;
}
int F_222 ( struct V_18 * V_19 , struct V_363 * V_361 )
{
struct V_1 * V_2 = F_9 ( V_19 ) ;
if ( ! V_2 -> V_304 )
return - V_334 ;
return F_223 ( V_2 -> V_304 , V_361 ) ;
}
int F_224 ( struct V_18 * V_19 , struct V_363 * V_361 )
{
struct V_1 * V_2 = F_9 ( V_19 ) ;
if ( ! V_2 -> V_304 )
return - V_334 ;
return F_225 ( V_2 -> V_304 , V_361 ) ;
}
static int F_226 ( struct V_18 * V_19 ,
struct V_364 * V_365 )
{
struct V_1 * V_2 = F_9 ( V_19 ) ;
int V_63 ;
for ( V_63 = 0 ; V_63 < V_315 ; V_63 ++ ) {
struct V_35 * V_36 = & V_2 -> V_306 [ V_63 ] ;
V_36 -> V_146 = V_365 -> V_366 ;
V_36 -> V_143 = V_365 -> V_367 ;
F_58 ( V_2 , V_36 , V_36 -> V_143 ) ;
F_61 ( V_2 , V_36 , V_36 -> V_146 ) ;
}
for ( V_63 = 0 ; V_63 < V_65 ; V_63 ++ ) {
struct V_6 * V_7 = & V_2 -> V_66 [ V_63 ] ;
V_7 -> V_148 = V_365 -> V_368 ;
F_64 ( V_2 , V_7 , V_7 -> V_148 ) ;
}
return 0 ;
}
static int F_227 ( struct V_18 * V_19 ,
struct V_364 * V_365 )
{
struct V_1 * V_2 = F_9 ( V_19 ) ;
V_365 -> V_366 = V_2 -> V_306 [ 0 ] . V_146 ;
V_365 -> V_367 = V_2 -> V_306 [ 0 ] . V_143 ;
V_365 -> V_368 = V_2 -> V_66 [ 0 ] . V_148 ;
return 0 ;
}
static void F_228 ( struct V_18 * V_19 ,
struct V_369 * V_370 )
{
F_229 ( V_370 -> V_371 , V_356 ,
sizeof( V_370 -> V_371 ) ) ;
F_229 ( V_370 -> V_372 , V_373 ,
sizeof( V_370 -> V_372 ) ) ;
F_229 ( V_370 -> V_374 , F_230 ( & V_19 -> V_19 ) ,
sizeof( V_370 -> V_374 ) ) ;
}
static void F_231 ( struct V_18 * V_375 ,
struct V_376 * V_377 )
{
struct V_1 * V_2 = F_9 ( V_375 ) ;
V_377 -> V_378 = V_379 ;
V_377 -> V_380 = V_381 ;
V_377 -> V_382 = V_2 -> V_308 ;
V_377 -> V_383 = V_2 -> V_313 ;
}
static int F_232 ( struct V_18 * V_19 ,
struct V_376 * V_377 )
{
struct V_1 * V_2 = F_9 ( V_19 ) ;
if ( ( V_377 -> V_382 == 0 ) || ( V_377 -> V_383 == 0 ) )
return - V_265 ;
V_2 -> V_308 = V_377 -> V_382 < V_379 ?
V_377 -> V_382 : V_379 ;
V_2 -> V_313 = F_233 ( T_7 , V_377 -> V_383 ,
V_314 * 2 , V_381 ) ;
if ( V_2 -> V_313 != V_377 -> V_383 )
F_37 ( V_19 , L_26 ,
V_2 -> V_313 , V_377 -> V_383 ) ;
if ( F_134 ( V_19 ) ) {
F_218 ( V_19 ) ;
if ( F_214 ( V_19 ) ) {
F_75 ( V_19 ,
L_27 ) ;
return - V_198 ;
}
}
return 0 ;
}
static void F_234 ( struct V_18 * V_375 , T_1 V_384 ,
T_3 * V_4 )
{
if ( V_384 == V_385 ) {
int V_11 ;
for ( V_11 = 0 ; V_11 < F_235 ( V_386 ) ; V_11 ++ )
memcpy ( V_4 + V_11 * V_387 ,
V_386 [ V_11 ] . V_388 , V_387 ) ;
}
}
static void F_236 ( struct V_1 * V_2 )
{
const struct V_389 * V_390 ;
void T_10 * V_5 = V_2 -> V_5 ;
T_1 V_391 , V_392 , V_41 ;
int V_11 ;
for ( V_11 = 0 , V_390 = V_386 ;
V_390 < V_386 + F_235 ( V_386 ) ;
V_390 ++ , V_11 ++ ) {
V_41 = 0 ;
switch ( V_390 -> type ) {
case V_393 :
V_41 = F_237 ( V_5 + V_390 -> V_3 ) ;
break;
case V_394 :
V_392 = F_237 ( V_5 + V_390 -> V_3 ) ;
V_391 = F_237 ( V_5 + V_390 -> V_3 + 4 ) ;
V_41 = ( T_2 ) V_391 << 32 | V_392 ;
break;
}
V_2 -> V_395 [ V_11 ] += V_41 ;
}
}
static void F_238 ( struct V_18 * V_19 ,
struct V_395 * V_20 , T_2 * V_4 )
{
struct V_1 * V_2 = F_9 ( V_19 ) ;
int V_11 ;
F_236 ( V_2 ) ;
for ( V_11 = 0 ; V_11 < F_235 ( V_386 ) ; V_11 ++ )
* V_4 ++ = V_2 -> V_395 [ V_11 ] ;
}
static int F_239 ( struct V_18 * V_19 , int V_384 )
{
if ( V_384 == V_385 )
return F_235 ( V_386 ) ;
return - V_396 ;
}
static int F_240 ( struct V_397 * V_19 , struct V_1 * V_2 )
{
int V_63 ;
F_41 ( V_2 ) ;
F_45 ( V_2 ) ;
V_2 -> V_66 = F_241 ( V_19 , V_65 , sizeof( struct V_6 ) ,
V_311 ) ;
if ( ! V_2 -> V_66 )
return - V_198 ;
for ( V_63 = 0 ; V_63 < V_65 ; V_63 ++ ) {
struct V_6 * V_7 = & V_2 -> V_66 [ V_63 ] ;
V_7 -> V_39 = V_63 ;
V_7 -> V_9 = V_2 -> V_313 ;
V_7 -> V_148 = V_398 ;
}
V_2 -> V_306 = F_241 ( V_19 , V_315 , sizeof( struct V_35 ) ,
V_311 ) ;
if ( ! V_2 -> V_306 )
return - V_198 ;
for ( V_63 = 0 ; V_63 < V_315 ; V_63 ++ ) {
struct V_35 * V_36 = & V_2 -> V_306 [ V_63 ] ;
V_36 -> V_39 = V_63 ;
V_36 -> V_9 = V_2 -> V_308 ;
V_36 -> V_143 = V_399 ;
V_36 -> V_146 = V_400 ;
}
return 0 ;
}
static void F_242 ( struct V_1 * V_2 ,
const struct V_401 * V_402 )
{
T_1 V_403 ;
T_1 V_404 ;
int V_11 ;
for ( V_11 = 0 ; V_11 < 6 ; V_11 ++ ) {
F_1 ( V_2 , F_243 ( V_11 ) , 0 ) ;
F_1 ( V_2 , F_244 ( V_11 ) , 0 ) ;
if ( V_11 < 4 )
F_1 ( V_2 , F_245 ( V_11 ) , 0 ) ;
}
V_403 = 0x3f ;
V_404 = 0 ;
for ( V_11 = 0 ; V_11 < V_402 -> V_405 ; V_11 ++ ) {
const struct V_406 * V_407 = V_402 -> V_407 + V_11 ;
F_1 ( V_2 , F_243 ( V_11 ) , ( V_407 -> V_5 & 0xffff0000 ) |
( V_407 -> V_408 << 8 ) | V_402 -> V_409 ) ;
F_1 ( V_2 , F_244 ( V_11 ) ,
( V_407 -> V_9 - 1 ) & 0xffff0000 ) ;
V_403 &= ~ ( 1 << V_11 ) ;
V_404 |= 3 << ( 2 * V_11 ) ;
}
F_1 ( V_2 , V_410 , V_403 ) ;
F_1 ( V_2 , V_411 , V_404 ) ;
}
static int F_246 ( struct V_1 * V_2 , int V_412 )
{
T_1 V_413 ;
F_1 ( V_2 , V_414 , 0 ) ;
V_413 = F_3 ( V_2 , V_415 ) ;
switch( V_412 ) {
case V_416 :
F_1 ( V_2 , V_417 , V_418 ) ;
V_413 |= V_419 | V_420 ;
break;
case V_421 :
F_1 ( V_2 , V_417 , V_422 ) ;
V_413 |= V_419 | V_420 ;
break;
case V_423 :
case V_424 :
V_413 |= V_420 ;
break;
default:
return - V_265 ;
}
if ( V_2 -> V_114 )
V_413 |= V_425 ;
V_413 &= ~ V_426 ;
F_1 ( V_2 , V_415 , V_413 ) ;
while ( ( F_3 ( V_2 , V_415 ) &
V_426 ) != 0 )
continue;
return 0 ;
}
static int F_247 ( struct V_427 * V_428 )
{
const struct V_401 * V_429 ;
struct V_430 * V_431 ;
struct V_432 * V_433 = V_428 -> V_19 . V_434 ;
struct V_432 * V_332 ;
struct V_1 * V_2 ;
struct V_18 * V_19 ;
const char * V_435 ;
char V_436 [ V_257 ] ;
const char * V_437 ;
const char * V_438 ;
int V_319 ;
int V_412 ;
int V_217 ;
int V_22 ;
V_19 = F_248 ( sizeof( struct V_1 ) , V_65 , V_315 ) ;
if ( ! V_19 )
return - V_198 ;
V_19 -> V_277 = F_249 ( V_433 , 0 ) ;
if ( V_19 -> V_277 == 0 ) {
V_217 = - V_265 ;
goto V_439;
}
V_332 = F_250 ( V_433 , L_28 , 0 ) ;
if ( ! V_332 ) {
if ( ! F_251 ( V_433 ) ) {
F_252 ( & V_428 -> V_19 , L_29 ) ;
V_217 = - V_334 ;
goto V_358;
}
V_217 = F_253 ( V_433 ) ;
if ( V_217 < 0 ) {
F_252 ( & V_428 -> V_19 , L_30 ) ;
goto V_358;
}
V_332 = F_254 ( V_433 ) ;
}
V_412 = F_255 ( V_433 ) ;
if ( V_412 < 0 ) {
F_252 ( & V_428 -> V_19 , L_31 ) ;
V_217 = - V_265 ;
goto V_440;
}
V_19 -> V_441 = V_381 ;
V_19 -> V_442 = 5 * V_443 ;
V_19 -> V_444 = & V_445 ;
V_19 -> V_446 = & V_447 ;
V_2 = F_9 ( V_19 ) ;
V_2 -> V_332 = V_332 ;
V_2 -> V_333 = V_412 ;
V_217 = F_256 ( V_433 , L_32 , & V_438 ) ;
V_2 -> V_114 = ( V_217 == 0 &&
strcmp ( V_438 , L_33 ) == 0 ) ;
V_2 -> V_345 . V_448 = F_211 ;
V_2 -> V_145 = F_257 ( & V_428 -> V_19 , NULL ) ;
if ( F_258 ( V_2 -> V_145 ) ) {
V_217 = F_259 ( V_2 -> V_145 ) ;
goto V_440;
}
F_260 ( V_2 -> V_145 ) ;
V_431 = F_261 ( V_428 , V_449 , 0 ) ;
V_2 -> V_5 = F_262 ( & V_428 -> V_19 , V_431 ) ;
if ( F_258 ( V_2 -> V_5 ) ) {
V_217 = F_259 ( V_2 -> V_5 ) ;
goto V_450;
}
V_2 -> V_213 = F_263 ( struct V_211 ) ;
if ( ! V_2 -> V_213 ) {
V_217 = - V_198 ;
goto V_450;
}
V_2 -> V_20 = F_264 ( struct V_23 ) ;
if ( ! V_2 -> V_20 ) {
V_217 = - V_198 ;
goto V_451;
}
V_435 = F_265 ( V_433 ) ;
if ( V_435 ) {
V_437 = L_34 ;
memcpy ( V_19 -> V_275 , V_435 , V_257 ) ;
} else {
F_195 ( V_2 , V_436 ) ;
if ( F_266 ( V_436 ) ) {
V_437 = L_35 ;
memcpy ( V_19 -> V_275 , V_436 , V_257 ) ;
} else {
V_437 = L_36 ;
F_267 ( V_19 ) ;
}
}
if ( ! F_268 ( V_433 , L_37 , & V_319 ) ) {
if ( V_319 < 0 ||
V_319 > V_452 ) {
V_319 = V_453 ;
F_269 ( & V_428 -> V_19 ,
L_38 ,
V_453 ) ;
}
} else if ( F_270 ( V_433 , L_39 ) ) {
V_319 = V_453 ;
} else {
V_319 = V_452 ;
}
V_2 -> V_319 = V_319 ;
V_2 -> V_313 = V_381 ;
V_2 -> V_308 = V_379 ;
V_2 -> V_19 = V_19 ;
F_271 ( V_19 , & V_428 -> V_19 ) ;
V_217 = F_240 ( & V_428 -> V_19 , V_2 ) ;
if ( V_217 < 0 )
goto V_454;
V_217 = F_246 ( V_2 , V_412 ) ;
if ( V_217 < 0 ) {
F_252 ( & V_428 -> V_19 , L_40 ) ;
goto V_454;
}
V_429 = F_272 () ;
if ( V_429 )
F_242 ( V_2 , V_429 ) ;
F_46 (cpu) {
struct V_211 * V_212 = F_11 ( V_2 -> V_213 , V_22 ) ;
F_273 ( V_19 , & V_212 -> V_223 , F_156 , V_455 ) ;
V_212 -> V_2 = V_2 ;
}
V_19 -> V_318 = V_456 | V_320 | V_321 ;
V_19 -> V_457 |= V_19 -> V_318 ;
V_19 -> V_458 |= V_19 -> V_318 ;
V_19 -> V_459 |= V_460 ;
V_19 -> V_461 = V_462 ;
V_217 = F_274 ( V_19 ) ;
if ( V_217 < 0 ) {
F_252 ( & V_428 -> V_19 , L_41 ) ;
goto V_454;
}
F_146 ( V_19 , L_42 , V_437 ,
V_19 -> V_275 ) ;
F_275 ( V_428 , V_2 -> V_19 ) ;
if ( V_2 -> V_114 ) {
struct V_280 * V_281 = F_276 ( V_433 ) ;
F_154 ( V_2 , V_281 ) ;
F_277 ( & V_281 -> V_19 ) ;
}
return 0 ;
V_454:
F_278 ( V_2 -> V_20 ) ;
V_451:
F_278 ( V_2 -> V_213 ) ;
V_450:
F_279 ( V_2 -> V_145 ) ;
V_440:
F_280 ( V_332 ) ;
V_358:
F_281 ( V_19 -> V_277 ) ;
V_439:
F_282 ( V_19 ) ;
return V_217 ;
}
static int F_283 ( struct V_427 * V_428 )
{
struct V_18 * V_19 = F_284 ( V_428 ) ;
struct V_1 * V_2 = F_9 ( V_19 ) ;
F_285 ( V_19 ) ;
F_279 ( V_2 -> V_145 ) ;
F_278 ( V_2 -> V_213 ) ;
F_278 ( V_2 -> V_20 ) ;
F_281 ( V_19 -> V_277 ) ;
F_280 ( V_2 -> V_332 ) ;
F_282 ( V_19 ) ;
return 0 ;
}
