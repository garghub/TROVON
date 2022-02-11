static void F_1 ( struct V_1 * V_2 )
{
T_1 * V_3 = ( T_1 * ) V_2 -> V_4 ;
F_2 ( V_3 [ 0 ] , 0 ) ;
F_2 ( V_3 [ 1 ] , 1 ) ;
F_2 ( V_3 [ 2 ] , 2 ) ;
F_2 ( V_3 [ 3 ] , 3 ) ;
}
static void F_3 ( struct V_1 * V_2 )
{
T_1 * V_3 = ( T_1 * ) V_2 -> V_4 ;
V_3 [ 0 ] = F_4 ( 0 ) ;
V_3 [ 1 ] = F_4 ( 1 ) ;
V_3 [ 2 ] = F_4 ( 2 ) ;
V_3 [ 3 ] = F_4 ( 3 ) ;
}
static void F_5 ( const void * V_5 )
{
const T_1 * V_6 = V_5 ;
F_6 ( V_6 [ 0 ] , 0 ) ;
F_6 ( V_6 [ 1 ] , 1 ) ;
F_6 ( V_6 [ 2 ] , 2 ) ;
F_6 ( V_6 [ 3 ] , 3 ) ;
F_6 ( V_6 [ 4 ] , 4 ) ;
F_6 ( V_6 [ 5 ] , 5 ) ;
F_6 ( V_6 [ 6 ] , 6 ) ;
F_7 ( V_6 [ 7 ] ) ;
}
static int F_8 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = F_9 ( V_8 ) ;
V_2 -> V_4 [ 0 ] = V_9 ;
V_2 -> V_4 [ 1 ] = V_10 ;
V_2 -> V_4 [ 2 ] = V_11 ;
V_2 -> V_4 [ 3 ] = V_12 ;
V_2 -> V_4 [ 4 ] = V_13 ;
V_2 -> V_4 [ 5 ] = V_14 ;
V_2 -> V_4 [ 6 ] = V_15 ;
V_2 -> V_4 [ 7 ] = V_16 ;
V_2 -> V_17 = 0 ;
return 0 ;
}
static int F_10 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = F_9 ( V_8 ) ;
V_2 -> V_4 [ 0 ] = V_18 ;
V_2 -> V_4 [ 1 ] = V_19 ;
V_2 -> V_4 [ 2 ] = V_20 ;
V_2 -> V_4 [ 3 ] = V_21 ;
V_2 -> V_4 [ 4 ] = V_22 ;
V_2 -> V_4 [ 5 ] = V_23 ;
V_2 -> V_4 [ 6 ] = V_24 ;
V_2 -> V_4 [ 7 ] = V_25 ;
V_2 -> V_17 = 0 ;
return 0 ;
}
static void F_11 ( struct V_1 * V_2 , const T_2 * V_26 ,
unsigned int V_27 )
{
unsigned int V_28 ;
unsigned int V_29 ;
const T_2 * V_30 ;
V_28 = V_2 -> V_17 % V_31 ;
V_2 -> V_17 += V_27 ;
V_29 = 0 ;
V_30 = V_26 ;
if ( ( V_28 + V_27 ) >= V_31 ) {
if ( V_28 ) {
V_29 = - V_28 ;
memcpy ( V_2 -> V_32 + V_28 , V_26 ,
V_29 + V_31 ) ;
V_30 = V_2 -> V_32 ;
}
do {
F_5 ( V_30 ) ;
V_29 += V_31 ;
V_30 = V_26 + V_29 ;
} while ( V_29 + V_31 <= V_27 );
V_28 = 0 ;
}
memcpy ( V_2 -> V_32 + V_28 , V_30 , V_27 - V_29 ) ;
}
static int F_12 ( struct V_7 * V_8 , const T_2 * V_26 ,
unsigned int V_27 )
{
struct V_1 * V_2 = F_9 ( V_8 ) ;
struct V_33 V_4 ;
unsigned long V_34 ;
if ( ( V_2 -> V_17 % V_31 ) + V_27 < V_31 )
return F_13 ( V_8 , V_26 , V_27 ) ;
V_34 = F_14 ( & V_4 ) ;
F_1 ( V_2 ) ;
F_11 ( V_2 , V_26 , V_27 ) ;
F_3 ( V_2 ) ;
F_15 ( & V_4 , V_34 ) ;
return 0 ;
}
static int F_16 ( struct V_7 * V_8 , T_2 * V_35 )
{
struct V_1 * V_2 = F_9 ( V_8 ) ;
static const T_2 V_36 [ 64 ] = { 0x80 , } ;
struct V_33 V_4 ;
T_3 * V_37 = ( T_3 * ) V_35 ;
unsigned int V_38 ;
unsigned long V_34 ;
unsigned int V_39 ;
T_4 V_40 ;
int V_41 ;
V_40 = F_17 ( V_2 -> V_17 << 3 ) ;
V_39 = V_2 -> V_17 & 0x3f ;
V_38 = ( V_39 < 56 ) ? ( 56 - V_39 ) : ( ( 64 + 56 ) - V_39 ) ;
V_34 = F_14 ( & V_4 ) ;
F_1 ( V_2 ) ;
F_11 ( V_2 , V_36 , V_38 ) ;
F_11 ( V_2 , ( const T_2 * ) & V_40 , sizeof( V_40 ) ) ;
F_3 ( V_2 ) ;
F_15 ( & V_4 , V_34 ) ;
for ( V_41 = 0 ; V_41 < 8 ; V_41 ++ )
V_37 [ V_41 ] = F_18 ( V_2 -> V_4 [ V_41 ] ) ;
memset ( V_2 , 0 , sizeof( * V_2 ) ) ;
return 0 ;
}
static int F_19 ( struct V_7 * V_8 , T_2 * V_3 )
{
T_2 V_42 [ V_43 ] ;
F_16 ( V_8 , V_42 ) ;
memcpy ( V_3 , V_42 , V_44 ) ;
F_20 ( V_42 , V_43 ) ;
return 0 ;
}
static int F_21 ( struct V_7 * V_8 , void * V_35 )
{
struct V_1 * V_2 = F_9 ( V_8 ) ;
memcpy ( V_35 , V_2 , sizeof( * V_2 ) ) ;
return 0 ;
}
static int F_22 ( struct V_7 * V_8 , const void * V_45 )
{
struct V_1 * V_2 = F_9 ( V_8 ) ;
memcpy ( V_2 , V_45 , sizeof( * V_2 ) ) ;
return 0 ;
}
static int T_5 F_23 ( void )
{
if ( ! F_24 () )
return - V_46 ;
return F_25 ( V_47 ,
F_26 ( V_47 ) ) ;
}
static void T_6 F_27 ( void )
{
F_28 ( V_47 ,
F_26 ( V_47 ) ) ;
}
