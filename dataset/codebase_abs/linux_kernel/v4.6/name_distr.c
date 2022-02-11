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
struct V_9 * F_9 ( struct V_10 * V_10 , struct V_3 * V_22 )
{
struct V_13 * V_14 = F_4 ( V_10 , V_15 ) ;
struct V_9 * V_16 ;
struct V_1 * V_23 ;
F_10 ( & V_22 -> V_24 ,
& V_14 -> V_25 -> V_26 [ V_22 -> V_27 ] ) ;
if ( V_22 -> V_27 == V_28 )
return NULL ;
V_16 = F_3 ( V_10 , V_29 , V_30 , 0 ) ;
if ( ! V_16 ) {
F_11 ( L_1 ) ;
return NULL ;
}
V_23 = (struct V_1 * ) F_12 ( F_6 ( V_16 ) ) ;
F_1 ( V_23 , V_22 ) ;
return V_16 ;
}
struct V_9 * F_13 ( struct V_10 * V_10 , struct V_3 * V_22 )
{
struct V_9 * V_16 ;
struct V_1 * V_23 ;
F_14 ( & V_22 -> V_24 ) ;
if ( V_22 -> V_27 == V_28 )
return NULL ;
V_16 = F_3 ( V_10 , V_31 , V_30 , 0 ) ;
if ( ! V_16 ) {
F_11 ( L_2 ) ;
return NULL ;
}
V_23 = (struct V_1 * ) F_12 ( F_6 ( V_16 ) ) ;
F_1 ( V_23 , V_22 ) ;
return V_16 ;
}
static void F_15 ( struct V_10 * V_10 , struct V_32 * V_33 ,
T_1 V_34 , struct V_35 * V_36 )
{
struct V_3 * V_22 ;
struct V_9 * V_37 = NULL ;
struct V_1 * V_23 = NULL ;
T_2 V_38 = ( F_16 ( V_10 , V_34 , 0 ) / V_30 ) *
V_30 ;
T_2 V_39 = V_38 ;
F_17 (publ, pls, local_list) {
if ( ! V_37 ) {
V_37 = F_3 ( V_10 , V_29 , V_39 ,
V_34 ) ;
if ( ! V_37 ) {
F_11 ( L_3 ) ;
return;
}
V_23 = (struct V_1 * ) F_12 ( F_6 ( V_37 ) ) ;
}
F_1 ( V_23 , V_22 ) ;
V_23 ++ ;
V_39 -= V_30 ;
if ( ! V_39 ) {
F_18 ( V_33 , V_37 ) ;
V_37 = NULL ;
V_39 = V_38 ;
}
}
if ( V_37 ) {
F_8 ( F_6 ( V_37 ) , V_17 + ( V_38 - V_39 ) ) ;
F_19 ( V_37 , V_17 + ( V_38 - V_39 ) ) ;
F_18 ( V_33 , V_37 ) ;
}
}
void F_20 ( struct V_10 * V_10 , T_1 V_34 )
{
struct V_13 * V_14 = F_4 ( V_10 , V_15 ) ;
struct V_32 V_40 ;
F_21 ( & V_40 ) ;
F_22 () ;
F_15 ( V_10 , & V_40 , V_34 ,
& V_14 -> V_25 -> V_26 [ V_41 ] ) ;
F_15 ( V_10 , & V_40 , V_34 ,
& V_14 -> V_25 -> V_26 [ V_42 ] ) ;
F_23 () ;
F_24 ( V_10 , & V_40 , V_34 , 0 ) ;
}
static void F_25 ( struct V_10 * V_10 , struct V_3 * V_22 , T_1 V_43 )
{
struct V_13 * V_14 = F_4 ( V_10 , V_15 ) ;
struct V_3 * V_4 ;
F_26 ( & V_14 -> V_44 ) ;
V_4 = F_27 ( V_10 , V_22 -> type , V_22 -> V_5 ,
V_22 -> V_45 , V_22 -> V_7 , V_22 -> V_8 ) ;
if ( V_4 )
F_28 ( V_10 , & V_4 -> V_46 , V_43 ) ;
F_29 ( & V_14 -> V_44 ) ;
if ( V_4 != V_22 ) {
F_30 ( L_4
L_5 ,
V_22 -> type , V_22 -> V_5 , V_22 -> V_45 , V_22 -> V_7 ,
V_22 -> V_8 ) ;
}
F_31 ( V_4 , V_47 ) ;
}
static void F_32 ( struct V_10 * V_10 , T_1 V_43 )
{
struct V_13 * V_14 = F_4 ( V_10 , V_15 ) ;
struct V_48 * V_49 , * V_50 ;
F_26 ( & V_14 -> V_44 ) ;
F_33 (e, tmp, &tn->dist_queue, next) {
if ( V_49 -> V_45 != V_43 )
continue;
F_14 ( & V_49 -> V_51 ) ;
F_34 ( V_49 ) ;
}
F_29 ( & V_14 -> V_44 ) ;
}
void F_35 ( struct V_10 * V_10 , struct V_35 * V_52 , T_1 V_43 )
{
struct V_3 * V_22 , * V_50 ;
F_33 (publ, tmp, nsub_list, nodesub_list)
F_25 ( V_10 , V_22 , V_43 ) ;
F_32 ( V_10 , V_43 ) ;
}
static bool F_36 ( struct V_10 * V_10 , struct V_1 * V_2 ,
T_1 V_45 , T_1 V_53 )
{
struct V_3 * V_22 = NULL ;
if ( V_53 == V_29 ) {
V_22 = F_37 ( V_10 , F_38 ( V_2 -> type ) ,
F_38 ( V_2 -> V_5 ) ,
F_38 ( V_2 -> V_6 ) ,
V_41 , V_45 ,
F_38 ( V_2 -> V_7 ) , F_38 ( V_2 -> V_8 ) ) ;
if ( V_22 ) {
F_39 ( V_10 , & V_22 -> V_46 , V_45 ) ;
return true ;
}
} else if ( V_53 == V_31 ) {
V_22 = F_27 ( V_10 , F_38 ( V_2 -> type ) ,
F_38 ( V_2 -> V_5 ) ,
V_45 , F_38 ( V_2 -> V_7 ) ,
F_38 ( V_2 -> V_8 ) ) ;
if ( V_22 ) {
F_28 ( V_10 , & V_22 -> V_46 , V_45 ) ;
F_31 ( V_22 , V_47 ) ;
return true ;
}
} else {
F_11 ( L_6 ) ;
}
return false ;
}
static void F_40 ( struct V_10 * V_10 , struct V_1 * V_2 ,
T_1 type , T_1 V_45 )
{
struct V_48 * V_49 ;
struct V_13 * V_14 = F_4 ( V_10 , V_15 ) ;
unsigned long V_54 = F_41 () ;
V_49 = F_42 ( sizeof( * V_49 ) , V_55 ) ;
if ( ! V_49 )
return;
V_49 -> V_53 = type ;
V_49 -> V_45 = V_45 ;
V_49 -> V_56 = V_54 + F_43 ( V_57 ) ;
memcpy ( V_49 , V_2 , sizeof( * V_2 ) ) ;
F_44 ( & V_49 -> V_51 , & V_14 -> V_58 ) ;
}
void F_45 ( struct V_10 * V_10 )
{
struct V_48 * V_49 , * V_50 ;
struct V_13 * V_14 = F_4 ( V_10 , V_15 ) ;
char V_43 [ 16 ] ;
unsigned long V_54 = F_41 () ;
F_33 (e, tmp, &tn->dist_queue, next) {
if ( F_46 ( V_49 -> V_56 , V_54 ) ) {
if ( ! F_36 ( V_10 , & V_49 -> V_2 , V_49 -> V_45 , V_49 -> V_53 ) )
continue;
} else {
F_47 ( V_43 , V_49 -> V_45 ) ;
F_48 ( L_7 ,
V_49 -> V_53 , F_38 ( V_49 -> V_2 . type ) ,
F_38 ( V_49 -> V_2 . V_5 ) ,
F_38 ( V_49 -> V_2 . V_6 ) ,
V_43 , F_38 ( V_49 -> V_2 . V_8 ) ) ;
}
F_14 ( & V_49 -> V_51 ) ;
F_34 ( V_49 ) ;
}
}
void F_49 ( struct V_10 * V_10 , struct V_32 * V_59 )
{
struct V_13 * V_14 = F_4 ( V_10 , V_15 ) ;
struct V_18 * V_19 ;
struct V_1 * V_23 ;
T_2 V_60 ;
T_1 V_45 ;
struct V_9 * V_37 ;
int V_61 ;
F_26 ( & V_14 -> V_44 ) ;
for ( V_37 = F_50 ( V_59 ) ; V_37 ; V_37 = F_50 ( V_59 ) ) {
F_51 ( V_37 ) ;
V_19 = F_6 ( V_37 ) ;
V_61 = F_52 ( V_19 ) ;
V_23 = (struct V_1 * ) F_12 ( V_19 ) ;
V_60 = F_53 ( V_19 ) / V_30 ;
V_45 = F_54 ( V_19 ) ;
while ( V_60 -- ) {
if ( ! F_36 ( V_10 , V_23 , V_45 , V_61 ) )
F_40 ( V_10 , V_23 , V_61 , V_45 ) ;
V_23 ++ ;
}
F_55 ( V_37 ) ;
F_45 ( V_10 ) ;
}
F_29 ( & V_14 -> V_44 ) ;
}
void F_56 ( struct V_10 * V_10 )
{
struct V_13 * V_14 = F_4 ( V_10 , V_15 ) ;
struct V_3 * V_22 ;
int V_27 ;
F_26 ( & V_14 -> V_44 ) ;
for ( V_27 = V_42 ; V_27 <= V_28 ; V_27 ++ )
F_57 (publ, &tn->nametbl->publ_list[scope],
local_list)
V_22 -> V_45 = V_14 -> V_20 ;
F_29 ( & V_14 -> V_44 ) ;
}
