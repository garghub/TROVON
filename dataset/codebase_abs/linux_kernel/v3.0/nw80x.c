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
static void F_12 ( struct V_1 * V_1 )
{
struct V_25 * V_25 = (struct V_25 * ) V_1 ;
T_2 V_17 , V_23 [ 2 ] ;
V_17 = V_25 -> V_26 [ V_27 ] . V_17 ;
switch ( V_25 -> V_28 ) {
case V_29 :
V_17 >>= 1 ;
F_1 ( V_1 , 0x1026 , & V_17 , 1 ) ;
break;
case V_30 :
V_17 = F_11 ( V_17 ) ;
V_23 [ 0 ] = V_17 << 3 ;
V_23 [ 1 ] = V_17 >> 5 ;
F_1 ( V_1 , 0x101d , V_23 , 2 ) ;
break;
}
}
static void F_13 ( struct V_1 * V_1 )
{
struct V_25 * V_25 = (struct V_25 * ) V_1 ;
T_3 V_17 ;
T_2 V_23 [ 2 ] ;
V_17 = V_25 -> V_26 [ V_31 ] . V_17 ;
switch ( V_25 -> V_28 ) {
case V_29 :
V_23 [ 0 ] = ( ( 9 - V_17 ) << 3 ) | 0x01 ;
F_1 ( V_1 , 0x1019 , V_23 , 1 ) ;
break;
case V_32 :
case V_33 :
case V_34 :
case V_30 :
V_23 [ 0 ] = V_17 ;
V_23 [ 1 ] = V_17 >> 8 ;
F_1 ( V_1 , 0x101b , V_23 , 2 ) ;
break;
}
}
static void F_14 ( struct V_1 * V_1 )
{
struct V_25 * V_25 = (struct V_25 * ) V_1 ;
int V_35 , V_36 ;
if ( V_1 -> V_37 & ( 1 << V_38 ) )
return;
if ( ! V_25 -> V_26 [ V_38 ] . V_17 ) {
V_25 -> V_39 = - 1 ;
return;
}
V_25 -> V_39 = V_40 ;
F_6 ( V_1 , 0x1004 , 1 ) ;
if ( V_1 -> V_10 [ 0 ] & 0x04 ) {
V_25 -> V_41 = V_1 -> V_42 * V_1 -> V_43 ;
} else {
F_6 ( V_1 , 0x1011 , 8 ) ;
V_35 = ( V_1 -> V_10 [ 1 ] << 8 ) + V_1 -> V_10 [ 0 ]
- ( V_1 -> V_10 [ 3 ] << 8 ) - V_1 -> V_10 [ 2 ] ;
V_36 = ( V_1 -> V_10 [ 5 ] << 8 ) + V_1 -> V_10 [ 4 ]
- ( V_1 -> V_10 [ 7 ] << 8 ) - V_1 -> V_10 [ 6 ] ;
V_25 -> V_41 = V_36 * V_35 ;
if ( V_25 -> V_41 == 0 )
V_25 -> V_41 = V_1 -> V_42 * V_1 -> V_43 ;
}
}
static int F_15 ( struct V_1 * V_1 ,
T_1 V_2 ,
T_2 V_44 )
{
F_1 ( V_1 , V_2 , & V_44 , 1 ) ;
F_6 ( V_1 , V_2 , 1 ) ;
return V_1 -> V_10 [ 0 ] == V_44 ;
}
static int F_16 ( struct V_1 * V_1 ,
const struct V_45 * V_46 )
{
struct V_25 * V_25 = (struct V_25 * ) V_1 ;
if ( ( unsigned ) V_28 >= V_47 )
V_28 = 0 ;
V_25 -> V_28 = V_28 ;
V_1 -> V_48 . V_49 = 1 ;
V_1 -> V_48 . V_26 = V_25 -> V_26 ;
V_25 -> V_39 = - 1 ;
if ( ! F_15 ( V_1 , 0x0500 , 0x55 ) ) {
V_25 -> V_50 = V_51 ;
if ( V_25 -> V_28 == V_52 )
V_25 -> V_28 = V_53 ;
} else if ( ! F_15 ( V_1 , 0x109b , 0xaa ) ) {
V_25 -> V_50 = V_54 ;
if ( V_25 -> V_28 == V_52 )
V_25 -> V_28 = V_29 ;
} else if ( V_46 -> V_55 == 0x06a5 && V_46 -> V_56 == 0xd800 ) {
F_6 ( V_1 , 0x0403 , 1 ) ;
F_2 ( V_57 , L_7 ,
V_1 -> V_10 [ 0 ] ) ;
switch ( V_1 -> V_10 [ 0 ] >> 1 ) {
case 0x00 :
if ( V_25 -> V_28 == V_52 )
V_25 -> V_28 = V_58 ;
break;
case 0x01 :
if ( V_25 -> V_28 == V_52 )
V_25 -> V_28 = V_59 ;
break;
case 0x0a :
if ( V_25 -> V_28 == V_52 )
V_25 -> V_28 = V_60 ;
break;
}
}
if ( V_61 [ V_25 -> V_28 ] != V_25 -> V_50 ) {
F_5 ( L_8 , V_25 -> V_28 , V_25 -> V_50 ) ;
V_1 -> V_8 = - V_62 ;
return V_1 -> V_8 ;
}
F_2 ( V_57 , L_9 , V_25 -> V_50 , V_25 -> V_28 ) ;
if ( V_25 -> V_50 == V_63 ) {
switch ( V_25 -> V_28 ) {
case V_64 :
V_1 -> V_48 . V_65 = V_66 ;
break;
default:
V_1 -> V_48 . V_65 = & V_66 [ 1 ] ;
break;
}
V_1 -> V_48 . V_67 = 1 ;
} else {
V_1 -> V_48 . V_65 = V_68 ;
switch ( V_25 -> V_28 ) {
case V_30 :
case V_69 :
case V_29 :
V_1 -> V_48 . V_67 = F_17 ( V_68 ) ;
break;
default:
V_1 -> V_48 . V_67 = 1 ;
break;
}
}
switch ( V_25 -> V_28 ) {
case V_29 :
V_25 -> V_26 [ V_27 ] . V_70 = 255 / 5 * 2 ;
break;
case V_32 :
case V_33 :
case V_34 :
V_1 -> V_37 = ( 1 << V_27 ) | ( 1 << V_38 ) ;
case V_30 :
V_25 -> V_26 [ V_31 ] . V_71 = 315 ;
V_25 -> V_26 [ V_31 ] . V_70 = 150 ;
break;
default:
V_1 -> V_37 = ( 1 << V_27 ) | ( 1 << V_31 )
| ( 1 << V_38 ) ;
break;
}
#if V_72
if ( ! ( V_1 -> V_37 & ( 1 << V_38 ) ) )
V_1 -> V_73 = ( 1 << V_27 ) | ( 1 << V_31 ) ;
#endif
return V_1 -> V_8 ;
}
static int F_18 ( struct V_1 * V_1 )
{
struct V_25 * V_25 = (struct V_25 * ) V_1 ;
switch ( V_25 -> V_50 ) {
case V_63 :
switch ( V_25 -> V_28 ) {
case V_58 :
F_10 ( V_1 , V_74 ) ;
break;
default:
F_10 ( V_1 , V_75 ) ;
break;
}
break;
default:
switch ( V_25 -> V_28 ) {
case V_76 :
case V_29 :
case V_69 :
F_10 ( V_1 , V_77 ) ;
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
V_20 = V_78 [ V_25 -> V_28 ] ;
F_10 ( V_1 , V_20 ) ;
switch ( V_25 -> V_28 ) {
case V_29 :
if ( V_1 -> V_42 == 320 )
F_10 ( V_1 , V_79 ) ;
else
F_10 ( V_1 , V_80 ) ;
F_10 ( V_1 , V_81 ) ;
break;
case V_30 :
if ( V_1 -> V_42 == 320 )
F_10 ( V_1 , V_82 ) ;
else
F_10 ( V_1 , V_83 ) ;
F_10 ( V_1 , V_84 ) ;
break;
case V_69 :
if ( V_1 -> V_42 == 320 )
F_10 ( V_1 , V_85 ) ;
else
F_10 ( V_1 , V_86 ) ;
F_10 ( V_1 , V_87 ) ;
break;
}
F_12 ( V_1 ) ;
F_13 ( V_1 ) ;
F_14 ( V_1 ) ;
V_25 -> V_88 = 0 ;
V_25 -> V_89 = 0 ;
return V_1 -> V_8 ;
}
static void F_20 ( struct V_1 * V_1 )
{
struct V_25 * V_25 = (struct V_25 * ) V_1 ;
T_2 V_44 ;
if ( V_25 -> V_50 != V_54 ) {
V_44 = 0x02 ;
F_1 ( V_1 , 0x0406 , & V_44 , 1 ) ;
}
switch ( V_25 -> V_28 ) {
case V_32 :
case V_30 :
case V_33 :
case V_34 :
V_44 = 0xff ;
break;
case V_90 :
V_44 = 0x21 ;
break;
case V_58 :
case V_60 :
case V_69 :
case V_59 :
V_44 = 0x01 ;
break;
default:
return;
}
F_1 ( V_1 , 0x0404 , & V_44 , 1 ) ;
}
static void F_21 ( struct V_1 * V_1 ,
T_2 * V_3 ,
int V_4 )
{
if ( V_3 [ 0 ] == 0x00 && V_3 [ 1 ] == 0x00
&& V_3 [ 6 ] == 0xff && V_3 [ 7 ] == 0xff ) {
F_22 ( V_1 , V_91 , NULL , 0 ) ;
F_22 ( V_1 , V_92 , V_3 + 8 , V_4 - 8 ) ;
} else {
F_22 ( V_1 , V_93 , V_3 , V_4 ) ;
}
}
static int F_23 ( struct V_1 * V_1 , T_4 V_17 )
{
struct V_25 * V_25 = (struct V_25 * ) V_1 ;
V_25 -> V_26 [ V_38 ] . V_17 = V_17 ;
if ( V_17 )
V_1 -> V_73 = ( 1 << V_27 ) | ( 1 << V_31 ) ;
else
V_1 -> V_73 = 0 ;
if ( V_1 -> V_94 )
F_14 ( V_1 ) ;
return V_1 -> V_8 ;
}
static void F_24 ( struct V_1 * V_1 )
{
struct V_25 * V_25 = (struct V_25 * ) V_1 ;
int V_95 ;
if ( V_25 -> V_39 < 0 )
return;
if ( -- V_25 -> V_39 >= 0 )
return;
V_25 -> V_39 = V_40 ;
F_6 ( V_1 , V_25 -> V_50 == V_54 ? 0x080d : 0x080c , 4 ) ;
V_95 = ( V_1 -> V_10 [ 3 ] << 24 ) + ( V_1 -> V_10 [ 2 ] << 16 )
+ ( V_1 -> V_10 [ 1 ] << 8 ) + V_1 -> V_10 [ 0 ] ;
V_95 /= V_25 -> V_41 ;
switch ( V_25 -> V_28 ) {
case V_29 :
F_25 ( V_1 , V_95 , 100 , 5 ) ;
break;
default:
F_26 ( V_1 , V_95 , 100 , 5 , 230 , 0 ) ;
break;
}
}
static int F_27 ( struct V_96 * V_97 ,
const struct V_45 * V_46 )
{
return F_28 ( V_97 , V_46 , & V_98 , sizeof( struct V_25 ) ,
V_99 ) ;
}
static int T_5 F_29 ( void )
{
return F_30 ( & V_100 ) ;
}
static void T_6 F_31 ( void )
{
F_32 ( & V_100 ) ;
}
