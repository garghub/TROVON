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
static struct V_9 *
F_10 ( struct V_1 * V_2 )
{
struct V_6 * V_7 ;
struct V_9 * V_10 ;
F_5 ( & V_2 -> V_3 ) ;
V_7 = V_2 -> V_5 ;
if ( V_7 ) {
F_11 (entity, &rq->entities, list) {
V_10 = F_12 ( V_7 ) ;
if ( V_10 ) {
V_2 -> V_5 = V_7 ;
F_7 ( & V_2 -> V_3 ) ;
return V_10 ;
}
}
}
F_13 (entity, &rq->entities, list) {
V_10 = F_12 ( V_7 ) ;
if ( V_10 ) {
V_2 -> V_5 = V_7 ;
F_7 ( & V_2 -> V_3 ) ;
return V_10 ;
}
if ( V_7 == V_2 -> V_5 )
break;
}
F_7 ( & V_2 -> V_3 ) ;
return NULL ;
}
int F_14 ( struct V_11 * V_12 ,
struct V_6 * V_7 ,
struct V_1 * V_2 ,
T_1 V_13 )
{
int V_14 ;
if ( ! ( V_12 && V_7 && V_2 ) )
return - V_15 ;
memset ( V_7 , 0 , sizeof( struct V_6 ) ) ;
F_3 ( & V_7 -> V_8 ) ;
V_7 -> V_2 = V_2 ;
V_7 -> V_12 = V_12 ;
F_2 ( & V_7 -> V_16 ) ;
V_14 = F_15 ( & V_7 -> V_17 , V_13 * sizeof( void * ) , V_18 ) ;
if ( V_14 )
return V_14 ;
F_16 ( & V_7 -> V_19 , 0 ) ;
V_7 -> V_20 = F_17 ( 1 ) ;
F_4 ( V_2 , V_7 ) ;
return 0 ;
}
static bool F_18 ( struct V_11 * V_12 ,
struct V_6 * V_7 )
{
return V_7 -> V_12 == V_12 &&
V_7 -> V_2 != NULL ;
}
static bool F_19 ( struct V_6 * V_7 )
{
F_20 () ;
if ( F_21 ( & V_7 -> V_17 ) )
return true ;
return false ;
}
void F_22 ( struct V_11 * V_12 ,
struct V_6 * V_7 )
{
struct V_1 * V_2 = V_7 -> V_2 ;
if ( ! F_18 ( V_12 , V_7 ) )
return;
F_23 ( V_12 -> V_21 , F_19 ( V_7 ) ) ;
F_8 ( V_2 , V_7 ) ;
F_24 ( & V_7 -> V_17 ) ;
}
static void F_25 ( struct V_22 * V_23 , struct V_24 * V_25 )
{
struct V_6 * V_7 =
F_26 ( V_25 , struct V_6 , V_25 ) ;
V_7 -> V_26 = NULL ;
F_27 ( V_23 ) ;
F_28 ( V_7 -> V_12 ) ;
}
static struct V_9 *
F_12 ( struct V_6 * V_7 )
{
struct V_11 * V_12 = V_7 -> V_12 ;
struct V_9 * V_10 ;
if ( F_29 ( V_7 -> V_26 ) )
return NULL ;
if ( ! F_30 ( & V_7 -> V_17 , & V_10 , sizeof( V_10 ) ) )
return NULL ;
while ( ( V_7 -> V_26 = V_12 -> V_27 -> V_26 ( V_10 ) ) ) {
if ( F_31 ( V_7 -> V_26 , & V_7 -> V_25 ,
F_25 ) )
F_27 ( V_7 -> V_26 ) ;
else
return NULL ;
}
return V_10 ;
}
static bool F_32 ( struct V_9 * V_10 )
{
struct V_6 * V_7 = V_10 -> V_28 ;
bool V_29 , V_30 = false ;
F_5 ( & V_7 -> V_16 ) ;
V_29 = F_33 ( & V_7 -> V_17 , & V_10 ,
sizeof( V_10 ) ) == sizeof( V_10 ) ;
if ( V_29 && F_34 ( & V_7 -> V_17 ) == sizeof( V_10 ) )
V_30 = true ;
F_7 ( & V_7 -> V_16 ) ;
if ( V_30 )
F_28 ( V_10 -> V_12 ) ;
return V_29 ;
}
int F_35 ( struct V_9 * V_10 )
{
struct V_6 * V_7 = V_10 -> V_28 ;
struct V_31 * V_22 = F_36 (
V_7 , V_10 -> V_32 ) ;
if ( ! V_22 )
return - V_33 ;
F_37 ( & V_22 -> V_34 ) ;
V_10 -> V_35 = V_22 ;
F_23 ( V_7 -> V_12 -> V_21 ,
F_32 ( V_10 ) ) ;
F_38 ( V_10 ) ;
return 0 ;
}
static bool F_39 ( struct V_11 * V_12 )
{
return F_40 ( & V_12 -> V_36 ) <
V_12 -> V_37 ;
}
static void F_28 ( struct V_11 * V_12 )
{
if ( F_39 ( V_12 ) )
F_41 ( & V_12 -> V_38 ) ;
}
static struct V_9 *
F_42 ( struct V_11 * V_12 )
{
struct V_9 * V_10 ;
if ( ! F_39 ( V_12 ) )
return NULL ;
V_10 = F_10 ( & V_12 -> V_39 ) ;
if ( V_10 == NULL )
V_10 = F_10 ( & V_12 -> V_40 ) ;
return V_10 ;
}
static void F_43 ( struct V_22 * V_23 , struct V_24 * V_25 )
{
struct V_31 * V_35 =
F_26 ( V_25 , struct V_31 , V_25 ) ;
struct V_11 * V_12 = V_35 -> V_12 ;
F_44 ( & V_12 -> V_36 ) ;
F_45 ( V_35 ) ;
F_27 ( & V_35 -> V_34 ) ;
F_41 ( & V_12 -> V_38 ) ;
}
static int F_46 ( void * V_41 )
{
struct V_42 V_43 = { . V_44 = 1 } ;
struct V_11 * V_12 = (struct V_11 * ) V_41 ;
int V_14 , V_45 ;
F_47 ( V_46 , V_47 , & V_43 ) ;
while ( ! F_48 () ) {
struct V_6 * V_7 ;
struct V_31 * V_35 ;
struct V_9 * V_10 ;
struct V_22 * V_22 ;
F_49 ( V_12 -> V_38 ,
F_48 () ||
( V_10 = F_42 ( V_12 ) ) ) ;
if ( ! V_10 )
continue;
V_7 = V_10 -> V_28 ;
V_35 = V_10 -> V_35 ;
F_50 ( & V_12 -> V_36 ) ;
V_22 = V_12 -> V_27 -> V_48 ( V_10 ) ;
if ( V_22 ) {
V_14 = F_31 ( V_22 , & V_35 -> V_25 ,
F_43 ) ;
if ( V_14 == - V_49 )
F_43 ( V_22 , & V_35 -> V_25 ) ;
else if ( V_14 )
F_51 ( L_1 , V_14 ) ;
F_27 ( V_22 ) ;
} else {
F_51 ( L_2 ) ;
F_43 ( NULL , & V_35 -> V_25 ) ;
}
V_45 = F_52 ( & V_7 -> V_17 , & V_10 ,
sizeof( V_10 ) ) ;
F_53 ( V_45 != sizeof( V_10 ) ) ;
F_54 ( & V_12 -> V_21 ) ;
}
return 0 ;
}
int F_55 ( struct V_11 * V_12 ,
struct V_50 * V_27 ,
unsigned V_51 , const char * V_52 )
{
V_12 -> V_27 = V_27 ;
V_12 -> V_37 = V_51 ;
V_12 -> V_52 = V_52 ;
F_1 ( & V_12 -> V_40 ) ;
F_1 ( & V_12 -> V_39 ) ;
F_56 ( & V_12 -> V_38 ) ;
F_56 ( & V_12 -> V_21 ) ;
F_16 ( & V_12 -> V_36 , 0 ) ;
V_12 -> V_53 = F_57 ( F_46 , V_12 , V_12 -> V_52 ) ;
if ( F_58 ( V_12 -> V_53 ) ) {
F_51 ( L_3 , V_52 ) ;
return F_59 ( V_12 -> V_53 ) ;
}
return 0 ;
}
void F_60 ( struct V_11 * V_12 )
{
F_61 ( V_12 -> V_53 ) ;
}
