static void F_1 ( struct V_1 * V_1 , T_1 V_2 , T_2 V_3 )
{
struct V_4 * V_5 = V_1 -> V_6 ;
int V_7 ;
if ( V_1 -> V_8 < 0 )
return;
V_1 -> V_9 [ 0 ] = V_3 ;
V_7 = F_2 ( V_5 ,
F_3 ( V_5 , 0 ) ,
0x01 ,
V_10 | V_11 | V_12 ,
0x00 , V_2 , V_1 -> V_9 , 1 , V_13 ) ;
if ( V_7 < 0 ) {
F_4 ( L_1 , V_7 ) ;
V_1 -> V_8 = V_7 ;
}
}
static void F_5 ( struct V_1 * V_1 , T_1 V_2 , T_2 V_3 )
{
F_6 ( V_14 , L_2 , V_2 , V_3 ) ;
F_1 ( V_1 , V_2 , V_3 ) ;
}
static T_2 F_7 ( struct V_1 * V_1 , T_1 V_2 )
{
struct V_4 * V_5 = V_1 -> V_6 ;
int V_7 ;
if ( V_1 -> V_8 < 0 )
return 0 ;
V_7 = F_2 ( V_5 ,
F_8 ( V_5 , 0 ) ,
0x01 ,
V_15 | V_11 | V_12 ,
0x00 , V_2 , V_1 -> V_9 , 1 , V_13 ) ;
F_6 ( V_16 , L_3 , V_2 , V_1 -> V_9 [ 0 ] ) ;
if ( V_7 < 0 ) {
F_4 ( L_4 , V_7 ) ;
V_1 -> V_8 = V_7 ;
}
return V_1 -> V_9 [ 0 ] ;
}
static int F_9 ( struct V_1 * V_1 )
{
T_2 V_17 ;
int V_18 ;
for ( V_18 = 0 ; V_18 < 5 ; V_18 ++ ) {
V_17 = F_7 ( V_1 , V_19 ) ;
switch ( V_17 ) {
case 0x00 :
return 1 ;
case 0x04 :
return 0 ;
case 0x03 :
break;
default:
F_6 ( V_16 | V_14 ,
L_5 ,
V_17 , V_18 + 1 ) ;
}
}
return 0 ;
}
static void F_10 ( struct V_1 * V_1 , T_2 V_2 , T_2 V_3 )
{
F_6 ( V_14 , L_6 , V_2 , V_3 ) ;
F_1 ( V_1 , V_20 , V_2 ) ;
F_1 ( V_1 , V_21 , V_3 ) ;
F_1 ( V_1 , V_22 , V_23 ) ;
if ( ! F_9 ( V_1 ) )
F_4 ( L_7 ) ;
}
static T_2 F_11 ( struct V_1 * V_1 , T_1 V_2 )
{
F_5 ( V_1 , V_20 , V_2 ) ;
F_5 ( V_1 , V_22 , V_24 ) ;
if ( ! F_9 ( V_1 ) )
F_4 ( L_8 ) ;
F_5 ( V_1 , V_22 , V_25 ) ;
if ( ! F_9 ( V_1 ) )
F_4 ( L_9 ) ;
return F_7 ( V_1 , V_26 ) ;
}
static void F_12 ( struct V_1 * V_1 , int V_27 )
{
T_2 V_17 ;
F_6 ( V_28 , L_10 , V_27 ) ;
V_17 = F_7 ( V_1 , 0x21 ) ;
V_17 |= 0x80 ;
F_5 ( V_1 , 0x21 , V_17 ) ;
V_17 = F_7 ( V_1 , 0x23 ) ;
if ( V_27 )
V_17 |= 0x80 ;
else
V_17 &= ~ 0x80 ;
F_5 ( V_1 , 0x23 , V_17 ) ;
if ( ! V_27 ) {
V_17 = F_7 ( V_1 , 0x21 ) ;
V_17 &= ~ 0x80 ;
F_5 ( V_1 , 0x21 , V_17 ) ;
}
}
static void F_13 ( struct V_1 * V_1 )
{
struct V_29 * V_29 = (struct V_29 * ) V_1 ;
T_2 V_3 ;
T_3 V_30 ;
if ( V_1 -> V_31 & ( 1 << V_32 ) )
return;
if ( V_29 -> V_33 == V_34 ) {
V_30 = V_29 -> V_35 [ V_32 ] . V_3 ;
V_3 = 0x76 ;
V_3 += V_30 ;
F_10 ( V_1 , 0x24 , V_3 ) ;
V_3 = 0x6a ;
V_3 += V_30 ;
F_10 ( V_1 , 0x25 , V_3 ) ;
if ( V_30 < - 40 )
V_3 = 0x71 ;
else if ( V_30 < 20 )
V_3 = 0x94 ;
else
V_3 = 0xe6 ;
F_10 ( V_1 , 0x26 , V_3 ) ;
} else {
V_3 = V_29 -> V_35 [ V_32 ] . V_3 ;
if ( V_3 < 8 )
V_3 = 15 - V_3 ;
else
V_3 = V_3 - 8 ;
F_10 ( V_1 , 0x55 ,
0x0f | ( V_3 << 4 ) ) ;
}
}
static void F_14 ( struct V_1 * V_1 )
{
struct V_29 * V_29 = (struct V_29 * ) V_1 ;
if ( V_1 -> V_31 & ( 1 << V_36 ) )
return;
F_10 ( V_1 , 0x56 ,
V_29 -> V_35 [ V_36 ] . V_3 << 4 ) ;
}
static void F_15 ( struct V_1 * V_1 )
{
struct V_29 * V_29 = (struct V_29 * ) V_1 ;
T_2 V_3 ;
if ( V_1 -> V_31 & ( 1 << V_37 ) )
return;
V_3 = F_11 ( V_1 , 0x13 ) ;
F_10 ( V_1 , 0xff , 0x00 ) ;
if ( V_29 -> V_35 [ V_37 ] . V_3 )
V_3 |= 0x05 ;
else
V_3 &= 0xfa ;
F_10 ( V_1 , 0x13 , V_3 ) ;
}
static void F_16 ( struct V_1 * V_1 )
{
struct V_29 * V_29 = (struct V_29 * ) V_1 ;
T_2 V_3 ;
static const T_2 V_38 [ 4 ] = { 0x00 , 0x25 , 0x38 , 0x5e } ;
if ( V_1 -> V_31 & ( 1 << V_39 ) )
return;
F_10 ( V_1 , 0x10 ,
V_38 [ V_29 -> V_35 [ V_39 ] . V_3 ] ) ;
V_3 = F_11 ( V_1 , 0x13 ) ;
F_10 ( V_1 , 0xff , 0x00 ) ;
F_10 ( V_1 , 0x13 , V_3 ) ;
V_3 = F_11 ( V_1 , 0xa1 ) ;
F_10 ( V_1 , 0xff , 0x00 ) ;
F_10 ( V_1 , 0xa1 , V_3 & 0xe0 ) ;
}
static void F_17 ( struct V_1 * V_1 )
{
struct V_29 * V_29 = (struct V_29 * ) V_1 ;
T_3 V_3 ;
if ( V_1 -> V_31 & ( 1 << V_40 ) )
return;
V_3 = V_29 -> V_35 [ V_40 ] . V_3 ;
if ( V_3 < 0 ) {
V_3 = F_11 ( V_1 , 0x42 ) ;
F_10 ( V_1 , 0xff , 0x00 ) ;
F_10 ( V_1 , 0x42 , V_3 | 0x40 ) ;
return;
}
if ( V_3 != 0 )
V_3 = 1 << ( V_3 - 1 ) ;
F_10 ( V_1 , 0x3f ,
V_3 ) ;
V_3 = F_11 ( V_1 , 0x42 ) ;
F_10 ( V_1 , 0xff , 0x00 ) ;
F_10 ( V_1 , 0x42 , V_3 & 0xbf ) ;
}
static void F_18 ( struct V_1 * V_1 )
{
struct V_29 * V_29 = (struct V_29 * ) V_1 ;
T_2 V_41 , V_42 , V_43 ;
static const T_2 V_44 [ 5 ] [ 2 ] = {
{ 0x14 , 0x38 } ,
{ 0x1e , 0x54 } ,
{ 0x28 , 0x70 } ,
{ 0x32 , 0x8c } ,
{ 0x48 , 0x90 }
} ;
if ( V_1 -> V_31 & ( 1 << V_45 ) )
return;
V_41 = V_44 [ V_29 -> V_35 [ V_45 ] . V_3 ] [ 0 ] ;
V_42 = V_44 [ V_29 -> V_35 [ V_45 ] . V_3 ] [ 1 ] ;
V_43 = V_41 + V_42 ;
F_10 ( V_1 , 0x4f , V_43 ) ;
F_10 ( V_1 , 0x50 , V_43 ) ;
F_10 ( V_1 , 0x51 , 0x00 ) ;
F_10 ( V_1 , 0x52 , V_41 ) ;
F_10 ( V_1 , 0x53 , V_42 ) ;
F_10 ( V_1 , 0x54 , V_43 ) ;
F_10 ( V_1 , 0x58 , 0x1a ) ;
V_41 = F_11 ( V_1 , 0x41 ) ;
F_10 ( V_1 , 0xff , 0x00 ) ;
F_10 ( V_1 , 0x41 , V_41 ) ;
}
static void F_19 ( struct V_1 * V_1 )
{
struct V_29 * V_29 = (struct V_29 * ) V_1 ;
T_2 V_3 ;
if ( V_1 -> V_31 & ( 1 << V_46 ) )
return;
V_3 = F_11 ( V_1 , 0x13 ) ;
F_10 ( V_1 , 0xff , 0x00 ) ;
if ( V_29 -> V_35 [ V_46 ] . V_3 == 0 ) {
F_10 ( V_1 , 0x13 , V_3 & 0xdf ) ;
return;
}
F_10 ( V_1 , 0x13 , V_3 | 0x20 ) ;
V_3 = F_11 ( V_1 , 0x42 ) ;
F_10 ( V_1 , 0xff , 0x00 ) ;
if ( V_29 -> V_35 [ V_46 ] . V_3 == 1 )
V_3 |= 0x01 ;
else
V_3 &= 0xfe ;
F_10 ( V_1 , 0x42 , V_3 ) ;
}
static int F_20 ( struct V_1 * V_1 ,
const struct V_47 * V_48 )
{
struct V_29 * V_29 = (struct V_29 * ) V_1 ;
V_1 -> V_49 . V_35 = V_29 -> V_35 ;
#if V_50 != 0
V_1 -> V_51 |= ( 1 << V_39 ) ;
#endif
return 0 ;
}
static int F_21 ( struct V_1 * V_1 )
{
struct V_29 * V_29 = (struct V_29 * ) V_1 ;
T_1 V_52 ;
F_5 ( V_1 , 0xe7 , 0x3a ) ;
F_5 ( V_1 , 0xe0 , 0x08 ) ;
F_22 ( 100 ) ;
F_5 ( V_1 , V_53 , 0x60 ) ;
F_10 ( V_1 , 0x12 , 0x80 ) ;
F_22 ( 10 ) ;
F_11 ( V_1 , 0x0a ) ;
V_52 = F_11 ( V_1 , 0x0a ) << 8 ;
F_11 ( V_1 , 0x0b ) ;
V_52 |= F_11 ( V_1 , 0x0b ) ;
F_6 ( V_54 , L_11 , V_52 ) ;
if ( ( V_52 & 0xfff0 ) == 0x9650 ) {
V_29 -> V_33 = V_55 ;
V_1 -> V_49 . V_56 = V_57 ;
V_1 -> V_49 . V_58 = F_23 ( V_57 ) ;
F_24 ( V_1 , V_59 ,
F_23 ( V_59 ) ) ;
F_25 ( V_1 , V_60 ,
F_23 ( V_60 ) ) ;
F_24 ( V_1 , V_61 ,
F_23 ( V_61 ) ) ;
F_25 ( V_1 , V_62 ,
F_23 ( V_62 ) ) ;
F_5 ( V_1 , 0xe0 , 0x00 ) ;
F_5 ( V_1 , 0xe0 , 0x01 ) ;
F_12 ( V_1 , 0 ) ;
F_5 ( V_1 , 0xe0 , 0x00 ) ;
} else if ( ( V_52 & 0xfff0 ) == 0x9710 ) {
const char * V_63 ;
int V_64 ;
V_29 -> V_33 = V_65 ;
V_1 -> V_49 . V_56 = V_66 ;
V_1 -> V_49 . V_58 = F_23 ( V_66 ) ;
V_1 -> V_31 = ( 1 << V_67 ) - 1 ;
V_1 -> V_49 . V_68 = 1 ;
V_1 -> V_49 . V_69 = 16384 ;
V_1 -> V_49 . V_70 = 2 ;
F_25 ( V_1 , V_71 ,
F_23 ( V_71 ) ) ;
F_5 ( V_1 , 0x1c , 0x00 ) ;
F_5 ( V_1 , 0x1d , 0x00 ) ;
V_63 = F_26 ( & V_1 -> V_72 ) ;
V_64 = strlen ( V_63 ) - 1 ;
if ( V_63 [ V_64 ] == '0' )
F_5 ( V_1 , 0x56 , 0x1f ) ;
else
F_5 ( V_1 , 0x56 , 0x17 ) ;
} else if ( ( V_52 & 0xfff0 ) == 0x5620 ) {
V_29 -> V_33 = V_34 ;
V_1 -> V_31 = ( 1 << V_36 ) |
( 1 << V_37 ) |
( 1 << V_39 ) |
( 1 << V_40 ) |
( 1 << V_45 ) |
( 1 << V_46 ) ;
V_29 -> V_35 [ V_32 ] . V_73 = - 90 ;
V_29 -> V_35 [ V_32 ] . V_74 = 90 ;
V_29 -> V_35 [ V_32 ] . V_75 = 0 ;
V_1 -> V_49 . V_56 = V_76 ;
V_1 -> V_49 . V_58 = F_23 ( V_76 ) ;
F_24 ( V_1 , V_77 ,
F_23 ( V_77 ) ) ;
F_25 ( V_1 , V_78 ,
F_23 ( V_78 ) ) ;
F_5 ( V_1 , 0xe0 , 0x00 ) ;
} else {
F_27 ( L_12 , V_52 ) ;
return - V_79 ;
}
return V_1 -> V_8 ;
}
static int F_28 ( struct V_1 * V_1 )
{
struct V_29 * V_29 = (struct V_29 * ) V_1 ;
if ( V_29 -> V_33 == V_65 )
return V_1 -> V_8 ;
else if ( V_29 -> V_33 == V_34 ) {
F_13 ( V_1 ) ;
return V_1 -> V_8 ;
}
switch ( V_1 -> V_80 ) {
case V_81 :
F_25 ( V_1 , V_82 ,
F_23 ( V_82 ) ) ;
F_24 ( V_1 , V_83 ,
F_23 ( V_83 ) ) ;
F_25 ( V_1 , V_84 ,
F_23 ( V_84 ) ) ;
break;
case V_85 :
F_25 ( V_1 , V_82 ,
F_23 ( V_82 ) ) ;
F_24 ( V_1 , V_86 ,
F_23 ( V_86 ) ) ;
F_25 ( V_1 , V_87 ,
F_23 ( V_87 ) ) ;
break;
case V_88 :
F_25 ( V_1 , V_89 ,
F_23 ( V_89 ) ) ;
F_24 ( V_1 , V_90 ,
F_23 ( V_90 ) ) ;
F_25 ( V_1 , V_91 ,
F_23 ( V_91 ) ) ;
break;
case V_92 :
F_25 ( V_1 , V_93 ,
F_23 ( V_93 ) ) ;
F_24 ( V_1 , V_94 ,
F_23 ( V_94 ) ) ;
F_25 ( V_1 , V_91 ,
F_23 ( V_91 ) ) ;
break;
default:
F_25 ( V_1 , V_95 ,
F_23 ( V_95 ) ) ;
F_24 ( V_1 , V_96 ,
F_23 ( V_96 ) ) ;
F_25 ( V_1 , V_97 ,
F_23 ( V_97 ) ) ;
break;
}
F_19 ( V_1 ) ;
F_15 ( V_1 ) ;
F_13 ( V_1 ) ;
F_14 ( V_1 ) ;
F_16 ( V_1 ) ;
F_17 ( V_1 ) ;
F_18 ( V_1 ) ;
F_5 ( V_1 , 0xe0 , 0x00 ) ;
F_5 ( V_1 , 0xe0 , 0x00 ) ;
F_12 ( V_1 , 1 ) ;
return V_1 -> V_8 ;
}
static void F_29 ( struct V_1 * V_1 )
{
F_5 ( V_1 , 0xe0 , 0x01 ) ;
F_12 ( V_1 , 0 ) ;
F_5 ( V_1 , 0xe0 , 0x00 ) ;
}
static void F_30 ( struct V_1 * V_1 ,
T_2 * V_17 , int V_98 )
{
struct V_29 * V_29 = (struct V_29 * ) V_1 ;
T_4 V_99 ;
T_2 V_100 ;
int V_101 = V_98 ;
int V_102 ;
V_102 = V_1 -> V_49 . V_68 ? 2048 : 2040 ;
do {
V_98 = V_73 ( V_101 , V_102 ) ;
if ( V_17 [ 0 ] != 12 || V_98 < 12 ) {
F_6 ( V_103 , L_13 ) ;
goto V_104;
}
if ( V_17 [ 1 ] & V_105 ) {
F_6 ( V_103 , L_14 ) ;
goto V_104;
}
if ( ! ( V_17 [ 1 ] & V_106 ) ) {
F_6 ( V_103 , L_15 ) ;
goto V_104;
}
V_99 = ( V_17 [ 5 ] << 24 ) | ( V_17 [ 4 ] << 16 )
| ( V_17 [ 3 ] << 8 ) | V_17 [ 2 ] ;
V_100 = V_17 [ 1 ] & V_107 ;
if ( V_99 != V_29 -> V_108 || V_100 != V_29 -> V_109 ) {
if ( V_1 -> V_110 == V_111 )
F_31 ( V_1 , V_112 ,
NULL , 0 ) ;
V_29 -> V_108 = V_99 ;
V_29 -> V_109 = V_100 ;
F_31 ( V_1 , V_113 ,
V_17 + 12 , V_98 - 12 ) ;
} else if ( V_17 [ 1 ] & V_114 ) {
V_29 -> V_108 = 0 ;
F_31 ( V_1 , V_112 ,
V_17 + 12 , V_98 - 12 ) ;
} else {
F_31 ( V_1 , V_111 ,
V_17 + 12 , V_98 - 12 ) ;
}
goto V_115;
V_104:
V_1 -> V_110 = V_116 ;
V_115:
V_101 -= V_98 ;
V_17 += V_98 ;
} while ( V_101 > 0 );
}
static int F_32 ( struct V_1 * V_1 ,
struct V_117 * V_118 )
{
switch ( V_118 -> V_48 ) {
case V_119 :
switch ( V_118 -> V_120 ) {
case 0 :
strcpy ( ( char * ) V_118 -> V_121 , L_16 ) ;
return 0 ;
case 1 :
strcpy ( ( char * ) V_118 -> V_121 , L_17 ) ;
return 0 ;
case 2 :
strcpy ( ( char * ) V_118 -> V_121 , L_18 ) ;
return 0 ;
}
break;
}
return - V_79 ;
}
static int F_33 ( struct V_122 * V_123 , const struct V_47 * V_48 )
{
return F_34 ( V_123 , V_48 , & V_124 , sizeof( struct V_29 ) ,
V_125 ) ;
}
