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
V_2 = F_1 ( (struct V_1 * ) V_2 ) ;
do {
F_7 (slice, &page->cp_layers, cpl_linkage) {
if ( V_8 -> V_9 -> V_10 . V_11 -> V_12 == V_7 )
return V_8 ;
}
V_2 = V_2 -> V_13 ;
} while ( V_2 != NULL );
return NULL ;
}
struct V_1 * F_8 ( struct V_14 * V_15 , T_1 V_16 )
{
struct V_1 * V_2 ;
F_9 ( & V_15 -> V_17 ) ;
V_2 = F_10 ( & V_15 -> V_18 , V_16 ) ;
if ( V_2 != NULL )
F_2 ( V_2 ) ;
return V_2 ;
}
int F_11 ( const struct V_19 * V_20 , struct V_21 * V_22 ,
struct V_23 * V_24 , T_1 V_25 , T_1 V_26 ,
T_2 V_27 , void * V_28 )
{
struct V_14 * V_15 ;
struct V_1 * V_2 ;
struct V_1 * * V_29 ;
const struct V_5 * V_8 ;
const struct V_6 * V_7 ;
T_1 V_30 ;
unsigned int V_31 ;
unsigned int V_32 ;
unsigned int V_33 ;
int V_34 = V_35 ;
int V_36 = 1 ;
V_30 = V_25 ;
V_15 = V_14 ( V_22 ) ;
V_29 = F_12 ( V_20 ) -> V_37 ;
V_7 = F_13 ( V_22 ) -> V_10 . V_11 -> V_12 ;
F_14 ( & V_15 -> V_17 ) ;
while ( ( V_31 = F_15 ( & V_15 -> V_18 , ( void * * ) V_29 ,
V_30 , V_38 ) ) > 0 ) {
int V_39 = 0 ;
V_30 = V_29 [ V_31 - 1 ] -> V_40 + 1 ;
for ( V_32 = 0 , V_33 = 0 ; V_32 < V_31 ; ++ V_32 ) {
V_2 = V_29 [ V_32 ] ;
V_29 [ V_32 ] = NULL ;
F_3 ( V_2 -> V_41 == V_42 ) ;
if ( V_2 -> V_40 > V_26 ) {
V_39 = 1 ;
break;
}
if ( V_2 -> V_43 == V_44 )
continue;
V_8 = F_6 ( V_2 , V_7 ) ;
F_16 ( V_20 , V_2 , V_8 != NULL ) ;
V_2 = V_8 -> V_45 ;
F_2 ( V_2 ) ;
F_17 ( & V_2 -> V_46 ,
L_1 , V_47 ) ;
V_29 [ V_33 ++ ] = V_2 ;
}
F_18 ( & V_15 -> V_17 ) ;
V_36 = 0 ;
for ( V_32 = 0 ; V_32 < V_33 ; ++ V_32 ) {
V_2 = V_29 [ V_32 ] ;
if ( V_34 == V_35 )
V_34 = (* V_27)( V_20 , V_24 , V_2 , V_28 ) ;
F_19 ( & V_2 -> V_46 ,
L_1 , V_47 ) ;
F_20 ( V_20 , V_2 ) ;
}
if ( V_31 < V_38 || V_39 )
break;
if ( V_34 == V_35 && F_21 () )
V_34 = V_48 ;
if ( V_34 != V_35 )
break;
F_14 ( & V_15 -> V_17 ) ;
V_36 = 1 ;
}
if ( V_36 )
F_18 ( & V_15 -> V_17 ) ;
return V_34 ;
}
static void F_22 ( const struct V_19 * V_20 , struct V_1 * V_2 )
{
struct V_21 * V_22 = V_2 -> V_49 ;
int V_50 = V_14 ( V_22 ) -> V_51 ;
F_16 ( V_20 , V_2 , F_23 ( & V_2 -> V_52 ) ) ;
F_16 ( V_20 , V_2 , V_2 -> V_53 == NULL ) ;
F_16 ( V_20 , V_2 , V_2 -> V_54 == NULL ) ;
F_16 ( V_20 , V_2 , V_2 -> V_3 == NULL ) ;
F_16 ( V_20 , V_2 , V_2 -> V_43 == V_44 ) ;
F_24 () ;
while ( ! F_23 ( & V_2 -> V_55 ) ) {
struct V_5 * V_8 ;
V_8 = F_25 ( V_2 -> V_55 . V_56 ,
struct V_5 , V_57 ) ;
F_26 ( V_2 -> V_55 . V_56 ) ;
V_8 -> V_58 -> V_59 ( V_20 , V_8 ) ;
}
F_27 ( V_22 , V_60 ) ;
F_28 ( V_22 , V_2 -> V_43 ) ;
F_29 ( & V_22 -> V_10 , & V_2 -> V_61 , L_2 , V_2 ) ;
F_30 ( V_20 , V_22 ) ;
F_31 ( & V_2 -> V_46 ) ;
F_32 ( V_2 , V_50 ) ;
}
static inline void F_33 ( struct V_1 * V_2 ,
enum V_62 V_63 )
{
* (enum V_62 * ) & V_2 -> V_43 = V_63 ;
}
static struct V_1 * F_34 ( const struct V_19 * V_20 ,
struct V_21 * V_64 , T_1 V_65 , struct V_2 * V_66 ,
enum V_67 type )
{
struct V_1 * V_2 ;
struct V_68 * V_69 ;
F_35 ( V_2 , V_14 ( V_64 ) -> V_51 ,
V_70 ) ;
if ( V_2 != NULL ) {
int V_71 = 0 ;
F_36 ( & V_2 -> V_4 , 1 ) ;
if ( type == V_42 )
F_5 ( & V_2 -> V_4 ) ;
V_2 -> V_49 = V_64 ;
F_37 ( V_64 ) ;
F_38 ( & V_64 -> V_10 , & V_2 -> V_61 , L_2 ,
V_2 ) ;
V_2 -> V_40 = V_65 ;
F_33 ( V_2 , V_72 ) ;
V_2 -> V_41 = type ;
F_39 ( & V_2 -> V_55 ) ;
F_39 ( & V_2 -> V_52 ) ;
F_39 ( & V_2 -> V_73 ) ;
F_40 ( & V_2 -> V_74 ) ;
F_41 ( & V_2 -> V_46 ) ;
V_69 = V_64 -> V_10 . V_75 ;
F_7 (o, &head->loh_layers,
co_lu.lo_linkage) {
if ( V_64 -> V_76 -> V_77 != NULL ) {
V_71 = V_64 -> V_76 -> V_77 ( V_20 , V_64 ,
V_2 , V_66 ) ;
if ( V_71 != 0 ) {
F_42 ( V_20 , V_2 , 0 ) ;
F_22 ( V_20 , V_2 ) ;
V_2 = F_43 ( V_71 ) ;
break;
}
}
}
if ( V_71 == 0 ) {
F_44 ( V_64 , V_60 ) ;
F_44 ( V_64 , V_78 ) ;
F_28 ( V_64 , V_72 ) ;
}
} else {
V_2 = F_43 ( - V_79 ) ;
}
return V_2 ;
}
static struct V_1 * F_45 ( const struct V_19 * V_20 ,
struct V_21 * V_64 ,
T_1 V_30 , struct V_2 * V_66 ,
enum V_67 type ,
struct V_1 * V_80 )
{
struct V_1 * V_2 = NULL ;
struct V_1 * V_81 = NULL ;
struct V_14 * V_15 ;
int V_82 ;
F_3 ( type == V_42 || type == V_83 ) ;
F_24 () ;
V_15 = V_14 ( V_64 ) ;
F_44 ( V_64 , V_84 ) ;
F_46 ( V_85 , L_3 V_86 L_4 ,
V_30 , F_47 ( & V_15 -> V_87 . V_88 ) , V_66 , V_66 -> V_89 , type ) ;
if ( type == V_42 ) {
F_48 ( F_49 ( V_66 ) ) ;
V_2 = F_50 ( V_66 , V_64 ) ;
F_51 ( V_20 , V_2 ,
F_52 ( V_2 != NULL ,
F_53 ( V_20 , V_2 ) == V_66 &&
( void * ) F_10 ( & V_15 -> V_18 ,
V_30 ) == V_2 ) ) ;
}
if ( V_2 != NULL ) {
F_44 ( V_64 , V_90 ) ;
return V_2 ;
}
V_2 = F_34 ( V_20 , V_64 , V_30 , V_66 , type ) ;
if ( F_54 ( V_2 ) )
return V_2 ;
if ( type == V_83 ) {
if ( V_80 ) {
F_3 ( V_2 -> V_3 == NULL ) ;
V_2 -> V_3 = V_80 ;
V_80 -> V_13 = V_2 ;
}
return V_2 ;
}
F_14 ( & V_15 -> V_17 ) ;
V_82 = F_55 ( & V_15 -> V_18 , V_30 , V_2 ) ;
if ( V_82 != 0 ) {
V_81 = V_2 ;
V_2 = F_43 ( V_82 ) ;
F_56 ( V_91 , V_20 , V_81 ,
L_5 , V_82 ) ;
} else {
if ( V_80 ) {
F_3 ( V_2 -> V_3 == NULL ) ;
V_2 -> V_3 = V_80 ;
V_80 -> V_13 = V_2 ;
}
V_15 -> V_92 ++ ;
}
F_18 ( & V_15 -> V_17 ) ;
if ( F_57 ( V_81 != NULL ) ) {
F_42 ( V_20 , V_81 , 0 ) ;
F_22 ( V_20 , V_81 ) ;
}
return V_2 ;
}
struct V_1 * F_58 ( const struct V_19 * V_20 , struct V_21 * V_64 ,
T_1 V_30 , struct V_2 * V_66 ,
enum V_67 type )
{
return F_45 ( V_20 , V_64 , V_30 , V_66 , type , NULL ) ;
}
struct V_1 * F_59 ( const struct V_19 * V_20 , struct V_21 * V_64 ,
T_1 V_30 , struct V_2 * V_66 ,
struct V_1 * V_80 )
{
return F_45 ( V_20 , V_64 , V_30 , V_66 , V_80 -> V_41 , V_80 ) ;
}
static inline int F_60 ( const struct V_1 * V_93 )
{
struct V_14 * V_94 ;
struct V_1 * V_80 ;
struct V_1 * V_95 ;
struct V_23 * V_96 ;
F_61 ( F_62 ( NULL , V_93 ) ) ;
V_94 = V_14 ( V_93 -> V_49 ) ;
V_80 = V_93 -> V_3 ;
V_95 = V_93 -> V_13 ;
V_96 = V_93 -> V_53 ;
return F_63 ( V_93 ) &&
F_52 ( V_80 != NULL , V_80 -> V_13 == V_93 ) &&
F_52 ( V_95 != NULL , V_95 -> V_3 == V_93 ) &&
F_52 ( V_95 != NULL , V_93 -> V_49 != V_95 -> V_49 ) &&
F_52 ( V_80 != NULL , V_93 -> V_49 != V_80 -> V_49 ) &&
F_52 ( V_96 != NULL && V_80 != NULL ,
V_80 -> V_53 == V_93 -> V_53 -> V_97 ) &&
F_52 ( V_96 != NULL && V_95 != NULL ,
V_95 -> V_53 -> V_97 == V_96 ) &&
F_52 ( V_93 -> V_43 < V_44 && V_93 -> V_41 == V_42 ,
( void * ) F_10 ( & V_94 -> V_18 ,
V_93 -> V_40 ) == V_93 ||
( V_95 == NULL && V_80 == NULL ) ) ;
}
static void F_64 ( const struct V_19 * V_20 ,
struct V_1 * V_2 , enum V_62 V_63 )
{
enum V_62 V_98 ;
static const int V_99 [ V_100 ] [ V_100 ] = {
[ V_72 ] = {
[ V_72 ] = 0 ,
[ V_101 ] = 1 ,
[ V_102 ] = 0 ,
[ V_103 ] = 1 ,
[ V_44 ] = 1 ,
} ,
[ V_101 ] = {
[ V_72 ] = 1 ,
[ V_101 ] = 0 ,
[ V_102 ] = 1 ,
[ V_103 ] = 1 ,
[ V_44 ] = 1 ,
} ,
[ V_102 ] = {
[ V_72 ] = 1 ,
[ V_101 ] = 0 ,
[ V_102 ] = 0 ,
[ V_103 ] = 0 ,
[ V_44 ] = 0 ,
} ,
[ V_103 ] = {
[ V_72 ] = 1 ,
[ V_101 ] = 0 ,
[ V_102 ] = 0 ,
[ V_103 ] = 0 ,
[ V_44 ] = 0 ,
} ,
[ V_44 ] = {
[ V_72 ] = 0 ,
[ V_101 ] = 0 ,
[ V_102 ] = 0 ,
[ V_103 ] = 0 ,
[ V_44 ] = 0 ,
}
} ;
V_98 = V_2 -> V_43 ;
F_16 ( V_20 , V_2 , V_99 [ V_98 ] [ V_63 ] ) ;
F_65 ( V_104 , V_20 , V_2 , L_6 , V_98 , V_63 ) ;
for (; V_2 != NULL ; V_2 = V_2 -> V_13 ) {
F_16 ( V_20 , V_2 , V_2 -> V_43 == V_98 ) ;
F_16 ( V_20 , V_2 ,
F_66 ( V_63 == V_101 , V_2 -> V_53 != NULL ) ) ;
F_28 ( V_2 -> V_49 , V_2 -> V_43 ) ;
F_67 ( V_2 -> V_49 , V_63 ) ;
F_33 ( V_2 , V_63 ) ;
}
}
static void F_68 ( const struct V_19 * V_20 ,
struct V_1 * V_2 , enum V_62 V_63 )
{
F_64 ( V_20 , V_2 , V_63 ) ;
}
void F_69 ( struct V_1 * V_2 )
{
F_2 ( V_2 ) ;
}
void F_20 ( const struct V_19 * V_20 , struct V_1 * V_2 )
{
F_16 ( V_20 , V_2 , F_4 ( & V_2 -> V_4 ) > ! ! V_2 -> V_3 ) ;
F_65 ( V_104 , V_20 , V_2 , L_7 ,
F_4 ( & V_2 -> V_4 ) ) ;
if ( F_70 ( & V_2 -> V_4 ) ) {
F_3 ( V_2 -> V_43 == V_44 ) ;
F_3 ( F_4 ( & V_2 -> V_4 ) == 0 ) ;
F_16 ( V_20 , V_2 , V_2 -> V_53 == NULL ) ;
F_16 ( V_20 , V_2 , F_23 ( & V_2 -> V_52 ) ) ;
F_22 ( V_20 , V_2 ) ;
}
}
struct V_2 * F_53 ( const struct V_19 * V_20 , struct V_1 * V_2 )
{
const struct V_5 * V_8 ;
V_2 = F_71 ( V_2 ) ;
do {
F_7 (slice, &page->cp_layers, cpl_linkage) {
if ( V_8 -> V_58 -> V_105 != NULL )
return V_8 -> V_58 -> V_105 ( V_20 , V_8 ) ;
}
V_2 = V_2 -> V_13 ;
} while ( V_2 != NULL );
F_72 () ;
}
struct V_1 * F_50 ( struct V_2 * V_66 , struct V_21 * V_22 )
{
struct V_1 * V_106 ;
struct V_1 * V_2 ;
F_48 ( F_49 ( V_66 ) ) ;
V_106 = (struct V_1 * ) V_66 -> V_89 ;
if ( V_106 == NULL )
return NULL ;
for ( V_2 = V_106 ; V_2 != NULL ; V_2 = V_2 -> V_13 ) {
if ( F_73 ( V_2 -> V_49 , V_22 ) ) {
F_2 ( V_2 ) ;
break;
}
}
F_3 ( F_52 ( V_2 , V_2 -> V_41 == V_42 ) ) ;
return V_2 ;
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
static int F_75 ( const struct V_19 * V_20 ,
struct V_23 * V_24 , struct V_1 * V_2 , T_3 V_107 )
{
F_51 ( V_20 , V_2 , F_73 ( V_2 -> V_49 , V_24 -> V_108 ) ) ;
return F_76 ( V_20 , V_2 , V_107 ,
( const struct V_19 * ,
const struct V_5 * , struct V_23 * ) ,
V_24 ) ;
}
static void F_77 ( const struct V_19 * V_20 ,
struct V_23 * V_24 , struct V_1 * V_2 , T_3 V_107 )
{
F_51 ( V_20 , V_2 , F_73 ( V_2 -> V_49 , V_24 -> V_108 ) ) ;
F_78 ( V_20 , V_2 , V_107 ,
( const struct V_19 * ,
const struct V_5 * , struct V_23 * ) , V_24 ) ;
}
static void F_79 ( struct V_1 * V_2 )
{
for ( V_2 = F_71 ( V_2 ) ; V_2 != NULL ; V_2 = V_2 -> V_13 ) {
if ( V_2 -> V_53 != NULL ) {
F_3 ( V_2 -> V_53 -> V_109 > 0 ) ;
V_2 -> V_53 -> V_109 -- ;
V_2 -> V_53 = NULL ;
V_2 -> V_110 = NULL ;
}
}
}
static void F_80 ( struct V_1 * V_2 )
{
for ( V_2 = F_71 ( V_2 ) ; V_2 != NULL ; V_2 = V_2 -> V_13 ) {
F_3 ( V_2 -> V_53 != NULL ) ;
V_2 -> V_53 -> V_109 ++ ;
}
}
void F_81 ( const struct V_19 * V_20 ,
struct V_23 * V_24 , struct V_1 * V_93 )
{
enum V_62 V_63 ;
V_63 = V_93 -> V_43 ;
F_51 ( V_20 , V_93 , V_63 == V_101 || V_63 == V_44 ) ;
F_51 ( V_20 , V_93 , F_60 ( V_93 ) ) ;
F_79 ( V_93 ) ;
if ( V_63 == V_101 )
F_68 ( V_20 , V_93 , V_72 ) ;
F_82 ( V_20 , V_93 , F_83 ( V_111 ) ,
( const struct V_19 * ,
const struct V_5 * , struct V_23 * ) ,
V_24 ) ;
}
int F_84 ( const struct V_1 * V_93 , const struct V_23 * V_24 )
{
F_61 ( F_73 ( V_93 -> V_49 , V_24 -> V_108 ) ) ;
return V_93 -> V_43 == V_101 && V_93 -> V_53 == V_24 ;
}
static int F_85 ( const struct V_19 * V_20 , struct V_23 * V_24 ,
struct V_1 * V_93 , int V_112 )
{
int V_71 ;
F_51 ( V_20 , V_93 , ! F_84 ( V_93 , V_24 ) ) ;
V_93 = F_71 ( V_93 ) ;
V_24 = F_86 ( V_24 ) ;
if ( V_93 -> V_43 == V_44 ) {
V_71 = - V_113 ;
} else {
V_71 = F_76 ( V_20 , V_93 , F_83 ( V_114 ) ,
( const struct V_19 * ,
const struct V_5 * ,
struct V_23 * , int ) ,
V_24 , V_112 ) ;
if ( V_71 == 0 ) {
F_16 ( V_20 , V_93 , V_93 -> V_53 == NULL ) ;
F_16 ( V_20 , V_93 , V_93 -> V_54 == NULL ) ;
V_93 -> V_53 = V_24 ;
V_93 -> V_110 = V_47 ;
F_80 ( V_93 ) ;
if ( V_93 -> V_43 != V_44 ) {
F_68 ( V_20 , V_93 , V_101 ) ;
} else {
F_81 ( V_20 , V_24 , V_93 ) ;
V_71 = - V_113 ;
}
}
}
F_51 ( V_20 , V_93 , F_52 ( V_71 == 0 , F_60 ( V_93 ) ) ) ;
return V_71 ;
}
int F_87 ( const struct V_19 * V_20 , struct V_23 * V_24 , struct V_1 * V_93 )
{
return F_85 ( V_20 , V_24 , V_93 , 0 ) ;
}
int F_88 ( const struct V_19 * V_20 , struct V_23 * V_24 ,
struct V_1 * V_93 )
{
return F_85 ( V_20 , V_24 , V_93 , 1 ) ;
}
void F_89 ( const struct V_19 * V_20 ,
struct V_23 * V_24 , struct V_1 * V_93 )
{
F_51 ( V_20 , V_93 , F_73 ( V_93 -> V_49 , V_24 -> V_108 ) ) ;
V_93 = F_71 ( V_93 ) ;
V_24 = F_86 ( V_24 ) ;
F_77 ( V_20 , V_24 , V_93 , F_83 ( V_115 ) ) ;
F_16 ( V_20 , V_93 , V_93 -> V_53 == NULL ) ;
V_93 -> V_53 = V_24 ;
V_93 -> V_110 = V_47 ;
F_80 ( V_93 ) ;
F_68 ( V_20 , V_93 , V_101 ) ;
}
void F_90 ( const struct V_19 * V_20 ,
struct V_23 * V_24 , struct V_1 * V_93 )
{
F_51 ( V_20 , V_93 , F_84 ( V_93 , V_24 ) ) ;
F_51 ( V_20 , V_93 , F_60 ( V_93 ) ) ;
V_93 = F_71 ( V_93 ) ;
V_24 = F_86 ( V_24 ) ;
F_79 ( V_93 ) ;
F_68 ( V_20 , V_93 , V_72 ) ;
F_82 ( V_20 , V_93 , F_83 ( V_116 ) ,
( const struct V_19 * ,
const struct V_5 * , struct V_23 * ) ,
V_24 ) ;
}
void F_91 ( const struct V_19 * V_20 ,
struct V_23 * V_24 , struct V_1 * V_93 )
{
F_51 ( V_20 , V_93 , F_84 ( V_93 , V_24 ) ) ;
V_93 = F_71 ( V_93 ) ;
V_24 = F_86 ( V_24 ) ;
F_81 ( V_20 , V_24 , V_93 ) ;
}
void F_92 ( const struct V_19 * V_20 ,
struct V_23 * V_24 , struct V_1 * V_93 )
{
F_51 ( V_20 , V_93 , F_84 ( V_93 , V_24 ) ) ;
F_51 ( V_20 , V_93 , F_60 ( V_93 ) ) ;
F_77 ( V_20 , V_24 , V_93 , F_83 ( V_117 ) ) ;
}
static void F_42 ( const struct V_19 * V_20 , struct V_1 * V_93 ,
int V_118 )
{
struct V_1 * V_119 = V_93 ;
F_16 ( V_20 , V_93 , V_93 == F_71 ( V_93 ) ) ;
F_16 ( V_20 , V_93 , V_93 -> V_43 != V_44 ) ;
F_79 ( V_93 ) ;
F_93 ( V_20 , V_93 , 0 ) ;
F_64 ( V_20 , V_93 , V_44 ) ;
F_78 ( V_20 , V_93 , F_83 ( V_120 ) ,
( const struct V_19 * , const struct V_5 * ) ) ;
if ( V_119 -> V_41 == V_42 ) {
if ( ! V_118 )
V_119 = V_93 -> V_13 ;
for (; V_119 != NULL ; V_119 = V_119 -> V_13 ) {
void * V_121 ;
struct V_14 * V_15 ;
V_15 = V_14 ( V_119 -> V_49 ) ;
F_14 ( & V_15 -> V_17 ) ;
V_121 = F_94 ( & V_15 -> V_18 ,
V_119 -> V_40 ) ;
F_16 ( V_20 , V_119 , V_121 == V_119 ) ;
F_16 ( V_20 , V_119 , V_15 -> V_92 > 0 ) ;
V_15 -> V_92 -- ;
F_18 ( & V_15 -> V_17 ) ;
F_20 ( V_20 , V_119 ) ;
}
}
}
void F_95 ( const struct V_19 * V_20 , struct V_1 * V_93 )
{
F_51 ( V_20 , V_93 , F_60 ( V_93 ) ) ;
F_42 ( V_20 , V_93 , 1 ) ;
}
int F_96 ( const struct V_19 * V_20 ,
struct V_23 * V_24 , struct V_1 * V_93 )
{
F_51 ( V_20 , V_93 , F_84 ( V_93 , V_24 ) ) ;
F_51 ( V_20 , V_93 , F_60 ( V_93 ) ) ;
return F_75 ( V_20 , V_24 , V_93 , F_83 ( V_122 ) ) ;
}
void F_93 ( const struct V_19 * V_20 , struct V_1 * V_93 , int V_123 )
{
F_51 ( V_20 , V_93 , F_60 ( V_93 ) ) ;
F_78 ( V_20 , V_93 , F_83 ( V_124 ) ,
( const struct V_19 * ,
const struct V_5 * , int ) , V_123 ) ;
}
int F_62 ( const struct V_19 * V_20 , const struct V_1 * V_93 )
{
int V_71 ;
const struct V_5 * V_8 ;
V_93 = F_1 ( (struct V_1 * ) V_93 ) ;
V_8 = F_97 ( V_93 -> V_55 . V_56 ,
const struct V_5 , V_57 ) ;
F_16 ( V_20 , V_93 , V_8 -> V_58 -> V_125 != NULL ) ;
V_71 = V_8 -> V_58 -> V_125 ( V_20 , V_8 ) ;
F_16 ( V_20 , V_93 , V_71 == - V_126 || V_71 == - V_127 ) ;
return V_71 == - V_126 ;
}
static enum V_62 F_98 ( enum V_128 V_129 )
{
return V_129 == V_130 ? V_103 : V_102 ;
}
static void F_99 ( const struct V_19 * V_20 ,
struct V_1 * V_93 , enum V_128 V_129 )
{
F_79 ( V_93 ) ;
F_68 ( V_20 , V_93 , F_98 ( V_129 ) ) ;
}
int F_100 ( const struct V_19 * V_20 , struct V_23 * V_24 ,
struct V_1 * V_93 , enum V_128 V_129 )
{
int V_71 ;
F_51 ( V_20 , V_93 , F_84 ( V_93 , V_24 ) ) ;
F_51 ( V_20 , V_93 , F_60 ( V_93 ) ) ;
F_51 ( V_20 , V_93 , V_129 < V_131 ) ;
if ( V_129 >= V_131 )
return - V_132 ;
V_71 = F_75 ( V_20 , V_24 , V_93 , F_83 ( V_24 [ V_129 ] . V_133 ) ) ;
if ( V_71 == 0 )
F_99 ( V_20 , V_93 , V_129 ) ;
F_48 ( F_52 ( V_129 == V_130 && V_93 -> V_41 == V_42 ,
F_66 ( V_71 == 0 ,
F_101 ( F_53 ( V_20 , V_93 ) ) ) ) ) ;
F_65 ( V_104 , V_20 , V_93 , L_8 , V_129 , V_71 ) ;
return V_71 ;
}
void F_102 ( const struct V_19 * V_20 ,
struct V_1 * V_93 , enum V_128 V_129 , int V_134 )
{
struct V_135 * V_136 = V_93 -> V_137 ;
F_16 ( V_20 , V_93 , V_129 < V_131 ) ;
F_16 ( V_20 , V_93 , V_93 -> V_54 == NULL ) ;
F_16 ( V_20 , V_93 , V_93 -> V_43 == F_98 ( V_129 ) ) ;
F_65 ( V_104 , V_20 , V_93 , L_8 , V_129 , V_134 ) ;
if ( V_129 == V_138 && V_134 == 0 ) {
F_16 ( V_20 , V_93 , ! ( V_93 -> V_139 & V_140 ) ) ;
V_93 -> V_139 |= V_140 ;
}
F_68 ( V_20 , V_93 , V_72 ) ;
if ( V_129 >= V_131 )
return;
F_82 ( V_20 , V_93 , F_83 ( V_24 [ V_129 ] . V_141 ) ,
( const struct V_19 * ,
const struct V_5 * , int ) , V_134 ) ;
if ( V_136 ) {
F_3 ( F_62 ( V_20 , V_93 ) ) ;
F_3 ( V_93 -> V_137 == V_136 ) ;
V_93 -> V_137 = NULL ;
}
F_20 ( V_20 , V_93 ) ;
if ( V_136 )
F_103 ( V_136 , V_134 ) ;
}
int F_104 ( const struct V_19 * V_20 , struct V_1 * V_93 ,
enum V_128 V_129 )
{
int V_71 ;
F_51 ( V_20 , V_93 , V_129 < V_131 ) ;
if ( V_129 >= V_131 )
return - V_132 ;
V_71 = F_76 ( V_20 , V_93 , F_83 ( V_24 [ V_129 ] . V_142 ) ,
( const struct V_19 * ,
const struct V_5 * ) ) ;
if ( V_71 == 0 ) {
F_16 ( V_20 , V_93 , V_93 -> V_43 == V_72 ) ;
F_99 ( V_20 , V_93 , V_129 ) ;
}
F_65 ( V_104 , V_20 , V_93 , L_8 , V_129 , V_71 ) ;
return V_71 ;
}
int F_105 ( const struct V_19 * V_20 , struct V_23 * V_24 ,
struct V_1 * V_93 , enum V_128 V_129 )
{
const struct V_5 * V_143 ;
int V_71 = 0 ;
F_51 ( V_20 , V_93 , V_129 < V_131 ) ;
F_51 ( V_20 , V_93 , F_84 ( V_93 , V_24 ) ) ;
F_51 ( V_20 , V_93 , F_60 ( V_93 ) ) ;
if ( V_129 >= V_131 )
return - V_132 ;
F_7 (scan, &pg->cp_layers, cpl_linkage) {
if ( V_143 -> V_58 -> V_24 [ V_129 ] . V_144 == NULL )
continue;
V_71 = V_143 -> V_58 -> V_24 [ V_129 ] . V_144 ( V_20 , V_143 , V_24 ) ;
if ( V_71 != 0 )
break;
}
F_65 ( V_104 , V_20 , V_93 , L_8 , V_129 , V_71 ) ;
return V_71 ;
}
int F_106 ( const struct V_19 * V_20 , struct V_23 * V_24 ,
struct V_1 * V_93 )
{
int V_71 ;
F_51 ( V_20 , V_93 , F_84 ( V_93 , V_24 ) ) ;
F_51 ( V_20 , V_93 , F_60 ( V_93 ) ) ;
V_71 = F_75 ( V_20 , V_24 , V_93 , F_83 ( V_145 ) ) ;
F_65 ( V_104 , V_20 , V_93 , L_7 , V_71 ) ;
return V_71 ;
}
int F_107 ( const struct V_19 * V_20 , struct V_23 * V_24 ,
struct V_1 * V_2 )
{
int V_146 ;
F_51 ( V_20 , V_2 , F_60 ( V_2 ) ) ;
V_146 = F_76 ( V_20 , V_2 , F_83 ( V_147 ) ,
( const struct V_19 * ,
const struct V_5 * , struct V_23 * ) ,
V_24 ) ;
F_16 ( V_20 , V_2 , V_146 != 0 ) ;
return V_146 ;
}
static int F_108 ( const struct V_19 * V_20 , struct V_23 * V_24 ,
struct V_1 * V_2 , void * V_28 )
{
F_87 ( V_20 , V_24 , V_2 ) ;
F_96 ( V_20 , V_24 , V_2 ) ;
F_92 ( V_20 , V_24 , V_2 ) ;
F_91 ( V_20 , V_24 , V_2 ) ;
return V_35 ;
}
int F_109 ( const struct V_19 * V_20 , struct V_21 * V_148 )
{
struct V_149 * V_150 ;
struct V_21 * V_22 = F_13 ( V_148 ) ;
struct V_23 * V_24 ;
int V_71 ;
V_150 = F_12 ( V_20 ) ;
V_24 = & V_150 -> V_151 ;
V_24 -> V_108 = V_22 ;
V_24 -> V_152 = 1 ;
V_71 = F_110 ( V_20 , V_24 , V_153 , V_22 ) ;
if ( V_71 != 0 ) {
F_111 ( V_20 , V_24 ) ;
return V_24 -> V_154 ;
}
do {
V_71 = F_11 ( V_20 , V_22 , V_24 , 0 , V_155 ,
F_108 , NULL ) ;
if ( V_71 == V_48 )
F_112 () ;
} while ( V_71 != V_35 );
F_111 ( V_20 , V_24 ) ;
return V_71 ;
}
void F_113 ( const struct V_19 * V_20 , struct V_1 * V_93 ,
int V_156 , int V_157 )
{
F_51 ( V_20 , V_93 , F_60 ( V_93 ) ) ;
F_65 ( V_104 , V_20 , V_93 , L_8 , V_156 , V_157 ) ;
F_78 ( V_20 , V_93 , F_83 ( V_158 ) ,
( const struct V_19 * ,
const struct V_5 * , int , int ) ,
V_156 , V_157 ) ;
}
void F_114 ( const struct V_19 * V_20 , void * V_159 ,
T_4 V_160 , const struct V_1 * V_93 )
{
(* V_160)( V_20 , V_159 ,
L_9 ,
V_93 , F_4 ( & V_93 -> V_4 ) , V_93 -> V_49 ,
V_93 -> V_40 , V_93 -> V_3 , V_93 -> V_13 ,
V_93 -> V_43 , V_93 -> V_161 , V_93 -> V_41 ,
V_93 -> V_53 , V_93 -> V_54 , V_93 -> V_139 ) ;
}
void F_115 ( const struct V_19 * V_20 , void * V_159 ,
T_4 V_160 , const struct V_1 * V_93 )
{
struct V_1 * V_143 ;
for ( V_143 = F_71 ( (struct V_1 * ) V_93 ) ;
V_143 != NULL ; V_143 = V_143 -> V_13 )
F_114 ( V_20 , V_159 , V_160 , V_143 ) ;
F_76 ( V_20 , (struct V_1 * ) V_93 , F_83 ( V_162 ) ,
( const struct V_19 * V_20 ,
const struct V_5 * V_8 ,
void * V_159 , T_4 V_163 ) , V_159 , V_160 ) ;
(* V_160)( V_20 , V_159 , L_10 , V_93 ) ;
}
int F_116 ( const struct V_19 * V_20 , struct V_1 * V_2 )
{
return F_76 ( V_20 , V_2 , F_83 ( V_164 ) ,
( const struct V_19 * ,
const struct V_5 * ) ) ;
}
T_5 F_117 ( const struct V_21 * V_22 , T_1 V_30 )
{
return ( T_5 ) V_30 << V_165 ;
}
T_1 F_118 ( const struct V_21 * V_22 , T_5 V_166 )
{
return V_166 >> V_165 ;
}
int F_119 ( const struct V_21 * V_22 )
{
return 1 << V_165 ;
}
void F_120 ( struct V_1 * V_2 , struct V_5 * V_8 ,
struct V_21 * V_22 ,
const struct V_167 * V_168 )
{
F_121 ( & V_8 -> V_57 , & V_2 -> V_55 ) ;
V_8 -> V_9 = V_22 ;
V_8 -> V_58 = V_168 ;
V_8 -> V_45 = V_2 ;
}
int F_122 ( void )
{
return 0 ;
}
void F_123 ( void )
{
}
