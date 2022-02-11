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
static int F_21 ( struct V_1 * V_1 )
{
F_6 ( V_1 , V_56 , sizeof( V_56 ) / 2 ) ;
return V_1 -> V_6 ;
}
static int F_22 ( struct V_57 * V_58 )
{
struct V_1 * V_1 =
F_23 ( V_58 -> V_59 , struct V_1 , V_60 ) ;
struct V_25 * V_25 = (struct V_25 * ) V_1 ;
V_1 -> V_6 = 0 ;
if ( V_58 -> V_24 == V_61 && V_58 -> V_62 && V_58 -> V_37 ) {
V_1 -> V_50 -> V_37 = V_63 ;
V_1 -> V_48 -> V_37 = V_64 ;
V_25 -> V_65 = V_66 ;
}
if ( ! V_1 -> V_67 )
return 0 ;
switch ( V_58 -> V_24 ) {
case V_68 :
F_13 ( V_1 ) ;
break;
case V_69 :
F_14 ( V_1 ) ;
break;
case V_70 :
F_15 ( V_1 ) ;
break;
case V_71 :
F_16 ( V_1 ) ;
break;
case V_72 :
F_17 ( V_1 ) ;
break;
case V_61 :
if ( V_1 -> V_50 -> V_62 || ( V_58 -> V_62 && V_58 -> V_37 ) )
F_19 ( V_1 ) ;
if ( V_1 -> V_48 -> V_62 || ( V_58 -> V_62 && V_58 -> V_37 ) )
F_18 ( V_1 ) ;
break;
case V_73 :
F_20 ( V_1 ) ;
break;
default:
return - V_74 ;
}
return V_1 -> V_6 ;
}
static int F_24 ( struct V_1 * V_1 )
{
struct V_25 * V_25 = (struct V_25 * ) V_1 ;
struct V_75 * V_76 = & V_1 -> V_60 ;
V_1 -> V_77 . V_60 = V_76 ;
F_25 ( V_76 , 11 ) ;
V_25 -> V_36 = F_26 ( V_76 , & V_78 ,
V_68 , 0 , 32 , 1 , 16 ) ;
V_25 -> V_39 = F_26 ( V_76 , & V_78 ,
V_79 , 0 , 255 , 1 , 127 ) ;
V_25 -> V_42 = F_26 ( V_76 , & V_78 ,
V_69 , 0 , 255 , 1 , 127 ) ;
V_25 -> V_43 = F_26 ( V_76 , & V_78 ,
V_70 ,
0 , 255 , 1 , 4 ) ;
V_25 -> V_44 = F_26 ( V_76 , & V_78 ,
V_71 , 0 , 3 , 1 , 1 ) ;
V_25 -> V_45 = F_26 ( V_76 , & V_78 ,
V_71 , 0 , 3 , 1 , 1 ) ;
V_1 -> V_80 = F_26 ( V_76 , & V_78 ,
V_61 , 0 , 1 , 1 , 1 ) ;
V_1 -> V_50 = F_26 ( V_76 , & V_78 ,
V_81 , 0 , 1023 , 1 ,
V_63 ) ;
V_1 -> V_48 = F_26 ( V_76 , & V_78 ,
V_82 , 0 , 62 , 1 ,
V_64 ) ;
V_25 -> V_52 = F_26 ( V_76 , & V_78 ,
V_73 , 0 , 1 , 1 , 0 ) ;
V_25 -> V_53 = F_26 ( V_76 , & V_78 ,
V_83 , 0 , 1 , 1 , 0 ) ;
if ( V_76 -> error ) {
F_4 ( L_5 ) ;
return V_76 -> error ;
}
F_27 ( 2 , & V_25 -> V_36 ) ;
F_28 ( 3 , & V_1 -> V_80 , 0 , false ) ;
F_27 ( 2 , & V_25 -> V_52 ) ;
return 0 ;
}
static int F_29 ( struct V_1 * V_1 )
{
struct V_25 * V_25 = (struct V_25 * ) V_1 ;
F_8 ( V_1 , V_84 ,
V_85 , sizeof( V_85 ) ) ;
F_13 ( V_1 ) ;
F_14 ( V_1 ) ;
F_15 ( V_1 ) ;
F_16 ( V_1 ) ;
F_17 ( V_1 ) ;
F_19 ( V_1 ) ;
F_18 ( V_1 ) ;
F_20 ( V_1 ) ;
V_25 -> V_86 = 0 ;
V_25 -> V_65 = 0 ;
F_30 ( & V_25 -> V_87 , 270 + V_25 -> V_36 -> V_37 ) ;
F_5 ( V_1 , 0xff , 0x01 ) ;
F_5 ( V_1 , 0x78 , 0x01 ) ;
return V_1 -> V_6 ;
}
static void F_31 ( struct V_1 * V_1 )
{
F_5 ( V_1 , 0xff , 0x01 ) ;
F_5 ( V_1 , 0x78 , 0x00 ) ;
}
static void F_32 ( struct V_1 * V_1 )
{
if ( ! V_1 -> V_88 )
return;
F_5 ( V_1 , 0xff , 0x01 ) ;
F_5 ( V_1 , 0x78 , 0x40 ) ;
}
static void F_33 ( struct V_1 * V_1 )
{
struct V_25 * V_25 = (struct V_25 * ) V_1 ;
int V_87 = F_34 ( & V_25 -> V_87 ) ;
int V_89 ;
const int V_90 = 30 ;
if ( V_25 -> V_65 < 0 )
return;
if ( V_25 -> V_65 > 0 ) {
V_25 -> V_65 -- ;
} else {
V_89 = 270 + V_25 -> V_36 -> V_37 ;
if ( F_35 ( V_1 , V_87 , V_89 ,
V_90 , V_91 ,
V_92 ) )
V_25 -> V_65 =
V_66 ;
}
}
static void F_36 ( struct V_1 * V_1 ,
T_1 * V_51 ,
int V_4 )
{
struct V_25 * V_25 = (struct V_25 * ) V_1 ;
T_1 * V_93 ;
T_1 * V_94 ;
V_94 = F_37 ( & V_25 -> V_86 , V_51 , V_4 ) ;
if ( V_94 ) {
int V_95 , V_96 , V_97 ;
V_96 = 61 + sizeof F_38 ;
V_97 = 74 ;
V_95 = ( V_94 - V_51 ) - ( V_97 + sizeof F_38 ) ;
if ( V_95 < 0 ) {
V_1 -> V_98 += V_95 ;
V_95 = 0 ;
} else {
F_39 ( V_1 , V_99 , V_51 , V_95 ) ;
}
V_93 = V_1 -> V_93 ;
if ( V_93 != NULL
&& V_93 [ V_1 -> V_98 - 2 ] == 0xff
&& V_93 [ V_1 -> V_98 - 1 ] == 0xd9 )
F_39 ( V_1 , V_100 , NULL , 0 ) ;
V_95 = V_94 - V_51 ;
V_4 -= V_95 ;
V_51 = V_94 ;
if ( V_1 -> V_101 == V_100 &&
V_95 >= V_96 )
F_30 ( & V_25 -> V_87 , V_51 [ - V_96 ] +
V_51 [ - V_96 + 1 ] ) ;
F_39 ( V_1 , V_102 ,
V_103 , sizeof V_103 ) ;
}
F_39 ( V_1 , V_99 , V_51 , V_4 ) ;
}
static int F_40 ( struct V_1 * V_1 ,
struct V_104 * V_105 )
{
T_1 V_2 ;
T_1 V_12 ;
if ( V_105 -> V_106 . type == V_107 &&
V_105 -> V_106 . V_108 == 0 &&
( V_105 -> V_105 < 0x000000ff ) &&
( V_105 -> V_37 <= 0x000000ff )
) {
V_2 = V_105 -> V_105 ;
V_12 = V_105 -> V_37 ;
F_5 ( V_1 , 0xff , 0x00 ) ;
F_5 ( V_1 , V_2 , V_12 ) ;
F_5 ( V_1 , 0xdc , 0x01 ) ;
}
return V_1 -> V_6 ;
}
static int F_41 ( struct V_1 * V_1 ,
struct V_109 * V_110 )
{
int V_5 = - V_74 ;
if ( V_110 -> V_106 . type == V_107 &&
V_110 -> V_106 . V_108 == 0 ) {
V_110 -> V_111 = 0 ;
V_110 -> V_112 = V_113 ;
V_5 = 0 ;
}
return V_5 ;
}
static int F_42 ( struct V_1 * V_1 ,
T_1 * V_51 ,
int V_4 )
{
int V_5 = - V_74 ;
T_1 V_114 , V_115 ;
if ( V_4 == 2 ) {
V_114 = V_51 [ 0 ] ;
V_115 = V_51 [ 1 ] ;
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
const struct V_23 * V_24 )
{
return F_46 ( V_119 , V_24 , & V_120 , sizeof( struct V_25 ) ,
V_121 ) ;
}
