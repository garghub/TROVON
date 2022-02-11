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
char V_18 [ 4 ] ;
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
static int F_20 ( const char * * V_48 , const char * V_49 [] [ V_50 ] , int V_51 )
{
int V_52 , V_53 ;
int V_54 , V_55 = - 1 ;
for ( V_52 = 0 ; V_52 < V_51 ; V_52 ++ ) {
for ( V_53 = 0 ; V_53 < V_50 && V_49 [ V_52 ] [ V_53 ] ; V_53 ++ ) {
V_54 = strlen ( V_49 [ V_52 ] [ V_53 ] ) ;
if ( V_54 > V_55 && ! strncasecmp ( * V_48 , V_49 [ V_52 ] [ V_53 ] , V_54 ) )
V_55 = V_54 ;
}
if ( V_55 > 0 ) {
* V_48 += V_55 ;
return V_52 ;
}
}
return - 1 ;
}
static enum V_56
F_21 ( const char * * V_48 , struct V_57 * V_38 )
{
const char * V_58 = * V_48 ;
int V_25 = - 1 , V_26 = - 1 , V_28 = - 1 ;
V_25 = F_20 ( & V_58 , V_29 , V_43 ) ;
if ( V_25 == - 1 )
return V_59 ;
while ( ( V_26 == - 1 || V_28 == - 1 ) && * V_58 == '-' ) {
++ V_58 ;
if ( V_26 == - 1 ) {
V_26 = F_20 ( & V_58 , V_30 ,
V_44 ) ;
if ( V_26 >= 0 ) {
if ( ! F_14 ( V_25 , V_26 ) )
return 0 ;
continue;
}
}
if ( V_28 == - 1 ) {
V_28 = F_20 ( & V_58 , V_31 ,
V_45 ) ;
if ( V_28 >= 0 )
continue;
}
-- V_58 ;
break;
}
if ( V_26 == - 1 )
V_26 = V_60 ;
if ( V_28 == - 1 )
V_28 = V_61 ;
V_38 -> V_12 = V_25 | ( V_26 << 8 ) | ( V_28 << 16 ) ;
V_38 -> type = V_35 ;
* V_48 = V_58 ;
return V_62 ;
}
static enum V_56
F_22 ( char * V_63 ,
const char * V_64 ,
unsigned int V_65 ,
struct V_57 * V_38 ,
const char * * V_66 )
{
char V_4 [ V_5 ] ;
char V_18 [ 4 ] ;
T_1 V_19 ;
int V_6 ;
snprintf ( V_4 , V_5 , L_1 , V_7 ,
V_63 , V_64 ) ;
V_6 = F_2 ( V_4 , V_9 ) ;
if ( V_6 < 0 )
return V_59 ;
if ( F_9 ( V_6 , V_18 , sizeof( V_18 ) ) < 0 ) {
F_3 ( V_6 ) ;
return V_59 ;
}
F_3 ( V_6 ) ;
V_19 = F_10 ( V_18 ) ;
V_38 -> V_12 = V_19 ;
V_38 -> type = V_34 ;
* V_66 += strlen ( V_63 ) + V_65 + 1 ;
V_38 -> V_67 |= V_68 ;
V_38 -> V_67 |= V_69 ;
V_38 -> V_67 |= V_70 ;
V_38 -> V_71 = 1 ;
return V_62 ;
}
static enum V_56
F_23 ( const struct V_72 * V_73 , char * V_63 ,
const char * V_74 , char * V_75 )
{
char V_4 [ V_5 ] ;
struct V_1 * V_76 ;
T_2 * V_3 ;
snprintf ( V_4 , V_5 , L_2 , V_7 , V_63 ) ;
V_3 = F_6 ( V_4 ) ;
if ( ! V_3 ) {
perror ( L_19 ) ;
return V_59 ;
}
while ( ( V_76 = F_24 ( V_3 ) ) ) {
char V_77 [ V_78 + 1 ] ;
int V_79 ;
if ( ! strcmp ( V_76 -> V_8 , L_20 )
|| ! strcmp ( V_76 -> V_8 , L_21 )
|| ! strcmp ( V_76 -> V_8 , L_22 )
|| ! strcmp ( V_76 -> V_8 , L_23 ) )
continue;
if ( ! F_25 ( V_76 -> V_8 , V_74 ) )
continue;
V_79 = snprintf ( V_77 , V_78 , L_24 , V_63 ,
V_76 -> V_8 , V_75 ? L_25 : L_26 ,
V_75 ? : L_26 ) ;
if ( V_79 < 0 )
return V_59 ;
if ( F_26 ( V_73 , V_77 , 0 ) )
return V_59 ;
}
return V_80 ;
}
static enum V_56
F_27 ( const struct V_72 * V_73 , const char * * V_66 ,
struct V_57 * V_38 )
{
const char * V_64 ;
char * V_75 = NULL , * V_81 ;
char V_63 [ V_21 ] ;
unsigned int V_82 , V_65 ;
if ( F_5 ( V_7 ) )
return 0 ;
V_64 = strchr ( * V_66 , ':' ) ;
if ( ! V_64 )
return V_59 ;
V_82 = V_64 - * V_66 ;
if ( V_82 >= V_21 )
return 0 ;
strncpy ( V_63 , * V_66 , V_82 ) ;
V_63 [ V_82 ] = '\0' ;
V_64 = V_64 + 1 ;
V_81 = strchr ( V_64 , ',' ) ;
if ( V_81 ) {
V_64 = F_28 ( V_64 , V_81 - V_64 ) ;
}
V_75 = strchr ( V_64 , ':' ) ;
if ( V_75 ) {
V_64 = F_28 ( V_64 , V_75 - V_64 ) ;
V_75 ++ ;
}
V_65 = strlen ( V_64 ) ;
if ( V_65 >= V_21 )
return V_59 ;
if ( strpbrk ( V_64 , L_27 ) ) {
* V_66 += strlen ( V_63 ) + V_65 + 1 ;
return F_23 ( V_73 , V_63 , V_64 ,
V_75 ) ;
} else {
return F_22 ( V_63 , V_64 ,
V_65 , V_38 , V_66 ) ;
}
}
static enum V_56
F_29 ( const char * type , const char * * V_66 ,
struct V_57 * V_38 )
{
int V_52 ;
for ( V_52 = 0 ; V_52 < 3 ; V_52 ++ ) {
if ( ! type [ V_52 ] )
break;
switch ( type [ V_52 ] ) {
case 'r' :
V_38 -> V_83 |= V_84 ;
break;
case 'w' :
V_38 -> V_83 |= V_85 ;
break;
case 'x' :
V_38 -> V_83 |= V_86 ;
break;
default:
return V_59 ;
}
}
if ( ! V_38 -> V_83 )
V_38 -> V_83 = V_84 | V_85 ;
* V_66 = type + V_52 ;
return V_62 ;
}
static enum V_56
F_30 ( const char * * V_66 , struct V_57 * V_38 )
{
const char * V_87 ;
const char * type ;
char * V_88 ;
T_1 V_89 ;
enum V_56 V_90 ;
V_87 = strchr ( * V_66 , ':' ) ;
if ( ! V_87 )
return V_59 ;
if ( strncmp ( * V_66 , L_28 , V_87 - * V_66 ) != 0 )
return V_59 ;
V_87 ++ ;
V_89 = F_31 ( V_87 , & V_88 , 0 ) ;
if ( V_87 == V_88 )
return V_59 ;
V_38 -> V_91 = V_89 ;
* V_66 = V_88 ;
type = strchr ( V_87 , ':' ) ;
if ( ! type ) {
V_38 -> V_83 = V_84 | V_85 ;
} else {
V_90 = F_29 ( ++ type , V_66 , V_38 ) ;
if ( V_90 == V_59 )
return V_59 ;
}
if ( V_38 -> V_83 == V_86 )
V_38 -> V_92 = sizeof( long ) ;
else
V_38 -> V_92 = V_93 ;
V_38 -> type = V_94 ;
return V_62 ;
}
static int F_32 ( const char * V_48 , unsigned int V_52 )
{
int V_54 ;
V_54 = strlen ( V_95 [ V_52 ] . V_96 ) ;
if ( ! strncasecmp ( V_48 , V_95 [ V_52 ] . V_96 , V_54 ) )
return V_54 ;
V_54 = strlen ( V_95 [ V_52 ] . V_97 ) ;
if ( V_54 ) {
if ( ! strncasecmp ( V_48 , V_95 [ V_52 ] . V_97 , V_54 ) )
return V_54 ;
}
return 0 ;
}
static enum V_56
F_33 ( const char * * V_66 , struct V_57 * V_38 )
{
const char * V_48 = * V_66 ;
unsigned int V_52 ;
int V_54 ;
for ( V_52 = 0 ; V_52 < F_34 ( V_95 ) ; V_52 ++ ) {
V_54 = F_32 ( V_48 , V_52 ) ;
if ( V_54 > 0 ) {
V_38 -> type = V_95 [ V_52 ] . type ;
V_38 -> V_12 = V_95 [ V_52 ] . V_12 ;
* V_66 = V_48 + V_54 ;
return V_62 ;
}
}
return V_59 ;
}
static enum V_56
F_35 ( const char * * V_66 , struct V_57 * V_38 )
{
const char * V_48 = * V_66 ;
T_1 V_12 ;
int V_54 ;
if ( * V_48 != 'r' )
return V_59 ;
V_54 = F_36 ( V_48 + 1 , & V_12 ) ;
if ( V_54 > 0 ) {
* V_66 = V_48 + V_54 + 1 ;
V_38 -> type = V_39 ;
V_38 -> V_12 = V_12 ;
return V_62 ;
}
return V_59 ;
}
static enum V_56
F_37 ( const char * * V_66 , struct V_57 * V_38 )
{
const char * V_48 = * V_66 ;
char * V_98 ;
unsigned long type ;
T_1 V_12 ;
type = strtoul ( V_48 , & V_98 , 0 ) ;
if ( V_98 > V_48 && type < V_99 && * V_98 == ':' ) {
V_48 = V_98 + 1 ;
V_12 = strtoul ( V_48 , & V_98 , 0 ) ;
if ( V_98 > V_48 ) {
V_38 -> type = type ;
V_38 -> V_12 = V_12 ;
* V_66 = V_98 ;
return V_62 ;
}
}
return V_59 ;
}
static int
F_38 ( const char * * V_66 , struct V_57 * V_38 )
{
const char * V_48 = * V_66 ;
int V_100 = 0 ;
int V_101 = 0 , V_102 = 0 , V_103 = 0 , V_104 = 0 ;
if ( ! * V_48 )
return 0 ;
if ( * V_48 == ',' )
return 0 ;
if ( * V_48 ++ != ':' )
return - 1 ;
while ( * V_48 ) {
if ( * V_48 == 'u' ) {
if ( ! V_100 )
V_100 = V_101 = V_102 = V_103 = 1 ;
V_101 = 0 ;
} else if ( * V_48 == 'k' ) {
if ( ! V_100 )
V_100 = V_101 = V_102 = V_103 = 1 ;
V_102 = 0 ;
} else if ( * V_48 == 'h' ) {
if ( ! V_100 )
V_100 = V_101 = V_102 = V_103 = 1 ;
V_103 = 0 ;
} else if ( * V_48 == 'p' ) {
V_104 ++ ;
} else
break;
++ V_48 ;
}
if ( V_48 < * V_66 + 2 )
return - 1 ;
* V_66 = V_48 ;
V_38 -> V_105 = V_101 ;
V_38 -> V_106 = V_102 ;
V_38 -> V_107 = V_103 ;
V_38 -> V_108 = V_104 ;
return 0 ;
}
static enum V_56
F_39 ( const struct V_72 * V_73 , const char * * V_48 ,
struct V_57 * V_38 )
{
enum V_56 V_109 ;
V_109 = F_27 ( V_73 , V_48 , V_38 ) ;
if ( V_109 != V_59 )
goto V_110;
V_109 = F_35 ( V_48 , V_38 ) ;
if ( V_109 != V_59 )
goto V_110;
V_109 = F_37 ( V_48 , V_38 ) ;
if ( V_109 != V_59 )
goto V_110;
V_109 = F_33 ( V_48 , V_38 ) ;
if ( V_109 != V_59 )
goto V_110;
V_109 = F_21 ( V_48 , V_38 ) ;
if ( V_109 != V_59 )
goto V_110;
V_109 = F_30 ( V_48 , V_38 ) ;
if ( V_109 != V_59 )
goto V_110;
fprintf ( V_111 , L_29 , * V_48 ) ;
fprintf ( V_111 , L_30 ) ;
return V_59 ;
V_110:
if ( F_38 ( V_48 , V_38 ) < 0 ) {
fprintf ( V_111 , L_31 , * V_48 ) ;
fprintf ( V_111 , L_32 ) ;
return V_59 ;
}
return V_109 ;
}
int F_26 ( const struct V_72 * V_73 , const char * V_48 , int T_4 V_112 )
{
struct V_113 * V_114 = * (struct V_113 * * ) V_73 -> V_115 ;
struct V_57 V_38 ;
enum V_56 V_109 ;
const char * V_116 ;
for (; ; ) {
V_116 = V_48 ;
memset ( & V_38 , 0 , sizeof( V_38 ) ) ;
V_109 = F_39 ( V_73 , & V_48 , & V_38 ) ;
if ( V_109 == V_59 )
return - 1 ;
if ( ! ( * V_48 == 0 || * V_48 == ',' || isspace ( * V_48 ) ) )
return - 1 ;
if ( V_109 != V_80 ) {
struct V_36 * V_37 ;
V_37 = F_40 ( & V_38 , V_114 -> V_117 ) ;
if ( V_37 == NULL )
return - 1 ;
F_41 ( V_114 , V_37 ) ;
V_37 -> V_22 = calloc ( V_48 - V_116 + 1 , 1 ) ;
if ( ! V_37 -> V_22 )
return - 1 ;
strncpy ( V_37 -> V_22 , V_116 , V_48 - V_116 ) ;
}
if ( * V_48 == 0 )
break;
if ( * V_48 == ',' )
++ V_48 ;
while ( isspace ( * V_48 ) )
++ V_48 ;
}
return 0 ;
}
int F_42 ( const struct V_72 * V_73 , const char * V_48 ,
int T_4 V_112 )
{
struct V_113 * V_114 = * (struct V_113 * * ) V_73 -> V_115 ;
struct V_36 * V_118 = NULL ;
if ( V_114 -> V_117 > 0 )
V_118 = F_43 ( V_114 -> V_119 . V_120 , struct V_36 , V_121 ) ;
if ( V_118 == NULL || V_118 -> V_38 . type != V_34 ) {
fprintf ( V_111 ,
L_33 ) ;
return - 1 ;
}
V_118 -> V_122 = F_44 ( V_48 ) ;
if ( V_118 -> V_122 == NULL ) {
fprintf ( V_111 , L_34 ) ;
return - 1 ;
}
return 0 ;
}
void F_45 ( const char * V_123 , const char * V_124 )
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
if ( V_123 != NULL &&
! F_25 ( V_16 . V_8 , V_123 ) )
continue;
snprintf ( V_20 , V_5 , L_2 , V_7 ,
V_16 . V_8 ) ;
V_3 = F_6 ( V_20 ) ;
if ( ! V_3 )
continue;
F_8 (sys_dirent, evt_dir, evt_dirent, evt_next) {
if ( V_124 != NULL &&
! F_25 ( V_17 . V_8 , V_124 ) )
continue;
snprintf ( V_4 , V_5 , L_4 ,
V_16 . V_8 , V_17 . V_8 ) ;
printf ( L_35 , V_4 ,
V_125 [ V_34 ] ) ;
}
F_11 ( V_3 ) ;
}
F_11 ( V_2 ) ;
}
int F_46 ( const char * V_126 )
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
if ( ! strcmp ( V_4 , V_126 ) ) {
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
void F_47 ( T_3 type )
{
struct V_127 * V_128 = V_95 ;
unsigned int V_52 ;
char V_22 [ 64 ] ;
for ( V_52 = 0 ; V_52 < F_34 ( V_95 ) ; V_52 ++ , V_128 ++ ) {
if ( type != V_128 -> type )
continue;
if ( strlen ( V_128 -> V_97 ) )
snprintf ( V_22 , sizeof( V_22 ) , L_36 ,
V_128 -> V_96 , V_128 -> V_97 ) ;
else
snprintf ( V_22 , sizeof( V_22 ) , L_37 , V_128 -> V_96 ) ;
printf ( L_35 , V_22 ,
V_125 [ type ] ) ;
}
}
int F_48 ( const char * V_124 )
{
unsigned int type , V_129 , V_52 , V_130 = 0 ;
for ( type = 0 ; type < V_43 ; type ++ ) {
for ( V_129 = 0 ; V_129 < V_44 ; V_129 ++ ) {
if ( ! F_14 ( type , V_129 ) )
continue;
for ( V_52 = 0 ; V_52 < V_45 ; V_52 ++ ) {
char * V_22 = F_16 ( type , V_129 , V_52 ) ;
if ( V_124 != NULL && ! F_25 ( V_22 , V_124 ) )
continue;
printf ( L_35 , V_22 ,
V_125 [ V_35 ] ) ;
++ V_130 ;
}
}
}
return V_130 ;
}
void F_49 ( const char * V_124 )
{
unsigned int V_52 , type , V_131 = - 1 , V_130 = 0 , V_132 = 0 ;
struct V_127 * V_128 = V_95 ;
char V_22 [ V_133 ] ;
printf ( L_38 ) ;
printf ( L_39 ) ;
for ( V_52 = 0 ; V_52 < F_34 ( V_95 ) ; V_52 ++ , V_128 ++ ) {
type = V_128 -> type ;
if ( type != V_131 && V_130 ) {
printf ( L_38 ) ;
V_130 = 0 ;
V_132 ++ ;
}
if ( V_124 != NULL &&
! ( F_25 ( V_128 -> V_96 , V_124 ) ||
( V_128 -> V_97 && F_25 ( V_128 -> V_97 , V_124 ) ) ) )
continue;
if ( strlen ( V_128 -> V_97 ) )
snprintf ( V_22 , V_133 , L_36 , V_128 -> V_96 , V_128 -> V_97 ) ;
else
strncpy ( V_22 , V_128 -> V_96 , V_133 ) ;
printf ( L_35 , V_22 ,
V_125 [ type ] ) ;
V_131 = type ;
++ V_130 ;
}
if ( V_132 ) {
V_130 = 0 ;
printf ( L_38 ) ;
}
F_48 ( V_124 ) ;
if ( V_124 != NULL )
return;
printf ( L_38 ) ;
printf ( L_35 ,
L_40 ,
V_125 [ V_39 ] ) ;
printf ( L_38 ) ;
printf ( L_35 ,
L_41 ,
V_125 [ V_94 ] ) ;
printf ( L_38 ) ;
F_45 ( NULL , NULL ) ;
exit ( 129 ) ;
}
