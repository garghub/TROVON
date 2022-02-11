static void F_1 ( struct V_1 * V_1 ,
T_1 V_2 ,
T_2 V_3 ,
T_2 V_4 )
{
int V_5 ;
#ifdef F_2
if ( V_4 > V_6 ) {
F_3 ( L_1 ) ;
return;
}
#endif
if ( V_1 -> V_7 < 0 )
return;
V_5 = F_4 ( V_1 -> V_8 ,
F_5 ( V_1 -> V_8 , 0 ) ,
V_2 ,
V_9 | V_10 | V_11 ,
0 ,
V_3 ,
V_4 ? V_1 -> V_12 : NULL , V_4 ,
500 ) ;
if ( V_5 < 0 ) {
F_3 ( L_2 , V_5 ) ;
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
V_5 = F_4 ( V_1 -> V_8 ,
F_7 ( V_1 -> V_8 , 0 ) ,
V_2 ,
V_15 | V_10 | V_11 ,
V_13 , V_3 ,
V_1 -> V_12 , 1 ,
500 ) ;
if ( V_5 < 0 ) {
F_3 ( L_3 , V_5 ) ;
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
V_5 = F_4 ( V_8 ,
F_7 ( V_8 , 0 ) ,
V_2 ,
V_15 | V_10 | V_11 ,
V_13 , V_3 , NULL , 0 , 500 ) ;
if ( V_5 < 0 ) {
F_3 ( L_4 , V_5 ) ;
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
for ( V_24 = 0 ; V_24 < 6 ; V_24 ++ ) {
F_1 ( V_1 , 0 , V_24 , 1 ) ;
V_26 [ V_24 ] = V_1 -> V_12 [ 0 ] ;
}
F_9 ( V_27 ,
L_8
L_9 ,
V_26 [ 0 ] , V_26 [ 1 ] , V_26 [ 2 ] ,
V_26 [ 3 ] , V_26 [ 4 ] , V_26 [ 5 ] ) ;
}
static void F_15 ( struct V_1 * V_1 ,
T_1 V_2 ,
T_2 V_21 , T_2 V_22 , T_1 V_28 , T_1 V_29 )
{
T_2 V_30 ;
F_8 ( V_1 , V_2 , V_21 , V_22 ) ;
F_1 ( V_1 , 0x01 , 0x0001 , 1 ) ;
if ( V_1 -> V_7 < 0 )
return;
F_9 ( V_25 , L_10 ,
V_1 -> V_12 [ 0 ] , V_28 ) ;
if ( ! V_29 )
return;
V_29 = 200 ;
while ( -- V_29 > 0 ) {
F_13 ( 10 ) ;
F_1 ( V_1 , 0x01 , 0x0001 , 1 ) ;
V_30 = V_1 -> V_12 [ 0 ] ;
if ( V_30 == V_28 ) {
F_9 ( V_25 , L_11 ,
V_30 , 200 - V_29 ) ;
break;
}
}
}
static void F_16 ( struct V_1 * V_1 )
{
int V_29 = 10 ;
while ( -- V_29 > 0 ) {
F_1 ( V_1 , 0x21 , 0 , 1 ) ;
if ( ( V_1 -> V_12 [ 0 ] & 0x01 ) == 0 )
break;
F_13 ( 10 ) ;
}
}
static void F_17 ( struct V_1 * V_1 )
{
int V_29 = 50 ;
while ( -- V_29 > 0 ) {
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
V_19 = V_1 -> V_12 ;
F_1 ( V_1 , 0x20 , 0 , 5 ) ;
F_9 ( V_27 , L_12 ,
V_19 [ 0 ] , V_19 [ 1 ] , V_19 [ 2 ] , V_19 [ 3 ] , V_19 [ 4 ] ) ;
F_1 ( V_1 , 0x23 , 0 , 64 ) ;
F_1 ( V_1 , 0x23 , 1 , 64 ) ;
}
static void F_19 ( struct V_1 * V_1 )
{
struct V_31 * V_31 = (struct V_31 * ) V_1 ;
T_1 V_32 ;
V_32 = V_1 -> V_33 . V_34 [ V_1 -> V_35 ] . V_36 ;
switch ( V_31 -> V_37 ) {
case V_38 :
F_8 ( V_1 , 0x31 , 0 , 0 ) ;
F_17 ( V_1 ) ;
F_16 ( V_1 ) ;
#ifdef F_2
F_18 ( V_1 ) ;
#endif
F_6 ( V_1 , 0x24 , 0 , 8 , 2 ) ;
F_1 ( V_1 , 0x24 , 8 , 1 ) ;
F_6 ( V_1 , 0x25 , 0 , 4 , V_32 ) ;
F_1 ( V_1 , 0x25 , 4 , 1 ) ;
F_16 ( V_1 ) ;
F_8 ( V_1 , 0x31 , 0x0004 , 0x00 ) ;
F_17 ( V_1 ) ;
F_16 ( V_1 ) ;
break;
default:
F_6 ( V_1 , 0x25 , 0 , 4 , V_32 ) ;
F_1 ( V_1 , 0x25 , 4 , 1 ) ;
F_6 ( V_1 , 0x27 , 0 , 0 , 6 ) ;
F_1 ( V_1 , 0x27 , 0 , 1 ) ;
F_16 ( V_1 ) ;
break;
case V_39 :
V_32 += 3 ;
if ( V_31 -> V_40 == V_41 ) {
F_15 ( V_1 ,
0x08 , V_32 , 0 ,
0x80 | ( V_32 & 0x0f ) , 1 ) ;
F_15 ( V_1 ,
1 , 3 , 0 , 0x9f , 0 ) ;
} else {
F_12 ( V_1 , 0x08 , V_32 , 0 ) ;
}
break;
case V_42 :
F_8 ( V_1 , 0xa0 , ( 0x0500 | ( V_32 & 0x0f ) ) , 0x00 ) ;
F_8 ( V_1 , 0x20 , 0x01 , 0x0500 | ( V_32 & 0x0f ) ) ;
break;
}
}
static void F_20 ( struct V_1 * V_1 )
{
int V_43 ;
V_43 = 256 ;
while ( -- V_43 > 0 ) {
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
static void F_22 ( struct V_1 * V_1 )
{
struct V_31 * V_31 = (struct V_31 * ) V_1 ;
T_2 V_44 ;
V_44 = V_31 -> V_37 == V_45 ? 0x20f0 : 0x21a7 ;
F_8 ( V_1 , 0x00 , V_44 , V_31 -> V_46 ) ;
}
static void F_23 ( struct V_1 * V_1 )
{
struct V_31 * V_31 = (struct V_31 * ) V_1 ;
T_2 V_44 ;
V_44 = V_31 -> V_37 == V_45 ? 0x20f1 : 0x21a8 ;
F_8 ( V_1 , 0x00 , V_44 , V_31 -> V_47 ) ;
}
static void F_24 ( struct V_1 * V_1 )
{
struct V_31 * V_31 = (struct V_31 * ) V_1 ;
T_2 V_44 ;
V_44 = V_31 -> V_37 == V_45 ? 0x20f6 : 0x21ae ;
F_8 ( V_1 , 0x00 , V_44 , V_31 -> V_48 ) ;
}
static void F_25 ( struct V_1 * V_1 )
{
struct V_31 * V_31 = (struct V_31 * ) V_1 ;
int V_49 = 1 ;
F_22 ( V_1 ) ;
F_23 ( V_1 ) ;
F_24 ( V_1 ) ;
switch ( V_31 -> V_37 ) {
case V_39 :
case V_42 :
V_49 = 0 ;
default:
F_8 ( V_1 , 0 , 0x21ad , 0x00 ) ;
F_8 ( V_1 , 0 , 0x21ac , 0x01 ) ;
F_8 ( V_1 , 0 , 0x21a3 , 0x00 ) ;
break;
case V_45 :
F_8 ( V_1 , 0 , 0x20f5 , 0x40 ) ;
F_8 ( V_1 , 0 , 0x20f4 , 0x01 ) ;
F_8 ( V_1 , 0 , 0x2089 , 0x00 ) ;
break;
}
if ( V_49 )
F_16 ( V_1 ) ;
}
static int F_26 ( struct V_1 * V_1 ,
const struct V_50 * V_51 )
{
struct V_31 * V_31 = (struct V_31 * ) V_1 ;
struct V_33 * V_33 ;
V_33 = & V_1 -> V_33 ;
V_31 -> V_37 = V_51 -> V_52 >> 8 ;
V_31 -> V_40 = V_51 -> V_52 ;
if ( V_31 -> V_40 == V_41 ) {
F_1 ( V_1 , 0x20 , 0 , 1 ) ;
switch ( V_1 -> V_12 [ 0 ] ) {
case 1 :
break;
case 2 :
V_31 -> V_37 = V_53 ;
V_31 -> V_40 = 0 ;
break;
default:
return - V_54 ;
}
}
switch ( V_31 -> V_37 ) {
default:
V_33 -> V_34 = V_55 ;
V_33 -> V_56 = F_27 ( V_55 ) ;
break;
case V_38 :
V_33 -> V_34 = V_57 ;
if ( V_31 -> V_40 == V_58 )
V_33 -> V_56 = F_27 ( V_57 ) - 1 ;
else
V_33 -> V_56 = F_27 ( V_57 ) ;
break;
case V_42 :
V_33 -> V_34 = V_59 ;
V_33 -> V_56 = F_27 ( V_59 ) ;
break;
}
V_31 -> V_46 = V_60 ;
V_31 -> V_47 = V_61 ;
V_31 -> V_48 = V_62 ;
V_31 -> V_63 = V_64 ;
V_31 -> V_65 = V_66 ;
return 0 ;
}
static int F_28 ( struct V_1 * V_1 )
{
struct V_31 * V_31 = (struct V_31 * ) V_1 ;
switch ( V_31 -> V_37 ) {
case V_53 :
F_8 ( V_1 , 0x1d , 0x00 , 0 ) ;
F_8 ( V_1 , 0x00 , 0x2306 , 0x01 ) ;
F_8 ( V_1 , 0x00 , 0x0d04 , 0x00 ) ;
F_8 ( V_1 , 0x00 , 0x2000 , 0x00 ) ;
F_8 ( V_1 , 0x00 , 0x2301 , 0x13 ) ;
F_8 ( V_1 , 0x00 , 0x2306 , 0x00 ) ;
case V_38 :
F_16 ( V_1 ) ;
#ifdef F_2
F_18 ( V_1 ) ;
#endif
break;
case V_45 :
#ifdef F_2
F_18 ( V_1 ) ;
#endif
F_1 ( V_1 , 0x00 , 0x5002 , 1 ) ;
F_6 ( V_1 , 0x24 , 0 , 0 , 0 ) ;
F_1 ( V_1 , 0x24 , 0 , 1 ) ;
F_16 ( V_1 ) ;
F_8 ( V_1 , 0x34 , 0 , 0 ) ;
F_17 ( V_1 ) ;
break;
case V_42 :
F_9 ( V_27 , L_13 ) ;
F_8 ( V_1 , 0xe0 , 0x0000 , 0x0000 ) ;
F_8 ( V_1 , 0xe0 , 0x0000 , 0x0001 ) ;
F_20 ( V_1 ) ;
if ( V_31 -> V_40 == V_67 )
F_10 ( V_1 ,
V_68 ,
F_27 ( V_68 ) ) ;
else
F_10 ( V_1 , V_69 ,
F_27 ( V_69 ) ) ;
F_11 ( V_1 , V_70 ) ;
break;
default:
F_9 ( V_27 , L_14 ) ;
if ( V_31 -> V_40 == V_41 ) {
#ifdef F_2
F_14 ( V_1 ) ;
#endif
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
F_11 ( V_1 , V_71 ) ;
break;
}
return V_1 -> V_7 ;
}
static int F_29 ( struct V_1 * V_1 )
{
struct V_31 * V_31 = (struct V_31 * ) V_1 ;
int V_72 ;
F_30 ( V_31 -> V_73 , V_1 -> V_74 , V_1 -> V_75 ,
0x22 ) ;
F_31 ( V_31 -> V_73 , V_31 -> V_65 ) ;
if ( V_31 -> V_37 == V_53 )
F_21 ( V_1 ) ;
F_19 ( V_1 ) ;
switch ( V_31 -> V_37 ) {
default:
switch ( V_31 -> V_40 ) {
case V_76 :
case V_77 :
case V_58 :
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
case V_39 :
if ( V_31 -> V_40 == V_41 ) {
#ifdef F_2
F_14 ( V_1 ) ;
#endif
F_15 ( V_1 , 0x24 ,
8 , 3 , 0x9e , 1 ) ;
F_15 ( V_1 , 0x24 ,
8 , 3 , 0x9e , 0 ) ;
F_15 ( V_1 , 0x24 ,
0 , 0 , 0x9d , 1 ) ;
} else {
F_12 ( V_1 , 0x24 , 8 , 3 ) ;
#ifdef F_2
F_14 ( V_1 ) ;
#endif
F_12 ( V_1 , 0x24 , 8 , 3 ) ;
F_12 ( V_1 , 0x24 , 0 , 0 ) ;
}
F_19 ( V_1 ) ;
F_8 ( V_1 , 0x00 , 0x270c , 0x05 ) ;
F_8 ( V_1 , 0x00 , 0x2310 , 0x05 ) ;
break;
case V_42 :
if ( V_31 -> V_40 == V_67 ) {
F_10 ( V_1 ,
V_78 ,
F_27 ( V_78 ) ) ;
} else {
F_10 ( V_1 , V_79 ,
F_27 ( V_79 ) ) ;
}
V_72 = ( V_31 -> V_63 ? 0x04 : 0x01 ) ;
F_8 ( V_1 , 0x0c , 0x0000 , V_72 ) ;
F_8 ( V_1 , 0xb0 , 0x0000 , V_72 ) ;
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
struct V_31 * V_31 = (struct V_31 * ) V_1 ;
switch ( V_31 -> V_37 ) {
default:
F_8 ( V_1 , 0x31 , 0 , 0 ) ;
F_17 ( V_1 ) ;
F_16 ( V_1 ) ;
break;
case V_39 :
case V_42 :
F_8 ( V_1 , 0x00 , 0x2000 , 0x0000 ) ;
if ( V_31 -> V_40 == V_41 ) {
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
struct V_31 * V_31 = (struct V_31 * ) V_1 ;
int V_24 , V_80 = 0 ;
static T_1 V_81 [] = { 0xff , 0xd9 } ;
switch ( V_31 -> V_37 ) {
case V_38 :
if ( V_19 [ 0 ] == 0xff ) {
if ( V_19 [ 1 ] != 0x01 ) {
return;
}
V_80 = 1 ;
V_19 += V_82 ;
V_4 -= V_82 ;
} else {
V_19 += 1 ;
V_4 -= 1 ;
}
break;
case V_45 :
if ( V_19 [ 0 ] == 0xff ) {
V_80 = 1 ;
V_19 += V_83 ;
V_4 -= V_83 ;
} else {
V_19 += 2 ;
V_4 -= 2 ;
}
break;
default:
switch ( V_19 [ 0 ] ) {
case 0xfe :
V_80 = 1 ;
V_19 += V_84 ;
V_4 -= V_84 ;
break;
case 0xff :
return;
default:
V_19 += 1 ;
V_4 -= 1 ;
break;
}
break;
case V_42 :
switch ( V_19 [ 0 ] ) {
case 0xfe :
V_80 = 1 ;
V_19 += V_85 ;
V_4 -= V_85 ;
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
if ( V_80 ) {
F_34 ( V_1 , V_86 ,
V_81 , 2 ) ;
F_34 ( V_1 , V_87 ,
V_31 -> V_73 , V_88 ) ;
}
V_24 = 0 ;
do {
if ( V_19 [ V_24 ] == 0xff ) {
F_34 ( V_1 , V_89 ,
V_19 , V_24 + 1 ) ;
V_4 -= V_24 ;
V_19 += V_24 ;
* V_19 = 0x00 ;
V_24 = 0 ;
}
V_24 ++ ;
} while ( V_24 < V_4 );
F_34 ( V_1 , V_89 , V_19 , V_4 ) ;
}
static int F_35 ( struct V_1 * V_1 , T_3 V_22 )
{
struct V_31 * V_31 = (struct V_31 * ) V_1 ;
V_31 -> V_46 = V_22 ;
if ( V_1 -> V_90 )
F_22 ( V_1 ) ;
return V_1 -> V_7 ;
}
static int F_36 ( struct V_1 * V_1 , T_3 * V_22 )
{
struct V_31 * V_31 = (struct V_31 * ) V_1 ;
* V_22 = V_31 -> V_46 ;
return 0 ;
}
static int F_37 ( struct V_1 * V_1 , T_3 V_22 )
{
struct V_31 * V_31 = (struct V_31 * ) V_1 ;
V_31 -> V_47 = V_22 ;
if ( V_1 -> V_90 )
F_23 ( V_1 ) ;
return V_1 -> V_7 ;
}
static int F_38 ( struct V_1 * V_1 , T_3 * V_22 )
{
struct V_31 * V_31 = (struct V_31 * ) V_1 ;
* V_22 = V_31 -> V_47 ;
return 0 ;
}
static int F_39 ( struct V_1 * V_1 , T_3 V_22 )
{
struct V_31 * V_31 = (struct V_31 * ) V_1 ;
V_31 -> V_48 = V_22 ;
if ( V_1 -> V_90 )
F_24 ( V_1 ) ;
return V_1 -> V_7 ;
}
static int F_40 ( struct V_1 * V_1 , T_3 * V_22 )
{
struct V_31 * V_31 = (struct V_31 * ) V_1 ;
* V_22 = V_31 -> V_48 ;
return 0 ;
}
static int F_41 ( struct V_1 * V_1 , T_3 V_22 )
{
struct V_31 * V_31 = (struct V_31 * ) V_1 ;
V_31 -> V_63 = V_22 ;
return 0 ;
}
static int F_42 ( struct V_1 * V_1 , T_3 * V_22 )
{
struct V_31 * V_31 = (struct V_31 * ) V_1 ;
* V_22 = V_31 -> V_63 ;
return 0 ;
}
static int F_43 ( struct V_1 * V_1 ,
struct V_91 * V_92 )
{
struct V_31 * V_31 = (struct V_31 * ) V_1 ;
if ( V_92 -> V_65 < V_93 )
V_31 -> V_65 = V_93 ;
else if ( V_92 -> V_65 > V_94 )
V_31 -> V_65 = V_94 ;
else
V_31 -> V_65 = V_92 -> V_65 ;
if ( V_1 -> V_90 )
F_31 ( V_31 -> V_73 , V_31 -> V_65 ) ;
return V_1 -> V_7 ;
}
static int F_44 ( struct V_1 * V_1 ,
struct V_91 * V_92 )
{
struct V_31 * V_31 = (struct V_31 * ) V_1 ;
memset ( V_92 , 0 , sizeof *V_92 ) ;
V_92 -> V_65 = V_31 -> V_65 ;
V_92 -> V_95 = V_96
| V_97 ;
return 0 ;
}
static int F_45 ( struct V_98 * V_99 ,
const struct V_50 * V_51 )
{
return F_46 ( V_99 , V_51 , & V_100 , sizeof( struct V_31 ) ,
V_101 ) ;
}
static int T_4 F_47 ( void )
{
return F_48 ( & V_102 ) ;
}
static void T_5 F_49 ( void )
{
F_50 ( & V_102 ) ;
}
