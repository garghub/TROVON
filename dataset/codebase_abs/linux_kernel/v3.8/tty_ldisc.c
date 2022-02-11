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
F_5 ( & V_5 , V_4 ) ;
if ( F_6 ( & V_2 -> V_3 ) ) {
struct V_6 * V_7 = V_2 -> V_8 ;
V_7 -> V_9 -- ;
F_7 ( V_7 -> V_10 ) ;
F_8 ( & V_5 , V_4 ) ;
F_9 ( V_2 ) ;
return;
}
F_8 ( & V_5 , V_4 ) ;
F_10 ( & V_2 -> V_11 ) ;
}
int F_11 ( int V_12 , struct V_6 * V_13 )
{
unsigned long V_4 ;
int V_14 = 0 ;
if ( V_12 < V_15 || V_12 >= V_16 )
return - V_17 ;
F_5 ( & V_5 , V_4 ) ;
V_18 [ V_12 ] = V_13 ;
V_13 -> V_19 = V_12 ;
V_13 -> V_9 = 0 ;
F_8 ( & V_5 , V_4 ) ;
return V_14 ;
}
int F_12 ( int V_12 )
{
unsigned long V_4 ;
int V_14 = 0 ;
if ( V_12 < V_15 || V_12 >= V_16 )
return - V_17 ;
F_5 ( & V_5 , V_4 ) ;
if ( V_18 [ V_12 ] -> V_9 )
V_14 = - V_20 ;
else
V_18 [ V_12 ] = NULL ;
F_8 ( & V_5 , V_4 ) ;
return V_14 ;
}
static struct V_6 * F_13 ( int V_12 )
{
unsigned long V_4 ;
struct V_6 * V_21 , * V_14 ;
F_5 ( & V_5 , V_4 ) ;
V_14 = F_14 ( - V_17 ) ;
V_21 = V_18 [ V_12 ] ;
if ( V_21 ) {
V_14 = F_14 ( - V_22 ) ;
if ( F_15 ( V_21 -> V_10 ) ) {
V_21 -> V_9 ++ ;
V_14 = V_21 ;
}
}
F_8 ( & V_5 , V_4 ) ;
return V_14 ;
}
static void F_16 ( struct V_6 * V_21 )
{
unsigned long V_4 ;
F_5 ( & V_5 , V_4 ) ;
V_21 -> V_9 -- ;
F_7 ( V_21 -> V_10 ) ;
F_8 ( & V_5 , V_4 ) ;
}
static struct V_1 * F_17 ( int V_12 )
{
struct V_1 * V_2 ;
struct V_6 * V_21 ;
if ( V_12 < V_15 || V_12 >= V_16 )
return F_14 ( - V_17 ) ;
V_21 = F_13 ( V_12 ) ;
if ( F_18 ( V_21 ) ) {
F_19 ( L_1 , V_12 ) ;
V_21 = F_13 ( V_12 ) ;
if ( F_18 ( V_21 ) )
return F_20 ( V_21 ) ;
}
V_2 = F_21 ( sizeof( struct V_1 ) , V_23 ) ;
if ( V_2 == NULL ) {
F_16 ( V_21 ) ;
return F_14 ( - V_24 ) ;
}
V_2 -> V_8 = V_21 ;
F_22 ( & V_2 -> V_3 , 1 ) ;
F_23 ( & V_2 -> V_11 ) ;
return V_2 ;
}
static void * F_24 ( struct V_25 * V_26 , T_1 * V_27 )
{
return ( * V_27 < V_16 ) ? V_27 : NULL ;
}
static void * F_25 ( struct V_25 * V_26 , void * V_28 , T_1 * V_27 )
{
( * V_27 ) ++ ;
return ( * V_27 < V_16 ) ? V_27 : NULL ;
}
static void F_26 ( struct V_25 * V_26 , void * V_28 )
{
}
static int F_27 ( struct V_25 * V_26 , void * V_28 )
{
int V_29 = * ( T_1 * ) V_28 ;
struct V_6 * V_21 ;
V_21 = F_13 ( V_29 ) ;
if ( F_18 ( V_21 ) )
return 0 ;
F_28 ( V_26 , L_2 , V_21 -> V_30 ? V_21 -> V_30 : L_3 , V_29 ) ;
F_16 ( V_21 ) ;
return 0 ;
}
static int F_29 ( struct V_31 * V_31 , struct V_32 * V_32 )
{
return F_30 ( V_32 , & V_33 ) ;
}
static void F_31 ( struct V_34 * V_35 , struct V_1 * V_2 )
{
V_35 -> V_36 = V_2 ;
}
static struct V_1 * F_32 ( struct V_34 * V_35 )
{
unsigned long V_4 ;
struct V_1 * V_2 ;
F_5 ( & V_5 , V_4 ) ;
V_2 = NULL ;
if ( F_33 ( V_37 , & V_35 -> V_4 ) )
V_2 = F_1 ( V_35 -> V_36 ) ;
F_8 ( & V_5 , V_4 ) ;
return V_2 ;
}
struct V_1 * F_34 ( struct V_34 * V_35 )
{
struct V_1 * V_2 ;
F_35 ( V_38 , ( V_2 = F_32 ( V_35 ) ) != NULL ) ;
return V_2 ;
}
struct V_1 * F_36 ( struct V_34 * V_35 )
{
return F_32 ( V_35 ) ;
}
void F_37 ( struct V_1 * V_2 )
{
F_3 ( V_2 ) ;
}
static inline void F_38 ( struct V_1 * V_2 )
{
F_3 ( V_2 ) ;
}
void F_39 ( struct V_34 * V_35 )
{
F_40 ( V_37 , & V_35 -> V_4 ) ;
F_41 ( V_39 , & V_35 -> V_4 ) ;
F_10 ( & V_38 ) ;
}
void F_42 ( struct V_34 * V_35 )
{
struct V_1 * V_2 = F_36 ( V_35 ) ;
if ( V_2 ) {
if ( V_2 -> V_8 -> V_40 )
V_2 -> V_8 -> V_40 ( V_35 ) ;
F_37 ( V_2 ) ;
}
F_43 ( V_35 ) ;
}
static void F_44 ( struct V_34 * V_35 , int V_19 )
{
F_45 ( & V_35 -> V_41 ) ;
V_35 -> V_42 . V_43 = V_19 ;
F_46 ( & V_35 -> V_41 ) ;
}
static int F_47 ( struct V_34 * V_35 , struct V_1 * V_2 )
{
F_48 ( F_49 ( V_44 , & V_35 -> V_4 ) ) ;
if ( V_2 -> V_8 -> V_45 ) {
int V_14 ;
V_14 = V_2 -> V_8 -> V_45 ( V_35 ) ;
if ( V_14 )
F_41 ( V_44 , & V_35 -> V_4 ) ;
return V_14 ;
}
return 0 ;
}
static void F_50 ( struct V_34 * V_35 , struct V_1 * V_2 )
{
F_48 ( ! F_33 ( V_44 , & V_35 -> V_4 ) ) ;
F_41 ( V_44 , & V_35 -> V_4 ) ;
if ( V_2 -> V_8 -> V_46 )
V_2 -> V_8 -> V_46 ( V_35 ) ;
}
static void F_51 ( struct V_34 * V_35 , struct V_1 * V_47 )
{
char V_48 [ 64 ] ;
struct V_1 * V_13 ;
int V_49 ;
V_47 = F_17 ( V_47 -> V_8 -> V_19 ) ;
F_48 ( F_18 ( V_47 ) ) ;
F_31 ( V_35 , V_47 ) ;
F_44 ( V_35 , V_47 -> V_8 -> V_19 ) ;
if ( F_47 ( V_35 , V_47 ) < 0 ) {
F_38 ( V_47 ) ;
V_13 = F_17 ( V_15 ) ;
if ( F_18 ( V_13 ) )
F_52 ( L_4 ) ;
F_31 ( V_35 , V_13 ) ;
F_44 ( V_35 , V_15 ) ;
V_49 = F_47 ( V_35 , V_13 ) ;
if ( V_49 < 0 )
F_52 ( L_5
L_6 ,
F_53 ( V_35 , V_48 ) , V_49 ) ;
}
}
static int F_54 ( struct V_34 * V_35 )
{
F_41 ( V_37 , & V_35 -> V_4 ) ;
return F_55 ( & V_35 -> V_50 -> V_48 . V_51 ) ;
}
static void F_56 ( struct V_34 * V_35 )
{
F_57 ( & V_35 -> V_52 ) ;
F_57 ( & V_35 -> V_53 ) ;
F_57 ( & V_35 -> V_50 -> V_48 . V_51 ) ;
}
static int F_58 ( struct V_34 * V_35 , long V_54 )
{
long V_14 ;
V_14 = F_59 ( V_35 -> V_36 -> V_11 ,
F_60 ( & V_35 -> V_36 -> V_3 ) == 1 , V_54 ) ;
return V_14 > 0 ? 0 : - V_20 ;
}
int F_61 ( struct V_34 * V_35 , int V_36 )
{
int V_55 ;
struct V_1 * V_56 , * V_13 ;
int V_51 , V_57 = 0 ;
struct V_34 * V_58 ;
V_13 = F_17 ( V_36 ) ;
if ( F_18 ( V_13 ) )
return F_62 ( V_13 ) ;
F_63 ( V_35 ) ;
V_58 = V_35 -> V_59 ;
if ( V_35 -> V_36 -> V_8 -> V_19 == V_36 ) {
F_64 ( V_35 ) ;
F_38 ( V_13 ) ;
return 0 ;
}
F_64 ( V_35 ) ;
F_65 ( V_35 , 0 ) ;
F_63 ( V_35 ) ;
F_45 ( & V_35 -> V_60 ) ;
while ( F_33 ( V_39 , & V_35 -> V_4 ) ) {
F_46 ( & V_35 -> V_60 ) ;
F_64 ( V_35 ) ;
F_35 ( V_38 ,
F_33 ( V_39 , & V_35 -> V_4 ) == 0 ) ;
F_63 ( V_35 ) ;
F_45 ( & V_35 -> V_60 ) ;
}
F_40 ( V_39 , & V_35 -> V_4 ) ;
V_35 -> V_61 = 0 ;
V_56 = V_35 -> V_36 ;
F_64 ( V_35 ) ;
V_51 = F_54 ( V_35 ) ;
if ( V_58 )
V_57 = F_54 ( V_58 ) ;
F_46 ( & V_35 -> V_60 ) ;
F_56 ( V_35 ) ;
V_55 = F_58 ( V_35 , 5 * V_62 ) ;
F_63 ( V_35 ) ;
F_45 ( & V_35 -> V_60 ) ;
if ( V_55 ) {
F_38 ( V_13 ) ;
goto V_63;
}
if ( F_33 ( V_64 , & V_35 -> V_4 ) ) {
F_41 ( V_39 , & V_35 -> V_4 ) ;
F_46 ( & V_35 -> V_60 ) ;
F_38 ( V_13 ) ;
F_64 ( V_35 ) ;
return - V_65 ;
}
F_50 ( V_35 , V_56 ) ;
F_31 ( V_35 , V_13 ) ;
F_44 ( V_35 , V_36 ) ;
V_55 = F_47 ( V_35 , V_13 ) ;
if ( V_55 < 0 ) {
F_38 ( V_13 ) ;
F_51 ( V_35 , V_56 ) ;
}
if ( V_35 -> V_36 -> V_8 -> V_19 != V_56 -> V_8 -> V_19 && V_35 -> V_8 -> V_66 )
V_35 -> V_8 -> V_66 ( V_35 ) ;
F_38 ( V_56 ) ;
V_63:
F_39 ( V_35 ) ;
if ( V_58 )
F_39 ( V_58 ) ;
if ( V_51 )
F_66 ( & V_35 -> V_50 -> V_48 . V_51 ) ;
if ( V_57 )
F_66 ( & V_58 -> V_50 -> V_48 . V_51 ) ;
F_46 ( & V_35 -> V_60 ) ;
F_64 ( V_35 ) ;
return V_55 ;
}
static void F_67 ( struct V_34 * V_35 )
{
F_45 ( & V_35 -> V_41 ) ;
V_35 -> V_42 = V_35 -> V_67 -> V_68 ;
V_35 -> V_42 . V_69 = F_68 ( & V_35 -> V_42 ) ;
V_35 -> V_42 . V_70 = F_69 ( & V_35 -> V_42 ) ;
F_46 ( & V_35 -> V_41 ) ;
}
static int F_70 ( struct V_34 * V_35 , int V_36 )
{
struct V_1 * V_2 = F_17 ( V_36 ) ;
if ( F_18 ( V_2 ) )
return - 1 ;
F_50 ( V_35 , V_35 -> V_36 ) ;
F_38 ( V_35 -> V_36 ) ;
V_35 -> V_36 = NULL ;
F_31 ( V_35 , V_2 ) ;
F_44 ( V_35 , V_36 ) ;
return 0 ;
}
void F_71 ( struct V_34 * V_35 )
{
struct V_1 * V_2 ;
int V_71 = V_35 -> V_67 -> V_4 & V_72 ;
int V_73 = 0 ;
V_2 = F_36 ( V_35 ) ;
if ( V_2 != NULL ) {
if ( V_2 -> V_8 -> V_40 )
V_2 -> V_8 -> V_40 ( V_35 ) ;
F_72 ( V_35 ) ;
if ( ( F_33 ( V_74 , & V_35 -> V_4 ) ) &&
V_2 -> V_8 -> V_75 )
V_2 -> V_8 -> V_75 ( V_35 ) ;
if ( V_2 -> V_8 -> V_76 )
V_2 -> V_8 -> V_76 ( V_35 ) ;
F_37 ( V_2 ) ;
}
F_73 ( & V_35 -> V_77 , V_78 ) ;
F_73 ( & V_35 -> V_79 , V_80 ) ;
F_45 ( & V_35 -> V_60 ) ;
F_41 ( V_37 , & V_35 -> V_4 ) ;
F_64 ( V_35 ) ;
F_55 ( & V_35 -> V_50 -> V_48 . V_51 ) ;
F_46 ( & V_35 -> V_60 ) ;
V_81:
F_63 ( V_35 ) ;
F_45 ( & V_35 -> V_60 ) ;
if ( V_35 -> V_36 ) {
if ( F_60 ( & V_35 -> V_36 -> V_3 ) != 1 ) {
char V_82 [ V_83 ] , V_84 [ 64 ] ;
long V_54 = 3 * V_62 ;
F_64 ( V_35 ) ;
while ( F_58 ( V_35 , V_54 ) == - V_20 ) {
V_54 = V_85 ;
F_74 ( V_86
L_7 ,
V_87 , F_75 ( V_82 , V_88 ) ,
F_53 ( V_35 , V_84 ) ) ;
}
F_46 ( & V_35 -> V_60 ) ;
goto V_81;
}
if ( V_71 == 0 ) {
if ( ! F_70 ( V_35 , V_35 -> V_42 . V_43 ) )
V_73 = F_47 ( V_35 , V_35 -> V_36 ) ;
else
V_73 = 1 ;
}
if ( V_71 || V_73 ) {
F_76 ( F_70 ( V_35 , V_15 ) ) ;
F_48 ( F_47 ( V_35 , V_35 -> V_36 ) ) ;
}
F_39 ( V_35 ) ;
}
F_46 ( & V_35 -> V_60 ) ;
if ( V_71 )
F_67 ( V_35 ) ;
}
int F_77 ( struct V_34 * V_35 , struct V_34 * V_58 )
{
struct V_1 * V_2 = V_35 -> V_36 ;
int V_55 ;
V_55 = F_47 ( V_35 , V_2 ) ;
if ( V_55 )
return V_55 ;
if ( V_58 ) {
V_55 = F_47 ( V_58 , V_58 -> V_36 ) ;
if ( V_55 ) {
F_50 ( V_35 , V_2 ) ;
return V_55 ;
}
F_39 ( V_58 ) ;
}
F_39 ( V_35 ) ;
return 0 ;
}
static void F_78 ( struct V_34 * V_35 )
{
F_58 ( V_35 , V_85 ) ;
F_45 ( & V_35 -> V_60 ) ;
F_50 ( V_35 , V_35 -> V_36 ) ;
F_38 ( V_35 -> V_36 ) ;
V_35 -> V_36 = NULL ;
F_44 ( V_35 , V_15 ) ;
F_46 ( & V_35 -> V_60 ) ;
}
void F_79 ( struct V_34 * V_35 , struct V_34 * V_58 )
{
F_80 ( V_35 , V_58 ) ;
F_54 ( V_35 ) ;
F_56 ( V_35 ) ;
if ( V_58 ) {
F_54 ( V_58 ) ;
F_56 ( V_58 ) ;
}
F_78 ( V_35 ) ;
if ( V_58 )
F_78 ( V_58 ) ;
F_81 ( V_35 , V_58 ) ;
}
void F_82 ( struct V_34 * V_35 )
{
struct V_1 * V_2 = F_17 ( V_15 ) ;
if ( F_18 ( V_2 ) )
F_52 ( L_8 ) ;
F_31 ( V_35 , V_2 ) ;
}
void F_83 ( struct V_34 * V_35 )
{
F_3 ( V_35 -> V_36 ) ;
F_31 ( V_35 , NULL ) ;
}
void F_84 ( void )
{
( void ) F_11 ( V_15 , & V_89 ) ;
}
