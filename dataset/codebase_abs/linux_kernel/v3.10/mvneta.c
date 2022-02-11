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
}
static void F_33 ( struct V_1 * V_2 )
{
int V_67 ;
T_1 V_68 ;
F_7 ( V_2 ) ;
V_68 = 0 ;
for ( V_67 = 0 ; V_67 < V_69 ; V_67 ++ ) {
struct V_6 * V_7 = & V_2 -> V_70 [ V_67 ] ;
if ( V_7 -> V_48 != NULL )
V_68 |= ( 1 << V_67 ) ;
}
F_1 ( V_2 , V_71 , V_68 ) ;
V_68 = 0 ;
for ( V_67 = 0 ; V_67 < V_72 ; V_67 ++ ) {
struct V_36 * V_37 = & V_2 -> V_73 [ V_67 ] ;
if ( V_37 -> V_48 != NULL )
V_68 |= ( 1 << V_67 ) ;
}
F_1 ( V_2 , V_74 , V_68 ) ;
}
static void F_34 ( struct V_1 * V_2 )
{
T_1 V_42 ;
int V_75 ;
V_42 = F_3 ( V_2 , V_74 ) & V_76 ;
if ( V_42 != 0 )
F_1 ( V_2 , V_74 ,
V_42 << V_77 ) ;
V_75 = 0 ;
do {
if ( V_75 ++ >= V_78 ) {
F_35 ( V_2 -> V_17 ,
L_1 ,
V_42 ) ;
break;
}
F_36 ( 1 ) ;
V_42 = F_3 ( V_2 , V_74 ) ;
} while ( V_42 & 0xff );
V_42 = ( F_3 ( V_2 , V_71 ) ) & V_79 ;
if ( V_42 != 0 )
F_1 ( V_2 , V_71 ,
( V_42 << V_80 ) ) ;
V_75 = 0 ;
do {
if ( V_75 ++ >= V_81 ) {
F_35 ( V_2 -> V_17 ,
L_2 ,
V_42 ) ;
break;
}
F_36 ( 1 ) ;
V_42 = F_3 ( V_2 , V_71 ) ;
} while ( V_42 & 0xff );
V_75 = 0 ;
do {
if ( V_75 ++ >= V_82 ) {
F_35 ( V_2 -> V_17 ,
L_3 ,
V_42 ) ;
break;
}
F_36 ( 1 ) ;
V_42 = F_3 ( V_2 , V_83 ) ;
} while ( ! ( V_42 & V_84 ) &&
( V_42 & V_85 ) );
F_37 ( 200 ) ;
}
static void F_38 ( struct V_1 * V_2 )
{
T_1 V_42 ;
V_42 = F_3 ( V_2 , V_50 ) ;
V_42 |= V_86 ;
F_1 ( V_2 , V_50 , V_42 ) ;
}
static void F_39 ( struct V_1 * V_2 )
{
T_1 V_42 ;
V_42 = F_3 ( V_2 , V_50 ) ;
V_42 &= ~ V_86 ;
F_1 ( V_2 , V_50 , V_42 ) ;
F_37 ( 200 ) ;
}
static void F_40 ( struct V_1 * V_2 , int V_67 )
{
int V_3 ;
T_1 V_42 ;
if ( V_67 == - 1 ) {
V_42 = 0 ;
} else {
V_42 = 0x1 | ( V_67 << 1 ) ;
V_42 |= ( V_42 << 24 ) | ( V_42 << 16 ) | ( V_42 << 8 ) ;
}
for ( V_3 = 0 ; V_3 <= 0xc ; V_3 += 4 )
F_1 ( V_2 , V_87 + V_3 , V_42 ) ;
}
static void F_41 ( struct V_1 * V_2 , int V_67 )
{
int V_3 ;
T_1 V_42 ;
if ( V_67 == - 1 ) {
V_42 = 0 ;
} else {
V_42 = 0x1 | ( V_67 << 1 ) ;
V_42 |= ( V_42 << 24 ) | ( V_42 << 16 ) | ( V_42 << 8 ) ;
}
for ( V_3 = 0 ; V_3 <= 0xfc ; V_3 += 4 )
F_1 ( V_2 , V_88 + V_3 , V_42 ) ;
}
static void F_42 ( struct V_1 * V_2 , int V_67 )
{
int V_3 ;
T_1 V_42 ;
if ( V_67 == - 1 ) {
memset ( V_2 -> V_89 , 0 , sizeof( V_2 -> V_89 ) ) ;
V_42 = 0 ;
} else {
memset ( V_2 -> V_89 , 1 , sizeof( V_2 -> V_89 ) ) ;
V_42 = 0x1 | ( V_67 << 1 ) ;
V_42 |= ( V_42 << 24 ) | ( V_42 << 16 ) | ( V_42 << 8 ) ;
}
for ( V_3 = 0 ; V_3 <= 0xfc ; V_3 += 4 )
F_1 ( V_2 , V_90 + V_3 , V_42 ) ;
}
static void F_43 ( struct V_1 * V_2 )
{
int V_91 ;
int V_67 ;
T_1 V_42 ;
F_1 ( V_2 , V_92 , 0 ) ;
F_1 ( V_2 , V_93 , 0 ) ;
F_1 ( V_2 , V_94 , 0 ) ;
F_1 ( V_2 , V_95 , 0 ) ;
F_1 ( V_2 , V_96 , 0 ) ;
F_1 ( V_2 , V_97 , 0 ) ;
F_1 ( V_2 , V_98 , 0 ) ;
F_1 ( V_2 , V_99 , 0x20 ) ;
for ( V_91 = 0 ; V_91 < V_100 ; V_91 ++ )
F_1 ( V_2 , F_44 ( V_91 ) ,
( V_101 |
V_102 ) ) ;
F_1 ( V_2 , V_103 , V_104 ) ;
F_1 ( V_2 , V_105 , V_106 ) ;
F_1 ( V_2 , V_107 , 0 ) ;
for ( V_67 = 0 ; V_67 < V_69 ; V_67 ++ ) {
F_1 ( V_2 , F_45 ( V_67 ) , 0 ) ;
F_1 ( V_2 , F_46 ( V_67 ) , 0 ) ;
}
F_1 ( V_2 , V_105 , 0 ) ;
F_1 ( V_2 , V_103 , 0 ) ;
V_42 = V_108 ;
F_1 ( V_2 , V_109 , V_42 ) ;
V_42 = F_47 ( V_110 ) ;
F_1 ( V_2 , V_111 , V_42 ) ;
V_42 = 0 ;
F_1 ( V_2 , V_112 , V_42 ) ;
F_1 ( V_2 , V_113 , 64 ) ;
V_42 = 0 ;
V_42 |= F_48 ( V_114 ) ;
V_42 |= F_49 ( V_114 ) ;
V_42 |= ( V_115 | V_116 |
V_117 ) ;
F_1 ( V_2 , V_118 , V_42 ) ;
F_40 ( V_2 , - 1 ) ;
F_41 ( V_2 , - 1 ) ;
F_42 ( V_2 , - 1 ) ;
F_1 ( V_2 , V_98 ,
( V_119
| V_120 ) ) ;
}
static void F_50 ( struct V_1 * V_2 , int V_121 )
{
T_1 V_42 , V_9 , V_122 ;
int V_67 ;
V_122 = V_121 * 8 ;
if ( V_122 > V_123 )
V_122 = V_123 ;
V_42 = F_3 ( V_2 , V_124 ) ;
V_42 &= ~ V_123 ;
V_42 |= V_122 ;
F_1 ( V_2 , V_124 , V_42 ) ;
V_42 = F_3 ( V_2 , V_125 ) ;
V_9 = V_42 & V_126 ;
if ( V_9 < V_122 ) {
V_9 = V_122 ;
V_42 &= ~ V_126 ;
V_42 |= V_9 ;
F_1 ( V_2 , V_125 , V_42 ) ;
}
for ( V_67 = 0 ; V_67 < V_69 ; V_67 ++ ) {
V_42 = F_3 ( V_2 , F_51 ( V_67 ) ) ;
V_9 = V_42 & V_127 ;
if ( V_9 < V_122 ) {
V_9 = V_122 ;
V_42 &= ~ V_127 ;
V_42 |= V_9 ;
F_1 ( V_2 , F_51 ( V_67 ) , V_42 ) ;
}
}
}
static void F_52 ( struct V_1 * V_2 , T_2 V_128 ,
int V_67 )
{
unsigned int V_129 ;
unsigned int V_130 ;
unsigned int V_131 ;
V_128 = ( 0xf & V_128 ) ;
V_130 = ( V_128 / 4 ) * 4 ;
V_131 = V_128 % 4 ;
V_129 = F_3 ( V_2 , ( V_87 + V_130 ) ) ;
if ( V_67 == - 1 ) {
V_129 &= ~ ( 0xff << ( 8 * V_131 ) ) ;
} else {
V_129 &= ~ ( 0xff << ( 8 * V_131 ) ) ;
V_129 |= ( ( 0x01 | ( V_67 << 1 ) ) << ( 8 * V_131 ) ) ;
}
F_1 ( V_2 , ( V_87 + V_130 ) , V_129 ) ;
}
static void F_53 ( struct V_1 * V_2 , unsigned char * V_132 ,
int V_67 )
{
unsigned int V_133 ;
unsigned int V_134 ;
if ( V_67 != - 1 ) {
V_134 = ( V_132 [ 4 ] << 8 ) | ( V_132 [ 5 ] ) ;
V_133 = ( V_132 [ 0 ] << 24 ) | ( V_132 [ 1 ] << 16 ) |
( V_132 [ 2 ] << 8 ) | ( V_132 [ 3 ] << 0 ) ;
F_1 ( V_2 , V_135 , V_134 ) ;
F_1 ( V_2 , V_136 , V_133 ) ;
}
F_52 ( V_2 , V_132 [ 5 ] , V_67 ) ;
}
static void F_54 ( struct V_1 * V_2 ,
struct V_36 * V_37 , T_1 V_137 )
{
F_1 ( V_2 , F_55 ( V_37 -> V_40 ) ,
V_137 | F_56 ( 0 ) ) ;
V_37 -> V_138 = V_137 ;
}
static void F_57 ( struct V_1 * V_2 ,
struct V_36 * V_37 , T_1 V_137 )
{
T_1 V_42 ;
unsigned long V_139 ;
V_139 = F_58 ( V_2 -> V_140 ) ;
V_42 = ( V_139 / 1000000 ) * V_137 ;
F_1 ( V_2 , F_59 ( V_37 -> V_40 ) , V_42 ) ;
V_37 -> V_141 = V_137 ;
}
static void F_60 ( struct V_1 * V_2 ,
struct V_6 * V_7 , T_1 V_137 )
{
T_1 V_42 ;
V_42 = F_3 ( V_2 , F_61 ( V_7 -> V_40 ) ) ;
V_42 &= ~ V_142 ;
V_42 |= F_62 ( V_137 ) ;
F_1 ( V_2 , F_61 ( V_7 -> V_40 ) , V_42 ) ;
V_7 -> V_143 = V_137 ;
}
static void F_63 ( struct V_1 * V_2 )
{
if ( F_64 ( V_144 , & V_2 -> V_145 ) == 0 ) {
V_2 -> V_146 . V_147 = V_148 +
F_65 ( V_149 ) ;
F_66 ( & V_2 -> V_146 ) ;
}
}
static void F_67 ( struct V_32 * V_46 ,
T_1 V_150 , T_1 V_151 )
{
V_46 -> V_152 = V_151 ;
V_46 -> V_153 = V_150 ;
}
static void F_68 ( struct V_1 * V_2 ,
struct V_6 * V_7 ,
int V_154 )
{
T_1 V_42 ;
while ( V_154 > 0xff ) {
V_42 = 0xff << V_155 ;
F_1 ( V_2 , F_25 ( V_7 -> V_40 ) , V_42 ) ;
V_154 = V_154 - 0xff ;
}
V_42 = V_154 << V_155 ;
F_1 ( V_2 , F_25 ( V_7 -> V_40 ) , V_42 ) ;
}
static int F_69 ( struct V_1 * V_2 ,
struct V_6 * V_7 )
{
T_1 V_42 ;
int V_154 ;
V_42 = F_3 ( V_2 , F_70 ( V_7 -> V_40 ) ) ;
V_154 = ( V_42 & V_156 ) >>
V_157 ;
return V_154 ;
}
static int F_71 ( struct V_1 * V_2 ,
struct V_6 * V_7 )
{
int V_154 ;
V_154 = F_69 ( V_2 , V_7 ) ;
if ( V_154 )
F_68 ( V_2 , V_7 , V_154 ) ;
return V_154 ;
}
static T_1 F_72 ( int V_158 , int V_159 ,
int V_160 , int V_161 )
{
T_1 V_162 ;
V_162 = V_158 << V_163 ;
V_162 |= V_160 << V_164 ;
if ( V_159 == F_73 ( V_165 ) )
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
static void F_74 ( struct V_1 * V_2 ,
struct V_32 * V_46 )
{
T_1 V_34 = V_46 -> V_34 ;
if ( ! F_12 ( V_46 ) ) {
F_75 ( V_2 -> V_17 ,
L_4 ,
V_46 -> V_34 , V_46 -> V_173 ) ;
return;
}
switch ( V_34 & V_174 ) {
case V_175 :
F_75 ( V_2 -> V_17 , L_5 ,
V_34 , V_46 -> V_173 ) ;
break;
case V_176 :
F_75 ( V_2 -> V_17 , L_6 ,
V_34 , V_46 -> V_173 ) ;
break;
case V_177 :
F_75 ( V_2 -> V_17 , L_7 ,
V_34 , V_46 -> V_173 ) ;
break;
case V_178 :
F_75 ( V_2 -> V_17 , L_8 ,
V_34 , V_46 -> V_173 ) ;
break;
}
}
static void F_76 ( struct V_1 * V_2 ,
struct V_32 * V_46 ,
struct V_179 * V_180 )
{
if ( ( V_46 -> V_34 & V_181 ) &&
( V_46 -> V_34 & V_182 ) ) {
V_180 -> V_183 = 0 ;
V_180 -> V_184 = V_185 ;
return;
}
V_180 -> V_184 = V_186 ;
}
static struct V_6 * F_77 ( struct V_1 * V_2 ,
T_1 V_187 )
{
int V_67 = F_78 ( V_187 ) - 1 ;
return ( V_67 < 0 || V_67 >= V_69 ) ? NULL : & V_2 -> V_70 [ V_67 ] ;
}
static void F_79 ( struct V_1 * V_2 ,
struct V_6 * V_7 , int V_188 )
{
int V_11 ;
for ( V_11 = 0 ; V_11 < V_188 ; V_11 ++ ) {
struct V_56 * V_57 = V_7 -> V_48 +
V_7 -> V_8 ;
struct V_179 * V_180 = V_7 -> V_189 [ V_7 -> V_8 ] ;
F_5 ( V_7 ) ;
if ( ! V_180 )
continue;
F_80 ( V_2 -> V_17 -> V_17 . V_190 , V_57 -> V_153 ,
V_57 -> V_173 , V_191 ) ;
F_81 ( V_180 ) ;
}
}
static int F_82 ( struct V_1 * V_2 ,
struct V_6 * V_7 )
{
struct V_192 * V_193 = F_83 ( V_2 -> V_17 , V_7 -> V_40 ) ;
int V_194 ;
V_194 = F_71 ( V_2 , V_7 ) ;
if ( V_194 == 0 )
return V_194 ;
F_79 ( V_2 , V_7 , V_194 ) ;
V_7 -> V_75 -= V_194 ;
if ( F_84 ( V_193 ) ) {
if ( V_7 -> V_9 - V_7 -> V_75 >= V_195 + 1 )
F_85 ( V_193 ) ;
}
return V_194 ;
}
static int F_86 ( struct V_1 * V_2 ,
struct V_32 * V_46 )
{
T_3 V_150 ;
struct V_179 * V_180 ;
V_180 = F_87 ( V_2 -> V_17 , V_2 -> V_196 ) ;
if ( ! V_180 )
return - V_197 ;
V_150 = F_88 ( V_2 -> V_17 -> V_17 . V_190 , V_180 -> V_198 ,
F_89 ( V_2 -> V_196 ) ,
V_199 ) ;
if ( F_90 ( F_91 ( V_2 -> V_17 -> V_17 . V_190 , V_150 ) ) ) {
F_92 ( V_180 ) ;
return - V_197 ;
}
F_67 ( V_46 , V_150 , ( T_1 ) V_180 ) ;
return 0 ;
}
static T_1 F_93 ( struct V_1 * V_2 , struct V_179 * V_180 )
{
if ( V_180 -> V_184 == V_200 ) {
int V_160 = 0 ;
T_2 V_161 ;
if ( V_180 -> V_201 == F_94 ( V_165 ) ) {
struct V_202 * V_203 = F_95 ( V_180 ) ;
V_160 = V_203 -> V_204 ;
V_161 = V_203 -> V_201 ;
} else if ( V_180 -> V_201 == F_94 ( V_205 ) ) {
struct V_206 * V_207 = F_96 ( V_180 ) ;
if ( F_97 ( V_180 ) > 0 )
V_160 = ( F_97 ( V_180 ) >> 2 ) ;
V_161 = V_207 -> V_208 ;
} else
return V_172 ;
return F_72 ( F_98 ( V_180 ) ,
V_180 -> V_201 , V_160 , V_161 ) ;
}
return V_172 ;
}
static struct V_36 * F_99 ( struct V_1 * V_2 ,
T_1 V_187 )
{
int V_67 = F_78 ( V_187 >> 8 ) - 1 ;
return ( V_67 < 0 || V_67 >= V_72 ) ? NULL : & V_2 -> V_73 [ V_67 ] ;
}
static void F_100 ( struct V_1 * V_2 ,
struct V_36 * V_37 )
{
int V_44 , V_11 ;
V_44 = F_15 ( V_2 , V_37 ) ;
for ( V_11 = 0 ; V_11 < V_37 -> V_9 ; V_11 ++ ) {
struct V_32 * V_46 = V_37 -> V_48 + V_11 ;
struct V_179 * V_180 = (struct V_179 * ) V_46 -> V_152 ;
F_81 ( V_180 ) ;
F_80 ( V_2 -> V_17 -> V_17 . V_190 , V_46 -> V_153 ,
V_46 -> V_173 , V_199 ) ;
}
if ( V_44 )
F_17 ( V_2 , V_37 , V_44 , V_44 ) ;
}
static int F_101 ( struct V_1 * V_2 , int V_209 ,
struct V_36 * V_37 )
{
struct V_16 * V_17 = V_2 -> V_17 ;
int V_44 , V_45 ;
V_44 = F_15 ( V_2 , V_37 ) ;
if ( V_209 > V_44 )
V_209 = V_44 ;
V_44 = 0 ;
V_45 = 0 ;
while ( V_44 < V_209 ) {
struct V_32 * V_46 = F_18 ( V_37 ) ;
struct V_179 * V_180 ;
T_1 V_210 ;
int V_24 , V_211 ;
F_102 ( V_46 ) ;
V_44 ++ ;
V_45 ++ ;
V_210 = V_46 -> V_34 ;
V_180 = (struct V_179 * ) V_46 -> V_152 ;
if ( ! F_12 ( V_46 ) ||
( V_210 & V_212 ) ) {
V_17 -> V_18 . V_29 ++ ;
F_74 ( V_2 , V_46 ) ;
F_67 ( V_46 , V_46 -> V_153 ,
( T_1 ) V_180 ) ;
continue;
}
F_80 ( V_2 -> V_17 -> V_17 . V_190 , V_46 -> V_153 ,
V_46 -> V_173 , V_199 ) ;
V_24 = V_46 -> V_173 -
( V_213 + V_52 ) ;
F_103 ( & V_2 -> V_20 . V_21 ) ;
V_2 -> V_20 . V_23 ++ ;
V_2 -> V_20 . V_25 += V_24 ;
F_104 ( & V_2 -> V_20 . V_21 ) ;
F_105 ( V_180 , V_52 ) ;
F_106 ( V_180 , V_24 ) ;
V_180 -> V_201 = F_107 ( V_180 , V_17 ) ;
F_76 ( V_2 , V_46 , V_180 ) ;
F_108 ( & V_2 -> V_214 , V_180 ) ;
V_211 = F_86 ( V_2 , V_46 ) ;
if ( V_211 ) {
F_75 ( V_2 -> V_17 , L_9 ) ;
V_37 -> V_215 ++ ;
V_45 -- ;
}
}
F_17 ( V_2 , V_37 , V_44 , V_45 ) ;
return V_44 ;
}
static int F_109 ( struct V_1 * V_2 , struct V_179 * V_180 ,
struct V_6 * V_7 )
{
struct V_56 * V_57 ;
int V_11 ;
for ( V_11 = 0 ; V_11 < F_110 ( V_180 ) -> V_216 ; V_11 ++ ) {
T_4 * V_217 = & F_110 ( V_180 ) -> V_218 [ V_11 ] ;
void * V_132 = F_111 ( V_217 -> V_219 . V_220 ) + V_217 -> V_221 ;
V_57 = F_26 ( V_7 ) ;
V_57 -> V_173 = V_217 -> V_9 ;
V_57 -> V_153 =
F_88 ( V_2 -> V_17 -> V_17 . V_190 , V_132 ,
V_57 -> V_173 , V_191 ) ;
if ( F_91 ( V_2 -> V_17 -> V_17 . V_190 ,
V_57 -> V_153 ) ) {
F_27 ( V_7 ) ;
goto error;
}
if ( V_11 == ( F_110 ( V_180 ) -> V_216 - 1 ) ) {
V_57 -> V_162 = V_222 | V_223 ;
V_7 -> V_189 [ V_7 -> V_10 ] = V_180 ;
F_6 ( V_7 ) ;
} else {
V_57 -> V_162 = 0 ;
V_7 -> V_189 [ V_7 -> V_10 ] = NULL ;
F_6 ( V_7 ) ;
}
}
return 0 ;
error:
for ( V_11 = V_11 - 1 ; V_11 >= 0 ; V_11 -- ) {
V_57 = V_7 -> V_48 + V_11 ;
F_80 ( V_2 -> V_17 -> V_17 . V_190 ,
V_57 -> V_153 ,
V_57 -> V_173 ,
V_191 ) ;
F_27 ( V_7 ) ;
}
return - V_197 ;
}
static int F_112 ( struct V_179 * V_180 , struct V_16 * V_17 )
{
struct V_1 * V_2 = F_9 ( V_17 ) ;
T_5 V_224 = F_113 ( V_180 ) ;
struct V_6 * V_7 = & V_2 -> V_70 [ V_224 ] ;
struct V_56 * V_57 ;
struct V_192 * V_193 ;
int V_218 = 0 ;
T_1 V_225 ;
if ( ! F_114 ( V_17 ) )
goto V_226;
V_218 = F_110 ( V_180 ) -> V_216 + 1 ;
V_193 = F_83 ( V_17 , V_224 ) ;
V_57 = F_26 ( V_7 ) ;
V_225 = F_93 ( V_2 , V_180 ) ;
V_57 -> V_173 = F_115 ( V_180 ) ;
V_57 -> V_153 = F_88 ( V_17 -> V_17 . V_190 , V_180 -> V_4 ,
V_57 -> V_173 ,
V_191 ) ;
if ( F_90 ( F_91 ( V_17 -> V_17 . V_190 ,
V_57 -> V_153 ) ) ) {
F_27 ( V_7 ) ;
V_218 = 0 ;
goto V_226;
}
if ( V_218 == 1 ) {
V_225 |= V_227 ;
V_57 -> V_162 = V_225 ;
V_7 -> V_189 [ V_7 -> V_10 ] = V_180 ;
F_6 ( V_7 ) ;
} else {
V_225 |= V_228 ;
V_7 -> V_189 [ V_7 -> V_10 ] = NULL ;
F_6 ( V_7 ) ;
V_57 -> V_162 = V_225 ;
if ( F_109 ( V_2 , V_180 , V_7 ) ) {
F_80 ( V_17 -> V_17 . V_190 ,
V_57 -> V_153 ,
V_57 -> V_173 ,
V_191 ) ;
F_27 ( V_7 ) ;
V_218 = 0 ;
goto V_226;
}
}
V_7 -> V_75 += V_218 ;
F_24 ( V_2 , V_7 , V_218 ) ;
if ( V_7 -> V_9 - V_7 -> V_75 < V_195 + 1 )
F_116 ( V_193 ) ;
V_226:
if ( V_218 > 0 ) {
F_103 ( & V_2 -> V_26 . V_21 ) ;
V_2 -> V_26 . V_23 ++ ;
V_2 -> V_26 . V_25 += V_180 -> V_229 ;
F_104 ( & V_2 -> V_26 . V_21 ) ;
} else {
V_17 -> V_18 . V_31 ++ ;
F_81 ( V_180 ) ;
}
if ( V_7 -> V_75 >= V_230 )
F_82 ( V_2 , V_7 ) ;
if ( V_7 -> V_75 == V_218 && V_218 > 0 )
F_63 ( V_2 ) ;
return V_231 ;
}
static void F_117 ( struct V_1 * V_2 ,
struct V_6 * V_7 )
{
int V_194 = V_7 -> V_75 ;
F_79 ( V_2 , V_7 , V_194 ) ;
V_7 -> V_75 = 0 ;
V_7 -> V_10 = 0 ;
V_7 -> V_8 = 0 ;
}
static T_1 F_118 ( struct V_1 * V_2 , T_1 V_232 ,
int * V_233 )
{
struct V_6 * V_7 ;
T_1 V_194 = 0 ;
struct V_192 * V_193 ;
* V_233 = 0 ;
while ( V_232 != 0 ) {
V_7 = F_77 ( V_2 , V_232 ) ;
if ( ! V_7 )
break;
V_193 = F_83 ( V_2 -> V_17 , V_7 -> V_40 ) ;
F_119 ( V_193 , F_120 () ) ;
if ( V_7 -> V_75 ) {
V_194 += F_82 ( V_2 , V_7 ) ;
* V_233 += V_7 -> V_75 ;
}
F_121 ( V_193 ) ;
V_232 &= ~ ( ( 1 << V_7 -> V_40 ) ) ;
}
return V_194 ;
}
static int F_122 ( unsigned char * V_132 )
{
int V_234 = 0 ;
int V_11 ;
for ( V_11 = 0 ; V_11 < V_235 ; V_11 ++ ) {
int V_236 ;
V_234 = ( V_234 ^ V_132 [ V_11 ] ) << 8 ;
for ( V_236 = 7 ; V_236 >= 0 ; V_236 -- ) {
if ( V_234 & ( 0x100 << V_236 ) )
V_234 ^= 0x107 << V_236 ;
}
}
return V_234 ;
}
static void F_123 ( struct V_1 * V_2 ,
unsigned char V_237 ,
int V_67 )
{
unsigned int V_238 ;
unsigned int V_130 ;
unsigned int V_131 ;
V_130 = ( V_237 / 4 ) ;
V_131 = V_237 % 4 ;
V_238 = F_3 ( V_2 , ( V_88
+ V_130 * 4 ) ) ;
if ( V_67 == - 1 )
V_238 &= ~ ( 0xff << ( 8 * V_131 ) ) ;
else {
V_238 &= ~ ( 0xff << ( 8 * V_131 ) ) ;
V_238 |= ( ( 0x01 | ( V_67 << 1 ) ) << ( 8 * V_131 ) ) ;
}
F_1 ( V_2 , V_88 + V_130 * 4 ,
V_238 ) ;
}
static void F_124 ( struct V_1 * V_2 ,
unsigned char V_239 ,
int V_67 )
{
unsigned int V_240 ;
unsigned int V_130 ;
unsigned int V_131 ;
V_130 = ( V_239 / 4 ) * 4 ;
V_131 = V_239 % 4 ;
V_240 = F_3 ( V_2 , V_90 + V_130 ) ;
if ( V_67 == - 1 ) {
V_240 &= ~ ( 0xff << ( 8 * V_131 ) ) ;
} else {
V_240 &= ~ ( 0xff << ( 8 * V_131 ) ) ;
V_240 |= ( ( 0x01 | ( V_67 << 1 ) ) << ( 8 * V_131 ) ) ;
}
F_1 ( V_2 , V_90 + V_130 , V_240 ) ;
}
static int F_125 ( struct V_1 * V_2 , unsigned char * V_241 ,
int V_67 )
{
unsigned char V_242 = 0 ;
if ( memcmp ( V_241 , L_10 , 5 ) == 0 ) {
F_123 ( V_2 , V_241 [ 5 ] , V_67 ) ;
return 0 ;
}
V_242 = F_122 ( V_241 ) ;
if ( V_67 == - 1 ) {
if ( V_2 -> V_89 [ V_242 ] == 0 ) {
F_126 ( V_2 -> V_17 , L_11 ,
V_242 ) ;
return - V_243 ;
}
V_2 -> V_89 [ V_242 ] -- ;
if ( V_2 -> V_89 [ V_242 ] != 0 ) {
F_126 ( V_2 -> V_17 ,
L_12 ,
V_2 -> V_89 [ V_242 ] , V_242 ) ;
return - V_243 ;
}
} else
V_2 -> V_89 [ V_242 ] ++ ;
F_124 ( V_2 , V_242 , V_67 ) ;
return 0 ;
}
static void F_127 ( struct V_1 * V_2 ,
int V_244 )
{
T_1 V_245 , V_42 ;
V_245 = F_3 ( V_2 , V_111 ) ;
V_42 = F_3 ( V_2 , V_246 ) ;
if ( V_244 ) {
V_245 |= V_247 ;
V_42 |= V_248 ;
F_1 ( V_2 , V_135 , 0xffff ) ;
F_1 ( V_2 , V_136 , 0xffffffff ) ;
} else {
V_245 &= ~ V_247 ;
V_42 &= ~ V_248 ;
}
F_1 ( V_2 , V_111 , V_245 ) ;
F_1 ( V_2 , V_246 , V_42 ) ;
}
static void F_128 ( struct V_16 * V_17 )
{
struct V_1 * V_2 = F_9 ( V_17 ) ;
struct V_249 * V_250 ;
if ( V_17 -> V_145 & V_251 ) {
F_127 ( V_2 , 1 ) ;
F_40 ( V_2 , V_110 ) ;
F_41 ( V_2 , V_110 ) ;
F_42 ( V_2 , V_110 ) ;
} else {
F_127 ( V_2 , 0 ) ;
F_40 ( V_2 , - 1 ) ;
F_53 ( V_2 , V_17 -> V_252 , V_110 ) ;
if ( V_17 -> V_145 & V_253 ) {
F_41 ( V_2 , V_110 ) ;
F_42 ( V_2 , V_110 ) ;
} else {
F_41 ( V_2 , - 1 ) ;
F_42 ( V_2 , - 1 ) ;
if ( ! F_129 ( V_17 ) ) {
F_130 (ha, dev) {
F_125 ( V_2 , V_250 -> V_132 ,
V_110 ) ;
}
}
}
}
}
static T_6 F_131 ( int V_254 , void * V_255 )
{
struct V_1 * V_2 = (struct V_1 * ) V_255 ;
F_1 ( V_2 , V_95 , 0 ) ;
F_132 ( & V_2 -> V_214 ) ;
return V_256 ;
}
static int F_133 ( struct V_257 * V_214 , int V_258 )
{
int V_44 = 0 ;
T_1 V_259 ;
unsigned long V_145 ;
struct V_1 * V_2 = F_9 ( V_214 -> V_17 ) ;
if ( ! F_114 ( V_2 -> V_17 ) ) {
F_134 ( V_214 ) ;
return V_44 ;
}
V_259 = F_3 ( V_2 , V_92 ) &
F_135 ( V_72 ) ;
V_259 |= V_2 -> V_259 ;
if ( V_72 > 1 ) {
while ( ( V_259 != 0 ) && ( V_258 > 0 ) ) {
int V_75 ;
struct V_36 * V_37 ;
V_37 = F_99 ( V_2 , V_259 ) ;
if ( ! V_37 )
break;
V_75 = F_101 ( V_2 , V_258 , V_37 ) ;
V_44 += V_75 ;
V_258 -= V_75 ;
if ( V_258 > 0 ) {
V_259 &= ~ ( ( 1 << V_37 -> V_40 ) << 8 ) ;
}
}
} else {
V_44 = F_101 ( V_2 , V_258 , & V_2 -> V_73 [ V_110 ] ) ;
V_258 -= V_44 ;
}
if ( V_258 > 0 ) {
V_259 = 0 ;
F_134 ( V_214 ) ;
F_136 ( V_145 ) ;
F_1 ( V_2 , V_95 ,
F_135 ( V_72 ) ) ;
F_137 ( V_145 ) ;
}
V_2 -> V_259 = V_259 ;
return V_44 ;
}
static void F_138 ( unsigned long V_4 )
{
struct V_16 * V_17 = (struct V_16 * ) V_4 ;
struct V_1 * V_2 = F_9 ( V_17 ) ;
int V_194 = 0 , V_233 = 0 ;
if ( ! F_114 ( V_17 ) )
return ;
F_139 ( V_144 , & V_2 -> V_145 ) ;
V_194 = F_118 ( V_2 ,
( ( ( 1 << V_69 ) - 1 ) &
V_260 ) ,
& V_233 ) ;
if ( V_233 > 0 )
F_63 ( V_2 ) ;
}
static int F_140 ( struct V_1 * V_2 , struct V_36 * V_37 ,
int V_188 )
{
struct V_16 * V_17 = V_2 -> V_17 ;
int V_11 ;
for ( V_11 = 0 ; V_11 < V_188 ; V_11 ++ ) {
struct V_179 * V_180 ;
struct V_32 * V_46 ;
unsigned long V_150 ;
V_180 = F_141 ( V_2 -> V_196 ) ;
if ( ! V_180 ) {
F_75 ( V_17 , L_13 ,
V_261 , V_37 -> V_40 , V_11 , V_188 ) ;
break;
}
V_46 = V_37 -> V_48 + V_11 ;
memset ( V_46 , 0 , sizeof( struct V_32 ) ) ;
V_150 = F_88 ( V_17 -> V_17 . V_190 , V_180 -> V_198 ,
F_89 ( V_2 -> V_196 ) ,
V_199 ) ;
if ( F_90 ( F_91 ( V_17 -> V_17 . V_190 , V_150 ) ) ) {
F_92 ( V_180 ) ;
break;
}
F_67 ( V_46 , V_150 , ( T_1 ) V_180 ) ;
}
F_13 ( V_2 , V_37 , V_11 ) ;
return V_11 ;
}
static void F_142 ( struct V_1 * V_2 )
{
int V_67 ;
for ( V_67 = 0 ; V_67 < V_69 ; V_67 ++ )
F_117 ( V_2 , & V_2 -> V_70 [ V_67 ] ) ;
F_1 ( V_2 , V_105 , V_106 ) ;
F_1 ( V_2 , V_105 , 0 ) ;
}
static void F_143 ( struct V_1 * V_2 )
{
F_1 ( V_2 , V_103 , V_104 ) ;
F_1 ( V_2 , V_103 , 0 ) ;
}
static int F_144 ( struct V_1 * V_2 ,
struct V_36 * V_37 )
{
V_37 -> V_9 = V_2 -> V_262 ;
V_37 -> V_48 = F_145 ( V_2 -> V_17 -> V_17 . V_190 ,
V_37 -> V_9 * V_263 ,
& V_37 -> V_264 , V_265 ) ;
if ( V_37 -> V_48 == NULL )
return - V_197 ;
F_146 ( V_37 -> V_48 !=
F_147 ( V_37 -> V_48 , V_266 ) ) ;
V_37 -> V_58 = V_37 -> V_9 - 1 ;
F_1 ( V_2 , F_148 ( V_37 -> V_40 ) , V_37 -> V_264 ) ;
F_1 ( V_2 , F_29 ( V_37 -> V_40 ) , V_37 -> V_9 ) ;
F_21 ( V_2 , V_37 , V_267 ) ;
F_54 ( V_2 , V_37 , V_37 -> V_138 ) ;
F_57 ( V_2 , V_37 , V_37 -> V_141 ) ;
F_28 ( V_2 , V_37 , F_89 ( V_2 -> V_196 ) ) ;
F_30 ( V_2 , V_37 ) ;
F_140 ( V_2 , V_37 , V_37 -> V_9 ) ;
return 0 ;
}
static void F_149 ( struct V_1 * V_2 ,
struct V_36 * V_37 )
{
F_100 ( V_2 , V_37 ) ;
if ( V_37 -> V_48 )
F_150 ( V_2 -> V_17 -> V_17 . V_190 ,
V_37 -> V_9 * V_263 ,
V_37 -> V_48 ,
V_37 -> V_264 ) ;
V_37 -> V_48 = NULL ;
V_37 -> V_58 = 0 ;
V_37 -> V_47 = 0 ;
V_37 -> V_264 = 0 ;
}
static int F_151 ( struct V_1 * V_2 ,
struct V_6 * V_7 )
{
V_7 -> V_9 = V_2 -> V_268 ;
V_7 -> V_48 = F_145 ( V_2 -> V_17 -> V_17 . V_190 ,
V_7 -> V_9 * V_263 ,
& V_7 -> V_264 , V_265 ) ;
if ( V_7 -> V_48 == NULL )
return - V_197 ;
F_146 ( V_7 -> V_48 !=
F_147 ( V_7 -> V_48 , V_266 ) ) ;
V_7 -> V_58 = V_7 -> V_9 - 1 ;
F_1 ( V_2 , F_46 ( V_7 -> V_40 ) , 0x03ffffff ) ;
F_1 ( V_2 , F_45 ( V_7 -> V_40 ) , 0x3fffffff ) ;
F_1 ( V_2 , F_152 ( V_7 -> V_40 ) , V_7 -> V_264 ) ;
F_1 ( V_2 , F_61 ( V_7 -> V_40 ) , V_7 -> V_9 ) ;
V_7 -> V_189 = F_153 ( V_7 -> V_9 * sizeof( * V_7 -> V_189 ) , V_265 ) ;
if ( V_7 -> V_189 == NULL ) {
F_150 ( V_2 -> V_17 -> V_17 . V_190 ,
V_7 -> V_9 * V_263 ,
V_7 -> V_48 , V_7 -> V_264 ) ;
return - V_197 ;
}
F_60 ( V_2 , V_7 , V_7 -> V_143 ) ;
return 0 ;
}
static void F_154 ( struct V_1 * V_2 ,
struct V_6 * V_7 )
{
F_155 ( V_7 -> V_189 ) ;
if ( V_7 -> V_48 )
F_150 ( V_2 -> V_17 -> V_17 . V_190 ,
V_7 -> V_9 * V_263 ,
V_7 -> V_48 , V_7 -> V_264 ) ;
V_7 -> V_48 = NULL ;
V_7 -> V_58 = 0 ;
V_7 -> V_47 = 0 ;
V_7 -> V_264 = 0 ;
F_1 ( V_2 , F_46 ( V_7 -> V_40 ) , 0 ) ;
F_1 ( V_2 , F_45 ( V_7 -> V_40 ) , 0 ) ;
F_1 ( V_2 , F_152 ( V_7 -> V_40 ) , 0 ) ;
F_1 ( V_2 , F_61 ( V_7 -> V_40 ) , 0 ) ;
}
static void F_156 ( struct V_1 * V_2 )
{
int V_67 ;
for ( V_67 = 0 ; V_67 < V_69 ; V_67 ++ )
F_154 ( V_2 , & V_2 -> V_70 [ V_67 ] ) ;
}
static void F_157 ( struct V_1 * V_2 )
{
int V_67 ;
for ( V_67 = 0 ; V_67 < V_72 ; V_67 ++ )
F_149 ( V_2 , & V_2 -> V_73 [ V_67 ] ) ;
}
static int F_158 ( struct V_1 * V_2 )
{
int V_67 ;
for ( V_67 = 0 ; V_67 < V_72 ; V_67 ++ ) {
int V_211 = F_144 ( V_2 , & V_2 -> V_73 [ V_67 ] ) ;
if ( V_211 ) {
F_75 ( V_2 -> V_17 , L_14 ,
V_261 , V_67 ) ;
F_157 ( V_2 ) ;
return V_211 ;
}
}
return 0 ;
}
static int F_159 ( struct V_1 * V_2 )
{
int V_67 ;
for ( V_67 = 0 ; V_67 < V_69 ; V_67 ++ ) {
int V_211 = F_151 ( V_2 , & V_2 -> V_70 [ V_67 ] ) ;
if ( V_211 ) {
F_75 ( V_2 -> V_17 , L_15 ,
V_261 , V_67 ) ;
F_156 ( V_2 ) ;
return V_211 ;
}
}
return 0 ;
}
static void F_160 ( struct V_1 * V_2 )
{
F_20 ( V_2 , V_2 -> V_196 ) ;
F_50 ( V_2 , V_2 -> V_196 ) ;
F_38 ( V_2 ) ;
F_161 ( & V_2 -> V_214 ) ;
F_1 ( V_2 , V_95 ,
F_135 ( V_72 ) ) ;
F_162 ( V_2 -> V_269 ) ;
F_163 ( V_2 -> V_17 ) ;
}
static void F_164 ( struct V_1 * V_2 )
{
F_165 ( V_2 -> V_269 ) ;
F_166 ( & V_2 -> V_214 ) ;
F_167 ( V_2 -> V_17 ) ;
F_34 ( V_2 ) ;
F_168 ( V_2 -> V_17 ) ;
F_39 ( V_2 ) ;
F_1 ( V_2 , V_94 , 0 ) ;
F_1 ( V_2 , V_93 , 0 ) ;
F_1 ( V_2 , V_95 , 0 ) ;
F_1 ( V_2 , V_96 , 0 ) ;
F_1 ( V_2 , V_97 , 0 ) ;
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
static int F_170 ( struct V_16 * V_17 , int V_122 )
{
if ( V_122 < 68 ) {
F_75 ( V_17 , L_17 ) ;
return - V_243 ;
}
if ( V_122 > 9676 ) {
F_126 ( V_17 , L_18 , V_122 ) ;
V_122 = 9676 ;
}
if ( ! F_171 ( F_172 ( V_122 ) , 8 ) ) {
F_126 ( V_17 , L_19 ,
V_122 , F_173 ( F_172 ( V_122 ) , 8 ) ) ;
V_122 = F_173 ( F_172 ( V_122 ) , 8 ) ;
}
return V_122 ;
}
static int F_174 ( struct V_16 * V_17 , int V_122 )
{
struct V_1 * V_2 = F_9 ( V_17 ) ;
int V_270 ;
V_122 = F_170 ( V_17 , V_122 ) ;
if ( V_122 < 0 )
return - V_243 ;
V_17 -> V_122 = V_122 ;
if ( ! F_114 ( V_17 ) )
return 0 ;
F_164 ( V_2 ) ;
F_156 ( V_2 ) ;
F_157 ( V_2 ) ;
V_2 -> V_196 = F_172 ( V_2 -> V_17 -> V_122 ) ;
V_270 = F_158 ( V_2 ) ;
if ( V_270 ) {
F_75 ( V_2 -> V_17 , L_20 ) ;
return V_270 ;
}
F_159 ( V_2 ) ;
F_160 ( V_2 ) ;
F_33 ( V_2 ) ;
return 0 ;
}
static int F_175 ( struct V_16 * V_17 , void * V_132 )
{
struct V_1 * V_2 = F_9 ( V_17 ) ;
T_2 * V_271 = V_132 + 2 ;
int V_11 ;
if ( F_114 ( V_17 ) )
return - V_272 ;
F_53 ( V_2 , V_17 -> V_252 , - 1 ) ;
F_53 ( V_2 , V_271 , V_110 ) ;
for ( V_11 = 0 ; V_11 < V_235 ; V_11 ++ )
V_17 -> V_252 [ V_11 ] = V_271 [ V_11 ] ;
return 0 ;
}
static void F_176 ( struct V_16 * V_273 )
{
struct V_1 * V_2 = F_9 ( V_273 ) ;
struct V_274 * V_275 = V_2 -> V_269 ;
int V_276 = 0 ;
if ( V_275 -> V_277 ) {
if ( ( V_2 -> V_278 != V_275 -> V_278 ) ||
( V_2 -> V_279 != V_275 -> V_279 ) ) {
T_1 V_42 ;
V_42 = F_3 ( V_2 , V_280 ) ;
V_42 &= ~ ( V_281 |
V_282 |
V_283 ) ;
if ( V_275 -> V_279 )
V_42 |= V_283 ;
if ( V_275 -> V_278 == V_284 )
V_42 |= V_282 ;
else
V_42 |= V_281 ;
F_1 ( V_2 , V_280 , V_42 ) ;
V_2 -> V_279 = V_275 -> V_279 ;
V_2 -> V_278 = V_275 -> V_278 ;
}
}
if ( V_275 -> V_277 != V_2 -> V_277 ) {
if ( ! V_275 -> V_277 ) {
V_2 -> V_279 = - 1 ;
V_2 -> V_278 = 0 ;
}
V_2 -> V_277 = V_275 -> V_277 ;
V_276 = 1 ;
}
if ( V_276 ) {
if ( V_275 -> V_277 ) {
T_1 V_42 = F_3 ( V_2 , V_280 ) ;
V_42 |= ( V_285 |
V_286 ) ;
F_1 ( V_2 , V_280 , V_42 ) ;
F_33 ( V_2 ) ;
F_126 ( V_2 -> V_17 , L_21 ) ;
} else {
F_34 ( V_2 ) ;
F_126 ( V_2 -> V_17 , L_22 ) ;
}
}
}
static int F_177 ( struct V_1 * V_2 )
{
struct V_274 * V_269 ;
V_269 = F_178 ( V_2 -> V_17 , V_2 -> V_287 , F_176 , 0 ,
V_2 -> V_288 ) ;
if ( ! V_269 ) {
F_75 ( V_2 -> V_17 , L_23 ) ;
return - V_289 ;
}
V_269 -> V_290 &= V_291 ;
V_269 -> V_292 = V_269 -> V_290 ;
V_2 -> V_269 = V_269 ;
V_2 -> V_277 = 0 ;
V_2 -> V_279 = 0 ;
V_2 -> V_278 = 0 ;
return 0 ;
}
static void F_179 ( struct V_1 * V_2 )
{
F_180 ( V_2 -> V_269 ) ;
V_2 -> V_269 = NULL ;
}
static int F_181 ( struct V_16 * V_17 )
{
struct V_1 * V_2 = F_9 ( V_17 ) ;
int V_270 ;
F_53 ( V_2 , V_17 -> V_252 , V_110 ) ;
V_2 -> V_196 = F_172 ( V_2 -> V_17 -> V_122 ) ;
V_270 = F_158 ( V_2 ) ;
if ( V_270 )
return V_270 ;
V_270 = F_159 ( V_2 ) ;
if ( V_270 )
goto V_293;
V_270 = F_182 ( V_2 -> V_17 -> V_254 , F_131 , 0 ,
V_294 , V_2 ) ;
if ( V_270 ) {
F_75 ( V_2 -> V_17 , L_24 , V_2 -> V_17 -> V_254 ) ;
goto V_295;
}
F_167 ( V_2 -> V_17 ) ;
V_270 = F_177 ( V_2 ) ;
if ( V_270 < 0 ) {
F_75 ( V_17 , L_25 ) ;
goto V_296;
}
F_160 ( V_2 ) ;
return 0 ;
V_296:
F_183 ( V_2 -> V_17 -> V_254 , V_2 ) ;
V_295:
F_156 ( V_2 ) ;
V_293:
F_157 ( V_2 ) ;
return V_270 ;
}
static int F_184 ( struct V_16 * V_17 )
{
struct V_1 * V_2 = F_9 ( V_17 ) ;
F_164 ( V_2 ) ;
F_179 ( V_2 ) ;
F_183 ( V_17 -> V_254 , V_2 ) ;
F_157 ( V_2 ) ;
F_156 ( V_2 ) ;
F_185 ( & V_2 -> V_146 ) ;
F_139 ( V_144 , & V_2 -> V_145 ) ;
return 0 ;
}
int F_186 ( struct V_16 * V_17 , struct V_297 * V_298 )
{
struct V_1 * V_2 = F_9 ( V_17 ) ;
if ( ! V_2 -> V_269 )
return - V_289 ;
return F_187 ( V_2 -> V_269 , V_298 ) ;
}
int F_188 ( struct V_16 * V_17 , struct V_297 * V_298 )
{
struct V_1 * V_2 = F_9 ( V_17 ) ;
if ( ! V_2 -> V_269 )
return - V_289 ;
return F_189 ( V_2 -> V_269 , V_298 ) ;
}
static int F_190 ( struct V_16 * V_17 ,
struct V_299 * V_300 )
{
struct V_1 * V_2 = F_9 ( V_17 ) ;
int V_67 ;
for ( V_67 = 0 ; V_67 < V_72 ; V_67 ++ ) {
struct V_36 * V_37 = & V_2 -> V_73 [ V_67 ] ;
V_37 -> V_141 = V_300 -> V_301 ;
V_37 -> V_138 = V_300 -> V_302 ;
F_54 ( V_2 , V_37 , V_37 -> V_138 ) ;
F_57 ( V_2 , V_37 , V_37 -> V_141 ) ;
}
for ( V_67 = 0 ; V_67 < V_69 ; V_67 ++ ) {
struct V_6 * V_7 = & V_2 -> V_70 [ V_67 ] ;
V_7 -> V_143 = V_300 -> V_303 ;
F_60 ( V_2 , V_7 , V_7 -> V_143 ) ;
}
return 0 ;
}
static int F_191 ( struct V_16 * V_17 ,
struct V_299 * V_300 )
{
struct V_1 * V_2 = F_9 ( V_17 ) ;
V_300 -> V_301 = V_2 -> V_73 [ 0 ] . V_141 ;
V_300 -> V_302 = V_2 -> V_73 [ 0 ] . V_138 ;
V_300 -> V_303 = V_2 -> V_70 [ 0 ] . V_143 ;
return 0 ;
}
static void F_192 ( struct V_16 * V_17 ,
struct V_304 * V_305 )
{
F_193 ( V_305 -> V_306 , V_294 ,
sizeof( V_305 -> V_306 ) ) ;
F_193 ( V_305 -> V_307 , V_308 ,
sizeof( V_305 -> V_307 ) ) ;
F_193 ( V_305 -> V_309 , F_194 ( & V_17 -> V_17 ) ,
sizeof( V_305 -> V_309 ) ) ;
}
static void F_195 ( struct V_16 * V_310 ,
struct V_311 * V_312 )
{
struct V_1 * V_2 = F_9 ( V_310 ) ;
V_312 -> V_313 = V_314 ;
V_312 -> V_315 = V_316 ;
V_312 -> V_317 = V_2 -> V_262 ;
V_312 -> V_318 = V_2 -> V_268 ;
}
static int F_196 ( struct V_16 * V_17 ,
struct V_311 * V_312 )
{
struct V_1 * V_2 = F_9 ( V_17 ) ;
if ( ( V_312 -> V_317 == 0 ) || ( V_312 -> V_318 == 0 ) )
return - V_243 ;
V_2 -> V_262 = V_312 -> V_317 < V_314 ?
V_312 -> V_317 : V_314 ;
V_2 -> V_268 = V_312 -> V_318 < V_316 ?
V_312 -> V_318 : V_316 ;
if ( F_114 ( V_17 ) ) {
F_184 ( V_17 ) ;
if ( F_181 ( V_17 ) ) {
F_75 ( V_17 ,
L_26 ) ;
return - V_197 ;
}
}
return 0 ;
}
static int F_197 ( struct V_1 * V_2 , int V_319 )
{
int V_67 ;
F_39 ( V_2 ) ;
F_43 ( V_2 ) ;
V_2 -> V_70 = F_198 ( V_69 * sizeof( struct V_6 ) ,
V_265 ) ;
if ( ! V_2 -> V_70 )
return - V_197 ;
for ( V_67 = 0 ; V_67 < V_69 ; V_67 ++ ) {
struct V_6 * V_7 = & V_2 -> V_70 [ V_67 ] ;
V_7 -> V_40 = V_67 ;
V_7 -> V_9 = V_2 -> V_268 ;
V_7 -> V_143 = V_230 ;
}
V_2 -> V_73 = F_198 ( V_72 * sizeof( struct V_36 ) ,
V_265 ) ;
if ( ! V_2 -> V_73 ) {
F_155 ( V_2 -> V_70 ) ;
return - V_197 ;
}
for ( V_67 = 0 ; V_67 < V_72 ; V_67 ++ ) {
struct V_36 * V_37 = & V_2 -> V_73 [ V_67 ] ;
V_37 -> V_40 = V_67 ;
V_37 -> V_9 = V_2 -> V_262 ;
V_37 -> V_138 = V_320 ;
V_37 -> V_141 = V_321 ;
}
return 0 ;
}
static void F_199 ( struct V_1 * V_2 )
{
F_155 ( V_2 -> V_70 ) ;
F_155 ( V_2 -> V_73 ) ;
}
static void F_200 ( struct V_1 * V_2 ,
const struct V_322 * V_323 )
{
T_1 V_324 ;
T_1 V_325 ;
int V_11 ;
for ( V_11 = 0 ; V_11 < 6 ; V_11 ++ ) {
F_1 ( V_2 , F_201 ( V_11 ) , 0 ) ;
F_1 ( V_2 , F_202 ( V_11 ) , 0 ) ;
if ( V_11 < 4 )
F_1 ( V_2 , F_203 ( V_11 ) , 0 ) ;
}
V_324 = 0x3f ;
V_325 = 0 ;
for ( V_11 = 0 ; V_11 < V_323 -> V_326 ; V_11 ++ ) {
const struct V_327 * V_328 = V_323 -> V_328 + V_11 ;
F_1 ( V_2 , F_201 ( V_11 ) , ( V_328 -> V_5 & 0xffff0000 ) |
( V_328 -> V_329 << 8 ) | V_323 -> V_330 ) ;
F_1 ( V_2 , F_202 ( V_11 ) ,
( V_328 -> V_9 - 1 ) & 0xffff0000 ) ;
V_324 &= ~ ( 1 << V_11 ) ;
V_325 |= 3 << ( 2 * V_11 ) ;
}
F_1 ( V_2 , V_331 , V_324 ) ;
}
static void F_204 ( struct V_1 * V_2 , int V_332 )
{
T_1 V_42 ;
F_1 ( V_2 , V_333 , 0 ) ;
if ( V_332 == V_334 )
F_32 ( V_2 ) ;
F_31 ( V_2 , 1 ) ;
V_42 = F_3 ( V_2 , V_64 ) ;
V_42 &= ~ V_335 ;
F_1 ( V_2 , V_64 , V_42 ) ;
while ( ( F_3 ( V_2 , V_64 ) &
V_335 ) != 0 )
continue;
}
static int F_205 ( struct V_336 * V_337 )
{
const struct V_322 * V_338 ;
struct V_339 * V_340 = V_337 -> V_17 . V_341 ;
struct V_339 * V_287 ;
T_1 V_319 ;
struct V_1 * V_2 ;
struct V_16 * V_17 ;
const char * V_342 ;
int V_332 ;
int V_211 ;
if ( V_110 != 0 ) {
F_206 ( & V_337 -> V_17 , L_27 , V_110 ) ;
return - V_243 ;
}
V_17 = F_207 ( sizeof( struct V_1 ) , V_69 , V_72 ) ;
if ( ! V_17 )
return - V_197 ;
V_17 -> V_254 = F_208 ( V_340 , 0 ) ;
if ( V_17 -> V_254 == 0 ) {
V_211 = - V_243 ;
goto V_343;
}
V_287 = F_209 ( V_340 , L_28 , 0 ) ;
if ( ! V_287 ) {
F_206 ( & V_337 -> V_17 , L_29 ) ;
V_211 = - V_289 ;
goto V_296;
}
V_332 = F_210 ( V_340 ) ;
if ( V_332 < 0 ) {
F_206 ( & V_337 -> V_17 , L_30 ) ;
V_211 = - V_243 ;
goto V_296;
}
V_342 = F_211 ( V_340 ) ;
if ( ! V_342 || ! F_212 ( V_342 ) )
F_213 ( V_17 ) ;
else
memcpy ( V_17 -> V_252 , V_342 , V_235 ) ;
V_17 -> V_344 = V_316 ;
V_17 -> V_345 = 5 * V_346 ;
V_17 -> V_347 = & V_348 ;
F_214 ( V_17 , & V_349 ) ;
V_2 = F_9 ( V_17 ) ;
V_2 -> V_146 . V_350 = F_138 ;
F_215 ( & V_2 -> V_146 ) ;
F_139 ( V_144 , & V_2 -> V_145 ) ;
V_2 -> V_351 = V_352 ;
V_2 -> V_287 = V_287 ;
V_2 -> V_288 = V_332 ;
V_2 -> V_5 = F_216 ( V_340 , 0 ) ;
if ( V_2 -> V_5 == NULL ) {
V_211 = - V_197 ;
goto V_296;
}
V_2 -> V_140 = F_217 ( & V_337 -> V_17 , NULL ) ;
if ( F_218 ( V_2 -> V_140 ) ) {
V_211 = F_219 ( V_2 -> V_140 ) ;
goto V_353;
}
F_220 ( V_2 -> V_140 ) ;
V_2 -> V_146 . V_4 = ( unsigned long ) V_17 ;
V_2 -> V_268 = V_316 ;
V_2 -> V_262 = V_314 ;
V_2 -> V_17 = V_17 ;
F_221 ( V_17 , & V_337 -> V_17 ) ;
V_211 = F_197 ( V_2 , V_319 ) ;
if ( V_211 < 0 ) {
F_206 ( & V_337 -> V_17 , L_31 ) ;
goto V_354;
}
F_204 ( V_2 , V_332 ) ;
V_338 = F_222 () ;
if ( V_338 )
F_200 ( V_2 , V_338 ) ;
F_223 ( V_17 , & V_2 -> V_214 , F_133 , V_2 -> V_351 ) ;
V_17 -> V_355 = V_356 | V_357 ;
V_17 -> V_358 |= V_356 | V_357 ;
V_17 -> V_359 |= V_356 | V_357 ;
V_17 -> V_360 |= V_361 ;
V_211 = F_224 ( V_17 ) ;
if ( V_211 < 0 ) {
F_206 ( & V_337 -> V_17 , L_32 ) ;
goto V_362;
}
F_126 ( V_17 , L_33 , V_17 -> V_252 ) ;
F_225 ( V_337 , V_2 -> V_17 ) ;
return 0 ;
V_362:
F_199 ( V_2 ) ;
V_354:
F_226 ( V_2 -> V_140 ) ;
V_353:
F_227 ( V_2 -> V_5 ) ;
V_296:
F_228 ( V_17 -> V_254 ) ;
V_343:
F_229 ( V_17 ) ;
return V_211 ;
}
static int F_230 ( struct V_336 * V_337 )
{
struct V_16 * V_17 = F_231 ( V_337 ) ;
struct V_1 * V_2 = F_9 ( V_17 ) ;
F_232 ( V_17 ) ;
F_199 ( V_2 ) ;
F_226 ( V_2 -> V_140 ) ;
F_227 ( V_2 -> V_5 ) ;
F_228 ( V_17 -> V_254 ) ;
F_229 ( V_17 ) ;
F_225 ( V_337 , NULL ) ;
return 0 ;
}
