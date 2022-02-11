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
const struct V_33 * const V_141 [] ,
struct V_142 * V_143 )
{
return - V_144 ;
}
static int F_101 ( struct V_2 * V_2 , struct V_139 * V_140 ,
struct V_85 * V_86 , const struct V_121 * V_122 ,
const struct V_33 * const V_141 [] ,
struct V_142 * V_143 )
{
struct V_1 * V_94 = F_1 ( V_2 ) ;
struct V_52 * V_53 , * V_145 = NULL ;
T_6 V_93 = V_116 ;
struct V_33 * V_38 [ V_146 + 1 ] = {} ;
const char * V_6 , * V_147 ;
T_1 V_7 , V_8 ;
T_4 V_48 = F_92 ( V_122 ) ;
int V_22 = 0 ;
if ( F_34 ( F_90 ( V_141 ) ||
! V_141 [ V_148 ] ||
! V_141 [ V_149 ] ||
! V_141 [ V_150 ] ||
! V_141 [ V_151 ] ||
( V_141 [ V_152 ] &&
! F_32 ( V_141 [ V_152 ] ) ) ) )
return - V_40 ;
V_6 = F_39 ( V_141 [ V_148 ] ) ;
V_147 = F_39 ( V_141 [ V_149 ] ) ;
V_7 = F_91 ( V_141 [ V_151 ] ) ;
V_8 = F_91 ( V_141 [ V_150 ] ) ;
F_11 ( L_16 ,
V_6 , V_147 , F_21 ( V_7 ) , V_8 ) ;
V_53 = F_27 ( sizeof( * V_53 ) , V_31 ) ;
if ( ! V_53 )
return - V_153 ;
F_102 ( & V_53 -> V_106 ) ;
F_103 ( V_53 -> V_6 , V_6 , V_154 ) ;
V_53 -> V_7 = V_7 ;
V_53 -> V_8 = V_8 ;
V_22 = F_104 ( V_147 , V_7 , V_8 , & V_53 -> type ) ;
if ( V_22 )
goto V_155;
if ( V_141 [ V_152 ] &&
F_35 ( V_38 , V_146 , V_141 [ V_152 ] ,
V_53 -> type -> V_156 , NULL ) ) {
V_22 = - V_40 ;
goto V_157;
}
V_22 = V_53 -> type -> V_158 ( V_2 , V_53 , V_38 , V_48 ) ;
if ( V_22 != 0 )
goto V_157;
V_22 = F_99 ( V_94 , V_53 -> V_6 , & V_93 , & V_145 ) ;
if ( V_22 == - V_137 ) {
if ( ( V_48 & V_125 ) &&
STRNCMP ( V_53 -> type -> V_6 , V_145 -> type -> V_6 ) &&
V_53 -> type -> V_7 == V_145 -> type -> V_7 &&
V_53 -> type -> V_10 == V_145 -> type -> V_10 &&
V_53 -> type -> V_11 == V_145 -> type -> V_11 &&
V_53 -> V_102 -> V_159 ( V_53 , V_145 ) )
V_22 = 0 ;
goto V_160;
} else if ( V_22 == - V_138 ) {
struct V_52 * * V_26 , * * V_161 ;
T_6 V_115 = V_94 -> V_118 + V_162 ;
if ( V_115 < V_94 -> V_118 || V_115 == V_116 )
goto V_160;
V_26 = F_105 ( V_115 , sizeof( struct V_52 * ) , V_31 ) ;
if ( ! V_26 )
goto V_160;
V_161 = F_106 ( V_94 -> V_95 ) ;
memcpy ( V_26 , V_161 , sizeof( struct V_52 * ) * V_94 -> V_118 ) ;
F_107 ( V_94 -> V_95 , V_26 ) ;
F_108 () ;
V_93 = V_94 -> V_118 ;
V_94 -> V_118 = V_115 ;
F_109 ( V_161 ) ;
V_22 = 0 ;
} else if ( V_22 ) {
goto V_160;
}
F_11 ( L_17 , V_53 -> V_6 , V_93 ) ;
V_52 ( V_94 , V_93 ) = V_53 ;
return V_22 ;
V_160:
V_53 -> V_102 -> V_163 ( V_53 ) ;
V_157:
F_110 ( V_53 -> type -> V_17 ) ;
V_155:
F_109 ( V_53 ) ;
return V_22 ;
}
static void
F_111 ( struct V_52 * V_53 )
{
F_11 ( L_18 , V_53 -> V_6 ) ;
V_53 -> V_102 -> V_163 ( V_53 ) ;
F_110 ( V_53 -> type -> V_17 ) ;
F_109 ( V_53 ) ;
}
static int F_112 ( struct V_2 * V_2 , struct V_139 * V_140 ,
struct V_85 * V_86 , const struct V_121 * V_122 ,
const struct V_33 * const V_141 [] ,
struct V_142 * V_143 )
{
struct V_1 * V_94 = F_1 ( V_2 ) ;
struct V_52 * V_117 ;
T_6 V_115 ;
int V_22 = 0 ;
if ( F_34 ( F_90 ( V_141 ) ) )
return - V_40 ;
F_113 () ;
F_114 ( & V_90 ) ;
if ( ! V_141 [ V_148 ] ) {
for ( V_115 = 0 ; V_115 < V_94 -> V_118 ; V_115 ++ ) {
V_117 = V_52 ( V_94 , V_115 ) ;
if ( V_117 && ( V_117 -> V_91 || V_117 -> V_92 ) ) {
V_22 = - V_164 ;
goto V_155;
}
}
V_94 -> V_165 = true ;
F_115 ( & V_90 ) ;
for ( V_115 = 0 ; V_115 < V_94 -> V_118 ; V_115 ++ ) {
V_117 = V_52 ( V_94 , V_115 ) ;
if ( V_117 ) {
V_52 ( V_94 , V_115 ) = NULL ;
F_111 ( V_117 ) ;
}
}
V_94 -> V_165 = false ;
} else {
V_117 = F_97 ( V_94 , F_39 ( V_141 [ V_148 ] ) ,
& V_115 ) ;
if ( ! V_117 ) {
V_22 = - V_166 ;
goto V_155;
} else if ( V_117 -> V_91 || V_117 -> V_92 ) {
V_22 = - V_164 ;
goto V_155;
}
V_52 ( V_94 , V_115 ) = NULL ;
F_115 ( & V_90 ) ;
F_111 ( V_117 ) ;
}
return 0 ;
V_155:
F_115 ( & V_90 ) ;
return V_22 ;
}
static void
F_116 ( struct V_52 * V_53 )
{
F_11 ( L_18 , V_53 -> V_6 ) ;
F_80 ( & V_53 -> V_106 ) ;
V_53 -> V_102 -> V_167 ( V_53 ) ;
F_81 ( & V_53 -> V_106 ) ;
}
static int F_117 ( struct V_2 * V_2 , struct V_139 * V_140 , struct V_85 * V_86 ,
const struct V_121 * V_122 ,
const struct V_33 * const V_141 [] ,
struct V_142 * V_143 )
{
struct V_1 * V_94 = F_1 ( V_2 ) ;
struct V_52 * V_117 ;
T_6 V_115 ;
if ( F_34 ( F_90 ( V_141 ) ) )
return - V_40 ;
if ( ! V_141 [ V_148 ] ) {
for ( V_115 = 0 ; V_115 < V_94 -> V_118 ; V_115 ++ ) {
V_117 = V_52 ( V_94 , V_115 ) ;
if ( V_117 )
F_116 ( V_117 ) ;
}
} else {
V_117 = F_98 ( V_94 , F_39 ( V_141 [ V_148 ] ) ) ;
if ( ! V_117 )
return - V_166 ;
F_116 ( V_117 ) ;
}
return 0 ;
}
static int F_118 ( struct V_2 * V_2 , struct V_139 * V_140 ,
struct V_85 * V_86 , const struct V_121 * V_122 ,
const struct V_33 * const V_141 [] ,
struct V_142 * V_143 )
{
struct V_1 * V_94 = F_1 ( V_2 ) ;
struct V_52 * V_53 , * V_117 ;
const char * V_168 ;
T_6 V_115 ;
int V_22 = 0 ;
if ( F_34 ( F_90 ( V_141 ) ||
! V_141 [ V_148 ] ||
! V_141 [ V_169 ] ) )
return - V_40 ;
V_53 = F_98 ( V_94 , F_39 ( V_141 [ V_148 ] ) ) ;
if ( ! V_53 )
return - V_166 ;
F_114 ( & V_90 ) ;
if ( V_53 -> V_91 != 0 ) {
V_22 = - V_170 ;
goto V_155;
}
V_168 = F_39 ( V_141 [ V_169 ] ) ;
for ( V_115 = 0 ; V_115 < V_94 -> V_118 ; V_115 ++ ) {
V_117 = V_52 ( V_94 , V_115 ) ;
if ( V_117 && STRNCMP ( V_117 -> V_6 , V_168 ) ) {
V_22 = - V_171 ;
goto V_155;
}
}
strncpy ( V_53 -> V_6 , V_168 , V_154 ) ;
V_155:
F_115 ( & V_90 ) ;
return V_22 ;
}
static int F_119 ( struct V_2 * V_2 , struct V_139 * V_140 , struct V_85 * V_86 ,
const struct V_121 * V_122 ,
const struct V_33 * const V_141 [] ,
struct V_142 * V_143 )
{
struct V_1 * V_94 = F_1 ( V_2 ) ;
struct V_52 * V_172 , * V_173 ;
T_6 V_174 , V_175 ;
char V_176 [ V_154 ] ;
if ( F_34 ( F_90 ( V_141 ) ||
! V_141 [ V_148 ] ||
! V_141 [ V_169 ] ) )
return - V_40 ;
V_172 = F_97 ( V_94 , F_39 ( V_141 [ V_148 ] ) ,
& V_174 ) ;
if ( ! V_172 )
return - V_166 ;
V_173 = F_97 ( V_94 , F_39 ( V_141 [ V_169 ] ) ,
& V_175 ) ;
if ( ! V_173 )
return - V_171 ;
if ( ! ( V_172 -> type -> V_110 == V_173 -> type -> V_110 &&
V_172 -> V_7 == V_173 -> V_7 ) )
return - V_113 ;
if ( V_172 -> V_92 || V_173 -> V_92 )
return - V_177 ;
strncpy ( V_176 , V_172 -> V_6 , V_154 ) ;
strncpy ( V_172 -> V_6 , V_173 -> V_6 , V_154 ) ;
strncpy ( V_173 -> V_6 , V_176 , V_154 ) ;
F_69 ( & V_90 ) ;
F_120 ( V_172 -> V_91 , V_173 -> V_91 ) ;
V_52 ( V_94 , V_174 ) = V_173 ;
V_52 ( V_94 , V_175 ) = V_172 ;
F_70 ( & V_90 ) ;
return 0 ;
}
static int
F_121 ( struct V_178 * V_179 )
{
if ( V_179 -> args [ V_180 ] ) {
struct V_1 * V_94 =
(struct V_1 * ) V_179 -> args [ V_181 ] ;
T_6 V_93 = ( T_6 ) V_179 -> args [ V_182 ] ;
struct V_52 * V_53 = V_52 ( V_94 , V_93 ) ;
if ( V_53 -> V_102 -> V_183 )
V_53 -> V_102 -> V_183 ( V_53 , V_179 , false ) ;
F_11 ( L_19 , V_53 -> V_6 ) ;
F_73 ( V_53 ) ;
}
return 0 ;
}
static inline void
F_122 ( struct V_121 * V_122 )
{
const struct V_33 * V_141 ;
int V_184 ;
F_11 ( L_20 ) ;
F_123 (attr, nlh, sizeof(struct nfgenmsg), rem) {
F_11 ( L_21 , V_35 ( V_141 ) , V_141 -> V_185 ) ;
}
}
static int
F_124 ( struct V_178 * V_179 , struct V_1 * V_94 )
{
struct V_121 * V_122 = F_125 ( V_179 -> V_86 ) ;
int V_186 = F_126 ( sizeof( struct V_130 ) ) ;
struct V_33 * V_187 [ V_188 + 1 ] ;
struct V_33 * V_141 = ( void * ) V_122 + V_186 ;
T_4 V_189 ;
T_6 V_93 ;
F_127 ( V_187 , V_188 , V_141 , V_122 -> V_190 - V_186 ,
V_191 , NULL ) ;
if ( V_187 [ V_148 ] ) {
struct V_52 * V_53 ;
V_53 = F_97 ( V_94 , F_39 ( V_187 [ V_148 ] ) ,
& V_93 ) ;
if ( ! V_53 )
return - V_166 ;
V_189 = V_192 ;
V_179 -> args [ V_182 ] = V_93 ;
} else {
V_189 = V_193 ;
}
if ( V_187 [ V_194 ] ) {
T_4 V_195 = F_42 ( V_187 [ V_194 ] ) ;
V_189 |= ( V_195 << 16 ) ;
}
V_179 -> args [ V_181 ] = ( unsigned long ) V_94 ;
V_179 -> args [ V_196 ] = V_189 ;
return 0 ;
}
static int
F_128 ( struct V_85 * V_86 , struct V_178 * V_179 )
{
T_6 V_93 = V_116 , V_21 ;
struct V_52 * V_53 = NULL ;
struct V_121 * V_122 = NULL ;
unsigned int V_48 = F_129 ( V_179 -> V_86 ) . V_126 ? V_197 : 0 ;
struct V_1 * V_94 = F_1 ( F_130 ( V_86 -> V_198 ) ) ;
T_4 V_189 , V_199 ;
bool V_165 ;
int V_22 = 0 ;
if ( ! V_179 -> args [ V_196 ] ) {
V_22 = F_124 ( V_179 , V_94 ) ;
if ( V_22 < 0 ) {
V_122 = F_125 ( V_179 -> V_86 ) ;
if ( V_122 -> V_123 & V_200 )
F_131 ( V_179 -> V_86 , V_122 , V_22 , NULL ) ;
return V_22 ;
}
}
if ( V_179 -> args [ V_182 ] >= V_94 -> V_118 )
goto V_155;
V_189 = F_132 ( V_179 -> args [ V_196 ] ) ;
V_199 = F_133 ( V_179 -> args [ V_196 ] ) ;
V_21 = V_189 == V_192 ? V_179 -> args [ V_182 ] + 1
: V_94 -> V_118 ;
V_201:
F_11 ( L_22 ,
V_189 , V_199 , V_179 -> args [ V_182 ] ) ;
for (; V_179 -> args [ V_182 ] < V_21 ; V_179 -> args [ V_182 ] ++ ) {
V_93 = ( T_6 ) V_179 -> args [ V_182 ] ;
F_69 ( & V_90 ) ;
V_53 = V_52 ( V_94 , V_93 ) ;
V_165 = V_94 -> V_165 ;
if ( ! V_53 || V_165 ) {
F_70 ( & V_90 ) ;
if ( V_189 == V_192 ) {
V_22 = - V_166 ;
goto V_155;
}
if ( V_165 ) {
V_22 = 0 ;
goto V_155;
}
continue;
}
if ( V_189 != V_192 &&
( ( V_189 == V_193 ) ==
! ! ( V_53 -> type -> V_110 & V_202 ) ) ) {
F_70 ( & V_90 ) ;
continue;
}
F_11 ( L_23 , V_53 -> V_6 ) ;
if ( ! V_179 -> args [ V_180 ] ) {
F_11 ( L_24 ) ;
V_53 -> V_92 ++ ;
}
F_70 ( & V_90 ) ;
V_122 = F_93 ( V_86 , F_129 ( V_179 -> V_86 ) . V_126 ,
V_179 -> V_122 -> V_203 , V_48 ,
V_204 ) ;
if ( ! V_122 ) {
V_22 = - V_89 ;
goto V_205;
}
if ( F_134 ( V_86 , V_120 , V_24 ) ||
F_135 ( V_86 , V_148 , V_53 -> V_6 ) )
goto V_206;
if ( V_199 & V_207 )
goto V_208;
switch ( V_179 -> args [ V_180 ] ) {
case 0 :
if ( F_135 ( V_86 , V_149 ,
V_53 -> type -> V_6 ) ||
F_134 ( V_86 , V_151 ,
V_53 -> V_7 ) ||
F_134 ( V_86 , V_150 ,
V_53 -> V_8 ) )
goto V_206;
V_22 = V_53 -> V_102 -> V_209 ( V_53 , V_86 ) ;
if ( V_22 < 0 )
goto V_205;
if ( V_199 & V_210 )
goto V_208;
if ( V_53 -> V_102 -> V_183 )
V_53 -> V_102 -> V_183 ( V_53 , V_179 , true ) ;
default:
F_78 () ;
V_22 = V_53 -> V_102 -> V_26 ( V_53 , V_86 , V_179 ) ;
F_79 () ;
if ( ! V_179 -> args [ V_180 ] )
goto V_208;
goto V_205;
}
}
if ( V_189 == V_193 ) {
V_189 = V_211 ;
V_179 -> args [ V_196 ] = V_189 | ( V_199 << 16 ) ;
V_179 -> args [ V_182 ] = 0 ;
if ( V_53 && V_53 -> V_102 -> V_183 )
V_53 -> V_102 -> V_183 ( V_53 , V_179 , false ) ;
goto V_201;
}
goto V_155;
V_206:
V_22 = - V_18 ;
V_208:
if ( V_189 == V_192 )
V_179 -> args [ V_182 ] = V_116 ;
else
V_179 -> args [ V_182 ] ++ ;
V_205:
if ( V_22 || ! V_179 -> args [ V_180 ] ) {
V_53 = V_52 ( V_94 , V_93 ) ;
if ( V_53 -> V_102 -> V_183 )
V_53 -> V_102 -> V_183 ( V_53 , V_179 , false ) ;
F_11 ( L_19 , V_53 -> V_6 ) ;
F_73 ( V_53 ) ;
V_179 -> args [ V_180 ] = 0 ;
}
V_155:
if ( V_122 ) {
F_136 ( V_86 , V_122 ) ;
F_11 ( L_25 , V_122 -> V_190 ) ;
F_122 ( V_122 ) ;
}
return V_22 < 0 ? V_22 : V_86 -> V_54 ;
}
static int F_137 ( struct V_2 * V_2 , struct V_139 * V_140 , struct V_85 * V_86 ,
const struct V_121 * V_122 ,
const struct V_33 * const V_141 [] ,
struct V_142 * V_143 )
{
if ( F_34 ( F_90 ( V_141 ) ) )
return - V_40 ;
{
struct V_212 V_213 = {
. V_214 = F_128 ,
. V_215 = F_121 ,
} ;
return F_138 ( V_140 , V_86 , V_122 , & V_213 ) ;
}
}
static int
F_139 ( struct V_139 * V_140 , struct V_85 * V_86 , struct V_52 * V_53 ,
struct V_33 * V_38 [] , enum V_216 V_217 ,
T_4 V_48 , bool V_218 )
{
int V_22 ;
T_4 V_219 = 0 ;
bool V_220 = V_48 & V_125 , V_221 = false ;
do {
F_80 ( & V_53 -> V_106 ) ;
V_22 = V_53 -> V_102 -> V_222 ( V_53 , V_38 , V_217 , & V_219 , V_48 , V_221 ) ;
F_81 ( & V_53 -> V_106 ) ;
V_221 = true ;
} while ( V_22 == - V_105 &&
V_53 -> V_102 -> V_223 &&
( V_22 = V_53 -> V_102 -> V_223 ( V_53 , V_221 ) ) == 0 );
if ( ! V_22 || ( V_22 == - V_224 && V_220 ) )
return 0 ;
if ( V_219 && V_218 ) {
struct V_121 * V_225 , * V_122 = F_125 ( V_86 ) ;
struct V_85 * V_226 ;
struct V_227 * V_228 ;
T_2 V_229 = V_20 ( V_230 ,
sizeof( * V_228 ) + V_190 ( V_122 ) ) ;
int V_186 = F_126 ( sizeof( struct V_130 ) ) ;
struct V_33 * V_187 [ V_188 + 1 ] ;
struct V_33 * V_231 ;
T_4 * V_232 ;
V_226 = F_140 ( V_229 , V_31 ) ;
if ( ! V_226 )
return - V_153 ;
V_225 = F_141 ( V_226 , F_129 ( V_86 ) . V_126 ,
V_122 -> V_203 , V_233 , V_229 , 0 ) ;
V_228 = F_96 ( V_225 ) ;
V_228 -> error = V_22 ;
memcpy ( & V_228 -> V_234 , V_122 , V_122 -> V_190 ) ;
V_231 = ( void * ) & V_228 -> V_234 + V_186 ;
F_127 ( V_187 , V_188 , V_231 ,
V_122 -> V_190 - V_186 , V_235 , NULL ) ;
V_232 = F_39 ( V_187 [ V_236 ] ) ;
* V_232 = V_219 ;
F_142 ( V_140 , V_226 , F_129 ( V_86 ) . V_126 ,
V_237 ) ;
return - V_238 ;
}
return V_22 ;
}
static int F_143 ( struct V_2 * V_2 , struct V_139 * V_140 , struct V_85 * V_86 ,
const struct V_121 * V_122 ,
const struct V_33 * const V_141 [] ,
struct V_142 * V_143 )
{
struct V_1 * V_94 = F_1 ( V_2 ) ;
struct V_52 * V_53 ;
struct V_33 * V_38 [ V_239 + 1 ] = {} ;
const struct V_33 * V_34 ;
T_4 V_48 = F_92 ( V_122 ) ;
bool V_218 ;
int V_22 = 0 ;
if ( F_34 ( F_90 ( V_141 ) ||
! V_141 [ V_148 ] ||
! ( ( V_141 [ V_152 ] != NULL ) ^
( V_141 [ V_240 ] != NULL ) ) ||
( V_141 [ V_152 ] &&
! F_32 ( V_141 [ V_152 ] ) ) ||
( V_141 [ V_240 ] &&
( ! F_32 ( V_141 [ V_240 ] ) ||
! V_141 [ V_236 ] ) ) ) )
return - V_40 ;
V_53 = F_98 ( V_94 , F_39 ( V_141 [ V_148 ] ) ) ;
if ( ! V_53 )
return - V_166 ;
V_218 = ! ! V_141 [ V_236 ] ;
if ( V_141 [ V_152 ] ) {
if ( F_35 ( V_38 , V_239 ,
V_141 [ V_152 ] ,
V_53 -> type -> V_241 , NULL ) )
return - V_40 ;
V_22 = F_139 ( V_140 , V_86 , V_53 , V_38 , V_107 , V_48 ,
V_218 ) ;
} else {
int V_242 ;
F_144 (nla, attr[IPSET_ATTR_ADT], nla_rem) {
memset ( V_38 , 0 , sizeof( V_38 ) ) ;
if ( V_35 ( V_34 ) != V_152 ||
! F_32 ( V_34 ) ||
F_35 ( V_38 , V_239 , V_34 ,
V_53 -> type -> V_241 , NULL ) )
return - V_40 ;
V_22 = F_139 ( V_140 , V_86 , V_53 , V_38 , V_107 ,
V_48 , V_218 ) ;
if ( V_22 < 0 )
return V_22 ;
}
}
return V_22 ;
}
static int F_145 ( struct V_2 * V_2 , struct V_139 * V_140 , struct V_85 * V_86 ,
const struct V_121 * V_122 ,
const struct V_33 * const V_141 [] ,
struct V_142 * V_143 )
{
struct V_1 * V_94 = F_1 ( V_2 ) ;
struct V_52 * V_53 ;
struct V_33 * V_38 [ V_239 + 1 ] = {} ;
const struct V_33 * V_34 ;
T_4 V_48 = F_92 ( V_122 ) ;
bool V_218 ;
int V_22 = 0 ;
if ( F_34 ( F_90 ( V_141 ) ||
! V_141 [ V_148 ] ||
! ( ( V_141 [ V_152 ] != NULL ) ^
( V_141 [ V_240 ] != NULL ) ) ||
( V_141 [ V_152 ] &&
! F_32 ( V_141 [ V_152 ] ) ) ||
( V_141 [ V_240 ] &&
( ! F_32 ( V_141 [ V_240 ] ) ||
! V_141 [ V_236 ] ) ) ) )
return - V_40 ;
V_53 = F_98 ( V_94 , F_39 ( V_141 [ V_148 ] ) ) ;
if ( ! V_53 )
return - V_166 ;
V_218 = ! ! V_141 [ V_236 ] ;
if ( V_141 [ V_152 ] ) {
if ( F_35 ( V_38 , V_239 ,
V_141 [ V_152 ] ,
V_53 -> type -> V_241 , NULL ) )
return - V_40 ;
V_22 = F_139 ( V_140 , V_86 , V_53 , V_38 , V_114 , V_48 ,
V_218 ) ;
} else {
int V_242 ;
F_144 (nla, attr[IPSET_ATTR_ADT], nla_rem) {
memset ( V_38 , 0 , sizeof( * V_38 ) ) ;
if ( V_35 ( V_34 ) != V_152 ||
! F_32 ( V_34 ) ||
F_35 ( V_38 , V_239 , V_34 ,
V_53 -> type -> V_241 , NULL ) )
return - V_40 ;
V_22 = F_139 ( V_140 , V_86 , V_53 , V_38 , V_114 ,
V_48 , V_218 ) ;
if ( V_22 < 0 )
return V_22 ;
}
}
return V_22 ;
}
static int F_146 ( struct V_2 * V_2 , struct V_139 * V_140 , struct V_85 * V_86 ,
const struct V_121 * V_122 ,
const struct V_33 * const V_141 [] ,
struct V_142 * V_143 )
{
struct V_1 * V_94 = F_1 ( V_2 ) ;
struct V_52 * V_53 ;
struct V_33 * V_38 [ V_239 + 1 ] = {} ;
int V_22 = 0 ;
if ( F_34 ( F_90 ( V_141 ) ||
! V_141 [ V_148 ] ||
! V_141 [ V_152 ] ||
! F_32 ( V_141 [ V_152 ] ) ) )
return - V_40 ;
V_53 = F_98 ( V_94 , F_39 ( V_141 [ V_148 ] ) ) ;
if ( ! V_53 )
return - V_166 ;
if ( F_35 ( V_38 , V_239 , V_141 [ V_152 ] ,
V_53 -> type -> V_241 , NULL ) )
return - V_40 ;
F_78 () ;
V_22 = V_53 -> V_102 -> V_222 ( V_53 , V_38 , V_104 , NULL , 0 , 0 ) ;
F_79 () ;
if ( V_22 == - V_105 )
V_22 = 1 ;
return V_22 > 0 ? 0 : - V_224 ;
}
static int F_147 ( struct V_2 * V_2 , struct V_139 * V_140 ,
struct V_85 * V_86 , const struct V_121 * V_122 ,
const struct V_33 * const V_141 [] ,
struct V_142 * V_143 )
{
struct V_1 * V_94 = F_1 ( V_2 ) ;
const struct V_52 * V_53 ;
struct V_85 * V_226 ;
struct V_121 * V_243 ;
int V_22 = 0 ;
if ( F_34 ( F_90 ( V_141 ) ||
! V_141 [ V_148 ] ) )
return - V_40 ;
V_53 = F_98 ( V_94 , F_39 ( V_141 [ V_148 ] ) ) ;
if ( ! V_53 )
return - V_166 ;
V_226 = F_140 ( V_244 , V_31 ) ;
if ( ! V_226 )
return - V_153 ;
V_243 = F_93 ( V_226 , F_129 ( V_86 ) . V_126 , V_122 -> V_203 , 0 ,
V_245 ) ;
if ( ! V_243 )
goto V_246;
if ( F_134 ( V_226 , V_120 , V_24 ) ||
F_135 ( V_226 , V_148 , V_53 -> V_6 ) ||
F_135 ( V_226 , V_149 , V_53 -> type -> V_6 ) ||
F_134 ( V_226 , V_151 , V_53 -> V_7 ) ||
F_134 ( V_226 , V_150 , V_53 -> V_8 ) )
goto V_206;
F_136 ( V_226 , V_243 ) ;
V_22 = F_142 ( V_140 , V_226 , F_129 ( V_86 ) . V_126 , V_237 ) ;
if ( V_22 < 0 )
return V_22 ;
return 0 ;
V_206:
F_148 ( V_226 , V_243 ) ;
V_246:
F_149 ( V_226 ) ;
return - V_89 ;
}
static int V_5 ( struct V_2 * V_2 , struct V_139 * V_140 , struct V_85 * V_86 ,
const struct V_121 * V_122 ,
const struct V_33 * const V_141 [] ,
struct V_142 * V_143 )
{
struct V_85 * V_226 ;
struct V_121 * V_243 ;
T_1 V_7 , V_20 , V_21 ;
const char * V_147 ;
int V_22 = 0 ;
if ( F_34 ( F_90 ( V_141 ) ||
! V_141 [ V_149 ] ||
! V_141 [ V_151 ] ) )
return - V_40 ;
V_7 = F_91 ( V_141 [ V_151 ] ) ;
V_147 = F_39 ( V_141 [ V_149 ] ) ;
V_22 = F_150 ( V_147 , V_7 , & V_20 , & V_21 ) ;
if ( V_22 )
return V_22 ;
V_226 = F_140 ( V_244 , V_31 ) ;
if ( ! V_226 )
return - V_153 ;
V_243 = F_93 ( V_226 , F_129 ( V_86 ) . V_126 , V_122 -> V_203 , 0 ,
V_247 ) ;
if ( ! V_243 )
goto V_246;
if ( F_134 ( V_226 , V_120 , V_24 ) ||
F_135 ( V_226 , V_149 , V_147 ) ||
F_134 ( V_226 , V_151 , V_7 ) ||
F_134 ( V_226 , V_150 , V_21 ) ||
F_134 ( V_226 , V_248 , V_20 ) )
goto V_206;
F_136 ( V_226 , V_243 ) ;
F_11 ( L_26 , V_243 -> V_190 ) ;
V_22 = F_142 ( V_140 , V_226 , F_129 ( V_86 ) . V_126 , V_237 ) ;
if ( V_22 < 0 )
return V_22 ;
return 0 ;
V_206:
F_148 ( V_226 , V_243 ) ;
V_246:
F_149 ( V_226 ) ;
return - V_89 ;
}
static int F_151 ( struct V_2 * V_2 , struct V_139 * V_140 ,
struct V_85 * V_86 , const struct V_121 * V_122 ,
const struct V_33 * const V_141 [] ,
struct V_142 * V_143 )
{
struct V_85 * V_226 ;
struct V_121 * V_243 ;
int V_22 = 0 ;
if ( F_34 ( ! V_141 [ V_120 ] ) )
return - V_40 ;
V_226 = F_140 ( V_244 , V_31 ) ;
if ( ! V_226 )
return - V_153 ;
V_243 = F_93 ( V_226 , F_129 ( V_86 ) . V_126 , V_122 -> V_203 , 0 ,
V_249 ) ;
if ( ! V_243 )
goto V_246;
if ( F_134 ( V_226 , V_120 , V_24 ) )
goto V_206;
F_136 ( V_226 , V_243 ) ;
V_22 = F_142 ( V_140 , V_226 , F_129 ( V_86 ) . V_126 , V_237 ) ;
if ( V_22 < 0 )
return V_22 ;
return 0 ;
V_206:
F_148 ( V_226 , V_243 ) ;
V_246:
F_149 ( V_226 ) ;
return - V_89 ;
}
static int
F_152 ( struct V_139 * V_198 , int V_250 , void T_7 * V_251 , int * V_54 )
{
unsigned int * V_252 ;
void * V_253 ;
int V_254 = * V_54 , V_22 = 0 ;
struct V_2 * V_2 = F_130 ( V_198 ) ;
struct V_1 * V_94 = F_1 ( V_2 ) ;
if ( ! F_153 ( V_2 -> V_255 , V_256 ) )
return - V_257 ;
if ( V_250 != V_258 )
return - V_259 ;
if ( * V_54 < sizeof( unsigned int ) )
return - V_25 ;
V_253 = F_154 ( * V_54 ) ;
if ( ! V_253 )
return - V_153 ;
if ( F_155 ( V_253 , V_251 , * V_54 ) != 0 ) {
V_22 = - V_18 ;
goto V_215;
}
V_252 = V_253 ;
if ( * V_252 < V_260 ) {
struct V_261 * V_262 = V_253 ;
if ( * V_54 < sizeof( struct V_261 ) ) {
V_22 = - V_25 ;
goto V_215;
}
if ( V_262 -> V_134 != V_24 ) {
V_22 = - V_263 ;
goto V_215;
}
}
switch ( * V_252 ) {
case V_260 : {
struct V_261 * V_262 = V_253 ;
if ( * V_54 != sizeof( struct V_261 ) ) {
V_22 = - V_25 ;
goto V_215;
}
V_262 -> V_134 = V_24 ;
V_22 = F_156 ( V_251 , V_262 ,
sizeof( struct V_261 ) ) ;
goto V_215;
}
case V_264 : {
struct V_265 * V_266 = V_253 ;
T_6 V_47 ;
if ( * V_54 != sizeof( struct V_265 ) ) {
V_22 = - V_25 ;
goto V_215;
}
V_266 -> V_53 . V_6 [ V_154 - 1 ] = '\0' ;
F_14 ( V_12 ) ;
F_97 ( V_94 , V_266 -> V_53 . V_6 , & V_47 ) ;
V_266 -> V_53 . V_93 = V_47 ;
F_10 ( V_12 ) ;
goto V_267;
}
case V_268 : {
struct V_269 * V_266 = V_253 ;
T_6 V_47 ;
if ( * V_54 != sizeof( struct V_269 ) ) {
V_22 = - V_25 ;
goto V_215;
}
V_266 -> V_53 . V_6 [ V_154 - 1 ] = '\0' ;
F_14 ( V_12 ) ;
F_97 ( V_94 , V_266 -> V_53 . V_6 , & V_47 ) ;
V_266 -> V_53 . V_93 = V_47 ;
if ( V_47 != V_116 )
V_266 -> V_7 = V_52 ( V_94 , V_47 ) -> V_7 ;
F_10 ( V_12 ) ;
goto V_267;
}
case V_270 : {
struct V_265 * V_266 = V_253 ;
struct V_52 * V_53 ;
if ( * V_54 != sizeof( struct V_265 ) ||
V_266 -> V_53 . V_93 >= V_94 -> V_118 ) {
V_22 = - V_25 ;
goto V_215;
}
F_14 ( V_12 ) ;
V_53 = V_52 ( V_94 , V_266 -> V_53 . V_93 ) ;
strncpy ( V_266 -> V_53 . V_6 , V_53 ? V_53 -> V_6 : L_27 ,
V_154 ) ;
F_10 ( V_12 ) ;
goto V_267;
}
default:
V_22 = - V_271 ;
goto V_215;
}
V_267:
V_22 = F_156 ( V_251 , V_253 , V_254 ) ;
V_215:
F_157 ( V_253 ) ;
if ( V_22 > 0 )
V_22 = 0 ;
return V_22 ;
}
static int T_8
F_158 ( struct V_2 * V_2 )
{
struct V_1 * V_94 = F_1 ( V_2 ) ;
struct V_52 * * V_26 ;
V_94 -> V_118 = V_272 ? V_272 : V_273 ;
if ( V_94 -> V_118 >= V_116 )
V_94 -> V_118 = V_116 - 1 ;
V_26 = F_105 ( V_94 -> V_118 , sizeof( struct V_52 * ) , V_31 ) ;
if ( ! V_26 )
return - V_153 ;
V_94 -> V_119 = false ;
V_94 -> V_165 = false ;
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
int V_22 = F_162 ( & V_274 ) ;
if ( V_22 != 0 ) {
F_163 ( L_28 ) ;
return V_22 ;
}
V_22 = F_164 ( & V_275 ) ;
if ( V_22 != 0 ) {
F_163 ( L_29 , V_22 ) ;
F_165 ( & V_274 ) ;
return V_22 ;
}
V_22 = F_166 ( & V_276 ) ;
if ( V_22 ) {
F_163 ( L_30 ) ;
F_167 ( & V_275 ) ;
F_165 ( & V_274 ) ;
return V_22 ;
}
F_168 ( L_31 , V_24 ) ;
return 0 ;
}
static void T_11
F_169 ( void )
{
F_170 ( & V_276 ) ;
F_167 ( & V_275 ) ;
F_165 ( & V_274 ) ;
F_11 ( L_32 ) ;
}
