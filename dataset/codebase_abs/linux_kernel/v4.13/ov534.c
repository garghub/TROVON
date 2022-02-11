static void F_1 ( struct V_1 * V_1 , T_1 V_2 , T_2 V_3 )
{
struct V_4 * V_5 = V_1 -> V_6 ;
int V_7 ;
if ( V_1 -> V_8 < 0 )
return;
F_2 ( V_9 , L_1 , V_2 , V_3 ) ;
V_1 -> V_10 [ 0 ] = V_3 ;
V_7 = F_3 ( V_5 ,
F_4 ( V_5 , 0 ) ,
0x01 ,
V_11 | V_12 | V_13 ,
0x00 , V_2 , V_1 -> V_10 , 1 , V_14 ) ;
if ( V_7 < 0 ) {
F_5 ( L_2 , V_7 ) ;
V_1 -> V_8 = V_7 ;
}
}
static T_2 F_6 ( struct V_1 * V_1 , T_1 V_2 )
{
struct V_4 * V_5 = V_1 -> V_6 ;
int V_7 ;
if ( V_1 -> V_8 < 0 )
return 0 ;
V_7 = F_3 ( V_5 ,
F_7 ( V_5 , 0 ) ,
0x01 ,
V_15 | V_12 | V_13 ,
0x00 , V_2 , V_1 -> V_10 , 1 , V_14 ) ;
F_2 ( V_16 , L_3 , V_2 , V_1 -> V_10 [ 0 ] ) ;
if ( V_7 < 0 ) {
F_5 ( L_4 , V_7 ) ;
V_1 -> V_8 = V_7 ;
}
return V_1 -> V_10 [ 0 ] ;
}
static void F_8 ( struct V_1 * V_1 , int V_17 )
{
T_2 V_18 ;
F_2 ( V_19 , L_5 , V_17 ) ;
V_18 = F_6 ( V_1 , 0x21 ) ;
V_18 |= 0x80 ;
F_1 ( V_1 , 0x21 , V_18 ) ;
V_18 = F_6 ( V_1 , 0x23 ) ;
if ( V_17 )
V_18 |= 0x80 ;
else
V_18 &= ~ 0x80 ;
F_1 ( V_1 , 0x23 , V_18 ) ;
if ( ! V_17 ) {
V_18 = F_6 ( V_1 , 0x21 ) ;
V_18 &= ~ 0x80 ;
F_1 ( V_1 , 0x21 , V_18 ) ;
}
}
static int F_9 ( struct V_1 * V_1 )
{
T_2 V_18 ;
int V_20 ;
for ( V_20 = 0 ; V_20 < 5 ; V_20 ++ ) {
F_10 ( 10 ) ;
V_18 = F_6 ( V_1 , V_21 ) ;
switch ( V_18 ) {
case 0x00 :
return 1 ;
case 0x04 :
return 0 ;
case 0x03 :
break;
default:
F_11 ( L_6 ,
V_18 , V_20 + 1 ) ;
}
}
return 0 ;
}
static void F_12 ( struct V_1 * V_1 , T_2 V_2 , T_2 V_3 )
{
F_2 ( V_9 , L_7 , V_2 , V_3 ) ;
F_1 ( V_1 , V_22 , V_2 ) ;
F_1 ( V_1 , V_23 , V_3 ) ;
F_1 ( V_1 , V_24 , V_25 ) ;
if ( ! F_9 ( V_1 ) ) {
F_5 ( L_8 ) ;
V_1 -> V_8 = - V_26 ;
}
}
static T_2 F_13 ( struct V_1 * V_1 , T_1 V_2 )
{
F_1 ( V_1 , V_22 , V_2 ) ;
F_1 ( V_1 , V_24 , V_27 ) ;
if ( ! F_9 ( V_1 ) )
F_5 ( L_9 ) ;
F_1 ( V_1 , V_24 , V_28 ) ;
if ( ! F_9 ( V_1 ) )
F_5 ( L_10 ) ;
return F_6 ( V_1 , V_29 ) ;
}
static void F_14 ( struct V_1 * V_1 )
{
struct V_30 * V_30 = (struct V_30 * ) V_1 ;
int V_20 ;
struct V_31 {
T_2 V_32 ;
T_2 V_33 ;
T_2 V_34 ;
T_2 V_35 ;
};
const struct V_31 * V_36 ;
static const struct V_31 V_37 [] = {
{ 60 , 0x01 , 0xc1 , 0x04 } ,
{ 50 , 0x01 , 0x41 , 0x02 } ,
{ 40 , 0x02 , 0xc1 , 0x04 } ,
{ 30 , 0x04 , 0x81 , 0x02 } ,
{ 15 , 0x03 , 0x41 , 0x04 } ,
} ;
static const struct V_31 V_38 [] = {
{ 187 , 0x01 , 0x81 , 0x02 } ,
{ 150 , 0x01 , 0xc1 , 0x04 } ,
{ 137 , 0x02 , 0xc1 , 0x02 } ,
{ 125 , 0x02 , 0x81 , 0x02 } ,
{ 100 , 0x02 , 0xc1 , 0x04 } ,
{ 75 , 0x03 , 0xc1 , 0x04 } ,
{ 60 , 0x04 , 0xc1 , 0x04 } ,
{ 50 , 0x02 , 0x41 , 0x04 } ,
{ 37 , 0x03 , 0x41 , 0x04 } ,
{ 30 , 0x04 , 0x41 , 0x04 } ,
} ;
if ( V_30 -> V_39 != V_40 )
return;
if ( V_1 -> V_41 . V_42 [ V_1 -> V_43 ] . V_44 == 0 ) {
V_36 = V_37 ;
V_20 = F_15 ( V_37 ) ;
} else {
V_36 = V_38 ;
V_20 = F_15 ( V_38 ) ;
}
while ( -- V_20 > 0 ) {
if ( V_30 -> V_45 >= V_36 -> V_32 )
break;
V_36 ++ ;
}
F_12 ( V_1 , 0x11 , V_36 -> V_33 ) ;
F_12 ( V_1 , 0x0d , V_36 -> V_34 ) ;
F_1 ( V_1 , 0xe5 , V_36 -> V_35 ) ;
F_2 ( V_46 , L_11 , V_36 -> V_32 ) ;
}
static void F_16 ( struct V_1 * V_1 , T_3 V_3 )
{
struct V_30 * V_30 = (struct V_30 * ) V_1 ;
if ( V_30 -> V_39 == V_47 ) {
} else {
T_4 V_48 ;
T_4 V_49 ;
V_48 = F_17 ( V_3 ) * 0x80 / 0x7fff ;
V_49 = F_18 ( V_3 ) * 0x80 / 0x7fff ;
if ( V_48 < 0 ) {
F_12 ( V_1 , 0xab ,
F_13 ( V_1 , 0xab ) | 0x2 ) ;
V_48 = - V_48 ;
} else {
F_12 ( V_1 , 0xab ,
F_13 ( V_1 , 0xab ) & ~ 0x2 ) ;
}
F_12 ( V_1 , 0xa9 , ( T_2 ) V_49 ) ;
F_12 ( V_1 , 0xaa , ( T_2 ) V_48 ) ;
}
}
static void F_19 ( struct V_1 * V_1 , T_3 V_3 )
{
struct V_30 * V_30 = (struct V_30 * ) V_1 ;
if ( V_30 -> V_39 == V_47 ) {
int V_20 ;
static T_2 V_50 [] [ 6 ] = {
{ 0x42 , 0x42 , 0x00 , 0x11 , 0x30 , 0x41 } ,
{ 0x52 , 0x52 , 0x00 , 0x16 , 0x3c , 0x52 } ,
{ 0x66 , 0x66 , 0x00 , 0x1b , 0x4b , 0x66 } ,
{ 0x80 , 0x80 , 0x00 , 0x22 , 0x5e , 0x80 } ,
{ 0x9a , 0x9a , 0x00 , 0x29 , 0x71 , 0x9a } ,
{ 0xb8 , 0xb8 , 0x00 , 0x31 , 0x87 , 0xb8 } ,
{ 0xdd , 0xdd , 0x00 , 0x3b , 0xa2 , 0xdd } ,
} ;
for ( V_20 = 0 ; V_20 < F_15 ( V_50 [ 0 ] ) ; V_20 ++ )
F_12 ( V_1 , 0x4f + V_20 , V_50 [ V_3 ] [ V_20 ] ) ;
} else {
F_12 ( V_1 , 0xa7 , V_3 ) ;
F_12 ( V_1 , 0xa8 , V_3 ) ;
}
}
static void F_20 ( struct V_1 * V_1 , T_3 V_3 )
{
struct V_30 * V_30 = (struct V_30 * ) V_1 ;
if ( V_30 -> V_39 == V_47 ) {
if ( V_3 < 0 )
V_3 = 0x80 - V_3 ;
F_12 ( V_1 , 0x55 , V_3 ) ;
} else {
F_12 ( V_1 , 0x9b , V_3 ) ;
}
}
static void F_21 ( struct V_1 * V_1 , T_3 V_3 )
{
struct V_30 * V_30 = (struct V_30 * ) V_1 ;
if ( V_30 -> V_39 == V_47 )
F_12 ( V_1 , 0x56 , V_3 ) ;
else
F_12 ( V_1 , 0x9c , V_3 ) ;
}
static void F_22 ( struct V_1 * V_1 , T_3 V_3 )
{
switch ( V_3 & 0x30 ) {
case 0x00 :
V_3 &= 0x0f ;
break;
case 0x10 :
V_3 &= 0x0f ;
V_3 |= 0x30 ;
break;
case 0x20 :
V_3 &= 0x0f ;
V_3 |= 0x70 ;
break;
default:
V_3 &= 0x0f ;
V_3 |= 0xf0 ;
break;
}
F_12 ( V_1 , 0x00 , V_3 ) ;
}
static T_3 F_23 ( struct V_1 * V_1 )
{
return F_13 ( V_1 , 0x00 ) ;
}
static void F_24 ( struct V_1 * V_1 , T_3 V_3 )
{
struct V_30 * V_30 = (struct V_30 * ) V_1 ;
if ( V_30 -> V_39 == V_47 ) {
F_12 ( V_1 , 0x10 , V_3 ) ;
} else {
F_12 ( V_1 , 0x08 , V_3 >> 7 ) ;
F_12 ( V_1 , 0x10 , V_3 << 1 ) ;
}
}
static T_3 F_25 ( struct V_1 * V_1 )
{
struct V_30 * V_30 = (struct V_30 * ) V_1 ;
if ( V_30 -> V_39 == V_47 ) {
return F_13 ( V_1 , 0x10 ) ;
} else {
T_2 V_51 = F_13 ( V_1 , 0x08 ) ;
T_2 V_52 = F_13 ( V_1 , 0x10 ) ;
return ( V_51 << 8 | V_52 ) >> 1 ;
}
}
static void F_26 ( struct V_1 * V_1 , T_3 V_3 )
{
if ( V_3 ) {
F_12 ( V_1 , 0x13 ,
F_13 ( V_1 , 0x13 ) | 0x04 ) ;
F_12 ( V_1 , 0x64 ,
F_13 ( V_1 , 0x64 ) | 0x03 ) ;
} else {
F_12 ( V_1 , 0x13 ,
F_13 ( V_1 , 0x13 ) & ~ 0x04 ) ;
F_12 ( V_1 , 0x64 ,
F_13 ( V_1 , 0x64 ) & ~ 0x03 ) ;
}
}
static void F_27 ( struct V_1 * V_1 , T_3 V_3 )
{
struct V_30 * V_30 = (struct V_30 * ) V_1 ;
if ( V_3 ) {
F_12 ( V_1 , 0x13 ,
F_13 ( V_1 , 0x13 ) | 0x02 ) ;
if ( V_30 -> V_39 == V_40 )
F_12 ( V_1 , 0x63 ,
F_13 ( V_1 , 0x63 ) | 0xc0 ) ;
} else {
F_12 ( V_1 , 0x13 ,
F_13 ( V_1 , 0x13 ) & ~ 0x02 ) ;
if ( V_30 -> V_39 == V_40 )
F_12 ( V_1 , 0x63 ,
F_13 ( V_1 , 0x63 ) & ~ 0xc0 ) ;
}
}
static void F_28 ( struct V_1 * V_1 , T_3 V_3 )
{
struct V_30 * V_30 = (struct V_30 * ) V_1 ;
T_2 V_18 ;
V_18 = V_30 -> V_39 == V_47 ?
0x05 :
0x01 ;
switch ( V_3 ) {
case V_53 :
F_12 ( V_1 , 0x13 ,
F_13 ( V_1 , 0x13 ) | V_18 ) ;
break;
case V_54 :
F_12 ( V_1 , 0x13 ,
F_13 ( V_1 , 0x13 ) & ~ V_18 ) ;
break;
}
}
static void F_29 ( struct V_1 * V_1 , T_3 V_3 )
{
F_12 ( V_1 , 0x91 , V_3 ) ;
F_12 ( V_1 , 0x8e , V_3 ) ;
}
static void F_30 ( struct V_1 * V_1 , T_3 V_55 , T_3 V_56 )
{
struct V_30 * V_30 = (struct V_30 * ) V_1 ;
T_2 V_3 ;
if ( V_30 -> V_39 == V_47 ) {
V_3 = F_13 ( V_1 , 0x1e ) ;
V_3 &= ~ 0x30 ;
if ( V_55 )
V_3 |= 0x20 ;
if ( V_56 )
V_3 |= 0x10 ;
F_12 ( V_1 , 0x1e , V_3 ) ;
} else {
V_3 = F_13 ( V_1 , 0x0c ) ;
V_3 &= ~ 0xc0 ;
if ( V_55 == 0 )
V_3 |= 0x40 ;
if ( V_56 == 0 )
V_3 |= 0x80 ;
F_12 ( V_1 , 0x0c , V_3 ) ;
}
}
static void F_31 ( struct V_1 * V_1 , T_3 V_3 )
{
struct V_30 * V_30 = (struct V_30 * ) V_1 ;
V_3 = V_3 ? 0x9e : 0x00 ;
if ( V_30 -> V_39 == V_47 ) {
F_12 ( V_1 , 0x2a , 0x00 ) ;
if ( V_3 )
V_3 = 0x9d ;
}
F_12 ( V_1 , 0x2b , V_3 ) ;
}
static int F_32 ( struct V_1 * V_1 ,
const struct V_57 * V_58 )
{
struct V_30 * V_30 = (struct V_30 * ) V_1 ;
struct V_41 * V_41 ;
V_41 = & V_1 -> V_41 ;
V_41 -> V_42 = V_59 ;
V_41 -> V_60 = F_15 ( V_59 ) ;
V_30 -> V_45 = V_61 ;
return 0 ;
}
static int F_33 ( struct V_62 * V_63 )
{
struct V_30 * V_30 = F_34 ( V_63 -> V_64 , struct V_30 , V_65 ) ;
struct V_1 * V_1 = & V_30 -> V_1 ;
switch ( V_63 -> V_58 ) {
case V_66 :
V_1 -> V_8 = 0 ;
if ( V_63 -> V_3 && V_30 -> V_67 && V_1 -> V_68 )
V_30 -> V_67 -> V_3 = F_23 ( V_1 ) ;
return V_1 -> V_8 ;
case V_69 :
V_1 -> V_8 = 0 ;
if ( V_63 -> V_3 == V_53 && V_30 -> V_70 &&
V_1 -> V_68 )
V_30 -> V_70 -> V_3 = F_25 ( V_1 ) ;
return V_1 -> V_8 ;
}
return - V_71 ;
}
static int F_35 ( struct V_62 * V_63 )
{
struct V_30 * V_30 = F_34 ( V_63 -> V_64 , struct V_30 , V_65 ) ;
struct V_1 * V_1 = & V_30 -> V_1 ;
V_1 -> V_8 = 0 ;
if ( ! V_1 -> V_68 )
return 0 ;
switch ( V_63 -> V_58 ) {
case V_72 :
F_16 ( V_1 , V_63 -> V_3 ) ;
break;
case V_73 :
F_19 ( V_1 , V_63 -> V_3 ) ;
break;
case V_74 :
F_20 ( V_1 , V_63 -> V_3 ) ;
break;
case V_75 :
F_21 ( V_1 , V_63 -> V_3 ) ;
break;
case V_66 :
F_26 ( V_1 , V_63 -> V_3 ) ;
if ( ! V_1 -> V_8 && ! V_63 -> V_3 && V_30 -> V_67 )
F_22 ( V_1 , V_30 -> V_67 -> V_3 ) ;
break;
case V_76 :
F_27 ( V_1 , V_63 -> V_3 ) ;
break;
case V_69 :
F_28 ( V_1 , V_63 -> V_3 ) ;
if ( ! V_1 -> V_8 && V_63 -> V_3 == V_54 &&
V_30 -> V_70 )
F_24 ( V_1 , V_30 -> V_70 -> V_3 ) ;
break;
case V_77 :
F_29 ( V_1 , V_63 -> V_3 ) ;
break;
case V_78 :
F_30 ( V_1 , V_63 -> V_3 , V_30 -> V_56 -> V_3 ) ;
break;
case V_79 :
F_30 ( V_1 , V_30 -> V_55 -> V_3 , V_63 -> V_3 ) ;
break;
case V_80 :
F_31 ( V_1 , V_63 -> V_3 ) ;
break;
}
return V_1 -> V_8 ;
}
static int F_36 ( struct V_1 * V_1 )
{
struct V_30 * V_30 = (struct V_30 * ) V_1 ;
struct V_81 * V_82 = & V_30 -> V_65 ;
int V_83 ;
int V_84 ;
int V_85 ;
int V_86 ;
int V_87 ;
int V_88 ;
int V_89 ;
int V_90 ;
int V_91 ;
int V_92 ;
int V_93 ;
int V_94 ;
if ( V_30 -> V_39 == V_47 ) {
V_83 = 0 ,
V_84 = 6 ,
V_85 = 3 ,
V_86 = - 127 ;
V_87 = 127 ;
V_88 = 0 ;
V_89 = 0x80 ;
V_90 = 0x40 ;
V_91 = 0x08 ;
V_92 = 0x60 ;
V_93 = 0x13 ;
V_94 = 1 ;
} else {
V_83 = 0 ,
V_84 = 255 ,
V_85 = 64 ,
V_86 = 0 ;
V_87 = 255 ;
V_88 = 0 ;
V_89 = 255 ;
V_90 = 32 ;
V_91 = 0 ;
V_92 = 255 ;
V_93 = 120 ;
V_94 = 0 ;
}
V_1 -> V_95 . V_65 = V_82 ;
F_37 ( V_82 , 13 ) ;
if ( V_30 -> V_39 == V_40 )
V_30 -> V_96 = F_38 ( V_82 , & V_97 ,
V_72 , - 90 , 90 , 1 , 0 ) ;
V_30 -> V_98 = F_38 ( V_82 , & V_97 ,
V_73 , V_83 , V_84 , 1 ,
V_85 ) ;
V_30 -> V_99 = F_38 ( V_82 , & V_97 ,
V_74 , V_86 , V_87 , 1 ,
V_88 ) ;
V_30 -> V_100 = F_38 ( V_82 , & V_97 ,
V_75 , 0 , V_89 , 1 , V_90 ) ;
if ( V_30 -> V_39 == V_40 ) {
V_30 -> V_101 = F_38 ( V_82 , & V_97 ,
V_66 , 0 , 1 , 1 , 1 ) ;
V_30 -> V_67 = F_38 ( V_82 , & V_97 ,
V_102 , 0 , 63 , 1 , 20 ) ;
}
V_30 -> V_103 = F_39 ( V_82 , & V_97 ,
V_69 ,
V_54 , 0 ,
V_53 ) ;
V_30 -> V_70 = F_38 ( V_82 , & V_97 ,
V_104 , V_91 , V_92 , 1 ,
V_93 ) ;
V_30 -> V_105 = F_38 ( V_82 , & V_97 ,
V_76 , 0 , 1 , 1 , 1 ) ;
if ( V_30 -> V_39 == V_40 )
V_30 -> V_106 = F_38 ( V_82 , & V_97 ,
V_77 , 0 , 63 , 1 , 0 ) ;
V_30 -> V_55 = F_38 ( V_82 , & V_97 ,
V_78 , 0 , 1 , 1 , V_94 ) ;
V_30 -> V_56 = F_38 ( V_82 , & V_97 ,
V_79 , 0 , 1 , 1 , 0 ) ;
V_30 -> V_107 = F_39 ( V_82 , & V_97 ,
V_80 ,
V_108 , 0 ,
V_109 ) ;
if ( V_82 -> error ) {
F_5 ( L_12 ) ;
return V_82 -> error ;
}
if ( V_30 -> V_39 == V_40 )
F_40 ( 2 , & V_30 -> V_101 , 0 , true ) ;
F_40 ( 2 , & V_30 -> V_103 , V_54 ,
true ) ;
return 0 ;
}
static int F_41 ( struct V_1 * V_1 )
{
struct V_30 * V_30 = (struct V_30 * ) V_1 ;
T_1 V_110 ;
static const struct V_111 V_112 [ V_113 ] = {
[ V_47 ] = { V_114 , F_15 (bridge_init_767x) } ,
[ V_40 ] = { V_115 , F_15 (bridge_init_772x) } ,
} ;
static const struct V_111 V_116 [ V_113 ] = {
[ V_47 ] = { V_117 , F_15 (sensor_init_767x) } ,
[ V_40 ] = { V_118 , F_15 (sensor_init_772x) } ,
} ;
F_1 ( V_1 , 0xe7 , 0x3a ) ;
F_1 ( V_1 , 0xe0 , 0x08 ) ;
F_10 ( 100 ) ;
F_1 ( V_1 , V_119 , 0x42 ) ;
F_12 ( V_1 , 0x12 , 0x80 ) ;
F_10 ( 10 ) ;
F_13 ( V_1 , 0x0a ) ;
V_110 = F_13 ( V_1 , 0x0a ) << 8 ;
F_13 ( V_1 , 0x0b ) ;
V_110 |= F_13 ( V_1 , 0x0b ) ;
F_2 ( V_46 , L_13 , V_110 ) ;
if ( ( V_110 & 0xfff0 ) == 0x7670 ) {
V_30 -> V_39 = V_47 ;
V_1 -> V_41 . V_42 = V_120 ;
V_1 -> V_41 . V_60 = F_15 ( V_120 ) ;
} else {
V_30 -> V_39 = V_40 ;
V_1 -> V_41 . V_121 = 1 ;
V_1 -> V_41 . V_122 = 16384 ;
V_1 -> V_41 . V_123 = 2 ;
V_1 -> V_41 . V_124 = V_125 ;
}
F_42 ( V_1 , V_112 [ V_30 -> V_39 ] . V_3 ,
V_112 [ V_30 -> V_39 ] . V_126 ) ;
F_8 ( V_1 , 1 ) ;
F_43 ( V_1 , V_116 [ V_30 -> V_39 ] . V_3 ,
V_116 [ V_30 -> V_39 ] . V_126 ) ;
F_44 ( V_1 ) ;
return V_1 -> V_8 ;
}
static int F_45 ( struct V_1 * V_1 )
{
struct V_30 * V_30 = (struct V_30 * ) V_1 ;
int V_127 ;
static const struct V_111 V_128 [ V_113 ] [ 2 ] = {
[ V_47 ] = { { V_129 ,
F_15 (bridge_start_qvga_767x) } ,
{ V_130 ,
F_15 (bridge_start_vga_767x) } } ,
[ V_40 ] = { { V_131 ,
F_15 (bridge_start_qvga_772x) } ,
{ V_132 ,
F_15 (bridge_start_vga_772x) } } ,
} ;
static const struct V_111 V_133 [ V_113 ] [ 2 ] = {
[ V_47 ] = { { V_134 ,
F_15 (sensor_start_qvga_767x) } ,
{ V_135 ,
F_15 (sensor_start_vga_767x) } } ,
[ V_40 ] = { { V_136 ,
F_15 (sensor_start_qvga_772x) } ,
{ V_137 ,
F_15 (sensor_start_vga_772x) } } ,
} ;
if ( V_30 -> V_39 == V_47 )
F_12 ( V_1 , 0x1e , 0x04 ) ;
V_127 = V_1 -> V_43 ;
F_42 ( V_1 , V_128 [ V_30 -> V_39 ] [ V_127 ] . V_3 ,
V_128 [ V_30 -> V_39 ] [ V_127 ] . V_126 ) ;
F_43 ( V_1 , V_133 [ V_30 -> V_39 ] [ V_127 ] . V_3 ,
V_133 [ V_30 -> V_39 ] [ V_127 ] . V_126 ) ;
F_14 ( V_1 ) ;
if ( V_30 -> V_96 )
F_16 ( V_1 , F_46 ( V_30 -> V_96 ) ) ;
F_19 ( V_1 , F_46 ( V_30 -> V_98 ) ) ;
if ( V_30 -> V_101 )
F_26 ( V_1 , F_46 ( V_30 -> V_101 ) ) ;
F_27 ( V_1 , F_46 ( V_30 -> V_105 ) ) ;
F_28 ( V_1 , F_46 ( V_30 -> V_103 ) ) ;
if ( V_30 -> V_67 )
F_22 ( V_1 , F_46 ( V_30 -> V_67 ) ) ;
F_24 ( V_1 , F_46 ( V_30 -> V_70 ) ) ;
F_20 ( V_1 , F_46 ( V_30 -> V_99 ) ) ;
F_21 ( V_1 , F_46 ( V_30 -> V_100 ) ) ;
if ( V_30 -> V_106 )
F_29 ( V_1 , F_46 ( V_30 -> V_106 ) ) ;
F_30 ( V_1 , F_46 ( V_30 -> V_55 ) ,
F_46 ( V_30 -> V_56 ) ) ;
F_31 ( V_1 , F_46 ( V_30 -> V_107 ) ) ;
F_8 ( V_1 , 1 ) ;
F_1 ( V_1 , 0xe0 , 0x00 ) ;
return V_1 -> V_8 ;
}
static void F_44 ( struct V_1 * V_1 )
{
F_1 ( V_1 , 0xe0 , 0x09 ) ;
F_8 ( V_1 , 0 ) ;
}
static void F_47 ( struct V_1 * V_1 ,
T_2 * V_18 , int V_126 )
{
struct V_30 * V_30 = (struct V_30 * ) V_1 ;
T_5 V_138 ;
T_1 V_139 ;
int V_140 = V_126 ;
int V_141 ;
V_141 = V_1 -> V_41 . V_121 ? 2048 : 2040 ;
do {
V_126 = F_48 ( V_140 , V_141 ) ;
if ( V_18 [ 0 ] != 12 || V_126 < 12 ) {
F_2 ( V_142 , L_14 ) ;
goto V_143;
}
if ( V_18 [ 1 ] & V_144 ) {
F_2 ( V_142 , L_15 ) ;
goto V_143;
}
if ( ! ( V_18 [ 1 ] & V_145 ) ) {
F_2 ( V_142 , L_16 ) ;
goto V_143;
}
V_138 = ( V_18 [ 5 ] << 24 ) | ( V_18 [ 4 ] << 16 )
| ( V_18 [ 3 ] << 8 ) | V_18 [ 2 ] ;
V_139 = ( V_18 [ 1 ] & V_146 ) ? 1 : 0 ;
if ( V_138 != V_30 -> V_147 || V_139 != V_30 -> V_148 ) {
if ( V_1 -> V_149 == V_150 )
F_49 ( V_1 , V_151 ,
NULL , 0 ) ;
V_30 -> V_147 = V_138 ;
V_30 -> V_148 = V_139 ;
F_49 ( V_1 , V_152 ,
V_18 + 12 , V_126 - 12 ) ;
} else if ( V_18 [ 1 ] & V_153 ) {
V_30 -> V_147 = 0 ;
if ( V_1 -> V_154 . V_155 == V_156
&& V_1 -> V_157 + V_126 - 12 !=
V_1 -> V_154 . V_158 *
V_1 -> V_154 . V_159 * 2 ) {
F_2 ( V_142 , L_17 ) ;
goto V_143;
}
F_49 ( V_1 , V_151 ,
V_18 + 12 , V_126 - 12 ) ;
} else {
F_49 ( V_1 , V_150 ,
V_18 + 12 , V_126 - 12 ) ;
}
goto V_160;
V_143:
V_1 -> V_149 = V_161 ;
V_160:
V_140 -= V_126 ;
V_18 += V_126 ;
} while ( V_140 > 0 );
}
static void F_50 ( struct V_1 * V_1 ,
struct V_162 * V_163 )
{
struct V_164 * V_165 = & V_163 -> V_163 . V_166 ;
struct V_167 * V_168 = & V_165 -> V_169 ;
struct V_30 * V_30 = (struct V_30 * ) V_1 ;
V_165 -> V_170 |= V_171 ;
V_168 -> V_172 = 1 ;
V_168 -> V_173 = V_30 -> V_45 ;
}
static void F_51 ( struct V_1 * V_1 ,
struct V_162 * V_163 )
{
struct V_164 * V_165 = & V_163 -> V_163 . V_166 ;
struct V_167 * V_168 = & V_165 -> V_169 ;
struct V_30 * V_30 = (struct V_30 * ) V_1 ;
if ( V_168 -> V_172 == 0 || V_168 -> V_173 == 0 )
V_30 -> V_45 = V_61 ;
else
V_30 -> V_45 = V_168 -> V_173 / V_168 -> V_172 ;
if ( V_1 -> V_68 )
F_14 ( V_1 ) ;
V_168 -> V_172 = 1 ;
V_168 -> V_173 = V_30 -> V_45 ;
}
static int F_52 ( struct V_174 * V_175 , const struct V_57 * V_58 )
{
return F_53 ( V_175 , V_58 , & V_176 , sizeof( struct V_30 ) ,
V_177 ) ;
}
