static struct V_1 * F_1 ( struct V_1 * V_2 )
{
while ( V_2 -> V_3 != NULL )
V_2 = V_2 -> V_3 ;
return V_2 ;
}
static void F_2 ( struct V_1 * V_2 )
{
F_3 ( F_4 ( & V_2 -> V_4 ) > 0 ) ;
F_5 ( & V_2 -> V_4 ) ;
}
static const struct V_5 *
F_6 ( const struct V_1 * V_2 ,
const struct V_6 * V_7 )
{
const struct V_5 * V_8 ;
V_9 ;
V_2 = F_1 ( (struct V_1 * ) V_2 ) ;
do {
F_7 (slice, &page->cp_layers, cpl_linkage) {
if ( V_8 -> V_10 -> V_11 . V_12 -> V_13 == V_7 )
RETURN ( V_8 ) ;
}
V_2 = V_2 -> V_14 ;
} while ( V_2 != NULL );
RETURN ( NULL ) ;
}
struct V_1 * F_8 ( struct V_15 * V_16 , T_1 V_17 )
{
struct V_1 * V_2 ;
F_3 ( F_9 ( & V_16 -> V_18 ) ) ;
V_2 = F_10 ( & V_16 -> V_19 , V_17 ) ;
if ( V_2 != NULL )
F_2 ( V_2 ) ;
return V_2 ;
}
int F_11 ( const struct V_20 * V_21 , struct V_22 * V_23 ,
struct V_24 * V_25 , T_1 V_26 , T_1 V_27 ,
T_2 V_28 , void * V_29 )
{
struct V_15 * V_16 ;
struct V_1 * V_2 ;
struct V_1 * * V_30 ;
const struct V_5 * V_8 ;
const struct V_6 * V_7 ;
T_1 V_31 ;
unsigned int V_32 ;
unsigned int V_33 ;
unsigned int V_34 ;
int V_35 = V_36 ;
int V_37 = 1 ;
V_9 ;
V_31 = V_26 ;
V_16 = V_15 ( V_23 ) ;
V_30 = F_12 ( V_21 ) -> V_38 ;
V_7 = F_13 ( V_23 ) -> V_11 . V_12 -> V_13 ;
F_14 ( & V_16 -> V_18 ) ;
while ( ( V_32 = F_15 ( & V_16 -> V_19 , ( void * * ) V_30 ,
V_31 , V_39 ) ) > 0 ) {
int V_40 = 0 ;
V_31 = V_30 [ V_32 - 1 ] -> V_41 + 1 ;
for ( V_33 = 0 , V_34 = 0 ; V_33 < V_32 ; ++ V_33 ) {
V_2 = V_30 [ V_33 ] ;
V_30 [ V_33 ] = NULL ;
F_3 ( V_2 -> V_42 == V_43 ) ;
if ( V_2 -> V_41 > V_27 ) {
V_40 = 1 ;
break;
}
if ( V_2 -> V_44 == V_45 )
continue;
V_8 = F_6 ( V_2 , V_7 ) ;
F_16 ( V_21 , V_2 , V_8 != NULL ) ;
V_2 = V_8 -> V_46 ;
F_2 ( V_2 ) ;
F_17 ( & V_2 -> V_47 ,
L_1 , V_48 ) ;
V_30 [ V_34 ++ ] = V_2 ;
}
F_18 ( & V_16 -> V_18 ) ;
V_37 = 0 ;
for ( V_33 = 0 ; V_33 < V_34 ; ++ V_33 ) {
V_2 = V_30 [ V_33 ] ;
if ( V_35 == V_36 )
V_35 = (* V_28)( V_21 , V_25 , V_2 , V_29 ) ;
F_19 ( & V_2 -> V_47 ,
L_1 , V_48 ) ;
F_20 ( V_21 , V_2 ) ;
}
if ( V_32 < V_39 || V_40 )
break;
if ( V_35 == V_36 && F_21 () )
V_35 = V_49 ;
if ( V_35 != V_36 )
break;
F_14 ( & V_16 -> V_18 ) ;
V_37 = 1 ;
}
if ( V_37 )
F_18 ( & V_16 -> V_18 ) ;
RETURN ( V_35 ) ;
}
static void F_22 ( const struct V_20 * V_21 , struct V_1 * V_2 )
{
struct V_22 * V_23 = V_2 -> V_50 ;
int V_51 = V_15 ( V_23 ) -> V_52 ;
F_16 ( V_21 , V_2 , F_23 ( & V_2 -> V_53 ) ) ;
F_16 ( V_21 , V_2 , V_2 -> V_54 == NULL ) ;
F_16 ( V_21 , V_2 , V_2 -> V_55 == NULL ) ;
F_16 ( V_21 , V_2 , V_2 -> V_3 == NULL ) ;
F_16 ( V_21 , V_2 , V_2 -> V_44 == V_45 ) ;
V_9 ;
F_24 () ;
while ( ! F_23 ( & V_2 -> V_56 ) ) {
struct V_5 * V_8 ;
V_8 = F_25 ( V_2 -> V_56 . V_57 ,
struct V_5 , V_58 ) ;
F_26 ( V_2 -> V_56 . V_57 ) ;
V_8 -> V_59 -> V_60 ( V_21 , V_8 ) ;
}
F_27 ( V_23 , V_61 ) ;
F_28 ( V_23 , V_2 -> V_44 ) ;
F_29 ( & V_23 -> V_11 , V_2 -> V_62 , L_2 , V_2 ) ;
F_30 ( V_21 , V_23 ) ;
F_31 ( & V_2 -> V_47 ) ;
F_32 ( V_2 , V_51 ) ;
EXIT ;
}
static inline void F_33 ( struct V_1 * V_2 ,
enum V_63 V_64 )
{
* (enum V_63 * ) & V_2 -> V_44 = V_64 ;
}
static struct V_1 * F_34 ( const struct V_20 * V_21 ,
struct V_22 * V_65 , T_1 V_66 , struct V_2 * V_67 ,
enum V_68 type )
{
struct V_1 * V_2 ;
struct V_69 * V_70 ;
V_9 ;
F_35 ( V_2 , V_15 ( V_65 ) -> V_52 ,
V_71 ) ;
if ( V_2 != NULL ) {
int V_72 = 0 ;
F_36 ( & V_2 -> V_4 , 1 ) ;
if ( type == V_43 )
F_5 ( & V_2 -> V_4 ) ;
V_2 -> V_50 = V_65 ;
F_37 ( V_65 ) ;
V_2 -> V_62 = F_38 ( & V_65 -> V_11 , L_2 , V_2 ) ;
V_2 -> V_41 = V_66 ;
F_33 ( V_2 , V_73 ) ;
V_2 -> V_42 = type ;
F_39 ( & V_2 -> V_56 ) ;
F_39 ( & V_2 -> V_53 ) ;
F_39 ( & V_2 -> V_74 ) ;
F_40 ( & V_2 -> V_75 ) ;
F_41 ( & V_2 -> V_47 ) ;
V_70 = V_65 -> V_11 . V_76 ;
F_7 (o, &head->loh_layers,
co_lu.lo_linkage) {
if ( V_65 -> V_77 -> V_78 != NULL ) {
V_72 = V_65 -> V_77 -> V_78 ( V_21 , V_65 ,
V_2 , V_67 ) ;
if ( V_72 != 0 ) {
F_42 ( V_21 , V_2 , 0 ) ;
F_22 ( V_21 , V_2 ) ;
V_2 = F_43 ( V_72 ) ;
break;
}
}
}
if ( V_72 == 0 ) {
F_44 ( V_65 , V_61 ) ;
F_44 ( V_65 , V_79 ) ;
F_28 ( V_65 , V_73 ) ;
}
} else {
V_2 = F_43 ( - V_80 ) ;
}
RETURN ( V_2 ) ;
}
static struct V_1 * F_45 ( const struct V_20 * V_21 ,
struct V_22 * V_65 ,
T_1 V_31 , struct V_2 * V_67 ,
enum V_68 type ,
struct V_1 * V_81 )
{
struct V_1 * V_2 = NULL ;
struct V_1 * V_82 = NULL ;
struct V_15 * V_16 ;
int V_83 ;
F_3 ( type == V_43 || type == V_84 ) ;
F_24 () ;
V_9 ;
V_16 = V_15 ( V_65 ) ;
F_44 ( V_65 , V_85 ) ;
F_46 ( V_86 , L_3 V_87 L_4 ,
V_31 , F_47 ( & V_16 -> V_88 . V_89 ) , V_67 , V_67 -> V_90 , type ) ;
if ( type == V_43 ) {
F_48 ( F_49 ( V_67 ) ) ;
V_2 = F_50 ( V_67 , V_65 ) ;
F_51 ( V_21 , V_2 ,
F_52 ( V_2 != NULL ,
F_53 ( V_21 , V_2 ) == V_67 &&
( void * ) F_10 ( & V_16 -> V_19 ,
V_31 ) == V_2 ) ) ;
}
if ( V_2 != NULL ) {
F_44 ( V_65 , V_91 ) ;
RETURN ( V_2 ) ;
}
V_2 = F_34 ( V_21 , V_65 , V_31 , V_67 , type ) ;
if ( F_54 ( V_2 ) )
RETURN ( V_2 ) ;
if ( type == V_84 ) {
if ( V_81 ) {
F_3 ( V_2 -> V_3 == NULL ) ;
V_2 -> V_3 = V_81 ;
V_81 -> V_14 = V_2 ;
}
RETURN ( V_2 ) ;
}
F_14 ( & V_16 -> V_18 ) ;
V_83 = F_55 ( & V_16 -> V_19 , V_31 , V_2 ) ;
if ( V_83 != 0 ) {
V_82 = V_2 ;
V_2 = F_43 ( V_83 ) ;
F_56 ( V_92 , V_21 , V_82 ,
L_5 , V_83 ) ;
} else {
if ( V_81 ) {
F_3 ( V_2 -> V_3 == NULL ) ;
V_2 -> V_3 = V_81 ;
V_81 -> V_14 = V_2 ;
}
V_16 -> V_93 ++ ;
}
F_18 ( & V_16 -> V_18 ) ;
if ( F_57 ( V_82 != NULL ) ) {
F_42 ( V_21 , V_82 , 0 ) ;
F_22 ( V_21 , V_82 ) ;
}
RETURN ( V_2 ) ;
}
struct V_1 * F_58 ( const struct V_20 * V_21 , struct V_22 * V_65 ,
T_1 V_31 , struct V_2 * V_67 ,
enum V_68 type )
{
return F_45 ( V_21 , V_65 , V_31 , V_67 , type , NULL ) ;
}
struct V_1 * F_59 ( const struct V_20 * V_21 , struct V_22 * V_65 ,
T_1 V_31 , struct V_2 * V_67 ,
struct V_1 * V_81 )
{
return F_45 ( V_21 , V_65 , V_31 , V_67 , V_81 -> V_42 , V_81 ) ;
}
static inline int F_60 ( const struct V_1 * V_94 )
{
struct V_15 * V_95 ;
struct V_1 * V_81 ;
struct V_1 * V_96 ;
struct V_24 * V_97 ;
F_61 ( F_62 ( NULL , V_94 ) ) ;
V_95 = V_15 ( V_94 -> V_50 ) ;
V_81 = V_94 -> V_3 ;
V_96 = V_94 -> V_14 ;
V_97 = V_94 -> V_54 ;
return F_63 ( V_94 ) &&
F_52 ( V_81 != NULL , V_81 -> V_14 == V_94 ) &&
F_52 ( V_96 != NULL , V_96 -> V_3 == V_94 ) &&
F_52 ( V_96 != NULL , V_94 -> V_50 != V_96 -> V_50 ) &&
F_52 ( V_81 != NULL , V_94 -> V_50 != V_81 -> V_50 ) &&
F_52 ( V_97 != NULL && V_81 != NULL ,
V_81 -> V_54 == V_94 -> V_54 -> V_98 ) &&
F_52 ( V_97 != NULL && V_96 != NULL ,
V_96 -> V_54 -> V_98 == V_97 ) &&
F_52 ( V_94 -> V_44 < V_45 && V_94 -> V_42 == V_43 ,
( void * ) F_10 ( & V_95 -> V_19 ,
V_94 -> V_41 ) == V_94 ||
( V_96 == NULL && V_81 == NULL ) ) ;
}
static void F_64 ( const struct V_20 * V_21 ,
struct V_1 * V_2 , enum V_63 V_64 )
{
enum V_63 V_99 ;
static const int V_100 [ V_101 ] [ V_101 ] = {
[ V_73 ] = {
[ V_73 ] = 0 ,
[ V_102 ] = 1 ,
[ V_103 ] = 0 ,
[ V_104 ] = 1 ,
[ V_45 ] = 1 ,
} ,
[ V_102 ] = {
[ V_73 ] = 1 ,
[ V_102 ] = 0 ,
[ V_103 ] = 1 ,
[ V_104 ] = 1 ,
[ V_45 ] = 1 ,
} ,
[ V_103 ] = {
[ V_73 ] = 1 ,
[ V_102 ] = 0 ,
[ V_103 ] = 0 ,
[ V_104 ] = 0 ,
[ V_45 ] = 0 ,
} ,
[ V_104 ] = {
[ V_73 ] = 1 ,
[ V_102 ] = 0 ,
[ V_103 ] = 0 ,
[ V_104 ] = 0 ,
[ V_45 ] = 0 ,
} ,
[ V_45 ] = {
[ V_73 ] = 0 ,
[ V_102 ] = 0 ,
[ V_103 ] = 0 ,
[ V_104 ] = 0 ,
[ V_45 ] = 0 ,
}
} ;
V_9 ;
V_99 = V_2 -> V_44 ;
F_16 ( V_21 , V_2 , V_100 [ V_99 ] [ V_64 ] ) ;
F_65 ( V_105 , V_21 , V_2 , L_6 , V_99 , V_64 ) ;
for (; V_2 != NULL ; V_2 = V_2 -> V_14 ) {
F_16 ( V_21 , V_2 , V_2 -> V_44 == V_99 ) ;
F_16 ( V_21 , V_2 ,
F_66 ( V_64 == V_102 , V_2 -> V_54 != NULL ) ) ;
F_28 ( V_2 -> V_50 , V_2 -> V_44 ) ;
F_67 ( V_2 -> V_50 , V_64 ) ;
F_33 ( V_2 , V_64 ) ;
}
EXIT ;
}
static void F_68 ( const struct V_20 * V_21 ,
struct V_1 * V_2 , enum V_63 V_64 )
{
F_64 ( V_21 , V_2 , V_64 ) ;
}
void F_69 ( struct V_1 * V_2 )
{
V_9 ;
F_2 ( V_2 ) ;
EXIT ;
}
void F_20 ( const struct V_20 * V_21 , struct V_1 * V_2 )
{
F_16 ( V_21 , V_2 , F_4 ( & V_2 -> V_4 ) > ! ! V_2 -> V_3 ) ;
V_9 ;
F_65 ( V_105 , V_21 , V_2 , L_7 ,
F_4 ( & V_2 -> V_4 ) ) ;
if ( F_70 ( & V_2 -> V_4 ) ) {
F_3 ( V_2 -> V_44 == V_45 ) ;
F_3 ( F_4 ( & V_2 -> V_4 ) == 0 ) ;
F_16 ( V_21 , V_2 , V_2 -> V_54 == NULL ) ;
F_16 ( V_21 , V_2 , F_23 ( & V_2 -> V_53 ) ) ;
F_22 ( V_21 , V_2 ) ;
}
EXIT ;
}
struct V_2 * F_53 ( const struct V_20 * V_21 , struct V_1 * V_2 )
{
const struct V_5 * V_8 ;
V_2 = F_71 ( V_2 ) ;
do {
F_7 (slice, &page->cp_layers, cpl_linkage) {
if ( V_8 -> V_59 -> V_106 != NULL )
RETURN ( V_8 -> V_59 -> V_106 ( V_21 , V_8 ) ) ;
}
V_2 = V_2 -> V_14 ;
} while ( V_2 != NULL );
F_72 () ;
}
struct V_1 * F_50 ( struct V_2 * V_67 , struct V_22 * V_23 )
{
struct V_1 * V_107 ;
struct V_1 * V_2 ;
V_9 ;
F_48 ( F_49 ( V_67 ) ) ;
V_107 = (struct V_1 * ) V_67 -> V_90 ;
if ( V_107 == NULL )
RETURN ( NULL ) ;
for ( V_2 = V_107 ; V_2 != NULL ; V_2 = V_2 -> V_14 ) {
if ( F_73 ( V_2 -> V_50 , V_23 ) ) {
F_2 ( V_2 ) ;
break;
}
}
F_3 ( F_52 ( V_2 , V_2 -> V_42 == V_43 ) ) ;
RETURN ( V_2 ) ;
}
struct V_1 * F_71 ( struct V_1 * V_2 )
{
return F_1 ( V_2 ) ;
}
const struct V_5 * F_74 ( const struct V_1 * V_2 ,
const struct V_6 * V_7 )
{
return F_6 ( V_2 , V_7 ) ;
}
static int F_75 ( const struct V_20 * V_21 ,
struct V_24 * V_25 , struct V_1 * V_2 , T_3 V_108 )
{
F_51 ( V_21 , V_2 , F_73 ( V_2 -> V_50 , V_25 -> V_109 ) ) ;
V_9 ;
RETURN ( F_76 ( V_21 , V_2 , V_108 ,
( const struct V_20 * ,
const struct V_5 * , struct V_24 * ) ,
V_25 ) ) ;
}
static void F_77 ( const struct V_20 * V_21 ,
struct V_24 * V_25 , struct V_1 * V_2 , T_3 V_108 )
{
F_51 ( V_21 , V_2 , F_73 ( V_2 -> V_50 , V_25 -> V_109 ) ) ;
V_9 ;
F_78 ( V_21 , V_2 , V_108 ,
( const struct V_20 * ,
const struct V_5 * , struct V_24 * ) , V_25 ) ;
EXIT ;
}
static void F_79 ( struct V_1 * V_2 )
{
V_9 ;
for ( V_2 = F_71 ( V_2 ) ; V_2 != NULL ; V_2 = V_2 -> V_14 ) {
if ( V_2 -> V_54 != NULL ) {
F_3 ( V_2 -> V_54 -> V_110 > 0 ) ;
V_2 -> V_54 -> V_110 -- ;
V_2 -> V_54 = NULL ;
V_2 -> V_111 = NULL ;
}
}
EXIT ;
}
static void F_80 ( struct V_1 * V_2 )
{
V_9 ;
for ( V_2 = F_71 ( V_2 ) ; V_2 != NULL ; V_2 = V_2 -> V_14 ) {
F_3 ( V_2 -> V_54 != NULL ) ;
V_2 -> V_54 -> V_110 ++ ;
}
EXIT ;
}
void F_81 ( const struct V_20 * V_21 ,
struct V_24 * V_25 , struct V_1 * V_94 )
{
enum V_63 V_64 ;
V_9 ;
V_64 = V_94 -> V_44 ;
F_51 ( V_21 , V_94 , V_64 == V_102 || V_64 == V_45 ) ;
F_51 ( V_21 , V_94 , F_60 ( V_94 ) ) ;
F_79 ( V_94 ) ;
if ( V_64 == V_102 )
F_68 ( V_21 , V_94 , V_73 ) ;
F_82 ( V_21 , V_94 , F_83 ( V_112 ) ,
( const struct V_20 * ,
const struct V_5 * , struct V_24 * ) ,
V_25 ) ;
EXIT ;
}
int F_84 ( const struct V_1 * V_94 , const struct V_24 * V_25 )
{
F_61 ( F_73 ( V_94 -> V_50 , V_25 -> V_109 ) ) ;
V_9 ;
RETURN ( V_94 -> V_44 == V_102 && V_94 -> V_54 == V_25 ) ;
}
static int F_85 ( const struct V_20 * V_21 , struct V_24 * V_25 ,
struct V_1 * V_94 , int V_113 )
{
int V_72 ;
F_51 ( V_21 , V_94 , ! F_84 ( V_94 , V_25 ) ) ;
V_9 ;
V_94 = F_71 ( V_94 ) ;
V_25 = F_86 ( V_25 ) ;
if ( V_94 -> V_44 == V_45 ) {
V_72 = - V_114 ;
} else {
V_72 = F_76 ( V_21 , V_94 , F_83 ( V_115 ) ,
( const struct V_20 * ,
const struct V_5 * ,
struct V_24 * , int ) ,
V_25 , V_113 ) ;
if ( V_72 == 0 ) {
F_16 ( V_21 , V_94 , V_94 -> V_54 == NULL ) ;
F_16 ( V_21 , V_94 , V_94 -> V_55 == NULL ) ;
V_94 -> V_54 = V_25 ;
V_94 -> V_111 = V_48 ;
F_80 ( V_94 ) ;
if ( V_94 -> V_44 != V_45 ) {
F_68 ( V_21 , V_94 , V_102 ) ;
} else {
F_81 ( V_21 , V_25 , V_94 ) ;
V_72 = - V_114 ;
}
}
}
F_51 ( V_21 , V_94 , F_52 ( V_72 == 0 , F_60 ( V_94 ) ) ) ;
RETURN ( V_72 ) ;
}
int F_87 ( const struct V_20 * V_21 , struct V_24 * V_25 , struct V_1 * V_94 )
{
return F_85 ( V_21 , V_25 , V_94 , 0 ) ;
}
int F_88 ( const struct V_20 * V_21 , struct V_24 * V_25 ,
struct V_1 * V_94 )
{
return F_85 ( V_21 , V_25 , V_94 , 1 ) ;
}
void F_89 ( const struct V_20 * V_21 ,
struct V_24 * V_25 , struct V_1 * V_94 )
{
F_51 ( V_21 , V_94 , F_73 ( V_94 -> V_50 , V_25 -> V_109 ) ) ;
V_9 ;
V_94 = F_71 ( V_94 ) ;
V_25 = F_86 ( V_25 ) ;
F_77 ( V_21 , V_25 , V_94 , F_83 ( V_116 ) ) ;
F_16 ( V_21 , V_94 , V_94 -> V_54 == NULL ) ;
V_94 -> V_54 = V_25 ;
V_94 -> V_111 = V_48 ;
F_80 ( V_94 ) ;
F_68 ( V_21 , V_94 , V_102 ) ;
EXIT ;
}
void F_90 ( const struct V_20 * V_21 ,
struct V_24 * V_25 , struct V_1 * V_94 )
{
F_51 ( V_21 , V_94 , F_84 ( V_94 , V_25 ) ) ;
F_51 ( V_21 , V_94 , F_60 ( V_94 ) ) ;
V_9 ;
V_94 = F_71 ( V_94 ) ;
V_25 = F_86 ( V_25 ) ;
F_79 ( V_94 ) ;
F_68 ( V_21 , V_94 , V_73 ) ;
F_82 ( V_21 , V_94 , F_83 ( V_117 ) ,
( const struct V_20 * ,
const struct V_5 * , struct V_24 * ) ,
V_25 ) ;
EXIT ;
}
void F_91 ( const struct V_20 * V_21 ,
struct V_24 * V_25 , struct V_1 * V_94 )
{
F_51 ( V_21 , V_94 , F_84 ( V_94 , V_25 ) ) ;
V_9 ;
V_94 = F_71 ( V_94 ) ;
V_25 = F_86 ( V_25 ) ;
F_81 ( V_21 , V_25 , V_94 ) ;
EXIT ;
}
void F_92 ( const struct V_20 * V_21 ,
struct V_24 * V_25 , struct V_1 * V_94 )
{
F_51 ( V_21 , V_94 , F_84 ( V_94 , V_25 ) ) ;
F_51 ( V_21 , V_94 , F_60 ( V_94 ) ) ;
F_77 ( V_21 , V_25 , V_94 , F_83 ( V_118 ) ) ;
}
static void F_42 ( const struct V_20 * V_21 , struct V_1 * V_94 ,
int V_119 )
{
struct V_1 * V_120 = V_94 ;
V_9 ;
F_16 ( V_21 , V_94 , V_94 == F_71 ( V_94 ) ) ;
F_16 ( V_21 , V_94 , V_94 -> V_44 != V_45 ) ;
F_79 ( V_94 ) ;
F_93 ( V_21 , V_94 , 0 ) ;
F_64 ( V_21 , V_94 , V_45 ) ;
F_78 ( V_21 , V_94 , F_83 ( V_121 ) ,
( const struct V_20 * , const struct V_5 * ) ) ;
if ( V_120 -> V_42 == V_43 ) {
if ( ! V_119 )
V_120 = V_94 -> V_14 ;
for (; V_120 != NULL ; V_120 = V_120 -> V_14 ) {
void * V_122 ;
struct V_15 * V_16 ;
V_16 = V_15 ( V_120 -> V_50 ) ;
F_14 ( & V_16 -> V_18 ) ;
V_122 = F_94 ( & V_16 -> V_19 ,
V_120 -> V_41 ) ;
F_16 ( V_21 , V_120 , V_122 == V_120 ) ;
F_16 ( V_21 , V_120 , V_16 -> V_93 > 0 ) ;
V_16 -> V_93 -- ;
F_18 ( & V_16 -> V_18 ) ;
F_20 ( V_21 , V_120 ) ;
}
}
EXIT ;
}
void F_95 ( const struct V_20 * V_21 , struct V_1 * V_94 )
{
F_51 ( V_21 , V_94 , F_60 ( V_94 ) ) ;
V_9 ;
F_42 ( V_21 , V_94 , 1 ) ;
EXIT ;
}
int F_96 ( const struct V_20 * V_21 ,
struct V_24 * V_25 , struct V_1 * V_94 )
{
F_51 ( V_21 , V_94 , F_84 ( V_94 , V_25 ) ) ;
F_51 ( V_21 , V_94 , F_60 ( V_94 ) ) ;
return F_75 ( V_21 , V_25 , V_94 , F_83 ( V_123 ) ) ;
}
void F_93 ( const struct V_20 * V_21 , struct V_1 * V_94 , int V_124 )
{
F_51 ( V_21 , V_94 , F_60 ( V_94 ) ) ;
F_78 ( V_21 , V_94 , F_83 ( V_125 ) ,
( const struct V_20 * ,
const struct V_5 * , int ) , V_124 ) ;
}
int F_62 ( const struct V_20 * V_21 , const struct V_1 * V_94 )
{
int V_72 ;
const struct V_5 * V_8 ;
V_9 ;
V_94 = F_1 ( (struct V_1 * ) V_94 ) ;
V_8 = F_97 ( V_94 -> V_56 . V_57 ,
const struct V_5 , V_58 ) ;
F_16 ( V_21 , V_94 , V_8 -> V_59 -> V_126 != NULL ) ;
V_72 = V_8 -> V_59 -> V_126 ( V_21 , V_8 ) ;
F_16 ( V_21 , V_94 , V_72 == - V_127 || V_72 == - V_128 ) ;
RETURN ( V_72 == - V_127 ) ;
}
static enum V_63 F_98 ( enum V_129 V_130 )
{
V_9 ;
RETURN ( V_130 == V_131 ? V_104 : V_103 ) ;
}
static void F_99 ( const struct V_20 * V_21 ,
struct V_1 * V_94 , enum V_129 V_130 )
{
V_9 ;
F_79 ( V_94 ) ;
F_68 ( V_21 , V_94 , F_98 ( V_130 ) ) ;
EXIT ;
}
int F_100 ( const struct V_20 * V_21 , struct V_24 * V_25 ,
struct V_1 * V_94 , enum V_129 V_130 )
{
int V_72 ;
F_51 ( V_21 , V_94 , F_84 ( V_94 , V_25 ) ) ;
F_51 ( V_21 , V_94 , F_60 ( V_94 ) ) ;
F_51 ( V_21 , V_94 , V_130 < V_132 ) ;
if ( V_130 >= V_132 )
return - V_133 ;
V_72 = F_75 ( V_21 , V_25 , V_94 , F_83 ( V_25 [ V_130 ] . V_134 ) ) ;
if ( V_72 == 0 )
F_99 ( V_21 , V_94 , V_130 ) ;
F_48 ( F_52 ( V_130 == V_131 && V_94 -> V_42 == V_43 ,
F_66 ( V_72 == 0 ,
F_101 ( F_53 ( V_21 , V_94 ) ) ) ) ) ;
F_65 ( V_105 , V_21 , V_94 , L_8 , V_130 , V_72 ) ;
return V_72 ;
}
void F_102 ( const struct V_20 * V_21 ,
struct V_1 * V_94 , enum V_129 V_130 , int V_135 )
{
struct V_136 * V_137 = V_94 -> V_138 ;
F_16 ( V_21 , V_94 , V_130 < V_132 ) ;
F_16 ( V_21 , V_94 , V_94 -> V_55 == NULL ) ;
F_16 ( V_21 , V_94 , V_94 -> V_44 == F_98 ( V_130 ) ) ;
V_9 ;
F_65 ( V_105 , V_21 , V_94 , L_8 , V_130 , V_135 ) ;
if ( V_130 == V_139 && V_135 == 0 ) {
F_16 ( V_21 , V_94 , ! ( V_94 -> V_140 & V_141 ) ) ;
V_94 -> V_140 |= V_141 ;
}
F_68 ( V_21 , V_94 , V_73 ) ;
if ( V_130 >= V_132 )
return;
F_82 ( V_21 , V_94 , F_83 ( V_25 [ V_130 ] . V_142 ) ,
( const struct V_20 * ,
const struct V_5 * , int ) , V_135 ) ;
if ( V_137 ) {
F_3 ( F_62 ( V_21 , V_94 ) ) ;
F_3 ( V_94 -> V_138 == V_137 ) ;
V_94 -> V_138 = NULL ;
}
F_20 ( V_21 , V_94 ) ;
if ( V_137 )
F_103 ( V_137 , V_135 ) ;
EXIT ;
}
int F_104 ( const struct V_20 * V_21 , struct V_1 * V_94 ,
enum V_129 V_130 )
{
int V_72 ;
F_51 ( V_21 , V_94 , V_130 < V_132 ) ;
V_9 ;
if ( V_130 >= V_132 )
RETURN ( - V_133 ) ;
V_72 = F_76 ( V_21 , V_94 , F_83 ( V_25 [ V_130 ] . V_143 ) ,
( const struct V_20 * ,
const struct V_5 * ) ) ;
if ( V_72 == 0 ) {
F_16 ( V_21 , V_94 , V_94 -> V_44 == V_73 ) ;
F_99 ( V_21 , V_94 , V_130 ) ;
}
F_65 ( V_105 , V_21 , V_94 , L_8 , V_130 , V_72 ) ;
RETURN ( V_72 ) ;
}
int F_105 ( const struct V_20 * V_21 , struct V_24 * V_25 ,
struct V_1 * V_94 , enum V_129 V_130 )
{
const struct V_5 * V_144 ;
int V_72 = 0 ;
F_51 ( V_21 , V_94 , V_130 < V_132 ) ;
F_51 ( V_21 , V_94 , F_84 ( V_94 , V_25 ) ) ;
F_51 ( V_21 , V_94 , F_60 ( V_94 ) ) ;
V_9 ;
if ( V_130 >= V_132 )
RETURN ( - V_133 ) ;
F_7 (scan, &pg->cp_layers, cpl_linkage) {
if ( V_144 -> V_59 -> V_25 [ V_130 ] . V_145 == NULL )
continue;
V_72 = V_144 -> V_59 -> V_25 [ V_130 ] . V_145 ( V_21 , V_144 , V_25 ) ;
if ( V_72 != 0 )
break;
}
F_65 ( V_105 , V_21 , V_94 , L_8 , V_130 , V_72 ) ;
RETURN ( V_72 ) ;
}
int F_106 ( const struct V_20 * V_21 , struct V_24 * V_25 ,
struct V_1 * V_94 )
{
int V_72 ;
F_51 ( V_21 , V_94 , F_84 ( V_94 , V_25 ) ) ;
F_51 ( V_21 , V_94 , F_60 ( V_94 ) ) ;
V_9 ;
V_72 = F_75 ( V_21 , V_25 , V_94 , F_83 ( V_146 ) ) ;
F_65 ( V_105 , V_21 , V_94 , L_7 , V_72 ) ;
RETURN ( V_72 ) ;
}
int F_107 ( const struct V_20 * V_21 , struct V_24 * V_25 ,
struct V_1 * V_2 )
{
int V_147 ;
F_51 ( V_21 , V_2 , F_60 ( V_2 ) ) ;
V_9 ;
V_147 = F_76 ( V_21 , V_2 , F_83 ( V_148 ) ,
( const struct V_20 * ,
const struct V_5 * , struct V_24 * ) ,
V_25 ) ;
F_16 ( V_21 , V_2 , V_147 != 0 ) ;
RETURN ( V_147 ) ;
}
static int F_108 ( const struct V_20 * V_21 , struct V_24 * V_25 ,
struct V_1 * V_2 , void * V_29 )
{
F_87 ( V_21 , V_25 , V_2 ) ;
F_96 ( V_21 , V_25 , V_2 ) ;
F_92 ( V_21 , V_25 , V_2 ) ;
F_91 ( V_21 , V_25 , V_2 ) ;
return V_36 ;
}
int F_109 ( const struct V_20 * V_21 , struct V_22 * V_149 )
{
struct V_150 * V_151 ;
struct V_22 * V_23 = F_13 ( V_149 ) ;
struct V_24 * V_25 ;
int V_72 ;
V_9 ;
V_151 = F_12 ( V_21 ) ;
V_25 = & V_151 -> V_152 ;
V_25 -> V_109 = V_23 ;
V_25 -> V_153 = 1 ;
V_72 = F_110 ( V_21 , V_25 , V_154 , V_23 ) ;
if ( V_72 != 0 ) {
F_111 ( V_21 , V_25 ) ;
RETURN ( V_25 -> V_155 ) ;
}
do {
V_72 = F_11 ( V_21 , V_23 , V_25 , 0 , V_156 ,
F_108 , NULL ) ;
if ( V_72 == V_49 )
F_112 () ;
} while ( V_72 != V_36 );
F_111 ( V_21 , V_25 ) ;
RETURN ( V_72 ) ;
}
void F_113 ( const struct V_20 * V_21 , struct V_1 * V_94 ,
int V_157 , int V_158 )
{
F_51 ( V_21 , V_94 , F_60 ( V_94 ) ) ;
F_65 ( V_105 , V_21 , V_94 , L_8 , V_157 , V_158 ) ;
F_78 ( V_21 , V_94 , F_83 ( V_159 ) ,
( const struct V_20 * ,
const struct V_5 * , int , int ) ,
V_157 , V_158 ) ;
}
void F_114 ( const struct V_20 * V_21 , void * V_160 ,
T_4 V_161 , const struct V_1 * V_94 )
{
(* V_161)( V_21 , V_160 ,
L_9 ,
V_94 , F_4 ( & V_94 -> V_4 ) , V_94 -> V_50 ,
V_94 -> V_41 , V_94 -> V_3 , V_94 -> V_14 ,
V_94 -> V_44 , V_94 -> V_162 , V_94 -> V_42 ,
V_94 -> V_54 , V_94 -> V_55 , V_94 -> V_140 ) ;
}
void F_115 ( const struct V_20 * V_21 , void * V_160 ,
T_4 V_161 , const struct V_1 * V_94 )
{
struct V_1 * V_144 ;
for ( V_144 = F_71 ( (struct V_1 * ) V_94 ) ;
V_144 != NULL ; V_144 = V_144 -> V_14 )
F_114 ( V_21 , V_160 , V_161 , V_144 ) ;
F_76 ( V_21 , (struct V_1 * ) V_94 , F_83 ( V_163 ) ,
( const struct V_20 * V_21 ,
const struct V_5 * V_8 ,
void * V_160 , T_4 V_164 ) , V_160 , V_161 ) ;
(* V_161)( V_21 , V_160 , L_10 , V_94 ) ;
}
int F_116 ( const struct V_20 * V_21 , struct V_1 * V_2 )
{
return F_76 ( V_21 , V_2 , F_83 ( V_165 ) ,
( const struct V_20 * ,
const struct V_5 * ) ) ;
}
T_5 F_117 ( const struct V_22 * V_23 , T_1 V_31 )
{
return ( T_5 ) V_31 << V_166 ;
}
T_1 F_118 ( const struct V_22 * V_23 , T_5 V_167 )
{
return V_167 >> V_166 ;
}
int F_119 ( const struct V_22 * V_23 )
{
return 1 << V_166 ;
}
void F_120 ( struct V_1 * V_2 , struct V_5 * V_8 ,
struct V_22 * V_23 ,
const struct V_168 * V_169 )
{
V_9 ;
F_121 ( & V_8 -> V_58 , & V_2 -> V_56 ) ;
V_8 -> V_10 = V_23 ;
V_8 -> V_59 = V_169 ;
V_8 -> V_46 = V_2 ;
EXIT ;
}
int F_122 ( void )
{
return 0 ;
}
void F_123 ( void )
{
}
