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
F_14 ( L_4 ,
type -> V_6 , F_22 ( type -> V_7 ) ,
type -> V_10 , type -> V_11 ,
type -> V_23 , V_24 ) ;
return - V_25 ;
}
F_3 () ;
if ( F_7 ( type -> V_6 , type -> V_7 , type -> V_10 ) ) {
F_14 ( L_5 ,
type -> V_6 , F_22 ( type -> V_7 ) ,
type -> V_10 ) ;
V_22 = - V_25 ;
goto V_19;
}
F_23 ( & type -> V_26 , & V_27 ) ;
F_12 ( L_6 ,
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
F_14 ( L_7 ,
type -> V_6 , F_22 ( type -> V_7 ) ,
type -> V_10 ) ;
goto V_19;
}
F_25 ( & type -> V_26 ) ;
F_12 ( L_8 ,
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
F_12 ( L_9 , V_29 ) ;
return V_29 ;
}
V_29 = F_29 ( V_28 ) ;
if ( ! V_29 )
return NULL ;
F_12 ( L_10 , V_29 ) ;
return V_29 ;
}
void
F_30 ( void * V_29 )
{
F_12 ( L_11 , V_29 ,
F_31 ( V_29 ) ? L_12 : L_13 ) ;
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
T_5 V_65 ;
if ( V_38 [ V_51 ] ) {
if ( ! ( V_53 -> V_62 & V_66 ) )
return - V_67 ;
V_64 -> V_68 = F_46 ( V_38 [ V_51 ] ) ;
}
if ( V_38 [ V_69 ] || V_38 [ V_70 ] ) {
if ( ! ( V_53 -> V_62 & V_71 ) )
return - V_72 ;
if ( V_38 [ V_69 ] )
V_64 -> V_73 = F_47 ( F_48 (
V_38 [ V_69 ] ) ) ;
if ( V_38 [ V_70 ] )
V_64 -> V_74 = F_47 ( F_48 (
V_38 [ V_70 ] ) ) ;
}
if ( V_38 [ V_75 ] ) {
if ( ! ( V_53 -> V_62 & V_76 ) )
return - V_77 ;
V_64 -> V_78 = F_49 ( V_38 [ V_75 ] ) ;
}
if ( V_38 [ V_79 ] ) {
if ( ! ( V_53 -> V_62 & V_80 ) )
return - V_81 ;
V_65 = F_47 ( F_48 ( V_38 [ V_79 ] ) ) ;
V_64 -> V_82 = V_65 >> 32 ;
V_64 -> V_83 = V_65 & 0xffffffff ;
}
if ( V_38 [ V_84 ] ) {
if ( ! ( V_53 -> V_62 & V_80 ) )
return - V_81 ;
V_64 -> V_85 = F_50 ( F_38 (
V_38 [ V_84 ] ) ) ;
}
if ( V_38 [ V_86 ] ) {
if ( ! ( V_53 -> V_62 & V_80 ) )
return - V_81 ;
V_64 -> V_87 = F_51 ( F_52 (
V_38 [ V_86 ] ) ) ;
}
return 0 ;
}
static inline void
F_53 ( struct V_52 * V_53 )
{
F_54 ( & V_88 ) ;
V_53 -> V_89 ++ ;
F_55 ( & V_88 ) ;
}
static inline void
F_56 ( struct V_52 * V_53 )
{
F_54 ( & V_88 ) ;
F_57 ( V_53 -> V_89 == 0 ) ;
V_53 -> V_89 -- ;
F_55 ( & V_88 ) ;
}
static inline struct V_52 *
F_58 ( struct V_2 * V_2 , T_6 V_90 )
{
struct V_52 * V_53 ;
struct V_1 * V_91 = F_1 ( V_2 ) ;
F_17 () ;
V_53 = F_59 ( V_91 -> V_92 ) [ V_90 ] ;
F_19 () ;
return V_53 ;
}
int
F_60 ( T_6 V_90 , const struct V_93 * V_94 ,
const struct V_95 * V_96 , struct V_97 * V_98 )
{
struct V_52 * V_53 = F_58 (
F_61 ( V_96 -> V_99 ? V_96 -> V_99 : V_96 -> V_100 ) , V_90 ) ;
int V_22 = 0 ;
F_57 ( V_53 == NULL ) ;
F_12 ( L_14 , V_53 -> V_6 , V_90 ) ;
if ( V_98 -> V_101 < V_53 -> type -> V_102 ||
! ( V_98 -> V_7 == V_53 -> V_7 || V_53 -> V_7 == V_9 ) )
return 0 ;
F_62 ( & V_53 -> V_103 ) ;
V_22 = V_53 -> V_104 -> V_105 ( V_53 , V_94 , V_96 , V_106 , V_98 ) ;
F_63 ( & V_53 -> V_103 ) ;
if ( V_22 == - V_107 ) {
F_12 ( L_15 ) ;
F_54 ( & V_53 -> V_103 ) ;
V_53 -> V_104 -> V_105 ( V_53 , V_94 , V_96 , V_108 , V_98 ) ;
F_55 ( & V_53 -> V_103 ) ;
V_22 = 1 ;
} else {
if ( ( V_98 -> V_109 & V_110 ) &&
( V_53 -> type -> V_111 & V_112 ) &&
( V_22 > 0 || V_22 == - V_113 ) )
V_22 = - V_22 ;
}
return ( V_22 < 0 ? 0 : V_22 ) ;
}
int
F_64 ( T_6 V_90 , const struct V_93 * V_94 ,
const struct V_95 * V_96 , struct V_97 * V_98 )
{
struct V_52 * V_53 = F_58 (
F_61 ( V_96 -> V_99 ? V_96 -> V_99 : V_96 -> V_100 ) , V_90 ) ;
int V_22 ;
F_57 ( V_53 == NULL ) ;
F_12 ( L_14 , V_53 -> V_6 , V_90 ) ;
if ( V_98 -> V_101 < V_53 -> type -> V_102 ||
! ( V_98 -> V_7 == V_53 -> V_7 || V_53 -> V_7 == V_9 ) )
return - V_114 ;
F_54 ( & V_53 -> V_103 ) ;
V_22 = V_53 -> V_104 -> V_105 ( V_53 , V_94 , V_96 , V_108 , V_98 ) ;
F_55 ( & V_53 -> V_103 ) ;
return V_22 ;
}
int
F_65 ( T_6 V_90 , const struct V_93 * V_94 ,
const struct V_95 * V_96 , struct V_97 * V_98 )
{
struct V_52 * V_53 = F_58 (
F_61 ( V_96 -> V_99 ? V_96 -> V_99 : V_96 -> V_100 ) , V_90 ) ;
int V_22 = 0 ;
F_57 ( V_53 == NULL ) ;
F_12 ( L_14 , V_53 -> V_6 , V_90 ) ;
if ( V_98 -> V_101 < V_53 -> type -> V_102 ||
! ( V_98 -> V_7 == V_53 -> V_7 || V_53 -> V_7 == V_9 ) )
return - V_114 ;
F_54 ( & V_53 -> V_103 ) ;
V_22 = V_53 -> V_104 -> V_105 ( V_53 , V_94 , V_96 , V_115 , V_98 ) ;
F_55 ( & V_53 -> V_103 ) ;
return V_22 ;
}
T_6
F_66 ( struct V_2 * V_2 , const char * V_6 , struct V_52 * * V_53 )
{
T_6 V_116 , V_90 = V_117 ;
struct V_52 * V_118 ;
struct V_1 * V_91 = F_1 ( V_2 ) ;
F_17 () ;
for ( V_116 = 0 ; V_116 < V_91 -> V_119 ; V_116 ++ ) {
V_118 = F_59 ( V_91 -> V_92 ) [ V_116 ] ;
if ( V_118 != NULL && F_9 ( V_118 -> V_6 , V_6 ) ) {
F_53 ( V_118 ) ;
V_90 = V_116 ;
* V_53 = V_118 ;
break;
}
}
F_19 () ;
return V_90 ;
}
static inline void
F_67 ( struct V_1 * V_91 , T_6 V_90 )
{
struct V_52 * V_53 ;
F_17 () ;
V_53 = F_59 ( V_91 -> V_92 ) [ V_90 ] ;
if ( V_53 != NULL )
F_56 ( V_53 ) ;
F_19 () ;
}
void
F_68 ( struct V_2 * V_2 , T_6 V_90 )
{
struct V_1 * V_91 = F_1 ( V_2 ) ;
F_67 ( V_91 , V_90 ) ;
}
const char *
F_69 ( struct V_2 * V_2 , T_6 V_90 )
{
const struct V_52 * V_53 = F_58 ( V_2 , V_90 ) ;
F_57 ( V_53 == NULL ) ;
F_57 ( V_53 -> V_89 == 0 ) ;
return V_53 -> V_6 ;
}
T_6
F_70 ( struct V_2 * V_2 , T_6 V_90 )
{
struct V_52 * V_53 ;
struct V_1 * V_91 = F_1 ( V_2 ) ;
if ( V_90 >= V_91 -> V_119 )
return V_117 ;
F_15 ( V_12 ) ;
V_53 = V_52 ( V_91 , V_90 ) ;
if ( V_53 )
F_53 ( V_53 ) ;
else
V_90 = V_117 ;
F_11 ( V_12 ) ;
return V_90 ;
}
void
F_71 ( struct V_2 * V_2 , T_6 V_90 )
{
struct V_52 * V_53 ;
struct V_1 * V_91 = F_1 ( V_2 ) ;
F_15 ( V_12 ) ;
if ( ! V_91 -> V_120 ) {
V_53 = V_52 ( V_91 , V_90 ) ;
if ( V_53 != NULL )
F_56 ( V_53 ) ;
}
F_11 ( V_12 ) ;
}
static inline bool
F_72 ( const struct V_33 * const V_38 [] )
{
return ! V_38 [ V_121 ] ||
F_73 ( V_38 [ V_121 ] ) != V_24 ;
}
static inline T_4
F_74 ( const struct V_122 * V_123 )
{
return V_123 -> V_124 & V_125 ? 0 : V_126 ;
}
static struct V_122 *
F_75 ( struct V_93 * V_94 , T_4 V_127 , T_4 V_128 , unsigned int V_48 ,
enum V_129 V_130 )
{
struct V_122 * V_123 ;
struct V_131 * V_132 ;
V_123 = F_76 ( V_94 , V_127 , V_128 , V_130 | ( V_12 << 8 ) ,
sizeof( * V_132 ) , V_48 ) ;
if ( V_123 == NULL )
return NULL ;
V_132 = F_77 ( V_123 ) ;
V_132 -> V_133 = V_134 ;
V_132 -> V_135 = V_136 ;
V_132 -> V_137 = 0 ;
return V_123 ;
}
static struct V_52 *
F_78 ( struct V_1 * V_91 , const char * V_6 , T_6 * V_47 )
{
struct V_52 * V_53 = NULL ;
T_6 V_116 ;
* V_47 = V_117 ;
for ( V_116 = 0 ; V_116 < V_91 -> V_119 ; V_116 ++ ) {
V_53 = V_52 ( V_91 , V_116 ) ;
if ( V_53 != NULL && F_9 ( V_53 -> V_6 , V_6 ) ) {
* V_47 = V_116 ;
break;
}
}
return ( * V_47 == V_117 ? NULL : V_53 ) ;
}
static inline struct V_52 *
F_79 ( struct V_1 * V_91 , const char * V_6 )
{
T_6 V_47 ;
return F_78 ( V_91 , V_6 , & V_47 ) ;
}
static int
F_80 ( struct V_1 * V_91 , const char * V_6 , T_6 * V_90 ,
struct V_52 * * V_53 )
{
struct V_52 * V_118 ;
T_6 V_116 ;
* V_90 = V_117 ;
for ( V_116 = 0 ; V_116 < V_91 -> V_119 ; V_116 ++ ) {
V_118 = V_52 ( V_91 , V_116 ) ;
if ( V_118 == NULL ) {
if ( * V_90 == V_117 )
* V_90 = V_116 ;
} else if ( F_9 ( V_6 , V_118 -> V_6 ) ) {
* V_53 = V_118 ;
return - V_138 ;
}
}
if ( * V_90 == V_117 )
return - V_139 ;
return 0 ;
}
static int
F_81 ( struct V_140 * V_141 , struct V_93 * V_94 ,
const struct V_122 * V_123 ,
const struct V_33 * const V_142 [] )
{
return - V_143 ;
}
static int
F_82 ( struct V_140 * V_141 , struct V_93 * V_94 ,
const struct V_122 * V_123 ,
const struct V_33 * const V_142 [] )
{
struct V_2 * V_2 = F_83 ( V_141 ) ;
struct V_1 * V_91 = F_1 ( V_2 ) ;
struct V_52 * V_53 , * V_144 = NULL ;
T_6 V_90 = V_117 ;
struct V_33 * V_38 [ V_145 + 1 ] = {} ;
const char * V_6 , * V_146 ;
T_1 V_7 , V_8 ;
T_4 V_48 = F_74 ( V_123 ) ;
int V_22 = 0 ;
if ( F_35 ( F_72 ( V_142 ) ||
V_142 [ V_147 ] == NULL ||
V_142 [ V_148 ] == NULL ||
V_142 [ V_149 ] == NULL ||
V_142 [ V_150 ] == NULL ||
( V_142 [ V_151 ] != NULL &&
! F_33 ( V_142 [ V_151 ] ) ) ) )
return - V_40 ;
V_6 = F_40 ( V_142 [ V_147 ] ) ;
V_146 = F_40 ( V_142 [ V_148 ] ) ;
V_7 = F_73 ( V_142 [ V_150 ] ) ;
V_8 = F_73 ( V_142 [ V_149 ] ) ;
F_12 ( L_16 ,
V_6 , V_146 , F_22 ( V_7 ) , V_8 ) ;
V_53 = F_28 ( sizeof( struct V_52 ) , V_31 ) ;
if ( ! V_53 )
return - V_152 ;
F_84 ( & V_53 -> V_103 ) ;
F_85 ( V_53 -> V_6 , V_6 , V_153 ) ;
V_53 -> V_7 = V_7 ;
V_53 -> V_8 = V_8 ;
V_22 = F_86 ( V_146 , V_7 , V_8 , & ( V_53 -> type ) ) ;
if ( V_22 )
goto V_100;
if ( V_142 [ V_151 ] &&
F_36 ( V_38 , V_145 , V_142 [ V_151 ] ,
V_53 -> type -> V_154 ) ) {
V_22 = - V_40 ;
goto V_155;
}
V_22 = V_53 -> type -> V_156 ( V_2 , V_53 , V_38 , V_48 ) ;
if ( V_22 != 0 )
goto V_155;
V_22 = F_80 ( V_91 , V_53 -> V_6 , & V_90 , & V_144 ) ;
if ( V_22 == - V_138 ) {
if ( ( V_48 & V_126 ) &&
F_9 ( V_53 -> type -> V_6 , V_144 -> type -> V_6 ) &&
V_53 -> type -> V_7 == V_144 -> type -> V_7 &&
V_53 -> type -> V_10 == V_144 -> type -> V_10 &&
V_53 -> type -> V_11 == V_144 -> type -> V_11 &&
V_53 -> V_104 -> V_157 ( V_53 , V_144 ) )
V_22 = 0 ;
goto V_158;
} else if ( V_22 == - V_139 ) {
struct V_52 * * V_26 , * * V_159 ;
T_6 V_116 = V_91 -> V_119 + V_160 ;
if ( V_116 < V_91 -> V_119 || V_116 == V_117 )
goto V_158;
V_26 = F_28 ( sizeof( struct V_52 * ) * V_116 , V_31 ) ;
if ( ! V_26 )
goto V_158;
V_159 = F_87 ( V_91 -> V_92 ) ;
memcpy ( V_26 , V_159 , sizeof( struct V_52 * ) * V_91 -> V_119 ) ;
F_88 ( V_91 -> V_92 , V_26 ) ;
F_89 () ;
V_90 = V_91 -> V_119 ;
V_91 -> V_119 = V_116 ;
F_90 ( V_159 ) ;
V_22 = 0 ;
} else if ( V_22 )
goto V_158;
F_12 ( L_17 , V_53 -> V_6 , V_90 ) ;
V_52 ( V_91 , V_90 ) = V_53 ;
return V_22 ;
V_158:
V_53 -> V_104 -> V_161 ( V_53 ) ;
V_155:
F_91 ( V_53 -> type -> V_17 ) ;
V_100:
F_90 ( V_53 ) ;
return V_22 ;
}
static void
F_92 ( struct V_1 * V_91 , T_6 V_90 )
{
struct V_52 * V_53 = V_52 ( V_91 , V_90 ) ;
F_12 ( L_18 , V_53 -> V_6 ) ;
V_52 ( V_91 , V_90 ) = NULL ;
V_53 -> V_104 -> V_161 ( V_53 ) ;
F_91 ( V_53 -> type -> V_17 ) ;
F_90 ( V_53 ) ;
}
static int
F_93 ( struct V_140 * V_141 , struct V_93 * V_94 ,
const struct V_122 * V_123 ,
const struct V_33 * const V_142 [] )
{
struct V_1 * V_91 = F_1 ( F_83 ( V_141 ) ) ;
struct V_52 * V_118 ;
T_6 V_116 ;
int V_22 = 0 ;
if ( F_35 ( F_72 ( V_142 ) ) )
return - V_40 ;
F_62 ( & V_88 ) ;
if ( ! V_142 [ V_147 ] ) {
for ( V_116 = 0 ; V_116 < V_91 -> V_119 ; V_116 ++ ) {
V_118 = V_52 ( V_91 , V_116 ) ;
if ( V_118 != NULL && V_118 -> V_89 ) {
V_22 = - V_162 ;
goto V_100;
}
}
F_63 ( & V_88 ) ;
for ( V_116 = 0 ; V_116 < V_91 -> V_119 ; V_116 ++ ) {
V_118 = V_52 ( V_91 , V_116 ) ;
if ( V_118 != NULL )
F_92 ( V_91 , V_116 ) ;
}
} else {
V_118 = F_78 ( V_91 , F_40 ( V_142 [ V_147 ] ) ,
& V_116 ) ;
if ( V_118 == NULL ) {
V_22 = - V_163 ;
goto V_100;
} else if ( V_118 -> V_89 ) {
V_22 = - V_162 ;
goto V_100;
}
F_63 ( & V_88 ) ;
F_92 ( V_91 , V_116 ) ;
}
return 0 ;
V_100:
F_63 ( & V_88 ) ;
return V_22 ;
}
static void
F_94 ( struct V_52 * V_53 )
{
F_12 ( L_18 , V_53 -> V_6 ) ;
F_54 ( & V_53 -> V_103 ) ;
V_53 -> V_104 -> V_164 ( V_53 ) ;
F_55 ( & V_53 -> V_103 ) ;
}
static int
F_95 ( struct V_140 * V_141 , struct V_93 * V_94 ,
const struct V_122 * V_123 ,
const struct V_33 * const V_142 [] )
{
struct V_1 * V_91 = F_1 ( F_83 ( V_141 ) ) ;
struct V_52 * V_118 ;
T_6 V_116 ;
if ( F_35 ( F_72 ( V_142 ) ) )
return - V_40 ;
if ( ! V_142 [ V_147 ] ) {
for ( V_116 = 0 ; V_116 < V_91 -> V_119 ; V_116 ++ ) {
V_118 = V_52 ( V_91 , V_116 ) ;
if ( V_118 != NULL )
F_94 ( V_118 ) ;
}
} else {
V_118 = F_79 ( V_91 , F_40 ( V_142 [ V_147 ] ) ) ;
if ( V_118 == NULL )
return - V_163 ;
F_94 ( V_118 ) ;
}
return 0 ;
}
static int
F_96 ( struct V_140 * V_141 , struct V_93 * V_94 ,
const struct V_122 * V_123 ,
const struct V_33 * const V_142 [] )
{
struct V_1 * V_91 = F_1 ( F_83 ( V_141 ) ) ;
struct V_52 * V_53 , * V_118 ;
const char * V_165 ;
T_6 V_116 ;
int V_22 = 0 ;
if ( F_35 ( F_72 ( V_142 ) ||
V_142 [ V_147 ] == NULL ||
V_142 [ V_166 ] == NULL ) )
return - V_40 ;
V_53 = F_79 ( V_91 , F_40 ( V_142 [ V_147 ] ) ) ;
if ( V_53 == NULL )
return - V_163 ;
F_62 ( & V_88 ) ;
if ( V_53 -> V_89 != 0 ) {
V_22 = - V_167 ;
goto V_100;
}
V_165 = F_40 ( V_142 [ V_166 ] ) ;
for ( V_116 = 0 ; V_116 < V_91 -> V_119 ; V_116 ++ ) {
V_118 = V_52 ( V_91 , V_116 ) ;
if ( V_118 != NULL && F_9 ( V_118 -> V_6 , V_165 ) ) {
V_22 = - V_168 ;
goto V_100;
}
}
strncpy ( V_53 -> V_6 , V_165 , V_153 ) ;
V_100:
F_63 ( & V_88 ) ;
return V_22 ;
}
static int
F_97 ( struct V_140 * V_141 , struct V_93 * V_94 ,
const struct V_122 * V_123 ,
const struct V_33 * const V_142 [] )
{
struct V_1 * V_91 = F_1 ( F_83 ( V_141 ) ) ;
struct V_52 * V_169 , * V_170 ;
T_6 V_171 , V_172 ;
char V_173 [ V_153 ] ;
if ( F_35 ( F_72 ( V_142 ) ||
V_142 [ V_147 ] == NULL ||
V_142 [ V_166 ] == NULL ) )
return - V_40 ;
V_169 = F_78 ( V_91 , F_40 ( V_142 [ V_147 ] ) ,
& V_171 ) ;
if ( V_169 == NULL )
return - V_163 ;
V_170 = F_78 ( V_91 , F_40 ( V_142 [ V_166 ] ) ,
& V_172 ) ;
if ( V_170 == NULL )
return - V_168 ;
if ( ! ( V_169 -> type -> V_111 == V_170 -> type -> V_111 &&
V_169 -> V_7 == V_170 -> V_7 ) )
return - V_114 ;
strncpy ( V_173 , V_169 -> V_6 , V_153 ) ;
strncpy ( V_169 -> V_6 , V_170 -> V_6 , V_153 ) ;
strncpy ( V_170 -> V_6 , V_173 , V_153 ) ;
F_54 ( & V_88 ) ;
F_98 ( V_169 -> V_89 , V_170 -> V_89 ) ;
V_52 ( V_91 , V_171 ) = V_170 ;
V_52 ( V_91 , V_172 ) = V_169 ;
F_55 ( & V_88 ) ;
return 0 ;
}
static int
F_99 ( struct V_174 * V_175 )
{
struct V_1 * V_91 = (struct V_1 * ) V_175 -> args [ V_176 ] ;
if ( V_175 -> args [ V_177 ] ) {
F_12 ( L_19 ,
V_52 ( V_91 , V_175 -> args [ V_178 ] ) -> V_6 ) ;
F_67 ( V_91 ,
( T_6 ) V_175 -> args [ V_178 ] ) ;
}
return 0 ;
}
static inline void
F_100 ( struct V_122 * V_123 )
{
const struct V_33 * V_142 ;
int V_179 ;
F_12 ( L_20 ) ;
F_101 (attr, nlh, sizeof(struct nfgenmsg), rem) {
F_12 ( L_21 , V_35 ( V_142 ) , V_142 -> V_180 ) ;
}
}
static int
F_102 ( struct V_174 * V_175 , struct V_1 * V_91 )
{
struct V_122 * V_123 = F_103 ( V_175 -> V_94 ) ;
int V_181 = F_104 ( sizeof( struct V_131 ) ) ;
struct V_33 * V_182 [ V_183 + 1 ] ;
struct V_33 * V_142 = ( void * ) V_123 + V_181 ;
T_4 V_184 ;
T_6 V_90 ;
F_105 ( V_182 , V_183 ,
V_142 , V_123 -> V_185 - V_181 , V_186 ) ;
if ( V_182 [ V_147 ] ) {
struct V_52 * V_53 ;
V_53 = F_78 ( V_91 , F_40 ( V_182 [ V_147 ] ) ,
& V_90 ) ;
if ( V_53 == NULL )
return - V_163 ;
V_184 = V_187 ;
V_175 -> args [ V_178 ] = V_90 ;
} else
V_184 = V_188 ;
if ( V_182 [ V_189 ] ) {
T_4 V_190 = F_43 ( V_182 [ V_189 ] ) ;
V_184 |= ( V_190 << 16 ) ;
}
V_175 -> args [ V_176 ] = ( unsigned long ) V_91 ;
V_175 -> args [ V_191 ] = V_184 ;
return 0 ;
}
static int
F_106 ( struct V_93 * V_94 , struct V_174 * V_175 )
{
T_6 V_90 = V_117 , V_21 ;
struct V_52 * V_53 = NULL ;
struct V_122 * V_123 = NULL ;
unsigned int V_48 = F_107 ( V_175 -> V_94 ) . V_127 ? V_192 : 0 ;
struct V_1 * V_91 = F_1 ( F_83 ( V_94 -> V_193 ) ) ;
T_4 V_184 , V_194 ;
int V_22 = 0 ;
if ( ! V_175 -> args [ V_191 ] ) {
V_22 = F_102 ( V_175 , V_91 ) ;
if ( V_22 < 0 ) {
V_123 = F_103 ( V_175 -> V_94 ) ;
if ( V_123 -> V_124 & V_195 )
F_108 ( V_175 -> V_94 , V_123 , V_22 ) ;
return V_22 ;
}
}
if ( V_175 -> args [ V_178 ] >= V_91 -> V_119 )
goto V_100;
V_184 = F_109 ( V_175 -> args [ V_191 ] ) ;
V_194 = F_110 ( V_175 -> args [ V_191 ] ) ;
V_21 = V_184 == V_187 ? V_175 -> args [ V_178 ] + 1
: V_91 -> V_119 ;
V_196:
F_12 ( L_22 ,
V_184 , V_194 , V_175 -> args [ V_178 ] ) ;
for (; V_175 -> args [ V_178 ] < V_21 ; V_175 -> args [ V_178 ] ++ ) {
V_90 = ( T_6 ) V_175 -> args [ V_178 ] ;
V_53 = V_52 ( V_91 , V_90 ) ;
if ( V_53 == NULL ) {
if ( V_184 == V_187 ) {
V_22 = - V_163 ;
goto V_100;
}
continue;
}
if ( V_184 != V_187 &&
( ( V_184 == V_188 ) ==
! ! ( V_53 -> type -> V_111 & V_197 ) ) )
continue;
F_12 ( L_23 , V_53 -> V_6 ) ;
if ( ! V_175 -> args [ V_177 ] ) {
F_12 ( L_24 ) ;
F_53 ( V_53 ) ;
}
V_123 = F_75 ( V_94 , F_107 ( V_175 -> V_94 ) . V_127 ,
V_175 -> V_123 -> V_198 , V_48 ,
V_199 ) ;
if ( ! V_123 ) {
V_22 = - V_200 ;
goto V_201;
}
if ( F_111 ( V_94 , V_121 , V_24 ) ||
F_112 ( V_94 , V_147 , V_53 -> V_6 ) )
goto V_202;
if ( V_194 & V_203 )
goto V_204;
switch ( V_175 -> args [ V_177 ] ) {
case 0 :
if ( F_112 ( V_94 , V_148 ,
V_53 -> type -> V_6 ) ||
F_111 ( V_94 , V_150 ,
V_53 -> V_7 ) ||
F_111 ( V_94 , V_149 ,
V_53 -> V_8 ) )
goto V_202;
V_22 = V_53 -> V_104 -> V_205 ( V_53 , V_94 ) ;
if ( V_22 < 0 )
goto V_201;
if ( V_194 & V_206 )
goto V_204;
default:
F_62 ( & V_53 -> V_103 ) ;
V_22 = V_53 -> V_104 -> V_26 ( V_53 , V_94 , V_175 ) ;
F_63 ( & V_53 -> V_103 ) ;
if ( ! V_175 -> args [ V_177 ] )
goto V_204;
goto V_201;
}
}
if ( V_184 == V_188 ) {
V_184 = V_207 ;
V_175 -> args [ V_191 ] = V_184 | ( V_194 << 16 ) ;
V_175 -> args [ V_178 ] = 0 ;
goto V_196;
}
goto V_100;
V_202:
V_22 = - V_18 ;
V_204:
if ( V_184 == V_187 )
V_175 -> args [ V_178 ] = V_117 ;
else
V_175 -> args [ V_178 ] ++ ;
V_201:
if ( V_22 || ! V_175 -> args [ V_177 ] ) {
F_12 ( L_19 , V_52 ( V_91 , V_90 ) -> V_6 ) ;
F_67 ( V_91 , V_90 ) ;
V_175 -> args [ V_177 ] = 0 ;
}
V_100:
if ( V_123 ) {
F_113 ( V_94 , V_123 ) ;
F_12 ( L_25 , V_123 -> V_185 ) ;
F_100 ( V_123 ) ;
}
return V_22 < 0 ? V_22 : V_94 -> V_54 ;
}
static int
F_114 ( struct V_140 * V_141 , struct V_93 * V_94 ,
const struct V_122 * V_123 ,
const struct V_33 * const V_142 [] )
{
if ( F_35 ( F_72 ( V_142 ) ) )
return - V_40 ;
{
struct V_208 V_209 = {
. V_210 = F_106 ,
. V_211 = F_99 ,
} ;
return F_115 ( V_141 , V_94 , V_123 , & V_209 ) ;
}
}
static int
F_116 ( struct V_140 * V_141 , struct V_93 * V_94 , struct V_52 * V_53 ,
struct V_33 * V_38 [] , enum V_212 V_213 ,
T_4 V_48 , bool V_214 )
{
int V_22 ;
T_4 V_215 = 0 ;
bool V_216 = V_48 & V_126 , V_217 = false ;
do {
F_54 ( & V_53 -> V_103 ) ;
V_22 = V_53 -> V_104 -> V_218 ( V_53 , V_38 , V_213 , & V_215 , V_48 , V_217 ) ;
F_55 ( & V_53 -> V_103 ) ;
V_217 = true ;
} while ( V_22 == - V_107 &&
V_53 -> V_104 -> V_219 &&
( V_22 = V_53 -> V_104 -> V_219 ( V_53 , V_217 ) ) == 0 );
if ( ! V_22 || ( V_22 == - V_220 && V_216 ) )
return 0 ;
if ( V_215 && V_214 ) {
struct V_122 * V_221 , * V_123 = F_103 ( V_94 ) ;
struct V_93 * V_222 ;
struct V_223 * V_224 ;
T_2 V_225 = V_20 ( V_226 ,
sizeof( * V_224 ) + V_185 ( V_123 ) ) ;
int V_181 = F_104 ( sizeof( struct V_131 ) ) ;
struct V_33 * V_182 [ V_183 + 1 ] ;
struct V_33 * V_227 ;
T_4 * V_228 ;
V_222 = F_117 ( V_225 , V_31 ) ;
if ( V_222 == NULL )
return - V_152 ;
V_221 = F_118 ( V_222 , F_107 ( V_94 ) . V_127 ,
V_123 -> V_198 , V_229 , V_225 , 0 ) ;
V_224 = F_77 ( V_221 ) ;
V_224 -> error = V_22 ;
memcpy ( & V_224 -> V_230 , V_123 , V_123 -> V_185 ) ;
V_227 = ( void * ) & V_224 -> V_230 + V_181 ;
F_105 ( V_182 , V_183 ,
V_227 , V_123 -> V_185 - V_181 ,
V_231 ) ;
V_228 = F_40 ( V_182 [ V_232 ] ) ;
* V_228 = V_215 ;
F_119 ( V_141 , V_222 , F_107 ( V_94 ) . V_127 , V_233 ) ;
return - V_234 ;
}
return V_22 ;
}
static int
F_120 ( struct V_140 * V_141 , struct V_93 * V_94 ,
const struct V_122 * V_123 ,
const struct V_33 * const V_142 [] )
{
struct V_1 * V_91 = F_1 ( F_83 ( V_141 ) ) ;
struct V_52 * V_53 ;
struct V_33 * V_38 [ V_235 + 1 ] = {} ;
const struct V_33 * V_34 ;
T_4 V_48 = F_74 ( V_123 ) ;
bool V_214 ;
int V_22 = 0 ;
if ( F_35 ( F_72 ( V_142 ) ||
V_142 [ V_147 ] == NULL ||
! ( ( V_142 [ V_151 ] != NULL ) ^
( V_142 [ V_236 ] != NULL ) ) ||
( V_142 [ V_151 ] != NULL &&
! F_33 ( V_142 [ V_151 ] ) ) ||
( V_142 [ V_236 ] != NULL &&
( ! F_33 ( V_142 [ V_236 ] ) ||
V_142 [ V_232 ] == NULL ) ) ) )
return - V_40 ;
V_53 = F_79 ( V_91 , F_40 ( V_142 [ V_147 ] ) ) ;
if ( V_53 == NULL )
return - V_163 ;
V_214 = ! ! V_142 [ V_232 ] ;
if ( V_142 [ V_151 ] ) {
if ( F_36 ( V_38 , V_235 ,
V_142 [ V_151 ] ,
V_53 -> type -> V_237 ) )
return - V_40 ;
V_22 = F_116 ( V_141 , V_94 , V_53 , V_38 , V_108 , V_48 ,
V_214 ) ;
} else {
int V_238 ;
F_121 (nla, attr[IPSET_ATTR_ADT], nla_rem) {
memset ( V_38 , 0 , sizeof( V_38 ) ) ;
if ( V_35 ( V_34 ) != V_151 ||
! F_33 ( V_34 ) ||
F_36 ( V_38 , V_235 , V_34 ,
V_53 -> type -> V_237 ) )
return - V_40 ;
V_22 = F_116 ( V_141 , V_94 , V_53 , V_38 , V_108 ,
V_48 , V_214 ) ;
if ( V_22 < 0 )
return V_22 ;
}
}
return V_22 ;
}
static int
F_122 ( struct V_140 * V_141 , struct V_93 * V_94 ,
const struct V_122 * V_123 ,
const struct V_33 * const V_142 [] )
{
struct V_1 * V_91 = F_1 ( F_83 ( V_141 ) ) ;
struct V_52 * V_53 ;
struct V_33 * V_38 [ V_235 + 1 ] = {} ;
const struct V_33 * V_34 ;
T_4 V_48 = F_74 ( V_123 ) ;
bool V_214 ;
int V_22 = 0 ;
if ( F_35 ( F_72 ( V_142 ) ||
V_142 [ V_147 ] == NULL ||
! ( ( V_142 [ V_151 ] != NULL ) ^
( V_142 [ V_236 ] != NULL ) ) ||
( V_142 [ V_151 ] != NULL &&
! F_33 ( V_142 [ V_151 ] ) ) ||
( V_142 [ V_236 ] != NULL &&
( ! F_33 ( V_142 [ V_236 ] ) ||
V_142 [ V_232 ] == NULL ) ) ) )
return - V_40 ;
V_53 = F_79 ( V_91 , F_40 ( V_142 [ V_147 ] ) ) ;
if ( V_53 == NULL )
return - V_163 ;
V_214 = ! ! V_142 [ V_232 ] ;
if ( V_142 [ V_151 ] ) {
if ( F_36 ( V_38 , V_235 ,
V_142 [ V_151 ] ,
V_53 -> type -> V_237 ) )
return - V_40 ;
V_22 = F_116 ( V_141 , V_94 , V_53 , V_38 , V_115 , V_48 ,
V_214 ) ;
} else {
int V_238 ;
F_121 (nla, attr[IPSET_ATTR_ADT], nla_rem) {
memset ( V_38 , 0 , sizeof( * V_38 ) ) ;
if ( V_35 ( V_34 ) != V_151 ||
! F_33 ( V_34 ) ||
F_36 ( V_38 , V_235 , V_34 ,
V_53 -> type -> V_237 ) )
return - V_40 ;
V_22 = F_116 ( V_141 , V_94 , V_53 , V_38 , V_115 ,
V_48 , V_214 ) ;
if ( V_22 < 0 )
return V_22 ;
}
}
return V_22 ;
}
static int
F_123 ( struct V_140 * V_141 , struct V_93 * V_94 ,
const struct V_122 * V_123 ,
const struct V_33 * const V_142 [] )
{
struct V_1 * V_91 = F_1 ( F_83 ( V_141 ) ) ;
struct V_52 * V_53 ;
struct V_33 * V_38 [ V_235 + 1 ] = {} ;
int V_22 = 0 ;
if ( F_35 ( F_72 ( V_142 ) ||
V_142 [ V_147 ] == NULL ||
V_142 [ V_151 ] == NULL ||
! F_33 ( V_142 [ V_151 ] ) ) )
return - V_40 ;
V_53 = F_79 ( V_91 , F_40 ( V_142 [ V_147 ] ) ) ;
if ( V_53 == NULL )
return - V_163 ;
if ( F_36 ( V_38 , V_235 , V_142 [ V_151 ] ,
V_53 -> type -> V_237 ) )
return - V_40 ;
F_62 ( & V_53 -> V_103 ) ;
V_22 = V_53 -> V_104 -> V_218 ( V_53 , V_38 , V_106 , NULL , 0 , 0 ) ;
F_63 ( & V_53 -> V_103 ) ;
if ( V_22 == - V_107 )
V_22 = 1 ;
return V_22 > 0 ? 0 : - V_220 ;
}
static int
F_124 ( struct V_140 * V_141 , struct V_93 * V_94 ,
const struct V_122 * V_123 ,
const struct V_33 * const V_142 [] )
{
struct V_1 * V_91 = F_1 ( F_83 ( V_141 ) ) ;
const struct V_52 * V_53 ;
struct V_93 * V_222 ;
struct V_122 * V_239 ;
int V_22 = 0 ;
if ( F_35 ( F_72 ( V_142 ) ||
V_142 [ V_147 ] == NULL ) )
return - V_40 ;
V_53 = F_79 ( V_91 , F_40 ( V_142 [ V_147 ] ) ) ;
if ( V_53 == NULL )
return - V_163 ;
V_222 = F_117 ( V_240 , V_31 ) ;
if ( V_222 == NULL )
return - V_152 ;
V_239 = F_75 ( V_222 , F_107 ( V_94 ) . V_127 , V_123 -> V_198 , 0 ,
V_241 ) ;
if ( ! V_239 )
goto V_242;
if ( F_111 ( V_222 , V_121 , V_24 ) ||
F_112 ( V_222 , V_147 , V_53 -> V_6 ) ||
F_112 ( V_222 , V_148 , V_53 -> type -> V_6 ) ||
F_111 ( V_222 , V_150 , V_53 -> V_7 ) ||
F_111 ( V_222 , V_149 , V_53 -> V_8 ) )
goto V_202;
F_113 ( V_222 , V_239 ) ;
V_22 = F_119 ( V_141 , V_222 , F_107 ( V_94 ) . V_127 , V_233 ) ;
if ( V_22 < 0 )
return V_22 ;
return 0 ;
V_202:
F_125 ( V_222 , V_239 ) ;
V_242:
F_126 ( V_222 ) ;
return - V_200 ;
}
static int
V_5 ( struct V_140 * V_141 , struct V_93 * V_94 ,
const struct V_122 * V_123 ,
const struct V_33 * const V_142 [] )
{
struct V_93 * V_222 ;
struct V_122 * V_239 ;
T_1 V_7 , V_20 , V_21 ;
const char * V_146 ;
int V_22 = 0 ;
if ( F_35 ( F_72 ( V_142 ) ||
V_142 [ V_148 ] == NULL ||
V_142 [ V_150 ] == NULL ) )
return - V_40 ;
V_7 = F_73 ( V_142 [ V_150 ] ) ;
V_146 = F_40 ( V_142 [ V_148 ] ) ;
V_22 = F_127 ( V_146 , V_7 , & V_20 , & V_21 ) ;
if ( V_22 )
return V_22 ;
V_222 = F_117 ( V_240 , V_31 ) ;
if ( V_222 == NULL )
return - V_152 ;
V_239 = F_75 ( V_222 , F_107 ( V_94 ) . V_127 , V_123 -> V_198 , 0 ,
V_243 ) ;
if ( ! V_239 )
goto V_242;
if ( F_111 ( V_222 , V_121 , V_24 ) ||
F_112 ( V_222 , V_148 , V_146 ) ||
F_111 ( V_222 , V_150 , V_7 ) ||
F_111 ( V_222 , V_149 , V_21 ) ||
F_111 ( V_222 , V_244 , V_20 ) )
goto V_202;
F_113 ( V_222 , V_239 ) ;
F_12 ( L_26 , V_239 -> V_185 ) ;
V_22 = F_119 ( V_141 , V_222 , F_107 ( V_94 ) . V_127 , V_233 ) ;
if ( V_22 < 0 )
return V_22 ;
return 0 ;
V_202:
F_125 ( V_222 , V_239 ) ;
V_242:
F_126 ( V_222 ) ;
return - V_200 ;
}
static int
F_128 ( struct V_140 * V_141 , struct V_93 * V_94 ,
const struct V_122 * V_123 ,
const struct V_33 * const V_142 [] )
{
struct V_93 * V_222 ;
struct V_122 * V_239 ;
int V_22 = 0 ;
if ( F_35 ( V_142 [ V_121 ] == NULL ) )
return - V_40 ;
V_222 = F_117 ( V_240 , V_31 ) ;
if ( V_222 == NULL )
return - V_152 ;
V_239 = F_75 ( V_222 , F_107 ( V_94 ) . V_127 , V_123 -> V_198 , 0 ,
V_245 ) ;
if ( ! V_239 )
goto V_242;
if ( F_111 ( V_222 , V_121 , V_24 ) )
goto V_202;
F_113 ( V_222 , V_239 ) ;
V_22 = F_119 ( V_141 , V_222 , F_107 ( V_94 ) . V_127 , V_233 ) ;
if ( V_22 < 0 )
return V_22 ;
return 0 ;
V_202:
F_125 ( V_222 , V_239 ) ;
V_242:
F_126 ( V_222 ) ;
return - V_200 ;
}
static int
F_129 ( struct V_140 * V_193 , int V_246 , void T_7 * V_247 , int * V_54 )
{
unsigned int * V_248 ;
void * V_249 ;
int V_250 = * V_54 , V_22 = 0 ;
struct V_2 * V_2 = F_83 ( V_193 ) ;
struct V_1 * V_91 = F_1 ( V_2 ) ;
if ( ! F_130 ( V_2 -> V_251 , V_252 ) )
return - V_253 ;
if ( V_246 != V_254 )
return - V_255 ;
if ( * V_54 < sizeof( unsigned int ) )
return - V_25 ;
V_249 = F_131 ( * V_54 ) ;
if ( ! V_249 )
return - V_152 ;
if ( F_132 ( V_249 , V_247 , * V_54 ) != 0 ) {
V_22 = - V_18 ;
goto V_211;
}
V_248 = ( unsigned int * ) V_249 ;
if ( * V_248 < V_256 ) {
struct V_257 * V_258 = V_249 ;
if ( * V_54 < sizeof( struct V_257 ) ) {
V_22 = - V_25 ;
goto V_211;
}
if ( V_258 -> V_135 != V_24 ) {
V_22 = - V_259 ;
goto V_211;
}
}
switch ( * V_248 ) {
case V_256 : {
struct V_257 * V_258 = V_249 ;
if ( * V_54 != sizeof( struct V_257 ) ) {
V_22 = - V_25 ;
goto V_211;
}
V_258 -> V_135 = V_24 ;
V_22 = F_133 ( V_247 , V_258 ,
sizeof( struct V_257 ) ) ;
goto V_211;
}
case V_260 : {
struct V_261 * V_262 = V_249 ;
T_6 V_47 ;
if ( * V_54 != sizeof( struct V_261 ) ) {
V_22 = - V_25 ;
goto V_211;
}
V_262 -> V_53 . V_6 [ V_153 - 1 ] = '\0' ;
F_15 ( V_12 ) ;
F_78 ( V_91 , V_262 -> V_53 . V_6 , & V_47 ) ;
V_262 -> V_53 . V_90 = V_47 ;
F_11 ( V_12 ) ;
goto V_263;
}
case V_264 : {
struct V_265 * V_262 = V_249 ;
T_6 V_47 ;
if ( * V_54 != sizeof( struct V_265 ) ) {
V_22 = - V_25 ;
goto V_211;
}
V_262 -> V_53 . V_6 [ V_153 - 1 ] = '\0' ;
F_15 ( V_12 ) ;
F_78 ( V_91 , V_262 -> V_53 . V_6 , & V_47 ) ;
V_262 -> V_53 . V_90 = V_47 ;
if ( V_47 != V_117 )
V_262 -> V_7 = V_52 ( V_91 , V_47 ) -> V_7 ;
F_11 ( V_12 ) ;
goto V_263;
}
case V_266 : {
struct V_261 * V_262 = V_249 ;
struct V_52 * V_53 ;
if ( * V_54 != sizeof( struct V_261 ) ||
V_262 -> V_53 . V_90 >= V_91 -> V_119 ) {
V_22 = - V_25 ;
goto V_211;
}
F_15 ( V_12 ) ;
V_53 = V_52 ( V_91 , V_262 -> V_53 . V_90 ) ;
strncpy ( V_262 -> V_53 . V_6 , V_53 ? V_53 -> V_6 : L_27 ,
V_153 ) ;
F_11 ( V_12 ) ;
goto V_263;
}
default:
V_22 = - V_267 ;
goto V_211;
}
V_263:
V_22 = F_133 ( V_247 , V_249 , V_250 ) ;
V_211:
F_134 ( V_249 ) ;
if ( V_22 > 0 )
V_22 = 0 ;
return V_22 ;
}
static int T_8
F_135 ( struct V_2 * V_2 )
{
struct V_1 * V_91 = F_1 ( V_2 ) ;
struct V_52 * * V_26 ;
V_91 -> V_119 = V_268 ? V_268 : V_269 ;
if ( V_91 -> V_119 >= V_117 )
V_91 -> V_119 = V_117 - 1 ;
V_26 = F_28 ( sizeof( struct V_52 * ) * V_91 -> V_119 , V_31 ) ;
if ( ! V_26 )
return - V_152 ;
V_91 -> V_120 = 0 ;
F_88 ( V_91 -> V_92 , V_26 ) ;
return 0 ;
}
static void T_9
F_136 ( struct V_2 * V_2 )
{
struct V_1 * V_91 = F_1 ( V_2 ) ;
struct V_52 * V_53 = NULL ;
T_6 V_116 ;
V_91 -> V_120 = 1 ;
for ( V_116 = 0 ; V_116 < V_91 -> V_119 ; V_116 ++ ) {
V_53 = V_52 ( V_91 , V_116 ) ;
if ( V_53 != NULL )
F_92 ( V_91 , V_116 ) ;
}
F_90 ( F_137 ( V_91 -> V_92 , 1 ) ) ;
}
static int T_10
F_138 ( void )
{
int V_22 = F_139 ( & V_270 ) ;
if ( V_22 != 0 ) {
F_140 ( L_28 ) ;
return V_22 ;
}
V_22 = F_141 ( & V_271 ) ;
if ( V_22 != 0 ) {
F_140 ( L_29 , V_22 ) ;
F_142 ( & V_270 ) ;
return V_22 ;
}
V_22 = F_143 ( & V_272 ) ;
if ( V_22 ) {
F_140 ( L_30 ) ;
F_144 ( & V_271 ) ;
F_142 ( & V_270 ) ;
return V_22 ;
}
F_145 ( L_31 , V_24 ) ;
return 0 ;
}
static void T_11
F_146 ( void )
{
F_147 ( & V_272 ) ;
F_144 ( & V_271 ) ;
F_142 ( & V_270 ) ;
F_12 ( L_32 ) ;
}
