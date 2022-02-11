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
V_27 -> V_36 = 1 ;
V_26 -> V_37 = V_25 -> V_38 ;
if ( V_26 -> V_37 == V_39 ) {
V_27 -> V_40 = V_41 ;
V_27 -> V_42 = F_16 ( V_41 ) ;
} else {
V_27 -> V_40 = V_43 ;
V_27 -> V_42 = F_16 ( V_43 ) ;
}
V_26 -> V_44 = V_45 ;
return 0 ;
}
static int F_17 ( struct V_10 * V_10 )
{
F_4 ( V_46 , L_4 ) ;
F_13 ( V_10 ) ;
return 0 ;
}
static int F_18 ( struct V_10 * V_10 )
{
F_4 ( V_46 , L_5 ) ;
F_6 ( V_10 , V_47 ) ;
F_11 ( 200 ) ;
F_6 ( V_10 , V_48 ) ;
F_19 ( V_10 , V_49 ) ;
F_6 ( V_10 , V_50 ) ;
F_19 ( V_10 , V_51 ) ;
F_1 ( V_10 -> V_2 , 0x8112 , 0x30 ) ;
return 0 ;
}
static void F_20 ( struct V_10 * V_10 , T_3 V_52 )
{
struct V_26 * V_26 = (struct V_26 * ) V_10 ;
struct V_1 * V_2 = V_10 -> V_2 ;
T_1 V_17 ;
if ( V_26 -> V_37 == V_39 )
V_17 = 0x8610 ;
else
V_17 = 0x8611 ;
F_1 ( V_2 , V_17 + 0 , V_52 ) ;
F_1 ( V_2 , V_17 + 1 , V_52 ) ;
F_1 ( V_2 , V_17 + 2 , V_52 ) ;
F_1 ( V_2 , V_17 + 3 , V_52 ) ;
}
static void F_21 ( struct V_10 * V_10 , T_3 V_53 , T_3 V_54 )
{
struct V_26 * V_26 = (struct V_26 * ) V_10 ;
struct V_1 * V_2 = V_10 -> V_2 ;
T_2 V_55 , V_56 ;
T_1 V_17 ;
V_56 = 0x20 + V_53 * 3 / 8 ;
V_55 = 0x90 - V_53 * 5 / 8 ;
if ( V_26 -> V_37 == V_39 ) {
V_17 = 0x8614 ;
} else {
V_17 = 0x8651 ;
V_56 += V_54 - 0x20 ;
V_55 += V_54 - 0x20 ;
F_1 ( V_2 , 0x8652 , V_54 + 0x20 ) ;
F_1 ( V_2 , 0x8654 , V_54 + 0x20 ) ;
}
F_1 ( V_2 , V_17 , V_56 ) ;
F_1 ( V_2 , V_17 + 2 , V_55 ) ;
}
static void F_22 ( struct V_10 * V_10 , T_3 V_52 )
{
int V_12 , V_57 = 0 ;
int V_58 [] = { 0 , 450 , 550 , 625 , V_59 } ;
for ( V_12 = 0 ; V_12 < F_16 ( V_58 ) - 1 ; V_12 ++ ) {
if ( V_52 <= V_58 [ V_12 + 1 ] ) {
V_57 = V_52 - V_58 [ V_12 ] ;
if ( V_12 )
V_57 += 300 ;
V_57 |= V_12 << 11 ;
break;
}
}
V_10 -> V_15 [ 0 ] = V_57 ;
V_10 -> V_15 [ 1 ] = V_57 >> 8 ;
F_9 ( V_10 , 0x8309 , 2 ) ;
}
static void F_23 ( struct V_10 * V_10 , T_3 V_52 )
{
if ( V_52 < 64 )
V_10 -> V_15 [ 0 ] = V_52 ;
else if ( V_52 < 128 )
V_10 -> V_15 [ 0 ] = ( V_52 / 2 ) | 0x40 ;
else
V_10 -> V_15 [ 0 ] = ( V_52 / 4 ) | 0xc0 ;
V_10 -> V_15 [ 1 ] = 0 ;
F_9 ( V_10 , 0x8335 , 2 ) ;
}
static void F_24 ( struct V_10 * V_10 , T_3 V_52 )
{
struct V_26 * V_26 = (struct V_26 * ) V_10 ;
if ( V_52 )
V_26 -> V_60 = V_61 ;
else
V_26 -> V_60 = - 1 ;
}
static int F_25 ( struct V_10 * V_10 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
int V_19 ;
static const T_2 V_62 [ 8 ] =
{ 0x92 , 0x30 , 0x20 , 0x00 , 0x0c , 0x00 , 0x00 , 0x00 } ;
V_19 = V_10 -> V_27 . V_40 [ ( int ) V_10 -> V_63 ] . V_64 ;
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
memcpy ( V_10 -> V_15 , V_62 , 8 ) ;
F_9 ( V_10 , 0x8391 , 8 ) ;
F_9 ( V_10 , 0x8390 , 8 ) ;
F_1 ( V_10 -> V_2 , 0x8114 , 0x00 ) ;
return 0 ;
}
static int F_26 ( struct V_10 * V_10 )
{
struct V_26 * V_26 = (struct V_26 * ) V_10 ;
struct V_1 * V_2 = V_10 -> V_2 ;
int V_65 ;
int V_19 ;
F_6 ( V_10 , V_47 ) ;
F_11 ( 200 ) ;
F_6 ( V_10 , V_48 ) ;
F_19 ( V_10 , V_49 ) ;
V_19 = V_10 -> V_27 . V_40 [ ( int ) V_10 -> V_63 ] . V_64 ;
switch ( V_19 ) {
default:
case 0 :
V_65 = 0x27 ;
break;
case 1 :
V_65 = 0x25 ;
break;
case 2 :
V_65 = 0x22 ;
break;
case 3 :
V_65 = 0x21 ;
break;
}
F_1 ( V_2 , 0x8700 , V_65 ) ;
F_1 ( V_2 , 0x8702 , 0x81 ) ;
F_1 ( V_2 , 0x8500 , V_19 ) ;
F_19 ( V_10 , V_51 ) ;
F_21 ( V_10 , F_27 ( V_26 -> V_66 ) ,
F_27 ( V_26 -> V_54 ) ) ;
F_24 ( V_10 , F_27 ( V_26 -> V_67 ) ) ;
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
int V_68 ;
int V_69 ;
int V_70 ;
T_2 V_71 , V_72 , V_73 , V_74 ;
int V_75 ;
T_2 V_76 = 110 ;
T_2 V_77 = 20 ;
T_2 V_78 = 4 ;
if ( V_26 -> V_60 < 0 )
return;
if ( -- V_26 -> V_60 >= 0 )
return;
V_26 -> V_60 = V_61 ;
switch ( V_26 -> V_37 ) {
case V_79 :
F_7 ( V_10 , 0x8621 , 1 ) ;
V_72 = V_10 -> V_15 [ 0 ] ;
F_7 ( V_10 , 0x8622 , 1 ) ;
V_71 = V_10 -> V_15 [ 0 ] ;
F_7 ( V_10 , 0x8623 , 1 ) ;
V_74 = V_10 -> V_15 [ 0 ] ;
F_7 ( V_10 , 0x8624 , 1 ) ;
V_73 = V_10 -> V_15 [ 0 ] ;
V_75 = ( 77 * V_71 + 75 * ( V_72 + V_73 ) + 29 * V_74 ) >> 8 ;
if ( V_75 < V_76 - V_77 ||
V_75 > V_76 + V_77 ) {
V_68 = F_12 ( V_10 , 0x09 , 0x10 ) ;
V_69 = 0x0800 ;
V_68 = V_68 & 0x07ff ;
V_70 = F_12 ( V_10 , 0x35 , 0x10 ) ;
V_68 += ( V_76 - V_75 ) >> V_78 ;
V_70 += ( V_76 - V_75 ) / 50 ;
if ( V_70 > 0x3f )
V_70 = 0x3f ;
else if ( V_70 < 3 )
V_70 = 3 ;
F_10 ( V_10 , V_70 , 0x35 ) ;
if ( V_68 > 0x0256 )
V_68 = 0x0256 ;
else if ( V_68 < 3 )
V_68 = 3 ;
F_10 ( V_10 , V_68 | V_69 , 0x09 ) ;
}
break;
}
}
static void F_30 ( struct V_10 * V_10 ,
T_4 * V_11 ,
int V_16 )
{
struct V_26 * V_26 = (struct V_26 * ) V_10 ;
V_16 -- ;
switch ( * V_11 ++ ) {
case 0 :
F_31 ( V_10 , V_80 , NULL , 0 ) ;
if ( V_16 < 2 ) {
F_4 ( V_81 , L_6 ) ;
V_10 -> V_82 = V_83 ;
return;
}
#if F_32 ( V_84 )
if ( V_11 [ 0 ] & 0x20 ) {
F_33 ( V_10 -> V_85 , V_86 , 1 ) ;
F_34 ( V_10 -> V_85 ) ;
F_33 ( V_10 -> V_85 , V_86 , 0 ) ;
F_34 ( V_10 -> V_85 ) ;
}
#endif
if ( V_11 [ 1 ] & 0x10 ) {
F_31 ( V_10 , V_87 , V_11 , V_16 ) ;
} else {
if ( V_26 -> V_37 == V_39 ) {
V_11 += 20 ;
V_16 -= 20 ;
} else {
V_11 += 16 ;
V_16 -= 16 ;
}
F_31 ( V_10 , V_87 , V_11 , V_16 ) ;
}
return;
case 0xff :
return;
}
F_31 ( V_10 , V_88 , V_11 , V_16 ) ;
}
static int F_35 ( struct V_89 * V_90 )
{
struct V_10 * V_10 =
F_36 ( V_90 -> V_91 , struct V_10 , V_92 ) ;
struct V_26 * V_26 = (struct V_26 * ) V_10 ;
V_10 -> V_93 = 0 ;
if ( ! V_10 -> V_94 )
return 0 ;
switch ( V_90 -> V_25 ) {
case V_95 :
F_20 ( V_10 , V_90 -> V_52 ) ;
break;
case V_96 :
F_21 ( V_10 , V_26 -> V_66 -> V_52 , V_90 -> V_52 ) ;
break;
case V_97 :
F_21 ( V_10 , V_90 -> V_52 , 0 ) ;
break;
case V_98 :
F_22 ( V_10 , V_90 -> V_52 ) ;
break;
case V_99 :
F_23 ( V_10 , V_90 -> V_52 ) ;
break;
case V_100 :
F_24 ( V_10 , V_90 -> V_52 ) ;
break;
}
return V_10 -> V_93 ;
}
static int F_37 ( struct V_10 * V_10 )
{
struct V_101 * V_102 = & V_10 -> V_92 ;
V_10 -> V_103 . V_92 = V_102 ;
F_38 ( V_102 , 3 ) ;
F_39 ( V_102 , & V_104 ,
V_97 , 1 , 0x7f , 1 , 0x40 ) ;
F_39 ( V_102 , & V_104 ,
V_95 , - 128 , 127 , 1 , 0 ) ;
F_39 ( V_102 , & V_104 ,
V_98 , 1 , V_59 , 1 , 700 ) ;
F_39 ( V_102 , & V_104 ,
V_99 , 0 , 255 , 1 , 63 ) ;
if ( V_102 -> error ) {
F_5 ( L_7 ) ;
return V_102 -> error ;
}
return 0 ;
}
static int F_40 ( struct V_10 * V_10 )
{
struct V_26 * V_26 = (struct V_26 * ) V_10 ;
struct V_101 * V_102 = & V_10 -> V_92 ;
V_10 -> V_103 . V_92 = V_102 ;
F_38 ( V_102 , 4 ) ;
V_26 -> V_54 = F_39 ( V_102 , & V_104 ,
V_96 , 0 , 0x3f , 1 , 0x20 ) ;
V_26 -> V_66 = F_39 ( V_102 , & V_104 ,
V_97 , 1 , 0x7f , 1 , 0x40 ) ;
F_39 ( V_102 , & V_104 ,
V_95 , 0 , 0x3f , 1 , 0x20 ) ;
V_26 -> V_67 = F_39 ( V_102 , & V_104 ,
V_100 , 0 , 1 , 1 , 1 ) ;
if ( V_102 -> error ) {
F_5 ( L_7 ) ;
return V_102 -> error ;
}
F_41 ( 2 , & V_26 -> V_54 ) ;
return 0 ;
}
static int F_42 ( struct V_105 * V_106 ,
const struct V_24 * V_25 )
{
return F_43 ( V_106 , V_25 ,
V_107 [ V_25 -> V_38 ] ,
sizeof( struct V_26 ) ,
V_108 ) ;
}
