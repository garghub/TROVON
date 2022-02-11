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
F_9 ( V_9 ) ;
F_10 ( L_1 , V_3 ) ;
if ( F_11 ( L_2 , V_3 ) < 0 ) {
F_12 ( L_3 , V_3 ) ;
F_13 ( V_9 ) ;
return false ;
}
F_13 ( V_9 ) ;
return true ;
}
static int
F_14 ( const char * V_3 , T_1 V_4 , T_1 V_5 ,
struct V_2 * * V_10 , bool V_11 )
{
struct V_2 * type ;
int V_12 ;
if ( V_11 && ! F_8 ( V_3 ) )
return - V_13 ;
F_15 () ;
* V_10 = F_5 ( V_3 , V_4 , V_5 ) ;
if ( * V_10 ) {
V_12 = ! F_16 ( ( * V_10 ) -> V_14 ) ? - V_15 : 0 ;
goto V_16;
}
F_6 (type, &ip_set_type_list, list)
if ( F_7 ( type -> V_3 , V_3 ) ) {
V_12 = - V_13 ;
goto V_16;
}
F_17 () ;
return V_11 ? - V_13 :
F_14 ( V_3 , V_4 , V_5 , V_10 , true ) ;
V_16:
F_17 () ;
return V_12 ;
}
static int
F_18 ( const char * V_3 , T_1 V_4 , T_1 * V_17 , T_1 * V_18 ,
bool V_11 )
{
struct V_2 * type ;
bool V_10 = false ;
if ( V_11 && ! F_8 ( V_3 ) )
return - V_13 ;
* V_17 = 255 ; * V_18 = 0 ;
F_15 () ;
F_6 (type, &ip_set_type_list, list)
if ( F_7 ( type -> V_3 , V_3 ) &&
( type -> V_4 == V_4 ||
type -> V_4 == V_6 ) ) {
V_10 = true ;
if ( type -> V_7 < * V_17 )
* V_17 = type -> V_7 ;
if ( type -> V_8 > * V_18 )
* V_18 = type -> V_8 ;
}
F_17 () ;
if ( V_10 )
return 0 ;
return V_11 ? - V_13 :
F_18 ( V_3 , V_4 , V_17 , V_18 , true ) ;
}
int
F_19 ( struct V_2 * type )
{
int V_19 = 0 ;
if ( type -> V_20 != V_21 ) {
F_12 ( L_4
L_5 ,
type -> V_3 , F_20 ( type -> V_4 ) ,
type -> V_7 , type -> V_8 ,
type -> V_20 , V_21 ) ;
return - V_22 ;
}
F_1 () ;
if ( F_5 ( type -> V_3 , type -> V_4 , type -> V_7 ) ) {
F_12 ( L_6
L_7 , type -> V_3 ,
F_20 ( type -> V_4 ) , type -> V_7 ) ;
V_19 = - V_22 ;
goto V_16;
}
F_21 ( & type -> V_23 , & V_24 ) ;
F_10 ( L_8 ,
type -> V_3 , F_20 ( type -> V_4 ) ,
type -> V_7 , type -> V_8 ) ;
V_16:
F_3 () ;
return V_19 ;
}
void
F_22 ( struct V_2 * type )
{
F_1 () ;
if ( ! F_5 ( type -> V_3 , type -> V_4 , type -> V_7 ) ) {
F_12 ( L_6
L_9 , type -> V_3 ,
F_20 ( type -> V_4 ) , type -> V_7 ) ;
goto V_16;
}
F_23 ( & type -> V_23 ) ;
F_10 ( L_10 ,
type -> V_3 , F_20 ( type -> V_4 ) , type -> V_7 ) ;
V_16:
F_3 () ;
F_24 () ;
}
void *
F_25 ( T_2 V_25 )
{
void * V_26 = NULL ;
if ( V_25 < V_27 )
V_26 = F_26 ( V_25 , V_28 | V_29 ) ;
if ( V_26 ) {
F_10 ( L_11 , V_26 ) ;
return V_26 ;
}
V_26 = F_27 ( V_25 ) ;
if ( ! V_26 )
return NULL ;
F_10 ( L_12 , V_26 ) ;
return V_26 ;
}
void
F_28 ( void * V_26 )
{
F_10 ( L_13 , V_26 ,
F_29 ( V_26 ) ? L_14 : L_15 ) ;
if ( F_29 ( V_26 ) )
F_30 ( V_26 ) ;
else
F_31 ( V_26 ) ;
}
static inline bool
F_32 ( const struct V_30 * V_31 )
{
return V_31 -> V_32 & V_33 ;
}
int
F_33 ( struct V_30 * V_31 , T_3 * V_34 )
{
struct V_30 * V_35 [ V_36 + 1 ] ;
if ( F_34 ( ! F_32 ( V_31 ) ) )
return - V_37 ;
if ( F_35 ( V_35 , V_36 , V_31 , V_38 ) )
return - V_37 ;
if ( F_34 ( ! F_36 ( V_35 , V_39 ) ) )
return - V_37 ;
* V_34 = F_37 ( V_35 [ V_39 ] ) ;
return 0 ;
}
int
F_38 ( struct V_30 * V_31 , union V_40 * V_34 )
{
struct V_30 * V_35 [ V_36 + 1 ] ;
if ( F_34 ( ! F_32 ( V_31 ) ) )
return - V_37 ;
if ( F_35 ( V_35 , V_36 , V_31 , V_38 ) )
return - V_37 ;
if ( F_34 ( ! F_36 ( V_35 , V_41 ) ) )
return - V_37 ;
memcpy ( V_34 , F_39 ( V_35 [ V_41 ] ) ,
sizeof( struct V_42 ) ) ;
return 0 ;
}
static inline void
F_40 ( struct V_43 * V_44 )
{
F_41 ( & V_45 ) ;
V_44 -> V_46 ++ ;
F_42 ( & V_45 ) ;
}
static inline void
F_43 ( struct V_43 * V_44 )
{
F_41 ( & V_45 ) ;
F_44 ( V_44 -> V_46 == 0 ) ;
V_44 -> V_46 -- ;
F_42 ( & V_45 ) ;
}
static inline struct V_43 *
F_45 ( T_4 V_47 )
{
struct V_43 * V_44 ;
F_15 () ;
V_44 = F_46 ( V_48 ) [ V_47 ] ;
F_17 () ;
return V_44 ;
}
int
F_47 ( T_4 V_47 , const struct V_49 * V_50 ,
const struct V_51 * V_52 ,
const struct V_53 * V_54 )
{
struct V_43 * V_44 = F_45 ( V_47 ) ;
int V_19 = 0 ;
F_44 ( V_44 == NULL ) ;
F_10 ( L_16 , V_44 -> V_3 , V_47 ) ;
if ( V_54 -> V_55 < V_44 -> type -> V_56 ||
! ( V_54 -> V_4 == V_44 -> V_4 || V_44 -> V_4 == V_6 ) )
return 0 ;
F_48 ( & V_44 -> V_57 ) ;
V_19 = V_44 -> V_58 -> V_59 ( V_44 , V_50 , V_52 , V_60 , V_54 ) ;
F_49 ( & V_44 -> V_57 ) ;
if ( V_19 == - V_61 ) {
F_10 ( L_17 ) ;
F_41 ( & V_44 -> V_57 ) ;
V_44 -> V_58 -> V_59 ( V_44 , V_50 , V_52 , V_62 , V_54 ) ;
F_42 ( & V_44 -> V_57 ) ;
V_19 = 1 ;
} else {
if ( ( V_54 -> V_63 & V_64 ) &&
( V_44 -> type -> V_65 & V_66 ) &&
( V_19 > 0 || V_19 == - V_67 ) )
V_19 = - V_19 ;
}
return ( V_19 < 0 ? 0 : V_19 ) ;
}
int
F_50 ( T_4 V_47 , const struct V_49 * V_50 ,
const struct V_51 * V_52 ,
const struct V_53 * V_54 )
{
struct V_43 * V_44 = F_45 ( V_47 ) ;
int V_19 ;
F_44 ( V_44 == NULL ) ;
F_10 ( L_16 , V_44 -> V_3 , V_47 ) ;
if ( V_54 -> V_55 < V_44 -> type -> V_56 ||
! ( V_54 -> V_4 == V_44 -> V_4 || V_44 -> V_4 == V_6 ) )
return 0 ;
F_41 ( & V_44 -> V_57 ) ;
V_19 = V_44 -> V_58 -> V_59 ( V_44 , V_50 , V_52 , V_62 , V_54 ) ;
F_42 ( & V_44 -> V_57 ) ;
return V_19 ;
}
int
F_51 ( T_4 V_47 , const struct V_49 * V_50 ,
const struct V_51 * V_52 ,
const struct V_53 * V_54 )
{
struct V_43 * V_44 = F_45 ( V_47 ) ;
int V_19 = 0 ;
F_44 ( V_44 == NULL ) ;
F_10 ( L_16 , V_44 -> V_3 , V_47 ) ;
if ( V_54 -> V_55 < V_44 -> type -> V_56 ||
! ( V_54 -> V_4 == V_44 -> V_4 || V_44 -> V_4 == V_6 ) )
return 0 ;
F_41 ( & V_44 -> V_57 ) ;
V_19 = V_44 -> V_58 -> V_59 ( V_44 , V_50 , V_52 , V_68 , V_54 ) ;
F_42 ( & V_44 -> V_57 ) ;
return V_19 ;
}
T_4
F_52 ( const char * V_3 , struct V_43 * * V_44 )
{
T_4 V_69 , V_47 = V_70 ;
struct V_43 * V_71 ;
F_15 () ;
for ( V_69 = 0 ; V_69 < V_72 ; V_69 ++ ) {
V_71 = F_46 ( V_48 ) [ V_69 ] ;
if ( V_71 != NULL && F_7 ( V_71 -> V_3 , V_3 ) ) {
F_40 ( V_71 ) ;
V_47 = V_69 ;
* V_44 = V_71 ;
break;
}
}
F_17 () ;
return V_47 ;
}
void
F_53 ( T_4 V_47 )
{
struct V_43 * V_44 ;
F_15 () ;
V_44 = F_46 ( V_48 ) [ V_47 ] ;
if ( V_44 != NULL )
F_43 ( V_44 ) ;
F_17 () ;
}
const char *
F_54 ( T_4 V_47 )
{
const struct V_43 * V_44 = F_45 ( V_47 ) ;
F_44 ( V_44 == NULL ) ;
F_44 ( V_44 -> V_46 == 0 ) ;
return V_44 -> V_3 ;
}
T_4
F_55 ( const char * V_3 )
{
T_4 V_69 , V_47 = V_70 ;
struct V_43 * V_71 ;
F_13 ( V_9 ) ;
for ( V_69 = 0 ; V_69 < V_72 ; V_69 ++ ) {
V_71 = F_56 ( V_69 ) ;
if ( V_71 != NULL && F_7 ( V_71 -> V_3 , V_3 ) ) {
F_40 ( V_71 ) ;
V_47 = V_69 ;
break;
}
}
F_9 ( V_9 ) ;
return V_47 ;
}
T_4
F_57 ( T_4 V_47 )
{
struct V_43 * V_44 ;
if ( V_47 > V_72 )
return V_70 ;
F_13 ( V_9 ) ;
V_44 = F_56 ( V_47 ) ;
if ( V_44 )
F_40 ( V_44 ) ;
else
V_47 = V_70 ;
F_9 ( V_9 ) ;
return V_47 ;
}
void
F_58 ( T_4 V_47 )
{
struct V_43 * V_44 ;
F_13 ( V_9 ) ;
V_44 = F_56 ( V_47 ) ;
if ( V_44 != NULL )
F_43 ( V_44 ) ;
F_9 ( V_9 ) ;
}
static inline bool
F_59 ( const struct V_30 * const V_35 [] )
{
return ! V_35 [ V_73 ] ||
F_60 ( V_35 [ V_73 ] ) != V_21 ;
}
static inline T_5
F_61 ( const struct V_74 * V_75 )
{
return V_75 -> V_76 & V_77 ? 0 : V_78 ;
}
static struct V_74 *
F_62 ( struct V_49 * V_50 , T_5 V_79 , T_5 V_80 , unsigned int V_63 ,
enum V_81 V_82 )
{
struct V_74 * V_75 ;
struct V_83 * V_84 ;
V_75 = F_63 ( V_50 , V_79 , V_80 , V_82 | ( V_9 << 8 ) ,
sizeof( * V_84 ) , V_63 ) ;
if ( V_75 == NULL )
return NULL ;
V_84 = F_64 ( V_75 ) ;
V_84 -> V_85 = V_86 ;
V_84 -> V_87 = V_88 ;
V_84 -> V_89 = 0 ;
return V_75 ;
}
static struct V_43 *
F_65 ( const char * V_3 , T_4 * V_90 )
{
struct V_43 * V_44 = NULL ;
T_4 V_69 ;
* V_90 = V_70 ;
for ( V_69 = 0 ; V_69 < V_72 ; V_69 ++ ) {
V_44 = F_56 ( V_69 ) ;
if ( V_44 != NULL && F_7 ( V_44 -> V_3 , V_3 ) ) {
* V_90 = V_69 ;
break;
}
}
return ( * V_90 == V_70 ? NULL : V_44 ) ;
}
static inline struct V_43 *
F_66 ( const char * V_3 )
{
T_4 V_90 ;
return F_65 ( V_3 , & V_90 ) ;
}
static int
F_67 ( const char * V_3 , T_4 * V_47 , struct V_43 * * V_44 )
{
struct V_43 * V_71 ;
T_4 V_69 ;
* V_47 = V_70 ;
for ( V_69 = 0 ; V_69 < V_72 ; V_69 ++ ) {
V_71 = F_56 ( V_69 ) ;
if ( V_71 == NULL ) {
if ( * V_47 == V_70 )
* V_47 = V_69 ;
} else if ( F_7 ( V_3 , V_71 -> V_3 ) ) {
* V_44 = V_71 ;
return - V_91 ;
}
}
if ( * V_47 == V_70 )
return - V_92 ;
return 0 ;
}
static int
F_68 ( struct V_93 * V_94 , struct V_49 * V_50 ,
const struct V_74 * V_75 ,
const struct V_30 * const V_95 [] )
{
return - V_96 ;
}
static int
F_69 ( struct V_93 * V_94 , struct V_49 * V_50 ,
const struct V_74 * V_75 ,
const struct V_30 * const V_95 [] )
{
struct V_43 * V_44 , * V_97 = NULL ;
T_4 V_47 = V_70 ;
struct V_30 * V_35 [ V_98 + 1 ] = {} ;
const char * V_3 , * V_99 ;
T_1 V_4 , V_5 ;
T_5 V_63 = F_61 ( V_75 ) ;
int V_19 = 0 ;
if ( F_34 ( F_59 ( V_95 ) ||
V_95 [ V_100 ] == NULL ||
V_95 [ V_101 ] == NULL ||
V_95 [ V_102 ] == NULL ||
V_95 [ V_103 ] == NULL ||
( V_95 [ V_104 ] != NULL &&
! F_32 ( V_95 [ V_104 ] ) ) ) )
return - V_37 ;
V_3 = F_39 ( V_95 [ V_100 ] ) ;
V_99 = F_39 ( V_95 [ V_101 ] ) ;
V_4 = F_60 ( V_95 [ V_103 ] ) ;
V_5 = F_60 ( V_95 [ V_102 ] ) ;
F_10 ( L_18 ,
V_3 , V_99 , F_20 ( V_4 ) , V_5 ) ;
V_44 = F_26 ( sizeof( struct V_43 ) , V_28 ) ;
if ( ! V_44 )
return - V_105 ;
F_70 ( & V_44 -> V_57 ) ;
F_71 ( V_44 -> V_3 , V_3 , V_106 ) ;
V_44 -> V_4 = V_4 ;
V_44 -> V_5 = V_5 ;
V_19 = F_72 ( V_99 , V_4 , V_5 , & ( V_44 -> type ) ) ;
if ( V_19 )
goto V_107;
if ( V_95 [ V_104 ] &&
F_35 ( V_35 , V_98 , V_95 [ V_104 ] ,
V_44 -> type -> V_108 ) ) {
V_19 = - V_37 ;
goto V_109;
}
V_19 = V_44 -> type -> V_110 ( V_44 , V_35 , V_63 ) ;
if ( V_19 != 0 )
goto V_109;
V_19 = F_67 ( V_44 -> V_3 , & V_47 , & V_97 ) ;
if ( V_19 == - V_91 ) {
if ( ( V_63 & V_78 ) &&
F_7 ( V_44 -> type -> V_3 , V_97 -> type -> V_3 ) &&
V_44 -> type -> V_4 == V_97 -> type -> V_4 &&
V_44 -> type -> V_7 == V_97 -> type -> V_7 &&
V_44 -> type -> V_8 == V_97 -> type -> V_8 &&
V_44 -> V_58 -> V_111 ( V_44 , V_97 ) )
V_19 = 0 ;
goto V_112;
} else if ( V_19 == - V_92 ) {
struct V_43 * * V_23 , * * V_113 ;
T_4 V_69 = V_72 + V_114 ;
if ( V_69 < V_72 || V_69 == V_70 )
goto V_112;
V_23 = F_26 ( sizeof( struct V_43 * ) * V_69 , V_28 ) ;
if ( ! V_23 )
goto V_112;
V_113 = F_73 ( V_48 ) ;
memcpy ( V_23 , V_113 , sizeof( struct V_43 * ) * V_72 ) ;
F_74 ( V_48 , V_23 ) ;
F_75 () ;
V_47 = V_72 ;
V_72 = V_69 ;
F_31 ( V_113 ) ;
V_19 = 0 ;
} else if ( V_19 )
goto V_112;
F_10 ( L_19 , V_44 -> V_3 , V_47 ) ;
F_56 ( V_47 ) = V_44 ;
return V_19 ;
V_112:
V_44 -> V_58 -> V_115 ( V_44 ) ;
V_109:
F_76 ( V_44 -> type -> V_14 ) ;
V_107:
F_31 ( V_44 ) ;
return V_19 ;
}
static void
F_77 ( T_4 V_47 )
{
struct V_43 * V_44 = F_56 ( V_47 ) ;
F_10 ( L_20 , V_44 -> V_3 ) ;
F_56 ( V_47 ) = NULL ;
V_44 -> V_58 -> V_115 ( V_44 ) ;
F_76 ( V_44 -> type -> V_14 ) ;
F_31 ( V_44 ) ;
}
static int
F_78 ( struct V_93 * V_94 , struct V_49 * V_50 ,
const struct V_74 * V_75 ,
const struct V_30 * const V_95 [] )
{
struct V_43 * V_71 ;
T_4 V_69 ;
int V_19 = 0 ;
if ( F_34 ( F_59 ( V_95 ) ) )
return - V_37 ;
F_48 ( & V_45 ) ;
if ( ! V_95 [ V_100 ] ) {
for ( V_69 = 0 ; V_69 < V_72 ; V_69 ++ ) {
V_71 = F_56 ( V_69 ) ;
if ( V_71 != NULL && V_71 -> V_46 ) {
V_19 = - V_116 ;
goto V_107;
}
}
F_49 ( & V_45 ) ;
for ( V_69 = 0 ; V_69 < V_72 ; V_69 ++ ) {
V_71 = F_56 ( V_69 ) ;
if ( V_71 != NULL )
F_77 ( V_69 ) ;
}
} else {
V_71 = F_65 ( F_39 ( V_95 [ V_100 ] ) , & V_69 ) ;
if ( V_71 == NULL ) {
V_19 = - V_117 ;
goto V_107;
} else if ( V_71 -> V_46 ) {
V_19 = - V_116 ;
goto V_107;
}
F_49 ( & V_45 ) ;
F_77 ( V_69 ) ;
}
return 0 ;
V_107:
F_49 ( & V_45 ) ;
return V_19 ;
}
static void
F_79 ( struct V_43 * V_44 )
{
F_10 ( L_20 , V_44 -> V_3 ) ;
F_41 ( & V_44 -> V_57 ) ;
V_44 -> V_58 -> V_118 ( V_44 ) ;
F_42 ( & V_44 -> V_57 ) ;
}
static int
F_80 ( struct V_93 * V_94 , struct V_49 * V_50 ,
const struct V_74 * V_75 ,
const struct V_30 * const V_95 [] )
{
struct V_43 * V_71 ;
T_4 V_69 ;
if ( F_34 ( F_59 ( V_95 ) ) )
return - V_37 ;
if ( ! V_95 [ V_100 ] ) {
for ( V_69 = 0 ; V_69 < V_72 ; V_69 ++ ) {
V_71 = F_56 ( V_69 ) ;
if ( V_71 != NULL )
F_79 ( V_71 ) ;
}
} else {
V_71 = F_66 ( F_39 ( V_95 [ V_100 ] ) ) ;
if ( V_71 == NULL )
return - V_117 ;
F_79 ( V_71 ) ;
}
return 0 ;
}
static int
F_81 ( struct V_93 * V_94 , struct V_49 * V_50 ,
const struct V_74 * V_75 ,
const struct V_30 * const V_95 [] )
{
struct V_43 * V_44 , * V_71 ;
const char * V_119 ;
T_4 V_69 ;
int V_19 = 0 ;
if ( F_34 ( F_59 ( V_95 ) ||
V_95 [ V_100 ] == NULL ||
V_95 [ V_120 ] == NULL ) )
return - V_37 ;
V_44 = F_66 ( F_39 ( V_95 [ V_100 ] ) ) ;
if ( V_44 == NULL )
return - V_117 ;
F_48 ( & V_45 ) ;
if ( V_44 -> V_46 != 0 ) {
V_19 = - V_121 ;
goto V_107;
}
V_119 = F_39 ( V_95 [ V_120 ] ) ;
for ( V_69 = 0 ; V_69 < V_72 ; V_69 ++ ) {
V_71 = F_56 ( V_69 ) ;
if ( V_71 != NULL && F_7 ( V_71 -> V_3 , V_119 ) ) {
V_19 = - V_122 ;
goto V_107;
}
}
strncpy ( V_44 -> V_3 , V_119 , V_106 ) ;
V_107:
F_49 ( & V_45 ) ;
return V_19 ;
}
static int
F_82 ( struct V_93 * V_94 , struct V_49 * V_50 ,
const struct V_74 * V_75 ,
const struct V_30 * const V_95 [] )
{
struct V_43 * V_123 , * V_124 ;
T_4 V_125 , V_126 ;
char V_127 [ V_106 ] ;
if ( F_34 ( F_59 ( V_95 ) ||
V_95 [ V_100 ] == NULL ||
V_95 [ V_120 ] == NULL ) )
return - V_37 ;
V_123 = F_65 ( F_39 ( V_95 [ V_100 ] ) , & V_125 ) ;
if ( V_123 == NULL )
return - V_117 ;
V_124 = F_65 ( F_39 ( V_95 [ V_120 ] ) , & V_126 ) ;
if ( V_124 == NULL )
return - V_122 ;
if ( ! ( V_123 -> type -> V_65 == V_124 -> type -> V_65 &&
V_123 -> type -> V_4 == V_124 -> type -> V_4 ) )
return - V_128 ;
strncpy ( V_127 , V_123 -> V_3 , V_106 ) ;
strncpy ( V_123 -> V_3 , V_124 -> V_3 , V_106 ) ;
strncpy ( V_124 -> V_3 , V_127 , V_106 ) ;
F_41 ( & V_45 ) ;
F_83 ( V_123 -> V_46 , V_124 -> V_46 ) ;
F_56 ( V_125 ) = V_124 ;
F_56 ( V_126 ) = V_123 ;
F_42 ( & V_45 ) ;
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
F_85 ( struct V_74 * V_75 )
{
const struct V_30 * V_95 ;
int V_131 ;
F_10 ( L_22 ) ;
F_86 (attr, nlh, sizeof(struct nfgenmsg), rem) {
F_10 ( L_23 , V_32 ( V_95 ) , V_95 -> V_132 ) ;
}
}
static int
F_87 ( struct V_129 * V_130 )
{
struct V_74 * V_75 = F_88 ( V_130 -> V_50 ) ;
int V_133 = F_89 ( sizeof( struct V_83 ) ) ;
struct V_30 * V_134 [ V_135 + 1 ] ;
struct V_30 * V_95 = ( void * ) V_75 + V_133 ;
T_5 V_136 ;
T_4 V_47 ;
F_90 ( V_134 , V_135 ,
V_95 , V_75 -> V_137 - V_133 , V_138 ) ;
if ( V_134 [ V_100 ] ) {
struct V_43 * V_44 ;
V_44 = F_65 ( F_39 ( V_134 [ V_100 ] ) ,
& V_47 ) ;
if ( V_44 == NULL )
return - V_117 ;
V_136 = V_139 ;
V_130 -> args [ 1 ] = V_47 ;
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
F_92 ( struct V_49 * V_50 , struct V_129 * V_130 )
{
T_4 V_47 = V_70 , V_18 ;
struct V_43 * V_44 = NULL ;
struct V_74 * V_75 = NULL ;
unsigned int V_63 = F_93 ( V_130 -> V_50 ) . V_79 ? V_143 : 0 ;
T_5 V_136 , V_144 ;
int V_19 = 0 ;
if ( ! V_130 -> args [ 0 ] ) {
V_19 = F_87 ( V_130 ) ;
if ( V_19 < 0 ) {
V_75 = F_88 ( V_130 -> V_50 ) ;
if ( V_75 -> V_76 & V_145 )
F_94 ( V_130 -> V_50 , V_75 , V_19 ) ;
return V_19 ;
}
}
if ( V_130 -> args [ 1 ] >= V_72 )
goto V_107;
V_136 = F_95 ( V_130 -> args [ 0 ] ) ;
V_144 = F_96 ( V_130 -> args [ 0 ] ) ;
V_18 = V_136 == V_139 ? V_130 -> args [ 1 ] + 1 : V_72 ;
V_146:
F_10 ( L_24 ,
V_136 , V_144 , V_130 -> args [ 1 ] ) ;
for (; V_130 -> args [ 1 ] < V_18 ; V_130 -> args [ 1 ] ++ ) {
V_47 = ( T_4 ) V_130 -> args [ 1 ] ;
V_44 = F_56 ( V_47 ) ;
if ( V_44 == NULL ) {
if ( V_136 == V_139 ) {
V_19 = - V_117 ;
goto V_107;
}
continue;
}
if ( V_136 != V_139 &&
( ( V_136 == V_140 ) ==
! ! ( V_44 -> type -> V_65 & V_147 ) ) )
continue;
F_10 ( L_25 , V_44 -> V_3 ) ;
if ( ! V_130 -> args [ 2 ] ) {
F_10 ( L_26 ) ;
F_40 ( V_44 ) ;
}
V_75 = F_62 ( V_50 , F_93 ( V_130 -> V_50 ) . V_79 ,
V_130 -> V_75 -> V_148 , V_63 ,
V_149 ) ;
if ( ! V_75 ) {
V_19 = - V_150 ;
goto V_151;
}
if ( F_97 ( V_50 , V_73 , V_21 ) ||
F_98 ( V_50 , V_100 , V_44 -> V_3 ) )
goto V_152;
if ( V_144 & V_153 )
goto V_154;
switch ( V_130 -> args [ 2 ] ) {
case 0 :
if ( F_98 ( V_50 , V_101 ,
V_44 -> type -> V_3 ) ||
F_97 ( V_50 , V_103 ,
V_44 -> V_4 ) ||
F_97 ( V_50 , V_102 ,
V_44 -> V_5 ) )
goto V_152;
V_19 = V_44 -> V_58 -> V_155 ( V_44 , V_50 ) ;
if ( V_19 < 0 )
goto V_151;
if ( V_144 & V_156 )
goto V_154;
default:
F_48 ( & V_44 -> V_57 ) ;
V_19 = V_44 -> V_58 -> V_23 ( V_44 , V_50 , V_130 ) ;
F_49 ( & V_44 -> V_57 ) ;
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
V_19 = - V_15 ;
V_154:
if ( V_136 == V_139 )
V_130 -> args [ 1 ] = V_70 ;
else
V_130 -> args [ 1 ] ++ ;
V_151:
if ( V_19 || ! V_130 -> args [ 2 ] ) {
F_10 ( L_21 , F_56 ( V_47 ) -> V_3 ) ;
F_53 ( V_47 ) ;
V_130 -> args [ 2 ] = 0 ;
}
V_107:
if ( V_75 ) {
F_99 ( V_50 , V_75 ) ;
F_10 ( L_27 , V_75 -> V_137 ) ;
F_85 ( V_75 ) ;
}
return V_19 < 0 ? V_19 : V_50 -> V_158 ;
}
static int
F_100 ( struct V_93 * V_94 , struct V_49 * V_50 ,
const struct V_74 * V_75 ,
const struct V_30 * const V_95 [] )
{
if ( F_34 ( F_59 ( V_95 ) ) )
return - V_37 ;
{
struct V_159 V_160 = {
. V_161 = F_92 ,
. V_162 = F_84 ,
} ;
return F_101 ( V_94 , V_50 , V_75 , & V_160 ) ;
}
}
static int
F_102 ( struct V_93 * V_94 , struct V_49 * V_50 , struct V_43 * V_44 ,
struct V_30 * V_35 [] , enum V_163 V_164 ,
T_5 V_63 , bool V_165 )
{
int V_19 ;
T_5 V_166 = 0 ;
bool V_167 = V_63 & V_78 , V_168 = false ;
do {
F_41 ( & V_44 -> V_57 ) ;
V_19 = V_44 -> V_58 -> V_169 ( V_44 , V_35 , V_164 , & V_166 , V_63 , V_168 ) ;
F_42 ( & V_44 -> V_57 ) ;
V_168 = true ;
} while ( V_19 == - V_61 &&
V_44 -> V_58 -> V_170 &&
( V_19 = V_44 -> V_58 -> V_170 ( V_44 , V_168 ) ) == 0 );
if ( ! V_19 || ( V_19 == - V_171 && V_167 ) )
return 0 ;
if ( V_166 && V_165 ) {
struct V_74 * V_172 , * V_75 = F_88 ( V_50 ) ;
struct V_49 * V_173 ;
struct V_174 * V_175 ;
T_2 V_176 = sizeof( * V_175 ) + V_137 ( V_75 ) ;
int V_133 = F_89 ( sizeof( struct V_83 ) ) ;
struct V_30 * V_134 [ V_135 + 1 ] ;
struct V_30 * V_177 ;
T_5 * V_178 ;
V_173 = F_103 ( V_176 , V_28 ) ;
if ( V_173 == NULL )
return - V_105 ;
V_172 = F_104 ( V_173 , F_93 ( V_50 ) . V_79 ,
V_75 -> V_148 , V_179 , V_176 , 0 ) ;
V_175 = F_64 ( V_172 ) ;
V_175 -> error = V_19 ;
memcpy ( & V_175 -> V_180 , V_75 , V_75 -> V_137 ) ;
V_177 = ( void * ) & V_175 -> V_180 + V_133 ;
F_90 ( V_134 , V_135 ,
V_177 , V_75 -> V_137 - V_133 ,
V_181 ) ;
V_178 = F_39 ( V_134 [ V_182 ] ) ;
* V_178 = V_166 ;
F_105 ( V_94 , V_173 , F_93 ( V_50 ) . V_79 , V_183 ) ;
return - V_184 ;
}
return V_19 ;
}
static int
F_106 ( struct V_93 * V_94 , struct V_49 * V_50 ,
const struct V_74 * V_75 ,
const struct V_30 * const V_95 [] )
{
struct V_43 * V_44 ;
struct V_30 * V_35 [ V_185 + 1 ] = {} ;
const struct V_30 * V_31 ;
T_5 V_63 = F_61 ( V_75 ) ;
bool V_165 ;
int V_19 = 0 ;
if ( F_34 ( F_59 ( V_95 ) ||
V_95 [ V_100 ] == NULL ||
! ( ( V_95 [ V_104 ] != NULL ) ^
( V_95 [ V_186 ] != NULL ) ) ||
( V_95 [ V_104 ] != NULL &&
! F_32 ( V_95 [ V_104 ] ) ) ||
( V_95 [ V_186 ] != NULL &&
( ! F_32 ( V_95 [ V_186 ] ) ||
V_95 [ V_182 ] == NULL ) ) ) )
return - V_37 ;
V_44 = F_66 ( F_39 ( V_95 [ V_100 ] ) ) ;
if ( V_44 == NULL )
return - V_117 ;
V_165 = ! ! V_95 [ V_182 ] ;
if ( V_95 [ V_104 ] ) {
if ( F_35 ( V_35 , V_185 ,
V_95 [ V_104 ] ,
V_44 -> type -> V_187 ) )
return - V_37 ;
V_19 = F_102 ( V_94 , V_50 , V_44 , V_35 , V_62 , V_63 ,
V_165 ) ;
} else {
int V_188 ;
F_107 (nla, attr[IPSET_ATTR_ADT], nla_rem) {
memset ( V_35 , 0 , sizeof( V_35 ) ) ;
if ( V_32 ( V_31 ) != V_104 ||
! F_32 ( V_31 ) ||
F_35 ( V_35 , V_185 , V_31 ,
V_44 -> type -> V_187 ) )
return - V_37 ;
V_19 = F_102 ( V_94 , V_50 , V_44 , V_35 , V_62 ,
V_63 , V_165 ) ;
if ( V_19 < 0 )
return V_19 ;
}
}
return V_19 ;
}
static int
F_108 ( struct V_93 * V_94 , struct V_49 * V_50 ,
const struct V_74 * V_75 ,
const struct V_30 * const V_95 [] )
{
struct V_43 * V_44 ;
struct V_30 * V_35 [ V_185 + 1 ] = {} ;
const struct V_30 * V_31 ;
T_5 V_63 = F_61 ( V_75 ) ;
bool V_165 ;
int V_19 = 0 ;
if ( F_34 ( F_59 ( V_95 ) ||
V_95 [ V_100 ] == NULL ||
! ( ( V_95 [ V_104 ] != NULL ) ^
( V_95 [ V_186 ] != NULL ) ) ||
( V_95 [ V_104 ] != NULL &&
! F_32 ( V_95 [ V_104 ] ) ) ||
( V_95 [ V_186 ] != NULL &&
( ! F_32 ( V_95 [ V_186 ] ) ||
V_95 [ V_182 ] == NULL ) ) ) )
return - V_37 ;
V_44 = F_66 ( F_39 ( V_95 [ V_100 ] ) ) ;
if ( V_44 == NULL )
return - V_117 ;
V_165 = ! ! V_95 [ V_182 ] ;
if ( V_95 [ V_104 ] ) {
if ( F_35 ( V_35 , V_185 ,
V_95 [ V_104 ] ,
V_44 -> type -> V_187 ) )
return - V_37 ;
V_19 = F_102 ( V_94 , V_50 , V_44 , V_35 , V_68 , V_63 ,
V_165 ) ;
} else {
int V_188 ;
F_107 (nla, attr[IPSET_ATTR_ADT], nla_rem) {
memset ( V_35 , 0 , sizeof( * V_35 ) ) ;
if ( V_32 ( V_31 ) != V_104 ||
! F_32 ( V_31 ) ||
F_35 ( V_35 , V_185 , V_31 ,
V_44 -> type -> V_187 ) )
return - V_37 ;
V_19 = F_102 ( V_94 , V_50 , V_44 , V_35 , V_68 ,
V_63 , V_165 ) ;
if ( V_19 < 0 )
return V_19 ;
}
}
return V_19 ;
}
static int
F_109 ( struct V_93 * V_94 , struct V_49 * V_50 ,
const struct V_74 * V_75 ,
const struct V_30 * const V_95 [] )
{
struct V_43 * V_44 ;
struct V_30 * V_35 [ V_185 + 1 ] = {} ;
int V_19 = 0 ;
if ( F_34 ( F_59 ( V_95 ) ||
V_95 [ V_100 ] == NULL ||
V_95 [ V_104 ] == NULL ||
! F_32 ( V_95 [ V_104 ] ) ) )
return - V_37 ;
V_44 = F_66 ( F_39 ( V_95 [ V_100 ] ) ) ;
if ( V_44 == NULL )
return - V_117 ;
if ( F_35 ( V_35 , V_185 , V_95 [ V_104 ] ,
V_44 -> type -> V_187 ) )
return - V_37 ;
F_48 ( & V_44 -> V_57 ) ;
V_19 = V_44 -> V_58 -> V_169 ( V_44 , V_35 , V_60 , NULL , 0 , 0 ) ;
F_49 ( & V_44 -> V_57 ) ;
if ( V_19 == - V_61 )
V_19 = 1 ;
return ( V_19 < 0 && V_19 != - V_67 ) ? V_19 :
V_19 > 0 ? 0 : - V_171 ;
}
static int
F_110 ( struct V_93 * V_94 , struct V_49 * V_50 ,
const struct V_74 * V_75 ,
const struct V_30 * const V_95 [] )
{
const struct V_43 * V_44 ;
struct V_49 * V_173 ;
struct V_74 * V_189 ;
int V_19 = 0 ;
if ( F_34 ( F_59 ( V_95 ) ||
V_95 [ V_100 ] == NULL ) )
return - V_37 ;
V_44 = F_66 ( F_39 ( V_95 [ V_100 ] ) ) ;
if ( V_44 == NULL )
return - V_117 ;
V_173 = F_103 ( V_190 , V_28 ) ;
if ( V_173 == NULL )
return - V_105 ;
V_189 = F_62 ( V_173 , F_93 ( V_50 ) . V_79 , V_75 -> V_148 , 0 ,
V_191 ) ;
if ( ! V_189 )
goto V_192;
if ( F_97 ( V_173 , V_73 , V_21 ) ||
F_98 ( V_173 , V_100 , V_44 -> V_3 ) ||
F_98 ( V_173 , V_101 , V_44 -> type -> V_3 ) ||
F_97 ( V_173 , V_103 , V_44 -> V_4 ) ||
F_97 ( V_173 , V_102 , V_44 -> V_5 ) )
goto V_152;
F_99 ( V_173 , V_189 ) ;
V_19 = F_105 ( V_94 , V_173 , F_93 ( V_50 ) . V_79 , V_183 ) ;
if ( V_19 < 0 )
return V_19 ;
return 0 ;
V_152:
F_111 ( V_173 , V_189 ) ;
V_192:
F_112 ( V_173 ) ;
return - V_150 ;
}
static int
V_2 ( struct V_93 * V_94 , struct V_49 * V_50 ,
const struct V_74 * V_75 ,
const struct V_30 * const V_95 [] )
{
struct V_49 * V_173 ;
struct V_74 * V_189 ;
T_1 V_4 , V_17 , V_18 ;
const char * V_99 ;
int V_19 = 0 ;
if ( F_34 ( F_59 ( V_95 ) ||
V_95 [ V_101 ] == NULL ||
V_95 [ V_103 ] == NULL ) )
return - V_37 ;
V_4 = F_60 ( V_95 [ V_103 ] ) ;
V_99 = F_39 ( V_95 [ V_101 ] ) ;
V_19 = F_113 ( V_99 , V_4 , & V_17 , & V_18 ) ;
if ( V_19 )
return V_19 ;
V_173 = F_103 ( V_190 , V_28 ) ;
if ( V_173 == NULL )
return - V_105 ;
V_189 = F_62 ( V_173 , F_93 ( V_50 ) . V_79 , V_75 -> V_148 , 0 ,
V_193 ) ;
if ( ! V_189 )
goto V_192;
if ( F_97 ( V_173 , V_73 , V_21 ) ||
F_98 ( V_173 , V_101 , V_99 ) ||
F_97 ( V_173 , V_103 , V_4 ) ||
F_97 ( V_173 , V_102 , V_18 ) ||
F_97 ( V_173 , V_194 , V_17 ) )
goto V_152;
F_99 ( V_173 , V_189 ) ;
F_10 ( L_28 , V_189 -> V_137 ) ;
V_19 = F_105 ( V_94 , V_173 , F_93 ( V_50 ) . V_79 , V_183 ) ;
if ( V_19 < 0 )
return V_19 ;
return 0 ;
V_152:
F_111 ( V_173 , V_189 ) ;
V_192:
F_112 ( V_173 ) ;
return - V_150 ;
}
static int
F_114 ( struct V_93 * V_94 , struct V_49 * V_50 ,
const struct V_74 * V_75 ,
const struct V_30 * const V_95 [] )
{
struct V_49 * V_173 ;
struct V_74 * V_189 ;
int V_19 = 0 ;
if ( F_34 ( V_95 [ V_73 ] == NULL ) )
return - V_37 ;
V_173 = F_103 ( V_190 , V_28 ) ;
if ( V_173 == NULL )
return - V_105 ;
V_189 = F_62 ( V_173 , F_93 ( V_50 ) . V_79 , V_75 -> V_148 , 0 ,
V_195 ) ;
if ( ! V_189 )
goto V_192;
if ( F_97 ( V_173 , V_73 , V_21 ) )
goto V_152;
F_99 ( V_173 , V_189 ) ;
V_19 = F_105 ( V_94 , V_173 , F_93 ( V_50 ) . V_79 , V_183 ) ;
if ( V_19 < 0 )
return V_19 ;
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
int V_201 = * V_158 , V_19 = 0 ;
if ( ! F_116 ( F_117 ( V_196 ) -> V_202 , V_203 ) )
return - V_204 ;
if ( V_197 != V_205 )
return - V_206 ;
if ( * V_158 < sizeof( unsigned int ) )
return - V_22 ;
V_200 = F_118 ( * V_158 ) ;
if ( ! V_200 )
return - V_105 ;
if ( F_119 ( V_200 , V_198 , * V_158 ) != 0 ) {
V_19 = - V_15 ;
goto V_162;
}
V_199 = ( unsigned int * ) V_200 ;
if ( * V_199 < V_207 ) {
struct V_208 * V_209 = V_200 ;
if ( V_209 -> V_87 != V_21 ) {
V_19 = - V_210 ;
goto V_162;
}
}
switch ( * V_199 ) {
case V_207 : {
struct V_208 * V_209 = V_200 ;
if ( * V_158 != sizeof( struct V_208 ) ) {
V_19 = - V_22 ;
goto V_162;
}
V_209 -> V_87 = V_21 ;
V_19 = F_120 ( V_198 , V_209 ,
sizeof( struct V_208 ) ) ;
goto V_162;
}
case V_211 : {
struct V_212 * V_213 = V_200 ;
T_4 V_90 ;
if ( * V_158 != sizeof( struct V_212 ) ) {
V_19 = - V_22 ;
goto V_162;
}
V_213 -> V_44 . V_3 [ V_106 - 1 ] = '\0' ;
F_13 ( V_9 ) ;
F_65 ( V_213 -> V_44 . V_3 , & V_90 ) ;
V_213 -> V_44 . V_47 = V_90 ;
F_9 ( V_9 ) ;
goto V_214;
}
case V_215 : {
struct V_212 * V_213 = V_200 ;
struct V_43 * V_44 ;
if ( * V_158 != sizeof( struct V_212 ) ||
V_213 -> V_44 . V_47 >= V_72 ) {
V_19 = - V_22 ;
goto V_162;
}
F_13 ( V_9 ) ;
V_44 = F_56 ( V_213 -> V_44 . V_47 ) ;
strncpy ( V_213 -> V_44 . V_3 , V_44 ? V_44 -> V_3 : L_29 ,
V_106 ) ;
F_9 ( V_9 ) ;
goto V_214;
}
default:
V_19 = - V_216 ;
goto V_162;
}
V_214:
V_19 = F_120 ( V_198 , V_200 , V_201 ) ;
V_162:
F_30 ( V_200 ) ;
if ( V_19 > 0 )
V_19 = 0 ;
return V_19 ;
}
static int T_7
F_121 ( void )
{
struct V_43 * * V_23 ;
int V_19 ;
if ( V_217 )
V_72 = V_217 ;
if ( V_72 >= V_70 )
V_72 = V_70 - 1 ;
V_23 = F_26 ( sizeof( struct V_43 * ) * V_72 , V_28 ) ;
if ( ! V_23 )
return - V_105 ;
F_74 ( V_48 , V_23 ) ;
V_19 = F_122 ( & V_218 ) ;
if ( V_19 != 0 ) {
F_123 ( L_30 ) ;
F_31 ( V_23 ) ;
return V_19 ;
}
V_19 = F_124 ( & V_219 ) ;
if ( V_19 != 0 ) {
F_123 ( L_31 , V_19 ) ;
F_125 ( & V_218 ) ;
F_31 ( V_23 ) ;
return V_19 ;
}
F_126 ( L_32 , V_21 ) ;
return 0 ;
}
static void T_8
F_127 ( void )
{
struct V_43 * * V_23 = F_128 ( V_48 , 1 ) ;
F_129 ( & V_219 ) ;
F_125 ( & V_218 ) ;
F_31 ( V_23 ) ;
F_10 ( L_33 ) ;
}
