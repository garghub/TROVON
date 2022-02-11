static void F_1 ( const char * V_1 , unsigned long long V_2 )
{
V_3 = V_1 ;
V_4 = V_2 ;
V_5 = 0 ;
}
const char * F_2 ( void )
{
return V_3 ;
}
unsigned long long F_3 ( void )
{
return V_5 ;
}
void F_4 ( const char * V_1 , unsigned long long V_2 )
{
F_1 ( V_1 , V_2 ) ;
}
void F_5 ( void )
{
static int V_6 ;
V_6 ++ ;
}
struct V_7 * F_6 ( void )
{
return calloc ( 1 , sizeof( struct V_7 ) ) ;
}
static int F_7 ( const void * V_8 , const void * V_9 )
{
const struct V_10 * V_11 = V_8 ;
const struct V_10 * V_12 = V_9 ;
if ( V_11 -> V_13 < V_12 -> V_13 )
return - 1 ;
if ( V_11 -> V_13 > V_12 -> V_13 )
return 1 ;
return 0 ;
}
static int F_8 ( struct V_14 * V_14 )
{
struct V_15 * V_16 = V_14 -> V_16 ;
struct V_15 * V_17 ;
struct V_10 * V_18 ;
int V_19 ;
V_18 = malloc ( sizeof( * V_18 ) * V_14 -> V_20 ) ;
if ( ! V_18 )
return - 1 ;
V_19 = 0 ;
while ( V_16 ) {
V_18 [ V_19 ] . V_13 = V_16 -> V_13 ;
V_18 [ V_19 ] . V_21 = V_16 -> V_21 ;
V_19 ++ ;
V_17 = V_16 ;
V_16 = V_16 -> V_22 ;
free ( V_17 ) ;
}
qsort ( V_18 , V_14 -> V_20 , sizeof( * V_18 ) , F_7 ) ;
V_14 -> V_18 = V_18 ;
V_14 -> V_16 = NULL ;
return 0 ;
}
static const char * F_9 ( struct V_14 * V_14 , int V_13 )
{
const struct V_10 * V_21 ;
struct V_10 V_23 ;
if ( ! V_13 )
return L_1 ;
if ( ! V_14 -> V_18 && F_8 ( V_14 ) )
return L_2 ;
V_23 . V_13 = V_13 ;
V_21 = bsearch ( & V_23 , V_14 -> V_18 , V_14 -> V_20 ,
sizeof( * V_14 -> V_18 ) , F_7 ) ;
if ( V_21 )
return V_21 -> V_21 ;
return L_3 ;
}
int F_10 ( struct V_14 * V_14 , int V_13 )
{
const struct V_10 * V_21 ;
struct V_10 V_23 ;
if ( ! V_13 )
return 1 ;
if ( ! V_14 -> V_18 && F_8 ( V_14 ) )
return 0 ;
V_23 . V_13 = V_13 ;
V_21 = bsearch ( & V_23 , V_14 -> V_18 , V_14 -> V_20 ,
sizeof( * V_14 -> V_18 ) , F_7 ) ;
if ( V_21 )
return 1 ;
return 0 ;
}
static int F_11 ( struct V_14 * V_14 , const char * V_21 , int V_13 )
{
struct V_10 * V_18 = V_14 -> V_18 ;
const struct V_10 * V_10 ;
struct V_10 V_23 ;
if ( ! V_13 )
return 0 ;
V_23 . V_13 = V_13 ;
V_10 = bsearch ( & V_23 , V_14 -> V_18 , V_14 -> V_20 ,
sizeof( * V_14 -> V_18 ) , F_7 ) ;
if ( V_10 ) {
V_24 = V_25 ;
return - 1 ;
}
V_18 = realloc ( V_18 , sizeof( * V_18 ) * ( V_14 -> V_20 + 1 ) ) ;
if ( ! V_18 ) {
V_24 = V_26 ;
return - 1 ;
}
V_18 [ V_14 -> V_20 ] . V_21 = F_12 ( V_21 ) ;
if ( ! V_18 [ V_14 -> V_20 ] . V_21 ) {
free ( V_18 ) ;
V_24 = V_26 ;
return - 1 ;
}
V_18 [ V_14 -> V_20 ] . V_13 = V_13 ;
if ( V_18 [ V_14 -> V_20 ] . V_21 )
V_14 -> V_20 ++ ;
qsort ( V_18 , V_14 -> V_20 , sizeof( * V_18 ) , F_7 ) ;
V_14 -> V_18 = V_18 ;
return 0 ;
}
int F_13 ( struct V_14 * V_14 , const char * V_21 , int V_13 )
{
struct V_15 * V_17 ;
if ( V_14 -> V_18 )
return F_11 ( V_14 , V_21 , V_13 ) ;
V_17 = malloc ( sizeof( * V_17 ) ) ;
if ( ! V_17 )
return - 1 ;
V_17 -> V_21 = F_12 ( V_21 ) ;
if ( ! V_17 -> V_21 ) {
free ( V_17 ) ;
return - 1 ;
}
V_17 -> V_13 = V_13 ;
V_17 -> V_22 = V_14 -> V_16 ;
V_14 -> V_16 = V_17 ;
V_14 -> V_20 ++ ;
return 0 ;
}
void F_14 ( struct V_14 * V_14 , char * V_27 )
{
V_14 -> V_27 = V_27 ;
}
static int F_15 ( const void * V_8 , const void * V_9 )
{
const struct V_28 * V_29 = V_8 ;
const struct V_28 * V_30 = V_9 ;
if ( V_29 -> V_31 < V_30 -> V_31 )
return - 1 ;
if ( V_29 -> V_31 > V_30 -> V_31 )
return 1 ;
return 0 ;
}
static int F_16 ( const void * V_8 , const void * V_9 )
{
const struct V_28 * V_29 = V_8 ;
const struct V_28 * V_30 = V_9 ;
if ( ( V_29 -> V_31 == V_30 -> V_31 ) ||
( V_29 -> V_31 > V_30 -> V_31 &&
V_29 -> V_31 < ( V_30 + 1 ) -> V_31 ) )
return 0 ;
if ( V_29 -> V_31 < V_30 -> V_31 )
return - 1 ;
return 1 ;
}
static int F_17 ( struct V_14 * V_14 )
{
struct V_32 * V_33 ;
struct V_32 * V_17 ;
struct V_28 * V_28 ;
int V_19 ;
V_28 = malloc ( sizeof( * V_28 ) * ( V_14 -> V_34 + 1 ) ) ;
if ( ! V_28 )
return - 1 ;
V_33 = V_14 -> V_33 ;
V_19 = 0 ;
while ( V_33 ) {
V_28 [ V_19 ] . V_35 = V_33 -> V_35 ;
V_28 [ V_19 ] . V_31 = V_33 -> V_31 ;
V_28 [ V_19 ] . V_36 = V_33 -> V_36 ;
V_19 ++ ;
V_17 = V_33 ;
V_33 = V_33 -> V_22 ;
free ( V_17 ) ;
}
qsort ( V_28 , V_14 -> V_34 , sizeof( * V_28 ) , F_15 ) ;
V_28 [ V_14 -> V_34 ] . V_35 = NULL ;
V_28 [ V_14 -> V_34 ] . V_31 = 0 ;
V_28 [ V_14 -> V_34 ] . V_36 = NULL ;
V_14 -> V_28 = V_28 ;
V_14 -> V_33 = NULL ;
return 0 ;
}
static struct V_28 *
F_18 ( struct V_14 * V_14 , unsigned long long V_31 )
{
struct V_28 * V_35 ;
struct V_28 V_23 ;
if ( ! V_14 -> V_28 )
F_17 ( V_14 ) ;
V_23 . V_31 = V_31 ;
V_35 = bsearch ( & V_23 , V_14 -> V_28 , V_14 -> V_34 ,
sizeof( * V_14 -> V_28 ) , F_16 ) ;
return V_35 ;
}
const char * F_19 ( struct V_14 * V_14 , unsigned long long V_31 )
{
struct V_28 * V_37 ;
V_37 = F_18 ( V_14 , V_31 ) ;
if ( ! V_37 )
return NULL ;
return V_37 -> V_35 ;
}
unsigned long long
F_20 ( struct V_14 * V_14 , unsigned long long V_31 )
{
struct V_28 * V_37 ;
V_37 = F_18 ( V_14 , V_31 ) ;
if ( ! V_37 )
return 0 ;
return V_37 -> V_31 ;
}
int F_21 ( struct V_14 * V_14 , char * V_35 ,
unsigned long long V_31 , char * V_36 )
{
struct V_32 * V_17 = malloc ( sizeof( * V_17 ) ) ;
if ( ! V_17 )
return - 1 ;
V_17 -> V_22 = V_14 -> V_33 ;
V_17 -> V_35 = F_12 ( V_35 ) ;
if ( ! V_17 -> V_35 )
goto V_38;
if ( V_36 ) {
V_17 -> V_36 = F_12 ( V_36 ) ;
if ( ! V_17 -> V_36 )
goto V_39;
} else
V_17 -> V_36 = NULL ;
V_17 -> V_31 = V_31 ;
V_14 -> V_33 = V_17 ;
V_14 -> V_34 ++ ;
return 0 ;
V_39:
free ( V_17 -> V_35 ) ;
V_17 -> V_35 = NULL ;
V_38:
free ( V_17 ) ;
V_24 = V_26 ;
return - 1 ;
}
void F_22 ( struct V_14 * V_14 )
{
int V_19 ;
if ( ! V_14 -> V_28 )
F_17 ( V_14 ) ;
for ( V_19 = 0 ; V_19 < ( int ) V_14 -> V_34 ; V_19 ++ ) {
printf ( L_4 ,
V_14 -> V_28 [ V_19 ] . V_31 ,
V_14 -> V_28 [ V_19 ] . V_35 ) ;
if ( V_14 -> V_28 [ V_19 ] . V_36 )
printf ( L_5 , V_14 -> V_28 [ V_19 ] . V_36 ) ;
else
printf ( L_6 ) ;
}
}
static int F_23 ( const void * V_8 , const void * V_9 )
{
const struct V_40 * V_41 = V_8 ;
const struct V_40 * V_42 = V_9 ;
if ( V_41 -> V_31 < V_42 -> V_31 )
return - 1 ;
if ( V_41 -> V_31 > V_42 -> V_31 )
return 1 ;
return 0 ;
}
static int F_24 ( struct V_14 * V_14 )
{
struct V_43 * V_44 ;
struct V_43 * V_17 ;
struct V_40 * V_40 ;
int V_19 ;
V_40 = malloc ( sizeof( * V_40 ) * ( V_14 -> V_45 + 1 ) ) ;
if ( ! V_40 )
return - 1 ;
V_44 = V_14 -> V_44 ;
V_19 = 0 ;
while ( V_44 ) {
V_40 [ V_19 ] . V_46 = V_44 -> V_46 ;
V_40 [ V_19 ] . V_31 = V_44 -> V_31 ;
V_19 ++ ;
V_17 = V_44 ;
V_44 = V_44 -> V_22 ;
free ( V_17 ) ;
}
qsort ( V_40 , V_14 -> V_45 , sizeof( * V_40 ) , F_23 ) ;
V_14 -> V_40 = V_40 ;
V_14 -> V_44 = NULL ;
return 0 ;
}
static struct V_40 *
F_25 ( struct V_14 * V_14 , unsigned long long V_31 )
{
struct V_40 * V_46 ;
struct V_40 V_23 ;
if ( ! V_14 -> V_40 && F_24 ( V_14 ) )
return NULL ;
V_23 . V_31 = V_31 ;
V_46 = bsearch ( & V_23 , V_14 -> V_40 , V_14 -> V_45 ,
sizeof( * V_14 -> V_40 ) , F_23 ) ;
return V_46 ;
}
int F_26 ( struct V_14 * V_14 , const char * V_47 ,
unsigned long long V_31 )
{
struct V_43 * V_17 = malloc ( sizeof( * V_17 ) ) ;
char * V_48 ;
if ( ! V_17 )
return - 1 ;
V_17 -> V_22 = V_14 -> V_44 ;
V_17 -> V_31 = V_31 ;
if ( V_47 [ 0 ] == '"' )
V_47 ++ ;
V_17 -> V_46 = F_12 ( V_47 ) ;
if ( ! V_17 -> V_46 )
goto V_38;
V_48 = V_17 -> V_46 + strlen ( V_17 -> V_46 ) - 1 ;
if ( * V_48 == '"' )
* V_48 = 0 ;
V_48 -= 2 ;
if ( strcmp ( V_48 , L_7 ) == 0 )
* V_48 = 0 ;
V_14 -> V_44 = V_17 ;
V_14 -> V_45 ++ ;
return 0 ;
V_38:
free ( V_17 ) ;
V_24 = V_26 ;
return - 1 ;
}
void F_27 ( struct V_14 * V_14 )
{
int V_19 ;
if ( ! V_14 -> V_40 )
F_24 ( V_14 ) ;
for ( V_19 = 0 ; V_19 < ( int ) V_14 -> V_45 ; V_19 ++ ) {
printf ( L_8 ,
V_14 -> V_40 [ V_19 ] . V_31 ,
V_14 -> V_40 [ V_19 ] . V_46 ) ;
}
}
static struct V_49 * F_28 ( void )
{
return calloc ( 1 , sizeof( struct V_49 ) ) ;
}
static int F_29 ( struct V_14 * V_14 , struct V_49 * V_50 )
{
int V_19 ;
struct V_49 * * V_51 = realloc ( V_14 -> V_51 , sizeof( V_50 ) *
( V_14 -> V_52 + 1 ) ) ;
if ( ! V_51 )
return - 1 ;
V_14 -> V_51 = V_51 ;
for ( V_19 = 0 ; V_19 < V_14 -> V_52 ; V_19 ++ ) {
if ( V_14 -> V_51 [ V_19 ] -> V_53 > V_50 -> V_53 )
break;
}
if ( V_19 < V_14 -> V_52 )
memmove ( & V_14 -> V_51 [ V_19 + 1 ] ,
& V_14 -> V_51 [ V_19 ] ,
sizeof( V_50 ) * ( V_14 -> V_52 - V_19 ) ) ;
V_14 -> V_51 [ V_19 ] = V_50 ;
V_14 -> V_52 ++ ;
V_50 -> V_14 = V_14 ;
return 0 ;
}
static int F_30 ( enum V_54 type )
{
switch ( type ) {
case V_55 ... V_56 :
return 1 ;
case V_57 ... V_58 :
default:
return 0 ;
}
}
static void F_31 ( struct V_59 * V_60 )
{
struct V_59 * V_22 ;
while ( V_60 ) {
V_22 = V_60 -> V_22 ;
free ( V_60 -> V_61 ) ;
free ( V_60 -> V_62 ) ;
free ( V_60 ) ;
V_60 = V_22 ;
}
}
static void F_32 ( struct V_7 * V_63 )
{
struct V_7 * V_64 ;
if ( ! V_63 )
return;
switch ( V_63 -> type ) {
case V_65 :
free ( V_63 -> V_66 . V_66 ) ;
break;
case V_67 :
free ( V_63 -> V_68 . V_69 ) ;
break;
case V_70 :
F_32 ( V_63 -> V_71 . V_68 ) ;
free ( V_63 -> V_71 . V_72 ) ;
F_31 ( V_63 -> V_71 . V_71 ) ;
break;
case V_73 :
F_32 ( V_63 -> V_74 . V_68 ) ;
F_31 ( V_63 -> V_74 . V_75 ) ;
break;
case V_76 :
F_32 ( V_63 -> V_77 . V_68 ) ;
F_32 ( V_63 -> V_77 . V_2 ) ;
break;
case V_78 :
free ( V_63 -> V_79 . type ) ;
F_32 ( V_63 -> V_79 . V_17 ) ;
break;
case V_80 :
case V_81 :
free ( V_63 -> string . string ) ;
break;
case V_82 :
free ( V_63 -> V_83 . V_84 ) ;
break;
case V_85 :
free ( V_63 -> V_86 . V_86 ) ;
F_32 ( V_63 -> V_86 . V_87 ) ;
F_32 ( V_63 -> V_86 . V_88 ) ;
break;
case V_89 :
while ( V_63 -> V_35 . args ) {
V_64 = V_63 -> V_35 . args ;
V_63 -> V_35 . args = V_64 -> V_22 ;
F_32 ( V_64 ) ;
}
break;
case V_90 :
default:
break;
}
free ( V_63 ) ;
}
static enum V_54 F_33 ( int V_91 )
{
if ( V_91 == '\n' )
return V_92 ;
if ( isspace ( V_91 ) )
return V_93 ;
if ( isalnum ( V_91 ) || V_91 == '_' )
return V_55 ;
if ( V_91 == '\'' )
return V_56 ;
if ( V_91 == '"' )
return V_94 ;
if ( ! isprint ( V_91 ) )
return V_95 ;
if ( V_91 == '(' || V_91 == ')' || V_91 == ',' )
return V_58 ;
return V_96 ;
}
static int F_34 ( void )
{
if ( V_5 >= V_4 )
return - 1 ;
return V_3 [ V_5 ++ ] ;
}
static int F_35 ( void )
{
if ( V_5 >= V_4 )
return - 1 ;
return V_3 [ V_5 ] ;
}
int F_36 ( void )
{
return F_35 () ;
}
static int F_37 ( char * * V_97 , char * V_1 , int V_2 )
{
char * V_98 = realloc ( * V_97 , V_2 ) ;
if ( ! V_98 ) {
free ( * V_97 ) ;
* V_97 = NULL ;
return - 1 ;
}
if ( ! * V_97 )
strcpy ( V_98 , V_1 ) ;
else
strcat ( V_98 , V_1 ) ;
* V_97 = V_98 ;
return 0 ;
}
static enum V_54 F_38 ( char * * V_97 )
{
char V_1 [ V_99 ] ;
int V_91 , V_100 , V_101 , V_102 ;
int V_19 = 0 ;
int V_103 = 0 ;
enum V_54 type ;
* V_97 = NULL ;
V_91 = F_34 () ;
if ( V_91 < 0 )
return V_95 ;
type = F_33 ( V_91 ) ;
if ( type == V_95 )
return type ;
V_1 [ V_19 ++ ] = V_91 ;
switch ( type ) {
case V_92 :
case V_58 :
if ( F_39 ( V_97 , L_9 , V_91 ) < 0 )
return V_57 ;
return type ;
case V_96 :
switch ( V_91 ) {
case '-' :
V_102 = F_35 () ;
if ( V_102 == '>' ) {
V_1 [ V_19 ++ ] = F_34 () ;
break;
}
case '+' :
case '|' :
case '&' :
case '>' :
case '<' :
V_100 = V_91 ;
V_91 = F_35 () ;
if ( V_91 != V_100 )
goto V_104;
V_1 [ V_19 ++ ] = F_34 () ;
switch ( V_100 ) {
case '>' :
case '<' :
goto V_104;
default:
break;
}
break;
case '!' :
case '=' :
goto V_104;
default:
break;
}
V_1 [ V_19 ] = 0 ;
* V_97 = F_12 ( V_1 ) ;
return type ;
V_104:
V_91 = F_35 () ;
if ( V_91 == '=' )
V_1 [ V_19 ++ ] = F_34 () ;
goto V_105;
case V_94 :
case V_56 :
V_19 -- ;
V_101 = V_91 ;
V_100 = 0 ;
V_106:
do {
if ( V_19 == ( V_99 - 1 ) ) {
V_1 [ V_19 ] = 0 ;
V_103 += V_99 ;
if ( F_37 ( V_97 , V_1 , V_103 ) < 0 )
return V_95 ;
V_19 = 0 ;
}
V_100 = V_91 ;
V_91 = F_34 () ;
V_1 [ V_19 ++ ] = V_91 ;
if ( V_91 == '\\' && V_100 == '\\' )
V_100 = 0 ;
} while ( V_91 != V_101 || V_100 == '\\' );
V_19 -- ;
if ( type == V_94 ) {
unsigned long long V_107 = V_5 ;
do {
V_91 = F_34 () ;
} while ( isspace ( V_91 ) );
if ( V_91 == '"' )
goto V_106;
V_5 = V_107 ;
}
goto V_105;
case V_57 ... V_93 :
case V_55 :
default:
break;
}
while ( F_33 ( F_35 () ) == type ) {
if ( V_19 == ( V_99 - 1 ) ) {
V_1 [ V_19 ] = 0 ;
V_103 += V_99 ;
if ( F_37 ( V_97 , V_1 , V_103 ) < 0 )
return V_95 ;
V_19 = 0 ;
}
V_91 = F_34 () ;
V_1 [ V_19 ++ ] = V_91 ;
}
V_105:
V_1 [ V_19 ] = 0 ;
if ( F_37 ( V_97 , V_1 , V_103 + V_19 + 1 ) < 0 )
return V_95 ;
if ( type == V_55 ) {
if ( strcmp ( * V_97 , L_10 ) == 0 ) {
free ( * V_97 ) ;
* V_97 = NULL ;
return F_40 ( L_11 , V_97 ) ;
} else if ( strcmp ( * V_97 , L_12 ) == 0 ) {
free ( * V_97 ) ;
* V_97 = NULL ;
return F_40 ( L_13 , V_97 ) ;
} else if ( strcmp ( * V_97 , L_14 ) == 0 ) {
free ( * V_97 ) ;
* V_97 = NULL ;
return F_40 ( L_15 , V_97 ) ;
}
}
return type ;
}
static enum V_54 F_40 ( const char * V_62 , char * * V_97 )
{
const char * V_108 ;
unsigned long long V_107 ;
unsigned long long V_109 ;
enum V_54 type ;
V_108 = V_3 ;
V_107 = V_5 ;
V_109 = V_4 ;
F_1 ( V_62 , strlen ( V_62 ) ) ;
type = F_38 ( V_97 ) ;
V_3 = V_108 ;
V_5 = V_107 ;
V_4 = V_109 ;
return type ;
}
static void F_41 ( char * V_97 )
{
if ( V_97 )
free ( V_97 ) ;
}
static enum V_54 F_42 ( char * * V_97 )
{
enum V_54 type ;
for (; ; ) {
type = F_38 ( V_97 ) ;
if ( type != V_93 )
return type ;
F_41 ( * V_97 ) ;
}
* V_97 = NULL ;
return V_95 ;
}
enum V_54 F_43 ( char * * V_97 )
{
return F_42 ( V_97 ) ;
}
void F_44 ( char * V_110 )
{
F_41 ( V_110 ) ;
}
static enum V_54 F_45 ( char * * V_97 )
{
enum V_54 type ;
for (; ; ) {
type = F_38 ( V_97 ) ;
if ( type != V_93 && type != V_92 )
return type ;
F_41 ( * V_97 ) ;
* V_97 = NULL ;
}
* V_97 = NULL ;
return V_95 ;
}
static int F_46 ( enum V_54 type , enum V_54 V_111 )
{
if ( type != V_111 ) {
F_47 ( L_16 ,
V_111 , type ) ;
return - 1 ;
}
return 0 ;
}
static int F_48 ( enum V_54 type , const char * V_110 ,
enum V_54 V_111 , const char * V_112 )
{
if ( type != V_111 ) {
F_47 ( L_16 ,
V_111 , type ) ;
return - 1 ;
}
if ( strcmp ( V_110 , V_112 ) != 0 ) {
F_47 ( L_17 ,
V_112 , V_110 ) ;
return - 1 ;
}
return 0 ;
}
static int F_49 ( enum V_54 V_111 , char * * V_97 , int V_113 )
{
enum V_54 type ;
if ( V_113 )
type = F_42 ( V_97 ) ;
else
type = F_45 ( V_97 ) ;
return F_46 ( type , V_111 ) ;
}
static int F_50 ( enum V_54 V_111 , char * * V_97 )
{
return F_49 ( V_111 , V_97 , 1 ) ;
}
static int F_51 ( enum V_54 V_111 , const char * V_62 ,
int V_113 )
{
enum V_54 type ;
char * V_110 ;
int V_114 ;
if ( V_113 )
type = F_42 ( & V_110 ) ;
else
type = F_45 ( & V_110 ) ;
V_114 = F_48 ( type , V_110 , V_111 , V_62 ) ;
F_41 ( V_110 ) ;
return V_114 ;
}
static int F_52 ( enum V_54 V_111 , const char * V_62 )
{
return F_51 ( V_111 , V_62 , 1 ) ;
}
static int F_53 ( enum V_54 V_111 , const char * V_62 )
{
return F_51 ( V_111 , V_62 , 0 ) ;
}
static char * F_54 ( void )
{
char * V_110 ;
if ( F_52 ( V_55 , L_18 ) < 0 )
return NULL ;
if ( F_52 ( V_96 , L_19 ) < 0 )
return NULL ;
if ( F_50 ( V_55 , & V_110 ) < 0 )
goto V_115;
return V_110 ;
V_115:
F_41 ( V_110 ) ;
return NULL ;
}
static int F_55 ( void )
{
char * V_110 ;
int V_53 ;
if ( F_53 ( V_55 , L_20 ) < 0 )
return - 1 ;
if ( F_52 ( V_96 , L_19 ) < 0 )
return - 1 ;
if ( F_50 ( V_55 , & V_110 ) < 0 )
goto V_115;
V_53 = strtoul ( V_110 , NULL , 0 ) ;
F_41 ( V_110 ) ;
return V_53 ;
V_115:
F_41 ( V_110 ) ;
return - 1 ;
}
static int F_56 ( struct V_116 * V_68 )
{
if ( ( V_68 -> V_71 & V_117 ) &&
( strstr ( V_68 -> type , L_21 ) || strstr ( V_68 -> type , L_22 ) ||
strstr ( V_68 -> type , L_23 ) ) )
return 1 ;
return 0 ;
}
static int F_57 ( struct V_116 * V_68 )
{
if ( strncmp ( V_68 -> type , L_24 , 10 ) == 0 )
return 1 ;
return 0 ;
}
static int F_58 ( struct V_116 * V_68 )
{
if ( strstr ( V_68 -> type , L_25 ) )
return 1 ;
return 0 ;
}
static unsigned int F_59 ( const char * V_69 )
{
static struct {
const char * type ;
unsigned int V_2 ;
} V_118 [] = {
{ L_22 , 1 } ,
{ L_26 , 2 } ,
{ L_27 , 4 } ,
{ L_28 , 8 } ,
{ L_23 , 1 } ,
{ L_29 , 2 } ,
{ L_30 , 4 } ,
{ L_31 , 8 } ,
{ L_21 , 1 } ,
{ } ,
} ;
int V_19 ;
for ( V_19 = 0 ; V_118 [ V_19 ] . type ; V_19 ++ ) {
if ( ! strcmp ( V_118 [ V_19 ] . type , V_69 ) )
return V_118 [ V_19 ] . V_2 ;
}
return 0 ;
}
static int F_60 ( struct V_49 * V_50 , struct V_116 * * V_119 )
{
struct V_116 * V_68 = NULL ;
enum V_54 type ;
char * V_110 ;
char * V_120 ;
int V_121 = 0 ;
do {
unsigned int V_122 = 0 ;
type = F_42 ( & V_110 ) ;
if ( type == V_92 ) {
F_41 ( V_110 ) ;
return V_121 ;
}
V_121 ++ ;
if ( F_48 ( type , V_110 , V_55 , L_32 ) )
goto V_115;
F_41 ( V_110 ) ;
type = F_42 ( & V_110 ) ;
if ( V_50 -> V_71 & V_123 &&
type == V_55 && strcmp ( V_110 , L_33 ) == 0 ) {
F_41 ( V_110 ) ;
type = F_42 ( & V_110 ) ;
}
if ( F_48 ( type , V_110 , V_96 , L_19 ) < 0 )
goto V_115;
F_41 ( V_110 ) ;
if ( F_50 ( V_55 , & V_110 ) < 0 )
goto V_115;
V_120 = V_110 ;
V_68 = calloc ( 1 , sizeof( * V_68 ) ) ;
if ( ! V_68 )
goto V_115;
V_68 -> V_50 = V_50 ;
for (; ; ) {
type = F_42 ( & V_110 ) ;
if ( type == V_55 ||
( type == V_96 && strcmp ( V_110 , L_34 ) == 0 ) ||
( V_50 -> V_71 & V_123 &&
type == V_96 && strcmp ( V_110 , L_35 ) == 0 ) ) {
if ( strcmp ( V_110 , L_34 ) == 0 )
V_68 -> V_71 |= V_124 ;
if ( V_68 -> type ) {
char * V_125 ;
V_125 = realloc ( V_68 -> type ,
strlen ( V_68 -> type ) +
strlen ( V_120 ) + 2 ) ;
if ( ! V_125 ) {
free ( V_120 ) ;
goto V_115;
}
V_68 -> type = V_125 ;
strcat ( V_68 -> type , L_36 ) ;
strcat ( V_68 -> type , V_120 ) ;
free ( V_120 ) ;
} else
V_68 -> type = V_120 ;
V_120 = V_110 ;
continue;
}
break;
}
if ( ! V_68 -> type ) {
F_61 ( V_50 , L_37 , V_126 ) ;
goto V_115;
}
V_68 -> V_69 = V_120 ;
if ( F_46 ( type , V_96 ) )
goto V_115;
if ( strcmp ( V_110 , L_38 ) == 0 ) {
enum V_54 V_127 = type ;
char * V_128 = V_110 ;
char * V_129 ;
int V_130 ;
V_68 -> V_71 |= V_117 ;
type = F_42 ( & V_110 ) ;
if ( type == V_55 )
V_68 -> V_131 = strtoul ( V_110 , NULL , 0 ) ;
else
V_68 -> V_131 = 0 ;
while ( strcmp ( V_110 , L_39 ) != 0 ) {
if ( V_127 == V_55 &&
type == V_55 )
V_130 = 2 ;
else
V_130 = 1 ;
V_127 = type ;
V_129 = realloc ( V_128 ,
strlen ( V_128 ) +
strlen ( V_110 ) + V_130 ) ;
if ( ! V_129 ) {
free ( V_128 ) ;
goto V_115;
}
V_128 = V_129 ;
if ( V_130 == 2 )
strcat ( V_128 , L_36 ) ;
strcat ( V_128 , V_110 ) ;
V_68 -> V_131 = strtoul ( V_110 , NULL , 0 ) ;
F_41 ( V_110 ) ;
type = F_42 ( & V_110 ) ;
if ( type == V_95 ) {
F_61 ( V_50 , L_40 ) ;
goto V_115;
}
}
F_41 ( V_110 ) ;
V_129 = realloc ( V_128 , strlen ( V_128 ) + 2 ) ;
if ( ! V_129 ) {
free ( V_128 ) ;
goto V_115;
}
V_128 = V_129 ;
strcat ( V_128 , L_39 ) ;
type = F_42 ( & V_110 ) ;
if ( type == V_55 ) {
char * V_125 ;
V_125 = realloc ( V_68 -> type ,
strlen ( V_68 -> type ) +
strlen ( V_68 -> V_69 ) +
strlen ( V_128 ) + 2 ) ;
if ( ! V_125 ) {
free ( V_128 ) ;
goto V_115;
}
V_68 -> type = V_125 ;
strcat ( V_68 -> type , L_36 ) ;
strcat ( V_68 -> type , V_68 -> V_69 ) ;
V_122 = F_59 ( V_68 -> V_69 ) ;
F_41 ( V_68 -> V_69 ) ;
strcat ( V_68 -> type , V_128 ) ;
V_68 -> V_69 = V_110 ;
type = F_42 ( & V_110 ) ;
} else {
char * V_125 ;
V_125 = realloc ( V_68 -> type ,
strlen ( V_68 -> type ) +
strlen ( V_128 ) + 1 ) ;
if ( ! V_125 ) {
free ( V_128 ) ;
goto V_115;
}
V_68 -> type = V_125 ;
strcat ( V_68 -> type , V_128 ) ;
}
free ( V_128 ) ;
}
if ( F_56 ( V_68 ) )
V_68 -> V_71 |= V_132 ;
if ( F_57 ( V_68 ) )
V_68 -> V_71 |= V_133 ;
if ( F_58 ( V_68 ) )
V_68 -> V_71 |= V_134 ;
if ( F_48 ( type , V_110 , V_96 , L_41 ) )
goto V_115;
F_41 ( V_110 ) ;
if ( F_52 ( V_55 , L_42 ) < 0 )
goto V_135;
if ( F_52 ( V_96 , L_19 ) < 0 )
goto V_135;
if ( F_50 ( V_55 , & V_110 ) )
goto V_115;
V_68 -> V_136 = strtoul ( V_110 , NULL , 0 ) ;
F_41 ( V_110 ) ;
if ( F_52 ( V_96 , L_41 ) < 0 )
goto V_135;
if ( F_52 ( V_55 , L_43 ) < 0 )
goto V_135;
if ( F_52 ( V_96 , L_19 ) < 0 )
goto V_135;
if ( F_50 ( V_55 , & V_110 ) )
goto V_115;
V_68 -> V_2 = strtoul ( V_110 , NULL , 0 ) ;
F_41 ( V_110 ) ;
if ( F_52 ( V_96 , L_41 ) < 0 )
goto V_135;
type = F_42 ( & V_110 ) ;
if ( type != V_92 ) {
if ( F_48 ( type , V_110 , V_55 , L_44 ) )
goto V_115;
F_41 ( V_110 ) ;
if ( F_52 ( V_96 , L_19 ) < 0 )
goto V_135;
if ( F_50 ( V_55 , & V_110 ) )
goto V_115;
if ( strtoul ( V_110 , NULL , 0 ) )
V_68 -> V_71 |= V_137 ;
F_41 ( V_110 ) ;
if ( F_52 ( V_96 , L_41 ) < 0 )
goto V_135;
if ( F_50 ( V_92 , & V_110 ) )
goto V_115;
}
F_41 ( V_110 ) ;
if ( V_68 -> V_71 & V_117 ) {
if ( V_68 -> V_131 )
V_68 -> V_138 = V_68 -> V_2 / V_68 -> V_131 ;
else if ( V_68 -> V_71 & V_133 )
V_68 -> V_138 = V_122 ;
else if ( V_68 -> V_71 & V_132 )
V_68 -> V_138 = 1 ;
else if ( V_68 -> V_71 & V_134 )
V_68 -> V_138 = V_50 -> V_14 ?
V_50 -> V_14 -> V_139 :
sizeof( long ) ;
} else
V_68 -> V_138 = V_68 -> V_2 ;
* V_119 = V_68 ;
V_119 = & V_68 -> V_22 ;
} while ( 1 );
return 0 ;
V_115:
F_41 ( V_110 ) ;
V_135:
if ( V_68 ) {
free ( V_68 -> type ) ;
free ( V_68 -> V_69 ) ;
free ( V_68 ) ;
}
return - 1 ;
}
static int F_62 ( struct V_49 * V_50 )
{
char * V_110 ;
int V_114 ;
if ( F_53 ( V_55 , L_45 ) < 0 )
return - 1 ;
if ( F_52 ( V_96 , L_19 ) < 0 )
return - 1 ;
if ( F_50 ( V_92 , & V_110 ) )
goto V_115;
F_41 ( V_110 ) ;
V_114 = F_60 ( V_50 , & V_50 -> V_140 . V_141 ) ;
if ( V_114 < 0 )
return V_114 ;
V_50 -> V_140 . V_142 = V_114 ;
V_114 = F_60 ( V_50 , & V_50 -> V_140 . V_119 ) ;
if ( V_114 < 0 )
return V_114 ;
V_50 -> V_140 . V_143 = V_114 ;
return 0 ;
V_115:
F_41 ( V_110 ) ;
return - 1 ;
}
static enum V_54
F_63 ( struct V_49 * V_50 , struct V_7 * V_63 , char * * V_97 )
{
enum V_54 type ;
char * V_110 ;
type = F_42 ( & V_110 ) ;
* V_97 = V_110 ;
return F_64 ( V_50 , V_63 , V_97 , type ) ;
}
static enum V_54
F_65 ( struct V_49 * V_50 , struct V_7 * V_63 , char * * V_97 )
{
enum V_54 type ;
type = F_63 ( V_50 , V_63 , V_97 ) ;
while ( type == V_96 ) {
type = F_66 ( V_50 , V_63 , V_97 ) ;
}
return type ;
}
static enum V_54
F_67 ( struct V_49 * V_50 , struct V_7 * V_144 , char * * V_97 )
{
struct V_7 * V_63 , * V_87 , * V_88 ;
enum V_54 type ;
char * V_110 = NULL ;
V_63 = F_6 () ;
V_87 = F_6 () ;
V_88 = F_6 () ;
if ( ! V_63 || ! V_87 || ! V_88 ) {
F_61 ( V_50 , L_46 , V_126 ) ;
F_32 ( V_87 ) ;
F_32 ( V_88 ) ;
goto V_38;
}
V_63 -> type = V_85 ;
V_63 -> V_86 . V_87 = V_87 ;
V_63 -> V_86 . V_88 = V_88 ;
* V_97 = NULL ;
type = F_63 ( V_50 , V_87 , & V_110 ) ;
V_145:
if ( type == V_96 && strcmp ( V_110 , L_19 ) != 0 ) {
type = F_66 ( V_50 , V_87 , & V_110 ) ;
goto V_145;
}
if ( F_48 ( type , V_110 , V_96 , L_19 ) )
goto V_38;
V_63 -> V_86 . V_86 = V_110 ;
type = F_63 ( V_50 , V_88 , & V_110 ) ;
V_144 -> V_86 . V_88 = V_63 ;
* V_97 = V_110 ;
return type ;
V_38:
V_144 -> V_86 . V_88 = NULL ;
F_41 ( V_110 ) ;
F_32 ( V_63 ) ;
return V_57 ;
}
static enum V_54
F_68 ( struct V_49 * V_50 , struct V_7 * V_144 , char * * V_97 )
{
struct V_7 * V_63 ;
enum V_54 type ;
char * V_110 = NULL ;
V_63 = F_6 () ;
if ( ! V_63 ) {
F_61 ( V_50 , L_46 , V_126 ) ;
* V_97 = NULL ;
return V_57 ;
}
* V_97 = NULL ;
type = F_63 ( V_50 , V_63 , & V_110 ) ;
if ( F_48 ( type , V_110 , V_96 , L_39 ) )
goto V_38;
V_144 -> V_86 . V_88 = V_63 ;
F_41 ( V_110 ) ;
type = F_45 ( & V_110 ) ;
* V_97 = V_110 ;
return type ;
V_38:
F_41 ( V_110 ) ;
F_32 ( V_63 ) ;
return V_57 ;
}
static int F_69 ( char * V_86 )
{
if ( ! V_86 [ 1 ] ) {
switch ( V_86 [ 0 ] ) {
case '~' :
case '!' :
return 4 ;
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
F_47 ( L_47 , V_86 [ 0 ] ) ;
return - 1 ;
}
} else {
if ( strcmp ( V_86 , L_48 ) == 0 ||
strcmp ( V_86 , L_49 ) == 0 ) {
return 3 ;
} else if ( strcmp ( V_86 , L_50 ) == 0 ||
strcmp ( V_86 , L_51 ) == 0 ) {
return 8 ;
} else if ( strcmp ( V_86 , L_52 ) == 0 ||
strcmp ( V_86 , L_53 ) == 0 ) {
return 9 ;
} else if ( strcmp ( V_86 , L_54 ) == 0 ||
strcmp ( V_86 , L_55 ) == 0 ) {
return 10 ;
} else if ( strcmp ( V_86 , L_56 ) == 0 ) {
return 14 ;
} else if ( strcmp ( V_86 , L_57 ) == 0 ) {
return 15 ;
} else {
F_47 ( L_58 , V_86 ) ;
return - 1 ;
}
}
}
static int F_70 ( struct V_7 * V_63 )
{
if ( ! V_63 -> V_86 . V_87 || V_63 -> V_86 . V_87 -> type == V_90 )
V_63 -> V_86 . V_146 = 0 ;
else
V_63 -> V_86 . V_146 = F_69 ( V_63 -> V_86 . V_86 ) ;
return V_63 -> V_86 . V_146 ;
}
static enum V_54
F_66 ( struct V_49 * V_50 , struct V_7 * V_63 , char * * V_97 )
{
struct V_7 * V_87 , * V_88 = NULL ;
enum V_54 type ;
char * V_110 ;
V_110 = * V_97 ;
if ( V_63 -> type == V_85 && ! V_63 -> V_86 . V_87 ) {
if ( V_110 [ 1 ] ) {
F_61 ( V_50 , L_59 , V_110 ) ;
goto V_38;
}
switch ( V_110 [ 0 ] ) {
case '~' :
case '!' :
case '+' :
case '-' :
break;
default:
F_61 ( V_50 , L_59 , V_110 ) ;
goto V_38;
}
V_87 = F_6 () ;
if ( ! V_87 )
goto V_147;
V_87 -> type = V_90 ;
V_63 -> V_86 . V_87 = V_87 ;
V_88 = F_6 () ;
if ( ! V_88 )
goto V_147;
V_63 -> V_86 . V_88 = V_88 ;
* V_97 = NULL ;
type = F_63 ( V_50 , V_88 , V_97 ) ;
} else if ( strcmp ( V_110 , L_60 ) == 0 ) {
V_87 = F_6 () ;
if ( ! V_87 )
goto V_147;
* V_87 = * V_63 ;
V_63 -> type = V_85 ;
V_63 -> V_86 . V_86 = V_110 ;
V_63 -> V_86 . V_87 = V_87 ;
V_63 -> V_86 . V_146 = 0 ;
type = F_67 ( V_50 , V_63 , V_97 ) ;
} else if ( strcmp ( V_110 , L_50 ) == 0 ||
strcmp ( V_110 , L_51 ) == 0 ||
strcmp ( V_110 , L_61 ) == 0 ||
strcmp ( V_110 , L_62 ) == 0 ||
strcmp ( V_110 , L_56 ) == 0 ||
strcmp ( V_110 , L_57 ) == 0 ||
strcmp ( V_110 , L_63 ) == 0 ||
strcmp ( V_110 , L_64 ) == 0 ||
strcmp ( V_110 , L_34 ) == 0 ||
strcmp ( V_110 , L_65 ) == 0 ||
strcmp ( V_110 , L_66 ) == 0 ||
strcmp ( V_110 , L_67 ) == 0 ||
strcmp ( V_110 , L_68 ) == 0 ||
strcmp ( V_110 , L_53 ) == 0 ||
strcmp ( V_110 , L_52 ) == 0 ||
strcmp ( V_110 , L_54 ) == 0 ||
strcmp ( V_110 , L_55 ) == 0 ) {
V_87 = F_6 () ;
if ( ! V_87 )
goto V_147;
* V_87 = * V_63 ;
V_63 -> type = V_85 ;
V_63 -> V_86 . V_86 = V_110 ;
V_63 -> V_86 . V_87 = V_87 ;
V_63 -> V_86 . V_88 = NULL ;
if ( F_70 ( V_63 ) == - 1 ) {
V_50 -> V_71 |= V_148 ;
V_63 -> V_86 . V_86 = NULL ;
goto V_38;
}
type = F_45 ( & V_110 ) ;
* V_97 = V_110 ;
if ( ( strcmp ( V_63 -> V_86 . V_86 , L_34 ) == 0 ) &&
type == V_58 && ( strcmp ( V_110 , L_69 ) == 0 ) ) {
char * V_149 ;
if ( V_87 -> type != V_65 ) {
F_61 ( V_50 , L_70 ) ;
goto V_38;
}
V_149 = realloc ( V_87 -> V_66 . V_66 ,
strlen ( V_87 -> V_66 . V_66 ) + 3 ) ;
if ( ! V_149 )
goto V_147;
V_87 -> V_66 . V_66 = V_149 ;
strcat ( V_87 -> V_66 . V_66 , L_71 ) ;
free ( V_63 -> V_86 . V_86 ) ;
* V_63 = * V_87 ;
free ( V_87 ) ;
return type ;
}
V_88 = F_6 () ;
if ( ! V_88 )
goto V_147;
type = F_64 ( V_50 , V_88 , V_97 , type ) ;
V_63 -> V_86 . V_88 = V_88 ;
} else if ( strcmp ( V_110 , L_38 ) == 0 ) {
V_87 = F_6 () ;
if ( ! V_87 )
goto V_147;
* V_87 = * V_63 ;
V_63 -> type = V_85 ;
V_63 -> V_86 . V_86 = V_110 ;
V_63 -> V_86 . V_87 = V_87 ;
V_63 -> V_86 . V_146 = 0 ;
type = F_68 ( V_50 , V_63 , V_97 ) ;
} else {
F_61 ( V_50 , L_58 , V_110 ) ;
V_50 -> V_71 |= V_148 ;
goto V_38;
}
if ( type == V_96 && strcmp ( * V_97 , L_19 ) != 0 ) {
int V_146 ;
V_146 = F_69 ( * V_97 ) ;
if ( V_146 > V_63 -> V_86 . V_146 )
return F_66 ( V_50 , V_63 , V_97 ) ;
return F_66 ( V_50 , V_88 , V_97 ) ;
}
return type ;
V_147:
F_61 ( V_50 , L_46 , V_126 ) ;
V_38:
F_41 ( V_110 ) ;
* V_97 = NULL ;
return V_57 ;
}
static enum V_54
F_71 ( struct V_49 * V_50 V_150 , struct V_7 * V_63 ,
char * * V_97 )
{
enum V_54 type ;
char * V_68 ;
char * V_110 ;
if ( F_52 ( V_96 , L_72 ) < 0 )
goto V_151;
if ( F_50 ( V_55 , & V_110 ) < 0 )
goto V_38;
V_68 = V_110 ;
V_63 -> type = V_67 ;
V_63 -> V_68 . V_69 = V_68 ;
if ( V_152 ) {
V_63 -> V_68 . V_68 = F_72 ( V_50 , V_63 -> V_68 . V_69 ) ;
V_63 -> V_68 . V_68 -> V_71 |= V_153 ;
V_152 = 0 ;
} else if ( V_154 ) {
V_63 -> V_68 . V_68 = F_72 ( V_50 , V_63 -> V_68 . V_69 ) ;
V_63 -> V_68 . V_68 -> V_71 |= V_155 ;
V_154 = 0 ;
}
type = F_42 ( & V_110 ) ;
* V_97 = V_110 ;
return type ;
V_38:
F_41 ( V_110 ) ;
V_151:
* V_97 = NULL ;
return V_57 ;
}
static unsigned long long
F_73 ( unsigned long long V_156 , const char * type , int V_157 )
{
int V_158 = 0 ;
char * V_159 ;
int V_130 ;
V_130 = strlen ( type ) ;
if ( V_157 ) {
if ( type [ V_130 - 1 ] != '*' ) {
F_47 ( L_73 ) ;
return V_156 ;
}
V_159 = malloc ( V_130 ) ;
if ( ! V_159 ) {
F_47 ( L_46 , V_126 ) ;
return V_156 ;
}
memcpy ( V_159 , type , V_130 ) ;
V_159 [ V_130 - 2 ] = 0 ;
V_156 = F_73 ( V_156 , V_159 , 0 ) ;
free ( V_159 ) ;
return V_156 ;
}
if ( type [ V_130 - 1 ] == '*' )
return V_156 ;
if ( strncmp ( type , L_74 , 6 ) == 0 )
return V_156 ;
if ( strcmp ( type , L_22 ) == 0 )
return V_156 & 0xff ;
if ( strcmp ( type , L_26 ) == 0 )
return V_156 & 0xffff ;
if ( strcmp ( type , L_27 ) == 0 )
return V_156 & 0xffffffff ;
if ( strcmp ( type , L_28 ) == 0 ||
strcmp ( type , L_31 ) )
return V_156 ;
if ( strcmp ( type , L_23 ) == 0 )
return ( unsigned long long ) ( char ) V_156 & 0xff ;
if ( strcmp ( type , L_29 ) == 0 )
return ( unsigned long long ) ( short ) V_156 & 0xffff ;
if ( strcmp ( type , L_30 ) == 0 )
return ( unsigned long long ) ( int ) V_156 & 0xffffffff ;
if ( strncmp ( type , L_75 , 9 ) == 0 ) {
V_158 = 0 ;
type += 9 ;
}
if ( strcmp ( type , L_21 ) == 0 ) {
if ( V_158 )
return ( unsigned long long ) ( char ) V_156 & 0xff ;
else
return V_156 & 0xff ;
}
if ( strcmp ( type , L_76 ) == 0 ) {
if ( V_158 )
return ( unsigned long long ) ( short ) V_156 & 0xffff ;
else
return V_156 & 0xffff ;
}
if ( strcmp ( type , L_77 ) == 0 ) {
if ( V_158 )
return ( unsigned long long ) ( int ) V_156 & 0xffffffff ;
else
return V_156 & 0xffffffff ;
}
return V_156 ;
}
static unsigned long long
F_74 ( unsigned long long V_156 , struct V_7 * V_63 , int V_157 )
{
if ( V_63 -> type != V_78 ) {
F_47 ( L_78 ) ;
return 0 ;
}
return F_73 ( V_156 , V_63 -> V_79 . type , V_157 ) ;
}
static int F_75 ( struct V_7 * V_63 , long long * V_156 )
{
long long V_87 , V_88 ;
int V_114 = 1 ;
switch ( V_63 -> type ) {
case V_65 :
* V_156 = strtoll ( V_63 -> V_66 . V_66 , NULL , 0 ) ;
break;
case V_78 :
V_114 = F_75 ( V_63 -> V_79 . V_17 , V_156 ) ;
if ( ! V_114 )
break;
* V_156 = F_74 ( * V_156 , V_63 , 0 ) ;
break;
case V_85 :
switch ( V_63 -> V_86 . V_86 [ 0 ] ) {
case '|' :
V_114 = F_75 ( V_63 -> V_86 . V_87 , & V_87 ) ;
if ( ! V_114 )
break;
V_114 = F_75 ( V_63 -> V_86 . V_88 , & V_88 ) ;
if ( ! V_114 )
break;
if ( V_63 -> V_86 . V_86 [ 1 ] )
* V_156 = V_87 || V_88 ;
else
* V_156 = V_87 | V_88 ;
break;
case '&' :
V_114 = F_75 ( V_63 -> V_86 . V_87 , & V_87 ) ;
if ( ! V_114 )
break;
V_114 = F_75 ( V_63 -> V_86 . V_88 , & V_88 ) ;
if ( ! V_114 )
break;
if ( V_63 -> V_86 . V_86 [ 1 ] )
* V_156 = V_87 && V_88 ;
else
* V_156 = V_87 & V_88 ;
break;
case '<' :
V_114 = F_75 ( V_63 -> V_86 . V_87 , & V_87 ) ;
if ( ! V_114 )
break;
V_114 = F_75 ( V_63 -> V_86 . V_88 , & V_88 ) ;
if ( ! V_114 )
break;
switch ( V_63 -> V_86 . V_86 [ 1 ] ) {
case 0 :
* V_156 = V_87 < V_88 ;
break;
case '<' :
* V_156 = V_87 << V_88 ;
break;
case '=' :
* V_156 = V_87 <= V_88 ;
break;
default:
F_47 ( L_58 , V_63 -> V_86 . V_86 ) ;
V_114 = 0 ;
}
break;
case '>' :
V_114 = F_75 ( V_63 -> V_86 . V_87 , & V_87 ) ;
if ( ! V_114 )
break;
V_114 = F_75 ( V_63 -> V_86 . V_88 , & V_88 ) ;
if ( ! V_114 )
break;
switch ( V_63 -> V_86 . V_86 [ 1 ] ) {
case 0 :
* V_156 = V_87 > V_88 ;
break;
case '>' :
* V_156 = V_87 >> V_88 ;
break;
case '=' :
* V_156 = V_87 >= V_88 ;
break;
default:
F_47 ( L_58 , V_63 -> V_86 . V_86 ) ;
V_114 = 0 ;
}
break;
case '=' :
V_114 = F_75 ( V_63 -> V_86 . V_87 , & V_87 ) ;
if ( ! V_114 )
break;
V_114 = F_75 ( V_63 -> V_86 . V_88 , & V_88 ) ;
if ( ! V_114 )
break;
if ( V_63 -> V_86 . V_86 [ 1 ] != '=' ) {
F_47 ( L_58 , V_63 -> V_86 . V_86 ) ;
V_114 = 0 ;
} else
* V_156 = V_87 == V_88 ;
break;
case '!' :
V_114 = F_75 ( V_63 -> V_86 . V_87 , & V_87 ) ;
if ( ! V_114 )
break;
V_114 = F_75 ( V_63 -> V_86 . V_88 , & V_88 ) ;
if ( ! V_114 )
break;
switch ( V_63 -> V_86 . V_86 [ 1 ] ) {
case '=' :
* V_156 = V_87 != V_88 ;
break;
default:
F_47 ( L_58 , V_63 -> V_86 . V_86 ) ;
V_114 = 0 ;
}
break;
case '-' :
if ( V_63 -> V_86 . V_87 -> type == V_90 )
V_87 = 0 ;
else
V_114 = F_75 ( V_63 -> V_86 . V_87 , & V_87 ) ;
if ( ! V_114 )
break;
V_114 = F_75 ( V_63 -> V_86 . V_88 , & V_88 ) ;
if ( ! V_114 )
break;
* V_156 = V_87 - V_88 ;
break;
case '+' :
if ( V_63 -> V_86 . V_87 -> type == V_90 )
V_87 = 0 ;
else
V_114 = F_75 ( V_63 -> V_86 . V_87 , & V_87 ) ;
if ( ! V_114 )
break;
V_114 = F_75 ( V_63 -> V_86 . V_88 , & V_88 ) ;
if ( ! V_114 )
break;
* V_156 = V_87 + V_88 ;
break;
default:
F_47 ( L_58 , V_63 -> V_86 . V_86 ) ;
V_114 = 0 ;
}
break;
case V_90 :
case V_67 ... V_73 :
case V_80 :
case V_81 :
default:
F_47 ( L_79 , V_63 -> type ) ;
V_114 = 0 ;
}
return V_114 ;
}
static char * F_76 ( struct V_7 * V_63 )
{
long long V_156 ;
static char V_1 [ 20 ] ;
switch ( V_63 -> type ) {
case V_65 :
return V_63 -> V_66 . V_66 ;
case V_78 :
return F_76 ( V_63 -> V_79 . V_17 ) ;
case V_85 :
if ( ! F_75 ( V_63 , & V_156 ) )
break;
sprintf ( V_1 , L_80 , V_156 ) ;
return V_1 ;
case V_90 :
case V_67 ... V_73 :
case V_80 :
case V_81 :
default:
F_47 ( L_79 , V_63 -> type ) ;
break;
}
return NULL ;
}
static enum V_54
F_77 ( struct V_49 * V_50 , struct V_59 * * V_160 , char * * V_97 )
{
enum V_54 type ;
struct V_7 * V_63 = NULL ;
struct V_59 * V_68 ;
char * V_110 = * V_97 ;
char * V_61 ;
do {
F_41 ( V_110 ) ;
type = F_45 ( & V_110 ) ;
if ( F_48 ( type , V_110 , V_96 , L_81 ) )
break;
V_63 = F_6 () ;
if ( ! V_63 )
goto V_38;
F_41 ( V_110 ) ;
type = F_63 ( V_50 , V_63 , & V_110 ) ;
if ( type == V_96 )
type = F_66 ( V_50 , V_63 , & V_110 ) ;
if ( type == V_57 )
goto V_38;
if ( F_48 ( type , V_110 , V_58 , L_82 ) )
goto V_38;
V_68 = calloc ( 1 , sizeof( * V_68 ) ) ;
if ( ! V_68 )
goto V_38;
V_61 = F_76 ( V_63 ) ;
if ( V_61 == NULL )
goto V_161;
V_68 -> V_61 = F_12 ( V_61 ) ;
if ( V_68 -> V_61 == NULL )
goto V_161;
F_32 ( V_63 ) ;
V_63 = F_6 () ;
if ( ! V_63 )
goto V_38;
F_41 ( V_110 ) ;
type = F_63 ( V_50 , V_63 , & V_110 ) ;
if ( F_48 ( type , V_110 , V_96 , L_83 ) )
goto V_161;
V_61 = F_76 ( V_63 ) ;
if ( V_61 == NULL )
goto V_161;
V_68 -> V_62 = F_12 ( V_61 ) ;
if ( V_68 -> V_62 == NULL )
goto V_161;
F_32 ( V_63 ) ;
V_63 = NULL ;
* V_160 = V_68 ;
V_160 = & V_68 -> V_22 ;
F_41 ( V_110 ) ;
type = F_45 ( & V_110 ) ;
} while ( type == V_58 && strcmp ( V_110 , L_82 ) == 0 );
* V_97 = V_110 ;
return type ;
V_161:
F_31 ( V_68 ) ;
V_38:
F_32 ( V_63 ) ;
F_41 ( V_110 ) ;
* V_97 = NULL ;
return V_57 ;
}
static enum V_54
F_78 ( struct V_49 * V_50 , struct V_7 * V_63 , char * * V_97 )
{
struct V_7 * V_68 ;
enum V_54 type ;
char * V_110 ;
memset ( V_63 , 0 , sizeof( * V_63 ) ) ;
V_63 -> type = V_70 ;
V_68 = F_6 () ;
if ( ! V_68 ) {
F_61 ( V_50 , L_46 , V_126 ) ;
goto V_38;
}
type = F_65 ( V_50 , V_68 , & V_110 ) ;
while ( type == V_96 )
type = F_66 ( V_50 , V_68 , & V_110 ) ;
if ( F_48 ( type , V_110 , V_58 , L_82 ) )
goto V_161;
F_41 ( V_110 ) ;
V_63 -> V_71 . V_68 = V_68 ;
type = F_45 ( & V_110 ) ;
if ( F_30 ( type ) ) {
V_63 -> V_71 . V_72 = V_110 ;
type = F_45 ( & V_110 ) ;
}
if ( F_48 ( type , V_110 , V_58 , L_82 ) )
goto V_38;
type = F_77 ( V_50 , & V_63 -> V_71 . V_71 , & V_110 ) ;
if ( F_48 ( type , V_110 , V_58 , L_69 ) )
goto V_38;
F_41 ( V_110 ) ;
type = F_45 ( V_97 ) ;
return type ;
V_161:
F_32 ( V_68 ) ;
V_38:
F_41 ( V_110 ) ;
* V_97 = NULL ;
return V_57 ;
}
static enum V_54
F_79 ( struct V_49 * V_50 , struct V_7 * V_63 , char * * V_97 )
{
struct V_7 * V_68 ;
enum V_54 type ;
char * V_110 ;
memset ( V_63 , 0 , sizeof( * V_63 ) ) ;
V_63 -> type = V_73 ;
V_68 = F_6 () ;
if ( ! V_68 ) {
F_61 ( V_50 , L_46 , V_126 ) ;
goto V_38;
}
type = F_65 ( V_50 , V_68 , & V_110 ) ;
if ( F_48 ( type , V_110 , V_58 , L_82 ) )
goto V_161;
V_63 -> V_74 . V_68 = V_68 ;
type = F_77 ( V_50 , & V_63 -> V_74 . V_75 , & V_110 ) ;
if ( F_48 ( type , V_110 , V_58 , L_69 ) )
goto V_38;
F_41 ( V_110 ) ;
type = F_45 ( V_97 ) ;
return type ;
V_161:
F_32 ( V_68 ) ;
V_38:
F_41 ( V_110 ) ;
* V_97 = NULL ;
return V_57 ;
}
static enum V_54
F_80 ( struct V_49 * V_50 , struct V_7 * V_63 , char * * V_97 )
{
struct V_7 * V_68 ;
enum V_54 type ;
char * V_110 ;
memset ( V_63 , 0 , sizeof( * V_63 ) ) ;
V_63 -> type = V_76 ;
V_68 = F_6 () ;
if ( ! V_68 ) {
F_61 ( V_50 , L_46 , V_126 ) ;
goto V_38;
}
type = F_63 ( V_50 , V_68 , & V_110 ) ;
if ( F_48 ( type , V_110 , V_58 , L_82 ) )
goto V_38;
V_63 -> V_77 . V_68 = V_68 ;
F_41 ( V_110 ) ;
V_68 = F_6 () ;
if ( ! V_68 ) {
F_61 ( V_50 , L_46 , V_126 ) ;
* V_97 = NULL ;
return V_57 ;
}
type = F_63 ( V_50 , V_68 , & V_110 ) ;
if ( F_48 ( type , V_110 , V_58 , L_69 ) )
goto V_38;
V_63 -> V_77 . V_2 = V_68 ;
F_41 ( V_110 ) ;
type = F_45 ( V_97 ) ;
return type ;
V_38:
F_32 ( V_68 ) ;
F_41 ( V_110 ) ;
* V_97 = NULL ;
return V_57 ;
}
static enum V_54
F_81 ( struct V_49 * V_50 , struct V_7 * V_63 , char * * V_97 )
{
struct V_116 * V_68 ;
enum V_54 type ;
char * V_110 ;
memset ( V_63 , 0 , sizeof( * V_63 ) ) ;
V_63 -> type = V_82 ;
type = F_42 ( & V_110 ) ;
* V_97 = V_110 ;
if ( type != V_55 )
goto V_38;
V_68 = F_82 ( V_50 , V_110 ) ;
if ( ! V_68 )
goto V_38;
V_63 -> V_83 . V_68 = V_68 ;
V_63 -> V_83 . V_84 = 0 ;
if ( F_52 ( V_58 , L_69 ) < 0 )
goto V_38;
F_41 ( V_110 ) ;
type = F_45 ( & V_110 ) ;
* V_97 = V_110 ;
if ( type != V_96 || strcmp ( V_110 , L_38 ) != 0 )
return type ;
F_41 ( V_110 ) ;
V_63 = F_6 () ;
if ( ! V_63 ) {
F_61 ( V_50 , L_46 , V_126 ) ;
* V_97 = NULL ;
return V_57 ;
}
type = F_63 ( V_50 , V_63 , & V_110 ) ;
if ( type == V_57 )
goto V_162;
if ( ! F_48 ( type , V_110 , V_96 , L_39 ) )
goto V_162;
F_41 ( V_110 ) ;
type = F_45 ( V_97 ) ;
return type ;
V_162:
F_32 ( V_63 ) ;
V_38:
F_41 ( V_110 ) ;
* V_97 = NULL ;
return V_57 ;
}
static enum V_54
F_83 ( struct V_49 * V_50 , struct V_7 * V_63 , char * * V_97 )
{
struct V_7 * V_163 ;
enum V_54 type ;
char * V_110 ;
type = F_63 ( V_50 , V_63 , & V_110 ) ;
if ( type == V_57 )
goto V_38;
if ( type == V_96 )
type = F_66 ( V_50 , V_63 , & V_110 ) ;
if ( type == V_57 )
goto V_38;
if ( F_48 ( type , V_110 , V_58 , L_69 ) )
goto V_38;
F_41 ( V_110 ) ;
type = F_45 ( & V_110 ) ;
if ( F_30 ( type ) ||
( type == V_58 && strcmp ( V_110 , L_84 ) == 0 ) ) {
if ( V_63 -> type != V_65 ) {
F_61 ( V_50 , L_85 ) ;
goto V_38;
}
V_163 = F_6 () ;
if ( ! V_163 ) {
F_61 ( V_50 , L_46 ,
V_126 ) ;
goto V_38;
}
V_63 -> type = V_78 ;
V_63 -> V_79 . type = V_63 -> V_66 . V_66 ;
V_63 -> V_79 . V_17 = V_163 ;
type = F_64 ( V_50 , V_163 , & V_110 , type ) ;
}
* V_97 = V_110 ;
return type ;
V_38:
F_41 ( V_110 ) ;
* V_97 = NULL ;
return V_57 ;
}
static enum V_54
F_84 ( struct V_49 * V_50 V_150 , struct V_7 * V_63 ,
char * * V_97 )
{
enum V_54 type ;
char * V_110 ;
if ( F_50 ( V_55 , & V_110 ) < 0 )
goto V_38;
V_63 -> type = V_80 ;
V_63 -> string . string = V_110 ;
V_63 -> string . V_136 = - 1 ;
if ( F_52 ( V_58 , L_69 ) < 0 )
goto V_151;
type = F_42 ( & V_110 ) ;
* V_97 = V_110 ;
return type ;
V_38:
F_41 ( V_110 ) ;
V_151:
* V_97 = NULL ;
return V_57 ;
}
static struct V_164 *
F_85 ( struct V_14 * V_14 , char * V_165 )
{
struct V_164 * V_35 ;
if ( ! V_14 )
return NULL ;
for ( V_35 = V_14 -> V_166 ; V_35 ; V_35 = V_35 -> V_22 ) {
if ( strcmp ( V_35 -> V_69 , V_165 ) == 0 )
break;
}
return V_35 ;
}
static void F_86 ( struct V_14 * V_14 , char * V_165 )
{
struct V_164 * V_35 ;
struct V_164 * * V_22 ;
V_22 = & V_14 -> V_166 ;
while ( ( V_35 = * V_22 ) ) {
if ( strcmp ( V_35 -> V_69 , V_165 ) == 0 ) {
* V_22 = V_35 -> V_22 ;
F_87 ( V_35 ) ;
break;
}
V_22 = & V_35 -> V_22 ;
}
}
static enum V_54
F_88 ( struct V_49 * V_50 , struct V_164 * V_35 ,
struct V_7 * V_63 , char * * V_97 )
{
struct V_7 * * V_167 ;
struct V_7 * V_64 ;
enum V_54 type ;
char * V_110 ;
int V_19 ;
V_63 -> type = V_89 ;
V_63 -> V_35 . V_35 = V_35 ;
* V_97 = NULL ;
V_167 = & ( V_63 -> V_35 . args ) ;
for ( V_19 = 0 ; V_19 < V_35 -> V_168 ; V_19 ++ ) {
V_64 = F_6 () ;
if ( ! V_64 ) {
F_61 ( V_50 , L_46 ,
V_126 ) ;
return V_57 ;
}
type = F_63 ( V_50 , V_64 , & V_110 ) ;
if ( V_19 < ( V_35 -> V_168 - 1 ) ) {
if ( type != V_58 || strcmp ( V_110 , L_82 ) != 0 ) {
F_61 ( V_50 ,
L_86 ,
V_35 -> V_69 , V_35 -> V_168 ,
V_50 -> V_69 , V_19 + 1 ) ;
goto V_169;
}
} else {
if ( type != V_58 || strcmp ( V_110 , L_69 ) != 0 ) {
F_61 ( V_50 ,
L_87 ,
V_35 -> V_69 , V_35 -> V_168 , V_50 -> V_69 ) ;
goto V_169;
}
}
* V_167 = V_64 ;
V_167 = & ( V_64 -> V_22 ) ;
F_41 ( V_110 ) ;
}
type = F_42 ( & V_110 ) ;
* V_97 = V_110 ;
return type ;
V_169:
F_32 ( V_64 ) ;
F_41 ( V_110 ) ;
return V_57 ;
}
static enum V_54
F_89 ( struct V_49 * V_50 , struct V_7 * V_63 ,
char * V_110 , char * * V_97 )
{
struct V_164 * V_35 ;
if ( strcmp ( V_110 , L_88 ) == 0 ) {
F_41 ( V_110 ) ;
V_152 = 1 ;
return F_78 ( V_50 , V_63 , V_97 ) ;
}
if ( strcmp ( V_110 , L_89 ) == 0 ) {
F_41 ( V_110 ) ;
V_154 = 1 ;
return F_79 ( V_50 , V_63 , V_97 ) ;
}
if ( strcmp ( V_110 , L_90 ) == 0 ) {
F_41 ( V_110 ) ;
return F_80 ( V_50 , V_63 , V_97 ) ;
}
if ( strcmp ( V_110 , L_91 ) == 0 ) {
F_41 ( V_110 ) ;
return F_84 ( V_50 , V_63 , V_97 ) ;
}
if ( strcmp ( V_110 , L_92 ) == 0 ) {
F_41 ( V_110 ) ;
return F_81 ( V_50 , V_63 , V_97 ) ;
}
V_35 = F_85 ( V_50 -> V_14 , V_110 ) ;
if ( V_35 ) {
F_41 ( V_110 ) ;
return F_88 ( V_50 , V_35 , V_63 , V_97 ) ;
}
F_61 ( V_50 , L_93 , V_110 ) ;
F_41 ( V_110 ) ;
return V_57 ;
}
static enum V_54
F_64 ( struct V_49 * V_50 , struct V_7 * V_63 ,
char * * V_97 , enum V_54 type )
{
char * V_110 ;
char * V_66 ;
V_110 = * V_97 ;
switch ( type ) {
case V_55 :
if ( strcmp ( V_110 , L_94 ) == 0 ) {
F_41 ( V_110 ) ;
type = F_71 ( V_50 , V_63 , & V_110 ) ;
break;
}
V_66 = V_110 ;
type = F_45 ( & V_110 ) ;
if ( type == V_58 && strcmp ( V_110 , L_84 ) == 0 ) {
F_41 ( V_110 ) ;
V_110 = NULL ;
type = F_89 ( V_50 , V_63 , V_66 , & V_110 ) ;
break;
}
while ( type == V_55 ) {
char * V_149 ;
V_149 = realloc ( V_66 ,
strlen ( V_66 ) + strlen ( V_110 ) + 2 ) ;
if ( ! V_149 ) {
free ( V_66 ) ;
* V_97 = NULL ;
F_41 ( V_110 ) ;
return V_57 ;
}
V_66 = V_149 ;
strcat ( V_66 , L_36 ) ;
strcat ( V_66 , V_110 ) ;
F_41 ( V_110 ) ;
type = F_45 ( & V_110 ) ;
}
V_63 -> type = V_65 ;
V_63 -> V_66 . V_66 = V_66 ;
break;
case V_94 :
case V_56 :
V_63 -> type = V_65 ;
V_63 -> V_66 . V_66 = V_110 ;
type = F_45 ( & V_110 ) ;
break;
case V_58 :
if ( strcmp ( V_110 , L_84 ) == 0 ) {
F_41 ( V_110 ) ;
type = F_83 ( V_50 , V_63 , & V_110 ) ;
break;
}
case V_96 :
V_63 -> type = V_85 ;
V_63 -> V_86 . V_86 = V_110 ;
V_63 -> V_86 . V_87 = NULL ;
type = F_66 ( V_50 , V_63 , & V_110 ) ;
if ( type == V_57 )
V_63 -> V_86 . V_86 = NULL ;
break;
case V_57 ... V_92 :
default:
F_61 ( V_50 , L_95 , type ) ;
return V_57 ;
}
* V_97 = V_110 ;
return type ;
}
static int F_90 ( struct V_49 * V_50 , struct V_7 * * V_160 )
{
enum V_54 type = V_57 ;
struct V_7 * V_63 ;
char * V_110 ;
int args = 0 ;
do {
if ( type == V_92 ) {
type = F_45 ( & V_110 ) ;
continue;
}
V_63 = F_6 () ;
if ( ! V_63 ) {
F_61 ( V_50 , L_46 ,
V_126 ) ;
return - 1 ;
}
type = F_63 ( V_50 , V_63 , & V_110 ) ;
if ( type == V_57 ) {
F_41 ( V_110 ) ;
F_32 ( V_63 ) ;
return - 1 ;
}
* V_160 = V_63 ;
args ++ ;
if ( type == V_96 ) {
type = F_66 ( V_50 , V_63 , & V_110 ) ;
F_41 ( V_110 ) ;
if ( type == V_57 ) {
* V_160 = NULL ;
F_32 ( V_63 ) ;
return - 1 ;
}
V_160 = & V_63 -> V_22 ;
continue;
}
if ( type == V_58 && strcmp ( V_110 , L_82 ) == 0 ) {
F_41 ( V_110 ) ;
* V_160 = V_63 ;
V_160 = & V_63 -> V_22 ;
continue;
}
break;
} while ( type != V_95 );
if ( type != V_95 && type != V_57 )
F_41 ( V_110 ) ;
return args ;
}
static int F_91 ( struct V_49 * V_50 )
{
enum V_54 type ;
char * V_110 ;
int V_114 ;
if ( F_53 ( V_55 , L_96 ) < 0 )
return - 1 ;
if ( F_52 ( V_55 , L_97 ) < 0 )
return - 1 ;
if ( F_52 ( V_96 , L_19 ) < 0 )
return - 1 ;
if ( F_50 ( V_94 , & V_110 ) < 0 )
goto V_115;
V_106:
V_50 -> V_170 . V_140 = V_110 ;
V_50 -> V_170 . args = NULL ;
type = F_45 ( & V_110 ) ;
if ( type == V_95 )
return 0 ;
if ( type == V_94 ) {
char * V_171 ;
if ( F_39 ( & V_171 , L_98 , V_50 -> V_170 . V_140 , V_110 ) < 0 )
goto V_115;
F_41 ( V_110 ) ;
F_41 ( V_50 -> V_170 . V_140 ) ;
V_50 -> V_170 . V_140 = NULL ;
V_110 = V_171 ;
goto V_106;
}
if ( F_48 ( type , V_110 , V_58 , L_82 ) )
goto V_115;
F_41 ( V_110 ) ;
V_114 = F_90 ( V_50 , & V_50 -> V_170 . args ) ;
if ( V_114 < 0 )
return - 1 ;
return V_114 ;
V_115:
F_41 ( V_110 ) ;
return - 1 ;
}
struct V_116 *
F_92 ( struct V_49 * V_50 , const char * V_69 )
{
struct V_116 * V_140 ;
for ( V_140 = V_50 -> V_140 . V_141 ;
V_140 ; V_140 = V_140 -> V_22 ) {
if ( strcmp ( V_140 -> V_69 , V_69 ) == 0 )
break;
}
return V_140 ;
}
struct V_116 *
F_82 ( struct V_49 * V_50 , const char * V_69 )
{
struct V_116 * V_140 ;
for ( V_140 = V_50 -> V_140 . V_119 ;
V_140 ; V_140 = V_140 -> V_22 ) {
if ( strcmp ( V_140 -> V_69 , V_69 ) == 0 )
break;
}
return V_140 ;
}
struct V_116 *
F_72 ( struct V_49 * V_50 , const char * V_69 )
{
struct V_116 * V_140 ;
V_140 = F_92 ( V_50 , V_69 ) ;
if ( V_140 )
return V_140 ;
return F_82 ( V_50 , V_69 ) ;
}
unsigned long long F_93 ( struct V_14 * V_14 ,
const void * V_172 , int V_2 )
{
switch ( V_2 ) {
case 1 :
return * ( unsigned char * ) V_172 ;
case 2 :
return F_94 ( V_14 , V_172 ) ;
case 4 :
return F_95 ( V_14 , V_172 ) ;
case 8 :
return F_96 ( V_14 , V_172 ) ;
default:
return 0 ;
}
}
int F_97 ( struct V_116 * V_68 , const void * V_173 ,
unsigned long long * V_61 )
{
if ( ! V_68 )
return - 1 ;
switch ( V_68 -> V_2 ) {
case 1 :
case 2 :
case 4 :
case 8 :
* V_61 = F_93 ( V_68 -> V_50 -> V_14 ,
V_173 + V_68 -> V_136 , V_68 -> V_2 ) ;
return 0 ;
default:
return - 1 ;
}
}
static int F_98 ( struct V_14 * V_14 ,
const char * type , int * V_136 , int * V_2 )
{
struct V_49 * V_50 ;
struct V_116 * V_68 ;
if ( ! V_14 -> V_51 ) {
F_47 ( L_99 ) ;
return - 1 ;
}
V_50 = V_14 -> V_51 [ 0 ] ;
V_68 = F_92 ( V_50 , type ) ;
if ( ! V_68 )
return - 1 ;
* V_136 = V_68 -> V_136 ;
* V_2 = V_68 -> V_2 ;
return 0 ;
}
static int F_99 ( struct V_14 * V_14 , void * V_173 ,
int * V_2 , int * V_136 , const char * V_69 )
{
int V_114 ;
if ( ! * V_2 ) {
V_114 = F_98 ( V_14 , V_69 , V_136 , V_2 ) ;
if ( V_114 < 0 )
return V_114 ;
}
return F_93 ( V_14 , V_173 + * V_136 , * V_2 ) ;
}
static int F_100 ( struct V_14 * V_14 , void * V_173 )
{
return F_99 ( V_14 , V_173 ,
& V_14 -> F_59 , & V_14 -> V_174 ,
L_100 ) ;
}
static int F_101 ( struct V_14 * V_14 , void * V_173 )
{
return F_99 ( V_14 , V_173 ,
& V_14 -> V_175 , & V_14 -> V_176 ,
L_101 ) ;
}
static int F_102 ( struct V_14 * V_14 , void * V_173 )
{
return F_99 ( V_14 , V_173 ,
& V_14 -> V_177 , & V_14 -> V_178 ,
L_102 ) ;
}
static int F_103 ( struct V_14 * V_14 , void * V_173 )
{
return F_99 ( V_14 , V_173 ,
& V_14 -> V_179 , & V_14 -> V_180 ,
L_103 ) ;
}
static int F_104 ( struct V_14 * V_14 , void * V_173 )
{
return F_99 ( V_14 , V_173 ,
& V_14 -> V_181 , & V_14 -> V_182 ,
L_104 ) ;
}
static int F_105 ( struct V_14 * V_14 , void * V_173 )
{
return F_99 ( V_14 , V_173 ,
& V_14 -> V_181 , & V_14 -> V_182 ,
L_105 ) ;
}
struct V_49 * F_106 ( struct V_14 * V_14 , int V_53 )
{
struct V_49 * * V_183 ;
struct V_49 V_23 ;
struct V_49 * V_184 = & V_23 ;
if ( V_14 -> V_185 && V_14 -> V_185 -> V_53 == V_53 )
return V_14 -> V_185 ;
V_23 . V_53 = V_53 ;
V_183 = bsearch ( & V_184 , V_14 -> V_51 , V_14 -> V_52 ,
sizeof( * V_14 -> V_51 ) , V_186 ) ;
if ( V_183 ) {
V_14 -> V_185 = * V_183 ;
return * V_183 ;
}
return NULL ;
}
struct V_49 *
F_107 ( struct V_14 * V_14 ,
const char * V_187 , const char * V_69 )
{
struct V_49 * V_50 ;
int V_19 ;
if ( V_14 -> V_185 &&
strcmp ( V_14 -> V_185 -> V_69 , V_69 ) == 0 &&
( ! V_187 || strcmp ( V_14 -> V_185 -> system , V_187 ) == 0 ) )
return V_14 -> V_185 ;
for ( V_19 = 0 ; V_19 < V_14 -> V_52 ; V_19 ++ ) {
V_50 = V_14 -> V_51 [ V_19 ] ;
if ( strcmp ( V_50 -> V_69 , V_69 ) == 0 ) {
if ( ! V_187 )
break;
if ( strcmp ( V_50 -> system , V_187 ) == 0 )
break;
}
}
if ( V_19 == V_14 -> V_52 )
V_50 = NULL ;
V_14 -> V_185 = V_50 ;
return V_50 ;
}
static unsigned long long
F_108 ( void * V_173 , int V_2 , struct V_49 * V_50 , struct V_7 * V_63 )
{
struct V_14 * V_14 = V_50 -> V_14 ;
unsigned long long V_156 = 0 ;
unsigned long long V_87 , V_88 ;
struct V_7 * V_188 = NULL ;
struct V_7 * V_189 ;
unsigned long V_136 ;
unsigned int V_190 ;
switch ( V_63 -> type ) {
case V_90 :
return 0 ;
case V_65 :
return F_109 ( V_63 -> V_66 . V_66 , NULL , 0 ) ;
case V_67 :
if ( ! V_63 -> V_68 . V_68 ) {
V_63 -> V_68 . V_68 = F_72 ( V_50 , V_63 -> V_68 . V_69 ) ;
if ( ! V_63 -> V_68 . V_68 )
goto V_191;
}
V_156 = F_93 ( V_14 , V_173 + V_63 -> V_68 . V_68 -> V_136 ,
V_63 -> V_68 . V_68 -> V_2 ) ;
break;
case V_70 :
case V_73 :
case V_76 :
break;
case V_78 :
V_156 = F_108 ( V_173 , V_2 , V_50 , V_63 -> V_79 . V_17 ) ;
return F_74 ( V_156 , V_63 , 0 ) ;
case V_80 :
case V_81 :
return 0 ;
case V_89 : {
struct V_192 V_193 ;
F_110 ( & V_193 ) ;
V_156 = F_111 ( & V_193 , V_173 , V_2 , V_50 , V_63 ) ;
F_112 ( & V_193 ) ;
return V_156 ;
}
case V_85 :
if ( strcmp ( V_63 -> V_86 . V_86 , L_38 ) == 0 ) {
V_88 = F_108 ( V_173 , V_2 , V_50 , V_63 -> V_86 . V_88 ) ;
V_189 = V_63 -> V_86 . V_87 ;
while ( V_189 -> type == V_78 ) {
if ( ! V_188 )
V_188 = V_189 ;
V_189 = V_189 -> V_79 . V_17 ;
}
V_190 = V_14 -> V_139 ;
switch ( V_189 -> type ) {
case V_82 :
V_136 = F_93 ( V_14 ,
V_173 + V_189 -> V_83 . V_68 -> V_136 ,
V_189 -> V_83 . V_68 -> V_2 ) ;
if ( V_189 -> V_83 . V_68 -> V_138 )
V_190 = V_189 -> V_83 . V_68 -> V_138 ;
V_136 &= 0xffff ;
V_136 += V_88 ;
break;
case V_67 :
if ( ! V_189 -> V_68 . V_68 ) {
V_189 -> V_68 . V_68 =
F_72 ( V_50 , V_189 -> V_68 . V_69 ) ;
if ( ! V_189 -> V_68 . V_68 ) {
V_63 = V_189 ;
goto V_191;
}
}
V_190 = V_189 -> V_68 . V_68 -> V_138 ;
V_136 = V_189 -> V_68 . V_68 -> V_136 +
V_88 * V_189 -> V_68 . V_68 -> V_138 ;
break;
default:
goto V_194;
}
V_156 = F_93 ( V_14 ,
V_173 + V_136 , V_190 ) ;
if ( V_188 )
V_156 = F_74 ( V_156 , V_188 , 1 ) ;
break;
} else if ( strcmp ( V_63 -> V_86 . V_86 , L_60 ) == 0 ) {
V_87 = F_108 ( V_173 , V_2 , V_50 , V_63 -> V_86 . V_87 ) ;
V_63 = V_63 -> V_86 . V_88 ;
if ( V_87 )
V_156 = F_108 ( V_173 , V_2 , V_50 , V_63 -> V_86 . V_87 ) ;
else
V_156 = F_108 ( V_173 , V_2 , V_50 , V_63 -> V_86 . V_88 ) ;
break;
}
V_194:
V_87 = F_108 ( V_173 , V_2 , V_50 , V_63 -> V_86 . V_87 ) ;
V_88 = F_108 ( V_173 , V_2 , V_50 , V_63 -> V_86 . V_88 ) ;
switch ( V_63 -> V_86 . V_86 [ 0 ] ) {
case '!' :
switch ( V_63 -> V_86 . V_86 [ 1 ] ) {
case 0 :
V_156 = ! V_88 ;
break;
case '=' :
V_156 = V_87 != V_88 ;
break;
default:
goto V_195;
}
break;
case '~' :
V_156 = ~ V_88 ;
break;
case '|' :
if ( V_63 -> V_86 . V_86 [ 1 ] )
V_156 = V_87 || V_88 ;
else
V_156 = V_87 | V_88 ;
break;
case '&' :
if ( V_63 -> V_86 . V_86 [ 1 ] )
V_156 = V_87 && V_88 ;
else
V_156 = V_87 & V_88 ;
break;
case '<' :
switch ( V_63 -> V_86 . V_86 [ 1 ] ) {
case 0 :
V_156 = V_87 < V_88 ;
break;
case '<' :
V_156 = V_87 << V_88 ;
break;
case '=' :
V_156 = V_87 <= V_88 ;
break;
default:
goto V_195;
}
break;
case '>' :
switch ( V_63 -> V_86 . V_86 [ 1 ] ) {
case 0 :
V_156 = V_87 > V_88 ;
break;
case '>' :
V_156 = V_87 >> V_88 ;
break;
case '=' :
V_156 = V_87 >= V_88 ;
break;
default:
goto V_195;
}
break;
case '=' :
if ( V_63 -> V_86 . V_86 [ 1 ] != '=' )
goto V_195;
V_156 = V_87 == V_88 ;
break;
case '-' :
V_156 = V_87 - V_88 ;
break;
case '+' :
V_156 = V_87 + V_88 ;
break;
case '/' :
V_156 = V_87 / V_88 ;
break;
case '*' :
V_156 = V_87 * V_88 ;
break;
default:
goto V_195;
}
break;
case V_82 :
V_136 = F_93 ( V_14 ,
V_173 + V_63 -> V_83 . V_68 -> V_136 ,
V_63 -> V_83 . V_68 -> V_2 ) ;
V_136 &= 0xffff ;
V_156 = ( unsigned long long ) ( ( unsigned long ) V_173 + V_136 ) ;
break;
default:
return 0 ;
}
return V_156 ;
V_195:
F_61 ( V_50 , L_106 , V_126 , V_63 -> V_86 . V_86 ) ;
return 0 ;
V_191:
F_61 ( V_50 , L_107 ,
V_126 , V_63 -> V_68 . V_69 ) ;
return 0 ;
}
static unsigned long long F_113 ( const char * V_196 )
{
int V_19 ;
if ( isdigit ( V_196 [ 0 ] ) )
return F_109 ( V_196 , NULL , 0 ) ;
for ( V_19 = 0 ; V_19 < ( int ) ( sizeof( V_71 ) / sizeof( V_71 [ 0 ] ) ) ; V_19 ++ )
if ( strcmp ( V_71 [ V_19 ] . V_69 , V_196 ) == 0 )
return V_71 [ V_19 ] . V_61 ;
return 0 ;
}
static void F_114 ( struct V_192 * V_193 , const char * V_140 ,
int V_197 , const char * V_62 )
{
if ( V_197 >= 0 )
F_115 ( V_193 , V_140 , V_197 , V_62 ) ;
else
F_115 ( V_193 , V_140 , V_62 ) ;
}
static void F_116 ( struct V_192 * V_193 , void * V_173 , int V_2 ,
struct V_49 * V_50 , const char * V_140 ,
int V_197 , struct V_7 * V_63 )
{
struct V_14 * V_14 = V_50 -> V_14 ;
struct V_59 * V_196 ;
struct V_116 * V_68 ;
struct V_40 * V_46 ;
unsigned long long V_156 , V_198 ;
unsigned long V_31 ;
char * V_62 ;
unsigned char * V_77 ;
int V_199 ;
int V_19 , V_130 ;
switch ( V_63 -> type ) {
case V_90 :
return;
case V_65 :
F_114 ( V_193 , V_140 , V_197 , V_63 -> V_66 . V_66 ) ;
return;
case V_67 :
V_68 = V_63 -> V_68 . V_68 ;
if ( ! V_68 ) {
V_68 = F_72 ( V_50 , V_63 -> V_68 . V_69 ) ;
if ( ! V_68 ) {
V_62 = V_63 -> V_68 . V_69 ;
goto V_191;
}
V_63 -> V_68 . V_68 = V_68 ;
}
V_130 = V_68 -> V_2 ? : V_2 - V_68 -> V_136 ;
if ( ! ( V_68 -> V_71 & V_117 ) &&
V_68 -> V_2 == V_14 -> V_139 ) {
V_31 = * ( unsigned long * ) ( V_173 + V_68 -> V_136 ) ;
V_46 = F_25 ( V_14 , V_31 ) ;
if ( V_46 )
F_117 ( V_193 , V_46 -> V_46 ) ;
else
F_115 ( V_193 , L_108 , V_31 ) ;
break;
}
V_62 = malloc ( V_130 + 1 ) ;
if ( ! V_62 ) {
F_61 ( V_50 , L_46 ,
V_126 ) ;
return;
}
memcpy ( V_62 , V_173 + V_68 -> V_136 , V_130 ) ;
V_62 [ V_130 ] = 0 ;
F_114 ( V_193 , V_140 , V_197 , V_62 ) ;
free ( V_62 ) ;
break;
case V_70 :
V_156 = F_108 ( V_173 , V_2 , V_50 , V_63 -> V_71 . V_68 ) ;
V_199 = 0 ;
for ( V_196 = V_63 -> V_71 . V_71 ; V_196 ; V_196 = V_196 -> V_22 ) {
V_198 = F_113 ( V_196 -> V_61 ) ;
if ( ! V_156 && ! V_198 ) {
F_114 ( V_193 , V_140 , V_197 , V_196 -> V_62 ) ;
break;
}
if ( V_198 && ( V_156 & V_198 ) == V_198 ) {
if ( V_199 && V_63 -> V_71 . V_72 )
F_117 ( V_193 , V_63 -> V_71 . V_72 ) ;
F_114 ( V_193 , V_140 , V_197 , V_196 -> V_62 ) ;
V_199 = 1 ;
V_156 &= ~ V_198 ;
}
}
break;
case V_73 :
V_156 = F_108 ( V_173 , V_2 , V_50 , V_63 -> V_74 . V_68 ) ;
for ( V_196 = V_63 -> V_74 . V_75 ; V_196 ; V_196 = V_196 -> V_22 ) {
V_198 = F_113 ( V_196 -> V_61 ) ;
if ( V_156 == V_198 ) {
F_114 ( V_193 , V_140 , V_197 , V_196 -> V_62 ) ;
break;
}
}
break;
case V_76 :
if ( V_63 -> V_77 . V_68 -> type == V_82 ) {
unsigned long V_136 ;
V_136 = F_93 ( V_14 ,
V_173 + V_63 -> V_77 . V_68 -> V_83 . V_68 -> V_136 ,
V_63 -> V_77 . V_68 -> V_83 . V_68 -> V_2 ) ;
V_77 = V_173 + ( V_136 & 0xffff ) ;
} else {
V_68 = V_63 -> V_77 . V_68 -> V_68 . V_68 ;
if ( ! V_68 ) {
V_62 = V_63 -> V_77 . V_68 -> V_68 . V_69 ;
V_68 = F_72 ( V_50 , V_62 ) ;
if ( ! V_68 )
goto V_191;
V_63 -> V_77 . V_68 -> V_68 . V_68 = V_68 ;
}
V_77 = V_173 + V_68 -> V_136 ;
}
V_130 = F_108 ( V_173 , V_2 , V_50 , V_63 -> V_77 . V_2 ) ;
for ( V_19 = 0 ; V_19 < V_130 ; V_19 ++ ) {
if ( V_19 )
F_118 ( V_193 , ' ' ) ;
F_115 ( V_193 , L_109 , V_77 [ V_19 ] ) ;
}
break;
case V_78 :
break;
case V_80 : {
int V_200 ;
if ( V_63 -> string . V_136 == - 1 ) {
struct V_116 * V_201 ;
V_201 = F_72 ( V_50 , V_63 -> string . string ) ;
V_63 -> string . V_136 = V_201 -> V_136 ;
}
V_200 = F_95 ( V_14 , V_173 + V_63 -> string . V_136 ) ;
V_200 &= 0xffff ;
F_114 ( V_193 , V_140 , V_197 , ( ( char * ) V_173 ) + V_200 ) ;
break;
}
case V_81 :
F_114 ( V_193 , V_140 , V_197 , V_63 -> string . string ) ;
break;
case V_85 :
if ( V_63 -> V_86 . V_86 [ 0 ] != '?' )
return;
V_156 = F_108 ( V_173 , V_2 , V_50 , V_63 -> V_86 . V_87 ) ;
if ( V_156 )
F_116 ( V_193 , V_173 , V_2 , V_50 ,
V_140 , V_197 , V_63 -> V_86 . V_88 -> V_86 . V_87 ) ;
else
F_116 ( V_193 , V_173 , V_2 , V_50 ,
V_140 , V_197 , V_63 -> V_86 . V_88 -> V_86 . V_88 ) ;
break;
case V_89 :
F_111 ( V_193 , V_173 , V_2 , V_50 , V_63 ) ;
break;
default:
break;
}
return;
V_191:
F_61 ( V_50 , L_107 ,
V_126 , V_63 -> V_68 . V_69 ) ;
}
static unsigned long long
F_111 ( struct V_192 * V_193 , void * V_173 , int V_2 ,
struct V_49 * V_50 , struct V_7 * V_63 )
{
struct V_164 * V_202 = V_63 -> V_35 . V_35 ;
struct V_203 * V_204 ;
unsigned long long * args ;
unsigned long long V_114 ;
struct V_7 * V_64 ;
struct V_192 V_62 ;
struct V_205 {
struct V_205 * V_22 ;
char * V_62 ;
} * V_206 = NULL , * string ;
int V_19 ;
if ( ! V_202 -> V_168 ) {
V_114 = (* V_202 -> V_35 )( V_193 , NULL ) ;
goto V_105;
}
V_64 = V_63 -> V_35 . args ;
V_204 = V_202 -> V_207 ;
V_114 = V_208 ;
args = malloc ( sizeof( * args ) * V_202 -> V_168 ) ;
if ( ! args )
goto V_105;
for ( V_19 = 0 ; V_19 < V_202 -> V_168 ; V_19 ++ ) {
switch ( V_204 -> type ) {
case V_209 :
case V_210 :
case V_211 :
args [ V_19 ] = F_108 ( V_173 , V_2 , V_50 , V_64 ) ;
break;
case V_212 :
F_110 ( & V_62 ) ;
F_116 ( & V_62 , V_173 , V_2 , V_50 , L_110 , - 1 , V_64 ) ;
F_119 ( & V_62 ) ;
string = malloc ( sizeof( * string ) ) ;
if ( ! string ) {
F_61 ( V_50 , L_111 ,
V_126 , __LINE__ ) ;
goto V_38;
}
string -> V_22 = V_206 ;
string -> V_62 = F_12 ( V_62 . V_213 ) ;
if ( ! string -> V_62 ) {
free ( string ) ;
F_61 ( V_50 , L_111 ,
V_126 , __LINE__ ) ;
goto V_38;
}
args [ V_19 ] = ( V_214 ) string -> V_62 ;
V_206 = string ;
F_112 ( & V_62 ) ;
break;
default:
F_61 ( V_50 , L_112 ) ;
goto V_38;
}
V_64 = V_64 -> V_22 ;
V_204 = V_204 -> V_22 ;
}
V_114 = (* V_202 -> V_35 )( V_193 , args ) ;
V_38:
free ( args ) ;
while ( V_206 ) {
string = V_206 ;
V_206 = string -> V_22 ;
free ( string -> V_62 ) ;
free ( string ) ;
}
V_105:
return V_114 ;
}
static void F_120 ( struct V_7 * args )
{
struct V_7 * V_22 ;
while ( args ) {
V_22 = args -> V_22 ;
F_32 ( args ) ;
args = V_22 ;
}
}
static struct V_7 * F_121 ( char * V_47 , void * V_173 , int V_2 , struct V_49 * V_50 )
{
struct V_14 * V_14 = V_50 -> V_14 ;
struct V_116 * V_68 , * V_215 ;
struct V_7 * args , * V_63 , * * V_22 ;
unsigned long long V_216 , V_156 ;
char * V_172 ;
void * V_217 ;
int V_218 ;
V_68 = V_14 -> V_219 ;
V_215 = V_14 -> V_220 ;
if ( ! V_68 ) {
V_68 = F_82 ( V_50 , L_113 ) ;
if ( ! V_68 ) {
F_61 ( V_50 , L_114 ) ;
return NULL ;
}
V_215 = F_82 ( V_50 , L_115 ) ;
if ( ! V_215 ) {
F_61 ( V_50 , L_116 ) ;
return NULL ;
}
V_14 -> V_219 = V_68 ;
V_14 -> V_220 = V_215 ;
}
V_216 = F_93 ( V_14 , V_173 + V_215 -> V_136 , V_215 -> V_2 ) ;
args = F_6 () ;
if ( ! args ) {
F_61 ( V_50 , L_117 ,
V_126 , __LINE__ ) ;
return NULL ;
}
V_63 = args ;
V_63 -> V_22 = NULL ;
V_22 = & V_63 -> V_22 ;
V_63 -> type = V_65 ;
if ( F_39 ( & V_63 -> V_66 . V_66 , L_80 , V_216 ) < 0 )
goto V_38;
for ( V_172 = V_47 + 5 , V_217 = V_173 + V_68 -> V_136 ;
V_217 < V_173 + V_2 && * V_172 ; V_172 ++ ) {
int V_221 = 0 ;
if ( * V_172 == '%' ) {
V_222:
V_172 ++ ;
switch ( * V_172 ) {
case '%' :
break;
case 'l' :
V_221 ++ ;
goto V_222;
case 'L' :
V_221 = 2 ;
goto V_222;
case '0' ... '9' :
goto V_222;
case '.' :
goto V_222;
case 'p' :
V_221 = 1 ;
case 'd' :
case 'u' :
case 'x' :
case 'i' :
switch ( V_221 ) {
case 0 :
V_218 = 4 ;
break;
case 1 :
V_218 = V_14 -> V_139 ;
break;
case 2 :
V_218 = 8 ;
break;
default:
V_218 = V_221 ;
break;
}
case '*' :
if ( * V_172 == '*' )
V_218 = 4 ;
V_217 = ( void * ) ( ( ( unsigned long ) V_217 + 3 ) &
~ 3 ) ;
V_156 = F_93 ( V_14 , V_217 , V_218 ) ;
V_217 += V_218 ;
V_63 = F_6 () ;
if ( ! V_63 ) {
F_61 ( V_50 , L_117 ,
V_126 , __LINE__ ) ;
goto V_38;
}
V_63 -> V_22 = NULL ;
V_63 -> type = V_65 ;
if ( F_39 ( & V_63 -> V_66 . V_66 , L_80 , V_156 ) < 0 ) {
free ( V_63 ) ;
goto V_38;
}
* V_22 = V_63 ;
V_22 = & V_63 -> V_22 ;
if ( * V_172 == '*' )
goto V_222;
break;
case 's' :
V_63 = F_6 () ;
if ( ! V_63 ) {
F_61 ( V_50 , L_117 ,
V_126 , __LINE__ ) ;
goto V_38;
}
V_63 -> V_22 = NULL ;
V_63 -> type = V_81 ;
V_63 -> string . string = F_12 ( V_217 ) ;
if ( ! V_63 -> string . string )
goto V_38;
V_217 += strlen ( V_217 ) + 1 ;
* V_22 = V_63 ;
V_22 = & V_63 -> V_22 ;
default:
break;
}
}
}
return args ;
V_38:
F_120 ( args ) ;
return NULL ;
}
static char *
F_122 ( void * V_173 , int V_2 V_150 ,
struct V_49 * V_50 )
{
struct V_14 * V_14 = V_50 -> V_14 ;
unsigned long long V_31 ;
struct V_116 * V_68 ;
struct V_40 * V_46 ;
char * V_140 ;
V_68 = V_14 -> V_223 ;
if ( ! V_68 ) {
V_68 = F_82 ( V_50 , L_97 ) ;
if ( ! V_68 ) {
F_61 ( V_50 , L_118 ) ;
return NULL ;
}
V_14 -> V_223 = V_68 ;
}
V_31 = F_93 ( V_14 , V_173 + V_68 -> V_136 , V_68 -> V_2 ) ;
V_46 = F_25 ( V_14 , V_31 ) ;
if ( ! V_46 ) {
if ( F_39 ( & V_140 , L_119 , V_31 ) < 0 )
return NULL ;
return V_140 ;
}
if ( F_39 ( & V_140 , L_120 , L_121 , V_46 -> V_46 ) < 0 )
return NULL ;
return V_140 ;
}
static void F_123 ( struct V_192 * V_193 , int V_224 , void * V_173 , int V_2 ,
struct V_49 * V_50 , struct V_7 * V_63 )
{
unsigned char * V_1 ;
const char * V_47 = L_122 ;
if ( V_63 -> type == V_89 ) {
F_111 ( V_193 , V_173 , V_2 , V_50 , V_63 ) ;
return;
}
if ( V_63 -> type != V_67 ) {
F_115 ( V_193 , L_123 ,
V_63 -> type ) ;
return;
}
if ( V_224 == 'm' )
V_47 = L_124 ;
if ( ! V_63 -> V_68 . V_68 ) {
V_63 -> V_68 . V_68 =
F_72 ( V_50 , V_63 -> V_68 . V_69 ) ;
if ( ! V_63 -> V_68 . V_68 ) {
F_61 ( V_50 , L_107 ,
V_126 , V_63 -> V_68 . V_69 ) ;
return;
}
}
if ( V_63 -> V_68 . V_68 -> V_2 != 6 ) {
F_115 ( V_193 , L_125 ) ;
return;
}
V_1 = V_173 + V_63 -> V_68 . V_68 -> V_136 ;
F_115 ( V_193 , V_47 , V_1 [ 0 ] , V_1 [ 1 ] , V_1 [ 2 ] , V_1 [ 3 ] , V_1 [ 4 ] , V_1 [ 5 ] ) ;
}
static int F_124 ( char * V_48 , unsigned int V_130 )
{
unsigned int V_19 ;
for ( V_19 = 0 ; V_19 < V_130 && V_48 [ V_19 ] ; V_19 ++ )
if ( ! isprint ( V_48 [ V_19 ] ) && ! isspace ( V_48 [ V_19 ] ) )
return 0 ;
return 1 ;
}
static void F_125 ( struct V_192 * V_193 , void * V_173 ,
int V_2 V_150 ,
struct V_49 * V_50 )
{
struct V_116 * V_68 ;
unsigned long long V_156 ;
unsigned int V_136 , V_130 , V_19 ;
V_68 = V_50 -> V_140 . V_119 ;
while ( V_68 ) {
F_115 ( V_193 , L_126 , V_68 -> V_69 ) ;
if ( V_68 -> V_71 & V_117 ) {
V_136 = V_68 -> V_136 ;
V_130 = V_68 -> V_2 ;
if ( V_68 -> V_71 & V_133 ) {
V_156 = F_93 ( V_50 -> V_14 , V_173 + V_136 , V_130 ) ;
V_136 = V_156 ;
V_130 = V_136 >> 16 ;
V_136 &= 0xffff ;
}
if ( V_68 -> V_71 & V_132 &&
F_124 ( V_173 + V_136 , V_130 ) ) {
F_115 ( V_193 , L_110 , ( char * ) V_173 + V_136 ) ;
} else {
F_117 ( V_193 , L_127 ) ;
for ( V_19 = 0 ; V_19 < V_130 ; V_19 ++ ) {
if ( V_19 )
F_117 ( V_193 , L_128 ) ;
F_115 ( V_193 , L_109 ,
* ( ( unsigned char * ) V_173 + V_136 + V_19 ) ) ;
}
F_118 ( V_193 , ']' ) ;
V_68 -> V_71 &= ~ V_132 ;
}
} else {
V_156 = F_93 ( V_50 -> V_14 , V_173 + V_68 -> V_136 ,
V_68 -> V_2 ) ;
if ( V_68 -> V_71 & V_124 ) {
F_115 ( V_193 , L_129 , V_156 ) ;
} else if ( V_68 -> V_71 & V_137 ) {
switch ( V_68 -> V_2 ) {
case 4 :
if ( V_68 -> V_71 & V_134 )
F_115 ( V_193 , L_130 , ( int ) V_156 ) ;
else
F_115 ( V_193 , L_131 , ( int ) V_156 ) ;
break;
case 2 :
F_115 ( V_193 , L_132 , ( short ) V_156 ) ;
break;
case 1 :
F_115 ( V_193 , L_133 , ( char ) V_156 ) ;
break;
default:
F_115 ( V_193 , L_80 , V_156 ) ;
}
} else {
if ( V_68 -> V_71 & V_134 )
F_115 ( V_193 , L_129 , V_156 ) ;
else
F_115 ( V_193 , L_134 , V_156 ) ;
}
}
V_68 = V_68 -> V_22 ;
}
}
static void F_126 ( struct V_192 * V_193 , void * V_173 , int V_2 , struct V_49 * V_50 )
{
struct V_14 * V_14 = V_50 -> V_14 ;
struct V_170 * V_170 = & V_50 -> V_170 ;
struct V_7 * V_63 = V_170 -> args ;
struct V_7 * args = NULL ;
const char * V_172 = V_170 -> V_140 ;
unsigned long long V_156 ;
struct V_28 * V_35 ;
const char * V_225 ;
struct V_192 V_48 ;
char * V_226 = NULL ;
char V_140 [ 32 ] ;
int V_227 ;
int V_228 ;
int V_197 ;
int V_130 ;
int V_221 ;
if ( V_50 -> V_71 & V_148 ) {
F_115 ( V_193 , L_135 ) ;
F_125 ( V_193 , V_173 , V_2 , V_50 ) ;
return;
}
if ( V_50 -> V_71 & V_229 ) {
V_226 = F_122 ( V_173 , V_2 , V_50 ) ;
args = F_121 ( V_226 , V_173 , V_2 , V_50 ) ;
V_63 = args ;
V_172 = V_226 ;
}
for (; * V_172 ; V_172 ++ ) {
V_221 = 0 ;
if ( * V_172 == '\\' ) {
V_172 ++ ;
switch ( * V_172 ) {
case 'n' :
F_118 ( V_193 , '\n' ) ;
break;
case 't' :
F_118 ( V_193 , '\t' ) ;
break;
case 'r' :
F_118 ( V_193 , '\r' ) ;
break;
case '\\' :
F_118 ( V_193 , '\\' ) ;
break;
default:
F_118 ( V_193 , * V_172 ) ;
break;
}
} else if ( * V_172 == '%' ) {
V_225 = V_172 ;
V_227 = 0 ;
V_228 = 0 ;
V_230:
V_172 ++ ;
switch ( * V_172 ) {
case '%' :
F_118 ( V_193 , '%' ) ;
break;
case '#' :
goto V_230;
case 'h' :
V_221 -- ;
goto V_230;
case 'l' :
V_221 ++ ;
goto V_230;
case 'L' :
V_221 = 2 ;
goto V_230;
case '*' :
if ( ! V_63 ) {
F_61 ( V_50 , L_136 ) ;
V_50 -> V_71 |= V_148 ;
goto V_231;
}
V_197 = F_108 ( V_173 , V_2 , V_50 , V_63 ) ;
V_228 = 1 ;
V_63 = V_63 -> V_22 ;
goto V_230;
case '.' :
case 'z' :
case 'Z' :
case '0' ... '9' :
goto V_230;
case 'p' :
if ( V_14 -> V_139 == 4 )
V_221 = 1 ;
else
V_221 = 2 ;
if ( * ( V_172 + 1 ) == 'F' ||
* ( V_172 + 1 ) == 'f' ) {
V_172 ++ ;
V_227 = * V_172 ;
} else if ( * ( V_172 + 1 ) == 'M' || * ( V_172 + 1 ) == 'm' ) {
F_123 ( V_193 , * ( V_172 + 1 ) , V_173 , V_2 , V_50 , V_63 ) ;
V_172 ++ ;
V_63 = V_63 -> V_22 ;
break;
}
case 'd' :
case 'i' :
case 'x' :
case 'X' :
case 'u' :
if ( ! V_63 ) {
F_61 ( V_50 , L_136 ) ;
V_50 -> V_71 |= V_148 ;
goto V_231;
}
V_130 = ( ( unsigned long ) V_172 + 1 ) -
( unsigned long ) V_225 ;
if ( V_130 > 31 ) {
F_61 ( V_50 , L_137 ) ;
V_50 -> V_71 |= V_148 ;
V_130 = 31 ;
}
memcpy ( V_140 , V_225 , V_130 ) ;
V_140 [ V_130 ] = 0 ;
V_156 = F_108 ( V_173 , V_2 , V_50 , V_63 ) ;
V_63 = V_63 -> V_22 ;
if ( V_227 ) {
V_35 = F_18 ( V_14 , V_156 ) ;
if ( V_35 ) {
F_117 ( V_193 , V_35 -> V_35 ) ;
if ( V_227 == 'F' )
F_115 ( V_193 ,
L_138 ,
V_156 - V_35 -> V_31 ) ;
break;
}
}
if ( V_14 -> V_139 == 8 && V_221 &&
sizeof( long ) != 8 ) {
char * V_48 ;
V_221 = 2 ;
V_48 = strchr ( V_140 , 'l' ) ;
if ( V_48 )
memmove ( V_48 + 1 , V_48 , strlen ( V_48 ) + 1 ) ;
else if ( strcmp ( V_140 , L_139 ) == 0 )
strcpy ( V_140 , L_129 ) ;
}
switch ( V_221 ) {
case - 2 :
if ( V_228 )
F_115 ( V_193 , V_140 , V_197 , ( char ) V_156 ) ;
else
F_115 ( V_193 , V_140 , ( char ) V_156 ) ;
break;
case - 1 :
if ( V_228 )
F_115 ( V_193 , V_140 , V_197 , ( short ) V_156 ) ;
else
F_115 ( V_193 , V_140 , ( short ) V_156 ) ;
break;
case 0 :
if ( V_228 )
F_115 ( V_193 , V_140 , V_197 , ( int ) V_156 ) ;
else
F_115 ( V_193 , V_140 , ( int ) V_156 ) ;
break;
case 1 :
if ( V_228 )
F_115 ( V_193 , V_140 , V_197 , ( long ) V_156 ) ;
else
F_115 ( V_193 , V_140 , ( long ) V_156 ) ;
break;
case 2 :
if ( V_228 )
F_115 ( V_193 , V_140 , V_197 ,
( long long ) V_156 ) ;
else
F_115 ( V_193 , V_140 , ( long long ) V_156 ) ;
break;
default:
F_61 ( V_50 , L_140 , V_221 ) ;
V_50 -> V_71 |= V_148 ;
}
break;
case 's' :
if ( ! V_63 ) {
F_61 ( V_50 , L_141 ) ;
V_50 -> V_71 |= V_148 ;
goto V_231;
}
V_130 = ( ( unsigned long ) V_172 + 1 ) -
( unsigned long ) V_225 ;
if ( V_130 > 31 ) {
F_61 ( V_50 , L_137 ) ;
V_50 -> V_71 |= V_148 ;
V_130 = 31 ;
}
memcpy ( V_140 , V_225 , V_130 ) ;
V_140 [ V_130 ] = 0 ;
if ( ! V_228 )
V_197 = - 1 ;
F_110 ( & V_48 ) ;
F_116 ( & V_48 , V_173 , V_2 , V_50 ,
V_140 , V_197 , V_63 ) ;
F_119 ( & V_48 ) ;
F_117 ( V_193 , V_48 . V_213 ) ;
F_112 ( & V_48 ) ;
V_63 = V_63 -> V_22 ;
break;
default:
F_115 ( V_193 , L_142 , * V_172 ) ;
}
} else
F_118 ( V_193 , * V_172 ) ;
}
if ( V_50 -> V_71 & V_148 ) {
V_231:
F_115 ( V_193 , L_135 ) ;
}
if ( args ) {
F_120 ( args ) ;
free ( V_226 ) ;
}
}
void F_127 ( struct V_14 * V_14 ,
struct V_192 * V_193 , struct V_232 * V_233 )
{
static int V_234 = 1 ;
static int V_235 = 1 ;
static int V_236 ;
static int V_237 ;
unsigned int V_238 ;
unsigned int V_239 ;
int V_240 ;
int V_241 ;
int V_242 ;
int V_243 ;
void * V_173 = V_233 -> V_173 ;
V_238 = F_103 ( V_14 , V_173 ) ;
V_239 = F_102 ( V_14 , V_173 ) ;
if ( V_236 )
V_240 = F_104 ( V_14 , V_173 ) ;
else if ( V_234 ) {
V_240 = F_104 ( V_14 , V_173 ) ;
if ( V_240 < 0 )
V_234 = 0 ;
else
V_236 = 1 ;
}
if ( V_237 )
V_241 = F_105 ( V_14 , V_173 ) ;
else if ( V_235 ) {
V_241 = F_105 ( V_14 , V_173 ) ;
if ( V_241 < 0 )
V_235 = 0 ;
else
V_237 = 1 ;
}
V_242 = V_238 & V_244 ;
V_243 = V_238 & V_245 ;
F_115 ( V_193 , L_143 ,
( V_238 & V_246 ) ? 'd' :
( V_238 & V_247 ) ?
'X' : '.' ,
( V_238 & V_248 ) ?
'N' : '.' ,
( V_242 && V_243 ) ? 'H' :
V_242 ? 'h' : V_243 ? 's' : '.' ) ;
if ( V_239 )
F_115 ( V_193 , L_144 , V_239 ) ;
else
F_118 ( V_193 , '.' ) ;
if ( V_237 ) {
if ( V_241 < 0 )
F_118 ( V_193 , '.' ) ;
else
F_115 ( V_193 , L_131 , V_241 ) ;
}
if ( V_236 ) {
if ( V_240 < 0 )
F_118 ( V_193 , '.' ) ;
else
F_115 ( V_193 , L_131 , V_240 ) ;
}
F_119 ( V_193 ) ;
}
int F_128 ( struct V_14 * V_14 , struct V_232 * V_249 )
{
return F_100 ( V_14 , V_249 -> V_173 ) ;
}
struct V_49 * F_129 ( struct V_14 * V_14 , int type )
{
return F_106 ( V_14 , type ) ;
}
int F_130 ( struct V_14 * V_14 , struct V_232 * V_249 )
{
return F_101 ( V_14 , V_249 -> V_173 ) ;
}
const char * F_131 ( struct V_14 * V_14 , int V_13 )
{
const char * V_21 ;
V_21 = F_9 ( V_14 , V_13 ) ;
return V_21 ;
}
void F_132 ( struct V_192 * V_193 , struct V_49 * V_50 ,
struct V_232 * V_233 )
{
int V_250 = 1 ;
if ( V_50 -> V_14 -> V_251 || ( V_50 -> V_71 & V_252 ) )
F_125 ( V_193 , V_233 -> V_173 , V_233 -> V_2 , V_50 ) ;
else {
if ( V_50 -> V_253 && ! ( V_50 -> V_71 & V_254 ) )
V_250 = V_50 -> V_253 ( V_193 , V_233 , V_50 ,
V_50 -> V_255 ) ;
if ( V_250 )
F_126 ( V_193 , V_233 -> V_173 , V_233 -> V_2 , V_50 ) ;
}
F_119 ( V_193 ) ;
}
static bool F_133 ( char * V_27 , bool V_256 )
{
if ( ! V_256 )
return true ;
if ( ! strcmp ( V_27 , L_145 ) || ! strcmp ( V_27 , L_146 )
|| ! strcmp ( V_27 , L_147 ) || ! strcmp ( V_27 , L_148 ) )
return true ;
return false ;
}
void F_134 ( struct V_14 * V_14 , struct V_192 * V_193 ,
struct V_232 * V_233 , bool V_256 )
{
static const char * V_257 = L_149 ;
struct V_49 * V_50 ;
unsigned long V_258 ;
unsigned long V_259 ;
unsigned long V_260 ;
const char * V_21 ;
void * V_173 = V_233 -> V_173 ;
int type ;
int V_13 ;
int V_130 ;
int V_48 ;
bool V_261 ;
V_261 = F_133 ( V_14 -> V_27 ,
V_256 ) ;
if ( V_261 ) {
V_258 = V_233 -> V_262 / V_263 ;
V_260 = V_233 -> V_262 - V_258 * V_263 ;
}
if ( V_233 -> V_2 < 0 ) {
F_47 ( L_150 , V_233 -> V_2 ) ;
return;
}
type = F_100 ( V_14 , V_173 ) ;
V_50 = F_106 ( V_14 , type ) ;
if ( ! V_50 ) {
F_47 ( L_151 , type ) ;
return;
}
V_13 = F_101 ( V_14 , V_173 ) ;
V_21 = F_9 ( V_14 , V_13 ) ;
if ( V_14 -> V_264 ) {
F_115 ( V_193 , L_152 ,
V_21 , V_13 , V_233 -> V_265 ) ;
F_127 ( V_14 , V_193 , V_233 ) ;
} else
F_115 ( V_193 , L_153 , V_21 , V_13 , V_233 -> V_265 ) ;
if ( V_261 ) {
if ( V_14 -> V_71 & V_266 ) {
V_259 = V_260 ;
V_48 = 9 ;
} else {
V_259 = ( V_260 + 500 ) / V_267 ;
V_48 = 6 ;
}
F_115 ( V_193 , L_154 ,
V_258 , V_48 , V_259 , V_50 -> V_69 ) ;
} else
F_115 ( V_193 , L_155 ,
V_233 -> V_262 , V_50 -> V_69 ) ;
V_130 = strlen ( V_50 -> V_69 ) ;
if ( V_130 < 20 )
F_115 ( V_193 , L_156 , 20 - V_130 , V_257 ) ;
F_132 ( V_193 , V_50 , V_233 ) ;
}
static int V_186 ( const void * V_8 , const void * V_9 )
{
struct V_49 * const * V_268 = V_8 ;
struct V_49 * const * V_269 = V_9 ;
if ( ( * V_268 ) -> V_53 < ( * V_269 ) -> V_53 )
return - 1 ;
if ( ( * V_268 ) -> V_53 > ( * V_269 ) -> V_53 )
return 1 ;
return 0 ;
}
static int F_135 ( const void * V_8 , const void * V_9 )
{
struct V_49 * const * V_268 = V_8 ;
struct V_49 * const * V_269 = V_9 ;
int V_270 ;
V_270 = strcmp ( ( * V_268 ) -> V_69 , ( * V_269 ) -> V_69 ) ;
if ( V_270 )
return V_270 ;
V_270 = strcmp ( ( * V_268 ) -> system , ( * V_269 ) -> system ) ;
if ( V_270 )
return V_270 ;
return V_186 ( V_8 , V_9 ) ;
}
static int F_136 ( const void * V_8 , const void * V_9 )
{
struct V_49 * const * V_268 = V_8 ;
struct V_49 * const * V_269 = V_9 ;
int V_270 ;
V_270 = strcmp ( ( * V_268 ) -> system , ( * V_269 ) -> system ) ;
if ( V_270 )
return V_270 ;
V_270 = strcmp ( ( * V_268 ) -> V_69 , ( * V_269 ) -> V_69 ) ;
if ( V_270 )
return V_270 ;
return V_186 ( V_8 , V_9 ) ;
}
struct V_49 * * F_137 ( struct V_14 * V_14 , enum V_271 V_272 )
{
struct V_49 * * V_51 ;
int (* F_138)( const void * V_8 , const void * V_9 );
V_51 = V_14 -> V_273 ;
if ( V_51 && V_14 -> V_127 == V_272 )
return V_51 ;
if ( ! V_51 ) {
V_51 = malloc ( sizeof( * V_51 ) * ( V_14 -> V_52 + 1 ) ) ;
if ( ! V_51 )
return NULL ;
memcpy ( V_51 , V_14 -> V_51 , sizeof( * V_51 ) * V_14 -> V_52 ) ;
V_51 [ V_14 -> V_52 ] = NULL ;
V_14 -> V_273 = V_51 ;
if ( V_272 == V_274 ) {
V_14 -> V_127 = V_272 ;
return V_51 ;
}
}
switch ( V_272 ) {
case V_274 :
F_138 = V_186 ;
break;
case V_275 :
F_138 = F_135 ;
break;
case V_276 :
F_138 = F_136 ;
break;
default:
return V_51 ;
}
qsort ( V_51 , V_14 -> V_52 , sizeof( * V_51 ) , F_138 ) ;
V_14 -> V_127 = V_272 ;
return V_51 ;
}
static struct V_116 * *
F_139 ( const char * type , const char * V_69 ,
int V_121 , struct V_116 * V_160 )
{
struct V_116 * * V_119 ;
struct V_116 * V_68 ;
int V_19 = 0 ;
V_119 = malloc ( sizeof( * V_119 ) * ( V_121 + 1 ) ) ;
if ( ! V_119 )
return NULL ;
for ( V_68 = V_160 ; V_68 ; V_68 = V_68 -> V_22 ) {
V_119 [ V_19 ++ ] = V_68 ;
if ( V_19 == V_121 + 1 ) {
F_47 ( L_157 ,
V_69 , type ) ;
V_19 -- ;
break;
}
}
if ( V_19 != V_121 )
F_47 ( L_158 ,
V_69 , type ) ;
V_119 [ V_19 ] = NULL ;
return V_119 ;
}
struct V_116 * * F_140 ( struct V_49 * V_50 )
{
return F_139 ( L_159 , V_50 -> V_69 ,
V_50 -> V_140 . V_142 ,
V_50 -> V_140 . V_141 ) ;
}
struct V_116 * * F_141 ( struct V_49 * V_50 )
{
return F_139 ( L_160 , V_50 -> V_69 ,
V_50 -> V_140 . V_143 ,
V_50 -> V_140 . V_119 ) ;
}
static void F_142 ( struct V_192 * V_193 , struct V_59 * V_68 )
{
F_115 ( V_193 , L_161 , V_68 -> V_61 , V_68 -> V_62 ) ;
if ( V_68 -> V_22 ) {
F_117 ( V_193 , L_128 ) ;
F_142 ( V_193 , V_68 -> V_22 ) ;
}
}
static void F_143 ( struct V_7 * args )
{
int V_277 = 1 ;
struct V_192 V_193 ;
switch ( args -> type ) {
case V_90 :
printf ( L_162 ) ;
break;
case V_65 :
printf ( L_110 , args -> V_66 . V_66 ) ;
break;
case V_67 :
printf ( L_163 , args -> V_68 . V_69 ) ;
break;
case V_70 :
printf ( L_164 ) ;
F_143 ( args -> V_71 . V_68 ) ;
printf ( L_165 , args -> V_71 . V_72 ) ;
F_110 ( & V_193 ) ;
F_142 ( & V_193 , args -> V_71 . V_71 ) ;
F_144 ( & V_193 ) ;
F_112 ( & V_193 ) ;
printf ( L_69 ) ;
break;
case V_73 :
printf ( L_166 ) ;
F_143 ( args -> V_74 . V_68 ) ;
printf ( L_128 ) ;
F_110 ( & V_193 ) ;
F_142 ( & V_193 , args -> V_74 . V_75 ) ;
F_144 ( & V_193 ) ;
F_112 ( & V_193 ) ;
printf ( L_69 ) ;
break;
case V_76 :
printf ( L_167 ) ;
F_143 ( args -> V_77 . V_68 ) ;
printf ( L_128 ) ;
F_143 ( args -> V_77 . V_2 ) ;
printf ( L_69 ) ;
break;
case V_80 :
case V_81 :
printf ( L_168 , args -> string . string ) ;
break;
case V_78 :
printf ( L_169 , args -> V_79 . type ) ;
F_143 ( args -> V_79 . V_17 ) ;
break;
case V_85 :
if ( strcmp ( args -> V_86 . V_86 , L_19 ) == 0 )
V_277 = 0 ;
if ( V_277 )
printf ( L_84 ) ;
F_143 ( args -> V_86 . V_87 ) ;
printf ( L_170 , args -> V_86 . V_86 ) ;
F_143 ( args -> V_86 . V_88 ) ;
if ( V_277 )
printf ( L_69 ) ;
break;
default:
return;
}
if ( args -> V_22 ) {
printf ( L_6 ) ;
F_143 ( args -> V_22 ) ;
}
}
static void F_145 ( const char * V_68 ,
int * V_136 , int * V_2 , int V_278 )
{
unsigned long long V_107 ;
unsigned long long V_109 ;
char * V_110 ;
int type ;
V_107 = V_5 ;
V_109 = V_4 ;
if ( F_52 ( V_55 , L_32 ) < 0 )
return;
if ( F_52 ( V_96 , L_19 ) < 0 )
return;
if ( F_50 ( V_55 , & V_110 ) < 0 )
goto V_115;
F_41 ( V_110 ) ;
if ( V_278 ) {
if ( F_52 ( V_55 , V_68 ) < 0 )
return;
} else {
if ( F_50 ( V_55 , & V_110 ) < 0 )
goto V_115;
if ( strcmp ( V_110 , V_68 ) != 0 )
goto V_279;
F_41 ( V_110 ) ;
}
if ( F_52 ( V_96 , L_41 ) < 0 )
return;
if ( F_52 ( V_55 , L_42 ) < 0 )
return;
if ( F_52 ( V_96 , L_19 ) < 0 )
return;
if ( F_50 ( V_55 , & V_110 ) < 0 )
goto V_115;
* V_136 = atoi ( V_110 ) ;
F_41 ( V_110 ) ;
if ( F_52 ( V_96 , L_41 ) < 0 )
return;
if ( F_52 ( V_55 , L_43 ) < 0 )
return;
if ( F_52 ( V_96 , L_19 ) < 0 )
return;
if ( F_50 ( V_55 , & V_110 ) < 0 )
goto V_115;
* V_2 = atoi ( V_110 ) ;
F_41 ( V_110 ) ;
if ( F_52 ( V_96 , L_41 ) < 0 )
return;
type = F_42 ( & V_110 ) ;
if ( type != V_92 ) {
if ( type != V_55 )
goto V_115;
if ( strcmp ( V_110 , L_44 ) != 0 )
goto V_115;
F_41 ( V_110 ) ;
if ( F_52 ( V_96 , L_19 ) < 0 )
return;
if ( F_50 ( V_55 , & V_110 ) )
goto V_115;
F_41 ( V_110 ) ;
if ( F_52 ( V_96 , L_41 ) < 0 )
return;
if ( F_50 ( V_92 , & V_110 ) )
goto V_115;
}
V_115:
F_41 ( V_110 ) ;
return;
V_279:
V_5 = V_107 ;
V_4 = V_109 ;
* V_136 = 0 ;
* V_2 = 0 ;
F_41 ( V_110 ) ;
}
int F_146 ( struct V_14 * V_14 , char * V_1 , unsigned long V_2 ,
int V_139 )
{
int V_280 ;
if ( ! V_2 ) {
V_14 -> V_281 = sizeof( long long ) ;
V_14 -> V_282 = V_139 ;
V_14 -> V_283 = sizeof( long long ) + V_139 ;
V_14 -> V_284 = 1 ;
return - 1 ;
}
F_1 ( V_1 , V_2 ) ;
F_145 ( L_171 , & V_14 -> V_285 ,
& V_14 -> V_281 , 1 ) ;
F_145 ( L_172 , & V_14 -> V_286 ,
& V_14 -> V_282 , 1 ) ;
F_145 ( L_173 , & V_14 -> V_287 ,
& V_280 , 0 ) ;
F_145 ( L_174 , & V_14 -> V_283 ,
& V_14 -> V_288 , 1 ) ;
return 0 ;
}
static int F_147 ( struct V_49 * V_50 ,
int V_53 , const char * V_289 ,
const char * V_290 )
{
if ( V_53 >= 0 && V_53 != V_50 -> V_53 )
return 0 ;
if ( V_290 && ( strcmp ( V_290 , V_50 -> V_69 ) != 0 ) )
return 0 ;
if ( V_289 && ( strcmp ( V_289 , V_50 -> system ) != 0 ) )
return 0 ;
return 1 ;
}
static void F_148 ( struct V_291 * V_292 )
{
free ( ( void * ) V_292 -> V_289 ) ;
free ( ( void * ) V_292 -> V_290 ) ;
free ( V_292 ) ;
}
static int F_149 ( struct V_14 * V_14 , struct V_49 * V_50 )
{
struct V_291 * V_292 , * * V_22 ;
for ( V_22 = & V_14 -> V_293 ; * V_22 ;
V_22 = & ( * V_22 ) -> V_22 ) {
V_292 = * V_22 ;
if ( F_147 ( V_50 , V_292 -> V_53 ,
V_292 -> V_289 ,
V_292 -> V_290 ) )
break;
}
if ( ! ( * V_22 ) )
return 0 ;
F_150 ( L_175 ,
V_50 -> V_53 , V_50 -> system , V_50 -> V_69 ) ;
V_50 -> V_253 = V_292 -> V_35 ;
V_50 -> V_255 = V_292 -> V_255 ;
* V_22 = V_292 -> V_22 ;
F_148 ( V_292 ) ;
return 1 ;
}
enum V_294 F_151 ( struct V_49 * * V_295 ,
struct V_14 * V_14 , const char * V_1 ,
unsigned long V_2 , const char * V_187 )
{
struct V_49 * V_50 ;
int V_114 ;
F_1 ( V_1 , V_2 ) ;
* V_295 = V_50 = F_28 () ;
if ( ! V_50 )
return V_296 ;
V_50 -> V_69 = F_54 () ;
if ( ! V_50 -> V_69 ) {
V_114 = V_296 ;
goto V_297;
}
if ( strcmp ( V_187 , L_176 ) == 0 ) {
V_50 -> V_71 |= V_123 ;
if ( strcmp ( V_50 -> V_69 , L_177 ) == 0 )
V_50 -> V_71 |= V_229 ;
}
V_50 -> V_53 = F_55 () ;
if ( V_50 -> V_53 < 0 ) {
V_114 = V_298 ;
goto V_297;
}
V_50 -> system = F_12 ( V_187 ) ;
if ( ! V_50 -> system ) {
V_114 = V_296 ;
goto V_297;
}
V_50 -> V_14 = V_14 ;
V_114 = F_62 ( V_50 ) ;
if ( V_114 < 0 ) {
V_114 = V_299 ;
goto V_300;
}
if ( V_14 && F_149 ( V_14 , V_50 ) )
V_301 = 0 ;
V_114 = F_91 ( V_50 ) ;
V_301 = 1 ;
if ( V_114 < 0 ) {
V_114 = V_302 ;
goto V_300;
}
if ( ! V_114 && ( V_50 -> V_71 & V_123 ) ) {
struct V_116 * V_68 ;
struct V_7 * V_63 , * * V_160 ;
V_160 = & V_50 -> V_170 . args ;
for ( V_68 = V_50 -> V_140 . V_119 ; V_68 ; V_68 = V_68 -> V_22 ) {
V_63 = F_6 () ;
if ( ! V_63 ) {
V_50 -> V_71 |= V_148 ;
return V_303 ;
}
V_63 -> type = V_67 ;
V_63 -> V_68 . V_69 = F_12 ( V_68 -> V_69 ) ;
if ( ! V_63 -> V_68 . V_69 ) {
V_50 -> V_71 |= V_148 ;
F_32 ( V_63 ) ;
return V_303 ;
}
V_63 -> V_68 . V_68 = V_68 ;
* V_160 = V_63 ;
V_160 = & V_63 -> V_22 ;
}
return 0 ;
}
return 0 ;
V_300:
V_50 -> V_71 |= V_148 ;
return V_114 ;
V_297:
free ( V_50 -> system ) ;
free ( V_50 -> V_69 ) ;
free ( V_50 ) ;
* V_295 = NULL ;
return V_114 ;
}
static enum V_294
F_152 ( struct V_14 * V_14 ,
struct V_49 * * V_295 ,
const char * V_1 , unsigned long V_2 ,
const char * V_187 )
{
int V_114 = F_151 ( V_295 , V_14 , V_1 , V_2 , V_187 ) ;
struct V_49 * V_50 = * V_295 ;
if ( V_50 == NULL )
return V_114 ;
if ( V_14 && F_29 ( V_14 , V_50 ) ) {
V_114 = V_296 ;
goto V_304;
}
#define F_153 0
if ( F_153 && V_50 -> V_170 . args )
F_143 ( V_50 -> V_170 . args ) ;
return 0 ;
V_304:
F_154 ( V_50 ) ;
return V_114 ;
}
enum V_294 F_155 ( struct V_14 * V_14 ,
struct V_49 * * V_295 ,
const char * V_1 ,
unsigned long V_2 , const char * V_187 )
{
return F_152 ( V_14 , V_295 , V_1 , V_2 , V_187 ) ;
}
enum V_294 F_156 ( struct V_14 * V_14 , const char * V_1 ,
unsigned long V_2 , const char * V_187 )
{
struct V_49 * V_50 = NULL ;
return F_152 ( V_14 , & V_50 , V_1 , V_2 , V_187 ) ;
}
int F_157 ( struct V_14 * V_14 V_150 ,
enum V_294 V_305 , char * V_1 , T_1 V_306 )
{
int V_307 ;
const char * V_308 ;
if ( V_305 >= 0 ) {
V_308 = F_158 ( V_305 , V_1 , V_306 ) ;
if ( V_308 != V_1 ) {
T_1 V_130 = strlen ( V_308 ) ;
memcpy ( V_1 , V_308 , F_159 ( V_306 - 1 , V_130 ) ) ;
* ( V_1 + F_159 ( V_306 - 1 , V_130 ) ) = '\0' ;
}
return 0 ;
}
if ( V_305 <= V_309 ||
V_305 >= V_310 )
return - 1 ;
V_307 = V_305 - V_309 - 1 ;
V_308 = V_311 [ V_307 ] ;
snprintf ( V_1 , V_306 , L_110 , V_308 ) ;
return 0 ;
}
int F_160 ( struct V_192 * V_193 , struct V_116 * V_68 ,
const char * V_69 , struct V_232 * V_233 ,
unsigned long long * V_156 , int V_169 )
{
if ( ! V_68 ) {
if ( V_169 )
F_115 ( V_193 , L_178 , V_69 ) ;
return - 1 ;
}
if ( F_97 ( V_68 , V_233 -> V_173 , V_156 ) ) {
if ( V_169 )
F_115 ( V_193 , L_179 , V_69 ) ;
return - 1 ;
}
return 0 ;
}
void * F_161 ( struct V_192 * V_193 , struct V_49 * V_50 ,
const char * V_69 , struct V_232 * V_233 ,
int * V_130 , int V_169 )
{
struct V_116 * V_68 ;
void * V_173 = V_233 -> V_173 ;
unsigned V_136 ;
int V_312 ;
if ( ! V_50 )
return NULL ;
V_68 = F_82 ( V_50 , V_69 ) ;
if ( ! V_68 ) {
if ( V_169 )
F_115 ( V_193 , L_178 , V_69 ) ;
return NULL ;
}
if ( ! V_130 )
V_130 = & V_312 ;
V_136 = V_68 -> V_136 ;
if ( V_68 -> V_71 & V_133 ) {
V_136 = F_93 ( V_50 -> V_14 ,
V_173 + V_136 , V_68 -> V_2 ) ;
* V_130 = V_136 >> 16 ;
V_136 &= 0xffff ;
} else
* V_130 = V_68 -> V_2 ;
return V_173 + V_136 ;
}
int F_162 ( struct V_192 * V_193 , struct V_49 * V_50 ,
const char * V_69 , struct V_232 * V_233 ,
unsigned long long * V_156 , int V_169 )
{
struct V_116 * V_68 ;
if ( ! V_50 )
return - 1 ;
V_68 = F_82 ( V_50 , V_69 ) ;
return F_160 ( V_193 , V_68 , V_69 , V_233 , V_156 , V_169 ) ;
}
int F_163 ( struct V_192 * V_193 , struct V_49 * V_50 ,
const char * V_69 , struct V_232 * V_233 ,
unsigned long long * V_156 , int V_169 )
{
struct V_116 * V_68 ;
if ( ! V_50 )
return - 1 ;
V_68 = F_92 ( V_50 , V_69 ) ;
return F_160 ( V_193 , V_68 , V_69 , V_233 , V_156 , V_169 ) ;
}
int F_164 ( struct V_192 * V_193 , struct V_49 * V_50 ,
const char * V_69 , struct V_232 * V_233 ,
unsigned long long * V_156 , int V_169 )
{
struct V_116 * V_68 ;
if ( ! V_50 )
return - 1 ;
V_68 = F_72 ( V_50 , V_69 ) ;
return F_160 ( V_193 , V_68 , V_69 , V_233 , V_156 , V_169 ) ;
}
int F_165 ( struct V_192 * V_193 , const char * V_47 ,
struct V_49 * V_50 , const char * V_69 ,
struct V_232 * V_233 , int V_169 )
{
struct V_116 * V_68 = F_82 ( V_50 , V_69 ) ;
unsigned long long V_156 ;
if ( ! V_68 )
goto V_313;
if ( F_97 ( V_68 , V_233 -> V_173 , & V_156 ) )
goto V_313;
return F_115 ( V_193 , V_47 , V_156 ) ;
V_313:
if ( V_169 )
F_115 ( V_193 , L_180 , V_69 ) ;
return - 1 ;
}
int F_166 ( struct V_192 * V_193 , const char * V_47 ,
struct V_49 * V_50 , const char * V_69 ,
struct V_232 * V_233 , int V_169 )
{
struct V_116 * V_68 = F_82 ( V_50 , V_69 ) ;
struct V_14 * V_14 = V_50 -> V_14 ;
unsigned long long V_156 ;
struct V_28 * V_35 ;
char V_314 [ 128 ] ;
if ( ! V_68 )
goto V_313;
if ( F_97 ( V_68 , V_233 -> V_173 , & V_156 ) )
goto V_313;
V_35 = F_18 ( V_14 , V_156 ) ;
if ( V_35 )
snprintf ( V_314 , 128 , L_181 , V_35 -> V_35 , V_35 -> V_31 - V_156 ) ;
else
sprintf ( V_314 , L_182 , V_156 ) ;
return F_115 ( V_193 , V_47 , V_314 ) ;
V_313:
if ( V_169 )
F_115 ( V_193 , L_180 , V_69 ) ;
return - 1 ;
}
static void F_87 ( struct V_164 * V_35 )
{
struct V_203 * V_207 ;
free ( V_35 -> V_69 ) ;
while ( V_35 -> V_207 ) {
V_207 = V_35 -> V_207 ;
V_35 -> V_207 = V_207 -> V_22 ;
free ( V_207 ) ;
}
free ( V_35 ) ;
}
int F_167 ( struct V_14 * V_14 ,
T_2 V_35 ,
enum V_315 V_316 ,
char * V_69 , ... )
{
struct V_164 * V_202 ;
struct V_203 * * V_317 ;
struct V_203 * V_204 ;
enum V_315 type ;
T_3 V_318 ;
int V_114 ;
V_202 = F_85 ( V_14 , V_69 ) ;
if ( V_202 ) {
F_150 ( L_183 , V_69 ) ;
F_86 ( V_14 , V_69 ) ;
}
V_202 = calloc ( 1 , sizeof( * V_202 ) ) ;
if ( ! V_202 ) {
F_47 ( L_184 ) ;
return V_296 ;
}
V_202 -> V_316 = V_316 ;
V_202 -> V_69 = F_12 ( V_69 ) ;
V_202 -> V_35 = V_35 ;
if ( ! V_202 -> V_69 ) {
F_47 ( L_185 ) ;
free ( V_202 ) ;
return V_296 ;
}
V_317 = & ( V_202 -> V_207 ) ;
va_start ( V_318 , V_69 ) ;
for (; ; ) {
type = va_arg ( V_318 , enum V_315 ) ;
if ( type == V_319 )
break;
if ( type >= V_320 ) {
F_47 ( L_186 , type ) ;
V_114 = V_321 ;
goto V_38;
}
V_204 = malloc ( sizeof( * V_204 ) ) ;
if ( ! V_204 ) {
F_47 ( L_187 ) ;
V_114 = V_296 ;
goto V_38;
}
V_204 -> type = type ;
V_204 -> V_22 = NULL ;
* V_317 = V_204 ;
V_317 = & ( V_204 -> V_22 ) ;
V_202 -> V_168 ++ ;
}
va_end ( V_318 ) ;
V_202 -> V_22 = V_14 -> V_166 ;
V_14 -> V_166 = V_202 ;
return 0 ;
V_38:
va_end ( V_318 ) ;
F_87 ( V_202 ) ;
return V_114 ;
}
int F_168 ( struct V_14 * V_14 ,
T_2 V_35 , char * V_69 )
{
struct V_164 * V_202 ;
V_202 = F_85 ( V_14 , V_69 ) ;
if ( V_202 && V_202 -> V_35 == V_35 ) {
F_86 ( V_14 , V_69 ) ;
return 0 ;
}
return - 1 ;
}
static struct V_49 * F_169 ( struct V_14 * V_14 , int V_53 ,
const char * V_289 ,
const char * V_290 )
{
struct V_49 * V_50 ;
if ( V_53 >= 0 ) {
V_50 = F_106 ( V_14 , V_53 ) ;
if ( ! V_50 )
return NULL ;
if ( V_290 && ( strcmp ( V_290 , V_50 -> V_69 ) != 0 ) )
return NULL ;
if ( V_289 && ( strcmp ( V_289 , V_50 -> system ) != 0 ) )
return NULL ;
} else {
V_50 = F_107 ( V_14 , V_289 , V_290 ) ;
if ( ! V_50 )
return NULL ;
}
return V_50 ;
}
int F_170 ( struct V_14 * V_14 , int V_53 ,
const char * V_289 , const char * V_290 ,
T_4 V_35 , void * V_255 )
{
struct V_49 * V_50 ;
struct V_291 * V_292 ;
V_50 = F_169 ( V_14 , V_53 , V_289 , V_290 ) ;
if ( V_50 == NULL )
goto V_322;
F_150 ( L_175 ,
V_50 -> V_53 , V_50 -> system , V_50 -> V_69 ) ;
V_50 -> V_253 = V_35 ;
V_50 -> V_255 = V_255 ;
return 0 ;
V_322:
V_292 = calloc ( 1 , sizeof( * V_292 ) ) ;
if ( ! V_292 ) {
F_47 ( L_188 ) ;
return V_296 ;
}
V_292 -> V_53 = V_53 ;
if ( V_290 )
V_292 -> V_290 = F_12 ( V_290 ) ;
if ( V_289 )
V_292 -> V_289 = F_12 ( V_289 ) ;
if ( ( V_290 && ! V_292 -> V_290 ) ||
( V_289 && ! V_292 -> V_289 ) ) {
F_47 ( L_189 ) ;
free ( ( void * ) V_292 -> V_290 ) ;
free ( ( void * ) V_292 -> V_289 ) ;
free ( V_292 ) ;
return V_296 ;
}
V_292 -> V_35 = V_35 ;
V_292 -> V_22 = V_14 -> V_293 ;
V_14 -> V_293 = V_292 ;
V_292 -> V_255 = V_255 ;
return - 1 ;
}
static int F_171 ( struct V_291 * V_253 , int V_53 ,
const char * V_289 , const char * V_290 ,
T_4 V_35 , void * V_255 )
{
if ( V_53 >= 0 && V_53 != V_253 -> V_53 )
return 0 ;
if ( V_290 && ( strcmp ( V_290 , V_253 -> V_290 ) != 0 ) )
return 0 ;
if ( V_289 && ( strcmp ( V_289 , V_253 -> V_289 ) != 0 ) )
return 0 ;
if ( V_35 != V_253 -> V_35 || V_255 != V_253 -> V_255 )
return 0 ;
return 1 ;
}
int F_172 ( struct V_14 * V_14 , int V_53 ,
const char * V_289 , const char * V_290 ,
T_4 V_35 , void * V_255 )
{
struct V_49 * V_50 ;
struct V_291 * V_292 ;
struct V_291 * * V_22 ;
V_50 = F_169 ( V_14 , V_53 , V_289 , V_290 ) ;
if ( V_50 == NULL )
goto V_322;
if ( V_50 -> V_253 == V_35 && V_50 -> V_255 == V_255 ) {
F_150 ( L_190 ,
V_50 -> V_53 , V_50 -> system , V_50 -> V_69 ) ;
V_50 -> V_253 = NULL ;
V_50 -> V_255 = NULL ;
return 0 ;
}
V_322:
for ( V_22 = & V_14 -> V_293 ; * V_22 ; V_22 = & ( * V_22 ) -> V_22 ) {
V_292 = * V_22 ;
if ( F_171 ( V_292 , V_53 , V_289 , V_290 ,
V_35 , V_255 ) )
break;
}
if ( ! ( * V_22 ) )
return - 1 ;
* V_22 = V_292 -> V_22 ;
F_148 ( V_292 ) ;
return 0 ;
}
struct V_14 * F_173 ( void )
{
struct V_14 * V_14 = calloc ( 1 , sizeof( * V_14 ) ) ;
if ( V_14 )
V_14 -> V_323 = 1 ;
return V_14 ;
}
void F_174 ( struct V_14 * V_14 )
{
V_14 -> V_323 ++ ;
}
static void F_175 ( struct V_116 * V_68 )
{
struct V_116 * V_22 ;
while ( V_68 ) {
V_22 = V_68 -> V_22 ;
free ( V_68 -> type ) ;
free ( V_68 -> V_69 ) ;
free ( V_68 ) ;
V_68 = V_22 ;
}
}
static void F_176 ( struct V_140 * V_140 )
{
F_175 ( V_140 -> V_141 ) ;
F_175 ( V_140 -> V_119 ) ;
}
void F_154 ( struct V_49 * V_50 )
{
free ( V_50 -> V_69 ) ;
free ( V_50 -> system ) ;
F_176 ( & V_50 -> V_140 ) ;
free ( V_50 -> V_170 . V_140 ) ;
F_120 ( V_50 -> V_170 . args ) ;
free ( V_50 ) ;
}
void F_177 ( struct V_14 * V_14 )
{
struct V_15 * V_16 , * V_324 ;
struct V_32 * V_33 , * V_325 ;
struct V_43 * V_44 , * V_326 ;
struct V_164 * V_327 ;
struct V_291 * V_292 ;
int V_19 ;
if ( ! V_14 )
return;
V_16 = V_14 -> V_16 ;
V_33 = V_14 -> V_33 ;
V_44 = V_14 -> V_44 ;
V_14 -> V_323 -- ;
if ( V_14 -> V_323 )
return;
if ( V_14 -> V_18 ) {
for ( V_19 = 0 ; V_19 < V_14 -> V_20 ; V_19 ++ )
free ( V_14 -> V_18 [ V_19 ] . V_21 ) ;
free ( V_14 -> V_18 ) ;
}
while ( V_16 ) {
V_324 = V_16 -> V_22 ;
free ( V_16 -> V_21 ) ;
free ( V_16 ) ;
V_16 = V_324 ;
}
if ( V_14 -> V_28 ) {
for ( V_19 = 0 ; V_19 < ( int ) V_14 -> V_34 ; V_19 ++ ) {
free ( V_14 -> V_28 [ V_19 ] . V_35 ) ;
free ( V_14 -> V_28 [ V_19 ] . V_36 ) ;
}
free ( V_14 -> V_28 ) ;
}
while ( V_33 ) {
V_325 = V_33 -> V_22 ;
free ( V_33 -> V_35 ) ;
free ( V_33 -> V_36 ) ;
free ( V_33 ) ;
V_33 = V_325 ;
}
while ( V_14 -> V_166 ) {
V_327 = V_14 -> V_166 ;
V_14 -> V_166 = V_327 -> V_22 ;
F_87 ( V_327 ) ;
}
if ( V_14 -> V_40 ) {
for ( V_19 = 0 ; V_19 < ( int ) V_14 -> V_45 ; V_19 ++ )
free ( V_14 -> V_40 [ V_19 ] . V_46 ) ;
free ( V_14 -> V_40 ) ;
}
while ( V_44 ) {
V_326 = V_44 -> V_22 ;
free ( V_44 -> V_46 ) ;
free ( V_44 ) ;
V_44 = V_326 ;
}
for ( V_19 = 0 ; V_19 < V_14 -> V_52 ; V_19 ++ )
F_154 ( V_14 -> V_51 [ V_19 ] ) ;
while ( V_14 -> V_293 ) {
V_292 = V_14 -> V_293 ;
V_14 -> V_293 = V_292 -> V_22 ;
F_148 ( V_292 ) ;
}
free ( V_14 -> V_51 ) ;
free ( V_14 -> V_273 ) ;
free ( V_14 ) ;
}
void F_178 ( struct V_14 * V_14 )
{
F_177 ( V_14 ) ;
}
