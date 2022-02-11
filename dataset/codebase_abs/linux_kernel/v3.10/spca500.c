static void F_1 ( struct V_1 * V_1 ,
T_1 V_2 ,
T_1 V_3 )
{
F_2 ( V_1 -> V_4 ,
F_3 ( V_1 -> V_4 , 0 ) ,
0 ,
V_5 | V_6 | V_7 ,
0 ,
V_2 , V_1 -> V_8 , V_3 , 500 ) ;
}
static int F_4 ( struct V_1 * V_1 ,
T_1 V_9 , T_1 V_2 , T_1 V_10 )
{
int V_11 ;
F_5 ( V_12 , L_1 , V_2 , V_10 ) ;
V_11 = F_2 ( V_1 -> V_4 ,
F_6 ( V_1 -> V_4 , 0 ) ,
V_9 ,
V_13 | V_6 | V_7 ,
V_10 , V_2 , NULL , 0 , 500 ) ;
if ( V_11 < 0 )
F_7 ( L_2 , V_11 ) ;
return V_11 ;
}
static int F_8 ( struct V_1 * V_1 ,
T_1 V_9 ,
T_1 V_2 ,
T_1 V_3 )
{
int V_11 ;
V_1 -> V_8 [ 1 ] = 0 ;
V_11 = F_2 ( V_1 -> V_4 ,
F_3 ( V_1 -> V_4 , 0 ) ,
V_9 ,
V_5 | V_6 | V_7 ,
0 ,
V_2 ,
V_1 -> V_8 , V_3 ,
500 ) ;
if ( V_11 < 0 ) {
F_7 ( L_3 , V_11 ) ;
return V_11 ;
}
return ( V_1 -> V_8 [ 1 ] << 8 ) + V_1 -> V_8 [ 0 ] ;
}
static int F_9 ( struct V_1 * V_1 ,
T_1 V_14 , T_1 V_2 , T_1 V_10 )
{
int V_11 , V_15 = 20 ;
while ( -- V_15 > 0 ) {
V_11 = F_8 ( V_1 , V_14 , V_2 , 1 ) ;
if ( V_11 == V_10 )
return 0 ;
F_10 ( 50 ) ;
}
return - V_16 ;
}
static int F_11 ( struct V_1 * V_1 ,
const T_1 V_17 [] [ 3 ] )
{
int V_11 , V_18 = 0 ;
while ( V_17 [ V_18 ] [ 0 ] != 0 || V_17 [ V_18 ] [ 1 ] != 0 || V_17 [ V_18 ] [ 2 ] != 0 ) {
V_11 = F_4 ( V_1 , V_17 [ V_18 ] [ 0 ] , V_17 [ V_18 ] [ 2 ] , V_17 [ V_18 ] [ 1 ] ) ;
if ( V_11 < 0 )
return V_11 ;
V_18 ++ ;
}
return 0 ;
}
static int F_12 ( struct V_1 * V_1 ,
unsigned int V_19 ,
unsigned int V_20 ,
unsigned int V_21 ,
const T_2 V_22 [ 2 ] [ 64 ] )
{
int V_18 , V_23 ;
for ( V_18 = 0 ; V_18 < 64 ; V_18 ++ ) {
V_23 = F_4 ( V_1 , V_19 , V_20 + V_18 , V_22 [ 0 ] [ V_18 ] ) ;
if ( V_23 < 0 )
return V_23 ;
}
for ( V_18 = 0 ; V_18 < 64 ; V_18 ++ ) {
V_23 = F_4 ( V_1 , V_19 , V_21 + V_18 , V_22 [ 1 ] [ V_18 ] ) ;
if ( V_23 < 0 )
return V_23 ;
}
return 0 ;
}
static void F_13 ( struct V_1 * V_1 )
{
F_1 ( V_1 , 0x0d04 , 2 ) ;
F_5 ( V_24 , L_4 ,
V_1 -> V_8 [ 0 ] , V_1 -> V_8 [ 1 ] ) ;
}
static void F_14 ( struct V_1 * V_1 )
{
F_1 ( V_1 , 0x0d05 , 2 ) ;
F_5 ( V_24 , L_5 ,
V_1 -> V_8 [ 0 ] , V_1 -> V_8 [ 1 ] ) ;
F_4 ( V_1 , 0x00 , 0x8167 , 0x5a ) ;
F_13 ( V_1 ) ;
F_4 ( V_1 , 0x00 , 0x8168 , 0x22 ) ;
F_4 ( V_1 , 0x00 , 0x816a , 0xc0 ) ;
F_4 ( V_1 , 0x00 , 0x816b , 0x0b ) ;
F_4 ( V_1 , 0x00 , 0x8169 , 0x25 ) ;
F_4 ( V_1 , 0x00 , 0x8157 , 0x5b ) ;
F_4 ( V_1 , 0x00 , 0x8158 , 0x5b ) ;
F_4 ( V_1 , 0x00 , 0x813f , 0x03 ) ;
F_4 ( V_1 , 0x00 , 0x8151 , 0x4a ) ;
F_4 ( V_1 , 0x00 , 0x8153 , 0x78 ) ;
F_4 ( V_1 , 0x00 , 0x0d01 , 0x04 ) ;
F_4 ( V_1 , 0x00 , 0x0d02 , 0x01 ) ;
F_4 ( V_1 , 0x00 , 0x8169 , 0x25 ) ;
F_4 ( V_1 , 0x00 , 0x0d01 , 0x02 ) ;
}
static void F_15 ( struct V_1 * V_1 ,
T_2 V_25 , T_2 V_26 )
{
int V_27 ;
F_4 ( V_1 , 0 , 0x8001 , V_25 ) ;
F_4 ( V_1 , 0 , 0x8002 , V_26 ) ;
V_27 = V_1 -> V_28 . V_29 [ ( int ) V_1 -> V_30 ] . V_31 ;
F_4 ( V_1 , 0 , 0x8003 , V_27 << 4 ) ;
}
static int F_16 ( struct V_1 * V_1 )
{
int V_23 ;
V_23 = F_4 ( V_1 , 0xe0 , 0x0001 , 0x0000 ) ;
if ( V_23 < 0 )
return V_23 ;
V_23 = F_9 ( V_1 , 0x06 , 0x0000 , 0x0000 ) ;
if ( V_23 < 0 )
return V_23 ;
V_23 = F_4 ( V_1 , 0xe0 , 0x0000 , 0x0000 ) ;
if ( V_23 < 0 )
return V_23 ;
V_23 = F_9 ( V_1 , 0x06 , 0 , 0 ) ;
if ( V_23 < 0 ) {
F_17 ( L_6 ) ;
return V_23 ;
}
return 0 ;
}
static int F_18 ( struct V_1 * V_1 )
{
if ( F_19 ( V_1 -> V_4 , V_1 -> V_32 , 0 ) < 0 ) {
F_17 ( L_7 ) ;
goto error;
}
F_13 ( V_1 ) ;
F_1 ( V_1 , 0x0d00 , 1 ) ;
F_5 ( V_33 , L_8 , V_1 -> V_34 ) ;
if ( F_19 ( V_1 -> V_4 ,
V_1 -> V_32 ,
V_1 -> V_34 ) < 0 ) {
F_17 ( L_7 ) ;
goto error;
}
return 0 ;
error:
return - V_35 ;
}
static void F_20 ( struct V_1 * V_1 )
{
int V_23 ;
T_2 V_36 ;
F_4 ( V_1 , 0x00 , 0x0d01 , 0x01 ) ;
F_4 ( V_1 , 0x00 , 0x0d03 , 0x00 ) ;
F_4 ( V_1 , 0x00 , 0x0d02 , 0x01 ) ;
F_4 ( V_1 , 0x00 , 0x850a , 0x0001 ) ;
V_23 = F_12 ( V_1 , 0x00 , 0x8800 , 0x8840 ,
V_37 ) ;
if ( V_23 < 0 )
F_17 ( L_9 ) ;
F_4 ( V_1 , 0x00 , 0x8880 , 2 ) ;
F_4 ( V_1 , 0x00 , 0x800a , 0x00 ) ;
F_4 ( V_1 , 0x00 , 0x820f , 0x01 ) ;
F_4 ( V_1 , 0x00 , 0x870a , 0x04 ) ;
F_4 ( V_1 , 0 , 0x8003 , 0x00 ) ;
F_4 ( V_1 , 0x00 , 0x8000 , 0x0004 ) ;
F_10 ( 2000 ) ;
if ( F_9 ( V_1 , 0 , 0x8000 , 0x44 ) != 0 ) {
F_1 ( V_1 , 0x816b , 1 ) ;
V_36 = V_1 -> V_8 [ 0 ] ;
F_4 ( V_1 , 0x00 , 0x816b , V_36 ) ;
}
}
static int F_21 ( struct V_1 * V_1 ,
const struct V_38 * V_39 )
{
struct V_40 * V_40 = (struct V_40 * ) V_1 ;
struct V_28 * V_28 ;
V_28 = & V_1 -> V_28 ;
V_40 -> V_41 = V_39 -> V_42 ;
if ( V_40 -> V_41 != V_43 ) {
V_28 -> V_29 = V_44 ;
V_28 -> V_45 = F_22 ( V_44 ) ;
} else {
V_28 -> V_29 = V_46 ;
V_28 -> V_45 = F_22 ( V_46 ) ;
}
return 0 ;
}
static int F_23 ( struct V_1 * V_1 )
{
struct V_40 * V_40 = (struct V_40 * ) V_1 ;
F_5 ( V_24 , L_10 ) ;
if ( V_40 -> V_41 == V_43 )
F_14 ( V_1 ) ;
F_5 ( V_24 , L_11 ) ;
return 0 ;
}
static int F_24 ( struct V_1 * V_1 )
{
struct V_40 * V_40 = (struct V_40 * ) V_1 ;
int V_23 ;
T_2 V_36 ;
T_2 V_25 , V_26 ;
F_25 ( V_40 -> V_47 , V_1 -> V_48 , V_1 -> V_49 ,
0x22 ) ;
F_26 ( V_40 -> V_47 , V_50 ) ;
if ( V_40 -> V_41 == V_43 ) {
V_25 = 0x16 ;
V_26 = 0x12 ;
} else {
V_25 = 0x28 ;
V_26 = 0x1e ;
}
F_1 ( V_1 , 0x8a04 , 1 ) ;
F_5 ( V_24 , L_12 ,
V_1 -> V_8 [ 0 ] ) ;
F_5 ( V_24 , L_13 ,
V_1 -> V_30 , V_25 , V_26 ) ;
switch ( V_40 -> V_41 ) {
case V_43 :
F_15 ( V_1 , V_25 , V_26 ) ;
F_4 ( V_1 , 0x00 , 0x850a , 0x0001 ) ;
F_4 ( V_1 , 0x00 , 0x8880 , 3 ) ;
V_23 = F_12 ( V_1 ,
0x00 , 0x8800 , 0x8840 ,
V_51 ) ;
if ( V_23 < 0 )
F_17 ( L_14 ) ;
F_4 ( V_1 , 0x00 , 0x870a , 0x04 ) ;
F_4 ( V_1 , 0x00 , 0x8000 , 0x0004 ) ;
F_10 ( 500 ) ;
if ( F_9 ( V_1 , 0 , 0x8000 , 0x44 ) != 0 )
F_17 ( L_6 ) ;
F_1 ( V_1 , 0x816b , 1 ) ;
V_36 = V_1 -> V_8 [ 0 ] ;
F_4 ( V_1 , 0x00 , 0x816b , V_36 ) ;
F_18 ( V_1 ) ;
F_11 ( V_1 , V_52 ) ;
F_15 ( V_1 , V_25 , V_26 ) ;
V_23 = F_4 ( V_1 , 0x00 , 0x850a , 0x0001 ) ;
if ( V_23 < 0 )
F_17 ( L_15 ) ;
F_4 ( V_1 , 0x00 , 0x8880 , 3 ) ;
V_23 = F_12 ( V_1 ,
0x00 , 0x8800 , 0x8840 ,
V_51 ) ;
if ( V_23 < 0 )
F_17 ( L_14 ) ;
F_4 ( V_1 , 0x00 , 0x870a , 0x04 ) ;
F_4 ( V_1 , 0x00 , 0x8000 , 0x0004 ) ;
if ( F_9 ( V_1 , 0 , 0x8000 , 0x44 ) != 0 )
F_17 ( L_6 ) ;
F_1 ( V_1 , 0x816b , 1 ) ;
V_36 = V_1 -> V_8 [ 0 ] ;
F_4 ( V_1 , 0x00 , 0x816b , V_36 ) ;
break;
case V_53 :
case V_54 :
V_23 = F_16 ( V_1 ) ;
if ( V_23 < 0 )
F_17 ( L_16 ) ;
V_23 = F_4 ( V_1 , 0x00 , 0x850a , 0x0001 ) ;
if ( V_23 < 0 )
F_17 ( L_15 ) ;
F_4 ( V_1 , 0x00 , 0x8880 , 3 ) ;
V_23 = F_12 ( V_1 ,
0x00 , 0x8800 , 0x8840 ,
V_51 ) ;
if ( V_23 < 0 )
F_17 ( L_14 ) ;
F_15 ( V_1 , V_25 , V_26 ) ;
F_4 ( V_1 , 0x20 , 0x0001 , 0x0004 ) ;
F_4 ( V_1 , 0x00 , 0x8000 , 0x0004 ) ;
if ( F_9 ( V_1 , 0 , 0x8000 , 0x44 ) != 0 )
F_17 ( L_6 ) ;
F_1 ( V_1 , 0x816b , 1 ) ;
V_36 = V_1 -> V_8 [ 0 ] ;
F_4 ( V_1 , 0x00 , 0x816b , V_36 ) ;
break;
case V_55 :
V_23 = F_16 ( V_1 ) ;
if ( V_23 < 0 )
F_17 ( L_16 ) ;
F_4 ( V_1 , 0x00 , 0x850a , 0x0001 ) ;
F_4 ( V_1 , 0x00 , 0x8880 , 0 ) ;
V_23 = F_12 ( V_1 ,
0x00 , 0x8800 , 0x8840 ,
V_56 ) ;
if ( V_23 < 0 )
F_17 ( L_14 ) ;
F_15 ( V_1 , V_25 , V_26 ) ;
F_4 ( V_1 , 0x20 , 0x0001 , 0x0004 ) ;
F_4 ( V_1 , 0x00 , 0x8000 , 0x0004 ) ;
if ( F_9 ( V_1 , 0 , 0x8000 , 0x44 ) != 0 )
F_17 ( L_6 ) ;
F_1 ( V_1 , 0x816b , 1 ) ;
V_36 = V_1 -> V_8 [ 0 ] ;
F_4 ( V_1 , 0x00 , 0x816b , V_36 ) ;
break;
case V_57 :
case V_58 :
case V_59 :
case V_60 :
case V_61 :
case V_62 :
case V_63 :
case V_64 :
case V_65 :
F_20 ( V_1 ) ;
F_4 ( V_1 , 0x00 , 0x0d01 , 0x01 ) ;
F_4 ( V_1 , 0x00 , 0x850a , 0x0001 ) ;
V_23 = F_12 ( V_1 ,
0x00 , 0x8800 , 0x8840 , V_37 ) ;
if ( V_23 < 0 )
F_17 ( L_14 ) ;
F_4 ( V_1 , 0x00 , 0x8880 , 2 ) ;
F_4 ( V_1 , 0x00 , 0x800a , 0x00 ) ;
F_4 ( V_1 , 0x00 , 0x820f , 0x01 ) ;
F_4 ( V_1 , 0x00 , 0x870a , 0x04 ) ;
F_15 ( V_1 , V_25 , V_26 ) ;
F_4 ( V_1 , 0x00 , 0x8000 , 0x0004 ) ;
F_9 ( V_1 , 0 , 0x8000 , 0x44 ) ;
F_1 ( V_1 , 0x816b , 1 ) ;
V_36 = V_1 -> V_8 [ 0 ] ;
F_4 ( V_1 , 0x00 , 0x816b , V_36 ) ;
break;
case V_66 :
case V_67 :
F_4 ( V_1 , 0x02 , 0x00 , 0x00 ) ;
F_4 ( V_1 , 0x00 , 0x850a , 0x0001 ) ;
V_23 = F_12 ( V_1 ,
0x00 , 0x8800 ,
0x8840 , V_51 ) ;
if ( V_23 < 0 )
F_17 ( L_14 ) ;
F_4 ( V_1 , 0x00 , 0x8880 , 3 ) ;
F_4 ( V_1 , 0x00 , 0x800a , 0x00 ) ;
F_4 ( V_1 , 0x00 , 0x870a , 0x04 ) ;
F_15 ( V_1 , V_25 , V_26 ) ;
F_4 ( V_1 , 0x00 , 0x8000 , 0x0004 ) ;
F_9 ( V_1 , 0 , 0x8000 , 0x44 ) ;
F_1 ( V_1 , 0x816b , 1 ) ;
V_36 = V_1 -> V_8 [ 0 ] ;
F_4 ( V_1 , 0x00 , 0x816b , V_36 ) ;
F_11 ( V_1 , V_68 ) ;
break;
}
return 0 ;
}
static void F_27 ( struct V_1 * V_1 )
{
F_4 ( V_1 , 0 , 0x8003 , 0x00 ) ;
F_4 ( V_1 , 0x00 , 0x8000 , 0x0004 ) ;
F_1 ( V_1 , 0x8000 , 1 ) ;
F_5 ( V_24 , L_17 ,
V_1 -> V_8 [ 0 ] ) ;
}
static void F_28 ( struct V_1 * V_1 ,
T_3 * V_17 ,
int V_69 )
{
struct V_40 * V_40 = (struct V_40 * ) V_1 ;
int V_18 ;
static T_2 V_70 [] = { 0xff , 0xd9 } ;
if ( V_17 [ 0 ] == 0xff ) {
if ( V_17 [ 1 ] != 0x01 ) {
return;
}
F_29 ( V_1 , V_71 ,
V_70 , 2 ) ;
F_29 ( V_1 , V_72 ,
V_40 -> V_47 , V_73 ) ;
V_17 += V_74 ;
V_69 -= V_74 ;
} else {
V_17 += 1 ;
V_69 -= 1 ;
}
V_18 = 0 ;
do {
if ( V_17 [ V_18 ] == 0xff ) {
F_29 ( V_1 , V_75 ,
V_17 , V_18 + 1 ) ;
V_69 -= V_18 ;
V_17 += V_18 ;
* V_17 = 0x00 ;
V_18 = 0 ;
}
V_18 ++ ;
} while ( V_18 < V_69 );
F_29 ( V_1 , V_75 , V_17 , V_69 ) ;
}
static void F_30 ( struct V_1 * V_1 , T_4 V_76 )
{
F_4 ( V_1 , 0x00 , 0x8167 ,
( T_2 ) ( V_76 - 128 ) ) ;
}
static void F_31 ( struct V_1 * V_1 , T_4 V_76 )
{
F_4 ( V_1 , 0x00 , 0x8168 , V_76 ) ;
}
static void F_32 ( struct V_1 * V_1 , T_4 V_76 )
{
F_4 ( V_1 , 0x00 , 0x8169 , V_76 ) ;
}
static int F_33 ( struct V_77 * V_78 )
{
struct V_1 * V_1 =
F_34 ( V_78 -> V_79 , struct V_1 , V_80 ) ;
V_1 -> V_81 = 0 ;
if ( ! V_1 -> V_82 )
return 0 ;
switch ( V_78 -> V_39 ) {
case V_83 :
F_30 ( V_1 , V_78 -> V_76 ) ;
break;
case V_84 :
F_31 ( V_1 , V_78 -> V_76 ) ;
break;
case V_85 :
F_32 ( V_1 , V_78 -> V_76 ) ;
break;
}
return V_1 -> V_81 ;
}
static int F_35 ( struct V_1 * V_1 )
{
struct V_86 * V_87 = & V_1 -> V_80 ;
V_1 -> V_88 . V_80 = V_87 ;
F_36 ( V_87 , 3 ) ;
F_37 ( V_87 , & V_89 ,
V_83 , 0 , 255 , 1 , 127 ) ;
F_37 ( V_87 , & V_89 ,
V_84 , 0 , 63 , 1 , 31 ) ;
F_37 ( V_87 , & V_89 ,
V_85 , 0 , 63 , 1 , 31 ) ;
if ( V_87 -> error ) {
F_7 ( L_18 ) ;
return V_87 -> error ;
}
return 0 ;
}
static int F_38 ( struct V_90 * V_91 ,
const struct V_38 * V_39 )
{
return F_39 ( V_91 , V_39 , & V_92 , sizeof( struct V_40 ) ,
V_93 ) ;
}
