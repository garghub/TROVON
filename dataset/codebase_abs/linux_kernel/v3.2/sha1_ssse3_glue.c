static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
* V_4 = (struct V_3 ) {
. V_5 = { V_6 , V_7 , V_8 , V_9 , V_10 } ,
} ;
return 0 ;
}
static int F_3 ( struct V_1 * V_2 , const T_1 * V_11 ,
unsigned int V_12 , unsigned int V_13 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
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
return 0 ;
}
static int F_5 ( struct V_1 * V_2 , const T_1 * V_11 ,
unsigned int V_12 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned int V_13 = V_4 -> V_15 % V_16 ;
int V_19 ;
if ( V_13 + V_12 < V_16 ) {
V_4 -> V_15 += V_12 ;
memcpy ( V_4 -> V_17 + V_13 , V_11 , V_12 ) ;
return 0 ;
}
if ( ! F_6 () ) {
V_19 = F_7 ( V_2 , V_11 , V_12 ) ;
} else {
F_8 () ;
V_19 = F_3 ( V_2 , V_11 , V_12 , V_13 ) ;
F_9 () ;
}
return V_19 ;
}
static int F_10 ( struct V_1 * V_2 , T_1 * V_20 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned int V_21 , V_22 , V_23 ;
T_2 * V_24 = ( T_2 * ) V_20 ;
T_3 V_25 ;
static const T_1 V_26 [ V_16 ] = { 0x80 , } ;
V_25 = F_11 ( V_4 -> V_15 << 3 ) ;
V_22 = V_4 -> V_15 % V_16 ;
V_23 = ( V_22 < 56 ) ? ( 56 - V_22 ) : ( ( V_16 + 56 ) - V_22 ) ;
if ( ! F_6 () ) {
F_7 ( V_2 , V_26 , V_23 ) ;
F_7 ( V_2 , ( const T_1 * ) & V_25 , sizeof( V_25 ) ) ;
} else {
F_8 () ;
if ( V_23 <= 56 ) {
V_4 -> V_15 += V_23 ;
memcpy ( V_4 -> V_17 + V_22 , V_26 , V_23 ) ;
} else {
F_3 ( V_2 , V_26 , V_23 , V_22 ) ;
}
F_3 ( V_2 , ( const T_1 * ) & V_25 , sizeof( V_25 ) , 56 ) ;
F_9 () ;
}
for ( V_21 = 0 ; V_21 < 5 ; V_21 ++ )
V_24 [ V_21 ] = F_12 ( V_4 -> V_5 [ V_21 ] ) ;
memset ( V_4 , 0 , sizeof( * V_4 ) ) ;
return 0 ;
}
static int F_13 ( struct V_1 * V_2 , void * V_20 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
memcpy ( V_20 , V_4 , sizeof( * V_4 ) ) ;
return 0 ;
}
static int F_14 ( struct V_1 * V_2 , const void * V_27 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
memcpy ( V_4 , V_27 , sizeof( * V_4 ) ) ;
return 0 ;
}
static bool T_4 F_15 ( void )
{
T_5 V_28 ;
if ( ! V_29 || ! V_30 )
return false ;
V_28 = F_16 ( V_31 ) ;
if ( ( V_28 & ( V_32 | V_33 ) ) != ( V_32 | V_33 ) ) {
F_17 ( L_1 ) ;
return false ;
}
return true ;
}
static int T_4 F_18 ( void )
{
if ( V_34 )
F_4 = V_35 ;
#ifdef F_19
if ( F_15 () )
F_4 = V_36 ;
#endif
if ( F_4 ) {
F_17 ( L_2 ,
F_4 == V_35 ? L_3
: L_4 ) ;
return F_20 ( & V_37 ) ;
}
F_17 ( L_5 ) ;
return - V_38 ;
}
static void T_6 F_21 ( void )
{
F_22 ( & V_37 ) ;
}
