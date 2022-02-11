static void F_1 ( const struct V_1 * V_2 )
{
( void ) F_2 ( V_3 , V_2 ) ;
( void ) F_2 ( V_3 + 2 , V_2 ) ;
( void ) F_2 ( V_3 + 2 , V_2 ) ;
( void ) F_2 ( V_3 + 2 , V_2 ) ;
( void ) F_2 ( V_3 + 2 , V_2 ) ;
}
static void F_3 ( const struct V_1 * V_2 )
{
T_1 V_4 ;
F_4 ( 26 ) ;
V_4 = F_2 ( V_5 , V_2 ) ;
F_5 ( V_5 + V_2 -> V_6 , V_4 | V_7 , V_2 ) ;
return;
}
static void F_6 ( int V_8 , T_1 V_9 , const struct V_1 * V_2 )
{
F_5 ( V_10 , 1 , V_2 ) ;
F_5 ( V_11 , V_8 & 0xff , V_2 ) ;
F_5 ( V_12 , ( V_8 >> 8 ) & 0xff , V_2 ) ;
F_5 ( V_13 , V_9 , V_2 ) ;
F_5 ( V_10 , 0 , V_2 ) ;
}
static int F_7 ( const struct V_14 * V_15 ,
const union V_16 * V_17 , T_2 V_18 , T_2 V_19 )
{
struct V_1 * V_2 = (struct V_1 * ) V_15 -> V_2 ;
static struct {
T_1 V_20 ;
T_1 V_21 ;
T_1 V_22 ;
T_1 V_23 ;
T_1 V_24 ;
} V_25 [ 3 ] = {
{
0 , 0x41 , 0x03 , 0x71 , 0x45 } ,
{
0 , 0x45 , 0x04 , 0x0c , 0x01 } ,
{
0 , 0x45 , 0x06 , 0x0e , 0x00 } ,
} ;
int V_26 ;
switch ( V_18 ) {
case 8 :
default:
V_26 = 0 ;
break;
case 16 :
V_26 = 1 ;
break;
case 32 :
V_26 = 2 ;
break;
}
F_6 ( 0x90 , 0x00 , V_2 ) ;
F_6 ( 0x04 , V_25 [ V_26 ] . V_20 , V_2 ) ;
F_6 ( 0x05 , 0x00 , V_2 ) ;
F_6 ( 0x02 , 0x01 , V_2 ) ;
F_6 ( 0x71 , V_25 [ V_26 ] . V_21 , V_2 ) ;
F_6 ( 0x0a , V_25 [ V_26 ] . V_22 , V_2 ) ;
F_6 ( V_25 [ V_26 ] . V_23 , V_25 [ V_26 ] . V_24 , V_2 ) ;
return 0 ;
}
static int F_8 ( const struct V_14 * V_15 , T_2 V_27 ,
T_2 V_18 , union V_16 * V_17 )
{
static struct {
T_2 V_28 ;
T_1 V_29 ;
T_1 V_30 ;
} V_31 [ 7 ] = {
{
8000 , ( 3 << 6 ) | 20 , 9 } ,
{
10000 , ( 1 << 6 ) | 19 , 3 } ,
{
13000 , ( 1 << 6 ) | 2 , 3 } ,
{
14000 , ( 2 << 6 ) | 8 , 7 } ,
{
16000 , ( 1 << 6 ) | 44 , 6 } ,
{
25000 , ( 1 << 6 ) | 15 , 5 } ,
{
50000 , ( 0 << 6 ) | 53 , 7 } ,
} ;
int V_26 ;
for ( V_26 = 0 ; V_26 < F_9 ( V_31 ) ; V_26 ++ )
if ( V_27 <= V_31 [ V_26 ] . V_28 ) {
V_17 -> V_32 . V_29 = V_31 [ V_26 ] . V_29 ;
V_17 -> V_32 . V_30 = V_31 [ V_26 ] . V_30 ;
return 0 ;
}
return - V_33 ;
}
static T_2 F_10 ( const struct V_14 * V_15 ,
const union V_16 * V_17 )
{
struct V_1 * V_2 = (struct V_1 * ) V_15 -> V_2 ;
T_1 V_34 , V_35 , V_36 ;
V_34 = V_17 -> V_32 . V_29 >> 6 ;
V_35 = V_17 -> V_32 . V_29 & 0x3f ;
V_36 = V_17 -> V_32 . V_30 ;
return ( ( V_2 -> V_37 * V_36 ) << ( 3 - V_34 ) ) /
( V_35 + 65 ) ;
}
static void F_11 ( const struct V_14 * V_15 ,
const union V_16 * V_17 )
{
struct V_1 * V_2 = (struct V_1 * ) V_15 -> V_2 ;
F_6 ( 0x06 , 0x02 , V_2 ) ;
F_6 ( 0x10 , 0x01 , V_2 ) ;
F_6 ( 0x70 , 0x01 , V_2 ) ;
F_6 ( 0x8f , 0x1f , V_2 ) ;
F_6 ( 0x03 , 0x00 , V_2 ) ;
F_6 ( 0x05 , 0x00 , V_2 ) ;
F_6 ( 0x20 , V_17 -> V_32 . V_29 , V_2 ) ;
F_6 ( 0x21 , V_17 -> V_32 . V_30 , V_2 ) ;
}
static int F_12 ( const struct V_14 * V_15 ,
const union V_16 * V_17 , T_2 V_18 ,
T_2 V_19 )
{
struct V_1 * V_2 = (struct V_1 * ) V_15 -> V_2 ;
T_2 V_38 , V_39 , V_40 , V_41 ;
V_38 = 0 ;
V_39 = 0 ;
switch ( V_18 ) {
case 8 :
V_38 = 0x83 ;
V_39 =
0x60 | 0x00 ;
break;
case 15 :
V_38 = 0xA0 ;
V_39 = 0x60 ;
break;
case 16 :
V_38 = 0xA1 ;
V_39 = 0x60 ;
break;
case 24 :
V_38 = 0xC0 ;
V_39 = 0x60 ;
break;
case 32 :
V_38 = 0xE3 ;
V_39 = 0x60 ;
break;
}
if ( ! V_19 ) {
V_38 = 0x80 ;
V_39 = 0x61 ;
}
V_40 = F_2 ( V_10 , V_2 ) ;
F_5 ( V_10 , ( V_40 & ~ V_42 ) | V_43 ,
V_2 ) ;
F_5 ( V_3 + 2 , 0x1D , V_2 ) ;
F_5 ( V_3 + 3 , V_38 , V_2 ) ;
F_5 ( V_3 , 0x02 , V_2 ) ;
V_40 = F_2 ( V_10 , V_2 ) ;
F_5 ( V_10 , V_40 | V_42 | V_43 , V_2 ) ;
if ( V_15 -> V_44 . V_45 < V_46 )
V_41 = 0x04 ;
else if ( V_15 -> V_44 . V_45 == V_46 )
V_41 = 0x08 ;
else
V_41 = 0x0C ;
#define F_13 0x80
V_40 = F_2 ( V_3 , V_2 ) ;
F_5 ( V_3 , ( V_39 | V_41 ) | ( V_40 & F_13 ) ,
V_2 ) ;
V_40 = F_2 ( V_10 , V_2 ) ;
F_5 ( V_10 , ( V_40 & ~ ( V_42 | V_43 ) ) ,
V_2 ) ;
F_14 ( V_47 , 0x890e20f1 , V_2 ) ;
F_14 ( V_10 , 0x47052100 , V_2 ) ;
return 0 ;
}
static int F_15 ( const struct V_14 * V_15 ,
const union V_16 * V_17 , T_2 V_18 ,
T_2 V_19 )
{
struct V_1 * V_2 = (struct V_1 * ) V_15 -> V_2 ;
T_2 V_48 ;
int V_49 = 0 ;
int V_50 = 0 ;
V_48 = 100000000 / V_17 -> V_51 . V_52 ;
switch ( V_18 ) {
case 8 :
if ( V_48 > 8000 ) {
V_50 = 0x24 ;
V_49 = 1 ;
} else
V_50 = 0x04 ;
break;
case 15 :
V_50 = 0x16 ;
break;
case 16 :
V_50 = 0x36 ;
break;
case 24 :
V_50 = 0xE6 ;
break;
case 32 :
V_50 = 0xE6 ;
break;
}
if ( 1 )
V_50 |= 0x02 ;
F_1 ( V_2 ) ;
F_5 ( V_3 + 2 , V_50 , V_2 ) ;
F_14 ( V_47 , 0x890e20f1 , V_2 ) ;
F_14 ( V_10 , 0x00072000 , V_2 ) ;
return V_49 ;
}
static int F_16 ( const struct V_14 * V_15 , T_2 V_27 ,
T_2 V_18 , union V_16 * V_17 )
{
T_2 V_53 ;
T_2 V_54 ;
T_2 V_55 ;
V_53 = 100000000 / V_27 ;
V_54 = - 1 ;
V_55 = 1 ;
if ( V_53 > V_56 ) {
V_53 = V_56 ;
return - V_33 ;
} else if ( V_53 < V_57 ) {
V_54 = 0 ;
return - V_33 ;
} else {
while ( V_53 < V_58 ) {
V_53 *= 2 ;
V_55 *= 2 ;
}
}
V_53 *= 1000 ;
V_53 = ( V_59 * V_53 ) / V_60 ;
V_53 += 500 ;
V_53 /= 1000 ;
if ( V_54 == - 1 ) {
V_54 = V_53 - V_61 ;
switch ( V_55 ) {
case 1 :
V_54 |= 0x0600 ;
break;
case 2 :
V_54 |= 0x0400 ;
break;
case 4 :
V_54 |= 0x0200 ;
break;
case 8 :
default:
break;
}
}
V_54 |= V_62 ;
V_17 -> V_51 . V_54 = V_54 ;
V_17 -> V_51 . V_63 = 0 ;
V_17 -> V_51 . V_55 = V_55 ;
V_17 -> V_51 . V_52 = V_27 ;
return 0 ;
}
static T_2 F_17 ( const struct V_14 * V_15 ,
const union V_16 * V_17 )
{
return ( V_17 -> V_51 . V_52 ) ;
}
static void F_18 ( T_1 V_64 , const struct V_1 * V_2 )
{
T_1 V_4 ;
V_64 &= 0x01 ;
V_4 = F_2 ( V_5 , V_2 ) ;
F_5 ( V_5 + V_2 -> V_6 ,
( V_4 & ~ 0x04 ) | ( V_64 << 2 ) , V_2 ) ;
V_4 = F_2 ( V_5 , V_2 ) ;
F_5 ( V_5 + V_2 -> V_6 , ( V_4 & ~ 0x08 ) | ( 0 << 3 ) ,
V_2 ) ;
F_3 ( V_2 ) ;
V_4 = F_2 ( V_5 , V_2 ) ;
F_5 ( V_5 + V_2 -> V_6 , ( V_4 & ~ 0x08 ) | ( 1 << 3 ) ,
V_2 ) ;
F_3 ( V_2 ) ;
return;
}
static void F_19 ( const struct V_14 * V_15 ,
const union V_16 * V_17 )
{
struct V_1 * V_2 = (struct V_1 * ) V_15 -> V_2 ;
T_2 V_54 ;
T_2 V_63 ;
T_2 V_26 ;
T_1 V_65 ;
T_1 V_66 ;
V_65 = F_2 ( V_5 , V_2 ) ;
F_5 ( V_5 + V_2 -> V_6 , 0 , V_2 ) ;
V_66 = F_2 ( V_67 + 3 , V_2 ) ;
F_5 ( V_67 + 3 ,
V_66 | ( V_68 >> 24 ) , V_2 ) ;
F_20 ( 15 ) ;
V_54 = V_17 -> V_51 . V_54 ;
V_63 = V_17 -> V_51 . V_63 ;
F_5 ( V_5 + V_2 -> V_6 , 0 , V_2 ) ;
F_3 ( V_2 ) ;
F_5 ( V_5 + V_2 -> V_6 , 1 , V_2 ) ;
F_3 ( V_2 ) ;
F_18 ( 1 , V_2 ) ;
F_18 ( 0 , V_2 ) ;
F_18 ( 0 , V_2 ) ;
for ( V_26 = 0 ; V_26 < 5 ; V_26 ++ ) {
F_18 ( V_63 & 1 , V_2 ) ;
V_63 >>= 1 ;
}
for ( V_26 = 0 ; V_26 < 8 + 1 + 2 + 2 ; V_26 ++ ) {
F_18 ( V_54 & 1 , V_2 ) ;
V_54 >>= 1 ;
}
F_20 ( 1 ) ;
( void ) F_2 ( V_3 , V_2 ) ;
F_5 ( V_67 + 3 , V_66 , V_2 ) ;
F_5 ( V_5 + V_2 -> V_6 ,
V_65 | V_7 , V_2 ) ;
F_20 ( 50 ) ;
F_5 ( V_5 + V_2 -> V_6 ,
( ( V_17 -> V_51 . V_63 & 0x0F ) | V_7 ) , V_2 ) ;
return;
}
static int F_21 ( const struct V_14 * V_15 , T_2 V_27 ,
T_2 V_18 , union V_16 * V_17 )
{
T_2 V_69 ;
T_2 V_54 ;
T_2 V_70 , V_71 , V_72 ;
T_2 V_40 , V_73 ;
T_3 V_74 , V_75 ;
short V_76 = 0 , V_77 ;
V_69 = 100000000 / V_27 ;
V_70 = V_58 ;
V_71 = V_56 ;
V_72 = V_60 ;
if ( V_69 == 0 )
V_54 = 0xE0 ;
else {
if ( V_69 < V_70 )
V_69 = V_70 ;
if ( V_69 > V_71 )
V_69 = V_71 ;
V_76 = 0 ;
while ( V_69 < ( V_70 << 3 ) ) {
V_69 <<= 1 ;
V_76 += 0x20 ;
}
V_40 = ( unsigned int ) ( V_69 ) ;
V_40 = ( unsigned int ) ( V_40 * ( V_78 + 2 ) ) ;
V_40 -= ( short ) ( V_72 << 1 ) ;
V_77 = V_78 ;
V_75 = 0xffff ;
do {
V_73 = V_40 ;
V_74 = V_73 % V_72 ;
V_73 = V_73 / V_72 ;
if ( ( V_73 & 0xffff ) <= 127
&& ( V_74 <= V_75 ) ) {
V_75 = V_74 ;
V_76 &= ~ 0x1f ;
V_76 |= V_77 ;
V_76 =
( V_76 & 0x00ff ) +
( ( V_73 & 0xff ) << 8 ) ;
}
V_40 += V_69 ;
V_77 ++ ;
} while ( V_77 <= ( V_78 << 1 ) );
V_54 = V_76 ;
}
V_17 -> V_51 . V_54 = V_54 ;
V_17 -> V_51 . V_63 = 0 ;
V_17 -> V_51 . V_55 = V_76 ;
V_17 -> V_51 . V_52 = V_27 ;
return 0 ;
}
static T_2 F_22 ( const struct V_14 * V_15 ,
const union V_16 * V_17 )
{
return ( V_17 -> V_51 . V_52 ) ;
}
static void F_23 ( const struct V_14 * V_15 ,
const union V_16 * V_17 )
{
struct V_1 * V_2 = (struct V_1 * ) V_15 -> V_2 ;
T_2 V_54 ;
T_2 V_63 ;
char V_66 ;
V_66 = F_2 ( V_67 + 3 , V_2 ) ;
F_5 ( V_67 + 3 ,
V_66 | ( V_68 >> 24 ) , V_2 ) ;
V_54 = V_17 -> V_51 . V_54 ;
V_63 = V_17 -> V_51 . V_63 ;
F_1 ( V_2 ) ;
( void ) F_2 ( V_3 + 2 , V_2 ) ;
F_5 ( V_3 + 2 , ( V_63 << 1 ) + 0x20 , V_2 ) ;
F_5 ( V_3 + 2 , 0 , V_2 ) ;
F_5 ( V_3 + 2 , ( V_54 & 0xFF00 ) >> 8 , V_2 ) ;
F_5 ( V_3 + 2 , ( V_54 & 0xFF ) , V_2 ) ;
( void ) F_2 ( V_3 , V_2 ) ;
F_5 ( V_67 + 3 , V_66 , V_2 ) ;
return;
}
static int F_24 ( const struct V_14 * V_15 , T_2 V_27 ,
T_2 V_18 , union V_16 * V_17 )
{
T_2 V_77 , V_73 , V_79 , V_80 , V_81 , V_82 ;
T_2 V_69 ;
T_2 V_54 ;
T_2 V_70 , V_71 , V_72 ;
T_3 V_29 , V_30 , V_83 = 0 , V_84 , V_85 , V_86 ;
V_69 = 100000000 / V_27 ;
V_70 = V_58 ;
V_71 = V_56 ;
V_72 = V_60 ;
V_84 = 0 ;
V_85 = 0 ;
if ( V_69 == 0 )
V_54 = 0xE0 ;
else {
if ( V_69 < V_70 )
V_69 = V_70 ;
if ( V_69 > V_71 )
V_69 = V_71 ;
V_80 = V_69 * 256 / 100 ;
while ( V_69 < ( V_70 << 3 ) ) {
V_69 <<= 1 ;
V_83 ++ ;
}
V_86 = 1 << V_83 ;
V_81 = 0 ;
V_82 = 0xFFFFFFFF ;
for ( V_29 = V_87 ; V_29 <= V_88 ; V_29 ++ ) {
for ( V_30 = V_89 ; V_30 <= V_90 ; V_30 ++ ) {
V_77 = 938356 ;
V_77 *= ( V_30 + 8 ) ;
V_73 = V_86 * 256 ;
V_73 *= ( V_29 + 2 ) ;
V_79 = V_77 / V_73 ;
if ( V_80 > V_79 )
V_81 = V_80 - V_79 ;
else
V_81 = V_79 - V_80 ;
if ( V_81 < V_82 ) {
V_84 = V_29 ;
V_85 = V_30 ;
V_82 = V_81 ;
}
}
}
V_54 = ( V_83 << 6 ) + ( V_84 ) + ( V_85 << 8 ) ;
}
V_17 -> V_51 . V_54 = V_54 ;
V_17 -> V_51 . V_63 = 0 ;
V_17 -> V_51 . V_55 = 0 ;
V_17 -> V_51 . V_52 = V_27 ;
return 0 ;
}
static T_2 F_25 ( const struct V_14 * V_15 ,
const union V_16 * V_17 )
{
return ( V_17 -> V_51 . V_52 ) ;
}
static void F_26 ( const struct V_14 * V_15 ,
const union V_16 * V_17 )
{
struct V_1 * V_2 = (struct V_1 * ) V_15 -> V_2 ;
T_2 V_54 ;
T_2 V_63 ;
char V_66 ;
char V_4 ;
V_66 = F_2 ( V_67 + 3 , V_2 ) ;
F_5 ( V_67 + 3 ,
V_66 | ( V_68 >> 24 ) , V_2 ) ;
V_54 = V_17 -> V_51 . V_54 ;
V_63 = V_17 -> V_51 . V_63 ;
V_4 = F_2 ( V_10 , V_2 ) ;
F_5 ( V_10 , V_4 | V_42 | V_43 , V_2 ) ;
F_5 ( V_3 , V_63 , V_2 ) ;
F_5 ( V_3 + 1 , ( V_54 & 0xff00 ) >> 8 , V_2 ) ;
F_5 ( V_3 + 1 , ( V_54 & 0xff ) , V_2 ) ;
V_4 = F_2 ( V_10 , V_2 ) ;
F_5 ( V_10 , ( V_4 & ~ V_42 ) | V_43 ,
V_2 ) ;
( void ) F_2 ( V_3 , V_2 ) ;
F_5 ( V_67 + 3 , V_66 , V_2 ) ;
return;
}
static int F_27 ( const struct V_14 * V_15 , T_2 V_27 ,
T_2 V_18 , union V_16 * V_17 )
{
T_2 V_69 ;
T_2 V_54 ;
T_2 V_70 , V_71 , V_72 ;
T_2 V_40 , V_73 ;
T_3 V_74 , V_75 ;
short V_76 = 0 , V_77 ;
V_69 = 100000000 / V_27 ;
V_70 = V_58 ;
V_71 = V_56 ;
V_72 = V_60 ;
if ( V_69 == 0 )
V_54 = 0xFF ;
else {
if ( V_69 < V_70 )
V_69 = V_70 ;
if ( V_69 > V_71 )
V_69 = V_71 ;
while ( V_69 < ( V_70 << 3 ) ) {
V_69 <<= 1 ;
V_76 += 0x40 ;
}
V_40 = ( unsigned int ) V_69 ;
V_40 = ( unsigned int ) ( V_40 * ( V_91 + 2 ) ) ;
V_40 -= ( ( short ) ( V_72 << 1 ) ) ;
V_77 = V_91 ;
V_75 = 0xFFFF ;
do {
V_73 = V_40 ;
V_74 = V_73 % V_72 ;
V_73 = V_73 / V_72 ;
if ( ( ( V_73 & 0xFFFF ) <= 255 )
&& ( V_74 <= V_75 ) ) {
V_75 = V_74 ;
V_76 &= ~ 0x3f ;
V_76 |= V_77 ;
V_76 =
( V_76 & 0x00FF ) +
( ( V_73 & 0xFF ) << 8 ) ;
}
V_40 += V_69 ;
V_77 ++ ;
} while ( V_77 <= 32 );
V_54 = V_76 ;
}
V_17 -> V_51 . V_54 = V_54 ;
V_17 -> V_51 . V_63 = 0 ;
V_17 -> V_51 . V_55 = V_76 ;
V_17 -> V_51 . V_52 = V_27 ;
return 0 ;
}
static T_2 F_28 ( const struct V_14 * V_15 ,
const union V_16 * V_17 )
{
return ( V_17 -> V_51 . V_52 ) ;
}
static void F_29 ( const struct V_14 * V_15 ,
const union V_16 * V_17 )
{
struct V_1 * V_2 = (struct V_1 * ) V_15 -> V_2 ;
T_2 V_54 ;
T_2 V_63 ;
T_1 V_92 , V_93 , V_94 ;
char V_66 ;
V_66 = F_2 ( V_67 + 3 , V_2 ) ;
F_5 ( V_67 + 3 ,
V_66 | ( V_68 >> 24 ) , V_2 ) ;
V_54 = V_17 -> V_51 . V_54 ;
V_63 = V_17 -> V_51 . V_63 ;
F_1 ( V_2 ) ;
V_93 = F_2 ( V_3 + 2 , V_2 ) | 1 ;
F_1 ( V_2 ) ;
F_5 ( V_3 + 2 , V_93 , V_2 ) ;
V_92 = V_93 ;
V_94 = V_92 ;
V_92 |= 8 ;
V_93 = 1 ;
F_5 ( V_3 , V_93 , V_2 ) ;
F_5 ( V_3 + 2 , V_92 , V_2 ) ;
F_4 ( 400 ) ;
V_63 = ( V_63 << 2 ) + 0x40 ;
V_93 = V_63 ;
V_92 = V_54 >> 8 ;
F_5 ( V_3 , V_93 , V_2 ) ;
F_5 ( V_3 + 2 , V_92 , V_2 ) ;
V_93 = V_63 + 1 ;
V_92 = ( T_1 ) V_54 ;
F_5 ( V_3 , V_93 , V_2 ) ;
F_5 ( V_3 + 2 , V_92 , V_2 ) ;
V_93 = V_63 + 2 ;
V_92 = 0x77 ;
F_5 ( V_3 , V_93 , V_2 ) ;
F_5 ( V_3 + 2 , V_92 , V_2 ) ;
F_4 ( 400 ) ;
V_92 = V_94 & ( ~ ( 1 | 8 ) ) ;
V_93 = 1 ;
F_5 ( V_3 , V_93 , V_2 ) ;
F_5 ( V_3 + 2 , V_92 , V_2 ) ;
( void ) F_2 ( V_3 , V_2 ) ;
F_5 ( V_67 + 3 , V_66 , V_2 ) ;
return;
}
static int F_30 ( const struct V_14 * V_15 ,
const union V_16 * V_17 , T_2 V_18 ,
T_2 V_19 )
{
struct V_1 * V_2 = (struct V_1 * ) V_15 -> V_2 ;
F_14 ( V_47 , 0x890e20f1 , V_2 ) ;
F_14 ( V_10 , 0x47052100 , V_2 ) ;
F_14 ( V_47 , 0x590e10ff , V_2 ) ;
F_14 ( V_10 , 0x47012100 , V_2 ) ;
return 0 ;
}
static int F_31 ( void )
{
return 0 ;
}
