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
struct V_52 * V_53 = F_73 ( V_95 -> V_2 , V_91 ) ;
int V_22 = 0 ;
F_72 ( ! V_53 ) ;
F_11 ( L_14 , V_53 -> V_6 , V_91 ) ;
if ( V_97 -> V_98 < V_53 -> type -> V_99 ||
! ( V_97 -> V_7 == V_53 -> V_7 || V_53 -> V_7 == V_9 ) )
return 0 ;
F_76 () ;
V_22 = V_53 -> V_100 -> V_101 ( V_53 , V_85 , V_95 , V_102 , V_97 ) ;
F_77 () ;
if ( V_22 == - V_103 ) {
F_11 ( L_15 ) ;
F_78 ( & V_53 -> V_104 ) ;
V_53 -> V_100 -> V_101 ( V_53 , V_85 , V_95 , V_105 , V_97 ) ;
F_79 ( & V_53 -> V_104 ) ;
V_22 = 1 ;
} else {
if ( ( V_97 -> V_106 & V_107 ) &&
( V_53 -> type -> V_108 & V_109 ) &&
( V_22 > 0 || V_22 == - V_110 ) )
V_22 = - V_22 ;
}
return ( V_22 < 0 ? 0 : V_22 ) ;
}
int
F_80 ( T_6 V_91 , const struct V_84 * V_85 ,
const struct V_94 * V_95 , struct V_96 * V_97 )
{
struct V_52 * V_53 = F_73 ( V_95 -> V_2 , V_91 ) ;
int V_22 ;
F_72 ( ! V_53 ) ;
F_11 ( L_14 , V_53 -> V_6 , V_91 ) ;
if ( V_97 -> V_98 < V_53 -> type -> V_99 ||
! ( V_97 -> V_7 == V_53 -> V_7 || V_53 -> V_7 == V_9 ) )
return - V_111 ;
F_78 ( & V_53 -> V_104 ) ;
V_22 = V_53 -> V_100 -> V_101 ( V_53 , V_85 , V_95 , V_105 , V_97 ) ;
F_79 ( & V_53 -> V_104 ) ;
return V_22 ;
}
int
F_81 ( T_6 V_91 , const struct V_84 * V_85 ,
const struct V_94 * V_95 , struct V_96 * V_97 )
{
struct V_52 * V_53 = F_73 ( V_95 -> V_2 , V_91 ) ;
int V_22 = 0 ;
F_72 ( ! V_53 ) ;
F_11 ( L_14 , V_53 -> V_6 , V_91 ) ;
if ( V_97 -> V_98 < V_53 -> type -> V_99 ||
! ( V_97 -> V_7 == V_53 -> V_7 || V_53 -> V_7 == V_9 ) )
return - V_111 ;
F_78 ( & V_53 -> V_104 ) ;
V_22 = V_53 -> V_100 -> V_101 ( V_53 , V_85 , V_95 , V_112 , V_97 ) ;
F_79 ( & V_53 -> V_104 ) ;
return V_22 ;
}
T_6
F_82 ( struct V_2 * V_2 , const char * V_6 , struct V_52 * * V_53 )
{
T_6 V_113 , V_91 = V_114 ;
struct V_52 * V_115 ;
struct V_1 * V_92 = F_1 ( V_2 ) ;
F_16 () ;
for ( V_113 = 0 ; V_113 < V_92 -> V_116 ; V_113 ++ ) {
V_115 = F_74 ( V_92 -> V_93 ) [ V_113 ] ;
if ( V_115 && STRNCMP ( V_115 -> V_6 , V_6 ) ) {
F_68 ( V_115 ) ;
V_91 = V_113 ;
* V_53 = V_115 ;
break;
}
}
F_18 () ;
return V_91 ;
}
static inline void
F_83 ( struct V_1 * V_92 , T_6 V_91 )
{
struct V_52 * V_53 ;
F_16 () ;
V_53 = F_74 ( V_92 -> V_93 ) [ V_91 ] ;
if ( V_53 )
F_71 ( V_53 ) ;
F_18 () ;
}
void
F_84 ( struct V_2 * V_2 , T_6 V_91 )
{
struct V_1 * V_92 = F_1 ( V_2 ) ;
F_83 ( V_92 , V_91 ) ;
}
const char *
F_85 ( struct V_2 * V_2 , T_6 V_91 )
{
const struct V_52 * V_53 = F_73 ( V_2 , V_91 ) ;
F_72 ( ! V_53 ) ;
F_72 ( V_53 -> V_90 == 0 ) ;
return V_53 -> V_6 ;
}
T_6
F_86 ( struct V_2 * V_2 , T_6 V_91 )
{
struct V_52 * V_53 ;
struct V_1 * V_92 = F_1 ( V_2 ) ;
if ( V_91 >= V_92 -> V_116 )
return V_114 ;
F_14 ( V_12 ) ;
V_53 = V_52 ( V_92 , V_91 ) ;
if ( V_53 )
F_68 ( V_53 ) ;
else
V_91 = V_114 ;
F_10 ( V_12 ) ;
return V_91 ;
}
void
F_87 ( struct V_2 * V_2 , T_6 V_91 )
{
struct V_52 * V_53 ;
struct V_1 * V_92 = F_1 ( V_2 ) ;
F_14 ( V_12 ) ;
if ( ! V_92 -> V_117 ) {
V_53 = V_52 ( V_92 , V_91 ) ;
if ( V_53 )
F_71 ( V_53 ) ;
}
F_10 ( V_12 ) ;
}
static inline bool
F_88 ( const struct V_33 * const V_38 [] )
{
return ! V_38 [ V_118 ] ||
F_89 ( V_38 [ V_118 ] ) != V_24 ;
}
static inline T_4
F_90 ( const struct V_119 * V_120 )
{
return V_120 -> V_121 & V_122 ? 0 : V_123 ;
}
static struct V_119 *
F_91 ( struct V_84 * V_85 , T_4 V_124 , T_4 V_125 , unsigned int V_48 ,
enum V_126 V_127 )
{
struct V_119 * V_120 ;
struct V_128 * V_129 ;
V_120 = F_92 ( V_85 , V_124 , V_125 , V_127 | ( V_12 << 8 ) ,
sizeof( * V_129 ) , V_48 ) ;
if ( ! V_120 )
return NULL ;
V_129 = F_93 ( V_120 ) ;
V_129 -> V_130 = V_131 ;
V_129 -> V_132 = V_133 ;
V_129 -> V_134 = 0 ;
return V_120 ;
}
static struct V_52 *
F_94 ( struct V_1 * V_92 , const char * V_6 , T_6 * V_47 )
{
struct V_52 * V_53 = NULL ;
T_6 V_113 ;
* V_47 = V_114 ;
for ( V_113 = 0 ; V_113 < V_92 -> V_116 ; V_113 ++ ) {
V_53 = V_52 ( V_92 , V_113 ) ;
if ( V_53 && STRNCMP ( V_53 -> V_6 , V_6 ) ) {
* V_47 = V_113 ;
break;
}
}
return ( * V_47 == V_114 ? NULL : V_53 ) ;
}
static inline struct V_52 *
F_95 ( struct V_1 * V_92 , const char * V_6 )
{
T_6 V_47 ;
return F_94 ( V_92 , V_6 , & V_47 ) ;
}
static int
F_96 ( struct V_1 * V_92 , const char * V_6 , T_6 * V_91 ,
struct V_52 * * V_53 )
{
struct V_52 * V_115 ;
T_6 V_113 ;
* V_91 = V_114 ;
for ( V_113 = 0 ; V_113 < V_92 -> V_116 ; V_113 ++ ) {
V_115 = V_52 ( V_92 , V_113 ) ;
if ( ! V_115 ) {
if ( * V_91 == V_114 )
* V_91 = V_113 ;
} else if ( STRNCMP ( V_6 , V_115 -> V_6 ) ) {
* V_53 = V_115 ;
return - V_135 ;
}
}
if ( * V_91 == V_114 )
return - V_136 ;
return 0 ;
}
static int F_97 ( struct V_2 * V_2 , struct V_137 * V_138 , struct V_84 * V_85 ,
const struct V_119 * V_120 ,
const struct V_33 * const V_139 [] )
{
return - V_140 ;
}
static int F_98 ( struct V_2 * V_2 , struct V_137 * V_138 ,
struct V_84 * V_85 , const struct V_119 * V_120 ,
const struct V_33 * const V_139 [] )
{
struct V_1 * V_92 = F_1 ( V_2 ) ;
struct V_52 * V_53 , * V_141 = NULL ;
T_6 V_91 = V_114 ;
struct V_33 * V_38 [ V_142 + 1 ] = {} ;
const char * V_6 , * V_143 ;
T_1 V_7 , V_8 ;
T_4 V_48 = F_90 ( V_120 ) ;
int V_22 = 0 ;
if ( F_34 ( F_88 ( V_139 ) ||
! V_139 [ V_144 ] ||
! V_139 [ V_145 ] ||
! V_139 [ V_146 ] ||
! V_139 [ V_147 ] ||
( V_139 [ V_148 ] &&
! F_32 ( V_139 [ V_148 ] ) ) ) )
return - V_40 ;
V_6 = F_39 ( V_139 [ V_144 ] ) ;
V_143 = F_39 ( V_139 [ V_145 ] ) ;
V_7 = F_89 ( V_139 [ V_147 ] ) ;
V_8 = F_89 ( V_139 [ V_146 ] ) ;
F_11 ( L_16 ,
V_6 , V_143 , F_21 ( V_7 ) , V_8 ) ;
V_53 = F_27 ( sizeof( * V_53 ) , V_31 ) ;
if ( ! V_53 )
return - V_149 ;
F_99 ( & V_53 -> V_104 ) ;
F_100 ( V_53 -> V_6 , V_6 , V_150 ) ;
V_53 -> V_7 = V_7 ;
V_53 -> V_8 = V_8 ;
V_22 = F_101 ( V_143 , V_7 , V_8 , & V_53 -> type ) ;
if ( V_22 )
goto V_151;
if ( V_139 [ V_148 ] &&
F_35 ( V_38 , V_142 , V_139 [ V_148 ] ,
V_53 -> type -> V_152 ) ) {
V_22 = - V_40 ;
goto V_153;
}
V_22 = V_53 -> type -> V_154 ( V_2 , V_53 , V_38 , V_48 ) ;
if ( V_22 != 0 )
goto V_153;
V_22 = F_96 ( V_92 , V_53 -> V_6 , & V_91 , & V_141 ) ;
if ( V_22 == - V_135 ) {
if ( ( V_48 & V_123 ) &&
STRNCMP ( V_53 -> type -> V_6 , V_141 -> type -> V_6 ) &&
V_53 -> type -> V_7 == V_141 -> type -> V_7 &&
V_53 -> type -> V_10 == V_141 -> type -> V_10 &&
V_53 -> type -> V_11 == V_141 -> type -> V_11 &&
V_53 -> V_100 -> V_155 ( V_53 , V_141 ) )
V_22 = 0 ;
goto V_156;
} else if ( V_22 == - V_136 ) {
struct V_52 * * V_26 , * * V_157 ;
T_6 V_113 = V_92 -> V_116 + V_158 ;
if ( V_113 < V_92 -> V_116 || V_113 == V_114 )
goto V_156;
V_26 = F_102 ( V_113 , sizeof( struct V_52 * ) , V_31 ) ;
if ( ! V_26 )
goto V_156;
V_157 = F_103 ( V_92 -> V_93 ) ;
memcpy ( V_26 , V_157 , sizeof( struct V_52 * ) * V_92 -> V_116 ) ;
F_104 ( V_92 -> V_93 , V_26 ) ;
F_105 () ;
V_91 = V_92 -> V_116 ;
V_92 -> V_116 = V_113 ;
F_106 ( V_157 ) ;
V_22 = 0 ;
} else if ( V_22 ) {
goto V_156;
}
F_11 ( L_17 , V_53 -> V_6 , V_91 ) ;
V_52 ( V_92 , V_91 ) = V_53 ;
return V_22 ;
V_156:
V_53 -> V_100 -> V_159 ( V_53 ) ;
V_153:
F_107 ( V_53 -> type -> V_17 ) ;
V_151:
F_106 ( V_53 ) ;
return V_22 ;
}
static void
F_108 ( struct V_52 * V_53 )
{
F_11 ( L_18 , V_53 -> V_6 ) ;
V_53 -> V_100 -> V_159 ( V_53 ) ;
F_107 ( V_53 -> type -> V_17 ) ;
F_106 ( V_53 ) ;
}
static int F_109 ( struct V_2 * V_2 , struct V_137 * V_138 ,
struct V_84 * V_85 , const struct V_119 * V_120 ,
const struct V_33 * const V_139 [] )
{
struct V_1 * V_92 = F_1 ( V_2 ) ;
struct V_52 * V_115 ;
T_6 V_113 ;
int V_22 = 0 ;
if ( F_34 ( F_88 ( V_139 ) ) )
return - V_40 ;
F_110 ( & V_89 ) ;
if ( ! V_139 [ V_144 ] ) {
for ( V_113 = 0 ; V_113 < V_92 -> V_116 ; V_113 ++ ) {
V_115 = V_52 ( V_92 , V_113 ) ;
if ( V_115 && V_115 -> V_90 ) {
V_22 = - V_160 ;
goto V_151;
}
}
V_92 -> V_161 = true ;
F_111 ( & V_89 ) ;
for ( V_113 = 0 ; V_113 < V_92 -> V_116 ; V_113 ++ ) {
V_115 = V_52 ( V_92 , V_113 ) ;
if ( V_115 ) {
V_52 ( V_92 , V_113 ) = NULL ;
F_108 ( V_115 ) ;
}
}
V_92 -> V_161 = false ;
} else {
V_115 = F_94 ( V_92 , F_39 ( V_139 [ V_144 ] ) ,
& V_113 ) ;
if ( ! V_115 ) {
V_22 = - V_162 ;
goto V_151;
} else if ( V_115 -> V_90 ) {
V_22 = - V_160 ;
goto V_151;
}
V_52 ( V_92 , V_113 ) = NULL ;
F_111 ( & V_89 ) ;
F_108 ( V_115 ) ;
}
return 0 ;
V_151:
F_111 ( & V_89 ) ;
return V_22 ;
}
static void
F_112 ( struct V_52 * V_53 )
{
F_11 ( L_18 , V_53 -> V_6 ) ;
F_78 ( & V_53 -> V_104 ) ;
V_53 -> V_100 -> V_163 ( V_53 ) ;
F_79 ( & V_53 -> V_104 ) ;
}
static int F_113 ( struct V_2 * V_2 , struct V_137 * V_138 , struct V_84 * V_85 ,
const struct V_119 * V_120 ,
const struct V_33 * const V_139 [] )
{
struct V_1 * V_92 = F_1 ( V_2 ) ;
struct V_52 * V_115 ;
T_6 V_113 ;
if ( F_34 ( F_88 ( V_139 ) ) )
return - V_40 ;
if ( ! V_139 [ V_144 ] ) {
for ( V_113 = 0 ; V_113 < V_92 -> V_116 ; V_113 ++ ) {
V_115 = V_52 ( V_92 , V_113 ) ;
if ( V_115 )
F_112 ( V_115 ) ;
}
} else {
V_115 = F_95 ( V_92 , F_39 ( V_139 [ V_144 ] ) ) ;
if ( ! V_115 )
return - V_162 ;
F_112 ( V_115 ) ;
}
return 0 ;
}
static int F_114 ( struct V_2 * V_2 , struct V_137 * V_138 ,
struct V_84 * V_85 , const struct V_119 * V_120 ,
const struct V_33 * const V_139 [] )
{
struct V_1 * V_92 = F_1 ( V_2 ) ;
struct V_52 * V_53 , * V_115 ;
const char * V_164 ;
T_6 V_113 ;
int V_22 = 0 ;
if ( F_34 ( F_88 ( V_139 ) ||
! V_139 [ V_144 ] ||
! V_139 [ V_165 ] ) )
return - V_40 ;
V_53 = F_95 ( V_92 , F_39 ( V_139 [ V_144 ] ) ) ;
if ( ! V_53 )
return - V_162 ;
F_110 ( & V_89 ) ;
if ( V_53 -> V_90 != 0 ) {
V_22 = - V_166 ;
goto V_151;
}
V_164 = F_39 ( V_139 [ V_165 ] ) ;
for ( V_113 = 0 ; V_113 < V_92 -> V_116 ; V_113 ++ ) {
V_115 = V_52 ( V_92 , V_113 ) ;
if ( V_115 && STRNCMP ( V_115 -> V_6 , V_164 ) ) {
V_22 = - V_167 ;
goto V_151;
}
}
strncpy ( V_53 -> V_6 , V_164 , V_150 ) ;
V_151:
F_111 ( & V_89 ) ;
return V_22 ;
}
static int F_115 ( struct V_2 * V_2 , struct V_137 * V_138 , struct V_84 * V_85 ,
const struct V_119 * V_120 ,
const struct V_33 * const V_139 [] )
{
struct V_1 * V_92 = F_1 ( V_2 ) ;
struct V_52 * V_168 , * V_169 ;
T_6 V_170 , V_171 ;
char V_172 [ V_150 ] ;
if ( F_34 ( F_88 ( V_139 ) ||
! V_139 [ V_144 ] ||
! V_139 [ V_165 ] ) )
return - V_40 ;
V_168 = F_94 ( V_92 , F_39 ( V_139 [ V_144 ] ) ,
& V_170 ) ;
if ( ! V_168 )
return - V_162 ;
V_169 = F_94 ( V_92 , F_39 ( V_139 [ V_165 ] ) ,
& V_171 ) ;
if ( ! V_169 )
return - V_167 ;
if ( ! ( V_168 -> type -> V_108 == V_169 -> type -> V_108 &&
V_168 -> V_7 == V_169 -> V_7 ) )
return - V_111 ;
strncpy ( V_172 , V_168 -> V_6 , V_150 ) ;
strncpy ( V_168 -> V_6 , V_169 -> V_6 , V_150 ) ;
strncpy ( V_169 -> V_6 , V_172 , V_150 ) ;
F_69 ( & V_89 ) ;
F_116 ( V_168 -> V_90 , V_169 -> V_90 ) ;
V_52 ( V_92 , V_170 ) = V_169 ;
V_52 ( V_92 , V_171 ) = V_168 ;
F_70 ( & V_89 ) ;
return 0 ;
}
static int
F_117 ( struct V_173 * V_174 )
{
if ( V_174 -> args [ V_175 ] ) {
struct V_1 * V_92 =
(struct V_1 * ) V_174 -> args [ V_176 ] ;
T_6 V_91 = ( T_6 ) V_174 -> args [ V_177 ] ;
struct V_52 * V_53 = V_52 ( V_92 , V_91 ) ;
if ( V_53 -> V_100 -> V_178 )
V_53 -> V_100 -> V_178 ( V_53 , V_174 , false ) ;
F_11 ( L_19 , V_53 -> V_6 ) ;
F_83 ( V_92 , V_91 ) ;
}
return 0 ;
}
static inline void
F_118 ( struct V_119 * V_120 )
{
const struct V_33 * V_139 ;
int V_179 ;
F_11 ( L_20 ) ;
F_119 (attr, nlh, sizeof(struct nfgenmsg), rem) {
F_11 ( L_21 , V_35 ( V_139 ) , V_139 -> V_180 ) ;
}
}
static int
F_120 ( struct V_173 * V_174 , struct V_1 * V_92 )
{
struct V_119 * V_120 = F_121 ( V_174 -> V_85 ) ;
int V_181 = F_122 ( sizeof( struct V_128 ) ) ;
struct V_33 * V_182 [ V_183 + 1 ] ;
struct V_33 * V_139 = ( void * ) V_120 + V_181 ;
T_4 V_184 ;
T_6 V_91 ;
F_123 ( V_182 , V_183 ,
V_139 , V_120 -> V_185 - V_181 , V_186 ) ;
if ( V_182 [ V_144 ] ) {
struct V_52 * V_53 ;
V_53 = F_94 ( V_92 , F_39 ( V_182 [ V_144 ] ) ,
& V_91 ) ;
if ( ! V_53 )
return - V_162 ;
V_184 = V_187 ;
V_174 -> args [ V_177 ] = V_91 ;
} else {
V_184 = V_188 ;
}
if ( V_182 [ V_189 ] ) {
T_4 V_190 = F_42 ( V_182 [ V_189 ] ) ;
V_184 |= ( V_190 << 16 ) ;
}
V_174 -> args [ V_176 ] = ( unsigned long ) V_92 ;
V_174 -> args [ V_191 ] = V_184 ;
return 0 ;
}
static int
F_124 ( struct V_84 * V_85 , struct V_173 * V_174 )
{
T_6 V_91 = V_114 , V_21 ;
struct V_52 * V_53 = NULL ;
struct V_119 * V_120 = NULL ;
unsigned int V_48 = F_125 ( V_174 -> V_85 ) . V_124 ? V_192 : 0 ;
struct V_1 * V_92 = F_1 ( F_126 ( V_85 -> V_193 ) ) ;
T_4 V_184 , V_194 ;
bool V_161 ;
int V_22 = 0 ;
if ( ! V_174 -> args [ V_191 ] ) {
V_22 = F_120 ( V_174 , V_92 ) ;
if ( V_22 < 0 ) {
V_120 = F_121 ( V_174 -> V_85 ) ;
if ( V_120 -> V_121 & V_195 )
F_127 ( V_174 -> V_85 , V_120 , V_22 ) ;
return V_22 ;
}
}
if ( V_174 -> args [ V_177 ] >= V_92 -> V_116 )
goto V_151;
V_184 = F_128 ( V_174 -> args [ V_191 ] ) ;
V_194 = F_129 ( V_174 -> args [ V_191 ] ) ;
V_21 = V_184 == V_187 ? V_174 -> args [ V_177 ] + 1
: V_92 -> V_116 ;
V_196:
F_11 ( L_22 ,
V_184 , V_194 , V_174 -> args [ V_177 ] ) ;
for (; V_174 -> args [ V_177 ] < V_21 ; V_174 -> args [ V_177 ] ++ ) {
V_91 = ( T_6 ) V_174 -> args [ V_177 ] ;
F_69 ( & V_89 ) ;
V_53 = V_52 ( V_92 , V_91 ) ;
V_161 = V_92 -> V_161 ;
if ( ! V_53 || V_161 ) {
F_70 ( & V_89 ) ;
if ( V_184 == V_187 ) {
V_22 = - V_162 ;
goto V_151;
}
if ( V_161 ) {
V_22 = 0 ;
goto V_151;
}
continue;
}
if ( V_184 != V_187 &&
( ( V_184 == V_188 ) ==
! ! ( V_53 -> type -> V_108 & V_197 ) ) ) {
F_70 ( & V_89 ) ;
continue;
}
F_11 ( L_23 , V_53 -> V_6 ) ;
if ( ! V_174 -> args [ V_175 ] ) {
F_11 ( L_24 ) ;
V_53 -> V_90 ++ ;
}
F_70 ( & V_89 ) ;
V_120 = F_91 ( V_85 , F_125 ( V_174 -> V_85 ) . V_124 ,
V_174 -> V_120 -> V_198 , V_48 ,
V_199 ) ;
if ( ! V_120 ) {
V_22 = - V_88 ;
goto V_200;
}
if ( F_130 ( V_85 , V_118 , V_24 ) ||
F_131 ( V_85 , V_144 , V_53 -> V_6 ) )
goto V_201;
if ( V_194 & V_202 )
goto V_203;
switch ( V_174 -> args [ V_175 ] ) {
case 0 :
if ( F_131 ( V_85 , V_145 ,
V_53 -> type -> V_6 ) ||
F_130 ( V_85 , V_147 ,
V_53 -> V_7 ) ||
F_130 ( V_85 , V_146 ,
V_53 -> V_8 ) )
goto V_201;
V_22 = V_53 -> V_100 -> V_204 ( V_53 , V_85 ) ;
if ( V_22 < 0 )
goto V_200;
if ( V_194 & V_205 )
goto V_203;
if ( V_53 -> V_100 -> V_178 )
V_53 -> V_100 -> V_178 ( V_53 , V_174 , true ) ;
default:
F_76 () ;
V_22 = V_53 -> V_100 -> V_26 ( V_53 , V_85 , V_174 ) ;
F_77 () ;
if ( ! V_174 -> args [ V_175 ] )
goto V_203;
goto V_200;
}
}
if ( V_184 == V_188 ) {
V_184 = V_206 ;
V_174 -> args [ V_191 ] = V_184 | ( V_194 << 16 ) ;
V_174 -> args [ V_177 ] = 0 ;
if ( V_53 && V_53 -> V_100 -> V_178 )
V_53 -> V_100 -> V_178 ( V_53 , V_174 , false ) ;
goto V_196;
}
goto V_151;
V_201:
V_22 = - V_18 ;
V_203:
if ( V_184 == V_187 )
V_174 -> args [ V_177 ] = V_114 ;
else
V_174 -> args [ V_177 ] ++ ;
V_200:
if ( V_22 || ! V_174 -> args [ V_175 ] ) {
V_53 = V_52 ( V_92 , V_91 ) ;
if ( V_53 -> V_100 -> V_178 )
V_53 -> V_100 -> V_178 ( V_53 , V_174 , false ) ;
F_11 ( L_19 , V_53 -> V_6 ) ;
F_83 ( V_92 , V_91 ) ;
V_174 -> args [ V_175 ] = 0 ;
}
V_151:
if ( V_120 ) {
F_132 ( V_85 , V_120 ) ;
F_11 ( L_25 , V_120 -> V_185 ) ;
F_118 ( V_120 ) ;
}
return V_22 < 0 ? V_22 : V_85 -> V_54 ;
}
static int F_133 ( struct V_2 * V_2 , struct V_137 * V_138 , struct V_84 * V_85 ,
const struct V_119 * V_120 ,
const struct V_33 * const V_139 [] )
{
if ( F_34 ( F_88 ( V_139 ) ) )
return - V_40 ;
{
struct V_207 V_208 = {
. V_209 = F_124 ,
. V_210 = F_117 ,
} ;
return F_134 ( V_138 , V_85 , V_120 , & V_208 ) ;
}
}
static int
F_135 ( struct V_137 * V_138 , struct V_84 * V_85 , struct V_52 * V_53 ,
struct V_33 * V_38 [] , enum V_211 V_212 ,
T_4 V_48 , bool V_213 )
{
int V_22 ;
T_4 V_214 = 0 ;
bool V_215 = V_48 & V_123 , V_216 = false ;
do {
F_78 ( & V_53 -> V_104 ) ;
V_22 = V_53 -> V_100 -> V_217 ( V_53 , V_38 , V_212 , & V_214 , V_48 , V_216 ) ;
F_79 ( & V_53 -> V_104 ) ;
V_216 = true ;
} while ( V_22 == - V_103 &&
V_53 -> V_100 -> V_218 &&
( V_22 = V_53 -> V_100 -> V_218 ( V_53 , V_216 ) ) == 0 );
if ( ! V_22 || ( V_22 == - V_219 && V_215 ) )
return 0 ;
if ( V_214 && V_213 ) {
struct V_119 * V_220 , * V_120 = F_121 ( V_85 ) ;
struct V_84 * V_221 ;
struct V_222 * V_223 ;
T_2 V_224 = V_20 ( V_225 ,
sizeof( * V_223 ) + V_185 ( V_120 ) ) ;
int V_181 = F_122 ( sizeof( struct V_128 ) ) ;
struct V_33 * V_182 [ V_183 + 1 ] ;
struct V_33 * V_226 ;
T_4 * V_227 ;
V_221 = F_136 ( V_224 , V_31 ) ;
if ( ! V_221 )
return - V_149 ;
V_220 = F_137 ( V_221 , F_125 ( V_85 ) . V_124 ,
V_120 -> V_198 , V_228 , V_224 , 0 ) ;
V_223 = F_93 ( V_220 ) ;
V_223 -> error = V_22 ;
memcpy ( & V_223 -> V_229 , V_120 , V_120 -> V_185 ) ;
V_226 = ( void * ) & V_223 -> V_229 + V_181 ;
F_123 ( V_182 , V_183 ,
V_226 , V_120 -> V_185 - V_181 ,
V_230 ) ;
V_227 = F_39 ( V_182 [ V_231 ] ) ;
* V_227 = V_214 ;
F_138 ( V_138 , V_221 , F_125 ( V_85 ) . V_124 ,
V_232 ) ;
return - V_233 ;
}
return V_22 ;
}
static int F_139 ( struct V_2 * V_2 , struct V_137 * V_138 , struct V_84 * V_85 ,
const struct V_119 * V_120 ,
const struct V_33 * const V_139 [] )
{
struct V_1 * V_92 = F_1 ( V_2 ) ;
struct V_52 * V_53 ;
struct V_33 * V_38 [ V_234 + 1 ] = {} ;
const struct V_33 * V_34 ;
T_4 V_48 = F_90 ( V_120 ) ;
bool V_213 ;
int V_22 = 0 ;
if ( F_34 ( F_88 ( V_139 ) ||
! V_139 [ V_144 ] ||
! ( ( V_139 [ V_148 ] != NULL ) ^
( V_139 [ V_235 ] != NULL ) ) ||
( V_139 [ V_148 ] &&
! F_32 ( V_139 [ V_148 ] ) ) ||
( V_139 [ V_235 ] &&
( ! F_32 ( V_139 [ V_235 ] ) ||
! V_139 [ V_231 ] ) ) ) )
return - V_40 ;
V_53 = F_95 ( V_92 , F_39 ( V_139 [ V_144 ] ) ) ;
if ( ! V_53 )
return - V_162 ;
V_213 = ! ! V_139 [ V_231 ] ;
if ( V_139 [ V_148 ] ) {
if ( F_35 ( V_38 , V_234 ,
V_139 [ V_148 ] ,
V_53 -> type -> V_236 ) )
return - V_40 ;
V_22 = F_135 ( V_138 , V_85 , V_53 , V_38 , V_105 , V_48 ,
V_213 ) ;
} else {
int V_237 ;
F_140 (nla, attr[IPSET_ATTR_ADT], nla_rem) {
memset ( V_38 , 0 , sizeof( V_38 ) ) ;
if ( V_35 ( V_34 ) != V_148 ||
! F_32 ( V_34 ) ||
F_35 ( V_38 , V_234 , V_34 ,
V_53 -> type -> V_236 ) )
return - V_40 ;
V_22 = F_135 ( V_138 , V_85 , V_53 , V_38 , V_105 ,
V_48 , V_213 ) ;
if ( V_22 < 0 )
return V_22 ;
}
}
return V_22 ;
}
static int F_141 ( struct V_2 * V_2 , struct V_137 * V_138 , struct V_84 * V_85 ,
const struct V_119 * V_120 ,
const struct V_33 * const V_139 [] )
{
struct V_1 * V_92 = F_1 ( V_2 ) ;
struct V_52 * V_53 ;
struct V_33 * V_38 [ V_234 + 1 ] = {} ;
const struct V_33 * V_34 ;
T_4 V_48 = F_90 ( V_120 ) ;
bool V_213 ;
int V_22 = 0 ;
if ( F_34 ( F_88 ( V_139 ) ||
! V_139 [ V_144 ] ||
! ( ( V_139 [ V_148 ] != NULL ) ^
( V_139 [ V_235 ] != NULL ) ) ||
( V_139 [ V_148 ] &&
! F_32 ( V_139 [ V_148 ] ) ) ||
( V_139 [ V_235 ] &&
( ! F_32 ( V_139 [ V_235 ] ) ||
! V_139 [ V_231 ] ) ) ) )
return - V_40 ;
V_53 = F_95 ( V_92 , F_39 ( V_139 [ V_144 ] ) ) ;
if ( ! V_53 )
return - V_162 ;
V_213 = ! ! V_139 [ V_231 ] ;
if ( V_139 [ V_148 ] ) {
if ( F_35 ( V_38 , V_234 ,
V_139 [ V_148 ] ,
V_53 -> type -> V_236 ) )
return - V_40 ;
V_22 = F_135 ( V_138 , V_85 , V_53 , V_38 , V_112 , V_48 ,
V_213 ) ;
} else {
int V_237 ;
F_140 (nla, attr[IPSET_ATTR_ADT], nla_rem) {
memset ( V_38 , 0 , sizeof( * V_38 ) ) ;
if ( V_35 ( V_34 ) != V_148 ||
! F_32 ( V_34 ) ||
F_35 ( V_38 , V_234 , V_34 ,
V_53 -> type -> V_236 ) )
return - V_40 ;
V_22 = F_135 ( V_138 , V_85 , V_53 , V_38 , V_112 ,
V_48 , V_213 ) ;
if ( V_22 < 0 )
return V_22 ;
}
}
return V_22 ;
}
static int F_142 ( struct V_2 * V_2 , struct V_137 * V_138 , struct V_84 * V_85 ,
const struct V_119 * V_120 ,
const struct V_33 * const V_139 [] )
{
struct V_1 * V_92 = F_1 ( V_2 ) ;
struct V_52 * V_53 ;
struct V_33 * V_38 [ V_234 + 1 ] = {} ;
int V_22 = 0 ;
if ( F_34 ( F_88 ( V_139 ) ||
! V_139 [ V_144 ] ||
! V_139 [ V_148 ] ||
! F_32 ( V_139 [ V_148 ] ) ) )
return - V_40 ;
V_53 = F_95 ( V_92 , F_39 ( V_139 [ V_144 ] ) ) ;
if ( ! V_53 )
return - V_162 ;
if ( F_35 ( V_38 , V_234 , V_139 [ V_148 ] ,
V_53 -> type -> V_236 ) )
return - V_40 ;
F_76 () ;
V_22 = V_53 -> V_100 -> V_217 ( V_53 , V_38 , V_102 , NULL , 0 , 0 ) ;
F_77 () ;
if ( V_22 == - V_103 )
V_22 = 1 ;
return V_22 > 0 ? 0 : - V_219 ;
}
static int F_143 ( struct V_2 * V_2 , struct V_137 * V_138 ,
struct V_84 * V_85 , const struct V_119 * V_120 ,
const struct V_33 * const V_139 [] )
{
struct V_1 * V_92 = F_1 ( V_2 ) ;
const struct V_52 * V_53 ;
struct V_84 * V_221 ;
struct V_119 * V_238 ;
int V_22 = 0 ;
if ( F_34 ( F_88 ( V_139 ) ||
! V_139 [ V_144 ] ) )
return - V_40 ;
V_53 = F_95 ( V_92 , F_39 ( V_139 [ V_144 ] ) ) ;
if ( ! V_53 )
return - V_162 ;
V_221 = F_136 ( V_239 , V_31 ) ;
if ( ! V_221 )
return - V_149 ;
V_238 = F_91 ( V_221 , F_125 ( V_85 ) . V_124 , V_120 -> V_198 , 0 ,
V_240 ) ;
if ( ! V_238 )
goto V_241;
if ( F_130 ( V_221 , V_118 , V_24 ) ||
F_131 ( V_221 , V_144 , V_53 -> V_6 ) ||
F_131 ( V_221 , V_145 , V_53 -> type -> V_6 ) ||
F_130 ( V_221 , V_147 , V_53 -> V_7 ) ||
F_130 ( V_221 , V_146 , V_53 -> V_8 ) )
goto V_201;
F_132 ( V_221 , V_238 ) ;
V_22 = F_138 ( V_138 , V_221 , F_125 ( V_85 ) . V_124 , V_232 ) ;
if ( V_22 < 0 )
return V_22 ;
return 0 ;
V_201:
F_144 ( V_221 , V_238 ) ;
V_241:
F_145 ( V_221 ) ;
return - V_88 ;
}
static int V_5 ( struct V_2 * V_2 , struct V_137 * V_138 , struct V_84 * V_85 ,
const struct V_119 * V_120 ,
const struct V_33 * const V_139 [] )
{
struct V_84 * V_221 ;
struct V_119 * V_238 ;
T_1 V_7 , V_20 , V_21 ;
const char * V_143 ;
int V_22 = 0 ;
if ( F_34 ( F_88 ( V_139 ) ||
! V_139 [ V_145 ] ||
! V_139 [ V_147 ] ) )
return - V_40 ;
V_7 = F_89 ( V_139 [ V_147 ] ) ;
V_143 = F_39 ( V_139 [ V_145 ] ) ;
V_22 = F_146 ( V_143 , V_7 , & V_20 , & V_21 ) ;
if ( V_22 )
return V_22 ;
V_221 = F_136 ( V_239 , V_31 ) ;
if ( ! V_221 )
return - V_149 ;
V_238 = F_91 ( V_221 , F_125 ( V_85 ) . V_124 , V_120 -> V_198 , 0 ,
V_242 ) ;
if ( ! V_238 )
goto V_241;
if ( F_130 ( V_221 , V_118 , V_24 ) ||
F_131 ( V_221 , V_145 , V_143 ) ||
F_130 ( V_221 , V_147 , V_7 ) ||
F_130 ( V_221 , V_146 , V_21 ) ||
F_130 ( V_221 , V_243 , V_20 ) )
goto V_201;
F_132 ( V_221 , V_238 ) ;
F_11 ( L_26 , V_238 -> V_185 ) ;
V_22 = F_138 ( V_138 , V_221 , F_125 ( V_85 ) . V_124 , V_232 ) ;
if ( V_22 < 0 )
return V_22 ;
return 0 ;
V_201:
F_144 ( V_221 , V_238 ) ;
V_241:
F_145 ( V_221 ) ;
return - V_88 ;
}
static int F_147 ( struct V_2 * V_2 , struct V_137 * V_138 ,
struct V_84 * V_85 , const struct V_119 * V_120 ,
const struct V_33 * const V_139 [] )
{
struct V_84 * V_221 ;
struct V_119 * V_238 ;
int V_22 = 0 ;
if ( F_34 ( ! V_139 [ V_118 ] ) )
return - V_40 ;
V_221 = F_136 ( V_239 , V_31 ) ;
if ( ! V_221 )
return - V_149 ;
V_238 = F_91 ( V_221 , F_125 ( V_85 ) . V_124 , V_120 -> V_198 , 0 ,
V_244 ) ;
if ( ! V_238 )
goto V_241;
if ( F_130 ( V_221 , V_118 , V_24 ) )
goto V_201;
F_132 ( V_221 , V_238 ) ;
V_22 = F_138 ( V_138 , V_221 , F_125 ( V_85 ) . V_124 , V_232 ) ;
if ( V_22 < 0 )
return V_22 ;
return 0 ;
V_201:
F_144 ( V_221 , V_238 ) ;
V_241:
F_145 ( V_221 ) ;
return - V_88 ;
}
static int
F_148 ( struct V_137 * V_193 , int V_245 , void T_7 * V_246 , int * V_54 )
{
unsigned int * V_247 ;
void * V_248 ;
int V_249 = * V_54 , V_22 = 0 ;
struct V_2 * V_2 = F_126 ( V_193 ) ;
struct V_1 * V_92 = F_1 ( V_2 ) ;
if ( ! F_149 ( V_2 -> V_250 , V_251 ) )
return - V_252 ;
if ( V_245 != V_253 )
return - V_254 ;
if ( * V_54 < sizeof( unsigned int ) )
return - V_25 ;
V_248 = F_150 ( * V_54 ) ;
if ( ! V_248 )
return - V_149 ;
if ( F_151 ( V_248 , V_246 , * V_54 ) != 0 ) {
V_22 = - V_18 ;
goto V_210;
}
V_247 = ( unsigned int * ) V_248 ;
if ( * V_247 < V_255 ) {
struct V_256 * V_257 = V_248 ;
if ( * V_54 < sizeof( struct V_256 ) ) {
V_22 = - V_25 ;
goto V_210;
}
if ( V_257 -> V_132 != V_24 ) {
V_22 = - V_258 ;
goto V_210;
}
}
switch ( * V_247 ) {
case V_255 : {
struct V_256 * V_257 = V_248 ;
if ( * V_54 != sizeof( struct V_256 ) ) {
V_22 = - V_25 ;
goto V_210;
}
V_257 -> V_132 = V_24 ;
V_22 = F_152 ( V_246 , V_257 ,
sizeof( struct V_256 ) ) ;
goto V_210;
}
case V_259 : {
struct V_260 * V_261 = V_248 ;
T_6 V_47 ;
if ( * V_54 != sizeof( struct V_260 ) ) {
V_22 = - V_25 ;
goto V_210;
}
V_261 -> V_53 . V_6 [ V_150 - 1 ] = '\0' ;
F_14 ( V_12 ) ;
F_94 ( V_92 , V_261 -> V_53 . V_6 , & V_47 ) ;
V_261 -> V_53 . V_91 = V_47 ;
F_10 ( V_12 ) ;
goto V_262;
}
case V_263 : {
struct V_264 * V_261 = V_248 ;
T_6 V_47 ;
if ( * V_54 != sizeof( struct V_264 ) ) {
V_22 = - V_25 ;
goto V_210;
}
V_261 -> V_53 . V_6 [ V_150 - 1 ] = '\0' ;
F_14 ( V_12 ) ;
F_94 ( V_92 , V_261 -> V_53 . V_6 , & V_47 ) ;
V_261 -> V_53 . V_91 = V_47 ;
if ( V_47 != V_114 )
V_261 -> V_7 = V_52 ( V_92 , V_47 ) -> V_7 ;
F_10 ( V_12 ) ;
goto V_262;
}
case V_265 : {
struct V_260 * V_261 = V_248 ;
struct V_52 * V_53 ;
if ( * V_54 != sizeof( struct V_260 ) ||
V_261 -> V_53 . V_91 >= V_92 -> V_116 ) {
V_22 = - V_25 ;
goto V_210;
}
F_14 ( V_12 ) ;
V_53 = V_52 ( V_92 , V_261 -> V_53 . V_91 ) ;
strncpy ( V_261 -> V_53 . V_6 , V_53 ? V_53 -> V_6 : L_27 ,
V_150 ) ;
F_10 ( V_12 ) ;
goto V_262;
}
default:
V_22 = - V_266 ;
goto V_210;
}
V_262:
V_22 = F_152 ( V_246 , V_248 , V_249 ) ;
V_210:
F_153 ( V_248 ) ;
if ( V_22 > 0 )
V_22 = 0 ;
return V_22 ;
}
static int T_8
F_154 ( struct V_2 * V_2 )
{
struct V_1 * V_92 = F_1 ( V_2 ) ;
struct V_52 * * V_26 ;
V_92 -> V_116 = V_267 ? V_267 : V_268 ;
if ( V_92 -> V_116 >= V_114 )
V_92 -> V_116 = V_114 - 1 ;
V_26 = F_102 ( V_92 -> V_116 , sizeof( struct V_52 * ) , V_31 ) ;
if ( ! V_26 )
return - V_149 ;
V_92 -> V_117 = false ;
V_92 -> V_161 = false ;
F_104 ( V_92 -> V_93 , V_26 ) ;
return 0 ;
}
static void T_9
F_155 ( struct V_2 * V_2 )
{
struct V_1 * V_92 = F_1 ( V_2 ) ;
struct V_52 * V_53 = NULL ;
T_6 V_113 ;
V_92 -> V_117 = true ;
for ( V_113 = 0 ; V_113 < V_92 -> V_116 ; V_113 ++ ) {
V_53 = V_52 ( V_92 , V_113 ) ;
if ( V_53 ) {
V_52 ( V_92 , V_113 ) = NULL ;
F_108 ( V_53 ) ;
}
}
F_106 ( F_156 ( V_92 -> V_93 , 1 ) ) ;
}
static int T_10
F_157 ( void )
{
int V_22 = F_158 ( & V_269 ) ;
if ( V_22 != 0 ) {
F_159 ( L_28 ) ;
return V_22 ;
}
V_22 = F_160 ( & V_270 ) ;
if ( V_22 != 0 ) {
F_159 ( L_29 , V_22 ) ;
F_161 ( & V_269 ) ;
return V_22 ;
}
V_22 = F_162 ( & V_271 ) ;
if ( V_22 ) {
F_159 ( L_30 ) ;
F_163 ( & V_270 ) ;
F_161 ( & V_269 ) ;
return V_22 ;
}
F_164 ( L_31 , V_24 ) ;
return 0 ;
}
static void T_11
F_165 ( void )
{
F_166 ( & V_271 ) ;
F_163 ( & V_270 ) ;
F_161 ( & V_269 ) ;
F_11 ( L_32 ) ;
}
