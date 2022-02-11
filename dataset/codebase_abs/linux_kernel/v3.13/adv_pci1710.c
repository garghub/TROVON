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
int V_32 , V_50 , V_18 , V_51 ;
V_50 = F_3 ( V_30 -> V_41 ) ;
V_18 = F_6 ( V_30 -> V_41 ) ;
if ( V_50 ) {
V_16 -> V_52 &= 0xfb ;
V_16 -> V_52 |= ( V_18 << 2 ) ;
F_9 ( V_16 -> V_52 , V_2 -> V_23 + V_53 ) ;
V_51 = V_54 ;
} else {
V_16 -> V_52 &= 0xfe ;
V_16 -> V_52 |= V_18 ;
F_9 ( V_16 -> V_52 , V_2 -> V_23 + V_53 ) ;
V_51 = V_55 ;
}
for ( V_32 = 0 ; V_32 < V_30 -> V_32 ; V_32 ++ )
F_9 ( V_31 [ V_32 ] , V_2 -> V_23 + V_51 ) ;
V_16 -> V_56 [ V_50 ] = V_31 [ V_32 ] ;
return V_32 ;
}
static int F_15 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_29 * V_30 , unsigned int * V_31 )
{
struct V_15 * V_16 = V_2 -> V_17 ;
int V_32 , V_50 ;
V_50 = F_3 ( V_30 -> V_41 ) ;
for ( V_32 = 0 ; V_32 < V_30 -> V_32 ; V_32 ++ )
V_31 [ V_32 ] = V_16 -> V_56 [ V_50 ] ;
return V_32 ;
}
static int F_16 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_29 * V_30 , unsigned int * V_31 )
{
V_31 [ 1 ] = F_13 ( V_2 -> V_23 + V_57 ) ;
return V_30 -> V_32 ;
}
static int F_17 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_29 * V_30 ,
unsigned int * V_31 )
{
if ( F_18 ( V_4 , V_31 ) )
F_9 ( V_4 -> V_58 , V_2 -> V_23 + V_59 ) ;
V_31 [ 1 ] = V_4 -> V_58 ;
return V_30 -> V_32 ;
}
static void F_19 ( struct V_1 * V_2 , int V_60 ,
unsigned int V_61 , unsigned int V_62 )
{
F_9 ( 0xb4 , V_2 -> V_23 + V_63 ) ;
F_9 ( 0x74 , V_2 -> V_23 + V_63 ) ;
if ( V_60 == 1 ) {
F_9 ( V_62 & 0xff , V_2 -> V_23 + V_64 ) ;
F_9 ( ( V_62 >> 8 ) & 0xff , V_2 -> V_23 + V_64 ) ;
F_9 ( V_61 & 0xff , V_2 -> V_23 + V_65 ) ;
F_9 ( ( V_61 >> 8 ) & 0xff , V_2 -> V_23 + V_65 ) ;
}
}
static int F_20 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_29 * V_30 ,
unsigned int * V_31 )
{
unsigned int V_66 , V_67 , V_68 ;
int V_8 ;
V_68 = 0xD2 ;
for ( V_8 = 0 ; V_8 < V_30 -> V_32 ; V_8 ++ ) {
F_9 ( V_68 , V_2 -> V_23 + V_63 ) ;
V_67 = F_13 ( V_2 -> V_23 + V_69 ) & 0xFF ;
V_66 = F_13 ( V_2 -> V_23 + V_69 ) & 0xFF ;
V_31 [ 0 ] = V_67 | ( V_66 << 8 ) ;
}
return V_30 -> V_32 ;
}
static int F_21 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_29 * V_30 ,
unsigned int * V_31 )
{
struct V_15 * V_16 = V_2 -> V_17 ;
T_1 V_66 , V_67 , V_68 , V_70 ;
V_67 = V_31 [ 0 ] & 0x00FF ;
V_66 = ( V_31 [ 0 ] & 0xFF00 ) >> 8 ;
F_9 ( V_67 , V_2 -> V_23 + V_69 ) ;
F_9 ( V_66 , V_2 -> V_23 + V_69 ) ;
if ( V_16 -> V_71 ) {
V_68 = 0xE2 ;
do {
F_9 ( V_68 , V_2 -> V_23 + V_63 ) ;
V_70 = F_13 ( V_2 -> V_23 + V_69 ) & 0xFF ;
} while ( V_70 & 0x40 );
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
T_1 V_68 = 0 ;
V_16 -> V_71 = V_31 [ 0 ] & 0x20 ;
if ( ! ( V_31 [ 0 ] & 0x10 ) ) {
V_16 -> V_35 &= ~ V_36 ;
} else {
V_16 -> V_35 |= V_36 ;
}
F_9 ( V_16 -> V_35 , V_2 -> V_23 + V_38 ) ;
if ( V_31 [ 0 ] & 0x01 )
V_68 |= V_72 ;
if ( V_31 [ 0 ] & 0x02 )
V_68 |= V_73 ;
if ( V_31 [ 0 ] & 0x04 )
V_68 |= V_74 ;
if ( V_31 [ 0 ] & 0x08 )
V_68 |= V_75 ;
V_68 |= V_76 ;
V_68 |= V_77 ;
F_9 ( V_68 , V_2 -> V_23 + V_63 ) ;
#endif
return 1 ;
}
static int F_24 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_29 * V_30 , unsigned int * V_31 )
{
struct V_15 * V_16 = V_2 -> V_17 ;
int V_32 , V_78 , V_50 ;
V_50 = F_3 ( V_30 -> V_41 ) ;
V_78 = V_16 -> V_52 & ( ~ ( 0x03 << ( V_50 << 1 ) ) ) ;
V_78 |= ( F_6 ( V_30 -> V_41 ) << ( V_50 << 1 ) ) ;
if ( V_78 != V_16 -> V_52 ) {
F_12 ( V_78 , V_2 -> V_23 + V_79 ) ;
V_16 -> V_52 = V_78 ;
}
for ( V_32 = 0 ; V_32 < V_30 -> V_32 ; V_32 ++ ) {
F_9 ( V_31 [ V_32 ] , V_2 -> V_23 + V_80 + ( V_50 << 1 ) ) ;
F_12 ( 0 , V_2 -> V_23 + V_81 ) ;
}
V_16 -> V_56 [ V_50 ] = V_31 [ V_32 ] ;
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
V_16 -> V_82 = 0 ;
V_16 -> V_83 = 0 ;
V_4 -> V_84 -> V_85 = 0 ;
V_16 -> V_86 = 0 ;
V_16 -> V_87 = 0 ;
return 0 ;
}
static void F_26 ( void * V_88 )
{
struct V_1 * V_2 = V_88 ;
struct V_15 * V_16 = V_2 -> V_17 ;
struct V_3 * V_4 = & V_2 -> V_89 [ 0 ] ;
int V_90 ;
#ifdef F_10
const struct V_13 * V_14 = F_8 ( V_2 ) ;
unsigned short V_91 ;
#endif
V_90 = F_13 ( V_2 -> V_23 + V_43 ) ;
if ( V_90 & V_44 ) {
F_5 ( L_7 , V_2 -> V_92 , V_90 ) ;
F_25 ( V_2 , V_4 ) ;
V_4 -> V_84 -> V_93 |= V_94 | V_95 ;
F_27 ( V_2 , V_4 ) ;
return;
}
if ( V_90 & V_96 ) {
F_5
( L_8 ,
V_2 -> V_92 , V_90 ) ;
F_25 ( V_2 , V_4 ) ;
V_4 -> V_84 -> V_93 |= V_94 | V_95 ;
F_27 ( V_2 , V_4 ) ;
return;
}
F_12 ( 0 , V_2 -> V_23 + V_40 ) ;
for (; ! ( F_13 ( V_2 -> V_23 + V_43 ) & V_44 ) ; ) {
#ifdef F_10
V_91 = F_13 ( V_2 -> V_23 + V_47 ) ;
if ( V_14 -> V_48 != V_49 )
if ( ( V_91 & 0xf000 ) !=
V_16 -> V_27 [ V_4 -> V_84 -> V_85 ] ) {
F_5
( L_9 ,
( V_91 & 0xf000 ) >> 12 ,
( V_16 ->
V_27 [ V_4 ->
V_84 -> V_85 ] & 0xf000 ) >>
12 ) ;
F_25 ( V_2 , V_4 ) ;
V_4 -> V_84 -> V_93 |=
V_94 | V_95 ;
F_27 ( V_2 , V_4 ) ;
return;
}
F_28 ( V_4 -> V_84 , V_91 & 0x0fff ) ;
#else
F_28 ( V_4 -> V_84 ,
F_13 ( V_2 -> V_23 + V_47 ) & 0x0fff ) ;
#endif
++ V_4 -> V_84 -> V_85 ;
if ( V_4 -> V_84 -> V_85 >= V_16 -> V_97 )
V_4 -> V_84 -> V_85 = 0 ;
if ( V_4 -> V_84 -> V_85 == 0 ) {
V_16 -> V_83 ++ ;
if ( ( ! V_16 -> V_87 ) &&
( V_16 -> V_83 >= V_16 -> V_98 ) ) {
F_25 ( V_2 , V_4 ) ;
V_4 -> V_84 -> V_93 |= V_94 ;
F_27 ( V_2 , V_4 ) ;
return;
}
}
}
F_12 ( 0 , V_2 -> V_23 + V_40 ) ;
F_27 ( V_2 , V_4 ) ;
}
static int F_29 ( struct V_1 * V_2 ,
struct V_3 * V_4 , int V_32 , int V_99 )
{
struct V_15 * V_16 = V_2 -> V_17 ;
int V_8 , V_100 ;
#ifdef F_10
const struct V_13 * V_14 = F_8 ( V_2 ) ;
unsigned short V_91 ;
#endif
V_100 = V_4 -> V_84 -> V_85 ;
for ( V_8 = 0 ; V_8 < V_32 ; V_8 ++ ) {
#ifdef F_10
V_91 = F_13 ( V_2 -> V_23 + V_47 ) ;
if ( V_14 -> V_48 != V_49 )
if ( ( V_91 & 0xf000 ) != V_16 -> V_27 [ V_100 ] ) {
F_5
( L_10 ,
V_2 -> V_92 , ( V_91 & 0xf000 ) >> 12 ,
( V_16 -> V_27 [ V_100 ] & 0xf000 ) >> 12 ,
V_8 , V_100 , V_16 -> V_83 , V_32 , V_99 ,
V_91 ) ;
F_25 ( V_2 , V_4 ) ;
V_4 -> V_84 -> V_93 |=
V_94 | V_95 ;
F_27 ( V_2 , V_4 ) ;
return 1 ;
}
F_28 ( V_4 -> V_84 , V_91 & 0x0fff ) ;
#else
F_28 ( V_4 -> V_84 ,
F_13 ( V_2 -> V_23 + V_47 ) & 0x0fff ) ;
#endif
V_100 ++ ;
if ( V_100 >= V_16 -> V_97 ) {
V_100 = 0 ;
V_16 -> V_83 ++ ;
}
}
V_4 -> V_84 -> V_85 = V_100 ;
return 0 ;
}
static void F_30 ( void * V_88 )
{
struct V_1 * V_2 = V_88 ;
const struct V_13 * V_14 = F_8 ( V_2 ) ;
struct V_15 * V_16 = V_2 -> V_17 ;
struct V_3 * V_4 = & V_2 -> V_89 [ 0 ] ;
int V_90 , V_101 ;
V_90 = F_13 ( V_2 -> V_23 + V_43 ) ;
if ( ! ( V_90 & V_102 ) ) {
F_5 ( L_11 ,
V_2 -> V_92 , V_90 ) ;
F_25 ( V_2 , V_4 ) ;
V_4 -> V_84 -> V_93 |= V_94 | V_95 ;
F_27 ( V_2 , V_4 ) ;
return;
}
if ( V_90 & V_96 ) {
F_5
( L_8 ,
V_2 -> V_92 , V_90 ) ;
F_25 ( V_2 , V_4 ) ;
V_4 -> V_84 -> V_93 |= V_94 | V_95 ;
F_27 ( V_2 , V_4 ) ;
return;
}
V_101 = V_14 -> V_103 ;
if ( V_101 * sizeof( short ) >= V_16 -> V_104 ) {
V_90 = V_16 -> V_104 / sizeof( short ) ;
if ( F_29 ( V_2 , V_4 , V_90 , 0 ) )
return;
V_101 -= V_90 ;
}
if ( V_101 ) {
if ( F_29 ( V_2 , V_4 , V_101 , 1 ) )
return;
}
if ( ! V_16 -> V_87 )
if ( V_16 -> V_83 >= V_16 -> V_98 ) {
F_25 ( V_2 , V_4 ) ;
V_4 -> V_84 -> V_93 |= V_94 ;
F_27 ( V_2 , V_4 ) ;
return;
}
F_12 ( 0 , V_2 -> V_23 + V_40 ) ;
F_27 ( V_2 , V_4 ) ;
}
static T_2 F_31 ( int V_105 , void * V_88 )
{
struct V_1 * V_2 = V_88 ;
struct V_15 * V_16 = V_2 -> V_17 ;
if ( ! V_2 -> V_106 )
return V_107 ;
if ( ! ( F_13 ( V_2 -> V_23 + V_43 ) & V_108 ) )
return V_107 ;
if ( V_16 -> V_109 ) {
V_16 -> V_109 = 0 ;
V_16 -> V_35 &= V_36 ;
V_16 -> V_35 |= V_37 ;
F_9 ( V_16 -> V_35 , V_2 -> V_23 + V_38 ) ;
V_16 -> V_35 = V_16 -> V_110 ;
F_12 ( 0 , V_2 -> V_23 + V_39 ) ;
F_12 ( 0 , V_2 -> V_23 + V_40 ) ;
F_9 ( V_16 -> V_28 , V_2 -> V_23 + V_24 ) ;
F_9 ( V_16 -> V_35 , V_2 -> V_23 + V_38 ) ;
F_19 ( V_2 , 1 , V_16 -> V_111 , V_16 -> V_112 ) ;
return V_113 ;
}
if ( V_16 -> V_114 ) {
F_26 ( V_88 ) ;
} else {
F_30 ( V_88 ) ;
}
return V_113 ;
}
static int F_32 ( int V_60 , struct V_1 * V_2 ,
struct V_3 * V_4 )
{
const struct V_13 * V_14 = F_8 ( V_2 ) ;
struct V_15 * V_16 = V_2 -> V_17 ;
unsigned int V_61 = 0 , V_62 = 0 ;
unsigned int V_10 ;
F_19 ( V_2 , - 1 , 0 , 0 ) ;
V_10 = F_1 ( V_2 , V_4 , V_16 -> V_115 ,
V_16 -> V_97 ) ;
if ( V_10 < 1 )
return - V_116 ;
F_7 ( V_2 , V_4 , V_16 -> V_115 ,
V_16 -> V_97 , V_10 ) ;
F_12 ( 0 , V_2 -> V_23 + V_39 ) ;
F_12 ( 0 , V_2 -> V_23 + V_40 ) ;
V_16 -> V_82 = V_60 ;
V_16 -> V_83 = 0 ;
V_4 -> V_84 -> V_85 = 0 ;
V_16 -> V_86 = 0 ;
V_16 -> V_87 = 0 ;
V_16 -> V_35 &= V_36 ;
if ( ( V_16 -> V_117 & V_118 ) ) {
V_16 -> V_114 = 1 ;
} else {
V_16 -> V_35 |= V_119 ;
V_16 -> V_114 = 0 ;
}
if ( ( V_16 -> V_98 == 0 ) || ( V_16 -> V_98 == - 1 ) )
V_16 -> V_87 = 1 ;
else
V_16 -> V_87 = 0 ;
switch ( V_60 ) {
case 1 :
case 2 :
if ( V_16 -> V_120 < V_14 -> V_121 )
V_16 -> V_120 = V_14 -> V_121 ;
V_16 -> V_35 |= V_122 | V_123 ;
if ( V_60 == 2 ) {
V_16 -> V_110 = V_16 -> V_35 ;
V_16 -> V_35 &=
~ ( V_122 | V_119 | V_124 ) ;
V_16 -> V_35 |= V_125 ;
V_16 -> V_109 = 1 ;
} else {
V_16 -> V_109 = 0 ;
}
F_33 ( V_16 -> V_126 ,
& V_61 , & V_62 ,
& V_16 -> V_120 ,
V_16 -> V_117 ) ;
F_9 ( V_16 -> V_35 , V_2 -> V_23 + V_38 ) ;
if ( V_60 != 2 ) {
F_19 ( V_2 , V_60 , V_61 , V_62 ) ;
} else {
V_16 -> V_111 = V_61 ;
V_16 -> V_112 = V_62 ;
}
break;
case 3 :
V_16 -> V_35 |= V_125 | V_123 ;
F_9 ( V_16 -> V_35 , V_2 -> V_23 + V_38 ) ;
break;
}
return 0 ;
}
static int F_34 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_127 * V_128 )
{
const struct V_13 * V_14 = F_8 ( V_2 ) ;
struct V_15 * V_16 = V_2 -> V_17 ;
int V_129 = 0 ;
int V_130 ;
unsigned int V_61 = 0 , V_62 = 0 ;
V_129 |= F_35 ( & V_128 -> V_131 , V_132 | V_133 ) ;
V_129 |= F_35 ( & V_128 -> V_134 , V_135 ) ;
V_129 |= F_35 ( & V_128 -> V_136 , V_137 | V_133 ) ;
V_129 |= F_35 ( & V_128 -> V_138 , V_139 ) ;
V_129 |= F_35 ( & V_128 -> V_140 , V_139 | V_141 ) ;
if ( V_129 )
return 1 ;
V_129 |= F_36 ( V_128 -> V_131 ) ;
V_129 |= F_36 ( V_128 -> V_136 ) ;
V_129 |= F_36 ( V_128 -> V_140 ) ;
if ( V_129 )
return 2 ;
V_129 |= F_37 ( & V_128 -> V_142 , 0 ) ;
V_129 |= F_37 ( & V_128 -> V_143 , 0 ) ;
if ( V_128 -> V_136 == V_137 )
V_129 |= F_38 ( & V_128 -> V_144 ,
V_14 -> V_121 ) ;
else
V_129 |= F_37 ( & V_128 -> V_144 , 0 ) ;
V_129 |= F_37 ( & V_128 -> V_145 , V_128 -> V_146 ) ;
if ( V_128 -> V_140 == V_139 )
V_129 |= F_38 ( & V_128 -> V_147 , 1 ) ;
else
V_129 |= F_37 ( & V_128 -> V_147 , 0 ) ;
if ( V_129 )
return 3 ;
if ( V_128 -> V_136 == V_137 ) {
V_130 = V_128 -> V_144 ;
F_33 ( V_16 -> V_126 ,
& V_61 , & V_62 ,
& V_128 -> V_144 , V_128 -> V_148 ) ;
if ( V_128 -> V_144 < V_14 -> V_121 )
V_128 -> V_144 = V_14 -> V_121 ;
if ( V_130 != V_128 -> V_144 )
V_129 ++ ;
}
if ( V_129 )
return 4 ;
if ( V_128 -> V_5 ) {
if ( ! F_1 ( V_2 , V_4 , V_128 -> V_5 ,
V_128 -> V_146 ) )
return 5 ;
}
return 0 ;
}
static int F_39 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_15 * V_16 = V_2 -> V_17 ;
struct V_127 * V_128 = & V_4 -> V_84 -> V_128 ;
V_16 -> V_97 = V_128 -> V_146 ;
V_16 -> V_115 = V_128 -> V_5 ;
V_16 -> V_117 = V_128 -> V_148 ;
V_16 -> V_104 = V_4 -> V_84 -> V_149 ;
V_16 -> V_120 = 0 ;
V_16 -> V_150 = 0 ;
if ( V_128 -> V_140 == V_139 )
V_16 -> V_98 = V_128 -> V_147 ;
else
V_16 -> V_98 = 0 ;
if ( V_128 -> V_134 == V_135 ) {
if ( V_128 -> V_136 == V_137 ) {
V_16 -> V_120 = V_128 -> V_144 ;
return F_32 ( V_128 -> V_131 ==
V_133 ? 2 : 1 , V_2 ,
V_4 ) ;
}
if ( V_128 -> V_136 == V_133 ) {
return F_32 ( 3 , V_2 , V_4 ) ;
}
}
return - 1 ;
}
static int F_40 ( struct V_1 * V_2 )
{
const struct V_13 * V_14 = F_8 ( V_2 ) ;
struct V_15 * V_16 = V_2 -> V_17 ;
F_9 ( 0x30 , V_2 -> V_23 + V_63 ) ;
V_16 -> V_35 = V_37 | V_36 ;
F_9 ( V_16 -> V_35 , V_2 -> V_23 + V_38 ) ;
F_12 ( 0 , V_2 -> V_23 + V_39 ) ;
F_12 ( 0 , V_2 -> V_23 + V_40 ) ;
F_19 ( V_2 , - 1 , 0 , 0 ) ;
V_16 -> V_52 = 0 ;
if ( V_14 -> V_151 ) {
F_12 ( V_16 -> V_52 , V_2 -> V_23 + V_53 ) ;
F_9 ( 0 , V_2 -> V_23 + V_55 ) ;
V_16 -> V_56 [ 0 ] = 0x0000 ;
if ( V_14 -> V_151 > 1 ) {
F_9 ( 0 , V_2 -> V_23 + V_54 ) ;
V_16 -> V_56 [ 1 ] = 0x0000 ;
}
}
F_9 ( 0 , V_2 -> V_23 + V_59 ) ;
F_12 ( 0 , V_2 -> V_23 + V_39 ) ;
F_12 ( 0 , V_2 -> V_23 + V_40 ) ;
return 0 ;
}
static int F_41 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_17 ;
F_12 ( V_152 , V_2 -> V_23 + V_153 ) ;
V_16 -> V_52 = 0xAA ;
F_12 ( V_16 -> V_52 , V_2 -> V_23 + V_79 ) ;
F_9 ( 0x0800 , V_2 -> V_23 + V_80 ) ;
F_9 ( 0x0800 , V_2 -> V_23 + V_154 ) ;
F_9 ( 0x0800 , V_2 -> V_23 + V_155 ) ;
F_9 ( 0x0800 , V_2 -> V_23 + V_156 ) ;
F_12 ( 0 , V_2 -> V_23 + V_81 ) ;
V_16 -> V_56 [ 0 ] = 0x0800 ;
V_16 -> V_56 [ 1 ] = 0x0800 ;
V_16 -> V_56 [ 2 ] = 0x0800 ;
V_16 -> V_56 [ 3 ] = 0x0800 ;
return 0 ;
}
static int F_42 ( struct V_1 * V_2 )
{
const struct V_13 * V_14 = F_8 ( V_2 ) ;
switch ( V_14 -> V_48 ) {
case V_157 :
return F_41 ( V_2 ) ;
default:
return F_40 ( V_2 ) ;
}
}
static int F_43 ( struct V_1 * V_2 ,
unsigned long V_158 )
{
struct V_159 * V_160 = F_44 ( V_2 ) ;
const struct V_13 * V_14 = NULL ;
struct V_15 * V_16 ;
struct V_3 * V_4 ;
int V_161 , V_162 , V_163 ;
if ( V_158 < F_45 ( V_164 ) )
V_14 = & V_164 [ V_158 ] ;
if ( ! V_14 )
return - V_165 ;
V_2 -> V_166 = V_14 ;
V_2 -> V_167 = V_14 -> V_168 ;
V_16 = F_46 ( V_2 , sizeof( * V_16 ) ) ;
if ( ! V_16 )
return - V_169 ;
V_161 = F_47 ( V_2 ) ;
if ( V_161 )
return V_161 ;
V_2 -> V_23 = F_48 ( V_160 , 2 ) ;
V_163 = 0 ;
if ( V_14 -> V_170 )
V_163 ++ ;
if ( V_14 -> V_151 )
V_163 ++ ;
if ( V_14 -> V_171 )
V_163 ++ ;
if ( V_14 -> V_172 )
V_163 ++ ;
if ( V_14 -> V_173 )
V_163 ++ ;
V_161 = F_49 ( V_2 , V_163 ) ;
if ( V_161 )
return V_161 ;
F_42 ( V_2 ) ;
if ( V_14 -> V_174 && V_160 -> V_105 ) {
V_161 = F_50 ( V_160 -> V_105 , F_31 ,
V_175 , V_2 -> V_167 , V_2 ) ;
if ( V_161 == 0 )
V_2 -> V_105 = V_160 -> V_105 ;
}
V_162 = 0 ;
if ( V_14 -> V_170 ) {
V_4 = & V_2 -> V_89 [ V_162 ] ;
V_2 -> V_176 = V_4 ;
V_4 -> type = V_177 ;
V_4 -> V_178 = V_179 | V_180 | V_181 ;
if ( V_14 -> V_182 )
V_4 -> V_178 |= V_183 ;
V_4 -> V_6 = V_14 -> V_170 ;
V_4 -> V_184 = V_14 -> V_185 ;
V_4 -> V_186 = V_14 -> V_170 ;
V_4 -> V_187 = V_14 -> V_188 ;
V_4 -> V_189 = F_25 ;
V_4 -> V_190 = F_11 ;
if ( V_2 -> V_105 ) {
V_4 -> V_178 |= V_191 ;
V_4 -> V_192 = F_34 ;
V_4 -> V_193 = F_39 ;
}
V_16 -> V_126 = V_194 ;
V_162 ++ ;
}
if ( V_14 -> V_151 ) {
V_4 = & V_2 -> V_89 [ V_162 ] ;
V_4 -> type = V_195 ;
V_4 -> V_178 = V_196 | V_181 | V_180 ;
V_4 -> V_6 = V_14 -> V_151 ;
V_4 -> V_184 = V_14 -> V_197 ;
V_4 -> V_186 = V_14 -> V_151 ;
V_4 -> V_187 = V_14 -> V_198 ;
switch ( V_14 -> V_48 ) {
case V_157 :
V_4 -> V_199 = F_24 ;
break;
default:
V_4 -> V_199 = F_14 ;
break;
}
V_4 -> V_190 = F_15 ;
V_162 ++ ;
}
if ( V_14 -> V_171 ) {
V_4 = & V_2 -> V_89 [ V_162 ] ;
V_4 -> type = V_200 ;
V_4 -> V_178 = V_179 | V_181 | V_180 ;
V_4 -> V_6 = V_14 -> V_171 ;
V_4 -> V_184 = 1 ;
V_4 -> V_186 = V_14 -> V_171 ;
V_4 -> V_187 = & V_201 ;
V_4 -> V_202 = F_16 ;
V_162 ++ ;
}
if ( V_14 -> V_172 ) {
V_4 = & V_2 -> V_89 [ V_162 ] ;
V_4 -> type = V_203 ;
V_4 -> V_178 = V_196 | V_181 | V_180 ;
V_4 -> V_6 = V_14 -> V_172 ;
V_4 -> V_184 = 1 ;
V_4 -> V_186 = V_14 -> V_172 ;
V_4 -> V_187 = & V_201 ;
V_4 -> V_202 = F_17 ;
V_162 ++ ;
}
if ( V_14 -> V_173 ) {
V_4 = & V_2 -> V_89 [ V_162 ] ;
V_4 -> type = V_204 ;
V_4 -> V_178 = V_179 | V_196 ;
V_4 -> V_6 = V_14 -> V_173 ;
V_4 -> V_186 = V_14 -> V_173 ;
V_4 -> V_184 = 0xffff ;
V_4 -> V_187 = & V_205 ;
V_4 -> V_190 = F_20 ;
V_4 -> V_199 = F_21 ;
V_4 -> V_206 = F_22 ;
V_162 ++ ;
}
F_51 ( V_2 -> V_207 , L_12 ,
V_2 -> V_167 , V_2 -> V_105 ? L_13 : L_14 ) ;
return 0 ;
}
static void F_52 ( struct V_1 * V_2 )
{
if ( V_2 -> V_23 )
F_42 ( V_2 ) ;
if ( V_2 -> V_105 )
F_53 ( V_2 -> V_105 , V_2 ) ;
F_54 ( V_2 ) ;
}
static int F_55 ( struct V_159 * V_2 ,
const struct V_208 * V_209 )
{
return F_56 ( V_2 , & V_210 ,
V_209 -> V_211 ) ;
}
