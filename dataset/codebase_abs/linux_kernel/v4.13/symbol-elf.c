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
char * F_39 ( struct V_43 * V_43 , int V_44 , char * V_45 )
{
return F_26 ( V_43 , V_44 , V_45 ) ;
}
static int F_40 ( T_2 * V_4 , void * V_90 , T_3 V_91 )
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
V_93 = F_41 ( V_4 ) ;
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
T_3 V_99 = F_42 ( V_98 -> V_100 ) ,
V_101 = F_42 ( V_98 -> V_102 ) ;
const char * V_35 ;
V_94 += sizeof( * V_98 ) ;
V_35 = V_94 ;
V_94 += V_99 ;
if ( V_98 -> V_103 == V_104 &&
V_98 -> V_100 == sizeof( L_13 ) ) {
if ( memcmp ( V_35 , L_13 , sizeof( L_13 ) ) == 0 ) {
T_3 V_105 = F_43 ( V_91 , V_101 ) ;
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
int F_44 ( const char * V_106 , void * V_90 , T_3 V_91 )
{
int V_107 , V_73 = - 1 ;
T_2 * V_4 ;
if ( V_91 < V_95 )
goto V_96;
V_107 = F_45 ( V_106 , V_108 ) ;
if ( V_107 < 0 )
goto V_96;
V_4 = F_46 ( V_107 , V_109 , NULL ) ;
if ( V_4 == NULL ) {
F_47 ( L_14 , V_9 , V_106 ) ;
goto V_110;
}
V_73 = F_40 ( V_4 , V_90 , V_91 ) ;
F_48 ( V_4 ) ;
V_110:
F_49 ( V_107 ) ;
V_96:
return V_73 ;
}
int F_50 ( const char * V_106 , void * V_111 , T_3 V_91 )
{
int V_107 , V_73 = - 1 ;
if ( V_91 < V_95 )
goto V_96;
V_107 = F_45 ( V_106 , V_108 ) ;
if ( V_107 < 0 )
goto V_96;
while ( 1 ) {
char V_90 [ V_112 ] ;
T_16 V_98 ;
T_3 V_99 , V_101 ;
if ( F_51 ( V_107 , & V_98 , sizeof( V_98 ) ) != sizeof( V_98 ) )
break;
V_99 = F_42 ( V_98 . V_100 ) ;
V_101 = F_42 ( V_98 . V_102 ) ;
if ( V_98 . V_103 == V_104 &&
V_98 . V_100 == sizeof( L_13 ) ) {
if ( F_51 ( V_107 , V_90 , V_99 ) != ( V_113 ) V_99 )
break;
if ( memcmp ( V_90 , L_13 , sizeof( L_13 ) ) == 0 ) {
T_3 V_105 = F_43 ( V_101 , V_91 ) ;
if ( F_51 ( V_107 , V_111 , V_105 ) == ( V_113 ) V_105 ) {
memset ( V_111 + V_105 , 0 , V_91 - V_105 ) ;
V_73 = 0 ;
break;
}
} else if ( F_51 ( V_107 , V_90 , V_101 ) != ( V_113 ) V_101 )
break;
} else {
int V_114 = V_99 + V_101 ;
if ( V_114 > ( int ) sizeof( V_90 ) ) {
V_114 = sizeof( V_90 ) ;
F_38 ( L_15 ,
V_9 , V_106 , V_98 . V_100 , V_98 . V_102 ) ;
}
if ( F_51 ( V_107 , V_90 , V_114 ) != V_114 )
break;
}
}
F_49 ( V_107 ) ;
V_96:
return V_73 ;
}
int F_52 ( const char * V_106 , char * V_115 ,
T_3 V_91 )
{
int V_107 , V_73 = - 1 ;
T_2 * V_4 ;
T_4 V_7 ;
T_8 V_25 ;
T_7 * V_92 ;
T_10 * V_29 ;
T_15 V_93 ;
V_107 = F_45 ( V_106 , V_108 ) ;
if ( V_107 < 0 )
goto V_96;
V_4 = F_46 ( V_107 , V_109 , NULL ) ;
if ( V_4 == NULL ) {
F_47 ( L_14 , V_9 , V_106 ) ;
goto V_110;
}
V_93 = F_41 ( V_4 ) ;
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
F_48 ( V_4 ) ;
V_110:
F_49 ( V_107 ) ;
V_96:
return V_73 ;
}
static int F_53 ( struct V_43 * V_43 , unsigned char V_116 )
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
bool F_54 ( struct V_54 * V_55 )
{
return V_55 -> V_74 || V_55 -> V_124 ;
}
bool F_55 ( struct V_54 * V_55 )
{
return V_55 -> V_125 != NULL ;
}
void F_56 ( struct V_54 * V_55 )
{
F_57 ( & V_55 -> V_35 ) ;
F_48 ( V_55 -> V_4 ) ;
F_49 ( V_55 -> V_107 ) ;
}
bool __weak F_58 ( T_4 V_7 )
{
return V_7 . V_126 == V_127 || V_7 . V_126 == V_128 ;
}
int F_59 ( struct V_54 * V_55 , struct V_43 * V_43 , const char * V_35 ,
enum V_129 type )
{
int V_73 = - 1 ;
T_4 V_7 ;
T_2 * V_4 ;
int V_107 ;
if ( F_60 ( V_43 ) ) {
V_107 = F_61 ( V_43 , V_35 ) ;
if ( V_107 < 0 )
return - 1 ;
type = V_43 -> V_130 ;
} else {
V_107 = F_45 ( V_35 , V_108 ) ;
if ( V_107 < 0 ) {
V_43 -> V_131 = V_132 ;
return - 1 ;
}
}
V_4 = F_46 ( V_107 , V_109 , NULL ) ;
if ( V_4 == NULL ) {
F_38 ( L_14 , V_9 , V_35 ) ;
V_43 -> V_131 = V_133 ;
goto V_110;
}
if ( F_4 ( V_4 , & V_7 ) == NULL ) {
V_43 -> V_131 = V_133 ;
F_38 ( L_9 , V_9 ) ;
goto V_76;
}
if ( F_53 ( V_43 , V_7 . V_134 [ V_135 ] ) ) {
V_43 -> V_131 = V_136 ;
goto V_76;
}
if ( V_43 -> V_137 && ! V_40 . V_138 ) {
T_17 V_111 [ V_95 ] ;
if ( F_40 ( V_4 , V_111 , V_95 ) < 0 ) {
V_43 -> V_131 = V_139 ;
goto V_76;
}
if ( ! F_62 ( V_43 , V_111 ) ) {
F_38 ( L_18 , V_9 , V_35 ) ;
V_43 -> V_131 = V_140 ;
goto V_76;
}
}
V_55 -> V_141 = ( F_63 ( V_4 ) == V_142 ) ;
V_55 -> V_125 = F_21 ( V_4 , & V_7 , & V_55 -> V_143 , L_19 ,
NULL ) ;
if ( V_55 -> V_143 . V_81 != V_144 )
V_55 -> V_125 = NULL ;
V_55 -> V_69 = 0 ;
V_55 -> V_74 = F_21 ( V_4 , & V_7 , & V_55 -> V_75 , L_20 ,
& V_55 -> V_69 ) ;
if ( V_55 -> V_75 . V_81 != V_145 )
V_55 -> V_74 = NULL ;
V_55 -> V_146 = 0 ;
V_55 -> V_124 = F_21 ( V_4 , & V_7 , & V_55 -> V_147 , L_21 ,
& V_55 -> V_146 ) ;
if ( V_55 -> V_147 . V_81 != V_148 )
V_55 -> V_124 = NULL ;
if ( V_43 -> V_52 == V_149 )
V_55 -> V_150 = true ;
else
V_55 -> V_150 = F_58 ( V_7 ) ;
V_55 -> V_35 = F_64 ( V_35 ) ;
if ( ! V_55 -> V_35 ) {
V_43 -> V_131 = V_132 ;
goto V_76;
}
V_55 -> V_4 = V_4 ;
V_55 -> V_107 = V_107 ;
V_55 -> V_7 = V_7 ;
V_55 -> type = type ;
return 0 ;
V_76:
F_48 ( V_4 ) ;
V_110:
F_49 ( V_107 ) ;
return V_73 ;
}
static bool F_65 ( struct V_151 * V_151 )
{
return V_151 && V_151 -> V_152 && V_151 -> V_152 -> V_35 &&
! V_151 -> V_152 -> V_153 ;
}
static T_12 F_66 ( struct V_151 * V_151 )
{
if ( V_151 && V_151 -> V_152 &&
V_151 -> V_152 -> V_153 )
return V_151 -> V_152 -> V_28 -
V_151 -> V_152 -> V_153 ;
return 0 ;
}
void __weak F_67 ( struct V_60 * T_18 T_1 ,
T_6 * V_10 T_1 ) { }
int F_68 ( struct V_43 * V_43 , struct V_56 * V_56 , struct V_54 * V_154 ,
struct V_54 * V_155 , int V_44 )
{
struct V_151 * V_151 = V_43 -> V_52 ? F_69 ( V_56 ) : NULL ;
struct V_156 * V_157 = V_151 ? F_70 ( V_56 ) : NULL ;
struct V_56 * V_158 = V_56 ;
struct V_43 * V_159 = V_43 ;
T_7 * V_23 , * V_26 ;
T_11 V_160 ;
int V_73 = - 1 ;
T_11 V_36 ;
T_4 V_7 ;
T_8 V_25 ;
T_8 V_161 ;
T_7 * V_65 , * V_162 = NULL ;
T_6 V_10 ;
T_10 * V_29 , * V_163 ;
T_2 * V_4 ;
int V_71 = 0 ;
bool V_164 = false , V_165 = false ;
if ( V_151 && ! V_157 )
return - 1 ;
V_43 -> V_130 = V_154 -> type ;
V_43 -> V_141 = V_154 -> V_141 ;
V_43 -> V_166 = V_154 -> V_7 . V_126 == V_128 ;
if ( V_44 && V_154 -> V_125 )
F_71 ( & V_43 -> V_87 [ V_56 -> type ] ) ;
if ( ! V_154 -> V_125 ) {
if ( V_43 -> V_52 )
goto V_76;
V_154 -> V_125 = V_154 -> V_74 ;
V_154 -> V_143 = V_154 -> V_75 ;
}
V_4 = V_154 -> V_4 ;
V_7 = V_154 -> V_7 ;
V_29 = V_154 -> V_125 ;
V_25 = V_154 -> V_143 ;
if ( F_21 ( V_155 -> V_4 , & V_155 -> V_7 , & V_161 ,
L_22 , NULL ) )
V_43 -> V_167 = V_161 . V_31 - V_161 . V_80 ;
if ( V_155 -> V_124 )
V_162 = F_22 ( V_155 -> V_124 , NULL ) ;
V_65 = F_31 ( V_29 , NULL ) ;
if ( V_65 == NULL )
goto V_76;
V_29 = F_23 ( V_4 , V_25 . V_77 ) ;
if ( V_29 == NULL )
goto V_76;
V_23 = F_31 ( V_29 , NULL ) ;
if ( V_23 == NULL )
goto V_76;
V_163 = F_23 ( V_155 -> V_4 , V_155 -> V_7 . V_37 ) ;
if ( V_163 == NULL )
goto V_76;
V_26 = F_31 ( V_163 , NULL ) ;
if ( V_26 == NULL )
goto V_76;
V_160 = V_25 . V_32 / V_25 . V_79 ;
memset ( & V_10 , 0 , sizeof( V_10 ) ) ;
if ( F_65 ( V_151 ) ) {
F_72 (syms, nr_syms, idx, sym) {
const char * V_45 = F_13 ( & V_10 , V_23 ) ;
if ( strcmp ( V_45 , V_151 -> V_152 -> V_35 ) )
continue;
V_151 -> V_152 -> V_153 = V_10 . V_168 ;
V_56 -> V_169 = V_151 -> V_152 -> V_28 -
V_151 -> V_152 -> V_153 ;
break;
}
}
if ( F_73 ( V_43 ) )
V_56 -> V_169 = V_56 -> V_170 - V_43 -> V_167 ;
V_43 -> V_150 = V_155 -> V_150 || F_66 ( V_151 ) ;
if ( V_56 -> type == V_21 && ( V_43 -> V_52 || V_44 ) ) {
V_164 = true ;
V_165 = V_43 -> V_150 ;
}
F_72 (syms, nr_syms, idx, sym) {
struct V_60 * V_61 ;
const char * V_45 = F_13 ( & V_10 , V_23 ) ;
char * V_51 = NULL ;
int V_171 = F_11 ( & V_10 ) ;
const char * V_172 ;
bool V_173 = false ;
if ( ! V_171 && ! F_12 ( & V_10 , V_56 -> type ) )
continue;
if ( V_7 . V_174 == V_175 || V_7 . V_174 == V_176 ) {
if ( V_45 [ 0 ] == '$' && strchr ( L_23 , V_45 [ 1 ] )
&& ( V_45 [ 2 ] == '\0' || V_45 [ 2 ] == '.' ) )
continue;
}
if ( V_155 -> V_124 && V_10 . V_15 == V_155 -> V_146 ) {
T_19 V_177 = V_10 . V_168 - V_154 -> V_147 . V_31 ;
T_12 * V_178 = V_162 -> V_24 + V_177 ;
V_10 . V_168 = F_74 ( V_43 , T_12 , * V_178 ) ;
V_10 . V_15 = F_18 ( V_155 -> V_4 ,
V_10 . V_168 ) ;
V_173 = true ;
}
if ( V_10 . V_15 == V_19 )
continue;
V_29 = F_23 ( V_155 -> V_4 , V_10 . V_15 ) ;
if ( ! V_29 )
goto V_76;
F_20 ( V_29 , & V_25 ) ;
if ( V_171 && ! F_17 ( & V_25 , V_26 , V_56 -> type ) )
continue;
V_172 = F_14 ( & V_25 , V_26 ) ;
if ( ( V_7 . V_174 == V_175 ) &&
( V_56 -> type == V_21 ) &&
( V_10 . V_168 & 1 ) )
-- V_10 . V_168 ;
if ( V_43 -> V_52 || V_44 ) {
char V_179 [ V_180 ] ;
if ( V_165 )
V_10 . V_168 -= V_25 . V_31 - V_25 . V_80 ;
if ( strcmp ( V_172 ,
( V_159 -> V_181 +
V_43 -> V_182 ) ) == 0 )
goto V_183;
if ( strcmp ( V_172 , L_22 ) == 0 ) {
if ( V_164 && V_43 -> V_52 ) {
V_164 = false ;
V_56 -> V_170 = V_25 . V_31 +
F_66 ( V_151 ) ;
V_56 -> V_184 = V_56 -> V_170 + V_25 . V_32 ;
V_56 -> V_185 = V_25 . V_80 ;
V_56 -> V_186 = V_187 ;
V_56 -> V_188 = V_189 ;
if ( V_157 ) {
F_75 ( V_56 ) ;
F_76 ( V_157 , V_56 ) ;
F_77 ( V_157 , V_56 ) ;
F_78 ( V_56 ) ;
}
}
if ( V_164 && V_44 ) {
V_164 = false ;
V_56 -> V_185 = V_25 . V_80 ;
}
V_158 = V_56 ;
V_159 = V_43 ;
goto V_183;
}
if ( ! V_151 )
goto V_183;
snprintf ( V_179 , sizeof( V_179 ) ,
L_24 , V_43 -> V_181 , V_172 ) ;
V_158 = F_79 ( V_157 , V_56 -> type , V_179 ) ;
if ( V_158 == NULL ) {
T_12 V_170 = V_10 . V_168 ;
if ( V_44 )
V_170 += V_56 -> V_170 + V_25 . V_80 ;
V_159 = F_80 ( V_179 ) ;
if ( V_159 == NULL )
goto V_76;
V_159 -> V_52 = V_43 -> V_52 ;
V_159 -> V_89 = V_43 -> V_89 ;
V_159 -> V_190 = V_43 -> V_190 ;
V_158 = F_81 ( V_170 , V_159 ,
V_56 -> type ) ;
F_82 ( V_159 ) ;
if ( V_158 == NULL ) {
goto V_76;
}
if ( V_165 ) {
V_158 -> V_170 = V_25 . V_31 +
F_66 ( V_151 ) ;
V_158 -> V_184 = V_158 -> V_170 +
V_25 . V_32 ;
V_158 -> V_185 = V_25 . V_80 ;
} else {
V_158 -> V_186 = V_191 ;
V_158 -> V_188 = V_191 ;
}
V_159 -> V_130 = V_43 -> V_130 ;
F_77 ( V_157 , V_158 ) ;
F_83 ( & V_56 -> V_192 -> V_193 -> V_194 , V_159 ) ;
F_78 ( V_158 ) ;
F_84 ( V_159 , V_56 -> type ) ;
} else
V_159 = V_158 -> V_43 ;
goto V_183;
}
if ( ( V_173 && V_155 -> V_150 )
|| ( ! V_173 && V_154 -> V_150 ) ) {
F_85 ( L_25 V_195 L_26
L_27 V_195 L_28 V_195 L_29 , V_9 ,
( T_12 ) V_10 . V_168 , ( T_12 ) V_25 . V_31 ,
( T_12 ) V_25 . V_80 ) ;
V_10 . V_168 -= V_25 . V_31 - V_25 . V_80 ;
}
V_183:
V_51 = F_26 ( V_43 , V_44 , V_45 ) ;
if ( V_51 != NULL )
V_45 = V_51 ;
V_61 = F_35 ( V_10 . V_168 , V_10 . V_196 ,
F_86 ( V_10 . V_11 ) , V_45 ) ;
free ( V_51 ) ;
if ( ! V_61 )
goto V_76;
F_67 ( V_61 , & V_10 ) ;
F_87 ( & V_159 -> V_87 [ V_158 -> type ] , V_61 , V_43 -> V_52 ) ;
V_71 ++ ;
}
if ( V_71 > 0 ) {
F_88 ( & V_43 -> V_87 [ V_56 -> type ] ) ;
F_89 ( & V_43 -> V_87 [ V_56 -> type ] ) ;
if ( V_151 ) {
F_90 ( V_157 , V_56 -> type ) ;
}
}
V_73 = V_71 ;
V_76:
return V_73 ;
}
static int F_91 ( T_2 * V_4 , bool V_197 , T_20 V_198 , void * V_92 )
{
T_21 V_199 ;
T_3 V_3 , V_200 ;
int V_73 ;
T_12 V_105 ;
if ( F_3 ( V_4 , & V_200 ) )
return - 1 ;
for ( V_3 = 0 ; V_3 < V_200 ; V_3 ++ ) {
if ( F_92 ( V_4 , V_3 , & V_199 ) == NULL )
return - 1 ;
if ( V_199 . V_201 != V_202 )
continue;
if ( V_197 ) {
if ( ! ( V_199 . V_203 & V_204 ) )
continue;
} else {
if ( ! ( V_199 . V_203 & V_205 ) )
continue;
}
V_105 = F_43 ( V_199 . V_206 , V_199 . V_207 ) ;
if ( ! V_105 )
continue;
V_73 = V_198 ( V_199 . V_208 , V_105 , V_199 . V_209 , V_92 ) ;
if ( V_73 )
return V_73 ;
}
return 0 ;
}
int F_93 ( int V_107 , bool V_197 , T_20 V_198 , void * V_92 ,
bool * V_141 )
{
int V_73 ;
T_2 * V_4 ;
V_4 = F_46 ( V_107 , V_109 , NULL ) ;
if ( V_4 == NULL )
return - 1 ;
if ( V_141 )
* V_141 = ( F_63 ( V_4 ) == V_142 ) ;
V_73 = F_91 ( V_4 , V_197 , V_198 , V_92 ) ;
F_48 ( V_4 ) ;
return V_73 ;
}
enum V_210 F_94 ( int V_107 )
{
enum V_210 V_210 = V_211 ;
T_4 V_7 ;
T_15 V_93 ;
T_2 * V_4 ;
V_4 = F_46 ( V_107 , V_109 , NULL ) ;
if ( V_4 == NULL )
goto V_96;
V_93 = F_41 ( V_4 ) ;
if ( V_93 != V_97 )
goto V_212;
if ( F_63 ( V_4 ) == V_142 ) {
V_210 = V_213 ;
goto V_212;
}
if ( F_4 ( V_4 , & V_7 ) == NULL )
goto V_212;
if ( V_7 . V_174 == V_214 )
V_210 = V_215 ;
else
V_210 = V_216 ;
V_212:
F_48 ( V_4 ) ;
V_96:
return V_210 ;
}
static int F_95 ( int V_217 , T_22 V_218 , int V_219 , T_22 V_220 , T_12 V_221 )
{
V_113 V_222 ;
T_3 V_114 ;
int V_73 = - 1 ;
char * V_223 = malloc ( V_224 ) ;
if ( V_223 == NULL )
return - 1 ;
if ( F_96 ( V_219 , V_220 , V_225 ) != V_220 )
goto V_96;
if ( F_96 ( V_217 , V_218 , V_225 ) != V_218 )
goto V_96;
while ( V_221 ) {
V_114 = V_224 ;
if ( V_221 < V_114 )
V_114 = V_221 ;
V_222 = F_51 ( V_217 , V_223 , V_114 ) ;
if ( V_222 < 0 )
goto V_96;
if ( ! V_222 )
break;
V_114 = V_222 ;
V_222 = F_97 ( V_219 , V_223 , V_114 ) ;
if ( V_222 < 0 )
goto V_96;
if ( ( T_3 ) V_222 != V_114 )
goto V_96;
V_221 -= V_114 ;
}
V_73 = 0 ;
V_96:
free ( V_223 ) ;
return V_73 ;
}
static int F_98 ( struct V_226 * V_226 , const char * V_106 )
{
T_4 * V_7 ;
V_226 -> V_107 = F_45 ( V_106 , V_108 ) ;
if ( V_226 -> V_107 == - 1 )
return - 1 ;
V_226 -> V_4 = F_46 ( V_226 -> V_107 , V_227 , NULL ) ;
if ( ! V_226 -> V_4 )
goto V_110;
V_226 -> V_228 = F_63 ( V_226 -> V_4 ) ;
if ( V_226 -> V_228 == V_229 )
goto V_212;
V_7 = F_4 ( V_226 -> V_4 , & V_226 -> V_7 ) ;
if ( ! V_7 )
goto V_212;
return 0 ;
V_212:
F_48 ( V_226 -> V_4 ) ;
V_110:
F_49 ( V_226 -> V_107 ) ;
return - 1 ;
}
static int F_99 ( struct V_226 * V_226 , char * V_106 , int V_228 ,
bool V_230 )
{
V_226 -> V_228 = V_228 ;
if ( V_230 )
V_226 -> V_107 = F_100 ( V_106 ) ;
else
V_226 -> V_107 = F_45 ( V_106 , V_231 | V_232 | V_233 , 0400 ) ;
if ( V_226 -> V_107 == - 1 )
return - 1 ;
V_226 -> V_4 = F_46 ( V_226 -> V_107 , V_234 , NULL ) ;
if ( ! V_226 -> V_4 )
goto V_110;
if ( ! F_101 ( V_226 -> V_4 , V_228 ) )
goto V_212;
memset ( & V_226 -> V_7 , 0 , sizeof( T_4 ) ) ;
return 0 ;
V_212:
F_48 ( V_226 -> V_4 ) ;
V_110:
F_49 ( V_226 -> V_107 ) ;
F_102 ( V_106 ) ;
return - 1 ;
}
static void F_103 ( struct V_226 * V_226 )
{
F_48 ( V_226 -> V_4 ) ;
F_49 ( V_226 -> V_107 ) ;
}
static int F_104 ( struct V_226 * V_217 , struct V_226 * V_219 , T_3 V_235 )
{
T_4 * V_7 = & V_219 -> V_7 ;
T_4 * V_236 = & V_217 -> V_7 ;
memcpy ( V_7 -> V_134 , V_236 -> V_134 , V_237 ) ;
V_7 -> V_126 = V_236 -> V_126 ;
V_7 -> V_174 = V_236 -> V_174 ;
V_7 -> V_238 = V_236 -> V_238 ;
V_7 -> V_239 = 0 ;
V_7 -> V_240 = 0 ;
V_7 -> V_241 = V_236 -> V_241 ;
V_7 -> V_8 = V_235 ;
V_7 -> V_242 = 0 ;
V_7 -> V_243 = 0 ;
V_7 -> V_37 = 0 ;
if ( V_217 -> V_228 == V_244 ) {
V_7 -> V_245 = sizeof( V_246 ) ;
V_7 -> V_247 = sizeof( V_246 ) ;
V_7 -> V_248 = sizeof( V_249 ) ;
} else {
V_7 -> V_245 = sizeof( V_250 ) ;
V_7 -> V_247 = sizeof( V_250 ) ;
V_7 -> V_248 = sizeof( V_251 ) ;
}
if ( ! F_105 ( V_219 -> V_4 , V_7 ) )
return - 1 ;
if ( ! F_106 ( V_219 -> V_4 , V_235 ) )
return - 1 ;
return 0 ;
}
static int F_107 ( struct V_226 * V_226 , int V_36 , T_22 V_177 ,
T_12 V_28 , T_12 V_221 )
{
T_21 V_199 = {
. V_201 = V_202 ,
. V_203 = V_205 | V_252 | V_204 ,
. V_209 = V_177 ,
. V_208 = V_28 ,
. V_253 = 0 ,
. V_207 = V_221 ,
. V_206 = V_221 ,
. V_254 = V_224 ,
} ;
if ( ! F_108 ( V_226 -> V_4 , V_36 , & V_199 ) )
return - 1 ;
return 0 ;
}
static T_22 F_109 ( struct V_226 * V_226 )
{
return F_110 ( V_226 -> V_4 , V_234 ) ;
}
static int F_111 ( void * V_255 , const char * V_35 , char type ,
T_12 V_170 )
{
struct V_256 * V_257 = V_255 ;
if ( ! F_112 ( type , V_21 ) )
return 0 ;
if ( strchr ( V_35 , '[' ) ) {
if ( V_170 > V_257 -> V_258 )
V_257 -> V_258 = V_170 ;
return 0 ;
}
if ( ! V_257 -> V_259 || V_170 < V_257 -> V_259 )
V_257 -> V_259 = V_170 ;
if ( ! V_257 -> V_260 || V_170 > V_257 -> V_260 )
V_257 -> V_260 = V_170 ;
if ( ! strcmp ( V_35 , L_30 ) ) {
V_257 -> V_261 = V_170 ;
return 0 ;
}
if ( ! strcmp ( V_35 , L_31 ) ) {
V_257 -> V_262 = V_170 ;
return 0 ;
}
return 0 ;
}
static int F_113 ( struct V_256 * V_257 ,
const char * V_263 )
{
char V_264 [ V_180 ] ;
F_114 ( V_264 , V_180 , L_32 , V_263 ) ;
if ( F_115 ( V_264 , L_33 ) )
return - 1 ;
if ( F_116 ( V_264 , V_257 ,
F_111 ) < 0 )
return - 1 ;
return 0 ;
}
static int F_117 ( void * V_255 ,
const char * V_35 T_1 ,
T_12 V_170 )
{
struct V_256 * V_257 = V_255 ;
if ( ! V_257 -> V_265 || V_170 < V_257 -> V_265 )
V_257 -> V_265 = V_170 ;
return 0 ;
}
static int F_118 ( struct V_256 * V_257 ,
const char * V_263 )
{
char V_266 [ V_180 ] ;
F_114 ( V_266 , V_180 , L_34 , V_263 ) ;
if ( F_115 ( V_266 , L_35 ) )
return - 1 ;
if ( F_119 ( V_266 , V_257 ,
F_117 ) < 0 )
return - 1 ;
return 0 ;
}
static void F_120 ( struct V_267 * V_268 , T_12 V_170 , T_12 V_184 , T_12 V_185 ,
T_12 T_18 , T_12 V_269 )
{
if ( V_268 -> V_28 || T_18 < V_170 || T_18 >= V_184 )
return;
V_268 -> V_28 = T_18 ;
V_268 -> V_177 = ( T_18 - V_170 ) + V_185 ;
V_268 -> V_221 = V_269 < V_184 ? V_269 - T_18 : V_184 - T_18 ;
}
static int F_121 ( T_12 V_170 , T_12 V_221 , T_12 V_185 , void * V_92 )
{
struct V_256 * V_257 = V_92 ;
T_12 V_184 = V_170 + V_221 ;
F_120 ( & V_257 -> V_270 , V_170 , V_184 , V_185 , V_257 -> V_261 ,
V_257 -> V_262 ) ;
F_120 ( & V_257 -> V_271 , V_170 , V_184 , V_185 , V_257 -> V_265 ,
V_257 -> V_258 ) ;
return 0 ;
}
static int F_122 ( struct V_256 * V_257 , T_2 * V_4 )
{
if ( F_91 ( V_4 , true , F_121 , V_257 ) < 0 )
return - 1 ;
return 0 ;
}
static int F_123 ( struct V_256 * V_257 , const char * V_263 ,
T_2 * V_4 )
{
if ( F_113 ( V_257 , V_263 ) )
return - 1 ;
if ( F_118 ( V_257 , V_263 ) )
return - 1 ;
if ( V_257 -> V_261 )
V_257 -> V_261 = F_124 ( V_257 -> V_261 , V_224 ) ;
else
V_257 -> V_261 = F_124 ( V_257 -> V_259 , V_224 ) ;
if ( V_257 -> V_262 ) {
V_257 -> V_262 = F_125 ( V_257 -> V_262 , V_224 ) ;
} else if ( V_257 -> V_260 ) {
V_257 -> V_262 = F_125 ( V_257 -> V_260 , V_224 ) ;
V_257 -> V_262 += V_224 ;
}
V_257 -> V_265 = F_124 ( V_257 -> V_265 , V_224 ) ;
if ( V_257 -> V_258 ) {
V_257 -> V_258 = F_125 ( V_257 -> V_258 ,
V_224 ) ;
V_257 -> V_258 += V_224 ;
}
if ( ! V_257 -> V_261 || ! V_257 -> V_262 )
return - 1 ;
if ( V_257 -> V_265 && ! V_257 -> V_258 )
return - 1 ;
return F_122 ( V_257 , V_4 ) ;
}
static int F_126 ( const char * V_272 , const char * V_273 ,
const char * V_35 )
{
char V_274 [ V_180 ] ;
char V_275 [ V_180 ] ;
F_114 ( V_274 , V_180 , L_36 , V_272 , V_35 ) ;
F_114 ( V_275 , V_180 , L_36 , V_273 , V_35 ) ;
return F_127 ( V_274 , V_275 , 0400 ) ;
}
static int F_128 ( const char * V_263 , const char * V_35 )
{
char V_106 [ V_180 ] ;
F_114 ( V_106 , V_180 , L_36 , V_263 , V_35 ) ;
return F_102 ( V_106 ) ;
}
static int F_129 ( int V_217 , int V_219 )
{
char * V_276 ;
char * V_277 ;
V_113 V_278 ;
T_3 V_221 ;
int V_73 = - 1 ;
V_276 = malloc ( V_224 ) ;
V_277 = malloc ( V_224 ) ;
if ( ! V_276 || ! V_277 )
goto V_96;
while ( 1 ) {
V_278 = F_51 ( V_217 , V_276 , V_224 ) ;
if ( V_278 < 0 )
goto V_96;
if ( ! V_278 )
break;
V_221 = V_278 ;
if ( F_130 ( V_219 , V_277 , V_221 ) != ( int ) V_221 )
goto V_96;
if ( memcmp ( V_276 , V_277 , V_221 ) )
goto V_96;
}
V_73 = 0 ;
V_96:
free ( V_277 ) ;
free ( V_276 ) ;
return V_73 ;
}
static int F_131 ( const char * V_274 ,
const char * V_275 )
{
int V_217 , V_219 , V_73 = - 1 ;
V_217 = F_45 ( V_274 , V_108 ) ;
if ( V_217 < 0 )
return - 1 ;
V_219 = F_45 ( V_275 , V_108 ) ;
if ( V_219 < 0 )
goto V_279;
V_73 = F_129 ( V_217 , V_219 ) ;
F_49 ( V_219 ) ;
V_279:
F_49 ( V_217 ) ;
return V_73 ;
}
static int F_132 ( const char * V_272 , const char * V_273 ,
const char * V_35 )
{
char V_274 [ V_180 ] ;
char V_275 [ V_180 ] ;
F_114 ( V_274 , V_180 , L_36 , V_272 , V_35 ) ;
F_114 ( V_275 , V_180 , L_36 , V_273 , V_35 ) ;
return F_131 ( V_274 , V_275 ) ;
}
int F_133 ( const char * V_272 , const char * V_273 )
{
struct V_226 V_226 ;
struct V_226 V_280 ;
T_3 V_235 = 2 ;
int V_36 = 0 , V_73 = - 1 ;
T_22 V_177 = V_224 , V_105 , V_281 = 0 ;
struct V_256 V_257 = { . V_261 = 0 , } ;
char V_282 [ V_180 ] ;
char V_283 [ V_180 ] ;
if ( F_126 ( V_272 , V_273 , L_37 ) )
return - 1 ;
if ( F_126 ( V_272 , V_273 , L_38 ) )
goto V_284;
F_114 ( V_282 , V_180 , L_39 , V_272 ) ;
F_114 ( V_283 , V_180 , L_39 , V_273 ) ;
if ( F_98 ( & V_226 , V_282 ) )
goto V_285;
if ( F_123 ( & V_257 , V_272 , V_226 . V_4 ) )
goto V_286;
if ( F_99 ( & V_280 , V_283 , V_226 . V_228 , false ) )
goto V_286;
if ( ! V_257 . V_271 . V_28 )
V_235 -= 1 ;
if ( F_104 ( & V_226 , & V_280 , V_235 ) )
goto V_287;
if ( F_107 ( & V_280 , V_36 ++ , V_177 , V_257 . V_270 . V_28 ,
V_257 . V_270 . V_221 ) )
goto V_287;
if ( V_257 . V_271 . V_28 ) {
V_281 = V_177 + V_257 . V_270 . V_221 ;
if ( F_107 ( & V_280 , V_36 , V_281 ,
V_257 . V_271 . V_28 , V_257 . V_271 . V_221 ) )
goto V_287;
}
V_105 = F_109 ( & V_280 ) ;
if ( V_105 < 0 || V_105 > V_177 )
goto V_287;
if ( F_95 ( V_226 . V_107 , V_257 . V_270 . V_177 , V_280 . V_107 , V_177 ,
V_257 . V_270 . V_221 ) )
goto V_287;
if ( V_281 && F_95 ( V_226 . V_107 , V_257 . V_271 . V_177 ,
V_280 . V_107 , V_281 ,
V_257 . V_271 . V_221 ) )
goto V_287;
if ( F_132 ( V_272 , V_273 , L_38 ) )
goto V_287;
if ( F_132 ( V_272 , V_273 , L_37 ) )
goto V_287;
V_73 = 0 ;
V_287:
F_103 ( & V_280 ) ;
if ( V_73 )
F_102 ( V_283 ) ;
V_286:
F_103 ( & V_226 ) ;
V_285:
if ( V_73 )
F_128 ( V_273 , L_38 ) ;
V_284:
if ( V_73 )
F_128 ( V_273 , L_37 ) ;
return V_73 ;
}
int F_134 ( struct V_288 * V_289 )
{
struct V_226 V_226 ;
struct V_226 V_280 ;
T_3 V_235 = 1 ;
int V_36 = 0 , V_73 = - 1 ;
T_22 V_177 = V_224 , V_105 ;
if ( F_98 ( & V_226 , V_289 -> V_282 ) )
return - 1 ;
strcpy ( V_289 -> V_283 , V_290 ) ;
if ( F_99 ( & V_280 , V_289 -> V_283 , V_226 . V_228 , true ) )
goto V_286;
if ( F_104 ( & V_226 , & V_280 , V_235 ) )
goto V_287;
if ( F_107 ( & V_280 , V_36 , V_177 , V_289 -> V_28 , V_289 -> V_221 ) )
goto V_287;
V_105 = F_109 ( & V_280 ) ;
if ( V_105 < 0 || V_105 > V_177 )
goto V_287;
if ( F_95 ( V_226 . V_107 , V_289 -> V_291 , V_280 . V_107 , V_177 , V_289 -> V_221 ) )
goto V_287;
V_73 = 0 ;
V_287:
F_103 ( & V_280 ) ;
if ( V_73 )
F_102 ( V_289 -> V_283 ) ;
V_286:
F_103 ( & V_226 ) ;
return V_73 ;
}
void F_135 ( struct V_288 * V_289 )
{
F_102 ( V_289 -> V_283 ) ;
}
static int F_136 ( T_2 * * V_4 , const char * V_92 , T_3 V_221 ,
struct V_292 * V_293 )
{
const char * V_294 , * V_35 , * args ;
struct V_295 * V_296 = NULL ;
T_4 V_7 ;
T_9 V_297 = 0 ;
T_8 V_25 ;
int V_278 = - V_123 ;
union {
T_23 V_298 [ V_299 ] ;
T_24 V_300 [ V_299 ] ;
} V_223 ;
T_7 V_5 = {
. V_24 = & V_223 , . V_301 = V_302 , . V_303 = V_304 ,
. V_78 = F_137 ( ( * V_4 ) , V_302 , V_299 , V_304 ) ,
. V_305 = 0 , . V_306 = 0
} ;
T_7 V_307 = {
. V_24 = ( void * ) V_92 , . V_301 = V_302 ,
. V_303 = V_304 , . V_78 = V_5 . V_78 , . V_305 = 0 ,
. V_306 = 0
} ;
V_296 = (struct V_295 * ) calloc ( 1 , sizeof( struct V_295 ) ) ;
if ( ! V_296 ) {
V_278 = - V_308 ;
goto V_309;
}
F_138 ( & V_296 -> V_310 ) ;
if ( V_221 < V_5 . V_78 + 3 )
goto V_311;
if ( F_139 ( * V_4 , & V_5 , & V_307 ,
F_140 ( * V_4 , NULL ) [ V_135 ] ) == NULL ) {
F_6 ( L_40 , F_141 ( - 1 ) ) ;
goto V_311;
}
V_294 = V_92 + V_5 . V_78 ;
V_35 = ( const char * ) memchr ( V_294 , '\0' , V_92 + V_221 - V_294 ) ;
if ( V_35 ++ == NULL )
goto V_311;
V_296 -> V_294 = F_64 ( V_294 ) ;
if ( ! V_296 -> V_294 ) {
V_278 = - V_308 ;
goto V_311;
}
V_296 -> V_35 = F_64 ( V_35 ) ;
if ( ! V_296 -> V_35 ) {
V_278 = - V_308 ;
goto V_312;
}
args = memchr ( V_35 , '\0' , V_92 + V_221 - V_35 ) ;
if ( args == NULL || V_92 + V_221 - args < 2 ||
args [ 1 ] == ':' || args [ 1 ] == '\0' )
V_296 -> args = NULL ;
else {
V_296 -> args = F_64 ( ++ args ) ;
if ( ! V_296 -> args ) {
V_278 = - V_308 ;
goto V_313;
}
}
if ( F_63 ( * V_4 ) == V_244 ) {
memcpy ( & V_296 -> V_28 , & V_223 , 3 * sizeof( T_24 ) ) ;
V_296 -> V_314 = true ;
} else {
memcpy ( & V_296 -> V_28 , & V_223 , 3 * sizeof( T_23 ) ) ;
V_296 -> V_314 = false ;
}
if ( ! F_4 ( * V_4 , & V_7 ) ) {
F_38 ( L_41 , V_9 ) ;
V_278 = - V_315 ;
goto V_316;
}
if ( F_21 ( * V_4 , & V_7 , & V_25 , V_317 , NULL ) ) {
V_297 = V_25 . V_80 ;
if ( V_297 ) {
if ( V_296 -> V_314 )
V_296 -> V_28 . V_300 [ 0 ] = V_296 -> V_28 . V_300 [ 0 ] + V_297 -
V_296 -> V_28 . V_300 [ 1 ] ;
else
V_296 -> V_28 . V_298 [ 0 ] = V_296 -> V_28 . V_298 [ 0 ] + V_297 -
V_296 -> V_28 . V_298 [ 1 ] ;
}
}
F_142 ( & V_296 -> V_310 , V_293 ) ;
return 0 ;
V_316:
free ( V_296 -> args ) ;
V_313:
free ( V_296 -> V_35 ) ;
V_312:
free ( V_296 -> V_294 ) ;
V_311:
free ( V_296 ) ;
V_309:
return V_278 ;
}
static int F_143 ( T_2 * V_4 , struct V_292 * V_293 )
{
T_4 V_7 ;
T_10 * V_318 = NULL ;
T_7 * V_92 ;
T_8 V_25 ;
T_3 V_319 , V_320 ;
T_16 V_98 ;
T_3 V_321 , V_322 , V_177 ;
int V_278 = 0 ;
if ( F_4 ( V_4 , & V_7 ) == NULL ) {
V_278 = - V_315 ;
goto V_323;
}
if ( F_5 ( V_4 , & V_319 ) != 0 ) {
V_278 = - V_315 ;
goto V_323;
}
V_318 = F_21 ( V_4 , & V_7 , & V_25 , V_324 , NULL ) ;
if ( ! V_318 ) {
V_278 = - V_325 ;
goto V_323;
}
if ( ( V_25 . V_81 != V_326 ) || ( V_25 . V_327 & V_328 ) ) {
V_278 = - V_325 ;
goto V_323;
}
V_92 = F_31 ( V_318 , NULL ) ;
for ( V_177 = 0 ; ( V_320 = F_144 ( V_92 , V_177 , & V_98 , & V_321 ,
& V_322 ) ) > 0 ; V_177 = V_320 ) {
if ( V_98 . V_100 == sizeof( V_329 ) &&
! memcmp ( V_92 -> V_24 + V_321 , V_329 ,
sizeof( V_329 ) ) ) {
if ( V_98 . V_103 != V_330 )
goto V_323;
V_278 = F_136 ( & V_4 , ( ( V_92 -> V_24 ) + V_322 ) ,
V_98 . V_102 , V_293 ) ;
if ( V_278 < 0 )
goto V_323;
}
}
if ( F_145 ( V_293 ) )
V_278 = - V_325 ;
V_323:
return V_278 ;
}
int F_146 ( struct V_292 * V_331 , const char * V_332 )
{
T_2 * V_4 ;
int V_107 , V_278 ;
V_107 = F_45 ( V_332 , V_108 ) ;
if ( V_107 < 0 )
return - V_315 ;
V_4 = F_46 ( V_107 , V_109 , NULL ) ;
if ( ! V_4 ) {
V_278 = - V_315 ;
goto V_110;
}
V_278 = F_143 ( V_4 , V_331 ) ;
F_48 ( V_4 ) ;
V_110:
F_49 ( V_107 ) ;
return V_278 ;
}
int F_147 ( struct V_292 * V_293 )
{
struct V_295 * V_296 , * V_84 ;
int V_333 = 0 ;
F_148 (pos, tmp, sdt_notes, note_list) {
F_149 ( & V_84 -> V_310 ) ;
free ( V_84 -> V_35 ) ;
free ( V_84 -> V_294 ) ;
free ( V_84 ) ;
V_333 ++ ;
}
return V_333 ;
}
int F_150 ( struct V_292 * V_170 )
{
struct V_295 * V_334 ;
int V_235 = 0 ;
F_151 (sdt_ptr, start, note_list)
V_235 ++ ;
return V_235 ;
}
void F_152 ( void )
{
F_153 ( V_304 ) ;
}
