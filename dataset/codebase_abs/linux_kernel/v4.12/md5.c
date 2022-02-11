static inline void F_1 ( T_1 * V_1 , unsigned int V_2 )
{
while ( V_2 -- ) {
F_2 ( V_1 ) ;
V_1 ++ ;
}
}
static inline void F_3 ( T_1 * V_1 , unsigned int V_2 )
{
while ( V_2 -- ) {
F_4 ( V_1 ) ;
V_1 ++ ;
}
}
static void F_5 ( T_2 * V_3 , T_2 const * V_4 )
{
T_1 V_5 , V_6 , V_7 , V_8 ;
V_5 = V_3 [ 0 ] ;
V_6 = V_3 [ 1 ] ;
V_7 = V_3 [ 2 ] ;
V_8 = V_3 [ 3 ] ;
F_6 ( V_9 , V_5 , V_6 , V_7 , V_8 , V_4 [ 0 ] + 0xd76aa478 , 7 ) ;
F_6 ( V_9 , V_8 , V_5 , V_6 , V_7 , V_4 [ 1 ] + 0xe8c7b756 , 12 ) ;
F_6 ( V_9 , V_7 , V_8 , V_5 , V_6 , V_4 [ 2 ] + 0x242070db , 17 ) ;
F_6 ( V_9 , V_6 , V_7 , V_8 , V_5 , V_4 [ 3 ] + 0xc1bdceee , 22 ) ;
F_6 ( V_9 , V_5 , V_6 , V_7 , V_8 , V_4 [ 4 ] + 0xf57c0faf , 7 ) ;
F_6 ( V_9 , V_8 , V_5 , V_6 , V_7 , V_4 [ 5 ] + 0x4787c62a , 12 ) ;
F_6 ( V_9 , V_7 , V_8 , V_5 , V_6 , V_4 [ 6 ] + 0xa8304613 , 17 ) ;
F_6 ( V_9 , V_6 , V_7 , V_8 , V_5 , V_4 [ 7 ] + 0xfd469501 , 22 ) ;
F_6 ( V_9 , V_5 , V_6 , V_7 , V_8 , V_4 [ 8 ] + 0x698098d8 , 7 ) ;
F_6 ( V_9 , V_8 , V_5 , V_6 , V_7 , V_4 [ 9 ] + 0x8b44f7af , 12 ) ;
F_6 ( V_9 , V_7 , V_8 , V_5 , V_6 , V_4 [ 10 ] + 0xffff5bb1 , 17 ) ;
F_6 ( V_9 , V_6 , V_7 , V_8 , V_5 , V_4 [ 11 ] + 0x895cd7be , 22 ) ;
F_6 ( V_9 , V_5 , V_6 , V_7 , V_8 , V_4 [ 12 ] + 0x6b901122 , 7 ) ;
F_6 ( V_9 , V_8 , V_5 , V_6 , V_7 , V_4 [ 13 ] + 0xfd987193 , 12 ) ;
F_6 ( V_9 , V_7 , V_8 , V_5 , V_6 , V_4 [ 14 ] + 0xa679438e , 17 ) ;
F_6 ( V_9 , V_6 , V_7 , V_8 , V_5 , V_4 [ 15 ] + 0x49b40821 , 22 ) ;
F_6 ( V_10 , V_5 , V_6 , V_7 , V_8 , V_4 [ 1 ] + 0xf61e2562 , 5 ) ;
F_6 ( V_10 , V_8 , V_5 , V_6 , V_7 , V_4 [ 6 ] + 0xc040b340 , 9 ) ;
F_6 ( V_10 , V_7 , V_8 , V_5 , V_6 , V_4 [ 11 ] + 0x265e5a51 , 14 ) ;
F_6 ( V_10 , V_6 , V_7 , V_8 , V_5 , V_4 [ 0 ] + 0xe9b6c7aa , 20 ) ;
F_6 ( V_10 , V_5 , V_6 , V_7 , V_8 , V_4 [ 5 ] + 0xd62f105d , 5 ) ;
F_6 ( V_10 , V_8 , V_5 , V_6 , V_7 , V_4 [ 10 ] + 0x02441453 , 9 ) ;
F_6 ( V_10 , V_7 , V_8 , V_5 , V_6 , V_4 [ 15 ] + 0xd8a1e681 , 14 ) ;
F_6 ( V_10 , V_6 , V_7 , V_8 , V_5 , V_4 [ 4 ] + 0xe7d3fbc8 , 20 ) ;
F_6 ( V_10 , V_5 , V_6 , V_7 , V_8 , V_4 [ 9 ] + 0x21e1cde6 , 5 ) ;
F_6 ( V_10 , V_8 , V_5 , V_6 , V_7 , V_4 [ 14 ] + 0xc33707d6 , 9 ) ;
F_6 ( V_10 , V_7 , V_8 , V_5 , V_6 , V_4 [ 3 ] + 0xf4d50d87 , 14 ) ;
F_6 ( V_10 , V_6 , V_7 , V_8 , V_5 , V_4 [ 8 ] + 0x455a14ed , 20 ) ;
F_6 ( V_10 , V_5 , V_6 , V_7 , V_8 , V_4 [ 13 ] + 0xa9e3e905 , 5 ) ;
F_6 ( V_10 , V_8 , V_5 , V_6 , V_7 , V_4 [ 2 ] + 0xfcefa3f8 , 9 ) ;
F_6 ( V_10 , V_7 , V_8 , V_5 , V_6 , V_4 [ 7 ] + 0x676f02d9 , 14 ) ;
F_6 ( V_10 , V_6 , V_7 , V_8 , V_5 , V_4 [ 12 ] + 0x8d2a4c8a , 20 ) ;
F_6 ( V_11 , V_5 , V_6 , V_7 , V_8 , V_4 [ 5 ] + 0xfffa3942 , 4 ) ;
F_6 ( V_11 , V_8 , V_5 , V_6 , V_7 , V_4 [ 8 ] + 0x8771f681 , 11 ) ;
F_6 ( V_11 , V_7 , V_8 , V_5 , V_6 , V_4 [ 11 ] + 0x6d9d6122 , 16 ) ;
F_6 ( V_11 , V_6 , V_7 , V_8 , V_5 , V_4 [ 14 ] + 0xfde5380c , 23 ) ;
F_6 ( V_11 , V_5 , V_6 , V_7 , V_8 , V_4 [ 1 ] + 0xa4beea44 , 4 ) ;
F_6 ( V_11 , V_8 , V_5 , V_6 , V_7 , V_4 [ 4 ] + 0x4bdecfa9 , 11 ) ;
F_6 ( V_11 , V_7 , V_8 , V_5 , V_6 , V_4 [ 7 ] + 0xf6bb4b60 , 16 ) ;
F_6 ( V_11 , V_6 , V_7 , V_8 , V_5 , V_4 [ 10 ] + 0xbebfbc70 , 23 ) ;
F_6 ( V_11 , V_5 , V_6 , V_7 , V_8 , V_4 [ 13 ] + 0x289b7ec6 , 4 ) ;
F_6 ( V_11 , V_8 , V_5 , V_6 , V_7 , V_4 [ 0 ] + 0xeaa127fa , 11 ) ;
F_6 ( V_11 , V_7 , V_8 , V_5 , V_6 , V_4 [ 3 ] + 0xd4ef3085 , 16 ) ;
F_6 ( V_11 , V_6 , V_7 , V_8 , V_5 , V_4 [ 6 ] + 0x04881d05 , 23 ) ;
F_6 ( V_11 , V_5 , V_6 , V_7 , V_8 , V_4 [ 9 ] + 0xd9d4d039 , 4 ) ;
F_6 ( V_11 , V_8 , V_5 , V_6 , V_7 , V_4 [ 12 ] + 0xe6db99e5 , 11 ) ;
F_6 ( V_11 , V_7 , V_8 , V_5 , V_6 , V_4 [ 15 ] + 0x1fa27cf8 , 16 ) ;
F_6 ( V_11 , V_6 , V_7 , V_8 , V_5 , V_4 [ 2 ] + 0xc4ac5665 , 23 ) ;
F_6 ( V_12 , V_5 , V_6 , V_7 , V_8 , V_4 [ 0 ] + 0xf4292244 , 6 ) ;
F_6 ( V_12 , V_8 , V_5 , V_6 , V_7 , V_4 [ 7 ] + 0x432aff97 , 10 ) ;
F_6 ( V_12 , V_7 , V_8 , V_5 , V_6 , V_4 [ 14 ] + 0xab9423a7 , 15 ) ;
F_6 ( V_12 , V_6 , V_7 , V_8 , V_5 , V_4 [ 5 ] + 0xfc93a039 , 21 ) ;
F_6 ( V_12 , V_5 , V_6 , V_7 , V_8 , V_4 [ 12 ] + 0x655b59c3 , 6 ) ;
F_6 ( V_12 , V_8 , V_5 , V_6 , V_7 , V_4 [ 3 ] + 0x8f0ccc92 , 10 ) ;
F_6 ( V_12 , V_7 , V_8 , V_5 , V_6 , V_4 [ 10 ] + 0xffeff47d , 15 ) ;
F_6 ( V_12 , V_6 , V_7 , V_8 , V_5 , V_4 [ 1 ] + 0x85845dd1 , 21 ) ;
F_6 ( V_12 , V_5 , V_6 , V_7 , V_8 , V_4 [ 8 ] + 0x6fa87e4f , 6 ) ;
F_6 ( V_12 , V_8 , V_5 , V_6 , V_7 , V_4 [ 15 ] + 0xfe2ce6e0 , 10 ) ;
F_6 ( V_12 , V_7 , V_8 , V_5 , V_6 , V_4 [ 6 ] + 0xa3014314 , 15 ) ;
F_6 ( V_12 , V_6 , V_7 , V_8 , V_5 , V_4 [ 13 ] + 0x4e0811a1 , 21 ) ;
F_6 ( V_12 , V_5 , V_6 , V_7 , V_8 , V_4 [ 4 ] + 0xf7537e82 , 6 ) ;
F_6 ( V_12 , V_8 , V_5 , V_6 , V_7 , V_4 [ 11 ] + 0xbd3af235 , 10 ) ;
F_6 ( V_12 , V_7 , V_8 , V_5 , V_6 , V_4 [ 2 ] + 0x2ad7d2bb , 15 ) ;
F_6 ( V_12 , V_6 , V_7 , V_8 , V_5 , V_4 [ 9 ] + 0xeb86d391 , 21 ) ;
V_3 [ 0 ] += V_5 ;
V_3 [ 1 ] += V_6 ;
V_3 [ 2 ] += V_7 ;
V_3 [ 3 ] += V_8 ;
}
static inline void F_7 ( struct V_13 * V_14 )
{
F_1 ( V_14 -> V_15 , sizeof( V_14 -> V_15 ) / sizeof( T_1 ) ) ;
F_5 ( V_14 -> V_3 , V_14 -> V_15 ) ;
}
static int F_8 ( struct V_16 * V_17 )
{
struct V_13 * V_18 = F_9 ( V_17 ) ;
V_18 -> V_3 [ 0 ] = V_19 ;
V_18 -> V_3 [ 1 ] = V_20 ;
V_18 -> V_3 [ 2 ] = V_21 ;
V_18 -> V_3 [ 3 ] = V_22 ;
V_18 -> V_23 = 0 ;
return 0 ;
}
static int F_10 ( struct V_16 * V_17 , const T_3 * V_24 , unsigned int V_25 )
{
struct V_13 * V_18 = F_9 ( V_17 ) ;
const T_1 V_26 = sizeof( V_18 -> V_15 ) - ( V_18 -> V_23 & 0x3f ) ;
V_18 -> V_23 += V_25 ;
if ( V_26 > V_25 ) {
memcpy ( ( char * ) V_18 -> V_15 + ( sizeof( V_18 -> V_15 ) - V_26 ) ,
V_24 , V_25 ) ;
return 0 ;
}
memcpy ( ( char * ) V_18 -> V_15 + ( sizeof( V_18 -> V_15 ) - V_26 ) ,
V_24 , V_26 ) ;
F_7 ( V_18 ) ;
V_24 += V_26 ;
V_25 -= V_26 ;
while ( V_25 >= sizeof( V_18 -> V_15 ) ) {
memcpy ( V_18 -> V_15 , V_24 , sizeof( V_18 -> V_15 ) ) ;
F_7 ( V_18 ) ;
V_24 += sizeof( V_18 -> V_15 ) ;
V_25 -= sizeof( V_18 -> V_15 ) ;
}
memcpy ( V_18 -> V_15 , V_24 , V_25 ) ;
return 0 ;
}
static int F_11 ( struct V_16 * V_17 , T_3 * V_27 )
{
struct V_13 * V_18 = F_9 ( V_17 ) ;
const unsigned int V_28 = V_18 -> V_23 & 0x3f ;
char * V_29 = ( char * ) V_18 -> V_15 + V_28 ;
int V_30 = 56 - ( V_28 + 1 ) ;
* V_29 ++ = 0x80 ;
if ( V_30 < 0 ) {
memset ( V_29 , 0x00 , V_30 + sizeof ( V_31 ) ) ;
F_7 ( V_18 ) ;
V_29 = ( char * ) V_18 -> V_15 ;
V_30 = 56 ;
}
memset ( V_29 , 0 , V_30 ) ;
V_18 -> V_15 [ 14 ] = V_18 -> V_23 << 3 ;
V_18 -> V_15 [ 15 ] = V_18 -> V_23 >> 29 ;
F_1 ( V_18 -> V_15 , ( sizeof( V_18 -> V_15 ) -
sizeof( V_31 ) ) / sizeof( T_1 ) ) ;
F_5 ( V_18 -> V_3 , V_18 -> V_15 ) ;
F_3 ( V_18 -> V_3 , sizeof( V_18 -> V_3 ) / sizeof( T_1 ) ) ;
memcpy ( V_27 , V_18 -> V_3 , sizeof( V_18 -> V_3 ) ) ;
memset ( V_18 , 0 , sizeof( * V_18 ) ) ;
return 0 ;
}
static int F_12 ( struct V_16 * V_17 , void * V_27 )
{
struct V_13 * V_14 = F_9 ( V_17 ) ;
memcpy ( V_27 , V_14 , sizeof( * V_14 ) ) ;
return 0 ;
}
static int F_13 ( struct V_16 * V_17 , const void * V_4 )
{
struct V_13 * V_14 = F_9 ( V_17 ) ;
memcpy ( V_14 , V_4 , sizeof( * V_14 ) ) ;
return 0 ;
}
static int T_4 F_14 ( void )
{
return F_15 ( & V_32 ) ;
}
static void T_5 F_16 ( void )
{
F_17 ( & V_32 ) ;
}
