static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
V_4 -> V_5 [ 0 ] = V_6 ;
V_4 -> V_5 [ 1 ] = V_7 ;
V_4 -> V_5 [ 2 ] = V_8 ;
V_4 -> V_5 [ 3 ] = V_9 ;
V_4 -> V_5 [ 4 ] = V_10 ;
V_4 -> V_5 [ 5 ] = V_11 ;
V_4 -> V_5 [ 6 ] = V_12 ;
V_4 -> V_5 [ 7 ] = V_13 ;
V_4 -> V_14 [ 0 ] = V_4 -> V_14 [ 1 ] = 0 ;
return 0 ;
}
static int F_3 ( struct V_1 * V_2 , const T_1 * V_15 ,
unsigned int V_16 , unsigned int V_17 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned int V_18 = 0 ;
V_4 -> V_14 [ 0 ] += V_16 ;
if ( V_4 -> V_14 [ 0 ] < V_16 )
V_4 -> V_14 [ 1 ] ++ ;
if ( V_17 ) {
V_18 = V_19 - V_17 ;
memcpy ( V_4 -> V_20 + V_17 , V_15 , V_18 ) ;
F_4 ( V_4 -> V_20 , V_4 -> V_5 , 1 ) ;
}
if ( V_16 - V_18 >= V_19 ) {
const unsigned int V_21 = ( V_16 - V_18 ) / V_19 ;
F_4 ( V_15 + V_18 , V_4 -> V_5 , ( V_22 ) V_21 ) ;
V_18 += V_21 * V_19 ;
}
memcpy ( V_4 -> V_20 , V_15 + V_18 , V_16 - V_18 ) ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 , const T_1 * V_15 ,
unsigned int V_16 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned int V_17 = V_4 -> V_14 [ 0 ] % V_19 ;
int V_23 ;
if ( V_17 + V_16 < V_19 ) {
V_4 -> V_14 [ 0 ] += V_16 ;
if ( V_4 -> V_14 [ 0 ] < V_16 )
V_4 -> V_14 [ 1 ] ++ ;
memcpy ( V_4 -> V_20 + V_17 , V_15 , V_16 ) ;
return 0 ;
}
if ( ! F_6 () ) {
V_23 = F_7 ( V_2 , V_15 , V_16 ) ;
} else {
F_8 () ;
V_23 = F_3 ( V_2 , V_15 , V_16 , V_17 ) ;
F_9 () ;
}
return V_23 ;
}
static int F_10 ( struct V_1 * V_2 , T_1 * V_24 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned int V_25 , V_26 , V_27 ;
T_2 * V_28 = ( T_2 * ) V_24 ;
T_2 V_29 [ 2 ] ;
static const T_1 V_30 [ V_19 ] = { 0x80 , } ;
V_29 [ 1 ] = F_11 ( V_4 -> V_14 [ 0 ] << 3 ) ;
V_29 [ 0 ] = F_11 ( V_4 -> V_14 [ 1 ] << 3 | V_4 -> V_14 [ 0 ] >> 61 ) ;
V_26 = V_4 -> V_14 [ 0 ] & 0x7f ;
V_27 = ( V_26 < 112 ) ? ( 112 - V_26 ) : ( ( 128 + 112 ) - V_26 ) ;
if ( ! F_6 () ) {
F_7 ( V_2 , V_30 , V_27 ) ;
F_7 ( V_2 , ( const T_1 * ) & V_29 , sizeof( V_29 ) ) ;
} else {
F_8 () ;
if ( V_27 <= 112 ) {
V_4 -> V_14 [ 0 ] += V_27 ;
if ( V_4 -> V_14 [ 0 ] < V_27 )
V_4 -> V_14 [ 1 ] ++ ;
memcpy ( V_4 -> V_20 + V_26 , V_30 , V_27 ) ;
} else {
F_3 ( V_2 , V_30 , V_27 , V_26 ) ;
}
F_3 ( V_2 , ( const T_1 * ) & V_29 ,
sizeof( V_29 ) , 112 ) ;
F_9 () ;
}
for ( V_25 = 0 ; V_25 < 8 ; V_25 ++ )
V_28 [ V_25 ] = F_11 ( V_4 -> V_5 [ V_25 ] ) ;
memset ( V_4 , 0 , sizeof( * V_4 ) ) ;
return 0 ;
}
static int F_12 ( struct V_1 * V_2 , void * V_24 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
memcpy ( V_24 , V_4 , sizeof( * V_4 ) ) ;
return 0 ;
}
static int F_13 ( struct V_1 * V_2 , const void * V_31 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
memcpy ( V_4 , V_31 , sizeof( * V_4 ) ) ;
return 0 ;
}
static int F_14 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
V_4 -> V_5 [ 0 ] = V_32 ;
V_4 -> V_5 [ 1 ] = V_33 ;
V_4 -> V_5 [ 2 ] = V_34 ;
V_4 -> V_5 [ 3 ] = V_35 ;
V_4 -> V_5 [ 4 ] = V_36 ;
V_4 -> V_5 [ 5 ] = V_37 ;
V_4 -> V_5 [ 6 ] = V_38 ;
V_4 -> V_5 [ 7 ] = V_39 ;
V_4 -> V_14 [ 0 ] = V_4 -> V_14 [ 1 ] = 0 ;
return 0 ;
}
static int F_15 ( struct V_1 * V_2 , T_1 * V_40 )
{
T_1 V_41 [ V_42 ] ;
F_10 ( V_2 , V_41 ) ;
memcpy ( V_40 , V_41 , V_43 ) ;
F_16 ( V_41 , V_42 ) ;
return 0 ;
}
static bool T_3 F_17 ( void )
{
V_22 V_44 ;
if ( ! V_45 || ! V_46 )
return false ;
V_44 = F_18 ( V_47 ) ;
if ( ( V_44 & ( V_48 | V_49 ) ) != ( V_48 | V_49 ) ) {
F_19 ( L_1 ) ;
return false ;
}
return true ;
}
static int T_3 F_20 ( void )
{
if ( V_50 )
F_4 = V_51 ;
#ifdef F_21
if ( F_17 () ) {
#ifdef F_22
if ( F_23 ( V_52 ) )
F_4 = V_53 ;
else
#endif
F_4 = V_54 ;
}
#endif
if ( F_4 ) {
#ifdef F_21
if ( F_4 == V_54 )
F_19 ( L_2 ) ;
#ifdef F_22
else if ( F_4 == V_53 )
F_19 ( L_3 ) ;
#endif
else
#endif
F_19 ( L_4 ) ;
return F_24 ( V_55 , F_25 ( V_55 ) ) ;
}
F_19 ( L_5 ) ;
return - V_56 ;
}
static void T_4 F_26 ( void )
{
F_27 ( V_55 , F_25 ( V_55 ) ) ;
}
