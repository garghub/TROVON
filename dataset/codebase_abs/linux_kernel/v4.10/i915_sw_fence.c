static int F_1 ( struct V_1 * V_2 ,
enum V_3 V_4 )
{
T_1 V_5 ;
V_5 = ( T_1 ) ( V_2 -> V_6 & V_7 ) ;
return V_5 ( V_2 , V_4 ) ;
}
static void F_2 ( struct V_8 * V_8 )
{
struct V_1 * V_2 = F_3 ( V_8 , F_4 ( * V_2 ) , V_8 ) ;
F_5 ( F_6 ( & V_2 -> V_9 ) > 0 ) ;
if ( V_2 -> V_6 & V_7 )
F_1 ( V_2 , V_10 ) ;
else
F_7 ( V_2 ) ;
}
static void F_8 ( struct V_1 * V_2 )
{
F_9 ( & V_2 -> V_8 , F_2 ) ;
}
static struct V_1 * F_10 ( struct V_1 * V_2 )
{
F_11 ( & V_2 -> V_8 ) ;
return V_2 ;
}
static void F_12 ( struct V_1 * V_2 ,
struct V_11 * V_12 )
{
T_2 * V_13 = & V_2 -> V_14 ;
T_3 * V_15 , * V_16 ;
unsigned long V_6 ;
F_13 ( & V_2 -> V_9 , - 1 ) ;
F_14 ( & V_13 -> V_17 , V_6 , 1 + ! ! V_12 ) ;
if ( V_12 ) {
F_15 (pos, next, &x->task_list, task_list) {
if ( V_15 -> V_18 == V_19 )
V_15 -> V_18 ( V_15 , V_20 , 0 , V_12 ) ;
else
F_16 ( & V_15 -> V_21 , V_12 ) ;
}
} else {
F_17 ( V_22 ) ;
do {
F_15 (pos, next,
&x->task_list, task_list)
V_15 -> V_18 ( V_15 , V_20 , 0 , & V_22 ) ;
if ( F_18 ( & V_22 ) )
break;
F_19 ( & V_22 , & V_13 -> V_21 ) ;
} while ( 1 );
}
F_20 ( & V_13 -> V_17 , V_6 ) ;
}
static void F_21 ( struct V_1 * V_2 ,
struct V_11 * V_12 )
{
if ( ! F_22 ( & V_2 -> V_9 ) )
return;
if ( V_2 -> V_6 & V_7 &&
F_1 ( V_2 , V_23 ) != V_24 )
return;
F_12 ( V_2 , V_12 ) ;
}
static void F_23 ( struct V_1 * V_2 )
{
if ( F_5 ( F_24 ( V_2 ) ) )
return;
F_21 ( V_2 , NULL ) ;
}
static void F_25 ( struct V_1 * V_2 )
{
F_5 ( F_26 ( & V_2 -> V_9 ) <= 1 ) ;
}
void F_27 ( struct V_1 * V_2 ,
T_1 V_5 ,
const char * V_25 ,
struct V_26 * V_27 )
{
F_28 ( ( unsigned long ) V_5 & ~ V_7 ) ;
F_29 ( & V_2 -> V_14 , V_25 , V_27 ) ;
F_30 ( & V_2 -> V_8 ) ;
F_31 ( & V_2 -> V_9 , 1 ) ;
V_2 -> V_6 = ( unsigned long ) V_5 ;
}
void F_32 ( struct V_1 * V_2 )
{
F_23 ( V_2 ) ;
F_8 ( V_2 ) ;
}
static int F_33 ( T_3 * V_28 , unsigned V_29 , int V_6 , void * V_27 )
{
F_34 ( & V_28 -> V_21 ) ;
F_21 ( V_28 -> V_30 , V_27 ) ;
F_8 ( V_28 -> V_30 ) ;
if ( V_28 -> V_6 & V_31 )
F_7 ( V_28 ) ;
return 0 ;
}
static bool F_35 ( struct V_1 * V_2 ,
const struct V_1 * const V_32 )
{
T_3 * V_28 ;
if ( F_36 ( V_33 , & V_2 -> V_6 ) )
return false ;
if ( V_2 == V_32 )
return true ;
F_37 (wq, &fence->wait.task_list, task_list) {
if ( V_28 -> V_18 != F_33 )
continue;
if ( F_35 ( V_28 -> V_30 , V_32 ) )
return true ;
}
return false ;
}
static void F_38 ( struct V_1 * V_2 )
{
T_3 * V_28 ;
if ( ! F_39 ( V_33 , & V_2 -> V_6 ) )
return;
F_37 (wq, &fence->wait.task_list, task_list) {
if ( V_28 -> V_18 != F_33 )
continue;
F_38 ( V_28 -> V_30 ) ;
}
}
static bool F_40 ( struct V_1 * V_2 ,
const struct V_1 * const V_32 )
{
unsigned long V_6 ;
bool V_34 ;
if ( ! F_41 ( V_35 ) )
return false ;
F_42 ( & V_36 , V_6 ) ;
V_34 = F_35 ( V_2 , V_32 ) ;
F_38 ( V_2 ) ;
F_20 ( & V_36 , V_6 ) ;
return V_34 ;
}
static int F_43 ( struct V_1 * V_2 ,
struct V_1 * V_32 ,
T_3 * V_28 , T_4 V_37 )
{
unsigned long V_6 ;
int V_9 ;
if ( F_24 ( V_32 ) )
return 0 ;
if ( F_44 ( F_40 ( V_2 , V_32 ) ) )
return - V_38 ;
V_9 = 0 ;
if ( ! V_28 ) {
V_28 = F_45 ( sizeof( * V_28 ) , V_37 ) ;
if ( ! V_28 ) {
if ( ! F_46 ( V_37 ) )
return - V_39 ;
F_47 ( V_32 ) ;
return 0 ;
}
V_9 |= V_31 ;
}
F_48 ( & V_28 -> V_21 ) ;
V_28 -> V_6 = V_9 ;
V_28 -> V_18 = F_33 ;
V_28 -> V_30 = F_10 ( V_2 ) ;
F_25 ( V_2 ) ;
F_42 ( & V_32 -> V_14 . V_17 , V_6 ) ;
if ( F_49 ( ! F_24 ( V_32 ) ) ) {
F_50 ( & V_32 -> V_14 , V_28 ) ;
V_9 = 1 ;
} else {
F_33 ( V_28 , 0 , 0 , NULL ) ;
V_9 = 0 ;
}
F_20 ( & V_32 -> V_14 . V_17 , V_6 ) ;
return V_9 ;
}
int F_51 ( struct V_1 * V_2 ,
struct V_1 * V_32 ,
T_3 * V_28 )
{
return F_43 ( V_2 , V_32 , V_28 , 0 ) ;
}
int F_52 ( struct V_1 * V_2 ,
struct V_1 * V_32 ,
T_4 V_37 )
{
return F_43 ( V_2 , V_32 , NULL , V_37 ) ;
}
static void F_53 ( unsigned long V_40 )
{
struct V_41 * V_42 = (struct V_41 * ) V_40 ;
F_54 ( V_43 L_1 ,
V_42 -> V_44 -> V_45 -> V_46 ( V_42 -> V_44 ) ,
V_42 -> V_44 -> V_45 -> V_47 ( V_42 -> V_44 ) ,
V_42 -> V_44 -> V_48 ) ;
F_55 ( V_42 -> V_44 ) ;
V_42 -> V_44 = NULL ;
F_32 ( V_42 -> V_2 ) ;
V_42 -> V_49 . V_50 = NULL ;
}
static void F_56 ( struct V_51 * V_44 ,
struct V_52 * V_40 )
{
struct V_41 * V_42 = F_3 ( V_40 , F_4 ( * V_42 ) , V_53 ) ;
F_57 ( & V_42 -> V_49 ) ;
if ( V_42 -> V_49 . V_50 )
F_32 ( V_42 -> V_2 ) ;
F_55 ( V_42 -> V_44 ) ;
F_7 ( V_42 ) ;
}
int F_58 ( struct V_1 * V_2 ,
struct V_51 * V_44 ,
unsigned long V_54 ,
T_4 V_37 )
{
struct V_41 * V_42 ;
int V_55 ;
if ( F_59 ( V_44 ) )
return 0 ;
V_42 = F_45 ( sizeof( * V_42 ) , V_37 ) ;
if ( ! V_42 ) {
if ( ! F_46 ( V_37 ) )
return - V_39 ;
return F_60 ( V_44 , false ) ;
}
V_42 -> V_2 = F_10 ( V_2 ) ;
F_25 ( V_2 ) ;
V_42 -> V_44 = NULL ;
F_61 ( & V_42 -> V_49 ,
F_53 , ( unsigned long ) V_42 ,
V_56 ) ;
if ( V_54 ) {
V_42 -> V_44 = F_62 ( V_44 ) ;
F_63 ( & V_42 -> V_49 , F_64 ( V_57 + V_54 ) ) ;
}
V_55 = F_65 ( V_44 , & V_42 -> V_53 , F_56 ) ;
if ( V_55 == 0 ) {
V_55 = 1 ;
} else {
F_56 ( V_44 , & V_42 -> V_53 ) ;
if ( V_55 == - V_58 )
V_55 = 0 ;
}
return V_55 ;
}
int F_66 ( struct V_1 * V_2 ,
struct V_59 * V_60 ,
const struct V_61 * V_62 ,
bool V_63 ,
unsigned long V_54 ,
T_4 V_37 )
{
struct V_51 * V_64 ;
int V_55 = 0 , V_9 ;
if ( V_63 ) {
struct V_51 * * V_65 ;
unsigned int V_66 , V_67 ;
V_55 = F_67 ( V_60 ,
& V_64 , & V_66 , & V_65 ) ;
if ( V_55 )
return V_55 ;
for ( V_67 = 0 ; V_67 < V_66 ; V_67 ++ ) {
if ( V_65 [ V_67 ] -> V_45 == V_62 )
continue;
V_9 = F_58 ( V_2 ,
V_65 [ V_67 ] ,
V_54 ,
V_37 ) ;
if ( V_9 < 0 ) {
V_55 = V_9 ;
break;
}
V_55 |= V_9 ;
}
for ( V_67 = 0 ; V_67 < V_66 ; V_67 ++ )
F_55 ( V_65 [ V_67 ] ) ;
F_7 ( V_65 ) ;
} else {
V_64 = F_68 ( V_60 ) ;
}
if ( V_55 >= 0 && V_64 && V_64 -> V_45 != V_62 ) {
V_9 = F_58 ( V_2 ,
V_64 ,
V_54 ,
V_37 ) ;
if ( V_9 < 0 )
V_55 = V_9 ;
else
V_55 |= V_9 ;
}
F_55 ( V_64 ) ;
return V_55 ;
}
