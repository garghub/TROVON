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
F_9 ( L_4 ) ;
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
const struct V_21 * V_22 )
{
struct V_23 * V_23 = & V_1 -> V_23 ;
V_23 -> V_24 = V_25 ;
V_23 -> V_26 = F_11 ( V_25 ) ;
V_23 -> V_27 = V_28 ;
return 0 ;
}
static void F_12 ( struct V_1 * V_1 , T_3 V_29 )
{
F_5 ( V_1 , 0xff , 0x04 ) ;
F_5 ( V_1 , 0x10 , V_29 ) ;
F_5 ( V_1 , 0x11 , 0x01 ) ;
}
static void F_13 ( struct V_1 * V_1 , T_3 V_29 )
{
F_5 ( V_1 , 0xff , 0x04 ) ;
F_5 ( V_1 , 0x0e , 0x00 ) ;
F_5 ( V_1 , 0x0f , V_1 -> V_30 -> V_31 - V_29 + 1 ) ;
F_5 ( V_1 , 0x11 , 0x01 ) ;
}
static void F_14 ( struct V_1 * V_1 , T_3 V_29 )
{
F_5 ( V_1 , 0xff , 0x04 ) ;
F_5 ( V_1 , 0x02 , V_29 ) ;
F_5 ( V_1 , 0x11 , 0x01 ) ;
F_5 ( V_1 , 0xff , 0x01 ) ;
if ( V_1 -> V_32 != 640 && V_29 <= 3 )
F_5 ( V_1 , 0x08 , 0x09 ) ;
else
F_5 ( V_1 , 0x08 , 0x08 ) ;
if ( V_1 -> V_32 == 640 && V_29 == 2 )
F_5 ( V_1 , 0x80 , 0x01 ) ;
else
F_5 ( V_1 , 0x80 , 0x1c ) ;
F_5 ( V_1 , 0x11 , 0x01 ) ;
}
static void F_15 ( struct V_1 * V_1 , T_3 V_33 , T_3 V_34 )
{
T_1 V_35 ;
F_5 ( V_1 , 0xff , 0x04 ) ;
V_35 = ( V_33 ? 0x04 : 0x00 ) |
( V_34 ? 0x08 : 0x00 ) ;
F_5 ( V_1 , 0x21 , V_35 ) ;
F_5 ( V_1 , 0x11 , 0x01 ) ;
}
static int F_16 ( struct V_1 * V_1 )
{
F_6 ( V_1 , V_36 , sizeof( V_36 ) / 2 ) ;
return V_1 -> V_6 ;
}
static int F_17 ( struct V_37 * V_38 )
{
struct V_1 * V_1 =
F_18 ( V_38 -> V_39 , struct V_1 , V_40 ) ;
struct V_41 * V_41 = (struct V_41 * ) V_1 ;
V_1 -> V_6 = 0 ;
if ( V_38 -> V_22 == V_42 && V_38 -> V_43 && V_38 -> V_29 ) {
V_1 -> V_44 -> V_29 = V_45 ;
V_1 -> V_30 -> V_29 = V_46 ;
V_41 -> V_47 = V_48 ;
}
if ( ! V_1 -> V_49 )
return 0 ;
switch ( V_38 -> V_22 ) {
case V_50 :
F_12 ( V_1 , V_38 -> V_29 ) ;
break;
case V_42 :
if ( V_1 -> V_44 -> V_43 || ( V_38 -> V_43 && V_38 -> V_29 ) )
F_14 ( V_1 , V_1 -> V_44 -> V_29 ) ;
if ( V_1 -> V_30 -> V_43 || ( V_38 -> V_43 && V_38 -> V_29 ) )
F_13 ( V_1 , V_1 -> V_30 -> V_29 ) ;
break;
case V_51 :
F_15 ( V_1 , V_41 -> V_33 -> V_29 , 1 ) ;
break;
default:
return - V_52 ;
}
return V_1 -> V_6 ;
}
static int F_19 ( struct V_1 * V_1 )
{
struct V_41 * V_41 = (struct V_41 * ) V_1 ;
struct V_53 * V_54 = & V_1 -> V_40 ;
V_1 -> V_55 . V_40 = V_54 ;
F_20 ( V_54 , 5 ) ;
V_41 -> V_56 = F_21 ( V_54 , & V_57 ,
V_50 , 0 , 15 , 1 , 7 ) ;
V_1 -> V_58 = F_21 ( V_54 , & V_57 ,
V_42 , 0 , 1 , 1 , 1 ) ;
V_1 -> V_44 = F_21 ( V_54 , & V_57 ,
V_59 , 2 , 63 , 1 ,
V_45 ) ;
V_1 -> V_30 = F_21 ( V_54 , & V_57 ,
V_60 , 0 , 244 , 1 ,
V_46 ) ;
V_41 -> V_33 = F_21 ( V_54 , & V_57 ,
V_51 , 0 , 1 , 1 , 0 ) ;
if ( V_54 -> error ) {
F_4 ( L_5 ) ;
return V_54 -> error ;
}
F_22 ( 3 , & V_1 -> V_58 , 0 , false ) ;
return 0 ;
}
static int F_23 ( struct V_1 * V_1 )
{
struct V_41 * V_41 = (struct V_41 * ) V_1 ;
V_41 -> V_61 = 0 ;
F_8 ( V_1 , V_62 ,
V_63 , sizeof( V_63 ) ) ;
F_12 ( V_1 , F_24 ( V_41 -> V_56 ) ) ;
F_13 ( V_1 , F_24 ( V_1 -> V_30 ) ) ;
F_14 ( V_1 , F_24 ( V_1 -> V_44 ) ) ;
F_15 ( V_1 , F_24 ( V_41 -> V_33 ) , 1 ) ;
switch ( V_1 -> V_23 . V_24 [ ( int ) V_1 -> V_64 ] . V_65 ) {
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
V_41 -> V_61 = 0 ;
V_41 -> V_47 = 0 ;
F_25 ( & V_41 -> V_66 , - 1 ) ;
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
struct V_41 * V_41 = (struct V_41 * ) V_1 ;
int V_66 = F_28 ( & V_41 -> V_66 ) ;
int V_67 , V_68 ;
if ( V_66 == - 1 )
return;
V_67 = 170 ;
V_68 = 20 ;
if ( V_41 -> V_47 > 0 )
V_41 -> V_47 -- ;
else if ( F_29 ( V_1 , V_66 ,
V_67 , V_68 ) )
V_41 -> V_47 = V_48 ;
}
static void F_30 ( struct V_1 * V_1 ,
T_4 V_69 , T_4 V_70 )
{
unsigned char V_71 [ 4 ] ;
F_31 ( V_1 , V_72 ,
V_73 , sizeof( V_73 ) ) ;
V_71 [ 0 ] = V_69 >> 8 ;
V_71 [ 1 ] = V_69 & 0xff ;
V_71 [ 2 ] = V_70 >> 8 ;
V_71 [ 3 ] = V_70 & 0xff ;
F_31 ( V_1 , V_74 ,
V_71 , sizeof( V_71 ) ) ;
F_31 ( V_1 , V_74 ,
V_75 , sizeof( V_75 ) ) ;
}
static void F_32 ( struct V_1 * V_1 ,
T_2 * V_35 ,
int V_4 )
{
struct V_41 * V_41 = (struct V_41 * ) V_1 ;
T_2 * V_76 ;
unsigned char * V_77 ;
V_77 = F_33 ( V_1 , & V_41 -> V_61 , V_35 , V_4 ) ;
if ( V_77 ) {
int V_78 , V_79 , V_80 ;
V_79 = 24 + sizeof F_34 ;
V_80 = 26 ;
V_78 = ( V_77 - V_35 ) - ( V_80 + sizeof F_34 ) ;
if ( V_78 < 0 ) {
V_1 -> V_81 += V_78 ;
V_78 = 0 ;
} else {
F_31 ( V_1 , V_74 , V_35 , V_78 ) ;
}
V_76 = V_1 -> V_76 ;
if ( V_76 != NULL
&& V_76 [ V_1 -> V_81 - 2 ] == 0xff
&& V_76 [ V_1 -> V_81 - 1 ] == 0xd9 )
F_31 ( V_1 , V_82 , NULL , 0 ) ;
V_78 = V_77 - V_35 ;
V_4 -= V_78 ;
V_35 = V_77 ;
if ( V_1 -> V_83 == V_82 &&
V_78 >= V_79 )
F_25 ( & V_41 -> V_66 , V_35 [ - V_79 ] +
V_35 [ - V_79 + 1 ] ) ;
else
F_25 ( & V_41 -> V_66 , - 1 ) ;
F_30 ( V_1 ,
V_1 -> V_84 , V_1 -> V_32 ) ;
}
F_31 ( V_1 , V_74 , V_35 , V_4 ) ;
}
static int F_35 ( struct V_1 * V_1 ,
T_2 * V_35 ,
int V_4 )
{
int V_5 = - V_52 ;
T_2 V_85 , V_86 ;
if ( V_4 == 2 ) {
V_85 = V_35 [ 0 ] ;
V_86 = V_35 [ 1 ] ;
if ( ( V_85 == 0x00 && V_86 == 0x11 ) ||
( V_85 == 0x22 && V_86 == 0x33 ) ||
( V_85 == 0x44 && V_86 == 0x55 ) ||
( V_85 == 0x66 && V_86 == 0x77 ) ||
( V_85 == 0x88 && V_86 == 0x99 ) ||
( V_85 == 0xaa && V_86 == 0xbb ) ||
( V_85 == 0xcc && V_86 == 0xdd ) ||
( V_85 == 0xee && V_86 == 0xff ) ) {
F_36 ( V_1 -> V_87 , V_88 , 1 ) ;
F_37 ( V_1 -> V_87 ) ;
F_36 ( V_1 -> V_87 , V_88 , 0 ) ;
F_37 ( V_1 -> V_87 ) ;
V_5 = 0 ;
}
}
return V_5 ;
}
static int F_38 ( struct V_89 * V_90 ,
const struct V_21 * V_22 )
{
return F_39 ( V_90 , V_22 , & V_91 , sizeof( struct V_41 ) ,
V_92 ) ;
}
