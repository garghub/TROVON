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
T_12 V_58 , V_59 , V_60 ;
T_8 V_61 ;
struct V_62 * V_63 ;
T_8 V_64 , V_65 ;
T_7 * V_66 , * V_67 , * V_23 ;
T_10 * V_68 , * V_69 , * V_70 ;
T_3 V_71 ;
T_4 V_7 ;
char V_72 [ 1024 ] ;
T_2 * V_4 ;
int V_73 = 0 , V_74 , V_75 = 0 ;
if ( ! V_55 -> V_76 )
return 0 ;
V_4 = V_55 -> V_4 ;
V_7 = V_55 -> V_7 ;
V_70 = V_55 -> V_76 ;
V_65 = V_55 -> V_77 ;
V_71 = V_55 -> V_71 ;
if ( V_70 == NULL )
goto V_78;
V_68 = F_21 ( V_4 , & V_7 , & V_64 ,
L_4 , NULL ) ;
if ( V_68 == NULL ) {
V_68 = F_21 ( V_4 , & V_7 , & V_64 ,
L_5 , NULL ) ;
if ( V_68 == NULL )
goto V_78;
}
V_75 = - 1 ;
if ( V_64 . V_79 != V_71 )
goto V_78;
if ( F_21 ( V_4 , & V_7 , & V_61 , L_6 , NULL ) == NULL )
goto V_78;
V_66 = F_31 ( V_68 , NULL ) ;
if ( V_66 == NULL )
goto V_78;
V_67 = F_31 ( V_70 , NULL ) ;
if ( V_67 == NULL )
goto V_78;
V_69 = F_23 ( V_4 , V_65 . V_79 ) ;
if ( V_69 == NULL )
goto V_78;
V_23 = F_31 ( V_69 , NULL ) ;
if ( V_23 == NULL )
goto V_78;
if ( V_23 -> V_80 == 0 )
goto V_78;
V_57 = V_64 . V_32 / V_64 . V_81 ;
V_58 = V_61 . V_82 ;
switch ( V_7 . V_83 ) {
case V_84 :
V_59 = 20 ;
V_60 = 12 ;
break;
case V_85 :
V_59 = 32 ;
V_60 = 16 ;
break;
default:
V_59 = V_61 . V_81 ;
V_60 = V_61 . V_81 ;
break;
}
V_58 += V_59 ;
if ( V_64 . V_86 == V_87 ) {
T_13 V_88 , * V_89 ;
F_32 (reldata, pos, pos_mem, idx,
nr_rel_entries) {
const char * V_45 = NULL ;
char * V_51 = NULL ;
V_74 = F_33 ( V_89 -> V_90 ) ;
F_34 ( V_67 , V_74 , & V_10 ) ;
V_45 = F_13 ( & V_10 , V_23 ) ;
V_51 = F_26 ( V_43 , 0 , V_45 ) ;
if ( V_51 != NULL )
V_45 = V_51 ;
snprintf ( V_72 , sizeof( V_72 ) ,
L_7 , V_45 ) ;
free ( V_51 ) ;
V_63 = F_35 ( V_58 , V_60 ,
V_91 , V_72 ) ;
if ( ! V_63 )
goto V_78;
V_58 += V_60 ;
F_36 ( & V_43 -> V_92 [ V_56 -> type ] , V_63 ) ;
++ V_73 ;
}
} else if ( V_64 . V_86 == V_93 ) {
T_14 V_88 , * V_89 ;
F_37 (reldata, pos, pos_mem, idx,
nr_rel_entries) {
const char * V_45 = NULL ;
char * V_51 = NULL ;
V_74 = F_33 ( V_89 -> V_90 ) ;
F_34 ( V_67 , V_74 , & V_10 ) ;
V_45 = F_13 ( & V_10 , V_23 ) ;
V_51 = F_26 ( V_43 , 0 , V_45 ) ;
if ( V_51 != NULL )
V_45 = V_51 ;
snprintf ( V_72 , sizeof( V_72 ) ,
L_7 , V_45 ) ;
free ( V_51 ) ;
V_63 = F_35 ( V_58 , V_60 ,
V_91 , V_72 ) ;
if ( ! V_63 )
goto V_78;
V_58 += V_60 ;
F_36 ( & V_43 -> V_92 [ V_56 -> type ] , V_63 ) ;
++ V_73 ;
}
}
V_75 = 0 ;
V_78:
if ( V_75 == 0 )
return V_73 ;
F_38 ( L_8 ,
V_9 , V_43 -> V_94 ) ;
return 0 ;
}
char * F_39 ( struct V_43 * V_43 , int V_44 , const char * V_45 )
{
return F_26 ( V_43 , V_44 , V_45 ) ;
}
static int F_40 ( T_2 * V_4 , void * V_95 , T_3 V_96 )
{
int V_75 = - 1 ;
T_4 V_7 ;
T_8 V_25 ;
T_7 * V_97 ;
T_10 * V_29 ;
T_15 V_98 ;
void * V_99 ;
if ( V_96 < V_100 )
goto V_101;
V_98 = F_41 ( V_4 ) ;
if ( V_98 != V_102 )
goto V_101;
if ( F_4 ( V_4 , & V_7 ) == NULL ) {
F_6 ( L_9 , V_9 ) ;
goto V_101;
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
return V_75 ;
} while ( 0 );
V_97 = F_31 ( V_29 , NULL ) ;
if ( V_97 == NULL )
goto V_101;
V_99 = V_97 -> V_24 ;
while ( V_99 < ( V_97 -> V_24 + V_97 -> V_80 ) ) {
T_16 * V_103 = V_99 ;
T_3 V_104 = F_42 ( V_103 -> V_105 ) ,
V_106 = F_42 ( V_103 -> V_107 ) ;
const char * V_35 ;
V_99 += sizeof( * V_103 ) ;
V_35 = V_99 ;
V_99 += V_104 ;
if ( V_103 -> V_108 == V_109 &&
V_103 -> V_105 == sizeof( L_13 ) ) {
if ( memcmp ( V_35 , L_13 , sizeof( L_13 ) ) == 0 ) {
T_3 V_110 = F_43 ( V_96 , V_106 ) ;
memcpy ( V_95 , V_99 , V_110 ) ;
memset ( V_95 + V_110 , 0 , V_96 - V_110 ) ;
V_75 = V_106 ;
break;
}
}
V_99 += V_106 ;
}
V_101:
return V_75 ;
}
int F_44 ( const char * V_111 , void * V_95 , T_3 V_96 )
{
int V_112 , V_75 = - 1 ;
T_2 * V_4 ;
if ( V_96 < V_100 )
goto V_101;
V_112 = F_45 ( V_111 , V_113 ) ;
if ( V_112 < 0 )
goto V_101;
V_4 = F_46 ( V_112 , V_114 , NULL ) ;
if ( V_4 == NULL ) {
F_47 ( L_14 , V_9 , V_111 ) ;
goto V_115;
}
V_75 = F_40 ( V_4 , V_95 , V_96 ) ;
F_48 ( V_4 ) ;
V_115:
F_49 ( V_112 ) ;
V_101:
return V_75 ;
}
int F_50 ( const char * V_111 , void * V_116 , T_3 V_96 )
{
int V_112 , V_75 = - 1 ;
if ( V_96 < V_100 )
goto V_101;
V_112 = F_45 ( V_111 , V_113 ) ;
if ( V_112 < 0 )
goto V_101;
while ( 1 ) {
char V_95 [ V_117 ] ;
T_16 V_103 ;
T_3 V_104 , V_106 ;
if ( F_51 ( V_112 , & V_103 , sizeof( V_103 ) ) != sizeof( V_103 ) )
break;
V_104 = F_42 ( V_103 . V_105 ) ;
V_106 = F_42 ( V_103 . V_107 ) ;
if ( V_103 . V_108 == V_109 &&
V_103 . V_105 == sizeof( L_13 ) ) {
if ( F_51 ( V_112 , V_95 , V_104 ) != ( V_118 ) V_104 )
break;
if ( memcmp ( V_95 , L_13 , sizeof( L_13 ) ) == 0 ) {
T_3 V_110 = F_43 ( V_106 , V_96 ) ;
if ( F_51 ( V_112 , V_116 , V_110 ) == ( V_118 ) V_110 ) {
memset ( V_116 + V_110 , 0 , V_96 - V_110 ) ;
V_75 = 0 ;
break;
}
} else if ( F_51 ( V_112 , V_95 , V_106 ) != ( V_118 ) V_106 )
break;
} else {
int V_119 = V_104 + V_106 ;
if ( V_119 > ( int ) sizeof( V_95 ) ) {
V_119 = sizeof( V_95 ) ;
F_38 ( L_15 ,
V_9 , V_111 , V_103 . V_105 , V_103 . V_107 ) ;
}
if ( F_51 ( V_112 , V_95 , V_119 ) != V_119 )
break;
}
}
F_49 ( V_112 ) ;
V_101:
return V_75 ;
}
int F_52 ( const char * V_111 , char * V_120 ,
T_3 V_96 )
{
int V_112 , V_75 = - 1 ;
T_2 * V_4 ;
T_4 V_7 ;
T_8 V_25 ;
T_7 * V_97 ;
T_10 * V_29 ;
T_15 V_98 ;
V_112 = F_45 ( V_111 , V_113 ) ;
if ( V_112 < 0 )
goto V_101;
V_4 = F_46 ( V_112 , V_114 , NULL ) ;
if ( V_4 == NULL ) {
F_47 ( L_14 , V_9 , V_111 ) ;
goto V_115;
}
V_98 = F_41 ( V_4 ) ;
if ( V_98 != V_102 )
goto V_78;
if ( F_4 ( V_4 , & V_7 ) == NULL ) {
F_6 ( L_9 , V_9 ) ;
goto V_78;
}
V_29 = F_21 ( V_4 , & V_7 , & V_25 ,
L_16 , NULL ) ;
if ( V_29 == NULL )
goto V_78;
V_97 = F_31 ( V_29 , NULL ) ;
if ( V_97 == NULL )
goto V_78;
strncpy ( V_120 , V_97 -> V_24 , V_96 ) ;
V_75 = 0 ;
V_78:
F_48 ( V_4 ) ;
V_115:
F_49 ( V_112 ) ;
V_101:
return V_75 ;
}
static int F_53 ( struct V_43 * V_43 , unsigned char V_121 )
{
static unsigned int const V_122 = 1 ;
V_43 -> V_123 = V_124 ;
switch ( V_121 ) {
case V_125 :
if ( * ( unsigned char const * ) & V_122 != 1 )
V_43 -> V_123 = V_126 ;
break;
case V_127 :
if ( * ( unsigned char const * ) & V_122 != 0 )
V_43 -> V_123 = V_126 ;
break;
default:
F_6 ( L_17 , V_121 ) ;
return - V_128 ;
}
return 0 ;
}
bool F_54 ( struct V_54 * V_55 )
{
return V_55 -> V_76 || V_55 -> V_129 ;
}
bool F_55 ( struct V_54 * V_55 )
{
return V_55 -> V_130 != NULL ;
}
void F_56 ( struct V_54 * V_55 )
{
F_57 ( & V_55 -> V_35 ) ;
F_48 ( V_55 -> V_4 ) ;
F_49 ( V_55 -> V_112 ) ;
}
bool __weak F_58 ( T_4 V_7 )
{
return V_7 . V_131 == V_132 || V_7 . V_131 == V_133 ;
}
int F_59 ( struct V_54 * V_55 , struct V_43 * V_43 , const char * V_35 ,
enum V_134 type )
{
int V_75 = - 1 ;
T_4 V_7 ;
T_2 * V_4 ;
int V_112 ;
if ( F_60 ( V_43 ) ) {
V_112 = F_61 ( V_43 , V_35 ) ;
if ( V_112 < 0 )
return - 1 ;
type = V_43 -> V_135 ;
} else {
V_112 = F_45 ( V_35 , V_113 ) ;
if ( V_112 < 0 ) {
V_43 -> V_136 = V_137 ;
return - 1 ;
}
}
V_4 = F_46 ( V_112 , V_114 , NULL ) ;
if ( V_4 == NULL ) {
F_38 ( L_14 , V_9 , V_35 ) ;
V_43 -> V_136 = V_138 ;
goto V_115;
}
if ( F_4 ( V_4 , & V_7 ) == NULL ) {
V_43 -> V_136 = V_138 ;
F_38 ( L_9 , V_9 ) ;
goto V_78;
}
if ( F_53 ( V_43 , V_7 . V_139 [ V_140 ] ) ) {
V_43 -> V_136 = V_141 ;
goto V_78;
}
if ( V_43 -> V_142 && ! V_40 . V_143 ) {
T_17 V_116 [ V_100 ] ;
if ( F_40 ( V_4 , V_116 , V_100 ) < 0 ) {
V_43 -> V_136 = V_144 ;
goto V_78;
}
if ( ! F_62 ( V_43 , V_116 ) ) {
F_38 ( L_18 , V_9 , V_35 ) ;
V_43 -> V_136 = V_145 ;
goto V_78;
}
}
V_55 -> V_146 = ( F_63 ( V_4 ) == V_147 ) ;
V_55 -> V_130 = F_21 ( V_4 , & V_7 , & V_55 -> V_148 , L_19 ,
NULL ) ;
if ( V_55 -> V_148 . V_86 != V_149 )
V_55 -> V_130 = NULL ;
V_55 -> V_71 = 0 ;
V_55 -> V_76 = F_21 ( V_4 , & V_7 , & V_55 -> V_77 , L_20 ,
& V_55 -> V_71 ) ;
if ( V_55 -> V_77 . V_86 != V_150 )
V_55 -> V_76 = NULL ;
V_55 -> V_151 = 0 ;
V_55 -> V_129 = F_21 ( V_4 , & V_7 , & V_55 -> V_152 , L_21 ,
& V_55 -> V_151 ) ;
if ( V_55 -> V_152 . V_86 != V_153 )
V_55 -> V_129 = NULL ;
if ( V_43 -> V_52 == V_154 )
V_55 -> V_155 = true ;
else
V_55 -> V_155 = F_58 ( V_7 ) ;
V_55 -> V_35 = F_64 ( V_35 ) ;
if ( ! V_55 -> V_35 ) {
V_43 -> V_136 = V_137 ;
goto V_78;
}
V_55 -> V_4 = V_4 ;
V_55 -> V_112 = V_112 ;
V_55 -> V_7 = V_7 ;
V_55 -> type = type ;
return 0 ;
V_78:
F_48 ( V_4 ) ;
V_115:
F_49 ( V_112 ) ;
return V_75 ;
}
static bool F_65 ( struct V_156 * V_156 )
{
return V_156 && V_156 -> V_157 && V_156 -> V_157 -> V_35 &&
! V_156 -> V_157 -> V_158 ;
}
static T_12 F_66 ( struct V_156 * V_156 )
{
if ( V_156 && V_156 -> V_157 &&
V_156 -> V_157 -> V_158 )
return V_156 -> V_157 -> V_28 -
V_156 -> V_157 -> V_158 ;
return 0 ;
}
void __weak F_67 ( struct V_62 * T_18 T_1 ,
T_6 * V_10 T_1 ) { }
int F_68 ( struct V_43 * V_43 , struct V_56 * V_56 , struct V_54 * V_159 ,
struct V_54 * V_160 , int V_44 )
{
struct V_156 * V_156 = V_43 -> V_52 ? F_69 ( V_56 ) : NULL ;
struct V_161 * V_162 = V_156 ? F_70 ( V_56 ) : NULL ;
struct V_56 * V_163 = V_56 ;
struct V_43 * V_164 = V_43 ;
T_7 * V_23 , * V_26 ;
T_11 V_165 ;
int V_75 = - 1 ;
T_11 V_36 ;
T_4 V_7 ;
T_8 V_25 ;
T_8 V_166 ;
T_7 * V_67 , * V_167 = NULL ;
T_6 V_10 ;
T_10 * V_29 , * V_168 ;
T_2 * V_4 ;
int V_73 = 0 ;
bool V_169 = false , V_170 = false ;
if ( V_156 && ! V_162 )
return - 1 ;
V_43 -> V_135 = V_159 -> type ;
V_43 -> V_146 = V_159 -> V_146 ;
V_43 -> V_171 = V_159 -> V_7 . V_131 == V_133 ;
if ( V_44 && V_159 -> V_130 )
F_71 ( & V_43 -> V_92 [ V_56 -> type ] ) ;
if ( ! V_159 -> V_130 ) {
if ( V_43 -> V_52 )
goto V_78;
V_159 -> V_130 = V_159 -> V_76 ;
V_159 -> V_148 = V_159 -> V_77 ;
}
V_4 = V_159 -> V_4 ;
V_7 = V_159 -> V_7 ;
V_29 = V_159 -> V_130 ;
V_25 = V_159 -> V_148 ;
if ( F_21 ( V_160 -> V_4 , & V_160 -> V_7 , & V_166 ,
L_22 , NULL ) )
V_43 -> V_172 = V_166 . V_31 - V_166 . V_82 ;
if ( V_160 -> V_129 )
V_167 = F_22 ( V_160 -> V_129 , NULL ) ;
V_67 = F_31 ( V_29 , NULL ) ;
if ( V_67 == NULL )
goto V_78;
V_29 = F_23 ( V_4 , V_25 . V_79 ) ;
if ( V_29 == NULL )
goto V_78;
V_23 = F_31 ( V_29 , NULL ) ;
if ( V_23 == NULL )
goto V_78;
V_168 = F_23 ( V_160 -> V_4 , V_160 -> V_7 . V_37 ) ;
if ( V_168 == NULL )
goto V_78;
V_26 = F_31 ( V_168 , NULL ) ;
if ( V_26 == NULL )
goto V_78;
V_165 = V_25 . V_32 / V_25 . V_81 ;
memset ( & V_10 , 0 , sizeof( V_10 ) ) ;
if ( F_65 ( V_156 ) ) {
F_72 (syms, nr_syms, idx, sym) {
const char * V_45 = F_13 ( & V_10 , V_23 ) ;
if ( strcmp ( V_45 , V_156 -> V_157 -> V_35 ) )
continue;
V_156 -> V_157 -> V_158 = V_10 . V_173 ;
V_56 -> V_174 = V_156 -> V_157 -> V_28 -
V_156 -> V_157 -> V_158 ;
break;
}
}
if ( F_73 ( V_43 ) )
V_56 -> V_174 = V_56 -> V_175 - V_43 -> V_172 ;
V_43 -> V_155 = V_160 -> V_155 || F_66 ( V_156 ) ;
if ( V_56 -> type == V_21 && ( V_43 -> V_52 || V_44 ) ) {
V_169 = true ;
V_170 = V_43 -> V_155 ;
}
F_72 (syms, nr_syms, idx, sym) {
struct V_62 * V_63 ;
const char * V_45 = F_13 ( & V_10 , V_23 ) ;
char * V_51 = NULL ;
int V_176 = F_11 ( & V_10 ) ;
const char * V_177 ;
bool V_178 = false ;
if ( ! V_176 && ! F_12 ( & V_10 , V_56 -> type ) )
continue;
if ( V_7 . V_83 == V_84 || V_7 . V_83 == V_85 ) {
if ( V_45 [ 0 ] == '$' && strchr ( L_23 , V_45 [ 1 ] )
&& ( V_45 [ 2 ] == '\0' || V_45 [ 2 ] == '.' ) )
continue;
}
if ( V_160 -> V_129 && V_10 . V_15 == V_160 -> V_151 ) {
T_19 V_179 = V_10 . V_173 - V_159 -> V_152 . V_31 ;
T_12 * V_180 = V_167 -> V_24 + V_179 ;
V_10 . V_173 = F_74 ( V_43 , T_12 , * V_180 ) ;
V_10 . V_15 = F_18 ( V_160 -> V_4 ,
V_10 . V_173 ) ;
V_178 = true ;
}
if ( V_10 . V_15 == V_19 )
continue;
V_29 = F_23 ( V_160 -> V_4 , V_10 . V_15 ) ;
if ( ! V_29 )
goto V_78;
F_20 ( V_29 , & V_25 ) ;
if ( V_176 && ! F_17 ( & V_25 , V_26 , V_56 -> type ) )
continue;
V_177 = F_14 ( & V_25 , V_26 ) ;
if ( ( V_7 . V_83 == V_84 ) &&
( V_56 -> type == V_21 ) &&
( V_10 . V_173 & 1 ) )
-- V_10 . V_173 ;
if ( V_43 -> V_52 || V_44 ) {
char V_181 [ V_182 ] ;
if ( V_170 )
V_10 . V_173 -= V_25 . V_31 - V_25 . V_82 ;
if ( strcmp ( V_177 ,
( V_164 -> V_183 +
V_43 -> V_184 ) ) == 0 )
goto V_185;
if ( strcmp ( V_177 , L_22 ) == 0 ) {
if ( V_169 && V_43 -> V_52 ) {
V_169 = false ;
V_56 -> V_175 = V_25 . V_31 +
F_66 ( V_156 ) ;
V_56 -> V_186 = V_56 -> V_175 + V_25 . V_32 ;
V_56 -> V_187 = V_25 . V_82 ;
V_56 -> V_188 = V_189 ;
V_56 -> V_190 = V_191 ;
if ( V_162 ) {
F_75 ( V_56 ) ;
F_76 ( V_162 , V_56 ) ;
F_77 ( V_162 , V_56 ) ;
F_78 ( V_56 ) ;
}
}
if ( V_169 && V_44 ) {
V_169 = false ;
V_56 -> V_187 = V_25 . V_82 ;
}
V_163 = V_56 ;
V_164 = V_43 ;
goto V_185;
}
if ( ! V_156 )
goto V_185;
snprintf ( V_181 , sizeof( V_181 ) ,
L_24 , V_43 -> V_183 , V_177 ) ;
V_163 = F_79 ( V_162 , V_56 -> type , V_181 ) ;
if ( V_163 == NULL ) {
T_12 V_175 = V_10 . V_173 ;
if ( V_44 )
V_175 += V_56 -> V_175 + V_25 . V_82 ;
V_164 = F_80 ( V_181 ) ;
if ( V_164 == NULL )
goto V_78;
V_164 -> V_52 = V_43 -> V_52 ;
V_164 -> V_94 = V_43 -> V_94 ;
V_164 -> V_192 = V_43 -> V_192 ;
V_163 = F_81 ( V_175 , V_164 ,
V_56 -> type ) ;
F_82 ( V_164 ) ;
if ( V_163 == NULL ) {
goto V_78;
}
if ( V_170 ) {
V_163 -> V_175 = V_25 . V_31 +
F_66 ( V_156 ) ;
V_163 -> V_186 = V_163 -> V_175 +
V_25 . V_32 ;
V_163 -> V_187 = V_25 . V_82 ;
} else {
V_163 -> V_188 = V_193 ;
V_163 -> V_190 = V_193 ;
}
V_164 -> V_135 = V_43 -> V_135 ;
F_77 ( V_162 , V_163 ) ;
F_83 ( & V_56 -> V_194 -> V_195 -> V_196 , V_164 ) ;
F_78 ( V_163 ) ;
F_84 ( V_164 , V_56 -> type ) ;
} else
V_164 = V_163 -> V_43 ;
goto V_185;
}
if ( ( V_178 && V_160 -> V_155 )
|| ( ! V_178 && V_159 -> V_155 ) ) {
F_85 ( L_25 V_197 L_26
L_27 V_197 L_28 V_197 L_29 , V_9 ,
( T_12 ) V_10 . V_173 , ( T_12 ) V_25 . V_31 ,
( T_12 ) V_25 . V_82 ) ;
V_10 . V_173 -= V_25 . V_31 - V_25 . V_82 ;
}
V_185:
V_51 = F_26 ( V_43 , V_44 , V_45 ) ;
if ( V_51 != NULL )
V_45 = V_51 ;
V_63 = F_35 ( V_10 . V_173 , V_10 . V_198 ,
F_86 ( V_10 . V_11 ) , V_45 ) ;
free ( V_51 ) ;
if ( ! V_63 )
goto V_78;
F_67 ( V_63 , & V_10 ) ;
F_87 ( & V_164 -> V_92 [ V_163 -> type ] , V_63 , V_43 -> V_52 ) ;
V_73 ++ ;
}
if ( V_73 > 0 ) {
F_88 ( & V_43 -> V_92 [ V_56 -> type ] ) ;
F_89 ( & V_43 -> V_92 [ V_56 -> type ] ) ;
if ( V_156 ) {
F_90 ( V_162 , V_56 -> type ) ;
}
}
V_75 = V_73 ;
V_78:
return V_75 ;
}
static int F_91 ( T_2 * V_4 , bool V_199 , T_20 V_200 , void * V_97 )
{
T_21 V_201 ;
T_3 V_3 , V_202 ;
int V_75 ;
T_12 V_110 ;
if ( F_3 ( V_4 , & V_202 ) )
return - 1 ;
for ( V_3 = 0 ; V_3 < V_202 ; V_3 ++ ) {
if ( F_92 ( V_4 , V_3 , & V_201 ) == NULL )
return - 1 ;
if ( V_201 . V_203 != V_204 )
continue;
if ( V_199 ) {
if ( ! ( V_201 . V_205 & V_206 ) )
continue;
} else {
if ( ! ( V_201 . V_205 & V_207 ) )
continue;
}
V_110 = F_43 ( V_201 . V_208 , V_201 . V_209 ) ;
if ( ! V_110 )
continue;
V_75 = V_200 ( V_201 . V_210 , V_110 , V_201 . V_211 , V_97 ) ;
if ( V_75 )
return V_75 ;
}
return 0 ;
}
int F_93 ( int V_112 , bool V_199 , T_20 V_200 , void * V_97 ,
bool * V_146 )
{
int V_75 ;
T_2 * V_4 ;
V_4 = F_46 ( V_112 , V_114 , NULL ) ;
if ( V_4 == NULL )
return - 1 ;
if ( V_146 )
* V_146 = ( F_63 ( V_4 ) == V_147 ) ;
V_75 = F_91 ( V_4 , V_199 , V_200 , V_97 ) ;
F_48 ( V_4 ) ;
return V_75 ;
}
enum V_212 F_94 ( int V_112 )
{
enum V_212 V_212 = V_213 ;
T_4 V_7 ;
T_15 V_98 ;
T_2 * V_4 ;
V_4 = F_46 ( V_112 , V_114 , NULL ) ;
if ( V_4 == NULL )
goto V_101;
V_98 = F_41 ( V_4 ) ;
if ( V_98 != V_102 )
goto V_214;
if ( F_63 ( V_4 ) == V_147 ) {
V_212 = V_215 ;
goto V_214;
}
if ( F_4 ( V_4 , & V_7 ) == NULL )
goto V_214;
if ( V_7 . V_83 == V_216 )
V_212 = V_217 ;
else
V_212 = V_218 ;
V_214:
F_48 ( V_4 ) ;
V_101:
return V_212 ;
}
static int F_95 ( int V_219 , T_22 V_220 , int V_221 , T_22 V_222 , T_12 V_223 )
{
V_118 V_224 ;
T_3 V_119 ;
int V_75 = - 1 ;
char * V_225 = malloc ( V_226 ) ;
if ( V_225 == NULL )
return - 1 ;
if ( F_96 ( V_221 , V_222 , V_227 ) != V_222 )
goto V_101;
if ( F_96 ( V_219 , V_220 , V_227 ) != V_220 )
goto V_101;
while ( V_223 ) {
V_119 = V_226 ;
if ( V_223 < V_119 )
V_119 = V_223 ;
V_224 = F_51 ( V_219 , V_225 , V_119 ) ;
if ( V_224 < 0 )
goto V_101;
if ( ! V_224 )
break;
V_119 = V_224 ;
V_224 = F_97 ( V_221 , V_225 , V_119 ) ;
if ( V_224 < 0 )
goto V_101;
if ( ( T_3 ) V_224 != V_119 )
goto V_101;
V_223 -= V_119 ;
}
V_75 = 0 ;
V_101:
free ( V_225 ) ;
return V_75 ;
}
static int F_98 ( struct V_228 * V_228 , const char * V_111 )
{
T_4 * V_7 ;
V_228 -> V_112 = F_45 ( V_111 , V_113 ) ;
if ( V_228 -> V_112 == - 1 )
return - 1 ;
V_228 -> V_4 = F_46 ( V_228 -> V_112 , V_229 , NULL ) ;
if ( ! V_228 -> V_4 )
goto V_115;
V_228 -> V_230 = F_63 ( V_228 -> V_4 ) ;
if ( V_228 -> V_230 == V_231 )
goto V_214;
V_7 = F_4 ( V_228 -> V_4 , & V_228 -> V_7 ) ;
if ( ! V_7 )
goto V_214;
return 0 ;
V_214:
F_48 ( V_228 -> V_4 ) ;
V_115:
F_49 ( V_228 -> V_112 ) ;
return - 1 ;
}
static int F_99 ( struct V_228 * V_228 , char * V_111 , int V_230 ,
bool V_232 )
{
V_228 -> V_230 = V_230 ;
if ( V_232 )
V_228 -> V_112 = F_100 ( V_111 ) ;
else
V_228 -> V_112 = F_45 ( V_111 , V_233 | V_234 | V_235 , 0400 ) ;
if ( V_228 -> V_112 == - 1 )
return - 1 ;
V_228 -> V_4 = F_46 ( V_228 -> V_112 , V_236 , NULL ) ;
if ( ! V_228 -> V_4 )
goto V_115;
if ( ! F_101 ( V_228 -> V_4 , V_230 ) )
goto V_214;
memset ( & V_228 -> V_7 , 0 , sizeof( T_4 ) ) ;
return 0 ;
V_214:
F_48 ( V_228 -> V_4 ) ;
V_115:
F_49 ( V_228 -> V_112 ) ;
F_102 ( V_111 ) ;
return - 1 ;
}
static void F_103 ( struct V_228 * V_228 )
{
F_48 ( V_228 -> V_4 ) ;
F_49 ( V_228 -> V_112 ) ;
}
static int F_104 ( struct V_228 * V_219 , struct V_228 * V_221 , T_3 V_237 )
{
T_4 * V_7 = & V_221 -> V_7 ;
T_4 * V_238 = & V_219 -> V_7 ;
memcpy ( V_7 -> V_139 , V_238 -> V_139 , V_239 ) ;
V_7 -> V_131 = V_238 -> V_131 ;
V_7 -> V_83 = V_238 -> V_83 ;
V_7 -> V_240 = V_238 -> V_240 ;
V_7 -> V_241 = 0 ;
V_7 -> V_242 = 0 ;
V_7 -> V_243 = V_238 -> V_243 ;
V_7 -> V_8 = V_237 ;
V_7 -> V_244 = 0 ;
V_7 -> V_245 = 0 ;
V_7 -> V_37 = 0 ;
if ( V_219 -> V_230 == V_246 ) {
V_7 -> V_247 = sizeof( V_248 ) ;
V_7 -> V_249 = sizeof( V_248 ) ;
V_7 -> V_250 = sizeof( V_251 ) ;
} else {
V_7 -> V_247 = sizeof( V_252 ) ;
V_7 -> V_249 = sizeof( V_252 ) ;
V_7 -> V_250 = sizeof( V_253 ) ;
}
if ( ! F_105 ( V_221 -> V_4 , V_7 ) )
return - 1 ;
if ( ! F_106 ( V_221 -> V_4 , V_237 ) )
return - 1 ;
return 0 ;
}
static int F_107 ( struct V_228 * V_228 , int V_36 , T_22 V_179 ,
T_12 V_28 , T_12 V_223 )
{
T_21 V_201 = {
. V_203 = V_204 ,
. V_205 = V_207 | V_254 | V_206 ,
. V_211 = V_179 ,
. V_210 = V_28 ,
. V_255 = 0 ,
. V_209 = V_223 ,
. V_208 = V_223 ,
. V_256 = V_226 ,
} ;
if ( ! F_108 ( V_228 -> V_4 , V_36 , & V_201 ) )
return - 1 ;
return 0 ;
}
static T_22 F_109 ( struct V_228 * V_228 )
{
return F_110 ( V_228 -> V_4 , V_236 ) ;
}
static int F_111 ( void * V_257 , const char * V_35 , char type ,
T_12 V_175 )
{
struct V_258 * V_259 = V_257 ;
if ( ! F_112 ( type , V_21 ) )
return 0 ;
if ( strchr ( V_35 , '[' ) ) {
if ( V_175 > V_259 -> V_260 )
V_259 -> V_260 = V_175 ;
return 0 ;
}
if ( ! V_259 -> V_261 || V_175 < V_259 -> V_261 )
V_259 -> V_261 = V_175 ;
if ( ! V_259 -> V_262 || V_175 > V_259 -> V_262 )
V_259 -> V_262 = V_175 ;
if ( ! strcmp ( V_35 , L_30 ) ) {
V_259 -> V_263 = V_175 ;
return 0 ;
}
if ( ! strcmp ( V_35 , L_31 ) ) {
V_259 -> V_264 = V_175 ;
return 0 ;
}
return 0 ;
}
static int F_113 ( struct V_258 * V_259 ,
const char * V_265 )
{
char V_266 [ V_182 ] ;
F_114 ( V_266 , V_182 , L_32 , V_265 ) ;
if ( F_115 ( V_266 , L_33 ) )
return - 1 ;
if ( F_116 ( V_266 , V_259 ,
F_111 ) < 0 )
return - 1 ;
return 0 ;
}
static int F_117 ( void * V_257 ,
const char * V_35 T_1 ,
T_12 V_175 , T_12 V_96 T_1 )
{
struct V_258 * V_259 = V_257 ;
if ( ! V_259 -> V_267 || V_175 < V_259 -> V_267 )
V_259 -> V_267 = V_175 ;
return 0 ;
}
static int F_118 ( struct V_258 * V_259 ,
const char * V_265 )
{
char V_268 [ V_182 ] ;
F_114 ( V_268 , V_182 , L_34 , V_265 ) ;
if ( F_115 ( V_268 , L_35 ) )
return - 1 ;
if ( F_119 ( V_268 , V_259 ,
F_117 ) < 0 )
return - 1 ;
return 0 ;
}
static void F_120 ( struct V_269 * V_270 , T_12 V_175 , T_12 V_186 , T_12 V_187 ,
T_12 T_18 , T_12 V_271 )
{
if ( V_270 -> V_28 || T_18 < V_175 || T_18 >= V_186 )
return;
V_270 -> V_28 = T_18 ;
V_270 -> V_179 = ( T_18 - V_175 ) + V_187 ;
V_270 -> V_223 = V_271 < V_186 ? V_271 - T_18 : V_186 - T_18 ;
}
static int F_121 ( T_12 V_175 , T_12 V_223 , T_12 V_187 , void * V_97 )
{
struct V_258 * V_259 = V_97 ;
T_12 V_186 = V_175 + V_223 ;
F_120 ( & V_259 -> V_272 , V_175 , V_186 , V_187 , V_259 -> V_263 ,
V_259 -> V_264 ) ;
F_120 ( & V_259 -> V_273 , V_175 , V_186 , V_187 , V_259 -> V_267 ,
V_259 -> V_260 ) ;
return 0 ;
}
static int F_122 ( struct V_258 * V_259 , T_2 * V_4 )
{
if ( F_91 ( V_4 , true , F_121 , V_259 ) < 0 )
return - 1 ;
return 0 ;
}
static int F_123 ( struct V_258 * V_259 , const char * V_265 ,
T_2 * V_4 )
{
if ( F_113 ( V_259 , V_265 ) )
return - 1 ;
if ( F_118 ( V_259 , V_265 ) )
return - 1 ;
if ( V_259 -> V_263 )
V_259 -> V_263 = F_124 ( V_259 -> V_263 , V_226 ) ;
else
V_259 -> V_263 = F_124 ( V_259 -> V_261 , V_226 ) ;
if ( V_259 -> V_264 ) {
V_259 -> V_264 = F_125 ( V_259 -> V_264 , V_226 ) ;
} else if ( V_259 -> V_262 ) {
V_259 -> V_264 = F_125 ( V_259 -> V_262 , V_226 ) ;
V_259 -> V_264 += V_226 ;
}
V_259 -> V_267 = F_124 ( V_259 -> V_267 , V_226 ) ;
if ( V_259 -> V_260 ) {
V_259 -> V_260 = F_125 ( V_259 -> V_260 ,
V_226 ) ;
V_259 -> V_260 += V_226 ;
}
if ( ! V_259 -> V_263 || ! V_259 -> V_264 )
return - 1 ;
if ( V_259 -> V_267 && ! V_259 -> V_260 )
return - 1 ;
return F_122 ( V_259 , V_4 ) ;
}
static int F_126 ( const char * V_274 , const char * V_275 ,
const char * V_35 )
{
char V_276 [ V_182 ] ;
char V_277 [ V_182 ] ;
F_114 ( V_276 , V_182 , L_36 , V_274 , V_35 ) ;
F_114 ( V_277 , V_182 , L_36 , V_275 , V_35 ) ;
return F_127 ( V_276 , V_277 , 0400 ) ;
}
static int F_128 ( const char * V_265 , const char * V_35 )
{
char V_111 [ V_182 ] ;
F_114 ( V_111 , V_182 , L_36 , V_265 , V_35 ) ;
return F_102 ( V_111 ) ;
}
static int F_129 ( int V_219 , int V_221 )
{
char * V_278 ;
char * V_279 ;
V_118 V_280 ;
T_3 V_223 ;
int V_75 = - 1 ;
V_278 = malloc ( V_226 ) ;
V_279 = malloc ( V_226 ) ;
if ( ! V_278 || ! V_279 )
goto V_101;
while ( 1 ) {
V_280 = F_51 ( V_219 , V_278 , V_226 ) ;
if ( V_280 < 0 )
goto V_101;
if ( ! V_280 )
break;
V_223 = V_280 ;
if ( F_130 ( V_221 , V_279 , V_223 ) != ( int ) V_223 )
goto V_101;
if ( memcmp ( V_278 , V_279 , V_223 ) )
goto V_101;
}
V_75 = 0 ;
V_101:
free ( V_279 ) ;
free ( V_278 ) ;
return V_75 ;
}
static int F_131 ( const char * V_276 ,
const char * V_277 )
{
int V_219 , V_221 , V_75 = - 1 ;
V_219 = F_45 ( V_276 , V_113 ) ;
if ( V_219 < 0 )
return - 1 ;
V_221 = F_45 ( V_277 , V_113 ) ;
if ( V_221 < 0 )
goto V_281;
V_75 = F_129 ( V_219 , V_221 ) ;
F_49 ( V_221 ) ;
V_281:
F_49 ( V_219 ) ;
return V_75 ;
}
static int F_132 ( const char * V_274 , const char * V_275 ,
const char * V_35 )
{
char V_276 [ V_182 ] ;
char V_277 [ V_182 ] ;
F_114 ( V_276 , V_182 , L_36 , V_274 , V_35 ) ;
F_114 ( V_277 , V_182 , L_36 , V_275 , V_35 ) ;
return F_131 ( V_276 , V_277 ) ;
}
int F_133 ( const char * V_274 , const char * V_275 )
{
struct V_228 V_228 ;
struct V_228 V_282 ;
T_3 V_237 = 2 ;
int V_36 = 0 , V_75 = - 1 ;
T_22 V_179 = V_226 , V_110 , V_283 = 0 ;
struct V_258 V_259 = { . V_263 = 0 , } ;
char V_284 [ V_182 ] ;
char V_285 [ V_182 ] ;
if ( F_126 ( V_274 , V_275 , L_37 ) )
return - 1 ;
if ( F_126 ( V_274 , V_275 , L_38 ) )
goto V_286;
F_114 ( V_284 , V_182 , L_39 , V_274 ) ;
F_114 ( V_285 , V_182 , L_39 , V_275 ) ;
if ( F_98 ( & V_228 , V_284 ) )
goto V_287;
if ( F_123 ( & V_259 , V_274 , V_228 . V_4 ) )
goto V_288;
if ( F_99 ( & V_282 , V_285 , V_228 . V_230 , false ) )
goto V_288;
if ( ! V_259 . V_273 . V_28 )
V_237 -= 1 ;
if ( F_104 ( & V_228 , & V_282 , V_237 ) )
goto V_289;
if ( F_107 ( & V_282 , V_36 ++ , V_179 , V_259 . V_272 . V_28 ,
V_259 . V_272 . V_223 ) )
goto V_289;
if ( V_259 . V_273 . V_28 ) {
V_283 = V_179 + V_259 . V_272 . V_223 ;
if ( F_107 ( & V_282 , V_36 , V_283 ,
V_259 . V_273 . V_28 , V_259 . V_273 . V_223 ) )
goto V_289;
}
V_110 = F_109 ( & V_282 ) ;
if ( V_110 < 0 || V_110 > V_179 )
goto V_289;
if ( F_95 ( V_228 . V_112 , V_259 . V_272 . V_179 , V_282 . V_112 , V_179 ,
V_259 . V_272 . V_223 ) )
goto V_289;
if ( V_283 && F_95 ( V_228 . V_112 , V_259 . V_273 . V_179 ,
V_282 . V_112 , V_283 ,
V_259 . V_273 . V_223 ) )
goto V_289;
if ( F_132 ( V_274 , V_275 , L_38 ) )
goto V_289;
if ( F_132 ( V_274 , V_275 , L_37 ) )
goto V_289;
V_75 = 0 ;
V_289:
F_103 ( & V_282 ) ;
if ( V_75 )
F_102 ( V_285 ) ;
V_288:
F_103 ( & V_228 ) ;
V_287:
if ( V_75 )
F_128 ( V_275 , L_38 ) ;
V_286:
if ( V_75 )
F_128 ( V_275 , L_37 ) ;
return V_75 ;
}
int F_134 ( struct V_290 * V_291 )
{
struct V_228 V_228 ;
struct V_228 V_282 ;
T_3 V_237 = 1 ;
int V_36 = 0 , V_75 = - 1 ;
T_22 V_179 = V_226 , V_110 ;
if ( F_98 ( & V_228 , V_291 -> V_284 ) )
return - 1 ;
strcpy ( V_291 -> V_285 , V_292 ) ;
if ( F_99 ( & V_282 , V_291 -> V_285 , V_228 . V_230 , true ) )
goto V_288;
if ( F_104 ( & V_228 , & V_282 , V_237 ) )
goto V_289;
if ( F_107 ( & V_282 , V_36 , V_179 , V_291 -> V_28 , V_291 -> V_223 ) )
goto V_289;
V_110 = F_109 ( & V_282 ) ;
if ( V_110 < 0 || V_110 > V_179 )
goto V_289;
if ( F_95 ( V_228 . V_112 , V_291 -> V_293 , V_282 . V_112 , V_179 , V_291 -> V_223 ) )
goto V_289;
V_75 = 0 ;
V_289:
F_103 ( & V_282 ) ;
if ( V_75 )
F_102 ( V_291 -> V_285 ) ;
V_288:
F_103 ( & V_228 ) ;
return V_75 ;
}
void F_135 ( struct V_290 * V_291 )
{
F_102 ( V_291 -> V_285 ) ;
}
static int F_136 ( T_2 * * V_4 , const char * V_97 , T_3 V_223 ,
struct V_294 * V_295 )
{
const char * V_296 , * V_35 , * args ;
struct V_297 * V_298 = NULL ;
T_4 V_7 ;
T_9 V_299 = 0 ;
T_8 V_25 ;
int V_280 = - V_128 ;
union {
T_23 V_300 [ V_301 ] ;
T_24 V_302 [ V_301 ] ;
} V_225 ;
T_7 V_5 = {
. V_24 = & V_225 , . V_303 = V_304 , . V_305 = V_306 ,
. V_80 = F_137 ( ( * V_4 ) , V_304 , V_301 , V_306 ) ,
. V_307 = 0 , . V_308 = 0
} ;
T_7 V_309 = {
. V_24 = ( void * ) V_97 , . V_303 = V_304 ,
. V_305 = V_306 , . V_80 = V_5 . V_80 , . V_307 = 0 ,
. V_308 = 0
} ;
V_298 = (struct V_297 * ) calloc ( 1 , sizeof( struct V_297 ) ) ;
if ( ! V_298 ) {
V_280 = - V_310 ;
goto V_311;
}
F_138 ( & V_298 -> V_312 ) ;
if ( V_223 < V_5 . V_80 + 3 )
goto V_313;
if ( F_139 ( * V_4 , & V_5 , & V_309 ,
F_140 ( * V_4 , NULL ) [ V_140 ] ) == NULL ) {
F_6 ( L_40 , F_141 ( - 1 ) ) ;
goto V_313;
}
V_296 = V_97 + V_5 . V_80 ;
V_35 = ( const char * ) memchr ( V_296 , '\0' , V_97 + V_223 - V_296 ) ;
if ( V_35 ++ == NULL )
goto V_313;
V_298 -> V_296 = F_64 ( V_296 ) ;
if ( ! V_298 -> V_296 ) {
V_280 = - V_310 ;
goto V_313;
}
V_298 -> V_35 = F_64 ( V_35 ) ;
if ( ! V_298 -> V_35 ) {
V_280 = - V_310 ;
goto V_314;
}
args = memchr ( V_35 , '\0' , V_97 + V_223 - V_35 ) ;
if ( args == NULL || V_97 + V_223 - args < 2 ||
args [ 1 ] == ':' || args [ 1 ] == '\0' )
V_298 -> args = NULL ;
else {
V_298 -> args = F_64 ( ++ args ) ;
if ( ! V_298 -> args ) {
V_280 = - V_310 ;
goto V_315;
}
}
if ( F_63 ( * V_4 ) == V_246 ) {
memcpy ( & V_298 -> V_28 , & V_225 , 3 * sizeof( T_24 ) ) ;
V_298 -> V_316 = true ;
} else {
memcpy ( & V_298 -> V_28 , & V_225 , 3 * sizeof( T_23 ) ) ;
V_298 -> V_316 = false ;
}
if ( ! F_4 ( * V_4 , & V_7 ) ) {
F_38 ( L_41 , V_9 ) ;
V_280 = - V_317 ;
goto V_318;
}
if ( F_21 ( * V_4 , & V_7 , & V_25 , V_319 , NULL ) ) {
V_299 = V_25 . V_82 ;
if ( V_299 ) {
if ( V_298 -> V_316 )
V_298 -> V_28 . V_302 [ 0 ] = V_298 -> V_28 . V_302 [ 0 ] + V_299 -
V_298 -> V_28 . V_302 [ 1 ] ;
else
V_298 -> V_28 . V_300 [ 0 ] = V_298 -> V_28 . V_300 [ 0 ] + V_299 -
V_298 -> V_28 . V_300 [ 1 ] ;
}
}
F_142 ( & V_298 -> V_312 , V_295 ) ;
return 0 ;
V_318:
free ( V_298 -> args ) ;
V_315:
free ( V_298 -> V_35 ) ;
V_314:
free ( V_298 -> V_296 ) ;
V_313:
free ( V_298 ) ;
V_311:
return V_280 ;
}
static int F_143 ( T_2 * V_4 , struct V_294 * V_295 )
{
T_4 V_7 ;
T_10 * V_320 = NULL ;
T_7 * V_97 ;
T_8 V_25 ;
T_3 V_321 , V_322 ;
T_16 V_103 ;
T_3 V_323 , V_324 , V_179 ;
int V_280 = 0 ;
if ( F_4 ( V_4 , & V_7 ) == NULL ) {
V_280 = - V_317 ;
goto V_325;
}
if ( F_5 ( V_4 , & V_321 ) != 0 ) {
V_280 = - V_317 ;
goto V_325;
}
V_320 = F_21 ( V_4 , & V_7 , & V_25 , V_326 , NULL ) ;
if ( ! V_320 ) {
V_280 = - V_327 ;
goto V_325;
}
if ( ( V_25 . V_86 != V_328 ) || ( V_25 . V_329 & V_330 ) ) {
V_280 = - V_327 ;
goto V_325;
}
V_97 = F_31 ( V_320 , NULL ) ;
for ( V_179 = 0 ; ( V_322 = F_144 ( V_97 , V_179 , & V_103 , & V_323 ,
& V_324 ) ) > 0 ; V_179 = V_322 ) {
if ( V_103 . V_105 == sizeof( V_331 ) &&
! memcmp ( V_97 -> V_24 + V_323 , V_331 ,
sizeof( V_331 ) ) ) {
if ( V_103 . V_108 != V_332 )
goto V_325;
V_280 = F_136 ( & V_4 , ( ( V_97 -> V_24 ) + V_324 ) ,
V_103 . V_107 , V_295 ) ;
if ( V_280 < 0 )
goto V_325;
}
}
if ( F_145 ( V_295 ) )
V_280 = - V_327 ;
V_325:
return V_280 ;
}
int F_146 ( struct V_294 * V_333 , const char * V_334 )
{
T_2 * V_4 ;
int V_112 , V_280 ;
V_112 = F_45 ( V_334 , V_113 ) ;
if ( V_112 < 0 )
return - V_317 ;
V_4 = F_46 ( V_112 , V_114 , NULL ) ;
if ( ! V_4 ) {
V_280 = - V_317 ;
goto V_115;
}
V_280 = F_143 ( V_4 , V_333 ) ;
F_48 ( V_4 ) ;
V_115:
F_49 ( V_112 ) ;
return V_280 ;
}
int F_147 ( struct V_294 * V_295 )
{
struct V_297 * V_298 , * V_89 ;
int V_335 = 0 ;
F_148 (pos, tmp, sdt_notes, note_list) {
F_149 ( & V_89 -> V_312 ) ;
free ( V_89 -> V_35 ) ;
free ( V_89 -> V_296 ) ;
free ( V_89 ) ;
V_335 ++ ;
}
return V_335 ;
}
int F_150 ( struct V_294 * V_175 )
{
struct V_297 * V_336 ;
int V_237 = 0 ;
F_151 (sdt_ptr, start, note_list)
V_237 ++ ;
return V_237 ;
}
void F_152 ( void )
{
F_153 ( V_306 ) ;
}
