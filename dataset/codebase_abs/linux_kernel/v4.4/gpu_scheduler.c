static void F_1 ( struct V_1 * V_2 )
{
F_2 ( & V_2 -> V_3 ) ;
F_3 ( & V_2 -> V_4 ) ;
V_2 -> V_5 = NULL ;
}
static void F_4 ( struct V_1 * V_2 ,
struct V_6 * V_7 )
{
F_5 ( & V_2 -> V_3 ) ;
F_6 ( & V_7 -> V_8 , & V_2 -> V_4 ) ;
F_7 ( & V_2 -> V_3 ) ;
}
static void F_8 ( struct V_1 * V_2 ,
struct V_6 * V_7 )
{
F_5 ( & V_2 -> V_3 ) ;
F_9 ( & V_7 -> V_8 ) ;
if ( V_2 -> V_5 == V_7 )
V_2 -> V_5 = NULL ;
F_7 ( & V_2 -> V_3 ) ;
}
static struct V_6 *
F_10 ( struct V_1 * V_2 )
{
struct V_6 * V_7 ;
F_5 ( & V_2 -> V_3 ) ;
V_7 = V_2 -> V_5 ;
if ( V_7 ) {
F_11 (entity, &rq->entities, list) {
if ( F_12 ( V_7 ) ) {
V_2 -> V_5 = V_7 ;
F_7 ( & V_2 -> V_3 ) ;
return V_7 ;
}
}
}
F_13 (entity, &rq->entities, list) {
if ( F_12 ( V_7 ) ) {
V_2 -> V_5 = V_7 ;
F_7 ( & V_2 -> V_3 ) ;
return V_7 ;
}
if ( V_7 == V_2 -> V_5 )
break;
}
F_7 ( & V_2 -> V_3 ) ;
return NULL ;
}
int F_14 ( struct V_9 * V_10 ,
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
V_12 = F_15 ( & V_7 -> V_15 , V_11 * sizeof( void * ) , V_16 ) ;
if ( V_12 )
return V_12 ;
F_16 ( & V_7 -> V_17 , 0 ) ;
V_7 -> V_18 = F_17 ( 1 ) ;
F_4 ( V_2 , V_7 ) ;
return 0 ;
}
static bool F_18 ( struct V_9 * V_10 ,
struct V_6 * V_7 )
{
return V_7 -> V_10 == V_10 &&
V_7 -> V_2 != NULL ;
}
static bool F_19 ( struct V_6 * V_7 )
{
F_20 () ;
if ( F_21 ( & V_7 -> V_15 ) )
return true ;
return false ;
}
static bool F_12 ( struct V_6 * V_7 )
{
if ( F_21 ( & V_7 -> V_15 ) )
return false ;
if ( F_22 ( V_7 -> V_19 ) )
return false ;
return true ;
}
void F_23 ( struct V_9 * V_10 ,
struct V_6 * V_7 )
{
struct V_1 * V_2 = V_7 -> V_2 ;
if ( ! F_18 ( V_10 , V_7 ) )
return;
F_24 ( V_10 -> V_20 , F_19 ( V_7 ) ) ;
F_8 ( V_2 , V_7 ) ;
F_25 ( & V_7 -> V_15 ) ;
}
static void F_26 ( struct V_21 * V_22 , struct V_23 * V_24 )
{
struct V_6 * V_7 =
F_27 ( V_24 , struct V_6 , V_24 ) ;
V_7 -> V_19 = NULL ;
F_28 ( V_22 ) ;
F_29 ( V_7 -> V_10 ) ;
}
static bool F_30 ( struct V_6 * V_7 )
{
struct V_9 * V_10 = V_7 -> V_10 ;
struct V_21 * V_21 = V_7 -> V_19 ;
struct V_25 * V_26 ;
if ( V_21 -> V_27 == V_7 -> V_18 ) {
F_28 ( V_7 -> V_19 ) ;
return false ;
}
V_26 = F_31 ( V_21 ) ;
if ( V_26 && V_26 -> V_10 == V_10 ) {
if ( F_32 ( V_28 , & V_21 -> V_29 ) ) {
F_28 ( V_7 -> V_19 ) ;
return false ;
}
V_7 -> V_24 . V_30 = F_26 ;
F_6 ( & V_7 -> V_24 . V_31 , & V_26 -> V_32 ) ;
return true ;
}
if ( ! F_33 ( V_7 -> V_19 , & V_7 -> V_24 ,
F_26 ) )
return true ;
F_28 ( V_7 -> V_19 ) ;
return false ;
}
static struct V_33 *
F_34 ( struct V_6 * V_7 )
{
struct V_9 * V_10 = V_7 -> V_10 ;
struct V_33 * V_34 ;
if ( ! F_35 ( & V_7 -> V_15 , & V_34 , sizeof( V_34 ) ) )
return NULL ;
while ( ( V_7 -> V_19 = V_10 -> V_35 -> V_19 ( V_34 ) ) )
if ( F_30 ( V_7 ) )
return NULL ;
return V_34 ;
}
static bool F_36 ( struct V_33 * V_34 )
{
struct V_9 * V_10 = V_34 -> V_10 ;
struct V_6 * V_7 = V_34 -> V_36 ;
bool V_37 , V_38 = false ;
F_5 ( & V_7 -> V_14 ) ;
V_37 = F_37 ( & V_7 -> V_15 , & V_34 ,
sizeof( V_34 ) ) == sizeof( V_34 ) ;
if ( V_37 && F_38 ( & V_7 -> V_15 ) == sizeof( V_34 ) )
V_38 = true ;
F_7 ( & V_7 -> V_14 ) ;
if ( V_38 )
F_29 ( V_10 ) ;
return V_37 ;
}
void F_39 ( struct V_33 * V_34 )
{
struct V_6 * V_7 = V_34 -> V_36 ;
F_40 ( V_34 ) ;
F_24 ( V_7 -> V_10 -> V_20 ,
F_36 ( V_34 ) ) ;
}
static bool F_41 ( struct V_9 * V_10 )
{
return F_42 ( & V_10 -> V_39 ) <
V_10 -> V_40 ;
}
static void F_29 ( struct V_9 * V_10 )
{
if ( F_41 ( V_10 ) )
F_43 ( & V_10 -> V_41 ) ;
}
static struct V_6 *
F_44 ( struct V_9 * V_10 )
{
struct V_6 * V_7 ;
if ( ! F_41 ( V_10 ) )
return NULL ;
V_7 = F_10 ( & V_10 -> V_42 ) ;
if ( V_7 == NULL )
V_7 = F_10 ( & V_10 -> V_43 ) ;
return V_7 ;
}
static void F_45 ( struct V_21 * V_22 , struct V_23 * V_24 )
{
struct V_25 * V_26 =
F_27 ( V_24 , struct V_25 , V_24 ) ;
struct V_9 * V_10 = V_26 -> V_10 ;
unsigned long V_29 ;
F_46 ( & V_10 -> V_39 ) ;
F_47 ( V_26 ) ;
if ( V_10 -> V_44 != V_45 ) {
F_48 ( & V_26 -> V_46 ) ;
F_49 ( & V_10 -> V_47 , V_29 ) ;
F_9 ( & V_26 -> V_8 ) ;
F_50 ( & V_10 -> V_47 , V_29 ) ;
}
F_51 ( V_26 ) ;
F_28 ( & V_26 -> V_48 ) ;
F_43 ( & V_10 -> V_41 ) ;
}
static void F_52 ( struct V_49 * V_50 )
{
struct V_25 * V_26 =
F_27 ( V_50 , struct V_25 , V_46 . V_50 ) ;
struct V_9 * V_10 = V_26 -> V_10 ;
struct V_25 * V_7 , * V_51 ;
unsigned long V_29 ;
F_53 ( L_1 , V_10 -> V_52 ) ;
F_49 ( & V_10 -> V_47 , V_29 ) ;
F_54 (entity, tmp, &sched->fence_list, list) {
F_53 ( L_2 , V_7 -> V_48 . V_53 ) ;
F_48 ( & V_7 -> V_46 ) ;
F_9 ( & V_7 -> V_8 ) ;
F_28 ( & V_7 -> V_48 ) ;
}
F_50 ( & V_10 -> V_47 , V_29 ) ;
}
static int F_55 ( void * V_54 )
{
struct V_55 V_56 = { . V_57 = 1 } ;
struct V_9 * V_10 = (struct V_9 * ) V_54 ;
int V_12 , V_58 ;
F_2 ( & V_10 -> V_47 ) ;
F_3 ( & V_10 -> V_59 ) ;
F_56 ( V_60 , V_61 , & V_56 ) ;
while ( ! F_57 () ) {
struct V_6 * V_7 ;
struct V_25 * V_26 ;
struct V_33 * V_34 ;
struct V_21 * V_21 ;
unsigned long V_29 ;
F_58 ( V_10 -> V_41 ,
( V_7 = F_44 ( V_10 ) ) ||
F_57 () ) ;
if ( ! V_7 )
continue;
V_34 = F_34 ( V_7 ) ;
if ( ! V_34 )
continue;
V_26 = V_34 -> V_26 ;
if ( V_10 -> V_44 != V_45 ) {
F_59 ( & V_26 -> V_46 , F_52 ) ;
F_60 ( & V_26 -> V_46 , V_10 -> V_44 ) ;
F_49 ( & V_10 -> V_47 , V_29 ) ;
F_6 ( & V_26 -> V_8 , & V_10 -> V_59 ) ;
F_50 ( & V_10 -> V_47 , V_29 ) ;
}
F_61 ( & V_10 -> V_39 ) ;
V_21 = V_10 -> V_35 -> V_62 ( V_34 ) ;
F_62 ( V_26 ) ;
if ( V_21 ) {
V_12 = F_33 ( V_21 , & V_26 -> V_24 ,
F_45 ) ;
if ( V_12 == - V_63 )
F_45 ( V_21 , & V_26 -> V_24 ) ;
else if ( V_12 )
F_53 ( L_3 , V_12 ) ;
F_28 ( V_21 ) ;
} else {
F_53 ( L_4 ) ;
F_45 ( NULL , & V_26 -> V_24 ) ;
}
V_58 = F_63 ( & V_7 -> V_15 , & V_34 ,
sizeof( V_34 ) ) ;
F_64 ( V_58 != sizeof( V_34 ) ) ;
F_65 ( & V_10 -> V_20 ) ;
}
return 0 ;
}
int F_66 ( struct V_9 * V_10 ,
struct V_64 * V_35 ,
unsigned V_65 , long V_44 , const char * V_52 )
{
V_10 -> V_35 = V_35 ;
V_10 -> V_40 = V_65 ;
V_10 -> V_52 = V_52 ;
V_10 -> V_44 = V_44 ;
F_1 ( & V_10 -> V_43 ) ;
F_1 ( & V_10 -> V_42 ) ;
F_67 ( & V_10 -> V_41 ) ;
F_67 ( & V_10 -> V_20 ) ;
F_16 ( & V_10 -> V_39 , 0 ) ;
if ( F_68 ( & V_66 ) == 1 ) {
V_67 = F_69 (
L_5 , sizeof( struct V_25 ) , 0 ,
V_68 , NULL ) ;
if ( ! V_67 )
return - V_69 ;
}
V_10 -> V_70 = F_70 ( F_55 , V_10 , V_10 -> V_52 ) ;
if ( F_71 ( V_10 -> V_70 ) ) {
F_53 ( L_6 , V_52 ) ;
return F_72 ( V_10 -> V_70 ) ;
}
return 0 ;
}
void F_73 ( struct V_9 * V_10 )
{
if ( V_10 -> V_70 )
F_74 ( V_10 -> V_70 ) ;
if ( F_75 ( & V_66 ) )
F_76 ( V_67 ) ;
}
