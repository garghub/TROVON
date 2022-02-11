int F_1 ( int V_1 , int V_2 , const char * V_3 , ... )
{
int V_4 ;
T_1 args ;
if ( V_2 < V_1 )
return 0 ;
va_start ( args , V_3 ) ;
V_4 = vfprintf ( V_5 , V_3 , args ) ;
va_end ( args ) ;
return V_4 ;
}
char * F_2 ( void )
{
return NULL ;
}
static void F_3 ( char * V_6 , char * * V_7 , const char * V_8 ,
const char * V_9 , T_2 * V_10 )
{
unsigned int V_11 = strlen ( V_9 ) + 1 + strlen ( V_8 ) ;
int V_12 = * V_7 ? strlen ( * V_7 ) : 0 ;
int V_13 = V_10 ? F_4 ( V_10 ) : 0 ;
char * V_14 ;
V_14 = realloc ( * V_7 , V_11 + V_12 + V_13 ) ;
if ( ! V_14 ) {
return;
}
* V_7 = V_14 ;
if ( ! V_12 )
* ( * V_7 ) = 0 ;
else
strcat ( * V_7 , V_8 ) ;
strcat ( * V_7 , V_9 ) ;
if ( V_10 )
strncat ( * V_7 , V_6 + V_10 -> V_15 , V_13 ) ;
}
static void F_5 ( char * V_16 )
{
for (; * V_16 ; V_16 ++ )
* V_16 = tolower ( * V_16 ) ;
}
static void F_6 ( char * V_16 )
{
char * V_17 = V_16 + strlen ( V_16 ) ;
-- V_17 ;
while ( V_17 >= V_16 && isspace ( * V_17 ) )
-- V_17 ;
if ( * V_17 == '.' )
* V_17 = 0 ;
}
static void F_7 ( char * V_6 , T_2 * V_18 )
{
int V_19 ;
for ( V_19 = V_18 -> V_15 ; V_19 < V_18 -> V_20 ; V_19 ++ ) {
if ( V_6 [ V_19 ] == ',' )
V_18 -> V_20 = V_19 ;
}
}
static int F_8 ( char * V_6 , T_2 * V_21 , int V_22 ,
char * * V_23 , T_2 * V_24 )
{
struct V_21 * V_25 ;
T_2 V_18 = * V_24 ;
for ( V_25 = V_26 ; V_25 -> V_21 ; V_25 ++ )
if ( F_9 ( V_6 , V_21 , V_25 -> V_21 ) && V_22 ) {
F_7 ( V_6 , & V_18 ) ;
F_3 ( V_6 , V_23 , L_1 , V_25 -> V_27 , & V_18 ) ;
return 1 ;
}
return 0 ;
}
static struct V_28 * F_10 ( char * V_6 , T_2 * V_24 )
{
T_2 V_18 = * V_24 ;
static bool V_29 ;
int V_19 ;
F_7 ( V_6 , & V_18 ) ;
for ( V_19 = 0 ; V_28 [ V_19 ] . V_30 ; V_19 ++ )
if ( F_9 ( V_6 , & V_18 , V_28 [ V_19 ] . V_30 ) )
return & V_28 [ V_19 ] ;
if ( ! V_29 ) {
V_29 = true ;
F_11 ( L_2 , V_31 ,
F_4 ( V_24 ) , V_6 + V_24 -> V_15 ) ;
}
return NULL ;
}
static char * F_12 ( void )
{
char * V_32 , * V_33 = NULL ;
int V_19 ;
for ( V_19 = 0 ; V_19 < V_34 + 1 ; V_19 ++ ) {
int V_35 ;
V_32 = V_33 ;
V_35 = F_13 ( & V_33 , L_3 , V_33 ? : L_4 , V_36 [ V_19 ] ) ;
if ( V_35 < 0 ) {
F_14 ( L_5 , V_31 ) ;
return NULL ;
}
free ( V_32 ) ;
}
for ( V_19 = 0 ; V_19 < ( int ) strlen ( V_33 ) ; V_19 ++ ) {
char V_37 = V_33 [ V_19 ] ;
if ( V_37 == '-' )
V_33 [ V_19 ] = ' ' ;
else if ( V_37 == '.' ) {
V_33 [ V_19 ] = '\0' ;
break;
}
}
return V_33 ;
}
static int F_15 ( int V_1 , char * V_38 )
{
char * V_39 ;
V_1 -= 2 ;
if ( V_1 >= V_40 )
return - V_41 ;
V_39 = F_16 ( V_38 ) ;
if ( ! V_39 ) {
F_14 ( L_6 , V_31 ,
strerror ( V_42 ) , V_38 ) ;
return - V_43 ;
}
free ( V_36 [ V_34 ] ) ;
V_36 [ V_34 ] = V_39 ;
V_34 = V_1 ;
return 0 ;
}
static void F_17 ( T_3 * V_44 , const char * V_45 )
{
fprintf ( V_44 , L_7 , V_45 ) ;
V_46 = 1 ;
}
static int F_18 ( void * V_47 , char * V_48 , char * V_23 ,
char * V_49 , char * V_50 )
{
struct V_51 * V_52 = V_47 ;
T_3 * V_53 = V_52 -> V_53 ;
char * V_39 = V_52 -> V_39 ;
fprintf ( V_53 , L_8 ) ;
fprintf ( V_53 , L_9 , V_48 ) ;
fprintf ( V_53 , L_10 , V_23 ) ;
fprintf ( V_53 , L_11 , V_49 ) ;
fprintf ( V_53 , L_12 , V_39 ) ;
if ( V_50 && V_50 [ 0 ] )
fprintf ( V_53 , L_13 , V_50 ) ;
fprintf ( V_53 , L_14 ) ;
return 0 ;
}
static void F_19 ( T_3 * V_53 )
{
fprintf ( V_53 , L_8 ) ;
fprintf ( V_53 , L_15 ) ;
fprintf ( V_53 , L_16 ) ;
fprintf ( V_53 , L_17 ) ;
fprintf ( V_53 , L_14 ) ;
fprintf ( V_53 , L_18 ) ;
V_46 = 0 ;
}
static char * F_20 ( const char * V_48 , char * V_23 )
{
int V_19 ;
for ( V_19 = 0 ; V_54 [ V_19 ] . V_48 ; V_19 ++ )
if ( ! strcasecmp ( V_48 , V_54 [ V_19 ] . V_48 ) )
return ( char * ) V_54 [ V_19 ] . V_23 ;
return V_23 ;
}
int F_21 ( const char * V_55 ,
int (* F_22)( void * V_47 , char * V_48 , char * V_23 , char * V_49 ,
char * V_50 ) ,
void * V_47 )
{
int V_56 = - V_57 ;
T_4 V_58 ;
T_2 * V_59 , * V_60 ;
int V_19 , V_61 , V_11 ;
char * V_6 ;
if ( ! V_55 )
return - V_62 ;
V_59 = F_23 ( V_55 , & V_6 , & V_58 , & V_11 ) ;
if ( ! V_59 )
return - V_57 ;
F_24 ( V_59 -> type == V_63 , V_59 , L_19 ) ;
V_60 = V_59 + 1 ;
for ( V_19 = 0 ; V_19 < V_59 -> V_58 ; V_19 ++ ) {
char * V_23 = NULL , * V_49 = NULL , * V_48 = NULL ;
char * V_50 = NULL ;
char * V_64 = NULL ;
struct V_28 * V_65 = NULL ;
T_2 * V_66 = NULL ;
T_2 * V_67 = NULL ;
T_2 * V_68 = V_60 ++ ;
F_24 ( V_68 -> type == V_69 , V_68 , L_20 ) ;
for ( V_61 = 0 ; V_61 < V_68 -> V_58 ; V_61 += 2 ) {
T_2 * V_21 , * V_24 ;
int V_22 ;
V_21 = V_60 + V_61 ;
F_24 ( V_21 -> type == V_70 , V_60 + V_61 ,
L_21 ) ;
V_24 = V_60 + V_61 + 1 ;
F_24 ( V_24 -> type == V_70 , V_60 + V_61 + 1 ,
L_22 ) ;
V_22 = ! F_9 ( V_6 , V_24 , L_23 ) ;
if ( F_8 ( V_6 , V_21 , V_22 , & V_23 , V_24 ) ) {
} else if ( F_9 ( V_6 , V_21 , L_24 ) ) {
F_3 ( V_6 , & V_48 , L_4 , L_4 , V_24 ) ;
} else if ( F_9 ( V_6 , V_21 , L_25 ) ) {
F_3 ( V_6 , & V_49 , L_4 , L_4 , V_24 ) ;
F_6 ( V_49 ) ;
} else if ( F_9 ( V_6 , V_21 ,
L_26 ) ) {
F_3 ( V_6 , & V_50 , L_4 , L_4 , V_24 ) ;
F_6 ( V_50 ) ;
} else if ( F_9 ( V_6 , V_21 , L_27 ) && V_22 ) {
V_67 = V_24 ;
} else if ( F_9 ( V_6 , V_21 , L_28 ) && V_22 ) {
V_65 = F_10 ( V_6 , V_24 ) ;
} else if ( F_9 ( V_6 , V_21 , L_29 ) ) {
V_66 = V_24 ;
} else if ( F_9 ( V_6 , V_21 , L_30 ) &&
! F_9 ( V_6 , V_24 , L_31 ) ) {
F_3 ( V_6 , & V_64 , L_32 ,
L_33 , V_24 ) ;
} else if ( F_9 ( V_6 , V_21 , L_34 ) && V_22 ) {
F_3 ( V_6 , & V_64 , L_32 ,
L_35 ,
NULL ) ;
}
}
if ( V_67 && V_49 && ! strstr ( V_49 , L_36 ) ) {
if ( F_9 ( V_6 , V_67 , L_37 ) )
F_3 ( V_6 , & V_64 , L_38 ,
L_39 , NULL ) ;
else
F_3 ( V_6 , & V_64 , L_38 ,
L_40 , NULL ) ;
}
if ( V_49 && V_64 )
F_3 ( V_6 , & V_49 , L_38 , V_64 , NULL ) ;
if ( V_50 && V_64 )
F_3 ( V_6 , & V_50 , L_38 , V_64 , NULL ) ;
if ( V_65 != NULL )
F_3 ( V_6 , & V_23 , L_1 , V_65 -> V_71 , V_66 ) ;
F_5 ( V_48 ) ;
V_56 = F_22 ( V_47 , V_48 , F_20 ( V_48 , V_23 ) , V_49 , V_50 ) ;
free ( V_23 ) ;
free ( V_49 ) ;
free ( V_48 ) ;
free ( V_50 ) ;
free ( V_64 ) ;
if ( V_56 )
break;
V_60 += V_61 ;
}
F_24 ( V_60 - V_59 == V_11 , V_60 , L_41 ) ;
V_56 = 0 ;
V_72:
F_25 ( V_6 , V_58 , V_59 ) ;
return V_56 ;
}
static char * F_26 ( char * V_73 )
{
unsigned int V_19 ;
int V_35 ;
int V_37 ;
char * V_45 ;
V_35 = F_13 ( & V_45 , L_42 , F_27 ( V_73 ) ) ;
if ( V_35 < 0 ) {
F_14 ( L_43 , V_31 ,
strerror ( V_42 ) , V_73 ) ;
return NULL ;
}
for ( V_19 = 0 ; V_19 < strlen ( V_45 ) ; V_19 ++ ) {
V_37 = V_45 [ V_19 ] ;
if ( V_37 == '-' )
V_45 [ V_19 ] = '_' ;
else if ( V_37 == '.' ) {
V_45 [ V_19 ] = '\0' ;
break;
} else if ( ! isalnum ( V_37 ) && V_37 != '_' ) {
F_11 ( L_44 ,
V_31 , V_37 , F_27 ( V_73 ) ) ;
free ( V_45 ) ;
V_45 = NULL ;
break;
}
}
return V_45 ;
}
static void F_28 ( T_3 * V_53 )
{
fprintf ( V_53 , L_45 ) ;
}
static void F_29 ( T_3 * V_53 )
{
fprintf ( V_53 , L_8 ) ;
fprintf ( V_53 , L_46 ) ;
fprintf ( V_53 , L_47 ) ;
fprintf ( V_53 , L_48 ) ;
fprintf ( V_53 , L_49 ) ;
fprintf ( V_53 , L_14 ) ;
fprintf ( V_53 , L_18 ) ;
}
static int F_30 ( T_3 * V_53 , char * V_74 )
{
int V_35 = 16384 ;
T_3 * V_75 ;
char * V_76 = NULL ;
char * line , * V_77 ;
int V_78 ;
char * V_45 ;
F_14 ( L_50 , V_31 , V_74 ) ;
line = malloc ( V_35 ) ;
if ( ! line )
return - 1 ;
V_75 = fopen ( V_74 , L_51 ) ;
if ( ! V_75 ) {
F_14 ( L_52 , V_31 , strerror ( V_42 ) ,
V_74 ) ;
return - 1 ;
}
F_28 ( V_53 ) ;
V_77 = fgets ( line , V_35 , V_75 ) ;
if ( ! V_77 )
goto V_14;
V_78 = 1 ;
while ( 1 ) {
char * V_79 , * V_80 , * type , * V_73 ;
V_78 ++ ;
V_77 = fgets ( line , V_35 , V_75 ) ;
if ( ! V_77 )
break;
if ( line [ 0 ] == '#' || line [ 0 ] == '\n' )
continue;
if ( line [ strlen ( line ) - 1 ] != '\n' ) {
F_14 ( L_53 ,
V_31 , V_74 , V_78 ) ;
return - 1 ;
}
line [ strlen ( line ) - 1 ] = '\0' ;
V_79 = strtok_r ( V_77 , L_1 , & V_76 ) ;
V_80 = strtok_r ( NULL , L_1 , & V_76 ) ;
V_73 = strtok_r ( NULL , L_1 , & V_76 ) ;
type = strtok_r ( NULL , L_1 , & V_76 ) ;
V_45 = F_26 ( V_73 ) ;
fprintf ( V_53 , L_8 ) ;
fprintf ( V_53 , L_54 , V_79 ) ;
fprintf ( V_53 , L_55 , V_80 ) ;
fprintf ( V_53 , L_56 , type ) ;
fprintf ( V_53 , L_57 , V_45 ) ;
fprintf ( V_53 , L_14 ) ;
}
V_14:
F_29 ( V_53 ) ;
return 0 ;
}
static void F_31 ( const char * V_81 )
{
T_3 * V_53 ;
F_14 ( L_58 , V_31 ) ;
V_53 = fopen ( V_81 , L_59 ) ;
if ( ! V_53 ) {
perror ( L_60 ) ;
F_32 ( 1 ) ;
}
fprintf ( V_53 , L_61 ) ;
F_28 ( V_53 ) ;
F_29 ( V_53 ) ;
fclose ( V_53 ) ;
}
static int F_33 ( void )
{
struct V_82 V_83 ;
if ( F_34 ( V_84 , & V_83 ) == 0 )
return F_35 ( ( int ) V_83 . V_85 / 2 , 512 ) ;
return 512 ;
}
static int F_36 ( const char * V_74 , const struct V_86 * V_87 ,
int V_88 , struct V_89 * V_90 )
{
char * V_45 , * V_38 = ( char * ) V_74 + V_90 -> V_91 ;
int V_92 = V_88 == V_93 ;
int V_94 = V_88 == V_95 ;
int V_1 = V_90 -> V_1 ;
int V_56 = 0 ;
F_37 ( L_62 ,
V_94 ? L_63 : V_92 ? L_64 : L_65 ,
V_1 , V_87 -> V_96 , V_38 , V_74 ) ;
if ( V_1 == 0 )
return 0 ;
if ( V_1 == 1 && V_92 ) {
if ( V_46 )
F_19 ( V_97 ) ;
V_45 = F_26 ( V_38 ) ;
if ( ! V_45 ) {
F_14 ( L_66 , V_31 ,
V_38 ) ;
return - 1 ;
}
F_17 ( V_97 , V_45 ) ;
return 0 ;
}
if ( V_1 == 1 && V_94 ) {
if ( ! strncmp ( V_38 , L_67 , 11 ) ) {
if ( V_98 ) {
F_14 ( L_68 ,
V_31 , V_98 , V_74 ) ;
} else {
V_98 = F_16 ( V_74 ) ;
}
return 0 ;
}
F_14 ( L_69 , V_31 , V_74 ) ;
return 0 ;
}
if ( V_94 ) {
char * V_99 = V_38 + strlen ( V_38 ) - 5 ;
if ( strncmp ( V_99 , L_70 , 5 ) ) {
F_14 ( L_71 , V_31 ,
V_74 ) ;
return 0 ;
}
}
if ( V_1 > 1 && F_15 ( V_1 , V_38 ) )
return - V_43 ;
if ( V_94 ) {
struct V_51 V_47 = {
. V_39 = F_12 () ,
. V_53 = V_97 ,
} ;
V_56 = F_21 ( V_74 , F_18 , & V_47 ) ;
free ( V_47 . V_39 ) ;
}
return V_56 ;
}
int main ( int V_100 , char * V_101 [] )
{
int V_102 ;
int V_103 ;
char V_104 [ V_105 ] ;
const char * V_106 ;
const char * V_81 ;
const char * V_107 ;
V_31 = F_27 ( V_101 [ 0 ] ) ;
if ( V_100 < 4 ) {
F_11 ( L_72 , V_31 ) ;
return 1 ;
}
V_106 = V_101 [ 1 ] ;
V_107 = V_101 [ 2 ] ;
V_81 = V_101 [ 3 ] ;
if ( V_100 > 4 )
V_108 = atoi ( V_101 [ 4 ] ) ;
V_97 = fopen ( V_81 , L_59 ) ;
if ( ! V_97 ) {
F_11 ( L_73 ,
V_31 , V_81 , strerror ( V_42 ) ) ;
return 2 ;
}
fprintf ( V_97 , L_61 ) ;
sprintf ( V_104 , L_74 , V_107 , V_106 ) ;
V_103 = F_33 () ;
V_98 = NULL ;
V_102 = F_38 ( V_104 , F_36 , V_103 , 0 ) ;
if ( V_102 && V_108 ) {
F_14 ( L_75 , V_31 , V_104 ) ;
goto V_109;
} else if ( V_102 ) {
goto V_109;
}
if ( V_46 )
F_19 ( V_97 ) ;
if ( ! V_98 ) {
F_14 ( L_76 , V_31 ) ;
goto V_109;
}
if ( F_30 ( V_97 , V_98 ) ) {
F_14 ( L_77 , V_31 , V_98 ) ;
goto V_109;
}
return 0 ;
V_109:
fclose ( V_97 ) ;
F_31 ( V_81 ) ;
return 0 ;
}
