int F_1 ( struct V_1 * V_2 , unsigned V_3 ,
struct V_4 * * V_5 )
{
T_1 V_6 = sizeof( struct V_4 ) ;
if ( V_3 == 0 )
return - V_7 ;
V_6 += sizeof( struct V_8 ) * V_3 ;
* V_5 = F_2 ( V_6 , V_9 ) ;
if ( ! * V_5 )
return - V_10 ;
( * V_5 ) -> V_2 = V_2 ;
( * V_5 ) -> V_11 = ( void * ) & ( * V_5 ) [ 1 ] ;
( * V_5 ) -> V_3 = V_3 ;
F_3 ( & ( * V_5 ) -> V_12 ) ;
return 0 ;
}
int F_4 ( struct V_1 * V_2 , unsigned V_6 ,
struct V_4 * * V_5 )
{
int V_13 ;
V_13 = F_1 ( V_2 , 1 , V_5 ) ;
if ( V_13 )
return V_13 ;
V_13 = F_5 ( V_2 , NULL , V_6 , & ( * V_5 ) -> V_11 [ 0 ] ) ;
if ( V_13 )
F_6 ( * V_5 ) ;
return V_13 ;
}
void F_7 ( struct V_4 * V_5 )
{
unsigned V_14 ;
struct V_15 * V_16 ;
V_16 = ( V_5 -> V_17 . V_18 ) ? & V_5 -> V_17 . V_18 -> V_17 : V_5 -> V_15 ;
for ( V_14 = 0 ; V_14 < V_5 -> V_3 ; ++ V_14 )
F_8 ( V_5 -> V_2 , & V_5 -> V_11 [ V_14 ] . V_19 , V_16 ) ;
F_9 ( V_5 -> V_15 ) ;
F_10 ( & V_5 -> V_20 . V_21 ) ;
F_11 ( & V_5 -> V_12 ) ;
F_6 ( V_5 ) ;
}
int F_12 ( struct V_4 * V_5 , struct V_22 * V_23 ,
struct V_24 * V_25 , void * V_26 ,
struct V_15 * * V_16 )
{
V_5 -> V_23 = V_23 ;
V_5 -> V_17 . V_27 = & V_23 -> V_27 ;
V_5 -> V_17 . V_28 = V_25 ;
V_5 -> V_17 . V_18 = F_13 ( V_5 -> V_17 . V_28 , V_26 ) ;
if ( ! V_5 -> V_17 . V_18 )
return - V_10 ;
* V_16 = F_14 ( & V_5 -> V_17 . V_18 -> V_17 ) ;
V_5 -> V_26 = V_26 ;
F_15 ( & V_5 -> V_17 ) ;
return 0 ;
}
static struct V_15 * F_16 ( struct V_29 * V_30 )
{
struct V_4 * V_5 = F_17 ( V_30 ) ;
struct V_31 * V_32 = V_5 -> V_11 -> V_32 ;
struct V_15 * V_15 = F_18 ( & V_5 -> V_12 ) ;
if ( V_15 == NULL && V_32 && ! V_5 -> V_11 -> V_33 ) {
struct V_22 * V_23 = V_5 -> V_23 ;
unsigned V_14 , V_33 ;
T_2 V_34 ;
int V_13 ;
V_13 = F_19 ( V_32 , V_23 , & V_5 -> V_12 ,
& V_5 -> V_17 . V_18 -> V_17 ,
& V_33 , & V_34 ) ;
if ( V_13 )
F_20 ( L_1 , V_13 ) ;
else {
for ( V_14 = 0 ; V_14 < V_5 -> V_3 ; ++ V_14 ) {
V_5 -> V_11 [ V_14 ] . V_33 = V_33 ;
V_5 -> V_11 [ V_14 ] . V_34 = V_34 ;
}
}
V_15 = F_18 ( & V_5 -> V_12 ) ;
}
return V_15 ;
}
static struct V_15 * F_21 ( struct V_29 * V_30 )
{
struct V_15 * V_15 = NULL ;
struct V_4 * V_5 ;
int V_13 ;
if ( ! V_30 ) {
F_20 ( L_2 ) ;
return NULL ;
}
V_5 = F_17 ( V_30 ) ;
V_13 = F_22 ( & V_5 -> V_12 ) ;
if ( V_13 ) {
F_20 ( L_3 , V_13 ) ;
return NULL ;
}
F_23 ( V_5 ) ;
V_13 = F_24 ( V_5 -> V_23 , V_5 -> V_3 , V_5 -> V_11 ,
V_5 -> V_12 . V_35 , & V_15 ) ;
if ( V_13 ) {
F_20 ( L_4 , V_13 ) ;
goto V_36;
}
V_36:
V_5 -> V_15 = V_15 ;
F_7 ( V_5 ) ;
return V_15 ;
}
