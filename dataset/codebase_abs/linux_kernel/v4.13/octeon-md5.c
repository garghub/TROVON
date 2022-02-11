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
V_8 -> V_3 [ 0 ] = F_10 ( V_9 ) ;
V_8 -> V_3 [ 1 ] = F_10 ( V_10 ) ;
V_8 -> V_3 [ 2 ] = F_10 ( V_11 ) ;
V_8 -> V_3 [ 3 ] = F_10 ( V_12 ) ;
V_8 -> V_13 = 0 ;
return 0 ;
}
static int F_11 ( struct V_6 * V_7 , const T_2 * V_14 ,
unsigned int V_15 )
{
struct V_1 * V_8 = F_9 ( V_7 ) ;
const T_3 V_16 = sizeof( V_8 -> V_5 ) - ( V_8 -> V_13 & 0x3f ) ;
struct V_17 V_18 ;
unsigned long V_19 ;
V_8 -> V_13 += V_15 ;
if ( V_16 > V_15 ) {
memcpy ( ( char * ) V_8 -> V_5 + ( sizeof( V_8 -> V_5 ) - V_16 ) ,
V_14 , V_15 ) ;
return 0 ;
}
memcpy ( ( char * ) V_8 -> V_5 + ( sizeof( V_8 -> V_5 ) - V_16 ) , V_14 ,
V_16 ) ;
V_19 = F_12 ( & V_18 ) ;
F_1 ( V_8 ) ;
F_5 ( V_8 -> V_5 ) ;
V_14 += V_16 ;
V_15 -= V_16 ;
while ( V_15 >= sizeof( V_8 -> V_5 ) ) {
F_5 ( V_14 ) ;
V_14 += sizeof( V_8 -> V_5 ) ;
V_15 -= sizeof( V_8 -> V_5 ) ;
}
F_3 ( V_8 ) ;
F_13 ( & V_18 , V_19 ) ;
memcpy ( V_8 -> V_5 , V_14 , V_15 ) ;
return 0 ;
}
static int F_14 ( struct V_6 * V_7 , T_2 * V_20 )
{
struct V_1 * V_8 = F_9 ( V_7 ) ;
const unsigned int V_21 = V_8 -> V_13 & 0x3f ;
char * V_22 = ( char * ) V_8 -> V_5 + V_21 ;
int V_23 = 56 - ( V_21 + 1 ) ;
struct V_17 V_18 ;
unsigned long V_19 ;
* V_22 ++ = 0x80 ;
V_19 = F_12 ( & V_18 ) ;
F_1 ( V_8 ) ;
if ( V_23 < 0 ) {
memset ( V_22 , 0x00 , V_23 + sizeof( T_1 ) ) ;
F_5 ( V_8 -> V_5 ) ;
V_22 = ( char * ) V_8 -> V_5 ;
V_23 = 56 ;
}
memset ( V_22 , 0 , V_23 ) ;
V_8 -> V_5 [ 14 ] = F_10 ( V_8 -> V_13 << 3 ) ;
V_8 -> V_5 [ 15 ] = F_10 ( V_8 -> V_13 >> 29 ) ;
F_5 ( V_8 -> V_5 ) ;
F_3 ( V_8 ) ;
F_13 ( & V_18 , V_19 ) ;
memcpy ( V_20 , V_8 -> V_3 , sizeof( V_8 -> V_3 ) ) ;
memset ( V_8 , 0 , sizeof( * V_8 ) ) ;
return 0 ;
}
static int F_15 ( struct V_6 * V_7 , void * V_20 )
{
struct V_1 * V_2 = F_9 ( V_7 ) ;
memcpy ( V_20 , V_2 , sizeof( * V_2 ) ) ;
return 0 ;
}
static int F_16 ( struct V_6 * V_7 , const void * V_24 )
{
struct V_1 * V_2 = F_9 ( V_7 ) ;
memcpy ( V_2 , V_24 , sizeof( * V_2 ) ) ;
return 0 ;
}
static int T_4 F_17 ( void )
{
if ( ! F_18 () )
return - V_25 ;
return F_19 ( & V_26 ) ;
}
static void T_5 F_20 ( void )
{
F_21 ( & V_26 ) ;
}
