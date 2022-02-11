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
V_2 -> V_7 [ 0 ] = V_8 ;
V_2 -> V_7 [ 1 ] = V_9 ;
V_2 -> V_7 [ 2 ] = V_10 ;
V_2 -> V_7 [ 3 ] = V_11 ;
V_2 -> V_12 = 0 ;
return 0 ;
}
static int F_5 ( struct V_5 * V_6 , const T_2 * V_13 ,
unsigned int V_14 )
{
struct V_1 * V_2 = F_4 ( V_6 ) ;
const unsigned int V_15 = V_2 -> V_12 & 0x3f ;
unsigned int V_16 = 64 - V_15 ;
const T_2 * V_17 = V_13 ;
V_2 -> V_12 += V_14 ;
if ( V_16 > V_14 ) {
memcpy ( ( char * ) V_2 -> V_18 + V_15 , V_17 , V_14 ) ;
return 0 ;
}
if ( V_15 ) {
memcpy ( ( char * ) V_2 -> V_18 + V_15 , V_17 , V_16 ) ;
F_6 ( V_2 -> V_7 , ( const T_2 * ) V_2 -> V_18 , 1 ) ;
V_14 -= V_16 ;
V_17 += V_16 ;
}
if ( V_14 > 63 ) {
F_6 ( V_2 -> V_7 , V_17 , V_14 >> 6 ) ;
V_17 += V_14 & ~ 0x3f ;
V_14 &= 0x3f ;
}
memcpy ( ( char * ) V_2 -> V_18 , V_17 , V_14 ) ;
return 0 ;
}
static int F_7 ( struct V_5 * V_6 , T_2 * V_19 )
{
struct V_1 * V_2 = F_4 ( V_6 ) ;
const unsigned int V_15 = V_2 -> V_12 & 0x3f ;
const T_2 * V_17 = ( const T_2 * ) V_2 -> V_18 ;
T_2 * V_20 = ( T_2 * ) V_17 + V_15 ;
int V_21 = 55 - V_15 ;
T_3 * V_22 = ( T_3 * ) ( ( char * ) V_2 -> V_18 + 56 ) ;
T_4 * V_23 = ( T_4 * ) V_19 ;
* V_20 ++ = 0x80 ;
if ( V_21 < 0 ) {
memset ( V_20 , 0x00 , V_21 + sizeof ( V_24 ) ) ;
F_6 ( V_2 -> V_7 , V_17 , 1 ) ;
V_20 = ( char * ) V_2 -> V_18 ;
V_21 = 56 ;
}
memset ( V_20 , 0 , V_21 ) ;
* V_22 = F_8 ( V_2 -> V_12 << 3 ) ;
F_6 ( V_2 -> V_7 , V_17 , 1 ) ;
V_23 [ 0 ] = F_9 ( V_2 -> V_7 [ 0 ] ) ;
V_23 [ 1 ] = F_9 ( V_2 -> V_7 [ 1 ] ) ;
V_23 [ 2 ] = F_9 ( V_2 -> V_7 [ 2 ] ) ;
V_23 [ 3 ] = F_9 ( V_2 -> V_7 [ 3 ] ) ;
F_1 ( V_2 ) ;
return 0 ;
}
static int F_10 ( struct V_5 * V_6 , void * V_19 )
{
struct V_1 * V_2 = F_4 ( V_6 ) ;
memcpy ( V_19 , V_2 , sizeof( * V_2 ) ) ;
return 0 ;
}
static int F_11 ( struct V_5 * V_6 , const void * V_25 )
{
struct V_1 * V_2 = F_4 ( V_6 ) ;
memcpy ( V_2 , V_25 , sizeof( * V_2 ) ) ;
return 0 ;
}
static int T_5 F_12 ( void )
{
return F_13 ( & V_26 ) ;
}
static void T_6 F_14 ( void )
{
F_15 ( & V_26 ) ;
}
