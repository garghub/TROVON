static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 , struct V_3 , V_5 . V_6 ) ;
F_3 ( & V_4 -> V_5 ) ;
}
void F_4 ( struct V_1 * V_7 )
{
struct V_3 * V_4 = F_2 ( V_7 , struct V_3 , V_5 . V_8 . V_7 ) ;
F_5 ( L_1 ,
V_4 -> V_5 . V_9 -> V_10 ,
( V_11 ) F_6 ( & V_4 -> V_12 -> V_13 . V_14 ) ,
V_4 -> V_12 -> V_13 . V_15 ) ;
F_3 ( & V_4 -> V_5 ) ;
}
int F_7 ( struct V_16 * V_17 , unsigned V_18 ,
struct V_3 * * V_4 , struct V_19 * V_20 )
{
T_1 V_21 = sizeof( struct V_3 ) ;
if ( V_18 == 0 )
return - V_22 ;
V_21 += sizeof( struct V_23 ) * V_18 ;
* V_4 = F_8 ( V_21 , V_24 ) ;
if ( ! * V_4 )
return - V_25 ;
( * V_4 ) -> V_17 = V_17 ;
( * V_4 ) -> V_20 = V_20 ;
( * V_4 ) -> V_26 = ( void * ) & ( * V_4 ) [ 1 ] ;
( * V_4 ) -> V_18 = V_18 ;
F_9 ( & ( * V_4 ) -> V_5 . V_6 , F_1 ) ;
F_10 ( & ( * V_4 ) -> V_27 ) ;
return 0 ;
}
int F_11 ( struct V_16 * V_17 , unsigned V_21 ,
struct V_3 * * V_4 )
{
int V_28 ;
V_28 = F_7 ( V_17 , 1 , V_4 , NULL ) ;
if ( V_28 )
return V_28 ;
V_28 = F_12 ( V_17 , NULL , V_21 , & ( * V_4 ) -> V_26 [ 0 ] ) ;
if ( V_28 )
F_13 ( * V_4 ) ;
return V_28 ;
}
void F_14 ( struct V_3 * V_4 )
{
unsigned V_29 ;
struct V_30 * V_31 ;
V_31 = ( V_4 -> V_5 . V_32 ) ? & V_4 -> V_5 . V_32 -> V_5 : V_4 -> V_30 ;
for ( V_29 = 0 ; V_29 < V_4 -> V_18 ; ++ V_29 )
F_15 ( V_4 -> V_17 , & V_4 -> V_26 [ V_29 ] . V_33 , V_31 ) ;
F_16 ( V_4 -> V_30 ) ;
F_17 ( & V_4 -> V_34 ) ;
F_18 ( & V_4 -> V_27 ) ;
if ( ! V_4 -> V_5 . V_35 )
F_13 ( V_4 ) ;
}
void F_19 ( struct V_36 * V_37 )
{
struct V_3 * V_4 = F_2 ( V_37 , struct V_3 , V_5 . V_37 ) ;
F_13 ( V_4 ) ;
}
int F_20 ( struct V_3 * V_4 , struct V_38 * V_12 ,
struct V_39 * V_40 , void * V_41 ,
struct V_30 * * V_31 )
{
struct V_30 * V_30 ;
int V_28 ;
V_4 -> V_12 = V_12 ;
if ( ! V_31 )
return - V_22 ;
V_28 = F_21 ( & V_4 -> V_5 , & V_12 -> V_9 ,
V_40 , F_4 ,
F_19 , V_41 , & V_30 ) ;
if ( V_28 )
return V_28 ;
V_4 -> V_41 = V_41 ;
V_4 -> V_42 = V_40 -> V_43 ;
* V_31 = F_22 ( V_30 ) ;
F_23 ( & V_4 -> V_5 ) ;
return 0 ;
}
static struct V_30 * F_24 ( struct V_44 * V_45 )
{
struct V_3 * V_4 = F_25 ( V_45 ) ;
struct V_19 * V_20 = V_4 -> V_20 ;
struct V_30 * V_30 = F_26 ( & V_4 -> V_27 ) ;
if ( V_30 == NULL && V_20 && ! V_4 -> V_46 ) {
struct V_38 * V_12 = V_4 -> V_12 ;
int V_28 ;
V_28 = F_27 ( V_20 , V_12 , & V_4 -> V_27 ,
& V_4 -> V_5 . V_32 -> V_5 ,
& V_4 -> V_46 , & V_4 -> V_47 ) ;
if ( V_28 )
F_5 ( L_2 , V_28 ) ;
V_30 = F_26 ( & V_4 -> V_27 ) ;
}
return V_30 ;
}
static struct V_30 * F_28 ( struct V_44 * V_45 )
{
struct V_30 * V_30 = NULL ;
struct V_3 * V_4 ;
int V_28 ;
if ( ! V_45 ) {
F_5 ( L_3 ) ;
return NULL ;
}
V_4 = F_25 ( V_45 ) ;
V_28 = F_29 ( & V_4 -> V_27 ) ;
if ( V_28 ) {
F_5 ( L_4 , V_28 ) ;
return NULL ;
}
F_30 ( V_4 ) ;
V_28 = F_31 ( V_4 -> V_12 , V_4 -> V_18 , V_4 -> V_26 ,
V_4 -> V_27 . V_48 , V_4 , & V_30 ) ;
if ( V_28 ) {
F_5 ( L_5 , V_28 ) ;
goto V_49;
}
V_49:
V_4 -> V_30 = V_30 ;
F_14 ( V_4 ) ;
return V_30 ;
}
