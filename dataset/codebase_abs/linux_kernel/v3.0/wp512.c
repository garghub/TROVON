static void F_1 ( struct V_1 * V_2 ) {
int V_3 , V_4 ;
T_1 V_5 [ 8 ] ;
T_1 V_6 [ 8 ] ;
T_1 V_7 [ 8 ] ;
T_1 V_8 [ 8 ] ;
const T_2 * V_9 = ( const T_2 * ) V_2 -> V_9 ;
for ( V_3 = 0 ; V_3 < 8 ; V_3 ++ )
V_6 [ V_3 ] = F_2 ( V_9 [ V_3 ] ) ;
V_7 [ 0 ] = V_6 [ 0 ] ^ ( V_5 [ 0 ] = V_2 -> V_10 [ 0 ] ) ;
V_7 [ 1 ] = V_6 [ 1 ] ^ ( V_5 [ 1 ] = V_2 -> V_10 [ 1 ] ) ;
V_7 [ 2 ] = V_6 [ 2 ] ^ ( V_5 [ 2 ] = V_2 -> V_10 [ 2 ] ) ;
V_7 [ 3 ] = V_6 [ 3 ] ^ ( V_5 [ 3 ] = V_2 -> V_10 [ 3 ] ) ;
V_7 [ 4 ] = V_6 [ 4 ] ^ ( V_5 [ 4 ] = V_2 -> V_10 [ 4 ] ) ;
V_7 [ 5 ] = V_6 [ 5 ] ^ ( V_5 [ 5 ] = V_2 -> V_10 [ 5 ] ) ;
V_7 [ 6 ] = V_6 [ 6 ] ^ ( V_5 [ 6 ] = V_2 -> V_10 [ 6 ] ) ;
V_7 [ 7 ] = V_6 [ 7 ] ^ ( V_5 [ 7 ] = V_2 -> V_10 [ 7 ] ) ;
for ( V_4 = 1 ; V_4 <= V_11 ; V_4 ++ ) {
V_8 [ 0 ] = V_12 [ ( int ) ( V_5 [ 0 ] >> 56 ) ] ^
V_13 [ ( int ) ( V_5 [ 7 ] >> 48 ) & 0xff ] ^
V_14 [ ( int ) ( V_5 [ 6 ] >> 40 ) & 0xff ] ^
V_15 [ ( int ) ( V_5 [ 5 ] >> 32 ) & 0xff ] ^
V_16 [ ( int ) ( V_5 [ 4 ] >> 24 ) & 0xff ] ^
V_17 [ ( int ) ( V_5 [ 3 ] >> 16 ) & 0xff ] ^
V_18 [ ( int ) ( V_5 [ 2 ] >> 8 ) & 0xff ] ^
V_19 [ ( int ) ( V_5 [ 1 ] ) & 0xff ] ^
V_20 [ V_4 ] ;
V_8 [ 1 ] = V_12 [ ( int ) ( V_5 [ 1 ] >> 56 ) ] ^
V_13 [ ( int ) ( V_5 [ 0 ] >> 48 ) & 0xff ] ^
V_14 [ ( int ) ( V_5 [ 7 ] >> 40 ) & 0xff ] ^
V_15 [ ( int ) ( V_5 [ 6 ] >> 32 ) & 0xff ] ^
V_16 [ ( int ) ( V_5 [ 5 ] >> 24 ) & 0xff ] ^
V_17 [ ( int ) ( V_5 [ 4 ] >> 16 ) & 0xff ] ^
V_18 [ ( int ) ( V_5 [ 3 ] >> 8 ) & 0xff ] ^
V_19 [ ( int ) ( V_5 [ 2 ] ) & 0xff ] ;
V_8 [ 2 ] = V_12 [ ( int ) ( V_5 [ 2 ] >> 56 ) ] ^
V_13 [ ( int ) ( V_5 [ 1 ] >> 48 ) & 0xff ] ^
V_14 [ ( int ) ( V_5 [ 0 ] >> 40 ) & 0xff ] ^
V_15 [ ( int ) ( V_5 [ 7 ] >> 32 ) & 0xff ] ^
V_16 [ ( int ) ( V_5 [ 6 ] >> 24 ) & 0xff ] ^
V_17 [ ( int ) ( V_5 [ 5 ] >> 16 ) & 0xff ] ^
V_18 [ ( int ) ( V_5 [ 4 ] >> 8 ) & 0xff ] ^
V_19 [ ( int ) ( V_5 [ 3 ] ) & 0xff ] ;
V_8 [ 3 ] = V_12 [ ( int ) ( V_5 [ 3 ] >> 56 ) ] ^
V_13 [ ( int ) ( V_5 [ 2 ] >> 48 ) & 0xff ] ^
V_14 [ ( int ) ( V_5 [ 1 ] >> 40 ) & 0xff ] ^
V_15 [ ( int ) ( V_5 [ 0 ] >> 32 ) & 0xff ] ^
V_16 [ ( int ) ( V_5 [ 7 ] >> 24 ) & 0xff ] ^
V_17 [ ( int ) ( V_5 [ 6 ] >> 16 ) & 0xff ] ^
V_18 [ ( int ) ( V_5 [ 5 ] >> 8 ) & 0xff ] ^
V_19 [ ( int ) ( V_5 [ 4 ] ) & 0xff ] ;
V_8 [ 4 ] = V_12 [ ( int ) ( V_5 [ 4 ] >> 56 ) ] ^
V_13 [ ( int ) ( V_5 [ 3 ] >> 48 ) & 0xff ] ^
V_14 [ ( int ) ( V_5 [ 2 ] >> 40 ) & 0xff ] ^
V_15 [ ( int ) ( V_5 [ 1 ] >> 32 ) & 0xff ] ^
V_16 [ ( int ) ( V_5 [ 0 ] >> 24 ) & 0xff ] ^
V_17 [ ( int ) ( V_5 [ 7 ] >> 16 ) & 0xff ] ^
V_18 [ ( int ) ( V_5 [ 6 ] >> 8 ) & 0xff ] ^
V_19 [ ( int ) ( V_5 [ 5 ] ) & 0xff ] ;
V_8 [ 5 ] = V_12 [ ( int ) ( V_5 [ 5 ] >> 56 ) ] ^
V_13 [ ( int ) ( V_5 [ 4 ] >> 48 ) & 0xff ] ^
V_14 [ ( int ) ( V_5 [ 3 ] >> 40 ) & 0xff ] ^
V_15 [ ( int ) ( V_5 [ 2 ] >> 32 ) & 0xff ] ^
V_16 [ ( int ) ( V_5 [ 1 ] >> 24 ) & 0xff ] ^
V_17 [ ( int ) ( V_5 [ 0 ] >> 16 ) & 0xff ] ^
V_18 [ ( int ) ( V_5 [ 7 ] >> 8 ) & 0xff ] ^
V_19 [ ( int ) ( V_5 [ 6 ] ) & 0xff ] ;
V_8 [ 6 ] = V_12 [ ( int ) ( V_5 [ 6 ] >> 56 ) ] ^
V_13 [ ( int ) ( V_5 [ 5 ] >> 48 ) & 0xff ] ^
V_14 [ ( int ) ( V_5 [ 4 ] >> 40 ) & 0xff ] ^
V_15 [ ( int ) ( V_5 [ 3 ] >> 32 ) & 0xff ] ^
V_16 [ ( int ) ( V_5 [ 2 ] >> 24 ) & 0xff ] ^
V_17 [ ( int ) ( V_5 [ 1 ] >> 16 ) & 0xff ] ^
V_18 [ ( int ) ( V_5 [ 0 ] >> 8 ) & 0xff ] ^
V_19 [ ( int ) ( V_5 [ 7 ] ) & 0xff ] ;
V_8 [ 7 ] = V_12 [ ( int ) ( V_5 [ 7 ] >> 56 ) ] ^
V_13 [ ( int ) ( V_5 [ 6 ] >> 48 ) & 0xff ] ^
V_14 [ ( int ) ( V_5 [ 5 ] >> 40 ) & 0xff ] ^
V_15 [ ( int ) ( V_5 [ 4 ] >> 32 ) & 0xff ] ^
V_16 [ ( int ) ( V_5 [ 3 ] >> 24 ) & 0xff ] ^
V_17 [ ( int ) ( V_5 [ 2 ] >> 16 ) & 0xff ] ^
V_18 [ ( int ) ( V_5 [ 1 ] >> 8 ) & 0xff ] ^
V_19 [ ( int ) ( V_5 [ 0 ] ) & 0xff ] ;
V_5 [ 0 ] = V_8 [ 0 ] ;
V_5 [ 1 ] = V_8 [ 1 ] ;
V_5 [ 2 ] = V_8 [ 2 ] ;
V_5 [ 3 ] = V_8 [ 3 ] ;
V_5 [ 4 ] = V_8 [ 4 ] ;
V_5 [ 5 ] = V_8 [ 5 ] ;
V_5 [ 6 ] = V_8 [ 6 ] ;
V_5 [ 7 ] = V_8 [ 7 ] ;
V_8 [ 0 ] = V_12 [ ( int ) ( V_7 [ 0 ] >> 56 ) ] ^
V_13 [ ( int ) ( V_7 [ 7 ] >> 48 ) & 0xff ] ^
V_14 [ ( int ) ( V_7 [ 6 ] >> 40 ) & 0xff ] ^
V_15 [ ( int ) ( V_7 [ 5 ] >> 32 ) & 0xff ] ^
V_16 [ ( int ) ( V_7 [ 4 ] >> 24 ) & 0xff ] ^
V_17 [ ( int ) ( V_7 [ 3 ] >> 16 ) & 0xff ] ^
V_18 [ ( int ) ( V_7 [ 2 ] >> 8 ) & 0xff ] ^
V_19 [ ( int ) ( V_7 [ 1 ] ) & 0xff ] ^
V_5 [ 0 ] ;
V_8 [ 1 ] = V_12 [ ( int ) ( V_7 [ 1 ] >> 56 ) ] ^
V_13 [ ( int ) ( V_7 [ 0 ] >> 48 ) & 0xff ] ^
V_14 [ ( int ) ( V_7 [ 7 ] >> 40 ) & 0xff ] ^
V_15 [ ( int ) ( V_7 [ 6 ] >> 32 ) & 0xff ] ^
V_16 [ ( int ) ( V_7 [ 5 ] >> 24 ) & 0xff ] ^
V_17 [ ( int ) ( V_7 [ 4 ] >> 16 ) & 0xff ] ^
V_18 [ ( int ) ( V_7 [ 3 ] >> 8 ) & 0xff ] ^
V_19 [ ( int ) ( V_7 [ 2 ] ) & 0xff ] ^
V_5 [ 1 ] ;
V_8 [ 2 ] = V_12 [ ( int ) ( V_7 [ 2 ] >> 56 ) ] ^
V_13 [ ( int ) ( V_7 [ 1 ] >> 48 ) & 0xff ] ^
V_14 [ ( int ) ( V_7 [ 0 ] >> 40 ) & 0xff ] ^
V_15 [ ( int ) ( V_7 [ 7 ] >> 32 ) & 0xff ] ^
V_16 [ ( int ) ( V_7 [ 6 ] >> 24 ) & 0xff ] ^
V_17 [ ( int ) ( V_7 [ 5 ] >> 16 ) & 0xff ] ^
V_18 [ ( int ) ( V_7 [ 4 ] >> 8 ) & 0xff ] ^
V_19 [ ( int ) ( V_7 [ 3 ] ) & 0xff ] ^
V_5 [ 2 ] ;
V_8 [ 3 ] = V_12 [ ( int ) ( V_7 [ 3 ] >> 56 ) ] ^
V_13 [ ( int ) ( V_7 [ 2 ] >> 48 ) & 0xff ] ^
V_14 [ ( int ) ( V_7 [ 1 ] >> 40 ) & 0xff ] ^
V_15 [ ( int ) ( V_7 [ 0 ] >> 32 ) & 0xff ] ^
V_16 [ ( int ) ( V_7 [ 7 ] >> 24 ) & 0xff ] ^
V_17 [ ( int ) ( V_7 [ 6 ] >> 16 ) & 0xff ] ^
V_18 [ ( int ) ( V_7 [ 5 ] >> 8 ) & 0xff ] ^
V_19 [ ( int ) ( V_7 [ 4 ] ) & 0xff ] ^
V_5 [ 3 ] ;
V_8 [ 4 ] = V_12 [ ( int ) ( V_7 [ 4 ] >> 56 ) ] ^
V_13 [ ( int ) ( V_7 [ 3 ] >> 48 ) & 0xff ] ^
V_14 [ ( int ) ( V_7 [ 2 ] >> 40 ) & 0xff ] ^
V_15 [ ( int ) ( V_7 [ 1 ] >> 32 ) & 0xff ] ^
V_16 [ ( int ) ( V_7 [ 0 ] >> 24 ) & 0xff ] ^
V_17 [ ( int ) ( V_7 [ 7 ] >> 16 ) & 0xff ] ^
V_18 [ ( int ) ( V_7 [ 6 ] >> 8 ) & 0xff ] ^
V_19 [ ( int ) ( V_7 [ 5 ] ) & 0xff ] ^
V_5 [ 4 ] ;
V_8 [ 5 ] = V_12 [ ( int ) ( V_7 [ 5 ] >> 56 ) ] ^
V_13 [ ( int ) ( V_7 [ 4 ] >> 48 ) & 0xff ] ^
V_14 [ ( int ) ( V_7 [ 3 ] >> 40 ) & 0xff ] ^
V_15 [ ( int ) ( V_7 [ 2 ] >> 32 ) & 0xff ] ^
V_16 [ ( int ) ( V_7 [ 1 ] >> 24 ) & 0xff ] ^
V_17 [ ( int ) ( V_7 [ 0 ] >> 16 ) & 0xff ] ^
V_18 [ ( int ) ( V_7 [ 7 ] >> 8 ) & 0xff ] ^
V_19 [ ( int ) ( V_7 [ 6 ] ) & 0xff ] ^
V_5 [ 5 ] ;
V_8 [ 6 ] = V_12 [ ( int ) ( V_7 [ 6 ] >> 56 ) ] ^
V_13 [ ( int ) ( V_7 [ 5 ] >> 48 ) & 0xff ] ^
V_14 [ ( int ) ( V_7 [ 4 ] >> 40 ) & 0xff ] ^
V_15 [ ( int ) ( V_7 [ 3 ] >> 32 ) & 0xff ] ^
V_16 [ ( int ) ( V_7 [ 2 ] >> 24 ) & 0xff ] ^
V_17 [ ( int ) ( V_7 [ 1 ] >> 16 ) & 0xff ] ^
V_18 [ ( int ) ( V_7 [ 0 ] >> 8 ) & 0xff ] ^
V_19 [ ( int ) ( V_7 [ 7 ] ) & 0xff ] ^
V_5 [ 6 ] ;
V_8 [ 7 ] = V_12 [ ( int ) ( V_7 [ 7 ] >> 56 ) ] ^
V_13 [ ( int ) ( V_7 [ 6 ] >> 48 ) & 0xff ] ^
V_14 [ ( int ) ( V_7 [ 5 ] >> 40 ) & 0xff ] ^
V_15 [ ( int ) ( V_7 [ 4 ] >> 32 ) & 0xff ] ^
V_16 [ ( int ) ( V_7 [ 3 ] >> 24 ) & 0xff ] ^
V_17 [ ( int ) ( V_7 [ 2 ] >> 16 ) & 0xff ] ^
V_18 [ ( int ) ( V_7 [ 1 ] >> 8 ) & 0xff ] ^
V_19 [ ( int ) ( V_7 [ 0 ] ) & 0xff ] ^
V_5 [ 7 ] ;
V_7 [ 0 ] = V_8 [ 0 ] ;
V_7 [ 1 ] = V_8 [ 1 ] ;
V_7 [ 2 ] = V_8 [ 2 ] ;
V_7 [ 3 ] = V_8 [ 3 ] ;
V_7 [ 4 ] = V_8 [ 4 ] ;
V_7 [ 5 ] = V_8 [ 5 ] ;
V_7 [ 6 ] = V_8 [ 6 ] ;
V_7 [ 7 ] = V_8 [ 7 ] ;
}
V_2 -> V_10 [ 0 ] ^= V_7 [ 0 ] ^ V_6 [ 0 ] ;
V_2 -> V_10 [ 1 ] ^= V_7 [ 1 ] ^ V_6 [ 1 ] ;
V_2 -> V_10 [ 2 ] ^= V_7 [ 2 ] ^ V_6 [ 2 ] ;
V_2 -> V_10 [ 3 ] ^= V_7 [ 3 ] ^ V_6 [ 3 ] ;
V_2 -> V_10 [ 4 ] ^= V_7 [ 4 ] ^ V_6 [ 4 ] ;
V_2 -> V_10 [ 5 ] ^= V_7 [ 5 ] ^ V_6 [ 5 ] ;
V_2 -> V_10 [ 6 ] ^= V_7 [ 6 ] ^ V_6 [ 6 ] ;
V_2 -> V_10 [ 7 ] ^= V_7 [ 7 ] ^ V_6 [ 7 ] ;
}
static int F_3 ( struct V_21 * V_22 ) {
struct V_1 * V_2 = F_4 ( V_22 ) ;
int V_3 ;
memset ( V_2 -> V_23 , 0 , 32 ) ;
V_2 -> V_24 = V_2 -> V_25 = 0 ;
V_2 -> V_9 [ 0 ] = 0 ;
for ( V_3 = 0 ; V_3 < 8 ; V_3 ++ ) {
V_2 -> V_10 [ V_3 ] = 0L ;
}
return 0 ;
}
static int F_5 ( struct V_21 * V_22 , const T_3 * V_26 ,
unsigned int V_27 )
{
struct V_1 * V_2 = F_4 ( V_22 ) ;
int V_28 = 0 ;
unsigned int V_29 = V_27 * 8 ;
int V_30 = ( 8 - ( ( int ) V_29 & 7 ) ) & 7 ;
int V_31 = V_2 -> V_24 & 7 ;
int V_3 ;
T_4 V_32 , V_33 ;
T_3 * V_9 = V_2 -> V_9 ;
T_3 * V_23 = V_2 -> V_23 ;
int V_24 = V_2 -> V_24 ;
int V_25 = V_2 -> V_25 ;
T_1 V_34 = V_29 ;
for ( V_3 = 31 , V_33 = 0 ; V_3 >= 0 && ( V_33 != 0 || V_34 != 0ULL ) ; V_3 -- ) {
V_33 += V_23 [ V_3 ] + ( ( T_4 ) V_34 & 0xff ) ;
V_23 [ V_3 ] = ( T_3 ) V_33 ;
V_33 >>= 8 ;
V_34 >>= 8 ;
}
while ( V_29 > 8 ) {
V_32 = ( ( V_26 [ V_28 ] << V_30 ) & 0xff ) |
( ( V_26 [ V_28 + 1 ] & 0xff ) >> ( 8 - V_30 ) ) ;
V_9 [ V_25 ++ ] |= ( T_3 ) ( V_32 >> V_31 ) ;
V_24 += 8 - V_31 ;
if ( V_24 == V_35 * 8 ) {
F_1 ( V_2 ) ;
V_24 = V_25 = 0 ;
}
V_9 [ V_25 ] = V_32 << ( 8 - V_31 ) ;
V_24 += V_31 ;
V_29 -= 8 ;
V_28 ++ ;
}
if ( V_29 > 0 ) {
V_32 = ( V_26 [ V_28 ] << V_30 ) & 0xff ;
V_9 [ V_25 ] |= V_32 >> V_31 ;
} else {
V_32 = 0 ;
}
if ( V_31 + V_29 < 8 ) {
V_24 += V_29 ;
} else {
V_25 ++ ;
V_24 += 8 - V_31 ;
V_29 -= 8 - V_31 ;
if ( V_24 == V_35 * 8 ) {
F_1 ( V_2 ) ;
V_24 = V_25 = 0 ;
}
V_9 [ V_25 ] = V_32 << ( 8 - V_31 ) ;
V_24 += ( int ) V_29 ;
}
V_2 -> V_24 = V_24 ;
V_2 -> V_25 = V_25 ;
return 0 ;
}
static int F_6 ( struct V_21 * V_22 , T_3 * V_36 )
{
struct V_1 * V_2 = F_4 ( V_22 ) ;
int V_3 ;
T_3 * V_9 = V_2 -> V_9 ;
T_3 * V_23 = V_2 -> V_23 ;
int V_24 = V_2 -> V_24 ;
int V_25 = V_2 -> V_25 ;
T_2 * V_37 = ( T_2 * ) V_36 ;
V_9 [ V_25 ] |= 0x80U >> ( V_24 & 7 ) ;
V_25 ++ ;
if ( V_25 > V_35 - V_38 ) {
if ( V_25 < V_35 ) {
memset ( & V_9 [ V_25 ] , 0 , V_35 - V_25 ) ;
}
F_1 ( V_2 ) ;
V_25 = 0 ;
}
if ( V_25 < V_35 - V_38 ) {
memset ( & V_9 [ V_25 ] , 0 ,
( V_35 - V_38 ) - V_25 ) ;
}
V_25 = V_35 - V_38 ;
memcpy ( & V_9 [ V_35 - V_38 ] ,
V_23 , V_38 ) ;
F_1 ( V_2 ) ;
for ( V_3 = 0 ; V_3 < V_39 / 8 ; V_3 ++ )
V_37 [ V_3 ] = F_7 ( V_2 -> V_10 [ V_3 ] ) ;
V_2 -> V_24 = V_24 ;
V_2 -> V_25 = V_25 ;
return 0 ;
}
static int F_8 ( struct V_21 * V_22 , T_3 * V_36 )
{
T_3 V_40 [ 64 ] ;
F_6 ( V_22 , V_40 ) ;
memcpy ( V_36 , V_40 , V_41 ) ;
memset ( V_40 , 0 , V_39 ) ;
return 0 ;
}
static int F_9 ( struct V_21 * V_22 , T_3 * V_36 )
{
T_3 V_40 [ 64 ] ;
F_6 ( V_22 , V_40 ) ;
memcpy ( V_36 , V_40 , V_42 ) ;
memset ( V_40 , 0 , V_39 ) ;
return 0 ;
}
static int T_5 F_10 ( void )
{
int V_43 = 0 ;
V_43 = F_11 ( & V_44 ) ;
if ( V_43 < 0 )
goto V_36;
V_43 = F_11 ( & V_45 ) ;
if ( V_43 < 0 )
{
F_12 ( & V_44 ) ;
goto V_36;
}
V_43 = F_11 ( & V_46 ) ;
if ( V_43 < 0 )
{
F_12 ( & V_44 ) ;
F_12 ( & V_45 ) ;
}
V_36:
return V_43 ;
}
static void T_6 F_13 ( void )
{
F_12 ( & V_44 ) ;
F_12 ( & V_45 ) ;
F_12 ( & V_46 ) ;
}
