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
static void F_41 ( struct V_21 * V_22 , struct V_23 * V_24 ) {
struct V_33 * V_39 = F_28 ( V_24 , struct V_33 , V_40 ) ;
F_42 ( & V_39 -> V_41 ) ;
}
void F_43 ( struct V_33 * V_42 )
{
struct V_33 * V_43 ;
struct V_9 * V_10 = V_42 -> V_10 ;
if ( V_10 -> V_44 != V_45 ) {
if ( F_44 ( & V_42 -> V_46 ) )
F_45 ( V_42 ) ;
V_43 = F_46 ( & V_10 -> V_47 ,
struct V_33 , V_31 ) ;
if ( V_43 ) {
F_47 ( & V_43 -> V_46 , V_42 -> V_48 ) ;
F_48 ( V_43 ) ;
F_49 ( & V_43 -> V_46 , V_10 -> V_44 ) ;
}
}
}
void F_50 ( struct V_33 * V_42 )
{
struct V_9 * V_10 = V_42 -> V_10 ;
if ( V_10 -> V_44 != V_45 &&
F_46 ( & V_10 -> V_47 , struct V_33 , V_31 ) == V_42 )
{
F_47 ( & V_42 -> V_46 , V_42 -> V_48 ) ;
F_48 ( V_42 ) ;
F_49 ( & V_42 -> V_46 , V_10 -> V_44 ) ;
}
}
void F_51 ( struct V_33 * V_34 )
{
struct V_6 * V_7 = V_34 -> V_36 ;
V_34 -> V_49 = 1 ;
F_35 ( & V_34 -> V_26 -> V_50 ,
& V_34 -> V_40 , F_41 ) ;
F_52 ( V_34 ) ;
F_25 ( V_7 -> V_10 -> V_20 ,
F_38 ( V_34 ) ) ;
}
int F_53 ( struct V_33 * V_39 ,
struct V_9 * V_10 ,
struct V_6 * V_7 ,
void (* F_54)( struct V_51 * V_52 ) ,
void (* F_55)( struct V_53 * V_54 ) ,
void * V_55 , struct V_21 * * V_21 )
{
F_3 ( & V_39 -> V_31 ) ;
F_56 ( & V_39 -> V_54 ) ;
V_39 -> V_10 = V_10 ;
V_39 -> V_36 = V_7 ;
V_39 -> V_26 = F_57 ( V_7 , V_55 ) ;
if ( ! V_39 -> V_26 )
return - V_56 ;
V_39 -> V_26 -> V_42 = V_39 ;
V_39 -> V_48 = F_54 ;
V_39 -> V_57 = F_55 ;
if ( V_21 )
* V_21 = & V_39 -> V_26 -> V_50 ;
return 0 ;
}
static bool F_58 ( struct V_9 * V_10 )
{
return F_59 ( & V_10 -> V_58 ) <
V_10 -> V_59 ;
}
static void F_30 ( struct V_9 * V_10 )
{
if ( F_58 ( V_10 ) )
F_60 ( & V_10 -> V_60 ) ;
}
static struct V_6 *
F_61 ( struct V_9 * V_10 )
{
struct V_6 * V_7 ;
int V_61 ;
if ( ! F_58 ( V_10 ) )
return NULL ;
for ( V_61 = 0 ; V_61 < V_62 ; V_61 ++ ) {
V_7 = F_11 ( & V_10 -> V_63 [ V_61 ] ) ;
if ( V_7 )
break;
}
return V_7 ;
}
static void F_62 ( struct V_21 * V_22 , struct V_23 * V_24 )
{
struct V_25 * V_26 =
F_28 ( V_24 , struct V_25 , V_24 ) ;
struct V_9 * V_10 = V_26 -> V_10 ;
unsigned long V_29 ;
F_63 ( & V_10 -> V_58 ) ;
F_64 ( & V_10 -> V_64 , V_29 ) ;
F_10 ( & V_26 -> V_42 -> V_31 ) ;
V_10 -> V_35 -> V_65 ( V_26 -> V_42 ) ;
F_65 ( & V_10 -> V_64 , V_29 ) ;
F_66 ( V_26 ) ;
F_67 ( V_26 ) ;
F_29 ( & V_26 -> V_50 ) ;
F_60 ( & V_10 -> V_60 ) ;
}
static int F_68 ( void * V_66 )
{
struct V_67 V_68 = { . V_69 = 1 } ;
struct V_9 * V_10 = (struct V_9 * ) V_66 ;
int V_12 , V_70 ;
F_69 ( V_71 , V_72 , & V_68 ) ;
while ( ! F_70 () ) {
struct V_6 * V_7 ;
struct V_25 * V_26 ;
struct V_33 * V_34 ;
struct V_21 * V_21 ;
F_71 ( V_10 -> V_60 ,
( V_7 = F_61 ( V_10 ) ) ||
F_70 () ) ;
if ( ! V_7 )
continue;
V_34 = F_36 ( V_7 ) ;
if ( ! V_34 )
continue;
V_26 = V_34 -> V_26 ;
F_72 ( & V_10 -> V_58 ) ;
F_73 ( V_10 , V_34 ) ;
V_21 = V_10 -> V_35 -> V_73 ( V_34 ) ;
F_74 ( V_26 ) ;
if ( V_21 ) {
V_12 = F_35 ( V_21 , & V_26 -> V_24 ,
F_62 ) ;
if ( V_12 == - V_74 )
F_62 ( V_21 , & V_26 -> V_24 ) ;
else if ( V_12 )
F_75 ( L_1 , V_12 ) ;
F_29 ( V_21 ) ;
} else {
F_75 ( L_2 ) ;
F_62 ( NULL , & V_26 -> V_24 ) ;
}
V_70 = F_76 ( & V_7 -> V_15 , & V_34 ,
sizeof( V_34 ) ) ;
F_77 ( V_70 != sizeof( V_34 ) ) ;
F_78 ( & V_10 -> V_20 ) ;
}
return 0 ;
}
int F_79 ( struct V_9 * V_10 ,
const struct V_75 * V_35 ,
unsigned V_76 , long V_44 , const char * V_77 )
{
int V_61 ;
V_10 -> V_35 = V_35 ;
V_10 -> V_59 = V_76 ;
V_10 -> V_77 = V_77 ;
V_10 -> V_44 = V_44 ;
for ( V_61 = 0 ; V_61 < V_62 ; V_61 ++ )
F_1 ( & V_10 -> V_63 [ V_61 ] ) ;
F_80 ( & V_10 -> V_60 ) ;
F_80 ( & V_10 -> V_20 ) ;
F_3 ( & V_10 -> V_47 ) ;
F_2 ( & V_10 -> V_64 ) ;
F_17 ( & V_10 -> V_58 , 0 ) ;
if ( F_81 ( & V_78 ) == 1 ) {
V_79 = F_82 (
L_3 , sizeof( struct V_25 ) , 0 ,
V_80 , NULL ) ;
if ( ! V_79 )
return - V_56 ;
}
V_10 -> V_81 = F_83 ( F_68 , V_10 , V_10 -> V_77 ) ;
if ( F_84 ( V_10 -> V_81 ) ) {
F_75 ( L_4 , V_77 ) ;
return F_85 ( V_10 -> V_81 ) ;
}
return 0 ;
}
void F_86 ( struct V_9 * V_10 )
{
if ( V_10 -> V_81 )
F_87 ( V_10 -> V_81 ) ;
if ( F_88 ( & V_78 ) )
F_89 ( V_79 ) ;
}
