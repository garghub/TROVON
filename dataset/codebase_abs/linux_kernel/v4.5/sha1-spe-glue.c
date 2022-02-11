static void F_1 ( void )
{
F_2 () ;
F_3 () ;
}
static void F_4 ( void )
{
F_5 () ;
F_6 () ;
}
static inline void F_7 ( struct V_1 * V_2 )
{
int V_3 = sizeof( struct V_1 ) >> 2 ;
T_1 * V_4 = ( T_1 * ) V_2 ;
F_8 ( sizeof( struct V_1 ) % 4 ) ;
do { * V_4 ++ = 0 ; } while ( -- V_3 );
}
static int F_9 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = F_10 ( V_6 ) ;
V_2 -> V_7 [ 0 ] = V_8 ;
V_2 -> V_7 [ 1 ] = V_9 ;
V_2 -> V_7 [ 2 ] = V_10 ;
V_2 -> V_7 [ 3 ] = V_11 ;
V_2 -> V_7 [ 4 ] = V_12 ;
V_2 -> V_3 = 0 ;
return 0 ;
}
static int F_11 ( struct V_5 * V_6 , const T_2 * V_13 ,
unsigned int V_14 )
{
struct V_1 * V_2 = F_10 ( V_6 ) ;
const unsigned int V_15 = V_2 -> V_3 & 0x3f ;
const unsigned int V_16 = 64 - V_15 ;
unsigned int V_17 ;
const T_2 * V_18 = V_13 ;
if ( V_16 > V_14 ) {
V_2 -> V_3 += V_14 ;
memcpy ( ( char * ) V_2 -> V_19 + V_15 , V_18 , V_14 ) ;
return 0 ;
}
V_2 -> V_3 += V_14 ;
if ( V_15 ) {
memcpy ( ( char * ) V_2 -> V_19 + V_15 , V_18 , V_16 ) ;
F_1 () ;
F_12 ( V_2 -> V_7 , ( const T_2 * ) V_2 -> V_19 , 1 ) ;
F_4 () ;
V_14 -= V_16 ;
V_18 += V_16 ;
}
while ( V_14 > 63 ) {
V_17 = ( V_14 > V_20 ) ? V_20 : V_14 ;
V_17 = V_17 & ~ 0x3f ;
F_1 () ;
F_12 ( V_2 -> V_7 , V_18 , V_17 >> 6 ) ;
F_4 () ;
V_18 += V_17 ;
V_14 -= V_17 ;
} ;
memcpy ( ( char * ) V_2 -> V_19 , V_18 , V_14 ) ;
return 0 ;
}
static int F_13 ( struct V_5 * V_6 , T_2 * V_21 )
{
struct V_1 * V_2 = F_10 ( V_6 ) ;
const unsigned int V_15 = V_2 -> V_3 & 0x3f ;
char * V_22 = ( char * ) V_2 -> V_19 + V_15 ;
int V_23 ;
T_3 * V_24 = ( T_3 * ) ( ( ( char * ) & V_2 -> V_19 ) + 56 ) ;
T_4 * V_25 = ( T_4 * ) V_21 ;
V_23 = 55 - V_15 ;
* V_22 ++ = 0x80 ;
F_1 () ;
if ( V_23 < 0 ) {
memset ( V_22 , 0x00 , V_23 + sizeof ( V_26 ) ) ;
F_12 ( V_2 -> V_7 , V_2 -> V_19 , 1 ) ;
V_22 = ( char * ) V_2 -> V_19 ;
V_23 = 56 ;
}
memset ( V_22 , 0 , V_23 ) ;
* V_24 = F_14 ( V_2 -> V_3 << 3 ) ;
F_12 ( V_2 -> V_7 , V_2 -> V_19 , 1 ) ;
F_4 () ;
V_25 [ 0 ] = F_15 ( V_2 -> V_7 [ 0 ] ) ;
V_25 [ 1 ] = F_15 ( V_2 -> V_7 [ 1 ] ) ;
V_25 [ 2 ] = F_15 ( V_2 -> V_7 [ 2 ] ) ;
V_25 [ 3 ] = F_15 ( V_2 -> V_7 [ 3 ] ) ;
V_25 [ 4 ] = F_15 ( V_2 -> V_7 [ 4 ] ) ;
F_7 ( V_2 ) ;
return 0 ;
}
static int F_16 ( struct V_5 * V_6 , void * V_21 )
{
struct V_1 * V_2 = F_10 ( V_6 ) ;
memcpy ( V_21 , V_2 , sizeof( * V_2 ) ) ;
return 0 ;
}
static int F_17 ( struct V_5 * V_6 , const void * V_27 )
{
struct V_1 * V_2 = F_10 ( V_6 ) ;
memcpy ( V_2 , V_27 , sizeof( * V_2 ) ) ;
return 0 ;
}
static int T_5 F_18 ( void )
{
return F_19 ( & V_28 ) ;
}
static void T_6 F_20 ( void )
{
F_21 ( & V_28 ) ;
}
