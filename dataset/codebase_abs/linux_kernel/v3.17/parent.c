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
* V_4 = V_2 -> V_10 ;
* V_6 = V_8 -> V_11 ;
return 0 ;
}
V_8 = V_8 -> V_8 ;
}
V_12 = F_2 ( V_2 ) -> V_10 ;
while ( V_12 ) {
int V_13 = F_3 ( V_12 ) ;
if ( F_4 ( V_2 , V_14 ) )
V_10 = F_5 ( F_6 ( V_2 ) -> V_15 ) ;
else
V_10 = V_9 ( V_2 , V_13 ) ;
if ( V_10 ) {
V_11 = V_10 -> V_8 ;
while ( V_11 -> V_16 ) {
if ( ( V_11 -> V_3 & 0xffff ) == V_3 ) {
* V_4 = F_7 ( V_10 ) ;
* V_6 = V_11 ;
return 0 ;
}
V_11 ++ ;
}
}
V_12 &= ~ ( 1ULL << V_13 ) ;
}
return - V_17 ;
}
int
F_8 ( struct V_1 * V_2 , T_3 * V_18 , int V_19 )
{
struct V_7 * V_8 ;
struct V_9 * V_10 ;
struct V_5 * V_11 ;
int V_20 = - 1 , V_13 ;
T_2 V_12 ;
V_8 = F_2 ( V_2 ) -> V_8 ;
while ( V_8 ) {
if ( ++ V_20 < V_19 )
V_18 [ V_20 ] = V_8 -> V_11 -> V_3 & 0xffff ;
V_8 = V_8 -> V_8 ;
}
V_12 = F_2 ( V_2 ) -> V_10 ;
while ( V_13 = F_3 ( V_12 ) , V_12 ) {
V_10 = V_9 ( V_2 , V_13 ) ;
if ( V_10 && ( V_11 = V_10 -> V_8 ) ) {
while ( V_11 -> V_16 ) {
if ( ++ V_20 < V_19 )
V_18 [ V_20 ] = V_11 -> V_3 & 0xffff ;
V_11 ++ ;
}
}
V_12 &= ~ ( 1ULL << V_13 ) ;
}
return V_20 + 1 ;
}
int
F_9 ( struct V_1 * V_2 ,
struct V_1 * V_10 ,
struct V_5 * V_11 , T_3 V_21 ,
struct V_5 * V_8 , T_2 V_22 ,
int V_19 , void * * V_23 )
{
struct V_24 * V_25 ;
struct V_7 * V_26 ;
int V_27 ;
V_27 = F_10 ( V_2 , V_10 , V_11 , V_21 |
V_28 , V_19 , V_23 ) ;
V_25 = * V_23 ;
if ( V_27 )
return V_27 ;
while ( V_8 && V_8 -> V_16 ) {
V_26 = F_11 ( sizeof( * V_26 ) , V_29 ) ;
if ( ! V_26 )
return - V_30 ;
V_26 -> V_8 = V_25 -> V_8 ;
V_25 -> V_8 = V_26 ;
V_26 -> V_10 = V_10 ? F_5 ( V_10 ) : NULL ;
V_26 -> V_11 = V_8 ;
V_8 ++ ;
}
V_25 -> V_10 = V_22 ;
return 0 ;
}
void
F_12 ( struct V_24 * V_2 )
{
struct V_7 * V_8 ;
while ( ( V_8 = V_2 -> V_8 ) ) {
V_2 -> V_8 = V_8 -> V_8 ;
F_13 ( V_8 ) ;
}
F_14 ( & V_2 -> V_31 ) ;
}
void
F_15 ( struct V_1 * V_25 )
{
F_12 ( F_2 ( V_25 ) ) ;
}
