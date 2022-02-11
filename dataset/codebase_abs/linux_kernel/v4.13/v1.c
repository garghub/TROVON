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
F_3 ( V_2 , 0x188 + ( V_7 * 16 ) , V_6 ++ ) ;
F_3 ( V_2 , 0x184 + ( V_7 * 16 ) , ( ( T_1 * ) V_3 ) [ V_11 ] ) ;
}
if ( V_9 ) {
T_1 V_12 = ( ( T_1 * ) V_3 ) [ V_11 ] ;
if ( ( V_11 & 0x3f ) == 0 )
F_3 ( V_2 , 0x188 + ( V_7 * 16 ) , V_6 ++ ) ;
F_3 ( V_2 , 0x184 + ( V_7 * 16 ) ,
V_12 & ( F_2 ( V_9 * 8 ) - 1 ) ) ;
++ V_11 ;
}
for (; V_11 & 0x3f ; V_11 ++ )
F_3 ( V_2 , 0x184 + ( V_7 * 16 ) , 0 ) ;
}
static void
F_4 ( struct V_1 * V_2 , void * V_3 , T_1 V_4 ,
T_1 V_5 , T_3 V_7 )
{
T_3 V_9 = V_5 % 4 ;
int V_11 ;
V_5 -= V_9 ;
F_3 ( V_2 , 0xac0 + ( V_7 * 8 ) , V_4 | ( 0x1 << 24 ) ) ;
for ( V_11 = 0 ; V_11 < V_5 / 4 ; V_11 ++ )
F_3 ( V_2 , 0xac4 + ( V_7 * 8 ) , ( ( T_1 * ) V_3 ) [ V_11 ] ) ;
if ( V_9 ) {
T_1 V_12 = ( ( T_1 * ) V_3 ) [ V_11 ] ;
F_3 ( V_2 , 0xac4 + ( V_7 * 8 ) ,
V_12 & ( F_2 ( V_9 * 8 ) - 1 ) ) ;
}
}
static void
F_5 ( struct V_1 * V_2 , void * V_3 , T_1 V_4 ,
T_1 V_5 , T_3 V_7 )
{
T_3 V_9 = V_5 % 4 ;
int V_11 ;
if ( V_4 >= V_13 && V_2 -> V_14 )
return F_4 ( V_2 , V_3 ,
V_4 - V_13 , V_5 ,
V_7 ) ;
V_5 -= V_9 ;
F_3 ( V_2 , 0x1c0 + ( V_7 * 8 ) , V_4 | ( 0x1 << 24 ) ) ;
for ( V_11 = 0 ; V_11 < V_5 / 4 ; V_11 ++ )
F_3 ( V_2 , 0x1c4 + ( V_7 * 8 ) , ( ( T_1 * ) V_3 ) [ V_11 ] ) ;
if ( V_9 ) {
T_1 V_12 = ( ( T_1 * ) V_3 ) [ V_11 ] ;
F_3 ( V_2 , 0x1c4 + ( V_7 * 8 ) ,
V_12 & ( F_2 ( V_9 * 8 ) - 1 ) ) ;
}
}
static void
F_6 ( struct V_1 * V_2 , T_1 V_4 , T_1 V_5 ,
T_3 V_7 , void * V_3 )
{
T_3 V_9 = V_5 % 4 ;
int V_11 ;
V_5 -= V_9 ;
F_3 ( V_2 , 0xac0 + ( V_7 * 8 ) , V_4 | ( 0x1 << 25 ) ) ;
for ( V_11 = 0 ; V_11 < V_5 / 4 ; V_11 ++ )
( ( T_1 * ) V_3 ) [ V_11 ] = F_7 ( V_2 , 0xac4 + ( V_7 * 8 ) ) ;
if ( V_9 ) {
T_1 V_12 = F_7 ( V_2 , 0xac4 + ( V_7 * 8 ) ) ;
for ( V_11 = V_5 ; V_11 < V_5 + V_9 ; V_11 ++ ) {
( ( T_3 * ) V_3 ) [ V_11 ] = ( T_3 ) ( V_12 & 0xff ) ;
V_12 >>= 8 ;
}
}
}
static void
F_8 ( struct V_1 * V_2 , T_1 V_4 , T_1 V_5 ,
T_3 V_7 , void * V_3 )
{
T_3 V_9 = V_5 % 4 ;
int V_11 ;
if ( V_4 >= V_13 && V_2 -> V_14 )
return F_6 ( V_2 , V_4 - V_13 ,
V_5 , V_7 , V_3 ) ;
V_5 -= V_9 ;
F_3 ( V_2 , 0x1c0 + ( V_7 * 8 ) , V_4 | ( 0x1 << 25 ) ) ;
for ( V_11 = 0 ; V_11 < V_5 / 4 ; V_11 ++ )
( ( T_1 * ) V_3 ) [ V_11 ] = F_7 ( V_2 , 0x1c4 + ( V_7 * 8 ) ) ;
if ( V_9 ) {
T_1 V_12 = F_7 ( V_2 , 0x1c4 + ( V_7 * 8 ) ) ;
for ( V_11 = V_5 ; V_11 < V_5 + V_9 ; V_11 ++ ) {
( ( T_3 * ) V_3 ) [ V_11 ] = ( T_3 ) ( V_12 & 0xff ) ;
V_12 >>= 8 ;
}
}
}
static void
F_9 ( struct V_1 * V_2 , struct V_15 * V_16 )
{
T_1 V_17 ;
T_1 V_18 ;
if ( V_16 == NULL ) {
F_3 ( V_2 , 0x10c , 0x0 ) ;
return;
}
switch ( V_2 -> V_19 -> V_20 ) {
case V_21 :
case V_22 :
case V_23 :
V_18 = 0x800 ;
break;
case V_24 :
V_18 = 0xe00 ;
break;
default:
V_18 = 0x600 ;
break;
}
F_3 ( V_2 , 0x10c , 0x1 ) ;
F_3 ( V_2 , V_18 + 4 * V_25 , 0x4 ) ;
F_3 ( V_2 , V_18 + 4 * V_26 , 0x0 ) ;
F_3 ( V_2 , V_18 + 4 * V_27 , 0x4 ) ;
F_3 ( V_2 , V_18 + 4 * V_28 , 0x5 ) ;
F_3 ( V_2 , V_18 + 4 * V_29 , 0x6 ) ;
switch ( F_10 ( V_16 -> V_30 ) ) {
case V_31 : V_17 = 0 ; break;
case V_32 : V_17 = 2 ; break;
case V_33 : V_17 = 3 ; break;
default:
F_11 ( 1 ) ;
return;
}
F_12 ( V_2 , 0x048 , 0x1 , 0x1 ) ;
F_3 ( V_2 , 0x054 ,
( ( V_16 -> V_34 >> 12 ) & 0xfffffff ) |
( V_17 << 28 ) | ( 1 << 30 ) ) ;
F_12 ( V_2 , 0x090 , 0x10000 , 0x10000 ) ;
F_12 ( V_2 , 0x0a4 , 0x8 , 0x8 ) ;
}
static void
F_13 ( struct V_1 * V_2 , T_1 V_35 )
{
F_3 ( V_2 , 0x104 , V_35 ) ;
}
static void
F_14 ( struct V_1 * V_2 )
{
T_1 V_10 = F_7 ( V_2 , 0x100 ) ;
if ( V_10 & F_2 ( 6 ) )
F_3 ( V_2 , 0x130 , 0x2 ) ;
else
F_3 ( V_2 , 0x100 , 0x2 ) ;
}
static int
F_15 ( struct V_1 * V_2 , T_1 V_36 )
{
struct V_37 * V_38 = V_2 -> V_19 -> V_38 ;
int V_39 ;
V_39 = F_16 ( V_38 , V_36 , V_2 -> V_34 + 0x100 , 0x10 , 0x10 ) ;
if ( V_39 < 0 )
return V_39 ;
return 0 ;
}
static int
F_17 ( struct V_1 * V_2 , T_1 V_40 )
{
struct V_37 * V_38 = V_2 -> V_19 -> V_38 ;
int V_39 ;
F_12 ( V_2 , 0x004 , V_40 , V_40 ) ;
V_39 = F_16 ( V_38 , 10 , V_2 -> V_34 + 0x008 , V_40 , 0x0 ) ;
if ( V_39 < 0 )
return V_39 ;
return 0 ;
}
static int
F_18 ( struct V_1 * V_2 )
{
struct V_37 * V_38 = V_2 -> V_19 -> V_38 ;
int V_39 ;
V_39 = F_16 ( V_38 , 10 , V_2 -> V_34 + 0x04c , 0xffff , 0x0 ) ;
if ( V_39 < 0 )
return V_39 ;
return 0 ;
}
static int
F_19 ( struct V_1 * V_2 )
{
struct V_37 * V_38 = V_2 -> V_19 -> V_38 ;
int V_39 ;
V_39 = F_16 ( V_38 , 10 , V_2 -> V_34 + 0x10c , 0x6 , 0x0 ) ;
if ( V_39 < 0 ) {
F_20 ( V_2 -> V_41 , L_1 ) ;
return V_39 ;
}
V_39 = F_18 ( V_2 ) ;
if ( V_39 )
return V_39 ;
F_3 ( V_2 , 0x010 , 0xff ) ;
return 0 ;
}
static void
F_21 ( struct V_1 * V_2 )
{
F_3 ( V_2 , 0x014 , 0xff ) ;
F_18 ( V_2 ) ;
}
int
F_22 ( struct V_42 * V_19 , const char * V_43 , T_1 V_34 ,
struct V_1 * * V_44 )
{
struct V_1 * V_2 ;
if ( ! ( V_2 = * V_44 = F_23 ( sizeof( * V_2 ) , V_45 ) ) )
return - V_46 ;
F_24 ( & V_47 , V_19 , V_43 , V_34 , V_2 ) ;
return 0 ;
}
