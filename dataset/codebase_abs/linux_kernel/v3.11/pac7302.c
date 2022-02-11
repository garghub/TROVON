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
V_31 += ( V_23 -> V_34 -> V_35 - V_23 -> V_34 -> V_36 )
* 150 / V_23 -> V_34 -> V_36 ;
V_31 -= V_33 [ V_30 ] * V_23 -> V_37 -> V_35 / V_23 -> V_37 -> V_36 ;
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
static const int V_38 [ 9 ] =
{ 217 , - 212 , 0 , - 101 , 170 , - 67 , - 38 , - 315 , 355 } ;
static const int V_39 [ 9 ] =
{ 19 , 106 , 0 , 19 , 106 , 1 , 19 , 106 , 1 } ;
F_5 ( V_1 , 0xff , 0x03 ) ;
F_5 ( V_1 , 0x11 , 0x01 ) ;
F_5 ( V_1 , 0xff , 0x00 ) ;
for ( V_30 = 0 ; V_30 < 9 ; V_30 ++ ) {
V_31 = V_38 [ V_30 ] * V_23 -> V_40 -> V_35 / V_23 -> V_40 -> V_36 ;
V_31 += V_39 [ V_30 ] ;
F_5 ( V_1 , 0x0f + 2 * V_30 , ( V_31 >> 8 ) & 0x07 ) ;
F_5 ( V_1 , 0x0f + 2 * V_30 + 1 , V_31 ) ;
}
F_5 ( V_1 , 0xdc , 0x01 ) ;
}
static void F_14 ( struct V_1 * V_1 )
{
struct V_23 * V_23 = (struct V_23 * ) V_1 ;
F_5 ( V_1 , 0xff , 0x00 ) ;
F_5 ( V_1 , 0xc6 , V_23 -> V_41 -> V_35 ) ;
F_5 ( V_1 , 0xdc , 0x01 ) ;
}
static T_1 F_15 ( T_2 V_42 )
{
const unsigned int V_43 = 1000 ;
unsigned int V_44 ;
V_44 = V_43 * ( V_42 - V_45 )
/ ( V_46 - V_45 ) ;
return 64 * V_44 * V_44 / ( V_43 * V_43 ) + 32 * V_44 / V_43 + 32 ;
}
static void F_16 ( struct V_1 * V_1 )
{
struct V_23 * V_23 = (struct V_23 * ) V_1 ;
F_5 ( V_1 , 0xff , 0x00 ) ;
F_5 ( V_1 , 0x01 ,
F_15 ( V_23 -> V_47 -> V_35 ) ) ;
F_5 ( V_1 , 0xdc , 0x01 ) ;
}
static void F_17 ( struct V_1 * V_1 )
{
struct V_23 * V_23 = (struct V_23 * ) V_1 ;
F_5 ( V_1 , 0xff , 0x00 ) ;
F_5 ( V_1 , 0x03 ,
F_15 ( V_23 -> V_48 -> V_35 ) ) ;
F_5 ( V_1 , 0xdc , 0x01 ) ;
}
static void F_18 ( struct V_1 * V_1 )
{
T_1 V_49 , V_50 ;
if ( V_1 -> V_51 -> V_35 < 32 ) {
V_49 = V_1 -> V_51 -> V_35 ;
V_50 = 0 ;
} else {
V_49 = 31 ;
V_50 = V_1 -> V_51 -> V_35 - 31 ;
}
F_5 ( V_1 , 0xff , 0x03 ) ;
F_5 ( V_1 , 0x10 , V_49 ) ;
F_5 ( V_1 , 0x12 , V_50 ) ;
F_5 ( V_1 , 0x11 , 0x01 ) ;
}
static void F_19 ( struct V_1 * V_1 )
{
T_1 V_52 ;
T_3 V_53 ;
V_52 = ( 90 * V_1 -> V_53 -> V_35 + 1999 ) / 2000 ;
if ( V_52 < 6 )
V_52 = 6 ;
else if ( V_52 > 63 )
V_52 = 63 ;
if ( V_52 < 6 || V_52 > 12 )
V_52 = ( ( V_52 + 2 ) / 3 ) * 3 ;
V_53 = ( V_1 -> V_53 -> V_35 * 45 * 448 ) / ( 1000 * V_52 ) ;
V_53 = 448 - V_53 ;
F_5 ( V_1 , 0xff , 0x03 ) ;
F_5 ( V_1 , 0x02 , V_52 ) ;
F_5 ( V_1 , 0x0e , V_53 & 0xff ) ;
F_5 ( V_1 , 0x0f , V_53 >> 8 ) ;
F_5 ( V_1 , 0x11 , 0x01 ) ;
}
static void F_20 ( struct V_1 * V_1 )
{
struct V_23 * V_23 = (struct V_23 * ) V_1 ;
T_1 V_54 , V_55 , V_56 ;
V_55 = V_23 -> V_55 -> V_35 ;
if ( V_23 -> V_28 & V_57 )
V_55 = ! V_55 ;
V_56 = V_23 -> V_56 -> V_35 ;
if ( V_23 -> V_28 & V_58 )
V_56 = ! V_56 ;
F_5 ( V_1 , 0xff , 0x03 ) ;
V_54 = ( V_55 ? 0x08 : 0x00 ) | ( V_56 ? 0x04 : 0x00 ) ;
F_5 ( V_1 , 0x21 , V_54 ) ;
F_5 ( V_1 , 0x11 , 0x01 ) ;
}
static void F_21 ( struct V_1 * V_1 )
{
struct V_23 * V_23 = (struct V_23 * ) V_1 ;
F_5 ( V_1 , 0xff , 0x00 ) ;
F_5 ( V_1 , 0xb6 , V_23 -> V_59 -> V_35 ) ;
F_5 ( V_1 , 0xdc , 0x01 ) ;
}
static int F_22 ( struct V_1 * V_1 )
{
F_6 ( V_1 , V_60 , sizeof( V_60 ) / 2 ) ;
return V_1 -> V_6 ;
}
static int F_23 ( struct V_61 * V_62 )
{
struct V_1 * V_1 =
F_24 ( V_62 -> V_63 , struct V_1 , V_64 ) ;
struct V_23 * V_23 = (struct V_23 * ) V_1 ;
V_1 -> V_6 = 0 ;
if ( V_62 -> V_22 == V_65 && V_62 -> V_66 && V_62 -> V_35 ) {
V_1 -> V_53 -> V_35 = V_67 ;
V_1 -> V_51 -> V_35 = V_68 ;
V_23 -> V_69 = V_70 ;
}
if ( ! V_1 -> V_71 )
return 0 ;
switch ( V_62 -> V_22 ) {
case V_72 :
F_12 ( V_1 ) ;
break;
case V_73 :
F_13 ( V_1 ) ;
break;
case V_74 :
F_14 ( V_1 ) ;
break;
case V_75 :
F_16 ( V_1 ) ;
break;
case V_76 :
F_17 ( V_1 ) ;
break;
case V_65 :
if ( V_1 -> V_53 -> V_66 || ( V_62 -> V_66 && V_62 -> V_35 ) )
F_19 ( V_1 ) ;
if ( V_1 -> V_51 -> V_66 || ( V_62 -> V_66 && V_62 -> V_35 ) )
F_18 ( V_1 ) ;
break;
case V_77 :
F_20 ( V_1 ) ;
break;
case V_78 :
F_21 ( V_1 ) ;
break;
default:
return - V_79 ;
}
return V_1 -> V_6 ;
}
static int F_25 ( struct V_1 * V_1 )
{
struct V_23 * V_23 = (struct V_23 * ) V_1 ;
struct V_80 * V_81 = & V_1 -> V_64 ;
V_1 -> V_82 . V_64 = V_81 ;
F_26 ( V_81 , 12 ) ;
V_23 -> V_34 = F_27 ( V_81 , & V_83 ,
V_72 , 0 , 32 , 1 , 16 ) ;
V_23 -> V_37 = F_27 ( V_81 , & V_83 ,
V_84 , 0 , 255 , 1 , 127 ) ;
V_23 -> V_40 = F_27 ( V_81 , & V_83 ,
V_73 , 0 , 255 , 1 , 127 ) ;
V_23 -> V_41 = F_27 ( V_81 , & V_83 ,
V_74 ,
0 , 255 , 1 , 55 ) ;
V_23 -> V_47 = F_27 ( V_81 , & V_83 ,
V_75 ,
V_45 ,
V_46 ,
1 , V_85 ) ;
V_23 -> V_48 = F_27 ( V_81 , & V_83 ,
V_76 ,
V_45 ,
V_46 ,
1 , V_85 ) ;
V_1 -> V_86 = F_27 ( V_81 , & V_83 ,
V_65 , 0 , 1 , 1 , 1 ) ;
V_1 -> V_53 = F_27 ( V_81 , & V_83 ,
V_87 , 0 , 1023 , 1 ,
V_67 ) ;
V_1 -> V_51 = F_27 ( V_81 , & V_83 ,
V_88 , 0 , 62 , 1 ,
V_68 ) ;
V_23 -> V_55 = F_27 ( V_81 , & V_83 ,
V_77 , 0 , 1 , 1 , 0 ) ;
V_23 -> V_56 = F_27 ( V_81 , & V_83 ,
V_89 , 0 , 1 , 1 , 0 ) ;
V_23 -> V_59 = F_27 ( V_81 , & V_83 ,
V_78 , 0 , 15 , 1 , 8 ) ;
if ( V_81 -> error ) {
F_4 ( L_5 ) ;
return V_81 -> error ;
}
F_28 ( 2 , & V_23 -> V_34 ) ;
F_29 ( 3 , & V_1 -> V_86 , 0 , false ) ;
F_28 ( 2 , & V_23 -> V_55 ) ;
return 0 ;
}
static int F_30 ( struct V_1 * V_1 )
{
struct V_23 * V_23 = (struct V_23 * ) V_1 ;
F_8 ( V_1 , V_90 ,
V_91 , sizeof( V_91 ) ) ;
V_23 -> V_92 = 0 ;
V_23 -> V_69 = 0 ;
F_31 ( & V_23 -> V_93 , 270 + V_23 -> V_34 -> V_35 ) ;
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
if ( ! V_1 -> V_94 )
return;
F_5 ( V_1 , 0xff , 0x01 ) ;
F_5 ( V_1 , 0x78 , 0x40 ) ;
}
static void F_34 ( struct V_1 * V_1 )
{
struct V_23 * V_23 = (struct V_23 * ) V_1 ;
int V_93 = F_35 ( & V_23 -> V_93 ) ;
int V_95 ;
const int V_96 = 30 ;
if ( V_23 -> V_69 < 0 )
return;
if ( V_23 -> V_69 > 0 ) {
V_23 -> V_69 -- ;
} else {
V_95 = 270 + V_23 -> V_34 -> V_35 ;
if ( F_36 ( V_1 , V_93 , V_95 ,
V_96 , V_97 ,
V_98 ) )
V_23 -> V_69 =
V_70 ;
}
}
static void F_37 ( struct V_1 * V_1 ,
T_1 * V_54 ,
int V_4 )
{
struct V_23 * V_23 = (struct V_23 * ) V_1 ;
T_1 * V_99 ;
T_1 * V_100 ;
V_100 = F_38 ( V_1 , & V_23 -> V_92 , V_54 , V_4 ) ;
if ( V_100 ) {
int V_101 , V_102 , V_103 ;
V_102 = 61 + sizeof F_39 ;
V_103 = 74 ;
V_101 = ( V_100 - V_54 ) - ( V_103 + sizeof F_39 ) ;
if ( V_101 < 0 ) {
V_1 -> V_104 += V_101 ;
V_101 = 0 ;
} else {
F_40 ( V_1 , V_105 , V_54 , V_101 ) ;
}
V_99 = V_1 -> V_99 ;
if ( V_99 != NULL
&& V_99 [ V_1 -> V_104 - 2 ] == 0xff
&& V_99 [ V_1 -> V_104 - 1 ] == 0xd9 )
F_40 ( V_1 , V_106 , NULL , 0 ) ;
V_101 = V_100 - V_54 ;
V_4 -= V_101 ;
V_54 = V_100 ;
if ( V_1 -> V_107 == V_106 &&
V_101 >= V_102 )
F_31 ( & V_23 -> V_93 , V_54 [ - V_102 ] +
V_54 [ - V_102 + 1 ] ) ;
F_40 ( V_1 , V_108 ,
V_109 , sizeof V_109 ) ;
}
F_40 ( V_1 , V_105 , V_54 , V_4 ) ;
}
static int F_41 ( struct V_1 * V_1 ,
const struct V_110 * V_111 )
{
T_1 V_2 ;
T_1 V_12 ;
if ( V_111 -> V_112 . V_113 == 0 &&
( V_111 -> V_111 < 0x000000ff ) &&
( V_111 -> V_35 <= 0x000000ff )
) {
V_2 = V_111 -> V_111 ;
V_12 = V_111 -> V_35 ;
F_5 ( V_1 , 0xff , 0x00 ) ;
F_5 ( V_1 , V_2 , V_12 ) ;
F_5 ( V_1 , 0xdc , 0x01 ) ;
}
return V_1 -> V_6 ;
}
static int F_42 ( struct V_1 * V_1 ,
T_1 * V_54 ,
int V_4 )
{
int V_5 = - V_79 ;
T_1 V_114 , V_115 ;
if ( V_4 == 2 ) {
V_114 = V_54 [ 0 ] ;
V_115 = V_54 [ 1 ] ;
if ( ( V_114 == 0x00 && V_115 == 0x11 ) ||
( V_114 == 0x22 && V_115 == 0x33 ) ||
( V_114 == 0x44 && V_115 == 0x55 ) ||
( V_114 == 0x66 && V_115 == 0x77 ) ||
( V_114 == 0x88 && V_115 == 0x99 ) ||
( V_114 == 0xaa && V_115 == 0xbb ) ||
( V_114 == 0xcc && V_115 == 0xdd ) ||
( V_114 == 0xee && V_115 == 0xff ) ) {
F_43 ( V_1 -> V_116 , V_117 , 1 ) ;
F_44 ( V_1 -> V_116 ) ;
F_43 ( V_1 -> V_116 , V_117 , 0 ) ;
F_44 ( V_1 -> V_116 ) ;
V_5 = 0 ;
}
}
return V_5 ;
}
static int F_45 ( struct V_118 * V_119 ,
const struct V_21 * V_22 )
{
return F_46 ( V_119 , V_22 , & V_120 , sizeof( struct V_23 ) ,
V_121 ) ;
}
