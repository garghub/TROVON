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
void F_24 ( struct V_9 * V_18 )
{
F_19 ( L_5 , V_18 ) ;
V_25 = V_18 ;
}
void F_36 ( struct V_9 * V_18 , unsigned int V_40 )
{
struct V_41 * V_41 = F_37 ( V_40 ) ;
T_1 V_42 ;
if ( F_38 ( ! V_41 || V_41 -> V_18 != V_18 ,
L_6 , V_40 ) )
return;
V_42 = V_41 -> V_42 ;
F_39 ( V_40 , V_43 ) ;
F_40 ( V_40 , NULL , NULL ) ;
F_41 ( V_40 ) ;
if ( V_18 -> V_14 -> V_44 )
V_18 -> V_14 -> V_44 ( V_18 , V_40 ) ;
F_42 () ;
V_41 -> V_18 = NULL ;
V_41 -> V_42 = 0 ;
if ( V_42 < V_18 -> V_20 ) {
V_18 -> V_45 [ V_42 ] = 0 ;
} else {
F_16 ( & V_46 ) ;
F_43 ( & V_18 -> V_19 , V_42 ) ;
F_18 ( & V_46 ) ;
}
}
int F_44 ( struct V_9 * V_18 , unsigned int V_47 ,
T_1 V_42 )
{
struct V_41 * V_41 = F_37 ( V_47 ) ;
int V_48 ;
if ( F_38 ( V_42 >= V_18 -> V_11 ,
L_7 , ( int ) V_42 , V_18 -> V_5 ) )
return - V_49 ;
if ( F_38 ( ! V_41 , L_8 , V_47 ) )
return - V_49 ;
if ( F_38 ( V_41 -> V_18 , L_9 , V_47 ) )
return - V_49 ;
F_16 ( & V_22 ) ;
V_41 -> V_42 = V_42 ;
V_41 -> V_18 = V_18 ;
if ( V_18 -> V_14 -> V_50 ) {
V_48 = V_18 -> V_14 -> V_50 ( V_18 , V_47 , V_42 ) ;
if ( V_48 != 0 ) {
if ( V_48 != - V_51 ) {
F_31 ( L_10 ,
V_18 -> V_5 , V_42 , V_47 , V_48 ) ;
}
V_41 -> V_18 = NULL ;
V_41 -> V_42 = 0 ;
F_18 ( & V_22 ) ;
return V_48 ;
}
if ( ! V_18 -> V_5 && V_41 -> V_52 )
V_18 -> V_5 = V_41 -> V_52 -> V_5 ;
}
if ( V_42 < V_18 -> V_20 ) {
V_18 -> V_45 [ V_42 ] = V_47 ;
} else {
F_16 ( & V_46 ) ;
F_45 ( & V_18 -> V_19 , V_42 , V_41 ) ;
F_18 ( & V_46 ) ;
}
F_18 ( & V_22 ) ;
F_46 ( V_47 , V_43 ) ;
return 0 ;
}
void F_32 ( struct V_9 * V_18 , unsigned int V_53 ,
T_1 V_54 , int V_55 )
{
struct V_16 * V_17 ;
int V_56 ;
V_17 = F_26 ( V_18 ) ;
F_19 ( L_11 , V_57 ,
F_47 ( V_17 ) , V_53 , ( int ) V_54 , V_55 ) ;
for ( V_56 = 0 ; V_56 < V_55 ; V_56 ++ ) {
F_44 ( V_18 , V_53 + V_56 , V_54 + V_56 ) ;
}
}
unsigned int F_48 ( struct V_9 * V_18 )
{
struct V_16 * V_17 ;
unsigned int V_47 ;
if ( V_18 == NULL )
V_18 = V_25 ;
V_17 = F_26 ( V_18 ) ;
V_47 = F_49 ( 1 , F_12 ( V_17 ) ) ;
if ( ! V_47 ) {
F_19 ( L_12 ) ;
return 0 ;
}
if ( V_47 >= V_18 -> V_21 ) {
F_50 ( L_13 ,
V_18 -> V_21 ) ;
F_51 ( V_47 ) ;
return 0 ;
}
F_19 ( L_14 , V_47 ) ;
if ( F_44 ( V_18 , V_47 , V_47 ) ) {
F_51 ( V_47 ) ;
return 0 ;
}
return V_47 ;
}
unsigned int F_52 ( struct V_9 * V_18 ,
T_1 V_42 )
{
struct V_16 * V_17 ;
int V_47 ;
F_19 ( L_15 , V_18 , V_42 ) ;
if ( V_18 == NULL )
V_18 = V_25 ;
if ( V_18 == NULL ) {
F_38 ( 1 , L_16 , V_57 , V_42 ) ;
return 0 ;
}
F_19 ( L_17 , V_18 ) ;
V_17 = F_26 ( V_18 ) ;
V_47 = F_53 ( V_18 , V_42 ) ;
if ( V_47 ) {
F_19 ( L_18 , V_47 ) ;
return V_47 ;
}
V_47 = F_54 ( - 1 , 1 , V_42 , F_12 ( V_17 ) , NULL ) ;
if ( V_47 <= 0 ) {
F_19 ( L_19 ) ;
return 0 ;
}
if ( F_44 ( V_18 , V_47 , V_42 ) ) {
F_51 ( V_47 ) ;
return 0 ;
}
F_19 ( L_20 ,
V_42 , F_47 ( V_17 ) , V_47 ) ;
return V_47 ;
}
int F_55 ( struct V_9 * V_18 , unsigned int V_53 ,
T_1 V_54 , int V_55 )
{
struct V_16 * V_17 ;
int V_48 ;
V_17 = F_26 ( V_18 ) ;
V_48 = F_30 ( V_53 , V_53 , V_55 ,
F_12 ( V_17 ) ) ;
if ( F_23 ( V_48 < 0 ) )
return V_48 ;
F_32 ( V_18 , V_53 , V_54 , V_55 ) ;
return 0 ;
}
static int F_56 ( struct V_9 * V_58 ,
struct V_30 * V_31 ,
T_1 * V_42 , unsigned int * type )
{
#ifdef F_57
if ( V_58 -> V_14 -> V_59 )
return V_58 -> V_14 -> V_59 ( V_58 , V_31 , V_42 , type ) ;
#endif
if ( V_58 -> V_14 -> V_60 )
return V_58 -> V_14 -> V_60 ( V_58 , F_10 ( V_31 -> V_7 ) ,
V_31 -> V_61 , V_31 -> V_37 ,
V_42 , type ) ;
* V_42 = V_31 -> V_61 [ 0 ] ;
return 0 ;
}
static void F_58 ( struct V_62 * V_41 ,
struct V_30 * V_31 )
{
int V_56 ;
V_31 -> V_7 = V_41 -> V_63 ? & V_41 -> V_63 -> V_7 : NULL ;
V_31 -> V_37 = V_41 -> V_64 ;
for ( V_56 = 0 ; V_56 < V_41 -> V_64 ; V_56 ++ )
V_31 -> V_61 [ V_56 ] = V_41 -> args [ V_56 ] ;
}
unsigned int F_59 ( struct V_30 * V_31 )
{
struct V_9 * V_18 ;
struct V_41 * V_41 ;
T_1 V_42 ;
unsigned int type = V_65 ;
int V_47 ;
if ( V_31 -> V_7 ) {
V_18 = F_34 ( V_31 , V_66 ) ;
if ( ! V_18 )
V_18 = F_34 ( V_31 , V_39 ) ;
} else {
V_18 = V_25 ;
}
if ( ! V_18 ) {
F_60 ( L_21 ,
F_47 ( F_10 ( V_31 -> V_7 ) ) ) ;
return 0 ;
}
if ( F_56 ( V_18 , V_31 , & V_42 , & type ) )
return 0 ;
if ( F_6 ( type & ~ V_67 ) )
type &= V_67 ;
V_47 = F_53 ( V_18 , V_42 ) ;
if ( V_47 ) {
if ( type == V_65 || type == F_61 ( V_47 ) )
return V_47 ;
if ( F_61 ( V_47 ) == V_65 ) {
V_41 = F_37 ( V_47 ) ;
if ( ! V_41 )
return 0 ;
F_62 ( V_41 , type ) ;
return V_47 ;
}
F_60 ( L_22 ,
V_42 , F_47 ( F_10 ( V_31 -> V_7 ) ) ) ;
return 0 ;
}
if ( F_63 ( V_18 ) ) {
V_47 = F_64 ( V_18 , 1 , V_68 , V_31 ) ;
if ( V_47 <= 0 )
return 0 ;
} else {
V_47 = F_52 ( V_18 , V_42 ) ;
if ( ! V_47 )
return V_47 ;
}
V_41 = F_37 ( V_47 ) ;
if ( ! V_41 ) {
if ( F_63 ( V_18 ) )
F_65 ( V_47 , 1 ) ;
else
F_66 ( V_47 ) ;
return 0 ;
}
F_62 ( V_41 , type ) ;
return V_47 ;
}
unsigned int F_67 ( struct V_62 * V_41 )
{
struct V_30 V_31 ;
F_58 ( V_41 , & V_31 ) ;
return F_59 ( & V_31 ) ;
}
void F_66 ( unsigned int V_47 )
{
struct V_41 * V_41 = F_37 ( V_47 ) ;
struct V_9 * V_18 ;
if ( ! V_47 || ! V_41 )
return;
V_18 = V_41 -> V_18 ;
if ( F_6 ( V_18 == NULL ) )
return;
if ( F_63 ( V_18 ) ) {
F_65 ( V_47 , 1 ) ;
} else {
F_36 ( V_18 , V_47 ) ;
F_51 ( V_47 ) ;
}
}
unsigned int F_53 ( struct V_9 * V_18 ,
T_1 V_42 )
{
struct V_41 * V_2 ;
if ( V_18 == NULL )
V_18 = V_25 ;
if ( V_18 == NULL )
return 0 ;
if ( V_42 < V_18 -> V_21 ) {
V_2 = F_68 ( V_18 , V_42 ) ;
if ( V_2 && V_2 -> V_42 == V_42 )
return V_42 ;
}
if ( V_42 < V_18 -> V_20 )
return V_18 -> V_45 [ V_42 ] ;
F_69 () ;
V_2 = F_70 ( & V_18 -> V_19 , V_42 ) ;
F_71 () ;
return V_2 ? V_2 -> V_40 : 0 ;
}
static int F_72 ( struct V_69 * V_70 , void * V_71 )
{
unsigned long V_72 ;
struct V_73 * V_74 ;
struct V_9 * V_18 ;
struct V_75 V_76 ;
void * V_2 , * * V_77 ;
int V_56 ;
F_73 ( V_70 , L_23 ,
L_24 , L_25 , L_26 , L_27 , L_28 ) ;
F_16 ( & V_22 ) ;
F_35 (domain, &irq_domain_list, link) {
struct V_16 * V_17 ;
int V_55 = 0 ;
V_17 = F_26 ( V_18 ) ;
F_74 (slot, &domain->revmap_tree, &iter, 0 )
V_55 ++ ;
F_73 ( V_70 , L_29 ,
V_18 == V_25 ? '*' : ' ' , V_18 -> V_5 ,
V_18 -> V_20 + V_55 , V_18 -> V_20 ,
V_18 -> V_21 ,
V_17 ? F_47 ( V_17 ) : L_30 ) ;
}
F_18 ( & V_22 ) ;
F_73 ( V_70 , L_31 , L_32 , L_33 ,
L_34 , ( int ) ( 2 * sizeof( void * ) + 2 ) , L_35 ,
L_36 , L_37 , L_38 ) ;
for ( V_56 = 1 ; V_56 < V_78 ; V_56 ++ ) {
V_74 = F_75 ( V_56 ) ;
if ( ! V_74 )
continue;
F_76 ( & V_74 -> V_79 , V_72 ) ;
V_18 = V_74 -> V_41 . V_18 ;
if ( V_18 ) {
struct V_80 * V_52 ;
int V_42 = V_74 -> V_41 . V_42 ;
bool V_81 ;
F_73 ( V_70 , L_39 , V_56 ) ;
F_73 ( V_70 , L_40 , V_42 ) ;
V_52 = F_77 ( V_74 ) ;
F_73 ( V_70 , L_41 , ( V_52 && V_52 -> V_5 ) ? V_52 -> V_5 : L_42 ) ;
V_2 = F_78 ( V_74 ) ;
F_73 ( V_70 , V_2 ? L_43 : L_44 , V_2 ) ;
F_73 ( V_70 , L_45 , ( V_74 -> V_82 && V_74 -> V_82 -> V_83 ) ? '*' : ' ' ) ;
V_81 = ( V_56 == V_42 ) && ( V_56 < V_18 -> V_21 ) ;
F_73 ( V_70 , L_46 ,
( V_42 < V_18 -> V_20 ) ? L_47 : L_48 ,
V_81 ? L_49 : L_30 ) ;
F_73 ( V_70 , L_50 , V_74 -> V_41 . V_18 -> V_5 ) ;
}
F_79 ( & V_74 -> V_79 , V_72 ) ;
}
return 0 ;
}
static int F_80 ( struct V_84 * V_84 , struct V_85 * V_85 )
{
return F_81 ( V_85 , F_72 , V_84 -> V_86 ) ;
}
static int T_2 F_82 ( void )
{
if ( F_83 ( L_51 , V_87 , NULL ,
NULL , & V_88 ) == NULL )
return - V_89 ;
return 0 ;
}
int F_84 ( struct V_9 * V_58 , struct V_16 * V_90 ,
const T_3 * V_91 , unsigned int V_92 ,
unsigned long * V_93 , unsigned int * V_94 )
{
if ( F_6 ( V_92 < 1 ) )
return - V_49 ;
* V_93 = V_91 [ 0 ] ;
* V_94 = V_65 ;
return 0 ;
}
int F_85 ( struct V_9 * V_58 , struct V_16 * V_90 ,
const T_3 * V_91 , unsigned int V_92 ,
T_1 * V_93 , unsigned int * V_94 )
{
if ( F_6 ( V_92 < 2 ) )
return - V_49 ;
* V_93 = V_91 [ 0 ] ;
* V_94 = V_91 [ 1 ] & V_67 ;
return 0 ;
}
int F_86 ( struct V_9 * V_58 ,
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
int F_54 ( int V_47 , unsigned int V_95 , T_1 V_42 ,
int V_96 , const struct V_97 * V_98 )
{
unsigned int V_99 ;
if ( V_47 >= 0 ) {
V_47 = F_87 ( V_47 , V_47 , V_95 , V_96 , V_100 ,
V_98 ) ;
} else {
V_99 = V_42 % V_78 ;
if ( V_99 == 0 )
V_99 ++ ;
V_47 = F_87 ( - 1 , V_99 , V_95 , V_96 , V_100 ,
V_98 ) ;
if ( V_47 <= 0 && V_99 > 1 ) {
V_47 = F_87 ( - 1 , 1 , V_95 , V_96 , V_100 ,
V_98 ) ;
}
}
return V_47 ;
}
struct V_9 * F_88 ( struct V_9 * V_101 ,
unsigned int V_72 ,
unsigned int V_10 ,
struct V_1 * V_7 ,
const struct V_13 * V_14 ,
void * V_15 )
{
struct V_9 * V_18 ;
if ( V_10 )
V_18 = F_89 ( V_7 , V_10 , V_14 , V_15 ) ;
else
V_18 = F_90 ( V_7 , V_14 , V_15 ) ;
if ( V_18 ) {
V_18 -> V_101 = V_101 ;
V_18 -> V_72 |= V_72 ;
}
return V_18 ;
}
static void F_91 ( int V_47 )
{
struct V_41 * V_2 ;
for ( V_2 = F_37 ( V_47 ) ; V_2 ; V_2 = V_2 -> V_102 ) {
struct V_9 * V_18 = V_2 -> V_18 ;
T_1 V_42 = V_2 -> V_42 ;
if ( V_42 < V_18 -> V_20 ) {
V_18 -> V_45 [ V_42 ] = V_47 ;
} else {
F_16 ( & V_46 ) ;
F_45 ( & V_18 -> V_19 , V_42 , V_2 ) ;
F_18 ( & V_46 ) ;
}
if ( ! V_18 -> V_5 && V_2 -> V_52 )
V_18 -> V_5 = V_2 -> V_52 -> V_5 ;
}
F_46 ( V_47 , V_43 ) ;
}
static void F_92 ( int V_47 )
{
struct V_41 * V_2 ;
F_39 ( V_47 , V_43 ) ;
F_40 ( V_47 , NULL , NULL ) ;
F_41 ( V_47 ) ;
F_42 () ;
for ( V_2 = F_37 ( V_47 ) ; V_2 ; V_2 = V_2 -> V_102 ) {
struct V_9 * V_18 = V_2 -> V_18 ;
T_1 V_42 = V_2 -> V_42 ;
if ( V_42 < V_18 -> V_20 ) {
V_18 -> V_45 [ V_42 ] = 0 ;
} else {
F_16 ( & V_46 ) ;
F_43 ( & V_18 -> V_19 , V_42 ) ;
F_18 ( & V_46 ) ;
}
}
}
static struct V_41 * F_93 ( struct V_9 * V_18 ,
struct V_41 * V_103 )
{
struct V_41 * V_41 ;
V_41 = F_11 ( sizeof( * V_41 ) , V_6 ,
F_94 ( V_103 ) ) ;
if ( V_41 ) {
V_103 -> V_102 = V_41 ;
V_41 -> V_40 = V_103 -> V_40 ;
V_41 -> V_104 = V_103 -> V_104 ;
V_41 -> V_18 = V_18 ;
}
return V_41 ;
}
static void F_95 ( unsigned int V_47 , unsigned int V_78 )
{
struct V_41 * V_41 , * V_105 ;
int V_56 ;
for ( V_56 = 0 ; V_56 < V_78 ; V_56 ++ ) {
V_41 = F_37 ( V_47 + V_56 ) ;
V_105 = V_41 -> V_102 ;
V_41 -> V_102 = NULL ;
V_41 -> V_18 = NULL ;
while ( V_105 ) {
V_41 = V_105 ;
V_105 = V_105 -> V_102 ;
F_4 ( V_41 ) ;
}
}
}
static int F_96 ( struct V_9 * V_18 ,
unsigned int V_47 , unsigned int V_78 )
{
struct V_41 * V_41 ;
struct V_9 * V_101 ;
int V_56 ;
for ( V_56 = 0 ; V_56 < V_78 ; V_56 ++ ) {
V_41 = F_37 ( V_47 + V_56 ) ;
V_41 -> V_18 = V_18 ;
for ( V_101 = V_18 -> V_101 ; V_101 ; V_101 = V_101 -> V_101 ) {
V_41 = F_93 ( V_101 , V_41 ) ;
if ( ! V_41 ) {
F_95 ( V_47 , V_56 + 1 ) ;
return - V_89 ;
}
}
}
return 0 ;
}
struct V_41 * F_68 ( struct V_9 * V_18 ,
unsigned int V_47 )
{
struct V_41 * V_41 ;
for ( V_41 = F_37 ( V_47 ) ; V_41 ;
V_41 = V_41 -> V_102 )
if ( V_41 -> V_18 == V_18 )
return V_41 ;
return NULL ;
}
int F_97 ( struct V_9 * V_18 , unsigned int V_47 ,
T_1 V_42 , struct V_80 * V_52 ,
void * V_106 )
{
struct V_41 * V_41 = F_68 ( V_18 , V_47 ) ;
if ( ! V_41 )
return - V_107 ;
V_41 -> V_42 = V_42 ;
V_41 -> V_52 = V_52 ? V_52 : & V_108 ;
V_41 -> V_106 = V_106 ;
return 0 ;
}
void F_98 ( struct V_9 * V_18 , unsigned int V_47 ,
T_1 V_42 , struct V_80 * V_52 ,
void * V_106 , T_4 V_83 ,
void * V_109 , const char * V_110 )
{
F_97 ( V_18 , V_47 , V_42 , V_52 , V_106 ) ;
F_99 ( V_47 , V_83 , 0 , V_110 ) ;
F_100 ( V_47 , V_109 ) ;
}
void F_101 ( struct V_41 * V_41 )
{
V_41 -> V_42 = 0 ;
V_41 -> V_52 = & V_108 ;
V_41 -> V_106 = NULL ;
}
void F_102 ( struct V_9 * V_18 , unsigned int V_47 ,
unsigned int V_78 )
{
struct V_41 * V_41 ;
int V_56 ;
for ( V_56 = 0 ; V_56 < V_78 ; V_56 ++ ) {
V_41 = F_68 ( V_18 , V_47 + V_56 ) ;
if ( V_41 )
F_101 ( V_41 ) ;
}
F_103 ( V_18 , V_47 , V_78 ) ;
}
void F_104 ( struct V_9 * V_18 , unsigned int V_47 ,
unsigned int V_78 )
{
int V_56 ;
for ( V_56 = 0 ; V_56 < V_78 ; V_56 ++ ) {
F_100 ( V_47 + V_56 , NULL ) ;
F_105 ( V_47 + V_56 , NULL ) ;
}
F_102 ( V_18 , V_47 , V_78 ) ;
}
static bool F_106 ( struct V_9 * V_18 )
{
return V_18 -> V_72 & V_111 ;
}
static void F_107 ( struct V_9 * V_18 ,
unsigned int V_53 ,
unsigned int V_78 )
{
V_18 -> V_14 -> free ( V_18 , V_53 , V_78 ) ;
if ( F_106 ( V_18 ) ) {
F_108 ( ! V_18 -> V_101 ) ;
F_107 ( V_18 -> V_101 , V_53 ,
V_78 ) ;
}
}
int F_109 ( struct V_9 * V_18 ,
unsigned int V_53 ,
unsigned int V_78 , void * V_112 )
{
int V_48 = 0 ;
struct V_9 * V_101 = V_18 -> V_101 ;
bool V_113 = F_106 ( V_18 ) ;
F_108 ( V_113 && ! V_101 ) ;
if ( V_113 )
V_48 = F_109 ( V_101 , V_53 ,
V_78 , V_112 ) ;
if ( V_48 < 0 )
return V_48 ;
V_48 = V_18 -> V_14 -> V_114 ( V_18 , V_53 , V_78 , V_112 ) ;
if ( V_48 < 0 && V_113 )
F_107 ( V_101 , V_53 , V_78 ) ;
return V_48 ;
}
int F_110 ( struct V_9 * V_18 , int V_53 ,
unsigned int V_78 , int V_96 , void * V_112 ,
bool realloc , const struct V_97 * V_98 )
{
int V_56 , V_48 , V_47 ;
if ( V_18 == NULL ) {
V_18 = V_25 ;
if ( F_38 ( ! V_18 , L_52 ) )
return - V_49 ;
}
if ( ! V_18 -> V_14 -> V_114 ) {
F_19 ( L_53 ) ;
return - V_115 ;
}
if ( realloc && V_53 >= 0 ) {
V_47 = V_53 ;
} else {
V_47 = F_54 ( V_53 , V_78 , 0 , V_96 ,
V_98 ) ;
if ( V_47 < 0 ) {
F_19 ( L_54 ,
V_53 , V_78 ) ;
return V_47 ;
}
}
if ( F_96 ( V_18 , V_47 , V_78 ) ) {
F_19 ( L_55 , V_47 ) ;
V_48 = - V_89 ;
goto V_116;
}
F_16 ( & V_22 ) ;
V_48 = F_109 ( V_18 , V_47 , V_78 , V_112 ) ;
if ( V_48 < 0 ) {
F_18 ( & V_22 ) ;
goto V_117;
}
for ( V_56 = 0 ; V_56 < V_78 ; V_56 ++ )
F_91 ( V_47 + V_56 ) ;
F_18 ( & V_22 ) ;
return V_47 ;
V_117:
F_95 ( V_47 , V_78 ) ;
V_116:
F_111 ( V_47 , V_78 ) ;
return V_48 ;
}
void F_65 ( unsigned int V_47 , unsigned int V_78 )
{
struct V_41 * V_2 = F_37 ( V_47 ) ;
int V_56 ;
if ( F_38 ( ! V_2 || ! V_2 -> V_18 || ! V_2 -> V_18 -> V_14 -> free ,
L_56 ) )
return;
F_16 ( & V_22 ) ;
for ( V_56 = 0 ; V_56 < V_78 ; V_56 ++ )
F_92 ( V_47 + V_56 ) ;
F_107 ( V_2 -> V_18 , V_47 , V_78 ) ;
F_18 ( & V_22 ) ;
F_95 ( V_47 , V_78 ) ;
F_111 ( V_47 , V_78 ) ;
}
int F_112 ( struct V_9 * V_18 ,
unsigned int V_53 , unsigned int V_78 ,
void * V_112 )
{
if ( F_106 ( V_18 ) )
return 0 ;
V_18 = V_18 -> V_101 ;
if ( V_18 )
return F_109 ( V_18 , V_53 ,
V_78 , V_112 ) ;
return - V_115 ;
}
void F_103 ( struct V_9 * V_18 ,
unsigned int V_53 , unsigned int V_78 )
{
if ( ! F_106 ( V_18 ) && V_18 -> V_101 )
F_107 ( V_18 -> V_101 , V_53 ,
V_78 ) ;
}
void F_113 ( struct V_41 * V_41 )
{
if ( V_41 && V_41 -> V_18 ) {
struct V_9 * V_18 = V_41 -> V_18 ;
if ( V_41 -> V_102 )
F_113 ( V_41 -> V_102 ) ;
if ( V_18 -> V_14 -> V_118 )
V_18 -> V_14 -> V_118 ( V_18 , V_41 ) ;
}
}
void F_114 ( struct V_41 * V_41 )
{
if ( V_41 && V_41 -> V_18 ) {
struct V_9 * V_18 = V_41 -> V_18 ;
if ( V_18 -> V_14 -> V_119 )
V_18 -> V_14 -> V_119 ( V_18 , V_41 ) ;
if ( V_41 -> V_102 )
F_114 ( V_41 -> V_102 ) ;
}
}
static void F_15 ( struct V_9 * V_18 )
{
if ( V_18 -> V_14 -> V_114 )
V_18 -> V_72 |= V_120 ;
}
struct V_41 * F_68 ( struct V_9 * V_18 ,
unsigned int V_47 )
{
struct V_41 * V_41 = F_37 ( V_47 ) ;
return ( V_41 && V_41 -> V_18 == V_18 ) ? V_41 : NULL ;
}
void F_98 ( struct V_9 * V_18 , unsigned int V_47 ,
T_1 V_42 , struct V_80 * V_52 ,
void * V_106 , T_4 V_83 ,
void * V_109 , const char * V_110 )
{
F_115 ( V_47 , V_52 , V_83 , V_110 ) ;
F_116 ( V_47 , V_106 ) ;
F_100 ( V_47 , V_109 ) ;
}
static void F_15 ( struct V_9 * V_18 )
{
}
