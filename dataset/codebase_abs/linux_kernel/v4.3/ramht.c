static T_1
F_1 ( struct V_1 * V_2 , int V_3 , T_1 V_4 )
{
T_1 V_5 = 0 ;
while ( V_4 ) {
V_5 ^= ( V_4 & ( ( 1 << V_2 -> V_6 ) - 1 ) ) ;
V_4 >>= V_2 -> V_6 ;
}
V_5 ^= V_3 << ( V_2 -> V_6 - 4 ) ;
return V_5 ;
}
struct V_7 *
F_2 ( struct V_1 * V_2 , int V_3 , T_1 V_4 )
{
T_1 V_8 , V_9 ;
V_8 = V_9 = F_1 ( V_2 , V_3 , V_4 ) ;
do {
if ( V_2 -> V_10 [ V_8 ] . V_3 == V_3 ) {
if ( V_2 -> V_10 [ V_8 ] . V_4 == V_4 )
return V_2 -> V_10 [ V_8 ] . V_11 ;
}
if ( ++ V_8 >= V_2 -> V_12 )
V_8 = 0 ;
} while ( V_8 != V_9 );
return NULL ;
}
static int
F_3 ( struct V_1 * V_2 , int V_8 , struct V_13 * V_14 ,
int V_3 , int V_15 , T_1 V_4 , T_1 V_16 )
{
struct V_17 * V_10 = & V_2 -> V_10 [ V_8 ] ;
T_2 V_11 = 0x00000040 ;
int V_18 ;
F_4 ( & V_10 -> V_11 ) ;
V_10 -> V_3 = V_3 ;
V_10 -> V_4 = V_4 ;
if ( V_14 ) {
V_18 = F_5 ( V_14 , V_2 -> V_19 , 16 , & V_10 -> V_11 ) ;
if ( V_18 ) {
if ( V_18 != - V_20 ) {
V_10 -> V_3 = - 1 ;
return V_18 ;
}
V_10 -> V_11 = NULL ;
}
if ( V_10 -> V_11 ) {
if ( V_2 -> V_21 -> V_22 >= V_23 )
V_11 = V_10 -> V_11 -> V_24 -> V_25 ;
else
V_11 = V_10 -> V_11 -> V_15 ;
}
if ( V_15 < 0 ) V_16 |= V_11 << - V_15 ;
else V_16 |= V_11 >> V_15 ;
}
F_6 ( V_2 -> V_26 ) ;
F_7 ( V_2 -> V_26 , ( V_8 << 3 ) + 0 , V_4 ) ;
F_7 ( V_2 -> V_26 , ( V_8 << 3 ) + 4 , V_16 ) ;
F_8 ( V_2 -> V_26 ) ;
return V_8 + 1 ;
}
void
F_9 ( struct V_1 * V_2 , int V_27 )
{
if ( -- V_27 >= 0 )
F_3 ( V_2 , V_27 , NULL , - 1 , 0 , 0 , 0 ) ;
}
int
F_10 ( struct V_1 * V_2 , struct V_13 * V_14 ,
int V_3 , int V_15 , T_1 V_4 , T_1 V_16 )
{
T_1 V_8 , V_9 ;
if ( F_2 ( V_2 , V_3 , V_4 ) )
return - V_28 ;
V_8 = V_9 = F_1 ( V_2 , V_3 , V_4 ) ;
do {
if ( V_2 -> V_10 [ V_8 ] . V_3 < 0 ) {
return F_3 ( V_2 , V_8 , V_14 , V_3 ,
V_15 , V_4 , V_16 ) ;
}
if ( ++ V_8 >= V_2 -> V_12 )
V_8 = 0 ;
} while ( V_8 != V_9 );
return - V_29 ;
}
void
F_11 ( struct V_1 * * V_30 )
{
struct V_1 * V_2 = * V_30 ;
if ( V_2 ) {
F_4 ( & V_2 -> V_26 ) ;
F_12 ( * V_30 ) ;
* V_30 = NULL ;
}
}
int
F_13 ( struct V_31 * V_21 , T_1 V_12 , T_1 V_32 ,
struct V_7 * V_19 , struct V_1 * * V_30 )
{
struct V_1 * V_2 ;
int V_18 , V_33 ;
if ( ! ( V_2 = * V_30 = F_14 ( sizeof( * V_2 ) + ( V_12 >> 3 ) *
sizeof( * V_2 -> V_10 ) , V_34 ) ) )
return - V_35 ;
V_2 -> V_21 = V_21 ;
V_2 -> V_19 = V_19 ;
V_2 -> V_12 = V_12 >> 3 ;
V_2 -> V_6 = F_15 ( V_2 -> V_12 ) ;
for ( V_33 = 0 ; V_33 < V_2 -> V_12 ; V_33 ++ )
V_2 -> V_10 [ V_33 ] . V_3 = - 1 ;
V_18 = F_16 ( V_2 -> V_21 , V_12 , V_32 , true ,
V_2 -> V_19 , & V_2 -> V_26 ) ;
if ( V_18 )
F_11 ( V_30 ) ;
return V_18 ;
}
