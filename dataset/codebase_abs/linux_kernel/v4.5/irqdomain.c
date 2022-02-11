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
struct V_9 * V_16 ;
struct V_17 * V_18 ;
V_18 = F_10 ( V_7 ) ;
V_16 = F_11 ( sizeof( * V_16 ) + (sizeof( unsigned int ) * V_10 ) ,
V_6 , F_12 ( V_18 ) ) ;
if ( F_6 ( ! V_16 ) )
return NULL ;
F_13 ( V_18 ) ;
F_14 ( & V_16 -> V_19 , V_6 ) ;
V_16 -> V_14 = V_14 ;
V_16 -> V_15 = V_15 ;
V_16 -> V_7 = V_7 ;
V_16 -> V_11 = V_11 ;
V_16 -> V_20 = V_10 ;
V_16 -> V_21 = V_12 ;
F_15 ( V_16 ) ;
F_16 ( & V_22 ) ;
F_17 ( & V_16 -> V_23 , & V_24 ) ;
F_18 ( & V_22 ) ;
F_19 ( L_2 , V_16 -> V_5 ) ;
return V_16 ;
}
void F_20 ( struct V_9 * V_16 )
{
F_16 ( & V_22 ) ;
F_6 ( V_16 -> V_19 . V_25 ) ;
F_21 ( & V_16 -> V_23 ) ;
if ( F_22 ( V_26 == V_16 ) )
F_23 ( NULL ) ;
F_18 ( & V_22 ) ;
F_19 ( L_3 , V_16 -> V_5 ) ;
F_24 ( F_25 ( V_16 ) ) ;
F_4 ( V_16 ) ;
}
struct V_9 * F_26 ( struct V_17 * V_18 ,
unsigned int V_10 ,
unsigned int V_27 ,
const struct V_13 * V_14 ,
void * V_15 )
{
struct V_9 * V_16 ;
V_16 = F_9 ( F_27 ( V_18 ) , V_10 , V_10 , 0 , V_14 , V_15 ) ;
if ( ! V_16 )
return NULL ;
if ( V_27 > 0 ) {
if ( F_28 ( V_28 ) ) {
int V_29 = F_29 ( V_27 , V_27 , V_10 ,
F_12 ( V_18 ) ) ;
if ( V_29 < 0 )
F_30 ( L_4 ,
V_27 ) ;
}
F_31 ( V_16 , V_27 , 0 , V_10 ) ;
}
return V_16 ;
}
struct V_9 * F_32 ( struct V_17 * V_18 ,
unsigned int V_10 ,
unsigned int V_27 ,
T_1 V_30 ,
const struct V_13 * V_14 ,
void * V_15 )
{
struct V_9 * V_16 ;
V_16 = F_9 ( F_27 ( V_18 ) , V_30 + V_10 ,
V_30 + V_10 , 0 , V_14 , V_15 ) ;
if ( V_16 )
F_31 ( V_16 , V_27 , V_30 , V_10 ) ;
return V_16 ;
}
struct V_9 * F_33 ( struct V_1 * V_7 ,
enum V_31 V_32 )
{
struct V_9 * V_33 , * V_34 = NULL ;
int V_29 ;
F_16 ( & V_22 ) ;
F_34 (h, &irq_domain_list, link) {
if ( V_33 -> V_14 -> V_35 )
V_29 = V_33 -> V_14 -> V_35 ( V_33 , F_10 ( V_7 ) , V_32 ) ;
else
V_29 = ( ( V_7 != NULL ) && ( V_33 -> V_7 == V_7 ) &&
( ( V_32 == V_36 ) ||
( V_33 -> V_32 == V_32 ) ) ) ;
if ( V_29 ) {
V_34 = V_33 ;
break;
}
}
F_18 ( & V_22 ) ;
return V_34 ;
}
void F_23 ( struct V_9 * V_16 )
{
F_19 ( L_5 , V_16 ) ;
V_26 = V_16 ;
}
void F_35 ( struct V_9 * V_16 , unsigned int V_37 )
{
struct V_38 * V_38 = F_36 ( V_37 ) ;
T_1 V_39 ;
if ( F_37 ( ! V_38 || V_38 -> V_16 != V_16 ,
L_6 , V_37 ) )
return;
V_39 = V_38 -> V_39 ;
F_38 ( V_37 , V_40 ) ;
F_39 ( V_37 , NULL , NULL ) ;
F_40 ( V_37 ) ;
if ( V_16 -> V_14 -> V_41 )
V_16 -> V_14 -> V_41 ( V_16 , V_37 ) ;
F_41 () ;
V_38 -> V_16 = NULL ;
V_38 -> V_39 = 0 ;
if ( V_39 < V_16 -> V_20 ) {
V_16 -> V_42 [ V_39 ] = 0 ;
} else {
F_16 ( & V_43 ) ;
F_42 ( & V_16 -> V_19 , V_39 ) ;
F_18 ( & V_43 ) ;
}
}
int F_43 ( struct V_9 * V_16 , unsigned int V_44 ,
T_1 V_39 )
{
struct V_38 * V_38 = F_36 ( V_44 ) ;
int V_45 ;
if ( F_37 ( V_39 >= V_16 -> V_11 ,
L_7 , ( int ) V_39 , V_16 -> V_5 ) )
return - V_46 ;
if ( F_37 ( ! V_38 , L_8 , V_44 ) )
return - V_46 ;
if ( F_37 ( V_38 -> V_16 , L_9 , V_44 ) )
return - V_46 ;
F_16 ( & V_22 ) ;
V_38 -> V_39 = V_39 ;
V_38 -> V_16 = V_16 ;
if ( V_16 -> V_14 -> V_47 ) {
V_45 = V_16 -> V_14 -> V_47 ( V_16 , V_44 , V_39 ) ;
if ( V_45 != 0 ) {
if ( V_45 != - V_48 ) {
F_30 ( L_10 ,
V_16 -> V_5 , V_39 , V_44 , V_45 ) ;
}
V_38 -> V_16 = NULL ;
V_38 -> V_39 = 0 ;
F_18 ( & V_22 ) ;
return V_45 ;
}
if ( ! V_16 -> V_5 && V_38 -> V_49 )
V_16 -> V_5 = V_38 -> V_49 -> V_5 ;
}
if ( V_39 < V_16 -> V_20 ) {
V_16 -> V_42 [ V_39 ] = V_44 ;
} else {
F_16 ( & V_43 ) ;
F_44 ( & V_16 -> V_19 , V_39 , V_38 ) ;
F_18 ( & V_43 ) ;
}
F_18 ( & V_22 ) ;
F_45 ( V_44 , V_40 ) ;
return 0 ;
}
void F_31 ( struct V_9 * V_16 , unsigned int V_50 ,
T_1 V_51 , int V_52 )
{
struct V_17 * V_18 ;
int V_53 ;
V_18 = F_25 ( V_16 ) ;
F_19 ( L_11 , V_54 ,
F_46 ( V_18 ) , V_50 , ( int ) V_51 , V_52 ) ;
for ( V_53 = 0 ; V_53 < V_52 ; V_53 ++ ) {
F_43 ( V_16 , V_50 + V_53 , V_51 + V_53 ) ;
}
}
unsigned int F_47 ( struct V_9 * V_16 )
{
struct V_17 * V_18 ;
unsigned int V_44 ;
if ( V_16 == NULL )
V_16 = V_26 ;
V_18 = F_25 ( V_16 ) ;
V_44 = F_48 ( 1 , F_12 ( V_18 ) ) ;
if ( ! V_44 ) {
F_19 ( L_12 ) ;
return 0 ;
}
if ( V_44 >= V_16 -> V_21 ) {
F_49 ( L_13 ,
V_16 -> V_21 ) ;
F_50 ( V_44 ) ;
return 0 ;
}
F_19 ( L_14 , V_44 ) ;
if ( F_43 ( V_16 , V_44 , V_44 ) ) {
F_50 ( V_44 ) ;
return 0 ;
}
return V_44 ;
}
unsigned int F_51 ( struct V_9 * V_16 ,
T_1 V_39 )
{
struct V_17 * V_18 ;
int V_44 ;
F_19 ( L_15 , V_16 , V_39 ) ;
if ( V_16 == NULL )
V_16 = V_26 ;
if ( V_16 == NULL ) {
F_37 ( 1 , L_16 , V_54 , V_39 ) ;
return 0 ;
}
F_19 ( L_17 , V_16 ) ;
V_18 = F_25 ( V_16 ) ;
V_44 = F_52 ( V_16 , V_39 ) ;
if ( V_44 ) {
F_19 ( L_18 , V_44 ) ;
return V_44 ;
}
V_44 = F_53 ( - 1 , 1 , V_39 , F_12 ( V_18 ) ) ;
if ( V_44 <= 0 ) {
F_19 ( L_19 ) ;
return 0 ;
}
if ( F_43 ( V_16 , V_44 , V_39 ) ) {
F_50 ( V_44 ) ;
return 0 ;
}
F_19 ( L_20 ,
V_39 , F_46 ( V_18 ) , V_44 ) ;
return V_44 ;
}
int F_54 ( struct V_9 * V_16 , unsigned int V_50 ,
T_1 V_51 , int V_52 )
{
struct V_17 * V_18 ;
int V_45 ;
V_18 = F_25 ( V_16 ) ;
V_45 = F_29 ( V_50 , V_50 , V_52 ,
F_12 ( V_18 ) ) ;
if ( F_22 ( V_45 < 0 ) )
return V_45 ;
F_31 ( V_16 , V_50 , V_51 , V_52 ) ;
return 0 ;
}
static int F_55 ( struct V_9 * V_55 ,
struct V_56 * V_57 ,
T_1 * V_39 , unsigned int * type )
{
#ifdef F_56
if ( V_55 -> V_14 -> V_58 )
return V_55 -> V_14 -> V_58 ( V_55 , V_57 , V_39 , type ) ;
#endif
if ( V_55 -> V_14 -> V_59 )
return V_55 -> V_14 -> V_59 ( V_55 , F_10 ( V_57 -> V_7 ) ,
V_57 -> V_60 , V_57 -> V_61 ,
V_39 , type ) ;
* V_39 = V_57 -> V_60 [ 0 ] ;
return 0 ;
}
static void F_57 ( struct V_62 * V_38 ,
struct V_56 * V_57 )
{
int V_53 ;
V_57 -> V_7 = V_38 -> V_63 ? & V_38 -> V_63 -> V_7 : NULL ;
V_57 -> V_61 = V_38 -> V_64 ;
for ( V_53 = 0 ; V_53 < V_38 -> V_64 ; V_53 ++ )
V_57 -> V_60 [ V_53 ] = V_38 -> args [ V_53 ] ;
}
unsigned int F_58 ( struct V_56 * V_57 )
{
struct V_9 * V_16 ;
T_1 V_39 ;
unsigned int type = V_65 ;
int V_44 ;
if ( V_57 -> V_7 ) {
V_16 = F_33 ( V_57 -> V_7 ,
V_66 ) ;
if ( ! V_16 )
V_16 = F_33 ( V_57 -> V_7 ,
V_36 ) ;
} else {
V_16 = V_26 ;
}
if ( ! V_16 ) {
F_59 ( L_21 ,
F_46 ( F_10 ( V_57 -> V_7 ) ) ) ;
return 0 ;
}
if ( F_55 ( V_16 , V_57 , & V_39 , & type ) )
return 0 ;
if ( F_60 ( V_16 ) ) {
V_44 = F_52 ( V_16 , V_39 ) ;
if ( V_44 )
return V_44 ;
V_44 = F_61 ( V_16 , 1 , V_67 , V_57 ) ;
if ( V_44 <= 0 )
return 0 ;
} else {
V_44 = F_51 ( V_16 , V_39 ) ;
if ( ! V_44 )
return V_44 ;
}
if ( type != V_65 &&
type != F_62 ( V_44 ) )
F_63 ( V_44 , type ) ;
return V_44 ;
}
unsigned int F_64 ( struct V_62 * V_38 )
{
struct V_56 V_57 ;
F_57 ( V_38 , & V_57 ) ;
return F_58 ( & V_57 ) ;
}
void F_65 ( unsigned int V_44 )
{
struct V_38 * V_38 = F_36 ( V_44 ) ;
struct V_9 * V_16 ;
if ( ! V_44 || ! V_38 )
return;
V_16 = V_38 -> V_16 ;
if ( F_6 ( V_16 == NULL ) )
return;
F_35 ( V_16 , V_44 ) ;
F_50 ( V_44 ) ;
}
unsigned int F_52 ( struct V_9 * V_16 ,
T_1 V_39 )
{
struct V_38 * V_2 ;
if ( V_16 == NULL )
V_16 = V_26 ;
if ( V_16 == NULL )
return 0 ;
if ( V_39 < V_16 -> V_21 ) {
V_2 = F_66 ( V_16 , V_39 ) ;
if ( V_2 && V_2 -> V_39 == V_39 )
return V_39 ;
}
if ( V_39 < V_16 -> V_20 )
return V_16 -> V_42 [ V_39 ] ;
F_67 () ;
V_2 = F_68 ( & V_16 -> V_19 , V_39 ) ;
F_69 () ;
return V_2 ? V_2 -> V_37 : 0 ;
}
static int F_70 ( struct V_68 * V_69 , void * V_70 )
{
unsigned long V_71 ;
struct V_72 * V_73 ;
struct V_9 * V_16 ;
struct V_74 V_75 ;
void * V_2 , * * V_76 ;
int V_53 ;
F_71 ( V_69 , L_22 ,
L_23 , L_24 , L_25 , L_26 , L_27 ) ;
F_16 ( & V_22 ) ;
F_34 (domain, &irq_domain_list, link) {
struct V_17 * V_18 ;
int V_52 = 0 ;
V_18 = F_25 ( V_16 ) ;
F_72 (slot, &domain->revmap_tree, &iter, 0 )
V_52 ++ ;
F_71 ( V_69 , L_28 ,
V_16 == V_26 ? '*' : ' ' , V_16 -> V_5 ,
V_16 -> V_20 + V_52 , V_16 -> V_20 ,
V_16 -> V_21 ,
V_18 ? F_46 ( V_18 ) : L_29 ) ;
}
F_18 ( & V_22 ) ;
F_71 ( V_69 , L_30 , L_31 , L_32 ,
L_33 , ( int ) ( 2 * sizeof( void * ) + 2 ) , L_34 ,
L_35 , L_36 , L_37 ) ;
for ( V_53 = 1 ; V_53 < V_77 ; V_53 ++ ) {
V_73 = F_73 ( V_53 ) ;
if ( ! V_73 )
continue;
F_74 ( & V_73 -> V_78 , V_71 ) ;
V_16 = V_73 -> V_38 . V_16 ;
if ( V_16 ) {
struct V_79 * V_49 ;
int V_39 = V_73 -> V_38 . V_39 ;
bool V_80 ;
F_71 ( V_69 , L_38 , V_53 ) ;
F_71 ( V_69 , L_39 , V_39 ) ;
V_49 = F_75 ( V_73 ) ;
F_71 ( V_69 , L_40 , ( V_49 && V_49 -> V_5 ) ? V_49 -> V_5 : L_41 ) ;
V_2 = F_76 ( V_73 ) ;
F_71 ( V_69 , V_2 ? L_42 : L_43 , V_2 ) ;
F_71 ( V_69 , L_44 , ( V_73 -> V_81 && V_73 -> V_81 -> V_82 ) ? '*' : ' ' ) ;
V_80 = ( V_53 == V_39 ) && ( V_53 < V_16 -> V_21 ) ;
F_71 ( V_69 , L_45 ,
( V_39 < V_16 -> V_20 ) ? L_46 : L_47 ,
V_80 ? L_48 : L_29 ) ;
F_71 ( V_69 , L_49 , V_73 -> V_38 . V_16 -> V_5 ) ;
}
F_77 ( & V_73 -> V_78 , V_71 ) ;
}
return 0 ;
}
static int F_78 ( struct V_83 * V_83 , struct V_84 * V_84 )
{
return F_79 ( V_84 , F_70 , V_83 -> V_85 ) ;
}
static int T_2 F_80 ( void )
{
if ( F_81 ( L_50 , V_86 , NULL ,
NULL , & V_87 ) == NULL )
return - V_88 ;
return 0 ;
}
int F_82 ( struct V_9 * V_55 , struct V_17 * V_89 ,
const T_3 * V_90 , unsigned int V_91 ,
unsigned long * V_92 , unsigned int * V_93 )
{
if ( F_6 ( V_91 < 1 ) )
return - V_46 ;
* V_92 = V_90 [ 0 ] ;
* V_93 = V_65 ;
return 0 ;
}
int F_83 ( struct V_9 * V_55 , struct V_17 * V_89 ,
const T_3 * V_90 , unsigned int V_91 ,
T_1 * V_92 , unsigned int * V_93 )
{
if ( F_6 ( V_91 < 2 ) )
return - V_46 ;
* V_92 = V_90 [ 0 ] ;
* V_93 = V_90 [ 1 ] & V_94 ;
return 0 ;
}
int F_84 ( struct V_9 * V_55 ,
struct V_17 * V_89 ,
const T_3 * V_90 , unsigned int V_91 ,
unsigned long * V_92 , unsigned int * V_93 )
{
if ( F_6 ( V_91 < 1 ) )
return - V_46 ;
* V_92 = V_90 [ 0 ] ;
* V_93 = ( V_91 > 1 ) ? V_90 [ 1 ] : V_65 ;
return 0 ;
}
static int F_53 ( int V_44 , unsigned int V_95 ,
T_1 V_39 , int V_96 )
{
unsigned int V_97 ;
if ( V_44 >= 0 ) {
V_44 = F_29 ( V_44 , V_44 , V_95 , V_96 ) ;
} else {
V_97 = V_39 % V_77 ;
if ( V_97 == 0 )
V_97 ++ ;
V_44 = F_85 ( V_97 , V_95 , V_96 ) ;
if ( V_44 <= 0 && V_97 > 1 )
V_44 = F_85 ( 1 , V_95 , V_96 ) ;
}
return V_44 ;
}
struct V_9 * F_86 ( struct V_9 * V_98 ,
unsigned int V_71 ,
unsigned int V_10 ,
struct V_1 * V_7 ,
const struct V_13 * V_14 ,
void * V_15 )
{
struct V_9 * V_16 ;
if ( V_10 )
V_16 = F_87 ( V_7 , V_10 , V_14 , V_15 ) ;
else
V_16 = F_88 ( V_7 , V_14 , V_15 ) ;
if ( V_16 ) {
V_16 -> V_98 = V_98 ;
V_16 -> V_71 |= V_71 ;
}
return V_16 ;
}
static void F_89 ( int V_44 )
{
struct V_38 * V_2 ;
for ( V_2 = F_36 ( V_44 ) ; V_2 ; V_2 = V_2 -> V_99 ) {
struct V_9 * V_16 = V_2 -> V_16 ;
T_1 V_39 = V_2 -> V_39 ;
if ( V_39 < V_16 -> V_20 ) {
V_16 -> V_42 [ V_39 ] = V_44 ;
} else {
F_16 ( & V_43 ) ;
F_44 ( & V_16 -> V_19 , V_39 , V_2 ) ;
F_18 ( & V_43 ) ;
}
if ( ! V_16 -> V_5 && V_2 -> V_49 )
V_16 -> V_5 = V_2 -> V_49 -> V_5 ;
}
F_45 ( V_44 , V_40 ) ;
}
static void F_90 ( int V_44 )
{
struct V_38 * V_2 ;
F_38 ( V_44 , V_40 ) ;
F_39 ( V_44 , NULL , NULL ) ;
F_40 ( V_44 ) ;
F_41 () ;
for ( V_2 = F_36 ( V_44 ) ; V_2 ; V_2 = V_2 -> V_99 ) {
struct V_9 * V_16 = V_2 -> V_16 ;
T_1 V_39 = V_2 -> V_39 ;
if ( V_39 < V_16 -> V_20 ) {
V_16 -> V_42 [ V_39 ] = 0 ;
} else {
F_16 ( & V_43 ) ;
F_42 ( & V_16 -> V_19 , V_39 ) ;
F_18 ( & V_43 ) ;
}
}
}
static struct V_38 * F_91 ( struct V_9 * V_16 ,
struct V_38 * V_100 )
{
struct V_38 * V_38 ;
V_38 = F_11 ( sizeof( * V_38 ) , V_6 ,
F_92 ( V_100 ) ) ;
if ( V_38 ) {
V_100 -> V_99 = V_38 ;
V_38 -> V_37 = V_100 -> V_37 ;
V_38 -> V_101 = V_100 -> V_101 ;
V_38 -> V_16 = V_16 ;
}
return V_38 ;
}
static void F_93 ( unsigned int V_44 , unsigned int V_77 )
{
struct V_38 * V_38 , * V_102 ;
int V_53 ;
for ( V_53 = 0 ; V_53 < V_77 ; V_53 ++ ) {
V_38 = F_36 ( V_44 + V_53 ) ;
V_102 = V_38 -> V_99 ;
V_38 -> V_99 = NULL ;
V_38 -> V_16 = NULL ;
while ( V_102 ) {
V_38 = V_102 ;
V_102 = V_102 -> V_99 ;
F_4 ( V_38 ) ;
}
}
}
static int F_94 ( struct V_9 * V_16 ,
unsigned int V_44 , unsigned int V_77 )
{
struct V_38 * V_38 ;
struct V_9 * V_98 ;
int V_53 ;
for ( V_53 = 0 ; V_53 < V_77 ; V_53 ++ ) {
V_38 = F_36 ( V_44 + V_53 ) ;
V_38 -> V_16 = V_16 ;
for ( V_98 = V_16 -> V_98 ; V_98 ; V_98 = V_98 -> V_98 ) {
V_38 = F_91 ( V_98 , V_38 ) ;
if ( ! V_38 ) {
F_93 ( V_44 , V_53 + 1 ) ;
return - V_88 ;
}
}
}
return 0 ;
}
struct V_38 * F_66 ( struct V_9 * V_16 ,
unsigned int V_44 )
{
struct V_38 * V_38 ;
for ( V_38 = F_36 ( V_44 ) ; V_38 ;
V_38 = V_38 -> V_99 )
if ( V_38 -> V_16 == V_16 )
return V_38 ;
return NULL ;
}
int F_95 ( struct V_9 * V_16 , unsigned int V_44 ,
T_1 V_39 , struct V_79 * V_49 ,
void * V_103 )
{
struct V_38 * V_38 = F_66 ( V_16 , V_44 ) ;
if ( ! V_38 )
return - V_104 ;
V_38 -> V_39 = V_39 ;
V_38 -> V_49 = V_49 ? V_49 : & V_105 ;
V_38 -> V_103 = V_103 ;
return 0 ;
}
void F_96 ( struct V_9 * V_16 , unsigned int V_44 ,
T_1 V_39 , struct V_79 * V_49 ,
void * V_103 , T_4 V_82 ,
void * V_106 , const char * V_107 )
{
F_95 ( V_16 , V_44 , V_39 , V_49 , V_103 ) ;
F_97 ( V_44 , V_82 , 0 , V_107 ) ;
F_98 ( V_44 , V_106 ) ;
}
void F_99 ( struct V_38 * V_38 )
{
V_38 -> V_39 = 0 ;
V_38 -> V_49 = & V_105 ;
V_38 -> V_103 = NULL ;
}
void F_100 ( struct V_9 * V_16 , unsigned int V_44 ,
unsigned int V_77 )
{
struct V_38 * V_38 ;
int V_53 ;
for ( V_53 = 0 ; V_53 < V_77 ; V_53 ++ ) {
V_38 = F_66 ( V_16 , V_44 + V_53 ) ;
if ( V_38 )
F_99 ( V_38 ) ;
}
F_101 ( V_16 , V_44 , V_77 ) ;
}
void F_102 ( struct V_9 * V_16 , unsigned int V_44 ,
unsigned int V_77 )
{
int V_53 ;
for ( V_53 = 0 ; V_53 < V_77 ; V_53 ++ ) {
F_98 ( V_44 + V_53 , NULL ) ;
F_103 ( V_44 + V_53 , NULL ) ;
}
F_100 ( V_16 , V_44 , V_77 ) ;
}
static bool F_104 ( struct V_9 * V_16 )
{
return V_16 -> V_71 & V_108 ;
}
static void F_105 ( struct V_9 * V_16 ,
unsigned int V_50 ,
unsigned int V_77 )
{
V_16 -> V_14 -> free ( V_16 , V_50 , V_77 ) ;
if ( F_104 ( V_16 ) ) {
F_106 ( ! V_16 -> V_98 ) ;
F_105 ( V_16 -> V_98 , V_50 ,
V_77 ) ;
}
}
int F_107 ( struct V_9 * V_16 ,
unsigned int V_50 ,
unsigned int V_77 , void * V_109 )
{
int V_45 = 0 ;
struct V_9 * V_98 = V_16 -> V_98 ;
bool V_110 = F_104 ( V_16 ) ;
F_106 ( V_110 && ! V_98 ) ;
if ( V_110 )
V_45 = F_107 ( V_98 , V_50 ,
V_77 , V_109 ) ;
if ( V_45 >= 0 )
V_45 = V_16 -> V_14 -> V_111 ( V_16 , V_50 , V_77 , V_109 ) ;
if ( V_45 < 0 && V_110 )
F_105 ( V_98 , V_50 , V_77 ) ;
return V_45 ;
}
int F_108 ( struct V_9 * V_16 , int V_50 ,
unsigned int V_77 , int V_96 , void * V_109 ,
bool realloc )
{
int V_53 , V_45 , V_44 ;
if ( V_16 == NULL ) {
V_16 = V_26 ;
if ( F_37 ( ! V_16 , L_51 ) )
return - V_46 ;
}
if ( ! V_16 -> V_14 -> V_111 ) {
F_19 ( L_52 ) ;
return - V_112 ;
}
if ( realloc && V_50 >= 0 ) {
V_44 = V_50 ;
} else {
V_44 = F_53 ( V_50 , V_77 , 0 , V_96 ) ;
if ( V_44 < 0 ) {
F_19 ( L_53 ,
V_50 , V_77 ) ;
return V_44 ;
}
}
if ( F_94 ( V_16 , V_44 , V_77 ) ) {
F_19 ( L_54 , V_44 ) ;
V_45 = - V_88 ;
goto V_113;
}
F_16 ( & V_22 ) ;
V_45 = F_107 ( V_16 , V_44 , V_77 , V_109 ) ;
if ( V_45 < 0 ) {
F_18 ( & V_22 ) ;
goto V_114;
}
for ( V_53 = 0 ; V_53 < V_77 ; V_53 ++ )
F_89 ( V_44 + V_53 ) ;
F_18 ( & V_22 ) ;
return V_44 ;
V_114:
F_93 ( V_44 , V_77 ) ;
V_113:
F_109 ( V_44 , V_77 ) ;
return V_45 ;
}
void F_110 ( unsigned int V_44 , unsigned int V_77 )
{
struct V_38 * V_2 = F_36 ( V_44 ) ;
int V_53 ;
if ( F_37 ( ! V_2 || ! V_2 -> V_16 || ! V_2 -> V_16 -> V_14 -> free ,
L_55 ) )
return;
F_16 ( & V_22 ) ;
for ( V_53 = 0 ; V_53 < V_77 ; V_53 ++ )
F_90 ( V_44 + V_53 ) ;
F_105 ( V_2 -> V_16 , V_44 , V_77 ) ;
F_18 ( & V_22 ) ;
F_93 ( V_44 , V_77 ) ;
F_109 ( V_44 , V_77 ) ;
}
int F_111 ( struct V_9 * V_16 ,
unsigned int V_50 , unsigned int V_77 ,
void * V_109 )
{
if ( F_104 ( V_16 ) )
return 0 ;
V_16 = V_16 -> V_98 ;
if ( V_16 )
return F_107 ( V_16 , V_50 ,
V_77 , V_109 ) ;
return - V_112 ;
}
void F_101 ( struct V_9 * V_16 ,
unsigned int V_50 , unsigned int V_77 )
{
if ( ! F_104 ( V_16 ) && V_16 -> V_98 )
F_105 ( V_16 -> V_98 , V_50 ,
V_77 ) ;
}
void F_112 ( struct V_38 * V_38 )
{
if ( V_38 && V_38 -> V_16 ) {
struct V_9 * V_16 = V_38 -> V_16 ;
if ( V_38 -> V_99 )
F_112 ( V_38 -> V_99 ) ;
if ( V_16 -> V_14 -> V_115 )
V_16 -> V_14 -> V_115 ( V_16 , V_38 ) ;
}
}
void F_113 ( struct V_38 * V_38 )
{
if ( V_38 && V_38 -> V_16 ) {
struct V_9 * V_16 = V_38 -> V_16 ;
if ( V_16 -> V_14 -> V_116 )
V_16 -> V_14 -> V_116 ( V_16 , V_38 ) ;
if ( V_38 -> V_99 )
F_113 ( V_38 -> V_99 ) ;
}
}
static void F_15 ( struct V_9 * V_16 )
{
if ( V_16 -> V_14 -> V_111 )
V_16 -> V_71 |= V_117 ;
}
struct V_38 * F_66 ( struct V_9 * V_16 ,
unsigned int V_44 )
{
struct V_38 * V_38 = F_36 ( V_44 ) ;
return ( V_38 && V_38 -> V_16 == V_16 ) ? V_38 : NULL ;
}
void F_96 ( struct V_9 * V_16 , unsigned int V_44 ,
T_1 V_39 , struct V_79 * V_49 ,
void * V_103 , T_4 V_82 ,
void * V_106 , const char * V_107 )
{
F_114 ( V_44 , V_49 , V_82 , V_107 ) ;
F_115 ( V_44 , V_103 ) ;
F_98 ( V_44 , V_106 ) ;
}
static void F_15 ( struct V_9 * V_16 )
{
}
