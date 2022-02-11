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
int F_57 ( struct V_35 * V_35 , struct V_38 * V_38 ,
struct V_36 * V_131 , struct V_36 * V_132 ,
T_10 V_39 , int V_133 )
{
struct V_128 * V_128 = V_35 -> V_122 ? F_58 ( V_38 ) : NULL ;
struct V_38 * V_134 = V_38 ;
struct V_35 * V_135 = V_35 ;
T_6 * V_19 , * V_22 ;
T_11 V_136 ;
int V_56 = - 1 ;
T_11 V_32 ;
T_3 V_4 ;
T_7 V_21 ;
T_6 * V_48 , * V_137 = NULL ;
T_5 V_6 ;
T_9 * V_25 , * V_138 ;
T_1 * V_1 ;
int V_54 = 0 ;
bool V_139 = false , V_140 = false ;
V_35 -> V_141 = V_131 -> type ;
V_35 -> V_114 = V_131 -> V_114 ;
V_35 -> V_142 = V_131 -> V_4 . V_125 == V_127 ;
if ( V_133 && V_131 -> V_109 )
F_59 ( & V_35 -> V_70 [ V_38 -> type ] ) ;
if ( ! V_131 -> V_109 ) {
V_131 -> V_109 = V_131 -> V_57 ;
V_131 -> V_116 = V_131 -> V_58 ;
}
V_1 = V_131 -> V_1 ;
V_4 = V_131 -> V_4 ;
V_25 = V_131 -> V_109 ;
V_21 = V_131 -> V_116 ;
if ( V_132 -> V_108 )
V_137 = F_18 ( V_132 -> V_108 , NULL ) ;
V_48 = F_22 ( V_25 , NULL ) ;
if ( V_48 == NULL )
goto V_59;
V_25 = F_19 ( V_1 , V_21 . V_60 ) ;
if ( V_25 == NULL )
goto V_59;
V_19 = F_22 ( V_25 , NULL ) ;
if ( V_19 == NULL )
goto V_59;
V_138 = F_19 ( V_1 , V_4 . V_33 ) ;
if ( V_138 == NULL )
goto V_59;
V_22 = F_22 ( V_138 , NULL ) ;
if ( V_22 == NULL )
goto V_59;
V_136 = V_21 . V_28 / V_21 . V_62 ;
memset ( & V_6 , 0 , sizeof( V_6 ) ) ;
if ( F_55 ( V_128 ) ) {
F_60 (syms, nr_syms, idx, sym) {
const char * V_143 = F_9 ( & V_6 , V_19 ) ;
if ( strcmp ( V_143 , V_128 -> V_129 -> V_31 ) )
continue;
V_128 -> V_129 -> V_130 = V_6 . V_144 ;
V_38 -> V_145 = V_128 -> V_129 -> V_24 -
V_128 -> V_129 -> V_130 ;
break;
}
}
V_35 -> V_124 = V_132 -> V_124 || F_56 ( V_128 ) ;
if ( V_38 -> type == V_17 && ( V_35 -> V_122 || V_133 ) ) {
V_139 = true ;
V_140 = V_35 -> V_124 ;
}
F_60 (syms, nr_syms, idx, sym) {
struct V_43 * V_44 ;
const char * V_143 = F_9 ( & V_6 , V_19 ) ;
char * V_146 = NULL ;
int V_147 = F_7 ( & V_6 ) ;
const char * V_148 ;
bool V_149 = false ;
if ( ! V_147 && ! F_8 ( & V_6 , V_38 -> type ) )
continue;
if ( V_4 . V_150 == V_151 ) {
if ( ! strcmp ( V_143 , L_20 ) ||
! strcmp ( V_143 , L_21 ) ||
! strcmp ( V_143 , L_22 ) )
continue;
}
if ( V_132 -> V_108 && V_6 . V_11 == V_132 -> V_119 ) {
T_18 V_152 = V_6 . V_144 - V_131 -> V_120 . V_27 ;
T_12 * V_153 = V_137 -> V_20 + V_152 ;
V_6 . V_144 = F_61 ( V_35 , T_12 , * V_153 ) ;
V_6 . V_11 = F_14 ( V_132 -> V_1 ,
V_6 . V_144 ) ;
V_149 = true ;
}
if ( V_6 . V_11 == V_15 )
continue;
V_25 = F_19 ( V_132 -> V_1 , V_6 . V_11 ) ;
if ( ! V_25 )
goto V_59;
F_16 ( V_25 , & V_21 ) ;
if ( V_147 && ! F_13 ( & V_21 , V_22 , V_38 -> type ) )
continue;
V_148 = F_10 ( & V_21 , V_22 ) ;
if ( ( V_4 . V_150 == V_151 ) &&
( V_38 -> type == V_17 ) &&
( V_6 . V_144 & 1 ) )
-- V_6 . V_144 ;
if ( V_35 -> V_122 || V_133 ) {
char V_154 [ V_155 ] ;
if ( V_140 )
V_6 . V_144 -= V_21 . V_27 - V_21 . V_63 ;
if ( strcmp ( V_148 ,
( V_135 -> V_156 +
V_35 -> V_157 ) ) == 0 )
goto V_158;
if ( strcmp ( V_148 , L_23 ) == 0 ) {
if ( V_139 && V_35 -> V_122 ) {
V_139 = false ;
V_38 -> V_159 = V_21 . V_27 +
F_56 ( V_128 ) ;
V_38 -> V_160 = V_38 -> V_159 + V_21 . V_28 ;
V_38 -> V_161 = V_21 . V_63 ;
V_38 -> V_162 = V_163 ;
V_38 -> V_164 = V_165 ;
F_62 ( V_128 -> V_166 , V_38 ) ;
F_63 ( V_128 -> V_166 , V_38 ) ;
}
if ( V_139 && V_133 ) {
V_139 = false ;
V_38 -> V_161 = V_21 . V_63 ;
}
V_134 = V_38 ;
V_135 = V_35 ;
goto V_158;
}
if ( ! V_128 )
goto V_158;
snprintf ( V_154 , sizeof( V_154 ) ,
L_24 , V_35 -> V_156 , V_148 ) ;
V_134 = F_64 ( V_128 -> V_166 , V_38 -> type , V_154 ) ;
if ( V_134 == NULL ) {
T_12 V_159 = V_6 . V_144 ;
if ( V_133 )
V_159 += V_38 -> V_159 + V_21 . V_63 ;
V_135 = F_65 ( V_154 ) ;
if ( V_135 == NULL )
goto V_59;
V_135 -> V_122 = V_35 -> V_122 ;
V_135 -> V_73 = V_35 -> V_73 ;
V_135 -> V_167 = V_35 -> V_167 ;
V_134 = F_66 ( V_159 , V_135 ,
V_38 -> type ) ;
if ( V_134 == NULL ) {
F_67 ( V_135 ) ;
goto V_59;
}
if ( V_140 ) {
V_134 -> V_159 = V_21 . V_27 +
F_56 ( V_128 ) ;
V_134 -> V_160 = V_134 -> V_159 +
V_21 . V_28 ;
V_134 -> V_161 = V_21 . V_63 ;
} else {
V_134 -> V_162 = V_168 ;
V_134 -> V_164 = V_168 ;
}
V_135 -> V_141 = V_35 -> V_141 ;
F_63 ( V_128 -> V_166 , V_134 ) ;
F_68 ( & V_35 -> V_169 , V_135 ) ;
F_69 ( V_135 , V_38 -> type ) ;
} else
V_135 = V_134 -> V_35 ;
goto V_158;
}
if ( ( V_149 && V_132 -> V_124 )
|| ( ! V_149 && V_131 -> V_124 ) ) {
F_70 ( L_25 V_170 L_26
L_27 V_170 L_28 V_170 L_29 , V_72 ,
( T_12 ) V_6 . V_144 , ( T_12 ) V_21 . V_27 ,
( T_12 ) V_21 . V_63 ) ;
V_6 . V_144 -= V_21 . V_27 - V_21 . V_63 ;
}
V_158:
if ( V_171 . V_172 ) {
V_146 = F_71 ( NULL , V_143 ,
V_173 | V_174 ) ;
if ( V_146 != NULL )
V_143 = V_146 ;
}
V_44 = F_26 ( V_6 . V_144 , V_6 . V_175 ,
F_72 ( V_6 . V_7 ) , V_143 ) ;
free ( V_146 ) ;
if ( ! V_44 )
goto V_59;
if ( V_39 && V_39 ( V_134 , V_44 ) )
F_27 ( V_44 ) ;
else {
F_28 ( & V_135 -> V_70 [ V_134 -> type ] , V_44 ) ;
V_54 ++ ;
}
}
if ( V_54 > 0 ) {
F_73 ( & V_35 -> V_70 [ V_38 -> type ] ) ;
F_74 ( & V_35 -> V_70 [ V_38 -> type ] ) ;
if ( V_128 ) {
F_75 ( V_128 -> V_166 , V_38 -> type ) ;
}
}
V_56 = V_54 ;
V_59:
return V_56 ;
}
static int F_76 ( T_1 * V_1 , bool V_176 , T_19 V_177 , void * V_76 )
{
T_20 V_178 ;
T_2 V_179 , V_180 ;
int V_56 ;
T_12 V_89 ;
if ( F_1 ( V_1 , & V_180 ) )
return - 1 ;
for ( V_179 = 0 ; V_179 < V_180 ; V_179 ++ ) {
if ( F_77 ( V_1 , V_179 , & V_178 ) == NULL )
return - 1 ;
if ( V_178 . V_181 != V_182 )
continue;
if ( V_176 ) {
if ( ! ( V_178 . V_183 & V_184 ) )
continue;
} else {
if ( ! ( V_178 . V_183 & V_185 ) )
continue;
}
V_89 = F_35 ( V_178 . V_186 , V_178 . V_187 ) ;
if ( ! V_89 )
continue;
V_56 = V_177 ( V_178 . V_188 , V_89 , V_178 . V_189 , V_76 ) ;
if ( V_56 )
return V_56 ;
}
return 0 ;
}
int F_78 ( int V_91 , bool V_176 , T_19 V_177 , void * V_76 ,
bool * V_114 )
{
int V_56 ;
T_1 * V_1 ;
V_1 = F_38 ( V_91 , V_93 , NULL ) ;
if ( V_1 == NULL )
return - 1 ;
if ( V_114 )
* V_114 = ( F_52 ( V_1 ) == V_115 ) ;
V_56 = F_76 ( V_1 , V_176 , V_177 , V_76 ) ;
F_40 ( V_1 ) ;
return V_56 ;
}
enum V_190 F_79 ( int V_91 )
{
enum V_190 V_190 = V_191 ;
T_3 V_4 ;
T_15 V_77 ;
T_1 * V_1 ;
V_1 = F_38 ( V_91 , V_93 , NULL ) ;
if ( V_1 == NULL )
goto V_80;
V_77 = F_32 ( V_1 ) ;
if ( V_77 != V_81 )
goto V_192;
if ( F_52 ( V_1 ) == V_115 ) {
V_190 = V_193 ;
goto V_192;
}
if ( F_2 ( V_1 , & V_4 ) == NULL )
goto V_192;
if ( V_4 . V_150 == V_194 )
V_190 = V_195 ;
else
V_190 = V_196 ;
V_192:
F_40 ( V_1 ) ;
V_80:
return V_190 ;
}
static int F_80 ( int V_197 , T_21 V_198 , int V_199 , T_21 V_200 , T_12 V_201 )
{
V_97 V_202 ;
T_2 V_98 ;
int V_56 = - 1 ;
char * V_203 = malloc ( V_204 ) ;
if ( V_203 == NULL )
return - 1 ;
if ( F_81 ( V_199 , V_200 , V_205 ) != V_200 )
goto V_80;
if ( F_81 ( V_197 , V_198 , V_205 ) != V_198 )
goto V_80;
while ( V_201 ) {
V_98 = V_204 ;
if ( V_201 < V_98 )
V_98 = V_201 ;
V_202 = F_43 ( V_197 , V_203 , V_98 ) ;
if ( V_202 < 0 )
goto V_80;
if ( ! V_202 )
break;
V_98 = V_202 ;
V_202 = F_82 ( V_199 , V_203 , V_98 ) ;
if ( V_202 < 0 )
goto V_80;
if ( ( T_2 ) V_202 != V_98 )
goto V_80;
V_201 -= V_98 ;
}
V_56 = 0 ;
V_80:
free ( V_203 ) ;
return V_56 ;
}
static int F_83 ( struct V_206 * V_206 , const char * V_90 )
{
T_3 * V_4 ;
V_206 -> V_91 = F_37 ( V_90 , V_92 ) ;
if ( V_206 -> V_91 == - 1 )
return - 1 ;
V_206 -> V_1 = F_38 ( V_206 -> V_91 , V_207 , NULL ) ;
if ( ! V_206 -> V_1 )
goto V_94;
V_206 -> V_208 = F_52 ( V_206 -> V_1 ) ;
if ( V_206 -> V_208 == V_209 )
goto V_192;
V_4 = F_2 ( V_206 -> V_1 , & V_206 -> V_4 ) ;
if ( ! V_4 )
goto V_192;
return 0 ;
V_192:
F_40 ( V_206 -> V_1 ) ;
V_94:
F_41 ( V_206 -> V_91 ) ;
return - 1 ;
}
static int F_84 ( struct V_206 * V_206 , char * V_90 , int V_208 ,
bool V_210 )
{
T_3 * V_4 ;
V_206 -> V_208 = V_208 ;
if ( V_210 )
V_206 -> V_91 = F_85 ( V_90 ) ;
else
V_206 -> V_91 = F_37 ( V_90 , V_211 | V_212 | V_213 , 0400 ) ;
if ( V_206 -> V_91 == - 1 )
return - 1 ;
V_206 -> V_1 = F_38 ( V_206 -> V_91 , V_214 , NULL ) ;
if ( ! V_206 -> V_1 )
goto V_94;
if ( ! F_86 ( V_206 -> V_1 , V_208 ) )
goto V_192;
V_4 = F_2 ( V_206 -> V_1 , & V_206 -> V_4 ) ;
if ( ! V_4 )
goto V_192;
return 0 ;
V_192:
F_40 ( V_206 -> V_1 ) ;
V_94:
F_41 ( V_206 -> V_91 ) ;
F_87 ( V_90 ) ;
return - 1 ;
}
static void F_88 ( struct V_206 * V_206 )
{
F_40 ( V_206 -> V_1 ) ;
F_41 ( V_206 -> V_91 ) ;
}
static int F_89 ( struct V_206 * V_197 , struct V_206 * V_199 , T_2 V_215 )
{
T_3 * V_4 = & V_199 -> V_4 ;
T_3 * V_216 = & V_197 -> V_4 ;
memcpy ( V_4 -> V_111 , V_216 -> V_111 , V_217 ) ;
V_4 -> V_125 = V_216 -> V_125 ;
V_4 -> V_150 = V_216 -> V_150 ;
V_4 -> V_218 = V_216 -> V_218 ;
V_4 -> V_219 = 0 ;
V_4 -> V_220 = 0 ;
V_4 -> V_221 = V_216 -> V_221 ;
V_4 -> V_5 = V_215 ;
V_4 -> V_222 = 0 ;
V_4 -> V_223 = 0 ;
V_4 -> V_33 = 0 ;
if ( V_197 -> V_208 == V_224 ) {
V_4 -> V_225 = sizeof( V_226 ) ;
V_4 -> V_227 = sizeof( V_226 ) ;
V_4 -> V_228 = sizeof( V_229 ) ;
} else {
V_4 -> V_225 = sizeof( V_230 ) ;
V_4 -> V_227 = sizeof( V_230 ) ;
V_4 -> V_228 = sizeof( V_231 ) ;
}
if ( ! F_90 ( V_199 -> V_1 , V_4 ) )
return - 1 ;
if ( ! F_91 ( V_199 -> V_1 , V_215 ) )
return - 1 ;
return 0 ;
}
static int F_92 ( struct V_206 * V_206 , int V_32 , T_21 V_152 ,
T_12 V_24 , T_12 V_201 )
{
T_20 V_232 ;
T_20 * V_178 ;
V_178 = F_77 ( V_206 -> V_1 , V_32 , & V_232 ) ;
if ( ! V_178 )
return - 1 ;
V_178 -> V_181 = V_182 ;
V_178 -> V_183 = V_185 | V_233 | V_184 ;
V_178 -> V_189 = V_152 ;
V_178 -> V_188 = V_24 ;
V_178 -> V_234 = 0 ;
V_178 -> V_187 = V_201 ;
V_178 -> V_186 = V_201 ;
V_178 -> V_235 = V_204 ;
if ( ! F_93 ( V_206 -> V_1 , V_32 , V_178 ) )
return - 1 ;
return 0 ;
}
static T_21 F_94 ( struct V_206 * V_206 )
{
return F_95 ( V_206 -> V_1 , V_214 ) ;
}
static int F_96 ( void * V_236 , const char * V_31 , char type ,
T_12 V_159 )
{
struct V_237 * V_238 = V_236 ;
if ( ! F_97 ( type , V_17 ) )
return 0 ;
if ( strchr ( V_31 , '[' ) ) {
if ( V_159 > V_238 -> V_239 )
V_238 -> V_239 = V_159 ;
return 0 ;
}
if ( ! V_238 -> V_240 || V_159 < V_238 -> V_240 )
V_238 -> V_240 = V_159 ;
if ( ! V_238 -> V_241 || V_159 > V_238 -> V_241 )
V_238 -> V_241 = V_159 ;
if ( ! strcmp ( V_31 , L_30 ) ) {
V_238 -> V_242 = V_159 ;
return 0 ;
}
if ( ! strcmp ( V_31 , L_31 ) ) {
V_238 -> V_243 = V_159 ;
return 0 ;
}
return 0 ;
}
static int F_98 ( struct V_237 * V_238 ,
const char * V_244 )
{
char V_245 [ V_155 ] ;
F_99 ( V_245 , V_155 , L_32 , V_244 ) ;
if ( F_100 ( V_245 , L_33 ) )
return - 1 ;
if ( F_101 ( V_245 , V_238 ,
F_96 ) < 0 )
return - 1 ;
return 0 ;
}
static int F_102 ( void * V_236 ,
const char * V_31 V_246 ,
T_12 V_159 )
{
struct V_237 * V_238 = V_236 ;
if ( ! V_238 -> V_247 || V_159 < V_238 -> V_247 )
V_238 -> V_247 = V_159 ;
return 0 ;
}
static int F_103 ( struct V_237 * V_238 ,
const char * V_244 )
{
char V_248 [ V_155 ] ;
F_99 ( V_248 , V_155 , L_34 , V_244 ) ;
if ( F_100 ( V_248 , L_35 ) )
return - 1 ;
if ( F_104 ( V_248 , V_238 ,
F_102 ) < 0 )
return - 1 ;
return 0 ;
}
static void F_105 ( struct V_249 * V_250 , T_12 V_159 , T_12 V_160 , T_12 V_161 ,
T_12 V_251 , T_12 V_252 )
{
if ( V_250 -> V_24 || V_251 < V_159 || V_251 >= V_160 )
return;
V_250 -> V_24 = V_251 ;
V_250 -> V_152 = ( V_251 - V_159 ) + V_161 ;
V_250 -> V_201 = V_252 < V_160 ? V_252 - V_251 : V_160 - V_251 ;
}
static int F_106 ( T_12 V_159 , T_12 V_201 , T_12 V_161 , void * V_76 )
{
struct V_237 * V_238 = V_76 ;
T_12 V_160 = V_159 + V_201 ;
F_105 ( & V_238 -> V_253 , V_159 , V_160 , V_161 , V_238 -> V_242 ,
V_238 -> V_243 ) ;
F_105 ( & V_238 -> V_254 , V_159 , V_160 , V_161 , V_238 -> V_247 ,
V_238 -> V_239 ) ;
return 0 ;
}
static int F_107 ( struct V_237 * V_238 , T_1 * V_1 )
{
if ( F_76 ( V_1 , true , F_106 , V_238 ) < 0 )
return - 1 ;
return 0 ;
}
static int F_108 ( struct V_237 * V_238 , const char * V_244 ,
T_1 * V_1 )
{
if ( F_98 ( V_238 , V_244 ) )
return - 1 ;
if ( F_103 ( V_238 , V_244 ) )
return - 1 ;
if ( V_238 -> V_242 )
V_238 -> V_242 = F_109 ( V_238 -> V_242 , V_204 ) ;
else
V_238 -> V_242 = F_109 ( V_238 -> V_240 , V_204 ) ;
if ( V_238 -> V_243 ) {
V_238 -> V_243 = F_110 ( V_238 -> V_243 , V_204 ) ;
} else if ( V_238 -> V_241 ) {
V_238 -> V_243 = F_110 ( V_238 -> V_241 , V_204 ) ;
V_238 -> V_243 += V_204 ;
}
V_238 -> V_247 = F_109 ( V_238 -> V_247 , V_204 ) ;
if ( V_238 -> V_239 ) {
V_238 -> V_239 = F_110 ( V_238 -> V_239 ,
V_204 ) ;
V_238 -> V_239 += V_204 ;
}
if ( ! V_238 -> V_242 || ! V_238 -> V_243 )
return - 1 ;
if ( V_238 -> V_247 && ! V_238 -> V_239 )
return - 1 ;
return F_107 ( V_238 , V_1 ) ;
}
static int F_111 ( const char * V_255 , const char * V_256 ,
const char * V_31 )
{
char V_257 [ V_155 ] ;
char V_258 [ V_155 ] ;
F_99 ( V_257 , V_155 , L_36 , V_255 , V_31 ) ;
F_99 ( V_258 , V_155 , L_36 , V_256 , V_31 ) ;
return F_112 ( V_257 , V_258 , 0400 ) ;
}
static int F_113 ( const char * V_244 , const char * V_31 )
{
char V_90 [ V_155 ] ;
F_99 ( V_90 , V_155 , L_36 , V_244 , V_31 ) ;
return F_87 ( V_90 ) ;
}
static int F_114 ( int V_197 , int V_199 )
{
char * V_259 ;
char * V_260 ;
V_97 V_261 ;
T_2 V_201 ;
int V_56 = - 1 ;
V_259 = malloc ( V_204 ) ;
V_260 = malloc ( V_204 ) ;
if ( ! V_259 || ! V_260 )
goto V_80;
while ( 1 ) {
V_261 = F_43 ( V_197 , V_259 , V_204 ) ;
if ( V_261 < 0 )
goto V_80;
if ( ! V_261 )
break;
V_201 = V_261 ;
if ( F_115 ( V_199 , V_260 , V_201 ) != ( int ) V_201 )
goto V_80;
if ( memcmp ( V_259 , V_260 , V_201 ) )
goto V_80;
}
V_56 = 0 ;
V_80:
free ( V_260 ) ;
free ( V_259 ) ;
return V_56 ;
}
static int F_116 ( const char * V_257 ,
const char * V_258 )
{
int V_197 , V_199 , V_56 = - 1 ;
V_197 = F_37 ( V_257 , V_92 ) ;
if ( V_197 < 0 )
return - 1 ;
V_199 = F_37 ( V_258 , V_92 ) ;
if ( V_199 < 0 )
goto V_262;
V_56 = F_114 ( V_197 , V_199 ) ;
F_41 ( V_199 ) ;
V_262:
F_41 ( V_197 ) ;
return V_56 ;
}
static int F_117 ( const char * V_255 , const char * V_256 ,
const char * V_31 )
{
char V_257 [ V_155 ] ;
char V_258 [ V_155 ] ;
F_99 ( V_257 , V_155 , L_36 , V_255 , V_31 ) ;
F_99 ( V_258 , V_155 , L_36 , V_256 , V_31 ) ;
return F_116 ( V_257 , V_258 ) ;
}
int F_118 ( const char * V_255 , const char * V_256 )
{
struct V_206 V_206 ;
struct V_206 V_263 ;
T_2 V_215 = 2 ;
int V_32 = 0 , V_56 = - 1 ;
T_21 V_152 = V_204 , V_89 , V_264 = 0 ;
struct V_237 V_238 = { . V_242 = 0 , } ;
char V_265 [ V_155 ] ;
char V_266 [ V_155 ] ;
if ( F_111 ( V_255 , V_256 , L_37 ) )
return - 1 ;
if ( F_111 ( V_255 , V_256 , L_38 ) )
goto V_267;
F_99 ( V_265 , V_155 , L_39 , V_255 ) ;
F_99 ( V_266 , V_155 , L_39 , V_256 ) ;
if ( F_83 ( & V_206 , V_265 ) )
goto V_268;
if ( F_108 ( & V_238 , V_255 , V_206 . V_1 ) )
goto V_269;
if ( F_84 ( & V_263 , V_266 , V_206 . V_208 , false ) )
goto V_269;
if ( ! V_238 . V_254 . V_24 )
V_215 -= 1 ;
if ( F_89 ( & V_206 , & V_263 , V_215 ) )
goto V_270;
if ( F_92 ( & V_263 , V_32 ++ , V_152 , V_238 . V_253 . V_24 ,
V_238 . V_253 . V_201 ) )
goto V_270;
if ( V_238 . V_254 . V_24 ) {
V_264 = V_152 + V_238 . V_253 . V_201 ;
if ( F_92 ( & V_263 , V_32 , V_264 ,
V_238 . V_254 . V_24 , V_238 . V_254 . V_201 ) )
goto V_270;
}
V_89 = F_94 ( & V_263 ) ;
if ( V_89 < 0 || V_89 > V_152 )
goto V_270;
if ( F_80 ( V_206 . V_91 , V_238 . V_253 . V_152 , V_263 . V_91 , V_152 ,
V_238 . V_253 . V_201 ) )
goto V_270;
if ( V_264 && F_80 ( V_206 . V_91 , V_238 . V_254 . V_152 ,
V_263 . V_91 , V_264 ,
V_238 . V_254 . V_201 ) )
goto V_270;
if ( F_117 ( V_255 , V_256 , L_38 ) )
goto V_270;
if ( F_117 ( V_255 , V_256 , L_37 ) )
goto V_270;
V_56 = 0 ;
V_270:
F_88 ( & V_263 ) ;
if ( V_56 )
F_87 ( V_266 ) ;
V_269:
F_88 ( & V_206 ) ;
V_268:
if ( V_56 )
F_113 ( V_256 , L_38 ) ;
V_267:
if ( V_56 )
F_113 ( V_256 , L_37 ) ;
return V_56 ;
}
int F_119 ( struct V_271 * V_272 )
{
struct V_206 V_206 ;
struct V_206 V_263 ;
T_2 V_215 = 1 ;
int V_32 = 0 , V_56 = - 1 ;
T_21 V_152 = V_204 , V_89 ;
if ( F_83 ( & V_206 , V_272 -> V_265 ) )
return - 1 ;
strcpy ( V_272 -> V_266 , V_273 ) ;
if ( F_84 ( & V_263 , V_272 -> V_266 , V_206 . V_208 , true ) )
goto V_269;
if ( F_89 ( & V_206 , & V_263 , V_215 ) )
goto V_270;
if ( F_92 ( & V_263 , V_32 , V_152 , V_272 -> V_24 , V_272 -> V_201 ) )
goto V_270;
V_89 = F_94 ( & V_263 ) ;
if ( V_89 < 0 || V_89 > V_152 )
goto V_270;
if ( F_80 ( V_206 . V_91 , V_272 -> V_274 , V_263 . V_91 , V_152 , V_272 -> V_201 ) )
goto V_270;
V_56 = 0 ;
V_270:
F_88 ( & V_263 ) ;
if ( V_56 )
F_87 ( V_272 -> V_266 ) ;
V_269:
F_88 ( & V_206 ) ;
return V_56 ;
}
void F_120 ( struct V_271 * V_272 )
{
F_87 ( V_272 -> V_266 ) ;
}
void F_121 ( void )
{
F_122 ( V_275 ) ;
}
