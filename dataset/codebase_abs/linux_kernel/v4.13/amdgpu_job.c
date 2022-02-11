static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 , struct V_3 , V_5 ) ;
F_3 ( L_1 ,
V_4 -> V_5 . V_6 -> V_7 ,
F_4 ( & V_4 -> V_8 -> V_9 . V_10 ) ,
V_4 -> V_8 -> V_9 . V_11 ) ;
if ( F_5 ( V_4 -> V_12 ) )
F_6 ( V_4 -> V_12 , V_4 ) ;
else
F_7 ( V_4 -> V_12 ) ;
}
int F_8 ( struct V_13 * V_12 , unsigned V_14 ,
struct V_3 * * V_4 , struct V_15 * V_16 )
{
T_1 V_17 = sizeof( struct V_3 ) ;
if ( V_14 == 0 )
return - V_18 ;
V_17 += sizeof( struct V_19 ) * V_14 ;
* V_4 = F_9 ( V_17 , V_20 ) ;
if ( ! * V_4 )
return - V_21 ;
( * V_4 ) -> V_12 = V_12 ;
( * V_4 ) -> V_16 = V_16 ;
( * V_4 ) -> V_22 = ( void * ) & ( * V_4 ) [ 1 ] ;
( * V_4 ) -> V_14 = V_14 ;
F_10 ( & ( * V_4 ) -> V_23 ) ;
F_10 ( & ( * V_4 ) -> V_24 ) ;
F_10 ( & ( * V_4 ) -> V_25 ) ;
return 0 ;
}
int F_11 ( struct V_13 * V_12 , unsigned V_17 ,
struct V_3 * * V_4 )
{
int V_26 ;
V_26 = F_8 ( V_12 , 1 , V_4 , NULL ) ;
if ( V_26 )
return V_26 ;
V_26 = F_12 ( V_12 , NULL , V_17 , & ( * V_4 ) -> V_22 [ 0 ] ) ;
if ( V_26 )
F_13 ( * V_4 ) ;
return V_26 ;
}
void F_14 ( struct V_3 * V_4 )
{
struct V_27 * V_28 ;
unsigned V_29 ;
V_28 = V_4 -> V_5 . V_30 ? & V_4 -> V_5 . V_30 -> V_31 : V_4 -> V_32 ;
for ( V_29 = 0 ; V_29 < V_4 -> V_14 ; ++ V_29 )
F_15 ( V_4 -> V_12 , & V_4 -> V_22 [ V_29 ] , V_28 ) ;
}
static void F_16 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 , struct V_3 , V_5 ) ;
F_17 ( V_4 -> V_32 ) ;
F_18 ( & V_4 -> V_23 ) ;
F_18 ( & V_4 -> V_24 ) ;
F_18 ( & V_4 -> V_25 ) ;
F_13 ( V_4 ) ;
}
void F_19 ( struct V_3 * V_4 )
{
F_14 ( V_4 ) ;
F_17 ( V_4 -> V_32 ) ;
F_18 ( & V_4 -> V_23 ) ;
F_18 ( & V_4 -> V_24 ) ;
F_18 ( & V_4 -> V_25 ) ;
F_13 ( V_4 ) ;
}
int F_20 ( struct V_3 * V_4 , struct V_33 * V_8 ,
struct V_34 * V_35 , void * V_36 ,
struct V_27 * * V_28 )
{
int V_26 ;
V_4 -> V_8 = V_8 ;
if ( ! V_28 )
return - V_18 ;
V_26 = F_21 ( & V_4 -> V_5 , & V_8 -> V_6 , V_35 , V_36 ) ;
if ( V_26 )
return V_26 ;
V_4 -> V_36 = V_36 ;
V_4 -> V_37 = V_35 -> V_38 ;
* V_28 = F_22 ( & V_4 -> V_5 . V_30 -> V_31 ) ;
F_14 ( V_4 ) ;
F_23 ( & V_4 -> V_5 ) ;
return 0 ;
}
static struct V_27 * F_24 ( struct V_1 * V_39 )
{
struct V_3 * V_4 = F_25 ( V_39 ) ;
struct V_15 * V_16 = V_4 -> V_16 ;
struct V_27 * V_32 = F_26 ( & V_4 -> V_24 ) ;
int V_26 ;
if ( F_27 ( V_32 , V_39 -> V_40 ) ) {
V_26 = F_28 ( V_4 -> V_12 , & V_4 -> V_25 , V_32 ) ;
if ( V_26 )
F_3 ( L_2 , V_26 ) ;
}
if ( ! V_32 )
V_32 = F_26 ( & V_4 -> V_23 ) ;
while ( V_32 == NULL && V_16 && ! V_4 -> V_41 ) {
struct V_33 * V_8 = V_4 -> V_8 ;
V_26 = F_29 ( V_16 , V_8 , & V_4 -> V_23 ,
& V_4 -> V_5 . V_30 -> V_31 ,
V_4 ) ;
if ( V_26 )
F_3 ( L_3 , V_26 ) ;
V_32 = F_26 ( & V_4 -> V_23 ) ;
}
return V_32 ;
}
static struct V_27 * F_30 ( struct V_1 * V_39 )
{
struct V_27 * V_32 = NULL ;
struct V_3 * V_4 ;
struct V_42 * V_43 = NULL ;
int V_26 ;
if ( ! V_39 ) {
F_3 ( L_4 ) ;
return NULL ;
}
V_4 = F_25 ( V_39 ) ;
F_31 ( F_32 ( & V_4 -> V_23 , NULL ) ) ;
F_33 ( V_4 ) ;
if ( V_4 -> V_16 )
V_43 = F_2 ( V_4 -> V_16 , struct V_42 , V_16 ) ;
if ( V_43 && F_34 ( V_4 -> V_12 , V_43 ) )
F_3 ( L_5 ) ;
else {
V_26 = F_35 ( V_4 -> V_8 , V_4 -> V_14 , V_4 -> V_22 , V_4 , & V_32 ) ;
if ( V_26 )
F_3 ( L_6 , V_26 ) ;
}
F_17 ( V_4 -> V_32 ) ;
V_4 -> V_32 = F_22 ( V_32 ) ;
F_14 ( V_4 ) ;
return V_32 ;
}
