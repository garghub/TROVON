struct V_1 * F_1 ( void * V_2 )
{
struct V_3 * V_4 ;
char * V_5 ;
V_4 = F_2 ( sizeof( * V_4 ) , V_6 ) ;
V_5 = F_3 ( V_6 , L_1 , V_2 ) ;
if ( ! V_4 || ! V_5 ) {
F_4 ( V_4 ) ;
F_4 ( V_5 ) ;
return NULL ;
}
V_4 -> V_5 = V_5 ;
V_4 -> V_2 = V_2 ;
V_4 -> V_7 . type = V_8 ;
return & V_4 -> V_7 ;
}
void F_5 ( struct V_1 * V_7 )
{
struct V_3 * V_4 ;
if ( F_6 ( V_7 -> type != V_8 ) )
return;
V_4 = F_7 ( V_7 , struct V_3 , V_7 ) ;
F_4 ( V_4 -> V_5 ) ;
F_4 ( V_4 ) ;
}
struct V_9 * F_8 ( struct V_1 * V_7 , int V_10 ,
T_1 V_11 , int V_12 ,
const struct V_13 * V_14 ,
void * V_15 )
{
struct V_9 * V_16 ;
struct V_17 * V_18 ;
V_18 = F_9 ( V_7 ) ;
V_16 = F_10 ( sizeof( * V_16 ) + (sizeof( unsigned int ) * V_10 ) ,
V_6 , F_11 ( V_18 ) ) ;
if ( F_6 ( ! V_16 ) )
return NULL ;
F_12 ( V_18 ) ;
F_13 ( & V_16 -> V_19 , V_6 ) ;
V_16 -> V_14 = V_14 ;
V_16 -> V_15 = V_15 ;
V_16 -> V_7 = V_7 ;
V_16 -> V_11 = V_11 ;
V_16 -> V_20 = V_10 ;
V_16 -> V_21 = V_12 ;
F_14 ( V_16 ) ;
F_15 ( & V_22 ) ;
F_16 ( & V_16 -> V_23 , & V_24 ) ;
F_17 ( & V_22 ) ;
F_18 ( L_2 , V_16 -> V_5 ) ;
return V_16 ;
}
void F_19 ( struct V_9 * V_16 )
{
F_15 ( & V_22 ) ;
F_6 ( V_16 -> V_19 . V_25 ) ;
F_20 ( & V_16 -> V_23 ) ;
if ( F_21 ( V_26 == V_16 ) )
F_22 ( NULL ) ;
F_17 ( & V_22 ) ;
F_18 ( L_3 , V_16 -> V_5 ) ;
F_23 ( F_24 ( V_16 ) ) ;
F_4 ( V_16 ) ;
}
struct V_9 * F_25 ( struct V_17 * V_18 ,
unsigned int V_10 ,
unsigned int V_27 ,
const struct V_13 * V_14 ,
void * V_15 )
{
struct V_9 * V_16 ;
V_16 = F_8 ( F_26 ( V_18 ) , V_10 , V_10 , 0 , V_14 , V_15 ) ;
if ( ! V_16 )
return NULL ;
if ( V_27 > 0 ) {
if ( F_27 ( V_28 ) ) {
int V_29 = F_28 ( V_27 , V_27 , V_10 ,
F_11 ( V_18 ) ) ;
if ( V_29 < 0 )
F_29 ( L_4 ,
V_27 ) ;
}
F_30 ( V_16 , V_27 , 0 , V_10 ) ;
}
return V_16 ;
}
struct V_9 * F_31 ( struct V_17 * V_18 ,
unsigned int V_10 ,
unsigned int V_27 ,
T_1 V_30 ,
const struct V_13 * V_14 ,
void * V_15 )
{
struct V_9 * V_16 ;
V_16 = F_8 ( F_26 ( V_18 ) , V_30 + V_10 ,
V_30 + V_10 , 0 , V_14 , V_15 ) ;
if ( V_16 )
F_30 ( V_16 , V_27 , V_30 , V_10 ) ;
return V_16 ;
}
struct V_9 * F_32 ( struct V_1 * V_7 ,
enum V_31 V_32 )
{
struct V_9 * V_33 , * V_34 = NULL ;
int V_29 ;
F_15 ( & V_22 ) ;
F_33 (h, &irq_domain_list, link) {
if ( V_33 -> V_14 -> V_35 )
V_29 = V_33 -> V_14 -> V_35 ( V_33 , F_9 ( V_7 ) , V_32 ) ;
else
V_29 = ( ( V_7 != NULL ) && ( V_33 -> V_7 == V_7 ) &&
( ( V_32 == V_36 ) ||
( V_33 -> V_32 == V_32 ) ) ) ;
if ( V_29 ) {
V_34 = V_33 ;
break;
}
}
F_17 ( & V_22 ) ;
return V_34 ;
}
void F_22 ( struct V_9 * V_16 )
{
F_18 ( L_5 , V_16 ) ;
V_26 = V_16 ;
}
void F_34 ( struct V_9 * V_16 , unsigned int V_37 )
{
struct V_38 * V_38 = F_35 ( V_37 ) ;
T_1 V_39 ;
if ( F_36 ( ! V_38 || V_38 -> V_16 != V_16 ,
L_6 , V_37 ) )
return;
V_39 = V_38 -> V_39 ;
F_37 ( V_37 , V_40 ) ;
F_38 ( V_37 , NULL , NULL ) ;
F_39 ( V_37 ) ;
if ( V_16 -> V_14 -> V_41 )
V_16 -> V_14 -> V_41 ( V_16 , V_37 ) ;
F_40 () ;
V_38 -> V_16 = NULL ;
V_38 -> V_39 = 0 ;
if ( V_39 < V_16 -> V_20 ) {
V_16 -> V_42 [ V_39 ] = 0 ;
} else {
F_15 ( & V_43 ) ;
F_41 ( & V_16 -> V_19 , V_39 ) ;
F_17 ( & V_43 ) ;
}
}
int F_42 ( struct V_9 * V_16 , unsigned int V_44 ,
T_1 V_39 )
{
struct V_38 * V_38 = F_35 ( V_44 ) ;
int V_45 ;
if ( F_36 ( V_39 >= V_16 -> V_11 ,
L_7 , ( int ) V_39 , V_16 -> V_5 ) )
return - V_46 ;
if ( F_36 ( ! V_38 , L_8 , V_44 ) )
return - V_46 ;
if ( F_36 ( V_38 -> V_16 , L_9 , V_44 ) )
return - V_46 ;
F_15 ( & V_22 ) ;
V_38 -> V_39 = V_39 ;
V_38 -> V_16 = V_16 ;
if ( V_16 -> V_14 -> V_47 ) {
V_45 = V_16 -> V_14 -> V_47 ( V_16 , V_44 , V_39 ) ;
if ( V_45 != 0 ) {
if ( V_45 != - V_48 ) {
F_29 ( L_10 ,
V_16 -> V_5 , V_39 , V_44 , V_45 ) ;
}
V_38 -> V_16 = NULL ;
V_38 -> V_39 = 0 ;
F_17 ( & V_22 ) ;
return V_45 ;
}
if ( ! V_16 -> V_5 && V_38 -> V_49 )
V_16 -> V_5 = V_38 -> V_49 -> V_5 ;
}
if ( V_39 < V_16 -> V_20 ) {
V_16 -> V_42 [ V_39 ] = V_44 ;
} else {
F_15 ( & V_43 ) ;
F_43 ( & V_16 -> V_19 , V_39 , V_38 ) ;
F_17 ( & V_43 ) ;
}
F_17 ( & V_22 ) ;
F_44 ( V_44 , V_40 ) ;
return 0 ;
}
void F_30 ( struct V_9 * V_16 , unsigned int V_50 ,
T_1 V_51 , int V_52 )
{
struct V_17 * V_18 ;
int V_53 ;
V_18 = F_24 ( V_16 ) ;
F_18 ( L_11 , V_54 ,
F_45 ( V_18 ) , V_50 , ( int ) V_51 , V_52 ) ;
for ( V_53 = 0 ; V_53 < V_52 ; V_53 ++ ) {
F_42 ( V_16 , V_50 + V_53 , V_51 + V_53 ) ;
}
}
unsigned int F_46 ( struct V_9 * V_16 )
{
struct V_17 * V_18 ;
unsigned int V_44 ;
if ( V_16 == NULL )
V_16 = V_26 ;
V_18 = F_24 ( V_16 ) ;
V_44 = F_47 ( 1 , F_11 ( V_18 ) ) ;
if ( ! V_44 ) {
F_18 ( L_12 ) ;
return 0 ;
}
if ( V_44 >= V_16 -> V_21 ) {
F_48 ( L_13 ,
V_16 -> V_21 ) ;
F_49 ( V_44 ) ;
return 0 ;
}
F_18 ( L_14 , V_44 ) ;
if ( F_42 ( V_16 , V_44 , V_44 ) ) {
F_49 ( V_44 ) ;
return 0 ;
}
return V_44 ;
}
unsigned int F_50 ( struct V_9 * V_16 ,
T_1 V_39 )
{
struct V_17 * V_18 ;
int V_44 ;
F_18 ( L_15 , V_16 , V_39 ) ;
if ( V_16 == NULL )
V_16 = V_26 ;
if ( V_16 == NULL ) {
F_36 ( 1 , L_16 , V_54 , V_39 ) ;
return 0 ;
}
F_18 ( L_17 , V_16 ) ;
V_18 = F_24 ( V_16 ) ;
V_44 = F_51 ( V_16 , V_39 ) ;
if ( V_44 ) {
F_18 ( L_18 , V_44 ) ;
return V_44 ;
}
V_44 = F_52 ( - 1 , 1 , V_39 , F_11 ( V_18 ) ) ;
if ( V_44 <= 0 ) {
F_18 ( L_19 ) ;
return 0 ;
}
if ( F_42 ( V_16 , V_44 , V_39 ) ) {
F_49 ( V_44 ) ;
return 0 ;
}
F_18 ( L_20 ,
V_39 , F_45 ( V_18 ) , V_44 ) ;
return V_44 ;
}
int F_53 ( struct V_9 * V_16 , unsigned int V_50 ,
T_1 V_51 , int V_52 )
{
struct V_17 * V_18 ;
int V_45 ;
V_18 = F_24 ( V_16 ) ;
V_45 = F_28 ( V_50 , V_50 , V_52 ,
F_11 ( V_18 ) ) ;
if ( F_21 ( V_45 < 0 ) )
return V_45 ;
F_30 ( V_16 , V_50 , V_51 , V_52 ) ;
return 0 ;
}
static int F_54 ( struct V_9 * V_55 ,
struct V_56 * V_57 ,
T_1 * V_39 , unsigned int * type )
{
#ifdef F_55
if ( V_55 -> V_14 -> V_58 )
return V_55 -> V_14 -> V_58 ( V_55 , V_57 , V_39 , type ) ;
#endif
if ( V_55 -> V_14 -> V_59 )
return V_55 -> V_14 -> V_59 ( V_55 , F_9 ( V_57 -> V_7 ) ,
V_57 -> V_60 , V_57 -> V_61 ,
V_39 , type ) ;
* V_39 = V_57 -> V_60 [ 0 ] ;
return 0 ;
}
static void F_56 ( struct V_62 * V_38 ,
struct V_56 * V_57 )
{
int V_53 ;
V_57 -> V_7 = V_38 -> V_63 ? & V_38 -> V_63 -> V_7 : NULL ;
V_57 -> V_61 = V_38 -> V_64 ;
for ( V_53 = 0 ; V_53 < V_38 -> V_64 ; V_53 ++ )
V_57 -> V_60 [ V_53 ] = V_38 -> args [ V_53 ] ;
}
unsigned int F_57 ( struct V_56 * V_57 )
{
struct V_9 * V_16 ;
T_1 V_39 ;
unsigned int type = V_65 ;
int V_44 ;
if ( V_57 -> V_7 )
V_16 = F_32 ( V_57 -> V_7 , V_36 ) ;
else
V_16 = V_26 ;
if ( ! V_16 ) {
F_58 ( L_21 ,
F_45 ( F_9 ( V_57 -> V_7 ) ) ) ;
return 0 ;
}
if ( F_54 ( V_16 , V_57 , & V_39 , & type ) )
return 0 ;
if ( F_59 ( V_16 ) ) {
V_44 = F_51 ( V_16 , V_39 ) ;
if ( V_44 )
return V_44 ;
V_44 = F_60 ( V_16 , 1 , V_66 , V_57 ) ;
if ( V_44 <= 0 )
return 0 ;
} else {
V_44 = F_50 ( V_16 , V_39 ) ;
if ( ! V_44 )
return V_44 ;
}
if ( type != V_65 &&
type != F_61 ( V_44 ) )
F_62 ( V_44 , type ) ;
return V_44 ;
}
unsigned int F_63 ( struct V_62 * V_38 )
{
struct V_56 V_57 ;
F_56 ( V_38 , & V_57 ) ;
return F_57 ( & V_57 ) ;
}
void F_64 ( unsigned int V_44 )
{
struct V_38 * V_38 = F_35 ( V_44 ) ;
struct V_9 * V_16 ;
if ( ! V_44 || ! V_38 )
return;
V_16 = V_38 -> V_16 ;
if ( F_6 ( V_16 == NULL ) )
return;
F_34 ( V_16 , V_44 ) ;
F_49 ( V_44 ) ;
}
unsigned int F_51 ( struct V_9 * V_16 ,
T_1 V_39 )
{
struct V_38 * V_2 ;
if ( V_16 == NULL )
V_16 = V_26 ;
if ( V_16 == NULL )
return 0 ;
if ( V_39 < V_16 -> V_21 ) {
V_2 = F_65 ( V_16 , V_39 ) ;
if ( V_2 && V_2 -> V_39 == V_39 )
return V_39 ;
}
if ( V_39 < V_16 -> V_20 )
return V_16 -> V_42 [ V_39 ] ;
F_66 () ;
V_2 = F_67 ( & V_16 -> V_19 , V_39 ) ;
F_68 () ;
return V_2 ? V_2 -> V_37 : 0 ;
}
static int F_69 ( struct V_67 * V_68 , void * V_69 )
{
unsigned long V_70 ;
struct V_71 * V_72 ;
struct V_9 * V_16 ;
struct V_73 V_74 ;
void * V_2 , * * V_75 ;
int V_53 ;
F_70 ( V_68 , L_22 ,
L_23 , L_24 , L_25 , L_26 , L_27 ) ;
F_15 ( & V_22 ) ;
F_33 (domain, &irq_domain_list, link) {
struct V_17 * V_18 ;
int V_52 = 0 ;
V_18 = F_24 ( V_16 ) ;
F_71 (slot, &domain->revmap_tree, &iter, 0 )
V_52 ++ ;
F_70 ( V_68 , L_28 ,
V_16 == V_26 ? '*' : ' ' , V_16 -> V_5 ,
V_16 -> V_20 + V_52 , V_16 -> V_20 ,
V_16 -> V_21 ,
V_18 ? F_45 ( V_18 ) : L_29 ) ;
}
F_17 ( & V_22 ) ;
F_70 ( V_68 , L_30 , L_31 , L_32 ,
L_33 , ( int ) ( 2 * sizeof( void * ) + 2 ) , L_34 ,
L_35 , L_36 , L_37 ) ;
for ( V_53 = 1 ; V_53 < V_76 ; V_53 ++ ) {
V_72 = F_72 ( V_53 ) ;
if ( ! V_72 )
continue;
F_73 ( & V_72 -> V_77 , V_70 ) ;
V_16 = V_72 -> V_38 . V_16 ;
if ( V_16 ) {
struct V_78 * V_49 ;
int V_39 = V_72 -> V_38 . V_39 ;
bool V_79 ;
F_70 ( V_68 , L_38 , V_53 ) ;
F_70 ( V_68 , L_39 , V_39 ) ;
V_49 = F_74 ( V_72 ) ;
F_70 ( V_68 , L_40 , ( V_49 && V_49 -> V_5 ) ? V_49 -> V_5 : L_41 ) ;
V_2 = F_75 ( V_72 ) ;
F_70 ( V_68 , V_2 ? L_42 : L_43 , V_2 ) ;
F_70 ( V_68 , L_44 , ( V_72 -> V_80 && V_72 -> V_80 -> V_81 ) ? '*' : ' ' ) ;
V_79 = ( V_53 == V_39 ) && ( V_53 < V_16 -> V_21 ) ;
F_70 ( V_68 , L_45 ,
( V_39 < V_16 -> V_20 ) ? L_46 : L_47 ,
V_79 ? L_48 : L_29 ) ;
F_70 ( V_68 , L_49 , V_72 -> V_38 . V_16 -> V_5 ) ;
}
F_76 ( & V_72 -> V_77 , V_70 ) ;
}
return 0 ;
}
static int F_77 ( struct V_82 * V_82 , struct V_83 * V_83 )
{
return F_78 ( V_83 , F_69 , V_82 -> V_84 ) ;
}
static int T_2 F_79 ( void )
{
if ( F_80 ( L_50 , V_85 , NULL ,
NULL , & V_86 ) == NULL )
return - V_87 ;
return 0 ;
}
int F_81 ( struct V_9 * V_55 , struct V_17 * V_88 ,
const T_3 * V_89 , unsigned int V_90 ,
unsigned long * V_91 , unsigned int * V_92 )
{
if ( F_6 ( V_90 < 1 ) )
return - V_46 ;
* V_91 = V_89 [ 0 ] ;
* V_92 = V_65 ;
return 0 ;
}
int F_82 ( struct V_9 * V_55 , struct V_17 * V_88 ,
const T_3 * V_89 , unsigned int V_90 ,
T_1 * V_91 , unsigned int * V_92 )
{
if ( F_6 ( V_90 < 2 ) )
return - V_46 ;
* V_91 = V_89 [ 0 ] ;
* V_92 = V_89 [ 1 ] & V_93 ;
return 0 ;
}
int F_83 ( struct V_9 * V_55 ,
struct V_17 * V_88 ,
const T_3 * V_89 , unsigned int V_90 ,
unsigned long * V_91 , unsigned int * V_92 )
{
if ( F_6 ( V_90 < 1 ) )
return - V_46 ;
* V_91 = V_89 [ 0 ] ;
* V_92 = ( V_90 > 1 ) ? V_89 [ 1 ] : V_65 ;
return 0 ;
}
static int F_52 ( int V_44 , unsigned int V_94 ,
T_1 V_39 , int V_95 )
{
unsigned int V_96 ;
if ( V_44 >= 0 ) {
V_44 = F_28 ( V_44 , V_44 , V_94 , V_95 ) ;
} else {
V_96 = V_39 % V_76 ;
if ( V_96 == 0 )
V_96 ++ ;
V_44 = F_84 ( V_96 , V_94 , V_95 ) ;
if ( V_44 <= 0 && V_96 > 1 )
V_44 = F_84 ( 1 , V_94 , V_95 ) ;
}
return V_44 ;
}
struct V_9 * F_85 ( struct V_9 * V_97 ,
unsigned int V_70 ,
unsigned int V_10 ,
struct V_1 * V_7 ,
const struct V_13 * V_14 ,
void * V_15 )
{
struct V_9 * V_16 ;
if ( V_10 )
V_16 = F_86 ( V_7 , V_10 , V_14 , V_15 ) ;
else
V_16 = F_87 ( V_7 , V_14 , V_15 ) ;
if ( V_16 ) {
V_16 -> V_97 = V_97 ;
V_16 -> V_70 |= V_70 ;
}
return V_16 ;
}
static void F_88 ( int V_44 )
{
struct V_38 * V_2 ;
for ( V_2 = F_35 ( V_44 ) ; V_2 ; V_2 = V_2 -> V_98 ) {
struct V_9 * V_16 = V_2 -> V_16 ;
T_1 V_39 = V_2 -> V_39 ;
if ( V_39 < V_16 -> V_20 ) {
V_16 -> V_42 [ V_39 ] = V_44 ;
} else {
F_15 ( & V_43 ) ;
F_43 ( & V_16 -> V_19 , V_39 , V_2 ) ;
F_17 ( & V_43 ) ;
}
if ( ! V_16 -> V_5 && V_2 -> V_49 )
V_16 -> V_5 = V_2 -> V_49 -> V_5 ;
}
F_44 ( V_44 , V_40 ) ;
}
static void F_89 ( int V_44 )
{
struct V_38 * V_2 ;
F_37 ( V_44 , V_40 ) ;
F_38 ( V_44 , NULL , NULL ) ;
F_39 ( V_44 ) ;
F_40 () ;
for ( V_2 = F_35 ( V_44 ) ; V_2 ; V_2 = V_2 -> V_98 ) {
struct V_9 * V_16 = V_2 -> V_16 ;
T_1 V_39 = V_2 -> V_39 ;
if ( V_39 < V_16 -> V_20 ) {
V_16 -> V_42 [ V_39 ] = 0 ;
} else {
F_15 ( & V_43 ) ;
F_41 ( & V_16 -> V_19 , V_39 ) ;
F_17 ( & V_43 ) ;
}
}
}
static struct V_38 * F_90 ( struct V_9 * V_16 ,
struct V_38 * V_99 )
{
struct V_38 * V_38 ;
V_38 = F_10 ( sizeof( * V_38 ) , V_6 ,
F_91 ( V_99 ) ) ;
if ( V_38 ) {
V_99 -> V_98 = V_38 ;
V_38 -> V_37 = V_99 -> V_37 ;
V_38 -> V_100 = V_99 -> V_100 ;
V_38 -> V_16 = V_16 ;
}
return V_38 ;
}
static void F_92 ( unsigned int V_44 , unsigned int V_76 )
{
struct V_38 * V_38 , * V_101 ;
int V_53 ;
for ( V_53 = 0 ; V_53 < V_76 ; V_53 ++ ) {
V_38 = F_35 ( V_44 + V_53 ) ;
V_101 = V_38 -> V_98 ;
V_38 -> V_98 = NULL ;
V_38 -> V_16 = NULL ;
while ( V_101 ) {
V_38 = V_101 ;
V_101 = V_101 -> V_98 ;
F_4 ( V_38 ) ;
}
}
}
static int F_93 ( struct V_9 * V_16 ,
unsigned int V_44 , unsigned int V_76 )
{
struct V_38 * V_38 ;
struct V_9 * V_97 ;
int V_53 ;
for ( V_53 = 0 ; V_53 < V_76 ; V_53 ++ ) {
V_38 = F_35 ( V_44 + V_53 ) ;
V_38 -> V_16 = V_16 ;
for ( V_97 = V_16 -> V_97 ; V_97 ; V_97 = V_97 -> V_97 ) {
V_38 = F_90 ( V_97 , V_38 ) ;
if ( ! V_38 ) {
F_92 ( V_44 , V_53 + 1 ) ;
return - V_87 ;
}
}
}
return 0 ;
}
struct V_38 * F_65 ( struct V_9 * V_16 ,
unsigned int V_44 )
{
struct V_38 * V_38 ;
for ( V_38 = F_35 ( V_44 ) ; V_38 ;
V_38 = V_38 -> V_98 )
if ( V_38 -> V_16 == V_16 )
return V_38 ;
return NULL ;
}
int F_94 ( struct V_9 * V_16 , unsigned int V_44 ,
T_1 V_39 , struct V_78 * V_49 ,
void * V_102 )
{
struct V_38 * V_38 = F_65 ( V_16 , V_44 ) ;
if ( ! V_38 )
return - V_103 ;
V_38 -> V_39 = V_39 ;
V_38 -> V_49 = V_49 ? V_49 : & V_104 ;
V_38 -> V_102 = V_102 ;
return 0 ;
}
void F_95 ( struct V_9 * V_16 , unsigned int V_44 ,
T_1 V_39 , struct V_78 * V_49 ,
void * V_102 , T_4 V_81 ,
void * V_105 , const char * V_106 )
{
F_94 ( V_16 , V_44 , V_39 , V_49 , V_102 ) ;
F_96 ( V_44 , V_81 , 0 , V_106 ) ;
F_97 ( V_44 , V_105 ) ;
}
void F_98 ( struct V_38 * V_38 )
{
V_38 -> V_39 = 0 ;
V_38 -> V_49 = & V_104 ;
V_38 -> V_102 = NULL ;
}
void F_99 ( struct V_9 * V_16 , unsigned int V_44 ,
unsigned int V_76 )
{
struct V_38 * V_38 ;
int V_53 ;
for ( V_53 = 0 ; V_53 < V_76 ; V_53 ++ ) {
V_38 = F_65 ( V_16 , V_44 + V_53 ) ;
if ( V_38 )
F_98 ( V_38 ) ;
}
F_100 ( V_16 , V_44 , V_76 ) ;
}
void F_101 ( struct V_9 * V_16 , unsigned int V_44 ,
unsigned int V_76 )
{
int V_53 ;
for ( V_53 = 0 ; V_53 < V_76 ; V_53 ++ ) {
F_97 ( V_44 + V_53 , NULL ) ;
F_102 ( V_44 + V_53 , NULL ) ;
}
F_99 ( V_16 , V_44 , V_76 ) ;
}
static bool F_103 ( struct V_9 * V_16 )
{
return V_16 -> V_70 & V_107 ;
}
static void F_104 ( struct V_9 * V_16 ,
unsigned int V_50 ,
unsigned int V_76 )
{
V_16 -> V_14 -> free ( V_16 , V_50 , V_76 ) ;
if ( F_103 ( V_16 ) ) {
F_105 ( ! V_16 -> V_97 ) ;
F_104 ( V_16 -> V_97 , V_50 ,
V_76 ) ;
}
}
static int F_106 ( struct V_9 * V_16 ,
unsigned int V_50 ,
unsigned int V_76 , void * V_108 )
{
int V_45 = 0 ;
struct V_9 * V_97 = V_16 -> V_97 ;
bool V_109 = F_103 ( V_16 ) ;
F_105 ( V_109 && ! V_97 ) ;
if ( V_109 )
V_45 = F_106 ( V_97 , V_50 ,
V_76 , V_108 ) ;
if ( V_45 >= 0 )
V_45 = V_16 -> V_14 -> V_110 ( V_16 , V_50 , V_76 , V_108 ) ;
if ( V_45 < 0 && V_109 )
F_104 ( V_97 , V_50 , V_76 ) ;
return V_45 ;
}
int F_107 ( struct V_9 * V_16 , int V_50 ,
unsigned int V_76 , int V_95 , void * V_108 ,
bool realloc )
{
int V_53 , V_45 , V_44 ;
if ( V_16 == NULL ) {
V_16 = V_26 ;
if ( F_36 ( ! V_16 , L_51 ) )
return - V_46 ;
}
if ( ! V_16 -> V_14 -> V_110 ) {
F_18 ( L_52 ) ;
return - V_111 ;
}
if ( realloc && V_50 >= 0 ) {
V_44 = V_50 ;
} else {
V_44 = F_52 ( V_50 , V_76 , 0 , V_95 ) ;
if ( V_44 < 0 ) {
F_18 ( L_53 ,
V_50 , V_76 ) ;
return V_44 ;
}
}
if ( F_93 ( V_16 , V_44 , V_76 ) ) {
F_18 ( L_54 , V_44 ) ;
V_45 = - V_87 ;
goto V_112;
}
F_15 ( & V_22 ) ;
V_45 = F_106 ( V_16 , V_44 , V_76 , V_108 ) ;
if ( V_45 < 0 ) {
F_17 ( & V_22 ) ;
goto V_113;
}
for ( V_53 = 0 ; V_53 < V_76 ; V_53 ++ )
F_88 ( V_44 + V_53 ) ;
F_17 ( & V_22 ) ;
return V_44 ;
V_113:
F_92 ( V_44 , V_76 ) ;
V_112:
F_108 ( V_44 , V_76 ) ;
return V_45 ;
}
void F_109 ( unsigned int V_44 , unsigned int V_76 )
{
struct V_38 * V_2 = F_35 ( V_44 ) ;
int V_53 ;
if ( F_36 ( ! V_2 || ! V_2 -> V_16 || ! V_2 -> V_16 -> V_14 -> free ,
L_55 ) )
return;
F_15 ( & V_22 ) ;
for ( V_53 = 0 ; V_53 < V_76 ; V_53 ++ )
F_89 ( V_44 + V_53 ) ;
F_104 ( V_2 -> V_16 , V_44 , V_76 ) ;
F_17 ( & V_22 ) ;
F_92 ( V_44 , V_76 ) ;
F_108 ( V_44 , V_76 ) ;
}
int F_110 ( struct V_9 * V_16 ,
unsigned int V_50 , unsigned int V_76 ,
void * V_108 )
{
if ( F_103 ( V_16 ) )
return 0 ;
V_16 = V_16 -> V_97 ;
if ( V_16 )
return F_106 ( V_16 , V_50 ,
V_76 , V_108 ) ;
return - V_111 ;
}
void F_100 ( struct V_9 * V_16 ,
unsigned int V_50 , unsigned int V_76 )
{
if ( ! F_103 ( V_16 ) && V_16 -> V_97 )
F_104 ( V_16 -> V_97 , V_50 ,
V_76 ) ;
}
void F_111 ( struct V_38 * V_38 )
{
if ( V_38 && V_38 -> V_16 ) {
struct V_9 * V_16 = V_38 -> V_16 ;
if ( V_38 -> V_98 )
F_111 ( V_38 -> V_98 ) ;
if ( V_16 -> V_14 -> V_114 )
V_16 -> V_14 -> V_114 ( V_16 , V_38 ) ;
}
}
void F_112 ( struct V_38 * V_38 )
{
if ( V_38 && V_38 -> V_16 ) {
struct V_9 * V_16 = V_38 -> V_16 ;
if ( V_16 -> V_14 -> V_115 )
V_16 -> V_14 -> V_115 ( V_16 , V_38 ) ;
if ( V_38 -> V_98 )
F_112 ( V_38 -> V_98 ) ;
}
}
static void F_14 ( struct V_9 * V_16 )
{
if ( V_16 -> V_14 -> V_110 )
V_16 -> V_70 |= V_116 ;
}
struct V_38 * F_65 ( struct V_9 * V_16 ,
unsigned int V_44 )
{
struct V_38 * V_38 = F_35 ( V_44 ) ;
return ( V_38 && V_38 -> V_16 == V_16 ) ? V_38 : NULL ;
}
void F_95 ( struct V_9 * V_16 , unsigned int V_44 ,
T_1 V_39 , struct V_78 * V_49 ,
void * V_102 , T_4 V_81 ,
void * V_105 , const char * V_106 )
{
F_113 ( V_44 , V_49 , V_81 , V_106 ) ;
F_114 ( V_44 , V_102 ) ;
F_97 ( V_44 , V_105 ) ;
}
static void F_14 ( struct V_9 * V_16 )
{
}
