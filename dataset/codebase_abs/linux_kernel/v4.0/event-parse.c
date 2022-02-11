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
free ( V_63 -> V_83 . V_83 ) ;
break;
case V_84 :
free ( V_63 -> V_85 . V_86 ) ;
break;
case V_87 :
free ( V_63 -> V_88 . V_88 ) ;
F_32 ( V_63 -> V_88 . V_89 ) ;
F_32 ( V_63 -> V_88 . V_90 ) ;
break;
case V_91 :
while ( V_63 -> V_35 . args ) {
V_64 = V_63 -> V_35 . args ;
V_63 -> V_35 . args = V_64 -> V_22 ;
F_32 ( V_64 ) ;
}
break;
case V_92 :
default:
break;
}
free ( V_63 ) ;
}
static enum V_54 F_33 ( int V_93 )
{
if ( V_93 == '\n' )
return V_94 ;
if ( isspace ( V_93 ) )
return V_95 ;
if ( isalnum ( V_93 ) || V_93 == '_' )
return V_55 ;
if ( V_93 == '\'' )
return V_56 ;
if ( V_93 == '"' )
return V_96 ;
if ( ! isprint ( V_93 ) )
return V_97 ;
if ( V_93 == '(' || V_93 == ')' || V_93 == ',' )
return V_58 ;
return V_98 ;
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
static int F_37 ( char * * V_99 , char * V_1 , int V_2 )
{
char * V_100 = realloc ( * V_99 , V_2 ) ;
if ( ! V_100 ) {
free ( * V_99 ) ;
* V_99 = NULL ;
return - 1 ;
}
if ( ! * V_99 )
strcpy ( V_100 , V_1 ) ;
else
strcat ( V_100 , V_1 ) ;
* V_99 = V_100 ;
return 0 ;
}
static enum V_54 F_38 ( char * * V_99 )
{
char V_1 [ V_101 ] ;
int V_93 , V_102 , V_103 , V_104 ;
int V_19 = 0 ;
int V_105 = 0 ;
enum V_54 type ;
* V_99 = NULL ;
V_93 = F_34 () ;
if ( V_93 < 0 )
return V_97 ;
type = F_33 ( V_93 ) ;
if ( type == V_97 )
return type ;
V_1 [ V_19 ++ ] = V_93 ;
switch ( type ) {
case V_94 :
case V_58 :
if ( F_39 ( V_99 , L_9 , V_93 ) < 0 )
return V_57 ;
return type ;
case V_98 :
switch ( V_93 ) {
case '-' :
V_104 = F_35 () ;
if ( V_104 == '>' ) {
V_1 [ V_19 ++ ] = F_34 () ;
break;
}
case '+' :
case '|' :
case '&' :
case '>' :
case '<' :
V_102 = V_93 ;
V_93 = F_35 () ;
if ( V_93 != V_102 )
goto V_106;
V_1 [ V_19 ++ ] = F_34 () ;
switch ( V_102 ) {
case '>' :
case '<' :
goto V_106;
default:
break;
}
break;
case '!' :
case '=' :
goto V_106;
default:
break;
}
V_1 [ V_19 ] = 0 ;
* V_99 = F_12 ( V_1 ) ;
return type ;
V_106:
V_93 = F_35 () ;
if ( V_93 == '=' )
V_1 [ V_19 ++ ] = F_34 () ;
goto V_107;
case V_96 :
case V_56 :
V_19 -- ;
V_103 = V_93 ;
V_102 = 0 ;
V_108:
do {
if ( V_19 == ( V_101 - 1 ) ) {
V_1 [ V_19 ] = 0 ;
V_105 += V_101 ;
if ( F_37 ( V_99 , V_1 , V_105 ) < 0 )
return V_97 ;
V_19 = 0 ;
}
V_102 = V_93 ;
V_93 = F_34 () ;
V_1 [ V_19 ++ ] = V_93 ;
if ( V_93 == '\\' && V_102 == '\\' )
V_102 = 0 ;
} while ( V_93 != V_103 || V_102 == '\\' );
V_19 -- ;
if ( type == V_96 ) {
unsigned long long V_109 = V_5 ;
do {
V_93 = F_34 () ;
} while ( isspace ( V_93 ) );
if ( V_93 == '"' )
goto V_108;
V_5 = V_109 ;
}
goto V_107;
case V_57 ... V_95 :
case V_55 :
default:
break;
}
while ( F_33 ( F_35 () ) == type ) {
if ( V_19 == ( V_101 - 1 ) ) {
V_1 [ V_19 ] = 0 ;
V_105 += V_101 ;
if ( F_37 ( V_99 , V_1 , V_105 ) < 0 )
return V_97 ;
V_19 = 0 ;
}
V_93 = F_34 () ;
V_1 [ V_19 ++ ] = V_93 ;
}
V_107:
V_1 [ V_19 ] = 0 ;
if ( F_37 ( V_99 , V_1 , V_105 + V_19 + 1 ) < 0 )
return V_97 ;
if ( type == V_55 ) {
if ( strcmp ( * V_99 , L_10 ) == 0 ) {
free ( * V_99 ) ;
* V_99 = NULL ;
return F_40 ( L_11 , V_99 ) ;
} else if ( strcmp ( * V_99 , L_12 ) == 0 ) {
free ( * V_99 ) ;
* V_99 = NULL ;
return F_40 ( L_13 , V_99 ) ;
} else if ( strcmp ( * V_99 , L_14 ) == 0 ) {
free ( * V_99 ) ;
* V_99 = NULL ;
return F_40 ( L_15 , V_99 ) ;
}
}
return type ;
}
static enum V_54 F_40 ( const char * V_62 , char * * V_99 )
{
const char * V_110 ;
unsigned long long V_109 ;
unsigned long long V_111 ;
enum V_54 type ;
V_110 = V_3 ;
V_109 = V_5 ;
V_111 = V_4 ;
F_1 ( V_62 , strlen ( V_62 ) ) ;
type = F_38 ( V_99 ) ;
V_3 = V_110 ;
V_5 = V_109 ;
V_4 = V_111 ;
return type ;
}
static void F_41 ( char * V_99 )
{
if ( V_99 )
free ( V_99 ) ;
}
static enum V_54 F_42 ( char * * V_99 )
{
enum V_54 type ;
for (; ; ) {
type = F_38 ( V_99 ) ;
if ( type != V_95 )
return type ;
F_41 ( * V_99 ) ;
}
* V_99 = NULL ;
return V_97 ;
}
enum V_54 F_43 ( char * * V_99 )
{
return F_42 ( V_99 ) ;
}
void F_44 ( char * V_112 )
{
F_41 ( V_112 ) ;
}
static enum V_54 F_45 ( char * * V_99 )
{
enum V_54 type ;
for (; ; ) {
type = F_38 ( V_99 ) ;
if ( type != V_95 && type != V_94 )
return type ;
F_41 ( * V_99 ) ;
* V_99 = NULL ;
}
* V_99 = NULL ;
return V_97 ;
}
static int F_46 ( enum V_54 type , enum V_54 V_113 )
{
if ( type != V_113 ) {
F_47 ( L_16 ,
V_113 , type ) ;
return - 1 ;
}
return 0 ;
}
static int F_48 ( enum V_54 type , const char * V_112 ,
enum V_54 V_113 , const char * V_114 )
{
if ( type != V_113 ) {
F_47 ( L_16 ,
V_113 , type ) ;
return - 1 ;
}
if ( strcmp ( V_112 , V_114 ) != 0 ) {
F_47 ( L_17 ,
V_114 , V_112 ) ;
return - 1 ;
}
return 0 ;
}
static int F_49 ( enum V_54 V_113 , char * * V_99 , int V_115 )
{
enum V_54 type ;
if ( V_115 )
type = F_42 ( V_99 ) ;
else
type = F_45 ( V_99 ) ;
return F_46 ( type , V_113 ) ;
}
static int F_50 ( enum V_54 V_113 , char * * V_99 )
{
return F_49 ( V_113 , V_99 , 1 ) ;
}
static int F_51 ( enum V_54 V_113 , const char * V_62 ,
int V_115 )
{
enum V_54 type ;
char * V_112 ;
int V_116 ;
if ( V_115 )
type = F_42 ( & V_112 ) ;
else
type = F_45 ( & V_112 ) ;
V_116 = F_48 ( type , V_112 , V_113 , V_62 ) ;
F_41 ( V_112 ) ;
return V_116 ;
}
static int F_52 ( enum V_54 V_113 , const char * V_62 )
{
return F_51 ( V_113 , V_62 , 1 ) ;
}
static int F_53 ( enum V_54 V_113 , const char * V_62 )
{
return F_51 ( V_113 , V_62 , 0 ) ;
}
static char * F_54 ( void )
{
char * V_112 ;
if ( F_52 ( V_55 , L_18 ) < 0 )
return NULL ;
if ( F_52 ( V_98 , L_19 ) < 0 )
return NULL ;
if ( F_50 ( V_55 , & V_112 ) < 0 )
goto V_117;
return V_112 ;
V_117:
F_41 ( V_112 ) ;
return NULL ;
}
static int F_55 ( void )
{
char * V_112 ;
int V_53 ;
if ( F_53 ( V_55 , L_20 ) < 0 )
return - 1 ;
if ( F_52 ( V_98 , L_19 ) < 0 )
return - 1 ;
if ( F_50 ( V_55 , & V_112 ) < 0 )
goto V_117;
V_53 = strtoul ( V_112 , NULL , 0 ) ;
F_41 ( V_112 ) ;
return V_53 ;
V_117:
F_41 ( V_112 ) ;
return - 1 ;
}
static int F_56 ( struct V_118 * V_68 )
{
if ( ( V_68 -> V_71 & V_119 ) &&
( strstr ( V_68 -> type , L_21 ) || strstr ( V_68 -> type , L_22 ) ||
strstr ( V_68 -> type , L_23 ) ) )
return 1 ;
return 0 ;
}
static int F_57 ( struct V_118 * V_68 )
{
if ( strncmp ( V_68 -> type , L_24 , 10 ) == 0 )
return 1 ;
return 0 ;
}
static int F_58 ( struct V_118 * V_68 )
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
} V_120 [] = {
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
for ( V_19 = 0 ; V_120 [ V_19 ] . type ; V_19 ++ ) {
if ( ! strcmp ( V_120 [ V_19 ] . type , V_69 ) )
return V_120 [ V_19 ] . V_2 ;
}
return 0 ;
}
static int F_60 ( struct V_49 * V_50 , struct V_118 * * V_121 )
{
struct V_118 * V_68 = NULL ;
enum V_54 type ;
char * V_112 ;
char * V_122 ;
int V_123 = 0 ;
do {
unsigned int V_124 = 0 ;
type = F_42 ( & V_112 ) ;
if ( type == V_94 ) {
F_41 ( V_112 ) ;
return V_123 ;
}
V_123 ++ ;
if ( F_48 ( type , V_112 , V_55 , L_32 ) )
goto V_117;
F_41 ( V_112 ) ;
type = F_42 ( & V_112 ) ;
if ( V_50 -> V_71 & V_125 &&
type == V_55 && strcmp ( V_112 , L_33 ) == 0 ) {
F_41 ( V_112 ) ;
type = F_42 ( & V_112 ) ;
}
if ( F_48 ( type , V_112 , V_98 , L_19 ) < 0 )
goto V_117;
F_41 ( V_112 ) ;
if ( F_50 ( V_55 , & V_112 ) < 0 )
goto V_117;
V_122 = V_112 ;
V_68 = calloc ( 1 , sizeof( * V_68 ) ) ;
if ( ! V_68 )
goto V_117;
V_68 -> V_50 = V_50 ;
for (; ; ) {
type = F_42 ( & V_112 ) ;
if ( type == V_55 ||
( type == V_98 && strcmp ( V_112 , L_34 ) == 0 ) ||
( V_50 -> V_71 & V_125 &&
type == V_98 && strcmp ( V_112 , L_35 ) == 0 ) ) {
if ( strcmp ( V_112 , L_34 ) == 0 )
V_68 -> V_71 |= V_126 ;
if ( V_68 -> type ) {
char * V_127 ;
V_127 = realloc ( V_68 -> type ,
strlen ( V_68 -> type ) +
strlen ( V_122 ) + 2 ) ;
if ( ! V_127 ) {
free ( V_122 ) ;
goto V_117;
}
V_68 -> type = V_127 ;
strcat ( V_68 -> type , L_36 ) ;
strcat ( V_68 -> type , V_122 ) ;
free ( V_122 ) ;
} else
V_68 -> type = V_122 ;
V_122 = V_112 ;
continue;
}
break;
}
if ( ! V_68 -> type ) {
F_61 ( V_50 , L_37 , V_128 ) ;
goto V_117;
}
V_68 -> V_69 = V_122 ;
if ( F_46 ( type , V_98 ) )
goto V_117;
if ( strcmp ( V_112 , L_38 ) == 0 ) {
enum V_54 V_129 = type ;
char * V_130 = V_112 ;
char * V_131 ;
int V_132 ;
V_68 -> V_71 |= V_119 ;
type = F_42 ( & V_112 ) ;
if ( type == V_55 )
V_68 -> V_133 = strtoul ( V_112 , NULL , 0 ) ;
else
V_68 -> V_133 = 0 ;
while ( strcmp ( V_112 , L_39 ) != 0 ) {
if ( V_129 == V_55 &&
type == V_55 )
V_132 = 2 ;
else
V_132 = 1 ;
V_129 = type ;
V_131 = realloc ( V_130 ,
strlen ( V_130 ) +
strlen ( V_112 ) + V_132 ) ;
if ( ! V_131 ) {
free ( V_130 ) ;
goto V_117;
}
V_130 = V_131 ;
if ( V_132 == 2 )
strcat ( V_130 , L_36 ) ;
strcat ( V_130 , V_112 ) ;
V_68 -> V_133 = strtoul ( V_112 , NULL , 0 ) ;
F_41 ( V_112 ) ;
type = F_42 ( & V_112 ) ;
if ( type == V_97 ) {
F_61 ( V_50 , L_40 ) ;
goto V_117;
}
}
F_41 ( V_112 ) ;
V_131 = realloc ( V_130 , strlen ( V_130 ) + 2 ) ;
if ( ! V_131 ) {
free ( V_130 ) ;
goto V_117;
}
V_130 = V_131 ;
strcat ( V_130 , L_39 ) ;
type = F_42 ( & V_112 ) ;
if ( type == V_55 ) {
char * V_127 ;
V_127 = realloc ( V_68 -> type ,
strlen ( V_68 -> type ) +
strlen ( V_68 -> V_69 ) +
strlen ( V_130 ) + 2 ) ;
if ( ! V_127 ) {
free ( V_130 ) ;
goto V_117;
}
V_68 -> type = V_127 ;
strcat ( V_68 -> type , L_36 ) ;
strcat ( V_68 -> type , V_68 -> V_69 ) ;
V_124 = F_59 ( V_68 -> V_69 ) ;
F_41 ( V_68 -> V_69 ) ;
strcat ( V_68 -> type , V_130 ) ;
V_68 -> V_69 = V_112 ;
type = F_42 ( & V_112 ) ;
} else {
char * V_127 ;
V_127 = realloc ( V_68 -> type ,
strlen ( V_68 -> type ) +
strlen ( V_130 ) + 1 ) ;
if ( ! V_127 ) {
free ( V_130 ) ;
goto V_117;
}
V_68 -> type = V_127 ;
strcat ( V_68 -> type , V_130 ) ;
}
free ( V_130 ) ;
}
if ( F_56 ( V_68 ) )
V_68 -> V_71 |= V_134 ;
if ( F_57 ( V_68 ) )
V_68 -> V_71 |= V_135 ;
if ( F_58 ( V_68 ) )
V_68 -> V_71 |= V_136 ;
if ( F_48 ( type , V_112 , V_98 , L_41 ) )
goto V_117;
F_41 ( V_112 ) ;
if ( F_52 ( V_55 , L_42 ) < 0 )
goto V_137;
if ( F_52 ( V_98 , L_19 ) < 0 )
goto V_137;
if ( F_50 ( V_55 , & V_112 ) )
goto V_117;
V_68 -> V_138 = strtoul ( V_112 , NULL , 0 ) ;
F_41 ( V_112 ) ;
if ( F_52 ( V_98 , L_41 ) < 0 )
goto V_137;
if ( F_52 ( V_55 , L_43 ) < 0 )
goto V_137;
if ( F_52 ( V_98 , L_19 ) < 0 )
goto V_137;
if ( F_50 ( V_55 , & V_112 ) )
goto V_117;
V_68 -> V_2 = strtoul ( V_112 , NULL , 0 ) ;
F_41 ( V_112 ) ;
if ( F_52 ( V_98 , L_41 ) < 0 )
goto V_137;
type = F_42 ( & V_112 ) ;
if ( type != V_94 ) {
if ( F_48 ( type , V_112 , V_55 , L_44 ) )
goto V_117;
F_41 ( V_112 ) ;
if ( F_52 ( V_98 , L_19 ) < 0 )
goto V_137;
if ( F_50 ( V_55 , & V_112 ) )
goto V_117;
if ( strtoul ( V_112 , NULL , 0 ) )
V_68 -> V_71 |= V_139 ;
F_41 ( V_112 ) ;
if ( F_52 ( V_98 , L_41 ) < 0 )
goto V_137;
if ( F_50 ( V_94 , & V_112 ) )
goto V_117;
}
F_41 ( V_112 ) ;
if ( V_68 -> V_71 & V_119 ) {
if ( V_68 -> V_133 )
V_68 -> V_140 = V_68 -> V_2 / V_68 -> V_133 ;
else if ( V_68 -> V_71 & V_135 )
V_68 -> V_140 = V_124 ;
else if ( V_68 -> V_71 & V_134 )
V_68 -> V_140 = 1 ;
else if ( V_68 -> V_71 & V_136 )
V_68 -> V_140 = V_50 -> V_14 ?
V_50 -> V_14 -> V_141 :
sizeof( long ) ;
} else
V_68 -> V_140 = V_68 -> V_2 ;
* V_121 = V_68 ;
V_121 = & V_68 -> V_22 ;
} while ( 1 );
return 0 ;
V_117:
F_41 ( V_112 ) ;
V_137:
if ( V_68 ) {
free ( V_68 -> type ) ;
free ( V_68 -> V_69 ) ;
free ( V_68 ) ;
}
return - 1 ;
}
static int F_62 ( struct V_49 * V_50 )
{
char * V_112 ;
int V_116 ;
if ( F_53 ( V_55 , L_45 ) < 0 )
return - 1 ;
if ( F_52 ( V_98 , L_19 ) < 0 )
return - 1 ;
if ( F_50 ( V_94 , & V_112 ) )
goto V_117;
F_41 ( V_112 ) ;
V_116 = F_60 ( V_50 , & V_50 -> V_142 . V_143 ) ;
if ( V_116 < 0 )
return V_116 ;
V_50 -> V_142 . V_144 = V_116 ;
V_116 = F_60 ( V_50 , & V_50 -> V_142 . V_121 ) ;
if ( V_116 < 0 )
return V_116 ;
V_50 -> V_142 . V_145 = V_116 ;
return 0 ;
V_117:
F_41 ( V_112 ) ;
return - 1 ;
}
static enum V_54
F_63 ( struct V_49 * V_50 , struct V_7 * V_63 , char * * V_99 )
{
enum V_54 type ;
char * V_112 ;
type = F_42 ( & V_112 ) ;
* V_99 = V_112 ;
return F_64 ( V_50 , V_63 , V_99 , type ) ;
}
static enum V_54
F_65 ( struct V_49 * V_50 , struct V_7 * V_63 , char * * V_99 )
{
enum V_54 type ;
type = F_63 ( V_50 , V_63 , V_99 ) ;
while ( type == V_98 ) {
type = F_66 ( V_50 , V_63 , V_99 ) ;
}
return type ;
}
static enum V_54
F_67 ( struct V_49 * V_50 , struct V_7 * V_146 , char * * V_99 )
{
struct V_7 * V_63 , * V_89 , * V_90 ;
enum V_54 type ;
char * V_112 = NULL ;
V_63 = F_6 () ;
V_89 = F_6 () ;
V_90 = F_6 () ;
if ( ! V_63 || ! V_89 || ! V_90 ) {
F_61 ( V_50 , L_46 , V_128 ) ;
F_32 ( V_89 ) ;
F_32 ( V_90 ) ;
goto V_38;
}
V_63 -> type = V_87 ;
V_63 -> V_88 . V_89 = V_89 ;
V_63 -> V_88 . V_90 = V_90 ;
* V_99 = NULL ;
type = F_63 ( V_50 , V_89 , & V_112 ) ;
V_147:
if ( type == V_98 && strcmp ( V_112 , L_19 ) != 0 ) {
type = F_66 ( V_50 , V_89 , & V_112 ) ;
goto V_147;
}
if ( F_48 ( type , V_112 , V_98 , L_19 ) )
goto V_38;
V_63 -> V_88 . V_88 = V_112 ;
type = F_63 ( V_50 , V_90 , & V_112 ) ;
V_146 -> V_88 . V_90 = V_63 ;
* V_99 = V_112 ;
return type ;
V_38:
V_146 -> V_88 . V_90 = NULL ;
F_41 ( V_112 ) ;
F_32 ( V_63 ) ;
return V_57 ;
}
static enum V_54
F_68 ( struct V_49 * V_50 , struct V_7 * V_146 , char * * V_99 )
{
struct V_7 * V_63 ;
enum V_54 type ;
char * V_112 = NULL ;
V_63 = F_6 () ;
if ( ! V_63 ) {
F_61 ( V_50 , L_46 , V_128 ) ;
* V_99 = NULL ;
return V_57 ;
}
* V_99 = NULL ;
type = F_63 ( V_50 , V_63 , & V_112 ) ;
if ( F_48 ( type , V_112 , V_98 , L_39 ) )
goto V_38;
V_146 -> V_88 . V_90 = V_63 ;
F_41 ( V_112 ) ;
type = F_45 ( & V_112 ) ;
* V_99 = V_112 ;
return type ;
V_38:
F_41 ( V_112 ) ;
F_32 ( V_63 ) ;
return V_57 ;
}
static int F_69 ( char * V_88 )
{
if ( ! V_88 [ 1 ] ) {
switch ( V_88 [ 0 ] ) {
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
F_47 ( L_47 , V_88 [ 0 ] ) ;
return - 1 ;
}
} else {
if ( strcmp ( V_88 , L_48 ) == 0 ||
strcmp ( V_88 , L_49 ) == 0 ) {
return 3 ;
} else if ( strcmp ( V_88 , L_50 ) == 0 ||
strcmp ( V_88 , L_51 ) == 0 ) {
return 8 ;
} else if ( strcmp ( V_88 , L_52 ) == 0 ||
strcmp ( V_88 , L_53 ) == 0 ) {
return 9 ;
} else if ( strcmp ( V_88 , L_54 ) == 0 ||
strcmp ( V_88 , L_55 ) == 0 ) {
return 10 ;
} else if ( strcmp ( V_88 , L_56 ) == 0 ) {
return 14 ;
} else if ( strcmp ( V_88 , L_57 ) == 0 ) {
return 15 ;
} else {
F_47 ( L_58 , V_88 ) ;
return - 1 ;
}
}
}
static int F_70 ( struct V_7 * V_63 )
{
if ( ! V_63 -> V_88 . V_89 || V_63 -> V_88 . V_89 -> type == V_92 )
V_63 -> V_88 . V_148 = 0 ;
else
V_63 -> V_88 . V_148 = F_69 ( V_63 -> V_88 . V_88 ) ;
return V_63 -> V_88 . V_148 ;
}
static enum V_54
F_66 ( struct V_49 * V_50 , struct V_7 * V_63 , char * * V_99 )
{
struct V_7 * V_89 , * V_90 = NULL ;
enum V_54 type ;
char * V_112 ;
V_112 = * V_99 ;
if ( V_63 -> type == V_87 && ! V_63 -> V_88 . V_89 ) {
if ( V_112 [ 1 ] ) {
F_61 ( V_50 , L_59 , V_112 ) ;
goto V_38;
}
switch ( V_112 [ 0 ] ) {
case '~' :
case '!' :
case '+' :
case '-' :
break;
default:
F_61 ( V_50 , L_59 , V_112 ) ;
goto V_38;
}
V_89 = F_6 () ;
if ( ! V_89 )
goto V_149;
V_89 -> type = V_92 ;
V_63 -> V_88 . V_89 = V_89 ;
V_90 = F_6 () ;
if ( ! V_90 )
goto V_149;
V_63 -> V_88 . V_90 = V_90 ;
* V_99 = NULL ;
type = F_63 ( V_50 , V_90 , V_99 ) ;
} else if ( strcmp ( V_112 , L_60 ) == 0 ) {
V_89 = F_6 () ;
if ( ! V_89 )
goto V_149;
* V_89 = * V_63 ;
V_63 -> type = V_87 ;
V_63 -> V_88 . V_88 = V_112 ;
V_63 -> V_88 . V_89 = V_89 ;
V_63 -> V_88 . V_148 = 0 ;
type = F_67 ( V_50 , V_63 , V_99 ) ;
} else if ( strcmp ( V_112 , L_50 ) == 0 ||
strcmp ( V_112 , L_51 ) == 0 ||
strcmp ( V_112 , L_61 ) == 0 ||
strcmp ( V_112 , L_62 ) == 0 ||
strcmp ( V_112 , L_56 ) == 0 ||
strcmp ( V_112 , L_57 ) == 0 ||
strcmp ( V_112 , L_63 ) == 0 ||
strcmp ( V_112 , L_64 ) == 0 ||
strcmp ( V_112 , L_34 ) == 0 ||
strcmp ( V_112 , L_65 ) == 0 ||
strcmp ( V_112 , L_66 ) == 0 ||
strcmp ( V_112 , L_67 ) == 0 ||
strcmp ( V_112 , L_68 ) == 0 ||
strcmp ( V_112 , L_53 ) == 0 ||
strcmp ( V_112 , L_52 ) == 0 ||
strcmp ( V_112 , L_54 ) == 0 ||
strcmp ( V_112 , L_55 ) == 0 ) {
V_89 = F_6 () ;
if ( ! V_89 )
goto V_149;
* V_89 = * V_63 ;
V_63 -> type = V_87 ;
V_63 -> V_88 . V_88 = V_112 ;
V_63 -> V_88 . V_89 = V_89 ;
V_63 -> V_88 . V_90 = NULL ;
if ( F_70 ( V_63 ) == - 1 ) {
V_50 -> V_71 |= V_150 ;
V_63 -> V_88 . V_88 = NULL ;
goto V_38;
}
type = F_45 ( & V_112 ) ;
* V_99 = V_112 ;
if ( ( strcmp ( V_63 -> V_88 . V_88 , L_34 ) == 0 ) &&
type == V_58 && ( strcmp ( V_112 , L_69 ) == 0 ) ) {
char * V_151 ;
if ( V_89 -> type != V_65 ) {
F_61 ( V_50 , L_70 ) ;
goto V_38;
}
V_151 = realloc ( V_89 -> V_66 . V_66 ,
strlen ( V_89 -> V_66 . V_66 ) + 3 ) ;
if ( ! V_151 )
goto V_149;
V_89 -> V_66 . V_66 = V_151 ;
strcat ( V_89 -> V_66 . V_66 , L_71 ) ;
free ( V_63 -> V_88 . V_88 ) ;
* V_63 = * V_89 ;
free ( V_89 ) ;
return type ;
}
V_90 = F_6 () ;
if ( ! V_90 )
goto V_149;
type = F_64 ( V_50 , V_90 , V_99 , type ) ;
V_63 -> V_88 . V_90 = V_90 ;
} else if ( strcmp ( V_112 , L_38 ) == 0 ) {
V_89 = F_6 () ;
if ( ! V_89 )
goto V_149;
* V_89 = * V_63 ;
V_63 -> type = V_87 ;
V_63 -> V_88 . V_88 = V_112 ;
V_63 -> V_88 . V_89 = V_89 ;
V_63 -> V_88 . V_148 = 0 ;
type = F_68 ( V_50 , V_63 , V_99 ) ;
} else {
F_61 ( V_50 , L_58 , V_112 ) ;
V_50 -> V_71 |= V_150 ;
goto V_38;
}
if ( type == V_98 && strcmp ( * V_99 , L_19 ) != 0 ) {
int V_148 ;
V_148 = F_69 ( * V_99 ) ;
if ( V_148 > V_63 -> V_88 . V_148 )
return F_66 ( V_50 , V_63 , V_99 ) ;
return F_66 ( V_50 , V_90 , V_99 ) ;
}
return type ;
V_149:
F_61 ( V_50 , L_46 , V_128 ) ;
V_38:
F_41 ( V_112 ) ;
* V_99 = NULL ;
return V_57 ;
}
static enum V_54
F_71 ( struct V_49 * V_50 V_152 , struct V_7 * V_63 ,
char * * V_99 )
{
enum V_54 type ;
char * V_68 ;
char * V_112 ;
if ( F_52 ( V_98 , L_72 ) < 0 )
goto V_153;
if ( F_50 ( V_55 , & V_112 ) < 0 )
goto V_38;
V_68 = V_112 ;
V_63 -> type = V_67 ;
V_63 -> V_68 . V_69 = V_68 ;
if ( V_154 ) {
V_63 -> V_68 . V_68 = F_72 ( V_50 , V_63 -> V_68 . V_69 ) ;
V_63 -> V_68 . V_68 -> V_71 |= V_155 ;
V_154 = 0 ;
} else if ( V_156 ) {
V_63 -> V_68 . V_68 = F_72 ( V_50 , V_63 -> V_68 . V_69 ) ;
V_63 -> V_68 . V_68 -> V_71 |= V_157 ;
V_156 = 0 ;
}
type = F_42 ( & V_112 ) ;
* V_99 = V_112 ;
return type ;
V_38:
F_41 ( V_112 ) ;
V_153:
* V_99 = NULL ;
return V_57 ;
}
static unsigned long long
F_73 ( unsigned long long V_158 , const char * type , int V_159 )
{
int V_160 = 0 ;
char * V_161 ;
int V_132 ;
V_132 = strlen ( type ) ;
if ( V_159 ) {
if ( type [ V_132 - 1 ] != '*' ) {
F_47 ( L_73 ) ;
return V_158 ;
}
V_161 = malloc ( V_132 ) ;
if ( ! V_161 ) {
F_47 ( L_46 , V_128 ) ;
return V_158 ;
}
memcpy ( V_161 , type , V_132 ) ;
V_161 [ V_132 - 2 ] = 0 ;
V_158 = F_73 ( V_158 , V_161 , 0 ) ;
free ( V_161 ) ;
return V_158 ;
}
if ( type [ V_132 - 1 ] == '*' )
return V_158 ;
if ( strncmp ( type , L_74 , 6 ) == 0 )
return V_158 ;
if ( strcmp ( type , L_22 ) == 0 )
return V_158 & 0xff ;
if ( strcmp ( type , L_26 ) == 0 )
return V_158 & 0xffff ;
if ( strcmp ( type , L_27 ) == 0 )
return V_158 & 0xffffffff ;
if ( strcmp ( type , L_28 ) == 0 ||
strcmp ( type , L_31 ) )
return V_158 ;
if ( strcmp ( type , L_23 ) == 0 )
return ( unsigned long long ) ( char ) V_158 & 0xff ;
if ( strcmp ( type , L_29 ) == 0 )
return ( unsigned long long ) ( short ) V_158 & 0xffff ;
if ( strcmp ( type , L_30 ) == 0 )
return ( unsigned long long ) ( int ) V_158 & 0xffffffff ;
if ( strncmp ( type , L_75 , 9 ) == 0 ) {
V_160 = 0 ;
type += 9 ;
}
if ( strcmp ( type , L_21 ) == 0 ) {
if ( V_160 )
return ( unsigned long long ) ( char ) V_158 & 0xff ;
else
return V_158 & 0xff ;
}
if ( strcmp ( type , L_76 ) == 0 ) {
if ( V_160 )
return ( unsigned long long ) ( short ) V_158 & 0xffff ;
else
return V_158 & 0xffff ;
}
if ( strcmp ( type , L_77 ) == 0 ) {
if ( V_160 )
return ( unsigned long long ) ( int ) V_158 & 0xffffffff ;
else
return V_158 & 0xffffffff ;
}
return V_158 ;
}
static unsigned long long
F_74 ( unsigned long long V_158 , struct V_7 * V_63 , int V_159 )
{
if ( V_63 -> type != V_78 ) {
F_47 ( L_78 ) ;
return 0 ;
}
return F_73 ( V_158 , V_63 -> V_79 . type , V_159 ) ;
}
static int F_75 ( struct V_7 * V_63 , long long * V_158 )
{
long long V_89 , V_90 ;
int V_116 = 1 ;
switch ( V_63 -> type ) {
case V_65 :
* V_158 = strtoll ( V_63 -> V_66 . V_66 , NULL , 0 ) ;
break;
case V_78 :
V_116 = F_75 ( V_63 -> V_79 . V_17 , V_158 ) ;
if ( ! V_116 )
break;
* V_158 = F_74 ( * V_158 , V_63 , 0 ) ;
break;
case V_87 :
switch ( V_63 -> V_88 . V_88 [ 0 ] ) {
case '|' :
V_116 = F_75 ( V_63 -> V_88 . V_89 , & V_89 ) ;
if ( ! V_116 )
break;
V_116 = F_75 ( V_63 -> V_88 . V_90 , & V_90 ) ;
if ( ! V_116 )
break;
if ( V_63 -> V_88 . V_88 [ 1 ] )
* V_158 = V_89 || V_90 ;
else
* V_158 = V_89 | V_90 ;
break;
case '&' :
V_116 = F_75 ( V_63 -> V_88 . V_89 , & V_89 ) ;
if ( ! V_116 )
break;
V_116 = F_75 ( V_63 -> V_88 . V_90 , & V_90 ) ;
if ( ! V_116 )
break;
if ( V_63 -> V_88 . V_88 [ 1 ] )
* V_158 = V_89 && V_90 ;
else
* V_158 = V_89 & V_90 ;
break;
case '<' :
V_116 = F_75 ( V_63 -> V_88 . V_89 , & V_89 ) ;
if ( ! V_116 )
break;
V_116 = F_75 ( V_63 -> V_88 . V_90 , & V_90 ) ;
if ( ! V_116 )
break;
switch ( V_63 -> V_88 . V_88 [ 1 ] ) {
case 0 :
* V_158 = V_89 < V_90 ;
break;
case '<' :
* V_158 = V_89 << V_90 ;
break;
case '=' :
* V_158 = V_89 <= V_90 ;
break;
default:
F_47 ( L_58 , V_63 -> V_88 . V_88 ) ;
V_116 = 0 ;
}
break;
case '>' :
V_116 = F_75 ( V_63 -> V_88 . V_89 , & V_89 ) ;
if ( ! V_116 )
break;
V_116 = F_75 ( V_63 -> V_88 . V_90 , & V_90 ) ;
if ( ! V_116 )
break;
switch ( V_63 -> V_88 . V_88 [ 1 ] ) {
case 0 :
* V_158 = V_89 > V_90 ;
break;
case '>' :
* V_158 = V_89 >> V_90 ;
break;
case '=' :
* V_158 = V_89 >= V_90 ;
break;
default:
F_47 ( L_58 , V_63 -> V_88 . V_88 ) ;
V_116 = 0 ;
}
break;
case '=' :
V_116 = F_75 ( V_63 -> V_88 . V_89 , & V_89 ) ;
if ( ! V_116 )
break;
V_116 = F_75 ( V_63 -> V_88 . V_90 , & V_90 ) ;
if ( ! V_116 )
break;
if ( V_63 -> V_88 . V_88 [ 1 ] != '=' ) {
F_47 ( L_58 , V_63 -> V_88 . V_88 ) ;
V_116 = 0 ;
} else
* V_158 = V_89 == V_90 ;
break;
case '!' :
V_116 = F_75 ( V_63 -> V_88 . V_89 , & V_89 ) ;
if ( ! V_116 )
break;
V_116 = F_75 ( V_63 -> V_88 . V_90 , & V_90 ) ;
if ( ! V_116 )
break;
switch ( V_63 -> V_88 . V_88 [ 1 ] ) {
case '=' :
* V_158 = V_89 != V_90 ;
break;
default:
F_47 ( L_58 , V_63 -> V_88 . V_88 ) ;
V_116 = 0 ;
}
break;
case '-' :
if ( V_63 -> V_88 . V_89 -> type == V_92 )
V_89 = 0 ;
else
V_116 = F_75 ( V_63 -> V_88 . V_89 , & V_89 ) ;
if ( ! V_116 )
break;
V_116 = F_75 ( V_63 -> V_88 . V_90 , & V_90 ) ;
if ( ! V_116 )
break;
* V_158 = V_89 - V_90 ;
break;
case '+' :
if ( V_63 -> V_88 . V_89 -> type == V_92 )
V_89 = 0 ;
else
V_116 = F_75 ( V_63 -> V_88 . V_89 , & V_89 ) ;
if ( ! V_116 )
break;
V_116 = F_75 ( V_63 -> V_88 . V_90 , & V_90 ) ;
if ( ! V_116 )
break;
* V_158 = V_89 + V_90 ;
break;
default:
F_47 ( L_58 , V_63 -> V_88 . V_88 ) ;
V_116 = 0 ;
}
break;
case V_92 :
case V_67 ... V_73 :
case V_80 :
case V_81 :
case V_82 :
default:
F_47 ( L_79 , V_63 -> type ) ;
V_116 = 0 ;
}
return V_116 ;
}
static char * F_76 ( struct V_7 * V_63 )
{
long long V_158 ;
static char V_1 [ 20 ] ;
switch ( V_63 -> type ) {
case V_65 :
return V_63 -> V_66 . V_66 ;
case V_78 :
return F_76 ( V_63 -> V_79 . V_17 ) ;
case V_87 :
if ( ! F_75 ( V_63 , & V_158 ) )
break;
sprintf ( V_1 , L_80 , V_158 ) ;
return V_1 ;
case V_92 :
case V_67 ... V_73 :
case V_80 :
case V_81 :
case V_82 :
default:
F_47 ( L_79 , V_63 -> type ) ;
break;
}
return NULL ;
}
static enum V_54
F_77 ( struct V_49 * V_50 , struct V_59 * * V_162 , char * * V_99 )
{
enum V_54 type ;
struct V_7 * V_63 = NULL ;
struct V_59 * V_68 ;
char * V_112 = * V_99 ;
char * V_61 ;
do {
F_41 ( V_112 ) ;
type = F_45 ( & V_112 ) ;
if ( F_48 ( type , V_112 , V_98 , L_81 ) )
break;
V_63 = F_6 () ;
if ( ! V_63 )
goto V_38;
F_41 ( V_112 ) ;
type = F_63 ( V_50 , V_63 , & V_112 ) ;
if ( type == V_98 )
type = F_66 ( V_50 , V_63 , & V_112 ) ;
if ( type == V_57 )
goto V_38;
if ( F_48 ( type , V_112 , V_58 , L_82 ) )
goto V_38;
V_68 = calloc ( 1 , sizeof( * V_68 ) ) ;
if ( ! V_68 )
goto V_38;
V_61 = F_76 ( V_63 ) ;
if ( V_61 == NULL )
goto V_163;
V_68 -> V_61 = F_12 ( V_61 ) ;
if ( V_68 -> V_61 == NULL )
goto V_163;
F_32 ( V_63 ) ;
V_63 = F_6 () ;
if ( ! V_63 )
goto V_38;
F_41 ( V_112 ) ;
type = F_63 ( V_50 , V_63 , & V_112 ) ;
if ( F_48 ( type , V_112 , V_98 , L_83 ) )
goto V_163;
V_61 = F_76 ( V_63 ) ;
if ( V_61 == NULL )
goto V_163;
V_68 -> V_62 = F_12 ( V_61 ) ;
if ( V_68 -> V_62 == NULL )
goto V_163;
F_32 ( V_63 ) ;
V_63 = NULL ;
* V_162 = V_68 ;
V_162 = & V_68 -> V_22 ;
F_41 ( V_112 ) ;
type = F_45 ( & V_112 ) ;
} while ( type == V_58 && strcmp ( V_112 , L_82 ) == 0 );
* V_99 = V_112 ;
return type ;
V_163:
F_31 ( V_68 ) ;
V_38:
F_32 ( V_63 ) ;
F_41 ( V_112 ) ;
* V_99 = NULL ;
return V_57 ;
}
static enum V_54
F_78 ( struct V_49 * V_50 , struct V_7 * V_63 , char * * V_99 )
{
struct V_7 * V_68 ;
enum V_54 type ;
char * V_112 = NULL ;
memset ( V_63 , 0 , sizeof( * V_63 ) ) ;
V_63 -> type = V_70 ;
V_68 = F_6 () ;
if ( ! V_68 ) {
F_61 ( V_50 , L_46 , V_128 ) ;
goto V_38;
}
type = F_65 ( V_50 , V_68 , & V_112 ) ;
while ( type == V_98 )
type = F_66 ( V_50 , V_68 , & V_112 ) ;
if ( F_48 ( type , V_112 , V_58 , L_82 ) )
goto V_163;
F_41 ( V_112 ) ;
V_63 -> V_71 . V_68 = V_68 ;
type = F_45 ( & V_112 ) ;
if ( F_30 ( type ) ) {
V_63 -> V_71 . V_72 = V_112 ;
type = F_45 ( & V_112 ) ;
}
if ( F_48 ( type , V_112 , V_58 , L_82 ) )
goto V_38;
type = F_77 ( V_50 , & V_63 -> V_71 . V_71 , & V_112 ) ;
if ( F_48 ( type , V_112 , V_58 , L_69 ) )
goto V_38;
F_41 ( V_112 ) ;
type = F_45 ( V_99 ) ;
return type ;
V_163:
F_32 ( V_68 ) ;
V_38:
F_41 ( V_112 ) ;
* V_99 = NULL ;
return V_57 ;
}
static enum V_54
F_79 ( struct V_49 * V_50 , struct V_7 * V_63 , char * * V_99 )
{
struct V_7 * V_68 ;
enum V_54 type ;
char * V_112 = NULL ;
memset ( V_63 , 0 , sizeof( * V_63 ) ) ;
V_63 -> type = V_73 ;
V_68 = F_6 () ;
if ( ! V_68 ) {
F_61 ( V_50 , L_46 , V_128 ) ;
goto V_38;
}
type = F_65 ( V_50 , V_68 , & V_112 ) ;
if ( F_48 ( type , V_112 , V_58 , L_82 ) )
goto V_163;
V_63 -> V_74 . V_68 = V_68 ;
type = F_77 ( V_50 , & V_63 -> V_74 . V_75 , & V_112 ) ;
if ( F_48 ( type , V_112 , V_58 , L_69 ) )
goto V_38;
F_41 ( V_112 ) ;
type = F_45 ( V_99 ) ;
return type ;
V_163:
F_32 ( V_68 ) ;
V_38:
F_41 ( V_112 ) ;
* V_99 = NULL ;
return V_57 ;
}
static enum V_54
F_80 ( struct V_49 * V_50 , struct V_7 * V_63 , char * * V_99 )
{
struct V_7 * V_68 ;
enum V_54 type ;
char * V_112 = NULL ;
memset ( V_63 , 0 , sizeof( * V_63 ) ) ;
V_63 -> type = V_76 ;
V_68 = F_6 () ;
if ( ! V_68 ) {
F_61 ( V_50 , L_46 , V_128 ) ;
goto V_38;
}
type = F_63 ( V_50 , V_68 , & V_112 ) ;
if ( F_48 ( type , V_112 , V_58 , L_82 ) )
goto V_38;
V_63 -> V_77 . V_68 = V_68 ;
F_41 ( V_112 ) ;
V_68 = F_6 () ;
if ( ! V_68 ) {
F_61 ( V_50 , L_46 , V_128 ) ;
* V_99 = NULL ;
return V_57 ;
}
type = F_63 ( V_50 , V_68 , & V_112 ) ;
if ( F_48 ( type , V_112 , V_58 , L_69 ) )
goto V_38;
V_63 -> V_77 . V_2 = V_68 ;
F_41 ( V_112 ) ;
type = F_45 ( V_99 ) ;
return type ;
V_38:
F_32 ( V_68 ) ;
F_41 ( V_112 ) ;
* V_99 = NULL ;
return V_57 ;
}
static enum V_54
F_81 ( struct V_49 * V_50 , struct V_7 * V_63 , char * * V_99 )
{
struct V_118 * V_68 ;
enum V_54 type ;
char * V_112 ;
memset ( V_63 , 0 , sizeof( * V_63 ) ) ;
V_63 -> type = V_84 ;
type = F_42 ( & V_112 ) ;
* V_99 = V_112 ;
if ( type != V_55 )
goto V_38;
V_68 = F_82 ( V_50 , V_112 ) ;
if ( ! V_68 )
goto V_38;
V_63 -> V_85 . V_68 = V_68 ;
V_63 -> V_85 . V_86 = 0 ;
if ( F_52 ( V_58 , L_69 ) < 0 )
goto V_38;
F_41 ( V_112 ) ;
type = F_45 ( & V_112 ) ;
* V_99 = V_112 ;
if ( type != V_98 || strcmp ( V_112 , L_38 ) != 0 )
return type ;
F_41 ( V_112 ) ;
V_63 = F_6 () ;
if ( ! V_63 ) {
F_61 ( V_50 , L_46 , V_128 ) ;
* V_99 = NULL ;
return V_57 ;
}
type = F_63 ( V_50 , V_63 , & V_112 ) ;
if ( type == V_57 )
goto V_164;
if ( ! F_48 ( type , V_112 , V_98 , L_39 ) )
goto V_164;
F_41 ( V_112 ) ;
type = F_45 ( V_99 ) ;
return type ;
V_164:
F_32 ( V_63 ) ;
V_38:
F_41 ( V_112 ) ;
* V_99 = NULL ;
return V_57 ;
}
static enum V_54
F_83 ( struct V_49 * V_50 , struct V_7 * V_63 , char * * V_99 )
{
struct V_7 * V_165 ;
enum V_54 type ;
char * V_112 ;
type = F_63 ( V_50 , V_63 , & V_112 ) ;
if ( type == V_57 )
goto V_38;
if ( type == V_98 )
type = F_66 ( V_50 , V_63 , & V_112 ) ;
if ( type == V_57 )
goto V_38;
if ( F_48 ( type , V_112 , V_58 , L_69 ) )
goto V_38;
F_41 ( V_112 ) ;
type = F_45 ( & V_112 ) ;
if ( F_30 ( type ) ||
( type == V_58 && strcmp ( V_112 , L_84 ) == 0 ) ) {
if ( V_63 -> type != V_65 ) {
F_61 ( V_50 , L_85 ) ;
goto V_38;
}
V_165 = F_6 () ;
if ( ! V_165 ) {
F_61 ( V_50 , L_46 ,
V_128 ) ;
goto V_38;
}
V_63 -> type = V_78 ;
V_63 -> V_79 . type = V_63 -> V_66 . V_66 ;
V_63 -> V_79 . V_17 = V_165 ;
type = F_64 ( V_50 , V_165 , & V_112 , type ) ;
}
* V_99 = V_112 ;
return type ;
V_38:
F_41 ( V_112 ) ;
* V_99 = NULL ;
return V_57 ;
}
static enum V_54
F_84 ( struct V_49 * V_50 V_152 , struct V_7 * V_63 ,
char * * V_99 )
{
enum V_54 type ;
char * V_112 ;
if ( F_50 ( V_55 , & V_112 ) < 0 )
goto V_38;
V_63 -> type = V_80 ;
V_63 -> string . string = V_112 ;
V_63 -> string . V_138 = - 1 ;
if ( F_52 ( V_58 , L_69 ) < 0 )
goto V_153;
type = F_42 ( & V_112 ) ;
* V_99 = V_112 ;
return type ;
V_38:
F_41 ( V_112 ) ;
V_153:
* V_99 = NULL ;
return V_57 ;
}
static enum V_54
F_85 ( struct V_49 * V_50 V_152 , struct V_7 * V_63 ,
char * * V_99 )
{
enum V_54 type ;
char * V_112 ;
if ( F_50 ( V_55 , & V_112 ) < 0 )
goto V_38;
V_63 -> type = V_82 ;
V_63 -> V_83 . V_83 = V_112 ;
V_63 -> V_83 . V_138 = - 1 ;
if ( F_52 ( V_58 , L_69 ) < 0 )
goto V_153;
type = F_42 ( & V_112 ) ;
* V_99 = V_112 ;
return type ;
V_38:
F_41 ( V_112 ) ;
V_153:
* V_99 = NULL ;
return V_57 ;
}
static struct V_166 *
F_86 ( struct V_14 * V_14 , char * V_167 )
{
struct V_166 * V_35 ;
if ( ! V_14 )
return NULL ;
for ( V_35 = V_14 -> V_168 ; V_35 ; V_35 = V_35 -> V_22 ) {
if ( strcmp ( V_35 -> V_69 , V_167 ) == 0 )
break;
}
return V_35 ;
}
static void F_87 ( struct V_14 * V_14 , char * V_167 )
{
struct V_166 * V_35 ;
struct V_166 * * V_22 ;
V_22 = & V_14 -> V_168 ;
while ( ( V_35 = * V_22 ) ) {
if ( strcmp ( V_35 -> V_69 , V_167 ) == 0 ) {
* V_22 = V_35 -> V_22 ;
F_88 ( V_35 ) ;
break;
}
V_22 = & V_35 -> V_22 ;
}
}
static enum V_54
F_89 ( struct V_49 * V_50 , struct V_166 * V_35 ,
struct V_7 * V_63 , char * * V_99 )
{
struct V_7 * * V_169 ;
struct V_7 * V_64 ;
enum V_54 type ;
char * V_112 ;
int V_19 ;
V_63 -> type = V_91 ;
V_63 -> V_35 . V_35 = V_35 ;
* V_99 = NULL ;
V_169 = & ( V_63 -> V_35 . args ) ;
for ( V_19 = 0 ; V_19 < V_35 -> V_170 ; V_19 ++ ) {
V_64 = F_6 () ;
if ( ! V_64 ) {
F_61 ( V_50 , L_46 ,
V_128 ) ;
return V_57 ;
}
type = F_63 ( V_50 , V_64 , & V_112 ) ;
if ( V_19 < ( V_35 -> V_170 - 1 ) ) {
if ( type != V_58 || strcmp ( V_112 , L_82 ) != 0 ) {
F_61 ( V_50 ,
L_86 ,
V_35 -> V_69 , V_35 -> V_170 ,
V_50 -> V_69 , V_19 + 1 ) ;
goto V_171;
}
} else {
if ( type != V_58 || strcmp ( V_112 , L_69 ) != 0 ) {
F_61 ( V_50 ,
L_87 ,
V_35 -> V_69 , V_35 -> V_170 , V_50 -> V_69 ) ;
goto V_171;
}
}
* V_169 = V_64 ;
V_169 = & ( V_64 -> V_22 ) ;
F_41 ( V_112 ) ;
}
type = F_42 ( & V_112 ) ;
* V_99 = V_112 ;
return type ;
V_171:
F_32 ( V_64 ) ;
F_41 ( V_112 ) ;
return V_57 ;
}
static enum V_54
F_90 ( struct V_49 * V_50 , struct V_7 * V_63 ,
char * V_112 , char * * V_99 )
{
struct V_166 * V_35 ;
if ( strcmp ( V_112 , L_88 ) == 0 ) {
F_41 ( V_112 ) ;
V_154 = 1 ;
return F_78 ( V_50 , V_63 , V_99 ) ;
}
if ( strcmp ( V_112 , L_89 ) == 0 ) {
F_41 ( V_112 ) ;
V_156 = 1 ;
return F_79 ( V_50 , V_63 , V_99 ) ;
}
if ( strcmp ( V_112 , L_90 ) == 0 ) {
F_41 ( V_112 ) ;
return F_80 ( V_50 , V_63 , V_99 ) ;
}
if ( strcmp ( V_112 , L_91 ) == 0 ) {
F_41 ( V_112 ) ;
return F_84 ( V_50 , V_63 , V_99 ) ;
}
if ( strcmp ( V_112 , L_92 ) == 0 ) {
F_41 ( V_112 ) ;
return F_85 ( V_50 , V_63 , V_99 ) ;
}
if ( strcmp ( V_112 , L_93 ) == 0 ) {
F_41 ( V_112 ) ;
return F_81 ( V_50 , V_63 , V_99 ) ;
}
V_35 = F_86 ( V_50 -> V_14 , V_112 ) ;
if ( V_35 ) {
F_41 ( V_112 ) ;
return F_89 ( V_50 , V_35 , V_63 , V_99 ) ;
}
F_61 ( V_50 , L_94 , V_112 ) ;
F_41 ( V_112 ) ;
return V_57 ;
}
static enum V_54
F_64 ( struct V_49 * V_50 , struct V_7 * V_63 ,
char * * V_99 , enum V_54 type )
{
char * V_112 ;
char * V_66 ;
V_112 = * V_99 ;
switch ( type ) {
case V_55 :
if ( strcmp ( V_112 , L_95 ) == 0 ) {
F_41 ( V_112 ) ;
type = F_71 ( V_50 , V_63 , & V_112 ) ;
break;
}
V_66 = V_112 ;
type = F_45 ( & V_112 ) ;
if ( type == V_58 && strcmp ( V_112 , L_84 ) == 0 ) {
F_41 ( V_112 ) ;
V_112 = NULL ;
type = F_90 ( V_50 , V_63 , V_66 , & V_112 ) ;
break;
}
while ( type == V_55 ) {
char * V_151 ;
V_151 = realloc ( V_66 ,
strlen ( V_66 ) + strlen ( V_112 ) + 2 ) ;
if ( ! V_151 ) {
free ( V_66 ) ;
* V_99 = NULL ;
F_41 ( V_112 ) ;
return V_57 ;
}
V_66 = V_151 ;
strcat ( V_66 , L_36 ) ;
strcat ( V_66 , V_112 ) ;
F_41 ( V_112 ) ;
type = F_45 ( & V_112 ) ;
}
V_63 -> type = V_65 ;
V_63 -> V_66 . V_66 = V_66 ;
break;
case V_96 :
case V_56 :
V_63 -> type = V_65 ;
V_63 -> V_66 . V_66 = V_112 ;
type = F_45 ( & V_112 ) ;
break;
case V_58 :
if ( strcmp ( V_112 , L_84 ) == 0 ) {
F_41 ( V_112 ) ;
type = F_83 ( V_50 , V_63 , & V_112 ) ;
break;
}
case V_98 :
V_63 -> type = V_87 ;
V_63 -> V_88 . V_88 = V_112 ;
V_63 -> V_88 . V_89 = NULL ;
type = F_66 ( V_50 , V_63 , & V_112 ) ;
if ( type == V_57 )
V_63 -> V_88 . V_88 = NULL ;
break;
case V_57 ... V_94 :
default:
F_61 ( V_50 , L_96 , type ) ;
return V_57 ;
}
* V_99 = V_112 ;
return type ;
}
static int F_91 ( struct V_49 * V_50 , struct V_7 * * V_162 )
{
enum V_54 type = V_57 ;
struct V_7 * V_63 ;
char * V_112 ;
int args = 0 ;
do {
if ( type == V_94 ) {
type = F_45 ( & V_112 ) ;
continue;
}
V_63 = F_6 () ;
if ( ! V_63 ) {
F_61 ( V_50 , L_46 ,
V_128 ) ;
return - 1 ;
}
type = F_63 ( V_50 , V_63 , & V_112 ) ;
if ( type == V_57 ) {
F_41 ( V_112 ) ;
F_32 ( V_63 ) ;
return - 1 ;
}
* V_162 = V_63 ;
args ++ ;
if ( type == V_98 ) {
type = F_66 ( V_50 , V_63 , & V_112 ) ;
F_41 ( V_112 ) ;
if ( type == V_57 ) {
* V_162 = NULL ;
F_32 ( V_63 ) ;
return - 1 ;
}
V_162 = & V_63 -> V_22 ;
continue;
}
if ( type == V_58 && strcmp ( V_112 , L_82 ) == 0 ) {
F_41 ( V_112 ) ;
* V_162 = V_63 ;
V_162 = & V_63 -> V_22 ;
continue;
}
break;
} while ( type != V_97 );
if ( type != V_97 && type != V_57 )
F_41 ( V_112 ) ;
return args ;
}
static int F_92 ( struct V_49 * V_50 )
{
enum V_54 type ;
char * V_112 ;
int V_116 ;
if ( F_53 ( V_55 , L_97 ) < 0 )
return - 1 ;
if ( F_52 ( V_55 , L_98 ) < 0 )
return - 1 ;
if ( F_52 ( V_98 , L_19 ) < 0 )
return - 1 ;
if ( F_50 ( V_96 , & V_112 ) < 0 )
goto V_117;
V_108:
V_50 -> V_172 . V_142 = V_112 ;
V_50 -> V_172 . args = NULL ;
type = F_45 ( & V_112 ) ;
if ( type == V_97 )
return 0 ;
if ( type == V_96 ) {
char * V_173 ;
if ( F_39 ( & V_173 , L_99 , V_50 -> V_172 . V_142 , V_112 ) < 0 )
goto V_117;
F_41 ( V_112 ) ;
F_41 ( V_50 -> V_172 . V_142 ) ;
V_50 -> V_172 . V_142 = NULL ;
V_112 = V_173 ;
goto V_108;
}
if ( F_48 ( type , V_112 , V_58 , L_82 ) )
goto V_117;
F_41 ( V_112 ) ;
V_116 = F_91 ( V_50 , & V_50 -> V_172 . args ) ;
if ( V_116 < 0 )
return - 1 ;
return V_116 ;
V_117:
F_41 ( V_112 ) ;
return - 1 ;
}
struct V_118 *
F_93 ( struct V_49 * V_50 , const char * V_69 )
{
struct V_118 * V_142 ;
for ( V_142 = V_50 -> V_142 . V_143 ;
V_142 ; V_142 = V_142 -> V_22 ) {
if ( strcmp ( V_142 -> V_69 , V_69 ) == 0 )
break;
}
return V_142 ;
}
struct V_118 *
F_82 ( struct V_49 * V_50 , const char * V_69 )
{
struct V_118 * V_142 ;
for ( V_142 = V_50 -> V_142 . V_121 ;
V_142 ; V_142 = V_142 -> V_22 ) {
if ( strcmp ( V_142 -> V_69 , V_69 ) == 0 )
break;
}
return V_142 ;
}
struct V_118 *
F_72 ( struct V_49 * V_50 , const char * V_69 )
{
struct V_118 * V_142 ;
V_142 = F_93 ( V_50 , V_69 ) ;
if ( V_142 )
return V_142 ;
return F_82 ( V_50 , V_69 ) ;
}
unsigned long long F_94 ( struct V_14 * V_14 ,
const void * V_174 , int V_2 )
{
switch ( V_2 ) {
case 1 :
return * ( unsigned char * ) V_174 ;
case 2 :
return F_95 ( V_14 , V_174 ) ;
case 4 :
return F_96 ( V_14 , V_174 ) ;
case 8 :
return F_97 ( V_14 , V_174 ) ;
default:
return 0 ;
}
}
int F_98 ( struct V_118 * V_68 , const void * V_175 ,
unsigned long long * V_61 )
{
if ( ! V_68 )
return - 1 ;
switch ( V_68 -> V_2 ) {
case 1 :
case 2 :
case 4 :
case 8 :
* V_61 = F_94 ( V_68 -> V_50 -> V_14 ,
V_175 + V_68 -> V_138 , V_68 -> V_2 ) ;
return 0 ;
default:
return - 1 ;
}
}
static int F_99 ( struct V_14 * V_14 ,
const char * type , int * V_138 , int * V_2 )
{
struct V_49 * V_50 ;
struct V_118 * V_68 ;
if ( ! V_14 -> V_51 ) {
F_47 ( L_100 ) ;
return - 1 ;
}
V_50 = V_14 -> V_51 [ 0 ] ;
V_68 = F_93 ( V_50 , type ) ;
if ( ! V_68 )
return - 1 ;
* V_138 = V_68 -> V_138 ;
* V_2 = V_68 -> V_2 ;
return 0 ;
}
static int F_100 ( struct V_14 * V_14 , void * V_175 ,
int * V_2 , int * V_138 , const char * V_69 )
{
int V_116 ;
if ( ! * V_2 ) {
V_116 = F_99 ( V_14 , V_69 , V_138 , V_2 ) ;
if ( V_116 < 0 )
return V_116 ;
}
return F_94 ( V_14 , V_175 + * V_138 , * V_2 ) ;
}
static int F_101 ( struct V_14 * V_14 , void * V_175 )
{
return F_100 ( V_14 , V_175 ,
& V_14 -> F_59 , & V_14 -> V_176 ,
L_101 ) ;
}
static int F_102 ( struct V_14 * V_14 , void * V_175 )
{
return F_100 ( V_14 , V_175 ,
& V_14 -> V_177 , & V_14 -> V_178 ,
L_102 ) ;
}
static int F_103 ( struct V_14 * V_14 , void * V_175 )
{
return F_100 ( V_14 , V_175 ,
& V_14 -> V_179 , & V_14 -> V_180 ,
L_103 ) ;
}
static int F_104 ( struct V_14 * V_14 , void * V_175 )
{
return F_100 ( V_14 , V_175 ,
& V_14 -> V_181 , & V_14 -> V_182 ,
L_104 ) ;
}
static int F_105 ( struct V_14 * V_14 , void * V_175 )
{
return F_100 ( V_14 , V_175 ,
& V_14 -> V_183 , & V_14 -> V_184 ,
L_105 ) ;
}
static int F_106 ( struct V_14 * V_14 , void * V_175 )
{
return F_100 ( V_14 , V_175 ,
& V_14 -> V_183 , & V_14 -> V_184 ,
L_106 ) ;
}
struct V_49 * F_107 ( struct V_14 * V_14 , int V_53 )
{
struct V_49 * * V_185 ;
struct V_49 V_23 ;
struct V_49 * V_186 = & V_23 ;
if ( V_14 -> V_187 && V_14 -> V_187 -> V_53 == V_53 )
return V_14 -> V_187 ;
V_23 . V_53 = V_53 ;
V_185 = bsearch ( & V_186 , V_14 -> V_51 , V_14 -> V_52 ,
sizeof( * V_14 -> V_51 ) , V_188 ) ;
if ( V_185 ) {
V_14 -> V_187 = * V_185 ;
return * V_185 ;
}
return NULL ;
}
struct V_49 *
F_108 ( struct V_14 * V_14 ,
const char * V_189 , const char * V_69 )
{
struct V_49 * V_50 ;
int V_19 ;
if ( V_14 -> V_187 &&
strcmp ( V_14 -> V_187 -> V_69 , V_69 ) == 0 &&
( ! V_189 || strcmp ( V_14 -> V_187 -> system , V_189 ) == 0 ) )
return V_14 -> V_187 ;
for ( V_19 = 0 ; V_19 < V_14 -> V_52 ; V_19 ++ ) {
V_50 = V_14 -> V_51 [ V_19 ] ;
if ( strcmp ( V_50 -> V_69 , V_69 ) == 0 ) {
if ( ! V_189 )
break;
if ( strcmp ( V_50 -> system , V_189 ) == 0 )
break;
}
}
if ( V_19 == V_14 -> V_52 )
V_50 = NULL ;
V_14 -> V_187 = V_50 ;
return V_50 ;
}
static unsigned long long
F_109 ( void * V_175 , int V_2 , struct V_49 * V_50 , struct V_7 * V_63 )
{
struct V_14 * V_14 = V_50 -> V_14 ;
unsigned long long V_158 = 0 ;
unsigned long long V_89 , V_90 ;
struct V_7 * V_190 = NULL ;
struct V_7 * V_191 ;
unsigned long V_138 ;
unsigned int V_192 ;
switch ( V_63 -> type ) {
case V_92 :
return 0 ;
case V_65 :
return F_110 ( V_63 -> V_66 . V_66 , NULL , 0 ) ;
case V_67 :
if ( ! V_63 -> V_68 . V_68 ) {
V_63 -> V_68 . V_68 = F_72 ( V_50 , V_63 -> V_68 . V_69 ) ;
if ( ! V_63 -> V_68 . V_68 )
goto V_193;
}
V_158 = F_94 ( V_14 , V_175 + V_63 -> V_68 . V_68 -> V_138 ,
V_63 -> V_68 . V_68 -> V_2 ) ;
break;
case V_70 :
case V_73 :
case V_76 :
break;
case V_78 :
V_158 = F_109 ( V_175 , V_2 , V_50 , V_63 -> V_79 . V_17 ) ;
return F_74 ( V_158 , V_63 , 0 ) ;
case V_80 :
case V_81 :
case V_82 :
return 0 ;
case V_91 : {
struct V_194 V_195 ;
F_111 ( & V_195 ) ;
V_158 = F_112 ( & V_195 , V_175 , V_2 , V_50 , V_63 ) ;
F_113 ( & V_195 ) ;
return V_158 ;
}
case V_87 :
if ( strcmp ( V_63 -> V_88 . V_88 , L_38 ) == 0 ) {
V_90 = F_109 ( V_175 , V_2 , V_50 , V_63 -> V_88 . V_90 ) ;
V_191 = V_63 -> V_88 . V_89 ;
while ( V_191 -> type == V_78 ) {
if ( ! V_190 )
V_190 = V_191 ;
V_191 = V_191 -> V_79 . V_17 ;
}
V_192 = V_14 -> V_141 ;
switch ( V_191 -> type ) {
case V_84 :
V_138 = F_94 ( V_14 ,
V_175 + V_191 -> V_85 . V_68 -> V_138 ,
V_191 -> V_85 . V_68 -> V_2 ) ;
if ( V_191 -> V_85 . V_68 -> V_140 )
V_192 = V_191 -> V_85 . V_68 -> V_140 ;
V_138 &= 0xffff ;
V_138 += V_90 ;
break;
case V_67 :
if ( ! V_191 -> V_68 . V_68 ) {
V_191 -> V_68 . V_68 =
F_72 ( V_50 , V_191 -> V_68 . V_69 ) ;
if ( ! V_191 -> V_68 . V_68 ) {
V_63 = V_191 ;
goto V_193;
}
}
V_192 = V_191 -> V_68 . V_68 -> V_140 ;
V_138 = V_191 -> V_68 . V_68 -> V_138 +
V_90 * V_191 -> V_68 . V_68 -> V_140 ;
break;
default:
goto V_196;
}
V_158 = F_94 ( V_14 ,
V_175 + V_138 , V_192 ) ;
if ( V_190 )
V_158 = F_74 ( V_158 , V_190 , 1 ) ;
break;
} else if ( strcmp ( V_63 -> V_88 . V_88 , L_60 ) == 0 ) {
V_89 = F_109 ( V_175 , V_2 , V_50 , V_63 -> V_88 . V_89 ) ;
V_63 = V_63 -> V_88 . V_90 ;
if ( V_89 )
V_158 = F_109 ( V_175 , V_2 , V_50 , V_63 -> V_88 . V_89 ) ;
else
V_158 = F_109 ( V_175 , V_2 , V_50 , V_63 -> V_88 . V_90 ) ;
break;
}
V_196:
V_89 = F_109 ( V_175 , V_2 , V_50 , V_63 -> V_88 . V_89 ) ;
V_90 = F_109 ( V_175 , V_2 , V_50 , V_63 -> V_88 . V_90 ) ;
switch ( V_63 -> V_88 . V_88 [ 0 ] ) {
case '!' :
switch ( V_63 -> V_88 . V_88 [ 1 ] ) {
case 0 :
V_158 = ! V_90 ;
break;
case '=' :
V_158 = V_89 != V_90 ;
break;
default:
goto V_197;
}
break;
case '~' :
V_158 = ~ V_90 ;
break;
case '|' :
if ( V_63 -> V_88 . V_88 [ 1 ] )
V_158 = V_89 || V_90 ;
else
V_158 = V_89 | V_90 ;
break;
case '&' :
if ( V_63 -> V_88 . V_88 [ 1 ] )
V_158 = V_89 && V_90 ;
else
V_158 = V_89 & V_90 ;
break;
case '<' :
switch ( V_63 -> V_88 . V_88 [ 1 ] ) {
case 0 :
V_158 = V_89 < V_90 ;
break;
case '<' :
V_158 = V_89 << V_90 ;
break;
case '=' :
V_158 = V_89 <= V_90 ;
break;
default:
goto V_197;
}
break;
case '>' :
switch ( V_63 -> V_88 . V_88 [ 1 ] ) {
case 0 :
V_158 = V_89 > V_90 ;
break;
case '>' :
V_158 = V_89 >> V_90 ;
break;
case '=' :
V_158 = V_89 >= V_90 ;
break;
default:
goto V_197;
}
break;
case '=' :
if ( V_63 -> V_88 . V_88 [ 1 ] != '=' )
goto V_197;
V_158 = V_89 == V_90 ;
break;
case '-' :
V_158 = V_89 - V_90 ;
break;
case '+' :
V_158 = V_89 + V_90 ;
break;
case '/' :
V_158 = V_89 / V_90 ;
break;
case '*' :
V_158 = V_89 * V_90 ;
break;
default:
goto V_197;
}
break;
case V_84 :
V_138 = F_94 ( V_14 ,
V_175 + V_63 -> V_85 . V_68 -> V_138 ,
V_63 -> V_85 . V_68 -> V_2 ) ;
V_138 &= 0xffff ;
V_158 = ( unsigned long long ) ( ( unsigned long ) V_175 + V_138 ) ;
break;
default:
return 0 ;
}
return V_158 ;
V_197:
F_61 ( V_50 , L_107 , V_128 , V_63 -> V_88 . V_88 ) ;
return 0 ;
V_193:
F_61 ( V_50 , L_108 ,
V_128 , V_63 -> V_68 . V_69 ) ;
return 0 ;
}
static unsigned long long F_114 ( const char * V_198 )
{
int V_19 ;
if ( isdigit ( V_198 [ 0 ] ) )
return F_110 ( V_198 , NULL , 0 ) ;
for ( V_19 = 0 ; V_19 < ( int ) ( sizeof( V_71 ) / sizeof( V_71 [ 0 ] ) ) ; V_19 ++ )
if ( strcmp ( V_71 [ V_19 ] . V_69 , V_198 ) == 0 )
return V_71 [ V_19 ] . V_61 ;
return 0 ;
}
static void F_115 ( struct V_194 * V_195 , const char * V_142 ,
int V_199 , const char * V_62 )
{
if ( V_199 >= 0 )
F_116 ( V_195 , V_142 , V_199 , V_62 ) ;
else
F_116 ( V_195 , V_142 , V_62 ) ;
}
static void F_117 ( struct V_14 * V_14 ,
struct V_194 * V_195 , const char * V_142 ,
int V_199 , const void * V_175 , int V_2 )
{
int V_200 = V_2 * 8 ;
int V_201 = ( V_200 + 3 ) / 4 ;
int V_132 = 0 ;
char V_1 [ 3 ] ;
char * V_62 ;
int V_86 ;
int V_19 ;
V_201 += ( V_200 - 1 ) / 32 ;
V_62 = malloc ( V_201 + 1 ) ;
if ( ! V_62 ) {
F_47 ( L_46 , V_128 ) ;
return;
}
V_62 [ V_201 ] = 0 ;
for ( V_19 = V_201 - 2 ; V_19 >= 0 ; V_19 -= 2 ) {
if ( V_14 -> V_202 )
V_86 = V_2 - ( V_132 + 1 ) ;
else
V_86 = V_132 ;
snprintf ( V_1 , 3 , L_109 , * ( ( unsigned char * ) V_175 + V_86 ) ) ;
memcpy ( V_62 + V_19 , V_1 , 2 ) ;
V_132 ++ ;
if ( ! ( V_132 & 3 ) && V_19 > 0 ) {
V_19 -- ;
V_62 [ V_19 ] = ',' ;
}
}
if ( V_199 >= 0 )
F_116 ( V_195 , V_142 , V_199 , V_62 ) ;
else
F_116 ( V_195 , V_142 , V_62 ) ;
free ( V_62 ) ;
}
static void F_118 ( struct V_194 * V_195 , void * V_175 , int V_2 ,
struct V_49 * V_50 , const char * V_142 ,
int V_199 , struct V_7 * V_63 )
{
struct V_14 * V_14 = V_50 -> V_14 ;
struct V_59 * V_198 ;
struct V_118 * V_68 ;
struct V_40 * V_46 ;
unsigned long long V_158 , V_203 ;
unsigned long V_31 ;
char * V_62 ;
unsigned char * V_77 ;
int V_204 ;
int V_19 , V_132 ;
switch ( V_63 -> type ) {
case V_92 :
return;
case V_65 :
F_115 ( V_195 , V_142 , V_199 , V_63 -> V_66 . V_66 ) ;
return;
case V_67 :
V_68 = V_63 -> V_68 . V_68 ;
if ( ! V_68 ) {
V_68 = F_72 ( V_50 , V_63 -> V_68 . V_69 ) ;
if ( ! V_68 ) {
V_62 = V_63 -> V_68 . V_69 ;
goto V_193;
}
V_63 -> V_68 . V_68 = V_68 ;
}
V_132 = V_68 -> V_2 ? : V_2 - V_68 -> V_138 ;
if ( ! ( V_68 -> V_71 & V_119 ) &&
V_68 -> V_2 == V_14 -> V_141 ) {
V_31 = * ( unsigned long * ) ( V_175 + V_68 -> V_138 ) ;
V_46 = F_25 ( V_14 , V_31 ) ;
if ( V_46 )
F_119 ( V_195 , V_46 -> V_46 ) ;
else
F_116 ( V_195 , L_110 , V_31 ) ;
break;
}
V_62 = malloc ( V_132 + 1 ) ;
if ( ! V_62 ) {
F_61 ( V_50 , L_46 ,
V_128 ) ;
return;
}
memcpy ( V_62 , V_175 + V_68 -> V_138 , V_132 ) ;
V_62 [ V_132 ] = 0 ;
F_115 ( V_195 , V_142 , V_199 , V_62 ) ;
free ( V_62 ) ;
break;
case V_70 :
V_158 = F_109 ( V_175 , V_2 , V_50 , V_63 -> V_71 . V_68 ) ;
V_204 = 0 ;
for ( V_198 = V_63 -> V_71 . V_71 ; V_198 ; V_198 = V_198 -> V_22 ) {
V_203 = F_114 ( V_198 -> V_61 ) ;
if ( ! V_158 && ! V_203 ) {
F_115 ( V_195 , V_142 , V_199 , V_198 -> V_62 ) ;
break;
}
if ( V_203 && ( V_158 & V_203 ) == V_203 ) {
if ( V_204 && V_63 -> V_71 . V_72 )
F_119 ( V_195 , V_63 -> V_71 . V_72 ) ;
F_115 ( V_195 , V_142 , V_199 , V_198 -> V_62 ) ;
V_204 = 1 ;
V_158 &= ~ V_203 ;
}
}
break;
case V_73 :
V_158 = F_109 ( V_175 , V_2 , V_50 , V_63 -> V_74 . V_68 ) ;
for ( V_198 = V_63 -> V_74 . V_75 ; V_198 ; V_198 = V_198 -> V_22 ) {
V_203 = F_114 ( V_198 -> V_61 ) ;
if ( V_158 == V_203 ) {
F_115 ( V_195 , V_142 , V_199 , V_198 -> V_62 ) ;
break;
}
}
break;
case V_76 :
if ( V_63 -> V_77 . V_68 -> type == V_84 ) {
unsigned long V_138 ;
V_138 = F_94 ( V_14 ,
V_175 + V_63 -> V_77 . V_68 -> V_85 . V_68 -> V_138 ,
V_63 -> V_77 . V_68 -> V_85 . V_68 -> V_2 ) ;
V_77 = V_175 + ( V_138 & 0xffff ) ;
} else {
V_68 = V_63 -> V_77 . V_68 -> V_68 . V_68 ;
if ( ! V_68 ) {
V_62 = V_63 -> V_77 . V_68 -> V_68 . V_69 ;
V_68 = F_72 ( V_50 , V_62 ) ;
if ( ! V_68 )
goto V_193;
V_63 -> V_77 . V_68 -> V_68 . V_68 = V_68 ;
}
V_77 = V_175 + V_68 -> V_138 ;
}
V_132 = F_109 ( V_175 , V_2 , V_50 , V_63 -> V_77 . V_2 ) ;
for ( V_19 = 0 ; V_19 < V_132 ; V_19 ++ ) {
if ( V_19 )
F_120 ( V_195 , ' ' ) ;
F_116 ( V_195 , L_109 , V_77 [ V_19 ] ) ;
}
break;
case V_78 :
break;
case V_80 : {
int V_205 ;
if ( V_63 -> string . V_138 == - 1 ) {
struct V_118 * V_206 ;
V_206 = F_72 ( V_50 , V_63 -> string . string ) ;
V_63 -> string . V_138 = V_206 -> V_138 ;
}
V_205 = F_96 ( V_14 , V_175 + V_63 -> string . V_138 ) ;
V_205 &= 0xffff ;
F_115 ( V_195 , V_142 , V_199 , ( ( char * ) V_175 ) + V_205 ) ;
break;
}
case V_81 :
F_115 ( V_195 , V_142 , V_199 , V_63 -> string . string ) ;
break;
case V_82 : {
int V_207 ;
int V_208 ;
if ( V_63 -> V_83 . V_138 == - 1 ) {
struct V_118 * V_206 ;
V_206 = F_72 ( V_50 , V_63 -> V_83 . V_83 ) ;
V_63 -> V_83 . V_138 = V_206 -> V_138 ;
}
V_207 = F_96 ( V_14 , V_175 + V_63 -> V_83 . V_138 ) ;
V_208 = V_207 >> 16 ;
V_207 &= 0xffff ;
F_117 ( V_14 , V_195 , V_142 , V_199 ,
V_175 + V_207 , V_208 ) ;
break;
}
case V_87 :
if ( V_63 -> V_88 . V_88 [ 0 ] != '?' )
return;
V_158 = F_109 ( V_175 , V_2 , V_50 , V_63 -> V_88 . V_89 ) ;
if ( V_158 )
F_118 ( V_195 , V_175 , V_2 , V_50 ,
V_142 , V_199 , V_63 -> V_88 . V_90 -> V_88 . V_89 ) ;
else
F_118 ( V_195 , V_175 , V_2 , V_50 ,
V_142 , V_199 , V_63 -> V_88 . V_90 -> V_88 . V_90 ) ;
break;
case V_91 :
F_112 ( V_195 , V_175 , V_2 , V_50 , V_63 ) ;
break;
default:
break;
}
return;
V_193:
F_61 ( V_50 , L_108 ,
V_128 , V_63 -> V_68 . V_69 ) ;
}
static unsigned long long
F_112 ( struct V_194 * V_195 , void * V_175 , int V_2 ,
struct V_49 * V_50 , struct V_7 * V_63 )
{
struct V_166 * V_209 = V_63 -> V_35 . V_35 ;
struct V_210 * V_211 ;
unsigned long long * args ;
unsigned long long V_116 ;
struct V_7 * V_64 ;
struct V_194 V_62 ;
struct V_212 {
struct V_212 * V_22 ;
char * V_62 ;
} * V_213 = NULL , * string ;
int V_19 ;
if ( ! V_209 -> V_170 ) {
V_116 = (* V_209 -> V_35 )( V_195 , NULL ) ;
goto V_107;
}
V_64 = V_63 -> V_35 . args ;
V_211 = V_209 -> V_214 ;
V_116 = V_215 ;
args = malloc ( sizeof( * args ) * V_209 -> V_170 ) ;
if ( ! args )
goto V_107;
for ( V_19 = 0 ; V_19 < V_209 -> V_170 ; V_19 ++ ) {
switch ( V_211 -> type ) {
case V_216 :
case V_217 :
case V_218 :
args [ V_19 ] = F_109 ( V_175 , V_2 , V_50 , V_64 ) ;
break;
case V_219 :
F_111 ( & V_62 ) ;
F_118 ( & V_62 , V_175 , V_2 , V_50 , L_111 , - 1 , V_64 ) ;
F_121 ( & V_62 ) ;
string = malloc ( sizeof( * string ) ) ;
if ( ! string ) {
F_61 ( V_50 , L_112 ,
V_128 , __LINE__ ) ;
goto V_38;
}
string -> V_22 = V_213 ;
string -> V_62 = F_12 ( V_62 . V_220 ) ;
if ( ! string -> V_62 ) {
free ( string ) ;
F_61 ( V_50 , L_112 ,
V_128 , __LINE__ ) ;
goto V_38;
}
args [ V_19 ] = ( V_221 ) string -> V_62 ;
V_213 = string ;
F_113 ( & V_62 ) ;
break;
default:
F_61 ( V_50 , L_113 ) ;
goto V_38;
}
V_64 = V_64 -> V_22 ;
V_211 = V_211 -> V_22 ;
}
V_116 = (* V_209 -> V_35 )( V_195 , args ) ;
V_38:
free ( args ) ;
while ( V_213 ) {
string = V_213 ;
V_213 = string -> V_22 ;
free ( string -> V_62 ) ;
free ( string ) ;
}
V_107:
return V_116 ;
}
static void F_122 ( struct V_7 * args )
{
struct V_7 * V_22 ;
while ( args ) {
V_22 = args -> V_22 ;
F_32 ( args ) ;
args = V_22 ;
}
}
static struct V_7 * F_123 ( char * V_47 , void * V_175 , int V_2 , struct V_49 * V_50 )
{
struct V_14 * V_14 = V_50 -> V_14 ;
struct V_118 * V_68 , * V_222 ;
struct V_7 * args , * V_63 , * * V_22 ;
unsigned long long V_223 , V_158 ;
char * V_174 ;
void * V_224 ;
int V_225 ;
V_68 = V_14 -> V_226 ;
V_222 = V_14 -> V_227 ;
if ( ! V_68 ) {
V_68 = F_82 ( V_50 , L_114 ) ;
if ( ! V_68 ) {
F_61 ( V_50 , L_115 ) ;
return NULL ;
}
V_222 = F_82 ( V_50 , L_116 ) ;
if ( ! V_222 ) {
F_61 ( V_50 , L_117 ) ;
return NULL ;
}
V_14 -> V_226 = V_68 ;
V_14 -> V_227 = V_222 ;
}
V_223 = F_94 ( V_14 , V_175 + V_222 -> V_138 , V_222 -> V_2 ) ;
args = F_6 () ;
if ( ! args ) {
F_61 ( V_50 , L_118 ,
V_128 , __LINE__ ) ;
return NULL ;
}
V_63 = args ;
V_63 -> V_22 = NULL ;
V_22 = & V_63 -> V_22 ;
V_63 -> type = V_65 ;
if ( F_39 ( & V_63 -> V_66 . V_66 , L_80 , V_223 ) < 0 )
goto V_38;
for ( V_174 = V_47 + 5 , V_224 = V_175 + V_68 -> V_138 ;
V_224 < V_175 + V_2 && * V_174 ; V_174 ++ ) {
int V_228 = 0 ;
if ( * V_174 == '%' ) {
V_229:
V_174 ++ ;
switch ( * V_174 ) {
case '%' :
break;
case 'l' :
V_228 ++ ;
goto V_229;
case 'L' :
V_228 = 2 ;
goto V_229;
case '0' ... '9' :
goto V_229;
case '.' :
goto V_229;
case 'p' :
V_228 = 1 ;
case 'd' :
case 'u' :
case 'x' :
case 'i' :
switch ( V_228 ) {
case 0 :
V_225 = 4 ;
break;
case 1 :
V_225 = V_14 -> V_141 ;
break;
case 2 :
V_225 = 8 ;
break;
default:
V_225 = V_228 ;
break;
}
case '*' :
if ( * V_174 == '*' )
V_225 = 4 ;
V_224 = ( void * ) ( ( ( unsigned long ) V_224 + 3 ) &
~ 3 ) ;
V_158 = F_94 ( V_14 , V_224 , V_225 ) ;
V_224 += V_225 ;
V_63 = F_6 () ;
if ( ! V_63 ) {
F_61 ( V_50 , L_118 ,
V_128 , __LINE__ ) ;
goto V_38;
}
V_63 -> V_22 = NULL ;
V_63 -> type = V_65 ;
if ( F_39 ( & V_63 -> V_66 . V_66 , L_80 , V_158 ) < 0 ) {
free ( V_63 ) ;
goto V_38;
}
* V_22 = V_63 ;
V_22 = & V_63 -> V_22 ;
if ( * V_174 == '*' )
goto V_229;
break;
case 's' :
V_63 = F_6 () ;
if ( ! V_63 ) {
F_61 ( V_50 , L_118 ,
V_128 , __LINE__ ) ;
goto V_38;
}
V_63 -> V_22 = NULL ;
V_63 -> type = V_81 ;
V_63 -> string . string = F_12 ( V_224 ) ;
if ( ! V_63 -> string . string )
goto V_38;
V_224 += strlen ( V_224 ) + 1 ;
* V_22 = V_63 ;
V_22 = & V_63 -> V_22 ;
default:
break;
}
}
}
return args ;
V_38:
F_122 ( args ) ;
return NULL ;
}
static char *
F_124 ( void * V_175 , int V_2 V_152 ,
struct V_49 * V_50 )
{
struct V_14 * V_14 = V_50 -> V_14 ;
unsigned long long V_31 ;
struct V_118 * V_68 ;
struct V_40 * V_46 ;
char * V_142 ;
V_68 = V_14 -> V_230 ;
if ( ! V_68 ) {
V_68 = F_82 ( V_50 , L_98 ) ;
if ( ! V_68 ) {
F_61 ( V_50 , L_119 ) ;
return NULL ;
}
V_14 -> V_230 = V_68 ;
}
V_31 = F_94 ( V_14 , V_175 + V_68 -> V_138 , V_68 -> V_2 ) ;
V_46 = F_25 ( V_14 , V_31 ) ;
if ( ! V_46 ) {
if ( F_39 ( & V_142 , L_120 , V_31 ) < 0 )
return NULL ;
return V_142 ;
}
if ( F_39 ( & V_142 , L_121 , L_122 , V_46 -> V_46 ) < 0 )
return NULL ;
return V_142 ;
}
static void F_125 ( struct V_194 * V_195 , int V_231 , void * V_175 , int V_2 ,
struct V_49 * V_50 , struct V_7 * V_63 )
{
unsigned char * V_1 ;
const char * V_47 = L_123 ;
if ( V_63 -> type == V_91 ) {
F_112 ( V_195 , V_175 , V_2 , V_50 , V_63 ) ;
return;
}
if ( V_63 -> type != V_67 ) {
F_116 ( V_195 , L_124 ,
V_63 -> type ) ;
return;
}
if ( V_231 == 'm' )
V_47 = L_125 ;
if ( ! V_63 -> V_68 . V_68 ) {
V_63 -> V_68 . V_68 =
F_72 ( V_50 , V_63 -> V_68 . V_69 ) ;
if ( ! V_63 -> V_68 . V_68 ) {
F_61 ( V_50 , L_108 ,
V_128 , V_63 -> V_68 . V_69 ) ;
return;
}
}
if ( V_63 -> V_68 . V_68 -> V_2 != 6 ) {
F_116 ( V_195 , L_126 ) ;
return;
}
V_1 = V_175 + V_63 -> V_68 . V_68 -> V_138 ;
F_116 ( V_195 , V_47 , V_1 [ 0 ] , V_1 [ 1 ] , V_1 [ 2 ] , V_1 [ 3 ] , V_1 [ 4 ] , V_1 [ 5 ] ) ;
}
static void F_126 ( struct V_194 * V_195 , char V_19 , unsigned char * V_1 )
{
const char * V_47 ;
if ( V_19 == 'i' )
V_47 = L_127 ;
else
V_47 = L_128 ;
F_116 ( V_195 , V_47 , V_1 [ 0 ] , V_1 [ 1 ] , V_1 [ 2 ] , V_1 [ 3 ] ) ;
}
static inline bool F_127 ( const struct V_232 * V_8 )
{
return ( ( unsigned long ) ( V_8 -> V_233 [ 0 ] | V_8 -> V_233 [ 1 ] ) |
( unsigned long ) ( V_8 -> V_233 [ 2 ] ^ F_128 ( 0x0000ffff ) ) ) == 0UL ;
}
static inline bool F_129 ( const struct V_232 * V_31 )
{
return ( V_31 -> V_233 [ 2 ] | F_128 ( 0x02000000 ) ) == F_128 ( 0x02005EFE ) ;
}
static void F_130 ( struct V_194 * V_195 , unsigned char * V_31 )
{
int V_19 , V_234 , V_235 ;
unsigned char V_236 [ 8 ] ;
int V_237 = 1 ;
int V_238 = - 1 ;
T_1 V_239 ;
T_2 V_240 , V_241 ;
bool V_242 = false ;
bool V_243 ;
struct V_232 V_244 ;
memcpy ( & V_244 , V_31 , sizeof( struct V_232 ) ) ;
V_243 = F_127 ( & V_244 ) || F_129 ( & V_244 ) ;
memset ( V_236 , 0 , sizeof( V_236 ) ) ;
if ( V_243 )
V_235 = 6 ;
else
V_235 = 8 ;
for ( V_19 = 0 ; V_19 < V_235 ; V_19 ++ ) {
for ( V_234 = V_19 ; V_234 < V_235 ; V_234 ++ ) {
if ( V_244 . V_245 [ V_234 ] != 0 )
break;
V_236 [ V_19 ] ++ ;
}
}
for ( V_19 = 0 ; V_19 < V_235 ; V_19 ++ ) {
if ( V_236 [ V_19 ] > V_237 ) {
V_237 = V_236 [ V_19 ] ;
V_238 = V_19 ;
}
}
if ( V_237 == 1 )
V_238 = - 1 ;
for ( V_19 = 0 ; V_19 < V_235 ; V_19 ++ ) {
if ( V_19 == V_238 ) {
if ( V_242 || V_19 == 0 )
F_116 ( V_195 , L_19 ) ;
F_116 ( V_195 , L_19 ) ;
V_242 = false ;
V_19 += V_237 - 1 ;
continue;
}
if ( V_242 ) {
F_116 ( V_195 , L_19 ) ;
V_242 = false ;
}
V_239 = F_131 ( V_244 . V_245 [ V_19 ] ) ;
V_240 = V_239 >> 8 ;
V_241 = V_239 & 0xff ;
if ( V_240 )
F_116 ( V_195 , L_129 , V_240 , V_241 ) ;
else
F_116 ( V_195 , L_130 , V_241 ) ;
V_242 = true ;
}
if ( V_243 ) {
if ( V_242 )
F_116 ( V_195 , L_19 ) ;
F_126 ( V_195 , 'I' , & V_244 . V_246 [ 12 ] ) ;
}
return;
}
static void F_132 ( struct V_194 * V_195 , char V_19 , unsigned char * V_1 )
{
int V_234 ;
for ( V_234 = 0 ; V_234 < 16 ; V_234 += 2 ) {
F_116 ( V_195 , L_131 , V_1 [ V_234 ] , V_1 [ V_234 + 1 ] ) ;
if ( V_19 == 'I' && V_234 < 14 )
F_116 ( V_195 , L_19 ) ;
}
}
static int F_133 ( struct V_194 * V_195 , const char * V_174 , char V_19 ,
void * V_175 , int V_2 , struct V_49 * V_50 ,
struct V_7 * V_63 )
{
unsigned char * V_1 ;
if ( V_63 -> type == V_91 ) {
F_112 ( V_195 , V_175 , V_2 , V_50 , V_63 ) ;
return 0 ;
}
if ( V_63 -> type != V_67 ) {
F_116 ( V_195 , L_124 , V_63 -> type ) ;
return 0 ;
}
if ( ! V_63 -> V_68 . V_68 ) {
V_63 -> V_68 . V_68 =
F_72 ( V_50 , V_63 -> V_68 . V_69 ) ;
if ( ! V_63 -> V_68 . V_68 ) {
F_47 ( L_108 ,
V_128 , V_63 -> V_68 . V_69 ) ;
return 0 ;
}
}
V_1 = V_175 + V_63 -> V_68 . V_68 -> V_138 ;
if ( V_63 -> V_68 . V_68 -> V_2 != 4 ) {
F_116 ( V_195 , L_132 ) ;
return 0 ;
}
F_126 ( V_195 , V_19 , V_1 ) ;
return 0 ;
}
static int F_134 ( struct V_194 * V_195 , const char * V_174 , char V_19 ,
void * V_175 , int V_2 , struct V_49 * V_50 ,
struct V_7 * V_63 )
{
char V_247 = 0 ;
unsigned char * V_1 ;
int V_248 = 0 ;
if ( V_19 == 'I' && * V_174 == 'c' ) {
V_247 = 1 ;
V_174 ++ ;
V_248 ++ ;
}
if ( V_63 -> type == V_91 ) {
F_112 ( V_195 , V_175 , V_2 , V_50 , V_63 ) ;
return V_248 ;
}
if ( V_63 -> type != V_67 ) {
F_116 ( V_195 , L_124 , V_63 -> type ) ;
return V_248 ;
}
if ( ! V_63 -> V_68 . V_68 ) {
V_63 -> V_68 . V_68 =
F_72 ( V_50 , V_63 -> V_68 . V_69 ) ;
if ( ! V_63 -> V_68 . V_68 ) {
F_47 ( L_108 ,
V_128 , V_63 -> V_68 . V_69 ) ;
return V_248 ;
}
}
V_1 = V_175 + V_63 -> V_68 . V_68 -> V_138 ;
if ( V_63 -> V_68 . V_68 -> V_2 != 16 ) {
F_116 ( V_195 , L_133 ) ;
return V_248 ;
}
if ( V_247 )
F_130 ( V_195 , V_1 ) ;
else
F_132 ( V_195 , V_19 , V_1 ) ;
return V_248 ;
}
static int F_135 ( struct V_194 * V_195 , const char * V_174 , char V_19 ,
void * V_175 , int V_2 , struct V_49 * V_50 ,
struct V_7 * V_63 )
{
char V_247 = 0 , V_249 = 0 ;
unsigned char * V_1 ;
struct V_250 * V_251 ;
int V_248 = 0 ;
if ( V_19 == 'I' ) {
if ( * V_174 == 'p' ) {
V_249 = 1 ;
V_174 ++ ;
V_248 ++ ;
}
if ( * V_174 == 'c' ) {
V_247 = 1 ;
V_174 ++ ;
V_248 ++ ;
}
}
if ( V_63 -> type == V_91 ) {
F_112 ( V_195 , V_175 , V_2 , V_50 , V_63 ) ;
return V_248 ;
}
if ( V_63 -> type != V_67 ) {
F_116 ( V_195 , L_124 , V_63 -> type ) ;
return V_248 ;
}
if ( ! V_63 -> V_68 . V_68 ) {
V_63 -> V_68 . V_68 =
F_72 ( V_50 , V_63 -> V_68 . V_69 ) ;
if ( ! V_63 -> V_68 . V_68 ) {
F_47 ( L_108 ,
V_128 , V_63 -> V_68 . V_69 ) ;
return V_248 ;
}
}
V_251 = (struct V_250 * ) ( V_175 + V_63 -> V_68 . V_68 -> V_138 ) ;
if ( V_251 -> V_252 == V_253 ) {
struct V_254 * V_255 = (struct V_254 * ) V_251 ;
if ( V_63 -> V_68 . V_68 -> V_2 < sizeof( struct V_254 ) ) {
F_116 ( V_195 , L_132 ) ;
return V_248 ;
}
F_126 ( V_195 , V_19 , ( unsigned char * ) & V_255 -> V_256 ) ;
if ( V_249 )
F_116 ( V_195 , L_134 , F_131 ( V_255 -> V_257 ) ) ;
} else if ( V_251 -> V_252 == V_258 ) {
struct V_259 * V_260 = (struct V_259 * ) V_251 ;
if ( V_63 -> V_68 . V_68 -> V_2 < sizeof( struct V_259 ) ) {
F_116 ( V_195 , L_133 ) ;
return V_248 ;
}
if ( V_249 )
F_116 ( V_195 , L_38 ) ;
V_1 = ( unsigned char * ) & V_260 -> V_261 ;
if ( V_247 )
F_130 ( V_195 , V_1 ) ;
else
F_132 ( V_195 , V_19 , V_1 ) ;
if ( V_249 )
F_116 ( V_195 , L_135 , F_131 ( V_260 -> V_262 ) ) ;
}
return V_248 ;
}
static int F_136 ( struct V_194 * V_195 , const char * V_174 ,
void * V_175 , int V_2 , struct V_49 * V_50 ,
struct V_7 * V_63 )
{
char V_19 = * V_174 ;
char V_263 ;
int V_248 = 0 ;
V_174 ++ ;
V_248 ++ ;
V_263 = * V_174 ;
V_174 ++ ;
V_248 ++ ;
switch ( V_263 ) {
case '4' :
V_248 += F_133 ( V_195 , V_174 , V_19 , V_175 , V_2 , V_50 , V_63 ) ;
break;
case '6' :
V_248 += F_134 ( V_195 , V_174 , V_19 , V_175 , V_2 , V_50 , V_63 ) ;
break;
case 'S' :
V_248 += F_135 ( V_195 , V_174 , V_19 , V_175 , V_2 , V_50 , V_63 ) ;
break;
default:
return 0 ;
}
return V_248 ;
}
static int F_137 ( char * V_48 , unsigned int V_132 )
{
unsigned int V_19 ;
for ( V_19 = 0 ; V_19 < V_132 && V_48 [ V_19 ] ; V_19 ++ )
if ( ! isprint ( V_48 [ V_19 ] ) && ! isspace ( V_48 [ V_19 ] ) )
return 0 ;
return 1 ;
}
static void F_138 ( struct V_194 * V_195 , void * V_175 ,
int V_2 V_152 ,
struct V_49 * V_50 )
{
struct V_118 * V_68 ;
unsigned long long V_158 ;
unsigned int V_138 , V_132 , V_19 ;
V_68 = V_50 -> V_142 . V_121 ;
while ( V_68 ) {
F_116 ( V_195 , L_136 , V_68 -> V_69 ) ;
if ( V_68 -> V_71 & V_119 ) {
V_138 = V_68 -> V_138 ;
V_132 = V_68 -> V_2 ;
if ( V_68 -> V_71 & V_135 ) {
V_158 = F_94 ( V_50 -> V_14 , V_175 + V_138 , V_132 ) ;
V_138 = V_158 ;
V_132 = V_138 >> 16 ;
V_138 &= 0xffff ;
}
if ( V_68 -> V_71 & V_134 &&
F_137 ( V_175 + V_138 , V_132 ) ) {
F_116 ( V_195 , L_111 , ( char * ) V_175 + V_138 ) ;
} else {
F_119 ( V_195 , L_137 ) ;
for ( V_19 = 0 ; V_19 < V_132 ; V_19 ++ ) {
if ( V_19 )
F_119 ( V_195 , L_138 ) ;
F_116 ( V_195 , L_109 ,
* ( ( unsigned char * ) V_175 + V_138 + V_19 ) ) ;
}
F_120 ( V_195 , ']' ) ;
V_68 -> V_71 &= ~ V_134 ;
}
} else {
V_158 = F_94 ( V_50 -> V_14 , V_175 + V_68 -> V_138 ,
V_68 -> V_2 ) ;
if ( V_68 -> V_71 & V_126 ) {
F_116 ( V_195 , L_139 , V_158 ) ;
} else if ( V_68 -> V_71 & V_139 ) {
switch ( V_68 -> V_2 ) {
case 4 :
if ( V_68 -> V_71 & V_136 )
F_116 ( V_195 , L_140 , ( int ) V_158 ) ;
else
F_116 ( V_195 , L_141 , ( int ) V_158 ) ;
break;
case 2 :
F_116 ( V_195 , L_142 , ( short ) V_158 ) ;
break;
case 1 :
F_116 ( V_195 , L_143 , ( char ) V_158 ) ;
break;
default:
F_116 ( V_195 , L_80 , V_158 ) ;
}
} else {
if ( V_68 -> V_71 & V_136 )
F_116 ( V_195 , L_139 , V_158 ) ;
else
F_116 ( V_195 , L_144 , V_158 ) ;
}
}
V_68 = V_68 -> V_22 ;
}
}
static void F_139 ( struct V_194 * V_195 , void * V_175 , int V_2 , struct V_49 * V_50 )
{
struct V_14 * V_14 = V_50 -> V_14 ;
struct V_172 * V_172 = & V_50 -> V_172 ;
struct V_7 * V_63 = V_172 -> args ;
struct V_7 * args = NULL ;
const char * V_174 = V_172 -> V_142 ;
unsigned long long V_158 ;
struct V_28 * V_35 ;
const char * V_264 ;
struct V_194 V_48 ;
char * V_265 = NULL ;
char V_142 [ 32 ] ;
int V_266 ;
int V_267 ;
int V_199 ;
int V_132 ;
int V_228 ;
if ( V_50 -> V_71 & V_150 ) {
F_116 ( V_195 , L_145 ) ;
F_138 ( V_195 , V_175 , V_2 , V_50 ) ;
return;
}
if ( V_50 -> V_71 & V_268 ) {
V_265 = F_124 ( V_175 , V_2 , V_50 ) ;
args = F_123 ( V_265 , V_175 , V_2 , V_50 ) ;
V_63 = args ;
V_174 = V_265 ;
}
for (; * V_174 ; V_174 ++ ) {
V_228 = 0 ;
if ( * V_174 == '\\' ) {
V_174 ++ ;
switch ( * V_174 ) {
case 'n' :
F_120 ( V_195 , '\n' ) ;
break;
case 't' :
F_120 ( V_195 , '\t' ) ;
break;
case 'r' :
F_120 ( V_195 , '\r' ) ;
break;
case '\\' :
F_120 ( V_195 , '\\' ) ;
break;
default:
F_120 ( V_195 , * V_174 ) ;
break;
}
} else if ( * V_174 == '%' ) {
V_264 = V_174 ;
V_266 = 0 ;
V_267 = 0 ;
V_269:
V_174 ++ ;
switch ( * V_174 ) {
case '%' :
F_120 ( V_195 , '%' ) ;
break;
case '#' :
goto V_269;
case 'h' :
V_228 -- ;
goto V_269;
case 'l' :
V_228 ++ ;
goto V_269;
case 'L' :
V_228 = 2 ;
goto V_269;
case '*' :
if ( ! V_63 ) {
F_61 ( V_50 , L_146 ) ;
V_50 -> V_71 |= V_150 ;
goto V_270;
}
V_199 = F_109 ( V_175 , V_2 , V_50 , V_63 ) ;
V_267 = 1 ;
V_63 = V_63 -> V_22 ;
goto V_269;
case '.' :
case 'z' :
case 'Z' :
case '0' ... '9' :
goto V_269;
case 'p' :
if ( V_14 -> V_141 == 4 )
V_228 = 1 ;
else
V_228 = 2 ;
if ( * ( V_174 + 1 ) == 'F' ||
* ( V_174 + 1 ) == 'f' ) {
V_174 ++ ;
V_266 = * V_174 ;
} else if ( * ( V_174 + 1 ) == 'M' || * ( V_174 + 1 ) == 'm' ) {
F_125 ( V_195 , * ( V_174 + 1 ) , V_175 , V_2 , V_50 , V_63 ) ;
V_174 ++ ;
V_63 = V_63 -> V_22 ;
break;
} else if ( * ( V_174 + 1 ) == 'I' || * ( V_174 + 1 ) == 'i' ) {
int V_271 ;
V_271 = F_136 ( V_195 , V_174 + 1 , V_175 , V_2 , V_50 , V_63 ) ;
if ( V_271 > 0 ) {
V_174 += V_271 ;
V_63 = V_63 -> V_22 ;
break;
}
}
case 'd' :
case 'i' :
case 'x' :
case 'X' :
case 'u' :
if ( ! V_63 ) {
F_61 ( V_50 , L_146 ) ;
V_50 -> V_71 |= V_150 ;
goto V_270;
}
V_132 = ( ( unsigned long ) V_174 + 1 ) -
( unsigned long ) V_264 ;
if ( V_132 > 31 ) {
F_61 ( V_50 , L_147 ) ;
V_50 -> V_71 |= V_150 ;
V_132 = 31 ;
}
memcpy ( V_142 , V_264 , V_132 ) ;
V_142 [ V_132 ] = 0 ;
V_158 = F_109 ( V_175 , V_2 , V_50 , V_63 ) ;
V_63 = V_63 -> V_22 ;
if ( V_266 ) {
V_35 = F_18 ( V_14 , V_158 ) ;
if ( V_35 ) {
F_119 ( V_195 , V_35 -> V_35 ) ;
if ( V_266 == 'F' )
F_116 ( V_195 ,
L_148 ,
V_158 - V_35 -> V_31 ) ;
break;
}
}
if ( V_14 -> V_141 == 8 && V_228 &&
sizeof( long ) != 8 ) {
char * V_48 ;
V_228 = 2 ;
V_48 = strchr ( V_142 , 'l' ) ;
if ( V_48 )
memmove ( V_48 + 1 , V_48 , strlen ( V_48 ) + 1 ) ;
else if ( strcmp ( V_142 , L_149 ) == 0 )
strcpy ( V_142 , L_139 ) ;
}
switch ( V_228 ) {
case - 2 :
if ( V_267 )
F_116 ( V_195 , V_142 , V_199 , ( char ) V_158 ) ;
else
F_116 ( V_195 , V_142 , ( char ) V_158 ) ;
break;
case - 1 :
if ( V_267 )
F_116 ( V_195 , V_142 , V_199 , ( short ) V_158 ) ;
else
F_116 ( V_195 , V_142 , ( short ) V_158 ) ;
break;
case 0 :
if ( V_267 )
F_116 ( V_195 , V_142 , V_199 , ( int ) V_158 ) ;
else
F_116 ( V_195 , V_142 , ( int ) V_158 ) ;
break;
case 1 :
if ( V_267 )
F_116 ( V_195 , V_142 , V_199 , ( long ) V_158 ) ;
else
F_116 ( V_195 , V_142 , ( long ) V_158 ) ;
break;
case 2 :
if ( V_267 )
F_116 ( V_195 , V_142 , V_199 ,
( long long ) V_158 ) ;
else
F_116 ( V_195 , V_142 , ( long long ) V_158 ) ;
break;
default:
F_61 ( V_50 , L_150 , V_228 ) ;
V_50 -> V_71 |= V_150 ;
}
break;
case 's' :
if ( ! V_63 ) {
F_61 ( V_50 , L_151 ) ;
V_50 -> V_71 |= V_150 ;
goto V_270;
}
V_132 = ( ( unsigned long ) V_174 + 1 ) -
( unsigned long ) V_264 ;
if ( V_132 > 31 ) {
F_61 ( V_50 , L_147 ) ;
V_50 -> V_71 |= V_150 ;
V_132 = 31 ;
}
memcpy ( V_142 , V_264 , V_132 ) ;
V_142 [ V_132 ] = 0 ;
if ( ! V_267 )
V_199 = - 1 ;
F_111 ( & V_48 ) ;
F_118 ( & V_48 , V_175 , V_2 , V_50 ,
V_142 , V_199 , V_63 ) ;
F_121 ( & V_48 ) ;
F_119 ( V_195 , V_48 . V_220 ) ;
F_113 ( & V_48 ) ;
V_63 = V_63 -> V_22 ;
break;
default:
F_116 ( V_195 , L_152 , * V_174 ) ;
}
} else
F_120 ( V_195 , * V_174 ) ;
}
if ( V_50 -> V_71 & V_150 ) {
V_270:
F_116 ( V_195 , L_145 ) ;
}
if ( args ) {
F_122 ( args ) ;
free ( V_265 ) ;
}
}
void F_140 ( struct V_14 * V_14 ,
struct V_194 * V_195 , struct V_272 * V_273 )
{
static int V_274 = 1 ;
static int V_275 = 1 ;
static int V_276 ;
static int V_277 ;
unsigned int V_278 ;
unsigned int V_279 ;
int V_280 ;
int V_281 ;
int V_282 ;
int V_283 ;
void * V_175 = V_273 -> V_175 ;
V_278 = F_104 ( V_14 , V_175 ) ;
V_279 = F_103 ( V_14 , V_175 ) ;
if ( V_276 )
V_280 = F_105 ( V_14 , V_175 ) ;
else if ( V_274 ) {
V_280 = F_105 ( V_14 , V_175 ) ;
if ( V_280 < 0 )
V_274 = 0 ;
else
V_276 = 1 ;
}
if ( V_277 )
V_281 = F_106 ( V_14 , V_175 ) ;
else if ( V_275 ) {
V_281 = F_106 ( V_14 , V_175 ) ;
if ( V_281 < 0 )
V_275 = 0 ;
else
V_277 = 1 ;
}
V_282 = V_278 & V_284 ;
V_283 = V_278 & V_285 ;
F_116 ( V_195 , L_153 ,
( V_278 & V_286 ) ? 'd' :
( V_278 & V_287 ) ?
'X' : '.' ,
( V_278 & V_288 ) ?
'N' : '.' ,
( V_282 && V_283 ) ? 'H' :
V_282 ? 'h' : V_283 ? 's' : '.' ) ;
if ( V_279 )
F_116 ( V_195 , L_130 , V_279 ) ;
else
F_120 ( V_195 , '.' ) ;
if ( V_277 ) {
if ( V_281 < 0 )
F_120 ( V_195 , '.' ) ;
else
F_116 ( V_195 , L_141 , V_281 ) ;
}
if ( V_276 ) {
if ( V_280 < 0 )
F_120 ( V_195 , '.' ) ;
else
F_116 ( V_195 , L_141 , V_280 ) ;
}
F_121 ( V_195 ) ;
}
int F_141 ( struct V_14 * V_14 , struct V_272 * V_289 )
{
return F_101 ( V_14 , V_289 -> V_175 ) ;
}
struct V_49 * F_142 ( struct V_14 * V_14 , int type )
{
return F_107 ( V_14 , type ) ;
}
int F_143 ( struct V_14 * V_14 , struct V_272 * V_289 )
{
return F_102 ( V_14 , V_289 -> V_175 ) ;
}
const char * F_144 ( struct V_14 * V_14 , int V_13 )
{
const char * V_21 ;
V_21 = F_9 ( V_14 , V_13 ) ;
return V_21 ;
}
void F_145 ( struct V_194 * V_195 , struct V_49 * V_50 ,
struct V_272 * V_273 )
{
int V_290 = 1 ;
if ( V_50 -> V_14 -> V_291 || ( V_50 -> V_71 & V_292 ) )
F_138 ( V_195 , V_273 -> V_175 , V_273 -> V_2 , V_50 ) ;
else {
if ( V_50 -> V_293 && ! ( V_50 -> V_71 & V_294 ) )
V_290 = V_50 -> V_293 ( V_195 , V_273 , V_50 ,
V_50 -> V_295 ) ;
if ( V_290 )
F_139 ( V_195 , V_273 -> V_175 , V_273 -> V_2 , V_50 ) ;
}
F_121 ( V_195 ) ;
}
static bool F_146 ( char * V_27 , bool V_296 )
{
if ( ! V_296 )
return true ;
if ( ! strcmp ( V_27 , L_154 ) || ! strcmp ( V_27 , L_155 )
|| ! strcmp ( V_27 , L_156 ) || ! strcmp ( V_27 , L_157 ) )
return true ;
return false ;
}
void F_147 ( struct V_14 * V_14 , struct V_194 * V_195 ,
struct V_272 * V_273 , bool V_296 )
{
static const char * V_297 = L_158 ;
struct V_49 * V_50 ;
unsigned long V_298 ;
unsigned long V_299 ;
unsigned long V_300 ;
const char * V_21 ;
void * V_175 = V_273 -> V_175 ;
int type ;
int V_13 ;
int V_132 ;
int V_48 ;
bool V_301 ;
V_301 = F_146 ( V_14 -> V_27 ,
V_296 ) ;
if ( V_301 ) {
V_298 = V_273 -> V_302 / V_303 ;
V_300 = V_273 -> V_302 - V_298 * V_303 ;
}
if ( V_273 -> V_2 < 0 ) {
F_47 ( L_159 , V_273 -> V_2 ) ;
return;
}
type = F_101 ( V_14 , V_175 ) ;
V_50 = F_107 ( V_14 , type ) ;
if ( ! V_50 ) {
F_47 ( L_160 , type ) ;
return;
}
V_13 = F_102 ( V_14 , V_175 ) ;
V_21 = F_9 ( V_14 , V_13 ) ;
if ( V_14 -> V_304 ) {
F_116 ( V_195 , L_161 ,
V_21 , V_13 , V_273 -> V_305 ) ;
F_140 ( V_14 , V_195 , V_273 ) ;
} else
F_116 ( V_195 , L_162 , V_21 , V_13 , V_273 -> V_305 ) ;
if ( V_301 ) {
if ( V_14 -> V_71 & V_306 ) {
V_299 = V_300 ;
V_48 = 9 ;
} else {
V_299 = ( V_300 + 500 ) / V_307 ;
V_48 = 6 ;
}
F_116 ( V_195 , L_163 ,
V_298 , V_48 , V_299 , V_50 -> V_69 ) ;
} else
F_116 ( V_195 , L_164 ,
V_273 -> V_302 , V_50 -> V_69 ) ;
V_132 = strlen ( V_50 -> V_69 ) ;
if ( V_132 < 20 )
F_116 ( V_195 , L_165 , 20 - V_132 , V_297 ) ;
F_145 ( V_195 , V_50 , V_273 ) ;
}
static int V_188 ( const void * V_8 , const void * V_9 )
{
struct V_49 * const * V_308 = V_8 ;
struct V_49 * const * V_309 = V_9 ;
if ( ( * V_308 ) -> V_53 < ( * V_309 ) -> V_53 )
return - 1 ;
if ( ( * V_308 ) -> V_53 > ( * V_309 ) -> V_53 )
return 1 ;
return 0 ;
}
static int F_148 ( const void * V_8 , const void * V_9 )
{
struct V_49 * const * V_308 = V_8 ;
struct V_49 * const * V_309 = V_9 ;
int V_310 ;
V_310 = strcmp ( ( * V_308 ) -> V_69 , ( * V_309 ) -> V_69 ) ;
if ( V_310 )
return V_310 ;
V_310 = strcmp ( ( * V_308 ) -> system , ( * V_309 ) -> system ) ;
if ( V_310 )
return V_310 ;
return V_188 ( V_8 , V_9 ) ;
}
static int F_149 ( const void * V_8 , const void * V_9 )
{
struct V_49 * const * V_308 = V_8 ;
struct V_49 * const * V_309 = V_9 ;
int V_310 ;
V_310 = strcmp ( ( * V_308 ) -> system , ( * V_309 ) -> system ) ;
if ( V_310 )
return V_310 ;
V_310 = strcmp ( ( * V_308 ) -> V_69 , ( * V_309 ) -> V_69 ) ;
if ( V_310 )
return V_310 ;
return V_188 ( V_8 , V_9 ) ;
}
struct V_49 * * F_150 ( struct V_14 * V_14 , enum V_311 V_312 )
{
struct V_49 * * V_51 ;
int (* F_151)( const void * V_8 , const void * V_9 );
V_51 = V_14 -> V_313 ;
if ( V_51 && V_14 -> V_129 == V_312 )
return V_51 ;
if ( ! V_51 ) {
V_51 = malloc ( sizeof( * V_51 ) * ( V_14 -> V_52 + 1 ) ) ;
if ( ! V_51 )
return NULL ;
memcpy ( V_51 , V_14 -> V_51 , sizeof( * V_51 ) * V_14 -> V_52 ) ;
V_51 [ V_14 -> V_52 ] = NULL ;
V_14 -> V_313 = V_51 ;
if ( V_312 == V_314 ) {
V_14 -> V_129 = V_312 ;
return V_51 ;
}
}
switch ( V_312 ) {
case V_314 :
F_151 = V_188 ;
break;
case V_315 :
F_151 = F_148 ;
break;
case V_316 :
F_151 = F_149 ;
break;
default:
return V_51 ;
}
qsort ( V_51 , V_14 -> V_52 , sizeof( * V_51 ) , F_151 ) ;
V_14 -> V_129 = V_312 ;
return V_51 ;
}
static struct V_118 * *
F_152 ( const char * type , const char * V_69 ,
int V_123 , struct V_118 * V_162 )
{
struct V_118 * * V_121 ;
struct V_118 * V_68 ;
int V_19 = 0 ;
V_121 = malloc ( sizeof( * V_121 ) * ( V_123 + 1 ) ) ;
if ( ! V_121 )
return NULL ;
for ( V_68 = V_162 ; V_68 ; V_68 = V_68 -> V_22 ) {
V_121 [ V_19 ++ ] = V_68 ;
if ( V_19 == V_123 + 1 ) {
F_47 ( L_166 ,
V_69 , type ) ;
V_19 -- ;
break;
}
}
if ( V_19 != V_123 )
F_47 ( L_167 ,
V_69 , type ) ;
V_121 [ V_19 ] = NULL ;
return V_121 ;
}
struct V_118 * * F_153 ( struct V_49 * V_50 )
{
return F_152 ( L_168 , V_50 -> V_69 ,
V_50 -> V_142 . V_144 ,
V_50 -> V_142 . V_143 ) ;
}
struct V_118 * * F_154 ( struct V_49 * V_50 )
{
return F_152 ( L_169 , V_50 -> V_69 ,
V_50 -> V_142 . V_145 ,
V_50 -> V_142 . V_121 ) ;
}
static void F_155 ( struct V_194 * V_195 , struct V_59 * V_68 )
{
F_116 ( V_195 , L_170 , V_68 -> V_61 , V_68 -> V_62 ) ;
if ( V_68 -> V_22 ) {
F_119 ( V_195 , L_138 ) ;
F_155 ( V_195 , V_68 -> V_22 ) ;
}
}
static void F_156 ( struct V_7 * args )
{
int V_317 = 1 ;
struct V_194 V_195 ;
switch ( args -> type ) {
case V_92 :
printf ( L_171 ) ;
break;
case V_65 :
printf ( L_111 , args -> V_66 . V_66 ) ;
break;
case V_67 :
printf ( L_172 , args -> V_68 . V_69 ) ;
break;
case V_70 :
printf ( L_173 ) ;
F_156 ( args -> V_71 . V_68 ) ;
printf ( L_174 , args -> V_71 . V_72 ) ;
F_111 ( & V_195 ) ;
F_155 ( & V_195 , args -> V_71 . V_71 ) ;
F_157 ( & V_195 ) ;
F_113 ( & V_195 ) ;
printf ( L_69 ) ;
break;
case V_73 :
printf ( L_175 ) ;
F_156 ( args -> V_74 . V_68 ) ;
printf ( L_138 ) ;
F_111 ( & V_195 ) ;
F_155 ( & V_195 , args -> V_74 . V_75 ) ;
F_157 ( & V_195 ) ;
F_113 ( & V_195 ) ;
printf ( L_69 ) ;
break;
case V_76 :
printf ( L_176 ) ;
F_156 ( args -> V_77 . V_68 ) ;
printf ( L_138 ) ;
F_156 ( args -> V_77 . V_2 ) ;
printf ( L_69 ) ;
break;
case V_80 :
case V_81 :
printf ( L_177 , args -> string . string ) ;
break;
case V_82 :
printf ( L_178 , args -> V_83 . V_83 ) ;
break;
case V_78 :
printf ( L_179 , args -> V_79 . type ) ;
F_156 ( args -> V_79 . V_17 ) ;
break;
case V_87 :
if ( strcmp ( args -> V_88 . V_88 , L_19 ) == 0 )
V_317 = 0 ;
if ( V_317 )
printf ( L_84 ) ;
F_156 ( args -> V_88 . V_89 ) ;
printf ( L_180 , args -> V_88 . V_88 ) ;
F_156 ( args -> V_88 . V_90 ) ;
if ( V_317 )
printf ( L_69 ) ;
break;
default:
return;
}
if ( args -> V_22 ) {
printf ( L_6 ) ;
F_156 ( args -> V_22 ) ;
}
}
static void F_158 ( const char * V_68 ,
int * V_138 , int * V_2 , int V_318 )
{
unsigned long long V_109 ;
unsigned long long V_111 ;
char * V_112 ;
int type ;
V_109 = V_5 ;
V_111 = V_4 ;
if ( F_52 ( V_55 , L_32 ) < 0 )
return;
if ( F_52 ( V_98 , L_19 ) < 0 )
return;
if ( F_50 ( V_55 , & V_112 ) < 0 )
goto V_117;
F_41 ( V_112 ) ;
if ( V_318 ) {
if ( F_52 ( V_55 , V_68 ) < 0 )
return;
} else {
if ( F_50 ( V_55 , & V_112 ) < 0 )
goto V_117;
if ( strcmp ( V_112 , V_68 ) != 0 )
goto V_319;
F_41 ( V_112 ) ;
}
if ( F_52 ( V_98 , L_41 ) < 0 )
return;
if ( F_52 ( V_55 , L_42 ) < 0 )
return;
if ( F_52 ( V_98 , L_19 ) < 0 )
return;
if ( F_50 ( V_55 , & V_112 ) < 0 )
goto V_117;
* V_138 = atoi ( V_112 ) ;
F_41 ( V_112 ) ;
if ( F_52 ( V_98 , L_41 ) < 0 )
return;
if ( F_52 ( V_55 , L_43 ) < 0 )
return;
if ( F_52 ( V_98 , L_19 ) < 0 )
return;
if ( F_50 ( V_55 , & V_112 ) < 0 )
goto V_117;
* V_2 = atoi ( V_112 ) ;
F_41 ( V_112 ) ;
if ( F_52 ( V_98 , L_41 ) < 0 )
return;
type = F_42 ( & V_112 ) ;
if ( type != V_94 ) {
if ( type != V_55 )
goto V_117;
if ( strcmp ( V_112 , L_44 ) != 0 )
goto V_117;
F_41 ( V_112 ) ;
if ( F_52 ( V_98 , L_19 ) < 0 )
return;
if ( F_50 ( V_55 , & V_112 ) )
goto V_117;
F_41 ( V_112 ) ;
if ( F_52 ( V_98 , L_41 ) < 0 )
return;
if ( F_50 ( V_94 , & V_112 ) )
goto V_117;
}
V_117:
F_41 ( V_112 ) ;
return;
V_319:
V_5 = V_109 ;
V_4 = V_111 ;
* V_138 = 0 ;
* V_2 = 0 ;
F_41 ( V_112 ) ;
}
int F_159 ( struct V_14 * V_14 , char * V_1 , unsigned long V_2 ,
int V_141 )
{
int V_320 ;
if ( ! V_2 ) {
V_14 -> V_321 = sizeof( long long ) ;
V_14 -> V_322 = V_141 ;
V_14 -> V_323 = sizeof( long long ) + V_141 ;
V_14 -> V_324 = 1 ;
return - 1 ;
}
F_1 ( V_1 , V_2 ) ;
F_158 ( L_181 , & V_14 -> V_325 ,
& V_14 -> V_321 , 1 ) ;
F_158 ( L_182 , & V_14 -> V_326 ,
& V_14 -> V_322 , 1 ) ;
F_158 ( L_183 , & V_14 -> V_327 ,
& V_320 , 0 ) ;
F_158 ( L_184 , & V_14 -> V_323 ,
& V_14 -> V_328 , 1 ) ;
return 0 ;
}
static int F_160 ( struct V_49 * V_50 ,
int V_53 , const char * V_329 ,
const char * V_330 )
{
if ( V_53 >= 0 && V_53 != V_50 -> V_53 )
return 0 ;
if ( V_330 && ( strcmp ( V_330 , V_50 -> V_69 ) != 0 ) )
return 0 ;
if ( V_329 && ( strcmp ( V_329 , V_50 -> system ) != 0 ) )
return 0 ;
return 1 ;
}
static void F_161 ( struct V_331 * V_332 )
{
free ( ( void * ) V_332 -> V_329 ) ;
free ( ( void * ) V_332 -> V_330 ) ;
free ( V_332 ) ;
}
static int F_162 ( struct V_14 * V_14 , struct V_49 * V_50 )
{
struct V_331 * V_332 , * * V_22 ;
for ( V_22 = & V_14 -> V_333 ; * V_22 ;
V_22 = & ( * V_22 ) -> V_22 ) {
V_332 = * V_22 ;
if ( F_160 ( V_50 , V_332 -> V_53 ,
V_332 -> V_329 ,
V_332 -> V_330 ) )
break;
}
if ( ! ( * V_22 ) )
return 0 ;
F_163 ( L_185 ,
V_50 -> V_53 , V_50 -> system , V_50 -> V_69 ) ;
V_50 -> V_293 = V_332 -> V_35 ;
V_50 -> V_295 = V_332 -> V_295 ;
* V_22 = V_332 -> V_22 ;
F_161 ( V_332 ) ;
return 1 ;
}
enum V_334 F_164 ( struct V_49 * * V_335 ,
struct V_14 * V_14 , const char * V_1 ,
unsigned long V_2 , const char * V_189 )
{
struct V_49 * V_50 ;
int V_116 ;
F_1 ( V_1 , V_2 ) ;
* V_335 = V_50 = F_28 () ;
if ( ! V_50 )
return V_336 ;
V_50 -> V_69 = F_54 () ;
if ( ! V_50 -> V_69 ) {
V_116 = V_336 ;
goto V_337;
}
if ( strcmp ( V_189 , L_186 ) == 0 ) {
V_50 -> V_71 |= V_125 ;
if ( strcmp ( V_50 -> V_69 , L_187 ) == 0 )
V_50 -> V_71 |= V_268 ;
}
V_50 -> V_53 = F_55 () ;
if ( V_50 -> V_53 < 0 ) {
V_116 = V_338 ;
goto V_337;
}
V_50 -> system = F_12 ( V_189 ) ;
if ( ! V_50 -> system ) {
V_116 = V_336 ;
goto V_337;
}
V_50 -> V_14 = V_14 ;
V_116 = F_62 ( V_50 ) ;
if ( V_116 < 0 ) {
V_116 = V_339 ;
goto V_340;
}
if ( V_14 && F_162 ( V_14 , V_50 ) )
V_341 = 0 ;
V_116 = F_92 ( V_50 ) ;
V_341 = 1 ;
if ( V_116 < 0 ) {
V_116 = V_342 ;
goto V_340;
}
if ( ! V_116 && ( V_50 -> V_71 & V_125 ) ) {
struct V_118 * V_68 ;
struct V_7 * V_63 , * * V_162 ;
V_162 = & V_50 -> V_172 . args ;
for ( V_68 = V_50 -> V_142 . V_121 ; V_68 ; V_68 = V_68 -> V_22 ) {
V_63 = F_6 () ;
if ( ! V_63 ) {
V_50 -> V_71 |= V_150 ;
return V_343 ;
}
V_63 -> type = V_67 ;
V_63 -> V_68 . V_69 = F_12 ( V_68 -> V_69 ) ;
if ( ! V_63 -> V_68 . V_69 ) {
V_50 -> V_71 |= V_150 ;
F_32 ( V_63 ) ;
return V_343 ;
}
V_63 -> V_68 . V_68 = V_68 ;
* V_162 = V_63 ;
V_162 = & V_63 -> V_22 ;
}
return 0 ;
}
return 0 ;
V_340:
V_50 -> V_71 |= V_150 ;
return V_116 ;
V_337:
free ( V_50 -> system ) ;
free ( V_50 -> V_69 ) ;
free ( V_50 ) ;
* V_335 = NULL ;
return V_116 ;
}
static enum V_334
F_165 ( struct V_14 * V_14 ,
struct V_49 * * V_335 ,
const char * V_1 , unsigned long V_2 ,
const char * V_189 )
{
int V_116 = F_164 ( V_335 , V_14 , V_1 , V_2 , V_189 ) ;
struct V_49 * V_50 = * V_335 ;
if ( V_50 == NULL )
return V_116 ;
if ( V_14 && F_29 ( V_14 , V_50 ) ) {
V_116 = V_336 ;
goto V_344;
}
#define F_166 0
if ( F_166 && V_50 -> V_172 . args )
F_156 ( V_50 -> V_172 . args ) ;
return 0 ;
V_344:
F_167 ( V_50 ) ;
return V_116 ;
}
enum V_334 F_168 ( struct V_14 * V_14 ,
struct V_49 * * V_335 ,
const char * V_1 ,
unsigned long V_2 , const char * V_189 )
{
return F_165 ( V_14 , V_335 , V_1 , V_2 , V_189 ) ;
}
enum V_334 F_169 ( struct V_14 * V_14 , const char * V_1 ,
unsigned long V_2 , const char * V_189 )
{
struct V_49 * V_50 = NULL ;
return F_165 ( V_14 , & V_50 , V_1 , V_2 , V_189 ) ;
}
int F_170 ( struct V_14 * V_14 V_152 ,
enum V_334 V_345 , char * V_1 , T_3 V_346 )
{
int V_347 ;
const char * V_348 ;
if ( V_345 >= 0 ) {
V_348 = F_171 ( V_345 , V_1 , V_346 ) ;
if ( V_348 != V_1 ) {
T_3 V_132 = strlen ( V_348 ) ;
memcpy ( V_1 , V_348 , F_172 ( V_346 - 1 , V_132 ) ) ;
* ( V_1 + F_172 ( V_346 - 1 , V_132 ) ) = '\0' ;
}
return 0 ;
}
if ( V_345 <= V_349 ||
V_345 >= V_350 )
return - 1 ;
V_347 = V_345 - V_349 - 1 ;
V_348 = V_351 [ V_347 ] ;
snprintf ( V_1 , V_346 , L_111 , V_348 ) ;
return 0 ;
}
int F_173 ( struct V_194 * V_195 , struct V_118 * V_68 ,
const char * V_69 , struct V_272 * V_273 ,
unsigned long long * V_158 , int V_171 )
{
if ( ! V_68 ) {
if ( V_171 )
F_116 ( V_195 , L_188 , V_69 ) ;
return - 1 ;
}
if ( F_98 ( V_68 , V_273 -> V_175 , V_158 ) ) {
if ( V_171 )
F_116 ( V_195 , L_189 , V_69 ) ;
return - 1 ;
}
return 0 ;
}
void * F_174 ( struct V_194 * V_195 , struct V_49 * V_50 ,
const char * V_69 , struct V_272 * V_273 ,
int * V_132 , int V_171 )
{
struct V_118 * V_68 ;
void * V_175 = V_273 -> V_175 ;
unsigned V_138 ;
int V_352 ;
if ( ! V_50 )
return NULL ;
V_68 = F_82 ( V_50 , V_69 ) ;
if ( ! V_68 ) {
if ( V_171 )
F_116 ( V_195 , L_188 , V_69 ) ;
return NULL ;
}
if ( ! V_132 )
V_132 = & V_352 ;
V_138 = V_68 -> V_138 ;
if ( V_68 -> V_71 & V_135 ) {
V_138 = F_94 ( V_50 -> V_14 ,
V_175 + V_138 , V_68 -> V_2 ) ;
* V_132 = V_138 >> 16 ;
V_138 &= 0xffff ;
} else
* V_132 = V_68 -> V_2 ;
return V_175 + V_138 ;
}
int F_175 ( struct V_194 * V_195 , struct V_49 * V_50 ,
const char * V_69 , struct V_272 * V_273 ,
unsigned long long * V_158 , int V_171 )
{
struct V_118 * V_68 ;
if ( ! V_50 )
return - 1 ;
V_68 = F_82 ( V_50 , V_69 ) ;
return F_173 ( V_195 , V_68 , V_69 , V_273 , V_158 , V_171 ) ;
}
int F_176 ( struct V_194 * V_195 , struct V_49 * V_50 ,
const char * V_69 , struct V_272 * V_273 ,
unsigned long long * V_158 , int V_171 )
{
struct V_118 * V_68 ;
if ( ! V_50 )
return - 1 ;
V_68 = F_93 ( V_50 , V_69 ) ;
return F_173 ( V_195 , V_68 , V_69 , V_273 , V_158 , V_171 ) ;
}
int F_177 ( struct V_194 * V_195 , struct V_49 * V_50 ,
const char * V_69 , struct V_272 * V_273 ,
unsigned long long * V_158 , int V_171 )
{
struct V_118 * V_68 ;
if ( ! V_50 )
return - 1 ;
V_68 = F_72 ( V_50 , V_69 ) ;
return F_173 ( V_195 , V_68 , V_69 , V_273 , V_158 , V_171 ) ;
}
int F_178 ( struct V_194 * V_195 , const char * V_47 ,
struct V_49 * V_50 , const char * V_69 ,
struct V_272 * V_273 , int V_171 )
{
struct V_118 * V_68 = F_82 ( V_50 , V_69 ) ;
unsigned long long V_158 ;
if ( ! V_68 )
goto V_353;
if ( F_98 ( V_68 , V_273 -> V_175 , & V_158 ) )
goto V_353;
return F_116 ( V_195 , V_47 , V_158 ) ;
V_353:
if ( V_171 )
F_116 ( V_195 , L_190 , V_69 ) ;
return - 1 ;
}
int F_179 ( struct V_194 * V_195 , const char * V_47 ,
struct V_49 * V_50 , const char * V_69 ,
struct V_272 * V_273 , int V_171 )
{
struct V_118 * V_68 = F_82 ( V_50 , V_69 ) ;
struct V_14 * V_14 = V_50 -> V_14 ;
unsigned long long V_158 ;
struct V_28 * V_35 ;
char V_354 [ 128 ] ;
if ( ! V_68 )
goto V_353;
if ( F_98 ( V_68 , V_273 -> V_175 , & V_158 ) )
goto V_353;
V_35 = F_18 ( V_14 , V_158 ) ;
if ( V_35 )
snprintf ( V_354 , 128 , L_191 , V_35 -> V_35 , V_35 -> V_31 - V_158 ) ;
else
sprintf ( V_354 , L_192 , V_158 ) ;
return F_116 ( V_195 , V_47 , V_354 ) ;
V_353:
if ( V_171 )
F_116 ( V_195 , L_190 , V_69 ) ;
return - 1 ;
}
static void F_88 ( struct V_166 * V_35 )
{
struct V_210 * V_214 ;
free ( V_35 -> V_69 ) ;
while ( V_35 -> V_214 ) {
V_214 = V_35 -> V_214 ;
V_35 -> V_214 = V_214 -> V_22 ;
free ( V_214 ) ;
}
free ( V_35 ) ;
}
int F_180 ( struct V_14 * V_14 ,
T_4 V_35 ,
enum V_355 V_356 ,
char * V_69 , ... )
{
struct V_166 * V_209 ;
struct V_210 * * V_357 ;
struct V_210 * V_211 ;
enum V_355 type ;
T_5 V_358 ;
int V_116 ;
V_209 = F_86 ( V_14 , V_69 ) ;
if ( V_209 ) {
F_163 ( L_193 , V_69 ) ;
F_87 ( V_14 , V_69 ) ;
}
V_209 = calloc ( 1 , sizeof( * V_209 ) ) ;
if ( ! V_209 ) {
F_47 ( L_194 ) ;
return V_336 ;
}
V_209 -> V_356 = V_356 ;
V_209 -> V_69 = F_12 ( V_69 ) ;
V_209 -> V_35 = V_35 ;
if ( ! V_209 -> V_69 ) {
F_47 ( L_195 ) ;
free ( V_209 ) ;
return V_336 ;
}
V_357 = & ( V_209 -> V_214 ) ;
va_start ( V_358 , V_69 ) ;
for (; ; ) {
type = va_arg ( V_358 , enum V_355 ) ;
if ( type == V_359 )
break;
if ( type >= V_360 ) {
F_47 ( L_196 , type ) ;
V_116 = V_361 ;
goto V_38;
}
V_211 = malloc ( sizeof( * V_211 ) ) ;
if ( ! V_211 ) {
F_47 ( L_197 ) ;
V_116 = V_336 ;
goto V_38;
}
V_211 -> type = type ;
V_211 -> V_22 = NULL ;
* V_357 = V_211 ;
V_357 = & ( V_211 -> V_22 ) ;
V_209 -> V_170 ++ ;
}
va_end ( V_358 ) ;
V_209 -> V_22 = V_14 -> V_168 ;
V_14 -> V_168 = V_209 ;
return 0 ;
V_38:
va_end ( V_358 ) ;
F_88 ( V_209 ) ;
return V_116 ;
}
int F_181 ( struct V_14 * V_14 ,
T_4 V_35 , char * V_69 )
{
struct V_166 * V_209 ;
V_209 = F_86 ( V_14 , V_69 ) ;
if ( V_209 && V_209 -> V_35 == V_35 ) {
F_87 ( V_14 , V_69 ) ;
return 0 ;
}
return - 1 ;
}
static struct V_49 * F_182 ( struct V_14 * V_14 , int V_53 ,
const char * V_329 ,
const char * V_330 )
{
struct V_49 * V_50 ;
if ( V_53 >= 0 ) {
V_50 = F_107 ( V_14 , V_53 ) ;
if ( ! V_50 )
return NULL ;
if ( V_330 && ( strcmp ( V_330 , V_50 -> V_69 ) != 0 ) )
return NULL ;
if ( V_329 && ( strcmp ( V_329 , V_50 -> system ) != 0 ) )
return NULL ;
} else {
V_50 = F_108 ( V_14 , V_329 , V_330 ) ;
if ( ! V_50 )
return NULL ;
}
return V_50 ;
}
int F_183 ( struct V_14 * V_14 , int V_53 ,
const char * V_329 , const char * V_330 ,
T_6 V_35 , void * V_295 )
{
struct V_49 * V_50 ;
struct V_331 * V_332 ;
V_50 = F_182 ( V_14 , V_53 , V_329 , V_330 ) ;
if ( V_50 == NULL )
goto V_362;
F_163 ( L_185 ,
V_50 -> V_53 , V_50 -> system , V_50 -> V_69 ) ;
V_50 -> V_293 = V_35 ;
V_50 -> V_295 = V_295 ;
return 0 ;
V_362:
V_332 = calloc ( 1 , sizeof( * V_332 ) ) ;
if ( ! V_332 ) {
F_47 ( L_198 ) ;
return V_336 ;
}
V_332 -> V_53 = V_53 ;
if ( V_330 )
V_332 -> V_330 = F_12 ( V_330 ) ;
if ( V_329 )
V_332 -> V_329 = F_12 ( V_329 ) ;
if ( ( V_330 && ! V_332 -> V_330 ) ||
( V_329 && ! V_332 -> V_329 ) ) {
F_47 ( L_199 ) ;
free ( ( void * ) V_332 -> V_330 ) ;
free ( ( void * ) V_332 -> V_329 ) ;
free ( V_332 ) ;
return V_336 ;
}
V_332 -> V_35 = V_35 ;
V_332 -> V_22 = V_14 -> V_333 ;
V_14 -> V_333 = V_332 ;
V_332 -> V_295 = V_295 ;
return - 1 ;
}
static int F_184 ( struct V_331 * V_293 , int V_53 ,
const char * V_329 , const char * V_330 ,
T_6 V_35 , void * V_295 )
{
if ( V_53 >= 0 && V_53 != V_293 -> V_53 )
return 0 ;
if ( V_330 && ( strcmp ( V_330 , V_293 -> V_330 ) != 0 ) )
return 0 ;
if ( V_329 && ( strcmp ( V_329 , V_293 -> V_329 ) != 0 ) )
return 0 ;
if ( V_35 != V_293 -> V_35 || V_295 != V_293 -> V_295 )
return 0 ;
return 1 ;
}
int F_185 ( struct V_14 * V_14 , int V_53 ,
const char * V_329 , const char * V_330 ,
T_6 V_35 , void * V_295 )
{
struct V_49 * V_50 ;
struct V_331 * V_332 ;
struct V_331 * * V_22 ;
V_50 = F_182 ( V_14 , V_53 , V_329 , V_330 ) ;
if ( V_50 == NULL )
goto V_362;
if ( V_50 -> V_293 == V_35 && V_50 -> V_295 == V_295 ) {
F_163 ( L_200 ,
V_50 -> V_53 , V_50 -> system , V_50 -> V_69 ) ;
V_50 -> V_293 = NULL ;
V_50 -> V_295 = NULL ;
return 0 ;
}
V_362:
for ( V_22 = & V_14 -> V_333 ; * V_22 ; V_22 = & ( * V_22 ) -> V_22 ) {
V_332 = * V_22 ;
if ( F_184 ( V_332 , V_53 , V_329 , V_330 ,
V_35 , V_295 ) )
break;
}
if ( ! ( * V_22 ) )
return - 1 ;
* V_22 = V_332 -> V_22 ;
F_161 ( V_332 ) ;
return 0 ;
}
struct V_14 * F_186 ( void )
{
struct V_14 * V_14 = calloc ( 1 , sizeof( * V_14 ) ) ;
if ( V_14 )
V_14 -> V_363 = 1 ;
return V_14 ;
}
void F_187 ( struct V_14 * V_14 )
{
V_14 -> V_363 ++ ;
}
static void F_188 ( struct V_118 * V_68 )
{
struct V_118 * V_22 ;
while ( V_68 ) {
V_22 = V_68 -> V_22 ;
free ( V_68 -> type ) ;
free ( V_68 -> V_69 ) ;
free ( V_68 ) ;
V_68 = V_22 ;
}
}
static void F_189 ( struct V_142 * V_142 )
{
F_188 ( V_142 -> V_143 ) ;
F_188 ( V_142 -> V_121 ) ;
}
void F_167 ( struct V_49 * V_50 )
{
free ( V_50 -> V_69 ) ;
free ( V_50 -> system ) ;
F_189 ( & V_50 -> V_142 ) ;
free ( V_50 -> V_172 . V_142 ) ;
F_122 ( V_50 -> V_172 . args ) ;
free ( V_50 ) ;
}
void F_190 ( struct V_14 * V_14 )
{
struct V_15 * V_16 , * V_364 ;
struct V_32 * V_33 , * V_365 ;
struct V_43 * V_44 , * V_366 ;
struct V_166 * V_367 ;
struct V_331 * V_332 ;
int V_19 ;
if ( ! V_14 )
return;
V_16 = V_14 -> V_16 ;
V_33 = V_14 -> V_33 ;
V_44 = V_14 -> V_44 ;
V_14 -> V_363 -- ;
if ( V_14 -> V_363 )
return;
if ( V_14 -> V_18 ) {
for ( V_19 = 0 ; V_19 < V_14 -> V_20 ; V_19 ++ )
free ( V_14 -> V_18 [ V_19 ] . V_21 ) ;
free ( V_14 -> V_18 ) ;
}
while ( V_16 ) {
V_364 = V_16 -> V_22 ;
free ( V_16 -> V_21 ) ;
free ( V_16 ) ;
V_16 = V_364 ;
}
if ( V_14 -> V_28 ) {
for ( V_19 = 0 ; V_19 < ( int ) V_14 -> V_34 ; V_19 ++ ) {
free ( V_14 -> V_28 [ V_19 ] . V_35 ) ;
free ( V_14 -> V_28 [ V_19 ] . V_36 ) ;
}
free ( V_14 -> V_28 ) ;
}
while ( V_33 ) {
V_365 = V_33 -> V_22 ;
free ( V_33 -> V_35 ) ;
free ( V_33 -> V_36 ) ;
free ( V_33 ) ;
V_33 = V_365 ;
}
while ( V_14 -> V_168 ) {
V_367 = V_14 -> V_168 ;
V_14 -> V_168 = V_367 -> V_22 ;
F_88 ( V_367 ) ;
}
if ( V_14 -> V_40 ) {
for ( V_19 = 0 ; V_19 < ( int ) V_14 -> V_45 ; V_19 ++ )
free ( V_14 -> V_40 [ V_19 ] . V_46 ) ;
free ( V_14 -> V_40 ) ;
}
while ( V_44 ) {
V_366 = V_44 -> V_22 ;
free ( V_44 -> V_46 ) ;
free ( V_44 ) ;
V_44 = V_366 ;
}
for ( V_19 = 0 ; V_19 < V_14 -> V_52 ; V_19 ++ )
F_167 ( V_14 -> V_51 [ V_19 ] ) ;
while ( V_14 -> V_333 ) {
V_332 = V_14 -> V_333 ;
V_14 -> V_333 = V_332 -> V_22 ;
F_161 ( V_332 ) ;
}
free ( V_14 -> V_51 ) ;
free ( V_14 -> V_313 ) ;
free ( V_14 ) ;
}
void F_191 ( struct V_14 * V_14 )
{
F_190 ( V_14 ) ;
}
