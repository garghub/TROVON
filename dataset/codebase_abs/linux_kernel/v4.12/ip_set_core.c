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
if ( STRNCMP ( type -> V_6 , V_6 ) &&
( type -> V_7 == V_7 ||
type -> V_7 == V_9 ) &&
V_8 >= type -> V_10 &&
V_8 <= type -> V_11 )
return type ;
return NULL ;
}
static bool
F_9 ( const char * V_6 )
{
F_10 ( V_12 ) ;
F_11 ( L_1 , V_6 ) ;
if ( F_12 ( L_2 , V_6 ) < 0 ) {
F_13 ( L_3 , V_6 ) ;
F_14 ( V_12 ) ;
return false ;
}
F_14 ( V_12 ) ;
return true ;
}
static int
F_15 ( const char * V_6 , T_1 V_7 , T_1 V_8 ,
struct V_5 * * V_13 , bool V_14 )
{
struct V_5 * type ;
int V_15 ;
if ( V_14 && ! F_9 ( V_6 ) )
return - V_16 ;
F_16 () ;
* V_13 = F_7 ( V_6 , V_7 , V_8 ) ;
if ( * V_13 ) {
V_15 = ! F_17 ( ( * V_13 ) -> V_17 ) ? - V_18 : 0 ;
goto V_19;
}
F_8 (type, &ip_set_type_list, list)
if ( STRNCMP ( type -> V_6 , V_6 ) ) {
V_15 = - V_16 ;
goto V_19;
}
F_18 () ;
return V_14 ? - V_16 :
F_15 ( V_6 , V_7 , V_8 , V_13 , true ) ;
V_19:
F_18 () ;
return V_15 ;
}
static int
F_19 ( const char * V_6 , T_1 V_7 , T_1 * V_20 , T_1 * V_21 ,
bool V_14 )
{
struct V_5 * type ;
bool V_13 = false ;
if ( V_14 && ! F_9 ( V_6 ) )
return - V_16 ;
* V_20 = 255 ; * V_21 = 0 ;
F_16 () ;
F_8 (type, &ip_set_type_list, list)
if ( STRNCMP ( type -> V_6 , V_6 ) &&
( type -> V_7 == V_7 ||
type -> V_7 == V_9 ) ) {
V_13 = true ;
if ( type -> V_10 < * V_20 )
* V_20 = type -> V_10 ;
if ( type -> V_11 > * V_21 )
* V_21 = type -> V_11 ;
}
F_18 () ;
if ( V_13 )
return 0 ;
return V_14 ? - V_16 :
F_19 ( V_6 , V_7 , V_20 , V_21 , true ) ;
}
int
F_20 ( struct V_5 * type )
{
int V_22 = 0 ;
if ( type -> V_23 != V_24 ) {
F_13 ( L_4 ,
type -> V_6 , F_21 ( type -> V_7 ) ,
type -> V_10 , type -> V_11 ,
type -> V_23 , V_24 ) ;
return - V_25 ;
}
F_3 () ;
if ( F_7 ( type -> V_6 , type -> V_7 , type -> V_10 ) ) {
F_13 ( L_5 ,
type -> V_6 , F_21 ( type -> V_7 ) ,
type -> V_10 ) ;
F_5 () ;
return - V_25 ;
}
F_22 ( & type -> V_26 , & V_27 ) ;
F_11 ( L_6 ,
type -> V_6 , F_21 ( type -> V_7 ) ,
type -> V_10 , type -> V_11 ) ;
F_5 () ;
return V_22 ;
}
void
F_23 ( struct V_5 * type )
{
F_3 () ;
if ( ! F_7 ( type -> V_6 , type -> V_7 , type -> V_10 ) ) {
F_13 ( L_7 ,
type -> V_6 , F_21 ( type -> V_7 ) ,
type -> V_10 ) ;
F_5 () ;
return;
}
F_24 ( & type -> V_26 ) ;
F_11 ( L_8 ,
type -> V_6 , F_21 ( type -> V_7 ) , type -> V_10 ) ;
F_5 () ;
F_25 () ;
}
void *
F_26 ( T_2 V_28 )
{
void * V_29 = NULL ;
if ( V_28 < V_30 )
V_29 = F_27 ( V_28 , V_31 | V_32 ) ;
if ( V_29 ) {
F_11 ( L_9 , V_29 ) ;
return V_29 ;
}
V_29 = F_28 ( V_28 ) ;
if ( ! V_29 )
return NULL ;
F_11 ( L_10 , V_29 ) ;
return V_29 ;
}
void
F_29 ( void * V_29 )
{
F_11 ( L_11 , V_29 ,
F_30 ( V_29 ) ? L_12 : L_13 ) ;
F_31 ( V_29 ) ;
}
static inline bool
F_32 ( const struct V_33 * V_34 )
{
return V_34 -> V_35 & V_36 ;
}
int
F_33 ( struct V_33 * V_34 , T_3 * V_37 )
{
struct V_33 * V_38 [ V_39 + 1 ] ;
if ( F_34 ( ! F_32 ( V_34 ) ) )
return - V_40 ;
if ( F_35 ( V_38 , V_39 , V_34 ,
V_41 , NULL ) )
return - V_40 ;
if ( F_34 ( ! F_36 ( V_38 , V_42 ) ) )
return - V_40 ;
* V_37 = F_37 ( V_38 [ V_42 ] ) ;
return 0 ;
}
int
F_38 ( struct V_33 * V_34 , union V_43 * V_37 )
{
struct V_33 * V_38 [ V_39 + 1 ] ;
if ( F_34 ( ! F_32 ( V_34 ) ) )
return - V_40 ;
if ( F_35 ( V_38 , V_39 , V_34 ,
V_41 , NULL ) )
return - V_40 ;
if ( F_34 ( ! F_36 ( V_38 , V_44 ) ) )
return - V_40 ;
memcpy ( V_37 , F_39 ( V_38 [ V_44 ] ) ,
sizeof( struct V_45 ) ) ;
return 0 ;
}
static inline bool
F_40 ( enum V_46 V_47 , T_4 V_48 , struct V_33 * V_38 [] )
{
return V_49 [ V_47 ] . V_50 ?
( V_48 & V_49 [ V_47 ] . V_50 ) :
! ! V_38 [ V_51 ] ;
}
T_2
F_41 ( struct V_52 * V_53 , struct V_33 * V_38 [] , T_2 V_54 ,
T_2 V_55 )
{
enum V_46 V_47 ;
T_4 V_56 = 0 ;
if ( V_38 [ V_57 ] )
V_56 = F_42 ( V_38 [ V_57 ] ) ;
if ( V_56 & V_58 )
V_53 -> V_48 |= V_59 ;
if ( ! V_55 )
V_55 = 1 ;
for ( V_47 = 0 ; V_47 < V_60 ; V_47 ++ ) {
if ( ! F_40 ( V_47 , V_56 , V_38 ) )
continue;
V_54 = F_43 ( V_54 , V_49 [ V_47 ] . V_55 ) ;
V_53 -> V_61 [ V_47 ] = V_54 ;
V_53 -> V_62 |= V_49 [ V_47 ] . type ;
V_54 += V_49 [ V_47 ] . V_54 ;
}
return F_43 ( V_54 , V_55 ) ;
}
int
F_44 ( struct V_52 * V_53 , struct V_33 * V_38 [] ,
struct V_63 * V_64 )
{
T_5 V_65 ;
if ( F_34 ( ! F_45 ( V_38 , V_51 ) ||
! F_45 ( V_38 , V_66 ) ||
! F_45 ( V_38 , V_67 ) ||
! F_45 ( V_38 , V_68 ) ||
! F_45 ( V_38 , V_69 ) ||
! F_45 ( V_38 , V_70 ) ) )
return - V_40 ;
if ( V_38 [ V_51 ] ) {
if ( ! F_46 ( V_53 ) )
return - V_71 ;
V_64 -> V_72 = F_47 ( V_38 [ V_51 ] ) ;
}
if ( V_38 [ V_67 ] || V_38 [ V_66 ] ) {
if ( ! F_48 ( V_53 ) )
return - V_73 ;
if ( V_38 [ V_67 ] )
V_64 -> V_74 = F_49 ( F_50 (
V_38 [ V_67 ] ) ) ;
if ( V_38 [ V_66 ] )
V_64 -> V_75 = F_49 ( F_50 (
V_38 [ V_66 ] ) ) ;
}
if ( V_38 [ V_76 ] ) {
if ( ! F_51 ( V_53 ) )
return - V_77 ;
V_64 -> V_78 = F_52 ( V_38 [ V_76 ] ) ;
}
if ( V_38 [ V_68 ] ) {
if ( ! F_53 ( V_53 ) )
return - V_79 ;
V_65 = F_49 ( F_50 ( V_38 [ V_68 ] ) ) ;
V_64 -> V_80 . V_81 = V_65 >> 32 ;
V_64 -> V_80 . V_82 = V_65 & 0xffffffff ;
}
if ( V_38 [ V_69 ] ) {
if ( ! F_53 ( V_53 ) )
return - V_79 ;
V_64 -> V_80 . V_83 =
F_54 ( F_37 ( V_38 [ V_69 ] ) ) ;
}
if ( V_38 [ V_70 ] ) {
if ( ! F_53 ( V_53 ) )
return - V_79 ;
V_64 -> V_80 . V_84 =
F_55 ( F_56 ( V_38 [ V_70 ] ) ) ;
}
return 0 ;
}
int
F_57 ( struct V_85 * V_86 , const struct V_52 * V_53 ,
const void * V_87 , bool V_88 )
{
if ( F_46 ( V_53 ) ) {
unsigned long * V_72 = F_58 ( V_87 , V_53 ) ;
if ( F_59 ( V_86 , V_51 ,
F_60 ( V_88 ? F_61 ( V_72 )
: * V_72 ) ) )
return - V_89 ;
}
if ( F_48 ( V_53 ) &&
F_62 ( V_86 , F_63 ( V_87 , V_53 ) ) )
return - V_89 ;
if ( F_51 ( V_53 ) &&
F_64 ( V_86 , F_65 ( V_87 , V_53 ) ) )
return - V_89 ;
if ( F_53 ( V_53 ) &&
F_66 ( V_86 , F_67 ( V_87 , V_53 ) ) )
return - V_89 ;
return 0 ;
}
static inline void
F_68 ( struct V_52 * V_53 )
{
F_69 ( & V_90 ) ;
V_53 -> V_91 ++ ;
F_70 ( & V_90 ) ;
}
static inline void
F_71 ( struct V_52 * V_53 )
{
F_69 ( & V_90 ) ;
F_72 ( V_53 -> V_91 == 0 ) ;
V_53 -> V_91 -- ;
F_70 ( & V_90 ) ;
}
static inline void
F_73 ( struct V_52 * V_53 )
{
F_69 ( & V_90 ) ;
F_72 ( V_53 -> V_92 == 0 ) ;
V_53 -> V_92 -- ;
F_70 ( & V_90 ) ;
}
static inline struct V_52 *
F_74 ( struct V_2 * V_2 , T_6 V_93 )
{
struct V_52 * V_53 ;
struct V_1 * V_94 = F_1 ( V_2 ) ;
F_16 () ;
V_53 = F_75 ( V_94 -> V_95 ) [ V_93 ] ;
F_18 () ;
return V_53 ;
}
int
F_76 ( T_6 V_93 , const struct V_85 * V_86 ,
const struct V_96 * V_97 , struct V_98 * V_99 )
{
struct V_52 * V_53 = F_74 ( F_77 ( V_97 ) , V_93 ) ;
int V_22 = 0 ;
F_72 ( ! V_53 ) ;
F_11 ( L_14 , V_53 -> V_6 , V_93 ) ;
if ( V_99 -> V_100 < V_53 -> type -> V_101 ||
! ( V_99 -> V_7 == V_53 -> V_7 || V_53 -> V_7 == V_9 ) )
return 0 ;
F_78 () ;
V_22 = V_53 -> V_102 -> V_103 ( V_53 , V_86 , V_97 , V_104 , V_99 ) ;
F_79 () ;
if ( V_22 == - V_105 ) {
F_11 ( L_15 ) ;
F_80 ( & V_53 -> V_106 ) ;
V_53 -> V_102 -> V_103 ( V_53 , V_86 , V_97 , V_107 , V_99 ) ;
F_81 ( & V_53 -> V_106 ) ;
V_22 = 1 ;
} else {
if ( ( V_99 -> V_108 & V_109 ) &&
( V_53 -> type -> V_110 & V_111 ) &&
( V_22 > 0 || V_22 == - V_112 ) )
V_22 = - V_22 ;
}
return ( V_22 < 0 ? 0 : V_22 ) ;
}
int
F_82 ( T_6 V_93 , const struct V_85 * V_86 ,
const struct V_96 * V_97 , struct V_98 * V_99 )
{
struct V_52 * V_53 = F_74 ( F_77 ( V_97 ) , V_93 ) ;
int V_22 ;
F_72 ( ! V_53 ) ;
F_11 ( L_14 , V_53 -> V_6 , V_93 ) ;
if ( V_99 -> V_100 < V_53 -> type -> V_101 ||
! ( V_99 -> V_7 == V_53 -> V_7 || V_53 -> V_7 == V_9 ) )
return - V_113 ;
F_80 ( & V_53 -> V_106 ) ;
V_22 = V_53 -> V_102 -> V_103 ( V_53 , V_86 , V_97 , V_107 , V_99 ) ;
F_81 ( & V_53 -> V_106 ) ;
return V_22 ;
}
int
F_83 ( T_6 V_93 , const struct V_85 * V_86 ,
const struct V_96 * V_97 , struct V_98 * V_99 )
{
struct V_52 * V_53 = F_74 ( F_77 ( V_97 ) , V_93 ) ;
int V_22 = 0 ;
F_72 ( ! V_53 ) ;
F_11 ( L_14 , V_53 -> V_6 , V_93 ) ;
if ( V_99 -> V_100 < V_53 -> type -> V_101 ||
! ( V_99 -> V_7 == V_53 -> V_7 || V_53 -> V_7 == V_9 ) )
return - V_113 ;
F_80 ( & V_53 -> V_106 ) ;
V_22 = V_53 -> V_102 -> V_103 ( V_53 , V_86 , V_97 , V_114 , V_99 ) ;
F_81 ( & V_53 -> V_106 ) ;
return V_22 ;
}
T_6
F_84 ( struct V_2 * V_2 , const char * V_6 , struct V_52 * * V_53 )
{
T_6 V_115 , V_93 = V_116 ;
struct V_52 * V_117 ;
struct V_1 * V_94 = F_1 ( V_2 ) ;
F_16 () ;
for ( V_115 = 0 ; V_115 < V_94 -> V_118 ; V_115 ++ ) {
V_117 = F_75 ( V_94 -> V_95 ) [ V_115 ] ;
if ( V_117 && STRNCMP ( V_117 -> V_6 , V_6 ) ) {
F_68 ( V_117 ) ;
V_93 = V_115 ;
* V_53 = V_117 ;
break;
}
}
F_18 () ;
return V_93 ;
}
static inline void
F_85 ( struct V_1 * V_94 , T_6 V_93 )
{
struct V_52 * V_53 ;
F_16 () ;
V_53 = F_75 ( V_94 -> V_95 ) [ V_93 ] ;
if ( V_53 )
F_71 ( V_53 ) ;
F_18 () ;
}
void
F_86 ( struct V_2 * V_2 , T_6 V_93 )
{
struct V_1 * V_94 = F_1 ( V_2 ) ;
F_85 ( V_94 , V_93 ) ;
}
const char *
F_87 ( struct V_2 * V_2 , T_6 V_93 )
{
const struct V_52 * V_53 = F_74 ( V_2 , V_93 ) ;
F_72 ( ! V_53 ) ;
F_72 ( V_53 -> V_91 == 0 ) ;
return V_53 -> V_6 ;
}
T_6
F_88 ( struct V_2 * V_2 , T_6 V_93 )
{
struct V_52 * V_53 ;
struct V_1 * V_94 = F_1 ( V_2 ) ;
if ( V_93 >= V_94 -> V_118 )
return V_116 ;
F_14 ( V_12 ) ;
V_53 = V_52 ( V_94 , V_93 ) ;
if ( V_53 )
F_68 ( V_53 ) ;
else
V_93 = V_116 ;
F_10 ( V_12 ) ;
return V_93 ;
}
void
F_89 ( struct V_2 * V_2 , T_6 V_93 )
{
struct V_52 * V_53 ;
struct V_1 * V_94 = F_1 ( V_2 ) ;
F_14 ( V_12 ) ;
if ( ! V_94 -> V_119 ) {
V_53 = V_52 ( V_94 , V_93 ) ;
if ( V_53 )
F_71 ( V_53 ) ;
}
F_10 ( V_12 ) ;
}
static inline bool
F_90 ( const struct V_33 * const V_38 [] )
{
return ! V_38 [ V_120 ] ||
F_91 ( V_38 [ V_120 ] ) != V_24 ;
}
static inline T_4
F_92 ( const struct V_121 * V_122 )
{
return V_122 -> V_123 & V_124 ? 0 : V_125 ;
}
static struct V_121 *
F_93 ( struct V_85 * V_86 , T_4 V_126 , T_4 V_127 , unsigned int V_48 ,
enum V_128 V_129 )
{
struct V_121 * V_122 ;
struct V_130 * V_131 ;
V_122 = F_94 ( V_86 , V_126 , V_127 , F_95 ( V_12 , V_129 ) ,
sizeof( * V_131 ) , V_48 ) ;
if ( ! V_122 )
return NULL ;
V_131 = F_96 ( V_122 ) ;
V_131 -> V_132 = V_133 ;
V_131 -> V_134 = V_135 ;
V_131 -> V_136 = 0 ;
return V_122 ;
}
static struct V_52 *
F_97 ( struct V_1 * V_94 , const char * V_6 , T_6 * V_47 )
{
struct V_52 * V_53 = NULL ;
T_6 V_115 ;
* V_47 = V_116 ;
for ( V_115 = 0 ; V_115 < V_94 -> V_118 ; V_115 ++ ) {
V_53 = V_52 ( V_94 , V_115 ) ;
if ( V_53 && STRNCMP ( V_53 -> V_6 , V_6 ) ) {
* V_47 = V_115 ;
break;
}
}
return ( * V_47 == V_116 ? NULL : V_53 ) ;
}
static inline struct V_52 *
F_98 ( struct V_1 * V_94 , const char * V_6 )
{
T_6 V_47 ;
return F_97 ( V_94 , V_6 , & V_47 ) ;
}
static int
F_99 ( struct V_1 * V_94 , const char * V_6 , T_6 * V_93 ,
struct V_52 * * V_53 )
{
struct V_52 * V_117 ;
T_6 V_115 ;
* V_93 = V_116 ;
for ( V_115 = 0 ; V_115 < V_94 -> V_118 ; V_115 ++ ) {
V_117 = V_52 ( V_94 , V_115 ) ;
if ( ! V_117 ) {
if ( * V_93 == V_116 )
* V_93 = V_115 ;
} else if ( STRNCMP ( V_6 , V_117 -> V_6 ) ) {
* V_53 = V_117 ;
return - V_137 ;
}
}
if ( * V_93 == V_116 )
return - V_138 ;
return 0 ;
}
static int F_100 ( struct V_2 * V_2 , struct V_139 * V_140 , struct V_85 * V_86 ,
const struct V_121 * V_122 ,
const struct V_33 * const V_141 [] )
{
return - V_142 ;
}
static int F_101 ( struct V_2 * V_2 , struct V_139 * V_140 ,
struct V_85 * V_86 , const struct V_121 * V_122 ,
const struct V_33 * const V_141 [] )
{
struct V_1 * V_94 = F_1 ( V_2 ) ;
struct V_52 * V_53 , * V_143 = NULL ;
T_6 V_93 = V_116 ;
struct V_33 * V_38 [ V_144 + 1 ] = {} ;
const char * V_6 , * V_145 ;
T_1 V_7 , V_8 ;
T_4 V_48 = F_92 ( V_122 ) ;
int V_22 = 0 ;
if ( F_34 ( F_90 ( V_141 ) ||
! V_141 [ V_146 ] ||
! V_141 [ V_147 ] ||
! V_141 [ V_148 ] ||
! V_141 [ V_149 ] ||
( V_141 [ V_150 ] &&
! F_32 ( V_141 [ V_150 ] ) ) ) )
return - V_40 ;
V_6 = F_39 ( V_141 [ V_146 ] ) ;
V_145 = F_39 ( V_141 [ V_147 ] ) ;
V_7 = F_91 ( V_141 [ V_149 ] ) ;
V_8 = F_91 ( V_141 [ V_148 ] ) ;
F_11 ( L_16 ,
V_6 , V_145 , F_21 ( V_7 ) , V_8 ) ;
V_53 = F_27 ( sizeof( * V_53 ) , V_31 ) ;
if ( ! V_53 )
return - V_151 ;
F_102 ( & V_53 -> V_106 ) ;
F_103 ( V_53 -> V_6 , V_6 , V_152 ) ;
V_53 -> V_7 = V_7 ;
V_53 -> V_8 = V_8 ;
V_22 = F_104 ( V_145 , V_7 , V_8 , & V_53 -> type ) ;
if ( V_22 )
goto V_153;
if ( V_141 [ V_150 ] &&
F_35 ( V_38 , V_144 , V_141 [ V_150 ] ,
V_53 -> type -> V_154 , NULL ) ) {
V_22 = - V_40 ;
goto V_155;
}
V_22 = V_53 -> type -> V_156 ( V_2 , V_53 , V_38 , V_48 ) ;
if ( V_22 != 0 )
goto V_155;
V_22 = F_99 ( V_94 , V_53 -> V_6 , & V_93 , & V_143 ) ;
if ( V_22 == - V_137 ) {
if ( ( V_48 & V_125 ) &&
STRNCMP ( V_53 -> type -> V_6 , V_143 -> type -> V_6 ) &&
V_53 -> type -> V_7 == V_143 -> type -> V_7 &&
V_53 -> type -> V_10 == V_143 -> type -> V_10 &&
V_53 -> type -> V_11 == V_143 -> type -> V_11 &&
V_53 -> V_102 -> V_157 ( V_53 , V_143 ) )
V_22 = 0 ;
goto V_158;
} else if ( V_22 == - V_138 ) {
struct V_52 * * V_26 , * * V_159 ;
T_6 V_115 = V_94 -> V_118 + V_160 ;
if ( V_115 < V_94 -> V_118 || V_115 == V_116 )
goto V_158;
V_26 = F_105 ( V_115 , sizeof( struct V_52 * ) , V_31 ) ;
if ( ! V_26 )
goto V_158;
V_159 = F_106 ( V_94 -> V_95 ) ;
memcpy ( V_26 , V_159 , sizeof( struct V_52 * ) * V_94 -> V_118 ) ;
F_107 ( V_94 -> V_95 , V_26 ) ;
F_108 () ;
V_93 = V_94 -> V_118 ;
V_94 -> V_118 = V_115 ;
F_109 ( V_159 ) ;
V_22 = 0 ;
} else if ( V_22 ) {
goto V_158;
}
F_11 ( L_17 , V_53 -> V_6 , V_93 ) ;
V_52 ( V_94 , V_93 ) = V_53 ;
return V_22 ;
V_158:
V_53 -> V_102 -> V_161 ( V_53 ) ;
V_155:
F_110 ( V_53 -> type -> V_17 ) ;
V_153:
F_109 ( V_53 ) ;
return V_22 ;
}
static void
F_111 ( struct V_52 * V_53 )
{
F_11 ( L_18 , V_53 -> V_6 ) ;
V_53 -> V_102 -> V_161 ( V_53 ) ;
F_110 ( V_53 -> type -> V_17 ) ;
F_109 ( V_53 ) ;
}
static int F_112 ( struct V_2 * V_2 , struct V_139 * V_140 ,
struct V_85 * V_86 , const struct V_121 * V_122 ,
const struct V_33 * const V_141 [] )
{
struct V_1 * V_94 = F_1 ( V_2 ) ;
struct V_52 * V_117 ;
T_6 V_115 ;
int V_22 = 0 ;
if ( F_34 ( F_90 ( V_141 ) ) )
return - V_40 ;
F_113 () ;
F_114 ( & V_90 ) ;
if ( ! V_141 [ V_146 ] ) {
for ( V_115 = 0 ; V_115 < V_94 -> V_118 ; V_115 ++ ) {
V_117 = V_52 ( V_94 , V_115 ) ;
if ( V_117 && ( V_117 -> V_91 || V_117 -> V_92 ) ) {
V_22 = - V_162 ;
goto V_153;
}
}
V_94 -> V_163 = true ;
F_115 ( & V_90 ) ;
for ( V_115 = 0 ; V_115 < V_94 -> V_118 ; V_115 ++ ) {
V_117 = V_52 ( V_94 , V_115 ) ;
if ( V_117 ) {
V_52 ( V_94 , V_115 ) = NULL ;
F_111 ( V_117 ) ;
}
}
V_94 -> V_163 = false ;
} else {
V_117 = F_97 ( V_94 , F_39 ( V_141 [ V_146 ] ) ,
& V_115 ) ;
if ( ! V_117 ) {
V_22 = - V_164 ;
goto V_153;
} else if ( V_117 -> V_91 || V_117 -> V_92 ) {
V_22 = - V_162 ;
goto V_153;
}
V_52 ( V_94 , V_115 ) = NULL ;
F_115 ( & V_90 ) ;
F_111 ( V_117 ) ;
}
return 0 ;
V_153:
F_115 ( & V_90 ) ;
return V_22 ;
}
static void
F_116 ( struct V_52 * V_53 )
{
F_11 ( L_18 , V_53 -> V_6 ) ;
F_80 ( & V_53 -> V_106 ) ;
V_53 -> V_102 -> V_165 ( V_53 ) ;
F_81 ( & V_53 -> V_106 ) ;
}
static int F_117 ( struct V_2 * V_2 , struct V_139 * V_140 , struct V_85 * V_86 ,
const struct V_121 * V_122 ,
const struct V_33 * const V_141 [] )
{
struct V_1 * V_94 = F_1 ( V_2 ) ;
struct V_52 * V_117 ;
T_6 V_115 ;
if ( F_34 ( F_90 ( V_141 ) ) )
return - V_40 ;
if ( ! V_141 [ V_146 ] ) {
for ( V_115 = 0 ; V_115 < V_94 -> V_118 ; V_115 ++ ) {
V_117 = V_52 ( V_94 , V_115 ) ;
if ( V_117 )
F_116 ( V_117 ) ;
}
} else {
V_117 = F_98 ( V_94 , F_39 ( V_141 [ V_146 ] ) ) ;
if ( ! V_117 )
return - V_164 ;
F_116 ( V_117 ) ;
}
return 0 ;
}
static int F_118 ( struct V_2 * V_2 , struct V_139 * V_140 ,
struct V_85 * V_86 , const struct V_121 * V_122 ,
const struct V_33 * const V_141 [] )
{
struct V_1 * V_94 = F_1 ( V_2 ) ;
struct V_52 * V_53 , * V_117 ;
const char * V_166 ;
T_6 V_115 ;
int V_22 = 0 ;
if ( F_34 ( F_90 ( V_141 ) ||
! V_141 [ V_146 ] ||
! V_141 [ V_167 ] ) )
return - V_40 ;
V_53 = F_98 ( V_94 , F_39 ( V_141 [ V_146 ] ) ) ;
if ( ! V_53 )
return - V_164 ;
F_114 ( & V_90 ) ;
if ( V_53 -> V_91 != 0 ) {
V_22 = - V_168 ;
goto V_153;
}
V_166 = F_39 ( V_141 [ V_167 ] ) ;
for ( V_115 = 0 ; V_115 < V_94 -> V_118 ; V_115 ++ ) {
V_117 = V_52 ( V_94 , V_115 ) ;
if ( V_117 && STRNCMP ( V_117 -> V_6 , V_166 ) ) {
V_22 = - V_169 ;
goto V_153;
}
}
strncpy ( V_53 -> V_6 , V_166 , V_152 ) ;
V_153:
F_115 ( & V_90 ) ;
return V_22 ;
}
static int F_119 ( struct V_2 * V_2 , struct V_139 * V_140 , struct V_85 * V_86 ,
const struct V_121 * V_122 ,
const struct V_33 * const V_141 [] )
{
struct V_1 * V_94 = F_1 ( V_2 ) ;
struct V_52 * V_170 , * V_171 ;
T_6 V_172 , V_173 ;
char V_174 [ V_152 ] ;
if ( F_34 ( F_90 ( V_141 ) ||
! V_141 [ V_146 ] ||
! V_141 [ V_167 ] ) )
return - V_40 ;
V_170 = F_97 ( V_94 , F_39 ( V_141 [ V_146 ] ) ,
& V_172 ) ;
if ( ! V_170 )
return - V_164 ;
V_171 = F_97 ( V_94 , F_39 ( V_141 [ V_167 ] ) ,
& V_173 ) ;
if ( ! V_171 )
return - V_169 ;
if ( ! ( V_170 -> type -> V_110 == V_171 -> type -> V_110 &&
V_170 -> V_7 == V_171 -> V_7 ) )
return - V_113 ;
if ( V_170 -> V_92 || V_171 -> V_92 )
return - V_175 ;
strncpy ( V_174 , V_170 -> V_6 , V_152 ) ;
strncpy ( V_170 -> V_6 , V_171 -> V_6 , V_152 ) ;
strncpy ( V_171 -> V_6 , V_174 , V_152 ) ;
F_69 ( & V_90 ) ;
F_120 ( V_170 -> V_91 , V_171 -> V_91 ) ;
V_52 ( V_94 , V_172 ) = V_171 ;
V_52 ( V_94 , V_173 ) = V_170 ;
F_70 ( & V_90 ) ;
return 0 ;
}
static int
F_121 ( struct V_176 * V_177 )
{
if ( V_177 -> args [ V_178 ] ) {
struct V_1 * V_94 =
(struct V_1 * ) V_177 -> args [ V_179 ] ;
T_6 V_93 = ( T_6 ) V_177 -> args [ V_180 ] ;
struct V_52 * V_53 = V_52 ( V_94 , V_93 ) ;
if ( V_53 -> V_102 -> V_181 )
V_53 -> V_102 -> V_181 ( V_53 , V_177 , false ) ;
F_11 ( L_19 , V_53 -> V_6 ) ;
F_73 ( V_53 ) ;
}
return 0 ;
}
static inline void
F_122 ( struct V_121 * V_122 )
{
const struct V_33 * V_141 ;
int V_182 ;
F_11 ( L_20 ) ;
F_123 (attr, nlh, sizeof(struct nfgenmsg), rem) {
F_11 ( L_21 , V_35 ( V_141 ) , V_141 -> V_183 ) ;
}
}
static int
F_124 ( struct V_176 * V_177 , struct V_1 * V_94 )
{
struct V_121 * V_122 = F_125 ( V_177 -> V_86 ) ;
int V_184 = F_126 ( sizeof( struct V_130 ) ) ;
struct V_33 * V_185 [ V_186 + 1 ] ;
struct V_33 * V_141 = ( void * ) V_122 + V_184 ;
T_4 V_187 ;
T_6 V_93 ;
F_127 ( V_185 , V_186 , V_141 , V_122 -> V_188 - V_184 ,
V_189 , NULL ) ;
if ( V_185 [ V_146 ] ) {
struct V_52 * V_53 ;
V_53 = F_97 ( V_94 , F_39 ( V_185 [ V_146 ] ) ,
& V_93 ) ;
if ( ! V_53 )
return - V_164 ;
V_187 = V_190 ;
V_177 -> args [ V_180 ] = V_93 ;
} else {
V_187 = V_191 ;
}
if ( V_185 [ V_192 ] ) {
T_4 V_193 = F_42 ( V_185 [ V_192 ] ) ;
V_187 |= ( V_193 << 16 ) ;
}
V_177 -> args [ V_179 ] = ( unsigned long ) V_94 ;
V_177 -> args [ V_194 ] = V_187 ;
return 0 ;
}
static int
F_128 ( struct V_85 * V_86 , struct V_176 * V_177 )
{
T_6 V_93 = V_116 , V_21 ;
struct V_52 * V_53 = NULL ;
struct V_121 * V_122 = NULL ;
unsigned int V_48 = F_129 ( V_177 -> V_86 ) . V_126 ? V_195 : 0 ;
struct V_1 * V_94 = F_1 ( F_130 ( V_86 -> V_196 ) ) ;
T_4 V_187 , V_197 ;
bool V_163 ;
int V_22 = 0 ;
if ( ! V_177 -> args [ V_194 ] ) {
V_22 = F_124 ( V_177 , V_94 ) ;
if ( V_22 < 0 ) {
V_122 = F_125 ( V_177 -> V_86 ) ;
if ( V_122 -> V_123 & V_198 )
F_131 ( V_177 -> V_86 , V_122 , V_22 , NULL ) ;
return V_22 ;
}
}
if ( V_177 -> args [ V_180 ] >= V_94 -> V_118 )
goto V_153;
V_187 = F_132 ( V_177 -> args [ V_194 ] ) ;
V_197 = F_133 ( V_177 -> args [ V_194 ] ) ;
V_21 = V_187 == V_190 ? V_177 -> args [ V_180 ] + 1
: V_94 -> V_118 ;
V_199:
F_11 ( L_22 ,
V_187 , V_197 , V_177 -> args [ V_180 ] ) ;
for (; V_177 -> args [ V_180 ] < V_21 ; V_177 -> args [ V_180 ] ++ ) {
V_93 = ( T_6 ) V_177 -> args [ V_180 ] ;
F_69 ( & V_90 ) ;
V_53 = V_52 ( V_94 , V_93 ) ;
V_163 = V_94 -> V_163 ;
if ( ! V_53 || V_163 ) {
F_70 ( & V_90 ) ;
if ( V_187 == V_190 ) {
V_22 = - V_164 ;
goto V_153;
}
if ( V_163 ) {
V_22 = 0 ;
goto V_153;
}
continue;
}
if ( V_187 != V_190 &&
( ( V_187 == V_191 ) ==
! ! ( V_53 -> type -> V_110 & V_200 ) ) ) {
F_70 ( & V_90 ) ;
continue;
}
F_11 ( L_23 , V_53 -> V_6 ) ;
if ( ! V_177 -> args [ V_178 ] ) {
F_11 ( L_24 ) ;
V_53 -> V_92 ++ ;
}
F_70 ( & V_90 ) ;
V_122 = F_93 ( V_86 , F_129 ( V_177 -> V_86 ) . V_126 ,
V_177 -> V_122 -> V_201 , V_48 ,
V_202 ) ;
if ( ! V_122 ) {
V_22 = - V_89 ;
goto V_203;
}
if ( F_134 ( V_86 , V_120 , V_24 ) ||
F_135 ( V_86 , V_146 , V_53 -> V_6 ) )
goto V_204;
if ( V_197 & V_205 )
goto V_206;
switch ( V_177 -> args [ V_178 ] ) {
case 0 :
if ( F_135 ( V_86 , V_147 ,
V_53 -> type -> V_6 ) ||
F_134 ( V_86 , V_149 ,
V_53 -> V_7 ) ||
F_134 ( V_86 , V_148 ,
V_53 -> V_8 ) )
goto V_204;
V_22 = V_53 -> V_102 -> V_207 ( V_53 , V_86 ) ;
if ( V_22 < 0 )
goto V_203;
if ( V_197 & V_208 )
goto V_206;
if ( V_53 -> V_102 -> V_181 )
V_53 -> V_102 -> V_181 ( V_53 , V_177 , true ) ;
default:
F_78 () ;
V_22 = V_53 -> V_102 -> V_26 ( V_53 , V_86 , V_177 ) ;
F_79 () ;
if ( ! V_177 -> args [ V_178 ] )
goto V_206;
goto V_203;
}
}
if ( V_187 == V_191 ) {
V_187 = V_209 ;
V_177 -> args [ V_194 ] = V_187 | ( V_197 << 16 ) ;
V_177 -> args [ V_180 ] = 0 ;
if ( V_53 && V_53 -> V_102 -> V_181 )
V_53 -> V_102 -> V_181 ( V_53 , V_177 , false ) ;
goto V_199;
}
goto V_153;
V_204:
V_22 = - V_18 ;
V_206:
if ( V_187 == V_190 )
V_177 -> args [ V_180 ] = V_116 ;
else
V_177 -> args [ V_180 ] ++ ;
V_203:
if ( V_22 || ! V_177 -> args [ V_178 ] ) {
V_53 = V_52 ( V_94 , V_93 ) ;
if ( V_53 -> V_102 -> V_181 )
V_53 -> V_102 -> V_181 ( V_53 , V_177 , false ) ;
F_11 ( L_19 , V_53 -> V_6 ) ;
F_73 ( V_53 ) ;
V_177 -> args [ V_178 ] = 0 ;
}
V_153:
if ( V_122 ) {
F_136 ( V_86 , V_122 ) ;
F_11 ( L_25 , V_122 -> V_188 ) ;
F_122 ( V_122 ) ;
}
return V_22 < 0 ? V_22 : V_86 -> V_54 ;
}
static int F_137 ( struct V_2 * V_2 , struct V_139 * V_140 , struct V_85 * V_86 ,
const struct V_121 * V_122 ,
const struct V_33 * const V_141 [] )
{
if ( F_34 ( F_90 ( V_141 ) ) )
return - V_40 ;
{
struct V_210 V_211 = {
. V_212 = F_128 ,
. V_213 = F_121 ,
} ;
return F_138 ( V_140 , V_86 , V_122 , & V_211 ) ;
}
}
static int
F_139 ( struct V_139 * V_140 , struct V_85 * V_86 , struct V_52 * V_53 ,
struct V_33 * V_38 [] , enum V_214 V_215 ,
T_4 V_48 , bool V_216 )
{
int V_22 ;
T_4 V_217 = 0 ;
bool V_218 = V_48 & V_125 , V_219 = false ;
do {
F_80 ( & V_53 -> V_106 ) ;
V_22 = V_53 -> V_102 -> V_220 ( V_53 , V_38 , V_215 , & V_217 , V_48 , V_219 ) ;
F_81 ( & V_53 -> V_106 ) ;
V_219 = true ;
} while ( V_22 == - V_105 &&
V_53 -> V_102 -> V_221 &&
( V_22 = V_53 -> V_102 -> V_221 ( V_53 , V_219 ) ) == 0 );
if ( ! V_22 || ( V_22 == - V_222 && V_218 ) )
return 0 ;
if ( V_217 && V_216 ) {
struct V_121 * V_223 , * V_122 = F_125 ( V_86 ) ;
struct V_85 * V_224 ;
struct V_225 * V_226 ;
T_2 V_227 = V_20 ( V_228 ,
sizeof( * V_226 ) + V_188 ( V_122 ) ) ;
int V_184 = F_126 ( sizeof( struct V_130 ) ) ;
struct V_33 * V_185 [ V_186 + 1 ] ;
struct V_33 * V_229 ;
T_4 * V_230 ;
V_224 = F_140 ( V_227 , V_31 ) ;
if ( ! V_224 )
return - V_151 ;
V_223 = F_141 ( V_224 , F_129 ( V_86 ) . V_126 ,
V_122 -> V_201 , V_231 , V_227 , 0 ) ;
V_226 = F_96 ( V_223 ) ;
V_226 -> error = V_22 ;
memcpy ( & V_226 -> V_232 , V_122 , V_122 -> V_188 ) ;
V_229 = ( void * ) & V_226 -> V_232 + V_184 ;
F_127 ( V_185 , V_186 , V_229 ,
V_122 -> V_188 - V_184 , V_233 , NULL ) ;
V_230 = F_39 ( V_185 [ V_234 ] ) ;
* V_230 = V_217 ;
F_142 ( V_140 , V_224 , F_129 ( V_86 ) . V_126 ,
V_235 ) ;
return - V_236 ;
}
return V_22 ;
}
static int F_143 ( struct V_2 * V_2 , struct V_139 * V_140 , struct V_85 * V_86 ,
const struct V_121 * V_122 ,
const struct V_33 * const V_141 [] )
{
struct V_1 * V_94 = F_1 ( V_2 ) ;
struct V_52 * V_53 ;
struct V_33 * V_38 [ V_237 + 1 ] = {} ;
const struct V_33 * V_34 ;
T_4 V_48 = F_92 ( V_122 ) ;
bool V_216 ;
int V_22 = 0 ;
if ( F_34 ( F_90 ( V_141 ) ||
! V_141 [ V_146 ] ||
! ( ( V_141 [ V_150 ] != NULL ) ^
( V_141 [ V_238 ] != NULL ) ) ||
( V_141 [ V_150 ] &&
! F_32 ( V_141 [ V_150 ] ) ) ||
( V_141 [ V_238 ] &&
( ! F_32 ( V_141 [ V_238 ] ) ||
! V_141 [ V_234 ] ) ) ) )
return - V_40 ;
V_53 = F_98 ( V_94 , F_39 ( V_141 [ V_146 ] ) ) ;
if ( ! V_53 )
return - V_164 ;
V_216 = ! ! V_141 [ V_234 ] ;
if ( V_141 [ V_150 ] ) {
if ( F_35 ( V_38 , V_237 ,
V_141 [ V_150 ] ,
V_53 -> type -> V_239 , NULL ) )
return - V_40 ;
V_22 = F_139 ( V_140 , V_86 , V_53 , V_38 , V_107 , V_48 ,
V_216 ) ;
} else {
int V_240 ;
F_144 (nla, attr[IPSET_ATTR_ADT], nla_rem) {
memset ( V_38 , 0 , sizeof( V_38 ) ) ;
if ( V_35 ( V_34 ) != V_150 ||
! F_32 ( V_34 ) ||
F_35 ( V_38 , V_237 , V_34 ,
V_53 -> type -> V_239 , NULL ) )
return - V_40 ;
V_22 = F_139 ( V_140 , V_86 , V_53 , V_38 , V_107 ,
V_48 , V_216 ) ;
if ( V_22 < 0 )
return V_22 ;
}
}
return V_22 ;
}
static int F_145 ( struct V_2 * V_2 , struct V_139 * V_140 , struct V_85 * V_86 ,
const struct V_121 * V_122 ,
const struct V_33 * const V_141 [] )
{
struct V_1 * V_94 = F_1 ( V_2 ) ;
struct V_52 * V_53 ;
struct V_33 * V_38 [ V_237 + 1 ] = {} ;
const struct V_33 * V_34 ;
T_4 V_48 = F_92 ( V_122 ) ;
bool V_216 ;
int V_22 = 0 ;
if ( F_34 ( F_90 ( V_141 ) ||
! V_141 [ V_146 ] ||
! ( ( V_141 [ V_150 ] != NULL ) ^
( V_141 [ V_238 ] != NULL ) ) ||
( V_141 [ V_150 ] &&
! F_32 ( V_141 [ V_150 ] ) ) ||
( V_141 [ V_238 ] &&
( ! F_32 ( V_141 [ V_238 ] ) ||
! V_141 [ V_234 ] ) ) ) )
return - V_40 ;
V_53 = F_98 ( V_94 , F_39 ( V_141 [ V_146 ] ) ) ;
if ( ! V_53 )
return - V_164 ;
V_216 = ! ! V_141 [ V_234 ] ;
if ( V_141 [ V_150 ] ) {
if ( F_35 ( V_38 , V_237 ,
V_141 [ V_150 ] ,
V_53 -> type -> V_239 , NULL ) )
return - V_40 ;
V_22 = F_139 ( V_140 , V_86 , V_53 , V_38 , V_114 , V_48 ,
V_216 ) ;
} else {
int V_240 ;
F_144 (nla, attr[IPSET_ATTR_ADT], nla_rem) {
memset ( V_38 , 0 , sizeof( * V_38 ) ) ;
if ( V_35 ( V_34 ) != V_150 ||
! F_32 ( V_34 ) ||
F_35 ( V_38 , V_237 , V_34 ,
V_53 -> type -> V_239 , NULL ) )
return - V_40 ;
V_22 = F_139 ( V_140 , V_86 , V_53 , V_38 , V_114 ,
V_48 , V_216 ) ;
if ( V_22 < 0 )
return V_22 ;
}
}
return V_22 ;
}
static int F_146 ( struct V_2 * V_2 , struct V_139 * V_140 , struct V_85 * V_86 ,
const struct V_121 * V_122 ,
const struct V_33 * const V_141 [] )
{
struct V_1 * V_94 = F_1 ( V_2 ) ;
struct V_52 * V_53 ;
struct V_33 * V_38 [ V_237 + 1 ] = {} ;
int V_22 = 0 ;
if ( F_34 ( F_90 ( V_141 ) ||
! V_141 [ V_146 ] ||
! V_141 [ V_150 ] ||
! F_32 ( V_141 [ V_150 ] ) ) )
return - V_40 ;
V_53 = F_98 ( V_94 , F_39 ( V_141 [ V_146 ] ) ) ;
if ( ! V_53 )
return - V_164 ;
if ( F_35 ( V_38 , V_237 , V_141 [ V_150 ] ,
V_53 -> type -> V_239 , NULL ) )
return - V_40 ;
F_78 () ;
V_22 = V_53 -> V_102 -> V_220 ( V_53 , V_38 , V_104 , NULL , 0 , 0 ) ;
F_79 () ;
if ( V_22 == - V_105 )
V_22 = 1 ;
return V_22 > 0 ? 0 : - V_222 ;
}
static int F_147 ( struct V_2 * V_2 , struct V_139 * V_140 ,
struct V_85 * V_86 , const struct V_121 * V_122 ,
const struct V_33 * const V_141 [] )
{
struct V_1 * V_94 = F_1 ( V_2 ) ;
const struct V_52 * V_53 ;
struct V_85 * V_224 ;
struct V_121 * V_241 ;
int V_22 = 0 ;
if ( F_34 ( F_90 ( V_141 ) ||
! V_141 [ V_146 ] ) )
return - V_40 ;
V_53 = F_98 ( V_94 , F_39 ( V_141 [ V_146 ] ) ) ;
if ( ! V_53 )
return - V_164 ;
V_224 = F_140 ( V_242 , V_31 ) ;
if ( ! V_224 )
return - V_151 ;
V_241 = F_93 ( V_224 , F_129 ( V_86 ) . V_126 , V_122 -> V_201 , 0 ,
V_243 ) ;
if ( ! V_241 )
goto V_244;
if ( F_134 ( V_224 , V_120 , V_24 ) ||
F_135 ( V_224 , V_146 , V_53 -> V_6 ) ||
F_135 ( V_224 , V_147 , V_53 -> type -> V_6 ) ||
F_134 ( V_224 , V_149 , V_53 -> V_7 ) ||
F_134 ( V_224 , V_148 , V_53 -> V_8 ) )
goto V_204;
F_136 ( V_224 , V_241 ) ;
V_22 = F_142 ( V_140 , V_224 , F_129 ( V_86 ) . V_126 , V_235 ) ;
if ( V_22 < 0 )
return V_22 ;
return 0 ;
V_204:
F_148 ( V_224 , V_241 ) ;
V_244:
F_149 ( V_224 ) ;
return - V_89 ;
}
static int V_5 ( struct V_2 * V_2 , struct V_139 * V_140 , struct V_85 * V_86 ,
const struct V_121 * V_122 ,
const struct V_33 * const V_141 [] )
{
struct V_85 * V_224 ;
struct V_121 * V_241 ;
T_1 V_7 , V_20 , V_21 ;
const char * V_145 ;
int V_22 = 0 ;
if ( F_34 ( F_90 ( V_141 ) ||
! V_141 [ V_147 ] ||
! V_141 [ V_149 ] ) )
return - V_40 ;
V_7 = F_91 ( V_141 [ V_149 ] ) ;
V_145 = F_39 ( V_141 [ V_147 ] ) ;
V_22 = F_150 ( V_145 , V_7 , & V_20 , & V_21 ) ;
if ( V_22 )
return V_22 ;
V_224 = F_140 ( V_242 , V_31 ) ;
if ( ! V_224 )
return - V_151 ;
V_241 = F_93 ( V_224 , F_129 ( V_86 ) . V_126 , V_122 -> V_201 , 0 ,
V_245 ) ;
if ( ! V_241 )
goto V_244;
if ( F_134 ( V_224 , V_120 , V_24 ) ||
F_135 ( V_224 , V_147 , V_145 ) ||
F_134 ( V_224 , V_149 , V_7 ) ||
F_134 ( V_224 , V_148 , V_21 ) ||
F_134 ( V_224 , V_246 , V_20 ) )
goto V_204;
F_136 ( V_224 , V_241 ) ;
F_11 ( L_26 , V_241 -> V_188 ) ;
V_22 = F_142 ( V_140 , V_224 , F_129 ( V_86 ) . V_126 , V_235 ) ;
if ( V_22 < 0 )
return V_22 ;
return 0 ;
V_204:
F_148 ( V_224 , V_241 ) ;
V_244:
F_149 ( V_224 ) ;
return - V_89 ;
}
static int F_151 ( struct V_2 * V_2 , struct V_139 * V_140 ,
struct V_85 * V_86 , const struct V_121 * V_122 ,
const struct V_33 * const V_141 [] )
{
struct V_85 * V_224 ;
struct V_121 * V_241 ;
int V_22 = 0 ;
if ( F_34 ( ! V_141 [ V_120 ] ) )
return - V_40 ;
V_224 = F_140 ( V_242 , V_31 ) ;
if ( ! V_224 )
return - V_151 ;
V_241 = F_93 ( V_224 , F_129 ( V_86 ) . V_126 , V_122 -> V_201 , 0 ,
V_247 ) ;
if ( ! V_241 )
goto V_244;
if ( F_134 ( V_224 , V_120 , V_24 ) )
goto V_204;
F_136 ( V_224 , V_241 ) ;
V_22 = F_142 ( V_140 , V_224 , F_129 ( V_86 ) . V_126 , V_235 ) ;
if ( V_22 < 0 )
return V_22 ;
return 0 ;
V_204:
F_148 ( V_224 , V_241 ) ;
V_244:
F_149 ( V_224 ) ;
return - V_89 ;
}
static int
F_152 ( struct V_139 * V_196 , int V_248 , void T_7 * V_249 , int * V_54 )
{
unsigned int * V_250 ;
void * V_251 ;
int V_252 = * V_54 , V_22 = 0 ;
struct V_2 * V_2 = F_130 ( V_196 ) ;
struct V_1 * V_94 = F_1 ( V_2 ) ;
if ( ! F_153 ( V_2 -> V_253 , V_254 ) )
return - V_255 ;
if ( V_248 != V_256 )
return - V_257 ;
if ( * V_54 < sizeof( unsigned int ) )
return - V_25 ;
V_251 = F_154 ( * V_54 ) ;
if ( ! V_251 )
return - V_151 ;
if ( F_155 ( V_251 , V_249 , * V_54 ) != 0 ) {
V_22 = - V_18 ;
goto V_213;
}
V_250 = V_251 ;
if ( * V_250 < V_258 ) {
struct V_259 * V_260 = V_251 ;
if ( * V_54 < sizeof( struct V_259 ) ) {
V_22 = - V_25 ;
goto V_213;
}
if ( V_260 -> V_134 != V_24 ) {
V_22 = - V_261 ;
goto V_213;
}
}
switch ( * V_250 ) {
case V_258 : {
struct V_259 * V_260 = V_251 ;
if ( * V_54 != sizeof( struct V_259 ) ) {
V_22 = - V_25 ;
goto V_213;
}
V_260 -> V_134 = V_24 ;
V_22 = F_156 ( V_249 , V_260 ,
sizeof( struct V_259 ) ) ;
goto V_213;
}
case V_262 : {
struct V_263 * V_264 = V_251 ;
T_6 V_47 ;
if ( * V_54 != sizeof( struct V_263 ) ) {
V_22 = - V_25 ;
goto V_213;
}
V_264 -> V_53 . V_6 [ V_152 - 1 ] = '\0' ;
F_14 ( V_12 ) ;
F_97 ( V_94 , V_264 -> V_53 . V_6 , & V_47 ) ;
V_264 -> V_53 . V_93 = V_47 ;
F_10 ( V_12 ) ;
goto V_265;
}
case V_266 : {
struct V_267 * V_264 = V_251 ;
T_6 V_47 ;
if ( * V_54 != sizeof( struct V_267 ) ) {
V_22 = - V_25 ;
goto V_213;
}
V_264 -> V_53 . V_6 [ V_152 - 1 ] = '\0' ;
F_14 ( V_12 ) ;
F_97 ( V_94 , V_264 -> V_53 . V_6 , & V_47 ) ;
V_264 -> V_53 . V_93 = V_47 ;
if ( V_47 != V_116 )
V_264 -> V_7 = V_52 ( V_94 , V_47 ) -> V_7 ;
F_10 ( V_12 ) ;
goto V_265;
}
case V_268 : {
struct V_263 * V_264 = V_251 ;
struct V_52 * V_53 ;
if ( * V_54 != sizeof( struct V_263 ) ||
V_264 -> V_53 . V_93 >= V_94 -> V_118 ) {
V_22 = - V_25 ;
goto V_213;
}
F_14 ( V_12 ) ;
V_53 = V_52 ( V_94 , V_264 -> V_53 . V_93 ) ;
strncpy ( V_264 -> V_53 . V_6 , V_53 ? V_53 -> V_6 : L_27 ,
V_152 ) ;
F_10 ( V_12 ) ;
goto V_265;
}
default:
V_22 = - V_269 ;
goto V_213;
}
V_265:
V_22 = F_156 ( V_249 , V_251 , V_252 ) ;
V_213:
F_157 ( V_251 ) ;
if ( V_22 > 0 )
V_22 = 0 ;
return V_22 ;
}
static int T_8
F_158 ( struct V_2 * V_2 )
{
struct V_1 * V_94 = F_1 ( V_2 ) ;
struct V_52 * * V_26 ;
V_94 -> V_118 = V_270 ? V_270 : V_271 ;
if ( V_94 -> V_118 >= V_116 )
V_94 -> V_118 = V_116 - 1 ;
V_26 = F_105 ( V_94 -> V_118 , sizeof( struct V_52 * ) , V_31 ) ;
if ( ! V_26 )
return - V_151 ;
V_94 -> V_119 = false ;
V_94 -> V_163 = false ;
F_107 ( V_94 -> V_95 , V_26 ) ;
return 0 ;
}
static void T_9
F_159 ( struct V_2 * V_2 )
{
struct V_1 * V_94 = F_1 ( V_2 ) ;
struct V_52 * V_53 = NULL ;
T_6 V_115 ;
V_94 -> V_119 = true ;
for ( V_115 = 0 ; V_115 < V_94 -> V_118 ; V_115 ++ ) {
V_53 = V_52 ( V_94 , V_115 ) ;
if ( V_53 ) {
V_52 ( V_94 , V_115 ) = NULL ;
F_111 ( V_53 ) ;
}
}
F_109 ( F_160 ( V_94 -> V_95 , 1 ) ) ;
}
static int T_10
F_161 ( void )
{
int V_22 = F_162 ( & V_272 ) ;
if ( V_22 != 0 ) {
F_163 ( L_28 ) ;
return V_22 ;
}
V_22 = F_164 ( & V_273 ) ;
if ( V_22 != 0 ) {
F_163 ( L_29 , V_22 ) ;
F_165 ( & V_272 ) ;
return V_22 ;
}
V_22 = F_166 ( & V_274 ) ;
if ( V_22 ) {
F_163 ( L_30 ) ;
F_167 ( & V_273 ) ;
F_165 ( & V_272 ) ;
return V_22 ;
}
F_168 ( L_31 , V_24 ) ;
return 0 ;
}
static void T_11
F_169 ( void )
{
F_170 ( & V_274 ) ;
F_167 ( & V_273 ) ;
F_165 ( & V_272 ) ;
F_11 ( L_32 ) ;
}
