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
F_16 ( V_20 , V_2 , F_23 ( & V_2 -> V_50 ) ) ;
F_16 ( V_20 , V_2 , V_2 -> V_51 == NULL ) ;
F_16 ( V_20 , V_2 , V_2 -> V_52 == NULL ) ;
F_16 ( V_20 , V_2 , V_2 -> V_3 == NULL ) ;
F_16 ( V_20 , V_2 , V_2 -> V_43 == V_44 ) ;
F_24 () ;
while ( ! F_23 ( & V_2 -> V_53 ) ) {
struct V_5 * V_8 ;
V_8 = F_25 ( V_2 -> V_53 . V_54 ,
struct V_5 , V_55 ) ;
F_26 ( V_2 -> V_53 . V_54 ) ;
V_8 -> V_56 -> V_57 ( V_20 , V_8 ) ;
}
F_27 ( & V_22 -> V_10 , & V_2 -> V_58 , L_2 , V_2 ) ;
F_28 ( V_20 , V_22 ) ;
F_29 ( & V_2 -> V_46 ) ;
F_30 ( V_2 ) ;
}
static inline void F_31 ( struct V_1 * V_2 ,
enum V_59 V_60 )
{
* (enum V_59 * ) & V_2 -> V_43 = V_60 ;
}
static struct V_1 * F_32 ( const struct V_19 * V_20 ,
struct V_21 * V_61 , T_1 V_62 , struct V_2 * V_63 ,
enum V_64 type )
{
struct V_1 * V_2 ;
struct V_65 * V_66 ;
F_33 ( V_2 , V_14 ( V_61 ) -> V_67 ,
V_68 ) ;
if ( V_2 != NULL ) {
int V_69 = 0 ;
F_34 ( & V_2 -> V_4 , 1 ) ;
if ( type == V_42 )
F_5 ( & V_2 -> V_4 ) ;
V_2 -> V_49 = V_61 ;
F_35 ( V_61 ) ;
F_36 ( & V_61 -> V_10 , & V_2 -> V_58 , L_2 ,
V_2 ) ;
V_2 -> V_40 = V_62 ;
F_31 ( V_2 , V_70 ) ;
V_2 -> V_41 = type ;
F_37 ( & V_2 -> V_53 ) ;
F_37 ( & V_2 -> V_50 ) ;
F_37 ( & V_2 -> V_71 ) ;
F_38 ( & V_2 -> V_72 ) ;
F_39 ( & V_2 -> V_46 ) ;
V_66 = V_61 -> V_10 . V_73 ;
F_7 (o, &head->loh_layers,
co_lu.lo_linkage) {
if ( V_61 -> V_74 -> V_75 != NULL ) {
V_69 = V_61 -> V_74 -> V_75 ( V_20 , V_61 ,
V_2 , V_63 ) ;
if ( V_69 != 0 ) {
F_40 ( V_20 , V_2 , 0 ) ;
F_22 ( V_20 , V_2 ) ;
V_2 = F_41 ( V_69 ) ;
break;
}
}
}
} else {
V_2 = F_41 ( - V_76 ) ;
}
return V_2 ;
}
static struct V_1 * F_42 ( const struct V_19 * V_20 ,
struct V_21 * V_61 ,
T_1 V_30 , struct V_2 * V_63 ,
enum V_64 type ,
struct V_1 * V_77 )
{
struct V_1 * V_2 = NULL ;
struct V_1 * V_78 = NULL ;
struct V_14 * V_15 ;
int V_79 ;
F_3 ( type == V_42 || type == V_80 ) ;
F_24 () ;
V_15 = V_14 ( V_61 ) ;
F_43 ( V_81 , L_3 V_82 L_4 ,
V_30 , F_44 ( & V_15 -> V_83 . V_84 ) , V_63 , V_63 -> V_85 , type ) ;
if ( type == V_42 ) {
F_45 ( F_46 ( V_63 ) ) ;
V_2 = F_47 ( V_63 , V_61 ) ;
F_48 ( V_20 , V_2 ,
F_49 ( V_2 != NULL ,
F_50 ( V_20 , V_2 ) == V_63 &&
( void * ) F_10 ( & V_15 -> V_18 ,
V_30 ) == V_2 ) ) ;
}
if ( V_2 != NULL ) {
return V_2 ;
}
V_2 = F_32 ( V_20 , V_61 , V_30 , V_63 , type ) ;
if ( F_51 ( V_2 ) )
return V_2 ;
if ( type == V_80 ) {
if ( V_77 ) {
F_3 ( V_2 -> V_3 == NULL ) ;
V_2 -> V_3 = V_77 ;
V_77 -> V_13 = V_2 ;
}
return V_2 ;
}
F_14 ( & V_15 -> V_17 ) ;
V_79 = F_52 ( & V_15 -> V_18 , V_30 , V_2 ) ;
if ( V_79 != 0 ) {
V_78 = V_2 ;
V_2 = F_41 ( V_79 ) ;
F_53 ( V_86 , V_20 , V_78 ,
L_5 , V_79 ) ;
} else {
if ( V_77 ) {
F_3 ( V_2 -> V_3 == NULL ) ;
V_2 -> V_3 = V_77 ;
V_77 -> V_13 = V_2 ;
}
V_15 -> V_87 ++ ;
}
F_18 ( & V_15 -> V_17 ) ;
if ( F_54 ( V_78 != NULL ) ) {
F_40 ( V_20 , V_78 , 0 ) ;
F_22 ( V_20 , V_78 ) ;
}
return V_2 ;
}
struct V_1 * F_55 ( const struct V_19 * V_20 , struct V_21 * V_61 ,
T_1 V_30 , struct V_2 * V_63 ,
enum V_64 type )
{
return F_42 ( V_20 , V_61 , V_30 , V_63 , type , NULL ) ;
}
struct V_1 * F_56 ( const struct V_19 * V_20 , struct V_21 * V_61 ,
T_1 V_30 , struct V_2 * V_63 ,
struct V_1 * V_77 )
{
return F_42 ( V_20 , V_61 , V_30 , V_63 , V_77 -> V_41 , V_77 ) ;
}
static inline int F_57 ( const struct V_1 * V_88 )
{
struct V_14 * V_89 ;
struct V_1 * V_77 ;
struct V_1 * V_90 ;
struct V_23 * V_91 ;
F_58 ( F_59 ( NULL , V_88 ) ) ;
V_89 = V_14 ( V_88 -> V_49 ) ;
V_77 = V_88 -> V_3 ;
V_90 = V_88 -> V_13 ;
V_91 = V_88 -> V_51 ;
return F_60 ( V_88 ) &&
F_49 ( V_77 != NULL , V_77 -> V_13 == V_88 ) &&
F_49 ( V_90 != NULL , V_90 -> V_3 == V_88 ) &&
F_49 ( V_90 != NULL , V_88 -> V_49 != V_90 -> V_49 ) &&
F_49 ( V_77 != NULL , V_88 -> V_49 != V_77 -> V_49 ) &&
F_49 ( V_91 != NULL && V_77 != NULL ,
V_77 -> V_51 == V_88 -> V_51 -> V_92 ) &&
F_49 ( V_91 != NULL && V_90 != NULL ,
V_90 -> V_51 -> V_92 == V_91 ) &&
F_49 ( V_88 -> V_43 < V_44 && V_88 -> V_41 == V_42 ,
( void * ) F_10 ( & V_89 -> V_18 ,
V_88 -> V_40 ) == V_88 ||
( V_90 == NULL && V_77 == NULL ) ) ;
}
static void F_61 ( const struct V_19 * V_20 ,
struct V_1 * V_2 , enum V_59 V_60 )
{
enum V_59 V_93 ;
static const int V_94 [ V_95 ] [ V_95 ] = {
[ V_70 ] = {
[ V_70 ] = 0 ,
[ V_96 ] = 1 ,
[ V_97 ] = 0 ,
[ V_98 ] = 1 ,
[ V_44 ] = 1 ,
} ,
[ V_96 ] = {
[ V_70 ] = 1 ,
[ V_96 ] = 0 ,
[ V_97 ] = 1 ,
[ V_98 ] = 1 ,
[ V_44 ] = 1 ,
} ,
[ V_97 ] = {
[ V_70 ] = 1 ,
[ V_96 ] = 0 ,
[ V_97 ] = 0 ,
[ V_98 ] = 0 ,
[ V_44 ] = 0 ,
} ,
[ V_98 ] = {
[ V_70 ] = 1 ,
[ V_96 ] = 0 ,
[ V_97 ] = 0 ,
[ V_98 ] = 0 ,
[ V_44 ] = 0 ,
} ,
[ V_44 ] = {
[ V_70 ] = 0 ,
[ V_96 ] = 0 ,
[ V_97 ] = 0 ,
[ V_98 ] = 0 ,
[ V_44 ] = 0 ,
}
} ;
V_93 = V_2 -> V_43 ;
F_16 ( V_20 , V_2 , V_94 [ V_93 ] [ V_60 ] ) ;
F_62 ( V_99 , V_20 , V_2 , L_6 , V_93 , V_60 ) ;
for (; V_2 != NULL ; V_2 = V_2 -> V_13 ) {
F_16 ( V_20 , V_2 , V_2 -> V_43 == V_93 ) ;
F_16 ( V_20 , V_2 ,
F_63 ( V_60 == V_96 , V_2 -> V_51 != NULL ) ) ;
F_31 ( V_2 , V_60 ) ;
}
}
static void F_64 ( const struct V_19 * V_20 ,
struct V_1 * V_2 , enum V_59 V_60 )
{
F_61 ( V_20 , V_2 , V_60 ) ;
}
void F_65 ( struct V_1 * V_2 )
{
F_2 ( V_2 ) ;
}
void F_20 ( const struct V_19 * V_20 , struct V_1 * V_2 )
{
F_16 ( V_20 , V_2 , F_4 ( & V_2 -> V_4 ) > ! ! V_2 -> V_3 ) ;
F_62 ( V_99 , V_20 , V_2 , L_7 ,
F_4 ( & V_2 -> V_4 ) ) ;
if ( F_66 ( & V_2 -> V_4 ) ) {
F_3 ( V_2 -> V_43 == V_44 ) ;
F_3 ( F_4 ( & V_2 -> V_4 ) == 0 ) ;
F_16 ( V_20 , V_2 , V_2 -> V_51 == NULL ) ;
F_16 ( V_20 , V_2 , F_23 ( & V_2 -> V_50 ) ) ;
F_22 ( V_20 , V_2 ) ;
}
}
struct V_2 * F_50 ( const struct V_19 * V_20 , struct V_1 * V_2 )
{
const struct V_5 * V_8 ;
V_2 = F_67 ( V_2 ) ;
do {
F_7 (slice, &page->cp_layers, cpl_linkage) {
if ( V_8 -> V_56 -> V_100 != NULL )
return V_8 -> V_56 -> V_100 ( V_20 , V_8 ) ;
}
V_2 = V_2 -> V_13 ;
} while ( V_2 != NULL );
F_68 () ;
}
struct V_1 * F_47 ( struct V_2 * V_63 , struct V_21 * V_22 )
{
struct V_1 * V_101 ;
struct V_1 * V_2 ;
F_45 ( F_46 ( V_63 ) ) ;
V_101 = (struct V_1 * ) V_63 -> V_85 ;
if ( V_101 == NULL )
return NULL ;
for ( V_2 = V_101 ; V_2 != NULL ; V_2 = V_2 -> V_13 ) {
if ( F_69 ( V_2 -> V_49 , V_22 ) ) {
F_2 ( V_2 ) ;
break;
}
}
F_3 ( F_49 ( V_2 , V_2 -> V_41 == V_42 ) ) ;
return V_2 ;
}
struct V_1 * F_67 ( struct V_1 * V_2 )
{
return F_1 ( V_2 ) ;
}
const struct V_5 * F_70 ( const struct V_1 * V_2 ,
const struct V_6 * V_7 )
{
return F_6 ( V_2 , V_7 ) ;
}
static int F_71 ( const struct V_19 * V_20 ,
struct V_23 * V_24 , struct V_1 * V_2 , T_3 V_102 )
{
F_48 ( V_20 , V_2 , F_69 ( V_2 -> V_49 , V_24 -> V_103 ) ) ;
return F_72 ( V_20 , V_2 , V_102 ,
( const struct V_19 * ,
const struct V_5 * , struct V_23 * ) ,
V_24 ) ;
}
static void F_73 ( const struct V_19 * V_20 ,
struct V_23 * V_24 , struct V_1 * V_2 , T_3 V_102 )
{
F_48 ( V_20 , V_2 , F_69 ( V_2 -> V_49 , V_24 -> V_103 ) ) ;
F_74 ( V_20 , V_2 , V_102 ,
( const struct V_19 * ,
const struct V_5 * , struct V_23 * ) , V_24 ) ;
}
static void F_75 ( struct V_1 * V_2 )
{
for ( V_2 = F_67 ( V_2 ) ; V_2 != NULL ; V_2 = V_2 -> V_13 ) {
if ( V_2 -> V_51 != NULL ) {
F_3 ( V_2 -> V_51 -> V_104 > 0 ) ;
V_2 -> V_51 -> V_104 -- ;
V_2 -> V_51 = NULL ;
V_2 -> V_105 = NULL ;
}
}
}
static void F_76 ( struct V_1 * V_2 )
{
for ( V_2 = F_67 ( V_2 ) ; V_2 != NULL ; V_2 = V_2 -> V_13 ) {
F_3 ( V_2 -> V_51 != NULL ) ;
V_2 -> V_51 -> V_104 ++ ;
}
}
void F_77 ( const struct V_19 * V_20 ,
struct V_23 * V_24 , struct V_1 * V_88 )
{
enum V_59 V_60 ;
V_60 = V_88 -> V_43 ;
F_48 ( V_20 , V_88 , V_60 == V_96 || V_60 == V_44 ) ;
F_48 ( V_20 , V_88 , F_57 ( V_88 ) ) ;
F_75 ( V_88 ) ;
if ( V_60 == V_96 )
F_64 ( V_20 , V_88 , V_70 ) ;
F_78 ( V_20 , V_88 , F_79 ( V_106 ) ,
( const struct V_19 * ,
const struct V_5 * , struct V_23 * ) ,
V_24 ) ;
}
int F_80 ( const struct V_1 * V_88 , const struct V_23 * V_24 )
{
F_58 ( F_69 ( V_88 -> V_49 , V_24 -> V_103 ) ) ;
return V_88 -> V_43 == V_96 && V_88 -> V_51 == V_24 ;
}
static int F_81 ( const struct V_19 * V_20 , struct V_23 * V_24 ,
struct V_1 * V_88 , int V_107 )
{
int V_69 ;
F_48 ( V_20 , V_88 , ! F_80 ( V_88 , V_24 ) ) ;
V_88 = F_67 ( V_88 ) ;
V_24 = F_82 ( V_24 ) ;
if ( V_88 -> V_43 == V_44 ) {
V_69 = - V_108 ;
} else {
V_69 = F_72 ( V_20 , V_88 , F_79 ( V_109 ) ,
( const struct V_19 * ,
const struct V_5 * ,
struct V_23 * , int ) ,
V_24 , V_107 ) ;
if ( V_69 == 0 ) {
F_16 ( V_20 , V_88 , V_88 -> V_51 == NULL ) ;
F_16 ( V_20 , V_88 , V_88 -> V_52 == NULL ) ;
V_88 -> V_51 = V_24 ;
V_88 -> V_105 = V_47 ;
F_76 ( V_88 ) ;
if ( V_88 -> V_43 != V_44 ) {
F_64 ( V_20 , V_88 , V_96 ) ;
} else {
F_77 ( V_20 , V_24 , V_88 ) ;
V_69 = - V_108 ;
}
}
}
F_48 ( V_20 , V_88 , F_49 ( V_69 == 0 , F_57 ( V_88 ) ) ) ;
return V_69 ;
}
int F_83 ( const struct V_19 * V_20 , struct V_23 * V_24 , struct V_1 * V_88 )
{
return F_81 ( V_20 , V_24 , V_88 , 0 ) ;
}
int F_84 ( const struct V_19 * V_20 , struct V_23 * V_24 ,
struct V_1 * V_88 )
{
return F_81 ( V_20 , V_24 , V_88 , 1 ) ;
}
void F_85 ( const struct V_19 * V_20 ,
struct V_23 * V_24 , struct V_1 * V_88 )
{
F_48 ( V_20 , V_88 , F_69 ( V_88 -> V_49 , V_24 -> V_103 ) ) ;
V_88 = F_67 ( V_88 ) ;
V_24 = F_82 ( V_24 ) ;
F_73 ( V_20 , V_24 , V_88 , F_79 ( V_110 ) ) ;
F_16 ( V_20 , V_88 , V_88 -> V_51 == NULL ) ;
V_88 -> V_51 = V_24 ;
V_88 -> V_105 = V_47 ;
F_76 ( V_88 ) ;
F_64 ( V_20 , V_88 , V_96 ) ;
}
void F_86 ( const struct V_19 * V_20 ,
struct V_23 * V_24 , struct V_1 * V_88 )
{
F_48 ( V_20 , V_88 , F_80 ( V_88 , V_24 ) ) ;
F_48 ( V_20 , V_88 , F_57 ( V_88 ) ) ;
V_88 = F_67 ( V_88 ) ;
V_24 = F_82 ( V_24 ) ;
F_75 ( V_88 ) ;
F_64 ( V_20 , V_88 , V_70 ) ;
F_78 ( V_20 , V_88 , F_79 ( V_111 ) ,
( const struct V_19 * ,
const struct V_5 * , struct V_23 * ) ,
V_24 ) ;
}
void F_87 ( const struct V_19 * V_20 ,
struct V_23 * V_24 , struct V_1 * V_88 )
{
F_48 ( V_20 , V_88 , F_80 ( V_88 , V_24 ) ) ;
V_88 = F_67 ( V_88 ) ;
V_24 = F_82 ( V_24 ) ;
F_77 ( V_20 , V_24 , V_88 ) ;
}
void F_88 ( const struct V_19 * V_20 ,
struct V_23 * V_24 , struct V_1 * V_88 )
{
F_48 ( V_20 , V_88 , F_80 ( V_88 , V_24 ) ) ;
F_48 ( V_20 , V_88 , F_57 ( V_88 ) ) ;
F_73 ( V_20 , V_24 , V_88 , F_79 ( V_112 ) ) ;
}
static void F_40 ( const struct V_19 * V_20 , struct V_1 * V_88 ,
int V_113 )
{
struct V_1 * V_114 = V_88 ;
F_16 ( V_20 , V_88 , V_88 == F_67 ( V_88 ) ) ;
F_16 ( V_20 , V_88 , V_88 -> V_43 != V_44 ) ;
F_75 ( V_88 ) ;
F_89 ( V_20 , V_88 , 0 ) ;
F_61 ( V_20 , V_88 , V_44 ) ;
F_74 ( V_20 , V_88 , F_79 ( V_115 ) ,
( const struct V_19 * , const struct V_5 * ) ) ;
if ( V_114 -> V_41 == V_42 ) {
if ( ! V_113 )
V_114 = V_88 -> V_13 ;
for (; V_114 != NULL ; V_114 = V_114 -> V_13 ) {
void * V_116 ;
struct V_14 * V_15 ;
V_15 = V_14 ( V_114 -> V_49 ) ;
F_14 ( & V_15 -> V_17 ) ;
V_116 = F_90 ( & V_15 -> V_18 ,
V_114 -> V_40 ) ;
F_16 ( V_20 , V_114 , V_116 == V_114 ) ;
F_16 ( V_20 , V_114 , V_15 -> V_87 > 0 ) ;
V_15 -> V_87 -- ;
F_18 ( & V_15 -> V_17 ) ;
F_20 ( V_20 , V_114 ) ;
}
}
}
void F_91 ( const struct V_19 * V_20 , struct V_1 * V_88 )
{
F_48 ( V_20 , V_88 , F_57 ( V_88 ) ) ;
F_40 ( V_20 , V_88 , 1 ) ;
}
int F_92 ( const struct V_19 * V_20 ,
struct V_23 * V_24 , struct V_1 * V_88 )
{
F_48 ( V_20 , V_88 , F_80 ( V_88 , V_24 ) ) ;
F_48 ( V_20 , V_88 , F_57 ( V_88 ) ) ;
return F_71 ( V_20 , V_24 , V_88 , F_79 ( V_117 ) ) ;
}
void F_89 ( const struct V_19 * V_20 , struct V_1 * V_88 , int V_118 )
{
F_48 ( V_20 , V_88 , F_57 ( V_88 ) ) ;
F_74 ( V_20 , V_88 , F_79 ( V_119 ) ,
( const struct V_19 * ,
const struct V_5 * , int ) , V_118 ) ;
}
int F_59 ( const struct V_19 * V_20 , const struct V_1 * V_88 )
{
int V_69 ;
const struct V_5 * V_8 ;
V_88 = F_1 ( (struct V_1 * ) V_88 ) ;
V_8 = F_93 ( V_88 -> V_53 . V_54 ,
const struct V_5 , V_55 ) ;
F_16 ( V_20 , V_88 , V_8 -> V_56 -> V_120 != NULL ) ;
V_69 = V_8 -> V_56 -> V_120 ( V_20 , V_8 ) ;
F_16 ( V_20 , V_88 , V_69 == - V_121 || V_69 == - V_122 ) ;
return V_69 == - V_121 ;
}
static enum V_59 F_94 ( enum V_123 V_124 )
{
return V_124 == V_125 ? V_98 : V_97 ;
}
static void F_95 ( const struct V_19 * V_20 ,
struct V_1 * V_88 , enum V_123 V_124 )
{
F_75 ( V_88 ) ;
F_64 ( V_20 , V_88 , F_94 ( V_124 ) ) ;
}
int F_96 ( const struct V_19 * V_20 , struct V_23 * V_24 ,
struct V_1 * V_88 , enum V_123 V_124 )
{
int V_69 ;
F_48 ( V_20 , V_88 , F_80 ( V_88 , V_24 ) ) ;
F_48 ( V_20 , V_88 , F_57 ( V_88 ) ) ;
F_48 ( V_20 , V_88 , V_124 < V_126 ) ;
if ( V_124 >= V_126 )
return - V_127 ;
V_69 = F_71 ( V_20 , V_24 , V_88 , F_79 ( V_24 [ V_124 ] . V_128 ) ) ;
if ( V_69 == 0 )
F_95 ( V_20 , V_88 , V_124 ) ;
F_45 ( F_49 ( V_124 == V_125 && V_88 -> V_41 == V_42 ,
F_63 ( V_69 == 0 ,
F_97 ( F_50 ( V_20 , V_88 ) ) ) ) ) ;
F_62 ( V_99 , V_20 , V_88 , L_8 , V_124 , V_69 ) ;
return V_69 ;
}
void F_98 ( const struct V_19 * V_20 ,
struct V_1 * V_88 , enum V_123 V_124 , int V_129 )
{
struct V_130 * V_131 = V_88 -> V_132 ;
F_16 ( V_20 , V_88 , V_124 < V_126 ) ;
F_16 ( V_20 , V_88 , V_88 -> V_52 == NULL ) ;
F_16 ( V_20 , V_88 , V_88 -> V_43 == F_94 ( V_124 ) ) ;
F_62 ( V_99 , V_20 , V_88 , L_8 , V_124 , V_129 ) ;
if ( V_124 == V_133 && V_129 == 0 ) {
F_16 ( V_20 , V_88 , ! ( V_88 -> V_134 & V_135 ) ) ;
V_88 -> V_134 |= V_135 ;
}
F_64 ( V_20 , V_88 , V_70 ) ;
if ( V_124 >= V_126 )
return;
F_78 ( V_20 , V_88 , F_79 ( V_24 [ V_124 ] . V_136 ) ,
( const struct V_19 * ,
const struct V_5 * , int ) , V_129 ) ;
if ( V_131 ) {
F_3 ( F_59 ( V_20 , V_88 ) ) ;
F_3 ( V_88 -> V_132 == V_131 ) ;
V_88 -> V_132 = NULL ;
}
F_20 ( V_20 , V_88 ) ;
if ( V_131 )
F_99 ( V_131 , V_129 ) ;
}
int F_100 ( const struct V_19 * V_20 , struct V_1 * V_88 ,
enum V_123 V_124 )
{
int V_69 ;
F_48 ( V_20 , V_88 , V_124 < V_126 ) ;
if ( V_124 >= V_126 )
return - V_127 ;
V_69 = F_72 ( V_20 , V_88 , F_79 ( V_24 [ V_124 ] . V_137 ) ,
( const struct V_19 * ,
const struct V_5 * ) ) ;
if ( V_69 == 0 ) {
F_16 ( V_20 , V_88 , V_88 -> V_43 == V_70 ) ;
F_95 ( V_20 , V_88 , V_124 ) ;
}
F_62 ( V_99 , V_20 , V_88 , L_8 , V_124 , V_69 ) ;
return V_69 ;
}
int F_101 ( const struct V_19 * V_20 , struct V_23 * V_24 ,
struct V_1 * V_88 , enum V_123 V_124 )
{
const struct V_5 * V_138 ;
int V_69 = 0 ;
F_48 ( V_20 , V_88 , V_124 < V_126 ) ;
F_48 ( V_20 , V_88 , F_80 ( V_88 , V_24 ) ) ;
F_48 ( V_20 , V_88 , F_57 ( V_88 ) ) ;
if ( V_124 >= V_126 )
return - V_127 ;
F_7 (scan, &pg->cp_layers, cpl_linkage) {
if ( V_138 -> V_56 -> V_24 [ V_124 ] . V_139 == NULL )
continue;
V_69 = V_138 -> V_56 -> V_24 [ V_124 ] . V_139 ( V_20 , V_138 , V_24 ) ;
if ( V_69 != 0 )
break;
}
F_62 ( V_99 , V_20 , V_88 , L_8 , V_124 , V_69 ) ;
return V_69 ;
}
int F_102 ( const struct V_19 * V_20 , struct V_23 * V_24 ,
struct V_1 * V_88 )
{
int V_69 ;
F_48 ( V_20 , V_88 , F_80 ( V_88 , V_24 ) ) ;
F_48 ( V_20 , V_88 , F_57 ( V_88 ) ) ;
V_69 = F_71 ( V_20 , V_24 , V_88 , F_79 ( V_140 ) ) ;
F_62 ( V_99 , V_20 , V_88 , L_7 , V_69 ) ;
return V_69 ;
}
int F_103 ( const struct V_19 * V_20 , struct V_23 * V_24 ,
struct V_1 * V_2 )
{
int V_141 ;
F_48 ( V_20 , V_2 , F_57 ( V_2 ) ) ;
V_141 = F_72 ( V_20 , V_2 , F_79 ( V_142 ) ,
( const struct V_19 * ,
const struct V_5 * , struct V_23 * ) ,
V_24 ) ;
F_16 ( V_20 , V_2 , V_141 != 0 ) ;
return V_141 ;
}
static int F_104 ( const struct V_19 * V_20 , struct V_23 * V_24 ,
struct V_1 * V_2 , void * V_28 )
{
F_83 ( V_20 , V_24 , V_2 ) ;
F_92 ( V_20 , V_24 , V_2 ) ;
F_88 ( V_20 , V_24 , V_2 ) ;
F_87 ( V_20 , V_24 , V_2 ) ;
return V_35 ;
}
int F_105 ( const struct V_19 * V_20 , struct V_21 * V_143 )
{
struct V_144 * V_145 ;
struct V_21 * V_22 = F_13 ( V_143 ) ;
struct V_23 * V_24 ;
int V_69 ;
V_145 = F_12 ( V_20 ) ;
V_24 = & V_145 -> V_146 ;
V_24 -> V_103 = V_22 ;
V_24 -> V_147 = 1 ;
V_69 = F_106 ( V_20 , V_24 , V_148 , V_22 ) ;
if ( V_69 != 0 ) {
F_107 ( V_20 , V_24 ) ;
return V_24 -> V_149 ;
}
do {
V_69 = F_11 ( V_20 , V_22 , V_24 , 0 , V_150 ,
F_104 , NULL ) ;
if ( V_69 == V_48 )
F_108 () ;
} while ( V_69 != V_35 );
F_107 ( V_20 , V_24 ) ;
return V_69 ;
}
void F_109 ( const struct V_19 * V_20 , struct V_1 * V_88 ,
int V_151 , int V_152 )
{
F_48 ( V_20 , V_88 , F_57 ( V_88 ) ) ;
F_62 ( V_99 , V_20 , V_88 , L_8 , V_151 , V_152 ) ;
F_74 ( V_20 , V_88 , F_79 ( V_153 ) ,
( const struct V_19 * ,
const struct V_5 * , int , int ) ,
V_151 , V_152 ) ;
}
void F_110 ( const struct V_19 * V_20 , void * V_154 ,
T_4 V_155 , const struct V_1 * V_88 )
{
(* V_155)( V_20 , V_154 ,
L_9 ,
V_88 , F_4 ( & V_88 -> V_4 ) , V_88 -> V_49 ,
V_88 -> V_40 , V_88 -> V_3 , V_88 -> V_13 ,
V_88 -> V_43 , V_88 -> V_156 , V_88 -> V_41 ,
V_88 -> V_51 , V_88 -> V_52 , V_88 -> V_134 ) ;
}
void F_111 ( const struct V_19 * V_20 , void * V_154 ,
T_4 V_155 , const struct V_1 * V_88 )
{
struct V_1 * V_138 ;
for ( V_138 = F_67 ( (struct V_1 * ) V_88 ) ;
V_138 != NULL ; V_138 = V_138 -> V_13 )
F_110 ( V_20 , V_154 , V_155 , V_138 ) ;
F_72 ( V_20 , (struct V_1 * ) V_88 , F_79 ( V_157 ) ,
( const struct V_19 * V_20 ,
const struct V_5 * V_8 ,
void * V_154 , T_4 V_158 ) , V_154 , V_155 ) ;
(* V_155)( V_20 , V_154 , L_10 , V_88 ) ;
}
int F_112 ( const struct V_19 * V_20 , struct V_1 * V_2 )
{
return F_72 ( V_20 , V_2 , F_79 ( V_159 ) ,
( const struct V_19 * ,
const struct V_5 * ) ) ;
}
T_5 F_113 ( const struct V_21 * V_22 , T_1 V_30 )
{
return ( T_5 ) V_30 << V_160 ;
}
T_1 F_114 ( const struct V_21 * V_22 , T_5 V_161 )
{
return V_161 >> V_160 ;
}
int F_115 ( const struct V_21 * V_22 )
{
return 1 << V_160 ;
}
void F_116 ( struct V_1 * V_2 , struct V_5 * V_8 ,
struct V_21 * V_22 ,
const struct V_162 * V_163 )
{
F_117 ( & V_8 -> V_55 , & V_2 -> V_53 ) ;
V_8 -> V_9 = V_22 ;
V_8 -> V_56 = V_163 ;
V_8 -> V_45 = V_2 ;
}
int F_118 ( void )
{
return 0 ;
}
void F_119 ( void )
{
}
