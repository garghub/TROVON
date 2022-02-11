static int F_1 ( int V_1 )
{
V_1 = F_2 ( V_1 , V_2 ) ;
if ( V_1 >= V_3 )
V_1 = F_3 ( V_2 ) ;
return V_1 ;
}
static struct V_4 * F_4 ( struct V_5 * V_6 )
{
return & V_6 -> V_7 [ V_8 ] ;
}
static struct V_4 * F_5 ( struct V_5 * V_6 )
{
return & V_6 -> V_7 [ V_9 ] ;
}
static bool F_6 ( const struct V_10 * V_11 )
{
return V_11 -> V_12 ;
}
static void F_7 ( struct V_13 * V_14 ,
enum V_15 type )
{
if ( type < V_16 )
V_14 -> V_17 [ type ] ++ ;
}
static void F_8 ( struct V_13 * V_14 ,
enum V_15 type )
{
if ( type < V_16 )
V_14 -> V_17 [ type ] -- ;
}
static void F_9 ( struct V_13 * V_14 ,
struct V_10 * V_11 ,
struct V_4 * V_18 ,
enum V_15 V_19 )
{
if ( F_10 ( F_11 ( V_11 -> type ) ) )
return;
if ( & V_11 -> V_20 == V_14 -> V_21 )
V_14 -> V_21 = V_14 -> V_21 -> V_22 ;
F_8 ( V_14 , V_11 -> type ) ;
V_11 -> type = V_19 ;
F_12 ( & V_11 -> V_20 , V_18 ) ;
}
static void F_13 ( struct V_13 * V_14 ,
struct V_10 * V_11 ,
enum V_15 V_23 )
{
if ( F_10 ( ! F_11 ( V_11 -> type ) ) ||
F_10 ( F_11 ( V_23 ) ) )
return;
F_7 ( V_14 , V_23 ) ;
V_11 -> type = V_23 ;
V_11 -> V_12 = 0 ;
F_12 ( & V_11 -> V_20 , & V_14 -> V_7 [ V_23 ] ) ;
}
static void F_14 ( struct V_13 * V_14 ,
struct V_10 * V_11 ,
enum V_15 V_23 )
{
if ( F_10 ( F_11 ( V_11 -> type ) ) ||
F_10 ( F_11 ( V_23 ) ) )
return;
if ( V_11 -> type != V_23 ) {
F_8 ( V_14 , V_11 -> type ) ;
F_7 ( V_14 , V_23 ) ;
V_11 -> type = V_23 ;
}
V_11 -> V_12 = 0 ;
if ( & V_11 -> V_20 == V_14 -> V_21 )
V_14 -> V_21 = V_14 -> V_21 -> V_22 ;
F_12 ( & V_11 -> V_20 , & V_14 -> V_7 [ V_23 ] ) ;
}
static bool F_15 ( const struct V_13 * V_14 )
{
return V_14 -> V_17 [ V_24 ] <
V_14 -> V_17 [ V_25 ] ;
}
static void F_16 ( struct V_26 * V_27 ,
struct V_13 * V_14 )
{
struct V_4 * V_28 = & V_14 -> V_7 [ V_25 ] ;
struct V_10 * V_11 , * V_29 , * V_30 ;
unsigned int V_31 = 0 ;
V_30 = F_17 ( V_28 , struct V_10 , V_20 ) ;
F_18 (node, tmp_node, active, list) {
if ( F_6 ( V_11 ) )
F_14 ( V_14 , V_11 , V_25 ) ;
else
F_14 ( V_14 , V_11 , V_24 ) ;
if ( ++ V_31 == V_27 -> V_32 || V_11 == V_30 )
break;
}
}
static void F_19 ( struct V_26 * V_27 ,
struct V_13 * V_14 )
{
struct V_4 * V_33 = & V_14 -> V_7 [ V_24 ] ;
struct V_4 * V_34 , * V_35 , * V_36 = V_33 ;
struct V_10 * V_11 ;
unsigned int V_31 = 0 ;
if ( F_20 ( V_33 ) )
return;
V_35 = V_14 -> V_21 -> V_36 ;
if ( V_35 == V_33 )
V_35 = V_35 -> V_36 ;
V_34 = V_14 -> V_21 ;
while ( V_31 < V_27 -> V_32 ) {
if ( V_34 == V_33 ) {
V_34 = V_34 -> V_22 ;
continue;
}
V_11 = F_21 ( V_34 , struct V_10 , V_20 ) ;
V_36 = V_34 -> V_22 ;
if ( F_6 ( V_11 ) )
F_14 ( V_14 , V_11 , V_25 ) ;
if ( V_34 == V_35 )
break;
V_34 = V_36 ;
V_31 ++ ;
}
V_14 -> V_21 = V_36 ;
}
static unsigned int
F_22 ( struct V_26 * V_27 ,
struct V_13 * V_14 ,
unsigned int V_37 ,
struct V_4 * V_18 ,
enum V_15 V_19 )
{
struct V_4 * V_33 = & V_14 -> V_7 [ V_24 ] ;
struct V_10 * V_11 , * V_29 ;
unsigned int V_38 = 0 ;
unsigned int V_31 = 0 ;
F_18 (node, tmp_node, inactive, list) {
if ( F_6 ( V_11 ) ) {
F_14 ( V_14 , V_11 , V_25 ) ;
} else if ( V_27 -> V_39 ( V_27 -> V_40 , V_11 ) ) {
F_9 ( V_14 , V_11 , V_18 ,
V_19 ) ;
if ( ++ V_38 == V_37 )
break;
}
if ( ++ V_31 == V_27 -> V_32 )
break;
}
return V_38 ;
}
static void F_23 ( struct V_26 * V_27 , struct V_13 * V_14 )
{
if ( F_15 ( V_14 ) )
F_16 ( V_27 , V_14 ) ;
F_19 ( V_27 , V_14 ) ;
}
static unsigned int F_24 ( struct V_26 * V_27 ,
struct V_13 * V_14 ,
unsigned int V_37 ,
struct V_4 * V_18 ,
enum V_15 V_19 )
{
struct V_10 * V_11 , * V_29 ;
struct V_4 * V_41 ;
unsigned int V_38 ;
V_38 = F_22 ( V_27 , V_14 , V_37 ,
V_18 , V_19 ) ;
if ( V_38 )
return V_38 ;
if ( ! F_20 ( & V_14 -> V_7 [ V_24 ] ) )
V_41 = & V_14 -> V_7 [ V_24 ] ;
else
V_41 = & V_14 -> V_7 [ V_25 ] ;
F_18 (node, tmp_node, force_shrink_list,
list) {
if ( V_27 -> V_39 ( V_27 -> V_40 , V_11 ) ) {
F_9 ( V_14 , V_11 , V_18 ,
V_19 ) ;
return 1 ;
}
}
return 0 ;
}
static void F_25 ( struct V_13 * V_14 ,
struct V_5 * V_6 )
{
struct V_10 * V_11 , * V_29 ;
F_18 (node, tmp_node,
local_pending_list(loc_l), list) {
if ( F_6 ( V_11 ) )
F_13 ( V_14 , V_11 , V_25 ) ;
else
F_13 ( V_14 , V_11 ,
V_24 ) ;
}
}
static void F_26 ( struct V_13 * V_14 ,
struct V_10 * V_11 )
{
unsigned long V_42 ;
if ( F_10 ( F_11 ( V_11 -> type ) ) )
return;
F_27 ( & V_14 -> V_43 , V_42 ) ;
F_14 ( V_14 , V_11 , V_44 ) ;
F_28 ( & V_14 -> V_43 , V_42 ) ;
}
static void F_29 ( struct V_26 * V_27 ,
struct V_5 * V_6 )
{
struct V_13 * V_14 = & V_27 -> V_45 . V_46 ;
struct V_10 * V_11 , * V_29 ;
unsigned int V_47 = 0 ;
F_30 ( & V_14 -> V_43 ) ;
F_25 ( V_14 , V_6 ) ;
F_23 ( V_27 , V_14 ) ;
F_31 (node, tmp_node, &l->lists[BPF_LRU_LIST_T_FREE],
list) {
F_9 ( V_14 , V_11 , F_4 ( V_6 ) ,
V_48 ) ;
if ( ++ V_47 == V_49 )
break;
}
if ( V_47 < V_49 )
F_24 ( V_27 , V_14 , V_49 - V_47 ,
F_4 ( V_6 ) ,
V_48 ) ;
F_32 ( & V_14 -> V_43 ) ;
}
static void F_33 ( struct V_26 * V_27 ,
struct V_5 * V_6 ,
int V_1 ,
struct V_10 * V_11 ,
T_1 V_50 )
{
* ( T_1 * ) ( ( void * ) V_11 + V_27 -> V_51 ) = V_50 ;
V_11 -> V_1 = V_1 ;
V_11 -> type = V_52 ;
V_11 -> V_12 = 0 ;
F_34 ( & V_11 -> V_20 , F_5 ( V_6 ) ) ;
}
static struct V_10 *
F_35 ( struct V_5 * V_6 )
{
struct V_10 * V_11 ;
V_11 = F_36 ( F_4 ( V_6 ) ,
struct V_10 ,
V_20 ) ;
if ( V_11 )
F_37 ( & V_11 -> V_20 ) ;
return V_11 ;
}
static struct V_10 *
F_38 ( struct V_26 * V_27 , struct V_5 * V_6 )
{
struct V_10 * V_11 ;
bool V_53 = false ;
V_54:
F_39 (node, local_pending_list(loc_l),
list) {
if ( ( ! F_6 ( V_11 ) || V_53 ) &&
V_27 -> V_39 ( V_27 -> V_40 , V_11 ) ) {
F_37 ( & V_11 -> V_20 ) ;
return V_11 ;
}
}
if ( ! V_53 ) {
V_53 = true ;
goto V_54;
}
return NULL ;
}
static struct V_10 * F_40 ( struct V_26 * V_27 ,
T_1 V_50 )
{
struct V_4 * V_18 ;
struct V_10 * V_11 = NULL ;
struct V_13 * V_14 ;
unsigned long V_42 ;
int V_1 = F_41 () ;
V_14 = F_42 ( V_27 -> V_55 , V_1 ) ;
F_27 ( & V_14 -> V_43 , V_42 ) ;
F_23 ( V_27 , V_14 ) ;
V_18 = & V_14 -> V_7 [ V_44 ] ;
if ( F_20 ( V_18 ) )
F_24 ( V_27 , V_14 , V_56 , V_18 ,
V_44 ) ;
if ( ! F_20 ( V_18 ) ) {
V_11 = F_17 ( V_18 , struct V_10 , V_20 ) ;
* ( T_1 * ) ( ( void * ) V_11 + V_27 -> V_51 ) = V_50 ;
V_11 -> V_12 = 0 ;
F_14 ( V_14 , V_11 , V_24 ) ;
}
F_28 ( & V_14 -> V_43 , V_42 ) ;
return V_11 ;
}
static struct V_10 * F_43 ( struct V_26 * V_27 ,
T_1 V_50 )
{
struct V_5 * V_6 , * V_57 ;
struct V_58 * V_59 = & V_27 -> V_45 ;
struct V_10 * V_11 ;
int V_60 , V_61 ;
unsigned long V_42 ;
int V_1 = F_41 () ;
V_6 = F_42 ( V_59 -> V_62 , V_1 ) ;
F_27 ( & V_6 -> V_43 , V_42 ) ;
V_11 = F_35 ( V_6 ) ;
if ( ! V_11 ) {
F_29 ( V_27 , V_6 ) ;
V_11 = F_35 ( V_6 ) ;
}
if ( V_11 )
F_33 ( V_27 , V_6 , V_1 , V_11 , V_50 ) ;
F_28 ( & V_6 -> V_43 , V_42 ) ;
if ( V_11 )
return V_11 ;
V_61 = V_6 -> V_63 ;
V_60 = V_61 ;
do {
V_57 = F_42 ( V_59 -> V_62 , V_60 ) ;
F_27 ( & V_57 -> V_43 , V_42 ) ;
V_11 = F_35 ( V_57 ) ;
if ( ! V_11 )
V_11 = F_38 ( V_27 , V_57 ) ;
F_28 ( & V_57 -> V_43 , V_42 ) ;
V_60 = F_1 ( V_60 ) ;
} while ( ! V_11 && V_60 != V_61 );
V_6 -> V_63 = V_60 ;
if ( V_11 ) {
F_27 ( & V_6 -> V_43 , V_42 ) ;
F_33 ( V_27 , V_6 , V_1 , V_11 , V_50 ) ;
F_28 ( & V_6 -> V_43 , V_42 ) ;
}
return V_11 ;
}
struct V_10 * F_44 ( struct V_26 * V_27 , T_1 V_50 )
{
if ( V_27 -> V_64 )
return F_40 ( V_27 , V_50 ) ;
else
return F_43 ( V_27 , V_50 ) ;
}
static void F_45 ( struct V_26 * V_27 ,
struct V_10 * V_11 )
{
unsigned long V_42 ;
if ( F_10 ( V_11 -> type == V_44 ) ||
F_10 ( V_11 -> type == V_48 ) )
return;
if ( V_11 -> type == V_52 ) {
struct V_5 * V_6 ;
V_6 = F_42 ( V_27 -> V_45 . V_62 , V_11 -> V_1 ) ;
F_27 ( & V_6 -> V_43 , V_42 ) ;
if ( F_46 ( V_11 -> type != V_52 ) ) {
F_28 ( & V_6 -> V_43 , V_42 ) ;
goto V_65;
}
V_11 -> type = V_48 ;
V_11 -> V_12 = 0 ;
F_12 ( & V_11 -> V_20 , F_4 ( V_6 ) ) ;
F_28 ( & V_6 -> V_43 , V_42 ) ;
return;
}
V_65:
F_26 ( & V_27 -> V_45 . V_46 , V_11 ) ;
}
static void F_47 ( struct V_26 * V_27 ,
struct V_10 * V_11 )
{
struct V_13 * V_14 ;
unsigned long V_42 ;
V_14 = F_42 ( V_27 -> V_55 , V_11 -> V_1 ) ;
F_27 ( & V_14 -> V_43 , V_42 ) ;
F_14 ( V_14 , V_11 , V_44 ) ;
F_28 ( & V_14 -> V_43 , V_42 ) ;
}
void F_48 ( struct V_26 * V_27 , struct V_10 * V_11 )
{
if ( V_27 -> V_64 )
F_47 ( V_27 , V_11 ) ;
else
F_45 ( V_27 , V_11 ) ;
}
static void F_49 ( struct V_26 * V_27 , void * V_66 ,
T_1 V_67 , T_1 V_68 ,
T_1 V_69 )
{
struct V_13 * V_14 = & V_27 -> V_45 . V_46 ;
T_1 V_31 ;
for ( V_31 = 0 ; V_31 < V_69 ; V_31 ++ ) {
struct V_10 * V_11 ;
V_11 = (struct V_10 * ) ( V_66 + V_67 ) ;
V_11 -> type = V_44 ;
V_11 -> V_12 = 0 ;
F_34 ( & V_11 -> V_20 , & V_14 -> V_7 [ V_44 ] ) ;
V_66 += V_68 ;
}
}
static void F_50 ( struct V_26 * V_27 , void * V_66 ,
T_1 V_67 , T_1 V_68 ,
T_1 V_69 )
{
T_1 V_31 , V_70 ;
int V_1 ;
struct V_13 * V_14 ;
V_70 = V_69 / F_51 () ;
V_31 = 0 ;
F_52 (cpu) {
struct V_10 * V_11 ;
V_14 = F_42 ( V_27 -> V_55 , V_1 ) ;
V_71:
V_11 = (struct V_10 * ) ( V_66 + V_67 ) ;
V_11 -> V_1 = V_1 ;
V_11 -> type = V_44 ;
V_11 -> V_12 = 0 ;
F_34 ( & V_11 -> V_20 , & V_14 -> V_7 [ V_44 ] ) ;
V_31 ++ ;
V_66 += V_68 ;
if ( V_31 == V_69 )
break;
if ( V_31 % V_70 )
goto V_71;
}
}
void F_53 ( struct V_26 * V_27 , void * V_66 , T_1 V_67 ,
T_1 V_68 , T_1 V_69 )
{
if ( V_27 -> V_64 )
F_50 ( V_27 , V_66 , V_67 , V_68 ,
V_69 ) ;
else
F_49 ( V_27 , V_66 , V_67 , V_68 ,
V_69 ) ;
}
static void F_54 ( struct V_5 * V_6 , int V_1 )
{
int V_31 ;
for ( V_31 = 0 ; V_31 < V_72 ; V_31 ++ )
F_55 ( & V_6 -> V_7 [ V_31 ] ) ;
V_6 -> V_63 = V_1 ;
F_56 ( & V_6 -> V_43 ) ;
}
static void F_57 ( struct V_13 * V_14 )
{
int V_31 ;
for ( V_31 = 0 ; V_31 < V_73 ; V_31 ++ )
F_55 ( & V_14 -> V_7 [ V_31 ] ) ;
for ( V_31 = 0 ; V_31 < V_16 ; V_31 ++ )
V_14 -> V_17 [ V_31 ] = 0 ;
V_14 -> V_21 = & V_14 -> V_7 [ V_24 ] ;
F_56 ( & V_14 -> V_43 ) ;
}
int F_58 ( struct V_26 * V_27 , bool V_64 , T_1 V_51 ,
T_2 V_39 , void * V_40 )
{
int V_1 ;
if ( V_64 ) {
V_27 -> V_55 = F_59 ( struct V_13 ) ;
if ( ! V_27 -> V_55 )
return - V_74 ;
F_52 (cpu) {
struct V_13 * V_14 ;
V_14 = F_42 ( V_27 -> V_55 , V_1 ) ;
F_57 ( V_14 ) ;
}
V_27 -> V_32 = V_75 ;
} else {
struct V_58 * V_59 = & V_27 -> V_45 ;
V_59 -> V_62 = F_59 ( struct V_5 ) ;
if ( ! V_59 -> V_62 )
return - V_74 ;
F_52 (cpu) {
struct V_5 * V_6 ;
V_6 = F_42 ( V_59 -> V_62 , V_1 ) ;
F_54 ( V_6 , V_1 ) ;
}
F_57 ( & V_59 -> V_46 ) ;
V_27 -> V_32 = V_76 ;
}
V_27 -> V_64 = V_64 ;
V_27 -> V_39 = V_39 ;
V_27 -> V_40 = V_40 ;
V_27 -> V_51 = V_51 ;
return 0 ;
}
void F_60 ( struct V_26 * V_27 )
{
if ( V_27 -> V_64 )
F_61 ( V_27 -> V_55 ) ;
else
F_61 ( V_27 -> V_45 . V_62 ) ;
}
