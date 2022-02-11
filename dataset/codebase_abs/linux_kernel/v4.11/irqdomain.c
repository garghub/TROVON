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
if ( F_6 ( ! F_7 ( V_7 ) ) )
return;
V_4 = F_8 ( V_7 , struct V_3 , V_7 ) ;
F_4 ( V_4 -> V_5 ) ;
F_4 ( V_4 ) ;
}
struct V_9 * F_9 ( struct V_1 * V_7 , int V_10 ,
T_1 V_11 , int V_12 ,
const struct V_13 * V_14 ,
void * V_15 )
{
struct V_16 * V_17 = F_10 ( V_7 ) ;
struct V_9 * V_18 ;
V_18 = F_11 ( sizeof( * V_18 ) + (sizeof( unsigned int ) * V_10 ) ,
V_6 , F_12 ( V_17 ) ) ;
if ( F_6 ( ! V_18 ) )
return NULL ;
F_13 ( V_17 ) ;
F_14 ( & V_18 -> V_19 , V_6 ) ;
V_18 -> V_14 = V_14 ;
V_18 -> V_15 = V_15 ;
V_18 -> V_7 = V_7 ;
V_18 -> V_11 = V_11 ;
V_18 -> V_20 = V_10 ;
V_18 -> V_21 = V_12 ;
F_15 ( V_18 ) ;
F_16 ( & V_22 ) ;
F_17 ( & V_18 -> V_23 , & V_24 ) ;
F_18 ( & V_22 ) ;
F_19 ( L_2 , V_18 -> V_5 ) ;
return V_18 ;
}
void F_20 ( struct V_9 * V_18 )
{
F_16 ( & V_22 ) ;
F_6 ( ! F_21 ( & V_18 -> V_19 ) ) ;
F_22 ( & V_18 -> V_23 ) ;
if ( F_23 ( V_25 == V_18 ) )
F_24 ( NULL ) ;
F_18 ( & V_22 ) ;
F_19 ( L_3 , V_18 -> V_5 ) ;
F_25 ( F_26 ( V_18 ) ) ;
F_4 ( V_18 ) ;
}
struct V_9 * F_27 ( struct V_16 * V_17 ,
unsigned int V_10 ,
unsigned int V_26 ,
const struct V_13 * V_14 ,
void * V_15 )
{
struct V_9 * V_18 ;
V_18 = F_9 ( F_28 ( V_17 ) , V_10 , V_10 , 0 , V_14 , V_15 ) ;
if ( ! V_18 )
return NULL ;
if ( V_26 > 0 ) {
if ( F_29 ( V_27 ) ) {
int V_28 = F_30 ( V_26 , V_26 , V_10 ,
F_12 ( V_17 ) ) ;
if ( V_28 < 0 )
F_31 ( L_4 ,
V_26 ) ;
}
F_32 ( V_18 , V_26 , 0 , V_10 ) ;
}
return V_18 ;
}
struct V_9 * F_33 ( struct V_16 * V_17 ,
unsigned int V_10 ,
unsigned int V_26 ,
T_1 V_29 ,
const struct V_13 * V_14 ,
void * V_15 )
{
struct V_9 * V_18 ;
V_18 = F_9 ( F_28 ( V_17 ) , V_29 + V_10 ,
V_29 + V_10 , 0 , V_14 , V_15 ) ;
if ( V_18 )
F_32 ( V_18 , V_26 , V_29 , V_10 ) ;
return V_18 ;
}
struct V_9 * F_34 ( struct V_30 * V_31 ,
enum V_32 V_33 )
{
struct V_9 * V_34 , * V_35 = NULL ;
struct V_1 * V_7 = V_31 -> V_7 ;
int V_28 ;
F_16 ( & V_22 ) ;
F_35 (h, &irq_domain_list, link) {
if ( V_34 -> V_14 -> V_36 && V_31 -> V_37 )
V_28 = V_34 -> V_14 -> V_36 ( V_34 , V_31 , V_33 ) ;
else if ( V_34 -> V_14 -> V_38 )
V_28 = V_34 -> V_14 -> V_38 ( V_34 , F_10 ( V_7 ) , V_33 ) ;
else
V_28 = ( ( V_7 != NULL ) && ( V_34 -> V_7 == V_7 ) &&
( ( V_33 == V_39 ) ||
( V_34 -> V_33 == V_33 ) ) ) ;
if ( V_28 ) {
V_35 = V_34 ;
break;
}
}
F_18 ( & V_22 ) ;
return V_35 ;
}
bool F_36 ( void )
{
struct V_9 * V_34 ;
bool V_40 = true ;
F_16 ( & V_22 ) ;
F_35 (h, &irq_domain_list, link) {
if ( F_37 ( V_34 ) &&
! F_38 ( V_34 ) ) {
V_40 = false ;
break;
}
}
F_18 ( & V_22 ) ;
return V_40 ;
}
void F_24 ( struct V_9 * V_18 )
{
F_19 ( L_5 , V_18 ) ;
V_25 = V_18 ;
}
void F_39 ( struct V_9 * V_18 , unsigned int V_41 )
{
struct V_42 * V_42 = F_40 ( V_41 ) ;
T_1 V_43 ;
if ( F_41 ( ! V_42 || V_42 -> V_18 != V_18 ,
L_6 , V_41 ) )
return;
V_43 = V_42 -> V_43 ;
F_42 ( V_41 , V_44 ) ;
F_43 ( V_41 , NULL , NULL ) ;
F_44 ( V_41 ) ;
if ( V_18 -> V_14 -> V_45 )
V_18 -> V_14 -> V_45 ( V_18 , V_41 ) ;
F_45 () ;
V_42 -> V_18 = NULL ;
V_42 -> V_43 = 0 ;
if ( V_43 < V_18 -> V_20 ) {
V_18 -> V_46 [ V_43 ] = 0 ;
} else {
F_16 ( & V_47 ) ;
F_46 ( & V_18 -> V_19 , V_43 ) ;
F_18 ( & V_47 ) ;
}
}
int F_47 ( struct V_9 * V_18 , unsigned int V_48 ,
T_1 V_43 )
{
struct V_42 * V_42 = F_40 ( V_48 ) ;
int V_40 ;
if ( F_41 ( V_43 >= V_18 -> V_11 ,
L_7 , ( int ) V_43 , V_18 -> V_5 ) )
return - V_49 ;
if ( F_41 ( ! V_42 , L_8 , V_48 ) )
return - V_49 ;
if ( F_41 ( V_42 -> V_18 , L_9 , V_48 ) )
return - V_49 ;
F_16 ( & V_22 ) ;
V_42 -> V_43 = V_43 ;
V_42 -> V_18 = V_18 ;
if ( V_18 -> V_14 -> V_50 ) {
V_40 = V_18 -> V_14 -> V_50 ( V_18 , V_48 , V_43 ) ;
if ( V_40 != 0 ) {
if ( V_40 != - V_51 ) {
F_31 ( L_10 ,
V_18 -> V_5 , V_43 , V_48 , V_40 ) ;
}
V_42 -> V_18 = NULL ;
V_42 -> V_43 = 0 ;
F_18 ( & V_22 ) ;
return V_40 ;
}
if ( ! V_18 -> V_5 && V_42 -> V_52 )
V_18 -> V_5 = V_42 -> V_52 -> V_5 ;
}
if ( V_43 < V_18 -> V_20 ) {
V_18 -> V_46 [ V_43 ] = V_48 ;
} else {
F_16 ( & V_47 ) ;
F_48 ( & V_18 -> V_19 , V_43 , V_42 ) ;
F_18 ( & V_47 ) ;
}
F_18 ( & V_22 ) ;
F_49 ( V_48 , V_44 ) ;
return 0 ;
}
void F_32 ( struct V_9 * V_18 , unsigned int V_53 ,
T_1 V_54 , int V_55 )
{
struct V_16 * V_17 ;
int V_56 ;
V_17 = F_26 ( V_18 ) ;
F_19 ( L_11 , V_57 ,
F_50 ( V_17 ) , V_53 , ( int ) V_54 , V_55 ) ;
for ( V_56 = 0 ; V_56 < V_55 ; V_56 ++ ) {
F_47 ( V_18 , V_53 + V_56 , V_54 + V_56 ) ;
}
}
unsigned int F_51 ( struct V_9 * V_18 )
{
struct V_16 * V_17 ;
unsigned int V_48 ;
if ( V_18 == NULL )
V_18 = V_25 ;
V_17 = F_26 ( V_18 ) ;
V_48 = F_52 ( 1 , F_12 ( V_17 ) ) ;
if ( ! V_48 ) {
F_19 ( L_12 ) ;
return 0 ;
}
if ( V_48 >= V_18 -> V_21 ) {
F_53 ( L_13 ,
V_18 -> V_21 ) ;
F_54 ( V_48 ) ;
return 0 ;
}
F_19 ( L_14 , V_48 ) ;
if ( F_47 ( V_18 , V_48 , V_48 ) ) {
F_54 ( V_48 ) ;
return 0 ;
}
return V_48 ;
}
unsigned int F_55 ( struct V_9 * V_18 ,
T_1 V_43 )
{
struct V_16 * V_17 ;
int V_48 ;
F_19 ( L_15 , V_18 , V_43 ) ;
if ( V_18 == NULL )
V_18 = V_25 ;
if ( V_18 == NULL ) {
F_41 ( 1 , L_16 , V_57 , V_43 ) ;
return 0 ;
}
F_19 ( L_17 , V_18 ) ;
V_17 = F_26 ( V_18 ) ;
V_48 = F_56 ( V_18 , V_43 ) ;
if ( V_48 ) {
F_19 ( L_18 , V_48 ) ;
return V_48 ;
}
V_48 = F_57 ( - 1 , 1 , V_43 , F_12 ( V_17 ) , NULL ) ;
if ( V_48 <= 0 ) {
F_19 ( L_19 ) ;
return 0 ;
}
if ( F_47 ( V_18 , V_48 , V_43 ) ) {
F_54 ( V_48 ) ;
return 0 ;
}
F_19 ( L_20 ,
V_43 , F_50 ( V_17 ) , V_48 ) ;
return V_48 ;
}
int F_58 ( struct V_9 * V_18 , unsigned int V_53 ,
T_1 V_54 , int V_55 )
{
struct V_16 * V_17 ;
int V_40 ;
V_17 = F_26 ( V_18 ) ;
V_40 = F_30 ( V_53 , V_53 , V_55 ,
F_12 ( V_17 ) ) ;
if ( F_23 ( V_40 < 0 ) )
return V_40 ;
F_32 ( V_18 , V_53 , V_54 , V_55 ) ;
return 0 ;
}
static int F_59 ( struct V_9 * V_58 ,
struct V_30 * V_31 ,
T_1 * V_43 , unsigned int * type )
{
#ifdef F_60
if ( V_58 -> V_14 -> V_59 )
return V_58 -> V_14 -> V_59 ( V_58 , V_31 , V_43 , type ) ;
#endif
if ( V_58 -> V_14 -> V_60 )
return V_58 -> V_14 -> V_60 ( V_58 , F_10 ( V_31 -> V_7 ) ,
V_31 -> V_61 , V_31 -> V_37 ,
V_43 , type ) ;
* V_43 = V_31 -> V_61 [ 0 ] ;
return 0 ;
}
static void F_61 ( struct V_62 * V_42 ,
struct V_30 * V_31 )
{
int V_56 ;
V_31 -> V_7 = V_42 -> V_63 ? & V_42 -> V_63 -> V_7 : NULL ;
V_31 -> V_37 = V_42 -> V_64 ;
for ( V_56 = 0 ; V_56 < V_42 -> V_64 ; V_56 ++ )
V_31 -> V_61 [ V_56 ] = V_42 -> args [ V_56 ] ;
}
unsigned int F_62 ( struct V_30 * V_31 )
{
struct V_9 * V_18 ;
struct V_42 * V_42 ;
T_1 V_43 ;
unsigned int type = V_65 ;
int V_48 ;
if ( V_31 -> V_7 ) {
V_18 = F_34 ( V_31 , V_66 ) ;
if ( ! V_18 )
V_18 = F_34 ( V_31 , V_39 ) ;
} else {
V_18 = V_25 ;
}
if ( ! V_18 ) {
F_63 ( L_21 ,
F_50 ( F_10 ( V_31 -> V_7 ) ) ) ;
return 0 ;
}
if ( F_59 ( V_18 , V_31 , & V_43 , & type ) )
return 0 ;
if ( F_6 ( type & ~ V_67 ) )
type &= V_67 ;
V_48 = F_56 ( V_18 , V_43 ) ;
if ( V_48 ) {
if ( type == V_65 || type == F_64 ( V_48 ) )
return V_48 ;
if ( F_64 ( V_48 ) == V_65 ) {
V_42 = F_40 ( V_48 ) ;
if ( ! V_42 )
return 0 ;
F_65 ( V_42 , type ) ;
return V_48 ;
}
F_63 ( L_22 ,
V_43 , F_50 ( F_10 ( V_31 -> V_7 ) ) ) ;
return 0 ;
}
if ( F_66 ( V_18 ) ) {
V_48 = F_67 ( V_18 , 1 , V_68 , V_31 ) ;
if ( V_48 <= 0 )
return 0 ;
} else {
V_48 = F_55 ( V_18 , V_43 ) ;
if ( ! V_48 )
return V_48 ;
}
V_42 = F_40 ( V_48 ) ;
if ( ! V_42 ) {
if ( F_66 ( V_18 ) )
F_68 ( V_48 , 1 ) ;
else
F_69 ( V_48 ) ;
return 0 ;
}
F_65 ( V_42 , type ) ;
return V_48 ;
}
unsigned int F_70 ( struct V_62 * V_42 )
{
struct V_30 V_31 ;
F_61 ( V_42 , & V_31 ) ;
return F_62 ( & V_31 ) ;
}
void F_69 ( unsigned int V_48 )
{
struct V_42 * V_42 = F_40 ( V_48 ) ;
struct V_9 * V_18 ;
if ( ! V_48 || ! V_42 )
return;
V_18 = V_42 -> V_18 ;
if ( F_6 ( V_18 == NULL ) )
return;
if ( F_66 ( V_18 ) ) {
F_68 ( V_48 , 1 ) ;
} else {
F_39 ( V_18 , V_48 ) ;
F_54 ( V_48 ) ;
}
}
unsigned int F_56 ( struct V_9 * V_18 ,
T_1 V_43 )
{
struct V_42 * V_2 ;
if ( V_18 == NULL )
V_18 = V_25 ;
if ( V_18 == NULL )
return 0 ;
if ( V_43 < V_18 -> V_21 ) {
V_2 = F_71 ( V_18 , V_43 ) ;
if ( V_2 && V_2 -> V_43 == V_43 )
return V_43 ;
}
if ( V_43 < V_18 -> V_20 )
return V_18 -> V_46 [ V_43 ] ;
F_72 () ;
V_2 = F_73 ( & V_18 -> V_19 , V_43 ) ;
F_74 () ;
return V_2 ? V_2 -> V_41 : 0 ;
}
static int F_75 ( struct V_69 * V_70 , void * V_71 )
{
unsigned long V_72 ;
struct V_73 * V_74 ;
struct V_9 * V_18 ;
struct V_75 V_76 ;
void * V_2 , * * V_77 ;
int V_56 ;
F_76 ( V_70 , L_23 ,
L_24 , L_25 , L_26 , L_27 , L_28 ) ;
F_16 ( & V_22 ) ;
F_35 (domain, &irq_domain_list, link) {
struct V_16 * V_17 ;
int V_55 = 0 ;
V_17 = F_26 ( V_18 ) ;
F_77 (slot, &domain->revmap_tree, &iter, 0 )
V_55 ++ ;
F_76 ( V_70 , L_29 ,
V_18 == V_25 ? '*' : ' ' , V_18 -> V_5 ,
V_18 -> V_20 + V_55 , V_18 -> V_20 ,
V_18 -> V_21 ,
V_17 ? F_50 ( V_17 ) : L_30 ) ;
}
F_18 ( & V_22 ) ;
F_76 ( V_70 , L_31 , L_32 , L_33 ,
L_34 , ( int ) ( 2 * sizeof( void * ) + 2 ) , L_35 ,
L_36 , L_37 , L_38 ) ;
for ( V_56 = 1 ; V_56 < V_78 ; V_56 ++ ) {
V_74 = F_78 ( V_56 ) ;
if ( ! V_74 )
continue;
F_79 ( & V_74 -> V_79 , V_72 ) ;
V_18 = V_74 -> V_42 . V_18 ;
if ( V_18 ) {
struct V_80 * V_52 ;
int V_43 = V_74 -> V_42 . V_43 ;
bool V_81 ;
F_76 ( V_70 , L_39 , V_56 ) ;
F_76 ( V_70 , L_40 , V_43 ) ;
V_52 = F_80 ( V_74 ) ;
F_76 ( V_70 , L_41 , ( V_52 && V_52 -> V_5 ) ? V_52 -> V_5 : L_42 ) ;
V_2 = F_81 ( V_74 ) ;
F_76 ( V_70 , V_2 ? L_43 : L_44 , V_2 ) ;
F_76 ( V_70 , L_45 , ( V_74 -> V_82 && V_74 -> V_82 -> V_83 ) ? '*' : ' ' ) ;
V_81 = ( V_56 == V_43 ) && ( V_56 < V_18 -> V_21 ) ;
F_76 ( V_70 , L_46 ,
( V_43 < V_18 -> V_20 ) ? L_47 : L_48 ,
V_81 ? L_49 : L_30 ) ;
F_76 ( V_70 , L_50 , V_74 -> V_42 . V_18 -> V_5 ) ;
}
F_82 ( & V_74 -> V_79 , V_72 ) ;
}
return 0 ;
}
static int F_83 ( struct V_84 * V_84 , struct V_85 * V_85 )
{
return F_84 ( V_85 , F_75 , V_84 -> V_86 ) ;
}
static int T_2 F_85 ( void )
{
if ( F_86 ( L_51 , V_87 , NULL ,
NULL , & V_88 ) == NULL )
return - V_89 ;
return 0 ;
}
int F_87 ( struct V_9 * V_58 , struct V_16 * V_90 ,
const T_3 * V_91 , unsigned int V_92 ,
unsigned long * V_93 , unsigned int * V_94 )
{
if ( F_6 ( V_92 < 1 ) )
return - V_49 ;
* V_93 = V_91 [ 0 ] ;
* V_94 = V_65 ;
return 0 ;
}
int F_88 ( struct V_9 * V_58 , struct V_16 * V_90 ,
const T_3 * V_91 , unsigned int V_92 ,
T_1 * V_93 , unsigned int * V_94 )
{
if ( F_6 ( V_92 < 2 ) )
return - V_49 ;
* V_93 = V_91 [ 0 ] ;
* V_94 = V_91 [ 1 ] & V_67 ;
return 0 ;
}
int F_89 ( struct V_9 * V_58 ,
struct V_16 * V_90 ,
const T_3 * V_91 , unsigned int V_92 ,
unsigned long * V_93 , unsigned int * V_94 )
{
if ( F_6 ( V_92 < 1 ) )
return - V_49 ;
* V_93 = V_91 [ 0 ] ;
if ( V_92 > 1 )
* V_94 = V_91 [ 1 ] & V_67 ;
else
* V_94 = V_65 ;
return 0 ;
}
int F_57 ( int V_48 , unsigned int V_95 , T_1 V_43 ,
int V_96 , const struct V_97 * V_98 )
{
unsigned int V_99 ;
if ( V_48 >= 0 ) {
V_48 = F_90 ( V_48 , V_48 , V_95 , V_96 , V_100 ,
V_98 ) ;
} else {
V_99 = V_43 % V_78 ;
if ( V_99 == 0 )
V_99 ++ ;
V_48 = F_90 ( - 1 , V_99 , V_95 , V_96 , V_100 ,
V_98 ) ;
if ( V_48 <= 0 && V_99 > 1 ) {
V_48 = F_90 ( - 1 , 1 , V_95 , V_96 , V_100 ,
V_98 ) ;
}
}
return V_48 ;
}
struct V_9 * F_91 ( struct V_9 * V_101 ,
unsigned int V_72 ,
unsigned int V_10 ,
struct V_1 * V_7 ,
const struct V_13 * V_14 ,
void * V_15 )
{
struct V_9 * V_18 ;
if ( V_10 )
V_18 = F_92 ( V_7 , V_10 , V_14 , V_15 ) ;
else
V_18 = F_93 ( V_7 , V_14 , V_15 ) ;
if ( V_18 ) {
V_18 -> V_101 = V_101 ;
V_18 -> V_72 |= V_72 ;
}
return V_18 ;
}
static void F_94 ( int V_48 )
{
struct V_42 * V_2 ;
for ( V_2 = F_40 ( V_48 ) ; V_2 ; V_2 = V_2 -> V_102 ) {
struct V_9 * V_18 = V_2 -> V_18 ;
T_1 V_43 = V_2 -> V_43 ;
if ( V_43 < V_18 -> V_20 ) {
V_18 -> V_46 [ V_43 ] = V_48 ;
} else {
F_16 ( & V_47 ) ;
F_48 ( & V_18 -> V_19 , V_43 , V_2 ) ;
F_18 ( & V_47 ) ;
}
if ( ! V_18 -> V_5 && V_2 -> V_52 )
V_18 -> V_5 = V_2 -> V_52 -> V_5 ;
}
F_49 ( V_48 , V_44 ) ;
}
static void F_95 ( int V_48 )
{
struct V_42 * V_2 ;
F_42 ( V_48 , V_44 ) ;
F_43 ( V_48 , NULL , NULL ) ;
F_44 ( V_48 ) ;
F_45 () ;
for ( V_2 = F_40 ( V_48 ) ; V_2 ; V_2 = V_2 -> V_102 ) {
struct V_9 * V_18 = V_2 -> V_18 ;
T_1 V_43 = V_2 -> V_43 ;
if ( V_43 < V_18 -> V_20 ) {
V_18 -> V_46 [ V_43 ] = 0 ;
} else {
F_16 ( & V_47 ) ;
F_46 ( & V_18 -> V_19 , V_43 ) ;
F_18 ( & V_47 ) ;
}
}
}
static struct V_42 * F_96 ( struct V_9 * V_18 ,
struct V_42 * V_103 )
{
struct V_42 * V_42 ;
V_42 = F_11 ( sizeof( * V_42 ) , V_6 ,
F_97 ( V_103 ) ) ;
if ( V_42 ) {
V_103 -> V_102 = V_42 ;
V_42 -> V_41 = V_103 -> V_41 ;
V_42 -> V_104 = V_103 -> V_104 ;
V_42 -> V_18 = V_18 ;
}
return V_42 ;
}
static void F_98 ( unsigned int V_48 , unsigned int V_78 )
{
struct V_42 * V_42 , * V_105 ;
int V_56 ;
for ( V_56 = 0 ; V_56 < V_78 ; V_56 ++ ) {
V_42 = F_40 ( V_48 + V_56 ) ;
V_105 = V_42 -> V_102 ;
V_42 -> V_102 = NULL ;
V_42 -> V_18 = NULL ;
while ( V_105 ) {
V_42 = V_105 ;
V_105 = V_105 -> V_102 ;
F_4 ( V_42 ) ;
}
}
}
static int F_99 ( struct V_9 * V_18 ,
unsigned int V_48 , unsigned int V_78 )
{
struct V_42 * V_42 ;
struct V_9 * V_101 ;
int V_56 ;
for ( V_56 = 0 ; V_56 < V_78 ; V_56 ++ ) {
V_42 = F_40 ( V_48 + V_56 ) ;
V_42 -> V_18 = V_18 ;
for ( V_101 = V_18 -> V_101 ; V_101 ; V_101 = V_101 -> V_101 ) {
V_42 = F_96 ( V_101 , V_42 ) ;
if ( ! V_42 ) {
F_98 ( V_48 , V_56 + 1 ) ;
return - V_89 ;
}
}
}
return 0 ;
}
struct V_42 * F_71 ( struct V_9 * V_18 ,
unsigned int V_48 )
{
struct V_42 * V_42 ;
for ( V_42 = F_40 ( V_48 ) ; V_42 ;
V_42 = V_42 -> V_102 )
if ( V_42 -> V_18 == V_18 )
return V_42 ;
return NULL ;
}
int F_100 ( struct V_9 * V_18 , unsigned int V_48 ,
T_1 V_43 , struct V_80 * V_52 ,
void * V_106 )
{
struct V_42 * V_42 = F_71 ( V_18 , V_48 ) ;
if ( ! V_42 )
return - V_107 ;
V_42 -> V_43 = V_43 ;
V_42 -> V_52 = V_52 ? V_52 : & V_108 ;
V_42 -> V_106 = V_106 ;
return 0 ;
}
void F_101 ( struct V_9 * V_18 , unsigned int V_48 ,
T_1 V_43 , struct V_80 * V_52 ,
void * V_106 , T_4 V_83 ,
void * V_109 , const char * V_110 )
{
F_100 ( V_18 , V_48 , V_43 , V_52 , V_106 ) ;
F_102 ( V_48 , V_83 , 0 , V_110 ) ;
F_103 ( V_48 , V_109 ) ;
}
void F_104 ( struct V_42 * V_42 )
{
V_42 -> V_43 = 0 ;
V_42 -> V_52 = & V_108 ;
V_42 -> V_106 = NULL ;
}
void F_105 ( struct V_9 * V_18 , unsigned int V_48 ,
unsigned int V_78 )
{
struct V_42 * V_42 ;
int V_56 ;
for ( V_56 = 0 ; V_56 < V_78 ; V_56 ++ ) {
V_42 = F_71 ( V_18 , V_48 + V_56 ) ;
if ( V_42 )
F_104 ( V_42 ) ;
}
F_106 ( V_18 , V_48 , V_78 ) ;
}
void F_107 ( struct V_9 * V_18 , unsigned int V_48 ,
unsigned int V_78 )
{
int V_56 ;
for ( V_56 = 0 ; V_56 < V_78 ; V_56 ++ ) {
F_103 ( V_48 + V_56 , NULL ) ;
F_108 ( V_48 + V_56 , NULL ) ;
}
F_105 ( V_18 , V_48 , V_78 ) ;
}
static bool F_109 ( struct V_9 * V_18 )
{
return V_18 -> V_72 & V_111 ;
}
static void F_110 ( struct V_9 * V_18 ,
unsigned int V_53 ,
unsigned int V_78 )
{
V_18 -> V_14 -> free ( V_18 , V_53 , V_78 ) ;
if ( F_109 ( V_18 ) ) {
F_111 ( ! V_18 -> V_101 ) ;
F_110 ( V_18 -> V_101 , V_53 ,
V_78 ) ;
}
}
int F_112 ( struct V_9 * V_18 ,
unsigned int V_53 ,
unsigned int V_78 , void * V_112 )
{
int V_40 = 0 ;
struct V_9 * V_101 = V_18 -> V_101 ;
bool V_113 = F_109 ( V_18 ) ;
F_111 ( V_113 && ! V_101 ) ;
if ( V_113 )
V_40 = F_112 ( V_101 , V_53 ,
V_78 , V_112 ) ;
if ( V_40 < 0 )
return V_40 ;
V_40 = V_18 -> V_14 -> V_114 ( V_18 , V_53 , V_78 , V_112 ) ;
if ( V_40 < 0 && V_113 )
F_110 ( V_101 , V_53 , V_78 ) ;
return V_40 ;
}
int F_113 ( struct V_9 * V_18 , int V_53 ,
unsigned int V_78 , int V_96 , void * V_112 ,
bool realloc , const struct V_97 * V_98 )
{
int V_56 , V_40 , V_48 ;
if ( V_18 == NULL ) {
V_18 = V_25 ;
if ( F_41 ( ! V_18 , L_52 ) )
return - V_49 ;
}
if ( ! V_18 -> V_14 -> V_114 ) {
F_19 ( L_53 ) ;
return - V_115 ;
}
if ( realloc && V_53 >= 0 ) {
V_48 = V_53 ;
} else {
V_48 = F_57 ( V_53 , V_78 , 0 , V_96 ,
V_98 ) ;
if ( V_48 < 0 ) {
F_19 ( L_54 ,
V_53 , V_78 ) ;
return V_48 ;
}
}
if ( F_99 ( V_18 , V_48 , V_78 ) ) {
F_19 ( L_55 , V_48 ) ;
V_40 = - V_89 ;
goto V_116;
}
F_16 ( & V_22 ) ;
V_40 = F_112 ( V_18 , V_48 , V_78 , V_112 ) ;
if ( V_40 < 0 ) {
F_18 ( & V_22 ) ;
goto V_117;
}
for ( V_56 = 0 ; V_56 < V_78 ; V_56 ++ )
F_94 ( V_48 + V_56 ) ;
F_18 ( & V_22 ) ;
return V_48 ;
V_117:
F_98 ( V_48 , V_78 ) ;
V_116:
F_114 ( V_48 , V_78 ) ;
return V_40 ;
}
void F_68 ( unsigned int V_48 , unsigned int V_78 )
{
struct V_42 * V_2 = F_40 ( V_48 ) ;
int V_56 ;
if ( F_41 ( ! V_2 || ! V_2 -> V_18 || ! V_2 -> V_18 -> V_14 -> free ,
L_56 ) )
return;
F_16 ( & V_22 ) ;
for ( V_56 = 0 ; V_56 < V_78 ; V_56 ++ )
F_95 ( V_48 + V_56 ) ;
F_110 ( V_2 -> V_18 , V_48 , V_78 ) ;
F_18 ( & V_22 ) ;
F_98 ( V_48 , V_78 ) ;
F_114 ( V_48 , V_78 ) ;
}
int F_115 ( struct V_9 * V_18 ,
unsigned int V_53 , unsigned int V_78 ,
void * V_112 )
{
if ( F_109 ( V_18 ) )
return 0 ;
V_18 = V_18 -> V_101 ;
if ( V_18 )
return F_112 ( V_18 , V_53 ,
V_78 , V_112 ) ;
return - V_115 ;
}
void F_106 ( struct V_9 * V_18 ,
unsigned int V_53 , unsigned int V_78 )
{
if ( ! F_109 ( V_18 ) && V_18 -> V_101 )
F_110 ( V_18 -> V_101 , V_53 ,
V_78 ) ;
}
static void F_116 ( struct V_42 * V_42 )
{
if ( V_42 && V_42 -> V_18 ) {
struct V_9 * V_18 = V_42 -> V_18 ;
if ( V_42 -> V_102 )
F_116 ( V_42 -> V_102 ) ;
if ( V_18 -> V_14 -> V_118 )
V_18 -> V_14 -> V_118 ( V_18 , V_42 ) ;
}
}
static void F_117 ( struct V_42 * V_42 )
{
if ( V_42 && V_42 -> V_18 ) {
struct V_9 * V_18 = V_42 -> V_18 ;
if ( V_18 -> V_14 -> V_119 )
V_18 -> V_14 -> V_119 ( V_18 , V_42 ) ;
if ( V_42 -> V_102 )
F_117 ( V_42 -> V_102 ) ;
}
}
void F_118 ( struct V_42 * V_42 )
{
if ( ! F_119 ( V_42 ) ) {
F_116 ( V_42 ) ;
F_120 ( V_42 ) ;
}
}
void F_121 ( struct V_42 * V_42 )
{
if ( F_119 ( V_42 ) ) {
F_117 ( V_42 ) ;
F_122 ( V_42 ) ;
}
}
static void F_15 ( struct V_9 * V_18 )
{
if ( V_18 -> V_14 -> V_114 )
V_18 -> V_72 |= V_120 ;
}
bool F_38 ( struct V_9 * V_18 )
{
for (; V_18 ; V_18 = V_18 -> V_101 ) {
if ( F_123 ( V_18 ) )
return true ;
}
return false ;
}
struct V_42 * F_71 ( struct V_9 * V_18 ,
unsigned int V_48 )
{
struct V_42 * V_42 = F_40 ( V_48 ) ;
return ( V_42 && V_42 -> V_18 == V_18 ) ? V_42 : NULL ;
}
void F_101 ( struct V_9 * V_18 , unsigned int V_48 ,
T_1 V_43 , struct V_80 * V_52 ,
void * V_106 , T_4 V_83 ,
void * V_109 , const char * V_110 )
{
F_124 ( V_48 , V_52 , V_83 , V_110 ) ;
F_125 ( V_48 , V_106 ) ;
F_103 ( V_48 , V_109 ) ;
}
static void F_15 ( struct V_9 * V_18 )
{
}
