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
static void F_6 ( struct V_1 * V_1 )
{
struct V_10 * V_10 = (struct V_10 * ) V_1 ;
V_1 -> V_7 [ 0 ] = 0x61 ;
V_1 -> V_7 [ 1 ] = V_10 -> V_11 [ V_12 ] . V_13 ;
F_1 ( V_1 , 2 ) ;
}
static void F_7 ( struct V_1 * V_1 )
{
struct V_10 * V_10 = (struct V_10 * ) V_1 ;
T_2 V_13 ;
V_13 = V_10 -> V_11 [ V_14 ] . V_13 ;
V_1 -> V_7 [ 0 ] = 0x5f ;
V_1 -> V_7 [ 1 ] = V_13 << 3 ;
V_1 -> V_7 [ 2 ] = ( ( V_13 >> 2 ) & 0xf8 ) | 0x04 ;
F_1 ( V_1 , 3 ) ;
}
static void F_8 ( struct V_1 * V_1 )
{
struct V_10 * V_10 = (struct V_10 * ) V_1 ;
V_1 -> V_7 [ 0 ] = 0x06 ;
V_1 -> V_7 [ 1 ] = V_10 -> V_11 [ GAMMA ] . V_13 * 0x40 ;
F_1 ( V_1 , 2 ) ;
}
static void F_9 ( struct V_1 * V_1 )
{
struct V_10 * V_10 = (struct V_10 * ) V_1 ;
V_1 -> V_7 [ 0 ] = 0x67 ;
V_1 -> V_7 [ 1 ] = V_10 -> V_11 [ V_15 ] . V_13 * 4 + 3 ;
F_1 ( V_1 , 2 ) ;
}
static void F_10 ( struct V_1 * V_1 )
{
struct V_10 * V_10 = (struct V_10 * ) V_1 ;
V_1 -> V_7 [ 0 ] = 0x22 ;
if ( V_10 -> V_11 [ V_16 ] . V_13 )
V_1 -> V_7 [ 1 ] = 0x76 ;
else if ( V_10 -> V_11 [ V_17 ] . V_13 )
V_1 -> V_7 [ 1 ] = 0x7a ;
else
V_1 -> V_7 [ 1 ] = 0x7e ;
F_1 ( V_1 , 2 ) ;
}
static int F_11 ( struct V_1 * V_1 ,
const struct V_18 * V_19 )
{
struct V_10 * V_10 = (struct V_10 * ) V_1 ;
struct V_20 * V_20 ;
V_20 = & V_1 -> V_20 ;
V_20 -> V_21 = V_22 ;
V_20 -> V_23 = F_12 ( V_22 ) ;
V_20 -> V_11 = V_10 -> V_11 ;
V_10 -> V_24 = V_25 ;
return 0 ;
}
static int F_13 ( struct V_1 * V_1 )
{
V_1 -> V_26 = ( 1 << V_16 ) | ( 1 << V_17 ) ;
return 0 ;
}
static int F_14 ( struct V_1 * V_1 )
{
struct V_10 * V_10 = (struct V_10 * ) V_1 ;
T_1 * V_27 ;
int V_28 ;
F_15 ( V_10 -> V_29 , V_1 -> V_30 , V_1 -> V_31 ,
0x21 ) ;
F_16 ( V_10 -> V_29 , V_10 -> V_24 ) ;
V_27 = V_1 -> V_7 ;
V_27 [ 0 ] = 0x01 ;
V_27 [ 1 ] = 0x01 ;
F_1 ( V_1 , 2 ) ;
V_27 [ 0 ] = 0x00 ;
V_27 [ 1 ] = 0x0c | 0x01 ;
V_27 [ 2 ] = 0x01 ;
V_27 [ 3 ] = V_1 -> V_31 / 8 ;
V_27 [ 4 ] = V_1 -> V_30 / 8 ;
V_27 [ 5 ] = 0x30 ;
V_27 [ 6 ] = 0x02 ;
V_27 [ 7 ] = V_10 -> V_11 [ GAMMA ] . V_13 * 0x40 ;
V_27 [ 8 ] = 0x01 ;
V_27 [ 9 ] = 0x52 ;
V_27 [ 10 ] = 0x18 ;
F_1 ( V_1 , 11 ) ;
V_27 [ 0 ] = 0x23 ;
V_27 [ 1 ] = 0x09 ;
F_1 ( V_1 , 2 ) ;
V_27 [ 0 ] = 0x3c ;
V_27 [ 1 ] = 50 ;
F_1 ( V_1 , 2 ) ;
V_27 [ 0 ] = 0x5e ;
V_27 [ 1 ] = 0 ;
V_27 [ 2 ] = V_10 -> V_11 [ V_14 ] . V_13 << 3 ;
V_27 [ 3 ] = ( ( V_10 -> V_11 [ V_14 ] . V_13 >> 2 ) & 0xf8 ) | 0x04 ;
V_27 [ 4 ] = V_10 -> V_11 [ V_12 ] . V_13 ;
V_27 [ 5 ] = 0x00 ;
F_1 ( V_1 , 6 ) ;
V_27 [ 0 ] = 0x67 ;
V_27 [ 1 ] = V_10 -> V_11 [ V_15 ] . V_13 * 4 + 3 ;
V_27 [ 2 ] = 0x14 ;
F_1 ( V_1 , 3 ) ;
V_27 [ 0 ] = 0x69 ;
V_27 [ 1 ] = 0x2f ;
V_27 [ 2 ] = 0x28 ;
V_27 [ 3 ] = 0x42 ;
F_1 ( V_1 , 4 ) ;
V_27 [ 0 ] = 0x63 ;
V_27 [ 1 ] = 0x07 ;
F_1 ( V_1 , 2 ) ;
for ( V_28 = 0 ; V_28 < sizeof F_17 ; V_28 ++ )
F_5 ( V_1 , V_28 + 1 , F_17 [ V_28 ] ) ;
V_27 [ 0 ] = 0x00 ;
V_27 [ 1 ] = 0x4d ;
F_1 ( V_1 , 2 ) ;
V_1 -> V_26 = 0 ;
return V_1 -> V_5 ;
}
static void F_18 ( struct V_1 * V_1 )
{
struct V_10 * V_10 = (struct V_10 * ) V_1 ;
V_1 -> V_26 = ( 1 << V_16 ) | ( 1 << V_17 ) ;
if ( V_10 -> V_11 [ V_16 ] . V_13 || V_10 -> V_11 [ V_17 ] . V_13 ) {
V_10 -> V_11 [ V_16 ] . V_13 = 0 ;
V_10 -> V_11 [ V_17 ] . V_13 = 0 ;
F_10 ( V_1 ) ;
F_19 ( 20 ) ;
}
V_1 -> V_7 [ 0 ] = 1 ;
V_1 -> V_7 [ 1 ] = 0 ;
F_1 ( V_1 , 2 ) ;
}
static void F_20 ( struct V_1 * V_1 ,
T_1 * V_27 ,
int V_2 )
{
struct V_10 * V_10 = (struct V_10 * ) V_1 ;
int V_32 ;
if ( V_2 < 6 ) {
return;
}
for ( V_32 = 0 ; V_32 < V_2 - 6 ; V_32 ++ ) {
if ( V_27 [ 0 + V_32 ] == 0xff
&& V_27 [ 1 + V_32 ] == 0xff
&& V_27 [ 2 + V_32 ] == 0x00
&& V_27 [ 3 + V_32 ] == 0xff
&& V_27 [ 4 + V_32 ] == 0x96 ) {
if ( V_27 [ 5 + V_32 ] == 0x64
|| V_27 [ 5 + V_32 ] == 0x65
|| V_27 [ 5 + V_32 ] == 0x66
|| V_27 [ 5 + V_32 ] == 0x67 ) {
F_21 ( V_33 , L_2 ,
V_32 , V_2 ) ;
F_22 ( V_1 , V_34 ,
V_27 , V_32 ) ;
F_22 ( V_1 , V_35 ,
V_10 -> V_29 , V_36 ) ;
V_27 += V_32 + 16 ;
V_2 -= V_32 + 16 ;
break;
}
}
}
F_22 ( V_1 , V_37 , V_27 , V_2 ) ;
}
static int F_23 ( struct V_1 * V_1 , T_3 V_13 )
{
struct V_10 * V_10 = (struct V_10 * ) V_1 ;
V_10 -> V_11 [ V_16 ] . V_13 = V_13 ;
if ( V_13 )
V_10 -> V_11 [ V_17 ] . V_13 = 0 ;
F_10 ( V_1 ) ;
return V_1 -> V_5 ;
}
static int F_24 ( struct V_1 * V_1 , T_3 V_13 )
{
struct V_10 * V_10 = (struct V_10 * ) V_1 ;
V_10 -> V_11 [ V_17 ] . V_13 = V_13 ;
if ( V_13 )
V_10 -> V_11 [ V_16 ] . V_13 = 0 ;
F_10 ( V_1 ) ;
return V_1 -> V_5 ;
}
static int F_25 ( struct V_1 * V_1 ,
struct V_38 * V_39 )
{
struct V_10 * V_10 = (struct V_10 * ) V_1 ;
if ( V_39 -> V_24 < V_40 )
V_10 -> V_24 = V_40 ;
else if ( V_39 -> V_24 > V_41 )
V_10 -> V_24 = V_41 ;
else
V_10 -> V_24 = V_39 -> V_24 ;
if ( V_1 -> V_42 )
F_16 ( V_10 -> V_29 , V_10 -> V_24 ) ;
return 0 ;
}
static int F_26 ( struct V_1 * V_1 ,
struct V_38 * V_39 )
{
struct V_10 * V_10 = (struct V_10 * ) V_1 ;
memset ( V_39 , 0 , sizeof *V_39 ) ;
V_39 -> V_24 = V_10 -> V_24 ;
V_39 -> V_43 = V_44
| V_45 ;
return 0 ;
}
static int F_27 ( struct V_46 * V_47 ,
const struct V_18 * V_19 )
{
return F_28 ( V_47 , V_19 , & V_48 , sizeof( struct V_10 ) ,
V_49 ) ;
}
