static void * F_1 ( void * V_1 )
{
return ( void * ) ( ( (struct V_2 * ) V_1 ) -> V_3 & V_4 ) ;
}
static inline void F_2 ( struct V_2 * V_5 )
{
F_3 ( V_5 , & V_6 ) ;
}
static inline void F_4 ( struct V_2 * V_5 )
{
F_5 ( V_5 , & V_6 ) ;
}
static inline void F_6 ( struct V_2 * V_5 ,
int V_7 , int V_8 )
{
F_7 ( V_5 , & V_6 , V_7 , V_8 ) ;
}
static inline void F_8 ( struct V_2 * V_5 )
{
F_9 ( V_5 , & V_6 ) ;
}
static inline void F_10 ( struct V_2 * V_5 )
{
F_11 ( V_5 , & V_6 ) ;
}
static inline void F_12 ( struct V_2 * V_5 )
{
F_13 ( V_5 , & V_6 ) ;
F_14 () ;
}
static inline void F_15 ( struct V_2 * V_5 )
{
F_16 ( V_5 , & V_6 ) ;
}
static inline void F_2 ( struct V_2 * V_5 )
{
}
static inline void F_4 ( struct V_2 * V_5 )
{
}
static inline void F_6 ( struct V_2 * V_5 ,
int V_7 , int V_8 )
{
}
static inline void F_8 ( struct V_2 * V_5 )
{
}
static inline void F_10 ( struct V_2 * V_5 )
{
}
static inline void F_12 ( struct V_2 * V_5 )
{
}
static inline void F_15 ( struct V_2 * V_5 )
{
}
static int F_17 ( struct V_2 * V_5 ,
enum V_9 V_10 )
{
T_1 V_11 ;
V_11 = ( T_1 ) ( V_5 -> V_3 & V_4 ) ;
return V_11 ( V_5 , V_10 ) ;
}
void F_18 ( struct V_2 * V_5 )
{
F_12 ( V_5 ) ;
}
static void F_19 ( struct V_12 * V_12 )
{
struct V_2 * V_5 = F_20 ( V_12 , F_21 ( * V_5 ) , V_12 ) ;
F_22 ( F_23 ( & V_5 -> V_13 ) > 0 ) ;
F_10 ( V_5 ) ;
if ( V_5 -> V_3 & V_4 ) {
F_17 ( V_5 , V_14 ) ;
} else {
F_18 ( V_5 ) ;
F_24 ( V_5 ) ;
}
}
static void F_25 ( struct V_2 * V_5 )
{
F_15 ( V_5 ) ;
F_26 ( & V_5 -> V_12 , F_19 ) ;
}
static struct V_2 * F_27 ( struct V_2 * V_5 )
{
F_15 ( V_5 ) ;
F_28 ( & V_5 -> V_12 ) ;
return V_5 ;
}
static void F_29 ( struct V_2 * V_5 ,
struct V_15 * V_16 )
{
T_2 * V_17 = & V_5 -> V_18 ;
T_3 * V_19 , * V_20 ;
unsigned long V_3 ;
F_8 ( V_5 ) ;
F_30 ( & V_5 -> V_13 , - 1 ) ;
F_31 ( & V_17 -> V_21 , V_3 , 1 + ! ! V_16 ) ;
if ( V_16 ) {
F_32 (pos, next, &x->task_list, task_list) {
if ( V_19 -> V_22 == V_23 )
V_19 -> V_22 ( V_19 , V_24 , 0 , V_16 ) ;
else
F_33 ( & V_19 -> V_25 , V_16 ) ;
}
} else {
F_34 ( V_26 ) ;
do {
F_32 (pos, next,
&x->task_list, task_list)
V_19 -> V_22 ( V_19 , V_24 , 0 , & V_26 ) ;
if ( F_35 ( & V_26 ) )
break;
F_36 ( & V_26 , & V_17 -> V_25 ) ;
} while ( 1 );
}
F_37 ( & V_17 -> V_21 , V_3 ) ;
F_15 ( V_5 ) ;
}
static void F_38 ( struct V_2 * V_5 ,
struct V_15 * V_16 )
{
F_15 ( V_5 ) ;
if ( ! F_39 ( & V_5 -> V_13 ) )
return;
F_6 ( V_5 , V_27 , V_28 ) ;
if ( V_5 -> V_3 & V_4 &&
F_17 ( V_5 , V_29 ) != V_30 )
return;
F_6 ( V_5 , V_28 , V_27 ) ;
F_29 ( V_5 , V_16 ) ;
}
static void F_40 ( struct V_2 * V_5 )
{
F_15 ( V_5 ) ;
if ( F_22 ( F_41 ( V_5 ) ) )
return;
F_38 ( V_5 , NULL ) ;
}
static void F_42 ( struct V_2 * V_5 )
{
F_15 ( V_5 ) ;
F_22 ( F_43 ( & V_5 -> V_13 ) <= 1 ) ;
}
void F_44 ( struct V_2 * V_5 ,
T_1 V_11 ,
const char * V_31 ,
struct V_32 * V_33 )
{
F_45 ( ( unsigned long ) V_11 & ~ V_4 ) ;
F_2 ( V_5 ) ;
F_46 ( & V_5 -> V_18 , V_31 , V_33 ) ;
F_47 ( & V_5 -> V_12 ) ;
F_48 ( & V_5 -> V_13 , 1 ) ;
V_5 -> V_3 = ( unsigned long ) V_11 ;
}
static void F_49 ( struct V_2 * V_5 )
{
F_40 ( V_5 ) ;
F_25 ( V_5 ) ;
}
void F_50 ( struct V_2 * V_5 )
{
F_4 ( V_5 ) ;
F_49 ( V_5 ) ;
}
static int F_51 ( T_3 * V_34 , unsigned V_35 , int V_3 , void * V_33 )
{
F_52 ( & V_34 -> V_25 ) ;
F_38 ( V_34 -> V_36 , V_33 ) ;
F_25 ( V_34 -> V_36 ) ;
if ( V_34 -> V_3 & V_37 )
F_24 ( V_34 ) ;
return 0 ;
}
static bool F_53 ( struct V_2 * V_5 ,
const struct V_2 * const V_38 )
{
T_3 * V_34 ;
if ( F_54 ( V_39 , & V_5 -> V_3 ) )
return false ;
if ( V_5 == V_38 )
return true ;
F_55 (wq, &fence->wait.task_list, task_list) {
if ( V_34 -> V_22 != F_51 )
continue;
if ( F_53 ( V_34 -> V_36 , V_38 ) )
return true ;
}
return false ;
}
static void F_56 ( struct V_2 * V_5 )
{
T_3 * V_34 ;
if ( ! F_57 ( V_39 , & V_5 -> V_3 ) )
return;
F_55 (wq, &fence->wait.task_list, task_list) {
if ( V_34 -> V_22 != F_51 )
continue;
F_56 ( V_34 -> V_36 ) ;
}
}
static bool F_58 ( struct V_2 * V_5 ,
const struct V_2 * const V_38 )
{
unsigned long V_3 ;
bool V_40 ;
if ( ! F_59 ( V_41 ) )
return false ;
F_60 ( & V_42 , V_3 ) ;
V_40 = F_53 ( V_5 , V_38 ) ;
F_56 ( V_5 ) ;
F_37 ( & V_42 , V_3 ) ;
return V_40 ;
}
static int F_61 ( struct V_2 * V_5 ,
struct V_2 * V_38 ,
T_3 * V_34 , T_4 V_43 )
{
unsigned long V_3 ;
int V_13 ;
F_15 ( V_5 ) ;
if ( F_41 ( V_38 ) )
return 0 ;
F_15 ( V_38 ) ;
if ( F_62 ( F_58 ( V_5 , V_38 ) ) )
return - V_44 ;
V_13 = 0 ;
if ( ! V_34 ) {
V_34 = F_63 ( sizeof( * V_34 ) , V_43 ) ;
if ( ! V_34 ) {
if ( ! F_64 ( V_43 ) )
return - V_45 ;
F_65 ( V_38 ) ;
return 0 ;
}
V_13 |= V_37 ;
}
F_66 ( & V_34 -> V_25 ) ;
V_34 -> V_3 = V_13 ;
V_34 -> V_22 = F_51 ;
V_34 -> V_36 = F_27 ( V_5 ) ;
F_42 ( V_5 ) ;
F_60 ( & V_38 -> V_18 . V_21 , V_3 ) ;
if ( F_67 ( ! F_41 ( V_38 ) ) ) {
F_68 ( & V_38 -> V_18 , V_34 ) ;
V_13 = 1 ;
} else {
F_51 ( V_34 , 0 , 0 , NULL ) ;
V_13 = 0 ;
}
F_37 ( & V_38 -> V_18 . V_21 , V_3 ) ;
return V_13 ;
}
int F_69 ( struct V_2 * V_5 ,
struct V_2 * V_38 ,
T_3 * V_34 )
{
return F_61 ( V_5 , V_38 , V_34 , 0 ) ;
}
int F_70 ( struct V_2 * V_5 ,
struct V_2 * V_38 ,
T_4 V_43 )
{
return F_61 ( V_5 , V_38 , NULL , V_43 ) ;
}
static void F_71 ( unsigned long V_46 )
{
struct V_47 * V_48 = (struct V_47 * ) V_46 ;
F_72 ( V_49 L_1 ,
V_48 -> V_50 -> V_51 -> V_52 ( V_48 -> V_50 ) ,
V_48 -> V_50 -> V_51 -> V_53 ( V_48 -> V_50 ) ,
V_48 -> V_50 -> V_54 ) ;
F_73 ( V_48 -> V_50 ) ;
V_48 -> V_50 = NULL ;
F_49 ( V_48 -> V_5 ) ;
V_48 -> V_55 . V_56 = NULL ;
}
static void F_74 ( struct V_57 * V_50 ,
struct V_58 * V_46 )
{
struct V_47 * V_48 = F_20 ( V_46 , F_21 ( * V_48 ) , V_59 ) ;
F_75 ( & V_48 -> V_55 ) ;
if ( V_48 -> V_55 . V_56 )
F_49 ( V_48 -> V_5 ) ;
F_73 ( V_48 -> V_50 ) ;
F_24 ( V_48 ) ;
}
int F_76 ( struct V_2 * V_5 ,
struct V_57 * V_50 ,
unsigned long V_60 ,
T_4 V_43 )
{
struct V_47 * V_48 ;
int V_61 ;
F_15 ( V_5 ) ;
if ( F_77 ( V_50 ) )
return 0 ;
V_48 = F_63 ( sizeof( * V_48 ) , V_43 ) ;
if ( ! V_48 ) {
if ( ! F_64 ( V_43 ) )
return - V_45 ;
return F_78 ( V_50 , false ) ;
}
V_48 -> V_5 = F_27 ( V_5 ) ;
F_42 ( V_5 ) ;
V_48 -> V_50 = NULL ;
F_79 ( & V_48 -> V_55 ,
F_71 , ( unsigned long ) V_48 ,
V_62 ) ;
if ( V_60 ) {
V_48 -> V_50 = F_80 ( V_50 ) ;
F_81 ( & V_48 -> V_55 , F_82 ( V_63 + V_60 ) ) ;
}
V_61 = F_83 ( V_50 , & V_48 -> V_59 , F_74 ) ;
if ( V_61 == 0 ) {
V_61 = 1 ;
} else {
F_74 ( V_50 , & V_48 -> V_59 ) ;
if ( V_61 == - V_64 )
V_61 = 0 ;
}
return V_61 ;
}
int F_84 ( struct V_2 * V_5 ,
struct V_65 * V_66 ,
const struct V_67 * V_68 ,
bool V_69 ,
unsigned long V_60 ,
T_4 V_43 )
{
struct V_57 * V_70 ;
int V_61 = 0 , V_13 ;
F_15 ( V_5 ) ;
if ( V_69 ) {
struct V_57 * * V_71 ;
unsigned int V_72 , V_73 ;
V_61 = F_85 ( V_66 ,
& V_70 , & V_72 , & V_71 ) ;
if ( V_61 )
return V_61 ;
for ( V_73 = 0 ; V_73 < V_72 ; V_73 ++ ) {
if ( V_71 [ V_73 ] -> V_51 == V_68 )
continue;
V_13 = F_76 ( V_5 ,
V_71 [ V_73 ] ,
V_60 ,
V_43 ) ;
if ( V_13 < 0 ) {
V_61 = V_13 ;
break;
}
V_61 |= V_13 ;
}
for ( V_73 = 0 ; V_73 < V_72 ; V_73 ++ )
F_73 ( V_71 [ V_73 ] ) ;
F_24 ( V_71 ) ;
} else {
V_70 = F_86 ( V_66 ) ;
}
if ( V_61 >= 0 && V_70 && V_70 -> V_51 != V_68 ) {
V_13 = F_76 ( V_5 ,
V_70 ,
V_60 ,
V_43 ) ;
if ( V_13 < 0 )
V_61 = V_13 ;
else
V_61 |= V_13 ;
}
F_73 ( V_70 ) ;
return V_61 ;
}
