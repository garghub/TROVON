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
T_9 * F_17 ( T_1 * V_1 , T_3 * V_28 ,
T_7 * V_29 , const char * V_30 , T_2 * V_31 )
{
T_9 * V_24 = NULL ;
T_2 V_25 = 1 ;
if ( ! F_18 ( F_19 ( V_1 , V_28 -> V_32 ) , NULL ) )
return NULL ;
while ( ( V_24 = F_15 ( V_1 , V_24 ) ) != NULL ) {
char * V_33 ;
F_16 ( V_24 , V_29 ) ;
V_33 = F_20 ( V_1 , V_28 -> V_32 , V_29 -> V_22 ) ;
if ( V_33 && ! strcmp ( V_30 , V_33 ) ) {
if ( V_31 )
* V_31 = V_25 ;
return V_24 ;
}
++ V_25 ;
}
return NULL ;
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
F_49 ( & V_36 -> V_30 ) ;
F_40 ( V_36 -> V_1 ) ;
F_41 ( V_36 -> V_90 ) ;
}
int F_50 ( struct V_35 * V_36 , struct V_34 * V_34 , const char * V_30 ,
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
if ( ! F_51 ( V_34 , V_94 ) )
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
V_36 -> V_30 = F_52 ( V_30 ) ;
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
static bool F_53 ( struct V_125 * V_125 )
{
return V_125 && V_125 -> V_126 && V_125 -> V_126 -> V_30 &&
! V_125 -> V_126 -> V_127 ;
}
static T_12 F_54 ( struct V_125 * V_125 )
{
if ( V_125 && V_125 -> V_126 &&
V_125 -> V_126 -> V_127 )
return V_125 -> V_126 -> V_23 -
V_125 -> V_126 -> V_127 ;
return 0 ;
}
int F_55 ( struct V_34 * V_34 , struct V_37 * V_37 ,
struct V_35 * V_128 , struct V_35 * V_129 ,
T_10 V_38 , int V_130 )
{
struct V_125 * V_125 = V_34 -> V_119 ? F_56 ( V_37 ) : NULL ;
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
F_57 ( & V_34 -> V_69 [ V_37 -> type ] ) ;
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
if ( F_53 ( V_125 ) ) {
F_58 (syms, nr_syms, idx, sym) {
const char * V_140 = F_9 ( & V_6 , V_18 ) ;
if ( strcmp ( V_140 , V_125 -> V_126 -> V_30 ) )
continue;
V_125 -> V_126 -> V_127 = V_6 . V_141 ;
V_37 -> V_142 = V_125 -> V_126 -> V_23 -
V_125 -> V_126 -> V_127 ;
break;
}
}
V_34 -> V_121 = V_129 -> V_121 || F_54 ( V_125 ) ;
if ( V_37 -> type == V_16 && ( V_34 -> V_119 || V_130 ) ) {
V_136 = true ;
V_137 = V_34 -> V_121 ;
}
F_58 (syms, nr_syms, idx, sym) {
struct V_42 * V_43 ;
const char * V_140 = F_9 ( & V_6 , V_18 ) ;
char * V_143 = NULL ;
int V_144 = F_7 ( & V_6 ) ;
const char * V_145 ;
bool V_146 = false ;
if ( ! V_144 && ! F_8 ( & V_6 , V_37 -> type ) )
continue;
if ( V_4 . V_147 == V_148 ) {
if ( ! strcmp ( V_140 , L_20 ) ||
! strcmp ( V_140 , L_21 ) ||
! strcmp ( V_140 , L_22 ) )
continue;
}
if ( V_129 -> V_107 && V_6 . V_10 == V_129 -> V_116 ) {
T_18 V_149 = V_6 . V_141 - V_128 -> V_117 . V_26 ;
T_12 * V_150 = V_134 -> V_19 + V_149 ;
V_6 . V_141 = F_59 ( V_34 , T_12 , * V_150 ) ;
V_6 . V_10 = F_14 ( V_129 -> V_1 ,
V_6 . V_141 ) ;
V_146 = true ;
}
if ( V_6 . V_10 == V_14 )
continue;
V_24 = F_19 ( V_129 -> V_1 , V_6 . V_10 ) ;
if ( ! V_24 )
goto V_58;
F_16 ( V_24 , & V_20 ) ;
if ( V_144 && ! F_13 ( & V_20 , V_21 , V_37 -> type ) )
continue;
V_145 = F_10 ( & V_20 , V_21 ) ;
if ( ( V_4 . V_147 == V_148 ) &&
( V_37 -> type == V_16 ) &&
( V_6 . V_141 & 1 ) )
-- V_6 . V_141 ;
if ( V_34 -> V_119 || V_130 ) {
char V_151 [ V_152 ] ;
if ( V_137 )
V_6 . V_141 -= V_20 . V_26 - V_20 . V_62 ;
if ( strcmp ( V_145 ,
( V_132 -> V_153 +
V_34 -> V_154 ) ) == 0 )
goto V_155;
if ( strcmp ( V_145 , L_23 ) == 0 ) {
if ( V_136 && V_34 -> V_119 ) {
V_136 = false ;
V_37 -> V_156 = V_20 . V_26 +
F_54 ( V_125 ) ;
V_37 -> V_157 = V_37 -> V_156 + V_20 . V_27 ;
V_37 -> V_158 = V_20 . V_62 ;
V_37 -> V_159 = V_160 ;
V_37 -> V_161 = V_162 ;
F_60 ( V_125 -> V_163 , V_37 ) ;
F_61 ( V_125 -> V_163 , V_37 ) ;
}
if ( V_136 && V_130 ) {
V_136 = false ;
V_37 -> V_158 = V_20 . V_62 ;
}
V_131 = V_37 ;
V_132 = V_34 ;
goto V_155;
}
if ( ! V_125 )
goto V_155;
snprintf ( V_151 , sizeof( V_151 ) ,
L_24 , V_34 -> V_153 , V_145 ) ;
V_131 = F_62 ( V_125 -> V_163 , V_37 -> type , V_151 ) ;
if ( V_131 == NULL ) {
T_12 V_156 = V_6 . V_141 ;
if ( V_130 )
V_156 += V_37 -> V_156 + V_20 . V_62 ;
V_132 = F_63 ( V_151 ) ;
if ( V_132 == NULL )
goto V_58;
V_132 -> V_119 = V_34 -> V_119 ;
V_132 -> V_72 = V_34 -> V_72 ;
V_132 -> V_164 = V_34 -> V_164 ;
V_131 = F_64 ( V_156 , V_132 ,
V_37 -> type ) ;
if ( V_131 == NULL ) {
F_65 ( V_132 ) ;
goto V_58;
}
if ( V_137 ) {
V_131 -> V_156 = V_20 . V_26 +
F_54 ( V_125 ) ;
V_131 -> V_157 = V_131 -> V_156 +
V_20 . V_27 ;
V_131 -> V_158 = V_20 . V_62 ;
} else {
V_131 -> V_159 = V_165 ;
V_131 -> V_161 = V_165 ;
}
V_132 -> V_138 = V_34 -> V_138 ;
F_61 ( V_125 -> V_163 , V_131 ) ;
F_66 ( & V_34 -> V_166 , V_132 ) ;
F_67 ( V_132 , V_37 -> type ) ;
} else
V_132 = V_131 -> V_34 ;
goto V_155;
}
if ( ( V_146 && V_129 -> V_121 )
|| ( ! V_146 && V_128 -> V_121 ) ) {
F_68 ( L_25 V_167 L_26
L_27 V_167 L_28 V_167 L_29 , V_71 ,
( T_12 ) V_6 . V_141 , ( T_12 ) V_20 . V_26 ,
( T_12 ) V_20 . V_62 ) ;
V_6 . V_141 -= V_20 . V_26 - V_20 . V_62 ;
}
V_155:
if ( V_168 . V_169 ) {
V_143 = F_69 ( NULL , V_140 ,
V_170 | V_171 ) ;
if ( V_143 != NULL )
V_140 = V_143 ;
}
V_43 = F_26 ( V_6 . V_141 , V_6 . V_172 ,
F_70 ( V_6 . V_7 ) , V_140 ) ;
free ( V_143 ) ;
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
F_71 ( & V_34 -> V_69 [ V_37 -> type ] ) ;
F_72 ( & V_34 -> V_69 [ V_37 -> type ] ) ;
if ( V_125 ) {
F_73 ( V_125 -> V_163 , V_37 -> type ) ;
}
}
V_55 = V_53 ;
V_58:
return V_55 ;
}
static int F_74 ( T_1 * V_1 , bool V_173 , T_19 V_174 , void * V_75 )
{
T_20 V_175 ;
T_2 V_176 , V_177 ;
int V_55 ;
T_12 V_88 ;
if ( F_1 ( V_1 , & V_177 ) )
return - 1 ;
for ( V_176 = 0 ; V_176 < V_177 ; V_176 ++ ) {
if ( F_75 ( V_1 , V_176 , & V_175 ) == NULL )
return - 1 ;
if ( V_175 . V_178 != V_179 )
continue;
if ( V_173 ) {
if ( ! ( V_175 . V_180 & V_181 ) )
continue;
} else {
if ( ! ( V_175 . V_180 & V_182 ) )
continue;
}
V_88 = F_35 ( V_175 . V_183 , V_175 . V_184 ) ;
if ( ! V_88 )
continue;
V_55 = V_174 ( V_175 . V_185 , V_88 , V_175 . V_186 , V_75 ) ;
if ( V_55 )
return V_55 ;
}
return 0 ;
}
int F_76 ( int V_90 , bool V_173 , T_19 V_174 , void * V_75 ,
bool * V_187 )
{
int V_55 ;
T_1 * V_1 ;
V_1 = F_38 ( V_90 , V_92 , NULL ) ;
if ( V_1 == NULL )
return - 1 ;
if ( V_187 )
* V_187 = ( F_77 ( V_1 ) == V_188 ) ;
V_55 = F_74 ( V_1 , V_173 , V_174 , V_75 ) ;
F_40 ( V_1 ) ;
return V_55 ;
}
static int F_78 ( int V_189 , T_21 V_190 , int V_191 , T_21 V_192 , T_12 V_193 )
{
V_96 V_194 ;
T_2 V_97 ;
int V_55 = - 1 ;
char * V_195 = malloc ( V_196 ) ;
if ( V_195 == NULL )
return - 1 ;
if ( F_79 ( V_191 , V_192 , V_197 ) != V_192 )
goto V_79;
if ( F_79 ( V_189 , V_190 , V_197 ) != V_190 )
goto V_79;
while ( V_193 ) {
V_97 = V_196 ;
if ( V_193 < V_97 )
V_97 = V_193 ;
V_194 = F_43 ( V_189 , V_195 , V_97 ) ;
if ( V_194 < 0 )
goto V_79;
if ( ! V_194 )
break;
V_97 = V_194 ;
V_194 = F_80 ( V_191 , V_195 , V_97 ) ;
if ( V_194 < 0 )
goto V_79;
if ( ( T_2 ) V_194 != V_97 )
goto V_79;
V_193 -= V_97 ;
}
V_55 = 0 ;
V_79:
free ( V_195 ) ;
return V_55 ;
}
static int F_81 ( struct V_198 * V_198 , const char * V_89 )
{
T_3 * V_4 ;
V_198 -> V_90 = F_37 ( V_89 , V_91 ) ;
if ( V_198 -> V_90 == - 1 )
return - 1 ;
V_198 -> V_1 = F_38 ( V_198 -> V_90 , V_199 , NULL ) ;
if ( ! V_198 -> V_1 )
goto V_93;
V_198 -> V_200 = F_77 ( V_198 -> V_1 ) ;
if ( V_198 -> V_200 == V_201 )
goto V_202;
V_4 = F_2 ( V_198 -> V_1 , & V_198 -> V_4 ) ;
if ( ! V_4 )
goto V_202;
return 0 ;
V_202:
F_40 ( V_198 -> V_1 ) ;
V_93:
F_41 ( V_198 -> V_90 ) ;
return - 1 ;
}
static int F_82 ( struct V_198 * V_198 , char * V_89 , int V_200 ,
bool V_203 )
{
T_3 * V_4 ;
V_198 -> V_200 = V_200 ;
if ( V_203 )
V_198 -> V_90 = F_83 ( V_89 ) ;
else
V_198 -> V_90 = F_37 ( V_89 , V_204 | V_205 | V_206 , 0400 ) ;
if ( V_198 -> V_90 == - 1 )
return - 1 ;
V_198 -> V_1 = F_38 ( V_198 -> V_90 , V_207 , NULL ) ;
if ( ! V_198 -> V_1 )
goto V_93;
if ( ! F_84 ( V_198 -> V_1 , V_200 ) )
goto V_202;
V_4 = F_2 ( V_198 -> V_1 , & V_198 -> V_4 ) ;
if ( ! V_4 )
goto V_202;
return 0 ;
V_202:
F_40 ( V_198 -> V_1 ) ;
V_93:
F_41 ( V_198 -> V_90 ) ;
F_85 ( V_89 ) ;
return - 1 ;
}
static void F_86 ( struct V_198 * V_198 )
{
F_40 ( V_198 -> V_1 ) ;
F_41 ( V_198 -> V_90 ) ;
}
static int F_87 ( struct V_198 * V_189 , struct V_198 * V_191 , T_2 V_208 )
{
T_3 * V_4 = & V_191 -> V_4 ;
T_3 * V_209 = & V_189 -> V_4 ;
memcpy ( V_4 -> V_110 , V_209 -> V_110 , V_210 ) ;
V_4 -> V_122 = V_209 -> V_122 ;
V_4 -> V_147 = V_209 -> V_147 ;
V_4 -> V_211 = V_209 -> V_211 ;
V_4 -> V_212 = 0 ;
V_4 -> V_213 = 0 ;
V_4 -> V_214 = V_209 -> V_214 ;
V_4 -> V_5 = V_208 ;
V_4 -> V_215 = 0 ;
V_4 -> V_216 = 0 ;
V_4 -> V_32 = 0 ;
if ( V_189 -> V_200 == V_217 ) {
V_4 -> V_218 = sizeof( V_219 ) ;
V_4 -> V_220 = sizeof( V_219 ) ;
V_4 -> V_221 = sizeof( V_222 ) ;
} else {
V_4 -> V_218 = sizeof( V_223 ) ;
V_4 -> V_220 = sizeof( V_223 ) ;
V_4 -> V_221 = sizeof( V_224 ) ;
}
if ( ! F_88 ( V_191 -> V_1 , V_4 ) )
return - 1 ;
if ( ! F_89 ( V_191 -> V_1 , V_208 ) )
return - 1 ;
return 0 ;
}
static int F_90 ( struct V_198 * V_198 , int V_31 , T_21 V_149 ,
T_12 V_23 , T_12 V_193 )
{
T_20 V_225 ;
T_20 * V_175 ;
V_175 = F_75 ( V_198 -> V_1 , V_31 , & V_225 ) ;
if ( ! V_175 )
return - 1 ;
V_175 -> V_178 = V_179 ;
V_175 -> V_180 = V_182 | V_226 | V_181 ;
V_175 -> V_186 = V_149 ;
V_175 -> V_185 = V_23 ;
V_175 -> V_227 = 0 ;
V_175 -> V_184 = V_193 ;
V_175 -> V_183 = V_193 ;
V_175 -> V_228 = V_196 ;
if ( ! F_91 ( V_198 -> V_1 , V_31 , V_175 ) )
return - 1 ;
return 0 ;
}
static T_21 F_92 ( struct V_198 * V_198 )
{
return F_93 ( V_198 -> V_1 , V_207 ) ;
}
static int F_94 ( void * V_229 , const char * V_30 , char type ,
T_12 V_156 )
{
struct V_230 * V_231 = V_229 ;
if ( ! F_95 ( type , V_16 ) )
return 0 ;
if ( strchr ( V_30 , '[' ) ) {
if ( V_156 > V_231 -> V_232 )
V_231 -> V_232 = V_156 ;
return 0 ;
}
if ( ! V_231 -> V_233 || V_156 < V_231 -> V_233 )
V_231 -> V_233 = V_156 ;
if ( ! V_231 -> V_234 || V_156 > V_231 -> V_234 )
V_231 -> V_234 = V_156 ;
if ( ! strcmp ( V_30 , L_30 ) ) {
V_231 -> V_235 = V_156 ;
return 0 ;
}
if ( ! strcmp ( V_30 , L_31 ) ) {
V_231 -> V_236 = V_156 ;
return 0 ;
}
return 0 ;
}
static int F_96 ( struct V_230 * V_231 ,
const char * V_237 )
{
char V_238 [ V_152 ] ;
F_97 ( V_238 , V_152 , L_32 , V_237 ) ;
if ( F_98 ( V_238 , L_33 ) )
return - 1 ;
if ( F_99 ( V_238 , V_231 ,
F_94 ) < 0 )
return - 1 ;
return 0 ;
}
static int F_100 ( void * V_229 ,
const char * V_30 V_239 ,
T_12 V_156 )
{
struct V_230 * V_231 = V_229 ;
if ( ! V_231 -> V_240 || V_156 < V_231 -> V_240 )
V_231 -> V_240 = V_156 ;
return 0 ;
}
static int F_101 ( struct V_230 * V_231 ,
const char * V_237 )
{
char V_241 [ V_152 ] ;
F_97 ( V_241 , V_152 , L_34 , V_237 ) ;
if ( F_98 ( V_241 , L_35 ) )
return - 1 ;
if ( F_102 ( V_241 , V_231 ,
F_100 ) < 0 )
return - 1 ;
return 0 ;
}
static void F_103 ( struct V_242 * V_243 , T_12 V_156 , T_12 V_157 , T_12 V_158 ,
T_12 V_244 , T_12 V_245 )
{
if ( V_243 -> V_23 || V_244 < V_156 || V_244 >= V_157 )
return;
V_243 -> V_23 = V_244 ;
V_243 -> V_149 = ( V_244 - V_156 ) + V_158 ;
V_243 -> V_193 = V_245 < V_157 ? V_245 - V_244 : V_157 - V_244 ;
}
static int F_104 ( T_12 V_156 , T_12 V_193 , T_12 V_158 , void * V_75 )
{
struct V_230 * V_231 = V_75 ;
T_12 V_157 = V_156 + V_193 ;
F_103 ( & V_231 -> V_246 , V_156 , V_157 , V_158 , V_231 -> V_235 ,
V_231 -> V_236 ) ;
F_103 ( & V_231 -> V_247 , V_156 , V_157 , V_158 , V_231 -> V_240 ,
V_231 -> V_232 ) ;
return 0 ;
}
static int F_105 ( struct V_230 * V_231 , T_1 * V_1 )
{
if ( F_74 ( V_1 , true , F_104 , V_231 ) < 0 )
return - 1 ;
return 0 ;
}
static int F_106 ( struct V_230 * V_231 , const char * V_237 ,
T_1 * V_1 )
{
if ( F_96 ( V_231 , V_237 ) )
return - 1 ;
if ( F_101 ( V_231 , V_237 ) )
return - 1 ;
if ( V_231 -> V_235 )
V_231 -> V_235 = F_107 ( V_231 -> V_235 , V_196 ) ;
else
V_231 -> V_235 = F_107 ( V_231 -> V_233 , V_196 ) ;
if ( V_231 -> V_236 ) {
V_231 -> V_236 = F_108 ( V_231 -> V_236 , V_196 ) ;
} else if ( V_231 -> V_234 ) {
V_231 -> V_236 = F_108 ( V_231 -> V_234 , V_196 ) ;
V_231 -> V_236 += V_196 ;
}
V_231 -> V_240 = F_107 ( V_231 -> V_240 , V_196 ) ;
if ( V_231 -> V_232 ) {
V_231 -> V_232 = F_108 ( V_231 -> V_232 ,
V_196 ) ;
V_231 -> V_232 += V_196 ;
}
if ( ! V_231 -> V_235 || ! V_231 -> V_236 )
return - 1 ;
if ( V_231 -> V_240 && ! V_231 -> V_232 )
return - 1 ;
return F_105 ( V_231 , V_1 ) ;
}
static int F_109 ( const char * V_248 , const char * V_249 ,
const char * V_30 )
{
char V_250 [ V_152 ] ;
char V_251 [ V_152 ] ;
F_97 ( V_250 , V_152 , L_36 , V_248 , V_30 ) ;
F_97 ( V_251 , V_152 , L_36 , V_249 , V_30 ) ;
return F_110 ( V_250 , V_251 , 0400 ) ;
}
static int F_111 ( const char * V_237 , const char * V_30 )
{
char V_89 [ V_152 ] ;
F_97 ( V_89 , V_152 , L_36 , V_237 , V_30 ) ;
return F_85 ( V_89 ) ;
}
static int F_112 ( int V_189 , int V_191 )
{
char * V_252 ;
char * V_253 ;
V_96 V_254 ;
T_2 V_193 ;
int V_55 = - 1 ;
V_252 = malloc ( V_196 ) ;
V_253 = malloc ( V_196 ) ;
if ( ! V_252 || ! V_253 )
goto V_79;
while ( 1 ) {
V_254 = F_43 ( V_189 , V_252 , V_196 ) ;
if ( V_254 < 0 )
goto V_79;
if ( ! V_254 )
break;
V_193 = V_254 ;
if ( F_113 ( V_191 , V_253 , V_193 ) != ( int ) V_193 )
goto V_79;
if ( memcmp ( V_252 , V_253 , V_193 ) )
goto V_79;
}
V_55 = 0 ;
V_79:
free ( V_253 ) ;
free ( V_252 ) ;
return V_55 ;
}
static int F_114 ( const char * V_250 ,
const char * V_251 )
{
int V_189 , V_191 , V_55 = - 1 ;
V_189 = F_37 ( V_250 , V_91 ) ;
if ( V_189 < 0 )
return - 1 ;
V_191 = F_37 ( V_251 , V_91 ) ;
if ( V_191 < 0 )
goto V_255;
V_55 = F_112 ( V_189 , V_191 ) ;
F_41 ( V_191 ) ;
V_255:
F_41 ( V_189 ) ;
return V_55 ;
}
static int F_115 ( const char * V_248 , const char * V_249 ,
const char * V_30 )
{
char V_250 [ V_152 ] ;
char V_251 [ V_152 ] ;
F_97 ( V_250 , V_152 , L_36 , V_248 , V_30 ) ;
F_97 ( V_251 , V_152 , L_36 , V_249 , V_30 ) ;
return F_114 ( V_250 , V_251 ) ;
}
int F_116 ( const char * V_248 , const char * V_249 )
{
struct V_198 V_198 ;
struct V_198 V_256 ;
T_2 V_208 = 2 ;
int V_31 = 0 , V_55 = - 1 ;
T_21 V_149 = V_196 , V_88 , V_257 = 0 ;
struct V_230 V_231 = { . V_235 = 0 , } ;
char V_258 [ V_152 ] ;
char V_259 [ V_152 ] ;
if ( F_109 ( V_248 , V_249 , L_37 ) )
return - 1 ;
if ( F_109 ( V_248 , V_249 , L_38 ) )
goto V_260;
F_97 ( V_258 , V_152 , L_39 , V_248 ) ;
F_97 ( V_259 , V_152 , L_39 , V_249 ) ;
if ( F_81 ( & V_198 , V_258 ) )
goto V_261;
if ( F_106 ( & V_231 , V_248 , V_198 . V_1 ) )
goto V_262;
if ( F_82 ( & V_256 , V_259 , V_198 . V_200 , false ) )
goto V_262;
if ( ! V_231 . V_247 . V_23 )
V_208 -= 1 ;
if ( F_87 ( & V_198 , & V_256 , V_208 ) )
goto V_263;
if ( F_90 ( & V_256 , V_31 ++ , V_149 , V_231 . V_246 . V_23 ,
V_231 . V_246 . V_193 ) )
goto V_263;
if ( V_231 . V_247 . V_23 ) {
V_257 = V_149 + V_231 . V_246 . V_193 ;
if ( F_90 ( & V_256 , V_31 , V_257 ,
V_231 . V_247 . V_23 , V_231 . V_247 . V_193 ) )
goto V_263;
}
V_88 = F_92 ( & V_256 ) ;
if ( V_88 < 0 || V_88 > V_149 )
goto V_263;
if ( F_78 ( V_198 . V_90 , V_231 . V_246 . V_149 , V_256 . V_90 , V_149 ,
V_231 . V_246 . V_193 ) )
goto V_263;
if ( V_257 && F_78 ( V_198 . V_90 , V_231 . V_247 . V_149 ,
V_256 . V_90 , V_257 ,
V_231 . V_247 . V_193 ) )
goto V_263;
if ( F_115 ( V_248 , V_249 , L_38 ) )
goto V_263;
if ( F_115 ( V_248 , V_249 , L_37 ) )
goto V_263;
V_55 = 0 ;
V_263:
F_86 ( & V_256 ) ;
if ( V_55 )
F_85 ( V_259 ) ;
V_262:
F_86 ( & V_198 ) ;
V_261:
if ( V_55 )
F_111 ( V_249 , L_38 ) ;
V_260:
if ( V_55 )
F_111 ( V_249 , L_37 ) ;
return V_55 ;
}
int F_117 ( struct V_264 * V_265 )
{
struct V_198 V_198 ;
struct V_198 V_256 ;
T_2 V_208 = 1 ;
int V_31 = 0 , V_55 = - 1 ;
T_21 V_149 = V_196 , V_88 ;
if ( F_81 ( & V_198 , V_265 -> V_258 ) )
return - 1 ;
strcpy ( V_265 -> V_259 , V_266 ) ;
if ( F_82 ( & V_256 , V_265 -> V_259 , V_198 . V_200 , true ) )
goto V_262;
if ( F_87 ( & V_198 , & V_256 , V_208 ) )
goto V_263;
if ( F_90 ( & V_256 , V_31 , V_149 , V_265 -> V_23 , V_265 -> V_193 ) )
goto V_263;
V_88 = F_92 ( & V_256 ) ;
if ( V_88 < 0 || V_88 > V_149 )
goto V_263;
if ( F_78 ( V_198 . V_90 , V_265 -> V_267 , V_256 . V_90 , V_149 , V_265 -> V_193 ) )
goto V_263;
V_55 = 0 ;
V_263:
F_86 ( & V_256 ) ;
if ( V_55 )
F_85 ( V_265 -> V_259 ) ;
V_262:
F_86 ( & V_198 ) ;
return V_55 ;
}
void F_118 ( struct V_264 * V_265 )
{
F_85 ( V_265 -> V_259 ) ;
}
void F_119 ( void )
{
F_120 ( V_268 ) ;
}
