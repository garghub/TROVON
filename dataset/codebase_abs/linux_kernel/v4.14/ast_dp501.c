static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
return F_2 ( & V_4 -> V_6 , L_1 , V_2 -> V_2 ) ;
}
static void F_3 ( struct V_3 * V_4 )
{
T_1 V_7 ;
V_7 = F_4 ( V_4 , V_8 , 0x9b , 0xff ) ;
V_7 |= 0x80 ;
F_5 ( V_4 , V_8 , 0x9b , 0x00 , V_7 ) ;
}
static void F_6 ( struct V_3 * V_4 )
{
T_1 V_7 ;
V_7 = F_4 ( V_4 , V_8 , 0x9b , 0xff ) ;
V_7 &= ~ 0x80 ;
F_5 ( V_4 , V_8 , 0x9b , 0x00 , V_7 ) ;
}
static bool F_7 ( struct V_3 * V_4 )
{
T_1 V_9 ;
T_2 V_10 = 0 ;
do {
V_9 = F_4 ( V_4 , V_8 , 0xd2 , 0xff ) ;
V_9 &= 0x80 ;
F_8 ( 100 ) ;
} while ( ( ! V_9 ) && ( V_10 ++ < 1000 ) );
if ( V_10 < 1000 )
return true ;
else
return false ;
}
static bool F_9 ( struct V_3 * V_4 )
{
T_1 V_9 ;
T_2 V_10 = 0 ;
do {
V_9 = F_4 ( V_4 , V_8 , 0xd2 , 0xff ) ;
V_9 &= 0x80 ;
F_8 ( 100 ) ;
} while ( ( V_9 ) && ( V_10 ++ < 1000 ) );
if ( V_10 < 1000 )
return true ;
else
return false ;
}
static void F_10 ( struct V_3 * V_4 )
{
F_5 ( V_4 , V_8 , 0x9b , ~ 0x40 , 0x40 ) ;
}
static void F_11 ( struct V_3 * V_4 )
{
F_5 ( V_4 , V_8 , 0x9b , ~ 0x40 , 0x00 ) ;
}
static bool F_12 ( struct V_1 * V_2 , T_1 V_11 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_10 = 0 ;
if ( F_9 ( V_4 ) ) {
F_6 ( V_4 ) ;
F_5 ( V_4 , V_8 , 0x9a , 0x00 , V_11 ) ;
F_3 ( V_4 ) ;
F_10 ( V_4 ) ;
do {
if ( F_7 ( V_4 ) ) {
F_11 ( V_4 ) ;
F_6 ( V_4 ) ;
return true ;
}
} while ( V_10 ++ < 100 );
}
F_11 ( V_4 ) ;
F_6 ( V_4 ) ;
return false ;
}
static bool F_13 ( struct V_1 * V_2 , T_1 V_11 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( F_9 ( V_4 ) ) {
F_6 ( V_4 ) ;
F_5 ( V_4 , V_8 , 0x9a , 0x00 , V_11 ) ;
F_3 ( V_4 ) ;
if ( F_7 ( V_4 ) ) {
F_6 ( V_4 ) ;
return true ;
}
}
F_6 ( V_4 ) ;
return false ;
}
void F_14 ( struct V_1 * V_2 , T_1 V_12 )
{
F_12 ( V_2 , 0x40 ) ;
F_13 ( V_2 , V_12 ) ;
F_15 ( 10 ) ;
}
static T_2 F_16 ( struct V_3 * V_4 )
{
return F_17 ( V_4 , 0x1e6e2104 ) & 0x7fffffff ;
}
bool F_18 ( struct V_1 * V_2 , T_1 * V_13 , T_2 V_14 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_2 V_15 , V_11 ;
T_2 V_16 ;
V_11 = F_17 ( V_4 , 0x1e6e2100 ) & 0x01 ;
if ( V_11 ) {
V_16 = F_16 ( V_4 ) ;
for ( V_15 = 0 ; V_15 < V_14 ; V_15 += 4 )
* ( T_2 * ) ( V_13 + V_15 ) = F_17 ( V_4 , V_16 + V_15 ) ;
return true ;
}
return false ;
}
static bool F_19 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_2 V_15 , V_11 , V_17 = 0 ;
T_2 V_16 ;
T_1 * V_18 = NULL ;
T_1 V_19 ;
V_11 = F_17 ( V_4 , 0x1e6e2100 ) & 0x01 ;
if ( ! V_11 ) {
if ( V_4 -> V_20 ) {
V_18 = V_4 -> V_20 ;
V_17 = 32 * 1024 ;
} else {
if ( ! V_4 -> V_6 &&
F_1 ( V_2 ) < 0 )
return false ;
V_18 = ( T_1 * ) V_4 -> V_6 -> V_11 ;
V_17 = V_4 -> V_6 -> V_14 ;
}
F_20 ( V_4 , 0x1e6e2000 , 0x1688a8a8 ) ;
V_11 = F_17 ( V_4 , 0x1e6e0004 ) ;
switch ( V_11 & 0x03 ) {
case 0 :
V_16 = 0x44000000 ;
break;
default:
case 1 :
V_16 = 0x48000000 ;
break;
case 2 :
V_16 = 0x50000000 ;
break;
case 3 :
V_16 = 0x60000000 ;
break;
}
V_16 -= 0x200000 ;
for ( V_15 = 0 ; V_15 < V_17 ; V_15 += 4 ) {
V_11 = * ( T_2 * ) ( V_18 + V_15 ) ;
F_20 ( V_4 , V_16 + V_15 , V_11 ) ;
}
F_20 ( V_4 , 0x1e6e2000 , 0x1688a8a8 ) ;
F_20 ( V_4 , 0x1e6e2104 , 0x80000000 + V_16 ) ;
F_20 ( V_4 , 0x1e6e2100 , 1 ) ;
V_11 = F_17 ( V_4 , 0x1e6e2040 ) & 0xfffff1ff ;
V_11 |= 0x800 ;
F_20 ( V_4 , 0x1e6e2040 , V_11 ) ;
V_19 = F_4 ( V_4 , V_8 , 0x99 , 0xfc ) ;
V_19 |= 0x02 ;
F_21 ( V_4 , V_8 , 0x99 , V_19 ) ;
}
return true ;
}
T_1 F_22 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_2 V_16 , V_21 , V_11 ;
T_1 V_22 [ 4 ] , V_23 , V_24 , V_25 = 0xff ;
V_16 = F_16 ( V_4 ) ;
V_21 = 0xf000 ;
V_11 = F_17 ( V_4 , V_16 + V_21 ) ;
if ( ( V_11 & 0xf0 ) != 0x10 )
return V_25 ;
V_21 = 0xf014 ;
* ( T_2 * ) V_22 = F_17 ( V_4 , V_16 + V_21 ) ;
if ( V_22 [ 2 ] == 0 ) {
V_23 = V_22 [ 0 ] ;
V_24 = V_22 [ 1 ] ;
V_11 = ( V_23 == 0x0a ) ? ( 90 * V_24 ) : ( 54 * V_24 ) ;
if ( V_11 > 0xff )
V_11 = 0xff ;
V_25 = ( T_1 ) V_11 ;
}
return V_25 ;
}
bool F_23 ( struct V_1 * V_2 , T_1 * V_26 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_2 V_15 , V_16 , V_21 , V_11 ;
V_16 = F_16 ( V_4 ) ;
V_21 = 0xf000 ;
V_11 = F_17 ( V_4 , V_16 + V_21 ) ;
if ( ( V_11 & 0xf0 ) != 0x10 )
return false ;
V_21 = 0xf010 ;
V_11 = F_17 ( V_4 , V_16 + V_21 ) ;
if ( ! ( V_11 & 0x01 ) )
return false ;
V_21 = 0xf020 ;
for ( V_15 = 0 ; V_15 < 128 ; V_15 += 4 ) {
V_11 = F_17 ( V_4 , V_16 + V_21 + V_15 ) ;
* ( T_2 * ) ( V_26 + V_15 ) = V_11 ;
}
return true ;
}
static bool F_24 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_19 ;
T_2 V_11 ;
F_25 ( V_4 , 0xf004 , 0x1e6e0000 ) ;
F_25 ( V_4 , 0xf000 , 0x1 ) ;
F_25 ( V_4 , 0x12000 , 0x1688a8a8 ) ;
V_19 = F_4 ( V_4 , V_8 , 0xd0 , 0xff ) ;
if ( ! ( V_19 & 0x80 ) ) {
V_11 = F_26 ( V_4 , 0x12008 ) ;
V_11 &= 0xfffff8ff ;
V_11 |= 0x00000500 ;
F_25 ( V_4 , 0x12008 , V_11 ) ;
if ( V_4 -> V_27 == V_28 ) {
V_11 = F_26 ( V_4 , 0x12084 ) ;
V_11 |= 0xfffe0000 ;
F_25 ( V_4 , 0x12084 , V_11 ) ;
V_11 = F_26 ( V_4 , 0x12088 ) ;
V_11 |= 0x000fffff ;
F_25 ( V_4 , 0x12088 , V_11 ) ;
V_11 = F_26 ( V_4 , 0x12090 ) ;
V_11 &= 0xffffffcf ;
V_11 |= 0x00000020 ;
F_25 ( V_4 , 0x12090 , V_11 ) ;
} else {
V_11 = F_26 ( V_4 , 0x12088 ) ;
V_11 |= 0x30000000 ;
F_25 ( V_4 , 0x12088 , V_11 ) ;
V_11 = F_26 ( V_4 , 0x1208c ) ;
V_11 |= 0x000000cf ;
F_25 ( V_4 , 0x1208c , V_11 ) ;
V_11 = F_26 ( V_4 , 0x120a4 ) ;
V_11 |= 0xffff0000 ;
F_25 ( V_4 , 0x120a4 , V_11 ) ;
V_11 = F_26 ( V_4 , 0x120a8 ) ;
V_11 |= 0x0000000f ;
F_25 ( V_4 , 0x120a8 , V_11 ) ;
V_11 = F_26 ( V_4 , 0x12094 ) ;
V_11 |= 0x00000002 ;
F_25 ( V_4 , 0x12094 , V_11 ) ;
}
}
V_11 = F_26 ( V_4 , 0x1202c ) ;
V_11 &= 0xfffbffff ;
F_25 ( V_4 , 0x1202c , V_11 ) ;
F_5 ( V_4 , V_8 , 0xa3 , 0xcf , 0x80 ) ;
return true ;
}
static void F_27 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_2 V_11 ;
F_25 ( V_4 , 0xf004 , 0x1e6e0000 ) ;
F_25 ( V_4 , 0xf000 , 0x1 ) ;
F_25 ( V_4 , 0x12000 , 0x1688a8a8 ) ;
F_25 ( V_4 , 0x12000 , 0x1688a8a8 ) ;
F_25 ( V_4 , 0x12000 , 0x1688a8a8 ) ;
V_11 = F_26 ( V_4 , 0x1202c ) ;
V_11 &= 0xfffcffff ;
F_25 ( V_4 , 0 , V_11 ) ;
F_5 ( V_4 , V_8 , 0xa3 , 0xcf , 0x00 ) ;
}
void F_28 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_19 ;
if ( V_4 -> V_27 == V_28 || V_4 -> V_27 == V_29 ) {
V_19 = F_4 ( V_4 , V_8 , 0xd1 , 0xff ) ;
switch ( V_19 & 0x0e ) {
case 0x04 :
F_24 ( V_2 ) ;
break;
case 0x08 :
F_19 ( V_2 ) ;
break;
case 0x0c :
F_24 ( V_2 ) ;
break;
default:
if ( V_4 -> V_30 == V_31 )
F_24 ( V_2 ) ;
else
F_27 ( V_2 ) ;
}
}
}
void F_29 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_30 ( V_4 -> V_6 ) ;
V_4 -> V_6 = NULL ;
}
