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
if ( ! V_23 ) {
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
unsigned int V_23 = V_24 ;
for ( V_3 = 0 ; V_3 < V_2 -> V_60 -> V_69 ; V_3 ++ ) {
if ( ! ( V_2 -> V_60 -> V_61 & ( 1 << V_3 ) ) )
continue;
F_3 ( V_2 , V_3 , V_26 ,
( unsigned int * ) & V_20 ) ;
V_20 &= 0xffff ;
do {
F_3 ( V_2 , V_3 , V_26 ,
( unsigned int * ) & V_21 ) ;
V_21 &= 0xffff ;
} while ( V_23 -- && ( V_21 == V_20 ) );
if ( ! V_23 ) {
F_5 ( L_6 , V_3 ) ;
return - V_12 ;
}
}
return 0 ;
}
static void F_24 ( struct V_1 * V_2 )
{
unsigned int V_70 ;
unsigned char V_3 ;
V_70 = F_17 ( V_2 , V_71 ) ;
if ( V_70 & V_72 )
F_18 ( V_2 , V_71 , V_70 &
( ~ V_72 ) ) ;
for ( V_3 = 0 ; V_3 < V_2 -> V_60 -> V_69 ; V_3 ++ ) {
if ( ! ( V_2 -> V_60 -> V_61 & ( 1 << V_3 ) ) )
continue;
F_6 ( V_2 , V_3 , V_73 , 0 ) ;
F_6 ( V_2 , V_3 , V_74 , 0 ) ;
}
F_18 ( V_2 , V_71 , V_70 | V_72 ) ;
}
static int F_25 ( struct V_1 * V_2 )
{
void T_1 * V_75 = V_2 -> V_76 +
V_77 ;
unsigned int V_66 , V_23 = 30 ;
V_66 = F_26 ( V_75 , 0 ) ;
if ( ( V_66 & V_78 ) && ( V_66 & V_79 ) )
return 0 ;
V_66 = F_26 ( V_75 , 0 ) ;
V_66 |= V_78 ;
F_27 ( V_75 , 0 , V_66 ) ;
do {
F_9 ( V_2 , 0 , V_80 , 0 ) ;
V_66 = F_26 ( V_75 , 0 ) ;
} while ( ! ( V_66 & V_79 ) && V_23 -- );
if ( ( ! V_23 ) ) {
F_5 ( L_7 ) ;
return - V_12 ;
}
return 0 ;
}
int F_28 ( struct V_1 * V_2 )
{
unsigned int V_58 ;
unsigned char V_3 ;
unsigned int V_81 ;
unsigned int V_23 = 100 ;
unsigned int V_6 ;
V_58 = F_17 ( V_2 , V_59 ) ;
V_58 &= ~ ( V_2 -> V_60 -> V_61 << V_62 ) ;
V_58 &= ~ ( V_2 -> V_60 -> V_63 << V_64 ) ;
do {
F_18 ( V_2 , V_59 , V_58 ) ;
if ( ! ( V_23 -- ) )
goto V_82;
V_6 = F_17 ( V_2 , V_59 ) ;
} while ( ( V_2 -> V_60 -> V_61 |
( V_2 -> V_60 -> V_63 << V_64 ) ) & V_6 );
V_81 = F_17 ( V_2 , V_83 ) ;
V_81 |= V_2 -> V_60 -> V_61 << 0 ;
V_81 |= V_2 -> V_60 -> V_63 << 20 ;
F_18 ( V_2 , V_83 , V_81 ) ;
if ( F_23 ( V_2 ) )
goto V_82;
for ( V_3 = 0 ; V_3 < V_2 -> V_60 -> V_69 ; V_3 ++ ) {
if ( ! ( V_2 -> V_60 -> V_61 & ( 1 << V_3 ) ) )
continue;
F_6 ( V_2 , V_3 , V_31 ,
V_84 ) ;
F_19 ( V_2 , V_3 , V_85 ,
V_86 ,
V_2 -> V_60 -> V_87 &
V_88 ) ;
F_6 ( V_2 , V_3 , V_89 , V_90 ) ;
F_6 ( V_2 , V_3 , V_91 , V_92 ) ;
F_22 ( V_2 , V_3 ,
V_85 ,
V_93 ) ;
F_21 ( V_2 , V_3 ,
V_85 ,
V_94 ) ;
}
if ( F_25 ( V_2 ) )
goto V_82;
if ( F_9 ( V_2 , 0 , V_95 , 0 ) )
goto V_82;
F_24 ( V_2 ) ;
return 0 ;
V_82:
F_5 ( L_8 ) ;
return - V_12 ;
}
static void F_29 ( struct V_1 * V_2 ,
unsigned char V_3 , unsigned int V_4 )
{
unsigned int V_13 ;
F_3 ( V_2 , V_3 , V_31 , & V_13 ) ;
V_13 &= V_32 &
( ~ ( ( V_4 & V_85 ) << V_96 ) ) ;
F_6 ( V_2 , V_3 , V_31 , V_13 ) ;
}
static T_2 F_30 ( T_2 V_97 )
{
V_97 ^= V_97 >> 1 ;
V_97 ^= V_97 >> 2 ;
V_97 ^= V_97 >> 4 ;
V_97 ^= V_97 >> 8 ;
V_97 ^= V_97 >> 16 ;
V_97 ^= V_97 >> 32 ;
return V_97 & 1 ;
}
static T_2 F_31 ( T_2 V_98 )
{
T_2 V_99 = 0xff800007fffULL , V_100 = 0x1f801ff801fULL ,
V_101 = 0xe387e0781e1ULL , V_102 = 0x7cb8e388e22ULL ,
V_103 = 0xaf5b2c93244ULL , V_104 = 0xf56d5525488ULL ,
V_105 = 0xdaf69a46910ULL ;
V_98 &= ~ ( 0x7fULL << 0x2C ) ;
V_98 |= F_30 ( V_99 & V_98 ) << 0x2C ;
V_98 |= F_30 ( V_100 & V_98 ) << 0x2D ;
V_98 |= F_30 ( V_101 & V_98 ) << 0x2E ;
V_98 |= F_30 ( V_102 & V_98 ) << 0x2F ;
V_98 |= F_30 ( V_103 & V_98 ) << 0x30 ;
V_98 |= F_30 ( V_104 & V_98 ) << 0x31 ;
V_98 |= F_30 ( V_105 & V_98 ) << 0x32 ;
return V_98 ;
}
void F_32 ( struct V_1 * V_2 ,
unsigned char V_3 , unsigned int V_106 ,
unsigned int V_107 , T_2 * V_98 )
{
unsigned int V_108 ;
unsigned int V_109 ;
F_3 ( V_2 , V_3 , V_110 , & V_108 ) ;
V_106 |= V_111 ;
F_6 ( V_2 , V_3 , V_110 , V_106 ) ;
for ( V_109 = 0 ; V_109 < V_107 ; V_109 ++ ) {
unsigned int V_112 , V_113 ;
T_2 V_114 ;
V_114 = F_31 ( V_98 [ V_109 ] ) ;
V_112 = ( unsigned int ) ( V_114 & 0xffffffff ) ;
V_113 = ( unsigned int ) ( V_114 >> 0x20 ) ;
F_6 ( V_2 , V_3 , V_115 , V_112 ) ;
F_6 ( V_2 , V_3 , V_116 , V_113 ) ;
}
F_6 ( V_2 , V_3 , V_110 , V_108 ) ;
}
static void F_33 ( struct V_1 * V_2 ,
unsigned char V_3 , unsigned int V_4 )
{
unsigned int V_13 ;
F_3 ( V_2 , V_3 , V_31 , & V_13 ) ;
V_13 &= V_32 ;
V_4 &= ( V_13 & V_117 ) ? 0x55 : 0xFF ;
V_13 |= ( V_4 << V_96 ) ;
F_6 ( V_2 , V_3 , V_31 , V_13 ) ;
}
static int F_34 ( struct V_1 * V_2 )
{
unsigned char V_3 ;
unsigned int V_4 = V_85 ;
int V_23 = V_24 ;
unsigned int V_66 = 0 ;
unsigned short V_118 ;
unsigned int V_119 = 0 ;
int V_120 = 0 ;
for ( V_3 = 0 ; V_3 < V_2 -> V_60 -> V_69 ; V_3 ++ ) {
if ( ! ( V_2 -> V_60 -> V_61 & ( 1 << V_3 ) ) )
continue;
for ( V_118 = 0 ; V_118 < V_121 ; V_118 ++ ) {
F_35 ( V_2 , V_3 , 0 , V_122 ,
V_118 , 0 ) ;
F_35 ( V_2 , V_3 , 0 , V_123 ,
V_118 , 0 ) ;
}
F_3 ( V_2 , V_3 , V_124 , & V_66 ) ;
V_66 &= ~ ( 1 << V_125 ) ;
F_6 ( V_2 , V_3 , V_124 , V_66 ) ;
F_3 ( V_2 , V_3 , V_31 , & V_66 ) ;
V_66 &= V_32 ;
V_66 |= V_126 ;
F_6 ( V_2 , V_3 , V_31 , V_66 ) ;
F_32 ( V_2 , V_3 , 0 , F_36 ( V_127 ) ,
( T_2 * ) V_127 ) ;
F_19 ( V_2 , V_3 , V_4 , V_86 ,
V_2 -> V_60 -> V_87 &
V_88 ) ;
F_3 ( V_2 , V_3 , V_27 , & V_119 ) ;
F_6 ( V_2 , V_3 , V_27 , 0 ) ;
F_22 ( V_2 , V_3 , V_4 , V_128 ) ;
F_19 ( V_2 , V_3 , V_4 ,
V_68 , 0 ) ;
F_6 ( V_2 , V_3 , V_129 , 0 ) ;
F_33 ( V_2 , V_3 , V_4 ) ;
}
for ( V_3 = 0 ; V_3 < V_2 -> V_60 -> V_69 ; V_3 ++ ) {
if ( ! ( V_2 -> V_60 -> V_61 & ( 1 << V_3 ) ) )
continue;
do {
V_120 = F_9 ( V_2 , V_3 , 20 , 1 ) ;
} while ( V_120 && V_23 -- );
if ( ! V_23 ) {
F_5 ( L_9 , V_3 ) ;
return - V_30 ;
}
F_29 ( V_2 , V_3 , V_4 ) ;
F_6 ( V_2 , V_3 , V_27 ,
V_119 & V_130 ) ;
F_6 ( V_2 , V_3 , V_31 ,
V_84 ) ;
F_19 ( V_2 , V_3 , V_4 , V_86 ,
V_2 -> V_60 -> V_87 &
V_88 ) ;
F_6 ( V_2 , V_3 , V_89 , V_90 ) ;
F_6 ( V_2 , V_3 , V_91 , V_92 ) ;
F_22 ( V_2 , V_3 , V_4 ,
V_93 ) ;
F_21 ( V_2 , V_3 , V_4 ,
V_94 ) ;
}
return 0 ;
}
int F_37 ( struct V_131 * V_132 )
{
unsigned char V_3 ;
unsigned int V_133 = 0 ;
struct V_1 * V_2 ;
struct V_134 * V_135 = & V_132 -> V_136 ;
struct V_137 * V_138 = V_132 -> V_139 ;
struct V_140 * V_141 =
& V_135 -> V_142 [ V_138 -> V_143 ( V_138 ) ] ;
struct V_140 * V_144 =
& V_135 -> V_142 [ V_138 -> V_145 ( V_138 ) ] ;
V_2 = F_38 ( sizeof( * V_2 ) , V_146 ) ;
if ( ! V_2 )
return - V_147 ;
V_2 -> V_148 = V_141 -> V_149 +
V_150 ;
V_2 -> V_151 = V_141 -> V_149 +
V_152 ;
V_2 -> V_76 = V_141 -> V_149 +
V_153 ;
V_2 -> V_154 =
V_2 -> V_151 + V_155 ;
V_2 -> V_156 = V_144 -> V_149 ;
V_2 -> V_60 = F_38 ( sizeof( * V_2 -> V_60 ) , V_146 ) ;
if ( ! V_2 -> V_60 )
goto V_157;
V_2 -> V_60 -> V_158 = V_132 -> V_136 . V_159 ;
V_2 -> V_60 -> V_61 = V_138 -> V_61 ;
V_2 -> V_60 -> V_63 = V_138 -> V_160 ;
V_2 -> V_60 -> V_87 = 0x1ffff ;
V_2 -> V_60 -> V_161 = 0x4000 ;
for ( V_3 = 0 ; V_3 < V_162 ; V_3 ++ ) {
if ( ! ( V_138 -> V_61 & ( 1 << V_3 ) ) )
continue;
V_2 -> V_60 -> V_163 [ V_3 ] . V_164 = 0 ;
V_2 -> V_60 -> V_163 [ V_3 ] . V_165 =
V_2 -> V_60 -> V_161 ;
V_2 -> V_60 -> V_163 [ V_3 ] . V_166 =
V_2 -> V_60 -> V_161 ;
V_2 -> V_60 -> V_163 [ V_3 ] . V_5 =
V_85 ;
V_133 = V_3 ;
}
V_2 -> V_60 -> V_69 = V_133 + 1 ;
if ( F_28 ( V_2 ) ) {
F_39 ( & F_40 ( V_132 ) , L_10 ) ;
goto V_82;
}
if ( F_34 ( V_2 ) )
goto V_82;
for ( V_3 = 0 ; V_3 < V_2 -> V_60 -> V_69 ; V_3 ++ ) {
unsigned int V_66 = 0 ;
if ( ! ( V_138 -> V_61 & ( 1 << V_3 ) ) )
continue;
F_3 ( V_2 , V_3 , V_167 , & V_66 ) ;
V_66 |= 0x1 ;
F_6 ( V_2 , V_3 , V_167 , V_66 ) ;
}
V_132 -> V_168 -> V_168 = V_2 ;
return 0 ;
V_82:
F_41 ( V_2 -> V_60 ) ;
V_157:
F_41 ( V_2 ) ;
return - V_12 ;
}
void F_42 ( struct V_1 * V_2 )
{
if ( ! V_2 )
return;
F_41 ( V_2 -> V_60 ) ;
F_41 ( V_2 ) ;
}
void F_43 ( struct V_1 * V_2 , unsigned char V_3 ,
unsigned int V_4 )
{
F_22 ( V_2 , V_3 , ( ~ V_4 ) &
V_85 , 0x10000 ) ;
F_33 ( V_2 , V_3 , V_4 ) ;
}
void F_44 ( struct V_1 * V_2 , unsigned char V_3 ,
unsigned int V_4 )
{
F_29 ( V_2 , V_3 , V_4 ) ;
}
void F_45 ( struct V_1 * V_2 ,
unsigned char V_3 , unsigned int V_4 , unsigned int V_169 )
{
F_19 ( V_2 , V_3 , V_4 , V_86 ,
V_2 -> V_60 -> V_87 & V_169 ) ;
}
static void F_46 ( struct V_1 * V_2 ,
unsigned char V_3 , unsigned int V_106 ,
unsigned int V_107 , T_2 * V_98 )
{
unsigned int V_109 , V_112 , V_113 ;
unsigned int V_108 , V_170 ;
F_3 ( V_2 , V_3 , V_124 , & V_170 ) ;
F_6 ( V_2 , V_3 , V_124 ,
V_170 & 0xfffffffb ) ;
F_3 ( V_2 , V_3 , V_110 , & V_108 ) ;
V_106 |= V_111 ;
for ( V_109 = 0 ; V_109 < V_107 ; V_109 ++ ) {
F_6 ( V_2 , V_3 , V_110 , V_106 ) ;
V_106 ++ ;
F_3 ( V_2 , V_3 , V_115 , & V_112 ) ;
F_3 ( V_2 , V_3 , V_116 , & V_113 ) ;
V_98 [ V_109 ] = V_113 ;
V_98 [ V_109 ] = ( V_98 [ V_109 ] << 0x20 ) | V_112 ;
}
F_6 ( V_2 , V_3 , V_124 , V_170 ) ;
F_6 ( V_2 , V_3 , V_110 , V_108 ) ;
}
void F_47 ( struct V_1 * V_2 ,
unsigned char V_3 , unsigned int V_106 ,
unsigned int V_107 , unsigned int * V_171 )
{
unsigned int V_109 , V_108 ;
F_3 ( V_2 , V_3 , V_110 , & V_108 ) ;
V_106 |= V_111 ;
F_6 ( V_2 , V_3 , V_110 , V_106 ) ;
for ( V_109 = 0 ; V_109 < V_107 ; V_109 ++ ) {
unsigned int V_112 , V_113 , V_114 ;
V_112 = ( ( V_171 [ V_109 ] & 0xfff0000 ) << 4 ) | ( 0x3 << 18 ) |
( ( V_171 [ V_109 ] & 0xff00 ) << 2 ) |
( 0x3 << 8 ) | ( V_171 [ V_109 ] & 0xff ) ;
V_113 = ( 0xf << 4 ) | ( ( V_171 [ V_109 ] & 0xf0000000 ) >> 28 ) ;
V_113 |= ( F_48 ( V_171 [ V_109 ] & 0xffff ) & 0x1 ) << 8 ;
V_114 = ( ( V_171 [ V_109 ] >> 0x10 ) & 0xffff ) ;
V_113 |= ( F_48 ( V_114 ) & 0x1 ) << 9 ;
F_6 ( V_2 , V_3 , V_115 , V_112 ) ;
F_6 ( V_2 , V_3 , V_116 , V_113 ) ;
}
F_6 ( V_2 , V_3 , V_110 , V_108 ) ;
}
static int F_49 ( struct V_1 * V_2 ,
unsigned char V_3 , unsigned char V_13 ,
T_2 * V_172 , unsigned int V_173 ,
int V_174 , unsigned int V_175 ,
unsigned int * V_176 )
{
T_2 V_177 [ V_178 ] ;
unsigned int V_179 , V_180 ;
unsigned int V_181 , V_182 ;
unsigned int V_183 ;
unsigned int V_184 , V_185 ;
unsigned int V_66 = 0 , V_186 ;
unsigned int V_119 ;
unsigned int V_187 , V_188 , V_189 ;
unsigned int V_190 , V_191 ;
if ( ( V_173 > V_2 -> V_60 -> V_161 ) || ! V_172 ) {
F_5 ( L_11 , V_173 ) ;
return - V_30 ;
}
F_20 ( V_2 , V_3 , V_13 , V_192 , & V_179 ) ;
F_20 ( V_2 , V_3 , V_13 , V_193 , & V_180 ) ;
F_20 ( V_2 , V_3 , V_13 , V_194 ,
& V_181 ) ;
F_20 ( V_2 , V_3 , V_13 , V_195 ,
& V_182 ) ;
if ( V_173 <= V_178 )
F_46 ( V_2 , V_3 , 0 , V_173 , V_177 ) ;
F_8 ( V_2 , V_3 , V_13 , & V_188 ) ;
F_20 ( V_2 , V_3 , V_13 , V_86 , & V_189 ) ;
V_189 = ( V_189 & V_2 -> V_60 -> V_87 ) >> 0 ;
F_3 ( V_2 , V_3 , V_31 , & V_191 ) ;
V_191 &= V_32 ;
F_3 ( V_2 , V_3 , V_91 , & V_187 ) ;
F_3 ( V_2 , V_3 , V_27 , & V_119 ) ;
F_3 ( V_2 , V_3 , V_89 , & V_190 ) ;
F_20 ( V_2 , V_3 , V_13 , V_196 ,
& V_183 ) ;
F_20 ( V_2 , V_3 , V_13 , V_68 , & V_184 ) ;
F_3 ( V_2 , V_3 , V_129 , & V_185 ) ;
F_6 ( V_2 , V_3 , V_31 , V_191 ) ;
F_32 ( V_2 , V_3 , 0 , V_173 , V_172 ) ;
F_19 ( V_2 , V_3 , ( 1 << V_13 ) , V_86 , 0 ) ;
F_6 ( V_2 , V_3 , V_27 , V_13 & V_130 ) ;
if ( V_174 )
F_6 ( V_2 , V_3 , V_91 , V_187 & 0xffffdfff ) ;
F_22 ( V_2 , V_3 , ( 1 << V_13 ) , V_128 ) ;
F_19 ( V_2 , V_3 , ( 1 << V_13 ) , V_68 , 0 ) ;
F_6 ( V_2 , V_3 , V_129 , 0 ) ;
F_33 ( V_2 , V_3 , ( 1 << V_13 ) ) ;
if ( F_9 ( V_2 , V_3 , V_175 , 1 ) != 0 )
return - V_12 ;
if ( V_176 ) {
unsigned int V_197 ;
F_20 ( V_2 , V_3 , V_13 , V_86 ,
& V_197 ) ;
* V_176 = V_197 & V_2 -> V_60 -> V_87 ;
}
F_29 ( V_2 , V_3 , ( 1 << V_13 ) ) ;
if ( V_173 <= V_178 )
F_32 ( V_2 , V_3 , 0 , V_173 , V_177 ) ;
F_22 ( V_2 , V_3 , ( 1 << V_13 ) , V_188 ) ;
F_19 ( V_2 , V_3 , ( 1 << V_13 ) , V_86 ,
V_2 -> V_60 -> V_87 & V_189 ) ;
F_3 ( V_2 , V_3 , V_124 , & V_66 ) ;
V_186 = F_12 ( V_66 , V_125 ) ;
F_6 ( V_2 , V_3 , V_124 , V_186 ) ;
F_6 ( V_2 , V_3 , V_91 , V_187 ) ;
F_6 ( V_2 , V_3 , V_27 , V_119 & V_130 ) ;
F_6 ( V_2 , V_3 , V_89 , V_190 ) ;
F_19 ( V_2 , V_3 , ( 1 << V_13 ) ,
V_192 , V_179 ) ;
F_19 ( V_2 , V_3 , ( 1 << V_13 ) ,
V_193 , V_180 ) ;
F_19 ( V_2 , V_3 , ( 1 << V_13 ) ,
V_194 , V_181 ) ;
F_19 ( V_2 , V_3 , ( 1 << V_13 ) ,
V_195 , V_182 ) ;
F_19 ( V_2 , V_3 , ( 1 << V_13 ) ,
V_196 , V_183 ) ;
F_19 ( V_2 , V_3 , ( 1 << V_13 ) ,
V_68 , V_184 ) ;
F_6 ( V_2 , V_3 , V_129 , V_185 ) ;
F_6 ( V_2 , V_3 , V_31 , V_191 ) ;
return 0 ;
}
static int F_50 ( struct V_1 * V_2 ,
unsigned char V_3 , unsigned char V_13 ,
enum V_35 V_198 ,
unsigned short V_41 , unsigned int * V_171 )
{
unsigned int V_119 , V_106 , V_112 , V_113 ;
unsigned int V_199 , V_108 , V_191 ;
unsigned short V_42 ;
int V_200 = 0 ;
T_2 V_201 , V_202 ;
V_42 = F_15 ( V_198 , V_41 ) ;
if ( V_42 == V_57 ) {
F_5 ( L_12 , V_42 ) ;
return - V_30 ;
}
switch ( V_198 ) {
case V_45 :
V_201 = 0xA070000000ull | ( V_42 & 0x3ff ) ;
break;
default:
V_201 = ( T_2 ) 0xA030000000ull | ( ( V_42 & 0x3ff ) << 10 ) ;
break;
}
F_3 ( V_2 , V_3 , V_27 , & V_119 ) ;
F_3 ( V_2 , V_3 , V_89 , & V_199 ) ;
F_3 ( V_2 , V_3 , V_31 , & V_191 ) ;
V_191 &= V_32 ;
if ( V_13 != ( V_119 & V_130 ) )
F_6 ( V_2 , V_3 , V_27 ,
V_13 & V_130 ) ;
F_46 ( V_2 , V_3 , 0 , 1 , & V_202 ) ;
F_6 ( V_2 , V_3 , V_31 , V_191 ) ;
F_3 ( V_2 , V_3 , V_110 , & V_108 ) ;
V_106 = V_111 ;
F_6 ( V_2 , V_3 , V_110 , V_106 ) ;
V_201 = F_31 ( V_201 ) ;
V_112 = ( unsigned int ) ( V_201 & 0xffffffff ) ;
V_113 = ( unsigned int ) ( V_201 >> 0x20 ) ;
F_6 ( V_2 , V_3 , V_115 , V_112 ) ;
F_6 ( V_2 , V_3 , V_116 , V_113 ) ;
F_6 ( V_2 , V_3 , V_110 , V_106 ) ;
F_9 ( V_2 , V_3 , 0x8 , 0 ) ;
F_3 ( V_2 , V_3 , V_203 , V_171 ) ;
F_6 ( V_2 , V_3 , V_110 , V_108 ) ;
F_32 ( V_2 , V_3 , 0 , 1 , & V_202 ) ;
if ( V_13 != ( V_119 & V_130 ) )
F_6 ( V_2 , V_3 , V_27 ,
V_119 & V_130 ) ;
F_6 ( V_2 , V_3 , V_89 , V_199 ) ;
F_6 ( V_2 , V_3 , V_31 , V_191 ) ;
return V_200 ;
}
static int F_51 ( struct V_1 * V_2 ,
unsigned char V_3 , unsigned char V_13 ,
enum V_35 V_198 ,
unsigned short V_41 , unsigned int V_171 )
{
unsigned short V_204 , V_205 , V_206 , V_207 , V_208 ;
T_2 V_201 [] = {
0x0F440000000ull ,
0x0F040000000ull ,
0x0F0000C0300ull ,
0x0E000010000ull
} ;
const int V_209 = F_36 ( V_201 ) , V_174 = 1 ;
const int V_210 = 0 , V_211 = 1 ;
V_206 = F_15 ( V_198 , V_41 ) ;
if ( V_206 == V_57 ) {
F_5 ( L_13 , V_206 ) ;
return - V_30 ;
}
V_208 = 0xffff & V_171 ;
V_207 = 0xffff & ( V_171 >> 0x10 ) ;
V_204 = F_15 ( V_56 , ( unsigned short )
( 0xff & V_207 ) ) ;
V_205 = F_15 ( V_56 , ( unsigned short )
( 0xff & V_208 ) ) ;
switch ( V_198 ) {
case V_45 :
V_201 [ V_210 ] = V_201 [ V_210 ] | ( ( V_207 >> 8 ) << 20 ) |
( ( V_204 & 0x3ff ) << 10 ) | ( V_206 & 0x3ff ) ;
V_201 [ V_211 ] = V_201 [ V_211 ] | ( ( V_208 >> 8 ) << 20 ) |
( ( V_205 & 0x3ff ) << 10 ) | ( V_206 & 0x3ff ) ;
break;
default:
V_201 [ V_210 ] = V_201 [ V_210 ] | ( ( V_207 >> 8 ) << 20 ) |
( ( V_206 & 0x3ff ) << 10 ) | ( V_204 & 0x3ff ) ;
V_201 [ V_211 ] = V_201 [ V_211 ] | ( ( V_208 >> 8 ) << 20 ) |
( ( V_206 & 0x3ff ) << 10 ) | ( V_205 & 0x3ff ) ;
break;
}
return F_49 ( V_2 , V_3 , V_13 , V_201 , V_209 ,
V_174 , V_209 * 0x5 , NULL ) ;
}
int F_52 ( void )
{
return F_36 ( V_212 ) ;
}
static int F_53 ( T_2 * V_172 ,
unsigned int V_173 , unsigned int V_213 ,
unsigned int V_214 , unsigned int * V_7 )
{
int V_109 , V_215 ;
unsigned int V_216 ;
const T_2 * V_217 ;
int V_218 ;
int V_219 = 0 ;
int V_220 ;
V_220 = V_173 ;
V_215 = 0 ;
V_216 = V_7 [ V_215 ++ ] ;
V_217 = V_212 ;
V_219 = F_36 ( V_212 ) ;
V_218 = V_173 ;
for ( V_109 = 0 ; V_109 < V_219 ; V_109 ++ )
V_172 [ V_173 ++ ] = V_217 [ V_109 ] ;
F_54 ( V_172 [ V_218 ] , ( V_214 ) ) ;
V_218 ++ ;
F_54 ( V_172 [ V_218 ] , 0 ) ;
V_218 ++ ;
F_55 ( V_172 [ V_218 ] , ( V_216 >> 0 ) ) ;
V_218 ++ ;
F_55 ( V_172 [ V_218 ] , ( V_216 >> 0x10 ) ) ;
return V_173 - V_220 ;
}
static int F_56 ( struct V_1 * V_2 ,
unsigned char V_3 , unsigned char V_13 ,
int * V_221 , T_2 * V_172 ,
unsigned int V_173 )
{
int V_222 = 0 ;
unsigned int V_223 = 0 , V_224 = 0 , V_225 = 0 ;
unsigned int V_226 = 0 , V_227 = 0 ;
if ( * V_221 ) {
F_50 ( V_2 , V_3 , V_13 , V_45 , 0 , & V_223 ) ;
F_50 ( V_2 , V_3 , V_13 , V_45 , 0x1 , & V_224 ) ;
F_50 ( V_2 , V_3 , V_13 , V_45 , 0x2 , & V_225 ) ;
F_50 ( V_2 , V_3 , V_13 , V_46 , 0 , & V_226 ) ;
F_50 ( V_2 , V_3 , V_13 , V_46 , 0x1 , & V_227 ) ;
* V_221 = 0 ;
}
V_222 = F_49 ( V_2 , V_3 , V_13 , V_172 , V_173 , 1 ,
V_173 * 0x5 , NULL ) ;
if ( V_222 != 0 )
return - V_12 ;
F_51 ( V_2 , V_3 , V_13 , V_45 , 0 , V_223 ) ;
F_51 ( V_2 , V_3 , V_13 , V_45 , 0x1 , V_224 ) ;
F_51 ( V_2 , V_3 , V_13 , V_45 , 0x2 , V_225 ) ;
F_51 ( V_2 , V_3 , V_13 , V_46 , 0 , V_226 ) ;
F_51 ( V_2 , V_3 , V_13 , V_46 , 0x1 , V_227 ) ;
return 0 ;
}
int F_57 ( struct V_1 * V_2 ,
unsigned char V_3 ,
struct V_228 * V_229 )
{
struct V_228 * V_230 ;
T_2 * V_231 ;
int V_232 ;
int V_233 ;
int V_234 = 1 ;
int V_222 = 0 ;
V_230 = V_229 -> V_235 ;
V_233 = V_229 -> V_213 ;
if ( ( unsigned int ) V_233 > V_2 -> V_60 -> V_161 )
V_233 = V_2 -> V_60 -> V_161 ;
V_231 = F_58 ( V_233 , sizeof( T_2 ) ,
V_146 ) ;
if ( ! V_231 )
return - V_147 ;
V_232 = 0 ;
while ( V_230 ) {
unsigned int V_214 , * V_7 , V_213 ;
V_3 = V_230 -> V_3 ;
V_214 = V_230 -> V_214 ;
V_7 = V_230 -> V_7 ;
V_213 = V_230 -> V_213 ;
V_232 += F_53 ( V_231 ,
V_232 ,
V_213 , V_214 , V_7 ) ;
V_230 = V_230 -> V_235 ;
}
if ( V_231 && ( V_232 > 0 ) ) {
V_231 [ V_232 ++ ] = 0x0E000010000ull ;
V_222 = F_56 ( V_2 , V_3 , 0 , & V_234 ,
V_231 ,
V_232 ) ;
}
F_41 ( V_231 ) ;
return V_222 ;
}
static int F_59 ( struct V_1 * V_2 ,
unsigned char V_3 , unsigned char V_13 ,
enum V_35 V_198 ,
unsigned short V_41 , unsigned int V_236 )
{
int V_200 = 0 ;
unsigned int V_42 ;
unsigned int V_191 ;
unsigned short V_237 ;
unsigned short V_238 = 0x10 ;
V_200 = F_3 ( V_2 , V_3 , V_31 , & V_191 ) ;
if ( V_117 & V_191 ) {
if ( V_13 & 0x1 ) {
F_5 ( L_14 , V_13 ) ;
return - V_30 ;
}
V_237 = 0x1f ;
V_238 = 0x20 ;
} else {
V_237 = 0x0f ;
}
if ( V_41 & ~ V_237 )
return - V_30 ;
V_42 = V_41 + ( V_13 << 0x5 ) ;
switch ( V_198 ) {
case V_47 :
case V_49 :
F_60 ( V_2 , V_3 , V_42 , V_236 ) ;
break;
case V_51 :
case V_53 :
F_60 ( V_2 , V_3 , ( V_42 + V_238 ) , V_236 ) ;
break;
default:
V_200 = - V_30 ;
break;
}
return V_200 ;
}
static int F_61 ( struct V_1 * V_2 ,
unsigned char V_3 , unsigned char V_13 ,
enum V_35 V_198 ,
unsigned short V_41 , unsigned int V_171 )
{
unsigned int V_239 , V_191 ;
unsigned short V_204 , V_205 , V_240 , V_241 , V_207 ,
V_242 ;
unsigned short V_243 ;
int V_200 = 0 ;
T_2 V_172 [] = {
0x0F440000000ull ,
0x0F040000000ull ,
0x0A000000000ull ,
0x0F0000C0300ull ,
0x0E000010000ull
} ;
const int V_209 = F_36 ( V_172 ) , V_174 = 1 ;
const unsigned short V_244 = 0 , V_245 = V_209 * 0x5 ;
F_3 ( V_2 , V_3 , V_31 , & V_191 ) ;
if ( V_117 & V_191 ) {
if ( V_13 & 0x1 ) {
F_5 ( L_15 , V_13 ) ;
return - V_30 ;
}
V_243 = ( unsigned short ) ~ 0x1f ;
} else {
V_243 = ( unsigned short ) ~ 0xf ;
}
if ( V_41 & V_243 )
return - V_30 ;
V_241 = F_15 ( V_198 , V_41 ) ;
if ( V_241 == V_57 ) {
F_5 ( L_16 , V_241 ) ;
return - V_30 ;
}
F_50 ( V_2 , V_3 , V_13 , V_46 , V_244 , & V_239 ) ;
V_240 = F_15 ( V_46 , V_244 ) ;
V_242 = 0xffff & V_171 ;
V_207 = 0xffff & ( V_171 >> 0x10 ) ;
V_204 = F_15 ( V_56 ,
( unsigned short ) ( 0xff & V_207 ) ) ;
V_205 = F_15 ( V_56 ,
( unsigned short ) ( 0xff & V_242 ) ) ;
V_172 [ 0 ] = V_172 [ 0x0 ] | ( ( V_207 >> 8 ) << 20 ) |
( ( V_240 & 0x3ff ) << 10 ) | ( V_204 & 0x3ff ) ;
V_172 [ 1 ] = V_172 [ 0x1 ] | ( ( V_242 >> 8 ) << 20 ) |
( ( V_240 & 0x3ff ) << 10 ) | ( V_205 & 0x3ff ) ;
V_172 [ 0x2 ] = V_172 [ 0x2 ] |
( ( V_241 & 0x3ff ) << 20 ) | ( ( V_240 & 0x3ff ) << 10 ) ;
V_200 = F_49 ( V_2 , V_3 , V_13 , V_172 , V_209 ,
V_174 , V_245 , NULL ) ;
F_51 ( V_2 , V_3 , V_13 , V_46 , V_244 , V_239 ) ;
return V_200 ;
}
static int F_62 ( struct V_1 * V_2 ,
unsigned char V_3 , unsigned char V_13 ,
unsigned short V_246 , unsigned int V_236 )
{
unsigned int V_191 ;
int V_222 = 0 ;
F_3 ( V_2 , V_3 , V_31 , & V_191 ) ;
V_191 &= V_32 ;
F_6 ( V_2 , V_3 , V_31 , V_191 | V_126 ) ;
V_222 = F_61 ( V_2 , V_3 , V_13 , V_55 , V_246 , V_236 ) ;
F_6 ( V_2 , V_3 , V_31 , V_191 ) ;
return V_222 ;
}
static int F_63 ( struct V_1
* V_2 , unsigned char V_3 ,
unsigned short V_247 ,
unsigned short * V_248 ,
unsigned char * V_13 )
{
unsigned int V_191 ;
F_3 ( V_2 , V_3 , V_31 , & V_191 ) ;
if ( V_191 & V_117 ) {
* V_248 = V_247 & 0x1F ;
* V_13 = ( V_247 >> 0x4 ) & 0x6 ;
} else {
* V_248 = V_247 & 0x0F ;
* V_13 = ( V_247 >> 0x4 ) & 0x7 ;
}
return 0 ;
}
int F_64 ( struct V_1 * V_2 ,
unsigned char V_3 , unsigned char V_4 ,
enum V_35 V_198 ,
unsigned short V_41 , unsigned int V_249 )
{
int V_222 = 0 ;
unsigned short V_118 ;
unsigned char V_13 = 0 ;
enum V_35 type ;
if ( V_41 >= V_121 )
return - V_30 ;
do {
if ( V_4 == 0 ) {
F_63 ( V_2 , V_3 , V_41 , & V_118 ,
& V_13 ) ;
type = V_198 - 1 ;
} else {
V_118 = V_41 ;
type = V_198 ;
if ( ! F_65 ( V_13 , ( unsigned long * ) & V_4 ) )
continue;
}
V_222 = F_51 ( V_2 , V_3 , V_13 , type , V_118 , V_249 ) ;
if ( V_222 ) {
F_5 ( L_17 ) ;
return - V_30 ;
}
} while ( V_4 && ( V_13 ++ < V_67 ) );
return 0 ;
}
int F_66 ( struct V_1 * V_2 ,
unsigned char V_3 , unsigned char V_4 ,
enum V_35 V_198 ,
unsigned short V_41 , unsigned int V_249 )
{
int V_222 = 0 ;
unsigned short V_118 ;
unsigned char V_13 = 0 ;
enum V_35 type ;
if ( V_41 >= V_250 )
return - V_30 ;
do {
if ( V_4 == 0 ) {
F_63 ( V_2 , V_3 , V_41 , & V_118 ,
& V_13 ) ;
type = V_198 - 3 ;
} else {
V_118 = V_41 ;
type = V_198 ;
if ( ! F_65 ( V_13 , ( unsigned long * ) & V_4 ) )
continue;
}
V_222 = F_61 ( V_2 , V_3 , V_13 , type , V_118 ,
V_249 ) ;
if ( V_222 ) {
F_5 ( L_18 ) ;
return - V_30 ;
}
} while ( V_4 && ( V_13 ++ < V_67 ) );
return 0 ;
}
int F_35 ( struct V_1 * V_2 ,
unsigned char V_3 , unsigned char V_4 ,
enum V_35 V_198 ,
unsigned short V_41 , unsigned int V_249 )
{
int V_222 = 0 ;
unsigned short V_118 ;
unsigned char V_13 = 0 ;
enum V_35 type ;
if ( V_41 >= V_250 )
return - V_30 ;
do {
if ( V_4 == 0 ) {
F_63 ( V_2 , V_3 , V_41 , & V_118 ,
& V_13 ) ;
type = V_198 - 3 ;
} else {
V_118 = V_41 ;
type = V_198 ;
if ( ! F_65 ( V_13 , ( unsigned long * ) & V_4 ) )
continue;
}
V_222 = F_59 ( V_2 , V_3 , V_13 , type , V_118 ,
V_249 ) ;
if ( V_222 ) {
F_5 ( L_19 ) ;
return - V_30 ;
}
} while ( V_4 && ( V_13 ++ < V_67 ) );
return 0 ;
}
int F_67 ( struct V_1 * V_2 ,
unsigned char V_3 , unsigned char V_4 ,
unsigned short V_41 , unsigned int V_249 )
{
int V_222 = 0 ;
unsigned char V_13 ;
if ( V_4 == 0 )
return - V_30 ;
for ( V_13 = 0 ; V_13 < V_67 ; V_13 ++ ) {
if ( ! F_65 ( V_13 , ( unsigned long * ) & V_4 ) )
continue;
V_222 = F_62 ( V_2 , V_3 , V_13 , V_41 , V_249 ) ;
if ( V_222 ) {
F_5 ( L_20 ) ;
return - V_30 ;
}
}
return 0 ;
}
