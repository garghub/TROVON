static int F_1 ( struct V_1 * V_2 , struct V_1 * V_3 )
{
char V_4 [ V_5 ] ;
int V_6 ;
snprintf ( V_4 , V_5 , L_1 , V_7 ,
V_2 -> V_8 , V_3 -> V_8 ) ;
V_6 = F_2 ( V_4 , V_9 ) ;
if ( V_6 < 0 )
return - V_10 ;
F_3 ( V_6 ) ;
return 0 ;
}
struct V_11 * F_4 ( T_1 V_12 )
{
struct V_11 * V_13 = NULL ;
T_2 * V_2 , * V_3 ;
struct V_1 * V_14 , * V_15 , V_16 , V_17 ;
char V_18 [ 24 ] ;
int V_6 ;
T_1 V_19 ;
char V_4 [ V_5 ] ;
char V_20 [ V_5 ] ;
if ( F_5 ( V_7 ) )
return NULL ;
V_2 = F_6 ( V_7 ) ;
if ( ! V_2 )
return NULL ;
F_7 (sys_dir, sys_dirent, sys_next) {
snprintf ( V_20 , V_5 , L_2 , V_7 ,
V_16 . V_8 ) ;
V_3 = F_6 ( V_20 ) ;
if ( ! V_3 )
continue;
F_8 (sys_dirent, evt_dir, evt_dirent, evt_next) {
snprintf ( V_4 , V_5 , L_3 , V_20 ,
V_17 . V_8 ) ;
V_6 = F_2 ( V_4 , V_9 ) ;
if ( V_6 < 0 )
continue;
if ( F_9 ( V_6 , V_18 , sizeof( V_18 ) ) < 0 ) {
F_3 ( V_6 ) ;
continue;
}
F_3 ( V_6 ) ;
V_19 = F_10 ( V_18 ) ;
if ( V_19 == V_12 ) {
F_11 ( V_3 ) ;
F_11 ( V_2 ) ;
V_13 = F_12 ( sizeof( * V_13 ) ) ;
V_13 -> system = malloc ( V_21 ) ;
if ( ! V_13 -> system ) {
free ( V_13 ) ;
return NULL ;
}
V_13 -> V_22 = malloc ( V_21 ) ;
if ( ! V_13 -> V_22 ) {
free ( V_13 -> system ) ;
free ( V_13 ) ;
return NULL ;
}
strncpy ( V_13 -> system , V_16 . V_8 ,
V_21 ) ;
strncpy ( V_13 -> V_22 , V_17 . V_8 ,
V_21 ) ;
return V_13 ;
}
}
F_11 ( V_3 ) ;
}
F_11 ( V_2 ) ;
return NULL ;
}
const char * F_13 ( int type )
{
switch ( type ) {
case V_23 :
return L_4 ;
case V_24 :
return L_5 ;
case V_25 :
return L_6 ;
case V_26 :
return L_7 ;
default:
break;
}
return L_8 ;
}
static int F_14 ( struct V_27 * * V_28 , int * V_29 ,
struct V_30 * V_31 , char * V_22 )
{
struct V_32 * V_33 ;
struct V_27 * V_34 = * V_28 ;
if ( ! V_34 ) {
V_34 = malloc ( sizeof( * V_34 ) ) ;
if ( ! V_34 )
return - V_35 ;
F_15 ( V_34 ) ;
}
F_16 ( V_31 ) ;
V_33 = F_17 ( V_31 , ( * V_29 ) ++ ) ;
if ( ! V_33 ) {
free ( V_34 ) ;
return - V_35 ;
}
if ( V_22 )
V_33 -> V_22 = F_18 ( V_22 ) ;
F_19 ( & V_33 -> V_36 , V_34 ) ;
* V_28 = V_34 ;
return 0 ;
}
static int F_20 ( char * V_37 , const char * V_38 [] [ V_39 ] , int V_40 )
{
int V_41 , V_42 ;
int V_43 , V_44 = - 1 ;
for ( V_41 = 0 ; V_41 < V_40 ; V_41 ++ ) {
for ( V_42 = 0 ; V_42 < V_39 && V_38 [ V_41 ] [ V_42 ] ; V_42 ++ ) {
V_43 = strlen ( V_38 [ V_41 ] [ V_42 ] ) ;
if ( V_43 > V_44 && ! strncasecmp ( V_37 , V_38 [ V_41 ] [ V_42 ] , V_43 ) )
V_44 = V_43 ;
}
if ( V_44 > 0 )
return V_41 ;
}
return - 1 ;
}
int F_21 ( struct V_27 * * V_34 , int * V_29 ,
char * type , char * V_45 , char * V_46 )
{
struct V_30 V_31 ;
char V_22 [ V_47 ] ;
int V_48 = - 1 , V_49 = - 1 , V_50 = - 1 ;
char * V_51 [ 2 ] = { V_45 , V_46 } ;
int V_41 , V_43 ;
V_48 = F_20 ( type , V_52 ,
V_53 ) ;
if ( V_48 == - 1 )
return - V_10 ;
V_43 = snprintf ( V_22 , V_47 , L_9 , type ) ;
for ( V_41 = 0 ; ( V_41 < 2 ) && ( V_51 [ V_41 ] ) ; V_41 ++ ) {
char * V_37 = V_51 [ V_41 ] ;
snprintf ( V_22 + V_43 , V_47 - V_43 , L_10 , V_37 ) ;
if ( V_49 == - 1 ) {
V_49 = F_20 ( V_37 , V_54 ,
V_55 ) ;
if ( V_49 >= 0 ) {
if ( ! F_22 ( V_48 , V_49 ) )
return - V_10 ;
continue;
}
}
if ( V_50 == - 1 ) {
V_50 = F_20 ( V_37 , V_56 ,
V_57 ) ;
if ( V_50 >= 0 )
continue;
}
}
if ( V_49 == - 1 )
V_49 = V_58 ;
if ( V_50 == - 1 )
V_50 = V_59 ;
memset ( & V_31 , 0 , sizeof( V_31 ) ) ;
V_31 . V_12 = V_48 | ( V_49 << 8 ) | ( V_50 << 16 ) ;
V_31 . type = V_26 ;
return F_14 ( V_34 , V_29 , & V_31 , V_22 ) ;
}
static int F_23 ( struct V_27 * * V_34 , int * V_29 ,
char * V_60 , char * V_61 )
{
struct V_30 V_31 ;
char V_22 [ V_47 ] ;
char V_4 [ V_5 ] ;
char V_18 [ 4 ] ;
T_1 V_19 ;
int V_6 ;
snprintf ( V_4 , V_5 , L_1 , V_7 ,
V_60 , V_61 ) ;
V_6 = F_2 ( V_4 , V_9 ) ;
if ( V_6 < 0 )
return - 1 ;
if ( F_9 ( V_6 , V_18 , sizeof( V_18 ) ) < 0 ) {
F_3 ( V_6 ) ;
return - 1 ;
}
F_3 ( V_6 ) ;
V_19 = F_10 ( V_18 ) ;
memset ( & V_31 , 0 , sizeof( V_31 ) ) ;
V_31 . V_12 = V_19 ;
V_31 . type = V_25 ;
V_31 . V_62 |= V_63 ;
V_31 . V_62 |= V_64 ;
V_31 . V_62 |= V_65 ;
V_31 . V_62 |= V_66 ;
V_31 . V_67 = 1 ;
snprintf ( V_22 , V_47 , L_11 , V_60 , V_61 ) ;
return F_14 ( V_34 , V_29 , & V_31 , V_22 ) ;
}
static int F_24 ( struct V_27 * * V_34 , int * V_29 ,
char * V_60 , char * V_61 )
{
char V_4 [ V_5 ] ;
struct V_1 * V_68 ;
T_2 * V_3 ;
int V_69 = 0 ;
snprintf ( V_4 , V_5 , L_2 , V_7 , V_60 ) ;
V_3 = F_6 ( V_4 ) ;
if ( ! V_3 ) {
perror ( L_12 ) ;
return - 1 ;
}
while ( ! V_69 && ( V_68 = F_25 ( V_3 ) ) ) {
if ( ! strcmp ( V_68 -> V_8 , L_13 )
|| ! strcmp ( V_68 -> V_8 , L_14 )
|| ! strcmp ( V_68 -> V_8 , L_15 )
|| ! strcmp ( V_68 -> V_8 , L_16 ) )
continue;
if ( ! F_26 ( V_68 -> V_8 , V_61 ) )
continue;
V_69 = F_23 ( V_34 , V_29 , V_60 , V_68 -> V_8 ) ;
}
return V_69 ;
}
int F_27 ( struct V_27 * * V_34 , int * V_29 ,
char * V_70 , char * V_71 )
{
int V_69 ;
V_69 = F_5 ( V_7 ) ;
if ( V_69 )
return V_69 ;
return strpbrk ( V_71 , L_17 ) ?
F_24 ( V_34 , V_29 , V_70 , V_71 ) :
F_23 ( V_34 , V_29 , V_70 , V_71 ) ;
}
static int
F_28 ( const char * type , struct V_30 * V_31 )
{
int V_41 ;
for ( V_41 = 0 ; V_41 < 3 ; V_41 ++ ) {
if ( ! type || ! type [ V_41 ] )
break;
#define F_29 ( T_3 ) \
do { \
if (attr->bp_type & bit) \
return -EINVAL; \
else \
attr->bp_type |= bit; \
} while (0)
switch ( type [ V_41 ] ) {
case 'r' :
F_29 ( V_72 ) ;
break;
case 'w' :
F_29 ( V_73 ) ;
break;
case 'x' :
F_29 ( V_74 ) ;
break;
default:
return - V_10 ;
}
}
#undef F_29
if ( ! V_31 -> V_75 )
V_31 -> V_75 = V_72 | V_73 ;
return 0 ;
}
int F_30 ( struct V_27 * * V_34 , int * V_29 ,
void * V_76 , char * type )
{
struct V_30 V_31 ;
memset ( & V_31 , 0 , sizeof( V_31 ) ) ;
V_31 . V_77 = ( unsigned long ) V_76 ;
if ( F_28 ( type , & V_31 ) )
return - V_10 ;
if ( V_31 . V_75 == V_74 )
V_31 . V_78 = sizeof( long ) ;
else
V_31 . V_78 = V_79 ;
V_31 . type = V_80 ;
V_31 . V_67 = 1 ;
return F_14 ( V_34 , V_29 , & V_31 , NULL ) ;
}
static int F_31 ( struct V_30 * V_31 ,
struct V_81 * V_82 )
{
#define F_32 ( type ) \
do { \
if (PARSE_EVENTS__TERM_TYPE_ ## type != term->type_val) \
return -EINVAL; \
} while (0)
switch ( V_82 -> V_83 ) {
case V_84 :
F_32 ( V_85 ) ;
V_31 -> V_12 = V_82 -> V_86 . V_87 ;
break;
case V_88 :
F_32 ( V_85 ) ;
V_31 -> V_89 = V_82 -> V_86 . V_87 ;
break;
case V_90 :
F_32 ( V_85 ) ;
V_31 -> V_91 = V_82 -> V_86 . V_87 ;
break;
case V_92 :
F_32 ( V_85 ) ;
V_31 -> V_67 = V_82 -> V_86 . V_87 ;
break;
case V_93 :
break;
case V_94 :
F_32 ( V_95 ) ;
break;
default:
return - V_10 ;
}
return 0 ;
#undef F_32
}
static int F_33 ( struct V_30 * V_31 ,
struct V_27 * V_96 , int V_97 )
{
struct V_81 * V_82 ;
F_34 (term, head, list)
if ( F_31 ( V_31 , V_82 ) && V_97 )
return - V_10 ;
return 0 ;
}
int F_35 ( struct V_27 * * V_34 , int * V_29 ,
unsigned long type , unsigned long V_12 ,
struct V_27 * V_98 )
{
struct V_30 V_31 ;
memset ( & V_31 , 0 , sizeof( V_31 ) ) ;
V_31 . type = type ;
V_31 . V_12 = V_12 ;
if ( V_98 &&
F_33 ( & V_31 , V_98 , 1 ) )
return - V_10 ;
return F_14 ( V_34 , V_29 , & V_31 , NULL ) ;
}
static int F_36 ( struct V_81 * V_82 )
{
return V_82 -> V_83 == V_94 ;
}
static char * F_37 ( struct V_27 * V_99 )
{
struct V_81 * V_82 ;
F_34 (term, head_terms, list)
if ( F_36 ( V_82 ) )
return V_82 -> V_86 . V_37 ;
return NULL ;
}
int F_38 ( struct V_27 * * V_34 , int * V_29 ,
char * V_22 , struct V_27 * V_98 )
{
struct V_30 V_31 ;
struct V_100 * V_101 ;
V_101 = F_39 ( V_22 ) ;
if ( ! V_101 )
return - V_10 ;
memset ( & V_31 , 0 , sizeof( V_31 ) ) ;
if ( F_40 ( V_101 , V_98 ) )
return - V_10 ;
F_33 ( & V_31 , V_98 , 0 ) ;
if ( F_41 ( V_101 , & V_31 , V_98 ) )
return - V_10 ;
return F_14 ( V_34 , V_29 , & V_31 ,
F_37 ( V_98 ) ) ;
}
void F_42 ( struct V_27 * V_102 ,
struct V_27 * V_103 )
{
F_43 ( V_102 , V_103 ) ;
free ( V_102 ) ;
}
int F_44 ( struct V_27 * V_34 , char * V_37 )
{
struct V_32 * V_33 ;
int V_104 = 0 , V_105 = 0 ;
int V_106 = 0 , V_107 = 0 , V_108 = 0 , V_109 = 0 , V_110 = 0 , V_111 = 0 ;
if ( V_37 == NULL )
return 0 ;
while ( * V_37 ) {
if ( * V_37 == 'u' ) {
if ( ! V_104 )
V_104 = V_106 = V_107 = V_108 = 1 ;
V_106 = 0 ;
} else if ( * V_37 == 'k' ) {
if ( ! V_104 )
V_104 = V_106 = V_107 = V_108 = 1 ;
V_107 = 0 ;
} else if ( * V_37 == 'h' ) {
if ( ! V_104 )
V_104 = V_106 = V_107 = V_108 = 1 ;
V_108 = 0 ;
} else if ( * V_37 == 'G' ) {
if ( ! V_105 )
V_105 = V_110 = V_109 = 1 ;
V_110 = 0 ;
} else if ( * V_37 == 'H' ) {
if ( ! V_105 )
V_105 = V_110 = V_109 = 1 ;
V_109 = 0 ;
} else if ( * V_37 == 'p' ) {
V_111 ++ ;
} else
break;
++ V_37 ;
}
if ( V_111 > 3 )
return - V_10 ;
F_34 (evsel, list, node) {
V_33 -> V_31 . V_112 = V_106 ;
V_33 -> V_31 . V_113 = V_107 ;
V_33 -> V_31 . V_114 = V_108 ;
V_33 -> V_31 . V_115 = V_111 ;
V_33 -> V_31 . V_116 = V_109 ;
V_33 -> V_31 . V_117 = V_110 ;
}
return 0 ;
}
static int F_45 ( const char * V_37 , void * V_118 , int V_119 )
{
T_4 V_120 ;
void * V_121 ;
int V_69 ;
V_69 = F_46 ( V_119 , & V_121 ) ;
if ( V_69 )
return V_69 ;
V_120 = F_47 ( V_37 , V_121 ) ;
#ifdef F_48
V_122 = 1 ;
#endif
V_69 = F_49 ( V_118 , V_121 ) ;
F_50 ( V_120 , V_121 ) ;
F_51 ( V_120 , V_121 ) ;
F_52 ( V_121 ) ;
return V_69 ;
}
int F_53 ( struct V_27 * V_123 , const char * V_37 )
{
struct V_124 V_118 = {
. V_123 = NULL ,
} ;
int V_69 ;
V_69 = F_45 ( V_37 , & V_118 , V_125 ) ;
if ( ! V_69 ) {
F_54 ( V_118 . V_123 , V_123 ) ;
free ( V_118 . V_123 ) ;
return 0 ;
}
F_55 ( V_118 . V_123 ) ;
return V_69 ;
}
int F_56 ( struct V_126 * V_127 , const char * V_37 , int T_5 V_128 )
{
struct V_129 V_118 = {
. V_34 = F_57 ( V_118 . V_34 ) ,
. V_29 = V_127 -> V_130 ,
} ;
int V_69 ;
V_69 = F_45 ( V_37 , & V_118 , V_131 ) ;
if ( ! V_69 ) {
int V_132 = V_118 . V_29 - V_127 -> V_130 ;
F_58 ( V_127 , & V_118 . V_34 , V_132 ) ;
return 0 ;
}
fprintf ( V_133 , L_18 , V_37 ) ;
fprintf ( V_133 , L_19 ) ;
return V_69 ;
}
int F_59 ( const struct V_134 * V_135 , const char * V_37 ,
int T_5 V_128 )
{
struct V_126 * V_127 = * (struct V_126 * * ) V_135 -> V_136 ;
return F_56 ( V_127 , V_37 , T_5 ) ;
}
int F_60 ( const struct V_134 * V_135 , const char * V_37 ,
int T_5 V_128 )
{
struct V_126 * V_127 = * (struct V_126 * * ) V_135 -> V_136 ;
struct V_32 * V_137 = NULL ;
if ( V_127 -> V_130 > 0 )
V_137 = F_61 ( V_127 -> V_132 . V_138 , struct V_32 , V_36 ) ;
if ( V_137 == NULL || V_137 -> V_31 . type != V_25 ) {
fprintf ( V_133 ,
L_20 ) ;
return - 1 ;
}
V_137 -> V_139 = F_18 ( V_37 ) ;
if ( V_137 -> V_139 == NULL ) {
fprintf ( V_133 , L_21 ) ;
return - 1 ;
}
return 0 ;
}
void F_62 ( const char * V_140 , const char * V_141 )
{
T_2 * V_2 , * V_3 ;
struct V_1 * V_14 , * V_15 , V_16 , V_17 ;
char V_4 [ V_5 ] ;
char V_20 [ V_5 ] ;
if ( F_5 ( V_7 ) )
return;
V_2 = F_6 ( V_7 ) ;
if ( ! V_2 )
return;
F_7 (sys_dir, sys_dirent, sys_next) {
if ( V_140 != NULL &&
! F_26 ( V_16 . V_8 , V_140 ) )
continue;
snprintf ( V_20 , V_5 , L_2 , V_7 ,
V_16 . V_8 ) ;
V_3 = F_6 ( V_20 ) ;
if ( ! V_3 )
continue;
F_8 (sys_dirent, evt_dir, evt_dirent, evt_next) {
if ( V_141 != NULL &&
! F_26 ( V_17 . V_8 , V_141 ) )
continue;
snprintf ( V_4 , V_5 , L_11 ,
V_16 . V_8 , V_17 . V_8 ) ;
printf ( L_22 , V_4 ,
V_142 [ V_25 ] ) ;
}
F_11 ( V_3 ) ;
}
F_11 ( V_2 ) ;
}
int F_63 ( const char * V_143 )
{
T_2 * V_2 , * V_3 ;
struct V_1 * V_14 , * V_15 , V_16 , V_17 ;
char V_4 [ V_5 ] ;
char V_20 [ V_5 ] ;
if ( F_5 ( V_7 ) )
return 0 ;
V_2 = F_6 ( V_7 ) ;
if ( ! V_2 )
return 0 ;
F_7 (sys_dir, sys_dirent, sys_next) {
snprintf ( V_20 , V_5 , L_2 , V_7 ,
V_16 . V_8 ) ;
V_3 = F_6 ( V_20 ) ;
if ( ! V_3 )
continue;
F_8 (sys_dirent, evt_dir, evt_dirent, evt_next) {
snprintf ( V_4 , V_5 , L_11 ,
V_16 . V_8 , V_17 . V_8 ) ;
if ( ! strcmp ( V_4 , V_143 ) ) {
F_11 ( V_3 ) ;
F_11 ( V_2 ) ;
return 1 ;
}
}
F_11 ( V_3 ) ;
}
F_11 ( V_2 ) ;
return 0 ;
}
static void F_64 ( T_6 type , struct V_144 * V_145 ,
unsigned V_146 )
{
char V_22 [ 64 ] ;
unsigned V_41 ;
for ( V_41 = 0 ; V_41 < V_146 ; V_41 ++ , V_145 ++ ) {
if ( strlen ( V_145 -> V_147 ) )
snprintf ( V_22 , sizeof( V_22 ) , L_23 ,
V_145 -> V_148 , V_145 -> V_147 ) ;
else
snprintf ( V_22 , sizeof( V_22 ) , L_9 , V_145 -> V_148 ) ;
printf ( L_22 , V_22 ,
V_142 [ type ] ) ;
}
}
void F_65 ( T_6 type )
{
if ( type == V_24 )
F_64 ( type , V_149 , V_150 ) ;
else
F_64 ( type , V_151 , V_152 ) ;
}
int F_66 ( const char * V_141 )
{
unsigned int type , V_153 , V_41 , V_154 = 0 ;
char V_22 [ 64 ] ;
for ( type = 0 ; type < V_53 ; type ++ ) {
for ( V_153 = 0 ; V_153 < V_55 ; V_153 ++ ) {
if ( ! F_22 ( type , V_153 ) )
continue;
for ( V_41 = 0 ; V_41 < V_57 ; V_41 ++ ) {
F_67 ( type , V_153 , V_41 ,
V_22 , sizeof( V_22 ) ) ;
if ( V_141 != NULL && ! F_26 ( V_22 , V_141 ) )
continue;
printf ( L_22 , V_22 ,
V_142 [ V_26 ] ) ;
++ V_154 ;
}
}
}
return V_154 ;
}
static void F_68 ( const char * V_141 , unsigned type ,
struct V_144 * V_145 , unsigned V_146 )
{
unsigned V_41 , V_154 = 0 ;
char V_22 [ V_47 ] ;
for ( V_41 = 0 ; V_41 < V_146 ; V_41 ++ , V_145 ++ ) {
if ( V_141 != NULL &&
! ( F_26 ( V_145 -> V_148 , V_141 ) ||
( V_145 -> V_147 && F_26 ( V_145 -> V_147 , V_141 ) ) ) )
continue;
if ( strlen ( V_145 -> V_147 ) )
snprintf ( V_22 , V_47 , L_23 , V_145 -> V_148 , V_145 -> V_147 ) ;
else
strncpy ( V_22 , V_145 -> V_148 , V_47 ) ;
printf ( L_22 , V_22 , V_142 [ type ] ) ;
V_154 ++ ;
}
if ( V_154 )
printf ( L_24 ) ;
}
void F_69 ( const char * V_141 )
{
printf ( L_24 ) ;
printf ( L_25 ) ;
F_68 ( V_141 , V_23 ,
V_151 , V_152 ) ;
F_68 ( V_141 , V_24 ,
V_149 , V_150 ) ;
F_66 ( V_141 ) ;
if ( V_141 != NULL )
return;
printf ( L_24 ) ;
printf ( L_22 ,
L_26 ,
V_142 [ V_155 ] ) ;
printf ( L_22 ,
L_27 ,
V_142 [ V_155 ] ) ;
printf ( L_28 ) ;
printf ( L_24 ) ;
printf ( L_22 ,
L_29 ,
V_142 [ V_80 ] ) ;
printf ( L_24 ) ;
F_62 ( NULL , NULL ) ;
}
int F_70 ( struct V_81 * V_82 )
{
return V_82 -> V_83 != V_156 ;
}
static int F_71 ( struct V_81 * * V_157 , int V_158 ,
int V_83 , char * V_12 ,
char * V_37 , long V_87 )
{
struct V_81 * V_82 ;
V_82 = F_12 ( sizeof( * V_82 ) ) ;
if ( ! V_82 )
return - V_35 ;
F_15 ( & V_82 -> V_34 ) ;
V_82 -> V_158 = V_158 ;
V_82 -> V_83 = V_83 ;
V_82 -> V_12 = V_12 ;
switch ( V_158 ) {
case V_159 :
V_82 -> V_86 . V_87 = V_87 ;
break;
case V_160 :
V_82 -> V_86 . V_37 = V_37 ;
break;
default:
return - V_10 ;
}
* V_157 = V_82 ;
return 0 ;
}
int F_72 ( struct V_81 * * V_82 ,
int V_83 , char * V_12 , long V_87 )
{
return F_71 ( V_82 , V_159 , V_83 ,
V_12 , NULL , V_87 ) ;
}
int F_73 ( struct V_81 * * V_82 ,
int V_83 , char * V_12 , char * V_37 )
{
return F_71 ( V_82 , V_160 , V_83 ,
V_12 , V_37 , 0 ) ;
}
int F_74 ( struct V_81 * * V_161 ,
struct V_81 * V_82 )
{
return F_71 ( V_161 , V_82 -> V_158 , V_82 -> V_83 , V_82 -> V_12 ,
V_82 -> V_86 . V_37 , V_82 -> V_86 . V_87 ) ;
}
void F_55 ( struct V_27 * V_123 )
{
struct V_81 * V_82 , * V_162 ;
F_75 (term, h, terms, list)
free ( V_82 ) ;
free ( V_123 ) ;
}
