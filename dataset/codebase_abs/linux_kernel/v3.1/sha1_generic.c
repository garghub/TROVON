static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
* V_4 = (struct V_3 ) {
. V_5 = { V_6 , V_7 , V_8 , V_9 , V_10 } ,
} ;
return 0 ;
}
static int F_3 ( struct V_1 * V_2 , const T_1 * V_11 ,
unsigned int V_12 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned int V_13 , V_14 ;
const T_1 * V_15 ;
V_13 = V_4 -> V_16 % V_17 ;
V_4 -> V_16 += V_12 ;
V_14 = 0 ;
V_15 = V_11 ;
if ( ( V_13 + V_12 ) >= V_17 ) {
T_2 V_18 [ V_19 ] ;
if ( V_13 ) {
V_14 = - V_13 ;
memcpy ( V_4 -> V_20 + V_13 , V_11 ,
V_14 + V_17 ) ;
V_15 = V_4 -> V_20 ;
}
do {
F_4 ( V_4 -> V_5 , V_15 , V_18 ) ;
V_14 += V_17 ;
V_15 = V_11 + V_14 ;
} while ( V_14 + V_17 <= V_12 );
memset ( V_18 , 0 , sizeof( V_18 ) ) ;
V_13 = 0 ;
}
memcpy ( V_4 -> V_20 + V_13 , V_15 , V_12 - V_14 ) ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 , T_1 * V_21 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_3 * V_22 = ( T_3 * ) V_21 ;
T_2 V_23 , V_24 , V_25 ;
T_4 V_26 ;
static const T_1 V_27 [ 64 ] = { 0x80 , } ;
V_26 = F_6 ( V_4 -> V_16 << 3 ) ;
V_24 = V_4 -> V_16 & 0x3f ;
V_25 = ( V_24 < 56 ) ? ( 56 - V_24 ) : ( ( 64 + 56 ) - V_24 ) ;
F_3 ( V_2 , V_27 , V_25 ) ;
F_3 ( V_2 , ( const T_1 * ) & V_26 , sizeof( V_26 ) ) ;
for ( V_23 = 0 ; V_23 < 5 ; V_23 ++ )
V_22 [ V_23 ] = F_7 ( V_4 -> V_5 [ V_23 ] ) ;
memset ( V_4 , 0 , sizeof *V_4 ) ;
return 0 ;
}
static int F_8 ( struct V_1 * V_2 , void * V_21 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
memcpy ( V_21 , V_4 , sizeof( * V_4 ) ) ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 , const void * V_28 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
memcpy ( V_4 , V_28 , sizeof( * V_4 ) ) ;
return 0 ;
}
static int T_5 F_10 ( void )
{
return F_11 ( & V_29 ) ;
}
static void T_6 F_12 ( void )
{
F_13 ( & V_29 ) ;
}
