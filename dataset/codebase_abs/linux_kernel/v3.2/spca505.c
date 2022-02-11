static int F_1 ( struct V_1 * V_2 ,
T_1 V_3 , T_1 V_4 , T_1 V_5 )
{
int V_6 ;
V_6 = F_2 ( V_2 ,
F_3 ( V_2 , 0 ) ,
V_3 ,
V_7 | V_8 ,
V_5 , V_4 , NULL , 0 , 500 ) ;
F_4 ( V_9 , L_1 ,
V_3 , V_4 , V_5 , V_6 ) ;
if ( V_6 < 0 )
F_5 ( L_2 , V_6 ) ;
return V_6 ;
}
static int F_6 ( struct V_10 * V_10 ,
T_1 V_3 ,
T_1 V_4 )
{
int V_6 ;
V_6 = F_2 ( V_10 -> V_2 ,
F_7 ( V_10 -> V_2 , 0 ) ,
V_3 ,
V_11 | V_7 | V_8 ,
0 ,
V_4 ,
V_10 -> V_12 , 2 ,
500 ) ;
if ( V_6 < 0 )
return V_6 ;
return ( V_10 -> V_12 [ 1 ] << 8 ) + V_10 -> V_12 [ 0 ] ;
}
static int F_8 ( struct V_10 * V_10 ,
const T_2 V_13 [] [ 3 ] )
{
struct V_1 * V_2 = V_10 -> V_2 ;
int V_6 , V_14 = 0 ;
while ( V_13 [ V_14 ] [ 0 ] != 0 ) {
V_6 = F_1 ( V_2 , V_13 [ V_14 ] [ 0 ] , V_13 [ V_14 ] [ 2 ] , V_13 [ V_14 ] [ 1 ] ) ;
if ( V_6 < 0 )
return V_6 ;
V_14 ++ ;
}
return 0 ;
}
static int F_9 ( struct V_10 * V_10 ,
const struct V_15 * V_16 )
{
struct V_17 * V_17 = (struct V_17 * ) V_10 ;
struct V_18 * V_18 ;
V_18 = & V_10 -> V_18 ;
V_18 -> V_19 = V_20 ;
V_17 -> V_21 = V_16 -> V_22 ;
if ( V_17 -> V_21 != V_23 )
V_18 -> V_24 = F_10 ( V_20 ) ;
else
V_18 -> V_24 = F_10 ( V_20 ) - 1 ;
V_17 -> V_25 = V_26 ;
return 0 ;
}
static int F_11 ( struct V_10 * V_10 )
{
struct V_17 * V_17 = (struct V_17 * ) V_10 ;
if ( F_8 ( V_10 ,
V_17 -> V_21 == V_27
? V_28
: V_29 ) )
return - V_30 ;
return 0 ;
}
static void F_12 ( struct V_10 * V_10 )
{
struct V_17 * V_17 = (struct V_17 * ) V_10 ;
T_2 V_25 = V_17 -> V_25 ;
F_1 ( V_10 -> V_2 , 0x05 , 0x00 , ( 255 - V_25 ) >> 6 ) ;
F_1 ( V_10 -> V_2 , 0x05 , 0x01 , ( 255 - V_25 ) << 2 ) ;
}
static int F_13 ( struct V_10 * V_10 )
{
struct V_17 * V_17 = (struct V_17 * ) V_10 ;
struct V_1 * V_2 = V_10 -> V_2 ;
int V_6 , V_31 ;
static T_2 V_32 [] [ 3 ] = {
{ 0x00 , 0x10 , 0x10 } ,
{ 0x01 , 0x1a , 0x1a } ,
{ 0x02 , 0x1c , 0x1d } ,
{ 0x04 , 0x34 , 0x34 } ,
{ 0x05 , 0x40 , 0x40 }
} ;
if ( V_17 -> V_21 == V_27 )
F_8 ( V_10 , V_33 ) ;
else
F_8 ( V_10 , V_34 ) ;
V_6 = F_6 ( V_10 , 0x06 , 0x16 ) ;
if ( V_6 < 0 ) {
F_4 ( V_35 | V_36 ,
L_3 ,
V_6 ) ;
return V_6 ;
}
if ( V_6 != 0x0101 ) {
F_5 ( L_4 ,
V_6 ) ;
}
V_6 = F_1 ( V_10 -> V_2 , 0x06 , 0x16 , 0x0a ) ;
if ( V_6 < 0 )
return V_6 ;
F_1 ( V_10 -> V_2 , 0x05 , 0xc2 , 0x12 ) ;
F_1 ( V_2 , 0x02 , 0x00 , 0x00 ) ;
V_31 = V_10 -> V_18 . V_19 [ ( int ) V_10 -> V_37 ] . V_38 ;
F_1 ( V_2 , V_39 , 0x00 , V_32 [ V_31 ] [ 0 ] ) ;
F_1 ( V_2 , V_39 , 0x06 , V_32 [ V_31 ] [ 1 ] ) ;
F_1 ( V_2 , V_39 , 0x07 , V_32 [ V_31 ] [ 2 ] ) ;
V_6 = F_1 ( V_2 , V_40 ,
V_41 ,
V_42 ) ;
F_12 ( V_10 ) ;
return V_6 ;
}
static void F_14 ( struct V_10 * V_10 )
{
F_1 ( V_10 -> V_2 , 0x02 , 0x00 , 0x00 ) ;
}
static void F_15 ( struct V_10 * V_10 )
{
if ( ! V_10 -> V_43 )
return;
F_1 ( V_10 -> V_2 , 0x03 , 0x03 , 0x20 ) ;
F_1 ( V_10 -> V_2 , 0x03 , 0x01 , 0x00 ) ;
F_1 ( V_10 -> V_2 , 0x03 , 0x00 , 0x01 ) ;
F_1 ( V_10 -> V_2 , 0x05 , 0x10 , 0x01 ) ;
F_1 ( V_10 -> V_2 , 0x05 , 0x11 , 0x0f ) ;
}
static void F_16 ( struct V_10 * V_10 ,
T_2 * V_13 ,
int V_44 )
{
switch ( V_13 [ 0 ] ) {
case 0 :
F_17 ( V_10 , V_45 , NULL , 0 ) ;
V_13 += V_46 ;
V_44 -= V_46 ;
F_17 ( V_10 , V_47 , V_13 , V_44 ) ;
break;
case 0xff :
break;
default:
V_13 += 1 ;
V_44 -= 1 ;
F_17 ( V_10 , V_48 , V_13 , V_44 ) ;
break;
}
}
static int F_18 ( struct V_10 * V_10 , T_3 V_49 )
{
struct V_17 * V_17 = (struct V_17 * ) V_10 ;
V_17 -> V_25 = V_49 ;
if ( V_10 -> V_50 )
F_12 ( V_10 ) ;
return 0 ;
}
static int F_19 ( struct V_10 * V_10 , T_3 * V_49 )
{
struct V_17 * V_17 = (struct V_17 * ) V_10 ;
* V_49 = V_17 -> V_25 ;
return 0 ;
}
static int F_20 ( struct V_51 * V_52 ,
const struct V_15 * V_16 )
{
return F_21 ( V_52 , V_16 , & V_53 , sizeof( struct V_17 ) ,
V_54 ) ;
}
static int T_4 F_22 ( void )
{
return F_23 ( & V_55 ) ;
}
static void T_5 F_24 ( void )
{
F_25 ( & V_55 ) ;
}
