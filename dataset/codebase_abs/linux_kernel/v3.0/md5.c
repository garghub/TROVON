static void F_1 ( T_1 * V_1 , T_1 const * V_2 )
{
T_1 V_3 , V_4 , V_5 , V_6 ;
V_3 = V_1 [ 0 ] ;
V_4 = V_1 [ 1 ] ;
V_5 = V_1 [ 2 ] ;
V_6 = V_1 [ 3 ] ;
F_2 ( V_7 , V_3 , V_4 , V_5 , V_6 , V_2 [ 0 ] + 0xd76aa478 , 7 ) ;
F_2 ( V_7 , V_6 , V_3 , V_4 , V_5 , V_2 [ 1 ] + 0xe8c7b756 , 12 ) ;
F_2 ( V_7 , V_5 , V_6 , V_3 , V_4 , V_2 [ 2 ] + 0x242070db , 17 ) ;
F_2 ( V_7 , V_4 , V_5 , V_6 , V_3 , V_2 [ 3 ] + 0xc1bdceee , 22 ) ;
F_2 ( V_7 , V_3 , V_4 , V_5 , V_6 , V_2 [ 4 ] + 0xf57c0faf , 7 ) ;
F_2 ( V_7 , V_6 , V_3 , V_4 , V_5 , V_2 [ 5 ] + 0x4787c62a , 12 ) ;
F_2 ( V_7 , V_5 , V_6 , V_3 , V_4 , V_2 [ 6 ] + 0xa8304613 , 17 ) ;
F_2 ( V_7 , V_4 , V_5 , V_6 , V_3 , V_2 [ 7 ] + 0xfd469501 , 22 ) ;
F_2 ( V_7 , V_3 , V_4 , V_5 , V_6 , V_2 [ 8 ] + 0x698098d8 , 7 ) ;
F_2 ( V_7 , V_6 , V_3 , V_4 , V_5 , V_2 [ 9 ] + 0x8b44f7af , 12 ) ;
F_2 ( V_7 , V_5 , V_6 , V_3 , V_4 , V_2 [ 10 ] + 0xffff5bb1 , 17 ) ;
F_2 ( V_7 , V_4 , V_5 , V_6 , V_3 , V_2 [ 11 ] + 0x895cd7be , 22 ) ;
F_2 ( V_7 , V_3 , V_4 , V_5 , V_6 , V_2 [ 12 ] + 0x6b901122 , 7 ) ;
F_2 ( V_7 , V_6 , V_3 , V_4 , V_5 , V_2 [ 13 ] + 0xfd987193 , 12 ) ;
F_2 ( V_7 , V_5 , V_6 , V_3 , V_4 , V_2 [ 14 ] + 0xa679438e , 17 ) ;
F_2 ( V_7 , V_4 , V_5 , V_6 , V_3 , V_2 [ 15 ] + 0x49b40821 , 22 ) ;
F_2 ( V_8 , V_3 , V_4 , V_5 , V_6 , V_2 [ 1 ] + 0xf61e2562 , 5 ) ;
F_2 ( V_8 , V_6 , V_3 , V_4 , V_5 , V_2 [ 6 ] + 0xc040b340 , 9 ) ;
F_2 ( V_8 , V_5 , V_6 , V_3 , V_4 , V_2 [ 11 ] + 0x265e5a51 , 14 ) ;
F_2 ( V_8 , V_4 , V_5 , V_6 , V_3 , V_2 [ 0 ] + 0xe9b6c7aa , 20 ) ;
F_2 ( V_8 , V_3 , V_4 , V_5 , V_6 , V_2 [ 5 ] + 0xd62f105d , 5 ) ;
F_2 ( V_8 , V_6 , V_3 , V_4 , V_5 , V_2 [ 10 ] + 0x02441453 , 9 ) ;
F_2 ( V_8 , V_5 , V_6 , V_3 , V_4 , V_2 [ 15 ] + 0xd8a1e681 , 14 ) ;
F_2 ( V_8 , V_4 , V_5 , V_6 , V_3 , V_2 [ 4 ] + 0xe7d3fbc8 , 20 ) ;
F_2 ( V_8 , V_3 , V_4 , V_5 , V_6 , V_2 [ 9 ] + 0x21e1cde6 , 5 ) ;
F_2 ( V_8 , V_6 , V_3 , V_4 , V_5 , V_2 [ 14 ] + 0xc33707d6 , 9 ) ;
F_2 ( V_8 , V_5 , V_6 , V_3 , V_4 , V_2 [ 3 ] + 0xf4d50d87 , 14 ) ;
F_2 ( V_8 , V_4 , V_5 , V_6 , V_3 , V_2 [ 8 ] + 0x455a14ed , 20 ) ;
F_2 ( V_8 , V_3 , V_4 , V_5 , V_6 , V_2 [ 13 ] + 0xa9e3e905 , 5 ) ;
F_2 ( V_8 , V_6 , V_3 , V_4 , V_5 , V_2 [ 2 ] + 0xfcefa3f8 , 9 ) ;
F_2 ( V_8 , V_5 , V_6 , V_3 , V_4 , V_2 [ 7 ] + 0x676f02d9 , 14 ) ;
F_2 ( V_8 , V_4 , V_5 , V_6 , V_3 , V_2 [ 12 ] + 0x8d2a4c8a , 20 ) ;
F_2 ( V_9 , V_3 , V_4 , V_5 , V_6 , V_2 [ 5 ] + 0xfffa3942 , 4 ) ;
F_2 ( V_9 , V_6 , V_3 , V_4 , V_5 , V_2 [ 8 ] + 0x8771f681 , 11 ) ;
F_2 ( V_9 , V_5 , V_6 , V_3 , V_4 , V_2 [ 11 ] + 0x6d9d6122 , 16 ) ;
F_2 ( V_9 , V_4 , V_5 , V_6 , V_3 , V_2 [ 14 ] + 0xfde5380c , 23 ) ;
F_2 ( V_9 , V_3 , V_4 , V_5 , V_6 , V_2 [ 1 ] + 0xa4beea44 , 4 ) ;
F_2 ( V_9 , V_6 , V_3 , V_4 , V_5 , V_2 [ 4 ] + 0x4bdecfa9 , 11 ) ;
F_2 ( V_9 , V_5 , V_6 , V_3 , V_4 , V_2 [ 7 ] + 0xf6bb4b60 , 16 ) ;
F_2 ( V_9 , V_4 , V_5 , V_6 , V_3 , V_2 [ 10 ] + 0xbebfbc70 , 23 ) ;
F_2 ( V_9 , V_3 , V_4 , V_5 , V_6 , V_2 [ 13 ] + 0x289b7ec6 , 4 ) ;
F_2 ( V_9 , V_6 , V_3 , V_4 , V_5 , V_2 [ 0 ] + 0xeaa127fa , 11 ) ;
F_2 ( V_9 , V_5 , V_6 , V_3 , V_4 , V_2 [ 3 ] + 0xd4ef3085 , 16 ) ;
F_2 ( V_9 , V_4 , V_5 , V_6 , V_3 , V_2 [ 6 ] + 0x04881d05 , 23 ) ;
F_2 ( V_9 , V_3 , V_4 , V_5 , V_6 , V_2 [ 9 ] + 0xd9d4d039 , 4 ) ;
F_2 ( V_9 , V_6 , V_3 , V_4 , V_5 , V_2 [ 12 ] + 0xe6db99e5 , 11 ) ;
F_2 ( V_9 , V_5 , V_6 , V_3 , V_4 , V_2 [ 15 ] + 0x1fa27cf8 , 16 ) ;
F_2 ( V_9 , V_4 , V_5 , V_6 , V_3 , V_2 [ 2 ] + 0xc4ac5665 , 23 ) ;
F_2 ( V_10 , V_3 , V_4 , V_5 , V_6 , V_2 [ 0 ] + 0xf4292244 , 6 ) ;
F_2 ( V_10 , V_6 , V_3 , V_4 , V_5 , V_2 [ 7 ] + 0x432aff97 , 10 ) ;
F_2 ( V_10 , V_5 , V_6 , V_3 , V_4 , V_2 [ 14 ] + 0xab9423a7 , 15 ) ;
F_2 ( V_10 , V_4 , V_5 , V_6 , V_3 , V_2 [ 5 ] + 0xfc93a039 , 21 ) ;
F_2 ( V_10 , V_3 , V_4 , V_5 , V_6 , V_2 [ 12 ] + 0x655b59c3 , 6 ) ;
F_2 ( V_10 , V_6 , V_3 , V_4 , V_5 , V_2 [ 3 ] + 0x8f0ccc92 , 10 ) ;
F_2 ( V_10 , V_5 , V_6 , V_3 , V_4 , V_2 [ 10 ] + 0xffeff47d , 15 ) ;
F_2 ( V_10 , V_4 , V_5 , V_6 , V_3 , V_2 [ 1 ] + 0x85845dd1 , 21 ) ;
F_2 ( V_10 , V_3 , V_4 , V_5 , V_6 , V_2 [ 8 ] + 0x6fa87e4f , 6 ) ;
F_2 ( V_10 , V_6 , V_3 , V_4 , V_5 , V_2 [ 15 ] + 0xfe2ce6e0 , 10 ) ;
F_2 ( V_10 , V_5 , V_6 , V_3 , V_4 , V_2 [ 6 ] + 0xa3014314 , 15 ) ;
F_2 ( V_10 , V_4 , V_5 , V_6 , V_3 , V_2 [ 13 ] + 0x4e0811a1 , 21 ) ;
F_2 ( V_10 , V_3 , V_4 , V_5 , V_6 , V_2 [ 4 ] + 0xf7537e82 , 6 ) ;
F_2 ( V_10 , V_6 , V_3 , V_4 , V_5 , V_2 [ 11 ] + 0xbd3af235 , 10 ) ;
F_2 ( V_10 , V_5 , V_6 , V_3 , V_4 , V_2 [ 2 ] + 0x2ad7d2bb , 15 ) ;
F_2 ( V_10 , V_4 , V_5 , V_6 , V_3 , V_2 [ 9 ] + 0xeb86d391 , 21 ) ;
V_1 [ 0 ] += V_3 ;
V_1 [ 1 ] += V_4 ;
V_1 [ 2 ] += V_5 ;
V_1 [ 3 ] += V_6 ;
}
static inline void F_3 ( T_1 * V_11 , unsigned int V_12 )
{
while ( V_12 -- ) {
F_4 ( V_11 ) ;
V_11 ++ ;
}
}
static inline void F_5 ( T_1 * V_11 , unsigned int V_12 )
{
while ( V_12 -- ) {
F_6 ( V_11 ) ;
V_11 ++ ;
}
}
static inline void F_7 ( struct V_13 * V_14 )
{
F_3 ( V_14 -> V_15 , sizeof( V_14 -> V_15 ) / sizeof( T_1 ) ) ;
F_1 ( V_14 -> V_1 , V_14 -> V_15 ) ;
}
static int F_8 ( struct V_16 * V_17 )
{
struct V_13 * V_18 = F_9 ( V_17 ) ;
V_18 -> V_1 [ 0 ] = 0x67452301 ;
V_18 -> V_1 [ 1 ] = 0xefcdab89 ;
V_18 -> V_1 [ 2 ] = 0x98badcfe ;
V_18 -> V_1 [ 3 ] = 0x10325476 ;
V_18 -> V_19 = 0 ;
return 0 ;
}
static int F_10 ( struct V_16 * V_17 , const T_2 * V_20 , unsigned int V_21 )
{
struct V_13 * V_18 = F_9 ( V_17 ) ;
const T_1 V_22 = sizeof( V_18 -> V_15 ) - ( V_18 -> V_19 & 0x3f ) ;
V_18 -> V_19 += V_21 ;
if ( V_22 > V_21 ) {
memcpy ( ( char * ) V_18 -> V_15 + ( sizeof( V_18 -> V_15 ) - V_22 ) ,
V_20 , V_21 ) ;
return 0 ;
}
memcpy ( ( char * ) V_18 -> V_15 + ( sizeof( V_18 -> V_15 ) - V_22 ) ,
V_20 , V_22 ) ;
F_7 ( V_18 ) ;
V_20 += V_22 ;
V_21 -= V_22 ;
while ( V_21 >= sizeof( V_18 -> V_15 ) ) {
memcpy ( V_18 -> V_15 , V_20 , sizeof( V_18 -> V_15 ) ) ;
F_7 ( V_18 ) ;
V_20 += sizeof( V_18 -> V_15 ) ;
V_21 -= sizeof( V_18 -> V_15 ) ;
}
memcpy ( V_18 -> V_15 , V_20 , V_21 ) ;
return 0 ;
}
static int F_11 ( struct V_16 * V_17 , T_2 * V_23 )
{
struct V_13 * V_18 = F_9 ( V_17 ) ;
const unsigned int V_24 = V_18 -> V_19 & 0x3f ;
char * V_25 = ( char * ) V_18 -> V_15 + V_24 ;
int V_26 = 56 - ( V_24 + 1 ) ;
* V_25 ++ = 0x80 ;
if ( V_26 < 0 ) {
memset ( V_25 , 0x00 , V_26 + sizeof ( V_27 ) ) ;
F_7 ( V_18 ) ;
V_25 = ( char * ) V_18 -> V_15 ;
V_26 = 56 ;
}
memset ( V_25 , 0 , V_26 ) ;
V_18 -> V_15 [ 14 ] = V_18 -> V_19 << 3 ;
V_18 -> V_15 [ 15 ] = V_18 -> V_19 >> 29 ;
F_3 ( V_18 -> V_15 , ( sizeof( V_18 -> V_15 ) -
sizeof( V_27 ) ) / sizeof( T_1 ) ) ;
F_1 ( V_18 -> V_1 , V_18 -> V_15 ) ;
F_5 ( V_18 -> V_1 , sizeof( V_18 -> V_1 ) / sizeof( T_1 ) ) ;
memcpy ( V_23 , V_18 -> V_1 , sizeof( V_18 -> V_1 ) ) ;
memset ( V_18 , 0 , sizeof( * V_18 ) ) ;
return 0 ;
}
static int F_12 ( struct V_16 * V_17 , void * V_23 )
{
struct V_13 * V_14 = F_9 ( V_17 ) ;
memcpy ( V_23 , V_14 , sizeof( * V_14 ) ) ;
return 0 ;
}
static int F_13 ( struct V_16 * V_17 , const void * V_2 )
{
struct V_13 * V_14 = F_9 ( V_17 ) ;
memcpy ( V_14 , V_2 , sizeof( * V_14 ) ) ;
return 0 ;
}
static int T_3 F_14 ( void )
{
return F_15 ( & V_28 ) ;
}
static void T_4 F_16 ( void )
{
F_17 ( & V_28 ) ;
}
