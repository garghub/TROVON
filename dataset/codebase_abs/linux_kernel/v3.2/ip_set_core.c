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
static int
F_8 ( const char * V_3 )
{
F_9 () ;
F_10 ( L_1 , V_3 ) ;
if ( F_11 ( L_2 , V_3 ) < 0 ) {
F_12 ( L_3 , V_3 ) ;
F_13 () ;
return - V_9 ;
}
F_13 () ;
return - V_10 ;
}
static int
F_14 ( const char * V_3 , T_1 V_4 , T_1 V_5 ,
struct V_2 * * V_11 )
{
struct V_2 * type ;
int V_12 ;
F_15 () ;
* V_11 = F_5 ( V_3 , V_4 , V_5 ) ;
if ( * V_11 ) {
V_12 = ! F_16 ( ( * V_11 ) -> V_13 ) ? - V_14 : 0 ;
goto V_15;
}
F_6 (type, &ip_set_type_list, list)
if ( F_7 ( type -> V_3 , V_3 ) ) {
V_12 = - V_9 ;
goto V_15;
}
F_17 () ;
return F_8 ( V_3 ) ;
V_15:
F_17 () ;
return V_12 ;
}
static int
F_18 ( const char * V_3 , T_1 V_4 , T_1 * V_16 , T_1 * V_17 )
{
struct V_2 * type ;
bool V_11 = false ;
* V_16 = 255 ; * V_17 = 0 ;
F_15 () ;
F_6 (type, &ip_set_type_list, list)
if ( F_7 ( type -> V_3 , V_3 ) &&
( type -> V_4 == V_4 || type -> V_4 == V_6 ) ) {
V_11 = true ;
if ( type -> V_7 < * V_16 )
* V_16 = type -> V_7 ;
if ( type -> V_8 > * V_17 )
* V_17 = type -> V_8 ;
}
F_17 () ;
if ( V_11 )
return 0 ;
return F_8 ( V_3 ) ;
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
if ( V_18 == - V_10 ) {
F_10 ( L_17 ) ;
F_41 ( & V_53 -> V_56 ) ;
V_53 -> V_57 -> V_58 ( V_53 , V_47 , V_49 , V_60 , V_51 ) ;
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
V_18 = V_53 -> V_57 -> V_58 ( V_53 , V_47 , V_49 , V_60 , V_51 ) ;
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
V_18 = V_53 -> V_57 -> V_58 ( V_53 , V_47 , V_49 , V_61 , V_51 ) ;
F_42 ( & V_53 -> V_56 ) ;
return V_18 ;
}
T_4
F_50 ( const char * V_3 , struct V_52 * * V_53 )
{
T_4 V_62 , V_42 = V_63 ;
struct V_52 * V_64 ;
for ( V_62 = 0 ; V_62 < V_65 ; V_62 ++ ) {
V_64 = V_44 [ V_62 ] ;
if ( V_64 != NULL && F_7 ( V_64 -> V_3 , V_3 ) ) {
F_40 ( V_62 ) ;
V_42 = V_62 ;
* V_53 = V_64 ;
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
struct V_52 * V_64 ;
T_4 V_42 ;
F_13 () ;
V_42 = F_50 ( V_3 , & V_64 ) ;
F_9 () ;
return V_42 ;
}
T_4
F_54 ( T_4 V_42 )
{
if ( V_42 > V_65 )
return V_63 ;
F_13 () ;
if ( V_44 [ V_42 ] )
F_40 ( V_42 ) ;
else
V_42 = V_63 ;
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
return ! V_34 [ V_66 ] ||
F_57 ( V_34 [ V_66 ] ) != V_20 ;
}
static inline T_5
F_58 ( const struct V_67 * V_68 )
{
return V_68 -> V_69 & V_70 ? 0 : V_71 ;
}
static struct V_67 *
F_59 ( struct V_46 * V_47 , T_5 V_72 , T_5 V_73 , unsigned int V_74 ,
enum V_75 V_76 )
{
struct V_67 * V_68 ;
struct V_77 * V_78 ;
V_68 = F_60 ( V_47 , V_72 , V_73 , V_76 | ( V_79 << 8 ) ,
sizeof( * V_78 ) , V_74 ) ;
if ( V_68 == NULL )
return NULL ;
V_78 = F_61 ( V_68 ) ;
V_78 -> V_80 = V_81 ;
V_78 -> V_82 = V_83 ;
V_78 -> V_84 = 0 ;
return V_68 ;
}
static T_4
F_62 ( const char * V_3 )
{
T_4 V_62 , V_42 = V_63 ;
const struct V_52 * V_53 ;
for ( V_62 = 0 ; V_42 == V_63 && V_62 < V_65 ; V_62 ++ ) {
V_53 = V_44 [ V_62 ] ;
if ( V_53 != NULL && F_7 ( V_53 -> V_3 , V_3 ) )
V_42 = V_62 ;
}
return V_42 ;
}
static inline struct V_52 *
F_63 ( const char * V_3 )
{
T_4 V_42 = F_62 ( V_3 ) ;
return V_42 == V_63 ? NULL : V_44 [ V_42 ] ;
}
static int
F_64 ( const char * V_3 , T_4 * V_42 , struct V_52 * * V_53 )
{
T_4 V_62 ;
* V_42 = V_63 ;
for ( V_62 = 0 ; V_62 < V_65 ; V_62 ++ ) {
if ( V_44 [ V_62 ] == NULL ) {
if ( * V_42 == V_63 )
* V_42 = V_62 ;
} else if ( F_7 ( V_3 , V_44 [ V_62 ] -> V_3 ) ) {
* V_53 = V_44 [ V_62 ] ;
return - V_85 ;
}
}
if ( * V_42 == V_63 )
return - V_86 ;
return 0 ;
}
static int
F_65 ( struct V_87 * V_88 , struct V_46 * V_47 ,
const struct V_67 * V_68 ,
const struct V_29 * const V_89 [] )
{
struct V_52 * V_53 , * V_90 = NULL ;
T_4 V_42 = V_63 ;
struct V_29 * V_34 [ V_91 + 1 ] = {} ;
const char * V_3 , * V_92 ;
T_1 V_4 , V_5 ;
T_5 V_74 = F_58 ( V_68 ) ;
int V_18 = 0 ;
if ( F_34 ( F_56 ( V_89 ) ||
V_89 [ V_93 ] == NULL ||
V_89 [ V_94 ] == NULL ||
V_89 [ V_95 ] == NULL ||
V_89 [ V_96 ] == NULL ||
( V_89 [ V_97 ] != NULL &&
! F_32 ( V_89 [ V_97 ] ) ) ) )
return - V_36 ;
V_3 = F_39 ( V_89 [ V_93 ] ) ;
V_92 = F_39 ( V_89 [ V_94 ] ) ;
V_4 = F_57 ( V_89 [ V_96 ] ) ;
V_5 = F_57 ( V_89 [ V_95 ] ) ;
F_10 ( L_18 ,
V_3 , V_92 , F_20 ( V_4 ) , V_5 ) ;
V_53 = F_26 ( sizeof( struct V_52 ) , V_27 ) ;
if ( ! V_53 )
return - V_98 ;
F_66 ( & V_53 -> V_56 ) ;
F_67 ( V_53 -> V_3 , V_3 , V_99 ) ;
V_53 -> V_4 = V_4 ;
V_53 -> V_5 = V_5 ;
V_18 = F_14 ( V_92 , V_4 , V_5 , & ( V_53 -> type ) ) ;
if ( V_18 )
goto V_100;
if ( V_89 [ V_97 ] &&
F_35 ( V_34 , V_91 , V_89 [ V_97 ] ,
V_53 -> type -> V_101 ) ) {
V_18 = - V_36 ;
goto V_102;
}
V_18 = V_53 -> type -> V_103 ( V_53 , V_34 , V_74 ) ;
if ( V_18 != 0 )
goto V_102;
if ( ( V_18 = F_64 ( V_53 -> V_3 , & V_42 , & V_90 ) ) != 0 ) {
if ( V_18 == - V_85 &&
( V_74 & V_71 ) &&
F_7 ( V_53 -> type -> V_3 , V_90 -> type -> V_3 ) &&
V_53 -> type -> V_4 == V_90 -> type -> V_4 &&
V_53 -> type -> V_7 == V_90 -> type -> V_7 &&
V_53 -> type -> V_8 == V_90 -> type -> V_8 &&
V_53 -> V_57 -> V_104 ( V_53 , V_90 ) )
V_18 = 0 ;
goto V_105;
}
F_10 ( L_19 , V_53 -> V_3 , V_42 ) ;
V_44 [ V_42 ] = V_53 ;
return V_18 ;
V_105:
V_53 -> V_57 -> V_106 ( V_53 ) ;
V_102:
F_68 ( V_53 -> type -> V_13 ) ;
V_100:
F_31 ( V_53 ) ;
return V_18 ;
}
static void
F_69 ( T_4 V_42 )
{
struct V_52 * V_53 = V_44 [ V_42 ] ;
F_10 ( L_20 , V_53 -> V_3 ) ;
V_44 [ V_42 ] = NULL ;
V_53 -> V_57 -> V_106 ( V_53 ) ;
F_68 ( V_53 -> type -> V_13 ) ;
F_31 ( V_53 ) ;
}
static int
F_70 ( struct V_87 * V_88 , struct V_46 * V_47 ,
const struct V_67 * V_68 ,
const struct V_29 * const V_89 [] )
{
T_4 V_62 ;
int V_18 = 0 ;
if ( F_34 ( F_56 ( V_89 ) ) )
return - V_36 ;
F_46 ( & V_43 ) ;
if ( ! V_89 [ V_93 ] ) {
for ( V_62 = 0 ; V_62 < V_65 ; V_62 ++ ) {
if ( V_44 [ V_62 ] != NULL && V_44 [ V_62 ] -> V_45 ) {
V_18 = - V_107 ;
goto V_100;
}
}
F_47 ( & V_43 ) ;
for ( V_62 = 0 ; V_62 < V_65 ; V_62 ++ ) {
if ( V_44 [ V_62 ] != NULL )
F_69 ( V_62 ) ;
}
} else {
V_62 = F_62 ( F_39 ( V_89 [ V_93 ] ) ) ;
if ( V_62 == V_63 ) {
V_18 = - V_108 ;
goto V_100;
} else if ( V_44 [ V_62 ] -> V_45 ) {
V_18 = - V_107 ;
goto V_100;
}
F_47 ( & V_43 ) ;
F_69 ( V_62 ) ;
}
return 0 ;
V_100:
F_47 ( & V_43 ) ;
return V_18 ;
}
static void
F_71 ( struct V_52 * V_53 )
{
F_10 ( L_20 , V_53 -> V_3 ) ;
F_41 ( & V_53 -> V_56 ) ;
V_53 -> V_57 -> V_109 ( V_53 ) ;
F_42 ( & V_53 -> V_56 ) ;
}
static int
F_72 ( struct V_87 * V_88 , struct V_46 * V_47 ,
const struct V_67 * V_68 ,
const struct V_29 * const V_89 [] )
{
T_4 V_62 ;
if ( F_34 ( F_56 ( V_89 ) ) )
return - V_36 ;
if ( ! V_89 [ V_93 ] ) {
for ( V_62 = 0 ; V_62 < V_65 ; V_62 ++ )
if ( V_44 [ V_62 ] != NULL )
F_71 ( V_44 [ V_62 ] ) ;
} else {
V_62 = F_62 ( F_39 ( V_89 [ V_93 ] ) ) ;
if ( V_62 == V_63 )
return - V_108 ;
F_71 ( V_44 [ V_62 ] ) ;
}
return 0 ;
}
static int
F_73 ( struct V_87 * V_88 , struct V_46 * V_47 ,
const struct V_67 * V_68 ,
const struct V_29 * const V_89 [] )
{
struct V_52 * V_53 ;
const char * V_110 ;
T_4 V_62 ;
int V_18 = 0 ;
if ( F_34 ( F_56 ( V_89 ) ||
V_89 [ V_93 ] == NULL ||
V_89 [ V_111 ] == NULL ) )
return - V_36 ;
V_53 = F_63 ( F_39 ( V_89 [ V_93 ] ) ) ;
if ( V_53 == NULL )
return - V_108 ;
F_46 ( & V_43 ) ;
if ( V_53 -> V_45 != 0 ) {
V_18 = - V_112 ;
goto V_100;
}
V_110 = F_39 ( V_89 [ V_111 ] ) ;
for ( V_62 = 0 ; V_62 < V_65 ; V_62 ++ ) {
if ( V_44 [ V_62 ] != NULL &&
F_7 ( V_44 [ V_62 ] -> V_3 , V_110 ) ) {
V_18 = - V_113 ;
goto V_100;
}
}
strncpy ( V_53 -> V_3 , V_110 , V_99 ) ;
V_100:
F_47 ( & V_43 ) ;
return V_18 ;
}
static int
F_74 ( struct V_87 * V_88 , struct V_46 * V_47 ,
const struct V_67 * V_68 ,
const struct V_29 * const V_89 [] )
{
struct V_52 * V_114 , * V_115 ;
T_4 V_116 , V_117 ;
char V_118 [ V_99 ] ;
if ( F_34 ( F_56 ( V_89 ) ||
V_89 [ V_93 ] == NULL ||
V_89 [ V_111 ] == NULL ) )
return - V_36 ;
V_116 = F_62 ( F_39 ( V_89 [ V_93 ] ) ) ;
if ( V_116 == V_63 )
return - V_108 ;
V_117 = F_62 ( F_39 ( V_89 [ V_111 ] ) ) ;
if ( V_117 == V_63 )
return - V_113 ;
V_114 = V_44 [ V_116 ] ;
V_115 = V_44 [ V_117 ] ;
if ( ! ( V_114 -> type -> V_119 == V_115 -> type -> V_119 &&
V_114 -> type -> V_4 == V_115 -> type -> V_4 ) )
return - V_120 ;
strncpy ( V_118 , V_114 -> V_3 , V_99 ) ;
strncpy ( V_114 -> V_3 , V_115 -> V_3 , V_99 ) ;
strncpy ( V_115 -> V_3 , V_118 , V_99 ) ;
F_41 ( & V_43 ) ;
F_75 ( V_114 -> V_45 , V_115 -> V_45 ) ;
V_44 [ V_116 ] = V_115 ;
V_44 [ V_117 ] = V_114 ;
F_42 ( & V_43 ) ;
return 0 ;
}
static int
F_76 ( struct V_121 * V_122 )
{
if ( V_122 -> args [ 2 ] ) {
F_10 ( L_21 , V_44 [ V_122 -> args [ 1 ] ] -> V_3 ) ;
F_51 ( ( T_4 ) V_122 -> args [ 1 ] ) ;
}
return 0 ;
}
static inline void
F_77 ( struct V_67 * V_68 )
{
const struct V_29 * V_89 ;
int V_123 ;
F_10 ( L_22 ) ;
F_78 (attr, nlh, sizeof(struct nfgenmsg), rem) {
F_10 ( L_23 , V_31 ( V_89 ) , V_89 -> V_124 ) ;
}
}
static int
F_79 ( struct V_121 * V_122 )
{
struct V_67 * V_68 = F_80 ( V_122 -> V_47 ) ;
int V_125 = F_81 ( sizeof( struct V_77 ) ) ;
struct V_29 * V_126 [ V_127 + 1 ] ;
struct V_29 * V_89 = ( void * ) V_68 + V_125 ;
T_5 V_128 ;
T_4 V_42 ;
F_82 ( V_126 , V_127 ,
V_89 , V_68 -> V_129 - V_125 , V_130 ) ;
if ( V_126 [ V_93 ] ) {
V_42 = F_62 ( F_39 ( V_126 [ V_93 ] ) ) ;
if ( V_42 == V_63 )
return - V_108 ;
V_128 = V_131 ;
V_122 -> args [ 1 ] = V_42 ;
} else
V_128 = V_132 ;
if ( V_126 [ V_133 ] ) {
T_5 V_134 = F_83 ( V_126 [ V_133 ] ) ;
V_128 |= ( V_134 << 16 ) ;
}
V_122 -> args [ 0 ] = V_128 ;
return 0 ;
}
static int
F_84 ( struct V_46 * V_47 , struct V_121 * V_122 )
{
T_4 V_42 = V_63 , V_17 ;
struct V_52 * V_53 = NULL ;
struct V_67 * V_68 = NULL ;
unsigned int V_74 = F_85 ( V_122 -> V_47 ) . V_72 ? V_135 : 0 ;
T_5 V_128 , V_136 ;
int V_18 = 0 ;
if ( ! V_122 -> args [ 0 ] ) {
V_18 = F_79 ( V_122 ) ;
if ( V_18 < 0 ) {
V_68 = F_80 ( V_122 -> V_47 ) ;
if ( V_68 -> V_69 & V_137 )
F_86 ( V_122 -> V_47 , V_68 , V_18 ) ;
return V_18 ;
}
}
if ( V_122 -> args [ 1 ] >= V_65 )
goto V_100;
V_128 = F_87 ( V_122 -> args [ 0 ] ) ;
V_136 = F_88 ( V_122 -> args [ 0 ] ) ;
V_17 = V_128 == V_131 ? V_122 -> args [ 1 ] + 1 : V_65 ;
V_138:
F_10 ( L_24 ,
V_128 , V_136 , V_122 -> args [ 1 ] ) ;
for (; V_122 -> args [ 1 ] < V_17 ; V_122 -> args [ 1 ] ++ ) {
V_42 = ( T_4 ) V_122 -> args [ 1 ] ;
V_53 = V_44 [ V_42 ] ;
if ( V_53 == NULL ) {
if ( V_128 == V_131 ) {
V_18 = - V_108 ;
goto V_100;
}
continue;
}
if ( V_128 != V_131 &&
( ( V_128 == V_132 ) ==
! ! ( V_53 -> type -> V_119 & V_139 ) ) )
continue;
F_10 ( L_25 , V_53 -> V_3 ) ;
if ( ! V_122 -> args [ 2 ] ) {
F_10 ( L_26 ) ;
F_40 ( V_42 ) ;
}
V_68 = F_59 ( V_47 , F_85 ( V_122 -> V_47 ) . V_72 ,
V_122 -> V_68 -> V_140 , V_74 ,
V_141 ) ;
if ( ! V_68 ) {
V_18 = - V_142 ;
goto V_143;
}
F_89 ( V_47 , V_66 , V_20 ) ;
F_90 ( V_47 , V_93 , V_53 -> V_3 ) ;
if ( V_136 & V_144 )
goto V_145;
switch ( V_122 -> args [ 2 ] ) {
case 0 :
F_90 ( V_47 , V_94 ,
V_53 -> type -> V_3 ) ;
F_89 ( V_47 , V_96 ,
V_53 -> V_4 ) ;
F_89 ( V_47 , V_95 ,
V_53 -> V_5 ) ;
V_18 = V_53 -> V_57 -> V_146 ( V_53 , V_47 ) ;
if ( V_18 < 0 )
goto V_143;
if ( V_136 & V_147 )
goto V_145;
default:
F_46 ( & V_53 -> V_56 ) ;
V_18 = V_53 -> V_57 -> V_22 ( V_53 , V_47 , V_122 ) ;
F_47 ( & V_53 -> V_56 ) ;
if ( ! V_122 -> args [ 2 ] )
goto V_145;
goto V_143;
}
}
if ( V_128 == V_132 ) {
V_128 = V_148 ;
V_122 -> args [ 0 ] = V_128 | ( V_136 << 16 ) ;
V_122 -> args [ 1 ] = 0 ;
goto V_138;
}
goto V_100;
V_149:
V_18 = - V_14 ;
V_145:
if ( V_128 == V_131 )
V_122 -> args [ 1 ] = V_63 ;
else
V_122 -> args [ 1 ] ++ ;
V_143:
if ( V_18 || ! V_122 -> args [ 2 ] ) {
F_10 ( L_21 , V_44 [ V_42 ] -> V_3 ) ;
F_51 ( V_42 ) ;
}
V_100:
if ( V_68 ) {
F_91 ( V_47 , V_68 ) ;
F_10 ( L_27 , V_68 -> V_129 ) ;
F_77 ( V_68 ) ;
}
return V_18 < 0 ? V_18 : V_47 -> V_150 ;
}
static int
F_92 ( struct V_87 * V_88 , struct V_46 * V_47 ,
const struct V_67 * V_68 ,
const struct V_29 * const V_89 [] )
{
if ( F_34 ( F_56 ( V_89 ) ) )
return - V_36 ;
return F_93 ( V_88 , V_47 , V_68 ,
F_84 ,
F_76 , 0 ) ;
}
static int
F_94 ( struct V_87 * V_88 , struct V_46 * V_47 , struct V_52 * V_53 ,
struct V_29 * V_34 [] , enum V_151 V_152 ,
T_5 V_74 , bool V_153 )
{
int V_18 ;
T_5 V_154 = 0 ;
bool V_155 = V_74 & V_71 , V_156 = false ;
do {
F_41 ( & V_53 -> V_56 ) ;
V_18 = V_53 -> V_57 -> V_157 ( V_53 , V_34 , V_152 , & V_154 , V_74 , V_156 ) ;
F_42 ( & V_53 -> V_56 ) ;
V_156 = true ;
} while ( V_18 == - V_10 &&
V_53 -> V_57 -> V_158 &&
( V_18 = V_53 -> V_57 -> V_158 ( V_53 , V_156 ) ) == 0 );
if ( ! V_18 || ( V_18 == - V_159 && V_155 ) )
return 0 ;
if ( V_154 && V_153 ) {
struct V_67 * V_160 , * V_68 = F_80 ( V_47 ) ;
struct V_46 * V_161 ;
struct V_162 * V_163 ;
T_2 V_164 = sizeof( * V_163 ) + V_129 ( V_68 ) ;
int V_125 = F_81 ( sizeof( struct V_77 ) ) ;
struct V_29 * V_126 [ V_127 + 1 ] ;
struct V_29 * V_165 ;
T_5 * V_166 ;
V_161 = F_95 ( V_164 , V_27 ) ;
if ( V_161 == NULL )
return - V_98 ;
V_160 = F_96 ( V_161 , F_85 ( V_47 ) . V_72 ,
V_68 -> V_140 , V_167 , V_164 , 0 ) ;
V_163 = F_61 ( V_160 ) ;
V_163 -> error = V_18 ;
memcpy ( & V_163 -> V_168 , V_68 , V_68 -> V_129 ) ;
V_165 = ( void * ) & V_163 -> V_168 + V_125 ;
F_82 ( V_126 , V_127 ,
V_165 , V_68 -> V_129 - V_125 ,
V_169 ) ;
V_166 = F_39 ( V_126 [ V_170 ] ) ;
* V_166 = V_154 ;
F_97 ( V_88 , V_161 , F_85 ( V_47 ) . V_72 , V_171 ) ;
return - V_172 ;
}
return V_18 ;
}
static int
F_98 ( struct V_87 * V_88 , struct V_46 * V_47 ,
const struct V_67 * V_68 ,
const struct V_29 * const V_89 [] )
{
struct V_52 * V_53 ;
struct V_29 * V_34 [ V_173 + 1 ] = {} ;
const struct V_29 * V_30 ;
T_5 V_74 = F_58 ( V_68 ) ;
bool V_153 ;
int V_18 = 0 ;
if ( F_34 ( F_56 ( V_89 ) ||
V_89 [ V_93 ] == NULL ||
! ( ( V_89 [ V_97 ] != NULL ) ^
( V_89 [ V_174 ] != NULL ) ) ||
( V_89 [ V_97 ] != NULL &&
! F_32 ( V_89 [ V_97 ] ) ) ||
( V_89 [ V_174 ] != NULL &&
( ! F_32 ( V_89 [ V_174 ] ) ||
V_89 [ V_170 ] == NULL ) ) ) )
return - V_36 ;
V_53 = F_63 ( F_39 ( V_89 [ V_93 ] ) ) ;
if ( V_53 == NULL )
return - V_108 ;
V_153 = ! ! V_89 [ V_170 ] ;
if ( V_89 [ V_97 ] ) {
if ( F_35 ( V_34 , V_173 ,
V_89 [ V_97 ] ,
V_53 -> type -> V_175 ) )
return - V_36 ;
V_18 = F_94 ( V_88 , V_47 , V_53 , V_34 , V_60 , V_74 ,
V_153 ) ;
} else {
int V_176 ;
F_99 (nla, attr[IPSET_ATTR_ADT], nla_rem) {
memset ( V_34 , 0 , sizeof( V_34 ) ) ;
if ( V_31 ( V_30 ) != V_97 ||
! F_32 ( V_30 ) ||
F_35 ( V_34 , V_173 , V_30 ,
V_53 -> type -> V_175 ) )
return - V_36 ;
V_18 = F_94 ( V_88 , V_47 , V_53 , V_34 , V_60 ,
V_74 , V_153 ) ;
if ( V_18 < 0 )
return V_18 ;
}
}
return V_18 ;
}
static int
F_100 ( struct V_87 * V_88 , struct V_46 * V_47 ,
const struct V_67 * V_68 ,
const struct V_29 * const V_89 [] )
{
struct V_52 * V_53 ;
struct V_29 * V_34 [ V_173 + 1 ] = {} ;
const struct V_29 * V_30 ;
T_5 V_74 = F_58 ( V_68 ) ;
bool V_153 ;
int V_18 = 0 ;
if ( F_34 ( F_56 ( V_89 ) ||
V_89 [ V_93 ] == NULL ||
! ( ( V_89 [ V_97 ] != NULL ) ^
( V_89 [ V_174 ] != NULL ) ) ||
( V_89 [ V_97 ] != NULL &&
! F_32 ( V_89 [ V_97 ] ) ) ||
( V_89 [ V_174 ] != NULL &&
( ! F_32 ( V_89 [ V_174 ] ) ||
V_89 [ V_170 ] == NULL ) ) ) )
return - V_36 ;
V_53 = F_63 ( F_39 ( V_89 [ V_93 ] ) ) ;
if ( V_53 == NULL )
return - V_108 ;
V_153 = ! ! V_89 [ V_170 ] ;
if ( V_89 [ V_97 ] ) {
if ( F_35 ( V_34 , V_173 ,
V_89 [ V_97 ] ,
V_53 -> type -> V_175 ) )
return - V_36 ;
V_18 = F_94 ( V_88 , V_47 , V_53 , V_34 , V_61 , V_74 ,
V_153 ) ;
} else {
int V_176 ;
F_99 (nla, attr[IPSET_ATTR_ADT], nla_rem) {
memset ( V_34 , 0 , sizeof( * V_34 ) ) ;
if ( V_31 ( V_30 ) != V_97 ||
! F_32 ( V_30 ) ||
F_35 ( V_34 , V_173 , V_30 ,
V_53 -> type -> V_175 ) )
return - V_36 ;
V_18 = F_94 ( V_88 , V_47 , V_53 , V_34 , V_61 ,
V_74 , V_153 ) ;
if ( V_18 < 0 )
return V_18 ;
}
}
return V_18 ;
}
static int
F_101 ( struct V_87 * V_88 , struct V_46 * V_47 ,
const struct V_67 * V_68 ,
const struct V_29 * const V_89 [] )
{
struct V_52 * V_53 ;
struct V_29 * V_34 [ V_173 + 1 ] = {} ;
int V_18 = 0 ;
if ( F_34 ( F_56 ( V_89 ) ||
V_89 [ V_93 ] == NULL ||
V_89 [ V_97 ] == NULL ||
! F_32 ( V_89 [ V_97 ] ) ) )
return - V_36 ;
V_53 = F_63 ( F_39 ( V_89 [ V_93 ] ) ) ;
if ( V_53 == NULL )
return - V_108 ;
if ( F_35 ( V_34 , V_173 , V_89 [ V_97 ] ,
V_53 -> type -> V_175 ) )
return - V_36 ;
F_46 ( & V_53 -> V_56 ) ;
V_18 = V_53 -> V_57 -> V_157 ( V_53 , V_34 , V_59 , NULL , 0 , 0 ) ;
F_47 ( & V_53 -> V_56 ) ;
if ( V_18 == - V_10 )
V_18 = 1 ;
return V_18 < 0 ? V_18 : V_18 > 0 ? 0 : - V_159 ;
}
static int
F_102 ( struct V_87 * V_88 , struct V_46 * V_47 ,
const struct V_67 * V_68 ,
const struct V_29 * const V_89 [] )
{
const struct V_52 * V_53 ;
struct V_46 * V_161 ;
struct V_67 * V_177 ;
T_4 V_42 ;
int V_18 = 0 ;
if ( F_34 ( F_56 ( V_89 ) ||
V_89 [ V_93 ] == NULL ) )
return - V_36 ;
V_42 = F_62 ( F_39 ( V_89 [ V_93 ] ) ) ;
if ( V_42 == V_63 )
return - V_108 ;
V_53 = V_44 [ V_42 ] ;
V_161 = F_95 ( V_178 , V_27 ) ;
if ( V_161 == NULL )
return - V_98 ;
V_177 = F_59 ( V_161 , F_85 ( V_47 ) . V_72 , V_68 -> V_140 , 0 ,
V_179 ) ;
if ( ! V_177 )
goto V_180;
F_89 ( V_161 , V_66 , V_20 ) ;
F_90 ( V_161 , V_93 , V_53 -> V_3 ) ;
F_90 ( V_161 , V_94 , V_53 -> type -> V_3 ) ;
F_89 ( V_161 , V_96 , V_53 -> V_4 ) ;
F_89 ( V_161 , V_95 , V_53 -> V_5 ) ;
F_91 ( V_161 , V_177 ) ;
V_18 = F_97 ( V_88 , V_161 , F_85 ( V_47 ) . V_72 , V_171 ) ;
if ( V_18 < 0 )
return V_18 ;
return 0 ;
V_149:
F_103 ( V_161 , V_177 ) ;
V_180:
F_104 ( V_161 ) ;
return - V_142 ;
}
static int
V_2 ( struct V_87 * V_88 , struct V_46 * V_47 ,
const struct V_67 * V_68 ,
const struct V_29 * const V_89 [] )
{
struct V_46 * V_161 ;
struct V_67 * V_177 ;
T_1 V_4 , V_16 , V_17 ;
const char * V_92 ;
int V_18 = 0 ;
if ( F_34 ( F_56 ( V_89 ) ||
V_89 [ V_94 ] == NULL ||
V_89 [ V_96 ] == NULL ) )
return - V_36 ;
V_4 = F_57 ( V_89 [ V_96 ] ) ;
V_92 = F_39 ( V_89 [ V_94 ] ) ;
V_18 = F_18 ( V_92 , V_4 , & V_16 , & V_17 ) ;
if ( V_18 )
return V_18 ;
V_161 = F_95 ( V_178 , V_27 ) ;
if ( V_161 == NULL )
return - V_98 ;
V_177 = F_59 ( V_161 , F_85 ( V_47 ) . V_72 , V_68 -> V_140 , 0 ,
V_181 ) ;
if ( ! V_177 )
goto V_180;
F_89 ( V_161 , V_66 , V_20 ) ;
F_90 ( V_161 , V_94 , V_92 ) ;
F_89 ( V_161 , V_96 , V_4 ) ;
F_89 ( V_161 , V_95 , V_17 ) ;
F_89 ( V_161 , V_182 , V_16 ) ;
F_91 ( V_161 , V_177 ) ;
F_10 ( L_28 , V_177 -> V_129 ) ;
V_18 = F_97 ( V_88 , V_161 , F_85 ( V_47 ) . V_72 , V_171 ) ;
if ( V_18 < 0 )
return V_18 ;
return 0 ;
V_149:
F_103 ( V_161 , V_177 ) ;
V_180:
F_104 ( V_161 ) ;
return - V_142 ;
}
static int
F_105 ( struct V_87 * V_88 , struct V_46 * V_47 ,
const struct V_67 * V_68 ,
const struct V_29 * const V_89 [] )
{
struct V_46 * V_161 ;
struct V_67 * V_177 ;
int V_18 = 0 ;
if ( F_34 ( V_89 [ V_66 ] == NULL ) )
return - V_36 ;
V_161 = F_95 ( V_178 , V_27 ) ;
if ( V_161 == NULL )
return - V_98 ;
V_177 = F_59 ( V_161 , F_85 ( V_47 ) . V_72 , V_68 -> V_140 , 0 ,
V_183 ) ;
if ( ! V_177 )
goto V_180;
F_89 ( V_161 , V_66 , V_20 ) ;
F_91 ( V_161 , V_177 ) ;
V_18 = F_97 ( V_88 , V_161 , F_85 ( V_47 ) . V_72 , V_171 ) ;
if ( V_18 < 0 )
return V_18 ;
return 0 ;
V_149:
F_103 ( V_161 , V_177 ) ;
V_180:
F_104 ( V_161 ) ;
return - V_142 ;
}
static int
F_106 ( struct V_87 * V_184 , int V_185 , void T_6 * V_186 , int * V_150 )
{
unsigned * V_187 ;
void * V_188 ;
int V_189 = * V_150 , V_18 = 0 ;
if ( ! F_107 ( V_190 ) )
return - V_191 ;
if ( V_185 != V_192 )
return - V_193 ;
if ( * V_150 < sizeof( unsigned ) )
return - V_21 ;
V_188 = F_108 ( * V_150 ) ;
if ( ! V_188 )
return - V_98 ;
if ( F_109 ( V_188 , V_186 , * V_150 ) != 0 ) {
V_18 = - V_14 ;
goto V_194;
}
V_187 = ( unsigned * ) V_188 ;
if ( * V_187 < V_195 ) {
struct V_196 * V_197 = V_188 ;
if ( V_197 -> V_82 != V_20 ) {
V_18 = - V_198 ;
goto V_194;
}
}
switch ( * V_187 ) {
case V_195 : {
struct V_196 * V_197 = V_188 ;
if ( * V_150 != sizeof( struct V_196 ) ) {
V_18 = - V_21 ;
goto V_194;
}
V_197 -> V_82 = V_20 ;
V_18 = F_110 ( V_186 , V_197 ,
sizeof( struct V_196 ) ) ;
goto V_194;
}
case V_199 : {
struct V_200 * V_201 = V_188 ;
if ( * V_150 != sizeof( struct V_200 ) ) {
V_18 = - V_21 ;
goto V_194;
}
V_201 -> V_53 . V_3 [ V_99 - 1 ] = '\0' ;
F_13 () ;
V_201 -> V_53 . V_42 = F_62 ( V_201 -> V_53 . V_3 ) ;
F_9 () ;
goto V_202;
}
case V_203 : {
struct V_200 * V_201 = V_188 ;
if ( * V_150 != sizeof( struct V_200 ) ||
V_201 -> V_53 . V_42 >= V_65 ) {
V_18 = - V_21 ;
goto V_194;
}
F_13 () ;
strncpy ( V_201 -> V_53 . V_3 ,
V_44 [ V_201 -> V_53 . V_42 ]
? V_44 [ V_201 -> V_53 . V_42 ] -> V_3 : L_29 ,
V_99 ) ;
F_9 () ;
goto V_202;
}
default:
V_18 = - V_204 ;
goto V_194;
}
V_202:
V_18 = F_110 ( V_186 , V_188 , V_189 ) ;
V_194:
F_30 ( V_188 ) ;
if ( V_18 > 0 )
V_18 = 0 ;
return V_18 ;
}
static int T_7
F_111 ( void )
{
int V_18 ;
if ( V_205 )
V_65 = V_205 ;
if ( V_65 >= V_63 )
V_65 = V_63 - 1 ;
V_44 = F_26 ( sizeof( struct V_52 * ) * V_65 ,
V_27 ) ;
if ( ! V_44 )
return - V_98 ;
V_18 = F_112 ( & V_206 ) ;
if ( V_18 != 0 ) {
F_113 ( L_30 ) ;
F_31 ( V_44 ) ;
return V_18 ;
}
V_18 = F_114 ( & V_207 ) ;
if ( V_18 != 0 ) {
F_113 ( L_31 , V_18 ) ;
F_115 ( & V_206 ) ;
F_31 ( V_44 ) ;
return V_18 ;
}
F_116 ( L_32 , V_20 ) ;
return 0 ;
}
static void T_8
F_117 ( void )
{
F_118 ( & V_207 ) ;
F_115 ( & V_206 ) ;
F_31 ( V_44 ) ;
F_10 ( L_33 ) ;
}
