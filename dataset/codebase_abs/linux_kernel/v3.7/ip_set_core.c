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
( type -> V_4 == V_4 ||
type -> V_4 == V_6 ) &&
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
( type -> V_4 == V_4 ||
type -> V_4 == V_6 ) ) {
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
} else {
if ( ( V_51 -> V_62 & V_63 ) &&
( V_53 -> type -> V_64 & V_65 ) &&
( V_18 > 0 || V_18 == - V_66 ) )
V_18 = - V_18 ;
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
V_18 = V_53 -> V_57 -> V_58 ( V_53 , V_47 , V_49 , V_67 , V_51 ) ;
F_42 ( & V_53 -> V_56 ) ;
return V_18 ;
}
T_4
F_50 ( const char * V_3 , struct V_52 * * V_53 )
{
T_4 V_68 , V_42 = V_69 ;
struct V_52 * V_70 ;
for ( V_68 = 0 ; V_68 < V_71 ; V_68 ++ ) {
V_70 = V_44 [ V_68 ] ;
if ( V_70 != NULL && F_7 ( V_70 -> V_3 , V_3 ) ) {
F_40 ( V_68 ) ;
V_42 = V_68 ;
* V_53 = V_70 ;
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
struct V_52 * V_70 ;
T_4 V_42 ;
F_13 () ;
V_42 = F_50 ( V_3 , & V_70 ) ;
F_9 () ;
return V_42 ;
}
T_4
F_54 ( T_4 V_42 )
{
if ( V_42 > V_71 )
return V_69 ;
F_13 () ;
if ( V_44 [ V_42 ] )
F_40 ( V_42 ) ;
else
V_42 = V_69 ;
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
return ! V_34 [ V_72 ] ||
F_57 ( V_34 [ V_72 ] ) != V_20 ;
}
static inline T_5
F_58 ( const struct V_73 * V_74 )
{
return V_74 -> V_75 & V_76 ? 0 : V_77 ;
}
static struct V_73 *
F_59 ( struct V_46 * V_47 , T_5 V_78 , T_5 V_79 , unsigned int V_62 ,
enum V_80 V_81 )
{
struct V_73 * V_74 ;
struct V_82 * V_83 ;
V_74 = F_60 ( V_47 , V_78 , V_79 , V_81 | ( V_84 << 8 ) ,
sizeof( * V_83 ) , V_62 ) ;
if ( V_74 == NULL )
return NULL ;
V_83 = F_61 ( V_74 ) ;
V_83 -> V_85 = V_86 ;
V_83 -> V_87 = V_88 ;
V_83 -> V_89 = 0 ;
return V_74 ;
}
static T_4
F_62 ( const char * V_3 )
{
T_4 V_68 , V_42 = V_69 ;
const struct V_52 * V_53 ;
for ( V_68 = 0 ; V_42 == V_69 && V_68 < V_71 ; V_68 ++ ) {
V_53 = V_44 [ V_68 ] ;
if ( V_53 != NULL && F_7 ( V_53 -> V_3 , V_3 ) )
V_42 = V_68 ;
}
return V_42 ;
}
static inline struct V_52 *
F_63 ( const char * V_3 )
{
T_4 V_42 = F_62 ( V_3 ) ;
return V_42 == V_69 ? NULL : V_44 [ V_42 ] ;
}
static int
F_64 ( const char * V_3 , T_4 * V_42 , struct V_52 * * V_53 )
{
T_4 V_68 ;
* V_42 = V_69 ;
for ( V_68 = 0 ; V_68 < V_71 ; V_68 ++ ) {
if ( V_44 [ V_68 ] == NULL ) {
if ( * V_42 == V_69 )
* V_42 = V_68 ;
} else if ( F_7 ( V_3 , V_44 [ V_68 ] -> V_3 ) ) {
* V_53 = V_44 [ V_68 ] ;
return - V_90 ;
}
}
if ( * V_42 == V_69 )
return - V_91 ;
return 0 ;
}
static int
F_65 ( struct V_92 * V_93 , struct V_46 * V_47 ,
const struct V_73 * V_74 ,
const struct V_29 * const V_94 [] )
{
return - V_95 ;
}
static int
F_66 ( struct V_92 * V_93 , struct V_46 * V_47 ,
const struct V_73 * V_74 ,
const struct V_29 * const V_94 [] )
{
struct V_52 * V_53 , * V_96 = NULL ;
T_4 V_42 = V_69 ;
struct V_29 * V_34 [ V_97 + 1 ] = {} ;
const char * V_3 , * V_98 ;
T_1 V_4 , V_5 ;
T_5 V_62 = F_58 ( V_74 ) ;
int V_18 = 0 ;
if ( F_34 ( F_56 ( V_94 ) ||
V_94 [ V_99 ] == NULL ||
V_94 [ V_100 ] == NULL ||
V_94 [ V_101 ] == NULL ||
V_94 [ V_102 ] == NULL ||
( V_94 [ V_103 ] != NULL &&
! F_32 ( V_94 [ V_103 ] ) ) ) )
return - V_36 ;
V_3 = F_39 ( V_94 [ V_99 ] ) ;
V_98 = F_39 ( V_94 [ V_100 ] ) ;
V_4 = F_57 ( V_94 [ V_102 ] ) ;
V_5 = F_57 ( V_94 [ V_101 ] ) ;
F_10 ( L_18 ,
V_3 , V_98 , F_20 ( V_4 ) , V_5 ) ;
V_53 = F_26 ( sizeof( struct V_52 ) , V_27 ) ;
if ( ! V_53 )
return - V_104 ;
F_67 ( & V_53 -> V_56 ) ;
F_68 ( V_53 -> V_3 , V_3 , V_105 ) ;
V_53 -> V_4 = V_4 ;
V_53 -> V_5 = V_5 ;
V_18 = F_69 ( V_98 , V_4 , V_5 , & ( V_53 -> type ) ) ;
if ( V_18 )
goto V_106;
if ( V_94 [ V_103 ] &&
F_35 ( V_34 , V_97 , V_94 [ V_103 ] ,
V_53 -> type -> V_107 ) ) {
V_18 = - V_36 ;
goto V_108;
}
V_18 = V_53 -> type -> V_109 ( V_53 , V_34 , V_62 ) ;
if ( V_18 != 0 )
goto V_108;
V_18 = F_64 ( V_53 -> V_3 , & V_42 , & V_96 ) ;
if ( V_18 != 0 ) {
if ( V_18 == - V_90 &&
( V_62 & V_77 ) &&
F_7 ( V_53 -> type -> V_3 , V_96 -> type -> V_3 ) &&
V_53 -> type -> V_4 == V_96 -> type -> V_4 &&
V_53 -> type -> V_7 == V_96 -> type -> V_7 &&
V_53 -> type -> V_8 == V_96 -> type -> V_8 &&
V_53 -> V_57 -> V_110 ( V_53 , V_96 ) )
V_18 = 0 ;
goto V_111;
}
F_10 ( L_19 , V_53 -> V_3 , V_42 ) ;
V_44 [ V_42 ] = V_53 ;
return V_18 ;
V_111:
V_53 -> V_57 -> V_112 ( V_53 ) ;
V_108:
F_70 ( V_53 -> type -> V_13 ) ;
V_106:
F_31 ( V_53 ) ;
return V_18 ;
}
static void
F_71 ( T_4 V_42 )
{
struct V_52 * V_53 = V_44 [ V_42 ] ;
F_10 ( L_20 , V_53 -> V_3 ) ;
V_44 [ V_42 ] = NULL ;
V_53 -> V_57 -> V_112 ( V_53 ) ;
F_70 ( V_53 -> type -> V_13 ) ;
F_31 ( V_53 ) ;
}
static int
F_72 ( struct V_92 * V_93 , struct V_46 * V_47 ,
const struct V_73 * V_74 ,
const struct V_29 * const V_94 [] )
{
T_4 V_68 ;
int V_18 = 0 ;
if ( F_34 ( F_56 ( V_94 ) ) )
return - V_36 ;
F_46 ( & V_43 ) ;
if ( ! V_94 [ V_99 ] ) {
for ( V_68 = 0 ; V_68 < V_71 ; V_68 ++ ) {
if ( V_44 [ V_68 ] != NULL && V_44 [ V_68 ] -> V_45 ) {
V_18 = - V_113 ;
goto V_106;
}
}
F_47 ( & V_43 ) ;
for ( V_68 = 0 ; V_68 < V_71 ; V_68 ++ ) {
if ( V_44 [ V_68 ] != NULL )
F_71 ( V_68 ) ;
}
} else {
V_68 = F_62 ( F_39 ( V_94 [ V_99 ] ) ) ;
if ( V_68 == V_69 ) {
V_18 = - V_114 ;
goto V_106;
} else if ( V_44 [ V_68 ] -> V_45 ) {
V_18 = - V_113 ;
goto V_106;
}
F_47 ( & V_43 ) ;
F_71 ( V_68 ) ;
}
return 0 ;
V_106:
F_47 ( & V_43 ) ;
return V_18 ;
}
static void
F_73 ( struct V_52 * V_53 )
{
F_10 ( L_20 , V_53 -> V_3 ) ;
F_41 ( & V_53 -> V_56 ) ;
V_53 -> V_57 -> V_115 ( V_53 ) ;
F_42 ( & V_53 -> V_56 ) ;
}
static int
F_74 ( struct V_92 * V_93 , struct V_46 * V_47 ,
const struct V_73 * V_74 ,
const struct V_29 * const V_94 [] )
{
T_4 V_68 ;
if ( F_34 ( F_56 ( V_94 ) ) )
return - V_36 ;
if ( ! V_94 [ V_99 ] ) {
for ( V_68 = 0 ; V_68 < V_71 ; V_68 ++ )
if ( V_44 [ V_68 ] != NULL )
F_73 ( V_44 [ V_68 ] ) ;
} else {
V_68 = F_62 ( F_39 ( V_94 [ V_99 ] ) ) ;
if ( V_68 == V_69 )
return - V_114 ;
F_73 ( V_44 [ V_68 ] ) ;
}
return 0 ;
}
static int
F_75 ( struct V_92 * V_93 , struct V_46 * V_47 ,
const struct V_73 * V_74 ,
const struct V_29 * const V_94 [] )
{
struct V_52 * V_53 ;
const char * V_116 ;
T_4 V_68 ;
int V_18 = 0 ;
if ( F_34 ( F_56 ( V_94 ) ||
V_94 [ V_99 ] == NULL ||
V_94 [ V_117 ] == NULL ) )
return - V_36 ;
V_53 = F_63 ( F_39 ( V_94 [ V_99 ] ) ) ;
if ( V_53 == NULL )
return - V_114 ;
F_46 ( & V_43 ) ;
if ( V_53 -> V_45 != 0 ) {
V_18 = - V_118 ;
goto V_106;
}
V_116 = F_39 ( V_94 [ V_117 ] ) ;
for ( V_68 = 0 ; V_68 < V_71 ; V_68 ++ ) {
if ( V_44 [ V_68 ] != NULL &&
F_7 ( V_44 [ V_68 ] -> V_3 , V_116 ) ) {
V_18 = - V_119 ;
goto V_106;
}
}
strncpy ( V_53 -> V_3 , V_116 , V_105 ) ;
V_106:
F_47 ( & V_43 ) ;
return V_18 ;
}
static int
F_76 ( struct V_92 * V_93 , struct V_46 * V_47 ,
const struct V_73 * V_74 ,
const struct V_29 * const V_94 [] )
{
struct V_52 * V_120 , * V_121 ;
T_4 V_122 , V_123 ;
char V_124 [ V_105 ] ;
if ( F_34 ( F_56 ( V_94 ) ||
V_94 [ V_99 ] == NULL ||
V_94 [ V_117 ] == NULL ) )
return - V_36 ;
V_122 = F_62 ( F_39 ( V_94 [ V_99 ] ) ) ;
if ( V_122 == V_69 )
return - V_114 ;
V_123 = F_62 ( F_39 ( V_94 [ V_117 ] ) ) ;
if ( V_123 == V_69 )
return - V_119 ;
V_120 = V_44 [ V_122 ] ;
V_121 = V_44 [ V_123 ] ;
if ( ! ( V_120 -> type -> V_64 == V_121 -> type -> V_64 &&
V_120 -> type -> V_4 == V_121 -> type -> V_4 ) )
return - V_125 ;
strncpy ( V_124 , V_120 -> V_3 , V_105 ) ;
strncpy ( V_120 -> V_3 , V_121 -> V_3 , V_105 ) ;
strncpy ( V_121 -> V_3 , V_124 , V_105 ) ;
F_41 ( & V_43 ) ;
F_77 ( V_120 -> V_45 , V_121 -> V_45 ) ;
V_44 [ V_122 ] = V_121 ;
V_44 [ V_123 ] = V_120 ;
F_42 ( & V_43 ) ;
return 0 ;
}
static int
F_78 ( struct V_126 * V_127 )
{
if ( V_127 -> args [ 2 ] ) {
F_10 ( L_21 , V_44 [ V_127 -> args [ 1 ] ] -> V_3 ) ;
F_51 ( ( T_4 ) V_127 -> args [ 1 ] ) ;
}
return 0 ;
}
static inline void
F_79 ( struct V_73 * V_74 )
{
const struct V_29 * V_94 ;
int V_128 ;
F_10 ( L_22 ) ;
F_80 (attr, nlh, sizeof(struct nfgenmsg), rem) {
F_10 ( L_23 , V_31 ( V_94 ) , V_94 -> V_129 ) ;
}
}
static int
F_81 ( struct V_126 * V_127 )
{
struct V_73 * V_74 = F_82 ( V_127 -> V_47 ) ;
int V_130 = F_83 ( sizeof( struct V_82 ) ) ;
struct V_29 * V_131 [ V_132 + 1 ] ;
struct V_29 * V_94 = ( void * ) V_74 + V_130 ;
T_5 V_133 ;
T_4 V_42 ;
F_84 ( V_131 , V_132 ,
V_94 , V_74 -> V_134 - V_130 , V_135 ) ;
if ( V_131 [ V_99 ] ) {
V_42 = F_62 ( F_39 ( V_131 [ V_99 ] ) ) ;
if ( V_42 == V_69 )
return - V_114 ;
V_133 = V_136 ;
V_127 -> args [ 1 ] = V_42 ;
} else
V_133 = V_137 ;
if ( V_131 [ V_138 ] ) {
T_5 V_139 = F_85 ( V_131 [ V_138 ] ) ;
V_133 |= ( V_139 << 16 ) ;
}
V_127 -> args [ 0 ] = V_133 ;
return 0 ;
}
static int
F_86 ( struct V_46 * V_47 , struct V_126 * V_127 )
{
T_4 V_42 = V_69 , V_17 ;
struct V_52 * V_53 = NULL ;
struct V_73 * V_74 = NULL ;
unsigned int V_62 = F_87 ( V_127 -> V_47 ) . V_78 ? V_140 : 0 ;
T_5 V_133 , V_141 ;
int V_18 = 0 ;
if ( ! V_127 -> args [ 0 ] ) {
V_18 = F_81 ( V_127 ) ;
if ( V_18 < 0 ) {
V_74 = F_82 ( V_127 -> V_47 ) ;
if ( V_74 -> V_75 & V_142 )
F_88 ( V_127 -> V_47 , V_74 , V_18 ) ;
return V_18 ;
}
}
if ( V_127 -> args [ 1 ] >= V_71 )
goto V_106;
V_133 = F_89 ( V_127 -> args [ 0 ] ) ;
V_141 = F_90 ( V_127 -> args [ 0 ] ) ;
V_17 = V_133 == V_136 ? V_127 -> args [ 1 ] + 1 : V_71 ;
V_143:
F_10 ( L_24 ,
V_133 , V_141 , V_127 -> args [ 1 ] ) ;
for (; V_127 -> args [ 1 ] < V_17 ; V_127 -> args [ 1 ] ++ ) {
V_42 = ( T_4 ) V_127 -> args [ 1 ] ;
V_53 = V_44 [ V_42 ] ;
if ( V_53 == NULL ) {
if ( V_133 == V_136 ) {
V_18 = - V_114 ;
goto V_106;
}
continue;
}
if ( V_133 != V_136 &&
( ( V_133 == V_137 ) ==
! ! ( V_53 -> type -> V_64 & V_144 ) ) )
continue;
F_10 ( L_25 , V_53 -> V_3 ) ;
if ( ! V_127 -> args [ 2 ] ) {
F_10 ( L_26 ) ;
F_40 ( V_42 ) ;
}
V_74 = F_59 ( V_47 , F_87 ( V_127 -> V_47 ) . V_78 ,
V_127 -> V_74 -> V_145 , V_62 ,
V_146 ) ;
if ( ! V_74 ) {
V_18 = - V_147 ;
goto V_148;
}
if ( F_91 ( V_47 , V_72 , V_20 ) ||
F_92 ( V_47 , V_99 , V_53 -> V_3 ) )
goto V_149;
if ( V_141 & V_150 )
goto V_151;
switch ( V_127 -> args [ 2 ] ) {
case 0 :
if ( F_92 ( V_47 , V_100 ,
V_53 -> type -> V_3 ) ||
F_91 ( V_47 , V_102 ,
V_53 -> V_4 ) ||
F_91 ( V_47 , V_101 ,
V_53 -> V_5 ) )
goto V_149;
V_18 = V_53 -> V_57 -> V_152 ( V_53 , V_47 ) ;
if ( V_18 < 0 )
goto V_148;
if ( V_141 & V_153 )
goto V_151;
default:
F_46 ( & V_53 -> V_56 ) ;
V_18 = V_53 -> V_57 -> V_22 ( V_53 , V_47 , V_127 ) ;
F_47 ( & V_53 -> V_56 ) ;
if ( ! V_127 -> args [ 2 ] )
goto V_151;
goto V_148;
}
}
if ( V_133 == V_137 ) {
V_133 = V_154 ;
V_127 -> args [ 0 ] = V_133 | ( V_141 << 16 ) ;
V_127 -> args [ 1 ] = 0 ;
goto V_143;
}
goto V_106;
V_149:
V_18 = - V_14 ;
V_151:
if ( V_133 == V_136 )
V_127 -> args [ 1 ] = V_69 ;
else
V_127 -> args [ 1 ] ++ ;
V_148:
if ( V_18 || ! V_127 -> args [ 2 ] ) {
F_10 ( L_21 , V_44 [ V_42 ] -> V_3 ) ;
F_51 ( V_42 ) ;
V_127 -> args [ 2 ] = 0 ;
}
V_106:
if ( V_74 ) {
F_93 ( V_47 , V_74 ) ;
F_10 ( L_27 , V_74 -> V_134 ) ;
F_79 ( V_74 ) ;
}
return V_18 < 0 ? V_18 : V_47 -> V_155 ;
}
static int
F_94 ( struct V_92 * V_93 , struct V_46 * V_47 ,
const struct V_73 * V_74 ,
const struct V_29 * const V_94 [] )
{
if ( F_34 ( F_56 ( V_94 ) ) )
return - V_36 ;
{
struct V_156 V_157 = {
. V_158 = F_86 ,
. V_159 = F_78 ,
} ;
return F_95 ( V_93 , V_47 , V_74 , & V_157 ) ;
}
}
static int
F_96 ( struct V_92 * V_93 , struct V_46 * V_47 , struct V_52 * V_53 ,
struct V_29 * V_34 [] , enum V_160 V_161 ,
T_5 V_62 , bool V_162 )
{
int V_18 ;
T_5 V_163 = 0 ;
bool V_164 = V_62 & V_77 , V_165 = false ;
do {
F_41 ( & V_53 -> V_56 ) ;
V_18 = V_53 -> V_57 -> V_166 ( V_53 , V_34 , V_161 , & V_163 , V_62 , V_165 ) ;
F_42 ( & V_53 -> V_56 ) ;
V_165 = true ;
} while ( V_18 == - V_60 &&
V_53 -> V_57 -> V_167 &&
( V_18 = V_53 -> V_57 -> V_167 ( V_53 , V_165 ) ) == 0 );
if ( ! V_18 || ( V_18 == - V_168 && V_164 ) )
return 0 ;
if ( V_163 && V_162 ) {
struct V_73 * V_169 , * V_74 = F_82 ( V_47 ) ;
struct V_46 * V_170 ;
struct V_171 * V_172 ;
T_2 V_173 = sizeof( * V_172 ) + V_134 ( V_74 ) ;
int V_130 = F_83 ( sizeof( struct V_82 ) ) ;
struct V_29 * V_131 [ V_132 + 1 ] ;
struct V_29 * V_174 ;
T_5 * V_175 ;
V_170 = F_97 ( V_173 , V_27 ) ;
if ( V_170 == NULL )
return - V_104 ;
V_169 = F_98 ( V_170 , F_87 ( V_47 ) . V_78 ,
V_74 -> V_145 , V_176 , V_173 , 0 ) ;
V_172 = F_61 ( V_169 ) ;
V_172 -> error = V_18 ;
memcpy ( & V_172 -> V_177 , V_74 , V_74 -> V_134 ) ;
V_174 = ( void * ) & V_172 -> V_177 + V_130 ;
F_84 ( V_131 , V_132 ,
V_174 , V_74 -> V_134 - V_130 ,
V_178 ) ;
V_175 = F_39 ( V_131 [ V_179 ] ) ;
* V_175 = V_163 ;
F_99 ( V_93 , V_170 , F_87 ( V_47 ) . V_78 , V_180 ) ;
return - V_181 ;
}
return V_18 ;
}
static int
F_100 ( struct V_92 * V_93 , struct V_46 * V_47 ,
const struct V_73 * V_74 ,
const struct V_29 * const V_94 [] )
{
struct V_52 * V_53 ;
struct V_29 * V_34 [ V_182 + 1 ] = {} ;
const struct V_29 * V_30 ;
T_5 V_62 = F_58 ( V_74 ) ;
bool V_162 ;
int V_18 = 0 ;
if ( F_34 ( F_56 ( V_94 ) ||
V_94 [ V_99 ] == NULL ||
! ( ( V_94 [ V_103 ] != NULL ) ^
( V_94 [ V_183 ] != NULL ) ) ||
( V_94 [ V_103 ] != NULL &&
! F_32 ( V_94 [ V_103 ] ) ) ||
( V_94 [ V_183 ] != NULL &&
( ! F_32 ( V_94 [ V_183 ] ) ||
V_94 [ V_179 ] == NULL ) ) ) )
return - V_36 ;
V_53 = F_63 ( F_39 ( V_94 [ V_99 ] ) ) ;
if ( V_53 == NULL )
return - V_114 ;
V_162 = ! ! V_94 [ V_179 ] ;
if ( V_94 [ V_103 ] ) {
if ( F_35 ( V_34 , V_182 ,
V_94 [ V_103 ] ,
V_53 -> type -> V_184 ) )
return - V_36 ;
V_18 = F_96 ( V_93 , V_47 , V_53 , V_34 , V_61 , V_62 ,
V_162 ) ;
} else {
int V_185 ;
F_101 (nla, attr[IPSET_ATTR_ADT], nla_rem) {
memset ( V_34 , 0 , sizeof( V_34 ) ) ;
if ( V_31 ( V_30 ) != V_103 ||
! F_32 ( V_30 ) ||
F_35 ( V_34 , V_182 , V_30 ,
V_53 -> type -> V_184 ) )
return - V_36 ;
V_18 = F_96 ( V_93 , V_47 , V_53 , V_34 , V_61 ,
V_62 , V_162 ) ;
if ( V_18 < 0 )
return V_18 ;
}
}
return V_18 ;
}
static int
F_102 ( struct V_92 * V_93 , struct V_46 * V_47 ,
const struct V_73 * V_74 ,
const struct V_29 * const V_94 [] )
{
struct V_52 * V_53 ;
struct V_29 * V_34 [ V_182 + 1 ] = {} ;
const struct V_29 * V_30 ;
T_5 V_62 = F_58 ( V_74 ) ;
bool V_162 ;
int V_18 = 0 ;
if ( F_34 ( F_56 ( V_94 ) ||
V_94 [ V_99 ] == NULL ||
! ( ( V_94 [ V_103 ] != NULL ) ^
( V_94 [ V_183 ] != NULL ) ) ||
( V_94 [ V_103 ] != NULL &&
! F_32 ( V_94 [ V_103 ] ) ) ||
( V_94 [ V_183 ] != NULL &&
( ! F_32 ( V_94 [ V_183 ] ) ||
V_94 [ V_179 ] == NULL ) ) ) )
return - V_36 ;
V_53 = F_63 ( F_39 ( V_94 [ V_99 ] ) ) ;
if ( V_53 == NULL )
return - V_114 ;
V_162 = ! ! V_94 [ V_179 ] ;
if ( V_94 [ V_103 ] ) {
if ( F_35 ( V_34 , V_182 ,
V_94 [ V_103 ] ,
V_53 -> type -> V_184 ) )
return - V_36 ;
V_18 = F_96 ( V_93 , V_47 , V_53 , V_34 , V_67 , V_62 ,
V_162 ) ;
} else {
int V_185 ;
F_101 (nla, attr[IPSET_ATTR_ADT], nla_rem) {
memset ( V_34 , 0 , sizeof( * V_34 ) ) ;
if ( V_31 ( V_30 ) != V_103 ||
! F_32 ( V_30 ) ||
F_35 ( V_34 , V_182 , V_30 ,
V_53 -> type -> V_184 ) )
return - V_36 ;
V_18 = F_96 ( V_93 , V_47 , V_53 , V_34 , V_67 ,
V_62 , V_162 ) ;
if ( V_18 < 0 )
return V_18 ;
}
}
return V_18 ;
}
static int
F_103 ( struct V_92 * V_93 , struct V_46 * V_47 ,
const struct V_73 * V_74 ,
const struct V_29 * const V_94 [] )
{
struct V_52 * V_53 ;
struct V_29 * V_34 [ V_182 + 1 ] = {} ;
int V_18 = 0 ;
if ( F_34 ( F_56 ( V_94 ) ||
V_94 [ V_99 ] == NULL ||
V_94 [ V_103 ] == NULL ||
! F_32 ( V_94 [ V_103 ] ) ) )
return - V_36 ;
V_53 = F_63 ( F_39 ( V_94 [ V_99 ] ) ) ;
if ( V_53 == NULL )
return - V_114 ;
if ( F_35 ( V_34 , V_182 , V_94 [ V_103 ] ,
V_53 -> type -> V_184 ) )
return - V_36 ;
F_46 ( & V_53 -> V_56 ) ;
V_18 = V_53 -> V_57 -> V_166 ( V_53 , V_34 , V_59 , NULL , 0 , 0 ) ;
F_47 ( & V_53 -> V_56 ) ;
if ( V_18 == - V_60 )
V_18 = 1 ;
return V_18 < 0 ? V_18 : V_18 > 0 ? 0 : - V_168 ;
}
static int
F_104 ( struct V_92 * V_93 , struct V_46 * V_47 ,
const struct V_73 * V_74 ,
const struct V_29 * const V_94 [] )
{
const struct V_52 * V_53 ;
struct V_46 * V_170 ;
struct V_73 * V_186 ;
T_4 V_42 ;
int V_18 = 0 ;
if ( F_34 ( F_56 ( V_94 ) ||
V_94 [ V_99 ] == NULL ) )
return - V_36 ;
V_42 = F_62 ( F_39 ( V_94 [ V_99 ] ) ) ;
if ( V_42 == V_69 )
return - V_114 ;
V_53 = V_44 [ V_42 ] ;
V_170 = F_97 ( V_187 , V_27 ) ;
if ( V_170 == NULL )
return - V_104 ;
V_186 = F_59 ( V_170 , F_87 ( V_47 ) . V_78 , V_74 -> V_145 , 0 ,
V_188 ) ;
if ( ! V_186 )
goto V_189;
if ( F_91 ( V_170 , V_72 , V_20 ) ||
F_92 ( V_170 , V_99 , V_53 -> V_3 ) ||
F_92 ( V_170 , V_100 , V_53 -> type -> V_3 ) ||
F_91 ( V_170 , V_102 , V_53 -> V_4 ) ||
F_91 ( V_170 , V_101 , V_53 -> V_5 ) )
goto V_149;
F_93 ( V_170 , V_186 ) ;
V_18 = F_99 ( V_93 , V_170 , F_87 ( V_47 ) . V_78 , V_180 ) ;
if ( V_18 < 0 )
return V_18 ;
return 0 ;
V_149:
F_105 ( V_170 , V_186 ) ;
V_189:
F_106 ( V_170 ) ;
return - V_147 ;
}
static int
V_2 ( struct V_92 * V_93 , struct V_46 * V_47 ,
const struct V_73 * V_74 ,
const struct V_29 * const V_94 [] )
{
struct V_46 * V_170 ;
struct V_73 * V_186 ;
T_1 V_4 , V_16 , V_17 ;
const char * V_98 ;
int V_18 = 0 ;
if ( F_34 ( F_56 ( V_94 ) ||
V_94 [ V_100 ] == NULL ||
V_94 [ V_102 ] == NULL ) )
return - V_36 ;
V_4 = F_57 ( V_94 [ V_102 ] ) ;
V_98 = F_39 ( V_94 [ V_100 ] ) ;
V_18 = F_107 ( V_98 , V_4 , & V_16 , & V_17 ) ;
if ( V_18 )
return V_18 ;
V_170 = F_97 ( V_187 , V_27 ) ;
if ( V_170 == NULL )
return - V_104 ;
V_186 = F_59 ( V_170 , F_87 ( V_47 ) . V_78 , V_74 -> V_145 , 0 ,
V_190 ) ;
if ( ! V_186 )
goto V_189;
if ( F_91 ( V_170 , V_72 , V_20 ) ||
F_92 ( V_170 , V_100 , V_98 ) ||
F_91 ( V_170 , V_102 , V_4 ) ||
F_91 ( V_170 , V_101 , V_17 ) ||
F_91 ( V_170 , V_191 , V_16 ) )
goto V_149;
F_93 ( V_170 , V_186 ) ;
F_10 ( L_28 , V_186 -> V_134 ) ;
V_18 = F_99 ( V_93 , V_170 , F_87 ( V_47 ) . V_78 , V_180 ) ;
if ( V_18 < 0 )
return V_18 ;
return 0 ;
V_149:
F_105 ( V_170 , V_186 ) ;
V_189:
F_106 ( V_170 ) ;
return - V_147 ;
}
static int
F_108 ( struct V_92 * V_93 , struct V_46 * V_47 ,
const struct V_73 * V_74 ,
const struct V_29 * const V_94 [] )
{
struct V_46 * V_170 ;
struct V_73 * V_186 ;
int V_18 = 0 ;
if ( F_34 ( V_94 [ V_72 ] == NULL ) )
return - V_36 ;
V_170 = F_97 ( V_187 , V_27 ) ;
if ( V_170 == NULL )
return - V_104 ;
V_186 = F_59 ( V_170 , F_87 ( V_47 ) . V_78 , V_74 -> V_145 , 0 ,
V_192 ) ;
if ( ! V_186 )
goto V_189;
if ( F_91 ( V_170 , V_72 , V_20 ) )
goto V_149;
F_93 ( V_170 , V_186 ) ;
V_18 = F_99 ( V_93 , V_170 , F_87 ( V_47 ) . V_78 , V_180 ) ;
if ( V_18 < 0 )
return V_18 ;
return 0 ;
V_149:
F_105 ( V_170 , V_186 ) ;
V_189:
F_106 ( V_170 ) ;
return - V_147 ;
}
static int
F_109 ( struct V_92 * V_193 , int V_194 , void T_6 * V_195 , int * V_155 )
{
unsigned int * V_196 ;
void * V_197 ;
int V_198 = * V_155 , V_18 = 0 ;
if ( ! F_110 ( V_199 ) )
return - V_200 ;
if ( V_194 != V_201 )
return - V_202 ;
if ( * V_155 < sizeof( unsigned int ) )
return - V_21 ;
V_197 = F_111 ( * V_155 ) ;
if ( ! V_197 )
return - V_104 ;
if ( F_112 ( V_197 , V_195 , * V_155 ) != 0 ) {
V_18 = - V_14 ;
goto V_159;
}
V_196 = ( unsigned int * ) V_197 ;
if ( * V_196 < V_203 ) {
struct V_204 * V_205 = V_197 ;
if ( V_205 -> V_87 != V_20 ) {
V_18 = - V_206 ;
goto V_159;
}
}
switch ( * V_196 ) {
case V_203 : {
struct V_204 * V_205 = V_197 ;
if ( * V_155 != sizeof( struct V_204 ) ) {
V_18 = - V_21 ;
goto V_159;
}
V_205 -> V_87 = V_20 ;
V_18 = F_113 ( V_195 , V_205 ,
sizeof( struct V_204 ) ) ;
goto V_159;
}
case V_207 : {
struct V_208 * V_209 = V_197 ;
if ( * V_155 != sizeof( struct V_208 ) ) {
V_18 = - V_21 ;
goto V_159;
}
V_209 -> V_53 . V_3 [ V_105 - 1 ] = '\0' ;
F_13 () ;
V_209 -> V_53 . V_42 = F_62 ( V_209 -> V_53 . V_3 ) ;
F_9 () ;
goto V_210;
}
case V_211 : {
struct V_208 * V_209 = V_197 ;
if ( * V_155 != sizeof( struct V_208 ) ||
V_209 -> V_53 . V_42 >= V_71 ) {
V_18 = - V_21 ;
goto V_159;
}
F_13 () ;
strncpy ( V_209 -> V_53 . V_3 ,
V_44 [ V_209 -> V_53 . V_42 ]
? V_44 [ V_209 -> V_53 . V_42 ] -> V_3 : L_29 ,
V_105 ) ;
F_9 () ;
goto V_210;
}
default:
V_18 = - V_212 ;
goto V_159;
}
V_210:
V_18 = F_113 ( V_195 , V_197 , V_198 ) ;
V_159:
F_30 ( V_197 ) ;
if ( V_18 > 0 )
V_18 = 0 ;
return V_18 ;
}
static int T_7
F_114 ( void )
{
int V_18 ;
if ( V_213 )
V_71 = V_213 ;
if ( V_71 >= V_69 )
V_71 = V_69 - 1 ;
V_44 = F_26 ( sizeof( struct V_52 * ) * V_71 ,
V_27 ) ;
if ( ! V_44 )
return - V_104 ;
V_18 = F_115 ( & V_214 ) ;
if ( V_18 != 0 ) {
F_116 ( L_30 ) ;
F_31 ( V_44 ) ;
return V_18 ;
}
V_18 = F_117 ( & V_215 ) ;
if ( V_18 != 0 ) {
F_116 ( L_31 , V_18 ) ;
F_118 ( & V_214 ) ;
F_31 ( V_44 ) ;
return V_18 ;
}
F_119 ( L_32 , V_20 ) ;
return 0 ;
}
static void T_8
F_120 ( void )
{
F_121 ( & V_215 ) ;
F_118 ( & V_214 ) ;
F_31 ( V_44 ) ;
F_10 ( L_33 ) ;
}
