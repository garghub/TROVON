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
static const char * F_13 ( T_1 V_12 )
{
static char V_23 [ V_24 ] ;
struct V_11 * V_13 ;
V_13 = F_4 ( V_12 ) ;
if ( V_13 ) {
snprintf ( V_23 , V_24 , L_4 , V_13 -> system , V_13 -> V_22 ) ;
free ( V_13 -> V_22 ) ;
free ( V_13 -> system ) ;
free ( V_13 ) ;
} else
snprintf ( V_23 , V_24 , L_4 , L_5 , L_5 ) ;
return V_23 ;
}
static int F_14 ( T_3 V_25 , T_3 V_26 )
{
if ( V_27 [ V_25 ] & F_15 ( V_26 ) )
return 1 ;
else
return 0 ;
}
static char * F_16 ( T_3 V_25 , T_3 V_26 , T_3 V_28 )
{
static char V_22 [ 50 ] ;
if ( V_28 ) {
sprintf ( V_22 , L_6 , V_29 [ V_25 ] [ 0 ] ,
V_30 [ V_26 ] [ 0 ] ,
V_31 [ V_28 ] [ 0 ] ) ;
} else {
sprintf ( V_22 , L_7 , V_29 [ V_25 ] [ 0 ] ,
V_30 [ V_26 ] [ 1 ] ) ;
}
return V_22 ;
}
const char * F_17 ( int type )
{
switch ( type ) {
case V_32 :
return L_8 ;
case V_33 :
return L_9 ;
case V_34 :
return L_10 ;
case V_35 :
return L_11 ;
default:
break;
}
return L_5 ;
}
const char * F_18 ( struct V_36 * V_37 )
{
T_1 V_12 = V_37 -> V_38 . V_12 ;
int type = V_37 -> V_38 . type ;
if ( type == V_39 || type == V_32 ) {
static char V_40 [ 128 ] ;
F_19 ( V_37 , V_40 , sizeof( V_40 ) ) ;
return V_40 ;
}
if ( V_37 -> V_22 )
return V_37 -> V_22 ;
return F_20 ( type , V_12 ) ;
}
const char * F_20 ( int type , T_1 V_12 )
{
static char V_23 [ 32 ] ;
if ( type == V_39 ) {
sprintf ( V_23 , L_12 V_41 , V_12 ) ;
return V_23 ;
}
switch ( type ) {
case V_32 :
return F_21 ( V_12 ) ;
case V_35 : {
T_3 V_25 , V_26 , V_28 ;
V_25 = ( V_12 >> 0 ) & 0xff ;
if ( V_25 > V_42 )
return L_13 ;
V_26 = ( V_12 >> 8 ) & 0xff ;
if ( V_26 > V_43 )
return L_14 ;
V_28 = ( V_12 >> 16 ) & 0xff ;
if ( V_28 > V_44 )
return L_15 ;
if ( ! F_14 ( V_25 , V_26 ) )
return L_16 ;
return F_16 ( V_25 , V_26 , V_28 ) ;
}
case V_33 :
if ( V_12 < V_45 && V_46 [ V_12 ] )
return V_46 [ V_12 ] ;
return L_17 ;
case V_34 :
return F_13 ( V_12 ) ;
default:
break;
}
return L_5 ;
}
static int F_22 ( struct V_47 * * V_48 , int * V_49 ,
struct V_50 * V_38 , char * V_22 )
{
struct V_36 * V_37 ;
struct V_47 * V_51 = * V_48 ;
if ( ! V_51 ) {
V_51 = malloc ( sizeof( * V_51 ) ) ;
if ( ! V_51 )
return - V_52 ;
F_23 ( V_51 ) ;
}
F_24 ( V_38 ) ;
V_37 = F_25 ( V_38 , ( * V_49 ) ++ ) ;
if ( ! V_37 ) {
free ( V_51 ) ;
return - V_52 ;
}
V_37 -> V_22 = F_26 ( V_22 ) ;
F_27 ( & V_37 -> V_53 , V_51 ) ;
* V_48 = V_51 ;
return 0 ;
}
static int F_28 ( char * V_54 , const char * V_55 [] [ V_56 ] , int V_57 )
{
int V_58 , V_59 ;
int V_60 , V_61 = - 1 ;
for ( V_58 = 0 ; V_58 < V_57 ; V_58 ++ ) {
for ( V_59 = 0 ; V_59 < V_56 && V_55 [ V_58 ] [ V_59 ] ; V_59 ++ ) {
V_60 = strlen ( V_55 [ V_58 ] [ V_59 ] ) ;
if ( V_60 > V_61 && ! strncasecmp ( V_54 , V_55 [ V_58 ] [ V_59 ] , V_60 ) )
V_61 = V_60 ;
}
if ( V_61 > 0 )
return V_58 ;
}
return - 1 ;
}
int F_29 ( struct V_47 * * V_51 , int * V_49 ,
char * type , char * V_62 , char * V_63 )
{
struct V_50 V_38 ;
char V_22 [ V_64 ] ;
int V_25 = - 1 , V_26 = - 1 , V_28 = - 1 ;
char * V_65 [ 2 ] = { V_62 , V_63 } ;
int V_58 , V_60 ;
V_25 = F_28 ( type , V_29 ,
V_42 ) ;
if ( V_25 == - 1 )
return - V_10 ;
V_60 = snprintf ( V_22 , V_64 , L_18 , type ) ;
for ( V_58 = 0 ; ( V_58 < 2 ) && ( V_65 [ V_58 ] ) ; V_58 ++ ) {
char * V_54 = V_65 [ V_58 ] ;
snprintf ( V_22 + V_60 , V_64 - V_60 , L_19 , V_54 ) ;
if ( V_26 == - 1 ) {
V_26 = F_28 ( V_54 , V_30 ,
V_43 ) ;
if ( V_26 >= 0 ) {
if ( ! F_14 ( V_25 , V_26 ) )
return - V_10 ;
continue;
}
}
if ( V_28 == - 1 ) {
V_28 = F_28 ( V_54 , V_31 ,
V_44 ) ;
if ( V_28 >= 0 )
continue;
}
}
if ( V_26 == - 1 )
V_26 = V_66 ;
if ( V_28 == - 1 )
V_28 = V_67 ;
memset ( & V_38 , 0 , sizeof( V_38 ) ) ;
V_38 . V_12 = V_25 | ( V_26 << 8 ) | ( V_28 << 16 ) ;
V_38 . type = V_35 ;
return F_22 ( V_51 , V_49 , & V_38 , V_22 ) ;
}
static int F_30 ( struct V_47 * * V_51 , int * V_49 ,
char * V_68 , char * V_69 )
{
struct V_50 V_38 ;
char V_22 [ V_64 ] ;
char V_4 [ V_5 ] ;
char V_18 [ 4 ] ;
T_1 V_19 ;
int V_6 ;
snprintf ( V_4 , V_5 , L_1 , V_7 ,
V_68 , V_69 ) ;
V_6 = F_2 ( V_4 , V_9 ) ;
if ( V_6 < 0 )
return - 1 ;
if ( F_9 ( V_6 , V_18 , sizeof( V_18 ) ) < 0 ) {
F_3 ( V_6 ) ;
return - 1 ;
}
F_3 ( V_6 ) ;
V_19 = F_10 ( V_18 ) ;
memset ( & V_38 , 0 , sizeof( V_38 ) ) ;
V_38 . V_12 = V_19 ;
V_38 . type = V_34 ;
V_38 . V_70 |= V_71 ;
V_38 . V_70 |= V_72 ;
V_38 . V_70 |= V_73 ;
V_38 . V_74 = 1 ;
snprintf ( V_22 , V_64 , L_4 , V_68 , V_69 ) ;
return F_22 ( V_51 , V_49 , & V_38 , V_22 ) ;
}
static int F_31 ( struct V_47 * * V_51 , int * V_49 ,
char * V_68 , char * V_69 )
{
char V_4 [ V_5 ] ;
struct V_1 * V_75 ;
T_2 * V_3 ;
int V_76 = 0 ;
snprintf ( V_4 , V_5 , L_2 , V_7 , V_68 ) ;
V_3 = F_6 ( V_4 ) ;
if ( ! V_3 ) {
perror ( L_20 ) ;
return - 1 ;
}
while ( ! V_76 && ( V_75 = F_32 ( V_3 ) ) ) {
if ( ! strcmp ( V_75 -> V_8 , L_21 )
|| ! strcmp ( V_75 -> V_8 , L_22 )
|| ! strcmp ( V_75 -> V_8 , L_23 )
|| ! strcmp ( V_75 -> V_8 , L_24 ) )
continue;
if ( ! F_33 ( V_75 -> V_8 , V_69 ) )
continue;
V_76 = F_30 ( V_51 , V_49 , V_68 , V_75 -> V_8 ) ;
}
return V_76 ;
}
int F_34 ( struct V_47 * * V_51 , int * V_49 ,
char * V_77 , char * V_78 )
{
int V_76 ;
V_76 = F_5 ( V_7 ) ;
if ( V_76 )
return V_76 ;
return strpbrk ( V_78 , L_25 ) ?
F_31 ( V_51 , V_49 , V_77 , V_78 ) :
F_30 ( V_51 , V_49 , V_77 , V_78 ) ;
}
static int
F_35 ( const char * type , struct V_50 * V_38 )
{
int V_58 ;
for ( V_58 = 0 ; V_58 < 3 ; V_58 ++ ) {
if ( ! type || ! type [ V_58 ] )
break;
switch ( type [ V_58 ] ) {
case 'r' :
V_38 -> V_79 |= V_80 ;
break;
case 'w' :
V_38 -> V_79 |= V_81 ;
break;
case 'x' :
V_38 -> V_79 |= V_82 ;
break;
default:
return - V_10 ;
}
}
if ( ! V_38 -> V_79 )
V_38 -> V_79 = V_80 | V_81 ;
return 0 ;
}
int F_36 ( struct V_47 * * V_51 , int * V_49 ,
void * V_83 , char * type )
{
struct V_50 V_38 ;
char V_22 [ V_64 ] ;
memset ( & V_38 , 0 , sizeof( V_38 ) ) ;
V_38 . V_84 = ( unsigned long ) V_83 ;
if ( F_35 ( type , & V_38 ) )
return - V_10 ;
if ( V_38 . V_79 == V_82 )
V_38 . V_85 = sizeof( long ) ;
else
V_38 . V_85 = V_86 ;
V_38 . type = V_87 ;
snprintf ( V_22 , V_64 , L_26 , V_83 , type ? type : L_27 ) ;
return F_22 ( V_51 , V_49 , & V_38 , V_22 ) ;
}
static int F_37 ( struct V_50 * V_38 ,
struct V_88 * V_89 )
{
#define F_38 ( type ) \
do { \
if (PARSE_EVENTS__TERM_TYPE_ ## type != term->type_val) \
return -EINVAL; \
} while (0)
switch ( V_89 -> V_90 ) {
case V_91 :
F_38 ( V_92 ) ;
V_38 -> V_12 = V_89 -> V_93 . V_94 ;
break;
case V_95 :
F_38 ( V_92 ) ;
V_38 -> V_96 = V_89 -> V_93 . V_94 ;
break;
case V_97 :
F_38 ( V_92 ) ;
V_38 -> V_98 = V_89 -> V_93 . V_94 ;
break;
case V_99 :
F_38 ( V_92 ) ;
V_38 -> V_74 = V_89 -> V_93 . V_94 ;
break;
case V_100 :
break;
case V_101 :
F_38 ( V_102 ) ;
break;
default:
return - V_10 ;
}
return 0 ;
#undef F_38
}
static int F_39 ( struct V_50 * V_38 ,
struct V_47 * V_103 , int V_104 )
{
struct V_88 * V_89 ;
F_40 (term, head, list)
if ( F_37 ( V_38 , V_89 ) && V_104 )
return - V_10 ;
return 0 ;
}
int F_41 ( struct V_47 * * V_51 , int * V_49 ,
unsigned long type , unsigned long V_12 ,
struct V_47 * V_105 )
{
struct V_50 V_38 ;
memset ( & V_38 , 0 , sizeof( V_38 ) ) ;
V_38 . type = type ;
V_38 . V_12 = V_12 ;
if ( V_105 &&
F_39 ( & V_38 , V_105 , 1 ) )
return - V_10 ;
return F_22 ( V_51 , V_49 , & V_38 ,
( char * ) F_20 ( type , V_12 ) ) ;
}
static int F_42 ( struct V_88 * V_89 )
{
return V_89 -> V_90 == V_101 ;
}
static char * F_43 ( struct V_50 * V_38 ,
struct V_47 * V_106 )
{
struct V_88 * V_89 ;
F_40 (term, head_terms, list)
if ( F_42 ( V_89 ) )
return V_89 -> V_93 . V_54 ;
return ( char * ) F_20 ( V_39 , V_38 -> V_12 ) ;
}
int F_44 ( struct V_47 * * V_51 , int * V_49 ,
char * V_22 , struct V_47 * V_105 )
{
struct V_50 V_38 ;
struct V_107 * V_108 ;
V_108 = F_45 ( V_22 ) ;
if ( ! V_108 )
return - V_10 ;
memset ( & V_38 , 0 , sizeof( V_38 ) ) ;
F_39 ( & V_38 , V_105 , 0 ) ;
if ( F_46 ( V_108 , & V_38 , V_105 ) )
return - V_10 ;
return F_22 ( V_51 , V_49 , & V_38 ,
F_43 ( & V_38 , V_105 ) ) ;
}
void F_47 ( struct V_47 * V_109 ,
struct V_47 * V_110 )
{
F_48 ( V_109 , V_110 ) ;
free ( V_109 ) ;
}
int F_49 ( struct V_47 * V_51 , char * V_54 )
{
struct V_36 * V_37 ;
int V_111 = 0 , V_112 = 0 ;
int V_113 = 0 , V_114 = 0 , V_115 = 0 , V_116 = 0 , V_117 = 0 , V_118 = 0 ;
if ( V_54 == NULL )
return 0 ;
while ( * V_54 ) {
if ( * V_54 == 'u' ) {
if ( ! V_111 )
V_111 = V_113 = V_114 = V_115 = 1 ;
V_113 = 0 ;
} else if ( * V_54 == 'k' ) {
if ( ! V_111 )
V_111 = V_113 = V_114 = V_115 = 1 ;
V_114 = 0 ;
} else if ( * V_54 == 'h' ) {
if ( ! V_111 )
V_111 = V_113 = V_114 = V_115 = 1 ;
V_115 = 0 ;
} else if ( * V_54 == 'G' ) {
if ( ! V_112 )
V_112 = V_117 = V_116 = 1 ;
V_117 = 0 ;
} else if ( * V_54 == 'H' ) {
if ( ! V_112 )
V_112 = V_117 = V_116 = 1 ;
V_116 = 0 ;
} else if ( * V_54 == 'p' ) {
V_118 ++ ;
} else
break;
++ V_54 ;
}
if ( V_118 > 3 )
return - V_10 ;
F_40 (evsel, list, node) {
V_37 -> V_38 . V_119 = V_113 ;
V_37 -> V_38 . V_120 = V_114 ;
V_37 -> V_38 . V_121 = V_115 ;
V_37 -> V_38 . V_122 = V_118 ;
V_37 -> V_38 . V_123 = V_116 ;
V_37 -> V_38 . V_124 = V_117 ;
}
return 0 ;
}
int F_50 ( struct V_125 * V_126 , const char * V_54 , int T_4 V_127 )
{
F_51 ( V_51 ) ;
F_51 ( V_128 ) ;
T_5 V_129 ;
int V_76 , V_49 = V_126 -> V_130 ;
V_129 = F_52 ( V_54 ) ;
#ifdef F_53
V_131 = 1 ;
#endif
V_76 = F_54 ( & V_51 , & V_49 ) ;
F_55 ( V_129 ) ;
F_56 ( V_129 ) ;
F_57 () ;
if ( ! V_76 ) {
int V_132 = V_49 - V_126 -> V_130 ;
F_58 ( V_126 , & V_51 , V_132 ) ;
return 0 ;
}
fprintf ( V_133 , L_28 , V_54 ) ;
fprintf ( V_133 , L_29 ) ;
return V_76 ;
}
int F_59 ( const struct V_134 * V_135 , const char * V_54 ,
int T_4 V_127 )
{
struct V_125 * V_126 = * (struct V_125 * * ) V_135 -> V_136 ;
return F_50 ( V_126 , V_54 , T_4 ) ;
}
int F_60 ( const struct V_134 * V_135 , const char * V_54 ,
int T_4 V_127 )
{
struct V_125 * V_126 = * (struct V_125 * * ) V_135 -> V_136 ;
struct V_36 * V_137 = NULL ;
if ( V_126 -> V_130 > 0 )
V_137 = F_61 ( V_126 -> V_132 . V_138 , struct V_36 , V_53 ) ;
if ( V_137 == NULL || V_137 -> V_38 . type != V_34 ) {
fprintf ( V_133 ,
L_30 ) ;
return - 1 ;
}
V_137 -> V_139 = F_26 ( V_54 ) ;
if ( V_137 -> V_139 == NULL ) {
fprintf ( V_133 , L_31 ) ;
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
! F_33 ( V_16 . V_8 , V_140 ) )
continue;
snprintf ( V_20 , V_5 , L_2 , V_7 ,
V_16 . V_8 ) ;
V_3 = F_6 ( V_20 ) ;
if ( ! V_3 )
continue;
F_8 (sys_dirent, evt_dir, evt_dirent, evt_next) {
if ( V_141 != NULL &&
! F_33 ( V_17 . V_8 , V_141 ) )
continue;
snprintf ( V_4 , V_5 , L_4 ,
V_16 . V_8 , V_17 . V_8 ) ;
printf ( L_32 , V_4 ,
V_142 [ V_34 ] ) ;
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
snprintf ( V_4 , V_5 , L_4 ,
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
void F_64 ( T_3 type )
{
struct V_144 * V_145 = V_146 ;
unsigned int V_58 ;
char V_22 [ 64 ] ;
for ( V_58 = 0 ; V_58 < F_65 ( V_146 ) ; V_58 ++ , V_145 ++ ) {
if ( type != V_145 -> type )
continue;
if ( strlen ( V_145 -> V_147 ) )
snprintf ( V_22 , sizeof( V_22 ) , L_33 ,
V_145 -> V_148 , V_145 -> V_147 ) ;
else
snprintf ( V_22 , sizeof( V_22 ) , L_18 , V_145 -> V_148 ) ;
printf ( L_32 , V_22 ,
V_142 [ type ] ) ;
}
}
int F_66 ( const char * V_141 )
{
unsigned int type , V_149 , V_58 , V_150 = 0 ;
for ( type = 0 ; type < V_42 ; type ++ ) {
for ( V_149 = 0 ; V_149 < V_43 ; V_149 ++ ) {
if ( ! F_14 ( type , V_149 ) )
continue;
for ( V_58 = 0 ; V_58 < V_44 ; V_58 ++ ) {
char * V_22 = F_16 ( type , V_149 , V_58 ) ;
if ( V_141 != NULL && ! F_33 ( V_22 , V_141 ) )
continue;
printf ( L_32 , V_22 ,
V_142 [ V_35 ] ) ;
++ V_150 ;
}
}
}
return V_150 ;
}
void F_67 ( const char * V_141 )
{
unsigned int V_58 , type , V_151 = - 1 , V_150 = 0 , V_152 = 0 ;
struct V_144 * V_145 = V_146 ;
char V_22 [ V_64 ] ;
printf ( L_34 ) ;
printf ( L_35 ) ;
for ( V_58 = 0 ; V_58 < F_65 ( V_146 ) ; V_58 ++ , V_145 ++ ) {
type = V_145 -> type ;
if ( type != V_151 && V_150 ) {
printf ( L_34 ) ;
V_150 = 0 ;
V_152 ++ ;
}
if ( V_141 != NULL &&
! ( F_33 ( V_145 -> V_148 , V_141 ) ||
( V_145 -> V_147 && F_33 ( V_145 -> V_147 , V_141 ) ) ) )
continue;
if ( strlen ( V_145 -> V_147 ) )
snprintf ( V_22 , V_64 , L_33 , V_145 -> V_148 , V_145 -> V_147 ) ;
else
strncpy ( V_22 , V_145 -> V_148 , V_64 ) ;
printf ( L_32 , V_22 ,
V_142 [ type ] ) ;
V_151 = type ;
++ V_150 ;
}
if ( V_152 ) {
V_150 = 0 ;
printf ( L_34 ) ;
}
F_66 ( V_141 ) ;
if ( V_141 != NULL )
return;
printf ( L_34 ) ;
printf ( L_32 ,
L_36 ,
V_142 [ V_39 ] ) ;
printf ( L_32 ,
L_37 ,
V_142 [ V_39 ] ) ;
printf ( L_38 ) ;
printf ( L_34 ) ;
printf ( L_32 ,
L_39 ,
V_142 [ V_87 ] ) ;
printf ( L_34 ) ;
F_62 ( NULL , NULL ) ;
}
int F_68 ( struct V_88 * V_89 )
{
return V_89 -> V_90 != V_153 ;
}
static int F_69 ( struct V_88 * * V_154 , int V_155 ,
int V_90 , char * V_12 ,
char * V_54 , long V_94 )
{
struct V_88 * V_89 ;
V_89 = F_12 ( sizeof( * V_89 ) ) ;
if ( ! V_89 )
return - V_52 ;
F_23 ( & V_89 -> V_51 ) ;
V_89 -> V_155 = V_155 ;
V_89 -> V_90 = V_90 ;
V_89 -> V_12 = V_12 ;
switch ( V_155 ) {
case V_156 :
V_89 -> V_93 . V_94 = V_94 ;
break;
case V_157 :
V_89 -> V_93 . V_54 = V_54 ;
break;
default:
return - V_10 ;
}
* V_154 = V_89 ;
return 0 ;
}
int F_70 ( struct V_88 * * V_89 ,
int V_90 , char * V_12 , long V_94 )
{
return F_69 ( V_89 , V_156 , V_90 ,
V_12 , NULL , V_94 ) ;
}
int F_71 ( struct V_88 * * V_89 ,
int V_90 , char * V_12 , char * V_54 )
{
return F_69 ( V_89 , V_157 , V_90 ,
V_12 , V_54 , 0 ) ;
}
void F_72 ( struct V_47 * V_158 )
{
struct V_88 * V_89 , * V_159 ;
F_73 (term, h, terms, list)
free ( V_89 ) ;
free ( V_158 ) ;
}
