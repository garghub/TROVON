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
F_5 ( V_1 , 0xff , 0x03 ) ;
F_5 ( V_1 , 0x10 , V_25 -> V_30 [ V_49 ] . V_38 >> 3 ) ;
F_5 ( V_1 , 0x11 , 0x01 ) ;
}
static void F_19 ( struct V_1 * V_1 )
{
struct V_25 * V_25 = (struct V_25 * ) V_1 ;
T_1 V_50 ;
T_2 V_51 ;
V_50 = ( 90 * V_25 -> V_30 [ V_52 ] . V_38 + 1999 ) / 2000 ;
if ( V_50 < 6 )
V_50 = 6 ;
else if ( V_50 > 63 )
V_50 = 63 ;
if ( V_50 < 6 || V_50 > 12 )
V_50 = ( ( V_50 + 2 ) / 3 ) * 3 ;
V_51 = ( V_25 -> V_30 [ V_52 ] . V_38 * 45 * 448 ) / ( 1000 * V_50 ) ;
V_51 = 448 - V_51 ;
F_5 ( V_1 , 0xff , 0x03 ) ;
F_5 ( V_1 , 0x02 , V_50 ) ;
F_5 ( V_1 , 0x0e , V_51 & 0xff ) ;
F_5 ( V_1 , 0x0f , V_51 >> 8 ) ;
F_5 ( V_1 , 0x11 , 0x01 ) ;
}
static void F_20 ( struct V_1 * V_1 )
{
struct V_25 * V_25 = (struct V_25 * ) V_1 ;
if ( V_25 -> V_30 [ V_53 ] . V_38 ) {
V_25 -> V_30 [ V_52 ] . V_38 = V_54 ;
V_25 -> V_30 [ V_49 ] . V_38 = V_55 ;
V_25 -> V_56 =
V_57 ;
} else {
V_25 -> V_56 = - 1 ;
}
F_19 ( V_1 ) ;
F_18 ( V_1 ) ;
}
static void F_21 ( struct V_1 * V_1 )
{
struct V_25 * V_25 = (struct V_25 * ) V_1 ;
T_1 V_58 , V_59 , V_60 ;
V_59 = V_25 -> V_30 [ V_61 ] . V_38 ;
if ( V_25 -> V_31 & V_62 )
V_59 = ! V_59 ;
V_60 = V_25 -> V_30 [ V_63 ] . V_38 ;
if ( V_25 -> V_31 & V_64 )
V_60 = ! V_60 ;
F_5 ( V_1 , 0xff , 0x03 ) ;
V_58 = ( V_59 ? 0x08 : 0x00 ) | ( V_60 ? 0x04 : 0x00 ) ;
F_5 ( V_1 , 0x21 , V_58 ) ;
F_5 ( V_1 , 0x11 , 0x01 ) ;
}
static int F_22 ( struct V_1 * V_1 )
{
F_6 ( V_1 , V_65 , sizeof( V_65 ) / 2 ) ;
return V_1 -> V_6 ;
}
static int F_23 ( struct V_1 * V_1 )
{
struct V_25 * V_25 = (struct V_25 * ) V_1 ;
F_8 ( V_1 , V_66 ,
V_67 , sizeof( V_67 ) ) ;
F_13 ( V_1 ) ;
F_14 ( V_1 ) ;
F_15 ( V_1 ) ;
F_16 ( V_1 ) ;
F_17 ( V_1 ) ;
F_20 ( V_1 ) ;
F_21 ( V_1 ) ;
V_25 -> V_68 = 0 ;
F_24 ( & V_25 -> V_69 , 270 + V_25 -> V_30 [ V_37 ] . V_38 ) ;
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
if ( ! V_1 -> V_70 )
return;
F_5 ( V_1 , 0xff , 0x01 ) ;
F_5 ( V_1 , 0x78 , 0x40 ) ;
}
static void F_27 ( struct V_1 * V_1 )
{
struct V_25 * V_25 = (struct V_25 * ) V_1 ;
int V_69 = F_28 ( & V_25 -> V_69 ) ;
int V_71 ;
const int V_72 = 30 ;
if ( V_25 -> V_56 < 0 )
return;
if ( V_25 -> V_56 > 0 ) {
V_25 -> V_56 -- ;
} else {
V_71 = 270 + V_25 -> V_30 [ V_37 ] . V_38 ;
F_29 ( V_1 , V_69 , V_71 ,
V_72 , V_73 , V_74 ) ;
V_25 -> V_56 = V_57 ;
}
}
static void F_30 ( struct V_1 * V_1 ,
T_1 * V_58 ,
int V_4 )
{
struct V_25 * V_25 = (struct V_25 * ) V_1 ;
T_1 * V_75 ;
T_1 * V_76 ;
V_76 = F_31 ( & V_25 -> V_68 , V_58 , V_4 ) ;
if ( V_76 ) {
int V_77 , V_78 , V_79 ;
V_78 = 61 + sizeof F_32 ;
V_79 = 74 ;
V_77 = ( V_76 - V_58 ) - ( V_79 + sizeof F_32 ) ;
if ( V_77 < 0 ) {
V_1 -> V_80 += V_77 ;
V_77 = 0 ;
} else {
F_33 ( V_1 , V_81 , V_58 , V_77 ) ;
}
V_75 = V_1 -> V_75 ;
if ( V_75 != NULL
&& V_75 [ V_1 -> V_80 - 2 ] == 0xff
&& V_75 [ V_1 -> V_80 - 1 ] == 0xd9 )
F_33 ( V_1 , V_82 , NULL , 0 ) ;
V_77 = V_76 - V_58 ;
V_4 -= V_77 ;
V_58 = V_76 ;
if ( V_1 -> V_83 == V_82 &&
V_77 >= V_78 )
F_24 ( & V_25 -> V_69 , V_58 [ - V_78 ] +
V_58 [ - V_78 + 1 ] ) ;
F_33 ( V_1 , V_84 ,
V_85 , sizeof V_85 ) ;
}
F_33 ( V_1 , V_81 , V_58 , V_4 ) ;
}
static int F_34 ( struct V_1 * V_1 ,
struct V_86 * V_87 )
{
T_1 V_2 ;
T_1 V_12 ;
if ( V_87 -> V_88 . type == V_89 &&
V_87 -> V_88 . V_90 == 0 &&
( V_87 -> V_87 < 0x000000ff ) &&
( V_87 -> V_38 <= 0x000000ff )
) {
V_2 = V_87 -> V_87 ;
V_12 = V_87 -> V_38 ;
F_5 ( V_1 , 0xff , 0x00 ) ;
F_5 ( V_1 , V_2 , V_12 ) ;
F_5 ( V_1 , 0xdc , 0x01 ) ;
}
return V_1 -> V_6 ;
}
static int F_35 ( struct V_1 * V_1 ,
struct V_91 * V_92 )
{
int V_5 = - V_93 ;
if ( V_92 -> V_88 . type == V_89 &&
V_92 -> V_88 . V_90 == 0 ) {
V_92 -> V_94 = 0 ;
V_92 -> V_95 = V_96 ;
V_5 = 0 ;
}
return V_5 ;
}
static int F_36 ( struct V_1 * V_1 ,
T_1 * V_58 ,
int V_4 )
{
int V_5 = - V_93 ;
T_1 V_97 , V_98 ;
if ( V_4 == 2 ) {
V_97 = V_58 [ 0 ] ;
V_98 = V_58 [ 1 ] ;
if ( ( V_97 == 0x00 && V_98 == 0x11 ) ||
( V_97 == 0x22 && V_98 == 0x33 ) ||
( V_97 == 0x44 && V_98 == 0x55 ) ||
( V_97 == 0x66 && V_98 == 0x77 ) ||
( V_97 == 0x88 && V_98 == 0x99 ) ||
( V_97 == 0xaa && V_98 == 0xbb ) ||
( V_97 == 0xcc && V_98 == 0xdd ) ||
( V_97 == 0xee && V_98 == 0xff ) ) {
F_37 ( V_1 -> V_99 , V_100 , 1 ) ;
F_38 ( V_1 -> V_99 ) ;
F_37 ( V_1 -> V_99 , V_100 , 0 ) ;
F_38 ( V_1 -> V_99 ) ;
V_5 = 0 ;
}
}
return V_5 ;
}
static int F_39 ( struct V_101 * V_102 ,
const struct V_23 * V_24 )
{
return F_40 ( V_102 , V_24 , & V_103 , sizeof( struct V_25 ) ,
V_104 ) ;
}
