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
if ( F_35 ( V_38 , V_39 , V_34 , V_41 ) )
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
if ( F_35 ( V_38 , V_39 , V_34 , V_41 ) )
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
F_41 ( struct V_52 * V_53 , struct V_33 * V_38 [] , T_2 V_54 )
{
enum V_46 V_47 ;
T_2 V_55 = V_54 ;
T_4 V_56 = 0 ;
if ( V_38 [ V_57 ] )
V_56 = F_42 ( V_38 [ V_57 ] ) ;
if ( V_56 & V_58 )
V_53 -> V_48 |= V_59 ;
for ( V_47 = 0 ; V_47 < V_60 ; V_47 ++ ) {
if ( ! F_40 ( V_47 , V_56 , V_38 ) )
continue;
V_55 = F_43 ( V_55 , V_49 [ V_47 ] . V_61 ) ;
V_53 -> V_55 [ V_47 ] = V_55 ;
V_53 -> V_62 |= V_49 [ V_47 ] . type ;
V_55 += V_49 [ V_47 ] . V_54 ;
}
return V_55 ;
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
V_64 -> V_80 = V_65 >> 32 ;
V_64 -> V_81 = V_65 & 0xffffffff ;
}
if ( V_38 [ V_69 ] ) {
if ( ! F_53 ( V_53 ) )
return - V_79 ;
V_64 -> V_82 = F_54 ( F_37 (
V_38 [ V_69 ] ) ) ;
}
if ( V_38 [ V_70 ] ) {
if ( ! F_53 ( V_53 ) )
return - V_79 ;
V_64 -> V_83 = F_55 ( F_56 (
V_38 [ V_70 ] ) ) ;
}
return 0 ;
}
int
F_57 ( struct V_84 * V_85 , const struct V_52 * V_53 ,
const void * V_86 , bool V_87 )
{
if ( F_46 ( V_53 ) ) {
unsigned long * V_72 = F_58 ( V_86 , V_53 ) ;
if ( F_59 ( V_85 , V_51 ,
F_60 ( V_87 ? F_61 ( V_72 )
: * V_72 ) ) )
return - V_88 ;
}
if ( F_48 ( V_53 ) &&
F_62 ( V_85 , F_63 ( V_86 , V_53 ) ) )
return - V_88 ;
if ( F_51 ( V_53 ) &&
F_64 ( V_85 , F_65 ( V_86 , V_53 ) ) )
return - V_88 ;
if ( F_53 ( V_53 ) &&
F_66 ( V_85 , F_67 ( V_86 , V_53 ) ) )
return - V_88 ;
return 0 ;
}
static inline void
F_68 ( struct V_52 * V_53 )
{
F_69 ( & V_89 ) ;
V_53 -> V_90 ++ ;
F_70 ( & V_89 ) ;
}
static inline void
F_71 ( struct V_52 * V_53 )
{
F_69 ( & V_89 ) ;
F_72 ( V_53 -> V_90 == 0 ) ;
V_53 -> V_90 -- ;
F_70 ( & V_89 ) ;
}
static inline struct V_52 *
F_73 ( struct V_2 * V_2 , T_6 V_91 )
{
struct V_52 * V_53 ;
struct V_1 * V_92 = F_1 ( V_2 ) ;
F_16 () ;
V_53 = F_74 ( V_92 -> V_93 ) [ V_91 ] ;
F_18 () ;
return V_53 ;
}
int
F_75 ( T_6 V_91 , const struct V_84 * V_85 ,
const struct V_94 * V_95 , struct V_96 * V_97 )
{
struct V_52 * V_53 = F_73 (
F_76 ( V_95 -> V_98 ? V_95 -> V_98 : V_95 -> V_99 ) , V_91 ) ;
int V_22 = 0 ;
F_72 ( ! V_53 ) ;
F_11 ( L_14 , V_53 -> V_6 , V_91 ) ;
if ( V_97 -> V_100 < V_53 -> type -> V_101 ||
! ( V_97 -> V_7 == V_53 -> V_7 || V_53 -> V_7 == V_9 ) )
return 0 ;
F_77 () ;
V_22 = V_53 -> V_102 -> V_103 ( V_53 , V_85 , V_95 , V_104 , V_97 ) ;
F_78 () ;
if ( V_22 == - V_105 ) {
F_11 ( L_15 ) ;
F_79 ( & V_53 -> V_106 ) ;
V_53 -> V_102 -> V_103 ( V_53 , V_85 , V_95 , V_107 , V_97 ) ;
F_80 ( & V_53 -> V_106 ) ;
V_22 = 1 ;
} else {
if ( ( V_97 -> V_108 & V_109 ) &&
( V_53 -> type -> V_110 & V_111 ) &&
( V_22 > 0 || V_22 == - V_112 ) )
V_22 = - V_22 ;
}
return ( V_22 < 0 ? 0 : V_22 ) ;
}
int
F_81 ( T_6 V_91 , const struct V_84 * V_85 ,
const struct V_94 * V_95 , struct V_96 * V_97 )
{
struct V_52 * V_53 = F_73 (
F_76 ( V_95 -> V_98 ? V_95 -> V_98 : V_95 -> V_99 ) , V_91 ) ;
int V_22 ;
F_72 ( ! V_53 ) ;
F_11 ( L_14 , V_53 -> V_6 , V_91 ) ;
if ( V_97 -> V_100 < V_53 -> type -> V_101 ||
! ( V_97 -> V_7 == V_53 -> V_7 || V_53 -> V_7 == V_9 ) )
return - V_113 ;
F_79 ( & V_53 -> V_106 ) ;
V_22 = V_53 -> V_102 -> V_103 ( V_53 , V_85 , V_95 , V_107 , V_97 ) ;
F_80 ( & V_53 -> V_106 ) ;
return V_22 ;
}
int
F_82 ( T_6 V_91 , const struct V_84 * V_85 ,
const struct V_94 * V_95 , struct V_96 * V_97 )
{
struct V_52 * V_53 = F_73 (
F_76 ( V_95 -> V_98 ? V_95 -> V_98 : V_95 -> V_99 ) , V_91 ) ;
int V_22 = 0 ;
F_72 ( ! V_53 ) ;
F_11 ( L_14 , V_53 -> V_6 , V_91 ) ;
if ( V_97 -> V_100 < V_53 -> type -> V_101 ||
! ( V_97 -> V_7 == V_53 -> V_7 || V_53 -> V_7 == V_9 ) )
return - V_113 ;
F_79 ( & V_53 -> V_106 ) ;
V_22 = V_53 -> V_102 -> V_103 ( V_53 , V_85 , V_95 , V_114 , V_97 ) ;
F_80 ( & V_53 -> V_106 ) ;
return V_22 ;
}
T_6
F_83 ( struct V_2 * V_2 , const char * V_6 , struct V_52 * * V_53 )
{
T_6 V_115 , V_91 = V_116 ;
struct V_52 * V_117 ;
struct V_1 * V_92 = F_1 ( V_2 ) ;
F_16 () ;
for ( V_115 = 0 ; V_115 < V_92 -> V_118 ; V_115 ++ ) {
V_117 = F_74 ( V_92 -> V_93 ) [ V_115 ] ;
if ( V_117 && STRNCMP ( V_117 -> V_6 , V_6 ) ) {
F_68 ( V_117 ) ;
V_91 = V_115 ;
* V_53 = V_117 ;
break;
}
}
F_18 () ;
return V_91 ;
}
static inline void
F_84 ( struct V_1 * V_92 , T_6 V_91 )
{
struct V_52 * V_53 ;
F_16 () ;
V_53 = F_74 ( V_92 -> V_93 ) [ V_91 ] ;
if ( V_53 )
F_71 ( V_53 ) ;
F_18 () ;
}
void
F_85 ( struct V_2 * V_2 , T_6 V_91 )
{
struct V_1 * V_92 = F_1 ( V_2 ) ;
F_84 ( V_92 , V_91 ) ;
}
const char *
F_86 ( struct V_2 * V_2 , T_6 V_91 )
{
const struct V_52 * V_53 = F_73 ( V_2 , V_91 ) ;
F_72 ( ! V_53 ) ;
F_72 ( V_53 -> V_90 == 0 ) ;
return V_53 -> V_6 ;
}
T_6
F_87 ( struct V_2 * V_2 , T_6 V_91 )
{
struct V_52 * V_53 ;
struct V_1 * V_92 = F_1 ( V_2 ) ;
if ( V_91 >= V_92 -> V_118 )
return V_116 ;
F_14 ( V_12 ) ;
V_53 = V_52 ( V_92 , V_91 ) ;
if ( V_53 )
F_68 ( V_53 ) ;
else
V_91 = V_116 ;
F_10 ( V_12 ) ;
return V_91 ;
}
void
F_88 ( struct V_2 * V_2 , T_6 V_91 )
{
struct V_52 * V_53 ;
struct V_1 * V_92 = F_1 ( V_2 ) ;
F_14 ( V_12 ) ;
if ( ! V_92 -> V_119 ) {
V_53 = V_52 ( V_92 , V_91 ) ;
if ( V_53 )
F_71 ( V_53 ) ;
}
F_10 ( V_12 ) ;
}
static inline bool
F_89 ( const struct V_33 * const V_38 [] )
{
return ! V_38 [ V_120 ] ||
F_90 ( V_38 [ V_120 ] ) != V_24 ;
}
static inline T_4
F_91 ( const struct V_121 * V_122 )
{
return V_122 -> V_123 & V_124 ? 0 : V_125 ;
}
static struct V_121 *
F_92 ( struct V_84 * V_85 , T_4 V_126 , T_4 V_127 , unsigned int V_48 ,
enum V_128 V_129 )
{
struct V_121 * V_122 ;
struct V_130 * V_131 ;
V_122 = F_93 ( V_85 , V_126 , V_127 , V_129 | ( V_12 << 8 ) ,
sizeof( * V_131 ) , V_48 ) ;
if ( ! V_122 )
return NULL ;
V_131 = F_94 ( V_122 ) ;
V_131 -> V_132 = V_133 ;
V_131 -> V_134 = V_135 ;
V_131 -> V_136 = 0 ;
return V_122 ;
}
static struct V_52 *
F_95 ( struct V_1 * V_92 , const char * V_6 , T_6 * V_47 )
{
struct V_52 * V_53 = NULL ;
T_6 V_115 ;
* V_47 = V_116 ;
for ( V_115 = 0 ; V_115 < V_92 -> V_118 ; V_115 ++ ) {
V_53 = V_52 ( V_92 , V_115 ) ;
if ( V_53 && STRNCMP ( V_53 -> V_6 , V_6 ) ) {
* V_47 = V_115 ;
break;
}
}
return ( * V_47 == V_116 ? NULL : V_53 ) ;
}
static inline struct V_52 *
F_96 ( struct V_1 * V_92 , const char * V_6 )
{
T_6 V_47 ;
return F_95 ( V_92 , V_6 , & V_47 ) ;
}
static int
F_97 ( struct V_1 * V_92 , const char * V_6 , T_6 * V_91 ,
struct V_52 * * V_53 )
{
struct V_52 * V_117 ;
T_6 V_115 ;
* V_91 = V_116 ;
for ( V_115 = 0 ; V_115 < V_92 -> V_118 ; V_115 ++ ) {
V_117 = V_52 ( V_92 , V_115 ) ;
if ( ! V_117 ) {
if ( * V_91 == V_116 )
* V_91 = V_115 ;
} else if ( STRNCMP ( V_6 , V_117 -> V_6 ) ) {
* V_53 = V_117 ;
return - V_137 ;
}
}
if ( * V_91 == V_116 )
return - V_138 ;
return 0 ;
}
static int
F_98 ( struct V_139 * V_140 , struct V_84 * V_85 ,
const struct V_121 * V_122 ,
const struct V_33 * const V_141 [] )
{
return - V_142 ;
}
static int
F_99 ( struct V_139 * V_140 , struct V_84 * V_85 ,
const struct V_121 * V_122 ,
const struct V_33 * const V_141 [] )
{
struct V_2 * V_2 = F_100 ( V_140 ) ;
struct V_1 * V_92 = F_1 ( V_2 ) ;
struct V_52 * V_53 , * V_143 = NULL ;
T_6 V_91 = V_116 ;
struct V_33 * V_38 [ V_144 + 1 ] = {} ;
const char * V_6 , * V_145 ;
T_1 V_7 , V_8 ;
T_4 V_48 = F_91 ( V_122 ) ;
int V_22 = 0 ;
if ( F_34 ( F_89 ( V_141 ) ||
! V_141 [ V_146 ] ||
! V_141 [ V_147 ] ||
! V_141 [ V_148 ] ||
! V_141 [ V_149 ] ||
( V_141 [ V_150 ] &&
! F_32 ( V_141 [ V_150 ] ) ) ) )
return - V_40 ;
V_6 = F_39 ( V_141 [ V_146 ] ) ;
V_145 = F_39 ( V_141 [ V_147 ] ) ;
V_7 = F_90 ( V_141 [ V_149 ] ) ;
V_8 = F_90 ( V_141 [ V_148 ] ) ;
F_11 ( L_16 ,
V_6 , V_145 , F_21 ( V_7 ) , V_8 ) ;
V_53 = F_27 ( sizeof( * V_53 ) , V_31 ) ;
if ( ! V_53 )
return - V_151 ;
F_101 ( & V_53 -> V_106 ) ;
F_102 ( V_53 -> V_6 , V_6 , V_152 ) ;
V_53 -> V_7 = V_7 ;
V_53 -> V_8 = V_8 ;
V_22 = F_103 ( V_145 , V_7 , V_8 , & V_53 -> type ) ;
if ( V_22 )
goto V_99;
if ( V_141 [ V_150 ] &&
F_35 ( V_38 , V_144 , V_141 [ V_150 ] ,
V_53 -> type -> V_153 ) ) {
V_22 = - V_40 ;
goto V_154;
}
V_22 = V_53 -> type -> V_155 ( V_2 , V_53 , V_38 , V_48 ) ;
if ( V_22 != 0 )
goto V_154;
V_22 = F_97 ( V_92 , V_53 -> V_6 , & V_91 , & V_143 ) ;
if ( V_22 == - V_137 ) {
if ( ( V_48 & V_125 ) &&
STRNCMP ( V_53 -> type -> V_6 , V_143 -> type -> V_6 ) &&
V_53 -> type -> V_7 == V_143 -> type -> V_7 &&
V_53 -> type -> V_10 == V_143 -> type -> V_10 &&
V_53 -> type -> V_11 == V_143 -> type -> V_11 &&
V_53 -> V_102 -> V_156 ( V_53 , V_143 ) )
V_22 = 0 ;
goto V_157;
} else if ( V_22 == - V_138 ) {
struct V_52 * * V_26 , * * V_158 ;
T_6 V_115 = V_92 -> V_118 + V_159 ;
if ( V_115 < V_92 -> V_118 || V_115 == V_116 )
goto V_157;
V_26 = F_104 ( V_115 , sizeof( struct V_52 * ) , V_31 ) ;
if ( ! V_26 )
goto V_157;
V_158 = F_105 ( V_92 -> V_93 ) ;
memcpy ( V_26 , V_158 , sizeof( struct V_52 * ) * V_92 -> V_118 ) ;
F_106 ( V_92 -> V_93 , V_26 ) ;
F_107 () ;
V_91 = V_92 -> V_118 ;
V_92 -> V_118 = V_115 ;
F_108 ( V_158 ) ;
V_22 = 0 ;
} else if ( V_22 ) {
goto V_157;
}
F_11 ( L_17 , V_53 -> V_6 , V_91 ) ;
V_52 ( V_92 , V_91 ) = V_53 ;
return V_22 ;
V_157:
V_53 -> V_102 -> V_160 ( V_53 ) ;
V_154:
F_109 ( V_53 -> type -> V_17 ) ;
V_99:
F_108 ( V_53 ) ;
return V_22 ;
}
static void
F_110 ( struct V_52 * V_53 )
{
F_11 ( L_18 , V_53 -> V_6 ) ;
V_53 -> V_102 -> V_160 ( V_53 ) ;
F_109 ( V_53 -> type -> V_17 ) ;
F_108 ( V_53 ) ;
}
static int
F_111 ( struct V_139 * V_140 , struct V_84 * V_85 ,
const struct V_121 * V_122 ,
const struct V_33 * const V_141 [] )
{
struct V_1 * V_92 = F_1 ( F_100 ( V_140 ) ) ;
struct V_52 * V_117 ;
T_6 V_115 ;
int V_22 = 0 ;
if ( F_34 ( F_89 ( V_141 ) ) )
return - V_40 ;
F_112 ( & V_89 ) ;
if ( ! V_141 [ V_146 ] ) {
for ( V_115 = 0 ; V_115 < V_92 -> V_118 ; V_115 ++ ) {
V_117 = V_52 ( V_92 , V_115 ) ;
if ( V_117 && V_117 -> V_90 ) {
V_22 = - V_161 ;
goto V_99;
}
}
V_92 -> V_162 = true ;
F_113 ( & V_89 ) ;
for ( V_115 = 0 ; V_115 < V_92 -> V_118 ; V_115 ++ ) {
V_117 = V_52 ( V_92 , V_115 ) ;
if ( V_117 ) {
V_52 ( V_92 , V_115 ) = NULL ;
F_110 ( V_117 ) ;
}
}
V_92 -> V_162 = false ;
} else {
V_117 = F_95 ( V_92 , F_39 ( V_141 [ V_146 ] ) ,
& V_115 ) ;
if ( ! V_117 ) {
V_22 = - V_163 ;
goto V_99;
} else if ( V_117 -> V_90 ) {
V_22 = - V_161 ;
goto V_99;
}
V_52 ( V_92 , V_115 ) = NULL ;
F_113 ( & V_89 ) ;
F_110 ( V_117 ) ;
}
return 0 ;
V_99:
F_113 ( & V_89 ) ;
return V_22 ;
}
static void
F_114 ( struct V_52 * V_53 )
{
F_11 ( L_18 , V_53 -> V_6 ) ;
F_79 ( & V_53 -> V_106 ) ;
V_53 -> V_102 -> V_164 ( V_53 ) ;
F_80 ( & V_53 -> V_106 ) ;
}
static int
F_115 ( struct V_139 * V_140 , struct V_84 * V_85 ,
const struct V_121 * V_122 ,
const struct V_33 * const V_141 [] )
{
struct V_1 * V_92 = F_1 ( F_100 ( V_140 ) ) ;
struct V_52 * V_117 ;
T_6 V_115 ;
if ( F_34 ( F_89 ( V_141 ) ) )
return - V_40 ;
if ( ! V_141 [ V_146 ] ) {
for ( V_115 = 0 ; V_115 < V_92 -> V_118 ; V_115 ++ ) {
V_117 = V_52 ( V_92 , V_115 ) ;
if ( V_117 )
F_114 ( V_117 ) ;
}
} else {
V_117 = F_96 ( V_92 , F_39 ( V_141 [ V_146 ] ) ) ;
if ( ! V_117 )
return - V_163 ;
F_114 ( V_117 ) ;
}
return 0 ;
}
static int
F_116 ( struct V_139 * V_140 , struct V_84 * V_85 ,
const struct V_121 * V_122 ,
const struct V_33 * const V_141 [] )
{
struct V_1 * V_92 = F_1 ( F_100 ( V_140 ) ) ;
struct V_52 * V_53 , * V_117 ;
const char * V_165 ;
T_6 V_115 ;
int V_22 = 0 ;
if ( F_34 ( F_89 ( V_141 ) ||
! V_141 [ V_146 ] ||
! V_141 [ V_166 ] ) )
return - V_40 ;
V_53 = F_96 ( V_92 , F_39 ( V_141 [ V_146 ] ) ) ;
if ( ! V_53 )
return - V_163 ;
F_112 ( & V_89 ) ;
if ( V_53 -> V_90 != 0 ) {
V_22 = - V_167 ;
goto V_99;
}
V_165 = F_39 ( V_141 [ V_166 ] ) ;
for ( V_115 = 0 ; V_115 < V_92 -> V_118 ; V_115 ++ ) {
V_117 = V_52 ( V_92 , V_115 ) ;
if ( V_117 && STRNCMP ( V_117 -> V_6 , V_165 ) ) {
V_22 = - V_168 ;
goto V_99;
}
}
strncpy ( V_53 -> V_6 , V_165 , V_152 ) ;
V_99:
F_113 ( & V_89 ) ;
return V_22 ;
}
static int
F_117 ( struct V_139 * V_140 , struct V_84 * V_85 ,
const struct V_121 * V_122 ,
const struct V_33 * const V_141 [] )
{
struct V_1 * V_92 = F_1 ( F_100 ( V_140 ) ) ;
struct V_52 * V_169 , * V_170 ;
T_6 V_171 , V_172 ;
char V_173 [ V_152 ] ;
if ( F_34 ( F_89 ( V_141 ) ||
! V_141 [ V_146 ] ||
! V_141 [ V_166 ] ) )
return - V_40 ;
V_169 = F_95 ( V_92 , F_39 ( V_141 [ V_146 ] ) ,
& V_171 ) ;
if ( ! V_169 )
return - V_163 ;
V_170 = F_95 ( V_92 , F_39 ( V_141 [ V_166 ] ) ,
& V_172 ) ;
if ( ! V_170 )
return - V_168 ;
if ( ! ( V_169 -> type -> V_110 == V_170 -> type -> V_110 &&
V_169 -> V_7 == V_170 -> V_7 ) )
return - V_113 ;
strncpy ( V_173 , V_169 -> V_6 , V_152 ) ;
strncpy ( V_169 -> V_6 , V_170 -> V_6 , V_152 ) ;
strncpy ( V_170 -> V_6 , V_173 , V_152 ) ;
F_69 ( & V_89 ) ;
F_118 ( V_169 -> V_90 , V_170 -> V_90 ) ;
V_52 ( V_92 , V_171 ) = V_170 ;
V_52 ( V_92 , V_172 ) = V_169 ;
F_70 ( & V_89 ) ;
return 0 ;
}
static int
F_119 ( struct V_174 * V_175 )
{
if ( V_175 -> args [ V_176 ] ) {
struct V_1 * V_92 =
(struct V_1 * ) V_175 -> args [ V_177 ] ;
T_6 V_91 = ( T_6 ) V_175 -> args [ V_178 ] ;
struct V_52 * V_53 = V_52 ( V_92 , V_91 ) ;
if ( V_53 -> V_102 -> V_179 )
V_53 -> V_102 -> V_179 ( V_53 , V_175 , false ) ;
F_11 ( L_19 , V_53 -> V_6 ) ;
F_84 ( V_92 , V_91 ) ;
}
return 0 ;
}
static inline void
F_120 ( struct V_121 * V_122 )
{
const struct V_33 * V_141 ;
int V_180 ;
F_11 ( L_20 ) ;
F_121 (attr, nlh, sizeof(struct nfgenmsg), rem) {
F_11 ( L_21 , V_35 ( V_141 ) , V_141 -> V_181 ) ;
}
}
static int
F_122 ( struct V_174 * V_175 , struct V_1 * V_92 )
{
struct V_121 * V_122 = F_123 ( V_175 -> V_85 ) ;
int V_182 = F_124 ( sizeof( struct V_130 ) ) ;
struct V_33 * V_183 [ V_184 + 1 ] ;
struct V_33 * V_141 = ( void * ) V_122 + V_182 ;
T_4 V_185 ;
T_6 V_91 ;
F_125 ( V_183 , V_184 ,
V_141 , V_122 -> V_186 - V_182 , V_187 ) ;
if ( V_183 [ V_146 ] ) {
struct V_52 * V_53 ;
V_53 = F_95 ( V_92 , F_39 ( V_183 [ V_146 ] ) ,
& V_91 ) ;
if ( ! V_53 )
return - V_163 ;
V_185 = V_188 ;
V_175 -> args [ V_178 ] = V_91 ;
} else {
V_185 = V_189 ;
}
if ( V_183 [ V_190 ] ) {
T_4 V_191 = F_42 ( V_183 [ V_190 ] ) ;
V_185 |= ( V_191 << 16 ) ;
}
V_175 -> args [ V_177 ] = ( unsigned long ) V_92 ;
V_175 -> args [ V_192 ] = V_185 ;
return 0 ;
}
static int
F_126 ( struct V_84 * V_85 , struct V_174 * V_175 )
{
T_6 V_91 = V_116 , V_21 ;
struct V_52 * V_53 = NULL ;
struct V_121 * V_122 = NULL ;
unsigned int V_48 = F_127 ( V_175 -> V_85 ) . V_126 ? V_193 : 0 ;
struct V_1 * V_92 = F_1 ( F_100 ( V_85 -> V_194 ) ) ;
T_4 V_185 , V_195 ;
bool V_162 ;
int V_22 = 0 ;
if ( ! V_175 -> args [ V_192 ] ) {
V_22 = F_122 ( V_175 , V_92 ) ;
if ( V_22 < 0 ) {
V_122 = F_123 ( V_175 -> V_85 ) ;
if ( V_122 -> V_123 & V_196 )
F_128 ( V_175 -> V_85 , V_122 , V_22 ) ;
return V_22 ;
}
}
if ( V_175 -> args [ V_178 ] >= V_92 -> V_118 )
goto V_99;
V_185 = F_129 ( V_175 -> args [ V_192 ] ) ;
V_195 = F_130 ( V_175 -> args [ V_192 ] ) ;
V_21 = V_185 == V_188 ? V_175 -> args [ V_178 ] + 1
: V_92 -> V_118 ;
V_197:
F_11 ( L_22 ,
V_185 , V_195 , V_175 -> args [ V_178 ] ) ;
for (; V_175 -> args [ V_178 ] < V_21 ; V_175 -> args [ V_178 ] ++ ) {
V_91 = ( T_6 ) V_175 -> args [ V_178 ] ;
F_69 ( & V_89 ) ;
V_53 = V_52 ( V_92 , V_91 ) ;
V_162 = V_92 -> V_162 ;
if ( ! V_53 || V_162 ) {
F_70 ( & V_89 ) ;
if ( V_185 == V_188 ) {
V_22 = - V_163 ;
goto V_99;
}
if ( V_162 ) {
V_22 = 0 ;
goto V_99;
}
continue;
}
if ( V_185 != V_188 &&
( ( V_185 == V_189 ) ==
! ! ( V_53 -> type -> V_110 & V_198 ) ) ) {
F_70 ( & V_89 ) ;
continue;
}
F_11 ( L_23 , V_53 -> V_6 ) ;
if ( ! V_175 -> args [ V_176 ] ) {
F_11 ( L_24 ) ;
V_53 -> V_90 ++ ;
}
F_70 ( & V_89 ) ;
V_122 = F_92 ( V_85 , F_127 ( V_175 -> V_85 ) . V_126 ,
V_175 -> V_122 -> V_199 , V_48 ,
V_200 ) ;
if ( ! V_122 ) {
V_22 = - V_88 ;
goto V_201;
}
if ( F_131 ( V_85 , V_120 , V_24 ) ||
F_132 ( V_85 , V_146 , V_53 -> V_6 ) )
goto V_202;
if ( V_195 & V_203 )
goto V_204;
switch ( V_175 -> args [ V_176 ] ) {
case 0 :
if ( F_132 ( V_85 , V_147 ,
V_53 -> type -> V_6 ) ||
F_131 ( V_85 , V_149 ,
V_53 -> V_7 ) ||
F_131 ( V_85 , V_148 ,
V_53 -> V_8 ) )
goto V_202;
V_22 = V_53 -> V_102 -> V_205 ( V_53 , V_85 ) ;
if ( V_22 < 0 )
goto V_201;
if ( V_195 & V_206 )
goto V_204;
if ( V_53 -> V_102 -> V_179 )
V_53 -> V_102 -> V_179 ( V_53 , V_175 , true ) ;
default:
F_77 () ;
V_22 = V_53 -> V_102 -> V_26 ( V_53 , V_85 , V_175 ) ;
F_78 () ;
if ( ! V_175 -> args [ V_176 ] )
goto V_204;
goto V_201;
}
}
if ( V_185 == V_189 ) {
V_185 = V_207 ;
V_175 -> args [ V_192 ] = V_185 | ( V_195 << 16 ) ;
V_175 -> args [ V_178 ] = 0 ;
if ( V_53 && V_53 -> V_102 -> V_179 )
V_53 -> V_102 -> V_179 ( V_53 , V_175 , false ) ;
goto V_197;
}
goto V_99;
V_202:
V_22 = - V_18 ;
V_204:
if ( V_185 == V_188 )
V_175 -> args [ V_178 ] = V_116 ;
else
V_175 -> args [ V_178 ] ++ ;
V_201:
if ( V_22 || ! V_175 -> args [ V_176 ] ) {
V_53 = V_52 ( V_92 , V_91 ) ;
if ( V_53 -> V_102 -> V_179 )
V_53 -> V_102 -> V_179 ( V_53 , V_175 , false ) ;
F_11 ( L_19 , V_53 -> V_6 ) ;
F_84 ( V_92 , V_91 ) ;
V_175 -> args [ V_176 ] = 0 ;
}
V_99:
if ( V_122 ) {
F_133 ( V_85 , V_122 ) ;
F_11 ( L_25 , V_122 -> V_186 ) ;
F_120 ( V_122 ) ;
}
return V_22 < 0 ? V_22 : V_85 -> V_54 ;
}
static int
F_134 ( struct V_139 * V_140 , struct V_84 * V_85 ,
const struct V_121 * V_122 ,
const struct V_33 * const V_141 [] )
{
if ( F_34 ( F_89 ( V_141 ) ) )
return - V_40 ;
{
struct V_208 V_209 = {
. V_210 = F_126 ,
. V_211 = F_119 ,
} ;
return F_135 ( V_140 , V_85 , V_122 , & V_209 ) ;
}
}
static int
F_136 ( struct V_139 * V_140 , struct V_84 * V_85 , struct V_52 * V_53 ,
struct V_33 * V_38 [] , enum V_212 V_213 ,
T_4 V_48 , bool V_214 )
{
int V_22 ;
T_4 V_215 = 0 ;
bool V_216 = V_48 & V_125 , V_217 = false ;
do {
F_79 ( & V_53 -> V_106 ) ;
V_22 = V_53 -> V_102 -> V_218 ( V_53 , V_38 , V_213 , & V_215 , V_48 , V_217 ) ;
F_80 ( & V_53 -> V_106 ) ;
V_217 = true ;
} while ( V_22 == - V_105 &&
V_53 -> V_102 -> V_219 &&
( V_22 = V_53 -> V_102 -> V_219 ( V_53 , V_217 ) ) == 0 );
if ( ! V_22 || ( V_22 == - V_220 && V_216 ) )
return 0 ;
if ( V_215 && V_214 ) {
struct V_121 * V_221 , * V_122 = F_123 ( V_85 ) ;
struct V_84 * V_222 ;
struct V_223 * V_224 ;
T_2 V_225 = V_20 ( V_226 ,
sizeof( * V_224 ) + V_186 ( V_122 ) ) ;
int V_182 = F_124 ( sizeof( struct V_130 ) ) ;
struct V_33 * V_183 [ V_184 + 1 ] ;
struct V_33 * V_227 ;
T_4 * V_228 ;
V_222 = F_137 ( V_225 , V_31 ) ;
if ( ! V_222 )
return - V_151 ;
V_221 = F_138 ( V_222 , F_127 ( V_85 ) . V_126 ,
V_122 -> V_199 , V_229 , V_225 , 0 ) ;
V_224 = F_94 ( V_221 ) ;
V_224 -> error = V_22 ;
memcpy ( & V_224 -> V_230 , V_122 , V_122 -> V_186 ) ;
V_227 = ( void * ) & V_224 -> V_230 + V_182 ;
F_125 ( V_183 , V_184 ,
V_227 , V_122 -> V_186 - V_182 ,
V_231 ) ;
V_228 = F_39 ( V_183 [ V_232 ] ) ;
* V_228 = V_215 ;
F_139 ( V_140 , V_222 , F_127 ( V_85 ) . V_126 ,
V_233 ) ;
return - V_234 ;
}
return V_22 ;
}
static int
F_140 ( struct V_139 * V_140 , struct V_84 * V_85 ,
const struct V_121 * V_122 ,
const struct V_33 * const V_141 [] )
{
struct V_1 * V_92 = F_1 ( F_100 ( V_140 ) ) ;
struct V_52 * V_53 ;
struct V_33 * V_38 [ V_235 + 1 ] = {} ;
const struct V_33 * V_34 ;
T_4 V_48 = F_91 ( V_122 ) ;
bool V_214 ;
int V_22 = 0 ;
if ( F_34 ( F_89 ( V_141 ) ||
! V_141 [ V_146 ] ||
! ( ( V_141 [ V_150 ] != NULL ) ^
( V_141 [ V_236 ] != NULL ) ) ||
( V_141 [ V_150 ] &&
! F_32 ( V_141 [ V_150 ] ) ) ||
( V_141 [ V_236 ] &&
( ! F_32 ( V_141 [ V_236 ] ) ||
! V_141 [ V_232 ] ) ) ) )
return - V_40 ;
V_53 = F_96 ( V_92 , F_39 ( V_141 [ V_146 ] ) ) ;
if ( ! V_53 )
return - V_163 ;
V_214 = ! ! V_141 [ V_232 ] ;
if ( V_141 [ V_150 ] ) {
if ( F_35 ( V_38 , V_235 ,
V_141 [ V_150 ] ,
V_53 -> type -> V_237 ) )
return - V_40 ;
V_22 = F_136 ( V_140 , V_85 , V_53 , V_38 , V_107 , V_48 ,
V_214 ) ;
} else {
int V_238 ;
F_141 (nla, attr[IPSET_ATTR_ADT], nla_rem) {
memset ( V_38 , 0 , sizeof( V_38 ) ) ;
if ( V_35 ( V_34 ) != V_150 ||
! F_32 ( V_34 ) ||
F_35 ( V_38 , V_235 , V_34 ,
V_53 -> type -> V_237 ) )
return - V_40 ;
V_22 = F_136 ( V_140 , V_85 , V_53 , V_38 , V_107 ,
V_48 , V_214 ) ;
if ( V_22 < 0 )
return V_22 ;
}
}
return V_22 ;
}
static int
F_142 ( struct V_139 * V_140 , struct V_84 * V_85 ,
const struct V_121 * V_122 ,
const struct V_33 * const V_141 [] )
{
struct V_1 * V_92 = F_1 ( F_100 ( V_140 ) ) ;
struct V_52 * V_53 ;
struct V_33 * V_38 [ V_235 + 1 ] = {} ;
const struct V_33 * V_34 ;
T_4 V_48 = F_91 ( V_122 ) ;
bool V_214 ;
int V_22 = 0 ;
if ( F_34 ( F_89 ( V_141 ) ||
! V_141 [ V_146 ] ||
! ( ( V_141 [ V_150 ] != NULL ) ^
( V_141 [ V_236 ] != NULL ) ) ||
( V_141 [ V_150 ] &&
! F_32 ( V_141 [ V_150 ] ) ) ||
( V_141 [ V_236 ] &&
( ! F_32 ( V_141 [ V_236 ] ) ||
! V_141 [ V_232 ] ) ) ) )
return - V_40 ;
V_53 = F_96 ( V_92 , F_39 ( V_141 [ V_146 ] ) ) ;
if ( ! V_53 )
return - V_163 ;
V_214 = ! ! V_141 [ V_232 ] ;
if ( V_141 [ V_150 ] ) {
if ( F_35 ( V_38 , V_235 ,
V_141 [ V_150 ] ,
V_53 -> type -> V_237 ) )
return - V_40 ;
V_22 = F_136 ( V_140 , V_85 , V_53 , V_38 , V_114 , V_48 ,
V_214 ) ;
} else {
int V_238 ;
F_141 (nla, attr[IPSET_ATTR_ADT], nla_rem) {
memset ( V_38 , 0 , sizeof( * V_38 ) ) ;
if ( V_35 ( V_34 ) != V_150 ||
! F_32 ( V_34 ) ||
F_35 ( V_38 , V_235 , V_34 ,
V_53 -> type -> V_237 ) )
return - V_40 ;
V_22 = F_136 ( V_140 , V_85 , V_53 , V_38 , V_114 ,
V_48 , V_214 ) ;
if ( V_22 < 0 )
return V_22 ;
}
}
return V_22 ;
}
static int
F_143 ( struct V_139 * V_140 , struct V_84 * V_85 ,
const struct V_121 * V_122 ,
const struct V_33 * const V_141 [] )
{
struct V_1 * V_92 = F_1 ( F_100 ( V_140 ) ) ;
struct V_52 * V_53 ;
struct V_33 * V_38 [ V_235 + 1 ] = {} ;
int V_22 = 0 ;
if ( F_34 ( F_89 ( V_141 ) ||
! V_141 [ V_146 ] ||
! V_141 [ V_150 ] ||
! F_32 ( V_141 [ V_150 ] ) ) )
return - V_40 ;
V_53 = F_96 ( V_92 , F_39 ( V_141 [ V_146 ] ) ) ;
if ( ! V_53 )
return - V_163 ;
if ( F_35 ( V_38 , V_235 , V_141 [ V_150 ] ,
V_53 -> type -> V_237 ) )
return - V_40 ;
F_77 () ;
V_22 = V_53 -> V_102 -> V_218 ( V_53 , V_38 , V_104 , NULL , 0 , 0 ) ;
F_78 () ;
if ( V_22 == - V_105 )
V_22 = 1 ;
return V_22 > 0 ? 0 : - V_220 ;
}
static int
F_144 ( struct V_139 * V_140 , struct V_84 * V_85 ,
const struct V_121 * V_122 ,
const struct V_33 * const V_141 [] )
{
struct V_1 * V_92 = F_1 ( F_100 ( V_140 ) ) ;
const struct V_52 * V_53 ;
struct V_84 * V_222 ;
struct V_121 * V_239 ;
int V_22 = 0 ;
if ( F_34 ( F_89 ( V_141 ) ||
! V_141 [ V_146 ] ) )
return - V_40 ;
V_53 = F_96 ( V_92 , F_39 ( V_141 [ V_146 ] ) ) ;
if ( ! V_53 )
return - V_163 ;
V_222 = F_137 ( V_240 , V_31 ) ;
if ( ! V_222 )
return - V_151 ;
V_239 = F_92 ( V_222 , F_127 ( V_85 ) . V_126 , V_122 -> V_199 , 0 ,
V_241 ) ;
if ( ! V_239 )
goto V_242;
if ( F_131 ( V_222 , V_120 , V_24 ) ||
F_132 ( V_222 , V_146 , V_53 -> V_6 ) ||
F_132 ( V_222 , V_147 , V_53 -> type -> V_6 ) ||
F_131 ( V_222 , V_149 , V_53 -> V_7 ) ||
F_131 ( V_222 , V_148 , V_53 -> V_8 ) )
goto V_202;
F_133 ( V_222 , V_239 ) ;
V_22 = F_139 ( V_140 , V_222 , F_127 ( V_85 ) . V_126 , V_233 ) ;
if ( V_22 < 0 )
return V_22 ;
return 0 ;
V_202:
F_145 ( V_222 , V_239 ) ;
V_242:
F_146 ( V_222 ) ;
return - V_88 ;
}
static int
V_5 ( struct V_139 * V_140 , struct V_84 * V_85 ,
const struct V_121 * V_122 ,
const struct V_33 * const V_141 [] )
{
struct V_84 * V_222 ;
struct V_121 * V_239 ;
T_1 V_7 , V_20 , V_21 ;
const char * V_145 ;
int V_22 = 0 ;
if ( F_34 ( F_89 ( V_141 ) ||
! V_141 [ V_147 ] ||
! V_141 [ V_149 ] ) )
return - V_40 ;
V_7 = F_90 ( V_141 [ V_149 ] ) ;
V_145 = F_39 ( V_141 [ V_147 ] ) ;
V_22 = F_147 ( V_145 , V_7 , & V_20 , & V_21 ) ;
if ( V_22 )
return V_22 ;
V_222 = F_137 ( V_240 , V_31 ) ;
if ( ! V_222 )
return - V_151 ;
V_239 = F_92 ( V_222 , F_127 ( V_85 ) . V_126 , V_122 -> V_199 , 0 ,
V_243 ) ;
if ( ! V_239 )
goto V_242;
if ( F_131 ( V_222 , V_120 , V_24 ) ||
F_132 ( V_222 , V_147 , V_145 ) ||
F_131 ( V_222 , V_149 , V_7 ) ||
F_131 ( V_222 , V_148 , V_21 ) ||
F_131 ( V_222 , V_244 , V_20 ) )
goto V_202;
F_133 ( V_222 , V_239 ) ;
F_11 ( L_26 , V_239 -> V_186 ) ;
V_22 = F_139 ( V_140 , V_222 , F_127 ( V_85 ) . V_126 , V_233 ) ;
if ( V_22 < 0 )
return V_22 ;
return 0 ;
V_202:
F_145 ( V_222 , V_239 ) ;
V_242:
F_146 ( V_222 ) ;
return - V_88 ;
}
static int
F_148 ( struct V_139 * V_140 , struct V_84 * V_85 ,
const struct V_121 * V_122 ,
const struct V_33 * const V_141 [] )
{
struct V_84 * V_222 ;
struct V_121 * V_239 ;
int V_22 = 0 ;
if ( F_34 ( ! V_141 [ V_120 ] ) )
return - V_40 ;
V_222 = F_137 ( V_240 , V_31 ) ;
if ( ! V_222 )
return - V_151 ;
V_239 = F_92 ( V_222 , F_127 ( V_85 ) . V_126 , V_122 -> V_199 , 0 ,
V_245 ) ;
if ( ! V_239 )
goto V_242;
if ( F_131 ( V_222 , V_120 , V_24 ) )
goto V_202;
F_133 ( V_222 , V_239 ) ;
V_22 = F_139 ( V_140 , V_222 , F_127 ( V_85 ) . V_126 , V_233 ) ;
if ( V_22 < 0 )
return V_22 ;
return 0 ;
V_202:
F_145 ( V_222 , V_239 ) ;
V_242:
F_146 ( V_222 ) ;
return - V_88 ;
}
static int
F_149 ( struct V_139 * V_194 , int V_246 , void T_7 * V_247 , int * V_54 )
{
unsigned int * V_248 ;
void * V_249 ;
int V_250 = * V_54 , V_22 = 0 ;
struct V_2 * V_2 = F_100 ( V_194 ) ;
struct V_1 * V_92 = F_1 ( V_2 ) ;
if ( ! F_150 ( V_2 -> V_251 , V_252 ) )
return - V_253 ;
if ( V_246 != V_254 )
return - V_255 ;
if ( * V_54 < sizeof( unsigned int ) )
return - V_25 ;
V_249 = F_151 ( * V_54 ) ;
if ( ! V_249 )
return - V_151 ;
if ( F_152 ( V_249 , V_247 , * V_54 ) != 0 ) {
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
if ( V_258 -> V_134 != V_24 ) {
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
V_258 -> V_134 = V_24 ;
V_22 = F_153 ( V_247 , V_258 ,
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
V_262 -> V_53 . V_6 [ V_152 - 1 ] = '\0' ;
F_14 ( V_12 ) ;
F_95 ( V_92 , V_262 -> V_53 . V_6 , & V_47 ) ;
V_262 -> V_53 . V_91 = V_47 ;
F_10 ( V_12 ) ;
goto V_263;
}
case V_264 : {
struct V_265 * V_262 = V_249 ;
T_6 V_47 ;
if ( * V_54 != sizeof( struct V_265 ) ) {
V_22 = - V_25 ;
goto V_211;
}
V_262 -> V_53 . V_6 [ V_152 - 1 ] = '\0' ;
F_14 ( V_12 ) ;
F_95 ( V_92 , V_262 -> V_53 . V_6 , & V_47 ) ;
V_262 -> V_53 . V_91 = V_47 ;
if ( V_47 != V_116 )
V_262 -> V_7 = V_52 ( V_92 , V_47 ) -> V_7 ;
F_10 ( V_12 ) ;
goto V_263;
}
case V_266 : {
struct V_261 * V_262 = V_249 ;
struct V_52 * V_53 ;
if ( * V_54 != sizeof( struct V_261 ) ||
V_262 -> V_53 . V_91 >= V_92 -> V_118 ) {
V_22 = - V_25 ;
goto V_211;
}
F_14 ( V_12 ) ;
V_53 = V_52 ( V_92 , V_262 -> V_53 . V_91 ) ;
strncpy ( V_262 -> V_53 . V_6 , V_53 ? V_53 -> V_6 : L_27 ,
V_152 ) ;
F_10 ( V_12 ) ;
goto V_263;
}
default:
V_22 = - V_267 ;
goto V_211;
}
V_263:
V_22 = F_153 ( V_247 , V_249 , V_250 ) ;
V_211:
F_154 ( V_249 ) ;
if ( V_22 > 0 )
V_22 = 0 ;
return V_22 ;
}
static int T_8
F_155 ( struct V_2 * V_2 )
{
struct V_1 * V_92 = F_1 ( V_2 ) ;
struct V_52 * * V_26 ;
V_92 -> V_118 = V_268 ? V_268 : V_269 ;
if ( V_92 -> V_118 >= V_116 )
V_92 -> V_118 = V_116 - 1 ;
V_26 = F_104 ( V_92 -> V_118 , sizeof( struct V_52 * ) , V_31 ) ;
if ( ! V_26 )
return - V_151 ;
V_92 -> V_119 = false ;
V_92 -> V_162 = false ;
F_106 ( V_92 -> V_93 , V_26 ) ;
return 0 ;
}
static void T_9
F_156 ( struct V_2 * V_2 )
{
struct V_1 * V_92 = F_1 ( V_2 ) ;
struct V_52 * V_53 = NULL ;
T_6 V_115 ;
V_92 -> V_119 = true ;
for ( V_115 = 0 ; V_115 < V_92 -> V_118 ; V_115 ++ ) {
V_53 = V_52 ( V_92 , V_115 ) ;
if ( V_53 ) {
V_52 ( V_92 , V_115 ) = NULL ;
F_110 ( V_53 ) ;
}
}
F_108 ( F_157 ( V_92 -> V_93 , 1 ) ) ;
}
static int T_10
F_158 ( void )
{
int V_22 = F_159 ( & V_270 ) ;
if ( V_22 != 0 ) {
F_160 ( L_28 ) ;
return V_22 ;
}
V_22 = F_161 ( & V_271 ) ;
if ( V_22 != 0 ) {
F_160 ( L_29 , V_22 ) ;
F_162 ( & V_270 ) ;
return V_22 ;
}
V_22 = F_163 ( & V_272 ) ;
if ( V_22 ) {
F_160 ( L_30 ) ;
F_164 ( & V_271 ) ;
F_162 ( & V_270 ) ;
return V_22 ;
}
F_165 ( L_31 , V_24 ) ;
return 0 ;
}
static void T_11
F_166 ( void )
{
F_167 ( & V_272 ) ;
F_164 ( & V_271 ) ;
F_162 ( & V_270 ) ;
F_11 ( L_32 ) ;
}
