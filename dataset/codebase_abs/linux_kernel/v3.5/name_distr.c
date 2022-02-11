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
static void F_8 ( struct V_9 * V_12 )
{
struct V_9 * V_17 ;
struct V_18 * V_19 ;
F_9 (n_ptr, &tipc_node_list, list) {
if ( F_10 ( V_19 ) ) {
V_17 = F_11 ( V_12 , V_20 ) ;
if ( ! V_17 )
break;
F_12 ( F_5 ( V_17 ) , V_19 -> V_21 ) ;
F_13 ( V_17 , V_19 -> V_21 , V_19 -> V_21 ) ;
}
}
F_14 ( V_12 ) ;
}
void F_15 ( struct V_3 * V_22 )
{
struct V_9 * V_12 ;
struct V_1 * V_23 ;
F_16 ( & V_22 -> V_24 , & V_25 [ V_22 -> V_26 ] -> V_27 ) ;
V_25 [ V_22 -> V_26 ] -> V_10 ++ ;
if ( V_22 -> V_26 == V_28 )
return;
V_12 = F_3 ( V_29 , V_30 , 0 ) ;
if ( ! V_12 ) {
F_17 ( L_1 ) ;
return;
}
V_23 = (struct V_1 * ) F_18 ( F_5 ( V_12 ) ) ;
F_1 ( V_23 , V_22 ) ;
F_8 ( V_12 ) ;
}
void F_19 ( struct V_3 * V_22 )
{
struct V_9 * V_12 ;
struct V_1 * V_23 ;
F_20 ( & V_22 -> V_24 ) ;
V_25 [ V_22 -> V_26 ] -> V_10 -- ;
if ( V_22 -> V_26 == V_28 )
return;
V_12 = F_3 ( V_31 , V_30 , 0 ) ;
if ( ! V_12 ) {
F_17 ( L_2 ) ;
return;
}
V_23 = (struct V_1 * ) F_18 ( F_5 ( V_12 ) ) ;
F_1 ( V_23 , V_22 ) ;
F_8 ( V_12 ) ;
}
static void F_21 ( struct V_32 * V_33 , T_1 V_34 ,
struct V_35 * V_36 , T_1 V_37 )
{
struct V_3 * V_22 ;
struct V_9 * V_12 = NULL ;
struct V_1 * V_23 = NULL ;
T_1 V_38 = 0 ;
T_1 V_39 = V_36 -> V_10 * V_30 ;
F_9 (publ, &pls->list, local_list) {
if ( ! V_12 ) {
V_38 = ( V_39 <= V_37 ) ? V_39 : V_37 ;
V_39 -= V_38 ;
V_12 = F_3 ( V_29 , V_38 , V_34 ) ;
if ( ! V_12 ) {
F_17 ( L_3 ) ;
return;
}
V_23 = (struct V_1 * ) F_18 ( F_5 ( V_12 ) ) ;
}
F_1 ( V_23 , V_22 ) ;
V_23 ++ ;
V_38 -= V_30 ;
if ( ! V_38 ) {
F_16 ( (struct V_32 * ) V_12 , V_33 ) ;
V_12 = NULL ;
}
}
}
void F_22 ( unsigned long V_40 )
{
struct V_18 * V_19 ;
struct V_41 * V_42 ;
struct V_32 V_33 ;
T_1 V_34 = ( T_1 ) V_40 ;
T_1 V_37 = 0 ;
F_23 ( & V_43 ) ;
V_19 = F_24 ( V_34 ) ;
if ( V_19 ) {
F_25 ( V_19 ) ;
V_42 = V_19 -> V_44 [ 0 ] ;
if ( V_42 )
V_37 = ( ( V_42 -> V_45 - V_13 ) /
V_30 ) * V_30 ;
F_26 ( V_19 ) ;
}
F_27 ( & V_43 ) ;
if ( ! V_37 )
return;
F_28 ( & V_33 ) ;
F_23 ( & V_46 ) ;
F_21 ( & V_33 , V_34 , & V_47 , V_37 ) ;
F_21 ( & V_33 , V_34 , & V_48 , V_37 ) ;
F_27 ( & V_46 ) ;
F_29 ( & V_33 , ( T_1 ) V_34 ) ;
}
static void F_30 ( struct V_3 * V_22 )
{
struct V_3 * V_4 ;
F_31 ( & V_46 ) ;
V_4 = F_32 ( V_22 -> type , V_22 -> V_5 ,
V_22 -> V_34 , V_22 -> V_7 , V_22 -> V_8 ) ;
if ( V_4 )
F_33 ( & V_4 -> V_49 ) ;
F_34 ( & V_46 ) ;
if ( V_4 != V_22 ) {
F_35 ( L_4
L_5 ,
V_22 -> type , V_22 -> V_5 , V_22 -> V_34 , V_22 -> V_7 , V_22 -> V_8 ) ;
}
F_36 ( V_4 ) ;
}
void F_37 ( struct V_9 * V_12 )
{
struct V_3 * V_22 ;
struct V_14 * V_15 = F_5 ( V_12 ) ;
struct V_1 * V_23 = (struct V_1 * ) F_18 ( V_15 ) ;
T_1 V_50 = F_38 ( V_15 ) / V_30 ;
F_31 ( & V_46 ) ;
while ( V_50 -- ) {
if ( F_39 ( V_15 ) == V_29 ) {
V_22 = F_40 ( F_41 ( V_23 -> type ) ,
F_41 ( V_23 -> V_5 ) ,
F_41 ( V_23 -> V_6 ) ,
V_51 ,
F_42 ( V_15 ) ,
F_41 ( V_23 -> V_7 ) ,
F_41 ( V_23 -> V_8 ) ) ;
if ( V_22 ) {
F_43 ( & V_22 -> V_49 ,
F_42 ( V_15 ) ,
V_22 ,
( V_52 )
F_30 ) ;
}
} else if ( F_39 ( V_15 ) == V_31 ) {
V_22 = F_32 ( F_41 ( V_23 -> type ) ,
F_41 ( V_23 -> V_5 ) ,
F_42 ( V_15 ) ,
F_41 ( V_23 -> V_7 ) ,
F_41 ( V_23 -> V_8 ) ) ;
if ( V_22 ) {
F_33 ( & V_22 -> V_49 ) ;
F_36 ( V_22 ) ;
} else {
F_35 ( L_6
L_7 ,
F_42 ( V_15 ) ,
F_41 ( V_23 -> type ) , F_41 ( V_23 -> V_5 ) ,
F_41 ( V_23 -> V_7 ) , F_41 ( V_23 -> V_8 ) ) ;
}
} else {
F_17 ( L_8 ) ;
}
V_23 ++ ;
}
F_34 ( & V_46 ) ;
F_14 ( V_12 ) ;
}
void F_44 ( void )
{
struct V_3 * V_22 ;
int V_26 ;
F_31 ( & V_46 ) ;
for ( V_26 = V_53 ; V_26 <= V_28 ; V_26 ++ )
F_9 (publ, &publ_lists[scope]->list, local_list)
V_22 -> V_34 = V_54 ;
F_34 ( & V_46 ) ;
}
