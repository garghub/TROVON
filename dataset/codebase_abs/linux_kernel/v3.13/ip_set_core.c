static inline struct V_1 * F_1 ( struct V_2 * V_2 )
{
return F_2 ( V_2 , V_3 ) ;
}
static inline void
F_3 ( void )
{
F_4 ( & V_4 ) ;
}
static inline void
F_5 ( void )
{
F_6 ( & V_4 ) ;
}
static struct V_5 *
F_7 ( const char * V_6 , T_1 V_7 , T_1 V_8 )
{
struct V_5 * type ;
F_8 (type, &ip_set_type_list, list)
if ( F_9 ( type -> V_6 , V_6 ) &&
( type -> V_7 == V_7 ||
type -> V_7 == V_9 ) &&
V_8 >= type -> V_10 &&
V_8 <= type -> V_11 )
return type ;
return NULL ;
}
static bool
F_10 ( const char * V_6 )
{
F_11 ( V_12 ) ;
F_12 ( L_1 , V_6 ) ;
if ( F_13 ( L_2 , V_6 ) < 0 ) {
F_14 ( L_3 , V_6 ) ;
F_15 ( V_12 ) ;
return false ;
}
F_15 ( V_12 ) ;
return true ;
}
static int
F_16 ( const char * V_6 , T_1 V_7 , T_1 V_8 ,
struct V_5 * * V_13 , bool V_14 )
{
struct V_5 * type ;
int V_15 ;
if ( V_14 && ! F_10 ( V_6 ) )
return - V_16 ;
F_17 () ;
* V_13 = F_7 ( V_6 , V_7 , V_8 ) ;
if ( * V_13 ) {
V_15 = ! F_18 ( ( * V_13 ) -> V_17 ) ? - V_18 : 0 ;
goto V_19;
}
F_8 (type, &ip_set_type_list, list)
if ( F_9 ( type -> V_6 , V_6 ) ) {
V_15 = - V_16 ;
goto V_19;
}
F_19 () ;
return V_14 ? - V_16 :
F_16 ( V_6 , V_7 , V_8 , V_13 , true ) ;
V_19:
F_19 () ;
return V_15 ;
}
static int
F_20 ( const char * V_6 , T_1 V_7 , T_1 * V_20 , T_1 * V_21 ,
bool V_14 )
{
struct V_5 * type ;
bool V_13 = false ;
if ( V_14 && ! F_10 ( V_6 ) )
return - V_16 ;
* V_20 = 255 ; * V_21 = 0 ;
F_17 () ;
F_8 (type, &ip_set_type_list, list)
if ( F_9 ( type -> V_6 , V_6 ) &&
( type -> V_7 == V_7 ||
type -> V_7 == V_9 ) ) {
V_13 = true ;
if ( type -> V_10 < * V_20 )
* V_20 = type -> V_10 ;
if ( type -> V_11 > * V_21 )
* V_21 = type -> V_11 ;
}
F_19 () ;
if ( V_13 )
return 0 ;
return V_14 ? - V_16 :
F_20 ( V_6 , V_7 , V_20 , V_21 , true ) ;
}
int
F_21 ( struct V_5 * type )
{
int V_22 = 0 ;
if ( type -> V_23 != V_24 ) {
F_14 ( L_4
L_5 ,
type -> V_6 , F_22 ( type -> V_7 ) ,
type -> V_10 , type -> V_11 ,
type -> V_23 , V_24 ) ;
return - V_25 ;
}
F_3 () ;
if ( F_7 ( type -> V_6 , type -> V_7 , type -> V_10 ) ) {
F_14 ( L_6
L_7 , type -> V_6 ,
F_22 ( type -> V_7 ) , type -> V_10 ) ;
V_22 = - V_25 ;
goto V_19;
}
F_23 ( & type -> V_26 , & V_27 ) ;
F_12 ( L_8 ,
type -> V_6 , F_22 ( type -> V_7 ) ,
type -> V_10 , type -> V_11 ) ;
V_19:
F_5 () ;
return V_22 ;
}
void
F_24 ( struct V_5 * type )
{
F_3 () ;
if ( ! F_7 ( type -> V_6 , type -> V_7 , type -> V_10 ) ) {
F_14 ( L_6
L_9 , type -> V_6 ,
F_22 ( type -> V_7 ) , type -> V_10 ) ;
goto V_19;
}
F_25 ( & type -> V_26 ) ;
F_12 ( L_10 ,
type -> V_6 , F_22 ( type -> V_7 ) , type -> V_10 ) ;
V_19:
F_5 () ;
F_26 () ;
}
void *
F_27 ( T_2 V_28 )
{
void * V_29 = NULL ;
if ( V_28 < V_30 )
V_29 = F_28 ( V_28 , V_31 | V_32 ) ;
if ( V_29 ) {
F_12 ( L_11 , V_29 ) ;
return V_29 ;
}
V_29 = F_29 ( V_28 ) ;
if ( ! V_29 )
return NULL ;
F_12 ( L_12 , V_29 ) ;
return V_29 ;
}
void
F_30 ( void * V_29 )
{
F_12 ( L_13 , V_29 ,
F_31 ( V_29 ) ? L_14 : L_15 ) ;
if ( F_31 ( V_29 ) )
F_32 ( V_29 ) ;
else
F_33 ( V_29 ) ;
}
static inline bool
F_34 ( const struct V_33 * V_34 )
{
return V_34 -> V_35 & V_36 ;
}
int
F_35 ( struct V_33 * V_34 , T_3 * V_37 )
{
struct V_33 * V_38 [ V_39 + 1 ] ;
if ( F_36 ( ! F_34 ( V_34 ) ) )
return - V_40 ;
if ( F_37 ( V_38 , V_39 , V_34 , V_41 ) )
return - V_40 ;
if ( F_36 ( ! F_38 ( V_38 , V_42 ) ) )
return - V_40 ;
* V_37 = F_39 ( V_38 [ V_42 ] ) ;
return 0 ;
}
int
F_40 ( struct V_33 * V_34 , union V_43 * V_37 )
{
struct V_33 * V_38 [ V_39 + 1 ] ;
if ( F_36 ( ! F_34 ( V_34 ) ) )
return - V_40 ;
if ( F_37 ( V_38 , V_39 , V_34 , V_41 ) )
return - V_40 ;
if ( F_36 ( ! F_38 ( V_38 , V_44 ) ) )
return - V_40 ;
memcpy ( V_37 , F_41 ( V_38 [ V_44 ] ) ,
sizeof( struct V_45 ) ) ;
return 0 ;
}
static inline bool
F_42 ( enum V_46 V_47 , T_4 V_48 , struct V_33 * V_38 [] )
{
return V_49 [ V_47 ] . V_50 ?
( V_48 & V_49 [ V_47 ] . V_50 ) :
! ! V_38 [ V_51 ] ;
}
T_2
F_43 ( struct V_52 * V_53 , struct V_33 * V_38 [] , T_2 V_54 )
{
enum V_46 V_47 ;
T_2 V_55 = 0 ;
T_4 V_56 = 0 ;
if ( V_38 [ V_57 ] )
V_56 = F_44 ( V_38 [ V_57 ] ) ;
for ( V_47 = 0 ; V_47 < V_58 ; V_47 ++ ) {
if ( ! F_42 ( V_47 , V_56 , V_38 ) )
continue;
V_55 += F_45 ( V_54 + V_55 , V_49 [ V_47 ] . V_59 ) ;
V_53 -> V_55 [ V_47 ] = V_55 ;
V_53 -> V_60 |= V_49 [ V_47 ] . type ;
V_55 += V_49 [ V_47 ] . V_54 ;
}
return V_54 + V_55 ;
}
int
F_46 ( struct V_52 * V_53 , struct V_33 * V_38 [] ,
struct V_61 * V_62 )
{
if ( V_38 [ V_51 ] ) {
if ( ! ( V_53 -> V_60 & V_63 ) )
return - V_64 ;
V_62 -> V_65 = F_47 ( V_38 [ V_51 ] ) ;
}
if ( V_38 [ V_66 ] || V_38 [ V_67 ] ) {
if ( ! ( V_53 -> V_60 & V_68 ) )
return - V_69 ;
if ( V_38 [ V_66 ] )
V_62 -> V_70 = F_48 ( F_49 (
V_38 [ V_66 ] ) ) ;
if ( V_38 [ V_67 ] )
V_62 -> V_71 = F_48 ( F_49 (
V_38 [ V_67 ] ) ) ;
}
if ( V_38 [ V_72 ] ) {
if ( ! ( V_53 -> V_60 & V_73 ) )
return - V_74 ;
V_62 -> V_75 = F_50 ( V_38 [ V_72 ] ) ;
}
return 0 ;
}
static inline void
F_51 ( struct V_52 * V_53 )
{
F_52 ( & V_76 ) ;
V_53 -> V_77 ++ ;
F_53 ( & V_76 ) ;
}
static inline void
F_54 ( struct V_52 * V_53 )
{
F_52 ( & V_76 ) ;
F_55 ( V_53 -> V_77 == 0 ) ;
V_53 -> V_77 -- ;
F_53 ( & V_76 ) ;
}
static inline struct V_52 *
F_56 ( struct V_2 * V_2 , T_5 V_78 )
{
struct V_52 * V_53 ;
struct V_1 * V_79 = F_1 ( V_2 ) ;
F_17 () ;
V_53 = F_57 ( V_79 -> V_80 ) [ V_78 ] ;
F_19 () ;
return V_53 ;
}
int
F_58 ( T_5 V_78 , const struct V_81 * V_82 ,
const struct V_83 * V_84 , struct V_85 * V_86 )
{
struct V_52 * V_53 = F_56 (
F_59 ( V_84 -> V_87 ? V_84 -> V_87 : V_84 -> V_88 ) , V_78 ) ;
int V_22 = 0 ;
F_55 ( V_53 == NULL ) ;
F_12 ( L_16 , V_53 -> V_6 , V_78 ) ;
if ( V_86 -> V_89 < V_53 -> type -> V_90 ||
! ( V_86 -> V_7 == V_53 -> V_7 || V_53 -> V_7 == V_9 ) )
return 0 ;
F_60 ( & V_53 -> V_91 ) ;
V_22 = V_53 -> V_92 -> V_93 ( V_53 , V_82 , V_84 , V_94 , V_86 ) ;
F_61 ( & V_53 -> V_91 ) ;
if ( V_22 == - V_95 ) {
F_12 ( L_17 ) ;
F_52 ( & V_53 -> V_91 ) ;
V_53 -> V_92 -> V_93 ( V_53 , V_82 , V_84 , V_96 , V_86 ) ;
F_53 ( & V_53 -> V_91 ) ;
V_22 = 1 ;
} else {
if ( ( V_86 -> V_97 & V_98 ) &&
( V_53 -> type -> V_99 & V_100 ) &&
( V_22 > 0 || V_22 == - V_101 ) )
V_22 = - V_22 ;
}
return ( V_22 < 0 ? 0 : V_22 ) ;
}
int
F_62 ( T_5 V_78 , const struct V_81 * V_82 ,
const struct V_83 * V_84 , struct V_85 * V_86 )
{
struct V_52 * V_53 = F_56 (
F_59 ( V_84 -> V_87 ? V_84 -> V_87 : V_84 -> V_88 ) , V_78 ) ;
int V_22 ;
F_55 ( V_53 == NULL ) ;
F_12 ( L_16 , V_53 -> V_6 , V_78 ) ;
if ( V_86 -> V_89 < V_53 -> type -> V_90 ||
! ( V_86 -> V_7 == V_53 -> V_7 || V_53 -> V_7 == V_9 ) )
return 0 ;
F_52 ( & V_53 -> V_91 ) ;
V_22 = V_53 -> V_92 -> V_93 ( V_53 , V_82 , V_84 , V_96 , V_86 ) ;
F_53 ( & V_53 -> V_91 ) ;
return V_22 ;
}
int
F_63 ( T_5 V_78 , const struct V_81 * V_82 ,
const struct V_83 * V_84 , struct V_85 * V_86 )
{
struct V_52 * V_53 = F_56 (
F_59 ( V_84 -> V_87 ? V_84 -> V_87 : V_84 -> V_88 ) , V_78 ) ;
int V_22 = 0 ;
F_55 ( V_53 == NULL ) ;
F_12 ( L_16 , V_53 -> V_6 , V_78 ) ;
if ( V_86 -> V_89 < V_53 -> type -> V_90 ||
! ( V_86 -> V_7 == V_53 -> V_7 || V_53 -> V_7 == V_9 ) )
return 0 ;
F_52 ( & V_53 -> V_91 ) ;
V_22 = V_53 -> V_92 -> V_93 ( V_53 , V_82 , V_84 , V_102 , V_86 ) ;
F_53 ( & V_53 -> V_91 ) ;
return V_22 ;
}
T_5
F_64 ( struct V_2 * V_2 , const char * V_6 , struct V_52 * * V_53 )
{
T_5 V_103 , V_78 = V_104 ;
struct V_52 * V_105 ;
struct V_1 * V_79 = F_1 ( V_2 ) ;
F_17 () ;
for ( V_103 = 0 ; V_103 < V_79 -> V_106 ; V_103 ++ ) {
V_105 = F_57 ( V_79 -> V_80 ) [ V_103 ] ;
if ( V_105 != NULL && F_9 ( V_105 -> V_6 , V_6 ) ) {
F_51 ( V_105 ) ;
V_78 = V_103 ;
* V_53 = V_105 ;
break;
}
}
F_19 () ;
return V_78 ;
}
static inline void
F_65 ( struct V_1 * V_79 , T_5 V_78 )
{
struct V_52 * V_53 ;
F_17 () ;
V_53 = F_57 ( V_79 -> V_80 ) [ V_78 ] ;
if ( V_53 != NULL )
F_54 ( V_53 ) ;
F_19 () ;
}
void
F_66 ( struct V_2 * V_2 , T_5 V_78 )
{
struct V_1 * V_79 = F_1 ( V_2 ) ;
F_65 ( V_79 , V_78 ) ;
}
const char *
F_67 ( struct V_2 * V_2 , T_5 V_78 )
{
const struct V_52 * V_53 = F_56 ( V_2 , V_78 ) ;
F_55 ( V_53 == NULL ) ;
F_55 ( V_53 -> V_77 == 0 ) ;
return V_53 -> V_6 ;
}
T_5
F_68 ( struct V_2 * V_2 , const char * V_6 )
{
T_5 V_103 , V_78 = V_104 ;
struct V_52 * V_105 ;
struct V_1 * V_79 = F_1 ( V_2 ) ;
F_15 ( V_12 ) ;
for ( V_103 = 0 ; V_103 < V_79 -> V_106 ; V_103 ++ ) {
V_105 = F_69 ( V_79 , V_103 ) ;
if ( V_105 != NULL && F_9 ( V_105 -> V_6 , V_6 ) ) {
F_51 ( V_105 ) ;
V_78 = V_103 ;
break;
}
}
F_11 ( V_12 ) ;
return V_78 ;
}
T_5
F_70 ( struct V_2 * V_2 , T_5 V_78 )
{
struct V_52 * V_53 ;
struct V_1 * V_79 = F_1 ( V_2 ) ;
if ( V_78 > V_79 -> V_106 )
return V_104 ;
F_15 ( V_12 ) ;
V_53 = F_69 ( V_79 , V_78 ) ;
if ( V_53 )
F_51 ( V_53 ) ;
else
V_78 = V_104 ;
F_11 ( V_12 ) ;
return V_78 ;
}
void
F_71 ( struct V_2 * V_2 , T_5 V_78 )
{
struct V_52 * V_53 ;
struct V_1 * V_79 = F_1 ( V_2 ) ;
F_15 ( V_12 ) ;
if ( ! V_79 -> V_107 ) {
V_53 = F_69 ( V_79 , V_78 ) ;
if ( V_53 != NULL )
F_54 ( V_53 ) ;
}
F_11 ( V_12 ) ;
}
static inline bool
F_72 ( const struct V_33 * const V_38 [] )
{
return ! V_38 [ V_108 ] ||
F_73 ( V_38 [ V_108 ] ) != V_24 ;
}
static inline T_4
F_74 ( const struct V_109 * V_110 )
{
return V_110 -> V_111 & V_112 ? 0 : V_113 ;
}
static struct V_109 *
F_75 ( struct V_81 * V_82 , T_4 V_114 , T_4 V_115 , unsigned int V_48 ,
enum V_116 V_117 )
{
struct V_109 * V_110 ;
struct V_118 * V_119 ;
V_110 = F_76 ( V_82 , V_114 , V_115 , V_117 | ( V_12 << 8 ) ,
sizeof( * V_119 ) , V_48 ) ;
if ( V_110 == NULL )
return NULL ;
V_119 = F_77 ( V_110 ) ;
V_119 -> V_120 = V_121 ;
V_119 -> V_122 = V_123 ;
V_119 -> V_124 = 0 ;
return V_110 ;
}
static struct V_52 *
F_78 ( struct V_1 * V_79 , const char * V_6 , T_5 * V_47 )
{
struct V_52 * V_53 = NULL ;
T_5 V_103 ;
* V_47 = V_104 ;
for ( V_103 = 0 ; V_103 < V_79 -> V_106 ; V_103 ++ ) {
V_53 = F_69 ( V_79 , V_103 ) ;
if ( V_53 != NULL && F_9 ( V_53 -> V_6 , V_6 ) ) {
* V_47 = V_103 ;
break;
}
}
return ( * V_47 == V_104 ? NULL : V_53 ) ;
}
static inline struct V_52 *
F_79 ( struct V_1 * V_79 , const char * V_6 )
{
T_5 V_47 ;
return F_78 ( V_79 , V_6 , & V_47 ) ;
}
static int
F_80 ( struct V_1 * V_79 , const char * V_6 , T_5 * V_78 ,
struct V_52 * * V_53 )
{
struct V_52 * V_105 ;
T_5 V_103 ;
* V_78 = V_104 ;
for ( V_103 = 0 ; V_103 < V_79 -> V_106 ; V_103 ++ ) {
V_105 = F_69 ( V_79 , V_103 ) ;
if ( V_105 == NULL ) {
if ( * V_78 == V_104 )
* V_78 = V_103 ;
} else if ( F_9 ( V_6 , V_105 -> V_6 ) ) {
* V_53 = V_105 ;
return - V_125 ;
}
}
if ( * V_78 == V_104 )
return - V_126 ;
return 0 ;
}
static int
F_81 ( struct V_127 * V_128 , struct V_81 * V_82 ,
const struct V_109 * V_110 ,
const struct V_33 * const V_129 [] )
{
return - V_130 ;
}
static int
F_82 ( struct V_127 * V_128 , struct V_81 * V_82 ,
const struct V_109 * V_110 ,
const struct V_33 * const V_129 [] )
{
struct V_2 * V_2 = F_83 ( V_128 ) ;
struct V_1 * V_79 = F_1 ( V_2 ) ;
struct V_52 * V_53 , * V_131 = NULL ;
T_5 V_78 = V_104 ;
struct V_33 * V_38 [ V_132 + 1 ] = {} ;
const char * V_6 , * V_133 ;
T_1 V_7 , V_8 ;
T_4 V_48 = F_74 ( V_110 ) ;
int V_22 = 0 ;
if ( F_36 ( F_72 ( V_129 ) ||
V_129 [ V_134 ] == NULL ||
V_129 [ V_135 ] == NULL ||
V_129 [ V_136 ] == NULL ||
V_129 [ V_137 ] == NULL ||
( V_129 [ V_138 ] != NULL &&
! F_34 ( V_129 [ V_138 ] ) ) ) )
return - V_40 ;
V_6 = F_41 ( V_129 [ V_134 ] ) ;
V_133 = F_41 ( V_129 [ V_135 ] ) ;
V_7 = F_73 ( V_129 [ V_137 ] ) ;
V_8 = F_73 ( V_129 [ V_136 ] ) ;
F_12 ( L_18 ,
V_6 , V_133 , F_22 ( V_7 ) , V_8 ) ;
V_53 = F_28 ( sizeof( struct V_52 ) , V_31 ) ;
if ( ! V_53 )
return - V_139 ;
F_84 ( & V_53 -> V_91 ) ;
F_85 ( V_53 -> V_6 , V_6 , V_140 ) ;
V_53 -> V_7 = V_7 ;
V_53 -> V_8 = V_8 ;
V_22 = F_86 ( V_133 , V_7 , V_8 , & ( V_53 -> type ) ) ;
if ( V_22 )
goto V_88;
if ( V_129 [ V_138 ] &&
F_37 ( V_38 , V_132 , V_129 [ V_138 ] ,
V_53 -> type -> V_141 ) ) {
V_22 = - V_40 ;
goto V_142;
}
V_22 = V_53 -> type -> V_143 ( V_2 , V_53 , V_38 , V_48 ) ;
if ( V_22 != 0 )
goto V_142;
V_22 = F_80 ( V_79 , V_53 -> V_6 , & V_78 , & V_131 ) ;
if ( V_22 == - V_125 ) {
if ( ( V_48 & V_113 ) &&
F_9 ( V_53 -> type -> V_6 , V_131 -> type -> V_6 ) &&
V_53 -> type -> V_7 == V_131 -> type -> V_7 &&
V_53 -> type -> V_10 == V_131 -> type -> V_10 &&
V_53 -> type -> V_11 == V_131 -> type -> V_11 &&
V_53 -> V_92 -> V_144 ( V_53 , V_131 ) )
V_22 = 0 ;
goto V_145;
} else if ( V_22 == - V_126 ) {
struct V_52 * * V_26 , * * V_146 ;
T_5 V_103 = V_79 -> V_106 + V_147 ;
if ( V_103 < V_79 -> V_106 || V_103 == V_104 )
goto V_145;
V_26 = F_28 ( sizeof( struct V_52 * ) * V_103 , V_31 ) ;
if ( ! V_26 )
goto V_145;
V_146 = F_87 ( V_79 -> V_80 ) ;
memcpy ( V_26 , V_146 , sizeof( struct V_52 * ) * V_79 -> V_106 ) ;
F_88 ( V_79 -> V_80 , V_26 ) ;
F_89 () ;
V_78 = V_79 -> V_106 ;
V_79 -> V_106 = V_103 ;
F_33 ( V_146 ) ;
V_22 = 0 ;
} else if ( V_22 )
goto V_145;
F_12 ( L_19 , V_53 -> V_6 , V_78 ) ;
F_69 ( V_79 , V_78 ) = V_53 ;
return V_22 ;
V_145:
V_53 -> V_92 -> V_148 ( V_53 ) ;
V_142:
F_90 ( V_53 -> type -> V_17 ) ;
V_88:
F_33 ( V_53 ) ;
return V_22 ;
}
static void
F_91 ( struct V_1 * V_79 , T_5 V_78 )
{
struct V_52 * V_53 = F_69 ( V_79 , V_78 ) ;
F_12 ( L_20 , V_53 -> V_6 ) ;
F_69 ( V_79 , V_78 ) = NULL ;
V_53 -> V_92 -> V_148 ( V_53 ) ;
F_90 ( V_53 -> type -> V_17 ) ;
F_33 ( V_53 ) ;
}
static int
F_92 ( struct V_127 * V_128 , struct V_81 * V_82 ,
const struct V_109 * V_110 ,
const struct V_33 * const V_129 [] )
{
struct V_1 * V_79 = F_1 ( F_83 ( V_128 ) ) ;
struct V_52 * V_105 ;
T_5 V_103 ;
int V_22 = 0 ;
if ( F_36 ( F_72 ( V_129 ) ) )
return - V_40 ;
F_60 ( & V_76 ) ;
if ( ! V_129 [ V_134 ] ) {
for ( V_103 = 0 ; V_103 < V_79 -> V_106 ; V_103 ++ ) {
V_105 = F_69 ( V_79 , V_103 ) ;
if ( V_105 != NULL && V_105 -> V_77 ) {
V_22 = - V_149 ;
goto V_88;
}
}
F_61 ( & V_76 ) ;
for ( V_103 = 0 ; V_103 < V_79 -> V_106 ; V_103 ++ ) {
V_105 = F_69 ( V_79 , V_103 ) ;
if ( V_105 != NULL )
F_91 ( V_79 , V_103 ) ;
}
} else {
V_105 = F_78 ( V_79 , F_41 ( V_129 [ V_134 ] ) ,
& V_103 ) ;
if ( V_105 == NULL ) {
V_22 = - V_150 ;
goto V_88;
} else if ( V_105 -> V_77 ) {
V_22 = - V_149 ;
goto V_88;
}
F_61 ( & V_76 ) ;
F_91 ( V_79 , V_103 ) ;
}
return 0 ;
V_88:
F_61 ( & V_76 ) ;
return V_22 ;
}
static void
F_93 ( struct V_52 * V_53 )
{
F_12 ( L_20 , V_53 -> V_6 ) ;
F_52 ( & V_53 -> V_91 ) ;
V_53 -> V_92 -> V_151 ( V_53 ) ;
F_53 ( & V_53 -> V_91 ) ;
}
static int
F_94 ( struct V_127 * V_128 , struct V_81 * V_82 ,
const struct V_109 * V_110 ,
const struct V_33 * const V_129 [] )
{
struct V_1 * V_79 = F_1 ( F_83 ( V_128 ) ) ;
struct V_52 * V_105 ;
T_5 V_103 ;
if ( F_36 ( F_72 ( V_129 ) ) )
return - V_40 ;
if ( ! V_129 [ V_134 ] ) {
for ( V_103 = 0 ; V_103 < V_79 -> V_106 ; V_103 ++ ) {
V_105 = F_69 ( V_79 , V_103 ) ;
if ( V_105 != NULL )
F_93 ( V_105 ) ;
}
} else {
V_105 = F_79 ( V_79 , F_41 ( V_129 [ V_134 ] ) ) ;
if ( V_105 == NULL )
return - V_150 ;
F_93 ( V_105 ) ;
}
return 0 ;
}
static int
F_95 ( struct V_127 * V_128 , struct V_81 * V_82 ,
const struct V_109 * V_110 ,
const struct V_33 * const V_129 [] )
{
struct V_1 * V_79 = F_1 ( F_83 ( V_128 ) ) ;
struct V_52 * V_53 , * V_105 ;
const char * V_152 ;
T_5 V_103 ;
int V_22 = 0 ;
if ( F_36 ( F_72 ( V_129 ) ||
V_129 [ V_134 ] == NULL ||
V_129 [ V_153 ] == NULL ) )
return - V_40 ;
V_53 = F_79 ( V_79 , F_41 ( V_129 [ V_134 ] ) ) ;
if ( V_53 == NULL )
return - V_150 ;
F_60 ( & V_76 ) ;
if ( V_53 -> V_77 != 0 ) {
V_22 = - V_154 ;
goto V_88;
}
V_152 = F_41 ( V_129 [ V_153 ] ) ;
for ( V_103 = 0 ; V_103 < V_79 -> V_106 ; V_103 ++ ) {
V_105 = F_69 ( V_79 , V_103 ) ;
if ( V_105 != NULL && F_9 ( V_105 -> V_6 , V_152 ) ) {
V_22 = - V_155 ;
goto V_88;
}
}
strncpy ( V_53 -> V_6 , V_152 , V_140 ) ;
V_88:
F_61 ( & V_76 ) ;
return V_22 ;
}
static int
F_96 ( struct V_127 * V_128 , struct V_81 * V_82 ,
const struct V_109 * V_110 ,
const struct V_33 * const V_129 [] )
{
struct V_1 * V_79 = F_1 ( F_83 ( V_128 ) ) ;
struct V_52 * V_156 , * V_157 ;
T_5 V_158 , V_159 ;
char V_160 [ V_140 ] ;
if ( F_36 ( F_72 ( V_129 ) ||
V_129 [ V_134 ] == NULL ||
V_129 [ V_153 ] == NULL ) )
return - V_40 ;
V_156 = F_78 ( V_79 , F_41 ( V_129 [ V_134 ] ) ,
& V_158 ) ;
if ( V_156 == NULL )
return - V_150 ;
V_157 = F_78 ( V_79 , F_41 ( V_129 [ V_153 ] ) ,
& V_159 ) ;
if ( V_157 == NULL )
return - V_155 ;
if ( ! ( V_156 -> type -> V_99 == V_157 -> type -> V_99 &&
V_156 -> V_7 == V_157 -> V_7 ) )
return - V_161 ;
strncpy ( V_160 , V_156 -> V_6 , V_140 ) ;
strncpy ( V_156 -> V_6 , V_157 -> V_6 , V_140 ) ;
strncpy ( V_157 -> V_6 , V_160 , V_140 ) ;
F_52 ( & V_76 ) ;
F_97 ( V_156 -> V_77 , V_157 -> V_77 ) ;
F_69 ( V_79 , V_158 ) = V_157 ;
F_69 ( V_79 , V_159 ) = V_156 ;
F_53 ( & V_76 ) ;
return 0 ;
}
static int
F_98 ( struct V_162 * V_163 )
{
struct V_1 * V_79 = (struct V_1 * ) V_163 -> args [ V_164 ] ;
if ( V_163 -> args [ V_165 ] ) {
F_12 ( L_21 ,
F_69 ( V_79 , V_163 -> args [ V_166 ] ) -> V_6 ) ;
F_65 ( V_79 ,
( T_5 ) V_163 -> args [ V_166 ] ) ;
}
return 0 ;
}
static inline void
F_99 ( struct V_109 * V_110 )
{
const struct V_33 * V_129 ;
int V_167 ;
F_12 ( L_22 ) ;
F_100 (attr, nlh, sizeof(struct nfgenmsg), rem) {
F_12 ( L_23 , V_35 ( V_129 ) , V_129 -> V_168 ) ;
}
}
static int
F_101 ( struct V_162 * V_163 , struct V_1 * V_79 )
{
struct V_109 * V_110 = F_102 ( V_163 -> V_82 ) ;
int V_169 = F_103 ( sizeof( struct V_118 ) ) ;
struct V_33 * V_170 [ V_171 + 1 ] ;
struct V_33 * V_129 = ( void * ) V_110 + V_169 ;
T_4 V_172 ;
T_5 V_78 ;
F_104 ( V_170 , V_171 ,
V_129 , V_110 -> V_173 - V_169 , V_174 ) ;
if ( V_170 [ V_134 ] ) {
struct V_52 * V_53 ;
V_53 = F_78 ( V_79 , F_41 ( V_170 [ V_134 ] ) ,
& V_78 ) ;
if ( V_53 == NULL )
return - V_150 ;
V_172 = V_175 ;
V_163 -> args [ V_166 ] = V_78 ;
} else
V_172 = V_176 ;
if ( V_170 [ V_177 ] ) {
T_4 V_178 = F_44 ( V_170 [ V_177 ] ) ;
V_172 |= ( V_178 << 16 ) ;
}
V_163 -> args [ V_164 ] = ( unsigned long ) V_79 ;
V_163 -> args [ V_179 ] = V_172 ;
return 0 ;
}
static int
F_105 ( struct V_81 * V_82 , struct V_162 * V_163 )
{
T_5 V_78 = V_104 , V_21 ;
struct V_52 * V_53 = NULL ;
struct V_109 * V_110 = NULL ;
unsigned int V_48 = F_106 ( V_163 -> V_82 ) . V_114 ? V_180 : 0 ;
struct V_1 * V_79 = F_1 ( F_83 ( V_82 -> V_181 ) ) ;
T_4 V_172 , V_182 ;
int V_22 = 0 ;
if ( ! V_163 -> args [ V_179 ] ) {
V_22 = F_101 ( V_163 , V_79 ) ;
if ( V_22 < 0 ) {
V_110 = F_102 ( V_163 -> V_82 ) ;
if ( V_110 -> V_111 & V_183 )
F_107 ( V_163 -> V_82 , V_110 , V_22 ) ;
return V_22 ;
}
}
if ( V_163 -> args [ V_166 ] >= V_79 -> V_106 )
goto V_88;
V_172 = F_108 ( V_163 -> args [ V_179 ] ) ;
V_182 = F_109 ( V_163 -> args [ V_179 ] ) ;
V_21 = V_172 == V_175 ? V_163 -> args [ V_166 ] + 1
: V_79 -> V_106 ;
V_184:
F_12 ( L_24 ,
V_172 , V_182 , V_163 -> args [ V_166 ] ) ;
for (; V_163 -> args [ V_166 ] < V_21 ; V_163 -> args [ V_166 ] ++ ) {
V_78 = ( T_5 ) V_163 -> args [ V_166 ] ;
V_53 = F_69 ( V_79 , V_78 ) ;
if ( V_53 == NULL ) {
if ( V_172 == V_175 ) {
V_22 = - V_150 ;
goto V_88;
}
continue;
}
if ( V_172 != V_175 &&
( ( V_172 == V_176 ) ==
! ! ( V_53 -> type -> V_99 & V_185 ) ) )
continue;
F_12 ( L_25 , V_53 -> V_6 ) ;
if ( ! V_163 -> args [ V_165 ] ) {
F_12 ( L_26 ) ;
F_51 ( V_53 ) ;
}
V_110 = F_75 ( V_82 , F_106 ( V_163 -> V_82 ) . V_114 ,
V_163 -> V_110 -> V_186 , V_48 ,
V_187 ) ;
if ( ! V_110 ) {
V_22 = - V_188 ;
goto V_189;
}
if ( F_110 ( V_82 , V_108 , V_24 ) ||
F_111 ( V_82 , V_134 , V_53 -> V_6 ) )
goto V_190;
if ( V_182 & V_191 )
goto V_192;
switch ( V_163 -> args [ V_165 ] ) {
case 0 :
if ( F_111 ( V_82 , V_135 ,
V_53 -> type -> V_6 ) ||
F_110 ( V_82 , V_137 ,
V_53 -> V_7 ) ||
F_110 ( V_82 , V_136 ,
V_53 -> V_8 ) )
goto V_190;
V_22 = V_53 -> V_92 -> V_193 ( V_53 , V_82 ) ;
if ( V_22 < 0 )
goto V_189;
if ( V_182 & V_194 )
goto V_192;
default:
F_60 ( & V_53 -> V_91 ) ;
V_22 = V_53 -> V_92 -> V_26 ( V_53 , V_82 , V_163 ) ;
F_61 ( & V_53 -> V_91 ) ;
if ( ! V_163 -> args [ V_165 ] )
goto V_192;
goto V_189;
}
}
if ( V_172 == V_176 ) {
V_172 = V_195 ;
V_163 -> args [ V_179 ] = V_172 | ( V_182 << 16 ) ;
V_163 -> args [ V_166 ] = 0 ;
goto V_184;
}
goto V_88;
V_190:
V_22 = - V_18 ;
V_192:
if ( V_172 == V_175 )
V_163 -> args [ V_166 ] = V_104 ;
else
V_163 -> args [ V_166 ] ++ ;
V_189:
if ( V_22 || ! V_163 -> args [ V_165 ] ) {
F_12 ( L_21 , F_69 ( V_79 , V_78 ) -> V_6 ) ;
F_65 ( V_79 , V_78 ) ;
V_163 -> args [ V_165 ] = 0 ;
}
V_88:
if ( V_110 ) {
F_112 ( V_82 , V_110 ) ;
F_12 ( L_27 , V_110 -> V_173 ) ;
F_99 ( V_110 ) ;
}
return V_22 < 0 ? V_22 : V_82 -> V_54 ;
}
static int
F_113 ( struct V_127 * V_128 , struct V_81 * V_82 ,
const struct V_109 * V_110 ,
const struct V_33 * const V_129 [] )
{
if ( F_36 ( F_72 ( V_129 ) ) )
return - V_40 ;
{
struct V_196 V_197 = {
. V_198 = F_105 ,
. V_199 = F_98 ,
} ;
return F_114 ( V_128 , V_82 , V_110 , & V_197 ) ;
}
}
static int
F_115 ( struct V_127 * V_128 , struct V_81 * V_82 , struct V_52 * V_53 ,
struct V_33 * V_38 [] , enum V_200 V_201 ,
T_4 V_48 , bool V_202 )
{
int V_22 ;
T_4 V_203 = 0 ;
bool V_204 = V_48 & V_113 , V_205 = false ;
do {
F_52 ( & V_53 -> V_91 ) ;
V_22 = V_53 -> V_92 -> V_206 ( V_53 , V_38 , V_201 , & V_203 , V_48 , V_205 ) ;
F_53 ( & V_53 -> V_91 ) ;
V_205 = true ;
} while ( V_22 == - V_95 &&
V_53 -> V_92 -> V_207 &&
( V_22 = V_53 -> V_92 -> V_207 ( V_53 , V_205 ) ) == 0 );
if ( ! V_22 || ( V_22 == - V_208 && V_204 ) )
return 0 ;
if ( V_203 && V_202 ) {
struct V_109 * V_209 , * V_110 = F_102 ( V_82 ) ;
struct V_81 * V_210 ;
struct V_211 * V_212 ;
T_2 V_213 = sizeof( * V_212 ) + V_173 ( V_110 ) ;
int V_169 = F_103 ( sizeof( struct V_118 ) ) ;
struct V_33 * V_170 [ V_171 + 1 ] ;
struct V_33 * V_214 ;
T_4 * V_215 ;
V_210 = F_116 ( V_213 , V_31 ) ;
if ( V_210 == NULL )
return - V_139 ;
V_209 = F_117 ( V_210 , F_106 ( V_82 ) . V_114 ,
V_110 -> V_186 , V_216 , V_213 , 0 ) ;
V_212 = F_77 ( V_209 ) ;
V_212 -> error = V_22 ;
memcpy ( & V_212 -> V_217 , V_110 , V_110 -> V_173 ) ;
V_214 = ( void * ) & V_212 -> V_217 + V_169 ;
F_104 ( V_170 , V_171 ,
V_214 , V_110 -> V_173 - V_169 ,
V_218 ) ;
V_215 = F_41 ( V_170 [ V_219 ] ) ;
* V_215 = V_203 ;
F_118 ( V_128 , V_210 , F_106 ( V_82 ) . V_114 , V_220 ) ;
return - V_221 ;
}
return V_22 ;
}
static int
F_119 ( struct V_127 * V_128 , struct V_81 * V_82 ,
const struct V_109 * V_110 ,
const struct V_33 * const V_129 [] )
{
struct V_1 * V_79 = F_1 ( F_83 ( V_128 ) ) ;
struct V_52 * V_53 ;
struct V_33 * V_38 [ V_222 + 1 ] = {} ;
const struct V_33 * V_34 ;
T_4 V_48 = F_74 ( V_110 ) ;
bool V_202 ;
int V_22 = 0 ;
if ( F_36 ( F_72 ( V_129 ) ||
V_129 [ V_134 ] == NULL ||
! ( ( V_129 [ V_138 ] != NULL ) ^
( V_129 [ V_223 ] != NULL ) ) ||
( V_129 [ V_138 ] != NULL &&
! F_34 ( V_129 [ V_138 ] ) ) ||
( V_129 [ V_223 ] != NULL &&
( ! F_34 ( V_129 [ V_223 ] ) ||
V_129 [ V_219 ] == NULL ) ) ) )
return - V_40 ;
V_53 = F_79 ( V_79 , F_41 ( V_129 [ V_134 ] ) ) ;
if ( V_53 == NULL )
return - V_150 ;
V_202 = ! ! V_129 [ V_219 ] ;
if ( V_129 [ V_138 ] ) {
if ( F_37 ( V_38 , V_222 ,
V_129 [ V_138 ] ,
V_53 -> type -> V_224 ) )
return - V_40 ;
V_22 = F_115 ( V_128 , V_82 , V_53 , V_38 , V_96 , V_48 ,
V_202 ) ;
} else {
int V_225 ;
F_120 (nla, attr[IPSET_ATTR_ADT], nla_rem) {
memset ( V_38 , 0 , sizeof( V_38 ) ) ;
if ( V_35 ( V_34 ) != V_138 ||
! F_34 ( V_34 ) ||
F_37 ( V_38 , V_222 , V_34 ,
V_53 -> type -> V_224 ) )
return - V_40 ;
V_22 = F_115 ( V_128 , V_82 , V_53 , V_38 , V_96 ,
V_48 , V_202 ) ;
if ( V_22 < 0 )
return V_22 ;
}
}
return V_22 ;
}
static int
F_121 ( struct V_127 * V_128 , struct V_81 * V_82 ,
const struct V_109 * V_110 ,
const struct V_33 * const V_129 [] )
{
struct V_1 * V_79 = F_1 ( F_83 ( V_128 ) ) ;
struct V_52 * V_53 ;
struct V_33 * V_38 [ V_222 + 1 ] = {} ;
const struct V_33 * V_34 ;
T_4 V_48 = F_74 ( V_110 ) ;
bool V_202 ;
int V_22 = 0 ;
if ( F_36 ( F_72 ( V_129 ) ||
V_129 [ V_134 ] == NULL ||
! ( ( V_129 [ V_138 ] != NULL ) ^
( V_129 [ V_223 ] != NULL ) ) ||
( V_129 [ V_138 ] != NULL &&
! F_34 ( V_129 [ V_138 ] ) ) ||
( V_129 [ V_223 ] != NULL &&
( ! F_34 ( V_129 [ V_223 ] ) ||
V_129 [ V_219 ] == NULL ) ) ) )
return - V_40 ;
V_53 = F_79 ( V_79 , F_41 ( V_129 [ V_134 ] ) ) ;
if ( V_53 == NULL )
return - V_150 ;
V_202 = ! ! V_129 [ V_219 ] ;
if ( V_129 [ V_138 ] ) {
if ( F_37 ( V_38 , V_222 ,
V_129 [ V_138 ] ,
V_53 -> type -> V_224 ) )
return - V_40 ;
V_22 = F_115 ( V_128 , V_82 , V_53 , V_38 , V_102 , V_48 ,
V_202 ) ;
} else {
int V_225 ;
F_120 (nla, attr[IPSET_ATTR_ADT], nla_rem) {
memset ( V_38 , 0 , sizeof( * V_38 ) ) ;
if ( V_35 ( V_34 ) != V_138 ||
! F_34 ( V_34 ) ||
F_37 ( V_38 , V_222 , V_34 ,
V_53 -> type -> V_224 ) )
return - V_40 ;
V_22 = F_115 ( V_128 , V_82 , V_53 , V_38 , V_102 ,
V_48 , V_202 ) ;
if ( V_22 < 0 )
return V_22 ;
}
}
return V_22 ;
}
static int
F_122 ( struct V_127 * V_128 , struct V_81 * V_82 ,
const struct V_109 * V_110 ,
const struct V_33 * const V_129 [] )
{
struct V_1 * V_79 = F_1 ( F_83 ( V_128 ) ) ;
struct V_52 * V_53 ;
struct V_33 * V_38 [ V_222 + 1 ] = {} ;
int V_22 = 0 ;
if ( F_36 ( F_72 ( V_129 ) ||
V_129 [ V_134 ] == NULL ||
V_129 [ V_138 ] == NULL ||
! F_34 ( V_129 [ V_138 ] ) ) )
return - V_40 ;
V_53 = F_79 ( V_79 , F_41 ( V_129 [ V_134 ] ) ) ;
if ( V_53 == NULL )
return - V_150 ;
if ( F_37 ( V_38 , V_222 , V_129 [ V_138 ] ,
V_53 -> type -> V_224 ) )
return - V_40 ;
F_60 ( & V_53 -> V_91 ) ;
V_22 = V_53 -> V_92 -> V_206 ( V_53 , V_38 , V_94 , NULL , 0 , 0 ) ;
F_61 ( & V_53 -> V_91 ) ;
if ( V_22 == - V_95 )
V_22 = 1 ;
return V_22 > 0 ? 0 : - V_208 ;
}
static int
F_123 ( struct V_127 * V_128 , struct V_81 * V_82 ,
const struct V_109 * V_110 ,
const struct V_33 * const V_129 [] )
{
struct V_1 * V_79 = F_1 ( F_83 ( V_128 ) ) ;
const struct V_52 * V_53 ;
struct V_81 * V_210 ;
struct V_109 * V_226 ;
int V_22 = 0 ;
if ( F_36 ( F_72 ( V_129 ) ||
V_129 [ V_134 ] == NULL ) )
return - V_40 ;
V_53 = F_79 ( V_79 , F_41 ( V_129 [ V_134 ] ) ) ;
if ( V_53 == NULL )
return - V_150 ;
V_210 = F_116 ( V_227 , V_31 ) ;
if ( V_210 == NULL )
return - V_139 ;
V_226 = F_75 ( V_210 , F_106 ( V_82 ) . V_114 , V_110 -> V_186 , 0 ,
V_228 ) ;
if ( ! V_226 )
goto V_229;
if ( F_110 ( V_210 , V_108 , V_24 ) ||
F_111 ( V_210 , V_134 , V_53 -> V_6 ) ||
F_111 ( V_210 , V_135 , V_53 -> type -> V_6 ) ||
F_110 ( V_210 , V_137 , V_53 -> V_7 ) ||
F_110 ( V_210 , V_136 , V_53 -> V_8 ) )
goto V_190;
F_112 ( V_210 , V_226 ) ;
V_22 = F_118 ( V_128 , V_210 , F_106 ( V_82 ) . V_114 , V_220 ) ;
if ( V_22 < 0 )
return V_22 ;
return 0 ;
V_190:
F_124 ( V_210 , V_226 ) ;
V_229:
F_125 ( V_210 ) ;
return - V_188 ;
}
static int
V_5 ( struct V_127 * V_128 , struct V_81 * V_82 ,
const struct V_109 * V_110 ,
const struct V_33 * const V_129 [] )
{
struct V_81 * V_210 ;
struct V_109 * V_226 ;
T_1 V_7 , V_20 , V_21 ;
const char * V_133 ;
int V_22 = 0 ;
if ( F_36 ( F_72 ( V_129 ) ||
V_129 [ V_135 ] == NULL ||
V_129 [ V_137 ] == NULL ) )
return - V_40 ;
V_7 = F_73 ( V_129 [ V_137 ] ) ;
V_133 = F_41 ( V_129 [ V_135 ] ) ;
V_22 = F_126 ( V_133 , V_7 , & V_20 , & V_21 ) ;
if ( V_22 )
return V_22 ;
V_210 = F_116 ( V_227 , V_31 ) ;
if ( V_210 == NULL )
return - V_139 ;
V_226 = F_75 ( V_210 , F_106 ( V_82 ) . V_114 , V_110 -> V_186 , 0 ,
V_230 ) ;
if ( ! V_226 )
goto V_229;
if ( F_110 ( V_210 , V_108 , V_24 ) ||
F_111 ( V_210 , V_135 , V_133 ) ||
F_110 ( V_210 , V_137 , V_7 ) ||
F_110 ( V_210 , V_136 , V_21 ) ||
F_110 ( V_210 , V_231 , V_20 ) )
goto V_190;
F_112 ( V_210 , V_226 ) ;
F_12 ( L_28 , V_226 -> V_173 ) ;
V_22 = F_118 ( V_128 , V_210 , F_106 ( V_82 ) . V_114 , V_220 ) ;
if ( V_22 < 0 )
return V_22 ;
return 0 ;
V_190:
F_124 ( V_210 , V_226 ) ;
V_229:
F_125 ( V_210 ) ;
return - V_188 ;
}
static int
F_127 ( struct V_127 * V_128 , struct V_81 * V_82 ,
const struct V_109 * V_110 ,
const struct V_33 * const V_129 [] )
{
struct V_81 * V_210 ;
struct V_109 * V_226 ;
int V_22 = 0 ;
if ( F_36 ( V_129 [ V_108 ] == NULL ) )
return - V_40 ;
V_210 = F_116 ( V_227 , V_31 ) ;
if ( V_210 == NULL )
return - V_139 ;
V_226 = F_75 ( V_210 , F_106 ( V_82 ) . V_114 , V_110 -> V_186 , 0 ,
V_232 ) ;
if ( ! V_226 )
goto V_229;
if ( F_110 ( V_210 , V_108 , V_24 ) )
goto V_190;
F_112 ( V_210 , V_226 ) ;
V_22 = F_118 ( V_128 , V_210 , F_106 ( V_82 ) . V_114 , V_220 ) ;
if ( V_22 < 0 )
return V_22 ;
return 0 ;
V_190:
F_124 ( V_210 , V_226 ) ;
V_229:
F_125 ( V_210 ) ;
return - V_188 ;
}
static int
F_128 ( struct V_127 * V_181 , int V_233 , void T_6 * V_234 , int * V_54 )
{
unsigned int * V_235 ;
void * V_236 ;
int V_237 = * V_54 , V_22 = 0 ;
struct V_2 * V_2 = F_83 ( V_181 ) ;
struct V_1 * V_79 = F_1 ( V_2 ) ;
if ( ! F_129 ( V_2 -> V_238 , V_239 ) )
return - V_240 ;
if ( V_233 != V_241 )
return - V_242 ;
if ( * V_54 < sizeof( unsigned int ) )
return - V_25 ;
V_236 = F_130 ( * V_54 ) ;
if ( ! V_236 )
return - V_139 ;
if ( F_131 ( V_236 , V_234 , * V_54 ) != 0 ) {
V_22 = - V_18 ;
goto V_199;
}
V_235 = ( unsigned int * ) V_236 ;
if ( * V_235 < V_243 ) {
struct V_244 * V_245 = V_236 ;
if ( V_245 -> V_122 != V_24 ) {
V_22 = - V_246 ;
goto V_199;
}
}
switch ( * V_235 ) {
case V_243 : {
struct V_244 * V_245 = V_236 ;
if ( * V_54 != sizeof( struct V_244 ) ) {
V_22 = - V_25 ;
goto V_199;
}
V_245 -> V_122 = V_24 ;
V_22 = F_132 ( V_234 , V_245 ,
sizeof( struct V_244 ) ) ;
goto V_199;
}
case V_247 : {
struct V_248 * V_249 = V_236 ;
T_5 V_47 ;
if ( * V_54 != sizeof( struct V_248 ) ) {
V_22 = - V_25 ;
goto V_199;
}
V_249 -> V_53 . V_6 [ V_140 - 1 ] = '\0' ;
F_15 ( V_12 ) ;
F_78 ( V_79 , V_249 -> V_53 . V_6 , & V_47 ) ;
V_249 -> V_53 . V_78 = V_47 ;
F_11 ( V_12 ) ;
goto V_250;
}
case V_251 : {
struct V_252 * V_249 = V_236 ;
T_5 V_47 ;
if ( * V_54 != sizeof( struct V_252 ) ) {
V_22 = - V_25 ;
goto V_199;
}
V_249 -> V_53 . V_6 [ V_140 - 1 ] = '\0' ;
F_15 ( V_12 ) ;
F_78 ( V_79 , V_249 -> V_53 . V_6 , & V_47 ) ;
V_249 -> V_53 . V_78 = V_47 ;
if ( V_47 != V_104 )
V_249 -> V_7 = F_69 ( V_79 , V_47 ) -> V_7 ;
F_11 ( V_12 ) ;
goto V_250;
}
case V_253 : {
struct V_248 * V_249 = V_236 ;
struct V_52 * V_53 ;
if ( * V_54 != sizeof( struct V_248 ) ||
V_249 -> V_53 . V_78 >= V_79 -> V_106 ) {
V_22 = - V_25 ;
goto V_199;
}
F_15 ( V_12 ) ;
V_53 = F_69 ( V_79 , V_249 -> V_53 . V_78 ) ;
strncpy ( V_249 -> V_53 . V_6 , V_53 ? V_53 -> V_6 : L_29 ,
V_140 ) ;
F_11 ( V_12 ) ;
goto V_250;
}
default:
V_22 = - V_254 ;
goto V_199;
}
V_250:
V_22 = F_132 ( V_234 , V_236 , V_237 ) ;
V_199:
F_32 ( V_236 ) ;
if ( V_22 > 0 )
V_22 = 0 ;
return V_22 ;
}
static int T_7
F_133 ( struct V_2 * V_2 )
{
struct V_1 * V_79 = F_1 ( V_2 ) ;
struct V_52 * * V_26 ;
V_79 -> V_106 = V_255 ? V_255 : V_256 ;
if ( V_79 -> V_106 >= V_104 )
V_79 -> V_106 = V_104 - 1 ;
V_26 = F_28 ( sizeof( struct V_52 * ) * V_79 -> V_106 , V_31 ) ;
if ( ! V_26 )
return - V_139 ;
V_79 -> V_107 = 0 ;
F_88 ( V_79 -> V_80 , V_26 ) ;
F_134 ( L_30 , V_24 ) ;
return 0 ;
}
static void T_8
F_135 ( struct V_2 * V_2 )
{
struct V_1 * V_79 = F_1 ( V_2 ) ;
struct V_52 * V_53 = NULL ;
T_5 V_103 ;
V_79 -> V_107 = 1 ;
for ( V_103 = 0 ; V_103 < V_79 -> V_106 ; V_103 ++ ) {
V_53 = F_69 ( V_79 , V_103 ) ;
if ( V_53 != NULL )
F_91 ( V_79 , V_103 ) ;
}
F_33 ( F_136 ( V_79 -> V_80 , 1 ) ) ;
}
static int T_9
F_137 ( void )
{
int V_22 = F_138 ( & V_257 ) ;
if ( V_22 != 0 ) {
F_139 ( L_31 ) ;
return V_22 ;
}
V_22 = F_140 ( & V_258 ) ;
if ( V_22 != 0 ) {
F_139 ( L_32 , V_22 ) ;
F_141 ( & V_257 ) ;
return V_22 ;
}
V_22 = F_142 ( & V_259 ) ;
if ( V_22 ) {
F_139 ( L_33 ) ;
F_143 ( & V_258 ) ;
F_141 ( & V_257 ) ;
return V_22 ;
}
return 0 ;
}
static void T_10
F_144 ( void )
{
F_145 ( & V_259 ) ;
F_143 ( & V_258 ) ;
F_141 ( & V_257 ) ;
F_12 ( L_34 ) ;
}
