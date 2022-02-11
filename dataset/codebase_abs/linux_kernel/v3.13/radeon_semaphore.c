int F_1 ( struct V_1 * V_2 ,
struct V_3 * * V_4 )
{
int V_5 , V_6 ;
* V_4 = F_2 ( sizeof( struct V_3 ) , V_7 ) ;
if ( * V_4 == NULL ) {
return - V_8 ;
}
V_6 = F_3 ( V_2 , & V_2 -> V_9 ,
& ( * V_4 ) -> V_10 , 8 , 8 , true ) ;
if ( V_6 ) {
F_4 ( * V_4 ) ;
* V_4 = NULL ;
return V_6 ;
}
( * V_4 ) -> V_11 = 0 ;
( * V_4 ) -> V_12 = F_5 ( ( * V_4 ) -> V_10 ) ;
* ( ( V_13 * ) F_6 ( ( * V_4 ) -> V_10 ) ) = 0 ;
for ( V_5 = 0 ; V_5 < V_14 ; ++ V_5 )
( * V_4 ) -> V_15 [ V_5 ] = NULL ;
return 0 ;
}
bool F_7 ( struct V_1 * V_2 , int V_16 ,
struct V_3 * V_4 )
{
struct V_17 * V_18 = & V_2 -> V_18 [ V_16 ] ;
F_8 ( V_16 , V_4 ) ;
if ( F_9 ( V_2 , V_16 , V_18 , V_4 , false ) ) {
-- V_4 -> V_11 ;
V_18 -> V_19 = V_4 -> V_12 ;
return true ;
}
return false ;
}
bool F_10 ( struct V_1 * V_2 , int V_16 ,
struct V_3 * V_4 )
{
struct V_17 * V_18 = & V_2 -> V_18 [ V_16 ] ;
F_11 ( V_16 , V_4 ) ;
if ( F_9 ( V_2 , V_16 , V_18 , V_4 , true ) ) {
++ V_4 -> V_11 ;
V_18 -> V_20 = V_4 -> V_12 ;
return true ;
}
return false ;
}
void F_12 ( struct V_3 * V_4 ,
struct V_21 * V_22 )
{
struct V_21 * V_23 ;
if ( ! V_22 )
return;
V_23 = V_4 -> V_15 [ V_22 -> V_18 ] ;
V_4 -> V_15 [ V_22 -> V_18 ] = F_13 ( V_22 , V_23 ) ;
}
int F_14 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
int V_18 )
{
int V_5 , V_6 ;
for ( V_5 = 0 ; V_5 < V_14 ; ++ V_5 ) {
struct V_21 * V_22 = V_4 -> V_15 [ V_5 ] ;
if ( ! F_15 ( V_22 , V_18 ) )
continue;
if ( ! V_2 -> V_18 [ V_5 ] . V_24 ) {
F_16 ( V_2 -> V_25 , L_1 ) ;
return - V_26 ;
}
V_6 = F_17 ( V_2 , & V_2 -> V_18 [ V_5 ] , 16 ) ;
if ( V_6 ) {
return V_6 ;
}
if ( ! F_7 ( V_2 , V_5 , V_4 ) ) {
F_18 ( & V_2 -> V_18 [ V_5 ] ) ;
F_19 ( V_22 ) ;
continue;
}
if ( ! F_10 ( V_2 , V_18 , V_4 ) ) {
F_18 ( & V_2 -> V_18 [ V_5 ] ) ;
F_19 ( V_22 ) ;
continue;
}
F_20 ( V_2 , & V_2 -> V_18 [ V_5 ] ) ;
F_21 ( V_22 , V_18 ) ;
}
return 0 ;
}
void F_22 ( struct V_1 * V_2 ,
struct V_3 * * V_4 ,
struct V_21 * V_22 )
{
if ( V_4 == NULL || * V_4 == NULL ) {
return;
}
if ( ( * V_4 ) -> V_11 > 0 ) {
F_16 ( V_2 -> V_25 , L_2
L_3 , * V_4 ) ;
}
F_23 ( V_2 , & ( * V_4 ) -> V_10 , V_22 ) ;
F_4 ( * V_4 ) ;
* V_4 = NULL ;
}
