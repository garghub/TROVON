void F_1 ( struct V_1 * V_2 ,
unsigned char V_3 , unsigned int V_4 )
{
F_2 ( V_2 , V_3 ) . V_5 = V_4 ;
}
static int F_3 ( struct V_1 * V_2 ,
unsigned char V_3 , unsigned int V_6 ,
unsigned int * V_7 )
{
unsigned int V_8 = V_9 ;
do {
* V_7 = F_4 ( V_2 , V_3 , V_6 ) ;
if ( ! ( F_4 ( V_2 , V_3 , V_10 ) & V_11 ) )
return 0 ;
} while ( V_8 -- );
F_5 ( L_1 ) ;
return - V_12 ;
}
static int F_6 ( struct V_1 * V_2 ,
unsigned char V_3 , unsigned int V_6 ,
unsigned int V_7 )
{
unsigned int V_8 = V_9 ;
do {
F_7 ( V_2 , V_3 , V_6 , V_7 ) ;
if ( ! ( F_4 ( V_2 , V_3 , V_10 ) & V_11 ) )
return 0 ;
} while ( V_8 -- );
F_5 ( L_2 ) ;
return - V_12 ;
}
static void F_8 ( struct V_1 * V_2 ,
unsigned char V_3 , unsigned char V_13 ,
unsigned int * V_14 )
{
unsigned int V_15 ;
F_3 ( V_2 , V_3 , V_16 , & V_15 ) ;
F_6 ( V_2 , V_3 , V_16 , V_13 ) ;
F_3 ( V_2 , V_3 , V_17 , V_14 ) ;
F_6 ( V_2 , V_3 , V_16 , V_15 ) ;
}
static int F_9 ( struct V_1 * V_2 ,
unsigned char V_3 , unsigned int V_18 ,
int V_19 )
{
unsigned int V_20 = 0 , V_21 = 0 ;
unsigned int V_6 = ( 1 << V_22 ) ;
int V_23 = V_24 ;
int V_25 = 0 ;
F_3 ( V_2 , V_3 , V_26 , & V_20 ) ;
V_20 &= 0xffff ;
while ( ( int ) V_18 > V_25 && V_23 -- ) {
if ( V_19 )
F_3 ( V_2 , V_3 , V_27 , & V_6 ) ;
F_3 ( V_2 , V_3 , V_26 , & V_21 ) ;
V_21 &= 0xffff ;
V_25 = V_21 - V_20 ;
if ( V_25 < 0 )
V_25 += 0x10000 ;
if ( V_25 >= 8 && ! ( V_6 & ( 1 << V_22 ) ) )
return 0 ;
}
if ( V_23 < 0 ) {
F_5 ( L_3 ) ;
return - V_12 ;
}
return 0 ;
}
int F_10 ( struct V_1 * V_2 ,
unsigned char V_3 , unsigned char V_28 )
{
unsigned int V_6 , V_29 ;
if ( ( V_28 != 4 ) && ( V_28 != 8 ) ) {
F_5 ( L_4 , V_28 ) ;
return - V_30 ;
}
F_3 ( V_2 , V_3 , V_31 , & V_6 ) ;
V_6 = V_32 & V_6 ;
V_29 = ( V_28 == 4 ) ?
F_11 ( V_6 , V_33 ) :
F_12 ( V_6 , V_33 ) ;
F_6 ( V_2 , V_3 , V_31 , V_29 ) ;
return 0 ;
}
int F_13 ( struct V_1 * V_2 ,
unsigned char V_3 , unsigned char V_28 )
{
unsigned int V_6 , V_29 ;
F_3 ( V_2 , V_3 , V_31 , & V_6 ) ;
V_6 &= V_32 ;
V_29 = ( V_28 ) ?
F_11 ( V_6 , V_34 ) :
F_12 ( V_6 , V_34 ) ;
if ( V_29 != V_6 )
F_6 ( V_2 , V_3 , V_31 , V_29 ) ;
return 0 ;
}
int F_14 ( struct V_1 * V_2 ,
unsigned char V_3 , enum V_35 V_36 ,
unsigned char V_28 )
{
unsigned int V_6 , V_29 ;
F_3 ( V_2 , V_3 , V_31 , & V_6 ) ;
V_6 &= V_32 ;
switch ( V_36 ) {
case V_37 :
V_29 = ( V_28 ) ?
F_11 ( V_6 , V_38 ) :
F_12 ( V_6 , V_38 ) ;
break;
case V_39 :
V_29 = ( V_28 ) ?
F_11 ( V_6 , V_40 ) :
F_12 ( V_6 , V_40 ) ;
break;
default:
F_5 ( L_5 , V_36 ) ;
return - V_30 ;
}
if ( V_29 != V_6 )
F_6 ( V_2 , V_3 , V_31 , V_29 ) ;
return 0 ;
}
static unsigned short F_15 ( unsigned int type ,
unsigned short V_41 )
{
unsigned short V_42 ;
switch ( type ) {
case V_43 :
case V_44 :
V_42 = 0x80 | ( V_41 & 0x7f ) ;
break;
case V_45 :
case V_46 :
V_42 = V_41 & 0x1f ;
break;
case V_47 :
case V_48 :
case V_49 :
V_42 = 0x180 | ( V_41 & 0x1f ) ;
break;
case V_50 :
V_42 = 0x140 | ( ( V_41 & 0x3 ) << 1 ) ;
break;
case V_51 :
case V_52 :
case V_53 :
V_42 = 0x1c0 | ( V_41 & 0x1f ) ;
break;
case V_54 :
V_42 = 0x100 | ( ( V_41 & 0x3 ) << 1 ) ;
break;
case V_55 :
V_42 = 0x280 | ( V_41 & 0x1f ) ;
break;
case V_37 :
V_42 = 0x200 ;
break;
case V_39 :
V_42 = 0x220 ;
break;
case V_56 :
V_42 = 0x300 | ( V_41 & 0xff ) ;
break;
default:
V_42 = V_57 ;
break;
}
return V_42 ;
}
void F_16 ( struct V_1 * V_2 )
{
unsigned int V_58 ;
V_58 = F_17 ( V_2 , V_59 ) ;
V_58 |= V_2 -> V_60 -> V_61 << V_62 ;
V_58 |= V_2 -> V_60 -> V_63 << V_64 ;
F_18 ( V_2 , V_59 , V_58 ) ;
}
static void F_19 ( struct V_1 * V_2 ,
unsigned char V_3 , unsigned int V_4 ,
unsigned int V_65 , unsigned int V_66 )
{
unsigned int V_13 , V_15 ;
F_3 ( V_2 , V_3 , V_16 , & V_15 ) ;
for ( V_13 = 0 ; V_13 < V_67 ; V_13 ++ ) {
if ( ! ( V_4 & ( 1 << V_13 ) ) )
continue;
F_6 ( V_2 , V_3 , V_16 , V_13 ) ;
F_6 ( V_2 , V_3 , V_65 , V_66 ) ;
}
F_6 ( V_2 , V_3 , V_16 , V_15 ) ;
}
static void F_20 ( struct V_1 * V_2 ,
unsigned char V_3 , unsigned char V_13 ,
unsigned int V_65 , unsigned int * V_66 )
{
unsigned int V_15 ;
F_3 ( V_2 , V_3 , V_16 , & V_15 ) ;
F_6 ( V_2 , V_3 , V_16 , V_13 ) ;
F_3 ( V_2 , V_3 , V_65 , V_66 ) ;
F_6 ( V_2 , V_3 , V_16 , V_15 ) ;
}
static void F_21 ( struct V_1 * V_2 ,
unsigned char V_3 , unsigned int V_4 ,
unsigned int V_14 )
{
unsigned int V_13 , V_15 ;
F_3 ( V_2 , V_3 , V_16 , & V_15 ) ;
for ( V_13 = 0 ; V_13 < V_67 ; V_13 ++ ) {
if ( ! ( V_4 & ( 1 << V_13 ) ) )
continue;
F_6 ( V_2 , V_3 , V_16 , V_13 ) ;
F_6 ( V_2 , V_3 , V_68 , V_14 ) ;
}
F_6 ( V_2 , V_3 , V_16 , V_15 ) ;
}
static void F_22 ( struct V_1 * V_2 ,
unsigned char V_3 , unsigned int V_4 ,
unsigned int V_14 )
{
unsigned int V_13 , V_15 ;
F_3 ( V_2 , V_3 , V_16 , & V_15 ) ;
for ( V_13 = 0 ; V_13 < V_67 ; V_13 ++ ) {
if ( ! ( V_4 & ( 1 << V_13 ) ) )
continue;
F_6 ( V_2 , V_3 , V_16 , V_13 ) ;
F_6 ( V_2 , V_3 , V_17 ,
V_14 ) ;
}
F_6 ( V_2 , V_3 , V_16 , V_15 ) ;
}
static int F_23 ( struct V_1 * V_2 )
{
unsigned int V_20 , V_21 ;
unsigned char V_3 ;
int V_23 = V_24 ;
for ( V_3 = 0 ; V_3 < V_2 -> V_60 -> V_69 ; V_3 ++ ) {
F_3 ( V_2 , V_3 , V_26 ,
( unsigned int * ) & V_20 ) ;
V_20 &= 0xffff ;
do {
F_3 ( V_2 , V_3 , V_26 ,
( unsigned int * ) & V_21 ) ;
V_21 &= 0xffff ;
} while ( V_23 -- && ( V_21 == V_20 ) );
if ( V_23 < 0 ) {
F_5 ( L_6 , V_3 ) ;
return - V_12 ;
}
}
return 0 ;
}
int F_24 ( struct V_1 * V_2 ,
unsigned int V_3 )
{
unsigned int V_70 = 0 , V_71 = 0 ;
F_3 ( V_2 , V_3 , V_31 , & V_70 ) ;
F_3 ( V_2 , V_3 , V_27 , & V_71 ) ;
if ( ( V_70 & ( 0xff << V_72 ) ) ||
( V_71 & ( 1 << V_22 ) ) )
return 1 ;
else
return 0 ;
}
static void F_25 ( struct V_1 * V_2 )
{
unsigned int V_73 ;
unsigned char V_3 ;
V_73 = F_17 ( V_2 , V_74 ) ;
if ( V_73 & V_75 )
F_18 ( V_2 , V_74 , V_73 &
( ~ V_75 ) ) ;
for ( V_3 = 0 ; V_3 < V_2 -> V_60 -> V_69 ; V_3 ++ ) {
F_6 ( V_2 , V_3 , V_76 , 0 ) ;
F_6 ( V_2 , V_3 , V_77 , 0 ) ;
}
F_18 ( V_2 , V_74 , V_73 | V_75 ) ;
}
static int F_26 ( struct V_1 * V_2 )
{
void T_1 * V_78 =
( void T_1 * ) ( ( V_79 ) V_2 -> V_80 +
V_81 ) ;
unsigned int V_66 ;
int V_23 = 30 ;
if ( V_2 -> V_82 -> V_83 != V_84 )
return 0 ;
V_66 = F_27 ( V_78 , 0 ) ;
if ( ( V_66 & V_85 ) && ( V_66 & V_86 ) )
return 0 ;
V_66 = F_27 ( V_78 , 0 ) ;
V_66 |= V_85 ;
F_28 ( V_78 , 0 , V_66 ) ;
do {
F_9 ( V_2 , 0 , V_87 , 0 ) ;
V_66 = F_27 ( V_78 , 0 ) ;
} while ( ! ( V_66 & V_86 ) && V_23 -- );
if ( ( V_23 < 0 ) ) {
F_5 ( L_7 ) ;
return - V_12 ;
}
return 0 ;
}
int F_29 ( struct V_1 * V_2 )
{
unsigned int V_58 ;
unsigned char V_3 ;
unsigned int V_88 ;
unsigned int V_23 = 100 ;
unsigned int V_6 ;
V_58 = F_17 ( V_2 , V_59 ) ;
V_58 &= ~ ( V_2 -> V_60 -> V_61 << V_62 ) ;
V_58 &= ~ ( V_2 -> V_60 -> V_63 << V_64 ) ;
do {
F_18 ( V_2 , V_59 , V_58 ) ;
if ( ! ( V_23 -- ) )
goto V_89;
V_6 = F_17 ( V_2 , V_59 ) ;
} while ( ( V_2 -> V_60 -> V_61 |
( V_2 -> V_60 -> V_63 << V_64 ) ) & V_6 );
V_88 = F_17 ( V_2 , V_90 ) ;
V_88 |= V_2 -> V_60 -> V_61 << 0 ;
V_88 |= V_2 -> V_60 -> V_63 << 20 ;
F_18 ( V_2 , V_90 , V_88 ) ;
if ( F_23 ( V_2 ) )
goto V_89;
for ( V_3 = 0 ; V_3 < V_2 -> V_60 -> V_69 ; V_3 ++ ) {
F_6 ( V_2 , V_3 , V_31 ,
V_91 ) ;
F_19 ( V_2 , V_3 , V_92 ,
V_93 ,
V_2 -> V_60 -> V_94 &
V_95 ) ;
F_6 ( V_2 , V_3 , V_96 , V_97 ) ;
F_6 ( V_2 , V_3 , V_98 , V_99 ) ;
F_22 ( V_2 , V_3 ,
V_92 ,
V_100 ) ;
F_21 ( V_2 , V_3 ,
V_92 ,
V_101 ) ;
}
if ( F_26 ( V_2 ) )
goto V_89;
if ( F_9 ( V_2 , 0 , V_102 , 0 ) )
goto V_89;
F_25 ( V_2 ) ;
return 0 ;
V_89:
F_5 ( L_8 ) ;
return - V_12 ;
}
static void F_30 ( struct V_1 * V_2 ,
unsigned char V_3 , unsigned int V_4 )
{
unsigned int V_13 ;
F_3 ( V_2 , V_3 , V_31 , & V_13 ) ;
V_13 &= V_32 &
( ~ ( ( V_4 & V_92 ) << V_72 ) ) ;
F_6 ( V_2 , V_3 , V_31 , V_13 ) ;
}
static T_2 F_31 ( T_2 V_103 )
{
V_103 ^= V_103 >> 1 ;
V_103 ^= V_103 >> 2 ;
V_103 ^= V_103 >> 4 ;
V_103 ^= V_103 >> 8 ;
V_103 ^= V_103 >> 16 ;
V_103 ^= V_103 >> 32 ;
return V_103 & 1 ;
}
static T_2 F_32 ( T_2 V_104 )
{
T_2 V_105 = 0xff800007fffULL , V_106 = 0x1f801ff801fULL ,
V_107 = 0xe387e0781e1ULL , V_108 = 0x7cb8e388e22ULL ,
V_109 = 0xaf5b2c93244ULL , V_110 = 0xf56d5525488ULL ,
V_111 = 0xdaf69a46910ULL ;
V_104 &= ~ ( 0x7fULL << 0x2C ) ;
V_104 |= F_31 ( V_105 & V_104 ) << 0x2C ;
V_104 |= F_31 ( V_106 & V_104 ) << 0x2D ;
V_104 |= F_31 ( V_107 & V_104 ) << 0x2E ;
V_104 |= F_31 ( V_108 & V_104 ) << 0x2F ;
V_104 |= F_31 ( V_109 & V_104 ) << 0x30 ;
V_104 |= F_31 ( V_110 & V_104 ) << 0x31 ;
V_104 |= F_31 ( V_111 & V_104 ) << 0x32 ;
return V_104 ;
}
void F_33 ( struct V_1 * V_2 ,
unsigned char V_3 , unsigned int V_112 ,
unsigned int V_113 , T_2 * V_104 )
{
unsigned int V_114 ;
unsigned int V_115 ;
F_3 ( V_2 , V_3 , V_116 , & V_114 ) ;
V_112 |= V_117 ;
F_6 ( V_2 , V_3 , V_116 , V_112 ) ;
for ( V_115 = 0 ; V_115 < V_113 ; V_115 ++ ) {
unsigned int V_118 , V_119 ;
T_2 V_120 ;
V_120 = F_32 ( V_104 [ V_115 ] ) ;
V_118 = ( unsigned int ) ( V_120 & 0xffffffff ) ;
V_119 = ( unsigned int ) ( V_120 >> 0x20 ) ;
F_6 ( V_2 , V_3 , V_121 , V_118 ) ;
F_6 ( V_2 , V_3 , V_122 , V_119 ) ;
}
F_6 ( V_2 , V_3 , V_116 , V_114 ) ;
}
static void F_34 ( struct V_1 * V_2 ,
unsigned char V_3 , unsigned int V_4 )
{
unsigned int V_13 ;
F_3 ( V_2 , V_3 , V_31 , & V_13 ) ;
V_13 &= V_32 ;
V_4 &= ( V_13 & V_123 ) ? 0x55 : 0xFF ;
V_13 |= ( V_4 << V_72 ) ;
F_6 ( V_2 , V_3 , V_31 , V_13 ) ;
}
static void F_35 ( struct V_1 * V_2 )
{
unsigned char V_3 ;
unsigned short V_124 ;
for ( V_3 = 0 ; V_3 < V_2 -> V_60 -> V_69 ; V_3 ++ ) {
for ( V_124 = 0 ; V_124 < V_125 ; V_124 ++ ) {
F_36 ( V_2 , V_3 , 0 , V_126 ,
V_124 , 0 ) ;
F_36 ( V_2 , V_3 , 0 , V_127 ,
V_124 , 0 ) ;
}
}
}
static int F_37 ( struct V_1 * V_2 )
{
unsigned char V_3 ;
unsigned int V_4 = V_92 ;
int V_23 = V_24 ;
unsigned int V_66 = 0 ;
unsigned int V_128 = 0 ;
int V_129 = 0 ;
for ( V_3 = 0 ; V_3 < V_2 -> V_60 -> V_69 ; V_3 ++ ) {
F_3 ( V_2 , V_3 , V_130 , & V_66 ) ;
V_66 &= ~ ( 1 << V_131 ) ;
F_6 ( V_2 , V_3 , V_130 , V_66 ) ;
F_3 ( V_2 , V_3 , V_31 , & V_66 ) ;
V_66 &= V_32 ;
V_66 |= V_132 ;
F_6 ( V_2 , V_3 , V_31 , V_66 ) ;
F_33 ( V_2 , V_3 , 0 , F_38 ( V_133 ) ,
( T_2 * ) V_133 ) ;
F_19 ( V_2 , V_3 , V_4 , V_93 ,
V_2 -> V_60 -> V_94 &
V_95 ) ;
F_3 ( V_2 , V_3 , V_27 , & V_128 ) ;
F_6 ( V_2 , V_3 , V_27 , 0 ) ;
F_22 ( V_2 , V_3 , V_4 , V_134 ) ;
F_19 ( V_2 , V_3 , V_4 ,
V_68 , 0 ) ;
F_6 ( V_2 , V_3 , V_135 , 0 ) ;
F_34 ( V_2 , V_3 , V_4 ) ;
}
for ( V_3 = 0 ; V_3 < V_2 -> V_60 -> V_69 ; V_3 ++ ) {
do {
V_129 = F_9 ( V_2 , V_3 , 20 , 1 ) ;
} while ( V_129 && V_23 -- );
if ( V_23 < 0 ) {
F_5 ( L_9 , V_3 ) ;
return - V_30 ;
}
F_30 ( V_2 , V_3 , V_4 ) ;
F_6 ( V_2 , V_3 , V_27 ,
V_128 & V_136 ) ;
F_6 ( V_2 , V_3 , V_31 ,
V_91 ) ;
F_19 ( V_2 , V_3 , V_4 , V_93 ,
V_2 -> V_60 -> V_94 &
V_95 ) ;
F_6 ( V_2 , V_3 , V_96 , V_97 ) ;
F_6 ( V_2 , V_3 , V_98 , V_99 ) ;
F_22 ( V_2 , V_3 , V_4 ,
V_100 ) ;
F_21 ( V_2 , V_3 , V_4 ,
V_101 ) ;
}
return 0 ;
}
int F_39 ( struct V_137 * V_138 )
{
unsigned char V_3 ;
unsigned int V_139 = 0 ;
struct V_1 * V_2 ;
struct V_140 * V_141 = & V_138 -> V_142 ;
struct V_143 * V_144 = V_138 -> V_145 ;
struct V_146 * V_147 =
& V_141 -> V_148 [ V_144 -> V_149 ( V_144 ) ] ;
struct V_146 * V_150 ;
V_2 = F_40 ( sizeof( * V_2 ) , V_151 ) ;
if ( ! V_2 )
return - V_152 ;
V_2 -> V_153 =
( void T_1 * ) ( ( V_79 ) V_147 -> V_154 +
V_155 ) ;
V_2 -> V_156 =
( void T_1 * ) ( ( V_79 ) V_147 -> V_154 +
V_157 ) ;
V_2 -> V_80 =
( void T_1 * ) ( ( V_79 ) V_147 -> V_154 +
V_158 ) ;
V_2 -> V_159 =
( void T_1 * ) ( ( V_79 ) V_2 -> V_156 +
V_160 ) ;
V_2 -> V_82 = V_141 -> V_82 ;
if ( V_2 -> V_82 -> V_83 == V_84 ) {
V_150 =
& V_141 -> V_148 [ V_144 -> V_161 ( V_144 ) ] ;
V_2 -> V_162 = V_150 -> V_154 ;
}
V_2 -> V_163 = ( V_2 -> V_82 -> V_83 ==
V_84 ) ? false : true ;
V_2 -> V_60 = F_40 ( sizeof( * V_2 -> V_60 ) , V_151 ) ;
if ( ! V_2 -> V_60 )
goto V_164;
V_2 -> V_60 -> V_165 = V_138 -> V_142 . V_166 ;
V_2 -> V_60 -> V_61 = V_144 -> V_61 ;
V_2 -> V_60 -> V_63 = V_144 -> V_167 ;
V_2 -> V_60 -> V_94 = 0x1ffff ;
V_2 -> V_60 -> V_168 = 0x4000 ;
for ( V_3 = 0 ; V_3 < V_169 ; V_3 ++ ) {
if ( ! ( V_144 -> V_61 & ( 1 << V_3 ) ) )
continue;
V_2 -> V_60 -> V_170 [ V_3 ] . V_171 = 0 ;
V_2 -> V_60 -> V_170 [ V_3 ] . V_172 =
V_2 -> V_60 -> V_168 ;
V_2 -> V_60 -> V_170 [ V_3 ] . V_173 =
V_2 -> V_60 -> V_168 ;
V_2 -> V_60 -> V_170 [ V_3 ] . V_5 =
V_92 ;
V_139 = V_3 ;
}
V_2 -> V_60 -> V_69 = V_139 + 1 ;
if ( F_29 ( V_2 ) ) {
F_41 ( & F_42 ( V_138 ) , L_10 ) ;
goto V_89;
}
F_35 ( V_2 ) ;
if ( ! V_2 -> V_163 ) {
if ( F_37 ( V_2 ) )
goto V_89;
}
for ( V_3 = 0 ; V_3 < V_2 -> V_60 -> V_69 ; V_3 ++ ) {
unsigned int V_66 = 0 ;
F_3 ( V_2 , V_3 , V_174 , & V_66 ) ;
V_66 |= 0x1 ;
F_6 ( V_2 , V_3 , V_174 , V_66 ) ;
}
V_138 -> V_175 -> V_175 = V_2 ;
return 0 ;
V_89:
F_43 ( V_2 -> V_60 ) ;
V_164:
F_43 ( V_2 ) ;
return - V_12 ;
}
void F_44 ( struct V_1 * V_2 )
{
if ( ! V_2 )
return;
F_43 ( V_2 -> V_60 ) ;
F_43 ( V_2 ) ;
}
void F_45 ( struct V_1 * V_2 , unsigned char V_3 ,
unsigned int V_4 )
{
int V_176 = 0 ;
unsigned int V_177 = 0 ;
if ( V_2 -> V_163 ) {
F_46 ( V_2 , V_178 , V_179 ) ;
do {
F_47 ( V_180 ) ;
V_177 = F_48 ( V_2 , V_181 ) ;
if ( ( ( V_177 >> V_182 ) & 0x1 ) )
return;
} while ( V_176 ++ < V_183 );
F_5 ( L_11 , V_3 ,
V_177 ) ;
} else {
F_22 ( V_2 , V_3 , ( ~ V_4 ) &
V_92 , 0x10000 ) ;
F_34 ( V_2 , V_3 , V_4 ) ;
}
}
void F_49 ( struct V_1 * V_2 , unsigned char V_3 ,
unsigned int V_4 )
{
if ( ! V_2 -> V_163 )
F_30 ( V_2 , V_3 , V_4 ) ;
}
void F_50 ( struct V_1 * V_2 ,
unsigned char V_3 , unsigned int V_4 , unsigned int V_184 )
{
F_19 ( V_2 , V_3 , V_4 , V_93 ,
V_2 -> V_60 -> V_94 & V_184 ) ;
}
static void F_51 ( struct V_1 * V_2 ,
unsigned char V_3 , unsigned int V_112 ,
unsigned int V_113 , T_2 * V_104 )
{
unsigned int V_115 , V_118 , V_119 ;
unsigned int V_114 , V_185 ;
F_3 ( V_2 , V_3 , V_130 , & V_185 ) ;
F_6 ( V_2 , V_3 , V_130 ,
V_185 & 0xfffffffb ) ;
F_3 ( V_2 , V_3 , V_116 , & V_114 ) ;
V_112 |= V_117 ;
for ( V_115 = 0 ; V_115 < V_113 ; V_115 ++ ) {
F_6 ( V_2 , V_3 , V_116 , V_112 ) ;
V_112 ++ ;
F_3 ( V_2 , V_3 , V_121 , & V_118 ) ;
F_3 ( V_2 , V_3 , V_122 , & V_119 ) ;
V_104 [ V_115 ] = V_119 ;
V_104 [ V_115 ] = ( V_104 [ V_115 ] << 0x20 ) | V_118 ;
}
F_6 ( V_2 , V_3 , V_130 , V_185 ) ;
F_6 ( V_2 , V_3 , V_116 , V_114 ) ;
}
void F_52 ( struct V_1 * V_2 ,
unsigned char V_3 , unsigned int V_112 ,
unsigned int V_113 , unsigned int * V_186 )
{
unsigned int V_115 , V_114 ;
F_3 ( V_2 , V_3 , V_116 , & V_114 ) ;
V_112 |= V_117 ;
F_6 ( V_2 , V_3 , V_116 , V_112 ) ;
for ( V_115 = 0 ; V_115 < V_113 ; V_115 ++ ) {
unsigned int V_118 , V_119 , V_120 ;
V_118 = ( ( V_186 [ V_115 ] & 0xfff0000 ) << 4 ) | ( 0x3 << 18 ) |
( ( V_186 [ V_115 ] & 0xff00 ) << 2 ) |
( 0x3 << 8 ) | ( V_186 [ V_115 ] & 0xff ) ;
V_119 = ( 0xf << 4 ) | ( ( V_186 [ V_115 ] & 0xf0000000 ) >> 28 ) ;
V_119 |= ( F_53 ( V_186 [ V_115 ] & 0xffff ) & 0x1 ) << 8 ;
V_120 = ( ( V_186 [ V_115 ] >> 0x10 ) & 0xffff ) ;
V_119 |= ( F_53 ( V_120 ) & 0x1 ) << 9 ;
F_6 ( V_2 , V_3 , V_121 , V_118 ) ;
F_6 ( V_2 , V_3 , V_122 , V_119 ) ;
}
F_6 ( V_2 , V_3 , V_116 , V_114 ) ;
}
static int F_54 ( struct V_1 * V_2 ,
unsigned char V_3 , unsigned char V_13 ,
T_2 * V_187 , unsigned int V_188 ,
int V_189 , unsigned int V_190 ,
unsigned int * V_191 )
{
T_2 V_192 [ V_193 ] ;
unsigned int V_194 , V_195 ;
unsigned int V_196 , V_197 ;
unsigned int V_198 ;
unsigned int V_199 , V_200 ;
unsigned int V_66 = 0 , V_201 ;
unsigned int V_128 ;
unsigned int V_202 , V_203 , V_204 ;
unsigned int V_205 , V_206 ;
if ( ( V_188 > V_2 -> V_60 -> V_168 ) || ! V_187 ) {
F_5 ( L_12 , V_188 ) ;
return - V_30 ;
}
F_20 ( V_2 , V_3 , V_13 , V_207 , & V_194 ) ;
F_20 ( V_2 , V_3 , V_13 , V_208 , & V_195 ) ;
F_20 ( V_2 , V_3 , V_13 , V_209 ,
& V_196 ) ;
F_20 ( V_2 , V_3 , V_13 , V_210 ,
& V_197 ) ;
if ( V_188 <= V_193 )
F_51 ( V_2 , V_3 , 0 , V_188 , V_192 ) ;
F_8 ( V_2 , V_3 , V_13 , & V_203 ) ;
F_20 ( V_2 , V_3 , V_13 , V_93 , & V_204 ) ;
V_204 = ( V_204 & V_2 -> V_60 -> V_94 ) >> 0 ;
F_3 ( V_2 , V_3 , V_31 , & V_206 ) ;
V_206 &= V_32 ;
F_3 ( V_2 , V_3 , V_98 , & V_202 ) ;
F_3 ( V_2 , V_3 , V_27 , & V_128 ) ;
F_3 ( V_2 , V_3 , V_96 , & V_205 ) ;
F_20 ( V_2 , V_3 , V_13 , V_211 ,
& V_198 ) ;
F_20 ( V_2 , V_3 , V_13 , V_68 , & V_199 ) ;
F_3 ( V_2 , V_3 , V_135 , & V_200 ) ;
F_6 ( V_2 , V_3 , V_31 , V_206 ) ;
F_33 ( V_2 , V_3 , 0 , V_188 , V_187 ) ;
F_19 ( V_2 , V_3 , ( 1 << V_13 ) , V_93 , 0 ) ;
F_6 ( V_2 , V_3 , V_27 , V_13 & V_136 ) ;
if ( V_189 )
F_6 ( V_2 , V_3 , V_98 , V_202 & 0xffffdfff ) ;
F_22 ( V_2 , V_3 , ( 1 << V_13 ) , V_134 ) ;
F_19 ( V_2 , V_3 , ( 1 << V_13 ) , V_68 , 0 ) ;
F_6 ( V_2 , V_3 , V_135 , 0 ) ;
F_34 ( V_2 , V_3 , ( 1 << V_13 ) ) ;
if ( F_9 ( V_2 , V_3 , V_190 , 1 ) != 0 )
return - V_12 ;
if ( V_191 ) {
unsigned int V_212 ;
F_20 ( V_2 , V_3 , V_13 , V_93 ,
& V_212 ) ;
* V_191 = V_212 & V_2 -> V_60 -> V_94 ;
}
F_30 ( V_2 , V_3 , ( 1 << V_13 ) ) ;
if ( V_188 <= V_193 )
F_33 ( V_2 , V_3 , 0 , V_188 , V_192 ) ;
F_22 ( V_2 , V_3 , ( 1 << V_13 ) , V_203 ) ;
F_19 ( V_2 , V_3 , ( 1 << V_13 ) , V_93 ,
V_2 -> V_60 -> V_94 & V_204 ) ;
F_3 ( V_2 , V_3 , V_130 , & V_66 ) ;
V_201 = F_12 ( V_66 , V_131 ) ;
F_6 ( V_2 , V_3 , V_130 , V_201 ) ;
F_6 ( V_2 , V_3 , V_98 , V_202 ) ;
F_6 ( V_2 , V_3 , V_27 , V_128 & V_136 ) ;
F_6 ( V_2 , V_3 , V_96 , V_205 ) ;
F_19 ( V_2 , V_3 , ( 1 << V_13 ) ,
V_207 , V_194 ) ;
F_19 ( V_2 , V_3 , ( 1 << V_13 ) ,
V_208 , V_195 ) ;
F_19 ( V_2 , V_3 , ( 1 << V_13 ) ,
V_209 , V_196 ) ;
F_19 ( V_2 , V_3 , ( 1 << V_13 ) ,
V_210 , V_197 ) ;
F_19 ( V_2 , V_3 , ( 1 << V_13 ) ,
V_211 , V_198 ) ;
F_19 ( V_2 , V_3 , ( 1 << V_13 ) ,
V_68 , V_199 ) ;
F_6 ( V_2 , V_3 , V_135 , V_200 ) ;
F_6 ( V_2 , V_3 , V_31 , V_206 ) ;
return 0 ;
}
static int F_55 ( struct V_1 * V_2 ,
unsigned char V_3 , unsigned char V_13 ,
enum V_35 V_213 ,
unsigned short V_41 , unsigned int * V_186 )
{
unsigned int V_128 , V_112 , V_118 , V_119 ;
unsigned int V_214 , V_114 , V_206 ;
unsigned short V_42 ;
int V_215 = 0 ;
T_2 V_216 , V_217 ;
V_42 = F_15 ( V_213 , V_41 ) ;
if ( V_42 == V_57 ) {
F_5 ( L_13 , V_42 ) ;
return - V_30 ;
}
switch ( V_213 ) {
case V_45 :
V_216 = 0xA070000000ull | ( V_42 & 0x3ff ) ;
break;
default:
V_216 = ( T_2 ) 0xA030000000ull | ( ( V_42 & 0x3ff ) << 10 ) ;
break;
}
F_3 ( V_2 , V_3 , V_27 , & V_128 ) ;
F_3 ( V_2 , V_3 , V_96 , & V_214 ) ;
F_3 ( V_2 , V_3 , V_31 , & V_206 ) ;
V_206 &= V_32 ;
if ( V_13 != ( V_128 & V_136 ) )
F_6 ( V_2 , V_3 , V_27 ,
V_13 & V_136 ) ;
F_51 ( V_2 , V_3 , 0 , 1 , & V_217 ) ;
F_6 ( V_2 , V_3 , V_31 , V_206 ) ;
F_3 ( V_2 , V_3 , V_116 , & V_114 ) ;
V_112 = V_117 ;
F_6 ( V_2 , V_3 , V_116 , V_112 ) ;
V_216 = F_32 ( V_216 ) ;
V_118 = ( unsigned int ) ( V_216 & 0xffffffff ) ;
V_119 = ( unsigned int ) ( V_216 >> 0x20 ) ;
F_6 ( V_2 , V_3 , V_121 , V_118 ) ;
F_6 ( V_2 , V_3 , V_122 , V_119 ) ;
F_6 ( V_2 , V_3 , V_116 , V_112 ) ;
F_9 ( V_2 , V_3 , 0x8 , 0 ) ;
F_3 ( V_2 , V_3 , V_218 , V_186 ) ;
F_6 ( V_2 , V_3 , V_116 , V_114 ) ;
F_33 ( V_2 , V_3 , 0 , 1 , & V_217 ) ;
if ( V_13 != ( V_128 & V_136 ) )
F_6 ( V_2 , V_3 , V_27 ,
V_128 & V_136 ) ;
F_6 ( V_2 , V_3 , V_96 , V_214 ) ;
F_6 ( V_2 , V_3 , V_31 , V_206 ) ;
return V_215 ;
}
static int F_56 ( struct V_1 * V_2 ,
unsigned char V_3 , unsigned char V_13 ,
enum V_35 V_213 ,
unsigned short V_41 , unsigned int V_186 )
{
unsigned short V_219 , V_220 , V_221 , V_222 , V_223 ;
T_2 V_216 [] = {
0x0F440000000ull ,
0x0F040000000ull ,
0x0F0000C0300ull ,
0x0E000010000ull
} ;
const int V_224 = F_38 ( V_216 ) , V_189 = 1 ;
const int V_225 = 0 , V_226 = 1 ;
V_221 = F_15 ( V_213 , V_41 ) ;
if ( V_221 == V_57 ) {
F_5 ( L_14 , V_221 ) ;
return - V_30 ;
}
V_223 = 0xffff & V_186 ;
V_222 = 0xffff & ( V_186 >> 0x10 ) ;
V_219 = F_15 ( V_56 , ( unsigned short )
( 0xff & V_222 ) ) ;
V_220 = F_15 ( V_56 , ( unsigned short )
( 0xff & V_223 ) ) ;
switch ( V_213 ) {
case V_45 :
V_216 [ V_225 ] = V_216 [ V_225 ] | ( ( V_222 >> 8 ) << 20 ) |
( ( V_219 & 0x3ff ) << 10 ) | ( V_221 & 0x3ff ) ;
V_216 [ V_226 ] = V_216 [ V_226 ] | ( ( V_223 >> 8 ) << 20 ) |
( ( V_220 & 0x3ff ) << 10 ) | ( V_221 & 0x3ff ) ;
break;
default:
V_216 [ V_225 ] = V_216 [ V_225 ] | ( ( V_222 >> 8 ) << 20 ) |
( ( V_221 & 0x3ff ) << 10 ) | ( V_219 & 0x3ff ) ;
V_216 [ V_226 ] = V_216 [ V_226 ] | ( ( V_223 >> 8 ) << 20 ) |
( ( V_221 & 0x3ff ) << 10 ) | ( V_220 & 0x3ff ) ;
break;
}
return F_54 ( V_2 , V_3 , V_13 , V_216 , V_224 ,
V_189 , V_224 * 0x5 , NULL ) ;
}
int F_57 ( void )
{
return F_38 ( V_227 ) ;
}
static int F_58 ( T_2 * V_187 ,
unsigned int V_188 , unsigned int V_228 ,
unsigned int V_229 , unsigned int * V_7 )
{
int V_115 ;
unsigned int V_230 ;
const T_2 * V_231 ;
int V_232 ;
int V_233 = 0 ;
int V_234 ;
V_234 = V_188 ;
V_230 = V_7 [ 0 ] ;
V_231 = V_227 ;
V_233 = F_38 ( V_227 ) ;
V_232 = V_188 ;
for ( V_115 = 0 ; V_115 < V_233 ; V_115 ++ )
V_187 [ V_188 ++ ] = V_231 [ V_115 ] ;
F_59 ( V_187 [ V_232 ] , ( V_229 ) ) ;
V_232 ++ ;
F_59 ( V_187 [ V_232 ] , 0 ) ;
V_232 ++ ;
F_60 ( V_187 [ V_232 ] , ( V_230 >> 0 ) ) ;
V_232 ++ ;
F_60 ( V_187 [ V_232 ] , ( V_230 >> 0x10 ) ) ;
return V_188 - V_234 ;
}
static int F_61 ( struct V_1 * V_2 ,
unsigned char V_3 , unsigned char V_13 ,
int * V_235 , T_2 * V_187 ,
unsigned int V_188 )
{
int V_236 = 0 ;
unsigned int V_237 = 0 , V_238 = 0 , V_239 = 0 ;
unsigned int V_240 = 0 , V_241 = 0 ;
if ( * V_235 ) {
F_55 ( V_2 , V_3 , V_13 , V_45 , 0 , & V_237 ) ;
F_55 ( V_2 , V_3 , V_13 , V_45 , 0x1 , & V_238 ) ;
F_55 ( V_2 , V_3 , V_13 , V_45 , 0x2 , & V_239 ) ;
F_55 ( V_2 , V_3 , V_13 , V_46 , 0 , & V_240 ) ;
F_55 ( V_2 , V_3 , V_13 , V_46 , 0x1 , & V_241 ) ;
* V_235 = 0 ;
}
V_236 = F_54 ( V_2 , V_3 , V_13 , V_187 , V_188 , 1 ,
V_188 * 0x5 , NULL ) ;
if ( V_236 != 0 )
return - V_12 ;
F_56 ( V_2 , V_3 , V_13 , V_45 , 0 , V_237 ) ;
F_56 ( V_2 , V_3 , V_13 , V_45 , 0x1 , V_238 ) ;
F_56 ( V_2 , V_3 , V_13 , V_45 , 0x2 , V_239 ) ;
F_56 ( V_2 , V_3 , V_13 , V_46 , 0 , V_240 ) ;
F_56 ( V_2 , V_3 , V_13 , V_46 , 0x1 , V_241 ) ;
return 0 ;
}
int F_62 ( struct V_1 * V_2 ,
unsigned char V_3 ,
struct V_242 * V_243 )
{
struct V_242 * V_244 ;
T_2 * V_245 ;
int V_246 ;
int V_247 ;
int V_248 = 1 ;
int V_236 = 0 ;
V_244 = V_243 -> V_249 ;
V_247 = V_243 -> V_228 ;
if ( ( unsigned int ) V_247 > V_2 -> V_60 -> V_168 )
V_247 = V_2 -> V_60 -> V_168 ;
V_245 = F_63 ( V_247 , sizeof( T_2 ) ,
V_151 ) ;
if ( ! V_245 )
return - V_152 ;
V_246 = 0 ;
while ( V_244 ) {
unsigned int V_229 , * V_7 , V_228 ;
V_3 = V_244 -> V_3 ;
V_229 = V_244 -> V_229 ;
V_7 = V_244 -> V_7 ;
V_228 = V_244 -> V_228 ;
V_246 += F_58 ( V_245 ,
V_246 ,
V_228 , V_229 , V_7 ) ;
V_244 = V_244 -> V_249 ;
}
if ( V_245 && ( V_246 > 0 ) ) {
V_245 [ V_246 ++ ] = 0x0E000010000ull ;
V_236 = F_61 ( V_2 , V_3 , 0 , & V_248 ,
V_245 ,
V_246 ) ;
}
F_43 ( V_245 ) ;
return V_236 ;
}
static int F_64 ( struct V_1 * V_2 ,
unsigned char V_3 , unsigned char V_13 ,
enum V_35 V_213 ,
unsigned short V_41 , unsigned int V_250 )
{
int V_215 = 0 ;
unsigned int V_42 ;
unsigned int V_206 ;
unsigned short V_251 ;
unsigned short V_252 = 0x10 ;
V_215 = F_3 ( V_2 , V_3 , V_31 , & V_206 ) ;
if ( V_123 & V_206 ) {
if ( V_13 & 0x1 ) {
F_5 ( L_15 , V_13 ) ;
return - V_30 ;
}
V_251 = 0x1f ;
V_252 = 0x20 ;
} else {
V_251 = 0x0f ;
}
if ( V_41 & ~ V_251 )
return - V_30 ;
V_42 = V_41 + ( V_13 << 0x5 ) ;
switch ( V_213 ) {
case V_47 :
case V_49 :
F_65 ( V_2 , V_3 , V_42 , V_250 ) ;
break;
case V_51 :
case V_53 :
F_65 ( V_2 , V_3 , ( V_42 + V_252 ) , V_250 ) ;
break;
default:
V_215 = - V_30 ;
break;
}
return V_215 ;
}
static int F_66 ( struct V_1 * V_2 ,
unsigned char V_3 , unsigned char V_13 ,
enum V_35 V_213 ,
unsigned short V_41 , unsigned int V_186 )
{
unsigned int V_253 , V_206 ;
unsigned short V_219 , V_220 , V_254 , V_255 , V_222 ,
V_256 ;
unsigned short V_257 ;
int V_215 = 0 ;
T_2 V_187 [] = {
0x0F440000000ull ,
0x0F040000000ull ,
0x0A000000000ull ,
0x0F0000C0300ull ,
0x0E000010000ull
} ;
const int V_224 = F_38 ( V_187 ) , V_189 = 1 ;
const unsigned short V_258 = 0 , V_259 = V_224 * 0x5 ;
F_3 ( V_2 , V_3 , V_31 , & V_206 ) ;
if ( V_123 & V_206 ) {
if ( V_13 & 0x1 ) {
F_5 ( L_16 , V_13 ) ;
return - V_30 ;
}
V_257 = ( unsigned short ) ~ 0x1f ;
} else {
V_257 = ( unsigned short ) ~ 0xf ;
}
if ( V_41 & V_257 )
return - V_30 ;
V_255 = F_15 ( V_213 , V_41 ) ;
if ( V_255 == V_57 ) {
F_5 ( L_17 , V_255 ) ;
return - V_30 ;
}
F_55 ( V_2 , V_3 , V_13 , V_46 , V_258 , & V_253 ) ;
V_254 = F_15 ( V_46 , V_258 ) ;
V_256 = 0xffff & V_186 ;
V_222 = 0xffff & ( V_186 >> 0x10 ) ;
V_219 = F_15 ( V_56 ,
( unsigned short ) ( 0xff & V_222 ) ) ;
V_220 = F_15 ( V_56 ,
( unsigned short ) ( 0xff & V_256 ) ) ;
V_187 [ 0 ] = V_187 [ 0x0 ] | ( ( V_222 >> 8 ) << 20 ) |
( ( V_254 & 0x3ff ) << 10 ) | ( V_219 & 0x3ff ) ;
V_187 [ 1 ] = V_187 [ 0x1 ] | ( ( V_256 >> 8 ) << 20 ) |
( ( V_254 & 0x3ff ) << 10 ) | ( V_220 & 0x3ff ) ;
V_187 [ 0x2 ] = V_187 [ 0x2 ] |
( ( V_255 & 0x3ff ) << 20 ) | ( ( V_254 & 0x3ff ) << 10 ) ;
V_215 = F_54 ( V_2 , V_3 , V_13 , V_187 , V_224 ,
V_189 , V_259 , NULL ) ;
F_56 ( V_2 , V_3 , V_13 , V_46 , V_258 , V_253 ) ;
return V_215 ;
}
static int F_67 ( struct V_1 * V_2 ,
unsigned char V_3 , unsigned char V_13 ,
unsigned short V_260 , unsigned int V_250 )
{
unsigned int V_206 ;
int V_236 = 0 ;
F_3 ( V_2 , V_3 , V_31 , & V_206 ) ;
V_206 &= V_32 ;
F_6 ( V_2 , V_3 , V_31 , V_206 | V_132 ) ;
V_236 = F_66 ( V_2 , V_3 , V_13 , V_55 , V_260 , V_250 ) ;
F_6 ( V_2 , V_3 , V_31 , V_206 ) ;
return V_236 ;
}
static int F_68 ( struct V_1
* V_2 , unsigned char V_3 ,
unsigned short V_261 ,
unsigned short * V_262 ,
unsigned char * V_13 )
{
unsigned int V_206 ;
F_3 ( V_2 , V_3 , V_31 , & V_206 ) ;
if ( V_206 & V_123 ) {
* V_262 = V_261 & 0x1F ;
* V_13 = ( V_261 >> 0x4 ) & 0x6 ;
} else {
* V_262 = V_261 & 0x0F ;
* V_13 = ( V_261 >> 0x4 ) & 0x7 ;
}
return 0 ;
}
int F_69 ( struct V_1 * V_2 ,
unsigned char V_3 , unsigned char V_4 ,
enum V_35 V_213 ,
unsigned short V_41 , unsigned int V_263 )
{
int V_236 = 0 ;
unsigned short V_124 ;
unsigned char V_13 = 0 ;
enum V_35 type ;
if ( V_41 >= V_125 )
return - V_30 ;
do {
if ( V_4 == 0 ) {
F_68 ( V_2 , V_3 , V_41 , & V_124 ,
& V_13 ) ;
type = V_213 - 1 ;
} else {
V_124 = V_41 ;
type = V_213 ;
if ( ! F_70 ( V_13 , ( unsigned long * ) & V_4 ) )
continue;
}
V_236 = F_56 ( V_2 , V_3 , V_13 , type , V_124 , V_263 ) ;
if ( V_236 ) {
F_5 ( L_18 ) ;
return - V_30 ;
}
} while ( V_4 && ( V_13 ++ < V_67 ) );
return 0 ;
}
int F_71 ( struct V_1 * V_2 ,
unsigned char V_3 , unsigned char V_4 ,
enum V_35 V_213 ,
unsigned short V_41 , unsigned int V_263 )
{
int V_236 = 0 ;
unsigned short V_124 ;
unsigned char V_13 = 0 ;
enum V_35 type ;
if ( V_41 >= V_264 )
return - V_30 ;
do {
if ( V_4 == 0 ) {
F_68 ( V_2 , V_3 , V_41 , & V_124 ,
& V_13 ) ;
type = V_213 - 3 ;
} else {
V_124 = V_41 ;
type = V_213 ;
if ( ! F_70 ( V_13 , ( unsigned long * ) & V_4 ) )
continue;
}
V_236 = F_66 ( V_2 , V_3 , V_13 , type , V_124 ,
V_263 ) ;
if ( V_236 ) {
F_5 ( L_19 ) ;
return - V_30 ;
}
} while ( V_4 && ( V_13 ++ < V_67 ) );
return 0 ;
}
int F_36 ( struct V_1 * V_2 ,
unsigned char V_3 , unsigned char V_4 ,
enum V_35 V_213 ,
unsigned short V_41 , unsigned int V_263 )
{
int V_236 = 0 ;
unsigned short V_124 ;
unsigned char V_13 = 0 ;
enum V_35 type ;
if ( V_41 >= V_264 )
return - V_30 ;
do {
if ( V_4 == 0 ) {
F_68 ( V_2 , V_3 , V_41 , & V_124 ,
& V_13 ) ;
type = V_213 - 3 ;
} else {
V_124 = V_41 ;
type = V_213 ;
if ( ! F_70 ( V_13 , ( unsigned long * ) & V_4 ) )
continue;
}
V_236 = F_64 ( V_2 , V_3 , V_13 , type , V_124 ,
V_263 ) ;
if ( V_236 ) {
F_5 ( L_20 ) ;
return - V_30 ;
}
} while ( V_4 && ( V_13 ++ < V_67 ) );
return 0 ;
}
int F_72 ( struct V_1 * V_2 ,
unsigned char V_3 , unsigned char V_4 ,
unsigned short V_41 , unsigned int V_263 )
{
int V_236 = 0 ;
unsigned char V_13 ;
if ( V_4 == 0 )
return - V_30 ;
for ( V_13 = 0 ; V_13 < V_67 ; V_13 ++ ) {
if ( ! F_70 ( V_13 , ( unsigned long * ) & V_4 ) )
continue;
V_236 = F_67 ( V_2 , V_3 , V_13 , V_41 , V_263 ) ;
if ( V_236 ) {
F_5 ( L_21 ) ;
return - V_30 ;
}
}
return 0 ;
}
