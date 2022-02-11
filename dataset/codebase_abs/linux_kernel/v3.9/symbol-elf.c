static inline T_1 F_1 ( const T_2 * V_1 )
{
return F_2 ( V_1 -> V_2 ) ;
}
static inline int F_3 ( const T_2 * V_1 )
{
return F_1 ( V_1 ) == V_3 &&
V_1 -> V_4 != 0 &&
V_1 -> V_5 != V_6 ;
}
static inline bool F_4 ( const T_2 * V_1 )
{
return F_1 ( V_1 ) == V_7 &&
V_1 -> V_4 != 0 &&
V_1 -> V_5 != V_6 ;
}
static inline int F_5 ( const T_2 * V_1 )
{
return F_1 ( V_1 ) == V_8 &&
V_1 -> V_4 != 0 &&
V_1 -> V_5 != V_6 &&
V_1 -> V_5 != V_9 ;
}
static bool F_6 ( T_2 * V_1 , enum V_10 type )
{
switch ( type ) {
case V_11 :
return F_3 ( V_1 ) ;
case V_12 :
return F_4 ( V_1 ) ;
default:
return false ;
}
}
static inline const char * F_7 ( const T_2 * V_1 ,
const T_3 * V_13 )
{
return V_13 -> V_14 + V_1 -> V_4 ;
}
static inline const char * F_8 ( const T_4 * V_15 ,
const T_3 * V_16 )
{
return V_16 -> V_14 + V_15 -> V_17 ;
}
static inline int F_9 ( const T_4 * V_15 ,
const T_3 * V_16 )
{
return strstr ( F_8 ( V_15 , V_16 ) , L_1 ) != NULL ;
}
static inline bool F_10 ( const T_4 * V_15 ,
const T_3 * V_16 )
{
return strstr ( F_8 ( V_15 , V_16 ) , L_2 ) != NULL ;
}
static bool F_11 ( T_4 * V_15 , T_3 * V_16 ,
enum V_10 type )
{
switch ( type ) {
case V_11 :
return F_9 ( V_15 , V_16 ) ;
case V_12 :
return F_10 ( V_15 , V_16 ) ;
default:
return false ;
}
}
static T_5 F_12 ( T_6 * V_18 , T_7 V_19 )
{
T_8 * V_20 = NULL ;
T_4 V_15 ;
T_5 V_21 = 1 ;
while ( ( V_20 = F_13 ( V_18 , V_20 ) ) != NULL ) {
F_14 ( V_20 , & V_15 ) ;
if ( ( V_19 >= V_15 . V_22 ) &&
( V_19 < ( V_15 . V_22 + V_15 . V_23 ) ) )
return V_21 ;
++ V_21 ;
}
return - 1 ;
}
static T_8 * F_15 ( T_6 * V_18 , T_9 * V_24 ,
T_4 * V_25 , const char * V_26 ,
T_5 * V_27 )
{
T_8 * V_20 = NULL ;
T_5 V_21 = 1 ;
if ( ! F_16 ( F_17 ( V_18 , V_24 -> V_28 ) , NULL ) )
return NULL ;
while ( ( V_20 = F_13 ( V_18 , V_20 ) ) != NULL ) {
char * V_29 ;
F_14 ( V_20 , V_25 ) ;
V_29 = F_18 ( V_18 , V_24 -> V_28 , V_25 -> V_17 ) ;
if ( ! strcmp ( V_26 , V_29 ) ) {
if ( V_27 )
* V_27 = V_21 ;
break;
}
++ V_21 ;
}
return V_20 ;
}
int F_19 ( struct V_30 * V_30 , struct V_31 * V_32 , struct V_33 * V_33 ,
T_10 V_34 )
{
T_11 V_35 , V_27 ;
T_2 V_1 ;
T_12 V_36 ;
T_4 V_37 ;
struct V_38 * V_39 ;
T_4 V_40 , V_41 ;
T_3 * V_42 , * V_43 , * V_13 ;
T_8 * V_44 , * V_45 , * V_46 ;
T_5 V_47 ;
T_9 V_48 ;
char V_49 [ 1024 ] ;
T_6 * V_18 ;
int V_50 = 0 , V_51 , V_52 = 0 ;
if ( ! V_32 -> V_53 )
return 0 ;
V_18 = V_32 -> V_18 ;
V_48 = V_32 -> V_48 ;
V_46 = V_32 -> V_53 ;
V_41 = V_32 -> V_54 ;
V_47 = V_32 -> V_47 ;
if ( V_46 == NULL )
goto V_55;
V_44 = F_15 ( V_18 , & V_48 , & V_40 ,
L_3 , NULL ) ;
if ( V_44 == NULL ) {
V_44 = F_15 ( V_18 , & V_48 , & V_40 ,
L_4 , NULL ) ;
if ( V_44 == NULL )
goto V_55;
}
V_52 = - 1 ;
if ( V_40 . V_56 != V_47 )
goto V_55;
if ( F_15 ( V_18 , & V_48 , & V_37 , L_5 , NULL ) == NULL )
goto V_55;
V_42 = F_20 ( V_44 , NULL ) ;
if ( V_42 == NULL )
goto V_55;
V_43 = F_20 ( V_46 , NULL ) ;
if ( V_43 == NULL )
goto V_55;
V_45 = F_17 ( V_18 , V_41 . V_56 ) ;
if ( V_45 == NULL )
goto V_55;
V_13 = F_20 ( V_45 , NULL ) ;
if ( V_13 == NULL )
goto V_55;
if ( V_13 -> V_57 == 0 )
goto V_55;
V_35 = V_40 . V_23 / V_40 . V_58 ;
V_36 = V_37 . V_59 ;
if ( V_40 . V_60 == V_61 ) {
T_13 V_62 , * V_63 ;
F_21 (reldata, pos, pos_mem, idx,
nr_rel_entries) {
V_51 = F_22 ( V_63 -> V_64 ) ;
V_36 += V_37 . V_58 ;
F_23 ( V_43 , V_51 , & V_1 ) ;
snprintf ( V_49 , sizeof( V_49 ) ,
L_6 , F_7 ( & V_1 , V_13 ) ) ;
V_39 = F_24 ( V_36 , V_37 . V_58 ,
V_65 , V_49 ) ;
if ( ! V_39 )
goto V_55;
if ( V_34 && V_34 ( V_33 , V_39 ) )
F_25 ( V_39 ) ;
else {
F_26 ( & V_30 -> V_66 [ V_33 -> type ] , V_39 ) ;
++ V_50 ;
}
}
} else if ( V_40 . V_60 == V_67 ) {
T_14 V_62 , * V_63 ;
F_27 (reldata, pos, pos_mem, idx,
nr_rel_entries) {
V_51 = F_22 ( V_63 -> V_64 ) ;
V_36 += V_37 . V_58 ;
F_23 ( V_43 , V_51 , & V_1 ) ;
snprintf ( V_49 , sizeof( V_49 ) ,
L_6 , F_7 ( & V_1 , V_13 ) ) ;
V_39 = F_24 ( V_36 , V_37 . V_58 ,
V_65 , V_49 ) ;
if ( ! V_39 )
goto V_55;
if ( V_34 && V_34 ( V_33 , V_39 ) )
F_25 ( V_39 ) ;
else {
F_26 ( & V_30 -> V_66 [ V_33 -> type ] , V_39 ) ;
++ V_50 ;
}
}
}
V_52 = 0 ;
V_55:
if ( V_52 == 0 )
return V_50 ;
F_28 ( L_7 ,
V_68 , V_30 -> V_69 ) ;
return 0 ;
}
static int F_29 ( T_6 * V_18 , void * V_70 , T_5 V_71 )
{
int V_52 = - 1 ;
T_9 V_48 ;
T_4 V_15 ;
T_3 * V_72 ;
T_8 * V_20 ;
T_15 V_73 ;
void * V_74 ;
if ( V_71 < V_75 )
goto V_76;
V_73 = F_30 ( V_18 ) ;
if ( V_73 != V_77 )
goto V_76;
if ( F_31 ( V_18 , & V_48 ) == NULL ) {
F_32 ( L_8 , V_68 ) ;
goto V_76;
}
do {
V_20 = F_15 ( V_18 , & V_48 , & V_15 ,
L_9 , NULL ) ;
if ( V_20 )
break;
V_20 = F_15 ( V_18 , & V_48 , & V_15 ,
L_10 , NULL ) ;
if ( V_20 )
break;
V_20 = F_15 ( V_18 , & V_48 , & V_15 ,
L_11 , NULL ) ;
if ( V_20 )
break;
return V_52 ;
} while ( 0 );
V_72 = F_20 ( V_20 , NULL ) ;
if ( V_72 == NULL )
goto V_76;
V_74 = V_72 -> V_14 ;
while ( V_74 < ( V_72 -> V_14 + V_72 -> V_57 ) ) {
T_16 * V_78 = V_74 ;
T_5 V_79 = F_33 ( V_78 -> V_80 ) ,
V_81 = F_33 ( V_78 -> V_82 ) ;
const char * V_26 ;
V_74 += sizeof( * V_78 ) ;
V_26 = V_74 ;
V_74 += V_79 ;
if ( V_78 -> V_83 == V_84 &&
V_78 -> V_80 == sizeof( L_12 ) ) {
if ( memcmp ( V_26 , L_12 , sizeof( L_12 ) ) == 0 ) {
T_5 V_85 = F_34 ( V_71 , V_81 ) ;
memcpy ( V_70 , V_74 , V_85 ) ;
memset ( V_70 + V_85 , 0 , V_71 - V_85 ) ;
V_52 = V_81 ;
break;
}
}
V_74 += V_81 ;
}
V_76:
return V_52 ;
}
int F_35 ( const char * V_86 , void * V_70 , T_5 V_71 )
{
int V_87 , V_52 = - 1 ;
T_6 * V_18 ;
if ( V_71 < V_75 )
goto V_76;
V_87 = F_36 ( V_86 , V_88 ) ;
if ( V_87 < 0 )
goto V_76;
V_18 = F_37 ( V_87 , V_89 , NULL ) ;
if ( V_18 == NULL ) {
F_38 ( L_13 , V_68 , V_86 ) ;
goto V_90;
}
V_52 = F_29 ( V_18 , V_70 , V_71 ) ;
F_39 ( V_18 ) ;
V_90:
F_40 ( V_87 ) ;
V_76:
return V_52 ;
}
int F_41 ( const char * V_86 , void * V_91 , T_5 V_71 )
{
int V_87 , V_52 = - 1 ;
if ( V_71 < V_75 )
goto V_76;
V_87 = F_36 ( V_86 , V_88 ) ;
if ( V_87 < 0 )
goto V_76;
while ( 1 ) {
char V_70 [ V_92 ] ;
T_16 V_78 ;
T_5 V_79 , V_81 ;
if ( F_42 ( V_87 , & V_78 , sizeof( V_78 ) ) != sizeof( V_78 ) )
break;
V_79 = F_33 ( V_78 . V_80 ) ;
V_81 = F_33 ( V_78 . V_82 ) ;
if ( V_78 . V_83 == V_84 &&
V_78 . V_80 == sizeof( L_12 ) ) {
if ( F_42 ( V_87 , V_70 , V_79 ) != ( V_93 ) V_79 )
break;
if ( memcmp ( V_70 , L_12 , sizeof( L_12 ) ) == 0 ) {
T_5 V_85 = F_34 ( V_81 , V_71 ) ;
if ( F_42 ( V_87 , V_91 , V_85 ) == ( V_93 ) V_85 ) {
memset ( V_91 + V_85 , 0 , V_71 - V_85 ) ;
V_52 = 0 ;
break;
}
} else if ( F_42 ( V_87 , V_70 , V_81 ) != ( V_93 ) V_81 )
break;
} else {
int V_94 = V_79 + V_81 ;
if ( F_42 ( V_87 , V_70 , V_94 ) != V_94 )
break;
}
}
F_40 ( V_87 ) ;
V_76:
return V_52 ;
}
int F_43 ( const char * V_86 , char * V_95 ,
T_5 V_71 )
{
int V_87 , V_52 = - 1 ;
T_6 * V_18 ;
T_9 V_48 ;
T_4 V_15 ;
T_3 * V_72 ;
T_8 * V_20 ;
T_15 V_73 ;
V_87 = F_36 ( V_86 , V_88 ) ;
if ( V_87 < 0 )
goto V_76;
V_18 = F_37 ( V_87 , V_89 , NULL ) ;
if ( V_18 == NULL ) {
F_38 ( L_13 , V_68 , V_86 ) ;
goto V_90;
}
V_73 = F_30 ( V_18 ) ;
if ( V_73 != V_77 )
goto V_90;
if ( F_31 ( V_18 , & V_48 ) == NULL ) {
F_32 ( L_8 , V_68 ) ;
goto V_90;
}
V_20 = F_15 ( V_18 , & V_48 , & V_15 ,
L_14 , NULL ) ;
if ( V_20 == NULL )
goto V_90;
V_72 = F_20 ( V_20 , NULL ) ;
if ( V_72 == NULL )
goto V_90;
strncpy ( V_95 , V_72 -> V_14 , V_71 ) ;
F_39 ( V_18 ) ;
V_90:
F_40 ( V_87 ) ;
V_76:
return V_52 ;
}
static int F_44 ( struct V_30 * V_30 , unsigned char V_96 )
{
static unsigned int const V_97 = 1 ;
V_30 -> V_98 = V_99 ;
switch ( V_96 ) {
case V_100 :
if ( * ( unsigned char const * ) & V_97 != 1 )
V_30 -> V_98 = V_101 ;
break;
case V_102 :
if ( * ( unsigned char const * ) & V_97 != 0 )
V_30 -> V_98 = V_101 ;
break;
default:
F_32 ( L_15 , V_96 ) ;
return - V_103 ;
}
return 0 ;
}
bool F_45 ( struct V_31 * V_32 )
{
return V_32 -> V_53 || V_32 -> V_104 ;
}
bool F_46 ( struct V_31 * V_32 )
{
return V_32 -> V_105 != NULL ;
}
void F_47 ( struct V_31 * V_32 )
{
free ( V_32 -> V_26 ) ;
F_39 ( V_32 -> V_18 ) ;
F_40 ( V_32 -> V_87 ) ;
}
int F_48 ( struct V_31 * V_32 , struct V_30 * V_30 , const char * V_26 ,
enum V_106 type )
{
int V_52 = - 1 ;
T_9 V_48 ;
T_6 * V_18 ;
int V_87 ;
V_87 = F_36 ( V_26 , V_88 ) ;
if ( V_87 < 0 )
return - 1 ;
V_18 = F_37 ( V_87 , V_89 , NULL ) ;
if ( V_18 == NULL ) {
F_28 ( L_13 , V_68 , V_26 ) ;
goto V_90;
}
if ( F_31 ( V_18 , & V_48 ) == NULL ) {
F_28 ( L_8 , V_68 ) ;
goto V_55;
}
if ( F_44 ( V_30 , V_48 . V_107 [ V_108 ] ) )
goto V_55;
if ( V_30 -> V_109 ) {
T_17 V_91 [ V_75 ] ;
if ( F_29 ( V_18 , V_91 , V_75 ) < 0 )
goto V_55;
if ( ! F_49 ( V_30 , V_91 ) )
goto V_55;
}
V_32 -> V_105 = F_15 ( V_18 , & V_48 , & V_32 -> V_110 , L_16 ,
NULL ) ;
if ( V_32 -> V_110 . V_60 != V_111 )
V_32 -> V_105 = NULL ;
V_32 -> V_47 = 0 ;
V_32 -> V_53 = F_15 ( V_18 , & V_48 , & V_32 -> V_54 , L_17 ,
& V_32 -> V_47 ) ;
if ( V_32 -> V_54 . V_60 != V_112 )
V_32 -> V_53 = NULL ;
V_32 -> V_113 = 0 ;
V_32 -> V_104 = F_15 ( V_18 , & V_48 , & V_32 -> V_114 , L_18 ,
& V_32 -> V_113 ) ;
if ( V_32 -> V_114 . V_60 != V_115 )
V_32 -> V_104 = NULL ;
if ( V_30 -> V_116 == V_117 ) {
T_4 V_15 ;
V_32 -> V_118 = ( V_48 . V_119 == V_120 ||
F_15 ( V_18 , & V_48 , & V_15 ,
L_19 ,
NULL ) != NULL ) ;
} else {
V_32 -> V_118 = 0 ;
}
V_32 -> V_26 = F_50 ( V_26 ) ;
if ( ! V_32 -> V_26 )
goto V_55;
V_32 -> V_18 = V_18 ;
V_32 -> V_87 = V_87 ;
V_32 -> V_48 = V_48 ;
V_32 -> type = type ;
return 0 ;
V_55:
F_39 ( V_18 ) ;
V_90:
F_40 ( V_87 ) ;
return V_52 ;
}
int F_51 ( struct V_30 * V_30 , struct V_33 * V_33 ,
struct V_31 * V_121 , struct V_31 * V_122 ,
T_10 V_34 , int V_123 )
{
struct V_124 * V_124 = V_30 -> V_116 ? F_52 ( V_33 ) : NULL ;
struct V_33 * V_125 = V_33 ;
struct V_30 * V_126 = V_30 ;
T_3 * V_13 , * V_16 ;
T_11 V_127 ;
int V_52 = - 1 ;
T_11 V_27 ;
T_9 V_48 ;
T_4 V_15 ;
T_3 * V_43 , * V_128 = NULL ;
T_2 V_1 ;
T_8 * V_20 , * V_129 ;
T_6 * V_18 ;
int V_50 = 0 ;
V_30 -> V_130 = V_121 -> type ;
if ( ! V_121 -> V_105 ) {
V_121 -> V_105 = V_121 -> V_53 ;
V_121 -> V_110 = V_121 -> V_54 ;
}
V_18 = V_121 -> V_18 ;
V_48 = V_121 -> V_48 ;
V_20 = V_121 -> V_105 ;
V_15 = V_121 -> V_110 ;
if ( V_122 -> V_104 )
V_128 = F_16 ( V_122 -> V_104 , NULL ) ;
V_43 = F_20 ( V_20 , NULL ) ;
if ( V_43 == NULL )
goto V_55;
V_20 = F_17 ( V_18 , V_15 . V_56 ) ;
if ( V_20 == NULL )
goto V_55;
V_13 = F_20 ( V_20 , NULL ) ;
if ( V_13 == NULL )
goto V_55;
V_129 = F_17 ( V_18 , V_48 . V_28 ) ;
if ( V_129 == NULL )
goto V_55;
V_16 = F_20 ( V_129 , NULL ) ;
if ( V_16 == NULL )
goto V_55;
V_127 = V_15 . V_23 / V_15 . V_58 ;
memset ( & V_1 , 0 , sizeof( V_1 ) ) ;
V_30 -> V_118 = V_122 -> V_118 ;
F_53 (syms, nr_syms, idx, sym) {
struct V_38 * V_39 ;
const char * V_131 = F_7 ( & V_1 , V_13 ) ;
char * V_132 = NULL ;
int V_133 = F_5 ( & V_1 ) ;
const char * V_134 ;
bool V_135 = false ;
if ( V_124 && V_124 -> V_136 && V_124 -> V_136 -> V_26 &&
strcmp ( V_131 , V_124 -> V_136 -> V_26 ) == 0 )
V_124 -> V_136 -> V_137 = V_1 . V_138 ;
if ( ! V_133 && ! F_6 ( & V_1 , V_33 -> type ) )
continue;
if ( V_48 . V_139 == V_140 ) {
if ( ! strcmp ( V_131 , L_20 ) ||
! strcmp ( V_131 , L_21 ) ||
! strcmp ( V_131 , L_22 ) )
continue;
}
if ( V_122 -> V_104 && V_1 . V_5 == V_122 -> V_113 ) {
T_18 V_141 = V_1 . V_138 - V_121 -> V_114 . V_22 ;
T_12 * V_142 = V_128 -> V_14 + V_141 ;
V_1 . V_138 = F_54 ( V_30 , T_12 , * V_142 ) ;
V_1 . V_5 = F_12 ( V_122 -> V_18 ,
V_1 . V_138 ) ;
V_135 = true ;
}
if ( V_1 . V_5 == V_9 )
continue;
V_20 = F_17 ( V_122 -> V_18 , V_1 . V_5 ) ;
if ( ! V_20 )
goto V_55;
F_14 ( V_20 , & V_15 ) ;
if ( V_133 && ! F_11 ( & V_15 , V_16 , V_33 -> type ) )
continue;
V_134 = F_8 ( & V_15 , V_16 ) ;
if ( ( V_48 . V_139 == V_140 ) &&
( V_33 -> type == V_11 ) &&
( V_1 . V_138 & 1 ) )
-- V_1 . V_138 ;
if ( V_30 -> V_116 != V_117 || V_123 ) {
char V_143 [ V_144 ] ;
if ( strcmp ( V_134 ,
( V_126 -> V_145 +
V_30 -> V_146 ) ) == 0 )
goto V_147;
if ( strcmp ( V_134 , L_23 ) == 0 ) {
V_125 = V_33 ;
V_126 = V_30 ;
goto V_147;
}
snprintf ( V_143 , sizeof( V_143 ) ,
L_24 , V_30 -> V_145 , V_134 ) ;
V_125 = F_55 ( V_124 -> V_148 , V_33 -> type , V_143 ) ;
if ( V_125 == NULL ) {
T_12 V_149 = V_1 . V_138 ;
if ( V_123 )
V_149 += V_33 -> V_149 + V_15 . V_59 ;
V_126 = F_56 ( V_143 ) ;
if ( V_126 == NULL )
goto V_55;
V_126 -> V_116 = V_30 -> V_116 ;
V_126 -> V_69 = V_30 -> V_69 ;
V_126 -> V_150 = V_30 -> V_150 ;
V_125 = F_57 ( V_149 , V_126 ,
V_33 -> type ) ;
if ( V_125 == NULL ) {
F_58 ( V_126 ) ;
goto V_55;
}
V_125 -> V_151 = V_152 ;
V_125 -> V_153 = V_152 ;
V_126 -> V_130 = V_30 -> V_130 ;
F_59 ( V_124 -> V_148 , V_125 ) ;
F_60 ( & V_30 -> V_154 , V_126 ) ;
F_61 ( V_126 , V_33 -> type ) ;
} else
V_126 = V_125 -> V_30 ;
goto V_147;
}
if ( ( V_135 && V_122 -> V_118 )
|| ( ! V_135 && V_121 -> V_118 ) ) {
F_62 ( L_25 V_155 L_26
L_27 V_155 L_28 V_155 L_29 , V_68 ,
( T_12 ) V_1 . V_138 , ( T_12 ) V_15 . V_22 ,
( T_12 ) V_15 . V_59 ) ;
V_1 . V_138 -= V_15 . V_22 - V_15 . V_59 ;
}
V_132 = F_63 ( NULL , V_131 , V_156 | V_157 ) ;
if ( V_132 != NULL )
V_131 = V_132 ;
V_147:
V_39 = F_24 ( V_1 . V_138 , V_1 . V_158 ,
F_64 ( V_1 . V_2 ) , V_131 ) ;
free ( V_132 ) ;
if ( ! V_39 )
goto V_55;
if ( V_34 && V_34 ( V_125 , V_39 ) )
F_25 ( V_39 ) ;
else {
F_26 ( & V_126 -> V_66 [ V_125 -> type ] , V_39 ) ;
V_50 ++ ;
}
}
if ( V_50 > 0 ) {
F_65 ( & V_30 -> V_66 [ V_33 -> type ] ) ;
F_66 ( & V_30 -> V_66 [ V_33 -> type ] ) ;
if ( V_124 ) {
F_67 ( V_124 -> V_148 , V_33 -> type ) ;
}
}
V_52 = V_50 ;
V_55:
return V_52 ;
}
void F_68 ( void )
{
F_69 ( V_159 ) ;
}
