static int F_1 ( struct V_1 * V_1 ,
T_1 V_2 , T_1 V_3 , T_1 V_4 )
{
int V_5 ;
struct V_6 * V_7 = V_1 -> V_7 ;
V_5 = F_2 ( V_7 ,
F_3 ( V_7 , 0 ) ,
V_2 ,
V_8 | V_9 ,
V_4 , V_3 , NULL , 0 , 500 ) ;
F_4 ( V_10 , L_1 ,
V_2 , V_3 , V_4 , V_5 ) ;
if ( V_5 < 0 )
F_5 ( L_2 , V_5 ) ;
return V_5 ;
}
static int F_6 ( struct V_1 * V_1 ,
T_1 V_2 ,
T_1 V_3 )
{
int V_5 ;
V_5 = F_2 ( V_1 -> V_7 ,
F_7 ( V_1 -> V_7 , 0 ) ,
V_2 ,
V_11 | V_8 | V_9 ,
0 ,
V_3 ,
V_1 -> V_12 , 2 ,
500 ) ;
if ( V_5 < 0 )
return V_5 ;
return ( V_1 -> V_12 [ 1 ] << 8 ) + V_1 -> V_12 [ 0 ] ;
}
static int F_8 ( struct V_1 * V_1 ,
const T_2 V_13 [] [ 3 ] )
{
int V_5 , V_14 = 0 ;
while ( V_13 [ V_14 ] [ 0 ] != 0 ) {
V_5 = F_1 ( V_1 , V_13 [ V_14 ] [ 0 ] , V_13 [ V_14 ] [ 2 ] ,
V_13 [ V_14 ] [ 1 ] ) ;
if ( V_5 < 0 )
return V_5 ;
V_14 ++ ;
}
return 0 ;
}
static int F_9 ( struct V_1 * V_1 ,
const struct V_15 * V_16 )
{
struct V_17 * V_17 = (struct V_17 * ) V_1 ;
struct V_18 * V_18 ;
V_18 = & V_1 -> V_18 ;
V_18 -> V_19 = V_20 ;
V_17 -> V_21 = V_16 -> V_22 ;
if ( V_17 -> V_21 != V_23 )
V_18 -> V_24 = F_10 ( V_20 ) ;
else
V_18 -> V_24 = F_10 ( V_20 ) - 1 ;
return 0 ;
}
static int F_11 ( struct V_1 * V_1 )
{
struct V_17 * V_17 = (struct V_17 * ) V_1 ;
if ( F_8 ( V_1 ,
V_17 -> V_21 == V_25
? V_26
: V_27 ) )
return - V_28 ;
return 0 ;
}
static void F_12 ( struct V_1 * V_1 , T_3 V_29 )
{
F_1 ( V_1 , 0x05 , 0x00 , ( 255 - V_29 ) >> 6 ) ;
F_1 ( V_1 , 0x05 , 0x01 , ( 255 - V_29 ) << 2 ) ;
}
static int F_13 ( struct V_1 * V_1 )
{
struct V_17 * V_17 = (struct V_17 * ) V_1 ;
int V_5 , V_30 ;
static T_2 V_31 [] [ 3 ] = {
{ 0x00 , 0x10 , 0x10 } ,
{ 0x01 , 0x1a , 0x1a } ,
{ 0x02 , 0x1c , 0x1d } ,
{ 0x04 , 0x34 , 0x34 } ,
{ 0x05 , 0x40 , 0x40 }
} ;
if ( V_17 -> V_21 == V_25 )
F_8 ( V_1 , V_32 ) ;
else
F_8 ( V_1 , V_33 ) ;
V_5 = F_6 ( V_1 , 0x06 , 0x16 ) ;
if ( V_5 < 0 ) {
F_14 ( L_3 , V_5 ) ;
return V_5 ;
}
if ( V_5 != 0x0101 ) {
F_5 ( L_4 ,
V_5 ) ;
}
V_5 = F_1 ( V_1 , 0x06 , 0x16 , 0x0a ) ;
if ( V_5 < 0 )
return V_5 ;
F_1 ( V_1 , 0x05 , 0xc2 , 0x12 ) ;
F_1 ( V_1 , 0x02 , 0x00 , 0x00 ) ;
V_30 = V_1 -> V_18 . V_19 [ ( int ) V_1 -> V_34 ] . V_35 ;
F_1 ( V_1 , V_36 , 0x00 , V_31 [ V_30 ] [ 0 ] ) ;
F_1 ( V_1 , V_36 , 0x06 , V_31 [ V_30 ] [ 1 ] ) ;
F_1 ( V_1 , V_36 , 0x07 , V_31 [ V_30 ] [ 2 ] ) ;
return F_1 ( V_1 , V_37 ,
V_38 ,
V_39 ) ;
}
static void F_15 ( struct V_1 * V_1 )
{
F_1 ( V_1 , 0x02 , 0x00 , 0x00 ) ;
}
static void F_16 ( struct V_1 * V_1 )
{
if ( ! V_1 -> V_40 )
return;
F_1 ( V_1 , 0x03 , 0x03 , 0x20 ) ;
F_1 ( V_1 , 0x03 , 0x01 , 0x00 ) ;
F_1 ( V_1 , 0x03 , 0x00 , 0x01 ) ;
F_1 ( V_1 , 0x05 , 0x10 , 0x01 ) ;
F_1 ( V_1 , 0x05 , 0x11 , 0x0f ) ;
}
static void F_17 ( struct V_1 * V_1 ,
T_2 * V_13 ,
int V_41 )
{
switch ( V_13 [ 0 ] ) {
case 0 :
F_18 ( V_1 , V_42 , NULL , 0 ) ;
V_13 += V_43 ;
V_41 -= V_43 ;
F_18 ( V_1 , V_44 , V_13 , V_41 ) ;
break;
case 0xff :
break;
default:
V_13 += 1 ;
V_41 -= 1 ;
F_18 ( V_1 , V_45 , V_13 , V_41 ) ;
break;
}
}
static int F_19 ( struct V_46 * V_47 )
{
struct V_1 * V_1 =
F_20 ( V_47 -> V_48 , struct V_1 , V_49 ) ;
V_1 -> V_50 = 0 ;
if ( ! V_1 -> V_51 )
return 0 ;
switch ( V_47 -> V_16 ) {
case V_52 :
F_12 ( V_1 , V_47 -> V_53 ) ;
break;
}
return V_1 -> V_50 ;
}
static int F_21 ( struct V_1 * V_1 )
{
struct V_54 * V_55 = & V_1 -> V_49 ;
V_1 -> V_56 . V_49 = V_55 ;
F_22 ( V_55 , 5 ) ;
F_23 ( V_55 , & V_57 ,
V_52 , 0 , 255 , 1 , 127 ) ;
if ( V_55 -> error ) {
F_5 ( L_5 ) ;
return V_55 -> error ;
}
return 0 ;
}
static int F_24 ( struct V_58 * V_59 ,
const struct V_15 * V_16 )
{
return F_25 ( V_59 , V_16 , & V_60 , sizeof( struct V_17 ) ,
V_61 ) ;
}
