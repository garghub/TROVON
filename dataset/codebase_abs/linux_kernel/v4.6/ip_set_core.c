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
static inline void
F_73 ( struct V_52 * V_53 )
{
F_69 ( & V_89 ) ;
V_53 -> V_91 ++ ;
F_70 ( & V_89 ) ;
}
static inline void
F_74 ( struct V_52 * V_53 )
{
F_69 ( & V_89 ) ;
F_72 ( V_53 -> V_91 == 0 ) ;
V_53 -> V_91 -- ;
F_70 ( & V_89 ) ;
}
static inline struct V_52 *
F_75 ( struct V_2 * V_2 , T_6 V_92 )
{
struct V_52 * V_53 ;
struct V_1 * V_93 = F_1 ( V_2 ) ;
F_16 () ;
V_53 = F_76 ( V_93 -> V_94 ) [ V_92 ] ;
F_18 () ;
return V_53 ;
}
int
F_77 ( T_6 V_92 , const struct V_84 * V_85 ,
const struct V_95 * V_96 , struct V_97 * V_98 )
{
struct V_52 * V_53 = F_75 ( V_96 -> V_2 , V_92 ) ;
int V_22 = 0 ;
F_72 ( ! V_53 ) ;
F_11 ( L_14 , V_53 -> V_6 , V_92 ) ;
if ( V_98 -> V_99 < V_53 -> type -> V_100 ||
! ( V_98 -> V_7 == V_53 -> V_7 || V_53 -> V_7 == V_9 ) )
return 0 ;
F_78 () ;
V_22 = V_53 -> V_101 -> V_102 ( V_53 , V_85 , V_96 , V_103 , V_98 ) ;
F_79 () ;
if ( V_22 == - V_104 ) {
F_11 ( L_15 ) ;
F_80 ( & V_53 -> V_105 ) ;
V_53 -> V_101 -> V_102 ( V_53 , V_85 , V_96 , V_106 , V_98 ) ;
F_81 ( & V_53 -> V_105 ) ;
V_22 = 1 ;
} else {
if ( ( V_98 -> V_107 & V_108 ) &&
( V_53 -> type -> V_109 & V_110 ) &&
( V_22 > 0 || V_22 == - V_111 ) )
V_22 = - V_22 ;
}
return ( V_22 < 0 ? 0 : V_22 ) ;
}
int
F_82 ( T_6 V_92 , const struct V_84 * V_85 ,
const struct V_95 * V_96 , struct V_97 * V_98 )
{
struct V_52 * V_53 = F_75 ( V_96 -> V_2 , V_92 ) ;
int V_22 ;
F_72 ( ! V_53 ) ;
F_11 ( L_14 , V_53 -> V_6 , V_92 ) ;
if ( V_98 -> V_99 < V_53 -> type -> V_100 ||
! ( V_98 -> V_7 == V_53 -> V_7 || V_53 -> V_7 == V_9 ) )
return - V_112 ;
F_80 ( & V_53 -> V_105 ) ;
V_22 = V_53 -> V_101 -> V_102 ( V_53 , V_85 , V_96 , V_106 , V_98 ) ;
F_81 ( & V_53 -> V_105 ) ;
return V_22 ;
}
int
F_83 ( T_6 V_92 , const struct V_84 * V_85 ,
const struct V_95 * V_96 , struct V_97 * V_98 )
{
struct V_52 * V_53 = F_75 ( V_96 -> V_2 , V_92 ) ;
int V_22 = 0 ;
F_72 ( ! V_53 ) ;
F_11 ( L_14 , V_53 -> V_6 , V_92 ) ;
if ( V_98 -> V_99 < V_53 -> type -> V_100 ||
! ( V_98 -> V_7 == V_53 -> V_7 || V_53 -> V_7 == V_9 ) )
return - V_112 ;
F_80 ( & V_53 -> V_105 ) ;
V_22 = V_53 -> V_101 -> V_102 ( V_53 , V_85 , V_96 , V_113 , V_98 ) ;
F_81 ( & V_53 -> V_105 ) ;
return V_22 ;
}
T_6
F_84 ( struct V_2 * V_2 , const char * V_6 , struct V_52 * * V_53 )
{
T_6 V_114 , V_92 = V_115 ;
struct V_52 * V_116 ;
struct V_1 * V_93 = F_1 ( V_2 ) ;
F_16 () ;
for ( V_114 = 0 ; V_114 < V_93 -> V_117 ; V_114 ++ ) {
V_116 = F_76 ( V_93 -> V_94 ) [ V_114 ] ;
if ( V_116 && STRNCMP ( V_116 -> V_6 , V_6 ) ) {
F_68 ( V_116 ) ;
V_92 = V_114 ;
* V_53 = V_116 ;
break;
}
}
F_18 () ;
return V_92 ;
}
static inline void
F_85 ( struct V_1 * V_93 , T_6 V_92 )
{
struct V_52 * V_53 ;
F_16 () ;
V_53 = F_76 ( V_93 -> V_94 ) [ V_92 ] ;
if ( V_53 )
F_71 ( V_53 ) ;
F_18 () ;
}
void
F_86 ( struct V_2 * V_2 , T_6 V_92 )
{
struct V_1 * V_93 = F_1 ( V_2 ) ;
F_85 ( V_93 , V_92 ) ;
}
const char *
F_87 ( struct V_2 * V_2 , T_6 V_92 )
{
const struct V_52 * V_53 = F_75 ( V_2 , V_92 ) ;
F_72 ( ! V_53 ) ;
F_72 ( V_53 -> V_90 == 0 ) ;
return V_53 -> V_6 ;
}
T_6
F_88 ( struct V_2 * V_2 , T_6 V_92 )
{
struct V_52 * V_53 ;
struct V_1 * V_93 = F_1 ( V_2 ) ;
if ( V_92 >= V_93 -> V_117 )
return V_115 ;
F_14 ( V_12 ) ;
V_53 = V_52 ( V_93 , V_92 ) ;
if ( V_53 )
F_68 ( V_53 ) ;
else
V_92 = V_115 ;
F_10 ( V_12 ) ;
return V_92 ;
}
void
F_89 ( struct V_2 * V_2 , T_6 V_92 )
{
struct V_52 * V_53 ;
struct V_1 * V_93 = F_1 ( V_2 ) ;
F_14 ( V_12 ) ;
if ( ! V_93 -> V_118 ) {
V_53 = V_52 ( V_93 , V_92 ) ;
if ( V_53 )
F_71 ( V_53 ) ;
}
F_10 ( V_12 ) ;
}
static inline bool
F_90 ( const struct V_33 * const V_38 [] )
{
return ! V_38 [ V_119 ] ||
F_91 ( V_38 [ V_119 ] ) != V_24 ;
}
static inline T_4
F_92 ( const struct V_120 * V_121 )
{
return V_121 -> V_122 & V_123 ? 0 : V_124 ;
}
static struct V_120 *
F_93 ( struct V_84 * V_85 , T_4 V_125 , T_4 V_126 , unsigned int V_48 ,
enum V_127 V_128 )
{
struct V_120 * V_121 ;
struct V_129 * V_130 ;
V_121 = F_94 ( V_85 , V_125 , V_126 , V_128 | ( V_12 << 8 ) ,
sizeof( * V_130 ) , V_48 ) ;
if ( ! V_121 )
return NULL ;
V_130 = F_95 ( V_121 ) ;
V_130 -> V_131 = V_132 ;
V_130 -> V_133 = V_134 ;
V_130 -> V_135 = 0 ;
return V_121 ;
}
static struct V_52 *
F_96 ( struct V_1 * V_93 , const char * V_6 , T_6 * V_47 )
{
struct V_52 * V_53 = NULL ;
T_6 V_114 ;
* V_47 = V_115 ;
for ( V_114 = 0 ; V_114 < V_93 -> V_117 ; V_114 ++ ) {
V_53 = V_52 ( V_93 , V_114 ) ;
if ( V_53 && STRNCMP ( V_53 -> V_6 , V_6 ) ) {
* V_47 = V_114 ;
break;
}
}
return ( * V_47 == V_115 ? NULL : V_53 ) ;
}
static inline struct V_52 *
F_97 ( struct V_1 * V_93 , const char * V_6 )
{
T_6 V_47 ;
return F_96 ( V_93 , V_6 , & V_47 ) ;
}
static int
F_98 ( struct V_1 * V_93 , const char * V_6 , T_6 * V_92 ,
struct V_52 * * V_53 )
{
struct V_52 * V_116 ;
T_6 V_114 ;
* V_92 = V_115 ;
for ( V_114 = 0 ; V_114 < V_93 -> V_117 ; V_114 ++ ) {
V_116 = V_52 ( V_93 , V_114 ) ;
if ( ! V_116 ) {
if ( * V_92 == V_115 )
* V_92 = V_114 ;
} else if ( STRNCMP ( V_6 , V_116 -> V_6 ) ) {
* V_53 = V_116 ;
return - V_136 ;
}
}
if ( * V_92 == V_115 )
return - V_137 ;
return 0 ;
}
static int F_99 ( struct V_2 * V_2 , struct V_138 * V_139 , struct V_84 * V_85 ,
const struct V_120 * V_121 ,
const struct V_33 * const V_140 [] )
{
return - V_141 ;
}
static int F_100 ( struct V_2 * V_2 , struct V_138 * V_139 ,
struct V_84 * V_85 , const struct V_120 * V_121 ,
const struct V_33 * const V_140 [] )
{
struct V_1 * V_93 = F_1 ( V_2 ) ;
struct V_52 * V_53 , * V_142 = NULL ;
T_6 V_92 = V_115 ;
struct V_33 * V_38 [ V_143 + 1 ] = {} ;
const char * V_6 , * V_144 ;
T_1 V_7 , V_8 ;
T_4 V_48 = F_92 ( V_121 ) ;
int V_22 = 0 ;
if ( F_34 ( F_90 ( V_140 ) ||
! V_140 [ V_145 ] ||
! V_140 [ V_146 ] ||
! V_140 [ V_147 ] ||
! V_140 [ V_148 ] ||
( V_140 [ V_149 ] &&
! F_32 ( V_140 [ V_149 ] ) ) ) )
return - V_40 ;
V_6 = F_39 ( V_140 [ V_145 ] ) ;
V_144 = F_39 ( V_140 [ V_146 ] ) ;
V_7 = F_91 ( V_140 [ V_148 ] ) ;
V_8 = F_91 ( V_140 [ V_147 ] ) ;
F_11 ( L_16 ,
V_6 , V_144 , F_21 ( V_7 ) , V_8 ) ;
V_53 = F_27 ( sizeof( * V_53 ) , V_31 ) ;
if ( ! V_53 )
return - V_150 ;
F_101 ( & V_53 -> V_105 ) ;
F_102 ( V_53 -> V_6 , V_6 , V_151 ) ;
V_53 -> V_7 = V_7 ;
V_53 -> V_8 = V_8 ;
V_22 = F_103 ( V_144 , V_7 , V_8 , & V_53 -> type ) ;
if ( V_22 )
goto V_152;
if ( V_140 [ V_149 ] &&
F_35 ( V_38 , V_143 , V_140 [ V_149 ] ,
V_53 -> type -> V_153 ) ) {
V_22 = - V_40 ;
goto V_154;
}
V_22 = V_53 -> type -> V_155 ( V_2 , V_53 , V_38 , V_48 ) ;
if ( V_22 != 0 )
goto V_154;
V_22 = F_98 ( V_93 , V_53 -> V_6 , & V_92 , & V_142 ) ;
if ( V_22 == - V_136 ) {
if ( ( V_48 & V_124 ) &&
STRNCMP ( V_53 -> type -> V_6 , V_142 -> type -> V_6 ) &&
V_53 -> type -> V_7 == V_142 -> type -> V_7 &&
V_53 -> type -> V_10 == V_142 -> type -> V_10 &&
V_53 -> type -> V_11 == V_142 -> type -> V_11 &&
V_53 -> V_101 -> V_156 ( V_53 , V_142 ) )
V_22 = 0 ;
goto V_157;
} else if ( V_22 == - V_137 ) {
struct V_52 * * V_26 , * * V_158 ;
T_6 V_114 = V_93 -> V_117 + V_159 ;
if ( V_114 < V_93 -> V_117 || V_114 == V_115 )
goto V_157;
V_26 = F_104 ( V_114 , sizeof( struct V_52 * ) , V_31 ) ;
if ( ! V_26 )
goto V_157;
V_158 = F_105 ( V_93 -> V_94 ) ;
memcpy ( V_26 , V_158 , sizeof( struct V_52 * ) * V_93 -> V_117 ) ;
F_106 ( V_93 -> V_94 , V_26 ) ;
F_107 () ;
V_92 = V_93 -> V_117 ;
V_93 -> V_117 = V_114 ;
F_108 ( V_158 ) ;
V_22 = 0 ;
} else if ( V_22 ) {
goto V_157;
}
F_11 ( L_17 , V_53 -> V_6 , V_92 ) ;
V_52 ( V_93 , V_92 ) = V_53 ;
return V_22 ;
V_157:
V_53 -> V_101 -> V_160 ( V_53 ) ;
V_154:
F_109 ( V_53 -> type -> V_17 ) ;
V_152:
F_108 ( V_53 ) ;
return V_22 ;
}
static void
F_110 ( struct V_52 * V_53 )
{
F_11 ( L_18 , V_53 -> V_6 ) ;
V_53 -> V_101 -> V_160 ( V_53 ) ;
F_109 ( V_53 -> type -> V_17 ) ;
F_108 ( V_53 ) ;
}
static int F_111 ( struct V_2 * V_2 , struct V_138 * V_139 ,
struct V_84 * V_85 , const struct V_120 * V_121 ,
const struct V_33 * const V_140 [] )
{
struct V_1 * V_93 = F_1 ( V_2 ) ;
struct V_52 * V_116 ;
T_6 V_114 ;
int V_22 = 0 ;
if ( F_34 ( F_90 ( V_140 ) ) )
return - V_40 ;
F_112 () ;
F_113 ( & V_89 ) ;
if ( ! V_140 [ V_145 ] ) {
for ( V_114 = 0 ; V_114 < V_93 -> V_117 ; V_114 ++ ) {
V_116 = V_52 ( V_93 , V_114 ) ;
if ( V_116 && ( V_116 -> V_90 || V_116 -> V_91 ) ) {
V_22 = - V_161 ;
goto V_152;
}
}
V_93 -> V_162 = true ;
F_114 ( & V_89 ) ;
for ( V_114 = 0 ; V_114 < V_93 -> V_117 ; V_114 ++ ) {
V_116 = V_52 ( V_93 , V_114 ) ;
if ( V_116 ) {
V_52 ( V_93 , V_114 ) = NULL ;
F_110 ( V_116 ) ;
}
}
V_93 -> V_162 = false ;
} else {
V_116 = F_96 ( V_93 , F_39 ( V_140 [ V_145 ] ) ,
& V_114 ) ;
if ( ! V_116 ) {
V_22 = - V_163 ;
goto V_152;
} else if ( V_116 -> V_90 || V_116 -> V_91 ) {
V_22 = - V_161 ;
goto V_152;
}
V_52 ( V_93 , V_114 ) = NULL ;
F_114 ( & V_89 ) ;
F_110 ( V_116 ) ;
}
return 0 ;
V_152:
F_114 ( & V_89 ) ;
return V_22 ;
}
static void
F_115 ( struct V_52 * V_53 )
{
F_11 ( L_18 , V_53 -> V_6 ) ;
F_80 ( & V_53 -> V_105 ) ;
V_53 -> V_101 -> V_164 ( V_53 ) ;
F_81 ( & V_53 -> V_105 ) ;
}
static int F_116 ( struct V_2 * V_2 , struct V_138 * V_139 , struct V_84 * V_85 ,
const struct V_120 * V_121 ,
const struct V_33 * const V_140 [] )
{
struct V_1 * V_93 = F_1 ( V_2 ) ;
struct V_52 * V_116 ;
T_6 V_114 ;
if ( F_34 ( F_90 ( V_140 ) ) )
return - V_40 ;
if ( ! V_140 [ V_145 ] ) {
for ( V_114 = 0 ; V_114 < V_93 -> V_117 ; V_114 ++ ) {
V_116 = V_52 ( V_93 , V_114 ) ;
if ( V_116 )
F_115 ( V_116 ) ;
}
} else {
V_116 = F_97 ( V_93 , F_39 ( V_140 [ V_145 ] ) ) ;
if ( ! V_116 )
return - V_163 ;
F_115 ( V_116 ) ;
}
return 0 ;
}
static int F_117 ( struct V_2 * V_2 , struct V_138 * V_139 ,
struct V_84 * V_85 , const struct V_120 * V_121 ,
const struct V_33 * const V_140 [] )
{
struct V_1 * V_93 = F_1 ( V_2 ) ;
struct V_52 * V_53 , * V_116 ;
const char * V_165 ;
T_6 V_114 ;
int V_22 = 0 ;
if ( F_34 ( F_90 ( V_140 ) ||
! V_140 [ V_145 ] ||
! V_140 [ V_166 ] ) )
return - V_40 ;
V_53 = F_97 ( V_93 , F_39 ( V_140 [ V_145 ] ) ) ;
if ( ! V_53 )
return - V_163 ;
F_113 ( & V_89 ) ;
if ( V_53 -> V_90 != 0 ) {
V_22 = - V_167 ;
goto V_152;
}
V_165 = F_39 ( V_140 [ V_166 ] ) ;
for ( V_114 = 0 ; V_114 < V_93 -> V_117 ; V_114 ++ ) {
V_116 = V_52 ( V_93 , V_114 ) ;
if ( V_116 && STRNCMP ( V_116 -> V_6 , V_165 ) ) {
V_22 = - V_168 ;
goto V_152;
}
}
strncpy ( V_53 -> V_6 , V_165 , V_151 ) ;
V_152:
F_114 ( & V_89 ) ;
return V_22 ;
}
static int F_118 ( struct V_2 * V_2 , struct V_138 * V_139 , struct V_84 * V_85 ,
const struct V_120 * V_121 ,
const struct V_33 * const V_140 [] )
{
struct V_1 * V_93 = F_1 ( V_2 ) ;
struct V_52 * V_169 , * V_170 ;
T_6 V_171 , V_172 ;
char V_173 [ V_151 ] ;
if ( F_34 ( F_90 ( V_140 ) ||
! V_140 [ V_145 ] ||
! V_140 [ V_166 ] ) )
return - V_40 ;
V_169 = F_96 ( V_93 , F_39 ( V_140 [ V_145 ] ) ,
& V_171 ) ;
if ( ! V_169 )
return - V_163 ;
V_170 = F_96 ( V_93 , F_39 ( V_140 [ V_166 ] ) ,
& V_172 ) ;
if ( ! V_170 )
return - V_168 ;
if ( ! ( V_169 -> type -> V_109 == V_170 -> type -> V_109 &&
V_169 -> V_7 == V_170 -> V_7 ) )
return - V_112 ;
if ( V_169 -> V_91 || V_170 -> V_91 )
return - V_174 ;
strncpy ( V_173 , V_169 -> V_6 , V_151 ) ;
strncpy ( V_169 -> V_6 , V_170 -> V_6 , V_151 ) ;
strncpy ( V_170 -> V_6 , V_173 , V_151 ) ;
F_69 ( & V_89 ) ;
F_119 ( V_169 -> V_90 , V_170 -> V_90 ) ;
V_52 ( V_93 , V_171 ) = V_170 ;
V_52 ( V_93 , V_172 ) = V_169 ;
F_70 ( & V_89 ) ;
return 0 ;
}
static int
F_120 ( struct V_175 * V_176 )
{
if ( V_176 -> args [ V_177 ] ) {
struct V_1 * V_93 =
(struct V_1 * ) V_176 -> args [ V_178 ] ;
T_6 V_92 = ( T_6 ) V_176 -> args [ V_179 ] ;
struct V_52 * V_53 = V_52 ( V_93 , V_92 ) ;
if ( V_53 -> V_101 -> V_180 )
V_53 -> V_101 -> V_180 ( V_53 , V_176 , false ) ;
F_11 ( L_19 , V_53 -> V_6 ) ;
F_74 ( V_53 ) ;
}
return 0 ;
}
static inline void
F_121 ( struct V_120 * V_121 )
{
const struct V_33 * V_140 ;
int V_181 ;
F_11 ( L_20 ) ;
F_122 (attr, nlh, sizeof(struct nfgenmsg), rem) {
F_11 ( L_21 , V_35 ( V_140 ) , V_140 -> V_182 ) ;
}
}
static int
F_123 ( struct V_175 * V_176 , struct V_1 * V_93 )
{
struct V_120 * V_121 = F_124 ( V_176 -> V_85 ) ;
int V_183 = F_125 ( sizeof( struct V_129 ) ) ;
struct V_33 * V_184 [ V_185 + 1 ] ;
struct V_33 * V_140 = ( void * ) V_121 + V_183 ;
T_4 V_186 ;
T_6 V_92 ;
F_126 ( V_184 , V_185 ,
V_140 , V_121 -> V_187 - V_183 , V_188 ) ;
if ( V_184 [ V_145 ] ) {
struct V_52 * V_53 ;
V_53 = F_96 ( V_93 , F_39 ( V_184 [ V_145 ] ) ,
& V_92 ) ;
if ( ! V_53 )
return - V_163 ;
V_186 = V_189 ;
V_176 -> args [ V_179 ] = V_92 ;
} else {
V_186 = V_190 ;
}
if ( V_184 [ V_191 ] ) {
T_4 V_192 = F_42 ( V_184 [ V_191 ] ) ;
V_186 |= ( V_192 << 16 ) ;
}
V_176 -> args [ V_178 ] = ( unsigned long ) V_93 ;
V_176 -> args [ V_193 ] = V_186 ;
return 0 ;
}
static int
F_127 ( struct V_84 * V_85 , struct V_175 * V_176 )
{
T_6 V_92 = V_115 , V_21 ;
struct V_52 * V_53 = NULL ;
struct V_120 * V_121 = NULL ;
unsigned int V_48 = F_128 ( V_176 -> V_85 ) . V_125 ? V_194 : 0 ;
struct V_1 * V_93 = F_1 ( F_129 ( V_85 -> V_195 ) ) ;
T_4 V_186 , V_196 ;
bool V_162 ;
int V_22 = 0 ;
if ( ! V_176 -> args [ V_193 ] ) {
V_22 = F_123 ( V_176 , V_93 ) ;
if ( V_22 < 0 ) {
V_121 = F_124 ( V_176 -> V_85 ) ;
if ( V_121 -> V_122 & V_197 )
F_130 ( V_176 -> V_85 , V_121 , V_22 ) ;
return V_22 ;
}
}
if ( V_176 -> args [ V_179 ] >= V_93 -> V_117 )
goto V_152;
V_186 = F_131 ( V_176 -> args [ V_193 ] ) ;
V_196 = F_132 ( V_176 -> args [ V_193 ] ) ;
V_21 = V_186 == V_189 ? V_176 -> args [ V_179 ] + 1
: V_93 -> V_117 ;
V_198:
F_11 ( L_22 ,
V_186 , V_196 , V_176 -> args [ V_179 ] ) ;
for (; V_176 -> args [ V_179 ] < V_21 ; V_176 -> args [ V_179 ] ++ ) {
V_92 = ( T_6 ) V_176 -> args [ V_179 ] ;
F_69 ( & V_89 ) ;
V_53 = V_52 ( V_93 , V_92 ) ;
V_162 = V_93 -> V_162 ;
if ( ! V_53 || V_162 ) {
F_70 ( & V_89 ) ;
if ( V_186 == V_189 ) {
V_22 = - V_163 ;
goto V_152;
}
if ( V_162 ) {
V_22 = 0 ;
goto V_152;
}
continue;
}
if ( V_186 != V_189 &&
( ( V_186 == V_190 ) ==
! ! ( V_53 -> type -> V_109 & V_199 ) ) ) {
F_70 ( & V_89 ) ;
continue;
}
F_11 ( L_23 , V_53 -> V_6 ) ;
if ( ! V_176 -> args [ V_177 ] ) {
F_11 ( L_24 ) ;
V_53 -> V_91 ++ ;
}
F_70 ( & V_89 ) ;
V_121 = F_93 ( V_85 , F_128 ( V_176 -> V_85 ) . V_125 ,
V_176 -> V_121 -> V_200 , V_48 ,
V_201 ) ;
if ( ! V_121 ) {
V_22 = - V_88 ;
goto V_202;
}
if ( F_133 ( V_85 , V_119 , V_24 ) ||
F_134 ( V_85 , V_145 , V_53 -> V_6 ) )
goto V_203;
if ( V_196 & V_204 )
goto V_205;
switch ( V_176 -> args [ V_177 ] ) {
case 0 :
if ( F_134 ( V_85 , V_146 ,
V_53 -> type -> V_6 ) ||
F_133 ( V_85 , V_148 ,
V_53 -> V_7 ) ||
F_133 ( V_85 , V_147 ,
V_53 -> V_8 ) )
goto V_203;
V_22 = V_53 -> V_101 -> V_206 ( V_53 , V_85 ) ;
if ( V_22 < 0 )
goto V_202;
if ( V_196 & V_207 )
goto V_205;
if ( V_53 -> V_101 -> V_180 )
V_53 -> V_101 -> V_180 ( V_53 , V_176 , true ) ;
default:
F_78 () ;
V_22 = V_53 -> V_101 -> V_26 ( V_53 , V_85 , V_176 ) ;
F_79 () ;
if ( ! V_176 -> args [ V_177 ] )
goto V_205;
goto V_202;
}
}
if ( V_186 == V_190 ) {
V_186 = V_208 ;
V_176 -> args [ V_193 ] = V_186 | ( V_196 << 16 ) ;
V_176 -> args [ V_179 ] = 0 ;
if ( V_53 && V_53 -> V_101 -> V_180 )
V_53 -> V_101 -> V_180 ( V_53 , V_176 , false ) ;
goto V_198;
}
goto V_152;
V_203:
V_22 = - V_18 ;
V_205:
if ( V_186 == V_189 )
V_176 -> args [ V_179 ] = V_115 ;
else
V_176 -> args [ V_179 ] ++ ;
V_202:
if ( V_22 || ! V_176 -> args [ V_177 ] ) {
V_53 = V_52 ( V_93 , V_92 ) ;
if ( V_53 -> V_101 -> V_180 )
V_53 -> V_101 -> V_180 ( V_53 , V_176 , false ) ;
F_11 ( L_19 , V_53 -> V_6 ) ;
F_74 ( V_53 ) ;
V_176 -> args [ V_177 ] = 0 ;
}
V_152:
if ( V_121 ) {
F_135 ( V_85 , V_121 ) ;
F_11 ( L_25 , V_121 -> V_187 ) ;
F_121 ( V_121 ) ;
}
return V_22 < 0 ? V_22 : V_85 -> V_54 ;
}
static int F_136 ( struct V_2 * V_2 , struct V_138 * V_139 , struct V_84 * V_85 ,
const struct V_120 * V_121 ,
const struct V_33 * const V_140 [] )
{
if ( F_34 ( F_90 ( V_140 ) ) )
return - V_40 ;
{
struct V_209 V_210 = {
. V_211 = F_127 ,
. V_212 = F_120 ,
} ;
return F_137 ( V_139 , V_85 , V_121 , & V_210 ) ;
}
}
static int
F_138 ( struct V_138 * V_139 , struct V_84 * V_85 , struct V_52 * V_53 ,
struct V_33 * V_38 [] , enum V_213 V_214 ,
T_4 V_48 , bool V_215 )
{
int V_22 ;
T_4 V_216 = 0 ;
bool V_217 = V_48 & V_124 , V_218 = false ;
do {
F_80 ( & V_53 -> V_105 ) ;
V_22 = V_53 -> V_101 -> V_219 ( V_53 , V_38 , V_214 , & V_216 , V_48 , V_218 ) ;
F_81 ( & V_53 -> V_105 ) ;
V_218 = true ;
} while ( V_22 == - V_104 &&
V_53 -> V_101 -> V_220 &&
( V_22 = V_53 -> V_101 -> V_220 ( V_53 , V_218 ) ) == 0 );
if ( ! V_22 || ( V_22 == - V_221 && V_217 ) )
return 0 ;
if ( V_216 && V_215 ) {
struct V_120 * V_222 , * V_121 = F_124 ( V_85 ) ;
struct V_84 * V_223 ;
struct V_224 * V_225 ;
T_2 V_226 = V_20 ( V_227 ,
sizeof( * V_225 ) + V_187 ( V_121 ) ) ;
int V_183 = F_125 ( sizeof( struct V_129 ) ) ;
struct V_33 * V_184 [ V_185 + 1 ] ;
struct V_33 * V_228 ;
T_4 * V_229 ;
V_223 = F_139 ( V_226 , V_31 ) ;
if ( ! V_223 )
return - V_150 ;
V_222 = F_140 ( V_223 , F_128 ( V_85 ) . V_125 ,
V_121 -> V_200 , V_230 , V_226 , 0 ) ;
V_225 = F_95 ( V_222 ) ;
V_225 -> error = V_22 ;
memcpy ( & V_225 -> V_231 , V_121 , V_121 -> V_187 ) ;
V_228 = ( void * ) & V_225 -> V_231 + V_183 ;
F_126 ( V_184 , V_185 ,
V_228 , V_121 -> V_187 - V_183 ,
V_232 ) ;
V_229 = F_39 ( V_184 [ V_233 ] ) ;
* V_229 = V_216 ;
F_141 ( V_139 , V_223 , F_128 ( V_85 ) . V_125 ,
V_234 ) ;
return - V_235 ;
}
return V_22 ;
}
static int F_142 ( struct V_2 * V_2 , struct V_138 * V_139 , struct V_84 * V_85 ,
const struct V_120 * V_121 ,
const struct V_33 * const V_140 [] )
{
struct V_1 * V_93 = F_1 ( V_2 ) ;
struct V_52 * V_53 ;
struct V_33 * V_38 [ V_236 + 1 ] = {} ;
const struct V_33 * V_34 ;
T_4 V_48 = F_92 ( V_121 ) ;
bool V_215 ;
int V_22 = 0 ;
if ( F_34 ( F_90 ( V_140 ) ||
! V_140 [ V_145 ] ||
! ( ( V_140 [ V_149 ] != NULL ) ^
( V_140 [ V_237 ] != NULL ) ) ||
( V_140 [ V_149 ] &&
! F_32 ( V_140 [ V_149 ] ) ) ||
( V_140 [ V_237 ] &&
( ! F_32 ( V_140 [ V_237 ] ) ||
! V_140 [ V_233 ] ) ) ) )
return - V_40 ;
V_53 = F_97 ( V_93 , F_39 ( V_140 [ V_145 ] ) ) ;
if ( ! V_53 )
return - V_163 ;
V_215 = ! ! V_140 [ V_233 ] ;
if ( V_140 [ V_149 ] ) {
if ( F_35 ( V_38 , V_236 ,
V_140 [ V_149 ] ,
V_53 -> type -> V_238 ) )
return - V_40 ;
V_22 = F_138 ( V_139 , V_85 , V_53 , V_38 , V_106 , V_48 ,
V_215 ) ;
} else {
int V_239 ;
F_143 (nla, attr[IPSET_ATTR_ADT], nla_rem) {
memset ( V_38 , 0 , sizeof( V_38 ) ) ;
if ( V_35 ( V_34 ) != V_149 ||
! F_32 ( V_34 ) ||
F_35 ( V_38 , V_236 , V_34 ,
V_53 -> type -> V_238 ) )
return - V_40 ;
V_22 = F_138 ( V_139 , V_85 , V_53 , V_38 , V_106 ,
V_48 , V_215 ) ;
if ( V_22 < 0 )
return V_22 ;
}
}
return V_22 ;
}
static int F_144 ( struct V_2 * V_2 , struct V_138 * V_139 , struct V_84 * V_85 ,
const struct V_120 * V_121 ,
const struct V_33 * const V_140 [] )
{
struct V_1 * V_93 = F_1 ( V_2 ) ;
struct V_52 * V_53 ;
struct V_33 * V_38 [ V_236 + 1 ] = {} ;
const struct V_33 * V_34 ;
T_4 V_48 = F_92 ( V_121 ) ;
bool V_215 ;
int V_22 = 0 ;
if ( F_34 ( F_90 ( V_140 ) ||
! V_140 [ V_145 ] ||
! ( ( V_140 [ V_149 ] != NULL ) ^
( V_140 [ V_237 ] != NULL ) ) ||
( V_140 [ V_149 ] &&
! F_32 ( V_140 [ V_149 ] ) ) ||
( V_140 [ V_237 ] &&
( ! F_32 ( V_140 [ V_237 ] ) ||
! V_140 [ V_233 ] ) ) ) )
return - V_40 ;
V_53 = F_97 ( V_93 , F_39 ( V_140 [ V_145 ] ) ) ;
if ( ! V_53 )
return - V_163 ;
V_215 = ! ! V_140 [ V_233 ] ;
if ( V_140 [ V_149 ] ) {
if ( F_35 ( V_38 , V_236 ,
V_140 [ V_149 ] ,
V_53 -> type -> V_238 ) )
return - V_40 ;
V_22 = F_138 ( V_139 , V_85 , V_53 , V_38 , V_113 , V_48 ,
V_215 ) ;
} else {
int V_239 ;
F_143 (nla, attr[IPSET_ATTR_ADT], nla_rem) {
memset ( V_38 , 0 , sizeof( * V_38 ) ) ;
if ( V_35 ( V_34 ) != V_149 ||
! F_32 ( V_34 ) ||
F_35 ( V_38 , V_236 , V_34 ,
V_53 -> type -> V_238 ) )
return - V_40 ;
V_22 = F_138 ( V_139 , V_85 , V_53 , V_38 , V_113 ,
V_48 , V_215 ) ;
if ( V_22 < 0 )
return V_22 ;
}
}
return V_22 ;
}
static int F_145 ( struct V_2 * V_2 , struct V_138 * V_139 , struct V_84 * V_85 ,
const struct V_120 * V_121 ,
const struct V_33 * const V_140 [] )
{
struct V_1 * V_93 = F_1 ( V_2 ) ;
struct V_52 * V_53 ;
struct V_33 * V_38 [ V_236 + 1 ] = {} ;
int V_22 = 0 ;
if ( F_34 ( F_90 ( V_140 ) ||
! V_140 [ V_145 ] ||
! V_140 [ V_149 ] ||
! F_32 ( V_140 [ V_149 ] ) ) )
return - V_40 ;
V_53 = F_97 ( V_93 , F_39 ( V_140 [ V_145 ] ) ) ;
if ( ! V_53 )
return - V_163 ;
if ( F_35 ( V_38 , V_236 , V_140 [ V_149 ] ,
V_53 -> type -> V_238 ) )
return - V_40 ;
F_78 () ;
V_22 = V_53 -> V_101 -> V_219 ( V_53 , V_38 , V_103 , NULL , 0 , 0 ) ;
F_79 () ;
if ( V_22 == - V_104 )
V_22 = 1 ;
return V_22 > 0 ? 0 : - V_221 ;
}
static int F_146 ( struct V_2 * V_2 , struct V_138 * V_139 ,
struct V_84 * V_85 , const struct V_120 * V_121 ,
const struct V_33 * const V_140 [] )
{
struct V_1 * V_93 = F_1 ( V_2 ) ;
const struct V_52 * V_53 ;
struct V_84 * V_223 ;
struct V_120 * V_240 ;
int V_22 = 0 ;
if ( F_34 ( F_90 ( V_140 ) ||
! V_140 [ V_145 ] ) )
return - V_40 ;
V_53 = F_97 ( V_93 , F_39 ( V_140 [ V_145 ] ) ) ;
if ( ! V_53 )
return - V_163 ;
V_223 = F_139 ( V_241 , V_31 ) ;
if ( ! V_223 )
return - V_150 ;
V_240 = F_93 ( V_223 , F_128 ( V_85 ) . V_125 , V_121 -> V_200 , 0 ,
V_242 ) ;
if ( ! V_240 )
goto V_243;
if ( F_133 ( V_223 , V_119 , V_24 ) ||
F_134 ( V_223 , V_145 , V_53 -> V_6 ) ||
F_134 ( V_223 , V_146 , V_53 -> type -> V_6 ) ||
F_133 ( V_223 , V_148 , V_53 -> V_7 ) ||
F_133 ( V_223 , V_147 , V_53 -> V_8 ) )
goto V_203;
F_135 ( V_223 , V_240 ) ;
V_22 = F_141 ( V_139 , V_223 , F_128 ( V_85 ) . V_125 , V_234 ) ;
if ( V_22 < 0 )
return V_22 ;
return 0 ;
V_203:
F_147 ( V_223 , V_240 ) ;
V_243:
F_148 ( V_223 ) ;
return - V_88 ;
}
static int V_5 ( struct V_2 * V_2 , struct V_138 * V_139 , struct V_84 * V_85 ,
const struct V_120 * V_121 ,
const struct V_33 * const V_140 [] )
{
struct V_84 * V_223 ;
struct V_120 * V_240 ;
T_1 V_7 , V_20 , V_21 ;
const char * V_144 ;
int V_22 = 0 ;
if ( F_34 ( F_90 ( V_140 ) ||
! V_140 [ V_146 ] ||
! V_140 [ V_148 ] ) )
return - V_40 ;
V_7 = F_91 ( V_140 [ V_148 ] ) ;
V_144 = F_39 ( V_140 [ V_146 ] ) ;
V_22 = F_149 ( V_144 , V_7 , & V_20 , & V_21 ) ;
if ( V_22 )
return V_22 ;
V_223 = F_139 ( V_241 , V_31 ) ;
if ( ! V_223 )
return - V_150 ;
V_240 = F_93 ( V_223 , F_128 ( V_85 ) . V_125 , V_121 -> V_200 , 0 ,
V_244 ) ;
if ( ! V_240 )
goto V_243;
if ( F_133 ( V_223 , V_119 , V_24 ) ||
F_134 ( V_223 , V_146 , V_144 ) ||
F_133 ( V_223 , V_148 , V_7 ) ||
F_133 ( V_223 , V_147 , V_21 ) ||
F_133 ( V_223 , V_245 , V_20 ) )
goto V_203;
F_135 ( V_223 , V_240 ) ;
F_11 ( L_26 , V_240 -> V_187 ) ;
V_22 = F_141 ( V_139 , V_223 , F_128 ( V_85 ) . V_125 , V_234 ) ;
if ( V_22 < 0 )
return V_22 ;
return 0 ;
V_203:
F_147 ( V_223 , V_240 ) ;
V_243:
F_148 ( V_223 ) ;
return - V_88 ;
}
static int F_150 ( struct V_2 * V_2 , struct V_138 * V_139 ,
struct V_84 * V_85 , const struct V_120 * V_121 ,
const struct V_33 * const V_140 [] )
{
struct V_84 * V_223 ;
struct V_120 * V_240 ;
int V_22 = 0 ;
if ( F_34 ( ! V_140 [ V_119 ] ) )
return - V_40 ;
V_223 = F_139 ( V_241 , V_31 ) ;
if ( ! V_223 )
return - V_150 ;
V_240 = F_93 ( V_223 , F_128 ( V_85 ) . V_125 , V_121 -> V_200 , 0 ,
V_246 ) ;
if ( ! V_240 )
goto V_243;
if ( F_133 ( V_223 , V_119 , V_24 ) )
goto V_203;
F_135 ( V_223 , V_240 ) ;
V_22 = F_141 ( V_139 , V_223 , F_128 ( V_85 ) . V_125 , V_234 ) ;
if ( V_22 < 0 )
return V_22 ;
return 0 ;
V_203:
F_147 ( V_223 , V_240 ) ;
V_243:
F_148 ( V_223 ) ;
return - V_88 ;
}
static int
F_151 ( struct V_138 * V_195 , int V_247 , void T_7 * V_248 , int * V_54 )
{
unsigned int * V_249 ;
void * V_250 ;
int V_251 = * V_54 , V_22 = 0 ;
struct V_2 * V_2 = F_129 ( V_195 ) ;
struct V_1 * V_93 = F_1 ( V_2 ) ;
if ( ! F_152 ( V_2 -> V_252 , V_253 ) )
return - V_254 ;
if ( V_247 != V_255 )
return - V_256 ;
if ( * V_54 < sizeof( unsigned int ) )
return - V_25 ;
V_250 = F_153 ( * V_54 ) ;
if ( ! V_250 )
return - V_150 ;
if ( F_154 ( V_250 , V_248 , * V_54 ) != 0 ) {
V_22 = - V_18 ;
goto V_212;
}
V_249 = ( unsigned int * ) V_250 ;
if ( * V_249 < V_257 ) {
struct V_258 * V_259 = V_250 ;
if ( * V_54 < sizeof( struct V_258 ) ) {
V_22 = - V_25 ;
goto V_212;
}
if ( V_259 -> V_133 != V_24 ) {
V_22 = - V_260 ;
goto V_212;
}
}
switch ( * V_249 ) {
case V_257 : {
struct V_258 * V_259 = V_250 ;
if ( * V_54 != sizeof( struct V_258 ) ) {
V_22 = - V_25 ;
goto V_212;
}
V_259 -> V_133 = V_24 ;
V_22 = F_155 ( V_248 , V_259 ,
sizeof( struct V_258 ) ) ;
goto V_212;
}
case V_261 : {
struct V_262 * V_263 = V_250 ;
T_6 V_47 ;
if ( * V_54 != sizeof( struct V_262 ) ) {
V_22 = - V_25 ;
goto V_212;
}
V_263 -> V_53 . V_6 [ V_151 - 1 ] = '\0' ;
F_14 ( V_12 ) ;
F_96 ( V_93 , V_263 -> V_53 . V_6 , & V_47 ) ;
V_263 -> V_53 . V_92 = V_47 ;
F_10 ( V_12 ) ;
goto V_264;
}
case V_265 : {
struct V_266 * V_263 = V_250 ;
T_6 V_47 ;
if ( * V_54 != sizeof( struct V_266 ) ) {
V_22 = - V_25 ;
goto V_212;
}
V_263 -> V_53 . V_6 [ V_151 - 1 ] = '\0' ;
F_14 ( V_12 ) ;
F_96 ( V_93 , V_263 -> V_53 . V_6 , & V_47 ) ;
V_263 -> V_53 . V_92 = V_47 ;
if ( V_47 != V_115 )
V_263 -> V_7 = V_52 ( V_93 , V_47 ) -> V_7 ;
F_10 ( V_12 ) ;
goto V_264;
}
case V_267 : {
struct V_262 * V_263 = V_250 ;
struct V_52 * V_53 ;
if ( * V_54 != sizeof( struct V_262 ) ||
V_263 -> V_53 . V_92 >= V_93 -> V_117 ) {
V_22 = - V_25 ;
goto V_212;
}
F_14 ( V_12 ) ;
V_53 = V_52 ( V_93 , V_263 -> V_53 . V_92 ) ;
strncpy ( V_263 -> V_53 . V_6 , V_53 ? V_53 -> V_6 : L_27 ,
V_151 ) ;
F_10 ( V_12 ) ;
goto V_264;
}
default:
V_22 = - V_268 ;
goto V_212;
}
V_264:
V_22 = F_155 ( V_248 , V_250 , V_251 ) ;
V_212:
F_156 ( V_250 ) ;
if ( V_22 > 0 )
V_22 = 0 ;
return V_22 ;
}
static int T_8
F_157 ( struct V_2 * V_2 )
{
struct V_1 * V_93 = F_1 ( V_2 ) ;
struct V_52 * * V_26 ;
V_93 -> V_117 = V_269 ? V_269 : V_270 ;
if ( V_93 -> V_117 >= V_115 )
V_93 -> V_117 = V_115 - 1 ;
V_26 = F_104 ( V_93 -> V_117 , sizeof( struct V_52 * ) , V_31 ) ;
if ( ! V_26 )
return - V_150 ;
V_93 -> V_118 = false ;
V_93 -> V_162 = false ;
F_106 ( V_93 -> V_94 , V_26 ) ;
return 0 ;
}
static void T_9
F_158 ( struct V_2 * V_2 )
{
struct V_1 * V_93 = F_1 ( V_2 ) ;
struct V_52 * V_53 = NULL ;
T_6 V_114 ;
V_93 -> V_118 = true ;
for ( V_114 = 0 ; V_114 < V_93 -> V_117 ; V_114 ++ ) {
V_53 = V_52 ( V_93 , V_114 ) ;
if ( V_53 ) {
V_52 ( V_93 , V_114 ) = NULL ;
F_110 ( V_53 ) ;
}
}
F_108 ( F_159 ( V_93 -> V_94 , 1 ) ) ;
}
static int T_10
F_160 ( void )
{
int V_22 = F_161 ( & V_271 ) ;
if ( V_22 != 0 ) {
F_162 ( L_28 ) ;
return V_22 ;
}
V_22 = F_163 ( & V_272 ) ;
if ( V_22 != 0 ) {
F_162 ( L_29 , V_22 ) ;
F_164 ( & V_271 ) ;
return V_22 ;
}
V_22 = F_165 ( & V_273 ) ;
if ( V_22 ) {
F_162 ( L_30 ) ;
F_166 ( & V_272 ) ;
F_164 ( & V_271 ) ;
return V_22 ;
}
F_167 ( L_31 , V_24 ) ;
return 0 ;
}
static void T_11
F_168 ( void )
{
F_169 ( & V_273 ) ;
F_166 ( & V_272 ) ;
F_164 ( & V_271 ) ;
F_11 ( L_32 ) ;
}
