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
F_8 ( struct V_1 * V_2 ,
struct V_1 * V_10 ,
struct V_5 * V_11 , T_3 V_18 ,
struct V_5 * V_8 , T_2 V_19 ,
int V_20 , void * * V_21 )
{
struct V_22 * V_23 ;
struct V_7 * V_24 ;
int V_25 ;
V_25 = F_9 ( V_2 , V_10 , V_11 , V_18 |
V_26 , V_20 , V_21 ) ;
V_23 = * V_21 ;
if ( V_25 )
return V_25 ;
while ( V_8 && V_8 -> V_16 ) {
V_24 = F_10 ( sizeof( * V_24 ) , V_27 ) ;
if ( ! V_24 )
return - V_28 ;
V_24 -> V_8 = V_23 -> V_8 ;
V_23 -> V_8 = V_24 ;
V_24 -> V_10 = V_10 ? F_5 ( V_10 ) : NULL ;
V_24 -> V_11 = V_8 ;
V_8 ++ ;
}
V_23 -> V_10 = V_19 ;
return 0 ;
}
void
F_11 ( struct V_22 * V_2 )
{
struct V_7 * V_8 ;
while ( ( V_8 = V_2 -> V_8 ) ) {
V_2 -> V_8 = V_8 -> V_8 ;
F_12 ( V_8 ) ;
}
F_13 ( & V_2 -> V_29 ) ;
}
void
F_14 ( struct V_1 * V_23 )
{
F_11 ( F_2 ( V_23 ) ) ;
}
