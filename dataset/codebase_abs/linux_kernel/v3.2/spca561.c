static void F_1 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_4 )
{
int V_5 ;
V_5 = F_2 ( V_2 , F_3 ( V_2 , 0 ) ,
0 ,
V_6 | V_7 | V_8 ,
V_4 , V_3 , NULL , 0 , 500 ) ;
F_4 ( V_9 , L_1 , V_3 , V_4 ) ;
if ( V_5 < 0 )
F_5 ( L_2 , V_5 ) ;
}
static void F_6 ( struct V_10 * V_10 ,
const T_1 V_11 [] [ 2 ] )
{
struct V_1 * V_2 = V_10 -> V_2 ;
int V_12 ;
V_12 = 0 ;
while ( V_11 [ V_12 ] [ 1 ] != 0 ) {
F_1 ( V_2 , V_11 [ V_12 ] [ 1 ] , V_11 [ V_12 ] [ 0 ] ) ;
V_12 ++ ;
}
}
static void F_7 ( struct V_10 * V_10 ,
T_1 V_3 , T_1 V_13 )
{
F_2 ( V_10 -> V_2 ,
F_8 ( V_10 -> V_2 , 0 ) ,
0 ,
V_14 | V_7 | V_8 ,
0 ,
V_3 , V_10 -> V_15 , V_13 , 500 ) ;
}
static void F_9 ( struct V_10 * V_10 ,
T_1 V_3 , T_1 V_16 )
{
F_2 ( V_10 -> V_2 ,
F_3 ( V_10 -> V_2 , 0 ) ,
0 ,
V_6 | V_7 | V_8 ,
0 ,
V_3 , V_10 -> V_15 , V_16 , 500 ) ;
}
static void F_10 ( struct V_10 * V_10 , T_1 V_4 , T_1 V_17 )
{
int V_18 = 60 ;
F_1 ( V_10 -> V_2 , 0x8801 , V_17 ) ;
F_1 ( V_10 -> V_2 , 0x8805 , V_4 ) ;
F_1 ( V_10 -> V_2 , 0x8800 , V_4 >> 8 ) ;
do {
F_7 ( V_10 , 0x8803 , 1 ) ;
if ( ! V_10 -> V_15 [ 0 ] )
return;
F_11 ( 10 ) ;
} while ( -- V_18 );
}
static int F_12 ( struct V_10 * V_10 , T_1 V_17 , T_2 V_19 )
{
int V_18 = 60 ;
T_2 V_4 ;
F_1 ( V_10 -> V_2 , 0x8804 , 0x92 ) ;
F_1 ( V_10 -> V_2 , 0x8801 , V_17 ) ;
F_1 ( V_10 -> V_2 , 0x8802 , V_19 | 0x01 ) ;
do {
F_7 ( V_10 , 0x8803 , 1 ) ;
if ( ! V_10 -> V_15 [ 0 ] ) {
F_7 ( V_10 , 0x8800 , 1 ) ;
V_4 = V_10 -> V_15 [ 0 ] ;
F_7 ( V_10 , 0x8805 , 1 ) ;
return ( ( int ) V_4 << 8 ) | V_10 -> V_15 [ 0 ] ;
}
F_11 ( 10 ) ;
} while ( -- V_18 );
return - 1 ;
}
static void F_13 ( struct V_10 * V_10 )
{
F_6 ( V_10 , V_20 ) ;
F_14 ( V_10 , V_21 ) ;
F_6 ( V_10 , V_22 ) ;
F_14 ( V_10 , V_23 ) ;
}
static int F_15 ( struct V_10 * V_10 ,
const struct V_24 * V_25 )
{
struct V_26 * V_26 = (struct V_26 * ) V_10 ;
struct V_27 * V_27 ;
T_1 V_28 , V_29 ;
T_2 V_30 , V_31 ;
F_7 ( V_10 , 0x8104 , 1 ) ;
V_30 = V_10 -> V_15 [ 0 ] ;
F_7 ( V_10 , 0x8105 , 1 ) ;
V_31 = V_10 -> V_15 [ 0 ] ;
V_28 = ( V_31 << 8 ) | V_30 ;
F_7 ( V_10 , 0x8106 , 1 ) ;
V_30 = V_10 -> V_15 [ 0 ] ;
F_7 ( V_10 , 0x8107 , 1 ) ;
V_31 = V_10 -> V_15 [ 0 ] ;
V_29 = ( V_31 << 8 ) | V_30 ;
if ( V_28 != V_25 -> V_32 || V_29 != V_25 -> V_33 ) {
F_4 ( V_34 , L_3 ) ;
return - V_35 ;
}
V_27 = & V_10 -> V_27 ;
V_10 -> V_36 = 7 + 1 ;
V_26 -> V_37 = V_25 -> V_38 ;
if ( V_26 -> V_37 == V_39 ) {
V_27 -> V_40 = V_41 ;
V_27 -> V_42 = F_16 ( V_41 ) ;
} else {
V_27 -> V_40 = V_43 ;
V_27 -> V_42 = F_16 ( V_43 ) ;
}
V_26 -> V_44 = V_45 ;
V_26 -> V_46 = V_47 ;
V_26 -> V_48 = V_49 ;
V_26 -> V_50 = V_51 ;
V_26 -> V_52 = V_53 ;
V_26 -> V_54 = V_55 ;
V_26 -> V_56 = V_57 ;
return 0 ;
}
static int F_17 ( struct V_10 * V_10 )
{
F_4 ( V_58 , L_4 ) ;
F_13 ( V_10 ) ;
return 0 ;
}
static int F_18 ( struct V_10 * V_10 )
{
F_4 ( V_58 , L_5 ) ;
F_6 ( V_10 , V_59 ) ;
F_11 ( 200 ) ;
F_6 ( V_10 , V_60 ) ;
F_19 ( V_10 , V_61 ) ;
F_6 ( V_10 , V_62 ) ;
F_19 ( V_10 , V_63 ) ;
F_1 ( V_10 -> V_2 , 0x8112 , 0x30 ) ;
return 0 ;
}
static void F_20 ( struct V_10 * V_10 )
{
struct V_26 * V_26 = (struct V_26 * ) V_10 ;
struct V_1 * V_2 = V_10 -> V_2 ;
T_2 V_4 ;
V_4 = V_26 -> V_44 ;
F_1 ( V_2 , 0x8611 , V_4 ) ;
F_1 ( V_2 , 0x8612 , V_4 ) ;
F_1 ( V_2 , 0x8613 , V_4 ) ;
F_1 ( V_2 , 0x8614 , V_4 ) ;
}
static void F_21 ( struct V_10 * V_10 )
{
struct V_26 * V_26 = (struct V_26 * ) V_10 ;
T_1 V_48 ;
T_2 V_64 , V_65 ;
T_1 V_17 ;
V_48 = V_26 -> V_48 ;
V_65 = 0x20 + V_48 * 3 / 8 ;
V_64 = 0x90 - V_48 * 5 / 8 ;
if ( V_26 -> V_37 == V_39 ) {
V_17 = 0x8614 ;
} else {
V_17 = 0x8651 ;
V_65 += V_26 -> V_46 - 0x20 ;
V_64 += V_26 -> V_46 - 0x20 ;
}
F_1 ( V_10 -> V_2 , V_17 , V_65 ) ;
F_1 ( V_10 -> V_2 , V_17 + 2 , V_64 ) ;
}
static void F_22 ( struct V_10 * V_10 )
{
struct V_26 * V_26 = (struct V_26 * ) V_10 ;
struct V_1 * V_2 = V_10 -> V_2 ;
T_2 V_4 ;
if ( V_26 -> V_37 != V_66 )
return;
V_4 = V_26 -> V_46 + 0x20 ;
F_21 ( V_10 ) ;
F_1 ( V_2 , 0x8652 , V_4 ) ;
F_1 ( V_2 , 0x8654 , V_4 ) ;
}
static void F_23 ( struct V_10 * V_10 )
{
struct V_26 * V_26 = (struct V_26 * ) V_10 ;
int V_12 , V_67 = 0 ;
int V_68 [] = { 0 , 450 , 550 , 625 , V_69 } ;
for ( V_12 = 0 ; V_12 < F_16 ( V_68 ) - 1 ; V_12 ++ ) {
if ( V_26 -> V_50 <= V_68 [ V_12 + 1 ] ) {
V_67 = V_26 -> V_50 - V_68 [ V_12 ] ;
if ( V_12 )
V_67 += 300 ;
V_67 |= V_12 << 11 ;
break;
}
}
V_10 -> V_15 [ 0 ] = V_67 ;
V_10 -> V_15 [ 1 ] = V_67 >> 8 ;
F_9 ( V_10 , 0x8309 , 2 ) ;
}
static void F_24 ( struct V_10 * V_10 )
{
struct V_26 * V_26 = (struct V_26 * ) V_10 ;
if ( V_26 -> V_54 < 64 )
V_10 -> V_15 [ 0 ] = V_26 -> V_54 ;
else if ( V_26 -> V_54 < 128 )
V_10 -> V_15 [ 0 ] = ( V_26 -> V_54 / 2 ) | 0x40 ;
else
V_10 -> V_15 [ 0 ] = ( V_26 -> V_54 / 4 ) | 0xc0 ;
V_10 -> V_15 [ 1 ] = 0 ;
F_9 ( V_10 , 0x8335 , 2 ) ;
}
static void F_25 ( struct V_10 * V_10 )
{
struct V_26 * V_26 = (struct V_26 * ) V_10 ;
if ( V_26 -> V_52 )
V_26 -> V_70 = V_71 ;
else
V_26 -> V_70 = - 1 ;
}
static int F_26 ( struct V_10 * V_10 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
int V_19 ;
static const T_2 V_72 [ 8 ] =
{ 0x92 , 0x30 , 0x20 , 0x00 , 0x0c , 0x00 , 0x00 , 0x00 } ;
V_19 = V_10 -> V_27 . V_40 [ ( int ) V_10 -> V_73 ] . V_74 ;
if ( V_19 <= 1 ) {
F_1 ( V_2 , 0x8500 , 0x10 | V_19 ) ;
} else {
F_1 ( V_2 , 0x8500 , V_19 ) ;
}
V_10 -> V_15 [ 0 ] = 0xaa ;
V_10 -> V_15 [ 1 ] = 0x00 ;
F_9 ( V_10 , 0x8307 , 2 ) ;
F_1 ( V_10 -> V_2 , 0x8700 , 0x8a ) ;
F_1 ( V_10 -> V_2 , 0x8112 , 0x1e | 0x20 ) ;
F_1 ( V_10 -> V_2 , 0x850b , 0x03 ) ;
memcpy ( V_10 -> V_15 , V_72 , 8 ) ;
F_9 ( V_10 , 0x8391 , 8 ) ;
F_9 ( V_10 , 0x8390 , 8 ) ;
F_21 ( V_10 ) ;
F_24 ( V_10 ) ;
F_23 ( V_10 ) ;
F_1 ( V_10 -> V_2 , 0x8114 , 0x00 ) ;
return 0 ;
}
static int F_27 ( struct V_10 * V_10 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
int V_75 ;
int V_19 ;
F_6 ( V_10 , V_59 ) ;
F_11 ( 200 ) ;
F_6 ( V_10 , V_60 ) ;
F_19 ( V_10 , V_61 ) ;
V_19 = V_10 -> V_27 . V_40 [ ( int ) V_10 -> V_73 ] . V_74 ;
switch ( V_19 ) {
default:
case 0 :
V_75 = 0x27 ;
break;
case 1 :
V_75 = 0x25 ;
break;
case 2 :
V_75 = 0x22 ;
break;
case 3 :
V_75 = 0x21 ;
break;
}
F_1 ( V_2 , 0x8700 , V_75 ) ;
F_1 ( V_2 , 0x8702 , 0x81 ) ;
F_1 ( V_2 , 0x8500 , V_19 ) ;
F_19 ( V_10 , V_63 ) ;
F_22 ( V_10 ) ;
F_25 ( V_10 ) ;
F_1 ( V_2 , 0x8112 , 0x10 | 0x20 ) ;
return 0 ;
}
static void F_28 ( struct V_10 * V_10 )
{
struct V_26 * V_26 = (struct V_26 * ) V_10 ;
if ( V_26 -> V_37 == V_39 ) {
F_1 ( V_10 -> V_2 , 0x8112 , 0x0e ) ;
F_1 ( V_10 -> V_2 , 0x8114 , 0x08 ) ;
} else {
F_1 ( V_10 -> V_2 , 0x8112 , 0x20 ) ;
}
}
static void F_29 ( struct V_10 * V_10 )
{
struct V_26 * V_26 = (struct V_26 * ) V_10 ;
int V_76 ;
int V_77 ;
int V_78 ;
T_2 V_79 , V_80 , V_81 , V_82 ;
int V_83 ;
T_2 V_84 = 110 ;
T_2 V_85 = 20 ;
T_2 V_86 = 4 ;
if ( V_26 -> V_70 < 0 )
return;
if ( -- V_26 -> V_70 >= 0 )
return;
V_26 -> V_70 = V_71 ;
switch ( V_26 -> V_37 ) {
case V_66 :
F_7 ( V_10 , 0x8621 , 1 ) ;
V_80 = V_10 -> V_15 [ 0 ] ;
F_7 ( V_10 , 0x8622 , 1 ) ;
V_79 = V_10 -> V_15 [ 0 ] ;
F_7 ( V_10 , 0x8623 , 1 ) ;
V_82 = V_10 -> V_15 [ 0 ] ;
F_7 ( V_10 , 0x8624 , 1 ) ;
V_81 = V_10 -> V_15 [ 0 ] ;
V_83 = ( 77 * V_79 + 75 * ( V_80 + V_81 ) + 29 * V_82 ) >> 8 ;
if ( V_83 < V_84 - V_85 ||
V_83 > V_84 + V_85 ) {
V_76 = F_12 ( V_10 , 0x09 , 0x10 ) ;
V_77 = 0x0800 ;
V_76 = V_76 & 0x07ff ;
V_78 = F_12 ( V_10 , 0x35 , 0x10 ) ;
V_76 += ( V_84 - V_83 ) >> V_86 ;
V_78 += ( V_84 - V_83 ) / 50 ;
if ( V_78 > 0x3f )
V_78 = 0x3f ;
else if ( V_78 < 3 )
V_78 = 3 ;
F_10 ( V_10 , V_78 , 0x35 ) ;
if ( V_76 > 0x0256 )
V_76 = 0x0256 ;
else if ( V_76 < 3 )
V_76 = 3 ;
F_10 ( V_10 , V_76 | V_77 , 0x09 ) ;
}
break;
}
}
static void F_30 ( struct V_10 * V_10 ,
T_3 * V_11 ,
int V_16 )
{
struct V_26 * V_26 = (struct V_26 * ) V_10 ;
V_16 -- ;
switch ( * V_11 ++ ) {
case 0 :
F_31 ( V_10 , V_87 , NULL , 0 ) ;
if ( V_16 < 2 ) {
F_4 ( V_88 , L_6 ) ;
V_10 -> V_89 = V_90 ;
return;
}
#if F_32 ( V_91 ) || F_32 ( V_92 )
if ( V_11 [ 0 ] & 0x20 ) {
F_33 ( V_10 -> V_93 , V_94 , 1 ) ;
F_34 ( V_10 -> V_93 ) ;
F_33 ( V_10 -> V_93 , V_94 , 0 ) ;
F_34 ( V_10 -> V_93 ) ;
}
#endif
if ( V_11 [ 1 ] & 0x10 ) {
F_31 ( V_10 , V_95 , V_11 , V_16 ) ;
} else {
if ( V_26 -> V_37 == V_39 ) {
V_11 += 20 ;
V_16 -= 20 ;
} else {
V_11 += 16 ;
V_16 -= 16 ;
}
F_31 ( V_10 , V_95 , V_11 , V_16 ) ;
}
return;
case 0xff :
return;
}
F_31 ( V_10 , V_96 , V_11 , V_16 ) ;
}
static int F_35 ( struct V_10 * V_10 , T_4 V_97 )
{
struct V_26 * V_26 = (struct V_26 * ) V_10 ;
V_26 -> V_44 = V_97 ;
if ( V_10 -> V_98 )
F_20 ( V_10 ) ;
return 0 ;
}
static int F_36 ( struct V_10 * V_10 , T_4 * V_97 )
{
struct V_26 * V_26 = (struct V_26 * ) V_10 ;
* V_97 = V_26 -> V_44 ;
return 0 ;
}
static int F_37 ( struct V_10 * V_10 , T_4 V_97 )
{
struct V_26 * V_26 = (struct V_26 * ) V_10 ;
V_26 -> V_46 = V_97 ;
if ( V_10 -> V_98 )
F_22 ( V_10 ) ;
return 0 ;
}
static int F_38 ( struct V_10 * V_10 , T_4 * V_97 )
{
struct V_26 * V_26 = (struct V_26 * ) V_10 ;
* V_97 = V_26 -> V_46 ;
return 0 ;
}
static int F_39 ( struct V_10 * V_10 , T_4 V_97 )
{
struct V_26 * V_26 = (struct V_26 * ) V_10 ;
V_26 -> V_52 = V_97 ;
if ( V_10 -> V_98 )
F_25 ( V_10 ) ;
return 0 ;
}
static int F_40 ( struct V_10 * V_10 , T_4 * V_97 )
{
struct V_26 * V_26 = (struct V_26 * ) V_10 ;
* V_97 = V_26 -> V_52 ;
return 0 ;
}
static int F_41 ( struct V_10 * V_10 , T_4 V_97 )
{
struct V_26 * V_26 = (struct V_26 * ) V_10 ;
V_26 -> V_48 = V_97 ;
if ( V_10 -> V_98 )
F_21 ( V_10 ) ;
return 0 ;
}
static int F_42 ( struct V_10 * V_10 , T_4 * V_97 )
{
struct V_26 * V_26 = (struct V_26 * ) V_10 ;
* V_97 = V_26 -> V_48 ;
return 0 ;
}
static int F_43 ( struct V_10 * V_10 , T_4 V_97 )
{
struct V_26 * V_26 = (struct V_26 * ) V_10 ;
V_26 -> V_50 = V_97 ;
if ( V_10 -> V_98 )
F_23 ( V_10 ) ;
return 0 ;
}
static int F_44 ( struct V_10 * V_10 , T_4 * V_97 )
{
struct V_26 * V_26 = (struct V_26 * ) V_10 ;
* V_97 = V_26 -> V_50 ;
return 0 ;
}
static int F_45 ( struct V_10 * V_10 , T_4 V_97 )
{
struct V_26 * V_26 = (struct V_26 * ) V_10 ;
V_26 -> V_54 = V_97 ;
if ( V_10 -> V_98 )
F_24 ( V_10 ) ;
return 0 ;
}
static int F_46 ( struct V_10 * V_10 , T_4 * V_97 )
{
struct V_26 * V_26 = (struct V_26 * ) V_10 ;
* V_97 = V_26 -> V_54 ;
return 0 ;
}
static int F_47 ( struct V_99 * V_100 ,
const struct V_24 * V_25 )
{
return F_48 ( V_100 , V_25 ,
V_101 [ V_25 -> V_38 ] ,
sizeof( struct V_26 ) ,
V_102 ) ;
}
static int T_5 F_49 ( void )
{
return F_50 ( & V_103 ) ;
}
static void T_6 F_51 ( void )
{
F_52 ( & V_103 ) ;
}
