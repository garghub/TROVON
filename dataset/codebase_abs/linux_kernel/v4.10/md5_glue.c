static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
V_4 -> V_5 [ 0 ] = F_3 ( V_6 ) ;
V_4 -> V_5 [ 1 ] = F_3 ( V_7 ) ;
V_4 -> V_5 [ 2 ] = F_3 ( V_8 ) ;
V_4 -> V_5 [ 3 ] = F_3 ( V_9 ) ;
V_4 -> V_10 = 0 ;
return 0 ;
}
static void F_4 ( struct V_3 * V_11 , const T_1 * V_12 ,
unsigned int V_13 , unsigned int V_14 )
{
unsigned int V_15 = 0 ;
V_11 -> V_10 += V_13 ;
if ( V_14 ) {
V_15 = V_16 - V_14 ;
memcpy ( ( T_1 * ) V_11 -> V_17 + V_14 , V_12 , V_15 ) ;
F_5 ( V_11 -> V_5 , ( T_1 * ) V_11 -> V_17 , 1 ) ;
}
if ( V_13 - V_15 >= V_16 ) {
const unsigned int V_18 = ( V_13 - V_15 ) / V_16 ;
F_5 ( V_11 -> V_5 , V_12 + V_15 , V_18 ) ;
V_15 += V_18 * V_16 ;
}
memcpy ( V_11 -> V_17 , V_12 + V_15 , V_13 - V_15 ) ;
}
static int F_6 ( struct V_1 * V_2 , const T_1 * V_12 ,
unsigned int V_13 )
{
struct V_3 * V_11 = F_2 ( V_2 ) ;
unsigned int V_14 = V_11 -> V_10 % V_16 ;
if ( V_14 + V_13 < V_16 ) {
V_11 -> V_10 += V_13 ;
memcpy ( ( T_1 * ) V_11 -> V_17 + V_14 , V_12 , V_13 ) ;
} else
F_4 ( V_11 , V_12 , V_13 , V_14 ) ;
return 0 ;
}
static int F_7 ( struct V_1 * V_2 , T_1 * V_19 )
{
struct V_3 * V_11 = F_2 ( V_2 ) ;
unsigned int V_20 , V_21 , V_22 ;
T_2 * V_23 = ( T_2 * ) V_19 ;
T_3 V_24 ;
static const T_1 V_25 [ V_16 ] = { 0x80 , } ;
V_24 = F_8 ( V_11 -> V_10 << 3 ) ;
V_21 = V_11 -> V_10 % V_16 ;
V_22 = ( V_21 < 56 ) ? ( 56 - V_21 ) : ( ( V_16 + 56 ) - V_21 ) ;
if ( V_22 <= 56 ) {
V_11 -> V_10 += V_22 ;
memcpy ( ( T_1 * ) V_11 -> V_17 + V_21 , V_25 , V_22 ) ;
} else {
F_4 ( V_11 , V_25 , V_22 , V_21 ) ;
}
F_4 ( V_11 , ( const T_1 * ) & V_24 , sizeof( V_24 ) , 56 ) ;
for ( V_20 = 0 ; V_20 < V_26 ; V_20 ++ )
V_23 [ V_20 ] = V_11 -> V_5 [ V_20 ] ;
memset ( V_11 , 0 , sizeof( * V_11 ) ) ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 , void * V_19 )
{
struct V_3 * V_11 = F_2 ( V_2 ) ;
memcpy ( V_19 , V_11 , sizeof( * V_11 ) ) ;
return 0 ;
}
static int F_10 ( struct V_1 * V_2 , const void * V_27 )
{
struct V_3 * V_11 = F_2 ( V_2 ) ;
memcpy ( V_11 , V_27 , sizeof( * V_11 ) ) ;
return 0 ;
}
static bool T_4 F_11 ( void )
{
unsigned long V_28 ;
if ( ! ( V_29 & V_30 ) )
return false ;
__asm__ __volatile__("rd %%asr26, %0" : "=r" (cfr));
if ( ! ( V_28 & V_31 ) )
return false ;
return true ;
}
static int T_4 F_12 ( void )
{
if ( F_11 () ) {
F_13 ( L_1 ) ;
return F_14 ( & V_32 ) ;
}
F_13 ( L_2 ) ;
return - V_33 ;
}
static void T_5 F_15 ( void )
{
F_16 ( & V_32 ) ;
}
