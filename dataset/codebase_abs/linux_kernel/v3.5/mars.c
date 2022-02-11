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
case V_28 :
F_13 ( V_17 -> V_29 , V_14 -> V_10 ) ;
break;
default:
return - V_30 ;
}
return V_1 -> V_5 ;
}
static int F_14 ( struct V_1 * V_1 )
{
struct V_17 * V_17 = (struct V_17 * ) V_1 ;
struct V_31 * V_32 = & V_1 -> V_16 ;
V_1 -> V_33 . V_16 = V_32 ;
F_15 ( V_32 , 7 ) ;
V_17 -> V_34 = F_16 ( V_32 , & V_35 ,
V_24 , 0 , 30 , 1 , 15 ) ;
V_17 -> V_36 = F_16 ( V_32 , & V_35 ,
V_25 , 0 , 255 , 1 , 200 ) ;
V_17 -> gamma = F_16 ( V_32 , & V_35 ,
V_26 , 0 , 3 , 1 , 1 ) ;
V_17 -> V_37 = F_16 ( V_32 , & V_35 ,
V_27 , 0 , 2 , 1 , 1 ) ;
V_17 -> V_22 = F_16 ( V_32 , & V_35 ,
V_19 , 0 , 1 , 1 , 0 ) ;
V_17 -> V_22 -> V_38 |= V_39 ;
V_17 -> V_21 = F_16 ( V_32 , & V_35 ,
V_40 , 0 , 1 , 1 , 0 ) ;
V_17 -> V_21 -> V_38 |= V_39 ;
V_17 -> V_41 = F_16 ( V_32 , & V_35 ,
V_28 ,
V_42 , V_43 , 1 , V_44 ) ;
if ( V_32 -> error ) {
F_4 ( L_2 ) ;
return V_32 -> error ;
}
F_17 ( 2 , & V_17 -> V_22 ) ;
return 0 ;
}
static int F_18 ( struct V_1 * V_1 ,
const struct V_45 * V_18 )
{
struct V_17 * V_17 = (struct V_17 * ) V_1 ;
struct V_46 * V_46 ;
V_46 = & V_1 -> V_46 ;
V_46 -> V_47 = V_48 ;
V_46 -> V_49 = F_19 ( V_48 ) ;
V_17 -> V_50 = V_44 ;
return 0 ;
}
static int F_20 ( struct V_1 * V_1 )
{
return 0 ;
}
static int F_21 ( struct V_1 * V_1 )
{
struct V_17 * V_17 = (struct V_17 * ) V_1 ;
T_1 * V_51 ;
int V_52 ;
F_22 ( V_17 -> V_29 , V_1 -> V_53 , V_1 -> V_54 ,
0x21 ) ;
F_13 ( V_17 -> V_29 , F_23 ( V_17 -> V_41 ) ) ;
V_51 = V_1 -> V_7 ;
V_51 [ 0 ] = 0x01 ;
V_51 [ 1 ] = 0x01 ;
F_1 ( V_1 , 2 ) ;
V_51 [ 0 ] = 0x00 ;
V_51 [ 1 ] = 0x0c | 0x01 ;
V_51 [ 2 ] = 0x01 ;
V_51 [ 3 ] = V_1 -> V_54 / 8 ;
V_51 [ 4 ] = V_1 -> V_53 / 8 ;
V_51 [ 5 ] = 0x30 ;
V_51 [ 6 ] = 0x02 ;
V_51 [ 7 ] = F_23 ( V_17 -> gamma ) * 0x40 ;
V_51 [ 8 ] = 0x01 ;
V_51 [ 9 ] = 0x52 ;
V_51 [ 10 ] = 0x18 ;
F_1 ( V_1 , 11 ) ;
V_51 [ 0 ] = 0x23 ;
V_51 [ 1 ] = 0x09 ;
F_1 ( V_1 , 2 ) ;
V_51 [ 0 ] = 0x3c ;
V_51 [ 1 ] = 50 ;
F_1 ( V_1 , 2 ) ;
V_51 [ 0 ] = 0x5e ;
V_51 [ 1 ] = 0 ;
V_51 [ 2 ] = F_23 ( V_17 -> V_36 ) << 3 ;
V_51 [ 3 ] = ( ( F_23 ( V_17 -> V_36 ) >> 2 ) & 0xf8 ) | 0x04 ;
V_51 [ 4 ] = F_23 ( V_17 -> V_34 ) ;
V_51 [ 5 ] = 0x00 ;
F_1 ( V_1 , 6 ) ;
V_51 [ 0 ] = 0x67 ;
V_51 [ 1 ] = F_23 ( V_17 -> V_37 ) * 4 + 3 ;
V_51 [ 2 ] = 0x14 ;
F_1 ( V_1 , 3 ) ;
V_51 [ 0 ] = 0x69 ;
V_51 [ 1 ] = 0x2f ;
V_51 [ 2 ] = 0x28 ;
V_51 [ 3 ] = 0x42 ;
F_1 ( V_1 , 4 ) ;
V_51 [ 0 ] = 0x63 ;
V_51 [ 1 ] = 0x07 ;
F_1 ( V_1 , 2 ) ;
for ( V_52 = 0 ; V_52 < sizeof F_24 ; V_52 ++ )
F_5 ( V_1 , V_52 + 1 , F_24 [ V_52 ] ) ;
V_51 [ 0 ] = 0x00 ;
V_51 [ 1 ] = 0x4d ;
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
T_1 * V_51 ,
int V_2 )
{
struct V_17 * V_17 = (struct V_17 * ) V_1 ;
int V_55 ;
if ( V_2 < 6 ) {
return;
}
for ( V_55 = 0 ; V_55 < V_2 - 6 ; V_55 ++ ) {
if ( V_51 [ 0 + V_55 ] == 0xff
&& V_51 [ 1 + V_55 ] == 0xff
&& V_51 [ 2 + V_55 ] == 0x00
&& V_51 [ 3 + V_55 ] == 0xff
&& V_51 [ 4 + V_55 ] == 0x96 ) {
if ( V_51 [ 5 + V_55 ] == 0x64
|| V_51 [ 5 + V_55 ] == 0x65
|| V_51 [ 5 + V_55 ] == 0x66
|| V_51 [ 5 + V_55 ] == 0x67 ) {
F_28 ( V_56 , L_3 ,
V_55 , V_2 ) ;
F_29 ( V_1 , V_57 ,
V_51 , V_55 ) ;
F_29 ( V_1 , V_58 ,
V_17 -> V_29 , V_59 ) ;
V_51 += V_55 + 16 ;
V_2 -= V_55 + 16 ;
break;
}
}
}
F_29 ( V_1 , V_60 , V_51 , V_2 ) ;
}
static int F_30 ( struct V_1 * V_1 ,
struct V_61 * V_62 )
{
struct V_17 * V_17 = (struct V_17 * ) V_1 ;
int V_4 ;
V_4 = F_31 ( V_17 -> V_41 , V_62 -> V_50 ) ;
if ( V_4 )
return V_4 ;
V_62 -> V_50 = F_23 ( V_17 -> V_41 ) ;
return 0 ;
}
static int F_32 ( struct V_1 * V_1 ,
struct V_61 * V_62 )
{
struct V_17 * V_17 = (struct V_17 * ) V_1 ;
memset ( V_62 , 0 , sizeof *V_62 ) ;
V_62 -> V_50 = F_23 ( V_17 -> V_41 ) ;
V_62 -> V_63 = V_64
| V_65 ;
return 0 ;
}
static int F_33 ( struct V_66 * V_67 ,
const struct V_45 * V_18 )
{
return F_34 ( V_67 , V_18 , & V_68 , sizeof( struct V_17 ) ,
V_69 ) ;
}
