static int F_1 ( T_1 * V_1 , T_2 * V_2 )
{
T_3 V_3 ;
T_3 * V_4 ;
V_4 = F_2 ( V_1 , & V_3 ) ;
if ( ! V_4 )
return - 1 ;
* V_2 = V_4 -> V_5 ;
return 0 ;
}
static inline T_4 F_3 ( const T_5 * V_6 )
{
return F_4 ( V_6 -> V_7 ) ;
}
static inline int F_5 ( const T_5 * V_6 )
{
return ( F_3 ( V_6 ) == V_8 ||
F_3 ( V_6 ) == V_9 ) &&
V_6 -> V_10 != 0 &&
V_6 -> V_11 != V_12 ;
}
static inline bool F_6 ( const T_5 * V_6 )
{
return F_3 ( V_6 ) == V_13 &&
V_6 -> V_10 != 0 &&
V_6 -> V_11 != V_12 ;
}
static inline int F_7 ( const T_5 * V_6 )
{
return F_3 ( V_6 ) == V_14 &&
V_6 -> V_10 != 0 &&
V_6 -> V_11 != V_12 &&
V_6 -> V_11 != V_15 ;
}
static bool F_8 ( T_5 * V_6 , enum V_16 type )
{
switch ( type ) {
case V_17 :
return F_5 ( V_6 ) ;
case V_18 :
return F_6 ( V_6 ) ;
default:
return false ;
}
}
static inline const char * F_9 ( const T_5 * V_6 ,
const T_6 * V_19 )
{
return V_19 -> V_20 + V_6 -> V_10 ;
}
static inline const char * F_10 ( const T_7 * V_21 ,
const T_6 * V_22 )
{
return V_22 -> V_20 + V_21 -> V_23 ;
}
static inline int F_11 ( const T_7 * V_21 ,
const T_6 * V_22 )
{
return strstr ( F_10 ( V_21 , V_22 ) , L_1 ) != NULL ;
}
static inline bool F_12 ( const T_7 * V_21 ,
const T_6 * V_22 )
{
return strstr ( F_10 ( V_21 , V_22 ) , L_2 ) != NULL ;
}
static bool F_13 ( T_7 * V_21 , T_6 * V_22 ,
enum V_16 type )
{
switch ( type ) {
case V_17 :
return F_11 ( V_21 , V_22 ) ;
case V_18 :
return F_12 ( V_21 , V_22 ) ;
default:
return false ;
}
}
static T_2 F_14 ( T_1 * V_1 , T_8 V_24 )
{
T_9 * V_25 = NULL ;
T_7 V_21 ;
T_2 V_26 = 1 ;
while ( ( V_25 = F_15 ( V_1 , V_25 ) ) != NULL ) {
F_16 ( V_25 , & V_21 ) ;
if ( ( V_24 >= V_21 . V_27 ) &&
( V_24 < ( V_21 . V_27 + V_21 . V_28 ) ) )
return V_26 ;
++ V_26 ;
}
return - 1 ;
}
T_9 * F_17 ( T_1 * V_1 , T_3 * V_29 ,
T_7 * V_30 , const char * V_31 , T_2 * V_32 )
{
T_9 * V_25 = NULL ;
T_2 V_26 = 1 ;
if ( ! F_18 ( F_19 ( V_1 , V_29 -> V_33 ) , NULL ) )
return NULL ;
while ( ( V_25 = F_15 ( V_1 , V_25 ) ) != NULL ) {
char * V_34 ;
F_16 ( V_25 , V_30 ) ;
V_34 = F_20 ( V_1 , V_29 -> V_33 , V_30 -> V_23 ) ;
if ( V_34 && ! strcmp ( V_31 , V_34 ) ) {
if ( V_32 )
* V_32 = V_26 ;
return V_25 ;
}
++ V_26 ;
}
return NULL ;
}
int F_21 ( struct V_35 * V_35 , struct V_36 * V_37 , struct V_38 * V_38 ,
T_10 V_39 )
{
T_11 V_40 , V_32 ;
T_5 V_6 ;
T_12 V_41 ;
T_7 V_42 ;
struct V_43 * V_44 ;
T_7 V_45 , V_46 ;
T_6 * V_47 , * V_48 , * V_19 ;
T_9 * V_49 , * V_50 , * V_51 ;
T_2 V_52 ;
T_3 V_4 ;
char V_53 [ 1024 ] ;
T_1 * V_1 ;
int V_54 = 0 , V_55 , V_56 = 0 ;
if ( ! V_37 -> V_57 )
return 0 ;
V_1 = V_37 -> V_1 ;
V_4 = V_37 -> V_4 ;
V_51 = V_37 -> V_57 ;
V_46 = V_37 -> V_58 ;
V_52 = V_37 -> V_52 ;
if ( V_51 == NULL )
goto V_59;
V_49 = F_17 ( V_1 , & V_4 , & V_45 ,
L_3 , NULL ) ;
if ( V_49 == NULL ) {
V_49 = F_17 ( V_1 , & V_4 , & V_45 ,
L_4 , NULL ) ;
if ( V_49 == NULL )
goto V_59;
}
V_56 = - 1 ;
if ( V_45 . V_60 != V_52 )
goto V_59;
if ( F_17 ( V_1 , & V_4 , & V_42 , L_5 , NULL ) == NULL )
goto V_59;
V_47 = F_22 ( V_49 , NULL ) ;
if ( V_47 == NULL )
goto V_59;
V_48 = F_22 ( V_51 , NULL ) ;
if ( V_48 == NULL )
goto V_59;
V_50 = F_19 ( V_1 , V_46 . V_60 ) ;
if ( V_50 == NULL )
goto V_59;
V_19 = F_22 ( V_50 , NULL ) ;
if ( V_19 == NULL )
goto V_59;
if ( V_19 -> V_61 == 0 )
goto V_59;
V_40 = V_45 . V_28 / V_45 . V_62 ;
V_41 = V_42 . V_63 ;
if ( V_45 . V_64 == V_65 ) {
T_13 V_66 , * V_67 ;
F_23 (reldata, pos, pos_mem, idx,
nr_rel_entries) {
V_55 = F_24 ( V_67 -> V_68 ) ;
V_41 += V_42 . V_62 ;
F_25 ( V_48 , V_55 , & V_6 ) ;
snprintf ( V_53 , sizeof( V_53 ) ,
L_6 , F_9 ( & V_6 , V_19 ) ) ;
V_44 = F_26 ( V_41 , V_42 . V_62 ,
V_69 , V_53 ) ;
if ( ! V_44 )
goto V_59;
if ( V_39 && V_39 ( V_38 , V_44 ) )
F_27 ( V_44 ) ;
else {
F_28 ( & V_35 -> V_70 [ V_38 -> type ] , V_44 ) ;
++ V_54 ;
}
}
} else if ( V_45 . V_64 == V_71 ) {
T_14 V_66 , * V_67 ;
F_29 (reldata, pos, pos_mem, idx,
nr_rel_entries) {
V_55 = F_24 ( V_67 -> V_68 ) ;
V_41 += V_42 . V_62 ;
F_25 ( V_48 , V_55 , & V_6 ) ;
snprintf ( V_53 , sizeof( V_53 ) ,
L_6 , F_9 ( & V_6 , V_19 ) ) ;
V_44 = F_26 ( V_41 , V_42 . V_62 ,
V_69 , V_53 ) ;
if ( ! V_44 )
goto V_59;
if ( V_39 && V_39 ( V_38 , V_44 ) )
F_27 ( V_44 ) ;
else {
F_28 ( & V_35 -> V_70 [ V_38 -> type ] , V_44 ) ;
++ V_54 ;
}
}
}
V_56 = 0 ;
V_59:
if ( V_56 == 0 )
return V_54 ;
F_30 ( L_7 ,
V_72 , V_35 -> V_73 ) ;
return 0 ;
}
static int F_31 ( T_1 * V_1 , void * V_74 , T_2 V_75 )
{
int V_56 = - 1 ;
T_3 V_4 ;
T_7 V_21 ;
T_6 * V_76 ;
T_9 * V_25 ;
T_15 V_77 ;
void * V_78 ;
if ( V_75 < V_79 )
goto V_80;
V_77 = F_32 ( V_1 ) ;
if ( V_77 != V_81 )
goto V_80;
if ( F_2 ( V_1 , & V_4 ) == NULL ) {
F_33 ( L_8 , V_72 ) ;
goto V_80;
}
do {
V_25 = F_17 ( V_1 , & V_4 , & V_21 ,
L_9 , NULL ) ;
if ( V_25 )
break;
V_25 = F_17 ( V_1 , & V_4 , & V_21 ,
L_10 , NULL ) ;
if ( V_25 )
break;
V_25 = F_17 ( V_1 , & V_4 , & V_21 ,
L_11 , NULL ) ;
if ( V_25 )
break;
return V_56 ;
} while ( 0 );
V_76 = F_22 ( V_25 , NULL ) ;
if ( V_76 == NULL )
goto V_80;
V_78 = V_76 -> V_20 ;
while ( V_78 < ( V_76 -> V_20 + V_76 -> V_61 ) ) {
T_16 * V_82 = V_78 ;
T_2 V_83 = F_34 ( V_82 -> V_84 ) ,
V_85 = F_34 ( V_82 -> V_86 ) ;
const char * V_31 ;
V_78 += sizeof( * V_82 ) ;
V_31 = V_78 ;
V_78 += V_83 ;
if ( V_82 -> V_87 == V_88 &&
V_82 -> V_84 == sizeof( L_12 ) ) {
if ( memcmp ( V_31 , L_12 , sizeof( L_12 ) ) == 0 ) {
T_2 V_89 = F_35 ( V_75 , V_85 ) ;
memcpy ( V_74 , V_78 , V_89 ) ;
memset ( V_74 + V_89 , 0 , V_75 - V_89 ) ;
V_56 = V_85 ;
break;
}
}
V_78 += V_85 ;
}
V_80:
return V_56 ;
}
int F_36 ( const char * V_90 , void * V_74 , T_2 V_75 )
{
int V_91 , V_56 = - 1 ;
T_1 * V_1 ;
if ( V_75 < V_79 )
goto V_80;
V_91 = F_37 ( V_90 , V_92 ) ;
if ( V_91 < 0 )
goto V_80;
V_1 = F_38 ( V_91 , V_93 , NULL ) ;
if ( V_1 == NULL ) {
F_39 ( L_13 , V_72 , V_90 ) ;
goto V_94;
}
V_56 = F_31 ( V_1 , V_74 , V_75 ) ;
F_40 ( V_1 ) ;
V_94:
F_41 ( V_91 ) ;
V_80:
return V_56 ;
}
int F_42 ( const char * V_90 , void * V_95 , T_2 V_75 )
{
int V_91 , V_56 = - 1 ;
if ( V_75 < V_79 )
goto V_80;
V_91 = F_37 ( V_90 , V_92 ) ;
if ( V_91 < 0 )
goto V_80;
while ( 1 ) {
char V_74 [ V_96 ] ;
T_16 V_82 ;
T_2 V_83 , V_85 ;
if ( F_43 ( V_91 , & V_82 , sizeof( V_82 ) ) != sizeof( V_82 ) )
break;
V_83 = F_34 ( V_82 . V_84 ) ;
V_85 = F_34 ( V_82 . V_86 ) ;
if ( V_82 . V_87 == V_88 &&
V_82 . V_84 == sizeof( L_12 ) ) {
if ( F_43 ( V_91 , V_74 , V_83 ) != ( V_97 ) V_83 )
break;
if ( memcmp ( V_74 , L_12 , sizeof( L_12 ) ) == 0 ) {
T_2 V_89 = F_35 ( V_85 , V_75 ) ;
if ( F_43 ( V_91 , V_95 , V_89 ) == ( V_97 ) V_89 ) {
memset ( V_95 + V_89 , 0 , V_75 - V_89 ) ;
V_56 = 0 ;
break;
}
} else if ( F_43 ( V_91 , V_74 , V_85 ) != ( V_97 ) V_85 )
break;
} else {
int V_98 = V_83 + V_85 ;
if ( F_43 ( V_91 , V_74 , V_98 ) != V_98 )
break;
}
}
F_41 ( V_91 ) ;
V_80:
return V_56 ;
}
int F_44 ( const char * V_90 , char * V_99 ,
T_2 V_75 )
{
int V_91 , V_56 = - 1 ;
T_1 * V_1 ;
T_3 V_4 ;
T_7 V_21 ;
T_6 * V_76 ;
T_9 * V_25 ;
T_15 V_77 ;
V_91 = F_37 ( V_90 , V_92 ) ;
if ( V_91 < 0 )
goto V_80;
V_1 = F_38 ( V_91 , V_93 , NULL ) ;
if ( V_1 == NULL ) {
F_39 ( L_13 , V_72 , V_90 ) ;
goto V_94;
}
V_77 = F_32 ( V_1 ) ;
if ( V_77 != V_81 )
goto V_59;
if ( F_2 ( V_1 , & V_4 ) == NULL ) {
F_33 ( L_8 , V_72 ) ;
goto V_59;
}
V_25 = F_17 ( V_1 , & V_4 , & V_21 ,
L_14 , NULL ) ;
if ( V_25 == NULL )
goto V_59;
V_76 = F_22 ( V_25 , NULL ) ;
if ( V_76 == NULL )
goto V_59;
strncpy ( V_99 , V_76 -> V_20 , V_75 ) ;
V_56 = 0 ;
V_59:
F_40 ( V_1 ) ;
V_94:
F_41 ( V_91 ) ;
V_80:
return V_56 ;
}
static int F_45 ( struct V_35 * V_35 , unsigned char V_100 )
{
static unsigned int const V_101 = 1 ;
V_35 -> V_102 = V_103 ;
switch ( V_100 ) {
case V_104 :
if ( * ( unsigned char const * ) & V_101 != 1 )
V_35 -> V_102 = V_105 ;
break;
case V_106 :
if ( * ( unsigned char const * ) & V_101 != 0 )
V_35 -> V_102 = V_105 ;
break;
default:
F_33 ( L_15 , V_100 ) ;
return - V_107 ;
}
return 0 ;
}
bool F_46 ( struct V_36 * V_37 )
{
return V_37 -> V_57 || V_37 -> V_108 ;
}
bool F_47 ( struct V_36 * V_37 )
{
return V_37 -> V_109 != NULL ;
}
void F_48 ( struct V_36 * V_37 )
{
F_49 ( & V_37 -> V_31 ) ;
F_40 ( V_37 -> V_1 ) ;
F_41 ( V_37 -> V_91 ) ;
}
int F_50 ( struct V_36 * V_37 , struct V_35 * V_35 , const char * V_31 ,
enum V_110 type )
{
int V_56 = - 1 ;
T_3 V_4 ;
T_1 * V_1 ;
int V_91 ;
V_91 = F_37 ( V_31 , V_92 ) ;
if ( V_91 < 0 )
return - 1 ;
V_1 = F_38 ( V_91 , V_93 , NULL ) ;
if ( V_1 == NULL ) {
F_30 ( L_13 , V_72 , V_31 ) ;
goto V_94;
}
if ( F_2 ( V_1 , & V_4 ) == NULL ) {
F_30 ( L_8 , V_72 ) ;
goto V_59;
}
if ( F_45 ( V_35 , V_4 . V_111 [ V_112 ] ) )
goto V_59;
if ( V_35 -> V_113 ) {
T_17 V_95 [ V_79 ] ;
if ( F_31 ( V_1 , V_95 , V_79 ) < 0 )
goto V_59;
if ( ! F_51 ( V_35 , V_95 ) )
goto V_59;
}
V_37 -> V_114 = ( F_52 ( V_1 ) == V_115 ) ;
V_37 -> V_109 = F_17 ( V_1 , & V_4 , & V_37 -> V_116 , L_16 ,
NULL ) ;
if ( V_37 -> V_116 . V_64 != V_117 )
V_37 -> V_109 = NULL ;
V_37 -> V_52 = 0 ;
V_37 -> V_57 = F_17 ( V_1 , & V_4 , & V_37 -> V_58 , L_17 ,
& V_37 -> V_52 ) ;
if ( V_37 -> V_58 . V_64 != V_118 )
V_37 -> V_57 = NULL ;
V_37 -> V_119 = 0 ;
V_37 -> V_108 = F_17 ( V_1 , & V_4 , & V_37 -> V_120 , L_18 ,
& V_37 -> V_119 ) ;
if ( V_37 -> V_120 . V_64 != V_121 )
V_37 -> V_108 = NULL ;
if ( V_35 -> V_122 == V_123 ) {
T_7 V_21 ;
V_37 -> V_124 = ( V_4 . V_125 == V_126 ||
V_4 . V_125 == V_127 ||
F_53 ( V_35 ) ||
F_17 ( V_1 , & V_4 , & V_21 ,
L_19 ,
NULL ) != NULL ) ;
} else {
V_37 -> V_124 = V_4 . V_125 == V_126 ||
V_4 . V_125 == V_127 ;
}
V_37 -> V_31 = F_54 ( V_31 ) ;
if ( ! V_37 -> V_31 )
goto V_59;
V_37 -> V_1 = V_1 ;
V_37 -> V_91 = V_91 ;
V_37 -> V_4 = V_4 ;
V_37 -> type = type ;
return 0 ;
V_59:
F_40 ( V_1 ) ;
V_94:
F_41 ( V_91 ) ;
return V_56 ;
}
static bool F_55 ( struct V_128 * V_128 )
{
return V_128 && V_128 -> V_129 && V_128 -> V_129 -> V_31 &&
! V_128 -> V_129 -> V_130 ;
}
static T_12 F_56 ( struct V_128 * V_128 )
{
if ( V_128 && V_128 -> V_129 &&
V_128 -> V_129 -> V_130 )
return V_128 -> V_129 -> V_24 -
V_128 -> V_129 -> V_130 ;
return 0 ;
}
static bool F_57 ( bool V_131 )
{
return V_131 ? V_132 . V_133 : V_132 . V_134 ;
}
int F_58 ( struct V_35 * V_35 , struct V_38 * V_38 ,
struct V_36 * V_135 , struct V_36 * V_136 ,
T_10 V_39 , int V_137 )
{
struct V_128 * V_128 = V_35 -> V_122 ? F_59 ( V_38 ) : NULL ;
struct V_38 * V_138 = V_38 ;
struct V_35 * V_139 = V_35 ;
T_6 * V_19 , * V_22 ;
T_11 V_140 ;
int V_56 = - 1 ;
T_11 V_32 ;
T_3 V_4 ;
T_7 V_21 ;
T_6 * V_48 , * V_141 = NULL ;
T_5 V_6 ;
T_9 * V_25 , * V_142 ;
T_1 * V_1 ;
int V_54 = 0 ;
bool V_143 = false , V_144 = false ;
V_35 -> V_145 = V_135 -> type ;
V_35 -> V_114 = V_135 -> V_114 ;
V_35 -> V_146 = V_135 -> V_4 . V_125 == V_127 ;
if ( V_137 && V_135 -> V_109 )
F_60 ( & V_35 -> V_70 [ V_38 -> type ] ) ;
if ( ! V_135 -> V_109 ) {
if ( V_35 -> V_122 )
goto V_59;
V_135 -> V_109 = V_135 -> V_57 ;
V_135 -> V_116 = V_135 -> V_58 ;
}
V_1 = V_135 -> V_1 ;
V_4 = V_135 -> V_4 ;
V_25 = V_135 -> V_109 ;
V_21 = V_135 -> V_116 ;
if ( V_136 -> V_108 )
V_141 = F_18 ( V_136 -> V_108 , NULL ) ;
V_48 = F_22 ( V_25 , NULL ) ;
if ( V_48 == NULL )
goto V_59;
V_25 = F_19 ( V_1 , V_21 . V_60 ) ;
if ( V_25 == NULL )
goto V_59;
V_19 = F_22 ( V_25 , NULL ) ;
if ( V_19 == NULL )
goto V_59;
V_142 = F_19 ( V_136 -> V_1 , V_136 -> V_4 . V_33 ) ;
if ( V_142 == NULL )
goto V_59;
V_22 = F_22 ( V_142 , NULL ) ;
if ( V_22 == NULL )
goto V_59;
V_140 = V_21 . V_28 / V_21 . V_62 ;
memset ( & V_6 , 0 , sizeof( V_6 ) ) ;
if ( F_55 ( V_128 ) ) {
F_61 (syms, nr_syms, idx, sym) {
const char * V_147 = F_9 ( & V_6 , V_19 ) ;
if ( strcmp ( V_147 , V_128 -> V_129 -> V_31 ) )
continue;
V_128 -> V_129 -> V_130 = V_6 . V_148 ;
V_38 -> V_149 = V_128 -> V_129 -> V_24 -
V_128 -> V_129 -> V_130 ;
break;
}
}
V_35 -> V_124 = V_136 -> V_124 || F_56 ( V_128 ) ;
if ( V_38 -> type == V_17 && ( V_35 -> V_122 || V_137 ) ) {
V_143 = true ;
V_144 = V_35 -> V_124 ;
}
F_61 (syms, nr_syms, idx, sym) {
struct V_43 * V_44 ;
const char * V_147 = F_9 ( & V_6 , V_19 ) ;
char * V_150 = NULL ;
int V_151 = F_7 ( & V_6 ) ;
const char * V_152 ;
bool V_153 = false ;
if ( ! V_151 && ! F_8 ( & V_6 , V_38 -> type ) )
continue;
if ( V_4 . V_154 == V_155 ) {
if ( ! strcmp ( V_147 , L_20 ) ||
! strcmp ( V_147 , L_21 ) ||
! strcmp ( V_147 , L_22 ) )
continue;
}
if ( V_136 -> V_108 && V_6 . V_11 == V_136 -> V_119 ) {
T_18 V_156 = V_6 . V_148 - V_135 -> V_120 . V_27 ;
T_12 * V_157 = V_141 -> V_20 + V_156 ;
V_6 . V_148 = F_62 ( V_35 , T_12 , * V_157 ) ;
V_6 . V_11 = F_14 ( V_136 -> V_1 ,
V_6 . V_148 ) ;
V_153 = true ;
}
if ( V_6 . V_11 == V_15 )
continue;
V_25 = F_19 ( V_136 -> V_1 , V_6 . V_11 ) ;
if ( ! V_25 )
goto V_59;
F_16 ( V_25 , & V_21 ) ;
if ( V_151 && ! F_13 ( & V_21 , V_22 , V_38 -> type ) )
continue;
V_152 = F_10 ( & V_21 , V_22 ) ;
if ( ( V_4 . V_154 == V_155 ) &&
( V_38 -> type == V_17 ) &&
( V_6 . V_148 & 1 ) )
-- V_6 . V_148 ;
if ( V_35 -> V_122 || V_137 ) {
char V_158 [ V_159 ] ;
if ( V_144 )
V_6 . V_148 -= V_21 . V_27 - V_21 . V_63 ;
if ( strcmp ( V_152 ,
( V_139 -> V_160 +
V_35 -> V_161 ) ) == 0 )
goto V_162;
if ( strcmp ( V_152 , L_23 ) == 0 ) {
if ( V_143 && V_35 -> V_122 ) {
V_143 = false ;
V_38 -> V_163 = V_21 . V_27 +
F_56 ( V_128 ) ;
V_38 -> V_164 = V_38 -> V_163 + V_21 . V_28 ;
V_38 -> V_165 = V_21 . V_63 ;
V_38 -> V_166 = V_167 ;
V_38 -> V_168 = V_169 ;
F_63 ( V_128 -> V_170 , V_38 ) ;
F_64 ( V_128 -> V_170 , V_38 ) ;
}
if ( V_143 && V_137 ) {
V_143 = false ;
V_38 -> V_165 = V_21 . V_63 ;
}
V_138 = V_38 ;
V_139 = V_35 ;
goto V_162;
}
if ( ! V_128 )
goto V_162;
snprintf ( V_158 , sizeof( V_158 ) ,
L_24 , V_35 -> V_160 , V_152 ) ;
V_138 = F_65 ( V_128 -> V_170 , V_38 -> type , V_158 ) ;
if ( V_138 == NULL ) {
T_12 V_163 = V_6 . V_148 ;
if ( V_137 )
V_163 += V_38 -> V_163 + V_21 . V_63 ;
V_139 = F_66 ( V_158 ) ;
if ( V_139 == NULL )
goto V_59;
V_139 -> V_122 = V_35 -> V_122 ;
V_139 -> V_73 = V_35 -> V_73 ;
V_139 -> V_171 = V_35 -> V_171 ;
V_138 = F_67 ( V_163 , V_139 ,
V_38 -> type ) ;
if ( V_138 == NULL ) {
F_68 ( V_139 ) ;
goto V_59;
}
if ( V_144 ) {
V_138 -> V_163 = V_21 . V_27 +
F_56 ( V_128 ) ;
V_138 -> V_164 = V_138 -> V_163 +
V_21 . V_28 ;
V_138 -> V_165 = V_21 . V_63 ;
} else {
V_138 -> V_166 = V_172 ;
V_138 -> V_168 = V_172 ;
}
V_139 -> V_145 = V_35 -> V_145 ;
F_64 ( V_128 -> V_170 , V_138 ) ;
F_69 ( & V_38 -> V_173 -> V_174 -> V_175 ,
V_139 ) ;
F_70 ( V_139 , V_38 -> type ) ;
} else
V_139 = V_138 -> V_35 ;
goto V_162;
}
if ( ( V_153 && V_136 -> V_124 )
|| ( ! V_153 && V_135 -> V_124 ) ) {
F_71 ( L_25 V_176 L_26
L_27 V_176 L_28 V_176 L_29 , V_72 ,
( T_12 ) V_6 . V_148 , ( T_12 ) V_21 . V_27 ,
( T_12 ) V_21 . V_63 ) ;
V_6 . V_148 -= V_21 . V_27 - V_21 . V_63 ;
}
V_162:
if ( F_57 ( V_35 -> V_122 || V_137 ) ) {
int V_177 = V_178 ;
if ( V_179 )
V_177 = V_180 | V_181 ;
V_150 = F_72 ( NULL , V_147 , V_177 ) ;
if ( V_150 != NULL )
V_147 = V_150 ;
}
V_44 = F_26 ( V_6 . V_148 , V_6 . V_182 ,
F_73 ( V_6 . V_7 ) , V_147 ) ;
free ( V_150 ) ;
if ( ! V_44 )
goto V_59;
if ( V_39 && V_39 ( V_138 , V_44 ) )
F_27 ( V_44 ) ;
else {
F_28 ( & V_139 -> V_70 [ V_138 -> type ] , V_44 ) ;
V_54 ++ ;
}
}
if ( V_54 > 0 ) {
F_74 ( & V_35 -> V_70 [ V_38 -> type ] ) ;
F_75 ( & V_35 -> V_70 [ V_38 -> type ] ) ;
if ( V_128 ) {
F_76 ( V_128 -> V_170 , V_38 -> type ) ;
}
}
V_56 = V_54 ;
V_59:
return V_56 ;
}
static int F_77 ( T_1 * V_1 , bool V_183 , T_19 V_184 , void * V_76 )
{
T_20 V_185 ;
T_2 V_186 , V_187 ;
int V_56 ;
T_12 V_89 ;
if ( F_1 ( V_1 , & V_187 ) )
return - 1 ;
for ( V_186 = 0 ; V_186 < V_187 ; V_186 ++ ) {
if ( F_78 ( V_1 , V_186 , & V_185 ) == NULL )
return - 1 ;
if ( V_185 . V_188 != V_189 )
continue;
if ( V_183 ) {
if ( ! ( V_185 . V_190 & V_191 ) )
continue;
} else {
if ( ! ( V_185 . V_190 & V_192 ) )
continue;
}
V_89 = F_35 ( V_185 . V_193 , V_185 . V_194 ) ;
if ( ! V_89 )
continue;
V_56 = V_184 ( V_185 . V_195 , V_89 , V_185 . V_196 , V_76 ) ;
if ( V_56 )
return V_56 ;
}
return 0 ;
}
int F_79 ( int V_91 , bool V_183 , T_19 V_184 , void * V_76 ,
bool * V_114 )
{
int V_56 ;
T_1 * V_1 ;
V_1 = F_38 ( V_91 , V_93 , NULL ) ;
if ( V_1 == NULL )
return - 1 ;
if ( V_114 )
* V_114 = ( F_52 ( V_1 ) == V_115 ) ;
V_56 = F_77 ( V_1 , V_183 , V_184 , V_76 ) ;
F_40 ( V_1 ) ;
return V_56 ;
}
enum V_197 F_80 ( int V_91 )
{
enum V_197 V_197 = V_198 ;
T_3 V_4 ;
T_15 V_77 ;
T_1 * V_1 ;
V_1 = F_38 ( V_91 , V_93 , NULL ) ;
if ( V_1 == NULL )
goto V_80;
V_77 = F_32 ( V_1 ) ;
if ( V_77 != V_81 )
goto V_199;
if ( F_52 ( V_1 ) == V_115 ) {
V_197 = V_200 ;
goto V_199;
}
if ( F_2 ( V_1 , & V_4 ) == NULL )
goto V_199;
if ( V_4 . V_154 == V_201 )
V_197 = V_202 ;
else
V_197 = V_203 ;
V_199:
F_40 ( V_1 ) ;
V_80:
return V_197 ;
}
static int F_81 ( int V_204 , T_21 V_205 , int V_206 , T_21 V_207 , T_12 V_208 )
{
V_97 V_209 ;
T_2 V_98 ;
int V_56 = - 1 ;
char * V_210 = malloc ( V_211 ) ;
if ( V_210 == NULL )
return - 1 ;
if ( F_82 ( V_206 , V_207 , V_212 ) != V_207 )
goto V_80;
if ( F_82 ( V_204 , V_205 , V_212 ) != V_205 )
goto V_80;
while ( V_208 ) {
V_98 = V_211 ;
if ( V_208 < V_98 )
V_98 = V_208 ;
V_209 = F_43 ( V_204 , V_210 , V_98 ) ;
if ( V_209 < 0 )
goto V_80;
if ( ! V_209 )
break;
V_98 = V_209 ;
V_209 = F_83 ( V_206 , V_210 , V_98 ) ;
if ( V_209 < 0 )
goto V_80;
if ( ( T_2 ) V_209 != V_98 )
goto V_80;
V_208 -= V_98 ;
}
V_56 = 0 ;
V_80:
free ( V_210 ) ;
return V_56 ;
}
static int F_84 ( struct V_213 * V_213 , const char * V_90 )
{
T_3 * V_4 ;
V_213 -> V_91 = F_37 ( V_90 , V_92 ) ;
if ( V_213 -> V_91 == - 1 )
return - 1 ;
V_213 -> V_1 = F_38 ( V_213 -> V_91 , V_214 , NULL ) ;
if ( ! V_213 -> V_1 )
goto V_94;
V_213 -> V_215 = F_52 ( V_213 -> V_1 ) ;
if ( V_213 -> V_215 == V_216 )
goto V_199;
V_4 = F_2 ( V_213 -> V_1 , & V_213 -> V_4 ) ;
if ( ! V_4 )
goto V_199;
return 0 ;
V_199:
F_40 ( V_213 -> V_1 ) ;
V_94:
F_41 ( V_213 -> V_91 ) ;
return - 1 ;
}
static int F_85 ( struct V_213 * V_213 , char * V_90 , int V_215 ,
bool V_217 )
{
T_3 * V_4 ;
V_213 -> V_215 = V_215 ;
if ( V_217 )
V_213 -> V_91 = F_86 ( V_90 ) ;
else
V_213 -> V_91 = F_37 ( V_90 , V_218 | V_219 | V_220 , 0400 ) ;
if ( V_213 -> V_91 == - 1 )
return - 1 ;
V_213 -> V_1 = F_38 ( V_213 -> V_91 , V_221 , NULL ) ;
if ( ! V_213 -> V_1 )
goto V_94;
if ( ! F_87 ( V_213 -> V_1 , V_215 ) )
goto V_199;
V_4 = F_2 ( V_213 -> V_1 , & V_213 -> V_4 ) ;
if ( ! V_4 )
goto V_199;
return 0 ;
V_199:
F_40 ( V_213 -> V_1 ) ;
V_94:
F_41 ( V_213 -> V_91 ) ;
F_88 ( V_90 ) ;
return - 1 ;
}
static void F_89 ( struct V_213 * V_213 )
{
F_40 ( V_213 -> V_1 ) ;
F_41 ( V_213 -> V_91 ) ;
}
static int F_90 ( struct V_213 * V_204 , struct V_213 * V_206 , T_2 V_222 )
{
T_3 * V_4 = & V_206 -> V_4 ;
T_3 * V_223 = & V_204 -> V_4 ;
memcpy ( V_4 -> V_111 , V_223 -> V_111 , V_224 ) ;
V_4 -> V_125 = V_223 -> V_125 ;
V_4 -> V_154 = V_223 -> V_154 ;
V_4 -> V_225 = V_223 -> V_225 ;
V_4 -> V_226 = 0 ;
V_4 -> V_227 = 0 ;
V_4 -> V_228 = V_223 -> V_228 ;
V_4 -> V_5 = V_222 ;
V_4 -> V_229 = 0 ;
V_4 -> V_230 = 0 ;
V_4 -> V_33 = 0 ;
if ( V_204 -> V_215 == V_231 ) {
V_4 -> V_232 = sizeof( V_233 ) ;
V_4 -> V_234 = sizeof( V_233 ) ;
V_4 -> V_235 = sizeof( V_236 ) ;
} else {
V_4 -> V_232 = sizeof( V_237 ) ;
V_4 -> V_234 = sizeof( V_237 ) ;
V_4 -> V_235 = sizeof( V_238 ) ;
}
if ( ! F_91 ( V_206 -> V_1 , V_4 ) )
return - 1 ;
if ( ! F_92 ( V_206 -> V_1 , V_222 ) )
return - 1 ;
return 0 ;
}
static int F_93 ( struct V_213 * V_213 , int V_32 , T_21 V_156 ,
T_12 V_24 , T_12 V_208 )
{
T_20 V_239 ;
T_20 * V_185 ;
V_185 = F_78 ( V_213 -> V_1 , V_32 , & V_239 ) ;
if ( ! V_185 )
return - 1 ;
V_185 -> V_188 = V_189 ;
V_185 -> V_190 = V_192 | V_240 | V_191 ;
V_185 -> V_196 = V_156 ;
V_185 -> V_195 = V_24 ;
V_185 -> V_241 = 0 ;
V_185 -> V_194 = V_208 ;
V_185 -> V_193 = V_208 ;
V_185 -> V_242 = V_211 ;
if ( ! F_94 ( V_213 -> V_1 , V_32 , V_185 ) )
return - 1 ;
return 0 ;
}
static T_21 F_95 ( struct V_213 * V_213 )
{
return F_96 ( V_213 -> V_1 , V_221 ) ;
}
static int F_97 ( void * V_243 , const char * V_31 , char type ,
T_12 V_163 )
{
struct V_244 * V_245 = V_243 ;
if ( ! F_98 ( type , V_17 ) )
return 0 ;
if ( strchr ( V_31 , '[' ) ) {
if ( V_163 > V_245 -> V_246 )
V_245 -> V_246 = V_163 ;
return 0 ;
}
if ( ! V_245 -> V_247 || V_163 < V_245 -> V_247 )
V_245 -> V_247 = V_163 ;
if ( ! V_245 -> V_248 || V_163 > V_245 -> V_248 )
V_245 -> V_248 = V_163 ;
if ( ! strcmp ( V_31 , L_30 ) ) {
V_245 -> V_249 = V_163 ;
return 0 ;
}
if ( ! strcmp ( V_31 , L_31 ) ) {
V_245 -> V_250 = V_163 ;
return 0 ;
}
return 0 ;
}
static int F_99 ( struct V_244 * V_245 ,
const char * V_251 )
{
char V_252 [ V_159 ] ;
F_100 ( V_252 , V_159 , L_32 , V_251 ) ;
if ( F_101 ( V_252 , L_33 ) )
return - 1 ;
if ( F_102 ( V_252 , V_245 ,
F_97 ) < 0 )
return - 1 ;
return 0 ;
}
static int F_103 ( void * V_243 ,
const char * V_31 V_253 ,
T_12 V_163 )
{
struct V_244 * V_245 = V_243 ;
if ( ! V_245 -> V_254 || V_163 < V_245 -> V_254 )
V_245 -> V_254 = V_163 ;
return 0 ;
}
static int F_104 ( struct V_244 * V_245 ,
const char * V_251 )
{
char V_255 [ V_159 ] ;
F_100 ( V_255 , V_159 , L_34 , V_251 ) ;
if ( F_101 ( V_255 , L_35 ) )
return - 1 ;
if ( F_105 ( V_255 , V_245 ,
F_103 ) < 0 )
return - 1 ;
return 0 ;
}
static void F_106 ( struct V_256 * V_257 , T_12 V_163 , T_12 V_164 , T_12 V_165 ,
T_12 V_258 , T_12 V_259 )
{
if ( V_257 -> V_24 || V_258 < V_163 || V_258 >= V_164 )
return;
V_257 -> V_24 = V_258 ;
V_257 -> V_156 = ( V_258 - V_163 ) + V_165 ;
V_257 -> V_208 = V_259 < V_164 ? V_259 - V_258 : V_164 - V_258 ;
}
static int F_107 ( T_12 V_163 , T_12 V_208 , T_12 V_165 , void * V_76 )
{
struct V_244 * V_245 = V_76 ;
T_12 V_164 = V_163 + V_208 ;
F_106 ( & V_245 -> V_260 , V_163 , V_164 , V_165 , V_245 -> V_249 ,
V_245 -> V_250 ) ;
F_106 ( & V_245 -> V_261 , V_163 , V_164 , V_165 , V_245 -> V_254 ,
V_245 -> V_246 ) ;
return 0 ;
}
static int F_108 ( struct V_244 * V_245 , T_1 * V_1 )
{
if ( F_77 ( V_1 , true , F_107 , V_245 ) < 0 )
return - 1 ;
return 0 ;
}
static int F_109 ( struct V_244 * V_245 , const char * V_251 ,
T_1 * V_1 )
{
if ( F_99 ( V_245 , V_251 ) )
return - 1 ;
if ( F_104 ( V_245 , V_251 ) )
return - 1 ;
if ( V_245 -> V_249 )
V_245 -> V_249 = F_110 ( V_245 -> V_249 , V_211 ) ;
else
V_245 -> V_249 = F_110 ( V_245 -> V_247 , V_211 ) ;
if ( V_245 -> V_250 ) {
V_245 -> V_250 = F_111 ( V_245 -> V_250 , V_211 ) ;
} else if ( V_245 -> V_248 ) {
V_245 -> V_250 = F_111 ( V_245 -> V_248 , V_211 ) ;
V_245 -> V_250 += V_211 ;
}
V_245 -> V_254 = F_110 ( V_245 -> V_254 , V_211 ) ;
if ( V_245 -> V_246 ) {
V_245 -> V_246 = F_111 ( V_245 -> V_246 ,
V_211 ) ;
V_245 -> V_246 += V_211 ;
}
if ( ! V_245 -> V_249 || ! V_245 -> V_250 )
return - 1 ;
if ( V_245 -> V_254 && ! V_245 -> V_246 )
return - 1 ;
return F_108 ( V_245 , V_1 ) ;
}
static int F_112 ( const char * V_262 , const char * V_263 ,
const char * V_31 )
{
char V_264 [ V_159 ] ;
char V_265 [ V_159 ] ;
F_100 ( V_264 , V_159 , L_36 , V_262 , V_31 ) ;
F_100 ( V_265 , V_159 , L_36 , V_263 , V_31 ) ;
return F_113 ( V_264 , V_265 , 0400 ) ;
}
static int F_114 ( const char * V_251 , const char * V_31 )
{
char V_90 [ V_159 ] ;
F_100 ( V_90 , V_159 , L_36 , V_251 , V_31 ) ;
return F_88 ( V_90 ) ;
}
static int F_115 ( int V_204 , int V_206 )
{
char * V_266 ;
char * V_267 ;
V_97 V_268 ;
T_2 V_208 ;
int V_56 = - 1 ;
V_266 = malloc ( V_211 ) ;
V_267 = malloc ( V_211 ) ;
if ( ! V_266 || ! V_267 )
goto V_80;
while ( 1 ) {
V_268 = F_43 ( V_204 , V_266 , V_211 ) ;
if ( V_268 < 0 )
goto V_80;
if ( ! V_268 )
break;
V_208 = V_268 ;
if ( F_116 ( V_206 , V_267 , V_208 ) != ( int ) V_208 )
goto V_80;
if ( memcmp ( V_266 , V_267 , V_208 ) )
goto V_80;
}
V_56 = 0 ;
V_80:
free ( V_267 ) ;
free ( V_266 ) ;
return V_56 ;
}
static int F_117 ( const char * V_264 ,
const char * V_265 )
{
int V_204 , V_206 , V_56 = - 1 ;
V_204 = F_37 ( V_264 , V_92 ) ;
if ( V_204 < 0 )
return - 1 ;
V_206 = F_37 ( V_265 , V_92 ) ;
if ( V_206 < 0 )
goto V_269;
V_56 = F_115 ( V_204 , V_206 ) ;
F_41 ( V_206 ) ;
V_269:
F_41 ( V_204 ) ;
return V_56 ;
}
static int F_118 ( const char * V_262 , const char * V_263 ,
const char * V_31 )
{
char V_264 [ V_159 ] ;
char V_265 [ V_159 ] ;
F_100 ( V_264 , V_159 , L_36 , V_262 , V_31 ) ;
F_100 ( V_265 , V_159 , L_36 , V_263 , V_31 ) ;
return F_117 ( V_264 , V_265 ) ;
}
int F_119 ( const char * V_262 , const char * V_263 )
{
struct V_213 V_213 ;
struct V_213 V_270 ;
T_2 V_222 = 2 ;
int V_32 = 0 , V_56 = - 1 ;
T_21 V_156 = V_211 , V_89 , V_271 = 0 ;
struct V_244 V_245 = { . V_249 = 0 , } ;
char V_272 [ V_159 ] ;
char V_273 [ V_159 ] ;
if ( F_112 ( V_262 , V_263 , L_37 ) )
return - 1 ;
if ( F_112 ( V_262 , V_263 , L_38 ) )
goto V_274;
F_100 ( V_272 , V_159 , L_39 , V_262 ) ;
F_100 ( V_273 , V_159 , L_39 , V_263 ) ;
if ( F_84 ( & V_213 , V_272 ) )
goto V_275;
if ( F_109 ( & V_245 , V_262 , V_213 . V_1 ) )
goto V_276;
if ( F_85 ( & V_270 , V_273 , V_213 . V_215 , false ) )
goto V_276;
if ( ! V_245 . V_261 . V_24 )
V_222 -= 1 ;
if ( F_90 ( & V_213 , & V_270 , V_222 ) )
goto V_277;
if ( F_93 ( & V_270 , V_32 ++ , V_156 , V_245 . V_260 . V_24 ,
V_245 . V_260 . V_208 ) )
goto V_277;
if ( V_245 . V_261 . V_24 ) {
V_271 = V_156 + V_245 . V_260 . V_208 ;
if ( F_93 ( & V_270 , V_32 , V_271 ,
V_245 . V_261 . V_24 , V_245 . V_261 . V_208 ) )
goto V_277;
}
V_89 = F_95 ( & V_270 ) ;
if ( V_89 < 0 || V_89 > V_156 )
goto V_277;
if ( F_81 ( V_213 . V_91 , V_245 . V_260 . V_156 , V_270 . V_91 , V_156 ,
V_245 . V_260 . V_208 ) )
goto V_277;
if ( V_271 && F_81 ( V_213 . V_91 , V_245 . V_261 . V_156 ,
V_270 . V_91 , V_271 ,
V_245 . V_261 . V_208 ) )
goto V_277;
if ( F_118 ( V_262 , V_263 , L_38 ) )
goto V_277;
if ( F_118 ( V_262 , V_263 , L_37 ) )
goto V_277;
V_56 = 0 ;
V_277:
F_89 ( & V_270 ) ;
if ( V_56 )
F_88 ( V_273 ) ;
V_276:
F_89 ( & V_213 ) ;
V_275:
if ( V_56 )
F_114 ( V_263 , L_38 ) ;
V_274:
if ( V_56 )
F_114 ( V_263 , L_37 ) ;
return V_56 ;
}
int F_120 ( struct V_278 * V_279 )
{
struct V_213 V_213 ;
struct V_213 V_270 ;
T_2 V_222 = 1 ;
int V_32 = 0 , V_56 = - 1 ;
T_21 V_156 = V_211 , V_89 ;
if ( F_84 ( & V_213 , V_279 -> V_272 ) )
return - 1 ;
strcpy ( V_279 -> V_273 , V_280 ) ;
if ( F_85 ( & V_270 , V_279 -> V_273 , V_213 . V_215 , true ) )
goto V_276;
if ( F_90 ( & V_213 , & V_270 , V_222 ) )
goto V_277;
if ( F_93 ( & V_270 , V_32 , V_156 , V_279 -> V_24 , V_279 -> V_208 ) )
goto V_277;
V_89 = F_95 ( & V_270 ) ;
if ( V_89 < 0 || V_89 > V_156 )
goto V_277;
if ( F_81 ( V_213 . V_91 , V_279 -> V_281 , V_270 . V_91 , V_156 , V_279 -> V_208 ) )
goto V_277;
V_56 = 0 ;
V_277:
F_89 ( & V_270 ) ;
if ( V_56 )
F_88 ( V_279 -> V_273 ) ;
V_276:
F_89 ( & V_213 ) ;
return V_56 ;
}
void F_121 ( struct V_278 * V_279 )
{
F_88 ( V_279 -> V_273 ) ;
}
void F_122 ( void )
{
F_123 ( V_282 ) ;
}
