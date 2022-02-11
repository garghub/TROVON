static int F_1 ( struct V_1 * V_2 , const T_1 * V_3 ,
unsigned int V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
const T_2 * V_7 = ( const T_2 * ) V_3 ;
int V_8 ;
const T_3 * V_9 = V_10 ;
T_3 V_11 , V_12 ;
V_11 = ( ( T_3 ) F_3 ( V_7 [ 0 ] ) << 32 ) | F_3 ( V_7 [ 1 ] ) ;
V_12 = ( ( T_3 ) F_3 ( V_7 [ 2 ] ) << 32 ) | F_3 ( V_7 [ 3 ] ) ;
for ( V_8 = 0 ; V_8 <= V_13 ; V_8 ++ ) {
V_6 -> V_14 [ V_8 ] = V_15 [ ( int ) ( V_12 >> 56 ) ] ^
V_16 [ ( int ) ( V_12 >> 48 ) & 0xff ] ^
V_17 [ ( int ) ( V_12 >> 40 ) & 0xff ] ^
V_18 [ ( int ) ( V_12 >> 32 ) & 0xff ] ^
V_19 [ ( int ) ( V_12 >> 24 ) & 0xff ] ^
V_20 [ ( int ) ( V_12 >> 16 ) & 0xff ] ^
V_21 [ ( int ) ( V_12 >> 8 ) & 0xff ] ^
V_10 [ ( int ) ( V_12 ) & 0xff ] ^
V_22 [ V_8 ] ^ V_11 ;
V_11 = V_12 ;
V_12 = V_6 -> V_14 [ V_8 ] ;
}
V_6 -> V_23 [ 0 ] = V_6 -> V_14 [ V_13 ] ;
for ( V_8 = 1 ; V_8 < V_13 ; V_8 ++ ) {
V_12 = V_6 -> V_14 [ V_13 - V_8 ] ;
V_6 -> V_23 [ V_8 ] = V_15 [ ( int ) V_9 [ ( int ) ( V_12 >> 56 ) ] & 0xff ] ^
V_16 [ ( int ) V_9 [ ( int ) ( V_12 >> 48 ) & 0xff ] & 0xff ] ^
V_17 [ ( int ) V_9 [ ( int ) ( V_12 >> 40 ) & 0xff ] & 0xff ] ^
V_18 [ ( int ) V_9 [ ( int ) ( V_12 >> 32 ) & 0xff ] & 0xff ] ^
V_19 [ ( int ) V_9 [ ( int ) ( V_12 >> 24 ) & 0xff ] & 0xff ] ^
V_20 [ ( int ) V_9 [ ( int ) ( V_12 >> 16 ) & 0xff ] & 0xff ] ^
V_21 [ ( int ) V_9 [ ( int ) ( V_12 >> 8 ) & 0xff ] & 0xff ] ^
V_10 [ ( int ) V_9 [ ( int ) ( V_12 ) & 0xff ] & 0xff ] ;
}
V_6 -> V_23 [ V_13 ] = V_6 -> V_14 [ 0 ] ;
return 0 ;
}
static void F_4 ( const T_3 V_24 [ V_13 + 1 ] ,
T_1 * V_25 , const T_1 * V_26 )
{
const T_4 * V_27 = ( const T_4 * ) V_26 ;
T_4 * V_28 = ( T_4 * ) V_25 ;
int V_8 ;
T_3 V_29 ;
V_29 = F_5 ( * V_27 ) ^ V_24 [ 0 ] ;
for ( V_8 = 1 ; V_8 < V_13 ; V_8 ++ ) {
V_29 = V_15 [ ( int ) ( V_29 >> 56 ) ] ^
V_16 [ ( int ) ( V_29 >> 48 ) & 0xff ] ^
V_17 [ ( int ) ( V_29 >> 40 ) & 0xff ] ^
V_18 [ ( int ) ( V_29 >> 32 ) & 0xff ] ^
V_19 [ ( int ) ( V_29 >> 24 ) & 0xff ] ^
V_20 [ ( int ) ( V_29 >> 16 ) & 0xff ] ^
V_21 [ ( int ) ( V_29 >> 8 ) & 0xff ] ^
V_10 [ ( int ) ( V_29 ) & 0xff ] ^
V_24 [ V_8 ] ;
}
V_29 = ( V_15 [ ( int ) ( V_29 >> 56 ) ] & 0xff00000000000000ULL ) ^
( V_16 [ ( int ) ( V_29 >> 48 ) & 0xff ] & 0x00ff000000000000ULL ) ^
( V_17 [ ( int ) ( V_29 >> 40 ) & 0xff ] & 0x0000ff0000000000ULL ) ^
( V_18 [ ( int ) ( V_29 >> 32 ) & 0xff ] & 0x000000ff00000000ULL ) ^
( V_19 [ ( int ) ( V_29 >> 24 ) & 0xff ] & 0x00000000ff000000ULL ) ^
( V_20 [ ( int ) ( V_29 >> 16 ) & 0xff ] & 0x0000000000ff0000ULL ) ^
( V_21 [ ( int ) ( V_29 >> 8 ) & 0xff ] & 0x000000000000ff00ULL ) ^
( V_10 [ ( int ) ( V_29 ) & 0xff ] & 0x00000000000000ffULL ) ^
V_24 [ V_13 ] ;
* V_28 = F_6 ( V_29 ) ;
}
static void F_7 ( struct V_1 * V_2 , T_1 * V_28 , const T_1 * V_27 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_4 ( V_6 -> V_14 , V_28 , V_27 ) ;
}
static void F_8 ( struct V_1 * V_2 , T_1 * V_28 , const T_1 * V_27 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_4 ( V_6 -> V_23 , V_28 , V_27 ) ;
}
static int T_5 F_9 ( void )
{
int V_30 = 0 ;
V_30 = F_10 ( & V_31 ) ;
return V_30 ;
}
static void T_6 F_11 ( void )
{
F_12 ( & V_31 ) ;
}
