static void F_1 ( struct V_1 * V_1 ,
T_1 V_2 ,
const T_2 * V_3 , int V_4 )
{
int V_5 ;
if ( V_1 -> V_6 < 0 )
return;
memcpy ( V_1 -> V_7 , V_3 , V_4 ) ;
V_5 = F_2 ( V_1 -> V_8 ,
F_3 ( V_1 -> V_8 , 0 ) ,
0 ,
V_9 | V_10 | V_11 ,
0 ,
V_2 , V_1 -> V_7 , V_4 ,
500 ) ;
if ( V_5 < 0 ) {
F_4 ( L_1 ,
V_2 , V_5 ) ;
V_1 -> V_6 = V_5 ;
}
}
static void F_5 ( struct V_1 * V_1 ,
T_1 V_2 ,
T_1 V_12 )
{
int V_5 ;
if ( V_1 -> V_6 < 0 )
return;
V_1 -> V_7 [ 0 ] = V_12 ;
V_5 = F_2 ( V_1 -> V_8 ,
F_3 ( V_1 -> V_8 , 0 ) ,
0 ,
V_9 | V_10 | V_11 ,
0 , V_2 , V_1 -> V_7 , 1 ,
500 ) ;
if ( V_5 < 0 ) {
F_4 ( L_2 ,
V_2 , V_12 , V_5 ) ;
V_1 -> V_6 = V_5 ;
}
}
static void F_6 ( struct V_1 * V_1 ,
const T_1 * V_13 , int V_4 )
{
while ( -- V_4 >= 0 ) {
F_5 ( V_1 , V_13 [ 0 ] , V_13 [ 1 ] ) ;
V_13 += 2 ;
}
}
static void F_7 ( struct V_1 * V_1 ,
const T_1 * V_14 , int V_4 )
{
int V_2 ;
int V_5 = 0 ;
if ( V_1 -> V_6 < 0 )
return;
for ( V_2 = 0 ; V_2 < V_4 ; V_2 ++ ) {
if ( V_14 [ V_2 ] == V_15 )
continue;
V_1 -> V_7 [ 0 ] = V_14 [ V_2 ] ;
V_5 = F_2 ( V_1 -> V_8 ,
F_3 ( V_1 -> V_8 , 0 ) ,
0 ,
V_9 | V_10 | V_11 ,
0 , V_2 , V_1 -> V_7 , 1 ,
500 ) ;
if ( V_5 < 0 ) {
F_4 ( L_3 ,
V_2 , V_14 [ V_2 ] , V_5 ) ;
V_1 -> V_6 = V_5 ;
break;
}
}
}
static void F_8 ( struct V_1 * V_1 ,
const T_1 * V_13 ,
const T_1 * V_16 , unsigned int V_17 )
{
int V_2 , V_4 ;
for (; ; ) {
V_2 = * V_13 ++ ;
V_4 = * V_13 ++ ;
switch ( V_4 ) {
case V_18 :
return;
case V_19 :
F_7 ( V_1 , V_16 , V_17 ) ;
break;
default:
if ( V_4 > V_20 ) {
F_9 ( V_21 | V_22 ,
L_4 ) ;
return;
}
while ( V_4 > 0 ) {
if ( V_4 < 8 ) {
F_1 ( V_1 ,
V_2 , V_13 , V_4 ) ;
V_13 += V_4 ;
break;
}
F_1 ( V_1 , V_2 , V_13 , 8 ) ;
V_13 += 8 ;
V_2 += 8 ;
V_4 -= 8 ;
}
}
}
}
static int F_10 ( struct V_1 * V_1 ,
const struct V_23 * V_24 )
{
struct V_25 * V_25 = (struct V_25 * ) V_1 ;
struct V_26 * V_26 ;
V_26 = & V_1 -> V_26 ;
F_9 ( V_27 , L_5 ) ;
V_26 -> V_28 = V_29 ;
V_26 -> V_30 = F_11 ( V_29 ) ;
V_25 -> V_31 = V_32 ;
V_25 -> V_33 = V_34 ;
V_25 -> V_35 = V_36 ;
V_25 -> V_37 = V_38 ;
V_25 -> V_39 = V_40 ;
V_25 -> V_41 = V_42 ;
V_25 -> V_43 = V_44 ;
V_25 -> V_45 = V_46 ;
V_25 -> V_47 = V_48 ;
V_25 -> V_49 = V_50 ;
V_25 -> V_51 = V_52 ;
V_25 -> V_53 = V_24 -> V_54 ;
return 0 ;
}
static void F_12 ( struct V_1 * V_1 )
{
struct V_25 * V_25 = (struct V_25 * ) V_1 ;
int V_55 , V_56 ;
static const T_1 V_57 [ 10 ] =
{ 0x29 , 0x33 , 0x42 , 0x5a , 0x6e , 0x80 , 0x9f , 0xbb ,
0xd4 , 0xec } ;
static const T_1 V_58 [ 10 ] =
{ 0x35 , 0x33 , 0x33 , 0x2f , 0x2a , 0x25 , 0x1e , 0x17 ,
0x11 , 0x0b } ;
F_5 ( V_1 , 0xff , 0x00 ) ;
for ( V_55 = 0 ; V_55 < 10 ; V_55 ++ ) {
V_56 = V_57 [ V_55 ] ;
V_56 += ( V_25 -> V_31 - V_59 )
* 150 / V_59 ;
V_56 -= V_58 [ V_55 ] * V_25 -> V_33 / V_60 ;
if ( V_56 < 0 )
V_56 = 0 ;
else if ( V_56 > 0xff )
V_56 = 0xff ;
F_5 ( V_1 , 0xa2 + V_55 , V_56 ) ;
}
F_5 ( V_1 , 0xdc , 0x01 ) ;
}
static void F_13 ( struct V_1 * V_1 )
{
struct V_25 * V_25 = (struct V_25 * ) V_1 ;
int V_55 , V_56 ;
static const int V_61 [ 9 ] =
{ 217 , - 212 , 0 , - 101 , 170 , - 67 , - 38 , - 315 , 355 } ;
static const int V_62 [ 9 ] =
{ 19 , 106 , 0 , 19 , 106 , 1 , 19 , 106 , 1 } ;
F_5 ( V_1 , 0xff , 0x03 ) ;
F_5 ( V_1 , 0x11 , 0x01 ) ;
F_5 ( V_1 , 0xff , 0x00 ) ;
for ( V_55 = 0 ; V_55 < 9 ; V_55 ++ ) {
V_56 = V_61 [ V_55 ] * V_25 -> V_35 / V_63 + V_62 [ V_55 ] ;
F_5 ( V_1 , 0x0f + 2 * V_55 , ( V_56 >> 8 ) & 0x07 ) ;
F_5 ( V_1 , 0x0f + 2 * V_55 + 1 , V_56 ) ;
}
F_5 ( V_1 , 0xdc , 0x01 ) ;
F_9 ( V_27 | V_22 , L_6 , V_25 -> V_35 ) ;
}
static void F_14 ( struct V_1 * V_1 )
{
struct V_25 * V_25 = (struct V_25 * ) V_1 ;
F_5 ( V_1 , 0xff , 0x00 ) ;
F_5 ( V_1 , 0xc6 , V_25 -> V_37 ) ;
F_5 ( V_1 , 0xdc , 0x01 ) ;
F_9 ( V_27 | V_22 , L_7 , V_25 -> V_37 ) ;
}
static void F_15 ( struct V_1 * V_1 )
{
struct V_25 * V_25 = (struct V_25 * ) V_1 ;
F_5 ( V_1 , 0xff , 0x00 ) ;
F_5 ( V_1 , 0xc5 , V_25 -> V_39 ) ;
F_5 ( V_1 , 0xdc , 0x01 ) ;
F_9 ( V_27 | V_22 , L_8 , V_25 -> V_39 ) ;
}
static void F_16 ( struct V_1 * V_1 )
{
struct V_25 * V_25 = (struct V_25 * ) V_1 ;
F_5 ( V_1 , 0xff , 0x00 ) ;
F_5 ( V_1 , 0xc7 , V_25 -> V_41 ) ;
F_5 ( V_1 , 0xdc , 0x01 ) ;
F_9 ( V_27 | V_22 , L_9 , V_25 -> V_41 ) ;
}
static void F_17 ( struct V_1 * V_1 )
{
struct V_25 * V_25 = (struct V_25 * ) V_1 ;
F_5 ( V_1 , 0xff , 0x03 ) ;
F_5 ( V_1 , 0x10 , V_25 -> V_43 >> 3 ) ;
F_5 ( V_1 , 0x11 , 0x01 ) ;
}
static void F_18 ( struct V_1 * V_1 )
{
struct V_25 * V_25 = (struct V_25 * ) V_1 ;
T_1 V_64 ;
T_3 V_45 ;
V_64 = ( 90 * V_25 -> V_45 + 1999 ) / 2000 ;
if ( V_64 < 6 )
V_64 = 6 ;
else if ( V_64 > 63 )
V_64 = 63 ;
if ( V_64 < 6 || V_64 > 12 )
V_64 = ( ( V_64 + 2 ) / 3 ) * 3 ;
V_45 = ( V_25 -> V_45 * 45 * 448 ) / ( 1000 * V_64 ) ;
V_45 = 448 - V_45 ;
F_5 ( V_1 , 0xff , 0x03 ) ;
F_5 ( V_1 , 0x02 , V_64 ) ;
F_5 ( V_1 , 0x0e , V_45 & 0xff ) ;
F_5 ( V_1 , 0x0f , V_45 >> 8 ) ;
F_5 ( V_1 , 0x11 , 0x01 ) ;
}
static void F_19 ( struct V_1 * V_1 )
{
struct V_25 * V_25 = (struct V_25 * ) V_1 ;
T_2 V_65 , V_49 , V_51 ;
V_49 = V_25 -> V_49 ;
if ( V_25 -> V_53 & V_66 )
V_49 = ! V_49 ;
V_51 = V_25 -> V_51 ;
if ( V_25 -> V_53 & V_67 )
V_51 = ! V_51 ;
F_5 ( V_1 , 0xff , 0x03 ) ;
V_65 = ( V_49 ? 0x08 : 0x00 ) | ( V_51 ? 0x04 : 0x00 ) ;
F_5 ( V_1 , 0x21 , V_65 ) ;
F_5 ( V_1 , 0x11 , 0x01 ) ;
}
static int F_20 ( struct V_1 * V_1 )
{
F_6 ( V_1 , V_68 , sizeof( V_68 ) / 2 ) ;
return V_1 -> V_6 ;
}
static int F_21 ( struct V_1 * V_1 )
{
struct V_25 * V_25 = (struct V_25 * ) V_1 ;
V_25 -> V_69 = 0 ;
F_8 ( V_1 , V_70 ,
V_71 , sizeof( V_71 ) ) ;
F_12 ( V_1 ) ;
F_13 ( V_1 ) ;
F_14 ( V_1 ) ;
F_15 ( V_1 ) ;
F_16 ( V_1 ) ;
F_17 ( V_1 ) ;
F_18 ( V_1 ) ;
F_19 ( V_1 ) ;
V_25 -> V_69 = 0 ;
V_25 -> V_72 = 0 ;
F_22 ( & V_25 -> V_73 , - 1 ) ;
F_5 ( V_1 , 0xff , 0x01 ) ;
F_5 ( V_1 , 0x78 , 0x01 ) ;
return V_1 -> V_6 ;
}
static void F_23 ( struct V_1 * V_1 )
{
F_5 ( V_1 , 0xff , 0x01 ) ;
F_5 ( V_1 , 0x78 , 0x00 ) ;
}
static void F_24 ( struct V_1 * V_1 )
{
if ( ! V_1 -> V_74 )
return;
F_5 ( V_1 , 0xff , 0x01 ) ;
F_5 ( V_1 , 0x78 , 0x40 ) ;
}
static void F_25 ( struct V_1 * V_1 )
{
struct V_25 * V_25 = (struct V_25 * ) V_1 ;
int V_73 = F_26 ( & V_25 -> V_73 ) ;
int V_75 ;
const int V_76 = 30 ;
if ( V_73 == - 1 )
return;
V_75 = 270 + V_25 -> V_31 ;
if ( V_25 -> V_72 > 0 )
V_25 -> V_72 -- ;
else if ( F_27 ( V_1 , V_73 , V_75 ,
V_76 , V_77 , V_78 ) )
V_25 -> V_72 = V_79 ;
}
static void F_28 ( struct V_1 * V_1 ,
T_3 V_80 , T_3 V_81 )
{
unsigned char V_82 [ 4 ] ;
F_29 ( V_1 , V_83 ,
V_84 , sizeof( V_84 ) ) ;
V_82 [ 0 ] = V_80 >> 8 ;
V_82 [ 1 ] = V_80 & 0xff ;
V_82 [ 2 ] = V_81 >> 8 ;
V_82 [ 3 ] = V_81 & 0xff ;
F_29 ( V_1 , V_85 ,
V_82 , sizeof( V_82 ) ) ;
F_29 ( V_1 , V_85 ,
V_86 , sizeof( V_86 ) ) ;
}
static void F_30 ( struct V_1 * V_1 ,
T_2 * V_65 ,
int V_4 )
{
struct V_25 * V_25 = (struct V_25 * ) V_1 ;
T_2 * V_87 ;
unsigned char * V_88 ;
V_88 = F_31 ( & V_25 -> V_69 , V_65 , V_4 ) ;
if ( V_88 ) {
int V_89 , V_90 , V_91 ;
V_90 = 61 + sizeof F_32 ;
V_91 = 74 ;
V_89 = ( V_88 - V_65 ) - ( V_91 + sizeof F_32 ) ;
if ( V_89 < 0 ) {
V_1 -> V_92 += V_89 ;
V_89 = 0 ;
} else {
F_29 ( V_1 , V_85 , V_65 , V_89 ) ;
}
V_87 = V_1 -> V_87 ;
if ( V_87 != NULL
&& V_87 [ V_1 -> V_92 - 2 ] == 0xff
&& V_87 [ V_1 -> V_92 - 1 ] == 0xd9 )
F_29 ( V_1 , V_93 , NULL , 0 ) ;
V_89 = V_88 - V_65 ;
V_4 -= V_89 ;
V_65 = V_88 ;
if ( V_1 -> V_94 == V_93 &&
V_89 >= V_90 )
F_22 ( & V_25 -> V_73 , V_65 [ - V_90 ] +
V_65 [ - V_90 + 1 ] ) ;
else
F_22 ( & V_25 -> V_73 , - 1 ) ;
F_28 ( V_1 ,
V_1 -> V_95 , V_1 -> V_96 ) ;
}
F_29 ( V_1 , V_85 , V_65 , V_4 ) ;
}
static int F_33 ( struct V_1 * V_1 , T_4 V_97 )
{
struct V_25 * V_25 = (struct V_25 * ) V_1 ;
V_25 -> V_31 = V_97 ;
if ( V_1 -> V_98 )
F_12 ( V_1 ) ;
return V_1 -> V_6 ;
}
static int F_34 ( struct V_1 * V_1 , T_4 * V_97 )
{
struct V_25 * V_25 = (struct V_25 * ) V_1 ;
* V_97 = V_25 -> V_31 ;
return 0 ;
}
static int F_35 ( struct V_1 * V_1 , T_4 V_97 )
{
struct V_25 * V_25 = (struct V_25 * ) V_1 ;
V_25 -> V_33 = V_97 ;
if ( V_1 -> V_98 )
F_12 ( V_1 ) ;
return V_1 -> V_6 ;
}
static int F_36 ( struct V_1 * V_1 , T_4 * V_97 )
{
struct V_25 * V_25 = (struct V_25 * ) V_1 ;
* V_97 = V_25 -> V_33 ;
return 0 ;
}
static int F_37 ( struct V_1 * V_1 , T_4 V_97 )
{
struct V_25 * V_25 = (struct V_25 * ) V_1 ;
V_25 -> V_35 = V_97 ;
if ( V_1 -> V_98 )
F_13 ( V_1 ) ;
return V_1 -> V_6 ;
}
static int F_38 ( struct V_1 * V_1 , T_4 * V_97 )
{
struct V_25 * V_25 = (struct V_25 * ) V_1 ;
* V_97 = V_25 -> V_35 ;
return 0 ;
}
static int F_39 ( struct V_1 * V_1 , T_4 V_97 )
{
struct V_25 * V_25 = (struct V_25 * ) V_1 ;
V_25 -> V_37 = V_97 ;
if ( V_1 -> V_98 )
F_14 ( V_1 ) ;
return V_1 -> V_6 ;
}
static int F_40 ( struct V_1 * V_1 , T_4 * V_97 )
{
struct V_25 * V_25 = (struct V_25 * ) V_1 ;
* V_97 = V_25 -> V_37 ;
return 0 ;
}
static int F_41 ( struct V_1 * V_1 , T_4 V_97 )
{
struct V_25 * V_25 = (struct V_25 * ) V_1 ;
V_25 -> V_39 = V_97 ;
if ( V_1 -> V_98 )
F_15 ( V_1 ) ;
return V_1 -> V_6 ;
}
static int F_42 ( struct V_1 * V_1 , T_4 * V_97 )
{
struct V_25 * V_25 = (struct V_25 * ) V_1 ;
* V_97 = V_25 -> V_39 ;
return 0 ;
}
static int F_43 ( struct V_1 * V_1 , T_4 V_97 )
{
struct V_25 * V_25 = (struct V_25 * ) V_1 ;
V_25 -> V_41 = V_97 ;
if ( V_1 -> V_98 )
F_16 ( V_1 ) ;
return V_1 -> V_6 ;
}
static int F_44 ( struct V_1 * V_1 , T_4 * V_97 )
{
struct V_25 * V_25 = (struct V_25 * ) V_1 ;
* V_97 = V_25 -> V_41 ;
return 0 ;
}
static int F_45 ( struct V_1 * V_1 , T_4 V_97 )
{
struct V_25 * V_25 = (struct V_25 * ) V_1 ;
V_25 -> V_43 = V_97 ;
if ( V_1 -> V_98 )
F_17 ( V_1 ) ;
return V_1 -> V_6 ;
}
static int F_46 ( struct V_1 * V_1 , T_4 * V_97 )
{
struct V_25 * V_25 = (struct V_25 * ) V_1 ;
* V_97 = V_25 -> V_43 ;
return 0 ;
}
static int F_47 ( struct V_1 * V_1 , T_4 V_97 )
{
struct V_25 * V_25 = (struct V_25 * ) V_1 ;
V_25 -> V_45 = V_97 ;
if ( V_1 -> V_98 )
F_18 ( V_1 ) ;
return V_1 -> V_6 ;
}
static int F_48 ( struct V_1 * V_1 , T_4 * V_97 )
{
struct V_25 * V_25 = (struct V_25 * ) V_1 ;
* V_97 = V_25 -> V_45 ;
return 0 ;
}
static int F_49 ( struct V_1 * V_1 , T_4 V_97 )
{
struct V_25 * V_25 = (struct V_25 * ) V_1 ;
V_25 -> V_47 = V_97 ;
if ( V_25 -> V_47 ) {
V_25 -> V_45 = V_46 ;
V_25 -> V_43 = V_44 ;
if ( V_1 -> V_98 ) {
V_25 -> V_72 =
V_79 ;
F_18 ( V_1 ) ;
F_17 ( V_1 ) ;
}
}
return V_1 -> V_6 ;
}
static int F_50 ( struct V_1 * V_1 , T_4 * V_97 )
{
struct V_25 * V_25 = (struct V_25 * ) V_1 ;
* V_97 = V_25 -> V_47 ;
return 0 ;
}
static int F_51 ( struct V_1 * V_1 , T_4 V_97 )
{
struct V_25 * V_25 = (struct V_25 * ) V_1 ;
V_25 -> V_49 = V_97 ;
if ( V_1 -> V_98 )
F_19 ( V_1 ) ;
return V_1 -> V_6 ;
}
static int F_52 ( struct V_1 * V_1 , T_4 * V_97 )
{
struct V_25 * V_25 = (struct V_25 * ) V_1 ;
* V_97 = V_25 -> V_49 ;
return 0 ;
}
static int F_53 ( struct V_1 * V_1 , T_4 V_97 )
{
struct V_25 * V_25 = (struct V_25 * ) V_1 ;
V_25 -> V_51 = V_97 ;
if ( V_1 -> V_98 )
F_19 ( V_1 ) ;
return V_1 -> V_6 ;
}
static int F_54 ( struct V_1 * V_1 , T_4 * V_97 )
{
struct V_25 * V_25 = (struct V_25 * ) V_1 ;
* V_97 = V_25 -> V_51 ;
return 0 ;
}
static int F_55 ( struct V_1 * V_1 ,
struct V_99 * V_100 )
{
T_1 V_2 ;
T_1 V_12 ;
if ( V_100 -> V_101 . type == V_102 &&
V_100 -> V_101 . V_103 == 0 &&
( V_100 -> V_100 < 0x000000ff ) &&
( V_100 -> V_97 <= 0x000000ff )
) {
V_2 = V_100 -> V_100 & 0x000000ff ;
V_12 = V_100 -> V_97 & 0x000000ff ;
F_5 ( V_1 , 0xff , 0x00 ) ;
F_5 ( V_1 , V_2 , V_12 ) ;
F_5 ( V_1 , 0xdc , 0x01 ) ;
}
return V_1 -> V_6 ;
}
static int F_56 ( struct V_1 * V_1 ,
struct V_104 * V_105 )
{
int V_5 = - V_106 ;
if ( V_105 -> V_101 . type == V_102 &&
V_105 -> V_101 . V_103 == 0 ) {
V_105 -> V_107 = 0 ;
V_105 -> V_108 = V_109 ;
V_5 = 0 ;
}
return V_5 ;
}
static int F_57 ( struct V_1 * V_1 ,
T_2 * V_65 ,
int V_4 )
{
int V_5 = - V_106 ;
T_2 V_110 , V_111 ;
if ( V_4 == 2 ) {
V_110 = V_65 [ 0 ] ;
V_111 = V_65 [ 1 ] ;
if ( ( V_110 == 0x00 && V_111 == 0x11 ) ||
( V_110 == 0x22 && V_111 == 0x33 ) ||
( V_110 == 0x44 && V_111 == 0x55 ) ||
( V_110 == 0x66 && V_111 == 0x77 ) ||
( V_110 == 0x88 && V_111 == 0x99 ) ||
( V_110 == 0xaa && V_111 == 0xbb ) ||
( V_110 == 0xcc && V_111 == 0xdd ) ||
( V_110 == 0xee && V_111 == 0xff ) ) {
F_58 ( V_1 -> V_112 , V_113 , 1 ) ;
F_59 ( V_1 -> V_112 ) ;
F_58 ( V_1 -> V_112 , V_113 , 0 ) ;
F_59 ( V_1 -> V_112 ) ;
V_5 = 0 ;
}
}
return V_5 ;
}
static int F_60 ( struct V_114 * V_115 ,
const struct V_23 * V_24 )
{
return F_61 ( V_115 , V_24 , & V_116 , sizeof( struct V_25 ) ,
V_117 ) ;
}
static int T_5 F_62 ( void )
{
return F_63 ( & V_118 ) ;
}
static void T_6 F_64 ( void )
{
F_65 ( & V_118 ) ;
}
