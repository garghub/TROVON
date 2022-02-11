static inline void F_1 ( struct V_1 * V_2 ) { }
static inline void F_2 ( struct V_1 * V_2 ) { }
struct V_3 * F_3 ( unsigned int type , int V_4 ,
const char * V_5 , void * V_6 )
{
struct V_7 * V_8 ;
char * V_9 ;
V_8 = F_4 ( sizeof( * V_8 ) , V_10 ) ;
switch ( type ) {
case V_11 :
V_9 = F_5 ( V_10 , L_1 , V_5 ) ;
break;
case V_12 :
V_9 = F_5 ( V_10 , L_2 , V_5 , V_4 ) ;
break;
default:
V_9 = F_5 ( V_10 , L_3 , V_6 ) ;
break;
}
if ( ! V_8 || ! V_9 ) {
F_6 ( V_8 ) ;
F_6 ( V_9 ) ;
return NULL ;
}
V_8 -> type = type ;
V_8 -> V_5 = V_9 ;
V_8 -> V_6 = V_6 ;
V_8 -> V_13 . V_14 = & V_15 ;
return & V_8 -> V_13 ;
}
void F_7 ( struct V_3 * V_13 )
{
struct V_7 * V_8 ;
if ( F_8 ( ! F_9 ( V_13 ) ) )
return;
V_8 = F_10 ( V_13 , struct V_7 , V_13 ) ;
F_6 ( V_8 -> V_5 ) ;
F_6 ( V_8 ) ;
}
struct V_1 * F_11 ( struct V_3 * V_13 , int V_16 ,
T_1 V_17 , int V_18 ,
const struct V_19 * V_14 ,
void * V_20 )
{
struct V_21 * V_22 = F_12 ( V_13 ) ;
struct V_7 * V_8 ;
struct V_1 * V_23 ;
static T_2 V_24 ;
V_23 = F_13 ( sizeof( * V_23 ) + (sizeof( unsigned int ) * V_16 ) ,
V_10 , F_14 ( V_22 ) ) ;
if ( F_8 ( ! V_23 ) )
return NULL ;
if ( V_13 && F_9 ( V_13 ) ) {
V_8 = F_10 ( V_13 , struct V_7 , V_13 ) ;
switch ( V_8 -> type ) {
case V_11 :
case V_12 :
V_23 -> V_5 = F_15 ( V_8 -> V_5 , V_10 ) ;
if ( ! V_23 -> V_5 ) {
F_6 ( V_23 ) ;
return NULL ;
}
V_23 -> V_25 |= V_26 ;
break;
default:
V_23 -> V_13 = V_13 ;
V_23 -> V_5 = V_8 -> V_5 ;
break;
}
#ifdef F_16
} else if ( F_17 ( V_13 ) ) {
struct V_27 V_28 = {
. V_29 = V_30 ,
} ;
T_3 V_31 ;
V_31 = F_18 ( F_19 ( V_13 ) ) ;
if ( F_20 ( V_31 , V_32 , & V_28 ) == V_33 ) {
V_23 -> V_5 = V_28 . V_34 ;
V_23 -> V_25 |= V_26 ;
}
V_23 -> V_13 = V_13 ;
#endif
} else if ( V_22 ) {
char * V_5 ;
V_5 = F_15 ( F_21 ( V_22 ) , V_10 ) ;
if ( ! V_5 ) {
F_6 ( V_23 ) ;
return NULL ;
}
F_22 ( V_5 , '/' , ':' ) ;
V_23 -> V_5 = V_5 ;
V_23 -> V_13 = V_13 ;
V_23 -> V_25 |= V_26 ;
}
if ( ! V_23 -> V_5 ) {
if ( V_13 )
F_23 ( L_4 ) ;
V_23 -> V_5 = F_5 ( V_10 , L_5 ,
F_24 ( & V_24 ) ) ;
if ( ! V_23 -> V_5 ) {
F_6 ( V_23 ) ;
return NULL ;
}
V_23 -> V_25 |= V_26 ;
}
F_25 ( V_22 ) ;
F_26 ( & V_23 -> V_35 , V_10 ) ;
V_23 -> V_14 = V_14 ;
V_23 -> V_20 = V_20 ;
V_23 -> V_17 = V_17 ;
V_23 -> V_36 = V_16 ;
V_23 -> V_37 = V_18 ;
F_27 ( V_23 ) ;
F_28 ( & V_38 ) ;
F_1 ( V_23 ) ;
F_29 ( & V_23 -> V_39 , & V_40 ) ;
F_30 ( & V_38 ) ;
F_31 ( L_6 , V_23 -> V_5 ) ;
return V_23 ;
}
void F_32 ( struct V_1 * V_23 )
{
F_28 ( & V_38 ) ;
F_2 ( V_23 ) ;
F_8 ( ! F_33 ( & V_23 -> V_35 ) ) ;
F_34 ( & V_23 -> V_39 ) ;
if ( F_35 ( V_41 == V_23 ) )
F_36 ( NULL ) ;
F_30 ( & V_38 ) ;
F_31 ( L_7 , V_23 -> V_5 ) ;
F_37 ( F_38 ( V_23 ) ) ;
if ( V_23 -> V_25 & V_26 )
F_6 ( V_23 -> V_5 ) ;
F_6 ( V_23 ) ;
}
void F_39 ( struct V_1 * V_23 ,
enum V_42 V_43 )
{
char * V_5 ;
if ( V_23 -> V_43 == V_43 )
return;
F_28 ( & V_38 ) ;
V_23 -> V_43 = V_43 ;
V_5 = F_5 ( V_10 , L_2 , V_23 -> V_5 , V_43 ) ;
if ( ! V_5 ) {
F_30 ( & V_38 ) ;
return;
}
F_2 ( V_23 ) ;
if ( V_23 -> V_25 & V_26 )
F_6 ( V_23 -> V_5 ) ;
else
V_23 -> V_25 |= V_26 ;
V_23 -> V_5 = V_5 ;
F_1 ( V_23 ) ;
F_30 ( & V_38 ) ;
}
struct V_1 * F_40 ( struct V_21 * V_22 ,
unsigned int V_16 ,
unsigned int V_44 ,
const struct V_19 * V_14 ,
void * V_20 )
{
struct V_1 * V_23 ;
V_23 = F_11 ( F_41 ( V_22 ) , V_16 , V_16 , 0 , V_14 , V_20 ) ;
if ( ! V_23 )
return NULL ;
if ( V_44 > 0 ) {
if ( F_42 ( V_45 ) ) {
int V_46 = F_43 ( V_44 , V_44 , V_16 ,
F_14 ( V_22 ) ) ;
if ( V_46 < 0 )
F_44 ( L_8 ,
V_44 ) ;
}
F_45 ( V_23 , V_44 , 0 , V_16 ) ;
}
return V_23 ;
}
struct V_1 * F_46 ( struct V_21 * V_22 ,
unsigned int V_16 ,
unsigned int V_44 ,
T_1 V_47 ,
const struct V_19 * V_14 ,
void * V_20 )
{
struct V_1 * V_23 ;
V_23 = F_11 ( F_41 ( V_22 ) , V_47 + V_16 ,
V_47 + V_16 , 0 , V_14 , V_20 ) ;
if ( V_23 )
F_45 ( V_23 , V_44 , V_47 , V_16 ) ;
return V_23 ;
}
struct V_1 * F_47 ( struct V_48 * V_49 ,
enum V_42 V_43 )
{
struct V_1 * V_50 , * V_51 = NULL ;
struct V_3 * V_13 = V_49 -> V_13 ;
int V_46 ;
F_28 ( & V_38 ) ;
F_48 (h, &irq_domain_list, link) {
if ( V_50 -> V_14 -> V_52 && V_49 -> V_53 )
V_46 = V_50 -> V_14 -> V_52 ( V_50 , V_49 , V_43 ) ;
else if ( V_50 -> V_14 -> V_54 )
V_46 = V_50 -> V_14 -> V_54 ( V_50 , F_12 ( V_13 ) , V_43 ) ;
else
V_46 = ( ( V_13 != NULL ) && ( V_50 -> V_13 == V_13 ) &&
( ( V_43 == V_55 ) ||
( V_50 -> V_43 == V_43 ) ) ) ;
if ( V_46 ) {
V_51 = V_50 ;
break;
}
}
F_30 ( & V_38 ) ;
return V_51 ;
}
bool F_49 ( void )
{
struct V_1 * V_50 ;
bool V_56 = true ;
F_28 ( & V_38 ) ;
F_48 (h, &irq_domain_list, link) {
if ( F_50 ( V_50 ) &&
! F_51 ( V_50 ) ) {
V_56 = false ;
break;
}
}
F_30 ( & V_38 ) ;
return V_56 ;
}
void F_36 ( struct V_1 * V_23 )
{
F_31 ( L_9 , V_23 ) ;
V_41 = V_23 ;
}
static void F_52 ( struct V_1 * V_23 ,
T_1 V_57 )
{
if ( V_57 < V_23 -> V_36 ) {
V_23 -> V_58 [ V_57 ] = 0 ;
} else {
F_28 ( & V_59 ) ;
F_53 ( & V_23 -> V_35 , V_57 ) ;
F_30 ( & V_59 ) ;
}
}
static void F_54 ( struct V_1 * V_23 ,
T_1 V_57 ,
struct V_60 * V_60 )
{
if ( V_57 < V_23 -> V_36 ) {
V_23 -> V_58 [ V_57 ] = V_60 -> V_61 ;
} else {
F_28 ( & V_59 ) ;
F_55 ( & V_23 -> V_35 , V_57 , V_60 ) ;
F_30 ( & V_59 ) ;
}
}
void F_56 ( struct V_1 * V_23 , unsigned int V_61 )
{
struct V_60 * V_60 = F_57 ( V_61 ) ;
T_1 V_57 ;
if ( F_58 ( ! V_60 || V_60 -> V_23 != V_23 ,
L_10 , V_61 ) )
return;
V_57 = V_60 -> V_57 ;
F_59 ( V_61 , V_62 ) ;
F_60 ( V_61 , NULL , NULL ) ;
F_61 ( V_61 ) ;
if ( V_23 -> V_14 -> V_63 )
V_23 -> V_14 -> V_63 ( V_23 , V_61 ) ;
F_62 () ;
V_60 -> V_23 = NULL ;
V_60 -> V_57 = 0 ;
V_23 -> V_64 -- ;
F_52 ( V_23 , V_57 ) ;
}
int F_63 ( struct V_1 * V_23 , unsigned int V_65 ,
T_1 V_57 )
{
struct V_60 * V_60 = F_57 ( V_65 ) ;
int V_56 ;
if ( F_58 ( V_57 >= V_23 -> V_17 ,
L_11 , ( int ) V_57 , V_23 -> V_5 ) )
return - V_66 ;
if ( F_58 ( ! V_60 , L_12 , V_65 ) )
return - V_66 ;
if ( F_58 ( V_60 -> V_23 , L_13 , V_65 ) )
return - V_66 ;
F_28 ( & V_38 ) ;
V_60 -> V_57 = V_57 ;
V_60 -> V_23 = V_23 ;
if ( V_23 -> V_14 -> V_67 ) {
V_56 = V_23 -> V_14 -> V_67 ( V_23 , V_65 , V_57 ) ;
if ( V_56 != 0 ) {
if ( V_56 != - V_68 ) {
F_44 ( L_14 ,
V_23 -> V_5 , V_57 , V_65 , V_56 ) ;
}
V_60 -> V_23 = NULL ;
V_60 -> V_57 = 0 ;
F_30 ( & V_38 ) ;
return V_56 ;
}
if ( ! V_23 -> V_5 && V_60 -> V_69 )
V_23 -> V_5 = V_60 -> V_69 -> V_5 ;
}
V_23 -> V_64 ++ ;
F_54 ( V_23 , V_57 , V_60 ) ;
F_30 ( & V_38 ) ;
F_64 ( V_65 , V_62 ) ;
return 0 ;
}
void F_45 ( struct V_1 * V_23 , unsigned int V_70 ,
T_1 V_71 , int V_72 )
{
struct V_21 * V_22 ;
int V_73 ;
V_22 = F_38 ( V_23 ) ;
F_31 ( L_15 , V_74 ,
F_21 ( V_22 ) , V_70 , ( int ) V_71 , V_72 ) ;
for ( V_73 = 0 ; V_73 < V_72 ; V_73 ++ ) {
F_63 ( V_23 , V_70 + V_73 , V_71 + V_73 ) ;
}
}
unsigned int F_65 ( struct V_1 * V_23 )
{
struct V_21 * V_22 ;
unsigned int V_65 ;
if ( V_23 == NULL )
V_23 = V_41 ;
V_22 = F_38 ( V_23 ) ;
V_65 = F_66 ( 1 , F_14 ( V_22 ) ) ;
if ( ! V_65 ) {
F_31 ( L_16 ) ;
return 0 ;
}
if ( V_65 >= V_23 -> V_37 ) {
F_23 ( L_17 ,
V_23 -> V_37 ) ;
F_67 ( V_65 ) ;
return 0 ;
}
F_31 ( L_18 , V_65 ) ;
if ( F_63 ( V_23 , V_65 , V_65 ) ) {
F_67 ( V_65 ) ;
return 0 ;
}
return V_65 ;
}
unsigned int F_68 ( struct V_1 * V_23 ,
T_1 V_57 )
{
struct V_21 * V_22 ;
int V_65 ;
F_31 ( L_19 , V_23 , V_57 ) ;
if ( V_23 == NULL )
V_23 = V_41 ;
if ( V_23 == NULL ) {
F_58 ( 1 , L_20 , V_74 , V_57 ) ;
return 0 ;
}
F_31 ( L_21 , V_23 ) ;
V_22 = F_38 ( V_23 ) ;
V_65 = F_69 ( V_23 , V_57 ) ;
if ( V_65 ) {
F_31 ( L_22 , V_65 ) ;
return V_65 ;
}
V_65 = F_70 ( - 1 , 1 , V_57 , F_14 ( V_22 ) , NULL ) ;
if ( V_65 <= 0 ) {
F_31 ( L_23 ) ;
return 0 ;
}
if ( F_63 ( V_23 , V_65 , V_57 ) ) {
F_67 ( V_65 ) ;
return 0 ;
}
F_31 ( L_24 ,
V_57 , F_21 ( V_22 ) , V_65 ) ;
return V_65 ;
}
int F_71 ( struct V_1 * V_23 , unsigned int V_70 ,
T_1 V_71 , int V_72 )
{
struct V_21 * V_22 ;
int V_56 ;
V_22 = F_38 ( V_23 ) ;
V_56 = F_43 ( V_70 , V_70 , V_72 ,
F_14 ( V_22 ) ) ;
if ( F_35 ( V_56 < 0 ) )
return V_56 ;
F_45 ( V_23 , V_70 , V_71 , V_72 ) ;
return 0 ;
}
static int F_72 ( struct V_1 * V_2 ,
struct V_48 * V_49 ,
T_1 * V_57 , unsigned int * type )
{
#ifdef F_73
if ( V_2 -> V_14 -> V_75 )
return V_2 -> V_14 -> V_75 ( V_2 , V_49 , V_57 , type ) ;
#endif
if ( V_2 -> V_14 -> V_76 )
return V_2 -> V_14 -> V_76 ( V_2 , F_12 ( V_49 -> V_13 ) ,
V_49 -> V_77 , V_49 -> V_53 ,
V_57 , type ) ;
* V_57 = V_49 -> V_77 [ 0 ] ;
return 0 ;
}
static void F_74 ( struct V_78 * V_60 ,
struct V_48 * V_49 )
{
int V_73 ;
V_49 -> V_13 = V_60 -> V_79 ? & V_60 -> V_79 -> V_13 : NULL ;
V_49 -> V_53 = V_60 -> V_80 ;
for ( V_73 = 0 ; V_73 < V_60 -> V_80 ; V_73 ++ )
V_49 -> V_77 [ V_73 ] = V_60 -> args [ V_73 ] ;
}
unsigned int F_75 ( struct V_48 * V_49 )
{
struct V_1 * V_23 ;
struct V_60 * V_60 ;
T_1 V_57 ;
unsigned int type = V_81 ;
int V_65 ;
if ( V_49 -> V_13 ) {
V_23 = F_47 ( V_49 , V_82 ) ;
if ( ! V_23 )
V_23 = F_47 ( V_49 , V_55 ) ;
} else {
V_23 = V_41 ;
}
if ( ! V_23 ) {
F_76 ( L_25 ,
F_21 ( F_12 ( V_49 -> V_13 ) ) ) ;
return 0 ;
}
if ( F_72 ( V_23 , V_49 , & V_57 , & type ) )
return 0 ;
if ( F_8 ( type & ~ V_83 ) )
type &= V_83 ;
V_65 = F_69 ( V_23 , V_57 ) ;
if ( V_65 ) {
if ( type == V_81 || type == F_77 ( V_65 ) )
return V_65 ;
if ( F_77 ( V_65 ) == V_81 ) {
V_60 = F_57 ( V_65 ) ;
if ( ! V_60 )
return 0 ;
F_78 ( V_60 , type ) ;
return V_65 ;
}
F_76 ( L_26 ,
V_57 , F_21 ( F_12 ( V_49 -> V_13 ) ) ) ;
return 0 ;
}
if ( F_79 ( V_23 ) ) {
V_65 = F_80 ( V_23 , 1 , V_84 , V_49 ) ;
if ( V_65 <= 0 )
return 0 ;
} else {
V_65 = F_68 ( V_23 , V_57 ) ;
if ( ! V_65 )
return V_65 ;
}
V_60 = F_57 ( V_65 ) ;
if ( ! V_60 ) {
if ( F_79 ( V_23 ) )
F_81 ( V_65 , 1 ) ;
else
F_82 ( V_65 ) ;
return 0 ;
}
F_78 ( V_60 , type ) ;
return V_65 ;
}
unsigned int F_83 ( struct V_78 * V_60 )
{
struct V_48 V_49 ;
F_74 ( V_60 , & V_49 ) ;
return F_75 ( & V_49 ) ;
}
void F_82 ( unsigned int V_65 )
{
struct V_60 * V_60 = F_57 ( V_65 ) ;
struct V_1 * V_23 ;
if ( ! V_65 || ! V_60 )
return;
V_23 = V_60 -> V_23 ;
if ( F_8 ( V_23 == NULL ) )
return;
if ( F_79 ( V_23 ) ) {
F_81 ( V_65 , 1 ) ;
} else {
F_56 ( V_23 , V_65 ) ;
F_67 ( V_65 ) ;
}
}
unsigned int F_69 ( struct V_1 * V_23 ,
T_1 V_57 )
{
struct V_60 * V_6 ;
if ( V_23 == NULL )
V_23 = V_41 ;
if ( V_23 == NULL )
return 0 ;
if ( V_57 < V_23 -> V_37 ) {
V_6 = F_84 ( V_23 , V_57 ) ;
if ( V_6 && V_6 -> V_57 == V_57 )
return V_57 ;
}
if ( V_57 < V_23 -> V_36 )
return V_23 -> V_58 [ V_57 ] ;
F_85 () ;
V_6 = F_86 ( & V_23 -> V_35 , V_57 ) ;
F_87 () ;
return V_6 ? V_6 -> V_61 : 0 ;
}
static void F_88 ( struct V_85 * V_86 , struct V_87 * V_88 )
{
struct V_1 * V_23 ;
struct V_60 * V_6 ;
V_23 = V_88 -> V_60 . V_23 ;
V_6 = & V_88 -> V_60 ;
while ( V_23 ) {
unsigned int V_61 = V_6 -> V_61 ;
unsigned long V_57 = V_6 -> V_57 ;
struct V_89 * V_69 ;
bool V_90 ;
if ( V_6 == & V_88 -> V_60 )
F_89 ( V_86 , L_27 , V_61 ) ;
else
F_89 ( V_86 , L_28 , V_61 ) ;
F_89 ( V_86 , L_29 , V_57 ) ;
V_69 = F_90 ( V_6 ) ;
F_89 ( V_86 , L_30 , ( V_69 && V_69 -> V_5 ) ? V_69 -> V_5 : L_31 ) ;
F_89 ( V_86 , V_6 ? L_32 : L_33 ,
F_91 ( V_6 ) ) ;
F_89 ( V_86 , L_34 , ( V_88 -> V_91 && V_88 -> V_91 -> V_92 ) ? '*' : ' ' ) ;
V_90 = ( V_61 == V_57 ) && ( V_61 < V_23 -> V_37 ) ;
F_89 ( V_86 , L_35 ,
( V_57 < V_23 -> V_36 ) ? L_36 : L_37 ,
V_90 ? L_38 : L_39 ) ;
F_89 ( V_86 , L_40 , V_23 -> V_5 ) ;
#ifdef F_73
V_23 = V_23 -> V_93 ;
V_6 = V_6 -> V_94 ;
#else
V_23 = NULL ;
#endif
}
}
static int F_92 ( struct V_85 * V_86 , void * V_95 )
{
unsigned long V_25 ;
struct V_87 * V_88 ;
struct V_1 * V_23 ;
struct V_96 V_97 ;
void T_4 * * V_98 ;
int V_73 ;
F_89 ( V_86 , L_41 ,
L_42 , L_43 , L_44 , L_45 , L_46 ) ;
F_28 ( & V_38 ) ;
F_48 (domain, &irq_domain_list, link) {
struct V_21 * V_22 ;
const char * V_5 ;
int V_72 = 0 ;
V_22 = F_38 ( V_23 ) ;
if ( V_22 )
V_5 = F_21 ( V_22 ) ;
else if ( F_9 ( V_23 -> V_13 ) )
V_5 = F_10 ( V_23 -> V_13 , struct V_7 ,
V_13 ) -> V_5 ;
else
V_5 = L_39 ;
F_93 (slot, &domain->revmap_tree, &iter, 0 )
V_72 ++ ;
F_89 ( V_86 , L_47 ,
V_23 == V_41 ? '*' : ' ' , V_23 -> V_5 ,
V_23 -> V_36 + V_72 , V_23 -> V_36 ,
V_23 -> V_37 ,
V_5 ) ;
}
F_30 ( & V_38 ) ;
F_89 ( V_86 , L_48 , L_49 , L_50 ,
L_51 , ( int ) ( 2 * sizeof( void * ) + 2 ) , L_52 ,
L_53 , L_54 , L_55 ) ;
for ( V_73 = 1 ; V_73 < V_99 ; V_73 ++ ) {
V_88 = F_94 ( V_73 ) ;
if ( ! V_88 )
continue;
F_95 ( & V_88 -> V_100 , V_25 ) ;
F_88 ( V_86 , V_88 ) ;
F_96 ( & V_88 -> V_100 , V_25 ) ;
}
return 0 ;
}
static int F_97 ( struct V_101 * V_101 , struct V_102 * V_102 )
{
return F_98 ( V_102 , F_92 , V_101 -> V_103 ) ;
}
static int T_5 F_99 ( void )
{
if ( F_100 ( L_56 , V_104 , NULL ,
NULL , & V_105 ) == NULL )
return - V_106 ;
return 0 ;
}
int F_101 ( struct V_1 * V_2 , struct V_21 * V_107 ,
const T_6 * V_108 , unsigned int V_109 ,
unsigned long * V_110 , unsigned int * V_111 )
{
if ( F_8 ( V_109 < 1 ) )
return - V_66 ;
* V_110 = V_108 [ 0 ] ;
* V_111 = V_81 ;
return 0 ;
}
int F_102 ( struct V_1 * V_2 , struct V_21 * V_107 ,
const T_6 * V_108 , unsigned int V_109 ,
T_1 * V_110 , unsigned int * V_111 )
{
if ( F_8 ( V_109 < 2 ) )
return - V_66 ;
* V_110 = V_108 [ 0 ] ;
* V_111 = V_108 [ 1 ] & V_83 ;
return 0 ;
}
int F_103 ( struct V_1 * V_2 ,
struct V_21 * V_107 ,
const T_6 * V_108 , unsigned int V_109 ,
unsigned long * V_110 , unsigned int * V_111 )
{
if ( F_8 ( V_109 < 1 ) )
return - V_66 ;
* V_110 = V_108 [ 0 ] ;
if ( V_109 > 1 )
* V_111 = V_108 [ 1 ] & V_83 ;
else
* V_111 = V_81 ;
return 0 ;
}
int F_70 ( int V_65 , unsigned int V_112 , T_1 V_57 ,
int V_113 , const struct V_114 * V_115 )
{
unsigned int V_116 ;
if ( V_65 >= 0 ) {
V_65 = F_104 ( V_65 , V_65 , V_112 , V_113 , V_117 ,
V_115 ) ;
} else {
V_116 = V_57 % V_99 ;
if ( V_116 == 0 )
V_116 ++ ;
V_65 = F_104 ( - 1 , V_116 , V_112 , V_113 , V_117 ,
V_115 ) ;
if ( V_65 <= 0 && V_116 > 1 ) {
V_65 = F_104 ( - 1 , 1 , V_112 , V_113 , V_117 ,
V_115 ) ;
}
}
return V_65 ;
}
struct V_1 * F_105 ( struct V_1 * V_93 ,
unsigned int V_25 ,
unsigned int V_16 ,
struct V_3 * V_13 ,
const struct V_19 * V_14 ,
void * V_20 )
{
struct V_1 * V_23 ;
if ( V_16 )
V_23 = F_106 ( V_13 , V_16 , V_14 , V_20 ) ;
else
V_23 = F_107 ( V_13 , V_14 , V_20 ) ;
if ( V_23 ) {
V_23 -> V_93 = V_93 ;
V_23 -> V_25 |= V_25 ;
}
return V_23 ;
}
static void F_108 ( int V_65 )
{
struct V_60 * V_6 ;
for ( V_6 = F_57 ( V_65 ) ; V_6 ; V_6 = V_6 -> V_94 ) {
struct V_1 * V_23 = V_6 -> V_23 ;
V_23 -> V_64 ++ ;
F_54 ( V_23 , V_6 -> V_57 , V_6 ) ;
if ( ! V_23 -> V_5 && V_6 -> V_69 )
V_23 -> V_5 = V_6 -> V_69 -> V_5 ;
}
F_64 ( V_65 , V_62 ) ;
}
static void F_109 ( int V_65 )
{
struct V_60 * V_6 ;
F_59 ( V_65 , V_62 ) ;
F_60 ( V_65 , NULL , NULL ) ;
F_61 ( V_65 ) ;
F_62 () ;
for ( V_6 = F_57 ( V_65 ) ; V_6 ; V_6 = V_6 -> V_94 ) {
struct V_1 * V_23 = V_6 -> V_23 ;
T_1 V_57 = V_6 -> V_57 ;
V_23 -> V_64 -- ;
F_52 ( V_23 , V_57 ) ;
}
}
static struct V_60 * F_110 ( struct V_1 * V_23 ,
struct V_60 * V_118 )
{
struct V_60 * V_60 ;
V_60 = F_13 ( sizeof( * V_60 ) , V_10 ,
F_111 ( V_118 ) ) ;
if ( V_60 ) {
V_118 -> V_94 = V_60 ;
V_60 -> V_61 = V_118 -> V_61 ;
V_60 -> V_119 = V_118 -> V_119 ;
V_60 -> V_23 = V_23 ;
}
return V_60 ;
}
static void F_112 ( unsigned int V_65 , unsigned int V_99 )
{
struct V_60 * V_60 , * V_120 ;
int V_73 ;
for ( V_73 = 0 ; V_73 < V_99 ; V_73 ++ ) {
V_60 = F_57 ( V_65 + V_73 ) ;
V_120 = V_60 -> V_94 ;
V_60 -> V_94 = NULL ;
V_60 -> V_23 = NULL ;
while ( V_120 ) {
V_60 = V_120 ;
V_120 = V_120 -> V_94 ;
F_6 ( V_60 ) ;
}
}
}
static int F_113 ( struct V_1 * V_23 ,
unsigned int V_65 , unsigned int V_99 )
{
struct V_60 * V_60 ;
struct V_1 * V_93 ;
int V_73 ;
for ( V_73 = 0 ; V_73 < V_99 ; V_73 ++ ) {
V_60 = F_57 ( V_65 + V_73 ) ;
V_60 -> V_23 = V_23 ;
for ( V_93 = V_23 -> V_93 ; V_93 ; V_93 = V_93 -> V_93 ) {
V_60 = F_110 ( V_93 , V_60 ) ;
if ( ! V_60 ) {
F_112 ( V_65 , V_73 + 1 ) ;
return - V_106 ;
}
}
}
return 0 ;
}
struct V_60 * F_84 ( struct V_1 * V_23 ,
unsigned int V_65 )
{
struct V_60 * V_60 ;
for ( V_60 = F_57 ( V_65 ) ; V_60 ;
V_60 = V_60 -> V_94 )
if ( V_60 -> V_23 == V_23 )
return V_60 ;
return NULL ;
}
int F_114 ( struct V_1 * V_23 , unsigned int V_65 ,
T_1 V_57 , struct V_89 * V_69 ,
void * V_121 )
{
struct V_60 * V_60 = F_84 ( V_23 , V_65 ) ;
if ( ! V_60 )
return - V_122 ;
V_60 -> V_57 = V_57 ;
V_60 -> V_69 = V_69 ? V_69 : & V_123 ;
V_60 -> V_121 = V_121 ;
return 0 ;
}
void F_115 ( struct V_1 * V_23 , unsigned int V_65 ,
T_1 V_57 , struct V_89 * V_69 ,
void * V_121 , T_7 V_92 ,
void * V_124 , const char * V_125 )
{
F_114 ( V_23 , V_65 , V_57 , V_69 , V_121 ) ;
F_116 ( V_65 , V_92 , 0 , V_125 ) ;
F_117 ( V_65 , V_124 ) ;
}
void F_118 ( struct V_60 * V_60 )
{
V_60 -> V_57 = 0 ;
V_60 -> V_69 = & V_123 ;
V_60 -> V_121 = NULL ;
}
void F_119 ( struct V_1 * V_23 , unsigned int V_65 ,
unsigned int V_99 )
{
struct V_60 * V_60 ;
int V_73 ;
for ( V_73 = 0 ; V_73 < V_99 ; V_73 ++ ) {
V_60 = F_84 ( V_23 , V_65 + V_73 ) ;
if ( V_60 )
F_118 ( V_60 ) ;
}
F_120 ( V_23 , V_65 , V_99 ) ;
}
void F_121 ( struct V_1 * V_23 , unsigned int V_65 ,
unsigned int V_99 )
{
int V_73 ;
for ( V_73 = 0 ; V_73 < V_99 ; V_73 ++ ) {
F_117 ( V_65 + V_73 , NULL ) ;
F_122 ( V_65 + V_73 , NULL ) ;
}
F_119 ( V_23 , V_65 , V_99 ) ;
}
static void F_123 ( struct V_1 * V_23 ,
unsigned int V_70 ,
unsigned int V_99 )
{
if ( V_23 -> V_14 -> free )
V_23 -> V_14 -> free ( V_23 , V_70 , V_99 ) ;
}
int F_124 ( struct V_1 * V_23 ,
unsigned int V_70 ,
unsigned int V_99 , void * V_126 )
{
return V_23 -> V_14 -> V_127 ( V_23 , V_70 , V_99 , V_126 ) ;
}
int F_125 ( struct V_1 * V_23 , int V_70 ,
unsigned int V_99 , int V_113 , void * V_126 ,
bool realloc , const struct V_114 * V_115 )
{
int V_73 , V_56 , V_65 ;
if ( V_23 == NULL ) {
V_23 = V_41 ;
if ( F_58 ( ! V_23 , L_57 ) )
return - V_66 ;
}
if ( ! V_23 -> V_14 -> V_127 ) {
F_31 ( L_58 ) ;
return - V_128 ;
}
if ( realloc && V_70 >= 0 ) {
V_65 = V_70 ;
} else {
V_65 = F_70 ( V_70 , V_99 , 0 , V_113 ,
V_115 ) ;
if ( V_65 < 0 ) {
F_31 ( L_59 ,
V_70 , V_99 ) ;
return V_65 ;
}
}
if ( F_113 ( V_23 , V_65 , V_99 ) ) {
F_31 ( L_60 , V_65 ) ;
V_56 = - V_106 ;
goto V_129;
}
F_28 ( & V_38 ) ;
V_56 = F_124 ( V_23 , V_65 , V_99 , V_126 ) ;
if ( V_56 < 0 ) {
F_30 ( & V_38 ) ;
goto V_130;
}
for ( V_73 = 0 ; V_73 < V_99 ; V_73 ++ )
F_108 ( V_65 + V_73 ) ;
F_30 ( & V_38 ) ;
return V_65 ;
V_130:
F_112 ( V_65 , V_99 ) ;
V_129:
F_126 ( V_65 , V_99 ) ;
return V_56 ;
}
static void F_127 ( struct V_60 * V_2 )
{
void T_4 * * V_98 ;
if ( V_2 -> V_57 < V_2 -> V_23 -> V_36 )
return;
F_28 ( & V_59 ) ;
V_98 = F_128 ( & V_2 -> V_23 -> V_35 , V_2 -> V_57 ) ;
if ( V_98 )
F_129 ( & V_2 -> V_23 -> V_35 , V_98 , V_2 ) ;
F_30 ( & V_59 ) ;
}
int F_130 ( struct V_1 * V_23 , int V_65 , void * V_126 )
{
struct V_60 * V_131 ;
struct V_60 * V_132 = F_57 ( V_65 ) ;
struct V_87 * V_88 ;
int V_133 = 0 ;
V_88 = F_94 ( V_65 ) ;
if ( ! V_88 )
return - V_66 ;
if ( F_8 ( V_88 -> V_91 ) )
return - V_134 ;
if ( V_23 == NULL )
return - V_66 ;
if ( F_8 ( ! F_79 ( V_23 ) ) )
return - V_66 ;
if ( ! V_132 )
return - V_66 ;
if ( V_23 -> V_93 != V_132 -> V_23 )
return - V_66 ;
V_131 = F_13 ( sizeof( * V_131 ) , V_10 ,
F_111 ( V_132 ) ) ;
if ( ! V_131 )
return - V_106 ;
F_28 ( & V_38 ) ;
* V_131 = * V_132 ;
V_132 -> V_94 = V_131 ;
V_132 -> V_23 = V_23 ;
V_132 -> V_135 = 0 ;
V_132 -> V_57 = 0 ;
V_132 -> V_69 = NULL ;
V_132 -> V_121 = NULL ;
V_133 = F_124 ( V_23 , V_65 , 1 , V_126 ) ;
if ( V_133 ) {
* V_132 = * V_131 ;
goto error;
}
F_127 ( V_131 ) ;
F_54 ( V_23 , V_132 -> V_57 , V_132 ) ;
error:
F_30 ( & V_38 ) ;
return V_133 ;
}
int F_131 ( struct V_1 * V_23 , int V_65 )
{
struct V_60 * V_132 = F_57 ( V_65 ) ;
struct V_60 * V_131 ;
struct V_60 * V_136 ;
struct V_87 * V_88 ;
V_88 = F_94 ( V_65 ) ;
if ( ! V_88 )
return - V_66 ;
if ( F_8 ( V_88 -> V_91 ) )
return - V_134 ;
if ( V_23 == NULL )
return - V_66 ;
if ( ! V_132 )
return - V_66 ;
V_136 = F_84 ( V_23 , V_65 ) ;
if ( F_8 ( V_132 != V_136 ) )
return - V_66 ;
if ( F_8 ( V_132 -> V_23 != V_23 ) )
return - V_66 ;
V_131 = V_132 -> V_94 ;
if ( F_8 ( ! V_131 ) )
return - V_66 ;
F_28 ( & V_38 ) ;
V_132 -> V_94 = NULL ;
F_52 ( V_23 , V_132 -> V_57 ) ;
F_123 ( V_23 , V_65 , 1 ) ;
* V_132 = * V_131 ;
F_127 ( V_132 ) ;
F_30 ( & V_38 ) ;
F_6 ( V_131 ) ;
return 0 ;
}
void F_81 ( unsigned int V_65 , unsigned int V_99 )
{
struct V_60 * V_6 = F_57 ( V_65 ) ;
int V_73 ;
if ( F_58 ( ! V_6 || ! V_6 -> V_23 || ! V_6 -> V_23 -> V_14 -> free ,
L_61 ) )
return;
F_28 ( & V_38 ) ;
for ( V_73 = 0 ; V_73 < V_99 ; V_73 ++ )
F_109 ( V_65 + V_73 ) ;
F_123 ( V_6 -> V_23 , V_65 , V_99 ) ;
F_30 ( & V_38 ) ;
F_112 ( V_65 , V_99 ) ;
F_126 ( V_65 , V_99 ) ;
}
int F_132 ( struct V_1 * V_23 ,
unsigned int V_70 , unsigned int V_99 ,
void * V_126 )
{
if ( ! V_23 -> V_93 )
return - V_128 ;
return F_124 ( V_23 -> V_93 , V_70 ,
V_99 , V_126 ) ;
}
void F_120 ( struct V_1 * V_23 ,
unsigned int V_70 , unsigned int V_99 )
{
if ( ! V_23 -> V_93 )
return;
F_123 ( V_23 -> V_93 , V_70 , V_99 ) ;
}
static void F_133 ( struct V_60 * V_60 )
{
if ( V_60 && V_60 -> V_23 ) {
struct V_1 * V_23 = V_60 -> V_23 ;
if ( V_60 -> V_94 )
F_133 ( V_60 -> V_94 ) ;
if ( V_23 -> V_14 -> V_137 )
V_23 -> V_14 -> V_137 ( V_23 , V_60 ) ;
}
}
static void F_134 ( struct V_60 * V_60 )
{
if ( V_60 && V_60 -> V_23 ) {
struct V_1 * V_23 = V_60 -> V_23 ;
if ( V_23 -> V_14 -> V_138 )
V_23 -> V_14 -> V_138 ( V_23 , V_60 ) ;
if ( V_60 -> V_94 )
F_134 ( V_60 -> V_94 ) ;
}
}
void F_135 ( struct V_60 * V_60 )
{
if ( ! F_136 ( V_60 ) ) {
F_133 ( V_60 ) ;
F_137 ( V_60 ) ;
}
}
void F_138 ( struct V_60 * V_60 )
{
if ( F_136 ( V_60 ) ) {
F_134 ( V_60 ) ;
F_139 ( V_60 ) ;
}
}
static void F_27 ( struct V_1 * V_23 )
{
if ( V_23 -> V_14 -> V_127 )
V_23 -> V_25 |= V_139 ;
}
bool F_51 ( struct V_1 * V_23 )
{
for (; V_23 ; V_23 = V_23 -> V_93 ) {
if ( F_140 ( V_23 ) )
return true ;
}
return false ;
}
struct V_60 * F_84 ( struct V_1 * V_23 ,
unsigned int V_65 )
{
struct V_60 * V_60 = F_57 ( V_65 ) ;
return ( V_60 && V_60 -> V_23 == V_23 ) ? V_60 : NULL ;
}
void F_115 ( struct V_1 * V_23 , unsigned int V_65 ,
T_1 V_57 , struct V_89 * V_69 ,
void * V_121 , T_7 V_92 ,
void * V_124 , const char * V_125 )
{
F_141 ( V_65 , V_69 , V_92 , V_125 ) ;
F_142 ( V_65 , V_121 ) ;
F_117 ( V_65 , V_124 ) ;
}
static void F_27 ( struct V_1 * V_23 )
{
}
static void
F_143 ( struct V_85 * V_86 , struct V_1 * V_2 , int V_140 )
{
F_89 ( V_86 , L_62 , V_140 , L_39 , V_2 -> V_5 ) ;
F_89 ( V_86 , L_63 , V_140 + 1 , L_39 ,
V_2 -> V_36 + V_2 -> V_37 ) ;
F_89 ( V_86 , L_64 , V_140 + 1 , L_39 , V_2 -> V_64 ) ;
F_89 ( V_86 , L_65 , V_140 + 1 , L_39 , V_2 -> V_25 ) ;
#ifdef F_73
if ( ! V_2 -> V_93 )
return;
F_89 ( V_86 , L_66 , V_140 + 1 , L_39 , V_2 -> V_93 -> V_5 ) ;
F_143 ( V_86 , V_2 -> V_93 , V_140 + 4 ) ;
#endif
}
static int F_144 ( struct V_85 * V_86 , void * V_141 )
{
struct V_1 * V_2 = V_86 -> V_95 ;
if ( ! V_2 ) {
if ( ! V_41 )
return 0 ;
V_2 = V_41 ;
}
F_143 ( V_86 , V_2 , 0 ) ;
return 0 ;
}
static int F_145 ( struct V_101 * V_101 , struct V_102 * V_102 )
{
return F_98 ( V_102 , F_144 , V_101 -> V_103 ) ;
}
static void F_1 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_5 || ! V_142 || V_2 -> V_143 )
return;
V_2 -> V_143 = F_100 ( V_2 -> V_5 , 0444 , V_142 , V_2 ,
& V_144 ) ;
}
static void F_2 ( struct V_1 * V_2 )
{
F_146 ( V_2 -> V_143 ) ;
}
void T_5 F_147 ( struct V_145 * V_146 )
{
struct V_1 * V_2 ;
V_142 = F_148 ( L_67 , V_146 ) ;
if ( ! V_142 )
return;
F_100 ( L_68 , 0444 , V_142 , NULL , & V_144 ) ;
F_28 ( & V_38 ) ;
F_48 (d, &irq_domain_list, link)
F_1 ( V_2 ) ;
F_30 ( & V_38 ) ;
}
