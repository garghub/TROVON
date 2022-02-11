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
int
F_40 ( struct V_43 * V_44 , struct V_30 * V_35 [] ,
struct V_45 * V_46 )
{
if ( V_35 [ V_47 ] ) {
if ( ! ( V_44 -> V_48 & V_49 ) )
return - V_50 ;
V_46 -> V_51 = F_41 ( V_35 [ V_47 ] ) ;
}
if ( V_35 [ V_52 ] || V_35 [ V_53 ] ) {
if ( ! ( V_44 -> V_48 & V_54 ) )
return - V_55 ;
if ( V_35 [ V_52 ] )
V_46 -> V_56 = F_42 ( F_43 (
V_35 [ V_52 ] ) ) ;
if ( V_35 [ V_53 ] )
V_46 -> V_57 = F_42 ( F_43 (
V_35 [ V_53 ] ) ) ;
}
return 0 ;
}
static inline void
F_44 ( struct V_43 * V_44 )
{
F_45 ( & V_58 ) ;
V_44 -> V_59 ++ ;
F_46 ( & V_58 ) ;
}
static inline void
F_47 ( struct V_43 * V_44 )
{
F_45 ( & V_58 ) ;
F_48 ( V_44 -> V_59 == 0 ) ;
V_44 -> V_59 -- ;
F_46 ( & V_58 ) ;
}
static inline struct V_43 *
F_49 ( T_4 V_60 )
{
struct V_43 * V_44 ;
F_15 () ;
V_44 = F_50 ( V_61 ) [ V_60 ] ;
F_17 () ;
return V_44 ;
}
int
F_51 ( T_4 V_60 , const struct V_62 * V_63 ,
const struct V_64 * V_65 , struct V_66 * V_67 )
{
struct V_43 * V_44 = F_49 ( V_60 ) ;
int V_19 = 0 ;
F_48 ( V_44 == NULL ) ;
F_10 ( L_16 , V_44 -> V_3 , V_60 ) ;
if ( V_67 -> V_68 < V_44 -> type -> V_69 ||
! ( V_67 -> V_4 == V_44 -> V_4 || V_44 -> V_4 == V_6 ) )
return 0 ;
F_52 ( & V_44 -> V_70 ) ;
V_19 = V_44 -> V_71 -> V_72 ( V_44 , V_63 , V_65 , V_73 , V_67 ) ;
F_53 ( & V_44 -> V_70 ) ;
if ( V_19 == - V_74 ) {
F_10 ( L_17 ) ;
F_45 ( & V_44 -> V_70 ) ;
V_44 -> V_71 -> V_72 ( V_44 , V_63 , V_65 , V_75 , V_67 ) ;
F_46 ( & V_44 -> V_70 ) ;
V_19 = 1 ;
} else {
if ( ( V_67 -> V_76 & V_77 ) &&
( V_44 -> type -> V_78 & V_79 ) &&
( V_19 > 0 || V_19 == - V_80 ) )
V_19 = - V_19 ;
}
return ( V_19 < 0 ? 0 : V_19 ) ;
}
int
F_54 ( T_4 V_60 , const struct V_62 * V_63 ,
const struct V_64 * V_65 , struct V_66 * V_67 )
{
struct V_43 * V_44 = F_49 ( V_60 ) ;
int V_19 ;
F_48 ( V_44 == NULL ) ;
F_10 ( L_16 , V_44 -> V_3 , V_60 ) ;
if ( V_67 -> V_68 < V_44 -> type -> V_69 ||
! ( V_67 -> V_4 == V_44 -> V_4 || V_44 -> V_4 == V_6 ) )
return 0 ;
F_45 ( & V_44 -> V_70 ) ;
V_19 = V_44 -> V_71 -> V_72 ( V_44 , V_63 , V_65 , V_75 , V_67 ) ;
F_46 ( & V_44 -> V_70 ) ;
return V_19 ;
}
int
F_55 ( T_4 V_60 , const struct V_62 * V_63 ,
const struct V_64 * V_65 , struct V_66 * V_67 )
{
struct V_43 * V_44 = F_49 ( V_60 ) ;
int V_19 = 0 ;
F_48 ( V_44 == NULL ) ;
F_10 ( L_16 , V_44 -> V_3 , V_60 ) ;
if ( V_67 -> V_68 < V_44 -> type -> V_69 ||
! ( V_67 -> V_4 == V_44 -> V_4 || V_44 -> V_4 == V_6 ) )
return 0 ;
F_45 ( & V_44 -> V_70 ) ;
V_19 = V_44 -> V_71 -> V_72 ( V_44 , V_63 , V_65 , V_81 , V_67 ) ;
F_46 ( & V_44 -> V_70 ) ;
return V_19 ;
}
T_4
F_56 ( const char * V_3 , struct V_43 * * V_44 )
{
T_4 V_82 , V_60 = V_83 ;
struct V_43 * V_84 ;
F_15 () ;
for ( V_82 = 0 ; V_82 < V_85 ; V_82 ++ ) {
V_84 = F_50 ( V_61 ) [ V_82 ] ;
if ( V_84 != NULL && F_7 ( V_84 -> V_3 , V_3 ) ) {
F_44 ( V_84 ) ;
V_60 = V_82 ;
* V_44 = V_84 ;
break;
}
}
F_17 () ;
return V_60 ;
}
void
F_57 ( T_4 V_60 )
{
struct V_43 * V_44 ;
F_15 () ;
V_44 = F_50 ( V_61 ) [ V_60 ] ;
if ( V_44 != NULL )
F_47 ( V_44 ) ;
F_17 () ;
}
const char *
F_58 ( T_4 V_60 )
{
const struct V_43 * V_44 = F_49 ( V_60 ) ;
F_48 ( V_44 == NULL ) ;
F_48 ( V_44 -> V_59 == 0 ) ;
return V_44 -> V_3 ;
}
T_4
F_59 ( const char * V_3 )
{
T_4 V_82 , V_60 = V_83 ;
struct V_43 * V_84 ;
F_13 ( V_9 ) ;
for ( V_82 = 0 ; V_82 < V_85 ; V_82 ++ ) {
V_84 = F_60 ( V_82 ) ;
if ( V_84 != NULL && F_7 ( V_84 -> V_3 , V_3 ) ) {
F_44 ( V_84 ) ;
V_60 = V_82 ;
break;
}
}
F_9 ( V_9 ) ;
return V_60 ;
}
T_4
F_61 ( T_4 V_60 )
{
struct V_43 * V_44 ;
if ( V_60 > V_85 )
return V_83 ;
F_13 ( V_9 ) ;
V_44 = F_60 ( V_60 ) ;
if ( V_44 )
F_44 ( V_44 ) ;
else
V_60 = V_83 ;
F_9 ( V_9 ) ;
return V_60 ;
}
void
F_62 ( T_4 V_60 )
{
struct V_43 * V_44 ;
F_13 ( V_9 ) ;
V_44 = F_60 ( V_60 ) ;
if ( V_44 != NULL )
F_47 ( V_44 ) ;
F_9 ( V_9 ) ;
}
static inline bool
F_63 ( const struct V_30 * const V_35 [] )
{
return ! V_35 [ V_86 ] ||
F_64 ( V_35 [ V_86 ] ) != V_21 ;
}
static inline T_5
F_65 ( const struct V_87 * V_88 )
{
return V_88 -> V_89 & V_90 ? 0 : V_91 ;
}
static struct V_87 *
F_66 ( struct V_62 * V_63 , T_5 V_92 , T_5 V_93 , unsigned int V_94 ,
enum V_95 V_96 )
{
struct V_87 * V_88 ;
struct V_97 * V_98 ;
V_88 = F_67 ( V_63 , V_92 , V_93 , V_96 | ( V_9 << 8 ) ,
sizeof( * V_98 ) , V_94 ) ;
if ( V_88 == NULL )
return NULL ;
V_98 = F_68 ( V_88 ) ;
V_98 -> V_99 = V_100 ;
V_98 -> V_101 = V_102 ;
V_98 -> V_103 = 0 ;
return V_88 ;
}
static struct V_43 *
F_69 ( const char * V_3 , T_4 * V_104 )
{
struct V_43 * V_44 = NULL ;
T_4 V_82 ;
* V_104 = V_83 ;
for ( V_82 = 0 ; V_82 < V_85 ; V_82 ++ ) {
V_44 = F_60 ( V_82 ) ;
if ( V_44 != NULL && F_7 ( V_44 -> V_3 , V_3 ) ) {
* V_104 = V_82 ;
break;
}
}
return ( * V_104 == V_83 ? NULL : V_44 ) ;
}
static inline struct V_43 *
F_70 ( const char * V_3 )
{
T_4 V_104 ;
return F_69 ( V_3 , & V_104 ) ;
}
static int
F_71 ( const char * V_3 , T_4 * V_60 , struct V_43 * * V_44 )
{
struct V_43 * V_84 ;
T_4 V_82 ;
* V_60 = V_83 ;
for ( V_82 = 0 ; V_82 < V_85 ; V_82 ++ ) {
V_84 = F_60 ( V_82 ) ;
if ( V_84 == NULL ) {
if ( * V_60 == V_83 )
* V_60 = V_82 ;
} else if ( F_7 ( V_3 , V_84 -> V_3 ) ) {
* V_44 = V_84 ;
return - V_105 ;
}
}
if ( * V_60 == V_83 )
return - V_106 ;
return 0 ;
}
static int
F_72 ( struct V_107 * V_108 , struct V_62 * V_63 ,
const struct V_87 * V_88 ,
const struct V_30 * const V_109 [] )
{
return - V_110 ;
}
static int
F_73 ( struct V_107 * V_108 , struct V_62 * V_63 ,
const struct V_87 * V_88 ,
const struct V_30 * const V_109 [] )
{
struct V_43 * V_44 , * V_111 = NULL ;
T_4 V_60 = V_83 ;
struct V_30 * V_35 [ V_112 + 1 ] = {} ;
const char * V_3 , * V_113 ;
T_1 V_4 , V_5 ;
T_5 V_94 = F_65 ( V_88 ) ;
int V_19 = 0 ;
if ( F_34 ( F_63 ( V_109 ) ||
V_109 [ V_114 ] == NULL ||
V_109 [ V_115 ] == NULL ||
V_109 [ V_116 ] == NULL ||
V_109 [ V_117 ] == NULL ||
( V_109 [ V_118 ] != NULL &&
! F_32 ( V_109 [ V_118 ] ) ) ) )
return - V_37 ;
V_3 = F_39 ( V_109 [ V_114 ] ) ;
V_113 = F_39 ( V_109 [ V_115 ] ) ;
V_4 = F_64 ( V_109 [ V_117 ] ) ;
V_5 = F_64 ( V_109 [ V_116 ] ) ;
F_10 ( L_18 ,
V_3 , V_113 , F_20 ( V_4 ) , V_5 ) ;
V_44 = F_26 ( sizeof( struct V_43 ) , V_28 ) ;
if ( ! V_44 )
return - V_119 ;
F_74 ( & V_44 -> V_70 ) ;
F_75 ( V_44 -> V_3 , V_3 , V_120 ) ;
V_44 -> V_4 = V_4 ;
V_44 -> V_5 = V_5 ;
V_19 = F_76 ( V_113 , V_4 , V_5 , & ( V_44 -> type ) ) ;
if ( V_19 )
goto V_121;
if ( V_109 [ V_118 ] &&
F_35 ( V_35 , V_112 , V_109 [ V_118 ] ,
V_44 -> type -> V_122 ) ) {
V_19 = - V_37 ;
goto V_123;
}
V_19 = V_44 -> type -> V_124 ( V_44 , V_35 , V_94 ) ;
if ( V_19 != 0 )
goto V_123;
V_19 = F_71 ( V_44 -> V_3 , & V_60 , & V_111 ) ;
if ( V_19 == - V_105 ) {
if ( ( V_94 & V_91 ) &&
F_7 ( V_44 -> type -> V_3 , V_111 -> type -> V_3 ) &&
V_44 -> type -> V_4 == V_111 -> type -> V_4 &&
V_44 -> type -> V_7 == V_111 -> type -> V_7 &&
V_44 -> type -> V_8 == V_111 -> type -> V_8 &&
V_44 -> V_71 -> V_125 ( V_44 , V_111 ) )
V_19 = 0 ;
goto V_126;
} else if ( V_19 == - V_106 ) {
struct V_43 * * V_23 , * * V_127 ;
T_4 V_82 = V_85 + V_128 ;
if ( V_82 < V_85 || V_82 == V_83 )
goto V_126;
V_23 = F_26 ( sizeof( struct V_43 * ) * V_82 , V_28 ) ;
if ( ! V_23 )
goto V_126;
V_127 = F_77 ( V_61 ) ;
memcpy ( V_23 , V_127 , sizeof( struct V_43 * ) * V_85 ) ;
F_78 ( V_61 , V_23 ) ;
F_79 () ;
V_60 = V_85 ;
V_85 = V_82 ;
F_31 ( V_127 ) ;
V_19 = 0 ;
} else if ( V_19 )
goto V_126;
F_10 ( L_19 , V_44 -> V_3 , V_60 ) ;
F_60 ( V_60 ) = V_44 ;
return V_19 ;
V_126:
V_44 -> V_71 -> V_129 ( V_44 ) ;
V_123:
F_80 ( V_44 -> type -> V_14 ) ;
V_121:
F_31 ( V_44 ) ;
return V_19 ;
}
static void
F_81 ( T_4 V_60 )
{
struct V_43 * V_44 = F_60 ( V_60 ) ;
F_10 ( L_20 , V_44 -> V_3 ) ;
F_60 ( V_60 ) = NULL ;
V_44 -> V_71 -> V_129 ( V_44 ) ;
F_80 ( V_44 -> type -> V_14 ) ;
F_31 ( V_44 ) ;
}
static int
F_82 ( struct V_107 * V_108 , struct V_62 * V_63 ,
const struct V_87 * V_88 ,
const struct V_30 * const V_109 [] )
{
struct V_43 * V_84 ;
T_4 V_82 ;
int V_19 = 0 ;
if ( F_34 ( F_63 ( V_109 ) ) )
return - V_37 ;
F_52 ( & V_58 ) ;
if ( ! V_109 [ V_114 ] ) {
for ( V_82 = 0 ; V_82 < V_85 ; V_82 ++ ) {
V_84 = F_60 ( V_82 ) ;
if ( V_84 != NULL && V_84 -> V_59 ) {
V_19 = - V_130 ;
goto V_121;
}
}
F_53 ( & V_58 ) ;
for ( V_82 = 0 ; V_82 < V_85 ; V_82 ++ ) {
V_84 = F_60 ( V_82 ) ;
if ( V_84 != NULL )
F_81 ( V_82 ) ;
}
} else {
V_84 = F_69 ( F_39 ( V_109 [ V_114 ] ) , & V_82 ) ;
if ( V_84 == NULL ) {
V_19 = - V_131 ;
goto V_121;
} else if ( V_84 -> V_59 ) {
V_19 = - V_130 ;
goto V_121;
}
F_53 ( & V_58 ) ;
F_81 ( V_82 ) ;
}
return 0 ;
V_121:
F_53 ( & V_58 ) ;
return V_19 ;
}
static void
F_83 ( struct V_43 * V_44 )
{
F_10 ( L_20 , V_44 -> V_3 ) ;
F_45 ( & V_44 -> V_70 ) ;
V_44 -> V_71 -> V_132 ( V_44 ) ;
F_46 ( & V_44 -> V_70 ) ;
}
static int
F_84 ( struct V_107 * V_108 , struct V_62 * V_63 ,
const struct V_87 * V_88 ,
const struct V_30 * const V_109 [] )
{
struct V_43 * V_84 ;
T_4 V_82 ;
if ( F_34 ( F_63 ( V_109 ) ) )
return - V_37 ;
if ( ! V_109 [ V_114 ] ) {
for ( V_82 = 0 ; V_82 < V_85 ; V_82 ++ ) {
V_84 = F_60 ( V_82 ) ;
if ( V_84 != NULL )
F_83 ( V_84 ) ;
}
} else {
V_84 = F_70 ( F_39 ( V_109 [ V_114 ] ) ) ;
if ( V_84 == NULL )
return - V_131 ;
F_83 ( V_84 ) ;
}
return 0 ;
}
static int
F_85 ( struct V_107 * V_108 , struct V_62 * V_63 ,
const struct V_87 * V_88 ,
const struct V_30 * const V_109 [] )
{
struct V_43 * V_44 , * V_84 ;
const char * V_133 ;
T_4 V_82 ;
int V_19 = 0 ;
if ( F_34 ( F_63 ( V_109 ) ||
V_109 [ V_114 ] == NULL ||
V_109 [ V_134 ] == NULL ) )
return - V_37 ;
V_44 = F_70 ( F_39 ( V_109 [ V_114 ] ) ) ;
if ( V_44 == NULL )
return - V_131 ;
F_52 ( & V_58 ) ;
if ( V_44 -> V_59 != 0 ) {
V_19 = - V_135 ;
goto V_121;
}
V_133 = F_39 ( V_109 [ V_134 ] ) ;
for ( V_82 = 0 ; V_82 < V_85 ; V_82 ++ ) {
V_84 = F_60 ( V_82 ) ;
if ( V_84 != NULL && F_7 ( V_84 -> V_3 , V_133 ) ) {
V_19 = - V_136 ;
goto V_121;
}
}
strncpy ( V_44 -> V_3 , V_133 , V_120 ) ;
V_121:
F_53 ( & V_58 ) ;
return V_19 ;
}
static int
F_86 ( struct V_107 * V_108 , struct V_62 * V_63 ,
const struct V_87 * V_88 ,
const struct V_30 * const V_109 [] )
{
struct V_43 * V_137 , * V_138 ;
T_4 V_139 , V_140 ;
char V_141 [ V_120 ] ;
if ( F_34 ( F_63 ( V_109 ) ||
V_109 [ V_114 ] == NULL ||
V_109 [ V_134 ] == NULL ) )
return - V_37 ;
V_137 = F_69 ( F_39 ( V_109 [ V_114 ] ) , & V_139 ) ;
if ( V_137 == NULL )
return - V_131 ;
V_138 = F_69 ( F_39 ( V_109 [ V_134 ] ) , & V_140 ) ;
if ( V_138 == NULL )
return - V_136 ;
if ( ! ( V_137 -> type -> V_78 == V_138 -> type -> V_78 &&
V_137 -> V_4 == V_138 -> V_4 ) )
return - V_142 ;
strncpy ( V_141 , V_137 -> V_3 , V_120 ) ;
strncpy ( V_137 -> V_3 , V_138 -> V_3 , V_120 ) ;
strncpy ( V_138 -> V_3 , V_141 , V_120 ) ;
F_45 ( & V_58 ) ;
F_87 ( V_137 -> V_59 , V_138 -> V_59 ) ;
F_60 ( V_139 ) = V_138 ;
F_60 ( V_140 ) = V_137 ;
F_46 ( & V_58 ) ;
return 0 ;
}
static int
F_88 ( struct V_143 * V_144 )
{
if ( V_144 -> args [ 2 ] ) {
F_10 ( L_21 , F_60 ( V_144 -> args [ 1 ] ) -> V_3 ) ;
F_57 ( ( T_4 ) V_144 -> args [ 1 ] ) ;
}
return 0 ;
}
static inline void
F_89 ( struct V_87 * V_88 )
{
const struct V_30 * V_109 ;
int V_145 ;
F_10 ( L_22 ) ;
F_90 (attr, nlh, sizeof(struct nfgenmsg), rem) {
F_10 ( L_23 , V_32 ( V_109 ) , V_109 -> V_146 ) ;
}
}
static int
F_91 ( struct V_143 * V_144 )
{
struct V_87 * V_88 = F_92 ( V_144 -> V_63 ) ;
int V_147 = F_93 ( sizeof( struct V_97 ) ) ;
struct V_30 * V_148 [ V_149 + 1 ] ;
struct V_30 * V_109 = ( void * ) V_88 + V_147 ;
T_5 V_150 ;
T_4 V_60 ;
F_94 ( V_148 , V_149 ,
V_109 , V_88 -> V_151 - V_147 , V_152 ) ;
if ( V_148 [ V_114 ] ) {
struct V_43 * V_44 ;
V_44 = F_69 ( F_39 ( V_148 [ V_114 ] ) ,
& V_60 ) ;
if ( V_44 == NULL )
return - V_131 ;
V_150 = V_153 ;
V_144 -> args [ 1 ] = V_60 ;
} else
V_150 = V_154 ;
if ( V_148 [ V_155 ] ) {
T_5 V_156 = F_95 ( V_148 [ V_155 ] ) ;
V_150 |= ( V_156 << 16 ) ;
}
V_144 -> args [ 0 ] = V_150 ;
return 0 ;
}
static int
F_96 ( struct V_62 * V_63 , struct V_143 * V_144 )
{
T_4 V_60 = V_83 , V_18 ;
struct V_43 * V_44 = NULL ;
struct V_87 * V_88 = NULL ;
unsigned int V_94 = F_97 ( V_144 -> V_63 ) . V_92 ? V_157 : 0 ;
T_5 V_150 , V_158 ;
int V_19 = 0 ;
if ( ! V_144 -> args [ 0 ] ) {
V_19 = F_91 ( V_144 ) ;
if ( V_19 < 0 ) {
V_88 = F_92 ( V_144 -> V_63 ) ;
if ( V_88 -> V_89 & V_159 )
F_98 ( V_144 -> V_63 , V_88 , V_19 ) ;
return V_19 ;
}
}
if ( V_144 -> args [ 1 ] >= V_85 )
goto V_121;
V_150 = F_99 ( V_144 -> args [ 0 ] ) ;
V_158 = F_100 ( V_144 -> args [ 0 ] ) ;
V_18 = V_150 == V_153 ? V_144 -> args [ 1 ] + 1 : V_85 ;
V_160:
F_10 ( L_24 ,
V_150 , V_158 , V_144 -> args [ 1 ] ) ;
for (; V_144 -> args [ 1 ] < V_18 ; V_144 -> args [ 1 ] ++ ) {
V_60 = ( T_4 ) V_144 -> args [ 1 ] ;
V_44 = F_60 ( V_60 ) ;
if ( V_44 == NULL ) {
if ( V_150 == V_153 ) {
V_19 = - V_131 ;
goto V_121;
}
continue;
}
if ( V_150 != V_153 &&
( ( V_150 == V_154 ) ==
! ! ( V_44 -> type -> V_78 & V_161 ) ) )
continue;
F_10 ( L_25 , V_44 -> V_3 ) ;
if ( ! V_144 -> args [ 2 ] ) {
F_10 ( L_26 ) ;
F_44 ( V_44 ) ;
}
V_88 = F_66 ( V_63 , F_97 ( V_144 -> V_63 ) . V_92 ,
V_144 -> V_88 -> V_162 , V_94 ,
V_163 ) ;
if ( ! V_88 ) {
V_19 = - V_164 ;
goto V_165;
}
if ( F_101 ( V_63 , V_86 , V_21 ) ||
F_102 ( V_63 , V_114 , V_44 -> V_3 ) )
goto V_166;
if ( V_158 & V_167 )
goto V_168;
switch ( V_144 -> args [ 2 ] ) {
case 0 :
if ( F_102 ( V_63 , V_115 ,
V_44 -> type -> V_3 ) ||
F_101 ( V_63 , V_117 ,
V_44 -> V_4 ) ||
F_101 ( V_63 , V_116 ,
V_44 -> V_5 ) )
goto V_166;
V_19 = V_44 -> V_71 -> V_169 ( V_44 , V_63 ) ;
if ( V_19 < 0 )
goto V_165;
if ( V_158 & V_170 )
goto V_168;
default:
F_52 ( & V_44 -> V_70 ) ;
V_19 = V_44 -> V_71 -> V_23 ( V_44 , V_63 , V_144 ) ;
F_53 ( & V_44 -> V_70 ) ;
if ( ! V_144 -> args [ 2 ] )
goto V_168;
goto V_165;
}
}
if ( V_150 == V_154 ) {
V_150 = V_171 ;
V_144 -> args [ 0 ] = V_150 | ( V_158 << 16 ) ;
V_144 -> args [ 1 ] = 0 ;
goto V_160;
}
goto V_121;
V_166:
V_19 = - V_15 ;
V_168:
if ( V_150 == V_153 )
V_144 -> args [ 1 ] = V_83 ;
else
V_144 -> args [ 1 ] ++ ;
V_165:
if ( V_19 || ! V_144 -> args [ 2 ] ) {
F_10 ( L_21 , F_60 ( V_60 ) -> V_3 ) ;
F_57 ( V_60 ) ;
V_144 -> args [ 2 ] = 0 ;
}
V_121:
if ( V_88 ) {
F_103 ( V_63 , V_88 ) ;
F_10 ( L_27 , V_88 -> V_151 ) ;
F_89 ( V_88 ) ;
}
return V_19 < 0 ? V_19 : V_63 -> V_172 ;
}
static int
F_104 ( struct V_107 * V_108 , struct V_62 * V_63 ,
const struct V_87 * V_88 ,
const struct V_30 * const V_109 [] )
{
if ( F_34 ( F_63 ( V_109 ) ) )
return - V_37 ;
{
struct V_173 V_174 = {
. V_175 = F_96 ,
. V_176 = F_88 ,
} ;
return F_105 ( V_108 , V_63 , V_88 , & V_174 ) ;
}
}
static int
F_106 ( struct V_107 * V_108 , struct V_62 * V_63 , struct V_43 * V_44 ,
struct V_30 * V_35 [] , enum V_177 V_178 ,
T_5 V_94 , bool V_179 )
{
int V_19 ;
T_5 V_180 = 0 ;
bool V_181 = V_94 & V_91 , V_182 = false ;
do {
F_45 ( & V_44 -> V_70 ) ;
V_19 = V_44 -> V_71 -> V_183 ( V_44 , V_35 , V_178 , & V_180 , V_94 , V_182 ) ;
F_46 ( & V_44 -> V_70 ) ;
V_182 = true ;
} while ( V_19 == - V_74 &&
V_44 -> V_71 -> V_184 &&
( V_19 = V_44 -> V_71 -> V_184 ( V_44 , V_182 ) ) == 0 );
if ( ! V_19 || ( V_19 == - V_185 && V_181 ) )
return 0 ;
if ( V_180 && V_179 ) {
struct V_87 * V_186 , * V_88 = F_92 ( V_63 ) ;
struct V_62 * V_187 ;
struct V_188 * V_189 ;
T_2 V_190 = sizeof( * V_189 ) + V_151 ( V_88 ) ;
int V_147 = F_93 ( sizeof( struct V_97 ) ) ;
struct V_30 * V_148 [ V_149 + 1 ] ;
struct V_30 * V_191 ;
T_5 * V_192 ;
V_187 = F_107 ( V_190 , V_28 ) ;
if ( V_187 == NULL )
return - V_119 ;
V_186 = F_108 ( V_187 , F_97 ( V_63 ) . V_92 ,
V_88 -> V_162 , V_193 , V_190 , 0 ) ;
V_189 = F_68 ( V_186 ) ;
V_189 -> error = V_19 ;
memcpy ( & V_189 -> V_194 , V_88 , V_88 -> V_151 ) ;
V_191 = ( void * ) & V_189 -> V_194 + V_147 ;
F_94 ( V_148 , V_149 ,
V_191 , V_88 -> V_151 - V_147 ,
V_195 ) ;
V_192 = F_39 ( V_148 [ V_196 ] ) ;
* V_192 = V_180 ;
F_109 ( V_108 , V_187 , F_97 ( V_63 ) . V_92 , V_197 ) ;
return - V_198 ;
}
return V_19 ;
}
static int
F_110 ( struct V_107 * V_108 , struct V_62 * V_63 ,
const struct V_87 * V_88 ,
const struct V_30 * const V_109 [] )
{
struct V_43 * V_44 ;
struct V_30 * V_35 [ V_199 + 1 ] = {} ;
const struct V_30 * V_31 ;
T_5 V_94 = F_65 ( V_88 ) ;
bool V_179 ;
int V_19 = 0 ;
if ( F_34 ( F_63 ( V_109 ) ||
V_109 [ V_114 ] == NULL ||
! ( ( V_109 [ V_118 ] != NULL ) ^
( V_109 [ V_200 ] != NULL ) ) ||
( V_109 [ V_118 ] != NULL &&
! F_32 ( V_109 [ V_118 ] ) ) ||
( V_109 [ V_200 ] != NULL &&
( ! F_32 ( V_109 [ V_200 ] ) ||
V_109 [ V_196 ] == NULL ) ) ) )
return - V_37 ;
V_44 = F_70 ( F_39 ( V_109 [ V_114 ] ) ) ;
if ( V_44 == NULL )
return - V_131 ;
V_179 = ! ! V_109 [ V_196 ] ;
if ( V_109 [ V_118 ] ) {
if ( F_35 ( V_35 , V_199 ,
V_109 [ V_118 ] ,
V_44 -> type -> V_201 ) )
return - V_37 ;
V_19 = F_106 ( V_108 , V_63 , V_44 , V_35 , V_75 , V_94 ,
V_179 ) ;
} else {
int V_202 ;
F_111 (nla, attr[IPSET_ATTR_ADT], nla_rem) {
memset ( V_35 , 0 , sizeof( V_35 ) ) ;
if ( V_32 ( V_31 ) != V_118 ||
! F_32 ( V_31 ) ||
F_35 ( V_35 , V_199 , V_31 ,
V_44 -> type -> V_201 ) )
return - V_37 ;
V_19 = F_106 ( V_108 , V_63 , V_44 , V_35 , V_75 ,
V_94 , V_179 ) ;
if ( V_19 < 0 )
return V_19 ;
}
}
return V_19 ;
}
static int
F_112 ( struct V_107 * V_108 , struct V_62 * V_63 ,
const struct V_87 * V_88 ,
const struct V_30 * const V_109 [] )
{
struct V_43 * V_44 ;
struct V_30 * V_35 [ V_199 + 1 ] = {} ;
const struct V_30 * V_31 ;
T_5 V_94 = F_65 ( V_88 ) ;
bool V_179 ;
int V_19 = 0 ;
if ( F_34 ( F_63 ( V_109 ) ||
V_109 [ V_114 ] == NULL ||
! ( ( V_109 [ V_118 ] != NULL ) ^
( V_109 [ V_200 ] != NULL ) ) ||
( V_109 [ V_118 ] != NULL &&
! F_32 ( V_109 [ V_118 ] ) ) ||
( V_109 [ V_200 ] != NULL &&
( ! F_32 ( V_109 [ V_200 ] ) ||
V_109 [ V_196 ] == NULL ) ) ) )
return - V_37 ;
V_44 = F_70 ( F_39 ( V_109 [ V_114 ] ) ) ;
if ( V_44 == NULL )
return - V_131 ;
V_179 = ! ! V_109 [ V_196 ] ;
if ( V_109 [ V_118 ] ) {
if ( F_35 ( V_35 , V_199 ,
V_109 [ V_118 ] ,
V_44 -> type -> V_201 ) )
return - V_37 ;
V_19 = F_106 ( V_108 , V_63 , V_44 , V_35 , V_81 , V_94 ,
V_179 ) ;
} else {
int V_202 ;
F_111 (nla, attr[IPSET_ATTR_ADT], nla_rem) {
memset ( V_35 , 0 , sizeof( * V_35 ) ) ;
if ( V_32 ( V_31 ) != V_118 ||
! F_32 ( V_31 ) ||
F_35 ( V_35 , V_199 , V_31 ,
V_44 -> type -> V_201 ) )
return - V_37 ;
V_19 = F_106 ( V_108 , V_63 , V_44 , V_35 , V_81 ,
V_94 , V_179 ) ;
if ( V_19 < 0 )
return V_19 ;
}
}
return V_19 ;
}
static int
F_113 ( struct V_107 * V_108 , struct V_62 * V_63 ,
const struct V_87 * V_88 ,
const struct V_30 * const V_109 [] )
{
struct V_43 * V_44 ;
struct V_30 * V_35 [ V_199 + 1 ] = {} ;
int V_19 = 0 ;
if ( F_34 ( F_63 ( V_109 ) ||
V_109 [ V_114 ] == NULL ||
V_109 [ V_118 ] == NULL ||
! F_32 ( V_109 [ V_118 ] ) ) )
return - V_37 ;
V_44 = F_70 ( F_39 ( V_109 [ V_114 ] ) ) ;
if ( V_44 == NULL )
return - V_131 ;
if ( F_35 ( V_35 , V_199 , V_109 [ V_118 ] ,
V_44 -> type -> V_201 ) )
return - V_37 ;
F_52 ( & V_44 -> V_70 ) ;
V_19 = V_44 -> V_71 -> V_183 ( V_44 , V_35 , V_73 , NULL , 0 , 0 ) ;
F_53 ( & V_44 -> V_70 ) ;
if ( V_19 == - V_74 )
V_19 = 1 ;
return V_19 > 0 ? 0 : - V_185 ;
}
static int
F_114 ( struct V_107 * V_108 , struct V_62 * V_63 ,
const struct V_87 * V_88 ,
const struct V_30 * const V_109 [] )
{
const struct V_43 * V_44 ;
struct V_62 * V_187 ;
struct V_87 * V_203 ;
int V_19 = 0 ;
if ( F_34 ( F_63 ( V_109 ) ||
V_109 [ V_114 ] == NULL ) )
return - V_37 ;
V_44 = F_70 ( F_39 ( V_109 [ V_114 ] ) ) ;
if ( V_44 == NULL )
return - V_131 ;
V_187 = F_107 ( V_204 , V_28 ) ;
if ( V_187 == NULL )
return - V_119 ;
V_203 = F_66 ( V_187 , F_97 ( V_63 ) . V_92 , V_88 -> V_162 , 0 ,
V_205 ) ;
if ( ! V_203 )
goto V_206;
if ( F_101 ( V_187 , V_86 , V_21 ) ||
F_102 ( V_187 , V_114 , V_44 -> V_3 ) ||
F_102 ( V_187 , V_115 , V_44 -> type -> V_3 ) ||
F_101 ( V_187 , V_117 , V_44 -> V_4 ) ||
F_101 ( V_187 , V_116 , V_44 -> V_5 ) )
goto V_166;
F_103 ( V_187 , V_203 ) ;
V_19 = F_109 ( V_108 , V_187 , F_97 ( V_63 ) . V_92 , V_197 ) ;
if ( V_19 < 0 )
return V_19 ;
return 0 ;
V_166:
F_115 ( V_187 , V_203 ) ;
V_206:
F_116 ( V_187 ) ;
return - V_164 ;
}
static int
V_2 ( struct V_107 * V_108 , struct V_62 * V_63 ,
const struct V_87 * V_88 ,
const struct V_30 * const V_109 [] )
{
struct V_62 * V_187 ;
struct V_87 * V_203 ;
T_1 V_4 , V_17 , V_18 ;
const char * V_113 ;
int V_19 = 0 ;
if ( F_34 ( F_63 ( V_109 ) ||
V_109 [ V_115 ] == NULL ||
V_109 [ V_117 ] == NULL ) )
return - V_37 ;
V_4 = F_64 ( V_109 [ V_117 ] ) ;
V_113 = F_39 ( V_109 [ V_115 ] ) ;
V_19 = F_117 ( V_113 , V_4 , & V_17 , & V_18 ) ;
if ( V_19 )
return V_19 ;
V_187 = F_107 ( V_204 , V_28 ) ;
if ( V_187 == NULL )
return - V_119 ;
V_203 = F_66 ( V_187 , F_97 ( V_63 ) . V_92 , V_88 -> V_162 , 0 ,
V_207 ) ;
if ( ! V_203 )
goto V_206;
if ( F_101 ( V_187 , V_86 , V_21 ) ||
F_102 ( V_187 , V_115 , V_113 ) ||
F_101 ( V_187 , V_117 , V_4 ) ||
F_101 ( V_187 , V_116 , V_18 ) ||
F_101 ( V_187 , V_208 , V_17 ) )
goto V_166;
F_103 ( V_187 , V_203 ) ;
F_10 ( L_28 , V_203 -> V_151 ) ;
V_19 = F_109 ( V_108 , V_187 , F_97 ( V_63 ) . V_92 , V_197 ) ;
if ( V_19 < 0 )
return V_19 ;
return 0 ;
V_166:
F_115 ( V_187 , V_203 ) ;
V_206:
F_116 ( V_187 ) ;
return - V_164 ;
}
static int
F_118 ( struct V_107 * V_108 , struct V_62 * V_63 ,
const struct V_87 * V_88 ,
const struct V_30 * const V_109 [] )
{
struct V_62 * V_187 ;
struct V_87 * V_203 ;
int V_19 = 0 ;
if ( F_34 ( V_109 [ V_86 ] == NULL ) )
return - V_37 ;
V_187 = F_107 ( V_204 , V_28 ) ;
if ( V_187 == NULL )
return - V_119 ;
V_203 = F_66 ( V_187 , F_97 ( V_63 ) . V_92 , V_88 -> V_162 , 0 ,
V_209 ) ;
if ( ! V_203 )
goto V_206;
if ( F_101 ( V_187 , V_86 , V_21 ) )
goto V_166;
F_103 ( V_187 , V_203 ) ;
V_19 = F_109 ( V_108 , V_187 , F_97 ( V_63 ) . V_92 , V_197 ) ;
if ( V_19 < 0 )
return V_19 ;
return 0 ;
V_166:
F_115 ( V_187 , V_203 ) ;
V_206:
F_116 ( V_187 ) ;
return - V_164 ;
}
static int
F_119 ( struct V_107 * V_210 , int V_211 , void T_6 * V_212 , int * V_172 )
{
unsigned int * V_213 ;
void * V_214 ;
int V_215 = * V_172 , V_19 = 0 ;
if ( ! F_120 ( F_121 ( V_210 ) -> V_216 , V_217 ) )
return - V_218 ;
if ( V_211 != V_219 )
return - V_220 ;
if ( * V_172 < sizeof( unsigned int ) )
return - V_22 ;
V_214 = F_122 ( * V_172 ) ;
if ( ! V_214 )
return - V_119 ;
if ( F_123 ( V_214 , V_212 , * V_172 ) != 0 ) {
V_19 = - V_15 ;
goto V_176;
}
V_213 = ( unsigned int * ) V_214 ;
if ( * V_213 < V_221 ) {
struct V_222 * V_223 = V_214 ;
if ( V_223 -> V_101 != V_21 ) {
V_19 = - V_224 ;
goto V_176;
}
}
switch ( * V_213 ) {
case V_221 : {
struct V_222 * V_223 = V_214 ;
if ( * V_172 != sizeof( struct V_222 ) ) {
V_19 = - V_22 ;
goto V_176;
}
V_223 -> V_101 = V_21 ;
V_19 = F_124 ( V_212 , V_223 ,
sizeof( struct V_222 ) ) ;
goto V_176;
}
case V_225 : {
struct V_226 * V_227 = V_214 ;
T_4 V_104 ;
if ( * V_172 != sizeof( struct V_226 ) ) {
V_19 = - V_22 ;
goto V_176;
}
V_227 -> V_44 . V_3 [ V_120 - 1 ] = '\0' ;
F_13 ( V_9 ) ;
F_69 ( V_227 -> V_44 . V_3 , & V_104 ) ;
V_227 -> V_44 . V_60 = V_104 ;
F_9 ( V_9 ) ;
goto V_228;
}
case V_229 : {
struct V_226 * V_227 = V_214 ;
struct V_43 * V_44 ;
if ( * V_172 != sizeof( struct V_226 ) ||
V_227 -> V_44 . V_60 >= V_85 ) {
V_19 = - V_22 ;
goto V_176;
}
F_13 ( V_9 ) ;
V_44 = F_60 ( V_227 -> V_44 . V_60 ) ;
strncpy ( V_227 -> V_44 . V_3 , V_44 ? V_44 -> V_3 : L_29 ,
V_120 ) ;
F_9 ( V_9 ) ;
goto V_228;
}
default:
V_19 = - V_230 ;
goto V_176;
}
V_228:
V_19 = F_124 ( V_212 , V_214 , V_215 ) ;
V_176:
F_30 ( V_214 ) ;
if ( V_19 > 0 )
V_19 = 0 ;
return V_19 ;
}
static int T_7
F_125 ( void )
{
struct V_43 * * V_23 ;
int V_19 ;
if ( V_231 )
V_85 = V_231 ;
if ( V_85 >= V_83 )
V_85 = V_83 - 1 ;
V_23 = F_26 ( sizeof( struct V_43 * ) * V_85 , V_28 ) ;
if ( ! V_23 )
return - V_119 ;
F_78 ( V_61 , V_23 ) ;
V_19 = F_126 ( & V_232 ) ;
if ( V_19 != 0 ) {
F_127 ( L_30 ) ;
F_31 ( V_23 ) ;
return V_19 ;
}
V_19 = F_128 ( & V_233 ) ;
if ( V_19 != 0 ) {
F_127 ( L_31 , V_19 ) ;
F_129 ( & V_232 ) ;
F_31 ( V_23 ) ;
return V_19 ;
}
F_130 ( L_32 , V_21 ) ;
return 0 ;
}
static void T_8
F_131 ( void )
{
struct V_43 * * V_23 = F_132 ( V_61 , 1 ) ;
F_133 ( & V_233 ) ;
F_129 ( & V_232 ) ;
F_31 ( V_23 ) ;
F_10 ( L_33 ) ;
}
