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
struct V_9 * V_16 = F_5 ( V_17 + V_11 , V_18 ) ;
struct V_19 * V_20 ;
if ( V_16 != NULL ) {
V_20 = F_6 ( V_16 ) ;
F_7 ( V_14 -> V_21 , V_20 , V_22 , type ,
V_17 , V_12 ) ;
F_8 ( V_20 , V_17 + V_11 ) ;
}
return V_16 ;
}
struct V_9 * F_9 ( struct V_10 * V_10 , struct V_3 * V_23 )
{
struct V_13 * V_14 = F_4 ( V_10 , V_15 ) ;
struct V_9 * V_16 ;
struct V_1 * V_24 ;
F_10 ( & V_23 -> V_25 ,
& V_14 -> V_26 -> V_27 [ V_23 -> V_28 ] ) ;
if ( V_23 -> V_28 == V_29 )
return NULL ;
V_16 = F_3 ( V_10 , V_30 , V_31 , 0 ) ;
if ( ! V_16 ) {
F_11 ( L_1 ) ;
return NULL ;
}
V_24 = (struct V_1 * ) F_12 ( F_6 ( V_16 ) ) ;
F_1 ( V_24 , V_23 ) ;
return V_16 ;
}
struct V_9 * F_13 ( struct V_10 * V_10 , struct V_3 * V_23 )
{
struct V_9 * V_16 ;
struct V_1 * V_24 ;
F_14 ( & V_23 -> V_25 ) ;
if ( V_23 -> V_28 == V_29 )
return NULL ;
V_16 = F_3 ( V_10 , V_32 , V_31 , 0 ) ;
if ( ! V_16 ) {
F_11 ( L_2 ) ;
return NULL ;
}
V_24 = (struct V_1 * ) F_12 ( F_6 ( V_16 ) ) ;
F_1 ( V_24 , V_23 ) ;
return V_16 ;
}
static void F_15 ( struct V_10 * V_10 , struct V_33 * V_34 ,
T_1 V_35 , struct V_36 * V_37 )
{
struct V_3 * V_23 ;
struct V_9 * V_38 = NULL ;
struct V_1 * V_24 = NULL ;
T_1 V_39 = ( ( F_16 ( V_10 , V_35 , 0 ) - V_17 ) /
V_31 ) * V_31 ;
T_1 V_40 = V_39 ;
F_17 (publ, pls, local_list) {
if ( ! V_38 ) {
V_38 = F_3 ( V_10 , V_30 , V_40 ,
V_35 ) ;
if ( ! V_38 ) {
F_11 ( L_3 ) ;
return;
}
F_18 ( F_6 ( V_38 ) , true ) ;
V_24 = (struct V_1 * ) F_12 ( F_6 ( V_38 ) ) ;
}
F_1 ( V_24 , V_23 ) ;
V_24 ++ ;
V_40 -= V_31 ;
if ( ! V_40 ) {
F_19 ( V_34 , V_38 ) ;
V_38 = NULL ;
V_40 = V_39 ;
}
}
if ( V_38 ) {
F_8 ( F_6 ( V_38 ) , V_17 + ( V_39 - V_40 ) ) ;
F_20 ( V_38 , V_17 + ( V_39 - V_40 ) ) ;
F_19 ( V_34 , V_38 ) ;
}
}
void F_21 ( struct V_10 * V_10 , T_1 V_35 )
{
struct V_13 * V_14 = F_4 ( V_10 , V_15 ) ;
struct V_33 V_41 ;
F_22 ( & V_41 ) ;
F_23 () ;
F_15 ( V_10 , & V_41 , V_35 ,
& V_14 -> V_26 -> V_27 [ V_42 ] ) ;
F_15 ( V_10 , & V_41 , V_35 ,
& V_14 -> V_26 -> V_27 [ V_43 ] ) ;
F_24 () ;
F_25 ( V_10 , & V_41 , V_35 , 0 ) ;
}
static void F_26 ( struct V_10 * V_10 , struct V_3 * V_23 , T_1 V_44 )
{
struct V_13 * V_14 = F_4 ( V_10 , V_15 ) ;
struct V_3 * V_4 ;
F_27 ( & V_14 -> V_45 ) ;
V_4 = F_28 ( V_10 , V_23 -> type , V_23 -> V_5 ,
V_23 -> V_46 , V_23 -> V_7 , V_23 -> V_8 ) ;
if ( V_4 )
F_29 ( V_10 , & V_4 -> V_47 , V_44 ) ;
F_30 ( & V_14 -> V_45 ) ;
if ( V_4 != V_23 ) {
F_31 ( L_4
L_5 ,
V_23 -> type , V_23 -> V_5 , V_23 -> V_46 , V_23 -> V_7 ,
V_23 -> V_8 ) ;
}
F_32 ( V_4 , V_48 ) ;
}
static void F_33 ( struct V_10 * V_10 , T_1 V_44 )
{
struct V_13 * V_14 = F_4 ( V_10 , V_15 ) ;
struct V_49 * V_50 , * V_51 ;
F_27 ( & V_14 -> V_45 ) ;
F_34 (e, tmp, &tn->dist_queue, next) {
if ( V_50 -> V_46 != V_44 )
continue;
F_14 ( & V_50 -> V_52 ) ;
F_35 ( V_50 ) ;
}
F_30 ( & V_14 -> V_45 ) ;
}
void F_36 ( struct V_10 * V_10 , struct V_36 * V_53 , T_1 V_44 )
{
struct V_3 * V_23 , * V_51 ;
F_34 (publ, tmp, nsub_list, nodesub_list)
F_26 ( V_10 , V_23 , V_44 ) ;
F_33 ( V_10 , V_44 ) ;
}
static bool F_37 ( struct V_10 * V_10 , struct V_1 * V_2 ,
T_1 V_46 , T_1 V_54 )
{
struct V_3 * V_23 = NULL ;
if ( V_54 == V_30 ) {
V_23 = F_38 ( V_10 , F_39 ( V_2 -> type ) ,
F_39 ( V_2 -> V_5 ) ,
F_39 ( V_2 -> V_6 ) ,
V_42 , V_46 ,
F_39 ( V_2 -> V_7 ) , F_39 ( V_2 -> V_8 ) ) ;
if ( V_23 ) {
F_40 ( V_10 , & V_23 -> V_47 , V_46 ) ;
return true ;
}
} else if ( V_54 == V_32 ) {
V_23 = F_28 ( V_10 , F_39 ( V_2 -> type ) ,
F_39 ( V_2 -> V_5 ) ,
V_46 , F_39 ( V_2 -> V_7 ) ,
F_39 ( V_2 -> V_8 ) ) ;
if ( V_23 ) {
F_29 ( V_10 , & V_23 -> V_47 , V_46 ) ;
F_32 ( V_23 , V_48 ) ;
return true ;
}
} else {
F_11 ( L_6 ) ;
}
return false ;
}
static void F_41 ( struct V_10 * V_10 , struct V_1 * V_2 ,
T_1 type , T_1 V_46 )
{
struct V_49 * V_50 ;
struct V_13 * V_14 = F_4 ( V_10 , V_15 ) ;
unsigned long V_55 = F_42 () ;
V_50 = F_43 ( sizeof( * V_50 ) , V_18 ) ;
if ( ! V_50 )
return;
V_50 -> V_54 = type ;
V_50 -> V_46 = V_46 ;
V_50 -> V_56 = V_55 + F_44 ( V_57 ) ;
memcpy ( V_50 , V_2 , sizeof( * V_2 ) ) ;
F_45 ( & V_50 -> V_52 , & V_14 -> V_58 ) ;
}
void F_46 ( struct V_10 * V_10 )
{
struct V_49 * V_50 , * V_51 ;
struct V_13 * V_14 = F_4 ( V_10 , V_15 ) ;
char V_44 [ 16 ] ;
unsigned long V_55 = F_42 () ;
F_34 (e, tmp, &tn->dist_queue, next) {
if ( F_47 ( V_50 -> V_56 , V_55 ) ) {
if ( ! F_37 ( V_10 , & V_50 -> V_2 , V_50 -> V_46 , V_50 -> V_54 ) )
continue;
} else {
F_48 ( V_44 , V_50 -> V_46 ) ;
F_49 ( L_7 ,
V_50 -> V_54 , F_39 ( V_50 -> V_2 . type ) ,
F_39 ( V_50 -> V_2 . V_5 ) ,
F_39 ( V_50 -> V_2 . V_6 ) ,
V_44 , F_39 ( V_50 -> V_2 . V_8 ) ) ;
}
F_14 ( & V_50 -> V_52 ) ;
F_35 ( V_50 ) ;
}
}
void F_50 ( struct V_10 * V_10 , struct V_33 * V_59 )
{
struct V_13 * V_14 = F_4 ( V_10 , V_15 ) ;
struct V_19 * V_20 ;
struct V_1 * V_24 ;
T_2 V_60 ;
T_1 V_46 ;
struct V_9 * V_38 ;
int V_61 ;
F_27 ( & V_14 -> V_45 ) ;
for ( V_38 = F_51 ( V_59 ) ; V_38 ; V_38 = F_51 ( V_59 ) ) {
F_52 ( V_38 ) ;
V_20 = F_6 ( V_38 ) ;
V_61 = F_53 ( V_20 ) ;
V_24 = (struct V_1 * ) F_12 ( V_20 ) ;
V_60 = F_54 ( V_20 ) / V_31 ;
V_46 = F_55 ( V_20 ) ;
while ( V_60 -- ) {
if ( ! F_37 ( V_10 , V_24 , V_46 , V_61 ) )
F_41 ( V_10 , V_24 , V_61 , V_46 ) ;
V_24 ++ ;
}
F_56 ( V_38 ) ;
F_46 ( V_10 ) ;
}
F_30 ( & V_14 -> V_45 ) ;
}
void F_57 ( struct V_10 * V_10 )
{
struct V_13 * V_14 = F_4 ( V_10 , V_15 ) ;
struct V_3 * V_23 ;
int V_28 ;
F_27 ( & V_14 -> V_45 ) ;
for ( V_28 = V_43 ; V_28 <= V_29 ; V_28 ++ )
F_58 (publ, &tn->nametbl->publ_list[scope],
local_list)
V_23 -> V_46 = V_14 -> V_21 ;
F_30 ( & V_14 -> V_45 ) ;
}
