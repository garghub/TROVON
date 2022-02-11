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
if ( V_4 > V_20 ) {
F_9 ( L_4 ) ;
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
const struct V_21 * V_22 )
{
struct V_23 * V_23 = (struct V_23 * ) V_1 ;
struct V_24 * V_24 ;
V_24 = & V_1 -> V_24 ;
V_24 -> V_25 = V_26 ;
V_24 -> V_27 = F_11 ( V_26 ) ;
V_23 -> V_28 = V_22 -> V_29 ;
return 0 ;
}
static void F_12 ( struct V_1 * V_1 )
{
struct V_23 * V_23 = (struct V_23 * ) V_1 ;
int V_30 , V_31 ;
static const T_1 V_32 [ 10 ] =
{ 0x29 , 0x33 , 0x42 , 0x5a , 0x6e , 0x80 , 0x9f , 0xbb ,
0xd4 , 0xec } ;
static const T_1 V_33 [ 10 ] =
{ 0x35 , 0x33 , 0x33 , 0x2f , 0x2a , 0x25 , 0x1e , 0x17 ,
0x11 , 0x0b } ;
F_5 ( V_1 , 0xff , 0x00 ) ;
for ( V_30 = 0 ; V_30 < 10 ; V_30 ++ ) {
V_31 = V_32 [ V_30 ] ;
V_31 += ( V_23 -> V_34 -> V_35 - ( V_36 ) V_23 -> V_34 -> V_37 )
* 150 / ( V_36 ) V_23 -> V_34 -> V_37 ;
V_31 -= V_33 [ V_30 ] * V_23 -> V_38 -> V_35 / ( V_36 ) V_23 -> V_38 -> V_37 ;
if ( V_31 < 0 )
V_31 = 0 ;
else if ( V_31 > 0xff )
V_31 = 0xff ;
F_5 ( V_1 , 0xa2 + V_30 , V_31 ) ;
}
F_5 ( V_1 , 0xdc , 0x01 ) ;
}
static void F_13 ( struct V_1 * V_1 )
{
struct V_23 * V_23 = (struct V_23 * ) V_1 ;
int V_30 , V_31 ;
static const int V_39 [ 9 ] =
{ 217 , - 212 , 0 , - 101 , 170 , - 67 , - 38 , - 315 , 355 } ;
static const int V_40 [ 9 ] =
{ 19 , 106 , 0 , 19 , 106 , 1 , 19 , 106 , 1 } ;
F_5 ( V_1 , 0xff , 0x03 ) ;
F_5 ( V_1 , 0x11 , 0x01 ) ;
F_5 ( V_1 , 0xff , 0x00 ) ;
for ( V_30 = 0 ; V_30 < 9 ; V_30 ++ ) {
V_31 = V_39 [ V_30 ] * V_23 -> V_41 -> V_35 / ( V_36 ) V_23 -> V_41 -> V_37 ;
V_31 += V_40 [ V_30 ] ;
F_5 ( V_1 , 0x0f + 2 * V_30 , ( V_31 >> 8 ) & 0x07 ) ;
F_5 ( V_1 , 0x0f + 2 * V_30 + 1 , V_31 ) ;
}
F_5 ( V_1 , 0xdc , 0x01 ) ;
}
static void F_14 ( struct V_1 * V_1 )
{
struct V_23 * V_23 = (struct V_23 * ) V_1 ;
F_5 ( V_1 , 0xff , 0x00 ) ;
F_5 ( V_1 , 0xc6 , V_23 -> V_42 -> V_35 ) ;
F_5 ( V_1 , 0xdc , 0x01 ) ;
}
static T_1 F_15 ( V_36 V_43 )
{
const unsigned int V_44 = 1000 ;
unsigned int V_45 ;
V_45 = V_44 * ( V_43 - V_46 )
/ ( V_47 - V_46 ) ;
return 64 * V_45 * V_45 / ( V_44 * V_44 ) + 32 * V_45 / V_44 + 32 ;
}
static void F_16 ( struct V_1 * V_1 )
{
struct V_23 * V_23 = (struct V_23 * ) V_1 ;
F_5 ( V_1 , 0xff , 0x00 ) ;
F_5 ( V_1 , 0x01 ,
F_15 ( V_23 -> V_48 -> V_35 ) ) ;
F_5 ( V_1 , 0xdc , 0x01 ) ;
}
static void F_17 ( struct V_1 * V_1 )
{
struct V_23 * V_23 = (struct V_23 * ) V_1 ;
F_5 ( V_1 , 0xff , 0x00 ) ;
F_5 ( V_1 , 0x03 ,
F_15 ( V_23 -> V_49 -> V_35 ) ) ;
F_5 ( V_1 , 0xdc , 0x01 ) ;
}
static void F_18 ( struct V_1 * V_1 )
{
T_1 V_50 , V_51 ;
if ( V_1 -> V_52 -> V_35 < 32 ) {
V_50 = V_1 -> V_52 -> V_35 ;
V_51 = 0 ;
} else {
V_50 = 31 ;
V_51 = V_1 -> V_52 -> V_35 - 31 ;
}
F_5 ( V_1 , 0xff , 0x03 ) ;
F_5 ( V_1 , 0x10 , V_50 ) ;
F_5 ( V_1 , 0x12 , V_51 ) ;
F_5 ( V_1 , 0x11 , 0x01 ) ;
}
static void F_19 ( struct V_1 * V_1 )
{
T_1 V_53 ;
T_2 V_54 ;
V_53 = ( 90 * V_1 -> V_54 -> V_35 + 1999 ) / 2000 ;
if ( V_53 < 6 )
V_53 = 6 ;
else if ( V_53 > 63 )
V_53 = 63 ;
if ( V_53 < 6 || V_53 > 12 )
V_53 = ( ( V_53 + 2 ) / 3 ) * 3 ;
V_54 = ( V_1 -> V_54 -> V_35 * 45 * 448 ) / ( 1000 * V_53 ) ;
V_54 = 448 - V_54 ;
F_5 ( V_1 , 0xff , 0x03 ) ;
F_5 ( V_1 , 0x02 , V_53 ) ;
F_5 ( V_1 , 0x0e , V_54 & 0xff ) ;
F_5 ( V_1 , 0x0f , V_54 >> 8 ) ;
F_5 ( V_1 , 0x11 , 0x01 ) ;
}
static void F_20 ( struct V_1 * V_1 )
{
struct V_23 * V_23 = (struct V_23 * ) V_1 ;
T_1 V_55 , V_56 , V_57 ;
V_56 = V_23 -> V_56 -> V_35 ;
if ( V_23 -> V_28 & V_58 )
V_56 = ! V_56 ;
V_57 = V_23 -> V_57 -> V_35 ;
if ( V_23 -> V_28 & V_59 )
V_57 = ! V_57 ;
F_5 ( V_1 , 0xff , 0x03 ) ;
V_55 = ( V_56 ? 0x08 : 0x00 ) | ( V_57 ? 0x04 : 0x00 ) ;
F_5 ( V_1 , 0x21 , V_55 ) ;
F_5 ( V_1 , 0x11 , 0x01 ) ;
}
static void F_21 ( struct V_1 * V_1 )
{
struct V_23 * V_23 = (struct V_23 * ) V_1 ;
F_5 ( V_1 , 0xff , 0x00 ) ;
F_5 ( V_1 , 0xb6 , V_23 -> V_60 -> V_35 ) ;
F_5 ( V_1 , 0xdc , 0x01 ) ;
}
static int F_22 ( struct V_1 * V_1 )
{
F_6 ( V_1 , V_61 , sizeof( V_61 ) / 2 ) ;
return V_1 -> V_6 ;
}
static int F_23 ( struct V_62 * V_63 )
{
struct V_1 * V_1 =
F_24 ( V_63 -> V_64 , struct V_1 , V_65 ) ;
struct V_23 * V_23 = (struct V_23 * ) V_1 ;
V_1 -> V_6 = 0 ;
if ( V_63 -> V_22 == V_66 && V_63 -> V_67 && V_63 -> V_35 ) {
V_1 -> V_54 -> V_35 = V_68 ;
V_1 -> V_52 -> V_35 = V_69 ;
V_23 -> V_70 = V_71 ;
}
if ( ! V_1 -> V_72 )
return 0 ;
switch ( V_63 -> V_22 ) {
case V_73 :
F_12 ( V_1 ) ;
break;
case V_74 :
F_13 ( V_1 ) ;
break;
case V_75 :
F_14 ( V_1 ) ;
break;
case V_76 :
F_16 ( V_1 ) ;
break;
case V_77 :
F_17 ( V_1 ) ;
break;
case V_66 :
if ( V_1 -> V_54 -> V_67 || ( V_63 -> V_67 && V_63 -> V_35 ) )
F_19 ( V_1 ) ;
if ( V_1 -> V_52 -> V_67 || ( V_63 -> V_67 && V_63 -> V_35 ) )
F_18 ( V_1 ) ;
break;
case V_78 :
F_20 ( V_1 ) ;
break;
case V_79 :
F_21 ( V_1 ) ;
break;
default:
return - V_80 ;
}
return V_1 -> V_6 ;
}
static int F_25 ( struct V_1 * V_1 )
{
struct V_23 * V_23 = (struct V_23 * ) V_1 ;
struct V_81 * V_82 = & V_1 -> V_65 ;
V_1 -> V_83 . V_65 = V_82 ;
F_26 ( V_82 , 12 ) ;
V_23 -> V_34 = F_27 ( V_82 , & V_84 ,
V_73 , 0 , 32 , 1 , 16 ) ;
V_23 -> V_38 = F_27 ( V_82 , & V_84 ,
V_85 , 0 , 255 , 1 , 127 ) ;
V_23 -> V_41 = F_27 ( V_82 , & V_84 ,
V_74 , 0 , 255 , 1 , 127 ) ;
V_23 -> V_42 = F_27 ( V_82 , & V_84 ,
V_75 ,
0 , 255 , 1 , 55 ) ;
V_23 -> V_48 = F_27 ( V_82 , & V_84 ,
V_76 ,
V_46 ,
V_47 ,
1 , V_86 ) ;
V_23 -> V_49 = F_27 ( V_82 , & V_84 ,
V_77 ,
V_46 ,
V_47 ,
1 , V_86 ) ;
V_1 -> V_87 = F_27 ( V_82 , & V_84 ,
V_66 , 0 , 1 , 1 , 1 ) ;
V_1 -> V_54 = F_27 ( V_82 , & V_84 ,
V_88 , 0 , 1023 , 1 ,
V_68 ) ;
V_1 -> V_52 = F_27 ( V_82 , & V_84 ,
V_89 , 0 , 62 , 1 ,
V_69 ) ;
V_23 -> V_56 = F_27 ( V_82 , & V_84 ,
V_78 , 0 , 1 , 1 , 0 ) ;
V_23 -> V_57 = F_27 ( V_82 , & V_84 ,
V_90 , 0 , 1 , 1 , 0 ) ;
V_23 -> V_60 = F_27 ( V_82 , & V_84 ,
V_79 , 0 , 15 , 1 , 8 ) ;
if ( V_82 -> error ) {
F_4 ( L_5 ) ;
return V_82 -> error ;
}
F_28 ( 2 , & V_23 -> V_34 ) ;
F_29 ( 3 , & V_1 -> V_87 , 0 , false ) ;
F_28 ( 2 , & V_23 -> V_56 ) ;
return 0 ;
}
static int F_30 ( struct V_1 * V_1 )
{
struct V_23 * V_23 = (struct V_23 * ) V_1 ;
F_8 ( V_1 , V_91 ,
V_92 , sizeof( V_92 ) ) ;
V_23 -> V_93 = 0 ;
V_23 -> V_70 = 0 ;
F_31 ( & V_23 -> V_94 , 270 + V_23 -> V_34 -> V_35 ) ;
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
if ( ! V_1 -> V_95 )
return;
F_5 ( V_1 , 0xff , 0x01 ) ;
F_5 ( V_1 , 0x78 , 0x40 ) ;
}
static void F_34 ( struct V_1 * V_1 )
{
struct V_23 * V_23 = (struct V_23 * ) V_1 ;
int V_94 = F_35 ( & V_23 -> V_94 ) ;
int V_96 ;
const int V_97 = 30 ;
if ( V_23 -> V_70 < 0 )
return;
if ( V_23 -> V_70 > 0 ) {
V_23 -> V_70 -- ;
} else {
V_96 = 270 + V_23 -> V_34 -> V_35 ;
if ( F_36 ( V_1 , V_94 , V_96 ,
V_97 , V_98 ,
V_99 ) )
V_23 -> V_70 =
V_71 ;
}
}
static void F_37 ( struct V_1 * V_1 ,
T_1 * V_55 ,
int V_4 )
{
struct V_23 * V_23 = (struct V_23 * ) V_1 ;
T_1 * V_100 ;
T_1 * V_101 ;
V_101 = F_38 ( V_1 , & V_23 -> V_93 , V_55 , V_4 ) ;
if ( V_101 ) {
int V_102 , V_103 , V_104 ;
V_103 = 61 + sizeof F_39 ;
V_104 = 74 ;
V_102 = ( V_101 - V_55 ) - ( V_104 + sizeof F_39 ) ;
if ( V_102 < 0 ) {
V_1 -> V_105 += V_102 ;
V_102 = 0 ;
} else {
F_40 ( V_1 , V_106 , V_55 , V_102 ) ;
}
V_100 = V_1 -> V_100 ;
if ( V_100 != NULL
&& V_100 [ V_1 -> V_105 - 2 ] == 0xff
&& V_100 [ V_1 -> V_105 - 1 ] == 0xd9 )
F_40 ( V_1 , V_107 , NULL , 0 ) ;
V_102 = V_101 - V_55 ;
V_4 -= V_102 ;
V_55 = V_101 ;
if ( V_1 -> V_108 == V_107 &&
V_102 >= V_103 )
F_31 ( & V_23 -> V_94 , V_55 [ - V_103 ] +
V_55 [ - V_103 + 1 ] ) ;
F_40 ( V_1 , V_109 ,
V_110 , sizeof V_110 ) ;
}
F_40 ( V_1 , V_106 , V_55 , V_4 ) ;
}
static int F_41 ( struct V_1 * V_1 ,
const struct V_111 * V_112 )
{
T_1 V_2 ;
T_1 V_12 ;
if ( V_112 -> V_113 . V_114 == 0 &&
( V_112 -> V_112 < 0x000000ff ) &&
( V_112 -> V_35 <= 0x000000ff )
) {
V_2 = V_112 -> V_112 ;
V_12 = V_112 -> V_35 ;
F_5 ( V_1 , 0xff , 0x00 ) ;
F_5 ( V_1 , V_2 , V_12 ) ;
F_5 ( V_1 , 0xdc , 0x01 ) ;
}
return V_1 -> V_6 ;
}
static int F_42 ( struct V_1 * V_1 ,
T_1 * V_55 ,
int V_4 )
{
int V_5 = - V_80 ;
T_1 V_115 , V_116 ;
if ( V_4 == 2 ) {
V_115 = V_55 [ 0 ] ;
V_116 = V_55 [ 1 ] ;
if ( ( V_115 == 0x00 && V_116 == 0x11 ) ||
( V_115 == 0x22 && V_116 == 0x33 ) ||
( V_115 == 0x44 && V_116 == 0x55 ) ||
( V_115 == 0x66 && V_116 == 0x77 ) ||
( V_115 == 0x88 && V_116 == 0x99 ) ||
( V_115 == 0xaa && V_116 == 0xbb ) ||
( V_115 == 0xcc && V_116 == 0xdd ) ||
( V_115 == 0xee && V_116 == 0xff ) ) {
F_43 ( V_1 -> V_117 , V_118 , 1 ) ;
F_44 ( V_1 -> V_117 ) ;
F_43 ( V_1 -> V_117 , V_118 , 0 ) ;
F_44 ( V_1 -> V_117 ) ;
V_5 = 0 ;
}
}
return V_5 ;
}
static int F_45 ( struct V_119 * V_120 ,
const struct V_21 * V_22 )
{
return F_46 ( V_120 , V_22 , & V_121 , sizeof( struct V_23 ) ,
V_122 ) ;
}
