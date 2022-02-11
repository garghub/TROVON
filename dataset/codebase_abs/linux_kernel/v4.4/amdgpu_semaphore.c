int F_1 ( struct V_1 * V_2 ,
struct V_3 * * V_4 )
{
int V_5 ;
* V_4 = F_2 ( sizeof( struct V_3 ) , V_6 ) ;
if ( * V_4 == NULL ) {
return - V_7 ;
}
V_5 = F_3 ( & V_2 -> V_8 ,
& ( * V_4 ) -> V_9 , 8 , 8 ) ;
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
bool F_7 ( struct V_13 * V_14 ,
struct V_3 * V_4 )
{
F_8 ( V_14 -> V_15 , V_4 ) ;
if ( F_9 ( V_14 , V_4 , false ) ) {
-- V_4 -> V_10 ;
V_14 -> V_16 = V_4 -> V_11 ;
return true ;
}
return false ;
}
bool F_10 ( struct V_13 * V_14 ,
struct V_3 * V_4 )
{
F_11 ( V_14 -> V_15 , V_4 ) ;
if ( F_9 ( V_14 , V_4 , true ) ) {
++ V_4 -> V_10 ;
V_14 -> V_17 = V_4 -> V_11 ;
return true ;
}
return false ;
}
void F_12 ( struct V_1 * V_2 ,
struct V_3 * * V_4 ,
struct V_18 * V_18 )
{
if ( V_4 == NULL || * V_4 == NULL ) {
return;
}
if ( ( * V_4 ) -> V_10 > 0 ) {
F_13 ( V_2 -> V_19 , L_1
L_2 , * V_4 ) ;
}
F_14 ( V_2 , & ( * V_4 ) -> V_9 , V_18 ) ;
F_4 ( * V_4 ) ;
* V_4 = NULL ;
}
