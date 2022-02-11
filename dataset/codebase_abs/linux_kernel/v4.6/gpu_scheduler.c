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
V_7 -> V_18 = F_18 ( 1 ) ;
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
if ( F_34 ( V_28 , & V_21 -> V_29 ) ) {
F_29 ( V_7 -> V_19 ) ;
return false ;
}
V_7 -> V_24 . V_30 = F_31 ;
F_7 ( & V_7 -> V_24 . V_31 , & V_26 -> V_32 ) ;
return true ;
}
if ( ! F_35 ( V_7 -> V_19 , & V_7 -> V_24 ,
F_27 ) )
return true ;
F_29 ( V_7 -> V_19 ) ;
return false ;
}
static struct V_33 *
F_36 ( struct V_6 * V_7 )
{
struct V_9 * V_10 = V_7 -> V_10 ;
struct V_33 * V_34 ;
if ( ! F_37 ( & V_7 -> V_15 , & V_34 , sizeof( V_34 ) ) )
return NULL ;
while ( ( V_7 -> V_19 = V_10 -> V_35 -> V_19 ( V_34 ) ) )
if ( F_32 ( V_7 ) )
return NULL ;
return V_34 ;
}
static bool F_38 ( struct V_33 * V_34 )
{
struct V_9 * V_10 = V_34 -> V_10 ;
struct V_6 * V_7 = V_34 -> V_36 ;
bool V_37 , V_38 = false ;
F_6 ( & V_7 -> V_14 ) ;
V_37 = F_39 ( & V_7 -> V_15 , & V_34 ,
sizeof( V_34 ) ) == sizeof( V_34 ) ;
if ( V_37 && F_40 ( & V_7 -> V_15 ) == sizeof( V_34 ) )
V_38 = true ;
F_8 ( & V_7 -> V_14 ) ;
if ( V_38 ) {
F_4 ( V_7 -> V_2 , V_7 ) ;
F_30 ( V_10 ) ;
}
return V_37 ;
}
void F_41 ( struct V_33 * V_34 )
{
struct V_6 * V_7 = V_34 -> V_36 ;
F_42 ( V_34 ) ;
F_25 ( V_7 -> V_10 -> V_20 ,
F_38 ( V_34 ) ) ;
}
static bool F_43 ( struct V_9 * V_10 )
{
return F_44 ( & V_10 -> V_39 ) <
V_10 -> V_40 ;
}
static void F_30 ( struct V_9 * V_10 )
{
if ( F_43 ( V_10 ) )
F_45 ( & V_10 -> V_41 ) ;
}
static struct V_6 *
F_46 ( struct V_9 * V_10 )
{
struct V_6 * V_7 ;
int V_42 ;
if ( ! F_43 ( V_10 ) )
return NULL ;
for ( V_42 = 0 ; V_42 < V_43 ; V_42 ++ ) {
V_7 = F_11 ( & V_10 -> V_44 [ V_42 ] ) ;
if ( V_7 )
break;
}
return V_7 ;
}
static void F_47 ( struct V_21 * V_22 , struct V_23 * V_24 )
{
struct V_25 * V_26 =
F_28 ( V_24 , struct V_25 , V_24 ) ;
struct V_9 * V_10 = V_26 -> V_10 ;
unsigned long V_29 ;
F_48 ( & V_10 -> V_39 ) ;
F_49 ( V_26 ) ;
if ( V_10 -> V_45 != V_46 ) {
F_50 ( & V_26 -> V_47 ) ;
F_51 ( & V_10 -> V_48 , V_29 ) ;
F_10 ( & V_26 -> V_8 ) ;
F_52 ( & V_10 -> V_48 , V_29 ) ;
}
F_53 ( V_26 ) ;
F_29 ( & V_26 -> V_49 ) ;
F_45 ( & V_10 -> V_41 ) ;
}
static void F_54 ( struct V_50 * V_51 )
{
struct V_25 * V_26 =
F_28 ( V_51 , struct V_25 , V_47 . V_51 ) ;
struct V_9 * V_10 = V_26 -> V_10 ;
struct V_25 * V_7 , * V_52 ;
unsigned long V_29 ;
F_55 ( L_1 , V_10 -> V_53 ) ;
F_51 ( & V_10 -> V_48 , V_29 ) ;
F_56 (entity, tmp, &sched->fence_list, list) {
F_55 ( L_2 , V_7 -> V_49 . V_54 ) ;
F_50 ( & V_7 -> V_47 ) ;
F_10 ( & V_7 -> V_8 ) ;
F_29 ( & V_7 -> V_49 ) ;
}
F_52 ( & V_10 -> V_48 , V_29 ) ;
}
static int F_57 ( void * V_55 )
{
struct V_56 V_57 = { . V_58 = 1 } ;
struct V_9 * V_10 = (struct V_9 * ) V_55 ;
int V_12 , V_59 ;
F_2 ( & V_10 -> V_48 ) ;
F_3 ( & V_10 -> V_60 ) ;
F_58 ( V_61 , V_62 , & V_57 ) ;
while ( ! F_59 () ) {
struct V_6 * V_7 ;
struct V_25 * V_26 ;
struct V_33 * V_34 ;
struct V_21 * V_21 ;
unsigned long V_29 ;
F_60 ( V_10 -> V_41 ,
( V_7 = F_46 ( V_10 ) ) ||
F_59 () ) ;
if ( ! V_7 )
continue;
V_34 = F_36 ( V_7 ) ;
if ( ! V_34 )
continue;
V_26 = V_34 -> V_26 ;
if ( V_10 -> V_45 != V_46 ) {
F_61 ( & V_26 -> V_47 , F_54 ) ;
F_62 ( & V_26 -> V_47 , V_10 -> V_45 ) ;
F_51 ( & V_10 -> V_48 , V_29 ) ;
F_7 ( & V_26 -> V_8 , & V_10 -> V_60 ) ;
F_52 ( & V_10 -> V_48 , V_29 ) ;
}
F_63 ( & V_10 -> V_39 ) ;
V_21 = V_10 -> V_35 -> V_63 ( V_34 ) ;
F_64 ( V_26 ) ;
if ( V_21 ) {
V_12 = F_35 ( V_21 , & V_26 -> V_24 ,
F_47 ) ;
if ( V_12 == - V_64 )
F_47 ( V_21 , & V_26 -> V_24 ) ;
else if ( V_12 )
F_55 ( L_3 , V_12 ) ;
F_29 ( V_21 ) ;
} else {
F_55 ( L_4 ) ;
F_47 ( NULL , & V_26 -> V_24 ) ;
}
V_59 = F_65 ( & V_7 -> V_15 , & V_34 ,
sizeof( V_34 ) ) ;
F_66 ( V_59 != sizeof( V_34 ) ) ;
F_67 ( & V_10 -> V_20 ) ;
}
return 0 ;
}
int F_68 ( struct V_9 * V_10 ,
struct V_65 * V_35 ,
unsigned V_66 , long V_45 , const char * V_53 )
{
int V_42 ;
V_10 -> V_35 = V_35 ;
V_10 -> V_40 = V_66 ;
V_10 -> V_53 = V_53 ;
V_10 -> V_45 = V_45 ;
for ( V_42 = 0 ; V_42 < V_43 ; V_42 ++ )
F_1 ( & V_10 -> V_44 [ V_42 ] ) ;
F_69 ( & V_10 -> V_41 ) ;
F_69 ( & V_10 -> V_20 ) ;
F_17 ( & V_10 -> V_39 , 0 ) ;
if ( F_70 ( & V_67 ) == 1 ) {
V_68 = F_71 (
L_5 , sizeof( struct V_25 ) , 0 ,
V_69 , NULL ) ;
if ( ! V_68 )
return - V_70 ;
}
V_10 -> V_71 = F_72 ( F_57 , V_10 , V_10 -> V_53 ) ;
if ( F_73 ( V_10 -> V_71 ) ) {
F_55 ( L_6 , V_53 ) ;
return F_74 ( V_10 -> V_71 ) ;
}
return 0 ;
}
void F_75 ( struct V_9 * V_10 )
{
if ( V_10 -> V_71 )
F_76 ( V_10 -> V_71 ) ;
if ( F_77 ( & V_67 ) )
F_78 ( V_68 ) ;
}
