static void
F_1 ( struct V_1 * V_2 , void * V_3 , T_1 V_4 ,
T_1 V_5 , T_2 V_6 , T_3 V_7 , bool V_8 )
{
T_3 V_9 = V_5 % 4 ;
T_1 V_10 ;
int V_11 ;
V_5 -= V_9 ;
V_10 = V_4 | F_2 ( 24 ) | ( V_8 ? F_2 ( 28 ) : 0 ) ;
F_3 ( V_2 , 0x180 + ( V_7 * 16 ) , V_10 ) ;
for ( V_11 = 0 ; V_11 < V_5 / 4 ; V_11 ++ ) {
if ( ( V_11 & 0x3f ) == 0 )
F_3 ( V_2 , 0x188 , V_6 ++ ) ;
F_3 ( V_2 , 0x184 , ( ( T_1 * ) V_3 ) [ V_11 ] ) ;
}
if ( V_9 ) {
T_1 V_12 = ( ( T_1 * ) V_3 ) [ V_11 ] ;
if ( ( V_11 & 0x3f ) == 0 )
F_3 ( V_2 , 0x188 , V_6 ++ ) ;
F_3 ( V_2 , 0x184 , V_12 & ( F_2 ( V_9 * 8 ) - 1 ) ) ;
++ V_11 ;
}
for (; V_11 & 0x3f ; V_11 ++ )
F_3 ( V_2 , 0x184 , 0 ) ;
}
static void
F_4 ( struct V_1 * V_2 , void * V_3 , T_1 V_4 ,
T_1 V_5 , T_3 V_7 )
{
T_3 V_9 = V_5 % 4 ;
int V_11 ;
V_5 -= V_9 ;
F_3 ( V_2 , 0x1c0 + ( V_7 * 16 ) , V_4 | ( 0x1 << 24 ) ) ;
for ( V_11 = 0 ; V_11 < V_5 / 4 ; V_11 ++ )
F_3 ( V_2 , 0x1c4 , ( ( T_1 * ) V_3 ) [ V_11 ] ) ;
if ( V_9 ) {
T_1 V_12 = ( ( T_1 * ) V_3 ) [ V_11 ] ;
F_3 ( V_2 , 0x1c4 , V_12 & ( F_2 ( V_9 * 8 ) - 1 ) ) ;
}
}
static void
F_5 ( struct V_1 * V_2 , T_1 V_4 , T_1 V_5 ,
T_3 V_7 , void * V_3 )
{
T_3 V_9 = V_5 % 4 ;
int V_11 ;
V_5 -= V_9 ;
F_3 ( V_2 , 0x1c0 + ( V_7 * 16 ) , V_4 | ( 0x1 << 25 ) ) ;
for ( V_11 = 0 ; V_11 < V_5 / 4 ; V_11 ++ )
( ( T_1 * ) V_3 ) [ V_11 ] = F_6 ( V_2 , 0x1c4 ) ;
if ( V_9 ) {
T_1 V_12 = F_6 ( V_2 , 0x1c4 ) ;
for ( V_11 = V_5 ; V_11 < V_5 + V_9 ; V_11 ++ ) {
( ( T_3 * ) V_3 ) [ V_11 ] = ( T_3 ) ( V_12 & 0xff ) ;
V_12 >>= 8 ;
}
}
}
static void
F_7 ( struct V_1 * V_2 , struct V_13 * V_14 )
{
T_1 V_15 ;
if ( V_14 == NULL ) {
F_3 ( V_2 , 0x10c , 0x0 ) ;
return;
}
F_3 ( V_2 , 0x10c , 0x1 ) ;
F_3 ( V_2 , 0xe00 + 4 * V_16 , 0x4 ) ;
F_3 ( V_2 , 0xe00 + 4 * V_17 , 0x0 ) ;
F_3 ( V_2 , 0xe00 + 4 * V_18 , 0x4 ) ;
F_3 ( V_2 , 0xe00 + 4 * V_19 , 0x5 ) ;
F_3 ( V_2 , 0xe00 + 4 * V_20 , 0x6 ) ;
switch ( F_8 ( V_14 -> V_21 ) ) {
case V_22 : V_15 = 0 ; break;
case V_23 : V_15 = 3 ; break;
default:
F_9 ( 1 ) ;
return;
}
F_10 ( V_2 , 0x048 , 0x1 , 0x1 ) ;
F_3 ( V_2 , 0x480 ,
( ( V_14 -> V_24 >> 12 ) & 0xfffffff ) |
( V_15 << 28 ) | ( 1 << 30 ) ) ;
}
static void
F_11 ( struct V_1 * V_2 , T_1 V_25 )
{
F_3 ( V_2 , 0x104 , V_25 ) ;
}
static void
F_12 ( struct V_1 * V_2 )
{
T_1 V_10 = F_6 ( V_2 , 0x100 ) ;
if ( V_10 & F_2 ( 6 ) )
F_3 ( V_2 , 0x130 , 0x2 ) ;
else
F_3 ( V_2 , 0x100 , 0x2 ) ;
}
static int
F_13 ( struct V_1 * V_2 , T_1 V_26 )
{
struct V_27 * V_28 = V_2 -> V_29 -> V_28 ;
int V_30 ;
V_30 = F_14 ( V_28 , V_26 , V_2 -> V_24 + 0x100 , 0x10 , 0x10 ) ;
if ( V_30 < 0 )
return V_30 ;
return 0 ;
}
static int
F_15 ( struct V_1 * V_2 , T_1 V_31 )
{
struct V_27 * V_28 = V_2 -> V_29 -> V_28 ;
int V_30 ;
F_10 ( V_2 , 0x004 , V_31 , V_31 ) ;
V_30 = F_14 ( V_28 , 10 , V_2 -> V_24 + 0x008 , V_31 , 0x0 ) ;
if ( V_30 < 0 )
return V_30 ;
return 0 ;
}
static int
F_16 ( struct V_1 * V_2 )
{
struct V_27 * V_28 = V_2 -> V_29 -> V_28 ;
int V_30 ;
V_30 = F_14 ( V_28 , 10 , V_2 -> V_24 + 0x04c , 0xffff , 0x0 ) ;
if ( V_30 < 0 )
return V_30 ;
return 0 ;
}
static int
F_17 ( struct V_1 * V_2 )
{
struct V_27 * V_28 = V_2 -> V_29 -> V_28 ;
int V_30 ;
V_30 = F_14 ( V_28 , 10 , V_2 -> V_24 + 0x10c , 0x6 , 0x0 ) ;
if ( V_30 < 0 ) {
F_18 ( V_2 -> V_32 , L_1 ) ;
return V_30 ;
}
V_30 = F_16 ( V_2 ) ;
if ( V_30 )
return V_30 ;
F_3 ( V_2 , 0x010 , 0xff ) ;
return 0 ;
}
static void
F_19 ( struct V_1 * V_2 )
{
F_3 ( V_2 , 0x014 , 0xff ) ;
F_16 ( V_2 ) ;
}
int
F_20 ( struct V_33 * V_29 , const char * V_34 , T_1 V_24 ,
struct V_1 * * V_35 )
{
struct V_1 * V_2 ;
if ( ! ( V_2 = * V_35 = F_21 ( sizeof( * V_2 ) , V_36 ) ) )
return - V_37 ;
F_22 ( & V_38 , V_29 , V_34 , V_24 , V_2 ) ;
return 0 ;
}
