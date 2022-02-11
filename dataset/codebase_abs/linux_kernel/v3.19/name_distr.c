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
void F_8 ( struct V_9 * V_17 )
{
struct V_9 * V_18 ;
struct V_19 * V_20 ;
T_1 V_21 ;
F_9 () ;
F_10 (node, &tipc_node_list, list) {
V_21 = V_20 -> V_22 ;
if ( F_11 ( V_21 ) )
continue;
if ( ! F_12 ( V_20 ) )
continue;
V_18 = F_13 ( V_17 , V_23 ) ;
if ( ! V_18 )
break;
F_14 ( F_5 ( V_18 ) , V_21 ) ;
F_15 ( V_18 , V_21 , V_21 ) ;
}
F_16 () ;
F_17 ( V_17 ) ;
}
struct V_9 * F_18 ( struct V_3 * V_24 )
{
struct V_9 * V_12 ;
struct V_1 * V_25 ;
F_19 ( & V_24 -> V_26 ,
& V_27 -> V_28 [ V_24 -> V_29 ] ) ;
if ( V_24 -> V_29 == V_30 )
return NULL ;
V_12 = F_3 ( V_31 , V_32 , 0 ) ;
if ( ! V_12 ) {
F_20 ( L_1 ) ;
return NULL ;
}
V_25 = (struct V_1 * ) F_21 ( F_5 ( V_12 ) ) ;
F_1 ( V_25 , V_24 ) ;
return V_12 ;
}
struct V_9 * F_22 ( struct V_3 * V_24 )
{
struct V_9 * V_12 ;
struct V_1 * V_25 ;
F_23 ( & V_24 -> V_26 ) ;
if ( V_24 -> V_29 == V_30 )
return NULL ;
V_12 = F_3 ( V_33 , V_32 , 0 ) ;
if ( ! V_12 ) {
F_20 ( L_2 ) ;
return NULL ;
}
V_25 = (struct V_1 * ) F_21 ( F_5 ( V_12 ) ) ;
F_1 ( V_25 , V_24 ) ;
return V_12 ;
}
static void F_24 ( struct V_34 * V_35 , T_1 V_21 ,
struct V_36 * V_37 )
{
struct V_3 * V_24 ;
struct V_9 * V_17 = NULL ;
struct V_1 * V_25 = NULL ;
T_2 V_38 = ( F_25 ( V_21 , 0 ) / V_32 ) * V_32 ;
T_2 V_39 = V_38 ;
F_26 (publ, pls, local_list) {
if ( ! V_17 ) {
V_17 = F_3 ( V_31 , V_39 , V_21 ) ;
if ( ! V_17 ) {
F_20 ( L_3 ) ;
return;
}
V_25 = (struct V_1 * ) F_21 ( F_5 ( V_17 ) ) ;
}
F_1 ( V_25 , V_24 ) ;
V_25 ++ ;
V_39 -= V_32 ;
if ( ! V_39 ) {
F_27 ( V_35 , V_17 ) ;
V_17 = NULL ;
V_39 = V_38 ;
}
}
if ( V_17 ) {
F_7 ( F_5 ( V_17 ) , V_13 + ( V_38 - V_39 ) ) ;
F_28 ( V_17 , V_13 + ( V_38 - V_39 ) ) ;
F_27 ( V_35 , V_17 ) ;
}
}
void F_29 ( T_1 V_21 )
{
struct V_34 V_40 ;
F_30 ( & V_40 ) ;
F_9 () ;
F_24 ( & V_40 , V_21 ,
& V_27 -> V_28 [ V_41 ] ) ;
F_24 ( & V_40 , V_21 ,
& V_27 -> V_28 [ V_42 ] ) ;
F_16 () ;
F_31 ( & V_40 , V_21 , V_21 ) ;
}
static void F_32 ( struct V_3 * V_24 , T_1 V_22 )
{
struct V_19 * V_20 ;
if ( F_11 ( V_22 ) )
return;
V_20 = F_33 ( V_22 ) ;
if ( ! V_20 ) {
F_20 ( L_4 ,
V_22 ) ;
return;
}
F_34 ( V_20 ) ;
F_35 ( & V_24 -> V_43 , & V_20 -> V_28 ) ;
F_36 ( V_20 ) ;
}
static void F_37 ( struct V_3 * V_24 , T_1 V_22 )
{
struct V_19 * V_20 ;
V_20 = F_33 ( V_22 ) ;
if ( ! V_20 )
return;
F_34 ( V_20 ) ;
F_38 ( & V_24 -> V_43 ) ;
F_36 ( V_20 ) ;
}
static void F_39 ( struct V_3 * V_24 , T_1 V_22 )
{
struct V_3 * V_4 ;
F_40 ( & V_44 ) ;
V_4 = F_41 ( V_24 -> type , V_24 -> V_5 ,
V_24 -> V_20 , V_24 -> V_7 , V_24 -> V_8 ) ;
if ( V_4 )
F_37 ( V_4 , V_22 ) ;
F_42 ( & V_44 ) ;
if ( V_4 != V_24 ) {
F_43 ( L_5
L_6 ,
V_24 -> type , V_24 -> V_5 , V_24 -> V_20 , V_24 -> V_7 ,
V_24 -> V_8 ) ;
}
F_44 ( V_4 , V_45 ) ;
}
void F_45 ( struct V_36 * V_46 , T_1 V_22 )
{
struct V_3 * V_24 , * V_47 ;
F_46 (publ, tmp, nsub_list, nodesub_list)
F_39 ( V_24 , V_22 ) ;
}
static bool F_47 ( struct V_1 * V_2 , T_1 V_20 , T_1 V_48 )
{
struct V_3 * V_24 = NULL ;
if ( V_48 == V_31 ) {
V_24 = F_48 ( F_49 ( V_2 -> type ) , F_49 ( V_2 -> V_5 ) ,
F_49 ( V_2 -> V_6 ) ,
V_41 , V_20 ,
F_49 ( V_2 -> V_7 ) , F_49 ( V_2 -> V_8 ) ) ;
if ( V_24 ) {
F_32 ( V_24 , V_20 ) ;
return true ;
}
} else if ( V_48 == V_33 ) {
V_24 = F_41 ( F_49 ( V_2 -> type ) , F_49 ( V_2 -> V_5 ) ,
V_20 , F_49 ( V_2 -> V_7 ) ,
F_49 ( V_2 -> V_8 ) ) ;
if ( V_24 ) {
F_37 ( V_24 , V_20 ) ;
F_44 ( V_24 , V_45 ) ;
return true ;
}
} else {
F_20 ( L_7 ) ;
}
return false ;
}
static void F_50 ( struct V_1 * V_2 , T_1 type , T_1 V_20 )
{
struct V_49 * V_50 ;
unsigned long V_51 = F_51 () ;
V_50 = F_52 ( sizeof( * V_50 ) , V_23 ) ;
if ( ! V_50 )
return;
V_50 -> V_48 = type ;
V_50 -> V_20 = V_20 ;
V_50 -> V_52 = V_51 + F_53 ( V_53 ) ;
memcpy ( V_50 , V_2 , sizeof( * V_2 ) ) ;
F_35 ( & V_50 -> V_54 , & V_55 ) ;
}
void F_54 ( void )
{
struct V_49 * V_50 , * V_47 ;
char V_22 [ 16 ] ;
unsigned long V_51 = F_51 () ;
F_46 (e, tmp, &tipc_dist_queue, next) {
if ( F_55 ( V_50 -> V_52 , V_51 ) ) {
if ( ! F_47 ( & V_50 -> V_2 , V_50 -> V_20 , V_50 -> V_48 ) )
continue;
} else {
F_56 ( V_22 , V_50 -> V_20 ) ;
F_57 ( L_8 ,
V_50 -> V_48 , F_49 ( V_50 -> V_2 . type ) ,
F_49 ( V_50 -> V_2 . V_5 ) ,
F_49 ( V_50 -> V_2 . V_6 ) ,
V_22 , F_49 ( V_50 -> V_2 . V_8 ) ) ;
}
F_23 ( & V_50 -> V_54 ) ;
F_58 ( V_50 ) ;
}
}
void F_59 ( struct V_9 * V_12 )
{
struct V_14 * V_15 = F_5 ( V_12 ) ;
struct V_1 * V_25 = (struct V_1 * ) F_21 ( V_15 ) ;
T_1 V_56 = F_60 ( V_15 ) / V_32 ;
T_1 V_20 = F_61 ( V_15 ) ;
F_40 ( & V_44 ) ;
while ( V_56 -- ) {
if ( ! F_47 ( V_25 , V_20 , F_62 ( V_15 ) ) )
F_50 ( V_25 , F_62 ( V_15 ) , V_20 ) ;
V_25 ++ ;
}
F_54 () ;
F_42 ( & V_44 ) ;
F_17 ( V_12 ) ;
}
void F_63 ( void )
{
struct V_3 * V_24 ;
int V_29 ;
F_40 ( & V_44 ) ;
for ( V_29 = V_42 ; V_29 <= V_30 ; V_29 ++ )
F_10 (publ, &tipc_nametbl->publ_list[scope],
local_list)
V_24 -> V_20 = V_57 ;
F_42 ( & V_44 ) ;
}
