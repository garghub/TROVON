static void F_1 ( struct V_1 * V_1 ,
T_1 V_2 ,
const T_2 * V_3 , int V_4 )
{
int V_5 ;
if ( V_1 -> V_6 < 0 )
return;
memcpy ( V_1 -> V_7 , V_3 , V_4 ) ;
V_5 = F_2 ( V_1 -> V_8 ,
F_3 ( V_1 -> V_8 , 0 ) ,
0 ,
V_9 | V_10 | V_11 ,
0 ,
V_2 , V_1 -> V_7 , V_4 ,
500 ) ;
if ( V_5 < 0 ) {
F_4 ( L_1 ,
V_2 , V_5 ) ;
V_1 -> V_6 = V_5 ;
}
}
static void F_5 ( struct V_1 * V_1 ,
T_1 V_2 ,
T_1 V_12 )
{
int V_5 ;
if ( V_1 -> V_6 < 0 )
return;
V_1 -> V_7 [ 0 ] = V_12 ;
V_5 = F_2 ( V_1 -> V_8 ,
F_3 ( V_1 -> V_8 , 0 ) ,
0 ,
V_9 | V_10 | V_11 ,
0 , V_2 , V_1 -> V_7 , 1 ,
500 ) ;
if ( V_5 < 0 ) {
F_4 ( L_2 ,
V_2 , V_12 , V_5 ) ;
V_1 -> V_6 = V_5 ;
}
}
static void F_6 ( struct V_1 * V_1 ,
const T_1 * V_13 , int V_4 )
{
while ( -- V_4 >= 0 ) {
F_5 ( V_1 , V_13 [ 0 ] , V_13 [ 1 ] ) ;
V_13 += 2 ;
}
}
static void F_7 ( struct V_1 * V_1 ,
const T_1 * V_14 , int V_4 )
{
int V_2 ;
int V_5 = 0 ;
if ( V_1 -> V_6 < 0 )
return;
for ( V_2 = 0 ; V_2 < V_4 ; V_2 ++ ) {
if ( V_14 [ V_2 ] == V_15 )
continue;
V_1 -> V_7 [ 0 ] = V_14 [ V_2 ] ;
V_5 = F_2 ( V_1 -> V_8 ,
F_3 ( V_1 -> V_8 , 0 ) ,
0 ,
V_9 | V_10 | V_11 ,
0 , V_2 , V_1 -> V_7 , 1 ,
500 ) ;
if ( V_5 < 0 ) {
F_4 ( L_3 ,
V_2 , V_14 [ V_2 ] , V_5 ) ;
V_1 -> V_6 = V_5 ;
break;
}
}
}
static void F_8 ( struct V_1 * V_1 ,
const T_1 * V_13 ,
const T_1 * V_16 , unsigned int V_17 )
{
int V_2 , V_4 ;
for (; ; ) {
V_2 = * V_13 ++ ;
V_4 = * V_13 ++ ;
switch ( V_4 ) {
case V_18 :
return;
case V_19 :
F_7 ( V_1 , V_16 , V_17 ) ;
break;
default:
if ( V_4 > V_20 ) {
F_9 ( V_21 | V_22 ,
L_4 ) ;
return;
}
while ( V_4 > 0 ) {
if ( V_4 < 8 ) {
F_1 ( V_1 ,
V_2 , V_13 , V_4 ) ;
V_13 += V_4 ;
break;
}
F_1 ( V_1 , V_2 , V_13 , 8 ) ;
V_13 += 8 ;
V_2 += 8 ;
V_4 -= 8 ;
}
}
}
}
static int F_10 ( struct V_1 * V_1 ,
const struct V_23 * V_24 )
{
struct V_25 * V_25 = & V_1 -> V_25 ;
V_25 -> V_26 = V_27 ;
V_25 -> V_28 = F_11 ( V_27 ) ;
V_25 -> V_29 = V_30 ;
return 0 ;
}
static void F_12 ( struct V_1 * V_1 , T_3 V_31 )
{
F_5 ( V_1 , 0xff , 0x04 ) ;
F_5 ( V_1 , 0x10 , V_31 ) ;
F_5 ( V_1 , 0x11 , 0x01 ) ;
}
static void F_13 ( struct V_1 * V_1 , T_3 V_31 )
{
F_5 ( V_1 , 0xff , 0x04 ) ;
F_5 ( V_1 , 0x0e , 0x00 ) ;
F_5 ( V_1 , 0x0f , V_1 -> V_32 -> V_33 - V_31 + 1 ) ;
F_5 ( V_1 , 0x11 , 0x01 ) ;
}
static void F_14 ( struct V_1 * V_1 , T_3 V_31 )
{
F_5 ( V_1 , 0xff , 0x04 ) ;
F_5 ( V_1 , 0x02 , V_31 ) ;
F_5 ( V_1 , 0x11 , 0x01 ) ;
F_5 ( V_1 , 0xff , 0x01 ) ;
if ( V_1 -> V_34 != 640 && V_31 <= 3 )
F_5 ( V_1 , 0x08 , 0x09 ) ;
else
F_5 ( V_1 , 0x08 , 0x08 ) ;
if ( V_1 -> V_34 == 640 && V_31 == 2 )
F_5 ( V_1 , 0x80 , 0x01 ) ;
else
F_5 ( V_1 , 0x80 , 0x1c ) ;
F_5 ( V_1 , 0x11 , 0x01 ) ;
}
static void F_15 ( struct V_1 * V_1 , T_3 V_35 , T_3 V_36 )
{
T_1 V_37 ;
F_5 ( V_1 , 0xff , 0x04 ) ;
V_37 = ( V_35 ? 0x04 : 0x00 ) |
( V_36 ? 0x08 : 0x00 ) ;
F_5 ( V_1 , 0x21 , V_37 ) ;
F_5 ( V_1 , 0x11 , 0x01 ) ;
}
static int F_16 ( struct V_1 * V_1 )
{
F_6 ( V_1 , V_38 , sizeof( V_38 ) / 2 ) ;
return V_1 -> V_6 ;
}
static int F_17 ( struct V_39 * V_40 )
{
struct V_1 * V_1 =
F_18 ( V_40 -> V_41 , struct V_1 , V_42 ) ;
struct V_43 * V_43 = (struct V_43 * ) V_1 ;
V_1 -> V_6 = 0 ;
if ( V_40 -> V_24 == V_44 && V_40 -> V_45 && V_40 -> V_31 ) {
V_1 -> V_46 -> V_31 = V_47 ;
V_1 -> V_32 -> V_31 = V_48 ;
V_43 -> V_49 = V_50 ;
}
if ( ! V_1 -> V_51 )
return 0 ;
switch ( V_40 -> V_24 ) {
case V_52 :
F_12 ( V_1 , V_40 -> V_31 ) ;
break;
case V_44 :
if ( V_1 -> V_46 -> V_45 || ( V_40 -> V_45 && V_40 -> V_31 ) )
F_14 ( V_1 , V_1 -> V_46 -> V_31 ) ;
if ( V_1 -> V_32 -> V_45 || ( V_40 -> V_45 && V_40 -> V_31 ) )
F_13 ( V_1 , V_1 -> V_32 -> V_31 ) ;
break;
case V_53 :
F_15 ( V_1 , V_43 -> V_35 -> V_31 , 1 ) ;
break;
default:
return - V_54 ;
}
return V_1 -> V_6 ;
}
static int F_19 ( struct V_1 * V_1 )
{
struct V_43 * V_43 = (struct V_43 * ) V_1 ;
struct V_55 * V_56 = & V_1 -> V_42 ;
V_1 -> V_57 . V_42 = V_56 ;
F_20 ( V_56 , 5 ) ;
V_43 -> V_58 = F_21 ( V_56 , & V_59 ,
V_52 , 0 , 15 , 1 , 7 ) ;
V_1 -> V_60 = F_21 ( V_56 , & V_59 ,
V_44 , 0 , 1 , 1 , 1 ) ;
V_1 -> V_46 = F_21 ( V_56 , & V_59 ,
V_61 , 2 , 63 , 1 ,
V_47 ) ;
V_1 -> V_32 = F_21 ( V_56 , & V_59 ,
V_62 , 0 , 244 , 1 ,
V_48 ) ;
V_43 -> V_35 = F_21 ( V_56 , & V_59 ,
V_53 , 0 , 1 , 1 , 0 ) ;
if ( V_56 -> error ) {
F_4 ( L_5 ) ;
return V_56 -> error ;
}
F_22 ( 3 , & V_1 -> V_60 , 0 , false ) ;
return 0 ;
}
static int F_23 ( struct V_1 * V_1 )
{
struct V_43 * V_43 = (struct V_43 * ) V_1 ;
V_43 -> V_63 = 0 ;
F_8 ( V_1 , V_64 ,
V_65 , sizeof( V_65 ) ) ;
F_12 ( V_1 , F_24 ( V_43 -> V_58 ) ) ;
F_13 ( V_1 , F_24 ( V_1 -> V_32 ) ) ;
F_14 ( V_1 , F_24 ( V_1 -> V_46 ) ) ;
F_15 ( V_1 , F_24 ( V_43 -> V_35 ) , 1 ) ;
switch ( V_1 -> V_25 . V_26 [ ( int ) V_1 -> V_66 ] . V_67 ) {
case 2 :
F_5 ( V_1 , 0xff , 0x01 ) ;
F_5 ( V_1 , 0x17 , 0x20 ) ;
F_5 ( V_1 , 0x87 , 0x10 ) ;
break;
case 1 :
F_5 ( V_1 , 0xff , 0x01 ) ;
F_5 ( V_1 , 0x17 , 0x30 ) ;
F_5 ( V_1 , 0x87 , 0x11 ) ;
break;
case 0 :
F_5 ( V_1 , 0xff , 0x01 ) ;
F_5 ( V_1 , 0x17 , 0x00 ) ;
F_5 ( V_1 , 0x87 , 0x12 ) ;
break;
}
V_43 -> V_63 = 0 ;
V_43 -> V_49 = 0 ;
F_25 ( & V_43 -> V_68 , - 1 ) ;
F_5 ( V_1 , 0xff , 0x01 ) ;
F_5 ( V_1 , 0x78 , 0x05 ) ;
return V_1 -> V_6 ;
}
static void F_26 ( struct V_1 * V_1 )
{
F_5 ( V_1 , 0xff , 0x04 ) ;
F_5 ( V_1 , 0x27 , 0x80 ) ;
F_5 ( V_1 , 0x28 , 0xca ) ;
F_5 ( V_1 , 0x29 , 0x53 ) ;
F_5 ( V_1 , 0x2a , 0x0e ) ;
F_5 ( V_1 , 0xff , 0x01 ) ;
F_5 ( V_1 , 0x3e , 0x20 ) ;
F_5 ( V_1 , 0x78 , 0x44 ) ;
F_5 ( V_1 , 0x78 , 0x44 ) ;
F_5 ( V_1 , 0x78 , 0x44 ) ;
}
static void F_27 ( struct V_1 * V_1 )
{
struct V_43 * V_43 = (struct V_43 * ) V_1 ;
int V_68 = F_28 ( & V_43 -> V_68 ) ;
int V_69 , V_70 ;
if ( V_68 == - 1 )
return;
V_69 = 170 ;
V_70 = 20 ;
if ( V_43 -> V_49 > 0 )
V_43 -> V_49 -- ;
else if ( F_29 ( V_1 , V_68 ,
V_69 , V_70 ) )
V_43 -> V_49 = V_50 ;
}
static void F_30 ( struct V_1 * V_1 ,
T_4 V_71 , T_4 V_72 )
{
unsigned char V_73 [ 4 ] ;
F_31 ( V_1 , V_74 ,
V_75 , sizeof( V_75 ) ) ;
V_73 [ 0 ] = V_71 >> 8 ;
V_73 [ 1 ] = V_71 & 0xff ;
V_73 [ 2 ] = V_72 >> 8 ;
V_73 [ 3 ] = V_72 & 0xff ;
F_31 ( V_1 , V_76 ,
V_73 , sizeof( V_73 ) ) ;
F_31 ( V_1 , V_76 ,
V_77 , sizeof( V_77 ) ) ;
}
static void F_32 ( struct V_1 * V_1 ,
T_2 * V_37 ,
int V_4 )
{
struct V_43 * V_43 = (struct V_43 * ) V_1 ;
T_2 * V_78 ;
unsigned char * V_79 ;
V_79 = F_33 ( & V_43 -> V_63 , V_37 , V_4 ) ;
if ( V_79 ) {
int V_80 , V_81 , V_82 ;
V_81 = 24 + sizeof F_34 ;
V_82 = 26 ;
V_80 = ( V_79 - V_37 ) - ( V_82 + sizeof F_34 ) ;
if ( V_80 < 0 ) {
V_1 -> V_83 += V_80 ;
V_80 = 0 ;
} else {
F_31 ( V_1 , V_76 , V_37 , V_80 ) ;
}
V_78 = V_1 -> V_78 ;
if ( V_78 != NULL
&& V_78 [ V_1 -> V_83 - 2 ] == 0xff
&& V_78 [ V_1 -> V_83 - 1 ] == 0xd9 )
F_31 ( V_1 , V_84 , NULL , 0 ) ;
V_80 = V_79 - V_37 ;
V_4 -= V_80 ;
V_37 = V_79 ;
if ( V_1 -> V_85 == V_84 &&
V_80 >= V_81 )
F_25 ( & V_43 -> V_68 , V_37 [ - V_81 ] +
V_37 [ - V_81 + 1 ] ) ;
else
F_25 ( & V_43 -> V_68 , - 1 ) ;
F_30 ( V_1 ,
V_1 -> V_86 , V_1 -> V_34 ) ;
}
F_31 ( V_1 , V_76 , V_37 , V_4 ) ;
}
static int F_35 ( struct V_1 * V_1 ,
T_2 * V_37 ,
int V_4 )
{
int V_5 = - V_54 ;
T_2 V_87 , V_88 ;
if ( V_4 == 2 ) {
V_87 = V_37 [ 0 ] ;
V_88 = V_37 [ 1 ] ;
if ( ( V_87 == 0x00 && V_88 == 0x11 ) ||
( V_87 == 0x22 && V_88 == 0x33 ) ||
( V_87 == 0x44 && V_88 == 0x55 ) ||
( V_87 == 0x66 && V_88 == 0x77 ) ||
( V_87 == 0x88 && V_88 == 0x99 ) ||
( V_87 == 0xaa && V_88 == 0xbb ) ||
( V_87 == 0xcc && V_88 == 0xdd ) ||
( V_87 == 0xee && V_88 == 0xff ) ) {
F_36 ( V_1 -> V_89 , V_90 , 1 ) ;
F_37 ( V_1 -> V_89 ) ;
F_36 ( V_1 -> V_89 , V_90 , 0 ) ;
F_37 ( V_1 -> V_89 ) ;
V_5 = 0 ;
}
}
return V_5 ;
}
static int F_38 ( struct V_91 * V_92 ,
const struct V_23 * V_24 )
{
return F_39 ( V_92 , V_24 , & V_93 , sizeof( struct V_43 ) ,
V_94 ) ;
}
