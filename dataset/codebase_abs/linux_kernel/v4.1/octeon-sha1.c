static void F_1 ( struct V_1 * V_2 )
{
T_1 * V_3 = ( T_1 * ) V_2 -> V_4 ;
union {
T_2 V_5 [ 2 ] ;
T_1 V_6 ;
} V_7 = { { V_2 -> V_4 [ 4 ] , } } ;
F_2 ( V_3 [ 0 ] , 0 ) ;
F_2 ( V_3 [ 1 ] , 1 ) ;
F_2 ( V_7 . V_6 , 2 ) ;
F_3 ( & V_7 . V_5 [ 0 ] , sizeof( V_7 . V_5 [ 0 ] ) ) ;
}
static void F_4 ( struct V_1 * V_2 )
{
T_1 * V_3 = ( T_1 * ) V_2 -> V_4 ;
union {
T_2 V_5 [ 2 ] ;
T_1 V_6 ;
} V_7 ;
V_3 [ 0 ] = F_5 ( 0 ) ;
V_3 [ 1 ] = F_5 ( 1 ) ;
V_7 . V_6 = F_5 ( 2 ) ;
V_2 -> V_4 [ 4 ] = V_7 . V_5 [ 0 ] ;
F_3 ( & V_7 . V_6 , sizeof( V_7 . V_6 ) ) ;
}
static void F_6 ( const void * V_8 )
{
const T_1 * V_9 = V_8 ;
F_7 ( V_9 [ 0 ] , 0 ) ;
F_7 ( V_9 [ 1 ] , 1 ) ;
F_7 ( V_9 [ 2 ] , 2 ) ;
F_7 ( V_9 [ 3 ] , 3 ) ;
F_7 ( V_9 [ 4 ] , 4 ) ;
F_7 ( V_9 [ 5 ] , 5 ) ;
F_7 ( V_9 [ 6 ] , 6 ) ;
F_8 ( V_9 [ 7 ] ) ;
}
static int F_9 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = F_10 ( V_11 ) ;
V_2 -> V_4 [ 0 ] = V_12 ;
V_2 -> V_4 [ 1 ] = V_13 ;
V_2 -> V_4 [ 2 ] = V_14 ;
V_2 -> V_4 [ 3 ] = V_15 ;
V_2 -> V_4 [ 4 ] = V_16 ;
V_2 -> V_17 = 0 ;
return 0 ;
}
static void F_11 ( struct V_1 * V_2 , const T_3 * V_18 ,
unsigned int V_19 )
{
unsigned int V_20 ;
unsigned int V_21 ;
const T_3 * V_22 ;
V_20 = V_2 -> V_17 % V_23 ;
V_2 -> V_17 += V_19 ;
V_21 = 0 ;
V_22 = V_18 ;
if ( ( V_20 + V_19 ) >= V_23 ) {
if ( V_20 ) {
V_21 = - V_20 ;
memcpy ( V_2 -> V_24 + V_20 , V_18 ,
V_21 + V_23 ) ;
V_22 = V_2 -> V_24 ;
}
do {
F_6 ( V_22 ) ;
V_21 += V_23 ;
V_22 = V_18 + V_21 ;
} while ( V_21 + V_23 <= V_19 );
V_20 = 0 ;
}
memcpy ( V_2 -> V_24 + V_20 , V_22 , V_19 - V_21 ) ;
}
static int F_12 ( struct V_10 * V_11 , const T_3 * V_18 ,
unsigned int V_19 )
{
struct V_1 * V_2 = F_10 ( V_11 ) ;
struct V_25 V_4 ;
unsigned long V_26 ;
if ( ( V_2 -> V_17 % V_23 ) + V_19 < V_23 )
return F_13 ( V_11 , V_18 , V_19 ) ;
V_26 = F_14 ( & V_4 ) ;
F_1 ( V_2 ) ;
F_11 ( V_2 , V_18 , V_19 ) ;
F_4 ( V_2 ) ;
F_15 ( & V_4 , V_26 ) ;
return 0 ;
}
static int F_16 ( struct V_10 * V_11 , T_3 * V_27 )
{
struct V_1 * V_2 = F_10 ( V_11 ) ;
static const T_3 V_28 [ 64 ] = { 0x80 , } ;
struct V_25 V_4 ;
T_4 * V_29 = ( T_4 * ) V_27 ;
unsigned int V_30 ;
unsigned long V_26 ;
unsigned int V_31 ;
T_5 V_32 ;
int V_33 ;
V_32 = F_17 ( V_2 -> V_17 << 3 ) ;
V_31 = V_2 -> V_17 & 0x3f ;
V_30 = ( V_31 < 56 ) ? ( 56 - V_31 ) : ( ( 64 + 56 ) - V_31 ) ;
V_26 = F_14 ( & V_4 ) ;
F_1 ( V_2 ) ;
F_11 ( V_2 , V_28 , V_30 ) ;
F_11 ( V_2 , ( const T_3 * ) & V_32 , sizeof( V_32 ) ) ;
F_4 ( V_2 ) ;
F_15 ( & V_4 , V_26 ) ;
for ( V_33 = 0 ; V_33 < 5 ; V_33 ++ )
V_29 [ V_33 ] = F_18 ( V_2 -> V_4 [ V_33 ] ) ;
memset ( V_2 , 0 , sizeof( * V_2 ) ) ;
return 0 ;
}
static int F_19 ( struct V_10 * V_11 , void * V_27 )
{
struct V_1 * V_2 = F_10 ( V_11 ) ;
memcpy ( V_27 , V_2 , sizeof( * V_2 ) ) ;
return 0 ;
}
static int F_20 ( struct V_10 * V_11 , const void * V_34 )
{
struct V_1 * V_2 = F_10 ( V_11 ) ;
memcpy ( V_2 , V_34 , sizeof( * V_2 ) ) ;
return 0 ;
}
static int T_6 F_21 ( void )
{
if ( ! F_22 () )
return - V_35 ;
return F_23 ( & V_36 ) ;
}
static void T_7 F_24 ( void )
{
F_25 ( & V_36 ) ;
}
