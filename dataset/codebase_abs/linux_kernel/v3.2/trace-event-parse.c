static void F_1 ( char * V_1 , unsigned long long V_2 )
{
V_3 = V_1 ;
V_4 = V_2 ;
V_5 = 0 ;
}
static int F_2 ( const void * V_6 , const void * V_7 )
{
const struct V_8 * V_9 = V_6 ;
const struct V_8 * V_10 = V_7 ;
if ( V_9 -> V_11 < V_10 -> V_11 )
return - 1 ;
if ( V_9 -> V_11 > V_10 -> V_11 )
return 1 ;
return 0 ;
}
void F_3 ( char * V_12 , int V_2 V_13 )
{
struct V_14 {
struct V_14 * V_15 ;
char * V_16 ;
int V_11 ;
} * V_17 = NULL , * V_18 ;
char * line ;
char * V_15 = NULL ;
int V_19 ;
line = strtok_r ( V_12 , L_1 , & V_15 ) ;
while ( line ) {
V_18 = F_4 ( sizeof( * V_18 ) ) ;
sscanf ( line , L_2 , & V_18 -> V_11 ,
( float * ) ( void * ) & V_18 -> V_16 ) ;
V_18 -> V_15 = V_17 ;
V_17 = V_18 ;
line = strtok_r ( NULL , L_1 , & V_15 ) ;
V_20 ++ ;
}
V_21 = F_4 ( sizeof( * V_21 ) * V_20 ) ;
V_19 = 0 ;
while ( V_17 ) {
V_21 [ V_19 ] . V_11 = V_17 -> V_11 ;
V_21 [ V_19 ] . V_16 = V_17 -> V_16 ;
V_19 ++ ;
V_18 = V_17 ;
V_17 = V_17 -> V_15 ;
free ( V_18 ) ;
}
qsort ( V_21 , V_20 , sizeof( * V_21 ) , F_2 ) ;
}
static int F_5 ( const void * V_6 , const void * V_7 )
{
const struct V_22 * V_23 = V_6 ;
const struct V_22 * V_24 = V_7 ;
if ( V_23 -> V_25 < V_24 -> V_25 )
return - 1 ;
if ( V_23 -> V_25 > V_24 -> V_25 )
return 1 ;
return 0 ;
}
void F_6 ( char * V_12 , unsigned int V_2 V_13 )
{
struct V_26 {
struct V_26 * V_15 ;
unsigned long long V_25 ;
char * V_27 ;
char * V_28 ;
} * V_17 = NULL , * V_18 ;
char * line ;
char * V_15 = NULL ;
char * V_29 ;
char V_30 ;
int T_1 V_31 ;
int V_19 ;
line = strtok_r ( V_12 , L_1 , & V_15 ) ;
while ( line ) {
V_18 = F_4 ( sizeof( * V_18 ) ) ;
V_18 -> V_28 = NULL ;
T_1 = sscanf ( line , L_3 ,
( float * ) ( void * ) & V_29 ,
& V_30 ,
( float * ) ( void * ) & V_18 -> V_27 ,
( float * ) ( void * ) & V_18 -> V_28 ) ;
V_18 -> V_25 = F_7 ( V_29 , NULL , 16 ) ;
free ( V_29 ) ;
if ( V_18 -> V_28 )
V_18 -> V_28 [ strlen ( V_18 -> V_28 ) - 1 ] = 0 ;
V_18 -> V_15 = V_17 ;
V_17 = V_18 ;
line = strtok_r ( NULL , L_1 , & V_15 ) ;
V_32 ++ ;
}
V_26 = F_4 ( sizeof( * V_26 ) * ( V_32 + 1 ) ) ;
V_19 = 0 ;
while ( V_17 ) {
V_26 [ V_19 ] . V_27 = V_17 -> V_27 ;
V_26 [ V_19 ] . V_25 = V_17 -> V_25 ;
V_26 [ V_19 ] . V_28 = V_17 -> V_28 ;
V_19 ++ ;
V_18 = V_17 ;
V_17 = V_17 -> V_15 ;
free ( V_18 ) ;
}
qsort ( V_26 , V_32 , sizeof( * V_26 ) , F_5 ) ;
V_26 [ V_32 ] . V_27 = NULL ;
V_26 [ V_32 ] . V_25 = 0 ;
V_26 [ V_32 ] . V_28 = NULL ;
}
static int F_8 ( const void * V_6 , const void * V_7 )
{
const struct V_22 * V_23 = V_6 ;
const struct V_22 * V_24 = V_7 ;
if ( ( V_23 -> V_25 == V_24 -> V_25 ) ||
( V_23 -> V_25 > V_24 -> V_25 &&
V_23 -> V_25 < ( V_24 + 1 ) -> V_25 ) )
return 0 ;
if ( V_23 -> V_25 < V_24 -> V_25 )
return - 1 ;
return 1 ;
}
static struct V_22 * F_9 ( unsigned long long V_25 )
{
struct V_22 * V_27 ;
struct V_22 V_33 ;
V_33 . V_25 = V_25 ;
V_27 = bsearch ( & V_33 , V_26 , V_32 , sizeof( * V_26 ) ,
F_8 ) ;
return V_27 ;
}
void F_10 ( void )
{
int V_19 ;
for ( V_19 = 0 ; V_19 < ( int ) V_32 ; V_19 ++ ) {
printf ( L_4 ,
V_26 [ V_19 ] . V_25 ,
V_26 [ V_19 ] . V_27 ) ;
if ( V_26 [ V_19 ] . V_28 )
printf ( L_5 , V_26 [ V_19 ] . V_28 ) ;
else
printf ( L_1 ) ;
}
}
static int F_11 ( const void * V_6 , const void * V_7 )
{
const struct V_22 * V_23 = V_6 ;
const struct V_22 * V_24 = V_7 ;
if ( V_23 -> V_25 < V_24 -> V_25 )
return - 1 ;
if ( V_23 -> V_25 > V_24 -> V_25 )
return 1 ;
return 0 ;
}
static struct V_34 * F_12 ( unsigned long long V_25 )
{
struct V_34 * V_35 ;
struct V_34 V_33 ;
V_33 . V_25 = V_25 ;
V_35 = bsearch ( & V_33 , V_36 , V_37 , sizeof( * V_36 ) ,
F_11 ) ;
return V_35 ;
}
void F_13 ( char * V_12 , unsigned int V_2 V_13 )
{
struct V_36 {
struct V_36 * V_15 ;
unsigned long long V_25 ;
char * V_35 ;
} * V_17 = NULL , * V_18 ;
char * line ;
char * V_15 = NULL ;
char * V_29 ;
int V_19 ;
line = strtok_r ( V_12 , L_1 , & V_15 ) ;
while ( line ) {
V_29 = F_14 ( & line , L_6 ) ;
if ( ! line ) {
F_15 ( L_7 ) ;
break;
}
V_18 = F_4 ( sizeof( * V_18 ) ) ;
V_18 -> V_25 = F_7 ( V_29 , NULL , 16 ) ;
V_18 -> V_35 = F_16 ( line + 1 ) ;
V_18 -> V_15 = V_17 ;
V_17 = V_18 ;
line = strtok_r ( NULL , L_1 , & V_15 ) ;
V_37 ++ ;
}
V_36 = F_4 ( sizeof( * V_36 ) * V_37 + 1 ) ;
V_19 = 0 ;
while ( V_17 ) {
V_36 [ V_19 ] . V_35 = V_17 -> V_35 ;
V_36 [ V_19 ] . V_25 = V_17 -> V_25 ;
V_19 ++ ;
V_18 = V_17 ;
V_17 = V_17 -> V_15 ;
free ( V_18 ) ;
}
qsort ( V_36 , V_37 , sizeof( * V_36 ) , F_11 ) ;
}
void F_17 ( void )
{
int V_19 ;
for ( V_19 = 0 ; V_19 < ( int ) V_37 ; V_19 ++ ) {
printf ( L_8 ,
V_36 [ V_19 ] . V_25 ,
V_36 [ V_19 ] . V_35 ) ;
}
}
static struct V_38 * F_18 ( void )
{
struct V_38 * V_38 ;
V_38 = F_4 ( sizeof( * V_38 ) ) ;
memset ( V_38 , 0 , sizeof( * V_38 ) ) ;
return V_38 ;
}
static void F_19 ( struct V_38 * V_38 )
{
V_38 -> V_15 = V_39 ;
V_39 = V_38 ;
}
static int F_20 ( enum V_40 type )
{
switch ( type ) {
case V_41 ... V_42 :
return 1 ;
case V_43 ... V_44 :
default:
return 0 ;
}
}
static void F_21 ( struct V_45 * V_46 )
{
if ( ! V_46 )
return;
switch ( V_46 -> type ) {
case V_47 :
if ( V_46 -> V_48 . V_48 )
free ( V_46 -> V_48 . V_48 ) ;
break;
case V_49 :
case V_50 ... V_51 :
default:
break;
}
free ( V_46 ) ;
}
static enum V_40 F_22 ( int V_30 )
{
if ( V_30 == '\n' )
return V_52 ;
if ( isspace ( V_30 ) )
return V_53 ;
if ( isalnum ( V_30 ) || V_30 == '_' )
return V_41 ;
if ( V_30 == '\'' )
return V_42 ;
if ( V_30 == '"' )
return V_54 ;
if ( ! isprint ( V_30 ) )
return V_55 ;
if ( V_30 == '(' || V_30 == ')' || V_30 == ',' )
return V_44 ;
return V_56 ;
}
static int F_23 ( void )
{
if ( V_5 >= V_4 )
return - 1 ;
return V_3 [ V_5 ++ ] ;
}
static int F_24 ( void )
{
if ( V_5 >= V_4 )
return - 1 ;
return V_3 [ V_5 ] ;
}
static enum V_40 F_25 ( char * * V_57 )
{
char V_1 [ V_58 ] ;
int V_30 , V_59 , V_60 , V_61 ;
int V_19 = 0 ;
int V_62 = 0 ;
enum V_40 type ;
* V_57 = NULL ;
V_30 = F_23 () ;
if ( V_30 < 0 )
return V_55 ;
type = F_22 ( V_30 ) ;
if ( type == V_55 )
return type ;
V_1 [ V_19 ++ ] = V_30 ;
switch ( type ) {
case V_52 :
case V_44 :
* V_57 = F_4 ( 2 ) ;
( * V_57 ) [ 0 ] = V_30 ;
( * V_57 ) [ 1 ] = 0 ;
return type ;
case V_56 :
switch ( V_30 ) {
case '-' :
V_61 = F_24 () ;
if ( V_61 == '>' ) {
V_1 [ V_19 ++ ] = F_23 () ;
break;
}
case '+' :
case '|' :
case '&' :
case '>' :
case '<' :
V_59 = V_30 ;
V_30 = F_24 () ;
if ( V_30 != V_59 )
goto V_63;
V_1 [ V_19 ++ ] = F_23 () ;
switch ( V_59 ) {
case '>' :
case '<' :
goto V_63;
default:
break;
}
break;
case '!' :
case '=' :
goto V_63;
default:
break;
}
V_1 [ V_19 ] = 0 ;
* V_57 = F_16 ( V_1 ) ;
return type ;
V_63:
V_30 = F_24 () ;
if ( V_30 == '=' )
V_1 [ V_19 ++ ] = F_23 () ;
break;
case V_54 :
case V_42 :
V_19 -- ;
V_60 = V_30 ;
V_59 = 0 ;
do {
if ( V_19 == ( V_58 - 1 ) ) {
V_1 [ V_19 ] = 0 ;
if ( * V_57 ) {
* V_57 = realloc ( * V_57 , V_62 + V_58 ) ;
if ( ! * V_57 )
return V_55 ;
strcat ( * V_57 , V_1 ) ;
} else
* V_57 = F_16 ( V_1 ) ;
if ( ! * V_57 )
return V_55 ;
V_62 += V_58 ;
V_19 = 0 ;
}
V_59 = V_30 ;
V_30 = F_23 () ;
V_1 [ V_19 ++ ] = V_30 ;
if ( V_30 == '\\' && V_59 == '\\' )
V_59 = 0 ;
} while ( V_30 != V_60 || V_59 == '\\' );
V_19 -- ;
goto V_64;
case V_43 ... V_53 :
case V_41 :
default:
break;
}
while ( F_22 ( F_24 () ) == type ) {
if ( V_19 == ( V_58 - 1 ) ) {
V_1 [ V_19 ] = 0 ;
if ( * V_57 ) {
* V_57 = realloc ( * V_57 , V_62 + V_58 ) ;
if ( ! * V_57 )
return V_55 ;
strcat ( * V_57 , V_1 ) ;
} else
* V_57 = F_16 ( V_1 ) ;
if ( ! * V_57 )
return V_55 ;
V_62 += V_58 ;
V_19 = 0 ;
}
V_30 = F_23 () ;
V_1 [ V_19 ++ ] = V_30 ;
}
V_64:
V_1 [ V_19 ] = 0 ;
if ( * V_57 ) {
* V_57 = realloc ( * V_57 , V_62 + V_19 ) ;
if ( ! * V_57 )
return V_55 ;
strcat ( * V_57 , V_1 ) ;
} else
* V_57 = F_16 ( V_1 ) ;
if ( ! * V_57 )
return V_55 ;
return type ;
}
static void F_26 ( char * V_57 )
{
if ( V_57 )
free ( V_57 ) ;
}
static enum V_40 F_27 ( char * * V_57 )
{
enum V_40 type ;
for (; ; ) {
type = F_25 ( V_57 ) ;
if ( type != V_53 )
return type ;
F_26 ( * V_57 ) ;
}
return V_55 ;
}
static enum V_40 F_28 ( char * * V_57 )
{
enum V_40 type ;
for (; ; ) {
type = F_25 ( V_57 ) ;
if ( type != V_53 && type != V_52 )
return type ;
F_26 ( * V_57 ) ;
}
return V_55 ;
}
static int F_29 ( enum V_40 type , enum V_40 V_65 )
{
if ( type != V_65 ) {
F_15 ( L_9 ,
V_65 , type ) ;
return - 1 ;
}
return 0 ;
}
static int F_30 ( enum V_40 type , char * V_66 ,
enum V_40 V_65 , const char * V_67 ,
bool V_68 )
{
if ( type != V_65 ) {
if ( V_68 )
F_15 ( L_9 ,
V_65 , type ) ;
return - 1 ;
}
if ( strcmp ( V_66 , V_67 ) != 0 ) {
if ( V_68 )
F_15 ( L_10 ,
V_67 , V_66 ) ;
return - 1 ;
}
return 0 ;
}
static int F_31 ( enum V_40 type , char * V_66 ,
enum V_40 V_65 , const char * V_67 )
{
return F_30 ( type , V_66 , V_65 , V_67 , true ) ;
}
static int F_32 ( enum V_40 V_65 , char * * V_57 , int V_69 )
{
enum V_40 type ;
if ( V_69 )
type = F_27 ( V_57 ) ;
else
type = F_28 ( V_57 ) ;
return F_29 ( type , V_65 ) ;
}
static int F_33 ( enum V_40 V_65 , char * * V_57 )
{
return F_32 ( V_65 , V_57 , 1 ) ;
}
static int F_34 ( enum V_40 V_65 , const char * V_70 ,
int V_69 , bool V_68 )
{
enum V_40 type ;
char * V_66 ;
int T_1 ;
if ( V_69 )
type = F_27 ( & V_66 ) ;
else
type = F_28 ( & V_66 ) ;
T_1 = F_30 ( type , V_66 , V_65 , V_70 , V_68 ) ;
F_26 ( V_66 ) ;
return T_1 ;
}
static int F_35 ( enum V_40 V_65 , const char * V_70 )
{
return F_34 ( V_65 , V_70 , 1 , true ) ;
}
static int F_36 ( enum V_40 V_65 , const char * V_70 )
{
return F_34 ( V_65 , V_70 , 0 , true ) ;
}
static char * F_37 ( void )
{
char * V_66 ;
if ( F_35 ( V_41 , L_11 ) < 0 )
return NULL ;
if ( F_35 ( V_56 , L_6 ) < 0 )
return NULL ;
if ( F_33 ( V_41 , & V_66 ) < 0 )
goto V_71;
return V_66 ;
V_71:
F_26 ( V_66 ) ;
return NULL ;
}
static int F_38 ( void )
{
char * V_66 ;
int V_72 ;
if ( F_36 ( V_41 , L_12 ) < 0 )
return - 1 ;
if ( F_35 ( V_56 , L_6 ) < 0 )
return - 1 ;
if ( F_33 ( V_41 , & V_66 ) < 0 )
goto V_71;
V_72 = strtoul ( V_66 , NULL , 0 ) ;
F_26 ( V_66 ) ;
return V_72 ;
V_71:
F_26 ( V_66 ) ;
return - 1 ;
}
static int F_39 ( struct V_73 * V_74 )
{
if ( ( V_74 -> V_75 & V_76 ) &&
( ! strstr ( V_74 -> type , L_13 ) || ! strstr ( V_74 -> type , L_14 ) ||
! strstr ( V_74 -> type , L_15 ) ) )
return 1 ;
return 0 ;
}
static int F_40 ( struct V_73 * V_74 )
{
if ( ! strncmp ( V_74 -> type , L_16 , 10 ) )
return 1 ;
return 0 ;
}
static int F_41 ( struct V_38 * V_38 , struct V_73 * * V_77 )
{
struct V_73 * V_74 = NULL ;
enum V_40 type ;
char * V_66 ;
char * V_78 ;
int V_79 = 0 ;
do {
type = F_27 ( & V_66 ) ;
if ( type == V_52 ) {
F_26 ( V_66 ) ;
return V_79 ;
}
V_79 ++ ;
if ( F_31 ( type , V_66 , V_41 , L_17 ) )
goto V_71;
F_26 ( V_66 ) ;
type = F_27 ( & V_66 ) ;
if ( V_38 -> V_75 & V_80 &&
type == V_41 && strcmp ( V_66 , L_18 ) == 0 ) {
F_26 ( V_66 ) ;
type = F_27 ( & V_66 ) ;
}
if ( F_31 ( type , V_66 , V_56 , L_6 ) < 0 )
return - 1 ;
if ( F_33 ( V_41 , & V_66 ) < 0 )
goto V_71;
V_78 = V_66 ;
V_74 = F_4 ( sizeof( * V_74 ) ) ;
memset ( V_74 , 0 , sizeof( * V_74 ) ) ;
for (; ; ) {
type = F_27 ( & V_66 ) ;
if ( type == V_41 ||
( type == V_56 && strcmp ( V_66 , L_19 ) == 0 ) ||
( V_38 -> V_75 & V_80 &&
type == V_56 && strcmp ( V_66 , L_20 ) == 0 ) ) {
if ( strcmp ( V_66 , L_19 ) == 0 )
V_74 -> V_75 |= V_81 ;
if ( V_74 -> type ) {
V_74 -> type = realloc ( V_74 -> type ,
strlen ( V_74 -> type ) +
strlen ( V_78 ) + 2 ) ;
strcat ( V_74 -> type , L_21 ) ;
strcat ( V_74 -> type , V_78 ) ;
} else
V_74 -> type = V_78 ;
V_78 = V_66 ;
continue;
}
break;
}
if ( ! V_74 -> type ) {
F_42 ( L_22 ) ;
goto V_71;
}
V_74 -> V_82 = V_78 ;
if ( F_29 ( type , V_56 ) )
goto V_71;
if ( strcmp ( V_66 , L_23 ) == 0 ) {
enum V_40 V_83 = type ;
char * V_84 = V_66 ;
int V_85 ;
V_74 -> V_75 |= V_76 ;
type = F_27 ( & V_66 ) ;
while ( strcmp ( V_66 , L_24 ) != 0 ) {
if ( V_83 == V_41 &&
type == V_41 )
V_85 = 2 ;
else
V_85 = 1 ;
V_83 = type ;
V_84 = realloc ( V_84 ,
strlen ( V_84 ) +
strlen ( V_66 ) + V_85 ) ;
if ( V_85 == 2 )
strcat ( V_84 , L_21 ) ;
strcat ( V_84 , V_66 ) ;
F_26 ( V_66 ) ;
type = F_27 ( & V_66 ) ;
if ( type == V_55 ) {
F_42 ( L_25 ) ;
goto V_71;
}
}
F_26 ( V_66 ) ;
V_84 = realloc ( V_84 , strlen ( V_84 ) + 2 ) ;
strcat ( V_84 , L_24 ) ;
type = F_27 ( & V_66 ) ;
if ( type == V_41 ) {
V_74 -> type = realloc ( V_74 -> type ,
strlen ( V_74 -> type ) +
strlen ( V_74 -> V_82 ) +
strlen ( V_84 ) + 2 ) ;
strcat ( V_74 -> type , L_21 ) ;
strcat ( V_74 -> type , V_74 -> V_82 ) ;
F_26 ( V_74 -> V_82 ) ;
strcat ( V_74 -> type , V_84 ) ;
V_74 -> V_82 = V_66 ;
type = F_27 ( & V_66 ) ;
} else {
V_74 -> type = realloc ( V_74 -> type ,
strlen ( V_74 -> type ) +
strlen ( V_84 ) + 1 ) ;
strcat ( V_74 -> type , V_84 ) ;
}
free ( V_84 ) ;
}
if ( F_39 ( V_74 ) ) {
V_74 -> V_75 |= V_86 ;
if ( F_40 ( V_74 ) )
V_74 -> V_75 |= V_87 ;
}
if ( F_31 ( type , V_66 , V_56 , L_26 ) )
goto V_71;
F_26 ( V_66 ) ;
if ( F_35 ( V_41 , L_27 ) < 0 )
goto V_88;
if ( F_35 ( V_56 , L_6 ) < 0 )
goto V_88;
if ( F_33 ( V_41 , & V_66 ) )
goto V_71;
V_74 -> V_89 = strtoul ( V_66 , NULL , 0 ) ;
F_26 ( V_66 ) ;
if ( F_35 ( V_56 , L_26 ) < 0 )
goto V_88;
if ( F_35 ( V_41 , L_28 ) < 0 )
goto V_88;
if ( F_35 ( V_56 , L_6 ) < 0 )
goto V_88;
if ( F_33 ( V_41 , & V_66 ) )
goto V_71;
V_74 -> V_2 = strtoul ( V_66 , NULL , 0 ) ;
F_26 ( V_66 ) ;
if ( F_35 ( V_56 , L_26 ) < 0 )
goto V_88;
type = F_27 ( & V_66 ) ;
if ( type != V_52 ) {
if ( F_31 ( type , V_66 , V_41 , L_29 ) )
goto V_71;
F_26 ( V_66 ) ;
if ( F_35 ( V_56 , L_6 ) < 0 )
goto V_88;
if ( F_33 ( V_41 , & V_66 ) )
goto V_71;
if ( strtoul ( V_66 , NULL , 0 ) )
V_74 -> V_75 |= V_90 ;
F_26 ( V_66 ) ;
if ( F_35 ( V_56 , L_26 ) < 0 )
goto V_88;
if ( F_33 ( V_52 , & V_66 ) )
goto V_71;
}
F_26 ( V_66 ) ;
* V_77 = V_74 ;
V_77 = & V_74 -> V_15 ;
} while ( 1 );
return 0 ;
V_71:
F_26 ( V_66 ) ;
V_88:
if ( V_74 )
free ( V_74 ) ;
return - 1 ;
}
static int F_43 ( struct V_38 * V_38 )
{
char * V_66 ;
int T_1 ;
if ( F_36 ( V_41 , L_30 ) < 0 )
return - 1 ;
if ( F_35 ( V_56 , L_6 ) < 0 )
return - 1 ;
if ( F_33 ( V_52 , & V_66 ) )
goto V_71;
F_26 ( V_66 ) ;
T_1 = F_41 ( V_38 , & V_38 -> V_91 . V_92 ) ;
if ( T_1 < 0 )
return T_1 ;
V_38 -> V_91 . V_93 = T_1 ;
T_1 = F_41 ( V_38 , & V_38 -> V_91 . V_77 ) ;
if ( T_1 < 0 )
return T_1 ;
V_38 -> V_91 . V_94 = T_1 ;
return 0 ;
V_71:
F_26 ( V_66 ) ;
return - 1 ;
}
static enum V_40
F_44 ( struct V_38 * V_38 , struct V_45 * V_46 , char * * V_57 )
{
enum V_40 type ;
char * V_66 ;
type = F_27 ( & V_66 ) ;
* V_57 = V_66 ;
return F_45 ( V_38 , V_46 , V_57 , type ) ;
}
static enum V_40
F_46 ( struct V_38 * V_38 , struct V_45 * V_95 , char * * V_57 )
{
struct V_45 * V_46 , * V_96 , * V_97 ;
enum V_40 type ;
char * V_66 = NULL ;
V_46 = F_4 ( sizeof( * V_46 ) ) ;
memset ( V_46 , 0 , sizeof( * V_46 ) ) ;
V_96 = F_4 ( sizeof( * V_96 ) ) ;
V_97 = F_4 ( sizeof( * V_97 ) ) ;
V_46 -> type = V_51 ;
V_46 -> V_98 . V_96 = V_96 ;
V_46 -> V_98 . V_97 = V_97 ;
* V_57 = NULL ;
type = F_44 ( V_38 , V_96 , & V_66 ) ;
if ( F_31 ( type , V_66 , V_56 , L_6 ) )
goto V_99;
V_46 -> V_98 . V_98 = V_66 ;
type = F_44 ( V_38 , V_97 , & V_66 ) ;
V_95 -> V_98 . V_97 = V_46 ;
* V_57 = V_66 ;
return type ;
V_99:
F_26 ( * V_57 ) ;
free ( V_97 ) ;
free ( V_96 ) ;
F_21 ( V_46 ) ;
return V_43 ;
}
static enum V_40
F_47 ( struct V_38 * V_38 , struct V_45 * V_95 , char * * V_57 )
{
struct V_45 * V_46 ;
enum V_40 type ;
char * V_66 = NULL ;
V_46 = F_4 ( sizeof( * V_46 ) ) ;
memset ( V_46 , 0 , sizeof( * V_46 ) ) ;
* V_57 = NULL ;
type = F_44 ( V_38 , V_46 , & V_66 ) ;
if ( F_31 ( type , V_66 , V_56 , L_24 ) )
goto V_99;
V_95 -> V_98 . V_97 = V_46 ;
F_26 ( V_66 ) ;
type = F_28 ( & V_66 ) ;
* V_57 = V_66 ;
return type ;
V_99:
F_26 ( * V_57 ) ;
F_21 ( V_46 ) ;
return V_43 ;
}
static int F_48 ( char * V_98 )
{
if ( ! V_98 [ 1 ] ) {
switch ( V_98 [ 0 ] ) {
case '*' :
case '/' :
case '%' :
return 6 ;
case '+' :
case '-' :
return 7 ;
case '<' :
case '>' :
return 9 ;
case '&' :
return 11 ;
case '^' :
return 12 ;
case '|' :
return 13 ;
case '?' :
return 16 ;
default:
F_42 ( L_31 , V_98 [ 0 ] ) ;
return - 1 ;
}
} else {
if ( strcmp ( V_98 , L_32 ) == 0 ||
strcmp ( V_98 , L_33 ) == 0 ) {
return 3 ;
} else if ( strcmp ( V_98 , L_34 ) == 0 ||
strcmp ( V_98 , L_35 ) == 0 ) {
return 8 ;
} else if ( strcmp ( V_98 , L_36 ) == 0 ||
strcmp ( V_98 , L_37 ) == 0 ) {
return 9 ;
} else if ( strcmp ( V_98 , L_38 ) == 0 ||
strcmp ( V_98 , L_39 ) == 0 ) {
return 10 ;
} else if ( strcmp ( V_98 , L_40 ) == 0 ) {
return 14 ;
} else if ( strcmp ( V_98 , L_41 ) == 0 ) {
return 15 ;
} else {
F_42 ( L_42 , V_98 ) ;
return - 1 ;
}
}
}
static void F_49 ( struct V_45 * V_46 )
{
if ( ! V_46 -> V_98 . V_96 || V_46 -> V_98 . V_96 -> type == V_49 ) {
V_46 -> V_98 . V_100 = 0 ;
return;
}
V_46 -> V_98 . V_100 = F_48 ( V_46 -> V_98 . V_98 ) ;
}
static enum V_40
F_50 ( struct V_38 * V_38 , struct V_45 * V_46 , char * * V_57 )
{
struct V_45 * V_96 , * V_97 = NULL ;
enum V_40 type ;
char * V_66 ;
V_66 = * V_57 ;
if ( V_46 -> type == V_51 && ! V_46 -> V_98 . V_96 ) {
if ( V_66 [ 1 ] ) {
F_42 ( L_43 , V_66 ) ;
return V_43 ;
}
switch ( V_66 [ 0 ] ) {
case '!' :
case '+' :
case '-' :
break;
default:
F_42 ( L_43 , V_66 ) ;
return V_43 ;
}
V_96 = F_4 ( sizeof( * V_96 ) ) ;
V_96 -> type = V_49 ;
V_46 -> V_98 . V_96 = V_96 ;
V_97 = F_4 ( sizeof( * V_97 ) ) ;
V_46 -> V_98 . V_97 = V_97 ;
type = F_44 ( V_38 , V_97 , V_57 ) ;
} else if ( strcmp ( V_66 , L_44 ) == 0 ) {
V_96 = F_4 ( sizeof( * V_96 ) ) ;
* V_96 = * V_46 ;
V_46 -> type = V_51 ;
V_46 -> V_98 . V_98 = V_66 ;
V_46 -> V_98 . V_96 = V_96 ;
V_46 -> V_98 . V_100 = 0 ;
type = F_46 ( V_38 , V_46 , V_57 ) ;
} else if ( strcmp ( V_66 , L_34 ) == 0 ||
strcmp ( V_66 , L_35 ) == 0 ||
strcmp ( V_66 , L_45 ) == 0 ||
strcmp ( V_66 , L_46 ) == 0 ||
strcmp ( V_66 , L_40 ) == 0 ||
strcmp ( V_66 , L_41 ) == 0 ||
strcmp ( V_66 , L_47 ) == 0 ||
strcmp ( V_66 , L_48 ) == 0 ||
strcmp ( V_66 , L_19 ) == 0 ||
strcmp ( V_66 , L_49 ) == 0 ||
strcmp ( V_66 , L_50 ) == 0 ||
strcmp ( V_66 , L_51 ) == 0 ||
strcmp ( V_66 , L_52 ) == 0 ||
strcmp ( V_66 , L_38 ) == 0 ||
strcmp ( V_66 , L_39 ) == 0 ) {
V_96 = F_4 ( sizeof( * V_96 ) ) ;
* V_96 = * V_46 ;
V_46 -> type = V_51 ;
V_46 -> V_98 . V_98 = V_66 ;
V_46 -> V_98 . V_96 = V_96 ;
F_49 ( V_46 ) ;
V_97 = F_4 ( sizeof( * V_97 ) ) ;
type = F_28 ( & V_66 ) ;
* V_57 = V_66 ;
if ( ( strcmp ( V_46 -> V_98 . V_98 , L_19 ) == 0 ) &&
type == V_44 && ( strcmp ( V_66 , L_53 ) == 0 ) ) {
if ( V_96 -> type != V_47 )
F_42 ( L_54 ) ;
V_96 -> V_48 . V_48 = realloc ( V_96 -> V_48 . V_48 ,
sizeof( V_96 -> V_48 . V_48 ) + 3 ) ;
strcat ( V_96 -> V_48 . V_48 , L_55 ) ;
* V_46 = * V_96 ;
free ( V_46 ) ;
return type ;
}
type = F_45 ( V_38 , V_97 , V_57 , type ) ;
V_46 -> V_98 . V_97 = V_97 ;
} else if ( strcmp ( V_66 , L_23 ) == 0 ) {
V_96 = F_4 ( sizeof( * V_96 ) ) ;
* V_96 = * V_46 ;
V_46 -> type = V_51 ;
V_46 -> V_98 . V_98 = V_66 ;
V_46 -> V_98 . V_96 = V_96 ;
V_46 -> V_98 . V_100 = 0 ;
type = F_47 ( V_38 , V_46 , V_57 ) ;
} else {
F_15 ( L_42 , V_66 ) ;
V_38 -> V_75 |= V_101 ;
return V_55 ;
}
if ( type == V_56 ) {
int V_100 ;
V_100 = F_48 ( * V_57 ) ;
if ( V_100 > V_46 -> V_98 . V_100 )
return F_50 ( V_38 , V_46 , V_57 ) ;
return F_50 ( V_38 , V_97 , V_57 ) ;
}
return type ;
}
static enum V_40
F_51 ( struct V_38 * V_38 V_13 , struct V_45 * V_46 ,
char * * V_57 )
{
enum V_40 type ;
char * V_74 ;
char * V_66 ;
if ( F_35 ( V_56 , L_56 ) < 0 )
return V_43 ;
if ( F_33 ( V_41 , & V_66 ) < 0 )
goto V_71;
V_74 = V_66 ;
V_46 -> type = V_50 ;
V_46 -> V_74 . V_82 = V_74 ;
if ( V_102 ) {
V_46 -> V_74 . V_74 = F_52 ( V_38 , V_46 -> V_74 . V_82 ) ;
V_46 -> V_74 . V_74 -> V_75 |= V_103 ;
V_102 = 0 ;
} else if ( V_104 ) {
V_46 -> V_74 . V_74 = F_52 ( V_38 , V_46 -> V_74 . V_82 ) ;
V_46 -> V_74 . V_74 -> V_75 |= V_105 ;
V_104 = 0 ;
}
type = F_27 ( & V_66 ) ;
* V_57 = V_66 ;
return type ;
V_71:
F_26 ( V_66 ) ;
return V_43 ;
}
static long long F_53 ( struct V_45 * V_46 )
{
long long V_96 , V_97 ;
long long V_106 = 0 ;
switch ( V_46 -> type ) {
case V_47 :
V_106 = strtoll ( V_46 -> V_48 . V_48 , NULL , 0 ) ;
break;
case V_107 :
V_106 = F_53 ( V_46 -> V_108 . V_18 ) ;
break;
case V_51 :
switch ( V_46 -> V_98 . V_98 [ 0 ] ) {
case '|' :
V_96 = F_53 ( V_46 -> V_98 . V_96 ) ;
V_97 = F_53 ( V_46 -> V_98 . V_97 ) ;
if ( V_46 -> V_98 . V_98 [ 1 ] )
V_106 = V_96 || V_97 ;
else
V_106 = V_96 | V_97 ;
break;
case '&' :
V_96 = F_53 ( V_46 -> V_98 . V_96 ) ;
V_97 = F_53 ( V_46 -> V_98 . V_97 ) ;
if ( V_46 -> V_98 . V_98 [ 1 ] )
V_106 = V_96 && V_97 ;
else
V_106 = V_96 & V_97 ;
break;
case '<' :
V_96 = F_53 ( V_46 -> V_98 . V_96 ) ;
V_97 = F_53 ( V_46 -> V_98 . V_97 ) ;
switch ( V_46 -> V_98 . V_98 [ 1 ] ) {
case 0 :
V_106 = V_96 < V_97 ;
break;
case '<' :
V_106 = V_96 << V_97 ;
break;
case '=' :
V_106 = V_96 <= V_97 ;
break;
default:
F_42 ( L_42 , V_46 -> V_98 . V_98 ) ;
}
break;
case '>' :
V_96 = F_53 ( V_46 -> V_98 . V_96 ) ;
V_97 = F_53 ( V_46 -> V_98 . V_97 ) ;
switch ( V_46 -> V_98 . V_98 [ 1 ] ) {
case 0 :
V_106 = V_96 > V_97 ;
break;
case '>' :
V_106 = V_96 >> V_97 ;
break;
case '=' :
V_106 = V_96 >= V_97 ;
break;
default:
F_42 ( L_42 , V_46 -> V_98 . V_98 ) ;
}
break;
case '=' :
V_96 = F_53 ( V_46 -> V_98 . V_96 ) ;
V_97 = F_53 ( V_46 -> V_98 . V_97 ) ;
if ( V_46 -> V_98 . V_98 [ 1 ] != '=' )
F_42 ( L_42 , V_46 -> V_98 . V_98 ) ;
V_106 = V_96 == V_97 ;
break;
case '!' :
V_96 = F_53 ( V_46 -> V_98 . V_96 ) ;
V_97 = F_53 ( V_46 -> V_98 . V_97 ) ;
switch ( V_46 -> V_98 . V_98 [ 1 ] ) {
case '=' :
V_106 = V_96 != V_97 ;
break;
default:
F_42 ( L_42 , V_46 -> V_98 . V_98 ) ;
}
break;
default:
F_42 ( L_42 , V_46 -> V_98 . V_98 ) ;
}
break;
case V_49 :
case V_50 ... V_109 :
case V_110 :
default:
F_42 ( L_57 , V_46 -> type ) ;
}
return V_106 ;
}
static char * F_54 ( struct V_45 * V_46 )
{
long long V_106 ;
static char V_1 [ 20 ] ;
switch ( V_46 -> type ) {
case V_47 :
return V_46 -> V_48 . V_48 ;
case V_107 :
return F_54 ( V_46 -> V_108 . V_18 ) ;
case V_51 :
V_106 = F_53 ( V_46 ) ;
sprintf ( V_1 , L_58 , V_106 ) ;
return V_1 ;
case V_49 :
case V_50 ... V_109 :
case V_110 :
default:
F_42 ( L_57 , V_46 -> type ) ;
break;
}
return NULL ;
}
static enum V_40
F_55 ( struct V_38 * V_38 , struct V_111 * * V_17 , char * * V_57 )
{
enum V_40 type ;
struct V_45 * V_46 = NULL ;
struct V_111 * V_74 ;
char * V_66 = NULL ;
char * V_112 ;
do {
F_26 ( V_66 ) ;
type = F_28 ( & V_66 ) ;
if ( F_31 ( type , V_66 , V_56 , L_59 ) )
break;
V_46 = F_4 ( sizeof( * V_46 ) ) ;
F_26 ( V_66 ) ;
type = F_44 ( V_38 , V_46 , & V_66 ) ;
if ( F_31 ( type , V_66 , V_44 , L_60 ) )
goto V_99;
V_74 = F_4 ( sizeof( * V_74 ) ) ;
memset ( V_74 , 0 , sizeof( * V_74 ) ) ;
V_112 = F_54 ( V_46 ) ;
V_74 -> V_112 = F_16 ( V_112 ) ;
F_26 ( V_66 ) ;
type = F_44 ( V_38 , V_46 , & V_66 ) ;
if ( F_31 ( type , V_66 , V_56 , L_61 ) )
goto V_99;
V_112 = F_54 ( V_46 ) ;
V_74 -> V_70 = F_16 ( V_112 ) ;
F_21 ( V_46 ) ;
V_46 = NULL ;
* V_17 = V_74 ;
V_17 = & V_74 -> V_15 ;
F_26 ( V_66 ) ;
type = F_28 ( & V_66 ) ;
} while ( type == V_44 && strcmp ( V_66 , L_60 ) == 0 );
* V_57 = V_66 ;
return type ;
V_99:
F_21 ( V_46 ) ;
F_26 ( V_66 ) ;
return V_43 ;
}
static enum V_40
F_56 ( struct V_38 * V_38 , struct V_45 * V_46 , char * * V_57 )
{
struct V_45 * V_74 ;
enum V_40 type ;
char * V_66 ;
memset ( V_46 , 0 , sizeof( * V_46 ) ) ;
V_46 -> type = V_113 ;
if ( F_36 ( V_44 , L_62 ) < 0 )
return V_43 ;
V_74 = F_4 ( sizeof( * V_74 ) ) ;
type = F_44 ( V_38 , V_74 , & V_66 ) ;
while ( type == V_56 )
type = F_50 ( V_38 , V_74 , & V_66 ) ;
if ( F_31 ( type , V_66 , V_44 , L_60 ) )
goto V_99;
V_46 -> V_75 . V_74 = V_74 ;
type = F_28 ( & V_66 ) ;
if ( F_20 ( type ) ) {
V_46 -> V_75 . V_114 = V_66 ;
type = F_28 ( & V_66 ) ;
}
if ( F_31 ( type , V_66 , V_44 , L_60 ) )
goto V_99;
type = F_55 ( V_38 , & V_46 -> V_75 . V_75 , & V_66 ) ;
if ( F_31 ( type , V_66 , V_44 , L_53 ) )
goto V_99;
F_26 ( V_66 ) ;
type = F_28 ( V_57 ) ;
return type ;
V_99:
F_26 ( V_66 ) ;
return V_43 ;
}
static enum V_40
F_57 ( struct V_38 * V_38 , struct V_45 * V_46 , char * * V_57 )
{
struct V_45 * V_74 ;
enum V_40 type ;
char * V_66 ;
memset ( V_46 , 0 , sizeof( * V_46 ) ) ;
V_46 -> type = V_109 ;
if ( F_36 ( V_44 , L_62 ) < 0 )
return V_43 ;
V_74 = F_4 ( sizeof( * V_74 ) ) ;
type = F_44 ( V_38 , V_74 , & V_66 ) ;
if ( F_31 ( type , V_66 , V_44 , L_60 ) )
goto V_99;
V_46 -> V_115 . V_74 = V_74 ;
type = F_55 ( V_38 , & V_46 -> V_115 . V_116 , & V_66 ) ;
if ( F_31 ( type , V_66 , V_44 , L_53 ) )
goto V_99;
F_26 ( V_66 ) ;
type = F_28 ( V_57 ) ;
return type ;
V_99:
F_26 ( V_66 ) ;
return V_43 ;
}
static enum V_40
F_58 ( struct V_38 * V_38 , struct V_45 * V_46 , char * * V_57 )
{
struct V_45 * V_117 ;
enum V_40 type ;
char * V_66 ;
type = F_44 ( V_38 , V_46 , & V_66 ) ;
if ( type == V_43 )
return V_43 ;
if ( type == V_56 )
type = F_50 ( V_38 , V_46 , & V_66 ) ;
if ( type == V_43 )
return V_43 ;
if ( F_31 ( type , V_66 , V_44 , L_53 ) ) {
F_26 ( V_66 ) ;
return V_43 ;
}
F_26 ( V_66 ) ;
type = F_28 ( & V_66 ) ;
if ( F_20 ( type ) ||
( type == V_44 && strcmp ( V_66 , L_62 ) == 0 ) ) {
if ( V_46 -> type != V_47 )
F_42 ( L_63 ) ;
V_117 = F_4 ( sizeof( * V_117 ) ) ;
V_46 -> type = V_107 ;
V_46 -> V_108 . type = V_46 -> V_48 . V_48 ;
V_46 -> V_108 . V_18 = V_117 ;
type = F_45 ( V_38 , V_117 , & V_66 , type ) ;
}
* V_57 = V_66 ;
return type ;
}
static enum V_40
F_59 ( struct V_38 * V_38 V_13 , struct V_45 * V_46 , char * * V_57 )
{
enum V_40 type ;
char * V_66 ;
if ( F_35 ( V_44 , L_62 ) < 0 )
return V_43 ;
if ( F_33 ( V_41 , & V_66 ) < 0 )
goto V_71;
V_46 -> type = V_110 ;
V_46 -> string . string = V_66 ;
V_46 -> string . V_89 = - 1 ;
if ( F_35 ( V_44 , L_53 ) < 0 )
return V_43 ;
type = F_27 ( & V_66 ) ;
* V_57 = V_66 ;
return type ;
V_71:
F_26 ( V_66 ) ;
return V_43 ;
}
enum V_40
F_45 ( struct V_38 * V_38 , struct V_45 * V_46 ,
char * * V_57 , enum V_40 type )
{
char * V_66 ;
char * V_48 ;
V_66 = * V_57 ;
switch ( type ) {
case V_41 :
if ( strcmp ( V_66 , L_64 ) == 0 ) {
F_26 ( V_66 ) ;
type = F_51 ( V_38 , V_46 , & V_66 ) ;
} else if ( strcmp ( V_66 , L_65 ) == 0 ) {
F_26 ( V_66 ) ;
V_102 = 1 ;
type = F_56 ( V_38 , V_46 , & V_66 ) ;
} else if ( strcmp ( V_66 , L_66 ) == 0 ) {
F_26 ( V_66 ) ;
V_104 = 1 ;
type = F_57 ( V_38 , V_46 , & V_66 ) ;
} else if ( strcmp ( V_66 , L_67 ) == 0 ) {
F_26 ( V_66 ) ;
type = F_59 ( V_38 , V_46 , & V_66 ) ;
} else {
V_48 = V_66 ;
type = F_28 ( & V_66 ) ;
while ( type == V_41 ) {
V_48 = realloc ( V_48 , strlen ( V_48 ) + strlen ( V_66 ) + 2 ) ;
strcat ( V_48 , L_21 ) ;
strcat ( V_48 , V_66 ) ;
F_26 ( V_66 ) ;
type = F_28 ( & V_66 ) ;
}
V_46 -> type = V_47 ;
V_46 -> V_48 . V_48 = V_48 ;
}
break;
case V_54 :
case V_42 :
V_46 -> type = V_47 ;
V_46 -> V_48 . V_48 = V_66 ;
type = F_28 ( & V_66 ) ;
break;
case V_44 :
if ( strcmp ( V_66 , L_62 ) == 0 ) {
F_26 ( V_66 ) ;
type = F_58 ( V_38 , V_46 , & V_66 ) ;
break;
}
case V_56 :
V_46 -> type = V_51 ;
V_46 -> V_98 . V_98 = V_66 ;
V_46 -> V_98 . V_96 = NULL ;
type = F_50 ( V_38 , V_46 , & V_66 ) ;
break;
case V_43 ... V_52 :
default:
F_42 ( L_68 , type ) ;
}
* V_57 = V_66 ;
return type ;
}
static int F_60 ( struct V_38 * V_38 , struct V_45 * * V_17 )
{
enum V_40 type = V_43 ;
struct V_45 * V_46 ;
char * V_66 ;
int args = 0 ;
do {
if ( type == V_52 ) {
F_26 ( V_66 ) ;
type = F_28 ( & V_66 ) ;
continue;
}
V_46 = F_4 ( sizeof( * V_46 ) ) ;
memset ( V_46 , 0 , sizeof( * V_46 ) ) ;
type = F_44 ( V_38 , V_46 , & V_66 ) ;
if ( type == V_43 ) {
F_21 ( V_46 ) ;
return - 1 ;
}
* V_17 = V_46 ;
args ++ ;
if ( type == V_56 ) {
type = F_50 ( V_38 , V_46 , & V_66 ) ;
V_17 = & V_46 -> V_15 ;
continue;
}
if ( type == V_44 && strcmp ( V_66 , L_60 ) == 0 ) {
F_26 ( V_66 ) ;
* V_17 = V_46 ;
V_17 = & V_46 -> V_15 ;
continue;
}
break;
} while ( type != V_55 );
if ( type != V_55 )
F_26 ( V_66 ) ;
return args ;
}
static int F_61 ( struct V_38 * V_38 )
{
enum V_40 type ;
char * V_66 ;
int T_1 ;
if ( F_36 ( V_41 , L_69 ) < 0 )
return - 1 ;
if ( F_35 ( V_41 , L_70 ) < 0 )
return - 1 ;
if ( F_35 ( V_56 , L_6 ) < 0 )
return - 1 ;
if ( F_33 ( V_54 , & V_66 ) < 0 )
goto V_71;
V_118:
V_38 -> V_119 . V_91 = V_66 ;
V_38 -> V_119 . args = NULL ;
type = F_28 ( & V_66 ) ;
if ( type == V_55 )
return 0 ;
if ( type == V_54 ) {
char * V_120 ;
V_120 = F_4 ( strlen ( V_38 -> V_119 . V_91 ) +
strlen ( V_66 ) + 1 ) ;
strcpy ( V_120 , V_38 -> V_119 . V_91 ) ;
strcat ( V_120 , V_66 ) ;
F_26 ( V_66 ) ;
F_26 ( V_38 -> V_119 . V_91 ) ;
V_38 -> V_119 . V_91 = NULL ;
V_66 = V_120 ;
goto V_118;
}
if ( F_31 ( type , V_66 , V_44 , L_60 ) )
goto V_71;
F_26 ( V_66 ) ;
T_1 = F_60 ( V_38 , & V_38 -> V_119 . args ) ;
if ( T_1 < 0 )
return - 1 ;
return T_1 ;
V_71:
F_26 ( V_66 ) ;
return - 1 ;
}
static struct V_73 *
F_62 ( struct V_38 * V_38 , const char * V_82 )
{
struct V_73 * V_91 ;
for ( V_91 = V_38 -> V_91 . V_92 ;
V_91 ; V_91 = V_91 -> V_15 ) {
if ( strcmp ( V_91 -> V_82 , V_82 ) == 0 )
break;
}
return V_91 ;
}
static struct V_73 *
F_63 ( struct V_38 * V_38 , const char * V_82 )
{
struct V_73 * V_91 ;
for ( V_91 = V_38 -> V_91 . V_77 ;
V_91 ; V_91 = V_91 -> V_15 ) {
if ( strcmp ( V_91 -> V_82 , V_82 ) == 0 )
break;
}
return V_91 ;
}
static struct V_73 *
F_52 ( struct V_38 * V_38 , const char * V_82 )
{
struct V_73 * V_91 ;
V_91 = F_62 ( V_38 , V_82 ) ;
if ( V_91 )
return V_91 ;
return F_63 ( V_38 , V_82 ) ;
}
unsigned long long F_64 ( void * V_121 , int V_2 )
{
switch ( V_2 ) {
case 1 :
return * ( unsigned char * ) V_121 ;
case 2 :
return F_65 ( V_121 ) ;
case 4 :
return F_66 ( V_121 ) ;
case 8 :
return F_67 ( V_121 ) ;
default:
return 0 ;
}
}
unsigned long long
F_68 ( struct V_38 * V_38 , const char * V_82 , void * V_122 )
{
struct V_73 * V_74 ;
V_74 = F_52 ( V_38 , V_82 ) ;
if ( ! V_74 )
return 0ULL ;
return F_64 ( V_122 + V_74 -> V_89 , V_74 -> V_2 ) ;
}
void * F_69 ( struct V_38 * V_38 , const char * V_82 , void * V_122 )
{
struct V_73 * V_74 ;
V_74 = F_52 ( V_38 , V_82 ) ;
if ( ! V_74 )
return NULL ;
if ( V_74 -> V_75 & V_87 ) {
int V_89 ;
V_89 = * ( int * ) ( V_122 + V_74 -> V_89 ) ;
V_89 &= 0xffff ;
return V_122 + V_89 ;
}
return V_122 + V_74 -> V_89 ;
}
static int F_70 ( const char * type , int * V_89 , int * V_2 )
{
struct V_38 * V_38 ;
struct V_73 * V_74 ;
if ( ! V_39 )
F_42 ( L_71 ) ;
V_38 = V_39 ;
V_74 = F_62 ( V_38 , type ) ;
if ( ! V_74 )
F_42 ( L_72 , type ) ;
* V_89 = V_74 -> V_89 ;
* V_2 = V_74 -> V_2 ;
return 0 ;
}
static int F_71 ( void * V_122 , int * V_2 , int * V_89 ,
const char * V_82 )
{
int T_1 ;
if ( ! * V_2 ) {
T_1 = F_70 ( V_82 , V_89 , V_2 ) ;
if ( T_1 < 0 )
return T_1 ;
}
return F_64 ( V_122 + * V_89 , * V_2 ) ;
}
int F_72 ( void * V_122 )
{
static int V_123 ;
static int V_124 ;
return F_71 ( V_122 , & V_124 , & V_123 ,
L_73 ) ;
}
int F_73 ( void * V_122 )
{
static int V_125 ;
static int V_126 ;
return F_71 ( V_122 , & V_126 , & V_125 ,
L_74 ) ;
}
int F_74 ( void * V_122 )
{
static int V_127 ;
static int V_128 ;
return F_71 ( V_122 , & V_128 , & V_127 ,
L_75 ) ;
}
int F_75 ( void * V_122 )
{
static int V_129 ;
static int V_130 ;
return F_71 ( V_122 , & V_130 , & V_129 ,
L_76 ) ;
}
int F_76 ( void * V_122 )
{
static int V_131 ;
static int V_132 ;
int T_1 ;
T_1 = F_71 ( V_122 , & V_132 , & V_131 ,
L_77 ) ;
if ( T_1 < 0 )
return - 1 ;
return T_1 ;
}
struct V_38 * F_77 ( int V_72 )
{
struct V_38 * V_38 ;
for ( V_38 = V_39 ; V_38 ; V_38 = V_38 -> V_15 ) {
if ( V_38 -> V_72 == V_72 )
break;
}
return V_38 ;
}
struct V_38 * F_78 ( struct V_38 * V_38 )
{
if ( ! V_38 )
return V_39 ;
return V_38 -> V_15 ;
}
static unsigned long long F_79 ( void * V_122 , int V_2 ,
struct V_38 * V_38 , struct V_45 * V_46 )
{
unsigned long long V_106 = 0 ;
unsigned long long V_96 , V_97 ;
struct V_45 * V_133 ;
switch ( V_46 -> type ) {
case V_49 :
return 0 ;
case V_47 :
return F_7 ( V_46 -> V_48 . V_48 , NULL , 0 ) ;
case V_50 :
if ( ! V_46 -> V_74 . V_74 ) {
V_46 -> V_74 . V_74 = F_52 ( V_38 , V_46 -> V_74 . V_82 ) ;
if ( ! V_46 -> V_74 . V_74 )
F_42 ( L_78 , V_46 -> V_74 . V_82 ) ;
}
V_106 = F_64 ( V_122 + V_46 -> V_74 . V_74 -> V_89 ,
V_46 -> V_74 . V_74 -> V_2 ) ;
break;
case V_113 :
case V_109 :
break;
case V_107 :
return F_79 ( V_122 , V_2 , V_38 , V_46 -> V_108 . V_18 ) ;
case V_110 :
return 0 ;
break;
case V_51 :
if ( strcmp ( V_46 -> V_98 . V_98 , L_23 ) == 0 ) {
if ( V_46 -> V_98 . V_96 -> type != V_50 )
goto V_134;
V_133 = V_46 -> V_98 . V_96 ;
if ( ! V_133 -> V_74 . V_74 ) {
V_133 -> V_74 . V_74 =
F_52 ( V_38 , V_133 -> V_74 . V_82 ) ;
if ( ! V_133 -> V_74 . V_74 )
F_42 ( L_78 , V_133 -> V_74 . V_82 ) ;
}
V_97 = F_79 ( V_122 , V_2 , V_38 , V_46 -> V_98 . V_97 ) ;
V_106 = F_64 ( V_122 + V_133 -> V_74 . V_74 -> V_89 +
V_97 * V_135 , V_135 ) ;
break;
}
V_134:
V_96 = F_79 ( V_122 , V_2 , V_38 , V_46 -> V_98 . V_96 ) ;
V_97 = F_79 ( V_122 , V_2 , V_38 , V_46 -> V_98 . V_97 ) ;
switch ( V_46 -> V_98 . V_98 [ 0 ] ) {
case '|' :
if ( V_46 -> V_98 . V_98 [ 1 ] )
V_106 = V_96 || V_97 ;
else
V_106 = V_96 | V_97 ;
break;
case '&' :
if ( V_46 -> V_98 . V_98 [ 1 ] )
V_106 = V_96 && V_97 ;
else
V_106 = V_96 & V_97 ;
break;
case '<' :
switch ( V_46 -> V_98 . V_98 [ 1 ] ) {
case 0 :
V_106 = V_96 < V_97 ;
break;
case '<' :
V_106 = V_96 << V_97 ;
break;
case '=' :
V_106 = V_96 <= V_97 ;
break;
default:
F_42 ( L_42 , V_46 -> V_98 . V_98 ) ;
}
break;
case '>' :
switch ( V_46 -> V_98 . V_98 [ 1 ] ) {
case 0 :
V_106 = V_96 > V_97 ;
break;
case '>' :
V_106 = V_96 >> V_97 ;
break;
case '=' :
V_106 = V_96 >= V_97 ;
break;
default:
F_42 ( L_42 , V_46 -> V_98 . V_98 ) ;
}
break;
case '=' :
if ( V_46 -> V_98 . V_98 [ 1 ] != '=' )
F_42 ( L_42 , V_46 -> V_98 . V_98 ) ;
V_106 = V_96 == V_97 ;
break;
case '-' :
V_106 = V_96 - V_97 ;
break;
case '+' :
V_106 = V_96 + V_97 ;
break;
default:
F_42 ( L_42 , V_46 -> V_98 . V_98 ) ;
}
break;
default:
return 0 ;
}
return V_106 ;
}
unsigned long long F_80 ( const char * V_136 )
{
int V_19 ;
if ( isdigit ( V_136 [ 0 ] ) )
return F_7 ( V_136 , NULL , 0 ) ;
for ( V_19 = 0 ; V_19 < ( int ) ( sizeof( V_75 ) / sizeof( V_75 [ 0 ] ) ) ; V_19 ++ )
if ( strcmp ( V_75 [ V_19 ] . V_82 , V_136 ) == 0 )
return V_75 [ V_19 ] . V_112 ;
return 0 ;
}
static void F_81 ( void * V_122 , int V_2 ,
struct V_38 * V_38 , struct V_45 * V_46 )
{
struct V_111 * V_136 ;
unsigned long long V_106 , V_137 ;
char * V_70 ;
int V_138 ;
switch ( V_46 -> type ) {
case V_49 :
return;
case V_47 :
printf ( L_79 , V_46 -> V_48 . V_48 ) ;
return;
case V_50 :
if ( ! V_46 -> V_74 . V_74 ) {
V_46 -> V_74 . V_74 = F_52 ( V_38 , V_46 -> V_74 . V_82 ) ;
if ( ! V_46 -> V_74 . V_74 )
F_42 ( L_78 , V_46 -> V_74 . V_82 ) ;
}
V_70 = F_4 ( V_46 -> V_74 . V_74 -> V_2 + 1 ) ;
memcpy ( V_70 , V_122 + V_46 -> V_74 . V_74 -> V_89 ,
V_46 -> V_74 . V_74 -> V_2 ) ;
V_70 [ V_46 -> V_74 . V_74 -> V_2 ] = 0 ;
printf ( L_79 , V_70 ) ;
free ( V_70 ) ;
break;
case V_113 :
V_106 = F_79 ( V_122 , V_2 , V_38 , V_46 -> V_75 . V_74 ) ;
V_138 = 0 ;
for ( V_136 = V_46 -> V_75 . V_75 ; V_136 ; V_136 = V_136 -> V_15 ) {
V_137 = F_80 ( V_136 -> V_112 ) ;
if ( ! V_106 && ! V_137 ) {
printf ( L_79 , V_136 -> V_70 ) ;
break;
}
if ( V_137 && ( V_106 & V_137 ) == V_137 ) {
if ( V_138 && V_46 -> V_75 . V_114 )
printf ( L_79 , V_46 -> V_75 . V_114 ) ;
printf ( L_79 , V_136 -> V_70 ) ;
V_138 = 1 ;
V_106 &= ~ V_137 ;
}
}
break;
case V_109 :
V_106 = F_79 ( V_122 , V_2 , V_38 , V_46 -> V_115 . V_74 ) ;
for ( V_136 = V_46 -> V_115 . V_116 ; V_136 ; V_136 = V_136 -> V_15 ) {
V_137 = F_80 ( V_136 -> V_112 ) ;
if ( V_106 == V_137 ) {
printf ( L_79 , V_136 -> V_70 ) ;
break;
}
}
break;
case V_107 :
break;
case V_110 : {
int V_139 ;
if ( V_46 -> string . V_89 == - 1 ) {
struct V_73 * V_140 ;
V_140 = F_52 ( V_38 , V_46 -> string . string ) ;
V_46 -> string . V_89 = V_140 -> V_89 ;
}
V_139 = * ( int * ) ( V_122 + V_46 -> string . V_89 ) ;
V_139 &= 0xffff ;
printf ( L_79 , ( ( char * ) V_122 ) + V_139 ) ;
break;
}
case V_51 :
if ( V_46 -> V_98 . V_98 [ 0 ] != '?' )
return;
V_106 = F_79 ( V_122 , V_2 , V_38 , V_46 -> V_98 . V_96 ) ;
if ( V_106 )
F_81 ( V_122 , V_2 , V_38 , V_46 -> V_98 . V_97 -> V_98 . V_96 ) ;
else
F_81 ( V_122 , V_2 , V_38 , V_46 -> V_98 . V_97 -> V_98 . V_97 ) ;
break;
default:
break;
}
}
static struct V_45 * F_82 ( char * V_141 , void * V_122 , int V_2 , struct V_38 * V_38 )
{
static struct V_73 * V_74 , * V_142 ;
struct V_45 * args , * V_46 , * * V_15 ;
unsigned long long V_143 , V_106 ;
char * V_121 ;
void * V_144 ;
if ( ! V_74 ) {
V_74 = F_63 ( V_38 , L_80 ) ;
if ( ! V_74 )
F_42 ( L_81 ) ;
V_142 = F_63 ( V_38 , L_82 ) ;
if ( ! V_142 )
F_42 ( L_83 ) ;
}
V_143 = F_64 ( V_122 + V_142 -> V_89 , V_142 -> V_2 ) ;
args = F_4 ( sizeof( * args ) ) ;
V_46 = args ;
V_46 -> V_15 = NULL ;
V_15 = & V_46 -> V_15 ;
V_46 -> type = V_47 ;
V_46 -> V_48 . V_48 = F_4 ( 32 ) ;
sprintf ( V_46 -> V_48 . V_48 , L_58 , V_143 ) ;
for ( V_121 = V_141 + 6 , V_144 = V_122 + V_74 -> V_89 ;
V_144 < V_122 + V_2 && * V_121 ; V_121 ++ ) {
int V_145 = 0 ;
if ( * V_121 == '%' ) {
V_146:
V_121 ++ ;
switch ( * V_121 ) {
case '%' :
break;
case 'l' :
V_145 ++ ;
goto V_146;
case 'L' :
V_145 = 2 ;
goto V_146;
case '0' ... '9' :
goto V_146;
case 'p' :
V_145 = 1 ;
case 'd' :
case 'u' :
case 'x' :
case 'i' :
V_144 = ( void * ) ( ( ( unsigned long ) V_144 + 3 ) &
~ 3 ) ;
switch ( V_145 ) {
case 0 :
case 1 :
V_145 = V_135 ;
break;
case 2 :
V_145 = 8 ;
default:
break;
}
V_106 = F_64 ( V_144 , V_145 ) ;
V_144 += V_145 ;
V_46 = F_4 ( sizeof( * V_46 ) ) ;
V_46 -> V_15 = NULL ;
V_46 -> type = V_47 ;
V_46 -> V_48 . V_48 = F_4 ( 32 ) ;
sprintf ( V_46 -> V_48 . V_48 , L_58 , V_106 ) ;
* V_15 = V_46 ;
V_15 = & V_46 -> V_15 ;
break;
case 's' :
V_46 = F_4 ( sizeof( * V_46 ) ) ;
V_46 -> V_15 = NULL ;
V_46 -> type = V_110 ;
V_46 -> string . string = F_16 ( V_144 ) ;
V_144 += strlen ( V_144 ) + 1 ;
* V_15 = V_46 ;
V_15 = & V_46 -> V_15 ;
default:
break;
}
}
}
return args ;
}
static void F_83 ( struct V_45 * args )
{
struct V_45 * V_15 ;
while ( args ) {
V_15 = args -> V_15 ;
if ( args -> type == V_47 )
free ( args -> V_48 . V_48 ) ;
else
free ( args -> string . string ) ;
free ( args ) ;
args = V_15 ;
}
}
static char * F_84 ( void * V_122 , int V_2 V_13 , struct V_38 * V_38 )
{
unsigned long long V_25 ;
static struct V_73 * V_74 ;
struct V_34 * V_35 ;
char * V_91 ;
char * V_147 ;
if ( ! V_74 ) {
V_74 = F_63 ( V_38 , L_70 ) ;
if ( ! V_74 )
F_42 ( L_84 ) ;
printf ( L_85 , V_74 -> V_89 , V_74 -> V_2 ) ;
}
V_25 = F_64 ( V_122 + V_74 -> V_89 , V_74 -> V_2 ) ;
V_35 = F_12 ( V_25 ) ;
if ( ! V_35 ) {
V_91 = F_4 ( 45 ) ;
sprintf ( V_91 , L_86 ,
V_25 ) ;
return V_91 ;
}
V_147 = V_35 -> V_35 ;
if ( * V_147 == '"' )
V_147 ++ ;
V_91 = F_4 ( strlen ( V_147 ) + 10 ) ;
sprintf ( V_91 , L_87 , L_88 , V_147 ) ;
V_147 = V_91 + strlen ( V_91 ) - 1 ;
if ( * V_147 == '"' )
* V_147 = 0 ;
V_147 -= 2 ;
if ( strcmp ( V_147 , L_89 ) == 0 )
* V_147 = 0 ;
return V_91 ;
}
static void F_85 ( void * V_122 , int V_2 , struct V_38 * V_38 )
{
struct V_119 * V_119 = & V_38 -> V_119 ;
struct V_45 * V_46 = V_119 -> args ;
struct V_45 * args = NULL ;
const char * V_121 = V_119 -> V_91 ;
unsigned long long V_106 ;
struct V_22 * V_27 ;
const char * V_148 ;
char * V_149 = NULL ;
char V_91 [ 32 ] ;
int V_150 ;
int V_85 ;
int V_145 ;
if ( V_38 -> V_75 & V_151 )
V_121 = L_90 ;
if ( V_38 -> V_75 & V_152 ) {
V_149 = F_84 ( V_122 , V_2 , V_38 ) ;
args = F_82 ( V_149 , V_122 , V_2 , V_38 ) ;
V_46 = args ;
V_121 = V_149 ;
}
for (; * V_121 ; V_121 ++ ) {
V_145 = 0 ;
if ( * V_121 == '\\' ) {
V_121 ++ ;
switch ( * V_121 ) {
case 'n' :
printf ( L_1 ) ;
break;
case 't' :
printf ( L_91 ) ;
break;
case 'r' :
printf ( L_92 ) ;
break;
case '\\' :
printf ( L_93 ) ;
break;
default:
printf ( L_94 , * V_121 ) ;
break;
}
} else if ( * V_121 == '%' ) {
V_148 = V_121 ;
V_150 = 0 ;
V_153:
V_121 ++ ;
switch ( * V_121 ) {
case '%' :
printf ( L_95 ) ;
break;
case 'l' :
V_145 ++ ;
goto V_153;
case 'L' :
V_145 = 2 ;
goto V_153;
case 'z' :
case 'Z' :
case '0' ... '9' :
goto V_153;
case 'p' :
if ( V_135 == 4 )
V_145 = 1 ;
else
V_145 = 2 ;
if ( * ( V_121 + 1 ) == 'F' ||
* ( V_121 + 1 ) == 'f' ) {
V_121 ++ ;
V_150 = * V_121 ;
}
case 'd' :
case 'i' :
case 'x' :
case 'X' :
case 'u' :
if ( ! V_46 )
F_42 ( L_96 ) ;
V_85 = ( ( unsigned long ) V_121 + 1 ) -
( unsigned long ) V_148 ;
if ( V_85 > 32 )
F_42 ( L_97 ) ;
memcpy ( V_91 , V_148 , V_85 ) ;
V_91 [ V_85 ] = 0 ;
V_106 = F_79 ( V_122 , V_2 , V_38 , V_46 ) ;
V_46 = V_46 -> V_15 ;
if ( V_150 ) {
V_27 = F_9 ( V_106 ) ;
if ( V_27 ) {
printf ( L_79 , V_27 -> V_27 ) ;
if ( V_150 == 'F' )
printf ( L_98 ,
V_106 - V_27 -> V_25 ) ;
break;
}
}
switch ( V_145 ) {
case 0 :
printf ( V_91 , ( int ) V_106 ) ;
break;
case 1 :
printf ( V_91 , ( long ) V_106 ) ;
break;
case 2 :
printf ( V_91 , ( long long ) V_106 ) ;
break;
default:
F_42 ( L_99 , V_145 ) ;
}
break;
case 's' :
if ( ! V_46 )
F_42 ( L_100 ) ;
F_81 ( V_122 , V_2 , V_38 , V_46 ) ;
V_46 = V_46 -> V_15 ;
break;
default:
printf ( L_101 , * V_121 ) ;
}
} else
printf ( L_94 , * V_121 ) ;
}
if ( args ) {
F_83 ( args ) ;
free ( V_149 ) ;
}
}
static inline int F_86 ( int V_154 )
{
if ( V_154 / 100 )
return 3 ;
if ( V_154 / 10 )
return 2 ;
return 1 ;
}
static void F_87 ( void * V_122 , int V_2 V_13 )
{
unsigned int V_155 ;
unsigned int V_156 ;
int V_157 ;
int V_158 ;
int V_159 ;
V_155 = F_75 ( V_122 ) ;
V_156 = F_74 ( V_122 ) ;
V_157 = F_76 ( V_122 ) ;
V_158 = V_155 & V_160 ;
V_159 = V_155 & V_161 ;
printf ( L_102 ,
( V_155 & V_162 ) ? 'd' :
( V_155 & V_163 ) ?
'X' : '.' ,
( V_155 & V_164 ) ?
'N' : '.' ,
( V_158 && V_159 ) ? 'H' :
V_158 ? 'h' : V_159 ? 's' : '.' ) ;
if ( V_156 )
printf ( L_103 , V_156 ) ;
else
printf ( L_20 ) ;
if ( V_157 < 0 )
printf ( L_104 ) ;
else
printf ( L_105 , V_157 ) ;
}
static struct V_165 *
F_88 ( int V_166 , int V_167 , unsigned long long V_168 ,
struct V_165 * V_15 )
{
struct V_73 * V_74 ;
struct V_38 * V_38 ;
unsigned long V_106 ;
int type ;
int V_11 ;
type = F_72 ( V_15 -> V_122 ) ;
V_38 = F_77 ( type ) ;
if ( ! V_38 )
return NULL ;
if ( ! ( V_38 -> V_75 & V_169 ) )
return NULL ;
V_11 = F_73 ( V_15 -> V_122 ) ;
V_74 = F_63 ( V_38 , L_106 ) ;
if ( ! V_74 )
F_42 ( L_107 ) ;
V_106 = F_64 ( V_15 -> V_122 + V_74 -> V_89 , V_74 -> V_2 ) ;
if ( V_167 != V_11 || V_168 != V_106 )
return NULL ;
return F_89 ( V_166 ) ;
}
static void F_90 ( unsigned long long V_170 )
{
if ( V_170 == ~ 0ULL )
return ( void ) printf ( L_108 ) ;
if ( V_170 > 100000ULL )
return ( void ) printf ( L_109 ) ;
if ( V_170 > 10000ULL )
return ( void ) printf ( L_110 ) ;
printf ( L_108 ) ;
}
static void F_91 ( unsigned long long V_170 )
{
unsigned long V_171 = V_170 / 1000 ;
unsigned long V_172 = V_170 % 1000 ;
char V_173 [ 21 ] ;
char V_174 [ 5 ] ;
int V_85 ;
int V_19 ;
sprintf ( V_173 , L_111 , V_171 ) ;
V_85 = printf ( L_111 , V_171 ) ;
if ( V_85 < 7 ) {
snprintf ( V_174 , 8 - V_85 , L_112 , V_172 ) ;
V_85 += printf ( L_113 , V_174 ) ;
}
printf ( L_114 ) ;
for ( V_19 = V_85 ; V_19 < 7 ; V_19 ++ )
printf ( L_21 ) ;
printf ( L_115 ) ;
}
static void
F_92 ( struct V_38 * V_38 , void * V_122 , struct V_165 * V_175 )
{
unsigned long long V_176 , V_177 ;
unsigned long long V_170 , V_178 ;
unsigned long long V_106 ;
struct V_73 * V_74 ;
struct V_22 * V_27 ;
struct V_38 * V_179 ;
int type ;
int V_19 ;
type = F_72 ( V_175 -> V_122 ) ;
V_179 = F_77 ( type ) ;
V_74 = F_63 ( V_179 , L_116 ) ;
if ( ! V_74 )
F_42 ( L_117 ) ;
V_176 = F_64 ( V_175 -> V_122 + V_74 -> V_89 , V_74 -> V_2 ) ;
V_74 = F_63 ( V_179 , L_118 ) ;
if ( ! V_74 )
F_42 ( L_117 ) ;
V_177 = F_64 ( V_175 -> V_122 + V_74 -> V_89 , V_74 -> V_2 ) ;
V_170 = V_176 - V_177 ;
F_90 ( V_170 ) ;
F_91 ( V_170 ) ;
V_74 = F_63 ( V_38 , L_119 ) ;
if ( ! V_74 )
F_42 ( L_120 ) ;
V_178 = F_64 ( V_122 + V_74 -> V_89 , V_74 -> V_2 ) ;
for ( V_19 = 0 ; V_19 < ( int ) ( V_178 * V_180 ) ; V_19 ++ )
printf ( L_21 ) ;
V_74 = F_63 ( V_38 , L_106 ) ;
if ( ! V_74 )
F_42 ( L_121 ) ;
V_106 = F_64 ( V_122 + V_74 -> V_89 , V_74 -> V_2 ) ;
V_27 = F_9 ( V_106 ) ;
if ( V_27 )
printf ( L_122 , V_27 -> V_27 ) ;
else
printf ( L_123 , V_106 ) ;
}
static void F_93 ( struct V_38 * V_38 , void * V_122 )
{
struct V_73 * V_74 ;
unsigned long long V_178 ;
unsigned long long V_106 ;
struct V_22 * V_27 ;
int V_19 ;
F_90 ( - 1 ) ;
printf ( L_124 ) ;
V_74 = F_63 ( V_38 , L_119 ) ;
if ( ! V_74 )
F_42 ( L_120 ) ;
V_178 = F_64 ( V_122 + V_74 -> V_89 , V_74 -> V_2 ) ;
for ( V_19 = 0 ; V_19 < ( int ) ( V_178 * V_180 ) ; V_19 ++ )
printf ( L_21 ) ;
V_74 = F_63 ( V_38 , L_106 ) ;
if ( ! V_74 )
F_42 ( L_121 ) ;
V_106 = F_64 ( V_122 + V_74 -> V_89 , V_74 -> V_2 ) ;
V_27 = F_9 ( V_106 ) ;
if ( V_27 )
printf ( L_125 , V_27 -> V_27 ) ;
else
printf ( L_126 , V_106 ) ;
}
static void
F_94 ( void * V_122 , int V_2 , struct V_38 * V_38 ,
int V_166 , int V_11 )
{
struct V_73 * V_74 ;
struct V_165 * V_181 ;
void * V_182 ;
unsigned long V_106 ;
if ( V_183 ) {
F_87 ( V_122 , V_2 ) ;
printf ( L_127 ) ;
}
V_74 = F_63 ( V_38 , L_106 ) ;
if ( ! V_74 )
F_42 ( L_128 ) ;
V_106 = F_64 ( V_122 + V_74 -> V_89 , V_74 -> V_2 ) ;
V_182 = F_4 ( V_2 ) ;
memcpy ( V_182 , V_122 , V_2 ) ;
V_122 = V_182 ;
V_181 = F_95 ( V_166 ) ;
if ( V_181 ) {
V_181 = F_88 ( V_166 , V_11 , V_106 , V_181 ) ;
if ( V_181 ) {
F_92 ( V_38 , V_122 , V_181 ) ;
goto V_99;
}
}
F_93 ( V_38 , V_122 ) ;
V_99:
free ( V_122 ) ;
}
static void
F_96 ( void * V_122 , int V_2 V_13 , struct V_38 * V_38 )
{
unsigned long long V_176 , V_177 ;
unsigned long long V_170 , V_178 ;
struct V_73 * V_74 ;
int V_19 ;
if ( V_183 ) {
F_87 ( V_122 , V_2 ) ;
printf ( L_127 ) ;
}
V_74 = F_63 ( V_38 , L_116 ) ;
if ( ! V_74 )
F_42 ( L_117 ) ;
V_176 = F_64 ( V_122 + V_74 -> V_89 , V_74 -> V_2 ) ;
V_74 = F_63 ( V_38 , L_118 ) ;
if ( ! V_74 )
F_42 ( L_129 ) ;
V_177 = F_64 ( V_122 + V_74 -> V_89 , V_74 -> V_2 ) ;
V_170 = V_176 - V_177 ;
F_90 ( V_170 ) ;
F_91 ( V_170 ) ;
V_74 = F_63 ( V_38 , L_119 ) ;
if ( ! V_74 )
F_42 ( L_120 ) ;
V_178 = F_64 ( V_122 + V_74 -> V_89 , V_74 -> V_2 ) ;
for ( V_19 = 0 ; V_19 < ( int ) ( V_178 * V_180 ) ; V_19 ++ )
printf ( L_21 ) ;
printf ( L_61 ) ;
}
static void
F_97 ( void * V_122 , int V_2 , struct V_38 * V_38 ,
int V_166 , int V_11 )
{
if ( V_38 -> V_75 & V_184 )
F_94 ( V_122 , V_2 , V_38 , V_166 , V_11 ) ;
else if ( V_38 -> V_75 & V_169 )
F_96 ( V_122 , V_2 , V_38 ) ;
printf ( L_1 ) ;
}
void F_98 ( int V_166 , void * V_122 , int V_2 )
{
struct V_38 * V_38 ;
int type ;
int V_11 ;
type = F_72 ( V_122 ) ;
V_38 = F_77 ( type ) ;
if ( ! V_38 ) {
F_15 ( L_130 , type ) ;
return;
}
V_11 = F_73 ( V_122 ) ;
if ( V_38 -> V_75 & ( V_184 | V_169 ) )
return F_97 ( V_122 , V_2 , V_38 , V_166 , V_11 ) ;
if ( V_183 )
F_87 ( V_122 , V_2 ) ;
if ( V_38 -> V_75 & V_101 ) {
printf ( L_131 ,
V_38 -> V_82 ) ;
return;
}
F_85 ( V_122 , V_2 , V_38 ) ;
}
static void F_99 ( struct V_111 * V_74 )
{
printf ( L_132 , V_74 -> V_112 , V_74 -> V_70 ) ;
if ( V_74 -> V_15 ) {
printf ( L_133 ) ;
F_99 ( V_74 -> V_15 ) ;
}
}
static void F_100 ( struct V_45 * args )
{
int V_185 = 1 ;
switch ( args -> type ) {
case V_49 :
printf ( L_134 ) ;
break;
case V_47 :
printf ( L_79 , args -> V_48 . V_48 ) ;
break;
case V_50 :
printf ( L_135 , args -> V_74 . V_82 ) ;
break;
case V_113 :
printf ( L_136 ) ;
F_100 ( args -> V_75 . V_74 ) ;
printf ( L_137 , args -> V_75 . V_114 ) ;
F_99 ( args -> V_75 . V_75 ) ;
printf ( L_53 ) ;
break;
case V_109 :
printf ( L_138 ) ;
F_100 ( args -> V_115 . V_74 ) ;
printf ( L_133 ) ;
F_99 ( args -> V_115 . V_116 ) ;
printf ( L_53 ) ;
break;
case V_110 :
printf ( L_139 , args -> string . string ) ;
break;
case V_107 :
printf ( L_140 , args -> V_108 . type ) ;
F_100 ( args -> V_108 . V_18 ) ;
break;
case V_51 :
if ( strcmp ( args -> V_98 . V_98 , L_6 ) == 0 )
V_185 = 0 ;
if ( V_185 )
printf ( L_62 ) ;
F_100 ( args -> V_98 . V_96 ) ;
printf ( L_141 , args -> V_98 . V_98 ) ;
F_100 ( args -> V_98 . V_97 ) ;
if ( V_185 )
printf ( L_53 ) ;
break;
default:
return;
}
if ( args -> V_15 ) {
printf ( L_1 ) ;
F_100 ( args -> V_15 ) ;
}
}
int F_101 ( char * V_1 , unsigned long V_2 )
{
struct V_73 * V_74 ;
struct V_45 * V_46 , * * V_17 ;
struct V_38 * V_38 ;
int T_1 ;
F_1 ( V_1 , V_2 ) ;
V_38 = F_18 () ;
if ( ! V_38 )
return - V_186 ;
V_38 -> V_75 |= V_80 ;
V_38 -> V_82 = F_37 () ;
if ( ! V_38 -> V_82 )
F_42 ( L_142 ) ;
if ( strcmp ( V_38 -> V_82 , L_143 ) == 0 )
V_38 -> V_75 |= V_151 ;
else if ( strcmp ( V_38 -> V_82 , L_144 ) == 0 )
V_38 -> V_75 |= V_184 ;
else if ( strcmp ( V_38 -> V_82 , L_145 ) == 0 )
V_38 -> V_75 |= V_169 ;
else if ( strcmp ( V_38 -> V_82 , L_146 ) == 0 )
V_38 -> V_75 |= V_152 ;
V_38 -> V_72 = F_38 () ;
if ( V_38 -> V_72 < 0 )
F_42 ( L_147 ) ;
F_19 ( V_38 ) ;
T_1 = F_43 ( V_38 ) ;
if ( T_1 < 0 )
F_42 ( L_148 ) ;
T_1 = F_61 ( V_38 ) ;
if ( T_1 < 0 )
F_42 ( L_149 ) ;
if ( T_1 > 0 )
return 0 ;
V_17 = & V_38 -> V_119 . args ;
for ( V_74 = V_38 -> V_91 . V_77 ; V_74 ; V_74 = V_74 -> V_15 ) {
V_46 = F_4 ( sizeof( * V_46 ) ) ;
memset ( V_46 , 0 , sizeof( * V_46 ) ) ;
* V_17 = V_46 ;
V_17 = & V_46 -> V_15 ;
V_46 -> type = V_50 ;
V_46 -> V_74 . V_82 = V_74 -> V_82 ;
V_46 -> V_74 . V_74 = V_74 ;
}
return 0 ;
}
int F_102 ( char * V_1 , unsigned long V_2 , char * V_187 )
{
struct V_38 * V_38 ;
int T_1 ;
F_1 ( V_1 , V_2 ) ;
V_38 = F_18 () ;
if ( ! V_38 )
return - V_186 ;
V_38 -> V_82 = F_37 () ;
if ( ! V_38 -> V_82 )
F_42 ( L_150 ) ;
V_38 -> V_72 = F_38 () ;
if ( V_38 -> V_72 < 0 )
F_42 ( L_151 ) ;
T_1 = F_43 ( V_38 ) ;
if ( T_1 < 0 ) {
F_15 ( L_152 , V_38 -> V_82 ) ;
goto V_188;
}
T_1 = F_61 ( V_38 ) ;
if ( T_1 < 0 ) {
F_15 ( L_153 , V_38 -> V_82 ) ;
goto V_188;
}
V_38 -> system = F_16 ( V_187 ) ;
#define F_103 0
if ( F_103 && V_38 -> V_119 . args )
F_100 ( V_38 -> V_119 . args ) ;
F_19 ( V_38 ) ;
return 0 ;
V_188:
V_38 -> V_75 |= V_101 ;
F_19 ( V_38 ) ;
return - 1 ;
}
void F_104 ( int V_189 , int V_190 )
{
V_191 = V_189 ;
V_135 = V_190 ;
}
int F_105 ( struct V_192 * V_193 )
{
return F_74 ( V_193 -> V_194 ) ;
}
int F_106 ( struct V_192 * V_193 )
{
return F_75 ( V_193 -> V_194 ) ;
}
int F_107 ( struct V_192 * V_193 )
{
return F_76 ( V_193 -> V_194 ) ;
}
