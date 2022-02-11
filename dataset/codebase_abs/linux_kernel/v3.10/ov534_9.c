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
F_10 ( 10 ) ;
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
static void F_11 ( struct V_1 * V_1 , T_2 V_2 , T_2 V_3 )
{
F_6 ( V_14 , L_6 , V_2 , V_3 ) ;
F_1 ( V_1 , V_20 , V_2 ) ;
F_1 ( V_1 , V_21 , V_3 ) ;
F_1 ( V_1 , V_22 , V_23 ) ;
if ( ! F_9 ( V_1 ) )
F_4 ( L_7 ) ;
}
static T_2 F_12 ( struct V_1 * V_1 , T_1 V_2 )
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
static void F_13 ( struct V_1 * V_1 , int V_27 )
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
static void F_14 ( struct V_1 * V_1 , T_3 V_29 )
{
struct V_30 * V_30 = (struct V_30 * ) V_1 ;
T_2 V_3 ;
T_4 V_31 ;
if ( V_30 -> V_32 == V_33 ) {
V_31 = V_29 ;
V_3 = 0x76 ;
V_3 += V_31 ;
F_11 ( V_1 , 0x24 , V_3 ) ;
V_3 = 0x6a ;
V_3 += V_31 ;
F_11 ( V_1 , 0x25 , V_3 ) ;
if ( V_31 < - 40 )
V_3 = 0x71 ;
else if ( V_31 < 20 )
V_3 = 0x94 ;
else
V_3 = 0xe6 ;
F_11 ( V_1 , 0x26 , V_3 ) ;
} else {
V_3 = V_29 ;
if ( V_3 < 8 )
V_3 = 15 - V_3 ;
else
V_3 = V_3 - 8 ;
F_11 ( V_1 , 0x55 ,
0x0f | ( V_3 << 4 ) ) ;
}
}
static void F_15 ( struct V_1 * V_1 , T_3 V_3 )
{
F_11 ( V_1 , 0x56 ,
V_3 << 4 ) ;
}
static void F_16 ( struct V_1 * V_1 , T_3 V_34 )
{
T_2 V_3 ;
V_3 = F_12 ( V_1 , 0x13 ) ;
F_11 ( V_1 , 0xff , 0x00 ) ;
if ( V_34 )
V_3 |= 0x05 ;
else
V_3 &= 0xfa ;
F_11 ( V_1 , 0x13 , V_3 ) ;
}
static void F_17 ( struct V_1 * V_1 , T_3 V_35 )
{
static const T_2 V_36 [ 4 ] = { 0x00 , 0x25 , 0x38 , 0x5e } ;
T_2 V_3 ;
F_11 ( V_1 , 0x10 , V_36 [ V_35 ] ) ;
V_3 = F_12 ( V_1 , 0x13 ) ;
F_11 ( V_1 , 0xff , 0x00 ) ;
F_11 ( V_1 , 0x13 , V_3 ) ;
V_3 = F_12 ( V_1 , 0xa1 ) ;
F_11 ( V_1 , 0xff , 0x00 ) ;
F_11 ( V_1 , 0xa1 , V_3 & 0xe0 ) ;
}
static void F_18 ( struct V_1 * V_1 , T_3 V_3 )
{
if ( V_3 < 0 ) {
V_3 = F_12 ( V_1 , 0x42 ) ;
F_11 ( V_1 , 0xff , 0x00 ) ;
F_11 ( V_1 , 0x42 , V_3 | 0x40 ) ;
return;
}
if ( V_3 != 0 )
V_3 = 1 << ( V_3 - 1 ) ;
F_11 ( V_1 , 0x3f ,
V_3 ) ;
V_3 = F_12 ( V_1 , 0x42 ) ;
F_11 ( V_1 , 0xff , 0x00 ) ;
F_11 ( V_1 , 0x42 , V_3 & 0xbf ) ;
}
static void F_19 ( struct V_1 * V_1 , T_3 V_3 )
{
T_2 V_37 , V_38 , V_39 ;
static const T_2 V_40 [ 5 ] [ 2 ] = {
{ 0x14 , 0x38 } ,
{ 0x1e , 0x54 } ,
{ 0x28 , 0x70 } ,
{ 0x32 , 0x8c } ,
{ 0x48 , 0x90 }
} ;
V_37 = V_40 [ V_3 ] [ 0 ] ;
V_38 = V_40 [ V_3 ] [ 1 ] ;
V_39 = V_37 + V_38 ;
F_11 ( V_1 , 0x4f , V_39 ) ;
F_11 ( V_1 , 0x50 , V_39 ) ;
F_11 ( V_1 , 0x51 , 0x00 ) ;
F_11 ( V_1 , 0x52 , V_37 ) ;
F_11 ( V_1 , 0x53 , V_38 ) ;
F_11 ( V_1 , 0x54 , V_39 ) ;
F_11 ( V_1 , 0x58 , 0x1a ) ;
V_37 = F_12 ( V_1 , 0x41 ) ;
F_11 ( V_1 , 0xff , 0x00 ) ;
F_11 ( V_1 , 0x41 , V_37 ) ;
}
static void F_20 ( struct V_1 * V_1 , T_3 V_41 )
{
T_2 V_3 ;
V_3 = F_12 ( V_1 , 0x13 ) ;
F_11 ( V_1 , 0xff , 0x00 ) ;
if ( V_41 == 0 ) {
F_11 ( V_1 , 0x13 , V_3 & 0xdf ) ;
return;
}
F_11 ( V_1 , 0x13 , V_3 | 0x20 ) ;
V_3 = F_12 ( V_1 , 0x42 ) ;
F_11 ( V_1 , 0xff , 0x00 ) ;
if ( V_41 == 1 )
V_3 |= 0x01 ;
else
V_3 &= 0xfe ;
F_11 ( V_1 , 0x42 , V_3 ) ;
}
static int F_21 ( struct V_1 * V_1 ,
const struct V_42 * V_43 )
{
return 0 ;
}
static int F_22 ( struct V_1 * V_1 )
{
struct V_30 * V_30 = (struct V_30 * ) V_1 ;
T_1 V_44 ;
F_5 ( V_1 , 0xe7 , 0x3a ) ;
F_5 ( V_1 , 0xe0 , 0x08 ) ;
F_10 ( 100 ) ;
F_5 ( V_1 , V_45 , 0x60 ) ;
F_11 ( V_1 , 0x12 , 0x80 ) ;
F_10 ( 10 ) ;
F_12 ( V_1 , 0x0a ) ;
V_44 = F_12 ( V_1 , 0x0a ) << 8 ;
F_12 ( V_1 , 0x0b ) ;
V_44 |= F_12 ( V_1 , 0x0b ) ;
F_6 ( V_46 , L_11 , V_44 ) ;
if ( ( V_44 & 0xfff0 ) == 0x9650 ) {
V_30 -> V_32 = V_47 ;
V_1 -> V_48 . V_49 = V_50 ;
V_1 -> V_48 . V_51 = F_23 ( V_50 ) ;
F_24 ( V_1 , V_52 ,
F_23 ( V_52 ) ) ;
F_25 ( V_1 , V_53 ,
F_23 ( V_53 ) ) ;
F_24 ( V_1 , V_54 ,
F_23 ( V_54 ) ) ;
F_25 ( V_1 , V_55 ,
F_23 ( V_55 ) ) ;
F_5 ( V_1 , 0xe0 , 0x00 ) ;
F_5 ( V_1 , 0xe0 , 0x01 ) ;
F_13 ( V_1 , 0 ) ;
F_5 ( V_1 , 0xe0 , 0x00 ) ;
} else if ( ( V_44 & 0xfff0 ) == 0x9710 ) {
const char * V_56 ;
int V_57 ;
V_30 -> V_32 = V_58 ;
V_1 -> V_48 . V_49 = V_59 ;
V_1 -> V_48 . V_51 = F_23 ( V_59 ) ;
V_1 -> V_48 . V_60 = 1 ;
V_1 -> V_48 . V_61 = 16384 ;
V_1 -> V_48 . V_62 = 2 ;
F_25 ( V_1 , V_63 ,
F_23 ( V_63 ) ) ;
F_5 ( V_1 , 0x1c , 0x00 ) ;
F_5 ( V_1 , 0x1d , 0x00 ) ;
V_56 = F_26 ( & V_1 -> V_64 ) ;
V_57 = strlen ( V_56 ) - 1 ;
if ( V_56 [ V_57 ] == '0' )
F_5 ( V_1 , 0x56 , 0x1f ) ;
else
F_5 ( V_1 , 0x56 , 0x17 ) ;
} else if ( ( V_44 & 0xfff0 ) == 0x5620 ) {
V_30 -> V_32 = V_33 ;
V_1 -> V_48 . V_49 = V_65 ;
V_1 -> V_48 . V_51 = F_23 ( V_65 ) ;
F_24 ( V_1 , V_66 ,
F_23 ( V_66 ) ) ;
F_25 ( V_1 , V_67 ,
F_23 ( V_67 ) ) ;
F_5 ( V_1 , 0xe0 , 0x00 ) ;
} else {
F_4 ( L_12 , V_44 ) ;
return - V_68 ;
}
return V_1 -> V_8 ;
}
static int F_27 ( struct V_1 * V_1 )
{
struct V_30 * V_30 = (struct V_30 * ) V_1 ;
if ( V_30 -> V_32 == V_58 )
return V_1 -> V_8 ;
if ( V_30 -> V_32 == V_33 )
return V_1 -> V_8 ;
switch ( V_1 -> V_69 ) {
case V_70 :
F_25 ( V_1 , V_71 ,
F_23 ( V_71 ) ) ;
F_24 ( V_1 , V_72 ,
F_23 ( V_72 ) ) ;
F_25 ( V_1 , V_73 ,
F_23 ( V_73 ) ) ;
break;
case V_74 :
F_25 ( V_1 , V_71 ,
F_23 ( V_71 ) ) ;
F_24 ( V_1 , V_75 ,
F_23 ( V_75 ) ) ;
F_25 ( V_1 , V_76 ,
F_23 ( V_76 ) ) ;
break;
case V_77 :
F_25 ( V_1 , V_78 ,
F_23 ( V_78 ) ) ;
F_24 ( V_1 , V_79 ,
F_23 ( V_79 ) ) ;
F_25 ( V_1 , V_80 ,
F_23 ( V_80 ) ) ;
break;
case V_81 :
F_25 ( V_1 , V_82 ,
F_23 ( V_82 ) ) ;
F_24 ( V_1 , V_83 ,
F_23 ( V_83 ) ) ;
F_25 ( V_1 , V_80 ,
F_23 ( V_80 ) ) ;
break;
default:
F_25 ( V_1 , V_84 ,
F_23 ( V_84 ) ) ;
F_24 ( V_1 , V_85 ,
F_23 ( V_85 ) ) ;
F_25 ( V_1 , V_86 ,
F_23 ( V_86 ) ) ;
break;
}
F_5 ( V_1 , 0xe0 , 0x00 ) ;
F_5 ( V_1 , 0xe0 , 0x00 ) ;
F_13 ( V_1 , 1 ) ;
return V_1 -> V_8 ;
}
static void F_28 ( struct V_1 * V_1 )
{
F_5 ( V_1 , 0xe0 , 0x01 ) ;
F_13 ( V_1 , 0 ) ;
F_5 ( V_1 , 0xe0 , 0x00 ) ;
}
static void F_29 ( struct V_1 * V_1 ,
T_2 * V_17 , int V_87 )
{
struct V_30 * V_30 = (struct V_30 * ) V_1 ;
T_5 V_88 ;
T_2 V_89 ;
int V_90 = V_87 ;
int V_91 ;
V_91 = V_1 -> V_48 . V_60 ? 2048 : 2040 ;
do {
V_87 = F_30 ( V_90 , V_91 ) ;
if ( V_17 [ 0 ] != 12 || V_87 < 12 ) {
F_6 ( V_92 , L_13 ) ;
goto V_93;
}
if ( V_17 [ 1 ] & V_94 ) {
F_6 ( V_92 , L_14 ) ;
goto V_93;
}
if ( ! ( V_17 [ 1 ] & V_95 ) ) {
F_6 ( V_92 , L_15 ) ;
goto V_93;
}
V_88 = ( V_17 [ 5 ] << 24 ) | ( V_17 [ 4 ] << 16 )
| ( V_17 [ 3 ] << 8 ) | V_17 [ 2 ] ;
V_89 = V_17 [ 1 ] & V_96 ;
if ( V_88 != V_30 -> V_97 || V_89 != V_30 -> V_98 ) {
if ( V_1 -> V_99 == V_100 )
F_31 ( V_1 , V_101 ,
NULL , 0 ) ;
V_30 -> V_97 = V_88 ;
V_30 -> V_98 = V_89 ;
F_31 ( V_1 , V_102 ,
V_17 + 12 , V_87 - 12 ) ;
} else if ( V_17 [ 1 ] & V_103 ) {
V_30 -> V_97 = 0 ;
F_31 ( V_1 , V_101 ,
V_17 + 12 , V_87 - 12 ) ;
} else {
F_31 ( V_1 , V_100 ,
V_17 + 12 , V_87 - 12 ) ;
}
goto V_104;
V_93:
V_1 -> V_99 = V_105 ;
V_104:
V_90 -= V_87 ;
V_17 += V_87 ;
} while ( V_90 > 0 );
}
static int F_32 ( struct V_106 * V_107 )
{
struct V_1 * V_1 =
F_33 ( V_107 -> V_108 , struct V_1 , V_109 ) ;
V_1 -> V_8 = 0 ;
if ( ! V_1 -> V_110 )
return 0 ;
switch ( V_107 -> V_43 ) {
case V_111 :
F_14 ( V_1 , V_107 -> V_3 ) ;
break;
case V_112 :
F_15 ( V_1 , V_107 -> V_3 ) ;
break;
case V_113 :
F_19 ( V_1 , V_107 -> V_3 ) ;
break;
case V_114 :
F_20 ( V_1 , V_107 -> V_3 ) ;
break;
case V_115 :
F_18 ( V_1 , V_107 -> V_3 ) ;
break;
case V_116 :
if ( V_107 -> V_117 )
F_16 ( V_1 , V_107 -> V_3 ) ;
if ( ! V_107 -> V_3 && V_1 -> V_35 -> V_117 )
F_17 ( V_1 , V_1 -> V_35 -> V_3 ) ;
break;
}
return V_1 -> V_8 ;
}
static int F_34 ( struct V_1 * V_1 )
{
struct V_30 * V_30 = (struct V_30 * ) V_1 ;
struct V_118 * V_119 = & V_1 -> V_109 ;
if ( V_30 -> V_32 == V_58 )
return 0 ;
V_1 -> V_64 . V_109 = V_119 ;
F_35 ( V_119 , 7 ) ;
if ( V_30 -> V_32 == V_33 ) {
F_36 ( V_119 , & V_120 ,
V_111 , - 90 , 90 , 1 , 0 ) ;
} else {
F_36 ( V_119 , & V_120 ,
V_111 , 0 , 15 , 1 , 7 ) ;
F_36 ( V_119 , & V_120 ,
V_112 , 0 , 15 , 1 , 3 ) ;
F_36 ( V_119 , & V_120 ,
V_113 , 0 , 4 , 1 , 2 ) ;
F_36 ( V_119 , & V_120 ,
V_115 , - 1 , 4 , 1 , - 1 ) ;
V_1 -> V_34 = F_36 ( V_119 , & V_120 ,
V_116 , 0 , 1 , 1 , 1 ) ;
V_1 -> V_35 = F_36 ( V_119 , & V_120 ,
V_121 , 0 , 3 , 1 , 0 ) ;
F_37 ( V_119 , & V_120 ,
V_114 ,
V_122 , 0 , 0 ) ;
F_38 ( 3 , & V_1 -> V_34 , 0 , false ) ;
}
if ( V_119 -> error ) {
F_4 ( L_16 ) ;
return V_119 -> error ;
}
return 0 ;
}
static int F_39 ( struct V_123 * V_124 , const struct V_42 * V_43 )
{
return F_40 ( V_124 , V_43 , & V_125 , sizeof( struct V_30 ) ,
V_126 ) ;
}
