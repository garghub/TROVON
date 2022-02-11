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
static struct V_17 * F_10 ( struct V_18 * V_19 , int V_1 )
{
struct V_17 * V_20 ;
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
V_20 = F_14 ( sizeof( struct V_17 ) , V_21 ) ;
if ( V_20 == NULL ) {
F_8 ( V_14 ) ;
return F_6 ( - V_22 ) ;
}
V_20 -> V_23 = V_14 ;
V_20 -> V_19 = V_19 ;
return V_20 ;
}
static inline void F_15 ( struct V_17 * V_20 )
{
if ( F_16 ( ! V_20 ) )
return;
F_8 ( V_20 -> V_23 ) ;
F_17 ( V_20 ) ;
}
static void * F_18 ( struct V_24 * V_25 , T_1 * V_26 )
{
return ( * V_26 < V_7 ) ? V_26 : NULL ;
}
static void * F_19 ( struct V_24 * V_25 , void * V_27 , T_1 * V_26 )
{
( * V_26 ) ++ ;
return ( * V_26 < V_7 ) ? V_26 : NULL ;
}
static void F_20 ( struct V_24 * V_25 , void * V_27 )
{
}
static int F_21 ( struct V_24 * V_25 , void * V_27 )
{
int V_28 = * ( T_1 * ) V_27 ;
struct V_2 * V_14 ;
V_14 = F_5 ( V_28 ) ;
if ( F_11 ( V_14 ) )
return 0 ;
F_22 ( V_25 , L_2 , V_14 -> V_29 ? V_14 -> V_29 : L_3 , V_28 ) ;
F_8 ( V_14 ) ;
return 0 ;
}
static int F_23 ( struct V_30 * V_30 , struct V_31 * V_31 )
{
return F_24 ( V_31 , & V_32 ) ;
}
struct V_17 * F_25 ( struct V_18 * V_19 )
{
F_26 ( & V_19 -> V_33 , V_34 ) ;
F_27 ( ! V_19 -> V_35 ) ;
return V_19 -> V_35 ;
}
struct V_17 * F_28 ( struct V_18 * V_19 )
{
struct V_17 * V_20 = NULL ;
if ( F_29 ( & V_19 -> V_33 ) ) {
V_20 = V_19 -> V_35 ;
if ( ! V_20 )
F_30 ( & V_19 -> V_33 ) ;
}
return V_20 ;
}
void F_31 ( struct V_17 * V_20 )
{
F_30 ( & V_20 -> V_19 -> V_33 ) ;
}
static inline int T_2
F_32 ( struct V_18 * V_19 , unsigned long V_36 )
{
return F_33 ( & V_19 -> V_33 , V_36 ) ;
}
static inline int T_2
F_34 ( struct V_18 * V_19 , unsigned long V_36 )
{
return F_35 ( & V_19 -> V_33 ,
V_37 , V_36 ) ;
}
static inline void F_36 ( struct V_18 * V_19 )
{
return F_37 ( & V_19 -> V_33 ) ;
}
static int T_2
F_38 ( struct V_18 * V_19 , unsigned long V_36 )
{
int V_5 ;
V_5 = F_32 ( V_19 , V_36 ) ;
if ( ! V_5 )
return - V_13 ;
F_39 ( V_38 , & V_19 -> V_4 ) ;
return 0 ;
}
static void F_40 ( struct V_18 * V_19 )
{
F_41 ( V_38 , & V_19 -> V_4 ) ;
F_36 ( V_19 ) ;
}
static int T_2
F_42 ( struct V_18 * V_19 , struct V_18 * V_39 ,
unsigned long V_36 )
{
int V_5 ;
if ( V_19 < V_39 ) {
V_5 = F_32 ( V_19 , V_36 ) ;
if ( V_5 ) {
V_5 = F_34 ( V_39 , V_36 ) ;
if ( ! V_5 )
F_36 ( V_19 ) ;
}
} else {
F_16 ( V_19 == V_39 ) ;
if ( V_39 && V_19 != V_39 ) {
V_5 = F_32 ( V_39 , V_36 ) ;
if ( V_5 ) {
V_5 = F_34 ( V_19 , V_36 ) ;
if ( ! V_5 )
F_36 ( V_39 ) ;
}
} else
V_5 = F_32 ( V_19 , V_36 ) ;
}
if ( ! V_5 )
return - V_13 ;
F_39 ( V_38 , & V_19 -> V_4 ) ;
if ( V_39 )
F_39 ( V_38 , & V_39 -> V_4 ) ;
return 0 ;
}
static void T_2
F_43 ( struct V_18 * V_19 , struct V_18 * V_39 )
{
F_42 ( V_19 , V_39 , V_34 ) ;
}
static void T_2 F_44 ( struct V_18 * V_19 ,
struct V_18 * V_39 )
{
F_36 ( V_19 ) ;
if ( V_39 )
F_36 ( V_39 ) ;
}
void F_45 ( struct V_18 * V_19 )
{
struct V_17 * V_20 = F_28 ( V_19 ) ;
F_46 ( V_19 , V_20 ) ;
if ( V_20 )
F_31 ( V_20 ) ;
}
static void F_47 ( struct V_18 * V_19 , int V_11 )
{
F_48 ( & V_19 -> V_40 ) ;
V_19 -> V_41 . V_42 = V_11 ;
F_49 ( & V_19 -> V_40 ) ;
}
static int F_50 ( struct V_18 * V_19 , struct V_17 * V_20 )
{
F_27 ( F_51 ( V_43 , & V_19 -> V_4 ) ) ;
if ( V_20 -> V_23 -> V_44 ) {
int V_5 ;
V_5 = V_20 -> V_23 -> V_44 ( V_19 ) ;
if ( V_5 )
F_41 ( V_43 , & V_19 -> V_4 ) ;
return V_5 ;
}
return 0 ;
}
static void F_52 ( struct V_18 * V_19 , struct V_17 * V_20 )
{
F_27 ( ! F_53 ( V_43 , & V_19 -> V_4 ) ) ;
F_41 ( V_43 , & V_19 -> V_4 ) ;
if ( V_20 -> V_23 -> V_45 )
V_20 -> V_23 -> V_45 ( V_19 ) ;
}
static void F_54 ( struct V_18 * V_19 , struct V_17 * V_46 )
{
char V_47 [ 64 ] ;
struct V_17 * V_3 ;
int V_48 ;
V_46 = F_10 ( V_19 , V_46 -> V_23 -> V_11 ) ;
F_27 ( F_11 ( V_46 ) ) ;
V_19 -> V_35 = V_46 ;
F_47 ( V_19 , V_46 -> V_23 -> V_11 ) ;
if ( F_50 ( V_19 , V_46 ) < 0 ) {
F_15 ( V_46 ) ;
V_3 = F_10 ( V_19 , V_6 ) ;
if ( F_11 ( V_3 ) )
F_55 ( L_4 ) ;
V_19 -> V_35 = V_3 ;
F_47 ( V_19 , V_6 ) ;
V_48 = F_50 ( V_19 , V_3 ) ;
if ( V_48 < 0 )
F_55 ( L_5
L_6 ,
F_56 ( V_19 , V_47 ) , V_48 ) ;
}
}
int F_57 ( struct V_18 * V_19 , int V_35 )
{
int V_49 ;
struct V_17 * V_50 , * V_3 ;
V_3 = F_10 ( V_19 , V_35 ) ;
if ( F_11 ( V_3 ) )
return F_58 ( V_3 ) ;
F_59 ( V_19 ) ;
V_49 = F_38 ( V_19 , 5 * V_51 ) ;
if ( V_49 ) {
F_15 ( V_3 ) ;
F_60 ( V_19 ) ;
return V_49 ;
}
if ( V_19 -> V_35 -> V_23 -> V_11 == V_35 ) {
F_40 ( V_19 ) ;
F_15 ( V_3 ) ;
F_60 ( V_19 ) ;
return 0 ;
}
V_50 = V_19 -> V_35 ;
if ( F_53 ( V_52 , & V_19 -> V_4 ) ) {
F_40 ( V_19 ) ;
F_15 ( V_3 ) ;
F_60 ( V_19 ) ;
return - V_53 ;
}
F_52 ( V_19 , V_50 ) ;
V_19 -> V_35 = V_3 ;
F_47 ( V_19 , V_35 ) ;
V_49 = F_50 ( V_19 , V_3 ) ;
if ( V_49 < 0 ) {
F_15 ( V_3 ) ;
F_54 ( V_19 , V_50 ) ;
}
if ( V_19 -> V_35 -> V_23 -> V_11 != V_50 -> V_23 -> V_11 && V_19 -> V_23 -> V_54 ) {
F_61 ( & V_19 -> V_40 ) ;
V_19 -> V_23 -> V_54 ( V_19 ) ;
F_62 ( & V_19 -> V_40 ) ;
}
F_15 ( V_50 ) ;
F_40 ( V_19 ) ;
F_63 ( & V_19 -> V_55 -> V_47 . V_56 ) ;
F_60 ( V_19 ) ;
return V_49 ;
}
static void F_64 ( struct V_18 * V_19 )
{
F_48 ( & V_19 -> V_40 ) ;
V_19 -> V_41 = V_19 -> V_57 -> V_58 ;
V_19 -> V_41 . V_59 = F_65 ( & V_19 -> V_41 ) ;
V_19 -> V_41 . V_60 = F_66 ( & V_19 -> V_41 ) ;
F_49 ( & V_19 -> V_40 ) ;
}
static int F_67 ( struct V_18 * V_19 , int V_35 )
{
struct V_17 * V_20 = F_10 ( V_19 , V_35 ) ;
if ( F_11 ( V_20 ) )
return - 1 ;
F_52 ( V_19 , V_19 -> V_35 ) ;
F_15 ( V_19 -> V_35 ) ;
V_19 -> V_35 = V_20 ;
F_47 ( V_19 , V_35 ) ;
return 0 ;
}
void F_68 ( struct V_18 * V_19 )
{
struct V_17 * V_20 ;
int V_61 = V_19 -> V_57 -> V_4 & V_62 ;
int V_63 = 0 ;
F_69 ( V_19 , L_7 , V_19 -> V_35 ) ;
V_20 = F_28 ( V_19 ) ;
if ( V_20 != NULL ) {
if ( V_20 -> V_23 -> V_64 )
V_20 -> V_23 -> V_64 ( V_19 ) ;
F_70 ( V_19 ) ;
if ( ( F_53 ( V_65 , & V_19 -> V_4 ) ) &&
V_20 -> V_23 -> V_66 )
V_20 -> V_23 -> V_66 ( V_19 ) ;
if ( V_20 -> V_23 -> V_67 )
V_20 -> V_23 -> V_67 ( V_19 ) ;
F_31 ( V_20 ) ;
}
F_71 ( & V_19 -> V_68 , V_69 ) ;
F_71 ( & V_19 -> V_70 , V_71 ) ;
F_38 ( V_19 , V_34 ) ;
if ( V_19 -> V_35 ) {
if ( V_61 == 0 ) {
if ( ! F_67 ( V_19 , V_19 -> V_41 . V_42 ) )
V_63 = F_50 ( V_19 , V_19 -> V_35 ) ;
else
V_63 = 1 ;
}
if ( V_61 || V_63 ) {
F_72 ( F_67 ( V_19 , V_6 ) ) ;
F_27 ( F_50 ( V_19 , V_19 -> V_35 ) ) ;
}
}
F_40 ( V_19 ) ;
if ( V_61 )
F_64 ( V_19 ) ;
F_69 ( V_19 , L_8 , V_19 -> V_35 ) ;
}
int F_73 ( struct V_18 * V_19 , struct V_18 * V_72 )
{
struct V_17 * V_20 = V_19 -> V_35 ;
int V_49 ;
V_49 = F_50 ( V_19 , V_20 ) ;
if ( V_49 )
return V_49 ;
if ( V_72 ) {
V_49 = F_50 ( V_72 , V_72 -> V_35 ) ;
if ( V_49 ) {
F_52 ( V_19 , V_20 ) ;
return V_49 ;
}
}
return 0 ;
}
static void F_74 ( struct V_18 * V_19 )
{
F_52 ( V_19 , V_19 -> V_35 ) ;
F_15 ( V_19 -> V_35 ) ;
V_19 -> V_35 = NULL ;
F_47 ( V_19 , V_6 ) ;
}
void F_75 ( struct V_18 * V_19 )
{
struct V_18 * V_72 = V_19 -> V_73 ;
F_69 ( V_19 , L_7 , V_19 -> V_35 ) ;
F_43 ( V_19 , V_72 ) ;
F_74 ( V_19 ) ;
if ( V_72 )
F_74 ( V_72 ) ;
F_44 ( V_19 , V_72 ) ;
F_69 ( V_19 , L_9 ) ;
}
void F_76 ( struct V_18 * V_19 )
{
struct V_17 * V_20 = F_10 ( V_19 , V_6 ) ;
if ( F_11 ( V_20 ) )
F_55 ( L_10 ) ;
V_19 -> V_35 = V_20 ;
}
void F_77 ( struct V_18 * V_19 )
{
F_15 ( V_19 -> V_35 ) ;
V_19 -> V_35 = NULL ;
}
void F_78 ( void )
{
( void ) F_1 ( V_6 , & V_74 ) ;
}
