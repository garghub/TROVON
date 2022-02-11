static inline struct V_1 * F_1 ( struct V_1 * V_2 )
{
if ( V_2 )
F_2 ( & V_2 -> V_3 ) ;
return V_2 ;
}
static void F_3 ( struct V_1 * V_2 )
{
unsigned long V_4 ;
if ( F_4 ( ! V_2 ) )
return;
F_5 ( V_4 ) ;
if ( F_6 ( & V_2 -> V_3 , & V_5 ) ) {
struct V_6 * V_7 = V_2 -> V_8 ;
V_7 -> V_9 -- ;
F_7 ( V_7 -> V_10 ) ;
F_8 ( & V_5 , V_4 ) ;
F_9 ( V_2 ) ;
return;
}
F_10 ( V_4 ) ;
F_11 ( & V_11 ) ;
}
int F_12 ( int V_12 , struct V_6 * V_13 )
{
unsigned long V_4 ;
int V_14 = 0 ;
if ( V_12 < V_15 || V_12 >= V_16 )
return - V_17 ;
F_13 ( & V_5 , V_4 ) ;
V_18 [ V_12 ] = V_13 ;
V_13 -> V_19 = V_12 ;
V_13 -> V_9 = 0 ;
F_8 ( & V_5 , V_4 ) ;
return V_14 ;
}
int F_14 ( int V_12 )
{
unsigned long V_4 ;
int V_14 = 0 ;
if ( V_12 < V_15 || V_12 >= V_16 )
return - V_17 ;
F_13 ( & V_5 , V_4 ) ;
if ( V_18 [ V_12 ] -> V_9 )
V_14 = - V_20 ;
else
V_18 [ V_12 ] = NULL ;
F_8 ( & V_5 , V_4 ) ;
return V_14 ;
}
static struct V_6 * F_15 ( int V_12 )
{
unsigned long V_4 ;
struct V_6 * V_21 , * V_14 ;
F_13 ( & V_5 , V_4 ) ;
V_14 = F_16 ( - V_17 ) ;
V_21 = V_18 [ V_12 ] ;
if ( V_21 ) {
V_14 = F_16 ( - V_22 ) ;
if ( F_17 ( V_21 -> V_10 ) ) {
V_21 -> V_9 ++ ;
V_14 = V_21 ;
}
}
F_8 ( & V_5 , V_4 ) ;
return V_14 ;
}
static void F_18 ( struct V_6 * V_21 )
{
unsigned long V_4 ;
F_13 ( & V_5 , V_4 ) ;
V_21 -> V_9 -- ;
F_7 ( V_21 -> V_10 ) ;
F_8 ( & V_5 , V_4 ) ;
}
static struct V_1 * F_19 ( int V_12 )
{
struct V_1 * V_2 ;
struct V_6 * V_21 ;
if ( V_12 < V_15 || V_12 >= V_16 )
return F_16 ( - V_17 ) ;
V_21 = F_15 ( V_12 ) ;
if ( F_20 ( V_21 ) ) {
F_21 ( L_1 , V_12 ) ;
V_21 = F_15 ( V_12 ) ;
if ( F_20 ( V_21 ) )
return F_22 ( V_21 ) ;
}
V_2 = F_23 ( sizeof( struct V_1 ) , V_23 ) ;
if ( V_2 == NULL ) {
F_18 ( V_21 ) ;
return F_16 ( - V_24 ) ;
}
V_2 -> V_8 = V_21 ;
F_24 ( & V_2 -> V_3 , 1 ) ;
return V_2 ;
}
static void * F_25 ( struct V_25 * V_26 , T_1 * V_27 )
{
return ( * V_27 < V_16 ) ? V_27 : NULL ;
}
static void * F_26 ( struct V_25 * V_26 , void * V_28 , T_1 * V_27 )
{
( * V_27 ) ++ ;
return ( * V_27 < V_16 ) ? V_27 : NULL ;
}
static void F_27 ( struct V_25 * V_26 , void * V_28 )
{
}
static int F_28 ( struct V_25 * V_26 , void * V_28 )
{
int V_29 = * ( T_1 * ) V_28 ;
struct V_6 * V_21 ;
V_21 = F_15 ( V_29 ) ;
if ( F_20 ( V_21 ) )
return 0 ;
F_29 ( V_26 , L_2 , V_21 -> V_30 ? V_21 -> V_30 : L_3 , V_29 ) ;
F_18 ( V_21 ) ;
return 0 ;
}
static int F_30 ( struct V_31 * V_31 , struct V_32 * V_32 )
{
return F_31 ( V_32 , & V_33 ) ;
}
static void F_32 ( struct V_34 * V_35 , struct V_1 * V_2 )
{
V_35 -> V_36 = V_2 ;
}
static struct V_1 * F_33 ( struct V_34 * V_35 )
{
unsigned long V_4 ;
struct V_1 * V_2 ;
F_13 ( & V_5 , V_4 ) ;
V_2 = NULL ;
if ( F_34 ( V_37 , & V_35 -> V_4 ) )
V_2 = F_1 ( V_35 -> V_36 ) ;
F_8 ( & V_5 , V_4 ) ;
return V_2 ;
}
struct V_1 * F_35 ( struct V_34 * V_35 )
{
struct V_1 * V_2 ;
F_36 ( V_38 , ( V_2 = F_33 ( V_35 ) ) != NULL ) ;
return V_2 ;
}
struct V_1 * F_37 ( struct V_34 * V_35 )
{
return F_33 ( V_35 ) ;
}
void F_38 ( struct V_1 * V_2 )
{
F_3 ( V_2 ) ;
}
static inline void F_39 ( struct V_1 * V_2 )
{
F_3 ( V_2 ) ;
}
void F_40 ( struct V_34 * V_35 )
{
F_41 ( V_37 , & V_35 -> V_4 ) ;
F_42 ( V_39 , & V_35 -> V_4 ) ;
F_11 ( & V_38 ) ;
}
void F_43 ( struct V_34 * V_35 )
{
struct V_1 * V_2 = F_37 ( V_35 ) ;
if ( V_2 ) {
if ( V_2 -> V_8 -> V_40 )
V_2 -> V_8 -> V_40 ( V_35 ) ;
F_38 ( V_2 ) ;
}
F_44 ( V_35 ) ;
}
static void F_45 ( struct V_34 * V_35 , int V_19 )
{
F_46 ( & V_35 -> V_41 ) ;
V_35 -> V_42 -> V_43 = V_19 ;
F_47 ( & V_35 -> V_41 ) ;
}
static int F_48 ( struct V_34 * V_35 , struct V_1 * V_2 )
{
F_49 ( F_50 ( V_44 , & V_35 -> V_4 ) ) ;
if ( V_2 -> V_8 -> V_45 ) {
int V_14 ;
F_49 ( ! F_51 () ) ;
V_14 = V_2 -> V_8 -> V_45 ( V_35 ) ;
if ( V_14 )
F_42 ( V_44 , & V_35 -> V_4 ) ;
return V_14 ;
}
return 0 ;
}
static void F_52 ( struct V_34 * V_35 , struct V_1 * V_2 )
{
F_49 ( ! F_34 ( V_44 , & V_35 -> V_4 ) ) ;
F_42 ( V_44 , & V_35 -> V_4 ) ;
if ( V_2 -> V_8 -> V_46 )
V_2 -> V_8 -> V_46 ( V_35 ) ;
}
static void F_53 ( struct V_34 * V_35 , struct V_1 * V_47 )
{
char V_48 [ 64 ] ;
struct V_1 * V_13 ;
int V_49 ;
V_47 = F_19 ( V_47 -> V_8 -> V_19 ) ;
F_49 ( F_20 ( V_47 ) ) ;
F_32 ( V_35 , V_47 ) ;
F_45 ( V_35 , V_47 -> V_8 -> V_19 ) ;
if ( F_48 ( V_35 , V_47 ) < 0 ) {
F_39 ( V_47 ) ;
V_13 = F_19 ( V_15 ) ;
if ( F_20 ( V_13 ) )
F_54 ( L_4 ) ;
F_32 ( V_35 , V_13 ) ;
F_45 ( V_35 , V_15 ) ;
V_49 = F_48 ( V_35 , V_13 ) ;
if ( V_49 < 0 )
F_54 ( L_5
L_6 ,
F_55 ( V_35 , V_48 ) , V_49 ) ;
}
}
static int F_56 ( struct V_34 * V_35 )
{
F_42 ( V_37 , & V_35 -> V_4 ) ;
return F_57 ( & V_35 -> V_48 . V_50 ) ;
}
static void F_58 ( struct V_34 * V_35 )
{
F_59 ( & V_35 -> V_51 ) ;
F_59 ( & V_35 -> V_52 ) ;
F_59 ( & V_35 -> V_48 . V_50 ) ;
}
static int F_60 ( struct V_34 * V_35 )
{
int V_14 ;
V_14 = F_61 ( V_11 ,
F_62 ( & V_35 -> V_36 -> V_3 ) == 1 , 5 * V_53 ) ;
if ( V_14 < 0 )
return V_14 ;
return V_14 > 0 ? 0 : - V_20 ;
}
int F_63 ( struct V_34 * V_35 , int V_36 )
{
int V_54 ;
struct V_1 * V_55 , * V_13 ;
int V_50 , V_56 = 0 ;
struct V_34 * V_57 ;
V_13 = F_19 ( V_36 ) ;
if ( F_20 ( V_13 ) )
return F_64 ( V_13 ) ;
F_65 () ;
V_57 = V_35 -> V_58 ;
if ( V_35 -> V_36 -> V_8 -> V_19 == V_36 ) {
F_66 () ;
F_39 ( V_13 ) ;
return 0 ;
}
F_66 () ;
F_67 ( V_35 , 0 ) ;
F_65 () ;
F_46 ( & V_35 -> V_59 ) ;
while ( F_34 ( V_39 , & V_35 -> V_4 ) ) {
F_47 ( & V_35 -> V_59 ) ;
F_66 () ;
F_36 ( V_38 ,
F_34 ( V_39 , & V_35 -> V_4 ) == 0 ) ;
F_65 () ;
F_46 ( & V_35 -> V_59 ) ;
}
F_41 ( V_39 , & V_35 -> V_4 ) ;
V_35 -> V_60 = 0 ;
V_55 = V_35 -> V_36 ;
F_66 () ;
V_50 = F_56 ( V_35 ) ;
if ( V_57 )
V_56 = F_56 ( V_57 ) ;
F_47 ( & V_35 -> V_59 ) ;
F_58 ( V_35 ) ;
V_54 = F_60 ( V_35 ) ;
F_65 () ;
F_46 ( & V_35 -> V_59 ) ;
if ( V_54 ) {
F_39 ( V_13 ) ;
goto V_61;
}
if ( F_34 ( V_62 , & V_35 -> V_4 ) ) {
F_42 ( V_39 , & V_35 -> V_4 ) ;
F_47 ( & V_35 -> V_59 ) ;
F_39 ( V_13 ) ;
F_66 () ;
return - V_63 ;
}
F_52 ( V_35 , V_55 ) ;
F_32 ( V_35 , V_13 ) ;
F_45 ( V_35 , V_36 ) ;
V_54 = F_48 ( V_35 , V_13 ) ;
if ( V_54 < 0 ) {
F_39 ( V_13 ) ;
F_53 ( V_35 , V_55 ) ;
}
if ( V_35 -> V_36 -> V_8 -> V_19 != V_55 -> V_8 -> V_19 && V_35 -> V_8 -> V_64 )
V_35 -> V_8 -> V_64 ( V_35 ) ;
F_39 ( V_55 ) ;
V_61:
F_40 ( V_35 ) ;
if ( V_57 )
F_40 ( V_57 ) ;
if ( V_50 )
F_68 ( & V_35 -> V_48 . V_50 ) ;
if ( V_56 )
F_68 ( & V_57 -> V_48 . V_50 ) ;
F_47 ( & V_35 -> V_59 ) ;
F_66 () ;
return V_54 ;
}
static void F_69 ( struct V_34 * V_35 )
{
F_46 ( & V_35 -> V_41 ) ;
* V_35 -> V_42 = V_35 -> V_65 -> V_66 ;
V_35 -> V_42 -> V_67 = F_70 ( V_35 -> V_42 ) ;
V_35 -> V_42 -> V_68 = F_71 ( V_35 -> V_42 ) ;
F_47 ( & V_35 -> V_41 ) ;
}
static int F_72 ( struct V_34 * V_35 , int V_36 )
{
struct V_1 * V_2 = F_19 ( V_36 ) ;
if ( F_20 ( V_2 ) )
return - 1 ;
F_4 ( F_60 ( V_35 ) ) ;
F_52 ( V_35 , V_35 -> V_36 ) ;
F_39 ( V_35 -> V_36 ) ;
V_35 -> V_36 = NULL ;
F_32 ( V_35 , V_2 ) ;
F_45 ( V_35 , V_36 ) ;
return 0 ;
}
void F_73 ( struct V_34 * V_35 )
{
struct V_1 * V_2 ;
int V_69 = V_35 -> V_65 -> V_4 & V_70 ;
int V_71 = 0 ;
V_2 = F_37 ( V_35 ) ;
if ( V_2 != NULL ) {
if ( V_2 -> V_8 -> V_40 )
V_2 -> V_8 -> V_40 ( V_35 ) ;
F_74 ( V_35 ) ;
if ( ( F_34 ( V_72 , & V_35 -> V_4 ) ) &&
V_2 -> V_8 -> V_73 )
V_2 -> V_8 -> V_73 ( V_35 ) ;
if ( V_2 -> V_8 -> V_74 )
V_2 -> V_8 -> V_74 ( V_35 ) ;
F_38 ( V_2 ) ;
}
F_75 ( & V_35 -> V_75 , V_76 ) ;
F_75 ( & V_35 -> V_77 , V_78 ) ;
F_46 ( & V_35 -> V_59 ) ;
F_42 ( V_37 , & V_35 -> V_4 ) ;
F_66 () ;
F_57 ( & V_35 -> V_48 . V_50 ) ;
F_47 ( & V_35 -> V_59 ) ;
F_65 () ;
F_46 ( & V_35 -> V_59 ) ;
if ( V_35 -> V_36 ) {
if ( V_69 == 0 ) {
if ( ! F_72 ( V_35 , V_35 -> V_42 -> V_43 ) )
V_71 = F_48 ( V_35 , V_35 -> V_36 ) ;
else
V_71 = 1 ;
}
if ( V_69 || V_71 ) {
F_76 ( F_72 ( V_35 , V_15 ) ) ;
F_49 ( F_48 ( V_35 , V_35 -> V_36 ) ) ;
}
F_40 ( V_35 ) ;
}
F_47 ( & V_35 -> V_59 ) ;
if ( V_69 )
F_69 ( V_35 ) ;
}
int F_77 ( struct V_34 * V_35 , struct V_34 * V_57 )
{
struct V_1 * V_2 = V_35 -> V_36 ;
int V_54 ;
V_54 = F_48 ( V_35 , V_2 ) ;
if ( V_54 )
return V_54 ;
if ( V_57 ) {
V_54 = F_48 ( V_57 , V_57 -> V_36 ) ;
if ( V_54 ) {
F_52 ( V_35 , V_2 ) ;
return V_54 ;
}
F_40 ( V_57 ) ;
}
F_40 ( V_35 ) ;
return 0 ;
}
void F_78 ( struct V_34 * V_35 , struct V_34 * V_57 )
{
F_66 () ;
F_56 ( V_35 ) ;
F_58 ( V_35 ) ;
F_65 () ;
F_46 ( & V_35 -> V_59 ) ;
F_52 ( V_35 , V_35 -> V_36 ) ;
F_39 ( V_35 -> V_36 ) ;
V_35 -> V_36 = NULL ;
F_45 ( V_35 , V_15 ) ;
F_47 ( & V_35 -> V_59 ) ;
if ( V_57 )
F_78 ( V_57 , NULL ) ;
}
void F_79 ( struct V_34 * V_35 )
{
struct V_1 * V_2 = F_19 ( V_15 ) ;
if ( F_20 ( V_2 ) )
F_54 ( L_7 ) ;
F_32 ( V_35 , V_2 ) ;
}
void F_80 ( struct V_34 * V_35 )
{
F_3 ( V_35 -> V_36 ) ;
F_32 ( V_35 , NULL ) ;
}
void F_81 ( void )
{
( void ) F_12 ( V_15 , & V_79 ) ;
}
