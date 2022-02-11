static void F_1 ( struct V_1 * V_1 ,
T_1 V_2 ,
T_2 V_3 ,
T_2 V_4 )
{
int V_5 ;
if ( V_4 > V_6 ) {
F_2 ( L_1 ) ;
return;
}
if ( V_1 -> V_7 < 0 )
return;
V_5 = F_3 ( V_1 -> V_8 ,
F_4 ( V_1 -> V_8 , 0 ) ,
V_2 ,
V_9 | V_10 | V_11 ,
0 ,
V_3 ,
V_4 ? V_1 -> V_12 : NULL , V_4 ,
500 ) ;
if ( V_5 < 0 ) {
F_5 ( L_2 , V_5 ) ;
V_1 -> V_7 = V_5 ;
}
}
static void F_6 ( struct V_1 * V_1 ,
T_1 V_2 ,
T_2 V_13 ,
T_2 V_3 ,
T_2 V_14 )
{
int V_5 ;
if ( V_1 -> V_7 < 0 )
return;
V_1 -> V_12 [ 0 ] = V_14 ;
V_5 = F_3 ( V_1 -> V_8 ,
F_7 ( V_1 -> V_8 , 0 ) ,
V_2 ,
V_15 | V_10 | V_11 ,
V_13 , V_3 ,
V_1 -> V_12 , 1 ,
500 ) ;
if ( V_5 < 0 ) {
F_5 ( L_3 , V_5 ) ;
V_1 -> V_7 = V_5 ;
}
}
static void F_8 ( struct V_1 * V_1 ,
T_1 V_2 , T_2 V_3 , T_2 V_13 )
{
struct V_16 * V_8 = V_1 -> V_8 ;
int V_5 ;
if ( V_1 -> V_7 < 0 )
return;
V_5 = F_3 ( V_8 ,
F_7 ( V_8 , 0 ) ,
V_2 ,
V_15 | V_10 | V_11 ,
V_13 , V_3 , NULL , 0 , 500 ) ;
if ( V_5 < 0 ) {
F_5 ( L_4 , V_5 ) ;
V_1 -> V_7 = V_5 ;
return;
}
F_9 ( V_17 , L_5 ,
V_2 , V_3 , V_13 ) ;
}
static void F_10 ( struct V_1 * V_1 ,
const struct V_18 * V_19 , int V_20 )
{
while ( -- V_20 >= 0 ) {
F_8 ( V_1 , V_19 -> V_2 , V_19 -> V_21 , V_19 -> V_22 ) ;
V_19 ++ ;
}
}
static void F_11 ( struct V_1 * V_1 ,
const T_1 V_23 [ 2 ] [ 64 ] )
{
int V_24 ;
for ( V_24 = 0 ; V_24 < 64 ; V_24 ++ )
F_8 ( V_1 , 0x00 , 0x2800 + V_24 , V_23 [ 0 ] [ V_24 ] ) ;
for ( V_24 = 0 ; V_24 < 64 ; V_24 ++ )
F_8 ( V_1 , 0x00 , 0x2840 + V_24 , V_23 [ 1 ] [ V_24 ] ) ;
}
static void F_12 ( struct V_1 * V_1 ,
T_1 V_2 , T_2 V_21 , T_2 V_22 )
{
F_8 ( V_1 , V_2 , V_21 , V_22 ) ;
F_1 ( V_1 , 0x01 , 0x0001 , 1 ) ;
F_9 ( V_25 , L_6 , V_1 -> V_12 [ 0 ] ) ;
F_8 ( V_1 , V_2 , V_21 , V_22 ) ;
F_13 ( 200 ) ;
F_1 ( V_1 , 0x01 , 0x0001 , 1 ) ;
F_9 ( V_25 , L_7 , V_1 -> V_12 [ 0 ] ) ;
}
static void F_14 ( struct V_1 * V_1 )
{
int V_24 ;
T_1 V_26 [ 6 ] ;
if ( V_27 < V_28 )
return;
for ( V_24 = 0 ; V_24 < 6 ; V_24 ++ ) {
F_1 ( V_1 , 0 , V_24 , 1 ) ;
V_26 [ V_24 ] = V_1 -> V_12 [ 0 ] ;
}
F_9 ( V_28 ,
L_8
L_9 ,
V_26 [ 0 ] , V_26 [ 1 ] , V_26 [ 2 ] ,
V_26 [ 3 ] , V_26 [ 4 ] , V_26 [ 5 ] ) ;
}
static void F_15 ( struct V_1 * V_1 ,
T_1 V_2 ,
T_2 V_21 , T_2 V_22 , T_1 V_29 , T_1 V_30 )
{
T_2 V_31 ;
F_8 ( V_1 , V_2 , V_21 , V_22 ) ;
F_1 ( V_1 , 0x01 , 0x0001 , 1 ) ;
if ( V_1 -> V_7 < 0 )
return;
F_9 ( V_25 , L_10 ,
V_1 -> V_12 [ 0 ] , V_29 ) ;
if ( ! V_30 )
return;
V_30 = 200 ;
while ( -- V_30 > 0 ) {
F_13 ( 10 ) ;
F_1 ( V_1 , 0x01 , 0x0001 , 1 ) ;
V_31 = V_1 -> V_12 [ 0 ] ;
if ( V_31 == V_29 ) {
F_9 ( V_25 , L_11 ,
V_31 , 200 - V_30 ) ;
break;
}
}
}
static void F_16 ( struct V_1 * V_1 )
{
int V_30 = 10 ;
while ( -- V_30 > 0 ) {
F_1 ( V_1 , 0x21 , 0 , 1 ) ;
if ( ( V_1 -> V_12 [ 0 ] & 0x01 ) == 0 )
break;
F_13 ( 10 ) ;
}
}
static void F_17 ( struct V_1 * V_1 )
{
int V_30 = 50 ;
while ( -- V_30 > 0 ) {
F_1 ( V_1 , 0x21 , 1 , 1 ) ;
if ( V_1 -> V_12 [ 0 ] != 0 ) {
F_6 ( V_1 , 0x21 , 0 , 1 , 0 ) ;
F_1 ( V_1 , 0x21 , 1 , 1 ) ;
F_16 ( V_1 ) ;
break;
}
F_13 ( 10 ) ;
}
}
static void F_18 ( struct V_1 * V_1 )
{
T_1 * V_19 ;
if ( V_27 < V_28 )
return;
V_19 = V_1 -> V_12 ;
F_1 ( V_1 , 0x20 , 0 , 5 ) ;
F_9 ( V_28 , L_12 ,
V_19 [ 0 ] , V_19 [ 1 ] , V_19 [ 2 ] , V_19 [ 3 ] , V_19 [ 4 ] ) ;
F_1 ( V_1 , 0x23 , 0 , 64 ) ;
F_1 ( V_1 , 0x23 , 1 , 64 ) ;
}
static void F_19 ( struct V_1 * V_1 )
{
struct V_32 * V_32 = (struct V_32 * ) V_1 ;
T_1 V_33 ;
V_33 = V_1 -> V_34 . V_35 [ V_1 -> V_36 ] . V_37 ;
switch ( V_32 -> V_38 ) {
case V_39 :
F_8 ( V_1 , 0x31 , 0 , 0 ) ;
F_17 ( V_1 ) ;
F_16 ( V_1 ) ;
F_18 ( V_1 ) ;
F_6 ( V_1 , 0x24 , 0 , 8 , 2 ) ;
F_1 ( V_1 , 0x24 , 8 , 1 ) ;
F_6 ( V_1 , 0x25 , 0 , 4 , V_33 ) ;
F_1 ( V_1 , 0x25 , 4 , 1 ) ;
F_16 ( V_1 ) ;
F_8 ( V_1 , 0x31 , 0x0004 , 0x00 ) ;
F_17 ( V_1 ) ;
F_16 ( V_1 ) ;
break;
default:
F_6 ( V_1 , 0x25 , 0 , 4 , V_33 ) ;
F_1 ( V_1 , 0x25 , 4 , 1 ) ;
F_6 ( V_1 , 0x27 , 0 , 0 , 6 ) ;
F_1 ( V_1 , 0x27 , 0 , 1 ) ;
F_16 ( V_1 ) ;
break;
case V_40 :
V_33 += 3 ;
if ( V_32 -> V_41 == V_42 ) {
F_15 ( V_1 ,
0x08 , V_33 , 0 ,
0x80 | ( V_33 & 0x0f ) , 1 ) ;
F_15 ( V_1 ,
1 , 3 , 0 , 0x9f , 0 ) ;
} else {
F_12 ( V_1 , 0x08 , V_33 , 0 ) ;
}
break;
case V_43 :
F_8 ( V_1 , 0xa0 , ( 0x0500 | ( V_33 & 0x0f ) ) , 0x00 ) ;
F_8 ( V_1 , 0x20 , 0x01 , 0x0500 | ( V_33 & 0x0f ) ) ;
break;
}
}
static void F_20 ( struct V_1 * V_1 )
{
int V_44 ;
V_44 = 256 ;
while ( -- V_44 > 0 ) {
F_1 ( V_1 , 0x06 , 0x00 , 1 ) ;
if ( V_1 -> V_12 [ 0 ] == 0 )
return;
F_13 ( 10 ) ;
}
}
static void F_21 ( struct V_1 * V_1 )
{
F_6 ( V_1 , 0x26 , 0 , 0 , 3 ) ;
F_1 ( V_1 , 0x26 , 0 , 1 ) ;
F_16 ( V_1 ) ;
}
static void F_22 ( struct V_1 * V_1 , T_3 V_22 )
{
struct V_32 * V_32 = (struct V_32 * ) V_1 ;
T_2 V_45 ;
V_45 = V_32 -> V_38 == V_46 ? 0x20f0 : 0x21a7 ;
F_8 ( V_1 , 0x00 , V_45 , V_22 ) ;
}
static void F_23 ( struct V_1 * V_1 , T_3 V_22 )
{
struct V_32 * V_32 = (struct V_32 * ) V_1 ;
T_2 V_45 ;
V_45 = V_32 -> V_38 == V_46 ? 0x20f1 : 0x21a8 ;
F_8 ( V_1 , 0x00 , V_45 , V_22 ) ;
}
static void F_24 ( struct V_1 * V_1 , T_3 V_22 )
{
struct V_32 * V_32 = (struct V_32 * ) V_1 ;
T_2 V_45 ;
V_45 = V_32 -> V_38 == V_46 ? 0x20f6 : 0x21ae ;
F_8 ( V_1 , 0x00 , V_45 , V_22 ) ;
}
static void F_25 ( struct V_1 * V_1 )
{
struct V_32 * V_32 = (struct V_32 * ) V_1 ;
int V_47 = 1 ;
switch ( V_32 -> V_38 ) {
case V_40 :
case V_43 :
V_47 = 0 ;
default:
F_8 ( V_1 , 0 , 0x21ad , 0x00 ) ;
F_8 ( V_1 , 0 , 0x21ac , 0x01 ) ;
F_8 ( V_1 , 0 , 0x21a3 , 0x00 ) ;
break;
case V_46 :
F_8 ( V_1 , 0 , 0x20f5 , 0x40 ) ;
F_8 ( V_1 , 0 , 0x20f4 , 0x01 ) ;
F_8 ( V_1 , 0 , 0x2089 , 0x00 ) ;
break;
}
if ( V_47 )
F_16 ( V_1 ) ;
}
static int F_26 ( struct V_1 * V_1 ,
const struct V_48 * V_49 )
{
struct V_32 * V_32 = (struct V_32 * ) V_1 ;
struct V_34 * V_34 ;
V_34 = & V_1 -> V_34 ;
V_32 -> V_38 = V_49 -> V_50 >> 8 ;
V_32 -> V_41 = V_49 -> V_50 ;
if ( V_32 -> V_41 == V_42 ) {
F_1 ( V_1 , 0x20 , 0 , 1 ) ;
switch ( V_1 -> V_12 [ 0 ] ) {
case 1 :
break;
case 2 :
V_32 -> V_38 = V_51 ;
V_32 -> V_41 = 0 ;
break;
default:
return - V_52 ;
}
}
switch ( V_32 -> V_38 ) {
default:
V_34 -> V_35 = V_53 ;
V_34 -> V_54 = F_27 ( V_53 ) ;
break;
case V_39 :
V_34 -> V_35 = V_55 ;
if ( V_32 -> V_41 == V_56 )
V_34 -> V_54 = F_27 ( V_55 ) - 1 ;
else
V_34 -> V_54 = F_27 ( V_55 ) ;
break;
case V_43 :
V_34 -> V_35 = V_57 ;
V_34 -> V_54 = F_27 ( V_57 ) ;
break;
}
return 0 ;
}
static int F_28 ( struct V_1 * V_1 )
{
struct V_32 * V_32 = (struct V_32 * ) V_1 ;
switch ( V_32 -> V_38 ) {
case V_51 :
F_8 ( V_1 , 0x1d , 0x00 , 0 ) ;
F_8 ( V_1 , 0x00 , 0x2306 , 0x01 ) ;
F_8 ( V_1 , 0x00 , 0x0d04 , 0x00 ) ;
F_8 ( V_1 , 0x00 , 0x2000 , 0x00 ) ;
F_8 ( V_1 , 0x00 , 0x2301 , 0x13 ) ;
F_8 ( V_1 , 0x00 , 0x2306 , 0x00 ) ;
case V_39 :
F_16 ( V_1 ) ;
F_18 ( V_1 ) ;
break;
case V_46 :
F_18 ( V_1 ) ;
F_1 ( V_1 , 0x00 , 0x5002 , 1 ) ;
F_6 ( V_1 , 0x24 , 0 , 0 , 0 ) ;
F_1 ( V_1 , 0x24 , 0 , 1 ) ;
F_16 ( V_1 ) ;
F_8 ( V_1 , 0x34 , 0 , 0 ) ;
F_17 ( V_1 ) ;
break;
case V_43 :
F_9 ( V_28 , L_13 ) ;
F_8 ( V_1 , 0xe0 , 0x0000 , 0x0000 ) ;
F_8 ( V_1 , 0xe0 , 0x0000 , 0x0001 ) ;
F_20 ( V_1 ) ;
if ( V_32 -> V_41 == V_58 )
F_10 ( V_1 ,
V_59 ,
F_27 ( V_59 ) ) ;
else
F_10 ( V_1 , V_60 ,
F_27 ( V_60 ) ) ;
F_11 ( V_1 , V_61 ) ;
break;
default:
F_9 ( V_28 , L_14 ) ;
if ( V_32 -> V_41 == V_42 ) {
F_14 ( V_1 ) ;
F_15 ( V_1 , 0x24 ,
8 , 3 , 0x9e , 1 ) ;
F_15 ( V_1 , 0x24 ,
8 , 3 , 0x9e , 0 ) ;
F_15 ( V_1 , 0x24 ,
0 , 0 , 0x9d , 1 ) ;
F_15 ( V_1 , 0x08 ,
6 , 0 , 0x86 , 1 ) ;
F_8 ( V_1 , 0x00 , 0x270c , 0x05 ) ;
F_8 ( V_1 , 0x00 , 0x2310 , 0x05 ) ;
F_15 ( V_1 , 0x01 ,
0x0f , 0 , 0xff , 0 ) ;
}
F_8 ( V_1 , 0 , 0x2000 , 0 ) ;
F_8 ( V_1 , 0 , 0x2883 , 1 ) ;
F_11 ( V_1 , V_62 ) ;
break;
}
return V_1 -> V_7 ;
}
static int F_29 ( struct V_1 * V_1 )
{
struct V_32 * V_32 = (struct V_32 * ) V_1 ;
int V_63 ;
F_30 ( V_32 -> V_64 , V_1 -> V_65 , V_1 -> V_66 ,
0x22 ) ;
F_31 ( V_32 -> V_64 , V_67 ) ;
if ( V_32 -> V_38 == V_51 )
F_21 ( V_1 ) ;
F_19 ( V_1 ) ;
switch ( V_32 -> V_38 ) {
default:
switch ( V_32 -> V_41 ) {
case V_68 :
case V_69 :
case V_56 :
F_8 ( V_1 , 0xf0 , 0 , 0 ) ;
F_17 ( V_1 ) ;
F_1 ( V_1 , 0xf0 , 4 , 0 ) ;
F_17 ( V_1 ) ;
break;
default:
F_8 ( V_1 , 0x31 , 0x0004 , 0x00 ) ;
F_17 ( V_1 ) ;
F_16 ( V_1 ) ;
break;
}
break;
case V_40 :
if ( V_32 -> V_41 == V_42 ) {
F_14 ( V_1 ) ;
F_15 ( V_1 , 0x24 ,
8 , 3 , 0x9e , 1 ) ;
F_15 ( V_1 , 0x24 ,
8 , 3 , 0x9e , 0 ) ;
F_15 ( V_1 , 0x24 ,
0 , 0 , 0x9d , 1 ) ;
} else {
F_12 ( V_1 , 0x24 , 8 , 3 ) ;
F_14 ( V_1 ) ;
F_12 ( V_1 , 0x24 , 8 , 3 ) ;
F_12 ( V_1 , 0x24 , 0 , 0 ) ;
}
F_19 ( V_1 ) ;
F_8 ( V_1 , 0x00 , 0x270c , 0x05 ) ;
F_8 ( V_1 , 0x00 , 0x2310 , 0x05 ) ;
break;
case V_43 :
if ( V_32 -> V_41 == V_58 ) {
F_10 ( V_1 ,
V_70 ,
F_27 ( V_70 ) ) ;
} else {
F_10 ( V_1 , V_71 ,
F_27 ( V_71 ) ) ;
}
V_63 = ( V_32 -> V_72 ? 0x04 : 0x01 ) ;
F_8 ( V_1 , 0x0c , 0x0000 , V_63 ) ;
F_8 ( V_1 , 0xb0 , 0x0000 , V_63 ) ;
F_8 ( V_1 , 0x30 , 0x0001 , 800 ) ;
F_8 ( V_1 , 0x30 , 0x0002 , 1600 ) ;
F_19 ( V_1 ) ;
break;
}
F_25 ( V_1 ) ;
return V_1 -> V_7 ;
}
static void F_32 ( struct V_1 * V_1 )
{
struct V_32 * V_32 = (struct V_32 * ) V_1 ;
switch ( V_32 -> V_38 ) {
default:
F_8 ( V_1 , 0x31 , 0 , 0 ) ;
F_17 ( V_1 ) ;
F_16 ( V_1 ) ;
break;
case V_40 :
case V_43 :
F_8 ( V_1 , 0x00 , 0x2000 , 0x0000 ) ;
if ( V_32 -> V_41 == V_42 ) {
F_15 ( V_1 , 0x24 ,
0x00 , 0x00 , 0x9d , 1 ) ;
F_15 ( V_1 , 0x01 ,
0x0f , 0x00 , 0xff , 1 ) ;
} else {
F_12 ( V_1 , 0x24 , 0 , 0 ) ;
F_8 ( V_1 , 0x01 , 0x000f , 0x0000 ) ;
}
break;
}
}
static void F_33 ( struct V_1 * V_1 ,
T_1 * V_19 ,
int V_4 )
{
struct V_32 * V_32 = (struct V_32 * ) V_1 ;
int V_24 , V_73 = 0 ;
static T_1 V_74 [] = { 0xff , 0xd9 } ;
switch ( V_32 -> V_38 ) {
case V_39 :
if ( V_19 [ 0 ] == 0xff ) {
if ( V_19 [ 1 ] != 0x01 ) {
return;
}
V_73 = 1 ;
V_19 += V_75 ;
V_4 -= V_75 ;
} else {
V_19 += 1 ;
V_4 -= 1 ;
}
break;
case V_46 :
if ( V_19 [ 0 ] == 0xff ) {
V_73 = 1 ;
V_19 += V_76 ;
V_4 -= V_76 ;
} else {
V_19 += 2 ;
V_4 -= 2 ;
}
break;
default:
switch ( V_19 [ 0 ] ) {
case 0xfe :
V_73 = 1 ;
V_19 += V_77 ;
V_4 -= V_77 ;
break;
case 0xff :
return;
default:
V_19 += 1 ;
V_4 -= 1 ;
break;
}
break;
case V_43 :
switch ( V_19 [ 0 ] ) {
case 0xfe :
V_73 = 1 ;
V_19 += V_78 ;
V_4 -= V_78 ;
break;
case 0xff :
return;
default:
V_19 += 1 ;
V_4 -= 1 ;
break;
}
break;
}
if ( V_73 ) {
F_34 ( V_1 , V_79 ,
V_74 , 2 ) ;
F_34 ( V_1 , V_80 ,
V_32 -> V_64 , V_81 ) ;
}
V_24 = 0 ;
do {
if ( V_19 [ V_24 ] == 0xff ) {
F_34 ( V_1 , V_82 ,
V_19 , V_24 + 1 ) ;
V_4 -= V_24 ;
V_19 += V_24 ;
* V_19 = 0x00 ;
V_24 = 0 ;
}
V_24 ++ ;
} while ( V_24 < V_4 );
F_34 ( V_1 , V_82 , V_19 , V_4 ) ;
}
static int F_35 ( struct V_83 * V_84 )
{
struct V_1 * V_1 =
F_36 ( V_84 -> V_85 , struct V_1 , V_86 ) ;
struct V_32 * V_32 = (struct V_32 * ) V_1 ;
V_1 -> V_7 = 0 ;
if ( ! V_1 -> V_87 )
return 0 ;
switch ( V_84 -> V_49 ) {
case V_88 :
F_22 ( V_1 , V_84 -> V_22 ) ;
break;
case V_89 :
F_23 ( V_1 , V_84 -> V_22 ) ;
break;
case V_90 :
F_24 ( V_1 , V_84 -> V_22 ) ;
break;
case V_91 :
V_32 -> V_72 = V_84 -> V_22 ;
break;
}
return V_1 -> V_7 ;
}
static int F_37 ( struct V_1 * V_1 )
{
struct V_92 * V_93 = & V_1 -> V_86 ;
V_1 -> V_94 . V_86 = V_93 ;
F_38 ( V_93 , 4 ) ;
F_39 ( V_93 , & V_95 ,
V_88 , - 128 , 127 , 1 , 0 ) ;
F_39 ( V_93 , & V_95 ,
V_89 , 0 , 255 , 1 , 0x20 ) ;
F_39 ( V_93 , & V_95 ,
V_90 , 0 , 255 , 1 , 0x1a ) ;
F_39 ( V_93 , & V_95 ,
V_91 , 0 , 1 , 1 , 1 ) ;
if ( V_93 -> error ) {
F_5 ( L_15 ) ;
return V_93 -> error ;
}
return 0 ;
}
static int F_40 ( struct V_96 * V_97 ,
const struct V_48 * V_49 )
{
return F_41 ( V_97 , V_49 , & V_98 , sizeof( struct V_32 ) ,
V_99 ) ;
}
