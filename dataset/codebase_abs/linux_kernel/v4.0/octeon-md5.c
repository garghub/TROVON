static void F_1 ( struct V_1 * V_2 )
{
T_1 * V_3 = ( T_1 * ) V_2 -> V_3 ;
F_2 ( V_3 [ 0 ] , 0 ) ;
F_2 ( V_3 [ 1 ] , 1 ) ;
}
static void F_3 ( struct V_1 * V_2 )
{
T_1 * V_3 = ( T_1 * ) V_2 -> V_3 ;
V_3 [ 0 ] = F_4 ( 0 ) ;
V_3 [ 1 ] = F_4 ( 1 ) ;
}
static void F_5 ( const void * V_4 )
{
const T_1 * V_5 = V_4 ;
F_6 ( V_5 [ 0 ] , 0 ) ;
F_6 ( V_5 [ 1 ] , 1 ) ;
F_6 ( V_5 [ 2 ] , 2 ) ;
F_6 ( V_5 [ 3 ] , 3 ) ;
F_6 ( V_5 [ 4 ] , 4 ) ;
F_6 ( V_5 [ 5 ] , 5 ) ;
F_6 ( V_5 [ 6 ] , 6 ) ;
F_7 ( V_5 [ 7 ] ) ;
}
static int F_8 ( struct V_6 * V_7 )
{
struct V_1 * V_8 = F_9 ( V_7 ) ;
V_8 -> V_3 [ 0 ] = F_10 ( 0x67452301 ) ;
V_8 -> V_3 [ 1 ] = F_10 ( 0xefcdab89 ) ;
V_8 -> V_3 [ 2 ] = F_10 ( 0x98badcfe ) ;
V_8 -> V_3 [ 3 ] = F_10 ( 0x10325476 ) ;
V_8 -> V_9 = 0 ;
return 0 ;
}
static int F_11 ( struct V_6 * V_7 , const T_2 * V_10 ,
unsigned int V_11 )
{
struct V_1 * V_8 = F_9 ( V_7 ) ;
const T_3 V_12 = sizeof( V_8 -> V_5 ) - ( V_8 -> V_9 & 0x3f ) ;
struct V_13 V_14 ;
unsigned long V_15 ;
V_8 -> V_9 += V_11 ;
if ( V_12 > V_11 ) {
memcpy ( ( char * ) V_8 -> V_5 + ( sizeof( V_8 -> V_5 ) - V_12 ) ,
V_10 , V_11 ) ;
return 0 ;
}
memcpy ( ( char * ) V_8 -> V_5 + ( sizeof( V_8 -> V_5 ) - V_12 ) , V_10 ,
V_12 ) ;
F_12 () ;
F_13 () ;
V_15 = F_14 ( & V_14 ) ;
F_1 ( V_8 ) ;
F_5 ( V_8 -> V_5 ) ;
V_10 += V_12 ;
V_11 -= V_12 ;
while ( V_11 >= sizeof( V_8 -> V_5 ) ) {
F_5 ( V_10 ) ;
V_10 += sizeof( V_8 -> V_5 ) ;
V_11 -= sizeof( V_8 -> V_5 ) ;
}
F_3 ( V_8 ) ;
F_15 ( & V_14 , V_15 ) ;
F_16 () ;
F_17 () ;
memcpy ( V_8 -> V_5 , V_10 , V_11 ) ;
return 0 ;
}
static int F_18 ( struct V_6 * V_7 , T_2 * V_16 )
{
struct V_1 * V_8 = F_9 ( V_7 ) ;
const unsigned int V_17 = V_8 -> V_9 & 0x3f ;
char * V_18 = ( char * ) V_8 -> V_5 + V_17 ;
int V_19 = 56 - ( V_17 + 1 ) ;
struct V_13 V_14 ;
unsigned long V_15 ;
* V_18 ++ = 0x80 ;
F_12 () ;
F_13 () ;
V_15 = F_14 ( & V_14 ) ;
F_1 ( V_8 ) ;
if ( V_19 < 0 ) {
memset ( V_18 , 0x00 , V_19 + sizeof( T_1 ) ) ;
F_5 ( V_8 -> V_5 ) ;
V_18 = ( char * ) V_8 -> V_5 ;
V_19 = 56 ;
}
memset ( V_18 , 0 , V_19 ) ;
V_8 -> V_5 [ 14 ] = F_10 ( V_8 -> V_9 << 3 ) ;
V_8 -> V_5 [ 15 ] = F_10 ( V_8 -> V_9 >> 29 ) ;
F_5 ( V_8 -> V_5 ) ;
F_3 ( V_8 ) ;
F_15 ( & V_14 , V_15 ) ;
F_16 () ;
F_17 () ;
memcpy ( V_16 , V_8 -> V_3 , sizeof( V_8 -> V_3 ) ) ;
memset ( V_8 , 0 , sizeof( * V_8 ) ) ;
return 0 ;
}
static int F_19 ( struct V_6 * V_7 , void * V_16 )
{
struct V_1 * V_2 = F_9 ( V_7 ) ;
memcpy ( V_16 , V_2 , sizeof( * V_2 ) ) ;
return 0 ;
}
static int F_20 ( struct V_6 * V_7 , const void * V_20 )
{
struct V_1 * V_2 = F_9 ( V_7 ) ;
memcpy ( V_2 , V_20 , sizeof( * V_2 ) ) ;
return 0 ;
}
static int T_4 F_21 ( void )
{
if ( ! F_22 () )
return - V_21 ;
return F_23 ( & V_22 ) ;
}
static void T_5 F_24 ( void )
{
F_25 ( & V_22 ) ;
}
