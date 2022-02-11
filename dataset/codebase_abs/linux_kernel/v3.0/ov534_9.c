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
V_3 = V_29 -> V_30 ;
if ( V_3 < 8 )
V_3 = 15 - V_3 ;
else
V_3 = V_3 - 8 ;
F_10 ( V_1 , 0x55 ,
0x0f | ( V_3 << 4 ) ) ;
}
static void F_14 ( struct V_1 * V_1 )
{
struct V_29 * V_29 = (struct V_29 * ) V_1 ;
F_10 ( V_1 , 0x56 ,
V_29 -> V_31 << 4 ) ;
}
static void F_15 ( struct V_1 * V_1 )
{
struct V_29 * V_29 = (struct V_29 * ) V_1 ;
T_2 V_3 ;
V_3 = F_11 ( V_1 , 0x13 ) ;
F_10 ( V_1 , 0xff , 0x00 ) ;
if ( V_29 -> V_32 )
V_3 |= 0x05 ;
else
V_3 &= 0xfa ;
F_10 ( V_1 , 0x13 , V_3 ) ;
}
static void F_16 ( struct V_1 * V_1 )
{
struct V_29 * V_29 = (struct V_29 * ) V_1 ;
T_2 V_3 ;
static const T_2 V_33 [ 4 ] = { 0x00 , 0x25 , 0x38 , 0x5e } ;
F_10 ( V_1 , 0x10 ,
V_33 [ V_29 -> V_34 ] ) ;
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
V_3 = V_29 -> V_35 ;
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
T_2 V_36 , V_37 , V_38 ;
static const T_2 V_39 [ 5 ] [ 2 ] = {
{ 0x14 , 0x38 } ,
{ 0x1e , 0x54 } ,
{ 0x28 , 0x70 } ,
{ 0x32 , 0x8c } ,
{ 0x48 , 0x90 }
} ;
V_36 = V_39 [ V_29 -> V_40 ] [ 0 ] ;
V_37 = V_39 [ V_29 -> V_40 ] [ 1 ] ;
V_38 = V_36 + V_37 ;
F_10 ( V_1 , 0x4f , V_38 ) ;
F_10 ( V_1 , 0x50 , V_38 ) ;
F_10 ( V_1 , 0x51 , 0x00 ) ;
F_10 ( V_1 , 0x52 , V_36 ) ;
F_10 ( V_1 , 0x53 , V_37 ) ;
F_10 ( V_1 , 0x54 , V_38 ) ;
F_10 ( V_1 , 0x58 , 0x1a ) ;
V_36 = F_11 ( V_1 , 0x41 ) ;
F_10 ( V_1 , 0xff , 0x00 ) ;
F_10 ( V_1 , 0x41 , V_36 ) ;
}
static void F_19 ( struct V_1 * V_1 )
{
struct V_29 * V_29 = (struct V_29 * ) V_1 ;
T_2 V_3 ;
V_3 = F_11 ( V_1 , 0x13 ) ;
F_10 ( V_1 , 0xff , 0x00 ) ;
if ( V_29 -> V_41 == 0 ) {
F_10 ( V_1 , 0x13 , V_3 & 0xdf ) ;
return;
}
F_10 ( V_1 , 0x13 , V_3 | 0x20 ) ;
V_3 = F_11 ( V_1 , 0x42 ) ;
F_10 ( V_1 , 0xff , 0x00 ) ;
if ( V_29 -> V_41 == 1 )
V_3 |= 0x01 ;
else
V_3 &= 0xfe ;
F_10 ( V_1 , 0x42 , V_3 ) ;
}
static int F_20 ( struct V_1 * V_1 ,
const struct V_42 * V_43 )
{
struct V_29 * V_29 = (struct V_29 * ) V_1 ;
struct V_44 * V_44 ;
V_44 = & V_1 -> V_44 ;
V_44 -> V_45 = V_46 ;
V_44 -> V_47 = F_21 ( V_46 ) ;
V_29 -> V_30 = V_48 ;
V_29 -> V_31 = V_49 ;
#if V_50 != 0
V_29 -> V_32 = V_50 ;
V_1 -> V_51 |= ( 1 << V_52 ) ;
#endif
#if V_53 != 0
V_29 -> V_34 = V_53 ;
#endif
#if V_54 != 0
V_29 -> V_35 = V_54 ;
#endif
V_29 -> V_40 = V_55 ;
V_29 -> V_41 = V_56 ;
return 0 ;
}
static int F_22 ( struct V_1 * V_1 )
{
T_1 V_57 ;
F_5 ( V_1 , 0xe7 , 0x3a ) ;
F_5 ( V_1 , 0xe0 , 0x08 ) ;
F_23 ( 100 ) ;
F_5 ( V_1 , V_58 , 0x60 ) ;
F_10 ( V_1 , 0x12 , 0x80 ) ;
F_23 ( 10 ) ;
F_11 ( V_1 , 0x0a ) ;
V_57 = F_11 ( V_1 , 0x0a ) << 8 ;
F_11 ( V_1 , 0x0b ) ;
V_57 |= F_11 ( V_1 , 0x0b ) ;
F_6 ( V_59 , L_11 , V_57 ) ;
F_24 ( V_1 , V_60 ,
F_21 ( V_60 ) ) ;
F_25 ( V_1 , V_61 ,
F_21 ( V_61 ) ) ;
F_24 ( V_1 , V_62 ,
F_21 ( V_62 ) ) ;
F_25 ( V_1 , V_63 ,
F_21 ( V_63 ) ) ;
F_5 ( V_1 , 0xe0 , 0x00 ) ;
F_5 ( V_1 , 0xe0 , 0x01 ) ;
F_12 ( V_1 , 0 ) ;
F_5 ( V_1 , 0xe0 , 0x00 ) ;
return V_1 -> V_8 ;
}
static int F_26 ( struct V_1 * V_1 )
{
switch ( V_1 -> V_64 ) {
case V_65 :
F_25 ( V_1 , V_66 ,
F_21 ( V_66 ) ) ;
F_24 ( V_1 , V_67 ,
F_21 ( V_67 ) ) ;
F_25 ( V_1 , V_68 ,
F_21 ( V_68 ) ) ;
break;
case V_69 :
F_25 ( V_1 , V_66 ,
F_21 ( V_66 ) ) ;
F_24 ( V_1 , V_70 ,
F_21 ( V_70 ) ) ;
F_25 ( V_1 , V_71 ,
F_21 ( V_71 ) ) ;
break;
case V_72 :
F_25 ( V_1 , V_73 ,
F_21 ( V_73 ) ) ;
F_24 ( V_1 , V_74 ,
F_21 ( V_74 ) ) ;
F_25 ( V_1 , V_75 ,
F_21 ( V_75 ) ) ;
break;
case V_76 :
F_25 ( V_1 , V_77 ,
F_21 ( V_77 ) ) ;
F_24 ( V_1 , V_78 ,
F_21 ( V_78 ) ) ;
F_25 ( V_1 , V_75 ,
F_21 ( V_75 ) ) ;
break;
default:
F_25 ( V_1 , V_79 ,
F_21 ( V_79 ) ) ;
F_24 ( V_1 , V_80 ,
F_21 ( V_80 ) ) ;
F_25 ( V_1 , V_81 ,
F_21 ( V_81 ) ) ;
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
static void F_27 ( struct V_1 * V_1 )
{
F_5 ( V_1 , 0xe0 , 0x01 ) ;
F_12 ( V_1 , 0 ) ;
F_5 ( V_1 , 0xe0 , 0x00 ) ;
}
static void F_28 ( struct V_1 * V_1 ,
T_2 * V_17 , int V_82 )
{
struct V_29 * V_29 = (struct V_29 * ) V_1 ;
T_4 V_83 ;
T_2 V_84 ;
int V_85 = V_82 ;
do {
V_82 = F_29 ( V_85 , 2040 ) ;
if ( V_17 [ 0 ] != 12 || V_82 < 12 ) {
F_6 ( V_86 , L_12 ) ;
goto V_87;
}
if ( V_17 [ 1 ] & V_88 ) {
F_6 ( V_86 , L_13 ) ;
goto V_87;
}
if ( ! ( V_17 [ 1 ] & V_89 ) ) {
F_6 ( V_86 , L_14 ) ;
goto V_87;
}
V_83 = ( V_17 [ 5 ] << 24 ) | ( V_17 [ 4 ] << 16 )
| ( V_17 [ 3 ] << 8 ) | V_17 [ 2 ] ;
V_84 = V_17 [ 1 ] & V_90 ;
if ( V_83 != V_29 -> V_91 || V_84 != V_29 -> V_92 ) {
if ( V_1 -> V_93 == V_94 )
F_30 ( V_1 , V_95 ,
NULL , 0 ) ;
V_29 -> V_91 = V_83 ;
V_29 -> V_92 = V_84 ;
F_30 ( V_1 , V_96 ,
V_17 + 12 , V_82 - 12 ) ;
} else if ( V_17 [ 1 ] & V_97 ) {
V_29 -> V_91 = 0 ;
F_30 ( V_1 , V_95 ,
V_17 + 12 , V_82 - 12 ) ;
} else {
F_30 ( V_1 , V_94 ,
V_17 + 12 , V_82 - 12 ) ;
}
goto V_98;
V_87:
V_1 -> V_93 = V_99 ;
V_98:
V_85 -= V_82 ;
V_17 += V_82 ;
} while ( V_85 > 0 );
}
static int F_31 ( struct V_1 * V_1 , T_5 V_3 )
{
struct V_29 * V_29 = (struct V_29 * ) V_1 ;
V_29 -> V_30 = V_3 ;
if ( V_1 -> V_100 )
F_13 ( V_1 ) ;
return V_1 -> V_8 ;
}
static int F_32 ( struct V_1 * V_1 , T_5 * V_3 )
{
struct V_29 * V_29 = (struct V_29 * ) V_1 ;
* V_3 = V_29 -> V_30 ;
return 0 ;
}
static int F_33 ( struct V_1 * V_1 , T_5 V_3 )
{
struct V_29 * V_29 = (struct V_29 * ) V_1 ;
V_29 -> V_31 = V_3 ;
if ( V_1 -> V_100 )
F_14 ( V_1 ) ;
return V_1 -> V_8 ;
}
static int F_34 ( struct V_1 * V_1 , T_5 * V_3 )
{
struct V_29 * V_29 = (struct V_29 * ) V_1 ;
* V_3 = V_29 -> V_31 ;
return 0 ;
}
static int F_35 ( struct V_1 * V_1 , T_5 V_3 )
{
struct V_29 * V_29 = (struct V_29 * ) V_1 ;
V_29 -> V_32 = V_3 ;
if ( V_1 -> V_100 ) {
if ( V_3 )
V_1 -> V_51 |= ( 1 << V_52 ) ;
else
V_1 -> V_51 &= ~ ( 1 << V_52 ) ;
F_15 ( V_1 ) ;
}
return V_1 -> V_8 ;
}
static int F_36 ( struct V_1 * V_1 , T_5 * V_3 )
{
struct V_29 * V_29 = (struct V_29 * ) V_1 ;
* V_3 = V_29 -> V_32 ;
return 0 ;
}
static int F_37 ( struct V_1 * V_1 , T_5 V_3 )
{
struct V_29 * V_29 = (struct V_29 * ) V_1 ;
V_29 -> V_34 = V_3 ;
if ( V_1 -> V_100 )
F_16 ( V_1 ) ;
return V_1 -> V_8 ;
}
static int F_38 ( struct V_1 * V_1 , T_5 * V_3 )
{
struct V_29 * V_29 = (struct V_29 * ) V_1 ;
* V_3 = V_29 -> V_34 ;
return 0 ;
}
static int F_39 ( struct V_1 * V_1 , T_5 V_3 )
{
struct V_29 * V_29 = (struct V_29 * ) V_1 ;
V_29 -> V_35 = V_3 ;
if ( V_1 -> V_100 )
F_17 ( V_1 ) ;
return V_1 -> V_8 ;
}
static int F_40 ( struct V_1 * V_1 , T_5 * V_3 )
{
struct V_29 * V_29 = (struct V_29 * ) V_1 ;
* V_3 = V_29 -> V_35 ;
return 0 ;
}
static int F_41 ( struct V_1 * V_1 , T_5 V_3 )
{
struct V_29 * V_29 = (struct V_29 * ) V_1 ;
V_29 -> V_40 = V_3 ;
if ( V_1 -> V_100 )
F_18 ( V_1 ) ;
return V_1 -> V_8 ;
}
static int F_42 ( struct V_1 * V_1 , T_5 * V_3 )
{
struct V_29 * V_29 = (struct V_29 * ) V_1 ;
* V_3 = V_29 -> V_40 ;
return 0 ;
}
static int F_43 ( struct V_1 * V_1 , T_5 V_3 )
{
struct V_29 * V_29 = (struct V_29 * ) V_1 ;
V_29 -> V_41 = V_3 ;
if ( V_1 -> V_100 )
F_19 ( V_1 ) ;
return V_1 -> V_8 ;
}
static int F_44 ( struct V_1 * V_1 , T_5 * V_3 )
{
struct V_29 * V_29 = (struct V_29 * ) V_1 ;
* V_3 = V_29 -> V_41 ;
return 0 ;
}
static int F_45 ( struct V_1 * V_1 ,
struct V_101 * V_102 )
{
switch ( V_102 -> V_43 ) {
case V_103 :
switch ( V_102 -> V_104 ) {
case 0 :
strcpy ( ( char * ) V_102 -> V_105 , L_15 ) ;
return 0 ;
case 1 :
strcpy ( ( char * ) V_102 -> V_105 , L_16 ) ;
return 0 ;
case 2 :
strcpy ( ( char * ) V_102 -> V_105 , L_17 ) ;
return 0 ;
}
break;
}
return - V_106 ;
}
static int F_46 ( struct V_107 * V_108 , const struct V_42 * V_43 )
{
return F_47 ( V_108 , V_43 , & V_109 , sizeof( struct V_29 ) ,
V_110 ) ;
}
static int T_6 F_48 ( void )
{
return F_49 ( & V_111 ) ;
}
static void T_7 F_50 ( void )
{
F_51 ( & V_111 ) ;
}
