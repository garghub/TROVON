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
static void F_15 ( struct V_17 * V_20 )
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
if ( ! V_19 -> V_35 )
F_27 ( & V_19 -> V_33 ) ;
return V_19 -> V_35 ;
}
struct V_17 * F_28 ( struct V_18 * V_19 )
{
struct V_17 * V_20 = NULL ;
if ( F_29 ( & V_19 -> V_33 ) ) {
V_20 = V_19 -> V_35 ;
if ( ! V_20 )
F_27 ( & V_19 -> V_33 ) ;
}
return V_20 ;
}
void F_30 ( struct V_17 * V_20 )
{
F_27 ( & V_20 -> V_19 -> V_33 ) ;
}
static inline int
F_31 ( struct V_18 * V_19 , unsigned long V_36 )
{
return F_32 ( & V_19 -> V_33 , V_36 ) ;
}
static inline int
F_33 ( struct V_18 * V_19 , unsigned long V_36 )
{
return F_34 ( & V_19 -> V_33 ,
V_37 , V_36 ) ;
}
static inline void F_35 ( struct V_18 * V_19 )
{
F_36 ( & V_19 -> V_33 ) ;
}
static int F_37 ( struct V_18 * V_19 , unsigned long V_36 )
{
int V_5 ;
V_5 = F_31 ( V_19 , V_36 ) ;
if ( ! V_5 )
return - V_13 ;
F_38 ( V_38 , & V_19 -> V_4 ) ;
return 0 ;
}
static void F_39 ( struct V_18 * V_19 )
{
F_40 ( V_38 , & V_19 -> V_4 ) ;
F_35 ( V_19 ) ;
}
static int
F_41 ( struct V_18 * V_19 , struct V_18 * V_39 ,
unsigned long V_36 )
{
int V_5 ;
if ( V_19 < V_39 ) {
V_5 = F_31 ( V_19 , V_36 ) ;
if ( V_5 ) {
V_5 = F_33 ( V_39 , V_36 ) ;
if ( ! V_5 )
F_35 ( V_19 ) ;
}
} else {
F_16 ( V_19 == V_39 ) ;
if ( V_39 && V_19 != V_39 ) {
V_5 = F_31 ( V_39 , V_36 ) ;
if ( V_5 ) {
V_5 = F_33 ( V_19 , V_36 ) ;
if ( ! V_5 )
F_35 ( V_39 ) ;
}
} else
V_5 = F_31 ( V_19 , V_36 ) ;
}
if ( ! V_5 )
return - V_13 ;
F_38 ( V_38 , & V_19 -> V_4 ) ;
if ( V_39 )
F_38 ( V_38 , & V_39 -> V_4 ) ;
return 0 ;
}
static void F_42 ( struct V_18 * V_19 , struct V_18 * V_39 )
{
F_41 ( V_19 , V_39 , V_34 ) ;
}
static void F_43 ( struct V_18 * V_19 ,
struct V_18 * V_39 )
{
F_35 ( V_19 ) ;
if ( V_39 )
F_35 ( V_39 ) ;
}
void F_44 ( struct V_18 * V_19 )
{
struct V_17 * V_20 = F_28 ( V_19 ) ;
F_45 ( V_19 , V_20 ) ;
if ( V_20 )
F_30 ( V_20 ) ;
}
static void F_46 ( struct V_18 * V_19 , int V_1 )
{
F_47 ( & V_19 -> V_40 ) ;
V_19 -> V_41 . V_42 = V_1 ;
F_48 ( & V_19 -> V_40 ) ;
V_19 -> V_43 = NULL ;
V_19 -> V_44 = 0 ;
}
static int F_49 ( struct V_18 * V_19 , struct V_17 * V_20 )
{
F_50 ( F_51 ( V_45 , & V_19 -> V_4 ) ) ;
if ( V_20 -> V_23 -> V_46 ) {
int V_5 ;
V_5 = V_20 -> V_23 -> V_46 ( V_19 ) ;
if ( V_5 )
F_40 ( V_45 , & V_19 -> V_4 ) ;
F_52 ( V_19 , L_4 , V_20 ) ;
return V_5 ;
}
return 0 ;
}
static void F_53 ( struct V_18 * V_19 , struct V_17 * V_20 )
{
F_50 ( ! F_54 ( V_45 , & V_19 -> V_4 ) ) ;
F_40 ( V_45 , & V_19 -> V_4 ) ;
if ( V_20 -> V_23 -> V_47 )
V_20 -> V_23 -> V_47 ( V_19 ) ;
F_52 ( V_19 , L_5 , V_20 ) ;
}
static void F_55 ( struct V_18 * V_19 , struct V_17 * V_48 )
{
struct V_17 * V_3 ;
int V_49 ;
V_48 = F_10 ( V_19 , V_48 -> V_23 -> V_11 ) ;
F_50 ( F_11 ( V_48 ) ) ;
V_19 -> V_35 = V_48 ;
F_46 ( V_19 , V_48 -> V_23 -> V_11 ) ;
if ( F_49 ( V_19 , V_48 ) < 0 ) {
F_15 ( V_48 ) ;
V_3 = F_10 ( V_19 , V_6 ) ;
if ( F_11 ( V_3 ) )
F_56 ( L_6 ) ;
V_19 -> V_35 = V_3 ;
F_46 ( V_19 , V_6 ) ;
V_49 = F_49 ( V_19 , V_3 ) ;
if ( V_49 < 0 )
F_56 ( L_7
L_8 ,
F_57 ( V_19 ) , V_49 ) ;
}
}
int F_58 ( struct V_18 * V_19 , int V_1 )
{
int V_50 ;
struct V_17 * V_51 , * V_3 ;
V_3 = F_10 ( V_19 , V_1 ) ;
if ( F_11 ( V_3 ) )
return F_59 ( V_3 ) ;
F_60 ( V_19 ) ;
V_50 = F_37 ( V_19 , 5 * V_52 ) ;
if ( V_50 )
goto V_53;
if ( ! V_19 -> V_35 ) {
V_50 = - V_54 ;
goto V_55;
}
if ( V_19 -> V_35 -> V_23 -> V_11 == V_1 )
goto V_55;
if ( F_54 ( V_56 , & V_19 -> V_4 ) ) {
V_50 = - V_54 ;
goto V_55;
}
V_51 = V_19 -> V_35 ;
F_53 ( V_19 , V_51 ) ;
V_19 -> V_35 = V_3 ;
F_46 ( V_19 , V_1 ) ;
V_50 = F_49 ( V_19 , V_3 ) ;
if ( V_50 < 0 ) {
F_15 ( V_3 ) ;
F_55 ( V_19 , V_51 ) ;
}
if ( V_19 -> V_35 -> V_23 -> V_11 != V_51 -> V_23 -> V_11 && V_19 -> V_23 -> V_57 ) {
F_61 ( & V_19 -> V_40 ) ;
V_19 -> V_23 -> V_57 ( V_19 ) ;
F_62 ( & V_19 -> V_40 ) ;
}
V_3 = V_51 ;
V_55:
F_39 ( V_19 ) ;
F_63 ( V_19 -> V_58 ) ;
V_53:
F_15 ( V_3 ) ;
F_64 ( V_19 ) ;
return V_50 ;
}
static void F_65 ( struct V_18 * V_19 )
{
if ( ! V_19 -> V_35 )
return;
F_53 ( V_19 , V_19 -> V_35 ) ;
F_15 ( V_19 -> V_35 ) ;
V_19 -> V_35 = NULL ;
}
static void F_66 ( struct V_18 * V_19 )
{
F_47 ( & V_19 -> V_40 ) ;
V_19 -> V_41 = V_19 -> V_59 -> V_60 ;
V_19 -> V_41 . V_61 = F_67 ( & V_19 -> V_41 ) ;
V_19 -> V_41 . V_62 = F_68 ( & V_19 -> V_41 ) ;
F_48 ( & V_19 -> V_40 ) ;
}
int F_69 ( struct V_18 * V_19 , int V_1 )
{
struct V_17 * V_20 ;
int V_50 ;
V_20 = F_10 ( V_19 , V_1 ) ;
if ( F_11 ( V_20 ) ) {
F_70 ( V_1 == V_6 ) ;
return F_59 ( V_20 ) ;
}
if ( V_19 -> V_35 ) {
F_53 ( V_19 , V_19 -> V_35 ) ;
F_15 ( V_19 -> V_35 ) ;
}
V_19 -> V_35 = V_20 ;
F_46 ( V_19 , V_1 ) ;
V_50 = F_49 ( V_19 , V_19 -> V_35 ) ;
if ( V_50 ) {
if ( ! F_50 ( V_1 == V_6 ) ) {
F_15 ( V_19 -> V_35 ) ;
V_19 -> V_35 = NULL ;
}
}
return V_50 ;
}
void F_71 ( struct V_18 * V_19 , bool V_63 )
{
struct V_17 * V_20 ;
F_52 ( V_19 , L_9 , V_19 -> V_35 ) ;
V_20 = F_28 ( V_19 ) ;
if ( V_20 != NULL ) {
if ( V_20 -> V_23 -> V_64 )
V_20 -> V_23 -> V_64 ( V_19 ) ;
F_72 ( V_19 ) ;
if ( ( F_54 ( V_65 , & V_19 -> V_4 ) ) &&
V_20 -> V_23 -> V_66 )
V_20 -> V_23 -> V_66 ( V_19 ) ;
if ( V_20 -> V_23 -> V_67 )
V_20 -> V_23 -> V_67 ( V_19 ) ;
F_30 ( V_20 ) ;
}
F_73 ( & V_19 -> V_68 , V_69 ) ;
F_73 ( & V_19 -> V_70 , V_71 ) ;
F_37 ( V_19 , V_34 ) ;
if ( V_19 -> V_59 -> V_4 & V_72 )
F_66 ( V_19 ) ;
if ( V_19 -> V_35 ) {
if ( V_63 ) {
if ( F_69 ( V_19 , V_19 -> V_41 . V_42 ) < 0 )
F_69 ( V_19 , V_6 ) ;
} else
F_65 ( V_19 ) ;
}
F_39 ( V_19 ) ;
}
int F_74 ( struct V_18 * V_19 , struct V_18 * V_73 )
{
int V_50 = F_49 ( V_19 , V_19 -> V_35 ) ;
if ( V_50 )
return V_50 ;
if ( V_73 ) {
V_50 = F_49 ( V_73 , V_73 -> V_35 ) ;
if ( V_50 ) {
F_53 ( V_19 , V_19 -> V_35 ) ;
return V_50 ;
}
}
return 0 ;
}
void F_75 ( struct V_18 * V_19 )
{
struct V_18 * V_73 = V_19 -> V_74 ;
F_42 ( V_19 , V_73 ) ;
F_65 ( V_19 ) ;
if ( V_73 )
F_65 ( V_73 ) ;
F_43 ( V_19 , V_73 ) ;
F_52 ( V_19 , L_10 ) ;
}
void F_76 ( struct V_18 * V_19 )
{
struct V_17 * V_20 = F_10 ( V_19 , V_6 ) ;
if ( F_11 ( V_20 ) )
F_56 ( L_11 ) ;
V_19 -> V_35 = V_20 ;
}
void F_77 ( struct V_18 * V_19 )
{
if ( V_19 -> V_35 )
F_15 ( V_19 -> V_35 ) ;
V_19 -> V_35 = NULL ;
}
