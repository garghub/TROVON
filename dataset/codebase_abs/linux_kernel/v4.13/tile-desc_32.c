const struct V_1 *
F_1 ( T_1 V_2 , T_2 V_3 )
{
const unsigned short * V_4 = V_5 [ V_3 ] ;
int V_6 = 0 ;
while ( 1 )
{
unsigned short V_7 = V_4 [ V_6 ] ;
unsigned int V_8 =
( ( unsigned int ) ( V_2 >> ( V_7 & 63 ) ) ) & ( V_7 >> 6 ) ;
unsigned short V_9 = V_4 [ V_6 + 1 + V_8 ] ;
if ( V_9 <= V_10 )
return & V_11 [ V_9 ] ;
V_6 = V_9 - V_10 ;
}
}
int
F_2 ( T_1 V_2 ,
unsigned int V_12 ,
struct V_13
V_14 [ V_15 ] )
{
int V_16 = 0 ;
int V_3 ;
int V_17 , V_18 ;
if ( ( V_2 & V_19 ) == 0 )
{
V_17 = V_20 ;
V_18 = V_21 ;
}
else
{
V_17 = V_22 ;
V_18 = V_23 ;
}
for ( V_3 = V_17 ; V_3 <= V_18 ; V_3 ++ )
{
const struct V_1 * V_24 ;
struct V_13 * V_25 ;
int V_26 ;
V_25 = & V_14 [ V_16 ++ ] ;
V_24 = F_1 ( V_2 , ( T_2 ) V_3 ) ;
V_25 -> V_27 = V_24 ;
for ( V_26 = 0 ; V_26 < V_24 -> V_28 ; V_26 ++ )
{
const struct V_29 * V_30 =
& V_31 [ V_24 -> V_32 [ V_3 ] [ V_26 ] ] ;
int V_33 = V_30 -> V_34 ( V_2 ) ;
if ( V_30 -> V_35 )
{
int V_36 = ( int ) ( ( sizeof( int ) * 8 ) - V_30 -> V_37 ) ;
V_33 = ( V_33 << V_36 ) >> V_36 ;
}
if ( V_30 -> type == V_38 )
{
V_33 *= V_39 ;
V_33 += ( int ) V_12 ;
}
V_25 -> V_32 [ V_26 ] = V_30 ;
V_25 -> V_40 [ V_26 ] = V_33 ;
}
}
return V_16 ;
}
