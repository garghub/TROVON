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
struct V_20 * V_21 ;
F_9 () ;
F_10 (n_ptr, &tipc_node_list, list) {
F_11 ( & V_19 -> V_22 ) ;
V_21 = V_19 -> V_23 [ V_19 -> V_24 & 1 ] ;
if ( V_21 ) {
V_17 = F_12 ( V_12 , V_25 ) ;
if ( ! V_17 ) {
F_13 ( & V_19 -> V_22 ) ;
break;
}
F_14 ( F_5 ( V_17 ) , V_19 -> V_24 ) ;
F_15 ( V_21 , V_17 ) ;
}
F_13 ( & V_19 -> V_22 ) ;
}
F_16 () ;
F_17 ( V_12 ) ;
}
void F_18 ( struct V_3 * V_26 )
{
struct V_9 * V_12 ;
struct V_1 * V_27 ;
F_19 ( & V_26 -> V_28 , & V_29 [ V_26 -> V_30 ] -> V_31 ) ;
V_29 [ V_26 -> V_30 ] -> V_10 ++ ;
if ( V_26 -> V_30 == V_32 )
return;
V_12 = F_3 ( V_33 , V_34 , 0 ) ;
if ( ! V_12 ) {
F_20 ( L_1 ) ;
return;
}
V_27 = (struct V_1 * ) F_21 ( F_5 ( V_12 ) ) ;
F_1 ( V_27 , V_26 ) ;
F_8 ( V_12 ) ;
}
void F_22 ( struct V_3 * V_26 )
{
struct V_9 * V_12 ;
struct V_1 * V_27 ;
F_23 ( & V_26 -> V_28 ) ;
V_29 [ V_26 -> V_30 ] -> V_10 -- ;
if ( V_26 -> V_30 == V_32 )
return;
V_12 = F_3 ( V_35 , V_34 , 0 ) ;
if ( ! V_12 ) {
F_20 ( L_2 ) ;
return;
}
V_27 = (struct V_1 * ) F_21 ( F_5 ( V_12 ) ) ;
F_1 ( V_27 , V_26 ) ;
F_8 ( V_12 ) ;
}
static void F_24 ( struct V_36 * V_37 , T_1 V_38 ,
struct V_39 * V_40 , T_1 V_41 )
{
struct V_3 * V_26 ;
struct V_9 * V_12 = NULL ;
struct V_1 * V_27 = NULL ;
T_1 V_42 = 0 ;
T_1 V_43 = V_40 -> V_10 * V_34 ;
F_25 (publ, &pls->list, local_list) {
if ( ! V_12 ) {
V_42 = ( V_43 <= V_41 ) ? V_43 : V_41 ;
V_43 -= V_42 ;
V_12 = F_3 ( V_33 , V_42 , V_38 ) ;
if ( ! V_12 ) {
F_20 ( L_3 ) ;
return;
}
V_27 = (struct V_1 * ) F_21 ( F_5 ( V_12 ) ) ;
}
F_1 ( V_27 , V_26 ) ;
V_27 ++ ;
V_42 -= V_34 ;
if ( ! V_42 ) {
F_19 ( (struct V_36 * ) V_12 , V_37 ) ;
V_12 = NULL ;
}
}
}
void F_26 ( unsigned long V_44 )
{
struct V_18 * V_19 ;
struct V_20 * V_21 ;
struct V_36 V_37 ;
T_1 V_38 = ( T_1 ) V_44 ;
T_1 V_41 = 0 ;
F_27 ( & V_45 ) ;
V_19 = F_28 ( V_38 ) ;
if ( V_19 ) {
F_29 ( V_19 ) ;
V_21 = V_19 -> V_23 [ 0 ] ;
if ( V_21 )
V_41 = ( ( V_21 -> V_46 - V_13 ) /
V_34 ) * V_34 ;
F_30 ( V_19 ) ;
}
F_31 ( & V_45 ) ;
if ( ! V_41 )
return;
F_32 ( & V_37 ) ;
F_27 ( & V_47 ) ;
F_24 ( & V_37 , V_38 , & V_48 , V_41 ) ;
F_24 ( & V_37 , V_38 , & V_49 , V_41 ) ;
F_31 ( & V_47 ) ;
F_33 ( & V_37 , V_38 ) ;
}
static void F_34 ( struct V_3 * V_26 )
{
struct V_3 * V_4 ;
F_35 ( & V_47 ) ;
V_4 = F_36 ( V_26 -> type , V_26 -> V_5 ,
V_26 -> V_38 , V_26 -> V_7 , V_26 -> V_8 ) ;
if ( V_4 )
F_37 ( & V_4 -> V_50 ) ;
F_38 ( & V_47 ) ;
if ( V_4 != V_26 ) {
F_39 ( L_4
L_5 ,
V_26 -> type , V_26 -> V_5 , V_26 -> V_38 , V_26 -> V_7 ,
V_26 -> V_8 ) ;
}
F_40 ( V_4 ) ;
}
void F_41 ( struct V_9 * V_12 )
{
struct V_3 * V_26 ;
struct V_14 * V_15 = F_5 ( V_12 ) ;
struct V_1 * V_27 = (struct V_1 * ) F_21 ( V_15 ) ;
T_1 V_51 = F_42 ( V_15 ) / V_34 ;
F_35 ( & V_47 ) ;
while ( V_51 -- ) {
if ( F_43 ( V_15 ) == V_33 ) {
V_26 = F_44 ( F_45 ( V_27 -> type ) ,
F_45 ( V_27 -> V_5 ) ,
F_45 ( V_27 -> V_6 ) ,
V_52 ,
F_46 ( V_15 ) ,
F_45 ( V_27 -> V_7 ) ,
F_45 ( V_27 -> V_8 ) ) ;
if ( V_26 ) {
F_47 ( & V_26 -> V_50 ,
F_46 ( V_15 ) ,
V_26 ,
( V_53 )
F_34 ) ;
}
} else if ( F_43 ( V_15 ) == V_35 ) {
V_26 = F_36 ( F_45 ( V_27 -> type ) ,
F_45 ( V_27 -> V_5 ) ,
F_46 ( V_15 ) ,
F_45 ( V_27 -> V_7 ) ,
F_45 ( V_27 -> V_8 ) ) ;
if ( V_26 ) {
F_37 ( & V_26 -> V_50 ) ;
F_40 ( V_26 ) ;
} else {
F_39 ( L_6
L_7 ,
F_46 ( V_15 ) , F_45 ( V_27 -> type ) ,
F_45 ( V_27 -> V_5 ) , F_45 ( V_27 -> V_7 ) ,
F_45 ( V_27 -> V_8 ) ) ;
}
} else {
F_20 ( L_8 ) ;
}
V_27 ++ ;
}
F_38 ( & V_47 ) ;
F_17 ( V_12 ) ;
}
void F_48 ( void )
{
struct V_3 * V_26 ;
int V_30 ;
F_35 ( & V_47 ) ;
for ( V_30 = V_54 ; V_30 <= V_32 ; V_30 ++ )
F_25 (publ, &publ_lists[scope]->list, local_list)
V_26 -> V_38 = V_55 ;
F_38 ( & V_47 ) ;
}
