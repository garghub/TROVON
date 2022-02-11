static void F_1 ( T_1 V_1 [ 25 ] )
{
int V_2 , V_3 , V_4 ;
T_1 V_5 , V_6 [ 5 ] ;
for ( V_4 = 0 ; V_4 < V_7 ; V_4 ++ ) {
for ( V_2 = 0 ; V_2 < 5 ; V_2 ++ )
V_6 [ V_2 ] = V_1 [ V_2 ] ^ V_1 [ V_2 + 5 ] ^ V_1 [ V_2 + 10 ] ^ V_1 [ V_2 + 15 ]
^ V_1 [ V_2 + 20 ] ;
for ( V_2 = 0 ; V_2 < 5 ; V_2 ++ ) {
V_5 = V_6 [ ( V_2 + 4 ) % 5 ] ^ F_2 ( V_6 [ ( V_2 + 1 ) % 5 ] , 1 ) ;
for ( V_3 = 0 ; V_3 < 25 ; V_3 += 5 )
V_1 [ V_3 + V_2 ] ^= V_5 ;
}
V_5 = V_1 [ 1 ] ;
for ( V_2 = 0 ; V_2 < 24 ; V_2 ++ ) {
V_3 = V_8 [ V_2 ] ;
V_6 [ 0 ] = V_1 [ V_3 ] ;
V_1 [ V_3 ] = F_2 ( V_5 , V_9 [ V_2 ] ) ;
V_5 = V_6 [ 0 ] ;
}
for ( V_3 = 0 ; V_3 < 25 ; V_3 += 5 ) {
for ( V_2 = 0 ; V_2 < 5 ; V_2 ++ )
V_6 [ V_2 ] = V_1 [ V_3 + V_2 ] ;
for ( V_2 = 0 ; V_2 < 5 ; V_2 ++ )
V_1 [ V_3 + V_2 ] ^= ( ~ V_6 [ ( V_2 + 1 ) % 5 ] ) &
V_6 [ ( V_2 + 2 ) % 5 ] ;
}
V_1 [ 0 ] ^= V_10 [ V_4 ] ;
}
}
static void F_3 ( struct V_11 * V_12 , unsigned int V_13 )
{
memset ( V_12 , 0 , sizeof( * V_12 ) ) ;
V_12 -> V_14 = V_13 ;
V_12 -> V_15 = 200 - 2 * V_13 ;
V_12 -> V_16 = V_12 -> V_15 / 8 ;
}
static int F_4 ( struct V_17 * V_18 )
{
struct V_11 * V_12 = F_5 ( V_18 ) ;
F_3 ( V_12 , V_19 ) ;
return 0 ;
}
static int F_6 ( struct V_17 * V_18 )
{
struct V_11 * V_12 = F_5 ( V_18 ) ;
F_3 ( V_12 , V_20 ) ;
return 0 ;
}
static int F_7 ( struct V_17 * V_18 )
{
struct V_11 * V_12 = F_5 ( V_18 ) ;
F_3 ( V_12 , V_21 ) ;
return 0 ;
}
static int F_8 ( struct V_17 * V_18 )
{
struct V_11 * V_12 = F_5 ( V_18 ) ;
F_3 ( V_12 , V_22 ) ;
return 0 ;
}
static int F_9 ( struct V_17 * V_18 , const T_2 * V_23 ,
unsigned int V_24 )
{
struct V_11 * V_12 = F_5 ( V_18 ) ;
unsigned int V_25 ;
const T_2 * V_26 ;
V_25 = 0 ;
V_26 = V_23 ;
if ( ( V_12 -> V_27 + V_24 ) > ( V_12 -> V_15 - 1 ) ) {
if ( V_12 -> V_27 ) {
V_25 = - V_12 -> V_27 ;
memcpy ( V_12 -> V_28 + V_12 -> V_27 , V_23 ,
V_25 + V_12 -> V_15 ) ;
V_26 = V_12 -> V_28 ;
}
do {
unsigned int V_2 ;
for ( V_2 = 0 ; V_2 < V_12 -> V_16 ; V_2 ++ )
V_12 -> V_1 [ V_2 ] ^= ( ( T_1 * ) V_26 ) [ V_2 ] ;
F_1 ( V_12 -> V_1 ) ;
V_25 += V_12 -> V_15 ;
V_26 = V_23 + V_25 ;
} while ( V_25 + ( V_12 -> V_15 - 1 ) < V_24 );
V_12 -> V_27 = 0 ;
}
memcpy ( V_12 -> V_28 + V_12 -> V_27 , V_26 , V_24 - V_25 ) ;
V_12 -> V_27 += ( V_24 - V_25 ) ;
return 0 ;
}
static int F_10 ( struct V_17 * V_18 , T_2 * V_29 )
{
struct V_11 * V_12 = F_5 ( V_18 ) ;
unsigned int V_2 , V_30 = V_12 -> V_27 ;
V_12 -> V_28 [ V_30 ++ ] = 0x06 ;
memset ( V_12 -> V_28 + V_30 , 0 , V_12 -> V_15 - V_30 ) ;
V_12 -> V_28 [ V_12 -> V_15 - 1 ] |= 0x80 ;
for ( V_2 = 0 ; V_2 < V_12 -> V_16 ; V_2 ++ )
V_12 -> V_1 [ V_2 ] ^= ( ( T_1 * ) V_12 -> V_28 ) [ V_2 ] ;
F_1 ( V_12 -> V_1 ) ;
for ( V_2 = 0 ; V_2 < V_12 -> V_16 ; V_2 ++ )
V_12 -> V_1 [ V_2 ] = F_11 ( V_12 -> V_1 [ V_2 ] ) ;
memcpy ( V_29 , V_12 -> V_1 , V_12 -> V_14 ) ;
memset ( V_12 , 0 , sizeof( * V_12 ) ) ;
return 0 ;
}
static int T_3 F_12 ( void )
{
int V_31 ;
V_31 = F_13 ( & V_32 ) ;
if ( V_31 < 0 )
goto V_33;
V_31 = F_13 ( & V_34 ) ;
if ( V_31 < 0 )
goto V_35;
V_31 = F_13 ( & V_36 ) ;
if ( V_31 < 0 )
goto V_37;
V_31 = F_13 ( & V_38 ) ;
if ( V_31 < 0 )
goto V_39;
return 0 ;
V_39:
F_14 ( & V_36 ) ;
V_37:
F_14 ( & V_34 ) ;
V_35:
F_14 ( & V_32 ) ;
V_33:
return V_31 ;
}
static void T_4 F_15 ( void )
{
F_14 ( & V_32 ) ;
F_14 ( & V_34 ) ;
F_14 ( & V_36 ) ;
F_14 ( & V_38 ) ;
}
