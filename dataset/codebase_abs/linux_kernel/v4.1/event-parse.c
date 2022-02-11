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
if ( V_21 )
V_17 -> V_21 = F_12 ( V_21 ) ;
else
V_17 -> V_21 = F_12 ( L_3 ) ;
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
int F_14 ( struct V_14 * V_14 , const char * V_27 )
{
V_14 -> V_27 = F_12 ( V_27 ) ;
if ( ! V_14 -> V_27 ) {
V_24 = V_26 ;
return - 1 ;
}
return 0 ;
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
F_32 ( V_63 -> V_79 . V_68 ) ;
F_32 ( V_63 -> V_79 . V_80 ) ;
F_32 ( V_63 -> V_79 . V_81 ) ;
break;
case V_82 :
free ( V_63 -> V_83 . type ) ;
F_32 ( V_63 -> V_83 . V_17 ) ;
break;
case V_84 :
case V_85 :
free ( V_63 -> string . string ) ;
break;
case V_86 :
free ( V_63 -> V_87 . V_87 ) ;
break;
case V_88 :
free ( V_63 -> V_89 . V_90 ) ;
break;
case V_91 :
free ( V_63 -> V_92 . V_92 ) ;
F_32 ( V_63 -> V_92 . V_93 ) ;
F_32 ( V_63 -> V_92 . V_94 ) ;
break;
case V_95 :
while ( V_63 -> V_35 . args ) {
V_64 = V_63 -> V_35 . args ;
V_63 -> V_35 . args = V_64 -> V_22 ;
F_32 ( V_64 ) ;
}
break;
case V_96 :
default:
break;
}
free ( V_63 ) ;
}
static enum V_54 F_33 ( int V_97 )
{
if ( V_97 == '\n' )
return V_98 ;
if ( isspace ( V_97 ) )
return V_99 ;
if ( isalnum ( V_97 ) || V_97 == '_' )
return V_55 ;
if ( V_97 == '\'' )
return V_56 ;
if ( V_97 == '"' )
return V_100 ;
if ( ! isprint ( V_97 ) )
return V_101 ;
if ( V_97 == '(' || V_97 == ')' || V_97 == ',' )
return V_58 ;
return V_102 ;
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
static int F_37 ( char * * V_103 , char * V_1 , int V_2 )
{
char * V_104 = realloc ( * V_103 , V_2 ) ;
if ( ! V_104 ) {
free ( * V_103 ) ;
* V_103 = NULL ;
return - 1 ;
}
if ( ! * V_103 )
strcpy ( V_104 , V_1 ) ;
else
strcat ( V_104 , V_1 ) ;
* V_103 = V_104 ;
return 0 ;
}
static enum V_54 F_38 ( char * * V_103 )
{
char V_1 [ V_105 ] ;
int V_97 , V_106 , V_107 , V_108 ;
int V_19 = 0 ;
int V_109 = 0 ;
enum V_54 type ;
* V_103 = NULL ;
V_97 = F_34 () ;
if ( V_97 < 0 )
return V_101 ;
type = F_33 ( V_97 ) ;
if ( type == V_101 )
return type ;
V_1 [ V_19 ++ ] = V_97 ;
switch ( type ) {
case V_98 :
case V_58 :
if ( F_39 ( V_103 , L_9 , V_97 ) < 0 )
return V_57 ;
return type ;
case V_102 :
switch ( V_97 ) {
case '-' :
V_108 = F_35 () ;
if ( V_108 == '>' ) {
V_1 [ V_19 ++ ] = F_34 () ;
break;
}
case '+' :
case '|' :
case '&' :
case '>' :
case '<' :
V_106 = V_97 ;
V_97 = F_35 () ;
if ( V_97 != V_106 )
goto V_110;
V_1 [ V_19 ++ ] = F_34 () ;
switch ( V_106 ) {
case '>' :
case '<' :
goto V_110;
default:
break;
}
break;
case '!' :
case '=' :
goto V_110;
default:
break;
}
V_1 [ V_19 ] = 0 ;
* V_103 = F_12 ( V_1 ) ;
return type ;
V_110:
V_97 = F_35 () ;
if ( V_97 == '=' )
V_1 [ V_19 ++ ] = F_34 () ;
goto V_111;
case V_100 :
case V_56 :
V_19 -- ;
V_107 = V_97 ;
V_106 = 0 ;
V_112:
do {
if ( V_19 == ( V_105 - 1 ) ) {
V_1 [ V_19 ] = 0 ;
V_109 += V_105 ;
if ( F_37 ( V_103 , V_1 , V_109 ) < 0 )
return V_101 ;
V_19 = 0 ;
}
V_106 = V_97 ;
V_97 = F_34 () ;
V_1 [ V_19 ++ ] = V_97 ;
if ( V_97 == '\\' && V_106 == '\\' )
V_106 = 0 ;
} while ( V_97 != V_107 || V_106 == '\\' );
V_19 -- ;
if ( type == V_100 ) {
unsigned long long V_113 = V_5 ;
do {
V_97 = F_34 () ;
} while ( isspace ( V_97 ) );
if ( V_97 == '"' )
goto V_112;
V_5 = V_113 ;
}
goto V_111;
case V_57 ... V_99 :
case V_55 :
default:
break;
}
while ( F_33 ( F_35 () ) == type ) {
if ( V_19 == ( V_105 - 1 ) ) {
V_1 [ V_19 ] = 0 ;
V_109 += V_105 ;
if ( F_37 ( V_103 , V_1 , V_109 ) < 0 )
return V_101 ;
V_19 = 0 ;
}
V_97 = F_34 () ;
V_1 [ V_19 ++ ] = V_97 ;
}
V_111:
V_1 [ V_19 ] = 0 ;
if ( F_37 ( V_103 , V_1 , V_109 + V_19 + 1 ) < 0 )
return V_101 ;
if ( type == V_55 ) {
if ( strcmp ( * V_103 , L_10 ) == 0 ) {
free ( * V_103 ) ;
* V_103 = NULL ;
return F_40 ( L_11 , V_103 ) ;
} else if ( strcmp ( * V_103 , L_12 ) == 0 ) {
free ( * V_103 ) ;
* V_103 = NULL ;
return F_40 ( L_13 , V_103 ) ;
} else if ( strcmp ( * V_103 , L_14 ) == 0 ) {
free ( * V_103 ) ;
* V_103 = NULL ;
return F_40 ( L_15 , V_103 ) ;
}
}
return type ;
}
static enum V_54 F_40 ( const char * V_62 , char * * V_103 )
{
const char * V_114 ;
unsigned long long V_113 ;
unsigned long long V_115 ;
enum V_54 type ;
V_114 = V_3 ;
V_113 = V_5 ;
V_115 = V_4 ;
F_1 ( V_62 , strlen ( V_62 ) ) ;
type = F_38 ( V_103 ) ;
V_3 = V_114 ;
V_5 = V_113 ;
V_4 = V_115 ;
return type ;
}
static void F_41 ( char * V_103 )
{
if ( V_103 )
free ( V_103 ) ;
}
static enum V_54 F_42 ( char * * V_103 )
{
enum V_54 type ;
for (; ; ) {
type = F_38 ( V_103 ) ;
if ( type != V_99 )
return type ;
F_41 ( * V_103 ) ;
}
* V_103 = NULL ;
return V_101 ;
}
enum V_54 F_43 ( char * * V_103 )
{
return F_42 ( V_103 ) ;
}
void F_44 ( char * V_116 )
{
F_41 ( V_116 ) ;
}
static enum V_54 F_45 ( char * * V_103 )
{
enum V_54 type ;
for (; ; ) {
type = F_38 ( V_103 ) ;
if ( type != V_99 && type != V_98 )
return type ;
F_41 ( * V_103 ) ;
* V_103 = NULL ;
}
* V_103 = NULL ;
return V_101 ;
}
static int F_46 ( enum V_54 type , enum V_54 V_117 )
{
if ( type != V_117 ) {
F_47 ( L_16 ,
V_117 , type ) ;
return - 1 ;
}
return 0 ;
}
static int F_48 ( enum V_54 type , const char * V_116 ,
enum V_54 V_117 , const char * V_118 )
{
if ( type != V_117 ) {
F_47 ( L_16 ,
V_117 , type ) ;
return - 1 ;
}
if ( strcmp ( V_116 , V_118 ) != 0 ) {
F_47 ( L_17 ,
V_118 , V_116 ) ;
return - 1 ;
}
return 0 ;
}
static int F_49 ( enum V_54 V_117 , char * * V_103 , int V_119 )
{
enum V_54 type ;
if ( V_119 )
type = F_42 ( V_103 ) ;
else
type = F_45 ( V_103 ) ;
return F_46 ( type , V_117 ) ;
}
static int F_50 ( enum V_54 V_117 , char * * V_103 )
{
return F_49 ( V_117 , V_103 , 1 ) ;
}
static int F_51 ( enum V_54 V_117 , const char * V_62 ,
int V_119 )
{
enum V_54 type ;
char * V_116 ;
int V_120 ;
if ( V_119 )
type = F_42 ( & V_116 ) ;
else
type = F_45 ( & V_116 ) ;
V_120 = F_48 ( type , V_116 , V_117 , V_62 ) ;
F_41 ( V_116 ) ;
return V_120 ;
}
static int F_52 ( enum V_54 V_117 , const char * V_62 )
{
return F_51 ( V_117 , V_62 , 1 ) ;
}
static int F_53 ( enum V_54 V_117 , const char * V_62 )
{
return F_51 ( V_117 , V_62 , 0 ) ;
}
static char * F_54 ( void )
{
char * V_116 ;
if ( F_52 ( V_55 , L_18 ) < 0 )
return NULL ;
if ( F_52 ( V_102 , L_19 ) < 0 )
return NULL ;
if ( F_50 ( V_55 , & V_116 ) < 0 )
goto V_121;
return V_116 ;
V_121:
F_41 ( V_116 ) ;
return NULL ;
}
static int F_55 ( void )
{
char * V_116 ;
int V_53 ;
if ( F_53 ( V_55 , L_20 ) < 0 )
return - 1 ;
if ( F_52 ( V_102 , L_19 ) < 0 )
return - 1 ;
if ( F_50 ( V_55 , & V_116 ) < 0 )
goto V_121;
V_53 = strtoul ( V_116 , NULL , 0 ) ;
F_41 ( V_116 ) ;
return V_53 ;
V_121:
F_41 ( V_116 ) ;
return - 1 ;
}
static int F_56 ( struct V_122 * V_68 )
{
if ( ( V_68 -> V_71 & V_123 ) &&
( strstr ( V_68 -> type , L_21 ) || strstr ( V_68 -> type , L_22 ) ||
strstr ( V_68 -> type , L_23 ) ) )
return 1 ;
return 0 ;
}
static int F_57 ( struct V_122 * V_68 )
{
if ( strncmp ( V_68 -> type , L_24 , 10 ) == 0 )
return 1 ;
return 0 ;
}
static int F_58 ( struct V_122 * V_68 )
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
} V_124 [] = {
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
for ( V_19 = 0 ; V_124 [ V_19 ] . type ; V_19 ++ ) {
if ( ! strcmp ( V_124 [ V_19 ] . type , V_69 ) )
return V_124 [ V_19 ] . V_2 ;
}
return 0 ;
}
static int F_60 ( struct V_49 * V_50 , struct V_122 * * V_125 )
{
struct V_122 * V_68 = NULL ;
enum V_54 type ;
char * V_116 ;
char * V_126 ;
int V_80 = 0 ;
do {
unsigned int V_127 = 0 ;
type = F_42 ( & V_116 ) ;
if ( type == V_98 ) {
F_41 ( V_116 ) ;
return V_80 ;
}
V_80 ++ ;
if ( F_48 ( type , V_116 , V_55 , L_32 ) )
goto V_121;
F_41 ( V_116 ) ;
type = F_42 ( & V_116 ) ;
if ( V_50 -> V_71 & V_128 &&
type == V_55 && strcmp ( V_116 , L_33 ) == 0 ) {
F_41 ( V_116 ) ;
type = F_42 ( & V_116 ) ;
}
if ( F_48 ( type , V_116 , V_102 , L_19 ) < 0 )
goto V_121;
F_41 ( V_116 ) ;
if ( F_50 ( V_55 , & V_116 ) < 0 )
goto V_121;
V_126 = V_116 ;
V_68 = calloc ( 1 , sizeof( * V_68 ) ) ;
if ( ! V_68 )
goto V_121;
V_68 -> V_50 = V_50 ;
for (; ; ) {
type = F_42 ( & V_116 ) ;
if ( type == V_55 ||
( type == V_102 && strcmp ( V_116 , L_34 ) == 0 ) ||
( V_50 -> V_71 & V_128 &&
type == V_102 && strcmp ( V_116 , L_35 ) == 0 ) ) {
if ( strcmp ( V_116 , L_34 ) == 0 )
V_68 -> V_71 |= V_129 ;
if ( V_68 -> type ) {
char * V_130 ;
V_130 = realloc ( V_68 -> type ,
strlen ( V_68 -> type ) +
strlen ( V_126 ) + 2 ) ;
if ( ! V_130 ) {
free ( V_126 ) ;
goto V_121;
}
V_68 -> type = V_130 ;
strcat ( V_68 -> type , L_36 ) ;
strcat ( V_68 -> type , V_126 ) ;
free ( V_126 ) ;
} else
V_68 -> type = V_126 ;
V_126 = V_116 ;
continue;
}
break;
}
if ( ! V_68 -> type ) {
F_61 ( V_50 , L_37 , V_131 ) ;
goto V_121;
}
V_68 -> V_69 = V_126 ;
if ( F_46 ( type , V_102 ) )
goto V_121;
if ( strcmp ( V_116 , L_38 ) == 0 ) {
enum V_54 V_132 = type ;
char * V_133 = V_116 ;
char * V_134 ;
int V_135 ;
V_68 -> V_71 |= V_123 ;
type = F_42 ( & V_116 ) ;
if ( type == V_55 )
V_68 -> V_136 = strtoul ( V_116 , NULL , 0 ) ;
else
V_68 -> V_136 = 0 ;
while ( strcmp ( V_116 , L_39 ) != 0 ) {
if ( V_132 == V_55 &&
type == V_55 )
V_135 = 2 ;
else
V_135 = 1 ;
V_132 = type ;
V_134 = realloc ( V_133 ,
strlen ( V_133 ) +
strlen ( V_116 ) + V_135 ) ;
if ( ! V_134 ) {
free ( V_133 ) ;
goto V_121;
}
V_133 = V_134 ;
if ( V_135 == 2 )
strcat ( V_133 , L_36 ) ;
strcat ( V_133 , V_116 ) ;
V_68 -> V_136 = strtoul ( V_116 , NULL , 0 ) ;
F_41 ( V_116 ) ;
type = F_42 ( & V_116 ) ;
if ( type == V_101 ) {
F_61 ( V_50 , L_40 ) ;
goto V_121;
}
}
F_41 ( V_116 ) ;
V_134 = realloc ( V_133 , strlen ( V_133 ) + 2 ) ;
if ( ! V_134 ) {
free ( V_133 ) ;
goto V_121;
}
V_133 = V_134 ;
strcat ( V_133 , L_39 ) ;
type = F_42 ( & V_116 ) ;
if ( type == V_55 ) {
char * V_130 ;
V_130 = realloc ( V_68 -> type ,
strlen ( V_68 -> type ) +
strlen ( V_68 -> V_69 ) +
strlen ( V_133 ) + 2 ) ;
if ( ! V_130 ) {
free ( V_133 ) ;
goto V_121;
}
V_68 -> type = V_130 ;
strcat ( V_68 -> type , L_36 ) ;
strcat ( V_68 -> type , V_68 -> V_69 ) ;
V_127 = F_59 ( V_68 -> V_69 ) ;
F_41 ( V_68 -> V_69 ) ;
strcat ( V_68 -> type , V_133 ) ;
V_68 -> V_69 = V_116 ;
type = F_42 ( & V_116 ) ;
} else {
char * V_130 ;
V_130 = realloc ( V_68 -> type ,
strlen ( V_68 -> type ) +
strlen ( V_133 ) + 1 ) ;
if ( ! V_130 ) {
free ( V_133 ) ;
goto V_121;
}
V_68 -> type = V_130 ;
strcat ( V_68 -> type , V_133 ) ;
}
free ( V_133 ) ;
}
if ( F_56 ( V_68 ) )
V_68 -> V_71 |= V_137 ;
if ( F_57 ( V_68 ) )
V_68 -> V_71 |= V_138 ;
if ( F_58 ( V_68 ) )
V_68 -> V_71 |= V_139 ;
if ( F_48 ( type , V_116 , V_102 , L_41 ) )
goto V_121;
F_41 ( V_116 ) ;
if ( F_52 ( V_55 , L_42 ) < 0 )
goto V_140;
if ( F_52 ( V_102 , L_19 ) < 0 )
goto V_140;
if ( F_50 ( V_55 , & V_116 ) )
goto V_121;
V_68 -> V_141 = strtoul ( V_116 , NULL , 0 ) ;
F_41 ( V_116 ) ;
if ( F_52 ( V_102 , L_41 ) < 0 )
goto V_140;
if ( F_52 ( V_55 , L_43 ) < 0 )
goto V_140;
if ( F_52 ( V_102 , L_19 ) < 0 )
goto V_140;
if ( F_50 ( V_55 , & V_116 ) )
goto V_121;
V_68 -> V_2 = strtoul ( V_116 , NULL , 0 ) ;
F_41 ( V_116 ) ;
if ( F_52 ( V_102 , L_41 ) < 0 )
goto V_140;
type = F_42 ( & V_116 ) ;
if ( type != V_98 ) {
if ( F_48 ( type , V_116 , V_55 , L_44 ) )
goto V_121;
F_41 ( V_116 ) ;
if ( F_52 ( V_102 , L_19 ) < 0 )
goto V_140;
if ( F_50 ( V_55 , & V_116 ) )
goto V_121;
if ( strtoul ( V_116 , NULL , 0 ) )
V_68 -> V_71 |= V_142 ;
F_41 ( V_116 ) ;
if ( F_52 ( V_102 , L_41 ) < 0 )
goto V_140;
if ( F_50 ( V_98 , & V_116 ) )
goto V_121;
}
F_41 ( V_116 ) ;
if ( V_68 -> V_71 & V_123 ) {
if ( V_68 -> V_136 )
V_68 -> V_143 = V_68 -> V_2 / V_68 -> V_136 ;
else if ( V_68 -> V_71 & V_138 )
V_68 -> V_143 = V_127 ;
else if ( V_68 -> V_71 & V_137 )
V_68 -> V_143 = 1 ;
else if ( V_68 -> V_71 & V_139 )
V_68 -> V_143 = V_50 -> V_14 ?
V_50 -> V_14 -> V_144 :
sizeof( long ) ;
} else
V_68 -> V_143 = V_68 -> V_2 ;
* V_125 = V_68 ;
V_125 = & V_68 -> V_22 ;
} while ( 1 );
return 0 ;
V_121:
F_41 ( V_116 ) ;
V_140:
if ( V_68 ) {
free ( V_68 -> type ) ;
free ( V_68 -> V_69 ) ;
free ( V_68 ) ;
}
return - 1 ;
}
static int F_62 ( struct V_49 * V_50 )
{
char * V_116 ;
int V_120 ;
if ( F_53 ( V_55 , L_45 ) < 0 )
return - 1 ;
if ( F_52 ( V_102 , L_19 ) < 0 )
return - 1 ;
if ( F_50 ( V_98 , & V_116 ) )
goto V_121;
F_41 ( V_116 ) ;
V_120 = F_60 ( V_50 , & V_50 -> V_145 . V_146 ) ;
if ( V_120 < 0 )
return V_120 ;
V_50 -> V_145 . V_147 = V_120 ;
V_120 = F_60 ( V_50 , & V_50 -> V_145 . V_125 ) ;
if ( V_120 < 0 )
return V_120 ;
V_50 -> V_145 . V_148 = V_120 ;
return 0 ;
V_121:
F_41 ( V_116 ) ;
return - 1 ;
}
static enum V_54
F_63 ( struct V_49 * V_50 , struct V_7 * V_63 , char * * V_103 )
{
enum V_54 type ;
char * V_116 ;
type = F_42 ( & V_116 ) ;
* V_103 = V_116 ;
return F_64 ( V_50 , V_63 , V_103 , type ) ;
}
static enum V_54
F_65 ( struct V_49 * V_50 , struct V_7 * V_63 , char * * V_103 )
{
enum V_54 type ;
type = F_63 ( V_50 , V_63 , V_103 ) ;
while ( type == V_102 ) {
type = F_66 ( V_50 , V_63 , V_103 ) ;
}
return type ;
}
static enum V_54
F_67 ( struct V_49 * V_50 , struct V_7 * V_149 , char * * V_103 )
{
struct V_7 * V_63 , * V_93 , * V_94 ;
enum V_54 type ;
char * V_116 = NULL ;
V_63 = F_6 () ;
V_93 = F_6 () ;
V_94 = F_6 () ;
if ( ! V_63 || ! V_93 || ! V_94 ) {
F_61 ( V_50 , L_46 , V_131 ) ;
F_32 ( V_93 ) ;
F_32 ( V_94 ) ;
goto V_38;
}
V_63 -> type = V_91 ;
V_63 -> V_92 . V_93 = V_93 ;
V_63 -> V_92 . V_94 = V_94 ;
* V_103 = NULL ;
type = F_63 ( V_50 , V_93 , & V_116 ) ;
V_150:
if ( type == V_102 && strcmp ( V_116 , L_19 ) != 0 ) {
type = F_66 ( V_50 , V_93 , & V_116 ) ;
goto V_150;
}
if ( F_48 ( type , V_116 , V_102 , L_19 ) )
goto V_38;
V_63 -> V_92 . V_92 = V_116 ;
type = F_63 ( V_50 , V_94 , & V_116 ) ;
V_149 -> V_92 . V_94 = V_63 ;
* V_103 = V_116 ;
return type ;
V_38:
V_149 -> V_92 . V_94 = NULL ;
F_41 ( V_116 ) ;
F_32 ( V_63 ) ;
return V_57 ;
}
static enum V_54
F_68 ( struct V_49 * V_50 , struct V_7 * V_149 , char * * V_103 )
{
struct V_7 * V_63 ;
enum V_54 type ;
char * V_116 = NULL ;
V_63 = F_6 () ;
if ( ! V_63 ) {
F_61 ( V_50 , L_46 , V_131 ) ;
* V_103 = NULL ;
return V_57 ;
}
* V_103 = NULL ;
type = F_63 ( V_50 , V_63 , & V_116 ) ;
if ( F_48 ( type , V_116 , V_102 , L_39 ) )
goto V_38;
V_149 -> V_92 . V_94 = V_63 ;
F_41 ( V_116 ) ;
type = F_45 ( & V_116 ) ;
* V_103 = V_116 ;
return type ;
V_38:
F_41 ( V_116 ) ;
F_32 ( V_63 ) ;
return V_57 ;
}
static int F_69 ( char * V_92 )
{
if ( ! V_92 [ 1 ] ) {
switch ( V_92 [ 0 ] ) {
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
F_47 ( L_47 , V_92 [ 0 ] ) ;
return - 1 ;
}
} else {
if ( strcmp ( V_92 , L_48 ) == 0 ||
strcmp ( V_92 , L_49 ) == 0 ) {
return 3 ;
} else if ( strcmp ( V_92 , L_50 ) == 0 ||
strcmp ( V_92 , L_51 ) == 0 ) {
return 8 ;
} else if ( strcmp ( V_92 , L_52 ) == 0 ||
strcmp ( V_92 , L_53 ) == 0 ) {
return 9 ;
} else if ( strcmp ( V_92 , L_54 ) == 0 ||
strcmp ( V_92 , L_55 ) == 0 ) {
return 10 ;
} else if ( strcmp ( V_92 , L_56 ) == 0 ) {
return 14 ;
} else if ( strcmp ( V_92 , L_57 ) == 0 ) {
return 15 ;
} else {
F_47 ( L_58 , V_92 ) ;
return - 1 ;
}
}
}
static int F_70 ( struct V_7 * V_63 )
{
if ( ! V_63 -> V_92 . V_93 || V_63 -> V_92 . V_93 -> type == V_96 )
V_63 -> V_92 . V_151 = 0 ;
else
V_63 -> V_92 . V_151 = F_69 ( V_63 -> V_92 . V_92 ) ;
return V_63 -> V_92 . V_151 ;
}
static enum V_54
F_66 ( struct V_49 * V_50 , struct V_7 * V_63 , char * * V_103 )
{
struct V_7 * V_93 , * V_94 = NULL ;
enum V_54 type ;
char * V_116 ;
V_116 = * V_103 ;
if ( V_63 -> type == V_91 && ! V_63 -> V_92 . V_93 ) {
if ( V_116 [ 1 ] ) {
F_61 ( V_50 , L_59 , V_116 ) ;
goto V_38;
}
switch ( V_116 [ 0 ] ) {
case '~' :
case '!' :
case '+' :
case '-' :
break;
default:
F_61 ( V_50 , L_59 , V_116 ) ;
goto V_38;
}
V_93 = F_6 () ;
if ( ! V_93 )
goto V_152;
V_93 -> type = V_96 ;
V_63 -> V_92 . V_93 = V_93 ;
V_94 = F_6 () ;
if ( ! V_94 )
goto V_152;
V_63 -> V_92 . V_94 = V_94 ;
* V_103 = NULL ;
type = F_63 ( V_50 , V_94 , V_103 ) ;
} else if ( strcmp ( V_116 , L_60 ) == 0 ) {
V_93 = F_6 () ;
if ( ! V_93 )
goto V_152;
* V_93 = * V_63 ;
V_63 -> type = V_91 ;
V_63 -> V_92 . V_92 = V_116 ;
V_63 -> V_92 . V_93 = V_93 ;
V_63 -> V_92 . V_151 = 0 ;
type = F_67 ( V_50 , V_63 , V_103 ) ;
} else if ( strcmp ( V_116 , L_50 ) == 0 ||
strcmp ( V_116 , L_51 ) == 0 ||
strcmp ( V_116 , L_61 ) == 0 ||
strcmp ( V_116 , L_62 ) == 0 ||
strcmp ( V_116 , L_56 ) == 0 ||
strcmp ( V_116 , L_57 ) == 0 ||
strcmp ( V_116 , L_63 ) == 0 ||
strcmp ( V_116 , L_64 ) == 0 ||
strcmp ( V_116 , L_34 ) == 0 ||
strcmp ( V_116 , L_65 ) == 0 ||
strcmp ( V_116 , L_66 ) == 0 ||
strcmp ( V_116 , L_67 ) == 0 ||
strcmp ( V_116 , L_68 ) == 0 ||
strcmp ( V_116 , L_53 ) == 0 ||
strcmp ( V_116 , L_52 ) == 0 ||
strcmp ( V_116 , L_54 ) == 0 ||
strcmp ( V_116 , L_55 ) == 0 ) {
V_93 = F_6 () ;
if ( ! V_93 )
goto V_152;
* V_93 = * V_63 ;
V_63 -> type = V_91 ;
V_63 -> V_92 . V_92 = V_116 ;
V_63 -> V_92 . V_93 = V_93 ;
V_63 -> V_92 . V_94 = NULL ;
if ( F_70 ( V_63 ) == - 1 ) {
V_50 -> V_71 |= V_153 ;
V_63 -> V_92 . V_92 = NULL ;
goto V_38;
}
type = F_45 ( & V_116 ) ;
* V_103 = V_116 ;
if ( ( strcmp ( V_63 -> V_92 . V_92 , L_34 ) == 0 ) &&
type == V_58 && ( strcmp ( V_116 , L_69 ) == 0 ) ) {
char * V_154 ;
if ( V_93 -> type != V_65 ) {
F_61 ( V_50 , L_70 ) ;
goto V_38;
}
V_154 = realloc ( V_93 -> V_66 . V_66 ,
strlen ( V_93 -> V_66 . V_66 ) + 3 ) ;
if ( ! V_154 )
goto V_152;
V_93 -> V_66 . V_66 = V_154 ;
strcat ( V_93 -> V_66 . V_66 , L_71 ) ;
free ( V_63 -> V_92 . V_92 ) ;
* V_63 = * V_93 ;
free ( V_93 ) ;
return type ;
}
V_94 = F_6 () ;
if ( ! V_94 )
goto V_152;
type = F_64 ( V_50 , V_94 , V_103 , type ) ;
if ( V_94 -> type == V_91 &&
F_69 ( V_63 -> V_92 . V_92 ) < F_69 ( V_94 -> V_92 . V_92 ) ) {
struct V_7 V_155 ;
V_63 -> V_92 . V_94 = V_94 -> V_92 . V_93 ;
V_155 = * V_63 ;
* V_63 = * V_94 ;
* V_94 = V_155 ;
V_63 -> V_92 . V_93 = V_94 ;
} else {
V_63 -> V_92 . V_94 = V_94 ;
}
} else if ( strcmp ( V_116 , L_38 ) == 0 ) {
V_93 = F_6 () ;
if ( ! V_93 )
goto V_152;
* V_93 = * V_63 ;
V_63 -> type = V_91 ;
V_63 -> V_92 . V_92 = V_116 ;
V_63 -> V_92 . V_93 = V_93 ;
V_63 -> V_92 . V_151 = 0 ;
type = F_68 ( V_50 , V_63 , V_103 ) ;
} else {
F_61 ( V_50 , L_58 , V_116 ) ;
V_50 -> V_71 |= V_153 ;
goto V_38;
}
if ( type == V_102 && strcmp ( * V_103 , L_19 ) != 0 ) {
int V_151 ;
V_151 = F_69 ( * V_103 ) ;
if ( V_151 > V_63 -> V_92 . V_151 )
return F_66 ( V_50 , V_63 , V_103 ) ;
return F_66 ( V_50 , V_94 , V_103 ) ;
}
return type ;
V_152:
F_61 ( V_50 , L_46 , V_131 ) ;
V_38:
F_41 ( V_116 ) ;
* V_103 = NULL ;
return V_57 ;
}
static enum V_54
F_71 ( struct V_49 * V_50 V_156 , struct V_7 * V_63 ,
char * * V_103 )
{
enum V_54 type ;
char * V_68 ;
char * V_116 ;
if ( F_52 ( V_102 , L_72 ) < 0 )
goto V_157;
if ( F_50 ( V_55 , & V_116 ) < 0 )
goto V_38;
V_68 = V_116 ;
V_63 -> type = V_67 ;
V_63 -> V_68 . V_69 = V_68 ;
if ( V_158 ) {
V_63 -> V_68 . V_68 = F_72 ( V_50 , V_63 -> V_68 . V_69 ) ;
V_63 -> V_68 . V_68 -> V_71 |= V_159 ;
V_158 = 0 ;
} else if ( V_160 ) {
V_63 -> V_68 . V_68 = F_72 ( V_50 , V_63 -> V_68 . V_69 ) ;
V_63 -> V_68 . V_68 -> V_71 |= V_161 ;
V_160 = 0 ;
}
type = F_42 ( & V_116 ) ;
* V_103 = V_116 ;
return type ;
V_38:
F_41 ( V_116 ) ;
V_157:
* V_103 = NULL ;
return V_57 ;
}
static int F_73 ( struct V_49 * V_50 , char * V_162 ,
struct V_7 * * V_7 )
{
struct V_7 * V_68 ;
enum V_54 type ;
char * V_116 ;
int V_120 = 0 ;
V_68 = F_6 () ;
if ( ! V_68 ) {
F_61 ( V_50 , L_46 , V_131 ) ;
V_24 = V_26 ;
return - 1 ;
}
type = F_63 ( V_50 , V_68 , & V_116 ) ;
if ( F_48 ( type , V_116 , V_58 , V_162 ) ) {
V_24 = V_163 ;
V_120 = - 1 ;
F_32 ( V_68 ) ;
goto V_164;
}
* V_7 = V_68 ;
V_164:
F_41 ( V_116 ) ;
return V_120 ;
}
static unsigned long long
F_74 ( unsigned long long V_165 , const char * type , int V_166 )
{
int V_167 = 0 ;
char * V_168 ;
int V_135 ;
V_135 = strlen ( type ) ;
if ( V_166 ) {
if ( type [ V_135 - 1 ] != '*' ) {
F_47 ( L_73 ) ;
return V_165 ;
}
V_168 = malloc ( V_135 ) ;
if ( ! V_168 ) {
F_47 ( L_46 , V_131 ) ;
return V_165 ;
}
memcpy ( V_168 , type , V_135 ) ;
V_168 [ V_135 - 2 ] = 0 ;
V_165 = F_74 ( V_165 , V_168 , 0 ) ;
free ( V_168 ) ;
return V_165 ;
}
if ( type [ V_135 - 1 ] == '*' )
return V_165 ;
if ( strncmp ( type , L_74 , 6 ) == 0 )
return V_165 ;
if ( strcmp ( type , L_22 ) == 0 )
return V_165 & 0xff ;
if ( strcmp ( type , L_26 ) == 0 )
return V_165 & 0xffff ;
if ( strcmp ( type , L_27 ) == 0 )
return V_165 & 0xffffffff ;
if ( strcmp ( type , L_28 ) == 0 ||
strcmp ( type , L_31 ) )
return V_165 ;
if ( strcmp ( type , L_23 ) == 0 )
return ( unsigned long long ) ( char ) V_165 & 0xff ;
if ( strcmp ( type , L_29 ) == 0 )
return ( unsigned long long ) ( short ) V_165 & 0xffff ;
if ( strcmp ( type , L_30 ) == 0 )
return ( unsigned long long ) ( int ) V_165 & 0xffffffff ;
if ( strncmp ( type , L_75 , 9 ) == 0 ) {
V_167 = 0 ;
type += 9 ;
}
if ( strcmp ( type , L_21 ) == 0 ) {
if ( V_167 )
return ( unsigned long long ) ( char ) V_165 & 0xff ;
else
return V_165 & 0xff ;
}
if ( strcmp ( type , L_76 ) == 0 ) {
if ( V_167 )
return ( unsigned long long ) ( short ) V_165 & 0xffff ;
else
return V_165 & 0xffff ;
}
if ( strcmp ( type , L_77 ) == 0 ) {
if ( V_167 )
return ( unsigned long long ) ( int ) V_165 & 0xffffffff ;
else
return V_165 & 0xffffffff ;
}
return V_165 ;
}
static unsigned long long
F_75 ( unsigned long long V_165 , struct V_7 * V_63 , int V_166 )
{
if ( V_63 -> type != V_82 ) {
F_47 ( L_78 ) ;
return 0 ;
}
return F_74 ( V_165 , V_63 -> V_83 . type , V_166 ) ;
}
static int F_76 ( struct V_7 * V_63 , long long * V_165 )
{
long long V_93 , V_94 ;
int V_120 = 1 ;
switch ( V_63 -> type ) {
case V_65 :
* V_165 = strtoll ( V_63 -> V_66 . V_66 , NULL , 0 ) ;
break;
case V_82 :
V_120 = F_76 ( V_63 -> V_83 . V_17 , V_165 ) ;
if ( ! V_120 )
break;
* V_165 = F_75 ( * V_165 , V_63 , 0 ) ;
break;
case V_91 :
switch ( V_63 -> V_92 . V_92 [ 0 ] ) {
case '|' :
V_120 = F_76 ( V_63 -> V_92 . V_93 , & V_93 ) ;
if ( ! V_120 )
break;
V_120 = F_76 ( V_63 -> V_92 . V_94 , & V_94 ) ;
if ( ! V_120 )
break;
if ( V_63 -> V_92 . V_92 [ 1 ] )
* V_165 = V_93 || V_94 ;
else
* V_165 = V_93 | V_94 ;
break;
case '&' :
V_120 = F_76 ( V_63 -> V_92 . V_93 , & V_93 ) ;
if ( ! V_120 )
break;
V_120 = F_76 ( V_63 -> V_92 . V_94 , & V_94 ) ;
if ( ! V_120 )
break;
if ( V_63 -> V_92 . V_92 [ 1 ] )
* V_165 = V_93 && V_94 ;
else
* V_165 = V_93 & V_94 ;
break;
case '<' :
V_120 = F_76 ( V_63 -> V_92 . V_93 , & V_93 ) ;
if ( ! V_120 )
break;
V_120 = F_76 ( V_63 -> V_92 . V_94 , & V_94 ) ;
if ( ! V_120 )
break;
switch ( V_63 -> V_92 . V_92 [ 1 ] ) {
case 0 :
* V_165 = V_93 < V_94 ;
break;
case '<' :
* V_165 = V_93 << V_94 ;
break;
case '=' :
* V_165 = V_93 <= V_94 ;
break;
default:
F_47 ( L_58 , V_63 -> V_92 . V_92 ) ;
V_120 = 0 ;
}
break;
case '>' :
V_120 = F_76 ( V_63 -> V_92 . V_93 , & V_93 ) ;
if ( ! V_120 )
break;
V_120 = F_76 ( V_63 -> V_92 . V_94 , & V_94 ) ;
if ( ! V_120 )
break;
switch ( V_63 -> V_92 . V_92 [ 1 ] ) {
case 0 :
* V_165 = V_93 > V_94 ;
break;
case '>' :
* V_165 = V_93 >> V_94 ;
break;
case '=' :
* V_165 = V_93 >= V_94 ;
break;
default:
F_47 ( L_58 , V_63 -> V_92 . V_92 ) ;
V_120 = 0 ;
}
break;
case '=' :
V_120 = F_76 ( V_63 -> V_92 . V_93 , & V_93 ) ;
if ( ! V_120 )
break;
V_120 = F_76 ( V_63 -> V_92 . V_94 , & V_94 ) ;
if ( ! V_120 )
break;
if ( V_63 -> V_92 . V_92 [ 1 ] != '=' ) {
F_47 ( L_58 , V_63 -> V_92 . V_92 ) ;
V_120 = 0 ;
} else
* V_165 = V_93 == V_94 ;
break;
case '!' :
V_120 = F_76 ( V_63 -> V_92 . V_93 , & V_93 ) ;
if ( ! V_120 )
break;
V_120 = F_76 ( V_63 -> V_92 . V_94 , & V_94 ) ;
if ( ! V_120 )
break;
switch ( V_63 -> V_92 . V_92 [ 1 ] ) {
case '=' :
* V_165 = V_93 != V_94 ;
break;
default:
F_47 ( L_58 , V_63 -> V_92 . V_92 ) ;
V_120 = 0 ;
}
break;
case '-' :
if ( V_63 -> V_92 . V_93 -> type == V_96 )
V_93 = 0 ;
else
V_120 = F_76 ( V_63 -> V_92 . V_93 , & V_93 ) ;
if ( ! V_120 )
break;
V_120 = F_76 ( V_63 -> V_92 . V_94 , & V_94 ) ;
if ( ! V_120 )
break;
* V_165 = V_93 - V_94 ;
break;
case '+' :
if ( V_63 -> V_92 . V_93 -> type == V_96 )
V_93 = 0 ;
else
V_120 = F_76 ( V_63 -> V_92 . V_93 , & V_93 ) ;
if ( ! V_120 )
break;
V_120 = F_76 ( V_63 -> V_92 . V_94 , & V_94 ) ;
if ( ! V_120 )
break;
* V_165 = V_93 + V_94 ;
break;
default:
F_47 ( L_58 , V_63 -> V_92 . V_92 ) ;
V_120 = 0 ;
}
break;
case V_96 :
case V_67 ... V_73 :
case V_84 :
case V_85 :
case V_86 :
default:
F_47 ( L_79 , V_63 -> type ) ;
V_120 = 0 ;
}
return V_120 ;
}
static char * F_77 ( struct V_7 * V_63 )
{
long long V_165 ;
static char V_1 [ 20 ] ;
switch ( V_63 -> type ) {
case V_65 :
return V_63 -> V_66 . V_66 ;
case V_82 :
return F_77 ( V_63 -> V_83 . V_17 ) ;
case V_91 :
if ( ! F_76 ( V_63 , & V_165 ) )
break;
sprintf ( V_1 , L_80 , V_165 ) ;
return V_1 ;
case V_96 :
case V_67 ... V_73 :
case V_84 :
case V_85 :
case V_86 :
default:
F_47 ( L_79 , V_63 -> type ) ;
break;
}
return NULL ;
}
static enum V_54
F_78 ( struct V_49 * V_50 , struct V_59 * * V_169 , char * * V_103 )
{
enum V_54 type ;
struct V_7 * V_63 = NULL ;
struct V_59 * V_68 ;
char * V_116 = * V_103 ;
char * V_61 ;
do {
F_41 ( V_116 ) ;
type = F_45 ( & V_116 ) ;
if ( F_48 ( type , V_116 , V_102 , L_81 ) )
break;
V_63 = F_6 () ;
if ( ! V_63 )
goto V_38;
F_41 ( V_116 ) ;
type = F_63 ( V_50 , V_63 , & V_116 ) ;
if ( type == V_102 )
type = F_66 ( V_50 , V_63 , & V_116 ) ;
if ( type == V_57 )
goto V_38;
if ( F_48 ( type , V_116 , V_58 , L_82 ) )
goto V_38;
V_68 = calloc ( 1 , sizeof( * V_68 ) ) ;
if ( ! V_68 )
goto V_38;
V_61 = F_77 ( V_63 ) ;
if ( V_61 == NULL )
goto V_170;
V_68 -> V_61 = F_12 ( V_61 ) ;
if ( V_68 -> V_61 == NULL )
goto V_170;
F_32 ( V_63 ) ;
V_63 = F_6 () ;
if ( ! V_63 )
goto V_38;
F_41 ( V_116 ) ;
type = F_63 ( V_50 , V_63 , & V_116 ) ;
if ( F_48 ( type , V_116 , V_102 , L_83 ) )
goto V_170;
V_61 = F_77 ( V_63 ) ;
if ( V_61 == NULL )
goto V_170;
V_68 -> V_62 = F_12 ( V_61 ) ;
if ( V_68 -> V_62 == NULL )
goto V_170;
F_32 ( V_63 ) ;
V_63 = NULL ;
* V_169 = V_68 ;
V_169 = & V_68 -> V_22 ;
F_41 ( V_116 ) ;
type = F_45 ( & V_116 ) ;
} while ( type == V_58 && strcmp ( V_116 , L_82 ) == 0 );
* V_103 = V_116 ;
return type ;
V_170:
F_31 ( V_68 ) ;
V_38:
F_32 ( V_63 ) ;
F_41 ( V_116 ) ;
* V_103 = NULL ;
return V_57 ;
}
static enum V_54
F_79 ( struct V_49 * V_50 , struct V_7 * V_63 , char * * V_103 )
{
struct V_7 * V_68 ;
enum V_54 type ;
char * V_116 = NULL ;
memset ( V_63 , 0 , sizeof( * V_63 ) ) ;
V_63 -> type = V_70 ;
V_68 = F_6 () ;
if ( ! V_68 ) {
F_61 ( V_50 , L_46 , V_131 ) ;
goto V_38;
}
type = F_65 ( V_50 , V_68 , & V_116 ) ;
while ( type == V_102 )
type = F_66 ( V_50 , V_68 , & V_116 ) ;
if ( F_48 ( type , V_116 , V_58 , L_82 ) )
goto V_170;
F_41 ( V_116 ) ;
V_63 -> V_71 . V_68 = V_68 ;
type = F_45 ( & V_116 ) ;
if ( F_30 ( type ) ) {
V_63 -> V_71 . V_72 = V_116 ;
type = F_45 ( & V_116 ) ;
}
if ( F_48 ( type , V_116 , V_58 , L_82 ) )
goto V_38;
type = F_78 ( V_50 , & V_63 -> V_71 . V_71 , & V_116 ) ;
if ( F_48 ( type , V_116 , V_58 , L_69 ) )
goto V_38;
F_41 ( V_116 ) ;
type = F_45 ( V_103 ) ;
return type ;
V_170:
F_32 ( V_68 ) ;
V_38:
F_41 ( V_116 ) ;
* V_103 = NULL ;
return V_57 ;
}
static enum V_54
F_80 ( struct V_49 * V_50 , struct V_7 * V_63 , char * * V_103 )
{
struct V_7 * V_68 ;
enum V_54 type ;
char * V_116 = NULL ;
memset ( V_63 , 0 , sizeof( * V_63 ) ) ;
V_63 -> type = V_73 ;
V_68 = F_6 () ;
if ( ! V_68 ) {
F_61 ( V_50 , L_46 , V_131 ) ;
goto V_38;
}
type = F_65 ( V_50 , V_68 , & V_116 ) ;
if ( F_48 ( type , V_116 , V_58 , L_82 ) )
goto V_170;
V_63 -> V_74 . V_68 = V_68 ;
type = F_78 ( V_50 , & V_63 -> V_74 . V_75 , & V_116 ) ;
if ( F_48 ( type , V_116 , V_58 , L_69 ) )
goto V_38;
F_41 ( V_116 ) ;
type = F_45 ( V_103 ) ;
return type ;
V_170:
F_32 ( V_68 ) ;
V_38:
F_41 ( V_116 ) ;
* V_103 = NULL ;
return V_57 ;
}
static enum V_54
F_81 ( struct V_49 * V_50 , struct V_7 * V_63 , char * * V_103 )
{
memset ( V_63 , 0 , sizeof( * V_63 ) ) ;
V_63 -> type = V_76 ;
if ( F_73 ( V_50 , L_82 , & V_63 -> V_77 . V_68 ) )
goto V_111;
if ( F_73 ( V_50 , L_69 , & V_63 -> V_77 . V_2 ) )
goto V_171;
return F_45 ( V_103 ) ;
V_171:
F_32 ( V_63 -> V_77 . V_68 ) ;
V_111:
* V_103 = NULL ;
return V_57 ;
}
static enum V_54
F_82 ( struct V_49 * V_50 , struct V_7 * V_63 , char * * V_103 )
{
memset ( V_63 , 0 , sizeof( * V_63 ) ) ;
V_63 -> type = V_78 ;
if ( F_73 ( V_50 , L_82 , & V_63 -> V_79 . V_68 ) )
goto V_111;
if ( F_73 ( V_50 , L_82 , & V_63 -> V_79 . V_80 ) )
goto V_171;
if ( F_73 ( V_50 , L_69 , & V_63 -> V_79 . V_81 ) )
goto V_172;
return F_45 ( V_103 ) ;
V_172:
F_32 ( V_63 -> V_79 . V_80 ) ;
V_171:
F_32 ( V_63 -> V_79 . V_68 ) ;
V_111:
* V_103 = NULL ;
return V_57 ;
}
static enum V_54
F_83 ( struct V_49 * V_50 , struct V_7 * V_63 , char * * V_103 )
{
struct V_122 * V_68 ;
enum V_54 type ;
char * V_116 ;
memset ( V_63 , 0 , sizeof( * V_63 ) ) ;
V_63 -> type = V_88 ;
type = F_42 ( & V_116 ) ;
* V_103 = V_116 ;
if ( type != V_55 )
goto V_38;
V_68 = F_84 ( V_50 , V_116 ) ;
if ( ! V_68 )
goto V_38;
V_63 -> V_89 . V_68 = V_68 ;
V_63 -> V_89 . V_90 = 0 ;
if ( F_52 ( V_58 , L_69 ) < 0 )
goto V_38;
F_41 ( V_116 ) ;
type = F_45 ( & V_116 ) ;
* V_103 = V_116 ;
if ( type != V_102 || strcmp ( V_116 , L_38 ) != 0 )
return type ;
F_41 ( V_116 ) ;
V_63 = F_6 () ;
if ( ! V_63 ) {
F_61 ( V_50 , L_46 , V_131 ) ;
* V_103 = NULL ;
return V_57 ;
}
type = F_63 ( V_50 , V_63 , & V_116 ) ;
if ( type == V_57 )
goto V_173;
if ( ! F_48 ( type , V_116 , V_102 , L_39 ) )
goto V_173;
F_41 ( V_116 ) ;
type = F_45 ( V_103 ) ;
return type ;
V_173:
F_32 ( V_63 ) ;
V_38:
F_41 ( V_116 ) ;
* V_103 = NULL ;
return V_57 ;
}
static enum V_54
F_85 ( struct V_49 * V_50 , struct V_7 * V_63 , char * * V_103 )
{
struct V_7 * V_174 ;
enum V_54 type ;
char * V_116 ;
type = F_63 ( V_50 , V_63 , & V_116 ) ;
if ( type == V_57 )
goto V_38;
if ( type == V_102 )
type = F_66 ( V_50 , V_63 , & V_116 ) ;
if ( type == V_57 )
goto V_38;
if ( F_48 ( type , V_116 , V_58 , L_69 ) )
goto V_38;
F_41 ( V_116 ) ;
type = F_45 ( & V_116 ) ;
if ( F_30 ( type ) ||
( type == V_58 && strcmp ( V_116 , L_84 ) == 0 ) ) {
if ( V_63 -> type != V_65 ) {
F_61 ( V_50 , L_85 ) ;
goto V_38;
}
V_174 = F_6 () ;
if ( ! V_174 ) {
F_61 ( V_50 , L_46 ,
V_131 ) ;
goto V_38;
}
V_63 -> type = V_82 ;
V_63 -> V_83 . type = V_63 -> V_66 . V_66 ;
V_63 -> V_83 . V_17 = V_174 ;
type = F_64 ( V_50 , V_174 , & V_116 , type ) ;
}
* V_103 = V_116 ;
return type ;
V_38:
F_41 ( V_116 ) ;
* V_103 = NULL ;
return V_57 ;
}
static enum V_54
F_86 ( struct V_49 * V_50 V_156 , struct V_7 * V_63 ,
char * * V_103 )
{
enum V_54 type ;
char * V_116 ;
if ( F_50 ( V_55 , & V_116 ) < 0 )
goto V_38;
V_63 -> type = V_84 ;
V_63 -> string . string = V_116 ;
V_63 -> string . V_141 = - 1 ;
if ( F_52 ( V_58 , L_69 ) < 0 )
goto V_157;
type = F_42 ( & V_116 ) ;
* V_103 = V_116 ;
return type ;
V_38:
F_41 ( V_116 ) ;
V_157:
* V_103 = NULL ;
return V_57 ;
}
static enum V_54
F_87 ( struct V_49 * V_50 V_156 , struct V_7 * V_63 ,
char * * V_103 )
{
enum V_54 type ;
char * V_116 ;
if ( F_50 ( V_55 , & V_116 ) < 0 )
goto V_38;
V_63 -> type = V_86 ;
V_63 -> V_87 . V_87 = V_116 ;
V_63 -> V_87 . V_141 = - 1 ;
if ( F_52 ( V_58 , L_69 ) < 0 )
goto V_157;
type = F_42 ( & V_116 ) ;
* V_103 = V_116 ;
return type ;
V_38:
F_41 ( V_116 ) ;
V_157:
* V_103 = NULL ;
return V_57 ;
}
static struct V_175 *
F_88 ( struct V_14 * V_14 , char * V_176 )
{
struct V_175 * V_35 ;
if ( ! V_14 )
return NULL ;
for ( V_35 = V_14 -> V_177 ; V_35 ; V_35 = V_35 -> V_22 ) {
if ( strcmp ( V_35 -> V_69 , V_176 ) == 0 )
break;
}
return V_35 ;
}
static void F_89 ( struct V_14 * V_14 , char * V_176 )
{
struct V_175 * V_35 ;
struct V_175 * * V_22 ;
V_22 = & V_14 -> V_177 ;
while ( ( V_35 = * V_22 ) ) {
if ( strcmp ( V_35 -> V_69 , V_176 ) == 0 ) {
* V_22 = V_35 -> V_22 ;
F_90 ( V_35 ) ;
break;
}
V_22 = & V_35 -> V_22 ;
}
}
static enum V_54
F_91 ( struct V_49 * V_50 , struct V_175 * V_35 ,
struct V_7 * V_63 , char * * V_103 )
{
struct V_7 * * V_178 ;
struct V_7 * V_64 ;
enum V_54 type ;
char * V_116 ;
int V_19 ;
V_63 -> type = V_95 ;
V_63 -> V_35 . V_35 = V_35 ;
* V_103 = NULL ;
V_178 = & ( V_63 -> V_35 . args ) ;
for ( V_19 = 0 ; V_19 < V_35 -> V_179 ; V_19 ++ ) {
V_64 = F_6 () ;
if ( ! V_64 ) {
F_61 ( V_50 , L_46 ,
V_131 ) ;
return V_57 ;
}
type = F_63 ( V_50 , V_64 , & V_116 ) ;
if ( V_19 < ( V_35 -> V_179 - 1 ) ) {
if ( type != V_58 || strcmp ( V_116 , L_82 ) != 0 ) {
F_61 ( V_50 ,
L_86 ,
V_35 -> V_69 , V_35 -> V_179 ,
V_50 -> V_69 , V_19 + 1 ) ;
goto V_180;
}
} else {
if ( type != V_58 || strcmp ( V_116 , L_69 ) != 0 ) {
F_61 ( V_50 ,
L_87 ,
V_35 -> V_69 , V_35 -> V_179 , V_50 -> V_69 ) ;
goto V_180;
}
}
* V_178 = V_64 ;
V_178 = & ( V_64 -> V_22 ) ;
F_41 ( V_116 ) ;
}
type = F_42 ( & V_116 ) ;
* V_103 = V_116 ;
return type ;
V_180:
F_32 ( V_64 ) ;
F_41 ( V_116 ) ;
return V_57 ;
}
static enum V_54
F_92 ( struct V_49 * V_50 , struct V_7 * V_63 ,
char * V_116 , char * * V_103 )
{
struct V_175 * V_35 ;
if ( strcmp ( V_116 , L_88 ) == 0 ) {
F_41 ( V_116 ) ;
V_158 = 1 ;
return F_79 ( V_50 , V_63 , V_103 ) ;
}
if ( strcmp ( V_116 , L_89 ) == 0 ) {
F_41 ( V_116 ) ;
V_160 = 1 ;
return F_80 ( V_50 , V_63 , V_103 ) ;
}
if ( strcmp ( V_116 , L_90 ) == 0 ) {
F_41 ( V_116 ) ;
return F_81 ( V_50 , V_63 , V_103 ) ;
}
if ( strcmp ( V_116 , L_91 ) == 0 ) {
F_41 ( V_116 ) ;
return F_82 ( V_50 , V_63 , V_103 ) ;
}
if ( strcmp ( V_116 , L_92 ) == 0 ) {
F_41 ( V_116 ) ;
return F_86 ( V_50 , V_63 , V_103 ) ;
}
if ( strcmp ( V_116 , L_93 ) == 0 ) {
F_41 ( V_116 ) ;
return F_87 ( V_50 , V_63 , V_103 ) ;
}
if ( strcmp ( V_116 , L_94 ) == 0 ) {
F_41 ( V_116 ) ;
return F_83 ( V_50 , V_63 , V_103 ) ;
}
V_35 = F_88 ( V_50 -> V_14 , V_116 ) ;
if ( V_35 ) {
F_41 ( V_116 ) ;
return F_91 ( V_50 , V_35 , V_63 , V_103 ) ;
}
F_61 ( V_50 , L_95 , V_116 ) ;
F_41 ( V_116 ) ;
return V_57 ;
}
static enum V_54
F_64 ( struct V_49 * V_50 , struct V_7 * V_63 ,
char * * V_103 , enum V_54 type )
{
char * V_116 ;
char * V_66 ;
V_116 = * V_103 ;
switch ( type ) {
case V_55 :
if ( strcmp ( V_116 , L_96 ) == 0 ) {
F_41 ( V_116 ) ;
type = F_71 ( V_50 , V_63 , & V_116 ) ;
break;
}
V_66 = V_116 ;
type = F_45 ( & V_116 ) ;
if ( type == V_58 && strcmp ( V_116 , L_84 ) == 0 ) {
F_41 ( V_116 ) ;
V_116 = NULL ;
type = F_92 ( V_50 , V_63 , V_66 , & V_116 ) ;
break;
}
while ( type == V_55 ) {
char * V_154 ;
V_154 = realloc ( V_66 ,
strlen ( V_66 ) + strlen ( V_116 ) + 2 ) ;
if ( ! V_154 ) {
free ( V_66 ) ;
* V_103 = NULL ;
F_41 ( V_116 ) ;
return V_57 ;
}
V_66 = V_154 ;
strcat ( V_66 , L_36 ) ;
strcat ( V_66 , V_116 ) ;
F_41 ( V_116 ) ;
type = F_45 ( & V_116 ) ;
}
V_63 -> type = V_65 ;
V_63 -> V_66 . V_66 = V_66 ;
break;
case V_100 :
case V_56 :
V_63 -> type = V_65 ;
V_63 -> V_66 . V_66 = V_116 ;
type = F_45 ( & V_116 ) ;
break;
case V_58 :
if ( strcmp ( V_116 , L_84 ) == 0 ) {
F_41 ( V_116 ) ;
type = F_85 ( V_50 , V_63 , & V_116 ) ;
break;
}
case V_102 :
V_63 -> type = V_91 ;
V_63 -> V_92 . V_92 = V_116 ;
V_63 -> V_92 . V_93 = NULL ;
type = F_66 ( V_50 , V_63 , & V_116 ) ;
if ( type == V_57 )
V_63 -> V_92 . V_92 = NULL ;
break;
case V_57 ... V_98 :
default:
F_61 ( V_50 , L_97 , type ) ;
return V_57 ;
}
* V_103 = V_116 ;
return type ;
}
static int F_93 ( struct V_49 * V_50 , struct V_7 * * V_169 )
{
enum V_54 type = V_57 ;
struct V_7 * V_63 ;
char * V_116 ;
int args = 0 ;
do {
if ( type == V_98 ) {
type = F_45 ( & V_116 ) ;
continue;
}
V_63 = F_6 () ;
if ( ! V_63 ) {
F_61 ( V_50 , L_46 ,
V_131 ) ;
return - 1 ;
}
type = F_63 ( V_50 , V_63 , & V_116 ) ;
if ( type == V_57 ) {
F_41 ( V_116 ) ;
F_32 ( V_63 ) ;
return - 1 ;
}
* V_169 = V_63 ;
args ++ ;
if ( type == V_102 ) {
type = F_66 ( V_50 , V_63 , & V_116 ) ;
F_41 ( V_116 ) ;
if ( type == V_57 ) {
* V_169 = NULL ;
F_32 ( V_63 ) ;
return - 1 ;
}
V_169 = & V_63 -> V_22 ;
continue;
}
if ( type == V_58 && strcmp ( V_116 , L_82 ) == 0 ) {
F_41 ( V_116 ) ;
* V_169 = V_63 ;
V_169 = & V_63 -> V_22 ;
continue;
}
break;
} while ( type != V_101 );
if ( type != V_101 && type != V_57 )
F_41 ( V_116 ) ;
return args ;
}
static int F_94 ( struct V_49 * V_50 )
{
enum V_54 type ;
char * V_116 ;
int V_120 ;
if ( F_53 ( V_55 , L_98 ) < 0 )
return - 1 ;
if ( F_52 ( V_55 , L_99 ) < 0 )
return - 1 ;
if ( F_52 ( V_102 , L_19 ) < 0 )
return - 1 ;
if ( F_50 ( V_100 , & V_116 ) < 0 )
goto V_121;
V_112:
V_50 -> V_181 . V_145 = V_116 ;
V_50 -> V_181 . args = NULL ;
type = F_45 ( & V_116 ) ;
if ( type == V_101 )
return 0 ;
if ( type == V_100 ) {
char * V_182 ;
if ( F_39 ( & V_182 , L_100 , V_50 -> V_181 . V_145 , V_116 ) < 0 )
goto V_121;
F_41 ( V_116 ) ;
F_41 ( V_50 -> V_181 . V_145 ) ;
V_50 -> V_181 . V_145 = NULL ;
V_116 = V_182 ;
goto V_112;
}
if ( F_48 ( type , V_116 , V_58 , L_82 ) )
goto V_121;
F_41 ( V_116 ) ;
V_120 = F_93 ( V_50 , & V_50 -> V_181 . args ) ;
if ( V_120 < 0 )
return - 1 ;
return V_120 ;
V_121:
F_41 ( V_116 ) ;
return - 1 ;
}
struct V_122 *
F_95 ( struct V_49 * V_50 , const char * V_69 )
{
struct V_122 * V_145 ;
for ( V_145 = V_50 -> V_145 . V_146 ;
V_145 ; V_145 = V_145 -> V_22 ) {
if ( strcmp ( V_145 -> V_69 , V_69 ) == 0 )
break;
}
return V_145 ;
}
struct V_122 *
F_84 ( struct V_49 * V_50 , const char * V_69 )
{
struct V_122 * V_145 ;
for ( V_145 = V_50 -> V_145 . V_125 ;
V_145 ; V_145 = V_145 -> V_22 ) {
if ( strcmp ( V_145 -> V_69 , V_69 ) == 0 )
break;
}
return V_145 ;
}
struct V_122 *
F_72 ( struct V_49 * V_50 , const char * V_69 )
{
struct V_122 * V_145 ;
V_145 = F_95 ( V_50 , V_69 ) ;
if ( V_145 )
return V_145 ;
return F_84 ( V_50 , V_69 ) ;
}
unsigned long long F_96 ( struct V_14 * V_14 ,
const void * V_183 , int V_2 )
{
switch ( V_2 ) {
case 1 :
return * ( unsigned char * ) V_183 ;
case 2 :
return F_97 ( V_14 , V_183 ) ;
case 4 :
return F_98 ( V_14 , V_183 ) ;
case 8 :
return F_99 ( V_14 , V_183 ) ;
default:
return 0 ;
}
}
int F_100 ( struct V_122 * V_68 , const void * V_184 ,
unsigned long long * V_61 )
{
if ( ! V_68 )
return - 1 ;
switch ( V_68 -> V_2 ) {
case 1 :
case 2 :
case 4 :
case 8 :
* V_61 = F_96 ( V_68 -> V_50 -> V_14 ,
V_184 + V_68 -> V_141 , V_68 -> V_2 ) ;
return 0 ;
default:
return - 1 ;
}
}
static int F_101 ( struct V_14 * V_14 ,
const char * type , int * V_141 , int * V_2 )
{
struct V_49 * V_50 ;
struct V_122 * V_68 ;
if ( ! V_14 -> V_51 ) {
F_47 ( L_101 ) ;
return - 1 ;
}
V_50 = V_14 -> V_51 [ 0 ] ;
V_68 = F_95 ( V_50 , type ) ;
if ( ! V_68 )
return - 1 ;
* V_141 = V_68 -> V_141 ;
* V_2 = V_68 -> V_2 ;
return 0 ;
}
static int F_102 ( struct V_14 * V_14 , void * V_184 ,
int * V_2 , int * V_141 , const char * V_69 )
{
int V_120 ;
if ( ! * V_2 ) {
V_120 = F_101 ( V_14 , V_69 , V_141 , V_2 ) ;
if ( V_120 < 0 )
return V_120 ;
}
return F_96 ( V_14 , V_184 + * V_141 , * V_2 ) ;
}
static int F_103 ( struct V_14 * V_14 , void * V_184 )
{
return F_102 ( V_14 , V_184 ,
& V_14 -> F_59 , & V_14 -> V_185 ,
L_102 ) ;
}
static int F_104 ( struct V_14 * V_14 , void * V_184 )
{
return F_102 ( V_14 , V_184 ,
& V_14 -> V_186 , & V_14 -> V_187 ,
L_103 ) ;
}
static int F_105 ( struct V_14 * V_14 , void * V_184 )
{
return F_102 ( V_14 , V_184 ,
& V_14 -> V_188 , & V_14 -> V_189 ,
L_104 ) ;
}
static int F_106 ( struct V_14 * V_14 , void * V_184 )
{
return F_102 ( V_14 , V_184 ,
& V_14 -> V_190 , & V_14 -> V_191 ,
L_105 ) ;
}
static int F_107 ( struct V_14 * V_14 , void * V_184 )
{
return F_102 ( V_14 , V_184 ,
& V_14 -> V_192 , & V_14 -> V_193 ,
L_106 ) ;
}
static int F_108 ( struct V_14 * V_14 , void * V_184 )
{
return F_102 ( V_14 , V_184 ,
& V_14 -> V_192 , & V_14 -> V_193 ,
L_107 ) ;
}
struct V_49 * F_109 ( struct V_14 * V_14 , int V_53 )
{
struct V_49 * * V_194 ;
struct V_49 V_23 ;
struct V_49 * V_195 = & V_23 ;
if ( V_14 -> V_196 && V_14 -> V_196 -> V_53 == V_53 )
return V_14 -> V_196 ;
V_23 . V_53 = V_53 ;
V_194 = bsearch ( & V_195 , V_14 -> V_51 , V_14 -> V_52 ,
sizeof( * V_14 -> V_51 ) , V_197 ) ;
if ( V_194 ) {
V_14 -> V_196 = * V_194 ;
return * V_194 ;
}
return NULL ;
}
struct V_49 *
F_110 ( struct V_14 * V_14 ,
const char * V_198 , const char * V_69 )
{
struct V_49 * V_50 ;
int V_19 ;
if ( V_14 -> V_196 &&
strcmp ( V_14 -> V_196 -> V_69 , V_69 ) == 0 &&
( ! V_198 || strcmp ( V_14 -> V_196 -> system , V_198 ) == 0 ) )
return V_14 -> V_196 ;
for ( V_19 = 0 ; V_19 < V_14 -> V_52 ; V_19 ++ ) {
V_50 = V_14 -> V_51 [ V_19 ] ;
if ( strcmp ( V_50 -> V_69 , V_69 ) == 0 ) {
if ( ! V_198 )
break;
if ( strcmp ( V_50 -> system , V_198 ) == 0 )
break;
}
}
if ( V_19 == V_14 -> V_52 )
V_50 = NULL ;
V_14 -> V_196 = V_50 ;
return V_50 ;
}
static unsigned long long
F_111 ( void * V_184 , int V_2 , struct V_49 * V_50 , struct V_7 * V_63 )
{
struct V_14 * V_14 = V_50 -> V_14 ;
unsigned long long V_165 = 0 ;
unsigned long long V_93 , V_94 ;
struct V_7 * V_199 = NULL ;
struct V_7 * V_200 ;
unsigned long V_141 ;
unsigned int V_201 ;
switch ( V_63 -> type ) {
case V_96 :
return 0 ;
case V_65 :
return F_112 ( V_63 -> V_66 . V_66 , NULL , 0 ) ;
case V_67 :
if ( ! V_63 -> V_68 . V_68 ) {
V_63 -> V_68 . V_68 = F_72 ( V_50 , V_63 -> V_68 . V_69 ) ;
if ( ! V_63 -> V_68 . V_68 )
goto V_202;
}
V_165 = F_96 ( V_14 , V_184 + V_63 -> V_68 . V_68 -> V_141 ,
V_63 -> V_68 . V_68 -> V_2 ) ;
break;
case V_70 :
case V_73 :
case V_78 :
case V_76 :
break;
case V_82 :
V_165 = F_111 ( V_184 , V_2 , V_50 , V_63 -> V_83 . V_17 ) ;
return F_75 ( V_165 , V_63 , 0 ) ;
case V_84 :
case V_85 :
case V_86 :
return 0 ;
case V_95 : {
struct V_203 V_204 ;
F_113 ( & V_204 ) ;
V_165 = F_114 ( & V_204 , V_184 , V_2 , V_50 , V_63 ) ;
F_115 ( & V_204 ) ;
return V_165 ;
}
case V_91 :
if ( strcmp ( V_63 -> V_92 . V_92 , L_38 ) == 0 ) {
V_94 = F_111 ( V_184 , V_2 , V_50 , V_63 -> V_92 . V_94 ) ;
V_200 = V_63 -> V_92 . V_93 ;
while ( V_200 -> type == V_82 ) {
if ( ! V_199 )
V_199 = V_200 ;
V_200 = V_200 -> V_83 . V_17 ;
}
V_201 = V_14 -> V_144 ;
switch ( V_200 -> type ) {
case V_88 :
V_141 = F_96 ( V_14 ,
V_184 + V_200 -> V_89 . V_68 -> V_141 ,
V_200 -> V_89 . V_68 -> V_2 ) ;
if ( V_200 -> V_89 . V_68 -> V_143 )
V_201 = V_200 -> V_89 . V_68 -> V_143 ;
V_141 &= 0xffff ;
V_141 += V_94 ;
break;
case V_67 :
if ( ! V_200 -> V_68 . V_68 ) {
V_200 -> V_68 . V_68 =
F_72 ( V_50 , V_200 -> V_68 . V_69 ) ;
if ( ! V_200 -> V_68 . V_68 ) {
V_63 = V_200 ;
goto V_202;
}
}
V_201 = V_200 -> V_68 . V_68 -> V_143 ;
V_141 = V_200 -> V_68 . V_68 -> V_141 +
V_94 * V_200 -> V_68 . V_68 -> V_143 ;
break;
default:
goto V_205;
}
V_165 = F_96 ( V_14 ,
V_184 + V_141 , V_201 ) ;
if ( V_199 )
V_165 = F_75 ( V_165 , V_199 , 1 ) ;
break;
} else if ( strcmp ( V_63 -> V_92 . V_92 , L_60 ) == 0 ) {
V_93 = F_111 ( V_184 , V_2 , V_50 , V_63 -> V_92 . V_93 ) ;
V_63 = V_63 -> V_92 . V_94 ;
if ( V_93 )
V_165 = F_111 ( V_184 , V_2 , V_50 , V_63 -> V_92 . V_93 ) ;
else
V_165 = F_111 ( V_184 , V_2 , V_50 , V_63 -> V_92 . V_94 ) ;
break;
}
V_205:
V_93 = F_111 ( V_184 , V_2 , V_50 , V_63 -> V_92 . V_93 ) ;
V_94 = F_111 ( V_184 , V_2 , V_50 , V_63 -> V_92 . V_94 ) ;
switch ( V_63 -> V_92 . V_92 [ 0 ] ) {
case '!' :
switch ( V_63 -> V_92 . V_92 [ 1 ] ) {
case 0 :
V_165 = ! V_94 ;
break;
case '=' :
V_165 = V_93 != V_94 ;
break;
default:
goto V_206;
}
break;
case '~' :
V_165 = ~ V_94 ;
break;
case '|' :
if ( V_63 -> V_92 . V_92 [ 1 ] )
V_165 = V_93 || V_94 ;
else
V_165 = V_93 | V_94 ;
break;
case '&' :
if ( V_63 -> V_92 . V_92 [ 1 ] )
V_165 = V_93 && V_94 ;
else
V_165 = V_93 & V_94 ;
break;
case '<' :
switch ( V_63 -> V_92 . V_92 [ 1 ] ) {
case 0 :
V_165 = V_93 < V_94 ;
break;
case '<' :
V_165 = V_93 << V_94 ;
break;
case '=' :
V_165 = V_93 <= V_94 ;
break;
default:
goto V_206;
}
break;
case '>' :
switch ( V_63 -> V_92 . V_92 [ 1 ] ) {
case 0 :
V_165 = V_93 > V_94 ;
break;
case '>' :
V_165 = V_93 >> V_94 ;
break;
case '=' :
V_165 = V_93 >= V_94 ;
break;
default:
goto V_206;
}
break;
case '=' :
if ( V_63 -> V_92 . V_92 [ 1 ] != '=' )
goto V_206;
V_165 = V_93 == V_94 ;
break;
case '-' :
V_165 = V_93 - V_94 ;
break;
case '+' :
V_165 = V_93 + V_94 ;
break;
case '/' :
V_165 = V_93 / V_94 ;
break;
case '*' :
V_165 = V_93 * V_94 ;
break;
default:
goto V_206;
}
break;
case V_88 :
V_141 = F_96 ( V_14 ,
V_184 + V_63 -> V_89 . V_68 -> V_141 ,
V_63 -> V_89 . V_68 -> V_2 ) ;
V_141 &= 0xffff ;
V_165 = ( unsigned long long ) ( ( unsigned long ) V_184 + V_141 ) ;
break;
default:
return 0 ;
}
return V_165 ;
V_206:
F_61 ( V_50 , L_108 , V_131 , V_63 -> V_92 . V_92 ) ;
return 0 ;
V_202:
F_61 ( V_50 , L_109 ,
V_131 , V_63 -> V_68 . V_69 ) ;
return 0 ;
}
static long long F_116 ( const char * V_207 )
{
int V_19 ;
if ( isdigit ( V_207 [ 0 ] ) )
return F_112 ( V_207 , NULL , 0 ) ;
for ( V_19 = 0 ; V_19 < ( int ) ( sizeof( V_71 ) / sizeof( V_71 [ 0 ] ) ) ; V_19 ++ )
if ( strcmp ( V_71 [ V_19 ] . V_69 , V_207 ) == 0 )
return V_71 [ V_19 ] . V_61 ;
return - 1LL ;
}
static void F_117 ( struct V_203 * V_204 , const char * V_145 ,
int V_208 , const char * V_62 )
{
if ( V_208 >= 0 )
F_118 ( V_204 , V_145 , V_208 , V_62 ) ;
else
F_118 ( V_204 , V_145 , V_62 ) ;
}
static void F_119 ( struct V_14 * V_14 ,
struct V_203 * V_204 , const char * V_145 ,
int V_208 , const void * V_184 , int V_2 )
{
int V_209 = V_2 * 8 ;
int V_210 = ( V_209 + 3 ) / 4 ;
int V_135 = 0 ;
char V_1 [ 3 ] ;
char * V_62 ;
int V_90 ;
int V_19 ;
V_210 += ( V_209 - 1 ) / 32 ;
V_62 = malloc ( V_210 + 1 ) ;
if ( ! V_62 ) {
F_47 ( L_46 , V_131 ) ;
return;
}
V_62 [ V_210 ] = 0 ;
for ( V_19 = V_210 - 2 ; V_19 >= 0 ; V_19 -= 2 ) {
if ( V_14 -> V_211 )
V_90 = V_2 - ( V_135 + 1 ) ;
else
V_90 = V_135 ;
snprintf ( V_1 , 3 , L_110 , * ( ( unsigned char * ) V_184 + V_90 ) ) ;
memcpy ( V_62 + V_19 , V_1 , 2 ) ;
V_135 ++ ;
if ( ! ( V_135 & 3 ) && V_19 > 0 ) {
V_19 -- ;
V_62 [ V_19 ] = ',' ;
}
}
if ( V_208 >= 0 )
F_118 ( V_204 , V_145 , V_208 , V_62 ) ;
else
F_118 ( V_204 , V_145 , V_62 ) ;
free ( V_62 ) ;
}
static void F_120 ( struct V_203 * V_204 , void * V_184 , int V_2 ,
struct V_49 * V_50 , const char * V_145 ,
int V_208 , struct V_7 * V_63 )
{
struct V_14 * V_14 = V_50 -> V_14 ;
struct V_59 * V_207 ;
struct V_122 * V_68 ;
struct V_40 * V_46 ;
long long V_165 , V_212 ;
unsigned long V_31 ;
char * V_62 ;
unsigned char * V_77 ;
int V_213 ;
int V_19 , V_135 ;
switch ( V_63 -> type ) {
case V_96 :
return;
case V_65 :
F_117 ( V_204 , V_145 , V_208 , V_63 -> V_66 . V_66 ) ;
return;
case V_67 :
V_68 = V_63 -> V_68 . V_68 ;
if ( ! V_68 ) {
V_68 = F_72 ( V_50 , V_63 -> V_68 . V_69 ) ;
if ( ! V_68 ) {
V_62 = V_63 -> V_68 . V_69 ;
goto V_202;
}
V_63 -> V_68 . V_68 = V_68 ;
}
V_135 = V_68 -> V_2 ? : V_2 - V_68 -> V_141 ;
if ( ! ( V_68 -> V_71 & V_123 ) &&
V_68 -> V_2 == V_14 -> V_144 ) {
V_31 = * ( unsigned long * ) ( V_184 + V_68 -> V_141 ) ;
V_46 = F_25 ( V_14 , V_31 ) ;
if ( V_46 )
F_121 ( V_204 , V_46 -> V_46 ) ;
else
F_118 ( V_204 , L_111 , V_31 ) ;
break;
}
V_62 = malloc ( V_135 + 1 ) ;
if ( ! V_62 ) {
F_61 ( V_50 , L_46 ,
V_131 ) ;
return;
}
memcpy ( V_62 , V_184 + V_68 -> V_141 , V_135 ) ;
V_62 [ V_135 ] = 0 ;
F_117 ( V_204 , V_145 , V_208 , V_62 ) ;
free ( V_62 ) ;
break;
case V_70 :
V_165 = F_111 ( V_184 , V_2 , V_50 , V_63 -> V_71 . V_68 ) ;
V_213 = 0 ;
for ( V_207 = V_63 -> V_71 . V_71 ; V_207 ; V_207 = V_207 -> V_22 ) {
V_212 = F_116 ( V_207 -> V_61 ) ;
if ( ! V_165 && V_212 < 0 ) {
F_117 ( V_204 , V_145 , V_208 , V_207 -> V_62 ) ;
break;
}
if ( V_212 > 0 && ( V_165 & V_212 ) == V_212 ) {
if ( V_213 && V_63 -> V_71 . V_72 )
F_121 ( V_204 , V_63 -> V_71 . V_72 ) ;
F_117 ( V_204 , V_145 , V_208 , V_207 -> V_62 ) ;
V_213 = 1 ;
V_165 &= ~ V_212 ;
}
}
break;
case V_73 :
V_165 = F_111 ( V_184 , V_2 , V_50 , V_63 -> V_74 . V_68 ) ;
for ( V_207 = V_63 -> V_74 . V_75 ; V_207 ; V_207 = V_207 -> V_22 ) {
V_212 = F_116 ( V_207 -> V_61 ) ;
if ( V_165 == V_212 ) {
F_117 ( V_204 , V_145 , V_208 , V_207 -> V_62 ) ;
break;
}
}
break;
case V_76 :
if ( V_63 -> V_77 . V_68 -> type == V_88 ) {
unsigned long V_141 ;
V_141 = F_96 ( V_14 ,
V_184 + V_63 -> V_77 . V_68 -> V_89 . V_68 -> V_141 ,
V_63 -> V_77 . V_68 -> V_89 . V_68 -> V_2 ) ;
V_77 = V_184 + ( V_141 & 0xffff ) ;
} else {
V_68 = V_63 -> V_77 . V_68 -> V_68 . V_68 ;
if ( ! V_68 ) {
V_62 = V_63 -> V_77 . V_68 -> V_68 . V_69 ;
V_68 = F_72 ( V_50 , V_62 ) ;
if ( ! V_68 )
goto V_202;
V_63 -> V_77 . V_68 -> V_68 . V_68 = V_68 ;
}
V_77 = V_184 + V_68 -> V_141 ;
}
V_135 = F_111 ( V_184 , V_2 , V_50 , V_63 -> V_77 . V_2 ) ;
for ( V_19 = 0 ; V_19 < V_135 ; V_19 ++ ) {
if ( V_19 )
F_122 ( V_204 , ' ' ) ;
F_118 ( V_204 , L_110 , V_77 [ V_19 ] ) ;
}
break;
case V_78 : {
void * V_214 ;
int V_81 ;
if ( V_63 -> V_79 . V_68 -> type == V_88 ) {
unsigned long V_141 ;
struct V_122 * V_68 =
V_63 -> V_79 . V_68 -> V_89 . V_68 ;
V_141 = F_96 ( V_14 ,
V_184 + V_68 -> V_141 ,
V_68 -> V_2 ) ;
V_214 = V_184 + ( V_141 & 0xffff ) ;
} else {
V_68 = V_63 -> V_79 . V_68 -> V_68 . V_68 ;
if ( ! V_68 ) {
V_62 = V_63 -> V_79 . V_68 -> V_68 . V_69 ;
V_68 = F_72 ( V_50 , V_62 ) ;
if ( ! V_68 )
goto V_202;
V_63 -> V_79 . V_68 -> V_68 . V_68 = V_68 ;
}
V_214 = V_184 + V_68 -> V_141 ;
}
V_135 = F_111 ( V_184 , V_2 , V_50 , V_63 -> V_79 . V_80 ) ;
V_81 = F_111 ( V_184 , V_2 , V_50 ,
V_63 -> V_79 . V_81 ) ;
for ( V_19 = 0 ; V_19 < V_135 ; V_19 ++ ) {
if ( V_19 )
F_122 ( V_204 , ' ' ) ;
if ( V_81 == 1 ) {
F_118 ( V_204 , L_112 , * ( V_215 * ) V_214 ) ;
} else if ( V_81 == 2 ) {
F_118 ( V_204 , L_112 , * ( V_216 * ) V_214 ) ;
} else if ( V_81 == 4 ) {
F_118 ( V_204 , L_112 , * ( V_217 * ) V_214 ) ;
} else if ( V_81 == 8 ) {
F_118 ( V_204 , L_113 V_218 , * ( V_219 * ) V_214 ) ;
} else {
F_118 ( V_204 , L_114 ,
V_81 , * ( V_215 * ) V_214 ) ;
V_81 = 1 ;
}
V_214 += V_81 ;
}
break;
}
case V_82 :
break;
case V_84 : {
int V_220 ;
if ( V_63 -> string . V_141 == - 1 ) {
struct V_122 * V_221 ;
V_221 = F_72 ( V_50 , V_63 -> string . string ) ;
V_63 -> string . V_141 = V_221 -> V_141 ;
}
V_220 = F_98 ( V_14 , V_184 + V_63 -> string . V_141 ) ;
V_220 &= 0xffff ;
F_117 ( V_204 , V_145 , V_208 , ( ( char * ) V_184 ) + V_220 ) ;
break;
}
case V_85 :
F_117 ( V_204 , V_145 , V_208 , V_63 -> string . string ) ;
break;
case V_86 : {
int V_222 ;
int V_223 ;
if ( V_63 -> V_87 . V_141 == - 1 ) {
struct V_122 * V_221 ;
V_221 = F_72 ( V_50 , V_63 -> V_87 . V_87 ) ;
V_63 -> V_87 . V_141 = V_221 -> V_141 ;
}
V_222 = F_98 ( V_14 , V_184 + V_63 -> V_87 . V_141 ) ;
V_223 = V_222 >> 16 ;
V_222 &= 0xffff ;
F_119 ( V_14 , V_204 , V_145 , V_208 ,
V_184 + V_222 , V_223 ) ;
break;
}
case V_91 :
if ( V_63 -> V_92 . V_92 [ 0 ] != '?' )
return;
V_165 = F_111 ( V_184 , V_2 , V_50 , V_63 -> V_92 . V_93 ) ;
if ( V_165 )
F_120 ( V_204 , V_184 , V_2 , V_50 ,
V_145 , V_208 , V_63 -> V_92 . V_94 -> V_92 . V_93 ) ;
else
F_120 ( V_204 , V_184 , V_2 , V_50 ,
V_145 , V_208 , V_63 -> V_92 . V_94 -> V_92 . V_94 ) ;
break;
case V_95 :
F_114 ( V_204 , V_184 , V_2 , V_50 , V_63 ) ;
break;
default:
break;
}
return;
V_202:
F_61 ( V_50 , L_109 ,
V_131 , V_63 -> V_68 . V_69 ) ;
}
static unsigned long long
F_114 ( struct V_203 * V_204 , void * V_184 , int V_2 ,
struct V_49 * V_50 , struct V_7 * V_63 )
{
struct V_175 * V_224 = V_63 -> V_35 . V_35 ;
struct V_225 * V_226 ;
unsigned long long * args ;
unsigned long long V_120 ;
struct V_7 * V_64 ;
struct V_203 V_62 ;
struct V_227 {
struct V_227 * V_22 ;
char * V_62 ;
} * V_228 = NULL , * string ;
int V_19 ;
if ( ! V_224 -> V_179 ) {
V_120 = (* V_224 -> V_35 )( V_204 , NULL ) ;
goto V_111;
}
V_64 = V_63 -> V_35 . args ;
V_226 = V_224 -> V_229 ;
V_120 = V_230 ;
args = malloc ( sizeof( * args ) * V_224 -> V_179 ) ;
if ( ! args )
goto V_111;
for ( V_19 = 0 ; V_19 < V_224 -> V_179 ; V_19 ++ ) {
switch ( V_226 -> type ) {
case V_231 :
case V_232 :
case V_233 :
args [ V_19 ] = F_111 ( V_184 , V_2 , V_50 , V_64 ) ;
break;
case V_234 :
F_113 ( & V_62 ) ;
F_120 ( & V_62 , V_184 , V_2 , V_50 , L_115 , - 1 , V_64 ) ;
F_123 ( & V_62 ) ;
string = malloc ( sizeof( * string ) ) ;
if ( ! string ) {
F_61 ( V_50 , L_116 ,
V_131 , __LINE__ ) ;
goto V_38;
}
string -> V_22 = V_228 ;
string -> V_62 = F_12 ( V_62 . V_235 ) ;
if ( ! string -> V_62 ) {
free ( string ) ;
F_61 ( V_50 , L_116 ,
V_131 , __LINE__ ) ;
goto V_38;
}
args [ V_19 ] = ( V_236 ) string -> V_62 ;
V_228 = string ;
F_115 ( & V_62 ) ;
break;
default:
F_61 ( V_50 , L_117 ) ;
goto V_38;
}
V_64 = V_64 -> V_22 ;
V_226 = V_226 -> V_22 ;
}
V_120 = (* V_224 -> V_35 )( V_204 , args ) ;
V_38:
free ( args ) ;
while ( V_228 ) {
string = V_228 ;
V_228 = string -> V_22 ;
free ( string -> V_62 ) ;
free ( string ) ;
}
V_111:
return V_120 ;
}
static void F_124 ( struct V_7 * args )
{
struct V_7 * V_22 ;
while ( args ) {
V_22 = args -> V_22 ;
F_32 ( args ) ;
args = V_22 ;
}
}
static struct V_7 * F_125 ( char * V_47 , void * V_184 , int V_2 , struct V_49 * V_50 )
{
struct V_14 * V_14 = V_50 -> V_14 ;
struct V_122 * V_68 , * V_237 ;
struct V_7 * args , * V_63 , * * V_22 ;
unsigned long long V_238 , V_165 ;
char * V_183 ;
void * V_239 ;
int V_240 ;
V_68 = V_14 -> V_241 ;
V_237 = V_14 -> V_242 ;
if ( ! V_68 ) {
V_68 = F_84 ( V_50 , L_118 ) ;
if ( ! V_68 ) {
F_61 ( V_50 , L_119 ) ;
return NULL ;
}
V_237 = F_84 ( V_50 , L_120 ) ;
if ( ! V_237 ) {
F_61 ( V_50 , L_121 ) ;
return NULL ;
}
V_14 -> V_241 = V_68 ;
V_14 -> V_242 = V_237 ;
}
V_238 = F_96 ( V_14 , V_184 + V_237 -> V_141 , V_237 -> V_2 ) ;
args = F_6 () ;
if ( ! args ) {
F_61 ( V_50 , L_122 ,
V_131 , __LINE__ ) ;
return NULL ;
}
V_63 = args ;
V_63 -> V_22 = NULL ;
V_22 = & V_63 -> V_22 ;
V_63 -> type = V_65 ;
if ( F_39 ( & V_63 -> V_66 . V_66 , L_80 , V_238 ) < 0 )
goto V_38;
for ( V_183 = V_47 + 5 , V_239 = V_184 + V_68 -> V_141 ;
V_239 < V_184 + V_2 && * V_183 ; V_183 ++ ) {
int V_243 = 0 ;
if ( * V_183 == '%' ) {
V_244:
V_183 ++ ;
switch ( * V_183 ) {
case '%' :
break;
case 'l' :
V_243 ++ ;
goto V_244;
case 'L' :
V_243 = 2 ;
goto V_244;
case '0' ... '9' :
goto V_244;
case '.' :
goto V_244;
case 'z' :
case 'Z' :
V_243 = 1 ;
goto V_244;
case 'p' :
V_243 = 1 ;
case 'd' :
case 'u' :
case 'x' :
case 'i' :
switch ( V_243 ) {
case 0 :
V_240 = 4 ;
break;
case 1 :
V_240 = V_14 -> V_144 ;
break;
case 2 :
V_240 = 8 ;
break;
default:
V_240 = V_243 ;
break;
}
case '*' :
if ( * V_183 == '*' )
V_240 = 4 ;
V_239 = ( void * ) ( ( ( unsigned long ) V_239 + 3 ) &
~ 3 ) ;
V_165 = F_96 ( V_14 , V_239 , V_240 ) ;
V_239 += V_240 ;
V_63 = F_6 () ;
if ( ! V_63 ) {
F_61 ( V_50 , L_122 ,
V_131 , __LINE__ ) ;
goto V_38;
}
V_63 -> V_22 = NULL ;
V_63 -> type = V_65 ;
if ( F_39 ( & V_63 -> V_66 . V_66 , L_80 , V_165 ) < 0 ) {
free ( V_63 ) ;
goto V_38;
}
* V_22 = V_63 ;
V_22 = & V_63 -> V_22 ;
if ( * V_183 == '*' )
goto V_244;
break;
case 's' :
V_63 = F_6 () ;
if ( ! V_63 ) {
F_61 ( V_50 , L_122 ,
V_131 , __LINE__ ) ;
goto V_38;
}
V_63 -> V_22 = NULL ;
V_63 -> type = V_85 ;
V_63 -> string . string = F_12 ( V_239 ) ;
if ( ! V_63 -> string . string )
goto V_38;
V_239 += strlen ( V_239 ) + 1 ;
* V_22 = V_63 ;
V_22 = & V_63 -> V_22 ;
default:
break;
}
}
}
return args ;
V_38:
F_124 ( args ) ;
return NULL ;
}
static char *
F_126 ( void * V_184 , int V_2 V_156 ,
struct V_49 * V_50 )
{
struct V_14 * V_14 = V_50 -> V_14 ;
unsigned long long V_31 ;
struct V_122 * V_68 ;
struct V_40 * V_46 ;
char * V_145 ;
V_68 = V_14 -> V_245 ;
if ( ! V_68 ) {
V_68 = F_84 ( V_50 , L_99 ) ;
if ( ! V_68 ) {
F_61 ( V_50 , L_123 ) ;
return NULL ;
}
V_14 -> V_245 = V_68 ;
}
V_31 = F_96 ( V_14 , V_184 + V_68 -> V_141 , V_68 -> V_2 ) ;
V_46 = F_25 ( V_14 , V_31 ) ;
if ( ! V_46 ) {
if ( F_39 ( & V_145 , L_124 , V_31 ) < 0 )
return NULL ;
return V_145 ;
}
if ( F_39 ( & V_145 , L_125 , L_126 , V_46 -> V_46 ) < 0 )
return NULL ;
return V_145 ;
}
static void F_127 ( struct V_203 * V_204 , int V_246 , void * V_184 , int V_2 ,
struct V_49 * V_50 , struct V_7 * V_63 )
{
unsigned char * V_1 ;
const char * V_47 = L_127 ;
if ( V_63 -> type == V_95 ) {
F_114 ( V_204 , V_184 , V_2 , V_50 , V_63 ) ;
return;
}
if ( V_63 -> type != V_67 ) {
F_118 ( V_204 , L_128 ,
V_63 -> type ) ;
return;
}
if ( V_246 == 'm' )
V_47 = L_129 ;
if ( ! V_63 -> V_68 . V_68 ) {
V_63 -> V_68 . V_68 =
F_72 ( V_50 , V_63 -> V_68 . V_69 ) ;
if ( ! V_63 -> V_68 . V_68 ) {
F_61 ( V_50 , L_109 ,
V_131 , V_63 -> V_68 . V_69 ) ;
return;
}
}
if ( V_63 -> V_68 . V_68 -> V_2 != 6 ) {
F_118 ( V_204 , L_130 ) ;
return;
}
V_1 = V_184 + V_63 -> V_68 . V_68 -> V_141 ;
F_118 ( V_204 , V_47 , V_1 [ 0 ] , V_1 [ 1 ] , V_1 [ 2 ] , V_1 [ 3 ] , V_1 [ 4 ] , V_1 [ 5 ] ) ;
}
static void F_128 ( struct V_203 * V_204 , char V_19 , unsigned char * V_1 )
{
const char * V_47 ;
if ( V_19 == 'i' )
V_47 = L_131 ;
else
V_47 = L_132 ;
F_118 ( V_204 , V_47 , V_1 [ 0 ] , V_1 [ 1 ] , V_1 [ 2 ] , V_1 [ 3 ] ) ;
}
static inline bool F_129 ( const struct V_247 * V_8 )
{
return ( ( unsigned long ) ( V_8 -> V_248 [ 0 ] | V_8 -> V_248 [ 1 ] ) |
( unsigned long ) ( V_8 -> V_248 [ 2 ] ^ F_130 ( 0x0000ffff ) ) ) == 0UL ;
}
static inline bool F_131 ( const struct V_247 * V_31 )
{
return ( V_31 -> V_248 [ 2 ] | F_130 ( 0x02000000 ) ) == F_130 ( 0x02005EFE ) ;
}
static void F_132 ( struct V_203 * V_204 , unsigned char * V_31 )
{
int V_19 , V_249 , V_250 ;
unsigned char V_251 [ 8 ] ;
int V_252 = 1 ;
int V_253 = - 1 ;
V_216 V_254 ;
V_215 V_255 , V_256 ;
bool V_257 = false ;
bool V_258 ;
struct V_247 V_259 ;
memcpy ( & V_259 , V_31 , sizeof( struct V_247 ) ) ;
V_258 = F_129 ( & V_259 ) || F_131 ( & V_259 ) ;
memset ( V_251 , 0 , sizeof( V_251 ) ) ;
if ( V_258 )
V_250 = 6 ;
else
V_250 = 8 ;
for ( V_19 = 0 ; V_19 < V_250 ; V_19 ++ ) {
for ( V_249 = V_19 ; V_249 < V_250 ; V_249 ++ ) {
if ( V_259 . V_260 [ V_249 ] != 0 )
break;
V_251 [ V_19 ] ++ ;
}
}
for ( V_19 = 0 ; V_19 < V_250 ; V_19 ++ ) {
if ( V_251 [ V_19 ] > V_252 ) {
V_252 = V_251 [ V_19 ] ;
V_253 = V_19 ;
}
}
if ( V_252 == 1 )
V_253 = - 1 ;
for ( V_19 = 0 ; V_19 < V_250 ; V_19 ++ ) {
if ( V_19 == V_253 ) {
if ( V_257 || V_19 == 0 )
F_118 ( V_204 , L_19 ) ;
F_118 ( V_204 , L_19 ) ;
V_257 = false ;
V_19 += V_252 - 1 ;
continue;
}
if ( V_257 ) {
F_118 ( V_204 , L_19 ) ;
V_257 = false ;
}
V_254 = F_133 ( V_259 . V_260 [ V_19 ] ) ;
V_255 = V_254 >> 8 ;
V_256 = V_254 & 0xff ;
if ( V_255 )
F_118 ( V_204 , L_133 , V_255 , V_256 ) ;
else
F_118 ( V_204 , L_134 , V_256 ) ;
V_257 = true ;
}
if ( V_258 ) {
if ( V_257 )
F_118 ( V_204 , L_19 ) ;
F_128 ( V_204 , 'I' , & V_259 . V_261 [ 12 ] ) ;
}
return;
}
static void F_134 ( struct V_203 * V_204 , char V_19 , unsigned char * V_1 )
{
int V_249 ;
for ( V_249 = 0 ; V_249 < 16 ; V_249 += 2 ) {
F_118 ( V_204 , L_135 , V_1 [ V_249 ] , V_1 [ V_249 + 1 ] ) ;
if ( V_19 == 'I' && V_249 < 14 )
F_118 ( V_204 , L_19 ) ;
}
}
static int F_135 ( struct V_203 * V_204 , const char * V_183 , char V_19 ,
void * V_184 , int V_2 , struct V_49 * V_50 ,
struct V_7 * V_63 )
{
unsigned char * V_1 ;
if ( V_63 -> type == V_95 ) {
F_114 ( V_204 , V_184 , V_2 , V_50 , V_63 ) ;
return 0 ;
}
if ( V_63 -> type != V_67 ) {
F_118 ( V_204 , L_128 , V_63 -> type ) ;
return 0 ;
}
if ( ! V_63 -> V_68 . V_68 ) {
V_63 -> V_68 . V_68 =
F_72 ( V_50 , V_63 -> V_68 . V_69 ) ;
if ( ! V_63 -> V_68 . V_68 ) {
F_47 ( L_109 ,
V_131 , V_63 -> V_68 . V_69 ) ;
return 0 ;
}
}
V_1 = V_184 + V_63 -> V_68 . V_68 -> V_141 ;
if ( V_63 -> V_68 . V_68 -> V_2 != 4 ) {
F_118 ( V_204 , L_136 ) ;
return 0 ;
}
F_128 ( V_204 , V_19 , V_1 ) ;
return 0 ;
}
static int F_136 ( struct V_203 * V_204 , const char * V_183 , char V_19 ,
void * V_184 , int V_2 , struct V_49 * V_50 ,
struct V_7 * V_63 )
{
char V_262 = 0 ;
unsigned char * V_1 ;
int V_263 = 0 ;
if ( V_19 == 'I' && * V_183 == 'c' ) {
V_262 = 1 ;
V_183 ++ ;
V_263 ++ ;
}
if ( V_63 -> type == V_95 ) {
F_114 ( V_204 , V_184 , V_2 , V_50 , V_63 ) ;
return V_263 ;
}
if ( V_63 -> type != V_67 ) {
F_118 ( V_204 , L_128 , V_63 -> type ) ;
return V_263 ;
}
if ( ! V_63 -> V_68 . V_68 ) {
V_63 -> V_68 . V_68 =
F_72 ( V_50 , V_63 -> V_68 . V_69 ) ;
if ( ! V_63 -> V_68 . V_68 ) {
F_47 ( L_109 ,
V_131 , V_63 -> V_68 . V_69 ) ;
return V_263 ;
}
}
V_1 = V_184 + V_63 -> V_68 . V_68 -> V_141 ;
if ( V_63 -> V_68 . V_68 -> V_2 != 16 ) {
F_118 ( V_204 , L_137 ) ;
return V_263 ;
}
if ( V_262 )
F_132 ( V_204 , V_1 ) ;
else
F_134 ( V_204 , V_19 , V_1 ) ;
return V_263 ;
}
static int F_137 ( struct V_203 * V_204 , const char * V_183 , char V_19 ,
void * V_184 , int V_2 , struct V_49 * V_50 ,
struct V_7 * V_63 )
{
char V_262 = 0 , V_264 = 0 ;
unsigned char * V_1 ;
struct V_265 * V_266 ;
int V_263 = 0 ;
if ( V_19 == 'I' ) {
if ( * V_183 == 'p' ) {
V_264 = 1 ;
V_183 ++ ;
V_263 ++ ;
}
if ( * V_183 == 'c' ) {
V_262 = 1 ;
V_183 ++ ;
V_263 ++ ;
}
}
if ( V_63 -> type == V_95 ) {
F_114 ( V_204 , V_184 , V_2 , V_50 , V_63 ) ;
return V_263 ;
}
if ( V_63 -> type != V_67 ) {
F_118 ( V_204 , L_128 , V_63 -> type ) ;
return V_263 ;
}
if ( ! V_63 -> V_68 . V_68 ) {
V_63 -> V_68 . V_68 =
F_72 ( V_50 , V_63 -> V_68 . V_69 ) ;
if ( ! V_63 -> V_68 . V_68 ) {
F_47 ( L_109 ,
V_131 , V_63 -> V_68 . V_69 ) ;
return V_263 ;
}
}
V_266 = (struct V_265 * ) ( V_184 + V_63 -> V_68 . V_68 -> V_141 ) ;
if ( V_266 -> V_267 == V_268 ) {
struct V_269 * V_270 = (struct V_269 * ) V_266 ;
if ( V_63 -> V_68 . V_68 -> V_2 < sizeof( struct V_269 ) ) {
F_118 ( V_204 , L_136 ) ;
return V_263 ;
}
F_128 ( V_204 , V_19 , ( unsigned char * ) & V_270 -> V_271 ) ;
if ( V_264 )
F_118 ( V_204 , L_138 , F_133 ( V_270 -> V_272 ) ) ;
} else if ( V_266 -> V_267 == V_273 ) {
struct V_274 * V_275 = (struct V_274 * ) V_266 ;
if ( V_63 -> V_68 . V_68 -> V_2 < sizeof( struct V_274 ) ) {
F_118 ( V_204 , L_137 ) ;
return V_263 ;
}
if ( V_264 )
F_118 ( V_204 , L_38 ) ;
V_1 = ( unsigned char * ) & V_275 -> V_276 ;
if ( V_262 )
F_132 ( V_204 , V_1 ) ;
else
F_134 ( V_204 , V_19 , V_1 ) ;
if ( V_264 )
F_118 ( V_204 , L_139 , F_133 ( V_275 -> V_277 ) ) ;
}
return V_263 ;
}
static int F_138 ( struct V_203 * V_204 , const char * V_183 ,
void * V_184 , int V_2 , struct V_49 * V_50 ,
struct V_7 * V_63 )
{
char V_19 = * V_183 ;
char V_278 ;
int V_263 = 0 ;
V_183 ++ ;
V_263 ++ ;
V_278 = * V_183 ;
V_183 ++ ;
V_263 ++ ;
switch ( V_278 ) {
case '4' :
V_263 += F_135 ( V_204 , V_183 , V_19 , V_184 , V_2 , V_50 , V_63 ) ;
break;
case '6' :
V_263 += F_136 ( V_204 , V_183 , V_19 , V_184 , V_2 , V_50 , V_63 ) ;
break;
case 'S' :
V_263 += F_137 ( V_204 , V_183 , V_19 , V_184 , V_2 , V_50 , V_63 ) ;
break;
default:
return 0 ;
}
return V_263 ;
}
static int F_139 ( char * V_48 , unsigned int V_135 )
{
unsigned int V_19 ;
for ( V_19 = 0 ; V_19 < V_135 && V_48 [ V_19 ] ; V_19 ++ )
if ( ! isprint ( V_48 [ V_19 ] ) && ! isspace ( V_48 [ V_19 ] ) )
return 0 ;
return 1 ;
}
static void F_140 ( struct V_203 * V_204 , void * V_184 ,
int V_2 V_156 ,
struct V_49 * V_50 )
{
struct V_122 * V_68 ;
unsigned long long V_165 ;
unsigned int V_141 , V_135 , V_19 ;
V_68 = V_50 -> V_145 . V_125 ;
while ( V_68 ) {
F_118 ( V_204 , L_140 , V_68 -> V_69 ) ;
if ( V_68 -> V_71 & V_123 ) {
V_141 = V_68 -> V_141 ;
V_135 = V_68 -> V_2 ;
if ( V_68 -> V_71 & V_138 ) {
V_165 = F_96 ( V_50 -> V_14 , V_184 + V_141 , V_135 ) ;
V_141 = V_165 ;
V_135 = V_141 >> 16 ;
V_141 &= 0xffff ;
}
if ( V_68 -> V_71 & V_137 &&
F_139 ( V_184 + V_141 , V_135 ) ) {
F_118 ( V_204 , L_115 , ( char * ) V_184 + V_141 ) ;
} else {
F_121 ( V_204 , L_141 ) ;
for ( V_19 = 0 ; V_19 < V_135 ; V_19 ++ ) {
if ( V_19 )
F_121 ( V_204 , L_142 ) ;
F_118 ( V_204 , L_110 ,
* ( ( unsigned char * ) V_184 + V_141 + V_19 ) ) ;
}
F_122 ( V_204 , ']' ) ;
V_68 -> V_71 &= ~ V_137 ;
}
} else {
V_165 = F_96 ( V_50 -> V_14 , V_184 + V_68 -> V_141 ,
V_68 -> V_2 ) ;
if ( V_68 -> V_71 & V_129 ) {
F_118 ( V_204 , L_143 , V_165 ) ;
} else if ( V_68 -> V_71 & V_142 ) {
switch ( V_68 -> V_2 ) {
case 4 :
if ( V_68 -> V_71 & V_139 )
F_118 ( V_204 , L_144 , ( int ) V_165 ) ;
else
F_118 ( V_204 , L_145 , ( int ) V_165 ) ;
break;
case 2 :
F_118 ( V_204 , L_146 , ( short ) V_165 ) ;
break;
case 1 :
F_118 ( V_204 , L_147 , ( char ) V_165 ) ;
break;
default:
F_118 ( V_204 , L_80 , V_165 ) ;
}
} else {
if ( V_68 -> V_71 & V_139 )
F_118 ( V_204 , L_143 , V_165 ) ;
else
F_118 ( V_204 , L_148 , V_165 ) ;
}
}
V_68 = V_68 -> V_22 ;
}
}
static void F_141 ( struct V_203 * V_204 , void * V_184 , int V_2 , struct V_49 * V_50 )
{
struct V_14 * V_14 = V_50 -> V_14 ;
struct V_181 * V_181 = & V_50 -> V_181 ;
struct V_7 * V_63 = V_181 -> args ;
struct V_7 * args = NULL ;
const char * V_183 = V_181 -> V_145 ;
unsigned long long V_165 ;
struct V_28 * V_35 ;
const char * V_279 ;
struct V_203 V_48 ;
char * V_280 = NULL ;
char V_145 [ 32 ] ;
int V_281 ;
int V_282 ;
int V_208 ;
int V_135 ;
int V_243 ;
if ( V_50 -> V_71 & V_153 ) {
F_118 ( V_204 , L_149 ) ;
F_140 ( V_204 , V_184 , V_2 , V_50 ) ;
return;
}
if ( V_50 -> V_71 & V_283 ) {
V_280 = F_126 ( V_184 , V_2 , V_50 ) ;
args = F_125 ( V_280 , V_184 , V_2 , V_50 ) ;
V_63 = args ;
V_183 = V_280 ;
}
for (; * V_183 ; V_183 ++ ) {
V_243 = 0 ;
if ( * V_183 == '\\' ) {
V_183 ++ ;
switch ( * V_183 ) {
case 'n' :
F_122 ( V_204 , '\n' ) ;
break;
case 't' :
F_122 ( V_204 , '\t' ) ;
break;
case 'r' :
F_122 ( V_204 , '\r' ) ;
break;
case '\\' :
F_122 ( V_204 , '\\' ) ;
break;
default:
F_122 ( V_204 , * V_183 ) ;
break;
}
} else if ( * V_183 == '%' ) {
V_279 = V_183 ;
V_281 = 0 ;
V_282 = 0 ;
V_284:
V_183 ++ ;
switch ( * V_183 ) {
case '%' :
F_122 ( V_204 , '%' ) ;
break;
case '#' :
goto V_284;
case 'h' :
V_243 -- ;
goto V_284;
case 'l' :
V_243 ++ ;
goto V_284;
case 'L' :
V_243 = 2 ;
goto V_284;
case '*' :
if ( ! V_63 ) {
F_61 ( V_50 , L_150 ) ;
V_50 -> V_71 |= V_153 ;
goto V_285;
}
V_208 = F_111 ( V_184 , V_2 , V_50 , V_63 ) ;
V_282 = 1 ;
V_63 = V_63 -> V_22 ;
goto V_284;
case '.' :
case 'z' :
case 'Z' :
case '0' ... '9' :
goto V_284;
case 'p' :
if ( V_14 -> V_144 == 4 )
V_243 = 1 ;
else
V_243 = 2 ;
if ( * ( V_183 + 1 ) == 'F' ||
* ( V_183 + 1 ) == 'f' ) {
V_183 ++ ;
V_281 = * V_183 ;
} else if ( * ( V_183 + 1 ) == 'M' || * ( V_183 + 1 ) == 'm' ) {
F_127 ( V_204 , * ( V_183 + 1 ) , V_184 , V_2 , V_50 , V_63 ) ;
V_183 ++ ;
V_63 = V_63 -> V_22 ;
break;
} else if ( * ( V_183 + 1 ) == 'I' || * ( V_183 + 1 ) == 'i' ) {
int V_286 ;
V_286 = F_138 ( V_204 , V_183 + 1 , V_184 , V_2 , V_50 , V_63 ) ;
if ( V_286 > 0 ) {
V_183 += V_286 ;
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
F_61 ( V_50 , L_150 ) ;
V_50 -> V_71 |= V_153 ;
goto V_285;
}
V_135 = ( ( unsigned long ) V_183 + 1 ) -
( unsigned long ) V_279 ;
if ( V_135 > 31 ) {
F_61 ( V_50 , L_151 ) ;
V_50 -> V_71 |= V_153 ;
V_135 = 31 ;
}
memcpy ( V_145 , V_279 , V_135 ) ;
V_145 [ V_135 ] = 0 ;
V_165 = F_111 ( V_184 , V_2 , V_50 , V_63 ) ;
V_63 = V_63 -> V_22 ;
if ( V_281 ) {
V_35 = F_18 ( V_14 , V_165 ) ;
if ( V_35 ) {
F_121 ( V_204 , V_35 -> V_35 ) ;
if ( V_281 == 'F' )
F_118 ( V_204 ,
L_152 ,
V_165 - V_35 -> V_31 ) ;
break;
}
}
if ( V_14 -> V_144 == 8 && V_243 &&
sizeof( long ) != 8 ) {
char * V_48 ;
V_243 = 2 ;
V_48 = strchr ( V_145 , 'l' ) ;
if ( V_48 )
memmove ( V_48 + 1 , V_48 , strlen ( V_48 ) + 1 ) ;
else if ( strcmp ( V_145 , L_153 ) == 0 )
strcpy ( V_145 , L_143 ) ;
}
switch ( V_243 ) {
case - 2 :
if ( V_282 )
F_118 ( V_204 , V_145 , V_208 , ( char ) V_165 ) ;
else
F_118 ( V_204 , V_145 , ( char ) V_165 ) ;
break;
case - 1 :
if ( V_282 )
F_118 ( V_204 , V_145 , V_208 , ( short ) V_165 ) ;
else
F_118 ( V_204 , V_145 , ( short ) V_165 ) ;
break;
case 0 :
if ( V_282 )
F_118 ( V_204 , V_145 , V_208 , ( int ) V_165 ) ;
else
F_118 ( V_204 , V_145 , ( int ) V_165 ) ;
break;
case 1 :
if ( V_282 )
F_118 ( V_204 , V_145 , V_208 , ( long ) V_165 ) ;
else
F_118 ( V_204 , V_145 , ( long ) V_165 ) ;
break;
case 2 :
if ( V_282 )
F_118 ( V_204 , V_145 , V_208 ,
( long long ) V_165 ) ;
else
F_118 ( V_204 , V_145 , ( long long ) V_165 ) ;
break;
default:
F_61 ( V_50 , L_154 , V_243 ) ;
V_50 -> V_71 |= V_153 ;
}
break;
case 's' :
if ( ! V_63 ) {
F_61 ( V_50 , L_155 ) ;
V_50 -> V_71 |= V_153 ;
goto V_285;
}
V_135 = ( ( unsigned long ) V_183 + 1 ) -
( unsigned long ) V_279 ;
if ( V_135 > 31 ) {
F_61 ( V_50 , L_151 ) ;
V_50 -> V_71 |= V_153 ;
V_135 = 31 ;
}
memcpy ( V_145 , V_279 , V_135 ) ;
V_145 [ V_135 ] = 0 ;
if ( ! V_282 )
V_208 = - 1 ;
F_113 ( & V_48 ) ;
F_120 ( & V_48 , V_184 , V_2 , V_50 ,
V_145 , V_208 , V_63 ) ;
F_123 ( & V_48 ) ;
F_121 ( V_204 , V_48 . V_235 ) ;
F_115 ( & V_48 ) ;
V_63 = V_63 -> V_22 ;
break;
default:
F_118 ( V_204 , L_156 , * V_183 ) ;
}
} else
F_122 ( V_204 , * V_183 ) ;
}
if ( V_50 -> V_71 & V_153 ) {
V_285:
F_118 ( V_204 , L_149 ) ;
}
if ( args ) {
F_124 ( args ) ;
free ( V_280 ) ;
}
}
void F_142 ( struct V_14 * V_14 ,
struct V_203 * V_204 , struct V_287 * V_288 )
{
static int V_289 = 1 ;
static int V_290 = 1 ;
static int V_291 ;
static int V_292 ;
unsigned int V_293 ;
unsigned int V_294 ;
int V_295 ;
int V_296 ;
int V_297 ;
int V_298 ;
void * V_184 = V_288 -> V_184 ;
V_293 = F_106 ( V_14 , V_184 ) ;
V_294 = F_105 ( V_14 , V_184 ) ;
if ( V_291 )
V_295 = F_107 ( V_14 , V_184 ) ;
else if ( V_289 ) {
V_295 = F_107 ( V_14 , V_184 ) ;
if ( V_295 < 0 )
V_289 = 0 ;
else
V_291 = 1 ;
}
if ( V_292 )
V_296 = F_108 ( V_14 , V_184 ) ;
else if ( V_290 ) {
V_296 = F_108 ( V_14 , V_184 ) ;
if ( V_296 < 0 )
V_290 = 0 ;
else
V_292 = 1 ;
}
V_297 = V_293 & V_299 ;
V_298 = V_293 & V_300 ;
F_118 ( V_204 , L_157 ,
( V_293 & V_301 ) ? 'd' :
( V_293 & V_302 ) ?
'X' : '.' ,
( V_293 & V_303 ) ?
'N' : '.' ,
( V_297 && V_298 ) ? 'H' :
V_297 ? 'h' : V_298 ? 's' : '.' ) ;
if ( V_294 )
F_118 ( V_204 , L_134 , V_294 ) ;
else
F_122 ( V_204 , '.' ) ;
if ( V_292 ) {
if ( V_296 < 0 )
F_122 ( V_204 , '.' ) ;
else
F_118 ( V_204 , L_145 , V_296 ) ;
}
if ( V_291 ) {
if ( V_295 < 0 )
F_122 ( V_204 , '.' ) ;
else
F_118 ( V_204 , L_145 , V_295 ) ;
}
F_123 ( V_204 ) ;
}
int F_143 ( struct V_14 * V_14 , struct V_287 * V_304 )
{
return F_103 ( V_14 , V_304 -> V_184 ) ;
}
struct V_49 * F_144 ( struct V_14 * V_14 , int type )
{
return F_109 ( V_14 , type ) ;
}
int F_145 ( struct V_14 * V_14 , struct V_287 * V_304 )
{
return F_104 ( V_14 , V_304 -> V_184 ) ;
}
const char * F_146 ( struct V_14 * V_14 , int V_13 )
{
const char * V_21 ;
V_21 = F_9 ( V_14 , V_13 ) ;
return V_21 ;
}
static struct V_10 *
F_147 ( struct V_14 * V_14 , const char * V_21 , struct V_10 * V_22 )
{
struct V_15 * V_16 = (struct V_15 * ) V_22 ;
if ( V_16 )
V_16 = V_16 -> V_22 ;
else
V_16 = V_14 -> V_16 ;
while ( V_16 && strcmp ( V_16 -> V_21 , V_21 ) != 0 )
V_16 = V_16 -> V_22 ;
return (struct V_10 * ) V_16 ;
}
struct V_10 * F_148 ( struct V_14 * V_14 , const char * V_21 ,
struct V_10 * V_22 )
{
struct V_10 * V_10 ;
if ( ! V_14 -> V_18 )
return F_147 ( V_14 , V_21 , V_22 ) ;
if ( V_22 ) {
if ( V_22 < V_14 -> V_18 ||
V_22 >= V_14 -> V_18 + V_14 -> V_20 )
V_22 = NULL ;
else
V_10 = V_22 ++ ;
}
if ( ! V_22 )
V_10 = V_14 -> V_18 ;
while ( V_10 < V_14 -> V_18 + V_14 -> V_20 ) {
if ( strcmp ( V_10 -> V_21 , V_21 ) == 0 )
return V_10 ;
V_10 ++ ;
}
return NULL ;
}
int F_149 ( struct V_14 * V_14 , struct V_10 * V_10 )
{
struct V_15 * V_16 = (struct V_15 * ) V_10 ;
if ( ! V_10 )
return - 1 ;
if ( ! V_14 -> V_18 ||
V_10 < V_14 -> V_18 ||
V_10 >= V_14 -> V_18 + V_14 -> V_20 )
return V_16 -> V_13 ;
return V_10 -> V_13 ;
}
void F_150 ( struct V_203 * V_204 , struct V_49 * V_50 ,
struct V_287 * V_288 )
{
int V_305 = 1 ;
if ( V_50 -> V_14 -> V_306 || ( V_50 -> V_71 & V_307 ) )
F_140 ( V_204 , V_288 -> V_184 , V_288 -> V_2 , V_50 ) ;
else {
if ( V_50 -> V_308 && ! ( V_50 -> V_71 & V_309 ) )
V_305 = V_50 -> V_308 ( V_204 , V_288 , V_50 ,
V_50 -> V_310 ) ;
if ( V_305 )
F_141 ( V_204 , V_288 -> V_184 , V_288 -> V_2 , V_50 ) ;
}
F_123 ( V_204 ) ;
}
static bool F_151 ( char * V_27 , bool V_311 )
{
if ( ! V_311 )
return true ;
if ( ! strcmp ( V_27 , L_158 ) || ! strcmp ( V_27 , L_159 )
|| ! strcmp ( V_27 , L_160 ) || ! strcmp ( V_27 , L_161 ) )
return true ;
return false ;
}
void F_152 ( struct V_14 * V_14 , struct V_203 * V_204 ,
struct V_287 * V_288 , bool V_311 )
{
static const char * V_312 = L_162 ;
struct V_49 * V_50 ;
unsigned long V_313 ;
unsigned long V_314 ;
unsigned long V_315 ;
const char * V_21 ;
void * V_184 = V_288 -> V_184 ;
int type ;
int V_13 ;
int V_135 ;
int V_48 ;
bool V_316 ;
V_316 = F_151 ( V_14 -> V_27 ,
V_311 ) ;
if ( V_316 ) {
V_313 = V_288 -> V_317 / V_318 ;
V_315 = V_288 -> V_317 - V_313 * V_318 ;
}
if ( V_288 -> V_2 < 0 ) {
F_47 ( L_163 , V_288 -> V_2 ) ;
return;
}
type = F_103 ( V_14 , V_184 ) ;
V_50 = F_109 ( V_14 , type ) ;
if ( ! V_50 ) {
F_47 ( L_164 , type ) ;
return;
}
V_13 = F_104 ( V_14 , V_184 ) ;
V_21 = F_9 ( V_14 , V_13 ) ;
if ( V_14 -> V_319 ) {
F_118 ( V_204 , L_165 ,
V_21 , V_13 , V_288 -> V_320 ) ;
F_142 ( V_14 , V_204 , V_288 ) ;
} else
F_118 ( V_204 , L_166 , V_21 , V_13 , V_288 -> V_320 ) ;
if ( V_316 ) {
if ( V_14 -> V_71 & V_321 ) {
V_314 = V_315 ;
V_48 = 9 ;
} else {
V_314 = ( V_315 + 500 ) / V_322 ;
V_48 = 6 ;
}
F_118 ( V_204 , L_167 ,
V_313 , V_48 , V_314 , V_50 -> V_69 ) ;
} else
F_118 ( V_204 , L_168 ,
V_288 -> V_317 , V_50 -> V_69 ) ;
V_135 = strlen ( V_50 -> V_69 ) ;
if ( V_135 < 20 )
F_118 ( V_204 , L_169 , 20 - V_135 , V_312 ) ;
F_150 ( V_204 , V_50 , V_288 ) ;
}
static int V_197 ( const void * V_8 , const void * V_9 )
{
struct V_49 * const * V_323 = V_8 ;
struct V_49 * const * V_324 = V_9 ;
if ( ( * V_323 ) -> V_53 < ( * V_324 ) -> V_53 )
return - 1 ;
if ( ( * V_323 ) -> V_53 > ( * V_324 ) -> V_53 )
return 1 ;
return 0 ;
}
static int F_153 ( const void * V_8 , const void * V_9 )
{
struct V_49 * const * V_323 = V_8 ;
struct V_49 * const * V_324 = V_9 ;
int V_325 ;
V_325 = strcmp ( ( * V_323 ) -> V_69 , ( * V_324 ) -> V_69 ) ;
if ( V_325 )
return V_325 ;
V_325 = strcmp ( ( * V_323 ) -> system , ( * V_324 ) -> system ) ;
if ( V_325 )
return V_325 ;
return V_197 ( V_8 , V_9 ) ;
}
static int F_154 ( const void * V_8 , const void * V_9 )
{
struct V_49 * const * V_323 = V_8 ;
struct V_49 * const * V_324 = V_9 ;
int V_325 ;
V_325 = strcmp ( ( * V_323 ) -> system , ( * V_324 ) -> system ) ;
if ( V_325 )
return V_325 ;
V_325 = strcmp ( ( * V_323 ) -> V_69 , ( * V_324 ) -> V_69 ) ;
if ( V_325 )
return V_325 ;
return V_197 ( V_8 , V_9 ) ;
}
struct V_49 * * F_155 ( struct V_14 * V_14 , enum V_326 V_327 )
{
struct V_49 * * V_51 ;
int (* F_156)( const void * V_8 , const void * V_9 );
V_51 = V_14 -> V_328 ;
if ( V_51 && V_14 -> V_132 == V_327 )
return V_51 ;
if ( ! V_51 ) {
V_51 = malloc ( sizeof( * V_51 ) * ( V_14 -> V_52 + 1 ) ) ;
if ( ! V_51 )
return NULL ;
memcpy ( V_51 , V_14 -> V_51 , sizeof( * V_51 ) * V_14 -> V_52 ) ;
V_51 [ V_14 -> V_52 ] = NULL ;
V_14 -> V_328 = V_51 ;
if ( V_327 == V_329 ) {
V_14 -> V_132 = V_327 ;
return V_51 ;
}
}
switch ( V_327 ) {
case V_329 :
F_156 = V_197 ;
break;
case V_330 :
F_156 = F_153 ;
break;
case V_331 :
F_156 = F_154 ;
break;
default:
return V_51 ;
}
qsort ( V_51 , V_14 -> V_52 , sizeof( * V_51 ) , F_156 ) ;
V_14 -> V_132 = V_327 ;
return V_51 ;
}
static struct V_122 * *
F_157 ( const char * type , const char * V_69 ,
int V_80 , struct V_122 * V_169 )
{
struct V_122 * * V_125 ;
struct V_122 * V_68 ;
int V_19 = 0 ;
V_125 = malloc ( sizeof( * V_125 ) * ( V_80 + 1 ) ) ;
if ( ! V_125 )
return NULL ;
for ( V_68 = V_169 ; V_68 ; V_68 = V_68 -> V_22 ) {
V_125 [ V_19 ++ ] = V_68 ;
if ( V_19 == V_80 + 1 ) {
F_47 ( L_170 ,
V_69 , type ) ;
V_19 -- ;
break;
}
}
if ( V_19 != V_80 )
F_47 ( L_171 ,
V_69 , type ) ;
V_125 [ V_19 ] = NULL ;
return V_125 ;
}
struct V_122 * * F_158 ( struct V_49 * V_50 )
{
return F_157 ( L_172 , V_50 -> V_69 ,
V_50 -> V_145 . V_147 ,
V_50 -> V_145 . V_146 ) ;
}
struct V_122 * * F_159 ( struct V_49 * V_50 )
{
return F_157 ( L_173 , V_50 -> V_69 ,
V_50 -> V_145 . V_148 ,
V_50 -> V_145 . V_125 ) ;
}
static void F_160 ( struct V_203 * V_204 , struct V_59 * V_68 )
{
F_118 ( V_204 , L_174 , V_68 -> V_61 , V_68 -> V_62 ) ;
if ( V_68 -> V_22 ) {
F_121 ( V_204 , L_142 ) ;
F_160 ( V_204 , V_68 -> V_22 ) ;
}
}
static void F_161 ( struct V_7 * args )
{
int V_332 = 1 ;
struct V_203 V_204 ;
switch ( args -> type ) {
case V_96 :
printf ( L_175 ) ;
break;
case V_65 :
printf ( L_115 , args -> V_66 . V_66 ) ;
break;
case V_67 :
printf ( L_176 , args -> V_68 . V_69 ) ;
break;
case V_70 :
printf ( L_177 ) ;
F_161 ( args -> V_71 . V_68 ) ;
printf ( L_178 , args -> V_71 . V_72 ) ;
F_113 ( & V_204 ) ;
F_160 ( & V_204 , args -> V_71 . V_71 ) ;
F_162 ( & V_204 ) ;
F_115 ( & V_204 ) ;
printf ( L_69 ) ;
break;
case V_73 :
printf ( L_179 ) ;
F_161 ( args -> V_74 . V_68 ) ;
printf ( L_142 ) ;
F_113 ( & V_204 ) ;
F_160 ( & V_204 , args -> V_74 . V_75 ) ;
F_162 ( & V_204 ) ;
F_115 ( & V_204 ) ;
printf ( L_69 ) ;
break;
case V_76 :
printf ( L_180 ) ;
F_161 ( args -> V_77 . V_68 ) ;
printf ( L_142 ) ;
F_161 ( args -> V_77 . V_2 ) ;
printf ( L_69 ) ;
break;
case V_78 :
printf ( L_181 ) ;
F_161 ( args -> V_79 . V_68 ) ;
printf ( L_142 ) ;
F_161 ( args -> V_79 . V_80 ) ;
printf ( L_142 ) ;
F_161 ( args -> V_79 . V_81 ) ;
printf ( L_69 ) ;
break;
case V_84 :
case V_85 :
printf ( L_182 , args -> string . string ) ;
break;
case V_86 :
printf ( L_183 , args -> V_87 . V_87 ) ;
break;
case V_82 :
printf ( L_184 , args -> V_83 . type ) ;
F_161 ( args -> V_83 . V_17 ) ;
break;
case V_91 :
if ( strcmp ( args -> V_92 . V_92 , L_19 ) == 0 )
V_332 = 0 ;
if ( V_332 )
printf ( L_84 ) ;
F_161 ( args -> V_92 . V_93 ) ;
printf ( L_185 , args -> V_92 . V_92 ) ;
F_161 ( args -> V_92 . V_94 ) ;
if ( V_332 )
printf ( L_69 ) ;
break;
default:
return;
}
if ( args -> V_22 ) {
printf ( L_6 ) ;
F_161 ( args -> V_22 ) ;
}
}
static void F_163 ( const char * V_68 ,
int * V_141 , int * V_2 , int V_333 )
{
unsigned long long V_113 ;
unsigned long long V_115 ;
char * V_116 ;
int type ;
V_113 = V_5 ;
V_115 = V_4 ;
if ( F_52 ( V_55 , L_32 ) < 0 )
return;
if ( F_52 ( V_102 , L_19 ) < 0 )
return;
if ( F_50 ( V_55 , & V_116 ) < 0 )
goto V_121;
F_41 ( V_116 ) ;
if ( V_333 ) {
if ( F_52 ( V_55 , V_68 ) < 0 )
return;
} else {
if ( F_50 ( V_55 , & V_116 ) < 0 )
goto V_121;
if ( strcmp ( V_116 , V_68 ) != 0 )
goto V_334;
F_41 ( V_116 ) ;
}
if ( F_52 ( V_102 , L_41 ) < 0 )
return;
if ( F_52 ( V_55 , L_42 ) < 0 )
return;
if ( F_52 ( V_102 , L_19 ) < 0 )
return;
if ( F_50 ( V_55 , & V_116 ) < 0 )
goto V_121;
* V_141 = atoi ( V_116 ) ;
F_41 ( V_116 ) ;
if ( F_52 ( V_102 , L_41 ) < 0 )
return;
if ( F_52 ( V_55 , L_43 ) < 0 )
return;
if ( F_52 ( V_102 , L_19 ) < 0 )
return;
if ( F_50 ( V_55 , & V_116 ) < 0 )
goto V_121;
* V_2 = atoi ( V_116 ) ;
F_41 ( V_116 ) ;
if ( F_52 ( V_102 , L_41 ) < 0 )
return;
type = F_42 ( & V_116 ) ;
if ( type != V_98 ) {
if ( type != V_55 )
goto V_121;
if ( strcmp ( V_116 , L_44 ) != 0 )
goto V_121;
F_41 ( V_116 ) ;
if ( F_52 ( V_102 , L_19 ) < 0 )
return;
if ( F_50 ( V_55 , & V_116 ) )
goto V_121;
F_41 ( V_116 ) ;
if ( F_52 ( V_102 , L_41 ) < 0 )
return;
if ( F_50 ( V_98 , & V_116 ) )
goto V_121;
}
V_121:
F_41 ( V_116 ) ;
return;
V_334:
V_5 = V_113 ;
V_4 = V_115 ;
* V_141 = 0 ;
* V_2 = 0 ;
F_41 ( V_116 ) ;
}
int F_164 ( struct V_14 * V_14 , char * V_1 , unsigned long V_2 ,
int V_144 )
{
int V_335 ;
if ( ! V_2 ) {
V_14 -> V_336 = sizeof( long long ) ;
V_14 -> V_337 = V_144 ;
V_14 -> V_338 = sizeof( long long ) + V_144 ;
V_14 -> V_339 = 1 ;
return - 1 ;
}
F_1 ( V_1 , V_2 ) ;
F_163 ( L_186 , & V_14 -> V_340 ,
& V_14 -> V_336 , 1 ) ;
F_163 ( L_187 , & V_14 -> V_341 ,
& V_14 -> V_337 , 1 ) ;
F_163 ( L_188 , & V_14 -> V_342 ,
& V_335 , 0 ) ;
F_163 ( L_189 , & V_14 -> V_338 ,
& V_14 -> V_343 , 1 ) ;
return 0 ;
}
static int F_165 ( struct V_49 * V_50 ,
int V_53 , const char * V_344 ,
const char * V_345 )
{
if ( V_53 >= 0 && V_53 != V_50 -> V_53 )
return 0 ;
if ( V_345 && ( strcmp ( V_345 , V_50 -> V_69 ) != 0 ) )
return 0 ;
if ( V_344 && ( strcmp ( V_344 , V_50 -> system ) != 0 ) )
return 0 ;
return 1 ;
}
static void F_166 ( struct V_346 * V_347 )
{
free ( ( void * ) V_347 -> V_344 ) ;
free ( ( void * ) V_347 -> V_345 ) ;
free ( V_347 ) ;
}
static int F_167 ( struct V_14 * V_14 , struct V_49 * V_50 )
{
struct V_346 * V_347 , * * V_22 ;
for ( V_22 = & V_14 -> V_348 ; * V_22 ;
V_22 = & ( * V_22 ) -> V_22 ) {
V_347 = * V_22 ;
if ( F_165 ( V_50 , V_347 -> V_53 ,
V_347 -> V_344 ,
V_347 -> V_345 ) )
break;
}
if ( ! ( * V_22 ) )
return 0 ;
F_168 ( L_190 ,
V_50 -> V_53 , V_50 -> system , V_50 -> V_69 ) ;
V_50 -> V_308 = V_347 -> V_35 ;
V_50 -> V_310 = V_347 -> V_310 ;
* V_22 = V_347 -> V_22 ;
F_166 ( V_347 ) ;
return 1 ;
}
enum V_349 F_169 ( struct V_49 * * V_350 ,
struct V_14 * V_14 , const char * V_1 ,
unsigned long V_2 , const char * V_198 )
{
struct V_49 * V_50 ;
int V_120 ;
F_1 ( V_1 , V_2 ) ;
* V_350 = V_50 = F_28 () ;
if ( ! V_50 )
return V_351 ;
V_50 -> V_69 = F_54 () ;
if ( ! V_50 -> V_69 ) {
V_120 = V_351 ;
goto V_352;
}
if ( strcmp ( V_198 , L_191 ) == 0 ) {
V_50 -> V_71 |= V_128 ;
if ( strcmp ( V_50 -> V_69 , L_192 ) == 0 )
V_50 -> V_71 |= V_283 ;
}
V_50 -> V_53 = F_55 () ;
if ( V_50 -> V_53 < 0 ) {
V_120 = V_353 ;
goto V_352;
}
V_50 -> system = F_12 ( V_198 ) ;
if ( ! V_50 -> system ) {
V_120 = V_351 ;
goto V_352;
}
V_50 -> V_14 = V_14 ;
V_120 = F_62 ( V_50 ) ;
if ( V_120 < 0 ) {
V_120 = V_354 ;
goto V_355;
}
if ( V_14 && F_167 ( V_14 , V_50 ) )
V_356 = 0 ;
V_120 = F_94 ( V_50 ) ;
V_356 = 1 ;
if ( V_120 < 0 ) {
V_120 = V_357 ;
goto V_355;
}
if ( ! V_120 && ( V_50 -> V_71 & V_128 ) ) {
struct V_122 * V_68 ;
struct V_7 * V_63 , * * V_169 ;
V_169 = & V_50 -> V_181 . args ;
for ( V_68 = V_50 -> V_145 . V_125 ; V_68 ; V_68 = V_68 -> V_22 ) {
V_63 = F_6 () ;
if ( ! V_63 ) {
V_50 -> V_71 |= V_153 ;
return V_358 ;
}
V_63 -> type = V_67 ;
V_63 -> V_68 . V_69 = F_12 ( V_68 -> V_69 ) ;
if ( ! V_63 -> V_68 . V_69 ) {
V_50 -> V_71 |= V_153 ;
F_32 ( V_63 ) ;
return V_358 ;
}
V_63 -> V_68 . V_68 = V_68 ;
* V_169 = V_63 ;
V_169 = & V_63 -> V_22 ;
}
return 0 ;
}
return 0 ;
V_355:
V_50 -> V_71 |= V_153 ;
return V_120 ;
V_352:
free ( V_50 -> system ) ;
free ( V_50 -> V_69 ) ;
free ( V_50 ) ;
* V_350 = NULL ;
return V_120 ;
}
static enum V_349
F_170 ( struct V_14 * V_14 ,
struct V_49 * * V_350 ,
const char * V_1 , unsigned long V_2 ,
const char * V_198 )
{
int V_120 = F_169 ( V_350 , V_14 , V_1 , V_2 , V_198 ) ;
struct V_49 * V_50 = * V_350 ;
if ( V_50 == NULL )
return V_120 ;
if ( V_14 && F_29 ( V_14 , V_50 ) ) {
V_120 = V_351 ;
goto V_359;
}
#define F_171 0
if ( F_171 && V_50 -> V_181 . args )
F_161 ( V_50 -> V_181 . args ) ;
return 0 ;
V_359:
F_172 ( V_50 ) ;
return V_120 ;
}
enum V_349 F_173 ( struct V_14 * V_14 ,
struct V_49 * * V_350 ,
const char * V_1 ,
unsigned long V_2 , const char * V_198 )
{
return F_170 ( V_14 , V_350 , V_1 , V_2 , V_198 ) ;
}
enum V_349 F_174 ( struct V_14 * V_14 , const char * V_1 ,
unsigned long V_2 , const char * V_198 )
{
struct V_49 * V_50 = NULL ;
return F_170 ( V_14 , & V_50 , V_1 , V_2 , V_198 ) ;
}
int F_175 ( struct V_14 * V_14 V_156 ,
enum V_349 V_360 , char * V_1 , T_1 V_361 )
{
int V_362 ;
const char * V_363 ;
if ( V_360 >= 0 ) {
V_363 = F_176 ( V_360 , V_1 , V_361 ) ;
if ( V_363 != V_1 ) {
T_1 V_135 = strlen ( V_363 ) ;
memcpy ( V_1 , V_363 , F_177 ( V_361 - 1 , V_135 ) ) ;
* ( V_1 + F_177 ( V_361 - 1 , V_135 ) ) = '\0' ;
}
return 0 ;
}
if ( V_360 <= V_364 ||
V_360 >= V_365 )
return - 1 ;
V_362 = V_360 - V_364 - 1 ;
V_363 = V_366 [ V_362 ] ;
snprintf ( V_1 , V_361 , L_115 , V_363 ) ;
return 0 ;
}
int F_178 ( struct V_203 * V_204 , struct V_122 * V_68 ,
const char * V_69 , struct V_287 * V_288 ,
unsigned long long * V_165 , int V_180 )
{
if ( ! V_68 ) {
if ( V_180 )
F_118 ( V_204 , L_193 , V_69 ) ;
return - 1 ;
}
if ( F_100 ( V_68 , V_288 -> V_184 , V_165 ) ) {
if ( V_180 )
F_118 ( V_204 , L_194 , V_69 ) ;
return - 1 ;
}
return 0 ;
}
void * F_179 ( struct V_203 * V_204 , struct V_49 * V_50 ,
const char * V_69 , struct V_287 * V_288 ,
int * V_135 , int V_180 )
{
struct V_122 * V_68 ;
void * V_184 = V_288 -> V_184 ;
unsigned V_141 ;
int V_367 ;
if ( ! V_50 )
return NULL ;
V_68 = F_84 ( V_50 , V_69 ) ;
if ( ! V_68 ) {
if ( V_180 )
F_118 ( V_204 , L_193 , V_69 ) ;
return NULL ;
}
if ( ! V_135 )
V_135 = & V_367 ;
V_141 = V_68 -> V_141 ;
if ( V_68 -> V_71 & V_138 ) {
V_141 = F_96 ( V_50 -> V_14 ,
V_184 + V_141 , V_68 -> V_2 ) ;
* V_135 = V_141 >> 16 ;
V_141 &= 0xffff ;
} else
* V_135 = V_68 -> V_2 ;
return V_184 + V_141 ;
}
int F_180 ( struct V_203 * V_204 , struct V_49 * V_50 ,
const char * V_69 , struct V_287 * V_288 ,
unsigned long long * V_165 , int V_180 )
{
struct V_122 * V_68 ;
if ( ! V_50 )
return - 1 ;
V_68 = F_84 ( V_50 , V_69 ) ;
return F_178 ( V_204 , V_68 , V_69 , V_288 , V_165 , V_180 ) ;
}
int F_181 ( struct V_203 * V_204 , struct V_49 * V_50 ,
const char * V_69 , struct V_287 * V_288 ,
unsigned long long * V_165 , int V_180 )
{
struct V_122 * V_68 ;
if ( ! V_50 )
return - 1 ;
V_68 = F_95 ( V_50 , V_69 ) ;
return F_178 ( V_204 , V_68 , V_69 , V_288 , V_165 , V_180 ) ;
}
int F_182 ( struct V_203 * V_204 , struct V_49 * V_50 ,
const char * V_69 , struct V_287 * V_288 ,
unsigned long long * V_165 , int V_180 )
{
struct V_122 * V_68 ;
if ( ! V_50 )
return - 1 ;
V_68 = F_72 ( V_50 , V_69 ) ;
return F_178 ( V_204 , V_68 , V_69 , V_288 , V_165 , V_180 ) ;
}
int F_183 ( struct V_203 * V_204 , const char * V_47 ,
struct V_49 * V_50 , const char * V_69 ,
struct V_287 * V_288 , int V_180 )
{
struct V_122 * V_68 = F_84 ( V_50 , V_69 ) ;
unsigned long long V_165 ;
if ( ! V_68 )
goto V_368;
if ( F_100 ( V_68 , V_288 -> V_184 , & V_165 ) )
goto V_368;
return F_118 ( V_204 , V_47 , V_165 ) ;
V_368:
if ( V_180 )
F_118 ( V_204 , L_195 , V_69 ) ;
return - 1 ;
}
int F_184 ( struct V_203 * V_204 , const char * V_47 ,
struct V_49 * V_50 , const char * V_69 ,
struct V_287 * V_288 , int V_180 )
{
struct V_122 * V_68 = F_84 ( V_50 , V_69 ) ;
struct V_14 * V_14 = V_50 -> V_14 ;
unsigned long long V_165 ;
struct V_28 * V_35 ;
char V_155 [ 128 ] ;
if ( ! V_68 )
goto V_368;
if ( F_100 ( V_68 , V_288 -> V_184 , & V_165 ) )
goto V_368;
V_35 = F_18 ( V_14 , V_165 ) ;
if ( V_35 )
snprintf ( V_155 , 128 , L_196 , V_35 -> V_35 , V_35 -> V_31 - V_165 ) ;
else
sprintf ( V_155 , L_197 , V_165 ) ;
return F_118 ( V_204 , V_47 , V_155 ) ;
V_368:
if ( V_180 )
F_118 ( V_204 , L_195 , V_69 ) ;
return - 1 ;
}
static void F_90 ( struct V_175 * V_35 )
{
struct V_225 * V_229 ;
free ( V_35 -> V_69 ) ;
while ( V_35 -> V_229 ) {
V_229 = V_35 -> V_229 ;
V_35 -> V_229 = V_229 -> V_22 ;
free ( V_229 ) ;
}
free ( V_35 ) ;
}
int F_185 ( struct V_14 * V_14 ,
T_2 V_35 ,
enum V_369 V_370 ,
char * V_69 , ... )
{
struct V_175 * V_224 ;
struct V_225 * * V_371 ;
struct V_225 * V_226 ;
enum V_369 type ;
T_3 V_372 ;
int V_120 ;
V_224 = F_88 ( V_14 , V_69 ) ;
if ( V_224 ) {
F_168 ( L_198 , V_69 ) ;
F_89 ( V_14 , V_69 ) ;
}
V_224 = calloc ( 1 , sizeof( * V_224 ) ) ;
if ( ! V_224 ) {
F_47 ( L_199 ) ;
return V_351 ;
}
V_224 -> V_370 = V_370 ;
V_224 -> V_69 = F_12 ( V_69 ) ;
V_224 -> V_35 = V_35 ;
if ( ! V_224 -> V_69 ) {
F_47 ( L_200 ) ;
free ( V_224 ) ;
return V_351 ;
}
V_371 = & ( V_224 -> V_229 ) ;
va_start ( V_372 , V_69 ) ;
for (; ; ) {
type = va_arg ( V_372 , enum V_369 ) ;
if ( type == V_373 )
break;
if ( type >= V_374 ) {
F_47 ( L_201 , type ) ;
V_120 = V_375 ;
goto V_38;
}
V_226 = malloc ( sizeof( * V_226 ) ) ;
if ( ! V_226 ) {
F_47 ( L_202 ) ;
V_120 = V_351 ;
goto V_38;
}
V_226 -> type = type ;
V_226 -> V_22 = NULL ;
* V_371 = V_226 ;
V_371 = & ( V_226 -> V_22 ) ;
V_224 -> V_179 ++ ;
}
va_end ( V_372 ) ;
V_224 -> V_22 = V_14 -> V_177 ;
V_14 -> V_177 = V_224 ;
return 0 ;
V_38:
va_end ( V_372 ) ;
F_90 ( V_224 ) ;
return V_120 ;
}
int F_186 ( struct V_14 * V_14 ,
T_2 V_35 , char * V_69 )
{
struct V_175 * V_224 ;
V_224 = F_88 ( V_14 , V_69 ) ;
if ( V_224 && V_224 -> V_35 == V_35 ) {
F_89 ( V_14 , V_69 ) ;
return 0 ;
}
return - 1 ;
}
static struct V_49 * F_187 ( struct V_14 * V_14 , int V_53 ,
const char * V_344 ,
const char * V_345 )
{
struct V_49 * V_50 ;
if ( V_53 >= 0 ) {
V_50 = F_109 ( V_14 , V_53 ) ;
if ( ! V_50 )
return NULL ;
if ( V_345 && ( strcmp ( V_345 , V_50 -> V_69 ) != 0 ) )
return NULL ;
if ( V_344 && ( strcmp ( V_344 , V_50 -> system ) != 0 ) )
return NULL ;
} else {
V_50 = F_110 ( V_14 , V_344 , V_345 ) ;
if ( ! V_50 )
return NULL ;
}
return V_50 ;
}
int F_188 ( struct V_14 * V_14 , int V_53 ,
const char * V_344 , const char * V_345 ,
T_4 V_35 , void * V_310 )
{
struct V_49 * V_50 ;
struct V_346 * V_347 ;
V_50 = F_187 ( V_14 , V_53 , V_344 , V_345 ) ;
if ( V_50 == NULL )
goto V_376;
F_168 ( L_190 ,
V_50 -> V_53 , V_50 -> system , V_50 -> V_69 ) ;
V_50 -> V_308 = V_35 ;
V_50 -> V_310 = V_310 ;
return 0 ;
V_376:
V_347 = calloc ( 1 , sizeof( * V_347 ) ) ;
if ( ! V_347 ) {
F_47 ( L_203 ) ;
return V_351 ;
}
V_347 -> V_53 = V_53 ;
if ( V_345 )
V_347 -> V_345 = F_12 ( V_345 ) ;
if ( V_344 )
V_347 -> V_344 = F_12 ( V_344 ) ;
if ( ( V_345 && ! V_347 -> V_345 ) ||
( V_344 && ! V_347 -> V_344 ) ) {
F_47 ( L_204 ) ;
free ( ( void * ) V_347 -> V_345 ) ;
free ( ( void * ) V_347 -> V_344 ) ;
free ( V_347 ) ;
return V_351 ;
}
V_347 -> V_35 = V_35 ;
V_347 -> V_22 = V_14 -> V_348 ;
V_14 -> V_348 = V_347 ;
V_347 -> V_310 = V_310 ;
return - 1 ;
}
static int F_189 ( struct V_346 * V_308 , int V_53 ,
const char * V_344 , const char * V_345 ,
T_4 V_35 , void * V_310 )
{
if ( V_53 >= 0 && V_53 != V_308 -> V_53 )
return 0 ;
if ( V_345 && ( strcmp ( V_345 , V_308 -> V_345 ) != 0 ) )
return 0 ;
if ( V_344 && ( strcmp ( V_344 , V_308 -> V_344 ) != 0 ) )
return 0 ;
if ( V_35 != V_308 -> V_35 || V_310 != V_308 -> V_310 )
return 0 ;
return 1 ;
}
int F_190 ( struct V_14 * V_14 , int V_53 ,
const char * V_344 , const char * V_345 ,
T_4 V_35 , void * V_310 )
{
struct V_49 * V_50 ;
struct V_346 * V_347 ;
struct V_346 * * V_22 ;
V_50 = F_187 ( V_14 , V_53 , V_344 , V_345 ) ;
if ( V_50 == NULL )
goto V_376;
if ( V_50 -> V_308 == V_35 && V_50 -> V_310 == V_310 ) {
F_168 ( L_205 ,
V_50 -> V_53 , V_50 -> system , V_50 -> V_69 ) ;
V_50 -> V_308 = NULL ;
V_50 -> V_310 = NULL ;
return 0 ;
}
V_376:
for ( V_22 = & V_14 -> V_348 ; * V_22 ; V_22 = & ( * V_22 ) -> V_22 ) {
V_347 = * V_22 ;
if ( F_189 ( V_347 , V_53 , V_344 , V_345 ,
V_35 , V_310 ) )
break;
}
if ( ! ( * V_22 ) )
return - 1 ;
* V_22 = V_347 -> V_22 ;
F_166 ( V_347 ) ;
return 0 ;
}
struct V_14 * F_191 ( void )
{
struct V_14 * V_14 = calloc ( 1 , sizeof( * V_14 ) ) ;
if ( V_14 )
V_14 -> V_377 = 1 ;
return V_14 ;
}
void F_192 ( struct V_14 * V_14 )
{
V_14 -> V_377 ++ ;
}
void F_193 ( struct V_122 * V_68 )
{
free ( V_68 -> type ) ;
free ( V_68 -> V_69 ) ;
free ( V_68 ) ;
}
static void F_194 ( struct V_122 * V_68 )
{
struct V_122 * V_22 ;
while ( V_68 ) {
V_22 = V_68 -> V_22 ;
F_193 ( V_68 ) ;
V_68 = V_22 ;
}
}
static void F_195 ( struct V_145 * V_145 )
{
F_194 ( V_145 -> V_146 ) ;
F_194 ( V_145 -> V_125 ) ;
}
void F_172 ( struct V_49 * V_50 )
{
free ( V_50 -> V_69 ) ;
free ( V_50 -> system ) ;
F_195 ( & V_50 -> V_145 ) ;
free ( V_50 -> V_181 . V_145 ) ;
F_124 ( V_50 -> V_181 . args ) ;
free ( V_50 ) ;
}
void F_196 ( struct V_14 * V_14 )
{
struct V_15 * V_16 , * V_378 ;
struct V_32 * V_33 , * V_379 ;
struct V_43 * V_44 , * V_380 ;
struct V_175 * V_381 ;
struct V_346 * V_347 ;
int V_19 ;
if ( ! V_14 )
return;
V_16 = V_14 -> V_16 ;
V_33 = V_14 -> V_33 ;
V_44 = V_14 -> V_44 ;
V_14 -> V_377 -- ;
if ( V_14 -> V_377 )
return;
if ( V_14 -> V_18 ) {
for ( V_19 = 0 ; V_19 < V_14 -> V_20 ; V_19 ++ )
free ( V_14 -> V_18 [ V_19 ] . V_21 ) ;
free ( V_14 -> V_18 ) ;
}
while ( V_16 ) {
V_378 = V_16 -> V_22 ;
free ( V_16 -> V_21 ) ;
free ( V_16 ) ;
V_16 = V_378 ;
}
if ( V_14 -> V_28 ) {
for ( V_19 = 0 ; V_19 < ( int ) V_14 -> V_34 ; V_19 ++ ) {
free ( V_14 -> V_28 [ V_19 ] . V_35 ) ;
free ( V_14 -> V_28 [ V_19 ] . V_36 ) ;
}
free ( V_14 -> V_28 ) ;
}
while ( V_33 ) {
V_379 = V_33 -> V_22 ;
free ( V_33 -> V_35 ) ;
free ( V_33 -> V_36 ) ;
free ( V_33 ) ;
V_33 = V_379 ;
}
while ( V_14 -> V_177 ) {
V_381 = V_14 -> V_177 ;
V_14 -> V_177 = V_381 -> V_22 ;
F_90 ( V_381 ) ;
}
if ( V_14 -> V_40 ) {
for ( V_19 = 0 ; V_19 < ( int ) V_14 -> V_45 ; V_19 ++ )
free ( V_14 -> V_40 [ V_19 ] . V_46 ) ;
free ( V_14 -> V_40 ) ;
}
while ( V_44 ) {
V_380 = V_44 -> V_22 ;
free ( V_44 -> V_46 ) ;
free ( V_44 ) ;
V_44 = V_380 ;
}
for ( V_19 = 0 ; V_19 < V_14 -> V_52 ; V_19 ++ )
F_172 ( V_14 -> V_51 [ V_19 ] ) ;
while ( V_14 -> V_348 ) {
V_347 = V_14 -> V_348 ;
V_14 -> V_348 = V_347 -> V_22 ;
F_166 ( V_347 ) ;
}
free ( V_14 -> V_27 ) ;
free ( V_14 -> V_51 ) ;
free ( V_14 -> V_328 ) ;
free ( V_14 ) ;
}
void F_197 ( struct V_14 * V_14 )
{
F_196 ( V_14 ) ;
}
