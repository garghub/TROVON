static inline void
F_1 ( void )
{
F_2 ( & V_1 ) ;
}
static inline void
F_3 ( void )
{
F_4 ( & V_1 ) ;
}
static struct V_2 *
F_5 ( const char * V_3 , T_1 V_4 , T_1 V_5 )
{
struct V_2 * type ;
F_6 (type, &ip_set_type_list, list)
if ( F_7 ( type -> V_3 , V_3 ) &&
( type -> V_4 == V_4 || type -> V_4 == V_6 ) &&
V_5 >= type -> V_7 &&
V_5 <= type -> V_8 )
return type ;
return NULL ;
}
static bool
F_8 ( const char * V_3 )
{
F_9 () ;
F_10 ( L_1 , V_3 ) ;
if ( F_11 ( L_2 , V_3 ) < 0 ) {
F_12 ( L_3 , V_3 ) ;
F_13 () ;
return false ;
}
F_13 () ;
return true ;
}
static int
F_14 ( const char * V_3 , T_1 V_4 , T_1 V_5 ,
struct V_2 * * V_9 , bool V_10 )
{
struct V_2 * type ;
int V_11 ;
if ( V_10 && ! F_8 ( V_3 ) )
return - V_12 ;
F_15 () ;
* V_9 = F_5 ( V_3 , V_4 , V_5 ) ;
if ( * V_9 ) {
V_11 = ! F_16 ( ( * V_9 ) -> V_13 ) ? - V_14 : 0 ;
goto V_15;
}
F_6 (type, &ip_set_type_list, list)
if ( F_7 ( type -> V_3 , V_3 ) ) {
V_11 = - V_12 ;
goto V_15;
}
F_17 () ;
return V_10 ? - V_12 :
F_14 ( V_3 , V_4 , V_5 , V_9 , true ) ;
V_15:
F_17 () ;
return V_11 ;
}
static int
F_18 ( const char * V_3 , T_1 V_4 , T_1 * V_16 , T_1 * V_17 ,
bool V_10 )
{
struct V_2 * type ;
bool V_9 = false ;
if ( V_10 && ! F_8 ( V_3 ) )
return - V_12 ;
* V_16 = 255 ; * V_17 = 0 ;
F_15 () ;
F_6 (type, &ip_set_type_list, list)
if ( F_7 ( type -> V_3 , V_3 ) &&
( type -> V_4 == V_4 || type -> V_4 == V_6 ) ) {
V_9 = true ;
if ( type -> V_7 < * V_16 )
* V_16 = type -> V_7 ;
if ( type -> V_8 > * V_17 )
* V_17 = type -> V_8 ;
}
F_17 () ;
if ( V_9 )
return 0 ;
return V_10 ? - V_12 :
F_18 ( V_3 , V_4 , V_16 , V_17 , true ) ;
}
int
F_19 ( struct V_2 * type )
{
int V_18 = 0 ;
if ( type -> V_19 != V_20 ) {
F_12 ( L_4
L_5 ,
type -> V_3 , F_20 ( type -> V_4 ) ,
type -> V_7 , type -> V_8 ,
type -> V_19 , V_20 ) ;
return - V_21 ;
}
F_1 () ;
if ( F_5 ( type -> V_3 , type -> V_4 , type -> V_7 ) ) {
F_12 ( L_6
L_7 , type -> V_3 ,
F_20 ( type -> V_4 ) , type -> V_7 ) ;
V_18 = - V_21 ;
goto V_15;
}
F_21 ( & type -> V_22 , & V_23 ) ;
F_10 ( L_8 ,
type -> V_3 , F_20 ( type -> V_4 ) ,
type -> V_7 , type -> V_8 ) ;
V_15:
F_3 () ;
return V_18 ;
}
void
F_22 ( struct V_2 * type )
{
F_1 () ;
if ( ! F_5 ( type -> V_3 , type -> V_4 , type -> V_7 ) ) {
F_12 ( L_6
L_9 , type -> V_3 ,
F_20 ( type -> V_4 ) , type -> V_7 ) ;
goto V_15;
}
F_23 ( & type -> V_22 ) ;
F_10 ( L_10 ,
type -> V_3 , F_20 ( type -> V_4 ) , type -> V_7 ) ;
V_15:
F_3 () ;
F_24 () ;
}
void *
F_25 ( T_2 V_24 )
{
void * V_25 = NULL ;
if ( V_24 < V_26 )
V_25 = F_26 ( V_24 , V_27 | V_28 ) ;
if ( V_25 ) {
F_10 ( L_11 , V_25 ) ;
return V_25 ;
}
V_25 = F_27 ( V_24 ) ;
if ( ! V_25 )
return NULL ;
F_10 ( L_12 , V_25 ) ;
return V_25 ;
}
void
F_28 ( void * V_25 )
{
F_10 ( L_13 , V_25 ,
F_29 ( V_25 ) ? L_14 : L_15 ) ;
if ( F_29 ( V_25 ) )
F_30 ( V_25 ) ;
else
F_31 ( V_25 ) ;
}
static inline bool
F_32 ( const struct V_29 * V_30 )
{
return V_30 -> V_31 & V_32 ;
}
int
F_33 ( struct V_29 * V_30 , T_3 * V_33 )
{
struct V_29 * V_34 [ V_35 + 1 ] ;
if ( F_34 ( ! F_32 ( V_30 ) ) )
return - V_36 ;
if ( F_35 ( V_34 , V_35 , V_30 , V_37 ) )
return - V_36 ;
if ( F_34 ( ! F_36 ( V_34 , V_38 ) ) )
return - V_36 ;
* V_33 = F_37 ( V_34 [ V_38 ] ) ;
return 0 ;
}
int
F_38 ( struct V_29 * V_30 , union V_39 * V_33 )
{
struct V_29 * V_34 [ V_35 + 1 ] ;
if ( F_34 ( ! F_32 ( V_30 ) ) )
return - V_36 ;
if ( F_35 ( V_34 , V_35 , V_30 , V_37 ) )
return - V_36 ;
if ( F_34 ( ! F_36 ( V_34 , V_40 ) ) )
return - V_36 ;
memcpy ( V_33 , F_39 ( V_34 [ V_40 ] ) ,
sizeof( struct V_41 ) ) ;
return 0 ;
}
static inline void
F_40 ( T_4 V_42 )
{
F_41 ( & V_43 ) ;
V_44 [ V_42 ] -> V_45 ++ ;
F_42 ( & V_43 ) ;
}
static inline void
F_43 ( T_4 V_42 )
{
F_41 ( & V_43 ) ;
F_44 ( V_44 [ V_42 ] -> V_45 == 0 ) ;
V_44 [ V_42 ] -> V_45 -- ;
F_42 ( & V_43 ) ;
}
int
F_45 ( T_4 V_42 , const struct V_46 * V_47 ,
const struct V_48 * V_49 ,
const struct V_50 * V_51 )
{
struct V_52 * V_53 = V_44 [ V_42 ] ;
int V_18 = 0 ;
F_44 ( V_53 == NULL ) ;
F_10 ( L_16 , V_53 -> V_3 , V_42 ) ;
if ( V_51 -> V_54 < V_53 -> type -> V_55 ||
! ( V_51 -> V_4 == V_53 -> V_4 || V_53 -> V_4 == V_6 ) )
return 0 ;
F_46 ( & V_53 -> V_56 ) ;
V_18 = V_53 -> V_57 -> V_58 ( V_53 , V_47 , V_49 , V_59 , V_51 ) ;
F_47 ( & V_53 -> V_56 ) ;
if ( V_18 == - V_60 ) {
F_10 ( L_17 ) ;
F_41 ( & V_53 -> V_56 ) ;
V_53 -> V_57 -> V_58 ( V_53 , V_47 , V_49 , V_61 , V_51 ) ;
F_42 ( & V_53 -> V_56 ) ;
V_18 = 1 ;
}
return ( V_18 < 0 ? 0 : V_18 ) ;
}
int
F_48 ( T_4 V_42 , const struct V_46 * V_47 ,
const struct V_48 * V_49 ,
const struct V_50 * V_51 )
{
struct V_52 * V_53 = V_44 [ V_42 ] ;
int V_18 ;
F_44 ( V_53 == NULL ) ;
F_10 ( L_16 , V_53 -> V_3 , V_42 ) ;
if ( V_51 -> V_54 < V_53 -> type -> V_55 ||
! ( V_51 -> V_4 == V_53 -> V_4 || V_53 -> V_4 == V_6 ) )
return 0 ;
F_41 ( & V_53 -> V_56 ) ;
V_18 = V_53 -> V_57 -> V_58 ( V_53 , V_47 , V_49 , V_61 , V_51 ) ;
F_42 ( & V_53 -> V_56 ) ;
return V_18 ;
}
int
F_49 ( T_4 V_42 , const struct V_46 * V_47 ,
const struct V_48 * V_49 ,
const struct V_50 * V_51 )
{
struct V_52 * V_53 = V_44 [ V_42 ] ;
int V_18 = 0 ;
F_44 ( V_53 == NULL ) ;
F_10 ( L_16 , V_53 -> V_3 , V_42 ) ;
if ( V_51 -> V_54 < V_53 -> type -> V_55 ||
! ( V_51 -> V_4 == V_53 -> V_4 || V_53 -> V_4 == V_6 ) )
return 0 ;
F_41 ( & V_53 -> V_56 ) ;
V_18 = V_53 -> V_57 -> V_58 ( V_53 , V_47 , V_49 , V_62 , V_51 ) ;
F_42 ( & V_53 -> V_56 ) ;
return V_18 ;
}
T_4
F_50 ( const char * V_3 , struct V_52 * * V_53 )
{
T_4 V_63 , V_42 = V_64 ;
struct V_52 * V_65 ;
for ( V_63 = 0 ; V_63 < V_66 ; V_63 ++ ) {
V_65 = V_44 [ V_63 ] ;
if ( V_65 != NULL && F_7 ( V_65 -> V_3 , V_3 ) ) {
F_40 ( V_63 ) ;
V_42 = V_63 ;
* V_53 = V_65 ;
}
}
return V_42 ;
}
void
F_51 ( T_4 V_42 )
{
if ( V_44 [ V_42 ] != NULL )
F_43 ( V_42 ) ;
}
const char *
F_52 ( T_4 V_42 )
{
const struct V_52 * V_53 = V_44 [ V_42 ] ;
F_44 ( V_53 == NULL ) ;
F_44 ( V_53 -> V_45 == 0 ) ;
return V_53 -> V_3 ;
}
T_4
F_53 ( const char * V_3 )
{
struct V_52 * V_65 ;
T_4 V_42 ;
F_13 () ;
V_42 = F_50 ( V_3 , & V_65 ) ;
F_9 () ;
return V_42 ;
}
T_4
F_54 ( T_4 V_42 )
{
if ( V_42 > V_66 )
return V_64 ;
F_13 () ;
if ( V_44 [ V_42 ] )
F_40 ( V_42 ) ;
else
V_42 = V_64 ;
F_9 () ;
return V_42 ;
}
void
F_55 ( T_4 V_42 )
{
F_13 () ;
F_51 ( V_42 ) ;
F_9 () ;
}
static inline bool
F_56 ( const struct V_29 * const V_34 [] )
{
return ! V_34 [ V_67 ] ||
F_57 ( V_34 [ V_67 ] ) != V_20 ;
}
static inline T_5
F_58 ( const struct V_68 * V_69 )
{
return V_69 -> V_70 & V_71 ? 0 : V_72 ;
}
static struct V_68 *
F_59 ( struct V_46 * V_47 , T_5 V_73 , T_5 V_74 , unsigned int V_75 ,
enum V_76 V_77 )
{
struct V_68 * V_69 ;
struct V_78 * V_79 ;
V_69 = F_60 ( V_47 , V_73 , V_74 , V_77 | ( V_80 << 8 ) ,
sizeof( * V_79 ) , V_75 ) ;
if ( V_69 == NULL )
return NULL ;
V_79 = F_61 ( V_69 ) ;
V_79 -> V_81 = V_82 ;
V_79 -> V_83 = V_84 ;
V_79 -> V_85 = 0 ;
return V_69 ;
}
static T_4
F_62 ( const char * V_3 )
{
T_4 V_63 , V_42 = V_64 ;
const struct V_52 * V_53 ;
for ( V_63 = 0 ; V_42 == V_64 && V_63 < V_66 ; V_63 ++ ) {
V_53 = V_44 [ V_63 ] ;
if ( V_53 != NULL && F_7 ( V_53 -> V_3 , V_3 ) )
V_42 = V_63 ;
}
return V_42 ;
}
static inline struct V_52 *
F_63 ( const char * V_3 )
{
T_4 V_42 = F_62 ( V_3 ) ;
return V_42 == V_64 ? NULL : V_44 [ V_42 ] ;
}
static int
F_64 ( const char * V_3 , T_4 * V_42 , struct V_52 * * V_53 )
{
T_4 V_63 ;
* V_42 = V_64 ;
for ( V_63 = 0 ; V_63 < V_66 ; V_63 ++ ) {
if ( V_44 [ V_63 ] == NULL ) {
if ( * V_42 == V_64 )
* V_42 = V_63 ;
} else if ( F_7 ( V_3 , V_44 [ V_63 ] -> V_3 ) ) {
* V_53 = V_44 [ V_63 ] ;
return - V_86 ;
}
}
if ( * V_42 == V_64 )
return - V_87 ;
return 0 ;
}
static int
F_65 ( struct V_88 * V_89 , struct V_46 * V_47 ,
const struct V_68 * V_69 ,
const struct V_29 * const V_90 [] )
{
struct V_52 * V_53 , * V_91 = NULL ;
T_4 V_42 = V_64 ;
struct V_29 * V_34 [ V_92 + 1 ] = {} ;
const char * V_3 , * V_93 ;
T_1 V_4 , V_5 ;
T_5 V_75 = F_58 ( V_69 ) ;
int V_18 = 0 ;
if ( F_34 ( F_56 ( V_90 ) ||
V_90 [ V_94 ] == NULL ||
V_90 [ V_95 ] == NULL ||
V_90 [ V_96 ] == NULL ||
V_90 [ V_97 ] == NULL ||
( V_90 [ V_98 ] != NULL &&
! F_32 ( V_90 [ V_98 ] ) ) ) )
return - V_36 ;
V_3 = F_39 ( V_90 [ V_94 ] ) ;
V_93 = F_39 ( V_90 [ V_95 ] ) ;
V_4 = F_57 ( V_90 [ V_97 ] ) ;
V_5 = F_57 ( V_90 [ V_96 ] ) ;
F_10 ( L_18 ,
V_3 , V_93 , F_20 ( V_4 ) , V_5 ) ;
V_53 = F_26 ( sizeof( struct V_52 ) , V_27 ) ;
if ( ! V_53 )
return - V_99 ;
F_66 ( & V_53 -> V_56 ) ;
F_67 ( V_53 -> V_3 , V_3 , V_100 ) ;
V_53 -> V_4 = V_4 ;
V_53 -> V_5 = V_5 ;
V_18 = F_68 ( V_93 , V_4 , V_5 , & ( V_53 -> type ) ) ;
if ( V_18 )
goto V_101;
if ( V_90 [ V_98 ] &&
F_35 ( V_34 , V_92 , V_90 [ V_98 ] ,
V_53 -> type -> V_102 ) ) {
V_18 = - V_36 ;
goto V_103;
}
V_18 = V_53 -> type -> V_104 ( V_53 , V_34 , V_75 ) ;
if ( V_18 != 0 )
goto V_103;
if ( ( V_18 = F_64 ( V_53 -> V_3 , & V_42 , & V_91 ) ) != 0 ) {
if ( V_18 == - V_86 &&
( V_75 & V_72 ) &&
F_7 ( V_53 -> type -> V_3 , V_91 -> type -> V_3 ) &&
V_53 -> type -> V_4 == V_91 -> type -> V_4 &&
V_53 -> type -> V_7 == V_91 -> type -> V_7 &&
V_53 -> type -> V_8 == V_91 -> type -> V_8 &&
V_53 -> V_57 -> V_105 ( V_53 , V_91 ) )
V_18 = 0 ;
goto V_106;
}
F_10 ( L_19 , V_53 -> V_3 , V_42 ) ;
V_44 [ V_42 ] = V_53 ;
return V_18 ;
V_106:
V_53 -> V_57 -> V_107 ( V_53 ) ;
V_103:
F_69 ( V_53 -> type -> V_13 ) ;
V_101:
F_31 ( V_53 ) ;
return V_18 ;
}
static void
F_70 ( T_4 V_42 )
{
struct V_52 * V_53 = V_44 [ V_42 ] ;
F_10 ( L_20 , V_53 -> V_3 ) ;
V_44 [ V_42 ] = NULL ;
V_53 -> V_57 -> V_107 ( V_53 ) ;
F_69 ( V_53 -> type -> V_13 ) ;
F_31 ( V_53 ) ;
}
static int
F_71 ( struct V_88 * V_89 , struct V_46 * V_47 ,
const struct V_68 * V_69 ,
const struct V_29 * const V_90 [] )
{
T_4 V_63 ;
int V_18 = 0 ;
if ( F_34 ( F_56 ( V_90 ) ) )
return - V_36 ;
F_46 ( & V_43 ) ;
if ( ! V_90 [ V_94 ] ) {
for ( V_63 = 0 ; V_63 < V_66 ; V_63 ++ ) {
if ( V_44 [ V_63 ] != NULL && V_44 [ V_63 ] -> V_45 ) {
V_18 = - V_108 ;
goto V_101;
}
}
F_47 ( & V_43 ) ;
for ( V_63 = 0 ; V_63 < V_66 ; V_63 ++ ) {
if ( V_44 [ V_63 ] != NULL )
F_70 ( V_63 ) ;
}
} else {
V_63 = F_62 ( F_39 ( V_90 [ V_94 ] ) ) ;
if ( V_63 == V_64 ) {
V_18 = - V_109 ;
goto V_101;
} else if ( V_44 [ V_63 ] -> V_45 ) {
V_18 = - V_108 ;
goto V_101;
}
F_47 ( & V_43 ) ;
F_70 ( V_63 ) ;
}
return 0 ;
V_101:
F_47 ( & V_43 ) ;
return V_18 ;
}
static void
F_72 ( struct V_52 * V_53 )
{
F_10 ( L_20 , V_53 -> V_3 ) ;
F_41 ( & V_53 -> V_56 ) ;
V_53 -> V_57 -> V_110 ( V_53 ) ;
F_42 ( & V_53 -> V_56 ) ;
}
static int
F_73 ( struct V_88 * V_89 , struct V_46 * V_47 ,
const struct V_68 * V_69 ,
const struct V_29 * const V_90 [] )
{
T_4 V_63 ;
if ( F_34 ( F_56 ( V_90 ) ) )
return - V_36 ;
if ( ! V_90 [ V_94 ] ) {
for ( V_63 = 0 ; V_63 < V_66 ; V_63 ++ )
if ( V_44 [ V_63 ] != NULL )
F_72 ( V_44 [ V_63 ] ) ;
} else {
V_63 = F_62 ( F_39 ( V_90 [ V_94 ] ) ) ;
if ( V_63 == V_64 )
return - V_109 ;
F_72 ( V_44 [ V_63 ] ) ;
}
return 0 ;
}
static int
F_74 ( struct V_88 * V_89 , struct V_46 * V_47 ,
const struct V_68 * V_69 ,
const struct V_29 * const V_90 [] )
{
struct V_52 * V_53 ;
const char * V_111 ;
T_4 V_63 ;
int V_18 = 0 ;
if ( F_34 ( F_56 ( V_90 ) ||
V_90 [ V_94 ] == NULL ||
V_90 [ V_112 ] == NULL ) )
return - V_36 ;
V_53 = F_63 ( F_39 ( V_90 [ V_94 ] ) ) ;
if ( V_53 == NULL )
return - V_109 ;
F_46 ( & V_43 ) ;
if ( V_53 -> V_45 != 0 ) {
V_18 = - V_113 ;
goto V_101;
}
V_111 = F_39 ( V_90 [ V_112 ] ) ;
for ( V_63 = 0 ; V_63 < V_66 ; V_63 ++ ) {
if ( V_44 [ V_63 ] != NULL &&
F_7 ( V_44 [ V_63 ] -> V_3 , V_111 ) ) {
V_18 = - V_114 ;
goto V_101;
}
}
strncpy ( V_53 -> V_3 , V_111 , V_100 ) ;
V_101:
F_47 ( & V_43 ) ;
return V_18 ;
}
static int
F_75 ( struct V_88 * V_89 , struct V_46 * V_47 ,
const struct V_68 * V_69 ,
const struct V_29 * const V_90 [] )
{
struct V_52 * V_115 , * V_116 ;
T_4 V_117 , V_118 ;
char V_119 [ V_100 ] ;
if ( F_34 ( F_56 ( V_90 ) ||
V_90 [ V_94 ] == NULL ||
V_90 [ V_112 ] == NULL ) )
return - V_36 ;
V_117 = F_62 ( F_39 ( V_90 [ V_94 ] ) ) ;
if ( V_117 == V_64 )
return - V_109 ;
V_118 = F_62 ( F_39 ( V_90 [ V_112 ] ) ) ;
if ( V_118 == V_64 )
return - V_114 ;
V_115 = V_44 [ V_117 ] ;
V_116 = V_44 [ V_118 ] ;
if ( ! ( V_115 -> type -> V_120 == V_116 -> type -> V_120 &&
V_115 -> type -> V_4 == V_116 -> type -> V_4 ) )
return - V_121 ;
strncpy ( V_119 , V_115 -> V_3 , V_100 ) ;
strncpy ( V_115 -> V_3 , V_116 -> V_3 , V_100 ) ;
strncpy ( V_116 -> V_3 , V_119 , V_100 ) ;
F_41 ( & V_43 ) ;
F_76 ( V_115 -> V_45 , V_116 -> V_45 ) ;
V_44 [ V_117 ] = V_116 ;
V_44 [ V_118 ] = V_115 ;
F_42 ( & V_43 ) ;
return 0 ;
}
static int
F_77 ( struct V_122 * V_123 )
{
if ( V_123 -> args [ 2 ] ) {
F_10 ( L_21 , V_44 [ V_123 -> args [ 1 ] ] -> V_3 ) ;
F_51 ( ( T_4 ) V_123 -> args [ 1 ] ) ;
}
return 0 ;
}
static inline void
F_78 ( struct V_68 * V_69 )
{
const struct V_29 * V_90 ;
int V_124 ;
F_10 ( L_22 ) ;
F_79 (attr, nlh, sizeof(struct nfgenmsg), rem) {
F_10 ( L_23 , V_31 ( V_90 ) , V_90 -> V_125 ) ;
}
}
static int
F_80 ( struct V_122 * V_123 )
{
struct V_68 * V_69 = F_81 ( V_123 -> V_47 ) ;
int V_126 = F_82 ( sizeof( struct V_78 ) ) ;
struct V_29 * V_127 [ V_128 + 1 ] ;
struct V_29 * V_90 = ( void * ) V_69 + V_126 ;
T_5 V_129 ;
T_4 V_42 ;
F_83 ( V_127 , V_128 ,
V_90 , V_69 -> V_130 - V_126 , V_131 ) ;
if ( V_127 [ V_94 ] ) {
V_42 = F_62 ( F_39 ( V_127 [ V_94 ] ) ) ;
if ( V_42 == V_64 )
return - V_109 ;
V_129 = V_132 ;
V_123 -> args [ 1 ] = V_42 ;
} else
V_129 = V_133 ;
if ( V_127 [ V_134 ] ) {
T_5 V_135 = F_84 ( V_127 [ V_134 ] ) ;
V_129 |= ( V_135 << 16 ) ;
}
V_123 -> args [ 0 ] = V_129 ;
return 0 ;
}
static int
F_85 ( struct V_46 * V_47 , struct V_122 * V_123 )
{
T_4 V_42 = V_64 , V_17 ;
struct V_52 * V_53 = NULL ;
struct V_68 * V_69 = NULL ;
unsigned int V_75 = F_86 ( V_123 -> V_47 ) . V_73 ? V_136 : 0 ;
T_5 V_129 , V_137 ;
int V_18 = 0 ;
if ( ! V_123 -> args [ 0 ] ) {
V_18 = F_80 ( V_123 ) ;
if ( V_18 < 0 ) {
V_69 = F_81 ( V_123 -> V_47 ) ;
if ( V_69 -> V_70 & V_138 )
F_87 ( V_123 -> V_47 , V_69 , V_18 ) ;
return V_18 ;
}
}
if ( V_123 -> args [ 1 ] >= V_66 )
goto V_101;
V_129 = F_88 ( V_123 -> args [ 0 ] ) ;
V_137 = F_89 ( V_123 -> args [ 0 ] ) ;
V_17 = V_129 == V_132 ? V_123 -> args [ 1 ] + 1 : V_66 ;
V_139:
F_10 ( L_24 ,
V_129 , V_137 , V_123 -> args [ 1 ] ) ;
for (; V_123 -> args [ 1 ] < V_17 ; V_123 -> args [ 1 ] ++ ) {
V_42 = ( T_4 ) V_123 -> args [ 1 ] ;
V_53 = V_44 [ V_42 ] ;
if ( V_53 == NULL ) {
if ( V_129 == V_132 ) {
V_18 = - V_109 ;
goto V_101;
}
continue;
}
if ( V_129 != V_132 &&
( ( V_129 == V_133 ) ==
! ! ( V_53 -> type -> V_120 & V_140 ) ) )
continue;
F_10 ( L_25 , V_53 -> V_3 ) ;
if ( ! V_123 -> args [ 2 ] ) {
F_10 ( L_26 ) ;
F_40 ( V_42 ) ;
}
V_69 = F_59 ( V_47 , F_86 ( V_123 -> V_47 ) . V_73 ,
V_123 -> V_69 -> V_141 , V_75 ,
V_142 ) ;
if ( ! V_69 ) {
V_18 = - V_143 ;
goto V_144;
}
F_90 ( V_47 , V_67 , V_20 ) ;
F_91 ( V_47 , V_94 , V_53 -> V_3 ) ;
if ( V_137 & V_145 )
goto V_146;
switch ( V_123 -> args [ 2 ] ) {
case 0 :
F_91 ( V_47 , V_95 ,
V_53 -> type -> V_3 ) ;
F_90 ( V_47 , V_97 ,
V_53 -> V_4 ) ;
F_90 ( V_47 , V_96 ,
V_53 -> V_5 ) ;
V_18 = V_53 -> V_57 -> V_147 ( V_53 , V_47 ) ;
if ( V_18 < 0 )
goto V_144;
if ( V_137 & V_148 )
goto V_146;
default:
F_46 ( & V_53 -> V_56 ) ;
V_18 = V_53 -> V_57 -> V_22 ( V_53 , V_47 , V_123 ) ;
F_47 ( & V_53 -> V_56 ) ;
if ( ! V_123 -> args [ 2 ] )
goto V_146;
goto V_144;
}
}
if ( V_129 == V_133 ) {
V_129 = V_149 ;
V_123 -> args [ 0 ] = V_129 | ( V_137 << 16 ) ;
V_123 -> args [ 1 ] = 0 ;
goto V_139;
}
goto V_101;
V_150:
V_18 = - V_14 ;
V_146:
if ( V_129 == V_132 )
V_123 -> args [ 1 ] = V_64 ;
else
V_123 -> args [ 1 ] ++ ;
V_144:
if ( V_18 || ! V_123 -> args [ 2 ] ) {
F_10 ( L_21 , V_44 [ V_42 ] -> V_3 ) ;
F_51 ( V_42 ) ;
V_123 -> args [ 2 ] = 0 ;
}
V_101:
if ( V_69 ) {
F_92 ( V_47 , V_69 ) ;
F_10 ( L_27 , V_69 -> V_130 ) ;
F_78 ( V_69 ) ;
}
return V_18 < 0 ? V_18 : V_47 -> V_151 ;
}
static int
F_93 ( struct V_88 * V_89 , struct V_46 * V_47 ,
const struct V_68 * V_69 ,
const struct V_29 * const V_90 [] )
{
if ( F_34 ( F_56 ( V_90 ) ) )
return - V_36 ;
return F_94 ( V_89 , V_47 , V_69 ,
F_85 ,
F_77 , 0 ) ;
}
static int
F_95 ( struct V_88 * V_89 , struct V_46 * V_47 , struct V_52 * V_53 ,
struct V_29 * V_34 [] , enum V_152 V_153 ,
T_5 V_75 , bool V_154 )
{
int V_18 ;
T_5 V_155 = 0 ;
bool V_156 = V_75 & V_72 , V_157 = false ;
do {
F_41 ( & V_53 -> V_56 ) ;
V_18 = V_53 -> V_57 -> V_158 ( V_53 , V_34 , V_153 , & V_155 , V_75 , V_157 ) ;
F_42 ( & V_53 -> V_56 ) ;
V_157 = true ;
} while ( V_18 == - V_60 &&
V_53 -> V_57 -> V_159 &&
( V_18 = V_53 -> V_57 -> V_159 ( V_53 , V_157 ) ) == 0 );
if ( ! V_18 || ( V_18 == - V_160 && V_156 ) )
return 0 ;
if ( V_155 && V_154 ) {
struct V_68 * V_161 , * V_69 = F_81 ( V_47 ) ;
struct V_46 * V_162 ;
struct V_163 * V_164 ;
T_2 V_165 = sizeof( * V_164 ) + V_130 ( V_69 ) ;
int V_126 = F_82 ( sizeof( struct V_78 ) ) ;
struct V_29 * V_127 [ V_128 + 1 ] ;
struct V_29 * V_166 ;
T_5 * V_167 ;
V_162 = F_96 ( V_165 , V_27 ) ;
if ( V_162 == NULL )
return - V_99 ;
V_161 = F_97 ( V_162 , F_86 ( V_47 ) . V_73 ,
V_69 -> V_141 , V_168 , V_165 , 0 ) ;
V_164 = F_61 ( V_161 ) ;
V_164 -> error = V_18 ;
memcpy ( & V_164 -> V_169 , V_69 , V_69 -> V_130 ) ;
V_166 = ( void * ) & V_164 -> V_169 + V_126 ;
F_83 ( V_127 , V_128 ,
V_166 , V_69 -> V_130 - V_126 ,
V_170 ) ;
V_167 = F_39 ( V_127 [ V_171 ] ) ;
* V_167 = V_155 ;
F_98 ( V_89 , V_162 , F_86 ( V_47 ) . V_73 , V_172 ) ;
return - V_173 ;
}
return V_18 ;
}
static int
F_99 ( struct V_88 * V_89 , struct V_46 * V_47 ,
const struct V_68 * V_69 ,
const struct V_29 * const V_90 [] )
{
struct V_52 * V_53 ;
struct V_29 * V_34 [ V_174 + 1 ] = {} ;
const struct V_29 * V_30 ;
T_5 V_75 = F_58 ( V_69 ) ;
bool V_154 ;
int V_18 = 0 ;
if ( F_34 ( F_56 ( V_90 ) ||
V_90 [ V_94 ] == NULL ||
! ( ( V_90 [ V_98 ] != NULL ) ^
( V_90 [ V_175 ] != NULL ) ) ||
( V_90 [ V_98 ] != NULL &&
! F_32 ( V_90 [ V_98 ] ) ) ||
( V_90 [ V_175 ] != NULL &&
( ! F_32 ( V_90 [ V_175 ] ) ||
V_90 [ V_171 ] == NULL ) ) ) )
return - V_36 ;
V_53 = F_63 ( F_39 ( V_90 [ V_94 ] ) ) ;
if ( V_53 == NULL )
return - V_109 ;
V_154 = ! ! V_90 [ V_171 ] ;
if ( V_90 [ V_98 ] ) {
if ( F_35 ( V_34 , V_174 ,
V_90 [ V_98 ] ,
V_53 -> type -> V_176 ) )
return - V_36 ;
V_18 = F_95 ( V_89 , V_47 , V_53 , V_34 , V_61 , V_75 ,
V_154 ) ;
} else {
int V_177 ;
F_100 (nla, attr[IPSET_ATTR_ADT], nla_rem) {
memset ( V_34 , 0 , sizeof( V_34 ) ) ;
if ( V_31 ( V_30 ) != V_98 ||
! F_32 ( V_30 ) ||
F_35 ( V_34 , V_174 , V_30 ,
V_53 -> type -> V_176 ) )
return - V_36 ;
V_18 = F_95 ( V_89 , V_47 , V_53 , V_34 , V_61 ,
V_75 , V_154 ) ;
if ( V_18 < 0 )
return V_18 ;
}
}
return V_18 ;
}
static int
F_101 ( struct V_88 * V_89 , struct V_46 * V_47 ,
const struct V_68 * V_69 ,
const struct V_29 * const V_90 [] )
{
struct V_52 * V_53 ;
struct V_29 * V_34 [ V_174 + 1 ] = {} ;
const struct V_29 * V_30 ;
T_5 V_75 = F_58 ( V_69 ) ;
bool V_154 ;
int V_18 = 0 ;
if ( F_34 ( F_56 ( V_90 ) ||
V_90 [ V_94 ] == NULL ||
! ( ( V_90 [ V_98 ] != NULL ) ^
( V_90 [ V_175 ] != NULL ) ) ||
( V_90 [ V_98 ] != NULL &&
! F_32 ( V_90 [ V_98 ] ) ) ||
( V_90 [ V_175 ] != NULL &&
( ! F_32 ( V_90 [ V_175 ] ) ||
V_90 [ V_171 ] == NULL ) ) ) )
return - V_36 ;
V_53 = F_63 ( F_39 ( V_90 [ V_94 ] ) ) ;
if ( V_53 == NULL )
return - V_109 ;
V_154 = ! ! V_90 [ V_171 ] ;
if ( V_90 [ V_98 ] ) {
if ( F_35 ( V_34 , V_174 ,
V_90 [ V_98 ] ,
V_53 -> type -> V_176 ) )
return - V_36 ;
V_18 = F_95 ( V_89 , V_47 , V_53 , V_34 , V_62 , V_75 ,
V_154 ) ;
} else {
int V_177 ;
F_100 (nla, attr[IPSET_ATTR_ADT], nla_rem) {
memset ( V_34 , 0 , sizeof( * V_34 ) ) ;
if ( V_31 ( V_30 ) != V_98 ||
! F_32 ( V_30 ) ||
F_35 ( V_34 , V_174 , V_30 ,
V_53 -> type -> V_176 ) )
return - V_36 ;
V_18 = F_95 ( V_89 , V_47 , V_53 , V_34 , V_62 ,
V_75 , V_154 ) ;
if ( V_18 < 0 )
return V_18 ;
}
}
return V_18 ;
}
static int
F_102 ( struct V_88 * V_89 , struct V_46 * V_47 ,
const struct V_68 * V_69 ,
const struct V_29 * const V_90 [] )
{
struct V_52 * V_53 ;
struct V_29 * V_34 [ V_174 + 1 ] = {} ;
int V_18 = 0 ;
if ( F_34 ( F_56 ( V_90 ) ||
V_90 [ V_94 ] == NULL ||
V_90 [ V_98 ] == NULL ||
! F_32 ( V_90 [ V_98 ] ) ) )
return - V_36 ;
V_53 = F_63 ( F_39 ( V_90 [ V_94 ] ) ) ;
if ( V_53 == NULL )
return - V_109 ;
if ( F_35 ( V_34 , V_174 , V_90 [ V_98 ] ,
V_53 -> type -> V_176 ) )
return - V_36 ;
F_46 ( & V_53 -> V_56 ) ;
V_18 = V_53 -> V_57 -> V_158 ( V_53 , V_34 , V_59 , NULL , 0 , 0 ) ;
F_47 ( & V_53 -> V_56 ) ;
if ( V_18 == - V_60 )
V_18 = 1 ;
return V_18 < 0 ? V_18 : V_18 > 0 ? 0 : - V_160 ;
}
static int
F_103 ( struct V_88 * V_89 , struct V_46 * V_47 ,
const struct V_68 * V_69 ,
const struct V_29 * const V_90 [] )
{
const struct V_52 * V_53 ;
struct V_46 * V_162 ;
struct V_68 * V_178 ;
T_4 V_42 ;
int V_18 = 0 ;
if ( F_34 ( F_56 ( V_90 ) ||
V_90 [ V_94 ] == NULL ) )
return - V_36 ;
V_42 = F_62 ( F_39 ( V_90 [ V_94 ] ) ) ;
if ( V_42 == V_64 )
return - V_109 ;
V_53 = V_44 [ V_42 ] ;
V_162 = F_96 ( V_179 , V_27 ) ;
if ( V_162 == NULL )
return - V_99 ;
V_178 = F_59 ( V_162 , F_86 ( V_47 ) . V_73 , V_69 -> V_141 , 0 ,
V_180 ) ;
if ( ! V_178 )
goto V_181;
F_90 ( V_162 , V_67 , V_20 ) ;
F_91 ( V_162 , V_94 , V_53 -> V_3 ) ;
F_91 ( V_162 , V_95 , V_53 -> type -> V_3 ) ;
F_90 ( V_162 , V_97 , V_53 -> V_4 ) ;
F_90 ( V_162 , V_96 , V_53 -> V_5 ) ;
F_92 ( V_162 , V_178 ) ;
V_18 = F_98 ( V_89 , V_162 , F_86 ( V_47 ) . V_73 , V_172 ) ;
if ( V_18 < 0 )
return V_18 ;
return 0 ;
V_150:
F_104 ( V_162 , V_178 ) ;
V_181:
F_105 ( V_162 ) ;
return - V_143 ;
}
static int
V_2 ( struct V_88 * V_89 , struct V_46 * V_47 ,
const struct V_68 * V_69 ,
const struct V_29 * const V_90 [] )
{
struct V_46 * V_162 ;
struct V_68 * V_178 ;
T_1 V_4 , V_16 , V_17 ;
const char * V_93 ;
int V_18 = 0 ;
if ( F_34 ( F_56 ( V_90 ) ||
V_90 [ V_95 ] == NULL ||
V_90 [ V_97 ] == NULL ) )
return - V_36 ;
V_4 = F_57 ( V_90 [ V_97 ] ) ;
V_93 = F_39 ( V_90 [ V_95 ] ) ;
V_18 = F_106 ( V_93 , V_4 , & V_16 , & V_17 ) ;
if ( V_18 )
return V_18 ;
V_162 = F_96 ( V_179 , V_27 ) ;
if ( V_162 == NULL )
return - V_99 ;
V_178 = F_59 ( V_162 , F_86 ( V_47 ) . V_73 , V_69 -> V_141 , 0 ,
V_182 ) ;
if ( ! V_178 )
goto V_181;
F_90 ( V_162 , V_67 , V_20 ) ;
F_91 ( V_162 , V_95 , V_93 ) ;
F_90 ( V_162 , V_97 , V_4 ) ;
F_90 ( V_162 , V_96 , V_17 ) ;
F_90 ( V_162 , V_183 , V_16 ) ;
F_92 ( V_162 , V_178 ) ;
F_10 ( L_28 , V_178 -> V_130 ) ;
V_18 = F_98 ( V_89 , V_162 , F_86 ( V_47 ) . V_73 , V_172 ) ;
if ( V_18 < 0 )
return V_18 ;
return 0 ;
V_150:
F_104 ( V_162 , V_178 ) ;
V_181:
F_105 ( V_162 ) ;
return - V_143 ;
}
static int
F_107 ( struct V_88 * V_89 , struct V_46 * V_47 ,
const struct V_68 * V_69 ,
const struct V_29 * const V_90 [] )
{
struct V_46 * V_162 ;
struct V_68 * V_178 ;
int V_18 = 0 ;
if ( F_34 ( V_90 [ V_67 ] == NULL ) )
return - V_36 ;
V_162 = F_96 ( V_179 , V_27 ) ;
if ( V_162 == NULL )
return - V_99 ;
V_178 = F_59 ( V_162 , F_86 ( V_47 ) . V_73 , V_69 -> V_141 , 0 ,
V_184 ) ;
if ( ! V_178 )
goto V_181;
F_90 ( V_162 , V_67 , V_20 ) ;
F_92 ( V_162 , V_178 ) ;
V_18 = F_98 ( V_89 , V_162 , F_86 ( V_47 ) . V_73 , V_172 ) ;
if ( V_18 < 0 )
return V_18 ;
return 0 ;
V_150:
F_104 ( V_162 , V_178 ) ;
V_181:
F_105 ( V_162 ) ;
return - V_143 ;
}
static int
F_108 ( struct V_88 * V_185 , int V_186 , void T_6 * V_187 , int * V_151 )
{
unsigned * V_188 ;
void * V_189 ;
int V_190 = * V_151 , V_18 = 0 ;
if ( ! F_109 ( V_191 ) )
return - V_192 ;
if ( V_186 != V_193 )
return - V_194 ;
if ( * V_151 < sizeof( unsigned ) )
return - V_21 ;
V_189 = F_110 ( * V_151 ) ;
if ( ! V_189 )
return - V_99 ;
if ( F_111 ( V_189 , V_187 , * V_151 ) != 0 ) {
V_18 = - V_14 ;
goto V_195;
}
V_188 = ( unsigned * ) V_189 ;
if ( * V_188 < V_196 ) {
struct V_197 * V_198 = V_189 ;
if ( V_198 -> V_83 != V_20 ) {
V_18 = - V_199 ;
goto V_195;
}
}
switch ( * V_188 ) {
case V_196 : {
struct V_197 * V_198 = V_189 ;
if ( * V_151 != sizeof( struct V_197 ) ) {
V_18 = - V_21 ;
goto V_195;
}
V_198 -> V_83 = V_20 ;
V_18 = F_112 ( V_187 , V_198 ,
sizeof( struct V_197 ) ) ;
goto V_195;
}
case V_200 : {
struct V_201 * V_202 = V_189 ;
if ( * V_151 != sizeof( struct V_201 ) ) {
V_18 = - V_21 ;
goto V_195;
}
V_202 -> V_53 . V_3 [ V_100 - 1 ] = '\0' ;
F_13 () ;
V_202 -> V_53 . V_42 = F_62 ( V_202 -> V_53 . V_3 ) ;
F_9 () ;
goto V_203;
}
case V_204 : {
struct V_201 * V_202 = V_189 ;
if ( * V_151 != sizeof( struct V_201 ) ||
V_202 -> V_53 . V_42 >= V_66 ) {
V_18 = - V_21 ;
goto V_195;
}
F_13 () ;
strncpy ( V_202 -> V_53 . V_3 ,
V_44 [ V_202 -> V_53 . V_42 ]
? V_44 [ V_202 -> V_53 . V_42 ] -> V_3 : L_29 ,
V_100 ) ;
F_9 () ;
goto V_203;
}
default:
V_18 = - V_205 ;
goto V_195;
}
V_203:
V_18 = F_112 ( V_187 , V_189 , V_190 ) ;
V_195:
F_30 ( V_189 ) ;
if ( V_18 > 0 )
V_18 = 0 ;
return V_18 ;
}
static int T_7
F_113 ( void )
{
int V_18 ;
if ( V_206 )
V_66 = V_206 ;
if ( V_66 >= V_64 )
V_66 = V_64 - 1 ;
V_44 = F_26 ( sizeof( struct V_52 * ) * V_66 ,
V_27 ) ;
if ( ! V_44 )
return - V_99 ;
V_18 = F_114 ( & V_207 ) ;
if ( V_18 != 0 ) {
F_115 ( L_30 ) ;
F_31 ( V_44 ) ;
return V_18 ;
}
V_18 = F_116 ( & V_208 ) ;
if ( V_18 != 0 ) {
F_115 ( L_31 , V_18 ) ;
F_117 ( & V_207 ) ;
F_31 ( V_44 ) ;
return V_18 ;
}
F_118 ( L_32 , V_20 ) ;
return 0 ;
}
static void T_8
F_119 ( void )
{
F_120 ( & V_208 ) ;
F_117 ( & V_207 ) ;
F_31 ( V_44 ) ;
F_10 ( L_33 ) ;
}
