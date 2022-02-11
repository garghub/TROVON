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
V_2 -> V_7 [ 5 ] = V_13 ;
V_2 -> V_7 [ 6 ] = V_14 ;
V_2 -> V_7 [ 7 ] = V_15 ;
V_2 -> V_3 = 0 ;
return 0 ;
}
static int F_11 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = F_10 ( V_6 ) ;
V_2 -> V_7 [ 0 ] = V_16 ;
V_2 -> V_7 [ 1 ] = V_17 ;
V_2 -> V_7 [ 2 ] = V_18 ;
V_2 -> V_7 [ 3 ] = V_19 ;
V_2 -> V_7 [ 4 ] = V_20 ;
V_2 -> V_7 [ 5 ] = V_21 ;
V_2 -> V_7 [ 6 ] = V_22 ;
V_2 -> V_7 [ 7 ] = V_23 ;
V_2 -> V_3 = 0 ;
return 0 ;
}
static int F_12 ( struct V_5 * V_6 , const T_2 * V_24 ,
unsigned int V_25 )
{
struct V_1 * V_2 = F_10 ( V_6 ) ;
const unsigned int V_26 = V_2 -> V_3 & 0x3f ;
const unsigned int V_27 = 64 - V_26 ;
unsigned int V_28 ;
const T_2 * V_29 = V_24 ;
if ( V_27 > V_25 ) {
V_2 -> V_3 += V_25 ;
memcpy ( ( char * ) V_2 -> V_30 + V_26 , V_29 , V_25 ) ;
return 0 ;
}
V_2 -> V_3 += V_25 ;
if ( V_26 ) {
memcpy ( ( char * ) V_2 -> V_30 + V_26 , V_29 , V_27 ) ;
F_1 () ;
F_13 ( V_2 -> V_7 , ( const T_2 * ) V_2 -> V_30 , 1 ) ;
F_4 () ;
V_25 -= V_27 ;
V_29 += V_27 ;
}
while ( V_25 > 63 ) {
V_28 = ( V_25 > V_31 ) ? V_31 : V_25 ;
V_28 = V_28 & ~ 0x3f ;
F_1 () ;
F_13 ( V_2 -> V_7 , V_29 , V_28 >> 6 ) ;
F_4 () ;
V_29 += V_28 ;
V_25 -= V_28 ;
} ;
memcpy ( ( char * ) V_2 -> V_30 , V_29 , V_25 ) ;
return 0 ;
}
static int F_14 ( struct V_5 * V_6 , T_2 * V_32 )
{
struct V_1 * V_2 = F_10 ( V_6 ) ;
const unsigned int V_26 = V_2 -> V_3 & 0x3f ;
char * V_33 = ( char * ) V_2 -> V_30 + V_26 ;
int V_34 ;
T_3 * V_35 = ( T_3 * ) ( ( ( char * ) & V_2 -> V_30 ) + 56 ) ;
T_4 * V_36 = ( T_4 * ) V_32 ;
V_34 = 55 - V_26 ;
* V_33 ++ = 0x80 ;
F_1 () ;
if ( V_34 < 0 ) {
memset ( V_33 , 0x00 , V_34 + sizeof ( V_37 ) ) ;
F_13 ( V_2 -> V_7 , V_2 -> V_30 , 1 ) ;
V_33 = ( char * ) V_2 -> V_30 ;
V_34 = 56 ;
}
memset ( V_33 , 0 , V_34 ) ;
* V_35 = F_15 ( V_2 -> V_3 << 3 ) ;
F_13 ( V_2 -> V_7 , V_2 -> V_30 , 1 ) ;
F_4 () ;
V_36 [ 0 ] = F_16 ( V_2 -> V_7 [ 0 ] ) ;
V_36 [ 1 ] = F_16 ( V_2 -> V_7 [ 1 ] ) ;
V_36 [ 2 ] = F_16 ( V_2 -> V_7 [ 2 ] ) ;
V_36 [ 3 ] = F_16 ( V_2 -> V_7 [ 3 ] ) ;
V_36 [ 4 ] = F_16 ( V_2 -> V_7 [ 4 ] ) ;
V_36 [ 5 ] = F_16 ( V_2 -> V_7 [ 5 ] ) ;
V_36 [ 6 ] = F_16 ( V_2 -> V_7 [ 6 ] ) ;
V_36 [ 7 ] = F_16 ( V_2 -> V_7 [ 7 ] ) ;
F_7 ( V_2 ) ;
return 0 ;
}
static int F_17 ( struct V_5 * V_6 , T_2 * V_32 )
{
T_1 V_38 [ V_39 >> 2 ] ;
T_4 * V_36 = ( T_4 * ) V_32 ;
F_14 ( V_6 , ( T_2 * ) V_38 ) ;
V_36 [ 0 ] = V_38 [ 0 ] ;
V_36 [ 1 ] = V_38 [ 1 ] ;
V_36 [ 2 ] = V_38 [ 2 ] ;
V_36 [ 3 ] = V_38 [ 3 ] ;
V_36 [ 4 ] = V_38 [ 4 ] ;
V_36 [ 5 ] = V_38 [ 5 ] ;
V_36 [ 6 ] = V_38 [ 6 ] ;
F_18 ( V_38 , V_39 ) ;
return 0 ;
}
static int F_19 ( struct V_5 * V_6 , void * V_32 )
{
struct V_1 * V_2 = F_10 ( V_6 ) ;
memcpy ( V_32 , V_2 , sizeof( * V_2 ) ) ;
return 0 ;
}
static int F_20 ( struct V_5 * V_6 , const void * V_40 )
{
struct V_1 * V_2 = F_10 ( V_6 ) ;
memcpy ( V_2 , V_40 , sizeof( * V_2 ) ) ;
return 0 ;
}
static int T_5 F_21 ( void )
{
return F_22 ( V_41 , F_23 ( V_41 ) ) ;
}
static void T_6 F_24 ( void )
{
F_25 ( V_41 , F_23 ( V_41 ) ) ;
}
