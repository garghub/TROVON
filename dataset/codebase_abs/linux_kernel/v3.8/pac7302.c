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
static T_1 F_16 ( T_2 V_44 )
{
const unsigned int V_45 = 1000 ;
unsigned int V_46 ;
V_46 = V_45 * ( V_44 - V_47 )
/ ( V_48 - V_47 ) ;
return 64 * V_46 * V_46 / ( V_45 * V_45 ) + 32 * V_46 / V_45 + 32 ;
}
static void F_17 ( struct V_1 * V_1 )
{
struct V_25 * V_25 = (struct V_25 * ) V_1 ;
F_5 ( V_1 , 0xff , 0x00 ) ;
F_5 ( V_1 , 0x01 ,
F_16 ( V_25 -> V_49 -> V_37 ) ) ;
F_5 ( V_1 , 0xdc , 0x01 ) ;
}
static void F_18 ( struct V_1 * V_1 )
{
struct V_25 * V_25 = (struct V_25 * ) V_1 ;
F_5 ( V_1 , 0xff , 0x00 ) ;
F_5 ( V_1 , 0x03 ,
F_16 ( V_25 -> V_50 -> V_37 ) ) ;
F_5 ( V_1 , 0xdc , 0x01 ) ;
}
static void F_19 ( struct V_1 * V_1 )
{
T_1 V_51 , V_52 ;
if ( V_1 -> V_53 -> V_37 < 32 ) {
V_51 = V_1 -> V_53 -> V_37 ;
V_52 = 0 ;
} else {
V_51 = 31 ;
V_52 = V_1 -> V_53 -> V_37 - 31 ;
}
F_5 ( V_1 , 0xff , 0x03 ) ;
F_5 ( V_1 , 0x10 , V_51 ) ;
F_5 ( V_1 , 0x12 , V_52 ) ;
F_5 ( V_1 , 0x11 , 0x01 ) ;
}
static void F_20 ( struct V_1 * V_1 )
{
T_1 V_54 ;
T_3 V_55 ;
V_54 = ( 90 * V_1 -> V_55 -> V_37 + 1999 ) / 2000 ;
if ( V_54 < 6 )
V_54 = 6 ;
else if ( V_54 > 63 )
V_54 = 63 ;
if ( V_54 < 6 || V_54 > 12 )
V_54 = ( ( V_54 + 2 ) / 3 ) * 3 ;
V_55 = ( V_1 -> V_55 -> V_37 * 45 * 448 ) / ( 1000 * V_54 ) ;
V_55 = 448 - V_55 ;
F_5 ( V_1 , 0xff , 0x03 ) ;
F_5 ( V_1 , 0x02 , V_54 ) ;
F_5 ( V_1 , 0x0e , V_55 & 0xff ) ;
F_5 ( V_1 , 0x0f , V_55 >> 8 ) ;
F_5 ( V_1 , 0x11 , 0x01 ) ;
}
static void F_21 ( struct V_1 * V_1 )
{
struct V_25 * V_25 = (struct V_25 * ) V_1 ;
T_1 V_56 , V_57 , V_58 ;
V_57 = V_25 -> V_57 -> V_37 ;
if ( V_25 -> V_30 & V_59 )
V_57 = ! V_57 ;
V_58 = V_25 -> V_58 -> V_37 ;
if ( V_25 -> V_30 & V_60 )
V_58 = ! V_58 ;
F_5 ( V_1 , 0xff , 0x03 ) ;
V_56 = ( V_57 ? 0x08 : 0x00 ) | ( V_58 ? 0x04 : 0x00 ) ;
F_5 ( V_1 , 0x21 , V_56 ) ;
F_5 ( V_1 , 0x11 , 0x01 ) ;
}
static void F_22 ( struct V_1 * V_1 )
{
struct V_25 * V_25 = (struct V_25 * ) V_1 ;
F_5 ( V_1 , 0xff , 0x00 ) ;
F_5 ( V_1 , 0xb6 , V_25 -> V_61 -> V_37 ) ;
F_5 ( V_1 , 0xdc , 0x01 ) ;
}
static int F_23 ( struct V_1 * V_1 )
{
F_6 ( V_1 , V_62 , sizeof( V_62 ) / 2 ) ;
return V_1 -> V_6 ;
}
static int F_24 ( struct V_63 * V_64 )
{
struct V_1 * V_1 =
F_25 ( V_64 -> V_65 , struct V_1 , V_66 ) ;
struct V_25 * V_25 = (struct V_25 * ) V_1 ;
V_1 -> V_6 = 0 ;
if ( V_64 -> V_24 == V_67 && V_64 -> V_68 && V_64 -> V_37 ) {
V_1 -> V_55 -> V_37 = V_69 ;
V_1 -> V_53 -> V_37 = V_70 ;
V_25 -> V_71 = V_72 ;
}
if ( ! V_1 -> V_73 )
return 0 ;
switch ( V_64 -> V_24 ) {
case V_74 :
F_13 ( V_1 ) ;
break;
case V_75 :
F_14 ( V_1 ) ;
break;
case V_76 :
F_15 ( V_1 ) ;
break;
case V_77 :
F_17 ( V_1 ) ;
break;
case V_78 :
F_18 ( V_1 ) ;
break;
case V_67 :
if ( V_1 -> V_55 -> V_68 || ( V_64 -> V_68 && V_64 -> V_37 ) )
F_20 ( V_1 ) ;
if ( V_1 -> V_53 -> V_68 || ( V_64 -> V_68 && V_64 -> V_37 ) )
F_19 ( V_1 ) ;
break;
case V_79 :
F_21 ( V_1 ) ;
break;
case V_80 :
F_22 ( V_1 ) ;
break;
default:
return - V_81 ;
}
return V_1 -> V_6 ;
}
static int F_26 ( struct V_1 * V_1 )
{
struct V_25 * V_25 = (struct V_25 * ) V_1 ;
struct V_82 * V_83 = & V_1 -> V_66 ;
V_1 -> V_84 . V_66 = V_83 ;
F_27 ( V_83 , 12 ) ;
V_25 -> V_36 = F_28 ( V_83 , & V_85 ,
V_74 , 0 , 32 , 1 , 16 ) ;
V_25 -> V_39 = F_28 ( V_83 , & V_85 ,
V_86 , 0 , 255 , 1 , 127 ) ;
V_25 -> V_42 = F_28 ( V_83 , & V_85 ,
V_75 , 0 , 255 , 1 , 127 ) ;
V_25 -> V_43 = F_28 ( V_83 , & V_85 ,
V_76 ,
0 , 255 , 1 , 55 ) ;
V_25 -> V_49 = F_28 ( V_83 , & V_85 ,
V_77 ,
V_47 ,
V_48 ,
1 , V_87 ) ;
V_25 -> V_50 = F_28 ( V_83 , & V_85 ,
V_78 ,
V_47 ,
V_48 ,
1 , V_87 ) ;
V_1 -> V_88 = F_28 ( V_83 , & V_85 ,
V_67 , 0 , 1 , 1 , 1 ) ;
V_1 -> V_55 = F_28 ( V_83 , & V_85 ,
V_89 , 0 , 1023 , 1 ,
V_69 ) ;
V_1 -> V_53 = F_28 ( V_83 , & V_85 ,
V_90 , 0 , 62 , 1 ,
V_70 ) ;
V_25 -> V_57 = F_28 ( V_83 , & V_85 ,
V_79 , 0 , 1 , 1 , 0 ) ;
V_25 -> V_58 = F_28 ( V_83 , & V_85 ,
V_91 , 0 , 1 , 1 , 0 ) ;
V_25 -> V_61 = F_28 ( V_83 , & V_85 ,
V_80 , 0 , 15 , 1 , 8 ) ;
if ( V_83 -> error ) {
F_4 ( L_5 ) ;
return V_83 -> error ;
}
F_29 ( 2 , & V_25 -> V_36 ) ;
F_30 ( 3 , & V_1 -> V_88 , 0 , false ) ;
F_29 ( 2 , & V_25 -> V_57 ) ;
return 0 ;
}
static int F_31 ( struct V_1 * V_1 )
{
struct V_25 * V_25 = (struct V_25 * ) V_1 ;
F_8 ( V_1 , V_92 ,
V_93 , sizeof( V_93 ) ) ;
V_25 -> V_94 = 0 ;
V_25 -> V_71 = 0 ;
F_32 ( & V_25 -> V_95 , 270 + V_25 -> V_36 -> V_37 ) ;
F_5 ( V_1 , 0xff , 0x01 ) ;
F_5 ( V_1 , 0x78 , 0x01 ) ;
return V_1 -> V_6 ;
}
static void F_33 ( struct V_1 * V_1 )
{
F_5 ( V_1 , 0xff , 0x01 ) ;
F_5 ( V_1 , 0x78 , 0x00 ) ;
}
static void F_34 ( struct V_1 * V_1 )
{
if ( ! V_1 -> V_96 )
return;
F_5 ( V_1 , 0xff , 0x01 ) ;
F_5 ( V_1 , 0x78 , 0x40 ) ;
}
static void F_35 ( struct V_1 * V_1 )
{
struct V_25 * V_25 = (struct V_25 * ) V_1 ;
int V_95 = F_36 ( & V_25 -> V_95 ) ;
int V_97 ;
const int V_98 = 30 ;
if ( V_25 -> V_71 < 0 )
return;
if ( V_25 -> V_71 > 0 ) {
V_25 -> V_71 -- ;
} else {
V_97 = 270 + V_25 -> V_36 -> V_37 ;
if ( F_37 ( V_1 , V_95 , V_97 ,
V_98 , V_99 ,
V_100 ) )
V_25 -> V_71 =
V_72 ;
}
}
static void F_38 ( struct V_1 * V_1 ,
T_1 * V_56 ,
int V_4 )
{
struct V_25 * V_25 = (struct V_25 * ) V_1 ;
T_1 * V_101 ;
T_1 * V_102 ;
V_102 = F_39 ( & V_25 -> V_94 , V_56 , V_4 ) ;
if ( V_102 ) {
int V_103 , V_104 , V_105 ;
V_104 = 61 + sizeof F_40 ;
V_105 = 74 ;
V_103 = ( V_102 - V_56 ) - ( V_105 + sizeof F_40 ) ;
if ( V_103 < 0 ) {
V_1 -> V_106 += V_103 ;
V_103 = 0 ;
} else {
F_41 ( V_1 , V_107 , V_56 , V_103 ) ;
}
V_101 = V_1 -> V_101 ;
if ( V_101 != NULL
&& V_101 [ V_1 -> V_106 - 2 ] == 0xff
&& V_101 [ V_1 -> V_106 - 1 ] == 0xd9 )
F_41 ( V_1 , V_108 , NULL , 0 ) ;
V_103 = V_102 - V_56 ;
V_4 -= V_103 ;
V_56 = V_102 ;
if ( V_1 -> V_109 == V_108 &&
V_103 >= V_104 )
F_32 ( & V_25 -> V_95 , V_56 [ - V_104 ] +
V_56 [ - V_104 + 1 ] ) ;
F_41 ( V_1 , V_110 ,
V_111 , sizeof V_111 ) ;
}
F_41 ( V_1 , V_107 , V_56 , V_4 ) ;
}
static int F_42 ( struct V_1 * V_1 ,
struct V_112 * V_113 )
{
T_1 V_2 ;
T_1 V_12 ;
if ( V_113 -> V_114 . type == V_115 &&
V_113 -> V_114 . V_116 == 0 &&
( V_113 -> V_113 < 0x000000ff ) &&
( V_113 -> V_37 <= 0x000000ff )
) {
V_2 = V_113 -> V_113 ;
V_12 = V_113 -> V_37 ;
F_5 ( V_1 , 0xff , 0x00 ) ;
F_5 ( V_1 , V_2 , V_12 ) ;
F_5 ( V_1 , 0xdc , 0x01 ) ;
}
return V_1 -> V_6 ;
}
static int F_43 ( struct V_1 * V_1 ,
struct V_117 * V_118 )
{
int V_5 = - V_81 ;
if ( V_118 -> V_114 . type == V_115 &&
V_118 -> V_114 . V_116 == 0 ) {
V_118 -> V_119 = 0 ;
V_118 -> V_120 = V_121 ;
V_5 = 0 ;
}
return V_5 ;
}
static int F_44 ( struct V_1 * V_1 ,
T_1 * V_56 ,
int V_4 )
{
int V_5 = - V_81 ;
T_1 V_122 , V_123 ;
if ( V_4 == 2 ) {
V_122 = V_56 [ 0 ] ;
V_123 = V_56 [ 1 ] ;
if ( ( V_122 == 0x00 && V_123 == 0x11 ) ||
( V_122 == 0x22 && V_123 == 0x33 ) ||
( V_122 == 0x44 && V_123 == 0x55 ) ||
( V_122 == 0x66 && V_123 == 0x77 ) ||
( V_122 == 0x88 && V_123 == 0x99 ) ||
( V_122 == 0xaa && V_123 == 0xbb ) ||
( V_122 == 0xcc && V_123 == 0xdd ) ||
( V_122 == 0xee && V_123 == 0xff ) ) {
F_45 ( V_1 -> V_124 , V_125 , 1 ) ;
F_46 ( V_1 -> V_124 ) ;
F_45 ( V_1 -> V_124 , V_125 , 0 ) ;
F_46 ( V_1 -> V_124 ) ;
V_5 = 0 ;
}
}
return V_5 ;
}
static int F_47 ( struct V_126 * V_127 ,
const struct V_23 * V_24 )
{
return F_48 ( V_127 , V_24 , & V_128 , sizeof( struct V_25 ) ,
V_129 ) ;
}
