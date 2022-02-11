static void F_1 ( struct V_1 * V_1 ,
T_1 V_2 ,
const T_2 * V_3 ,
int V_4 )
{
struct V_5 * V_6 = V_1 -> V_6 ;
int V_7 ;
if ( V_1 -> V_8 < 0 )
return;
if ( V_4 == 1 )
F_2 ( V_9 , L_1 , V_2 , * V_3 ) ;
else
F_2 ( V_9 , L_2 ,
V_2 , * V_3 , V_3 [ 1 ] ) ;
memcpy ( V_1 -> V_10 , V_3 , V_4 ) ;
V_7 = F_3 ( V_6 , F_4 ( V_6 , 0 ) ,
0x00 ,
V_11 | V_12 | V_13 ,
0x00 ,
V_2 ,
V_1 -> V_10 ,
V_4 ,
500 ) ;
if ( V_7 < 0 ) {
F_5 ( L_3 , V_7 ) ;
V_1 -> V_8 = V_7 ;
}
}
static void F_6 ( struct V_1 * V_1 ,
T_1 V_2 ,
int V_4 )
{
struct V_5 * V_6 = V_1 -> V_6 ;
int V_7 ;
if ( V_1 -> V_8 < 0 )
return;
V_7 = F_3 ( V_6 , F_7 ( V_6 , 0 ) ,
0x00 ,
V_14 | V_12 | V_13 ,
0x00 , V_2 ,
V_1 -> V_10 , V_4 , 500 ) ;
if ( V_7 < 0 ) {
F_5 ( L_4 , V_7 ) ;
V_1 -> V_8 = V_7 ;
return;
}
if ( V_4 == 1 )
F_2 ( V_15 , L_5 ,
V_2 , V_1 -> V_10 [ 0 ] ) ;
else
F_2 ( V_15 , L_6 ,
V_2 , V_1 -> V_10 [ 0 ] ,
V_1 -> V_10 [ 1 ] ) ;
}
static void F_8 ( struct V_1 * V_1 ,
T_2 V_16 ,
const T_2 * V_3 ,
int V_4 )
{
T_2 V_17 [ 2 ] ;
int V_18 ;
F_1 ( V_1 , 0x0600 , V_3 + 1 , V_4 - 1 ) ;
F_1 ( V_1 , 0x0600 , V_3 , V_4 ) ;
V_17 [ 0 ] = V_4 ;
V_17 [ 1 ] = V_16 ;
F_1 ( V_1 , 0x0502 , V_17 , 2 ) ;
V_17 [ 0 ] = 0x01 ;
F_1 ( V_1 , 0x0501 , V_17 , 1 ) ;
for ( V_18 = 5 ; -- V_18 >= 0 ; ) {
F_9 ( 4 ) ;
F_6 ( V_1 , 0x0505 , 1 ) ;
if ( V_1 -> V_8 < 0 )
return;
if ( V_1 -> V_10 [ 0 ] == 0 )
return;
}
V_1 -> V_8 = - V_19 ;
}
static void F_10 ( struct V_1 * V_1 ,
const T_2 * V_20 )
{
T_1 V_21 ;
int V_4 ;
for (; ; ) {
V_21 = * V_20 ++ << 8 ;
V_21 += * V_20 ++ ;
V_4 = * V_20 ++ ;
if ( V_4 == 0 )
break;
if ( V_20 [ - 3 ] != V_22 )
F_1 ( V_1 , V_21 , V_20 , V_4 ) ;
else
F_8 ( V_1 , V_21 , V_20 , V_4 ) ;
V_20 += V_4 ;
}
}
static int F_11 ( int V_23 )
{
int V_24 , V_18 ;
V_24 = 0 ;
for ( V_18 = 0 ; V_18 < 8 ; V_18 ++ ) {
V_24 <<= 1 ;
if ( V_23 & 1 )
V_24 ++ ;
V_23 >>= 1 ;
}
return V_24 ;
}
static void F_12 ( struct V_1 * V_1 , T_2 V_17 )
{
struct V_25 * V_25 = (struct V_25 * ) V_1 ;
T_2 V_23 [ 2 ] ;
switch ( V_25 -> V_26 ) {
case V_27 :
F_1 ( V_1 , 0x1026 , & V_17 , 1 ) ;
break;
case V_28 :
V_17 = F_11 ( V_17 ) ;
V_23 [ 0 ] = V_17 << 3 ;
V_23 [ 1 ] = V_17 >> 5 ;
F_1 ( V_1 , 0x101d , V_23 , 2 ) ;
break;
}
}
static void F_13 ( struct V_1 * V_1 , T_3 V_17 )
{
struct V_25 * V_25 = (struct V_25 * ) V_1 ;
T_2 V_23 [ 2 ] ;
switch ( V_25 -> V_26 ) {
case V_27 :
V_23 [ 0 ] = ( ( 9 - V_17 ) << 3 ) | 0x01 ;
F_1 ( V_1 , 0x1019 , V_23 , 1 ) ;
break;
case V_29 :
case V_30 :
case V_31 :
case V_28 :
V_23 [ 0 ] = V_17 ;
V_23 [ 1 ] = V_17 >> 8 ;
F_1 ( V_1 , 0x101b , V_23 , 2 ) ;
break;
}
}
static void F_14 ( struct V_1 * V_1 , T_3 V_17 )
{
struct V_25 * V_25 = (struct V_25 * ) V_1 ;
int V_32 , V_33 ;
if ( ! V_17 ) {
V_25 -> V_34 = - 1 ;
return;
}
V_25 -> V_34 = V_35 ;
F_6 ( V_1 , 0x1004 , 1 ) ;
if ( V_1 -> V_10 [ 0 ] & 0x04 ) {
V_25 -> V_36 = V_1 -> V_37 . V_38 * V_1 -> V_37 . V_39 ;
} else {
F_6 ( V_1 , 0x1011 , 8 ) ;
V_32 = ( V_1 -> V_10 [ 1 ] << 8 ) + V_1 -> V_10 [ 0 ]
- ( V_1 -> V_10 [ 3 ] << 8 ) - V_1 -> V_10 [ 2 ] ;
V_33 = ( V_1 -> V_10 [ 5 ] << 8 ) + V_1 -> V_10 [ 4 ]
- ( V_1 -> V_10 [ 7 ] << 8 ) - V_1 -> V_10 [ 6 ] ;
V_25 -> V_36 = V_33 * V_32 ;
if ( V_25 -> V_36 == 0 )
V_25 -> V_36 = V_1 -> V_37 . V_38 *
V_1 -> V_37 . V_39 ;
}
}
static int F_15 ( struct V_1 * V_1 ,
T_1 V_2 ,
T_2 V_40 )
{
F_1 ( V_1 , V_2 , & V_40 , 1 ) ;
F_6 ( V_1 , V_2 , 1 ) ;
return V_1 -> V_10 [ 0 ] == V_40 ;
}
static int F_16 ( struct V_1 * V_1 ,
const struct V_41 * V_42 )
{
struct V_25 * V_25 = (struct V_25 * ) V_1 ;
if ( ( unsigned ) V_26 >= V_43 )
V_26 = 0 ;
V_25 -> V_26 = V_26 ;
V_1 -> V_44 . V_45 = 1 ;
V_25 -> V_34 = - 1 ;
if ( ! F_15 ( V_1 , 0x0500 , 0x55 ) ) {
V_25 -> V_46 = V_47 ;
if ( V_25 -> V_26 == V_48 )
V_25 -> V_26 = V_49 ;
} else if ( ! F_15 ( V_1 , 0x109b , 0xaa ) ) {
V_25 -> V_46 = V_50 ;
if ( V_25 -> V_26 == V_48 )
V_25 -> V_26 = V_27 ;
} else if ( V_42 -> V_51 == 0x06a5 && V_42 -> V_52 == 0xd800 ) {
F_6 ( V_1 , 0x0403 , 1 ) ;
F_2 ( V_53 , L_7 ,
V_1 -> V_10 [ 0 ] ) ;
switch ( V_1 -> V_10 [ 0 ] >> 1 ) {
case 0x00 :
if ( V_25 -> V_26 == V_48 )
V_25 -> V_26 = V_54 ;
break;
case 0x01 :
if ( V_25 -> V_26 == V_48 )
V_25 -> V_26 = V_55 ;
break;
case 0x0a :
if ( V_25 -> V_26 == V_48 )
V_25 -> V_26 = V_56 ;
break;
}
}
if ( V_57 [ V_25 -> V_26 ] != V_25 -> V_46 ) {
F_5 ( L_8 ,
V_25 -> V_26 , V_25 -> V_46 ) ;
V_1 -> V_8 = - V_58 ;
return V_1 -> V_8 ;
}
F_2 ( V_53 , L_9 , V_25 -> V_46 , V_25 -> V_26 ) ;
if ( V_25 -> V_46 == V_59 ) {
switch ( V_25 -> V_26 ) {
case V_60 :
V_1 -> V_44 . V_61 = V_62 ;
break;
default:
V_1 -> V_44 . V_61 = & V_62 [ 1 ] ;
break;
}
V_1 -> V_44 . V_63 = 1 ;
} else {
V_1 -> V_44 . V_61 = V_64 ;
switch ( V_25 -> V_26 ) {
case V_28 :
case V_65 :
case V_27 :
V_1 -> V_44 . V_63 = F_17 ( V_64 ) ;
break;
default:
V_1 -> V_44 . V_63 = 1 ;
break;
}
}
return V_1 -> V_8 ;
}
static int F_18 ( struct V_1 * V_1 )
{
struct V_25 * V_25 = (struct V_25 * ) V_1 ;
switch ( V_25 -> V_46 ) {
case V_59 :
switch ( V_25 -> V_26 ) {
case V_54 :
F_10 ( V_1 , V_66 ) ;
break;
default:
F_10 ( V_1 , V_67 ) ;
break;
}
break;
default:
switch ( V_25 -> V_26 ) {
case V_68 :
case V_27 :
case V_65 :
F_10 ( V_1 , V_69 ) ;
break;
}
break;
}
return V_1 -> V_8 ;
}
static int F_19 ( struct V_1 * V_1 )
{
struct V_25 * V_25 = (struct V_25 * ) V_1 ;
const T_2 * V_20 ;
V_20 = V_70 [ V_25 -> V_26 ] ;
F_10 ( V_1 , V_20 ) ;
switch ( V_25 -> V_26 ) {
case V_27 :
if ( V_1 -> V_37 . V_38 == 320 )
F_10 ( V_1 , V_71 ) ;
else
F_10 ( V_1 , V_72 ) ;
F_10 ( V_1 , V_73 ) ;
break;
case V_28 :
if ( V_1 -> V_37 . V_38 == 320 )
F_10 ( V_1 , V_74 ) ;
else
F_10 ( V_1 , V_75 ) ;
F_10 ( V_1 , V_76 ) ;
break;
case V_65 :
if ( V_1 -> V_37 . V_38 == 320 )
F_10 ( V_1 , V_77 ) ;
else
F_10 ( V_1 , V_78 ) ;
F_10 ( V_1 , V_79 ) ;
break;
}
V_25 -> V_80 = 0 ;
V_25 -> V_81 = 0 ;
return V_1 -> V_8 ;
}
static void F_20 ( struct V_1 * V_1 )
{
struct V_25 * V_25 = (struct V_25 * ) V_1 ;
T_2 V_40 ;
if ( V_25 -> V_46 != V_50 ) {
V_40 = 0x02 ;
F_1 ( V_1 , 0x0406 , & V_40 , 1 ) ;
}
switch ( V_25 -> V_26 ) {
case V_29 :
case V_28 :
case V_30 :
case V_31 :
V_40 = 0xff ;
break;
case V_82 :
V_40 = 0x21 ;
break;
case V_54 :
case V_56 :
case V_65 :
case V_55 :
V_40 = 0x01 ;
break;
default:
return;
}
F_1 ( V_1 , 0x0404 , & V_40 , 1 ) ;
}
static void F_21 ( struct V_1 * V_1 ,
T_2 * V_3 ,
int V_4 )
{
if ( V_3 [ 0 ] == 0x00 && V_3 [ 1 ] == 0x00
&& V_3 [ 6 ] == 0xff && V_3 [ 7 ] == 0xff ) {
F_22 ( V_1 , V_83 , NULL , 0 ) ;
F_22 ( V_1 , V_84 , V_3 + 8 , V_4 - 8 ) ;
} else {
F_22 ( V_1 , V_85 , V_3 , V_4 ) ;
}
}
static void F_23 ( struct V_1 * V_1 )
{
struct V_25 * V_25 = (struct V_25 * ) V_1 ;
int V_86 ;
if ( V_25 -> V_34 < 0 )
return;
if ( -- V_25 -> V_34 >= 0 )
return;
V_25 -> V_34 = V_35 ;
F_6 ( V_1 , V_25 -> V_46 == V_50 ? 0x080d : 0x080c , 4 ) ;
V_86 = ( V_1 -> V_10 [ 3 ] << 24 ) + ( V_1 -> V_10 [ 2 ] << 16 )
+ ( V_1 -> V_10 [ 1 ] << 8 ) + V_1 -> V_10 [ 0 ] ;
V_86 /= V_25 -> V_36 ;
switch ( V_25 -> V_26 ) {
case V_27 :
F_24 ( V_1 , V_86 , 100 , 5 ) ;
break;
default:
F_25 ( V_1 , V_86 , 100 , 5 , 230 , 0 ) ;
break;
}
}
static int F_26 ( struct V_87 * V_88 )
{
struct V_1 * V_1 =
F_27 ( V_88 -> V_89 , struct V_1 , V_90 ) ;
V_1 -> V_8 = 0 ;
if ( ! V_1 -> V_91 )
return 0 ;
switch ( V_88 -> V_42 ) {
case V_92 :
if ( V_88 -> V_93 )
F_14 ( V_1 , V_88 -> V_17 ) ;
if ( ! V_88 -> V_17 ) {
if ( V_1 -> V_94 -> V_93 )
F_12 ( V_1 , V_1 -> V_94 -> V_17 ) ;
if ( V_1 -> V_95 -> V_93 )
F_13 ( V_1 ,
V_1 -> V_95 -> V_17 ) ;
}
break;
case V_96 :
F_13 ( V_1 , V_1 -> V_95 -> V_17 ) ;
break;
}
return V_1 -> V_8 ;
}
static int F_28 ( struct V_1 * V_1 )
{
struct V_25 * V_25 = (struct V_25 * ) V_1 ;
struct V_97 * V_98 = & V_1 -> V_90 ;
V_1 -> V_99 . V_90 = V_98 ;
F_29 ( V_98 , 3 ) ;
switch ( V_25 -> V_26 ) {
case V_27 :
V_1 -> V_100 = F_30 ( V_98 , & V_101 ,
V_92 , 0 , 1 , 1 , 1 ) ;
V_1 -> V_94 = F_30 ( V_98 , & V_101 ,
V_102 , 0 , 127 , 1 , 127 / 5 * 2 ) ;
V_1 -> V_95 = F_30 ( V_98 , & V_101 ,
V_96 , 0 , 9 , 1 , 9 ) ;
break;
case V_28 :
V_1 -> V_100 = F_30 ( V_98 , & V_101 ,
V_92 , 0 , 1 , 1 , 1 ) ;
V_1 -> V_94 = F_30 ( V_98 , & V_101 ,
V_102 , 0 , 253 , 1 , 128 ) ;
case V_29 :
case V_30 :
case V_31 :
V_1 -> V_95 = F_30 ( V_98 , & V_101 ,
V_96 , 0 , 315 , 1 , 150 ) ;
break;
default:
break;
}
if ( V_98 -> error ) {
F_5 ( L_10 ) ;
return V_98 -> error ;
}
if ( V_1 -> V_100 )
F_31 ( 3 , & V_1 -> V_100 , 0 , false ) ;
return 0 ;
}
static int F_32 ( struct V_103 * V_104 ,
const struct V_41 * V_42 )
{
return F_33 ( V_104 , V_42 , & V_105 , sizeof( struct V_25 ) ,
V_106 ) ;
}
