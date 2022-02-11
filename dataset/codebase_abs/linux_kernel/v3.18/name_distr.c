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
T_1 V_20 ;
F_9 () ;
F_10 (node, &tipc_node_list, list) {
V_20 = V_19 -> V_21 ;
if ( F_11 ( V_20 ) )
continue;
if ( ! F_12 ( V_19 ) )
continue;
V_17 = F_13 ( V_12 , V_22 ) ;
if ( ! V_17 )
break;
F_14 ( F_5 ( V_17 ) , V_20 ) ;
F_15 ( V_17 , V_20 , V_20 ) ;
}
F_16 () ;
F_17 ( V_12 ) ;
}
struct V_9 * F_18 ( struct V_3 * V_23 )
{
struct V_9 * V_12 ;
struct V_1 * V_24 ;
F_19 ( & V_23 -> V_25 , & V_26 [ V_23 -> V_27 ] -> V_28 ) ;
V_26 [ V_23 -> V_27 ] -> V_10 ++ ;
if ( V_23 -> V_27 == V_29 )
return NULL ;
V_12 = F_3 ( V_30 , V_31 , 0 ) ;
if ( ! V_12 ) {
F_20 ( L_1 ) ;
return NULL ;
}
V_24 = (struct V_1 * ) F_21 ( F_5 ( V_12 ) ) ;
F_1 ( V_24 , V_23 ) ;
return V_12 ;
}
struct V_9 * F_22 ( struct V_3 * V_23 )
{
struct V_9 * V_12 ;
struct V_1 * V_24 ;
F_23 ( & V_23 -> V_25 ) ;
V_26 [ V_23 -> V_27 ] -> V_10 -- ;
if ( V_23 -> V_27 == V_29 )
return NULL ;
V_12 = F_3 ( V_32 , V_31 , 0 ) ;
if ( ! V_12 ) {
F_20 ( L_2 ) ;
return NULL ;
}
V_24 = (struct V_1 * ) F_21 ( F_5 ( V_12 ) ) ;
F_1 ( V_24 , V_23 ) ;
return V_12 ;
}
static void F_24 ( struct V_33 * V_34 , T_1 V_20 ,
struct V_35 * V_36 )
{
struct V_3 * V_23 ;
struct V_9 * V_12 = NULL ;
struct V_1 * V_24 = NULL ;
T_2 V_37 = V_36 -> V_10 * V_31 ;
T_2 V_38 = ( F_25 ( V_20 , 0 ) / V_31 ) * V_31 ;
T_2 V_39 = V_37 ;
T_2 V_40 = 0 ;
F_26 (publ, &pls->list, local_list) {
if ( ! V_12 ) {
V_40 = F_27 ( T_2 , V_39 , V_38 ) ;
V_39 -= V_40 ;
V_12 = F_3 ( V_30 , V_40 , V_20 ) ;
if ( ! V_12 ) {
F_20 ( L_3 ) ;
return;
}
V_24 = (struct V_1 * ) F_21 ( F_5 ( V_12 ) ) ;
}
F_1 ( V_24 , V_23 ) ;
V_24 ++ ;
V_40 -= V_31 ;
if ( ! V_40 ) {
F_19 ( (struct V_33 * ) V_12 , V_34 ) ;
V_12 = NULL ;
}
}
}
void F_28 ( T_1 V_20 )
{
F_29 ( V_34 ) ;
struct V_9 * V_41 ;
F_30 ( & V_42 ) ;
F_24 ( & V_34 , V_20 , & V_43 ) ;
F_24 ( & V_34 , V_20 , & V_44 ) ;
F_31 ( & V_42 ) ;
V_41 = (struct V_9 * ) V_34 . V_45 ;
( (struct V_9 * ) V_34 . V_46 ) -> V_45 = NULL ;
F_15 ( V_41 , V_20 , V_20 ) ;
}
static void F_32 ( struct V_3 * V_23 )
{
struct V_3 * V_4 ;
F_33 ( & V_42 ) ;
V_4 = F_34 ( V_23 -> type , V_23 -> V_5 ,
V_23 -> V_19 , V_23 -> V_7 , V_23 -> V_8 ) ;
if ( V_4 )
F_35 ( & V_4 -> V_47 ) ;
F_36 ( & V_42 ) ;
if ( V_4 != V_23 ) {
F_37 ( L_4
L_5 ,
V_23 -> type , V_23 -> V_5 , V_23 -> V_19 , V_23 -> V_7 ,
V_23 -> V_8 ) ;
}
F_38 ( V_4 ) ;
}
static bool F_39 ( struct V_1 * V_2 , T_1 V_19 , T_1 V_48 )
{
struct V_3 * V_23 = NULL ;
if ( V_48 == V_30 ) {
V_23 = F_40 ( F_41 ( V_2 -> type ) , F_41 ( V_2 -> V_5 ) ,
F_41 ( V_2 -> V_6 ) ,
V_49 , V_19 ,
F_41 ( V_2 -> V_7 ) , F_41 ( V_2 -> V_8 ) ) ;
if ( V_23 ) {
F_42 ( & V_23 -> V_47 , V_19 , V_23 ,
( V_50 )
F_32 ) ;
return true ;
}
} else if ( V_48 == V_32 ) {
V_23 = F_34 ( F_41 ( V_2 -> type ) , F_41 ( V_2 -> V_5 ) ,
V_19 , F_41 ( V_2 -> V_7 ) ,
F_41 ( V_2 -> V_8 ) ) ;
if ( V_23 ) {
F_35 ( & V_23 -> V_47 ) ;
F_38 ( V_23 ) ;
return true ;
}
} else {
F_20 ( L_6 ) ;
}
return false ;
}
static void F_43 ( struct V_1 * V_2 , T_1 type , T_1 V_19 )
{
struct V_51 * V_52 ;
unsigned long V_53 = F_44 () ;
V_52 = F_45 ( sizeof( * V_52 ) , V_22 ) ;
if ( ! V_52 )
return;
V_52 -> V_48 = type ;
V_52 -> V_19 = V_19 ;
V_52 -> V_54 = V_53 + F_46 ( V_55 ) ;
memcpy ( V_52 , V_2 , sizeof( * V_2 ) ) ;
F_19 ( & V_52 -> V_45 , & V_56 ) ;
}
void F_47 ( void )
{
struct V_51 * V_52 , * V_57 ;
char V_21 [ 16 ] ;
unsigned long V_53 = F_44 () ;
F_48 (e, tmp, &tipc_dist_queue, next) {
if ( F_49 ( V_52 -> V_54 , V_53 ) ) {
if ( ! F_39 ( & V_52 -> V_2 , V_52 -> V_19 , V_52 -> V_48 ) )
continue;
} else {
F_50 ( V_21 , V_52 -> V_19 ) ;
F_51 ( L_7 ,
V_52 -> V_48 , F_41 ( V_52 -> V_2 . type ) ,
F_41 ( V_52 -> V_2 . V_5 ) ,
F_41 ( V_52 -> V_2 . V_6 ) ,
V_21 , F_41 ( V_52 -> V_2 . V_8 ) ) ;
}
F_23 ( & V_52 -> V_45 ) ;
F_38 ( V_52 ) ;
}
}
void F_52 ( struct V_9 * V_12 )
{
struct V_14 * V_15 = F_5 ( V_12 ) ;
struct V_1 * V_24 = (struct V_1 * ) F_21 ( V_15 ) ;
T_1 V_58 = F_53 ( V_15 ) / V_31 ;
T_1 V_19 = F_54 ( V_15 ) ;
F_33 ( & V_42 ) ;
while ( V_58 -- ) {
if ( ! F_39 ( V_24 , V_19 , F_55 ( V_15 ) ) )
F_43 ( V_24 , F_55 ( V_15 ) , V_19 ) ;
V_24 ++ ;
}
F_47 () ;
F_36 ( & V_42 ) ;
F_17 ( V_12 ) ;
}
void F_56 ( void )
{
struct V_3 * V_23 ;
int V_27 ;
F_33 ( & V_42 ) ;
for ( V_27 = V_59 ; V_27 <= V_29 ; V_27 ++ )
F_26 (publ, &publ_lists[scope]->list, local_list)
V_23 -> V_19 = V_60 ;
F_36 ( & V_42 ) ;
}
