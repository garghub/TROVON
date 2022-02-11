int F_1 ( int V_1 , struct V_2 * V_3 )
{
unsigned long V_4 ;
int V_5 = 0 ;
if ( V_1 < V_6 || V_1 >= V_7 )
return - V_8 ;
F_2 ( & V_9 , V_4 ) ;
V_10 [ V_1 ] = V_3 ;
V_3 -> V_11 = V_1 ;
V_3 -> V_12 = 0 ;
F_3 ( & V_9 , V_4 ) ;
return V_5 ;
}
int F_4 ( int V_1 )
{
unsigned long V_4 ;
int V_5 = 0 ;
if ( V_1 < V_6 || V_1 >= V_7 )
return - V_8 ;
F_2 ( & V_9 , V_4 ) ;
if ( V_10 [ V_1 ] -> V_12 )
V_5 = - V_13 ;
else
V_10 [ V_1 ] = NULL ;
F_3 ( & V_9 , V_4 ) ;
return V_5 ;
}
static struct V_2 * F_5 ( int V_1 )
{
unsigned long V_4 ;
struct V_2 * V_14 , * V_5 ;
F_2 ( & V_9 , V_4 ) ;
V_5 = F_6 ( - V_8 ) ;
V_14 = V_10 [ V_1 ] ;
if ( V_14 ) {
V_5 = F_6 ( - V_15 ) ;
if ( F_7 ( V_14 -> V_16 ) ) {
V_14 -> V_12 ++ ;
V_5 = V_14 ;
}
}
F_3 ( & V_9 , V_4 ) ;
return V_5 ;
}
static void F_8 ( struct V_2 * V_14 )
{
unsigned long V_4 ;
F_2 ( & V_9 , V_4 ) ;
V_14 -> V_12 -- ;
F_9 ( V_14 -> V_16 ) ;
F_3 ( & V_9 , V_4 ) ;
}
static struct V_17 * F_10 ( int V_1 )
{
struct V_17 * V_18 ;
struct V_2 * V_14 ;
if ( V_1 < V_6 || V_1 >= V_7 )
return F_6 ( - V_8 ) ;
V_14 = F_5 ( V_1 ) ;
if ( F_11 ( V_14 ) ) {
F_12 ( L_1 , V_1 ) ;
V_14 = F_5 ( V_1 ) ;
if ( F_11 ( V_14 ) )
return F_13 ( V_14 ) ;
}
V_18 = F_14 ( sizeof( struct V_17 ) , V_19 ) ;
if ( V_18 == NULL ) {
F_8 ( V_14 ) ;
return F_6 ( - V_20 ) ;
}
V_18 -> V_21 = V_14 ;
F_15 ( & V_18 -> V_22 , 1 ) ;
F_16 ( & V_18 -> V_23 ) ;
return V_18 ;
}
static inline void F_17 ( struct V_17 * V_18 )
{
unsigned long V_4 ;
if ( F_18 ( ! V_18 ) )
return;
F_2 ( & V_9 , V_4 ) ;
F_19 ( ! F_20 ( & V_18 -> V_22 ) ) ;
V_18 -> V_21 -> V_12 -- ;
F_9 ( V_18 -> V_21 -> V_16 ) ;
F_21 ( V_18 ) ;
F_3 ( & V_9 , V_4 ) ;
}
static void * F_22 ( struct V_24 * V_25 , T_1 * V_26 )
{
return ( * V_26 < V_7 ) ? V_26 : NULL ;
}
static void * F_23 ( struct V_24 * V_25 , void * V_27 , T_1 * V_26 )
{
( * V_26 ) ++ ;
return ( * V_26 < V_7 ) ? V_26 : NULL ;
}
static void F_24 ( struct V_24 * V_25 , void * V_27 )
{
}
static int F_25 ( struct V_24 * V_25 , void * V_27 )
{
int V_28 = * ( T_1 * ) V_27 ;
struct V_2 * V_14 ;
V_14 = F_5 ( V_28 ) ;
if ( F_11 ( V_14 ) )
return 0 ;
F_26 ( V_25 , L_2 , V_14 -> V_29 ? V_14 -> V_29 : L_3 , V_28 ) ;
F_8 ( V_14 ) ;
return 0 ;
}
static int F_27 ( struct V_30 * V_30 , struct V_31 * V_31 )
{
return F_28 ( V_31 , & V_32 ) ;
}
static struct V_17 * F_29 ( struct V_33 * V_34 )
{
unsigned long V_4 ;
struct V_17 * V_18 ;
F_2 ( & V_9 , V_4 ) ;
V_18 = NULL ;
if ( F_30 ( V_35 , & V_34 -> V_4 ) && V_34 -> V_36 ) {
V_18 = V_34 -> V_36 ;
F_31 ( & V_18 -> V_22 ) ;
}
F_3 ( & V_9 , V_4 ) ;
return V_18 ;
}
struct V_17 * F_32 ( struct V_33 * V_34 )
{
struct V_17 * V_18 ;
F_33 ( V_37 , ( V_18 = F_29 ( V_34 ) ) != NULL ) ;
return V_18 ;
}
struct V_17 * F_34 ( struct V_33 * V_34 )
{
return F_29 ( V_34 ) ;
}
void F_35 ( struct V_17 * V_18 )
{
unsigned long V_4 ;
if ( F_18 ( ! V_18 ) )
return;
F_2 ( & V_9 , V_4 ) ;
F_19 ( F_20 ( & V_18 -> V_22 ) ) ;
F_3 ( & V_9 , V_4 ) ;
if ( F_36 ( & V_18 -> V_23 ) )
F_37 ( & V_18 -> V_23 ) ;
}
static void F_38 ( struct V_33 * V_34 )
{
F_39 ( V_38 , & V_34 -> V_4 ) ;
F_40 ( V_35 , & V_34 -> V_4 ) ;
F_39 ( V_39 , & V_34 -> V_4 ) ;
F_37 ( & V_37 ) ;
}
void F_41 ( struct V_33 * V_34 )
{
struct V_17 * V_18 = F_34 ( V_34 ) ;
if ( V_18 ) {
if ( V_18 -> V_21 -> V_40 )
V_18 -> V_21 -> V_40 ( V_34 ) ;
F_35 ( V_18 ) ;
}
F_42 ( V_34 ) ;
}
static void F_43 ( struct V_33 * V_34 , int V_11 )
{
F_44 ( & V_34 -> V_41 ) ;
V_34 -> V_42 . V_43 = V_11 ;
F_45 ( & V_34 -> V_41 ) ;
}
static int F_46 ( struct V_33 * V_34 , struct V_17 * V_18 )
{
F_19 ( F_47 ( V_44 , & V_34 -> V_4 ) ) ;
if ( V_18 -> V_21 -> V_45 ) {
int V_5 ;
V_5 = V_18 -> V_21 -> V_45 ( V_34 ) ;
if ( V_5 )
F_39 ( V_44 , & V_34 -> V_4 ) ;
return V_5 ;
}
return 0 ;
}
static void F_48 ( struct V_33 * V_34 , struct V_17 * V_18 )
{
F_19 ( ! F_30 ( V_44 , & V_34 -> V_4 ) ) ;
F_39 ( V_44 , & V_34 -> V_4 ) ;
if ( V_18 -> V_21 -> V_46 )
V_18 -> V_21 -> V_46 ( V_34 ) ;
}
static void F_49 ( struct V_33 * V_34 , struct V_17 * V_47 )
{
char V_48 [ 64 ] ;
struct V_17 * V_3 ;
int V_49 ;
V_47 = F_10 ( V_47 -> V_21 -> V_11 ) ;
F_19 ( F_11 ( V_47 ) ) ;
V_34 -> V_36 = V_47 ;
F_43 ( V_34 , V_47 -> V_21 -> V_11 ) ;
if ( F_46 ( V_34 , V_47 ) < 0 ) {
F_17 ( V_47 ) ;
V_3 = F_10 ( V_6 ) ;
if ( F_11 ( V_3 ) )
F_50 ( L_4 ) ;
V_34 -> V_36 = V_3 ;
F_43 ( V_34 , V_6 ) ;
V_49 = F_46 ( V_34 , V_3 ) ;
if ( V_49 < 0 )
F_50 ( L_5
L_6 ,
F_51 ( V_34 , V_48 ) , V_49 ) ;
}
}
static int F_52 ( struct V_33 * V_34 , long V_50 )
{
long V_5 ;
V_5 = F_53 ( V_34 -> V_36 -> V_23 ,
F_54 ( & V_34 -> V_36 -> V_22 ) == 1 , V_50 ) ;
return V_5 > 0 ? 0 : - V_13 ;
}
static int F_55 ( struct V_33 * V_34 , struct V_33 * V_51 ,
long V_50 )
{
int V_52 ;
F_39 ( V_35 , & V_34 -> V_4 ) ;
if ( V_51 )
F_39 ( V_35 , & V_51 -> V_4 ) ;
V_52 = F_52 ( V_34 , V_50 ) ;
if ( ! V_52 && V_51 )
V_52 = F_52 ( V_51 , V_50 ) ;
if ( V_52 )
return V_52 ;
F_40 ( V_38 , & V_34 -> V_4 ) ;
if ( V_51 )
F_40 ( V_38 , & V_51 -> V_4 ) ;
return 0 ;
}
static bool F_56 ( struct V_33 * V_34 )
{
char V_53 [ V_54 ] , V_55 [ 64 ] ;
long V_50 = 3 * V_56 ;
F_39 ( V_35 , & V_34 -> V_4 ) ;
if ( V_34 -> V_36 ) {
F_57 ( V_34 ) ;
while ( F_52 ( V_34 , V_50 ) == - V_13 ) {
V_50 = V_57 ;
F_58 ( V_58
L_7 ,
V_59 , F_59 ( V_53 , V_60 ) ,
F_51 ( V_34 , V_55 ) ) ;
}
F_40 ( V_38 , & V_34 -> V_4 ) ;
F_45 ( & V_34 -> V_61 ) ;
F_60 ( V_34 ) ;
F_44 ( & V_34 -> V_61 ) ;
}
return ! ! V_34 -> V_36 ;
}
int F_61 ( struct V_33 * V_34 , int V_36 )
{
int V_52 ;
struct V_17 * V_62 , * V_3 ;
struct V_33 * V_51 ;
V_3 = F_10 ( V_36 ) ;
if ( F_11 ( V_3 ) )
return F_62 ( V_3 ) ;
F_60 ( V_34 ) ;
V_51 = V_34 -> V_63 ;
if ( V_34 -> V_36 -> V_21 -> V_11 == V_36 ) {
F_57 ( V_34 ) ;
F_17 ( V_3 ) ;
return 0 ;
}
F_44 ( & V_34 -> V_61 ) ;
while ( F_30 ( V_39 , & V_34 -> V_4 ) ) {
F_45 ( & V_34 -> V_61 ) ;
F_57 ( V_34 ) ;
F_33 ( V_37 ,
F_30 ( V_39 , & V_34 -> V_4 ) == 0 ) ;
F_60 ( V_34 ) ;
F_44 ( & V_34 -> V_61 ) ;
}
F_40 ( V_39 , & V_34 -> V_4 ) ;
V_34 -> V_64 = 0 ;
V_62 = V_34 -> V_36 ;
F_57 ( V_34 ) ;
V_52 = F_55 ( V_34 , V_51 , 5 * V_56 ) ;
F_45 ( & V_34 -> V_61 ) ;
F_63 ( & V_34 -> V_65 ) ;
F_60 ( V_34 ) ;
F_44 ( & V_34 -> V_61 ) ;
if ( V_52 ) {
F_17 ( V_3 ) ;
goto V_66;
}
if ( F_30 ( V_67 , & V_34 -> V_4 ) ) {
F_39 ( V_39 , & V_34 -> V_4 ) ;
F_45 ( & V_34 -> V_61 ) ;
F_17 ( V_3 ) ;
F_57 ( V_34 ) ;
return - V_68 ;
}
F_48 ( V_34 , V_62 ) ;
V_34 -> V_36 = V_3 ;
F_43 ( V_34 , V_36 ) ;
V_52 = F_46 ( V_34 , V_3 ) ;
if ( V_52 < 0 ) {
F_17 ( V_3 ) ;
F_49 ( V_34 , V_62 ) ;
}
if ( V_34 -> V_36 -> V_21 -> V_11 != V_62 -> V_21 -> V_11 && V_34 -> V_21 -> V_69 )
V_34 -> V_21 -> V_69 ( V_34 ) ;
F_17 ( V_62 ) ;
V_66:
F_38 ( V_34 ) ;
if ( V_51 )
F_38 ( V_51 ) ;
F_64 ( & V_34 -> V_70 -> V_48 . V_71 ) ;
if ( V_51 )
F_64 ( & V_51 -> V_70 -> V_48 . V_71 ) ;
F_45 ( & V_34 -> V_61 ) ;
F_57 ( V_34 ) ;
return V_52 ;
}
static void F_65 ( struct V_33 * V_34 )
{
F_44 ( & V_34 -> V_41 ) ;
V_34 -> V_42 = V_34 -> V_72 -> V_73 ;
V_34 -> V_42 . V_74 = F_66 ( & V_34 -> V_42 ) ;
V_34 -> V_42 . V_75 = F_67 ( & V_34 -> V_42 ) ;
F_45 ( & V_34 -> V_41 ) ;
}
static int F_68 ( struct V_33 * V_34 , int V_36 )
{
struct V_17 * V_18 = F_10 ( V_36 ) ;
if ( F_11 ( V_18 ) )
return - 1 ;
F_48 ( V_34 , V_34 -> V_36 ) ;
F_17 ( V_34 -> V_36 ) ;
V_34 -> V_36 = V_18 ;
F_43 ( V_34 , V_36 ) ;
return 0 ;
}
void F_69 ( struct V_33 * V_34 )
{
struct V_17 * V_18 ;
int V_76 = V_34 -> V_72 -> V_4 & V_77 ;
int V_78 = 0 ;
F_70 ( V_34 , L_8 , V_34 -> V_36 ) ;
V_18 = F_34 ( V_34 ) ;
if ( V_18 != NULL ) {
if ( V_18 -> V_21 -> V_40 )
V_18 -> V_21 -> V_40 ( V_34 ) ;
F_71 ( V_34 ) ;
if ( ( F_30 ( V_79 , & V_34 -> V_4 ) ) &&
V_18 -> V_21 -> V_80 )
V_18 -> V_21 -> V_80 ( V_34 ) ;
if ( V_18 -> V_21 -> V_81 )
V_18 -> V_21 -> V_81 ( V_34 ) ;
F_35 ( V_18 ) ;
}
F_72 ( & V_34 -> V_82 , V_83 ) ;
F_72 ( & V_34 -> V_84 , V_85 ) ;
F_44 ( & V_34 -> V_61 ) ;
if ( F_56 ( V_34 ) ) {
if ( V_76 == 0 ) {
if ( ! F_68 ( V_34 , V_34 -> V_42 . V_43 ) )
V_78 = F_46 ( V_34 , V_34 -> V_36 ) ;
else
V_78 = 1 ;
}
if ( V_76 || V_78 ) {
F_73 ( F_68 ( V_34 , V_6 ) ) ;
F_19 ( F_46 ( V_34 , V_34 -> V_36 ) ) ;
}
F_38 ( V_34 ) ;
}
F_45 ( & V_34 -> V_61 ) ;
if ( V_76 )
F_65 ( V_34 ) ;
F_70 ( V_34 , L_9 , V_34 -> V_36 ) ;
}
int F_74 ( struct V_33 * V_34 , struct V_33 * V_51 )
{
struct V_17 * V_18 = V_34 -> V_36 ;
int V_52 ;
V_52 = F_46 ( V_34 , V_18 ) ;
if ( V_52 )
return V_52 ;
if ( V_51 ) {
V_52 = F_46 ( V_51 , V_51 -> V_36 ) ;
if ( V_52 ) {
F_48 ( V_34 , V_18 ) ;
return V_52 ;
}
F_38 ( V_51 ) ;
}
F_38 ( V_34 ) ;
return 0 ;
}
static void F_75 ( struct V_33 * V_34 )
{
F_44 ( & V_34 -> V_61 ) ;
F_48 ( V_34 , V_34 -> V_36 ) ;
F_17 ( V_34 -> V_36 ) ;
V_34 -> V_36 = NULL ;
F_43 ( V_34 , V_6 ) ;
F_45 ( & V_34 -> V_61 ) ;
}
void F_76 ( struct V_33 * V_34 , struct V_33 * V_51 )
{
F_70 ( V_34 , L_8 , V_34 -> V_36 ) ;
F_55 ( V_34 , V_51 , V_57 ) ;
F_77 ( V_34 , V_51 ) ;
F_75 ( V_34 ) ;
if ( V_51 )
F_75 ( V_51 ) ;
F_78 ( V_34 , V_51 ) ;
F_70 ( V_34 , L_10 ) ;
}
void F_79 ( struct V_33 * V_34 )
{
struct V_17 * V_18 = F_10 ( V_6 ) ;
if ( F_11 ( V_18 ) )
F_50 ( L_11 ) ;
V_34 -> V_36 = V_18 ;
}
void F_80 ( struct V_33 * V_34 )
{
F_17 ( V_34 -> V_36 ) ;
V_34 -> V_36 = NULL ;
}
void F_81 ( void )
{
( void ) F_1 ( V_6 , & V_86 ) ;
}
