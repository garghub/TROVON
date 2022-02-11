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
return F_3 ( V_6 ) == V_8 &&
V_6 -> V_9 != 0 &&
V_6 -> V_10 != V_11 ;
}
static inline bool F_6 ( const T_5 * V_6 )
{
return F_3 ( V_6 ) == V_12 &&
V_6 -> V_9 != 0 &&
V_6 -> V_10 != V_11 ;
}
static inline int F_7 ( const T_5 * V_6 )
{
return F_3 ( V_6 ) == V_13 &&
V_6 -> V_9 != 0 &&
V_6 -> V_10 != V_11 &&
V_6 -> V_10 != V_14 ;
}
static bool F_8 ( T_5 * V_6 , enum V_15 type )
{
switch ( type ) {
case V_16 :
return F_5 ( V_6 ) ;
case V_17 :
return F_6 ( V_6 ) ;
default:
return false ;
}
}
static inline const char * F_9 ( const T_5 * V_6 ,
const T_6 * V_18 )
{
return V_18 -> V_19 + V_6 -> V_9 ;
}
static inline const char * F_10 ( const T_7 * V_20 ,
const T_6 * V_21 )
{
return V_21 -> V_19 + V_20 -> V_22 ;
}
static inline int F_11 ( const T_7 * V_20 ,
const T_6 * V_21 )
{
return strstr ( F_10 ( V_20 , V_21 ) , L_1 ) != NULL ;
}
static inline bool F_12 ( const T_7 * V_20 ,
const T_6 * V_21 )
{
return strstr ( F_10 ( V_20 , V_21 ) , L_2 ) != NULL ;
}
static bool F_13 ( T_7 * V_20 , T_6 * V_21 ,
enum V_15 type )
{
switch ( type ) {
case V_16 :
return F_11 ( V_20 , V_21 ) ;
case V_17 :
return F_12 ( V_20 , V_21 ) ;
default:
return false ;
}
}
static T_2 F_14 ( T_1 * V_1 , T_8 V_23 )
{
T_9 * V_24 = NULL ;
T_7 V_20 ;
T_2 V_25 = 1 ;
while ( ( V_24 = F_15 ( V_1 , V_24 ) ) != NULL ) {
F_16 ( V_24 , & V_20 ) ;
if ( ( V_23 >= V_20 . V_26 ) &&
( V_23 < ( V_20 . V_26 + V_20 . V_27 ) ) )
return V_25 ;
++ V_25 ;
}
return - 1 ;
}
static T_9 * F_17 ( T_1 * V_1 , T_3 * V_28 ,
T_7 * V_29 , const char * V_30 ,
T_2 * V_31 )
{
T_9 * V_24 = NULL ;
T_2 V_25 = 1 ;
if ( ! F_18 ( F_19 ( V_1 , V_28 -> V_32 ) , NULL ) )
return NULL ;
while ( ( V_24 = F_15 ( V_1 , V_24 ) ) != NULL ) {
char * V_33 ;
F_16 ( V_24 , V_29 ) ;
V_33 = F_20 ( V_1 , V_28 -> V_32 , V_29 -> V_22 ) ;
if ( ! strcmp ( V_30 , V_33 ) ) {
if ( V_31 )
* V_31 = V_25 ;
break;
}
++ V_25 ;
}
return V_24 ;
}
int F_21 ( struct V_34 * V_34 , struct V_35 * V_36 , struct V_37 * V_37 ,
T_10 V_38 )
{
T_11 V_39 , V_31 ;
T_5 V_6 ;
T_12 V_40 ;
T_7 V_41 ;
struct V_42 * V_43 ;
T_7 V_44 , V_45 ;
T_6 * V_46 , * V_47 , * V_18 ;
T_9 * V_48 , * V_49 , * V_50 ;
T_2 V_51 ;
T_3 V_4 ;
char V_52 [ 1024 ] ;
T_1 * V_1 ;
int V_53 = 0 , V_54 , V_55 = 0 ;
if ( ! V_36 -> V_56 )
return 0 ;
V_1 = V_36 -> V_1 ;
V_4 = V_36 -> V_4 ;
V_50 = V_36 -> V_56 ;
V_45 = V_36 -> V_57 ;
V_51 = V_36 -> V_51 ;
if ( V_50 == NULL )
goto V_58;
V_48 = F_17 ( V_1 , & V_4 , & V_44 ,
L_3 , NULL ) ;
if ( V_48 == NULL ) {
V_48 = F_17 ( V_1 , & V_4 , & V_44 ,
L_4 , NULL ) ;
if ( V_48 == NULL )
goto V_58;
}
V_55 = - 1 ;
if ( V_44 . V_59 != V_51 )
goto V_58;
if ( F_17 ( V_1 , & V_4 , & V_41 , L_5 , NULL ) == NULL )
goto V_58;
V_46 = F_22 ( V_48 , NULL ) ;
if ( V_46 == NULL )
goto V_58;
V_47 = F_22 ( V_50 , NULL ) ;
if ( V_47 == NULL )
goto V_58;
V_49 = F_19 ( V_1 , V_45 . V_59 ) ;
if ( V_49 == NULL )
goto V_58;
V_18 = F_22 ( V_49 , NULL ) ;
if ( V_18 == NULL )
goto V_58;
if ( V_18 -> V_60 == 0 )
goto V_58;
V_39 = V_44 . V_27 / V_44 . V_61 ;
V_40 = V_41 . V_62 ;
if ( V_44 . V_63 == V_64 ) {
T_13 V_65 , * V_66 ;
F_23 (reldata, pos, pos_mem, idx,
nr_rel_entries) {
V_54 = F_24 ( V_66 -> V_67 ) ;
V_40 += V_41 . V_61 ;
F_25 ( V_47 , V_54 , & V_6 ) ;
snprintf ( V_52 , sizeof( V_52 ) ,
L_6 , F_9 ( & V_6 , V_18 ) ) ;
V_43 = F_26 ( V_40 , V_41 . V_61 ,
V_68 , V_52 ) ;
if ( ! V_43 )
goto V_58;
if ( V_38 && V_38 ( V_37 , V_43 ) )
F_27 ( V_43 ) ;
else {
F_28 ( & V_34 -> V_69 [ V_37 -> type ] , V_43 ) ;
++ V_53 ;
}
}
} else if ( V_44 . V_63 == V_70 ) {
T_14 V_65 , * V_66 ;
F_29 (reldata, pos, pos_mem, idx,
nr_rel_entries) {
V_54 = F_24 ( V_66 -> V_67 ) ;
V_40 += V_41 . V_61 ;
F_25 ( V_47 , V_54 , & V_6 ) ;
snprintf ( V_52 , sizeof( V_52 ) ,
L_6 , F_9 ( & V_6 , V_18 ) ) ;
V_43 = F_26 ( V_40 , V_41 . V_61 ,
V_68 , V_52 ) ;
if ( ! V_43 )
goto V_58;
if ( V_38 && V_38 ( V_37 , V_43 ) )
F_27 ( V_43 ) ;
else {
F_28 ( & V_34 -> V_69 [ V_37 -> type ] , V_43 ) ;
++ V_53 ;
}
}
}
V_55 = 0 ;
V_58:
if ( V_55 == 0 )
return V_53 ;
F_30 ( L_7 ,
V_71 , V_34 -> V_72 ) ;
return 0 ;
}
static int F_31 ( T_1 * V_1 , void * V_73 , T_2 V_74 )
{
int V_55 = - 1 ;
T_3 V_4 ;
T_7 V_20 ;
T_6 * V_75 ;
T_9 * V_24 ;
T_15 V_76 ;
void * V_77 ;
if ( V_74 < V_78 )
goto V_79;
V_76 = F_32 ( V_1 ) ;
if ( V_76 != V_80 )
goto V_79;
if ( F_2 ( V_1 , & V_4 ) == NULL ) {
F_33 ( L_8 , V_71 ) ;
goto V_79;
}
do {
V_24 = F_17 ( V_1 , & V_4 , & V_20 ,
L_9 , NULL ) ;
if ( V_24 )
break;
V_24 = F_17 ( V_1 , & V_4 , & V_20 ,
L_10 , NULL ) ;
if ( V_24 )
break;
V_24 = F_17 ( V_1 , & V_4 , & V_20 ,
L_11 , NULL ) ;
if ( V_24 )
break;
return V_55 ;
} while ( 0 );
V_75 = F_22 ( V_24 , NULL ) ;
if ( V_75 == NULL )
goto V_79;
V_77 = V_75 -> V_19 ;
while ( V_77 < ( V_75 -> V_19 + V_75 -> V_60 ) ) {
T_16 * V_81 = V_77 ;
T_2 V_82 = F_34 ( V_81 -> V_83 ) ,
V_84 = F_34 ( V_81 -> V_85 ) ;
const char * V_30 ;
V_77 += sizeof( * V_81 ) ;
V_30 = V_77 ;
V_77 += V_82 ;
if ( V_81 -> V_86 == V_87 &&
V_81 -> V_83 == sizeof( L_12 ) ) {
if ( memcmp ( V_30 , L_12 , sizeof( L_12 ) ) == 0 ) {
T_2 V_88 = F_35 ( V_74 , V_84 ) ;
memcpy ( V_73 , V_77 , V_88 ) ;
memset ( V_73 + V_88 , 0 , V_74 - V_88 ) ;
V_55 = V_84 ;
break;
}
}
V_77 += V_84 ;
}
V_79:
return V_55 ;
}
int F_36 ( const char * V_89 , void * V_73 , T_2 V_74 )
{
int V_90 , V_55 = - 1 ;
T_1 * V_1 ;
if ( V_74 < V_78 )
goto V_79;
V_90 = F_37 ( V_89 , V_91 ) ;
if ( V_90 < 0 )
goto V_79;
V_1 = F_38 ( V_90 , V_92 , NULL ) ;
if ( V_1 == NULL ) {
F_39 ( L_13 , V_71 , V_89 ) ;
goto V_93;
}
V_55 = F_31 ( V_1 , V_73 , V_74 ) ;
F_40 ( V_1 ) ;
V_93:
F_41 ( V_90 ) ;
V_79:
return V_55 ;
}
int F_42 ( const char * V_89 , void * V_94 , T_2 V_74 )
{
int V_90 , V_55 = - 1 ;
if ( V_74 < V_78 )
goto V_79;
V_90 = F_37 ( V_89 , V_91 ) ;
if ( V_90 < 0 )
goto V_79;
while ( 1 ) {
char V_73 [ V_95 ] ;
T_16 V_81 ;
T_2 V_82 , V_84 ;
if ( F_43 ( V_90 , & V_81 , sizeof( V_81 ) ) != sizeof( V_81 ) )
break;
V_82 = F_34 ( V_81 . V_83 ) ;
V_84 = F_34 ( V_81 . V_85 ) ;
if ( V_81 . V_86 == V_87 &&
V_81 . V_83 == sizeof( L_12 ) ) {
if ( F_43 ( V_90 , V_73 , V_82 ) != ( V_96 ) V_82 )
break;
if ( memcmp ( V_73 , L_12 , sizeof( L_12 ) ) == 0 ) {
T_2 V_88 = F_35 ( V_84 , V_74 ) ;
if ( F_43 ( V_90 , V_94 , V_88 ) == ( V_96 ) V_88 ) {
memset ( V_94 + V_88 , 0 , V_74 - V_88 ) ;
V_55 = 0 ;
break;
}
} else if ( F_43 ( V_90 , V_73 , V_84 ) != ( V_96 ) V_84 )
break;
} else {
int V_97 = V_82 + V_84 ;
if ( F_43 ( V_90 , V_73 , V_97 ) != V_97 )
break;
}
}
F_41 ( V_90 ) ;
V_79:
return V_55 ;
}
int F_44 ( const char * V_89 , char * V_98 ,
T_2 V_74 )
{
int V_90 , V_55 = - 1 ;
T_1 * V_1 ;
T_3 V_4 ;
T_7 V_20 ;
T_6 * V_75 ;
T_9 * V_24 ;
T_15 V_76 ;
V_90 = F_37 ( V_89 , V_91 ) ;
if ( V_90 < 0 )
goto V_79;
V_1 = F_38 ( V_90 , V_92 , NULL ) ;
if ( V_1 == NULL ) {
F_39 ( L_13 , V_71 , V_89 ) ;
goto V_93;
}
V_76 = F_32 ( V_1 ) ;
if ( V_76 != V_80 )
goto V_58;
if ( F_2 ( V_1 , & V_4 ) == NULL ) {
F_33 ( L_8 , V_71 ) ;
goto V_58;
}
V_24 = F_17 ( V_1 , & V_4 , & V_20 ,
L_14 , NULL ) ;
if ( V_24 == NULL )
goto V_58;
V_75 = F_22 ( V_24 , NULL ) ;
if ( V_75 == NULL )
goto V_58;
strncpy ( V_98 , V_75 -> V_19 , V_74 ) ;
V_58:
F_40 ( V_1 ) ;
V_93:
F_41 ( V_90 ) ;
V_79:
return V_55 ;
}
static int F_45 ( struct V_34 * V_34 , unsigned char V_99 )
{
static unsigned int const V_100 = 1 ;
V_34 -> V_101 = V_102 ;
switch ( V_99 ) {
case V_103 :
if ( * ( unsigned char const * ) & V_100 != 1 )
V_34 -> V_101 = V_104 ;
break;
case V_105 :
if ( * ( unsigned char const * ) & V_100 != 0 )
V_34 -> V_101 = V_104 ;
break;
default:
F_33 ( L_15 , V_99 ) ;
return - V_106 ;
}
return 0 ;
}
bool F_46 ( struct V_35 * V_36 )
{
return V_36 -> V_56 || V_36 -> V_107 ;
}
bool F_47 ( struct V_35 * V_36 )
{
return V_36 -> V_108 != NULL ;
}
void F_48 ( struct V_35 * V_36 )
{
free ( V_36 -> V_30 ) ;
F_40 ( V_36 -> V_1 ) ;
F_41 ( V_36 -> V_90 ) ;
}
int F_49 ( struct V_35 * V_36 , struct V_34 * V_34 , const char * V_30 ,
enum V_109 type )
{
int V_55 = - 1 ;
T_3 V_4 ;
T_1 * V_1 ;
int V_90 ;
V_90 = F_37 ( V_30 , V_91 ) ;
if ( V_90 < 0 )
return - 1 ;
V_1 = F_38 ( V_90 , V_92 , NULL ) ;
if ( V_1 == NULL ) {
F_30 ( L_13 , V_71 , V_30 ) ;
goto V_93;
}
if ( F_2 ( V_1 , & V_4 ) == NULL ) {
F_30 ( L_8 , V_71 ) ;
goto V_58;
}
if ( F_45 ( V_34 , V_4 . V_110 [ V_111 ] ) )
goto V_58;
if ( V_34 -> V_112 ) {
T_17 V_94 [ V_78 ] ;
if ( F_31 ( V_1 , V_94 , V_78 ) < 0 )
goto V_58;
if ( ! F_50 ( V_34 , V_94 ) )
goto V_58;
}
V_36 -> V_108 = F_17 ( V_1 , & V_4 , & V_36 -> V_113 , L_16 ,
NULL ) ;
if ( V_36 -> V_113 . V_63 != V_114 )
V_36 -> V_108 = NULL ;
V_36 -> V_51 = 0 ;
V_36 -> V_56 = F_17 ( V_1 , & V_4 , & V_36 -> V_57 , L_17 ,
& V_36 -> V_51 ) ;
if ( V_36 -> V_57 . V_63 != V_115 )
V_36 -> V_56 = NULL ;
V_36 -> V_116 = 0 ;
V_36 -> V_107 = F_17 ( V_1 , & V_4 , & V_36 -> V_117 , L_18 ,
& V_36 -> V_116 ) ;
if ( V_36 -> V_117 . V_63 != V_118 )
V_36 -> V_107 = NULL ;
if ( V_34 -> V_119 == V_120 ) {
T_7 V_20 ;
V_36 -> V_121 = ( V_4 . V_122 == V_123 ||
V_4 . V_122 == V_124 ||
F_17 ( V_1 , & V_4 , & V_20 ,
L_19 ,
NULL ) != NULL ) ;
} else {
V_36 -> V_121 = V_4 . V_122 == V_123 ||
V_4 . V_122 == V_124 ;
}
V_36 -> V_30 = F_51 ( V_30 ) ;
if ( ! V_36 -> V_30 )
goto V_58;
V_36 -> V_1 = V_1 ;
V_36 -> V_90 = V_90 ;
V_36 -> V_4 = V_4 ;
V_36 -> type = type ;
return 0 ;
V_58:
F_40 ( V_1 ) ;
V_93:
F_41 ( V_90 ) ;
return V_55 ;
}
static bool F_52 ( struct V_125 * V_125 )
{
return V_125 && V_125 -> V_126 && V_125 -> V_126 -> V_30 &&
! V_125 -> V_126 -> V_127 ;
}
static T_12 F_53 ( struct V_125 * V_125 )
{
if ( V_125 && V_125 -> V_126 &&
V_125 -> V_126 -> V_127 )
return V_125 -> V_126 -> V_23 -
V_125 -> V_126 -> V_127 ;
return 0 ;
}
int F_54 ( struct V_34 * V_34 , struct V_37 * V_37 ,
struct V_35 * V_128 , struct V_35 * V_129 ,
T_10 V_38 , int V_130 )
{
struct V_125 * V_125 = V_34 -> V_119 ? F_55 ( V_37 ) : NULL ;
struct V_37 * V_131 = V_37 ;
struct V_34 * V_132 = V_34 ;
T_6 * V_18 , * V_21 ;
T_11 V_133 ;
int V_55 = - 1 ;
T_11 V_31 ;
T_3 V_4 ;
T_7 V_20 ;
T_6 * V_47 , * V_134 = NULL ;
T_5 V_6 ;
T_9 * V_24 , * V_135 ;
T_1 * V_1 ;
int V_53 = 0 ;
bool V_136 = false , V_137 = false ;
V_34 -> V_138 = V_128 -> type ;
V_34 -> V_139 = V_128 -> V_4 . V_122 == V_124 ;
if ( V_130 && V_128 -> V_108 )
F_56 ( & V_34 -> V_69 [ V_37 -> type ] ) ;
if ( ! V_128 -> V_108 ) {
V_128 -> V_108 = V_128 -> V_56 ;
V_128 -> V_113 = V_128 -> V_57 ;
}
V_1 = V_128 -> V_1 ;
V_4 = V_128 -> V_4 ;
V_24 = V_128 -> V_108 ;
V_20 = V_128 -> V_113 ;
if ( V_129 -> V_107 )
V_134 = F_18 ( V_129 -> V_107 , NULL ) ;
V_47 = F_22 ( V_24 , NULL ) ;
if ( V_47 == NULL )
goto V_58;
V_24 = F_19 ( V_1 , V_20 . V_59 ) ;
if ( V_24 == NULL )
goto V_58;
V_18 = F_22 ( V_24 , NULL ) ;
if ( V_18 == NULL )
goto V_58;
V_135 = F_19 ( V_1 , V_4 . V_32 ) ;
if ( V_135 == NULL )
goto V_58;
V_21 = F_22 ( V_135 , NULL ) ;
if ( V_21 == NULL )
goto V_58;
V_133 = V_20 . V_27 / V_20 . V_61 ;
memset ( & V_6 , 0 , sizeof( V_6 ) ) ;
if ( F_52 ( V_125 ) ) {
F_57 (syms, nr_syms, idx, sym) {
const char * V_140 = F_9 ( & V_6 , V_18 ) ;
if ( strcmp ( V_140 , V_125 -> V_126 -> V_30 ) )
continue;
V_125 -> V_126 -> V_127 = V_6 . V_141 ;
break;
}
}
V_34 -> V_121 = V_129 -> V_121 || F_53 ( V_125 ) ;
if ( V_37 -> type == V_16 && ( V_34 -> V_119 || V_130 ) ) {
V_136 = true ;
V_137 = V_34 -> V_121 ;
}
F_57 (syms, nr_syms, idx, sym) {
struct V_42 * V_43 ;
const char * V_140 = F_9 ( & V_6 , V_18 ) ;
char * V_142 = NULL ;
int V_143 = F_7 ( & V_6 ) ;
const char * V_144 ;
bool V_145 = false ;
if ( ! V_143 && ! F_8 ( & V_6 , V_37 -> type ) )
continue;
if ( V_4 . V_146 == V_147 ) {
if ( ! strcmp ( V_140 , L_20 ) ||
! strcmp ( V_140 , L_21 ) ||
! strcmp ( V_140 , L_22 ) )
continue;
}
if ( V_129 -> V_107 && V_6 . V_10 == V_129 -> V_116 ) {
T_18 V_148 = V_6 . V_141 - V_128 -> V_117 . V_26 ;
T_12 * V_149 = V_134 -> V_19 + V_148 ;
V_6 . V_141 = F_58 ( V_34 , T_12 , * V_149 ) ;
V_6 . V_10 = F_14 ( V_129 -> V_1 ,
V_6 . V_141 ) ;
V_145 = true ;
}
if ( V_6 . V_10 == V_14 )
continue;
V_24 = F_19 ( V_129 -> V_1 , V_6 . V_10 ) ;
if ( ! V_24 )
goto V_58;
F_16 ( V_24 , & V_20 ) ;
if ( V_143 && ! F_13 ( & V_20 , V_21 , V_37 -> type ) )
continue;
V_144 = F_10 ( & V_20 , V_21 ) ;
if ( ( V_4 . V_146 == V_147 ) &&
( V_37 -> type == V_16 ) &&
( V_6 . V_141 & 1 ) )
-- V_6 . V_141 ;
if ( V_34 -> V_119 || V_130 ) {
char V_150 [ V_151 ] ;
if ( V_137 )
V_6 . V_141 -= V_20 . V_26 - V_20 . V_62 ;
if ( strcmp ( V_144 ,
( V_132 -> V_152 +
V_34 -> V_153 ) ) == 0 )
goto V_154;
if ( strcmp ( V_144 , L_23 ) == 0 ) {
if ( V_136 && V_34 -> V_119 ) {
V_136 = false ;
V_37 -> V_155 = V_20 . V_26 +
F_53 ( V_125 ) ;
V_37 -> V_156 = V_37 -> V_155 + V_20 . V_27 ;
V_37 -> V_157 = V_20 . V_62 ;
V_37 -> V_158 = V_159 ;
V_37 -> V_160 = V_161 ;
F_59 ( V_125 -> V_162 , V_37 ) ;
F_60 ( V_125 -> V_162 , V_37 ) ;
}
if ( V_136 && V_130 ) {
V_136 = false ;
V_37 -> V_157 = V_20 . V_62 ;
}
V_131 = V_37 ;
V_132 = V_34 ;
goto V_154;
}
if ( ! V_125 )
goto V_154;
snprintf ( V_150 , sizeof( V_150 ) ,
L_24 , V_34 -> V_152 , V_144 ) ;
V_131 = F_61 ( V_125 -> V_162 , V_37 -> type , V_150 ) ;
if ( V_131 == NULL ) {
T_12 V_155 = V_6 . V_141 ;
if ( V_130 )
V_155 += V_37 -> V_155 + V_20 . V_62 ;
V_132 = F_62 ( V_150 ) ;
if ( V_132 == NULL )
goto V_58;
V_132 -> V_119 = V_34 -> V_119 ;
V_132 -> V_72 = V_34 -> V_72 ;
V_132 -> V_163 = V_34 -> V_163 ;
V_131 = F_63 ( V_155 , V_132 ,
V_37 -> type ) ;
if ( V_131 == NULL ) {
F_64 ( V_132 ) ;
goto V_58;
}
if ( V_137 ) {
V_131 -> V_155 = V_20 . V_26 +
F_53 ( V_125 ) ;
V_131 -> V_156 = V_131 -> V_155 +
V_20 . V_27 ;
V_131 -> V_157 = V_20 . V_62 ;
} else {
V_131 -> V_158 = V_164 ;
V_131 -> V_160 = V_164 ;
}
V_132 -> V_138 = V_34 -> V_138 ;
F_60 ( V_125 -> V_162 , V_131 ) ;
F_65 ( & V_34 -> V_165 , V_132 ) ;
F_66 ( V_132 , V_37 -> type ) ;
} else
V_132 = V_131 -> V_34 ;
goto V_154;
}
if ( ( V_145 && V_129 -> V_121 )
|| ( ! V_145 && V_128 -> V_121 ) ) {
F_67 ( L_25 V_166 L_26
L_27 V_166 L_28 V_166 L_29 , V_71 ,
( T_12 ) V_6 . V_141 , ( T_12 ) V_20 . V_26 ,
( T_12 ) V_20 . V_62 ) ;
V_6 . V_141 -= V_20 . V_26 - V_20 . V_62 ;
}
if ( V_167 . V_168 ) {
V_142 = F_68 ( NULL , V_140 ,
V_169 | V_170 ) ;
if ( V_142 != NULL )
V_140 = V_142 ;
}
V_154:
V_43 = F_26 ( V_6 . V_141 , V_6 . V_171 ,
F_69 ( V_6 . V_7 ) , V_140 ) ;
free ( V_142 ) ;
if ( ! V_43 )
goto V_58;
if ( V_38 && V_38 ( V_131 , V_43 ) )
F_27 ( V_43 ) ;
else {
F_28 ( & V_132 -> V_69 [ V_131 -> type ] , V_43 ) ;
V_53 ++ ;
}
}
if ( V_53 > 0 ) {
F_70 ( & V_34 -> V_69 [ V_37 -> type ] ) ;
F_71 ( & V_34 -> V_69 [ V_37 -> type ] ) ;
if ( V_125 ) {
F_72 ( V_125 -> V_162 , V_37 -> type ) ;
}
}
V_55 = V_53 ;
V_58:
return V_55 ;
}
static int F_73 ( T_1 * V_1 , bool V_172 , T_19 V_173 , void * V_75 )
{
T_20 V_174 ;
T_2 V_175 , V_176 ;
int V_55 ;
T_12 V_88 ;
if ( F_1 ( V_1 , & V_176 ) )
return - 1 ;
for ( V_175 = 0 ; V_175 < V_176 ; V_175 ++ ) {
if ( F_74 ( V_1 , V_175 , & V_174 ) == NULL )
return - 1 ;
if ( V_174 . V_177 != V_178 )
continue;
if ( V_172 ) {
if ( ! ( V_174 . V_179 & V_180 ) )
continue;
} else {
if ( ! ( V_174 . V_179 & V_181 ) )
continue;
}
V_88 = F_35 ( V_174 . V_182 , V_174 . V_183 ) ;
if ( ! V_88 )
continue;
V_55 = V_173 ( V_174 . V_184 , V_88 , V_174 . V_185 , V_75 ) ;
if ( V_55 )
return V_55 ;
}
return 0 ;
}
int F_75 ( int V_90 , bool V_172 , T_19 V_173 , void * V_75 ,
bool * V_186 )
{
int V_55 ;
T_1 * V_1 ;
V_1 = F_38 ( V_90 , V_92 , NULL ) ;
if ( V_1 == NULL )
return - 1 ;
if ( V_186 )
* V_186 = ( F_76 ( V_1 ) == V_187 ) ;
V_55 = F_73 ( V_1 , V_172 , V_173 , V_75 ) ;
F_40 ( V_1 ) ;
return V_55 ;
}
static int F_77 ( int V_188 , T_21 V_189 , int V_190 , T_21 V_191 , T_12 V_192 )
{
V_96 V_193 ;
T_2 V_97 ;
int V_55 = - 1 ;
char * V_194 = malloc ( V_195 ) ;
if ( V_194 == NULL )
return - 1 ;
if ( F_78 ( V_190 , V_191 , V_196 ) != V_191 )
goto V_79;
if ( F_78 ( V_188 , V_189 , V_196 ) != V_189 )
goto V_79;
while ( V_192 ) {
V_97 = V_195 ;
if ( V_192 < V_97 )
V_97 = V_192 ;
V_193 = F_43 ( V_188 , V_194 , V_97 ) ;
if ( V_193 < 0 )
goto V_79;
if ( ! V_193 )
break;
V_97 = V_193 ;
V_193 = F_79 ( V_190 , V_194 , V_97 ) ;
if ( V_193 < 0 )
goto V_79;
if ( ( T_2 ) V_193 != V_97 )
goto V_79;
V_192 -= V_97 ;
}
V_55 = 0 ;
V_79:
free ( V_194 ) ;
return V_55 ;
}
static int F_80 ( struct V_197 * V_197 , const char * V_89 )
{
T_3 * V_4 ;
V_197 -> V_90 = F_37 ( V_89 , V_91 ) ;
if ( V_197 -> V_90 == - 1 )
return - 1 ;
V_197 -> V_1 = F_38 ( V_197 -> V_90 , V_198 , NULL ) ;
if ( ! V_197 -> V_1 )
goto V_93;
V_197 -> V_199 = F_76 ( V_197 -> V_1 ) ;
if ( V_197 -> V_199 == V_200 )
goto V_201;
V_4 = F_2 ( V_197 -> V_1 , & V_197 -> V_4 ) ;
if ( ! V_4 )
goto V_201;
return 0 ;
V_201:
F_40 ( V_197 -> V_1 ) ;
V_93:
F_41 ( V_197 -> V_90 ) ;
return - 1 ;
}
static int F_81 ( struct V_197 * V_197 , char * V_89 , int V_199 ,
bool V_202 )
{
T_3 * V_4 ;
V_197 -> V_199 = V_199 ;
if ( V_202 )
V_197 -> V_90 = F_82 ( V_89 ) ;
else
V_197 -> V_90 = F_37 ( V_89 , V_203 | V_204 | V_205 , 0400 ) ;
if ( V_197 -> V_90 == - 1 )
return - 1 ;
V_197 -> V_1 = F_38 ( V_197 -> V_90 , V_206 , NULL ) ;
if ( ! V_197 -> V_1 )
goto V_93;
if ( ! F_83 ( V_197 -> V_1 , V_199 ) )
goto V_201;
V_4 = F_2 ( V_197 -> V_1 , & V_197 -> V_4 ) ;
if ( ! V_4 )
goto V_201;
return 0 ;
V_201:
F_40 ( V_197 -> V_1 ) ;
V_93:
F_41 ( V_197 -> V_90 ) ;
F_84 ( V_89 ) ;
return - 1 ;
}
static void F_85 ( struct V_197 * V_197 )
{
F_40 ( V_197 -> V_1 ) ;
F_41 ( V_197 -> V_90 ) ;
}
static int F_86 ( struct V_197 * V_188 , struct V_197 * V_190 , T_2 V_207 )
{
T_3 * V_4 = & V_190 -> V_4 ;
T_3 * V_208 = & V_188 -> V_4 ;
memcpy ( V_4 -> V_110 , V_208 -> V_110 , V_209 ) ;
V_4 -> V_122 = V_208 -> V_122 ;
V_4 -> V_146 = V_208 -> V_146 ;
V_4 -> V_210 = V_208 -> V_210 ;
V_4 -> V_211 = 0 ;
V_4 -> V_212 = 0 ;
V_4 -> V_213 = V_208 -> V_213 ;
V_4 -> V_5 = V_207 ;
V_4 -> V_214 = 0 ;
V_4 -> V_215 = 0 ;
V_4 -> V_32 = 0 ;
if ( V_188 -> V_199 == V_216 ) {
V_4 -> V_217 = sizeof( V_218 ) ;
V_4 -> V_219 = sizeof( V_218 ) ;
V_4 -> V_220 = sizeof( V_221 ) ;
} else {
V_4 -> V_217 = sizeof( V_222 ) ;
V_4 -> V_219 = sizeof( V_222 ) ;
V_4 -> V_220 = sizeof( V_223 ) ;
}
if ( ! F_87 ( V_190 -> V_1 , V_4 ) )
return - 1 ;
if ( ! F_88 ( V_190 -> V_1 , V_207 ) )
return - 1 ;
return 0 ;
}
static int F_89 ( struct V_197 * V_197 , int V_31 , T_21 V_148 ,
T_12 V_23 , T_12 V_192 )
{
T_20 V_224 ;
T_20 * V_174 ;
V_174 = F_74 ( V_197 -> V_1 , V_31 , & V_224 ) ;
if ( ! V_174 )
return - 1 ;
V_174 -> V_177 = V_178 ;
V_174 -> V_179 = V_181 | V_225 | V_180 ;
V_174 -> V_185 = V_148 ;
V_174 -> V_184 = V_23 ;
V_174 -> V_226 = 0 ;
V_174 -> V_183 = V_192 ;
V_174 -> V_182 = V_192 ;
V_174 -> V_227 = V_195 ;
if ( ! F_90 ( V_197 -> V_1 , V_31 , V_174 ) )
return - 1 ;
return 0 ;
}
static T_21 F_91 ( struct V_197 * V_197 )
{
return F_92 ( V_197 -> V_1 , V_206 ) ;
}
static int F_93 ( void * V_228 , const char * V_30 , char type ,
T_12 V_155 )
{
struct V_229 * V_230 = V_228 ;
if ( ! F_94 ( type , V_16 ) )
return 0 ;
if ( strchr ( V_30 , '[' ) ) {
if ( V_155 > V_230 -> V_231 )
V_230 -> V_231 = V_155 ;
return 0 ;
}
if ( ! V_230 -> V_232 || V_155 < V_230 -> V_232 )
V_230 -> V_232 = V_155 ;
if ( ! V_230 -> V_233 || V_155 > V_230 -> V_233 )
V_230 -> V_233 = V_155 ;
if ( ! strcmp ( V_30 , L_30 ) ) {
V_230 -> V_234 = V_155 ;
return 0 ;
}
if ( ! strcmp ( V_30 , L_31 ) ) {
V_230 -> V_235 = V_155 ;
return 0 ;
}
return 0 ;
}
static int F_95 ( struct V_229 * V_230 ,
const char * V_236 )
{
char V_237 [ V_151 ] ;
F_96 ( V_237 , V_151 , L_32 , V_236 ) ;
if ( F_97 ( V_237 , L_33 ) )
return - 1 ;
if ( F_98 ( V_237 , V_230 ,
F_93 ) < 0 )
return - 1 ;
return 0 ;
}
static int F_99 ( void * V_228 ,
const char * V_30 V_238 ,
T_12 V_155 )
{
struct V_229 * V_230 = V_228 ;
if ( ! V_230 -> V_239 || V_155 < V_230 -> V_239 )
V_230 -> V_239 = V_155 ;
return 0 ;
}
static int F_100 ( struct V_229 * V_230 ,
const char * V_236 )
{
char V_240 [ V_151 ] ;
F_96 ( V_240 , V_151 , L_34 , V_236 ) ;
if ( F_97 ( V_240 , L_35 ) )
return - 1 ;
if ( F_101 ( V_240 , V_230 ,
F_99 ) < 0 )
return - 1 ;
return 0 ;
}
static void F_102 ( struct V_241 * V_242 , T_12 V_155 , T_12 V_156 , T_12 V_157 ,
T_12 V_243 , T_12 V_244 )
{
if ( V_242 -> V_23 || V_243 < V_155 || V_243 >= V_156 )
return;
V_242 -> V_23 = V_243 ;
V_242 -> V_148 = ( V_243 - V_155 ) + V_157 ;
V_242 -> V_192 = V_244 < V_156 ? V_244 - V_243 : V_156 - V_243 ;
}
static int F_103 ( T_12 V_155 , T_12 V_192 , T_12 V_157 , void * V_75 )
{
struct V_229 * V_230 = V_75 ;
T_12 V_156 = V_155 + V_192 ;
F_102 ( & V_230 -> V_245 , V_155 , V_156 , V_157 , V_230 -> V_234 ,
V_230 -> V_235 ) ;
F_102 ( & V_230 -> V_246 , V_155 , V_156 , V_157 , V_230 -> V_239 ,
V_230 -> V_231 ) ;
return 0 ;
}
static int F_104 ( struct V_229 * V_230 , T_1 * V_1 )
{
if ( F_73 ( V_1 , true , F_103 , V_230 ) < 0 )
return - 1 ;
return 0 ;
}
static int F_105 ( struct V_229 * V_230 , const char * V_236 ,
T_1 * V_1 )
{
if ( F_95 ( V_230 , V_236 ) )
return - 1 ;
if ( F_100 ( V_230 , V_236 ) )
return - 1 ;
if ( V_230 -> V_234 )
V_230 -> V_234 = F_106 ( V_230 -> V_234 , V_195 ) ;
else
V_230 -> V_234 = F_106 ( V_230 -> V_232 , V_195 ) ;
if ( V_230 -> V_235 ) {
V_230 -> V_235 = F_107 ( V_230 -> V_235 , V_195 ) ;
} else if ( V_230 -> V_233 ) {
V_230 -> V_235 = F_107 ( V_230 -> V_233 , V_195 ) ;
V_230 -> V_235 += V_195 ;
}
V_230 -> V_239 = F_106 ( V_230 -> V_239 , V_195 ) ;
if ( V_230 -> V_231 ) {
V_230 -> V_231 = F_107 ( V_230 -> V_231 ,
V_195 ) ;
V_230 -> V_231 += V_195 ;
}
if ( ! V_230 -> V_234 || ! V_230 -> V_235 )
return - 1 ;
if ( V_230 -> V_239 && ! V_230 -> V_231 )
return - 1 ;
return F_104 ( V_230 , V_1 ) ;
}
static int F_108 ( const char * V_247 , const char * V_248 ,
const char * V_30 )
{
char V_249 [ V_151 ] ;
char V_250 [ V_151 ] ;
F_96 ( V_249 , V_151 , L_36 , V_247 , V_30 ) ;
F_96 ( V_250 , V_151 , L_36 , V_248 , V_30 ) ;
return F_109 ( V_249 , V_250 , 0400 ) ;
}
static int F_110 ( const char * V_236 , const char * V_30 )
{
char V_89 [ V_151 ] ;
F_96 ( V_89 , V_151 , L_36 , V_236 , V_30 ) ;
return F_84 ( V_89 ) ;
}
static int F_111 ( int V_188 , int V_190 )
{
char * V_251 ;
char * V_252 ;
V_96 V_253 ;
T_2 V_192 ;
int V_55 = - 1 ;
V_251 = malloc ( V_195 ) ;
V_252 = malloc ( V_195 ) ;
if ( ! V_251 || ! V_252 )
goto V_79;
while ( 1 ) {
V_253 = F_43 ( V_188 , V_251 , V_195 ) ;
if ( V_253 < 0 )
goto V_79;
if ( ! V_253 )
break;
V_192 = V_253 ;
if ( F_112 ( V_190 , V_252 , V_192 ) != ( int ) V_192 )
goto V_79;
if ( memcmp ( V_251 , V_252 , V_192 ) )
goto V_79;
}
V_55 = 0 ;
V_79:
free ( V_252 ) ;
free ( V_251 ) ;
return V_55 ;
}
static int F_113 ( const char * V_249 ,
const char * V_250 )
{
int V_188 , V_190 , V_55 = - 1 ;
V_188 = F_37 ( V_249 , V_91 ) ;
if ( V_188 < 0 )
return - 1 ;
V_190 = F_37 ( V_250 , V_91 ) ;
if ( V_190 < 0 )
goto V_254;
V_55 = F_111 ( V_188 , V_190 ) ;
F_41 ( V_190 ) ;
V_254:
F_41 ( V_188 ) ;
return V_55 ;
}
static int F_114 ( const char * V_247 , const char * V_248 ,
const char * V_30 )
{
char V_249 [ V_151 ] ;
char V_250 [ V_151 ] ;
F_96 ( V_249 , V_151 , L_36 , V_247 , V_30 ) ;
F_96 ( V_250 , V_151 , L_36 , V_248 , V_30 ) ;
return F_113 ( V_249 , V_250 ) ;
}
int F_115 ( const char * V_247 , const char * V_248 )
{
struct V_197 V_197 ;
struct V_197 V_255 ;
T_2 V_207 = 2 ;
int V_31 = 0 , V_55 = - 1 ;
T_21 V_148 = V_195 , V_88 , V_256 = 0 ;
struct V_229 V_230 = { . V_234 = 0 , } ;
char V_257 [ V_151 ] ;
char V_258 [ V_151 ] ;
if ( F_108 ( V_247 , V_248 , L_37 ) )
return - 1 ;
if ( F_108 ( V_247 , V_248 , L_38 ) )
goto V_259;
F_96 ( V_257 , V_151 , L_39 , V_247 ) ;
F_96 ( V_258 , V_151 , L_39 , V_248 ) ;
if ( F_80 ( & V_197 , V_257 ) )
goto V_260;
if ( F_105 ( & V_230 , V_247 , V_197 . V_1 ) )
goto V_261;
if ( F_81 ( & V_255 , V_258 , V_197 . V_199 , false ) )
goto V_261;
if ( ! V_230 . V_246 . V_23 )
V_207 -= 1 ;
if ( F_86 ( & V_197 , & V_255 , V_207 ) )
goto V_262;
if ( F_89 ( & V_255 , V_31 ++ , V_148 , V_230 . V_245 . V_23 ,
V_230 . V_245 . V_192 ) )
goto V_262;
if ( V_230 . V_246 . V_23 ) {
V_256 = V_148 + V_230 . V_245 . V_192 ;
if ( F_89 ( & V_255 , V_31 , V_256 ,
V_230 . V_246 . V_23 , V_230 . V_246 . V_192 ) )
goto V_262;
}
V_88 = F_91 ( & V_255 ) ;
if ( V_88 < 0 || V_88 > V_148 )
goto V_262;
if ( F_77 ( V_197 . V_90 , V_230 . V_245 . V_148 , V_255 . V_90 , V_148 ,
V_230 . V_245 . V_192 ) )
goto V_262;
if ( V_256 && F_77 ( V_197 . V_90 , V_230 . V_246 . V_148 ,
V_255 . V_90 , V_256 ,
V_230 . V_246 . V_192 ) )
goto V_262;
if ( F_114 ( V_247 , V_248 , L_38 ) )
goto V_262;
if ( F_114 ( V_247 , V_248 , L_37 ) )
goto V_262;
V_55 = 0 ;
V_262:
F_85 ( & V_255 ) ;
if ( V_55 )
F_84 ( V_258 ) ;
V_261:
F_85 ( & V_197 ) ;
V_260:
if ( V_55 )
F_110 ( V_248 , L_38 ) ;
V_259:
if ( V_55 )
F_110 ( V_248 , L_37 ) ;
return V_55 ;
}
int F_116 ( struct V_263 * V_264 )
{
struct V_197 V_197 ;
struct V_197 V_255 ;
T_2 V_207 = 1 ;
int V_31 = 0 , V_55 = - 1 ;
T_21 V_148 = V_195 , V_88 ;
if ( F_80 ( & V_197 , V_264 -> V_257 ) )
return - 1 ;
strcpy ( V_264 -> V_258 , V_265 ) ;
if ( F_81 ( & V_255 , V_264 -> V_258 , V_197 . V_199 , true ) )
goto V_261;
if ( F_86 ( & V_197 , & V_255 , V_207 ) )
goto V_262;
if ( F_89 ( & V_255 , V_31 , V_148 , V_264 -> V_23 , V_264 -> V_192 ) )
goto V_262;
V_88 = F_91 ( & V_255 ) ;
if ( V_88 < 0 || V_88 > V_148 )
goto V_262;
if ( F_77 ( V_197 . V_90 , V_264 -> V_266 , V_255 . V_90 , V_148 , V_264 -> V_192 ) )
goto V_262;
V_55 = 0 ;
V_262:
F_85 ( & V_255 ) ;
if ( V_55 )
F_84 ( V_264 -> V_258 ) ;
V_261:
F_85 ( & V_197 ) ;
return V_55 ;
}
void F_117 ( struct V_263 * V_264 )
{
F_84 ( V_264 -> V_258 ) ;
}
void F_118 ( void )
{
F_119 ( V_267 ) ;
}
