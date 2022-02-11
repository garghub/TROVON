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
struct V_29 * V_30 , unsigned int * V_31 )
{
struct V_15 * V_16 = V_2 -> V_17 ;
int V_32 , V_33 ;
#ifdef F_10
const struct V_13 * V_14 = F_8 ( V_2 ) ;
unsigned int V_34 ;
#endif
V_16 -> V_35 &= V_36 ;
V_16 -> V_35 |= V_37 ;
F_9 ( V_16 -> V_35 , V_2 -> V_23 + V_38 ) ;
F_12 ( 0 , V_2 -> V_23 + V_39 ) ;
F_12 ( 0 , V_2 -> V_23 + V_40 ) ;
F_7 ( V_2 , V_4 , & V_30 -> V_41 , 1 , 1 ) ;
for ( V_32 = 0 ; V_32 < V_30 -> V_32 ; V_32 ++ ) {
F_9 ( 0 , V_2 -> V_23 + V_42 ) ;
V_33 = 100 ;
while ( V_33 -- ) {
if ( ! ( F_13 ( V_2 -> V_23 + V_43 ) & V_44 ) )
goto V_45;
}
F_2 ( V_2 , L_5 ) ;
F_12 ( 0 , V_2 -> V_23 + V_39 ) ;
F_12 ( 0 , V_2 -> V_23 + V_40 ) ;
V_31 [ V_32 ] = 0 ;
return - V_46 ;
V_45:
#ifdef F_10
V_34 = F_13 ( V_2 -> V_23 + V_47 ) ;
if ( V_14 -> V_48 != V_49 )
if ( ( V_34 & 0xf000 ) != V_16 -> V_27 [ 0 ] ) {
F_2 ( V_2 , L_6 ) ;
return - V_46 ;
}
V_31 [ V_32 ] = V_34 & 0x0fff ;
#else
V_31 [ V_32 ] = F_13 ( V_2 -> V_23 + V_47 ) & 0x0fff ;
#endif
}
F_12 ( 0 , V_2 -> V_23 + V_39 ) ;
F_12 ( 0 , V_2 -> V_23 + V_40 ) ;
return V_32 ;
}
static int F_14 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_29 * V_30 , unsigned int * V_31 )
{
struct V_15 * V_16 = V_2 -> V_17 ;
unsigned int V_50 ;
int V_32 , V_51 , V_18 , V_52 ;
V_51 = F_3 ( V_30 -> V_41 ) ;
V_18 = F_6 ( V_30 -> V_41 ) ;
if ( V_51 ) {
V_16 -> V_53 &= 0xfb ;
V_16 -> V_53 |= ( V_18 << 2 ) ;
F_9 ( V_16 -> V_53 , V_2 -> V_23 + V_54 ) ;
V_52 = V_55 ;
} else {
V_16 -> V_53 &= 0xfe ;
V_16 -> V_53 |= V_18 ;
F_9 ( V_16 -> V_53 , V_2 -> V_23 + V_54 ) ;
V_52 = V_56 ;
}
V_50 = V_16 -> V_57 [ V_51 ] ;
for ( V_32 = 0 ; V_32 < V_30 -> V_32 ; V_32 ++ ) {
V_50 = V_31 [ V_32 ] ;
F_9 ( V_50 , V_2 -> V_23 + V_52 ) ;
}
V_16 -> V_57 [ V_51 ] = V_50 ;
return V_32 ;
}
static int F_15 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_29 * V_30 , unsigned int * V_31 )
{
struct V_15 * V_16 = V_2 -> V_17 ;
int V_32 , V_51 ;
V_51 = F_3 ( V_30 -> V_41 ) ;
for ( V_32 = 0 ; V_32 < V_30 -> V_32 ; V_32 ++ )
V_31 [ V_32 ] = V_16 -> V_57 [ V_51 ] ;
return V_32 ;
}
static int F_16 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_29 * V_30 , unsigned int * V_31 )
{
V_31 [ 1 ] = F_13 ( V_2 -> V_23 + V_58 ) ;
return V_30 -> V_32 ;
}
static int F_17 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_29 * V_30 ,
unsigned int * V_31 )
{
if ( F_18 ( V_4 , V_31 ) )
F_9 ( V_4 -> V_59 , V_2 -> V_23 + V_60 ) ;
V_31 [ 1 ] = V_4 -> V_59 ;
return V_30 -> V_32 ;
}
static void F_19 ( struct V_1 * V_2 , int V_61 ,
unsigned int V_62 , unsigned int V_63 )
{
F_9 ( 0xb4 , V_2 -> V_23 + V_64 ) ;
F_9 ( 0x74 , V_2 -> V_23 + V_64 ) ;
if ( V_61 == 1 ) {
F_9 ( V_63 & 0xff , V_2 -> V_23 + V_65 ) ;
F_9 ( ( V_63 >> 8 ) & 0xff , V_2 -> V_23 + V_65 ) ;
F_9 ( V_62 & 0xff , V_2 -> V_23 + V_66 ) ;
F_9 ( ( V_62 >> 8 ) & 0xff , V_2 -> V_23 + V_66 ) ;
}
}
static int F_20 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_29 * V_30 ,
unsigned int * V_31 )
{
unsigned int V_67 , V_68 , V_69 ;
int V_8 ;
V_69 = 0xD2 ;
for ( V_8 = 0 ; V_8 < V_30 -> V_32 ; V_8 ++ ) {
F_9 ( V_69 , V_2 -> V_23 + V_64 ) ;
V_68 = F_13 ( V_2 -> V_23 + V_70 ) & 0xFF ;
V_67 = F_13 ( V_2 -> V_23 + V_70 ) & 0xFF ;
V_31 [ 0 ] = V_68 | ( V_67 << 8 ) ;
}
return V_30 -> V_32 ;
}
static int F_21 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_29 * V_30 ,
unsigned int * V_31 )
{
struct V_15 * V_16 = V_2 -> V_17 ;
T_1 V_67 , V_68 , V_69 , V_71 ;
V_68 = V_31 [ 0 ] & 0x00FF ;
V_67 = ( V_31 [ 0 ] & 0xFF00 ) >> 8 ;
F_9 ( V_68 , V_2 -> V_23 + V_70 ) ;
F_9 ( V_67 , V_2 -> V_23 + V_70 ) ;
if ( V_16 -> V_72 ) {
V_69 = 0xE2 ;
do {
F_9 ( V_69 , V_2 -> V_23 + V_64 ) ;
V_71 = F_13 ( V_2 -> V_23 + V_70 ) & 0xFF ;
} while ( V_71 & 0x40 );
}
return V_30 -> V_32 ;
}
static int F_22 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_29 * V_30 ,
unsigned int * V_31 )
{
#ifdef F_23
struct V_15 * V_16 = V_2 -> V_17 ;
T_1 V_69 = 0 ;
V_16 -> V_72 = V_31 [ 0 ] & 0x20 ;
if ( ! ( V_31 [ 0 ] & 0x10 ) ) {
V_16 -> V_35 &= ~ V_36 ;
} else {
V_16 -> V_35 |= V_36 ;
}
F_9 ( V_16 -> V_35 , V_2 -> V_23 + V_38 ) ;
if ( V_31 [ 0 ] & 0x01 )
V_69 |= V_73 ;
if ( V_31 [ 0 ] & 0x02 )
V_69 |= V_74 ;
if ( V_31 [ 0 ] & 0x04 )
V_69 |= V_75 ;
if ( V_31 [ 0 ] & 0x08 )
V_69 |= V_76 ;
V_69 |= V_77 ;
V_69 |= V_78 ;
F_9 ( V_69 , V_2 -> V_23 + V_64 ) ;
#endif
return 1 ;
}
static int F_24 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_29 * V_30 , unsigned int * V_31 )
{
struct V_15 * V_16 = V_2 -> V_17 ;
unsigned int V_50 ;
int V_32 , V_79 , V_51 ;
V_51 = F_3 ( V_30 -> V_41 ) ;
V_79 = V_16 -> V_53 & ( ~ ( 0x03 << ( V_51 << 1 ) ) ) ;
V_79 |= ( F_6 ( V_30 -> V_41 ) << ( V_51 << 1 ) ) ;
if ( V_79 != V_16 -> V_53 ) {
F_12 ( V_79 , V_2 -> V_23 + V_80 ) ;
V_16 -> V_53 = V_79 ;
}
V_50 = V_16 -> V_57 [ V_51 ] ;
for ( V_32 = 0 ; V_32 < V_30 -> V_32 ; V_32 ++ ) {
V_50 = V_31 [ V_32 ] ;
F_9 ( V_50 , V_2 -> V_23 + V_81 + ( V_51 << 1 ) ) ;
F_12 ( 0 , V_2 -> V_23 + V_82 ) ;
}
V_16 -> V_57 [ V_51 ] = V_50 ;
return V_32 ;
}
static int F_25 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
const struct V_13 * V_14 = F_8 ( V_2 ) ;
struct V_15 * V_16 = V_2 -> V_17 ;
switch ( V_14 -> V_48 ) {
default:
V_16 -> V_35 &= V_36 ;
V_16 -> V_35 |= V_37 ;
F_9 ( V_16 -> V_35 , V_2 -> V_23 + V_38 ) ;
F_19 ( V_2 , - 1 , 0 , 0 ) ;
F_12 ( 0 , V_2 -> V_23 + V_39 ) ;
F_12 ( 0 , V_2 -> V_23 + V_40 ) ;
break;
}
V_16 -> V_83 = 0 ;
V_16 -> V_84 = 0 ;
V_4 -> V_85 -> V_86 = 0 ;
V_16 -> V_87 = 0 ;
V_16 -> V_88 = 0 ;
return 0 ;
}
static void F_26 ( void * V_89 )
{
struct V_1 * V_2 = V_89 ;
struct V_15 * V_16 = V_2 -> V_17 ;
struct V_3 * V_4 = V_2 -> V_90 ;
int V_91 ;
#ifdef F_10
const struct V_13 * V_14 = F_8 ( V_2 ) ;
unsigned short V_92 ;
#endif
V_91 = F_13 ( V_2 -> V_23 + V_43 ) ;
if ( V_91 & V_44 ) {
F_27 ( V_2 -> V_93 , L_7 , V_91 ) ;
F_25 ( V_2 , V_4 ) ;
V_4 -> V_85 -> V_94 |= V_95 | V_96 ;
F_28 ( V_2 , V_4 ) ;
return;
}
if ( V_91 & V_97 ) {
F_27 ( V_2 -> V_93 ,
L_8 , V_91 ) ;
F_25 ( V_2 , V_4 ) ;
V_4 -> V_85 -> V_94 |= V_95 | V_96 ;
F_28 ( V_2 , V_4 ) ;
return;
}
F_12 ( 0 , V_2 -> V_23 + V_40 ) ;
for (; ! ( F_13 ( V_2 -> V_23 + V_43 ) & V_44 ) ; ) {
#ifdef F_10
V_92 = F_13 ( V_2 -> V_23 + V_47 ) ;
if ( V_14 -> V_48 != V_49 )
if ( ( V_92 & 0xf000 ) !=
V_16 -> V_27 [ V_4 -> V_85 -> V_86 ] ) {
F_5
( L_9 ,
( V_92 & 0xf000 ) >> 12 ,
( V_16 ->
V_27 [ V_4 ->
V_85 -> V_86 ] & 0xf000 ) >>
12 ) ;
F_25 ( V_2 , V_4 ) ;
V_4 -> V_85 -> V_94 |=
V_95 | V_96 ;
F_28 ( V_2 , V_4 ) ;
return;
}
F_29 ( V_4 -> V_85 , V_92 & 0x0fff ) ;
#else
F_29 ( V_4 -> V_85 ,
F_13 ( V_2 -> V_23 + V_47 ) & 0x0fff ) ;
#endif
++ V_4 -> V_85 -> V_86 ;
if ( V_4 -> V_85 -> V_86 >= V_16 -> V_98 )
V_4 -> V_85 -> V_86 = 0 ;
if ( V_4 -> V_85 -> V_86 == 0 ) {
V_16 -> V_84 ++ ;
if ( ( ! V_16 -> V_88 ) &&
( V_16 -> V_84 >= V_16 -> V_99 ) ) {
F_25 ( V_2 , V_4 ) ;
V_4 -> V_85 -> V_94 |= V_95 ;
F_28 ( V_2 , V_4 ) ;
return;
}
}
}
F_12 ( 0 , V_2 -> V_23 + V_40 ) ;
F_28 ( V_2 , V_4 ) ;
}
static int F_30 ( struct V_1 * V_2 ,
struct V_3 * V_4 , int V_32 , int V_100 )
{
struct V_15 * V_16 = V_2 -> V_17 ;
int V_8 , V_101 ;
#ifdef F_10
const struct V_13 * V_14 = F_8 ( V_2 ) ;
unsigned short V_92 ;
#endif
V_101 = V_4 -> V_85 -> V_86 ;
for ( V_8 = 0 ; V_8 < V_32 ; V_8 ++ ) {
#ifdef F_10
V_92 = F_13 ( V_2 -> V_23 + V_47 ) ;
if ( V_14 -> V_48 != V_49 )
if ( ( V_92 & 0xf000 ) != V_16 -> V_27 [ V_101 ] ) {
F_27 ( V_2 -> V_93 ,
L_10 ,
( V_92 & 0xf000 ) >> 12 ,
( V_16 -> V_27 [ V_101 ] & 0xf000 ) >> 12 ,
V_8 , V_101 , V_16 -> V_84 , V_32 , V_100 ,
V_92 ) ;
F_25 ( V_2 , V_4 ) ;
V_4 -> V_85 -> V_94 |=
V_95 | V_96 ;
F_28 ( V_2 , V_4 ) ;
return 1 ;
}
F_29 ( V_4 -> V_85 , V_92 & 0x0fff ) ;
#else
F_29 ( V_4 -> V_85 ,
F_13 ( V_2 -> V_23 + V_47 ) & 0x0fff ) ;
#endif
V_101 ++ ;
if ( V_101 >= V_16 -> V_98 ) {
V_101 = 0 ;
V_16 -> V_84 ++ ;
}
}
V_4 -> V_85 -> V_86 = V_101 ;
return 0 ;
}
static void F_31 ( void * V_89 )
{
struct V_1 * V_2 = V_89 ;
const struct V_13 * V_14 = F_8 ( V_2 ) ;
struct V_15 * V_16 = V_2 -> V_17 ;
struct V_3 * V_4 = V_2 -> V_90 ;
int V_91 , V_102 ;
V_91 = F_13 ( V_2 -> V_23 + V_43 ) ;
if ( ! ( V_91 & V_103 ) ) {
F_27 ( V_2 -> V_93 , L_11 , V_91 ) ;
F_25 ( V_2 , V_4 ) ;
V_4 -> V_85 -> V_94 |= V_95 | V_96 ;
F_28 ( V_2 , V_4 ) ;
return;
}
if ( V_91 & V_97 ) {
F_27 ( V_2 -> V_93 ,
L_8 , V_91 ) ;
F_25 ( V_2 , V_4 ) ;
V_4 -> V_85 -> V_94 |= V_95 | V_96 ;
F_28 ( V_2 , V_4 ) ;
return;
}
V_102 = V_14 -> V_104 ;
if ( V_102 * sizeof( short ) >= V_16 -> V_105 ) {
V_91 = V_16 -> V_105 / sizeof( short ) ;
if ( F_30 ( V_2 , V_4 , V_91 , 0 ) )
return;
V_102 -= V_91 ;
}
if ( V_102 ) {
if ( F_30 ( V_2 , V_4 , V_102 , 1 ) )
return;
}
if ( ! V_16 -> V_88 )
if ( V_16 -> V_84 >= V_16 -> V_99 ) {
F_25 ( V_2 , V_4 ) ;
V_4 -> V_85 -> V_94 |= V_95 ;
F_28 ( V_2 , V_4 ) ;
return;
}
F_12 ( 0 , V_2 -> V_23 + V_40 ) ;
F_28 ( V_2 , V_4 ) ;
}
static T_2 F_32 ( int V_106 , void * V_89 )
{
struct V_1 * V_2 = V_89 ;
struct V_15 * V_16 = V_2 -> V_17 ;
if ( ! V_2 -> V_107 )
return V_108 ;
if ( ! ( F_13 ( V_2 -> V_23 + V_43 ) & V_109 ) )
return V_108 ;
if ( V_16 -> V_110 ) {
V_16 -> V_110 = 0 ;
V_16 -> V_35 &= V_36 ;
V_16 -> V_35 |= V_37 ;
F_9 ( V_16 -> V_35 , V_2 -> V_23 + V_38 ) ;
V_16 -> V_35 = V_16 -> V_111 ;
F_12 ( 0 , V_2 -> V_23 + V_39 ) ;
F_12 ( 0 , V_2 -> V_23 + V_40 ) ;
F_9 ( V_16 -> V_28 , V_2 -> V_23 + V_24 ) ;
F_9 ( V_16 -> V_35 , V_2 -> V_23 + V_38 ) ;
F_19 ( V_2 , 1 , V_16 -> V_112 , V_16 -> V_113 ) ;
return V_114 ;
}
if ( V_16 -> V_115 ) {
F_26 ( V_89 ) ;
} else {
F_31 ( V_89 ) ;
}
return V_114 ;
}
static int F_33 ( int V_61 , struct V_1 * V_2 ,
struct V_3 * V_4 )
{
const struct V_13 * V_14 = F_8 ( V_2 ) ;
struct V_15 * V_16 = V_2 -> V_17 ;
unsigned int V_62 = 0 , V_63 = 0 ;
unsigned int V_10 ;
F_19 ( V_2 , - 1 , 0 , 0 ) ;
V_10 = F_1 ( V_2 , V_4 , V_16 -> V_116 ,
V_16 -> V_98 ) ;
if ( V_10 < 1 )
return - V_117 ;
F_7 ( V_2 , V_4 , V_16 -> V_116 ,
V_16 -> V_98 , V_10 ) ;
F_12 ( 0 , V_2 -> V_23 + V_39 ) ;
F_12 ( 0 , V_2 -> V_23 + V_40 ) ;
V_16 -> V_83 = V_61 ;
V_16 -> V_84 = 0 ;
V_4 -> V_85 -> V_86 = 0 ;
V_16 -> V_87 = 0 ;
V_16 -> V_88 = 0 ;
V_16 -> V_35 &= V_36 ;
if ( ( V_16 -> V_118 & V_119 ) ) {
V_16 -> V_115 = 1 ;
} else {
V_16 -> V_35 |= V_120 ;
V_16 -> V_115 = 0 ;
}
if ( ( V_16 -> V_99 == 0 ) || ( V_16 -> V_99 == - 1 ) )
V_16 -> V_88 = 1 ;
else
V_16 -> V_88 = 0 ;
switch ( V_61 ) {
case 1 :
case 2 :
if ( V_16 -> V_121 < V_14 -> V_122 )
V_16 -> V_121 = V_14 -> V_122 ;
V_16 -> V_35 |= V_123 | V_124 ;
if ( V_61 == 2 ) {
V_16 -> V_111 = V_16 -> V_35 ;
V_16 -> V_35 &=
~ ( V_123 | V_120 | V_125 ) ;
V_16 -> V_35 |= V_126 ;
V_16 -> V_110 = 1 ;
} else {
V_16 -> V_110 = 0 ;
}
F_34 ( V_16 -> V_127 ,
& V_62 , & V_63 ,
& V_16 -> V_121 ,
V_16 -> V_118 ) ;
F_9 ( V_16 -> V_35 , V_2 -> V_23 + V_38 ) ;
if ( V_61 != 2 ) {
F_19 ( V_2 , V_61 , V_62 , V_63 ) ;
} else {
V_16 -> V_112 = V_62 ;
V_16 -> V_113 = V_63 ;
}
break;
case 3 :
V_16 -> V_35 |= V_126 | V_124 ;
F_9 ( V_16 -> V_35 , V_2 -> V_23 + V_38 ) ;
break;
}
return 0 ;
}
static int F_35 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_128 * V_129 )
{
const struct V_13 * V_14 = F_8 ( V_2 ) ;
struct V_15 * V_16 = V_2 -> V_17 ;
int V_130 = 0 ;
int V_131 ;
unsigned int V_62 = 0 , V_63 = 0 ;
V_130 |= F_36 ( & V_129 -> V_132 , V_133 | V_134 ) ;
V_130 |= F_36 ( & V_129 -> V_135 , V_136 ) ;
V_130 |= F_36 ( & V_129 -> V_137 , V_138 | V_134 ) ;
V_130 |= F_36 ( & V_129 -> V_139 , V_140 ) ;
V_130 |= F_36 ( & V_129 -> V_141 , V_140 | V_142 ) ;
if ( V_130 )
return 1 ;
V_130 |= F_37 ( V_129 -> V_132 ) ;
V_130 |= F_37 ( V_129 -> V_137 ) ;
V_130 |= F_37 ( V_129 -> V_141 ) ;
if ( V_130 )
return 2 ;
V_130 |= F_38 ( & V_129 -> V_143 , 0 ) ;
V_130 |= F_38 ( & V_129 -> V_144 , 0 ) ;
if ( V_129 -> V_137 == V_138 )
V_130 |= F_39 ( & V_129 -> V_145 ,
V_14 -> V_122 ) ;
else
V_130 |= F_38 ( & V_129 -> V_145 , 0 ) ;
V_130 |= F_38 ( & V_129 -> V_146 , V_129 -> V_147 ) ;
if ( V_129 -> V_141 == V_140 )
V_130 |= F_39 ( & V_129 -> V_148 , 1 ) ;
else
V_130 |= F_38 ( & V_129 -> V_148 , 0 ) ;
if ( V_130 )
return 3 ;
if ( V_129 -> V_137 == V_138 ) {
V_131 = V_129 -> V_145 ;
F_34 ( V_16 -> V_127 ,
& V_62 , & V_63 ,
& V_129 -> V_145 , V_129 -> V_149 ) ;
if ( V_129 -> V_145 < V_14 -> V_122 )
V_129 -> V_145 = V_14 -> V_122 ;
if ( V_131 != V_129 -> V_145 )
V_130 ++ ;
}
if ( V_130 )
return 4 ;
if ( V_129 -> V_5 ) {
if ( ! F_1 ( V_2 , V_4 , V_129 -> V_5 ,
V_129 -> V_147 ) )
return 5 ;
}
return 0 ;
}
static int F_40 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_15 * V_16 = V_2 -> V_17 ;
struct V_128 * V_129 = & V_4 -> V_85 -> V_129 ;
V_16 -> V_98 = V_129 -> V_147 ;
V_16 -> V_116 = V_129 -> V_5 ;
V_16 -> V_118 = V_129 -> V_149 ;
V_16 -> V_105 = V_4 -> V_85 -> V_150 ;
V_16 -> V_121 = 0 ;
V_16 -> V_151 = 0 ;
if ( V_129 -> V_141 == V_140 )
V_16 -> V_99 = V_129 -> V_148 ;
else
V_16 -> V_99 = 0 ;
if ( V_129 -> V_135 == V_136 ) {
if ( V_129 -> V_137 == V_138 ) {
V_16 -> V_121 = V_129 -> V_145 ;
return F_33 ( V_129 -> V_132 ==
V_134 ? 2 : 1 , V_2 ,
V_4 ) ;
}
if ( V_129 -> V_137 == V_134 ) {
return F_33 ( 3 , V_2 , V_4 ) ;
}
}
return - 1 ;
}
static int F_41 ( struct V_1 * V_2 )
{
const struct V_13 * V_14 = F_8 ( V_2 ) ;
struct V_15 * V_16 = V_2 -> V_17 ;
F_9 ( 0x30 , V_2 -> V_23 + V_64 ) ;
V_16 -> V_35 = V_37 | V_36 ;
F_9 ( V_16 -> V_35 , V_2 -> V_23 + V_38 ) ;
F_12 ( 0 , V_2 -> V_23 + V_39 ) ;
F_12 ( 0 , V_2 -> V_23 + V_40 ) ;
F_19 ( V_2 , - 1 , 0 , 0 ) ;
V_16 -> V_53 = 0 ;
if ( V_14 -> V_152 ) {
F_12 ( V_16 -> V_53 , V_2 -> V_23 + V_54 ) ;
F_9 ( 0 , V_2 -> V_23 + V_56 ) ;
V_16 -> V_57 [ 0 ] = 0x0000 ;
if ( V_14 -> V_152 > 1 ) {
F_9 ( 0 , V_2 -> V_23 + V_55 ) ;
V_16 -> V_57 [ 1 ] = 0x0000 ;
}
}
F_9 ( 0 , V_2 -> V_23 + V_60 ) ;
F_12 ( 0 , V_2 -> V_23 + V_39 ) ;
F_12 ( 0 , V_2 -> V_23 + V_40 ) ;
return 0 ;
}
static int F_42 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_17 ;
F_12 ( V_153 , V_2 -> V_23 + V_154 ) ;
V_16 -> V_53 = 0xAA ;
F_12 ( V_16 -> V_53 , V_2 -> V_23 + V_80 ) ;
F_9 ( 0x0800 , V_2 -> V_23 + V_81 ) ;
F_9 ( 0x0800 , V_2 -> V_23 + V_155 ) ;
F_9 ( 0x0800 , V_2 -> V_23 + V_156 ) ;
F_9 ( 0x0800 , V_2 -> V_23 + V_157 ) ;
F_12 ( 0 , V_2 -> V_23 + V_82 ) ;
V_16 -> V_57 [ 0 ] = 0x0800 ;
V_16 -> V_57 [ 1 ] = 0x0800 ;
V_16 -> V_57 [ 2 ] = 0x0800 ;
V_16 -> V_57 [ 3 ] = 0x0800 ;
return 0 ;
}
static int F_43 ( struct V_1 * V_2 )
{
const struct V_13 * V_14 = F_8 ( V_2 ) ;
switch ( V_14 -> V_48 ) {
case V_158 :
return F_42 ( V_2 ) ;
default:
return F_41 ( V_2 ) ;
}
}
static int F_44 ( struct V_1 * V_2 ,
unsigned long V_159 )
{
struct V_160 * V_161 = F_45 ( V_2 ) ;
const struct V_13 * V_14 = NULL ;
struct V_15 * V_16 ;
struct V_3 * V_4 ;
int V_162 , V_163 , V_164 ;
if ( V_159 < F_46 ( V_165 ) )
V_14 = & V_165 [ V_159 ] ;
if ( ! V_14 )
return - V_166 ;
V_2 -> V_167 = V_14 ;
V_2 -> V_168 = V_14 -> V_169 ;
V_16 = F_47 ( V_2 , sizeof( * V_16 ) ) ;
if ( ! V_16 )
return - V_170 ;
V_162 = F_48 ( V_2 ) ;
if ( V_162 )
return V_162 ;
V_2 -> V_23 = F_49 ( V_161 , 2 ) ;
V_164 = 0 ;
if ( V_14 -> V_171 )
V_164 ++ ;
if ( V_14 -> V_152 )
V_164 ++ ;
if ( V_14 -> V_172 )
V_164 ++ ;
if ( V_14 -> V_173 )
V_164 ++ ;
if ( V_14 -> V_174 )
V_164 ++ ;
V_162 = F_50 ( V_2 , V_164 ) ;
if ( V_162 )
return V_162 ;
F_43 ( V_2 ) ;
if ( V_14 -> V_175 && V_161 -> V_106 ) {
V_162 = F_51 ( V_161 -> V_106 , F_32 ,
V_176 , V_2 -> V_168 , V_2 ) ;
if ( V_162 == 0 )
V_2 -> V_106 = V_161 -> V_106 ;
}
V_163 = 0 ;
if ( V_14 -> V_171 ) {
V_4 = & V_2 -> V_177 [ V_163 ] ;
V_4 -> type = V_178 ;
V_4 -> V_179 = V_180 | V_181 | V_182 ;
if ( V_14 -> V_183 )
V_4 -> V_179 |= V_184 ;
V_4 -> V_6 = V_14 -> V_171 ;
V_4 -> V_185 = V_14 -> V_186 ;
V_4 -> V_187 = V_14 -> V_188 ;
V_4 -> V_189 = F_11 ;
if ( V_2 -> V_106 ) {
V_2 -> V_90 = V_4 ;
V_4 -> V_179 |= V_190 ;
V_4 -> V_191 = V_4 -> V_6 ;
V_4 -> V_192 = F_35 ;
V_4 -> V_193 = F_40 ;
V_4 -> V_194 = F_25 ;
}
V_16 -> V_127 = V_195 ;
V_163 ++ ;
}
if ( V_14 -> V_152 ) {
V_4 = & V_2 -> V_177 [ V_163 ] ;
V_4 -> type = V_196 ;
V_4 -> V_179 = V_197 | V_182 | V_181 ;
V_4 -> V_6 = V_14 -> V_152 ;
V_4 -> V_185 = V_14 -> V_198 ;
V_4 -> V_191 = V_14 -> V_152 ;
V_4 -> V_187 = V_14 -> V_199 ;
switch ( V_14 -> V_48 ) {
case V_158 :
V_4 -> V_200 = F_24 ;
break;
default:
V_4 -> V_200 = F_14 ;
break;
}
V_4 -> V_189 = F_15 ;
V_163 ++ ;
}
if ( V_14 -> V_172 ) {
V_4 = & V_2 -> V_177 [ V_163 ] ;
V_4 -> type = V_201 ;
V_4 -> V_179 = V_180 | V_182 | V_181 ;
V_4 -> V_6 = V_14 -> V_172 ;
V_4 -> V_185 = 1 ;
V_4 -> V_191 = V_14 -> V_172 ;
V_4 -> V_187 = & V_202 ;
V_4 -> V_203 = F_16 ;
V_163 ++ ;
}
if ( V_14 -> V_173 ) {
V_4 = & V_2 -> V_177 [ V_163 ] ;
V_4 -> type = V_204 ;
V_4 -> V_179 = V_197 | V_182 | V_181 ;
V_4 -> V_6 = V_14 -> V_173 ;
V_4 -> V_185 = 1 ;
V_4 -> V_191 = V_14 -> V_173 ;
V_4 -> V_187 = & V_202 ;
V_4 -> V_203 = F_17 ;
V_163 ++ ;
}
if ( V_14 -> V_174 ) {
V_4 = & V_2 -> V_177 [ V_163 ] ;
V_4 -> type = V_205 ;
V_4 -> V_179 = V_180 | V_197 ;
V_4 -> V_6 = V_14 -> V_174 ;
V_4 -> V_191 = V_14 -> V_174 ;
V_4 -> V_185 = 0xffff ;
V_4 -> V_187 = & V_206 ;
V_4 -> V_189 = F_20 ;
V_4 -> V_200 = F_21 ;
V_4 -> V_207 = F_22 ;
V_163 ++ ;
}
F_52 ( V_2 -> V_93 , L_12 ,
V_2 -> V_168 , V_2 -> V_106 ? L_13 : L_14 ) ;
return 0 ;
}
static void F_53 ( struct V_1 * V_2 )
{
if ( V_2 -> V_23 )
F_43 ( V_2 ) ;
if ( V_2 -> V_106 )
F_54 ( V_2 -> V_106 , V_2 ) ;
F_55 ( V_2 ) ;
}
static int F_56 ( struct V_160 * V_2 ,
const struct V_208 * V_209 )
{
return F_57 ( V_2 , & V_210 ,
V_209 -> V_211 ) ;
}
