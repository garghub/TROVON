static inline T_1 F_1 ( T_1 V_1 )
{
return ( ( V_1 & 0x00ff00ff ) << 8 ) | ( ( V_1 & 0xff00ff00 ) >> 8 ) ;
}
static int F_2 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = F_3 ( V_3 ) ;
struct V_6 * V_7 = F_4 ( V_3 -> V_8 ) ;
V_5 -> V_9 = 0 ;
V_5 -> V_10 = V_7 -> V_10 ;
V_5 -> V_11 = V_7 -> V_11 ;
return 0 ;
}
static int F_5 ( struct V_2 * V_3 , const T_2 * V_12 ,
unsigned int V_13 )
{
struct V_4 * V_5 = F_3 ( V_3 ) ;
const T_3 * V_14 ;
if ( V_5 -> V_9 ) {
int V_15 = 4 - V_5 -> V_9 ;
if ( V_15 > V_13 )
V_15 = V_13 ;
memcpy ( & V_5 -> V_16 [ V_5 -> V_9 ] , V_12 , V_15 ) ;
V_5 -> V_9 += V_15 ;
V_12 += V_15 ;
V_13 -= V_15 ;
if ( V_5 -> V_9 < 4 )
return 0 ;
V_14 = ( const T_3 * ) V_5 -> V_16 ;
V_5 -> V_10 ^= F_6 ( V_14 ) ;
F_7 ( V_5 -> V_10 , V_5 -> V_11 ) ;
V_5 -> V_9 = 0 ;
}
V_14 = ( const T_3 * ) V_12 ;
while ( V_13 >= 4 ) {
V_5 -> V_10 ^= F_6 ( V_14 ++ ) ;
F_7 ( V_5 -> V_10 , V_5 -> V_11 ) ;
V_13 -= 4 ;
}
if ( V_13 > 0 ) {
V_5 -> V_9 = V_13 ;
memcpy ( V_5 -> V_16 , V_14 , V_13 ) ;
}
return 0 ;
}
static int F_8 ( struct V_2 * V_3 , T_2 * V_17 )
{
struct V_4 * V_5 = F_3 ( V_3 ) ;
T_2 * V_12 = V_5 -> V_16 ;
T_3 * V_18 = ( T_3 * ) V_17 ;
switch ( V_5 -> V_9 ) {
case 0 :
V_5 -> V_10 ^= 0x5a ;
break;
case 1 :
V_5 -> V_10 ^= V_12 [ 0 ] | 0x5a00 ;
break;
case 2 :
V_5 -> V_10 ^= V_12 [ 0 ] | ( V_12 [ 1 ] << 8 ) | 0x5a0000 ;
break;
case 3 :
V_5 -> V_10 ^= V_12 [ 0 ] | ( V_12 [ 1 ] << 8 ) | ( V_12 [ 2 ] << 16 ) |
0x5a000000 ;
break;
}
F_7 ( V_5 -> V_10 , V_5 -> V_11 ) ;
F_7 ( V_5 -> V_10 , V_5 -> V_11 ) ;
V_18 [ 0 ] = F_9 ( V_5 -> V_10 ) ;
V_18 [ 1 ] = F_9 ( V_5 -> V_11 ) ;
return 0 ;
}
static int F_10 ( struct V_19 * V_8 , const T_2 * V_20 ,
unsigned int V_21 )
{
struct V_6 * V_5 = F_4 ( V_8 ) ;
const T_3 * V_12 = ( const T_3 * ) V_20 ;
if ( V_21 != 8 ) {
F_11 ( V_8 , V_22 ) ;
return - V_23 ;
}
V_5 -> V_10 = F_12 ( V_12 [ 0 ] ) ;
V_5 -> V_11 = F_12 ( V_12 [ 1 ] ) ;
return 0 ;
}
static int T_4 F_13 ( void )
{
return F_14 ( & V_24 ) ;
}
static void T_5 F_15 ( void )
{
F_16 ( & V_24 ) ;
}
