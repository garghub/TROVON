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
F_16 ( & V_22 -> V_24 , & V_25 ) ;
V_26 ++ ;
V_12 = F_3 ( V_27 , V_28 , 0 ) ;
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
V_26 -- ;
V_12 = F_3 ( V_29 , V_28 , 0 ) ;
if ( ! V_12 ) {
F_17 ( L_2 ) ;
return;
}
V_23 = (struct V_1 * ) F_18 ( F_5 ( V_12 ) ) ;
F_1 ( V_23 , V_22 ) ;
F_8 ( V_12 ) ;
}
void F_21 ( unsigned long V_30 )
{
struct V_18 * V_19 ;
struct V_31 * V_32 ;
struct V_3 * V_22 ;
struct V_1 * V_23 = NULL ;
struct V_9 * V_12 = NULL ;
struct V_33 V_34 ;
T_1 V_35 = ( T_1 ) V_30 ;
T_1 V_36 = 0 ;
T_1 V_37 ;
T_1 V_38 = 0 ;
F_22 ( & V_39 ) ;
V_19 = F_23 ( V_35 ) ;
if ( V_19 ) {
F_24 ( V_19 ) ;
V_32 = V_19 -> V_40 [ 0 ] ;
if ( V_32 )
V_38 = ( ( V_32 -> V_41 - V_13 ) /
V_28 ) * V_28 ;
F_25 ( V_19 ) ;
}
F_26 ( & V_39 ) ;
if ( ! V_38 )
return;
F_27 ( & V_34 ) ;
F_22 ( & V_42 ) ;
V_37 = V_26 * V_28 ;
F_9 (publ, &publ_root, local_list) {
if ( ! V_12 ) {
V_36 = ( V_37 <= V_38 ) ? V_37 : V_38 ;
V_37 -= V_36 ;
V_12 = F_3 ( V_27 , V_36 , V_35 ) ;
if ( ! V_12 ) {
F_17 ( L_3 ) ;
goto exit;
}
V_23 = (struct V_1 * ) F_18 ( F_5 ( V_12 ) ) ;
}
F_1 ( V_23 , V_22 ) ;
V_23 ++ ;
V_36 -= V_28 ;
if ( ! V_36 ) {
F_16 ( (struct V_33 * ) V_12 , & V_34 ) ;
V_12 = NULL ;
}
}
exit:
F_26 ( & V_42 ) ;
F_28 ( & V_34 , ( T_1 ) V_35 ) ;
}
static void F_29 ( struct V_3 * V_22 )
{
struct V_3 * V_4 ;
F_30 ( & V_42 ) ;
V_22 -> V_8 += 1222345 ;
V_4 = F_31 ( V_22 -> type , V_22 -> V_5 ,
V_22 -> V_35 , V_22 -> V_7 , V_22 -> V_8 ) ;
if ( V_4 )
F_32 ( & V_4 -> V_43 ) ;
F_33 ( & V_42 ) ;
if ( V_4 != V_22 ) {
F_34 ( L_4
L_5 ,
V_22 -> type , V_22 -> V_5 , V_22 -> V_35 , V_22 -> V_7 , V_22 -> V_8 ) ;
}
F_35 ( V_4 ) ;
}
void F_36 ( struct V_9 * V_12 )
{
struct V_3 * V_22 ;
struct V_14 * V_15 = F_5 ( V_12 ) ;
struct V_1 * V_23 = (struct V_1 * ) F_18 ( V_15 ) ;
T_1 V_44 = F_37 ( V_15 ) / V_28 ;
F_30 ( & V_42 ) ;
while ( V_44 -- ) {
if ( F_38 ( V_15 ) == V_27 ) {
V_22 = F_39 ( F_40 ( V_23 -> type ) ,
F_40 ( V_23 -> V_5 ) ,
F_40 ( V_23 -> V_6 ) ,
V_45 ,
F_41 ( V_15 ) ,
F_40 ( V_23 -> V_7 ) ,
F_40 ( V_23 -> V_8 ) ) ;
if ( V_22 ) {
F_42 ( & V_22 -> V_43 ,
F_41 ( V_15 ) ,
V_22 ,
( V_46 )
F_29 ) ;
}
} else if ( F_38 ( V_15 ) == V_29 ) {
V_22 = F_31 ( F_40 ( V_23 -> type ) ,
F_40 ( V_23 -> V_5 ) ,
F_41 ( V_15 ) ,
F_40 ( V_23 -> V_7 ) ,
F_40 ( V_23 -> V_8 ) ) ;
if ( V_22 ) {
F_32 ( & V_22 -> V_43 ) ;
F_35 ( V_22 ) ;
} else {
F_34 ( L_6
L_7 ,
F_41 ( V_15 ) ,
F_40 ( V_23 -> type ) , F_40 ( V_23 -> V_5 ) ,
F_40 ( V_23 -> V_7 ) , F_40 ( V_23 -> V_8 ) ) ;
}
} else {
F_17 ( L_8 ) ;
}
V_23 ++ ;
}
F_33 ( & V_42 ) ;
F_14 ( V_12 ) ;
}
void F_43 ( void )
{
struct V_3 * V_22 ;
F_30 ( & V_42 ) ;
F_9 (publ, &publ_root, local_list) {
if ( V_22 -> V_35 == V_47 )
break;
V_22 -> V_35 = V_47 ;
}
F_33 ( & V_42 ) ;
}
