static void
F_1 ( T_1 * V_1 , short V_2 , short V_3 ,
T_2 const V_4 )
{
int V_5 ;
for ( V_5 = 0 ; V_5 < 5 ; V_5 ++ ) {
F_2 ( V_1 -> V_6 , 0x24200 + V_5 * 0x24 , V_4 [ V_5 ] [ 0 ] ) ;
F_2 ( V_1 -> V_6 , 0x24204 + V_5 * 0x24 , V_4 [ V_5 ] [ 1 ] ) ;
F_2 ( V_1 -> V_6 , 0x24208 + V_5 * 0x24 , V_4 [ V_5 ] [ 2 ] ) ;
F_2 ( V_1 -> V_6 , 0x2420c + V_5 * 0x24 , V_4 [ V_5 ] [ 3 ] ) ;
F_2 ( V_1 -> V_6 , 0x24210 + V_5 * 0x24 , V_4 [ V_5 ] [ 4 ] ) ;
}
F_2 ( V_1 -> V_6 , 0x24538 , V_2 & 0xffff ) ;
F_2 ( V_1 -> V_6 , 0x2453C , V_3 & 0xffff ) ;
}
static void
F_3 ( T_1 * V_1 , short V_2 , short V_3 ,
T_2 const V_4 )
{
int V_5 ;
for ( V_5 = 0 ; V_5 < 5 ; V_5 ++ ) {
F_2 ( V_1 -> V_6 , 0x242b4 + V_5 * 0x24 , V_4 [ V_5 ] [ 0 ] ) ;
F_2 ( V_1 -> V_6 , 0x242b8 + V_5 * 0x24 , V_4 [ V_5 ] [ 1 ] ) ;
F_2 ( V_1 -> V_6 , 0x242bc + V_5 * 0x24 , V_4 [ V_5 ] [ 2 ] ) ;
F_2 ( V_1 -> V_6 , 0x242c0 + V_5 * 0x24 , V_4 [ V_5 ] [ 3 ] ) ;
F_2 ( V_1 -> V_6 , 0x242c4 + V_5 * 0x24 , V_4 [ V_5 ] [ 4 ] ) ;
}
F_2 ( V_1 -> V_6 , 0x24540 , V_2 & 0xffff ) ;
F_2 ( V_1 -> V_6 , 0x24544 , V_3 & 0xffff ) ;
}
static void
F_4 ( T_1 * V_1 , short V_2 , short V_3 ,
T_2 const V_4 )
{
int V_5 ;
for ( V_5 = 0 ; V_5 < 5 ; V_5 ++ ) {
F_2 ( V_1 -> V_6 , 0x24368 + V_5 * 0x24 , V_4 [ V_5 ] [ 0 ] ) ;
F_2 ( V_1 -> V_6 , 0x2436c + V_5 * 0x24 , V_4 [ V_5 ] [ 1 ] ) ;
F_2 ( V_1 -> V_6 , 0x24370 + V_5 * 0x24 , V_4 [ V_5 ] [ 2 ] ) ;
F_2 ( V_1 -> V_6 , 0x24374 + V_5 * 0x24 , V_4 [ V_5 ] [ 3 ] ) ;
F_2 ( V_1 -> V_6 , 0x24378 + V_5 * 0x24 , V_4 [ V_5 ] [ 4 ] ) ;
}
F_2 ( V_1 -> V_6 , 0x24548 , V_2 & 0xffff ) ;
F_2 ( V_1 -> V_6 , 0x2454C , V_3 & 0xffff ) ;
}
static void
F_5 ( T_1 * V_1 , short V_2 , short V_3 ,
T_2 const V_4 )
{
int V_5 ;
for ( V_5 = 0 ; V_5 < 5 ; V_5 ++ ) {
F_2 ( V_1 -> V_6 , 0x2441C + V_5 * 0x24 , V_4 [ V_5 ] [ 0 ] ) ;
F_2 ( V_1 -> V_6 , 0x24420 + V_5 * 0x24 , V_4 [ V_5 ] [ 1 ] ) ;
F_2 ( V_1 -> V_6 , 0x24424 + V_5 * 0x24 , V_4 [ V_5 ] [ 2 ] ) ;
F_2 ( V_1 -> V_6 , 0x24428 + V_5 * 0x24 , V_4 [ V_5 ] [ 3 ] ) ;
F_2 ( V_1 -> V_6 , 0x2442C + V_5 * 0x24 , V_4 [ V_5 ] [ 4 ] ) ;
}
F_2 ( V_1 -> V_6 , 0x24550 , V_2 & 0xffff ) ;
F_2 ( V_1 -> V_6 , 0x24554 , V_3 & 0xffff ) ;
}
static void
F_6 ( T_1 * V_1 ,
T_3 const V_2 ,
T_4 const V_4 )
{
int V_5 ;
for ( V_5 = 0 ; V_5 < 5 ; V_5 ++ ) {
F_2 ( V_1 -> V_6 , 0x24214 + V_5 * 0x24 , V_4 [ V_5 ] [ 0 ] ) ;
F_2 ( V_1 -> V_6 , 0x24218 + V_5 * 0x24 , V_4 [ V_5 ] [ 1 ] ) ;
F_2 ( V_1 -> V_6 , 0x2421C + V_5 * 0x24 , V_4 [ V_5 ] [ 2 ] ) ;
F_2 ( V_1 -> V_6 , 0x24220 + V_5 * 0x24 , V_4 [ V_5 ] [ 3 ] ) ;
}
F_2 ( V_1 -> V_6 , 0x244F8 , V_2 [ 0 ] ) ;
F_2 ( V_1 -> V_6 , 0x244FC , V_2 [ 1 ] ) ;
F_2 ( V_1 -> V_6 , 0x24500 , V_2 [ 2 ] ) ;
F_2 ( V_1 -> V_6 , 0x24504 , V_2 [ 3 ] ) ;
}
static void
F_7 ( T_1 * V_1 ,
T_3 const V_2 ,
T_4 const V_4 )
{
int V_5 ;
for ( V_5 = 0 ; V_5 < 5 ; V_5 ++ ) {
F_2 ( V_1 -> V_6 , 0x242C8 + V_5 * 0x24 , V_4 [ V_5 ] [ 0 ] ) ;
F_2 ( V_1 -> V_6 , 0x242CC + V_5 * 0x24 , V_4 [ V_5 ] [ 1 ] ) ;
F_2 ( V_1 -> V_6 , 0x242D0 + V_5 * 0x24 , V_4 [ V_5 ] [ 2 ] ) ;
F_2 ( V_1 -> V_6 , 0x244D4 + V_5 * 0x24 , V_4 [ V_5 ] [ 3 ] ) ;
}
F_2 ( V_1 -> V_6 , 0x24508 , V_2 [ 0 ] ) ;
F_2 ( V_1 -> V_6 , 0x2450C , V_2 [ 1 ] ) ;
F_2 ( V_1 -> V_6 , 0x24510 , V_2 [ 2 ] ) ;
F_2 ( V_1 -> V_6 , 0x24514 , V_2 [ 3 ] ) ;
}
static void
F_8 ( T_1 * V_1 ,
T_3 const V_2 ,
T_4 const V_4 )
{
int V_5 ;
for ( V_5 = 0 ; V_5 < 5 ; V_5 ++ ) {
F_2 ( V_1 -> V_6 , 0x2437C + V_5 * 0x24 , V_4 [ V_5 ] [ 0 ] ) ;
F_2 ( V_1 -> V_6 , 0x24380 + V_5 * 0x24 , V_4 [ V_5 ] [ 1 ] ) ;
F_2 ( V_1 -> V_6 , 0x24384 + V_5 * 0x24 , V_4 [ V_5 ] [ 2 ] ) ;
F_2 ( V_1 -> V_6 , 0x24388 + V_5 * 0x24 , V_4 [ V_5 ] [ 3 ] ) ;
}
F_2 ( V_1 -> V_6 , 0x24518 , V_2 [ 0 ] ) ;
F_2 ( V_1 -> V_6 , 0x2451C , V_2 [ 1 ] ) ;
F_2 ( V_1 -> V_6 , 0x24520 , V_2 [ 2 ] ) ;
F_2 ( V_1 -> V_6 , 0x24524 , V_2 [ 3 ] ) ;
}
static void
F_9 ( T_1 * V_1 ,
T_3 const V_2 ,
T_4 const V_4 )
{
int V_5 ;
for ( V_5 = 0 ; V_5 < 5 ; V_5 ++ ) {
F_2 ( V_1 -> V_6 , 0x24430 + V_5 * 0x24 , V_4 [ V_5 ] [ 0 ] ) ;
F_2 ( V_1 -> V_6 , 0x24434 + V_5 * 0x24 , V_4 [ V_5 ] [ 1 ] ) ;
F_2 ( V_1 -> V_6 , 0x24438 + V_5 * 0x24 , V_4 [ V_5 ] [ 2 ] ) ;
F_2 ( V_1 -> V_6 , 0x2443C + V_5 * 0x24 , V_4 [ V_5 ] [ 3 ] ) ;
}
F_2 ( V_1 -> V_6 , 0x24528 , V_2 [ 0 ] ) ;
F_2 ( V_1 -> V_6 , 0x2452C , V_2 [ 1 ] ) ;
F_2 ( V_1 -> V_6 , 0x24530 , V_2 [ 2 ] ) ;
F_2 ( V_1 -> V_6 , 0x24534 , V_2 [ 3 ] ) ;
}
static void
F_10 ( T_1 * V_1 , T_5 const V_7 )
{
int V_5 ;
for ( V_5 = 0 ; V_5 < V_8 ; V_5 ++ ) {
F_2 ( V_1 -> V_6 , 0x244D0 + ( V_5 * 4 ) , V_7 [ V_5 ] ) ;
}
}
static void
F_11 ( T_1 * V_1 )
{
F_10 ( V_1 , V_9 ) ;
}
static void
F_12 ( T_1 * V_1 , unsigned short V_10 ,
unsigned short V_11 )
{
T_6 V_12 = 0 ;
V_12 &= 0x1FFFFFFF ;
V_12 |= 0xA0000000 ;
V_12 = ( V_12 & 0xffffE0ff ) | ( ( V_10 & 0x1F ) << 8 ) ;
V_12 = ( V_12 & 0xfffc1fff ) | ( ( V_11 & 0x1F ) << 0xd ) ;
F_2 ( V_1 -> V_6 , 0x24660 , V_12 ) ;
}
static void
F_13 ( T_1 * V_1 , T_7 const V_13 )
{
int V_5 ;
for ( V_5 = 0 ; V_5 < 0x20 ; V_5 ++ ) {
F_2 ( V_1 -> V_6 , 0x24000 + ( V_5 << 2 ) , V_13 [ V_5 ] & 0xffff ) ;
F_2 ( V_1 -> V_6 , 0x24080 + ( V_5 << 2 ) , V_13 [ V_5 ] >> 0x10 ) ;
}
}
static void
F_14 ( T_1 * V_1 , T_7 const V_13 )
{
int V_5 ;
for ( V_5 = 0 ; V_5 < 0x20 ; V_5 ++ ) {
F_2 ( V_1 -> V_6 , 0x24100 + ( V_5 << 2 ) , V_13 [ V_5 ] & 0xffff ) ;
F_2 ( V_1 -> V_6 , 0x24180 + ( V_5 << 2 ) , V_13 [ V_5 ] >> 0x10 ) ;
}
}
static void F_15 ( T_1 * V_1 , T_6 V_14 )
{
T_6 V_15 ;
V_15 = ( F_16 ( V_1 -> V_6 , 0x24660 ) & 0x1FFFFFFF ) | 0xC0000000 ;
V_15 = ( V_15 & 0xffffff07 ) | ( ( V_14 & 0x1f ) << 3 ) ;
F_2 ( V_1 -> V_6 , 0x24660 , V_15 ) ;
}
static void F_17 ( T_1 * V_1 )
{
T_6 V_15 ;
V_15 = ( F_16 ( V_1 -> V_6 , 0x24660 ) & 0x1FFFFFFF ) | 0xC0000000 ;
V_15 |= 1 ;
F_2 ( V_1 -> V_6 , 0x24660 , V_15 ) ;
}
static void F_18 ( T_1 * V_1 )
{
T_6 V_15 ;
V_15 = ( F_16 ( V_1 -> V_6 , 0x24660 ) & 0x1FFFFFFF ) | 0xC0000000 ;
V_15 &= 0xfffffffe ;
F_2 ( V_1 -> V_6 , 0x24660 , V_15 ) ;
}
static void F_19 ( T_1 * V_1 )
{
int V_5 ;
for ( V_5 = 0 ; V_5 < 20 ; V_5 ++ )
F_2 ( V_1 -> V_6 , 0x24600 + ( V_5 << 2 ) , 0 ) ;
for ( V_5 = 0 ; V_5 < 4 ; V_5 ++ )
F_2 ( V_1 -> V_6 , 0x24650 + ( V_5 << 2 ) , 0 ) ;
}
static void F_20 ( T_1 * V_1 )
{
F_19 ( V_1 ) ;
F_1 ( V_1 , 0 , 0 , V_16 ) ;
F_3 ( V_1 , 0 , 0 , V_16 ) ;
F_4 ( V_1 , 0 , 0 , V_16 ) ;
F_5 ( V_1 , 0 , 0 , V_16 ) ;
F_10 ( V_1 , V_17 ) ;
F_12 ( V_1 , 0 , 0 ) ;
F_13 ( V_1 , V_18 ) ;
F_14 ( V_1 , V_18 ) ;
F_13 ( V_1 , V_18 ) ;
F_14 ( V_1 , V_18 ) ;
F_6 ( V_1 , V_19 ,
V_20 ) ;
F_7 ( V_1 , V_19 ,
V_20 ) ;
F_8 ( V_1 , V_19 ,
V_20 ) ;
F_9 ( V_1 , V_19 ,
V_20 ) ;
}
static void F_21 ( T_1 * V_1 )
{
F_1 ( V_1 , 0 , 1 , V_21 ) ;
F_3 ( V_1 , 0 , 1 , V_21 ) ;
F_4 ( V_1 , 0 , 0 , V_16 ) ;
F_5 ( V_1 , 0 , 0 , V_16 ) ;
F_12 ( V_1 , 0 , 0 ) ;
}
static void F_22 ( T_1 * V_1 )
{
F_1 ( V_1 , V_22 ,
V_23 , V_24 ) ;
F_3 ( V_1 , V_25 ,
V_26 ,
V_27 ) ;
F_4 ( V_1 , V_28 ,
V_29 , V_30 ) ;
F_5 ( V_1 , V_28 ,
V_29 ,
V_30 ) ;
F_12 ( V_1 , V_31 , V_32 ) ;
}
static void F_23 ( T_1 * V_1 )
{
F_1 ( V_1 , V_33 ,
V_34 ,
V_35 ) ;
F_3 ( V_1 , V_36 ,
V_37 ,
V_38 ) ;
F_4 ( V_1 , V_39 ,
V_40 ,
V_41 ) ;
F_5 ( V_1 , V_39 ,
V_40 ,
V_41 ) ;
F_12 ( V_1 , V_42 , V_43 ) ;
}
static void F_24 ( T_1 * V_1 )
{
F_1 ( V_1 , V_44 ,
V_45 , V_46 ) ;
F_3 ( V_1 , V_47 ,
V_48 , V_49 ) ;
F_4 ( V_1 , V_50 ,
V_51 , V_52 ) ;
F_5 ( V_1 , V_50 ,
V_51 , V_52 ) ;
F_12 ( V_1 , V_53 , V_54 ) ;
}
static void F_25 ( T_1 * V_1 )
{
F_20 ( V_1 ) ;
}
