static void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
V_2 -> type = F_2 ( V_4 -> type ) ;
V_2 -> V_5 = F_2 ( V_4 -> V_5 ) ;
V_2 -> V_6 = F_2 ( V_4 -> V_6 ) ;
V_2 -> V_7 = F_2 ( V_4 -> V_7 ) ;
V_2 -> V_8 = F_2 ( V_4 -> V_8 ) ;
}
static struct V_9 * F_3 ( T_1 type , T_1 V_10 , T_1 V_11 )
{
struct V_9 * V_12 = F_4 ( V_13 + V_10 ) ;
struct V_14 * V_15 ;
if ( V_12 != NULL ) {
V_15 = F_5 ( V_12 ) ;
F_6 ( V_15 , V_16 , type , V_13 , V_11 ) ;
F_7 ( V_15 , V_13 + V_10 ) ;
}
return V_12 ;
}
void F_8 ( struct V_9 * V_12 )
{
struct V_9 * V_17 ;
struct V_18 * V_19 ;
struct V_20 * V_21 ;
F_9 () ;
F_10 (n_ptr, &tipc_node_list, list) {
F_11 ( V_19 ) ;
V_21 = V_19 -> V_22 [ V_19 -> V_23 & 1 ] ;
if ( V_21 ) {
V_17 = F_12 ( V_12 , V_24 ) ;
if ( ! V_17 ) {
F_13 ( V_19 ) ;
break;
}
F_14 ( F_5 ( V_17 ) , V_19 -> V_23 ) ;
F_15 ( V_21 , V_17 ) ;
}
F_13 ( V_19 ) ;
}
F_16 () ;
F_17 ( V_12 ) ;
}
struct V_9 * F_18 ( struct V_3 * V_25 )
{
struct V_9 * V_12 ;
struct V_1 * V_26 ;
F_19 ( & V_25 -> V_27 , & V_28 [ V_25 -> V_29 ] -> V_30 ) ;
V_28 [ V_25 -> V_29 ] -> V_10 ++ ;
if ( V_25 -> V_29 == V_31 )
return NULL ;
V_12 = F_3 ( V_32 , V_33 , 0 ) ;
if ( ! V_12 ) {
F_20 ( L_1 ) ;
return NULL ;
}
V_26 = (struct V_1 * ) F_21 ( F_5 ( V_12 ) ) ;
F_1 ( V_26 , V_25 ) ;
return V_12 ;
}
struct V_9 * F_22 ( struct V_3 * V_25 )
{
struct V_9 * V_12 ;
struct V_1 * V_26 ;
F_23 ( & V_25 -> V_27 ) ;
V_28 [ V_25 -> V_29 ] -> V_10 -- ;
if ( V_25 -> V_29 == V_31 )
return NULL ;
V_12 = F_3 ( V_34 , V_33 , 0 ) ;
if ( ! V_12 ) {
F_20 ( L_2 ) ;
return NULL ;
}
V_26 = (struct V_1 * ) F_21 ( F_5 ( V_12 ) ) ;
F_1 ( V_26 , V_25 ) ;
return V_12 ;
}
static void F_24 ( struct V_35 * V_36 , T_1 V_37 ,
struct V_38 * V_39 , T_1 V_40 )
{
struct V_3 * V_25 ;
struct V_9 * V_12 = NULL ;
struct V_1 * V_26 = NULL ;
T_1 V_41 = 0 ;
T_1 V_42 = V_39 -> V_10 * V_33 ;
F_25 (publ, &pls->list, local_list) {
if ( ! V_12 ) {
V_41 = ( V_42 <= V_40 ) ? V_42 : V_40 ;
V_42 -= V_41 ;
V_12 = F_3 ( V_32 , V_41 , V_37 ) ;
if ( ! V_12 ) {
F_20 ( L_3 ) ;
return;
}
V_26 = (struct V_1 * ) F_21 ( F_5 ( V_12 ) ) ;
}
F_1 ( V_26 , V_25 ) ;
V_26 ++ ;
V_41 -= V_33 ;
if ( ! V_41 ) {
F_19 ( (struct V_35 * ) V_12 , V_36 ) ;
V_12 = NULL ;
}
}
}
void F_26 ( T_1 V_40 , T_1 V_37 )
{
F_27 ( V_36 ) ;
F_28 ( & V_43 ) ;
F_24 ( & V_36 , V_37 , & V_44 , V_40 ) ;
F_24 ( & V_36 , V_37 , & V_45 , V_40 ) ;
F_29 ( & V_43 ) ;
F_30 ( & V_36 , V_37 ) ;
}
static void F_31 ( struct V_3 * V_25 )
{
struct V_3 * V_4 ;
F_32 ( & V_43 ) ;
V_4 = F_33 ( V_25 -> type , V_25 -> V_5 ,
V_25 -> V_37 , V_25 -> V_7 , V_25 -> V_8 ) ;
if ( V_4 )
F_34 ( & V_4 -> V_46 ) ;
F_35 ( & V_43 ) ;
if ( V_4 != V_25 ) {
F_36 ( L_4
L_5 ,
V_25 -> type , V_25 -> V_5 , V_25 -> V_37 , V_25 -> V_7 ,
V_25 -> V_8 ) ;
}
F_37 ( V_4 ) ;
}
void F_38 ( struct V_9 * V_12 )
{
struct V_3 * V_25 ;
struct V_14 * V_15 = F_5 ( V_12 ) ;
struct V_1 * V_26 = (struct V_1 * ) F_21 ( V_15 ) ;
T_1 V_47 = F_39 ( V_15 ) / V_33 ;
F_32 ( & V_43 ) ;
while ( V_47 -- ) {
if ( F_40 ( V_15 ) == V_32 ) {
V_25 = F_41 ( F_42 ( V_26 -> type ) ,
F_42 ( V_26 -> V_5 ) ,
F_42 ( V_26 -> V_6 ) ,
V_48 ,
F_43 ( V_15 ) ,
F_42 ( V_26 -> V_7 ) ,
F_42 ( V_26 -> V_8 ) ) ;
if ( V_25 ) {
F_44 ( & V_25 -> V_46 ,
F_43 ( V_15 ) ,
V_25 ,
( V_49 )
F_31 ) ;
}
} else if ( F_40 ( V_15 ) == V_34 ) {
V_25 = F_33 ( F_42 ( V_26 -> type ) ,
F_42 ( V_26 -> V_5 ) ,
F_43 ( V_15 ) ,
F_42 ( V_26 -> V_7 ) ,
F_42 ( V_26 -> V_8 ) ) ;
if ( V_25 ) {
F_34 ( & V_25 -> V_46 ) ;
F_37 ( V_25 ) ;
} else {
F_36 ( L_6
L_7 ,
F_43 ( V_15 ) , F_42 ( V_26 -> type ) ,
F_42 ( V_26 -> V_5 ) , F_42 ( V_26 -> V_7 ) ,
F_42 ( V_26 -> V_8 ) ) ;
}
} else {
F_20 ( L_8 ) ;
}
V_26 ++ ;
}
F_35 ( & V_43 ) ;
F_17 ( V_12 ) ;
}
void F_45 ( void )
{
struct V_3 * V_25 ;
int V_29 ;
F_32 ( & V_43 ) ;
for ( V_29 = V_50 ; V_29 <= V_31 ; V_29 ++ )
F_25 (publ, &publ_lists[scope]->list, local_list)
V_25 -> V_37 = V_51 ;
F_35 ( & V_43 ) ;
}
