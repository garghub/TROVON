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
if ( ( type != V_114 &&
type != V_115 ) ||
type != V_38 -> V_116 )
return - 1 ;
if ( ! V_112 || ! F_49 ( V_112 + 1 ) )
return - 1 ;
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
V_38 -> V_116 = V_143 -> type ;
V_38 -> V_122 = V_143 -> V_122 ;
V_38 -> V_153 = V_143 -> V_7 . V_133 == V_135 ;
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
const char * V_154 = F_11 ( & V_9 , V_22 ) ;
if ( strcmp ( V_154 , V_136 -> V_137 -> V_34 ) )
continue;
V_136 -> V_137 -> V_138 = V_9 . V_155 ;
V_41 -> V_156 = V_136 -> V_137 -> V_27 -
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
const char * V_154 = F_11 ( & V_9 , V_22 ) ;
char * V_157 = NULL ;
int V_158 = F_9 ( & V_9 ) ;
const char * V_159 ;
bool V_160 = false ;
if ( ! V_158 && ! F_10 ( & V_9 , V_41 -> type ) )
continue;
if ( V_7 . V_161 == V_162 ) {
if ( ! strcmp ( V_154 , L_21 ) ||
! strcmp ( V_154 , L_22 ) ||
! strcmp ( V_154 , L_23 ) )
continue;
}
if ( V_144 -> V_117 && V_9 . V_14 == V_144 -> V_127 ) {
T_19 V_163 = V_9 . V_155 - V_143 -> V_128 . V_30 ;
T_13 * V_164 = V_149 -> V_23 + V_163 ;
V_9 . V_155 = F_70 ( V_38 , T_13 , * V_164 ) ;
V_9 . V_14 = F_16 ( V_144 -> V_4 ,
V_9 . V_155 ) ;
V_160 = true ;
}
if ( V_9 . V_14 == V_18 )
continue;
V_28 = F_21 ( V_144 -> V_4 , V_9 . V_14 ) ;
if ( ! V_28 )
goto V_62;
F_18 ( V_28 , & V_24 ) ;
if ( V_158 && ! F_15 ( & V_24 , V_25 , V_41 -> type ) )
continue;
V_159 = F_12 ( & V_24 , V_25 ) ;
if ( ( V_7 . V_161 == V_162 ) &&
( V_41 -> type == V_20 ) &&
( V_9 . V_155 & 1 ) )
-- V_9 . V_155 ;
if ( V_38 -> V_130 || V_145 ) {
char V_165 [ V_166 ] ;
if ( V_152 )
V_9 . V_155 -= V_24 . V_30 - V_24 . V_66 ;
if ( strcmp ( V_159 ,
( V_147 -> V_167 +
V_38 -> V_168 ) ) == 0 )
goto V_169;
if ( strcmp ( V_159 , L_24 ) == 0 ) {
if ( V_151 && V_38 -> V_130 ) {
V_151 = false ;
V_41 -> V_170 = V_24 . V_30 +
F_64 ( V_136 ) ;
V_41 -> V_171 = V_41 -> V_170 + V_24 . V_31 ;
V_41 -> V_172 = V_24 . V_66 ;
V_41 -> V_173 = V_174 ;
V_41 -> V_175 = V_176 ;
F_71 ( V_136 -> V_177 , V_41 ) ;
F_72 ( V_136 -> V_177 , V_41 ) ;
}
if ( V_151 && V_145 ) {
V_151 = false ;
V_41 -> V_172 = V_24 . V_66 ;
}
V_146 = V_41 ;
V_147 = V_38 ;
goto V_169;
}
if ( ! V_136 )
goto V_169;
snprintf ( V_165 , sizeof( V_165 ) ,
L_25 , V_38 -> V_167 , V_159 ) ;
V_146 = F_73 ( V_136 -> V_177 , V_41 -> type , V_165 ) ;
if ( V_146 == NULL ) {
T_13 V_170 = V_9 . V_155 ;
if ( V_145 )
V_170 += V_41 -> V_170 + V_24 . V_66 ;
V_147 = F_74 ( V_165 ) ;
if ( V_147 == NULL )
goto V_62;
V_147 -> V_130 = V_38 -> V_130 ;
V_147 -> V_76 = V_38 -> V_76 ;
V_147 -> V_178 = V_38 -> V_178 ;
V_146 = F_75 ( V_170 , V_147 ,
V_41 -> type ) ;
if ( V_146 == NULL ) {
F_76 ( V_147 ) ;
goto V_62;
}
if ( V_152 ) {
V_146 -> V_170 = V_24 . V_30 +
F_64 ( V_136 ) ;
V_146 -> V_171 = V_146 -> V_170 +
V_24 . V_31 ;
V_146 -> V_172 = V_24 . V_66 ;
} else {
V_146 -> V_173 = V_179 ;
V_146 -> V_175 = V_179 ;
}
V_147 -> V_116 = V_38 -> V_116 ;
F_72 ( V_136 -> V_177 , V_146 ) ;
F_77 ( & V_41 -> V_180 -> V_181 -> V_182 ,
V_147 ) ;
F_78 ( V_147 , V_41 -> type ) ;
} else
V_147 = V_146 -> V_38 ;
goto V_169;
}
if ( ( V_160 && V_144 -> V_132 )
|| ( ! V_160 && V_143 -> V_132 ) ) {
F_79 ( L_26 V_183 L_27
L_28 V_183 L_29 V_183 L_30 , V_75 ,
( T_13 ) V_9 . V_155 , ( T_13 ) V_24 . V_30 ,
( T_13 ) V_24 . V_66 ) ;
V_9 . V_155 -= V_24 . V_30 - V_24 . V_66 ;
}
V_169:
if ( F_65 ( V_38 -> V_130 || V_145 ) ) {
int V_184 = V_185 ;
if ( V_186 )
V_184 = V_187 | V_188 ;
V_157 = F_1 ( NULL , V_154 , V_184 ) ;
if ( V_157 != NULL )
V_154 = V_157 ;
}
V_47 = F_28 ( V_9 . V_155 , V_9 . V_189 ,
F_80 ( V_9 . V_10 ) , V_154 ) ;
free ( V_157 ) ;
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
F_83 ( V_136 -> V_177 , V_41 -> type ) ;
}
}
V_59 = V_57 ;
V_62:
return V_59 ;
}
static int F_84 ( T_2 * V_4 , bool V_190 , T_20 V_191 , void * V_79 )
{
T_21 V_192 ;
T_3 V_3 , V_193 ;
int V_59 ;
T_13 V_92 ;
if ( F_3 ( V_4 , & V_193 ) )
return - 1 ;
for ( V_3 = 0 ; V_3 < V_193 ; V_3 ++ ) {
if ( F_85 ( V_4 , V_3 , & V_192 ) == NULL )
return - 1 ;
if ( V_192 . V_194 != V_195 )
continue;
if ( V_190 ) {
if ( ! ( V_192 . V_196 & V_197 ) )
continue;
} else {
if ( ! ( V_192 . V_196 & V_198 ) )
continue;
}
V_92 = F_37 ( V_192 . V_199 , V_192 . V_200 ) ;
if ( ! V_92 )
continue;
V_59 = V_191 ( V_192 . V_201 , V_92 , V_192 . V_202 , V_79 ) ;
if ( V_59 )
return V_59 ;
}
return 0 ;
}
int F_86 ( int V_94 , bool V_190 , T_20 V_191 , void * V_79 ,
bool * V_122 )
{
int V_59 ;
T_2 * V_4 ;
V_4 = F_40 ( V_94 , V_96 , NULL ) ;
if ( V_4 == NULL )
return - 1 ;
if ( V_122 )
* V_122 = ( F_60 ( V_4 ) == V_123 ) ;
V_59 = F_84 ( V_4 , V_190 , V_191 , V_79 ) ;
F_42 ( V_4 ) ;
return V_59 ;
}
enum V_203 F_87 ( int V_94 )
{
enum V_203 V_203 = V_204 ;
T_4 V_7 ;
T_16 V_80 ;
T_2 * V_4 ;
V_4 = F_40 ( V_94 , V_96 , NULL ) ;
if ( V_4 == NULL )
goto V_83;
V_80 = F_34 ( V_4 ) ;
if ( V_80 != V_84 )
goto V_205;
if ( F_60 ( V_4 ) == V_123 ) {
V_203 = V_206 ;
goto V_205;
}
if ( F_4 ( V_4 , & V_7 ) == NULL )
goto V_205;
if ( V_7 . V_161 == V_207 )
V_203 = V_208 ;
else
V_203 = V_209 ;
V_205:
F_42 ( V_4 ) ;
V_83:
return V_203 ;
}
static int F_88 ( int V_210 , T_22 V_211 , int V_212 , T_22 V_213 , T_13 V_214 )
{
V_100 V_215 ;
T_3 V_101 ;
int V_59 = - 1 ;
char * V_216 = malloc ( V_217 ) ;
if ( V_216 == NULL )
return - 1 ;
if ( F_89 ( V_212 , V_213 , V_218 ) != V_213 )
goto V_83;
if ( F_89 ( V_210 , V_211 , V_218 ) != V_211 )
goto V_83;
while ( V_214 ) {
V_101 = V_217 ;
if ( V_214 < V_101 )
V_101 = V_214 ;
V_215 = F_45 ( V_210 , V_216 , V_101 ) ;
if ( V_215 < 0 )
goto V_83;
if ( ! V_215 )
break;
V_101 = V_215 ;
V_215 = F_90 ( V_212 , V_216 , V_101 ) ;
if ( V_215 < 0 )
goto V_83;
if ( ( T_3 ) V_215 != V_101 )
goto V_83;
V_214 -= V_101 ;
}
V_59 = 0 ;
V_83:
free ( V_216 ) ;
return V_59 ;
}
static int F_91 ( struct V_219 * V_219 , const char * V_93 )
{
T_4 * V_7 ;
V_219 -> V_94 = F_39 ( V_93 , V_95 ) ;
if ( V_219 -> V_94 == - 1 )
return - 1 ;
V_219 -> V_4 = F_40 ( V_219 -> V_94 , V_220 , NULL ) ;
if ( ! V_219 -> V_4 )
goto V_97;
V_219 -> V_221 = F_60 ( V_219 -> V_4 ) ;
if ( V_219 -> V_221 == V_222 )
goto V_205;
V_7 = F_4 ( V_219 -> V_4 , & V_219 -> V_7 ) ;
if ( ! V_7 )
goto V_205;
return 0 ;
V_205:
F_42 ( V_219 -> V_4 ) ;
V_97:
F_43 ( V_219 -> V_94 ) ;
return - 1 ;
}
static int F_92 ( struct V_219 * V_219 , char * V_93 , int V_221 ,
bool V_223 )
{
T_4 * V_7 ;
V_219 -> V_221 = V_221 ;
if ( V_223 )
V_219 -> V_94 = F_50 ( V_93 ) ;
else
V_219 -> V_94 = F_39 ( V_93 , V_224 | V_225 | V_226 , 0400 ) ;
if ( V_219 -> V_94 == - 1 )
return - 1 ;
V_219 -> V_4 = F_40 ( V_219 -> V_94 , V_227 , NULL ) ;
if ( ! V_219 -> V_4 )
goto V_97;
if ( ! F_93 ( V_219 -> V_4 , V_221 ) )
goto V_205;
V_7 = F_4 ( V_219 -> V_4 , & V_219 -> V_7 ) ;
if ( ! V_7 )
goto V_205;
return 0 ;
V_205:
F_42 ( V_219 -> V_4 ) ;
V_97:
F_43 ( V_219 -> V_94 ) ;
F_52 ( V_93 ) ;
return - 1 ;
}
static void F_94 ( struct V_219 * V_219 )
{
F_42 ( V_219 -> V_4 ) ;
F_43 ( V_219 -> V_94 ) ;
}
static int F_95 ( struct V_219 * V_210 , struct V_219 * V_212 , T_3 V_228 )
{
T_4 * V_7 = & V_212 -> V_7 ;
T_4 * V_229 = & V_210 -> V_7 ;
memcpy ( V_7 -> V_119 , V_229 -> V_119 , V_230 ) ;
V_7 -> V_133 = V_229 -> V_133 ;
V_7 -> V_161 = V_229 -> V_161 ;
V_7 -> V_231 = V_229 -> V_231 ;
V_7 -> V_232 = 0 ;
V_7 -> V_233 = 0 ;
V_7 -> V_234 = V_229 -> V_234 ;
V_7 -> V_8 = V_228 ;
V_7 -> V_235 = 0 ;
V_7 -> V_236 = 0 ;
V_7 -> V_36 = 0 ;
if ( V_210 -> V_221 == V_237 ) {
V_7 -> V_238 = sizeof( V_239 ) ;
V_7 -> V_240 = sizeof( V_239 ) ;
V_7 -> V_241 = sizeof( V_242 ) ;
} else {
V_7 -> V_238 = sizeof( V_243 ) ;
V_7 -> V_240 = sizeof( V_243 ) ;
V_7 -> V_241 = sizeof( V_244 ) ;
}
if ( ! F_96 ( V_212 -> V_4 , V_7 ) )
return - 1 ;
if ( ! F_97 ( V_212 -> V_4 , V_228 ) )
return - 1 ;
return 0 ;
}
static int F_98 ( struct V_219 * V_219 , int V_35 , T_22 V_163 ,
T_13 V_27 , T_13 V_214 )
{
T_21 V_245 ;
T_21 * V_192 ;
V_192 = F_85 ( V_219 -> V_4 , V_35 , & V_245 ) ;
if ( ! V_192 )
return - 1 ;
V_192 -> V_194 = V_195 ;
V_192 -> V_196 = V_198 | V_246 | V_197 ;
V_192 -> V_202 = V_163 ;
V_192 -> V_201 = V_27 ;
V_192 -> V_247 = 0 ;
V_192 -> V_200 = V_214 ;
V_192 -> V_199 = V_214 ;
V_192 -> V_248 = V_217 ;
if ( ! F_99 ( V_219 -> V_4 , V_35 , V_192 ) )
return - 1 ;
return 0 ;
}
static T_22 F_100 ( struct V_219 * V_219 )
{
return F_101 ( V_219 -> V_4 , V_227 ) ;
}
static int F_102 ( void * V_249 , const char * V_34 , char type ,
T_13 V_170 )
{
struct V_250 * V_251 = V_249 ;
if ( ! F_103 ( type , V_20 ) )
return 0 ;
if ( strchr ( V_34 , '[' ) ) {
if ( V_170 > V_251 -> V_252 )
V_251 -> V_252 = V_170 ;
return 0 ;
}
if ( ! V_251 -> V_253 || V_170 < V_251 -> V_253 )
V_251 -> V_253 = V_170 ;
if ( ! V_251 -> V_254 || V_170 > V_251 -> V_254 )
V_251 -> V_254 = V_170 ;
if ( ! strcmp ( V_34 , L_31 ) ) {
V_251 -> V_255 = V_170 ;
return 0 ;
}
if ( ! strcmp ( V_34 , L_32 ) ) {
V_251 -> V_256 = V_170 ;
return 0 ;
}
return 0 ;
}
static int F_104 ( struct V_250 * V_251 ,
const char * V_257 )
{
char V_258 [ V_166 ] ;
F_105 ( V_258 , V_166 , L_33 , V_257 ) ;
if ( F_106 ( V_258 , L_34 ) )
return - 1 ;
if ( F_107 ( V_258 , V_251 ,
F_102 ) < 0 )
return - 1 ;
return 0 ;
}
static int F_108 ( void * V_249 ,
const char * V_34 T_1 ,
T_13 V_170 )
{
struct V_250 * V_251 = V_249 ;
if ( ! V_251 -> V_259 || V_170 < V_251 -> V_259 )
V_251 -> V_259 = V_170 ;
return 0 ;
}
static int F_109 ( struct V_250 * V_251 ,
const char * V_257 )
{
char V_260 [ V_166 ] ;
F_105 ( V_260 , V_166 , L_35 , V_257 ) ;
if ( F_106 ( V_260 , L_36 ) )
return - 1 ;
if ( F_110 ( V_260 , V_251 ,
F_108 ) < 0 )
return - 1 ;
return 0 ;
}
static void F_111 ( struct V_261 * V_262 , T_13 V_170 , T_13 V_171 , T_13 V_172 ,
T_13 V_263 , T_13 V_264 )
{
if ( V_262 -> V_27 || V_263 < V_170 || V_263 >= V_171 )
return;
V_262 -> V_27 = V_263 ;
V_262 -> V_163 = ( V_263 - V_170 ) + V_172 ;
V_262 -> V_214 = V_264 < V_171 ? V_264 - V_263 : V_171 - V_263 ;
}
static int F_112 ( T_13 V_170 , T_13 V_214 , T_13 V_172 , void * V_79 )
{
struct V_250 * V_251 = V_79 ;
T_13 V_171 = V_170 + V_214 ;
F_111 ( & V_251 -> V_265 , V_170 , V_171 , V_172 , V_251 -> V_255 ,
V_251 -> V_256 ) ;
F_111 ( & V_251 -> V_266 , V_170 , V_171 , V_172 , V_251 -> V_259 ,
V_251 -> V_252 ) ;
return 0 ;
}
static int F_113 ( struct V_250 * V_251 , T_2 * V_4 )
{
if ( F_84 ( V_4 , true , F_112 , V_251 ) < 0 )
return - 1 ;
return 0 ;
}
static int F_114 ( struct V_250 * V_251 , const char * V_257 ,
T_2 * V_4 )
{
if ( F_104 ( V_251 , V_257 ) )
return - 1 ;
if ( F_109 ( V_251 , V_257 ) )
return - 1 ;
if ( V_251 -> V_255 )
V_251 -> V_255 = F_115 ( V_251 -> V_255 , V_217 ) ;
else
V_251 -> V_255 = F_115 ( V_251 -> V_253 , V_217 ) ;
if ( V_251 -> V_256 ) {
V_251 -> V_256 = F_116 ( V_251 -> V_256 , V_217 ) ;
} else if ( V_251 -> V_254 ) {
V_251 -> V_256 = F_116 ( V_251 -> V_254 , V_217 ) ;
V_251 -> V_256 += V_217 ;
}
V_251 -> V_259 = F_115 ( V_251 -> V_259 , V_217 ) ;
if ( V_251 -> V_252 ) {
V_251 -> V_252 = F_116 ( V_251 -> V_252 ,
V_217 ) ;
V_251 -> V_252 += V_217 ;
}
if ( ! V_251 -> V_255 || ! V_251 -> V_256 )
return - 1 ;
if ( V_251 -> V_259 && ! V_251 -> V_252 )
return - 1 ;
return F_113 ( V_251 , V_4 ) ;
}
static int F_117 ( const char * V_267 , const char * V_268 ,
const char * V_34 )
{
char V_269 [ V_166 ] ;
char V_270 [ V_166 ] ;
F_105 ( V_269 , V_166 , L_37 , V_267 , V_34 ) ;
F_105 ( V_270 , V_166 , L_37 , V_268 , V_34 ) ;
return F_118 ( V_269 , V_270 , 0400 ) ;
}
static int F_119 ( const char * V_257 , const char * V_34 )
{
char V_93 [ V_166 ] ;
F_105 ( V_93 , V_166 , L_37 , V_257 , V_34 ) ;
return F_52 ( V_93 ) ;
}
static int F_120 ( int V_210 , int V_212 )
{
char * V_271 ;
char * V_272 ;
V_100 V_273 ;
T_3 V_214 ;
int V_59 = - 1 ;
V_271 = malloc ( V_217 ) ;
V_272 = malloc ( V_217 ) ;
if ( ! V_271 || ! V_272 )
goto V_83;
while ( 1 ) {
V_273 = F_45 ( V_210 , V_271 , V_217 ) ;
if ( V_273 < 0 )
goto V_83;
if ( ! V_273 )
break;
V_214 = V_273 ;
if ( F_121 ( V_212 , V_272 , V_214 ) != ( int ) V_214 )
goto V_83;
if ( memcmp ( V_271 , V_272 , V_214 ) )
goto V_83;
}
V_59 = 0 ;
V_83:
free ( V_272 ) ;
free ( V_271 ) ;
return V_59 ;
}
static int F_122 ( const char * V_269 ,
const char * V_270 )
{
int V_210 , V_212 , V_59 = - 1 ;
V_210 = F_39 ( V_269 , V_95 ) ;
if ( V_210 < 0 )
return - 1 ;
V_212 = F_39 ( V_270 , V_95 ) ;
if ( V_212 < 0 )
goto V_274;
V_59 = F_120 ( V_210 , V_212 ) ;
F_43 ( V_212 ) ;
V_274:
F_43 ( V_210 ) ;
return V_59 ;
}
static int F_123 ( const char * V_267 , const char * V_268 ,
const char * V_34 )
{
char V_269 [ V_166 ] ;
char V_270 [ V_166 ] ;
F_105 ( V_269 , V_166 , L_37 , V_267 , V_34 ) ;
F_105 ( V_270 , V_166 , L_37 , V_268 , V_34 ) ;
return F_122 ( V_269 , V_270 ) ;
}
int F_124 ( const char * V_267 , const char * V_268 )
{
struct V_219 V_219 ;
struct V_219 V_275 ;
T_3 V_228 = 2 ;
int V_35 = 0 , V_59 = - 1 ;
T_22 V_163 = V_217 , V_92 , V_276 = 0 ;
struct V_250 V_251 = { . V_255 = 0 , } ;
char V_277 [ V_166 ] ;
char V_278 [ V_166 ] ;
if ( F_117 ( V_267 , V_268 , L_38 ) )
return - 1 ;
if ( F_117 ( V_267 , V_268 , L_39 ) )
goto V_279;
F_105 ( V_277 , V_166 , L_40 , V_267 ) ;
F_105 ( V_278 , V_166 , L_40 , V_268 ) ;
if ( F_91 ( & V_219 , V_277 ) )
goto V_280;
if ( F_114 ( & V_251 , V_267 , V_219 . V_4 ) )
goto V_281;
if ( F_92 ( & V_275 , V_278 , V_219 . V_221 , false ) )
goto V_281;
if ( ! V_251 . V_266 . V_27 )
V_228 -= 1 ;
if ( F_95 ( & V_219 , & V_275 , V_228 ) )
goto V_282;
if ( F_98 ( & V_275 , V_35 ++ , V_163 , V_251 . V_265 . V_27 ,
V_251 . V_265 . V_214 ) )
goto V_282;
if ( V_251 . V_266 . V_27 ) {
V_276 = V_163 + V_251 . V_265 . V_214 ;
if ( F_98 ( & V_275 , V_35 , V_276 ,
V_251 . V_266 . V_27 , V_251 . V_266 . V_214 ) )
goto V_282;
}
V_92 = F_100 ( & V_275 ) ;
if ( V_92 < 0 || V_92 > V_163 )
goto V_282;
if ( F_88 ( V_219 . V_94 , V_251 . V_265 . V_163 , V_275 . V_94 , V_163 ,
V_251 . V_265 . V_214 ) )
goto V_282;
if ( V_276 && F_88 ( V_219 . V_94 , V_251 . V_266 . V_163 ,
V_275 . V_94 , V_276 ,
V_251 . V_266 . V_214 ) )
goto V_282;
if ( F_123 ( V_267 , V_268 , L_39 ) )
goto V_282;
if ( F_123 ( V_267 , V_268 , L_38 ) )
goto V_282;
V_59 = 0 ;
V_282:
F_94 ( & V_275 ) ;
if ( V_59 )
F_52 ( V_278 ) ;
V_281:
F_94 ( & V_219 ) ;
V_280:
if ( V_59 )
F_119 ( V_268 , L_39 ) ;
V_279:
if ( V_59 )
F_119 ( V_268 , L_38 ) ;
return V_59 ;
}
int F_125 ( struct V_283 * V_284 )
{
struct V_219 V_219 ;
struct V_219 V_275 ;
T_3 V_228 = 1 ;
int V_35 = 0 , V_59 = - 1 ;
T_22 V_163 = V_217 , V_92 ;
if ( F_91 ( & V_219 , V_284 -> V_277 ) )
return - 1 ;
strcpy ( V_284 -> V_278 , V_285 ) ;
if ( F_92 ( & V_275 , V_284 -> V_278 , V_219 . V_221 , true ) )
goto V_281;
if ( F_95 ( & V_219 , & V_275 , V_228 ) )
goto V_282;
if ( F_98 ( & V_275 , V_35 , V_163 , V_284 -> V_27 , V_284 -> V_214 ) )
goto V_282;
V_92 = F_100 ( & V_275 ) ;
if ( V_92 < 0 || V_92 > V_163 )
goto V_282;
if ( F_88 ( V_219 . V_94 , V_284 -> V_286 , V_275 . V_94 , V_163 , V_284 -> V_214 ) )
goto V_282;
V_59 = 0 ;
V_282:
F_94 ( & V_275 ) ;
if ( V_59 )
F_52 ( V_284 -> V_278 ) ;
V_281:
F_94 ( & V_219 ) ;
return V_59 ;
}
void F_126 ( struct V_283 * V_284 )
{
F_52 ( V_284 -> V_278 ) ;
}
void F_127 ( void )
{
F_128 ( V_287 ) ;
}
