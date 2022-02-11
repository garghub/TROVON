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
int F_25 ( struct V_39 * V_39 , struct V_40 * V_41 , struct V_42 * V_42 ,
T_11 V_43 )
{
T_12 V_44 , V_36 ;
T_6 V_10 ;
T_13 V_45 ;
T_8 V_46 ;
struct V_47 * V_48 ;
T_8 V_49 , V_50 ;
T_7 * V_51 , * V_52 , * V_23 ;
T_10 * V_53 , * V_54 , * V_55 ;
T_3 V_56 ;
T_4 V_7 ;
char V_57 [ 1024 ] ;
T_2 * V_4 ;
int V_58 = 0 , V_59 , V_60 = 0 ;
if ( ! V_41 -> V_61 )
return 0 ;
V_4 = V_41 -> V_4 ;
V_7 = V_41 -> V_7 ;
V_55 = V_41 -> V_61 ;
V_50 = V_41 -> V_62 ;
V_56 = V_41 -> V_56 ;
if ( V_55 == NULL )
goto V_63;
V_53 = F_21 ( V_4 , & V_7 , & V_49 ,
L_4 , NULL ) ;
if ( V_53 == NULL ) {
V_53 = F_21 ( V_4 , & V_7 , & V_49 ,
L_5 , NULL ) ;
if ( V_53 == NULL )
goto V_63;
}
V_60 = - 1 ;
if ( V_49 . V_64 != V_56 )
goto V_63;
if ( F_21 ( V_4 , & V_7 , & V_46 , L_6 , NULL ) == NULL )
goto V_63;
V_51 = F_26 ( V_53 , NULL ) ;
if ( V_51 == NULL )
goto V_63;
V_52 = F_26 ( V_55 , NULL ) ;
if ( V_52 == NULL )
goto V_63;
V_54 = F_23 ( V_4 , V_50 . V_64 ) ;
if ( V_54 == NULL )
goto V_63;
V_23 = F_26 ( V_54 , NULL ) ;
if ( V_23 == NULL )
goto V_63;
if ( V_23 -> V_65 == 0 )
goto V_63;
V_44 = V_49 . V_32 / V_49 . V_66 ;
V_45 = V_46 . V_67 ;
if ( V_49 . V_68 == V_69 ) {
T_14 V_70 , * V_71 ;
F_27 (reldata, pos, pos_mem, idx,
nr_rel_entries) {
V_59 = F_28 ( V_71 -> V_72 ) ;
V_45 += V_46 . V_66 ;
F_29 ( V_52 , V_59 , & V_10 ) ;
snprintf ( V_57 , sizeof( V_57 ) ,
L_7 , F_13 ( & V_10 , V_23 ) ) ;
V_48 = F_30 ( V_45 , V_46 . V_66 ,
V_73 , V_57 ) ;
if ( ! V_48 )
goto V_63;
if ( V_43 && V_43 ( V_42 , V_48 ) )
F_31 ( V_48 ) ;
else {
F_32 ( & V_39 -> V_74 [ V_42 -> type ] , V_48 ) ;
++ V_58 ;
}
}
} else if ( V_49 . V_68 == V_75 ) {
T_15 V_70 , * V_71 ;
F_33 (reldata, pos, pos_mem, idx,
nr_rel_entries) {
V_59 = F_28 ( V_71 -> V_72 ) ;
V_45 += V_46 . V_66 ;
F_29 ( V_52 , V_59 , & V_10 ) ;
snprintf ( V_57 , sizeof( V_57 ) ,
L_7 , F_13 ( & V_10 , V_23 ) ) ;
V_48 = F_30 ( V_45 , V_46 . V_66 ,
V_73 , V_57 ) ;
if ( ! V_48 )
goto V_63;
if ( V_43 && V_43 ( V_42 , V_48 ) )
F_31 ( V_48 ) ;
else {
F_32 ( & V_39 -> V_74 [ V_42 -> type ] , V_48 ) ;
++ V_58 ;
}
}
}
V_60 = 0 ;
V_63:
if ( V_60 == 0 )
return V_58 ;
F_34 ( L_8 ,
V_9 , V_39 -> V_76 ) ;
return 0 ;
}
static int F_35 ( T_2 * V_4 , void * V_77 , T_3 V_78 )
{
int V_60 = - 1 ;
T_4 V_7 ;
T_8 V_25 ;
T_7 * V_79 ;
T_10 * V_29 ;
T_16 V_80 ;
void * V_81 ;
if ( V_78 < V_82 )
goto V_83;
V_80 = F_36 ( V_4 ) ;
if ( V_80 != V_84 )
goto V_83;
if ( F_4 ( V_4 , & V_7 ) == NULL ) {
F_6 ( L_9 , V_9 ) ;
goto V_83;
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
return V_60 ;
} while ( 0 );
V_79 = F_26 ( V_29 , NULL ) ;
if ( V_79 == NULL )
goto V_83;
V_81 = V_79 -> V_24 ;
while ( V_81 < ( V_79 -> V_24 + V_79 -> V_65 ) ) {
T_17 * V_85 = V_81 ;
T_3 V_86 = F_37 ( V_85 -> V_87 ) ,
V_88 = F_37 ( V_85 -> V_89 ) ;
const char * V_35 ;
V_81 += sizeof( * V_85 ) ;
V_35 = V_81 ;
V_81 += V_86 ;
if ( V_85 -> V_90 == V_91 &&
V_85 -> V_87 == sizeof( L_13 ) ) {
if ( memcmp ( V_35 , L_13 , sizeof( L_13 ) ) == 0 ) {
T_3 V_92 = F_38 ( V_78 , V_88 ) ;
memcpy ( V_77 , V_81 , V_92 ) ;
memset ( V_77 + V_92 , 0 , V_78 - V_92 ) ;
V_60 = V_88 ;
break;
}
}
V_81 += V_88 ;
}
V_83:
return V_60 ;
}
int F_39 ( const char * V_93 , void * V_77 , T_3 V_78 )
{
int V_94 , V_60 = - 1 ;
T_2 * V_4 ;
if ( V_78 < V_82 )
goto V_83;
V_94 = F_40 ( V_93 , V_95 ) ;
if ( V_94 < 0 )
goto V_83;
V_4 = F_41 ( V_94 , V_96 , NULL ) ;
if ( V_4 == NULL ) {
F_42 ( L_14 , V_9 , V_93 ) ;
goto V_97;
}
V_60 = F_35 ( V_4 , V_77 , V_78 ) ;
F_43 ( V_4 ) ;
V_97:
F_44 ( V_94 ) ;
V_83:
return V_60 ;
}
int F_45 ( const char * V_93 , void * V_98 , T_3 V_78 )
{
int V_94 , V_60 = - 1 ;
if ( V_78 < V_82 )
goto V_83;
V_94 = F_40 ( V_93 , V_95 ) ;
if ( V_94 < 0 )
goto V_83;
while ( 1 ) {
char V_77 [ V_99 ] ;
T_17 V_85 ;
T_3 V_86 , V_88 ;
if ( F_46 ( V_94 , & V_85 , sizeof( V_85 ) ) != sizeof( V_85 ) )
break;
V_86 = F_37 ( V_85 . V_87 ) ;
V_88 = F_37 ( V_85 . V_89 ) ;
if ( V_85 . V_90 == V_91 &&
V_85 . V_87 == sizeof( L_13 ) ) {
if ( F_46 ( V_94 , V_77 , V_86 ) != ( V_100 ) V_86 )
break;
if ( memcmp ( V_77 , L_13 , sizeof( L_13 ) ) == 0 ) {
T_3 V_92 = F_38 ( V_88 , V_78 ) ;
if ( F_46 ( V_94 , V_98 , V_92 ) == ( V_100 ) V_92 ) {
memset ( V_98 + V_92 , 0 , V_78 - V_92 ) ;
V_60 = 0 ;
break;
}
} else if ( F_46 ( V_94 , V_77 , V_88 ) != ( V_100 ) V_88 )
break;
} else {
int V_101 = V_86 + V_88 ;
if ( F_46 ( V_94 , V_77 , V_101 ) != V_101 )
break;
}
}
F_44 ( V_94 ) ;
V_83:
return V_60 ;
}
int F_47 ( const char * V_93 , char * V_102 ,
T_3 V_78 )
{
int V_94 , V_60 = - 1 ;
T_2 * V_4 ;
T_4 V_7 ;
T_8 V_25 ;
T_7 * V_79 ;
T_10 * V_29 ;
T_16 V_80 ;
V_94 = F_40 ( V_93 , V_95 ) ;
if ( V_94 < 0 )
goto V_83;
V_4 = F_41 ( V_94 , V_96 , NULL ) ;
if ( V_4 == NULL ) {
F_42 ( L_14 , V_9 , V_93 ) ;
goto V_97;
}
V_80 = F_36 ( V_4 ) ;
if ( V_80 != V_84 )
goto V_63;
if ( F_4 ( V_4 , & V_7 ) == NULL ) {
F_6 ( L_9 , V_9 ) ;
goto V_63;
}
V_29 = F_21 ( V_4 , & V_7 , & V_25 ,
L_15 , NULL ) ;
if ( V_29 == NULL )
goto V_63;
V_79 = F_26 ( V_29 , NULL ) ;
if ( V_79 == NULL )
goto V_63;
strncpy ( V_102 , V_79 -> V_24 , V_78 ) ;
V_60 = 0 ;
V_63:
F_43 ( V_4 ) ;
V_97:
F_44 ( V_94 ) ;
V_83:
return V_60 ;
}
static int F_48 ( struct V_39 * V_39 , unsigned char V_103 )
{
static unsigned int const V_104 = 1 ;
V_39 -> V_105 = V_106 ;
switch ( V_103 ) {
case V_107 :
if ( * ( unsigned char const * ) & V_104 != 1 )
V_39 -> V_105 = V_108 ;
break;
case V_109 :
if ( * ( unsigned char const * ) & V_104 != 0 )
V_39 -> V_105 = V_108 ;
break;
default:
F_6 ( L_16 , V_103 ) ;
return - V_110 ;
}
return 0 ;
}
static int F_49 ( struct V_39 * V_39 , const char * V_35 ,
enum V_111 type )
{
int V_94 = - 1 ;
char V_112 [] = L_17 ;
struct V_113 V_114 ;
if ( type != V_115 &&
type != V_116 &&
type != V_117 )
return - 1 ;
if ( type == V_117 )
V_35 = V_39 -> V_76 ;
if ( F_50 ( & V_114 , V_35 ) || ! V_114 . V_118 )
return - 1 ;
V_94 = F_51 ( V_112 ) ;
if ( V_94 < 0 ) {
V_39 -> V_119 = V_120 ;
goto V_83;
}
if ( ! F_52 ( V_114 . V_121 , V_35 , V_94 ) ) {
V_39 -> V_119 = V_122 ;
F_44 ( V_94 ) ;
V_94 = - 1 ;
}
F_53 ( V_112 ) ;
V_83:
free ( V_114 . V_121 ) ;
return V_94 ;
}
bool F_54 ( struct V_40 * V_41 )
{
return V_41 -> V_61 || V_41 -> V_123 ;
}
bool F_55 ( struct V_40 * V_41 )
{
return V_41 -> V_124 != NULL ;
}
void F_56 ( struct V_40 * V_41 )
{
F_57 ( & V_41 -> V_35 ) ;
F_43 ( V_41 -> V_4 ) ;
F_44 ( V_41 -> V_94 ) ;
}
bool __weak F_58 ( T_4 V_7 )
{
return V_7 . V_125 == V_126 || V_7 . V_125 == V_127 ;
}
int F_59 ( struct V_40 * V_41 , struct V_39 * V_39 , const char * V_35 ,
enum V_111 type )
{
int V_60 = - 1 ;
T_4 V_7 ;
T_2 * V_4 ;
int V_94 ;
if ( F_60 ( V_39 ) ) {
V_94 = F_49 ( V_39 , V_35 , type ) ;
if ( V_94 < 0 )
return - 1 ;
} else {
V_94 = F_40 ( V_35 , V_95 ) ;
if ( V_94 < 0 ) {
V_39 -> V_119 = V_120 ;
return - 1 ;
}
}
V_4 = F_41 ( V_94 , V_96 , NULL ) ;
if ( V_4 == NULL ) {
F_34 ( L_14 , V_9 , V_35 ) ;
V_39 -> V_119 = V_128 ;
goto V_97;
}
if ( F_4 ( V_4 , & V_7 ) == NULL ) {
V_39 -> V_119 = V_128 ;
F_34 ( L_9 , V_9 ) ;
goto V_63;
}
if ( F_48 ( V_39 , V_7 . V_129 [ V_130 ] ) ) {
V_39 -> V_119 = V_131 ;
goto V_63;
}
if ( V_39 -> V_132 ) {
T_18 V_98 [ V_82 ] ;
if ( F_35 ( V_4 , V_98 , V_82 ) < 0 ) {
V_39 -> V_119 = V_133 ;
goto V_63;
}
if ( ! F_61 ( V_39 , V_98 ) ) {
F_34 ( L_18 , V_9 , V_35 ) ;
V_39 -> V_119 = V_134 ;
goto V_63;
}
}
V_41 -> V_135 = ( F_62 ( V_4 ) == V_136 ) ;
V_41 -> V_124 = F_21 ( V_4 , & V_7 , & V_41 -> V_137 , L_19 ,
NULL ) ;
if ( V_41 -> V_137 . V_68 != V_138 )
V_41 -> V_124 = NULL ;
V_41 -> V_56 = 0 ;
V_41 -> V_61 = F_21 ( V_4 , & V_7 , & V_41 -> V_62 , L_20 ,
& V_41 -> V_56 ) ;
if ( V_41 -> V_62 . V_68 != V_139 )
V_41 -> V_61 = NULL ;
V_41 -> V_140 = 0 ;
V_41 -> V_123 = F_21 ( V_4 , & V_7 , & V_41 -> V_141 , L_21 ,
& V_41 -> V_140 ) ;
if ( V_41 -> V_141 . V_68 != V_142 )
V_41 -> V_123 = NULL ;
if ( V_39 -> V_143 == V_144 )
V_41 -> V_145 = true ;
else
V_41 -> V_145 = F_58 ( V_7 ) ;
V_41 -> V_35 = F_63 ( V_35 ) ;
if ( ! V_41 -> V_35 ) {
V_39 -> V_119 = V_120 ;
goto V_63;
}
V_41 -> V_4 = V_4 ;
V_41 -> V_94 = V_94 ;
V_41 -> V_7 = V_7 ;
V_41 -> type = type ;
return 0 ;
V_63:
F_43 ( V_4 ) ;
V_97:
F_44 ( V_94 ) ;
return V_60 ;
}
static bool F_64 ( struct V_146 * V_146 )
{
return V_146 && V_146 -> V_147 && V_146 -> V_147 -> V_35 &&
! V_146 -> V_147 -> V_148 ;
}
static T_13 F_65 ( struct V_146 * V_146 )
{
if ( V_146 && V_146 -> V_147 &&
V_146 -> V_147 -> V_148 )
return V_146 -> V_147 -> V_28 -
V_146 -> V_147 -> V_148 ;
return 0 ;
}
static bool F_66 ( bool V_149 )
{
return V_149 ? V_150 . V_151 : V_150 . V_152 ;
}
void __weak F_67 ( struct V_47 * T_19 T_1 ,
T_6 * V_10 T_1 ) { }
int F_68 ( struct V_39 * V_39 , struct V_42 * V_42 ,
struct V_40 * V_153 , struct V_40 * V_154 ,
T_11 V_43 , int V_155 )
{
struct V_146 * V_146 = V_39 -> V_143 ? F_69 ( V_42 ) : NULL ;
struct V_156 * V_157 = V_146 ? F_70 ( V_42 ) : NULL ;
struct V_42 * V_158 = V_42 ;
struct V_39 * V_159 = V_39 ;
T_7 * V_23 , * V_26 ;
T_12 V_160 ;
int V_60 = - 1 ;
T_12 V_36 ;
T_4 V_7 ;
T_8 V_25 ;
T_8 V_161 ;
T_7 * V_52 , * V_162 = NULL ;
T_6 V_10 ;
T_10 * V_29 , * V_163 ;
T_2 * V_4 ;
int V_58 = 0 ;
bool V_164 = false , V_165 = false ;
if ( V_146 && ! V_157 )
return - 1 ;
V_39 -> V_166 = V_153 -> type ;
V_39 -> V_135 = V_153 -> V_135 ;
V_39 -> V_167 = V_153 -> V_7 . V_125 == V_127 ;
if ( V_155 && V_153 -> V_124 )
F_71 ( & V_39 -> V_74 [ V_42 -> type ] ) ;
if ( ! V_153 -> V_124 ) {
if ( V_39 -> V_143 )
goto V_63;
V_153 -> V_124 = V_153 -> V_61 ;
V_153 -> V_137 = V_153 -> V_62 ;
}
V_4 = V_153 -> V_4 ;
V_7 = V_153 -> V_7 ;
V_29 = V_153 -> V_124 ;
V_25 = V_153 -> V_137 ;
if ( F_21 ( V_154 -> V_4 , & V_154 -> V_7 , & V_161 ,
L_22 , NULL ) )
V_39 -> V_168 = V_161 . V_31 - V_161 . V_67 ;
if ( V_154 -> V_123 )
V_162 = F_22 ( V_154 -> V_123 , NULL ) ;
V_52 = F_26 ( V_29 , NULL ) ;
if ( V_52 == NULL )
goto V_63;
V_29 = F_23 ( V_4 , V_25 . V_64 ) ;
if ( V_29 == NULL )
goto V_63;
V_23 = F_26 ( V_29 , NULL ) ;
if ( V_23 == NULL )
goto V_63;
V_163 = F_23 ( V_154 -> V_4 , V_154 -> V_7 . V_37 ) ;
if ( V_163 == NULL )
goto V_63;
V_26 = F_26 ( V_163 , NULL ) ;
if ( V_26 == NULL )
goto V_63;
V_160 = V_25 . V_32 / V_25 . V_66 ;
memset ( & V_10 , 0 , sizeof( V_10 ) ) ;
if ( F_64 ( V_146 ) ) {
F_72 (syms, nr_syms, idx, sym) {
const char * V_169 = F_13 ( & V_10 , V_23 ) ;
if ( strcmp ( V_169 , V_146 -> V_147 -> V_35 ) )
continue;
V_146 -> V_147 -> V_148 = V_10 . V_170 ;
V_42 -> V_171 = V_146 -> V_147 -> V_28 -
V_146 -> V_147 -> V_148 ;
break;
}
}
if ( F_73 ( V_39 ) )
V_42 -> V_171 = V_42 -> V_172 - V_39 -> V_168 ;
V_39 -> V_145 = V_154 -> V_145 || F_65 ( V_146 ) ;
if ( V_42 -> type == V_21 && ( V_39 -> V_143 || V_155 ) ) {
V_164 = true ;
V_165 = V_39 -> V_145 ;
}
F_72 (syms, nr_syms, idx, sym) {
struct V_47 * V_48 ;
const char * V_169 = F_13 ( & V_10 , V_23 ) ;
char * V_173 = NULL ;
int V_174 = F_11 ( & V_10 ) ;
const char * V_175 ;
bool V_176 = false ;
if ( ! V_174 && ! F_12 ( & V_10 , V_42 -> type ) )
continue;
if ( V_7 . V_177 == V_178 || V_7 . V_177 == V_179 ) {
if ( V_169 [ 0 ] == '$' && strchr ( L_23 , V_169 [ 1 ] )
&& ( V_169 [ 2 ] == '\0' || V_169 [ 2 ] == '.' ) )
continue;
}
if ( V_154 -> V_123 && V_10 . V_15 == V_154 -> V_140 ) {
T_20 V_180 = V_10 . V_170 - V_153 -> V_141 . V_31 ;
T_13 * V_181 = V_162 -> V_24 + V_180 ;
V_10 . V_170 = F_74 ( V_39 , T_13 , * V_181 ) ;
V_10 . V_15 = F_18 ( V_154 -> V_4 ,
V_10 . V_170 ) ;
V_176 = true ;
}
if ( V_10 . V_15 == V_19 )
continue;
V_29 = F_23 ( V_154 -> V_4 , V_10 . V_15 ) ;
if ( ! V_29 )
goto V_63;
F_20 ( V_29 , & V_25 ) ;
if ( V_174 && ! F_17 ( & V_25 , V_26 , V_42 -> type ) )
continue;
V_175 = F_14 ( & V_25 , V_26 ) ;
if ( ( V_7 . V_177 == V_178 ) &&
( V_42 -> type == V_21 ) &&
( V_10 . V_170 & 1 ) )
-- V_10 . V_170 ;
if ( V_39 -> V_143 || V_155 ) {
char V_182 [ V_183 ] ;
if ( V_165 )
V_10 . V_170 -= V_25 . V_31 - V_25 . V_67 ;
if ( strcmp ( V_175 ,
( V_159 -> V_184 +
V_39 -> V_185 ) ) == 0 )
goto V_186;
if ( strcmp ( V_175 , L_22 ) == 0 ) {
if ( V_164 && V_39 -> V_143 ) {
V_164 = false ;
V_42 -> V_172 = V_25 . V_31 +
F_65 ( V_146 ) ;
V_42 -> V_187 = V_42 -> V_172 + V_25 . V_32 ;
V_42 -> V_188 = V_25 . V_67 ;
V_42 -> V_189 = V_190 ;
V_42 -> V_191 = V_192 ;
if ( V_157 ) {
F_75 ( V_42 ) ;
F_76 ( V_157 , V_42 ) ;
F_77 ( V_157 , V_42 ) ;
F_78 ( V_42 ) ;
}
}
if ( V_164 && V_155 ) {
V_164 = false ;
V_42 -> V_188 = V_25 . V_67 ;
}
V_158 = V_42 ;
V_159 = V_39 ;
goto V_186;
}
if ( ! V_146 )
goto V_186;
snprintf ( V_182 , sizeof( V_182 ) ,
L_24 , V_39 -> V_184 , V_175 ) ;
V_158 = F_79 ( V_157 , V_42 -> type , V_182 ) ;
if ( V_158 == NULL ) {
T_13 V_172 = V_10 . V_170 ;
if ( V_155 )
V_172 += V_42 -> V_172 + V_25 . V_67 ;
V_159 = F_80 ( V_182 ) ;
if ( V_159 == NULL )
goto V_63;
V_159 -> V_143 = V_39 -> V_143 ;
V_159 -> V_76 = V_39 -> V_76 ;
V_159 -> V_193 = V_39 -> V_193 ;
V_158 = F_81 ( V_172 , V_159 ,
V_42 -> type ) ;
F_82 ( V_159 ) ;
if ( V_158 == NULL ) {
goto V_63;
}
if ( V_165 ) {
V_158 -> V_172 = V_25 . V_31 +
F_65 ( V_146 ) ;
V_158 -> V_187 = V_158 -> V_172 +
V_25 . V_32 ;
V_158 -> V_188 = V_25 . V_67 ;
} else {
V_158 -> V_189 = V_194 ;
V_158 -> V_191 = V_194 ;
}
V_159 -> V_166 = V_39 -> V_166 ;
F_77 ( V_157 , V_158 ) ;
F_83 ( & V_42 -> V_195 -> V_196 -> V_197 , V_159 ) ;
F_78 ( V_158 ) ;
F_84 ( V_159 , V_42 -> type ) ;
} else
V_159 = V_158 -> V_39 ;
goto V_186;
}
if ( ( V_176 && V_154 -> V_145 )
|| ( ! V_176 && V_153 -> V_145 ) ) {
F_85 ( L_25 V_198 L_26
L_27 V_198 L_28 V_198 L_29 , V_9 ,
( T_13 ) V_10 . V_170 , ( T_13 ) V_25 . V_31 ,
( T_13 ) V_25 . V_67 ) ;
V_10 . V_170 -= V_25 . V_31 - V_25 . V_67 ;
}
V_186:
if ( F_66 ( V_39 -> V_143 || V_155 ) ) {
int V_199 = V_200 ;
if ( V_201 )
V_199 = V_202 | V_203 ;
V_173 = F_1 ( NULL , V_169 , V_199 ) ;
if ( V_173 == NULL )
V_173 = F_86 ( V_169 , V_204 ) ;
else if ( F_87 ( V_173 ) )
F_88 ( V_173 ) ;
if ( V_173 != NULL )
V_169 = V_173 ;
}
V_48 = F_30 ( V_10 . V_170 , V_10 . V_205 ,
F_89 ( V_10 . V_11 ) , V_169 ) ;
free ( V_173 ) ;
if ( ! V_48 )
goto V_63;
F_67 ( V_48 , & V_10 ) ;
if ( V_43 && V_43 ( V_158 , V_48 ) )
F_31 ( V_48 ) ;
else {
F_32 ( & V_159 -> V_74 [ V_158 -> type ] , V_48 ) ;
V_58 ++ ;
}
}
if ( V_58 > 0 ) {
if ( ! V_150 . V_206 )
F_90 ( & V_39 -> V_74 [ V_42 -> type ] ) ;
F_91 ( & V_39 -> V_74 [ V_42 -> type ] ) ;
if ( V_146 ) {
F_92 ( V_157 , V_42 -> type ) ;
}
}
V_60 = V_58 ;
V_63:
return V_60 ;
}
static int F_93 ( T_2 * V_4 , bool V_207 , T_21 V_208 , void * V_79 )
{
T_22 V_209 ;
T_3 V_3 , V_210 ;
int V_60 ;
T_13 V_92 ;
if ( F_3 ( V_4 , & V_210 ) )
return - 1 ;
for ( V_3 = 0 ; V_3 < V_210 ; V_3 ++ ) {
if ( F_94 ( V_4 , V_3 , & V_209 ) == NULL )
return - 1 ;
if ( V_209 . V_211 != V_212 )
continue;
if ( V_207 ) {
if ( ! ( V_209 . V_213 & V_214 ) )
continue;
} else {
if ( ! ( V_209 . V_213 & V_215 ) )
continue;
}
V_92 = F_38 ( V_209 . V_216 , V_209 . V_217 ) ;
if ( ! V_92 )
continue;
V_60 = V_208 ( V_209 . V_218 , V_92 , V_209 . V_219 , V_79 ) ;
if ( V_60 )
return V_60 ;
}
return 0 ;
}
int F_95 ( int V_94 , bool V_207 , T_21 V_208 , void * V_79 ,
bool * V_135 )
{
int V_60 ;
T_2 * V_4 ;
V_4 = F_41 ( V_94 , V_96 , NULL ) ;
if ( V_4 == NULL )
return - 1 ;
if ( V_135 )
* V_135 = ( F_62 ( V_4 ) == V_136 ) ;
V_60 = F_93 ( V_4 , V_207 , V_208 , V_79 ) ;
F_43 ( V_4 ) ;
return V_60 ;
}
enum V_220 F_96 ( int V_94 )
{
enum V_220 V_220 = V_221 ;
T_4 V_7 ;
T_16 V_80 ;
T_2 * V_4 ;
V_4 = F_41 ( V_94 , V_96 , NULL ) ;
if ( V_4 == NULL )
goto V_83;
V_80 = F_36 ( V_4 ) ;
if ( V_80 != V_84 )
goto V_222;
if ( F_62 ( V_4 ) == V_136 ) {
V_220 = V_223 ;
goto V_222;
}
if ( F_4 ( V_4 , & V_7 ) == NULL )
goto V_222;
if ( V_7 . V_177 == V_224 )
V_220 = V_225 ;
else
V_220 = V_226 ;
V_222:
F_43 ( V_4 ) ;
V_83:
return V_220 ;
}
static int F_97 ( int V_227 , T_23 V_228 , int V_229 , T_23 V_230 , T_13 V_231 )
{
V_100 V_232 ;
T_3 V_101 ;
int V_60 = - 1 ;
char * V_233 = malloc ( V_234 ) ;
if ( V_233 == NULL )
return - 1 ;
if ( F_98 ( V_229 , V_230 , V_235 ) != V_230 )
goto V_83;
if ( F_98 ( V_227 , V_228 , V_235 ) != V_228 )
goto V_83;
while ( V_231 ) {
V_101 = V_234 ;
if ( V_231 < V_101 )
V_101 = V_231 ;
V_232 = F_46 ( V_227 , V_233 , V_101 ) ;
if ( V_232 < 0 )
goto V_83;
if ( ! V_232 )
break;
V_101 = V_232 ;
V_232 = F_99 ( V_229 , V_233 , V_101 ) ;
if ( V_232 < 0 )
goto V_83;
if ( ( T_3 ) V_232 != V_101 )
goto V_83;
V_231 -= V_101 ;
}
V_60 = 0 ;
V_83:
free ( V_233 ) ;
return V_60 ;
}
static int F_100 ( struct V_236 * V_236 , const char * V_93 )
{
T_4 * V_7 ;
V_236 -> V_94 = F_40 ( V_93 , V_95 ) ;
if ( V_236 -> V_94 == - 1 )
return - 1 ;
V_236 -> V_4 = F_41 ( V_236 -> V_94 , V_237 , NULL ) ;
if ( ! V_236 -> V_4 )
goto V_97;
V_236 -> V_238 = F_62 ( V_236 -> V_4 ) ;
if ( V_236 -> V_238 == V_239 )
goto V_222;
V_7 = F_4 ( V_236 -> V_4 , & V_236 -> V_7 ) ;
if ( ! V_7 )
goto V_222;
return 0 ;
V_222:
F_43 ( V_236 -> V_4 ) ;
V_97:
F_44 ( V_236 -> V_94 ) ;
return - 1 ;
}
static int F_101 ( struct V_236 * V_236 , char * V_93 , int V_238 ,
bool V_240 )
{
V_236 -> V_238 = V_238 ;
if ( V_240 )
V_236 -> V_94 = F_51 ( V_93 ) ;
else
V_236 -> V_94 = F_40 ( V_93 , V_241 | V_242 | V_243 , 0400 ) ;
if ( V_236 -> V_94 == - 1 )
return - 1 ;
V_236 -> V_4 = F_41 ( V_236 -> V_94 , V_244 , NULL ) ;
if ( ! V_236 -> V_4 )
goto V_97;
if ( ! F_102 ( V_236 -> V_4 , V_238 ) )
goto V_222;
memset ( & V_236 -> V_7 , 0 , sizeof( T_4 ) ) ;
return 0 ;
V_222:
F_43 ( V_236 -> V_4 ) ;
V_97:
F_44 ( V_236 -> V_94 ) ;
F_53 ( V_93 ) ;
return - 1 ;
}
static void F_103 ( struct V_236 * V_236 )
{
F_43 ( V_236 -> V_4 ) ;
F_44 ( V_236 -> V_94 ) ;
}
static int F_104 ( struct V_236 * V_227 , struct V_236 * V_229 , T_3 V_245 )
{
T_4 * V_7 = & V_229 -> V_7 ;
T_4 * V_246 = & V_227 -> V_7 ;
memcpy ( V_7 -> V_129 , V_246 -> V_129 , V_247 ) ;
V_7 -> V_125 = V_246 -> V_125 ;
V_7 -> V_177 = V_246 -> V_177 ;
V_7 -> V_248 = V_246 -> V_248 ;
V_7 -> V_249 = 0 ;
V_7 -> V_250 = 0 ;
V_7 -> V_251 = V_246 -> V_251 ;
V_7 -> V_8 = V_245 ;
V_7 -> V_252 = 0 ;
V_7 -> V_253 = 0 ;
V_7 -> V_37 = 0 ;
if ( V_227 -> V_238 == V_254 ) {
V_7 -> V_255 = sizeof( V_256 ) ;
V_7 -> V_257 = sizeof( V_256 ) ;
V_7 -> V_258 = sizeof( V_259 ) ;
} else {
V_7 -> V_255 = sizeof( V_260 ) ;
V_7 -> V_257 = sizeof( V_260 ) ;
V_7 -> V_258 = sizeof( V_261 ) ;
}
if ( ! F_105 ( V_229 -> V_4 , V_7 ) )
return - 1 ;
if ( ! F_106 ( V_229 -> V_4 , V_245 ) )
return - 1 ;
return 0 ;
}
static int F_107 ( struct V_236 * V_236 , int V_36 , T_23 V_180 ,
T_13 V_28 , T_13 V_231 )
{
T_22 V_209 = {
. V_211 = V_212 ,
. V_213 = V_215 | V_262 | V_214 ,
. V_219 = V_180 ,
. V_218 = V_28 ,
. V_263 = 0 ,
. V_217 = V_231 ,
. V_216 = V_231 ,
. V_264 = V_234 ,
} ;
if ( ! F_108 ( V_236 -> V_4 , V_36 , & V_209 ) )
return - 1 ;
return 0 ;
}
static T_23 F_109 ( struct V_236 * V_236 )
{
return F_110 ( V_236 -> V_4 , V_244 ) ;
}
static int F_111 ( void * V_265 , const char * V_35 , char type ,
T_13 V_172 )
{
struct V_266 * V_267 = V_265 ;
if ( ! F_112 ( type , V_21 ) )
return 0 ;
if ( strchr ( V_35 , '[' ) ) {
if ( V_172 > V_267 -> V_268 )
V_267 -> V_268 = V_172 ;
return 0 ;
}
if ( ! V_267 -> V_269 || V_172 < V_267 -> V_269 )
V_267 -> V_269 = V_172 ;
if ( ! V_267 -> V_270 || V_172 > V_267 -> V_270 )
V_267 -> V_270 = V_172 ;
if ( ! strcmp ( V_35 , L_30 ) ) {
V_267 -> V_271 = V_172 ;
return 0 ;
}
if ( ! strcmp ( V_35 , L_31 ) ) {
V_267 -> V_272 = V_172 ;
return 0 ;
}
return 0 ;
}
static int F_113 ( struct V_266 * V_267 ,
const char * V_273 )
{
char V_274 [ V_183 ] ;
F_114 ( V_274 , V_183 , L_32 , V_273 ) ;
if ( F_115 ( V_274 , L_33 ) )
return - 1 ;
if ( F_116 ( V_274 , V_267 ,
F_111 ) < 0 )
return - 1 ;
return 0 ;
}
static int F_117 ( void * V_265 ,
const char * V_35 T_1 ,
T_13 V_172 )
{
struct V_266 * V_267 = V_265 ;
if ( ! V_267 -> V_275 || V_172 < V_267 -> V_275 )
V_267 -> V_275 = V_172 ;
return 0 ;
}
static int F_118 ( struct V_266 * V_267 ,
const char * V_273 )
{
char V_276 [ V_183 ] ;
F_114 ( V_276 , V_183 , L_34 , V_273 ) ;
if ( F_115 ( V_276 , L_35 ) )
return - 1 ;
if ( F_119 ( V_276 , V_267 ,
F_117 ) < 0 )
return - 1 ;
return 0 ;
}
static void F_120 ( struct V_277 * V_278 , T_13 V_172 , T_13 V_187 , T_13 V_188 ,
T_13 T_19 , T_13 V_279 )
{
if ( V_278 -> V_28 || T_19 < V_172 || T_19 >= V_187 )
return;
V_278 -> V_28 = T_19 ;
V_278 -> V_180 = ( T_19 - V_172 ) + V_188 ;
V_278 -> V_231 = V_279 < V_187 ? V_279 - T_19 : V_187 - T_19 ;
}
static int F_121 ( T_13 V_172 , T_13 V_231 , T_13 V_188 , void * V_79 )
{
struct V_266 * V_267 = V_79 ;
T_13 V_187 = V_172 + V_231 ;
F_120 ( & V_267 -> V_280 , V_172 , V_187 , V_188 , V_267 -> V_271 ,
V_267 -> V_272 ) ;
F_120 ( & V_267 -> V_281 , V_172 , V_187 , V_188 , V_267 -> V_275 ,
V_267 -> V_268 ) ;
return 0 ;
}
static int F_122 ( struct V_266 * V_267 , T_2 * V_4 )
{
if ( F_93 ( V_4 , true , F_121 , V_267 ) < 0 )
return - 1 ;
return 0 ;
}
static int F_123 ( struct V_266 * V_267 , const char * V_273 ,
T_2 * V_4 )
{
if ( F_113 ( V_267 , V_273 ) )
return - 1 ;
if ( F_118 ( V_267 , V_273 ) )
return - 1 ;
if ( V_267 -> V_271 )
V_267 -> V_271 = F_124 ( V_267 -> V_271 , V_234 ) ;
else
V_267 -> V_271 = F_124 ( V_267 -> V_269 , V_234 ) ;
if ( V_267 -> V_272 ) {
V_267 -> V_272 = F_125 ( V_267 -> V_272 , V_234 ) ;
} else if ( V_267 -> V_270 ) {
V_267 -> V_272 = F_125 ( V_267 -> V_270 , V_234 ) ;
V_267 -> V_272 += V_234 ;
}
V_267 -> V_275 = F_124 ( V_267 -> V_275 , V_234 ) ;
if ( V_267 -> V_268 ) {
V_267 -> V_268 = F_125 ( V_267 -> V_268 ,
V_234 ) ;
V_267 -> V_268 += V_234 ;
}
if ( ! V_267 -> V_271 || ! V_267 -> V_272 )
return - 1 ;
if ( V_267 -> V_275 && ! V_267 -> V_268 )
return - 1 ;
return F_122 ( V_267 , V_4 ) ;
}
static int F_126 ( const char * V_282 , const char * V_283 ,
const char * V_35 )
{
char V_284 [ V_183 ] ;
char V_285 [ V_183 ] ;
F_114 ( V_284 , V_183 , L_36 , V_282 , V_35 ) ;
F_114 ( V_285 , V_183 , L_36 , V_283 , V_35 ) ;
return F_127 ( V_284 , V_285 , 0400 ) ;
}
static int F_128 ( const char * V_273 , const char * V_35 )
{
char V_93 [ V_183 ] ;
F_114 ( V_93 , V_183 , L_36 , V_273 , V_35 ) ;
return F_53 ( V_93 ) ;
}
static int F_129 ( int V_227 , int V_229 )
{
char * V_286 ;
char * V_287 ;
V_100 V_288 ;
T_3 V_231 ;
int V_60 = - 1 ;
V_286 = malloc ( V_234 ) ;
V_287 = malloc ( V_234 ) ;
if ( ! V_286 || ! V_287 )
goto V_83;
while ( 1 ) {
V_288 = F_46 ( V_227 , V_286 , V_234 ) ;
if ( V_288 < 0 )
goto V_83;
if ( ! V_288 )
break;
V_231 = V_288 ;
if ( F_130 ( V_229 , V_287 , V_231 ) != ( int ) V_231 )
goto V_83;
if ( memcmp ( V_286 , V_287 , V_231 ) )
goto V_83;
}
V_60 = 0 ;
V_83:
free ( V_287 ) ;
free ( V_286 ) ;
return V_60 ;
}
static int F_131 ( const char * V_284 ,
const char * V_285 )
{
int V_227 , V_229 , V_60 = - 1 ;
V_227 = F_40 ( V_284 , V_95 ) ;
if ( V_227 < 0 )
return - 1 ;
V_229 = F_40 ( V_285 , V_95 ) ;
if ( V_229 < 0 )
goto V_289;
V_60 = F_129 ( V_227 , V_229 ) ;
F_44 ( V_229 ) ;
V_289:
F_44 ( V_227 ) ;
return V_60 ;
}
static int F_132 ( const char * V_282 , const char * V_283 ,
const char * V_35 )
{
char V_284 [ V_183 ] ;
char V_285 [ V_183 ] ;
F_114 ( V_284 , V_183 , L_36 , V_282 , V_35 ) ;
F_114 ( V_285 , V_183 , L_36 , V_283 , V_35 ) ;
return F_131 ( V_284 , V_285 ) ;
}
int F_133 ( const char * V_282 , const char * V_283 )
{
struct V_236 V_236 ;
struct V_236 V_290 ;
T_3 V_245 = 2 ;
int V_36 = 0 , V_60 = - 1 ;
T_23 V_180 = V_234 , V_92 , V_291 = 0 ;
struct V_266 V_267 = { . V_271 = 0 , } ;
char V_292 [ V_183 ] ;
char V_293 [ V_183 ] ;
if ( F_126 ( V_282 , V_283 , L_37 ) )
return - 1 ;
if ( F_126 ( V_282 , V_283 , L_38 ) )
goto V_294;
F_114 ( V_292 , V_183 , L_39 , V_282 ) ;
F_114 ( V_293 , V_183 , L_39 , V_283 ) ;
if ( F_100 ( & V_236 , V_292 ) )
goto V_295;
if ( F_123 ( & V_267 , V_282 , V_236 . V_4 ) )
goto V_296;
if ( F_101 ( & V_290 , V_293 , V_236 . V_238 , false ) )
goto V_296;
if ( ! V_267 . V_281 . V_28 )
V_245 -= 1 ;
if ( F_104 ( & V_236 , & V_290 , V_245 ) )
goto V_297;
if ( F_107 ( & V_290 , V_36 ++ , V_180 , V_267 . V_280 . V_28 ,
V_267 . V_280 . V_231 ) )
goto V_297;
if ( V_267 . V_281 . V_28 ) {
V_291 = V_180 + V_267 . V_280 . V_231 ;
if ( F_107 ( & V_290 , V_36 , V_291 ,
V_267 . V_281 . V_28 , V_267 . V_281 . V_231 ) )
goto V_297;
}
V_92 = F_109 ( & V_290 ) ;
if ( V_92 < 0 || V_92 > V_180 )
goto V_297;
if ( F_97 ( V_236 . V_94 , V_267 . V_280 . V_180 , V_290 . V_94 , V_180 ,
V_267 . V_280 . V_231 ) )
goto V_297;
if ( V_291 && F_97 ( V_236 . V_94 , V_267 . V_281 . V_180 ,
V_290 . V_94 , V_291 ,
V_267 . V_281 . V_231 ) )
goto V_297;
if ( F_132 ( V_282 , V_283 , L_38 ) )
goto V_297;
if ( F_132 ( V_282 , V_283 , L_37 ) )
goto V_297;
V_60 = 0 ;
V_297:
F_103 ( & V_290 ) ;
if ( V_60 )
F_53 ( V_293 ) ;
V_296:
F_103 ( & V_236 ) ;
V_295:
if ( V_60 )
F_128 ( V_283 , L_38 ) ;
V_294:
if ( V_60 )
F_128 ( V_283 , L_37 ) ;
return V_60 ;
}
int F_134 ( struct V_298 * V_299 )
{
struct V_236 V_236 ;
struct V_236 V_290 ;
T_3 V_245 = 1 ;
int V_36 = 0 , V_60 = - 1 ;
T_23 V_180 = V_234 , V_92 ;
if ( F_100 ( & V_236 , V_299 -> V_292 ) )
return - 1 ;
strcpy ( V_299 -> V_293 , V_300 ) ;
if ( F_101 ( & V_290 , V_299 -> V_293 , V_236 . V_238 , true ) )
goto V_296;
if ( F_104 ( & V_236 , & V_290 , V_245 ) )
goto V_297;
if ( F_107 ( & V_290 , V_36 , V_180 , V_299 -> V_28 , V_299 -> V_231 ) )
goto V_297;
V_92 = F_109 ( & V_290 ) ;
if ( V_92 < 0 || V_92 > V_180 )
goto V_297;
if ( F_97 ( V_236 . V_94 , V_299 -> V_301 , V_290 . V_94 , V_180 , V_299 -> V_231 ) )
goto V_297;
V_60 = 0 ;
V_297:
F_103 ( & V_290 ) ;
if ( V_60 )
F_53 ( V_299 -> V_293 ) ;
V_296:
F_103 ( & V_236 ) ;
return V_60 ;
}
void F_135 ( struct V_298 * V_299 )
{
F_53 ( V_299 -> V_293 ) ;
}
static int F_136 ( T_2 * * V_4 , const char * V_79 , T_3 V_231 ,
struct V_302 * V_303 )
{
const char * V_304 , * V_35 ;
struct V_305 * V_306 = NULL ;
T_4 V_7 ;
T_9 V_307 = 0 ;
T_8 V_25 ;
int V_288 = - V_110 ;
union {
T_24 V_308 [ V_309 ] ;
T_25 V_310 [ V_309 ] ;
} V_233 ;
T_7 V_5 = {
. V_24 = & V_233 , . V_311 = V_312 , . V_313 = V_314 ,
. V_65 = F_137 ( ( * V_4 ) , V_312 , V_309 , V_314 ) ,
. V_315 = 0 , . V_316 = 0
} ;
T_7 V_317 = {
. V_24 = ( void * ) V_79 , . V_311 = V_312 ,
. V_313 = V_314 , . V_65 = V_5 . V_65 , . V_315 = 0 ,
. V_316 = 0
} ;
V_306 = (struct V_305 * ) calloc ( 1 , sizeof( struct V_305 ) ) ;
if ( ! V_306 ) {
V_288 = - V_318 ;
goto V_319;
}
F_138 ( & V_306 -> V_320 ) ;
if ( V_231 < V_5 . V_65 + 3 )
goto V_321;
if ( F_139 ( * V_4 , & V_5 , & V_317 ,
F_140 ( * V_4 , NULL ) [ V_130 ] ) == NULL ) {
F_6 ( L_40 , F_141 ( - 1 ) ) ;
goto V_321;
}
V_304 = V_79 + V_5 . V_65 ;
V_35 = ( const char * ) memchr ( V_304 , '\0' , V_79 + V_231 - V_304 ) ;
if ( V_35 ++ == NULL )
goto V_321;
V_306 -> V_304 = F_63 ( V_304 ) ;
if ( ! V_306 -> V_304 ) {
V_288 = - V_318 ;
goto V_321;
}
V_306 -> V_35 = F_63 ( V_35 ) ;
if ( ! V_306 -> V_35 ) {
V_288 = - V_318 ;
goto V_322;
}
if ( F_62 ( * V_4 ) == V_254 ) {
memcpy ( & V_306 -> V_28 , & V_233 , 3 * sizeof( T_25 ) ) ;
V_306 -> V_323 = true ;
} else {
memcpy ( & V_306 -> V_28 , & V_233 , 3 * sizeof( T_24 ) ) ;
V_306 -> V_323 = false ;
}
if ( ! F_4 ( * V_4 , & V_7 ) ) {
F_34 ( L_41 , V_9 ) ;
V_288 = - V_324 ;
goto V_325;
}
if ( F_21 ( * V_4 , & V_7 , & V_25 , V_326 , NULL ) ) {
V_307 = V_25 . V_67 ;
if ( V_307 ) {
if ( V_306 -> V_323 )
V_306 -> V_28 . V_310 [ 0 ] = V_306 -> V_28 . V_310 [ 0 ] + V_307 -
V_306 -> V_28 . V_310 [ 1 ] ;
else
V_306 -> V_28 . V_308 [ 0 ] = V_306 -> V_28 . V_308 [ 0 ] + V_307 -
V_306 -> V_28 . V_308 [ 1 ] ;
}
}
F_142 ( & V_306 -> V_320 , V_303 ) ;
return 0 ;
V_325:
free ( V_306 -> V_35 ) ;
V_322:
free ( V_306 -> V_304 ) ;
V_321:
free ( V_306 ) ;
V_319:
return V_288 ;
}
static int F_143 ( T_2 * V_4 , struct V_302 * V_303 )
{
T_4 V_7 ;
T_10 * V_327 = NULL ;
T_7 * V_79 ;
T_8 V_25 ;
T_3 V_328 , V_329 ;
T_17 V_85 ;
T_3 V_330 , V_331 , V_180 ;
int V_288 = 0 ;
if ( F_4 ( V_4 , & V_7 ) == NULL ) {
V_288 = - V_324 ;
goto V_332;
}
if ( F_5 ( V_4 , & V_328 ) != 0 ) {
V_288 = - V_324 ;
goto V_332;
}
V_327 = F_21 ( V_4 , & V_7 , & V_25 , V_333 , NULL ) ;
if ( ! V_327 ) {
V_288 = - V_334 ;
goto V_332;
}
if ( ( V_25 . V_68 != V_335 ) || ( V_25 . V_336 & V_337 ) ) {
V_288 = - V_334 ;
goto V_332;
}
V_79 = F_26 ( V_327 , NULL ) ;
for ( V_180 = 0 ; ( V_329 = F_144 ( V_79 , V_180 , & V_85 , & V_330 ,
& V_331 ) ) > 0 ; V_180 = V_329 ) {
if ( V_85 . V_87 == sizeof( V_338 ) &&
! memcmp ( V_79 -> V_24 + V_330 , V_338 ,
sizeof( V_338 ) ) ) {
if ( V_85 . V_90 != V_339 )
goto V_332;
V_288 = F_136 ( & V_4 , ( ( V_79 -> V_24 ) + V_331 ) ,
V_85 . V_89 , V_303 ) ;
if ( V_288 < 0 )
goto V_332;
}
}
if ( F_145 ( V_303 ) )
V_288 = - V_334 ;
V_332:
return V_288 ;
}
int F_146 ( struct V_302 * V_340 , const char * V_341 )
{
T_2 * V_4 ;
int V_94 , V_288 ;
V_94 = F_40 ( V_341 , V_95 ) ;
if ( V_94 < 0 )
return - V_324 ;
V_4 = F_41 ( V_94 , V_96 , NULL ) ;
if ( ! V_4 ) {
V_288 = - V_324 ;
goto V_97;
}
V_288 = F_143 ( V_4 , V_340 ) ;
F_43 ( V_4 ) ;
V_97:
F_44 ( V_94 ) ;
return V_288 ;
}
int F_147 ( struct V_302 * V_303 )
{
struct V_305 * V_306 , * V_71 ;
int V_342 = 0 ;
F_148 (pos, tmp, sdt_notes, note_list) {
F_149 ( & V_71 -> V_320 ) ;
free ( V_71 -> V_35 ) ;
free ( V_71 -> V_304 ) ;
free ( V_71 ) ;
V_342 ++ ;
}
return V_342 ;
}
int F_150 ( struct V_302 * V_172 )
{
struct V_305 * V_343 ;
int V_245 = 0 ;
F_151 (sdt_ptr, start, note_list)
V_245 ++ ;
return V_245 ;
}
void F_152 ( void )
{
F_153 ( V_314 ) ;
}
