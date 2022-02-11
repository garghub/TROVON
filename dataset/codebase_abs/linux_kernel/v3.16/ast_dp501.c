int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
static char * V_6 = L_1 ;
int V_7 ;
V_7 = F_2 ( & V_4 -> V_8 , V_6 , V_2 -> V_2 ) ;
if ( V_7 )
return V_7 ;
return 0 ;
}
static void F_3 ( struct V_3 * V_4 )
{
T_1 V_9 ;
V_9 = F_4 ( V_4 , V_10 , 0x9b , 0xff ) ;
V_9 |= 0x80 ;
F_5 ( V_4 , V_10 , 0x9b , 0x00 , V_9 ) ;
}
static void F_6 ( struct V_3 * V_4 )
{
T_1 V_9 ;
V_9 = F_4 ( V_4 , V_10 , 0x9b , 0xff ) ;
V_9 &= ~ 0x80 ;
F_5 ( V_4 , V_10 , 0x9b , 0x00 , V_9 ) ;
}
static bool F_7 ( struct V_3 * V_4 )
{
T_1 V_11 ;
T_2 V_12 = 0 ;
do {
V_11 = F_4 ( V_4 , V_10 , 0xd2 , 0xff ) ;
V_11 &= 0x80 ;
F_8 ( 100 ) ;
} while ( ( ! V_11 ) && ( V_12 ++ < 1000 ) );
if ( V_12 < 1000 )
return true ;
else
return false ;
}
static bool F_9 ( struct V_3 * V_4 )
{
T_1 V_11 ;
T_2 V_12 = 0 ;
do {
V_11 = F_4 ( V_4 , V_10 , 0xd2 , 0xff ) ;
V_11 &= 0x80 ;
F_8 ( 100 ) ;
} while ( ( V_11 ) && ( V_12 ++ < 1000 ) );
if ( V_12 < 1000 )
return true ;
else
return false ;
}
static void F_10 ( struct V_3 * V_4 )
{
F_5 ( V_4 , V_10 , 0x9b , ~ 0x40 , 0x40 ) ;
}
static void F_11 ( struct V_3 * V_4 )
{
F_5 ( V_4 , V_10 , 0x9b , ~ 0x40 , 0x00 ) ;
}
static bool F_12 ( struct V_1 * V_2 , T_1 V_13 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_12 = 0 ;
if ( F_9 ( V_4 ) ) {
F_6 ( V_4 ) ;
F_5 ( V_4 , V_10 , 0x9a , 0x00 , V_13 ) ;
F_3 ( V_4 ) ;
F_10 ( V_4 ) ;
do {
if ( F_7 ( V_4 ) ) {
F_11 ( V_4 ) ;
F_6 ( V_4 ) ;
return true ;
}
} while ( V_12 ++ < 100 );
}
F_11 ( V_4 ) ;
F_6 ( V_4 ) ;
return false ;
}
static bool F_13 ( struct V_1 * V_2 , T_1 V_13 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( F_9 ( V_4 ) ) {
F_6 ( V_4 ) ;
F_5 ( V_4 , V_10 , 0x9a , 0x00 , V_13 ) ;
F_3 ( V_4 ) ;
if ( F_7 ( V_4 ) ) {
F_6 ( V_4 ) ;
return true ;
}
}
F_6 ( V_4 ) ;
return false ;
}
void F_14 ( struct V_1 * V_2 , T_1 V_14 )
{
F_12 ( V_2 , 0x40 ) ;
F_13 ( V_2 , V_14 ) ;
F_15 ( 10 ) ;
}
static T_2 F_16 ( struct V_3 * V_4 )
{
return F_17 ( V_4 , 0x1e6e2104 ) & 0x7fffffff ;
}
bool F_18 ( struct V_1 * V_2 , T_1 * V_15 , T_2 V_16 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_2 V_17 , V_13 ;
T_2 V_18 ;
V_13 = F_17 ( V_4 , 0x1e6e2100 ) & 0x01 ;
if ( V_13 ) {
V_18 = F_16 ( V_4 ) ;
for ( V_17 = 0 ; V_17 < V_16 ; V_17 += 4 )
* ( T_2 * ) ( V_15 + V_17 ) = F_17 ( V_4 , V_18 + V_17 ) ;
return true ;
}
return false ;
}
bool F_19 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_2 V_17 , V_13 , V_19 = 0 ;
T_2 V_18 ;
T_1 * V_20 = NULL ;
T_1 V_21 ;
V_13 = F_17 ( V_4 , 0x1e6e2100 ) & 0x01 ;
if ( ! V_13 ) {
if ( V_4 -> V_22 ) {
V_20 = V_4 -> V_22 ;
V_19 = 32 * 1024 ;
} else if ( V_4 -> V_8 ) {
V_20 = ( T_1 * ) V_4 -> V_8 -> V_13 ;
V_19 = V_4 -> V_8 -> V_16 ;
}
F_20 ( V_4 , 0x1e6e2000 , 0x1688a8a8 ) ;
V_13 = F_17 ( V_4 , 0x1e6e0004 ) ;
switch ( V_13 & 0x03 ) {
case 0 :
V_18 = 0x44000000 ;
break;
default:
case 1 :
V_18 = 0x48000000 ;
break;
case 2 :
V_18 = 0x50000000 ;
break;
case 3 :
V_18 = 0x60000000 ;
break;
}
V_18 -= 0x200000 ;
for ( V_17 = 0 ; V_17 < V_19 ; V_17 += 4 ) {
V_13 = * ( T_2 * ) ( V_20 + V_17 ) ;
F_20 ( V_4 , V_18 + V_17 , V_13 ) ;
}
F_20 ( V_4 , 0x1e6e2000 , 0x1688a8a8 ) ;
F_20 ( V_4 , 0x1e6e2104 , 0x80000000 + V_18 ) ;
F_20 ( V_4 , 0x1e6e2100 , 1 ) ;
V_13 = F_17 ( V_4 , 0x1e6e2040 ) & 0xfffff1ff ;
V_13 |= 0x800 ;
F_20 ( V_4 , 0x1e6e2040 , V_13 ) ;
V_21 = F_4 ( V_4 , V_10 , 0x99 , 0xfc ) ;
V_21 |= 0x02 ;
F_21 ( V_4 , V_10 , 0x99 , V_21 ) ;
}
return true ;
}
T_1 F_22 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_2 V_18 , V_23 , V_13 ;
T_1 V_24 [ 4 ] , V_25 , V_26 , V_27 = 0xff ;
V_18 = F_16 ( V_4 ) ;
V_23 = 0xf000 ;
V_13 = F_17 ( V_4 , V_18 + V_23 ) ;
if ( ( V_13 & 0xf0 ) != 0x10 )
return V_27 ;
V_23 = 0xf014 ;
* ( T_2 * ) V_24 = F_17 ( V_4 , V_18 + V_23 ) ;
if ( V_24 [ 2 ] == 0 ) {
V_25 = V_24 [ 0 ] ;
V_26 = V_24 [ 1 ] ;
V_13 = ( V_25 == 0x0a ) ? ( 90 * V_26 ) : ( 54 * V_26 ) ;
if ( V_13 > 0xff )
V_13 = 0xff ;
V_27 = ( T_1 ) V_13 ;
}
return V_27 ;
}
bool F_23 ( struct V_1 * V_2 , T_1 * V_28 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_2 V_17 , V_18 , V_23 , V_13 ;
V_18 = F_16 ( V_4 ) ;
V_23 = 0xf000 ;
V_13 = F_17 ( V_4 , V_18 + V_23 ) ;
if ( ( V_13 & 0xf0 ) != 0x10 )
return false ;
V_23 = 0xf010 ;
V_13 = F_17 ( V_4 , V_18 + V_23 ) ;
if ( ! ( V_13 & 0x01 ) )
return false ;
V_23 = 0xf020 ;
for ( V_17 = 0 ; V_17 < 128 ; V_17 += 4 ) {
V_13 = F_17 ( V_4 , V_18 + V_23 + V_17 ) ;
* ( T_2 * ) ( V_28 + V_17 ) = V_13 ;
}
return true ;
}
static bool F_24 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_21 ;
T_2 V_13 ;
F_25 ( V_4 , 0xf004 , 0x1e6e0000 ) ;
F_25 ( V_4 , 0xf000 , 0x1 ) ;
F_25 ( V_4 , 0x12000 , 0x1688a8a8 ) ;
V_21 = F_4 ( V_4 , V_10 , 0xd0 , 0xff ) ;
if ( ! ( V_21 & 0x80 ) ) {
V_13 = F_26 ( V_4 , 0x12008 ) ;
V_13 &= 0xfffff8ff ;
V_13 |= 0x00000500 ;
F_25 ( V_4 , 0x12008 , V_13 ) ;
if ( V_4 -> V_29 == V_30 ) {
V_13 = F_26 ( V_4 , 0x12084 ) ;
V_13 |= 0xfffe0000 ;
F_25 ( V_4 , 0x12084 , V_13 ) ;
V_13 = F_26 ( V_4 , 0x12088 ) ;
V_13 |= 0x000fffff ;
F_25 ( V_4 , 0x12088 , V_13 ) ;
V_13 = F_26 ( V_4 , 0x12090 ) ;
V_13 &= 0xffffffcf ;
V_13 |= 0x00000020 ;
F_25 ( V_4 , 0x12090 , V_13 ) ;
} else {
V_13 = F_26 ( V_4 , 0x12088 ) ;
V_13 |= 0x30000000 ;
F_25 ( V_4 , 0x12088 , V_13 ) ;
V_13 = F_26 ( V_4 , 0x1208c ) ;
V_13 |= 0x000000cf ;
F_25 ( V_4 , 0x1208c , V_13 ) ;
V_13 = F_26 ( V_4 , 0x120a4 ) ;
V_13 |= 0xffff0000 ;
F_25 ( V_4 , 0x120a4 , V_13 ) ;
V_13 = F_26 ( V_4 , 0x120a8 ) ;
V_13 |= 0x0000000f ;
F_25 ( V_4 , 0x120a8 , V_13 ) ;
V_13 = F_26 ( V_4 , 0x12094 ) ;
V_13 |= 0x00000002 ;
F_25 ( V_4 , 0x12094 , V_13 ) ;
}
}
V_13 = F_26 ( V_4 , 0x1202c ) ;
V_13 &= 0xfffbffff ;
F_25 ( V_4 , 0x1202c , V_13 ) ;
F_5 ( V_4 , V_10 , 0xa3 , 0xcf , 0x80 ) ;
return true ;
}
void F_27 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_21 ;
T_2 V_13 ;
if ( V_4 -> V_29 == V_30 || V_4 -> V_29 == V_31 ) {
V_21 = F_4 ( V_4 , V_10 , 0xd1 , 0xff ) ;
switch ( V_21 & 0x0e ) {
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
if ( V_4 -> V_32 == V_33 )
F_24 ( V_2 ) ;
else {
F_25 ( V_4 , 0x12000 , 0x1688a8a8 ) ;
V_13 = F_26 ( V_4 , 0x1202c ) ;
V_13 &= 0xfffcffff ;
F_25 ( V_4 , 0 , V_13 ) ;
}
}
}
}
