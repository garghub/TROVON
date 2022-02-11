static inline void F_1 ( struct V_1 * V_2 )
{
int V_3 = sizeof( struct V_1 ) >> 2 ;
T_1 * V_4 = ( T_1 * ) V_2 ;
F_2 ( sizeof( struct V_1 ) % 4 ) ;
do { * V_4 ++ = 0 ; } while ( -- V_3 );
}
static int F_3 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = F_4 ( V_6 ) ;
V_2 -> V_7 [ 0 ] = 0x67452301 ;
V_2 -> V_7 [ 1 ] = 0xefcdab89 ;
V_2 -> V_7 [ 2 ] = 0x98badcfe ;
V_2 -> V_7 [ 3 ] = 0x10325476 ;
V_2 -> V_8 = 0 ;
return 0 ;
}
static int F_5 ( struct V_5 * V_6 , const T_2 * V_9 ,
unsigned int V_10 )
{
struct V_1 * V_2 = F_4 ( V_6 ) ;
const unsigned int V_11 = V_2 -> V_8 & 0x3f ;
unsigned int V_12 = 64 - V_11 ;
const T_2 * V_13 = V_9 ;
V_2 -> V_8 += V_10 ;
if ( V_12 > V_10 ) {
memcpy ( ( char * ) V_2 -> V_14 + V_11 , V_13 , V_10 ) ;
return 0 ;
}
if ( V_11 ) {
memcpy ( ( char * ) V_2 -> V_14 + V_11 , V_13 , V_12 ) ;
F_6 ( V_2 -> V_7 , ( const T_2 * ) V_2 -> V_14 , 1 ) ;
V_10 -= V_12 ;
V_13 += V_12 ;
}
if ( V_10 > 63 ) {
F_6 ( V_2 -> V_7 , V_13 , V_10 >> 6 ) ;
V_13 += V_10 & ~ 0x3f ;
V_10 &= 0x3f ;
}
memcpy ( ( char * ) V_2 -> V_14 , V_13 , V_10 ) ;
return 0 ;
}
static int F_7 ( struct V_5 * V_6 , T_2 * V_15 )
{
struct V_1 * V_2 = F_4 ( V_6 ) ;
const unsigned int V_11 = V_2 -> V_8 & 0x3f ;
const T_2 * V_13 = ( const T_2 * ) V_2 -> V_14 ;
T_2 * V_16 = ( T_2 * ) V_13 + V_11 ;
int V_17 = 55 - V_11 ;
T_3 * V_18 = ( T_3 * ) ( ( char * ) V_2 -> V_14 + 56 ) ;
T_4 * V_19 = ( T_4 * ) V_15 ;
* V_16 ++ = 0x80 ;
if ( V_17 < 0 ) {
memset ( V_16 , 0x00 , V_17 + sizeof ( V_20 ) ) ;
F_6 ( V_2 -> V_7 , V_13 , 1 ) ;
V_16 = ( char * ) V_2 -> V_14 ;
V_17 = 56 ;
}
memset ( V_16 , 0 , V_17 ) ;
* V_18 = F_8 ( V_2 -> V_8 << 3 ) ;
F_6 ( V_2 -> V_7 , V_13 , 1 ) ;
V_19 [ 0 ] = F_9 ( V_2 -> V_7 [ 0 ] ) ;
V_19 [ 1 ] = F_9 ( V_2 -> V_7 [ 1 ] ) ;
V_19 [ 2 ] = F_9 ( V_2 -> V_7 [ 2 ] ) ;
V_19 [ 3 ] = F_9 ( V_2 -> V_7 [ 3 ] ) ;
F_1 ( V_2 ) ;
return 0 ;
}
static int F_10 ( struct V_5 * V_6 , void * V_15 )
{
struct V_1 * V_2 = F_4 ( V_6 ) ;
memcpy ( V_15 , V_2 , sizeof( * V_2 ) ) ;
return 0 ;
}
static int F_11 ( struct V_5 * V_6 , const void * V_21 )
{
struct V_1 * V_2 = F_4 ( V_6 ) ;
memcpy ( V_2 , V_21 , sizeof( * V_2 ) ) ;
return 0 ;
}
static int T_5 F_12 ( void )
{
return F_13 ( & V_22 ) ;
}
static void T_6 F_14 ( void )
{
F_15 ( & V_22 ) ;
}
