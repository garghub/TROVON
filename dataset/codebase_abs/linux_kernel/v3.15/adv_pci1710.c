static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
unsigned int * V_5 , unsigned int V_6 )
{
unsigned int V_7 [ 32 ] ;
unsigned int V_8 , V_9 , V_10 , V_11 ;
if ( V_6 < 1 ) {
F_2 ( V_2 , L_1 ) ;
return 0 ;
}
if ( V_6 == 1 )
return 1 ;
V_7 [ 0 ] = V_5 [ 0 ] ;
for ( V_8 = 1 , V_10 = 1 ; V_8 < V_6 ; V_8 ++ , V_10 ++ ) {
if ( V_5 [ 0 ] == V_5 [ V_8 ] )
break;
if ( ( F_3 ( V_5 [ V_8 ] ) & 1 ) &&
( F_4 ( V_5 [ V_8 ] ) == V_12 ) ) {
F_2 ( V_2 , L_2 ) ;
return 0 ;
}
V_9 = ( F_3 ( V_7 [ V_8 - 1 ] ) + 1 ) % V_4 -> V_6 ;
if ( F_4 ( V_7 [ V_8 - 1 ] ) == V_12 )
V_9 = ( V_9 + 1 ) % V_4 -> V_6 ;
if ( V_9 != F_3 ( V_5 [ V_8 ] ) ) {
F_5 ( L_3 ,
V_8 , F_3 ( V_5 [ V_8 ] ) , V_9 ,
F_3 ( V_5 [ 0 ] ) ) ;
return 0 ;
}
V_7 [ V_8 ] = V_5 [ V_8 ] ;
}
for ( V_8 = 0 , V_11 = 0 ; V_8 < V_6 ; V_8 ++ ) {
if ( V_5 [ V_8 ] != V_7 [ V_8 % V_10 ] ) {
F_5 ( L_4 ,
V_8 , F_3 ( V_7 [ V_8 ] ) ,
F_6 ( V_7 [ V_8 ] ) ,
F_4 ( V_7 [ V_8 ] ) ,
F_3 ( V_5 [ V_8 % V_10 ] ) ,
F_6 ( V_5 [ V_8 % V_10 ] ) ,
F_4 ( V_7 [ V_8 % V_10 ] ) ) ;
return 0 ;
}
}
return V_10 ;
}
static void F_7 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
unsigned int * V_5 , unsigned int V_6 ,
unsigned int V_10 )
{
const struct V_13 * V_14 = F_8 ( V_2 ) ;
struct V_15 * V_16 = V_2 -> V_17 ;
unsigned int V_8 , V_18 , V_19 ;
V_16 -> V_20 = V_10 ;
V_16 -> V_21 = 0 ;
for ( V_8 = 0 ; V_8 < V_10 ; V_8 ++ ) {
V_19 = V_22 [ F_3 ( V_5 [ V_8 ] ) ] ;
F_9 ( V_19 , V_2 -> V_23 + V_24 ) ;
V_18 = V_14 -> V_25 [ F_6 ( V_5 [ V_8 ] ) ] ;
if ( F_4 ( V_5 [ V_8 ] ) == V_12 )
V_18 |= 0x0020 ;
F_9 ( V_18 , V_2 -> V_23 + V_26 ) ;
#ifdef F_10
V_16 -> V_27 [ V_8 ] =
( F_3 ( V_5 [ V_8 ] ) << 12 ) & 0xf000 ;
#endif
}
#ifdef F_10
for ( ; V_8 < V_6 ; V_8 ++ ) {
V_16 -> V_27 [ V_8 ] =
( F_3 ( V_5 [ V_8 ] ) << 12 ) & 0xf000 ;
}
#endif
V_16 -> V_28 =
F_3 ( V_5 [ 0 ] ) | ( F_3 ( V_5 [ V_10 - 1 ] ) << 8 ) ;
F_9 ( V_16 -> V_28 , V_2 -> V_23 + V_24 ) ;
}
static int F_11 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_29 * V_30 ,
unsigned long V_31 )
{
unsigned int V_32 ;
V_32 = F_12 ( V_2 -> V_23 + V_33 ) ;
if ( ( V_32 & V_34 ) == 0 )
return 0 ;
return - V_35 ;
}
static int F_13 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_29 * V_30 , unsigned int * V_36 )
{
struct V_15 * V_16 = V_2 -> V_17 ;
int V_37 ;
int V_38 ;
#ifdef F_10
const struct V_13 * V_14 = F_8 ( V_2 ) ;
unsigned int V_39 ;
#endif
V_16 -> V_40 &= V_41 ;
V_16 -> V_40 |= V_42 ;
F_9 ( V_16 -> V_40 , V_2 -> V_23 + V_43 ) ;
F_14 ( 0 , V_2 -> V_23 + V_44 ) ;
F_14 ( 0 , V_2 -> V_23 + V_45 ) ;
F_7 ( V_2 , V_4 , & V_30 -> V_46 , 1 , 1 ) ;
for ( V_38 = 0 ; V_38 < V_30 -> V_38 ; V_38 ++ ) {
F_9 ( 0 , V_2 -> V_23 + V_47 ) ;
V_37 = F_15 ( V_2 , V_4 , V_30 , F_11 , 0 ) ;
if ( V_37 ) {
F_14 ( 0 , V_2 -> V_23 + V_44 ) ;
F_14 ( 0 , V_2 -> V_23 + V_45 ) ;
return V_37 ;
}
#ifdef F_10
V_39 = F_12 ( V_2 -> V_23 + V_48 ) ;
if ( V_14 -> V_49 != V_50 )
if ( ( V_39 & 0xf000 ) != V_16 -> V_27 [ 0 ] ) {
F_2 ( V_2 , L_5 ) ;
return - V_51 ;
}
V_36 [ V_38 ] = V_39 & 0x0fff ;
#else
V_36 [ V_38 ] = F_12 ( V_2 -> V_23 + V_48 ) & 0x0fff ;
#endif
}
F_14 ( 0 , V_2 -> V_23 + V_44 ) ;
F_14 ( 0 , V_2 -> V_23 + V_45 ) ;
return V_38 ;
}
static int F_16 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_29 * V_30 , unsigned int * V_36 )
{
struct V_15 * V_16 = V_2 -> V_17 ;
unsigned int V_52 ;
int V_38 , V_53 , V_18 , V_54 ;
V_53 = F_3 ( V_30 -> V_46 ) ;
V_18 = F_6 ( V_30 -> V_46 ) ;
if ( V_53 ) {
V_16 -> V_55 &= 0xfb ;
V_16 -> V_55 |= ( V_18 << 2 ) ;
F_9 ( V_16 -> V_55 , V_2 -> V_23 + V_56 ) ;
V_54 = V_57 ;
} else {
V_16 -> V_55 &= 0xfe ;
V_16 -> V_55 |= V_18 ;
F_9 ( V_16 -> V_55 , V_2 -> V_23 + V_56 ) ;
V_54 = V_58 ;
}
V_52 = V_16 -> V_59 [ V_53 ] ;
for ( V_38 = 0 ; V_38 < V_30 -> V_38 ; V_38 ++ ) {
V_52 = V_36 [ V_38 ] ;
F_9 ( V_52 , V_2 -> V_23 + V_54 ) ;
}
V_16 -> V_59 [ V_53 ] = V_52 ;
return V_38 ;
}
static int F_17 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_29 * V_30 , unsigned int * V_36 )
{
struct V_15 * V_16 = V_2 -> V_17 ;
int V_38 , V_53 ;
V_53 = F_3 ( V_30 -> V_46 ) ;
for ( V_38 = 0 ; V_38 < V_30 -> V_38 ; V_38 ++ )
V_36 [ V_38 ] = V_16 -> V_59 [ V_53 ] ;
return V_38 ;
}
static int F_18 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_29 * V_30 , unsigned int * V_36 )
{
V_36 [ 1 ] = F_12 ( V_2 -> V_23 + V_60 ) ;
return V_30 -> V_38 ;
}
static int F_19 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_29 * V_30 ,
unsigned int * V_36 )
{
if ( F_20 ( V_4 , V_36 ) )
F_9 ( V_4 -> V_61 , V_2 -> V_23 + V_62 ) ;
V_36 [ 1 ] = V_4 -> V_61 ;
return V_30 -> V_38 ;
}
static void F_21 ( struct V_1 * V_2 , int V_63 ,
unsigned int V_64 , unsigned int V_65 )
{
F_9 ( 0xb4 , V_2 -> V_23 + V_66 ) ;
F_9 ( 0x74 , V_2 -> V_23 + V_66 ) ;
if ( V_63 == 1 ) {
F_9 ( V_65 & 0xff , V_2 -> V_23 + V_67 ) ;
F_9 ( ( V_65 >> 8 ) & 0xff , V_2 -> V_23 + V_67 ) ;
F_9 ( V_64 & 0xff , V_2 -> V_23 + V_68 ) ;
F_9 ( ( V_64 >> 8 ) & 0xff , V_2 -> V_23 + V_68 ) ;
}
}
static int F_22 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_29 * V_30 ,
unsigned int * V_36 )
{
unsigned int V_69 , V_70 , V_71 ;
int V_8 ;
V_71 = 0xD2 ;
for ( V_8 = 0 ; V_8 < V_30 -> V_38 ; V_8 ++ ) {
F_9 ( V_71 , V_2 -> V_23 + V_66 ) ;
V_70 = F_12 ( V_2 -> V_23 + V_72 ) & 0xFF ;
V_69 = F_12 ( V_2 -> V_23 + V_72 ) & 0xFF ;
V_36 [ 0 ] = V_70 | ( V_69 << 8 ) ;
}
return V_30 -> V_38 ;
}
static int F_23 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_29 * V_30 ,
unsigned int * V_36 )
{
struct V_15 * V_16 = V_2 -> V_17 ;
T_1 V_69 , V_70 , V_71 , V_32 ;
V_70 = V_36 [ 0 ] & 0x00FF ;
V_69 = ( V_36 [ 0 ] & 0xFF00 ) >> 8 ;
F_9 ( V_70 , V_2 -> V_23 + V_72 ) ;
F_9 ( V_69 , V_2 -> V_23 + V_72 ) ;
if ( V_16 -> V_73 ) {
V_71 = 0xE2 ;
do {
F_9 ( V_71 , V_2 -> V_23 + V_66 ) ;
V_32 = F_12 ( V_2 -> V_23 + V_72 ) & 0xFF ;
} while ( V_32 & 0x40 );
}
return V_30 -> V_38 ;
}
static int F_24 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_29 * V_30 ,
unsigned int * V_36 )
{
#ifdef F_25
struct V_15 * V_16 = V_2 -> V_17 ;
T_1 V_71 = 0 ;
V_16 -> V_73 = V_36 [ 0 ] & 0x20 ;
if ( ! ( V_36 [ 0 ] & 0x10 ) ) {
V_16 -> V_40 &= ~ V_41 ;
} else {
V_16 -> V_40 |= V_41 ;
}
F_9 ( V_16 -> V_40 , V_2 -> V_23 + V_43 ) ;
if ( V_36 [ 0 ] & 0x01 )
V_71 |= V_74 ;
if ( V_36 [ 0 ] & 0x02 )
V_71 |= V_75 ;
if ( V_36 [ 0 ] & 0x04 )
V_71 |= V_76 ;
if ( V_36 [ 0 ] & 0x08 )
V_71 |= V_77 ;
V_71 |= V_78 ;
V_71 |= V_79 ;
F_9 ( V_71 , V_2 -> V_23 + V_66 ) ;
#endif
return 1 ;
}
static int F_26 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_29 * V_30 , unsigned int * V_36 )
{
struct V_15 * V_16 = V_2 -> V_17 ;
unsigned int V_52 ;
int V_38 , V_80 , V_53 ;
V_53 = F_3 ( V_30 -> V_46 ) ;
V_80 = V_16 -> V_55 & ( ~ ( 0x03 << ( V_53 << 1 ) ) ) ;
V_80 |= ( F_6 ( V_30 -> V_46 ) << ( V_53 << 1 ) ) ;
if ( V_80 != V_16 -> V_55 ) {
F_14 ( V_80 , V_2 -> V_23 + V_81 ) ;
V_16 -> V_55 = V_80 ;
}
V_52 = V_16 -> V_59 [ V_53 ] ;
for ( V_38 = 0 ; V_38 < V_30 -> V_38 ; V_38 ++ ) {
V_52 = V_36 [ V_38 ] ;
F_9 ( V_52 , V_2 -> V_23 + V_82 + ( V_53 << 1 ) ) ;
F_14 ( 0 , V_2 -> V_23 + V_83 ) ;
}
V_16 -> V_59 [ V_53 ] = V_52 ;
return V_38 ;
}
static int F_27 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
const struct V_13 * V_14 = F_8 ( V_2 ) ;
struct V_15 * V_16 = V_2 -> V_17 ;
switch ( V_14 -> V_49 ) {
default:
V_16 -> V_40 &= V_41 ;
V_16 -> V_40 |= V_42 ;
F_9 ( V_16 -> V_40 , V_2 -> V_23 + V_43 ) ;
F_21 ( V_2 , - 1 , 0 , 0 ) ;
F_14 ( 0 , V_2 -> V_23 + V_44 ) ;
F_14 ( 0 , V_2 -> V_23 + V_45 ) ;
break;
}
V_16 -> V_84 = 0 ;
V_16 -> V_85 = 0 ;
V_4 -> V_86 -> V_87 = 0 ;
V_16 -> V_88 = 0 ;
V_16 -> V_89 = 0 ;
return 0 ;
}
static void F_28 ( void * V_90 )
{
struct V_1 * V_2 = V_90 ;
struct V_15 * V_16 = V_2 -> V_17 ;
struct V_3 * V_4 = V_2 -> V_91 ;
int V_92 ;
#ifdef F_10
const struct V_13 * V_14 = F_8 ( V_2 ) ;
unsigned short V_93 ;
#endif
V_92 = F_12 ( V_2 -> V_23 + V_33 ) ;
if ( V_92 & V_34 ) {
F_29 ( V_2 -> V_94 , L_6 , V_92 ) ;
V_4 -> V_86 -> V_95 |= V_96 | V_97 ;
F_30 ( V_2 , V_4 ) ;
return;
}
if ( V_92 & V_98 ) {
F_29 ( V_2 -> V_94 ,
L_7 , V_92 ) ;
V_4 -> V_86 -> V_95 |= V_96 | V_97 ;
F_30 ( V_2 , V_4 ) ;
return;
}
F_14 ( 0 , V_2 -> V_23 + V_45 ) ;
for (; ! ( F_12 ( V_2 -> V_23 + V_33 ) & V_34 ) ; ) {
#ifdef F_10
V_93 = F_12 ( V_2 -> V_23 + V_48 ) ;
if ( V_14 -> V_49 != V_50 )
if ( ( V_93 & 0xf000 ) !=
V_16 -> V_27 [ V_4 -> V_86 -> V_87 ] ) {
F_5
( L_8 ,
( V_93 & 0xf000 ) >> 12 ,
( V_16 ->
V_27 [ V_4 ->
V_86 -> V_87 ] & 0xf000 ) >>
12 ) ;
V_4 -> V_86 -> V_95 |=
V_96 | V_97 ;
F_30 ( V_2 , V_4 ) ;
return;
}
F_31 ( V_4 -> V_86 , V_93 & 0x0fff ) ;
#else
F_31 ( V_4 -> V_86 ,
F_12 ( V_2 -> V_23 + V_48 ) & 0x0fff ) ;
#endif
++ V_4 -> V_86 -> V_87 ;
if ( V_4 -> V_86 -> V_87 >= V_16 -> V_99 )
V_4 -> V_86 -> V_87 = 0 ;
if ( V_4 -> V_86 -> V_87 == 0 ) {
V_16 -> V_85 ++ ;
if ( ( ! V_16 -> V_89 ) &&
( V_16 -> V_85 >= V_16 -> V_100 ) ) {
V_4 -> V_86 -> V_95 |= V_96 ;
F_30 ( V_2 , V_4 ) ;
return;
}
}
}
F_14 ( 0 , V_2 -> V_23 + V_45 ) ;
F_30 ( V_2 , V_4 ) ;
}
static int F_32 ( struct V_1 * V_2 ,
struct V_3 * V_4 , int V_38 , int V_101 )
{
struct V_15 * V_16 = V_2 -> V_17 ;
int V_8 , V_102 ;
#ifdef F_10
const struct V_13 * V_14 = F_8 ( V_2 ) ;
unsigned short V_93 ;
#endif
V_102 = V_4 -> V_86 -> V_87 ;
for ( V_8 = 0 ; V_8 < V_38 ; V_8 ++ ) {
#ifdef F_10
V_93 = F_12 ( V_2 -> V_23 + V_48 ) ;
if ( V_14 -> V_49 != V_50 )
if ( ( V_93 & 0xf000 ) != V_16 -> V_27 [ V_102 ] ) {
F_29 ( V_2 -> V_94 ,
L_9 ,
( V_93 & 0xf000 ) >> 12 ,
( V_16 -> V_27 [ V_102 ] & 0xf000 ) >> 12 ,
V_8 , V_102 , V_16 -> V_85 , V_38 , V_101 ,
V_93 ) ;
V_4 -> V_86 -> V_95 |=
V_96 | V_97 ;
F_30 ( V_2 , V_4 ) ;
return 1 ;
}
F_31 ( V_4 -> V_86 , V_93 & 0x0fff ) ;
#else
F_31 ( V_4 -> V_86 ,
F_12 ( V_2 -> V_23 + V_48 ) & 0x0fff ) ;
#endif
V_102 ++ ;
if ( V_102 >= V_16 -> V_99 ) {
V_102 = 0 ;
V_16 -> V_85 ++ ;
}
}
V_4 -> V_86 -> V_87 = V_102 ;
return 0 ;
}
static void F_33 ( void * V_90 )
{
struct V_1 * V_2 = V_90 ;
const struct V_13 * V_14 = F_8 ( V_2 ) ;
struct V_15 * V_16 = V_2 -> V_17 ;
struct V_3 * V_4 = V_2 -> V_91 ;
int V_92 , V_103 ;
V_92 = F_12 ( V_2 -> V_23 + V_33 ) ;
if ( ! ( V_92 & V_104 ) ) {
F_29 ( V_2 -> V_94 , L_10 , V_92 ) ;
V_4 -> V_86 -> V_95 |= V_96 | V_97 ;
F_30 ( V_2 , V_4 ) ;
return;
}
if ( V_92 & V_98 ) {
F_29 ( V_2 -> V_94 ,
L_7 , V_92 ) ;
V_4 -> V_86 -> V_95 |= V_96 | V_97 ;
F_30 ( V_2 , V_4 ) ;
return;
}
V_103 = V_14 -> V_105 ;
if ( V_103 * sizeof( short ) >= V_16 -> V_106 ) {
V_92 = V_16 -> V_106 / sizeof( short ) ;
if ( F_32 ( V_2 , V_4 , V_92 , 0 ) )
return;
V_103 -= V_92 ;
}
if ( V_103 ) {
if ( F_32 ( V_2 , V_4 , V_103 , 1 ) )
return;
}
if ( ! V_16 -> V_89 )
if ( V_16 -> V_85 >= V_16 -> V_100 ) {
V_4 -> V_86 -> V_95 |= V_96 ;
F_30 ( V_2 , V_4 ) ;
return;
}
F_14 ( 0 , V_2 -> V_23 + V_45 ) ;
F_30 ( V_2 , V_4 ) ;
}
static T_2 F_34 ( int V_107 , void * V_90 )
{
struct V_1 * V_2 = V_90 ;
struct V_15 * V_16 = V_2 -> V_17 ;
if ( ! V_2 -> V_108 )
return V_109 ;
if ( ! ( F_12 ( V_2 -> V_23 + V_33 ) & V_110 ) )
return V_109 ;
if ( V_16 -> V_111 ) {
V_16 -> V_111 = 0 ;
V_16 -> V_40 &= V_41 ;
V_16 -> V_40 |= V_42 ;
F_9 ( V_16 -> V_40 , V_2 -> V_23 + V_43 ) ;
V_16 -> V_40 = V_16 -> V_112 ;
F_14 ( 0 , V_2 -> V_23 + V_44 ) ;
F_14 ( 0 , V_2 -> V_23 + V_45 ) ;
F_9 ( V_16 -> V_28 , V_2 -> V_23 + V_24 ) ;
F_9 ( V_16 -> V_40 , V_2 -> V_23 + V_43 ) ;
F_21 ( V_2 , 1 , V_16 -> V_113 , V_16 -> V_114 ) ;
return V_115 ;
}
if ( V_16 -> V_116 ) {
F_28 ( V_90 ) ;
} else {
F_33 ( V_90 ) ;
}
return V_115 ;
}
static int F_35 ( int V_63 , struct V_1 * V_2 ,
struct V_3 * V_4 )
{
const struct V_13 * V_14 = F_8 ( V_2 ) ;
struct V_15 * V_16 = V_2 -> V_17 ;
unsigned int V_64 = 0 , V_65 = 0 ;
unsigned int V_10 ;
F_21 ( V_2 , - 1 , 0 , 0 ) ;
V_10 = F_1 ( V_2 , V_4 , V_16 -> V_117 ,
V_16 -> V_99 ) ;
if ( V_10 < 1 )
return - V_118 ;
F_7 ( V_2 , V_4 , V_16 -> V_117 ,
V_16 -> V_99 , V_10 ) ;
F_14 ( 0 , V_2 -> V_23 + V_44 ) ;
F_14 ( 0 , V_2 -> V_23 + V_45 ) ;
V_16 -> V_84 = V_63 ;
V_16 -> V_85 = 0 ;
V_4 -> V_86 -> V_87 = 0 ;
V_16 -> V_88 = 0 ;
V_16 -> V_89 = 0 ;
V_16 -> V_40 &= V_41 ;
if ( ( V_16 -> V_119 & V_120 ) ) {
V_16 -> V_116 = 1 ;
} else {
V_16 -> V_40 |= V_121 ;
V_16 -> V_116 = 0 ;
}
if ( ( V_16 -> V_100 == 0 ) || ( V_16 -> V_100 == - 1 ) )
V_16 -> V_89 = 1 ;
else
V_16 -> V_89 = 0 ;
switch ( V_63 ) {
case 1 :
case 2 :
if ( V_16 -> V_122 < V_14 -> V_123 )
V_16 -> V_122 = V_14 -> V_123 ;
V_16 -> V_40 |= V_124 | V_125 ;
if ( V_63 == 2 ) {
V_16 -> V_112 = V_16 -> V_40 ;
V_16 -> V_40 &=
~ ( V_124 | V_121 | V_126 ) ;
V_16 -> V_40 |= V_127 ;
V_16 -> V_111 = 1 ;
} else {
V_16 -> V_111 = 0 ;
}
F_36 ( V_16 -> V_128 ,
& V_64 , & V_65 ,
& V_16 -> V_122 ,
V_16 -> V_119 ) ;
F_9 ( V_16 -> V_40 , V_2 -> V_23 + V_43 ) ;
if ( V_63 != 2 ) {
F_21 ( V_2 , V_63 , V_64 , V_65 ) ;
} else {
V_16 -> V_113 = V_64 ;
V_16 -> V_114 = V_65 ;
}
break;
case 3 :
V_16 -> V_40 |= V_127 | V_125 ;
F_9 ( V_16 -> V_40 , V_2 -> V_23 + V_43 ) ;
break;
}
return 0 ;
}
static int F_37 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_129 * V_130 )
{
const struct V_13 * V_14 = F_8 ( V_2 ) ;
struct V_15 * V_16 = V_2 -> V_17 ;
int V_131 = 0 ;
int V_132 ;
unsigned int V_64 = 0 , V_65 = 0 ;
V_131 |= F_38 ( & V_130 -> V_133 , V_134 | V_135 ) ;
V_131 |= F_38 ( & V_130 -> V_136 , V_137 ) ;
V_131 |= F_38 ( & V_130 -> V_138 , V_139 | V_135 ) ;
V_131 |= F_38 ( & V_130 -> V_140 , V_141 ) ;
V_131 |= F_38 ( & V_130 -> V_142 , V_141 | V_143 ) ;
if ( V_131 )
return 1 ;
V_131 |= F_39 ( V_130 -> V_133 ) ;
V_131 |= F_39 ( V_130 -> V_138 ) ;
V_131 |= F_39 ( V_130 -> V_142 ) ;
if ( V_131 )
return 2 ;
V_131 |= F_40 ( & V_130 -> V_144 , 0 ) ;
V_131 |= F_40 ( & V_130 -> V_145 , 0 ) ;
if ( V_130 -> V_138 == V_139 )
V_131 |= F_41 ( & V_130 -> V_146 ,
V_14 -> V_123 ) ;
else
V_131 |= F_40 ( & V_130 -> V_146 , 0 ) ;
V_131 |= F_40 ( & V_130 -> V_147 , V_130 -> V_148 ) ;
if ( V_130 -> V_142 == V_141 )
V_131 |= F_41 ( & V_130 -> V_149 , 1 ) ;
else
V_131 |= F_40 ( & V_130 -> V_149 , 0 ) ;
if ( V_131 )
return 3 ;
if ( V_130 -> V_138 == V_139 ) {
V_132 = V_130 -> V_146 ;
F_36 ( V_16 -> V_128 ,
& V_64 , & V_65 ,
& V_130 -> V_146 , V_130 -> V_150 ) ;
if ( V_130 -> V_146 < V_14 -> V_123 )
V_130 -> V_146 = V_14 -> V_123 ;
if ( V_132 != V_130 -> V_146 )
V_131 ++ ;
}
if ( V_131 )
return 4 ;
if ( V_130 -> V_5 ) {
if ( ! F_1 ( V_2 , V_4 , V_130 -> V_5 ,
V_130 -> V_148 ) )
return 5 ;
}
return 0 ;
}
static int F_42 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_15 * V_16 = V_2 -> V_17 ;
struct V_129 * V_130 = & V_4 -> V_86 -> V_130 ;
V_16 -> V_99 = V_130 -> V_148 ;
V_16 -> V_117 = V_130 -> V_5 ;
V_16 -> V_119 = V_130 -> V_150 ;
V_16 -> V_106 = V_4 -> V_86 -> V_151 ;
V_16 -> V_122 = 0 ;
V_16 -> V_152 = 0 ;
if ( V_130 -> V_142 == V_141 )
V_16 -> V_100 = V_130 -> V_149 ;
else
V_16 -> V_100 = 0 ;
if ( V_130 -> V_136 == V_137 ) {
if ( V_130 -> V_138 == V_139 ) {
V_16 -> V_122 = V_130 -> V_146 ;
return F_35 ( V_130 -> V_133 ==
V_135 ? 2 : 1 , V_2 ,
V_4 ) ;
}
if ( V_130 -> V_138 == V_135 ) {
return F_35 ( 3 , V_2 , V_4 ) ;
}
}
return - 1 ;
}
static int F_43 ( struct V_1 * V_2 )
{
const struct V_13 * V_14 = F_8 ( V_2 ) ;
struct V_15 * V_16 = V_2 -> V_17 ;
F_9 ( 0x30 , V_2 -> V_23 + V_66 ) ;
V_16 -> V_40 = V_42 | V_41 ;
F_9 ( V_16 -> V_40 , V_2 -> V_23 + V_43 ) ;
F_14 ( 0 , V_2 -> V_23 + V_44 ) ;
F_14 ( 0 , V_2 -> V_23 + V_45 ) ;
F_21 ( V_2 , - 1 , 0 , 0 ) ;
V_16 -> V_55 = 0 ;
if ( V_14 -> V_153 ) {
F_14 ( V_16 -> V_55 , V_2 -> V_23 + V_56 ) ;
F_9 ( 0 , V_2 -> V_23 + V_58 ) ;
V_16 -> V_59 [ 0 ] = 0x0000 ;
if ( V_14 -> V_153 > 1 ) {
F_9 ( 0 , V_2 -> V_23 + V_57 ) ;
V_16 -> V_59 [ 1 ] = 0x0000 ;
}
}
F_9 ( 0 , V_2 -> V_23 + V_62 ) ;
F_14 ( 0 , V_2 -> V_23 + V_44 ) ;
F_14 ( 0 , V_2 -> V_23 + V_45 ) ;
return 0 ;
}
static int F_44 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_17 ;
F_14 ( V_154 , V_2 -> V_23 + V_155 ) ;
V_16 -> V_55 = 0xAA ;
F_14 ( V_16 -> V_55 , V_2 -> V_23 + V_81 ) ;
F_9 ( 0x0800 , V_2 -> V_23 + V_82 ) ;
F_9 ( 0x0800 , V_2 -> V_23 + V_156 ) ;
F_9 ( 0x0800 , V_2 -> V_23 + V_157 ) ;
F_9 ( 0x0800 , V_2 -> V_23 + V_158 ) ;
F_14 ( 0 , V_2 -> V_23 + V_83 ) ;
V_16 -> V_59 [ 0 ] = 0x0800 ;
V_16 -> V_59 [ 1 ] = 0x0800 ;
V_16 -> V_59 [ 2 ] = 0x0800 ;
V_16 -> V_59 [ 3 ] = 0x0800 ;
return 0 ;
}
static int F_45 ( struct V_1 * V_2 )
{
const struct V_13 * V_14 = F_8 ( V_2 ) ;
switch ( V_14 -> V_49 ) {
case V_159 :
return F_44 ( V_2 ) ;
default:
return F_43 ( V_2 ) ;
}
}
static int F_46 ( struct V_1 * V_2 ,
unsigned long V_31 )
{
struct V_160 * V_161 = F_47 ( V_2 ) ;
const struct V_13 * V_14 = NULL ;
struct V_15 * V_16 ;
struct V_3 * V_4 ;
int V_37 , V_162 , V_163 ;
if ( V_31 < F_48 ( V_164 ) )
V_14 = & V_164 [ V_31 ] ;
if ( ! V_14 )
return - V_165 ;
V_2 -> V_166 = V_14 ;
V_2 -> V_167 = V_14 -> V_168 ;
V_16 = F_49 ( V_2 , sizeof( * V_16 ) ) ;
if ( ! V_16 )
return - V_169 ;
V_37 = F_50 ( V_2 ) ;
if ( V_37 )
return V_37 ;
V_2 -> V_23 = F_51 ( V_161 , 2 ) ;
V_163 = 0 ;
if ( V_14 -> V_170 )
V_163 ++ ;
if ( V_14 -> V_153 )
V_163 ++ ;
if ( V_14 -> V_171 )
V_163 ++ ;
if ( V_14 -> V_172 )
V_163 ++ ;
if ( V_14 -> V_173 )
V_163 ++ ;
V_37 = F_52 ( V_2 , V_163 ) ;
if ( V_37 )
return V_37 ;
F_45 ( V_2 ) ;
if ( V_14 -> V_174 && V_161 -> V_107 ) {
V_37 = F_53 ( V_161 -> V_107 , F_34 ,
V_175 , V_2 -> V_167 , V_2 ) ;
if ( V_37 == 0 )
V_2 -> V_107 = V_161 -> V_107 ;
}
V_162 = 0 ;
if ( V_14 -> V_170 ) {
V_4 = & V_2 -> V_176 [ V_162 ] ;
V_4 -> type = V_177 ;
V_4 -> V_178 = V_179 | V_180 | V_181 ;
if ( V_14 -> V_182 )
V_4 -> V_178 |= V_183 ;
V_4 -> V_6 = V_14 -> V_170 ;
V_4 -> V_184 = V_14 -> V_185 ;
V_4 -> V_186 = V_14 -> V_187 ;
V_4 -> V_188 = F_13 ;
if ( V_2 -> V_107 ) {
V_2 -> V_91 = V_4 ;
V_4 -> V_178 |= V_189 ;
V_4 -> V_190 = V_4 -> V_6 ;
V_4 -> V_191 = F_37 ;
V_4 -> V_192 = F_42 ;
V_4 -> V_193 = F_27 ;
}
V_16 -> V_128 = V_194 ;
V_162 ++ ;
}
if ( V_14 -> V_153 ) {
V_4 = & V_2 -> V_176 [ V_162 ] ;
V_4 -> type = V_195 ;
V_4 -> V_178 = V_196 | V_181 | V_180 ;
V_4 -> V_6 = V_14 -> V_153 ;
V_4 -> V_184 = V_14 -> V_197 ;
V_4 -> V_190 = V_14 -> V_153 ;
V_4 -> V_186 = V_14 -> V_198 ;
switch ( V_14 -> V_49 ) {
case V_159 :
V_4 -> V_199 = F_26 ;
break;
default:
V_4 -> V_199 = F_16 ;
break;
}
V_4 -> V_188 = F_17 ;
V_162 ++ ;
}
if ( V_14 -> V_171 ) {
V_4 = & V_2 -> V_176 [ V_162 ] ;
V_4 -> type = V_200 ;
V_4 -> V_178 = V_179 | V_181 | V_180 ;
V_4 -> V_6 = V_14 -> V_171 ;
V_4 -> V_184 = 1 ;
V_4 -> V_190 = V_14 -> V_171 ;
V_4 -> V_186 = & V_201 ;
V_4 -> V_202 = F_18 ;
V_162 ++ ;
}
if ( V_14 -> V_172 ) {
V_4 = & V_2 -> V_176 [ V_162 ] ;
V_4 -> type = V_203 ;
V_4 -> V_178 = V_196 | V_181 | V_180 ;
V_4 -> V_6 = V_14 -> V_172 ;
V_4 -> V_184 = 1 ;
V_4 -> V_190 = V_14 -> V_172 ;
V_4 -> V_186 = & V_201 ;
V_4 -> V_202 = F_19 ;
V_162 ++ ;
}
if ( V_14 -> V_173 ) {
V_4 = & V_2 -> V_176 [ V_162 ] ;
V_4 -> type = V_204 ;
V_4 -> V_178 = V_179 | V_196 ;
V_4 -> V_6 = V_14 -> V_173 ;
V_4 -> V_190 = V_14 -> V_173 ;
V_4 -> V_184 = 0xffff ;
V_4 -> V_186 = & V_205 ;
V_4 -> V_188 = F_22 ;
V_4 -> V_199 = F_23 ;
V_4 -> V_206 = F_24 ;
V_162 ++ ;
}
return 0 ;
}
static void F_54 ( struct V_1 * V_2 )
{
if ( V_2 -> V_23 )
F_45 ( V_2 ) ;
if ( V_2 -> V_107 )
F_55 ( V_2 -> V_107 , V_2 ) ;
F_56 ( V_2 ) ;
}
static int F_57 ( struct V_160 * V_2 ,
const struct V_207 * V_208 )
{
return F_58 ( V_2 , & V_209 ,
V_208 -> V_210 ) ;
}
