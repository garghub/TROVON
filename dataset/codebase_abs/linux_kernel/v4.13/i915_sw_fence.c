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
static void F_19 ( struct V_2 * V_5 ,
struct V_12 * V_13 )
{
T_2 * V_14 = & V_5 -> V_15 ;
T_3 * V_16 , * V_17 ;
unsigned long V_3 ;
F_8 ( V_5 ) ;
F_20 ( & V_5 -> V_18 , - 1 ) ;
F_21 ( & V_14 -> V_19 , V_3 , 1 + ! ! V_13 ) ;
if ( V_13 ) {
F_22 (pos, next, &x->head, entry) {
if ( V_16 -> V_20 == V_21 )
V_16 -> V_20 ( V_16 , V_22 , 0 , V_13 ) ;
else
F_23 ( & V_16 -> V_23 , V_13 ) ;
}
} else {
F_24 ( V_24 ) ;
do {
F_22 (pos, next, &x->head, entry)
V_16 -> V_20 ( V_16 , V_22 , 0 , & V_24 ) ;
if ( F_25 ( & V_24 ) )
break;
F_26 ( & V_24 , & V_14 -> V_25 ) ;
} while ( 1 );
}
F_27 ( & V_14 -> V_19 , V_3 ) ;
F_15 ( V_5 ) ;
}
static void F_28 ( struct V_2 * V_5 ,
struct V_12 * V_13 )
{
F_15 ( V_5 ) ;
if ( ! F_29 ( & V_5 -> V_18 ) )
return;
F_6 ( V_5 , V_26 , V_27 ) ;
if ( F_17 ( V_5 , V_28 ) != V_29 )
return;
F_6 ( V_5 , V_27 , V_26 ) ;
F_19 ( V_5 , V_13 ) ;
F_10 ( V_5 ) ;
F_17 ( V_5 , V_30 ) ;
}
static void F_30 ( struct V_2 * V_5 )
{
F_15 ( V_5 ) ;
if ( F_31 ( F_32 ( V_5 ) ) )
return;
F_28 ( V_5 , NULL ) ;
}
static void F_33 ( struct V_2 * V_5 )
{
F_15 ( V_5 ) ;
F_31 ( F_34 ( & V_5 -> V_18 ) <= 1 ) ;
}
void F_35 ( struct V_2 * V_5 ,
T_1 V_11 ,
const char * V_31 ,
struct V_32 * V_33 )
{
F_36 ( ! V_11 || ( unsigned long ) V_11 & ~ V_4 ) ;
F_2 ( V_5 ) ;
F_37 ( & V_5 -> V_15 , V_31 , V_33 ) ;
F_38 ( & V_5 -> V_18 , 1 ) ;
V_5 -> V_3 = ( unsigned long ) V_11 ;
}
void F_39 ( struct V_2 * V_5 )
{
F_4 ( V_5 ) ;
F_30 ( V_5 ) ;
}
static int F_40 ( T_3 * V_34 , unsigned V_35 , int V_3 , void * V_33 )
{
F_41 ( & V_34 -> V_23 ) ;
F_28 ( V_34 -> V_36 , V_33 ) ;
if ( V_34 -> V_3 & V_37 )
F_42 ( V_34 ) ;
return 0 ;
}
static bool F_43 ( struct V_2 * V_5 ,
const struct V_2 * const V_38 )
{
T_3 * V_34 ;
if ( F_44 ( V_39 , & V_5 -> V_3 ) )
return false ;
if ( V_5 == V_38 )
return true ;
F_45 (wq, &fence->wait.head, entry) {
if ( V_34 -> V_20 != F_40 )
continue;
if ( F_43 ( V_34 -> V_36 , V_38 ) )
return true ;
}
return false ;
}
static void F_46 ( struct V_2 * V_5 )
{
T_3 * V_34 ;
if ( ! F_47 ( V_39 , & V_5 -> V_3 ) )
return;
F_45 (wq, &fence->wait.head, entry) {
if ( V_34 -> V_20 != F_40 )
continue;
F_46 ( V_34 -> V_36 ) ;
}
}
static bool F_48 ( struct V_2 * V_5 ,
const struct V_2 * const V_38 )
{
unsigned long V_3 ;
bool V_40 ;
if ( ! F_49 ( V_41 ) )
return false ;
F_50 ( & V_42 , V_3 ) ;
V_40 = F_43 ( V_5 , V_38 ) ;
F_46 ( V_5 ) ;
F_27 ( & V_42 , V_3 ) ;
return V_40 ;
}
static int F_51 ( struct V_2 * V_5 ,
struct V_2 * V_38 ,
T_3 * V_34 , T_4 V_43 )
{
unsigned long V_3 ;
int V_18 ;
F_15 ( V_5 ) ;
if ( F_32 ( V_38 ) )
return 0 ;
F_15 ( V_38 ) ;
if ( F_52 ( F_48 ( V_5 , V_38 ) ) )
return - V_44 ;
V_18 = 0 ;
if ( ! V_34 ) {
V_34 = F_53 ( sizeof( * V_34 ) , V_43 ) ;
if ( ! V_34 ) {
if ( ! F_54 ( V_43 ) )
return - V_45 ;
F_55 ( V_38 ) ;
return 0 ;
}
V_18 |= V_37 ;
}
F_56 ( & V_34 -> V_23 ) ;
V_34 -> V_3 = V_18 ;
V_34 -> V_20 = F_40 ;
V_34 -> V_36 = V_5 ;
F_33 ( V_5 ) ;
F_50 ( & V_38 -> V_15 . V_19 , V_3 ) ;
if ( F_57 ( ! F_32 ( V_38 ) ) ) {
F_58 ( & V_38 -> V_15 , V_34 ) ;
V_18 = 1 ;
} else {
F_40 ( V_34 , 0 , 0 , NULL ) ;
V_18 = 0 ;
}
F_27 ( & V_38 -> V_15 . V_19 , V_3 ) ;
return V_18 ;
}
int F_59 ( struct V_2 * V_5 ,
struct V_2 * V_38 ,
T_3 * V_34 )
{
return F_51 ( V_5 , V_38 , V_34 , 0 ) ;
}
int F_60 ( struct V_2 * V_5 ,
struct V_2 * V_38 ,
T_4 V_43 )
{
return F_51 ( V_5 , V_38 , NULL , V_43 ) ;
}
static void F_61 ( unsigned long V_46 )
{
struct V_47 * V_48 = (struct V_47 * ) V_46 ;
F_62 ( L_1 ,
V_48 -> V_49 -> V_50 -> V_51 ( V_48 -> V_49 ) ,
V_48 -> V_49 -> V_50 -> V_52 ( V_48 -> V_49 ) ,
V_48 -> V_49 -> V_53 ) ;
F_63 ( V_48 -> V_49 ) ;
V_48 -> V_49 = NULL ;
F_30 ( V_48 -> V_5 ) ;
V_48 -> V_54 . V_55 = NULL ;
}
static void F_64 ( struct V_56 * V_49 ,
struct V_57 * V_46 )
{
struct V_47 * V_48 = F_65 ( V_46 , F_66 ( * V_48 ) , V_58 ) ;
F_67 ( & V_48 -> V_54 ) ;
if ( V_48 -> V_54 . V_55 )
F_30 ( V_48 -> V_5 ) ;
F_63 ( V_48 -> V_49 ) ;
F_42 ( V_48 ) ;
}
int F_68 ( struct V_2 * V_5 ,
struct V_56 * V_49 ,
unsigned long V_59 ,
T_4 V_43 )
{
struct V_47 * V_48 ;
int V_60 ;
F_15 ( V_5 ) ;
if ( F_69 ( V_49 ) )
return 0 ;
V_48 = F_53 ( sizeof( * V_48 ) , V_43 ) ;
if ( ! V_48 ) {
if ( ! F_54 ( V_43 ) )
return - V_45 ;
return F_70 ( V_49 , false ) ;
}
V_48 -> V_5 = V_5 ;
F_33 ( V_5 ) ;
V_48 -> V_49 = NULL ;
F_71 ( & V_48 -> V_54 ,
F_61 , ( unsigned long ) V_48 ,
V_61 ) ;
if ( V_59 ) {
V_48 -> V_49 = F_72 ( V_49 ) ;
F_73 ( & V_48 -> V_54 , F_74 ( V_62 + V_59 ) ) ;
}
V_60 = F_75 ( V_49 , & V_48 -> V_58 , F_64 ) ;
if ( V_60 == 0 ) {
V_60 = 1 ;
} else {
F_64 ( V_49 , & V_48 -> V_58 ) ;
if ( V_60 == - V_63 )
V_60 = 0 ;
}
return V_60 ;
}
int F_76 ( struct V_2 * V_5 ,
struct V_64 * V_65 ,
const struct V_66 * V_67 ,
bool V_68 ,
unsigned long V_59 ,
T_4 V_43 )
{
struct V_56 * V_69 ;
int V_60 = 0 , V_18 ;
F_15 ( V_5 ) ;
if ( V_68 ) {
struct V_56 * * V_70 ;
unsigned int V_71 , V_72 ;
V_60 = F_77 ( V_65 ,
& V_69 , & V_71 , & V_70 ) ;
if ( V_60 )
return V_60 ;
for ( V_72 = 0 ; V_72 < V_71 ; V_72 ++ ) {
if ( V_70 [ V_72 ] -> V_50 == V_67 )
continue;
V_18 = F_68 ( V_5 ,
V_70 [ V_72 ] ,
V_59 ,
V_43 ) ;
if ( V_18 < 0 ) {
V_60 = V_18 ;
break;
}
V_60 |= V_18 ;
}
for ( V_72 = 0 ; V_72 < V_71 ; V_72 ++ )
F_63 ( V_70 [ V_72 ] ) ;
F_42 ( V_70 ) ;
} else {
V_69 = F_78 ( V_65 ) ;
}
if ( V_60 >= 0 && V_69 && V_69 -> V_50 != V_67 ) {
V_18 = F_68 ( V_5 ,
V_69 ,
V_59 ,
V_43 ) ;
if ( V_18 < 0 )
V_60 = V_18 ;
else
V_60 |= V_18 ;
}
F_63 ( V_69 ) ;
return V_60 ;
}
