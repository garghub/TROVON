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
struct V_1 * F_24 ( struct V_2 * V_25 ,
enum V_26 V_27 )
{
struct V_1 * V_28 , * V_29 = NULL ;
int V_23 ;
F_8 ( & V_15 ) ;
F_25 (h, &irq_domain_list, link) {
if ( V_28 -> V_8 -> V_30 )
V_23 = V_28 -> V_8 -> V_30 ( V_28 , V_25 , V_27 ) ;
else
V_23 = ( ( V_28 -> V_3 != NULL ) && ( V_28 -> V_3 == V_25 ) &&
( ( V_27 == V_31 ) ||
( V_28 -> V_27 == V_27 ) ) ) ;
if ( V_23 ) {
V_29 = V_28 ;
break;
}
}
F_10 ( & V_15 ) ;
return V_29 ;
}
void F_15 ( struct V_1 * V_10 )
{
F_11 ( L_4 , V_10 ) ;
V_20 = V_10 ;
}
void F_26 ( struct V_1 * V_10 , unsigned int V_32 )
{
struct V_33 * V_33 = F_27 ( V_32 ) ;
T_1 V_34 ;
if ( F_28 ( ! V_33 || V_33 -> V_10 != V_10 ,
L_5 , V_32 ) )
return;
V_34 = V_33 -> V_34 ;
F_29 ( V_32 , V_35 ) ;
F_30 ( V_32 , NULL , NULL ) ;
F_31 ( V_32 ) ;
if ( V_10 -> V_8 -> V_36 )
V_10 -> V_8 -> V_36 ( V_10 , V_32 ) ;
F_32 () ;
V_33 -> V_10 = NULL ;
V_33 -> V_34 = 0 ;
if ( V_34 < V_10 -> V_13 ) {
V_10 -> V_37 [ V_34 ] = 0 ;
} else {
F_8 ( & V_38 ) ;
F_33 ( & V_10 -> V_12 , V_34 ) ;
F_10 ( & V_38 ) ;
}
}
int F_34 ( struct V_1 * V_10 , unsigned int V_39 ,
T_1 V_34 )
{
struct V_33 * V_33 = F_27 ( V_39 ) ;
int V_40 ;
if ( F_28 ( V_34 >= V_10 -> V_5 ,
L_6 , ( int ) V_34 , V_10 -> V_18 ) )
return - V_41 ;
if ( F_28 ( ! V_33 , L_7 , V_39 ) )
return - V_41 ;
if ( F_28 ( V_33 -> V_10 , L_8 , V_39 ) )
return - V_41 ;
F_8 ( & V_15 ) ;
V_33 -> V_34 = V_34 ;
V_33 -> V_10 = V_10 ;
if ( V_10 -> V_8 -> V_42 ) {
V_40 = V_10 -> V_8 -> V_42 ( V_10 , V_39 , V_34 ) ;
if ( V_40 != 0 ) {
if ( V_40 != - V_43 ) {
F_21 ( L_9 ,
V_10 -> V_18 , V_34 , V_39 , V_40 ) ;
}
V_33 -> V_10 = NULL ;
V_33 -> V_34 = 0 ;
F_10 ( & V_15 ) ;
return V_40 ;
}
if ( ! V_10 -> V_18 && V_33 -> V_44 )
V_10 -> V_18 = V_33 -> V_44 -> V_18 ;
}
if ( V_34 < V_10 -> V_13 ) {
V_10 -> V_37 [ V_34 ] = V_39 ;
} else {
F_8 ( & V_38 ) ;
F_35 ( & V_10 -> V_12 , V_34 , V_33 ) ;
F_10 ( & V_38 ) ;
}
F_10 ( & V_15 ) ;
F_36 ( V_39 , V_35 ) ;
return 0 ;
}
void F_22 ( struct V_1 * V_10 , unsigned int V_45 ,
T_1 V_46 , int V_47 )
{
int V_48 ;
F_11 ( L_10 , V_49 ,
F_37 ( V_10 -> V_3 ) , V_45 , ( int ) V_46 , V_47 ) ;
for ( V_48 = 0 ; V_48 < V_47 ; V_48 ++ ) {
F_34 ( V_10 , V_45 + V_48 , V_46 + V_48 ) ;
}
}
unsigned int F_38 ( struct V_1 * V_10 )
{
unsigned int V_39 ;
if ( V_10 == NULL )
V_10 = V_20 ;
V_39 = F_39 ( 1 , F_3 ( V_10 -> V_3 ) ) ;
if ( ! V_39 ) {
F_11 ( L_11 ) ;
return 0 ;
}
if ( V_39 >= V_10 -> V_14 ) {
F_40 ( L_12 ,
V_10 -> V_14 ) ;
F_41 ( V_39 ) ;
return 0 ;
}
F_11 ( L_13 , V_39 ) ;
if ( F_34 ( V_10 , V_39 , V_39 ) ) {
F_41 ( V_39 ) ;
return 0 ;
}
return V_39 ;
}
unsigned int F_42 ( struct V_1 * V_10 ,
T_1 V_34 )
{
int V_39 ;
F_11 ( L_14 , V_10 , V_34 ) ;
if ( V_10 == NULL )
V_10 = V_20 ;
if ( V_10 == NULL ) {
F_28 ( 1 , L_15 , V_49 , V_34 ) ;
return 0 ;
}
F_11 ( L_16 , V_10 ) ;
V_39 = F_43 ( V_10 , V_34 ) ;
if ( V_39 ) {
F_11 ( L_17 , V_39 ) ;
return V_39 ;
}
V_39 = F_44 ( - 1 , 1 , V_34 ,
F_3 ( V_10 -> V_3 ) ) ;
if ( V_39 <= 0 ) {
F_11 ( L_18 ) ;
return 0 ;
}
if ( F_34 ( V_10 , V_39 , V_34 ) ) {
F_41 ( V_39 ) ;
return 0 ;
}
F_11 ( L_19 ,
V_34 , F_37 ( V_10 -> V_3 ) , V_39 ) ;
return V_39 ;
}
int F_45 ( struct V_1 * V_10 , unsigned int V_45 ,
T_1 V_46 , int V_47 )
{
int V_40 ;
V_40 = F_20 ( V_45 , V_45 , V_47 ,
F_3 ( V_10 -> V_3 ) ) ;
if ( F_14 ( V_40 < 0 ) )
return V_40 ;
F_22 ( V_10 , V_45 , V_46 , V_47 ) ;
return 0 ;
}
unsigned int F_46 ( struct V_50 * V_33 )
{
struct V_1 * V_10 ;
T_1 V_34 ;
unsigned int type = V_51 ;
int V_39 ;
V_10 = V_33 -> V_52 ? F_47 ( V_33 -> V_52 ) : V_20 ;
if ( ! V_10 ) {
F_48 ( L_20 ,
F_37 ( V_33 -> V_52 ) ) ;
return 0 ;
}
if ( V_10 -> V_8 -> V_53 == NULL )
V_34 = V_33 -> args [ 0 ] ;
else {
if ( V_10 -> V_8 -> V_53 ( V_10 , V_33 -> V_52 , V_33 -> args ,
V_33 -> V_54 , & V_34 , & type ) )
return 0 ;
}
if ( F_49 ( V_10 ) ) {
V_39 = F_43 ( V_10 , V_34 ) ;
if ( V_39 )
return V_39 ;
V_39 = F_50 ( V_10 , 1 , V_55 , V_33 ) ;
if ( V_39 <= 0 )
return 0 ;
} else {
V_39 = F_42 ( V_10 , V_34 ) ;
if ( ! V_39 )
return V_39 ;
}
if ( type != V_51 &&
type != F_51 ( V_39 ) )
F_52 ( V_39 , type ) ;
return V_39 ;
}
void F_53 ( unsigned int V_39 )
{
struct V_33 * V_33 = F_27 ( V_39 ) ;
struct V_1 * V_10 ;
if ( ! V_39 || ! V_33 )
return;
V_10 = V_33 -> V_10 ;
if ( F_4 ( V_10 == NULL ) )
return;
F_26 ( V_10 , V_39 ) ;
F_41 ( V_39 ) ;
}
unsigned int F_43 ( struct V_1 * V_10 ,
T_1 V_34 )
{
struct V_33 * V_56 ;
if ( V_10 == NULL )
V_10 = V_20 ;
if ( V_10 == NULL )
return 0 ;
if ( V_34 < V_10 -> V_14 ) {
V_56 = F_54 ( V_10 , V_34 ) ;
if ( V_56 && V_56 -> V_34 == V_34 )
return V_34 ;
}
if ( V_34 < V_10 -> V_13 )
return V_10 -> V_37 [ V_34 ] ;
F_55 () ;
V_56 = F_56 ( & V_10 -> V_12 , V_34 ) ;
F_57 () ;
return V_56 ? V_56 -> V_32 : 0 ;
}
static int F_58 ( struct V_57 * V_58 , void * V_59 )
{
unsigned long V_60 ;
struct V_61 * V_62 ;
struct V_1 * V_10 ;
struct V_63 V_64 ;
void * V_56 , * * V_65 ;
int V_48 ;
F_59 ( V_58 , L_21 ,
L_22 , L_23 , L_24 , L_25 , L_26 ) ;
F_8 ( & V_15 ) ;
F_25 (domain, &irq_domain_list, link) {
int V_47 = 0 ;
F_60 (slot, &domain->revmap_tree, &iter, 0 )
V_47 ++ ;
F_59 ( V_58 , L_27 ,
V_10 == V_20 ? '*' : ' ' , V_10 -> V_18 ,
V_10 -> V_13 + V_47 , V_10 -> V_13 ,
V_10 -> V_14 ,
V_10 -> V_3 ? F_37 ( V_10 -> V_3 ) : L_28 ) ;
}
F_10 ( & V_15 ) ;
F_59 ( V_58 , L_29 , L_30 , L_31 ,
L_32 , ( int ) ( 2 * sizeof( void * ) + 2 ) , L_33 ,
L_34 , L_35 , L_36 ) ;
for ( V_48 = 1 ; V_48 < V_66 ; V_48 ++ ) {
V_62 = F_61 ( V_48 ) ;
if ( ! V_62 )
continue;
F_62 ( & V_62 -> V_67 , V_60 ) ;
V_10 = V_62 -> V_33 . V_10 ;
if ( V_10 ) {
struct V_68 * V_44 ;
int V_34 = V_62 -> V_33 . V_34 ;
bool V_69 ;
F_59 ( V_58 , L_37 , V_48 ) ;
F_59 ( V_58 , L_38 , V_34 ) ;
V_44 = F_63 ( V_62 ) ;
F_59 ( V_58 , L_39 , ( V_44 && V_44 -> V_18 ) ? V_44 -> V_18 : L_40 ) ;
V_56 = F_64 ( V_62 ) ;
F_59 ( V_58 , V_56 ? L_41 : L_42 , V_56 ) ;
F_59 ( V_58 , L_43 , ( V_62 -> V_70 && V_62 -> V_70 -> V_71 ) ? '*' : ' ' ) ;
V_69 = ( V_48 == V_34 ) && ( V_48 < V_10 -> V_14 ) ;
F_59 ( V_58 , L_44 ,
( V_34 < V_10 -> V_13 ) ? L_45 : L_46 ,
V_69 ? L_47 : L_28 ) ;
F_59 ( V_58 , L_48 , V_62 -> V_33 . V_10 -> V_18 ) ;
}
F_65 ( & V_62 -> V_67 , V_60 ) ;
}
return 0 ;
}
static int F_66 ( struct V_72 * V_72 , struct V_73 * V_73 )
{
return F_67 ( V_73 , F_58 , V_72 -> V_74 ) ;
}
static int T_2 F_68 ( void )
{
if ( F_69 ( L_49 , V_75 , NULL ,
NULL , & V_76 ) == NULL )
return - V_77 ;
return 0 ;
}
int F_70 ( struct V_1 * V_78 , struct V_2 * V_79 ,
const T_3 * V_80 , unsigned int V_81 ,
unsigned long * V_82 , unsigned int * V_83 )
{
if ( F_4 ( V_81 < 1 ) )
return - V_41 ;
* V_82 = V_80 [ 0 ] ;
* V_83 = V_51 ;
return 0 ;
}
int F_71 ( struct V_1 * V_78 , struct V_2 * V_79 ,
const T_3 * V_80 , unsigned int V_81 ,
T_1 * V_82 , unsigned int * V_83 )
{
if ( F_4 ( V_81 < 2 ) )
return - V_41 ;
* V_82 = V_80 [ 0 ] ;
* V_83 = V_80 [ 1 ] & V_84 ;
return 0 ;
}
int F_72 ( struct V_1 * V_78 ,
struct V_2 * V_79 ,
const T_3 * V_80 , unsigned int V_81 ,
unsigned long * V_82 , unsigned int * V_83 )
{
if ( F_4 ( V_81 < 1 ) )
return - V_41 ;
* V_82 = V_80 [ 0 ] ;
* V_83 = ( V_81 > 1 ) ? V_80 [ 1 ] : V_51 ;
return 0 ;
}
static int F_44 ( int V_39 , unsigned int V_85 ,
T_1 V_34 , int V_25 )
{
unsigned int V_86 ;
if ( V_39 >= 0 ) {
V_39 = F_20 ( V_39 , V_39 , V_85 , V_25 ) ;
} else {
V_86 = V_34 % V_66 ;
if ( V_86 == 0 )
V_86 ++ ;
V_39 = F_73 ( V_86 , V_85 , V_25 ) ;
if ( V_39 <= 0 && V_86 > 1 )
V_39 = F_73 ( 1 , V_85 , V_25 ) ;
}
return V_39 ;
}
struct V_1 * F_74 ( struct V_1 * V_87 ,
unsigned int V_60 ,
unsigned int V_4 ,
struct V_2 * V_25 ,
const struct V_7 * V_8 ,
void * V_9 )
{
struct V_1 * V_10 ;
if ( V_4 )
V_10 = F_75 ( V_25 , V_4 , V_8 , V_9 ) ;
else
V_10 = F_76 ( V_25 , V_8 , V_9 ) ;
if ( V_10 ) {
V_10 -> V_87 = V_87 ;
V_10 -> V_60 |= V_60 ;
}
return V_10 ;
}
static void F_77 ( int V_39 )
{
struct V_33 * V_56 ;
for ( V_56 = F_27 ( V_39 ) ; V_56 ; V_56 = V_56 -> V_88 ) {
struct V_1 * V_10 = V_56 -> V_10 ;
T_1 V_34 = V_56 -> V_34 ;
if ( V_34 < V_10 -> V_13 ) {
V_10 -> V_37 [ V_34 ] = V_39 ;
} else {
F_8 ( & V_38 ) ;
F_35 ( & V_10 -> V_12 , V_34 , V_56 ) ;
F_10 ( & V_38 ) ;
}
if ( ! V_10 -> V_18 && V_56 -> V_44 )
V_10 -> V_18 = V_56 -> V_44 -> V_18 ;
}
F_36 ( V_39 , V_35 ) ;
}
static void F_78 ( int V_39 )
{
struct V_33 * V_56 ;
F_29 ( V_39 , V_35 ) ;
F_30 ( V_39 , NULL , NULL ) ;
F_31 ( V_39 ) ;
F_32 () ;
for ( V_56 = F_27 ( V_39 ) ; V_56 ; V_56 = V_56 -> V_88 ) {
struct V_1 * V_10 = V_56 -> V_10 ;
T_1 V_34 = V_56 -> V_34 ;
if ( V_34 < V_10 -> V_13 ) {
V_10 -> V_37 [ V_34 ] = 0 ;
} else {
F_8 ( & V_38 ) ;
F_33 ( & V_10 -> V_12 , V_34 ) ;
F_10 ( & V_38 ) ;
}
}
}
static struct V_33 * F_79 ( struct V_1 * V_10 ,
struct V_33 * V_89 )
{
struct V_33 * V_33 ;
V_33 = F_2 ( sizeof( * V_33 ) , V_11 ,
F_80 ( V_89 ) ) ;
if ( V_33 ) {
V_89 -> V_88 = V_33 ;
V_33 -> V_32 = V_89 -> V_32 ;
V_33 -> V_90 = V_89 -> V_90 ;
V_33 -> V_10 = V_10 ;
}
return V_33 ;
}
static void F_81 ( unsigned int V_39 , unsigned int V_66 )
{
struct V_33 * V_33 , * V_91 ;
int V_48 ;
for ( V_48 = 0 ; V_48 < V_66 ; V_48 ++ ) {
V_33 = F_27 ( V_39 + V_48 ) ;
V_91 = V_33 -> V_88 ;
V_33 -> V_88 = NULL ;
V_33 -> V_10 = NULL ;
while ( V_91 ) {
V_33 = V_91 ;
V_91 = V_91 -> V_88 ;
F_17 ( V_33 ) ;
}
}
}
static int F_82 ( struct V_1 * V_10 ,
unsigned int V_39 , unsigned int V_66 )
{
struct V_33 * V_33 ;
struct V_1 * V_87 ;
int V_48 ;
for ( V_48 = 0 ; V_48 < V_66 ; V_48 ++ ) {
V_33 = F_27 ( V_39 + V_48 ) ;
V_33 -> V_10 = V_10 ;
for ( V_87 = V_10 -> V_87 ; V_87 ; V_87 = V_87 -> V_87 ) {
V_33 = F_79 ( V_87 , V_33 ) ;
if ( ! V_33 ) {
F_81 ( V_39 , V_48 + 1 ) ;
return - V_77 ;
}
}
}
return 0 ;
}
struct V_33 * F_54 ( struct V_1 * V_10 ,
unsigned int V_39 )
{
struct V_33 * V_33 ;
for ( V_33 = F_27 ( V_39 ) ; V_33 ;
V_33 = V_33 -> V_88 )
if ( V_33 -> V_10 == V_10 )
return V_33 ;
return NULL ;
}
int F_83 ( struct V_1 * V_10 , unsigned int V_39 ,
T_1 V_34 , struct V_68 * V_44 ,
void * V_92 )
{
struct V_33 * V_33 = F_54 ( V_10 , V_39 ) ;
if ( ! V_33 )
return - V_93 ;
V_33 -> V_34 = V_34 ;
V_33 -> V_44 = V_44 ? V_44 : & V_94 ;
V_33 -> V_92 = V_92 ;
return 0 ;
}
void F_84 ( struct V_1 * V_10 , unsigned int V_39 ,
T_1 V_34 , struct V_68 * V_44 ,
void * V_92 , T_4 V_71 ,
void * V_95 , const char * V_96 )
{
F_83 ( V_10 , V_39 , V_34 , V_44 , V_92 ) ;
F_85 ( V_39 , V_71 , 0 , V_96 ) ;
F_86 ( V_39 , V_95 ) ;
}
void F_87 ( struct V_33 * V_33 )
{
V_33 -> V_34 = 0 ;
V_33 -> V_44 = & V_94 ;
V_33 -> V_92 = NULL ;
}
void F_88 ( struct V_1 * V_10 , unsigned int V_39 ,
unsigned int V_66 )
{
struct V_33 * V_33 ;
int V_48 ;
for ( V_48 = 0 ; V_48 < V_66 ; V_48 ++ ) {
V_33 = F_54 ( V_10 , V_39 + V_48 ) ;
if ( V_33 )
F_87 ( V_33 ) ;
}
F_89 ( V_10 , V_39 , V_66 ) ;
}
void F_90 ( struct V_1 * V_10 , unsigned int V_39 ,
unsigned int V_66 )
{
int V_48 ;
for ( V_48 = 0 ; V_48 < V_66 ; V_48 ++ ) {
F_86 ( V_39 + V_48 , NULL ) ;
F_91 ( V_39 + V_48 , NULL ) ;
}
F_88 ( V_10 , V_39 , V_66 ) ;
}
static bool F_92 ( struct V_1 * V_10 )
{
return V_10 -> V_60 & V_97 ;
}
static void F_93 ( struct V_1 * V_10 ,
unsigned int V_45 ,
unsigned int V_66 )
{
V_10 -> V_8 -> free ( V_10 , V_45 , V_66 ) ;
if ( F_92 ( V_10 ) ) {
F_94 ( ! V_10 -> V_87 ) ;
F_93 ( V_10 -> V_87 , V_45 ,
V_66 ) ;
}
}
static int F_95 ( struct V_1 * V_10 ,
unsigned int V_45 ,
unsigned int V_66 , void * V_98 )
{
int V_40 = 0 ;
struct V_1 * V_87 = V_10 -> V_87 ;
bool V_99 = F_92 ( V_10 ) ;
F_94 ( V_99 && ! V_87 ) ;
if ( V_99 )
V_40 = F_95 ( V_87 , V_45 ,
V_66 , V_98 ) ;
if ( V_40 >= 0 )
V_40 = V_10 -> V_8 -> V_100 ( V_10 , V_45 , V_66 , V_98 ) ;
if ( V_40 < 0 && V_99 )
F_93 ( V_87 , V_45 , V_66 ) ;
return V_40 ;
}
int F_96 ( struct V_1 * V_10 , int V_45 ,
unsigned int V_66 , int V_25 , void * V_98 ,
bool realloc )
{
int V_48 , V_40 , V_39 ;
if ( V_10 == NULL ) {
V_10 = V_20 ;
if ( F_28 ( ! V_10 , L_50 ) )
return - V_41 ;
}
if ( ! V_10 -> V_8 -> V_100 ) {
F_11 ( L_51 ) ;
return - V_101 ;
}
if ( realloc && V_45 >= 0 ) {
V_39 = V_45 ;
} else {
V_39 = F_44 ( V_45 , V_66 , 0 , V_25 ) ;
if ( V_39 < 0 ) {
F_11 ( L_52 ,
V_45 , V_66 ) ;
return V_39 ;
}
}
if ( F_82 ( V_10 , V_39 , V_66 ) ) {
F_11 ( L_53 , V_39 ) ;
V_40 = - V_77 ;
goto V_102;
}
F_8 ( & V_15 ) ;
V_40 = F_95 ( V_10 , V_39 , V_66 , V_98 ) ;
if ( V_40 < 0 ) {
F_10 ( & V_15 ) ;
goto V_103;
}
for ( V_48 = 0 ; V_48 < V_66 ; V_48 ++ )
F_77 ( V_39 + V_48 ) ;
F_10 ( & V_15 ) ;
return V_39 ;
V_103:
F_81 ( V_39 , V_66 ) ;
V_102:
F_97 ( V_39 , V_66 ) ;
return V_40 ;
}
void F_98 ( unsigned int V_39 , unsigned int V_66 )
{
struct V_33 * V_56 = F_27 ( V_39 ) ;
int V_48 ;
if ( F_28 ( ! V_56 || ! V_56 -> V_10 || ! V_56 -> V_10 -> V_8 -> free ,
L_54 ) )
return;
F_8 ( & V_15 ) ;
for ( V_48 = 0 ; V_48 < V_66 ; V_48 ++ )
F_78 ( V_39 + V_48 ) ;
F_93 ( V_56 -> V_10 , V_39 , V_66 ) ;
F_10 ( & V_15 ) ;
F_81 ( V_39 , V_66 ) ;
F_97 ( V_39 , V_66 ) ;
}
int F_99 ( struct V_1 * V_10 ,
unsigned int V_45 , unsigned int V_66 ,
void * V_98 )
{
if ( F_92 ( V_10 ) )
return 0 ;
V_10 = V_10 -> V_87 ;
if ( V_10 )
return F_95 ( V_10 , V_45 ,
V_66 , V_98 ) ;
return - V_101 ;
}
void F_89 ( struct V_1 * V_10 ,
unsigned int V_45 , unsigned int V_66 )
{
if ( ! F_92 ( V_10 ) && V_10 -> V_87 )
F_93 ( V_10 -> V_87 , V_45 ,
V_66 ) ;
}
void F_100 ( struct V_33 * V_33 )
{
if ( V_33 && V_33 -> V_10 ) {
struct V_1 * V_10 = V_33 -> V_10 ;
if ( V_33 -> V_88 )
F_100 ( V_33 -> V_88 ) ;
if ( V_10 -> V_8 -> V_104 )
V_10 -> V_8 -> V_104 ( V_10 , V_33 ) ;
}
}
void F_101 ( struct V_33 * V_33 )
{
if ( V_33 && V_33 -> V_10 ) {
struct V_1 * V_10 = V_33 -> V_10 ;
if ( V_10 -> V_8 -> V_105 )
V_10 -> V_8 -> V_105 ( V_10 , V_33 ) ;
if ( V_33 -> V_88 )
F_101 ( V_33 -> V_88 ) ;
}
}
static void F_7 ( struct V_1 * V_10 )
{
if ( V_10 -> V_8 -> V_100 )
V_10 -> V_60 |= V_106 ;
}
struct V_33 * F_54 ( struct V_1 * V_10 ,
unsigned int V_39 )
{
struct V_33 * V_33 = F_27 ( V_39 ) ;
return ( V_33 && V_33 -> V_10 == V_10 ) ? V_33 : NULL ;
}
void F_84 ( struct V_1 * V_10 , unsigned int V_39 ,
T_1 V_34 , struct V_68 * V_44 ,
void * V_92 , T_4 V_71 ,
void * V_95 , const char * V_96 )
{
F_102 ( V_39 , V_44 , V_71 , V_96 ) ;
F_103 ( V_39 , V_92 ) ;
F_86 ( V_39 , V_95 ) ;
}
static void F_7 ( struct V_1 * V_10 )
{
}
