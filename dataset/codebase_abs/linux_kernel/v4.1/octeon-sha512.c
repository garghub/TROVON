static void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 -> V_3 [ 0 ] , 0 ) ;
F_2 ( V_2 -> V_3 [ 1 ] , 1 ) ;
F_2 ( V_2 -> V_3 [ 2 ] , 2 ) ;
F_2 ( V_2 -> V_3 [ 3 ] , 3 ) ;
F_2 ( V_2 -> V_3 [ 4 ] , 4 ) ;
F_2 ( V_2 -> V_3 [ 5 ] , 5 ) ;
F_2 ( V_2 -> V_3 [ 6 ] , 6 ) ;
F_2 ( V_2 -> V_3 [ 7 ] , 7 ) ;
}
static void F_3 ( struct V_1 * V_2 )
{
V_2 -> V_3 [ 0 ] = F_4 ( 0 ) ;
V_2 -> V_3 [ 1 ] = F_4 ( 1 ) ;
V_2 -> V_3 [ 2 ] = F_4 ( 2 ) ;
V_2 -> V_3 [ 3 ] = F_4 ( 3 ) ;
V_2 -> V_3 [ 4 ] = F_4 ( 4 ) ;
V_2 -> V_3 [ 5 ] = F_4 ( 5 ) ;
V_2 -> V_3 [ 6 ] = F_4 ( 6 ) ;
V_2 -> V_3 [ 7 ] = F_4 ( 7 ) ;
}
static void F_5 ( const void * V_4 )
{
const T_1 * V_5 = V_4 ;
F_6 ( V_5 [ 0 ] , 0 ) ;
F_6 ( V_5 [ 1 ] , 1 ) ;
F_6 ( V_5 [ 2 ] , 2 ) ;
F_6 ( V_5 [ 3 ] , 3 ) ;
F_6 ( V_5 [ 4 ] , 4 ) ;
F_6 ( V_5 [ 5 ] , 5 ) ;
F_6 ( V_5 [ 6 ] , 6 ) ;
F_6 ( V_5 [ 7 ] , 7 ) ;
F_6 ( V_5 [ 8 ] , 8 ) ;
F_6 ( V_5 [ 9 ] , 9 ) ;
F_6 ( V_5 [ 10 ] , 10 ) ;
F_6 ( V_5 [ 11 ] , 11 ) ;
F_6 ( V_5 [ 12 ] , 12 ) ;
F_6 ( V_5 [ 13 ] , 13 ) ;
F_6 ( V_5 [ 14 ] , 14 ) ;
F_7 ( V_5 [ 15 ] ) ;
}
static int F_8 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_9 ( V_7 ) ;
V_2 -> V_3 [ 0 ] = V_8 ;
V_2 -> V_3 [ 1 ] = V_9 ;
V_2 -> V_3 [ 2 ] = V_10 ;
V_2 -> V_3 [ 3 ] = V_11 ;
V_2 -> V_3 [ 4 ] = V_12 ;
V_2 -> V_3 [ 5 ] = V_13 ;
V_2 -> V_3 [ 6 ] = V_14 ;
V_2 -> V_3 [ 7 ] = V_15 ;
V_2 -> V_16 [ 0 ] = V_2 -> V_16 [ 1 ] = 0 ;
return 0 ;
}
static int F_10 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_9 ( V_7 ) ;
V_2 -> V_3 [ 0 ] = V_17 ;
V_2 -> V_3 [ 1 ] = V_18 ;
V_2 -> V_3 [ 2 ] = V_19 ;
V_2 -> V_3 [ 3 ] = V_20 ;
V_2 -> V_3 [ 4 ] = V_21 ;
V_2 -> V_3 [ 5 ] = V_22 ;
V_2 -> V_3 [ 6 ] = V_23 ;
V_2 -> V_3 [ 7 ] = V_24 ;
V_2 -> V_16 [ 0 ] = V_2 -> V_16 [ 1 ] = 0 ;
return 0 ;
}
static void F_11 ( struct V_1 * V_2 , const T_2 * V_25 ,
unsigned int V_26 )
{
unsigned int V_27 ;
unsigned int V_28 ;
unsigned int V_29 ;
V_28 = V_2 -> V_16 [ 0 ] % V_30 ;
if ( ( V_2 -> V_16 [ 0 ] += V_26 ) < V_26 )
V_2 -> V_16 [ 1 ] ++ ;
V_27 = V_30 - V_28 ;
if ( V_26 >= V_27 ) {
memcpy ( & V_2 -> V_31 [ V_28 ] , V_25 , V_27 ) ;
F_5 ( V_2 -> V_31 ) ;
for ( V_29 = V_27 ; V_29 + V_30 <= V_26 ;
V_29 += V_30 )
F_5 ( & V_25 [ V_29 ] ) ;
V_28 = 0 ;
} else {
V_29 = 0 ;
}
memcpy ( & V_2 -> V_31 [ V_28 ] , & V_25 [ V_29 ] , V_26 - V_29 ) ;
}
static int F_12 ( struct V_6 * V_7 , const T_2 * V_25 ,
unsigned int V_26 )
{
struct V_1 * V_2 = F_9 ( V_7 ) ;
struct V_32 V_3 ;
unsigned long V_33 ;
if ( ( V_2 -> V_16 [ 0 ] % V_30 ) + V_26 < V_30 )
return F_13 ( V_7 , V_25 , V_26 ) ;
V_33 = F_14 ( & V_3 ) ;
F_1 ( V_2 ) ;
F_11 ( V_2 , V_25 , V_26 ) ;
F_3 ( V_2 ) ;
F_15 ( & V_3 , V_33 ) ;
return 0 ;
}
static int F_16 ( struct V_6 * V_7 , T_2 * V_34 )
{
struct V_1 * V_2 = F_9 ( V_7 ) ;
static T_2 V_35 [ 128 ] = { 0x80 , } ;
struct V_32 V_3 ;
T_3 * V_36 = ( T_3 * ) V_34 ;
unsigned int V_37 ;
unsigned long V_33 ;
unsigned int V_28 ;
T_3 V_38 [ 2 ] ;
int V_29 ;
V_38 [ 1 ] = F_17 ( V_2 -> V_16 [ 0 ] << 3 ) ;
V_38 [ 0 ] = F_17 ( V_2 -> V_16 [ 1 ] << 3 | V_2 -> V_16 [ 0 ] >> 61 ) ;
V_28 = V_2 -> V_16 [ 0 ] & 0x7f ;
V_37 = ( V_28 < 112 ) ? ( 112 - V_28 ) : ( ( 128 + 112 ) - V_28 ) ;
V_33 = F_14 ( & V_3 ) ;
F_1 ( V_2 ) ;
F_11 ( V_2 , V_35 , V_37 ) ;
F_11 ( V_2 , ( const T_2 * ) V_38 , sizeof( V_38 ) ) ;
F_3 ( V_2 ) ;
F_15 ( & V_3 , V_33 ) ;
for ( V_29 = 0 ; V_29 < 8 ; V_29 ++ )
V_36 [ V_29 ] = F_17 ( V_2 -> V_3 [ V_29 ] ) ;
memset ( V_2 , 0 , sizeof( struct V_1 ) ) ;
return 0 ;
}
static int F_18 ( struct V_6 * V_7 , T_2 * V_34 )
{
T_2 V_39 [ 64 ] ;
F_16 ( V_7 , V_39 ) ;
memcpy ( V_34 , V_39 , 48 ) ;
F_19 ( V_39 , 64 ) ;
return 0 ;
}
static int T_4 F_20 ( void )
{
if ( ! F_21 () )
return - V_40 ;
return F_22 ( V_41 ,
F_23 ( V_41 ) ) ;
}
static void T_5 F_24 ( void )
{
F_25 ( V_41 ,
F_23 ( V_41 ) ) ;
}
