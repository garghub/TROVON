static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
* V_4 = (struct V_3 ) {
. V_5 = { V_6 , V_7 , V_8 , V_9 , V_10 } ,
} ;
return 0 ;
}
static void F_3 ( struct V_3 * V_4 , const T_1 * V_11 ,
unsigned int V_12 , unsigned int V_13 )
{
unsigned int V_14 = 0 ;
V_4 -> V_15 += V_12 ;
if ( V_13 ) {
V_14 = V_16 - V_13 ;
memcpy ( V_4 -> V_17 + V_13 , V_11 , V_14 ) ;
F_4 ( V_4 -> V_5 , V_4 -> V_17 , 1 ) ;
}
if ( V_12 - V_14 >= V_16 ) {
const unsigned int V_18 = ( V_12 - V_14 ) / V_16 ;
F_4 ( V_4 -> V_5 , V_11 + V_14 , V_18 ) ;
V_14 += V_18 * V_16 ;
}
memcpy ( V_4 -> V_17 , V_11 + V_14 , V_12 - V_14 ) ;
}
static int F_5 ( struct V_1 * V_2 , const T_1 * V_11 ,
unsigned int V_12 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned int V_13 = V_4 -> V_15 % V_16 ;
if ( V_13 + V_12 < V_16 ) {
V_4 -> V_15 += V_12 ;
memcpy ( V_4 -> V_17 + V_13 , V_11 , V_12 ) ;
} else
F_3 ( V_4 , V_11 , V_12 , V_13 ) ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 , T_1 * V_19 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned int V_20 , V_21 , V_22 ;
T_2 * V_23 = ( T_2 * ) V_19 ;
T_3 V_24 ;
static const T_1 V_25 [ V_16 ] = { 0x80 , } ;
V_24 = F_7 ( V_4 -> V_15 << 3 ) ;
V_21 = V_4 -> V_15 % V_16 ;
V_22 = ( V_21 < 56 ) ? ( 56 - V_21 ) : ( ( V_16 + 56 ) - V_21 ) ;
if ( V_22 <= 56 ) {
V_4 -> V_15 += V_22 ;
memcpy ( V_4 -> V_17 + V_21 , V_25 , V_22 ) ;
} else {
F_3 ( V_4 , V_25 , V_22 , V_21 ) ;
}
F_3 ( V_4 , ( const T_1 * ) & V_24 , sizeof( V_24 ) , 56 ) ;
for ( V_20 = 0 ; V_20 < 5 ; V_20 ++ )
V_23 [ V_20 ] = F_8 ( V_4 -> V_5 [ V_20 ] ) ;
memset ( V_4 , 0 , sizeof( * V_4 ) ) ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 , void * V_19 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
memcpy ( V_19 , V_4 , sizeof( * V_4 ) ) ;
return 0 ;
}
static int F_10 ( struct V_1 * V_2 , const void * V_26 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
memcpy ( V_4 , V_26 , sizeof( * V_4 ) ) ;
return 0 ;
}
static bool T_4 F_11 ( void )
{
unsigned long V_27 ;
if ( ! ( V_28 & V_29 ) )
return false ;
__asm__ __volatile__("rd %%asr26, %0" : "=r" (cfr));
if ( ! ( V_27 & V_30 ) )
return false ;
return true ;
}
static int T_4 F_12 ( void )
{
if ( F_11 () ) {
F_13 ( L_1 ) ;
return F_14 ( & V_31 ) ;
}
F_13 ( L_2 ) ;
return - V_32 ;
}
static void T_5 F_15 ( void )
{
F_16 ( & V_31 ) ;
}
