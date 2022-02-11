static const struct V_1 *
F_1 ( T_1 V_2 , const unsigned short * V_3 )
{
int V_4 = 0 ;
while ( 1 )
{
unsigned short V_5 = V_3 [ V_4 ] ;
unsigned int V_6 =
( ( unsigned int ) ( V_2 >> ( V_5 & 63 ) ) ) & ( V_5 >> 6 ) ;
unsigned short V_7 = V_3 [ V_4 + 1 + V_6 ] ;
if ( V_7 <= V_8 )
return & V_9 [ V_7 ] ;
V_4 = V_7 - V_8 ;
}
}
int
F_2 ( T_1 V_2 ,
unsigned long long V_10 ,
struct V_11
V_12 [ V_13 ] )
{
int V_14 = 0 ;
int V_15 ;
int V_16 , V_17 ;
if ( ( V_2 & V_18 ) == 0 )
{
V_16 = V_19 ;
V_17 = V_20 ;
}
else
{
V_16 = V_21 ;
V_17 = V_22 ;
}
for ( V_15 = V_16 ; V_15 <= V_17 ; V_15 ++ )
{
const struct V_1 * V_23 ;
struct V_11 * V_24 ;
int V_25 ;
V_24 = & V_12 [ V_14 ++ ] ;
V_23 = F_1 ( V_2 , V_26 [ V_15 ] ) ;
V_24 -> V_27 = V_23 ;
for ( V_25 = 0 ; V_25 < V_23 -> V_28 ; V_25 ++ )
{
const struct V_29 * V_30 =
& V_31 [ V_23 -> V_32 [ V_15 ] [ V_25 ] ] ;
int V_33 = V_30 -> V_34 ( V_2 ) ;
long long V_35 ;
if ( V_30 -> V_36 )
{
int V_37 = ( int ) ( ( sizeof( int ) * 8 ) - V_30 -> V_38 ) ;
V_33 = ( V_33 << V_37 ) >> V_37 ;
}
if ( V_30 -> type == V_39 )
V_35 = ( V_33 * V_40 ) + V_10 ;
else
V_35 = V_33 ;
V_24 -> V_32 [ V_25 ] = V_30 ;
V_24 -> V_41 [ V_25 ] = V_35 ;
}
}
return V_14 ;
}
