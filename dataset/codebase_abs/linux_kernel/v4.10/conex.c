static void F_1 ( struct V_1 * V_1 ,
T_1 V_2 ,
T_1 V_3 )
{
struct V_4 * V_5 = V_1 -> V_5 ;
if ( V_3 > V_6 ) {
F_2 ( L_1 ) ;
return;
}
F_3 ( V_5 ,
F_4 ( V_5 , 0 ) ,
0 ,
V_7 | V_8 | V_9 ,
0 ,
V_2 , V_1 -> V_10 , V_3 ,
500 ) ;
F_5 ( V_11 , L_2 ,
V_2 , V_1 -> V_10 [ 0 ] ) ;
}
static void F_6 ( struct V_1 * V_1 ,
T_1 V_2 ,
T_2 V_12 )
{
struct V_4 * V_5 = V_1 -> V_5 ;
V_1 -> V_10 [ 0 ] = V_12 ;
F_3 ( V_5 ,
F_7 ( V_5 , 0 ) ,
0 ,
V_13 | V_8 | V_9 ,
0 ,
V_2 , V_1 -> V_10 , 1 , 500 ) ;
}
static void F_8 ( struct V_1 * V_1 ,
T_1 V_2 ,
const T_2 * V_14 ,
T_1 V_3 )
{
struct V_4 * V_5 = V_1 -> V_5 ;
if ( V_3 > V_6 ) {
F_2 ( L_3 ) ;
return;
}
F_5 ( V_15 , L_4 , V_2 , * V_14 ) ;
memcpy ( V_1 -> V_10 , V_14 , V_3 ) ;
F_3 ( V_5 ,
F_7 ( V_5 , 0 ) ,
0 ,
V_13 | V_8 | V_9 ,
0 ,
V_2 , V_1 -> V_10 , V_3 , 500 ) ;
}
static void F_9 ( struct V_1 * V_1 )
{
int V_16 = 0 ;
F_6 ( V_1 , 0x006a , 0x02 ) ;
while ( V_17 [ V_16 ] [ 1 ] ) {
F_8 ( V_1 , 0x006b , V_17 [ V_16 ] , 3 ) ;
V_16 ++ ;
}
F_6 ( V_1 , 0x006a , 0x00 ) ;
}
static void F_10 ( struct V_1 * V_1 )
{
int V_16 = 0 ;
int V_18 ;
const T_2 * V_19 = V_20 ;
F_8 ( V_1 , 0x0020 , V_21 , 8 ) ;
F_8 ( V_1 , 0x0028 , V_22 , 8 ) ;
F_8 ( V_1 , 0x0010 , V_23 , 2 ) ;
F_6 ( V_1 , 0x0092 , 0x03 ) ;
switch ( V_1 -> V_24 . V_25 [ ( int ) V_1 -> V_26 ] . V_27 ) {
case 0 :
F_8 ( V_1 , 0x0071 , V_28 , 4 ) ;
break;
case 1 :
F_8 ( V_1 , 0x0071 , V_29 , 4 ) ;
break;
default:
F_8 ( V_1 , 0x0071 , V_30 , 4 ) ;
break;
case 3 :
F_8 ( V_1 , 0x0071 , V_31 , 4 ) ;
break;
}
F_8 ( V_1 , 0x007b , V_32 , 6 ) ;
F_6 ( V_1 , 0x00f8 , 0x00 ) ;
F_8 ( V_1 , 0x0010 , V_23 , 2 ) ;
F_6 ( V_1 , 0x0098 , 0x41 ) ;
for ( V_16 = 0 ; V_16 < 11 ; V_16 ++ ) {
if ( V_16 == 3 || V_16 == 5 || V_16 == 8 )
V_18 = 8 ;
else
V_18 = 4 ;
F_8 ( V_1 , 0x00e5 , V_19 , V_18 ) ;
if ( V_18 == 4 )
F_1 ( V_1 , 0x00e8 , 1 ) ;
else
F_1 ( V_1 , 0x00e8 , V_18 ) ;
V_19 += V_18 ;
}
F_1 ( V_1 , 0x00e7 , 8 ) ;
}
static void F_11 ( struct V_1 * V_1 )
{
const T_2 * V_33 ;
static const T_2 V_34 [] = { 0x08 , 0x05 , 0x07 , 0x04 , 0x24 } ;
static const T_2 V_35 [] =
{ 0x0a , 0x00 , 0xf2 , 0x01 , 0x0f , 0x00 , 0x97 , 0x02 } ;
switch ( V_1 -> V_24 . V_25 [ ( int ) V_1 -> V_26 ] . V_27 ) {
case 0 :
V_33 = V_36 ;
break;
case 1 :
V_33 = V_37 ;
break;
default:
V_33 = V_38 ;
break;
case 3 :
V_33 = V_39 ;
break;
}
F_6 ( V_1 , 0x009a , 0x01 ) ;
F_6 ( V_1 , 0x0010 , 0x10 ) ;
F_8 ( V_1 , 0x0012 , V_34 , 5 ) ;
F_8 ( V_1 , 0x0017 , V_35 , 8 ) ;
F_6 ( V_1 , 0x00c0 , 0x00 ) ;
F_6 ( V_1 , 0x00c1 , 0x04 ) ;
F_6 ( V_1 , 0x00c2 , 0x04 ) ;
F_8 ( V_1 , 0x0061 , V_33 , 8 ) ;
V_33 += 8 ;
F_8 ( V_1 , 0x00ca , V_33 , 8 ) ;
V_33 += 8 ;
F_8 ( V_1 , 0x00d2 , V_33 , 8 ) ;
V_33 += 8 ;
F_8 ( V_1 , 0x00da , V_33 , 6 ) ;
V_33 += 8 ;
F_8 ( V_1 , 0x0041 , V_33 , 8 ) ;
V_33 += 8 ;
F_8 ( V_1 , 0x0049 , V_33 , 8 ) ;
V_33 += 8 ;
F_8 ( V_1 , 0x0051 , V_33 , 2 ) ;
F_1 ( V_1 , 0x0010 , 1 ) ;
}
static void F_12 ( struct V_1 * V_1 )
{
int V_16 ;
int V_18 ;
F_6 ( V_1 , 0x00c0 , 0x01 ) ;
F_6 ( V_1 , 0x00c3 , 0x00 ) ;
F_6 ( V_1 , 0x00c0 , 0x00 ) ;
F_1 ( V_1 , 0x0001 , 1 ) ;
V_18 = 8 ;
for ( V_16 = 0 ; V_16 < 79 ; V_16 ++ ) {
if ( V_16 == 78 )
V_18 = 6 ;
F_8 ( V_1 , 0x0008 , V_40 [ V_16 ] , V_18 ) ;
}
F_1 ( V_1 , 0x0002 , 1 ) ;
F_6 ( V_1 , 0x0055 , 0x14 ) ;
}
static void F_13 ( struct V_1 * V_1 )
{
int V_16 ;
int V_18 ;
T_2 V_41 ;
int V_42 ;
F_6 ( V_1 , 0x00c0 , 0x01 ) ;
F_6 ( V_1 , 0x00c3 , 0x00 ) ;
F_6 ( V_1 , 0x00c0 , 0x00 ) ;
F_1 ( V_1 , 0x0001 , 1 ) ;
V_18 = 8 ;
switch ( V_1 -> V_24 . V_25 [ V_1 -> V_26 ] . V_27 ) {
case 0 :
for ( V_16 = 0 ; V_16 < 27 ; V_16 ++ ) {
if ( V_16 == 26 )
V_18 = 2 ;
F_8 ( V_1 , 0x0008 , V_43 [ V_16 ] , V_18 ) ;
}
V_41 = 0x28 ;
break;
case 1 :
for ( V_16 = 0 ; V_16 < 27 ; V_16 ++ ) {
if ( V_16 == 26 )
V_18 = 2 ;
F_8 ( V_1 , 0x0008 , V_44 [ V_16 ] , V_18 ) ;
}
V_41 = 0x16 ;
break;
default:
for ( V_16 = 0 ; V_16 < 27 ; V_16 ++ ) {
if ( V_16 == 26 )
V_18 = 2 ;
F_8 ( V_1 , 0x0008 , V_45 [ V_16 ] , V_18 ) ;
}
V_41 = 0x14 ;
break;
case 3 :
for ( V_16 = 0 ; V_16 < 27 ; V_16 ++ ) {
if ( V_16 == 26 )
V_18 = 2 ;
F_8 ( V_1 , 0x0008 , V_46 [ V_16 ] , V_18 ) ;
}
V_41 = 0x0B ;
break;
}
F_1 ( V_1 , 0x0002 , 1 ) ;
F_6 ( V_1 , 0x0055 , V_41 ) ;
F_1 ( V_1 , 0x0002 , 1 ) ;
F_8 ( V_1 , 0x0010 , V_23 , 2 ) ;
F_6 ( V_1 , 0x0054 , 0x02 ) ;
F_6 ( V_1 , 0x0054 , 0x01 ) ;
F_6 ( V_1 , 0x0000 , 0x94 ) ;
F_6 ( V_1 , 0x0053 , 0xc0 ) ;
F_6 ( V_1 , 0x00fc , 0xe1 ) ;
F_6 ( V_1 , 0x0000 , 0x00 ) ;
V_42 = 50 ;
do {
F_1 ( V_1 , 0x0002 , 1 ) ;
if ( V_1 -> V_10 [ 0 ] == 0x00 )
break;
F_6 ( V_1 , 0x0053 , 0x00 ) ;
} while ( -- V_42 );
if ( V_42 == 0 )
F_2 ( L_5 ) ;
F_1 ( V_1 , 0x0001 , 1 ) ;
V_18 = 8 ;
for ( V_16 = 0 ; V_16 < 18 ; V_16 ++ ) {
if ( V_16 == 17 )
V_18 = 2 ;
F_8 ( V_1 , 0x0008 , V_47 [ V_16 ] , V_18 ) ;
}
F_1 ( V_1 , 0x0002 , 1 ) ;
F_1 ( V_1 , 0x0053 , 1 ) ;
F_6 ( V_1 , 0x0054 , 0x02 ) ;
F_6 ( V_1 , 0x0054 , 0x01 ) ;
F_6 ( V_1 , 0x0000 , 0x94 ) ;
F_6 ( V_1 , 0x0053 , 0xc0 ) ;
F_1 ( V_1 , 0x0038 , 1 ) ;
F_1 ( V_1 , 0x0038 , 1 ) ;
F_1 ( V_1 , 0x001f , 1 ) ;
F_8 ( V_1 , 0x0012 , V_34 , 5 ) ;
F_8 ( V_1 , 0x00e5 , V_48 , 8 ) ;
F_1 ( V_1 , 0x00e8 , 8 ) ;
F_8 ( V_1 , 0x00e5 , V_49 , 4 ) ;
F_1 ( V_1 , 0x00e8 , 1 ) ;
F_6 ( V_1 , 0x009a , 0x01 ) ;
F_8 ( V_1 , 0x00e5 , V_50 , 4 ) ;
F_1 ( V_1 , 0x00e8 , 1 ) ;
F_8 ( V_1 , 0x00e5 , V_51 , 4 ) ;
F_1 ( V_1 , 0x00e8 , 1 ) ;
F_8 ( V_1 , 0x0051 , V_52 , 2 ) ;
F_8 ( V_1 , 0x0010 , V_23 , 2 ) ;
F_6 ( V_1 , 0x0070 , V_53 ) ;
}
static void F_14 ( struct V_1 * V_1 )
{
int V_16 = 0 ;
F_6 ( V_1 , 0x0010 , 0x00 ) ;
F_6 ( V_1 , 0x0053 , 0x00 ) ;
F_6 ( V_1 , 0x0052 , 0x00 ) ;
F_6 ( V_1 , 0x009b , 0x2f ) ;
F_6 ( V_1 , 0x009c , 0x10 ) ;
F_1 ( V_1 , 0x0098 , 1 ) ;
F_6 ( V_1 , 0x0098 , 0x40 ) ;
F_1 ( V_1 , 0x0099 , 1 ) ;
F_6 ( V_1 , 0x0099 , 0x07 ) ;
F_6 ( V_1 , 0x0039 , 0x40 ) ;
F_6 ( V_1 , 0x003c , 0xff ) ;
F_6 ( V_1 , 0x003f , 0x1f ) ;
F_6 ( V_1 , 0x003d , 0x40 ) ;
F_1 ( V_1 , 0x0099 , 1 ) ;
while ( V_54 [ V_16 ] [ 0 ] ) {
F_6 ( V_1 , 0x00e5 , V_54 [ V_16 ] [ 0 ] ) ;
F_1 ( V_1 , 0x00e8 , 1 ) ;
if ( V_16 == 1 ) {
F_6 ( V_1 , 0x00ed , 0x01 ) ;
F_1 ( V_1 , 0x00ed , 1 ) ;
}
V_16 ++ ;
}
F_6 ( V_1 , 0x00c3 , 0x00 ) ;
}
static int F_15 ( struct V_1 * V_1 ,
const struct V_55 * V_56 )
{
struct V_24 * V_24 ;
V_24 = & V_1 -> V_24 ;
V_24 -> V_25 = V_57 ;
V_24 -> V_58 = F_16 ( V_57 ) ;
return 0 ;
}
static int F_17 ( struct V_1 * V_1 )
{
F_14 ( V_1 ) ;
F_11 ( V_1 ) ;
F_9 ( V_1 ) ;
F_10 ( V_1 ) ;
F_12 ( V_1 ) ;
return 0 ;
}
static int F_18 ( struct V_1 * V_1 )
{
struct V_59 * V_59 = (struct V_59 * ) V_1 ;
F_19 ( V_59 -> V_60 , V_1 -> V_61 . V_62 ,
V_1 -> V_61 . V_63 ,
0x22 ) ;
F_20 ( V_59 -> V_60 , V_64 ) ;
F_11 ( V_1 ) ;
F_9 ( V_1 ) ;
F_10 ( V_1 ) ;
F_13 ( V_1 ) ;
return 0 ;
}
static void F_21 ( struct V_1 * V_1 )
{
int V_42 = 50 ;
if ( ! V_1 -> V_65 )
return;
F_6 ( V_1 , 0x0000 , 0x00 ) ;
F_1 ( V_1 , 0x0002 , 1 ) ;
F_6 ( V_1 , 0x0053 , 0x00 ) ;
while ( V_42 -- ) {
F_1 ( V_1 , 0x0053 , 1 ) ;
if ( V_1 -> V_10 [ 0 ] == 0 )
break;
}
F_6 ( V_1 , 0x0000 , 0x00 ) ;
F_1 ( V_1 , 0x0002 , 1 ) ;
F_6 ( V_1 , 0x0010 , 0x00 ) ;
F_1 ( V_1 , 0x0033 , 1 ) ;
F_6 ( V_1 , 0x00fc , 0xe0 ) ;
}
static void F_22 ( struct V_1 * V_1 ,
T_3 * V_66 ,
int V_3 )
{
struct V_59 * V_59 = (struct V_59 * ) V_1 ;
if ( V_66 [ 0 ] == 0xff && V_66 [ 1 ] == 0xd8 ) {
F_23 ( V_1 , V_67 , NULL , 0 ) ;
F_23 ( V_1 , V_68 ,
V_59 -> V_60 , V_69 ) ;
V_66 += 2 ;
V_3 -= 2 ;
}
F_23 ( V_1 , V_70 , V_66 , V_3 ) ;
}
static void F_24 ( struct V_1 * V_1 , T_4 V_12 , T_4 V_71 )
{
T_2 V_72 [] = { 0x88 , 0x00 , 0xd4 , 0x01 , 0x88 , 0x01 , 0x01 , 0x01 } ;
T_2 V_73 [ 2 ] ;
V_72 [ 2 ] = V_12 ;
F_8 ( V_1 , 0x00e5 , V_72 , 8 ) ;
F_1 ( V_1 , 0x00e8 , 8 ) ;
F_8 ( V_1 , 0x00e5 , V_51 , 4 ) ;
F_1 ( V_1 , 0x00e8 , 1 ) ;
V_73 [ 0 ] = 0x77 ;
V_73 [ 1 ] = V_71 ;
F_8 ( V_1 , 0x0051 , V_73 , 2 ) ;
F_8 ( V_1 , 0x0010 , V_23 , 2 ) ;
F_6 ( V_1 , 0x0070 , V_53 ) ;
}
static void F_25 ( struct V_1 * V_1 , T_4 V_12 , T_4 V_71 )
{
T_2 V_74 [] = { 0x88 , 0x0a , 0x0c , 0x01 } ;
T_2 V_73 [ 2 ] ;
V_74 [ 2 ] = V_12 ;
F_8 ( V_1 , 0x00e5 , V_74 , 4 ) ;
F_1 ( V_1 , 0x00e8 , 1 ) ;
V_73 [ 0 ] = 0x77 ;
V_73 [ 1 ] = V_71 ;
F_8 ( V_1 , 0x0051 , V_73 , 2 ) ;
F_8 ( V_1 , 0x0010 , V_23 , 2 ) ;
F_6 ( V_1 , 0x0070 , V_53 ) ;
}
static int F_26 ( struct V_75 * V_76 )
{
struct V_1 * V_1 =
F_27 ( V_76 -> V_77 , struct V_1 , V_78 ) ;
struct V_59 * V_59 = (struct V_59 * ) V_1 ;
V_1 -> V_79 = 0 ;
if ( ! V_1 -> V_80 )
return 0 ;
switch ( V_76 -> V_56 ) {
case V_81 :
F_24 ( V_1 , V_76 -> V_12 , V_59 -> V_71 -> V_82 . V_12 ) ;
break;
case V_83 :
F_25 ( V_1 , V_76 -> V_12 , V_59 -> V_71 -> V_82 . V_12 ) ;
break;
case V_84 :
F_24 ( V_1 , V_59 -> V_85 -> V_82 . V_12 , V_76 -> V_12 ) ;
F_25 ( V_1 , V_59 -> V_86 -> V_82 . V_12 , V_76 -> V_12 ) ;
break;
}
return V_1 -> V_79 ;
}
static int F_28 ( struct V_1 * V_1 )
{
struct V_59 * V_59 = (struct V_59 * ) V_1 ;
struct V_87 * V_88 = & V_1 -> V_78 ;
V_1 -> V_89 . V_78 = V_88 ;
F_29 ( V_88 , 3 ) ;
V_59 -> V_85 = F_30 ( V_88 , & V_90 ,
V_81 , 0 , 255 , 1 , 0xd4 ) ;
V_59 -> V_86 = F_30 ( V_88 , & V_90 ,
V_83 , 0x0a , 0x1f , 1 , 0x0c ) ;
V_59 -> V_71 = F_30 ( V_88 , & V_90 ,
V_84 , 0 , 7 , 1 , 3 ) ;
if ( V_88 -> error ) {
F_31 ( L_6 ) ;
return V_88 -> error ;
}
return 0 ;
}
static int F_32 ( struct V_91 * V_92 ,
const struct V_55 * V_56 )
{
return F_33 ( V_92 , V_56 , & V_93 , sizeof( struct V_59 ) ,
V_94 ) ;
}
