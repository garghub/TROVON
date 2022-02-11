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
static inline T_5 F_5 ( const T_6 * V_9 )
{
return F_6 ( V_9 -> V_10 ) ;
}
static inline int F_7 ( const T_6 * V_9 )
{
return ( F_5 ( V_9 ) == V_11 ||
F_5 ( V_9 ) == V_12 ) &&
V_9 -> V_13 != 0 &&
V_9 -> V_14 != V_15 ;
}
static inline bool F_8 ( const T_6 * V_9 )
{
return F_5 ( V_9 ) == V_16 &&
V_9 -> V_13 != 0 &&
V_9 -> V_14 != V_15 ;
}
static inline int F_9 ( const T_6 * V_9 )
{
return F_5 ( V_9 ) == V_17 &&
V_9 -> V_13 != 0 &&
V_9 -> V_14 != V_15 &&
V_9 -> V_14 != V_18 ;
}
static bool F_10 ( T_6 * V_9 , enum V_19 type )
{
switch ( type ) {
case V_20 :
return F_7 ( V_9 ) ;
case V_21 :
return F_8 ( V_9 ) ;
default:
return false ;
}
}
static inline const char * F_11 ( const T_6 * V_9 ,
const T_7 * V_22 )
{
return V_22 -> V_23 + V_9 -> V_13 ;
}
static inline const char * F_12 ( const T_8 * V_24 ,
const T_7 * V_25 )
{
return V_25 -> V_23 + V_24 -> V_26 ;
}
static inline int F_13 ( const T_8 * V_24 ,
const T_7 * V_25 )
{
return strstr ( F_12 ( V_24 , V_25 ) , L_1 ) != NULL ;
}
static inline bool F_14 ( const T_8 * V_24 ,
const T_7 * V_25 )
{
return strstr ( F_12 ( V_24 , V_25 ) , L_2 ) != NULL ;
}
static bool F_15 ( T_8 * V_24 , T_7 * V_25 ,
enum V_19 type )
{
switch ( type ) {
case V_20 :
return F_13 ( V_24 , V_25 ) ;
case V_21 :
return F_14 ( V_24 , V_25 ) ;
default:
return false ;
}
}
static T_3 F_16 ( T_2 * V_4 , T_9 V_27 )
{
T_10 * V_28 = NULL ;
T_8 V_24 ;
T_3 V_29 = 1 ;
while ( ( V_28 = F_17 ( V_4 , V_28 ) ) != NULL ) {
F_18 ( V_28 , & V_24 ) ;
if ( ( V_27 >= V_24 . V_30 ) &&
( V_27 < ( V_24 . V_30 + V_24 . V_31 ) ) )
return V_29 ;
++ V_29 ;
}
return - 1 ;
}
T_10 * F_19 ( T_2 * V_4 , T_4 * V_32 ,
T_8 * V_33 , const char * V_34 , T_3 * V_35 )
{
T_10 * V_28 = NULL ;
T_3 V_29 = 1 ;
if ( ! F_20 ( F_21 ( V_4 , V_32 -> V_36 ) , NULL ) )
return NULL ;
while ( ( V_28 = F_17 ( V_4 , V_28 ) ) != NULL ) {
char * V_37 ;
F_18 ( V_28 , V_33 ) ;
V_37 = F_22 ( V_4 , V_32 -> V_36 , V_33 -> V_26 ) ;
if ( V_37 && ! strcmp ( V_34 , V_37 ) ) {
if ( V_35 )
* V_35 = V_29 ;
return V_28 ;
}
++ V_29 ;
}
return NULL ;
}
int F_23 ( struct V_38 * V_38 , struct V_39 * V_40 , struct V_41 * V_41 ,
T_11 V_42 )
{
T_12 V_43 , V_35 ;
T_6 V_9 ;
T_13 V_44 ;
T_8 V_45 ;
struct V_46 * V_47 ;
T_8 V_48 , V_49 ;
T_7 * V_50 , * V_51 , * V_22 ;
T_10 * V_52 , * V_53 , * V_54 ;
T_3 V_55 ;
T_4 V_7 ;
char V_56 [ 1024 ] ;
T_2 * V_4 ;
int V_57 = 0 , V_58 , V_59 = 0 ;
if ( ! V_40 -> V_60 )
return 0 ;
V_4 = V_40 -> V_4 ;
V_7 = V_40 -> V_7 ;
V_54 = V_40 -> V_60 ;
V_49 = V_40 -> V_61 ;
V_55 = V_40 -> V_55 ;
if ( V_54 == NULL )
goto V_62;
V_52 = F_19 ( V_4 , & V_7 , & V_48 ,
L_3 , NULL ) ;
if ( V_52 == NULL ) {
V_52 = F_19 ( V_4 , & V_7 , & V_48 ,
L_4 , NULL ) ;
if ( V_52 == NULL )
goto V_62;
}
V_59 = - 1 ;
if ( V_48 . V_63 != V_55 )
goto V_62;
if ( F_19 ( V_4 , & V_7 , & V_45 , L_5 , NULL ) == NULL )
goto V_62;
V_50 = F_24 ( V_52 , NULL ) ;
if ( V_50 == NULL )
goto V_62;
V_51 = F_24 ( V_54 , NULL ) ;
if ( V_51 == NULL )
goto V_62;
V_53 = F_21 ( V_4 , V_49 . V_63 ) ;
if ( V_53 == NULL )
goto V_62;
V_22 = F_24 ( V_53 , NULL ) ;
if ( V_22 == NULL )
goto V_62;
if ( V_22 -> V_64 == 0 )
goto V_62;
V_43 = V_48 . V_31 / V_48 . V_65 ;
V_44 = V_45 . V_66 ;
if ( V_48 . V_67 == V_68 ) {
T_14 V_69 , * V_70 ;
F_25 (reldata, pos, pos_mem, idx,
nr_rel_entries) {
V_58 = F_26 ( V_70 -> V_71 ) ;
V_44 += V_45 . V_65 ;
F_27 ( V_51 , V_58 , & V_9 ) ;
snprintf ( V_56 , sizeof( V_56 ) ,
L_6 , F_11 ( & V_9 , V_22 ) ) ;
V_47 = F_28 ( V_44 , V_45 . V_65 ,
V_72 , V_56 ) ;
if ( ! V_47 )
goto V_62;
if ( V_42 && V_42 ( V_41 , V_47 ) )
F_29 ( V_47 ) ;
else {
F_30 ( & V_38 -> V_73 [ V_41 -> type ] , V_47 ) ;
++ V_57 ;
}
}
} else if ( V_48 . V_67 == V_74 ) {
T_15 V_69 , * V_70 ;
F_31 (reldata, pos, pos_mem, idx,
nr_rel_entries) {
V_58 = F_26 ( V_70 -> V_71 ) ;
V_44 += V_45 . V_65 ;
F_27 ( V_51 , V_58 , & V_9 ) ;
snprintf ( V_56 , sizeof( V_56 ) ,
L_6 , F_11 ( & V_9 , V_22 ) ) ;
V_47 = F_28 ( V_44 , V_45 . V_65 ,
V_72 , V_56 ) ;
if ( ! V_47 )
goto V_62;
if ( V_42 && V_42 ( V_41 , V_47 ) )
F_29 ( V_47 ) ;
else {
F_30 ( & V_38 -> V_73 [ V_41 -> type ] , V_47 ) ;
++ V_57 ;
}
}
}
V_59 = 0 ;
V_62:
if ( V_59 == 0 )
return V_57 ;
F_32 ( L_7 ,
V_75 , V_38 -> V_76 ) ;
return 0 ;
}
static int F_33 ( T_2 * V_4 , void * V_77 , T_3 V_78 )
{
int V_59 = - 1 ;
T_4 V_7 ;
T_8 V_24 ;
T_7 * V_79 ;
T_10 * V_28 ;
T_16 V_80 ;
void * V_81 ;
if ( V_78 < V_82 )
goto V_83;
V_80 = F_34 ( V_4 ) ;
if ( V_80 != V_84 )
goto V_83;
if ( F_4 ( V_4 , & V_7 ) == NULL ) {
F_35 ( L_8 , V_75 ) ;
goto V_83;
}
do {
V_28 = F_19 ( V_4 , & V_7 , & V_24 ,
L_9 , NULL ) ;
if ( V_28 )
break;
V_28 = F_19 ( V_4 , & V_7 , & V_24 ,
L_10 , NULL ) ;
if ( V_28 )
break;
V_28 = F_19 ( V_4 , & V_7 , & V_24 ,
L_11 , NULL ) ;
if ( V_28 )
break;
return V_59 ;
} while ( 0 );
V_79 = F_24 ( V_28 , NULL ) ;
if ( V_79 == NULL )
goto V_83;
V_81 = V_79 -> V_23 ;
while ( V_81 < ( V_79 -> V_23 + V_79 -> V_64 ) ) {
T_17 * V_85 = V_81 ;
T_3 V_86 = F_36 ( V_85 -> V_87 ) ,
V_88 = F_36 ( V_85 -> V_89 ) ;
const char * V_34 ;
V_81 += sizeof( * V_85 ) ;
V_34 = V_81 ;
V_81 += V_86 ;
if ( V_85 -> V_90 == V_91 &&
V_85 -> V_87 == sizeof( L_12 ) ) {
if ( memcmp ( V_34 , L_12 , sizeof( L_12 ) ) == 0 ) {
T_3 V_92 = F_37 ( V_78 , V_88 ) ;
memcpy ( V_77 , V_81 , V_92 ) ;
memset ( V_77 + V_92 , 0 , V_78 - V_92 ) ;
V_59 = V_88 ;
break;
}
}
V_81 += V_88 ;
}
V_83:
return V_59 ;
}
int F_38 ( const char * V_93 , void * V_77 , T_3 V_78 )
{
int V_94 , V_59 = - 1 ;
T_2 * V_4 ;
if ( V_78 < V_82 )
goto V_83;
V_94 = F_39 ( V_93 , V_95 ) ;
if ( V_94 < 0 )
goto V_83;
V_4 = F_40 ( V_94 , V_96 , NULL ) ;
if ( V_4 == NULL ) {
F_41 ( L_13 , V_75 , V_93 ) ;
goto V_97;
}
V_59 = F_33 ( V_4 , V_77 , V_78 ) ;
F_42 ( V_4 ) ;
V_97:
F_43 ( V_94 ) ;
V_83:
return V_59 ;
}
int F_44 ( const char * V_93 , void * V_98 , T_3 V_78 )
{
int V_94 , V_59 = - 1 ;
if ( V_78 < V_82 )
goto V_83;
V_94 = F_39 ( V_93 , V_95 ) ;
if ( V_94 < 0 )
goto V_83;
while ( 1 ) {
char V_77 [ V_99 ] ;
T_17 V_85 ;
T_3 V_86 , V_88 ;
if ( F_45 ( V_94 , & V_85 , sizeof( V_85 ) ) != sizeof( V_85 ) )
break;
V_86 = F_36 ( V_85 . V_87 ) ;
V_88 = F_36 ( V_85 . V_89 ) ;
if ( V_85 . V_90 == V_91 &&
V_85 . V_87 == sizeof( L_12 ) ) {
if ( F_45 ( V_94 , V_77 , V_86 ) != ( V_100 ) V_86 )
break;
if ( memcmp ( V_77 , L_12 , sizeof( L_12 ) ) == 0 ) {
T_3 V_92 = F_37 ( V_88 , V_78 ) ;
if ( F_45 ( V_94 , V_98 , V_92 ) == ( V_100 ) V_92 ) {
memset ( V_98 + V_92 , 0 , V_78 - V_92 ) ;
V_59 = 0 ;
break;
}
} else if ( F_45 ( V_94 , V_77 , V_88 ) != ( V_100 ) V_88 )
break;
} else {
int V_101 = V_86 + V_88 ;
if ( F_45 ( V_94 , V_77 , V_101 ) != V_101 )
break;
}
}
F_43 ( V_94 ) ;
V_83:
return V_59 ;
}
int F_46 ( const char * V_93 , char * V_102 ,
T_3 V_78 )
{
int V_94 , V_59 = - 1 ;
T_2 * V_4 ;
T_4 V_7 ;
T_8 V_24 ;
T_7 * V_79 ;
T_10 * V_28 ;
T_16 V_80 ;
V_94 = F_39 ( V_93 , V_95 ) ;
if ( V_94 < 0 )
goto V_83;
V_4 = F_40 ( V_94 , V_96 , NULL ) ;
if ( V_4 == NULL ) {
F_41 ( L_13 , V_75 , V_93 ) ;
goto V_97;
}
V_80 = F_34 ( V_4 ) ;
if ( V_80 != V_84 )
goto V_62;
if ( F_4 ( V_4 , & V_7 ) == NULL ) {
F_35 ( L_8 , V_75 ) ;
goto V_62;
}
V_28 = F_19 ( V_4 , & V_7 , & V_24 ,
L_14 , NULL ) ;
if ( V_28 == NULL )
goto V_62;
V_79 = F_24 ( V_28 , NULL ) ;
if ( V_79 == NULL )
goto V_62;
strncpy ( V_102 , V_79 -> V_23 , V_78 ) ;
V_59 = 0 ;
V_62:
F_42 ( V_4 ) ;
V_97:
F_43 ( V_94 ) ;
V_83:
return V_59 ;
}
static int F_47 ( struct V_38 * V_38 , unsigned char V_103 )
{
static unsigned int const V_104 = 1 ;
V_38 -> V_105 = V_106 ;
switch ( V_103 ) {
case V_107 :
if ( * ( unsigned char const * ) & V_104 != 1 )
V_38 -> V_105 = V_108 ;
break;
case V_109 :
if ( * ( unsigned char const * ) & V_104 != 0 )
V_38 -> V_105 = V_108 ;
break;
default:
F_35 ( L_15 , V_103 ) ;
return - V_110 ;
}
return 0 ;
}
static int F_48 ( struct V_38 * V_38 , const char * V_34 ,
enum V_111 type )
{
int V_94 ;
const char * V_112 = strrchr ( V_34 , '.' ) ;
char V_113 [] = L_16 ;
if ( type != V_114 &&
type != V_115 &&
type != V_116 )
return - 1 ;
if ( ! V_112 || ! F_49 ( V_112 + 1 ) ) {
V_112 = strrchr ( V_38 -> V_34 , '.' ) ;
if ( ! V_112 || ! F_49 ( V_112 + 1 ) )
return - 1 ;
}
V_94 = F_50 ( V_113 ) ;
if ( V_94 < 0 )
return - 1 ;
if ( ! F_51 ( V_112 + 1 , V_34 , V_94 ) ) {
F_43 ( V_94 ) ;
V_94 = - 1 ;
}
F_52 ( V_113 ) ;
return V_94 ;
}
bool F_53 ( struct V_39 * V_40 )
{
return V_40 -> V_60 || V_40 -> V_117 ;
}
bool F_54 ( struct V_39 * V_40 )
{
return V_40 -> V_118 != NULL ;
}
void F_55 ( struct V_39 * V_40 )
{
F_56 ( & V_40 -> V_34 ) ;
F_42 ( V_40 -> V_4 ) ;
F_43 ( V_40 -> V_94 ) ;
}
int F_57 ( struct V_39 * V_40 , struct V_38 * V_38 , const char * V_34 ,
enum V_111 type )
{
int V_59 = - 1 ;
T_4 V_7 ;
T_2 * V_4 ;
int V_94 ;
if ( F_58 ( V_38 ) )
V_94 = F_48 ( V_38 , V_34 , type ) ;
else
V_94 = F_39 ( V_34 , V_95 ) ;
if ( V_94 < 0 )
return - 1 ;
V_4 = F_40 ( V_94 , V_96 , NULL ) ;
if ( V_4 == NULL ) {
F_32 ( L_13 , V_75 , V_34 ) ;
goto V_97;
}
if ( F_4 ( V_4 , & V_7 ) == NULL ) {
F_32 ( L_8 , V_75 ) ;
goto V_62;
}
if ( F_47 ( V_38 , V_7 . V_119 [ V_120 ] ) )
goto V_62;
if ( V_38 -> V_121 ) {
T_18 V_98 [ V_82 ] ;
if ( F_33 ( V_4 , V_98 , V_82 ) < 0 )
goto V_62;
if ( ! F_59 ( V_38 , V_98 ) )
goto V_62;
}
V_40 -> V_122 = ( F_60 ( V_4 ) == V_123 ) ;
V_40 -> V_118 = F_19 ( V_4 , & V_7 , & V_40 -> V_124 , L_17 ,
NULL ) ;
if ( V_40 -> V_124 . V_67 != V_125 )
V_40 -> V_118 = NULL ;
V_40 -> V_55 = 0 ;
V_40 -> V_60 = F_19 ( V_4 , & V_7 , & V_40 -> V_61 , L_18 ,
& V_40 -> V_55 ) ;
if ( V_40 -> V_61 . V_67 != V_126 )
V_40 -> V_60 = NULL ;
V_40 -> V_127 = 0 ;
V_40 -> V_117 = F_19 ( V_4 , & V_7 , & V_40 -> V_128 , L_19 ,
& V_40 -> V_127 ) ;
if ( V_40 -> V_128 . V_67 != V_129 )
V_40 -> V_117 = NULL ;
if ( V_38 -> V_130 == V_131 ) {
T_8 V_24 ;
V_40 -> V_132 = ( V_7 . V_133 == V_134 ||
V_7 . V_133 == V_135 ||
F_61 ( V_38 ) ||
F_19 ( V_4 , & V_7 , & V_24 ,
L_20 ,
NULL ) != NULL ) ;
} else {
V_40 -> V_132 = V_7 . V_133 == V_134 ||
V_7 . V_133 == V_135 ;
}
V_40 -> V_34 = F_62 ( V_34 ) ;
if ( ! V_40 -> V_34 )
goto V_62;
V_40 -> V_4 = V_4 ;
V_40 -> V_94 = V_94 ;
V_40 -> V_7 = V_7 ;
V_40 -> type = type ;
return 0 ;
V_62:
F_42 ( V_4 ) ;
V_97:
F_43 ( V_94 ) ;
return V_59 ;
}
static bool F_63 ( struct V_136 * V_136 )
{
return V_136 && V_136 -> V_137 && V_136 -> V_137 -> V_34 &&
! V_136 -> V_137 -> V_138 ;
}
static T_13 F_64 ( struct V_136 * V_136 )
{
if ( V_136 && V_136 -> V_137 &&
V_136 -> V_137 -> V_138 )
return V_136 -> V_137 -> V_27 -
V_136 -> V_137 -> V_138 ;
return 0 ;
}
static bool F_65 ( bool V_139 )
{
return V_139 ? V_140 . V_141 : V_140 . V_142 ;
}
int F_66 ( struct V_38 * V_38 , struct V_41 * V_41 ,
struct V_39 * V_143 , struct V_39 * V_144 ,
T_11 V_42 , int V_145 )
{
struct V_136 * V_136 = V_38 -> V_130 ? F_67 ( V_41 ) : NULL ;
struct V_41 * V_146 = V_41 ;
struct V_38 * V_147 = V_38 ;
T_7 * V_22 , * V_25 ;
T_12 V_148 ;
int V_59 = - 1 ;
T_12 V_35 ;
T_4 V_7 ;
T_8 V_24 ;
T_7 * V_51 , * V_149 = NULL ;
T_6 V_9 ;
T_10 * V_28 , * V_150 ;
T_2 * V_4 ;
int V_57 = 0 ;
bool V_151 = false , V_152 = false ;
V_38 -> V_153 = V_143 -> type ;
V_38 -> V_122 = V_143 -> V_122 ;
V_38 -> V_154 = V_143 -> V_7 . V_133 == V_135 ;
if ( V_145 && V_143 -> V_118 )
F_68 ( & V_38 -> V_73 [ V_41 -> type ] ) ;
if ( ! V_143 -> V_118 ) {
if ( V_38 -> V_130 )
goto V_62;
V_143 -> V_118 = V_143 -> V_60 ;
V_143 -> V_124 = V_143 -> V_61 ;
}
V_4 = V_143 -> V_4 ;
V_7 = V_143 -> V_7 ;
V_28 = V_143 -> V_118 ;
V_24 = V_143 -> V_124 ;
if ( V_144 -> V_117 )
V_149 = F_20 ( V_144 -> V_117 , NULL ) ;
V_51 = F_24 ( V_28 , NULL ) ;
if ( V_51 == NULL )
goto V_62;
V_28 = F_21 ( V_4 , V_24 . V_63 ) ;
if ( V_28 == NULL )
goto V_62;
V_22 = F_24 ( V_28 , NULL ) ;
if ( V_22 == NULL )
goto V_62;
V_150 = F_21 ( V_144 -> V_4 , V_144 -> V_7 . V_36 ) ;
if ( V_150 == NULL )
goto V_62;
V_25 = F_24 ( V_150 , NULL ) ;
if ( V_25 == NULL )
goto V_62;
V_148 = V_24 . V_31 / V_24 . V_65 ;
memset ( & V_9 , 0 , sizeof( V_9 ) ) ;
if ( F_63 ( V_136 ) ) {
F_69 (syms, nr_syms, idx, sym) {
const char * V_155 = F_11 ( & V_9 , V_22 ) ;
if ( strcmp ( V_155 , V_136 -> V_137 -> V_34 ) )
continue;
V_136 -> V_137 -> V_138 = V_9 . V_156 ;
V_41 -> V_157 = V_136 -> V_137 -> V_27 -
V_136 -> V_137 -> V_138 ;
break;
}
}
V_38 -> V_132 = V_144 -> V_132 || F_64 ( V_136 ) ;
if ( V_41 -> type == V_20 && ( V_38 -> V_130 || V_145 ) ) {
V_151 = true ;
V_152 = V_38 -> V_132 ;
}
F_69 (syms, nr_syms, idx, sym) {
struct V_46 * V_47 ;
const char * V_155 = F_11 ( & V_9 , V_22 ) ;
char * V_158 = NULL ;
int V_159 = F_9 ( & V_9 ) ;
const char * V_160 ;
bool V_161 = false ;
if ( ! V_159 && ! F_10 ( & V_9 , V_41 -> type ) )
continue;
if ( V_7 . V_162 == V_163 ) {
if ( ! strcmp ( V_155 , L_21 ) ||
! strcmp ( V_155 , L_22 ) ||
! strcmp ( V_155 , L_23 ) )
continue;
}
if ( V_144 -> V_117 && V_9 . V_14 == V_144 -> V_127 ) {
T_19 V_164 = V_9 . V_156 - V_143 -> V_128 . V_30 ;
T_13 * V_165 = V_149 -> V_23 + V_164 ;
V_9 . V_156 = F_70 ( V_38 , T_13 , * V_165 ) ;
V_9 . V_14 = F_16 ( V_144 -> V_4 ,
V_9 . V_156 ) ;
V_161 = true ;
}
if ( V_9 . V_14 == V_18 )
continue;
V_28 = F_21 ( V_144 -> V_4 , V_9 . V_14 ) ;
if ( ! V_28 )
goto V_62;
F_18 ( V_28 , & V_24 ) ;
if ( V_159 && ! F_15 ( & V_24 , V_25 , V_41 -> type ) )
continue;
V_160 = F_12 ( & V_24 , V_25 ) ;
if ( ( V_7 . V_162 == V_163 ) &&
( V_41 -> type == V_20 ) &&
( V_9 . V_156 & 1 ) )
-- V_9 . V_156 ;
if ( V_38 -> V_130 || V_145 ) {
char V_166 [ V_167 ] ;
if ( V_152 )
V_9 . V_156 -= V_24 . V_30 - V_24 . V_66 ;
if ( strcmp ( V_160 ,
( V_147 -> V_168 +
V_38 -> V_169 ) ) == 0 )
goto V_170;
if ( strcmp ( V_160 , L_24 ) == 0 ) {
if ( V_151 && V_38 -> V_130 ) {
V_151 = false ;
V_41 -> V_171 = V_24 . V_30 +
F_64 ( V_136 ) ;
V_41 -> V_172 = V_41 -> V_171 + V_24 . V_31 ;
V_41 -> V_173 = V_24 . V_66 ;
V_41 -> V_174 = V_175 ;
V_41 -> V_176 = V_177 ;
F_71 ( V_136 -> V_178 , V_41 ) ;
F_72 ( V_136 -> V_178 , V_41 ) ;
}
if ( V_151 && V_145 ) {
V_151 = false ;
V_41 -> V_173 = V_24 . V_66 ;
}
V_146 = V_41 ;
V_147 = V_38 ;
goto V_170;
}
if ( ! V_136 )
goto V_170;
snprintf ( V_166 , sizeof( V_166 ) ,
L_25 , V_38 -> V_168 , V_160 ) ;
V_146 = F_73 ( V_136 -> V_178 , V_41 -> type , V_166 ) ;
if ( V_146 == NULL ) {
T_13 V_171 = V_9 . V_156 ;
if ( V_145 )
V_171 += V_41 -> V_171 + V_24 . V_66 ;
V_147 = F_74 ( V_166 ) ;
if ( V_147 == NULL )
goto V_62;
V_147 -> V_130 = V_38 -> V_130 ;
V_147 -> V_76 = V_38 -> V_76 ;
V_147 -> V_179 = V_38 -> V_179 ;
V_146 = F_75 ( V_171 , V_147 ,
V_41 -> type ) ;
if ( V_146 == NULL ) {
F_76 ( V_147 ) ;
goto V_62;
}
if ( V_152 ) {
V_146 -> V_171 = V_24 . V_30 +
F_64 ( V_136 ) ;
V_146 -> V_172 = V_146 -> V_171 +
V_24 . V_31 ;
V_146 -> V_173 = V_24 . V_66 ;
} else {
V_146 -> V_174 = V_180 ;
V_146 -> V_176 = V_180 ;
}
V_147 -> V_153 = V_38 -> V_153 ;
F_72 ( V_136 -> V_178 , V_146 ) ;
F_77 ( & V_41 -> V_181 -> V_182 -> V_183 ,
V_147 ) ;
F_78 ( V_147 , V_41 -> type ) ;
} else
V_147 = V_146 -> V_38 ;
goto V_170;
}
if ( ( V_161 && V_144 -> V_132 )
|| ( ! V_161 && V_143 -> V_132 ) ) {
F_79 ( L_26 V_184 L_27
L_28 V_184 L_29 V_184 L_30 , V_75 ,
( T_13 ) V_9 . V_156 , ( T_13 ) V_24 . V_30 ,
( T_13 ) V_24 . V_66 ) ;
V_9 . V_156 -= V_24 . V_30 - V_24 . V_66 ;
}
V_170:
if ( F_65 ( V_38 -> V_130 || V_145 ) ) {
int V_185 = V_186 ;
if ( V_187 )
V_185 = V_188 | V_189 ;
V_158 = F_1 ( NULL , V_155 , V_185 ) ;
if ( V_158 != NULL )
V_155 = V_158 ;
}
V_47 = F_28 ( V_9 . V_156 , V_9 . V_190 ,
F_80 ( V_9 . V_10 ) , V_155 ) ;
free ( V_158 ) ;
if ( ! V_47 )
goto V_62;
if ( V_42 && V_42 ( V_146 , V_47 ) )
F_29 ( V_47 ) ;
else {
F_30 ( & V_147 -> V_73 [ V_146 -> type ] , V_47 ) ;
V_57 ++ ;
}
}
if ( V_57 > 0 ) {
F_81 ( & V_38 -> V_73 [ V_41 -> type ] ) ;
F_82 ( & V_38 -> V_73 [ V_41 -> type ] ) ;
if ( V_136 ) {
F_83 ( V_136 -> V_178 , V_41 -> type ) ;
}
}
V_59 = V_57 ;
V_62:
return V_59 ;
}
static int F_84 ( T_2 * V_4 , bool V_191 , T_20 V_192 , void * V_79 )
{
T_21 V_193 ;
T_3 V_3 , V_194 ;
int V_59 ;
T_13 V_92 ;
if ( F_3 ( V_4 , & V_194 ) )
return - 1 ;
for ( V_3 = 0 ; V_3 < V_194 ; V_3 ++ ) {
if ( F_85 ( V_4 , V_3 , & V_193 ) == NULL )
return - 1 ;
if ( V_193 . V_195 != V_196 )
continue;
if ( V_191 ) {
if ( ! ( V_193 . V_197 & V_198 ) )
continue;
} else {
if ( ! ( V_193 . V_197 & V_199 ) )
continue;
}
V_92 = F_37 ( V_193 . V_200 , V_193 . V_201 ) ;
if ( ! V_92 )
continue;
V_59 = V_192 ( V_193 . V_202 , V_92 , V_193 . V_203 , V_79 ) ;
if ( V_59 )
return V_59 ;
}
return 0 ;
}
int F_86 ( int V_94 , bool V_191 , T_20 V_192 , void * V_79 ,
bool * V_122 )
{
int V_59 ;
T_2 * V_4 ;
V_4 = F_40 ( V_94 , V_96 , NULL ) ;
if ( V_4 == NULL )
return - 1 ;
if ( V_122 )
* V_122 = ( F_60 ( V_4 ) == V_123 ) ;
V_59 = F_84 ( V_4 , V_191 , V_192 , V_79 ) ;
F_42 ( V_4 ) ;
return V_59 ;
}
enum V_204 F_87 ( int V_94 )
{
enum V_204 V_204 = V_205 ;
T_4 V_7 ;
T_16 V_80 ;
T_2 * V_4 ;
V_4 = F_40 ( V_94 , V_96 , NULL ) ;
if ( V_4 == NULL )
goto V_83;
V_80 = F_34 ( V_4 ) ;
if ( V_80 != V_84 )
goto V_206;
if ( F_60 ( V_4 ) == V_123 ) {
V_204 = V_207 ;
goto V_206;
}
if ( F_4 ( V_4 , & V_7 ) == NULL )
goto V_206;
if ( V_7 . V_162 == V_208 )
V_204 = V_209 ;
else
V_204 = V_210 ;
V_206:
F_42 ( V_4 ) ;
V_83:
return V_204 ;
}
static int F_88 ( int V_211 , T_22 V_212 , int V_213 , T_22 V_214 , T_13 V_215 )
{
V_100 V_216 ;
T_3 V_101 ;
int V_59 = - 1 ;
char * V_217 = malloc ( V_218 ) ;
if ( V_217 == NULL )
return - 1 ;
if ( F_89 ( V_213 , V_214 , V_219 ) != V_214 )
goto V_83;
if ( F_89 ( V_211 , V_212 , V_219 ) != V_212 )
goto V_83;
while ( V_215 ) {
V_101 = V_218 ;
if ( V_215 < V_101 )
V_101 = V_215 ;
V_216 = F_45 ( V_211 , V_217 , V_101 ) ;
if ( V_216 < 0 )
goto V_83;
if ( ! V_216 )
break;
V_101 = V_216 ;
V_216 = F_90 ( V_213 , V_217 , V_101 ) ;
if ( V_216 < 0 )
goto V_83;
if ( ( T_3 ) V_216 != V_101 )
goto V_83;
V_215 -= V_101 ;
}
V_59 = 0 ;
V_83:
free ( V_217 ) ;
return V_59 ;
}
static int F_91 ( struct V_220 * V_220 , const char * V_93 )
{
T_4 * V_7 ;
V_220 -> V_94 = F_39 ( V_93 , V_95 ) ;
if ( V_220 -> V_94 == - 1 )
return - 1 ;
V_220 -> V_4 = F_40 ( V_220 -> V_94 , V_221 , NULL ) ;
if ( ! V_220 -> V_4 )
goto V_97;
V_220 -> V_222 = F_60 ( V_220 -> V_4 ) ;
if ( V_220 -> V_222 == V_223 )
goto V_206;
V_7 = F_4 ( V_220 -> V_4 , & V_220 -> V_7 ) ;
if ( ! V_7 )
goto V_206;
return 0 ;
V_206:
F_42 ( V_220 -> V_4 ) ;
V_97:
F_43 ( V_220 -> V_94 ) ;
return - 1 ;
}
static int F_92 ( struct V_220 * V_220 , char * V_93 , int V_222 ,
bool V_224 )
{
T_4 * V_7 ;
V_220 -> V_222 = V_222 ;
if ( V_224 )
V_220 -> V_94 = F_50 ( V_93 ) ;
else
V_220 -> V_94 = F_39 ( V_93 , V_225 | V_226 | V_227 , 0400 ) ;
if ( V_220 -> V_94 == - 1 )
return - 1 ;
V_220 -> V_4 = F_40 ( V_220 -> V_94 , V_228 , NULL ) ;
if ( ! V_220 -> V_4 )
goto V_97;
if ( ! F_93 ( V_220 -> V_4 , V_222 ) )
goto V_206;
V_7 = F_4 ( V_220 -> V_4 , & V_220 -> V_7 ) ;
if ( ! V_7 )
goto V_206;
return 0 ;
V_206:
F_42 ( V_220 -> V_4 ) ;
V_97:
F_43 ( V_220 -> V_94 ) ;
F_52 ( V_93 ) ;
return - 1 ;
}
static void F_94 ( struct V_220 * V_220 )
{
F_42 ( V_220 -> V_4 ) ;
F_43 ( V_220 -> V_94 ) ;
}
static int F_95 ( struct V_220 * V_211 , struct V_220 * V_213 , T_3 V_229 )
{
T_4 * V_7 = & V_213 -> V_7 ;
T_4 * V_230 = & V_211 -> V_7 ;
memcpy ( V_7 -> V_119 , V_230 -> V_119 , V_231 ) ;
V_7 -> V_133 = V_230 -> V_133 ;
V_7 -> V_162 = V_230 -> V_162 ;
V_7 -> V_232 = V_230 -> V_232 ;
V_7 -> V_233 = 0 ;
V_7 -> V_234 = 0 ;
V_7 -> V_235 = V_230 -> V_235 ;
V_7 -> V_8 = V_229 ;
V_7 -> V_236 = 0 ;
V_7 -> V_237 = 0 ;
V_7 -> V_36 = 0 ;
if ( V_211 -> V_222 == V_238 ) {
V_7 -> V_239 = sizeof( V_240 ) ;
V_7 -> V_241 = sizeof( V_240 ) ;
V_7 -> V_242 = sizeof( V_243 ) ;
} else {
V_7 -> V_239 = sizeof( V_244 ) ;
V_7 -> V_241 = sizeof( V_244 ) ;
V_7 -> V_242 = sizeof( V_245 ) ;
}
if ( ! F_96 ( V_213 -> V_4 , V_7 ) )
return - 1 ;
if ( ! F_97 ( V_213 -> V_4 , V_229 ) )
return - 1 ;
return 0 ;
}
static int F_98 ( struct V_220 * V_220 , int V_35 , T_22 V_164 ,
T_13 V_27 , T_13 V_215 )
{
T_21 V_246 ;
T_21 * V_193 ;
V_193 = F_85 ( V_220 -> V_4 , V_35 , & V_246 ) ;
if ( ! V_193 )
return - 1 ;
V_193 -> V_195 = V_196 ;
V_193 -> V_197 = V_199 | V_247 | V_198 ;
V_193 -> V_203 = V_164 ;
V_193 -> V_202 = V_27 ;
V_193 -> V_248 = 0 ;
V_193 -> V_201 = V_215 ;
V_193 -> V_200 = V_215 ;
V_193 -> V_249 = V_218 ;
if ( ! F_99 ( V_220 -> V_4 , V_35 , V_193 ) )
return - 1 ;
return 0 ;
}
static T_22 F_100 ( struct V_220 * V_220 )
{
return F_101 ( V_220 -> V_4 , V_228 ) ;
}
static int F_102 ( void * V_250 , const char * V_34 , char type ,
T_13 V_171 )
{
struct V_251 * V_252 = V_250 ;
if ( ! F_103 ( type , V_20 ) )
return 0 ;
if ( strchr ( V_34 , '[' ) ) {
if ( V_171 > V_252 -> V_253 )
V_252 -> V_253 = V_171 ;
return 0 ;
}
if ( ! V_252 -> V_254 || V_171 < V_252 -> V_254 )
V_252 -> V_254 = V_171 ;
if ( ! V_252 -> V_255 || V_171 > V_252 -> V_255 )
V_252 -> V_255 = V_171 ;
if ( ! strcmp ( V_34 , L_31 ) ) {
V_252 -> V_256 = V_171 ;
return 0 ;
}
if ( ! strcmp ( V_34 , L_32 ) ) {
V_252 -> V_257 = V_171 ;
return 0 ;
}
return 0 ;
}
static int F_104 ( struct V_251 * V_252 ,
const char * V_258 )
{
char V_259 [ V_167 ] ;
F_105 ( V_259 , V_167 , L_33 , V_258 ) ;
if ( F_106 ( V_259 , L_34 ) )
return - 1 ;
if ( F_107 ( V_259 , V_252 ,
F_102 ) < 0 )
return - 1 ;
return 0 ;
}
static int F_108 ( void * V_250 ,
const char * V_34 T_1 ,
T_13 V_171 )
{
struct V_251 * V_252 = V_250 ;
if ( ! V_252 -> V_260 || V_171 < V_252 -> V_260 )
V_252 -> V_260 = V_171 ;
return 0 ;
}
static int F_109 ( struct V_251 * V_252 ,
const char * V_258 )
{
char V_261 [ V_167 ] ;
F_105 ( V_261 , V_167 , L_35 , V_258 ) ;
if ( F_106 ( V_261 , L_36 ) )
return - 1 ;
if ( F_110 ( V_261 , V_252 ,
F_108 ) < 0 )
return - 1 ;
return 0 ;
}
static void F_111 ( struct V_262 * V_263 , T_13 V_171 , T_13 V_172 , T_13 V_173 ,
T_13 V_264 , T_13 V_265 )
{
if ( V_263 -> V_27 || V_264 < V_171 || V_264 >= V_172 )
return;
V_263 -> V_27 = V_264 ;
V_263 -> V_164 = ( V_264 - V_171 ) + V_173 ;
V_263 -> V_215 = V_265 < V_172 ? V_265 - V_264 : V_172 - V_264 ;
}
static int F_112 ( T_13 V_171 , T_13 V_215 , T_13 V_173 , void * V_79 )
{
struct V_251 * V_252 = V_79 ;
T_13 V_172 = V_171 + V_215 ;
F_111 ( & V_252 -> V_266 , V_171 , V_172 , V_173 , V_252 -> V_256 ,
V_252 -> V_257 ) ;
F_111 ( & V_252 -> V_267 , V_171 , V_172 , V_173 , V_252 -> V_260 ,
V_252 -> V_253 ) ;
return 0 ;
}
static int F_113 ( struct V_251 * V_252 , T_2 * V_4 )
{
if ( F_84 ( V_4 , true , F_112 , V_252 ) < 0 )
return - 1 ;
return 0 ;
}
static int F_114 ( struct V_251 * V_252 , const char * V_258 ,
T_2 * V_4 )
{
if ( F_104 ( V_252 , V_258 ) )
return - 1 ;
if ( F_109 ( V_252 , V_258 ) )
return - 1 ;
if ( V_252 -> V_256 )
V_252 -> V_256 = F_115 ( V_252 -> V_256 , V_218 ) ;
else
V_252 -> V_256 = F_115 ( V_252 -> V_254 , V_218 ) ;
if ( V_252 -> V_257 ) {
V_252 -> V_257 = F_116 ( V_252 -> V_257 , V_218 ) ;
} else if ( V_252 -> V_255 ) {
V_252 -> V_257 = F_116 ( V_252 -> V_255 , V_218 ) ;
V_252 -> V_257 += V_218 ;
}
V_252 -> V_260 = F_115 ( V_252 -> V_260 , V_218 ) ;
if ( V_252 -> V_253 ) {
V_252 -> V_253 = F_116 ( V_252 -> V_253 ,
V_218 ) ;
V_252 -> V_253 += V_218 ;
}
if ( ! V_252 -> V_256 || ! V_252 -> V_257 )
return - 1 ;
if ( V_252 -> V_260 && ! V_252 -> V_253 )
return - 1 ;
return F_113 ( V_252 , V_4 ) ;
}
static int F_117 ( const char * V_268 , const char * V_269 ,
const char * V_34 )
{
char V_270 [ V_167 ] ;
char V_271 [ V_167 ] ;
F_105 ( V_270 , V_167 , L_37 , V_268 , V_34 ) ;
F_105 ( V_271 , V_167 , L_37 , V_269 , V_34 ) ;
return F_118 ( V_270 , V_271 , 0400 ) ;
}
static int F_119 ( const char * V_258 , const char * V_34 )
{
char V_93 [ V_167 ] ;
F_105 ( V_93 , V_167 , L_37 , V_258 , V_34 ) ;
return F_52 ( V_93 ) ;
}
static int F_120 ( int V_211 , int V_213 )
{
char * V_272 ;
char * V_273 ;
V_100 V_274 ;
T_3 V_215 ;
int V_59 = - 1 ;
V_272 = malloc ( V_218 ) ;
V_273 = malloc ( V_218 ) ;
if ( ! V_272 || ! V_273 )
goto V_83;
while ( 1 ) {
V_274 = F_45 ( V_211 , V_272 , V_218 ) ;
if ( V_274 < 0 )
goto V_83;
if ( ! V_274 )
break;
V_215 = V_274 ;
if ( F_121 ( V_213 , V_273 , V_215 ) != ( int ) V_215 )
goto V_83;
if ( memcmp ( V_272 , V_273 , V_215 ) )
goto V_83;
}
V_59 = 0 ;
V_83:
free ( V_273 ) ;
free ( V_272 ) ;
return V_59 ;
}
static int F_122 ( const char * V_270 ,
const char * V_271 )
{
int V_211 , V_213 , V_59 = - 1 ;
V_211 = F_39 ( V_270 , V_95 ) ;
if ( V_211 < 0 )
return - 1 ;
V_213 = F_39 ( V_271 , V_95 ) ;
if ( V_213 < 0 )
goto V_275;
V_59 = F_120 ( V_211 , V_213 ) ;
F_43 ( V_213 ) ;
V_275:
F_43 ( V_211 ) ;
return V_59 ;
}
static int F_123 ( const char * V_268 , const char * V_269 ,
const char * V_34 )
{
char V_270 [ V_167 ] ;
char V_271 [ V_167 ] ;
F_105 ( V_270 , V_167 , L_37 , V_268 , V_34 ) ;
F_105 ( V_271 , V_167 , L_37 , V_269 , V_34 ) ;
return F_122 ( V_270 , V_271 ) ;
}
int F_124 ( const char * V_268 , const char * V_269 )
{
struct V_220 V_220 ;
struct V_220 V_276 ;
T_3 V_229 = 2 ;
int V_35 = 0 , V_59 = - 1 ;
T_22 V_164 = V_218 , V_92 , V_277 = 0 ;
struct V_251 V_252 = { . V_256 = 0 , } ;
char V_278 [ V_167 ] ;
char V_279 [ V_167 ] ;
if ( F_117 ( V_268 , V_269 , L_38 ) )
return - 1 ;
if ( F_117 ( V_268 , V_269 , L_39 ) )
goto V_280;
F_105 ( V_278 , V_167 , L_40 , V_268 ) ;
F_105 ( V_279 , V_167 , L_40 , V_269 ) ;
if ( F_91 ( & V_220 , V_278 ) )
goto V_281;
if ( F_114 ( & V_252 , V_268 , V_220 . V_4 ) )
goto V_282;
if ( F_92 ( & V_276 , V_279 , V_220 . V_222 , false ) )
goto V_282;
if ( ! V_252 . V_267 . V_27 )
V_229 -= 1 ;
if ( F_95 ( & V_220 , & V_276 , V_229 ) )
goto V_283;
if ( F_98 ( & V_276 , V_35 ++ , V_164 , V_252 . V_266 . V_27 ,
V_252 . V_266 . V_215 ) )
goto V_283;
if ( V_252 . V_267 . V_27 ) {
V_277 = V_164 + V_252 . V_266 . V_215 ;
if ( F_98 ( & V_276 , V_35 , V_277 ,
V_252 . V_267 . V_27 , V_252 . V_267 . V_215 ) )
goto V_283;
}
V_92 = F_100 ( & V_276 ) ;
if ( V_92 < 0 || V_92 > V_164 )
goto V_283;
if ( F_88 ( V_220 . V_94 , V_252 . V_266 . V_164 , V_276 . V_94 , V_164 ,
V_252 . V_266 . V_215 ) )
goto V_283;
if ( V_277 && F_88 ( V_220 . V_94 , V_252 . V_267 . V_164 ,
V_276 . V_94 , V_277 ,
V_252 . V_267 . V_215 ) )
goto V_283;
if ( F_123 ( V_268 , V_269 , L_39 ) )
goto V_283;
if ( F_123 ( V_268 , V_269 , L_38 ) )
goto V_283;
V_59 = 0 ;
V_283:
F_94 ( & V_276 ) ;
if ( V_59 )
F_52 ( V_279 ) ;
V_282:
F_94 ( & V_220 ) ;
V_281:
if ( V_59 )
F_119 ( V_269 , L_39 ) ;
V_280:
if ( V_59 )
F_119 ( V_269 , L_38 ) ;
return V_59 ;
}
int F_125 ( struct V_284 * V_285 )
{
struct V_220 V_220 ;
struct V_220 V_276 ;
T_3 V_229 = 1 ;
int V_35 = 0 , V_59 = - 1 ;
T_22 V_164 = V_218 , V_92 ;
if ( F_91 ( & V_220 , V_285 -> V_278 ) )
return - 1 ;
strcpy ( V_285 -> V_279 , V_286 ) ;
if ( F_92 ( & V_276 , V_285 -> V_279 , V_220 . V_222 , true ) )
goto V_282;
if ( F_95 ( & V_220 , & V_276 , V_229 ) )
goto V_283;
if ( F_98 ( & V_276 , V_35 , V_164 , V_285 -> V_27 , V_285 -> V_215 ) )
goto V_283;
V_92 = F_100 ( & V_276 ) ;
if ( V_92 < 0 || V_92 > V_164 )
goto V_283;
if ( F_88 ( V_220 . V_94 , V_285 -> V_287 , V_276 . V_94 , V_164 , V_285 -> V_215 ) )
goto V_283;
V_59 = 0 ;
V_283:
F_94 ( & V_276 ) ;
if ( V_59 )
F_52 ( V_285 -> V_279 ) ;
V_282:
F_94 ( & V_220 ) ;
return V_59 ;
}
void F_126 ( struct V_284 * V_285 )
{
F_52 ( V_285 -> V_279 ) ;
}
void F_127 ( void )
{
F_128 ( V_288 ) ;
}
