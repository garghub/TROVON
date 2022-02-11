int F_1 ( struct V_1 * V_2 ,
struct V_3 * * V_4 )
{
T_1 * V_5 ;
int V_6 , V_7 ;
* V_4 = F_2 ( sizeof( struct V_3 ) , V_8 ) ;
if ( * V_4 == NULL ) {
return - V_9 ;
}
V_7 = F_3 ( V_2 , & V_2 -> V_10 , & ( * V_4 ) -> V_11 ,
8 * V_12 , 8 ) ;
if ( V_7 ) {
F_4 ( * V_4 ) ;
* V_4 = NULL ;
return V_7 ;
}
( * V_4 ) -> V_13 = 0 ;
( * V_4 ) -> V_14 = F_5 ( ( * V_4 ) -> V_11 ) ;
V_5 = F_6 ( ( * V_4 ) -> V_11 ) ;
for ( V_6 = 0 ; V_6 < V_12 ; ++ V_6 )
V_5 [ V_6 ] = 0 ;
for ( V_6 = 0 ; V_6 < V_15 ; ++ V_6 )
( * V_4 ) -> V_16 [ V_6 ] = NULL ;
return 0 ;
}
bool F_7 ( struct V_1 * V_2 , int V_17 ,
struct V_3 * V_4 )
{
struct V_18 * V_19 = & V_2 -> V_19 [ V_17 ] ;
F_8 ( V_17 , V_4 ) ;
if ( F_9 ( V_2 , V_17 , V_19 , V_4 , false ) ) {
-- V_4 -> V_13 ;
V_19 -> V_20 = V_4 -> V_14 ;
return true ;
}
return false ;
}
bool F_10 ( struct V_1 * V_2 , int V_17 ,
struct V_3 * V_4 )
{
struct V_18 * V_19 = & V_2 -> V_19 [ V_17 ] ;
F_11 ( V_17 , V_4 ) ;
if ( F_9 ( V_2 , V_17 , V_19 , V_4 , true ) ) {
++ V_4 -> V_13 ;
V_19 -> V_21 = V_4 -> V_14 ;
return true ;
}
return false ;
}
void F_12 ( struct V_3 * V_4 ,
struct V_22 * V_23 )
{
struct V_22 * V_24 ;
if ( ! V_23 )
return;
V_24 = V_4 -> V_16 [ V_23 -> V_19 ] ;
V_4 -> V_16 [ V_23 -> V_19 ] = F_13 ( V_23 , V_24 ) ;
}
int F_14 ( struct V_1 * V_2 ,
struct V_3 * V_25 ,
struct V_26 * V_27 ,
bool V_28 )
{
struct V_29 * V_30 ;
struct V_23 * V_31 ;
struct V_22 * V_23 ;
unsigned V_6 ;
int V_7 = 0 ;
V_31 = F_15 ( V_27 ) ;
V_23 = V_31 ? F_16 ( V_31 ) : NULL ;
if ( V_23 && V_23 -> V_2 == V_2 )
F_12 ( V_25 , V_23 ) ;
else if ( V_31 )
V_7 = F_17 ( V_31 , true ) ;
V_30 = F_18 ( V_27 ) ;
if ( V_28 || ! V_30 || V_7 )
return V_7 ;
for ( V_6 = 0 ; V_6 < V_30 -> V_32 ; ++ V_6 ) {
V_31 = F_19 ( V_30 -> V_28 [ V_6 ] ,
F_20 ( V_27 ) ) ;
V_23 = F_16 ( V_31 ) ;
if ( V_23 && V_23 -> V_2 == V_2 )
F_12 ( V_25 , V_23 ) ;
else
V_7 = F_17 ( V_31 , true ) ;
if ( V_7 )
break;
}
return V_7 ;
}
int F_21 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
int V_19 )
{
unsigned V_33 = 0 ;
int V_6 , V_7 ;
for ( V_6 = 0 ; V_6 < V_15 ; ++ V_6 ) {
struct V_22 * V_23 = V_4 -> V_16 [ V_6 ] ;
if ( ! F_22 ( V_23 , V_19 ) )
continue;
if ( ! V_2 -> V_19 [ V_6 ] . V_34 ) {
F_23 ( V_2 -> V_35 , L_1 ) ;
return - V_36 ;
}
if ( ++ V_33 > V_12 ) {
V_7 = F_24 ( V_23 , false ) ;
if ( V_7 )
return V_7 ;
continue;
}
V_7 = F_25 ( V_2 , & V_2 -> V_19 [ V_6 ] , 16 ) ;
if ( V_7 ) {
return V_7 ;
}
if ( ! F_7 ( V_2 , V_6 , V_4 ) ) {
F_26 ( & V_2 -> V_19 [ V_6 ] ) ;
V_7 = F_24 ( V_23 , false ) ;
if ( V_7 )
return V_7 ;
continue;
}
if ( ! F_10 ( V_2 , V_19 , V_4 ) ) {
F_26 ( & V_2 -> V_19 [ V_6 ] ) ;
V_7 = F_24 ( V_23 , false ) ;
if ( V_7 )
return V_7 ;
continue;
}
F_27 ( V_2 , & V_2 -> V_19 [ V_6 ] , false ) ;
F_28 ( V_23 , V_19 ) ;
V_4 -> V_14 += 8 ;
}
return 0 ;
}
void F_29 ( struct V_1 * V_2 ,
struct V_3 * * V_4 ,
struct V_22 * V_23 )
{
if ( V_4 == NULL || * V_4 == NULL ) {
return;
}
if ( ( * V_4 ) -> V_13 > 0 ) {
F_23 ( V_2 -> V_35 , L_2
L_3 , * V_4 ) ;
}
F_30 ( V_2 , & ( * V_4 ) -> V_11 , V_23 ) ;
F_4 ( * V_4 ) ;
* V_4 = NULL ;
}
