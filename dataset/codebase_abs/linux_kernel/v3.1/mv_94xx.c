static void F_1 ( struct V_1 * V_2 , int V_3 )
{
T_1 V_4 ;
struct V_5 * V_6 = & V_2 -> V_6 [ V_3 ] ;
T_1 V_7 ;
F_2 ( V_2 , V_3 , V_8 ) ;
V_4 = F_3 ( V_2 , V_3 ) ;
V_7 = ( ( V_4 & 0x3f0000 ) >> 16 ) & 0xff ;
V_6 -> V_9 &= ~ ( V_10 | V_11 ) ;
switch ( V_7 ) {
case 0x10 :
V_6 -> V_9 |= V_10 ;
break;
case 0x1d :
default:
V_6 -> V_9 |= V_11 ;
break;
}
}
void F_4 ( struct V_1 * V_2 , int V_12 ,
struct V_13 V_13 )
{
T_1 V_14 , V_15 = 0 , V_16 = 0 ;
T_2 V_3 ;
if ( V_2 -> V_17 -> V_18 == V_19 )
return;
for ( V_3 = 0 ; V_3 < 3 ; V_3 ++ ) {
switch ( V_3 ) {
case 0 :
V_15 = V_20 ;
V_16 = V_21 ;
break;
case 1 :
V_15 = V_21 ;
V_16 = V_22 ;
break;
case 2 :
V_15 = V_22 ;
V_16 = V_23 ;
break;
}
F_2 ( V_2 , V_12 , V_15 ) ;
V_14 = F_3 ( V_2 , V_12 ) ;
V_14 &= ~ ( 0xFBE << 16 ) ;
V_14 |= ( ( ( V_13 . V_24 << 11 ) |
( V_13 . V_25 << 7 ) |
( V_13 . V_26 << 1 ) ) << 16 ) ;
F_5 ( V_2 , V_12 , V_14 ) ;
F_2 ( V_2 , V_12 , V_16 ) ;
V_14 = F_3 ( V_2 , V_12 ) ;
V_14 &= ~ ( 0xC000 ) ;
V_14 |= ( V_13 . V_27 << 14 ) ;
F_5 ( V_2 , V_12 , V_14 ) ;
}
}
void F_6 ( struct V_1 * V_2 , int V_12 ,
struct V_28 V_29 )
{
T_1 V_14 ;
if ( ( V_2 -> V_17 -> V_18 == V_19 )
|| ( V_2 -> V_17 -> V_18 == V_30 ) )
return;
F_2 ( V_2 , V_12 , V_31 ) ;
V_14 = F_3 ( V_2 , V_12 ) ;
V_14 &= ~ 0xFF ;
V_14 |= ( ( 0x1 << 7 ) |
( V_29 . V_32 << 4 ) |
( V_29 . V_33 << 0 ) ) ;
F_5 ( V_2 , V_12 , V_14 ) ;
F_2 ( V_2 , V_12 , V_34 ) ;
V_14 = F_3 ( V_2 , V_12 ) ;
V_14 &= ~ 0x40001 ;
V_14 |= ( 0 << 18 ) ;
F_5 ( V_2 , V_12 , V_14 ) ;
F_2 ( V_2 , V_12 , V_35 ) ;
V_14 = F_3 ( V_2 , V_12 ) ;
V_14 &= ~ 0xFFF ;
V_14 |= ( ( 0x3F << 6 ) | ( 0x0 << 0 ) ) ;
F_5 ( V_2 , V_12 , V_14 ) ;
F_2 ( V_2 , V_12 , V_34 ) ;
V_14 = F_3 ( V_2 , V_12 ) ;
V_14 &= ~ 0x8 ;
V_14 |= ( 0 << 3 ) ;
F_5 ( V_2 , V_12 , V_14 ) ;
}
void F_7 ( struct V_1 * V_2 , int V_12 , T_2 V_36 )
{
union V_37 V_38 , V_39 ;
F_2 ( V_2 , V_12 , V_40 ) ;
V_39 . V_41 = F_3 ( V_2 , V_12 ) ;
V_38 . V_41 = 0 ;
V_38 . V_42 . V_43 = V_39 . V_42 . V_43 ;
V_38 . V_42 . V_44 = 1 ;
V_38 . V_42 . V_45 = 1 ;
V_38 . V_42 . V_46 = 1 ;
switch ( V_36 ) {
case 0x0 :
V_38 . V_42 . V_47 = 1 ;
V_38 . V_42 . V_48 = 0 ;
V_38 . V_42 . V_49 = 1 ;
V_38 . V_42 . V_50 = 0x30 ;
break;
case 0x1 :
V_38 . V_42 . V_47 = 3 ;
V_38 . V_42 . V_50 = 0x3c ;
V_38 . V_42 . V_51 = 0x08 ;
break;
case 0x2 :
default:
V_38 . V_42 . V_47 = 7 ;
V_38 . V_42 . V_48 = 1 ;
V_38 . V_42 . V_49 = 1 ;
V_38 . V_42 . V_50 = 0x3f ;
V_38 . V_42 . V_51 = 0x09 ;
break;
}
F_5 ( V_2 , V_12 , V_38 . V_41 ) ;
}
static void T_3
F_8 ( struct V_1 * V_2 , int V_12 )
{
T_1 V_52 ;
V_52 = ( T_1 ) ( * ( T_1 * ) & V_2 -> V_53 . V_13 [ V_12 ] ) ;
if ( V_52 == 0xFFFFFFFFL ) {
V_2 -> V_53 . V_13 [ V_12 ] . V_25 = 0x6 ;
V_2 -> V_53 . V_13 [ V_12 ] . V_26 = 0x1A ;
V_2 -> V_53 . V_13 [ V_12 ] . V_27 = 0x3 ;
}
V_52 = ( T_2 ) ( * ( T_2 * ) & V_2 -> V_53 . V_54 [ V_12 ] ) ;
if ( V_52 == 0xFFL ) {
switch ( V_2 -> V_17 -> V_18 ) {
case V_19 :
case V_30 :
V_2 -> V_53 . V_54 [ V_12 ] . V_32 = 0x7 ;
V_2 -> V_53 . V_54 [ V_12 ] . V_33 = 0x7 ;
break;
case V_55 :
case V_56 :
case V_57 :
default:
V_2 -> V_53 . V_54 [ V_12 ] . V_32 = 0x7 ;
V_2 -> V_53 . V_54 [ V_12 ] . V_33 = 0xC ;
break;
}
}
V_52 = ( T_2 ) ( * ( T_2 * ) & V_2 -> V_53 . V_58 [ V_12 ] ) ;
if ( V_52 == 0xFFL )
V_2 -> V_53 . V_58 [ V_12 ] = 0x2 ;
F_4 ( V_2 , V_12 ,
V_2 -> V_53 . V_13 [ V_12 ] ) ;
F_6 ( V_2 , V_12 ,
V_2 -> V_53 . V_54 [ V_12 ] ) ;
F_7 ( V_2 , V_12 ,
V_2 -> V_53 . V_58 [ V_12 ] ) ;
}
static void T_3 F_9 ( struct V_1 * V_2 , int V_12 )
{
void T_4 * V_59 = V_2 -> V_59 ;
T_1 V_14 ;
V_14 = F_10 ( V_60 ) ;
V_14 |= 1 << ( V_12 + V_61 ) ;
F_11 ( V_60 , V_14 ) ;
}
static void F_12 ( struct V_1 * V_2 , T_1 V_12 , int V_62 )
{
T_1 V_14 ;
T_1 V_63 = 5000 ;
if ( V_62 == V_64 ) {
F_13 ( V_2 , V_12 , V_65 ) ;
V_14 = F_14 ( V_2 , V_12 ) ;
F_15 ( V_2 , V_12 , V_14 | 0x20000000 ) ;
F_15 ( V_2 , V_12 , V_14 | 0x100000 ) ;
return;
}
V_14 = F_16 ( V_2 , V_12 ) ;
V_14 &= ~ V_66 ;
F_17 ( V_2 , V_12 , V_14 ) ;
if ( V_62 ) {
V_14 = F_18 ( V_2 , V_12 ) ;
V_14 |= V_67 ;
F_19 ( V_2 , V_12 , V_14 ) ;
do {
V_14 = F_18 ( V_2 , V_12 ) ;
F_20 ( 10 ) ;
V_63 -- ;
} while ( ( V_14 & V_67 ) && V_63 );
if ( ! V_63 )
F_21 ( L_1 ) ;
} else {
V_14 = F_18 ( V_2 , V_12 ) ;
V_14 |= V_68 ;
F_19 ( V_2 , V_12 , V_14 ) ;
}
}
static void F_22 ( struct V_1 * V_2 , T_1 V_12 )
{
T_1 V_14 ;
F_2 ( V_2 , V_12 , V_40 ) ;
V_14 = F_3 ( V_2 , V_12 ) ;
F_5 ( V_2 , V_12 , V_14 | 0x00800000 ) ;
}
static void F_23 ( struct V_1 * V_2 , T_1 V_12 )
{
T_1 V_14 ;
T_2 V_18 = 0 ;
V_18 = V_2 -> V_17 -> V_18 ;
if ( V_18 == V_19 ) {
F_2 ( V_2 , V_12 , V_69 ) ;
F_5 ( V_2 , V_12 , 0x8300ffc1 ) ;
}
if ( V_18 == V_30 ) {
F_2 ( V_2 , V_12 , V_70 ) ;
F_5 ( V_2 , V_12 , 0x08001006 ) ;
F_2 ( V_2 , V_12 , V_69 ) ;
F_5 ( V_2 , V_12 , 0x0000705f ) ;
}
F_2 ( V_2 , V_12 , V_40 ) ;
V_14 = F_3 ( V_2 , V_12 ) ;
V_14 |= F_24 ( 0 ) ;
F_5 ( V_2 , V_12 , V_14 & 0xfd7fffff ) ;
}
static int T_3 F_25 ( struct V_1 * V_2 )
{
void T_4 * V_59 = V_2 -> V_59 ;
int V_3 ;
T_1 V_14 , V_71 ;
T_2 V_18 ;
V_18 = V_2 -> V_17 -> V_18 ;
F_26 ( V_2 ) ;
if ( V_2 -> V_72 & V_73 ) {
V_14 = F_10 ( V_74 ) ;
V_14 &= ~ V_75 ;
V_14 |= V_76 ;
F_11 ( V_74 , V_14 ) ;
}
V_71 = F_10 ( V_77 ) & 0xFFFF ;
if ( V_71 & V_78 )
V_71 &= ~ V_78 ;
else
F_27 ( V_77 , V_71 | V_78 ) ;
if ( V_2 -> V_72 & V_73 ) {
V_14 = F_10 ( V_74 ) ;
V_14 &= ~ V_75 ;
V_14 |= V_79 ;
V_14 &= ~ V_76 ;
V_14 |= V_80 ;
F_11 ( V_74 , V_14 ) ;
F_28 ( 100 ) ;
V_14 &= ~ V_80 ;
F_11 ( V_74 , V_14 ) ;
F_28 ( 100 ) ;
}
F_11 ( V_81 , 0xFF ) ;
if ( V_18 == V_19 ) {
F_11 ( V_82 , V_83 ) ;
F_11 ( V_84 , 0x00018080 ) ;
}
F_11 ( V_82 , V_40 ) ;
if ( V_18 == V_19 || V_18 == V_30 )
F_11 ( V_84 , 0x0084d4fe ) ;
else
F_11 ( V_84 , 0x0084fffe ) ;
if ( V_18 == V_30 ) {
F_11 ( V_82 , V_70 ) ;
F_11 ( V_84 , 0x08001006 ) ;
F_11 ( V_82 , V_69 ) ;
F_11 ( V_84 , 0x0000705f ) ;
}
F_11 ( V_60 , 0 ) ;
F_11 ( V_85 , 0 ) ;
F_11 ( V_86 , 0 ) ;
F_29 ( V_2 ) ;
F_11 ( V_82 , V_87 ) ;
V_14 = F_10 ( V_84 ) ;
V_14 &= 0xFFFF00FF ;
V_14 |= 0x00003300 ;
F_11 ( V_84 , V_14 ) ;
F_11 ( V_88 , V_2 -> V_89 ) ;
F_11 ( V_90 , ( V_2 -> V_89 >> 16 ) >> 16 ) ;
F_11 ( V_91 , V_2 -> V_92 ) ;
F_11 ( V_93 , ( V_2 -> V_92 >> 16 ) >> 16 ) ;
F_11 ( V_94 , V_95 ) ;
F_11 ( V_96 , V_2 -> V_97 ) ;
F_11 ( V_98 , ( V_2 -> V_97 >> 16 ) >> 16 ) ;
F_11 ( V_99 , V_100 ) ;
F_11 ( V_101 , V_2 -> V_102 ) ;
F_11 ( V_103 , ( V_2 -> V_102 >> 16 ) >> 16 ) ;
for ( V_3 = 0 ; V_3 < V_2 -> V_104 -> V_105 ; V_3 ++ ) {
F_22 ( V_2 , V_3 ) ;
F_30 ( V_2 , V_3 , V_106 , V_107 ,
F_31 ( V_2 -> V_6 [ V_3 ] . V_108 ) ) ;
F_9 ( V_2 , V_3 ) ;
F_8 ( V_2 , V_3 ) ;
F_23 ( V_2 , V_3 ) ;
F_12 ( V_2 , V_3 , V_67 ) ;
F_28 ( 500 ) ;
F_1 ( V_2 , V_3 ) ;
}
if ( V_2 -> V_72 & V_73 ) {
F_32 ( 0x0E008000 , V_59 + 0x000 ) ;
F_32 ( 0x59000008 , V_59 + 0x004 ) ;
F_32 ( 0x20 , V_59 + 0x008 ) ;
F_32 ( 0x20 , V_59 + 0x00c ) ;
F_32 ( 0x20 , V_59 + 0x010 ) ;
F_32 ( 0x20 , V_59 + 0x014 ) ;
F_32 ( 0x20 , V_59 + 0x018 ) ;
F_32 ( 0x20 , V_59 + 0x01c ) ;
}
for ( V_3 = 0 ; V_3 < V_2 -> V_104 -> V_105 ; V_3 ++ ) {
V_14 = F_16 ( V_2 , V_3 ) ;
V_14 &= ~ V_109 ;
F_17 ( V_2 , V_3 , V_14 ) ;
V_14 = V_66 | V_110 |
V_111 | V_112 | V_113 ;
F_33 ( V_2 , V_3 , V_14 ) ;
F_28 ( 100 ) ;
F_34 ( V_2 , V_3 , 1 ) ;
}
V_71 = F_10 ( V_77 ) ;
V_71 |= V_114 ;
V_71 &= ~ V_115 ;
V_71 |= V_116 ;
F_27 ( V_77 , V_71 ) ;
V_14 = F_10 ( V_60 ) ;
V_14 |= V_117 ;
V_14 &= ~ V_118 ;
F_11 ( V_60 , V_14 ) ;
V_14 = 0 ;
if ( V_95 > 0x1ff )
F_11 ( V_119 , 0x1ff | V_120 ) ;
else
F_11 ( V_119 , V_95 | V_120 ) ;
V_14 = 0x10000 | V_121 ;
F_11 ( V_122 , V_14 ) ;
F_11 ( V_94 , 0 ) ;
F_11 ( V_94 , V_95 | V_123 ) ;
F_11 ( V_99 , V_100 | V_124 ) ;
F_11 ( V_60 , V_125 | V_126 |
V_127 | V_128 ) ;
V_14 = ( V_129 | V_130 | V_131 | V_132 | V_133 |
V_134 | V_135 ) ;
V_14 |= V_136 ;
F_11 ( V_137 , V_14 ) ;
F_11 ( V_138 , 0xFFFF ) ;
return 0 ;
}
static int F_35 ( struct V_1 * V_2 )
{
if ( ! F_36 ( V_2 , 2 , - 1 ) ) {
V_2 -> V_139 = V_2 -> V_59 + 0x10200 ;
V_2 -> V_59 += 0x20000 ;
if ( V_2 -> V_140 == 1 )
V_2 -> V_59 += 0x4000 ;
return 0 ;
}
return - 1 ;
}
static void F_37 ( struct V_1 * V_2 )
{
if ( V_2 -> V_59 ) {
V_2 -> V_59 -= 0x20000 ;
if ( V_2 -> V_140 == 1 )
V_2 -> V_59 -= 0x4000 ;
F_38 ( V_2 -> V_59 ) ;
}
}
static void F_39 ( struct V_1 * V_2 )
{
void T_4 * V_59 = V_2 -> V_139 ;
T_1 V_14 ;
V_14 = F_10 ( V_141 ) ;
V_14 |= ( V_142 | V_143 ) ;
F_11 ( V_144 , V_14 ) ;
F_32 ( V_14 , V_59 + 0x0C ) ;
F_32 ( V_14 , V_59 + 0x10 ) ;
F_32 ( V_14 , V_59 + 0x14 ) ;
F_32 ( V_14 , V_59 + 0x18 ) ;
F_11 ( V_141 , V_14 ) ;
}
static void F_40 ( struct V_1 * V_2 )
{
void T_4 * V_59 = V_2 -> V_139 ;
T_1 V_14 ;
V_14 = F_10 ( V_141 ) ;
V_14 &= ~ ( V_142 | V_143 ) ;
F_11 ( V_144 , V_14 ) ;
F_32 ( V_14 , V_59 + 0x0C ) ;
F_32 ( V_14 , V_59 + 0x10 ) ;
F_32 ( V_14 , V_59 + 0x14 ) ;
F_32 ( V_14 , V_59 + 0x18 ) ;
F_11 ( V_141 , V_14 ) ;
}
static T_1 F_41 ( struct V_1 * V_2 , int V_145 )
{
void T_4 * V_59 = V_2 -> V_139 ;
T_1 V_146 = 0 ;
if ( ! ( V_2 -> V_72 & V_73 ) ) {
V_146 = F_10 ( V_144 ) ;
if ( ! ( V_146 & ( V_142 | V_143 ) ) )
return 0 ;
}
return V_146 ;
}
static T_5 F_42 ( struct V_1 * V_2 , int V_145 , T_1 V_146 )
{
void T_4 * V_59 = V_2 -> V_59 ;
if ( ( ( V_146 & V_142 ) && V_2 -> V_140 == 0 ) ||
( ( V_146 & V_143 ) && V_2 -> V_140 == 1 ) ) {
F_27 ( V_147 , V_130 ) ;
F_43 ( & V_2 -> V_148 ) ;
F_44 ( V_2 ) ;
F_45 ( & V_2 -> V_148 ) ;
}
return V_149 ;
}
static void F_46 ( struct V_1 * V_2 , T_1 V_150 )
{
T_1 V_14 ;
V_14 = F_47 ( V_2 , V_151 + ( V_150 >> 3 ) ) ;
if ( V_14 && 1 << ( V_150 % 32 ) ) {
F_48 ( L_2 , V_14 , V_150 ) ;
F_49 ( V_2 , V_151 + ( V_150 >> 3 ) ,
1 << ( V_150 % 32 ) ) ;
do {
V_14 = F_47 ( V_2 ,
V_151 + ( V_150 >> 3 ) ) ;
} while ( V_14 & 1 << ( V_150 % 32 ) );
}
}
void F_50 ( struct V_1 * V_2 , T_2 V_152 , T_2 V_153 )
{
void T_4 * V_59 = V_2 -> V_59 ;
T_1 V_14 ;
if ( V_153 ) {
V_14 = F_10 ( V_154 ) ;
if ( V_14 ) {
F_21 ( L_3 , V_14 ) ;
F_11 ( V_154 , V_14 ) ;
}
V_14 = F_10 ( V_155 ) ;
if ( V_14 ) {
F_21 ( L_4 , V_14 ) ;
F_11 ( V_155 , V_14 ) ;
}
} else {
if ( V_152 > 31 )
V_14 = F_10 ( V_155 ) ;
else
V_14 = F_10 ( V_154 ) ;
if ( V_14 & ( 1 << ( V_152 % 32 ) ) ) {
F_21 ( L_5 , V_152 ) ;
if ( V_152 > 31 )
F_11 ( V_155 , 1 << ( V_152 % 32 ) ) ;
else
F_11 ( V_154 , 1 << ( V_152 % 32 ) ) ;
}
}
}
static void F_51 ( struct V_1 * V_2 , enum V_156 type ,
T_1 V_157 )
{
void T_4 * V_59 = V_2 -> V_59 ;
T_1 V_14 ;
F_50 ( V_2 , 0 , 1 ) ;
V_14 = F_10 ( V_147 ) ;
F_11 ( V_147 , V_14 | V_133 ) ;
V_14 = F_10 ( V_60 ) | 0xFF00 ;
F_11 ( V_60 , V_14 ) ;
}
static void F_52 ( struct V_1 * V_2 )
{
void T_4 * V_59 = V_2 -> V_59 ;
T_1 V_158 , V_159 ;
T_2 V_3 ;
struct V_160 * V_161 ;
V_158 = F_10 ( V_162 ) ;
V_159 = F_10 ( V_163 ) ;
F_21 ( L_6 ,
V_158 , V_159 ) ;
for ( V_3 = 0 ; V_3 < 32 ; V_3 ++ ) {
if ( V_158 & F_24 ( V_3 ) ) {
V_161 = F_53 ( V_2 , V_3 ) ;
if ( V_161 )
F_54 ( V_2 , V_161 -> V_164 ) ;
}
if ( V_159 & F_24 ( V_3 ) ) {
V_161 = F_53 ( V_2 , V_3 + 32 ) ;
if ( V_161 )
F_54 ( V_2 , V_161 -> V_164 ) ;
}
}
F_11 ( V_162 , V_158 ) ;
F_11 ( V_163 , V_159 ) ;
}
static void F_55 ( struct V_1 * V_2 , T_2 * V_157 )
{
void T_4 * V_59 = V_2 -> V_59 ;
T_2 V_152 = * V_157 ;
if ( * V_157 == V_165 )
return;
V_2 -> V_166 &= ~ F_24 ( V_152 ) ;
if ( V_152 < 32 )
F_56 ( V_152 , ( T_1 ) V_2 -> V_166 ) ;
else
F_56 ( V_152 , ( T_1 ) ( V_2 -> V_166 >> 32 ) ) ;
* V_157 = V_165 ;
return;
}
static T_2 F_57 ( struct V_1 * V_2 , T_2 * V_157 )
{
int V_3 ;
void T_4 * V_59 = V_2 -> V_59 ;
if ( * V_157 != V_165 )
return 0 ;
V_3 = F_58 ( V_2 -> V_166 ) ;
if ( V_3 >= 32 ) {
V_2 -> V_166 |= F_24 ( V_3 ) ;
F_56 ( V_3 , ( T_1 ) ( V_2 -> V_166 >> 32 ) ) ;
* V_157 = V_3 ;
return 0 ;
} else if ( V_3 >= 0 ) {
V_2 -> V_166 |= F_24 ( V_3 ) ;
F_56 ( V_3 , ( T_1 ) V_2 -> V_166 ) ;
* V_157 = V_3 ;
return 0 ;
}
return V_165 ;
}
static void F_59 ( struct V_167 * V_168 , int V_169 , void * V_170 )
{
int V_3 ;
struct V_167 * V_171 ;
struct V_172 * V_173 = V_170 ;
struct V_174 V_175 ;
* ( T_1 * ) & V_175 = 0 ;
F_60 (scatter, sg, nr, i) {
V_173 -> V_176 = F_31 ( F_61 ( V_171 ) ) ;
V_175 . V_177 = F_62 ( V_171 ) ;
V_173 -> V_175 = F_63 ( * ( T_1 * ) & V_175 ) ;
V_173 ++ ;
}
}
static int F_64 ( struct V_1 * V_2 , int V_3 )
{
T_1 V_178 ;
V_178 = F_18 ( V_2 , V_3 ) ;
if ( V_178 & V_179 )
return 1 ;
return 0 ;
}
static void F_65 ( struct V_1 * V_2 , int V_180 ,
struct V_181 * V_140 )
{
int V_3 ;
T_1 V_182 [ 7 ] ;
for ( V_3 = 0 ; V_3 < 7 ; V_3 ++ ) {
F_13 ( V_2 , V_180 ,
V_183 + V_3 * 4 ) ;
V_182 [ V_3 ] = F_63 ( F_14 ( V_2 , V_180 ) ) ;
}
memcpy ( V_140 , V_182 , 28 ) ;
}
static void F_66 ( struct V_1 * V_2 , int V_180 ,
struct V_181 * V_140 )
{
int V_3 ;
T_1 V_182 [ 7 ] ;
for ( V_3 = 0 ; V_3 < 7 ; V_3 ++ ) {
F_13 ( V_2 , V_180 ,
V_184 + V_3 * 4 ) ;
V_182 [ V_3 ] = F_63 ( F_14 ( V_2 , V_180 ) ) ;
F_21 ( L_7 ,
V_180 + V_2 -> V_140 * V_2 -> V_104 -> V_105 , V_3 , V_182 [ V_3 ] ) ;
}
memcpy ( V_140 , V_182 , 28 ) ;
}
static T_1 F_67 ( struct V_181 * V_140 )
{
T_1 V_185 = 0 ;
V_185 |= V_140 -> V_186 ;
if ( V_140 -> V_187 )
V_185 |= V_188 ;
if ( V_140 -> V_189 )
V_185 |= V_190 ;
if ( V_140 -> V_191 )
V_185 |= V_192 ;
if ( V_140 -> V_193 )
V_185 |= V_194 ;
if ( V_140 -> V_195 )
V_185 |= V_196 ;
if ( V_140 -> V_197 )
V_185 |= V_198 ;
V_185 |= ( T_1 ) V_140 -> V_12 << 24 ;
return V_185 ;
}
static T_1 F_68 ( struct V_181 * V_140 )
{
return F_67 ( V_140 ) ;
}
static void F_69 ( struct V_1 * V_2 , int V_3 ,
struct V_181 * V_140 )
{
struct V_5 * V_6 = & V_2 -> V_6 [ V_3 ] ;
struct V_199 * V_200 = & V_6 -> V_200 ;
F_21 ( L_8 , V_6 -> V_7 ) ;
V_200 -> V_201 =
( V_6 -> V_7 & V_202 ) >>
V_203 ;
V_200 -> V_201 += 0x8 ;
F_21 ( L_9 , V_200 -> V_201 ) ;
V_6 -> V_204 = V_205 ;
V_6 -> V_206 = V_207 ;
F_65 ( V_2 , V_3 , V_140 ) ;
V_6 -> V_208 = F_67 ( V_140 ) ;
if ( V_6 -> V_9 & V_10 ) {
F_66 ( V_2 , V_3 , V_140 ) ;
V_6 -> V_185 = F_68 ( V_140 ) ;
V_6 -> V_209 = * ( V_210 * ) V_140 -> V_211 ;
} else {
V_6 -> V_185 = V_194 | 1 ;
}
}
void F_70 ( struct V_1 * V_2 , T_1 V_12 ,
struct V_212 * V_213 )
{
T_1 V_214 = 0 ;
T_1 V_14 ;
V_14 = F_18 ( V_2 , V_12 ) ;
V_214 = ( V_213 -> V_206 - V_205 ) << 12 ;
if ( V_214 ) {
V_14 &= ~ ( 0x3 << 12 ) ;
V_14 |= V_214 ;
}
F_19 ( V_2 , V_12 , V_14 ) ;
F_12 ( V_2 , V_12 , V_67 ) ;
}
static void F_71 ( struct V_1 * V_2 )
{
T_1 V_14 ;
void T_4 * V_59 = V_2 -> V_59 ;
V_14 = F_10 ( V_85 ) ;
F_11 ( V_85 , 0 ) ;
F_11 ( V_85 , V_14 ) ;
V_14 = F_10 ( V_86 ) ;
F_11 ( V_86 , 0 ) ;
F_11 ( V_86 , V_14 ) ;
}
T_1 F_72 ( struct V_1 * V_2 )
{
void T_4 * V_59 = V_2 -> V_139 - 0x10200 ;
return F_10 ( V_215 ) ;
}
void F_73 ( struct V_1 * V_2 , T_1 V_216 )
{
void T_4 * V_59 = V_2 -> V_139 - 0x10200 ;
F_11 ( V_215 , V_216 ) ;
}
int F_74 ( struct V_1 * V_2 ,
T_1 * V_217 ,
T_2 V_218 ,
T_2 V_219 ,
T_2 V_220 ,
T_1 V_176
)
{
void T_4 * V_59 = V_2 -> V_139 - 0x10200 ;
T_1 V_221 ;
V_221 = ( ( T_1 ) V_218 << 8 ) | ( ( T_1 ) V_220 << 4 ) ;
if ( V_219 )
V_221 |= V_222 ;
if ( V_176 != V_223 ) {
F_11 ( V_224 , ( V_176 & 0x0003FFFFL ) ) ;
V_221 |= V_225 ;
}
* V_217 = V_221 ;
return 0 ;
}
int F_75 ( struct V_1 * V_2 , T_1 V_218 )
{
void T_4 * V_59 = V_2 -> V_139 - 0x10200 ;
F_11 ( V_226 , V_218 | V_227 ) ;
return 0 ;
}
int F_76 ( struct V_1 * V_2 , T_1 V_228 )
{
void T_4 * V_59 = V_2 -> V_139 - 0x10200 ;
T_1 V_3 , V_221 ;
for ( V_3 = 0 ; V_3 < V_228 ; V_3 ++ ) {
V_221 = F_10 ( V_226 ) ;
if ( ! ( V_221 & V_227 ) )
return 0 ;
F_28 ( 10 ) ;
}
return - 1 ;
}
void F_77 ( struct V_1 * V_2 , T_1 V_229 ,
int V_230 , int V_231 , void * V_170 )
{
int V_3 ;
struct V_172 * V_173 = V_170 ;
T_6 V_232 ;
struct V_174 V_175 ;
* ( T_1 * ) & V_175 = 0 ;
V_173 += V_231 ;
#define F_78 0x01
if ( ( V_2 -> V_17 -> V_18 == V_19 ) ||
( V_2 -> V_17 -> V_18 == V_30 ) )
V_232 = ( V_229 <= 0x08 ) ?
V_2 -> V_233 : V_2 -> V_234 ;
else
return;
for ( V_3 = V_231 ; V_3 < V_235 ; V_3 ++ , ++ V_173 ) {
if ( V_3 == V_235 - 1 ) {
V_173 -> V_176 = F_31 ( F_79 ( V_173 - 1 ) ) ;
V_175 . V_177 = 2 ;
V_175 . V_236 = F_78 ;
} else {
V_173 -> V_176 = F_31 ( V_232 ) ;
V_175 . V_177 = V_230 ;
}
V_173 -> V_175 = F_63 ( * ( T_1 * ) & V_175 ) ;
}
}
static void F_80 ( struct V_1 * V_2 , T_1 time )
{
void T_4 * V_59 = V_2 -> V_59 ;
T_1 V_14 = 0 ;
if ( time == 0 ) {
F_11 ( V_119 , 0 ) ;
F_11 ( V_122 , 0x10000 ) ;
} else {
if ( V_95 > 0x1ff )
F_11 ( V_119 , 0x1ff | V_120 ) ;
else
F_11 ( V_119 , V_95 | V_120 ) ;
V_14 = 0x10000 | time ;
F_11 ( V_122 , V_14 ) ;
}
}
