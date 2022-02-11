static inline T_1 F_1 ( T_1 V_1 , int V_2 )
{
return ( V_1 << V_2 ) | ( V_1 >> ( 32 - V_2 ) ) ;
}
static inline T_1 F_2 ( T_1 V_1 , int V_2 )
{
return ( V_1 >> V_2 ) | ( V_1 << ( 32 - V_2 ) ) ;
}
static inline T_1 F_3 ( T_1 V_1 )
{
return ( ( V_1 & 0x00ff00ff ) << 8 ) | ( ( V_1 & 0xff00ff00 ) >> 8 ) ;
}
static inline T_1 F_4 ( const T_2 * V_3 )
{
return V_3 [ 0 ] | ( V_3 [ 1 ] << 8 ) | ( V_3 [ 2 ] << 16 ) | ( V_3 [ 3 ] << 24 ) ;
}
static inline void F_5 ( T_2 * V_3 , T_1 V_4 )
{
V_3 [ 0 ] = V_4 ;
V_3 [ 1 ] = V_4 >> 8 ;
V_3 [ 2 ] = V_4 >> 16 ;
V_3 [ 3 ] = V_4 >> 24 ;
}
static void F_6 ( void * V_5 )
{
struct V_6 * V_7 = V_5 ;
V_7 -> V_8 = 0 ;
}
static void F_7 ( void * V_5 , const T_2 * V_9 , unsigned int V_10 )
{
struct V_6 * V_7 = V_5 ;
if ( V_7 -> V_8 ) {
int V_11 = 4 - V_7 -> V_8 ;
if ( V_11 > V_10 )
V_11 = V_10 ;
memcpy ( & V_7 -> V_12 [ V_7 -> V_8 ] , V_9 , V_11 ) ;
V_7 -> V_8 += V_11 ;
V_9 += V_11 ;
V_10 -= V_11 ;
if ( V_7 -> V_8 < 4 )
return;
V_7 -> V_13 ^= F_4 ( V_7 -> V_12 ) ;
F_8 ( V_7 -> V_13 , V_7 -> V_14 ) ;
V_7 -> V_8 = 0 ;
}
while ( V_10 >= 4 ) {
V_7 -> V_13 ^= F_4 ( V_9 ) ;
F_8 ( V_7 -> V_13 , V_7 -> V_14 ) ;
V_9 += 4 ;
V_10 -= 4 ;
}
if ( V_10 > 0 ) {
V_7 -> V_8 = V_10 ;
memcpy ( V_7 -> V_12 , V_9 , V_10 ) ;
}
}
static void F_9 ( void * V_5 , T_2 * V_15 )
{
struct V_6 * V_7 = V_5 ;
T_2 * V_9 = V_7 -> V_12 ;
switch ( V_7 -> V_8 ) {
case 0 :
V_7 -> V_13 ^= 0x5a ;
break;
case 1 :
V_7 -> V_13 ^= V_9 [ 0 ] | 0x5a00 ;
break;
case 2 :
V_7 -> V_13 ^= V_9 [ 0 ] | ( V_9 [ 1 ] << 8 ) | 0x5a0000 ;
break;
case 3 :
V_7 -> V_13 ^= V_9 [ 0 ] | ( V_9 [ 1 ] << 8 ) | ( V_9 [ 2 ] << 16 ) |
0x5a000000 ;
break;
}
F_8 ( V_7 -> V_13 , V_7 -> V_14 ) ;
F_8 ( V_7 -> V_13 , V_7 -> V_14 ) ;
F_5 ( V_15 , V_7 -> V_13 ) ;
F_5 ( V_15 + 4 , V_7 -> V_14 ) ;
}
static int F_10 ( void * V_5 , const T_2 * V_16 , unsigned int V_17 ,
T_1 * V_18 )
{
struct V_6 * V_7 = V_5 ;
if ( V_17 != 8 ) {
if ( V_18 )
* V_18 = V_19 ;
return - V_20 ;
}
V_7 -> V_13 = F_4 ( V_16 ) ;
V_7 -> V_14 = F_4 ( V_16 + 4 ) ;
return 0 ;
}
static int T_3 F_11 ( void )
{
return F_12 ( & V_21 ) ;
}
static void T_4 F_13 ( void )
{
F_14 ( & V_21 ) ;
}
