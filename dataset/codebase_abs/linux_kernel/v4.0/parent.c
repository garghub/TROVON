int
F_1 ( struct V_1 * V_2 , T_1 V_3 ,
struct V_1 * * V_4 ,
struct V_5 * * V_6 )
{
struct V_7 * V_8 ;
struct V_9 * V_10 ;
struct V_5 * V_11 ;
T_2 V_12 ;
V_8 = F_2 ( V_2 ) -> V_8 ;
while ( V_8 ) {
if ( ( V_8 -> V_11 -> V_3 & 0xffff ) == V_3 ) {
* V_4 = & V_2 -> V_10 -> V_13 . V_14 ;
* V_6 = V_8 -> V_11 ;
return 0 ;
}
V_8 = V_8 -> V_8 ;
}
V_12 = F_2 ( V_2 ) -> V_10 ;
while ( V_12 ) {
int V_15 = F_3 ( V_12 ) ;
if ( F_4 ( V_2 , V_16 ) )
V_10 = F_5 ( F_6 ( V_2 ) -> V_17 ) ;
else
V_10 = V_9 ( V_2 , V_15 ) ;
if ( V_10 ) {
V_11 = V_10 -> V_8 ;
while ( V_11 -> V_18 ) {
if ( ( V_11 -> V_3 & 0xffff ) == V_3 ) {
* V_4 = F_7 ( V_10 ) ;
* V_6 = V_11 ;
return 0 ;
}
V_11 ++ ;
}
}
V_12 &= ~ ( 1ULL << V_15 ) ;
}
return - V_19 ;
}
int
F_8 ( struct V_1 * V_2 , T_3 * V_20 , int V_21 )
{
struct V_7 * V_8 ;
struct V_9 * V_10 ;
struct V_5 * V_11 ;
int V_22 = - 1 , V_15 ;
T_2 V_12 ;
V_8 = F_2 ( V_2 ) -> V_8 ;
while ( V_8 ) {
if ( ++ V_22 < V_21 )
V_20 [ V_22 ] = V_8 -> V_11 -> V_3 & 0xffff ;
V_8 = V_8 -> V_8 ;
}
V_12 = F_2 ( V_2 ) -> V_10 ;
while ( V_15 = F_3 ( V_12 ) , V_12 ) {
V_10 = V_9 ( V_2 , V_15 ) ;
if ( V_10 && ( V_11 = V_10 -> V_8 ) ) {
while ( V_11 -> V_18 ) {
if ( ++ V_22 < V_21 )
V_20 [ V_22 ] = V_11 -> V_3 & 0xffff ;
V_11 ++ ;
}
}
V_12 &= ~ ( 1ULL << V_15 ) ;
}
return V_22 + 1 ;
}
int
F_9 ( struct V_1 * V_2 , struct V_1 * V_10 ,
struct V_5 * V_11 , T_3 V_23 ,
struct V_5 * V_8 , T_2 V_24 ,
int V_21 , void * * V_25 )
{
struct V_26 * V_14 ;
struct V_7 * V_27 ;
int V_28 ;
V_28 = F_10 ( V_2 , V_10 , V_11 , V_23 |
V_29 , V_21 , V_25 ) ;
V_14 = * V_25 ;
if ( V_28 )
return V_28 ;
while ( V_8 && V_8 -> V_18 ) {
V_27 = F_11 ( sizeof( * V_27 ) , V_30 ) ;
if ( ! V_27 )
return - V_31 ;
V_27 -> V_8 = V_14 -> V_8 ;
V_14 -> V_8 = V_27 ;
V_27 -> V_10 = V_10 ? F_5 ( V_10 ) : NULL ;
V_27 -> V_11 = V_8 ;
V_8 ++ ;
}
V_14 -> V_10 = V_24 ;
return 0 ;
}
void
F_12 ( struct V_26 * V_2 )
{
struct V_7 * V_8 ;
while ( ( V_8 = V_2 -> V_8 ) ) {
V_2 -> V_8 = V_8 -> V_8 ;
F_13 ( V_8 ) ;
}
F_14 ( & V_2 -> V_14 ) ;
}
void
F_15 ( struct V_1 * V_14 )
{
F_12 ( F_2 ( V_14 ) ) ;
}
