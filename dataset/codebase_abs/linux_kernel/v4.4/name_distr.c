static void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
V_2 -> type = F_2 ( V_4 -> type ) ;
V_2 -> V_5 = F_2 ( V_4 -> V_5 ) ;
V_2 -> V_6 = F_2 ( V_4 -> V_6 ) ;
V_2 -> V_7 = F_2 ( V_4 -> V_7 ) ;
V_2 -> V_8 = F_2 ( V_4 -> V_8 ) ;
}
static struct V_9 * F_3 ( struct V_10 * V_10 , T_1 type , T_1 V_11 ,
T_1 V_12 )
{
struct V_13 * V_14 = F_4 ( V_10 , V_15 ) ;
struct V_9 * V_16 = F_5 ( V_17 + V_11 ) ;
struct V_18 * V_19 ;
if ( V_16 != NULL ) {
V_19 = F_6 ( V_16 ) ;
F_7 ( V_14 -> V_20 , V_19 , V_21 , type ,
V_17 , V_12 ) ;
F_8 ( V_19 , V_17 + V_11 ) ;
}
return V_16 ;
}
void F_9 ( struct V_10 * V_10 , struct V_9 * V_22 )
{
struct V_13 * V_14 = F_4 ( V_10 , V_15 ) ;
struct V_9 * V_23 ;
struct V_24 * V_25 ;
T_1 V_26 ;
F_10 () ;
F_11 (node, &tn->node_list, list) {
V_26 = V_25 -> V_27 ;
if ( F_12 ( V_10 , V_26 ) )
continue;
if ( ! F_13 ( V_25 ) )
continue;
V_23 = F_14 ( V_22 , V_28 ) ;
if ( ! V_23 )
break;
F_15 ( F_6 ( V_23 ) , V_26 ) ;
F_16 ( V_10 , V_23 , V_26 , 0 ) ;
}
F_17 () ;
F_18 ( V_22 ) ;
}
struct V_9 * F_19 ( struct V_10 * V_10 , struct V_3 * V_29 )
{
struct V_13 * V_14 = F_4 ( V_10 , V_15 ) ;
struct V_9 * V_16 ;
struct V_1 * V_30 ;
F_20 ( & V_29 -> V_31 ,
& V_14 -> V_32 -> V_33 [ V_29 -> V_34 ] ) ;
if ( V_29 -> V_34 == V_35 )
return NULL ;
V_16 = F_3 ( V_10 , V_36 , V_37 , 0 ) ;
if ( ! V_16 ) {
F_21 ( L_1 ) ;
return NULL ;
}
V_30 = (struct V_1 * ) F_22 ( F_6 ( V_16 ) ) ;
F_1 ( V_30 , V_29 ) ;
return V_16 ;
}
struct V_9 * F_23 ( struct V_10 * V_10 , struct V_3 * V_29 )
{
struct V_9 * V_16 ;
struct V_1 * V_30 ;
F_24 ( & V_29 -> V_31 ) ;
if ( V_29 -> V_34 == V_35 )
return NULL ;
V_16 = F_3 ( V_10 , V_38 , V_37 , 0 ) ;
if ( ! V_16 ) {
F_21 ( L_2 ) ;
return NULL ;
}
V_30 = (struct V_1 * ) F_22 ( F_6 ( V_16 ) ) ;
F_1 ( V_30 , V_29 ) ;
return V_16 ;
}
static void F_25 ( struct V_10 * V_10 , struct V_39 * V_40 ,
T_1 V_26 , struct V_41 * V_42 )
{
struct V_3 * V_29 ;
struct V_9 * V_22 = NULL ;
struct V_1 * V_30 = NULL ;
T_2 V_43 = ( F_26 ( V_10 , V_26 , 0 ) / V_37 ) *
V_37 ;
T_2 V_44 = V_43 ;
F_27 (publ, pls, local_list) {
if ( ! V_22 ) {
V_22 = F_3 ( V_10 , V_36 , V_44 ,
V_26 ) ;
if ( ! V_22 ) {
F_21 ( L_3 ) ;
return;
}
V_30 = (struct V_1 * ) F_22 ( F_6 ( V_22 ) ) ;
}
F_1 ( V_30 , V_29 ) ;
V_30 ++ ;
V_44 -= V_37 ;
if ( ! V_44 ) {
F_28 ( V_40 , V_22 ) ;
V_22 = NULL ;
V_44 = V_43 ;
}
}
if ( V_22 ) {
F_8 ( F_6 ( V_22 ) , V_17 + ( V_43 - V_44 ) ) ;
F_29 ( V_22 , V_17 + ( V_43 - V_44 ) ) ;
F_28 ( V_40 , V_22 ) ;
}
}
void F_30 ( struct V_10 * V_10 , T_1 V_26 )
{
struct V_13 * V_14 = F_4 ( V_10 , V_15 ) ;
struct V_39 V_45 ;
F_31 ( & V_45 ) ;
F_10 () ;
F_25 ( V_10 , & V_45 , V_26 ,
& V_14 -> V_32 -> V_33 [ V_46 ] ) ;
F_25 ( V_10 , & V_45 , V_26 ,
& V_14 -> V_32 -> V_33 [ V_47 ] ) ;
F_17 () ;
F_32 ( V_10 , & V_45 , V_26 , 0 ) ;
}
static void F_33 ( struct V_10 * V_10 , struct V_3 * V_29 ,
T_1 V_27 )
{
struct V_24 * V_25 ;
if ( F_12 ( V_10 , V_27 ) )
return;
V_25 = F_34 ( V_10 , V_27 ) ;
if ( ! V_25 ) {
F_21 ( L_4 ,
V_27 ) ;
return;
}
F_35 ( V_25 ) ;
F_36 ( & V_29 -> V_48 , & V_25 -> V_33 ) ;
F_37 ( V_25 ) ;
F_38 ( V_25 ) ;
}
static void F_39 ( struct V_10 * V_10 , struct V_3 * V_29 ,
T_1 V_27 )
{
struct V_24 * V_25 ;
V_25 = F_34 ( V_10 , V_27 ) ;
if ( ! V_25 )
return;
F_35 ( V_25 ) ;
F_40 ( & V_29 -> V_48 ) ;
F_37 ( V_25 ) ;
F_38 ( V_25 ) ;
}
static void F_41 ( struct V_10 * V_10 , struct V_3 * V_29 , T_1 V_27 )
{
struct V_13 * V_14 = F_4 ( V_10 , V_15 ) ;
struct V_3 * V_4 ;
F_42 ( & V_14 -> V_49 ) ;
V_4 = F_43 ( V_10 , V_29 -> type , V_29 -> V_5 ,
V_29 -> V_25 , V_29 -> V_7 , V_29 -> V_8 ) ;
if ( V_4 )
F_39 ( V_10 , V_4 , V_27 ) ;
F_44 ( & V_14 -> V_49 ) ;
if ( V_4 != V_29 ) {
F_45 ( L_5
L_6 ,
V_29 -> type , V_29 -> V_5 , V_29 -> V_25 , V_29 -> V_7 ,
V_29 -> V_8 ) ;
}
F_46 ( V_4 , V_50 ) ;
}
void F_47 ( struct V_10 * V_10 , struct V_41 * V_51 , T_1 V_27 )
{
struct V_3 * V_29 , * V_52 ;
F_48 (publ, tmp, nsub_list, nodesub_list)
F_41 ( V_10 , V_29 , V_27 ) ;
}
static bool F_49 ( struct V_10 * V_10 , struct V_1 * V_2 ,
T_1 V_25 , T_1 V_53 )
{
struct V_3 * V_29 = NULL ;
if ( V_53 == V_36 ) {
V_29 = F_50 ( V_10 , F_51 ( V_2 -> type ) ,
F_51 ( V_2 -> V_5 ) ,
F_51 ( V_2 -> V_6 ) ,
V_46 , V_25 ,
F_51 ( V_2 -> V_7 ) , F_51 ( V_2 -> V_8 ) ) ;
if ( V_29 ) {
F_33 ( V_10 , V_29 , V_25 ) ;
return true ;
}
} else if ( V_53 == V_38 ) {
V_29 = F_43 ( V_10 , F_51 ( V_2 -> type ) ,
F_51 ( V_2 -> V_5 ) ,
V_25 , F_51 ( V_2 -> V_7 ) ,
F_51 ( V_2 -> V_8 ) ) ;
if ( V_29 ) {
F_39 ( V_10 , V_29 , V_25 ) ;
F_46 ( V_29 , V_50 ) ;
return true ;
}
} else {
F_21 ( L_7 ) ;
}
return false ;
}
static void F_52 ( struct V_1 * V_2 , T_1 type , T_1 V_25 )
{
struct V_54 * V_55 ;
unsigned long V_56 = F_53 () ;
V_55 = F_54 ( sizeof( * V_55 ) , V_28 ) ;
if ( ! V_55 )
return;
V_55 -> V_53 = type ;
V_55 -> V_25 = V_25 ;
V_55 -> V_57 = V_56 + F_55 ( V_58 ) ;
memcpy ( V_55 , V_2 , sizeof( * V_2 ) ) ;
F_36 ( & V_55 -> V_59 , & V_60 ) ;
}
void F_56 ( struct V_10 * V_10 )
{
struct V_54 * V_55 , * V_52 ;
char V_27 [ 16 ] ;
unsigned long V_56 = F_53 () ;
F_48 (e, tmp, &tipc_dist_queue, next) {
if ( F_57 ( V_55 -> V_57 , V_56 ) ) {
if ( ! F_49 ( V_10 , & V_55 -> V_2 , V_55 -> V_25 , V_55 -> V_53 ) )
continue;
} else {
F_58 ( V_27 , V_55 -> V_25 ) ;
F_59 ( L_8 ,
V_55 -> V_53 , F_51 ( V_55 -> V_2 . type ) ,
F_51 ( V_55 -> V_2 . V_5 ) ,
F_51 ( V_55 -> V_2 . V_6 ) ,
V_27 , F_51 ( V_55 -> V_2 . V_8 ) ) ;
}
F_24 ( & V_55 -> V_59 ) ;
F_60 ( V_55 ) ;
}
}
void F_61 ( struct V_10 * V_10 , struct V_39 * V_61 )
{
struct V_13 * V_14 = F_4 ( V_10 , V_15 ) ;
struct V_18 * V_19 ;
struct V_1 * V_30 ;
T_2 V_62 ;
T_1 V_25 ;
struct V_9 * V_22 ;
int V_63 ;
F_42 ( & V_14 -> V_49 ) ;
for ( V_22 = F_62 ( V_61 ) ; V_22 ; V_22 = F_62 ( V_61 ) ) {
V_19 = F_6 ( V_22 ) ;
V_63 = F_63 ( V_19 ) ;
V_30 = (struct V_1 * ) F_22 ( V_19 ) ;
V_62 = F_64 ( V_19 ) / V_37 ;
V_25 = F_65 ( V_19 ) ;
while ( V_62 -- ) {
if ( ! F_49 ( V_10 , V_30 , V_25 , V_63 ) )
F_52 ( V_30 , V_63 , V_25 ) ;
V_30 ++ ;
}
F_18 ( V_22 ) ;
F_56 ( V_10 ) ;
}
F_44 ( & V_14 -> V_49 ) ;
}
void F_66 ( struct V_10 * V_10 )
{
struct V_13 * V_14 = F_4 ( V_10 , V_15 ) ;
struct V_3 * V_29 ;
int V_34 ;
F_42 ( & V_14 -> V_49 ) ;
for ( V_34 = V_47 ; V_34 <= V_35 ; V_34 ++ )
F_11 (publ, &tn->nametbl->publ_list[scope],
local_list)
V_29 -> V_25 = V_14 -> V_20 ;
F_44 ( & V_14 -> V_49 ) ;
}
