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
V_42 |= V_117 | V_118 ;
#if F_50 ( V_119 )
V_42 |= V_120 ;
#endif
F_1 ( V_2 , V_121 , V_42 ) ;
V_42 = F_3 ( V_2 , V_122 ) ;
V_42 &= ~ V_123 ;
F_1 ( V_2 , V_122 , V_42 ) ;
F_40 ( V_2 , - 1 ) ;
F_41 ( V_2 , - 1 ) ;
F_42 ( V_2 , - 1 ) ;
F_1 ( V_2 , V_100 ,
( V_124
| V_125 ) ) ;
}
static void F_51 ( struct V_1 * V_2 , int V_126 )
{
T_1 V_42 , V_9 , V_127 ;
int V_69 ;
V_127 = V_126 * 8 ;
if ( V_127 > V_128 )
V_127 = V_128 ;
V_42 = F_3 ( V_2 , V_129 ) ;
V_42 &= ~ V_128 ;
V_42 |= V_127 ;
F_1 ( V_2 , V_129 , V_42 ) ;
V_42 = F_3 ( V_2 , V_130 ) ;
V_9 = V_42 & V_131 ;
if ( V_9 < V_127 ) {
V_9 = V_127 ;
V_42 &= ~ V_131 ;
V_42 |= V_9 ;
F_1 ( V_2 , V_130 , V_42 ) ;
}
for ( V_69 = 0 ; V_69 < V_71 ; V_69 ++ ) {
V_42 = F_3 ( V_2 , F_52 ( V_69 ) ) ;
V_9 = V_42 & V_132 ;
if ( V_9 < V_127 ) {
V_9 = V_127 ;
V_42 &= ~ V_132 ;
V_42 |= V_9 ;
F_1 ( V_2 , F_52 ( V_69 ) , V_42 ) ;
}
}
}
static void F_53 ( struct V_1 * V_2 , T_2 V_133 ,
int V_69 )
{
unsigned int V_134 ;
unsigned int V_135 ;
unsigned int V_136 ;
V_133 = ( 0xf & V_133 ) ;
V_135 = ( V_133 / 4 ) * 4 ;
V_136 = V_133 % 4 ;
V_134 = F_3 ( V_2 , ( V_89 + V_135 ) ) ;
if ( V_69 == - 1 ) {
V_134 &= ~ ( 0xff << ( 8 * V_136 ) ) ;
} else {
V_134 &= ~ ( 0xff << ( 8 * V_136 ) ) ;
V_134 |= ( ( 0x01 | ( V_69 << 1 ) ) << ( 8 * V_136 ) ) ;
}
F_1 ( V_2 , ( V_89 + V_135 ) , V_134 ) ;
}
static void F_54 ( struct V_1 * V_2 , unsigned char * V_137 ,
int V_69 )
{
unsigned int V_138 ;
unsigned int V_139 ;
if ( V_69 != - 1 ) {
V_139 = ( V_137 [ 4 ] << 8 ) | ( V_137 [ 5 ] ) ;
V_138 = ( V_137 [ 0 ] << 24 ) | ( V_137 [ 1 ] << 16 ) |
( V_137 [ 2 ] << 8 ) | ( V_137 [ 3 ] << 0 ) ;
F_1 ( V_2 , V_140 , V_139 ) ;
F_1 ( V_2 , V_141 , V_138 ) ;
}
F_53 ( V_2 , V_137 [ 5 ] , V_69 ) ;
}
static void F_55 ( struct V_1 * V_2 ,
struct V_36 * V_37 , T_1 V_142 )
{
F_1 ( V_2 , F_56 ( V_37 -> V_40 ) ,
V_142 | F_57 ( 0 ) ) ;
V_37 -> V_143 = V_142 ;
}
static void F_58 ( struct V_1 * V_2 ,
struct V_36 * V_37 , T_1 V_142 )
{
T_1 V_42 ;
unsigned long V_144 ;
V_144 = F_59 ( V_2 -> V_145 ) ;
V_42 = ( V_144 / 1000000 ) * V_142 ;
F_1 ( V_2 , F_60 ( V_37 -> V_40 ) , V_42 ) ;
V_37 -> V_146 = V_142 ;
}
static void F_61 ( struct V_1 * V_2 ,
struct V_6 * V_7 , T_1 V_142 )
{
T_1 V_42 ;
V_42 = F_3 ( V_2 , F_62 ( V_7 -> V_40 ) ) ;
V_42 &= ~ V_147 ;
V_42 |= F_63 ( V_142 ) ;
F_1 ( V_2 , F_62 ( V_7 -> V_40 ) , V_42 ) ;
V_7 -> V_148 = V_142 ;
}
static void F_64 ( struct V_1 * V_2 )
{
if ( F_65 ( V_149 , & V_2 -> V_150 ) == 0 ) {
V_2 -> V_151 . V_152 = V_153 +
F_66 ( V_154 ) ;
F_67 ( & V_2 -> V_151 ) ;
}
}
static void F_68 ( struct V_32 * V_46 ,
T_1 V_155 , T_1 V_156 )
{
V_46 -> V_157 = V_156 ;
V_46 -> V_158 = V_155 ;
}
static void F_69 ( struct V_1 * V_2 ,
struct V_6 * V_7 ,
int V_159 )
{
T_1 V_42 ;
while ( V_159 > 0xff ) {
V_42 = 0xff << V_160 ;
F_1 ( V_2 , F_25 ( V_7 -> V_40 ) , V_42 ) ;
V_159 = V_159 - 0xff ;
}
V_42 = V_159 << V_160 ;
F_1 ( V_2 , F_25 ( V_7 -> V_40 ) , V_42 ) ;
}
static int F_70 ( struct V_1 * V_2 ,
struct V_6 * V_7 )
{
T_1 V_42 ;
int V_159 ;
V_42 = F_3 ( V_2 , F_71 ( V_7 -> V_40 ) ) ;
V_159 = ( V_42 & V_161 ) >>
V_162 ;
return V_159 ;
}
static int F_72 ( struct V_1 * V_2 ,
struct V_6 * V_7 )
{
int V_159 ;
V_159 = F_70 ( V_2 , V_7 ) ;
if ( V_159 )
F_69 ( V_2 , V_7 , V_159 ) ;
return V_159 ;
}
static T_1 F_73 ( int V_163 , int V_164 ,
int V_165 , int V_166 )
{
T_1 V_167 ;
V_167 = V_163 << V_168 ;
V_167 |= V_165 << V_169 ;
if ( V_164 == F_74 ( V_170 ) )
V_167 |= V_171 ;
else
V_167 |= V_172 ;
if ( V_166 == V_173 )
V_167 |= V_174 ;
else if ( V_166 == V_175 )
V_167 |= V_176 | V_174 ;
else
V_167 |= V_177 ;
return V_167 ;
}
static void F_75 ( struct V_1 * V_2 ,
struct V_32 * V_46 )
{
T_1 V_34 = V_46 -> V_34 ;
if ( ! F_12 ( V_46 ) ) {
F_76 ( V_2 -> V_17 ,
L_4 ,
V_46 -> V_34 , V_46 -> V_178 ) ;
return;
}
switch ( V_34 & V_179 ) {
case V_180 :
F_76 ( V_2 -> V_17 , L_5 ,
V_34 , V_46 -> V_178 ) ;
break;
case V_181 :
F_76 ( V_2 -> V_17 , L_6 ,
V_34 , V_46 -> V_178 ) ;
break;
case V_182 :
F_76 ( V_2 -> V_17 , L_7 ,
V_34 , V_46 -> V_178 ) ;
break;
case V_183 :
F_76 ( V_2 -> V_17 , L_8 ,
V_34 , V_46 -> V_178 ) ;
break;
}
}
static void F_77 ( struct V_1 * V_2 ,
struct V_32 * V_46 ,
struct V_184 * V_185 )
{
if ( ( V_46 -> V_34 & V_186 ) &&
( V_46 -> V_34 & V_187 ) ) {
V_185 -> V_188 = 0 ;
V_185 -> V_189 = V_190 ;
return;
}
V_185 -> V_189 = V_191 ;
}
static struct V_6 * F_78 ( struct V_1 * V_2 ,
T_1 V_192 )
{
int V_69 = F_79 ( V_192 ) - 1 ;
return ( V_69 < 0 || V_69 >= V_71 ) ? NULL : & V_2 -> V_72 [ V_69 ] ;
}
static void F_80 ( struct V_1 * V_2 ,
struct V_6 * V_7 , int V_193 )
{
int V_11 ;
for ( V_11 = 0 ; V_11 < V_193 ; V_11 ++ ) {
struct V_56 * V_57 = V_7 -> V_48 +
V_7 -> V_8 ;
struct V_184 * V_185 = V_7 -> V_194 [ V_7 -> V_8 ] ;
F_5 ( V_7 ) ;
if ( ! V_185 )
continue;
F_81 ( V_2 -> V_17 -> V_17 . V_195 , V_57 -> V_158 ,
V_57 -> V_178 , V_196 ) ;
F_82 ( V_185 ) ;
}
}
static int F_83 ( struct V_1 * V_2 ,
struct V_6 * V_7 )
{
struct V_197 * V_198 = F_84 ( V_2 -> V_17 , V_7 -> V_40 ) ;
int V_199 ;
V_199 = F_72 ( V_2 , V_7 ) ;
if ( V_199 == 0 )
return V_199 ;
F_80 ( V_2 , V_7 , V_199 ) ;
V_7 -> V_77 -= V_199 ;
if ( F_85 ( V_198 ) ) {
if ( V_7 -> V_9 - V_7 -> V_77 >= V_200 + 1 )
F_86 ( V_198 ) ;
}
return V_199 ;
}
static int F_87 ( struct V_1 * V_2 ,
struct V_32 * V_46 )
{
T_3 V_155 ;
struct V_184 * V_185 ;
V_185 = F_88 ( V_2 -> V_17 , V_2 -> V_201 ) ;
if ( ! V_185 )
return - V_202 ;
V_155 = F_89 ( V_2 -> V_17 -> V_17 . V_195 , V_185 -> V_203 ,
F_90 ( V_2 -> V_201 ) ,
V_204 ) ;
if ( F_91 ( F_92 ( V_2 -> V_17 -> V_17 . V_195 , V_155 ) ) ) {
F_93 ( V_185 ) ;
return - V_202 ;
}
F_68 ( V_46 , V_155 , ( T_1 ) V_185 ) ;
return 0 ;
}
static T_1 F_94 ( struct V_1 * V_2 , struct V_184 * V_185 )
{
if ( V_185 -> V_189 == V_205 ) {
int V_165 = 0 ;
T_2 V_166 ;
if ( V_185 -> V_206 == F_95 ( V_170 ) ) {
struct V_207 * V_208 = F_96 ( V_185 ) ;
V_165 = V_208 -> V_209 ;
V_166 = V_208 -> V_206 ;
} else if ( V_185 -> V_206 == F_95 ( V_210 ) ) {
struct V_211 * V_212 = F_97 ( V_185 ) ;
if ( F_98 ( V_185 ) > 0 )
V_165 = ( F_98 ( V_185 ) >> 2 ) ;
V_166 = V_212 -> V_213 ;
} else
return V_177 ;
return F_73 ( F_99 ( V_185 ) ,
V_185 -> V_206 , V_165 , V_166 ) ;
}
return V_177 ;
}
static struct V_36 * F_100 ( struct V_1 * V_2 ,
T_1 V_192 )
{
int V_69 = F_79 ( V_192 >> 8 ) - 1 ;
return ( V_69 < 0 || V_69 >= V_74 ) ? NULL : & V_2 -> V_75 [ V_69 ] ;
}
static void F_101 ( struct V_1 * V_2 ,
struct V_36 * V_37 )
{
int V_44 , V_11 ;
V_44 = F_15 ( V_2 , V_37 ) ;
for ( V_11 = 0 ; V_11 < V_37 -> V_9 ; V_11 ++ ) {
struct V_32 * V_46 = V_37 -> V_48 + V_11 ;
struct V_184 * V_185 = (struct V_184 * ) V_46 -> V_157 ;
F_82 ( V_185 ) ;
F_81 ( V_2 -> V_17 -> V_17 . V_195 , V_46 -> V_158 ,
V_46 -> V_178 , V_204 ) ;
}
if ( V_44 )
F_17 ( V_2 , V_37 , V_44 , V_44 ) ;
}
static int F_102 ( struct V_1 * V_2 , int V_214 ,
struct V_36 * V_37 )
{
struct V_16 * V_17 = V_2 -> V_17 ;
int V_44 , V_45 ;
V_44 = F_15 ( V_2 , V_37 ) ;
if ( V_214 > V_44 )
V_214 = V_44 ;
V_44 = 0 ;
V_45 = 0 ;
while ( V_44 < V_214 ) {
struct V_32 * V_46 = F_18 ( V_37 ) ;
struct V_184 * V_185 ;
T_1 V_215 ;
int V_24 , V_216 ;
F_103 ( V_46 ) ;
V_44 ++ ;
V_45 ++ ;
V_215 = V_46 -> V_34 ;
V_185 = (struct V_184 * ) V_46 -> V_157 ;
if ( ! F_12 ( V_46 ) ||
( V_215 & V_217 ) ) {
V_17 -> V_18 . V_29 ++ ;
F_75 ( V_2 , V_46 ) ;
F_68 ( V_46 , V_46 -> V_158 ,
( T_1 ) V_185 ) ;
continue;
}
F_81 ( V_2 -> V_17 -> V_17 . V_195 , V_46 -> V_158 ,
V_46 -> V_178 , V_204 ) ;
V_24 = V_46 -> V_178 -
( V_218 + V_52 ) ;
F_104 ( & V_2 -> V_20 . V_21 ) ;
V_2 -> V_20 . V_23 ++ ;
V_2 -> V_20 . V_25 += V_24 ;
F_105 ( & V_2 -> V_20 . V_21 ) ;
F_106 ( V_185 , V_52 ) ;
F_107 ( V_185 , V_24 ) ;
V_185 -> V_206 = F_108 ( V_185 , V_17 ) ;
F_77 ( V_2 , V_46 , V_185 ) ;
F_109 ( & V_2 -> V_219 , V_185 ) ;
V_216 = F_87 ( V_2 , V_46 ) ;
if ( V_216 ) {
F_76 ( V_2 -> V_17 , L_9 ) ;
V_37 -> V_220 ++ ;
V_45 -- ;
}
}
F_17 ( V_2 , V_37 , V_44 , V_45 ) ;
return V_44 ;
}
static int F_110 ( struct V_1 * V_2 , struct V_184 * V_185 ,
struct V_6 * V_7 )
{
struct V_56 * V_57 ;
int V_11 ;
for ( V_11 = 0 ; V_11 < F_111 ( V_185 ) -> V_221 ; V_11 ++ ) {
T_4 * V_222 = & F_111 ( V_185 ) -> V_223 [ V_11 ] ;
void * V_137 = F_112 ( V_222 -> V_224 . V_225 ) + V_222 -> V_226 ;
V_57 = F_26 ( V_7 ) ;
V_57 -> V_178 = V_222 -> V_9 ;
V_57 -> V_158 =
F_89 ( V_2 -> V_17 -> V_17 . V_195 , V_137 ,
V_57 -> V_178 , V_196 ) ;
if ( F_92 ( V_2 -> V_17 -> V_17 . V_195 ,
V_57 -> V_158 ) ) {
F_27 ( V_7 ) ;
goto error;
}
if ( V_11 == ( F_111 ( V_185 ) -> V_221 - 1 ) ) {
V_57 -> V_167 = V_227 | V_228 ;
V_7 -> V_194 [ V_7 -> V_10 ] = V_185 ;
F_6 ( V_7 ) ;
} else {
V_57 -> V_167 = 0 ;
V_7 -> V_194 [ V_7 -> V_10 ] = NULL ;
F_6 ( V_7 ) ;
}
}
return 0 ;
error:
for ( V_11 = V_11 - 1 ; V_11 >= 0 ; V_11 -- ) {
V_57 = V_7 -> V_48 + V_11 ;
F_81 ( V_2 -> V_17 -> V_17 . V_195 ,
V_57 -> V_158 ,
V_57 -> V_178 ,
V_196 ) ;
F_27 ( V_7 ) ;
}
return - V_202 ;
}
static int F_113 ( struct V_184 * V_185 , struct V_16 * V_17 )
{
struct V_1 * V_2 = F_9 ( V_17 ) ;
T_5 V_229 = F_114 ( V_185 ) ;
struct V_6 * V_7 = & V_2 -> V_72 [ V_229 ] ;
struct V_56 * V_57 ;
struct V_197 * V_198 ;
int V_223 = 0 ;
T_1 V_230 ;
if ( ! F_115 ( V_17 ) )
goto V_231;
V_223 = F_111 ( V_185 ) -> V_221 + 1 ;
V_198 = F_84 ( V_17 , V_229 ) ;
V_57 = F_26 ( V_7 ) ;
V_230 = F_94 ( V_2 , V_185 ) ;
V_57 -> V_178 = F_116 ( V_185 ) ;
V_57 -> V_158 = F_89 ( V_17 -> V_17 . V_195 , V_185 -> V_4 ,
V_57 -> V_178 ,
V_196 ) ;
if ( F_91 ( F_92 ( V_17 -> V_17 . V_195 ,
V_57 -> V_158 ) ) ) {
F_27 ( V_7 ) ;
V_223 = 0 ;
goto V_231;
}
if ( V_223 == 1 ) {
V_230 |= V_232 ;
V_57 -> V_167 = V_230 ;
V_7 -> V_194 [ V_7 -> V_10 ] = V_185 ;
F_6 ( V_7 ) ;
} else {
V_230 |= V_233 ;
V_7 -> V_194 [ V_7 -> V_10 ] = NULL ;
F_6 ( V_7 ) ;
V_57 -> V_167 = V_230 ;
if ( F_110 ( V_2 , V_185 , V_7 ) ) {
F_81 ( V_17 -> V_17 . V_195 ,
V_57 -> V_158 ,
V_57 -> V_178 ,
V_196 ) ;
F_27 ( V_7 ) ;
V_223 = 0 ;
goto V_231;
}
}
V_7 -> V_77 += V_223 ;
F_24 ( V_2 , V_7 , V_223 ) ;
if ( V_7 -> V_9 - V_7 -> V_77 < V_200 + 1 )
F_117 ( V_198 ) ;
V_231:
if ( V_223 > 0 ) {
F_104 ( & V_2 -> V_26 . V_21 ) ;
V_2 -> V_26 . V_23 ++ ;
V_2 -> V_26 . V_25 += V_185 -> V_234 ;
F_105 ( & V_2 -> V_26 . V_21 ) ;
} else {
V_17 -> V_18 . V_31 ++ ;
F_82 ( V_185 ) ;
}
if ( V_7 -> V_77 >= V_235 )
F_83 ( V_2 , V_7 ) ;
if ( V_7 -> V_77 == V_223 && V_223 > 0 )
F_64 ( V_2 ) ;
return V_236 ;
}
static void F_118 ( struct V_1 * V_2 ,
struct V_6 * V_7 )
{
int V_199 = V_7 -> V_77 ;
F_80 ( V_2 , V_7 , V_199 ) ;
V_7 -> V_77 = 0 ;
V_7 -> V_10 = 0 ;
V_7 -> V_8 = 0 ;
}
static T_1 F_119 ( struct V_1 * V_2 , T_1 V_237 ,
int * V_238 )
{
struct V_6 * V_7 ;
T_1 V_199 = 0 ;
struct V_197 * V_198 ;
* V_238 = 0 ;
while ( V_237 != 0 ) {
V_7 = F_78 ( V_2 , V_237 ) ;
if ( ! V_7 )
break;
V_198 = F_84 ( V_2 -> V_17 , V_7 -> V_40 ) ;
F_120 ( V_198 , F_121 () ) ;
if ( V_7 -> V_77 ) {
V_199 += F_83 ( V_2 , V_7 ) ;
* V_238 += V_7 -> V_77 ;
}
F_122 ( V_198 ) ;
V_237 &= ~ ( ( 1 << V_7 -> V_40 ) ) ;
}
return V_199 ;
}
static int F_123 ( unsigned char * V_137 )
{
int V_239 = 0 ;
int V_11 ;
for ( V_11 = 0 ; V_11 < V_240 ; V_11 ++ ) {
int V_241 ;
V_239 = ( V_239 ^ V_137 [ V_11 ] ) << 8 ;
for ( V_241 = 7 ; V_241 >= 0 ; V_241 -- ) {
if ( V_239 & ( 0x100 << V_241 ) )
V_239 ^= 0x107 << V_241 ;
}
}
return V_239 ;
}
static void F_124 ( struct V_1 * V_2 ,
unsigned char V_242 ,
int V_69 )
{
unsigned int V_243 ;
unsigned int V_135 ;
unsigned int V_136 ;
V_135 = ( V_242 / 4 ) ;
V_136 = V_242 % 4 ;
V_243 = F_3 ( V_2 , ( V_90
+ V_135 * 4 ) ) ;
if ( V_69 == - 1 )
V_243 &= ~ ( 0xff << ( 8 * V_136 ) ) ;
else {
V_243 &= ~ ( 0xff << ( 8 * V_136 ) ) ;
V_243 |= ( ( 0x01 | ( V_69 << 1 ) ) << ( 8 * V_136 ) ) ;
}
F_1 ( V_2 , V_90 + V_135 * 4 ,
V_243 ) ;
}
static void F_125 ( struct V_1 * V_2 ,
unsigned char V_244 ,
int V_69 )
{
unsigned int V_245 ;
unsigned int V_135 ;
unsigned int V_136 ;
V_135 = ( V_244 / 4 ) * 4 ;
V_136 = V_244 % 4 ;
V_245 = F_3 ( V_2 , V_92 + V_135 ) ;
if ( V_69 == - 1 ) {
V_245 &= ~ ( 0xff << ( 8 * V_136 ) ) ;
} else {
V_245 &= ~ ( 0xff << ( 8 * V_136 ) ) ;
V_245 |= ( ( 0x01 | ( V_69 << 1 ) ) << ( 8 * V_136 ) ) ;
}
F_1 ( V_2 , V_92 + V_135 , V_245 ) ;
}
static int F_126 ( struct V_1 * V_2 , unsigned char * V_246 ,
int V_69 )
{
unsigned char V_247 = 0 ;
if ( memcmp ( V_246 , L_10 , 5 ) == 0 ) {
F_124 ( V_2 , V_246 [ 5 ] , V_69 ) ;
return 0 ;
}
V_247 = F_123 ( V_246 ) ;
if ( V_69 == - 1 ) {
if ( V_2 -> V_91 [ V_247 ] == 0 ) {
F_127 ( V_2 -> V_17 , L_11 ,
V_247 ) ;
return - V_248 ;
}
V_2 -> V_91 [ V_247 ] -- ;
if ( V_2 -> V_91 [ V_247 ] != 0 ) {
F_127 ( V_2 -> V_17 ,
L_12 ,
V_2 -> V_91 [ V_247 ] , V_247 ) ;
return - V_248 ;
}
} else
V_2 -> V_91 [ V_247 ] ++ ;
F_125 ( V_2 , V_247 , V_69 ) ;
return 0 ;
}
static void F_128 ( struct V_1 * V_2 ,
int V_249 )
{
T_1 V_250 , V_42 ;
V_250 = F_3 ( V_2 , V_113 ) ;
V_42 = F_3 ( V_2 , V_251 ) ;
if ( V_249 ) {
V_250 |= V_252 ;
V_42 |= V_253 ;
F_1 ( V_2 , V_140 , 0xffff ) ;
F_1 ( V_2 , V_141 , 0xffffffff ) ;
} else {
V_250 &= ~ V_252 ;
V_42 &= ~ V_253 ;
}
F_1 ( V_2 , V_113 , V_250 ) ;
F_1 ( V_2 , V_251 , V_42 ) ;
}
static void F_129 ( struct V_16 * V_17 )
{
struct V_1 * V_2 = F_9 ( V_17 ) ;
struct V_254 * V_255 ;
if ( V_17 -> V_150 & V_256 ) {
F_128 ( V_2 , 1 ) ;
F_40 ( V_2 , V_112 ) ;
F_41 ( V_2 , V_112 ) ;
F_42 ( V_2 , V_112 ) ;
} else {
F_128 ( V_2 , 0 ) ;
F_40 ( V_2 , - 1 ) ;
F_54 ( V_2 , V_17 -> V_257 , V_112 ) ;
if ( V_17 -> V_150 & V_258 ) {
F_41 ( V_2 , V_112 ) ;
F_42 ( V_2 , V_112 ) ;
} else {
F_41 ( V_2 , - 1 ) ;
F_42 ( V_2 , - 1 ) ;
if ( ! F_130 ( V_17 ) ) {
F_131 (ha, dev) {
F_126 ( V_2 , V_255 -> V_137 ,
V_112 ) ;
}
}
}
}
}
static T_6 F_132 ( int V_259 , void * V_260 )
{
struct V_1 * V_2 = (struct V_1 * ) V_260 ;
F_1 ( V_2 , V_97 , 0 ) ;
F_133 ( & V_2 -> V_219 ) ;
return V_261 ;
}
static int F_134 ( struct V_262 * V_219 , int V_263 )
{
int V_44 = 0 ;
T_1 V_264 ;
unsigned long V_150 ;
struct V_1 * V_2 = F_9 ( V_219 -> V_17 ) ;
if ( ! F_115 ( V_2 -> V_17 ) ) {
F_135 ( V_219 ) ;
return V_44 ;
}
V_264 = F_3 ( V_2 , V_94 ) &
F_136 ( V_74 ) ;
V_264 |= V_2 -> V_264 ;
if ( V_74 > 1 ) {
while ( ( V_264 != 0 ) && ( V_263 > 0 ) ) {
int V_77 ;
struct V_36 * V_37 ;
V_37 = F_100 ( V_2 , V_264 ) ;
if ( ! V_37 )
break;
V_77 = F_102 ( V_2 , V_263 , V_37 ) ;
V_44 += V_77 ;
V_263 -= V_77 ;
if ( V_263 > 0 ) {
V_264 &= ~ ( ( 1 << V_37 -> V_40 ) << 8 ) ;
}
}
} else {
V_44 = F_102 ( V_2 , V_263 , & V_2 -> V_75 [ V_112 ] ) ;
V_263 -= V_44 ;
}
if ( V_263 > 0 ) {
V_264 = 0 ;
F_135 ( V_219 ) ;
F_137 ( V_150 ) ;
F_1 ( V_2 , V_97 ,
F_136 ( V_74 ) ) ;
F_138 ( V_150 ) ;
}
V_2 -> V_264 = V_264 ;
return V_44 ;
}
static void F_139 ( unsigned long V_4 )
{
struct V_16 * V_17 = (struct V_16 * ) V_4 ;
struct V_1 * V_2 = F_9 ( V_17 ) ;
int V_199 = 0 , V_238 = 0 ;
if ( ! F_115 ( V_17 ) )
return ;
F_140 ( V_149 , & V_2 -> V_150 ) ;
V_199 = F_119 ( V_2 ,
( ( ( 1 << V_71 ) - 1 ) &
V_265 ) ,
& V_238 ) ;
if ( V_238 > 0 )
F_64 ( V_2 ) ;
}
static int F_141 ( struct V_1 * V_2 , struct V_36 * V_37 ,
int V_193 )
{
struct V_16 * V_17 = V_2 -> V_17 ;
int V_11 ;
for ( V_11 = 0 ; V_11 < V_193 ; V_11 ++ ) {
struct V_184 * V_185 ;
struct V_32 * V_46 ;
unsigned long V_155 ;
V_185 = F_142 ( V_2 -> V_201 ) ;
if ( ! V_185 ) {
F_76 ( V_17 , L_13 ,
V_266 , V_37 -> V_40 , V_11 , V_193 ) ;
break;
}
V_46 = V_37 -> V_48 + V_11 ;
memset ( V_46 , 0 , sizeof( struct V_32 ) ) ;
V_155 = F_89 ( V_17 -> V_17 . V_195 , V_185 -> V_203 ,
F_90 ( V_2 -> V_201 ) ,
V_204 ) ;
if ( F_91 ( F_92 ( V_17 -> V_17 . V_195 , V_155 ) ) ) {
F_93 ( V_185 ) ;
break;
}
F_68 ( V_46 , V_155 , ( T_1 ) V_185 ) ;
}
F_13 ( V_2 , V_37 , V_11 ) ;
return V_11 ;
}
static void F_143 ( struct V_1 * V_2 )
{
int V_69 ;
for ( V_69 = 0 ; V_69 < V_71 ; V_69 ++ )
F_118 ( V_2 , & V_2 -> V_72 [ V_69 ] ) ;
F_1 ( V_2 , V_107 , V_108 ) ;
F_1 ( V_2 , V_107 , 0 ) ;
}
static void F_144 ( struct V_1 * V_2 )
{
F_1 ( V_2 , V_105 , V_106 ) ;
F_1 ( V_2 , V_105 , 0 ) ;
}
static int F_145 ( struct V_1 * V_2 ,
struct V_36 * V_37 )
{
V_37 -> V_9 = V_2 -> V_267 ;
V_37 -> V_48 = F_146 ( V_2 -> V_17 -> V_17 . V_195 ,
V_37 -> V_9 * V_268 ,
& V_37 -> V_269 , V_270 ) ;
if ( V_37 -> V_48 == NULL )
return - V_202 ;
F_147 ( V_37 -> V_48 !=
F_148 ( V_37 -> V_48 , V_271 ) ) ;
V_37 -> V_58 = V_37 -> V_9 - 1 ;
F_1 ( V_2 , F_149 ( V_37 -> V_40 ) , V_37 -> V_269 ) ;
F_1 ( V_2 , F_29 ( V_37 -> V_40 ) , V_37 -> V_9 ) ;
F_21 ( V_2 , V_37 , V_272 ) ;
F_55 ( V_2 , V_37 , V_37 -> V_143 ) ;
F_58 ( V_2 , V_37 , V_37 -> V_146 ) ;
F_28 ( V_2 , V_37 , F_90 ( V_2 -> V_201 ) ) ;
F_30 ( V_2 , V_37 ) ;
F_141 ( V_2 , V_37 , V_37 -> V_9 ) ;
return 0 ;
}
static void F_150 ( struct V_1 * V_2 ,
struct V_36 * V_37 )
{
F_101 ( V_2 , V_37 ) ;
if ( V_37 -> V_48 )
F_151 ( V_2 -> V_17 -> V_17 . V_195 ,
V_37 -> V_9 * V_268 ,
V_37 -> V_48 ,
V_37 -> V_269 ) ;
V_37 -> V_48 = NULL ;
V_37 -> V_58 = 0 ;
V_37 -> V_47 = 0 ;
V_37 -> V_269 = 0 ;
}
static int F_152 ( struct V_1 * V_2 ,
struct V_6 * V_7 )
{
V_7 -> V_9 = V_2 -> V_273 ;
V_7 -> V_48 = F_146 ( V_2 -> V_17 -> V_17 . V_195 ,
V_7 -> V_9 * V_268 ,
& V_7 -> V_269 , V_270 ) ;
if ( V_7 -> V_48 == NULL )
return - V_202 ;
F_147 ( V_7 -> V_48 !=
F_148 ( V_7 -> V_48 , V_271 ) ) ;
V_7 -> V_58 = V_7 -> V_9 - 1 ;
F_1 ( V_2 , F_46 ( V_7 -> V_40 ) , 0x03ffffff ) ;
F_1 ( V_2 , F_45 ( V_7 -> V_40 ) , 0x3fffffff ) ;
F_1 ( V_2 , F_153 ( V_7 -> V_40 ) , V_7 -> V_269 ) ;
F_1 ( V_2 , F_62 ( V_7 -> V_40 ) , V_7 -> V_9 ) ;
V_7 -> V_194 = F_154 ( V_7 -> V_9 * sizeof( * V_7 -> V_194 ) , V_270 ) ;
if ( V_7 -> V_194 == NULL ) {
F_151 ( V_2 -> V_17 -> V_17 . V_195 ,
V_7 -> V_9 * V_268 ,
V_7 -> V_48 , V_7 -> V_269 ) ;
return - V_202 ;
}
F_61 ( V_2 , V_7 , V_7 -> V_148 ) ;
return 0 ;
}
static void F_155 ( struct V_1 * V_2 ,
struct V_6 * V_7 )
{
F_156 ( V_7 -> V_194 ) ;
if ( V_7 -> V_48 )
F_151 ( V_2 -> V_17 -> V_17 . V_195 ,
V_7 -> V_9 * V_268 ,
V_7 -> V_48 , V_7 -> V_269 ) ;
V_7 -> V_48 = NULL ;
V_7 -> V_58 = 0 ;
V_7 -> V_47 = 0 ;
V_7 -> V_269 = 0 ;
F_1 ( V_2 , F_46 ( V_7 -> V_40 ) , 0 ) ;
F_1 ( V_2 , F_45 ( V_7 -> V_40 ) , 0 ) ;
F_1 ( V_2 , F_153 ( V_7 -> V_40 ) , 0 ) ;
F_1 ( V_2 , F_62 ( V_7 -> V_40 ) , 0 ) ;
}
static void F_157 ( struct V_1 * V_2 )
{
int V_69 ;
for ( V_69 = 0 ; V_69 < V_71 ; V_69 ++ )
F_155 ( V_2 , & V_2 -> V_72 [ V_69 ] ) ;
}
static void F_158 ( struct V_1 * V_2 )
{
int V_69 ;
for ( V_69 = 0 ; V_69 < V_74 ; V_69 ++ )
F_150 ( V_2 , & V_2 -> V_75 [ V_69 ] ) ;
}
static int F_159 ( struct V_1 * V_2 )
{
int V_69 ;
for ( V_69 = 0 ; V_69 < V_74 ; V_69 ++ ) {
int V_216 = F_145 ( V_2 , & V_2 -> V_75 [ V_69 ] ) ;
if ( V_216 ) {
F_76 ( V_2 -> V_17 , L_14 ,
V_266 , V_69 ) ;
F_158 ( V_2 ) ;
return V_216 ;
}
}
return 0 ;
}
static int F_160 ( struct V_1 * V_2 )
{
int V_69 ;
for ( V_69 = 0 ; V_69 < V_71 ; V_69 ++ ) {
int V_216 = F_152 ( V_2 , & V_2 -> V_72 [ V_69 ] ) ;
if ( V_216 ) {
F_76 ( V_2 -> V_17 , L_15 ,
V_266 , V_69 ) ;
F_157 ( V_2 ) ;
return V_216 ;
}
}
return 0 ;
}
static void F_161 ( struct V_1 * V_2 )
{
F_20 ( V_2 , V_2 -> V_201 ) ;
F_51 ( V_2 , V_2 -> V_201 ) ;
F_38 ( V_2 ) ;
F_162 ( & V_2 -> V_219 ) ;
F_1 ( V_2 , V_97 ,
F_136 ( V_74 ) ) ;
F_163 ( V_2 -> V_274 ) ;
F_164 ( V_2 -> V_17 ) ;
}
static void F_165 ( struct V_1 * V_2 )
{
F_166 ( V_2 -> V_274 ) ;
F_167 ( & V_2 -> V_219 ) ;
F_168 ( V_2 -> V_17 ) ;
F_34 ( V_2 ) ;
F_169 ( V_2 -> V_17 ) ;
F_39 ( V_2 ) ;
F_1 ( V_2 , V_96 , 0 ) ;
F_1 ( V_2 , V_95 , 0 ) ;
F_1 ( V_2 , V_97 , 0 ) ;
F_1 ( V_2 , V_98 , 0 ) ;
F_1 ( V_2 , V_99 , 0 ) ;
F_143 ( V_2 ) ;
F_144 ( V_2 ) ;
}
static void F_170 ( struct V_16 * V_17 )
{
struct V_1 * V_2 = F_9 ( V_17 ) ;
F_127 ( V_17 , L_16 ) ;
F_165 ( V_2 ) ;
F_161 ( V_2 ) ;
}
static int F_171 ( struct V_16 * V_17 , int V_127 )
{
if ( V_127 < 68 ) {
F_76 ( V_17 , L_17 ) ;
return - V_248 ;
}
if ( V_127 > 9676 ) {
F_127 ( V_17 , L_18 , V_127 ) ;
V_127 = 9676 ;
}
if ( ! F_172 ( F_173 ( V_127 ) , 8 ) ) {
F_127 ( V_17 , L_19 ,
V_127 , F_174 ( F_173 ( V_127 ) , 8 ) ) ;
V_127 = F_174 ( F_173 ( V_127 ) , 8 ) ;
}
return V_127 ;
}
static int F_175 ( struct V_16 * V_17 , int V_127 )
{
struct V_1 * V_2 = F_9 ( V_17 ) ;
int V_275 ;
V_127 = F_171 ( V_17 , V_127 ) ;
if ( V_127 < 0 )
return - V_248 ;
V_17 -> V_127 = V_127 ;
if ( ! F_115 ( V_17 ) )
return 0 ;
F_165 ( V_2 ) ;
F_157 ( V_2 ) ;
F_158 ( V_2 ) ;
V_2 -> V_201 = F_173 ( V_2 -> V_17 -> V_127 ) ;
V_275 = F_159 ( V_2 ) ;
if ( V_275 ) {
F_76 ( V_2 -> V_17 , L_20 ) ;
return V_275 ;
}
F_160 ( V_2 ) ;
F_161 ( V_2 ) ;
F_33 ( V_2 ) ;
return 0 ;
}
static void F_176 ( struct V_1 * V_2 , unsigned char * V_137 )
{
T_1 V_276 , V_277 ;
V_276 = F_3 ( V_2 , V_140 ) ;
V_277 = F_3 ( V_2 , V_141 ) ;
V_137 [ 0 ] = ( V_277 >> 24 ) & 0xFF ;
V_137 [ 1 ] = ( V_277 >> 16 ) & 0xFF ;
V_137 [ 2 ] = ( V_277 >> 8 ) & 0xFF ;
V_137 [ 3 ] = V_277 & 0xFF ;
V_137 [ 4 ] = ( V_276 >> 8 ) & 0xFF ;
V_137 [ 5 ] = V_276 & 0xFF ;
}
static int F_177 ( struct V_16 * V_17 , void * V_137 )
{
struct V_1 * V_2 = F_9 ( V_17 ) ;
T_2 * V_278 = V_137 + 2 ;
int V_11 ;
if ( F_115 ( V_17 ) )
return - V_279 ;
F_54 ( V_2 , V_17 -> V_257 , - 1 ) ;
F_54 ( V_2 , V_278 , V_112 ) ;
for ( V_11 = 0 ; V_11 < V_240 ; V_11 ++ )
V_17 -> V_257 [ V_11 ] = V_278 [ V_11 ] ;
return 0 ;
}
static void F_178 ( struct V_16 * V_280 )
{
struct V_1 * V_2 = F_9 ( V_280 ) ;
struct V_281 * V_282 = V_2 -> V_274 ;
int V_283 = 0 ;
if ( V_282 -> V_284 ) {
if ( ( V_2 -> V_285 != V_282 -> V_285 ) ||
( V_2 -> V_286 != V_282 -> V_286 ) ) {
T_1 V_42 ;
V_42 = F_3 ( V_2 , V_287 ) ;
V_42 &= ~ ( V_288 |
V_289 |
V_290 |
V_291 |
V_292 ) ;
if ( V_282 -> V_286 )
V_42 |= V_290 ;
if ( V_282 -> V_285 == V_293 )
V_42 |= V_289 ;
else
V_42 |= V_288 ;
F_1 ( V_2 , V_287 , V_42 ) ;
V_2 -> V_286 = V_282 -> V_286 ;
V_2 -> V_285 = V_282 -> V_285 ;
}
}
if ( V_282 -> V_284 != V_2 -> V_284 ) {
if ( ! V_282 -> V_284 ) {
V_2 -> V_286 = - 1 ;
V_2 -> V_285 = 0 ;
}
V_2 -> V_284 = V_282 -> V_284 ;
V_283 = 1 ;
}
if ( V_283 ) {
if ( V_282 -> V_284 ) {
T_1 V_42 = F_3 ( V_2 , V_287 ) ;
V_42 |= ( V_294 |
V_295 ) ;
F_1 ( V_2 , V_287 , V_42 ) ;
F_33 ( V_2 ) ;
F_127 ( V_2 -> V_17 , L_21 ) ;
} else {
F_34 ( V_2 ) ;
F_127 ( V_2 -> V_17 , L_22 ) ;
}
}
}
static int F_179 ( struct V_1 * V_2 )
{
struct V_281 * V_274 ;
V_274 = F_180 ( V_2 -> V_17 , V_2 -> V_296 , F_178 , 0 ,
V_2 -> V_297 ) ;
if ( ! V_274 ) {
F_76 ( V_2 -> V_17 , L_23 ) ;
return - V_298 ;
}
V_274 -> V_299 &= V_300 ;
V_274 -> V_301 = V_274 -> V_299 ;
V_2 -> V_274 = V_274 ;
V_2 -> V_284 = 0 ;
V_2 -> V_286 = 0 ;
V_2 -> V_285 = 0 ;
return 0 ;
}
static void F_181 ( struct V_1 * V_2 )
{
F_182 ( V_2 -> V_274 ) ;
V_2 -> V_274 = NULL ;
}
static int F_183 ( struct V_16 * V_17 )
{
struct V_1 * V_2 = F_9 ( V_17 ) ;
int V_275 ;
F_54 ( V_2 , V_17 -> V_257 , V_112 ) ;
V_2 -> V_201 = F_173 ( V_2 -> V_17 -> V_127 ) ;
V_275 = F_159 ( V_2 ) ;
if ( V_275 )
return V_275 ;
V_275 = F_160 ( V_2 ) ;
if ( V_275 )
goto V_302;
V_275 = F_184 ( V_2 -> V_17 -> V_259 , F_132 , 0 ,
V_303 , V_2 ) ;
if ( V_275 ) {
F_76 ( V_2 -> V_17 , L_24 , V_2 -> V_17 -> V_259 ) ;
goto V_304;
}
F_168 ( V_2 -> V_17 ) ;
V_275 = F_179 ( V_2 ) ;
if ( V_275 < 0 ) {
F_76 ( V_17 , L_25 ) ;
goto V_305;
}
F_161 ( V_2 ) ;
return 0 ;
V_305:
F_185 ( V_2 -> V_17 -> V_259 , V_2 ) ;
V_304:
F_157 ( V_2 ) ;
V_302:
F_158 ( V_2 ) ;
return V_275 ;
}
static int F_186 ( struct V_16 * V_17 )
{
struct V_1 * V_2 = F_9 ( V_17 ) ;
F_165 ( V_2 ) ;
F_181 ( V_2 ) ;
F_185 ( V_17 -> V_259 , V_2 ) ;
F_158 ( V_2 ) ;
F_157 ( V_2 ) ;
F_187 ( & V_2 -> V_151 ) ;
F_140 ( V_149 , & V_2 -> V_150 ) ;
return 0 ;
}
static int F_188 ( struct V_16 * V_17 , struct V_306 * V_307 , int V_308 )
{
struct V_1 * V_2 = F_9 ( V_17 ) ;
int V_275 ;
if ( ! V_2 -> V_274 )
return - V_309 ;
V_275 = F_189 ( V_2 -> V_274 , V_307 , V_308 ) ;
if ( ! V_275 )
F_178 ( V_17 ) ;
return V_275 ;
}
int F_190 ( struct V_16 * V_17 , struct V_310 * V_308 )
{
struct V_1 * V_2 = F_9 ( V_17 ) ;
if ( ! V_2 -> V_274 )
return - V_298 ;
return F_191 ( V_2 -> V_274 , V_308 ) ;
}
int F_192 ( struct V_16 * V_17 , struct V_310 * V_308 )
{
struct V_1 * V_2 = F_9 ( V_17 ) ;
if ( ! V_2 -> V_274 )
return - V_298 ;
return F_193 ( V_2 -> V_274 , V_308 ) ;
}
static int F_194 ( struct V_16 * V_17 ,
struct V_311 * V_312 )
{
struct V_1 * V_2 = F_9 ( V_17 ) ;
int V_69 ;
for ( V_69 = 0 ; V_69 < V_74 ; V_69 ++ ) {
struct V_36 * V_37 = & V_2 -> V_75 [ V_69 ] ;
V_37 -> V_146 = V_312 -> V_313 ;
V_37 -> V_143 = V_312 -> V_314 ;
F_55 ( V_2 , V_37 , V_37 -> V_143 ) ;
F_58 ( V_2 , V_37 , V_37 -> V_146 ) ;
}
for ( V_69 = 0 ; V_69 < V_71 ; V_69 ++ ) {
struct V_6 * V_7 = & V_2 -> V_72 [ V_69 ] ;
V_7 -> V_148 = V_312 -> V_315 ;
F_61 ( V_2 , V_7 , V_7 -> V_148 ) ;
}
return 0 ;
}
static int F_195 ( struct V_16 * V_17 ,
struct V_311 * V_312 )
{
struct V_1 * V_2 = F_9 ( V_17 ) ;
V_312 -> V_313 = V_2 -> V_75 [ 0 ] . V_146 ;
V_312 -> V_314 = V_2 -> V_75 [ 0 ] . V_143 ;
V_312 -> V_315 = V_2 -> V_72 [ 0 ] . V_148 ;
return 0 ;
}
static void F_196 ( struct V_16 * V_17 ,
struct V_316 * V_317 )
{
F_197 ( V_317 -> V_318 , V_303 ,
sizeof( V_317 -> V_318 ) ) ;
F_197 ( V_317 -> V_319 , V_320 ,
sizeof( V_317 -> V_319 ) ) ;
F_197 ( V_317 -> V_321 , F_198 ( & V_17 -> V_17 ) ,
sizeof( V_317 -> V_321 ) ) ;
}
static void F_199 ( struct V_16 * V_322 ,
struct V_323 * V_324 )
{
struct V_1 * V_2 = F_9 ( V_322 ) ;
V_324 -> V_325 = V_326 ;
V_324 -> V_327 = V_328 ;
V_324 -> V_329 = V_2 -> V_267 ;
V_324 -> V_330 = V_2 -> V_273 ;
}
static int F_200 ( struct V_16 * V_17 ,
struct V_323 * V_324 )
{
struct V_1 * V_2 = F_9 ( V_17 ) ;
if ( ( V_324 -> V_329 == 0 ) || ( V_324 -> V_330 == 0 ) )
return - V_248 ;
V_2 -> V_267 = V_324 -> V_329 < V_326 ?
V_324 -> V_329 : V_326 ;
V_2 -> V_273 = V_324 -> V_330 < V_328 ?
V_324 -> V_330 : V_328 ;
if ( F_115 ( V_17 ) ) {
F_186 ( V_17 ) ;
if ( F_183 ( V_17 ) ) {
F_76 ( V_17 ,
L_26 ) ;
return - V_202 ;
}
}
return 0 ;
}
static int F_201 ( struct V_1 * V_2 , int V_331 )
{
int V_69 ;
F_39 ( V_2 ) ;
F_43 ( V_2 ) ;
V_2 -> V_72 = F_202 ( V_71 * sizeof( struct V_6 ) ,
V_270 ) ;
if ( ! V_2 -> V_72 )
return - V_202 ;
for ( V_69 = 0 ; V_69 < V_71 ; V_69 ++ ) {
struct V_6 * V_7 = & V_2 -> V_72 [ V_69 ] ;
V_7 -> V_40 = V_69 ;
V_7 -> V_9 = V_2 -> V_273 ;
V_7 -> V_148 = V_235 ;
}
V_2 -> V_75 = F_202 ( V_74 * sizeof( struct V_36 ) ,
V_270 ) ;
if ( ! V_2 -> V_75 ) {
F_156 ( V_2 -> V_72 ) ;
return - V_202 ;
}
for ( V_69 = 0 ; V_69 < V_74 ; V_69 ++ ) {
struct V_36 * V_37 = & V_2 -> V_75 [ V_69 ] ;
V_37 -> V_40 = V_69 ;
V_37 -> V_9 = V_2 -> V_267 ;
V_37 -> V_143 = V_332 ;
V_37 -> V_146 = V_333 ;
}
return 0 ;
}
static void F_203 ( struct V_1 * V_2 )
{
F_156 ( V_2 -> V_72 ) ;
F_156 ( V_2 -> V_75 ) ;
}
static void F_204 ( struct V_1 * V_2 ,
const struct V_334 * V_335 )
{
T_1 V_336 ;
T_1 V_337 ;
int V_11 ;
for ( V_11 = 0 ; V_11 < 6 ; V_11 ++ ) {
F_1 ( V_2 , F_205 ( V_11 ) , 0 ) ;
F_1 ( V_2 , F_206 ( V_11 ) , 0 ) ;
if ( V_11 < 4 )
F_1 ( V_2 , F_207 ( V_11 ) , 0 ) ;
}
V_336 = 0x3f ;
V_337 = 0 ;
for ( V_11 = 0 ; V_11 < V_335 -> V_338 ; V_11 ++ ) {
const struct V_339 * V_340 = V_335 -> V_340 + V_11 ;
F_1 ( V_2 , F_205 ( V_11 ) , ( V_340 -> V_5 & 0xffff0000 ) |
( V_340 -> V_341 << 8 ) | V_335 -> V_342 ) ;
F_1 ( V_2 , F_206 ( V_11 ) ,
( V_340 -> V_9 - 1 ) & 0xffff0000 ) ;
V_336 &= ~ ( 1 << V_11 ) ;
V_337 |= 3 << ( 2 * V_11 ) ;
}
F_1 ( V_2 , V_343 , V_336 ) ;
}
static void F_208 ( struct V_1 * V_2 , int V_344 )
{
T_1 V_42 ;
F_1 ( V_2 , V_345 , 0 ) ;
if ( V_344 == V_346 )
F_32 ( V_2 ) ;
F_31 ( V_2 , 1 ) ;
V_42 = F_3 ( V_2 , V_64 ) ;
V_42 &= ~ V_347 ;
F_1 ( V_2 , V_64 , V_42 ) ;
while ( ( F_3 ( V_2 , V_64 ) &
V_347 ) != 0 )
continue;
}
static int F_209 ( struct V_348 * V_349 )
{
const struct V_334 * V_350 ;
struct V_351 * V_352 = V_349 -> V_17 . V_353 ;
struct V_351 * V_296 ;
T_1 V_331 ;
struct V_1 * V_2 ;
struct V_16 * V_17 ;
const char * V_354 ;
char V_355 [ V_240 ] ;
const char * V_356 ;
int V_344 ;
int V_216 ;
if ( V_112 != 0 ) {
F_210 ( & V_349 -> V_17 , L_27 , V_112 ) ;
return - V_248 ;
}
V_17 = F_211 ( sizeof( struct V_1 ) , V_71 , V_74 ) ;
if ( ! V_17 )
return - V_202 ;
V_17 -> V_259 = F_212 ( V_352 , 0 ) ;
if ( V_17 -> V_259 == 0 ) {
V_216 = - V_248 ;
goto V_357;
}
V_296 = F_213 ( V_352 , L_28 , 0 ) ;
if ( ! V_296 ) {
F_210 ( & V_349 -> V_17 , L_29 ) ;
V_216 = - V_298 ;
goto V_305;
}
V_344 = F_214 ( V_352 ) ;
if ( V_344 < 0 ) {
F_210 ( & V_349 -> V_17 , L_30 ) ;
V_216 = - V_248 ;
goto V_305;
}
V_17 -> V_358 = V_328 ;
V_17 -> V_359 = 5 * V_360 ;
V_17 -> V_361 = & V_362 ;
F_215 ( V_17 , & V_363 ) ;
V_2 = F_9 ( V_17 ) ;
V_2 -> V_364 = V_365 ;
V_2 -> V_296 = V_296 ;
V_2 -> V_297 = V_344 ;
V_2 -> V_145 = F_216 ( & V_349 -> V_17 , NULL ) ;
if ( F_217 ( V_2 -> V_145 ) ) {
V_216 = F_218 ( V_2 -> V_145 ) ;
goto V_305;
}
F_219 ( V_2 -> V_145 ) ;
V_2 -> V_5 = F_220 ( V_352 , 0 ) ;
if ( V_2 -> V_5 == NULL ) {
V_216 = - V_202 ;
goto V_366;
}
V_354 = F_221 ( V_352 ) ;
if ( V_354 && F_222 ( V_354 ) ) {
V_356 = L_31 ;
memcpy ( V_17 -> V_257 , V_354 , V_240 ) ;
} else {
F_176 ( V_2 , V_355 ) ;
if ( F_222 ( V_355 ) ) {
V_356 = L_32 ;
memcpy ( V_17 -> V_257 , V_355 , V_240 ) ;
} else {
V_356 = L_33 ;
F_223 ( V_17 ) ;
}
}
V_2 -> V_151 . V_4 = ( unsigned long ) V_17 ;
V_2 -> V_151 . V_367 = F_139 ;
F_224 ( & V_2 -> V_151 ) ;
F_140 ( V_149 , & V_2 -> V_150 ) ;
V_2 -> V_273 = V_328 ;
V_2 -> V_267 = V_326 ;
V_2 -> V_17 = V_17 ;
F_225 ( V_17 , & V_349 -> V_17 ) ;
V_216 = F_201 ( V_2 , V_331 ) ;
if ( V_216 < 0 ) {
F_210 ( & V_349 -> V_17 , L_34 ) ;
goto V_368;
}
F_208 ( V_2 , V_344 ) ;
V_350 = F_226 () ;
if ( V_350 )
F_204 ( V_2 , V_350 ) ;
F_227 ( V_17 , & V_2 -> V_219 , F_134 , V_2 -> V_364 ) ;
V_17 -> V_369 = V_370 | V_371 ;
V_17 -> V_372 |= V_370 | V_371 ;
V_17 -> V_373 |= V_370 | V_371 ;
V_17 -> V_374 |= V_375 ;
V_216 = F_228 ( V_17 ) ;
if ( V_216 < 0 ) {
F_210 ( & V_349 -> V_17 , L_35 ) ;
goto V_376;
}
F_127 ( V_17 , L_36 , V_356 ,
V_17 -> V_257 ) ;
F_229 ( V_349 , V_2 -> V_17 ) ;
return 0 ;
V_376:
F_203 ( V_2 ) ;
V_368:
F_230 ( V_2 -> V_5 ) ;
V_366:
F_231 ( V_2 -> V_145 ) ;
V_305:
F_232 ( V_17 -> V_259 ) ;
V_357:
F_233 ( V_17 ) ;
return V_216 ;
}
static int F_234 ( struct V_348 * V_349 )
{
struct V_16 * V_17 = F_235 ( V_349 ) ;
struct V_1 * V_2 = F_9 ( V_17 ) ;
F_236 ( V_17 ) ;
F_203 ( V_2 ) ;
F_231 ( V_2 -> V_145 ) ;
F_230 ( V_2 -> V_5 ) ;
F_232 ( V_17 -> V_259 ) ;
F_233 ( V_17 ) ;
return 0 ;
}
