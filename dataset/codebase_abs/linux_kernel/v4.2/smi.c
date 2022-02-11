static enum V_1 F_1 ( bool V_2 , int V_3 ,
T_1 * V_4 , T_1 V_5 ,
const T_1 * V_6 ,
const T_1 * V_7 ,
T_1 V_8 ,
bool V_9 ,
bool V_10 )
{
if ( V_5 >= V_11 )
return V_12 ;
if ( ! V_8 ) {
if ( V_5 && * V_4 == 0 ) {
( * V_4 ) ++ ;
return ( V_6 [ * V_4 ] ==
V_3 ? V_13 : V_12 ) ;
}
if ( * V_4 && * V_4 < V_5 ) {
if ( ! V_2 )
return V_12 ;
( * V_4 ) ++ ;
return ( V_6 [ * V_4 ] ==
V_3 ? V_13 : V_12 ) ;
}
if ( * V_4 == V_5 ) {
( * V_4 ) ++ ;
return ( V_2 ||
V_9 ?
V_13 : V_12 ) ;
}
return ( * V_4 == V_5 + 1 ? V_13 : V_12 ) ;
} else {
if ( V_5 && * V_4 == V_5 + 1 ) {
( * V_4 ) -- ;
return ( V_7 [ * V_4 ] ==
V_3 ? V_13 : V_12 ) ;
}
if ( 2 <= * V_4 && * V_4 <= V_5 ) {
if ( ! V_2 )
return V_12 ;
( * V_4 ) -- ;
return ( V_7 [ * V_4 ] ==
V_3 ? V_13 : V_12 ) ;
}
if ( * V_4 == 1 ) {
( * V_4 ) -- ;
return ( V_2 ||
V_10 ?
V_13 : V_12 ) ;
}
if ( * V_4 == 0 )
return V_13 ;
return V_12 ;
}
}
enum V_1 F_2 ( struct V_14 * V_15 ,
bool V_2 , int V_3 )
{
return F_1 ( V_2 , V_3 ,
& V_15 -> V_4 , V_15 -> V_5 ,
V_15 -> V_6 ,
V_15 -> V_7 ,
F_3 ( V_15 ) ,
V_15 -> V_16 == V_17 ,
V_15 -> V_18 == V_17 ) ;
}
enum V_1 F_4 ( struct V_19 * V_15 ,
bool V_2 , int V_3 )
{
return F_1 ( V_2 , V_3 ,
& V_15 -> V_4 , V_15 -> V_5 ,
V_15 -> V_20 . V_21 . V_6 ,
V_15 -> V_20 . V_21 . V_7 ,
F_5 ( V_15 ) ,
V_15 -> V_20 . V_21 . V_16 ==
V_22 ,
V_15 -> V_20 . V_21 . V_18 ==
V_22 ) ;
}
static enum V_1 F_6 ( bool V_2 , int V_3 ,
int V_23 ,
T_1 * V_4 , T_1 V_5 ,
const T_1 * V_6 ,
T_1 * V_7 ,
T_1 V_8 ,
bool V_9 ,
bool V_10 )
{
if ( V_5 >= V_11 )
return V_12 ;
if ( ! V_8 ) {
if ( V_5 && * V_4 == 0 )
return V_12 ;
if ( * V_4 && * V_4 < V_5 ) {
if ( ! V_2 )
return V_12 ;
V_7 [ * V_4 ] = V_3 ;
return ( V_6 [ * V_4 + 1 ] <= V_23 ?
V_13 : V_12 ) ;
}
if ( * V_4 == V_5 ) {
if ( V_5 )
V_7 [ * V_4 ] = V_3 ;
return ( V_2 ||
V_9 ?
V_13 : V_12 ) ;
}
return ( * V_4 == V_5 + 1 ? V_13 : V_12 ) ;
} else {
if ( V_5 && * V_4 == V_5 + 1 ) {
( * V_4 ) -- ;
return ( V_7 [ * V_4 ] ==
V_3 ? V_13 : V_12 ) ;
}
if ( 2 <= * V_4 && * V_4 <= V_5 ) {
if ( ! V_2 )
return V_12 ;
return ( V_7 [ * V_4 - 1 ] <= V_23 ?
V_13 : V_12 ) ;
}
if ( * V_4 == 1 ) {
if ( V_10 ) {
( * V_4 ) -- ;
return V_13 ;
}
return ( V_2 ? V_13 : V_12 ) ;
}
return ( * V_4 == 0 ? V_13 : V_12 ) ;
}
}
enum V_1 F_7 ( struct V_14 * V_15 , bool V_2 ,
int V_3 , int V_23 )
{
return F_6 ( V_2 , V_3 , V_23 ,
& V_15 -> V_4 , V_15 -> V_5 ,
V_15 -> V_6 ,
V_15 -> V_7 ,
F_3 ( V_15 ) ,
V_15 -> V_16 == V_17 ,
V_15 -> V_18 == V_17 ) ;
}
enum V_1 F_8 ( struct V_19 * V_15 , bool V_2 ,
int V_3 , int V_23 )
{
return F_6 ( V_2 , V_3 , V_23 ,
& V_15 -> V_4 , V_15 -> V_5 ,
V_15 -> V_20 . V_21 . V_6 ,
V_15 -> V_20 . V_21 . V_7 ,
F_5 ( V_15 ) ,
V_15 -> V_20 . V_21 . V_16 ==
V_22 ,
V_15 -> V_20 . V_21 . V_18 ==
V_22 ) ;
}
static enum V_24 F_9 ( T_1 V_4 , T_1 V_5 ,
T_1 V_8 ,
bool V_9 ,
bool V_10 )
{
if ( ! V_8 ) {
if ( V_4 && V_4 < V_5 )
return V_25 ;
if ( V_4 == V_5 )
return ( V_9 ?
V_26 : V_27 ) ;
if ( V_4 == V_5 + 1 )
return V_26 ;
} else {
if ( 2 <= V_4 && V_4 <= V_5 )
return V_25 ;
if ( V_4 == 1 )
return ( ! V_10 ?
V_26 : V_27 ) ;
}
return V_27 ;
}
enum V_24 F_10 ( struct V_14 * V_15 )
{
return F_9 ( V_15 -> V_4 , V_15 -> V_5 ,
F_3 ( V_15 ) ,
V_15 -> V_16 == V_17 ,
V_15 -> V_18 == V_17 ) ;
}
enum V_24 F_11 ( struct V_19 * V_15 )
{
return F_9 ( V_15 -> V_4 , V_15 -> V_5 ,
F_5 ( V_15 ) ,
V_15 -> V_20 . V_21 . V_16 ==
V_22 ,
V_15 -> V_20 . V_21 . V_18 ==
V_22 ) ;
}
int F_12 ( struct V_14 * V_15 )
{
return ( ! F_3 ( V_15 ) ? V_15 -> V_6 [ V_15 -> V_4 + 1 ] :
V_15 -> V_7 [ V_15 -> V_4 - 1 ] ) ;
}
int F_13 ( struct V_19 * V_15 )
{
return ! F_5 ( V_15 ) ? V_15 -> V_20 . V_21 . V_6 [ V_15 -> V_4 + 1 ] :
V_15 -> V_20 . V_21 . V_7 [ V_15 -> V_4 - 1 ] ;
}
