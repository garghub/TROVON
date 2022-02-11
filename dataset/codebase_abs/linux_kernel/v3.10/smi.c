enum V_1 F_1 ( struct V_2 * V_3 ,
T_1 V_4 , int V_5 )
{
T_1 V_6 , V_7 ;
V_6 = V_3 -> V_6 ;
V_7 = V_3 -> V_7 ;
if ( V_7 >= V_8 )
return V_9 ;
if ( ! F_2 ( V_3 ) ) {
if ( V_7 && V_6 == 0 ) {
V_3 -> V_6 ++ ;
return ( V_3 -> V_10 [ V_3 -> V_6 ] ==
V_5 ? V_11 : V_9 ) ;
}
if ( V_6 && V_6 < V_7 ) {
if ( V_4 != V_12 )
return V_9 ;
V_3 -> V_6 ++ ;
return ( V_3 -> V_10 [ V_3 -> V_6 ] ==
V_5 ? V_11 : V_9 ) ;
}
if ( V_6 == V_7 ) {
V_3 -> V_6 ++ ;
return ( V_4 == V_12 ||
V_3 -> V_13 == V_14 ?
V_11 : V_9 ) ;
}
return ( V_6 == V_7 + 1 ? V_11 : V_9 ) ;
} else {
if ( V_7 && V_6 == V_7 + 1 ) {
V_3 -> V_6 -- ;
return ( V_3 -> V_15 [ V_3 -> V_6 ] ==
V_5 ? V_11 : V_9 ) ;
}
if ( 2 <= V_6 && V_6 <= V_7 ) {
if ( V_4 != V_12 )
return V_9 ;
V_3 -> V_6 -- ;
return ( V_3 -> V_15 [ V_3 -> V_6 ] ==
V_5 ? V_11 : V_9 ) ;
}
if ( V_6 == 1 ) {
V_3 -> V_6 -- ;
return ( V_4 == V_12 ||
V_3 -> V_16 == V_14 ?
V_11 : V_9 ) ;
}
if ( V_6 == 0 )
return V_11 ;
return V_9 ;
}
}
enum V_1 F_3 ( struct V_2 * V_3 , T_1 V_4 ,
int V_5 , int V_17 )
{
T_1 V_6 , V_7 ;
V_6 = V_3 -> V_6 ;
V_7 = V_3 -> V_7 ;
if ( V_7 >= V_8 )
return V_9 ;
if ( ! F_2 ( V_3 ) ) {
if ( V_7 && V_6 == 0 )
return V_9 ;
if ( V_6 && V_6 < V_7 ) {
if ( V_4 != V_12 )
return V_9 ;
V_3 -> V_15 [ V_6 ] = V_5 ;
return ( V_3 -> V_10 [ V_6 + 1 ] <= V_17 ?
V_11 : V_9 ) ;
}
if ( V_6 == V_7 ) {
if ( V_7 )
V_3 -> V_15 [ V_6 ] = V_5 ;
return ( V_4 == V_12 ||
V_3 -> V_13 == V_14 ?
V_11 : V_9 ) ;
}
return ( V_6 == V_7 + 1 ? V_11 : V_9 ) ;
} else {
if ( V_7 && V_6 == V_7 + 1 ) {
V_3 -> V_6 -- ;
return ( V_3 -> V_15 [ V_3 -> V_6 ] ==
V_5 ? V_11 : V_9 ) ;
}
if ( 2 <= V_6 && V_6 <= V_7 ) {
if ( V_4 != V_12 )
return V_9 ;
return ( V_3 -> V_15 [ V_6 - 1 ] <= V_17 ?
V_11 : V_9 ) ;
}
if ( V_6 == 1 ) {
if ( V_3 -> V_16 == V_14 ) {
V_3 -> V_6 -- ;
return V_11 ;
}
return ( V_4 == V_12 ?
V_11 : V_9 ) ;
}
return ( V_6 == 0 ? V_11 : V_9 ) ;
}
}
enum V_18 F_4 ( struct V_2 * V_3 )
{
T_1 V_6 , V_7 ;
V_6 = V_3 -> V_6 ;
V_7 = V_3 -> V_7 ;
if ( ! F_2 ( V_3 ) ) {
if ( V_6 && V_6 < V_7 )
return V_19 ;
if ( V_6 == V_7 )
return ( V_3 -> V_13 == V_14 ?
V_20 : V_21 ) ;
if ( V_6 == V_7 + 1 )
return V_20 ;
} else {
if ( 2 <= V_6 && V_6 <= V_7 )
return V_19 ;
if ( V_6 == 1 )
return ( V_3 -> V_16 != V_14 ?
V_20 : V_21 ) ;
}
return V_21 ;
}
int F_5 ( struct V_2 * V_3 )
{
return ( ! F_2 ( V_3 ) ? V_3 -> V_10 [ V_3 -> V_6 + 1 ] :
V_3 -> V_15 [ V_3 -> V_6 - 1 ] ) ;
}
