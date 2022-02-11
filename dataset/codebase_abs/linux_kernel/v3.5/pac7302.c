static void F_1 ( struct V_1 * V_1 ,
T_1 V_2 ,
const T_1 * V_3 , int V_4 )
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
#ifdef F_9
if ( V_4 > V_20 ) {
F_10 ( V_21 | V_22 ,
L_4 ) ;
return;
}
#endif
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
static int F_11 ( struct V_1 * V_1 ,
const struct V_23 * V_24 )
{
struct V_25 * V_25 = (struct V_25 * ) V_1 ;
struct V_26 * V_26 ;
V_26 = & V_1 -> V_26 ;
V_26 -> V_27 = V_28 ;
V_26 -> V_29 = F_12 ( V_28 ) ;
V_1 -> V_26 . V_30 = V_25 -> V_30 ;
V_25 -> V_31 = V_24 -> V_32 ;
return 0 ;
}
static void F_13 ( struct V_1 * V_1 )
{
struct V_25 * V_25 = (struct V_25 * ) V_1 ;
int V_33 , V_34 ;
static const T_1 V_35 [ 10 ] =
{ 0x29 , 0x33 , 0x42 , 0x5a , 0x6e , 0x80 , 0x9f , 0xbb ,
0xd4 , 0xec } ;
static const T_1 V_36 [ 10 ] =
{ 0x35 , 0x33 , 0x33 , 0x2f , 0x2a , 0x25 , 0x1e , 0x17 ,
0x11 , 0x0b } ;
F_5 ( V_1 , 0xff , 0x00 ) ;
for ( V_33 = 0 ; V_33 < 10 ; V_33 ++ ) {
V_34 = V_35 [ V_33 ] ;
V_34 += ( V_25 -> V_30 [ V_37 ] . V_38 - V_39 )
* 150 / V_39 ;
V_34 -= V_36 [ V_33 ] * V_25 -> V_30 [ V_40 ] . V_38 / V_41 ;
if ( V_34 < 0 )
V_34 = 0 ;
else if ( V_34 > 0xff )
V_34 = 0xff ;
F_5 ( V_1 , 0xa2 + V_33 , V_34 ) ;
}
F_5 ( V_1 , 0xdc , 0x01 ) ;
}
static void F_14 ( struct V_1 * V_1 )
{
struct V_25 * V_25 = (struct V_25 * ) V_1 ;
int V_33 , V_34 ;
static const int V_42 [ 9 ] =
{ 217 , - 212 , 0 , - 101 , 170 , - 67 , - 38 , - 315 , 355 } ;
static const int V_43 [ 9 ] =
{ 19 , 106 , 0 , 19 , 106 , 1 , 19 , 106 , 1 } ;
F_5 ( V_1 , 0xff , 0x03 ) ;
F_5 ( V_1 , 0x11 , 0x01 ) ;
F_5 ( V_1 , 0xff , 0x00 ) ;
for ( V_33 = 0 ; V_33 < 9 ; V_33 ++ ) {
V_34 = V_42 [ V_33 ] * V_25 -> V_30 [ V_44 ] . V_38 / V_45 + V_43 [ V_33 ] ;
F_5 ( V_1 , 0x0f + 2 * V_33 , ( V_34 >> 8 ) & 0x07 ) ;
F_5 ( V_1 , 0x0f + 2 * V_33 + 1 , V_34 ) ;
}
F_5 ( V_1 , 0xdc , 0x01 ) ;
}
static void F_15 ( struct V_1 * V_1 )
{
struct V_25 * V_25 = (struct V_25 * ) V_1 ;
F_5 ( V_1 , 0xff , 0x00 ) ;
F_5 ( V_1 , 0xc6 , V_25 -> V_30 [ V_46 ] . V_38 ) ;
F_5 ( V_1 , 0xdc , 0x01 ) ;
}
static void F_16 ( struct V_1 * V_1 )
{
struct V_25 * V_25 = (struct V_25 * ) V_1 ;
F_5 ( V_1 , 0xff , 0x00 ) ;
F_5 ( V_1 , 0xc5 , V_25 -> V_30 [ V_47 ] . V_38 ) ;
F_5 ( V_1 , 0xdc , 0x01 ) ;
}
static void F_17 ( struct V_1 * V_1 )
{
struct V_25 * V_25 = (struct V_25 * ) V_1 ;
F_5 ( V_1 , 0xff , 0x00 ) ;
F_5 ( V_1 , 0xc7 , V_25 -> V_30 [ V_48 ] . V_38 ) ;
F_5 ( V_1 , 0xdc , 0x01 ) ;
}
static void F_18 ( struct V_1 * V_1 )
{
struct V_25 * V_25 = (struct V_25 * ) V_1 ;
T_1 V_49 , V_50 ;
if ( V_25 -> V_30 [ V_51 ] . V_38 < 32 ) {
V_49 = V_25 -> V_30 [ V_51 ] . V_38 ;
V_50 = 0 ;
} else {
V_49 = 31 ;
V_50 = V_25 -> V_30 [ V_51 ] . V_38 - 31 ;
}
F_5 ( V_1 , 0xff , 0x03 ) ;
F_5 ( V_1 , 0x10 , V_49 ) ;
F_5 ( V_1 , 0x12 , V_50 ) ;
F_5 ( V_1 , 0x11 , 0x01 ) ;
}
static void F_19 ( struct V_1 * V_1 )
{
struct V_25 * V_25 = (struct V_25 * ) V_1 ;
T_1 V_52 ;
T_2 V_53 ;
V_52 = ( 90 * V_25 -> V_30 [ V_54 ] . V_38 + 1999 ) / 2000 ;
if ( V_52 < 6 )
V_52 = 6 ;
else if ( V_52 > 63 )
V_52 = 63 ;
if ( V_52 < 6 || V_52 > 12 )
V_52 = ( ( V_52 + 2 ) / 3 ) * 3 ;
V_53 = ( V_25 -> V_30 [ V_54 ] . V_38 * 45 * 448 ) / ( 1000 * V_52 ) ;
V_53 = 448 - V_53 ;
F_5 ( V_1 , 0xff , 0x03 ) ;
F_5 ( V_1 , 0x02 , V_52 ) ;
F_5 ( V_1 , 0x0e , V_53 & 0xff ) ;
F_5 ( V_1 , 0x0f , V_53 >> 8 ) ;
F_5 ( V_1 , 0x11 , 0x01 ) ;
}
static void F_20 ( struct V_1 * V_1 )
{
struct V_25 * V_25 = (struct V_25 * ) V_1 ;
if ( V_25 -> V_30 [ V_55 ] . V_38 ) {
V_25 -> V_30 [ V_54 ] . V_38 = V_56 ;
V_25 -> V_30 [ V_51 ] . V_38 = V_57 ;
V_25 -> V_58 =
V_59 ;
} else {
V_25 -> V_58 = - 1 ;
}
F_19 ( V_1 ) ;
F_18 ( V_1 ) ;
}
static void F_21 ( struct V_1 * V_1 )
{
struct V_25 * V_25 = (struct V_25 * ) V_1 ;
T_1 V_60 , V_61 , V_62 ;
V_61 = V_25 -> V_30 [ V_63 ] . V_38 ;
if ( V_25 -> V_31 & V_64 )
V_61 = ! V_61 ;
V_62 = V_25 -> V_30 [ V_65 ] . V_38 ;
if ( V_25 -> V_31 & V_66 )
V_62 = ! V_62 ;
F_5 ( V_1 , 0xff , 0x03 ) ;
V_60 = ( V_61 ? 0x08 : 0x00 ) | ( V_62 ? 0x04 : 0x00 ) ;
F_5 ( V_1 , 0x21 , V_60 ) ;
F_5 ( V_1 , 0x11 , 0x01 ) ;
}
static int F_22 ( struct V_1 * V_1 )
{
F_6 ( V_1 , V_67 , sizeof( V_67 ) / 2 ) ;
return V_1 -> V_6 ;
}
static int F_23 ( struct V_1 * V_1 )
{
struct V_25 * V_25 = (struct V_25 * ) V_1 ;
F_8 ( V_1 , V_68 ,
V_69 , sizeof( V_69 ) ) ;
F_13 ( V_1 ) ;
F_14 ( V_1 ) ;
F_15 ( V_1 ) ;
F_16 ( V_1 ) ;
F_17 ( V_1 ) ;
F_20 ( V_1 ) ;
F_21 ( V_1 ) ;
V_25 -> V_70 = 0 ;
F_24 ( & V_25 -> V_71 , 270 + V_25 -> V_30 [ V_37 ] . V_38 ) ;
F_5 ( V_1 , 0xff , 0x01 ) ;
F_5 ( V_1 , 0x78 , 0x01 ) ;
return V_1 -> V_6 ;
}
static void F_25 ( struct V_1 * V_1 )
{
F_5 ( V_1 , 0xff , 0x01 ) ;
F_5 ( V_1 , 0x78 , 0x00 ) ;
}
static void F_26 ( struct V_1 * V_1 )
{
if ( ! V_1 -> V_72 )
return;
F_5 ( V_1 , 0xff , 0x01 ) ;
F_5 ( V_1 , 0x78 , 0x40 ) ;
}
static void F_27 ( struct V_1 * V_1 )
{
struct V_25 * V_25 = (struct V_25 * ) V_1 ;
int V_71 = F_28 ( & V_25 -> V_71 ) ;
int V_73 ;
const int V_74 = 30 ;
if ( V_25 -> V_58 < 0 )
return;
if ( V_25 -> V_58 > 0 ) {
V_25 -> V_58 -- ;
} else {
V_73 = 270 + V_25 -> V_30 [ V_37 ] . V_38 ;
F_29 ( V_1 , V_71 , V_73 ,
V_74 , V_75 , V_76 ) ;
V_25 -> V_58 = V_59 ;
}
}
static void F_30 ( struct V_1 * V_1 ,
T_1 * V_60 ,
int V_4 )
{
struct V_25 * V_25 = (struct V_25 * ) V_1 ;
T_1 * V_77 ;
T_1 * V_78 ;
V_78 = F_31 ( & V_25 -> V_70 , V_60 , V_4 ) ;
if ( V_78 ) {
int V_79 , V_80 , V_81 ;
V_80 = 61 + sizeof F_32 ;
V_81 = 74 ;
V_79 = ( V_78 - V_60 ) - ( V_81 + sizeof F_32 ) ;
if ( V_79 < 0 ) {
V_1 -> V_82 += V_79 ;
V_79 = 0 ;
} else {
F_33 ( V_1 , V_83 , V_60 , V_79 ) ;
}
V_77 = V_1 -> V_77 ;
if ( V_77 != NULL
&& V_77 [ V_1 -> V_82 - 2 ] == 0xff
&& V_77 [ V_1 -> V_82 - 1 ] == 0xd9 )
F_33 ( V_1 , V_84 , NULL , 0 ) ;
V_79 = V_78 - V_60 ;
V_4 -= V_79 ;
V_60 = V_78 ;
if ( V_1 -> V_85 == V_84 &&
V_79 >= V_80 )
F_24 ( & V_25 -> V_71 , V_60 [ - V_80 ] +
V_60 [ - V_80 + 1 ] ) ;
F_33 ( V_1 , V_86 ,
V_87 , sizeof V_87 ) ;
}
F_33 ( V_1 , V_83 , V_60 , V_4 ) ;
}
static int F_34 ( struct V_1 * V_1 ,
struct V_88 * V_89 )
{
T_1 V_2 ;
T_1 V_12 ;
if ( V_89 -> V_90 . type == V_91 &&
V_89 -> V_90 . V_92 == 0 &&
( V_89 -> V_89 < 0x000000ff ) &&
( V_89 -> V_38 <= 0x000000ff )
) {
V_2 = V_89 -> V_89 ;
V_12 = V_89 -> V_38 ;
F_5 ( V_1 , 0xff , 0x00 ) ;
F_5 ( V_1 , V_2 , V_12 ) ;
F_5 ( V_1 , 0xdc , 0x01 ) ;
}
return V_1 -> V_6 ;
}
static int F_35 ( struct V_1 * V_1 ,
struct V_93 * V_94 )
{
int V_5 = - V_95 ;
if ( V_94 -> V_90 . type == V_91 &&
V_94 -> V_90 . V_92 == 0 ) {
V_94 -> V_96 = 0 ;
V_94 -> V_97 = V_98 ;
V_5 = 0 ;
}
return V_5 ;
}
static int F_36 ( struct V_1 * V_1 ,
T_1 * V_60 ,
int V_4 )
{
int V_5 = - V_95 ;
T_1 V_99 , V_100 ;
if ( V_4 == 2 ) {
V_99 = V_60 [ 0 ] ;
V_100 = V_60 [ 1 ] ;
if ( ( V_99 == 0x00 && V_100 == 0x11 ) ||
( V_99 == 0x22 && V_100 == 0x33 ) ||
( V_99 == 0x44 && V_100 == 0x55 ) ||
( V_99 == 0x66 && V_100 == 0x77 ) ||
( V_99 == 0x88 && V_100 == 0x99 ) ||
( V_99 == 0xaa && V_100 == 0xbb ) ||
( V_99 == 0xcc && V_100 == 0xdd ) ||
( V_99 == 0xee && V_100 == 0xff ) ) {
F_37 ( V_1 -> V_101 , V_102 , 1 ) ;
F_38 ( V_1 -> V_101 ) ;
F_37 ( V_1 -> V_101 , V_102 , 0 ) ;
F_38 ( V_1 -> V_101 ) ;
V_5 = 0 ;
}
}
return V_5 ;
}
static int F_39 ( struct V_103 * V_104 ,
const struct V_23 * V_24 )
{
return F_40 ( V_104 , V_24 , & V_105 , sizeof( struct V_25 ) ,
V_106 ) ;
}
