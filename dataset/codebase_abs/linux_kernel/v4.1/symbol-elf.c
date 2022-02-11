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
int V_94 = - 1 ;
char V_112 [] = L_16 ;
struct V_113 V_114 ;
if ( type != V_115 &&
type != V_116 &&
type != V_117 )
return - 1 ;
if ( type == V_117 )
V_34 = V_38 -> V_76 ;
if ( F_49 ( & V_114 , V_34 ) || ! V_114 . V_118 )
return - 1 ;
V_94 = F_50 ( V_112 ) ;
if ( V_94 < 0 ) {
V_38 -> V_119 = V_120 ;
goto V_83;
}
if ( ! F_51 ( V_114 . V_121 , V_34 , V_94 ) ) {
V_38 -> V_119 = V_122 ;
F_43 ( V_94 ) ;
V_94 = - 1 ;
}
F_52 ( V_112 ) ;
V_83:
free ( V_114 . V_121 ) ;
return V_94 ;
}
bool F_53 ( struct V_39 * V_40 )
{
return V_40 -> V_60 || V_40 -> V_123 ;
}
bool F_54 ( struct V_39 * V_40 )
{
return V_40 -> V_124 != NULL ;
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
if ( F_58 ( V_38 ) ) {
V_94 = F_48 ( V_38 , V_34 , type ) ;
if ( V_94 < 0 )
return - 1 ;
} else {
V_94 = F_39 ( V_34 , V_95 ) ;
if ( V_94 < 0 ) {
V_38 -> V_119 = V_120 ;
return - 1 ;
}
}
V_4 = F_40 ( V_94 , V_96 , NULL ) ;
if ( V_4 == NULL ) {
F_32 ( L_13 , V_75 , V_34 ) ;
V_38 -> V_119 = V_125 ;
goto V_97;
}
if ( F_4 ( V_4 , & V_7 ) == NULL ) {
V_38 -> V_119 = V_125 ;
F_32 ( L_8 , V_75 ) ;
goto V_62;
}
if ( F_47 ( V_38 , V_7 . V_126 [ V_127 ] ) ) {
V_38 -> V_119 = V_128 ;
goto V_62;
}
if ( V_38 -> V_129 ) {
T_18 V_98 [ V_82 ] ;
if ( F_33 ( V_4 , V_98 , V_82 ) < 0 ) {
V_38 -> V_119 = V_130 ;
goto V_62;
}
if ( ! F_59 ( V_38 , V_98 ) ) {
V_38 -> V_119 = V_131 ;
goto V_62;
}
}
V_40 -> V_132 = ( F_60 ( V_4 ) == V_133 ) ;
V_40 -> V_124 = F_19 ( V_4 , & V_7 , & V_40 -> V_134 , L_17 ,
NULL ) ;
if ( V_40 -> V_134 . V_67 != V_135 )
V_40 -> V_124 = NULL ;
V_40 -> V_55 = 0 ;
V_40 -> V_60 = F_19 ( V_4 , & V_7 , & V_40 -> V_61 , L_18 ,
& V_40 -> V_55 ) ;
if ( V_40 -> V_61 . V_67 != V_136 )
V_40 -> V_60 = NULL ;
V_40 -> V_137 = 0 ;
V_40 -> V_123 = F_19 ( V_4 , & V_7 , & V_40 -> V_138 , L_19 ,
& V_40 -> V_137 ) ;
if ( V_40 -> V_138 . V_67 != V_139 )
V_40 -> V_123 = NULL ;
if ( V_38 -> V_140 == V_141 ) {
T_8 V_24 ;
V_40 -> V_142 = ( V_7 . V_143 == V_144 ||
V_7 . V_143 == V_145 ||
F_61 ( V_38 ) ||
F_19 ( V_4 , & V_7 , & V_24 ,
L_20 ,
NULL ) != NULL ) ;
} else {
V_40 -> V_142 = V_7 . V_143 == V_144 ||
V_7 . V_143 == V_145 ;
}
V_40 -> V_34 = F_62 ( V_34 ) ;
if ( ! V_40 -> V_34 ) {
V_38 -> V_119 = V_120 ;
goto V_62;
}
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
static bool F_63 ( struct V_146 * V_146 )
{
return V_146 && V_146 -> V_147 && V_146 -> V_147 -> V_34 &&
! V_146 -> V_147 -> V_148 ;
}
static T_13 F_64 ( struct V_146 * V_146 )
{
if ( V_146 && V_146 -> V_147 &&
V_146 -> V_147 -> V_148 )
return V_146 -> V_147 -> V_27 -
V_146 -> V_147 -> V_148 ;
return 0 ;
}
static bool F_65 ( bool V_149 )
{
return V_149 ? V_150 . V_151 : V_150 . V_152 ;
}
int F_66 ( struct V_38 * V_38 , struct V_41 * V_41 ,
struct V_39 * V_153 , struct V_39 * V_154 ,
T_11 V_42 , int V_155 )
{
struct V_146 * V_146 = V_38 -> V_140 ? F_67 ( V_41 ) : NULL ;
struct V_156 * V_157 = V_146 ? F_68 ( V_41 ) : NULL ;
struct V_41 * V_158 = V_41 ;
struct V_38 * V_159 = V_38 ;
T_7 * V_22 , * V_25 ;
T_12 V_160 ;
int V_59 = - 1 ;
T_12 V_35 ;
T_4 V_7 ;
T_8 V_24 ;
T_7 * V_51 , * V_161 = NULL ;
T_6 V_9 ;
T_10 * V_28 , * V_162 ;
T_2 * V_4 ;
int V_57 = 0 ;
bool V_163 = false , V_164 = false ;
if ( V_146 && ! V_157 )
return - 1 ;
V_38 -> V_165 = V_153 -> type ;
V_38 -> V_132 = V_153 -> V_132 ;
V_38 -> V_166 = V_153 -> V_7 . V_143 == V_145 ;
if ( V_155 && V_153 -> V_124 )
F_69 ( & V_38 -> V_73 [ V_41 -> type ] ) ;
if ( ! V_153 -> V_124 ) {
if ( V_38 -> V_140 )
goto V_62;
V_153 -> V_124 = V_153 -> V_60 ;
V_153 -> V_134 = V_153 -> V_61 ;
}
V_4 = V_153 -> V_4 ;
V_7 = V_153 -> V_7 ;
V_28 = V_153 -> V_124 ;
V_24 = V_153 -> V_134 ;
if ( V_154 -> V_123 )
V_161 = F_20 ( V_154 -> V_123 , NULL ) ;
V_51 = F_24 ( V_28 , NULL ) ;
if ( V_51 == NULL )
goto V_62;
V_28 = F_21 ( V_4 , V_24 . V_63 ) ;
if ( V_28 == NULL )
goto V_62;
V_22 = F_24 ( V_28 , NULL ) ;
if ( V_22 == NULL )
goto V_62;
V_162 = F_21 ( V_154 -> V_4 , V_154 -> V_7 . V_36 ) ;
if ( V_162 == NULL )
goto V_62;
V_25 = F_24 ( V_162 , NULL ) ;
if ( V_25 == NULL )
goto V_62;
V_160 = V_24 . V_31 / V_24 . V_65 ;
memset ( & V_9 , 0 , sizeof( V_9 ) ) ;
if ( F_63 ( V_146 ) ) {
F_70 (syms, nr_syms, idx, sym) {
const char * V_167 = F_11 ( & V_9 , V_22 ) ;
if ( strcmp ( V_167 , V_146 -> V_147 -> V_34 ) )
continue;
V_146 -> V_147 -> V_148 = V_9 . V_168 ;
V_41 -> V_169 = V_146 -> V_147 -> V_27 -
V_146 -> V_147 -> V_148 ;
break;
}
}
V_38 -> V_142 = V_154 -> V_142 || F_64 ( V_146 ) ;
if ( V_41 -> type == V_20 && ( V_38 -> V_140 || V_155 ) ) {
V_163 = true ;
V_164 = V_38 -> V_142 ;
}
F_70 (syms, nr_syms, idx, sym) {
struct V_46 * V_47 ;
const char * V_167 = F_11 ( & V_9 , V_22 ) ;
char * V_170 = NULL ;
int V_171 = F_9 ( & V_9 ) ;
const char * V_172 ;
bool V_173 = false ;
if ( ! V_171 && ! F_10 ( & V_9 , V_41 -> type ) )
continue;
if ( V_7 . V_174 == V_175 || V_7 . V_174 == V_176 ) {
if ( V_167 [ 0 ] == '$' && strchr ( L_21 , V_167 [ 1 ] )
&& ( V_167 [ 2 ] == '\0' || V_167 [ 2 ] == '.' ) )
continue;
}
if ( V_154 -> V_123 && V_9 . V_14 == V_154 -> V_137 ) {
T_19 V_177 = V_9 . V_168 - V_153 -> V_138 . V_30 ;
T_13 * V_178 = V_161 -> V_23 + V_177 ;
V_9 . V_168 = F_71 ( V_38 , T_13 , * V_178 ) ;
V_9 . V_14 = F_16 ( V_154 -> V_4 ,
V_9 . V_168 ) ;
V_173 = true ;
}
if ( V_9 . V_14 == V_18 )
continue;
V_28 = F_21 ( V_154 -> V_4 , V_9 . V_14 ) ;
if ( ! V_28 )
goto V_62;
F_18 ( V_28 , & V_24 ) ;
if ( V_171 && ! F_15 ( & V_24 , V_25 , V_41 -> type ) )
continue;
V_172 = F_12 ( & V_24 , V_25 ) ;
if ( ( V_7 . V_174 == V_175 ) &&
( V_41 -> type == V_20 ) &&
( V_9 . V_168 & 1 ) )
-- V_9 . V_168 ;
if ( V_38 -> V_140 || V_155 ) {
char V_179 [ V_180 ] ;
if ( V_164 )
V_9 . V_168 -= V_24 . V_30 - V_24 . V_66 ;
if ( strcmp ( V_172 ,
( V_159 -> V_181 +
V_38 -> V_182 ) ) == 0 )
goto V_183;
if ( strcmp ( V_172 , L_22 ) == 0 ) {
if ( V_163 && V_38 -> V_140 ) {
V_163 = false ;
V_41 -> V_184 = V_24 . V_30 +
F_64 ( V_146 ) ;
V_41 -> V_185 = V_41 -> V_184 + V_24 . V_31 ;
V_41 -> V_186 = V_24 . V_66 ;
V_41 -> V_187 = V_188 ;
V_41 -> V_189 = V_190 ;
if ( V_157 ) {
F_72 ( V_157 , V_41 ) ;
F_73 ( V_157 , V_41 ) ;
}
}
if ( V_163 && V_155 ) {
V_163 = false ;
V_41 -> V_186 = V_24 . V_66 ;
}
V_158 = V_41 ;
V_159 = V_38 ;
goto V_183;
}
if ( ! V_146 )
goto V_183;
snprintf ( V_179 , sizeof( V_179 ) ,
L_23 , V_38 -> V_181 , V_172 ) ;
V_158 = F_74 ( V_157 , V_41 -> type , V_179 ) ;
if ( V_158 == NULL ) {
T_13 V_184 = V_9 . V_168 ;
if ( V_155 )
V_184 += V_41 -> V_184 + V_24 . V_66 ;
V_159 = F_75 ( V_179 ) ;
if ( V_159 == NULL )
goto V_62;
V_159 -> V_140 = V_38 -> V_140 ;
V_159 -> V_76 = V_38 -> V_76 ;
V_159 -> V_191 = V_38 -> V_191 ;
V_158 = F_76 ( V_184 , V_159 ,
V_41 -> type ) ;
if ( V_158 == NULL ) {
F_77 ( V_159 ) ;
goto V_62;
}
if ( V_164 ) {
V_158 -> V_184 = V_24 . V_30 +
F_64 ( V_146 ) ;
V_158 -> V_185 = V_158 -> V_184 +
V_24 . V_31 ;
V_158 -> V_186 = V_24 . V_66 ;
} else {
V_158 -> V_187 = V_192 ;
V_158 -> V_189 = V_192 ;
}
V_159 -> V_165 = V_38 -> V_165 ;
F_73 ( V_157 , V_158 ) ;
F_78 ( & V_41 -> V_193 -> V_194 -> V_195 ,
V_159 ) ;
F_79 ( V_159 , V_41 -> type ) ;
} else
V_159 = V_158 -> V_38 ;
goto V_183;
}
if ( ( V_173 && V_154 -> V_142 )
|| ( ! V_173 && V_153 -> V_142 ) ) {
F_80 ( L_24 V_196 L_25
L_26 V_196 L_27 V_196 L_28 , V_75 ,
( T_13 ) V_9 . V_168 , ( T_13 ) V_24 . V_30 ,
( T_13 ) V_24 . V_66 ) ;
V_9 . V_168 -= V_24 . V_30 - V_24 . V_66 ;
}
V_183:
if ( F_65 ( V_38 -> V_140 || V_155 ) ) {
int V_197 = V_198 ;
if ( V_199 )
V_197 = V_200 | V_201 ;
V_170 = F_1 ( NULL , V_167 , V_197 ) ;
if ( V_170 != NULL )
V_167 = V_170 ;
}
V_47 = F_28 ( V_9 . V_168 , V_9 . V_202 ,
F_81 ( V_9 . V_10 ) , V_167 ) ;
free ( V_170 ) ;
if ( ! V_47 )
goto V_62;
if ( V_42 && V_42 ( V_158 , V_47 ) )
F_29 ( V_47 ) ;
else {
F_30 ( & V_159 -> V_73 [ V_158 -> type ] , V_47 ) ;
V_57 ++ ;
}
}
if ( V_57 > 0 ) {
if ( ! V_150 . V_203 )
F_82 ( & V_38 -> V_73 [ V_41 -> type ] ) ;
F_83 ( & V_38 -> V_73 [ V_41 -> type ] ) ;
if ( V_146 ) {
F_84 ( V_157 , V_41 -> type ) ;
}
}
V_59 = V_57 ;
V_62:
return V_59 ;
}
static int F_85 ( T_2 * V_4 , bool V_204 , T_20 V_205 , void * V_79 )
{
T_21 V_206 ;
T_3 V_3 , V_207 ;
int V_59 ;
T_13 V_92 ;
if ( F_3 ( V_4 , & V_207 ) )
return - 1 ;
for ( V_3 = 0 ; V_3 < V_207 ; V_3 ++ ) {
if ( F_86 ( V_4 , V_3 , & V_206 ) == NULL )
return - 1 ;
if ( V_206 . V_208 != V_209 )
continue;
if ( V_204 ) {
if ( ! ( V_206 . V_210 & V_211 ) )
continue;
} else {
if ( ! ( V_206 . V_210 & V_212 ) )
continue;
}
V_92 = F_37 ( V_206 . V_213 , V_206 . V_214 ) ;
if ( ! V_92 )
continue;
V_59 = V_205 ( V_206 . V_215 , V_92 , V_206 . V_216 , V_79 ) ;
if ( V_59 )
return V_59 ;
}
return 0 ;
}
int F_87 ( int V_94 , bool V_204 , T_20 V_205 , void * V_79 ,
bool * V_132 )
{
int V_59 ;
T_2 * V_4 ;
V_4 = F_40 ( V_94 , V_96 , NULL ) ;
if ( V_4 == NULL )
return - 1 ;
if ( V_132 )
* V_132 = ( F_60 ( V_4 ) == V_133 ) ;
V_59 = F_85 ( V_4 , V_204 , V_205 , V_79 ) ;
F_42 ( V_4 ) ;
return V_59 ;
}
enum V_217 F_88 ( int V_94 )
{
enum V_217 V_217 = V_218 ;
T_4 V_7 ;
T_16 V_80 ;
T_2 * V_4 ;
V_4 = F_40 ( V_94 , V_96 , NULL ) ;
if ( V_4 == NULL )
goto V_83;
V_80 = F_34 ( V_4 ) ;
if ( V_80 != V_84 )
goto V_219;
if ( F_60 ( V_4 ) == V_133 ) {
V_217 = V_220 ;
goto V_219;
}
if ( F_4 ( V_4 , & V_7 ) == NULL )
goto V_219;
if ( V_7 . V_174 == V_221 )
V_217 = V_222 ;
else
V_217 = V_223 ;
V_219:
F_42 ( V_4 ) ;
V_83:
return V_217 ;
}
static int F_89 ( int V_224 , T_22 V_225 , int V_226 , T_22 V_227 , T_13 V_228 )
{
V_100 V_229 ;
T_3 V_101 ;
int V_59 = - 1 ;
char * V_230 = malloc ( V_231 ) ;
if ( V_230 == NULL )
return - 1 ;
if ( F_90 ( V_226 , V_227 , V_232 ) != V_227 )
goto V_83;
if ( F_90 ( V_224 , V_225 , V_232 ) != V_225 )
goto V_83;
while ( V_228 ) {
V_101 = V_231 ;
if ( V_228 < V_101 )
V_101 = V_228 ;
V_229 = F_45 ( V_224 , V_230 , V_101 ) ;
if ( V_229 < 0 )
goto V_83;
if ( ! V_229 )
break;
V_101 = V_229 ;
V_229 = F_91 ( V_226 , V_230 , V_101 ) ;
if ( V_229 < 0 )
goto V_83;
if ( ( T_3 ) V_229 != V_101 )
goto V_83;
V_228 -= V_101 ;
}
V_59 = 0 ;
V_83:
free ( V_230 ) ;
return V_59 ;
}
static int F_92 ( struct V_233 * V_233 , const char * V_93 )
{
T_4 * V_7 ;
V_233 -> V_94 = F_39 ( V_93 , V_95 ) ;
if ( V_233 -> V_94 == - 1 )
return - 1 ;
V_233 -> V_4 = F_40 ( V_233 -> V_94 , V_234 , NULL ) ;
if ( ! V_233 -> V_4 )
goto V_97;
V_233 -> V_235 = F_60 ( V_233 -> V_4 ) ;
if ( V_233 -> V_235 == V_236 )
goto V_219;
V_7 = F_4 ( V_233 -> V_4 , & V_233 -> V_7 ) ;
if ( ! V_7 )
goto V_219;
return 0 ;
V_219:
F_42 ( V_233 -> V_4 ) ;
V_97:
F_43 ( V_233 -> V_94 ) ;
return - 1 ;
}
static int F_93 ( struct V_233 * V_233 , char * V_93 , int V_235 ,
bool V_237 )
{
T_4 * V_7 ;
V_233 -> V_235 = V_235 ;
if ( V_237 )
V_233 -> V_94 = F_50 ( V_93 ) ;
else
V_233 -> V_94 = F_39 ( V_93 , V_238 | V_239 | V_240 , 0400 ) ;
if ( V_233 -> V_94 == - 1 )
return - 1 ;
V_233 -> V_4 = F_40 ( V_233 -> V_94 , V_241 , NULL ) ;
if ( ! V_233 -> V_4 )
goto V_97;
if ( ! F_94 ( V_233 -> V_4 , V_235 ) )
goto V_219;
V_7 = F_4 ( V_233 -> V_4 , & V_233 -> V_7 ) ;
if ( ! V_7 )
goto V_219;
return 0 ;
V_219:
F_42 ( V_233 -> V_4 ) ;
V_97:
F_43 ( V_233 -> V_94 ) ;
F_52 ( V_93 ) ;
return - 1 ;
}
static void F_95 ( struct V_233 * V_233 )
{
F_42 ( V_233 -> V_4 ) ;
F_43 ( V_233 -> V_94 ) ;
}
static int F_96 ( struct V_233 * V_224 , struct V_233 * V_226 , T_3 V_242 )
{
T_4 * V_7 = & V_226 -> V_7 ;
T_4 * V_243 = & V_224 -> V_7 ;
memcpy ( V_7 -> V_126 , V_243 -> V_126 , V_244 ) ;
V_7 -> V_143 = V_243 -> V_143 ;
V_7 -> V_174 = V_243 -> V_174 ;
V_7 -> V_245 = V_243 -> V_245 ;
V_7 -> V_246 = 0 ;
V_7 -> V_247 = 0 ;
V_7 -> V_248 = V_243 -> V_248 ;
V_7 -> V_8 = V_242 ;
V_7 -> V_249 = 0 ;
V_7 -> V_250 = 0 ;
V_7 -> V_36 = 0 ;
if ( V_224 -> V_235 == V_251 ) {
V_7 -> V_252 = sizeof( V_253 ) ;
V_7 -> V_254 = sizeof( V_253 ) ;
V_7 -> V_255 = sizeof( V_256 ) ;
} else {
V_7 -> V_252 = sizeof( V_257 ) ;
V_7 -> V_254 = sizeof( V_257 ) ;
V_7 -> V_255 = sizeof( V_258 ) ;
}
if ( ! F_97 ( V_226 -> V_4 , V_7 ) )
return - 1 ;
if ( ! F_98 ( V_226 -> V_4 , V_242 ) )
return - 1 ;
return 0 ;
}
static int F_99 ( struct V_233 * V_233 , int V_35 , T_22 V_177 ,
T_13 V_27 , T_13 V_228 )
{
T_21 V_259 ;
T_21 * V_206 ;
V_206 = F_86 ( V_233 -> V_4 , V_35 , & V_259 ) ;
if ( ! V_206 )
return - 1 ;
V_206 -> V_208 = V_209 ;
V_206 -> V_210 = V_212 | V_260 | V_211 ;
V_206 -> V_216 = V_177 ;
V_206 -> V_215 = V_27 ;
V_206 -> V_261 = 0 ;
V_206 -> V_214 = V_228 ;
V_206 -> V_213 = V_228 ;
V_206 -> V_262 = V_231 ;
if ( ! F_100 ( V_233 -> V_4 , V_35 , V_206 ) )
return - 1 ;
return 0 ;
}
static T_22 F_101 ( struct V_233 * V_233 )
{
return F_102 ( V_233 -> V_4 , V_241 ) ;
}
static int F_103 ( void * V_263 , const char * V_34 , char type ,
T_13 V_184 )
{
struct V_264 * V_265 = V_263 ;
if ( ! F_104 ( type , V_20 ) )
return 0 ;
if ( strchr ( V_34 , '[' ) ) {
if ( V_184 > V_265 -> V_266 )
V_265 -> V_266 = V_184 ;
return 0 ;
}
if ( ! V_265 -> V_267 || V_184 < V_265 -> V_267 )
V_265 -> V_267 = V_184 ;
if ( ! V_265 -> V_268 || V_184 > V_265 -> V_268 )
V_265 -> V_268 = V_184 ;
if ( ! strcmp ( V_34 , L_29 ) ) {
V_265 -> V_269 = V_184 ;
return 0 ;
}
if ( ! strcmp ( V_34 , L_30 ) ) {
V_265 -> V_270 = V_184 ;
return 0 ;
}
return 0 ;
}
static int F_105 ( struct V_264 * V_265 ,
const char * V_271 )
{
char V_272 [ V_180 ] ;
F_106 ( V_272 , V_180 , L_31 , V_271 ) ;
if ( F_107 ( V_272 , L_32 ) )
return - 1 ;
if ( F_108 ( V_272 , V_265 ,
F_103 ) < 0 )
return - 1 ;
return 0 ;
}
static int F_109 ( void * V_263 ,
const char * V_34 T_1 ,
T_13 V_184 )
{
struct V_264 * V_265 = V_263 ;
if ( ! V_265 -> V_273 || V_184 < V_265 -> V_273 )
V_265 -> V_273 = V_184 ;
return 0 ;
}
static int F_110 ( struct V_264 * V_265 ,
const char * V_271 )
{
char V_274 [ V_180 ] ;
F_106 ( V_274 , V_180 , L_33 , V_271 ) ;
if ( F_107 ( V_274 , L_34 ) )
return - 1 ;
if ( F_111 ( V_274 , V_265 ,
F_109 ) < 0 )
return - 1 ;
return 0 ;
}
static void F_112 ( struct V_275 * V_276 , T_13 V_184 , T_13 V_185 , T_13 V_186 ,
T_13 V_277 , T_13 V_278 )
{
if ( V_276 -> V_27 || V_277 < V_184 || V_277 >= V_185 )
return;
V_276 -> V_27 = V_277 ;
V_276 -> V_177 = ( V_277 - V_184 ) + V_186 ;
V_276 -> V_228 = V_278 < V_185 ? V_278 - V_277 : V_185 - V_277 ;
}
static int F_113 ( T_13 V_184 , T_13 V_228 , T_13 V_186 , void * V_79 )
{
struct V_264 * V_265 = V_79 ;
T_13 V_185 = V_184 + V_228 ;
F_112 ( & V_265 -> V_279 , V_184 , V_185 , V_186 , V_265 -> V_269 ,
V_265 -> V_270 ) ;
F_112 ( & V_265 -> V_280 , V_184 , V_185 , V_186 , V_265 -> V_273 ,
V_265 -> V_266 ) ;
return 0 ;
}
static int F_114 ( struct V_264 * V_265 , T_2 * V_4 )
{
if ( F_85 ( V_4 , true , F_113 , V_265 ) < 0 )
return - 1 ;
return 0 ;
}
static int F_115 ( struct V_264 * V_265 , const char * V_271 ,
T_2 * V_4 )
{
if ( F_105 ( V_265 , V_271 ) )
return - 1 ;
if ( F_110 ( V_265 , V_271 ) )
return - 1 ;
if ( V_265 -> V_269 )
V_265 -> V_269 = F_116 ( V_265 -> V_269 , V_231 ) ;
else
V_265 -> V_269 = F_116 ( V_265 -> V_267 , V_231 ) ;
if ( V_265 -> V_270 ) {
V_265 -> V_270 = F_117 ( V_265 -> V_270 , V_231 ) ;
} else if ( V_265 -> V_268 ) {
V_265 -> V_270 = F_117 ( V_265 -> V_268 , V_231 ) ;
V_265 -> V_270 += V_231 ;
}
V_265 -> V_273 = F_116 ( V_265 -> V_273 , V_231 ) ;
if ( V_265 -> V_266 ) {
V_265 -> V_266 = F_117 ( V_265 -> V_266 ,
V_231 ) ;
V_265 -> V_266 += V_231 ;
}
if ( ! V_265 -> V_269 || ! V_265 -> V_270 )
return - 1 ;
if ( V_265 -> V_273 && ! V_265 -> V_266 )
return - 1 ;
return F_114 ( V_265 , V_4 ) ;
}
static int F_118 ( const char * V_281 , const char * V_282 ,
const char * V_34 )
{
char V_283 [ V_180 ] ;
char V_284 [ V_180 ] ;
F_106 ( V_283 , V_180 , L_35 , V_281 , V_34 ) ;
F_106 ( V_284 , V_180 , L_35 , V_282 , V_34 ) ;
return F_119 ( V_283 , V_284 , 0400 ) ;
}
static int F_120 ( const char * V_271 , const char * V_34 )
{
char V_93 [ V_180 ] ;
F_106 ( V_93 , V_180 , L_35 , V_271 , V_34 ) ;
return F_52 ( V_93 ) ;
}
static int F_121 ( int V_224 , int V_226 )
{
char * V_285 ;
char * V_286 ;
V_100 V_287 ;
T_3 V_228 ;
int V_59 = - 1 ;
V_285 = malloc ( V_231 ) ;
V_286 = malloc ( V_231 ) ;
if ( ! V_285 || ! V_286 )
goto V_83;
while ( 1 ) {
V_287 = F_45 ( V_224 , V_285 , V_231 ) ;
if ( V_287 < 0 )
goto V_83;
if ( ! V_287 )
break;
V_228 = V_287 ;
if ( F_122 ( V_226 , V_286 , V_228 ) != ( int ) V_228 )
goto V_83;
if ( memcmp ( V_285 , V_286 , V_228 ) )
goto V_83;
}
V_59 = 0 ;
V_83:
free ( V_286 ) ;
free ( V_285 ) ;
return V_59 ;
}
static int F_123 ( const char * V_283 ,
const char * V_284 )
{
int V_224 , V_226 , V_59 = - 1 ;
V_224 = F_39 ( V_283 , V_95 ) ;
if ( V_224 < 0 )
return - 1 ;
V_226 = F_39 ( V_284 , V_95 ) ;
if ( V_226 < 0 )
goto V_288;
V_59 = F_121 ( V_224 , V_226 ) ;
F_43 ( V_226 ) ;
V_288:
F_43 ( V_224 ) ;
return V_59 ;
}
static int F_124 ( const char * V_281 , const char * V_282 ,
const char * V_34 )
{
char V_283 [ V_180 ] ;
char V_284 [ V_180 ] ;
F_106 ( V_283 , V_180 , L_35 , V_281 , V_34 ) ;
F_106 ( V_284 , V_180 , L_35 , V_282 , V_34 ) ;
return F_123 ( V_283 , V_284 ) ;
}
int F_125 ( const char * V_281 , const char * V_282 )
{
struct V_233 V_233 ;
struct V_233 V_289 ;
T_3 V_242 = 2 ;
int V_35 = 0 , V_59 = - 1 ;
T_22 V_177 = V_231 , V_92 , V_290 = 0 ;
struct V_264 V_265 = { . V_269 = 0 , } ;
char V_291 [ V_180 ] ;
char V_292 [ V_180 ] ;
if ( F_118 ( V_281 , V_282 , L_36 ) )
return - 1 ;
if ( F_118 ( V_281 , V_282 , L_37 ) )
goto V_293;
F_106 ( V_291 , V_180 , L_38 , V_281 ) ;
F_106 ( V_292 , V_180 , L_38 , V_282 ) ;
if ( F_92 ( & V_233 , V_291 ) )
goto V_294;
if ( F_115 ( & V_265 , V_281 , V_233 . V_4 ) )
goto V_295;
if ( F_93 ( & V_289 , V_292 , V_233 . V_235 , false ) )
goto V_295;
if ( ! V_265 . V_280 . V_27 )
V_242 -= 1 ;
if ( F_96 ( & V_233 , & V_289 , V_242 ) )
goto V_296;
if ( F_99 ( & V_289 , V_35 ++ , V_177 , V_265 . V_279 . V_27 ,
V_265 . V_279 . V_228 ) )
goto V_296;
if ( V_265 . V_280 . V_27 ) {
V_290 = V_177 + V_265 . V_279 . V_228 ;
if ( F_99 ( & V_289 , V_35 , V_290 ,
V_265 . V_280 . V_27 , V_265 . V_280 . V_228 ) )
goto V_296;
}
V_92 = F_101 ( & V_289 ) ;
if ( V_92 < 0 || V_92 > V_177 )
goto V_296;
if ( F_89 ( V_233 . V_94 , V_265 . V_279 . V_177 , V_289 . V_94 , V_177 ,
V_265 . V_279 . V_228 ) )
goto V_296;
if ( V_290 && F_89 ( V_233 . V_94 , V_265 . V_280 . V_177 ,
V_289 . V_94 , V_290 ,
V_265 . V_280 . V_228 ) )
goto V_296;
if ( F_124 ( V_281 , V_282 , L_37 ) )
goto V_296;
if ( F_124 ( V_281 , V_282 , L_36 ) )
goto V_296;
V_59 = 0 ;
V_296:
F_95 ( & V_289 ) ;
if ( V_59 )
F_52 ( V_292 ) ;
V_295:
F_95 ( & V_233 ) ;
V_294:
if ( V_59 )
F_120 ( V_282 , L_37 ) ;
V_293:
if ( V_59 )
F_120 ( V_282 , L_36 ) ;
return V_59 ;
}
int F_126 ( struct V_297 * V_298 )
{
struct V_233 V_233 ;
struct V_233 V_289 ;
T_3 V_242 = 1 ;
int V_35 = 0 , V_59 = - 1 ;
T_22 V_177 = V_231 , V_92 ;
if ( F_92 ( & V_233 , V_298 -> V_291 ) )
return - 1 ;
strcpy ( V_298 -> V_292 , V_299 ) ;
if ( F_93 ( & V_289 , V_298 -> V_292 , V_233 . V_235 , true ) )
goto V_295;
if ( F_96 ( & V_233 , & V_289 , V_242 ) )
goto V_296;
if ( F_99 ( & V_289 , V_35 , V_177 , V_298 -> V_27 , V_298 -> V_228 ) )
goto V_296;
V_92 = F_101 ( & V_289 ) ;
if ( V_92 < 0 || V_92 > V_177 )
goto V_296;
if ( F_89 ( V_233 . V_94 , V_298 -> V_300 , V_289 . V_94 , V_177 , V_298 -> V_228 ) )
goto V_296;
V_59 = 0 ;
V_296:
F_95 ( & V_289 ) ;
if ( V_59 )
F_52 ( V_298 -> V_292 ) ;
V_295:
F_95 ( & V_233 ) ;
return V_59 ;
}
void F_127 ( struct V_297 * V_298 )
{
F_52 ( V_298 -> V_292 ) ;
}
void F_128 ( void )
{
F_129 ( V_301 ) ;
}
