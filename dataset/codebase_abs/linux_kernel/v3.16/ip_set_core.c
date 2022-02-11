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
F_32 ( V_29 ) ;
}
static inline bool
F_33 ( const struct V_33 * V_34 )
{
return V_34 -> V_35 & V_36 ;
}
int
F_34 ( struct V_33 * V_34 , T_3 * V_37 )
{
struct V_33 * V_38 [ V_39 + 1 ] ;
if ( F_35 ( ! F_33 ( V_34 ) ) )
return - V_40 ;
if ( F_36 ( V_38 , V_39 , V_34 , V_41 ) )
return - V_40 ;
if ( F_35 ( ! F_37 ( V_38 , V_42 ) ) )
return - V_40 ;
* V_37 = F_38 ( V_38 [ V_42 ] ) ;
return 0 ;
}
int
F_39 ( struct V_33 * V_34 , union V_43 * V_37 )
{
struct V_33 * V_38 [ V_39 + 1 ] ;
if ( F_35 ( ! F_33 ( V_34 ) ) )
return - V_40 ;
if ( F_36 ( V_38 , V_39 , V_34 , V_41 ) )
return - V_40 ;
if ( F_35 ( ! F_37 ( V_38 , V_44 ) ) )
return - V_40 ;
memcpy ( V_37 , F_40 ( V_38 [ V_44 ] ) ,
sizeof( struct V_45 ) ) ;
return 0 ;
}
static inline bool
F_41 ( enum V_46 V_47 , T_4 V_48 , struct V_33 * V_38 [] )
{
return V_49 [ V_47 ] . V_50 ?
( V_48 & V_49 [ V_47 ] . V_50 ) :
! ! V_38 [ V_51 ] ;
}
T_2
F_42 ( struct V_52 * V_53 , struct V_33 * V_38 [] , T_2 V_54 )
{
enum V_46 V_47 ;
T_2 V_55 = 0 ;
T_4 V_56 = 0 ;
if ( V_38 [ V_57 ] )
V_56 = F_43 ( V_38 [ V_57 ] ) ;
if ( V_56 & V_58 )
V_53 -> V_48 |= V_59 ;
for ( V_47 = 0 ; V_47 < V_60 ; V_47 ++ ) {
if ( ! F_41 ( V_47 , V_56 , V_38 ) )
continue;
V_55 += F_44 ( V_54 + V_55 , V_49 [ V_47 ] . V_61 ) ;
V_53 -> V_55 [ V_47 ] = V_55 ;
V_53 -> V_62 |= V_49 [ V_47 ] . type ;
V_55 += V_49 [ V_47 ] . V_54 ;
}
return V_54 + V_55 ;
}
int
F_45 ( struct V_52 * V_53 , struct V_33 * V_38 [] ,
struct V_63 * V_64 )
{
if ( V_38 [ V_51 ] ) {
if ( ! ( V_53 -> V_62 & V_65 ) )
return - V_66 ;
V_64 -> V_67 = F_46 ( V_38 [ V_51 ] ) ;
}
if ( V_38 [ V_68 ] || V_38 [ V_69 ] ) {
if ( ! ( V_53 -> V_62 & V_70 ) )
return - V_71 ;
if ( V_38 [ V_68 ] )
V_64 -> V_72 = F_47 ( F_48 (
V_38 [ V_68 ] ) ) ;
if ( V_38 [ V_69 ] )
V_64 -> V_73 = F_47 ( F_48 (
V_38 [ V_69 ] ) ) ;
}
if ( V_38 [ V_74 ] ) {
if ( ! ( V_53 -> V_62 & V_75 ) )
return - V_76 ;
V_64 -> V_77 = F_49 ( V_38 [ V_74 ] ) ;
}
return 0 ;
}
static inline void
F_50 ( struct V_52 * V_53 )
{
F_51 ( & V_78 ) ;
V_53 -> V_79 ++ ;
F_52 ( & V_78 ) ;
}
static inline void
F_53 ( struct V_52 * V_53 )
{
F_51 ( & V_78 ) ;
F_54 ( V_53 -> V_79 == 0 ) ;
V_53 -> V_79 -- ;
F_52 ( & V_78 ) ;
}
static inline struct V_52 *
F_55 ( struct V_2 * V_2 , T_5 V_80 )
{
struct V_52 * V_53 ;
struct V_1 * V_81 = F_1 ( V_2 ) ;
F_17 () ;
V_53 = F_56 ( V_81 -> V_82 ) [ V_80 ] ;
F_19 () ;
return V_53 ;
}
int
F_57 ( T_5 V_80 , const struct V_83 * V_84 ,
const struct V_85 * V_86 , struct V_87 * V_88 )
{
struct V_52 * V_53 = F_55 (
F_58 ( V_86 -> V_89 ? V_86 -> V_89 : V_86 -> V_90 ) , V_80 ) ;
int V_22 = 0 ;
F_54 ( V_53 == NULL ) ;
F_12 ( L_16 , V_53 -> V_6 , V_80 ) ;
if ( V_88 -> V_91 < V_53 -> type -> V_92 ||
! ( V_88 -> V_7 == V_53 -> V_7 || V_53 -> V_7 == V_9 ) )
return 0 ;
F_59 ( & V_53 -> V_93 ) ;
V_22 = V_53 -> V_94 -> V_95 ( V_53 , V_84 , V_86 , V_96 , V_88 ) ;
F_60 ( & V_53 -> V_93 ) ;
if ( V_22 == - V_97 ) {
F_12 ( L_17 ) ;
F_51 ( & V_53 -> V_93 ) ;
V_53 -> V_94 -> V_95 ( V_53 , V_84 , V_86 , V_98 , V_88 ) ;
F_52 ( & V_53 -> V_93 ) ;
V_22 = 1 ;
} else {
if ( ( V_88 -> V_99 & V_100 ) &&
( V_53 -> type -> V_101 & V_102 ) &&
( V_22 > 0 || V_22 == - V_103 ) )
V_22 = - V_22 ;
}
return ( V_22 < 0 ? 0 : V_22 ) ;
}
int
F_61 ( T_5 V_80 , const struct V_83 * V_84 ,
const struct V_85 * V_86 , struct V_87 * V_88 )
{
struct V_52 * V_53 = F_55 (
F_58 ( V_86 -> V_89 ? V_86 -> V_89 : V_86 -> V_90 ) , V_80 ) ;
int V_22 ;
F_54 ( V_53 == NULL ) ;
F_12 ( L_16 , V_53 -> V_6 , V_80 ) ;
if ( V_88 -> V_91 < V_53 -> type -> V_92 ||
! ( V_88 -> V_7 == V_53 -> V_7 || V_53 -> V_7 == V_9 ) )
return - V_104 ;
F_51 ( & V_53 -> V_93 ) ;
V_22 = V_53 -> V_94 -> V_95 ( V_53 , V_84 , V_86 , V_98 , V_88 ) ;
F_52 ( & V_53 -> V_93 ) ;
return V_22 ;
}
int
F_62 ( T_5 V_80 , const struct V_83 * V_84 ,
const struct V_85 * V_86 , struct V_87 * V_88 )
{
struct V_52 * V_53 = F_55 (
F_58 ( V_86 -> V_89 ? V_86 -> V_89 : V_86 -> V_90 ) , V_80 ) ;
int V_22 = 0 ;
F_54 ( V_53 == NULL ) ;
F_12 ( L_16 , V_53 -> V_6 , V_80 ) ;
if ( V_88 -> V_91 < V_53 -> type -> V_92 ||
! ( V_88 -> V_7 == V_53 -> V_7 || V_53 -> V_7 == V_9 ) )
return - V_104 ;
F_51 ( & V_53 -> V_93 ) ;
V_22 = V_53 -> V_94 -> V_95 ( V_53 , V_84 , V_86 , V_105 , V_88 ) ;
F_52 ( & V_53 -> V_93 ) ;
return V_22 ;
}
T_5
F_63 ( struct V_2 * V_2 , const char * V_6 , struct V_52 * * V_53 )
{
T_5 V_106 , V_80 = V_107 ;
struct V_52 * V_108 ;
struct V_1 * V_81 = F_1 ( V_2 ) ;
F_17 () ;
for ( V_106 = 0 ; V_106 < V_81 -> V_109 ; V_106 ++ ) {
V_108 = F_56 ( V_81 -> V_82 ) [ V_106 ] ;
if ( V_108 != NULL && F_9 ( V_108 -> V_6 , V_6 ) ) {
F_50 ( V_108 ) ;
V_80 = V_106 ;
* V_53 = V_108 ;
break;
}
}
F_19 () ;
return V_80 ;
}
static inline void
F_64 ( struct V_1 * V_81 , T_5 V_80 )
{
struct V_52 * V_53 ;
F_17 () ;
V_53 = F_56 ( V_81 -> V_82 ) [ V_80 ] ;
if ( V_53 != NULL )
F_53 ( V_53 ) ;
F_19 () ;
}
void
F_65 ( struct V_2 * V_2 , T_5 V_80 )
{
struct V_1 * V_81 = F_1 ( V_2 ) ;
F_64 ( V_81 , V_80 ) ;
}
const char *
F_66 ( struct V_2 * V_2 , T_5 V_80 )
{
const struct V_52 * V_53 = F_55 ( V_2 , V_80 ) ;
F_54 ( V_53 == NULL ) ;
F_54 ( V_53 -> V_79 == 0 ) ;
return V_53 -> V_6 ;
}
T_5
F_67 ( struct V_2 * V_2 , T_5 V_80 )
{
struct V_52 * V_53 ;
struct V_1 * V_81 = F_1 ( V_2 ) ;
if ( V_80 > V_81 -> V_109 )
return V_107 ;
F_15 ( V_12 ) ;
V_53 = V_52 ( V_81 , V_80 ) ;
if ( V_53 )
F_50 ( V_53 ) ;
else
V_80 = V_107 ;
F_11 ( V_12 ) ;
return V_80 ;
}
void
F_68 ( struct V_2 * V_2 , T_5 V_80 )
{
struct V_52 * V_53 ;
struct V_1 * V_81 = F_1 ( V_2 ) ;
F_15 ( V_12 ) ;
if ( ! V_81 -> V_110 ) {
V_53 = V_52 ( V_81 , V_80 ) ;
if ( V_53 != NULL )
F_53 ( V_53 ) ;
}
F_11 ( V_12 ) ;
}
static inline bool
F_69 ( const struct V_33 * const V_38 [] )
{
return ! V_38 [ V_111 ] ||
F_70 ( V_38 [ V_111 ] ) != V_24 ;
}
static inline T_4
F_71 ( const struct V_112 * V_113 )
{
return V_113 -> V_114 & V_115 ? 0 : V_116 ;
}
static struct V_112 *
F_72 ( struct V_83 * V_84 , T_4 V_117 , T_4 V_118 , unsigned int V_48 ,
enum V_119 V_120 )
{
struct V_112 * V_113 ;
struct V_121 * V_122 ;
V_113 = F_73 ( V_84 , V_117 , V_118 , V_120 | ( V_12 << 8 ) ,
sizeof( * V_122 ) , V_48 ) ;
if ( V_113 == NULL )
return NULL ;
V_122 = F_74 ( V_113 ) ;
V_122 -> V_123 = V_124 ;
V_122 -> V_125 = V_126 ;
V_122 -> V_127 = 0 ;
return V_113 ;
}
static struct V_52 *
F_75 ( struct V_1 * V_81 , const char * V_6 , T_5 * V_47 )
{
struct V_52 * V_53 = NULL ;
T_5 V_106 ;
* V_47 = V_107 ;
for ( V_106 = 0 ; V_106 < V_81 -> V_109 ; V_106 ++ ) {
V_53 = V_52 ( V_81 , V_106 ) ;
if ( V_53 != NULL && F_9 ( V_53 -> V_6 , V_6 ) ) {
* V_47 = V_106 ;
break;
}
}
return ( * V_47 == V_107 ? NULL : V_53 ) ;
}
static inline struct V_52 *
F_76 ( struct V_1 * V_81 , const char * V_6 )
{
T_5 V_47 ;
return F_75 ( V_81 , V_6 , & V_47 ) ;
}
static int
F_77 ( struct V_1 * V_81 , const char * V_6 , T_5 * V_80 ,
struct V_52 * * V_53 )
{
struct V_52 * V_108 ;
T_5 V_106 ;
* V_80 = V_107 ;
for ( V_106 = 0 ; V_106 < V_81 -> V_109 ; V_106 ++ ) {
V_108 = V_52 ( V_81 , V_106 ) ;
if ( V_108 == NULL ) {
if ( * V_80 == V_107 )
* V_80 = V_106 ;
} else if ( F_9 ( V_6 , V_108 -> V_6 ) ) {
* V_53 = V_108 ;
return - V_128 ;
}
}
if ( * V_80 == V_107 )
return - V_129 ;
return 0 ;
}
static int
F_78 ( struct V_130 * V_131 , struct V_83 * V_84 ,
const struct V_112 * V_113 ,
const struct V_33 * const V_132 [] )
{
return - V_133 ;
}
static int
F_79 ( struct V_130 * V_131 , struct V_83 * V_84 ,
const struct V_112 * V_113 ,
const struct V_33 * const V_132 [] )
{
struct V_2 * V_2 = F_80 ( V_131 ) ;
struct V_1 * V_81 = F_1 ( V_2 ) ;
struct V_52 * V_53 , * V_134 = NULL ;
T_5 V_80 = V_107 ;
struct V_33 * V_38 [ V_135 + 1 ] = {} ;
const char * V_6 , * V_136 ;
T_1 V_7 , V_8 ;
T_4 V_48 = F_71 ( V_113 ) ;
int V_22 = 0 ;
if ( F_35 ( F_69 ( V_132 ) ||
V_132 [ V_137 ] == NULL ||
V_132 [ V_138 ] == NULL ||
V_132 [ V_139 ] == NULL ||
V_132 [ V_140 ] == NULL ||
( V_132 [ V_141 ] != NULL &&
! F_33 ( V_132 [ V_141 ] ) ) ) )
return - V_40 ;
V_6 = F_40 ( V_132 [ V_137 ] ) ;
V_136 = F_40 ( V_132 [ V_138 ] ) ;
V_7 = F_70 ( V_132 [ V_140 ] ) ;
V_8 = F_70 ( V_132 [ V_139 ] ) ;
F_12 ( L_18 ,
V_6 , V_136 , F_22 ( V_7 ) , V_8 ) ;
V_53 = F_28 ( sizeof( struct V_52 ) , V_31 ) ;
if ( ! V_53 )
return - V_142 ;
F_81 ( & V_53 -> V_93 ) ;
F_82 ( V_53 -> V_6 , V_6 , V_143 ) ;
V_53 -> V_7 = V_7 ;
V_53 -> V_8 = V_8 ;
V_22 = F_83 ( V_136 , V_7 , V_8 , & ( V_53 -> type ) ) ;
if ( V_22 )
goto V_90;
if ( V_132 [ V_141 ] &&
F_36 ( V_38 , V_135 , V_132 [ V_141 ] ,
V_53 -> type -> V_144 ) ) {
V_22 = - V_40 ;
goto V_145;
}
V_22 = V_53 -> type -> V_146 ( V_2 , V_53 , V_38 , V_48 ) ;
if ( V_22 != 0 )
goto V_145;
V_22 = F_77 ( V_81 , V_53 -> V_6 , & V_80 , & V_134 ) ;
if ( V_22 == - V_128 ) {
if ( ( V_48 & V_116 ) &&
F_9 ( V_53 -> type -> V_6 , V_134 -> type -> V_6 ) &&
V_53 -> type -> V_7 == V_134 -> type -> V_7 &&
V_53 -> type -> V_10 == V_134 -> type -> V_10 &&
V_53 -> type -> V_11 == V_134 -> type -> V_11 &&
V_53 -> V_94 -> V_147 ( V_53 , V_134 ) )
V_22 = 0 ;
goto V_148;
} else if ( V_22 == - V_129 ) {
struct V_52 * * V_26 , * * V_149 ;
T_5 V_106 = V_81 -> V_109 + V_150 ;
if ( V_106 < V_81 -> V_109 || V_106 == V_107 )
goto V_148;
V_26 = F_28 ( sizeof( struct V_52 * ) * V_106 , V_31 ) ;
if ( ! V_26 )
goto V_148;
V_149 = F_84 ( V_81 -> V_82 ) ;
memcpy ( V_26 , V_149 , sizeof( struct V_52 * ) * V_81 -> V_109 ) ;
F_85 ( V_81 -> V_82 , V_26 ) ;
F_86 () ;
V_80 = V_81 -> V_109 ;
V_81 -> V_109 = V_106 ;
F_87 ( V_149 ) ;
V_22 = 0 ;
} else if ( V_22 )
goto V_148;
F_12 ( L_19 , V_53 -> V_6 , V_80 ) ;
V_52 ( V_81 , V_80 ) = V_53 ;
return V_22 ;
V_148:
V_53 -> V_94 -> V_151 ( V_53 ) ;
V_145:
F_88 ( V_53 -> type -> V_17 ) ;
V_90:
F_87 ( V_53 ) ;
return V_22 ;
}
static void
F_89 ( struct V_1 * V_81 , T_5 V_80 )
{
struct V_52 * V_53 = V_52 ( V_81 , V_80 ) ;
F_12 ( L_20 , V_53 -> V_6 ) ;
V_52 ( V_81 , V_80 ) = NULL ;
V_53 -> V_94 -> V_151 ( V_53 ) ;
F_88 ( V_53 -> type -> V_17 ) ;
F_87 ( V_53 ) ;
}
static int
F_90 ( struct V_130 * V_131 , struct V_83 * V_84 ,
const struct V_112 * V_113 ,
const struct V_33 * const V_132 [] )
{
struct V_1 * V_81 = F_1 ( F_80 ( V_131 ) ) ;
struct V_52 * V_108 ;
T_5 V_106 ;
int V_22 = 0 ;
if ( F_35 ( F_69 ( V_132 ) ) )
return - V_40 ;
F_59 ( & V_78 ) ;
if ( ! V_132 [ V_137 ] ) {
for ( V_106 = 0 ; V_106 < V_81 -> V_109 ; V_106 ++ ) {
V_108 = V_52 ( V_81 , V_106 ) ;
if ( V_108 != NULL && V_108 -> V_79 ) {
V_22 = - V_152 ;
goto V_90;
}
}
F_60 ( & V_78 ) ;
for ( V_106 = 0 ; V_106 < V_81 -> V_109 ; V_106 ++ ) {
V_108 = V_52 ( V_81 , V_106 ) ;
if ( V_108 != NULL )
F_89 ( V_81 , V_106 ) ;
}
} else {
V_108 = F_75 ( V_81 , F_40 ( V_132 [ V_137 ] ) ,
& V_106 ) ;
if ( V_108 == NULL ) {
V_22 = - V_153 ;
goto V_90;
} else if ( V_108 -> V_79 ) {
V_22 = - V_152 ;
goto V_90;
}
F_60 ( & V_78 ) ;
F_89 ( V_81 , V_106 ) ;
}
return 0 ;
V_90:
F_60 ( & V_78 ) ;
return V_22 ;
}
static void
F_91 ( struct V_52 * V_53 )
{
F_12 ( L_20 , V_53 -> V_6 ) ;
F_51 ( & V_53 -> V_93 ) ;
V_53 -> V_94 -> V_154 ( V_53 ) ;
F_52 ( & V_53 -> V_93 ) ;
}
static int
F_92 ( struct V_130 * V_131 , struct V_83 * V_84 ,
const struct V_112 * V_113 ,
const struct V_33 * const V_132 [] )
{
struct V_1 * V_81 = F_1 ( F_80 ( V_131 ) ) ;
struct V_52 * V_108 ;
T_5 V_106 ;
if ( F_35 ( F_69 ( V_132 ) ) )
return - V_40 ;
if ( ! V_132 [ V_137 ] ) {
for ( V_106 = 0 ; V_106 < V_81 -> V_109 ; V_106 ++ ) {
V_108 = V_52 ( V_81 , V_106 ) ;
if ( V_108 != NULL )
F_91 ( V_108 ) ;
}
} else {
V_108 = F_76 ( V_81 , F_40 ( V_132 [ V_137 ] ) ) ;
if ( V_108 == NULL )
return - V_153 ;
F_91 ( V_108 ) ;
}
return 0 ;
}
static int
F_93 ( struct V_130 * V_131 , struct V_83 * V_84 ,
const struct V_112 * V_113 ,
const struct V_33 * const V_132 [] )
{
struct V_1 * V_81 = F_1 ( F_80 ( V_131 ) ) ;
struct V_52 * V_53 , * V_108 ;
const char * V_155 ;
T_5 V_106 ;
int V_22 = 0 ;
if ( F_35 ( F_69 ( V_132 ) ||
V_132 [ V_137 ] == NULL ||
V_132 [ V_156 ] == NULL ) )
return - V_40 ;
V_53 = F_76 ( V_81 , F_40 ( V_132 [ V_137 ] ) ) ;
if ( V_53 == NULL )
return - V_153 ;
F_59 ( & V_78 ) ;
if ( V_53 -> V_79 != 0 ) {
V_22 = - V_157 ;
goto V_90;
}
V_155 = F_40 ( V_132 [ V_156 ] ) ;
for ( V_106 = 0 ; V_106 < V_81 -> V_109 ; V_106 ++ ) {
V_108 = V_52 ( V_81 , V_106 ) ;
if ( V_108 != NULL && F_9 ( V_108 -> V_6 , V_155 ) ) {
V_22 = - V_158 ;
goto V_90;
}
}
strncpy ( V_53 -> V_6 , V_155 , V_143 ) ;
V_90:
F_60 ( & V_78 ) ;
return V_22 ;
}
static int
F_94 ( struct V_130 * V_131 , struct V_83 * V_84 ,
const struct V_112 * V_113 ,
const struct V_33 * const V_132 [] )
{
struct V_1 * V_81 = F_1 ( F_80 ( V_131 ) ) ;
struct V_52 * V_159 , * V_160 ;
T_5 V_161 , V_162 ;
char V_163 [ V_143 ] ;
if ( F_35 ( F_69 ( V_132 ) ||
V_132 [ V_137 ] == NULL ||
V_132 [ V_156 ] == NULL ) )
return - V_40 ;
V_159 = F_75 ( V_81 , F_40 ( V_132 [ V_137 ] ) ,
& V_161 ) ;
if ( V_159 == NULL )
return - V_153 ;
V_160 = F_75 ( V_81 , F_40 ( V_132 [ V_156 ] ) ,
& V_162 ) ;
if ( V_160 == NULL )
return - V_158 ;
if ( ! ( V_159 -> type -> V_101 == V_160 -> type -> V_101 &&
V_159 -> V_7 == V_160 -> V_7 ) )
return - V_104 ;
strncpy ( V_163 , V_159 -> V_6 , V_143 ) ;
strncpy ( V_159 -> V_6 , V_160 -> V_6 , V_143 ) ;
strncpy ( V_160 -> V_6 , V_163 , V_143 ) ;
F_51 ( & V_78 ) ;
F_95 ( V_159 -> V_79 , V_160 -> V_79 ) ;
V_52 ( V_81 , V_161 ) = V_160 ;
V_52 ( V_81 , V_162 ) = V_159 ;
F_52 ( & V_78 ) ;
return 0 ;
}
static int
F_96 ( struct V_164 * V_165 )
{
struct V_1 * V_81 = (struct V_1 * ) V_165 -> args [ V_166 ] ;
if ( V_165 -> args [ V_167 ] ) {
F_12 ( L_21 ,
V_52 ( V_81 , V_165 -> args [ V_168 ] ) -> V_6 ) ;
F_64 ( V_81 ,
( T_5 ) V_165 -> args [ V_168 ] ) ;
}
return 0 ;
}
static inline void
F_97 ( struct V_112 * V_113 )
{
const struct V_33 * V_132 ;
int V_169 ;
F_12 ( L_22 ) ;
F_98 (attr, nlh, sizeof(struct nfgenmsg), rem) {
F_12 ( L_23 , V_35 ( V_132 ) , V_132 -> V_170 ) ;
}
}
static int
F_99 ( struct V_164 * V_165 , struct V_1 * V_81 )
{
struct V_112 * V_113 = F_100 ( V_165 -> V_84 ) ;
int V_171 = F_101 ( sizeof( struct V_121 ) ) ;
struct V_33 * V_172 [ V_173 + 1 ] ;
struct V_33 * V_132 = ( void * ) V_113 + V_171 ;
T_4 V_174 ;
T_5 V_80 ;
F_102 ( V_172 , V_173 ,
V_132 , V_113 -> V_175 - V_171 , V_176 ) ;
if ( V_172 [ V_137 ] ) {
struct V_52 * V_53 ;
V_53 = F_75 ( V_81 , F_40 ( V_172 [ V_137 ] ) ,
& V_80 ) ;
if ( V_53 == NULL )
return - V_153 ;
V_174 = V_177 ;
V_165 -> args [ V_168 ] = V_80 ;
} else
V_174 = V_178 ;
if ( V_172 [ V_179 ] ) {
T_4 V_180 = F_43 ( V_172 [ V_179 ] ) ;
V_174 |= ( V_180 << 16 ) ;
}
V_165 -> args [ V_166 ] = ( unsigned long ) V_81 ;
V_165 -> args [ V_181 ] = V_174 ;
return 0 ;
}
static int
F_103 ( struct V_83 * V_84 , struct V_164 * V_165 )
{
T_5 V_80 = V_107 , V_21 ;
struct V_52 * V_53 = NULL ;
struct V_112 * V_113 = NULL ;
unsigned int V_48 = F_104 ( V_165 -> V_84 ) . V_117 ? V_182 : 0 ;
struct V_1 * V_81 = F_1 ( F_80 ( V_84 -> V_183 ) ) ;
T_4 V_174 , V_184 ;
int V_22 = 0 ;
if ( ! V_165 -> args [ V_181 ] ) {
V_22 = F_99 ( V_165 , V_81 ) ;
if ( V_22 < 0 ) {
V_113 = F_100 ( V_165 -> V_84 ) ;
if ( V_113 -> V_114 & V_185 )
F_105 ( V_165 -> V_84 , V_113 , V_22 ) ;
return V_22 ;
}
}
if ( V_165 -> args [ V_168 ] >= V_81 -> V_109 )
goto V_90;
V_174 = F_106 ( V_165 -> args [ V_181 ] ) ;
V_184 = F_107 ( V_165 -> args [ V_181 ] ) ;
V_21 = V_174 == V_177 ? V_165 -> args [ V_168 ] + 1
: V_81 -> V_109 ;
V_186:
F_12 ( L_24 ,
V_174 , V_184 , V_165 -> args [ V_168 ] ) ;
for (; V_165 -> args [ V_168 ] < V_21 ; V_165 -> args [ V_168 ] ++ ) {
V_80 = ( T_5 ) V_165 -> args [ V_168 ] ;
V_53 = V_52 ( V_81 , V_80 ) ;
if ( V_53 == NULL ) {
if ( V_174 == V_177 ) {
V_22 = - V_153 ;
goto V_90;
}
continue;
}
if ( V_174 != V_177 &&
( ( V_174 == V_178 ) ==
! ! ( V_53 -> type -> V_101 & V_187 ) ) )
continue;
F_12 ( L_25 , V_53 -> V_6 ) ;
if ( ! V_165 -> args [ V_167 ] ) {
F_12 ( L_26 ) ;
F_50 ( V_53 ) ;
}
V_113 = F_72 ( V_84 , F_104 ( V_165 -> V_84 ) . V_117 ,
V_165 -> V_113 -> V_188 , V_48 ,
V_189 ) ;
if ( ! V_113 ) {
V_22 = - V_190 ;
goto V_191;
}
if ( F_108 ( V_84 , V_111 , V_24 ) ||
F_109 ( V_84 , V_137 , V_53 -> V_6 ) )
goto V_192;
if ( V_184 & V_193 )
goto V_194;
switch ( V_165 -> args [ V_167 ] ) {
case 0 :
if ( F_109 ( V_84 , V_138 ,
V_53 -> type -> V_6 ) ||
F_108 ( V_84 , V_140 ,
V_53 -> V_7 ) ||
F_108 ( V_84 , V_139 ,
V_53 -> V_8 ) )
goto V_192;
V_22 = V_53 -> V_94 -> V_195 ( V_53 , V_84 ) ;
if ( V_22 < 0 )
goto V_191;
if ( V_184 & V_196 )
goto V_194;
default:
F_59 ( & V_53 -> V_93 ) ;
V_22 = V_53 -> V_94 -> V_26 ( V_53 , V_84 , V_165 ) ;
F_60 ( & V_53 -> V_93 ) ;
if ( ! V_165 -> args [ V_167 ] )
goto V_194;
goto V_191;
}
}
if ( V_174 == V_178 ) {
V_174 = V_197 ;
V_165 -> args [ V_181 ] = V_174 | ( V_184 << 16 ) ;
V_165 -> args [ V_168 ] = 0 ;
goto V_186;
}
goto V_90;
V_192:
V_22 = - V_18 ;
V_194:
if ( V_174 == V_177 )
V_165 -> args [ V_168 ] = V_107 ;
else
V_165 -> args [ V_168 ] ++ ;
V_191:
if ( V_22 || ! V_165 -> args [ V_167 ] ) {
F_12 ( L_21 , V_52 ( V_81 , V_80 ) -> V_6 ) ;
F_64 ( V_81 , V_80 ) ;
V_165 -> args [ V_167 ] = 0 ;
}
V_90:
if ( V_113 ) {
F_110 ( V_84 , V_113 ) ;
F_12 ( L_27 , V_113 -> V_175 ) ;
F_97 ( V_113 ) ;
}
return V_22 < 0 ? V_22 : V_84 -> V_54 ;
}
static int
F_111 ( struct V_130 * V_131 , struct V_83 * V_84 ,
const struct V_112 * V_113 ,
const struct V_33 * const V_132 [] )
{
if ( F_35 ( F_69 ( V_132 ) ) )
return - V_40 ;
{
struct V_198 V_199 = {
. V_200 = F_103 ,
. V_201 = F_96 ,
} ;
return F_112 ( V_131 , V_84 , V_113 , & V_199 ) ;
}
}
static int
F_113 ( struct V_130 * V_131 , struct V_83 * V_84 , struct V_52 * V_53 ,
struct V_33 * V_38 [] , enum V_202 V_203 ,
T_4 V_48 , bool V_204 )
{
int V_22 ;
T_4 V_205 = 0 ;
bool V_206 = V_48 & V_116 , V_207 = false ;
do {
F_51 ( & V_53 -> V_93 ) ;
V_22 = V_53 -> V_94 -> V_208 ( V_53 , V_38 , V_203 , & V_205 , V_48 , V_207 ) ;
F_52 ( & V_53 -> V_93 ) ;
V_207 = true ;
} while ( V_22 == - V_97 &&
V_53 -> V_94 -> V_209 &&
( V_22 = V_53 -> V_94 -> V_209 ( V_53 , V_207 ) ) == 0 );
if ( ! V_22 || ( V_22 == - V_210 && V_206 ) )
return 0 ;
if ( V_205 && V_204 ) {
struct V_112 * V_211 , * V_113 = F_100 ( V_84 ) ;
struct V_83 * V_212 ;
struct V_213 * V_214 ;
T_2 V_215 = sizeof( * V_214 ) + V_175 ( V_113 ) ;
int V_171 = F_101 ( sizeof( struct V_121 ) ) ;
struct V_33 * V_172 [ V_173 + 1 ] ;
struct V_33 * V_216 ;
T_4 * V_217 ;
V_212 = F_114 ( V_215 , V_31 ) ;
if ( V_212 == NULL )
return - V_142 ;
V_211 = F_115 ( V_212 , F_104 ( V_84 ) . V_117 ,
V_113 -> V_188 , V_218 , V_215 , 0 ) ;
V_214 = F_74 ( V_211 ) ;
V_214 -> error = V_22 ;
memcpy ( & V_214 -> V_219 , V_113 , V_113 -> V_175 ) ;
V_216 = ( void * ) & V_214 -> V_219 + V_171 ;
F_102 ( V_172 , V_173 ,
V_216 , V_113 -> V_175 - V_171 ,
V_220 ) ;
V_217 = F_40 ( V_172 [ V_221 ] ) ;
* V_217 = V_205 ;
F_116 ( V_131 , V_212 , F_104 ( V_84 ) . V_117 , V_222 ) ;
return - V_223 ;
}
return V_22 ;
}
static int
F_117 ( struct V_130 * V_131 , struct V_83 * V_84 ,
const struct V_112 * V_113 ,
const struct V_33 * const V_132 [] )
{
struct V_1 * V_81 = F_1 ( F_80 ( V_131 ) ) ;
struct V_52 * V_53 ;
struct V_33 * V_38 [ V_224 + 1 ] = {} ;
const struct V_33 * V_34 ;
T_4 V_48 = F_71 ( V_113 ) ;
bool V_204 ;
int V_22 = 0 ;
if ( F_35 ( F_69 ( V_132 ) ||
V_132 [ V_137 ] == NULL ||
! ( ( V_132 [ V_141 ] != NULL ) ^
( V_132 [ V_225 ] != NULL ) ) ||
( V_132 [ V_141 ] != NULL &&
! F_33 ( V_132 [ V_141 ] ) ) ||
( V_132 [ V_225 ] != NULL &&
( ! F_33 ( V_132 [ V_225 ] ) ||
V_132 [ V_221 ] == NULL ) ) ) )
return - V_40 ;
V_53 = F_76 ( V_81 , F_40 ( V_132 [ V_137 ] ) ) ;
if ( V_53 == NULL )
return - V_153 ;
V_204 = ! ! V_132 [ V_221 ] ;
if ( V_132 [ V_141 ] ) {
if ( F_36 ( V_38 , V_224 ,
V_132 [ V_141 ] ,
V_53 -> type -> V_226 ) )
return - V_40 ;
V_22 = F_113 ( V_131 , V_84 , V_53 , V_38 , V_98 , V_48 ,
V_204 ) ;
} else {
int V_227 ;
F_118 (nla, attr[IPSET_ATTR_ADT], nla_rem) {
memset ( V_38 , 0 , sizeof( V_38 ) ) ;
if ( V_35 ( V_34 ) != V_141 ||
! F_33 ( V_34 ) ||
F_36 ( V_38 , V_224 , V_34 ,
V_53 -> type -> V_226 ) )
return - V_40 ;
V_22 = F_113 ( V_131 , V_84 , V_53 , V_38 , V_98 ,
V_48 , V_204 ) ;
if ( V_22 < 0 )
return V_22 ;
}
}
return V_22 ;
}
static int
F_119 ( struct V_130 * V_131 , struct V_83 * V_84 ,
const struct V_112 * V_113 ,
const struct V_33 * const V_132 [] )
{
struct V_1 * V_81 = F_1 ( F_80 ( V_131 ) ) ;
struct V_52 * V_53 ;
struct V_33 * V_38 [ V_224 + 1 ] = {} ;
const struct V_33 * V_34 ;
T_4 V_48 = F_71 ( V_113 ) ;
bool V_204 ;
int V_22 = 0 ;
if ( F_35 ( F_69 ( V_132 ) ||
V_132 [ V_137 ] == NULL ||
! ( ( V_132 [ V_141 ] != NULL ) ^
( V_132 [ V_225 ] != NULL ) ) ||
( V_132 [ V_141 ] != NULL &&
! F_33 ( V_132 [ V_141 ] ) ) ||
( V_132 [ V_225 ] != NULL &&
( ! F_33 ( V_132 [ V_225 ] ) ||
V_132 [ V_221 ] == NULL ) ) ) )
return - V_40 ;
V_53 = F_76 ( V_81 , F_40 ( V_132 [ V_137 ] ) ) ;
if ( V_53 == NULL )
return - V_153 ;
V_204 = ! ! V_132 [ V_221 ] ;
if ( V_132 [ V_141 ] ) {
if ( F_36 ( V_38 , V_224 ,
V_132 [ V_141 ] ,
V_53 -> type -> V_226 ) )
return - V_40 ;
V_22 = F_113 ( V_131 , V_84 , V_53 , V_38 , V_105 , V_48 ,
V_204 ) ;
} else {
int V_227 ;
F_118 (nla, attr[IPSET_ATTR_ADT], nla_rem) {
memset ( V_38 , 0 , sizeof( * V_38 ) ) ;
if ( V_35 ( V_34 ) != V_141 ||
! F_33 ( V_34 ) ||
F_36 ( V_38 , V_224 , V_34 ,
V_53 -> type -> V_226 ) )
return - V_40 ;
V_22 = F_113 ( V_131 , V_84 , V_53 , V_38 , V_105 ,
V_48 , V_204 ) ;
if ( V_22 < 0 )
return V_22 ;
}
}
return V_22 ;
}
static int
F_120 ( struct V_130 * V_131 , struct V_83 * V_84 ,
const struct V_112 * V_113 ,
const struct V_33 * const V_132 [] )
{
struct V_1 * V_81 = F_1 ( F_80 ( V_131 ) ) ;
struct V_52 * V_53 ;
struct V_33 * V_38 [ V_224 + 1 ] = {} ;
int V_22 = 0 ;
if ( F_35 ( F_69 ( V_132 ) ||
V_132 [ V_137 ] == NULL ||
V_132 [ V_141 ] == NULL ||
! F_33 ( V_132 [ V_141 ] ) ) )
return - V_40 ;
V_53 = F_76 ( V_81 , F_40 ( V_132 [ V_137 ] ) ) ;
if ( V_53 == NULL )
return - V_153 ;
if ( F_36 ( V_38 , V_224 , V_132 [ V_141 ] ,
V_53 -> type -> V_226 ) )
return - V_40 ;
F_59 ( & V_53 -> V_93 ) ;
V_22 = V_53 -> V_94 -> V_208 ( V_53 , V_38 , V_96 , NULL , 0 , 0 ) ;
F_60 ( & V_53 -> V_93 ) ;
if ( V_22 == - V_97 )
V_22 = 1 ;
return V_22 > 0 ? 0 : - V_210 ;
}
static int
F_121 ( struct V_130 * V_131 , struct V_83 * V_84 ,
const struct V_112 * V_113 ,
const struct V_33 * const V_132 [] )
{
struct V_1 * V_81 = F_1 ( F_80 ( V_131 ) ) ;
const struct V_52 * V_53 ;
struct V_83 * V_212 ;
struct V_112 * V_228 ;
int V_22 = 0 ;
if ( F_35 ( F_69 ( V_132 ) ||
V_132 [ V_137 ] == NULL ) )
return - V_40 ;
V_53 = F_76 ( V_81 , F_40 ( V_132 [ V_137 ] ) ) ;
if ( V_53 == NULL )
return - V_153 ;
V_212 = F_114 ( V_229 , V_31 ) ;
if ( V_212 == NULL )
return - V_142 ;
V_228 = F_72 ( V_212 , F_104 ( V_84 ) . V_117 , V_113 -> V_188 , 0 ,
V_230 ) ;
if ( ! V_228 )
goto V_231;
if ( F_108 ( V_212 , V_111 , V_24 ) ||
F_109 ( V_212 , V_137 , V_53 -> V_6 ) ||
F_109 ( V_212 , V_138 , V_53 -> type -> V_6 ) ||
F_108 ( V_212 , V_140 , V_53 -> V_7 ) ||
F_108 ( V_212 , V_139 , V_53 -> V_8 ) )
goto V_192;
F_110 ( V_212 , V_228 ) ;
V_22 = F_116 ( V_131 , V_212 , F_104 ( V_84 ) . V_117 , V_222 ) ;
if ( V_22 < 0 )
return V_22 ;
return 0 ;
V_192:
F_122 ( V_212 , V_228 ) ;
V_231:
F_123 ( V_212 ) ;
return - V_190 ;
}
static int
V_5 ( struct V_130 * V_131 , struct V_83 * V_84 ,
const struct V_112 * V_113 ,
const struct V_33 * const V_132 [] )
{
struct V_83 * V_212 ;
struct V_112 * V_228 ;
T_1 V_7 , V_20 , V_21 ;
const char * V_136 ;
int V_22 = 0 ;
if ( F_35 ( F_69 ( V_132 ) ||
V_132 [ V_138 ] == NULL ||
V_132 [ V_140 ] == NULL ) )
return - V_40 ;
V_7 = F_70 ( V_132 [ V_140 ] ) ;
V_136 = F_40 ( V_132 [ V_138 ] ) ;
V_22 = F_124 ( V_136 , V_7 , & V_20 , & V_21 ) ;
if ( V_22 )
return V_22 ;
V_212 = F_114 ( V_229 , V_31 ) ;
if ( V_212 == NULL )
return - V_142 ;
V_228 = F_72 ( V_212 , F_104 ( V_84 ) . V_117 , V_113 -> V_188 , 0 ,
V_232 ) ;
if ( ! V_228 )
goto V_231;
if ( F_108 ( V_212 , V_111 , V_24 ) ||
F_109 ( V_212 , V_138 , V_136 ) ||
F_108 ( V_212 , V_140 , V_7 ) ||
F_108 ( V_212 , V_139 , V_21 ) ||
F_108 ( V_212 , V_233 , V_20 ) )
goto V_192;
F_110 ( V_212 , V_228 ) ;
F_12 ( L_28 , V_228 -> V_175 ) ;
V_22 = F_116 ( V_131 , V_212 , F_104 ( V_84 ) . V_117 , V_222 ) ;
if ( V_22 < 0 )
return V_22 ;
return 0 ;
V_192:
F_122 ( V_212 , V_228 ) ;
V_231:
F_123 ( V_212 ) ;
return - V_190 ;
}
static int
F_125 ( struct V_130 * V_131 , struct V_83 * V_84 ,
const struct V_112 * V_113 ,
const struct V_33 * const V_132 [] )
{
struct V_83 * V_212 ;
struct V_112 * V_228 ;
int V_22 = 0 ;
if ( F_35 ( V_132 [ V_111 ] == NULL ) )
return - V_40 ;
V_212 = F_114 ( V_229 , V_31 ) ;
if ( V_212 == NULL )
return - V_142 ;
V_228 = F_72 ( V_212 , F_104 ( V_84 ) . V_117 , V_113 -> V_188 , 0 ,
V_234 ) ;
if ( ! V_228 )
goto V_231;
if ( F_108 ( V_212 , V_111 , V_24 ) )
goto V_192;
F_110 ( V_212 , V_228 ) ;
V_22 = F_116 ( V_131 , V_212 , F_104 ( V_84 ) . V_117 , V_222 ) ;
if ( V_22 < 0 )
return V_22 ;
return 0 ;
V_192:
F_122 ( V_212 , V_228 ) ;
V_231:
F_123 ( V_212 ) ;
return - V_190 ;
}
static int
F_126 ( struct V_130 * V_183 , int V_235 , void T_6 * V_236 , int * V_54 )
{
unsigned int * V_237 ;
void * V_238 ;
int V_239 = * V_54 , V_22 = 0 ;
struct V_2 * V_2 = F_80 ( V_183 ) ;
struct V_1 * V_81 = F_1 ( V_2 ) ;
if ( ! F_127 ( V_2 -> V_240 , V_241 ) )
return - V_242 ;
if ( V_235 != V_243 )
return - V_244 ;
if ( * V_54 < sizeof( unsigned int ) )
return - V_25 ;
V_238 = F_128 ( * V_54 ) ;
if ( ! V_238 )
return - V_142 ;
if ( F_129 ( V_238 , V_236 , * V_54 ) != 0 ) {
V_22 = - V_18 ;
goto V_201;
}
V_237 = ( unsigned int * ) V_238 ;
if ( * V_237 < V_245 ) {
struct V_246 * V_247 = V_238 ;
if ( V_247 -> V_125 != V_24 ) {
V_22 = - V_248 ;
goto V_201;
}
}
switch ( * V_237 ) {
case V_245 : {
struct V_246 * V_247 = V_238 ;
if ( * V_54 != sizeof( struct V_246 ) ) {
V_22 = - V_25 ;
goto V_201;
}
V_247 -> V_125 = V_24 ;
V_22 = F_130 ( V_236 , V_247 ,
sizeof( struct V_246 ) ) ;
goto V_201;
}
case V_249 : {
struct V_250 * V_251 = V_238 ;
T_5 V_47 ;
if ( * V_54 != sizeof( struct V_250 ) ) {
V_22 = - V_25 ;
goto V_201;
}
V_251 -> V_53 . V_6 [ V_143 - 1 ] = '\0' ;
F_15 ( V_12 ) ;
F_75 ( V_81 , V_251 -> V_53 . V_6 , & V_47 ) ;
V_251 -> V_53 . V_80 = V_47 ;
F_11 ( V_12 ) ;
goto V_252;
}
case V_253 : {
struct V_254 * V_251 = V_238 ;
T_5 V_47 ;
if ( * V_54 != sizeof( struct V_254 ) ) {
V_22 = - V_25 ;
goto V_201;
}
V_251 -> V_53 . V_6 [ V_143 - 1 ] = '\0' ;
F_15 ( V_12 ) ;
F_75 ( V_81 , V_251 -> V_53 . V_6 , & V_47 ) ;
V_251 -> V_53 . V_80 = V_47 ;
if ( V_47 != V_107 )
V_251 -> V_7 = V_52 ( V_81 , V_47 ) -> V_7 ;
F_11 ( V_12 ) ;
goto V_252;
}
case V_255 : {
struct V_250 * V_251 = V_238 ;
struct V_52 * V_53 ;
if ( * V_54 != sizeof( struct V_250 ) ||
V_251 -> V_53 . V_80 >= V_81 -> V_109 ) {
V_22 = - V_25 ;
goto V_201;
}
F_15 ( V_12 ) ;
V_53 = V_52 ( V_81 , V_251 -> V_53 . V_80 ) ;
strncpy ( V_251 -> V_53 . V_6 , V_53 ? V_53 -> V_6 : L_29 ,
V_143 ) ;
F_11 ( V_12 ) ;
goto V_252;
}
default:
V_22 = - V_256 ;
goto V_201;
}
V_252:
V_22 = F_130 ( V_236 , V_238 , V_239 ) ;
V_201:
F_131 ( V_238 ) ;
if ( V_22 > 0 )
V_22 = 0 ;
return V_22 ;
}
static int T_7
F_132 ( struct V_2 * V_2 )
{
struct V_1 * V_81 = F_1 ( V_2 ) ;
struct V_52 * * V_26 ;
V_81 -> V_109 = V_257 ? V_257 : V_258 ;
if ( V_81 -> V_109 >= V_107 )
V_81 -> V_109 = V_107 - 1 ;
V_26 = F_28 ( sizeof( struct V_52 * ) * V_81 -> V_109 , V_31 ) ;
if ( ! V_26 )
return - V_142 ;
V_81 -> V_110 = 0 ;
F_85 ( V_81 -> V_82 , V_26 ) ;
return 0 ;
}
static void T_8
F_133 ( struct V_2 * V_2 )
{
struct V_1 * V_81 = F_1 ( V_2 ) ;
struct V_52 * V_53 = NULL ;
T_5 V_106 ;
V_81 -> V_110 = 1 ;
for ( V_106 = 0 ; V_106 < V_81 -> V_109 ; V_106 ++ ) {
V_53 = V_52 ( V_81 , V_106 ) ;
if ( V_53 != NULL )
F_89 ( V_81 , V_106 ) ;
}
F_87 ( F_134 ( V_81 -> V_82 , 1 ) ) ;
}
static int T_9
F_135 ( void )
{
int V_22 = F_136 ( & V_259 ) ;
if ( V_22 != 0 ) {
F_137 ( L_30 ) ;
return V_22 ;
}
V_22 = F_138 ( & V_260 ) ;
if ( V_22 != 0 ) {
F_137 ( L_31 , V_22 ) ;
F_139 ( & V_259 ) ;
return V_22 ;
}
V_22 = F_140 ( & V_261 ) ;
if ( V_22 ) {
F_137 ( L_32 ) ;
F_141 ( & V_260 ) ;
F_139 ( & V_259 ) ;
return V_22 ;
}
F_142 ( L_33 , V_24 ) ;
return 0 ;
}
static void T_10
F_143 ( void )
{
F_144 ( & V_261 ) ;
F_141 ( & V_260 ) ;
F_139 ( & V_259 ) ;
F_12 ( L_34 ) ;
}
