int F_1 ( struct V_1 * V_2 ,
struct V_3 * * V_4 )
{
int V_5 ;
* V_4 = F_2 ( sizeof( struct V_3 ) , V_6 ) ;
if ( * V_4 == NULL ) {
return - V_7 ;
}
V_5 = F_3 ( V_2 , & V_2 -> V_8 ,
& ( * V_4 ) -> V_9 , 8 , 8 , true ) ;
if ( V_5 ) {
F_4 ( * V_4 ) ;
* V_4 = NULL ;
return V_5 ;
}
( * V_4 ) -> V_10 = 0 ;
( * V_4 ) -> V_11 = F_5 ( ( * V_4 ) -> V_9 ) ;
* ( ( V_12 * ) F_6 ( ( * V_4 ) -> V_9 ) ) = 0 ;
return 0 ;
}
void F_7 ( struct V_1 * V_2 , int V_13 ,
struct V_3 * V_4 )
{
-- V_4 -> V_10 ;
F_8 ( V_2 , V_13 , & V_2 -> V_13 [ V_13 ] , V_4 , false ) ;
}
void F_9 ( struct V_1 * V_2 , int V_13 ,
struct V_3 * V_4 )
{
++ V_4 -> V_10 ;
F_8 ( V_2 , V_13 , & V_2 -> V_13 [ V_13 ] , V_4 , true ) ;
}
int F_10 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
int V_14 , int V_15 )
{
int V_5 ;
if ( V_14 == V_15 ) {
return 0 ;
}
if ( ! V_2 -> V_13 [ V_14 ] . V_16 ) {
F_11 ( V_2 -> V_17 , L_1 ) ;
return - V_18 ;
}
V_5 = F_12 ( V_2 , & V_2 -> V_13 [ V_14 ] , 8 ) ;
if ( V_5 ) {
return V_5 ;
}
F_7 ( V_2 , V_14 , V_4 ) ;
F_13 ( V_2 , & V_2 -> V_13 [ V_14 ] ) ;
F_9 ( V_2 , V_15 , V_4 ) ;
V_2 -> V_13 [ V_14 ] . V_19 = V_4 -> V_11 ;
V_2 -> V_13 [ V_15 ] . V_20 = V_4 -> V_11 ;
return 0 ;
}
void F_14 ( struct V_1 * V_2 ,
struct V_3 * * V_4 ,
struct V_21 * V_22 )
{
if ( V_4 == NULL || * V_4 == NULL ) {
return;
}
if ( ( * V_4 ) -> V_10 > 0 ) {
F_11 ( V_2 -> V_17 , L_2
L_3 , * V_4 ) ;
}
F_15 ( V_2 , & ( * V_4 ) -> V_9 , V_22 ) ;
F_4 ( * V_4 ) ;
* V_4 = NULL ;
}
