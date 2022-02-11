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
type -> V_5 == V_5 )
return type ;
return NULL ;
}
static int
F_8 ( const char * V_3 )
{
F_9 () ;
F_10 ( L_1 , V_3 ) ;
if ( F_11 ( L_2 , V_3 ) < 0 ) {
F_12 ( L_3 , V_3 ) ;
F_13 () ;
return - V_7 ;
}
F_13 () ;
return - V_8 ;
}
static int
F_14 ( const char * V_3 , T_1 V_4 , T_1 V_5 ,
struct V_2 * * V_9 )
{
struct V_2 * type ;
int V_10 ;
F_15 () ;
* V_9 = F_5 ( V_3 , V_4 , V_5 ) ;
if ( * V_9 ) {
V_10 = ! F_16 ( ( * V_9 ) -> V_11 ) ? - V_12 : 0 ;
goto V_13;
}
F_6 (type, &ip_set_type_list, list)
if ( F_7 ( type -> V_3 , V_3 ) ) {
V_10 = - V_7 ;
goto V_13;
}
F_17 () ;
return F_8 ( V_3 ) ;
V_13:
F_17 () ;
return V_10 ;
}
static int
F_18 ( const char * V_3 , T_1 V_4 , T_1 * V_14 , T_1 * V_15 )
{
struct V_2 * type ;
bool V_9 = false ;
* V_14 = 255 ; * V_15 = 0 ;
F_15 () ;
F_6 (type, &ip_set_type_list, list)
if ( F_7 ( type -> V_3 , V_3 ) &&
( type -> V_4 == V_4 || type -> V_4 == V_6 ) ) {
V_9 = true ;
if ( type -> V_5 < * V_14 )
* V_14 = type -> V_5 ;
if ( type -> V_5 > * V_15 )
* V_15 = type -> V_5 ;
}
F_17 () ;
if ( V_9 )
return 0 ;
return F_8 ( V_3 ) ;
}
int
F_19 ( struct V_2 * type )
{
int V_16 = 0 ;
if ( type -> V_17 != V_18 ) {
F_12 ( L_4
L_5 ,
type -> V_3 , F_20 ( type -> V_4 ) ,
type -> V_5 , type -> V_17 , V_18 ) ;
return - V_19 ;
}
F_1 () ;
if ( F_5 ( type -> V_3 , type -> V_4 , type -> V_5 ) ) {
F_12 ( L_6
L_7 , type -> V_3 ,
F_20 ( type -> V_4 ) , type -> V_5 ) ;
V_16 = - V_19 ;
goto V_13;
}
F_21 ( & type -> V_20 , & V_21 ) ;
F_10 ( L_8 ,
type -> V_3 , F_20 ( type -> V_4 ) , type -> V_5 ) ;
V_13:
F_3 () ;
return V_16 ;
}
void
F_22 ( struct V_2 * type )
{
F_1 () ;
if ( ! F_5 ( type -> V_3 , type -> V_4 , type -> V_5 ) ) {
F_12 ( L_6
L_9 , type -> V_3 ,
F_20 ( type -> V_4 ) , type -> V_5 ) ;
goto V_13;
}
F_23 ( & type -> V_20 ) ;
F_10 ( L_10 ,
type -> V_3 , F_20 ( type -> V_4 ) , type -> V_5 ) ;
V_13:
F_3 () ;
F_24 () ;
}
void *
F_25 ( T_2 V_22 )
{
void * V_23 = NULL ;
if ( V_22 < V_24 )
V_23 = F_26 ( V_22 , V_25 | V_26 ) ;
if ( V_23 ) {
F_10 ( L_11 , V_23 ) ;
return V_23 ;
}
V_23 = F_27 ( V_22 ) ;
if ( ! V_23 )
return NULL ;
F_10 ( L_12 , V_23 ) ;
return V_23 ;
}
void
F_28 ( void * V_23 )
{
F_10 ( L_13 , V_23 ,
F_29 ( V_23 ) ? L_14 : L_15 ) ;
if ( F_29 ( V_23 ) )
F_30 ( V_23 ) ;
else
F_31 ( V_23 ) ;
}
static inline bool
F_32 ( const struct V_27 * V_28 )
{
return V_28 -> V_29 & V_30 ;
}
int
F_33 ( struct V_27 * V_28 , T_3 * V_31 )
{
struct V_27 * V_32 [ V_33 + 1 ] ;
if ( F_34 ( ! F_32 ( V_28 ) ) )
return - V_34 ;
if ( F_35 ( V_32 , V_33 , V_28 , V_35 ) )
return - V_34 ;
if ( F_34 ( ! F_36 ( V_32 , V_36 ) ) )
return - V_34 ;
* V_31 = F_37 ( V_32 [ V_36 ] ) ;
return 0 ;
}
int
F_38 ( struct V_27 * V_28 , union V_37 * V_31 )
{
struct V_27 * V_32 [ V_33 + 1 ] ;
if ( F_34 ( ! F_32 ( V_28 ) ) )
return - V_34 ;
if ( F_35 ( V_32 , V_33 , V_28 , V_35 ) )
return - V_34 ;
if ( F_34 ( ! F_36 ( V_32 , V_38 ) ) )
return - V_34 ;
memcpy ( V_31 , F_39 ( V_32 [ V_38 ] ) ,
sizeof( struct V_39 ) ) ;
return 0 ;
}
static inline void
F_40 ( T_4 V_40 )
{
F_41 ( & V_41 ) ;
V_42 [ V_40 ] -> V_43 ++ ;
F_42 ( & V_41 ) ;
}
static inline void
F_43 ( T_4 V_40 )
{
F_41 ( & V_41 ) ;
F_44 ( V_42 [ V_40 ] -> V_43 == 0 ) ;
V_42 [ V_40 ] -> V_43 -- ;
F_42 ( & V_41 ) ;
}
int
F_45 ( T_4 V_40 , const struct V_44 * V_45 ,
T_1 V_4 , T_1 V_46 , T_1 V_47 )
{
struct V_48 * V_49 = V_42 [ V_40 ] ;
int V_16 = 0 ;
F_44 ( V_49 == NULL ) ;
F_10 ( L_16 , V_49 -> V_3 , V_40 ) ;
if ( V_46 < V_49 -> type -> V_50 ||
! ( V_4 == V_49 -> V_4 || V_49 -> V_4 == V_6 ) )
return 0 ;
F_46 ( & V_49 -> V_51 ) ;
V_16 = V_49 -> V_52 -> V_53 ( V_49 , V_45 , V_54 , V_4 , V_46 , V_47 ) ;
F_47 ( & V_49 -> V_51 ) ;
if ( V_16 == - V_8 ) {
F_10 ( L_17 ) ;
F_41 ( & V_49 -> V_51 ) ;
V_49 -> V_52 -> V_53 ( V_49 , V_45 , V_55 , V_4 , V_46 , V_47 ) ;
F_42 ( & V_49 -> V_51 ) ;
V_16 = 1 ;
}
return ( V_16 < 0 ? 0 : V_16 ) ;
}
int
F_48 ( T_4 V_40 , const struct V_44 * V_45 ,
T_1 V_4 , T_1 V_46 , T_1 V_47 )
{
struct V_48 * V_49 = V_42 [ V_40 ] ;
int V_16 ;
F_44 ( V_49 == NULL ) ;
F_10 ( L_16 , V_49 -> V_3 , V_40 ) ;
if ( V_46 < V_49 -> type -> V_50 ||
! ( V_4 == V_49 -> V_4 || V_49 -> V_4 == V_6 ) )
return 0 ;
F_41 ( & V_49 -> V_51 ) ;
V_16 = V_49 -> V_52 -> V_53 ( V_49 , V_45 , V_55 , V_4 , V_46 , V_47 ) ;
F_42 ( & V_49 -> V_51 ) ;
return V_16 ;
}
int
F_49 ( T_4 V_40 , const struct V_44 * V_45 ,
T_1 V_4 , T_1 V_46 , T_1 V_47 )
{
struct V_48 * V_49 = V_42 [ V_40 ] ;
int V_16 = 0 ;
F_44 ( V_49 == NULL ) ;
F_10 ( L_16 , V_49 -> V_3 , V_40 ) ;
if ( V_46 < V_49 -> type -> V_50 ||
! ( V_4 == V_49 -> V_4 || V_49 -> V_4 == V_6 ) )
return 0 ;
F_41 ( & V_49 -> V_51 ) ;
V_16 = V_49 -> V_52 -> V_53 ( V_49 , V_45 , V_56 , V_4 , V_46 , V_47 ) ;
F_42 ( & V_49 -> V_51 ) ;
return V_16 ;
}
T_4
F_50 ( const char * V_3 , struct V_48 * * V_49 )
{
T_4 V_57 , V_40 = V_58 ;
struct V_48 * V_59 ;
for ( V_57 = 0 ; V_57 < V_60 ; V_57 ++ ) {
V_59 = V_42 [ V_57 ] ;
if ( V_59 != NULL && F_7 ( V_59 -> V_3 , V_3 ) ) {
F_40 ( V_57 ) ;
V_40 = V_57 ;
* V_49 = V_59 ;
}
}
return V_40 ;
}
void
F_51 ( T_4 V_40 )
{
if ( V_42 [ V_40 ] != NULL )
F_43 ( V_40 ) ;
}
const char *
F_52 ( T_4 V_40 )
{
const struct V_48 * V_49 = V_42 [ V_40 ] ;
F_44 ( V_49 == NULL ) ;
F_44 ( V_49 -> V_43 == 0 ) ;
return V_49 -> V_3 ;
}
T_4
F_53 ( const char * V_3 )
{
struct V_48 * V_59 ;
T_4 V_40 ;
F_13 () ;
V_40 = F_50 ( V_3 , & V_59 ) ;
F_9 () ;
return V_40 ;
}
T_4
F_54 ( T_4 V_40 )
{
if ( V_40 > V_60 )
return V_58 ;
F_13 () ;
if ( V_42 [ V_40 ] )
F_40 ( V_40 ) ;
else
V_40 = V_58 ;
F_9 () ;
return V_40 ;
}
void
F_55 ( T_4 V_40 )
{
F_13 () ;
F_51 ( V_40 ) ;
F_9 () ;
}
static inline bool
F_56 ( const struct V_27 * const V_32 [] )
{
return ! V_32 [ V_61 ] ||
F_57 ( V_32 [ V_61 ] ) != V_18 ;
}
static inline T_5
F_58 ( const struct V_62 * V_63 )
{
return V_63 -> V_64 & V_65 ? 0 : V_66 ;
}
static struct V_62 *
F_59 ( struct V_44 * V_45 , T_5 V_67 , T_5 V_68 , unsigned int V_47 ,
enum V_69 V_70 )
{
struct V_62 * V_63 ;
struct V_71 * V_72 ;
V_63 = F_60 ( V_45 , V_67 , V_68 , V_70 | ( V_73 << 8 ) ,
sizeof( * V_72 ) , V_47 ) ;
if ( V_63 == NULL )
return NULL ;
V_72 = F_61 ( V_63 ) ;
V_72 -> V_74 = V_75 ;
V_72 -> V_76 = V_77 ;
V_72 -> V_78 = 0 ;
return V_63 ;
}
static T_4
F_62 ( const char * V_3 )
{
T_4 V_57 , V_40 = V_58 ;
const struct V_48 * V_49 ;
for ( V_57 = 0 ; V_40 == V_58 && V_57 < V_60 ; V_57 ++ ) {
V_49 = V_42 [ V_57 ] ;
if ( V_49 != NULL && F_7 ( V_49 -> V_3 , V_3 ) )
V_40 = V_57 ;
}
return V_40 ;
}
static inline struct V_48 *
F_63 ( const char * V_3 )
{
T_4 V_40 = F_62 ( V_3 ) ;
return V_40 == V_58 ? NULL : V_42 [ V_40 ] ;
}
static int
F_64 ( const char * V_3 , T_4 * V_40 , struct V_48 * * V_49 )
{
T_4 V_57 ;
* V_40 = V_58 ;
for ( V_57 = 0 ; V_57 < V_60 ; V_57 ++ ) {
if ( V_42 [ V_57 ] == NULL ) {
if ( * V_40 == V_58 )
* V_40 = V_57 ;
} else if ( F_7 ( V_3 , V_42 [ V_57 ] -> V_3 ) ) {
* V_49 = V_42 [ V_57 ] ;
return - V_79 ;
}
}
if ( * V_40 == V_58 )
return - V_80 ;
return 0 ;
}
static int
F_65 ( struct V_81 * V_82 , struct V_44 * V_45 ,
const struct V_62 * V_63 ,
const struct V_27 * const V_83 [] )
{
struct V_48 * V_49 , * V_84 = NULL ;
T_4 V_40 = V_58 ;
struct V_27 * V_32 [ V_85 + 1 ] = {} ;
const char * V_3 , * V_86 ;
T_1 V_4 , V_5 ;
T_5 V_47 = F_58 ( V_63 ) ;
int V_16 = 0 ;
if ( F_34 ( F_56 ( V_83 ) ||
V_83 [ V_87 ] == NULL ||
V_83 [ V_88 ] == NULL ||
V_83 [ V_89 ] == NULL ||
V_83 [ V_90 ] == NULL ||
( V_83 [ V_91 ] != NULL &&
! F_32 ( V_83 [ V_91 ] ) ) ) )
return - V_34 ;
V_3 = F_39 ( V_83 [ V_87 ] ) ;
V_86 = F_39 ( V_83 [ V_88 ] ) ;
V_4 = F_57 ( V_83 [ V_90 ] ) ;
V_5 = F_57 ( V_83 [ V_89 ] ) ;
F_10 ( L_18 ,
V_3 , V_86 , F_20 ( V_4 ) , V_5 ) ;
V_49 = F_26 ( sizeof( struct V_48 ) , V_25 ) ;
if ( ! V_49 )
return - V_92 ;
F_66 ( & V_49 -> V_51 ) ;
F_67 ( V_49 -> V_3 , V_3 , V_93 ) ;
V_49 -> V_4 = V_4 ;
V_16 = F_14 ( V_86 , V_4 , V_5 , & ( V_49 -> type ) ) ;
if ( V_16 )
goto V_94;
if ( V_83 [ V_91 ] &&
F_35 ( V_32 , V_85 , V_83 [ V_91 ] ,
V_49 -> type -> V_95 ) ) {
V_16 = - V_34 ;
goto V_96;
}
V_16 = V_49 -> type -> V_97 ( V_49 , V_32 , V_47 ) ;
if ( V_16 != 0 )
goto V_96;
if ( ( V_16 = F_64 ( V_49 -> V_3 , & V_40 , & V_84 ) ) != 0 ) {
if ( V_16 == - V_79 &&
( V_47 & V_66 ) &&
F_7 ( V_49 -> type -> V_3 , V_84 -> type -> V_3 ) &&
V_49 -> type -> V_4 == V_84 -> type -> V_4 &&
V_49 -> type -> V_5 == V_84 -> type -> V_5 &&
V_49 -> V_52 -> V_98 ( V_49 , V_84 ) )
V_16 = 0 ;
goto V_99;
}
F_10 ( L_19 , V_49 -> V_3 , V_40 ) ;
V_42 [ V_40 ] = V_49 ;
return V_16 ;
V_99:
V_49 -> V_52 -> V_100 ( V_49 ) ;
V_96:
F_68 ( V_49 -> type -> V_11 ) ;
V_94:
F_31 ( V_49 ) ;
return V_16 ;
}
static void
F_69 ( T_4 V_40 )
{
struct V_48 * V_49 = V_42 [ V_40 ] ;
F_10 ( L_20 , V_49 -> V_3 ) ;
V_42 [ V_40 ] = NULL ;
V_49 -> V_52 -> V_100 ( V_49 ) ;
F_68 ( V_49 -> type -> V_11 ) ;
F_31 ( V_49 ) ;
}
static int
F_70 ( struct V_81 * V_82 , struct V_44 * V_45 ,
const struct V_62 * V_63 ,
const struct V_27 * const V_83 [] )
{
T_4 V_57 ;
int V_16 = 0 ;
if ( F_34 ( F_56 ( V_83 ) ) )
return - V_34 ;
F_46 ( & V_41 ) ;
if ( ! V_83 [ V_87 ] ) {
for ( V_57 = 0 ; V_57 < V_60 ; V_57 ++ ) {
if ( V_42 [ V_57 ] != NULL && V_42 [ V_57 ] -> V_43 ) {
V_16 = - V_101 ;
goto V_94;
}
}
F_47 ( & V_41 ) ;
for ( V_57 = 0 ; V_57 < V_60 ; V_57 ++ ) {
if ( V_42 [ V_57 ] != NULL )
F_69 ( V_57 ) ;
}
} else {
V_57 = F_62 ( F_39 ( V_83 [ V_87 ] ) ) ;
if ( V_57 == V_58 ) {
V_16 = - V_102 ;
goto V_94;
} else if ( V_42 [ V_57 ] -> V_43 ) {
V_16 = - V_101 ;
goto V_94;
}
F_47 ( & V_41 ) ;
F_69 ( V_57 ) ;
}
return 0 ;
V_94:
F_47 ( & V_41 ) ;
return V_16 ;
}
static void
F_71 ( struct V_48 * V_49 )
{
F_10 ( L_20 , V_49 -> V_3 ) ;
F_41 ( & V_49 -> V_51 ) ;
V_49 -> V_52 -> V_103 ( V_49 ) ;
F_42 ( & V_49 -> V_51 ) ;
}
static int
F_72 ( struct V_81 * V_82 , struct V_44 * V_45 ,
const struct V_62 * V_63 ,
const struct V_27 * const V_83 [] )
{
T_4 V_57 ;
if ( F_34 ( F_56 ( V_83 ) ) )
return - V_34 ;
if ( ! V_83 [ V_87 ] ) {
for ( V_57 = 0 ; V_57 < V_60 ; V_57 ++ )
if ( V_42 [ V_57 ] != NULL )
F_71 ( V_42 [ V_57 ] ) ;
} else {
V_57 = F_62 ( F_39 ( V_83 [ V_87 ] ) ) ;
if ( V_57 == V_58 )
return - V_102 ;
F_71 ( V_42 [ V_57 ] ) ;
}
return 0 ;
}
static int
F_73 ( struct V_81 * V_82 , struct V_44 * V_45 ,
const struct V_62 * V_63 ,
const struct V_27 * const V_83 [] )
{
struct V_48 * V_49 ;
const char * V_104 ;
T_4 V_57 ;
int V_16 = 0 ;
if ( F_34 ( F_56 ( V_83 ) ||
V_83 [ V_87 ] == NULL ||
V_83 [ V_105 ] == NULL ) )
return - V_34 ;
V_49 = F_63 ( F_39 ( V_83 [ V_87 ] ) ) ;
if ( V_49 == NULL )
return - V_102 ;
F_46 ( & V_41 ) ;
if ( V_49 -> V_43 != 0 ) {
V_16 = - V_106 ;
goto V_94;
}
V_104 = F_39 ( V_83 [ V_105 ] ) ;
for ( V_57 = 0 ; V_57 < V_60 ; V_57 ++ ) {
if ( V_42 [ V_57 ] != NULL &&
F_7 ( V_42 [ V_57 ] -> V_3 , V_104 ) ) {
V_16 = - V_107 ;
goto V_94;
}
}
strncpy ( V_49 -> V_3 , V_104 , V_93 ) ;
V_94:
F_47 ( & V_41 ) ;
return V_16 ;
}
static int
F_74 ( struct V_81 * V_82 , struct V_44 * V_45 ,
const struct V_62 * V_63 ,
const struct V_27 * const V_83 [] )
{
struct V_48 * V_108 , * V_109 ;
T_4 V_110 , V_111 ;
char V_112 [ V_93 ] ;
if ( F_34 ( F_56 ( V_83 ) ||
V_83 [ V_87 ] == NULL ||
V_83 [ V_105 ] == NULL ) )
return - V_34 ;
V_110 = F_62 ( F_39 ( V_83 [ V_87 ] ) ) ;
if ( V_110 == V_58 )
return - V_102 ;
V_111 = F_62 ( F_39 ( V_83 [ V_105 ] ) ) ;
if ( V_111 == V_58 )
return - V_107 ;
V_108 = V_42 [ V_110 ] ;
V_109 = V_42 [ V_111 ] ;
if ( ! ( V_108 -> type -> V_113 == V_109 -> type -> V_113 &&
V_108 -> type -> V_4 == V_109 -> type -> V_4 ) )
return - V_114 ;
strncpy ( V_112 , V_108 -> V_3 , V_93 ) ;
strncpy ( V_108 -> V_3 , V_109 -> V_3 , V_93 ) ;
strncpy ( V_109 -> V_3 , V_112 , V_93 ) ;
F_41 ( & V_41 ) ;
F_75 ( V_108 -> V_43 , V_109 -> V_43 ) ;
V_42 [ V_110 ] = V_109 ;
V_42 [ V_111 ] = V_108 ;
F_42 ( & V_41 ) ;
return 0 ;
}
static int
F_76 ( struct V_115 * V_116 )
{
if ( V_116 -> args [ 2 ] ) {
F_10 ( L_21 , V_42 [ V_116 -> args [ 1 ] ] -> V_3 ) ;
F_51 ( ( T_4 ) V_116 -> args [ 1 ] ) ;
}
return 0 ;
}
static inline void
F_77 ( struct V_62 * V_63 )
{
const struct V_27 * V_83 ;
int V_117 ;
F_10 ( L_22 ) ;
F_78 (attr, nlh, sizeof(struct nfgenmsg), rem) {
F_10 ( L_23 , V_29 ( V_83 ) , V_83 -> V_118 ) ;
}
}
static int
F_79 ( struct V_115 * V_116 )
{
struct V_62 * V_63 = F_80 ( V_116 -> V_45 ) ;
int V_119 = F_81 ( sizeof( struct V_71 ) ) ;
struct V_27 * V_120 [ V_121 + 1 ] ;
struct V_27 * V_83 = ( void * ) V_63 + V_119 ;
T_4 V_40 ;
F_82 ( V_120 , V_121 ,
V_83 , V_63 -> V_122 - V_119 , V_123 ) ;
if ( ! V_120 [ V_87 ] ) {
V_116 -> args [ 0 ] = V_124 ;
return 0 ;
}
V_40 = F_62 ( F_39 ( V_120 [ V_87 ] ) ) ;
if ( V_40 == V_58 )
return - V_102 ;
V_116 -> args [ 0 ] = V_125 ;
V_116 -> args [ 1 ] = V_40 ;
return 0 ;
}
static int
F_83 ( struct V_44 * V_45 , struct V_115 * V_116 )
{
T_4 V_40 = V_58 , V_15 ;
struct V_48 * V_49 = NULL ;
struct V_62 * V_63 = NULL ;
unsigned int V_47 = F_84 ( V_116 -> V_45 ) . V_67 ? V_126 : 0 ;
int V_16 = 0 ;
if ( V_116 -> args [ 0 ] == V_127 ) {
V_16 = F_79 ( V_116 ) ;
if ( V_16 < 0 ) {
V_63 = F_80 ( V_116 -> V_45 ) ;
if ( V_63 -> V_64 & V_128 )
F_85 ( V_116 -> V_45 , V_63 , V_16 ) ;
return V_16 ;
}
}
if ( V_116 -> args [ 1 ] >= V_60 )
goto V_94;
V_15 = V_116 -> args [ 0 ] == V_125 ? V_116 -> args [ 1 ] + 1 : V_60 ;
V_129:
F_10 ( L_24 , V_116 -> args [ 0 ] , V_116 -> args [ 1 ] ) ;
for (; V_116 -> args [ 1 ] < V_15 ; V_116 -> args [ 1 ] ++ ) {
V_40 = ( T_4 ) V_116 -> args [ 1 ] ;
V_49 = V_42 [ V_40 ] ;
if ( V_49 == NULL ) {
if ( V_116 -> args [ 0 ] == V_125 ) {
V_16 = - V_102 ;
goto V_94;
}
continue;
}
if ( V_116 -> args [ 0 ] != V_125 &&
( ( V_116 -> args [ 0 ] == V_124 ) ==
! ! ( V_49 -> type -> V_113 & V_130 ) ) )
continue;
F_10 ( L_25 , V_49 -> V_3 ) ;
if ( ! V_116 -> args [ 2 ] ) {
F_10 ( L_26 ) ;
F_40 ( V_40 ) ;
}
V_63 = F_59 ( V_45 , F_84 ( V_116 -> V_45 ) . V_67 ,
V_116 -> V_63 -> V_131 , V_47 ,
V_132 ) ;
if ( ! V_63 ) {
V_16 = - V_133 ;
goto V_134;
}
F_86 ( V_45 , V_61 , V_18 ) ;
F_87 ( V_45 , V_87 , V_49 -> V_3 ) ;
switch ( V_116 -> args [ 2 ] ) {
case 0 :
F_87 ( V_45 , V_88 ,
V_49 -> type -> V_3 ) ;
F_86 ( V_45 , V_90 ,
V_49 -> V_4 ) ;
F_86 ( V_45 , V_89 ,
V_49 -> type -> V_5 ) ;
V_16 = V_49 -> V_52 -> V_135 ( V_49 , V_45 ) ;
if ( V_16 < 0 )
goto V_134;
default:
F_46 ( & V_49 -> V_51 ) ;
V_16 = V_49 -> V_52 -> V_20 ( V_49 , V_45 , V_116 ) ;
F_47 ( & V_49 -> V_51 ) ;
if ( ! V_116 -> args [ 2 ] ) {
if ( V_116 -> args [ 0 ] == V_125 )
V_116 -> args [ 1 ] = V_58 ;
else
V_116 -> args [ 1 ] ++ ;
}
goto V_134;
}
}
if ( V_116 -> args [ 0 ] == V_124 ) {
V_116 -> args [ 0 ] = V_136 ;
V_116 -> args [ 1 ] = 0 ;
goto V_129;
}
goto V_94;
V_137:
V_16 = - V_12 ;
V_134:
if ( V_16 || ! V_116 -> args [ 2 ] ) {
F_10 ( L_21 , V_42 [ V_40 ] -> V_3 ) ;
F_51 ( V_40 ) ;
}
V_94:
if ( V_63 ) {
F_88 ( V_45 , V_63 ) ;
F_10 ( L_27 , V_63 -> V_122 ) ;
F_77 ( V_63 ) ;
}
return V_16 < 0 ? V_16 : V_45 -> V_138 ;
}
static int
F_89 ( struct V_81 * V_82 , struct V_44 * V_45 ,
const struct V_62 * V_63 ,
const struct V_27 * const V_83 [] )
{
if ( F_34 ( F_56 ( V_83 ) ) )
return - V_34 ;
return F_90 ( V_82 , V_45 , V_63 ,
F_83 ,
F_76 ) ;
}
static int
F_91 ( struct V_81 * V_82 , struct V_44 * V_45 , struct V_48 * V_49 ,
struct V_27 * V_32 [] , enum V_139 V_140 ,
T_5 V_47 , bool V_141 )
{
int V_16 , V_142 = 0 ;
T_5 V_143 = 0 ;
bool V_144 = V_47 & V_66 ;
do {
F_41 ( & V_49 -> V_51 ) ;
V_16 = V_49 -> V_52 -> V_145 ( V_49 , V_32 , V_140 , & V_143 , V_47 ) ;
F_42 ( & V_49 -> V_51 ) ;
} while ( V_16 == - V_8 &&
V_49 -> V_52 -> V_146 &&
( V_16 = V_49 -> V_52 -> V_146 ( V_49 , V_142 ++ ) ) == 0 );
if ( ! V_16 || ( V_16 == - V_147 && V_144 ) )
return 0 ;
if ( V_143 && V_141 ) {
struct V_62 * V_148 , * V_63 = F_80 ( V_45 ) ;
struct V_44 * V_149 ;
struct V_150 * V_151 ;
T_2 V_152 = sizeof( * V_151 ) + V_122 ( V_63 ) ;
int V_119 = F_81 ( sizeof( struct V_71 ) ) ;
struct V_27 * V_120 [ V_121 + 1 ] ;
struct V_27 * V_153 ;
T_5 * V_154 ;
V_149 = F_92 ( V_152 , V_25 ) ;
if ( V_149 == NULL )
return - V_92 ;
V_148 = F_93 ( V_149 , F_84 ( V_45 ) . V_67 ,
V_63 -> V_131 , V_155 , V_152 , 0 ) ;
V_151 = F_61 ( V_148 ) ;
V_151 -> error = V_16 ;
memcpy ( & V_151 -> V_156 , V_63 , V_63 -> V_122 ) ;
V_153 = ( void * ) & V_151 -> V_156 + V_119 ;
F_82 ( V_120 , V_121 ,
V_153 , V_63 -> V_122 - V_119 ,
V_157 ) ;
V_154 = F_39 ( V_120 [ V_158 ] ) ;
* V_154 = V_143 ;
F_94 ( V_82 , V_149 , F_84 ( V_45 ) . V_67 , V_159 ) ;
return - V_160 ;
}
return V_16 ;
}
static int
F_95 ( struct V_81 * V_82 , struct V_44 * V_45 ,
const struct V_62 * V_63 ,
const struct V_27 * const V_83 [] )
{
struct V_48 * V_49 ;
struct V_27 * V_32 [ V_161 + 1 ] = {} ;
const struct V_27 * V_28 ;
T_5 V_47 = F_58 ( V_63 ) ;
bool V_141 ;
int V_16 = 0 ;
if ( F_34 ( F_56 ( V_83 ) ||
V_83 [ V_87 ] == NULL ||
! ( ( V_83 [ V_91 ] != NULL ) ^
( V_83 [ V_162 ] != NULL ) ) ||
( V_83 [ V_91 ] != NULL &&
! F_32 ( V_83 [ V_91 ] ) ) ||
( V_83 [ V_162 ] != NULL &&
( ! F_32 ( V_83 [ V_162 ] ) ||
V_83 [ V_158 ] == NULL ) ) ) )
return - V_34 ;
V_49 = F_63 ( F_39 ( V_83 [ V_87 ] ) ) ;
if ( V_49 == NULL )
return - V_102 ;
V_141 = ! ! V_83 [ V_158 ] ;
if ( V_83 [ V_91 ] ) {
if ( F_35 ( V_32 , V_161 ,
V_83 [ V_91 ] ,
V_49 -> type -> V_163 ) )
return - V_34 ;
V_16 = F_91 ( V_82 , V_45 , V_49 , V_32 , V_55 , V_47 ,
V_141 ) ;
} else {
int V_164 ;
F_96 (nla, attr[IPSET_ATTR_ADT], nla_rem) {
memset ( V_32 , 0 , sizeof( V_32 ) ) ;
if ( V_29 ( V_28 ) != V_91 ||
! F_32 ( V_28 ) ||
F_35 ( V_32 , V_161 , V_28 ,
V_49 -> type -> V_163 ) )
return - V_34 ;
V_16 = F_91 ( V_82 , V_45 , V_49 , V_32 , V_55 ,
V_47 , V_141 ) ;
if ( V_16 < 0 )
return V_16 ;
}
}
return V_16 ;
}
static int
F_97 ( struct V_81 * V_82 , struct V_44 * V_45 ,
const struct V_62 * V_63 ,
const struct V_27 * const V_83 [] )
{
struct V_48 * V_49 ;
struct V_27 * V_32 [ V_161 + 1 ] = {} ;
const struct V_27 * V_28 ;
T_5 V_47 = F_58 ( V_63 ) ;
bool V_141 ;
int V_16 = 0 ;
if ( F_34 ( F_56 ( V_83 ) ||
V_83 [ V_87 ] == NULL ||
! ( ( V_83 [ V_91 ] != NULL ) ^
( V_83 [ V_162 ] != NULL ) ) ||
( V_83 [ V_91 ] != NULL &&
! F_32 ( V_83 [ V_91 ] ) ) ||
( V_83 [ V_162 ] != NULL &&
( ! F_32 ( V_83 [ V_162 ] ) ||
V_83 [ V_158 ] == NULL ) ) ) )
return - V_34 ;
V_49 = F_63 ( F_39 ( V_83 [ V_87 ] ) ) ;
if ( V_49 == NULL )
return - V_102 ;
V_141 = ! ! V_83 [ V_158 ] ;
if ( V_83 [ V_91 ] ) {
if ( F_35 ( V_32 , V_161 ,
V_83 [ V_91 ] ,
V_49 -> type -> V_163 ) )
return - V_34 ;
V_16 = F_91 ( V_82 , V_45 , V_49 , V_32 , V_56 , V_47 ,
V_141 ) ;
} else {
int V_164 ;
F_96 (nla, attr[IPSET_ATTR_ADT], nla_rem) {
memset ( V_32 , 0 , sizeof( * V_32 ) ) ;
if ( V_29 ( V_28 ) != V_91 ||
! F_32 ( V_28 ) ||
F_35 ( V_32 , V_161 , V_28 ,
V_49 -> type -> V_163 ) )
return - V_34 ;
V_16 = F_91 ( V_82 , V_45 , V_49 , V_32 , V_56 ,
V_47 , V_141 ) ;
if ( V_16 < 0 )
return V_16 ;
}
}
return V_16 ;
}
static int
F_98 ( struct V_81 * V_82 , struct V_44 * V_45 ,
const struct V_62 * V_63 ,
const struct V_27 * const V_83 [] )
{
struct V_48 * V_49 ;
struct V_27 * V_32 [ V_161 + 1 ] = {} ;
int V_16 = 0 ;
if ( F_34 ( F_56 ( V_83 ) ||
V_83 [ V_87 ] == NULL ||
V_83 [ V_91 ] == NULL ||
! F_32 ( V_83 [ V_91 ] ) ) )
return - V_34 ;
V_49 = F_63 ( F_39 ( V_83 [ V_87 ] ) ) ;
if ( V_49 == NULL )
return - V_102 ;
if ( F_35 ( V_32 , V_161 , V_83 [ V_91 ] ,
V_49 -> type -> V_163 ) )
return - V_34 ;
F_46 ( & V_49 -> V_51 ) ;
V_16 = V_49 -> V_52 -> V_145 ( V_49 , V_32 , V_54 , NULL , 0 ) ;
F_47 ( & V_49 -> V_51 ) ;
if ( V_16 == - V_8 )
V_16 = 1 ;
return V_16 < 0 ? V_16 : V_16 > 0 ? 0 : - V_147 ;
}
static int
F_99 ( struct V_81 * V_82 , struct V_44 * V_45 ,
const struct V_62 * V_63 ,
const struct V_27 * const V_83 [] )
{
const struct V_48 * V_49 ;
struct V_44 * V_149 ;
struct V_62 * V_165 ;
T_4 V_40 ;
int V_16 = 0 ;
if ( F_34 ( F_56 ( V_83 ) ||
V_83 [ V_87 ] == NULL ) )
return - V_34 ;
V_40 = F_62 ( F_39 ( V_83 [ V_87 ] ) ) ;
if ( V_40 == V_58 )
return - V_102 ;
V_49 = V_42 [ V_40 ] ;
V_149 = F_92 ( V_166 , V_25 ) ;
if ( V_149 == NULL )
return - V_92 ;
V_165 = F_59 ( V_149 , F_84 ( V_45 ) . V_67 , V_63 -> V_131 , 0 ,
V_167 ) ;
if ( ! V_165 )
goto V_168;
F_86 ( V_149 , V_61 , V_18 ) ;
F_87 ( V_149 , V_87 , V_49 -> V_3 ) ;
F_87 ( V_149 , V_88 , V_49 -> type -> V_3 ) ;
F_86 ( V_149 , V_90 , V_49 -> V_4 ) ;
F_86 ( V_149 , V_89 , V_49 -> type -> V_5 ) ;
F_88 ( V_149 , V_165 ) ;
V_16 = F_94 ( V_82 , V_149 , F_84 ( V_45 ) . V_67 , V_159 ) ;
if ( V_16 < 0 )
return V_16 ;
return 0 ;
V_137:
F_100 ( V_149 , V_165 ) ;
V_168:
F_101 ( V_149 ) ;
return - V_133 ;
}
static int
V_2 ( struct V_81 * V_82 , struct V_44 * V_45 ,
const struct V_62 * V_63 ,
const struct V_27 * const V_83 [] )
{
struct V_44 * V_149 ;
struct V_62 * V_165 ;
T_1 V_4 , V_14 , V_15 ;
const char * V_86 ;
int V_16 = 0 ;
if ( F_34 ( F_56 ( V_83 ) ||
V_83 [ V_88 ] == NULL ||
V_83 [ V_90 ] == NULL ) )
return - V_34 ;
V_4 = F_57 ( V_83 [ V_90 ] ) ;
V_86 = F_39 ( V_83 [ V_88 ] ) ;
V_16 = F_18 ( V_86 , V_4 , & V_14 , & V_15 ) ;
if ( V_16 )
return V_16 ;
V_149 = F_92 ( V_166 , V_25 ) ;
if ( V_149 == NULL )
return - V_92 ;
V_165 = F_59 ( V_149 , F_84 ( V_45 ) . V_67 , V_63 -> V_131 , 0 ,
V_169 ) ;
if ( ! V_165 )
goto V_168;
F_86 ( V_149 , V_61 , V_18 ) ;
F_87 ( V_149 , V_88 , V_86 ) ;
F_86 ( V_149 , V_90 , V_4 ) ;
F_86 ( V_149 , V_89 , V_15 ) ;
F_86 ( V_149 , V_170 , V_14 ) ;
F_88 ( V_149 , V_165 ) ;
F_10 ( L_28 , V_165 -> V_122 ) ;
V_16 = F_94 ( V_82 , V_149 , F_84 ( V_45 ) . V_67 , V_159 ) ;
if ( V_16 < 0 )
return V_16 ;
return 0 ;
V_137:
F_100 ( V_149 , V_165 ) ;
V_168:
F_101 ( V_149 ) ;
return - V_133 ;
}
static int
F_102 ( struct V_81 * V_82 , struct V_44 * V_45 ,
const struct V_62 * V_63 ,
const struct V_27 * const V_83 [] )
{
struct V_44 * V_149 ;
struct V_62 * V_165 ;
int V_16 = 0 ;
if ( F_34 ( V_83 [ V_61 ] == NULL ) )
return - V_34 ;
V_149 = F_92 ( V_166 , V_25 ) ;
if ( V_149 == NULL )
return - V_92 ;
V_165 = F_59 ( V_149 , F_84 ( V_45 ) . V_67 , V_63 -> V_131 , 0 ,
V_171 ) ;
if ( ! V_165 )
goto V_168;
F_86 ( V_149 , V_61 , V_18 ) ;
F_88 ( V_149 , V_165 ) ;
V_16 = F_94 ( V_82 , V_149 , F_84 ( V_45 ) . V_67 , V_159 ) ;
if ( V_16 < 0 )
return V_16 ;
return 0 ;
V_137:
F_100 ( V_149 , V_165 ) ;
V_168:
F_101 ( V_149 ) ;
return - V_133 ;
}
static int
F_103 ( struct V_81 * V_172 , int V_173 , void T_6 * V_174 , int * V_138 )
{
unsigned * V_175 ;
void * V_176 ;
int V_177 = * V_138 , V_16 = 0 ;
if ( ! F_104 ( V_178 ) )
return - V_179 ;
if ( V_173 != V_180 )
return - V_181 ;
if ( * V_138 < sizeof( unsigned ) )
return - V_19 ;
V_176 = F_105 ( * V_138 ) ;
if ( ! V_176 )
return - V_92 ;
if ( F_106 ( V_176 , V_174 , * V_138 ) != 0 ) {
V_16 = - V_12 ;
goto V_182;
}
V_175 = ( unsigned * ) V_176 ;
if ( * V_175 < V_183 ) {
struct V_184 * V_185 = V_176 ;
if ( V_185 -> V_76 != V_18 ) {
V_16 = - V_186 ;
goto V_182;
}
}
switch ( * V_175 ) {
case V_183 : {
struct V_184 * V_185 = V_176 ;
if ( * V_138 != sizeof( struct V_184 ) ) {
V_16 = - V_19 ;
goto V_182;
}
V_185 -> V_76 = V_18 ;
V_16 = F_107 ( V_174 , V_185 ,
sizeof( struct V_184 ) ) ;
goto V_182;
}
case V_187 : {
struct V_188 * V_189 = V_176 ;
if ( * V_138 != sizeof( struct V_188 ) ) {
V_16 = - V_19 ;
goto V_182;
}
V_189 -> V_49 . V_3 [ V_93 - 1 ] = '\0' ;
F_13 () ;
V_189 -> V_49 . V_40 = F_62 ( V_189 -> V_49 . V_3 ) ;
F_9 () ;
goto V_190;
}
case V_191 : {
struct V_188 * V_189 = V_176 ;
if ( * V_138 != sizeof( struct V_188 ) ||
V_189 -> V_49 . V_40 >= V_60 ) {
V_16 = - V_19 ;
goto V_182;
}
F_13 () ;
strncpy ( V_189 -> V_49 . V_3 ,
V_42 [ V_189 -> V_49 . V_40 ]
? V_42 [ V_189 -> V_49 . V_40 ] -> V_3 : L_29 ,
V_93 ) ;
F_9 () ;
goto V_190;
}
default:
V_16 = - V_192 ;
goto V_182;
}
V_190:
V_16 = F_107 ( V_174 , V_176 , V_177 ) ;
V_182:
F_30 ( V_176 ) ;
if ( V_16 > 0 )
V_16 = 0 ;
return V_16 ;
}
static int T_7
F_108 ( void )
{
int V_16 ;
if ( V_193 )
V_60 = V_193 ;
if ( V_60 >= V_58 )
V_60 = V_58 - 1 ;
V_42 = F_26 ( sizeof( struct V_48 * ) * V_60 ,
V_25 ) ;
if ( ! V_42 ) {
F_109 ( L_30 ) ;
return - V_92 ;
}
V_16 = F_110 ( & V_194 ) ;
if ( V_16 != 0 ) {
F_109 ( L_31 ) ;
F_31 ( V_42 ) ;
return V_16 ;
}
V_16 = F_111 ( & V_195 ) ;
if ( V_16 != 0 ) {
F_109 ( L_32 , V_16 ) ;
F_112 ( & V_194 ) ;
F_31 ( V_42 ) ;
return V_16 ;
}
F_113 ( L_33 , V_18 ) ;
return 0 ;
}
static void T_8
F_114 ( void )
{
F_115 ( & V_195 ) ;
F_112 ( & V_194 ) ;
F_31 ( V_42 ) ;
F_10 ( L_34 ) ;
}
