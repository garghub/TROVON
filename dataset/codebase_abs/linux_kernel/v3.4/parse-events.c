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
if ( V_37 -> V_22 )
return V_37 -> V_22 ;
return F_19 ( type , V_12 ) ;
}
const char * F_19 ( int type , T_1 V_12 )
{
static char V_23 [ 32 ] ;
if ( type == V_39 ) {
sprintf ( V_23 , L_12 V_40 , V_12 ) ;
return V_23 ;
}
switch ( type ) {
case V_32 :
if ( V_12 < V_41 && V_42 [ V_12 ] )
return V_42 [ V_12 ] ;
return L_13 ;
case V_35 : {
T_3 V_25 , V_26 , V_28 ;
V_25 = ( V_12 >> 0 ) & 0xff ;
if ( V_25 > V_43 )
return L_14 ;
V_26 = ( V_12 >> 8 ) & 0xff ;
if ( V_26 > V_44 )
return L_15 ;
V_28 = ( V_12 >> 16 ) & 0xff ;
if ( V_28 > V_45 )
return L_16 ;
if ( ! F_14 ( V_25 , V_26 ) )
return L_17 ;
return F_16 ( V_25 , V_26 , V_28 ) ;
}
case V_33 :
if ( V_12 < V_46 && V_47 [ V_12 ] )
return V_47 [ V_12 ] ;
return L_18 ;
case V_34 :
return F_13 ( V_12 ) ;
default:
break;
}
return L_5 ;
}
static int F_20 ( struct V_48 * V_49 , int * V_50 ,
struct V_51 * V_38 , char * V_22 )
{
struct V_36 * V_37 ;
F_21 ( V_38 ) ;
V_37 = F_22 ( V_38 , ( * V_50 ) ++ ) ;
if ( ! V_37 )
return - V_52 ;
F_23 ( & V_37 -> V_53 , V_49 ) ;
V_37 -> V_22 = F_24 ( V_22 ) ;
return 0 ;
}
static int F_25 ( char * V_54 , const char * V_55 [] [ V_56 ] , int V_57 )
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
int F_26 ( struct V_48 * V_49 , int * V_50 ,
char * type , char * V_62 , char * V_63 )
{
struct V_51 V_38 ;
char V_22 [ V_64 ] ;
int V_25 = - 1 , V_26 = - 1 , V_28 = - 1 ;
char * V_65 [ 2 ] = { V_62 , V_63 } ;
int V_58 , V_60 ;
V_25 = F_25 ( type , V_29 ,
V_43 ) ;
if ( V_25 == - 1 )
return - V_10 ;
V_60 = snprintf ( V_22 , V_64 , L_19 , type ) ;
for ( V_58 = 0 ; ( V_58 < 2 ) && ( V_65 [ V_58 ] ) ; V_58 ++ ) {
char * V_54 = V_65 [ V_58 ] ;
snprintf ( V_22 + V_60 , V_64 - V_60 , L_20 , V_54 ) ;
if ( V_26 == - 1 ) {
V_26 = F_25 ( V_54 , V_30 ,
V_44 ) ;
if ( V_26 >= 0 ) {
if ( ! F_14 ( V_25 , V_26 ) )
return - V_10 ;
continue;
}
}
if ( V_28 == - 1 ) {
V_28 = F_25 ( V_54 , V_31 ,
V_45 ) ;
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
return F_20 ( V_49 , V_50 , & V_38 , V_22 ) ;
}
static int F_27 ( struct V_48 * V_49 , int * V_50 ,
char * V_68 , char * V_69 )
{
struct V_51 V_38 ;
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
return F_20 ( V_49 , V_50 , & V_38 , V_22 ) ;
}
static int F_28 ( struct V_48 * V_49 , int * V_50 ,
char * V_68 , char * V_69 )
{
char V_4 [ V_5 ] ;
struct V_1 * V_75 ;
T_2 * V_3 ;
int V_76 = 0 ;
snprintf ( V_4 , V_5 , L_2 , V_7 , V_68 ) ;
V_3 = F_6 ( V_4 ) ;
if ( ! V_3 ) {
perror ( L_21 ) ;
return - 1 ;
}
while ( ! V_76 && ( V_75 = F_29 ( V_3 ) ) ) {
if ( ! strcmp ( V_75 -> V_8 , L_22 )
|| ! strcmp ( V_75 -> V_8 , L_23 )
|| ! strcmp ( V_75 -> V_8 , L_24 )
|| ! strcmp ( V_75 -> V_8 , L_25 ) )
continue;
if ( ! F_30 ( V_75 -> V_8 , V_69 ) )
continue;
V_76 = F_27 ( V_49 , V_50 , V_68 , V_75 -> V_8 ) ;
}
return V_76 ;
}
int F_31 ( struct V_48 * V_49 , int * V_50 ,
char * V_77 , char * V_78 )
{
int V_76 ;
V_76 = F_5 ( V_7 ) ;
if ( V_76 )
return V_76 ;
return strpbrk ( V_78 , L_26 ) ?
F_28 ( V_49 , V_50 , V_77 , V_78 ) :
F_27 ( V_49 , V_50 , V_77 , V_78 ) ;
}
static int
F_32 ( const char * type , struct V_51 * V_38 )
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
int F_33 ( struct V_48 * V_49 , int * V_50 ,
void * V_83 , char * type )
{
struct V_51 V_38 ;
char V_22 [ V_64 ] ;
memset ( & V_38 , 0 , sizeof( V_38 ) ) ;
V_38 . V_84 = ( unsigned long ) V_83 ;
if ( F_32 ( type , & V_38 ) )
return - V_10 ;
if ( V_38 . V_79 == V_82 )
V_38 . V_85 = sizeof( long ) ;
else
V_38 . V_85 = V_86 ;
V_38 . type = V_87 ;
snprintf ( V_22 , V_64 , L_27 , V_83 , type ? type : L_28 ) ;
return F_20 ( V_49 , V_50 , & V_38 , V_22 ) ;
}
static int F_34 ( struct V_51 * V_38 ,
struct V_88 * V_89 )
{
switch ( V_89 -> type ) {
case V_90 :
V_38 -> V_12 = V_89 -> V_91 . V_92 ;
break;
case V_93 :
V_38 -> V_94 = V_89 -> V_91 . V_92 ;
break;
case V_95 :
V_38 -> V_96 = V_89 -> V_91 . V_92 ;
break;
case V_97 :
V_38 -> V_74 = V_89 -> V_91 . V_92 ;
break;
case V_98 :
break;
default:
return - V_10 ;
}
return 0 ;
}
static int F_35 ( struct V_51 * V_38 ,
struct V_48 * V_99 , int V_100 )
{
struct V_88 * V_89 ;
F_36 (term, head, list)
if ( F_34 ( V_38 , V_89 ) && V_100 )
return - V_10 ;
return 0 ;
}
int F_37 ( struct V_48 * V_49 , int * V_50 ,
unsigned long type , unsigned long V_12 ,
struct V_48 * V_101 )
{
struct V_51 V_38 ;
memset ( & V_38 , 0 , sizeof( V_38 ) ) ;
V_38 . type = type ;
V_38 . V_12 = V_12 ;
if ( V_101 &&
F_35 ( & V_38 , V_101 , 1 ) )
return - V_10 ;
return F_20 ( V_49 , V_50 , & V_38 ,
( char * ) F_19 ( type , V_12 ) ) ;
}
int F_38 ( struct V_48 * V_49 , int * V_50 ,
char * V_22 , struct V_48 * V_101 )
{
struct V_51 V_38 ;
struct V_102 * V_103 ;
V_103 = F_39 ( V_22 ) ;
if ( ! V_103 )
return - V_10 ;
memset ( & V_38 , 0 , sizeof( V_38 ) ) ;
F_35 ( & V_38 , V_101 , 0 ) ;
if ( F_40 ( V_103 , & V_38 , V_101 ) )
return - V_10 ;
return F_20 ( V_49 , V_50 , & V_38 , ( char * ) L_29 ) ;
}
void F_41 ( struct V_48 * V_104 ,
struct V_48 * V_105 )
{
F_42 ( V_104 , V_105 ) ;
F_43 ( V_104 ) ;
}
int F_44 ( struct V_48 * V_49 , char * V_54 )
{
struct V_36 * V_37 ;
int V_106 = 0 , V_107 = 0 ;
int V_108 = 0 , V_109 = 0 , V_110 = 0 , V_111 = 0 , V_112 = 0 , V_113 = 0 ;
if ( V_54 == NULL )
return 0 ;
while ( * V_54 ) {
if ( * V_54 == 'u' ) {
if ( ! V_106 )
V_106 = V_108 = V_109 = V_110 = 1 ;
V_108 = 0 ;
} else if ( * V_54 == 'k' ) {
if ( ! V_106 )
V_106 = V_108 = V_109 = V_110 = 1 ;
V_109 = 0 ;
} else if ( * V_54 == 'h' ) {
if ( ! V_106 )
V_106 = V_108 = V_109 = V_110 = 1 ;
V_110 = 0 ;
} else if ( * V_54 == 'G' ) {
if ( ! V_107 )
V_107 = V_112 = V_111 = 1 ;
V_112 = 0 ;
} else if ( * V_54 == 'H' ) {
if ( ! V_107 )
V_107 = V_112 = V_111 = 1 ;
V_111 = 0 ;
} else if ( * V_54 == 'p' ) {
V_113 ++ ;
} else
break;
++ V_54 ;
}
if ( V_113 > 3 )
return - V_10 ;
F_36 (evsel, list, node) {
V_37 -> V_38 . V_114 = V_108 ;
V_37 -> V_38 . V_115 = V_109 ;
V_37 -> V_38 . V_116 = V_110 ;
V_37 -> V_38 . V_117 = V_113 ;
V_37 -> V_38 . V_118 = V_111 ;
V_37 -> V_38 . V_119 = V_112 ;
}
return 0 ;
}
int F_45 ( struct V_120 * V_121 , const char * V_54 , int T_4 V_122 )
{
F_46 ( V_49 ) ;
F_46 ( V_123 ) ;
T_5 V_124 ;
int V_76 , V_50 = V_121 -> V_125 ;
V_124 = F_47 ( V_54 ) ;
V_76 = F_48 ( & V_49 , & V_123 , & V_50 ) ;
F_49 ( V_124 ) ;
F_50 ( V_124 ) ;
if ( ! V_76 ) {
int V_126 = V_50 - V_121 -> V_125 ;
F_51 ( V_121 , & V_49 , V_126 ) ;
return 0 ;
}
fprintf ( V_127 , L_30 , V_54 ) ;
fprintf ( V_127 , L_31 ) ;
return V_76 ;
}
int F_52 ( const struct V_128 * V_129 , const char * V_54 ,
int T_4 V_122 )
{
struct V_120 * V_121 = * (struct V_120 * * ) V_129 -> V_130 ;
return F_45 ( V_121 , V_54 , T_4 ) ;
}
int F_53 ( const struct V_128 * V_129 , const char * V_54 ,
int T_4 V_122 )
{
struct V_120 * V_121 = * (struct V_120 * * ) V_129 -> V_130 ;
struct V_36 * V_131 = NULL ;
if ( V_121 -> V_125 > 0 )
V_131 = F_54 ( V_121 -> V_126 . V_132 , struct V_36 , V_53 ) ;
if ( V_131 == NULL || V_131 -> V_38 . type != V_34 ) {
fprintf ( V_127 ,
L_32 ) ;
return - 1 ;
}
V_131 -> V_133 = F_24 ( V_54 ) ;
if ( V_131 -> V_133 == NULL ) {
fprintf ( V_127 , L_33 ) ;
return - 1 ;
}
return 0 ;
}
void F_55 ( const char * V_134 , const char * V_135 )
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
if ( V_134 != NULL &&
! F_30 ( V_16 . V_8 , V_134 ) )
continue;
snprintf ( V_20 , V_5 , L_2 , V_7 ,
V_16 . V_8 ) ;
V_3 = F_6 ( V_20 ) ;
if ( ! V_3 )
continue;
F_8 (sys_dirent, evt_dir, evt_dirent, evt_next) {
if ( V_135 != NULL &&
! F_30 ( V_17 . V_8 , V_135 ) )
continue;
snprintf ( V_4 , V_5 , L_4 ,
V_16 . V_8 , V_17 . V_8 ) ;
printf ( L_34 , V_4 ,
V_136 [ V_34 ] ) ;
}
F_11 ( V_3 ) ;
}
F_11 ( V_2 ) ;
}
int F_56 ( const char * V_137 )
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
if ( ! strcmp ( V_4 , V_137 ) ) {
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
void F_57 ( T_3 type )
{
struct V_138 * V_139 = V_140 ;
unsigned int V_58 ;
char V_22 [ 64 ] ;
for ( V_58 = 0 ; V_58 < F_58 ( V_140 ) ; V_58 ++ , V_139 ++ ) {
if ( type != V_139 -> type )
continue;
if ( strlen ( V_139 -> V_141 ) )
snprintf ( V_22 , sizeof( V_22 ) , L_35 ,
V_139 -> V_142 , V_139 -> V_141 ) ;
else
snprintf ( V_22 , sizeof( V_22 ) , L_19 , V_139 -> V_142 ) ;
printf ( L_34 , V_22 ,
V_136 [ type ] ) ;
}
}
int F_59 ( const char * V_135 )
{
unsigned int type , V_143 , V_58 , V_144 = 0 ;
for ( type = 0 ; type < V_43 ; type ++ ) {
for ( V_143 = 0 ; V_143 < V_44 ; V_143 ++ ) {
if ( ! F_14 ( type , V_143 ) )
continue;
for ( V_58 = 0 ; V_58 < V_45 ; V_58 ++ ) {
char * V_22 = F_16 ( type , V_143 , V_58 ) ;
if ( V_135 != NULL && ! F_30 ( V_22 , V_135 ) )
continue;
printf ( L_34 , V_22 ,
V_136 [ V_35 ] ) ;
++ V_144 ;
}
}
}
return V_144 ;
}
void F_60 ( const char * V_135 )
{
unsigned int V_58 , type , V_145 = - 1 , V_144 = 0 , V_146 = 0 ;
struct V_138 * V_139 = V_140 ;
char V_22 [ V_64 ] ;
printf ( L_36 ) ;
printf ( L_37 ) ;
for ( V_58 = 0 ; V_58 < F_58 ( V_140 ) ; V_58 ++ , V_139 ++ ) {
type = V_139 -> type ;
if ( type != V_145 && V_144 ) {
printf ( L_36 ) ;
V_144 = 0 ;
V_146 ++ ;
}
if ( V_135 != NULL &&
! ( F_30 ( V_139 -> V_142 , V_135 ) ||
( V_139 -> V_141 && F_30 ( V_139 -> V_141 , V_135 ) ) ) )
continue;
if ( strlen ( V_139 -> V_141 ) )
snprintf ( V_22 , V_64 , L_35 , V_139 -> V_142 , V_139 -> V_141 ) ;
else
strncpy ( V_22 , V_139 -> V_142 , V_64 ) ;
printf ( L_34 , V_22 ,
V_136 [ type ] ) ;
V_145 = type ;
++ V_144 ;
}
if ( V_146 ) {
V_144 = 0 ;
printf ( L_36 ) ;
}
F_59 ( V_135 ) ;
if ( V_135 != NULL )
return;
printf ( L_36 ) ;
printf ( L_34 ,
L_38 ,
V_136 [ V_39 ] ) ;
printf ( L_34 ,
L_39 ,
V_136 [ V_39 ] ) ;
printf ( L_40 ) ;
printf ( L_36 ) ;
printf ( L_34 ,
L_41 ,
V_136 [ V_87 ] ) ;
printf ( L_36 ) ;
F_55 ( NULL , NULL ) ;
}
int F_61 ( struct V_88 * V_89 )
{
return V_89 -> type <= V_147 ;
}
int F_62 ( struct V_88 * * V_148 , int type ,
char * V_12 , char * V_54 , long V_92 )
{
struct V_88 * V_89 ;
V_89 = F_12 ( sizeof( * V_89 ) ) ;
if ( ! V_89 )
return - V_52 ;
F_43 ( & V_89 -> V_49 ) ;
V_89 -> type = type ;
V_89 -> V_12 = V_12 ;
switch ( type ) {
case V_90 :
case V_93 :
case V_95 :
case V_97 :
case V_98 :
case V_149 :
V_89 -> V_91 . V_92 = V_92 ;
break;
case V_150 :
V_89 -> V_91 . V_54 = V_54 ;
break;
default:
return - V_10 ;
}
* V_148 = V_89 ;
return 0 ;
}
void F_63 ( struct V_48 * V_151 )
{
struct V_88 * V_89 , * V_152 ;
F_64 (term, h, terms, list)
free ( V_89 ) ;
free ( V_151 ) ;
}
