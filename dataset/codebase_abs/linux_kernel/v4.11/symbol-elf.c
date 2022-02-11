static inline char * F_1 ( void T_1 * V_1 , const char * V_2 , int V_3 )
{
return F_2 ( V_2 , V_3 ) ;
}
static inline char * F_1 ( void T_1 * V_1 ,
const char T_1 * V_2 ,
int T_1 V_3 )
{
return NULL ;
}
static int F_3 ( T_2 * V_4 , T_3 * V_5 )
{
T_4 V_6 ;
T_4 * V_7 ;
V_7 = F_4 ( V_4 , & V_6 ) ;
if ( ! V_7 )
return - 1 ;
* V_5 = V_7 -> V_8 ;
return 0 ;
}
static int F_5 ( T_2 * V_4 T_1 , T_3 * V_5 T_1 )
{
F_6 ( L_1 , V_9 ) ;
return - 1 ;
}
static inline T_5 F_7 ( const T_6 * V_10 )
{
return F_8 ( V_10 -> V_11 ) ;
}
static inline int F_9 ( const T_6 * V_10 )
{
return ( F_7 ( V_10 ) == V_12 ||
F_7 ( V_10 ) == V_13 ) &&
V_10 -> V_14 != 0 &&
V_10 -> V_15 != V_16 ;
}
static inline bool F_10 ( const T_6 * V_10 )
{
return F_7 ( V_10 ) == V_17 &&
V_10 -> V_14 != 0 &&
V_10 -> V_15 != V_16 ;
}
static inline int F_11 ( const T_6 * V_10 )
{
return F_7 ( V_10 ) == V_18 &&
V_10 -> V_14 != 0 &&
V_10 -> V_15 != V_16 &&
V_10 -> V_15 != V_19 ;
}
static bool F_12 ( T_6 * V_10 , enum V_20 type )
{
switch ( type ) {
case V_21 :
return F_9 ( V_10 ) ;
case V_22 :
return F_10 ( V_10 ) ;
default:
return false ;
}
}
static inline const char * F_13 ( const T_6 * V_10 ,
const T_7 * V_23 )
{
return V_23 -> V_24 + V_10 -> V_14 ;
}
static inline const char * F_14 ( const T_8 * V_25 ,
const T_7 * V_26 )
{
return V_26 -> V_24 + V_25 -> V_27 ;
}
static inline int F_15 ( const T_8 * V_25 ,
const T_7 * V_26 )
{
return strstr ( F_14 ( V_25 , V_26 ) , L_2 ) != NULL ;
}
static inline bool F_16 ( const T_8 * V_25 ,
const T_7 * V_26 )
{
return strstr ( F_14 ( V_25 , V_26 ) , L_3 ) != NULL ;
}
static bool F_17 ( T_8 * V_25 , T_7 * V_26 ,
enum V_20 type )
{
switch ( type ) {
case V_21 :
return F_15 ( V_25 , V_26 ) ;
case V_22 :
return F_16 ( V_25 , V_26 ) ;
default:
return false ;
}
}
static T_3 F_18 ( T_2 * V_4 , T_9 V_28 )
{
T_10 * V_29 = NULL ;
T_8 V_25 ;
T_3 V_30 = 1 ;
while ( ( V_29 = F_19 ( V_4 , V_29 ) ) != NULL ) {
F_20 ( V_29 , & V_25 ) ;
if ( ( V_28 >= V_25 . V_31 ) &&
( V_28 < ( V_25 . V_31 + V_25 . V_32 ) ) )
return V_30 ;
++ V_30 ;
}
return - 1 ;
}
T_10 * F_21 ( T_2 * V_4 , T_4 * V_33 ,
T_8 * V_34 , const char * V_35 , T_3 * V_36 )
{
T_10 * V_29 = NULL ;
T_3 V_30 = 1 ;
if ( ! F_22 ( F_23 ( V_4 , V_33 -> V_37 ) , NULL ) )
return NULL ;
while ( ( V_29 = F_19 ( V_4 , V_29 ) ) != NULL ) {
char * V_38 ;
F_20 ( V_29 , V_34 ) ;
V_38 = F_24 ( V_4 , V_33 -> V_37 , V_34 -> V_27 ) ;
if ( V_38 && ! strcmp ( V_35 , V_38 ) ) {
if ( V_36 )
* V_36 = V_30 ;
return V_29 ;
}
++ V_30 ;
}
return NULL ;
}
static bool F_25 ( bool V_39 )
{
return V_39 ? V_40 . V_41 : V_40 . V_42 ;
}
static char * F_26 ( struct V_43 * V_43 , int V_44 , const char * V_45 )
{
int V_46 = V_47 > 0 ? ( V_48 | V_49 ) : V_50 ;
char * V_51 = NULL ;
if ( ! F_25 ( V_43 -> V_52 || V_44 ) )
return V_51 ;
V_51 = F_1 ( NULL , V_45 , V_46 ) ;
if ( V_51 == NULL )
V_51 = F_27 ( V_45 , V_53 ) ;
else if ( F_28 ( V_51 ) )
F_29 ( V_51 ) ;
return V_51 ;
}
int F_30 ( struct V_43 * V_43 , struct V_54 * V_55 , struct V_56 * V_56 )
{
T_11 V_57 , V_36 ;
T_6 V_10 ;
T_12 V_58 ;
T_8 V_59 ;
struct V_60 * V_61 ;
T_8 V_62 , V_63 ;
T_7 * V_64 , * V_65 , * V_23 ;
T_10 * V_66 , * V_67 , * V_68 ;
T_3 V_69 ;
T_4 V_7 ;
char V_70 [ 1024 ] ;
T_2 * V_4 ;
int V_71 = 0 , V_72 , V_73 = 0 ;
if ( ! V_55 -> V_74 )
return 0 ;
V_4 = V_55 -> V_4 ;
V_7 = V_55 -> V_7 ;
V_68 = V_55 -> V_74 ;
V_63 = V_55 -> V_75 ;
V_69 = V_55 -> V_69 ;
if ( V_68 == NULL )
goto V_76;
V_66 = F_21 ( V_4 , & V_7 , & V_62 ,
L_4 , NULL ) ;
if ( V_66 == NULL ) {
V_66 = F_21 ( V_4 , & V_7 , & V_62 ,
L_5 , NULL ) ;
if ( V_66 == NULL )
goto V_76;
}
V_73 = - 1 ;
if ( V_62 . V_77 != V_69 )
goto V_76;
if ( F_21 ( V_4 , & V_7 , & V_59 , L_6 , NULL ) == NULL )
goto V_76;
V_64 = F_31 ( V_66 , NULL ) ;
if ( V_64 == NULL )
goto V_76;
V_65 = F_31 ( V_68 , NULL ) ;
if ( V_65 == NULL )
goto V_76;
V_67 = F_23 ( V_4 , V_63 . V_77 ) ;
if ( V_67 == NULL )
goto V_76;
V_23 = F_31 ( V_67 , NULL ) ;
if ( V_23 == NULL )
goto V_76;
if ( V_23 -> V_78 == 0 )
goto V_76;
V_57 = V_62 . V_32 / V_62 . V_79 ;
V_58 = V_59 . V_80 ;
if ( V_62 . V_81 == V_82 ) {
T_13 V_83 , * V_84 ;
F_32 (reldata, pos, pos_mem, idx,
nr_rel_entries) {
const char * V_45 = NULL ;
char * V_51 = NULL ;
V_72 = F_33 ( V_84 -> V_85 ) ;
V_58 += V_59 . V_79 ;
F_34 ( V_65 , V_72 , & V_10 ) ;
V_45 = F_13 ( & V_10 , V_23 ) ;
V_51 = F_26 ( V_43 , 0 , V_45 ) ;
if ( V_51 != NULL )
V_45 = V_51 ;
snprintf ( V_70 , sizeof( V_70 ) ,
L_7 , V_45 ) ;
free ( V_51 ) ;
V_61 = F_35 ( V_58 , V_59 . V_79 ,
V_86 , V_70 ) ;
if ( ! V_61 )
goto V_76;
F_36 ( & V_43 -> V_87 [ V_56 -> type ] , V_61 ) ;
++ V_71 ;
}
} else if ( V_62 . V_81 == V_88 ) {
T_14 V_83 , * V_84 ;
F_37 (reldata, pos, pos_mem, idx,
nr_rel_entries) {
const char * V_45 = NULL ;
char * V_51 = NULL ;
V_72 = F_33 ( V_84 -> V_85 ) ;
V_58 += V_59 . V_79 ;
F_34 ( V_65 , V_72 , & V_10 ) ;
V_45 = F_13 ( & V_10 , V_23 ) ;
V_51 = F_26 ( V_43 , 0 , V_45 ) ;
if ( V_51 != NULL )
V_45 = V_51 ;
snprintf ( V_70 , sizeof( V_70 ) ,
L_7 , V_45 ) ;
free ( V_51 ) ;
V_61 = F_35 ( V_58 , V_59 . V_79 ,
V_86 , V_70 ) ;
if ( ! V_61 )
goto V_76;
F_36 ( & V_43 -> V_87 [ V_56 -> type ] , V_61 ) ;
++ V_71 ;
}
}
V_73 = 0 ;
V_76:
if ( V_73 == 0 )
return V_71 ;
F_38 ( L_8 ,
V_9 , V_43 -> V_89 ) ;
return 0 ;
}
static int F_39 ( T_2 * V_4 , void * V_90 , T_3 V_91 )
{
int V_73 = - 1 ;
T_4 V_7 ;
T_8 V_25 ;
T_7 * V_92 ;
T_10 * V_29 ;
T_15 V_93 ;
void * V_94 ;
if ( V_91 < V_95 )
goto V_96;
V_93 = F_40 ( V_4 ) ;
if ( V_93 != V_97 )
goto V_96;
if ( F_4 ( V_4 , & V_7 ) == NULL ) {
F_6 ( L_9 , V_9 ) ;
goto V_96;
}
do {
V_29 = F_21 ( V_4 , & V_7 , & V_25 ,
L_10 , NULL ) ;
if ( V_29 )
break;
V_29 = F_21 ( V_4 , & V_7 , & V_25 ,
L_11 , NULL ) ;
if ( V_29 )
break;
V_29 = F_21 ( V_4 , & V_7 , & V_25 ,
L_12 , NULL ) ;
if ( V_29 )
break;
return V_73 ;
} while ( 0 );
V_92 = F_31 ( V_29 , NULL ) ;
if ( V_92 == NULL )
goto V_96;
V_94 = V_92 -> V_24 ;
while ( V_94 < ( V_92 -> V_24 + V_92 -> V_78 ) ) {
T_16 * V_98 = V_94 ;
T_3 V_99 = F_41 ( V_98 -> V_100 ) ,
V_101 = F_41 ( V_98 -> V_102 ) ;
const char * V_35 ;
V_94 += sizeof( * V_98 ) ;
V_35 = V_94 ;
V_94 += V_99 ;
if ( V_98 -> V_103 == V_104 &&
V_98 -> V_100 == sizeof( L_13 ) ) {
if ( memcmp ( V_35 , L_13 , sizeof( L_13 ) ) == 0 ) {
T_3 V_105 = F_42 ( V_91 , V_101 ) ;
memcpy ( V_90 , V_94 , V_105 ) ;
memset ( V_90 + V_105 , 0 , V_91 - V_105 ) ;
V_73 = V_101 ;
break;
}
}
V_94 += V_101 ;
}
V_96:
return V_73 ;
}
int F_43 ( const char * V_106 , void * V_90 , T_3 V_91 )
{
int V_107 , V_73 = - 1 ;
T_2 * V_4 ;
if ( V_91 < V_95 )
goto V_96;
V_107 = F_44 ( V_106 , V_108 ) ;
if ( V_107 < 0 )
goto V_96;
V_4 = F_45 ( V_107 , V_109 , NULL ) ;
if ( V_4 == NULL ) {
F_46 ( L_14 , V_9 , V_106 ) ;
goto V_110;
}
V_73 = F_39 ( V_4 , V_90 , V_91 ) ;
F_47 ( V_4 ) ;
V_110:
F_48 ( V_107 ) ;
V_96:
return V_73 ;
}
int F_49 ( const char * V_106 , void * V_111 , T_3 V_91 )
{
int V_107 , V_73 = - 1 ;
if ( V_91 < V_95 )
goto V_96;
V_107 = F_44 ( V_106 , V_108 ) ;
if ( V_107 < 0 )
goto V_96;
while ( 1 ) {
char V_90 [ V_112 ] ;
T_16 V_98 ;
T_3 V_99 , V_101 ;
if ( F_50 ( V_107 , & V_98 , sizeof( V_98 ) ) != sizeof( V_98 ) )
break;
V_99 = F_41 ( V_98 . V_100 ) ;
V_101 = F_41 ( V_98 . V_102 ) ;
if ( V_98 . V_103 == V_104 &&
V_98 . V_100 == sizeof( L_13 ) ) {
if ( F_50 ( V_107 , V_90 , V_99 ) != ( V_113 ) V_99 )
break;
if ( memcmp ( V_90 , L_13 , sizeof( L_13 ) ) == 0 ) {
T_3 V_105 = F_42 ( V_101 , V_91 ) ;
if ( F_50 ( V_107 , V_111 , V_105 ) == ( V_113 ) V_105 ) {
memset ( V_111 + V_105 , 0 , V_91 - V_105 ) ;
V_73 = 0 ;
break;
}
} else if ( F_50 ( V_107 , V_90 , V_101 ) != ( V_113 ) V_101 )
break;
} else {
int V_114 = V_99 + V_101 ;
if ( V_114 > ( int ) sizeof( V_90 ) ) {
V_114 = sizeof( V_90 ) ;
F_38 ( L_15 ,
V_9 , V_106 , V_98 . V_100 , V_98 . V_102 ) ;
}
if ( F_50 ( V_107 , V_90 , V_114 ) != V_114 )
break;
}
}
F_48 ( V_107 ) ;
V_96:
return V_73 ;
}
int F_51 ( const char * V_106 , char * V_115 ,
T_3 V_91 )
{
int V_107 , V_73 = - 1 ;
T_2 * V_4 ;
T_4 V_7 ;
T_8 V_25 ;
T_7 * V_92 ;
T_10 * V_29 ;
T_15 V_93 ;
V_107 = F_44 ( V_106 , V_108 ) ;
if ( V_107 < 0 )
goto V_96;
V_4 = F_45 ( V_107 , V_109 , NULL ) ;
if ( V_4 == NULL ) {
F_46 ( L_14 , V_9 , V_106 ) ;
goto V_110;
}
V_93 = F_40 ( V_4 ) ;
if ( V_93 != V_97 )
goto V_76;
if ( F_4 ( V_4 , & V_7 ) == NULL ) {
F_6 ( L_9 , V_9 ) ;
goto V_76;
}
V_29 = F_21 ( V_4 , & V_7 , & V_25 ,
L_16 , NULL ) ;
if ( V_29 == NULL )
goto V_76;
V_92 = F_31 ( V_29 , NULL ) ;
if ( V_92 == NULL )
goto V_76;
strncpy ( V_115 , V_92 -> V_24 , V_91 ) ;
V_73 = 0 ;
V_76:
F_47 ( V_4 ) ;
V_110:
F_48 ( V_107 ) ;
V_96:
return V_73 ;
}
static int F_52 ( struct V_43 * V_43 , unsigned char V_116 )
{
static unsigned int const V_117 = 1 ;
V_43 -> V_118 = V_119 ;
switch ( V_116 ) {
case V_120 :
if ( * ( unsigned char const * ) & V_117 != 1 )
V_43 -> V_118 = V_121 ;
break;
case V_122 :
if ( * ( unsigned char const * ) & V_117 != 0 )
V_43 -> V_118 = V_121 ;
break;
default:
F_6 ( L_17 , V_116 ) ;
return - V_123 ;
}
return 0 ;
}
static int F_53 ( struct V_43 * V_43 , const char * V_35 ,
enum V_124 type )
{
int V_107 = - 1 ;
char V_125 [] = L_18 ;
struct V_126 V_127 ;
if ( type != V_128 &&
type != V_129 &&
type != V_130 )
return - 1 ;
if ( type == V_130 )
V_35 = V_43 -> V_89 ;
if ( F_54 ( & V_127 , V_35 ) || ! V_127 . V_131 )
return - 1 ;
V_107 = F_55 ( V_125 ) ;
if ( V_107 < 0 ) {
V_43 -> V_132 = V_133 ;
goto V_96;
}
if ( ! F_56 ( V_127 . V_134 , V_35 , V_107 ) ) {
V_43 -> V_132 = V_135 ;
F_48 ( V_107 ) ;
V_107 = - 1 ;
}
F_57 ( V_125 ) ;
V_96:
free ( V_127 . V_134 ) ;
return V_107 ;
}
bool F_58 ( struct V_54 * V_55 )
{
return V_55 -> V_74 || V_55 -> V_136 ;
}
bool F_59 ( struct V_54 * V_55 )
{
return V_55 -> V_137 != NULL ;
}
void F_60 ( struct V_54 * V_55 )
{
F_61 ( & V_55 -> V_35 ) ;
F_47 ( V_55 -> V_4 ) ;
F_48 ( V_55 -> V_107 ) ;
}
bool __weak F_62 ( T_4 V_7 )
{
return V_7 . V_138 == V_139 || V_7 . V_138 == V_140 ;
}
int F_63 ( struct V_54 * V_55 , struct V_43 * V_43 , const char * V_35 ,
enum V_124 type )
{
int V_73 = - 1 ;
T_4 V_7 ;
T_2 * V_4 ;
int V_107 ;
if ( F_64 ( V_43 ) ) {
V_107 = F_53 ( V_43 , V_35 , type ) ;
if ( V_107 < 0 )
return - 1 ;
} else {
V_107 = F_44 ( V_35 , V_108 ) ;
if ( V_107 < 0 ) {
V_43 -> V_132 = V_133 ;
return - 1 ;
}
}
V_4 = F_45 ( V_107 , V_109 , NULL ) ;
if ( V_4 == NULL ) {
F_38 ( L_14 , V_9 , V_35 ) ;
V_43 -> V_132 = V_141 ;
goto V_110;
}
if ( F_4 ( V_4 , & V_7 ) == NULL ) {
V_43 -> V_132 = V_141 ;
F_38 ( L_9 , V_9 ) ;
goto V_76;
}
if ( F_52 ( V_43 , V_7 . V_142 [ V_143 ] ) ) {
V_43 -> V_132 = V_144 ;
goto V_76;
}
if ( V_43 -> V_145 && ! V_40 . V_146 ) {
T_17 V_111 [ V_95 ] ;
if ( F_39 ( V_4 , V_111 , V_95 ) < 0 ) {
V_43 -> V_132 = V_147 ;
goto V_76;
}
if ( ! F_65 ( V_43 , V_111 ) ) {
F_38 ( L_19 , V_9 , V_35 ) ;
V_43 -> V_132 = V_148 ;
goto V_76;
}
}
V_55 -> V_149 = ( F_66 ( V_4 ) == V_150 ) ;
V_55 -> V_137 = F_21 ( V_4 , & V_7 , & V_55 -> V_151 , L_20 ,
NULL ) ;
if ( V_55 -> V_151 . V_81 != V_152 )
V_55 -> V_137 = NULL ;
V_55 -> V_69 = 0 ;
V_55 -> V_74 = F_21 ( V_4 , & V_7 , & V_55 -> V_75 , L_21 ,
& V_55 -> V_69 ) ;
if ( V_55 -> V_75 . V_81 != V_153 )
V_55 -> V_74 = NULL ;
V_55 -> V_154 = 0 ;
V_55 -> V_136 = F_21 ( V_4 , & V_7 , & V_55 -> V_155 , L_22 ,
& V_55 -> V_154 ) ;
if ( V_55 -> V_155 . V_81 != V_156 )
V_55 -> V_136 = NULL ;
if ( V_43 -> V_52 == V_157 )
V_55 -> V_158 = true ;
else
V_55 -> V_158 = F_62 ( V_7 ) ;
V_55 -> V_35 = F_67 ( V_35 ) ;
if ( ! V_55 -> V_35 ) {
V_43 -> V_132 = V_133 ;
goto V_76;
}
V_55 -> V_4 = V_4 ;
V_55 -> V_107 = V_107 ;
V_55 -> V_7 = V_7 ;
V_55 -> type = type ;
return 0 ;
V_76:
F_47 ( V_4 ) ;
V_110:
F_48 ( V_107 ) ;
return V_73 ;
}
static bool F_68 ( struct V_159 * V_159 )
{
return V_159 && V_159 -> V_160 && V_159 -> V_160 -> V_35 &&
! V_159 -> V_160 -> V_161 ;
}
static T_12 F_69 ( struct V_159 * V_159 )
{
if ( V_159 && V_159 -> V_160 &&
V_159 -> V_160 -> V_161 )
return V_159 -> V_160 -> V_28 -
V_159 -> V_160 -> V_161 ;
return 0 ;
}
void __weak F_70 ( struct V_60 * T_18 T_1 ,
T_6 * V_10 T_1 ) { }
int F_71 ( struct V_43 * V_43 , struct V_56 * V_56 , struct V_54 * V_162 ,
struct V_54 * V_163 , int V_44 )
{
struct V_159 * V_159 = V_43 -> V_52 ? F_72 ( V_56 ) : NULL ;
struct V_164 * V_165 = V_159 ? F_73 ( V_56 ) : NULL ;
struct V_56 * V_166 = V_56 ;
struct V_43 * V_167 = V_43 ;
T_7 * V_23 , * V_26 ;
T_11 V_168 ;
int V_73 = - 1 ;
T_11 V_36 ;
T_4 V_7 ;
T_8 V_25 ;
T_8 V_169 ;
T_7 * V_65 , * V_170 = NULL ;
T_6 V_10 ;
T_10 * V_29 , * V_171 ;
T_2 * V_4 ;
int V_71 = 0 ;
bool V_172 = false , V_173 = false ;
if ( V_159 && ! V_165 )
return - 1 ;
V_43 -> V_174 = V_162 -> type ;
V_43 -> V_149 = V_162 -> V_149 ;
V_43 -> V_175 = V_162 -> V_7 . V_138 == V_140 ;
if ( V_44 && V_162 -> V_137 )
F_74 ( & V_43 -> V_87 [ V_56 -> type ] ) ;
if ( ! V_162 -> V_137 ) {
if ( V_43 -> V_52 )
goto V_76;
V_162 -> V_137 = V_162 -> V_74 ;
V_162 -> V_151 = V_162 -> V_75 ;
}
V_4 = V_162 -> V_4 ;
V_7 = V_162 -> V_7 ;
V_29 = V_162 -> V_137 ;
V_25 = V_162 -> V_151 ;
if ( F_21 ( V_163 -> V_4 , & V_163 -> V_7 , & V_169 ,
L_23 , NULL ) )
V_43 -> V_176 = V_169 . V_31 - V_169 . V_80 ;
if ( V_163 -> V_136 )
V_170 = F_22 ( V_163 -> V_136 , NULL ) ;
V_65 = F_31 ( V_29 , NULL ) ;
if ( V_65 == NULL )
goto V_76;
V_29 = F_23 ( V_4 , V_25 . V_77 ) ;
if ( V_29 == NULL )
goto V_76;
V_23 = F_31 ( V_29 , NULL ) ;
if ( V_23 == NULL )
goto V_76;
V_171 = F_23 ( V_163 -> V_4 , V_163 -> V_7 . V_37 ) ;
if ( V_171 == NULL )
goto V_76;
V_26 = F_31 ( V_171 , NULL ) ;
if ( V_26 == NULL )
goto V_76;
V_168 = V_25 . V_32 / V_25 . V_79 ;
memset ( & V_10 , 0 , sizeof( V_10 ) ) ;
if ( F_68 ( V_159 ) ) {
F_75 (syms, nr_syms, idx, sym) {
const char * V_45 = F_13 ( & V_10 , V_23 ) ;
if ( strcmp ( V_45 , V_159 -> V_160 -> V_35 ) )
continue;
V_159 -> V_160 -> V_161 = V_10 . V_177 ;
V_56 -> V_178 = V_159 -> V_160 -> V_28 -
V_159 -> V_160 -> V_161 ;
break;
}
}
if ( F_76 ( V_43 ) )
V_56 -> V_178 = V_56 -> V_179 - V_43 -> V_176 ;
V_43 -> V_158 = V_163 -> V_158 || F_69 ( V_159 ) ;
if ( V_56 -> type == V_21 && ( V_43 -> V_52 || V_44 ) ) {
V_172 = true ;
V_173 = V_43 -> V_158 ;
}
F_75 (syms, nr_syms, idx, sym) {
struct V_60 * V_61 ;
const char * V_45 = F_13 ( & V_10 , V_23 ) ;
char * V_51 = NULL ;
int V_180 = F_11 ( & V_10 ) ;
const char * V_181 ;
bool V_182 = false ;
if ( ! V_180 && ! F_12 ( & V_10 , V_56 -> type ) )
continue;
if ( V_7 . V_183 == V_184 || V_7 . V_183 == V_185 ) {
if ( V_45 [ 0 ] == '$' && strchr ( L_24 , V_45 [ 1 ] )
&& ( V_45 [ 2 ] == '\0' || V_45 [ 2 ] == '.' ) )
continue;
}
if ( V_163 -> V_136 && V_10 . V_15 == V_163 -> V_154 ) {
T_19 V_186 = V_10 . V_177 - V_162 -> V_155 . V_31 ;
T_12 * V_187 = V_170 -> V_24 + V_186 ;
V_10 . V_177 = F_77 ( V_43 , T_12 , * V_187 ) ;
V_10 . V_15 = F_18 ( V_163 -> V_4 ,
V_10 . V_177 ) ;
V_182 = true ;
}
if ( V_10 . V_15 == V_19 )
continue;
V_29 = F_23 ( V_163 -> V_4 , V_10 . V_15 ) ;
if ( ! V_29 )
goto V_76;
F_20 ( V_29 , & V_25 ) ;
if ( V_180 && ! F_17 ( & V_25 , V_26 , V_56 -> type ) )
continue;
V_181 = F_14 ( & V_25 , V_26 ) ;
if ( ( V_7 . V_183 == V_184 ) &&
( V_56 -> type == V_21 ) &&
( V_10 . V_177 & 1 ) )
-- V_10 . V_177 ;
if ( V_43 -> V_52 || V_44 ) {
char V_188 [ V_189 ] ;
if ( V_173 )
V_10 . V_177 -= V_25 . V_31 - V_25 . V_80 ;
if ( strcmp ( V_181 ,
( V_167 -> V_190 +
V_43 -> V_191 ) ) == 0 )
goto V_192;
if ( strcmp ( V_181 , L_23 ) == 0 ) {
if ( V_172 && V_43 -> V_52 ) {
V_172 = false ;
V_56 -> V_179 = V_25 . V_31 +
F_69 ( V_159 ) ;
V_56 -> V_193 = V_56 -> V_179 + V_25 . V_32 ;
V_56 -> V_194 = V_25 . V_80 ;
V_56 -> V_195 = V_196 ;
V_56 -> V_197 = V_198 ;
if ( V_165 ) {
F_78 ( V_56 ) ;
F_79 ( V_165 , V_56 ) ;
F_80 ( V_165 , V_56 ) ;
F_81 ( V_56 ) ;
}
}
if ( V_172 && V_44 ) {
V_172 = false ;
V_56 -> V_194 = V_25 . V_80 ;
}
V_166 = V_56 ;
V_167 = V_43 ;
goto V_192;
}
if ( ! V_159 )
goto V_192;
snprintf ( V_188 , sizeof( V_188 ) ,
L_25 , V_43 -> V_190 , V_181 ) ;
V_166 = F_82 ( V_165 , V_56 -> type , V_188 ) ;
if ( V_166 == NULL ) {
T_12 V_179 = V_10 . V_177 ;
if ( V_44 )
V_179 += V_56 -> V_179 + V_25 . V_80 ;
V_167 = F_83 ( V_188 ) ;
if ( V_167 == NULL )
goto V_76;
V_167 -> V_52 = V_43 -> V_52 ;
V_167 -> V_89 = V_43 -> V_89 ;
V_167 -> V_199 = V_43 -> V_199 ;
V_166 = F_84 ( V_179 , V_167 ,
V_56 -> type ) ;
F_85 ( V_167 ) ;
if ( V_166 == NULL ) {
goto V_76;
}
if ( V_173 ) {
V_166 -> V_179 = V_25 . V_31 +
F_69 ( V_159 ) ;
V_166 -> V_193 = V_166 -> V_179 +
V_25 . V_32 ;
V_166 -> V_194 = V_25 . V_80 ;
} else {
V_166 -> V_195 = V_200 ;
V_166 -> V_197 = V_200 ;
}
V_167 -> V_174 = V_43 -> V_174 ;
F_80 ( V_165 , V_166 ) ;
F_86 ( & V_56 -> V_201 -> V_202 -> V_203 , V_167 ) ;
F_81 ( V_166 ) ;
F_87 ( V_167 , V_56 -> type ) ;
} else
V_167 = V_166 -> V_43 ;
goto V_192;
}
if ( ( V_182 && V_163 -> V_158 )
|| ( ! V_182 && V_162 -> V_158 ) ) {
F_88 ( L_26 V_204 L_27
L_28 V_204 L_29 V_204 L_30 , V_9 ,
( T_12 ) V_10 . V_177 , ( T_12 ) V_25 . V_31 ,
( T_12 ) V_25 . V_80 ) ;
V_10 . V_177 -= V_25 . V_31 - V_25 . V_80 ;
}
V_192:
V_51 = F_26 ( V_43 , V_44 , V_45 ) ;
if ( V_51 != NULL )
V_45 = V_51 ;
V_61 = F_35 ( V_10 . V_177 , V_10 . V_205 ,
F_89 ( V_10 . V_11 ) , V_45 ) ;
free ( V_51 ) ;
if ( ! V_61 )
goto V_76;
F_70 ( V_61 , & V_10 ) ;
F_90 ( & V_167 -> V_87 [ V_166 -> type ] , V_61 , V_43 -> V_52 ) ;
V_71 ++ ;
}
if ( V_71 > 0 ) {
F_91 ( & V_43 -> V_87 [ V_56 -> type ] ) ;
F_92 ( & V_43 -> V_87 [ V_56 -> type ] ) ;
if ( V_159 ) {
F_93 ( V_165 , V_56 -> type ) ;
}
}
V_73 = V_71 ;
V_76:
return V_73 ;
}
static int F_94 ( T_2 * V_4 , bool V_206 , T_20 V_207 , void * V_92 )
{
T_21 V_208 ;
T_3 V_3 , V_209 ;
int V_73 ;
T_12 V_105 ;
if ( F_3 ( V_4 , & V_209 ) )
return - 1 ;
for ( V_3 = 0 ; V_3 < V_209 ; V_3 ++ ) {
if ( F_95 ( V_4 , V_3 , & V_208 ) == NULL )
return - 1 ;
if ( V_208 . V_210 != V_211 )
continue;
if ( V_206 ) {
if ( ! ( V_208 . V_212 & V_213 ) )
continue;
} else {
if ( ! ( V_208 . V_212 & V_214 ) )
continue;
}
V_105 = F_42 ( V_208 . V_215 , V_208 . V_216 ) ;
if ( ! V_105 )
continue;
V_73 = V_207 ( V_208 . V_217 , V_105 , V_208 . V_218 , V_92 ) ;
if ( V_73 )
return V_73 ;
}
return 0 ;
}
int F_96 ( int V_107 , bool V_206 , T_20 V_207 , void * V_92 ,
bool * V_149 )
{
int V_73 ;
T_2 * V_4 ;
V_4 = F_45 ( V_107 , V_109 , NULL ) ;
if ( V_4 == NULL )
return - 1 ;
if ( V_149 )
* V_149 = ( F_66 ( V_4 ) == V_150 ) ;
V_73 = F_94 ( V_4 , V_206 , V_207 , V_92 ) ;
F_47 ( V_4 ) ;
return V_73 ;
}
enum V_219 F_97 ( int V_107 )
{
enum V_219 V_219 = V_220 ;
T_4 V_7 ;
T_15 V_93 ;
T_2 * V_4 ;
V_4 = F_45 ( V_107 , V_109 , NULL ) ;
if ( V_4 == NULL )
goto V_96;
V_93 = F_40 ( V_4 ) ;
if ( V_93 != V_97 )
goto V_221;
if ( F_66 ( V_4 ) == V_150 ) {
V_219 = V_222 ;
goto V_221;
}
if ( F_4 ( V_4 , & V_7 ) == NULL )
goto V_221;
if ( V_7 . V_183 == V_223 )
V_219 = V_224 ;
else
V_219 = V_225 ;
V_221:
F_47 ( V_4 ) ;
V_96:
return V_219 ;
}
static int F_98 ( int V_226 , T_22 V_227 , int V_228 , T_22 V_229 , T_12 V_230 )
{
V_113 V_231 ;
T_3 V_114 ;
int V_73 = - 1 ;
char * V_232 = malloc ( V_233 ) ;
if ( V_232 == NULL )
return - 1 ;
if ( F_99 ( V_228 , V_229 , V_234 ) != V_229 )
goto V_96;
if ( F_99 ( V_226 , V_227 , V_234 ) != V_227 )
goto V_96;
while ( V_230 ) {
V_114 = V_233 ;
if ( V_230 < V_114 )
V_114 = V_230 ;
V_231 = F_50 ( V_226 , V_232 , V_114 ) ;
if ( V_231 < 0 )
goto V_96;
if ( ! V_231 )
break;
V_114 = V_231 ;
V_231 = F_100 ( V_228 , V_232 , V_114 ) ;
if ( V_231 < 0 )
goto V_96;
if ( ( T_3 ) V_231 != V_114 )
goto V_96;
V_230 -= V_114 ;
}
V_73 = 0 ;
V_96:
free ( V_232 ) ;
return V_73 ;
}
static int F_101 ( struct V_235 * V_235 , const char * V_106 )
{
T_4 * V_7 ;
V_235 -> V_107 = F_44 ( V_106 , V_108 ) ;
if ( V_235 -> V_107 == - 1 )
return - 1 ;
V_235 -> V_4 = F_45 ( V_235 -> V_107 , V_236 , NULL ) ;
if ( ! V_235 -> V_4 )
goto V_110;
V_235 -> V_237 = F_66 ( V_235 -> V_4 ) ;
if ( V_235 -> V_237 == V_238 )
goto V_221;
V_7 = F_4 ( V_235 -> V_4 , & V_235 -> V_7 ) ;
if ( ! V_7 )
goto V_221;
return 0 ;
V_221:
F_47 ( V_235 -> V_4 ) ;
V_110:
F_48 ( V_235 -> V_107 ) ;
return - 1 ;
}
static int F_102 ( struct V_235 * V_235 , char * V_106 , int V_237 ,
bool V_239 )
{
V_235 -> V_237 = V_237 ;
if ( V_239 )
V_235 -> V_107 = F_55 ( V_106 ) ;
else
V_235 -> V_107 = F_44 ( V_106 , V_240 | V_241 | V_242 , 0400 ) ;
if ( V_235 -> V_107 == - 1 )
return - 1 ;
V_235 -> V_4 = F_45 ( V_235 -> V_107 , V_243 , NULL ) ;
if ( ! V_235 -> V_4 )
goto V_110;
if ( ! F_103 ( V_235 -> V_4 , V_237 ) )
goto V_221;
memset ( & V_235 -> V_7 , 0 , sizeof( T_4 ) ) ;
return 0 ;
V_221:
F_47 ( V_235 -> V_4 ) ;
V_110:
F_48 ( V_235 -> V_107 ) ;
F_57 ( V_106 ) ;
return - 1 ;
}
static void F_104 ( struct V_235 * V_235 )
{
F_47 ( V_235 -> V_4 ) ;
F_48 ( V_235 -> V_107 ) ;
}
static int F_105 ( struct V_235 * V_226 , struct V_235 * V_228 , T_3 V_244 )
{
T_4 * V_7 = & V_228 -> V_7 ;
T_4 * V_245 = & V_226 -> V_7 ;
memcpy ( V_7 -> V_142 , V_245 -> V_142 , V_246 ) ;
V_7 -> V_138 = V_245 -> V_138 ;
V_7 -> V_183 = V_245 -> V_183 ;
V_7 -> V_247 = V_245 -> V_247 ;
V_7 -> V_248 = 0 ;
V_7 -> V_249 = 0 ;
V_7 -> V_250 = V_245 -> V_250 ;
V_7 -> V_8 = V_244 ;
V_7 -> V_251 = 0 ;
V_7 -> V_252 = 0 ;
V_7 -> V_37 = 0 ;
if ( V_226 -> V_237 == V_253 ) {
V_7 -> V_254 = sizeof( V_255 ) ;
V_7 -> V_256 = sizeof( V_255 ) ;
V_7 -> V_257 = sizeof( V_258 ) ;
} else {
V_7 -> V_254 = sizeof( V_259 ) ;
V_7 -> V_256 = sizeof( V_259 ) ;
V_7 -> V_257 = sizeof( V_260 ) ;
}
if ( ! F_106 ( V_228 -> V_4 , V_7 ) )
return - 1 ;
if ( ! F_107 ( V_228 -> V_4 , V_244 ) )
return - 1 ;
return 0 ;
}
static int F_108 ( struct V_235 * V_235 , int V_36 , T_22 V_186 ,
T_12 V_28 , T_12 V_230 )
{
T_21 V_208 = {
. V_210 = V_211 ,
. V_212 = V_214 | V_261 | V_213 ,
. V_218 = V_186 ,
. V_217 = V_28 ,
. V_262 = 0 ,
. V_216 = V_230 ,
. V_215 = V_230 ,
. V_263 = V_233 ,
} ;
if ( ! F_109 ( V_235 -> V_4 , V_36 , & V_208 ) )
return - 1 ;
return 0 ;
}
static T_22 F_110 ( struct V_235 * V_235 )
{
return F_111 ( V_235 -> V_4 , V_243 ) ;
}
static int F_112 ( void * V_264 , const char * V_35 , char type ,
T_12 V_179 )
{
struct V_265 * V_266 = V_264 ;
if ( ! F_113 ( type , V_21 ) )
return 0 ;
if ( strchr ( V_35 , '[' ) ) {
if ( V_179 > V_266 -> V_267 )
V_266 -> V_267 = V_179 ;
return 0 ;
}
if ( ! V_266 -> V_268 || V_179 < V_266 -> V_268 )
V_266 -> V_268 = V_179 ;
if ( ! V_266 -> V_269 || V_179 > V_266 -> V_269 )
V_266 -> V_269 = V_179 ;
if ( ! strcmp ( V_35 , L_31 ) ) {
V_266 -> V_270 = V_179 ;
return 0 ;
}
if ( ! strcmp ( V_35 , L_32 ) ) {
V_266 -> V_271 = V_179 ;
return 0 ;
}
return 0 ;
}
static int F_114 ( struct V_265 * V_266 ,
const char * V_272 )
{
char V_273 [ V_189 ] ;
F_115 ( V_273 , V_189 , L_33 , V_272 ) ;
if ( F_116 ( V_273 , L_34 ) )
return - 1 ;
if ( F_117 ( V_273 , V_266 ,
F_112 ) < 0 )
return - 1 ;
return 0 ;
}
static int F_118 ( void * V_264 ,
const char * V_35 T_1 ,
T_12 V_179 )
{
struct V_265 * V_266 = V_264 ;
if ( ! V_266 -> V_274 || V_179 < V_266 -> V_274 )
V_266 -> V_274 = V_179 ;
return 0 ;
}
static int F_119 ( struct V_265 * V_266 ,
const char * V_272 )
{
char V_275 [ V_189 ] ;
F_115 ( V_275 , V_189 , L_35 , V_272 ) ;
if ( F_116 ( V_275 , L_36 ) )
return - 1 ;
if ( F_120 ( V_275 , V_266 ,
F_118 ) < 0 )
return - 1 ;
return 0 ;
}
static void F_121 ( struct V_276 * V_277 , T_12 V_179 , T_12 V_193 , T_12 V_194 ,
T_12 T_18 , T_12 V_278 )
{
if ( V_277 -> V_28 || T_18 < V_179 || T_18 >= V_193 )
return;
V_277 -> V_28 = T_18 ;
V_277 -> V_186 = ( T_18 - V_179 ) + V_194 ;
V_277 -> V_230 = V_278 < V_193 ? V_278 - T_18 : V_193 - T_18 ;
}
static int F_122 ( T_12 V_179 , T_12 V_230 , T_12 V_194 , void * V_92 )
{
struct V_265 * V_266 = V_92 ;
T_12 V_193 = V_179 + V_230 ;
F_121 ( & V_266 -> V_279 , V_179 , V_193 , V_194 , V_266 -> V_270 ,
V_266 -> V_271 ) ;
F_121 ( & V_266 -> V_280 , V_179 , V_193 , V_194 , V_266 -> V_274 ,
V_266 -> V_267 ) ;
return 0 ;
}
static int F_123 ( struct V_265 * V_266 , T_2 * V_4 )
{
if ( F_94 ( V_4 , true , F_122 , V_266 ) < 0 )
return - 1 ;
return 0 ;
}
static int F_124 ( struct V_265 * V_266 , const char * V_272 ,
T_2 * V_4 )
{
if ( F_114 ( V_266 , V_272 ) )
return - 1 ;
if ( F_119 ( V_266 , V_272 ) )
return - 1 ;
if ( V_266 -> V_270 )
V_266 -> V_270 = F_125 ( V_266 -> V_270 , V_233 ) ;
else
V_266 -> V_270 = F_125 ( V_266 -> V_268 , V_233 ) ;
if ( V_266 -> V_271 ) {
V_266 -> V_271 = F_126 ( V_266 -> V_271 , V_233 ) ;
} else if ( V_266 -> V_269 ) {
V_266 -> V_271 = F_126 ( V_266 -> V_269 , V_233 ) ;
V_266 -> V_271 += V_233 ;
}
V_266 -> V_274 = F_125 ( V_266 -> V_274 , V_233 ) ;
if ( V_266 -> V_267 ) {
V_266 -> V_267 = F_126 ( V_266 -> V_267 ,
V_233 ) ;
V_266 -> V_267 += V_233 ;
}
if ( ! V_266 -> V_270 || ! V_266 -> V_271 )
return - 1 ;
if ( V_266 -> V_274 && ! V_266 -> V_267 )
return - 1 ;
return F_123 ( V_266 , V_4 ) ;
}
static int F_127 ( const char * V_281 , const char * V_282 ,
const char * V_35 )
{
char V_283 [ V_189 ] ;
char V_284 [ V_189 ] ;
F_115 ( V_283 , V_189 , L_37 , V_281 , V_35 ) ;
F_115 ( V_284 , V_189 , L_37 , V_282 , V_35 ) ;
return F_128 ( V_283 , V_284 , 0400 ) ;
}
static int F_129 ( const char * V_272 , const char * V_35 )
{
char V_106 [ V_189 ] ;
F_115 ( V_106 , V_189 , L_37 , V_272 , V_35 ) ;
return F_57 ( V_106 ) ;
}
static int F_130 ( int V_226 , int V_228 )
{
char * V_285 ;
char * V_286 ;
V_113 V_287 ;
T_3 V_230 ;
int V_73 = - 1 ;
V_285 = malloc ( V_233 ) ;
V_286 = malloc ( V_233 ) ;
if ( ! V_285 || ! V_286 )
goto V_96;
while ( 1 ) {
V_287 = F_50 ( V_226 , V_285 , V_233 ) ;
if ( V_287 < 0 )
goto V_96;
if ( ! V_287 )
break;
V_230 = V_287 ;
if ( F_131 ( V_228 , V_286 , V_230 ) != ( int ) V_230 )
goto V_96;
if ( memcmp ( V_285 , V_286 , V_230 ) )
goto V_96;
}
V_73 = 0 ;
V_96:
free ( V_286 ) ;
free ( V_285 ) ;
return V_73 ;
}
static int F_132 ( const char * V_283 ,
const char * V_284 )
{
int V_226 , V_228 , V_73 = - 1 ;
V_226 = F_44 ( V_283 , V_108 ) ;
if ( V_226 < 0 )
return - 1 ;
V_228 = F_44 ( V_284 , V_108 ) ;
if ( V_228 < 0 )
goto V_288;
V_73 = F_130 ( V_226 , V_228 ) ;
F_48 ( V_228 ) ;
V_288:
F_48 ( V_226 ) ;
return V_73 ;
}
static int F_133 ( const char * V_281 , const char * V_282 ,
const char * V_35 )
{
char V_283 [ V_189 ] ;
char V_284 [ V_189 ] ;
F_115 ( V_283 , V_189 , L_37 , V_281 , V_35 ) ;
F_115 ( V_284 , V_189 , L_37 , V_282 , V_35 ) ;
return F_132 ( V_283 , V_284 ) ;
}
int F_134 ( const char * V_281 , const char * V_282 )
{
struct V_235 V_235 ;
struct V_235 V_289 ;
T_3 V_244 = 2 ;
int V_36 = 0 , V_73 = - 1 ;
T_22 V_186 = V_233 , V_105 , V_290 = 0 ;
struct V_265 V_266 = { . V_270 = 0 , } ;
char V_291 [ V_189 ] ;
char V_292 [ V_189 ] ;
if ( F_127 ( V_281 , V_282 , L_38 ) )
return - 1 ;
if ( F_127 ( V_281 , V_282 , L_39 ) )
goto V_293;
F_115 ( V_291 , V_189 , L_40 , V_281 ) ;
F_115 ( V_292 , V_189 , L_40 , V_282 ) ;
if ( F_101 ( & V_235 , V_291 ) )
goto V_294;
if ( F_124 ( & V_266 , V_281 , V_235 . V_4 ) )
goto V_295;
if ( F_102 ( & V_289 , V_292 , V_235 . V_237 , false ) )
goto V_295;
if ( ! V_266 . V_280 . V_28 )
V_244 -= 1 ;
if ( F_105 ( & V_235 , & V_289 , V_244 ) )
goto V_296;
if ( F_108 ( & V_289 , V_36 ++ , V_186 , V_266 . V_279 . V_28 ,
V_266 . V_279 . V_230 ) )
goto V_296;
if ( V_266 . V_280 . V_28 ) {
V_290 = V_186 + V_266 . V_279 . V_230 ;
if ( F_108 ( & V_289 , V_36 , V_290 ,
V_266 . V_280 . V_28 , V_266 . V_280 . V_230 ) )
goto V_296;
}
V_105 = F_110 ( & V_289 ) ;
if ( V_105 < 0 || V_105 > V_186 )
goto V_296;
if ( F_98 ( V_235 . V_107 , V_266 . V_279 . V_186 , V_289 . V_107 , V_186 ,
V_266 . V_279 . V_230 ) )
goto V_296;
if ( V_290 && F_98 ( V_235 . V_107 , V_266 . V_280 . V_186 ,
V_289 . V_107 , V_290 ,
V_266 . V_280 . V_230 ) )
goto V_296;
if ( F_133 ( V_281 , V_282 , L_39 ) )
goto V_296;
if ( F_133 ( V_281 , V_282 , L_38 ) )
goto V_296;
V_73 = 0 ;
V_296:
F_104 ( & V_289 ) ;
if ( V_73 )
F_57 ( V_292 ) ;
V_295:
F_104 ( & V_235 ) ;
V_294:
if ( V_73 )
F_129 ( V_282 , L_39 ) ;
V_293:
if ( V_73 )
F_129 ( V_282 , L_38 ) ;
return V_73 ;
}
int F_135 ( struct V_297 * V_298 )
{
struct V_235 V_235 ;
struct V_235 V_289 ;
T_3 V_244 = 1 ;
int V_36 = 0 , V_73 = - 1 ;
T_22 V_186 = V_233 , V_105 ;
if ( F_101 ( & V_235 , V_298 -> V_291 ) )
return - 1 ;
strcpy ( V_298 -> V_292 , V_299 ) ;
if ( F_102 ( & V_289 , V_298 -> V_292 , V_235 . V_237 , true ) )
goto V_295;
if ( F_105 ( & V_235 , & V_289 , V_244 ) )
goto V_296;
if ( F_108 ( & V_289 , V_36 , V_186 , V_298 -> V_28 , V_298 -> V_230 ) )
goto V_296;
V_105 = F_110 ( & V_289 ) ;
if ( V_105 < 0 || V_105 > V_186 )
goto V_296;
if ( F_98 ( V_235 . V_107 , V_298 -> V_300 , V_289 . V_107 , V_186 , V_298 -> V_230 ) )
goto V_296;
V_73 = 0 ;
V_296:
F_104 ( & V_289 ) ;
if ( V_73 )
F_57 ( V_298 -> V_292 ) ;
V_295:
F_104 ( & V_235 ) ;
return V_73 ;
}
void F_136 ( struct V_297 * V_298 )
{
F_57 ( V_298 -> V_292 ) ;
}
static int F_137 ( T_2 * * V_4 , const char * V_92 , T_3 V_230 ,
struct V_301 * V_302 )
{
const char * V_303 , * V_35 ;
struct V_304 * V_305 = NULL ;
T_4 V_7 ;
T_9 V_306 = 0 ;
T_8 V_25 ;
int V_287 = - V_123 ;
union {
T_23 V_307 [ V_308 ] ;
T_24 V_309 [ V_308 ] ;
} V_232 ;
T_7 V_5 = {
. V_24 = & V_232 , . V_310 = V_311 , . V_312 = V_313 ,
. V_78 = F_138 ( ( * V_4 ) , V_311 , V_308 , V_313 ) ,
. V_314 = 0 , . V_315 = 0
} ;
T_7 V_316 = {
. V_24 = ( void * ) V_92 , . V_310 = V_311 ,
. V_312 = V_313 , . V_78 = V_5 . V_78 , . V_314 = 0 ,
. V_315 = 0
} ;
V_305 = (struct V_304 * ) calloc ( 1 , sizeof( struct V_304 ) ) ;
if ( ! V_305 ) {
V_287 = - V_317 ;
goto V_318;
}
F_139 ( & V_305 -> V_319 ) ;
if ( V_230 < V_5 . V_78 + 3 )
goto V_320;
if ( F_140 ( * V_4 , & V_5 , & V_316 ,
F_141 ( * V_4 , NULL ) [ V_143 ] ) == NULL ) {
F_6 ( L_41 , F_142 ( - 1 ) ) ;
goto V_320;
}
V_303 = V_92 + V_5 . V_78 ;
V_35 = ( const char * ) memchr ( V_303 , '\0' , V_92 + V_230 - V_303 ) ;
if ( V_35 ++ == NULL )
goto V_320;
V_305 -> V_303 = F_67 ( V_303 ) ;
if ( ! V_305 -> V_303 ) {
V_287 = - V_317 ;
goto V_320;
}
V_305 -> V_35 = F_67 ( V_35 ) ;
if ( ! V_305 -> V_35 ) {
V_287 = - V_317 ;
goto V_321;
}
if ( F_66 ( * V_4 ) == V_253 ) {
memcpy ( & V_305 -> V_28 , & V_232 , 3 * sizeof( T_24 ) ) ;
V_305 -> V_322 = true ;
} else {
memcpy ( & V_305 -> V_28 , & V_232 , 3 * sizeof( T_23 ) ) ;
V_305 -> V_322 = false ;
}
if ( ! F_4 ( * V_4 , & V_7 ) ) {
F_38 ( L_42 , V_9 ) ;
V_287 = - V_323 ;
goto V_324;
}
if ( F_21 ( * V_4 , & V_7 , & V_25 , V_325 , NULL ) ) {
V_306 = V_25 . V_80 ;
if ( V_306 ) {
if ( V_305 -> V_322 )
V_305 -> V_28 . V_309 [ 0 ] = V_305 -> V_28 . V_309 [ 0 ] + V_306 -
V_305 -> V_28 . V_309 [ 1 ] ;
else
V_305 -> V_28 . V_307 [ 0 ] = V_305 -> V_28 . V_307 [ 0 ] + V_306 -
V_305 -> V_28 . V_307 [ 1 ] ;
}
}
F_143 ( & V_305 -> V_319 , V_302 ) ;
return 0 ;
V_324:
free ( V_305 -> V_35 ) ;
V_321:
free ( V_305 -> V_303 ) ;
V_320:
free ( V_305 ) ;
V_318:
return V_287 ;
}
static int F_144 ( T_2 * V_4 , struct V_301 * V_302 )
{
T_4 V_7 ;
T_10 * V_326 = NULL ;
T_7 * V_92 ;
T_8 V_25 ;
T_3 V_327 , V_328 ;
T_16 V_98 ;
T_3 V_329 , V_330 , V_186 ;
int V_287 = 0 ;
if ( F_4 ( V_4 , & V_7 ) == NULL ) {
V_287 = - V_323 ;
goto V_331;
}
if ( F_5 ( V_4 , & V_327 ) != 0 ) {
V_287 = - V_323 ;
goto V_331;
}
V_326 = F_21 ( V_4 , & V_7 , & V_25 , V_332 , NULL ) ;
if ( ! V_326 ) {
V_287 = - V_333 ;
goto V_331;
}
if ( ( V_25 . V_81 != V_334 ) || ( V_25 . V_335 & V_336 ) ) {
V_287 = - V_333 ;
goto V_331;
}
V_92 = F_31 ( V_326 , NULL ) ;
for ( V_186 = 0 ; ( V_328 = F_145 ( V_92 , V_186 , & V_98 , & V_329 ,
& V_330 ) ) > 0 ; V_186 = V_328 ) {
if ( V_98 . V_100 == sizeof( V_337 ) &&
! memcmp ( V_92 -> V_24 + V_329 , V_337 ,
sizeof( V_337 ) ) ) {
if ( V_98 . V_103 != V_338 )
goto V_331;
V_287 = F_137 ( & V_4 , ( ( V_92 -> V_24 ) + V_330 ) ,
V_98 . V_102 , V_302 ) ;
if ( V_287 < 0 )
goto V_331;
}
}
if ( F_146 ( V_302 ) )
V_287 = - V_333 ;
V_331:
return V_287 ;
}
int F_147 ( struct V_301 * V_339 , const char * V_340 )
{
T_2 * V_4 ;
int V_107 , V_287 ;
V_107 = F_44 ( V_340 , V_108 ) ;
if ( V_107 < 0 )
return - V_323 ;
V_4 = F_45 ( V_107 , V_109 , NULL ) ;
if ( ! V_4 ) {
V_287 = - V_323 ;
goto V_110;
}
V_287 = F_144 ( V_4 , V_339 ) ;
F_47 ( V_4 ) ;
V_110:
F_48 ( V_107 ) ;
return V_287 ;
}
int F_148 ( struct V_301 * V_302 )
{
struct V_304 * V_305 , * V_84 ;
int V_341 = 0 ;
F_149 (pos, tmp, sdt_notes, note_list) {
F_150 ( & V_84 -> V_319 ) ;
free ( V_84 -> V_35 ) ;
free ( V_84 -> V_303 ) ;
free ( V_84 ) ;
V_341 ++ ;
}
return V_341 ;
}
int F_151 ( struct V_301 * V_179 )
{
struct V_304 * V_342 ;
int V_244 = 0 ;
F_152 (sdt_ptr, start, note_list)
V_244 ++ ;
return V_244 ;
}
void F_153 ( void )
{
F_154 ( V_313 ) ;
}
