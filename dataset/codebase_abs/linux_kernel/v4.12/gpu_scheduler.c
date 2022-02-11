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
bool F_32 ( struct V_21 * V_25 ,
struct V_6 * V_7 )
{
struct V_9 * V_10 = V_7 -> V_10 ;
struct V_26 * V_27 ;
if ( ! V_25 || F_33 ( V_25 ) )
return false ;
if ( V_25 -> V_28 == V_7 -> V_18 )
return true ;
V_27 = F_34 ( V_25 ) ;
if ( V_27 && V_27 -> V_10 == V_10 )
return true ;
return false ;
}
static bool F_35 ( struct V_6 * V_7 )
{
struct V_9 * V_10 = V_7 -> V_10 ;
struct V_21 * V_25 = V_7 -> V_19 ;
struct V_26 * V_27 ;
if ( V_25 -> V_28 == V_7 -> V_18 ) {
F_29 ( V_7 -> V_19 ) ;
return false ;
}
V_27 = F_34 ( V_25 ) ;
if ( V_27 && V_27 -> V_10 == V_10 ) {
V_25 = F_36 ( & V_27 -> V_29 ) ;
F_29 ( V_7 -> V_19 ) ;
V_7 -> V_19 = V_25 ;
if ( ! F_37 ( V_25 , & V_7 -> V_24 ,
F_31 ) )
return true ;
F_29 ( V_25 ) ;
return false ;
}
if ( ! F_37 ( V_7 -> V_19 , & V_7 -> V_24 ,
F_27 ) )
return true ;
F_29 ( V_7 -> V_19 ) ;
return false ;
}
static struct V_30 *
F_38 ( struct V_6 * V_7 )
{
struct V_9 * V_10 = V_7 -> V_10 ;
struct V_30 * V_31 ;
if ( ! F_39 ( & V_7 -> V_15 , & V_31 , sizeof( V_31 ) ) )
return NULL ;
while ( ( V_7 -> V_19 = V_10 -> V_32 -> V_19 ( V_31 ) ) )
if ( F_35 ( V_7 ) )
return NULL ;
return V_31 ;
}
static bool F_40 ( struct V_30 * V_31 )
{
struct V_9 * V_10 = V_31 -> V_10 ;
struct V_6 * V_7 = V_31 -> V_33 ;
bool V_34 , V_35 = false ;
F_6 ( & V_7 -> V_14 ) ;
V_34 = F_41 ( & V_7 -> V_15 , & V_31 ,
sizeof( V_31 ) ) == sizeof( V_31 ) ;
if ( V_34 && F_42 ( & V_7 -> V_15 ) == sizeof( V_31 ) )
V_35 = true ;
F_8 ( & V_7 -> V_14 ) ;
if ( V_35 ) {
F_4 ( V_7 -> V_2 , V_7 ) ;
F_30 ( V_10 ) ;
}
return V_34 ;
}
static void F_43 ( struct V_36 * V_37 )
{
struct V_30 * V_38 = F_28 ( V_37 , struct V_30 ,
V_39 ) ;
struct V_9 * V_10 = V_38 -> V_10 ;
F_6 ( & V_10 -> V_40 ) ;
F_10 ( & V_38 -> V_41 ) ;
if ( V_10 -> V_42 != V_43 ) {
struct V_30 * V_44 ;
F_8 ( & V_10 -> V_40 ) ;
F_44 ( & V_38 -> V_45 ) ;
F_6 ( & V_10 -> V_40 ) ;
V_44 = F_45 ( & V_10 -> V_46 ,
struct V_30 , V_41 ) ;
if ( V_44 )
F_46 ( & V_44 -> V_45 , V_10 -> V_42 ) ;
}
F_8 ( & V_10 -> V_40 ) ;
V_10 -> V_32 -> V_47 ( V_38 ) ;
}
static void F_47 ( struct V_21 * V_22 ,
struct V_23 * V_24 )
{
struct V_30 * V_48 = F_28 ( V_24 , struct V_30 ,
V_49 ) ;
F_48 ( & V_48 -> V_39 ) ;
}
static void F_49 ( struct V_30 * V_38 )
{
struct V_9 * V_10 = V_38 -> V_10 ;
F_6 ( & V_10 -> V_40 ) ;
F_7 ( & V_38 -> V_41 , & V_10 -> V_46 ) ;
if ( V_10 -> V_42 != V_43 &&
F_45 ( & V_10 -> V_46 ,
struct V_30 , V_41 ) == V_38 )
F_46 ( & V_38 -> V_45 , V_10 -> V_42 ) ;
F_8 ( & V_10 -> V_40 ) ;
}
static void F_50 ( struct V_36 * V_37 )
{
struct V_30 * V_48 = F_28 ( V_37 , struct V_30 ,
V_45 . V_37 ) ;
V_48 -> V_10 -> V_32 -> V_50 ( V_48 ) ;
}
void F_51 ( struct V_9 * V_10 )
{
struct V_30 * V_38 ;
F_6 ( & V_10 -> V_40 ) ;
F_52 (s_job, &sched->ring_mirror_list, node) {
if ( V_38 -> V_27 -> V_51 &&
F_53 ( V_38 -> V_27 -> V_51 ,
& V_38 -> V_27 -> V_24 ) ) {
F_29 ( V_38 -> V_27 -> V_51 ) ;
V_38 -> V_27 -> V_51 = NULL ;
}
}
F_17 ( & V_10 -> V_52 , 0 ) ;
F_8 ( & V_10 -> V_40 ) ;
}
void F_54 ( struct V_9 * V_10 )
{
struct V_30 * V_38 , * V_53 ;
int V_12 ;
F_6 ( & V_10 -> V_40 ) ;
V_38 = F_45 ( & V_10 -> V_46 ,
struct V_30 , V_41 ) ;
if ( V_38 && V_10 -> V_42 != V_43 )
F_46 ( & V_38 -> V_45 , V_10 -> V_42 ) ;
F_55 (s_job, tmp, &sched->ring_mirror_list, node) {
struct V_26 * V_27 = V_38 -> V_27 ;
struct V_21 * V_25 ;
F_8 ( & V_10 -> V_40 ) ;
V_25 = V_10 -> V_32 -> V_54 ( V_38 ) ;
F_56 ( & V_10 -> V_52 ) ;
if ( V_25 ) {
V_27 -> V_51 = F_36 ( V_25 ) ;
V_12 = F_37 ( V_25 , & V_27 -> V_24 ,
V_55 ) ;
if ( V_12 == - V_56 )
V_55 ( V_25 , & V_27 -> V_24 ) ;
else if ( V_12 )
F_57 ( L_1 ,
V_12 ) ;
F_29 ( V_25 ) ;
} else {
F_57 ( L_2 ) ;
V_55 ( NULL , & V_27 -> V_24 ) ;
}
F_6 ( & V_10 -> V_40 ) ;
}
F_8 ( & V_10 -> V_40 ) ;
}
void F_58 ( struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_33 ;
F_59 ( V_31 ) ;
F_37 ( & V_31 -> V_27 -> V_57 , & V_31 -> V_49 ,
F_47 ) ;
F_25 ( V_7 -> V_10 -> V_20 ,
F_40 ( V_31 ) ) ;
}
int F_60 ( struct V_30 * V_48 ,
struct V_9 * V_10 ,
struct V_6 * V_7 ,
void * V_58 )
{
V_48 -> V_10 = V_10 ;
V_48 -> V_33 = V_7 ;
V_48 -> V_27 = F_61 ( V_7 , V_58 ) ;
if ( ! V_48 -> V_27 )
return - V_59 ;
V_48 -> V_60 = F_62 ( & V_10 -> V_61 ) ;
F_63 ( & V_48 -> V_39 , F_43 ) ;
F_3 ( & V_48 -> V_41 ) ;
F_64 ( & V_48 -> V_45 , F_50 ) ;
return 0 ;
}
static bool F_65 ( struct V_9 * V_10 )
{
return F_66 ( & V_10 -> V_52 ) <
V_10 -> V_62 ;
}
static void F_30 ( struct V_9 * V_10 )
{
if ( F_65 ( V_10 ) )
F_67 ( & V_10 -> V_63 ) ;
}
static struct V_6 *
F_68 ( struct V_9 * V_10 )
{
struct V_6 * V_7 ;
int V_64 ;
if ( ! F_65 ( V_10 ) )
return NULL ;
for ( V_64 = V_65 - 1 ; V_64 >= V_66 ; V_64 -- ) {
V_7 = F_11 ( & V_10 -> V_67 [ V_64 ] ) ;
if ( V_7 )
break;
}
return V_7 ;
}
static void V_55 ( struct V_21 * V_22 , struct V_23 * V_24 )
{
struct V_26 * V_27 =
F_28 ( V_24 , struct V_26 , V_24 ) ;
struct V_9 * V_10 = V_27 -> V_10 ;
F_69 ( & V_10 -> V_52 ) ;
F_70 ( V_27 ) ;
F_71 ( V_27 ) ;
F_29 ( & V_27 -> V_57 ) ;
F_67 ( & V_10 -> V_63 ) ;
}
static bool F_72 ( struct V_9 * V_10 )
{
if ( F_73 () ) {
F_74 () ;
return true ;
}
return false ;
}
static int F_75 ( void * V_68 )
{
struct V_69 V_70 = { . V_71 = 1 } ;
struct V_9 * V_10 = (struct V_9 * ) V_68 ;
int V_12 , V_72 ;
F_76 ( V_73 , V_74 , & V_70 ) ;
while ( ! F_77 () ) {
struct V_6 * V_7 = NULL ;
struct V_26 * V_27 ;
struct V_30 * V_31 ;
struct V_21 * V_25 ;
F_78 ( V_10 -> V_63 ,
( ! F_72 ( V_10 ) &&
( V_7 = F_68 ( V_10 ) ) ) ||
F_77 () ) ;
if ( ! V_7 )
continue;
V_31 = F_38 ( V_7 ) ;
if ( ! V_31 )
continue;
V_27 = V_31 -> V_27 ;
F_56 ( & V_10 -> V_52 ) ;
F_49 ( V_31 ) ;
V_25 = V_10 -> V_32 -> V_54 ( V_31 ) ;
F_79 ( V_27 ) ;
if ( V_25 ) {
V_27 -> V_51 = F_36 ( V_25 ) ;
V_12 = F_37 ( V_25 , & V_27 -> V_24 ,
V_55 ) ;
if ( V_12 == - V_56 )
V_55 ( V_25 , & V_27 -> V_24 ) ;
else if ( V_12 )
F_57 ( L_1 ,
V_12 ) ;
F_29 ( V_25 ) ;
} else {
F_57 ( L_2 ) ;
V_55 ( NULL , & V_27 -> V_24 ) ;
}
V_72 = F_80 ( & V_7 -> V_15 , & V_31 ,
sizeof( V_31 ) ) ;
F_81 ( V_72 != sizeof( V_31 ) ) ;
F_82 ( & V_10 -> V_20 ) ;
}
return 0 ;
}
int F_83 ( struct V_9 * V_10 ,
const struct V_75 * V_32 ,
unsigned V_76 , long V_42 , const char * V_77 )
{
int V_64 ;
V_10 -> V_32 = V_32 ;
V_10 -> V_62 = V_76 ;
V_10 -> V_77 = V_77 ;
V_10 -> V_42 = V_42 ;
for ( V_64 = V_66 ; V_64 < V_65 ; V_64 ++ )
F_1 ( & V_10 -> V_67 [ V_64 ] ) ;
F_84 ( & V_10 -> V_63 ) ;
F_84 ( & V_10 -> V_20 ) ;
F_3 ( & V_10 -> V_46 ) ;
F_2 ( & V_10 -> V_40 ) ;
F_17 ( & V_10 -> V_52 , 0 ) ;
F_85 ( & V_10 -> V_61 , 0 ) ;
V_10 -> V_78 = F_86 ( F_75 , V_10 , V_10 -> V_77 ) ;
if ( F_87 ( V_10 -> V_78 ) ) {
F_57 ( L_3 , V_77 ) ;
return F_88 ( V_10 -> V_78 ) ;
}
return 0 ;
}
void F_89 ( struct V_9 * V_10 )
{
if ( V_10 -> V_78 )
F_90 ( V_10 -> V_78 ) ;
}
