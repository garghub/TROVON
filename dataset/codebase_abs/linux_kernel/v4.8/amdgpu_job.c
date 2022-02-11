static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 , struct V_3 , V_5 ) ;
F_3 ( L_1 ,
V_4 -> V_5 . V_6 -> V_7 ,
F_4 ( & V_4 -> V_8 -> V_9 . V_10 ) ,
V_4 -> V_8 -> V_9 . V_11 ) ;
F_5 ( V_4 -> V_12 ) ;
}
int F_6 ( struct V_13 * V_12 , unsigned V_14 ,
struct V_3 * * V_4 , struct V_15 * V_16 )
{
T_1 V_17 = sizeof( struct V_3 ) ;
if ( V_14 == 0 )
return - V_18 ;
V_17 += sizeof( struct V_19 ) * V_14 ;
* V_4 = F_7 ( V_17 , V_20 ) ;
if ( ! * V_4 )
return - V_21 ;
( * V_4 ) -> V_12 = V_12 ;
( * V_4 ) -> V_16 = V_16 ;
( * V_4 ) -> V_22 = ( void * ) & ( * V_4 ) [ 1 ] ;
( * V_4 ) -> V_14 = V_14 ;
F_8 ( & ( * V_4 ) -> V_23 ) ;
return 0 ;
}
int F_9 ( struct V_13 * V_12 , unsigned V_17 ,
struct V_3 * * V_4 )
{
int V_24 ;
V_24 = F_6 ( V_12 , 1 , V_4 , NULL ) ;
if ( V_24 )
return V_24 ;
V_24 = F_10 ( V_12 , NULL , V_17 , & ( * V_4 ) -> V_22 [ 0 ] ) ;
if ( V_24 )
F_11 ( * V_4 ) ;
return V_24 ;
}
void F_12 ( struct V_3 * V_4 )
{
struct V_25 * V_26 ;
unsigned V_27 ;
V_26 = V_4 -> V_5 . V_28 ? & V_4 -> V_5 . V_28 -> V_29 : V_4 -> V_25 ;
for ( V_27 = 0 ; V_27 < V_4 -> V_14 ; ++ V_27 )
F_13 ( V_4 -> V_12 , & V_4 -> V_22 [ V_27 ] , V_26 ) ;
}
void F_14 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 , struct V_3 , V_5 ) ;
F_15 ( V_4 -> V_25 ) ;
F_16 ( & V_4 -> V_23 ) ;
F_11 ( V_4 ) ;
}
void F_17 ( struct V_3 * V_4 )
{
F_12 ( V_4 ) ;
F_15 ( V_4 -> V_25 ) ;
F_16 ( & V_4 -> V_23 ) ;
F_11 ( V_4 ) ;
}
int F_18 ( struct V_3 * V_4 , struct V_30 * V_8 ,
struct V_31 * V_32 , void * V_33 ,
struct V_25 * * V_26 )
{
int V_24 ;
V_4 -> V_8 = V_8 ;
if ( ! V_26 )
return - V_18 ;
V_24 = F_19 ( & V_4 -> V_5 , & V_8 -> V_6 , V_32 , V_33 ) ;
if ( V_24 )
return V_24 ;
V_4 -> V_33 = V_33 ;
V_4 -> V_34 = V_32 -> V_35 ;
* V_26 = F_20 ( & V_4 -> V_5 . V_28 -> V_29 ) ;
F_12 ( V_4 ) ;
F_21 ( & V_4 -> V_5 ) ;
return 0 ;
}
static struct V_25 * F_22 ( struct V_1 * V_36 )
{
struct V_3 * V_4 = F_23 ( V_36 ) ;
struct V_15 * V_16 = V_4 -> V_16 ;
struct V_25 * V_25 = F_24 ( & V_4 -> V_23 ) ;
if ( V_25 == NULL && V_16 && ! V_4 -> V_37 ) {
struct V_30 * V_8 = V_4 -> V_8 ;
int V_24 ;
V_24 = F_25 ( V_16 , V_8 , & V_4 -> V_23 ,
& V_4 -> V_5 . V_28 -> V_29 ,
V_4 ) ;
if ( V_24 )
F_3 ( L_2 , V_24 ) ;
V_25 = F_24 ( & V_4 -> V_23 ) ;
}
return V_25 ;
}
static struct V_25 * F_26 ( struct V_1 * V_36 )
{
struct V_25 * V_25 = NULL ;
struct V_3 * V_4 ;
int V_24 ;
if ( ! V_36 ) {
F_3 ( L_3 ) ;
return NULL ;
}
V_4 = F_23 ( V_36 ) ;
F_27 ( F_28 ( & V_4 -> V_23 , NULL ) ) ;
F_29 ( V_4 ) ;
V_24 = F_30 ( V_4 -> V_8 , V_4 -> V_14 , V_4 -> V_22 ,
V_4 -> V_23 . V_38 , V_4 , & V_25 ) ;
if ( V_24 )
F_3 ( L_4 , V_24 ) ;
F_15 ( V_4 -> V_25 ) ;
V_4 -> V_25 = F_20 ( V_25 ) ;
F_12 ( V_4 ) ;
return V_25 ;
}
