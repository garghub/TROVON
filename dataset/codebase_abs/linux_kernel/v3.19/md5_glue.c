static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
V_4 -> V_5 [ 0 ] = F_3 ( 0x67452301 ) ;
V_4 -> V_5 [ 1 ] = F_3 ( 0xefcdab89 ) ;
V_4 -> V_5 [ 2 ] = F_3 ( 0x98badcfe ) ;
V_4 -> V_5 [ 3 ] = F_3 ( 0x10325476 ) ;
V_4 -> V_6 = 0 ;
return 0 ;
}
static void F_4 ( struct V_3 * V_7 , const T_1 * V_8 ,
unsigned int V_9 , unsigned int V_10 )
{
unsigned int V_11 = 0 ;
V_7 -> V_6 += V_9 ;
if ( V_10 ) {
V_11 = V_12 - V_10 ;
memcpy ( ( T_1 * ) V_7 -> V_13 + V_10 , V_8 , V_11 ) ;
F_5 ( V_7 -> V_5 , ( T_1 * ) V_7 -> V_13 , 1 ) ;
}
if ( V_9 - V_11 >= V_12 ) {
const unsigned int V_14 = ( V_9 - V_11 ) / V_12 ;
F_5 ( V_7 -> V_5 , V_8 + V_11 , V_14 ) ;
V_11 += V_14 * V_12 ;
}
memcpy ( V_7 -> V_13 , V_8 + V_11 , V_9 - V_11 ) ;
}
static int F_6 ( struct V_1 * V_2 , const T_1 * V_8 ,
unsigned int V_9 )
{
struct V_3 * V_7 = F_2 ( V_2 ) ;
unsigned int V_10 = V_7 -> V_6 % V_12 ;
if ( V_10 + V_9 < V_12 ) {
V_7 -> V_6 += V_9 ;
memcpy ( ( T_1 * ) V_7 -> V_13 + V_10 , V_8 , V_9 ) ;
} else
F_4 ( V_7 , V_8 , V_9 , V_10 ) ;
return 0 ;
}
static int F_7 ( struct V_1 * V_2 , T_1 * V_15 )
{
struct V_3 * V_7 = F_2 ( V_2 ) ;
unsigned int V_16 , V_17 , V_18 ;
T_2 * V_19 = ( T_2 * ) V_15 ;
T_3 V_20 ;
static const T_1 V_21 [ V_12 ] = { 0x80 , } ;
V_20 = F_8 ( V_7 -> V_6 << 3 ) ;
V_17 = V_7 -> V_6 % V_12 ;
V_18 = ( V_17 < 56 ) ? ( 56 - V_17 ) : ( ( V_12 + 56 ) - V_17 ) ;
if ( V_18 <= 56 ) {
V_7 -> V_6 += V_18 ;
memcpy ( ( T_1 * ) V_7 -> V_13 + V_17 , V_21 , V_18 ) ;
} else {
F_4 ( V_7 , V_21 , V_18 , V_17 ) ;
}
F_4 ( V_7 , ( const T_1 * ) & V_20 , sizeof( V_20 ) , 56 ) ;
for ( V_16 = 0 ; V_16 < V_22 ; V_16 ++ )
V_19 [ V_16 ] = V_7 -> V_5 [ V_16 ] ;
memset ( V_7 , 0 , sizeof( * V_7 ) ) ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 , void * V_15 )
{
struct V_3 * V_7 = F_2 ( V_2 ) ;
memcpy ( V_15 , V_7 , sizeof( * V_7 ) ) ;
return 0 ;
}
static int F_10 ( struct V_1 * V_2 , const void * V_23 )
{
struct V_3 * V_7 = F_2 ( V_2 ) ;
memcpy ( V_7 , V_23 , sizeof( * V_7 ) ) ;
return 0 ;
}
static bool T_4 F_11 ( void )
{
unsigned long V_24 ;
if ( ! ( V_25 & V_26 ) )
return false ;
__asm__ __volatile__("rd %%asr26, %0" : "=r" (cfr));
if ( ! ( V_24 & V_27 ) )
return false ;
return true ;
}
static int T_4 F_12 ( void )
{
if ( F_11 () ) {
F_13 ( L_1 ) ;
return F_14 ( & V_28 ) ;
}
F_13 ( L_2 ) ;
return - V_29 ;
}
static void T_5 F_15 ( void )
{
F_16 ( & V_28 ) ;
}
