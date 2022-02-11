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
V_25 -> V_30 = V_24 -> V_31 ;
return 0 ;
}
static void F_13 ( struct V_1 * V_1 )
{
struct V_25 * V_25 = (struct V_25 * ) V_1 ;
int V_32 , V_33 ;
static const T_1 V_34 [ 10 ] =
{ 0x29 , 0x33 , 0x42 , 0x5a , 0x6e , 0x80 , 0x9f , 0xbb ,
0xd4 , 0xec } ;
static const T_1 V_35 [ 10 ] =
{ 0x35 , 0x33 , 0x33 , 0x2f , 0x2a , 0x25 , 0x1e , 0x17 ,
0x11 , 0x0b } ;
F_5 ( V_1 , 0xff , 0x00 ) ;
for ( V_32 = 0 ; V_32 < 10 ; V_32 ++ ) {
V_33 = V_34 [ V_32 ] ;
V_33 += ( V_25 -> V_36 -> V_37 - V_25 -> V_36 -> V_38 )
* 150 / V_25 -> V_36 -> V_38 ;
V_33 -= V_35 [ V_32 ] * V_25 -> V_39 -> V_37 / V_25 -> V_39 -> V_38 ;
if ( V_33 < 0 )
V_33 = 0 ;
else if ( V_33 > 0xff )
V_33 = 0xff ;
F_5 ( V_1 , 0xa2 + V_32 , V_33 ) ;
}
F_5 ( V_1 , 0xdc , 0x01 ) ;
}
static void F_14 ( struct V_1 * V_1 )
{
struct V_25 * V_25 = (struct V_25 * ) V_1 ;
int V_32 , V_33 ;
static const int V_40 [ 9 ] =
{ 217 , - 212 , 0 , - 101 , 170 , - 67 , - 38 , - 315 , 355 } ;
static const int V_41 [ 9 ] =
{ 19 , 106 , 0 , 19 , 106 , 1 , 19 , 106 , 1 } ;
F_5 ( V_1 , 0xff , 0x03 ) ;
F_5 ( V_1 , 0x11 , 0x01 ) ;
F_5 ( V_1 , 0xff , 0x00 ) ;
for ( V_32 = 0 ; V_32 < 9 ; V_32 ++ ) {
V_33 = V_40 [ V_32 ] * V_25 -> V_42 -> V_37 / V_25 -> V_42 -> V_38 ;
V_33 += V_41 [ V_32 ] ;
F_5 ( V_1 , 0x0f + 2 * V_32 , ( V_33 >> 8 ) & 0x07 ) ;
F_5 ( V_1 , 0x0f + 2 * V_32 + 1 , V_33 ) ;
}
F_5 ( V_1 , 0xdc , 0x01 ) ;
}
static void F_15 ( struct V_1 * V_1 )
{
struct V_25 * V_25 = (struct V_25 * ) V_1 ;
F_5 ( V_1 , 0xff , 0x00 ) ;
F_5 ( V_1 , 0xc6 , V_25 -> V_43 -> V_37 ) ;
F_5 ( V_1 , 0xdc , 0x01 ) ;
}
static void F_16 ( struct V_1 * V_1 )
{
struct V_25 * V_25 = (struct V_25 * ) V_1 ;
F_5 ( V_1 , 0xff , 0x00 ) ;
F_5 ( V_1 , 0xc5 , V_25 -> V_44 -> V_37 ) ;
F_5 ( V_1 , 0xdc , 0x01 ) ;
}
static void F_17 ( struct V_1 * V_1 )
{
struct V_25 * V_25 = (struct V_25 * ) V_1 ;
F_5 ( V_1 , 0xff , 0x00 ) ;
F_5 ( V_1 , 0xc7 , V_25 -> V_45 -> V_37 ) ;
F_5 ( V_1 , 0xdc , 0x01 ) ;
}
static void F_18 ( struct V_1 * V_1 )
{
T_1 V_46 , V_47 ;
if ( V_1 -> V_48 -> V_37 < 32 ) {
V_46 = V_1 -> V_48 -> V_37 ;
V_47 = 0 ;
} else {
V_46 = 31 ;
V_47 = V_1 -> V_48 -> V_37 - 31 ;
}
F_5 ( V_1 , 0xff , 0x03 ) ;
F_5 ( V_1 , 0x10 , V_46 ) ;
F_5 ( V_1 , 0x12 , V_47 ) ;
F_5 ( V_1 , 0x11 , 0x01 ) ;
}
static void F_19 ( struct V_1 * V_1 )
{
T_1 V_49 ;
T_2 V_50 ;
V_49 = ( 90 * V_1 -> V_50 -> V_37 + 1999 ) / 2000 ;
if ( V_49 < 6 )
V_49 = 6 ;
else if ( V_49 > 63 )
V_49 = 63 ;
if ( V_49 < 6 || V_49 > 12 )
V_49 = ( ( V_49 + 2 ) / 3 ) * 3 ;
V_50 = ( V_1 -> V_50 -> V_37 * 45 * 448 ) / ( 1000 * V_49 ) ;
V_50 = 448 - V_50 ;
F_5 ( V_1 , 0xff , 0x03 ) ;
F_5 ( V_1 , 0x02 , V_49 ) ;
F_5 ( V_1 , 0x0e , V_50 & 0xff ) ;
F_5 ( V_1 , 0x0f , V_50 >> 8 ) ;
F_5 ( V_1 , 0x11 , 0x01 ) ;
}
static void F_20 ( struct V_1 * V_1 )
{
struct V_25 * V_25 = (struct V_25 * ) V_1 ;
T_1 V_51 , V_52 , V_53 ;
V_52 = V_25 -> V_52 -> V_37 ;
if ( V_25 -> V_30 & V_54 )
V_52 = ! V_52 ;
V_53 = V_25 -> V_53 -> V_37 ;
if ( V_25 -> V_30 & V_55 )
V_53 = ! V_53 ;
F_5 ( V_1 , 0xff , 0x03 ) ;
V_51 = ( V_52 ? 0x08 : 0x00 ) | ( V_53 ? 0x04 : 0x00 ) ;
F_5 ( V_1 , 0x21 , V_51 ) ;
F_5 ( V_1 , 0x11 , 0x01 ) ;
}
static void F_21 ( struct V_1 * V_1 )
{
struct V_25 * V_25 = (struct V_25 * ) V_1 ;
F_5 ( V_1 , 0xff , 0x00 ) ;
F_5 ( V_1 , 0xb6 , V_25 -> V_56 -> V_37 ) ;
F_5 ( V_1 , 0xdc , 0x01 ) ;
}
static int F_22 ( struct V_1 * V_1 )
{
F_6 ( V_1 , V_57 , sizeof( V_57 ) / 2 ) ;
return V_1 -> V_6 ;
}
static int F_23 ( struct V_58 * V_59 )
{
struct V_1 * V_1 =
F_24 ( V_59 -> V_60 , struct V_1 , V_61 ) ;
struct V_25 * V_25 = (struct V_25 * ) V_1 ;
V_1 -> V_6 = 0 ;
if ( V_59 -> V_24 == V_62 && V_59 -> V_63 && V_59 -> V_37 ) {
V_1 -> V_50 -> V_37 = V_64 ;
V_1 -> V_48 -> V_37 = V_65 ;
V_25 -> V_66 = V_67 ;
}
if ( ! V_1 -> V_68 )
return 0 ;
switch ( V_59 -> V_24 ) {
case V_69 :
F_13 ( V_1 ) ;
break;
case V_70 :
F_14 ( V_1 ) ;
break;
case V_71 :
F_15 ( V_1 ) ;
break;
case V_72 :
F_16 ( V_1 ) ;
break;
case V_73 :
F_17 ( V_1 ) ;
break;
case V_62 :
if ( V_1 -> V_50 -> V_63 || ( V_59 -> V_63 && V_59 -> V_37 ) )
F_19 ( V_1 ) ;
if ( V_1 -> V_48 -> V_63 || ( V_59 -> V_63 && V_59 -> V_37 ) )
F_18 ( V_1 ) ;
break;
case V_74 :
F_20 ( V_1 ) ;
break;
case V_75 :
F_21 ( V_1 ) ;
break;
default:
return - V_76 ;
}
return V_1 -> V_6 ;
}
static int F_25 ( struct V_1 * V_1 )
{
struct V_25 * V_25 = (struct V_25 * ) V_1 ;
struct V_77 * V_78 = & V_1 -> V_61 ;
V_1 -> V_79 . V_61 = V_78 ;
F_26 ( V_78 , 12 ) ;
V_25 -> V_36 = F_27 ( V_78 , & V_80 ,
V_69 , 0 , 32 , 1 , 16 ) ;
V_25 -> V_39 = F_27 ( V_78 , & V_80 ,
V_81 , 0 , 255 , 1 , 127 ) ;
V_25 -> V_42 = F_27 ( V_78 , & V_80 ,
V_70 , 0 , 255 , 1 , 127 ) ;
V_25 -> V_43 = F_27 ( V_78 , & V_80 ,
V_71 ,
0 , 255 , 1 , 55 ) ;
V_25 -> V_44 = F_27 ( V_78 , & V_80 ,
V_72 , 0 , 3 , 1 , 1 ) ;
V_25 -> V_45 = F_27 ( V_78 , & V_80 ,
V_73 , 0 , 3 , 1 , 1 ) ;
V_1 -> V_82 = F_27 ( V_78 , & V_80 ,
V_62 , 0 , 1 , 1 , 1 ) ;
V_1 -> V_50 = F_27 ( V_78 , & V_80 ,
V_83 , 0 , 1023 , 1 ,
V_64 ) ;
V_1 -> V_48 = F_27 ( V_78 , & V_80 ,
V_84 , 0 , 62 , 1 ,
V_65 ) ;
V_25 -> V_52 = F_27 ( V_78 , & V_80 ,
V_74 , 0 , 1 , 1 , 0 ) ;
V_25 -> V_53 = F_27 ( V_78 , & V_80 ,
V_85 , 0 , 1 , 1 , 0 ) ;
V_25 -> V_56 = F_27 ( V_78 , & V_80 ,
V_75 , 0 , 15 , 1 , 8 ) ;
if ( V_78 -> error ) {
F_4 ( L_5 ) ;
return V_78 -> error ;
}
F_28 ( 2 , & V_25 -> V_36 ) ;
F_29 ( 3 , & V_1 -> V_82 , 0 , false ) ;
F_28 ( 2 , & V_25 -> V_52 ) ;
return 0 ;
}
static int F_30 ( struct V_1 * V_1 )
{
struct V_25 * V_25 = (struct V_25 * ) V_1 ;
F_8 ( V_1 , V_86 ,
V_87 , sizeof( V_87 ) ) ;
V_25 -> V_88 = 0 ;
V_25 -> V_66 = 0 ;
F_31 ( & V_25 -> V_89 , 270 + V_25 -> V_36 -> V_37 ) ;
F_5 ( V_1 , 0xff , 0x01 ) ;
F_5 ( V_1 , 0x78 , 0x01 ) ;
return V_1 -> V_6 ;
}
static void F_32 ( struct V_1 * V_1 )
{
F_5 ( V_1 , 0xff , 0x01 ) ;
F_5 ( V_1 , 0x78 , 0x00 ) ;
}
static void F_33 ( struct V_1 * V_1 )
{
if ( ! V_1 -> V_90 )
return;
F_5 ( V_1 , 0xff , 0x01 ) ;
F_5 ( V_1 , 0x78 , 0x40 ) ;
}
static void F_34 ( struct V_1 * V_1 )
{
struct V_25 * V_25 = (struct V_25 * ) V_1 ;
int V_89 = F_35 ( & V_25 -> V_89 ) ;
int V_91 ;
const int V_92 = 30 ;
if ( V_25 -> V_66 < 0 )
return;
if ( V_25 -> V_66 > 0 ) {
V_25 -> V_66 -- ;
} else {
V_91 = 270 + V_25 -> V_36 -> V_37 ;
if ( F_36 ( V_1 , V_89 , V_91 ,
V_92 , V_93 ,
V_94 ) )
V_25 -> V_66 =
V_67 ;
}
}
static void F_37 ( struct V_1 * V_1 ,
T_1 * V_51 ,
int V_4 )
{
struct V_25 * V_25 = (struct V_25 * ) V_1 ;
T_1 * V_95 ;
T_1 * V_96 ;
V_96 = F_38 ( & V_25 -> V_88 , V_51 , V_4 ) ;
if ( V_96 ) {
int V_97 , V_98 , V_99 ;
V_98 = 61 + sizeof F_39 ;
V_99 = 74 ;
V_97 = ( V_96 - V_51 ) - ( V_99 + sizeof F_39 ) ;
if ( V_97 < 0 ) {
V_1 -> V_100 += V_97 ;
V_97 = 0 ;
} else {
F_40 ( V_1 , V_101 , V_51 , V_97 ) ;
}
V_95 = V_1 -> V_95 ;
if ( V_95 != NULL
&& V_95 [ V_1 -> V_100 - 2 ] == 0xff
&& V_95 [ V_1 -> V_100 - 1 ] == 0xd9 )
F_40 ( V_1 , V_102 , NULL , 0 ) ;
V_97 = V_96 - V_51 ;
V_4 -= V_97 ;
V_51 = V_96 ;
if ( V_1 -> V_103 == V_102 &&
V_97 >= V_98 )
F_31 ( & V_25 -> V_89 , V_51 [ - V_98 ] +
V_51 [ - V_98 + 1 ] ) ;
F_40 ( V_1 , V_104 ,
V_105 , sizeof V_105 ) ;
}
F_40 ( V_1 , V_101 , V_51 , V_4 ) ;
}
static int F_41 ( struct V_1 * V_1 ,
struct V_106 * V_107 )
{
T_1 V_2 ;
T_1 V_12 ;
if ( V_107 -> V_108 . type == V_109 &&
V_107 -> V_108 . V_110 == 0 &&
( V_107 -> V_107 < 0x000000ff ) &&
( V_107 -> V_37 <= 0x000000ff )
) {
V_2 = V_107 -> V_107 ;
V_12 = V_107 -> V_37 ;
F_5 ( V_1 , 0xff , 0x00 ) ;
F_5 ( V_1 , V_2 , V_12 ) ;
F_5 ( V_1 , 0xdc , 0x01 ) ;
}
return V_1 -> V_6 ;
}
static int F_42 ( struct V_1 * V_1 ,
struct V_111 * V_112 )
{
int V_5 = - V_76 ;
if ( V_112 -> V_108 . type == V_109 &&
V_112 -> V_108 . V_110 == 0 ) {
V_112 -> V_113 = 0 ;
V_112 -> V_114 = V_115 ;
V_5 = 0 ;
}
return V_5 ;
}
static int F_43 ( struct V_1 * V_1 ,
T_1 * V_51 ,
int V_4 )
{
int V_5 = - V_76 ;
T_1 V_116 , V_117 ;
if ( V_4 == 2 ) {
V_116 = V_51 [ 0 ] ;
V_117 = V_51 [ 1 ] ;
if ( ( V_116 == 0x00 && V_117 == 0x11 ) ||
( V_116 == 0x22 && V_117 == 0x33 ) ||
( V_116 == 0x44 && V_117 == 0x55 ) ||
( V_116 == 0x66 && V_117 == 0x77 ) ||
( V_116 == 0x88 && V_117 == 0x99 ) ||
( V_116 == 0xaa && V_117 == 0xbb ) ||
( V_116 == 0xcc && V_117 == 0xdd ) ||
( V_116 == 0xee && V_117 == 0xff ) ) {
F_44 ( V_1 -> V_118 , V_119 , 1 ) ;
F_45 ( V_1 -> V_118 ) ;
F_44 ( V_1 -> V_118 , V_119 , 0 ) ;
F_45 ( V_1 -> V_118 ) ;
V_5 = 0 ;
}
}
return V_5 ;
}
static int F_46 ( struct V_120 * V_121 ,
const struct V_23 * V_24 )
{
return F_47 ( V_121 , V_24 , & V_122 , sizeof( struct V_25 ) ,
V_123 ) ;
}
