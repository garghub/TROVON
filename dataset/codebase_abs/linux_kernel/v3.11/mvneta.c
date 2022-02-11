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
memset ( V_18 , 0 , sizeof( struct V_15 ) ) ;
do {
V_19 = F_10 ( & V_2 -> V_20 . V_21 ) ;
V_18 -> V_22 = V_2 -> V_20 . V_23 ;
V_18 -> V_24 = V_2 -> V_20 . V_25 ;
} while ( F_11 ( & V_2 -> V_20 . V_21 , V_19 ) );
do {
V_19 = F_10 ( & V_2 -> V_26 . V_21 ) ;
V_18 -> V_27 = V_2 -> V_26 . V_23 ;
V_18 -> V_28 = V_2 -> V_26 . V_25 ;
} while ( F_11 ( & V_2 -> V_26 . V_21 , V_19 ) );
V_18 -> V_29 = V_17 -> V_18 . V_29 ;
V_18 -> V_30 = V_17 -> V_18 . V_30 ;
V_18 -> V_31 = V_17 -> V_18 . V_31 ;
return V_18 ;
}
static int F_12 ( struct V_32 * V_33 )
{
return ( V_33 -> V_34 & V_35 ) ==
V_35 ;
}
static void F_13 ( struct V_1 * V_2 ,
struct V_36 * V_37 ,
int V_38 )
{
while ( V_38 > V_39 ) {
F_1 ( V_2 , F_14 ( V_37 -> V_40 ) ,
( V_39 <<
V_41 ) ) ;
V_38 -= V_39 ;
}
F_1 ( V_2 , F_14 ( V_37 -> V_40 ) ,
( V_38 << V_41 ) ) ;
}
static int F_15 ( struct V_1 * V_2 ,
struct V_36 * V_37 )
{
T_1 V_42 ;
V_42 = F_3 ( V_2 , F_16 ( V_37 -> V_40 ) ) ;
return V_42 & V_43 ;
}
static void F_17 ( struct V_1 * V_2 ,
struct V_36 * V_37 ,
int V_44 , int V_45 )
{
T_1 V_42 ;
if ( ( V_44 <= 0xff ) && ( V_45 <= 0xff ) ) {
V_42 = V_44 |
( V_45 << V_41 ) ;
F_1 ( V_2 , F_14 ( V_37 -> V_40 ) , V_42 ) ;
return;
}
while ( ( V_44 > 0 ) || ( V_45 > 0 ) ) {
if ( V_44 <= 0xff ) {
V_42 = V_44 ;
V_44 = 0 ;
} else {
V_42 = 0xff ;
V_44 -= 0xff ;
}
if ( V_45 <= 0xff ) {
V_42 |= V_45 << V_41 ;
V_45 = 0 ;
} else {
V_42 |= 0xff << V_41 ;
V_45 -= 0xff ;
}
F_1 ( V_2 , F_14 ( V_37 -> V_40 ) , V_42 ) ;
}
}
static struct V_32 *
F_18 ( struct V_36 * V_37 )
{
int V_46 = V_37 -> V_47 ;
V_37 -> V_47 = F_19 ( V_37 , V_46 ) ;
return V_37 -> V_48 + V_46 ;
}
static void F_20 ( struct V_1 * V_2 , int V_49 )
{
T_1 V_42 ;
V_42 = F_3 ( V_2 , V_50 ) ;
V_42 &= ~ V_51 ;
V_42 |= ( ( V_49 - V_52 ) / 2 ) <<
V_53 ;
F_1 ( V_2 , V_50 , V_42 ) ;
}
static void F_21 ( struct V_1 * V_2 ,
struct V_36 * V_37 ,
int V_3 )
{
T_1 V_42 ;
V_42 = F_3 ( V_2 , F_22 ( V_37 -> V_40 ) ) ;
V_42 &= ~ V_54 ;
V_42 |= F_23 ( V_3 >> 3 ) ;
F_1 ( V_2 , F_22 ( V_37 -> V_40 ) , V_42 ) ;
}
static void F_24 ( struct V_1 * V_2 ,
struct V_6 * V_7 ,
int V_55 )
{
T_1 V_42 ;
V_42 = V_55 ;
F_1 ( V_2 , F_25 ( V_7 -> V_40 ) , V_42 ) ;
}
static struct V_56 *
F_26 ( struct V_6 * V_7 )
{
int V_57 = V_7 -> V_47 ;
V_7 -> V_47 = F_19 ( V_7 , V_57 ) ;
return V_7 -> V_48 + V_57 ;
}
static void F_27 ( struct V_6 * V_7 )
{
if ( V_7 -> V_47 == 0 )
V_7 -> V_47 = V_7 -> V_58 - 1 ;
else
V_7 -> V_47 -- ;
}
static void F_28 ( struct V_1 * V_2 ,
struct V_36 * V_37 ,
int V_59 )
{
T_1 V_42 ;
V_42 = F_3 ( V_2 , F_29 ( V_37 -> V_40 ) ) ;
V_42 &= ~ V_60 ;
V_42 |= ( ( V_59 >> 3 ) << V_61 ) ;
F_1 ( V_2 , F_29 ( V_37 -> V_40 ) , V_42 ) ;
}
static void F_30 ( struct V_1 * V_2 ,
struct V_36 * V_37 )
{
T_1 V_42 ;
V_42 = F_3 ( V_2 , F_22 ( V_37 -> V_40 ) ) ;
V_42 &= ~ V_62 ;
F_1 ( V_2 , F_22 ( V_37 -> V_40 ) , V_42 ) ;
}
static void F_31 ( struct V_1 * V_2 , int V_63 )
{
T_1 V_42 ;
V_42 = F_3 ( V_2 , V_64 ) ;
if ( V_63 )
V_42 |= V_65 ;
else
V_42 &= ~ V_65 ;
F_1 ( V_2 , V_64 , V_42 ) ;
}
static void F_32 ( struct V_1 * V_2 )
{
T_1 V_42 ;
V_42 = F_3 ( V_2 , V_64 ) ;
V_42 |= V_66 ;
F_1 ( V_2 , V_64 , V_42 ) ;
F_1 ( V_2 , V_67 , V_68 ) ;
}
static void F_33 ( struct V_1 * V_2 )
{
int V_69 ;
T_1 V_70 ;
F_7 ( V_2 ) ;
V_70 = 0 ;
for ( V_69 = 0 ; V_69 < V_71 ; V_69 ++ ) {
struct V_6 * V_7 = & V_2 -> V_72 [ V_69 ] ;
if ( V_7 -> V_48 != NULL )
V_70 |= ( 1 << V_69 ) ;
}
F_1 ( V_2 , V_73 , V_70 ) ;
V_70 = 0 ;
for ( V_69 = 0 ; V_69 < V_74 ; V_69 ++ ) {
struct V_36 * V_37 = & V_2 -> V_75 [ V_69 ] ;
if ( V_37 -> V_48 != NULL )
V_70 |= ( 1 << V_69 ) ;
}
F_1 ( V_2 , V_76 , V_70 ) ;
}
static void F_34 ( struct V_1 * V_2 )
{
T_1 V_42 ;
int V_77 ;
V_42 = F_3 ( V_2 , V_76 ) & V_78 ;
if ( V_42 != 0 )
F_1 ( V_2 , V_76 ,
V_42 << V_79 ) ;
V_77 = 0 ;
do {
if ( V_77 ++ >= V_80 ) {
F_35 ( V_2 -> V_17 ,
L_1 ,
V_42 ) ;
break;
}
F_36 ( 1 ) ;
V_42 = F_3 ( V_2 , V_76 ) ;
} while ( V_42 & 0xff );
V_42 = ( F_3 ( V_2 , V_73 ) ) & V_81 ;
if ( V_42 != 0 )
F_1 ( V_2 , V_73 ,
( V_42 << V_82 ) ) ;
V_77 = 0 ;
do {
if ( V_77 ++ >= V_83 ) {
F_35 ( V_2 -> V_17 ,
L_2 ,
V_42 ) ;
break;
}
F_36 ( 1 ) ;
V_42 = F_3 ( V_2 , V_73 ) ;
} while ( V_42 & 0xff );
V_77 = 0 ;
do {
if ( V_77 ++ >= V_84 ) {
F_35 ( V_2 -> V_17 ,
L_3 ,
V_42 ) ;
break;
}
F_36 ( 1 ) ;
V_42 = F_3 ( V_2 , V_85 ) ;
} while ( ! ( V_42 & V_86 ) &&
( V_42 & V_87 ) );
F_37 ( 200 ) ;
}
static void F_38 ( struct V_1 * V_2 )
{
T_1 V_42 ;
V_42 = F_3 ( V_2 , V_50 ) ;
V_42 |= V_88 ;
F_1 ( V_2 , V_50 , V_42 ) ;
}
static void F_39 ( struct V_1 * V_2 )
{
T_1 V_42 ;
V_42 = F_3 ( V_2 , V_50 ) ;
V_42 &= ~ V_88 ;
F_1 ( V_2 , V_50 , V_42 ) ;
F_37 ( 200 ) ;
}
static void F_40 ( struct V_1 * V_2 , int V_69 )
{
int V_3 ;
T_1 V_42 ;
if ( V_69 == - 1 ) {
V_42 = 0 ;
} else {
V_42 = 0x1 | ( V_69 << 1 ) ;
V_42 |= ( V_42 << 24 ) | ( V_42 << 16 ) | ( V_42 << 8 ) ;
}
for ( V_3 = 0 ; V_3 <= 0xc ; V_3 += 4 )
F_1 ( V_2 , V_89 + V_3 , V_42 ) ;
}
static void F_41 ( struct V_1 * V_2 , int V_69 )
{
int V_3 ;
T_1 V_42 ;
if ( V_69 == - 1 ) {
V_42 = 0 ;
} else {
V_42 = 0x1 | ( V_69 << 1 ) ;
V_42 |= ( V_42 << 24 ) | ( V_42 << 16 ) | ( V_42 << 8 ) ;
}
for ( V_3 = 0 ; V_3 <= 0xfc ; V_3 += 4 )
F_1 ( V_2 , V_90 + V_3 , V_42 ) ;
}
static void F_42 ( struct V_1 * V_2 , int V_69 )
{
int V_3 ;
T_1 V_42 ;
if ( V_69 == - 1 ) {
memset ( V_2 -> V_91 , 0 , sizeof( V_2 -> V_91 ) ) ;
V_42 = 0 ;
} else {
memset ( V_2 -> V_91 , 1 , sizeof( V_2 -> V_91 ) ) ;
V_42 = 0x1 | ( V_69 << 1 ) ;
V_42 |= ( V_42 << 24 ) | ( V_42 << 16 ) | ( V_42 << 8 ) ;
}
for ( V_3 = 0 ; V_3 <= 0xfc ; V_3 += 4 )
F_1 ( V_2 , V_92 + V_3 , V_42 ) ;
}
static void F_43 ( struct V_1 * V_2 )
{
int V_93 ;
int V_69 ;
T_1 V_42 ;
F_1 ( V_2 , V_94 , 0 ) ;
F_1 ( V_2 , V_95 , 0 ) ;
F_1 ( V_2 , V_96 , 0 ) ;
F_1 ( V_2 , V_97 , 0 ) ;
F_1 ( V_2 , V_98 , 0 ) ;
F_1 ( V_2 , V_99 , 0 ) ;
F_1 ( V_2 , V_100 , 0 ) ;
F_1 ( V_2 , V_101 , 0x20 ) ;
for ( V_93 = 0 ; V_93 < V_102 ; V_93 ++ )
F_1 ( V_2 , F_44 ( V_93 ) ,
( V_103 |
V_104 ) ) ;
F_1 ( V_2 , V_105 , V_106 ) ;
F_1 ( V_2 , V_107 , V_108 ) ;
F_1 ( V_2 , V_109 , 0 ) ;
for ( V_69 = 0 ; V_69 < V_71 ; V_69 ++ ) {
F_1 ( V_2 , F_45 ( V_69 ) , 0 ) ;
F_1 ( V_2 , F_46 ( V_69 ) , 0 ) ;
}
F_1 ( V_2 , V_107 , 0 ) ;
F_1 ( V_2 , V_105 , 0 ) ;
V_42 = V_110 ;
F_1 ( V_2 , V_111 , V_42 ) ;
V_42 = F_47 ( V_112 ) ;
F_1 ( V_2 , V_113 , V_42 ) ;
V_42 = 0 ;
F_1 ( V_2 , V_114 , V_42 ) ;
F_1 ( V_2 , V_115 , 64 ) ;
V_42 = 0 ;
V_42 |= F_48 ( V_116 ) ;
V_42 |= F_49 ( V_116 ) ;
V_42 |= ( V_117 | V_118 |
V_119 ) ;
F_1 ( V_2 , V_120 , V_42 ) ;
F_40 ( V_2 , - 1 ) ;
F_41 ( V_2 , - 1 ) ;
F_42 ( V_2 , - 1 ) ;
F_1 ( V_2 , V_100 ,
( V_121
| V_122 ) ) ;
}
static void F_50 ( struct V_1 * V_2 , int V_123 )
{
T_1 V_42 , V_9 , V_124 ;
int V_69 ;
V_124 = V_123 * 8 ;
if ( V_124 > V_125 )
V_124 = V_125 ;
V_42 = F_3 ( V_2 , V_126 ) ;
V_42 &= ~ V_125 ;
V_42 |= V_124 ;
F_1 ( V_2 , V_126 , V_42 ) ;
V_42 = F_3 ( V_2 , V_127 ) ;
V_9 = V_42 & V_128 ;
if ( V_9 < V_124 ) {
V_9 = V_124 ;
V_42 &= ~ V_128 ;
V_42 |= V_9 ;
F_1 ( V_2 , V_127 , V_42 ) ;
}
for ( V_69 = 0 ; V_69 < V_71 ; V_69 ++ ) {
V_42 = F_3 ( V_2 , F_51 ( V_69 ) ) ;
V_9 = V_42 & V_129 ;
if ( V_9 < V_124 ) {
V_9 = V_124 ;
V_42 &= ~ V_129 ;
V_42 |= V_9 ;
F_1 ( V_2 , F_51 ( V_69 ) , V_42 ) ;
}
}
}
static void F_52 ( struct V_1 * V_2 , T_2 V_130 ,
int V_69 )
{
unsigned int V_131 ;
unsigned int V_132 ;
unsigned int V_133 ;
V_130 = ( 0xf & V_130 ) ;
V_132 = ( V_130 / 4 ) * 4 ;
V_133 = V_130 % 4 ;
V_131 = F_3 ( V_2 , ( V_89 + V_132 ) ) ;
if ( V_69 == - 1 ) {
V_131 &= ~ ( 0xff << ( 8 * V_133 ) ) ;
} else {
V_131 &= ~ ( 0xff << ( 8 * V_133 ) ) ;
V_131 |= ( ( 0x01 | ( V_69 << 1 ) ) << ( 8 * V_133 ) ) ;
}
F_1 ( V_2 , ( V_89 + V_132 ) , V_131 ) ;
}
static void F_53 ( struct V_1 * V_2 , unsigned char * V_134 ,
int V_69 )
{
unsigned int V_135 ;
unsigned int V_136 ;
if ( V_69 != - 1 ) {
V_136 = ( V_134 [ 4 ] << 8 ) | ( V_134 [ 5 ] ) ;
V_135 = ( V_134 [ 0 ] << 24 ) | ( V_134 [ 1 ] << 16 ) |
( V_134 [ 2 ] << 8 ) | ( V_134 [ 3 ] << 0 ) ;
F_1 ( V_2 , V_137 , V_136 ) ;
F_1 ( V_2 , V_138 , V_135 ) ;
}
F_52 ( V_2 , V_134 [ 5 ] , V_69 ) ;
}
static void F_54 ( struct V_1 * V_2 ,
struct V_36 * V_37 , T_1 V_139 )
{
F_1 ( V_2 , F_55 ( V_37 -> V_40 ) ,
V_139 | F_56 ( 0 ) ) ;
V_37 -> V_140 = V_139 ;
}
static void F_57 ( struct V_1 * V_2 ,
struct V_36 * V_37 , T_1 V_139 )
{
T_1 V_42 ;
unsigned long V_141 ;
V_141 = F_58 ( V_2 -> V_142 ) ;
V_42 = ( V_141 / 1000000 ) * V_139 ;
F_1 ( V_2 , F_59 ( V_37 -> V_40 ) , V_42 ) ;
V_37 -> V_143 = V_139 ;
}
static void F_60 ( struct V_1 * V_2 ,
struct V_6 * V_7 , T_1 V_139 )
{
T_1 V_42 ;
V_42 = F_3 ( V_2 , F_61 ( V_7 -> V_40 ) ) ;
V_42 &= ~ V_144 ;
V_42 |= F_62 ( V_139 ) ;
F_1 ( V_2 , F_61 ( V_7 -> V_40 ) , V_42 ) ;
V_7 -> V_145 = V_139 ;
}
static void F_63 ( struct V_1 * V_2 )
{
if ( F_64 ( V_146 , & V_2 -> V_147 ) == 0 ) {
V_2 -> V_148 . V_149 = V_150 +
F_65 ( V_151 ) ;
F_66 ( & V_2 -> V_148 ) ;
}
}
static void F_67 ( struct V_32 * V_46 ,
T_1 V_152 , T_1 V_153 )
{
V_46 -> V_154 = V_153 ;
V_46 -> V_155 = V_152 ;
}
static void F_68 ( struct V_1 * V_2 ,
struct V_6 * V_7 ,
int V_156 )
{
T_1 V_42 ;
while ( V_156 > 0xff ) {
V_42 = 0xff << V_157 ;
F_1 ( V_2 , F_25 ( V_7 -> V_40 ) , V_42 ) ;
V_156 = V_156 - 0xff ;
}
V_42 = V_156 << V_157 ;
F_1 ( V_2 , F_25 ( V_7 -> V_40 ) , V_42 ) ;
}
static int F_69 ( struct V_1 * V_2 ,
struct V_6 * V_7 )
{
T_1 V_42 ;
int V_156 ;
V_42 = F_3 ( V_2 , F_70 ( V_7 -> V_40 ) ) ;
V_156 = ( V_42 & V_158 ) >>
V_159 ;
return V_156 ;
}
static int F_71 ( struct V_1 * V_2 ,
struct V_6 * V_7 )
{
int V_156 ;
V_156 = F_69 ( V_2 , V_7 ) ;
if ( V_156 )
F_68 ( V_2 , V_7 , V_156 ) ;
return V_156 ;
}
static T_1 F_72 ( int V_160 , int V_161 ,
int V_162 , int V_163 )
{
T_1 V_164 ;
V_164 = V_160 << V_165 ;
V_164 |= V_162 << V_166 ;
if ( V_161 == F_73 ( V_167 ) )
V_164 |= V_168 ;
else
V_164 |= V_169 ;
if ( V_163 == V_170 )
V_164 |= V_171 ;
else if ( V_163 == V_172 )
V_164 |= V_173 | V_171 ;
else
V_164 |= V_174 ;
return V_164 ;
}
static void F_74 ( struct V_1 * V_2 ,
struct V_32 * V_46 )
{
T_1 V_34 = V_46 -> V_34 ;
if ( ! F_12 ( V_46 ) ) {
F_75 ( V_2 -> V_17 ,
L_4 ,
V_46 -> V_34 , V_46 -> V_175 ) ;
return;
}
switch ( V_34 & V_176 ) {
case V_177 :
F_75 ( V_2 -> V_17 , L_5 ,
V_34 , V_46 -> V_175 ) ;
break;
case V_178 :
F_75 ( V_2 -> V_17 , L_6 ,
V_34 , V_46 -> V_175 ) ;
break;
case V_179 :
F_75 ( V_2 -> V_17 , L_7 ,
V_34 , V_46 -> V_175 ) ;
break;
case V_180 :
F_75 ( V_2 -> V_17 , L_8 ,
V_34 , V_46 -> V_175 ) ;
break;
}
}
static void F_76 ( struct V_1 * V_2 ,
struct V_32 * V_46 ,
struct V_181 * V_182 )
{
if ( ( V_46 -> V_34 & V_183 ) &&
( V_46 -> V_34 & V_184 ) ) {
V_182 -> V_185 = 0 ;
V_182 -> V_186 = V_187 ;
return;
}
V_182 -> V_186 = V_188 ;
}
static struct V_6 * F_77 ( struct V_1 * V_2 ,
T_1 V_189 )
{
int V_69 = F_78 ( V_189 ) - 1 ;
return ( V_69 < 0 || V_69 >= V_71 ) ? NULL : & V_2 -> V_72 [ V_69 ] ;
}
static void F_79 ( struct V_1 * V_2 ,
struct V_6 * V_7 , int V_190 )
{
int V_11 ;
for ( V_11 = 0 ; V_11 < V_190 ; V_11 ++ ) {
struct V_56 * V_57 = V_7 -> V_48 +
V_7 -> V_8 ;
struct V_181 * V_182 = V_7 -> V_191 [ V_7 -> V_8 ] ;
F_5 ( V_7 ) ;
if ( ! V_182 )
continue;
F_80 ( V_2 -> V_17 -> V_17 . V_192 , V_57 -> V_155 ,
V_57 -> V_175 , V_193 ) ;
F_81 ( V_182 ) ;
}
}
static int F_82 ( struct V_1 * V_2 ,
struct V_6 * V_7 )
{
struct V_194 * V_195 = F_83 ( V_2 -> V_17 , V_7 -> V_40 ) ;
int V_196 ;
V_196 = F_71 ( V_2 , V_7 ) ;
if ( V_196 == 0 )
return V_196 ;
F_79 ( V_2 , V_7 , V_196 ) ;
V_7 -> V_77 -= V_196 ;
if ( F_84 ( V_195 ) ) {
if ( V_7 -> V_9 - V_7 -> V_77 >= V_197 + 1 )
F_85 ( V_195 ) ;
}
return V_196 ;
}
static int F_86 ( struct V_1 * V_2 ,
struct V_32 * V_46 )
{
T_3 V_152 ;
struct V_181 * V_182 ;
V_182 = F_87 ( V_2 -> V_17 , V_2 -> V_198 ) ;
if ( ! V_182 )
return - V_199 ;
V_152 = F_88 ( V_2 -> V_17 -> V_17 . V_192 , V_182 -> V_200 ,
F_89 ( V_2 -> V_198 ) ,
V_201 ) ;
if ( F_90 ( F_91 ( V_2 -> V_17 -> V_17 . V_192 , V_152 ) ) ) {
F_92 ( V_182 ) ;
return - V_199 ;
}
F_67 ( V_46 , V_152 , ( T_1 ) V_182 ) ;
return 0 ;
}
static T_1 F_93 ( struct V_1 * V_2 , struct V_181 * V_182 )
{
if ( V_182 -> V_186 == V_202 ) {
int V_162 = 0 ;
T_2 V_163 ;
if ( V_182 -> V_203 == F_94 ( V_167 ) ) {
struct V_204 * V_205 = F_95 ( V_182 ) ;
V_162 = V_205 -> V_206 ;
V_163 = V_205 -> V_203 ;
} else if ( V_182 -> V_203 == F_94 ( V_207 ) ) {
struct V_208 * V_209 = F_96 ( V_182 ) ;
if ( F_97 ( V_182 ) > 0 )
V_162 = ( F_97 ( V_182 ) >> 2 ) ;
V_163 = V_209 -> V_210 ;
} else
return V_174 ;
return F_72 ( F_98 ( V_182 ) ,
V_182 -> V_203 , V_162 , V_163 ) ;
}
return V_174 ;
}
static struct V_36 * F_99 ( struct V_1 * V_2 ,
T_1 V_189 )
{
int V_69 = F_78 ( V_189 >> 8 ) - 1 ;
return ( V_69 < 0 || V_69 >= V_74 ) ? NULL : & V_2 -> V_75 [ V_69 ] ;
}
static void F_100 ( struct V_1 * V_2 ,
struct V_36 * V_37 )
{
int V_44 , V_11 ;
V_44 = F_15 ( V_2 , V_37 ) ;
for ( V_11 = 0 ; V_11 < V_37 -> V_9 ; V_11 ++ ) {
struct V_32 * V_46 = V_37 -> V_48 + V_11 ;
struct V_181 * V_182 = (struct V_181 * ) V_46 -> V_154 ;
F_81 ( V_182 ) ;
F_80 ( V_2 -> V_17 -> V_17 . V_192 , V_46 -> V_155 ,
V_46 -> V_175 , V_201 ) ;
}
if ( V_44 )
F_17 ( V_2 , V_37 , V_44 , V_44 ) ;
}
static int F_101 ( struct V_1 * V_2 , int V_211 ,
struct V_36 * V_37 )
{
struct V_16 * V_17 = V_2 -> V_17 ;
int V_44 , V_45 ;
V_44 = F_15 ( V_2 , V_37 ) ;
if ( V_211 > V_44 )
V_211 = V_44 ;
V_44 = 0 ;
V_45 = 0 ;
while ( V_44 < V_211 ) {
struct V_32 * V_46 = F_18 ( V_37 ) ;
struct V_181 * V_182 ;
T_1 V_212 ;
int V_24 , V_213 ;
F_102 ( V_46 ) ;
V_44 ++ ;
V_45 ++ ;
V_212 = V_46 -> V_34 ;
V_182 = (struct V_181 * ) V_46 -> V_154 ;
if ( ! F_12 ( V_46 ) ||
( V_212 & V_214 ) ) {
V_17 -> V_18 . V_29 ++ ;
F_74 ( V_2 , V_46 ) ;
F_67 ( V_46 , V_46 -> V_155 ,
( T_1 ) V_182 ) ;
continue;
}
F_80 ( V_2 -> V_17 -> V_17 . V_192 , V_46 -> V_155 ,
V_46 -> V_175 , V_201 ) ;
V_24 = V_46 -> V_175 -
( V_215 + V_52 ) ;
F_103 ( & V_2 -> V_20 . V_21 ) ;
V_2 -> V_20 . V_23 ++ ;
V_2 -> V_20 . V_25 += V_24 ;
F_104 ( & V_2 -> V_20 . V_21 ) ;
F_105 ( V_182 , V_52 ) ;
F_106 ( V_182 , V_24 ) ;
V_182 -> V_203 = F_107 ( V_182 , V_17 ) ;
F_76 ( V_2 , V_46 , V_182 ) ;
F_108 ( & V_2 -> V_216 , V_182 ) ;
V_213 = F_86 ( V_2 , V_46 ) ;
if ( V_213 ) {
F_75 ( V_2 -> V_17 , L_9 ) ;
V_37 -> V_217 ++ ;
V_45 -- ;
}
}
F_17 ( V_2 , V_37 , V_44 , V_45 ) ;
return V_44 ;
}
static int F_109 ( struct V_1 * V_2 , struct V_181 * V_182 ,
struct V_6 * V_7 )
{
struct V_56 * V_57 ;
int V_11 ;
for ( V_11 = 0 ; V_11 < F_110 ( V_182 ) -> V_218 ; V_11 ++ ) {
T_4 * V_219 = & F_110 ( V_182 ) -> V_220 [ V_11 ] ;
void * V_134 = F_111 ( V_219 -> V_221 . V_222 ) + V_219 -> V_223 ;
V_57 = F_26 ( V_7 ) ;
V_57 -> V_175 = V_219 -> V_9 ;
V_57 -> V_155 =
F_88 ( V_2 -> V_17 -> V_17 . V_192 , V_134 ,
V_57 -> V_175 , V_193 ) ;
if ( F_91 ( V_2 -> V_17 -> V_17 . V_192 ,
V_57 -> V_155 ) ) {
F_27 ( V_7 ) ;
goto error;
}
if ( V_11 == ( F_110 ( V_182 ) -> V_218 - 1 ) ) {
V_57 -> V_164 = V_224 | V_225 ;
V_7 -> V_191 [ V_7 -> V_10 ] = V_182 ;
F_6 ( V_7 ) ;
} else {
V_57 -> V_164 = 0 ;
V_7 -> V_191 [ V_7 -> V_10 ] = NULL ;
F_6 ( V_7 ) ;
}
}
return 0 ;
error:
for ( V_11 = V_11 - 1 ; V_11 >= 0 ; V_11 -- ) {
V_57 = V_7 -> V_48 + V_11 ;
F_80 ( V_2 -> V_17 -> V_17 . V_192 ,
V_57 -> V_155 ,
V_57 -> V_175 ,
V_193 ) ;
F_27 ( V_7 ) ;
}
return - V_199 ;
}
static int F_112 ( struct V_181 * V_182 , struct V_16 * V_17 )
{
struct V_1 * V_2 = F_9 ( V_17 ) ;
T_5 V_226 = F_113 ( V_182 ) ;
struct V_6 * V_7 = & V_2 -> V_72 [ V_226 ] ;
struct V_56 * V_57 ;
struct V_194 * V_195 ;
int V_220 = 0 ;
T_1 V_227 ;
if ( ! F_114 ( V_17 ) )
goto V_228;
V_220 = F_110 ( V_182 ) -> V_218 + 1 ;
V_195 = F_83 ( V_17 , V_226 ) ;
V_57 = F_26 ( V_7 ) ;
V_227 = F_93 ( V_2 , V_182 ) ;
V_57 -> V_175 = F_115 ( V_182 ) ;
V_57 -> V_155 = F_88 ( V_17 -> V_17 . V_192 , V_182 -> V_4 ,
V_57 -> V_175 ,
V_193 ) ;
if ( F_90 ( F_91 ( V_17 -> V_17 . V_192 ,
V_57 -> V_155 ) ) ) {
F_27 ( V_7 ) ;
V_220 = 0 ;
goto V_228;
}
if ( V_220 == 1 ) {
V_227 |= V_229 ;
V_57 -> V_164 = V_227 ;
V_7 -> V_191 [ V_7 -> V_10 ] = V_182 ;
F_6 ( V_7 ) ;
} else {
V_227 |= V_230 ;
V_7 -> V_191 [ V_7 -> V_10 ] = NULL ;
F_6 ( V_7 ) ;
V_57 -> V_164 = V_227 ;
if ( F_109 ( V_2 , V_182 , V_7 ) ) {
F_80 ( V_17 -> V_17 . V_192 ,
V_57 -> V_155 ,
V_57 -> V_175 ,
V_193 ) ;
F_27 ( V_7 ) ;
V_220 = 0 ;
goto V_228;
}
}
V_7 -> V_77 += V_220 ;
F_24 ( V_2 , V_7 , V_220 ) ;
if ( V_7 -> V_9 - V_7 -> V_77 < V_197 + 1 )
F_116 ( V_195 ) ;
V_228:
if ( V_220 > 0 ) {
F_103 ( & V_2 -> V_26 . V_21 ) ;
V_2 -> V_26 . V_23 ++ ;
V_2 -> V_26 . V_25 += V_182 -> V_231 ;
F_104 ( & V_2 -> V_26 . V_21 ) ;
} else {
V_17 -> V_18 . V_31 ++ ;
F_81 ( V_182 ) ;
}
if ( V_7 -> V_77 >= V_232 )
F_82 ( V_2 , V_7 ) ;
if ( V_7 -> V_77 == V_220 && V_220 > 0 )
F_63 ( V_2 ) ;
return V_233 ;
}
static void F_117 ( struct V_1 * V_2 ,
struct V_6 * V_7 )
{
int V_196 = V_7 -> V_77 ;
F_79 ( V_2 , V_7 , V_196 ) ;
V_7 -> V_77 = 0 ;
V_7 -> V_10 = 0 ;
V_7 -> V_8 = 0 ;
}
static T_1 F_118 ( struct V_1 * V_2 , T_1 V_234 ,
int * V_235 )
{
struct V_6 * V_7 ;
T_1 V_196 = 0 ;
struct V_194 * V_195 ;
* V_235 = 0 ;
while ( V_234 != 0 ) {
V_7 = F_77 ( V_2 , V_234 ) ;
if ( ! V_7 )
break;
V_195 = F_83 ( V_2 -> V_17 , V_7 -> V_40 ) ;
F_119 ( V_195 , F_120 () ) ;
if ( V_7 -> V_77 ) {
V_196 += F_82 ( V_2 , V_7 ) ;
* V_235 += V_7 -> V_77 ;
}
F_121 ( V_195 ) ;
V_234 &= ~ ( ( 1 << V_7 -> V_40 ) ) ;
}
return V_196 ;
}
static int F_122 ( unsigned char * V_134 )
{
int V_236 = 0 ;
int V_11 ;
for ( V_11 = 0 ; V_11 < V_237 ; V_11 ++ ) {
int V_238 ;
V_236 = ( V_236 ^ V_134 [ V_11 ] ) << 8 ;
for ( V_238 = 7 ; V_238 >= 0 ; V_238 -- ) {
if ( V_236 & ( 0x100 << V_238 ) )
V_236 ^= 0x107 << V_238 ;
}
}
return V_236 ;
}
static void F_123 ( struct V_1 * V_2 ,
unsigned char V_239 ,
int V_69 )
{
unsigned int V_240 ;
unsigned int V_132 ;
unsigned int V_133 ;
V_132 = ( V_239 / 4 ) ;
V_133 = V_239 % 4 ;
V_240 = F_3 ( V_2 , ( V_90
+ V_132 * 4 ) ) ;
if ( V_69 == - 1 )
V_240 &= ~ ( 0xff << ( 8 * V_133 ) ) ;
else {
V_240 &= ~ ( 0xff << ( 8 * V_133 ) ) ;
V_240 |= ( ( 0x01 | ( V_69 << 1 ) ) << ( 8 * V_133 ) ) ;
}
F_1 ( V_2 , V_90 + V_132 * 4 ,
V_240 ) ;
}
static void F_124 ( struct V_1 * V_2 ,
unsigned char V_241 ,
int V_69 )
{
unsigned int V_242 ;
unsigned int V_132 ;
unsigned int V_133 ;
V_132 = ( V_241 / 4 ) * 4 ;
V_133 = V_241 % 4 ;
V_242 = F_3 ( V_2 , V_92 + V_132 ) ;
if ( V_69 == - 1 ) {
V_242 &= ~ ( 0xff << ( 8 * V_133 ) ) ;
} else {
V_242 &= ~ ( 0xff << ( 8 * V_133 ) ) ;
V_242 |= ( ( 0x01 | ( V_69 << 1 ) ) << ( 8 * V_133 ) ) ;
}
F_1 ( V_2 , V_92 + V_132 , V_242 ) ;
}
static int F_125 ( struct V_1 * V_2 , unsigned char * V_243 ,
int V_69 )
{
unsigned char V_244 = 0 ;
if ( memcmp ( V_243 , L_10 , 5 ) == 0 ) {
F_123 ( V_2 , V_243 [ 5 ] , V_69 ) ;
return 0 ;
}
V_244 = F_122 ( V_243 ) ;
if ( V_69 == - 1 ) {
if ( V_2 -> V_91 [ V_244 ] == 0 ) {
F_126 ( V_2 -> V_17 , L_11 ,
V_244 ) ;
return - V_245 ;
}
V_2 -> V_91 [ V_244 ] -- ;
if ( V_2 -> V_91 [ V_244 ] != 0 ) {
F_126 ( V_2 -> V_17 ,
L_12 ,
V_2 -> V_91 [ V_244 ] , V_244 ) ;
return - V_245 ;
}
} else
V_2 -> V_91 [ V_244 ] ++ ;
F_124 ( V_2 , V_244 , V_69 ) ;
return 0 ;
}
static void F_127 ( struct V_1 * V_2 ,
int V_246 )
{
T_1 V_247 , V_42 ;
V_247 = F_3 ( V_2 , V_113 ) ;
V_42 = F_3 ( V_2 , V_248 ) ;
if ( V_246 ) {
V_247 |= V_249 ;
V_42 |= V_250 ;
F_1 ( V_2 , V_137 , 0xffff ) ;
F_1 ( V_2 , V_138 , 0xffffffff ) ;
} else {
V_247 &= ~ V_249 ;
V_42 &= ~ V_250 ;
}
F_1 ( V_2 , V_113 , V_247 ) ;
F_1 ( V_2 , V_248 , V_42 ) ;
}
static void F_128 ( struct V_16 * V_17 )
{
struct V_1 * V_2 = F_9 ( V_17 ) ;
struct V_251 * V_252 ;
if ( V_17 -> V_147 & V_253 ) {
F_127 ( V_2 , 1 ) ;
F_40 ( V_2 , V_112 ) ;
F_41 ( V_2 , V_112 ) ;
F_42 ( V_2 , V_112 ) ;
} else {
F_127 ( V_2 , 0 ) ;
F_40 ( V_2 , - 1 ) ;
F_53 ( V_2 , V_17 -> V_254 , V_112 ) ;
if ( V_17 -> V_147 & V_255 ) {
F_41 ( V_2 , V_112 ) ;
F_42 ( V_2 , V_112 ) ;
} else {
F_41 ( V_2 , - 1 ) ;
F_42 ( V_2 , - 1 ) ;
if ( ! F_129 ( V_17 ) ) {
F_130 (ha, dev) {
F_125 ( V_2 , V_252 -> V_134 ,
V_112 ) ;
}
}
}
}
}
static T_6 F_131 ( int V_256 , void * V_257 )
{
struct V_1 * V_2 = (struct V_1 * ) V_257 ;
F_1 ( V_2 , V_97 , 0 ) ;
F_132 ( & V_2 -> V_216 ) ;
return V_258 ;
}
static int F_133 ( struct V_259 * V_216 , int V_260 )
{
int V_44 = 0 ;
T_1 V_261 ;
unsigned long V_147 ;
struct V_1 * V_2 = F_9 ( V_216 -> V_17 ) ;
if ( ! F_114 ( V_2 -> V_17 ) ) {
F_134 ( V_216 ) ;
return V_44 ;
}
V_261 = F_3 ( V_2 , V_94 ) &
F_135 ( V_74 ) ;
V_261 |= V_2 -> V_261 ;
if ( V_74 > 1 ) {
while ( ( V_261 != 0 ) && ( V_260 > 0 ) ) {
int V_77 ;
struct V_36 * V_37 ;
V_37 = F_99 ( V_2 , V_261 ) ;
if ( ! V_37 )
break;
V_77 = F_101 ( V_2 , V_260 , V_37 ) ;
V_44 += V_77 ;
V_260 -= V_77 ;
if ( V_260 > 0 ) {
V_261 &= ~ ( ( 1 << V_37 -> V_40 ) << 8 ) ;
}
}
} else {
V_44 = F_101 ( V_2 , V_260 , & V_2 -> V_75 [ V_112 ] ) ;
V_260 -= V_44 ;
}
if ( V_260 > 0 ) {
V_261 = 0 ;
F_134 ( V_216 ) ;
F_136 ( V_147 ) ;
F_1 ( V_2 , V_97 ,
F_135 ( V_74 ) ) ;
F_137 ( V_147 ) ;
}
V_2 -> V_261 = V_261 ;
return V_44 ;
}
static void F_138 ( unsigned long V_4 )
{
struct V_16 * V_17 = (struct V_16 * ) V_4 ;
struct V_1 * V_2 = F_9 ( V_17 ) ;
int V_196 = 0 , V_235 = 0 ;
if ( ! F_114 ( V_17 ) )
return ;
F_139 ( V_146 , & V_2 -> V_147 ) ;
V_196 = F_118 ( V_2 ,
( ( ( 1 << V_71 ) - 1 ) &
V_262 ) ,
& V_235 ) ;
if ( V_235 > 0 )
F_63 ( V_2 ) ;
}
static int F_140 ( struct V_1 * V_2 , struct V_36 * V_37 ,
int V_190 )
{
struct V_16 * V_17 = V_2 -> V_17 ;
int V_11 ;
for ( V_11 = 0 ; V_11 < V_190 ; V_11 ++ ) {
struct V_181 * V_182 ;
struct V_32 * V_46 ;
unsigned long V_152 ;
V_182 = F_141 ( V_2 -> V_198 ) ;
if ( ! V_182 ) {
F_75 ( V_17 , L_13 ,
V_263 , V_37 -> V_40 , V_11 , V_190 ) ;
break;
}
V_46 = V_37 -> V_48 + V_11 ;
memset ( V_46 , 0 , sizeof( struct V_32 ) ) ;
V_152 = F_88 ( V_17 -> V_17 . V_192 , V_182 -> V_200 ,
F_89 ( V_2 -> V_198 ) ,
V_201 ) ;
if ( F_90 ( F_91 ( V_17 -> V_17 . V_192 , V_152 ) ) ) {
F_92 ( V_182 ) ;
break;
}
F_67 ( V_46 , V_152 , ( T_1 ) V_182 ) ;
}
F_13 ( V_2 , V_37 , V_11 ) ;
return V_11 ;
}
static void F_142 ( struct V_1 * V_2 )
{
int V_69 ;
for ( V_69 = 0 ; V_69 < V_71 ; V_69 ++ )
F_117 ( V_2 , & V_2 -> V_72 [ V_69 ] ) ;
F_1 ( V_2 , V_107 , V_108 ) ;
F_1 ( V_2 , V_107 , 0 ) ;
}
static void F_143 ( struct V_1 * V_2 )
{
F_1 ( V_2 , V_105 , V_106 ) ;
F_1 ( V_2 , V_105 , 0 ) ;
}
static int F_144 ( struct V_1 * V_2 ,
struct V_36 * V_37 )
{
V_37 -> V_9 = V_2 -> V_264 ;
V_37 -> V_48 = F_145 ( V_2 -> V_17 -> V_17 . V_192 ,
V_37 -> V_9 * V_265 ,
& V_37 -> V_266 , V_267 ) ;
if ( V_37 -> V_48 == NULL )
return - V_199 ;
F_146 ( V_37 -> V_48 !=
F_147 ( V_37 -> V_48 , V_268 ) ) ;
V_37 -> V_58 = V_37 -> V_9 - 1 ;
F_1 ( V_2 , F_148 ( V_37 -> V_40 ) , V_37 -> V_266 ) ;
F_1 ( V_2 , F_29 ( V_37 -> V_40 ) , V_37 -> V_9 ) ;
F_21 ( V_2 , V_37 , V_269 ) ;
F_54 ( V_2 , V_37 , V_37 -> V_140 ) ;
F_57 ( V_2 , V_37 , V_37 -> V_143 ) ;
F_28 ( V_2 , V_37 , F_89 ( V_2 -> V_198 ) ) ;
F_30 ( V_2 , V_37 ) ;
F_140 ( V_2 , V_37 , V_37 -> V_9 ) ;
return 0 ;
}
static void F_149 ( struct V_1 * V_2 ,
struct V_36 * V_37 )
{
F_100 ( V_2 , V_37 ) ;
if ( V_37 -> V_48 )
F_150 ( V_2 -> V_17 -> V_17 . V_192 ,
V_37 -> V_9 * V_265 ,
V_37 -> V_48 ,
V_37 -> V_266 ) ;
V_37 -> V_48 = NULL ;
V_37 -> V_58 = 0 ;
V_37 -> V_47 = 0 ;
V_37 -> V_266 = 0 ;
}
static int F_151 ( struct V_1 * V_2 ,
struct V_6 * V_7 )
{
V_7 -> V_9 = V_2 -> V_270 ;
V_7 -> V_48 = F_145 ( V_2 -> V_17 -> V_17 . V_192 ,
V_7 -> V_9 * V_265 ,
& V_7 -> V_266 , V_267 ) ;
if ( V_7 -> V_48 == NULL )
return - V_199 ;
F_146 ( V_7 -> V_48 !=
F_147 ( V_7 -> V_48 , V_268 ) ) ;
V_7 -> V_58 = V_7 -> V_9 - 1 ;
F_1 ( V_2 , F_46 ( V_7 -> V_40 ) , 0x03ffffff ) ;
F_1 ( V_2 , F_45 ( V_7 -> V_40 ) , 0x3fffffff ) ;
F_1 ( V_2 , F_152 ( V_7 -> V_40 ) , V_7 -> V_266 ) ;
F_1 ( V_2 , F_61 ( V_7 -> V_40 ) , V_7 -> V_9 ) ;
V_7 -> V_191 = F_153 ( V_7 -> V_9 * sizeof( * V_7 -> V_191 ) , V_267 ) ;
if ( V_7 -> V_191 == NULL ) {
F_150 ( V_2 -> V_17 -> V_17 . V_192 ,
V_7 -> V_9 * V_265 ,
V_7 -> V_48 , V_7 -> V_266 ) ;
return - V_199 ;
}
F_60 ( V_2 , V_7 , V_7 -> V_145 ) ;
return 0 ;
}
static void F_154 ( struct V_1 * V_2 ,
struct V_6 * V_7 )
{
F_155 ( V_7 -> V_191 ) ;
if ( V_7 -> V_48 )
F_150 ( V_2 -> V_17 -> V_17 . V_192 ,
V_7 -> V_9 * V_265 ,
V_7 -> V_48 , V_7 -> V_266 ) ;
V_7 -> V_48 = NULL ;
V_7 -> V_58 = 0 ;
V_7 -> V_47 = 0 ;
V_7 -> V_266 = 0 ;
F_1 ( V_2 , F_46 ( V_7 -> V_40 ) , 0 ) ;
F_1 ( V_2 , F_45 ( V_7 -> V_40 ) , 0 ) ;
F_1 ( V_2 , F_152 ( V_7 -> V_40 ) , 0 ) ;
F_1 ( V_2 , F_61 ( V_7 -> V_40 ) , 0 ) ;
}
static void F_156 ( struct V_1 * V_2 )
{
int V_69 ;
for ( V_69 = 0 ; V_69 < V_71 ; V_69 ++ )
F_154 ( V_2 , & V_2 -> V_72 [ V_69 ] ) ;
}
static void F_157 ( struct V_1 * V_2 )
{
int V_69 ;
for ( V_69 = 0 ; V_69 < V_74 ; V_69 ++ )
F_149 ( V_2 , & V_2 -> V_75 [ V_69 ] ) ;
}
static int F_158 ( struct V_1 * V_2 )
{
int V_69 ;
for ( V_69 = 0 ; V_69 < V_74 ; V_69 ++ ) {
int V_213 = F_144 ( V_2 , & V_2 -> V_75 [ V_69 ] ) ;
if ( V_213 ) {
F_75 ( V_2 -> V_17 , L_14 ,
V_263 , V_69 ) ;
F_157 ( V_2 ) ;
return V_213 ;
}
}
return 0 ;
}
static int F_159 ( struct V_1 * V_2 )
{
int V_69 ;
for ( V_69 = 0 ; V_69 < V_71 ; V_69 ++ ) {
int V_213 = F_151 ( V_2 , & V_2 -> V_72 [ V_69 ] ) ;
if ( V_213 ) {
F_75 ( V_2 -> V_17 , L_15 ,
V_263 , V_69 ) ;
F_156 ( V_2 ) ;
return V_213 ;
}
}
return 0 ;
}
static void F_160 ( struct V_1 * V_2 )
{
F_20 ( V_2 , V_2 -> V_198 ) ;
F_50 ( V_2 , V_2 -> V_198 ) ;
F_38 ( V_2 ) ;
F_161 ( & V_2 -> V_216 ) ;
F_1 ( V_2 , V_97 ,
F_135 ( V_74 ) ) ;
F_162 ( V_2 -> V_271 ) ;
F_163 ( V_2 -> V_17 ) ;
}
static void F_164 ( struct V_1 * V_2 )
{
F_165 ( V_2 -> V_271 ) ;
F_166 ( & V_2 -> V_216 ) ;
F_167 ( V_2 -> V_17 ) ;
F_34 ( V_2 ) ;
F_168 ( V_2 -> V_17 ) ;
F_39 ( V_2 ) ;
F_1 ( V_2 , V_96 , 0 ) ;
F_1 ( V_2 , V_95 , 0 ) ;
F_1 ( V_2 , V_97 , 0 ) ;
F_1 ( V_2 , V_98 , 0 ) ;
F_1 ( V_2 , V_99 , 0 ) ;
F_142 ( V_2 ) ;
F_143 ( V_2 ) ;
}
static void F_169 ( struct V_16 * V_17 )
{
struct V_1 * V_2 = F_9 ( V_17 ) ;
F_126 ( V_17 , L_16 ) ;
F_164 ( V_2 ) ;
F_160 ( V_2 ) ;
}
static int F_170 ( struct V_16 * V_17 , int V_124 )
{
if ( V_124 < 68 ) {
F_75 ( V_17 , L_17 ) ;
return - V_245 ;
}
if ( V_124 > 9676 ) {
F_126 ( V_17 , L_18 , V_124 ) ;
V_124 = 9676 ;
}
if ( ! F_171 ( F_172 ( V_124 ) , 8 ) ) {
F_126 ( V_17 , L_19 ,
V_124 , F_173 ( F_172 ( V_124 ) , 8 ) ) ;
V_124 = F_173 ( F_172 ( V_124 ) , 8 ) ;
}
return V_124 ;
}
static int F_174 ( struct V_16 * V_17 , int V_124 )
{
struct V_1 * V_2 = F_9 ( V_17 ) ;
int V_272 ;
V_124 = F_170 ( V_17 , V_124 ) ;
if ( V_124 < 0 )
return - V_245 ;
V_17 -> V_124 = V_124 ;
if ( ! F_114 ( V_17 ) )
return 0 ;
F_164 ( V_2 ) ;
F_156 ( V_2 ) ;
F_157 ( V_2 ) ;
V_2 -> V_198 = F_172 ( V_2 -> V_17 -> V_124 ) ;
V_272 = F_158 ( V_2 ) ;
if ( V_272 ) {
F_75 ( V_2 -> V_17 , L_20 ) ;
return V_272 ;
}
F_159 ( V_2 ) ;
F_160 ( V_2 ) ;
F_33 ( V_2 ) ;
return 0 ;
}
static void F_175 ( struct V_1 * V_2 , unsigned char * V_134 )
{
T_1 V_273 , V_274 ;
V_273 = F_3 ( V_2 , V_137 ) ;
V_274 = F_3 ( V_2 , V_138 ) ;
V_134 [ 0 ] = ( V_274 >> 24 ) & 0xFF ;
V_134 [ 1 ] = ( V_274 >> 16 ) & 0xFF ;
V_134 [ 2 ] = ( V_274 >> 8 ) & 0xFF ;
V_134 [ 3 ] = V_274 & 0xFF ;
V_134 [ 4 ] = ( V_273 >> 8 ) & 0xFF ;
V_134 [ 5 ] = V_273 & 0xFF ;
}
static int F_176 ( struct V_16 * V_17 , void * V_134 )
{
struct V_1 * V_2 = F_9 ( V_17 ) ;
T_2 * V_275 = V_134 + 2 ;
int V_11 ;
if ( F_114 ( V_17 ) )
return - V_276 ;
F_53 ( V_2 , V_17 -> V_254 , - 1 ) ;
F_53 ( V_2 , V_275 , V_112 ) ;
for ( V_11 = 0 ; V_11 < V_237 ; V_11 ++ )
V_17 -> V_254 [ V_11 ] = V_275 [ V_11 ] ;
return 0 ;
}
static void F_177 ( struct V_16 * V_277 )
{
struct V_1 * V_2 = F_9 ( V_277 ) ;
struct V_278 * V_279 = V_2 -> V_271 ;
int V_280 = 0 ;
if ( V_279 -> V_281 ) {
if ( ( V_2 -> V_282 != V_279 -> V_282 ) ||
( V_2 -> V_283 != V_279 -> V_283 ) ) {
T_1 V_42 ;
V_42 = F_3 ( V_2 , V_284 ) ;
V_42 &= ~ ( V_285 |
V_286 |
V_287 ) ;
if ( V_279 -> V_283 )
V_42 |= V_287 ;
if ( V_279 -> V_282 == V_288 )
V_42 |= V_286 ;
else
V_42 |= V_285 ;
F_1 ( V_2 , V_284 , V_42 ) ;
V_2 -> V_283 = V_279 -> V_283 ;
V_2 -> V_282 = V_279 -> V_282 ;
}
}
if ( V_279 -> V_281 != V_2 -> V_281 ) {
if ( ! V_279 -> V_281 ) {
V_2 -> V_283 = - 1 ;
V_2 -> V_282 = 0 ;
}
V_2 -> V_281 = V_279 -> V_281 ;
V_280 = 1 ;
}
if ( V_280 ) {
if ( V_279 -> V_281 ) {
T_1 V_42 = F_3 ( V_2 , V_284 ) ;
V_42 |= ( V_289 |
V_290 ) ;
F_1 ( V_2 , V_284 , V_42 ) ;
F_33 ( V_2 ) ;
F_126 ( V_2 -> V_17 , L_21 ) ;
} else {
F_34 ( V_2 ) ;
F_126 ( V_2 -> V_17 , L_22 ) ;
}
}
}
static int F_178 ( struct V_1 * V_2 )
{
struct V_278 * V_271 ;
V_271 = F_179 ( V_2 -> V_17 , V_2 -> V_291 , F_177 , 0 ,
V_2 -> V_292 ) ;
if ( ! V_271 ) {
F_75 ( V_2 -> V_17 , L_23 ) ;
return - V_293 ;
}
V_271 -> V_294 &= V_295 ;
V_271 -> V_296 = V_271 -> V_294 ;
V_2 -> V_271 = V_271 ;
V_2 -> V_281 = 0 ;
V_2 -> V_283 = 0 ;
V_2 -> V_282 = 0 ;
return 0 ;
}
static void F_180 ( struct V_1 * V_2 )
{
F_181 ( V_2 -> V_271 ) ;
V_2 -> V_271 = NULL ;
}
static int F_182 ( struct V_16 * V_17 )
{
struct V_1 * V_2 = F_9 ( V_17 ) ;
int V_272 ;
F_53 ( V_2 , V_17 -> V_254 , V_112 ) ;
V_2 -> V_198 = F_172 ( V_2 -> V_17 -> V_124 ) ;
V_272 = F_158 ( V_2 ) ;
if ( V_272 )
return V_272 ;
V_272 = F_159 ( V_2 ) ;
if ( V_272 )
goto V_297;
V_272 = F_183 ( V_2 -> V_17 -> V_256 , F_131 , 0 ,
V_298 , V_2 ) ;
if ( V_272 ) {
F_75 ( V_2 -> V_17 , L_24 , V_2 -> V_17 -> V_256 ) ;
goto V_299;
}
F_167 ( V_2 -> V_17 ) ;
V_272 = F_178 ( V_2 ) ;
if ( V_272 < 0 ) {
F_75 ( V_17 , L_25 ) ;
goto V_300;
}
F_160 ( V_2 ) ;
return 0 ;
V_300:
F_184 ( V_2 -> V_17 -> V_256 , V_2 ) ;
V_299:
F_156 ( V_2 ) ;
V_297:
F_157 ( V_2 ) ;
return V_272 ;
}
static int F_185 ( struct V_16 * V_17 )
{
struct V_1 * V_2 = F_9 ( V_17 ) ;
F_164 ( V_2 ) ;
F_180 ( V_2 ) ;
F_184 ( V_17 -> V_256 , V_2 ) ;
F_157 ( V_2 ) ;
F_156 ( V_2 ) ;
F_186 ( & V_2 -> V_148 ) ;
F_139 ( V_146 , & V_2 -> V_147 ) ;
return 0 ;
}
int F_187 ( struct V_16 * V_17 , struct V_301 * V_302 )
{
struct V_1 * V_2 = F_9 ( V_17 ) ;
if ( ! V_2 -> V_271 )
return - V_293 ;
return F_188 ( V_2 -> V_271 , V_302 ) ;
}
int F_189 ( struct V_16 * V_17 , struct V_301 * V_302 )
{
struct V_1 * V_2 = F_9 ( V_17 ) ;
if ( ! V_2 -> V_271 )
return - V_293 ;
return F_190 ( V_2 -> V_271 , V_302 ) ;
}
static int F_191 ( struct V_16 * V_17 ,
struct V_303 * V_304 )
{
struct V_1 * V_2 = F_9 ( V_17 ) ;
int V_69 ;
for ( V_69 = 0 ; V_69 < V_74 ; V_69 ++ ) {
struct V_36 * V_37 = & V_2 -> V_75 [ V_69 ] ;
V_37 -> V_143 = V_304 -> V_305 ;
V_37 -> V_140 = V_304 -> V_306 ;
F_54 ( V_2 , V_37 , V_37 -> V_140 ) ;
F_57 ( V_2 , V_37 , V_37 -> V_143 ) ;
}
for ( V_69 = 0 ; V_69 < V_71 ; V_69 ++ ) {
struct V_6 * V_7 = & V_2 -> V_72 [ V_69 ] ;
V_7 -> V_145 = V_304 -> V_307 ;
F_60 ( V_2 , V_7 , V_7 -> V_145 ) ;
}
return 0 ;
}
static int F_192 ( struct V_16 * V_17 ,
struct V_303 * V_304 )
{
struct V_1 * V_2 = F_9 ( V_17 ) ;
V_304 -> V_305 = V_2 -> V_75 [ 0 ] . V_143 ;
V_304 -> V_306 = V_2 -> V_75 [ 0 ] . V_140 ;
V_304 -> V_307 = V_2 -> V_72 [ 0 ] . V_145 ;
return 0 ;
}
static void F_193 ( struct V_16 * V_17 ,
struct V_308 * V_309 )
{
F_194 ( V_309 -> V_310 , V_298 ,
sizeof( V_309 -> V_310 ) ) ;
F_194 ( V_309 -> V_311 , V_312 ,
sizeof( V_309 -> V_311 ) ) ;
F_194 ( V_309 -> V_313 , F_195 ( & V_17 -> V_17 ) ,
sizeof( V_309 -> V_313 ) ) ;
}
static void F_196 ( struct V_16 * V_314 ,
struct V_315 * V_316 )
{
struct V_1 * V_2 = F_9 ( V_314 ) ;
V_316 -> V_317 = V_318 ;
V_316 -> V_319 = V_320 ;
V_316 -> V_321 = V_2 -> V_264 ;
V_316 -> V_322 = V_2 -> V_270 ;
}
static int F_197 ( struct V_16 * V_17 ,
struct V_315 * V_316 )
{
struct V_1 * V_2 = F_9 ( V_17 ) ;
if ( ( V_316 -> V_321 == 0 ) || ( V_316 -> V_322 == 0 ) )
return - V_245 ;
V_2 -> V_264 = V_316 -> V_321 < V_318 ?
V_316 -> V_321 : V_318 ;
V_2 -> V_270 = V_316 -> V_322 < V_320 ?
V_316 -> V_322 : V_320 ;
if ( F_114 ( V_17 ) ) {
F_185 ( V_17 ) ;
if ( F_182 ( V_17 ) ) {
F_75 ( V_17 ,
L_26 ) ;
return - V_199 ;
}
}
return 0 ;
}
static int F_198 ( struct V_1 * V_2 , int V_323 )
{
int V_69 ;
F_39 ( V_2 ) ;
F_43 ( V_2 ) ;
V_2 -> V_72 = F_199 ( V_71 * sizeof( struct V_6 ) ,
V_267 ) ;
if ( ! V_2 -> V_72 )
return - V_199 ;
for ( V_69 = 0 ; V_69 < V_71 ; V_69 ++ ) {
struct V_6 * V_7 = & V_2 -> V_72 [ V_69 ] ;
V_7 -> V_40 = V_69 ;
V_7 -> V_9 = V_2 -> V_270 ;
V_7 -> V_145 = V_232 ;
}
V_2 -> V_75 = F_199 ( V_74 * sizeof( struct V_36 ) ,
V_267 ) ;
if ( ! V_2 -> V_75 ) {
F_155 ( V_2 -> V_72 ) ;
return - V_199 ;
}
for ( V_69 = 0 ; V_69 < V_74 ; V_69 ++ ) {
struct V_36 * V_37 = & V_2 -> V_75 [ V_69 ] ;
V_37 -> V_40 = V_69 ;
V_37 -> V_9 = V_2 -> V_264 ;
V_37 -> V_140 = V_324 ;
V_37 -> V_143 = V_325 ;
}
return 0 ;
}
static void F_200 ( struct V_1 * V_2 )
{
F_155 ( V_2 -> V_72 ) ;
F_155 ( V_2 -> V_75 ) ;
}
static void F_201 ( struct V_1 * V_2 ,
const struct V_326 * V_327 )
{
T_1 V_328 ;
T_1 V_329 ;
int V_11 ;
for ( V_11 = 0 ; V_11 < 6 ; V_11 ++ ) {
F_1 ( V_2 , F_202 ( V_11 ) , 0 ) ;
F_1 ( V_2 , F_203 ( V_11 ) , 0 ) ;
if ( V_11 < 4 )
F_1 ( V_2 , F_204 ( V_11 ) , 0 ) ;
}
V_328 = 0x3f ;
V_329 = 0 ;
for ( V_11 = 0 ; V_11 < V_327 -> V_330 ; V_11 ++ ) {
const struct V_331 * V_332 = V_327 -> V_332 + V_11 ;
F_1 ( V_2 , F_202 ( V_11 ) , ( V_332 -> V_5 & 0xffff0000 ) |
( V_332 -> V_333 << 8 ) | V_327 -> V_334 ) ;
F_1 ( V_2 , F_203 ( V_11 ) ,
( V_332 -> V_9 - 1 ) & 0xffff0000 ) ;
V_328 &= ~ ( 1 << V_11 ) ;
V_329 |= 3 << ( 2 * V_11 ) ;
}
F_1 ( V_2 , V_335 , V_328 ) ;
}
static void F_205 ( struct V_1 * V_2 , int V_336 )
{
T_1 V_42 ;
F_1 ( V_2 , V_337 , 0 ) ;
if ( V_336 == V_338 )
F_32 ( V_2 ) ;
F_31 ( V_2 , 1 ) ;
V_42 = F_3 ( V_2 , V_64 ) ;
V_42 &= ~ V_339 ;
F_1 ( V_2 , V_64 , V_42 ) ;
while ( ( F_3 ( V_2 , V_64 ) &
V_339 ) != 0 )
continue;
}
static int F_206 ( struct V_340 * V_341 )
{
const struct V_326 * V_342 ;
struct V_343 * V_344 = V_341 -> V_17 . V_345 ;
struct V_343 * V_291 ;
T_1 V_323 ;
struct V_1 * V_2 ;
struct V_16 * V_17 ;
const char * V_346 ;
char V_347 [ V_237 ] ;
const char * V_348 ;
int V_336 ;
int V_213 ;
if ( V_112 != 0 ) {
F_207 ( & V_341 -> V_17 , L_27 , V_112 ) ;
return - V_245 ;
}
V_17 = F_208 ( sizeof( struct V_1 ) , V_71 , V_74 ) ;
if ( ! V_17 )
return - V_199 ;
V_17 -> V_256 = F_209 ( V_344 , 0 ) ;
if ( V_17 -> V_256 == 0 ) {
V_213 = - V_245 ;
goto V_349;
}
V_291 = F_210 ( V_344 , L_28 , 0 ) ;
if ( ! V_291 ) {
F_207 ( & V_341 -> V_17 , L_29 ) ;
V_213 = - V_293 ;
goto V_300;
}
V_336 = F_211 ( V_344 ) ;
if ( V_336 < 0 ) {
F_207 ( & V_341 -> V_17 , L_30 ) ;
V_213 = - V_245 ;
goto V_300;
}
V_17 -> V_350 = V_320 ;
V_17 -> V_351 = 5 * V_352 ;
V_17 -> V_353 = & V_354 ;
F_212 ( V_17 , & V_355 ) ;
V_2 = F_9 ( V_17 ) ;
V_2 -> V_356 = V_357 ;
V_2 -> V_291 = V_291 ;
V_2 -> V_292 = V_336 ;
V_2 -> V_142 = F_213 ( & V_341 -> V_17 , NULL ) ;
if ( F_214 ( V_2 -> V_142 ) ) {
V_213 = F_215 ( V_2 -> V_142 ) ;
goto V_300;
}
F_216 ( V_2 -> V_142 ) ;
V_2 -> V_5 = F_217 ( V_344 , 0 ) ;
if ( V_2 -> V_5 == NULL ) {
V_213 = - V_199 ;
goto V_358;
}
V_346 = F_218 ( V_344 ) ;
if ( V_346 && F_219 ( V_346 ) ) {
V_348 = L_31 ;
memcpy ( V_17 -> V_254 , V_346 , V_237 ) ;
} else {
F_175 ( V_2 , V_347 ) ;
if ( F_219 ( V_347 ) ) {
V_348 = L_32 ;
memcpy ( V_17 -> V_254 , V_347 , V_237 ) ;
} else {
V_348 = L_33 ;
F_220 ( V_17 ) ;
}
}
V_2 -> V_148 . V_4 = ( unsigned long ) V_17 ;
V_2 -> V_148 . V_359 = F_138 ;
F_221 ( & V_2 -> V_148 ) ;
F_139 ( V_146 , & V_2 -> V_147 ) ;
V_2 -> V_270 = V_320 ;
V_2 -> V_264 = V_318 ;
V_2 -> V_17 = V_17 ;
F_222 ( V_17 , & V_341 -> V_17 ) ;
V_213 = F_198 ( V_2 , V_323 ) ;
if ( V_213 < 0 ) {
F_207 ( & V_341 -> V_17 , L_34 ) ;
goto V_360;
}
F_205 ( V_2 , V_336 ) ;
V_342 = F_223 () ;
if ( V_342 )
F_201 ( V_2 , V_342 ) ;
F_224 ( V_17 , & V_2 -> V_216 , F_133 , V_2 -> V_356 ) ;
V_17 -> V_361 = V_362 | V_363 ;
V_17 -> V_364 |= V_362 | V_363 ;
V_17 -> V_365 |= V_362 | V_363 ;
V_17 -> V_366 |= V_367 ;
V_213 = F_225 ( V_17 ) ;
if ( V_213 < 0 ) {
F_207 ( & V_341 -> V_17 , L_35 ) ;
goto V_368;
}
F_126 ( V_17 , L_36 , V_348 ,
V_17 -> V_254 ) ;
F_226 ( V_341 , V_2 -> V_17 ) ;
return 0 ;
V_368:
F_200 ( V_2 ) ;
V_360:
F_227 ( V_2 -> V_5 ) ;
V_358:
F_228 ( V_2 -> V_142 ) ;
V_300:
F_229 ( V_17 -> V_256 ) ;
V_349:
F_230 ( V_17 ) ;
return V_213 ;
}
static int F_231 ( struct V_340 * V_341 )
{
struct V_16 * V_17 = F_232 ( V_341 ) ;
struct V_1 * V_2 = F_9 ( V_17 ) ;
F_233 ( V_17 ) ;
F_200 ( V_2 ) ;
F_228 ( V_2 -> V_142 ) ;
F_227 ( V_2 -> V_5 ) ;
F_229 ( V_17 -> V_256 ) ;
F_230 ( V_17 ) ;
return 0 ;
}
