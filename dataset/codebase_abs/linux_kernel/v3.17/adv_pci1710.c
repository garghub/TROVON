static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
unsigned int V_5 ,
unsigned int V_6 )
{
const struct V_7 * V_8 = F_2 ( V_2 ) ;
struct V_9 * V_10 = V_2 -> V_11 ;
if ( V_8 -> V_12 != V_13 ) {
if ( ( V_6 & 0xf000 ) != V_10 -> V_14 [ V_5 ] ) {
F_3 ( V_2 -> V_15 ,
L_1 ,
( V_6 >> 12 ) & 0xf ,
( V_10 -> V_14 [ V_5 ] >> 12 ) & 0xf ) ;
return - V_16 ;
}
}
return 0 ;
}
static int F_4 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_17 * V_18 )
{
struct V_9 * V_10 = V_2 -> V_11 ;
unsigned int V_19 = F_5 ( V_18 -> V_20 [ 0 ] ) ;
unsigned int V_21 = F_6 ( V_18 -> V_20 [ 0 ] ) ;
unsigned int V_22 = ( V_19 + 1 ) % V_4 -> V_23 ;
unsigned int V_24 [ 32 ] ;
unsigned int V_25 ;
int V_26 ;
if ( V_18 -> V_27 == 1 ) {
V_10 -> V_28 = V_18 -> V_27 ;
return 0 ;
}
V_24 [ 0 ] = V_18 -> V_20 [ 0 ] ;
for ( V_26 = 1 ; V_26 < V_18 -> V_27 ; V_26 ++ ) {
unsigned int V_5 = F_5 ( V_18 -> V_20 [ V_26 ] ) ;
unsigned int V_29 = F_6 ( V_18 -> V_20 [ V_26 ] ) ;
if ( V_18 -> V_20 [ 0 ] == V_18 -> V_20 [ V_26 ] )
break;
if ( V_29 == V_30 && ( V_5 & 1 ) ) {
F_3 ( V_2 -> V_15 ,
L_2 ) ;
return - V_31 ;
}
if ( V_21 == V_30 )
V_22 = ( V_22 + 1 ) % V_4 -> V_23 ;
if ( V_5 != V_22 ) {
F_3 ( V_2 -> V_15 ,
L_3 ,
V_26 , V_5 , V_22 , V_19 ) ;
return - V_31 ;
}
V_24 [ V_26 ] = V_18 -> V_20 [ V_26 ] ;
V_21 = V_29 ;
}
V_25 = V_26 ;
for ( V_26 = 0 ; V_26 < V_18 -> V_27 ; V_26 ++ ) {
if ( V_18 -> V_20 [ V_26 ] != V_24 [ V_26 % V_25 ] ) {
F_3 ( V_2 -> V_15 ,
L_4 ,
V_26 , F_5 ( V_24 [ V_26 ] ) ,
F_7 ( V_24 [ V_26 ] ) ,
F_6 ( V_24 [ V_26 ] ) ,
F_5 ( V_18 -> V_20 [ V_26 % V_25 ] ) ,
F_7 ( V_18 -> V_20 [ V_26 % V_25 ] ) ,
F_6 ( V_24 [ V_26 % V_25 ] ) ) ;
return - V_31 ;
}
}
V_10 -> V_28 = V_25 ;
return 0 ;
}
static void F_8 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
unsigned int * V_20 , unsigned int V_23 ,
unsigned int V_25 )
{
const struct V_7 * V_32 = F_2 ( V_2 ) ;
struct V_9 * V_10 = V_2 -> V_11 ;
unsigned int V_26 , V_33 , V_34 ;
for ( V_26 = 0 ; V_26 < V_25 ; V_26 ++ ) {
V_34 = V_35 [ F_5 ( V_20 [ V_26 ] ) ] ;
F_9 ( V_34 , V_2 -> V_36 + V_37 ) ;
V_33 = V_32 -> V_38 [ F_7 ( V_20 [ V_26 ] ) ] ;
if ( F_6 ( V_20 [ V_26 ] ) == V_30 )
V_33 |= 0x0020 ;
F_9 ( V_33 , V_2 -> V_36 + V_39 ) ;
V_10 -> V_14 [ V_26 ] =
( F_5 ( V_20 [ V_26 ] ) << 12 ) & 0xf000 ;
}
for ( ; V_26 < V_23 ; V_26 ++ ) {
V_10 -> V_14 [ V_26 ] =
( F_5 ( V_20 [ V_26 ] ) << 12 ) & 0xf000 ;
}
V_10 -> V_40 =
F_5 ( V_20 [ 0 ] ) | ( F_5 ( V_20 [ V_25 - 1 ] ) << 8 ) ;
F_9 ( V_10 -> V_40 , V_2 -> V_36 + V_37 ) ;
}
static int F_10 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_41 * V_42 ,
unsigned long V_43 )
{
unsigned int V_44 ;
V_44 = F_11 ( V_2 -> V_36 + V_45 ) ;
if ( ( V_44 & V_46 ) == 0 )
return 0 ;
return - V_47 ;
}
static int F_12 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_41 * V_42 , unsigned int * V_48 )
{
struct V_9 * V_10 = V_2 -> V_11 ;
unsigned int V_5 = F_5 ( V_42 -> V_49 ) ;
int V_50 = 0 ;
int V_26 ;
V_10 -> V_51 &= V_52 ;
V_10 -> V_51 |= V_53 ;
F_9 ( V_10 -> V_51 , V_2 -> V_36 + V_54 ) ;
F_13 ( 0 , V_2 -> V_36 + V_55 ) ;
F_13 ( 0 , V_2 -> V_36 + V_56 ) ;
F_8 ( V_2 , V_4 , & V_42 -> V_49 , 1 , 1 ) ;
for ( V_26 = 0 ; V_26 < V_42 -> V_57 ; V_26 ++ ) {
unsigned int V_6 ;
F_9 ( 0 , V_2 -> V_36 + V_58 ) ;
V_50 = F_14 ( V_2 , V_4 , V_42 , F_10 , 0 ) ;
if ( V_50 )
break;
V_6 = F_11 ( V_2 -> V_36 + V_59 ) ;
V_50 = F_1 ( V_2 , V_4 , V_5 , V_6 ) ;
if ( V_50 )
break;
V_48 [ V_26 ] = V_6 & V_4 -> V_60 ;
}
F_13 ( 0 , V_2 -> V_36 + V_55 ) ;
F_13 ( 0 , V_2 -> V_36 + V_56 ) ;
return V_50 ? V_50 : V_42 -> V_57 ;
}
static int F_15 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_41 * V_42 , unsigned int * V_48 )
{
struct V_9 * V_10 = V_2 -> V_11 ;
unsigned int V_6 ;
int V_57 , V_5 , V_33 , V_61 ;
V_5 = F_5 ( V_42 -> V_49 ) ;
V_33 = F_7 ( V_42 -> V_49 ) ;
if ( V_5 ) {
V_10 -> V_62 &= 0xfb ;
V_10 -> V_62 |= ( V_33 << 2 ) ;
F_9 ( V_10 -> V_62 , V_2 -> V_36 + V_63 ) ;
V_61 = V_64 ;
} else {
V_10 -> V_62 &= 0xfe ;
V_10 -> V_62 |= V_33 ;
F_9 ( V_10 -> V_62 , V_2 -> V_36 + V_63 ) ;
V_61 = V_65 ;
}
V_6 = V_10 -> V_66 [ V_5 ] ;
for ( V_57 = 0 ; V_57 < V_42 -> V_57 ; V_57 ++ ) {
V_6 = V_48 [ V_57 ] ;
F_9 ( V_6 , V_2 -> V_36 + V_61 ) ;
}
V_10 -> V_66 [ V_5 ] = V_6 ;
return V_57 ;
}
static int F_16 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_41 * V_42 , unsigned int * V_48 )
{
struct V_9 * V_10 = V_2 -> V_11 ;
int V_57 , V_5 ;
V_5 = F_5 ( V_42 -> V_49 ) ;
for ( V_57 = 0 ; V_57 < V_42 -> V_57 ; V_57 ++ )
V_48 [ V_57 ] = V_10 -> V_66 [ V_5 ] ;
return V_57 ;
}
static int F_17 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_41 * V_42 , unsigned int * V_48 )
{
V_48 [ 1 ] = F_11 ( V_2 -> V_36 + V_67 ) ;
return V_42 -> V_57 ;
}
static int F_18 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_41 * V_42 ,
unsigned int * V_48 )
{
if ( F_19 ( V_4 , V_48 ) )
F_9 ( V_4 -> V_68 , V_2 -> V_36 + V_69 ) ;
V_48 [ 1 ] = V_4 -> V_68 ;
return V_42 -> V_57 ;
}
static void F_20 ( struct V_1 * V_2 ,
bool V_70 )
{
struct V_9 * V_10 = V_2 -> V_11 ;
unsigned long V_71 = V_2 -> V_36 + V_72 ;
F_21 ( V_71 , 1 , 2 , V_73 | V_74 ) ;
F_21 ( V_71 , 1 , 1 , V_73 | V_74 ) ;
if ( V_70 ) {
F_22 ( V_71 , 1 , 2 , V_10 -> V_75 ) ;
F_22 ( V_71 , 1 , 1 , V_10 -> V_76 ) ;
}
}
static int F_23 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_41 * V_42 ,
unsigned int * V_48 )
{
unsigned int V_77 , V_78 , V_79 ;
int V_26 ;
V_79 = 0xD2 ;
for ( V_26 = 0 ; V_26 < V_42 -> V_57 ; V_26 ++ ) {
F_9 ( V_79 , V_2 -> V_36 + V_80 ) ;
V_78 = F_11 ( V_2 -> V_36 + V_81 ) & 0xFF ;
V_77 = F_11 ( V_2 -> V_36 + V_81 ) & 0xFF ;
V_48 [ 0 ] = V_78 | ( V_77 << 8 ) ;
}
return V_42 -> V_57 ;
}
static int F_24 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_41 * V_42 ,
unsigned int * V_48 )
{
struct V_9 * V_10 = V_2 -> V_11 ;
T_1 V_77 , V_78 , V_79 , V_44 ;
V_78 = V_48 [ 0 ] & 0x00FF ;
V_77 = ( V_48 [ 0 ] & 0xFF00 ) >> 8 ;
F_9 ( V_78 , V_2 -> V_36 + V_81 ) ;
F_9 ( V_77 , V_2 -> V_36 + V_81 ) ;
if ( V_10 -> V_82 ) {
V_79 = 0xE2 ;
do {
F_9 ( V_79 , V_2 -> V_36 + V_80 ) ;
V_44 = F_11 ( V_2 -> V_36 + V_81 ) & 0xFF ;
} while ( V_44 & 0x40 );
}
return V_42 -> V_57 ;
}
static int F_25 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_41 * V_42 ,
unsigned int * V_48 )
{
#ifdef F_26
struct V_9 * V_10 = V_2 -> V_11 ;
T_1 V_79 = 0 ;
V_10 -> V_82 = V_48 [ 0 ] & 0x20 ;
if ( ! ( V_48 [ 0 ] & 0x10 ) ) {
V_10 -> V_51 &= ~ V_52 ;
} else {
V_10 -> V_51 |= V_52 ;
}
F_9 ( V_10 -> V_51 , V_2 -> V_36 + V_54 ) ;
if ( V_48 [ 0 ] & 0x01 )
V_79 |= V_83 ;
if ( V_48 [ 0 ] & 0x02 )
V_79 |= V_84 ;
if ( V_48 [ 0 ] & 0x04 )
V_79 |= V_85 ;
if ( V_48 [ 0 ] & 0x08 )
V_79 |= V_86 ;
V_79 |= V_87 ;
V_79 |= V_88 ;
F_9 ( V_79 , V_2 -> V_36 + V_80 ) ;
#endif
return 1 ;
}
static int F_27 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_41 * V_42 , unsigned int * V_48 )
{
struct V_9 * V_10 = V_2 -> V_11 ;
unsigned int V_6 ;
int V_57 , V_89 , V_5 ;
V_5 = F_5 ( V_42 -> V_49 ) ;
V_89 = V_10 -> V_62 & ( ~ ( 0x03 << ( V_5 << 1 ) ) ) ;
V_89 |= ( F_7 ( V_42 -> V_49 ) << ( V_5 << 1 ) ) ;
if ( V_89 != V_10 -> V_62 ) {
F_13 ( V_89 , V_2 -> V_36 + V_90 ) ;
V_10 -> V_62 = V_89 ;
}
V_6 = V_10 -> V_66 [ V_5 ] ;
for ( V_57 = 0 ; V_57 < V_42 -> V_57 ; V_57 ++ ) {
V_6 = V_48 [ V_57 ] ;
F_9 ( V_6 , V_2 -> V_36 + V_91 + ( V_5 << 1 ) ) ;
F_13 ( 0 , V_2 -> V_36 + V_92 ) ;
}
V_10 -> V_66 [ V_5 ] = V_6 ;
return V_57 ;
}
static int F_28 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
const struct V_7 * V_32 = F_2 ( V_2 ) ;
struct V_9 * V_10 = V_2 -> V_11 ;
switch ( V_32 -> V_12 ) {
default:
V_10 -> V_51 &= V_52 ;
V_10 -> V_51 |= V_53 ;
F_9 ( V_10 -> V_51 , V_2 -> V_36 + V_54 ) ;
F_20 ( V_2 , false ) ;
F_13 ( 0 , V_2 -> V_36 + V_55 ) ;
F_13 ( 0 , V_2 -> V_36 + V_56 ) ;
break;
}
V_10 -> V_93 = 0 ;
V_4 -> V_94 -> V_95 = 0 ;
return 0 ;
}
static void F_29 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_9 * V_10 = V_2 -> V_11 ;
struct V_17 * V_18 = & V_4 -> V_94 -> V_18 ;
unsigned int V_44 ;
unsigned int V_6 ;
int V_50 ;
V_44 = F_11 ( V_2 -> V_36 + V_45 ) ;
if ( V_44 & V_46 ) {
F_30 ( V_2 -> V_15 , L_5 , V_44 ) ;
V_4 -> V_94 -> V_96 |= V_97 | V_98 ;
F_31 ( V_2 , V_4 ) ;
return;
}
if ( V_44 & V_99 ) {
F_30 ( V_2 -> V_15 ,
L_6 , V_44 ) ;
V_4 -> V_94 -> V_96 |= V_97 | V_98 ;
F_31 ( V_2 , V_4 ) ;
return;
}
F_13 ( 0 , V_2 -> V_36 + V_56 ) ;
for (; ! ( F_11 ( V_2 -> V_36 + V_45 ) & V_46 ) ; ) {
V_6 = F_11 ( V_2 -> V_36 + V_59 ) ;
V_50 = F_1 ( V_2 , V_4 , V_4 -> V_94 -> V_95 , V_6 ) ;
if ( V_50 ) {
V_4 -> V_94 -> V_96 |= V_97 | V_98 ;
break;
}
F_32 ( V_4 , V_6 & V_4 -> V_60 ) ;
V_4 -> V_94 -> V_95 ++ ;
if ( V_4 -> V_94 -> V_95 >= V_18 -> V_27 )
V_4 -> V_94 -> V_95 = 0 ;
if ( V_4 -> V_94 -> V_95 == 0 ) {
V_10 -> V_93 ++ ;
if ( V_18 -> V_100 == V_101 &&
V_10 -> V_93 >= V_18 -> V_102 ) {
V_4 -> V_94 -> V_96 |= V_97 ;
break;
}
}
}
F_13 ( 0 , V_2 -> V_36 + V_56 ) ;
F_31 ( V_2 , V_4 ) ;
}
static int F_33 ( struct V_1 * V_2 ,
struct V_3 * V_4 , int V_57 , int V_103 )
{
struct V_9 * V_10 = V_2 -> V_11 ;
struct V_17 * V_18 = & V_4 -> V_94 -> V_18 ;
unsigned int V_6 ;
int V_50 ;
int V_26 ;
for ( V_26 = 0 ; V_26 < V_57 ; V_26 ++ ) {
V_6 = F_11 ( V_2 -> V_36 + V_59 ) ;
V_50 = F_1 ( V_2 , V_4 , V_4 -> V_94 -> V_95 , V_6 ) ;
if ( V_50 ) {
V_4 -> V_94 -> V_96 |= V_97 | V_98 ;
return V_50 ;
}
F_32 ( V_4 , V_6 & V_4 -> V_60 ) ;
V_4 -> V_94 -> V_95 ++ ;
if ( V_4 -> V_94 -> V_95 >= V_18 -> V_27 ) {
V_4 -> V_94 -> V_95 = 0 ;
V_10 -> V_93 ++ ;
}
}
return 0 ;
}
static void F_34 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
const struct V_7 * V_32 = F_2 ( V_2 ) ;
struct V_9 * V_10 = V_2 -> V_11 ;
struct V_17 * V_18 = & V_4 -> V_94 -> V_18 ;
int V_104 , V_105 ;
V_104 = F_11 ( V_2 -> V_36 + V_45 ) ;
if ( ! ( V_104 & V_106 ) ) {
F_30 ( V_2 -> V_15 , L_7 , V_104 ) ;
V_4 -> V_94 -> V_96 |= V_97 | V_98 ;
F_31 ( V_2 , V_4 ) ;
return;
}
if ( V_104 & V_99 ) {
F_30 ( V_2 -> V_15 ,
L_6 , V_104 ) ;
V_4 -> V_94 -> V_96 |= V_97 | V_98 ;
F_31 ( V_2 , V_4 ) ;
return;
}
V_105 = V_32 -> V_107 ;
if ( V_105 * sizeof( short ) >= V_4 -> V_94 -> V_108 ) {
V_104 = V_4 -> V_94 -> V_108 / sizeof( short ) ;
if ( F_33 ( V_2 , V_4 , V_104 , 0 ) )
return;
V_105 -= V_104 ;
}
if ( V_105 ) {
if ( F_33 ( V_2 , V_4 , V_105 , 1 ) )
return;
}
if ( V_18 -> V_100 == V_101 &&
V_10 -> V_93 >= V_18 -> V_102 ) {
V_4 -> V_94 -> V_96 |= V_97 ;
F_31 ( V_2 , V_4 ) ;
return;
}
F_13 ( 0 , V_2 -> V_36 + V_56 ) ;
F_31 ( V_2 , V_4 ) ;
}
static T_2 F_35 ( int V_109 , void * V_110 )
{
struct V_1 * V_2 = V_110 ;
struct V_9 * V_10 = V_2 -> V_11 ;
struct V_3 * V_4 ;
struct V_17 * V_18 ;
if ( ! V_2 -> V_111 )
return V_112 ;
V_4 = V_2 -> V_113 ;
V_18 = & V_4 -> V_94 -> V_18 ;
if ( ! ( F_11 ( V_2 -> V_36 + V_45 ) & V_114 ) )
return V_112 ;
if ( V_10 -> V_115 ) {
V_10 -> V_115 = 0 ;
V_10 -> V_51 &= V_52 ;
V_10 -> V_51 |= V_53 ;
F_9 ( V_10 -> V_51 , V_2 -> V_36 + V_54 ) ;
V_10 -> V_51 = V_10 -> V_116 ;
F_13 ( 0 , V_2 -> V_36 + V_55 ) ;
F_13 ( 0 , V_2 -> V_36 + V_56 ) ;
F_9 ( V_10 -> V_40 , V_2 -> V_36 + V_37 ) ;
F_9 ( V_10 -> V_51 , V_2 -> V_36 + V_54 ) ;
F_20 ( V_2 , true ) ;
return V_117 ;
}
if ( V_18 -> V_118 & V_119 )
F_29 ( V_2 , V_4 ) ;
else
F_34 ( V_2 , V_4 ) ;
return V_117 ;
}
static int F_36 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_9 * V_10 = V_2 -> V_11 ;
struct V_17 * V_18 = & V_4 -> V_94 -> V_18 ;
F_20 ( V_2 , false ) ;
F_8 ( V_2 , V_4 , V_18 -> V_20 , V_18 -> V_27 ,
V_10 -> V_28 ) ;
F_13 ( 0 , V_2 -> V_36 + V_55 ) ;
F_13 ( 0 , V_2 -> V_36 + V_56 ) ;
V_10 -> V_93 = 0 ;
V_4 -> V_94 -> V_95 = 0 ;
V_10 -> V_51 &= V_52 ;
if ( ( V_18 -> V_118 & V_119 ) == 0 )
V_10 -> V_51 |= V_120 ;
V_10 -> V_76 = V_10 -> V_121 ;
V_10 -> V_75 = V_10 -> V_122 ;
if ( V_18 -> V_123 == V_124 ) {
V_10 -> V_51 |= V_125 | V_126 ;
if ( V_18 -> V_127 == V_128 ) {
V_10 -> V_116 = V_10 -> V_51 ;
V_10 -> V_51 &=
~ ( V_125 | V_120 | V_129 ) ;
V_10 -> V_51 |= V_130 ;
V_10 -> V_115 = 1 ;
} else {
V_10 -> V_115 = 0 ;
}
F_9 ( V_10 -> V_51 , V_2 -> V_36 + V_54 ) ;
if ( V_18 -> V_127 == V_131 )
F_20 ( V_2 , true ) ;
} else {
V_10 -> V_51 |= V_130 | V_126 ;
F_9 ( V_10 -> V_51 , V_2 -> V_36 + V_54 ) ;
}
return 0 ;
}
static int F_37 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_17 * V_18 )
{
const struct V_7 * V_32 = F_2 ( V_2 ) ;
struct V_9 * V_10 = V_2 -> V_11 ;
int V_132 = 0 ;
unsigned int V_133 ;
V_132 |= F_38 ( & V_18 -> V_127 , V_131 | V_128 ) ;
V_132 |= F_38 ( & V_18 -> V_134 , V_135 ) ;
V_132 |= F_38 ( & V_18 -> V_123 , V_124 | V_128 ) ;
V_132 |= F_38 ( & V_18 -> V_136 , V_101 ) ;
V_132 |= F_38 ( & V_18 -> V_100 , V_101 | V_137 ) ;
if ( V_132 )
return 1 ;
V_132 |= F_39 ( V_18 -> V_127 ) ;
V_132 |= F_39 ( V_18 -> V_123 ) ;
V_132 |= F_39 ( V_18 -> V_100 ) ;
if ( V_132 )
return 2 ;
V_132 |= F_40 ( & V_18 -> V_138 , 0 ) ;
V_132 |= F_40 ( & V_18 -> V_139 , 0 ) ;
if ( V_18 -> V_123 == V_124 )
V_132 |= F_41 ( & V_18 -> V_140 ,
V_32 -> V_141 ) ;
else
V_132 |= F_40 ( & V_18 -> V_140 , 0 ) ;
V_132 |= F_40 ( & V_18 -> V_142 , V_18 -> V_27 ) ;
if ( V_18 -> V_100 == V_101 )
V_132 |= F_41 ( & V_18 -> V_102 , 1 ) ;
else
V_132 |= F_40 ( & V_18 -> V_102 , 0 ) ;
if ( V_132 )
return 3 ;
if ( V_18 -> V_123 == V_124 ) {
V_133 = V_18 -> V_140 ;
F_42 ( V_143 ,
& V_10 -> V_121 ,
& V_10 -> V_122 ,
& V_133 , V_18 -> V_118 ) ;
V_132 |= F_40 ( & V_18 -> V_140 , V_133 ) ;
}
if ( V_132 )
return 4 ;
V_132 |= F_4 ( V_2 , V_4 , V_18 ) ;
if ( V_132 )
return 5 ;
return 0 ;
}
static int F_43 ( struct V_1 * V_2 )
{
const struct V_7 * V_32 = F_2 ( V_2 ) ;
struct V_9 * V_10 = V_2 -> V_11 ;
F_9 ( 0x30 , V_2 -> V_36 + V_80 ) ;
V_10 -> V_51 = V_53 | V_52 ;
F_9 ( V_10 -> V_51 , V_2 -> V_36 + V_54 ) ;
F_13 ( 0 , V_2 -> V_36 + V_55 ) ;
F_13 ( 0 , V_2 -> V_36 + V_56 ) ;
F_20 ( V_2 , false ) ;
V_10 -> V_62 = 0 ;
if ( V_32 -> V_144 ) {
F_13 ( V_10 -> V_62 , V_2 -> V_36 + V_63 ) ;
F_9 ( 0 , V_2 -> V_36 + V_65 ) ;
V_10 -> V_66 [ 0 ] = 0x0000 ;
if ( V_32 -> V_144 > 1 ) {
F_9 ( 0 , V_2 -> V_36 + V_64 ) ;
V_10 -> V_66 [ 1 ] = 0x0000 ;
}
}
F_9 ( 0 , V_2 -> V_36 + V_69 ) ;
F_13 ( 0 , V_2 -> V_36 + V_55 ) ;
F_13 ( 0 , V_2 -> V_36 + V_56 ) ;
return 0 ;
}
static int F_44 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = V_2 -> V_11 ;
F_13 ( V_145 , V_2 -> V_36 + V_146 ) ;
V_10 -> V_62 = 0xAA ;
F_13 ( V_10 -> V_62 , V_2 -> V_36 + V_90 ) ;
F_9 ( 0x0800 , V_2 -> V_36 + V_91 ) ;
F_9 ( 0x0800 , V_2 -> V_36 + V_147 ) ;
F_9 ( 0x0800 , V_2 -> V_36 + V_148 ) ;
F_9 ( 0x0800 , V_2 -> V_36 + V_149 ) ;
F_13 ( 0 , V_2 -> V_36 + V_92 ) ;
V_10 -> V_66 [ 0 ] = 0x0800 ;
V_10 -> V_66 [ 1 ] = 0x0800 ;
V_10 -> V_66 [ 2 ] = 0x0800 ;
V_10 -> V_66 [ 3 ] = 0x0800 ;
return 0 ;
}
static int F_45 ( struct V_1 * V_2 )
{
const struct V_7 * V_32 = F_2 ( V_2 ) ;
switch ( V_32 -> V_12 ) {
case V_150 :
return F_44 ( V_2 ) ;
default:
return F_43 ( V_2 ) ;
}
}
static int F_46 ( struct V_1 * V_2 ,
unsigned long V_43 )
{
struct V_151 * V_152 = F_47 ( V_2 ) ;
const struct V_7 * V_32 = NULL ;
struct V_9 * V_10 ;
struct V_3 * V_4 ;
int V_50 , V_153 , V_154 ;
if ( V_43 < F_48 ( V_155 ) )
V_32 = & V_155 [ V_43 ] ;
if ( ! V_32 )
return - V_156 ;
V_2 -> V_157 = V_32 ;
V_2 -> V_158 = V_32 -> V_159 ;
V_10 = F_49 ( V_2 , sizeof( * V_10 ) ) ;
if ( ! V_10 )
return - V_160 ;
V_50 = F_50 ( V_2 ) ;
if ( V_50 )
return V_50 ;
V_2 -> V_36 = F_51 ( V_152 , 2 ) ;
V_154 = 0 ;
if ( V_32 -> V_161 )
V_154 ++ ;
if ( V_32 -> V_144 )
V_154 ++ ;
if ( V_32 -> V_162 )
V_154 ++ ;
if ( V_32 -> V_163 )
V_154 ++ ;
if ( V_32 -> V_164 )
V_154 ++ ;
V_50 = F_52 ( V_2 , V_154 ) ;
if ( V_50 )
return V_50 ;
F_45 ( V_2 ) ;
if ( V_32 -> V_165 && V_152 -> V_109 ) {
V_50 = F_53 ( V_152 -> V_109 , F_35 ,
V_166 , V_2 -> V_158 , V_2 ) ;
if ( V_50 == 0 )
V_2 -> V_109 = V_152 -> V_109 ;
}
V_153 = 0 ;
if ( V_32 -> V_161 ) {
V_4 = & V_2 -> V_167 [ V_153 ] ;
V_4 -> type = V_168 ;
V_4 -> V_169 = V_170 | V_171 | V_172 ;
if ( V_32 -> V_173 )
V_4 -> V_169 |= V_174 ;
V_4 -> V_23 = V_32 -> V_161 ;
V_4 -> V_60 = V_32 -> V_175 ;
V_4 -> V_176 = V_32 -> V_177 ;
V_4 -> V_178 = F_12 ;
if ( V_2 -> V_109 ) {
V_2 -> V_113 = V_4 ;
V_4 -> V_169 |= V_179 ;
V_4 -> V_180 = V_4 -> V_23 ;
V_4 -> V_181 = F_37 ;
V_4 -> V_182 = F_36 ;
V_4 -> V_183 = F_28 ;
}
V_153 ++ ;
}
if ( V_32 -> V_144 ) {
V_4 = & V_2 -> V_167 [ V_153 ] ;
V_4 -> type = V_184 ;
V_4 -> V_169 = V_185 | V_172 | V_171 ;
V_4 -> V_23 = V_32 -> V_144 ;
V_4 -> V_60 = V_32 -> V_186 ;
V_4 -> V_180 = V_32 -> V_144 ;
V_4 -> V_176 = V_32 -> V_187 ;
switch ( V_32 -> V_12 ) {
case V_150 :
V_4 -> V_188 = F_27 ;
break;
default:
V_4 -> V_188 = F_15 ;
break;
}
V_4 -> V_178 = F_16 ;
V_153 ++ ;
}
if ( V_32 -> V_162 ) {
V_4 = & V_2 -> V_167 [ V_153 ] ;
V_4 -> type = V_189 ;
V_4 -> V_169 = V_170 | V_172 | V_171 ;
V_4 -> V_23 = V_32 -> V_162 ;
V_4 -> V_60 = 1 ;
V_4 -> V_180 = V_32 -> V_162 ;
V_4 -> V_176 = & V_190 ;
V_4 -> V_191 = F_17 ;
V_153 ++ ;
}
if ( V_32 -> V_163 ) {
V_4 = & V_2 -> V_167 [ V_153 ] ;
V_4 -> type = V_192 ;
V_4 -> V_169 = V_185 | V_172 | V_171 ;
V_4 -> V_23 = V_32 -> V_163 ;
V_4 -> V_60 = 1 ;
V_4 -> V_180 = V_32 -> V_163 ;
V_4 -> V_176 = & V_190 ;
V_4 -> V_191 = F_18 ;
V_153 ++ ;
}
if ( V_32 -> V_164 ) {
V_4 = & V_2 -> V_167 [ V_153 ] ;
V_4 -> type = V_193 ;
V_4 -> V_169 = V_170 | V_185 ;
V_4 -> V_23 = V_32 -> V_164 ;
V_4 -> V_180 = V_32 -> V_164 ;
V_4 -> V_60 = 0xffff ;
V_4 -> V_176 = & V_194 ;
V_4 -> V_178 = F_23 ;
V_4 -> V_188 = F_24 ;
V_4 -> V_195 = F_25 ;
V_153 ++ ;
}
return 0 ;
}
static void F_54 ( struct V_1 * V_2 )
{
if ( V_2 -> V_36 )
F_45 ( V_2 ) ;
if ( V_2 -> V_109 )
F_55 ( V_2 -> V_109 , V_2 ) ;
F_56 ( V_2 ) ;
}
static int F_57 ( struct V_151 * V_2 ,
const struct V_196 * V_197 )
{
return F_58 ( V_2 , & V_198 ,
V_197 -> V_199 ) ;
}
