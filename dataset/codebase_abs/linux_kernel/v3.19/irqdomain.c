struct V_1 * F_1 ( struct V_2 * V_3 , int V_4 ,
T_1 V_5 , int V_6 ,
const struct V_7 * V_8 ,
void * V_9 )
{
struct V_1 * V_10 ;
V_10 = F_2 ( sizeof( * V_10 ) + (sizeof( unsigned int ) * V_4 ) ,
V_11 , F_3 ( V_3 ) ) ;
if ( F_4 ( ! V_10 ) )
return NULL ;
F_5 ( & V_10 -> V_12 , V_11 ) ;
V_10 -> V_8 = V_8 ;
V_10 -> V_9 = V_9 ;
V_10 -> V_3 = F_6 ( V_3 ) ;
V_10 -> V_5 = V_5 ;
V_10 -> V_13 = V_4 ;
V_10 -> V_14 = V_6 ;
F_7 ( V_10 ) ;
F_8 ( & V_15 ) ;
F_9 ( & V_10 -> V_16 , & V_17 ) ;
F_10 ( & V_15 ) ;
F_11 ( L_1 , V_10 -> V_18 ) ;
return V_10 ;
}
void F_12 ( struct V_1 * V_10 )
{
F_8 ( & V_15 ) ;
F_4 ( V_10 -> V_12 . V_19 ) ;
F_13 ( & V_10 -> V_16 ) ;
if ( F_14 ( V_20 == V_10 ) )
F_15 ( NULL ) ;
F_10 ( & V_15 ) ;
F_11 ( L_2 , V_10 -> V_18 ) ;
F_16 ( V_10 -> V_3 ) ;
F_17 ( V_10 ) ;
}
struct V_1 * F_18 ( struct V_2 * V_3 ,
unsigned int V_4 ,
unsigned int V_21 ,
const struct V_7 * V_8 ,
void * V_9 )
{
struct V_1 * V_10 ;
V_10 = F_1 ( V_3 , V_4 , V_4 , 0 , V_8 , V_9 ) ;
if ( ! V_10 )
return NULL ;
if ( V_21 > 0 ) {
if ( F_19 ( V_22 ) ) {
int V_23 = F_20 ( V_21 , V_21 , V_4 ,
F_3 ( V_3 ) ) ;
if ( V_23 < 0 )
F_21 ( L_3 ,
V_21 ) ;
}
F_22 ( V_10 , V_21 , 0 , V_4 ) ;
}
return V_10 ;
}
struct V_1 * F_23 ( struct V_2 * V_3 ,
unsigned int V_4 ,
unsigned int V_21 ,
T_1 V_24 ,
const struct V_7 * V_8 ,
void * V_9 )
{
struct V_1 * V_10 ;
V_10 = F_1 ( V_3 , V_24 + V_4 ,
V_24 + V_4 , 0 , V_8 , V_9 ) ;
if ( V_10 )
F_22 ( V_10 , V_21 , V_24 , V_4 ) ;
return V_10 ;
}
struct V_1 * F_24 ( struct V_2 * V_25 )
{
struct V_1 * V_26 , * V_27 = NULL ;
int V_23 ;
F_8 ( & V_15 ) ;
F_25 (h, &irq_domain_list, link) {
if ( V_26 -> V_8 -> V_28 )
V_23 = V_26 -> V_8 -> V_28 ( V_26 , V_25 ) ;
else
V_23 = ( V_26 -> V_3 != NULL ) && ( V_26 -> V_3 == V_25 ) ;
if ( V_23 ) {
V_27 = V_26 ;
break;
}
}
F_10 ( & V_15 ) ;
return V_27 ;
}
void F_15 ( struct V_1 * V_10 )
{
F_11 ( L_4 , V_10 ) ;
V_20 = V_10 ;
}
void F_26 ( struct V_1 * V_10 , unsigned int V_29 )
{
struct V_30 * V_30 = F_27 ( V_29 ) ;
T_1 V_31 ;
if ( F_28 ( ! V_30 || V_30 -> V_10 != V_10 ,
L_5 , V_29 ) )
return;
V_31 = V_30 -> V_31 ;
F_29 ( V_29 , V_32 ) ;
F_30 ( V_29 , NULL , NULL ) ;
F_31 ( V_29 ) ;
if ( V_10 -> V_8 -> V_33 )
V_10 -> V_8 -> V_33 ( V_10 , V_29 ) ;
F_32 () ;
V_30 -> V_10 = NULL ;
V_30 -> V_31 = 0 ;
if ( V_31 < V_10 -> V_13 ) {
V_10 -> V_34 [ V_31 ] = 0 ;
} else {
F_8 ( & V_35 ) ;
F_33 ( & V_10 -> V_12 , V_31 ) ;
F_10 ( & V_35 ) ;
}
}
int F_34 ( struct V_1 * V_10 , unsigned int V_36 ,
T_1 V_31 )
{
struct V_30 * V_30 = F_27 ( V_36 ) ;
int V_37 ;
if ( F_28 ( V_31 >= V_10 -> V_5 ,
L_6 , ( int ) V_31 , V_10 -> V_18 ) )
return - V_38 ;
if ( F_28 ( ! V_30 , L_7 , V_36 ) )
return - V_38 ;
if ( F_28 ( V_30 -> V_10 , L_8 , V_36 ) )
return - V_38 ;
F_8 ( & V_15 ) ;
V_30 -> V_31 = V_31 ;
V_30 -> V_10 = V_10 ;
if ( V_10 -> V_8 -> V_39 ) {
V_37 = V_10 -> V_8 -> V_39 ( V_10 , V_36 , V_31 ) ;
if ( V_37 != 0 ) {
if ( V_37 != - V_40 ) {
F_21 ( L_9 ,
V_10 -> V_18 , V_31 , V_36 , V_37 ) ;
}
V_30 -> V_10 = NULL ;
V_30 -> V_31 = 0 ;
F_10 ( & V_15 ) ;
return V_37 ;
}
if ( ! V_10 -> V_18 && V_30 -> V_41 )
V_10 -> V_18 = V_30 -> V_41 -> V_18 ;
}
if ( V_31 < V_10 -> V_13 ) {
V_10 -> V_34 [ V_31 ] = V_36 ;
} else {
F_8 ( & V_35 ) ;
F_35 ( & V_10 -> V_12 , V_31 , V_30 ) ;
F_10 ( & V_35 ) ;
}
F_10 ( & V_15 ) ;
F_36 ( V_36 , V_32 ) ;
return 0 ;
}
void F_22 ( struct V_1 * V_10 , unsigned int V_42 ,
T_1 V_43 , int V_44 )
{
int V_45 ;
F_11 ( L_10 , V_46 ,
F_37 ( V_10 -> V_3 ) , V_42 , ( int ) V_43 , V_44 ) ;
for ( V_45 = 0 ; V_45 < V_44 ; V_45 ++ ) {
F_34 ( V_10 , V_42 + V_45 , V_43 + V_45 ) ;
}
}
unsigned int F_38 ( struct V_1 * V_10 )
{
unsigned int V_36 ;
if ( V_10 == NULL )
V_10 = V_20 ;
V_36 = F_39 ( 1 , F_3 ( V_10 -> V_3 ) ) ;
if ( ! V_36 ) {
F_11 ( L_11 ) ;
return 0 ;
}
if ( V_36 >= V_10 -> V_14 ) {
F_40 ( L_12 ,
V_10 -> V_14 ) ;
F_41 ( V_36 ) ;
return 0 ;
}
F_11 ( L_13 , V_36 ) ;
if ( F_34 ( V_10 , V_36 , V_36 ) ) {
F_41 ( V_36 ) ;
return 0 ;
}
return V_36 ;
}
unsigned int F_42 ( struct V_1 * V_10 ,
T_1 V_31 )
{
int V_36 ;
F_11 ( L_14 , V_10 , V_31 ) ;
if ( V_10 == NULL )
V_10 = V_20 ;
if ( V_10 == NULL ) {
F_28 ( 1 , L_15 , V_46 , V_31 ) ;
return 0 ;
}
F_11 ( L_16 , V_10 ) ;
V_36 = F_43 ( V_10 , V_31 ) ;
if ( V_36 ) {
F_11 ( L_17 , V_36 ) ;
return V_36 ;
}
V_36 = F_44 ( - 1 , 1 , V_31 ,
F_3 ( V_10 -> V_3 ) ) ;
if ( V_36 <= 0 ) {
F_11 ( L_18 ) ;
return 0 ;
}
if ( F_34 ( V_10 , V_36 , V_31 ) ) {
F_41 ( V_36 ) ;
return 0 ;
}
F_11 ( L_19 ,
V_31 , F_37 ( V_10 -> V_3 ) , V_36 ) ;
return V_36 ;
}
int F_45 ( struct V_1 * V_10 , unsigned int V_42 ,
T_1 V_43 , int V_44 )
{
int V_37 ;
V_37 = F_20 ( V_42 , V_42 , V_44 ,
F_3 ( V_10 -> V_3 ) ) ;
if ( F_14 ( V_37 < 0 ) )
return V_37 ;
F_22 ( V_10 , V_42 , V_43 , V_44 ) ;
return 0 ;
}
unsigned int F_46 ( struct V_47 * V_30 )
{
struct V_1 * V_10 ;
T_1 V_31 ;
unsigned int type = V_48 ;
int V_36 ;
V_10 = V_30 -> V_49 ? F_24 ( V_30 -> V_49 ) : V_20 ;
if ( ! V_10 ) {
F_47 ( L_20 ,
F_37 ( V_30 -> V_49 ) ) ;
return 0 ;
}
if ( V_10 -> V_8 -> V_50 == NULL )
V_31 = V_30 -> args [ 0 ] ;
else {
if ( V_10 -> V_8 -> V_50 ( V_10 , V_30 -> V_49 , V_30 -> args ,
V_30 -> V_51 , & V_31 , & type ) )
return 0 ;
}
if ( F_48 ( V_10 ) ) {
V_36 = F_43 ( V_10 , V_31 ) ;
if ( V_36 )
return V_36 ;
V_36 = F_49 ( V_10 , 1 , V_52 , V_30 ) ;
if ( V_36 <= 0 )
return 0 ;
} else {
V_36 = F_42 ( V_10 , V_31 ) ;
if ( ! V_36 )
return V_36 ;
}
if ( type != V_48 &&
type != F_50 ( V_36 ) )
F_51 ( V_36 , type ) ;
return V_36 ;
}
void F_52 ( unsigned int V_36 )
{
struct V_30 * V_30 = F_27 ( V_36 ) ;
struct V_1 * V_10 ;
if ( ! V_36 || ! V_30 )
return;
V_10 = V_30 -> V_10 ;
if ( F_4 ( V_10 == NULL ) )
return;
F_26 ( V_10 , V_36 ) ;
F_41 ( V_36 ) ;
}
unsigned int F_43 ( struct V_1 * V_10 ,
T_1 V_31 )
{
struct V_30 * V_53 ;
if ( V_10 == NULL )
V_10 = V_20 ;
if ( V_10 == NULL )
return 0 ;
if ( V_31 < V_10 -> V_14 ) {
V_53 = F_53 ( V_10 , V_31 ) ;
if ( V_53 && V_53 -> V_31 == V_31 )
return V_31 ;
}
if ( V_31 < V_10 -> V_13 )
return V_10 -> V_34 [ V_31 ] ;
F_54 () ;
V_53 = F_55 ( & V_10 -> V_12 , V_31 ) ;
F_56 () ;
return V_53 ? V_53 -> V_29 : 0 ;
}
static int F_57 ( struct V_54 * V_55 , void * V_56 )
{
unsigned long V_57 ;
struct V_58 * V_59 ;
struct V_1 * V_10 ;
struct V_60 V_61 ;
void * V_53 , * * V_62 ;
int V_45 ;
F_58 ( V_55 , L_21 ,
L_22 , L_23 , L_24 , L_25 , L_26 ) ;
F_8 ( & V_15 ) ;
F_25 (domain, &irq_domain_list, link) {
int V_44 = 0 ;
F_59 (slot, &domain->revmap_tree, &iter, 0 )
V_44 ++ ;
F_58 ( V_55 , L_27 ,
V_10 == V_20 ? '*' : ' ' , V_10 -> V_18 ,
V_10 -> V_13 + V_44 , V_10 -> V_13 ,
V_10 -> V_14 ,
V_10 -> V_3 ? F_37 ( V_10 -> V_3 ) : L_28 ) ;
}
F_10 ( & V_15 ) ;
F_58 ( V_55 , L_29 , L_30 , L_31 ,
L_32 , ( int ) ( 2 * sizeof( void * ) + 2 ) , L_33 ,
L_34 , L_35 , L_36 ) ;
for ( V_45 = 1 ; V_45 < V_63 ; V_45 ++ ) {
V_59 = F_60 ( V_45 ) ;
if ( ! V_59 )
continue;
F_61 ( & V_59 -> V_64 , V_57 ) ;
V_10 = V_59 -> V_30 . V_10 ;
if ( V_10 ) {
struct V_65 * V_41 ;
int V_31 = V_59 -> V_30 . V_31 ;
bool V_66 ;
F_58 ( V_55 , L_37 , V_45 ) ;
F_58 ( V_55 , L_38 , V_31 ) ;
V_41 = F_62 ( V_59 ) ;
F_58 ( V_55 , L_39 , ( V_41 && V_41 -> V_18 ) ? V_41 -> V_18 : L_40 ) ;
V_53 = F_63 ( V_59 ) ;
F_58 ( V_55 , V_53 ? L_41 : L_42 , V_53 ) ;
F_58 ( V_55 , L_43 , ( V_59 -> V_67 && V_59 -> V_67 -> V_68 ) ? '*' : ' ' ) ;
V_66 = ( V_45 == V_31 ) && ( V_45 < V_10 -> V_14 ) ;
F_58 ( V_55 , L_44 ,
( V_31 < V_10 -> V_13 ) ? L_45 : L_46 ,
V_66 ? L_47 : L_28 ) ;
F_58 ( V_55 , L_48 , V_59 -> V_30 . V_10 -> V_18 ) ;
}
F_64 ( & V_59 -> V_64 , V_57 ) ;
}
return 0 ;
}
static int F_65 ( struct V_69 * V_69 , struct V_70 * V_70 )
{
return F_66 ( V_70 , F_57 , V_69 -> V_71 ) ;
}
static int T_2 F_67 ( void )
{
if ( F_68 ( L_49 , V_72 , NULL ,
NULL , & V_73 ) == NULL )
return - V_74 ;
return 0 ;
}
int F_69 ( struct V_1 * V_75 , struct V_2 * V_76 ,
const T_3 * V_77 , unsigned int V_78 ,
unsigned long * V_79 , unsigned int * V_80 )
{
if ( F_4 ( V_78 < 1 ) )
return - V_38 ;
* V_79 = V_77 [ 0 ] ;
* V_80 = V_48 ;
return 0 ;
}
int F_70 ( struct V_1 * V_75 , struct V_2 * V_76 ,
const T_3 * V_77 , unsigned int V_78 ,
T_1 * V_79 , unsigned int * V_80 )
{
if ( F_4 ( V_78 < 2 ) )
return - V_38 ;
* V_79 = V_77 [ 0 ] ;
* V_80 = V_77 [ 1 ] & V_81 ;
return 0 ;
}
int F_71 ( struct V_1 * V_75 ,
struct V_2 * V_76 ,
const T_3 * V_77 , unsigned int V_78 ,
unsigned long * V_79 , unsigned int * V_80 )
{
if ( F_4 ( V_78 < 1 ) )
return - V_38 ;
* V_79 = V_77 [ 0 ] ;
* V_80 = ( V_78 > 1 ) ? V_77 [ 1 ] : V_48 ;
return 0 ;
}
static int F_44 ( int V_36 , unsigned int V_82 ,
T_1 V_31 , int V_25 )
{
unsigned int V_83 ;
if ( V_36 >= 0 ) {
V_36 = F_20 ( V_36 , V_36 , V_82 , V_25 ) ;
} else {
V_83 = V_31 % V_63 ;
if ( V_83 == 0 )
V_83 ++ ;
V_36 = F_72 ( V_83 , V_82 , V_25 ) ;
if ( V_36 <= 0 && V_83 > 1 )
V_36 = F_72 ( 1 , V_82 , V_25 ) ;
}
return V_36 ;
}
struct V_1 * F_73 ( struct V_1 * V_84 ,
unsigned int V_57 ,
unsigned int V_4 ,
struct V_2 * V_25 ,
const struct V_7 * V_8 ,
void * V_9 )
{
struct V_1 * V_10 ;
if ( V_4 )
V_10 = F_74 ( V_25 , V_4 , V_8 , V_9 ) ;
else
V_10 = F_75 ( V_25 , V_8 , V_9 ) ;
if ( V_10 ) {
V_10 -> V_84 = V_84 ;
V_10 -> V_57 |= V_57 ;
}
return V_10 ;
}
static void F_76 ( int V_36 )
{
struct V_30 * V_53 ;
for ( V_53 = F_27 ( V_36 ) ; V_53 ; V_53 = V_53 -> V_85 ) {
struct V_1 * V_10 = V_53 -> V_10 ;
T_1 V_31 = V_53 -> V_31 ;
if ( V_31 < V_10 -> V_13 ) {
V_10 -> V_34 [ V_31 ] = V_36 ;
} else {
F_8 ( & V_35 ) ;
F_35 ( & V_10 -> V_12 , V_31 , V_53 ) ;
F_10 ( & V_35 ) ;
}
if ( ! V_10 -> V_18 && V_53 -> V_41 )
V_10 -> V_18 = V_53 -> V_41 -> V_18 ;
}
F_36 ( V_36 , V_32 ) ;
}
static void F_77 ( int V_36 )
{
struct V_30 * V_53 ;
F_29 ( V_36 , V_32 ) ;
F_30 ( V_36 , NULL , NULL ) ;
F_31 ( V_36 ) ;
F_32 () ;
for ( V_53 = F_27 ( V_36 ) ; V_53 ; V_53 = V_53 -> V_85 ) {
struct V_1 * V_10 = V_53 -> V_10 ;
T_1 V_31 = V_53 -> V_31 ;
if ( V_31 < V_10 -> V_13 ) {
V_10 -> V_34 [ V_31 ] = 0 ;
} else {
F_8 ( & V_35 ) ;
F_33 ( & V_10 -> V_12 , V_31 ) ;
F_10 ( & V_35 ) ;
}
}
}
static struct V_30 * F_78 ( struct V_1 * V_10 ,
struct V_30 * V_86 )
{
struct V_30 * V_30 ;
V_30 = F_2 ( sizeof( * V_30 ) , V_11 , V_86 -> V_25 ) ;
if ( V_30 ) {
V_86 -> V_85 = V_30 ;
V_30 -> V_29 = V_86 -> V_29 ;
V_30 -> V_25 = V_86 -> V_25 ;
V_30 -> V_10 = V_10 ;
}
return V_30 ;
}
static void F_79 ( unsigned int V_36 , unsigned int V_63 )
{
struct V_30 * V_30 , * V_87 ;
int V_45 ;
for ( V_45 = 0 ; V_45 < V_63 ; V_45 ++ ) {
V_30 = F_27 ( V_36 + V_45 ) ;
V_87 = V_30 -> V_85 ;
V_30 -> V_85 = NULL ;
V_30 -> V_10 = NULL ;
while ( V_87 ) {
V_30 = V_87 ;
V_87 = V_87 -> V_85 ;
F_17 ( V_30 ) ;
}
}
}
static int F_80 ( struct V_1 * V_10 ,
unsigned int V_36 , unsigned int V_63 )
{
struct V_30 * V_30 ;
struct V_1 * V_84 ;
int V_45 ;
for ( V_45 = 0 ; V_45 < V_63 ; V_45 ++ ) {
V_30 = F_27 ( V_36 + V_45 ) ;
V_30 -> V_10 = V_10 ;
for ( V_84 = V_10 -> V_84 ; V_84 ; V_84 = V_84 -> V_84 ) {
V_30 = F_78 ( V_84 , V_30 ) ;
if ( ! V_30 ) {
F_79 ( V_36 , V_45 + 1 ) ;
return - V_74 ;
}
}
}
return 0 ;
}
struct V_30 * F_53 ( struct V_1 * V_10 ,
unsigned int V_36 )
{
struct V_30 * V_30 ;
for ( V_30 = F_27 ( V_36 ) ; V_30 ;
V_30 = V_30 -> V_85 )
if ( V_30 -> V_10 == V_10 )
return V_30 ;
return NULL ;
}
int F_81 ( struct V_1 * V_10 , unsigned int V_36 ,
T_1 V_31 , struct V_65 * V_41 ,
void * V_88 )
{
struct V_30 * V_30 = F_53 ( V_10 , V_36 ) ;
if ( ! V_30 )
return - V_89 ;
V_30 -> V_31 = V_31 ;
V_30 -> V_41 = V_41 ? V_41 : & V_90 ;
V_30 -> V_88 = V_88 ;
return 0 ;
}
void F_82 ( struct V_1 * V_10 , unsigned int V_36 ,
T_1 V_31 , struct V_65 * V_41 ,
void * V_88 , T_4 V_68 ,
void * V_91 , const char * V_92 )
{
F_81 ( V_10 , V_36 , V_31 , V_41 , V_88 ) ;
F_83 ( V_36 , V_68 , 0 , V_92 ) ;
F_84 ( V_36 , V_91 ) ;
}
void F_85 ( struct V_30 * V_30 )
{
V_30 -> V_31 = 0 ;
V_30 -> V_41 = & V_90 ;
V_30 -> V_88 = NULL ;
}
void F_86 ( struct V_1 * V_10 , unsigned int V_36 ,
unsigned int V_63 )
{
struct V_30 * V_30 ;
int V_45 ;
for ( V_45 = 0 ; V_45 < V_63 ; V_45 ++ ) {
V_30 = F_53 ( V_10 , V_36 + V_45 ) ;
if ( V_30 )
F_85 ( V_30 ) ;
}
F_87 ( V_10 , V_36 , V_63 ) ;
}
void F_88 ( struct V_1 * V_10 , unsigned int V_36 ,
unsigned int V_63 )
{
int V_45 ;
for ( V_45 = 0 ; V_45 < V_63 ; V_45 ++ ) {
F_84 ( V_36 + V_45 , NULL ) ;
F_89 ( V_36 + V_45 , NULL ) ;
}
F_86 ( V_10 , V_36 , V_63 ) ;
}
static bool F_90 ( struct V_1 * V_10 )
{
return V_10 -> V_57 & V_93 ;
}
static void F_91 ( struct V_1 * V_10 ,
unsigned int V_42 ,
unsigned int V_63 )
{
V_10 -> V_8 -> free ( V_10 , V_42 , V_63 ) ;
if ( F_90 ( V_10 ) ) {
F_92 ( ! V_10 -> V_84 ) ;
F_91 ( V_10 -> V_84 , V_42 ,
V_63 ) ;
}
}
static int F_93 ( struct V_1 * V_10 ,
unsigned int V_42 ,
unsigned int V_63 , void * V_94 )
{
int V_37 = 0 ;
struct V_1 * V_84 = V_10 -> V_84 ;
bool V_95 = F_90 ( V_10 ) ;
F_92 ( V_95 && ! V_84 ) ;
if ( V_95 )
V_37 = F_93 ( V_84 , V_42 ,
V_63 , V_94 ) ;
if ( V_37 >= 0 )
V_37 = V_10 -> V_8 -> V_96 ( V_10 , V_42 , V_63 , V_94 ) ;
if ( V_37 < 0 && V_95 )
F_91 ( V_84 , V_42 , V_63 ) ;
return V_37 ;
}
int F_94 ( struct V_1 * V_10 , int V_42 ,
unsigned int V_63 , int V_25 , void * V_94 ,
bool realloc )
{
int V_45 , V_37 , V_36 ;
if ( V_10 == NULL ) {
V_10 = V_20 ;
if ( F_28 ( ! V_10 , L_50 ) )
return - V_38 ;
}
if ( ! V_10 -> V_8 -> V_96 ) {
F_11 ( L_51 ) ;
return - V_97 ;
}
if ( realloc && V_42 >= 0 ) {
V_36 = V_42 ;
} else {
V_36 = F_44 ( V_42 , V_63 , 0 , V_25 ) ;
if ( V_36 < 0 ) {
F_11 ( L_52 ,
V_42 , V_63 ) ;
return V_36 ;
}
}
if ( F_80 ( V_10 , V_36 , V_63 ) ) {
F_11 ( L_53 , V_36 ) ;
V_37 = - V_74 ;
goto V_98;
}
F_8 ( & V_15 ) ;
V_37 = F_93 ( V_10 , V_36 , V_63 , V_94 ) ;
if ( V_37 < 0 ) {
F_10 ( & V_15 ) ;
goto V_99;
}
for ( V_45 = 0 ; V_45 < V_63 ; V_45 ++ )
F_76 ( V_36 + V_45 ) ;
F_10 ( & V_15 ) ;
return V_36 ;
V_99:
F_79 ( V_36 , V_63 ) ;
V_98:
F_95 ( V_36 , V_63 ) ;
return V_37 ;
}
void F_96 ( unsigned int V_36 , unsigned int V_63 )
{
struct V_30 * V_53 = F_27 ( V_36 ) ;
int V_45 ;
if ( F_28 ( ! V_53 || ! V_53 -> V_10 || ! V_53 -> V_10 -> V_8 -> free ,
L_54 ) )
return;
F_8 ( & V_15 ) ;
for ( V_45 = 0 ; V_45 < V_63 ; V_45 ++ )
F_77 ( V_36 + V_45 ) ;
F_91 ( V_53 -> V_10 , V_36 , V_63 ) ;
F_10 ( & V_15 ) ;
F_79 ( V_36 , V_63 ) ;
F_95 ( V_36 , V_63 ) ;
}
int F_97 ( struct V_1 * V_10 ,
unsigned int V_42 , unsigned int V_63 ,
void * V_94 )
{
if ( F_90 ( V_10 ) )
return 0 ;
V_10 = V_10 -> V_84 ;
if ( V_10 )
return F_93 ( V_10 , V_42 ,
V_63 , V_94 ) ;
return - V_97 ;
}
void F_87 ( struct V_1 * V_10 ,
unsigned int V_42 , unsigned int V_63 )
{
if ( ! F_90 ( V_10 ) && V_10 -> V_84 )
F_91 ( V_10 -> V_84 , V_42 ,
V_63 ) ;
}
void F_98 ( struct V_30 * V_30 )
{
if ( V_30 && V_30 -> V_10 ) {
struct V_1 * V_10 = V_30 -> V_10 ;
if ( V_30 -> V_85 )
F_98 ( V_30 -> V_85 ) ;
if ( V_10 -> V_8 -> V_100 )
V_10 -> V_8 -> V_100 ( V_10 , V_30 ) ;
}
}
void F_99 ( struct V_30 * V_30 )
{
if ( V_30 && V_30 -> V_10 ) {
struct V_1 * V_10 = V_30 -> V_10 ;
if ( V_10 -> V_8 -> V_101 )
V_10 -> V_8 -> V_101 ( V_10 , V_30 ) ;
if ( V_30 -> V_85 )
F_99 ( V_30 -> V_85 ) ;
}
}
static void F_7 ( struct V_1 * V_10 )
{
if ( V_10 -> V_8 -> V_96 )
V_10 -> V_57 |= V_102 ;
}
struct V_30 * F_53 ( struct V_1 * V_10 ,
unsigned int V_36 )
{
struct V_30 * V_30 = F_27 ( V_36 ) ;
return ( V_30 && V_30 -> V_10 == V_10 ) ? V_30 : NULL ;
}
static void F_7 ( struct V_1 * V_10 )
{
}
