static void F_1 ( struct V_1 * V_1 ,
int V_2 )
{
int V_3 , V_4 ;
if ( V_1 -> V_5 < 0 )
return;
V_4 = F_2 ( V_1 -> V_6 ,
F_3 ( V_1 -> V_6 , 4 ) ,
V_1 -> V_7 ,
V_2 ,
& V_3 ,
500 ) ;
if ( V_4 < 0 ) {
F_4 ( L_1 ,
V_1 -> V_7 [ 0 ] , V_4 ) ;
V_1 -> V_5 = V_4 ;
}
}
static void F_5 ( struct V_1 * V_1 ,
T_1 V_8 ,
T_1 V_9 )
{
V_1 -> V_7 [ 0 ] = 0x1f ;
V_1 -> V_7 [ 1 ] = 0 ;
V_1 -> V_7 [ 2 ] = V_8 ;
V_1 -> V_7 [ 3 ] = V_9 ;
F_1 ( V_1 , 4 ) ;
}
static void F_6 ( struct V_1 * V_1 , T_2 V_10 )
{
V_1 -> V_7 [ 0 ] = 0x61 ;
V_1 -> V_7 [ 1 ] = V_10 ;
F_1 ( V_1 , 2 ) ;
}
static void F_7 ( struct V_1 * V_1 , T_2 V_10 )
{
V_1 -> V_7 [ 0 ] = 0x5f ;
V_1 -> V_7 [ 1 ] = V_10 << 3 ;
V_1 -> V_7 [ 2 ] = ( ( V_10 >> 2 ) & 0xf8 ) | 0x04 ;
F_1 ( V_1 , 3 ) ;
}
static void F_8 ( struct V_1 * V_1 , T_2 V_10 )
{
V_1 -> V_7 [ 0 ] = 0x06 ;
V_1 -> V_7 [ 1 ] = V_10 * 0x40 ;
F_1 ( V_1 , 2 ) ;
}
static void F_9 ( struct V_1 * V_1 , T_2 V_10 )
{
V_1 -> V_7 [ 0 ] = 0x67 ;
V_1 -> V_7 [ 1 ] = V_10 * 4 + 3 ;
F_1 ( V_1 , 2 ) ;
}
static void F_10 ( struct V_1 * V_1 , bool V_11 , bool V_12 )
{
V_1 -> V_7 [ 0 ] = 0x22 ;
if ( V_11 )
V_1 -> V_7 [ 1 ] = 0x76 ;
else if ( V_12 )
V_1 -> V_7 [ 1 ] = 0x7a ;
else
V_1 -> V_7 [ 1 ] = 0x7e ;
F_1 ( V_1 , 2 ) ;
}
static int F_11 ( struct V_13 * V_14 )
{
struct V_1 * V_1 =
F_12 ( V_14 -> V_15 , struct V_1 , V_16 ) ;
struct V_17 * V_17 = (struct V_17 * ) V_1 ;
V_1 -> V_5 = 0 ;
if ( V_14 -> V_18 == V_19 ) {
if ( V_14 -> V_20 && V_14 -> V_10 )
V_17 -> V_21 -> V_10 = 0 ;
if ( V_17 -> V_21 -> V_20 && V_17 -> V_21 -> V_10 )
V_17 -> V_22 -> V_10 = 0 ;
}
if ( ! V_1 -> V_23 )
return 0 ;
switch ( V_14 -> V_18 ) {
case V_24 :
F_6 ( V_1 , V_14 -> V_10 ) ;
break;
case V_25 :
F_7 ( V_1 , V_14 -> V_10 ) ;
break;
case V_26 :
F_8 ( V_1 , V_14 -> V_10 ) ;
break;
case V_19 :
F_10 ( V_1 , V_17 -> V_22 -> V_10 ,
V_17 -> V_21 -> V_10 ) ;
break;
case V_27 :
F_9 ( V_1 , V_14 -> V_10 ) ;
break;
default:
return - V_28 ;
}
return V_1 -> V_5 ;
}
static int F_13 ( struct V_1 * V_1 )
{
struct V_17 * V_17 = (struct V_17 * ) V_1 ;
struct V_29 * V_30 = & V_1 -> V_16 ;
V_1 -> V_31 . V_16 = V_30 ;
F_14 ( V_30 , 6 ) ;
V_17 -> V_32 = F_15 ( V_30 , & V_33 ,
V_24 , 0 , 30 , 1 , 15 ) ;
V_17 -> V_34 = F_15 ( V_30 , & V_33 ,
V_25 , 0 , 255 , 1 , 200 ) ;
V_17 -> gamma = F_15 ( V_30 , & V_33 ,
V_26 , 0 , 3 , 1 , 1 ) ;
V_17 -> V_35 = F_15 ( V_30 , & V_33 ,
V_27 , 0 , 2 , 1 , 1 ) ;
V_17 -> V_22 = F_15 ( V_30 , & V_33 ,
V_19 , 0 , 1 , 1 , 0 ) ;
V_17 -> V_22 -> V_36 |= V_37 ;
V_17 -> V_21 = F_15 ( V_30 , & V_33 ,
V_38 , 0 , 1 , 1 , 0 ) ;
V_17 -> V_21 -> V_36 |= V_37 ;
if ( V_30 -> error ) {
F_4 ( L_2 ) ;
return V_30 -> error ;
}
F_16 ( 2 , & V_17 -> V_22 ) ;
return 0 ;
}
static int F_17 ( struct V_1 * V_1 ,
const struct V_39 * V_18 )
{
struct V_40 * V_40 ;
V_40 = & V_1 -> V_40 ;
V_40 -> V_41 = V_42 ;
V_40 -> V_43 = F_18 ( V_42 ) ;
return 0 ;
}
static int F_19 ( struct V_1 * V_1 )
{
return 0 ;
}
static int F_20 ( struct V_1 * V_1 )
{
struct V_17 * V_17 = (struct V_17 * ) V_1 ;
T_1 * V_44 ;
int V_45 ;
F_21 ( V_17 -> V_46 , V_1 -> V_47 , V_1 -> V_48 ,
0x21 ) ;
F_22 ( V_17 -> V_46 , V_49 ) ;
V_44 = V_1 -> V_7 ;
V_44 [ 0 ] = 0x01 ;
V_44 [ 1 ] = 0x01 ;
F_1 ( V_1 , 2 ) ;
V_44 [ 0 ] = 0x00 ;
V_44 [ 1 ] = 0x0c | 0x01 ;
V_44 [ 2 ] = 0x01 ;
V_44 [ 3 ] = V_1 -> V_48 / 8 ;
V_44 [ 4 ] = V_1 -> V_47 / 8 ;
V_44 [ 5 ] = 0x30 ;
V_44 [ 6 ] = 0x02 ;
V_44 [ 7 ] = F_23 ( V_17 -> gamma ) * 0x40 ;
V_44 [ 8 ] = 0x01 ;
V_44 [ 9 ] = 0x52 ;
V_44 [ 10 ] = 0x18 ;
F_1 ( V_1 , 11 ) ;
V_44 [ 0 ] = 0x23 ;
V_44 [ 1 ] = 0x09 ;
F_1 ( V_1 , 2 ) ;
V_44 [ 0 ] = 0x3c ;
V_44 [ 1 ] = 50 ;
F_1 ( V_1 , 2 ) ;
V_44 [ 0 ] = 0x5e ;
V_44 [ 1 ] = 0 ;
V_44 [ 2 ] = F_23 ( V_17 -> V_34 ) << 3 ;
V_44 [ 3 ] = ( ( F_23 ( V_17 -> V_34 ) >> 2 ) & 0xf8 ) | 0x04 ;
V_44 [ 4 ] = F_23 ( V_17 -> V_32 ) ;
V_44 [ 5 ] = 0x00 ;
F_1 ( V_1 , 6 ) ;
V_44 [ 0 ] = 0x67 ;
V_44 [ 1 ] = F_23 ( V_17 -> V_35 ) * 4 + 3 ;
V_44 [ 2 ] = 0x14 ;
F_1 ( V_1 , 3 ) ;
V_44 [ 0 ] = 0x69 ;
V_44 [ 1 ] = 0x2f ;
V_44 [ 2 ] = 0x28 ;
V_44 [ 3 ] = 0x42 ;
F_1 ( V_1 , 4 ) ;
V_44 [ 0 ] = 0x63 ;
V_44 [ 1 ] = 0x07 ;
F_1 ( V_1 , 2 ) ;
for ( V_45 = 0 ; V_45 < sizeof F_24 ; V_45 ++ )
F_5 ( V_1 , V_45 + 1 , F_24 [ V_45 ] ) ;
V_44 [ 0 ] = 0x00 ;
V_44 [ 1 ] = 0x4d ;
F_1 ( V_1 , 2 ) ;
F_10 ( V_1 , F_23 ( V_17 -> V_22 ) ,
F_23 ( V_17 -> V_21 ) ) ;
return V_1 -> V_5 ;
}
static void F_25 ( struct V_1 * V_1 )
{
struct V_17 * V_17 = (struct V_17 * ) V_1 ;
if ( F_23 ( V_17 -> V_22 ) ||
F_23 ( V_17 -> V_21 ) ) {
F_10 ( V_1 , false , false ) ;
F_26 ( 20 ) ;
}
V_1 -> V_7 [ 0 ] = 1 ;
V_1 -> V_7 [ 1 ] = 0 ;
F_1 ( V_1 , 2 ) ;
}
static void F_27 ( struct V_1 * V_1 ,
T_1 * V_44 ,
int V_2 )
{
struct V_17 * V_17 = (struct V_17 * ) V_1 ;
int V_50 ;
if ( V_2 < 6 ) {
return;
}
for ( V_50 = 0 ; V_50 < V_2 - 6 ; V_50 ++ ) {
if ( V_44 [ 0 + V_50 ] == 0xff
&& V_44 [ 1 + V_50 ] == 0xff
&& V_44 [ 2 + V_50 ] == 0x00
&& V_44 [ 3 + V_50 ] == 0xff
&& V_44 [ 4 + V_50 ] == 0x96 ) {
if ( V_44 [ 5 + V_50 ] == 0x64
|| V_44 [ 5 + V_50 ] == 0x65
|| V_44 [ 5 + V_50 ] == 0x66
|| V_44 [ 5 + V_50 ] == 0x67 ) {
F_28 ( V_51 , L_3 ,
V_50 , V_2 ) ;
F_29 ( V_1 , V_52 ,
V_44 , V_50 ) ;
F_29 ( V_1 , V_53 ,
V_17 -> V_46 , V_54 ) ;
V_44 += V_50 + 16 ;
V_2 -= V_50 + 16 ;
break;
}
}
}
F_29 ( V_1 , V_55 , V_44 , V_2 ) ;
}
static int F_30 ( struct V_56 * V_57 ,
const struct V_39 * V_18 )
{
return F_31 ( V_57 , V_18 , & V_58 , sizeof( struct V_17 ) ,
V_59 ) ;
}
