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
F_5 ( V_32 , L_6 ) ;
return V_23 ;
}
return 0 ;
}
static int F_17 ( struct V_1 * V_1 )
{
if ( F_18 ( V_1 -> V_4 , V_1 -> V_33 , 0 ) < 0 ) {
F_5 ( V_32 , L_7 ) ;
goto error;
}
F_13 ( V_1 ) ;
F_1 ( V_1 , 0x0d00 , 1 ) ;
F_5 ( V_34 , L_8 , V_1 -> V_35 ) ;
if ( F_18 ( V_1 -> V_4 ,
V_1 -> V_33 ,
V_1 -> V_35 ) < 0 ) {
F_5 ( V_32 , L_7 ) ;
goto error;
}
return 0 ;
error:
return - V_36 ;
}
static void F_19 ( struct V_1 * V_1 )
{
int V_23 ;
T_2 V_37 ;
F_4 ( V_1 , 0x00 , 0x0d01 , 0x01 ) ;
F_4 ( V_1 , 0x00 , 0x0d03 , 0x00 ) ;
F_4 ( V_1 , 0x00 , 0x0d02 , 0x01 ) ;
F_4 ( V_1 , 0x00 , 0x850a , 0x0001 ) ;
V_23 = F_12 ( V_1 , 0x00 , 0x8800 , 0x8840 ,
V_38 ) ;
if ( V_23 < 0 )
F_5 ( V_32 | V_24 , L_9 ) ;
F_4 ( V_1 , 0x00 , 0x8880 , 2 ) ;
F_4 ( V_1 , 0x00 , 0x800a , 0x00 ) ;
F_4 ( V_1 , 0x00 , 0x820f , 0x01 ) ;
F_4 ( V_1 , 0x00 , 0x870a , 0x04 ) ;
F_4 ( V_1 , 0 , 0x8003 , 0x00 ) ;
F_4 ( V_1 , 0x00 , 0x8000 , 0x0004 ) ;
F_10 ( 2000 ) ;
if ( F_9 ( V_1 , 0 , 0x8000 , 0x44 ) != 0 ) {
F_1 ( V_1 , 0x816b , 1 ) ;
V_37 = V_1 -> V_8 [ 0 ] ;
F_4 ( V_1 , 0x00 , 0x816b , V_37 ) ;
}
}
static int F_20 ( struct V_1 * V_1 ,
const struct V_39 * V_40 )
{
struct V_41 * V_41 = (struct V_41 * ) V_1 ;
struct V_28 * V_28 ;
V_28 = & V_1 -> V_28 ;
V_41 -> V_42 = V_40 -> V_43 ;
if ( V_41 -> V_42 != V_44 ) {
V_28 -> V_29 = V_45 ;
V_28 -> V_46 = F_21 ( V_45 ) ;
} else {
V_28 -> V_29 = V_47 ;
V_28 -> V_46 = F_21 ( V_47 ) ;
}
V_41 -> V_48 = V_49 ;
V_41 -> V_50 = V_51 ;
V_41 -> V_52 = V_53 ;
V_41 -> V_54 = V_55 ;
return 0 ;
}
static int F_22 ( struct V_1 * V_1 )
{
struct V_41 * V_41 = (struct V_41 * ) V_1 ;
F_5 ( V_24 , L_10 ) ;
if ( V_41 -> V_42 == V_44 )
F_14 ( V_1 ) ;
F_5 ( V_24 , L_11 ) ;
return 0 ;
}
static int F_23 ( struct V_1 * V_1 )
{
struct V_41 * V_41 = (struct V_41 * ) V_1 ;
int V_23 ;
T_2 V_37 ;
T_2 V_25 , V_26 ;
F_24 ( V_41 -> V_56 , V_1 -> V_57 , V_1 -> V_58 ,
0x22 ) ;
F_25 ( V_41 -> V_56 , V_41 -> V_54 ) ;
if ( V_41 -> V_42 == V_44 ) {
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
switch ( V_41 -> V_42 ) {
case V_44 :
F_15 ( V_1 , V_25 , V_26 ) ;
F_4 ( V_1 , 0x00 , 0x850a , 0x0001 ) ;
F_4 ( V_1 , 0x00 , 0x8880 , 3 ) ;
V_23 = F_12 ( V_1 ,
0x00 , 0x8800 , 0x8840 ,
V_59 ) ;
if ( V_23 < 0 )
F_5 ( V_32 , L_14 ) ;
F_4 ( V_1 , 0x00 , 0x870a , 0x04 ) ;
F_4 ( V_1 , 0x00 , 0x8000 , 0x0004 ) ;
F_10 ( 500 ) ;
if ( F_9 ( V_1 , 0 , 0x8000 , 0x44 ) != 0 )
F_5 ( V_32 , L_6 ) ;
F_1 ( V_1 , 0x816b , 1 ) ;
V_37 = V_1 -> V_8 [ 0 ] ;
F_4 ( V_1 , 0x00 , 0x816b , V_37 ) ;
F_17 ( V_1 ) ;
F_11 ( V_1 , V_60 ) ;
F_15 ( V_1 , V_25 , V_26 ) ;
V_23 = F_4 ( V_1 , 0x00 , 0x850a , 0x0001 ) ;
if ( V_23 < 0 )
F_5 ( V_32 , L_15 ) ;
F_4 ( V_1 , 0x00 , 0x8880 , 3 ) ;
V_23 = F_12 ( V_1 ,
0x00 , 0x8800 , 0x8840 ,
V_59 ) ;
if ( V_23 < 0 )
F_5 ( V_32 , L_14 ) ;
F_4 ( V_1 , 0x00 , 0x870a , 0x04 ) ;
F_4 ( V_1 , 0x00 , 0x8000 , 0x0004 ) ;
if ( F_9 ( V_1 , 0 , 0x8000 , 0x44 ) != 0 )
F_5 ( V_32 , L_6 ) ;
F_1 ( V_1 , 0x816b , 1 ) ;
V_37 = V_1 -> V_8 [ 0 ] ;
F_4 ( V_1 , 0x00 , 0x816b , V_37 ) ;
break;
case V_61 :
case V_62 :
V_23 = F_16 ( V_1 ) ;
if ( V_23 < 0 )
F_5 ( V_32 , L_16 ) ;
V_23 = F_4 ( V_1 , 0x00 , 0x850a , 0x0001 ) ;
if ( V_23 < 0 )
F_5 ( V_32 , L_15 ) ;
F_4 ( V_1 , 0x00 , 0x8880 , 3 ) ;
V_23 = F_12 ( V_1 ,
0x00 , 0x8800 , 0x8840 ,
V_59 ) ;
if ( V_23 < 0 )
F_5 ( V_32 , L_14 ) ;
F_15 ( V_1 , V_25 , V_26 ) ;
F_4 ( V_1 , 0x20 , 0x0001 , 0x0004 ) ;
F_4 ( V_1 , 0x00 , 0x8000 , 0x0004 ) ;
if ( F_9 ( V_1 , 0 , 0x8000 , 0x44 ) != 0 )
F_5 ( V_32 , L_6 ) ;
F_1 ( V_1 , 0x816b , 1 ) ;
V_37 = V_1 -> V_8 [ 0 ] ;
F_4 ( V_1 , 0x00 , 0x816b , V_37 ) ;
break;
case V_63 :
V_23 = F_16 ( V_1 ) ;
if ( V_23 < 0 )
F_5 ( V_32 , L_16 ) ;
F_4 ( V_1 , 0x00 , 0x850a , 0x0001 ) ;
F_4 ( V_1 , 0x00 , 0x8880 , 0 ) ;
V_23 = F_12 ( V_1 ,
0x00 , 0x8800 , 0x8840 ,
V_64 ) ;
if ( V_23 < 0 )
F_5 ( V_32 , L_14 ) ;
F_15 ( V_1 , V_25 , V_26 ) ;
F_4 ( V_1 , 0x20 , 0x0001 , 0x0004 ) ;
F_4 ( V_1 , 0x00 , 0x8000 , 0x0004 ) ;
if ( F_9 ( V_1 , 0 , 0x8000 , 0x44 ) != 0 )
F_5 ( V_32 , L_6 ) ;
F_1 ( V_1 , 0x816b , 1 ) ;
V_37 = V_1 -> V_8 [ 0 ] ;
F_4 ( V_1 , 0x00 , 0x816b , V_37 ) ;
break;
case V_65 :
case V_66 :
case V_67 :
case V_68 :
case V_69 :
case V_70 :
case V_71 :
case V_72 :
case V_73 :
F_19 ( V_1 ) ;
F_4 ( V_1 , 0x00 , 0x0d01 , 0x01 ) ;
F_4 ( V_1 , 0x00 , 0x850a , 0x0001 ) ;
V_23 = F_12 ( V_1 ,
0x00 , 0x8800 , 0x8840 , V_38 ) ;
if ( V_23 < 0 )
F_5 ( V_32 , L_14 ) ;
F_4 ( V_1 , 0x00 , 0x8880 , 2 ) ;
F_4 ( V_1 , 0x00 , 0x800a , 0x00 ) ;
F_4 ( V_1 , 0x00 , 0x820f , 0x01 ) ;
F_4 ( V_1 , 0x00 , 0x870a , 0x04 ) ;
F_15 ( V_1 , V_25 , V_26 ) ;
F_4 ( V_1 , 0x00 , 0x8000 , 0x0004 ) ;
F_9 ( V_1 , 0 , 0x8000 , 0x44 ) ;
F_1 ( V_1 , 0x816b , 1 ) ;
V_37 = V_1 -> V_8 [ 0 ] ;
F_4 ( V_1 , 0x00 , 0x816b , V_37 ) ;
break;
case V_74 :
case V_75 :
F_4 ( V_1 , 0x02 , 0x00 , 0x00 ) ;
F_4 ( V_1 , 0x00 , 0x850a , 0x0001 ) ;
V_23 = F_12 ( V_1 ,
0x00 , 0x8800 ,
0x8840 , V_59 ) ;
if ( V_23 < 0 )
F_5 ( V_32 , L_14 ) ;
F_4 ( V_1 , 0x00 , 0x8880 , 3 ) ;
F_4 ( V_1 , 0x00 , 0x800a , 0x00 ) ;
F_4 ( V_1 , 0x00 , 0x870a , 0x04 ) ;
F_15 ( V_1 , V_25 , V_26 ) ;
F_4 ( V_1 , 0x00 , 0x8000 , 0x0004 ) ;
F_9 ( V_1 , 0 , 0x8000 , 0x44 ) ;
F_1 ( V_1 , 0x816b , 1 ) ;
V_37 = V_1 -> V_8 [ 0 ] ;
F_4 ( V_1 , 0x00 , 0x816b , V_37 ) ;
F_11 ( V_1 , V_76 ) ;
break;
}
return 0 ;
}
static void F_26 ( struct V_1 * V_1 )
{
F_4 ( V_1 , 0 , 0x8003 , 0x00 ) ;
F_4 ( V_1 , 0x00 , 0x8000 , 0x0004 ) ;
F_1 ( V_1 , 0x8000 , 1 ) ;
F_5 ( V_24 , L_17 ,
V_1 -> V_8 [ 0 ] ) ;
}
static void F_27 ( struct V_1 * V_1 ,
T_3 * V_17 ,
int V_77 )
{
struct V_41 * V_41 = (struct V_41 * ) V_1 ;
int V_18 ;
static T_2 V_78 [] = { 0xff , 0xd9 } ;
if ( V_17 [ 0 ] == 0xff ) {
if ( V_17 [ 1 ] != 0x01 ) {
return;
}
F_28 ( V_1 , V_79 ,
V_78 , 2 ) ;
F_28 ( V_1 , V_80 ,
V_41 -> V_56 , V_81 ) ;
V_17 += V_82 ;
V_77 -= V_82 ;
} else {
V_17 += 1 ;
V_77 -= 1 ;
}
V_18 = 0 ;
do {
if ( V_17 [ V_18 ] == 0xff ) {
F_28 ( V_1 , V_83 ,
V_17 , V_18 + 1 ) ;
V_77 -= V_18 ;
V_17 += V_18 ;
* V_17 = 0x00 ;
V_18 = 0 ;
}
V_18 ++ ;
} while ( V_18 < V_77 );
F_28 ( V_1 , V_83 , V_17 , V_77 ) ;
}
static void F_29 ( struct V_1 * V_1 )
{
struct V_41 * V_41 = (struct V_41 * ) V_1 ;
F_4 ( V_1 , 0x00 , 0x8167 ,
( T_2 ) ( V_41 -> V_48 - 128 ) ) ;
}
static void F_30 ( struct V_1 * V_1 )
{
struct V_41 * V_41 = (struct V_41 * ) V_1 ;
F_4 ( V_1 , 0x00 , 0x8168 , V_41 -> V_50 ) ;
}
static void F_31 ( struct V_1 * V_1 )
{
struct V_41 * V_41 = (struct V_41 * ) V_1 ;
F_4 ( V_1 , 0x00 , 0x8169 , V_41 -> V_52 ) ;
}
static int F_32 ( struct V_1 * V_1 , T_4 V_84 )
{
struct V_41 * V_41 = (struct V_41 * ) V_1 ;
V_41 -> V_48 = V_84 ;
if ( V_1 -> V_85 )
F_29 ( V_1 ) ;
return 0 ;
}
static int F_33 ( struct V_1 * V_1 , T_4 * V_84 )
{
struct V_41 * V_41 = (struct V_41 * ) V_1 ;
* V_84 = V_41 -> V_48 ;
return 0 ;
}
static int F_34 ( struct V_1 * V_1 , T_4 V_84 )
{
struct V_41 * V_41 = (struct V_41 * ) V_1 ;
V_41 -> V_50 = V_84 ;
if ( V_1 -> V_85 )
F_30 ( V_1 ) ;
return 0 ;
}
static int F_35 ( struct V_1 * V_1 , T_4 * V_84 )
{
struct V_41 * V_41 = (struct V_41 * ) V_1 ;
* V_84 = V_41 -> V_50 ;
return 0 ;
}
static int F_36 ( struct V_1 * V_1 , T_4 V_84 )
{
struct V_41 * V_41 = (struct V_41 * ) V_1 ;
V_41 -> V_52 = V_84 ;
if ( V_1 -> V_85 )
F_31 ( V_1 ) ;
return 0 ;
}
static int F_37 ( struct V_1 * V_1 , T_4 * V_84 )
{
struct V_41 * V_41 = (struct V_41 * ) V_1 ;
* V_84 = V_41 -> V_52 ;
return 0 ;
}
static int F_38 ( struct V_1 * V_1 ,
struct V_86 * V_87 )
{
struct V_41 * V_41 = (struct V_41 * ) V_1 ;
if ( V_87 -> V_54 < V_88 )
V_41 -> V_54 = V_88 ;
else if ( V_87 -> V_54 > V_89 )
V_41 -> V_54 = V_89 ;
else
V_41 -> V_54 = V_87 -> V_54 ;
if ( V_1 -> V_85 )
F_25 ( V_41 -> V_56 , V_41 -> V_54 ) ;
return 0 ;
}
static int F_39 ( struct V_1 * V_1 ,
struct V_86 * V_87 )
{
struct V_41 * V_41 = (struct V_41 * ) V_1 ;
memset ( V_87 , 0 , sizeof *V_87 ) ;
V_87 -> V_54 = V_41 -> V_54 ;
V_87 -> V_90 = V_91
| V_92 ;
return 0 ;
}
static int F_40 ( struct V_93 * V_94 ,
const struct V_39 * V_40 )
{
return F_41 ( V_94 , V_40 , & V_95 , sizeof( struct V_41 ) ,
V_96 ) ;
}
static int T_5 F_42 ( void )
{
return F_43 ( & V_97 ) ;
}
static void T_6 F_44 ( void )
{
F_45 ( & V_97 ) ;
}
