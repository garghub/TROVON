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
return V_59 ;
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
F_23 ( struct V_72 * V_73 , char * V_63 ,
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
F_27 ( struct V_72 * V_73 , const char * * V_66 ,
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
return F_23 ( V_73 , V_63 ,
V_64 , V_75 ) ;
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
const char * V_98 = V_48 + V_54 + 1 ;
if ( * V_98 != '\0' && * V_98 != ',' && * V_98 != ':' )
return V_59 ;
* V_66 = V_98 ;
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
char * V_99 ;
unsigned long type ;
T_1 V_12 ;
type = strtoul ( V_48 , & V_99 , 0 ) ;
if ( V_99 > V_48 && type < V_100 && * V_99 == ':' ) {
V_48 = V_99 + 1 ;
V_12 = strtoul ( V_48 , & V_99 , 0 ) ;
if ( V_99 > V_48 ) {
V_38 -> type = type ;
V_38 -> V_12 = V_12 ;
* V_66 = V_99 ;
return V_62 ;
}
}
return V_59 ;
}
static int
F_38 ( const char * * V_66 , struct V_57 * V_38 )
{
const char * V_48 = * V_66 ;
int V_101 = 0 , V_102 = 0 ;
int V_103 = 0 , V_104 = 0 , V_105 = 0 , V_106 = 0 , V_107 = 0 , V_108 = 0 ;
if ( ! * V_48 )
return 0 ;
if ( * V_48 == ',' )
return 0 ;
if ( * V_48 ++ != ':' )
return - 1 ;
while ( * V_48 ) {
if ( * V_48 == 'u' ) {
if ( ! V_101 )
V_101 = V_103 = V_104 = V_105 = 1 ;
V_103 = 0 ;
} else if ( * V_48 == 'k' ) {
if ( ! V_101 )
V_101 = V_103 = V_104 = V_105 = 1 ;
V_104 = 0 ;
} else if ( * V_48 == 'h' ) {
if ( ! V_101 )
V_101 = V_103 = V_104 = V_105 = 1 ;
V_105 = 0 ;
} else if ( * V_48 == 'G' ) {
if ( ! V_102 )
V_102 = V_107 = V_106 = 1 ;
V_107 = 0 ;
} else if ( * V_48 == 'H' ) {
if ( ! V_102 )
V_102 = V_107 = V_106 = 1 ;
V_106 = 0 ;
} else if ( * V_48 == 'p' ) {
V_108 ++ ;
} else
break;
++ V_48 ;
}
if ( V_48 < * V_66 + 2 )
return - 1 ;
* V_66 = V_48 ;
V_38 -> V_109 = V_103 ;
V_38 -> V_110 = V_104 ;
V_38 -> V_111 = V_105 ;
V_38 -> V_112 = V_108 ;
V_38 -> V_113 = V_106 ;
V_38 -> V_114 = V_107 ;
return 0 ;
}
static enum V_56
F_39 ( struct V_72 * V_73 , const char * * V_48 ,
struct V_57 * V_38 )
{
enum V_56 V_115 ;
V_115 = F_27 ( V_73 , V_48 , V_38 ) ;
if ( V_115 != V_59 )
goto V_116;
V_115 = F_35 ( V_48 , V_38 ) ;
if ( V_115 != V_59 )
goto V_116;
V_115 = F_37 ( V_48 , V_38 ) ;
if ( V_115 != V_59 )
goto V_116;
V_115 = F_33 ( V_48 , V_38 ) ;
if ( V_115 != V_59 )
goto V_116;
V_115 = F_21 ( V_48 , V_38 ) ;
if ( V_115 != V_59 )
goto V_116;
V_115 = F_30 ( V_48 , V_38 ) ;
if ( V_115 != V_59 )
goto V_116;
fprintf ( V_117 , L_29 , * V_48 ) ;
fprintf ( V_117 , L_30 ) ;
return V_59 ;
V_116:
if ( F_38 ( V_48 , V_38 ) < 0 ) {
fprintf ( V_117 , L_31 , * V_48 ) ;
fprintf ( V_117 , L_32 ) ;
return V_59 ;
}
return V_115 ;
}
int F_26 ( struct V_72 * V_73 , const char * V_48 , int T_4 V_118 )
{
struct V_57 V_38 ;
enum V_56 V_115 ;
const char * V_119 ;
for (; ; ) {
V_119 = V_48 ;
memset ( & V_38 , 0 , sizeof( V_38 ) ) ;
F_40 ( & V_38 ) ;
V_115 = F_39 ( V_73 , & V_48 , & V_38 ) ;
if ( V_115 == V_59 )
return - 1 ;
if ( ! ( * V_48 == 0 || * V_48 == ',' || isspace ( * V_48 ) ) )
return - 1 ;
if ( V_115 != V_80 ) {
struct V_36 * V_37 ;
V_37 = F_41 ( & V_38 , V_73 -> V_120 ) ;
if ( V_37 == NULL )
return - 1 ;
F_42 ( V_73 , V_37 ) ;
V_37 -> V_22 = calloc ( V_48 - V_119 + 1 , 1 ) ;
if ( ! V_37 -> V_22 )
return - 1 ;
strncpy ( V_37 -> V_22 , V_119 , V_48 - V_119 ) ;
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
int F_43 ( const struct V_121 * V_122 , const char * V_48 ,
int T_4 V_118 )
{
struct V_72 * V_73 = * (struct V_72 * * ) V_122 -> V_123 ;
return F_26 ( V_73 , V_48 , T_4 ) ;
}
int F_44 ( const struct V_121 * V_122 , const char * V_48 ,
int T_4 V_118 )
{
struct V_72 * V_73 = * (struct V_72 * * ) V_122 -> V_123 ;
struct V_36 * V_124 = NULL ;
if ( V_73 -> V_120 > 0 )
V_124 = F_45 ( V_73 -> V_125 . V_126 , struct V_36 , V_127 ) ;
if ( V_124 == NULL || V_124 -> V_38 . type != V_34 ) {
fprintf ( V_117 ,
L_33 ) ;
return - 1 ;
}
V_124 -> V_128 = F_46 ( V_48 ) ;
if ( V_124 -> V_128 == NULL ) {
fprintf ( V_117 , L_34 ) ;
return - 1 ;
}
return 0 ;
}
void F_47 ( const char * V_129 , const char * V_130 )
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
if ( V_129 != NULL &&
! F_25 ( V_16 . V_8 , V_129 ) )
continue;
snprintf ( V_20 , V_5 , L_2 , V_7 ,
V_16 . V_8 ) ;
V_3 = F_6 ( V_20 ) ;
if ( ! V_3 )
continue;
F_8 (sys_dirent, evt_dir, evt_dirent, evt_next) {
if ( V_130 != NULL &&
! F_25 ( V_17 . V_8 , V_130 ) )
continue;
snprintf ( V_4 , V_5 , L_4 ,
V_16 . V_8 , V_17 . V_8 ) ;
printf ( L_35 , V_4 ,
V_131 [ V_34 ] ) ;
}
F_11 ( V_3 ) ;
}
F_11 ( V_2 ) ;
}
int F_48 ( const char * V_132 )
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
if ( ! strcmp ( V_4 , V_132 ) ) {
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
void F_49 ( T_3 type )
{
struct V_133 * V_134 = V_95 ;
unsigned int V_52 ;
char V_22 [ 64 ] ;
for ( V_52 = 0 ; V_52 < F_34 ( V_95 ) ; V_52 ++ , V_134 ++ ) {
if ( type != V_134 -> type )
continue;
if ( strlen ( V_134 -> V_97 ) )
snprintf ( V_22 , sizeof( V_22 ) , L_36 ,
V_134 -> V_96 , V_134 -> V_97 ) ;
else
snprintf ( V_22 , sizeof( V_22 ) , L_37 , V_134 -> V_96 ) ;
printf ( L_35 , V_22 ,
V_131 [ type ] ) ;
}
}
int F_50 ( const char * V_130 )
{
unsigned int type , V_135 , V_52 , V_136 = 0 ;
for ( type = 0 ; type < V_43 ; type ++ ) {
for ( V_135 = 0 ; V_135 < V_44 ; V_135 ++ ) {
if ( ! F_14 ( type , V_135 ) )
continue;
for ( V_52 = 0 ; V_52 < V_45 ; V_52 ++ ) {
char * V_22 = F_16 ( type , V_135 , V_52 ) ;
if ( V_130 != NULL && ! F_25 ( V_22 , V_130 ) )
continue;
printf ( L_35 , V_22 ,
V_131 [ V_35 ] ) ;
++ V_136 ;
}
}
}
return V_136 ;
}
void F_51 ( const char * V_130 )
{
unsigned int V_52 , type , V_137 = - 1 , V_136 = 0 , V_138 = 0 ;
struct V_133 * V_134 = V_95 ;
char V_22 [ V_139 ] ;
printf ( L_38 ) ;
printf ( L_39 ) ;
for ( V_52 = 0 ; V_52 < F_34 ( V_95 ) ; V_52 ++ , V_134 ++ ) {
type = V_134 -> type ;
if ( type != V_137 && V_136 ) {
printf ( L_38 ) ;
V_136 = 0 ;
V_138 ++ ;
}
if ( V_130 != NULL &&
! ( F_25 ( V_134 -> V_96 , V_130 ) ||
( V_134 -> V_97 && F_25 ( V_134 -> V_97 , V_130 ) ) ) )
continue;
if ( strlen ( V_134 -> V_97 ) )
snprintf ( V_22 , V_139 , L_36 , V_134 -> V_96 , V_134 -> V_97 ) ;
else
strncpy ( V_22 , V_134 -> V_96 , V_139 ) ;
printf ( L_35 , V_22 ,
V_131 [ type ] ) ;
V_137 = type ;
++ V_136 ;
}
if ( V_138 ) {
V_136 = 0 ;
printf ( L_38 ) ;
}
F_50 ( V_130 ) ;
if ( V_130 != NULL )
return;
printf ( L_38 ) ;
printf ( L_35 ,
L_40 ,
V_131 [ V_39 ] ) ;
printf ( L_38 ) ;
printf ( L_35 ,
L_41 ,
V_131 [ V_94 ] ) ;
printf ( L_38 ) ;
F_47 ( NULL , NULL ) ;
}
