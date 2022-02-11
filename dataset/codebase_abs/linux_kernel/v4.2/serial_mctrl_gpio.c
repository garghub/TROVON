void F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
enum V_4 V_5 ;
struct V_6 * V_7 [ V_8 ] ;
int V_9 [ V_8 ] ;
unsigned int V_10 = 0 ;
for ( V_5 = 0 ; V_5 < V_8 ; V_5 ++ )
if ( V_2 -> V_11 [ V_5 ] && V_12 [ V_5 ] . V_13 ) {
V_7 [ V_10 ] = V_2 -> V_11 [ V_5 ] ;
V_9 [ V_10 ] = ! ! ( V_3 & V_12 [ V_5 ] . V_3 ) ;
V_10 ++ ;
}
F_2 ( V_10 , V_7 , V_9 ) ;
}
struct V_6 * F_3 ( struct V_1 * V_2 ,
enum V_4 V_14 )
{
return V_2 -> V_11 [ V_14 ] ;
}
unsigned int F_4 ( struct V_1 * V_2 , unsigned int * V_3 )
{
enum V_4 V_5 ;
for ( V_5 = 0 ; V_5 < V_8 ; V_5 ++ ) {
if ( V_2 -> V_11 [ V_5 ] && ! V_12 [ V_5 ] . V_13 ) {
if ( F_5 ( V_2 -> V_11 [ V_5 ] ) )
* V_3 |= V_12 [ V_5 ] . V_3 ;
else
* V_3 &= ~ V_12 [ V_5 ] . V_3 ;
}
}
return * V_3 ;
}
struct V_1 * F_6 ( struct V_15 * V_16 , unsigned int V_17 )
{
struct V_1 * V_2 ;
enum V_4 V_5 ;
V_2 = F_7 ( V_16 , sizeof( * V_2 ) , V_18 ) ;
if ( ! V_2 )
return F_8 ( - V_19 ) ;
for ( V_5 = 0 ; V_5 < V_8 ; V_5 ++ ) {
enum V_20 V_21 ;
if ( V_12 [ V_5 ] . V_13 )
V_21 = V_22 ;
else
V_21 = V_23 ;
V_2 -> V_11 [ V_5 ] =
F_9 ( V_16 ,
V_12 [ V_5 ] . V_24 ,
V_17 , V_21 ) ;
if ( F_10 ( V_2 -> V_11 [ V_5 ] ) )
return F_11 ( V_2 -> V_11 [ V_5 ] ) ;
}
return V_2 ;
}
void F_12 ( struct V_15 * V_16 , struct V_1 * V_2 )
{
enum V_4 V_5 ;
for ( V_5 = 0 ; V_5 < V_8 ; V_5 ++ )
if ( V_2 -> V_11 [ V_5 ] )
F_13 ( V_16 , V_2 -> V_11 [ V_5 ] ) ;
F_14 ( V_16 , V_2 ) ;
}
