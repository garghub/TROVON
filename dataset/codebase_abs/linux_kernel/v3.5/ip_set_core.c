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
return - V_91 ;
}
static int
F_66 ( struct V_88 * V_89 , struct V_46 * V_47 ,
const struct V_68 * V_69 ,
const struct V_29 * const V_90 [] )
{
struct V_52 * V_53 , * V_92 = NULL ;
T_4 V_42 = V_64 ;
struct V_29 * V_34 [ V_93 + 1 ] = {} ;
const char * V_3 , * V_94 ;
T_1 V_4 , V_5 ;
T_5 V_75 = F_58 ( V_69 ) ;
int V_18 = 0 ;
if ( F_34 ( F_56 ( V_90 ) ||
V_90 [ V_95 ] == NULL ||
V_90 [ V_96 ] == NULL ||
V_90 [ V_97 ] == NULL ||
V_90 [ V_98 ] == NULL ||
( V_90 [ V_99 ] != NULL &&
! F_32 ( V_90 [ V_99 ] ) ) ) )
return - V_36 ;
V_3 = F_39 ( V_90 [ V_95 ] ) ;
V_94 = F_39 ( V_90 [ V_96 ] ) ;
V_4 = F_57 ( V_90 [ V_98 ] ) ;
V_5 = F_57 ( V_90 [ V_97 ] ) ;
F_10 ( L_18 ,
V_3 , V_94 , F_20 ( V_4 ) , V_5 ) ;
V_53 = F_26 ( sizeof( struct V_52 ) , V_27 ) ;
if ( ! V_53 )
return - V_100 ;
F_67 ( & V_53 -> V_56 ) ;
F_68 ( V_53 -> V_3 , V_3 , V_101 ) ;
V_53 -> V_4 = V_4 ;
V_53 -> V_5 = V_5 ;
V_18 = F_69 ( V_94 , V_4 , V_5 , & ( V_53 -> type ) ) ;
if ( V_18 )
goto V_102;
if ( V_90 [ V_99 ] &&
F_35 ( V_34 , V_93 , V_90 [ V_99 ] ,
V_53 -> type -> V_103 ) ) {
V_18 = - V_36 ;
goto V_104;
}
V_18 = V_53 -> type -> V_105 ( V_53 , V_34 , V_75 ) ;
if ( V_18 != 0 )
goto V_104;
if ( ( V_18 = F_64 ( V_53 -> V_3 , & V_42 , & V_92 ) ) != 0 ) {
if ( V_18 == - V_86 &&
( V_75 & V_72 ) &&
F_7 ( V_53 -> type -> V_3 , V_92 -> type -> V_3 ) &&
V_53 -> type -> V_4 == V_92 -> type -> V_4 &&
V_53 -> type -> V_7 == V_92 -> type -> V_7 &&
V_53 -> type -> V_8 == V_92 -> type -> V_8 &&
V_53 -> V_57 -> V_106 ( V_53 , V_92 ) )
V_18 = 0 ;
goto V_107;
}
F_10 ( L_19 , V_53 -> V_3 , V_42 ) ;
V_44 [ V_42 ] = V_53 ;
return V_18 ;
V_107:
V_53 -> V_57 -> V_108 ( V_53 ) ;
V_104:
F_70 ( V_53 -> type -> V_13 ) ;
V_102:
F_31 ( V_53 ) ;
return V_18 ;
}
static void
F_71 ( T_4 V_42 )
{
struct V_52 * V_53 = V_44 [ V_42 ] ;
F_10 ( L_20 , V_53 -> V_3 ) ;
V_44 [ V_42 ] = NULL ;
V_53 -> V_57 -> V_108 ( V_53 ) ;
F_70 ( V_53 -> type -> V_13 ) ;
F_31 ( V_53 ) ;
}
static int
F_72 ( struct V_88 * V_89 , struct V_46 * V_47 ,
const struct V_68 * V_69 ,
const struct V_29 * const V_90 [] )
{
T_4 V_63 ;
int V_18 = 0 ;
if ( F_34 ( F_56 ( V_90 ) ) )
return - V_36 ;
F_46 ( & V_43 ) ;
if ( ! V_90 [ V_95 ] ) {
for ( V_63 = 0 ; V_63 < V_66 ; V_63 ++ ) {
if ( V_44 [ V_63 ] != NULL && V_44 [ V_63 ] -> V_45 ) {
V_18 = - V_109 ;
goto V_102;
}
}
F_47 ( & V_43 ) ;
for ( V_63 = 0 ; V_63 < V_66 ; V_63 ++ ) {
if ( V_44 [ V_63 ] != NULL )
F_71 ( V_63 ) ;
}
} else {
V_63 = F_62 ( F_39 ( V_90 [ V_95 ] ) ) ;
if ( V_63 == V_64 ) {
V_18 = - V_110 ;
goto V_102;
} else if ( V_44 [ V_63 ] -> V_45 ) {
V_18 = - V_109 ;
goto V_102;
}
F_47 ( & V_43 ) ;
F_71 ( V_63 ) ;
}
return 0 ;
V_102:
F_47 ( & V_43 ) ;
return V_18 ;
}
static void
F_73 ( struct V_52 * V_53 )
{
F_10 ( L_20 , V_53 -> V_3 ) ;
F_41 ( & V_53 -> V_56 ) ;
V_53 -> V_57 -> V_111 ( V_53 ) ;
F_42 ( & V_53 -> V_56 ) ;
}
static int
F_74 ( struct V_88 * V_89 , struct V_46 * V_47 ,
const struct V_68 * V_69 ,
const struct V_29 * const V_90 [] )
{
T_4 V_63 ;
if ( F_34 ( F_56 ( V_90 ) ) )
return - V_36 ;
if ( ! V_90 [ V_95 ] ) {
for ( V_63 = 0 ; V_63 < V_66 ; V_63 ++ )
if ( V_44 [ V_63 ] != NULL )
F_73 ( V_44 [ V_63 ] ) ;
} else {
V_63 = F_62 ( F_39 ( V_90 [ V_95 ] ) ) ;
if ( V_63 == V_64 )
return - V_110 ;
F_73 ( V_44 [ V_63 ] ) ;
}
return 0 ;
}
static int
F_75 ( struct V_88 * V_89 , struct V_46 * V_47 ,
const struct V_68 * V_69 ,
const struct V_29 * const V_90 [] )
{
struct V_52 * V_53 ;
const char * V_112 ;
T_4 V_63 ;
int V_18 = 0 ;
if ( F_34 ( F_56 ( V_90 ) ||
V_90 [ V_95 ] == NULL ||
V_90 [ V_113 ] == NULL ) )
return - V_36 ;
V_53 = F_63 ( F_39 ( V_90 [ V_95 ] ) ) ;
if ( V_53 == NULL )
return - V_110 ;
F_46 ( & V_43 ) ;
if ( V_53 -> V_45 != 0 ) {
V_18 = - V_114 ;
goto V_102;
}
V_112 = F_39 ( V_90 [ V_113 ] ) ;
for ( V_63 = 0 ; V_63 < V_66 ; V_63 ++ ) {
if ( V_44 [ V_63 ] != NULL &&
F_7 ( V_44 [ V_63 ] -> V_3 , V_112 ) ) {
V_18 = - V_115 ;
goto V_102;
}
}
strncpy ( V_53 -> V_3 , V_112 , V_101 ) ;
V_102:
F_47 ( & V_43 ) ;
return V_18 ;
}
static int
F_76 ( struct V_88 * V_89 , struct V_46 * V_47 ,
const struct V_68 * V_69 ,
const struct V_29 * const V_90 [] )
{
struct V_52 * V_116 , * V_117 ;
T_4 V_118 , V_119 ;
char V_120 [ V_101 ] ;
if ( F_34 ( F_56 ( V_90 ) ||
V_90 [ V_95 ] == NULL ||
V_90 [ V_113 ] == NULL ) )
return - V_36 ;
V_118 = F_62 ( F_39 ( V_90 [ V_95 ] ) ) ;
if ( V_118 == V_64 )
return - V_110 ;
V_119 = F_62 ( F_39 ( V_90 [ V_113 ] ) ) ;
if ( V_119 == V_64 )
return - V_115 ;
V_116 = V_44 [ V_118 ] ;
V_117 = V_44 [ V_119 ] ;
if ( ! ( V_116 -> type -> V_121 == V_117 -> type -> V_121 &&
V_116 -> type -> V_4 == V_117 -> type -> V_4 ) )
return - V_122 ;
strncpy ( V_120 , V_116 -> V_3 , V_101 ) ;
strncpy ( V_116 -> V_3 , V_117 -> V_3 , V_101 ) ;
strncpy ( V_117 -> V_3 , V_120 , V_101 ) ;
F_41 ( & V_43 ) ;
F_77 ( V_116 -> V_45 , V_117 -> V_45 ) ;
V_44 [ V_118 ] = V_117 ;
V_44 [ V_119 ] = V_116 ;
F_42 ( & V_43 ) ;
return 0 ;
}
static int
F_78 ( struct V_123 * V_124 )
{
if ( V_124 -> args [ 2 ] ) {
F_10 ( L_21 , V_44 [ V_124 -> args [ 1 ] ] -> V_3 ) ;
F_51 ( ( T_4 ) V_124 -> args [ 1 ] ) ;
}
return 0 ;
}
static inline void
F_79 ( struct V_68 * V_69 )
{
const struct V_29 * V_90 ;
int V_125 ;
F_10 ( L_22 ) ;
F_80 (attr, nlh, sizeof(struct nfgenmsg), rem) {
F_10 ( L_23 , V_31 ( V_90 ) , V_90 -> V_126 ) ;
}
}
static int
F_81 ( struct V_123 * V_124 )
{
struct V_68 * V_69 = F_82 ( V_124 -> V_47 ) ;
int V_127 = F_83 ( sizeof( struct V_78 ) ) ;
struct V_29 * V_128 [ V_129 + 1 ] ;
struct V_29 * V_90 = ( void * ) V_69 + V_127 ;
T_5 V_130 ;
T_4 V_42 ;
F_84 ( V_128 , V_129 ,
V_90 , V_69 -> V_131 - V_127 , V_132 ) ;
if ( V_128 [ V_95 ] ) {
V_42 = F_62 ( F_39 ( V_128 [ V_95 ] ) ) ;
if ( V_42 == V_64 )
return - V_110 ;
V_130 = V_133 ;
V_124 -> args [ 1 ] = V_42 ;
} else
V_130 = V_134 ;
if ( V_128 [ V_135 ] ) {
T_5 V_136 = F_85 ( V_128 [ V_135 ] ) ;
V_130 |= ( V_136 << 16 ) ;
}
V_124 -> args [ 0 ] = V_130 ;
return 0 ;
}
static int
F_86 ( struct V_46 * V_47 , struct V_123 * V_124 )
{
T_4 V_42 = V_64 , V_17 ;
struct V_52 * V_53 = NULL ;
struct V_68 * V_69 = NULL ;
unsigned int V_75 = F_87 ( V_124 -> V_47 ) . V_73 ? V_137 : 0 ;
T_5 V_130 , V_138 ;
int V_18 = 0 ;
if ( ! V_124 -> args [ 0 ] ) {
V_18 = F_81 ( V_124 ) ;
if ( V_18 < 0 ) {
V_69 = F_82 ( V_124 -> V_47 ) ;
if ( V_69 -> V_70 & V_139 )
F_88 ( V_124 -> V_47 , V_69 , V_18 ) ;
return V_18 ;
}
}
if ( V_124 -> args [ 1 ] >= V_66 )
goto V_102;
V_130 = F_89 ( V_124 -> args [ 0 ] ) ;
V_138 = F_90 ( V_124 -> args [ 0 ] ) ;
V_17 = V_130 == V_133 ? V_124 -> args [ 1 ] + 1 : V_66 ;
V_140:
F_10 ( L_24 ,
V_130 , V_138 , V_124 -> args [ 1 ] ) ;
for (; V_124 -> args [ 1 ] < V_17 ; V_124 -> args [ 1 ] ++ ) {
V_42 = ( T_4 ) V_124 -> args [ 1 ] ;
V_53 = V_44 [ V_42 ] ;
if ( V_53 == NULL ) {
if ( V_130 == V_133 ) {
V_18 = - V_110 ;
goto V_102;
}
continue;
}
if ( V_130 != V_133 &&
( ( V_130 == V_134 ) ==
! ! ( V_53 -> type -> V_121 & V_141 ) ) )
continue;
F_10 ( L_25 , V_53 -> V_3 ) ;
if ( ! V_124 -> args [ 2 ] ) {
F_10 ( L_26 ) ;
F_40 ( V_42 ) ;
}
V_69 = F_59 ( V_47 , F_87 ( V_124 -> V_47 ) . V_73 ,
V_124 -> V_69 -> V_142 , V_75 ,
V_143 ) ;
if ( ! V_69 ) {
V_18 = - V_144 ;
goto V_145;
}
if ( F_91 ( V_47 , V_67 , V_20 ) ||
F_92 ( V_47 , V_95 , V_53 -> V_3 ) )
goto V_146;
if ( V_138 & V_147 )
goto V_148;
switch ( V_124 -> args [ 2 ] ) {
case 0 :
if ( F_92 ( V_47 , V_96 ,
V_53 -> type -> V_3 ) ||
F_91 ( V_47 , V_98 ,
V_53 -> V_4 ) ||
F_91 ( V_47 , V_97 ,
V_53 -> V_5 ) )
goto V_146;
V_18 = V_53 -> V_57 -> V_149 ( V_53 , V_47 ) ;
if ( V_18 < 0 )
goto V_145;
if ( V_138 & V_150 )
goto V_148;
default:
F_46 ( & V_53 -> V_56 ) ;
V_18 = V_53 -> V_57 -> V_22 ( V_53 , V_47 , V_124 ) ;
F_47 ( & V_53 -> V_56 ) ;
if ( ! V_124 -> args [ 2 ] )
goto V_148;
goto V_145;
}
}
if ( V_130 == V_134 ) {
V_130 = V_151 ;
V_124 -> args [ 0 ] = V_130 | ( V_138 << 16 ) ;
V_124 -> args [ 1 ] = 0 ;
goto V_140;
}
goto V_102;
V_146:
V_18 = - V_14 ;
V_148:
if ( V_130 == V_133 )
V_124 -> args [ 1 ] = V_64 ;
else
V_124 -> args [ 1 ] ++ ;
V_145:
if ( V_18 || ! V_124 -> args [ 2 ] ) {
F_10 ( L_21 , V_44 [ V_42 ] -> V_3 ) ;
F_51 ( V_42 ) ;
V_124 -> args [ 2 ] = 0 ;
}
V_102:
if ( V_69 ) {
F_93 ( V_47 , V_69 ) ;
F_10 ( L_27 , V_69 -> V_131 ) ;
F_79 ( V_69 ) ;
}
return V_18 < 0 ? V_18 : V_47 -> V_152 ;
}
static int
F_94 ( struct V_88 * V_89 , struct V_46 * V_47 ,
const struct V_68 * V_69 ,
const struct V_29 * const V_90 [] )
{
if ( F_34 ( F_56 ( V_90 ) ) )
return - V_36 ;
{
struct V_153 V_154 = {
. V_155 = F_86 ,
. V_156 = F_78 ,
} ;
return F_95 ( V_89 , V_47 , V_69 , & V_154 ) ;
}
}
static int
F_96 ( struct V_88 * V_89 , struct V_46 * V_47 , struct V_52 * V_53 ,
struct V_29 * V_34 [] , enum V_157 V_158 ,
T_5 V_75 , bool V_159 )
{
int V_18 ;
T_5 V_160 = 0 ;
bool V_161 = V_75 & V_72 , V_162 = false ;
do {
F_41 ( & V_53 -> V_56 ) ;
V_18 = V_53 -> V_57 -> V_163 ( V_53 , V_34 , V_158 , & V_160 , V_75 , V_162 ) ;
F_42 ( & V_53 -> V_56 ) ;
V_162 = true ;
} while ( V_18 == - V_60 &&
V_53 -> V_57 -> V_164 &&
( V_18 = V_53 -> V_57 -> V_164 ( V_53 , V_162 ) ) == 0 );
if ( ! V_18 || ( V_18 == - V_165 && V_161 ) )
return 0 ;
if ( V_160 && V_159 ) {
struct V_68 * V_166 , * V_69 = F_82 ( V_47 ) ;
struct V_46 * V_167 ;
struct V_168 * V_169 ;
T_2 V_170 = sizeof( * V_169 ) + V_131 ( V_69 ) ;
int V_127 = F_83 ( sizeof( struct V_78 ) ) ;
struct V_29 * V_128 [ V_129 + 1 ] ;
struct V_29 * V_171 ;
T_5 * V_172 ;
V_167 = F_97 ( V_170 , V_27 ) ;
if ( V_167 == NULL )
return - V_100 ;
V_166 = F_98 ( V_167 , F_87 ( V_47 ) . V_73 ,
V_69 -> V_142 , V_173 , V_170 , 0 ) ;
V_169 = F_61 ( V_166 ) ;
V_169 -> error = V_18 ;
memcpy ( & V_169 -> V_174 , V_69 , V_69 -> V_131 ) ;
V_171 = ( void * ) & V_169 -> V_174 + V_127 ;
F_84 ( V_128 , V_129 ,
V_171 , V_69 -> V_131 - V_127 ,
V_175 ) ;
V_172 = F_39 ( V_128 [ V_176 ] ) ;
* V_172 = V_160 ;
F_99 ( V_89 , V_167 , F_87 ( V_47 ) . V_73 , V_177 ) ;
return - V_178 ;
}
return V_18 ;
}
static int
F_100 ( struct V_88 * V_89 , struct V_46 * V_47 ,
const struct V_68 * V_69 ,
const struct V_29 * const V_90 [] )
{
struct V_52 * V_53 ;
struct V_29 * V_34 [ V_179 + 1 ] = {} ;
const struct V_29 * V_30 ;
T_5 V_75 = F_58 ( V_69 ) ;
bool V_159 ;
int V_18 = 0 ;
if ( F_34 ( F_56 ( V_90 ) ||
V_90 [ V_95 ] == NULL ||
! ( ( V_90 [ V_99 ] != NULL ) ^
( V_90 [ V_180 ] != NULL ) ) ||
( V_90 [ V_99 ] != NULL &&
! F_32 ( V_90 [ V_99 ] ) ) ||
( V_90 [ V_180 ] != NULL &&
( ! F_32 ( V_90 [ V_180 ] ) ||
V_90 [ V_176 ] == NULL ) ) ) )
return - V_36 ;
V_53 = F_63 ( F_39 ( V_90 [ V_95 ] ) ) ;
if ( V_53 == NULL )
return - V_110 ;
V_159 = ! ! V_90 [ V_176 ] ;
if ( V_90 [ V_99 ] ) {
if ( F_35 ( V_34 , V_179 ,
V_90 [ V_99 ] ,
V_53 -> type -> V_181 ) )
return - V_36 ;
V_18 = F_96 ( V_89 , V_47 , V_53 , V_34 , V_61 , V_75 ,
V_159 ) ;
} else {
int V_182 ;
F_101 (nla, attr[IPSET_ATTR_ADT], nla_rem) {
memset ( V_34 , 0 , sizeof( V_34 ) ) ;
if ( V_31 ( V_30 ) != V_99 ||
! F_32 ( V_30 ) ||
F_35 ( V_34 , V_179 , V_30 ,
V_53 -> type -> V_181 ) )
return - V_36 ;
V_18 = F_96 ( V_89 , V_47 , V_53 , V_34 , V_61 ,
V_75 , V_159 ) ;
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
struct V_29 * V_34 [ V_179 + 1 ] = {} ;
const struct V_29 * V_30 ;
T_5 V_75 = F_58 ( V_69 ) ;
bool V_159 ;
int V_18 = 0 ;
if ( F_34 ( F_56 ( V_90 ) ||
V_90 [ V_95 ] == NULL ||
! ( ( V_90 [ V_99 ] != NULL ) ^
( V_90 [ V_180 ] != NULL ) ) ||
( V_90 [ V_99 ] != NULL &&
! F_32 ( V_90 [ V_99 ] ) ) ||
( V_90 [ V_180 ] != NULL &&
( ! F_32 ( V_90 [ V_180 ] ) ||
V_90 [ V_176 ] == NULL ) ) ) )
return - V_36 ;
V_53 = F_63 ( F_39 ( V_90 [ V_95 ] ) ) ;
if ( V_53 == NULL )
return - V_110 ;
V_159 = ! ! V_90 [ V_176 ] ;
if ( V_90 [ V_99 ] ) {
if ( F_35 ( V_34 , V_179 ,
V_90 [ V_99 ] ,
V_53 -> type -> V_181 ) )
return - V_36 ;
V_18 = F_96 ( V_89 , V_47 , V_53 , V_34 , V_62 , V_75 ,
V_159 ) ;
} else {
int V_182 ;
F_101 (nla, attr[IPSET_ATTR_ADT], nla_rem) {
memset ( V_34 , 0 , sizeof( * V_34 ) ) ;
if ( V_31 ( V_30 ) != V_99 ||
! F_32 ( V_30 ) ||
F_35 ( V_34 , V_179 , V_30 ,
V_53 -> type -> V_181 ) )
return - V_36 ;
V_18 = F_96 ( V_89 , V_47 , V_53 , V_34 , V_62 ,
V_75 , V_159 ) ;
if ( V_18 < 0 )
return V_18 ;
}
}
return V_18 ;
}
static int
F_103 ( struct V_88 * V_89 , struct V_46 * V_47 ,
const struct V_68 * V_69 ,
const struct V_29 * const V_90 [] )
{
struct V_52 * V_53 ;
struct V_29 * V_34 [ V_179 + 1 ] = {} ;
int V_18 = 0 ;
if ( F_34 ( F_56 ( V_90 ) ||
V_90 [ V_95 ] == NULL ||
V_90 [ V_99 ] == NULL ||
! F_32 ( V_90 [ V_99 ] ) ) )
return - V_36 ;
V_53 = F_63 ( F_39 ( V_90 [ V_95 ] ) ) ;
if ( V_53 == NULL )
return - V_110 ;
if ( F_35 ( V_34 , V_179 , V_90 [ V_99 ] ,
V_53 -> type -> V_181 ) )
return - V_36 ;
F_46 ( & V_53 -> V_56 ) ;
V_18 = V_53 -> V_57 -> V_163 ( V_53 , V_34 , V_59 , NULL , 0 , 0 ) ;
F_47 ( & V_53 -> V_56 ) ;
if ( V_18 == - V_60 )
V_18 = 1 ;
return V_18 < 0 ? V_18 : V_18 > 0 ? 0 : - V_165 ;
}
static int
F_104 ( struct V_88 * V_89 , struct V_46 * V_47 ,
const struct V_68 * V_69 ,
const struct V_29 * const V_90 [] )
{
const struct V_52 * V_53 ;
struct V_46 * V_167 ;
struct V_68 * V_183 ;
T_4 V_42 ;
int V_18 = 0 ;
if ( F_34 ( F_56 ( V_90 ) ||
V_90 [ V_95 ] == NULL ) )
return - V_36 ;
V_42 = F_62 ( F_39 ( V_90 [ V_95 ] ) ) ;
if ( V_42 == V_64 )
return - V_110 ;
V_53 = V_44 [ V_42 ] ;
V_167 = F_97 ( V_184 , V_27 ) ;
if ( V_167 == NULL )
return - V_100 ;
V_183 = F_59 ( V_167 , F_87 ( V_47 ) . V_73 , V_69 -> V_142 , 0 ,
V_185 ) ;
if ( ! V_183 )
goto V_186;
if ( F_91 ( V_167 , V_67 , V_20 ) ||
F_92 ( V_167 , V_95 , V_53 -> V_3 ) ||
F_92 ( V_167 , V_96 , V_53 -> type -> V_3 ) ||
F_91 ( V_167 , V_98 , V_53 -> V_4 ) ||
F_91 ( V_167 , V_97 , V_53 -> V_5 ) )
goto V_146;
F_93 ( V_167 , V_183 ) ;
V_18 = F_99 ( V_89 , V_167 , F_87 ( V_47 ) . V_73 , V_177 ) ;
if ( V_18 < 0 )
return V_18 ;
return 0 ;
V_146:
F_105 ( V_167 , V_183 ) ;
V_186:
F_106 ( V_167 ) ;
return - V_144 ;
}
static int
V_2 ( struct V_88 * V_89 , struct V_46 * V_47 ,
const struct V_68 * V_69 ,
const struct V_29 * const V_90 [] )
{
struct V_46 * V_167 ;
struct V_68 * V_183 ;
T_1 V_4 , V_16 , V_17 ;
const char * V_94 ;
int V_18 = 0 ;
if ( F_34 ( F_56 ( V_90 ) ||
V_90 [ V_96 ] == NULL ||
V_90 [ V_98 ] == NULL ) )
return - V_36 ;
V_4 = F_57 ( V_90 [ V_98 ] ) ;
V_94 = F_39 ( V_90 [ V_96 ] ) ;
V_18 = F_107 ( V_94 , V_4 , & V_16 , & V_17 ) ;
if ( V_18 )
return V_18 ;
V_167 = F_97 ( V_184 , V_27 ) ;
if ( V_167 == NULL )
return - V_100 ;
V_183 = F_59 ( V_167 , F_87 ( V_47 ) . V_73 , V_69 -> V_142 , 0 ,
V_187 ) ;
if ( ! V_183 )
goto V_186;
if ( F_91 ( V_167 , V_67 , V_20 ) ||
F_92 ( V_167 , V_96 , V_94 ) ||
F_91 ( V_167 , V_98 , V_4 ) ||
F_91 ( V_167 , V_97 , V_17 ) ||
F_91 ( V_167 , V_188 , V_16 ) )
goto V_146;
F_93 ( V_167 , V_183 ) ;
F_10 ( L_28 , V_183 -> V_131 ) ;
V_18 = F_99 ( V_89 , V_167 , F_87 ( V_47 ) . V_73 , V_177 ) ;
if ( V_18 < 0 )
return V_18 ;
return 0 ;
V_146:
F_105 ( V_167 , V_183 ) ;
V_186:
F_106 ( V_167 ) ;
return - V_144 ;
}
static int
F_108 ( struct V_88 * V_89 , struct V_46 * V_47 ,
const struct V_68 * V_69 ,
const struct V_29 * const V_90 [] )
{
struct V_46 * V_167 ;
struct V_68 * V_183 ;
int V_18 = 0 ;
if ( F_34 ( V_90 [ V_67 ] == NULL ) )
return - V_36 ;
V_167 = F_97 ( V_184 , V_27 ) ;
if ( V_167 == NULL )
return - V_100 ;
V_183 = F_59 ( V_167 , F_87 ( V_47 ) . V_73 , V_69 -> V_142 , 0 ,
V_189 ) ;
if ( ! V_183 )
goto V_186;
if ( F_91 ( V_167 , V_67 , V_20 ) )
goto V_146;
F_93 ( V_167 , V_183 ) ;
V_18 = F_99 ( V_89 , V_167 , F_87 ( V_47 ) . V_73 , V_177 ) ;
if ( V_18 < 0 )
return V_18 ;
return 0 ;
V_146:
F_105 ( V_167 , V_183 ) ;
V_186:
F_106 ( V_167 ) ;
return - V_144 ;
}
static int
F_109 ( struct V_88 * V_190 , int V_191 , void T_6 * V_192 , int * V_152 )
{
unsigned int * V_193 ;
void * V_194 ;
int V_195 = * V_152 , V_18 = 0 ;
if ( ! F_110 ( V_196 ) )
return - V_197 ;
if ( V_191 != V_198 )
return - V_199 ;
if ( * V_152 < sizeof( unsigned int ) )
return - V_21 ;
V_194 = F_111 ( * V_152 ) ;
if ( ! V_194 )
return - V_100 ;
if ( F_112 ( V_194 , V_192 , * V_152 ) != 0 ) {
V_18 = - V_14 ;
goto V_156;
}
V_193 = ( unsigned int * ) V_194 ;
if ( * V_193 < V_200 ) {
struct V_201 * V_202 = V_194 ;
if ( V_202 -> V_83 != V_20 ) {
V_18 = - V_203 ;
goto V_156;
}
}
switch ( * V_193 ) {
case V_200 : {
struct V_201 * V_202 = V_194 ;
if ( * V_152 != sizeof( struct V_201 ) ) {
V_18 = - V_21 ;
goto V_156;
}
V_202 -> V_83 = V_20 ;
V_18 = F_113 ( V_192 , V_202 ,
sizeof( struct V_201 ) ) ;
goto V_156;
}
case V_204 : {
struct V_205 * V_206 = V_194 ;
if ( * V_152 != sizeof( struct V_205 ) ) {
V_18 = - V_21 ;
goto V_156;
}
V_206 -> V_53 . V_3 [ V_101 - 1 ] = '\0' ;
F_13 () ;
V_206 -> V_53 . V_42 = F_62 ( V_206 -> V_53 . V_3 ) ;
F_9 () ;
goto V_207;
}
case V_208 : {
struct V_205 * V_206 = V_194 ;
if ( * V_152 != sizeof( struct V_205 ) ||
V_206 -> V_53 . V_42 >= V_66 ) {
V_18 = - V_21 ;
goto V_156;
}
F_13 () ;
strncpy ( V_206 -> V_53 . V_3 ,
V_44 [ V_206 -> V_53 . V_42 ]
? V_44 [ V_206 -> V_53 . V_42 ] -> V_3 : L_29 ,
V_101 ) ;
F_9 () ;
goto V_207;
}
default:
V_18 = - V_209 ;
goto V_156;
}
V_207:
V_18 = F_113 ( V_192 , V_194 , V_195 ) ;
V_156:
F_30 ( V_194 ) ;
if ( V_18 > 0 )
V_18 = 0 ;
return V_18 ;
}
static int T_7
F_114 ( void )
{
int V_18 ;
if ( V_210 )
V_66 = V_210 ;
if ( V_66 >= V_64 )
V_66 = V_64 - 1 ;
V_44 = F_26 ( sizeof( struct V_52 * ) * V_66 ,
V_27 ) ;
if ( ! V_44 )
return - V_100 ;
V_18 = F_115 ( & V_211 ) ;
if ( V_18 != 0 ) {
F_116 ( L_30 ) ;
F_31 ( V_44 ) ;
return V_18 ;
}
V_18 = F_117 ( & V_212 ) ;
if ( V_18 != 0 ) {
F_116 ( L_31 , V_18 ) ;
F_118 ( & V_211 ) ;
F_31 ( V_44 ) ;
return V_18 ;
}
F_119 ( L_32 , V_20 ) ;
return 0 ;
}
static void T_8
F_120 ( void )
{
F_121 ( & V_212 ) ;
F_118 ( & V_211 ) ;
F_31 ( V_44 ) ;
F_10 ( L_33 ) ;
}
