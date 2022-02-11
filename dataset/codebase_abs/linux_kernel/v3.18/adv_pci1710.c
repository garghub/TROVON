static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
unsigned int V_5 ,
unsigned int V_6 )
{
const struct V_7 * V_8 = V_2 -> V_9 ;
struct V_10 * V_11 = V_2 -> V_12 ;
if ( V_8 -> V_13 != V_14 ) {
if ( ( V_6 & 0xf000 ) != V_11 -> V_15 [ V_5 ] ) {
F_2 ( V_2 -> V_16 ,
L_1 ,
( V_6 >> 12 ) & 0xf ,
( V_11 -> V_15 [ V_5 ] >> 12 ) & 0xf ) ;
return - V_17 ;
}
}
return 0 ;
}
static int F_3 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_18 * V_19 )
{
struct V_10 * V_11 = V_2 -> V_12 ;
unsigned int V_20 = F_4 ( V_19 -> V_21 [ 0 ] ) ;
unsigned int V_22 = F_5 ( V_19 -> V_21 [ 0 ] ) ;
unsigned int V_23 = ( V_20 + 1 ) % V_4 -> V_24 ;
unsigned int V_25 [ 32 ] ;
unsigned int V_26 ;
int V_27 ;
if ( V_19 -> V_28 == 1 ) {
V_11 -> V_29 = V_19 -> V_28 ;
return 0 ;
}
V_25 [ 0 ] = V_19 -> V_21 [ 0 ] ;
for ( V_27 = 1 ; V_27 < V_19 -> V_28 ; V_27 ++ ) {
unsigned int V_5 = F_4 ( V_19 -> V_21 [ V_27 ] ) ;
unsigned int V_30 = F_5 ( V_19 -> V_21 [ V_27 ] ) ;
if ( V_19 -> V_21 [ 0 ] == V_19 -> V_21 [ V_27 ] )
break;
if ( V_30 == V_31 && ( V_5 & 1 ) ) {
F_2 ( V_2 -> V_16 ,
L_2 ) ;
return - V_32 ;
}
if ( V_22 == V_31 )
V_23 = ( V_23 + 1 ) % V_4 -> V_24 ;
if ( V_5 != V_23 ) {
F_2 ( V_2 -> V_16 ,
L_3 ,
V_27 , V_5 , V_23 , V_20 ) ;
return - V_32 ;
}
V_25 [ V_27 ] = V_19 -> V_21 [ V_27 ] ;
V_22 = V_30 ;
}
V_26 = V_27 ;
for ( V_27 = 0 ; V_27 < V_19 -> V_28 ; V_27 ++ ) {
if ( V_19 -> V_21 [ V_27 ] != V_25 [ V_27 % V_26 ] ) {
F_2 ( V_2 -> V_16 ,
L_4 ,
V_27 , F_4 ( V_25 [ V_27 ] ) ,
F_6 ( V_25 [ V_27 ] ) ,
F_5 ( V_25 [ V_27 ] ) ,
F_4 ( V_19 -> V_21 [ V_27 % V_26 ] ) ,
F_6 ( V_19 -> V_21 [ V_27 % V_26 ] ) ,
F_5 ( V_25 [ V_27 % V_26 ] ) ) ;
return - V_32 ;
}
}
V_11 -> V_29 = V_26 ;
return 0 ;
}
static void F_7 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
unsigned int * V_21 , unsigned int V_24 ,
unsigned int V_26 )
{
const struct V_7 * V_33 = V_2 -> V_9 ;
struct V_10 * V_11 = V_2 -> V_12 ;
unsigned int V_27 , V_34 , V_35 ;
for ( V_27 = 0 ; V_27 < V_26 ; V_27 ++ ) {
V_35 = V_36 [ F_4 ( V_21 [ V_27 ] ) ] ;
F_8 ( V_35 , V_2 -> V_37 + V_38 ) ;
V_34 = V_33 -> V_39 [ F_6 ( V_21 [ V_27 ] ) ] ;
if ( F_5 ( V_21 [ V_27 ] ) == V_31 )
V_34 |= 0x0020 ;
F_8 ( V_34 , V_2 -> V_37 + V_40 ) ;
V_11 -> V_15 [ V_27 ] =
( F_4 ( V_21 [ V_27 ] ) << 12 ) & 0xf000 ;
}
for ( ; V_27 < V_24 ; V_27 ++ ) {
V_11 -> V_15 [ V_27 ] =
( F_4 ( V_21 [ V_27 ] ) << 12 ) & 0xf000 ;
}
V_11 -> V_41 =
F_4 ( V_21 [ 0 ] ) | ( F_4 ( V_21 [ V_26 - 1 ] ) << 8 ) ;
F_8 ( V_11 -> V_41 , V_2 -> V_37 + V_38 ) ;
}
static int F_9 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_42 * V_43 ,
unsigned long V_44 )
{
unsigned int V_45 ;
V_45 = F_10 ( V_2 -> V_37 + V_46 ) ;
if ( ( V_45 & V_47 ) == 0 )
return 0 ;
return - V_48 ;
}
static int F_11 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_42 * V_43 , unsigned int * V_49 )
{
struct V_10 * V_11 = V_2 -> V_12 ;
unsigned int V_5 = F_4 ( V_43 -> V_50 ) ;
int V_51 = 0 ;
int V_27 ;
V_11 -> V_52 &= V_53 ;
V_11 -> V_52 |= V_54 ;
F_8 ( V_11 -> V_52 , V_2 -> V_37 + V_55 ) ;
F_12 ( 0 , V_2 -> V_37 + V_56 ) ;
F_12 ( 0 , V_2 -> V_37 + V_57 ) ;
F_7 ( V_2 , V_4 , & V_43 -> V_50 , 1 , 1 ) ;
for ( V_27 = 0 ; V_27 < V_43 -> V_58 ; V_27 ++ ) {
unsigned int V_6 ;
F_8 ( 0 , V_2 -> V_37 + V_59 ) ;
V_51 = F_13 ( V_2 , V_4 , V_43 , F_9 , 0 ) ;
if ( V_51 )
break;
V_6 = F_10 ( V_2 -> V_37 + V_60 ) ;
V_51 = F_1 ( V_2 , V_4 , V_5 , V_6 ) ;
if ( V_51 )
break;
V_49 [ V_27 ] = V_6 & V_4 -> V_61 ;
}
F_12 ( 0 , V_2 -> V_37 + V_56 ) ;
F_12 ( 0 , V_2 -> V_37 + V_57 ) ;
return V_51 ? V_51 : V_43 -> V_58 ;
}
static int F_14 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_42 * V_43 , unsigned int * V_49 )
{
struct V_10 * V_11 = V_2 -> V_12 ;
unsigned int V_6 ;
int V_58 , V_5 , V_34 , V_62 ;
V_5 = F_4 ( V_43 -> V_50 ) ;
V_34 = F_6 ( V_43 -> V_50 ) ;
if ( V_5 ) {
V_11 -> V_63 &= 0xfb ;
V_11 -> V_63 |= ( V_34 << 2 ) ;
F_8 ( V_11 -> V_63 , V_2 -> V_37 + V_64 ) ;
V_62 = V_65 ;
} else {
V_11 -> V_63 &= 0xfe ;
V_11 -> V_63 |= V_34 ;
F_8 ( V_11 -> V_63 , V_2 -> V_37 + V_64 ) ;
V_62 = V_66 ;
}
V_6 = V_11 -> V_67 [ V_5 ] ;
for ( V_58 = 0 ; V_58 < V_43 -> V_58 ; V_58 ++ ) {
V_6 = V_49 [ V_58 ] ;
F_8 ( V_6 , V_2 -> V_37 + V_62 ) ;
}
V_11 -> V_67 [ V_5 ] = V_6 ;
return V_58 ;
}
static int F_15 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_42 * V_43 , unsigned int * V_49 )
{
struct V_10 * V_11 = V_2 -> V_12 ;
int V_58 , V_5 ;
V_5 = F_4 ( V_43 -> V_50 ) ;
for ( V_58 = 0 ; V_58 < V_43 -> V_58 ; V_58 ++ )
V_49 [ V_58 ] = V_11 -> V_67 [ V_5 ] ;
return V_58 ;
}
static int F_16 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_42 * V_43 , unsigned int * V_49 )
{
V_49 [ 1 ] = F_10 ( V_2 -> V_37 + V_68 ) ;
return V_43 -> V_58 ;
}
static int F_17 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_42 * V_43 ,
unsigned int * V_49 )
{
if ( F_18 ( V_4 , V_49 ) )
F_8 ( V_4 -> V_69 , V_2 -> V_37 + V_70 ) ;
V_49 [ 1 ] = V_4 -> V_69 ;
return V_43 -> V_58 ;
}
static void F_19 ( struct V_1 * V_2 ,
bool V_71 )
{
struct V_10 * V_11 = V_2 -> V_12 ;
unsigned long V_72 = V_2 -> V_37 + V_73 ;
F_20 ( V_72 , 1 , 2 , V_74 | V_75 ) ;
F_20 ( V_72 , 1 , 1 , V_74 | V_75 ) ;
if ( V_71 ) {
F_21 ( V_72 , 1 , 2 , V_11 -> V_76 ) ;
F_21 ( V_72 , 1 , 1 , V_11 -> V_77 ) ;
}
}
static int F_22 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_42 * V_43 ,
unsigned int * V_49 )
{
unsigned int V_78 , V_79 , V_80 ;
int V_27 ;
V_80 = 0xD2 ;
for ( V_27 = 0 ; V_27 < V_43 -> V_58 ; V_27 ++ ) {
F_8 ( V_80 , V_2 -> V_37 + V_81 ) ;
V_79 = F_10 ( V_2 -> V_37 + V_82 ) & 0xFF ;
V_78 = F_10 ( V_2 -> V_37 + V_82 ) & 0xFF ;
V_49 [ 0 ] = V_79 | ( V_78 << 8 ) ;
}
return V_43 -> V_58 ;
}
static int F_23 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_42 * V_43 ,
unsigned int * V_49 )
{
struct V_10 * V_11 = V_2 -> V_12 ;
T_1 V_78 , V_79 , V_80 , V_45 ;
V_79 = V_49 [ 0 ] & 0x00FF ;
V_78 = ( V_49 [ 0 ] & 0xFF00 ) >> 8 ;
F_8 ( V_79 , V_2 -> V_37 + V_82 ) ;
F_8 ( V_78 , V_2 -> V_37 + V_82 ) ;
if ( V_11 -> V_83 ) {
V_80 = 0xE2 ;
do {
F_8 ( V_80 , V_2 -> V_37 + V_81 ) ;
V_45 = F_10 ( V_2 -> V_37 + V_82 ) & 0xFF ;
} while ( V_45 & 0x40 );
}
return V_43 -> V_58 ;
}
static int F_24 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_42 * V_43 ,
unsigned int * V_49 )
{
#ifdef F_25
struct V_10 * V_11 = V_2 -> V_12 ;
T_1 V_80 = 0 ;
V_11 -> V_83 = V_49 [ 0 ] & 0x20 ;
if ( ! ( V_49 [ 0 ] & 0x10 ) ) {
V_11 -> V_52 &= ~ V_53 ;
} else {
V_11 -> V_52 |= V_53 ;
}
F_8 ( V_11 -> V_52 , V_2 -> V_37 + V_55 ) ;
if ( V_49 [ 0 ] & 0x01 )
V_80 |= V_84 ;
if ( V_49 [ 0 ] & 0x02 )
V_80 |= V_85 ;
if ( V_49 [ 0 ] & 0x04 )
V_80 |= V_86 ;
if ( V_49 [ 0 ] & 0x08 )
V_80 |= V_87 ;
V_80 |= V_88 ;
V_80 |= V_89 ;
F_8 ( V_80 , V_2 -> V_37 + V_81 ) ;
#endif
return 1 ;
}
static int F_26 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_42 * V_43 , unsigned int * V_49 )
{
struct V_10 * V_11 = V_2 -> V_12 ;
unsigned int V_6 ;
int V_58 , V_90 , V_5 ;
V_5 = F_4 ( V_43 -> V_50 ) ;
V_90 = V_11 -> V_63 & ( ~ ( 0x03 << ( V_5 << 1 ) ) ) ;
V_90 |= ( F_6 ( V_43 -> V_50 ) << ( V_5 << 1 ) ) ;
if ( V_90 != V_11 -> V_63 ) {
F_12 ( V_90 , V_2 -> V_37 + V_91 ) ;
V_11 -> V_63 = V_90 ;
}
V_6 = V_11 -> V_67 [ V_5 ] ;
for ( V_58 = 0 ; V_58 < V_43 -> V_58 ; V_58 ++ ) {
V_6 = V_49 [ V_58 ] ;
F_8 ( V_6 , V_2 -> V_37 + V_92 + ( V_5 << 1 ) ) ;
F_12 ( 0 , V_2 -> V_37 + V_93 ) ;
}
V_11 -> V_67 [ V_5 ] = V_6 ;
return V_58 ;
}
static int F_27 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
const struct V_7 * V_33 = V_2 -> V_9 ;
struct V_10 * V_11 = V_2 -> V_12 ;
switch ( V_33 -> V_13 ) {
default:
V_11 -> V_52 &= V_53 ;
V_11 -> V_52 |= V_54 ;
F_8 ( V_11 -> V_52 , V_2 -> V_37 + V_55 ) ;
F_19 ( V_2 , false ) ;
F_12 ( 0 , V_2 -> V_37 + V_56 ) ;
F_12 ( 0 , V_2 -> V_37 + V_57 ) ;
break;
}
V_11 -> V_94 = 0 ;
V_4 -> V_95 -> V_96 = 0 ;
return 0 ;
}
static void F_28 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_10 * V_11 = V_2 -> V_12 ;
struct V_18 * V_19 = & V_4 -> V_95 -> V_19 ;
unsigned int V_45 ;
unsigned int V_6 ;
int V_51 ;
V_45 = F_10 ( V_2 -> V_37 + V_46 ) ;
if ( V_45 & V_47 ) {
F_29 ( V_2 -> V_16 , L_5 , V_45 ) ;
V_4 -> V_95 -> V_97 |= V_98 | V_99 ;
F_30 ( V_2 , V_4 ) ;
return;
}
if ( V_45 & V_100 ) {
F_29 ( V_2 -> V_16 ,
L_6 , V_45 ) ;
V_4 -> V_95 -> V_97 |= V_98 | V_99 ;
F_30 ( V_2 , V_4 ) ;
return;
}
F_12 ( 0 , V_2 -> V_37 + V_57 ) ;
for (; ! ( F_10 ( V_2 -> V_37 + V_46 ) & V_47 ) ; ) {
V_6 = F_10 ( V_2 -> V_37 + V_60 ) ;
V_51 = F_1 ( V_2 , V_4 , V_4 -> V_95 -> V_96 , V_6 ) ;
if ( V_51 ) {
V_4 -> V_95 -> V_97 |= V_98 | V_99 ;
break;
}
F_31 ( V_4 , V_6 & V_4 -> V_61 ) ;
V_4 -> V_95 -> V_96 ++ ;
if ( V_4 -> V_95 -> V_96 >= V_19 -> V_28 )
V_4 -> V_95 -> V_96 = 0 ;
if ( V_4 -> V_95 -> V_96 == 0 ) {
V_11 -> V_94 ++ ;
if ( V_19 -> V_101 == V_102 &&
V_11 -> V_94 >= V_19 -> V_103 ) {
V_4 -> V_95 -> V_97 |= V_98 ;
break;
}
}
}
F_12 ( 0 , V_2 -> V_37 + V_57 ) ;
F_30 ( V_2 , V_4 ) ;
}
static int F_32 ( struct V_1 * V_2 ,
struct V_3 * V_4 , int V_58 , int V_104 )
{
struct V_10 * V_11 = V_2 -> V_12 ;
struct V_18 * V_19 = & V_4 -> V_95 -> V_19 ;
unsigned int V_6 ;
int V_51 ;
int V_27 ;
for ( V_27 = 0 ; V_27 < V_58 ; V_27 ++ ) {
V_6 = F_10 ( V_2 -> V_37 + V_60 ) ;
V_51 = F_1 ( V_2 , V_4 , V_4 -> V_95 -> V_96 , V_6 ) ;
if ( V_51 ) {
V_4 -> V_95 -> V_97 |= V_98 | V_99 ;
return V_51 ;
}
F_31 ( V_4 , V_6 & V_4 -> V_61 ) ;
V_4 -> V_95 -> V_96 ++ ;
if ( V_4 -> V_95 -> V_96 >= V_19 -> V_28 ) {
V_4 -> V_95 -> V_96 = 0 ;
V_11 -> V_94 ++ ;
}
}
return 0 ;
}
static void F_33 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
const struct V_7 * V_33 = V_2 -> V_9 ;
struct V_10 * V_11 = V_2 -> V_12 ;
struct V_18 * V_19 = & V_4 -> V_95 -> V_19 ;
int V_105 , V_106 ;
V_105 = F_10 ( V_2 -> V_37 + V_46 ) ;
if ( ! ( V_105 & V_107 ) ) {
F_29 ( V_2 -> V_16 , L_7 , V_105 ) ;
V_4 -> V_95 -> V_97 |= V_98 | V_99 ;
F_30 ( V_2 , V_4 ) ;
return;
}
if ( V_105 & V_100 ) {
F_29 ( V_2 -> V_16 ,
L_6 , V_105 ) ;
V_4 -> V_95 -> V_97 |= V_98 | V_99 ;
F_30 ( V_2 , V_4 ) ;
return;
}
V_106 = V_33 -> V_108 ;
if ( V_106 * sizeof( short ) >= V_4 -> V_95 -> V_109 ) {
V_105 = V_4 -> V_95 -> V_109 / sizeof( short ) ;
if ( F_32 ( V_2 , V_4 , V_105 , 0 ) )
return;
V_106 -= V_105 ;
}
if ( V_106 ) {
if ( F_32 ( V_2 , V_4 , V_106 , 1 ) )
return;
}
if ( V_19 -> V_101 == V_102 &&
V_11 -> V_94 >= V_19 -> V_103 ) {
V_4 -> V_95 -> V_97 |= V_98 ;
F_30 ( V_2 , V_4 ) ;
return;
}
F_12 ( 0 , V_2 -> V_37 + V_57 ) ;
F_30 ( V_2 , V_4 ) ;
}
static T_2 F_34 ( int V_110 , void * V_111 )
{
struct V_1 * V_2 = V_111 ;
struct V_10 * V_11 = V_2 -> V_12 ;
struct V_3 * V_4 ;
struct V_18 * V_19 ;
if ( ! V_2 -> V_112 )
return V_113 ;
V_4 = V_2 -> V_114 ;
V_19 = & V_4 -> V_95 -> V_19 ;
if ( ! ( F_10 ( V_2 -> V_37 + V_46 ) & V_115 ) )
return V_113 ;
if ( V_11 -> V_116 ) {
V_11 -> V_116 = 0 ;
V_11 -> V_52 &= V_53 ;
V_11 -> V_52 |= V_54 ;
F_8 ( V_11 -> V_52 , V_2 -> V_37 + V_55 ) ;
V_11 -> V_52 = V_11 -> V_117 ;
F_12 ( 0 , V_2 -> V_37 + V_56 ) ;
F_12 ( 0 , V_2 -> V_37 + V_57 ) ;
F_8 ( V_11 -> V_41 , V_2 -> V_37 + V_38 ) ;
F_8 ( V_11 -> V_52 , V_2 -> V_37 + V_55 ) ;
F_19 ( V_2 , true ) ;
return V_118 ;
}
if ( V_19 -> V_119 & V_120 )
F_28 ( V_2 , V_4 ) ;
else
F_33 ( V_2 , V_4 ) ;
return V_118 ;
}
static int F_35 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_10 * V_11 = V_2 -> V_12 ;
struct V_18 * V_19 = & V_4 -> V_95 -> V_19 ;
F_19 ( V_2 , false ) ;
F_7 ( V_2 , V_4 , V_19 -> V_21 , V_19 -> V_28 ,
V_11 -> V_29 ) ;
F_12 ( 0 , V_2 -> V_37 + V_56 ) ;
F_12 ( 0 , V_2 -> V_37 + V_57 ) ;
V_11 -> V_94 = 0 ;
V_4 -> V_95 -> V_96 = 0 ;
V_11 -> V_52 &= V_53 ;
if ( ( V_19 -> V_119 & V_120 ) == 0 )
V_11 -> V_52 |= V_121 ;
V_11 -> V_77 = V_11 -> V_122 ;
V_11 -> V_76 = V_11 -> V_123 ;
if ( V_19 -> V_124 == V_125 ) {
V_11 -> V_52 |= V_126 | V_127 ;
if ( V_19 -> V_128 == V_129 ) {
V_11 -> V_117 = V_11 -> V_52 ;
V_11 -> V_52 &=
~ ( V_126 | V_121 | V_130 ) ;
V_11 -> V_52 |= V_131 ;
V_11 -> V_116 = 1 ;
} else {
V_11 -> V_116 = 0 ;
}
F_8 ( V_11 -> V_52 , V_2 -> V_37 + V_55 ) ;
if ( V_19 -> V_128 == V_132 )
F_19 ( V_2 , true ) ;
} else {
V_11 -> V_52 |= V_131 | V_127 ;
F_8 ( V_11 -> V_52 , V_2 -> V_37 + V_55 ) ;
}
return 0 ;
}
static int F_36 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_18 * V_19 )
{
const struct V_7 * V_33 = V_2 -> V_9 ;
struct V_10 * V_11 = V_2 -> V_12 ;
int V_133 = 0 ;
unsigned int V_134 ;
V_133 |= F_37 ( & V_19 -> V_128 , V_132 | V_129 ) ;
V_133 |= F_37 ( & V_19 -> V_135 , V_136 ) ;
V_133 |= F_37 ( & V_19 -> V_124 , V_125 | V_129 ) ;
V_133 |= F_37 ( & V_19 -> V_137 , V_102 ) ;
V_133 |= F_37 ( & V_19 -> V_101 , V_102 | V_138 ) ;
if ( V_133 )
return 1 ;
V_133 |= F_38 ( V_19 -> V_128 ) ;
V_133 |= F_38 ( V_19 -> V_124 ) ;
V_133 |= F_38 ( V_19 -> V_101 ) ;
if ( V_133 )
return 2 ;
V_133 |= F_39 ( & V_19 -> V_139 , 0 ) ;
V_133 |= F_39 ( & V_19 -> V_140 , 0 ) ;
if ( V_19 -> V_124 == V_125 )
V_133 |= F_40 ( & V_19 -> V_141 ,
V_33 -> V_142 ) ;
else
V_133 |= F_39 ( & V_19 -> V_141 , 0 ) ;
V_133 |= F_39 ( & V_19 -> V_143 , V_19 -> V_28 ) ;
if ( V_19 -> V_101 == V_102 )
V_133 |= F_40 ( & V_19 -> V_103 , 1 ) ;
else
V_133 |= F_39 ( & V_19 -> V_103 , 0 ) ;
if ( V_133 )
return 3 ;
if ( V_19 -> V_124 == V_125 ) {
V_134 = V_19 -> V_141 ;
F_41 ( V_144 ,
& V_11 -> V_122 ,
& V_11 -> V_123 ,
& V_134 , V_19 -> V_119 ) ;
V_133 |= F_39 ( & V_19 -> V_141 , V_134 ) ;
}
if ( V_133 )
return 4 ;
V_133 |= F_3 ( V_2 , V_4 , V_19 ) ;
if ( V_133 )
return 5 ;
return 0 ;
}
static int F_42 ( struct V_1 * V_2 )
{
const struct V_7 * V_33 = V_2 -> V_9 ;
struct V_10 * V_11 = V_2 -> V_12 ;
F_8 ( 0x30 , V_2 -> V_37 + V_81 ) ;
V_11 -> V_52 = V_54 | V_53 ;
F_8 ( V_11 -> V_52 , V_2 -> V_37 + V_55 ) ;
F_12 ( 0 , V_2 -> V_37 + V_56 ) ;
F_12 ( 0 , V_2 -> V_37 + V_57 ) ;
F_19 ( V_2 , false ) ;
V_11 -> V_63 = 0 ;
if ( V_33 -> V_145 ) {
F_12 ( V_11 -> V_63 , V_2 -> V_37 + V_64 ) ;
F_8 ( 0 , V_2 -> V_37 + V_66 ) ;
V_11 -> V_67 [ 0 ] = 0x0000 ;
if ( V_33 -> V_145 > 1 ) {
F_8 ( 0 , V_2 -> V_37 + V_65 ) ;
V_11 -> V_67 [ 1 ] = 0x0000 ;
}
}
F_8 ( 0 , V_2 -> V_37 + V_70 ) ;
F_12 ( 0 , V_2 -> V_37 + V_56 ) ;
F_12 ( 0 , V_2 -> V_37 + V_57 ) ;
return 0 ;
}
static int F_43 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_12 ;
F_12 ( V_146 , V_2 -> V_37 + V_147 ) ;
V_11 -> V_63 = 0xAA ;
F_12 ( V_11 -> V_63 , V_2 -> V_37 + V_91 ) ;
F_8 ( 0x0800 , V_2 -> V_37 + V_92 ) ;
F_8 ( 0x0800 , V_2 -> V_37 + V_148 ) ;
F_8 ( 0x0800 , V_2 -> V_37 + V_149 ) ;
F_8 ( 0x0800 , V_2 -> V_37 + V_150 ) ;
F_12 ( 0 , V_2 -> V_37 + V_93 ) ;
V_11 -> V_67 [ 0 ] = 0x0800 ;
V_11 -> V_67 [ 1 ] = 0x0800 ;
V_11 -> V_67 [ 2 ] = 0x0800 ;
V_11 -> V_67 [ 3 ] = 0x0800 ;
return 0 ;
}
static int F_44 ( struct V_1 * V_2 )
{
const struct V_7 * V_33 = V_2 -> V_9 ;
switch ( V_33 -> V_13 ) {
case V_151 :
return F_43 ( V_2 ) ;
default:
return F_42 ( V_2 ) ;
}
}
static int F_45 ( struct V_1 * V_2 ,
unsigned long V_44 )
{
struct V_152 * V_153 = F_46 ( V_2 ) ;
const struct V_7 * V_33 = NULL ;
struct V_10 * V_11 ;
struct V_3 * V_4 ;
int V_51 , V_154 , V_155 ;
if ( V_44 < F_47 ( V_156 ) )
V_33 = & V_156 [ V_44 ] ;
if ( ! V_33 )
return - V_157 ;
V_2 -> V_9 = V_33 ;
V_2 -> V_158 = V_33 -> V_159 ;
V_11 = F_48 ( V_2 , sizeof( * V_11 ) ) ;
if ( ! V_11 )
return - V_160 ;
V_51 = F_49 ( V_2 ) ;
if ( V_51 )
return V_51 ;
V_2 -> V_37 = F_50 ( V_153 , 2 ) ;
V_155 = 0 ;
if ( V_33 -> V_161 )
V_155 ++ ;
if ( V_33 -> V_145 )
V_155 ++ ;
if ( V_33 -> V_162 )
V_155 ++ ;
if ( V_33 -> V_163 )
V_155 ++ ;
if ( V_33 -> V_164 )
V_155 ++ ;
V_51 = F_51 ( V_2 , V_155 ) ;
if ( V_51 )
return V_51 ;
F_44 ( V_2 ) ;
if ( V_33 -> V_165 && V_153 -> V_110 ) {
V_51 = F_52 ( V_153 -> V_110 , F_34 ,
V_166 , V_2 -> V_158 , V_2 ) ;
if ( V_51 == 0 )
V_2 -> V_110 = V_153 -> V_110 ;
}
V_154 = 0 ;
if ( V_33 -> V_161 ) {
V_4 = & V_2 -> V_167 [ V_154 ] ;
V_4 -> type = V_168 ;
V_4 -> V_169 = V_170 | V_171 | V_172 ;
if ( V_33 -> V_173 )
V_4 -> V_169 |= V_174 ;
V_4 -> V_24 = V_33 -> V_161 ;
V_4 -> V_61 = V_33 -> V_175 ;
V_4 -> V_176 = V_33 -> V_177 ;
V_4 -> V_178 = F_11 ;
if ( V_2 -> V_110 ) {
V_2 -> V_114 = V_4 ;
V_4 -> V_169 |= V_179 ;
V_4 -> V_180 = V_4 -> V_24 ;
V_4 -> V_181 = F_36 ;
V_4 -> V_182 = F_35 ;
V_4 -> V_183 = F_27 ;
}
V_154 ++ ;
}
if ( V_33 -> V_145 ) {
V_4 = & V_2 -> V_167 [ V_154 ] ;
V_4 -> type = V_184 ;
V_4 -> V_169 = V_185 | V_172 | V_171 ;
V_4 -> V_24 = V_33 -> V_145 ;
V_4 -> V_61 = V_33 -> V_186 ;
V_4 -> V_180 = V_33 -> V_145 ;
V_4 -> V_176 = V_33 -> V_187 ;
switch ( V_33 -> V_13 ) {
case V_151 :
V_4 -> V_188 = F_26 ;
break;
default:
V_4 -> V_188 = F_14 ;
break;
}
V_4 -> V_178 = F_15 ;
V_154 ++ ;
}
if ( V_33 -> V_162 ) {
V_4 = & V_2 -> V_167 [ V_154 ] ;
V_4 -> type = V_189 ;
V_4 -> V_169 = V_170 | V_172 | V_171 ;
V_4 -> V_24 = V_33 -> V_162 ;
V_4 -> V_61 = 1 ;
V_4 -> V_180 = V_33 -> V_162 ;
V_4 -> V_176 = & V_190 ;
V_4 -> V_191 = F_16 ;
V_154 ++ ;
}
if ( V_33 -> V_163 ) {
V_4 = & V_2 -> V_167 [ V_154 ] ;
V_4 -> type = V_192 ;
V_4 -> V_169 = V_185 | V_172 | V_171 ;
V_4 -> V_24 = V_33 -> V_163 ;
V_4 -> V_61 = 1 ;
V_4 -> V_180 = V_33 -> V_163 ;
V_4 -> V_176 = & V_190 ;
V_4 -> V_191 = F_17 ;
V_154 ++ ;
}
if ( V_33 -> V_164 ) {
V_4 = & V_2 -> V_167 [ V_154 ] ;
V_4 -> type = V_193 ;
V_4 -> V_169 = V_170 | V_185 ;
V_4 -> V_24 = V_33 -> V_164 ;
V_4 -> V_180 = V_33 -> V_164 ;
V_4 -> V_61 = 0xffff ;
V_4 -> V_176 = & V_194 ;
V_4 -> V_178 = F_22 ;
V_4 -> V_188 = F_23 ;
V_4 -> V_195 = F_24 ;
V_154 ++ ;
}
return 0 ;
}
static void F_53 ( struct V_1 * V_2 )
{
if ( V_2 -> V_37 )
F_44 ( V_2 ) ;
F_54 ( V_2 ) ;
}
static int F_55 ( struct V_152 * V_2 ,
const struct V_196 * V_197 )
{
return F_56 ( V_2 , & V_198 ,
V_197 -> V_199 ) ;
}
