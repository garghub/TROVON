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
( * V_4 ) -> V_23 = false ;
F_8 ( & ( * V_4 ) -> V_24 ) ;
return 0 ;
}
int F_9 ( struct V_13 * V_12 , unsigned V_17 ,
struct V_3 * * V_4 )
{
int V_25 ;
V_25 = F_6 ( V_12 , 1 , V_4 , NULL ) ;
if ( V_25 )
return V_25 ;
V_25 = F_10 ( V_12 , NULL , V_17 , & ( * V_4 ) -> V_22 [ 0 ] ) ;
if ( V_25 )
F_11 ( * V_4 ) ;
return V_25 ;
}
void F_12 ( struct V_3 * V_4 )
{
struct V_26 * V_27 ;
unsigned V_28 ;
V_27 = V_4 -> V_5 . V_29 ? & V_4 -> V_5 . V_29 -> V_30 : V_4 -> V_31 ;
for ( V_28 = 0 ; V_28 < V_4 -> V_14 ; ++ V_28 )
F_13 ( V_4 -> V_12 , & V_4 -> V_22 [ V_28 ] , V_27 ) ;
}
static void F_14 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 , struct V_3 , V_5 ) ;
F_15 ( V_4 -> V_31 ) ;
F_16 ( & V_4 -> V_24 ) ;
F_11 ( V_4 ) ;
}
void F_17 ( struct V_3 * V_4 )
{
F_12 ( V_4 ) ;
F_15 ( V_4 -> V_31 ) ;
F_16 ( & V_4 -> V_24 ) ;
F_11 ( V_4 ) ;
}
int F_18 ( struct V_3 * V_4 , struct V_32 * V_8 ,
struct V_33 * V_34 , void * V_35 ,
struct V_26 * * V_27 )
{
int V_25 ;
V_4 -> V_8 = V_8 ;
if ( ! V_27 )
return - V_18 ;
V_25 = F_19 ( & V_4 -> V_5 , & V_8 -> V_6 , V_34 , V_35 ) ;
if ( V_25 )
return V_25 ;
V_4 -> V_35 = V_35 ;
V_4 -> V_36 = V_34 -> V_37 ;
* V_27 = F_20 ( & V_4 -> V_5 . V_29 -> V_30 ) ;
F_12 ( V_4 ) ;
F_21 ( & V_4 -> V_5 ) ;
return 0 ;
}
static struct V_26 * F_22 ( struct V_1 * V_38 )
{
struct V_3 * V_4 = F_23 ( V_38 ) ;
struct V_15 * V_16 = V_4 -> V_16 ;
struct V_26 * V_31 = F_24 ( & V_4 -> V_24 ) ;
while ( V_31 == NULL && V_16 && ! V_4 -> V_39 ) {
struct V_32 * V_8 = V_4 -> V_8 ;
int V_25 ;
V_25 = F_25 ( V_16 , V_8 , & V_4 -> V_24 ,
& V_4 -> V_5 . V_29 -> V_30 ,
V_4 ) ;
if ( V_25 )
F_3 ( L_2 , V_25 ) ;
V_31 = F_24 ( & V_4 -> V_24 ) ;
}
if ( F_26 ( V_31 , V_38 -> V_40 ) )
V_4 -> V_23 = true ;
return V_31 ;
}
static struct V_26 * F_27 ( struct V_1 * V_38 )
{
struct V_26 * V_31 = NULL ;
struct V_3 * V_4 ;
int V_25 ;
if ( ! V_38 ) {
F_3 ( L_3 ) ;
return NULL ;
}
V_4 = F_23 ( V_38 ) ;
F_28 ( F_29 ( & V_4 -> V_24 , NULL ) ) ;
F_30 ( V_4 ) ;
V_25 = F_31 ( V_4 -> V_8 , V_4 -> V_14 , V_4 -> V_22 , V_4 , & V_31 ) ;
if ( V_25 )
F_3 ( L_4 , V_25 ) ;
F_15 ( V_4 -> V_31 ) ;
V_4 -> V_31 = F_20 ( V_31 ) ;
F_12 ( V_4 ) ;
return V_31 ;
}
