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
int V_13 = F_3 ( V_12 ) - 1 ;
if ( ( V_10 = V_9 ( V_2 , V_13 ) ) ) {
V_11 = V_10 -> V_8 ;
while ( V_11 -> V_14 ) {
if ( ( V_11 -> V_3 & 0xffff ) == V_3 ) {
* V_4 = F_4 ( V_10 ) ;
* V_6 = V_11 ;
return 0 ;
}
V_11 ++ ;
}
}
V_12 &= ~ ( 1ULL << V_13 ) ;
}
return - V_15 ;
}
int
F_5 ( struct V_1 * V_2 ,
struct V_1 * V_10 ,
struct V_5 * V_11 , T_3 V_16 ,
struct V_5 * V_8 , T_2 V_17 ,
int V_18 , void * * V_19 )
{
struct V_20 * V_21 ;
struct V_7 * V_22 ;
int V_23 ;
V_23 = F_6 ( V_2 , V_10 , V_11 , V_16 |
V_24 , V_18 , V_19 ) ;
V_21 = * V_19 ;
if ( V_23 )
return V_23 ;
while ( V_8 && V_8 -> V_14 ) {
V_22 = F_7 ( sizeof( * V_22 ) , V_25 ) ;
if ( ! V_22 )
return - V_26 ;
V_22 -> V_8 = V_21 -> V_8 ;
V_21 -> V_8 = V_22 ;
V_22 -> V_10 = V_10 ? F_8 ( V_10 ) : NULL ;
V_22 -> V_11 = V_8 ;
V_8 ++ ;
}
V_21 -> V_10 = V_17 ;
return 0 ;
}
void
F_9 ( struct V_20 * V_2 )
{
struct V_7 * V_8 ;
while ( ( V_8 = V_2 -> V_8 ) ) {
V_2 -> V_8 = V_8 -> V_8 ;
F_10 ( V_8 ) ;
}
F_11 ( & V_2 -> V_27 ) ;
}
void
F_12 ( struct V_1 * V_21 )
{
F_9 ( F_2 ( V_21 ) ) ;
}
