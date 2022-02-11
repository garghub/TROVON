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
V_68 -> V_69 = V_68 -> V_132 = V_126 ;
if ( F_46 ( type , V_102 ) )
goto V_121;
if ( strcmp ( V_116 , L_38 ) == 0 ) {
enum V_54 V_133 = type ;
char * V_134 = V_116 ;
char * V_135 ;
int V_136 ;
V_68 -> V_71 |= V_123 ;
type = F_42 ( & V_116 ) ;
if ( type == V_55 )
V_68 -> V_137 = strtoul ( V_116 , NULL , 0 ) ;
else
V_68 -> V_137 = 0 ;
while ( strcmp ( V_116 , L_39 ) != 0 ) {
if ( V_133 == V_55 &&
type == V_55 )
V_136 = 2 ;
else
V_136 = 1 ;
V_133 = type ;
V_135 = realloc ( V_134 ,
strlen ( V_134 ) +
strlen ( V_116 ) + V_136 ) ;
if ( ! V_135 ) {
free ( V_134 ) ;
goto V_121;
}
V_134 = V_135 ;
if ( V_136 == 2 )
strcat ( V_134 , L_36 ) ;
strcat ( V_134 , V_116 ) ;
V_68 -> V_137 = strtoul ( V_116 , NULL , 0 ) ;
F_41 ( V_116 ) ;
type = F_42 ( & V_116 ) ;
if ( type == V_101 ) {
F_61 ( V_50 , L_40 ) ;
goto V_121;
}
}
F_41 ( V_116 ) ;
V_135 = realloc ( V_134 , strlen ( V_134 ) + 2 ) ;
if ( ! V_135 ) {
free ( V_134 ) ;
goto V_121;
}
V_134 = V_135 ;
strcat ( V_134 , L_39 ) ;
type = F_42 ( & V_116 ) ;
if ( type == V_55 ) {
char * V_130 ;
V_130 = realloc ( V_68 -> type ,
strlen ( V_68 -> type ) +
strlen ( V_68 -> V_69 ) +
strlen ( V_134 ) + 2 ) ;
if ( ! V_130 ) {
free ( V_134 ) ;
goto V_121;
}
V_68 -> type = V_130 ;
strcat ( V_68 -> type , L_36 ) ;
strcat ( V_68 -> type , V_68 -> V_69 ) ;
V_127 = F_59 ( V_68 -> V_69 ) ;
F_41 ( V_68 -> V_69 ) ;
strcat ( V_68 -> type , V_134 ) ;
V_68 -> V_69 = V_68 -> V_132 = V_116 ;
type = F_42 ( & V_116 ) ;
} else {
char * V_130 ;
V_130 = realloc ( V_68 -> type ,
strlen ( V_68 -> type ) +
strlen ( V_134 ) + 1 ) ;
if ( ! V_130 ) {
free ( V_134 ) ;
goto V_121;
}
V_68 -> type = V_130 ;
strcat ( V_68 -> type , V_134 ) ;
}
free ( V_134 ) ;
}
if ( F_56 ( V_68 ) )
V_68 -> V_71 |= V_138 ;
if ( F_57 ( V_68 ) )
V_68 -> V_71 |= V_139 ;
if ( F_58 ( V_68 ) )
V_68 -> V_71 |= V_140 ;
if ( F_48 ( type , V_116 , V_102 , L_41 ) )
goto V_121;
F_41 ( V_116 ) ;
if ( F_52 ( V_55 , L_42 ) < 0 )
goto V_141;
if ( F_52 ( V_102 , L_19 ) < 0 )
goto V_141;
if ( F_50 ( V_55 , & V_116 ) )
goto V_121;
V_68 -> V_142 = strtoul ( V_116 , NULL , 0 ) ;
F_41 ( V_116 ) ;
if ( F_52 ( V_102 , L_41 ) < 0 )
goto V_141;
if ( F_52 ( V_55 , L_43 ) < 0 )
goto V_141;
if ( F_52 ( V_102 , L_19 ) < 0 )
goto V_141;
if ( F_50 ( V_55 , & V_116 ) )
goto V_121;
V_68 -> V_2 = strtoul ( V_116 , NULL , 0 ) ;
F_41 ( V_116 ) ;
if ( F_52 ( V_102 , L_41 ) < 0 )
goto V_141;
type = F_42 ( & V_116 ) ;
if ( type != V_98 ) {
if ( F_48 ( type , V_116 , V_55 , L_44 ) )
goto V_121;
F_41 ( V_116 ) ;
if ( F_52 ( V_102 , L_19 ) < 0 )
goto V_141;
if ( F_50 ( V_55 , & V_116 ) )
goto V_121;
if ( strtoul ( V_116 , NULL , 0 ) )
V_68 -> V_71 |= V_143 ;
F_41 ( V_116 ) ;
if ( F_52 ( V_102 , L_41 ) < 0 )
goto V_141;
if ( F_50 ( V_98 , & V_116 ) )
goto V_121;
}
F_41 ( V_116 ) ;
if ( V_68 -> V_71 & V_123 ) {
if ( V_68 -> V_137 )
V_68 -> V_144 = V_68 -> V_2 / V_68 -> V_137 ;
else if ( V_68 -> V_71 & V_139 )
V_68 -> V_144 = V_127 ;
else if ( V_68 -> V_71 & V_138 )
V_68 -> V_144 = 1 ;
else if ( V_68 -> V_71 & V_140 )
V_68 -> V_144 = V_50 -> V_14 ?
V_50 -> V_14 -> V_145 :
sizeof( long ) ;
} else
V_68 -> V_144 = V_68 -> V_2 ;
* V_125 = V_68 ;
V_125 = & V_68 -> V_22 ;
} while ( 1 );
return 0 ;
V_121:
F_41 ( V_116 ) ;
V_141:
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
V_120 = F_60 ( V_50 , & V_50 -> V_146 . V_147 ) ;
if ( V_120 < 0 )
return V_120 ;
V_50 -> V_146 . V_148 = V_120 ;
V_120 = F_60 ( V_50 , & V_50 -> V_146 . V_125 ) ;
if ( V_120 < 0 )
return V_120 ;
V_50 -> V_146 . V_149 = V_120 ;
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
F_67 ( struct V_49 * V_50 , struct V_7 * V_150 , char * * V_103 )
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
V_151:
if ( type == V_102 && strcmp ( V_116 , L_19 ) != 0 ) {
type = F_66 ( V_50 , V_93 , & V_116 ) ;
goto V_151;
}
if ( F_48 ( type , V_116 , V_102 , L_19 ) )
goto V_38;
V_63 -> V_92 . V_92 = V_116 ;
type = F_63 ( V_50 , V_94 , & V_116 ) ;
V_150 -> V_92 . V_94 = V_63 ;
* V_103 = V_116 ;
return type ;
V_38:
V_150 -> V_92 . V_94 = NULL ;
F_41 ( V_116 ) ;
F_32 ( V_63 ) ;
return V_57 ;
}
static enum V_54
F_68 ( struct V_49 * V_50 , struct V_7 * V_150 , char * * V_103 )
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
V_150 -> V_92 . V_94 = V_63 ;
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
V_63 -> V_92 . V_152 = 0 ;
else
V_63 -> V_92 . V_152 = F_69 ( V_63 -> V_92 . V_92 ) ;
return V_63 -> V_92 . V_152 ;
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
goto V_153;
V_93 -> type = V_96 ;
V_63 -> V_92 . V_93 = V_93 ;
V_94 = F_6 () ;
if ( ! V_94 )
goto V_153;
V_63 -> V_92 . V_94 = V_94 ;
* V_103 = NULL ;
type = F_63 ( V_50 , V_94 , V_103 ) ;
} else if ( strcmp ( V_116 , L_60 ) == 0 ) {
V_93 = F_6 () ;
if ( ! V_93 )
goto V_153;
* V_93 = * V_63 ;
V_63 -> type = V_91 ;
V_63 -> V_92 . V_92 = V_116 ;
V_63 -> V_92 . V_93 = V_93 ;
V_63 -> V_92 . V_152 = 0 ;
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
goto V_153;
* V_93 = * V_63 ;
V_63 -> type = V_91 ;
V_63 -> V_92 . V_92 = V_116 ;
V_63 -> V_92 . V_93 = V_93 ;
V_63 -> V_92 . V_94 = NULL ;
if ( F_70 ( V_63 ) == - 1 ) {
V_50 -> V_71 |= V_154 ;
V_63 -> V_92 . V_92 = NULL ;
goto V_38;
}
type = F_45 ( & V_116 ) ;
* V_103 = V_116 ;
if ( ( strcmp ( V_63 -> V_92 . V_92 , L_34 ) == 0 ) &&
type == V_58 && ( strcmp ( V_116 , L_69 ) == 0 ) ) {
char * V_155 ;
if ( V_93 -> type != V_65 ) {
F_61 ( V_50 , L_70 ) ;
goto V_38;
}
V_155 = realloc ( V_93 -> V_66 . V_66 ,
strlen ( V_93 -> V_66 . V_66 ) + 3 ) ;
if ( ! V_155 )
goto V_153;
V_93 -> V_66 . V_66 = V_155 ;
strcat ( V_93 -> V_66 . V_66 , L_71 ) ;
free ( V_63 -> V_92 . V_92 ) ;
* V_63 = * V_93 ;
free ( V_93 ) ;
return type ;
}
V_94 = F_6 () ;
if ( ! V_94 )
goto V_153;
type = F_64 ( V_50 , V_94 , V_103 , type ) ;
if ( V_94 -> type == V_91 &&
F_69 ( V_63 -> V_92 . V_92 ) < F_69 ( V_94 -> V_92 . V_92 ) ) {
struct V_7 V_156 ;
V_63 -> V_92 . V_94 = V_94 -> V_92 . V_93 ;
V_156 = * V_63 ;
* V_63 = * V_94 ;
* V_94 = V_156 ;
V_63 -> V_92 . V_93 = V_94 ;
} else {
V_63 -> V_92 . V_94 = V_94 ;
}
} else if ( strcmp ( V_116 , L_38 ) == 0 ) {
V_93 = F_6 () ;
if ( ! V_93 )
goto V_153;
* V_93 = * V_63 ;
V_63 -> type = V_91 ;
V_63 -> V_92 . V_92 = V_116 ;
V_63 -> V_92 . V_93 = V_93 ;
V_63 -> V_92 . V_152 = 0 ;
type = F_68 ( V_50 , V_63 , V_103 ) ;
} else {
F_61 ( V_50 , L_58 , V_116 ) ;
V_50 -> V_71 |= V_154 ;
goto V_38;
}
if ( type == V_102 && strcmp ( * V_103 , L_19 ) != 0 ) {
int V_152 ;
V_152 = F_69 ( * V_103 ) ;
if ( V_152 > V_63 -> V_92 . V_152 )
return F_66 ( V_50 , V_63 , V_103 ) ;
return F_66 ( V_50 , V_94 , V_103 ) ;
}
return type ;
V_153:
F_61 ( V_50 , L_46 , V_131 ) ;
V_38:
F_41 ( V_116 ) ;
* V_103 = NULL ;
return V_57 ;
}
static enum V_54
F_71 ( struct V_49 * V_50 V_157 , struct V_7 * V_63 ,
char * * V_103 )
{
enum V_54 type ;
char * V_68 ;
char * V_116 ;
if ( F_52 ( V_102 , L_72 ) < 0 )
goto V_158;
if ( F_50 ( V_55 , & V_116 ) < 0 )
goto V_38;
V_68 = V_116 ;
V_63 -> type = V_67 ;
V_63 -> V_68 . V_69 = V_68 ;
if ( V_159 ) {
V_63 -> V_68 . V_68 = F_72 ( V_50 , V_63 -> V_68 . V_69 ) ;
V_63 -> V_68 . V_68 -> V_71 |= V_160 ;
V_159 = 0 ;
} else if ( V_161 ) {
V_63 -> V_68 . V_68 = F_72 ( V_50 , V_63 -> V_68 . V_69 ) ;
V_63 -> V_68 . V_68 -> V_71 |= V_162 ;
V_161 = 0 ;
}
type = F_42 ( & V_116 ) ;
* V_103 = V_116 ;
return type ;
V_38:
F_41 ( V_116 ) ;
V_158:
* V_103 = NULL ;
return V_57 ;
}
static int F_73 ( struct V_49 * V_50 , char * V_163 ,
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
if ( F_48 ( type , V_116 , V_58 , V_163 ) ) {
V_24 = V_164 ;
V_120 = - 1 ;
F_32 ( V_68 ) ;
goto V_165;
}
* V_7 = V_68 ;
V_165:
F_41 ( V_116 ) ;
return V_120 ;
}
static unsigned long long
F_74 ( unsigned long long V_166 , const char * type , int V_167 )
{
int V_168 = 0 ;
char * V_169 ;
int V_136 ;
V_136 = strlen ( type ) ;
if ( V_167 ) {
if ( type [ V_136 - 1 ] != '*' ) {
F_47 ( L_73 ) ;
return V_166 ;
}
V_169 = malloc ( V_136 ) ;
if ( ! V_169 ) {
F_47 ( L_46 , V_131 ) ;
return V_166 ;
}
memcpy ( V_169 , type , V_136 ) ;
V_169 [ V_136 - 2 ] = 0 ;
V_166 = F_74 ( V_166 , V_169 , 0 ) ;
free ( V_169 ) ;
return V_166 ;
}
if ( type [ V_136 - 1 ] == '*' )
return V_166 ;
if ( strncmp ( type , L_74 , 6 ) == 0 )
return V_166 ;
if ( strcmp ( type , L_22 ) == 0 )
return V_166 & 0xff ;
if ( strcmp ( type , L_26 ) == 0 )
return V_166 & 0xffff ;
if ( strcmp ( type , L_27 ) == 0 )
return V_166 & 0xffffffff ;
if ( strcmp ( type , L_28 ) == 0 ||
strcmp ( type , L_31 ) )
return V_166 ;
if ( strcmp ( type , L_23 ) == 0 )
return ( unsigned long long ) ( char ) V_166 & 0xff ;
if ( strcmp ( type , L_29 ) == 0 )
return ( unsigned long long ) ( short ) V_166 & 0xffff ;
if ( strcmp ( type , L_30 ) == 0 )
return ( unsigned long long ) ( int ) V_166 & 0xffffffff ;
if ( strncmp ( type , L_75 , 9 ) == 0 ) {
V_168 = 0 ;
type += 9 ;
}
if ( strcmp ( type , L_21 ) == 0 ) {
if ( V_168 )
return ( unsigned long long ) ( char ) V_166 & 0xff ;
else
return V_166 & 0xff ;
}
if ( strcmp ( type , L_76 ) == 0 ) {
if ( V_168 )
return ( unsigned long long ) ( short ) V_166 & 0xffff ;
else
return V_166 & 0xffff ;
}
if ( strcmp ( type , L_77 ) == 0 ) {
if ( V_168 )
return ( unsigned long long ) ( int ) V_166 & 0xffffffff ;
else
return V_166 & 0xffffffff ;
}
return V_166 ;
}
static unsigned long long
F_75 ( unsigned long long V_166 , struct V_7 * V_63 , int V_167 )
{
if ( V_63 -> type != V_82 ) {
F_47 ( L_78 ) ;
return 0 ;
}
return F_74 ( V_166 , V_63 -> V_83 . type , V_167 ) ;
}
static int F_76 ( struct V_7 * V_63 , long long * V_166 )
{
long long V_93 , V_94 ;
int V_120 = 1 ;
switch ( V_63 -> type ) {
case V_65 :
* V_166 = strtoll ( V_63 -> V_66 . V_66 , NULL , 0 ) ;
break;
case V_82 :
V_120 = F_76 ( V_63 -> V_83 . V_17 , V_166 ) ;
if ( ! V_120 )
break;
* V_166 = F_75 ( * V_166 , V_63 , 0 ) ;
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
* V_166 = V_93 || V_94 ;
else
* V_166 = V_93 | V_94 ;
break;
case '&' :
V_120 = F_76 ( V_63 -> V_92 . V_93 , & V_93 ) ;
if ( ! V_120 )
break;
V_120 = F_76 ( V_63 -> V_92 . V_94 , & V_94 ) ;
if ( ! V_120 )
break;
if ( V_63 -> V_92 . V_92 [ 1 ] )
* V_166 = V_93 && V_94 ;
else
* V_166 = V_93 & V_94 ;
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
* V_166 = V_93 < V_94 ;
break;
case '<' :
* V_166 = V_93 << V_94 ;
break;
case '=' :
* V_166 = V_93 <= V_94 ;
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
* V_166 = V_93 > V_94 ;
break;
case '>' :
* V_166 = V_93 >> V_94 ;
break;
case '=' :
* V_166 = V_93 >= V_94 ;
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
* V_166 = V_93 == V_94 ;
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
* V_166 = V_93 != V_94 ;
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
* V_166 = V_93 - V_94 ;
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
* V_166 = V_93 + V_94 ;
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
long long V_166 ;
static char V_1 [ 20 ] ;
switch ( V_63 -> type ) {
case V_65 :
return V_63 -> V_66 . V_66 ;
case V_82 :
return F_77 ( V_63 -> V_83 . V_17 ) ;
case V_91 :
if ( ! F_76 ( V_63 , & V_166 ) )
break;
sprintf ( V_1 , L_80 , V_166 ) ;
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
F_78 ( struct V_49 * V_50 , struct V_59 * * V_170 , char * * V_103 )
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
goto V_171;
V_68 -> V_61 = F_12 ( V_61 ) ;
if ( V_68 -> V_61 == NULL )
goto V_171;
F_32 ( V_63 ) ;
V_63 = F_6 () ;
if ( ! V_63 )
goto V_38;
F_41 ( V_116 ) ;
type = F_63 ( V_50 , V_63 , & V_116 ) ;
if ( F_48 ( type , V_116 , V_102 , L_83 ) )
goto V_171;
V_61 = F_77 ( V_63 ) ;
if ( V_61 == NULL )
goto V_171;
V_68 -> V_62 = F_12 ( V_61 ) ;
if ( V_68 -> V_62 == NULL )
goto V_171;
F_32 ( V_63 ) ;
V_63 = NULL ;
* V_170 = V_68 ;
V_170 = & V_68 -> V_22 ;
F_41 ( V_116 ) ;
type = F_45 ( & V_116 ) ;
} while ( type == V_58 && strcmp ( V_116 , L_82 ) == 0 );
* V_103 = V_116 ;
return type ;
V_171:
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
goto V_171;
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
V_171:
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
goto V_171;
V_63 -> V_74 . V_68 = V_68 ;
type = F_78 ( V_50 , & V_63 -> V_74 . V_75 , & V_116 ) ;
if ( F_48 ( type , V_116 , V_58 , L_69 ) )
goto V_38;
F_41 ( V_116 ) ;
type = F_45 ( V_103 ) ;
return type ;
V_171:
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
goto V_172;
return F_45 ( V_103 ) ;
V_172:
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
goto V_172;
if ( F_73 ( V_50 , L_69 , & V_63 -> V_79 . V_81 ) )
goto V_173;
return F_45 ( V_103 ) ;
V_173:
F_32 ( V_63 -> V_79 . V_80 ) ;
V_172:
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
goto V_174;
if ( ! F_48 ( type , V_116 , V_102 , L_39 ) )
goto V_174;
F_41 ( V_116 ) ;
type = F_45 ( V_103 ) ;
return type ;
V_174:
F_32 ( V_63 ) ;
V_38:
F_41 ( V_116 ) ;
* V_103 = NULL ;
return V_57 ;
}
static enum V_54
F_85 ( struct V_49 * V_50 , struct V_7 * V_63 , char * * V_103 )
{
struct V_7 * V_175 ;
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
V_175 = F_6 () ;
if ( ! V_175 ) {
F_61 ( V_50 , L_46 ,
V_131 ) ;
goto V_38;
}
V_63 -> type = V_82 ;
V_63 -> V_83 . type = V_63 -> V_66 . V_66 ;
V_63 -> V_83 . V_17 = V_175 ;
type = F_64 ( V_50 , V_175 , & V_116 , type ) ;
}
* V_103 = V_116 ;
return type ;
V_38:
F_41 ( V_116 ) ;
* V_103 = NULL ;
return V_57 ;
}
static enum V_54
F_86 ( struct V_49 * V_50 V_157 , struct V_7 * V_63 ,
char * * V_103 )
{
enum V_54 type ;
char * V_116 ;
if ( F_50 ( V_55 , & V_116 ) < 0 )
goto V_38;
V_63 -> type = V_84 ;
V_63 -> string . string = V_116 ;
V_63 -> string . V_142 = - 1 ;
if ( F_52 ( V_58 , L_69 ) < 0 )
goto V_158;
type = F_42 ( & V_116 ) ;
* V_103 = V_116 ;
return type ;
V_38:
F_41 ( V_116 ) ;
V_158:
* V_103 = NULL ;
return V_57 ;
}
static enum V_54
F_87 ( struct V_49 * V_50 V_157 , struct V_7 * V_63 ,
char * * V_103 )
{
enum V_54 type ;
char * V_116 ;
if ( F_50 ( V_55 , & V_116 ) < 0 )
goto V_38;
V_63 -> type = V_86 ;
V_63 -> V_87 . V_87 = V_116 ;
V_63 -> V_87 . V_142 = - 1 ;
if ( F_52 ( V_58 , L_69 ) < 0 )
goto V_158;
type = F_42 ( & V_116 ) ;
* V_103 = V_116 ;
return type ;
V_38:
F_41 ( V_116 ) ;
V_158:
* V_103 = NULL ;
return V_57 ;
}
static struct V_176 *
F_88 ( struct V_14 * V_14 , char * V_177 )
{
struct V_176 * V_35 ;
if ( ! V_14 )
return NULL ;
for ( V_35 = V_14 -> V_178 ; V_35 ; V_35 = V_35 -> V_22 ) {
if ( strcmp ( V_35 -> V_69 , V_177 ) == 0 )
break;
}
return V_35 ;
}
static void F_89 ( struct V_14 * V_14 , char * V_177 )
{
struct V_176 * V_35 ;
struct V_176 * * V_22 ;
V_22 = & V_14 -> V_178 ;
while ( ( V_35 = * V_22 ) ) {
if ( strcmp ( V_35 -> V_69 , V_177 ) == 0 ) {
* V_22 = V_35 -> V_22 ;
F_90 ( V_35 ) ;
break;
}
V_22 = & V_35 -> V_22 ;
}
}
static enum V_54
F_91 ( struct V_49 * V_50 , struct V_176 * V_35 ,
struct V_7 * V_63 , char * * V_103 )
{
struct V_7 * * V_179 ;
struct V_7 * V_64 ;
enum V_54 type ;
char * V_116 ;
int V_19 ;
V_63 -> type = V_95 ;
V_63 -> V_35 . V_35 = V_35 ;
* V_103 = NULL ;
V_179 = & ( V_63 -> V_35 . args ) ;
for ( V_19 = 0 ; V_19 < V_35 -> V_180 ; V_19 ++ ) {
V_64 = F_6 () ;
if ( ! V_64 ) {
F_61 ( V_50 , L_46 ,
V_131 ) ;
return V_57 ;
}
type = F_63 ( V_50 , V_64 , & V_116 ) ;
if ( V_19 < ( V_35 -> V_180 - 1 ) ) {
if ( type != V_58 || strcmp ( V_116 , L_82 ) != 0 ) {
F_61 ( V_50 ,
L_86 ,
V_35 -> V_69 , V_35 -> V_180 ,
V_50 -> V_69 , V_19 + 1 ) ;
goto V_181;
}
} else {
if ( type != V_58 || strcmp ( V_116 , L_69 ) != 0 ) {
F_61 ( V_50 ,
L_87 ,
V_35 -> V_69 , V_35 -> V_180 , V_50 -> V_69 ) ;
goto V_181;
}
}
* V_179 = V_64 ;
V_179 = & ( V_64 -> V_22 ) ;
F_41 ( V_116 ) ;
}
type = F_42 ( & V_116 ) ;
* V_103 = V_116 ;
return type ;
V_181:
F_32 ( V_64 ) ;
F_41 ( V_116 ) ;
return V_57 ;
}
static enum V_54
F_92 ( struct V_49 * V_50 , struct V_7 * V_63 ,
char * V_116 , char * * V_103 )
{
struct V_176 * V_35 ;
if ( strcmp ( V_116 , L_88 ) == 0 ) {
F_41 ( V_116 ) ;
V_159 = 1 ;
return F_79 ( V_50 , V_63 , V_103 ) ;
}
if ( strcmp ( V_116 , L_89 ) == 0 ) {
F_41 ( V_116 ) ;
V_161 = 1 ;
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
char * V_155 ;
V_155 = realloc ( V_66 ,
strlen ( V_66 ) + strlen ( V_116 ) + 2 ) ;
if ( ! V_155 ) {
free ( V_66 ) ;
* V_103 = NULL ;
F_41 ( V_116 ) ;
return V_57 ;
}
V_66 = V_155 ;
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
static int F_93 ( struct V_49 * V_50 , struct V_7 * * V_170 )
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
* V_170 = V_63 ;
args ++ ;
if ( type == V_102 ) {
type = F_66 ( V_50 , V_63 , & V_116 ) ;
F_41 ( V_116 ) ;
if ( type == V_57 ) {
* V_170 = NULL ;
F_32 ( V_63 ) ;
return - 1 ;
}
V_170 = & V_63 -> V_22 ;
continue;
}
if ( type == V_58 && strcmp ( V_116 , L_82 ) == 0 ) {
F_41 ( V_116 ) ;
* V_170 = V_63 ;
V_170 = & V_63 -> V_22 ;
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
V_50 -> V_182 . V_146 = V_116 ;
V_50 -> V_182 . args = NULL ;
type = F_45 ( & V_116 ) ;
if ( type == V_101 )
return 0 ;
if ( type == V_100 ) {
char * V_183 ;
if ( F_39 ( & V_183 , L_100 , V_50 -> V_182 . V_146 , V_116 ) < 0 )
goto V_121;
F_41 ( V_116 ) ;
F_41 ( V_50 -> V_182 . V_146 ) ;
V_50 -> V_182 . V_146 = NULL ;
V_116 = V_183 ;
goto V_112;
}
if ( F_48 ( type , V_116 , V_58 , L_82 ) )
goto V_121;
F_41 ( V_116 ) ;
V_120 = F_93 ( V_50 , & V_50 -> V_182 . args ) ;
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
struct V_122 * V_146 ;
for ( V_146 = V_50 -> V_146 . V_147 ;
V_146 ; V_146 = V_146 -> V_22 ) {
if ( strcmp ( V_146 -> V_69 , V_69 ) == 0 )
break;
}
return V_146 ;
}
struct V_122 *
F_84 ( struct V_49 * V_50 , const char * V_69 )
{
struct V_122 * V_146 ;
for ( V_146 = V_50 -> V_146 . V_125 ;
V_146 ; V_146 = V_146 -> V_22 ) {
if ( strcmp ( V_146 -> V_69 , V_69 ) == 0 )
break;
}
return V_146 ;
}
struct V_122 *
F_72 ( struct V_49 * V_50 , const char * V_69 )
{
struct V_122 * V_146 ;
V_146 = F_95 ( V_50 , V_69 ) ;
if ( V_146 )
return V_146 ;
return F_84 ( V_50 , V_69 ) ;
}
unsigned long long F_96 ( struct V_14 * V_14 ,
const void * V_184 , int V_2 )
{
switch ( V_2 ) {
case 1 :
return * ( unsigned char * ) V_184 ;
case 2 :
return F_97 ( V_14 , V_184 ) ;
case 4 :
return F_98 ( V_14 , V_184 ) ;
case 8 :
return F_99 ( V_14 , V_184 ) ;
default:
return 0 ;
}
}
int F_100 ( struct V_122 * V_68 , const void * V_185 ,
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
V_185 + V_68 -> V_142 , V_68 -> V_2 ) ;
return 0 ;
default:
return - 1 ;
}
}
static int F_101 ( struct V_14 * V_14 ,
const char * type , int * V_142 , int * V_2 )
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
* V_142 = V_68 -> V_142 ;
* V_2 = V_68 -> V_2 ;
return 0 ;
}
static int F_102 ( struct V_14 * V_14 , void * V_185 ,
int * V_2 , int * V_142 , const char * V_69 )
{
int V_120 ;
if ( ! * V_2 ) {
V_120 = F_101 ( V_14 , V_69 , V_142 , V_2 ) ;
if ( V_120 < 0 )
return V_120 ;
}
return F_96 ( V_14 , V_185 + * V_142 , * V_2 ) ;
}
static int F_103 ( struct V_14 * V_14 , void * V_185 )
{
return F_102 ( V_14 , V_185 ,
& V_14 -> F_59 , & V_14 -> V_186 ,
L_102 ) ;
}
static int F_104 ( struct V_14 * V_14 , void * V_185 )
{
return F_102 ( V_14 , V_185 ,
& V_14 -> V_187 , & V_14 -> V_188 ,
L_103 ) ;
}
static int F_105 ( struct V_14 * V_14 , void * V_185 )
{
return F_102 ( V_14 , V_185 ,
& V_14 -> V_189 , & V_14 -> V_190 ,
L_104 ) ;
}
static int F_106 ( struct V_14 * V_14 , void * V_185 )
{
return F_102 ( V_14 , V_185 ,
& V_14 -> V_191 , & V_14 -> V_192 ,
L_105 ) ;
}
static int F_107 ( struct V_14 * V_14 , void * V_185 )
{
return F_102 ( V_14 , V_185 ,
& V_14 -> V_193 , & V_14 -> V_194 ,
L_106 ) ;
}
static int F_108 ( struct V_14 * V_14 , void * V_185 )
{
return F_102 ( V_14 , V_185 ,
& V_14 -> V_193 , & V_14 -> V_194 ,
L_107 ) ;
}
struct V_49 * F_109 ( struct V_14 * V_14 , int V_53 )
{
struct V_49 * * V_195 ;
struct V_49 V_23 ;
struct V_49 * V_196 = & V_23 ;
if ( V_14 -> V_197 && V_14 -> V_197 -> V_53 == V_53 )
return V_14 -> V_197 ;
V_23 . V_53 = V_53 ;
V_195 = bsearch ( & V_196 , V_14 -> V_51 , V_14 -> V_52 ,
sizeof( * V_14 -> V_51 ) , V_198 ) ;
if ( V_195 ) {
V_14 -> V_197 = * V_195 ;
return * V_195 ;
}
return NULL ;
}
struct V_49 *
F_110 ( struct V_14 * V_14 ,
const char * V_199 , const char * V_69 )
{
struct V_49 * V_50 ;
int V_19 ;
if ( V_14 -> V_197 &&
strcmp ( V_14 -> V_197 -> V_69 , V_69 ) == 0 &&
( ! V_199 || strcmp ( V_14 -> V_197 -> system , V_199 ) == 0 ) )
return V_14 -> V_197 ;
for ( V_19 = 0 ; V_19 < V_14 -> V_52 ; V_19 ++ ) {
V_50 = V_14 -> V_51 [ V_19 ] ;
if ( strcmp ( V_50 -> V_69 , V_69 ) == 0 ) {
if ( ! V_199 )
break;
if ( strcmp ( V_50 -> system , V_199 ) == 0 )
break;
}
}
if ( V_19 == V_14 -> V_52 )
V_50 = NULL ;
V_14 -> V_197 = V_50 ;
return V_50 ;
}
static unsigned long long
F_111 ( void * V_185 , int V_2 , struct V_49 * V_50 , struct V_7 * V_63 )
{
struct V_14 * V_14 = V_50 -> V_14 ;
unsigned long long V_166 = 0 ;
unsigned long long V_93 , V_94 ;
struct V_7 * V_200 = NULL ;
struct V_7 * V_201 ;
unsigned long V_142 ;
unsigned int V_202 ;
switch ( V_63 -> type ) {
case V_96 :
return 0 ;
case V_65 :
return F_112 ( V_63 -> V_66 . V_66 , NULL , 0 ) ;
case V_67 :
if ( ! V_63 -> V_68 . V_68 ) {
V_63 -> V_68 . V_68 = F_72 ( V_50 , V_63 -> V_68 . V_69 ) ;
if ( ! V_63 -> V_68 . V_68 )
goto V_203;
}
V_166 = F_96 ( V_14 , V_185 + V_63 -> V_68 . V_68 -> V_142 ,
V_63 -> V_68 . V_68 -> V_2 ) ;
break;
case V_70 :
case V_73 :
case V_78 :
case V_76 :
break;
case V_82 :
V_166 = F_111 ( V_185 , V_2 , V_50 , V_63 -> V_83 . V_17 ) ;
return F_75 ( V_166 , V_63 , 0 ) ;
case V_84 :
case V_85 :
case V_86 :
return 0 ;
case V_95 : {
struct V_204 V_205 ;
F_113 ( & V_205 ) ;
V_166 = F_114 ( & V_205 , V_185 , V_2 , V_50 , V_63 ) ;
F_115 ( & V_205 ) ;
return V_166 ;
}
case V_91 :
if ( strcmp ( V_63 -> V_92 . V_92 , L_38 ) == 0 ) {
V_94 = F_111 ( V_185 , V_2 , V_50 , V_63 -> V_92 . V_94 ) ;
V_201 = V_63 -> V_92 . V_93 ;
while ( V_201 -> type == V_82 ) {
if ( ! V_200 )
V_200 = V_201 ;
V_201 = V_201 -> V_83 . V_17 ;
}
V_202 = V_14 -> V_145 ;
switch ( V_201 -> type ) {
case V_88 :
V_142 = F_96 ( V_14 ,
V_185 + V_201 -> V_89 . V_68 -> V_142 ,
V_201 -> V_89 . V_68 -> V_2 ) ;
if ( V_201 -> V_89 . V_68 -> V_144 )
V_202 = V_201 -> V_89 . V_68 -> V_144 ;
V_142 &= 0xffff ;
V_142 += V_94 ;
break;
case V_67 :
if ( ! V_201 -> V_68 . V_68 ) {
V_201 -> V_68 . V_68 =
F_72 ( V_50 , V_201 -> V_68 . V_69 ) ;
if ( ! V_201 -> V_68 . V_68 ) {
V_63 = V_201 ;
goto V_203;
}
}
V_202 = V_201 -> V_68 . V_68 -> V_144 ;
V_142 = V_201 -> V_68 . V_68 -> V_142 +
V_94 * V_201 -> V_68 . V_68 -> V_144 ;
break;
default:
goto V_206;
}
V_166 = F_96 ( V_14 ,
V_185 + V_142 , V_202 ) ;
if ( V_200 )
V_166 = F_75 ( V_166 , V_200 , 1 ) ;
break;
} else if ( strcmp ( V_63 -> V_92 . V_92 , L_60 ) == 0 ) {
V_93 = F_111 ( V_185 , V_2 , V_50 , V_63 -> V_92 . V_93 ) ;
V_63 = V_63 -> V_92 . V_94 ;
if ( V_93 )
V_166 = F_111 ( V_185 , V_2 , V_50 , V_63 -> V_92 . V_93 ) ;
else
V_166 = F_111 ( V_185 , V_2 , V_50 , V_63 -> V_92 . V_94 ) ;
break;
}
V_206:
V_93 = F_111 ( V_185 , V_2 , V_50 , V_63 -> V_92 . V_93 ) ;
V_94 = F_111 ( V_185 , V_2 , V_50 , V_63 -> V_92 . V_94 ) ;
switch ( V_63 -> V_92 . V_92 [ 0 ] ) {
case '!' :
switch ( V_63 -> V_92 . V_92 [ 1 ] ) {
case 0 :
V_166 = ! V_94 ;
break;
case '=' :
V_166 = V_93 != V_94 ;
break;
default:
goto V_207;
}
break;
case '~' :
V_166 = ~ V_94 ;
break;
case '|' :
if ( V_63 -> V_92 . V_92 [ 1 ] )
V_166 = V_93 || V_94 ;
else
V_166 = V_93 | V_94 ;
break;
case '&' :
if ( V_63 -> V_92 . V_92 [ 1 ] )
V_166 = V_93 && V_94 ;
else
V_166 = V_93 & V_94 ;
break;
case '<' :
switch ( V_63 -> V_92 . V_92 [ 1 ] ) {
case 0 :
V_166 = V_93 < V_94 ;
break;
case '<' :
V_166 = V_93 << V_94 ;
break;
case '=' :
V_166 = V_93 <= V_94 ;
break;
default:
goto V_207;
}
break;
case '>' :
switch ( V_63 -> V_92 . V_92 [ 1 ] ) {
case 0 :
V_166 = V_93 > V_94 ;
break;
case '>' :
V_166 = V_93 >> V_94 ;
break;
case '=' :
V_166 = V_93 >= V_94 ;
break;
default:
goto V_207;
}
break;
case '=' :
if ( V_63 -> V_92 . V_92 [ 1 ] != '=' )
goto V_207;
V_166 = V_93 == V_94 ;
break;
case '-' :
V_166 = V_93 - V_94 ;
break;
case '+' :
V_166 = V_93 + V_94 ;
break;
case '/' :
V_166 = V_93 / V_94 ;
break;
case '*' :
V_166 = V_93 * V_94 ;
break;
default:
goto V_207;
}
break;
case V_88 :
V_142 = F_96 ( V_14 ,
V_185 + V_63 -> V_89 . V_68 -> V_142 ,
V_63 -> V_89 . V_68 -> V_2 ) ;
V_142 &= 0xffff ;
V_166 = ( unsigned long long ) ( ( unsigned long ) V_185 + V_142 ) ;
break;
default:
return 0 ;
}
return V_166 ;
V_207:
F_61 ( V_50 , L_108 , V_131 , V_63 -> V_92 . V_92 ) ;
return 0 ;
V_203:
F_61 ( V_50 , L_109 ,
V_131 , V_63 -> V_68 . V_69 ) ;
return 0 ;
}
static long long F_116 ( const char * V_208 )
{
int V_19 ;
if ( isdigit ( V_208 [ 0 ] ) )
return F_112 ( V_208 , NULL , 0 ) ;
for ( V_19 = 0 ; V_19 < ( int ) ( sizeof( V_71 ) / sizeof( V_71 [ 0 ] ) ) ; V_19 ++ )
if ( strcmp ( V_71 [ V_19 ] . V_69 , V_208 ) == 0 )
return V_71 [ V_19 ] . V_61 ;
return - 1LL ;
}
static void F_117 ( struct V_204 * V_205 , const char * V_146 ,
int V_209 , const char * V_62 )
{
if ( V_209 >= 0 )
F_118 ( V_205 , V_146 , V_209 , V_62 ) ;
else
F_118 ( V_205 , V_146 , V_62 ) ;
}
static void F_119 ( struct V_14 * V_14 ,
struct V_204 * V_205 , const char * V_146 ,
int V_209 , const void * V_185 , int V_2 )
{
int V_210 = V_2 * 8 ;
int V_211 = ( V_210 + 3 ) / 4 ;
int V_136 = 0 ;
char V_1 [ 3 ] ;
char * V_62 ;
int V_90 ;
int V_19 ;
V_211 += ( V_210 - 1 ) / 32 ;
V_62 = malloc ( V_211 + 1 ) ;
if ( ! V_62 ) {
F_47 ( L_46 , V_131 ) ;
return;
}
V_62 [ V_211 ] = 0 ;
for ( V_19 = V_211 - 2 ; V_19 >= 0 ; V_19 -= 2 ) {
if ( V_14 -> V_212 )
V_90 = V_2 - ( V_136 + 1 ) ;
else
V_90 = V_136 ;
snprintf ( V_1 , 3 , L_110 , * ( ( unsigned char * ) V_185 + V_90 ) ) ;
memcpy ( V_62 + V_19 , V_1 , 2 ) ;
V_136 ++ ;
if ( ! ( V_136 & 3 ) && V_19 > 0 ) {
V_19 -- ;
V_62 [ V_19 ] = ',' ;
}
}
if ( V_209 >= 0 )
F_118 ( V_205 , V_146 , V_209 , V_62 ) ;
else
F_118 ( V_205 , V_146 , V_62 ) ;
free ( V_62 ) ;
}
static void F_120 ( struct V_204 * V_205 , void * V_185 , int V_2 ,
struct V_49 * V_50 , const char * V_146 ,
int V_209 , struct V_7 * V_63 )
{
struct V_14 * V_14 = V_50 -> V_14 ;
struct V_59 * V_208 ;
struct V_122 * V_68 ;
struct V_40 * V_46 ;
long long V_166 , V_213 ;
unsigned long V_31 ;
char * V_62 ;
unsigned char * V_77 ;
int V_214 ;
int V_19 , V_136 ;
switch ( V_63 -> type ) {
case V_96 :
return;
case V_65 :
F_117 ( V_205 , V_146 , V_209 , V_63 -> V_66 . V_66 ) ;
return;
case V_67 :
V_68 = V_63 -> V_68 . V_68 ;
if ( ! V_68 ) {
V_68 = F_72 ( V_50 , V_63 -> V_68 . V_69 ) ;
if ( ! V_68 ) {
V_62 = V_63 -> V_68 . V_69 ;
goto V_203;
}
V_63 -> V_68 . V_68 = V_68 ;
}
V_136 = V_68 -> V_2 ? : V_2 - V_68 -> V_142 ;
if ( ! ( V_68 -> V_71 & V_123 ) &&
V_68 -> V_2 == V_14 -> V_145 ) {
V_31 = * ( unsigned long * ) ( V_185 + V_68 -> V_142 ) ;
V_46 = F_25 ( V_14 , V_31 ) ;
if ( V_46 )
F_121 ( V_205 , V_46 -> V_46 ) ;
else
F_118 ( V_205 , L_111 , V_31 ) ;
break;
}
V_62 = malloc ( V_136 + 1 ) ;
if ( ! V_62 ) {
F_61 ( V_50 , L_46 ,
V_131 ) ;
return;
}
memcpy ( V_62 , V_185 + V_68 -> V_142 , V_136 ) ;
V_62 [ V_136 ] = 0 ;
F_117 ( V_205 , V_146 , V_209 , V_62 ) ;
free ( V_62 ) ;
break;
case V_70 :
V_166 = F_111 ( V_185 , V_2 , V_50 , V_63 -> V_71 . V_68 ) ;
V_214 = 0 ;
for ( V_208 = V_63 -> V_71 . V_71 ; V_208 ; V_208 = V_208 -> V_22 ) {
V_213 = F_116 ( V_208 -> V_61 ) ;
if ( ! V_166 && V_213 < 0 ) {
F_117 ( V_205 , V_146 , V_209 , V_208 -> V_62 ) ;
break;
}
if ( V_213 > 0 && ( V_166 & V_213 ) == V_213 ) {
if ( V_214 && V_63 -> V_71 . V_72 )
F_121 ( V_205 , V_63 -> V_71 . V_72 ) ;
F_117 ( V_205 , V_146 , V_209 , V_208 -> V_62 ) ;
V_214 = 1 ;
V_166 &= ~ V_213 ;
}
}
break;
case V_73 :
V_166 = F_111 ( V_185 , V_2 , V_50 , V_63 -> V_74 . V_68 ) ;
for ( V_208 = V_63 -> V_74 . V_75 ; V_208 ; V_208 = V_208 -> V_22 ) {
V_213 = F_116 ( V_208 -> V_61 ) ;
if ( V_166 == V_213 ) {
F_117 ( V_205 , V_146 , V_209 , V_208 -> V_62 ) ;
break;
}
}
break;
case V_76 :
if ( V_63 -> V_77 . V_68 -> type == V_88 ) {
unsigned long V_142 ;
V_142 = F_96 ( V_14 ,
V_185 + V_63 -> V_77 . V_68 -> V_89 . V_68 -> V_142 ,
V_63 -> V_77 . V_68 -> V_89 . V_68 -> V_2 ) ;
V_77 = V_185 + ( V_142 & 0xffff ) ;
} else {
V_68 = V_63 -> V_77 . V_68 -> V_68 . V_68 ;
if ( ! V_68 ) {
V_62 = V_63 -> V_77 . V_68 -> V_68 . V_69 ;
V_68 = F_72 ( V_50 , V_62 ) ;
if ( ! V_68 )
goto V_203;
V_63 -> V_77 . V_68 -> V_68 . V_68 = V_68 ;
}
V_77 = V_185 + V_68 -> V_142 ;
}
V_136 = F_111 ( V_185 , V_2 , V_50 , V_63 -> V_77 . V_2 ) ;
for ( V_19 = 0 ; V_19 < V_136 ; V_19 ++ ) {
if ( V_19 )
F_122 ( V_205 , ' ' ) ;
F_118 ( V_205 , L_110 , V_77 [ V_19 ] ) ;
}
break;
case V_78 : {
void * V_215 ;
int V_81 ;
if ( V_63 -> V_79 . V_68 -> type == V_88 ) {
unsigned long V_142 ;
struct V_122 * V_68 =
V_63 -> V_79 . V_68 -> V_89 . V_68 ;
V_142 = F_96 ( V_14 ,
V_185 + V_68 -> V_142 ,
V_68 -> V_2 ) ;
V_215 = V_185 + ( V_142 & 0xffff ) ;
} else {
V_68 = V_63 -> V_79 . V_68 -> V_68 . V_68 ;
if ( ! V_68 ) {
V_62 = V_63 -> V_79 . V_68 -> V_68 . V_69 ;
V_68 = F_72 ( V_50 , V_62 ) ;
if ( ! V_68 )
goto V_203;
V_63 -> V_79 . V_68 -> V_68 . V_68 = V_68 ;
}
V_215 = V_185 + V_68 -> V_142 ;
}
V_136 = F_111 ( V_185 , V_2 , V_50 , V_63 -> V_79 . V_80 ) ;
V_81 = F_111 ( V_185 , V_2 , V_50 ,
V_63 -> V_79 . V_81 ) ;
for ( V_19 = 0 ; V_19 < V_136 ; V_19 ++ ) {
if ( V_19 )
F_122 ( V_205 , ' ' ) ;
if ( V_81 == 1 ) {
F_118 ( V_205 , L_112 , * ( V_216 * ) V_215 ) ;
} else if ( V_81 == 2 ) {
F_118 ( V_205 , L_112 , * ( V_217 * ) V_215 ) ;
} else if ( V_81 == 4 ) {
F_118 ( V_205 , L_112 , * ( V_218 * ) V_215 ) ;
} else if ( V_81 == 8 ) {
F_118 ( V_205 , L_113 V_219 , * ( V_220 * ) V_215 ) ;
} else {
F_118 ( V_205 , L_114 ,
V_81 , * ( V_216 * ) V_215 ) ;
V_81 = 1 ;
}
V_215 += V_81 ;
}
break;
}
case V_82 :
break;
case V_84 : {
int V_221 ;
if ( V_63 -> string . V_142 == - 1 ) {
struct V_122 * V_222 ;
V_222 = F_72 ( V_50 , V_63 -> string . string ) ;
V_63 -> string . V_142 = V_222 -> V_142 ;
}
V_221 = F_98 ( V_14 , V_185 + V_63 -> string . V_142 ) ;
V_221 &= 0xffff ;
F_117 ( V_205 , V_146 , V_209 , ( ( char * ) V_185 ) + V_221 ) ;
break;
}
case V_85 :
F_117 ( V_205 , V_146 , V_209 , V_63 -> string . string ) ;
break;
case V_86 : {
int V_223 ;
int V_224 ;
if ( V_63 -> V_87 . V_142 == - 1 ) {
struct V_122 * V_222 ;
V_222 = F_72 ( V_50 , V_63 -> V_87 . V_87 ) ;
V_63 -> V_87 . V_142 = V_222 -> V_142 ;
}
V_223 = F_98 ( V_14 , V_185 + V_63 -> V_87 . V_142 ) ;
V_224 = V_223 >> 16 ;
V_223 &= 0xffff ;
F_119 ( V_14 , V_205 , V_146 , V_209 ,
V_185 + V_223 , V_224 ) ;
break;
}
case V_91 :
if ( V_63 -> V_92 . V_92 [ 0 ] != '?' )
return;
V_166 = F_111 ( V_185 , V_2 , V_50 , V_63 -> V_92 . V_93 ) ;
if ( V_166 )
F_120 ( V_205 , V_185 , V_2 , V_50 ,
V_146 , V_209 , V_63 -> V_92 . V_94 -> V_92 . V_93 ) ;
else
F_120 ( V_205 , V_185 , V_2 , V_50 ,
V_146 , V_209 , V_63 -> V_92 . V_94 -> V_92 . V_94 ) ;
break;
case V_95 :
F_114 ( V_205 , V_185 , V_2 , V_50 , V_63 ) ;
break;
default:
break;
}
return;
V_203:
F_61 ( V_50 , L_109 ,
V_131 , V_63 -> V_68 . V_69 ) ;
}
static unsigned long long
F_114 ( struct V_204 * V_205 , void * V_185 , int V_2 ,
struct V_49 * V_50 , struct V_7 * V_63 )
{
struct V_176 * V_225 = V_63 -> V_35 . V_35 ;
struct V_226 * V_227 ;
unsigned long long * args ;
unsigned long long V_120 ;
struct V_7 * V_64 ;
struct V_204 V_62 ;
struct V_228 {
struct V_228 * V_22 ;
char * V_62 ;
} * V_229 = NULL , * string ;
int V_19 ;
if ( ! V_225 -> V_180 ) {
V_120 = (* V_225 -> V_35 )( V_205 , NULL ) ;
goto V_111;
}
V_64 = V_63 -> V_35 . args ;
V_227 = V_225 -> V_230 ;
V_120 = V_231 ;
args = malloc ( sizeof( * args ) * V_225 -> V_180 ) ;
if ( ! args )
goto V_111;
for ( V_19 = 0 ; V_19 < V_225 -> V_180 ; V_19 ++ ) {
switch ( V_227 -> type ) {
case V_232 :
case V_233 :
case V_234 :
args [ V_19 ] = F_111 ( V_185 , V_2 , V_50 , V_64 ) ;
break;
case V_235 :
F_113 ( & V_62 ) ;
F_120 ( & V_62 , V_185 , V_2 , V_50 , L_115 , - 1 , V_64 ) ;
F_123 ( & V_62 ) ;
string = malloc ( sizeof( * string ) ) ;
if ( ! string ) {
F_61 ( V_50 , L_116 ,
V_131 , __LINE__ ) ;
goto V_38;
}
string -> V_22 = V_229 ;
string -> V_62 = F_12 ( V_62 . V_236 ) ;
if ( ! string -> V_62 ) {
free ( string ) ;
F_61 ( V_50 , L_116 ,
V_131 , __LINE__ ) ;
goto V_38;
}
args [ V_19 ] = ( V_237 ) string -> V_62 ;
V_229 = string ;
F_115 ( & V_62 ) ;
break;
default:
F_61 ( V_50 , L_117 ) ;
goto V_38;
}
V_64 = V_64 -> V_22 ;
V_227 = V_227 -> V_22 ;
}
V_120 = (* V_225 -> V_35 )( V_205 , args ) ;
V_38:
free ( args ) ;
while ( V_229 ) {
string = V_229 ;
V_229 = string -> V_22 ;
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
static struct V_7 * F_125 ( char * V_47 , void * V_185 , int V_2 , struct V_49 * V_50 )
{
struct V_14 * V_14 = V_50 -> V_14 ;
struct V_122 * V_68 , * V_238 ;
struct V_7 * args , * V_63 , * * V_22 ;
unsigned long long V_239 , V_166 ;
char * V_184 ;
void * V_240 ;
int V_241 ;
V_68 = V_14 -> V_242 ;
V_238 = V_14 -> V_243 ;
if ( ! V_68 ) {
V_68 = F_84 ( V_50 , L_118 ) ;
if ( ! V_68 ) {
F_61 ( V_50 , L_119 ) ;
return NULL ;
}
V_238 = F_84 ( V_50 , L_120 ) ;
if ( ! V_238 ) {
F_61 ( V_50 , L_121 ) ;
return NULL ;
}
V_14 -> V_242 = V_68 ;
V_14 -> V_243 = V_238 ;
}
V_239 = F_96 ( V_14 , V_185 + V_238 -> V_142 , V_238 -> V_2 ) ;
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
if ( F_39 ( & V_63 -> V_66 . V_66 , L_80 , V_239 ) < 0 )
goto V_38;
for ( V_184 = V_47 + 5 , V_240 = V_185 + V_68 -> V_142 ;
V_240 < V_185 + V_2 && * V_184 ; V_184 ++ ) {
int V_244 = 0 ;
if ( * V_184 == '%' ) {
V_245:
V_184 ++ ;
switch ( * V_184 ) {
case '%' :
break;
case 'l' :
V_244 ++ ;
goto V_245;
case 'L' :
V_244 = 2 ;
goto V_245;
case '0' ... '9' :
goto V_245;
case '.' :
goto V_245;
case 'z' :
case 'Z' :
V_244 = 1 ;
goto V_245;
case 'p' :
V_244 = 1 ;
case 'd' :
case 'u' :
case 'x' :
case 'i' :
switch ( V_244 ) {
case 0 :
V_241 = 4 ;
break;
case 1 :
V_241 = V_14 -> V_145 ;
break;
case 2 :
V_241 = 8 ;
break;
default:
V_241 = V_244 ;
break;
}
case '*' :
if ( * V_184 == '*' )
V_241 = 4 ;
V_240 = ( void * ) ( ( ( unsigned long ) V_240 + 3 ) &
~ 3 ) ;
V_166 = F_96 ( V_14 , V_240 , V_241 ) ;
V_240 += V_241 ;
V_63 = F_6 () ;
if ( ! V_63 ) {
F_61 ( V_50 , L_122 ,
V_131 , __LINE__ ) ;
goto V_38;
}
V_63 -> V_22 = NULL ;
V_63 -> type = V_65 ;
if ( F_39 ( & V_63 -> V_66 . V_66 , L_80 , V_166 ) < 0 ) {
free ( V_63 ) ;
goto V_38;
}
* V_22 = V_63 ;
V_22 = & V_63 -> V_22 ;
if ( * V_184 == '*' )
goto V_245;
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
V_63 -> string . string = F_12 ( V_240 ) ;
if ( ! V_63 -> string . string )
goto V_38;
V_240 += strlen ( V_240 ) + 1 ;
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
F_126 ( void * V_185 , int V_2 V_157 ,
struct V_49 * V_50 )
{
struct V_14 * V_14 = V_50 -> V_14 ;
unsigned long long V_31 ;
struct V_122 * V_68 ;
struct V_40 * V_46 ;
char * V_146 ;
V_68 = V_14 -> V_246 ;
if ( ! V_68 ) {
V_68 = F_84 ( V_50 , L_99 ) ;
if ( ! V_68 ) {
F_61 ( V_50 , L_123 ) ;
return NULL ;
}
V_14 -> V_246 = V_68 ;
}
V_31 = F_96 ( V_14 , V_185 + V_68 -> V_142 , V_68 -> V_2 ) ;
V_46 = F_25 ( V_14 , V_31 ) ;
if ( ! V_46 ) {
if ( F_39 ( & V_146 , L_124 , V_31 ) < 0 )
return NULL ;
return V_146 ;
}
if ( F_39 ( & V_146 , L_125 , L_126 , V_46 -> V_46 ) < 0 )
return NULL ;
return V_146 ;
}
static void F_127 ( struct V_204 * V_205 , int V_247 , void * V_185 , int V_2 ,
struct V_49 * V_50 , struct V_7 * V_63 )
{
unsigned char * V_1 ;
const char * V_47 = L_127 ;
if ( V_63 -> type == V_95 ) {
F_114 ( V_205 , V_185 , V_2 , V_50 , V_63 ) ;
return;
}
if ( V_63 -> type != V_67 ) {
F_118 ( V_205 , L_128 ,
V_63 -> type ) ;
return;
}
if ( V_247 == 'm' )
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
F_118 ( V_205 , L_130 ) ;
return;
}
V_1 = V_185 + V_63 -> V_68 . V_68 -> V_142 ;
F_118 ( V_205 , V_47 , V_1 [ 0 ] , V_1 [ 1 ] , V_1 [ 2 ] , V_1 [ 3 ] , V_1 [ 4 ] , V_1 [ 5 ] ) ;
}
static void F_128 ( struct V_204 * V_205 , char V_19 , unsigned char * V_1 )
{
const char * V_47 ;
if ( V_19 == 'i' )
V_47 = L_131 ;
else
V_47 = L_132 ;
F_118 ( V_205 , V_47 , V_1 [ 0 ] , V_1 [ 1 ] , V_1 [ 2 ] , V_1 [ 3 ] ) ;
}
static inline bool F_129 ( const struct V_248 * V_8 )
{
return ( ( unsigned long ) ( V_8 -> V_249 [ 0 ] | V_8 -> V_249 [ 1 ] ) |
( unsigned long ) ( V_8 -> V_249 [ 2 ] ^ F_130 ( 0x0000ffff ) ) ) == 0UL ;
}
static inline bool F_131 ( const struct V_248 * V_31 )
{
return ( V_31 -> V_249 [ 2 ] | F_130 ( 0x02000000 ) ) == F_130 ( 0x02005EFE ) ;
}
static void F_132 ( struct V_204 * V_205 , unsigned char * V_31 )
{
int V_19 , V_250 , V_251 ;
unsigned char V_252 [ 8 ] ;
int V_253 = 1 ;
int V_254 = - 1 ;
V_217 V_255 ;
V_216 V_256 , V_257 ;
bool V_258 = false ;
bool V_259 ;
struct V_248 V_260 ;
memcpy ( & V_260 , V_31 , sizeof( struct V_248 ) ) ;
V_259 = F_129 ( & V_260 ) || F_131 ( & V_260 ) ;
memset ( V_252 , 0 , sizeof( V_252 ) ) ;
if ( V_259 )
V_251 = 6 ;
else
V_251 = 8 ;
for ( V_19 = 0 ; V_19 < V_251 ; V_19 ++ ) {
for ( V_250 = V_19 ; V_250 < V_251 ; V_250 ++ ) {
if ( V_260 . V_261 [ V_250 ] != 0 )
break;
V_252 [ V_19 ] ++ ;
}
}
for ( V_19 = 0 ; V_19 < V_251 ; V_19 ++ ) {
if ( V_252 [ V_19 ] > V_253 ) {
V_253 = V_252 [ V_19 ] ;
V_254 = V_19 ;
}
}
if ( V_253 == 1 )
V_254 = - 1 ;
for ( V_19 = 0 ; V_19 < V_251 ; V_19 ++ ) {
if ( V_19 == V_254 ) {
if ( V_258 || V_19 == 0 )
F_118 ( V_205 , L_19 ) ;
F_118 ( V_205 , L_19 ) ;
V_258 = false ;
V_19 += V_253 - 1 ;
continue;
}
if ( V_258 ) {
F_118 ( V_205 , L_19 ) ;
V_258 = false ;
}
V_255 = F_133 ( V_260 . V_261 [ V_19 ] ) ;
V_256 = V_255 >> 8 ;
V_257 = V_255 & 0xff ;
if ( V_256 )
F_118 ( V_205 , L_133 , V_256 , V_257 ) ;
else
F_118 ( V_205 , L_134 , V_257 ) ;
V_258 = true ;
}
if ( V_259 ) {
if ( V_258 )
F_118 ( V_205 , L_19 ) ;
F_128 ( V_205 , 'I' , & V_260 . V_262 [ 12 ] ) ;
}
return;
}
static void F_134 ( struct V_204 * V_205 , char V_19 , unsigned char * V_1 )
{
int V_250 ;
for ( V_250 = 0 ; V_250 < 16 ; V_250 += 2 ) {
F_118 ( V_205 , L_135 , V_1 [ V_250 ] , V_1 [ V_250 + 1 ] ) ;
if ( V_19 == 'I' && V_250 < 14 )
F_118 ( V_205 , L_19 ) ;
}
}
static int F_135 ( struct V_204 * V_205 , const char * V_184 , char V_19 ,
void * V_185 , int V_2 , struct V_49 * V_50 ,
struct V_7 * V_63 )
{
unsigned char * V_1 ;
if ( V_63 -> type == V_95 ) {
F_114 ( V_205 , V_185 , V_2 , V_50 , V_63 ) ;
return 0 ;
}
if ( V_63 -> type != V_67 ) {
F_118 ( V_205 , L_128 , V_63 -> type ) ;
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
V_1 = V_185 + V_63 -> V_68 . V_68 -> V_142 ;
if ( V_63 -> V_68 . V_68 -> V_2 != 4 ) {
F_118 ( V_205 , L_136 ) ;
return 0 ;
}
F_128 ( V_205 , V_19 , V_1 ) ;
return 0 ;
}
static int F_136 ( struct V_204 * V_205 , const char * V_184 , char V_19 ,
void * V_185 , int V_2 , struct V_49 * V_50 ,
struct V_7 * V_63 )
{
char V_263 = 0 ;
unsigned char * V_1 ;
int V_264 = 0 ;
if ( V_19 == 'I' && * V_184 == 'c' ) {
V_263 = 1 ;
V_184 ++ ;
V_264 ++ ;
}
if ( V_63 -> type == V_95 ) {
F_114 ( V_205 , V_185 , V_2 , V_50 , V_63 ) ;
return V_264 ;
}
if ( V_63 -> type != V_67 ) {
F_118 ( V_205 , L_128 , V_63 -> type ) ;
return V_264 ;
}
if ( ! V_63 -> V_68 . V_68 ) {
V_63 -> V_68 . V_68 =
F_72 ( V_50 , V_63 -> V_68 . V_69 ) ;
if ( ! V_63 -> V_68 . V_68 ) {
F_47 ( L_109 ,
V_131 , V_63 -> V_68 . V_69 ) ;
return V_264 ;
}
}
V_1 = V_185 + V_63 -> V_68 . V_68 -> V_142 ;
if ( V_63 -> V_68 . V_68 -> V_2 != 16 ) {
F_118 ( V_205 , L_137 ) ;
return V_264 ;
}
if ( V_263 )
F_132 ( V_205 , V_1 ) ;
else
F_134 ( V_205 , V_19 , V_1 ) ;
return V_264 ;
}
static int F_137 ( struct V_204 * V_205 , const char * V_184 , char V_19 ,
void * V_185 , int V_2 , struct V_49 * V_50 ,
struct V_7 * V_63 )
{
char V_263 = 0 , V_265 = 0 ;
unsigned char * V_1 ;
struct V_266 * V_267 ;
int V_264 = 0 ;
if ( V_19 == 'I' ) {
if ( * V_184 == 'p' ) {
V_265 = 1 ;
V_184 ++ ;
V_264 ++ ;
}
if ( * V_184 == 'c' ) {
V_263 = 1 ;
V_184 ++ ;
V_264 ++ ;
}
}
if ( V_63 -> type == V_95 ) {
F_114 ( V_205 , V_185 , V_2 , V_50 , V_63 ) ;
return V_264 ;
}
if ( V_63 -> type != V_67 ) {
F_118 ( V_205 , L_128 , V_63 -> type ) ;
return V_264 ;
}
if ( ! V_63 -> V_68 . V_68 ) {
V_63 -> V_68 . V_68 =
F_72 ( V_50 , V_63 -> V_68 . V_69 ) ;
if ( ! V_63 -> V_68 . V_68 ) {
F_47 ( L_109 ,
V_131 , V_63 -> V_68 . V_69 ) ;
return V_264 ;
}
}
V_267 = (struct V_266 * ) ( V_185 + V_63 -> V_68 . V_68 -> V_142 ) ;
if ( V_267 -> V_268 == V_269 ) {
struct V_270 * V_271 = (struct V_270 * ) V_267 ;
if ( V_63 -> V_68 . V_68 -> V_2 < sizeof( struct V_270 ) ) {
F_118 ( V_205 , L_136 ) ;
return V_264 ;
}
F_128 ( V_205 , V_19 , ( unsigned char * ) & V_271 -> V_272 ) ;
if ( V_265 )
F_118 ( V_205 , L_138 , F_133 ( V_271 -> V_273 ) ) ;
} else if ( V_267 -> V_268 == V_274 ) {
struct V_275 * V_276 = (struct V_275 * ) V_267 ;
if ( V_63 -> V_68 . V_68 -> V_2 < sizeof( struct V_275 ) ) {
F_118 ( V_205 , L_137 ) ;
return V_264 ;
}
if ( V_265 )
F_118 ( V_205 , L_38 ) ;
V_1 = ( unsigned char * ) & V_276 -> V_277 ;
if ( V_263 )
F_132 ( V_205 , V_1 ) ;
else
F_134 ( V_205 , V_19 , V_1 ) ;
if ( V_265 )
F_118 ( V_205 , L_139 , F_133 ( V_276 -> V_278 ) ) ;
}
return V_264 ;
}
static int F_138 ( struct V_204 * V_205 , const char * V_184 ,
void * V_185 , int V_2 , struct V_49 * V_50 ,
struct V_7 * V_63 )
{
char V_19 = * V_184 ;
char V_279 ;
int V_264 = 0 ;
V_184 ++ ;
V_264 ++ ;
V_279 = * V_184 ;
V_184 ++ ;
V_264 ++ ;
switch ( V_279 ) {
case '4' :
V_264 += F_135 ( V_205 , V_184 , V_19 , V_185 , V_2 , V_50 , V_63 ) ;
break;
case '6' :
V_264 += F_136 ( V_205 , V_184 , V_19 , V_185 , V_2 , V_50 , V_63 ) ;
break;
case 'S' :
V_264 += F_137 ( V_205 , V_184 , V_19 , V_185 , V_2 , V_50 , V_63 ) ;
break;
default:
return 0 ;
}
return V_264 ;
}
static int F_139 ( char * V_48 , unsigned int V_136 )
{
unsigned int V_19 ;
for ( V_19 = 0 ; V_19 < V_136 && V_48 [ V_19 ] ; V_19 ++ )
if ( ! isprint ( V_48 [ V_19 ] ) && ! isspace ( V_48 [ V_19 ] ) )
return 0 ;
return 1 ;
}
static void F_140 ( struct V_204 * V_205 , void * V_185 ,
int V_2 V_157 ,
struct V_49 * V_50 )
{
struct V_122 * V_68 ;
unsigned long long V_166 ;
unsigned int V_142 , V_136 , V_19 ;
V_68 = V_50 -> V_146 . V_125 ;
while ( V_68 ) {
F_118 ( V_205 , L_140 , V_68 -> V_69 ) ;
if ( V_68 -> V_71 & V_123 ) {
V_142 = V_68 -> V_142 ;
V_136 = V_68 -> V_2 ;
if ( V_68 -> V_71 & V_139 ) {
V_166 = F_96 ( V_50 -> V_14 , V_185 + V_142 , V_136 ) ;
V_142 = V_166 ;
V_136 = V_142 >> 16 ;
V_142 &= 0xffff ;
}
if ( V_68 -> V_71 & V_138 &&
F_139 ( V_185 + V_142 , V_136 ) ) {
F_118 ( V_205 , L_115 , ( char * ) V_185 + V_142 ) ;
} else {
F_121 ( V_205 , L_141 ) ;
for ( V_19 = 0 ; V_19 < V_136 ; V_19 ++ ) {
if ( V_19 )
F_121 ( V_205 , L_142 ) ;
F_118 ( V_205 , L_110 ,
* ( ( unsigned char * ) V_185 + V_142 + V_19 ) ) ;
}
F_122 ( V_205 , ']' ) ;
V_68 -> V_71 &= ~ V_138 ;
}
} else {
V_166 = F_96 ( V_50 -> V_14 , V_185 + V_68 -> V_142 ,
V_68 -> V_2 ) ;
if ( V_68 -> V_71 & V_129 ) {
F_118 ( V_205 , L_143 , V_166 ) ;
} else if ( V_68 -> V_71 & V_143 ) {
switch ( V_68 -> V_2 ) {
case 4 :
if ( V_68 -> V_71 & V_140 )
F_118 ( V_205 , L_144 , ( int ) V_166 ) ;
else
F_118 ( V_205 , L_145 , ( int ) V_166 ) ;
break;
case 2 :
F_118 ( V_205 , L_146 , ( short ) V_166 ) ;
break;
case 1 :
F_118 ( V_205 , L_147 , ( char ) V_166 ) ;
break;
default:
F_118 ( V_205 , L_80 , V_166 ) ;
}
} else {
if ( V_68 -> V_71 & V_140 )
F_118 ( V_205 , L_143 , V_166 ) ;
else
F_118 ( V_205 , L_148 , V_166 ) ;
}
}
V_68 = V_68 -> V_22 ;
}
}
static void F_141 ( struct V_204 * V_205 , void * V_185 , int V_2 , struct V_49 * V_50 )
{
struct V_14 * V_14 = V_50 -> V_14 ;
struct V_182 * V_182 = & V_50 -> V_182 ;
struct V_7 * V_63 = V_182 -> args ;
struct V_7 * args = NULL ;
const char * V_184 = V_182 -> V_146 ;
unsigned long long V_166 ;
struct V_28 * V_35 ;
const char * V_280 ;
struct V_204 V_48 ;
char * V_281 = NULL ;
char V_146 [ 32 ] ;
int V_282 ;
int V_283 ;
int V_209 ;
int V_136 ;
int V_244 ;
if ( V_50 -> V_71 & V_154 ) {
F_118 ( V_205 , L_149 ) ;
F_140 ( V_205 , V_185 , V_2 , V_50 ) ;
return;
}
if ( V_50 -> V_71 & V_284 ) {
V_281 = F_126 ( V_185 , V_2 , V_50 ) ;
args = F_125 ( V_281 , V_185 , V_2 , V_50 ) ;
V_63 = args ;
V_184 = V_281 ;
}
for (; * V_184 ; V_184 ++ ) {
V_244 = 0 ;
if ( * V_184 == '\\' ) {
V_184 ++ ;
switch ( * V_184 ) {
case 'n' :
F_122 ( V_205 , '\n' ) ;
break;
case 't' :
F_122 ( V_205 , '\t' ) ;
break;
case 'r' :
F_122 ( V_205 , '\r' ) ;
break;
case '\\' :
F_122 ( V_205 , '\\' ) ;
break;
default:
F_122 ( V_205 , * V_184 ) ;
break;
}
} else if ( * V_184 == '%' ) {
V_280 = V_184 ;
V_282 = 0 ;
V_283 = 0 ;
V_285:
V_184 ++ ;
switch ( * V_184 ) {
case '%' :
F_122 ( V_205 , '%' ) ;
break;
case '#' :
goto V_285;
case 'h' :
V_244 -- ;
goto V_285;
case 'l' :
V_244 ++ ;
goto V_285;
case 'L' :
V_244 = 2 ;
goto V_285;
case '*' :
if ( ! V_63 ) {
F_61 ( V_50 , L_150 ) ;
V_50 -> V_71 |= V_154 ;
goto V_286;
}
V_209 = F_111 ( V_185 , V_2 , V_50 , V_63 ) ;
V_283 = 1 ;
V_63 = V_63 -> V_22 ;
goto V_285;
case '.' :
case 'z' :
case 'Z' :
case '0' ... '9' :
goto V_285;
case 'p' :
if ( V_14 -> V_145 == 4 )
V_244 = 1 ;
else
V_244 = 2 ;
if ( * ( V_184 + 1 ) == 'F' ||
* ( V_184 + 1 ) == 'f' ) {
V_184 ++ ;
V_282 = * V_184 ;
} else if ( * ( V_184 + 1 ) == 'M' || * ( V_184 + 1 ) == 'm' ) {
F_127 ( V_205 , * ( V_184 + 1 ) , V_185 , V_2 , V_50 , V_63 ) ;
V_184 ++ ;
V_63 = V_63 -> V_22 ;
break;
} else if ( * ( V_184 + 1 ) == 'I' || * ( V_184 + 1 ) == 'i' ) {
int V_287 ;
V_287 = F_138 ( V_205 , V_184 + 1 , V_185 , V_2 , V_50 , V_63 ) ;
if ( V_287 > 0 ) {
V_184 += V_287 ;
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
V_50 -> V_71 |= V_154 ;
goto V_286;
}
V_136 = ( ( unsigned long ) V_184 + 1 ) -
( unsigned long ) V_280 ;
if ( V_136 > 31 ) {
F_61 ( V_50 , L_151 ) ;
V_50 -> V_71 |= V_154 ;
V_136 = 31 ;
}
memcpy ( V_146 , V_280 , V_136 ) ;
V_146 [ V_136 ] = 0 ;
V_166 = F_111 ( V_185 , V_2 , V_50 , V_63 ) ;
V_63 = V_63 -> V_22 ;
if ( V_282 ) {
V_35 = F_18 ( V_14 , V_166 ) ;
if ( V_35 ) {
F_121 ( V_205 , V_35 -> V_35 ) ;
if ( V_282 == 'F' )
F_118 ( V_205 ,
L_152 ,
V_166 - V_35 -> V_31 ) ;
break;
}
}
if ( V_14 -> V_145 == 8 && V_244 &&
sizeof( long ) != 8 ) {
char * V_48 ;
V_244 = 2 ;
V_48 = strchr ( V_146 , 'l' ) ;
if ( V_48 )
memmove ( V_48 + 1 , V_48 , strlen ( V_48 ) + 1 ) ;
else if ( strcmp ( V_146 , L_153 ) == 0 )
strcpy ( V_146 , L_143 ) ;
}
switch ( V_244 ) {
case - 2 :
if ( V_283 )
F_118 ( V_205 , V_146 , V_209 , ( char ) V_166 ) ;
else
F_118 ( V_205 , V_146 , ( char ) V_166 ) ;
break;
case - 1 :
if ( V_283 )
F_118 ( V_205 , V_146 , V_209 , ( short ) V_166 ) ;
else
F_118 ( V_205 , V_146 , ( short ) V_166 ) ;
break;
case 0 :
if ( V_283 )
F_118 ( V_205 , V_146 , V_209 , ( int ) V_166 ) ;
else
F_118 ( V_205 , V_146 , ( int ) V_166 ) ;
break;
case 1 :
if ( V_283 )
F_118 ( V_205 , V_146 , V_209 , ( long ) V_166 ) ;
else
F_118 ( V_205 , V_146 , ( long ) V_166 ) ;
break;
case 2 :
if ( V_283 )
F_118 ( V_205 , V_146 , V_209 ,
( long long ) V_166 ) ;
else
F_118 ( V_205 , V_146 , ( long long ) V_166 ) ;
break;
default:
F_61 ( V_50 , L_154 , V_244 ) ;
V_50 -> V_71 |= V_154 ;
}
break;
case 's' :
if ( ! V_63 ) {
F_61 ( V_50 , L_155 ) ;
V_50 -> V_71 |= V_154 ;
goto V_286;
}
V_136 = ( ( unsigned long ) V_184 + 1 ) -
( unsigned long ) V_280 ;
if ( V_136 > 31 ) {
F_61 ( V_50 , L_151 ) ;
V_50 -> V_71 |= V_154 ;
V_136 = 31 ;
}
memcpy ( V_146 , V_280 , V_136 ) ;
V_146 [ V_136 ] = 0 ;
if ( ! V_283 )
V_209 = - 1 ;
F_113 ( & V_48 ) ;
F_120 ( & V_48 , V_185 , V_2 , V_50 ,
V_146 , V_209 , V_63 ) ;
F_123 ( & V_48 ) ;
F_121 ( V_205 , V_48 . V_236 ) ;
F_115 ( & V_48 ) ;
V_63 = V_63 -> V_22 ;
break;
default:
F_118 ( V_205 , L_156 , * V_184 ) ;
}
} else
F_122 ( V_205 , * V_184 ) ;
}
if ( V_50 -> V_71 & V_154 ) {
V_286:
F_118 ( V_205 , L_149 ) ;
}
if ( args ) {
F_124 ( args ) ;
free ( V_281 ) ;
}
}
void F_142 ( struct V_14 * V_14 ,
struct V_204 * V_205 , struct V_288 * V_289 )
{
static int V_290 = 1 ;
static int V_291 = 1 ;
static int V_292 ;
static int V_293 ;
unsigned int V_294 ;
unsigned int V_295 ;
int V_296 ;
int V_297 ;
int V_298 ;
int V_299 ;
void * V_185 = V_289 -> V_185 ;
V_294 = F_106 ( V_14 , V_185 ) ;
V_295 = F_105 ( V_14 , V_185 ) ;
if ( V_292 )
V_296 = F_107 ( V_14 , V_185 ) ;
else if ( V_290 ) {
V_296 = F_107 ( V_14 , V_185 ) ;
if ( V_296 < 0 )
V_290 = 0 ;
else
V_292 = 1 ;
}
if ( V_293 )
V_297 = F_108 ( V_14 , V_185 ) ;
else if ( V_291 ) {
V_297 = F_108 ( V_14 , V_185 ) ;
if ( V_297 < 0 )
V_291 = 0 ;
else
V_293 = 1 ;
}
V_298 = V_294 & V_300 ;
V_299 = V_294 & V_301 ;
F_118 ( V_205 , L_157 ,
( V_294 & V_302 ) ? 'd' :
( V_294 & V_303 ) ?
'X' : '.' ,
( V_294 & V_304 ) ?
'N' : '.' ,
( V_298 && V_299 ) ? 'H' :
V_298 ? 'h' : V_299 ? 's' : '.' ) ;
if ( V_295 )
F_118 ( V_205 , L_134 , V_295 ) ;
else
F_122 ( V_205 , '.' ) ;
if ( V_293 ) {
if ( V_297 < 0 )
F_122 ( V_205 , '.' ) ;
else
F_118 ( V_205 , L_145 , V_297 ) ;
}
if ( V_292 ) {
if ( V_296 < 0 )
F_122 ( V_205 , '.' ) ;
else
F_118 ( V_205 , L_145 , V_296 ) ;
}
F_123 ( V_205 ) ;
}
int F_143 ( struct V_14 * V_14 , struct V_288 * V_305 )
{
return F_103 ( V_14 , V_305 -> V_185 ) ;
}
struct V_49 * F_144 ( struct V_14 * V_14 , int type )
{
return F_109 ( V_14 , type ) ;
}
int F_145 ( struct V_14 * V_14 , struct V_288 * V_305 )
{
return F_104 ( V_14 , V_305 -> V_185 ) ;
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
void F_150 ( struct V_204 * V_205 , struct V_49 * V_50 ,
struct V_288 * V_289 )
{
int V_306 = 1 ;
if ( V_50 -> V_14 -> V_307 || ( V_50 -> V_71 & V_308 ) )
F_140 ( V_205 , V_289 -> V_185 , V_289 -> V_2 , V_50 ) ;
else {
if ( V_50 -> V_309 && ! ( V_50 -> V_71 & V_310 ) )
V_306 = V_50 -> V_309 ( V_205 , V_289 , V_50 ,
V_50 -> V_311 ) ;
if ( V_306 )
F_141 ( V_205 , V_289 -> V_185 , V_289 -> V_2 , V_50 ) ;
}
F_123 ( V_205 ) ;
}
static bool F_151 ( char * V_27 , bool V_312 )
{
if ( ! V_312 )
return true ;
if ( ! strcmp ( V_27 , L_158 ) || ! strcmp ( V_27 , L_159 )
|| ! strcmp ( V_27 , L_160 ) || ! strcmp ( V_27 , L_161 ) )
return true ;
return false ;
}
void F_152 ( struct V_14 * V_14 , struct V_204 * V_205 ,
struct V_288 * V_289 , bool V_312 )
{
static const char * V_313 = L_162 ;
struct V_49 * V_50 ;
unsigned long V_314 ;
unsigned long V_315 ;
unsigned long V_316 ;
const char * V_21 ;
void * V_185 = V_289 -> V_185 ;
int type ;
int V_13 ;
int V_136 ;
int V_48 ;
bool V_317 ;
V_317 = F_151 ( V_14 -> V_27 ,
V_312 ) ;
if ( V_317 ) {
V_314 = V_289 -> V_318 / V_319 ;
V_316 = V_289 -> V_318 - V_314 * V_319 ;
}
if ( V_289 -> V_2 < 0 ) {
F_47 ( L_163 , V_289 -> V_2 ) ;
return;
}
type = F_103 ( V_14 , V_185 ) ;
V_50 = F_109 ( V_14 , type ) ;
if ( ! V_50 ) {
F_47 ( L_164 , type ) ;
return;
}
V_13 = F_104 ( V_14 , V_185 ) ;
V_21 = F_9 ( V_14 , V_13 ) ;
if ( V_14 -> V_320 ) {
F_118 ( V_205 , L_165 ,
V_21 , V_13 , V_289 -> V_321 ) ;
F_142 ( V_14 , V_205 , V_289 ) ;
} else
F_118 ( V_205 , L_166 , V_21 , V_13 , V_289 -> V_321 ) ;
if ( V_317 ) {
if ( V_14 -> V_71 & V_322 ) {
V_315 = V_316 ;
V_48 = 9 ;
} else {
V_315 = ( V_316 + 500 ) / V_323 ;
V_48 = 6 ;
}
F_118 ( V_205 , L_167 ,
V_314 , V_48 , V_315 , V_50 -> V_69 ) ;
} else
F_118 ( V_205 , L_168 ,
V_289 -> V_318 , V_50 -> V_69 ) ;
V_136 = strlen ( V_50 -> V_69 ) ;
if ( V_136 < 20 )
F_118 ( V_205 , L_169 , 20 - V_136 , V_313 ) ;
F_150 ( V_205 , V_50 , V_289 ) ;
}
static int V_198 ( const void * V_8 , const void * V_9 )
{
struct V_49 * const * V_324 = V_8 ;
struct V_49 * const * V_325 = V_9 ;
if ( ( * V_324 ) -> V_53 < ( * V_325 ) -> V_53 )
return - 1 ;
if ( ( * V_324 ) -> V_53 > ( * V_325 ) -> V_53 )
return 1 ;
return 0 ;
}
static int F_153 ( const void * V_8 , const void * V_9 )
{
struct V_49 * const * V_324 = V_8 ;
struct V_49 * const * V_325 = V_9 ;
int V_326 ;
V_326 = strcmp ( ( * V_324 ) -> V_69 , ( * V_325 ) -> V_69 ) ;
if ( V_326 )
return V_326 ;
V_326 = strcmp ( ( * V_324 ) -> system , ( * V_325 ) -> system ) ;
if ( V_326 )
return V_326 ;
return V_198 ( V_8 , V_9 ) ;
}
static int F_154 ( const void * V_8 , const void * V_9 )
{
struct V_49 * const * V_324 = V_8 ;
struct V_49 * const * V_325 = V_9 ;
int V_326 ;
V_326 = strcmp ( ( * V_324 ) -> system , ( * V_325 ) -> system ) ;
if ( V_326 )
return V_326 ;
V_326 = strcmp ( ( * V_324 ) -> V_69 , ( * V_325 ) -> V_69 ) ;
if ( V_326 )
return V_326 ;
return V_198 ( V_8 , V_9 ) ;
}
struct V_49 * * F_155 ( struct V_14 * V_14 , enum V_327 V_328 )
{
struct V_49 * * V_51 ;
int (* F_156)( const void * V_8 , const void * V_9 );
V_51 = V_14 -> V_329 ;
if ( V_51 && V_14 -> V_133 == V_328 )
return V_51 ;
if ( ! V_51 ) {
V_51 = malloc ( sizeof( * V_51 ) * ( V_14 -> V_52 + 1 ) ) ;
if ( ! V_51 )
return NULL ;
memcpy ( V_51 , V_14 -> V_51 , sizeof( * V_51 ) * V_14 -> V_52 ) ;
V_51 [ V_14 -> V_52 ] = NULL ;
V_14 -> V_329 = V_51 ;
if ( V_328 == V_330 ) {
V_14 -> V_133 = V_328 ;
return V_51 ;
}
}
switch ( V_328 ) {
case V_330 :
F_156 = V_198 ;
break;
case V_331 :
F_156 = F_153 ;
break;
case V_332 :
F_156 = F_154 ;
break;
default:
return V_51 ;
}
qsort ( V_51 , V_14 -> V_52 , sizeof( * V_51 ) , F_156 ) ;
V_14 -> V_133 = V_328 ;
return V_51 ;
}
static struct V_122 * *
F_157 ( const char * type , const char * V_69 ,
int V_80 , struct V_122 * V_170 )
{
struct V_122 * * V_125 ;
struct V_122 * V_68 ;
int V_19 = 0 ;
V_125 = malloc ( sizeof( * V_125 ) * ( V_80 + 1 ) ) ;
if ( ! V_125 )
return NULL ;
for ( V_68 = V_170 ; V_68 ; V_68 = V_68 -> V_22 ) {
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
V_50 -> V_146 . V_148 ,
V_50 -> V_146 . V_147 ) ;
}
struct V_122 * * F_159 ( struct V_49 * V_50 )
{
return F_157 ( L_173 , V_50 -> V_69 ,
V_50 -> V_146 . V_149 ,
V_50 -> V_146 . V_125 ) ;
}
static void F_160 ( struct V_204 * V_205 , struct V_59 * V_68 )
{
F_118 ( V_205 , L_174 , V_68 -> V_61 , V_68 -> V_62 ) ;
if ( V_68 -> V_22 ) {
F_121 ( V_205 , L_142 ) ;
F_160 ( V_205 , V_68 -> V_22 ) ;
}
}
static void F_161 ( struct V_7 * args )
{
int V_333 = 1 ;
struct V_204 V_205 ;
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
F_113 ( & V_205 ) ;
F_160 ( & V_205 , args -> V_71 . V_71 ) ;
F_162 ( & V_205 ) ;
F_115 ( & V_205 ) ;
printf ( L_69 ) ;
break;
case V_73 :
printf ( L_179 ) ;
F_161 ( args -> V_74 . V_68 ) ;
printf ( L_142 ) ;
F_113 ( & V_205 ) ;
F_160 ( & V_205 , args -> V_74 . V_75 ) ;
F_162 ( & V_205 ) ;
F_115 ( & V_205 ) ;
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
V_333 = 0 ;
if ( V_333 )
printf ( L_84 ) ;
F_161 ( args -> V_92 . V_93 ) ;
printf ( L_185 , args -> V_92 . V_92 ) ;
F_161 ( args -> V_92 . V_94 ) ;
if ( V_333 )
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
int * V_142 , int * V_2 , int V_334 )
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
if ( V_334 ) {
if ( F_52 ( V_55 , V_68 ) < 0 )
return;
} else {
if ( F_50 ( V_55 , & V_116 ) < 0 )
goto V_121;
if ( strcmp ( V_116 , V_68 ) != 0 )
goto V_335;
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
* V_142 = atoi ( V_116 ) ;
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
V_335:
V_5 = V_113 ;
V_4 = V_115 ;
* V_142 = 0 ;
* V_2 = 0 ;
F_41 ( V_116 ) ;
}
int F_164 ( struct V_14 * V_14 , char * V_1 , unsigned long V_2 ,
int V_145 )
{
int V_336 ;
if ( ! V_2 ) {
V_14 -> V_337 = sizeof( long long ) ;
V_14 -> V_338 = V_145 ;
V_14 -> V_339 = sizeof( long long ) + V_145 ;
V_14 -> V_340 = 1 ;
return - 1 ;
}
F_1 ( V_1 , V_2 ) ;
F_163 ( L_186 , & V_14 -> V_341 ,
& V_14 -> V_337 , 1 ) ;
F_163 ( L_187 , & V_14 -> V_342 ,
& V_14 -> V_338 , 1 ) ;
F_163 ( L_188 , & V_14 -> V_343 ,
& V_336 , 0 ) ;
F_163 ( L_189 , & V_14 -> V_339 ,
& V_14 -> V_344 , 1 ) ;
return 0 ;
}
static int F_165 ( struct V_49 * V_50 ,
int V_53 , const char * V_345 ,
const char * V_346 )
{
if ( V_53 >= 0 && V_53 != V_50 -> V_53 )
return 0 ;
if ( V_346 && ( strcmp ( V_346 , V_50 -> V_69 ) != 0 ) )
return 0 ;
if ( V_345 && ( strcmp ( V_345 , V_50 -> system ) != 0 ) )
return 0 ;
return 1 ;
}
static void F_166 ( struct V_347 * V_348 )
{
free ( ( void * ) V_348 -> V_345 ) ;
free ( ( void * ) V_348 -> V_346 ) ;
free ( V_348 ) ;
}
static int F_167 ( struct V_14 * V_14 , struct V_49 * V_50 )
{
struct V_347 * V_348 , * * V_22 ;
for ( V_22 = & V_14 -> V_349 ; * V_22 ;
V_22 = & ( * V_22 ) -> V_22 ) {
V_348 = * V_22 ;
if ( F_165 ( V_50 , V_348 -> V_53 ,
V_348 -> V_345 ,
V_348 -> V_346 ) )
break;
}
if ( ! ( * V_22 ) )
return 0 ;
F_168 ( L_190 ,
V_50 -> V_53 , V_50 -> system , V_50 -> V_69 ) ;
V_50 -> V_309 = V_348 -> V_35 ;
V_50 -> V_311 = V_348 -> V_311 ;
* V_22 = V_348 -> V_22 ;
F_166 ( V_348 ) ;
return 1 ;
}
enum V_350 F_169 ( struct V_49 * * V_351 ,
struct V_14 * V_14 , const char * V_1 ,
unsigned long V_2 , const char * V_199 )
{
struct V_49 * V_50 ;
int V_120 ;
F_1 ( V_1 , V_2 ) ;
* V_351 = V_50 = F_28 () ;
if ( ! V_50 )
return V_352 ;
V_50 -> V_69 = F_54 () ;
if ( ! V_50 -> V_69 ) {
V_120 = V_352 ;
goto V_353;
}
if ( strcmp ( V_199 , L_191 ) == 0 ) {
V_50 -> V_71 |= V_128 ;
if ( strcmp ( V_50 -> V_69 , L_192 ) == 0 )
V_50 -> V_71 |= V_284 ;
}
V_50 -> V_53 = F_55 () ;
if ( V_50 -> V_53 < 0 ) {
V_120 = V_354 ;
goto V_353;
}
V_50 -> system = F_12 ( V_199 ) ;
if ( ! V_50 -> system ) {
V_120 = V_352 ;
goto V_353;
}
V_50 -> V_14 = V_14 ;
V_120 = F_62 ( V_50 ) ;
if ( V_120 < 0 ) {
V_120 = V_355 ;
goto V_356;
}
if ( V_14 && F_167 ( V_14 , V_50 ) )
V_357 = 0 ;
V_120 = F_94 ( V_50 ) ;
V_357 = 1 ;
if ( V_120 < 0 ) {
V_120 = V_358 ;
goto V_356;
}
if ( ! V_120 && ( V_50 -> V_71 & V_128 ) ) {
struct V_122 * V_68 ;
struct V_7 * V_63 , * * V_170 ;
V_170 = & V_50 -> V_182 . args ;
for ( V_68 = V_50 -> V_146 . V_125 ; V_68 ; V_68 = V_68 -> V_22 ) {
V_63 = F_6 () ;
if ( ! V_63 ) {
V_50 -> V_71 |= V_154 ;
return V_359 ;
}
V_63 -> type = V_67 ;
V_63 -> V_68 . V_69 = F_12 ( V_68 -> V_69 ) ;
if ( ! V_63 -> V_68 . V_69 ) {
V_50 -> V_71 |= V_154 ;
F_32 ( V_63 ) ;
return V_359 ;
}
V_63 -> V_68 . V_68 = V_68 ;
* V_170 = V_63 ;
V_170 = & V_63 -> V_22 ;
}
return 0 ;
}
return 0 ;
V_356:
V_50 -> V_71 |= V_154 ;
return V_120 ;
V_353:
free ( V_50 -> system ) ;
free ( V_50 -> V_69 ) ;
free ( V_50 ) ;
* V_351 = NULL ;
return V_120 ;
}
static enum V_350
F_170 ( struct V_14 * V_14 ,
struct V_49 * * V_351 ,
const char * V_1 , unsigned long V_2 ,
const char * V_199 )
{
int V_120 = F_169 ( V_351 , V_14 , V_1 , V_2 , V_199 ) ;
struct V_49 * V_50 = * V_351 ;
if ( V_50 == NULL )
return V_120 ;
if ( V_14 && F_29 ( V_14 , V_50 ) ) {
V_120 = V_352 ;
goto V_360;
}
#define F_171 0
if ( F_171 && V_50 -> V_182 . args )
F_161 ( V_50 -> V_182 . args ) ;
return 0 ;
V_360:
F_172 ( V_50 ) ;
return V_120 ;
}
enum V_350 F_173 ( struct V_14 * V_14 ,
struct V_49 * * V_351 ,
const char * V_1 ,
unsigned long V_2 , const char * V_199 )
{
return F_170 ( V_14 , V_351 , V_1 , V_2 , V_199 ) ;
}
enum V_350 F_174 ( struct V_14 * V_14 , const char * V_1 ,
unsigned long V_2 , const char * V_199 )
{
struct V_49 * V_50 = NULL ;
return F_170 ( V_14 , & V_50 , V_1 , V_2 , V_199 ) ;
}
int F_175 ( struct V_14 * V_14 V_157 ,
enum V_350 V_361 , char * V_1 , T_1 V_362 )
{
int V_363 ;
const char * V_364 ;
if ( V_361 >= 0 ) {
V_364 = F_176 ( V_361 , V_1 , V_362 ) ;
if ( V_364 != V_1 ) {
T_1 V_136 = strlen ( V_364 ) ;
memcpy ( V_1 , V_364 , F_177 ( V_362 - 1 , V_136 ) ) ;
* ( V_1 + F_177 ( V_362 - 1 , V_136 ) ) = '\0' ;
}
return 0 ;
}
if ( V_361 <= V_365 ||
V_361 >= V_366 )
return - 1 ;
V_363 = V_361 - V_365 - 1 ;
V_364 = V_367 [ V_363 ] ;
snprintf ( V_1 , V_362 , L_115 , V_364 ) ;
return 0 ;
}
int F_178 ( struct V_204 * V_205 , struct V_122 * V_68 ,
const char * V_69 , struct V_288 * V_289 ,
unsigned long long * V_166 , int V_181 )
{
if ( ! V_68 ) {
if ( V_181 )
F_118 ( V_205 , L_193 , V_69 ) ;
return - 1 ;
}
if ( F_100 ( V_68 , V_289 -> V_185 , V_166 ) ) {
if ( V_181 )
F_118 ( V_205 , L_194 , V_69 ) ;
return - 1 ;
}
return 0 ;
}
void * F_179 ( struct V_204 * V_205 , struct V_49 * V_50 ,
const char * V_69 , struct V_288 * V_289 ,
int * V_136 , int V_181 )
{
struct V_122 * V_68 ;
void * V_185 = V_289 -> V_185 ;
unsigned V_142 ;
int V_368 ;
if ( ! V_50 )
return NULL ;
V_68 = F_84 ( V_50 , V_69 ) ;
if ( ! V_68 ) {
if ( V_181 )
F_118 ( V_205 , L_193 , V_69 ) ;
return NULL ;
}
if ( ! V_136 )
V_136 = & V_368 ;
V_142 = V_68 -> V_142 ;
if ( V_68 -> V_71 & V_139 ) {
V_142 = F_96 ( V_50 -> V_14 ,
V_185 + V_142 , V_68 -> V_2 ) ;
* V_136 = V_142 >> 16 ;
V_142 &= 0xffff ;
} else
* V_136 = V_68 -> V_2 ;
return V_185 + V_142 ;
}
int F_180 ( struct V_204 * V_205 , struct V_49 * V_50 ,
const char * V_69 , struct V_288 * V_289 ,
unsigned long long * V_166 , int V_181 )
{
struct V_122 * V_68 ;
if ( ! V_50 )
return - 1 ;
V_68 = F_84 ( V_50 , V_69 ) ;
return F_178 ( V_205 , V_68 , V_69 , V_289 , V_166 , V_181 ) ;
}
int F_181 ( struct V_204 * V_205 , struct V_49 * V_50 ,
const char * V_69 , struct V_288 * V_289 ,
unsigned long long * V_166 , int V_181 )
{
struct V_122 * V_68 ;
if ( ! V_50 )
return - 1 ;
V_68 = F_95 ( V_50 , V_69 ) ;
return F_178 ( V_205 , V_68 , V_69 , V_289 , V_166 , V_181 ) ;
}
int F_182 ( struct V_204 * V_205 , struct V_49 * V_50 ,
const char * V_69 , struct V_288 * V_289 ,
unsigned long long * V_166 , int V_181 )
{
struct V_122 * V_68 ;
if ( ! V_50 )
return - 1 ;
V_68 = F_72 ( V_50 , V_69 ) ;
return F_178 ( V_205 , V_68 , V_69 , V_289 , V_166 , V_181 ) ;
}
int F_183 ( struct V_204 * V_205 , const char * V_47 ,
struct V_49 * V_50 , const char * V_69 ,
struct V_288 * V_289 , int V_181 )
{
struct V_122 * V_68 = F_84 ( V_50 , V_69 ) ;
unsigned long long V_166 ;
if ( ! V_68 )
goto V_369;
if ( F_100 ( V_68 , V_289 -> V_185 , & V_166 ) )
goto V_369;
return F_118 ( V_205 , V_47 , V_166 ) ;
V_369:
if ( V_181 )
F_118 ( V_205 , L_195 , V_69 ) ;
return - 1 ;
}
int F_184 ( struct V_204 * V_205 , const char * V_47 ,
struct V_49 * V_50 , const char * V_69 ,
struct V_288 * V_289 , int V_181 )
{
struct V_122 * V_68 = F_84 ( V_50 , V_69 ) ;
struct V_14 * V_14 = V_50 -> V_14 ;
unsigned long long V_166 ;
struct V_28 * V_35 ;
char V_156 [ 128 ] ;
if ( ! V_68 )
goto V_369;
if ( F_100 ( V_68 , V_289 -> V_185 , & V_166 ) )
goto V_369;
V_35 = F_18 ( V_14 , V_166 ) ;
if ( V_35 )
snprintf ( V_156 , 128 , L_196 , V_35 -> V_35 , V_35 -> V_31 - V_166 ) ;
else
sprintf ( V_156 , L_197 , V_166 ) ;
return F_118 ( V_205 , V_47 , V_156 ) ;
V_369:
if ( V_181 )
F_118 ( V_205 , L_195 , V_69 ) ;
return - 1 ;
}
static void F_90 ( struct V_176 * V_35 )
{
struct V_226 * V_230 ;
free ( V_35 -> V_69 ) ;
while ( V_35 -> V_230 ) {
V_230 = V_35 -> V_230 ;
V_35 -> V_230 = V_230 -> V_22 ;
free ( V_230 ) ;
}
free ( V_35 ) ;
}
int F_185 ( struct V_14 * V_14 ,
T_2 V_35 ,
enum V_370 V_371 ,
char * V_69 , ... )
{
struct V_176 * V_225 ;
struct V_226 * * V_372 ;
struct V_226 * V_227 ;
enum V_370 type ;
T_3 V_373 ;
int V_120 ;
V_225 = F_88 ( V_14 , V_69 ) ;
if ( V_225 ) {
F_168 ( L_198 , V_69 ) ;
F_89 ( V_14 , V_69 ) ;
}
V_225 = calloc ( 1 , sizeof( * V_225 ) ) ;
if ( ! V_225 ) {
F_47 ( L_199 ) ;
return V_352 ;
}
V_225 -> V_371 = V_371 ;
V_225 -> V_69 = F_12 ( V_69 ) ;
V_225 -> V_35 = V_35 ;
if ( ! V_225 -> V_69 ) {
F_47 ( L_200 ) ;
free ( V_225 ) ;
return V_352 ;
}
V_372 = & ( V_225 -> V_230 ) ;
va_start ( V_373 , V_69 ) ;
for (; ; ) {
type = va_arg ( V_373 , enum V_370 ) ;
if ( type == V_374 )
break;
if ( type >= V_375 ) {
F_47 ( L_201 , type ) ;
V_120 = V_376 ;
goto V_38;
}
V_227 = malloc ( sizeof( * V_227 ) ) ;
if ( ! V_227 ) {
F_47 ( L_202 ) ;
V_120 = V_352 ;
goto V_38;
}
V_227 -> type = type ;
V_227 -> V_22 = NULL ;
* V_372 = V_227 ;
V_372 = & ( V_227 -> V_22 ) ;
V_225 -> V_180 ++ ;
}
va_end ( V_373 ) ;
V_225 -> V_22 = V_14 -> V_178 ;
V_14 -> V_178 = V_225 ;
return 0 ;
V_38:
va_end ( V_373 ) ;
F_90 ( V_225 ) ;
return V_120 ;
}
int F_186 ( struct V_14 * V_14 ,
T_2 V_35 , char * V_69 )
{
struct V_176 * V_225 ;
V_225 = F_88 ( V_14 , V_69 ) ;
if ( V_225 && V_225 -> V_35 == V_35 ) {
F_89 ( V_14 , V_69 ) ;
return 0 ;
}
return - 1 ;
}
static struct V_49 * F_187 ( struct V_14 * V_14 , int V_53 ,
const char * V_345 ,
const char * V_346 )
{
struct V_49 * V_50 ;
if ( V_53 >= 0 ) {
V_50 = F_109 ( V_14 , V_53 ) ;
if ( ! V_50 )
return NULL ;
if ( V_346 && ( strcmp ( V_346 , V_50 -> V_69 ) != 0 ) )
return NULL ;
if ( V_345 && ( strcmp ( V_345 , V_50 -> system ) != 0 ) )
return NULL ;
} else {
V_50 = F_110 ( V_14 , V_345 , V_346 ) ;
if ( ! V_50 )
return NULL ;
}
return V_50 ;
}
int F_188 ( struct V_14 * V_14 , int V_53 ,
const char * V_345 , const char * V_346 ,
T_4 V_35 , void * V_311 )
{
struct V_49 * V_50 ;
struct V_347 * V_348 ;
V_50 = F_187 ( V_14 , V_53 , V_345 , V_346 ) ;
if ( V_50 == NULL )
goto V_377;
F_168 ( L_190 ,
V_50 -> V_53 , V_50 -> system , V_50 -> V_69 ) ;
V_50 -> V_309 = V_35 ;
V_50 -> V_311 = V_311 ;
return 0 ;
V_377:
V_348 = calloc ( 1 , sizeof( * V_348 ) ) ;
if ( ! V_348 ) {
F_47 ( L_203 ) ;
return V_352 ;
}
V_348 -> V_53 = V_53 ;
if ( V_346 )
V_348 -> V_346 = F_12 ( V_346 ) ;
if ( V_345 )
V_348 -> V_345 = F_12 ( V_345 ) ;
if ( ( V_346 && ! V_348 -> V_346 ) ||
( V_345 && ! V_348 -> V_345 ) ) {
F_47 ( L_204 ) ;
free ( ( void * ) V_348 -> V_346 ) ;
free ( ( void * ) V_348 -> V_345 ) ;
free ( V_348 ) ;
return V_352 ;
}
V_348 -> V_35 = V_35 ;
V_348 -> V_22 = V_14 -> V_349 ;
V_14 -> V_349 = V_348 ;
V_348 -> V_311 = V_311 ;
return - 1 ;
}
static int F_189 ( struct V_347 * V_309 , int V_53 ,
const char * V_345 , const char * V_346 ,
T_4 V_35 , void * V_311 )
{
if ( V_53 >= 0 && V_53 != V_309 -> V_53 )
return 0 ;
if ( V_346 && ( strcmp ( V_346 , V_309 -> V_346 ) != 0 ) )
return 0 ;
if ( V_345 && ( strcmp ( V_345 , V_309 -> V_345 ) != 0 ) )
return 0 ;
if ( V_35 != V_309 -> V_35 || V_311 != V_309 -> V_311 )
return 0 ;
return 1 ;
}
int F_190 ( struct V_14 * V_14 , int V_53 ,
const char * V_345 , const char * V_346 ,
T_4 V_35 , void * V_311 )
{
struct V_49 * V_50 ;
struct V_347 * V_348 ;
struct V_347 * * V_22 ;
V_50 = F_187 ( V_14 , V_53 , V_345 , V_346 ) ;
if ( V_50 == NULL )
goto V_377;
if ( V_50 -> V_309 == V_35 && V_50 -> V_311 == V_311 ) {
F_168 ( L_205 ,
V_50 -> V_53 , V_50 -> system , V_50 -> V_69 ) ;
V_50 -> V_309 = NULL ;
V_50 -> V_311 = NULL ;
return 0 ;
}
V_377:
for ( V_22 = & V_14 -> V_349 ; * V_22 ; V_22 = & ( * V_22 ) -> V_22 ) {
V_348 = * V_22 ;
if ( F_189 ( V_348 , V_53 , V_345 , V_346 ,
V_35 , V_311 ) )
break;
}
if ( ! ( * V_22 ) )
return - 1 ;
* V_22 = V_348 -> V_22 ;
F_166 ( V_348 ) ;
return 0 ;
}
struct V_14 * F_191 ( void )
{
struct V_14 * V_14 = calloc ( 1 , sizeof( * V_14 ) ) ;
if ( V_14 )
V_14 -> V_378 = 1 ;
return V_14 ;
}
void F_192 ( struct V_14 * V_14 )
{
V_14 -> V_378 ++ ;
}
void F_193 ( struct V_122 * V_68 )
{
free ( V_68 -> type ) ;
if ( V_68 -> V_132 != V_68 -> V_69 )
free ( V_68 -> V_132 ) ;
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
static void F_195 ( struct V_146 * V_146 )
{
F_194 ( V_146 -> V_147 ) ;
F_194 ( V_146 -> V_125 ) ;
}
void F_172 ( struct V_49 * V_50 )
{
free ( V_50 -> V_69 ) ;
free ( V_50 -> system ) ;
F_195 ( & V_50 -> V_146 ) ;
free ( V_50 -> V_182 . V_146 ) ;
F_124 ( V_50 -> V_182 . args ) ;
free ( V_50 ) ;
}
void F_196 ( struct V_14 * V_14 )
{
struct V_15 * V_16 , * V_379 ;
struct V_32 * V_33 , * V_380 ;
struct V_43 * V_44 , * V_381 ;
struct V_176 * V_382 ;
struct V_347 * V_348 ;
int V_19 ;
if ( ! V_14 )
return;
V_16 = V_14 -> V_16 ;
V_33 = V_14 -> V_33 ;
V_44 = V_14 -> V_44 ;
V_14 -> V_378 -- ;
if ( V_14 -> V_378 )
return;
if ( V_14 -> V_18 ) {
for ( V_19 = 0 ; V_19 < V_14 -> V_20 ; V_19 ++ )
free ( V_14 -> V_18 [ V_19 ] . V_21 ) ;
free ( V_14 -> V_18 ) ;
}
while ( V_16 ) {
V_379 = V_16 -> V_22 ;
free ( V_16 -> V_21 ) ;
free ( V_16 ) ;
V_16 = V_379 ;
}
if ( V_14 -> V_28 ) {
for ( V_19 = 0 ; V_19 < ( int ) V_14 -> V_34 ; V_19 ++ ) {
free ( V_14 -> V_28 [ V_19 ] . V_35 ) ;
free ( V_14 -> V_28 [ V_19 ] . V_36 ) ;
}
free ( V_14 -> V_28 ) ;
}
while ( V_33 ) {
V_380 = V_33 -> V_22 ;
free ( V_33 -> V_35 ) ;
free ( V_33 -> V_36 ) ;
free ( V_33 ) ;
V_33 = V_380 ;
}
while ( V_14 -> V_178 ) {
V_382 = V_14 -> V_178 ;
V_14 -> V_178 = V_382 -> V_22 ;
F_90 ( V_382 ) ;
}
if ( V_14 -> V_40 ) {
for ( V_19 = 0 ; V_19 < ( int ) V_14 -> V_45 ; V_19 ++ )
free ( V_14 -> V_40 [ V_19 ] . V_46 ) ;
free ( V_14 -> V_40 ) ;
}
while ( V_44 ) {
V_381 = V_44 -> V_22 ;
free ( V_44 -> V_46 ) ;
free ( V_44 ) ;
V_44 = V_381 ;
}
for ( V_19 = 0 ; V_19 < V_14 -> V_52 ; V_19 ++ )
F_172 ( V_14 -> V_51 [ V_19 ] ) ;
while ( V_14 -> V_349 ) {
V_348 = V_14 -> V_349 ;
V_14 -> V_349 = V_348 -> V_22 ;
F_166 ( V_348 ) ;
}
free ( V_14 -> V_27 ) ;
free ( V_14 -> V_51 ) ;
free ( V_14 -> V_329 ) ;
free ( V_14 ) ;
}
void F_197 ( struct V_14 * V_14 )
{
F_196 ( V_14 ) ;
}
