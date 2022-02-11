static void F_1 ( struct V_1 * V_2 )
{
F_2 ( & V_2 -> V_3 ) ;
F_3 ( & V_2 -> V_4 ) ;
V_2 -> V_5 = NULL ;
}
static void F_4 ( struct V_1 * V_2 ,
struct V_6 * V_7 )
{
if ( ! F_5 ( & V_7 -> V_8 ) )
return;
F_6 ( & V_2 -> V_3 ) ;
F_7 ( & V_7 -> V_8 , & V_2 -> V_4 ) ;
F_8 ( & V_2 -> V_3 ) ;
}
static void F_9 ( struct V_1 * V_2 ,
struct V_6 * V_7 )
{
if ( F_5 ( & V_7 -> V_8 ) )
return;
F_6 ( & V_2 -> V_3 ) ;
F_10 ( & V_7 -> V_8 ) ;
if ( V_2 -> V_5 == V_7 )
V_2 -> V_5 = NULL ;
F_8 ( & V_2 -> V_3 ) ;
}
static struct V_6 *
F_11 ( struct V_1 * V_2 )
{
struct V_6 * V_7 ;
F_6 ( & V_2 -> V_3 ) ;
V_7 = V_2 -> V_5 ;
if ( V_7 ) {
F_12 (entity, &rq->entities, list) {
if ( F_13 ( V_7 ) ) {
V_2 -> V_5 = V_7 ;
F_8 ( & V_2 -> V_3 ) ;
return V_7 ;
}
}
}
F_14 (entity, &rq->entities, list) {
if ( F_13 ( V_7 ) ) {
V_2 -> V_5 = V_7 ;
F_8 ( & V_2 -> V_3 ) ;
return V_7 ;
}
if ( V_7 == V_2 -> V_5 )
break;
}
F_8 ( & V_2 -> V_3 ) ;
return NULL ;
}
int F_15 ( struct V_9 * V_10 ,
struct V_6 * V_7 ,
struct V_1 * V_2 ,
T_1 V_11 )
{
int V_12 ;
if ( ! ( V_10 && V_7 && V_2 ) )
return - V_13 ;
memset ( V_7 , 0 , sizeof( struct V_6 ) ) ;
F_3 ( & V_7 -> V_8 ) ;
V_7 -> V_2 = V_2 ;
V_7 -> V_10 = V_10 ;
F_2 ( & V_7 -> V_14 ) ;
V_12 = F_16 ( & V_7 -> V_15 , V_11 * sizeof( void * ) , V_16 ) ;
if ( V_12 )
return V_12 ;
F_17 ( & V_7 -> V_17 , 0 ) ;
V_7 -> V_18 = F_18 ( 2 ) ;
return 0 ;
}
static bool F_19 ( struct V_9 * V_10 ,
struct V_6 * V_7 )
{
return V_7 -> V_10 == V_10 &&
V_7 -> V_2 != NULL ;
}
static bool F_20 ( struct V_6 * V_7 )
{
F_21 () ;
if ( F_22 ( & V_7 -> V_15 ) )
return true ;
return false ;
}
static bool F_13 ( struct V_6 * V_7 )
{
if ( F_22 ( & V_7 -> V_15 ) )
return false ;
if ( F_23 ( V_7 -> V_19 ) )
return false ;
return true ;
}
void F_24 ( struct V_9 * V_10 ,
struct V_6 * V_7 )
{
struct V_1 * V_2 = V_7 -> V_2 ;
if ( ! F_19 ( V_10 , V_7 ) )
return;
F_25 ( V_10 -> V_20 , F_20 ( V_7 ) ) ;
F_9 ( V_2 , V_7 ) ;
F_26 ( & V_7 -> V_15 ) ;
}
static void F_27 ( struct V_21 * V_22 , struct V_23 * V_24 )
{
struct V_6 * V_7 =
F_28 ( V_24 , struct V_6 , V_24 ) ;
V_7 -> V_19 = NULL ;
F_29 ( V_22 ) ;
F_30 ( V_7 -> V_10 ) ;
}
static void F_31 ( struct V_21 * V_22 , struct V_23 * V_24 )
{
struct V_6 * V_7 =
F_28 ( V_24 , struct V_6 , V_24 ) ;
V_7 -> V_19 = NULL ;
F_29 ( V_22 ) ;
}
static bool F_32 ( struct V_6 * V_7 )
{
struct V_9 * V_10 = V_7 -> V_10 ;
struct V_21 * V_21 = V_7 -> V_19 ;
struct V_25 * V_26 ;
if ( V_21 -> V_27 == V_7 -> V_18 ) {
F_29 ( V_7 -> V_19 ) ;
return false ;
}
V_26 = F_33 ( V_21 ) ;
if ( V_26 && V_26 -> V_10 == V_10 ) {
V_21 = F_34 ( & V_26 -> V_28 ) ;
F_29 ( V_7 -> V_19 ) ;
V_7 -> V_19 = V_21 ;
if ( ! F_35 ( V_21 , & V_7 -> V_24 ,
F_31 ) )
return true ;
F_29 ( V_21 ) ;
return false ;
}
if ( ! F_35 ( V_7 -> V_19 , & V_7 -> V_24 ,
F_27 ) )
return true ;
F_29 ( V_7 -> V_19 ) ;
return false ;
}
static struct V_29 *
F_36 ( struct V_6 * V_7 )
{
struct V_9 * V_10 = V_7 -> V_10 ;
struct V_29 * V_30 ;
if ( ! F_37 ( & V_7 -> V_15 , & V_30 , sizeof( V_30 ) ) )
return NULL ;
while ( ( V_7 -> V_19 = V_10 -> V_31 -> V_19 ( V_30 ) ) )
if ( F_32 ( V_7 ) )
return NULL ;
return V_30 ;
}
static bool F_38 ( struct V_29 * V_30 )
{
struct V_9 * V_10 = V_30 -> V_10 ;
struct V_6 * V_7 = V_30 -> V_32 ;
bool V_33 , V_34 = false ;
F_6 ( & V_7 -> V_14 ) ;
V_33 = F_39 ( & V_7 -> V_15 , & V_30 ,
sizeof( V_30 ) ) == sizeof( V_30 ) ;
if ( V_33 && F_40 ( & V_7 -> V_15 ) == sizeof( V_30 ) )
V_34 = true ;
F_8 ( & V_7 -> V_14 ) ;
if ( V_34 ) {
F_4 ( V_7 -> V_2 , V_7 ) ;
F_30 ( V_10 ) ;
}
return V_33 ;
}
static void F_41 ( struct V_35 * V_36 )
{
struct V_29 * V_37 = F_28 ( V_36 , struct V_29 ,
V_38 ) ;
struct V_9 * V_10 = V_37 -> V_10 ;
F_6 ( & V_10 -> V_39 ) ;
F_10 ( & V_37 -> V_40 ) ;
if ( V_10 -> V_41 != V_42 ) {
struct V_29 * V_43 ;
F_8 ( & V_10 -> V_39 ) ;
F_42 ( & V_37 -> V_44 ) ;
F_6 ( & V_10 -> V_39 ) ;
V_43 = F_43 ( & V_10 -> V_45 ,
struct V_29 , V_40 ) ;
if ( V_43 )
F_44 ( & V_43 -> V_44 , V_10 -> V_41 ) ;
}
F_8 ( & V_10 -> V_39 ) ;
V_10 -> V_31 -> V_46 ( V_37 ) ;
}
static void F_45 ( struct V_21 * V_22 , struct V_23 * V_24 )
{
struct V_29 * V_47 = F_28 ( V_24 , struct V_29 ,
V_48 ) ;
F_46 ( & V_47 -> V_38 ) ;
}
static void F_47 ( struct V_29 * V_37 )
{
struct V_9 * V_10 = V_37 -> V_10 ;
F_6 ( & V_10 -> V_39 ) ;
F_7 ( & V_37 -> V_40 , & V_10 -> V_45 ) ;
if ( V_10 -> V_41 != V_42 &&
F_43 ( & V_10 -> V_45 ,
struct V_29 , V_40 ) == V_37 )
F_44 ( & V_37 -> V_44 , V_10 -> V_41 ) ;
F_8 ( & V_10 -> V_39 ) ;
}
static void F_48 ( struct V_35 * V_36 )
{
struct V_29 * V_47 = F_28 ( V_36 , struct V_29 ,
V_44 . V_36 ) ;
V_47 -> V_10 -> V_31 -> V_49 ( V_47 ) ;
}
void F_49 ( struct V_9 * V_10 )
{
struct V_29 * V_37 ;
F_6 ( & V_10 -> V_39 ) ;
F_50 (s_job, &sched->ring_mirror_list, node) {
if ( F_51 ( V_37 -> V_26 -> V_50 , & V_37 -> V_26 -> V_24 ) ) {
F_29 ( V_37 -> V_26 -> V_50 ) ;
V_37 -> V_26 -> V_50 = NULL ;
}
}
F_17 ( & V_10 -> V_51 , 0 ) ;
F_8 ( & V_10 -> V_39 ) ;
}
void F_52 ( struct V_9 * V_10 )
{
struct V_29 * V_37 , * V_52 ;
int V_12 ;
F_6 ( & V_10 -> V_39 ) ;
V_37 = F_43 ( & V_10 -> V_45 ,
struct V_29 , V_40 ) ;
if ( V_37 && V_10 -> V_41 != V_42 )
F_44 ( & V_37 -> V_44 , V_10 -> V_41 ) ;
F_53 (s_job, tmp, &sched->ring_mirror_list, node) {
struct V_25 * V_26 = V_37 -> V_26 ;
struct V_21 * V_21 ;
F_8 ( & V_10 -> V_39 ) ;
V_21 = V_10 -> V_31 -> V_53 ( V_37 ) ;
F_54 ( & V_10 -> V_51 ) ;
if ( V_21 ) {
V_26 -> V_50 = F_34 ( V_21 ) ;
V_12 = F_35 ( V_21 , & V_26 -> V_24 ,
V_54 ) ;
if ( V_12 == - V_55 )
V_54 ( V_21 , & V_26 -> V_24 ) ;
else if ( V_12 )
F_55 ( L_1 ,
V_12 ) ;
F_29 ( V_21 ) ;
} else {
F_55 ( L_2 ) ;
V_54 ( NULL , & V_26 -> V_24 ) ;
}
F_6 ( & V_10 -> V_39 ) ;
}
F_8 ( & V_10 -> V_39 ) ;
}
void F_56 ( struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_32 ;
F_57 ( V_30 ) ;
F_35 ( & V_30 -> V_26 -> V_56 , & V_30 -> V_48 ,
F_45 ) ;
F_25 ( V_7 -> V_10 -> V_20 ,
F_38 ( V_30 ) ) ;
}
int F_58 ( struct V_29 * V_47 ,
struct V_9 * V_10 ,
struct V_6 * V_7 ,
void * V_57 )
{
V_47 -> V_10 = V_10 ;
V_47 -> V_32 = V_7 ;
V_47 -> V_26 = F_59 ( V_7 , V_57 ) ;
if ( ! V_47 -> V_26 )
return - V_58 ;
F_60 ( & V_47 -> V_38 , F_41 ) ;
F_3 ( & V_47 -> V_40 ) ;
F_61 ( & V_47 -> V_44 , F_48 ) ;
return 0 ;
}
static bool F_62 ( struct V_9 * V_10 )
{
return F_63 ( & V_10 -> V_51 ) <
V_10 -> V_59 ;
}
static void F_30 ( struct V_9 * V_10 )
{
if ( F_62 ( V_10 ) )
F_64 ( & V_10 -> V_60 ) ;
}
static struct V_6 *
F_65 ( struct V_9 * V_10 )
{
struct V_6 * V_7 ;
int V_61 ;
if ( ! F_62 ( V_10 ) )
return NULL ;
for ( V_61 = 0 ; V_61 < V_62 ; V_61 ++ ) {
V_7 = F_11 ( & V_10 -> V_63 [ V_61 ] ) ;
if ( V_7 )
break;
}
return V_7 ;
}
static void V_54 ( struct V_21 * V_22 , struct V_23 * V_24 )
{
struct V_25 * V_26 =
F_28 ( V_24 , struct V_25 , V_24 ) ;
struct V_9 * V_10 = V_26 -> V_10 ;
F_66 ( & V_10 -> V_51 ) ;
F_67 ( V_26 ) ;
F_68 ( V_26 ) ;
F_29 ( & V_26 -> V_56 ) ;
F_64 ( & V_10 -> V_60 ) ;
}
static bool F_69 ( struct V_9 * V_10 )
{
if ( F_70 () ) {
F_71 () ;
return true ;
}
return false ;
}
static int F_72 ( void * V_64 )
{
struct V_65 V_66 = { . V_67 = 1 } ;
struct V_9 * V_10 = (struct V_9 * ) V_64 ;
int V_12 , V_68 ;
F_73 ( V_69 , V_70 , & V_66 ) ;
while ( ! F_74 () ) {
struct V_6 * V_7 = NULL ;
struct V_25 * V_26 ;
struct V_29 * V_30 ;
struct V_21 * V_21 ;
F_75 ( V_10 -> V_60 ,
( ! F_69 ( V_10 ) &&
( V_7 = F_65 ( V_10 ) ) ) ||
F_74 () ) ;
if ( ! V_7 )
continue;
V_30 = F_36 ( V_7 ) ;
if ( ! V_30 )
continue;
V_26 = V_30 -> V_26 ;
F_54 ( & V_10 -> V_51 ) ;
F_47 ( V_30 ) ;
V_21 = V_10 -> V_31 -> V_53 ( V_30 ) ;
F_76 ( V_26 ) ;
if ( V_21 ) {
V_26 -> V_50 = F_34 ( V_21 ) ;
V_12 = F_35 ( V_21 , & V_26 -> V_24 ,
V_54 ) ;
if ( V_12 == - V_55 )
V_54 ( V_21 , & V_26 -> V_24 ) ;
else if ( V_12 )
F_55 ( L_1 ,
V_12 ) ;
F_29 ( V_21 ) ;
} else {
F_55 ( L_2 ) ;
V_54 ( NULL , & V_26 -> V_24 ) ;
}
V_68 = F_77 ( & V_7 -> V_15 , & V_30 ,
sizeof( V_30 ) ) ;
F_78 ( V_68 != sizeof( V_30 ) ) ;
F_79 ( & V_10 -> V_20 ) ;
}
return 0 ;
}
int F_80 ( struct V_9 * V_10 ,
const struct V_71 * V_31 ,
unsigned V_72 , long V_41 , const char * V_73 )
{
int V_61 ;
V_10 -> V_31 = V_31 ;
V_10 -> V_59 = V_72 ;
V_10 -> V_73 = V_73 ;
V_10 -> V_41 = V_41 ;
for ( V_61 = 0 ; V_61 < V_62 ; V_61 ++ )
F_1 ( & V_10 -> V_63 [ V_61 ] ) ;
F_81 ( & V_10 -> V_60 ) ;
F_81 ( & V_10 -> V_20 ) ;
F_3 ( & V_10 -> V_45 ) ;
F_2 ( & V_10 -> V_39 ) ;
F_17 ( & V_10 -> V_51 , 0 ) ;
if ( F_82 ( & V_74 ) == 1 ) {
V_75 = F_83 (
L_3 , sizeof( struct V_25 ) , 0 ,
V_76 , NULL ) ;
if ( ! V_75 )
return - V_58 ;
}
V_10 -> V_77 = F_84 ( F_72 , V_10 , V_10 -> V_73 ) ;
if ( F_85 ( V_10 -> V_77 ) ) {
F_55 ( L_4 , V_73 ) ;
return F_86 ( V_10 -> V_77 ) ;
}
return 0 ;
}
void F_87 ( struct V_9 * V_10 )
{
if ( V_10 -> V_77 )
F_88 ( V_10 -> V_77 ) ;
if ( F_89 ( & V_74 ) )
F_90 ( V_75 ) ;
}
