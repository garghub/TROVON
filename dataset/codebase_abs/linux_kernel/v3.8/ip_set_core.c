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
F_40 ( struct V_42 * V_43 )
{
F_41 ( & V_44 ) ;
V_43 -> V_45 ++ ;
F_42 ( & V_44 ) ;
}
static inline void
F_43 ( struct V_42 * V_43 )
{
F_41 ( & V_44 ) ;
F_44 ( V_43 -> V_45 == 0 ) ;
V_43 -> V_45 -- ;
F_42 ( & V_44 ) ;
}
static inline struct V_42 *
F_45 ( T_4 V_46 )
{
struct V_42 * V_43 ;
F_15 () ;
V_43 = F_46 ( V_47 ) [ V_46 ] ;
F_17 () ;
return V_43 ;
}
int
F_47 ( T_4 V_46 , const struct V_48 * V_49 ,
const struct V_50 * V_51 ,
const struct V_52 * V_53 )
{
struct V_42 * V_43 = F_45 ( V_46 ) ;
int V_18 = 0 ;
F_44 ( V_43 == NULL ) ;
F_10 ( L_16 , V_43 -> V_3 , V_46 ) ;
if ( V_53 -> V_54 < V_43 -> type -> V_55 ||
! ( V_53 -> V_4 == V_43 -> V_4 || V_43 -> V_4 == V_6 ) )
return 0 ;
F_48 ( & V_43 -> V_56 ) ;
V_18 = V_43 -> V_57 -> V_58 ( V_43 , V_49 , V_51 , V_59 , V_53 ) ;
F_49 ( & V_43 -> V_56 ) ;
if ( V_18 == - V_60 ) {
F_10 ( L_17 ) ;
F_41 ( & V_43 -> V_56 ) ;
V_43 -> V_57 -> V_58 ( V_43 , V_49 , V_51 , V_61 , V_53 ) ;
F_42 ( & V_43 -> V_56 ) ;
V_18 = 1 ;
} else {
if ( ( V_53 -> V_62 & V_63 ) &&
( V_43 -> type -> V_64 & V_65 ) &&
( V_18 > 0 || V_18 == - V_66 ) )
V_18 = - V_18 ;
}
return ( V_18 < 0 ? 0 : V_18 ) ;
}
int
F_50 ( T_4 V_46 , const struct V_48 * V_49 ,
const struct V_50 * V_51 ,
const struct V_52 * V_53 )
{
struct V_42 * V_43 = F_45 ( V_46 ) ;
int V_18 ;
F_44 ( V_43 == NULL ) ;
F_10 ( L_16 , V_43 -> V_3 , V_46 ) ;
if ( V_53 -> V_54 < V_43 -> type -> V_55 ||
! ( V_53 -> V_4 == V_43 -> V_4 || V_43 -> V_4 == V_6 ) )
return 0 ;
F_41 ( & V_43 -> V_56 ) ;
V_18 = V_43 -> V_57 -> V_58 ( V_43 , V_49 , V_51 , V_61 , V_53 ) ;
F_42 ( & V_43 -> V_56 ) ;
return V_18 ;
}
int
F_51 ( T_4 V_46 , const struct V_48 * V_49 ,
const struct V_50 * V_51 ,
const struct V_52 * V_53 )
{
struct V_42 * V_43 = F_45 ( V_46 ) ;
int V_18 = 0 ;
F_44 ( V_43 == NULL ) ;
F_10 ( L_16 , V_43 -> V_3 , V_46 ) ;
if ( V_53 -> V_54 < V_43 -> type -> V_55 ||
! ( V_53 -> V_4 == V_43 -> V_4 || V_43 -> V_4 == V_6 ) )
return 0 ;
F_41 ( & V_43 -> V_56 ) ;
V_18 = V_43 -> V_57 -> V_58 ( V_43 , V_49 , V_51 , V_67 , V_53 ) ;
F_42 ( & V_43 -> V_56 ) ;
return V_18 ;
}
T_4
F_52 ( const char * V_3 , struct V_42 * * V_43 )
{
T_4 V_68 , V_46 = V_69 ;
struct V_42 * V_70 ;
F_15 () ;
for ( V_68 = 0 ; V_68 < V_71 ; V_68 ++ ) {
V_70 = F_46 ( V_47 ) [ V_68 ] ;
if ( V_70 != NULL && F_7 ( V_70 -> V_3 , V_3 ) ) {
F_40 ( V_70 ) ;
V_46 = V_68 ;
* V_43 = V_70 ;
break;
}
}
F_17 () ;
return V_46 ;
}
void
F_53 ( T_4 V_46 )
{
struct V_42 * V_43 ;
F_15 () ;
V_43 = F_46 ( V_47 ) [ V_46 ] ;
if ( V_43 != NULL )
F_43 ( V_43 ) ;
F_17 () ;
}
const char *
F_54 ( T_4 V_46 )
{
const struct V_42 * V_43 = F_45 ( V_46 ) ;
F_44 ( V_43 == NULL ) ;
F_44 ( V_43 -> V_45 == 0 ) ;
return V_43 -> V_3 ;
}
T_4
F_55 ( const char * V_3 )
{
T_4 V_68 , V_46 = V_69 ;
struct V_42 * V_70 ;
F_13 () ;
for ( V_68 = 0 ; V_68 < V_71 ; V_68 ++ ) {
V_70 = F_56 ( V_68 ) ;
if ( V_70 != NULL && F_7 ( V_70 -> V_3 , V_3 ) ) {
F_40 ( V_70 ) ;
V_46 = V_68 ;
break;
}
}
F_9 () ;
return V_46 ;
}
T_4
F_57 ( T_4 V_46 )
{
struct V_42 * V_43 ;
if ( V_46 > V_71 )
return V_69 ;
F_13 () ;
V_43 = F_56 ( V_46 ) ;
if ( V_43 )
F_40 ( V_43 ) ;
else
V_46 = V_69 ;
F_9 () ;
return V_46 ;
}
void
F_58 ( T_4 V_46 )
{
struct V_42 * V_43 ;
F_13 () ;
V_43 = F_56 ( V_46 ) ;
if ( V_43 != NULL )
F_43 ( V_43 ) ;
F_9 () ;
}
static inline bool
F_59 ( const struct V_29 * const V_34 [] )
{
return ! V_34 [ V_72 ] ||
F_60 ( V_34 [ V_72 ] ) != V_20 ;
}
static inline T_5
F_61 ( const struct V_73 * V_74 )
{
return V_74 -> V_75 & V_76 ? 0 : V_77 ;
}
static struct V_73 *
F_62 ( struct V_48 * V_49 , T_5 V_78 , T_5 V_79 , unsigned int V_62 ,
enum V_80 V_81 )
{
struct V_73 * V_74 ;
struct V_82 * V_83 ;
V_74 = F_63 ( V_49 , V_78 , V_79 , V_81 | ( V_84 << 8 ) ,
sizeof( * V_83 ) , V_62 ) ;
if ( V_74 == NULL )
return NULL ;
V_83 = F_64 ( V_74 ) ;
V_83 -> V_85 = V_86 ;
V_83 -> V_87 = V_88 ;
V_83 -> V_89 = 0 ;
return V_74 ;
}
static struct V_42 *
F_65 ( const char * V_3 , T_4 * V_90 )
{
struct V_42 * V_43 = NULL ;
T_4 V_68 ;
* V_90 = V_69 ;
for ( V_68 = 0 ; V_68 < V_71 ; V_68 ++ ) {
V_43 = F_56 ( V_68 ) ;
if ( V_43 != NULL && F_7 ( V_43 -> V_3 , V_3 ) ) {
* V_90 = V_68 ;
break;
}
}
return ( * V_90 == V_69 ? NULL : V_43 ) ;
}
static inline struct V_42 *
F_66 ( const char * V_3 )
{
T_4 V_90 ;
return F_65 ( V_3 , & V_90 ) ;
}
static int
F_67 ( const char * V_3 , T_4 * V_46 , struct V_42 * * V_43 )
{
struct V_42 * V_70 ;
T_4 V_68 ;
* V_46 = V_69 ;
for ( V_68 = 0 ; V_68 < V_71 ; V_68 ++ ) {
V_70 = F_56 ( V_68 ) ;
if ( V_70 == NULL ) {
if ( * V_46 == V_69 )
* V_46 = V_68 ;
} else if ( F_7 ( V_3 , V_70 -> V_3 ) ) {
* V_43 = V_70 ;
return - V_91 ;
}
}
if ( * V_46 == V_69 )
return - V_92 ;
return 0 ;
}
static int
F_68 ( struct V_93 * V_94 , struct V_48 * V_49 ,
const struct V_73 * V_74 ,
const struct V_29 * const V_95 [] )
{
return - V_96 ;
}
static int
F_69 ( struct V_93 * V_94 , struct V_48 * V_49 ,
const struct V_73 * V_74 ,
const struct V_29 * const V_95 [] )
{
struct V_42 * V_43 , * V_97 = NULL ;
T_4 V_46 = V_69 ;
struct V_29 * V_34 [ V_98 + 1 ] = {} ;
const char * V_3 , * V_99 ;
T_1 V_4 , V_5 ;
T_5 V_62 = F_61 ( V_74 ) ;
int V_18 = 0 ;
if ( F_34 ( F_59 ( V_95 ) ||
V_95 [ V_100 ] == NULL ||
V_95 [ V_101 ] == NULL ||
V_95 [ V_102 ] == NULL ||
V_95 [ V_103 ] == NULL ||
( V_95 [ V_104 ] != NULL &&
! F_32 ( V_95 [ V_104 ] ) ) ) )
return - V_36 ;
V_3 = F_39 ( V_95 [ V_100 ] ) ;
V_99 = F_39 ( V_95 [ V_101 ] ) ;
V_4 = F_60 ( V_95 [ V_103 ] ) ;
V_5 = F_60 ( V_95 [ V_102 ] ) ;
F_10 ( L_18 ,
V_3 , V_99 , F_20 ( V_4 ) , V_5 ) ;
V_43 = F_26 ( sizeof( struct V_42 ) , V_27 ) ;
if ( ! V_43 )
return - V_105 ;
F_70 ( & V_43 -> V_56 ) ;
F_71 ( V_43 -> V_3 , V_3 , V_106 ) ;
V_43 -> V_4 = V_4 ;
V_43 -> V_5 = V_5 ;
V_18 = F_72 ( V_99 , V_4 , V_5 , & ( V_43 -> type ) ) ;
if ( V_18 )
goto V_107;
if ( V_95 [ V_104 ] &&
F_35 ( V_34 , V_98 , V_95 [ V_104 ] ,
V_43 -> type -> V_108 ) ) {
V_18 = - V_36 ;
goto V_109;
}
V_18 = V_43 -> type -> V_110 ( V_43 , V_34 , V_62 ) ;
if ( V_18 != 0 )
goto V_109;
V_18 = F_67 ( V_43 -> V_3 , & V_46 , & V_97 ) ;
if ( V_18 == - V_91 ) {
if ( ( V_62 & V_77 ) &&
F_7 ( V_43 -> type -> V_3 , V_97 -> type -> V_3 ) &&
V_43 -> type -> V_4 == V_97 -> type -> V_4 &&
V_43 -> type -> V_7 == V_97 -> type -> V_7 &&
V_43 -> type -> V_8 == V_97 -> type -> V_8 &&
V_43 -> V_57 -> V_111 ( V_43 , V_97 ) )
V_18 = 0 ;
goto V_112;
} else if ( V_18 == - V_92 ) {
struct V_42 * * V_22 , * * V_113 ;
T_4 V_68 = V_71 + V_114 ;
if ( V_68 < V_71 || V_68 == V_69 )
goto V_112;
V_22 = F_26 ( sizeof( struct V_42 * ) * V_68 , V_27 ) ;
if ( ! V_22 )
goto V_112;
V_113 = F_73 ( V_47 ) ;
memcpy ( V_22 , V_113 , sizeof( struct V_42 * ) * V_71 ) ;
F_74 ( V_47 , V_22 ) ;
F_75 () ;
V_46 = V_71 ;
V_71 = V_68 ;
F_31 ( V_113 ) ;
V_18 = 0 ;
} else if ( V_18 )
goto V_112;
F_10 ( L_19 , V_43 -> V_3 , V_46 ) ;
F_56 ( V_46 ) = V_43 ;
return V_18 ;
V_112:
V_43 -> V_57 -> V_115 ( V_43 ) ;
V_109:
F_76 ( V_43 -> type -> V_13 ) ;
V_107:
F_31 ( V_43 ) ;
return V_18 ;
}
static void
F_77 ( T_4 V_46 )
{
struct V_42 * V_43 = F_56 ( V_46 ) ;
F_10 ( L_20 , V_43 -> V_3 ) ;
F_56 ( V_46 ) = NULL ;
V_43 -> V_57 -> V_115 ( V_43 ) ;
F_76 ( V_43 -> type -> V_13 ) ;
F_31 ( V_43 ) ;
}
static int
F_78 ( struct V_93 * V_94 , struct V_48 * V_49 ,
const struct V_73 * V_74 ,
const struct V_29 * const V_95 [] )
{
struct V_42 * V_70 ;
T_4 V_68 ;
int V_18 = 0 ;
if ( F_34 ( F_59 ( V_95 ) ) )
return - V_36 ;
F_48 ( & V_44 ) ;
if ( ! V_95 [ V_100 ] ) {
for ( V_68 = 0 ; V_68 < V_71 ; V_68 ++ ) {
V_70 = F_56 ( V_68 ) ;
if ( V_70 != NULL && V_70 -> V_45 ) {
V_18 = - V_116 ;
goto V_107;
}
}
F_49 ( & V_44 ) ;
for ( V_68 = 0 ; V_68 < V_71 ; V_68 ++ ) {
V_70 = F_56 ( V_68 ) ;
if ( V_70 != NULL )
F_77 ( V_68 ) ;
}
} else {
V_70 = F_65 ( F_39 ( V_95 [ V_100 ] ) , & V_68 ) ;
if ( V_70 == NULL ) {
V_18 = - V_117 ;
goto V_107;
} else if ( V_70 -> V_45 ) {
V_18 = - V_116 ;
goto V_107;
}
F_49 ( & V_44 ) ;
F_77 ( V_68 ) ;
}
return 0 ;
V_107:
F_49 ( & V_44 ) ;
return V_18 ;
}
static void
F_79 ( struct V_42 * V_43 )
{
F_10 ( L_20 , V_43 -> V_3 ) ;
F_41 ( & V_43 -> V_56 ) ;
V_43 -> V_57 -> V_118 ( V_43 ) ;
F_42 ( & V_43 -> V_56 ) ;
}
static int
F_80 ( struct V_93 * V_94 , struct V_48 * V_49 ,
const struct V_73 * V_74 ,
const struct V_29 * const V_95 [] )
{
struct V_42 * V_70 ;
T_4 V_68 ;
if ( F_34 ( F_59 ( V_95 ) ) )
return - V_36 ;
if ( ! V_95 [ V_100 ] ) {
for ( V_68 = 0 ; V_68 < V_71 ; V_68 ++ ) {
V_70 = F_56 ( V_68 ) ;
if ( V_70 != NULL )
F_79 ( V_70 ) ;
}
} else {
V_70 = F_66 ( F_39 ( V_95 [ V_100 ] ) ) ;
if ( V_70 == NULL )
return - V_117 ;
F_79 ( V_70 ) ;
}
return 0 ;
}
static int
F_81 ( struct V_93 * V_94 , struct V_48 * V_49 ,
const struct V_73 * V_74 ,
const struct V_29 * const V_95 [] )
{
struct V_42 * V_43 , * V_70 ;
const char * V_119 ;
T_4 V_68 ;
int V_18 = 0 ;
if ( F_34 ( F_59 ( V_95 ) ||
V_95 [ V_100 ] == NULL ||
V_95 [ V_120 ] == NULL ) )
return - V_36 ;
V_43 = F_66 ( F_39 ( V_95 [ V_100 ] ) ) ;
if ( V_43 == NULL )
return - V_117 ;
F_48 ( & V_44 ) ;
if ( V_43 -> V_45 != 0 ) {
V_18 = - V_121 ;
goto V_107;
}
V_119 = F_39 ( V_95 [ V_120 ] ) ;
for ( V_68 = 0 ; V_68 < V_71 ; V_68 ++ ) {
V_70 = F_56 ( V_68 ) ;
if ( V_70 != NULL && F_7 ( V_70 -> V_3 , V_119 ) ) {
V_18 = - V_122 ;
goto V_107;
}
}
strncpy ( V_43 -> V_3 , V_119 , V_106 ) ;
V_107:
F_49 ( & V_44 ) ;
return V_18 ;
}
static int
F_82 ( struct V_93 * V_94 , struct V_48 * V_49 ,
const struct V_73 * V_74 ,
const struct V_29 * const V_95 [] )
{
struct V_42 * V_123 , * V_124 ;
T_4 V_125 , V_126 ;
char V_127 [ V_106 ] ;
if ( F_34 ( F_59 ( V_95 ) ||
V_95 [ V_100 ] == NULL ||
V_95 [ V_120 ] == NULL ) )
return - V_36 ;
V_123 = F_65 ( F_39 ( V_95 [ V_100 ] ) , & V_125 ) ;
if ( V_123 == NULL )
return - V_117 ;
V_124 = F_65 ( F_39 ( V_95 [ V_120 ] ) , & V_126 ) ;
if ( V_124 == NULL )
return - V_122 ;
if ( ! ( V_123 -> type -> V_64 == V_124 -> type -> V_64 &&
V_123 -> type -> V_4 == V_124 -> type -> V_4 ) )
return - V_128 ;
strncpy ( V_127 , V_123 -> V_3 , V_106 ) ;
strncpy ( V_123 -> V_3 , V_124 -> V_3 , V_106 ) ;
strncpy ( V_124 -> V_3 , V_127 , V_106 ) ;
F_41 ( & V_44 ) ;
F_83 ( V_123 -> V_45 , V_124 -> V_45 ) ;
F_56 ( V_125 ) = V_124 ;
F_56 ( V_126 ) = V_123 ;
F_42 ( & V_44 ) ;
return 0 ;
}
static int
F_84 ( struct V_129 * V_130 )
{
if ( V_130 -> args [ 2 ] ) {
F_10 ( L_21 , F_56 ( V_130 -> args [ 1 ] ) -> V_3 ) ;
F_53 ( ( T_4 ) V_130 -> args [ 1 ] ) ;
}
return 0 ;
}
static inline void
F_85 ( struct V_73 * V_74 )
{
const struct V_29 * V_95 ;
int V_131 ;
F_10 ( L_22 ) ;
F_86 (attr, nlh, sizeof(struct nfgenmsg), rem) {
F_10 ( L_23 , V_31 ( V_95 ) , V_95 -> V_132 ) ;
}
}
static int
F_87 ( struct V_129 * V_130 )
{
struct V_73 * V_74 = F_88 ( V_130 -> V_49 ) ;
int V_133 = F_89 ( sizeof( struct V_82 ) ) ;
struct V_29 * V_134 [ V_135 + 1 ] ;
struct V_29 * V_95 = ( void * ) V_74 + V_133 ;
T_5 V_136 ;
T_4 V_46 ;
F_90 ( V_134 , V_135 ,
V_95 , V_74 -> V_137 - V_133 , V_138 ) ;
if ( V_134 [ V_100 ] ) {
struct V_42 * V_43 ;
V_43 = F_65 ( F_39 ( V_134 [ V_100 ] ) ,
& V_46 ) ;
if ( V_43 == NULL )
return - V_117 ;
V_136 = V_139 ;
V_130 -> args [ 1 ] = V_46 ;
} else
V_136 = V_140 ;
if ( V_134 [ V_141 ] ) {
T_5 V_142 = F_91 ( V_134 [ V_141 ] ) ;
V_136 |= ( V_142 << 16 ) ;
}
V_130 -> args [ 0 ] = V_136 ;
return 0 ;
}
static int
F_92 ( struct V_48 * V_49 , struct V_129 * V_130 )
{
T_4 V_46 = V_69 , V_17 ;
struct V_42 * V_43 = NULL ;
struct V_73 * V_74 = NULL ;
unsigned int V_62 = F_93 ( V_130 -> V_49 ) . V_78 ? V_143 : 0 ;
T_5 V_136 , V_144 ;
int V_18 = 0 ;
if ( ! V_130 -> args [ 0 ] ) {
V_18 = F_87 ( V_130 ) ;
if ( V_18 < 0 ) {
V_74 = F_88 ( V_130 -> V_49 ) ;
if ( V_74 -> V_75 & V_145 )
F_94 ( V_130 -> V_49 , V_74 , V_18 ) ;
return V_18 ;
}
}
if ( V_130 -> args [ 1 ] >= V_71 )
goto V_107;
V_136 = F_95 ( V_130 -> args [ 0 ] ) ;
V_144 = F_96 ( V_130 -> args [ 0 ] ) ;
V_17 = V_136 == V_139 ? V_130 -> args [ 1 ] + 1 : V_71 ;
V_146:
F_10 ( L_24 ,
V_136 , V_144 , V_130 -> args [ 1 ] ) ;
for (; V_130 -> args [ 1 ] < V_17 ; V_130 -> args [ 1 ] ++ ) {
V_46 = ( T_4 ) V_130 -> args [ 1 ] ;
V_43 = F_56 ( V_46 ) ;
if ( V_43 == NULL ) {
if ( V_136 == V_139 ) {
V_18 = - V_117 ;
goto V_107;
}
continue;
}
if ( V_136 != V_139 &&
( ( V_136 == V_140 ) ==
! ! ( V_43 -> type -> V_64 & V_147 ) ) )
continue;
F_10 ( L_25 , V_43 -> V_3 ) ;
if ( ! V_130 -> args [ 2 ] ) {
F_10 ( L_26 ) ;
F_40 ( V_43 ) ;
}
V_74 = F_62 ( V_49 , F_93 ( V_130 -> V_49 ) . V_78 ,
V_130 -> V_74 -> V_148 , V_62 ,
V_149 ) ;
if ( ! V_74 ) {
V_18 = - V_150 ;
goto V_151;
}
if ( F_97 ( V_49 , V_72 , V_20 ) ||
F_98 ( V_49 , V_100 , V_43 -> V_3 ) )
goto V_152;
if ( V_144 & V_153 )
goto V_154;
switch ( V_130 -> args [ 2 ] ) {
case 0 :
if ( F_98 ( V_49 , V_101 ,
V_43 -> type -> V_3 ) ||
F_97 ( V_49 , V_103 ,
V_43 -> V_4 ) ||
F_97 ( V_49 , V_102 ,
V_43 -> V_5 ) )
goto V_152;
V_18 = V_43 -> V_57 -> V_155 ( V_43 , V_49 ) ;
if ( V_18 < 0 )
goto V_151;
if ( V_144 & V_156 )
goto V_154;
default:
F_48 ( & V_43 -> V_56 ) ;
V_18 = V_43 -> V_57 -> V_22 ( V_43 , V_49 , V_130 ) ;
F_49 ( & V_43 -> V_56 ) ;
if ( ! V_130 -> args [ 2 ] )
goto V_154;
goto V_151;
}
}
if ( V_136 == V_140 ) {
V_136 = V_157 ;
V_130 -> args [ 0 ] = V_136 | ( V_144 << 16 ) ;
V_130 -> args [ 1 ] = 0 ;
goto V_146;
}
goto V_107;
V_152:
V_18 = - V_14 ;
V_154:
if ( V_136 == V_139 )
V_130 -> args [ 1 ] = V_69 ;
else
V_130 -> args [ 1 ] ++ ;
V_151:
if ( V_18 || ! V_130 -> args [ 2 ] ) {
F_10 ( L_21 , F_56 ( V_46 ) -> V_3 ) ;
F_53 ( V_46 ) ;
V_130 -> args [ 2 ] = 0 ;
}
V_107:
if ( V_74 ) {
F_99 ( V_49 , V_74 ) ;
F_10 ( L_27 , V_74 -> V_137 ) ;
F_85 ( V_74 ) ;
}
return V_18 < 0 ? V_18 : V_49 -> V_158 ;
}
static int
F_100 ( struct V_93 * V_94 , struct V_48 * V_49 ,
const struct V_73 * V_74 ,
const struct V_29 * const V_95 [] )
{
if ( F_34 ( F_59 ( V_95 ) ) )
return - V_36 ;
{
struct V_159 V_160 = {
. V_161 = F_92 ,
. V_162 = F_84 ,
} ;
return F_101 ( V_94 , V_49 , V_74 , & V_160 ) ;
}
}
static int
F_102 ( struct V_93 * V_94 , struct V_48 * V_49 , struct V_42 * V_43 ,
struct V_29 * V_34 [] , enum V_163 V_164 ,
T_5 V_62 , bool V_165 )
{
int V_18 ;
T_5 V_166 = 0 ;
bool V_167 = V_62 & V_77 , V_168 = false ;
do {
F_41 ( & V_43 -> V_56 ) ;
V_18 = V_43 -> V_57 -> V_169 ( V_43 , V_34 , V_164 , & V_166 , V_62 , V_168 ) ;
F_42 ( & V_43 -> V_56 ) ;
V_168 = true ;
} while ( V_18 == - V_60 &&
V_43 -> V_57 -> V_170 &&
( V_18 = V_43 -> V_57 -> V_170 ( V_43 , V_168 ) ) == 0 );
if ( ! V_18 || ( V_18 == - V_171 && V_167 ) )
return 0 ;
if ( V_166 && V_165 ) {
struct V_73 * V_172 , * V_74 = F_88 ( V_49 ) ;
struct V_48 * V_173 ;
struct V_174 * V_175 ;
T_2 V_176 = sizeof( * V_175 ) + V_137 ( V_74 ) ;
int V_133 = F_89 ( sizeof( struct V_82 ) ) ;
struct V_29 * V_134 [ V_135 + 1 ] ;
struct V_29 * V_177 ;
T_5 * V_178 ;
V_173 = F_103 ( V_176 , V_27 ) ;
if ( V_173 == NULL )
return - V_105 ;
V_172 = F_104 ( V_173 , F_93 ( V_49 ) . V_78 ,
V_74 -> V_148 , V_179 , V_176 , 0 ) ;
V_175 = F_64 ( V_172 ) ;
V_175 -> error = V_18 ;
memcpy ( & V_175 -> V_180 , V_74 , V_74 -> V_137 ) ;
V_177 = ( void * ) & V_175 -> V_180 + V_133 ;
F_90 ( V_134 , V_135 ,
V_177 , V_74 -> V_137 - V_133 ,
V_181 ) ;
V_178 = F_39 ( V_134 [ V_182 ] ) ;
* V_178 = V_166 ;
F_105 ( V_94 , V_173 , F_93 ( V_49 ) . V_78 , V_183 ) ;
return - V_184 ;
}
return V_18 ;
}
static int
F_106 ( struct V_93 * V_94 , struct V_48 * V_49 ,
const struct V_73 * V_74 ,
const struct V_29 * const V_95 [] )
{
struct V_42 * V_43 ;
struct V_29 * V_34 [ V_185 + 1 ] = {} ;
const struct V_29 * V_30 ;
T_5 V_62 = F_61 ( V_74 ) ;
bool V_165 ;
int V_18 = 0 ;
if ( F_34 ( F_59 ( V_95 ) ||
V_95 [ V_100 ] == NULL ||
! ( ( V_95 [ V_104 ] != NULL ) ^
( V_95 [ V_186 ] != NULL ) ) ||
( V_95 [ V_104 ] != NULL &&
! F_32 ( V_95 [ V_104 ] ) ) ||
( V_95 [ V_186 ] != NULL &&
( ! F_32 ( V_95 [ V_186 ] ) ||
V_95 [ V_182 ] == NULL ) ) ) )
return - V_36 ;
V_43 = F_66 ( F_39 ( V_95 [ V_100 ] ) ) ;
if ( V_43 == NULL )
return - V_117 ;
V_165 = ! ! V_95 [ V_182 ] ;
if ( V_95 [ V_104 ] ) {
if ( F_35 ( V_34 , V_185 ,
V_95 [ V_104 ] ,
V_43 -> type -> V_187 ) )
return - V_36 ;
V_18 = F_102 ( V_94 , V_49 , V_43 , V_34 , V_61 , V_62 ,
V_165 ) ;
} else {
int V_188 ;
F_107 (nla, attr[IPSET_ATTR_ADT], nla_rem) {
memset ( V_34 , 0 , sizeof( V_34 ) ) ;
if ( V_31 ( V_30 ) != V_104 ||
! F_32 ( V_30 ) ||
F_35 ( V_34 , V_185 , V_30 ,
V_43 -> type -> V_187 ) )
return - V_36 ;
V_18 = F_102 ( V_94 , V_49 , V_43 , V_34 , V_61 ,
V_62 , V_165 ) ;
if ( V_18 < 0 )
return V_18 ;
}
}
return V_18 ;
}
static int
F_108 ( struct V_93 * V_94 , struct V_48 * V_49 ,
const struct V_73 * V_74 ,
const struct V_29 * const V_95 [] )
{
struct V_42 * V_43 ;
struct V_29 * V_34 [ V_185 + 1 ] = {} ;
const struct V_29 * V_30 ;
T_5 V_62 = F_61 ( V_74 ) ;
bool V_165 ;
int V_18 = 0 ;
if ( F_34 ( F_59 ( V_95 ) ||
V_95 [ V_100 ] == NULL ||
! ( ( V_95 [ V_104 ] != NULL ) ^
( V_95 [ V_186 ] != NULL ) ) ||
( V_95 [ V_104 ] != NULL &&
! F_32 ( V_95 [ V_104 ] ) ) ||
( V_95 [ V_186 ] != NULL &&
( ! F_32 ( V_95 [ V_186 ] ) ||
V_95 [ V_182 ] == NULL ) ) ) )
return - V_36 ;
V_43 = F_66 ( F_39 ( V_95 [ V_100 ] ) ) ;
if ( V_43 == NULL )
return - V_117 ;
V_165 = ! ! V_95 [ V_182 ] ;
if ( V_95 [ V_104 ] ) {
if ( F_35 ( V_34 , V_185 ,
V_95 [ V_104 ] ,
V_43 -> type -> V_187 ) )
return - V_36 ;
V_18 = F_102 ( V_94 , V_49 , V_43 , V_34 , V_67 , V_62 ,
V_165 ) ;
} else {
int V_188 ;
F_107 (nla, attr[IPSET_ATTR_ADT], nla_rem) {
memset ( V_34 , 0 , sizeof( * V_34 ) ) ;
if ( V_31 ( V_30 ) != V_104 ||
! F_32 ( V_30 ) ||
F_35 ( V_34 , V_185 , V_30 ,
V_43 -> type -> V_187 ) )
return - V_36 ;
V_18 = F_102 ( V_94 , V_49 , V_43 , V_34 , V_67 ,
V_62 , V_165 ) ;
if ( V_18 < 0 )
return V_18 ;
}
}
return V_18 ;
}
static int
F_109 ( struct V_93 * V_94 , struct V_48 * V_49 ,
const struct V_73 * V_74 ,
const struct V_29 * const V_95 [] )
{
struct V_42 * V_43 ;
struct V_29 * V_34 [ V_185 + 1 ] = {} ;
int V_18 = 0 ;
if ( F_34 ( F_59 ( V_95 ) ||
V_95 [ V_100 ] == NULL ||
V_95 [ V_104 ] == NULL ||
! F_32 ( V_95 [ V_104 ] ) ) )
return - V_36 ;
V_43 = F_66 ( F_39 ( V_95 [ V_100 ] ) ) ;
if ( V_43 == NULL )
return - V_117 ;
if ( F_35 ( V_34 , V_185 , V_95 [ V_104 ] ,
V_43 -> type -> V_187 ) )
return - V_36 ;
F_48 ( & V_43 -> V_56 ) ;
V_18 = V_43 -> V_57 -> V_169 ( V_43 , V_34 , V_59 , NULL , 0 , 0 ) ;
F_49 ( & V_43 -> V_56 ) ;
if ( V_18 == - V_60 )
V_18 = 1 ;
return V_18 < 0 ? V_18 : V_18 > 0 ? 0 : - V_171 ;
}
static int
F_110 ( struct V_93 * V_94 , struct V_48 * V_49 ,
const struct V_73 * V_74 ,
const struct V_29 * const V_95 [] )
{
const struct V_42 * V_43 ;
struct V_48 * V_173 ;
struct V_73 * V_189 ;
int V_18 = 0 ;
if ( F_34 ( F_59 ( V_95 ) ||
V_95 [ V_100 ] == NULL ) )
return - V_36 ;
V_43 = F_66 ( F_39 ( V_95 [ V_100 ] ) ) ;
if ( V_43 == NULL )
return - V_117 ;
V_173 = F_103 ( V_190 , V_27 ) ;
if ( V_173 == NULL )
return - V_105 ;
V_189 = F_62 ( V_173 , F_93 ( V_49 ) . V_78 , V_74 -> V_148 , 0 ,
V_191 ) ;
if ( ! V_189 )
goto V_192;
if ( F_97 ( V_173 , V_72 , V_20 ) ||
F_98 ( V_173 , V_100 , V_43 -> V_3 ) ||
F_98 ( V_173 , V_101 , V_43 -> type -> V_3 ) ||
F_97 ( V_173 , V_103 , V_43 -> V_4 ) ||
F_97 ( V_173 , V_102 , V_43 -> V_5 ) )
goto V_152;
F_99 ( V_173 , V_189 ) ;
V_18 = F_105 ( V_94 , V_173 , F_93 ( V_49 ) . V_78 , V_183 ) ;
if ( V_18 < 0 )
return V_18 ;
return 0 ;
V_152:
F_111 ( V_173 , V_189 ) ;
V_192:
F_112 ( V_173 ) ;
return - V_150 ;
}
static int
V_2 ( struct V_93 * V_94 , struct V_48 * V_49 ,
const struct V_73 * V_74 ,
const struct V_29 * const V_95 [] )
{
struct V_48 * V_173 ;
struct V_73 * V_189 ;
T_1 V_4 , V_16 , V_17 ;
const char * V_99 ;
int V_18 = 0 ;
if ( F_34 ( F_59 ( V_95 ) ||
V_95 [ V_101 ] == NULL ||
V_95 [ V_103 ] == NULL ) )
return - V_36 ;
V_4 = F_60 ( V_95 [ V_103 ] ) ;
V_99 = F_39 ( V_95 [ V_101 ] ) ;
V_18 = F_113 ( V_99 , V_4 , & V_16 , & V_17 ) ;
if ( V_18 )
return V_18 ;
V_173 = F_103 ( V_190 , V_27 ) ;
if ( V_173 == NULL )
return - V_105 ;
V_189 = F_62 ( V_173 , F_93 ( V_49 ) . V_78 , V_74 -> V_148 , 0 ,
V_193 ) ;
if ( ! V_189 )
goto V_192;
if ( F_97 ( V_173 , V_72 , V_20 ) ||
F_98 ( V_173 , V_101 , V_99 ) ||
F_97 ( V_173 , V_103 , V_4 ) ||
F_97 ( V_173 , V_102 , V_17 ) ||
F_97 ( V_173 , V_194 , V_16 ) )
goto V_152;
F_99 ( V_173 , V_189 ) ;
F_10 ( L_28 , V_189 -> V_137 ) ;
V_18 = F_105 ( V_94 , V_173 , F_93 ( V_49 ) . V_78 , V_183 ) ;
if ( V_18 < 0 )
return V_18 ;
return 0 ;
V_152:
F_111 ( V_173 , V_189 ) ;
V_192:
F_112 ( V_173 ) ;
return - V_150 ;
}
static int
F_114 ( struct V_93 * V_94 , struct V_48 * V_49 ,
const struct V_73 * V_74 ,
const struct V_29 * const V_95 [] )
{
struct V_48 * V_173 ;
struct V_73 * V_189 ;
int V_18 = 0 ;
if ( F_34 ( V_95 [ V_72 ] == NULL ) )
return - V_36 ;
V_173 = F_103 ( V_190 , V_27 ) ;
if ( V_173 == NULL )
return - V_105 ;
V_189 = F_62 ( V_173 , F_93 ( V_49 ) . V_78 , V_74 -> V_148 , 0 ,
V_195 ) ;
if ( ! V_189 )
goto V_192;
if ( F_97 ( V_173 , V_72 , V_20 ) )
goto V_152;
F_99 ( V_173 , V_189 ) ;
V_18 = F_105 ( V_94 , V_173 , F_93 ( V_49 ) . V_78 , V_183 ) ;
if ( V_18 < 0 )
return V_18 ;
return 0 ;
V_152:
F_111 ( V_173 , V_189 ) ;
V_192:
F_112 ( V_173 ) ;
return - V_150 ;
}
static int
F_115 ( struct V_93 * V_196 , int V_197 , void T_6 * V_198 , int * V_158 )
{
unsigned int * V_199 ;
void * V_200 ;
int V_201 = * V_158 , V_18 = 0 ;
if ( ! F_116 ( F_117 ( V_196 ) -> V_202 , V_203 ) )
return - V_204 ;
if ( V_197 != V_205 )
return - V_206 ;
if ( * V_158 < sizeof( unsigned int ) )
return - V_21 ;
V_200 = F_118 ( * V_158 ) ;
if ( ! V_200 )
return - V_105 ;
if ( F_119 ( V_200 , V_198 , * V_158 ) != 0 ) {
V_18 = - V_14 ;
goto V_162;
}
V_199 = ( unsigned int * ) V_200 ;
if ( * V_199 < V_207 ) {
struct V_208 * V_209 = V_200 ;
if ( V_209 -> V_87 != V_20 ) {
V_18 = - V_210 ;
goto V_162;
}
}
switch ( * V_199 ) {
case V_207 : {
struct V_208 * V_209 = V_200 ;
if ( * V_158 != sizeof( struct V_208 ) ) {
V_18 = - V_21 ;
goto V_162;
}
V_209 -> V_87 = V_20 ;
V_18 = F_120 ( V_198 , V_209 ,
sizeof( struct V_208 ) ) ;
goto V_162;
}
case V_211 : {
struct V_212 * V_213 = V_200 ;
T_4 V_90 ;
if ( * V_158 != sizeof( struct V_212 ) ) {
V_18 = - V_21 ;
goto V_162;
}
V_213 -> V_43 . V_3 [ V_106 - 1 ] = '\0' ;
F_13 () ;
F_65 ( V_213 -> V_43 . V_3 , & V_90 ) ;
V_213 -> V_43 . V_46 = V_90 ;
F_9 () ;
goto V_214;
}
case V_215 : {
struct V_212 * V_213 = V_200 ;
struct V_42 * V_43 ;
if ( * V_158 != sizeof( struct V_212 ) ||
V_213 -> V_43 . V_46 >= V_71 ) {
V_18 = - V_21 ;
goto V_162;
}
F_13 () ;
V_43 = F_56 ( V_213 -> V_43 . V_46 ) ;
strncpy ( V_213 -> V_43 . V_3 , V_43 ? V_43 -> V_3 : L_29 ,
V_106 ) ;
F_9 () ;
goto V_214;
}
default:
V_18 = - V_216 ;
goto V_162;
}
V_214:
V_18 = F_120 ( V_198 , V_200 , V_201 ) ;
V_162:
F_30 ( V_200 ) ;
if ( V_18 > 0 )
V_18 = 0 ;
return V_18 ;
}
static int T_7
F_121 ( void )
{
struct V_42 * * V_22 ;
int V_18 ;
if ( V_217 )
V_71 = V_217 ;
if ( V_71 >= V_69 )
V_71 = V_69 - 1 ;
V_22 = F_26 ( sizeof( struct V_42 * ) * V_71 , V_27 ) ;
if ( ! V_22 )
return - V_105 ;
F_74 ( V_47 , V_22 ) ;
V_18 = F_122 ( & V_218 ) ;
if ( V_18 != 0 ) {
F_123 ( L_30 ) ;
F_31 ( V_22 ) ;
return V_18 ;
}
V_18 = F_124 ( & V_219 ) ;
if ( V_18 != 0 ) {
F_123 ( L_31 , V_18 ) ;
F_125 ( & V_218 ) ;
F_31 ( V_22 ) ;
return V_18 ;
}
F_126 ( L_32 , V_20 ) ;
return 0 ;
}
static void T_8
F_127 ( void )
{
struct V_42 * * V_22 = F_128 ( V_47 , 1 ) ;
F_129 ( & V_219 ) ;
F_125 ( & V_218 ) ;
F_31 ( V_22 ) ;
F_10 ( L_33 ) ;
}
