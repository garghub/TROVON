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
struct V_7 * V_8 ;
V_8 = F_7 ( sizeof( * V_8 ) ) ;
if ( ! V_8 )
return NULL ;
memset ( V_8 , 0 , sizeof( * V_8 ) ) ;
return V_8 ;
}
static int F_8 ( const void * V_9 , const void * V_10 )
{
const struct V_11 * V_12 = V_9 ;
const struct V_11 * V_13 = V_10 ;
if ( V_12 -> V_14 < V_13 -> V_14 )
return - 1 ;
if ( V_12 -> V_14 > V_13 -> V_14 )
return 1 ;
return 0 ;
}
static int F_9 ( struct V_15 * V_15 )
{
struct V_16 * V_17 = V_15 -> V_17 ;
struct V_16 * V_18 ;
struct V_11 * V_19 ;
int V_20 ;
V_19 = F_7 ( sizeof( * V_19 ) * V_15 -> V_21 ) ;
V_20 = 0 ;
while ( V_17 ) {
V_19 [ V_20 ] . V_14 = V_17 -> V_14 ;
V_19 [ V_20 ] . V_22 = V_17 -> V_22 ;
V_20 ++ ;
V_18 = V_17 ;
V_17 = V_17 -> V_23 ;
free ( V_18 ) ;
}
qsort ( V_19 , V_15 -> V_21 , sizeof( * V_19 ) , F_8 ) ;
V_15 -> V_19 = V_19 ;
V_15 -> V_17 = NULL ;
return 0 ;
}
static char * F_10 ( struct V_15 * V_15 , int V_14 )
{
const struct V_11 * V_22 ;
struct V_11 V_24 ;
if ( ! V_14 )
return L_1 ;
if ( ! V_15 -> V_19 )
F_9 ( V_15 ) ;
V_24 . V_14 = V_14 ;
V_22 = bsearch ( & V_24 , V_15 -> V_19 , V_15 -> V_21 ,
sizeof( * V_15 -> V_19 ) , F_8 ) ;
if ( V_22 )
return V_22 -> V_22 ;
return L_2 ;
}
int F_11 ( struct V_15 * V_15 , int V_14 )
{
const struct V_11 * V_22 ;
struct V_11 V_24 ;
if ( ! V_14 )
return 1 ;
if ( ! V_15 -> V_19 )
F_9 ( V_15 ) ;
V_24 . V_14 = V_14 ;
V_22 = bsearch ( & V_24 , V_15 -> V_19 , V_15 -> V_21 ,
sizeof( * V_15 -> V_19 ) , F_8 ) ;
if ( V_22 )
return 1 ;
return 0 ;
}
static int F_12 ( struct V_15 * V_15 , const char * V_22 , int V_14 )
{
struct V_11 * V_19 = V_15 -> V_19 ;
const struct V_11 * V_11 ;
struct V_11 V_24 ;
if ( ! V_14 )
return 0 ;
V_24 . V_14 = V_14 ;
V_11 = bsearch ( & V_24 , V_15 -> V_19 , V_15 -> V_21 ,
sizeof( * V_15 -> V_19 ) , F_8 ) ;
if ( V_11 ) {
V_25 = V_26 ;
return - 1 ;
}
V_19 = realloc ( V_19 , sizeof( * V_19 ) * ( V_15 -> V_21 + 1 ) ) ;
if ( ! V_19 ) {
V_25 = V_27 ;
return - 1 ;
}
V_19 [ V_15 -> V_21 ] . V_14 = V_14 ;
V_19 [ V_15 -> V_21 ] . V_22 = F_13 ( V_22 ) ;
if ( ! V_19 [ V_15 -> V_21 ] . V_22 )
F_14 ( L_3 ) ;
if ( V_19 [ V_15 -> V_21 ] . V_22 )
V_15 -> V_21 ++ ;
qsort ( V_19 , V_15 -> V_21 , sizeof( * V_19 ) , F_8 ) ;
V_15 -> V_19 = V_19 ;
return 0 ;
}
int F_15 ( struct V_15 * V_15 , const char * V_22 , int V_14 )
{
struct V_16 * V_18 ;
if ( V_15 -> V_19 )
return F_12 ( V_15 , V_22 , V_14 ) ;
V_18 = F_7 ( sizeof( * V_18 ) ) ;
V_18 -> V_22 = F_13 ( V_22 ) ;
if ( ! V_18 -> V_22 )
F_14 ( L_3 ) ;
V_18 -> V_14 = V_14 ;
V_18 -> V_23 = V_15 -> V_17 ;
V_15 -> V_17 = V_18 ;
V_15 -> V_21 ++ ;
return 0 ;
}
static int F_16 ( const void * V_9 , const void * V_10 )
{
const struct V_28 * V_29 = V_9 ;
const struct V_28 * V_30 = V_10 ;
if ( V_29 -> V_31 < V_30 -> V_31 )
return - 1 ;
if ( V_29 -> V_31 > V_30 -> V_31 )
return 1 ;
return 0 ;
}
static int F_17 ( const void * V_9 , const void * V_10 )
{
const struct V_28 * V_29 = V_9 ;
const struct V_28 * V_30 = V_10 ;
if ( ( V_29 -> V_31 == V_30 -> V_31 ) ||
( V_29 -> V_31 > V_30 -> V_31 &&
V_29 -> V_31 < ( V_30 + 1 ) -> V_31 ) )
return 0 ;
if ( V_29 -> V_31 < V_30 -> V_31 )
return - 1 ;
return 1 ;
}
static int F_18 ( struct V_15 * V_15 )
{
struct V_32 * V_33 ;
struct V_32 * V_18 ;
struct V_28 * V_28 ;
int V_20 ;
V_28 = F_7 ( sizeof( * V_28 ) * ( V_15 -> V_34 + 1 ) ) ;
V_33 = V_15 -> V_33 ;
V_20 = 0 ;
while ( V_33 ) {
V_28 [ V_20 ] . V_35 = V_33 -> V_35 ;
V_28 [ V_20 ] . V_31 = V_33 -> V_31 ;
V_28 [ V_20 ] . V_36 = V_33 -> V_36 ;
V_20 ++ ;
V_18 = V_33 ;
V_33 = V_33 -> V_23 ;
free ( V_18 ) ;
}
qsort ( V_28 , V_15 -> V_34 , sizeof( * V_28 ) , F_16 ) ;
V_28 [ V_15 -> V_34 ] . V_35 = NULL ;
V_28 [ V_15 -> V_34 ] . V_31 = 0 ;
V_28 [ V_15 -> V_34 ] . V_36 = NULL ;
V_15 -> V_28 = V_28 ;
V_15 -> V_33 = NULL ;
return 0 ;
}
static struct V_28 *
F_19 ( struct V_15 * V_15 , unsigned long long V_31 )
{
struct V_28 * V_35 ;
struct V_28 V_24 ;
if ( ! V_15 -> V_28 )
F_18 ( V_15 ) ;
V_24 . V_31 = V_31 ;
V_35 = bsearch ( & V_24 , V_15 -> V_28 , V_15 -> V_34 ,
sizeof( * V_15 -> V_28 ) , F_17 ) ;
return V_35 ;
}
const char * F_20 ( struct V_15 * V_15 , unsigned long long V_31 )
{
struct V_28 * V_37 ;
V_37 = F_19 ( V_15 , V_31 ) ;
if ( ! V_37 )
return NULL ;
return V_37 -> V_35 ;
}
unsigned long long
F_21 ( struct V_15 * V_15 , unsigned long long V_31 )
{
struct V_28 * V_37 ;
V_37 = F_19 ( V_15 , V_31 ) ;
if ( ! V_37 )
return 0 ;
return V_37 -> V_31 ;
}
int F_22 ( struct V_15 * V_15 , char * V_35 ,
unsigned long long V_31 , char * V_36 )
{
struct V_32 * V_18 ;
V_18 = F_7 ( sizeof( * V_18 ) ) ;
V_18 -> V_23 = V_15 -> V_33 ;
V_18 -> V_35 = F_13 ( V_35 ) ;
if ( V_36 )
V_18 -> V_36 = F_13 ( V_36 ) ;
else
V_18 -> V_36 = NULL ;
V_18 -> V_31 = V_31 ;
if ( ! V_18 -> V_35 || ( V_36 && ! V_18 -> V_36 ) )
F_14 ( L_4 ) ;
V_15 -> V_33 = V_18 ;
V_15 -> V_34 ++ ;
return 0 ;
}
void F_23 ( struct V_15 * V_15 )
{
int V_20 ;
if ( ! V_15 -> V_28 )
F_18 ( V_15 ) ;
for ( V_20 = 0 ; V_20 < ( int ) V_15 -> V_34 ; V_20 ++ ) {
printf ( L_5 ,
V_15 -> V_28 [ V_20 ] . V_31 ,
V_15 -> V_28 [ V_20 ] . V_35 ) ;
if ( V_15 -> V_28 [ V_20 ] . V_36 )
printf ( L_6 , V_15 -> V_28 [ V_20 ] . V_36 ) ;
else
printf ( L_7 ) ;
}
}
static int F_24 ( const void * V_9 , const void * V_10 )
{
const struct V_38 * V_39 = V_9 ;
const struct V_38 * V_40 = V_10 ;
if ( V_39 -> V_31 < V_40 -> V_31 )
return - 1 ;
if ( V_39 -> V_31 > V_40 -> V_31 )
return 1 ;
return 0 ;
}
static void F_25 ( struct V_15 * V_15 )
{
struct V_41 * V_42 ;
struct V_41 * V_18 ;
struct V_38 * V_38 ;
int V_20 ;
V_38 = F_7 ( sizeof( * V_38 ) * ( V_15 -> V_43 + 1 ) ) ;
V_42 = V_15 -> V_42 ;
V_20 = 0 ;
while ( V_42 ) {
V_38 [ V_20 ] . V_44 = V_42 -> V_44 ;
V_38 [ V_20 ] . V_31 = V_42 -> V_31 ;
V_20 ++ ;
V_18 = V_42 ;
V_42 = V_42 -> V_23 ;
free ( V_18 ) ;
}
qsort ( V_38 , V_15 -> V_43 , sizeof( * V_38 ) , F_24 ) ;
V_15 -> V_38 = V_38 ;
V_15 -> V_42 = NULL ;
}
static struct V_38 *
F_26 ( struct V_15 * V_15 , unsigned long long V_31 )
{
struct V_38 * V_44 ;
struct V_38 V_24 ;
if ( ! V_15 -> V_38 )
F_25 ( V_15 ) ;
V_24 . V_31 = V_31 ;
V_44 = bsearch ( & V_24 , V_15 -> V_38 , V_15 -> V_43 ,
sizeof( * V_15 -> V_38 ) , F_24 ) ;
return V_44 ;
}
int F_27 ( struct V_15 * V_15 , char * V_45 ,
unsigned long long V_31 )
{
struct V_41 * V_18 ;
V_18 = F_7 ( sizeof( * V_18 ) ) ;
V_18 -> V_23 = V_15 -> V_42 ;
V_18 -> V_44 = F_13 ( V_45 ) ;
V_18 -> V_31 = V_31 ;
if ( ! V_18 -> V_44 )
F_14 ( L_8 ) ;
V_15 -> V_42 = V_18 ;
V_15 -> V_43 ++ ;
return 0 ;
}
void F_28 ( struct V_15 * V_15 )
{
int V_20 ;
if ( ! V_15 -> V_38 )
F_25 ( V_15 ) ;
for ( V_20 = 0 ; V_20 < ( int ) V_15 -> V_43 ; V_20 ++ ) {
printf ( L_9 ,
V_15 -> V_38 [ V_20 ] . V_31 ,
V_15 -> V_38 [ V_20 ] . V_44 ) ;
}
}
static struct V_46 * F_29 ( void )
{
struct V_46 * V_47 ;
V_47 = malloc ( sizeof( * V_47 ) ) ;
if ( ! V_47 )
return NULL ;
memset ( V_47 , 0 , sizeof( * V_47 ) ) ;
return V_47 ;
}
static void F_30 ( struct V_15 * V_15 , struct V_46 * V_47 )
{
int V_20 ;
V_15 -> V_48 = realloc ( V_15 -> V_48 , sizeof( V_47 ) *
( V_15 -> V_49 + 1 ) ) ;
if ( ! V_15 -> V_48 )
F_14 ( L_10 ) ;
for ( V_20 = 0 ; V_20 < V_15 -> V_49 ; V_20 ++ ) {
if ( V_15 -> V_48 [ V_20 ] -> V_50 > V_47 -> V_50 )
break;
}
if ( V_20 < V_15 -> V_49 )
memmove ( & V_15 -> V_48 [ V_20 + 1 ] ,
& V_15 -> V_48 [ V_20 ] ,
sizeof( V_47 ) * ( V_15 -> V_49 - V_20 ) ) ;
V_15 -> V_48 [ V_20 ] = V_47 ;
V_15 -> V_49 ++ ;
V_47 -> V_15 = V_15 ;
}
static int F_31 ( enum V_51 type )
{
switch ( type ) {
case V_52 ... V_53 :
return 1 ;
case V_54 ... V_55 :
default:
return 0 ;
}
}
static void F_32 ( struct V_56 * V_57 )
{
struct V_56 * V_23 ;
while ( V_57 ) {
V_23 = V_57 -> V_23 ;
free ( V_57 -> V_58 ) ;
free ( V_57 -> V_59 ) ;
free ( V_57 ) ;
V_57 = V_23 ;
}
}
static void F_33 ( struct V_7 * V_8 )
{
struct V_7 * V_60 ;
if ( ! V_8 )
return;
switch ( V_8 -> type ) {
case V_61 :
free ( V_8 -> V_62 . V_62 ) ;
break;
case V_63 :
free ( V_8 -> V_64 . V_65 ) ;
break;
case V_66 :
F_33 ( V_8 -> V_67 . V_64 ) ;
free ( V_8 -> V_67 . V_68 ) ;
F_32 ( V_8 -> V_67 . V_67 ) ;
break;
case V_69 :
F_33 ( V_8 -> V_70 . V_64 ) ;
F_32 ( V_8 -> V_70 . V_71 ) ;
break;
case V_72 :
F_33 ( V_8 -> V_73 . V_64 ) ;
F_33 ( V_8 -> V_73 . V_2 ) ;
break;
case V_74 :
free ( V_8 -> V_75 . type ) ;
F_33 ( V_8 -> V_75 . V_18 ) ;
break;
case V_76 :
case V_77 :
free ( V_8 -> string . string ) ;
break;
case V_78 :
free ( V_8 -> V_79 . V_80 ) ;
break;
case V_81 :
free ( V_8 -> V_82 . V_82 ) ;
F_33 ( V_8 -> V_82 . V_83 ) ;
F_33 ( V_8 -> V_82 . V_84 ) ;
break;
case V_85 :
while ( V_8 -> V_35 . args ) {
V_60 = V_8 -> V_35 . args ;
V_8 -> V_35 . args = V_60 -> V_23 ;
F_33 ( V_60 ) ;
}
break;
case V_86 :
default:
break;
}
free ( V_8 ) ;
}
static enum V_51 F_34 ( int V_87 )
{
if ( V_87 == '\n' )
return V_88 ;
if ( isspace ( V_87 ) )
return V_89 ;
if ( isalnum ( V_87 ) || V_87 == '_' )
return V_52 ;
if ( V_87 == '\'' )
return V_53 ;
if ( V_87 == '"' )
return V_90 ;
if ( ! isprint ( V_87 ) )
return V_91 ;
if ( V_87 == '(' || V_87 == ')' || V_87 == ',' )
return V_55 ;
return V_92 ;
}
static int F_35 ( void )
{
if ( V_5 >= V_4 )
return - 1 ;
return V_3 [ V_5 ++ ] ;
}
static int F_36 ( void )
{
if ( V_5 >= V_4 )
return - 1 ;
return V_3 [ V_5 ] ;
}
int F_37 ( void )
{
return F_36 () ;
}
static int F_38 ( char * * V_93 , char * V_1 , int V_2 )
{
char * V_94 = realloc ( * V_93 , V_2 ) ;
if ( ! V_94 ) {
free ( * V_93 ) ;
* V_93 = NULL ;
return - 1 ;
}
if ( ! * V_93 )
strcpy ( V_94 , V_1 ) ;
else
strcat ( V_94 , V_1 ) ;
* V_93 = V_94 ;
return 0 ;
}
static enum V_51 F_39 ( char * * V_93 )
{
char V_1 [ V_95 ] ;
int V_87 , V_96 , V_97 , V_98 ;
int V_20 = 0 ;
int V_99 = 0 ;
enum V_51 type ;
* V_93 = NULL ;
V_87 = F_35 () ;
if ( V_87 < 0 )
return V_91 ;
type = F_34 ( V_87 ) ;
if ( type == V_91 )
return type ;
V_1 [ V_20 ++ ] = V_87 ;
switch ( type ) {
case V_88 :
case V_55 :
* V_93 = F_7 ( 2 ) ;
( * V_93 ) [ 0 ] = V_87 ;
( * V_93 ) [ 1 ] = 0 ;
return type ;
case V_92 :
switch ( V_87 ) {
case '-' :
V_98 = F_36 () ;
if ( V_98 == '>' ) {
V_1 [ V_20 ++ ] = F_35 () ;
break;
}
case '+' :
case '|' :
case '&' :
case '>' :
case '<' :
V_96 = V_87 ;
V_87 = F_36 () ;
if ( V_87 != V_96 )
goto V_100;
V_1 [ V_20 ++ ] = F_35 () ;
switch ( V_96 ) {
case '>' :
case '<' :
goto V_100;
default:
break;
}
break;
case '!' :
case '=' :
goto V_100;
default:
break;
}
V_1 [ V_20 ] = 0 ;
* V_93 = F_13 ( V_1 ) ;
return type ;
V_100:
V_87 = F_36 () ;
if ( V_87 == '=' )
V_1 [ V_20 ++ ] = F_35 () ;
goto V_101;
case V_90 :
case V_53 :
V_20 -- ;
V_97 = V_87 ;
V_96 = 0 ;
V_102:
do {
if ( V_20 == ( V_95 - 1 ) ) {
V_1 [ V_20 ] = 0 ;
V_99 += V_95 ;
if ( F_38 ( V_93 , V_1 , V_99 ) < 0 )
return V_91 ;
V_20 = 0 ;
}
V_96 = V_87 ;
V_87 = F_35 () ;
V_1 [ V_20 ++ ] = V_87 ;
if ( V_87 == '\\' && V_96 == '\\' )
V_96 = 0 ;
} while ( V_87 != V_97 || V_96 == '\\' );
V_20 -- ;
if ( type == V_90 ) {
unsigned long long V_103 = V_5 ;
do {
V_87 = F_35 () ;
} while ( isspace ( V_87 ) );
if ( V_87 == '"' )
goto V_102;
V_5 = V_103 ;
}
goto V_101;
case V_54 ... V_89 :
case V_52 :
default:
break;
}
while ( F_34 ( F_36 () ) == type ) {
if ( V_20 == ( V_95 - 1 ) ) {
V_1 [ V_20 ] = 0 ;
V_99 += V_95 ;
if ( F_38 ( V_93 , V_1 , V_99 ) < 0 )
return V_91 ;
V_20 = 0 ;
}
V_87 = F_35 () ;
V_1 [ V_20 ++ ] = V_87 ;
}
V_101:
V_1 [ V_20 ] = 0 ;
if ( F_38 ( V_93 , V_1 , V_99 + V_20 + 1 ) < 0 )
return V_91 ;
if ( type == V_52 ) {
if ( strcmp ( * V_93 , L_11 ) == 0 ) {
free ( * V_93 ) ;
* V_93 = NULL ;
return F_40 ( L_12 , V_93 ) ;
} else if ( strcmp ( * V_93 , L_13 ) == 0 ) {
free ( * V_93 ) ;
* V_93 = NULL ;
return F_40 ( L_14 , V_93 ) ;
} else if ( strcmp ( * V_93 , L_15 ) == 0 ) {
free ( * V_93 ) ;
* V_93 = NULL ;
return F_40 ( L_16 , V_93 ) ;
}
}
return type ;
}
static enum V_51 F_40 ( const char * V_59 , char * * V_93 )
{
const char * V_104 ;
unsigned long long V_103 ;
unsigned long long V_105 ;
enum V_51 type ;
V_104 = V_3 ;
V_103 = V_5 ;
V_105 = V_4 ;
F_1 ( V_59 , strlen ( V_59 ) ) ;
type = F_39 ( V_93 ) ;
V_3 = V_104 ;
V_5 = V_103 ;
V_4 = V_105 ;
return type ;
}
static void F_41 ( char * V_93 )
{
if ( V_93 )
free ( V_93 ) ;
}
static enum V_51 F_42 ( char * * V_93 )
{
enum V_51 type ;
for (; ; ) {
type = F_39 ( V_93 ) ;
if ( type != V_89 )
return type ;
F_41 ( * V_93 ) ;
}
* V_93 = NULL ;
return V_91 ;
}
enum V_51 F_43 ( char * * V_93 )
{
return F_42 ( V_93 ) ;
}
void F_44 ( char * V_106 )
{
F_41 ( V_106 ) ;
}
static enum V_51 F_45 ( char * * V_93 )
{
enum V_51 type ;
for (; ; ) {
type = F_39 ( V_93 ) ;
if ( type != V_89 && type != V_88 )
return type ;
F_41 ( * V_93 ) ;
* V_93 = NULL ;
}
* V_93 = NULL ;
return V_91 ;
}
static int F_46 ( enum V_51 type , enum V_51 V_107 )
{
if ( type != V_107 ) {
F_47 ( L_17 ,
V_107 , type ) ;
return - 1 ;
}
return 0 ;
}
static int F_48 ( enum V_51 type , const char * V_106 ,
enum V_51 V_107 , const char * V_108 )
{
if ( type != V_107 ) {
F_47 ( L_17 ,
V_107 , type ) ;
return - 1 ;
}
if ( strcmp ( V_106 , V_108 ) != 0 ) {
F_47 ( L_18 ,
V_108 , V_106 ) ;
return - 1 ;
}
return 0 ;
}
static int F_49 ( enum V_51 V_107 , char * * V_93 , int V_109 )
{
enum V_51 type ;
if ( V_109 )
type = F_42 ( V_93 ) ;
else
type = F_45 ( V_93 ) ;
return F_46 ( type , V_107 ) ;
}
static int F_50 ( enum V_51 V_107 , char * * V_93 )
{
return F_49 ( V_107 , V_93 , 1 ) ;
}
static int F_51 ( enum V_51 V_107 , const char * V_59 ,
int V_109 )
{
enum V_51 type ;
char * V_106 ;
int V_110 ;
if ( V_109 )
type = F_42 ( & V_106 ) ;
else
type = F_45 ( & V_106 ) ;
V_110 = F_48 ( type , V_106 , V_107 , V_59 ) ;
F_41 ( V_106 ) ;
return V_110 ;
}
static int F_52 ( enum V_51 V_107 , const char * V_59 )
{
return F_51 ( V_107 , V_59 , 1 ) ;
}
static int F_53 ( enum V_51 V_107 , const char * V_59 )
{
return F_51 ( V_107 , V_59 , 0 ) ;
}
static char * F_54 ( void )
{
char * V_106 ;
if ( F_52 ( V_52 , L_19 ) < 0 )
return NULL ;
if ( F_52 ( V_92 , L_20 ) < 0 )
return NULL ;
if ( F_50 ( V_52 , & V_106 ) < 0 )
goto V_111;
return V_106 ;
V_111:
F_41 ( V_106 ) ;
return NULL ;
}
static int F_55 ( void )
{
char * V_106 ;
int V_50 ;
if ( F_53 ( V_52 , L_21 ) < 0 )
return - 1 ;
if ( F_52 ( V_92 , L_20 ) < 0 )
return - 1 ;
if ( F_50 ( V_52 , & V_106 ) < 0 )
goto V_111;
V_50 = strtoul ( V_106 , NULL , 0 ) ;
F_41 ( V_106 ) ;
return V_50 ;
V_111:
F_41 ( V_106 ) ;
return - 1 ;
}
static int F_56 ( struct V_112 * V_64 )
{
if ( ( V_64 -> V_67 & V_113 ) &&
( strstr ( V_64 -> type , L_22 ) || strstr ( V_64 -> type , L_23 ) ||
strstr ( V_64 -> type , L_24 ) ) )
return 1 ;
return 0 ;
}
static int F_57 ( struct V_112 * V_64 )
{
if ( strncmp ( V_64 -> type , L_25 , 10 ) == 0 )
return 1 ;
return 0 ;
}
static int F_58 ( struct V_112 * V_64 )
{
if ( strstr ( V_64 -> type , L_26 ) )
return 1 ;
return 0 ;
}
static int F_59 ( struct V_46 * V_47 , struct V_112 * * V_114 )
{
struct V_112 * V_64 = NULL ;
enum V_51 type ;
char * V_106 ;
char * V_115 ;
int V_116 = 0 ;
do {
type = F_42 ( & V_106 ) ;
if ( type == V_88 ) {
F_41 ( V_106 ) ;
return V_116 ;
}
V_116 ++ ;
if ( F_48 ( type , V_106 , V_52 , L_27 ) )
goto V_111;
F_41 ( V_106 ) ;
type = F_42 ( & V_106 ) ;
if ( V_47 -> V_67 & V_117 &&
type == V_52 && strcmp ( V_106 , L_28 ) == 0 ) {
F_41 ( V_106 ) ;
type = F_42 ( & V_106 ) ;
}
if ( F_48 ( type , V_106 , V_92 , L_20 ) < 0 )
goto V_111;
F_41 ( V_106 ) ;
if ( F_50 ( V_52 , & V_106 ) < 0 )
goto V_111;
V_115 = V_106 ;
V_64 = F_7 ( sizeof( * V_64 ) ) ;
memset ( V_64 , 0 , sizeof( * V_64 ) ) ;
V_64 -> V_47 = V_47 ;
for (; ; ) {
type = F_42 ( & V_106 ) ;
if ( type == V_52 ||
( type == V_92 && strcmp ( V_106 , L_29 ) == 0 ) ||
( V_47 -> V_67 & V_117 &&
type == V_92 && strcmp ( V_106 , L_30 ) == 0 ) ) {
if ( strcmp ( V_106 , L_29 ) == 0 )
V_64 -> V_67 |= V_118 ;
if ( V_64 -> type ) {
char * V_119 ;
V_119 = realloc ( V_64 -> type ,
strlen ( V_64 -> type ) +
strlen ( V_115 ) + 2 ) ;
if ( ! V_119 ) {
free ( V_115 ) ;
goto V_111;
}
V_64 -> type = V_119 ;
strcat ( V_64 -> type , L_31 ) ;
strcat ( V_64 -> type , V_115 ) ;
free ( V_115 ) ;
} else
V_64 -> type = V_115 ;
V_115 = V_106 ;
continue;
}
break;
}
if ( ! V_64 -> type ) {
F_14 ( L_32 ) ;
goto V_111;
}
V_64 -> V_65 = V_115 ;
if ( F_46 ( type , V_92 ) )
goto V_111;
if ( strcmp ( V_106 , L_33 ) == 0 ) {
enum V_51 V_120 = type ;
char * V_121 = V_106 ;
char * V_122 ;
int V_123 ;
V_64 -> V_67 |= V_113 ;
type = F_42 ( & V_106 ) ;
if ( type == V_52 )
V_64 -> V_124 = strtoul ( V_106 , NULL , 0 ) ;
else
V_64 -> V_124 = 0 ;
while ( strcmp ( V_106 , L_34 ) != 0 ) {
if ( V_120 == V_52 &&
type == V_52 )
V_123 = 2 ;
else
V_123 = 1 ;
V_120 = type ;
V_122 = realloc ( V_121 ,
strlen ( V_121 ) +
strlen ( V_106 ) + V_123 ) ;
if ( ! V_122 ) {
free ( V_121 ) ;
goto V_111;
}
V_121 = V_122 ;
if ( V_123 == 2 )
strcat ( V_121 , L_31 ) ;
strcat ( V_121 , V_106 ) ;
V_64 -> V_124 = strtoul ( V_106 , NULL , 0 ) ;
F_41 ( V_106 ) ;
type = F_42 ( & V_106 ) ;
if ( type == V_91 ) {
F_14 ( L_35 ) ;
goto V_111;
}
}
F_41 ( V_106 ) ;
V_122 = realloc ( V_121 , strlen ( V_121 ) + 2 ) ;
if ( ! V_122 ) {
free ( V_121 ) ;
goto V_111;
}
V_121 = V_122 ;
strcat ( V_121 , L_34 ) ;
type = F_42 ( & V_106 ) ;
if ( type == V_52 ) {
char * V_119 ;
V_119 = realloc ( V_64 -> type ,
strlen ( V_64 -> type ) +
strlen ( V_64 -> V_65 ) +
strlen ( V_121 ) + 2 ) ;
if ( ! V_119 ) {
free ( V_121 ) ;
goto V_111;
}
V_64 -> type = V_119 ;
strcat ( V_64 -> type , L_31 ) ;
strcat ( V_64 -> type , V_64 -> V_65 ) ;
F_41 ( V_64 -> V_65 ) ;
strcat ( V_64 -> type , V_121 ) ;
V_64 -> V_65 = V_106 ;
type = F_42 ( & V_106 ) ;
} else {
char * V_119 ;
V_119 = realloc ( V_64 -> type ,
strlen ( V_64 -> type ) +
strlen ( V_121 ) + 1 ) ;
if ( ! V_119 ) {
free ( V_121 ) ;
goto V_111;
}
V_64 -> type = V_119 ;
strcat ( V_64 -> type , V_121 ) ;
}
free ( V_121 ) ;
}
if ( F_56 ( V_64 ) )
V_64 -> V_67 |= V_125 ;
if ( F_57 ( V_64 ) )
V_64 -> V_67 |= V_126 ;
if ( F_58 ( V_64 ) )
V_64 -> V_67 |= V_127 ;
if ( F_48 ( type , V_106 , V_92 , L_36 ) )
goto V_111;
F_41 ( V_106 ) ;
if ( F_52 ( V_52 , L_37 ) < 0 )
goto V_128;
if ( F_52 ( V_92 , L_20 ) < 0 )
goto V_128;
if ( F_50 ( V_52 , & V_106 ) )
goto V_111;
V_64 -> V_129 = strtoul ( V_106 , NULL , 0 ) ;
F_41 ( V_106 ) ;
if ( F_52 ( V_92 , L_36 ) < 0 )
goto V_128;
if ( F_52 ( V_52 , L_38 ) < 0 )
goto V_128;
if ( F_52 ( V_92 , L_20 ) < 0 )
goto V_128;
if ( F_50 ( V_52 , & V_106 ) )
goto V_111;
V_64 -> V_2 = strtoul ( V_106 , NULL , 0 ) ;
F_41 ( V_106 ) ;
if ( F_52 ( V_92 , L_36 ) < 0 )
goto V_128;
type = F_42 ( & V_106 ) ;
if ( type != V_88 ) {
if ( F_48 ( type , V_106 , V_52 , L_39 ) )
goto V_111;
F_41 ( V_106 ) ;
if ( F_52 ( V_92 , L_20 ) < 0 )
goto V_128;
if ( F_50 ( V_52 , & V_106 ) )
goto V_111;
F_41 ( V_106 ) ;
if ( F_52 ( V_92 , L_36 ) < 0 )
goto V_128;
if ( F_50 ( V_88 , & V_106 ) )
goto V_111;
}
F_41 ( V_106 ) ;
if ( V_64 -> V_67 & V_113 ) {
if ( V_64 -> V_124 )
V_64 -> V_130 = V_64 -> V_2 / V_64 -> V_124 ;
else if ( V_64 -> V_67 & V_125 )
V_64 -> V_130 = 1 ;
else
V_64 -> V_130 = V_47 -> V_15 -> V_131 ;
} else
V_64 -> V_130 = V_64 -> V_2 ;
* V_114 = V_64 ;
V_114 = & V_64 -> V_23 ;
} while ( 1 );
return 0 ;
V_111:
F_41 ( V_106 ) ;
V_128:
if ( V_64 ) {
free ( V_64 -> type ) ;
free ( V_64 -> V_65 ) ;
free ( V_64 ) ;
}
return - 1 ;
}
static int F_60 ( struct V_46 * V_47 )
{
char * V_106 ;
int V_110 ;
if ( F_53 ( V_52 , L_40 ) < 0 )
return - 1 ;
if ( F_52 ( V_92 , L_20 ) < 0 )
return - 1 ;
if ( F_50 ( V_88 , & V_106 ) )
goto V_111;
F_41 ( V_106 ) ;
V_110 = F_59 ( V_47 , & V_47 -> V_132 . V_133 ) ;
if ( V_110 < 0 )
return V_110 ;
V_47 -> V_132 . V_134 = V_110 ;
V_110 = F_59 ( V_47 , & V_47 -> V_132 . V_114 ) ;
if ( V_110 < 0 )
return V_110 ;
V_47 -> V_132 . V_135 = V_110 ;
return 0 ;
V_111:
F_41 ( V_106 ) ;
return - 1 ;
}
static enum V_51
F_61 ( struct V_46 * V_47 , struct V_7 * V_8 , char * * V_93 )
{
enum V_51 type ;
char * V_106 ;
type = F_42 ( & V_106 ) ;
* V_93 = V_106 ;
return F_62 ( V_47 , V_8 , V_93 , type ) ;
}
static enum V_51
F_63 ( struct V_46 * V_47 , struct V_7 * V_136 , char * * V_93 )
{
struct V_7 * V_8 , * V_83 , * V_84 ;
enum V_51 type ;
char * V_106 = NULL ;
V_8 = F_6 () ;
V_83 = F_6 () ;
V_84 = F_6 () ;
V_8 -> type = V_81 ;
V_8 -> V_82 . V_83 = V_83 ;
V_8 -> V_82 . V_84 = V_84 ;
* V_93 = NULL ;
type = F_61 ( V_47 , V_83 , & V_106 ) ;
V_137:
if ( type == V_92 && strcmp ( V_106 , L_20 ) != 0 ) {
type = F_64 ( V_47 , V_83 , & V_106 ) ;
goto V_137;
}
if ( F_48 ( type , V_106 , V_92 , L_20 ) )
goto V_138;
V_8 -> V_82 . V_82 = V_106 ;
type = F_61 ( V_47 , V_84 , & V_106 ) ;
V_136 -> V_82 . V_84 = V_8 ;
* V_93 = V_106 ;
return type ;
V_138:
V_136 -> V_82 . V_84 = NULL ;
F_41 ( V_106 ) ;
F_33 ( V_8 ) ;
return V_54 ;
}
static enum V_51
F_65 ( struct V_46 * V_47 , struct V_7 * V_136 , char * * V_93 )
{
struct V_7 * V_8 ;
enum V_51 type ;
char * V_106 = NULL ;
V_8 = F_6 () ;
* V_93 = NULL ;
type = F_61 ( V_47 , V_8 , & V_106 ) ;
if ( F_48 ( type , V_106 , V_92 , L_34 ) )
goto V_138;
V_136 -> V_82 . V_84 = V_8 ;
F_41 ( V_106 ) ;
type = F_45 ( & V_106 ) ;
* V_93 = V_106 ;
return type ;
V_138:
F_41 ( * V_93 ) ;
* V_93 = NULL ;
F_33 ( V_8 ) ;
return V_54 ;
}
static int F_66 ( char * V_82 )
{
if ( ! V_82 [ 1 ] ) {
switch ( V_82 [ 0 ] ) {
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
F_47 ( L_41 , V_82 [ 0 ] ) ;
return - 1 ;
}
} else {
if ( strcmp ( V_82 , L_42 ) == 0 ||
strcmp ( V_82 , L_43 ) == 0 ) {
return 3 ;
} else if ( strcmp ( V_82 , L_44 ) == 0 ||
strcmp ( V_82 , L_45 ) == 0 ) {
return 8 ;
} else if ( strcmp ( V_82 , L_46 ) == 0 ||
strcmp ( V_82 , L_47 ) == 0 ) {
return 9 ;
} else if ( strcmp ( V_82 , L_48 ) == 0 ||
strcmp ( V_82 , L_49 ) == 0 ) {
return 10 ;
} else if ( strcmp ( V_82 , L_50 ) == 0 ) {
return 14 ;
} else if ( strcmp ( V_82 , L_51 ) == 0 ) {
return 15 ;
} else {
F_47 ( L_52 , V_82 ) ;
return - 1 ;
}
}
}
static int F_67 ( struct V_7 * V_8 )
{
if ( ! V_8 -> V_82 . V_83 || V_8 -> V_82 . V_83 -> type == V_86 )
V_8 -> V_82 . V_139 = 0 ;
else
V_8 -> V_82 . V_139 = F_66 ( V_8 -> V_82 . V_82 ) ;
return V_8 -> V_82 . V_139 ;
}
static enum V_51
F_64 ( struct V_46 * V_47 , struct V_7 * V_8 , char * * V_93 )
{
struct V_7 * V_83 , * V_84 = NULL ;
enum V_51 type ;
char * V_106 ;
V_106 = * V_93 ;
if ( V_8 -> type == V_81 && ! V_8 -> V_82 . V_83 ) {
if ( V_106 [ 1 ] ) {
F_14 ( L_53 , V_106 ) ;
goto V_138;
}
switch ( V_106 [ 0 ] ) {
case '~' :
case '!' :
case '+' :
case '-' :
break;
default:
F_47 ( L_53 , V_106 ) ;
goto V_138;
}
V_83 = F_6 () ;
V_83 -> type = V_86 ;
V_8 -> V_82 . V_83 = V_83 ;
V_84 = F_6 () ;
V_8 -> V_82 . V_84 = V_84 ;
* V_93 = NULL ;
type = F_61 ( V_47 , V_84 , V_93 ) ;
} else if ( strcmp ( V_106 , L_54 ) == 0 ) {
V_83 = F_6 () ;
* V_83 = * V_8 ;
V_8 -> type = V_81 ;
V_8 -> V_82 . V_82 = V_106 ;
V_8 -> V_82 . V_83 = V_83 ;
V_8 -> V_82 . V_139 = 0 ;
type = F_63 ( V_47 , V_8 , V_93 ) ;
} else if ( strcmp ( V_106 , L_44 ) == 0 ||
strcmp ( V_106 , L_45 ) == 0 ||
strcmp ( V_106 , L_55 ) == 0 ||
strcmp ( V_106 , L_56 ) == 0 ||
strcmp ( V_106 , L_50 ) == 0 ||
strcmp ( V_106 , L_51 ) == 0 ||
strcmp ( V_106 , L_57 ) == 0 ||
strcmp ( V_106 , L_58 ) == 0 ||
strcmp ( V_106 , L_29 ) == 0 ||
strcmp ( V_106 , L_59 ) == 0 ||
strcmp ( V_106 , L_60 ) == 0 ||
strcmp ( V_106 , L_61 ) == 0 ||
strcmp ( V_106 , L_62 ) == 0 ||
strcmp ( V_106 , L_48 ) == 0 ||
strcmp ( V_106 , L_49 ) == 0 ) {
V_83 = F_6 () ;
* V_83 = * V_8 ;
V_8 -> type = V_81 ;
V_8 -> V_82 . V_82 = V_106 ;
V_8 -> V_82 . V_83 = V_83 ;
if ( F_67 ( V_8 ) == - 1 ) {
V_47 -> V_67 |= V_140 ;
V_8 -> V_82 . V_82 = NULL ;
goto V_138;
}
type = F_45 ( & V_106 ) ;
* V_93 = V_106 ;
if ( ( strcmp ( V_8 -> V_82 . V_82 , L_29 ) == 0 ) &&
type == V_55 && ( strcmp ( V_106 , L_63 ) == 0 ) ) {
char * V_141 ;
if ( V_83 -> type != V_61 )
F_14 ( L_64 ) ;
V_141 = realloc ( V_83 -> V_62 . V_62 ,
strlen ( V_83 -> V_62 . V_62 ) + 3 ) ;
if ( ! V_141 )
goto V_138;
V_83 -> V_62 . V_62 = V_141 ;
strcat ( V_83 -> V_62 . V_62 , L_65 ) ;
free ( V_8 -> V_82 . V_82 ) ;
* V_8 = * V_83 ;
free ( V_83 ) ;
return type ;
}
V_84 = F_6 () ;
type = F_62 ( V_47 , V_84 , V_93 , type ) ;
V_8 -> V_82 . V_84 = V_84 ;
} else if ( strcmp ( V_106 , L_33 ) == 0 ) {
V_83 = F_6 () ;
* V_83 = * V_8 ;
V_8 -> type = V_81 ;
V_8 -> V_82 . V_82 = V_106 ;
V_8 -> V_82 . V_83 = V_83 ;
V_8 -> V_82 . V_139 = 0 ;
type = F_65 ( V_47 , V_8 , V_93 ) ;
} else {
F_47 ( L_52 , V_106 ) ;
V_47 -> V_67 |= V_140 ;
goto V_138;
}
if ( type == V_92 && strcmp ( * V_93 , L_20 ) != 0 ) {
int V_139 ;
V_139 = F_66 ( * V_93 ) ;
if ( V_139 > V_8 -> V_82 . V_139 )
return F_64 ( V_47 , V_8 , V_93 ) ;
return F_64 ( V_47 , V_84 , V_93 ) ;
}
return type ;
V_138:
F_41 ( V_106 ) ;
* V_93 = NULL ;
return V_54 ;
}
static enum V_51
F_68 ( struct V_46 * V_47 V_142 , struct V_7 * V_8 ,
char * * V_93 )
{
enum V_51 type ;
char * V_64 ;
char * V_106 ;
if ( F_52 ( V_92 , L_66 ) < 0 )
goto V_143;
if ( F_50 ( V_52 , & V_106 ) < 0 )
goto V_138;
V_64 = V_106 ;
V_8 -> type = V_63 ;
V_8 -> V_64 . V_65 = V_64 ;
if ( V_144 ) {
V_8 -> V_64 . V_64 = F_69 ( V_47 , V_8 -> V_64 . V_65 ) ;
V_8 -> V_64 . V_64 -> V_67 |= V_145 ;
V_144 = 0 ;
} else if ( V_146 ) {
V_8 -> V_64 . V_64 = F_69 ( V_47 , V_8 -> V_64 . V_65 ) ;
V_8 -> V_64 . V_64 -> V_67 |= V_147 ;
V_146 = 0 ;
}
type = F_42 ( & V_106 ) ;
* V_93 = V_106 ;
return type ;
V_138:
F_41 ( V_106 ) ;
V_143:
* V_93 = NULL ;
return V_54 ;
}
static unsigned long long
F_70 ( unsigned long long V_148 , const char * type , int V_149 )
{
int V_150 = 0 ;
char * V_151 ;
int V_123 ;
V_123 = strlen ( type ) ;
if ( V_149 ) {
if ( type [ V_123 - 1 ] != '*' ) {
F_47 ( L_67 ) ;
return V_148 ;
}
V_151 = F_7 ( V_123 ) ;
memcpy ( V_151 , type , V_123 ) ;
V_151 [ V_123 - 2 ] = 0 ;
V_148 = F_70 ( V_148 , V_151 , 0 ) ;
free ( V_151 ) ;
return V_148 ;
}
if ( type [ V_123 - 1 ] == '*' )
return V_148 ;
if ( strncmp ( type , L_68 , 6 ) == 0 )
return V_148 ;
if ( strcmp ( type , L_23 ) == 0 )
return V_148 & 0xff ;
if ( strcmp ( type , L_69 ) == 0 )
return V_148 & 0xffff ;
if ( strcmp ( type , L_70 ) == 0 )
return V_148 & 0xffffffff ;
if ( strcmp ( type , L_71 ) == 0 ||
strcmp ( type , L_72 ) )
return V_148 ;
if ( strcmp ( type , L_24 ) == 0 )
return ( unsigned long long ) ( char ) V_148 & 0xff ;
if ( strcmp ( type , L_73 ) == 0 )
return ( unsigned long long ) ( short ) V_148 & 0xffff ;
if ( strcmp ( type , L_74 ) == 0 )
return ( unsigned long long ) ( int ) V_148 & 0xffffffff ;
if ( strncmp ( type , L_75 , 9 ) == 0 ) {
V_150 = 0 ;
type += 9 ;
}
if ( strcmp ( type , L_22 ) == 0 ) {
if ( V_150 )
return ( unsigned long long ) ( char ) V_148 & 0xff ;
else
return V_148 & 0xff ;
}
if ( strcmp ( type , L_76 ) == 0 ) {
if ( V_150 )
return ( unsigned long long ) ( short ) V_148 & 0xffff ;
else
return V_148 & 0xffff ;
}
if ( strcmp ( type , L_77 ) == 0 ) {
if ( V_150 )
return ( unsigned long long ) ( int ) V_148 & 0xffffffff ;
else
return V_148 & 0xffffffff ;
}
return V_148 ;
}
static unsigned long long
F_71 ( unsigned long long V_148 , struct V_7 * V_8 , int V_149 )
{
if ( V_8 -> type != V_74 )
F_14 ( L_78 ) ;
return F_70 ( V_148 , V_8 -> V_75 . type , V_149 ) ;
}
static int F_72 ( struct V_7 * V_8 , long long * V_148 )
{
long long V_83 , V_84 ;
int V_110 = 1 ;
switch ( V_8 -> type ) {
case V_61 :
* V_148 = strtoll ( V_8 -> V_62 . V_62 , NULL , 0 ) ;
break;
case V_74 :
V_110 = F_72 ( V_8 -> V_75 . V_18 , V_148 ) ;
if ( ! V_110 )
break;
* V_148 = F_71 ( * V_148 , V_8 , 0 ) ;
break;
case V_81 :
switch ( V_8 -> V_82 . V_82 [ 0 ] ) {
case '|' :
V_110 = F_72 ( V_8 -> V_82 . V_83 , & V_83 ) ;
if ( ! V_110 )
break;
V_110 = F_72 ( V_8 -> V_82 . V_84 , & V_84 ) ;
if ( ! V_110 )
break;
if ( V_8 -> V_82 . V_82 [ 1 ] )
* V_148 = V_83 || V_84 ;
else
* V_148 = V_83 | V_84 ;
break;
case '&' :
V_110 = F_72 ( V_8 -> V_82 . V_83 , & V_83 ) ;
if ( ! V_110 )
break;
V_110 = F_72 ( V_8 -> V_82 . V_84 , & V_84 ) ;
if ( ! V_110 )
break;
if ( V_8 -> V_82 . V_82 [ 1 ] )
* V_148 = V_83 && V_84 ;
else
* V_148 = V_83 & V_84 ;
break;
case '<' :
V_110 = F_72 ( V_8 -> V_82 . V_83 , & V_83 ) ;
if ( ! V_110 )
break;
V_110 = F_72 ( V_8 -> V_82 . V_84 , & V_84 ) ;
if ( ! V_110 )
break;
switch ( V_8 -> V_82 . V_82 [ 1 ] ) {
case 0 :
* V_148 = V_83 < V_84 ;
break;
case '<' :
* V_148 = V_83 << V_84 ;
break;
case '=' :
* V_148 = V_83 <= V_84 ;
break;
default:
F_47 ( L_52 , V_8 -> V_82 . V_82 ) ;
V_110 = 0 ;
}
break;
case '>' :
V_110 = F_72 ( V_8 -> V_82 . V_83 , & V_83 ) ;
if ( ! V_110 )
break;
V_110 = F_72 ( V_8 -> V_82 . V_84 , & V_84 ) ;
if ( ! V_110 )
break;
switch ( V_8 -> V_82 . V_82 [ 1 ] ) {
case 0 :
* V_148 = V_83 > V_84 ;
break;
case '>' :
* V_148 = V_83 >> V_84 ;
break;
case '=' :
* V_148 = V_83 >= V_84 ;
break;
default:
F_47 ( L_52 , V_8 -> V_82 . V_82 ) ;
V_110 = 0 ;
}
break;
case '=' :
V_110 = F_72 ( V_8 -> V_82 . V_83 , & V_83 ) ;
if ( ! V_110 )
break;
V_110 = F_72 ( V_8 -> V_82 . V_84 , & V_84 ) ;
if ( ! V_110 )
break;
if ( V_8 -> V_82 . V_82 [ 1 ] != '=' ) {
F_47 ( L_52 , V_8 -> V_82 . V_82 ) ;
V_110 = 0 ;
} else
* V_148 = V_83 == V_84 ;
break;
case '!' :
V_110 = F_72 ( V_8 -> V_82 . V_83 , & V_83 ) ;
if ( ! V_110 )
break;
V_110 = F_72 ( V_8 -> V_82 . V_84 , & V_84 ) ;
if ( ! V_110 )
break;
switch ( V_8 -> V_82 . V_82 [ 1 ] ) {
case '=' :
* V_148 = V_83 != V_84 ;
break;
default:
F_47 ( L_52 , V_8 -> V_82 . V_82 ) ;
V_110 = 0 ;
}
break;
case '-' :
if ( V_8 -> V_82 . V_83 -> type == V_86 )
V_83 = 0 ;
else
V_110 = F_72 ( V_8 -> V_82 . V_83 , & V_83 ) ;
if ( ! V_110 )
break;
V_110 = F_72 ( V_8 -> V_82 . V_84 , & V_84 ) ;
if ( ! V_110 )
break;
* V_148 = V_83 - V_84 ;
break;
case '+' :
if ( V_8 -> V_82 . V_83 -> type == V_86 )
V_83 = 0 ;
else
V_110 = F_72 ( V_8 -> V_82 . V_83 , & V_83 ) ;
if ( ! V_110 )
break;
V_110 = F_72 ( V_8 -> V_82 . V_84 , & V_84 ) ;
if ( ! V_110 )
break;
* V_148 = V_83 + V_84 ;
break;
default:
F_47 ( L_52 , V_8 -> V_82 . V_82 ) ;
V_110 = 0 ;
}
break;
case V_86 :
case V_63 ... V_69 :
case V_76 :
case V_77 :
default:
F_47 ( L_79 , V_8 -> type ) ;
V_110 = 0 ;
}
return V_110 ;
}
static char * F_73 ( struct V_7 * V_8 )
{
long long V_148 ;
static char V_1 [ 20 ] ;
switch ( V_8 -> type ) {
case V_61 :
return V_8 -> V_62 . V_62 ;
case V_74 :
return F_73 ( V_8 -> V_75 . V_18 ) ;
case V_81 :
if ( ! F_72 ( V_8 , & V_148 ) )
break;
sprintf ( V_1 , L_80 , V_148 ) ;
return V_1 ;
case V_86 :
case V_63 ... V_69 :
case V_76 :
case V_77 :
default:
F_14 ( L_79 , V_8 -> type ) ;
break;
}
return NULL ;
}
static enum V_51
F_74 ( struct V_46 * V_47 , struct V_56 * * V_152 , char * * V_93 )
{
enum V_51 type ;
struct V_7 * V_8 = NULL ;
struct V_56 * V_64 ;
char * V_106 = * V_93 ;
char * V_58 ;
do {
F_41 ( V_106 ) ;
type = F_45 ( & V_106 ) ;
if ( F_48 ( type , V_106 , V_92 , L_81 ) )
break;
V_8 = F_6 () ;
F_41 ( V_106 ) ;
type = F_61 ( V_47 , V_8 , & V_106 ) ;
if ( type == V_92 )
type = F_64 ( V_47 , V_8 , & V_106 ) ;
if ( type == V_54 )
goto V_138;
if ( F_48 ( type , V_106 , V_55 , L_82 ) )
goto V_138;
V_64 = F_7 ( sizeof( * V_64 ) ) ;
memset ( V_64 , 0 , sizeof( * V_64 ) ) ;
V_58 = F_73 ( V_8 ) ;
if ( V_58 == NULL )
goto V_138;
V_64 -> V_58 = F_13 ( V_58 ) ;
if ( V_64 -> V_58 == NULL )
goto V_138;
F_33 ( V_8 ) ;
V_8 = F_6 () ;
F_41 ( V_106 ) ;
type = F_61 ( V_47 , V_8 , & V_106 ) ;
if ( F_48 ( type , V_106 , V_92 , L_83 ) )
goto V_138;
V_58 = F_73 ( V_8 ) ;
if ( V_58 == NULL )
goto V_138;
V_64 -> V_59 = F_13 ( V_58 ) ;
if ( V_64 -> V_59 == NULL )
goto V_138;
F_33 ( V_8 ) ;
V_8 = NULL ;
* V_152 = V_64 ;
V_152 = & V_64 -> V_23 ;
F_41 ( V_106 ) ;
type = F_45 ( & V_106 ) ;
} while ( type == V_55 && strcmp ( V_106 , L_82 ) == 0 );
* V_93 = V_106 ;
return type ;
V_138:
F_33 ( V_8 ) ;
F_41 ( V_106 ) ;
* V_93 = NULL ;
return V_54 ;
}
static enum V_51
F_75 ( struct V_46 * V_47 , struct V_7 * V_8 , char * * V_93 )
{
struct V_7 * V_64 ;
enum V_51 type ;
char * V_106 ;
memset ( V_8 , 0 , sizeof( * V_8 ) ) ;
V_8 -> type = V_66 ;
V_64 = F_6 () ;
type = F_61 ( V_47 , V_64 , & V_106 ) ;
while ( type == V_92 )
type = F_64 ( V_47 , V_64 , & V_106 ) ;
if ( F_48 ( type , V_106 , V_55 , L_82 ) )
goto V_138;
F_41 ( V_106 ) ;
V_8 -> V_67 . V_64 = V_64 ;
type = F_45 ( & V_106 ) ;
if ( F_31 ( type ) ) {
V_8 -> V_67 . V_68 = V_106 ;
type = F_45 ( & V_106 ) ;
}
if ( F_48 ( type , V_106 , V_55 , L_82 ) )
goto V_138;
type = F_74 ( V_47 , & V_8 -> V_67 . V_67 , & V_106 ) ;
if ( F_48 ( type , V_106 , V_55 , L_63 ) )
goto V_138;
F_41 ( V_106 ) ;
type = F_45 ( V_93 ) ;
return type ;
V_138:
F_41 ( V_106 ) ;
* V_93 = NULL ;
return V_54 ;
}
static enum V_51
F_76 ( struct V_46 * V_47 , struct V_7 * V_8 , char * * V_93 )
{
struct V_7 * V_64 ;
enum V_51 type ;
char * V_106 ;
memset ( V_8 , 0 , sizeof( * V_8 ) ) ;
V_8 -> type = V_69 ;
V_64 = F_6 () ;
type = F_61 ( V_47 , V_64 , & V_106 ) ;
if ( F_48 ( type , V_106 , V_55 , L_82 ) )
goto V_138;
V_8 -> V_70 . V_64 = V_64 ;
type = F_74 ( V_47 , & V_8 -> V_70 . V_71 , & V_106 ) ;
if ( F_48 ( type , V_106 , V_55 , L_63 ) )
goto V_138;
F_41 ( V_106 ) ;
type = F_45 ( V_93 ) ;
return type ;
V_138:
F_41 ( V_106 ) ;
* V_93 = NULL ;
return V_54 ;
}
static enum V_51
F_77 ( struct V_46 * V_47 , struct V_7 * V_8 , char * * V_93 )
{
struct V_7 * V_64 ;
enum V_51 type ;
char * V_106 ;
memset ( V_8 , 0 , sizeof( * V_8 ) ) ;
V_8 -> type = V_72 ;
V_64 = F_6 () ;
type = F_61 ( V_47 , V_64 , & V_106 ) ;
if ( F_48 ( type , V_106 , V_55 , L_82 ) )
goto V_138;
V_8 -> V_73 . V_64 = V_64 ;
F_41 ( V_106 ) ;
V_64 = F_6 () ;
type = F_61 ( V_47 , V_64 , & V_106 ) ;
if ( F_48 ( type , V_106 , V_55 , L_63 ) )
goto V_138;
V_8 -> V_73 . V_2 = V_64 ;
F_41 ( V_106 ) ;
type = F_45 ( V_93 ) ;
return type ;
V_138:
F_33 ( V_64 ) ;
F_41 ( V_106 ) ;
* V_93 = NULL ;
return V_54 ;
}
static enum V_51
F_78 ( struct V_46 * V_47 , struct V_7 * V_8 , char * * V_93 )
{
struct V_112 * V_64 ;
enum V_51 type ;
char * V_106 ;
memset ( V_8 , 0 , sizeof( * V_8 ) ) ;
V_8 -> type = V_78 ;
type = F_42 ( & V_106 ) ;
* V_93 = V_106 ;
if ( type != V_52 )
goto V_138;
V_64 = F_79 ( V_47 , V_106 ) ;
if ( ! V_64 )
goto V_138;
V_8 -> V_79 . V_64 = V_64 ;
V_8 -> V_79 . V_80 = 0 ;
if ( F_52 ( V_55 , L_63 ) < 0 )
goto V_138;
F_41 ( V_106 ) ;
type = F_45 ( & V_106 ) ;
* V_93 = V_106 ;
if ( type != V_92 || strcmp ( V_106 , L_33 ) != 0 )
return type ;
F_41 ( V_106 ) ;
V_8 = F_6 () ;
type = F_61 ( V_47 , V_8 , & V_106 ) ;
if ( type == V_54 )
goto V_153;
if ( ! F_48 ( type , V_106 , V_92 , L_34 ) )
goto V_153;
F_41 ( V_106 ) ;
type = F_45 ( V_93 ) ;
return type ;
V_153:
F_33 ( V_8 ) ;
V_138:
F_41 ( V_106 ) ;
* V_93 = NULL ;
return V_54 ;
}
static enum V_51
F_80 ( struct V_46 * V_47 , struct V_7 * V_8 , char * * V_93 )
{
struct V_7 * V_154 ;
enum V_51 type ;
char * V_106 ;
type = F_61 ( V_47 , V_8 , & V_106 ) ;
if ( type == V_54 )
goto V_138;
if ( type == V_92 )
type = F_64 ( V_47 , V_8 , & V_106 ) ;
if ( type == V_54 )
goto V_138;
if ( F_48 ( type , V_106 , V_55 , L_63 ) )
goto V_138;
F_41 ( V_106 ) ;
type = F_45 ( & V_106 ) ;
if ( F_31 ( type ) ||
( type == V_55 && strcmp ( V_106 , L_84 ) == 0 ) ) {
if ( V_8 -> type != V_61 )
F_14 ( L_85 ) ;
V_154 = F_6 () ;
V_8 -> type = V_74 ;
V_8 -> V_75 . type = V_8 -> V_62 . V_62 ;
V_8 -> V_75 . V_18 = V_154 ;
type = F_62 ( V_47 , V_154 , & V_106 , type ) ;
}
* V_93 = V_106 ;
return type ;
V_138:
F_41 ( V_106 ) ;
* V_93 = NULL ;
return V_54 ;
}
static enum V_51
F_81 ( struct V_46 * V_47 V_142 , struct V_7 * V_8 , char * * V_93 )
{
enum V_51 type ;
char * V_106 ;
if ( F_50 ( V_52 , & V_106 ) < 0 )
goto V_138;
V_8 -> type = V_76 ;
V_8 -> string . string = V_106 ;
V_8 -> string . V_129 = - 1 ;
if ( F_52 ( V_55 , L_63 ) < 0 )
goto V_143;
type = F_42 ( & V_106 ) ;
* V_93 = V_106 ;
return type ;
V_138:
F_41 ( V_106 ) ;
V_143:
* V_93 = NULL ;
return V_54 ;
}
static struct V_155 *
F_82 ( struct V_15 * V_15 , char * V_156 )
{
struct V_155 * V_35 ;
for ( V_35 = V_15 -> V_157 ; V_35 ; V_35 = V_35 -> V_23 ) {
if ( strcmp ( V_35 -> V_65 , V_156 ) == 0 )
break;
}
return V_35 ;
}
static void F_83 ( struct V_15 * V_15 , char * V_156 )
{
struct V_155 * V_35 ;
struct V_155 * * V_23 ;
V_23 = & V_15 -> V_157 ;
while ( ( V_35 = * V_23 ) ) {
if ( strcmp ( V_35 -> V_65 , V_156 ) == 0 ) {
* V_23 = V_35 -> V_23 ;
F_84 ( V_35 ) ;
break;
}
V_23 = & V_35 -> V_23 ;
}
}
static enum V_51
F_85 ( struct V_46 * V_47 , struct V_155 * V_35 ,
struct V_7 * V_8 , char * * V_93 )
{
struct V_7 * * V_158 ;
struct V_7 * V_60 ;
enum V_51 type ;
char * V_106 ;
char * V_159 ;
int V_20 ;
V_8 -> type = V_85 ;
V_8 -> V_35 . V_35 = V_35 ;
* V_93 = NULL ;
V_158 = & ( V_8 -> V_35 . args ) ;
for ( V_20 = 0 ; V_20 < V_35 -> V_160 ; V_20 ++ ) {
V_60 = F_6 () ;
type = F_61 ( V_47 , V_60 , & V_106 ) ;
if ( V_20 < ( V_35 -> V_160 - 1 ) )
V_159 = L_82 ;
else
V_159 = L_63 ;
if ( F_48 ( type , V_106 , V_55 , V_159 ) ) {
F_33 ( V_60 ) ;
F_41 ( V_106 ) ;
return V_54 ;
}
* V_158 = V_60 ;
V_158 = & ( V_60 -> V_23 ) ;
F_41 ( V_106 ) ;
}
type = F_42 ( & V_106 ) ;
* V_93 = V_106 ;
return type ;
}
static enum V_51
F_86 ( struct V_46 * V_47 , struct V_7 * V_8 ,
char * V_106 , char * * V_93 )
{
struct V_155 * V_35 ;
if ( strcmp ( V_106 , L_86 ) == 0 ) {
F_41 ( V_106 ) ;
V_144 = 1 ;
return F_75 ( V_47 , V_8 , V_93 ) ;
}
if ( strcmp ( V_106 , L_87 ) == 0 ) {
F_41 ( V_106 ) ;
V_146 = 1 ;
return F_76 ( V_47 , V_8 , V_93 ) ;
}
if ( strcmp ( V_106 , L_88 ) == 0 ) {
F_41 ( V_106 ) ;
return F_77 ( V_47 , V_8 , V_93 ) ;
}
if ( strcmp ( V_106 , L_89 ) == 0 ) {
F_41 ( V_106 ) ;
return F_81 ( V_47 , V_8 , V_93 ) ;
}
if ( strcmp ( V_106 , L_90 ) == 0 ) {
F_41 ( V_106 ) ;
return F_78 ( V_47 , V_8 , V_93 ) ;
}
V_35 = F_82 ( V_47 -> V_15 , V_106 ) ;
if ( V_35 ) {
F_41 ( V_106 ) ;
return F_85 ( V_47 , V_35 , V_8 , V_93 ) ;
}
F_47 ( L_91 , V_106 ) ;
F_41 ( V_106 ) ;
return V_54 ;
}
static enum V_51
F_62 ( struct V_46 * V_47 , struct V_7 * V_8 ,
char * * V_93 , enum V_51 type )
{
char * V_106 ;
char * V_62 ;
V_106 = * V_93 ;
switch ( type ) {
case V_52 :
if ( strcmp ( V_106 , L_92 ) == 0 ) {
F_41 ( V_106 ) ;
type = F_68 ( V_47 , V_8 , & V_106 ) ;
break;
}
V_62 = V_106 ;
type = F_45 ( & V_106 ) ;
if ( type == V_55 && strcmp ( V_106 , L_84 ) == 0 ) {
F_41 ( V_106 ) ;
V_106 = NULL ;
type = F_86 ( V_47 , V_8 , V_62 , & V_106 ) ;
break;
}
while ( type == V_52 ) {
char * V_141 ;
V_141 = realloc ( V_62 ,
strlen ( V_62 ) + strlen ( V_106 ) + 2 ) ;
if ( ! V_141 ) {
free ( V_62 ) ;
* V_93 = NULL ;
F_41 ( V_106 ) ;
return V_54 ;
}
V_62 = V_141 ;
strcat ( V_62 , L_31 ) ;
strcat ( V_62 , V_106 ) ;
F_41 ( V_106 ) ;
type = F_45 ( & V_106 ) ;
}
V_8 -> type = V_61 ;
V_8 -> V_62 . V_62 = V_62 ;
break;
case V_90 :
case V_53 :
V_8 -> type = V_61 ;
V_8 -> V_62 . V_62 = V_106 ;
type = F_45 ( & V_106 ) ;
break;
case V_55 :
if ( strcmp ( V_106 , L_84 ) == 0 ) {
F_41 ( V_106 ) ;
type = F_80 ( V_47 , V_8 , & V_106 ) ;
break;
}
case V_92 :
V_8 -> type = V_81 ;
V_8 -> V_82 . V_82 = V_106 ;
V_8 -> V_82 . V_83 = NULL ;
type = F_64 ( V_47 , V_8 , & V_106 ) ;
if ( type == V_54 )
V_8 -> V_82 . V_82 = NULL ;
break;
case V_54 ... V_88 :
default:
F_14 ( L_93 , type ) ;
}
* V_93 = V_106 ;
return type ;
}
static int F_87 ( struct V_46 * V_47 , struct V_7 * * V_152 )
{
enum V_51 type = V_54 ;
struct V_7 * V_8 ;
char * V_106 ;
int args = 0 ;
do {
if ( type == V_88 ) {
type = F_45 ( & V_106 ) ;
continue;
}
V_8 = F_6 () ;
type = F_61 ( V_47 , V_8 , & V_106 ) ;
if ( type == V_54 ) {
F_41 ( V_106 ) ;
F_33 ( V_8 ) ;
return - 1 ;
}
* V_152 = V_8 ;
args ++ ;
if ( type == V_92 ) {
type = F_64 ( V_47 , V_8 , & V_106 ) ;
F_41 ( V_106 ) ;
if ( type == V_54 ) {
* V_152 = NULL ;
F_33 ( V_8 ) ;
return - 1 ;
}
V_152 = & V_8 -> V_23 ;
continue;
}
if ( type == V_55 && strcmp ( V_106 , L_82 ) == 0 ) {
F_41 ( V_106 ) ;
* V_152 = V_8 ;
V_152 = & V_8 -> V_23 ;
continue;
}
break;
} while ( type != V_91 );
if ( type != V_91 && type != V_54 )
F_41 ( V_106 ) ;
return args ;
}
static int F_88 ( struct V_46 * V_47 )
{
enum V_51 type ;
char * V_106 ;
int V_110 ;
if ( F_53 ( V_52 , L_94 ) < 0 )
return - 1 ;
if ( F_52 ( V_52 , L_95 ) < 0 )
return - 1 ;
if ( F_52 ( V_92 , L_20 ) < 0 )
return - 1 ;
if ( F_50 ( V_90 , & V_106 ) < 0 )
goto V_111;
V_102:
V_47 -> V_161 . V_132 = V_106 ;
V_47 -> V_161 . args = NULL ;
type = F_45 ( & V_106 ) ;
if ( type == V_91 )
return 0 ;
if ( type == V_90 ) {
char * V_162 ;
V_162 = F_7 ( strlen ( V_47 -> V_161 . V_132 ) +
strlen ( V_106 ) + 1 ) ;
strcpy ( V_162 , V_47 -> V_161 . V_132 ) ;
strcat ( V_162 , V_106 ) ;
F_41 ( V_106 ) ;
F_41 ( V_47 -> V_161 . V_132 ) ;
V_47 -> V_161 . V_132 = NULL ;
V_106 = V_162 ;
goto V_102;
}
if ( F_48 ( type , V_106 , V_55 , L_82 ) )
goto V_111;
F_41 ( V_106 ) ;
V_110 = F_87 ( V_47 , & V_47 -> V_161 . args ) ;
if ( V_110 < 0 )
return - 1 ;
return V_110 ;
V_111:
F_41 ( V_106 ) ;
return - 1 ;
}
struct V_112 *
F_89 ( struct V_46 * V_47 , const char * V_65 )
{
struct V_112 * V_132 ;
for ( V_132 = V_47 -> V_132 . V_133 ;
V_132 ; V_132 = V_132 -> V_23 ) {
if ( strcmp ( V_132 -> V_65 , V_65 ) == 0 )
break;
}
return V_132 ;
}
struct V_112 *
F_79 ( struct V_46 * V_47 , const char * V_65 )
{
struct V_112 * V_132 ;
for ( V_132 = V_47 -> V_132 . V_114 ;
V_132 ; V_132 = V_132 -> V_23 ) {
if ( strcmp ( V_132 -> V_65 , V_65 ) == 0 )
break;
}
return V_132 ;
}
struct V_112 *
F_69 ( struct V_46 * V_47 , const char * V_65 )
{
struct V_112 * V_132 ;
V_132 = F_89 ( V_47 , V_65 ) ;
if ( V_132 )
return V_132 ;
return F_79 ( V_47 , V_65 ) ;
}
unsigned long long F_90 ( struct V_15 * V_15 ,
const void * V_163 , int V_2 )
{
switch ( V_2 ) {
case 1 :
return * ( unsigned char * ) V_163 ;
case 2 :
return F_91 ( V_15 , V_163 ) ;
case 4 :
return F_92 ( V_15 , V_163 ) ;
case 8 :
return F_93 ( V_15 , V_163 ) ;
default:
return 0 ;
}
}
int F_94 ( struct V_112 * V_64 , const void * V_164 ,
unsigned long long * V_58 )
{
if ( ! V_64 )
return - 1 ;
switch ( V_64 -> V_2 ) {
case 1 :
case 2 :
case 4 :
case 8 :
* V_58 = F_90 ( V_64 -> V_47 -> V_15 ,
V_164 + V_64 -> V_129 , V_64 -> V_2 ) ;
return 0 ;
default:
return - 1 ;
}
}
static int F_95 ( struct V_15 * V_15 ,
const char * type , int * V_129 , int * V_2 )
{
struct V_46 * V_47 ;
struct V_112 * V_64 ;
if ( ! V_15 -> V_48 )
F_14 ( L_96 ) ;
V_47 = V_15 -> V_48 [ 0 ] ;
V_64 = F_89 ( V_47 , type ) ;
if ( ! V_64 )
return - 1 ;
* V_129 = V_64 -> V_129 ;
* V_2 = V_64 -> V_2 ;
return 0 ;
}
static int F_96 ( struct V_15 * V_15 , void * V_164 ,
int * V_2 , int * V_129 , const char * V_65 )
{
int V_110 ;
if ( ! * V_2 ) {
V_110 = F_95 ( V_15 , V_65 , V_129 , V_2 ) ;
if ( V_110 < 0 )
return V_110 ;
}
return F_90 ( V_15 , V_164 + * V_129 , * V_2 ) ;
}
static int F_97 ( struct V_15 * V_15 , void * V_164 )
{
return F_96 ( V_15 , V_164 ,
& V_15 -> V_165 , & V_15 -> V_166 ,
L_97 ) ;
}
static int F_98 ( struct V_15 * V_15 , void * V_164 )
{
return F_96 ( V_15 , V_164 ,
& V_15 -> V_167 , & V_15 -> V_168 ,
L_98 ) ;
}
static int F_99 ( struct V_15 * V_15 , void * V_164 )
{
return F_96 ( V_15 , V_164 ,
& V_15 -> V_169 , & V_15 -> V_170 ,
L_99 ) ;
}
static int F_100 ( struct V_15 * V_15 , void * V_164 )
{
return F_96 ( V_15 , V_164 ,
& V_15 -> V_171 , & V_15 -> V_172 ,
L_100 ) ;
}
static int F_101 ( struct V_15 * V_15 , void * V_164 )
{
return F_96 ( V_15 , V_164 ,
& V_15 -> V_173 , & V_15 -> V_174 ,
L_101 ) ;
}
static int F_102 ( struct V_15 * V_15 , void * V_164 )
{
return F_96 ( V_15 , V_164 ,
& V_15 -> V_173 , & V_15 -> V_174 ,
L_102 ) ;
}
struct V_46 * F_103 ( struct V_15 * V_15 , int V_50 )
{
struct V_46 * * V_175 ;
struct V_46 V_24 ;
struct V_46 * V_176 = & V_24 ;
if ( V_15 -> V_177 && V_15 -> V_177 -> V_50 == V_50 )
return V_15 -> V_177 ;
V_24 . V_50 = V_50 ;
V_175 = bsearch ( & V_176 , V_15 -> V_48 , V_15 -> V_49 ,
sizeof( * V_15 -> V_48 ) , V_178 ) ;
if ( V_175 ) {
V_15 -> V_177 = * V_175 ;
return * V_175 ;
}
return NULL ;
}
struct V_46 *
F_104 ( struct V_15 * V_15 ,
const char * V_179 , const char * V_65 )
{
struct V_46 * V_47 ;
int V_20 ;
if ( V_15 -> V_177 &&
strcmp ( V_15 -> V_177 -> V_65 , V_65 ) == 0 &&
( ! V_179 || strcmp ( V_15 -> V_177 -> system , V_179 ) == 0 ) )
return V_15 -> V_177 ;
for ( V_20 = 0 ; V_20 < V_15 -> V_49 ; V_20 ++ ) {
V_47 = V_15 -> V_48 [ V_20 ] ;
if ( strcmp ( V_47 -> V_65 , V_65 ) == 0 ) {
if ( ! V_179 )
break;
if ( strcmp ( V_47 -> system , V_179 ) == 0 )
break;
}
}
if ( V_20 == V_15 -> V_49 )
V_47 = NULL ;
V_15 -> V_177 = V_47 ;
return V_47 ;
}
static unsigned long long
F_105 ( void * V_164 , int V_2 , struct V_46 * V_47 , struct V_7 * V_8 )
{
struct V_15 * V_15 = V_47 -> V_15 ;
unsigned long long V_148 = 0 ;
unsigned long long V_83 , V_84 ;
struct V_7 * V_180 = NULL ;
struct V_7 * V_181 ;
unsigned long V_129 ;
unsigned int V_182 ;
switch ( V_8 -> type ) {
case V_86 :
return 0 ;
case V_61 :
return F_106 ( V_8 -> V_62 . V_62 , NULL , 0 ) ;
case V_63 :
if ( ! V_8 -> V_64 . V_64 ) {
V_8 -> V_64 . V_64 = F_69 ( V_47 , V_8 -> V_64 . V_65 ) ;
if ( ! V_8 -> V_64 . V_64 )
F_14 ( L_103 , V_8 -> V_64 . V_65 ) ;
}
V_148 = F_90 ( V_15 , V_164 + V_8 -> V_64 . V_64 -> V_129 ,
V_8 -> V_64 . V_64 -> V_2 ) ;
break;
case V_66 :
case V_69 :
case V_72 :
break;
case V_74 :
V_148 = F_105 ( V_164 , V_2 , V_47 , V_8 -> V_75 . V_18 ) ;
return F_71 ( V_148 , V_8 , 0 ) ;
case V_76 :
case V_77 :
return 0 ;
case V_85 : {
struct V_183 V_184 ;
F_107 ( & V_184 ) ;
V_148 = F_108 ( & V_184 , V_164 , V_2 , V_47 , V_8 ) ;
F_109 ( & V_184 ) ;
return V_148 ;
}
case V_81 :
if ( strcmp ( V_8 -> V_82 . V_82 , L_33 ) == 0 ) {
V_84 = F_105 ( V_164 , V_2 , V_47 , V_8 -> V_82 . V_84 ) ;
V_181 = V_8 -> V_82 . V_83 ;
while ( V_181 -> type == V_74 ) {
if ( ! V_180 )
V_180 = V_181 ;
V_181 = V_181 -> V_75 . V_18 ;
}
V_182 = V_15 -> V_131 ;
switch ( V_181 -> type ) {
case V_78 :
V_129 = F_90 ( V_15 ,
V_164 + V_181 -> V_79 . V_64 -> V_129 ,
V_181 -> V_79 . V_64 -> V_2 ) ;
if ( V_181 -> V_79 . V_64 -> V_130 )
V_182 = V_181 -> V_79 . V_64 -> V_130 ;
V_129 &= 0xffff ;
V_129 += V_84 ;
break;
case V_63 :
if ( ! V_181 -> V_64 . V_64 ) {
V_181 -> V_64 . V_64 =
F_69 ( V_47 , V_181 -> V_64 . V_65 ) ;
if ( ! V_181 -> V_64 . V_64 )
F_14 ( L_103 , V_181 -> V_64 . V_65 ) ;
}
V_182 = V_181 -> V_64 . V_64 -> V_130 ;
V_129 = V_181 -> V_64 . V_64 -> V_129 +
V_84 * V_181 -> V_64 . V_64 -> V_130 ;
break;
default:
goto V_185;
}
V_148 = F_90 ( V_15 ,
V_164 + V_129 , V_182 ) ;
if ( V_180 )
V_148 = F_71 ( V_148 , V_180 , 1 ) ;
break;
} else if ( strcmp ( V_8 -> V_82 . V_82 , L_54 ) == 0 ) {
V_83 = F_105 ( V_164 , V_2 , V_47 , V_8 -> V_82 . V_83 ) ;
V_8 = V_8 -> V_82 . V_84 ;
if ( V_83 )
V_148 = F_105 ( V_164 , V_2 , V_47 , V_8 -> V_82 . V_83 ) ;
else
V_148 = F_105 ( V_164 , V_2 , V_47 , V_8 -> V_82 . V_84 ) ;
break;
}
V_185:
V_83 = F_105 ( V_164 , V_2 , V_47 , V_8 -> V_82 . V_83 ) ;
V_84 = F_105 ( V_164 , V_2 , V_47 , V_8 -> V_82 . V_84 ) ;
switch ( V_8 -> V_82 . V_82 [ 0 ] ) {
case '!' :
switch ( V_8 -> V_82 . V_82 [ 1 ] ) {
case 0 :
V_148 = ! V_84 ;
break;
case '=' :
V_148 = V_83 != V_84 ;
break;
default:
F_14 ( L_52 , V_8 -> V_82 . V_82 ) ;
}
break;
case '~' :
V_148 = ~ V_84 ;
break;
case '|' :
if ( V_8 -> V_82 . V_82 [ 1 ] )
V_148 = V_83 || V_84 ;
else
V_148 = V_83 | V_84 ;
break;
case '&' :
if ( V_8 -> V_82 . V_82 [ 1 ] )
V_148 = V_83 && V_84 ;
else
V_148 = V_83 & V_84 ;
break;
case '<' :
switch ( V_8 -> V_82 . V_82 [ 1 ] ) {
case 0 :
V_148 = V_83 < V_84 ;
break;
case '<' :
V_148 = V_83 << V_84 ;
break;
case '=' :
V_148 = V_83 <= V_84 ;
break;
default:
F_14 ( L_52 , V_8 -> V_82 . V_82 ) ;
}
break;
case '>' :
switch ( V_8 -> V_82 . V_82 [ 1 ] ) {
case 0 :
V_148 = V_83 > V_84 ;
break;
case '>' :
V_148 = V_83 >> V_84 ;
break;
case '=' :
V_148 = V_83 >= V_84 ;
break;
default:
F_14 ( L_52 , V_8 -> V_82 . V_82 ) ;
}
break;
case '=' :
if ( V_8 -> V_82 . V_82 [ 1 ] != '=' )
F_14 ( L_52 , V_8 -> V_82 . V_82 ) ;
V_148 = V_83 == V_84 ;
break;
case '-' :
V_148 = V_83 - V_84 ;
break;
case '+' :
V_148 = V_83 + V_84 ;
break;
case '/' :
V_148 = V_83 / V_84 ;
break;
case '*' :
V_148 = V_83 * V_84 ;
break;
default:
F_14 ( L_52 , V_8 -> V_82 . V_82 ) ;
}
break;
default:
return 0 ;
}
return V_148 ;
}
static unsigned long long F_110 ( const char * V_186 )
{
int V_20 ;
if ( isdigit ( V_186 [ 0 ] ) )
return F_106 ( V_186 , NULL , 0 ) ;
for ( V_20 = 0 ; V_20 < ( int ) ( sizeof( V_67 ) / sizeof( V_67 [ 0 ] ) ) ; V_20 ++ )
if ( strcmp ( V_67 [ V_20 ] . V_65 , V_186 ) == 0 )
return V_67 [ V_20 ] . V_58 ;
return 0 ;
}
static void F_111 ( struct V_183 * V_184 , const char * V_132 ,
int V_187 , const char * V_59 )
{
if ( V_187 >= 0 )
F_112 ( V_184 , V_132 , V_187 , V_59 ) ;
else
F_112 ( V_184 , V_132 , V_59 ) ;
}
static void F_113 ( struct V_183 * V_184 , void * V_164 , int V_2 ,
struct V_46 * V_47 , const char * V_132 ,
int V_187 , struct V_7 * V_8 )
{
struct V_15 * V_15 = V_47 -> V_15 ;
struct V_56 * V_186 ;
struct V_112 * V_64 ;
unsigned long long V_148 , V_188 ;
unsigned long V_31 ;
char * V_59 ;
unsigned char * V_73 ;
int V_189 ;
int V_20 , V_123 ;
switch ( V_8 -> type ) {
case V_86 :
return;
case V_61 :
F_111 ( V_184 , V_132 , V_187 , V_8 -> V_62 . V_62 ) ;
return;
case V_63 :
V_64 = V_8 -> V_64 . V_64 ;
if ( ! V_64 ) {
V_64 = F_69 ( V_47 , V_8 -> V_64 . V_65 ) ;
if ( ! V_64 )
F_14 ( L_103 , V_8 -> V_64 . V_65 ) ;
V_8 -> V_64 . V_64 = V_64 ;
}
V_123 = V_64 -> V_2 ? : V_2 - V_64 -> V_129 ;
if ( ! ( V_64 -> V_67 & V_113 ) &&
V_64 -> V_2 == V_15 -> V_131 ) {
V_31 = * ( unsigned long * ) ( V_164 + V_64 -> V_129 ) ;
F_112 ( V_184 , L_104 , V_31 ) ;
break;
}
V_59 = F_7 ( V_123 + 1 ) ;
memcpy ( V_59 , V_164 + V_64 -> V_129 , V_123 ) ;
V_59 [ V_123 ] = 0 ;
F_111 ( V_184 , V_132 , V_187 , V_59 ) ;
free ( V_59 ) ;
break;
case V_66 :
V_148 = F_105 ( V_164 , V_2 , V_47 , V_8 -> V_67 . V_64 ) ;
V_189 = 0 ;
for ( V_186 = V_8 -> V_67 . V_67 ; V_186 ; V_186 = V_186 -> V_23 ) {
V_188 = F_110 ( V_186 -> V_58 ) ;
if ( ! V_148 && ! V_188 ) {
F_111 ( V_184 , V_132 , V_187 , V_186 -> V_59 ) ;
break;
}
if ( V_188 && ( V_148 & V_188 ) == V_188 ) {
if ( V_189 && V_8 -> V_67 . V_68 )
F_114 ( V_184 , V_8 -> V_67 . V_68 ) ;
F_111 ( V_184 , V_132 , V_187 , V_186 -> V_59 ) ;
V_189 = 1 ;
V_148 &= ~ V_188 ;
}
}
break;
case V_69 :
V_148 = F_105 ( V_164 , V_2 , V_47 , V_8 -> V_70 . V_64 ) ;
for ( V_186 = V_8 -> V_70 . V_71 ; V_186 ; V_186 = V_186 -> V_23 ) {
V_188 = F_110 ( V_186 -> V_58 ) ;
if ( V_148 == V_188 ) {
F_111 ( V_184 , V_132 , V_187 , V_186 -> V_59 ) ;
break;
}
}
break;
case V_72 :
V_64 = V_8 -> V_73 . V_64 -> V_64 . V_64 ;
if ( ! V_64 ) {
V_59 = V_8 -> V_73 . V_64 -> V_64 . V_65 ;
V_64 = F_69 ( V_47 , V_59 ) ;
if ( ! V_64 )
F_14 ( L_103 , V_59 ) ;
V_8 -> V_73 . V_64 -> V_64 . V_64 = V_64 ;
}
V_73 = V_164 + V_64 -> V_129 ;
V_123 = F_105 ( V_164 , V_2 , V_47 , V_8 -> V_73 . V_2 ) ;
for ( V_20 = 0 ; V_20 < V_123 ; V_20 ++ ) {
if ( V_20 )
F_115 ( V_184 , ' ' ) ;
F_112 ( V_184 , L_105 , V_73 [ V_20 ] ) ;
}
break;
case V_74 :
break;
case V_76 : {
int V_190 ;
if ( V_8 -> string . V_129 == - 1 ) {
struct V_112 * V_191 ;
V_191 = F_69 ( V_47 , V_8 -> string . string ) ;
V_8 -> string . V_129 = V_191 -> V_129 ;
}
V_190 = F_92 ( V_15 , V_164 + V_8 -> string . V_129 ) ;
V_190 &= 0xffff ;
F_111 ( V_184 , V_132 , V_187 , ( ( char * ) V_164 ) + V_190 ) ;
break;
}
case V_77 :
F_111 ( V_184 , V_132 , V_187 , V_8 -> string . string ) ;
break;
case V_81 :
if ( V_8 -> V_82 . V_82 [ 0 ] != '?' )
return;
V_148 = F_105 ( V_164 , V_2 , V_47 , V_8 -> V_82 . V_83 ) ;
if ( V_148 )
F_113 ( V_184 , V_164 , V_2 , V_47 ,
V_132 , V_187 , V_8 -> V_82 . V_84 -> V_82 . V_83 ) ;
else
F_113 ( V_184 , V_164 , V_2 , V_47 ,
V_132 , V_187 , V_8 -> V_82 . V_84 -> V_82 . V_84 ) ;
break;
case V_85 :
F_108 ( V_184 , V_164 , V_2 , V_47 , V_8 ) ;
break;
default:
break;
}
}
static unsigned long long
F_108 ( struct V_183 * V_184 , void * V_164 , int V_2 ,
struct V_46 * V_47 , struct V_7 * V_8 )
{
struct V_155 * V_192 = V_8 -> V_35 . V_35 ;
struct V_193 * V_194 ;
unsigned long long * args ;
unsigned long long V_110 ;
struct V_7 * V_60 ;
struct V_183 V_59 ;
struct V_195 {
struct V_195 * V_23 ;
char * V_59 ;
} * V_196 = NULL , * string ;
int V_20 ;
if ( ! V_192 -> V_160 ) {
V_110 = (* V_192 -> V_35 )( V_184 , NULL ) ;
goto V_101;
}
V_60 = V_8 -> V_35 . args ;
V_194 = V_192 -> V_197 ;
args = F_7 ( sizeof( * args ) * V_192 -> V_160 ) ;
for ( V_20 = 0 ; V_20 < V_192 -> V_160 ; V_20 ++ ) {
switch ( V_194 -> type ) {
case V_198 :
case V_199 :
case V_200 :
args [ V_20 ] = F_105 ( V_164 , V_2 , V_47 , V_60 ) ;
break;
case V_201 :
F_107 ( & V_59 ) ;
F_113 ( & V_59 , V_164 , V_2 , V_47 , L_106 , - 1 , V_60 ) ;
F_116 ( & V_59 ) ;
string = F_7 ( sizeof( * string ) ) ;
string -> V_23 = V_196 ;
string -> V_59 = F_13 ( V_59 . V_202 ) ;
if ( ! string -> V_59 )
F_14 ( L_107 ) ;
args [ V_20 ] = ( unsigned long long ) string -> V_59 ;
V_196 = string ;
F_109 ( & V_59 ) ;
break;
default:
F_14 ( L_108 ) ;
break;
}
V_60 = V_60 -> V_23 ;
V_194 = V_194 -> V_23 ;
}
V_110 = (* V_192 -> V_35 )( V_184 , args ) ;
free ( args ) ;
while ( V_196 ) {
string = V_196 ;
V_196 = string -> V_23 ;
free ( string -> V_59 ) ;
free ( string ) ;
}
V_101:
return V_110 ;
}
static struct V_7 * F_117 ( char * V_45 , void * V_164 , int V_2 , struct V_46 * V_47 )
{
struct V_15 * V_15 = V_47 -> V_15 ;
struct V_112 * V_64 , * V_203 ;
struct V_7 * args , * V_8 , * * V_23 ;
unsigned long long V_204 , V_148 ;
char * V_163 ;
void * V_205 ;
int V_206 ;
V_64 = V_15 -> V_207 ;
V_203 = V_15 -> V_208 ;
if ( ! V_64 ) {
V_64 = F_79 ( V_47 , L_109 ) ;
if ( ! V_64 )
F_14 ( L_110 ) ;
V_203 = F_79 ( V_47 , L_111 ) ;
if ( ! V_203 )
F_14 ( L_112 ) ;
V_15 -> V_207 = V_64 ;
V_15 -> V_208 = V_203 ;
}
V_204 = F_90 ( V_15 , V_164 + V_203 -> V_129 , V_203 -> V_2 ) ;
args = F_6 () ;
V_8 = args ;
V_8 -> V_23 = NULL ;
V_23 = & V_8 -> V_23 ;
V_8 -> type = V_61 ;
V_8 -> V_62 . V_62 = F_7 ( 32 ) ;
sprintf ( V_8 -> V_62 . V_62 , L_80 , V_204 ) ;
for ( V_163 = V_45 + 6 , V_205 = V_164 + V_64 -> V_129 ;
V_205 < V_164 + V_2 && * V_163 ; V_163 ++ ) {
int V_209 = 0 ;
if ( * V_163 == '%' ) {
V_210:
V_163 ++ ;
switch ( * V_163 ) {
case '%' :
break;
case 'l' :
V_209 ++ ;
goto V_210;
case 'L' :
V_209 = 2 ;
goto V_210;
case '0' ... '9' :
goto V_210;
case '.' :
goto V_210;
case 'p' :
V_209 = 1 ;
case 'd' :
case 'u' :
case 'x' :
case 'i' :
switch ( V_209 ) {
case 0 :
V_206 = 4 ;
break;
case 1 :
V_206 = V_15 -> V_131 ;
break;
case 2 :
V_206 = 8 ;
break;
default:
V_206 = V_209 ;
break;
}
case '*' :
if ( * V_163 == '*' )
V_206 = 4 ;
V_205 = ( void * ) ( ( ( unsigned long ) V_205 + 3 ) &
~ 3 ) ;
V_148 = F_90 ( V_15 , V_205 , V_206 ) ;
V_205 += V_206 ;
V_8 = F_6 () ;
V_8 -> V_23 = NULL ;
V_8 -> type = V_61 ;
V_8 -> V_62 . V_62 = F_7 ( 32 ) ;
sprintf ( V_8 -> V_62 . V_62 , L_80 , V_148 ) ;
* V_23 = V_8 ;
V_23 = & V_8 -> V_23 ;
if ( * V_163 == '*' )
goto V_210;
break;
case 's' :
V_8 = F_6 () ;
V_8 -> V_23 = NULL ;
V_8 -> type = V_77 ;
V_8 -> string . string = F_13 ( V_205 ) ;
if ( ! V_8 -> string . string )
break;
V_205 += strlen ( V_205 ) + 1 ;
* V_23 = V_8 ;
V_23 = & V_8 -> V_23 ;
default:
break;
}
}
}
return args ;
}
static void F_118 ( struct V_7 * args )
{
struct V_7 * V_23 ;
while ( args ) {
V_23 = args -> V_23 ;
F_33 ( args ) ;
args = V_23 ;
}
}
static char *
F_119 ( void * V_164 , int V_2 V_142 , struct V_46 * V_47 )
{
struct V_15 * V_15 = V_47 -> V_15 ;
unsigned long long V_31 ;
struct V_112 * V_64 ;
struct V_38 * V_44 ;
char * V_132 ;
char * V_211 ;
V_64 = V_15 -> V_212 ;
if ( ! V_64 ) {
V_64 = F_79 ( V_47 , L_95 ) ;
if ( ! V_64 )
F_14 ( L_113 ) ;
V_15 -> V_212 = V_64 ;
}
V_31 = F_90 ( V_15 , V_164 + V_64 -> V_129 , V_64 -> V_2 ) ;
V_44 = F_26 ( V_15 , V_31 ) ;
if ( ! V_44 ) {
V_132 = F_7 ( 45 ) ;
sprintf ( V_132 , L_114 ,
V_31 ) ;
return V_132 ;
}
V_211 = V_44 -> V_44 ;
if ( * V_211 == '"' )
V_211 ++ ;
V_132 = F_7 ( strlen ( V_211 ) + 10 ) ;
sprintf ( V_132 , L_115 , L_116 , V_211 ) ;
V_211 = V_132 + strlen ( V_132 ) - 1 ;
if ( * V_211 == '"' )
* V_211 = 0 ;
V_211 -= 2 ;
if ( strcmp ( V_211 , L_117 ) == 0 )
* V_211 = 0 ;
return V_132 ;
}
static void F_120 ( struct V_183 * V_184 , int V_213 , void * V_164 , int V_2 ,
struct V_46 * V_47 , struct V_7 * V_8 )
{
unsigned char * V_1 ;
char * V_45 = L_118 ;
if ( V_8 -> type == V_85 ) {
F_108 ( V_184 , V_164 , V_2 , V_47 , V_8 ) ;
return;
}
if ( V_8 -> type != V_63 ) {
F_112 ( V_184 , L_119 ,
V_8 -> type ) ;
return;
}
if ( V_213 == 'm' )
V_45 = L_120 ;
if ( ! V_8 -> V_64 . V_64 ) {
V_8 -> V_64 . V_64 =
F_69 ( V_47 , V_8 -> V_64 . V_65 ) ;
if ( ! V_8 -> V_64 . V_64 )
F_14 ( L_103 , V_8 -> V_64 . V_65 ) ;
}
if ( V_8 -> V_64 . V_64 -> V_2 != 6 ) {
F_112 ( V_184 , L_121 ) ;
return;
}
V_1 = V_164 + V_8 -> V_64 . V_64 -> V_129 ;
F_112 ( V_184 , V_45 , V_1 [ 0 ] , V_1 [ 1 ] , V_1 [ 2 ] , V_1 [ 3 ] , V_1 [ 4 ] , V_1 [ 5 ] ) ;
}
static int F_121 ( char * V_211 , unsigned int V_123 )
{
unsigned int V_20 ;
for ( V_20 = 0 ; V_20 < V_123 && V_211 [ V_20 ] ; V_20 ++ )
if ( ! isprint ( V_211 [ V_20 ] ) )
return 0 ;
return 1 ;
}
static void F_122 ( struct V_183 * V_184 , void * V_164 , int V_2 ,
struct V_46 * V_47 )
{
struct V_112 * V_64 ;
unsigned long long V_148 ;
unsigned int V_129 , V_123 , V_20 ;
V_64 = V_47 -> V_132 . V_114 ;
while ( V_64 ) {
F_112 ( V_184 , L_122 , V_64 -> V_65 ) ;
if ( V_64 -> V_67 & V_113 ) {
V_129 = V_64 -> V_129 ;
V_123 = V_64 -> V_2 ;
if ( V_64 -> V_67 & V_126 ) {
V_148 = F_90 ( V_47 -> V_15 , V_164 + V_129 , V_123 ) ;
V_129 = V_148 ;
V_123 = V_129 >> 16 ;
V_129 &= 0xffff ;
}
if ( V_64 -> V_67 & V_125 &&
F_121 ( V_164 + V_129 , V_123 ) ) {
F_112 ( V_184 , L_106 , ( char * ) V_164 + V_129 ) ;
} else {
F_114 ( V_184 , L_123 ) ;
for ( V_20 = 0 ; V_20 < V_123 ; V_20 ++ ) {
if ( V_20 )
F_114 ( V_184 , L_124 ) ;
F_112 ( V_184 , L_105 ,
* ( ( unsigned char * ) V_164 + V_129 + V_20 ) ) ;
}
F_115 ( V_184 , ']' ) ;
V_64 -> V_67 &= ~ V_125 ;
}
} else {
V_148 = F_90 ( V_47 -> V_15 , V_164 + V_64 -> V_129 ,
V_64 -> V_2 ) ;
if ( V_64 -> V_67 & V_118 ) {
F_112 ( V_184 , L_125 , V_148 ) ;
} else if ( V_64 -> V_67 & V_214 ) {
switch ( V_64 -> V_2 ) {
case 4 :
if ( V_64 -> V_67 & V_127 )
F_112 ( V_184 , L_126 , ( int ) V_148 ) ;
else
F_112 ( V_184 , L_127 , ( int ) V_148 ) ;
break;
case 2 :
F_112 ( V_184 , L_128 , ( short ) V_148 ) ;
break;
case 1 :
F_112 ( V_184 , L_129 , ( char ) V_148 ) ;
break;
default:
F_112 ( V_184 , L_80 , V_148 ) ;
}
} else {
if ( V_64 -> V_67 & V_127 )
F_112 ( V_184 , L_125 , V_148 ) ;
else
F_112 ( V_184 , L_130 , V_148 ) ;
}
}
V_64 = V_64 -> V_23 ;
}
}
static void F_123 ( struct V_183 * V_184 , void * V_164 , int V_2 , struct V_46 * V_47 )
{
struct V_15 * V_15 = V_47 -> V_15 ;
struct V_161 * V_161 = & V_47 -> V_161 ;
struct V_7 * V_8 = V_161 -> args ;
struct V_7 * args = NULL ;
const char * V_163 = V_161 -> V_132 ;
unsigned long long V_148 ;
struct V_28 * V_35 ;
const char * V_215 ;
char * V_216 = NULL ;
char V_132 [ 32 ] ;
int V_217 ;
int V_218 ;
int V_187 ;
int V_123 ;
int V_209 ;
if ( V_47 -> V_67 & V_140 ) {
F_112 ( V_184 , L_131 ) ;
F_122 ( V_184 , V_164 , V_2 , V_47 ) ;
return;
}
if ( V_47 -> V_67 & V_219 ) {
V_216 = F_119 ( V_164 , V_2 , V_47 ) ;
args = F_117 ( V_216 , V_164 , V_2 , V_47 ) ;
V_8 = args ;
V_163 = V_216 ;
}
for (; * V_163 ; V_163 ++ ) {
V_209 = 0 ;
if ( * V_163 == '\\' ) {
V_163 ++ ;
switch ( * V_163 ) {
case 'n' :
F_115 ( V_184 , '\n' ) ;
break;
case 't' :
F_115 ( V_184 , '\t' ) ;
break;
case 'r' :
F_115 ( V_184 , '\r' ) ;
break;
case '\\' :
F_115 ( V_184 , '\\' ) ;
break;
default:
F_115 ( V_184 , * V_163 ) ;
break;
}
} else if ( * V_163 == '%' ) {
V_215 = V_163 ;
V_217 = 0 ;
V_218 = 0 ;
V_220:
V_163 ++ ;
switch ( * V_163 ) {
case '%' :
F_115 ( V_184 , '%' ) ;
break;
case '#' :
goto V_220;
case 'h' :
V_209 -- ;
goto V_220;
case 'l' :
V_209 ++ ;
goto V_220;
case 'L' :
V_209 = 2 ;
goto V_220;
case '*' :
if ( ! V_8 )
F_14 ( L_132 ) ;
V_187 = F_105 ( V_164 , V_2 , V_47 , V_8 ) ;
V_218 = 1 ;
V_8 = V_8 -> V_23 ;
goto V_220;
case '.' :
case 'z' :
case 'Z' :
case '0' ... '9' :
goto V_220;
case 'p' :
if ( V_15 -> V_131 == 4 )
V_209 = 1 ;
else
V_209 = 2 ;
if ( * ( V_163 + 1 ) == 'F' ||
* ( V_163 + 1 ) == 'f' ) {
V_163 ++ ;
V_217 = * V_163 ;
} else if ( * ( V_163 + 1 ) == 'M' || * ( V_163 + 1 ) == 'm' ) {
F_120 ( V_184 , * ( V_163 + 1 ) , V_164 , V_2 , V_47 , V_8 ) ;
V_163 ++ ;
V_8 = V_8 -> V_23 ;
break;
}
case 'd' :
case 'i' :
case 'x' :
case 'X' :
case 'u' :
if ( ! V_8 )
F_14 ( L_132 ) ;
V_123 = ( ( unsigned long ) V_163 + 1 ) -
( unsigned long ) V_215 ;
if ( V_123 > 31 )
F_14 ( L_133 ) ;
memcpy ( V_132 , V_215 , V_123 ) ;
V_132 [ V_123 ] = 0 ;
V_148 = F_105 ( V_164 , V_2 , V_47 , V_8 ) ;
V_8 = V_8 -> V_23 ;
if ( V_217 ) {
V_35 = F_19 ( V_15 , V_148 ) ;
if ( V_35 ) {
F_114 ( V_184 , V_35 -> V_35 ) ;
if ( V_217 == 'F' )
F_112 ( V_184 ,
L_134 ,
V_148 - V_35 -> V_31 ) ;
break;
}
}
if ( V_15 -> V_131 == 8 && V_209 &&
sizeof( long ) != 8 ) {
char * V_211 ;
V_209 = 2 ;
V_211 = strchr ( V_132 , 'l' ) ;
if ( V_211 )
memmove ( V_211 + 1 , V_211 , strlen ( V_211 ) + 1 ) ;
else if ( strcmp ( V_132 , L_135 ) == 0 )
strcpy ( V_132 , L_125 ) ;
}
switch ( V_209 ) {
case - 2 :
if ( V_218 )
F_112 ( V_184 , V_132 , V_187 , ( char ) V_148 ) ;
else
F_112 ( V_184 , V_132 , ( char ) V_148 ) ;
break;
case - 1 :
if ( V_218 )
F_112 ( V_184 , V_132 , V_187 , ( short ) V_148 ) ;
else
F_112 ( V_184 , V_132 , ( short ) V_148 ) ;
break;
case 0 :
if ( V_218 )
F_112 ( V_184 , V_132 , V_187 , ( int ) V_148 ) ;
else
F_112 ( V_184 , V_132 , ( int ) V_148 ) ;
break;
case 1 :
if ( V_218 )
F_112 ( V_184 , V_132 , V_187 , ( long ) V_148 ) ;
else
F_112 ( V_184 , V_132 , ( long ) V_148 ) ;
break;
case 2 :
if ( V_218 )
F_112 ( V_184 , V_132 , V_187 ,
( long long ) V_148 ) ;
else
F_112 ( V_184 , V_132 , ( long long ) V_148 ) ;
break;
default:
F_14 ( L_136 , V_209 ) ;
}
break;
case 's' :
if ( ! V_8 )
F_14 ( L_137 ) ;
V_123 = ( ( unsigned long ) V_163 + 1 ) -
( unsigned long ) V_215 ;
if ( V_123 > 31 )
F_14 ( L_133 ) ;
memcpy ( V_132 , V_215 , V_123 ) ;
V_132 [ V_123 ] = 0 ;
if ( ! V_218 )
V_187 = - 1 ;
F_113 ( V_184 , V_164 , V_2 , V_47 ,
V_132 , V_187 , V_8 ) ;
V_8 = V_8 -> V_23 ;
break;
default:
F_112 ( V_184 , L_138 , * V_163 ) ;
}
} else
F_115 ( V_184 , * V_163 ) ;
}
if ( args ) {
F_118 ( args ) ;
free ( V_216 ) ;
}
}
void F_124 ( struct V_15 * V_15 ,
struct V_183 * V_184 , struct V_221 * V_222 )
{
static int V_223 = 1 ;
static int V_224 = 1 ;
static int V_225 ;
static int V_226 ;
unsigned int V_227 ;
unsigned int V_228 ;
int V_229 ;
int V_230 ;
int V_231 ;
int V_232 ;
void * V_164 = V_222 -> V_164 ;
V_227 = F_100 ( V_15 , V_164 ) ;
V_228 = F_99 ( V_15 , V_164 ) ;
if ( V_225 )
V_229 = F_101 ( V_15 , V_164 ) ;
else if ( V_223 ) {
V_229 = F_101 ( V_15 , V_164 ) ;
if ( V_229 < 0 )
V_223 = 0 ;
else
V_225 = 1 ;
}
if ( V_226 )
V_230 = F_102 ( V_15 , V_164 ) ;
else if ( V_224 ) {
V_230 = F_102 ( V_15 , V_164 ) ;
if ( V_230 < 0 )
V_224 = 0 ;
else
V_226 = 1 ;
}
V_231 = V_227 & V_233 ;
V_232 = V_227 & V_234 ;
F_112 ( V_184 , L_139 ,
( V_227 & V_235 ) ? 'd' :
( V_227 & V_236 ) ?
'X' : '.' ,
( V_227 & V_237 ) ?
'N' : '.' ,
( V_231 && V_232 ) ? 'H' :
V_231 ? 'h' : V_232 ? 's' : '.' ) ;
if ( V_228 )
F_112 ( V_184 , L_140 , V_228 ) ;
else
F_115 ( V_184 , '.' ) ;
if ( V_226 ) {
if ( V_230 < 0 )
F_115 ( V_184 , '.' ) ;
else
F_112 ( V_184 , L_127 , V_230 ) ;
}
if ( V_225 ) {
if ( V_229 < 0 )
F_115 ( V_184 , '.' ) ;
else
F_112 ( V_184 , L_127 , V_229 ) ;
}
F_116 ( V_184 ) ;
}
int F_125 ( struct V_15 * V_15 , struct V_221 * V_238 )
{
return F_97 ( V_15 , V_238 -> V_164 ) ;
}
struct V_46 * F_126 ( struct V_15 * V_15 , int type )
{
return F_103 ( V_15 , type ) ;
}
int F_127 ( struct V_15 * V_15 , struct V_221 * V_238 )
{
return F_98 ( V_15 , V_238 -> V_164 ) ;
}
const char * F_128 ( struct V_15 * V_15 , int V_14 )
{
const char * V_22 ;
V_22 = F_10 ( V_15 , V_14 ) ;
return V_22 ;
}
void F_129 ( struct V_183 * V_184 , struct V_46 * V_47 ,
struct V_221 * V_222 )
{
int V_239 = 1 ;
if ( V_47 -> V_15 -> V_240 )
F_122 ( V_184 , V_222 -> V_164 , V_222 -> V_2 , V_47 ) ;
else {
if ( V_47 -> V_241 )
V_239 = V_47 -> V_241 ( V_184 , V_222 , V_47 ,
V_47 -> V_242 ) ;
if ( V_239 )
F_123 ( V_184 , V_222 -> V_164 , V_222 -> V_2 , V_47 ) ;
}
F_116 ( V_184 ) ;
}
void F_130 ( struct V_15 * V_15 , struct V_183 * V_184 ,
struct V_221 * V_222 )
{
static char * V_243 = L_141 ;
struct V_46 * V_47 ;
unsigned long V_244 ;
unsigned long V_245 ;
unsigned long V_246 ;
const char * V_22 ;
void * V_164 = V_222 -> V_164 ;
int type ;
int V_14 ;
int V_123 ;
int V_211 ;
V_244 = V_222 -> V_247 / V_248 ;
V_246 = V_222 -> V_247 - V_244 * V_248 ;
if ( V_222 -> V_2 < 0 ) {
F_47 ( L_142 , V_222 -> V_2 ) ;
return;
}
type = F_97 ( V_15 , V_164 ) ;
V_47 = F_103 ( V_15 , type ) ;
if ( ! V_47 ) {
F_47 ( L_143 , type ) ;
return;
}
V_14 = F_98 ( V_15 , V_164 ) ;
V_22 = F_10 ( V_15 , V_14 ) ;
if ( V_15 -> V_249 ) {
F_112 ( V_184 , L_144 ,
V_22 , V_14 , V_222 -> V_250 ) ;
F_124 ( V_15 , V_184 , V_222 ) ;
} else
F_112 ( V_184 , L_145 , V_22 , V_14 , V_222 -> V_250 ) ;
if ( V_15 -> V_67 & V_251 ) {
V_245 = V_246 ;
V_211 = 9 ;
} else {
V_245 = ( V_246 + 500 ) / V_252 ;
V_211 = 6 ;
}
F_112 ( V_184 , L_146 , V_244 , V_211 , V_245 , V_47 -> V_65 ) ;
V_123 = strlen ( V_47 -> V_65 ) ;
if ( V_123 < 20 )
F_112 ( V_184 , L_147 , 20 - V_123 , V_243 ) ;
F_129 ( V_184 , V_47 , V_222 ) ;
}
static int V_178 ( const void * V_9 , const void * V_10 )
{
struct V_46 * const * V_253 = V_9 ;
struct V_46 * const * V_254 = V_10 ;
if ( ( * V_253 ) -> V_50 < ( * V_254 ) -> V_50 )
return - 1 ;
if ( ( * V_253 ) -> V_50 > ( * V_254 ) -> V_50 )
return 1 ;
return 0 ;
}
static int F_131 ( const void * V_9 , const void * V_10 )
{
struct V_46 * const * V_253 = V_9 ;
struct V_46 * const * V_254 = V_10 ;
int V_255 ;
V_255 = strcmp ( ( * V_253 ) -> V_65 , ( * V_254 ) -> V_65 ) ;
if ( V_255 )
return V_255 ;
V_255 = strcmp ( ( * V_253 ) -> system , ( * V_254 ) -> system ) ;
if ( V_255 )
return V_255 ;
return V_178 ( V_9 , V_10 ) ;
}
static int F_132 ( const void * V_9 , const void * V_10 )
{
struct V_46 * const * V_253 = V_9 ;
struct V_46 * const * V_254 = V_10 ;
int V_255 ;
V_255 = strcmp ( ( * V_253 ) -> system , ( * V_254 ) -> system ) ;
if ( V_255 )
return V_255 ;
V_255 = strcmp ( ( * V_253 ) -> V_65 , ( * V_254 ) -> V_65 ) ;
if ( V_255 )
return V_255 ;
return V_178 ( V_9 , V_10 ) ;
}
struct V_46 * * F_133 ( struct V_15 * V_15 , enum V_256 V_257 )
{
struct V_46 * * V_48 ;
int (* F_134)( const void * V_9 , const void * V_10 );
V_48 = V_15 -> V_258 ;
if ( V_48 && V_15 -> V_120 == V_257 )
return V_48 ;
if ( ! V_48 ) {
V_48 = malloc ( sizeof( * V_48 ) * ( V_15 -> V_49 + 1 ) ) ;
if ( ! V_48 )
return NULL ;
memcpy ( V_48 , V_15 -> V_48 , sizeof( * V_48 ) * V_15 -> V_49 ) ;
V_48 [ V_15 -> V_49 ] = NULL ;
V_15 -> V_258 = V_48 ;
if ( V_257 == V_259 ) {
V_15 -> V_120 = V_257 ;
return V_48 ;
}
}
switch ( V_257 ) {
case V_259 :
F_134 = V_178 ;
break;
case V_260 :
F_134 = F_131 ;
break;
case V_261 :
F_134 = F_132 ;
break;
default:
return V_48 ;
}
qsort ( V_48 , V_15 -> V_49 , sizeof( * V_48 ) , F_134 ) ;
V_15 -> V_120 = V_257 ;
return V_48 ;
}
static struct V_112 * *
F_135 ( const char * type , const char * V_65 ,
int V_116 , struct V_112 * V_152 )
{
struct V_112 * * V_114 ;
struct V_112 * V_64 ;
int V_20 = 0 ;
V_114 = F_7 ( sizeof( * V_114 ) * ( V_116 + 1 ) ) ;
for ( V_64 = V_152 ; V_64 ; V_64 = V_64 -> V_23 ) {
V_114 [ V_20 ++ ] = V_64 ;
if ( V_20 == V_116 + 1 ) {
F_47 ( L_148 ,
V_65 , type ) ;
V_20 -- ;
break;
}
}
if ( V_20 != V_116 )
F_47 ( L_149 ,
V_65 , type ) ;
V_114 [ V_20 ] = NULL ;
return V_114 ;
}
struct V_112 * * F_136 ( struct V_46 * V_47 )
{
return F_135 ( L_150 , V_47 -> V_65 ,
V_47 -> V_132 . V_134 ,
V_47 -> V_132 . V_133 ) ;
}
struct V_112 * * F_137 ( struct V_46 * V_47 )
{
return F_135 ( L_151 , V_47 -> V_65 ,
V_47 -> V_132 . V_135 ,
V_47 -> V_132 . V_114 ) ;
}
static void F_138 ( struct V_183 * V_184 , struct V_56 * V_64 )
{
F_112 ( V_184 , L_152 , V_64 -> V_58 , V_64 -> V_59 ) ;
if ( V_64 -> V_23 ) {
F_114 ( V_184 , L_124 ) ;
F_138 ( V_184 , V_64 -> V_23 ) ;
}
}
static void F_139 ( struct V_7 * args )
{
int V_262 = 1 ;
struct V_183 V_184 ;
switch ( args -> type ) {
case V_86 :
printf ( L_153 ) ;
break;
case V_61 :
printf ( L_106 , args -> V_62 . V_62 ) ;
break;
case V_63 :
printf ( L_154 , args -> V_64 . V_65 ) ;
break;
case V_66 :
printf ( L_155 ) ;
F_139 ( args -> V_67 . V_64 ) ;
printf ( L_156 , args -> V_67 . V_68 ) ;
F_107 ( & V_184 ) ;
F_138 ( & V_184 , args -> V_67 . V_67 ) ;
F_140 ( & V_184 ) ;
F_109 ( & V_184 ) ;
printf ( L_63 ) ;
break;
case V_69 :
printf ( L_157 ) ;
F_139 ( args -> V_70 . V_64 ) ;
printf ( L_124 ) ;
F_107 ( & V_184 ) ;
F_138 ( & V_184 , args -> V_70 . V_71 ) ;
F_140 ( & V_184 ) ;
F_109 ( & V_184 ) ;
printf ( L_63 ) ;
break;
case V_72 :
printf ( L_158 ) ;
F_139 ( args -> V_73 . V_64 ) ;
printf ( L_124 ) ;
F_139 ( args -> V_73 . V_2 ) ;
printf ( L_63 ) ;
break;
case V_76 :
case V_77 :
printf ( L_159 , args -> string . string ) ;
break;
case V_74 :
printf ( L_160 , args -> V_75 . type ) ;
F_139 ( args -> V_75 . V_18 ) ;
break;
case V_81 :
if ( strcmp ( args -> V_82 . V_82 , L_20 ) == 0 )
V_262 = 0 ;
if ( V_262 )
printf ( L_84 ) ;
F_139 ( args -> V_82 . V_83 ) ;
printf ( L_161 , args -> V_82 . V_82 ) ;
F_139 ( args -> V_82 . V_84 ) ;
if ( V_262 )
printf ( L_63 ) ;
break;
default:
return;
}
if ( args -> V_23 ) {
printf ( L_7 ) ;
F_139 ( args -> V_23 ) ;
}
}
static void F_141 ( const char * V_64 ,
int * V_129 , int * V_2 , int V_263 )
{
unsigned long long V_103 ;
unsigned long long V_105 ;
char * V_106 ;
int type ;
V_103 = V_5 ;
V_105 = V_4 ;
if ( F_52 ( V_52 , L_27 ) < 0 )
return;
if ( F_52 ( V_92 , L_20 ) < 0 )
return;
if ( F_50 ( V_52 , & V_106 ) < 0 )
goto V_111;
F_41 ( V_106 ) ;
if ( V_263 ) {
if ( F_52 ( V_52 , V_64 ) < 0 )
return;
} else {
if ( F_50 ( V_52 , & V_106 ) < 0 )
goto V_111;
if ( strcmp ( V_106 , V_64 ) != 0 )
goto V_264;
F_41 ( V_106 ) ;
}
if ( F_52 ( V_92 , L_36 ) < 0 )
return;
if ( F_52 ( V_52 , L_37 ) < 0 )
return;
if ( F_52 ( V_92 , L_20 ) < 0 )
return;
if ( F_50 ( V_52 , & V_106 ) < 0 )
goto V_111;
* V_129 = atoi ( V_106 ) ;
F_41 ( V_106 ) ;
if ( F_52 ( V_92 , L_36 ) < 0 )
return;
if ( F_52 ( V_52 , L_38 ) < 0 )
return;
if ( F_52 ( V_92 , L_20 ) < 0 )
return;
if ( F_50 ( V_52 , & V_106 ) < 0 )
goto V_111;
* V_2 = atoi ( V_106 ) ;
F_41 ( V_106 ) ;
if ( F_52 ( V_92 , L_36 ) < 0 )
return;
type = F_42 ( & V_106 ) ;
if ( type != V_88 ) {
if ( type != V_52 )
goto V_111;
if ( strcmp ( V_106 , L_39 ) != 0 )
goto V_111;
F_41 ( V_106 ) ;
if ( F_52 ( V_92 , L_20 ) < 0 )
return;
if ( F_50 ( V_52 , & V_106 ) )
goto V_111;
F_41 ( V_106 ) ;
if ( F_52 ( V_92 , L_36 ) < 0 )
return;
if ( F_50 ( V_88 , & V_106 ) )
goto V_111;
}
V_111:
F_41 ( V_106 ) ;
return;
V_264:
V_5 = V_103 ;
V_4 = V_105 ;
* V_129 = 0 ;
* V_2 = 0 ;
F_41 ( V_106 ) ;
}
int F_142 ( struct V_15 * V_15 , char * V_1 , unsigned long V_2 ,
int V_131 )
{
int V_265 ;
if ( ! V_2 ) {
V_15 -> V_266 = sizeof( long long ) ;
V_15 -> V_267 = V_131 ;
V_15 -> V_268 = sizeof( long long ) + V_131 ;
V_15 -> V_269 = 1 ;
return - 1 ;
}
F_1 ( V_1 , V_2 ) ;
F_141 ( L_162 , & V_15 -> V_270 ,
& V_15 -> V_266 , 1 ) ;
F_141 ( L_163 , & V_15 -> V_271 ,
& V_15 -> V_267 , 1 ) ;
F_141 ( L_164 , & V_15 -> V_272 ,
& V_265 , 0 ) ;
F_141 ( L_165 , & V_15 -> V_268 ,
& V_15 -> V_273 , 1 ) ;
return 0 ;
}
static int F_143 ( struct V_46 * V_47 ,
int V_50 , const char * V_274 ,
const char * V_275 )
{
if ( V_50 >= 0 && V_50 != V_47 -> V_50 )
return 0 ;
if ( V_275 && ( strcmp ( V_275 , V_47 -> V_65 ) != 0 ) )
return 0 ;
if ( V_274 && ( strcmp ( V_274 , V_47 -> system ) != 0 ) )
return 0 ;
return 1 ;
}
static void F_144 ( struct V_276 * V_277 )
{
free ( ( void * ) V_277 -> V_274 ) ;
free ( ( void * ) V_277 -> V_275 ) ;
free ( V_277 ) ;
}
static int F_145 ( struct V_15 * V_15 , struct V_46 * V_47 )
{
struct V_276 * V_277 , * * V_23 ;
for ( V_23 = & V_15 -> V_278 ; * V_23 ;
V_23 = & ( * V_23 ) -> V_23 ) {
V_277 = * V_23 ;
if ( F_143 ( V_47 , V_277 -> V_50 ,
V_277 -> V_274 ,
V_277 -> V_275 ) )
break;
}
if ( ! ( * V_23 ) )
return 0 ;
F_146 ( L_166 ,
V_47 -> V_50 , V_47 -> system , V_47 -> V_65 ) ;
V_47 -> V_241 = V_277 -> V_35 ;
V_47 -> V_242 = V_277 -> V_242 ;
* V_23 = V_277 -> V_23 ;
F_144 ( V_277 ) ;
return 1 ;
}
int F_147 ( struct V_15 * V_15 ,
const char * V_1 , unsigned long V_2 ,
const char * V_179 )
{
struct V_46 * V_47 ;
int V_110 ;
F_1 ( V_1 , V_2 ) ;
V_47 = F_29 () ;
if ( ! V_47 )
return - V_27 ;
V_47 -> V_65 = F_54 () ;
if ( ! V_47 -> V_65 ) {
free ( V_47 ) ;
return - 1 ;
}
if ( strcmp ( V_179 , L_167 ) == 0 ) {
V_47 -> V_67 |= V_117 ;
if ( strcmp ( V_47 -> V_65 , L_168 ) == 0 )
V_47 -> V_67 |= V_219 ;
}
V_47 -> V_50 = F_55 () ;
if ( V_47 -> V_50 < 0 )
F_14 ( L_169 ) ;
V_47 -> system = F_13 ( V_179 ) ;
if ( ! V_47 -> system )
F_14 ( L_170 ) ;
V_47 -> V_15 = V_15 ;
V_110 = F_60 ( V_47 ) ;
if ( V_110 < 0 ) {
F_47 ( L_171 , V_47 -> V_65 ) ;
goto V_279;
}
if ( F_145 ( V_15 , V_47 ) )
V_280 = 0 ;
V_110 = F_88 ( V_47 ) ;
if ( V_110 < 0 ) {
F_47 ( L_172 ,
V_47 -> V_65 ) ;
V_280 = 1 ;
goto V_279;
}
V_280 = 1 ;
F_30 ( V_15 , V_47 ) ;
if ( ! V_110 && ( V_47 -> V_67 & V_117 ) ) {
struct V_112 * V_64 ;
struct V_7 * V_8 , * * V_152 ;
V_152 = & V_47 -> V_161 . args ;
for ( V_64 = V_47 -> V_132 . V_114 ; V_64 ; V_64 = V_64 -> V_23 ) {
V_8 = F_6 () ;
* V_152 = V_8 ;
V_152 = & V_8 -> V_23 ;
V_8 -> type = V_63 ;
V_8 -> V_64 . V_65 = F_13 ( V_64 -> V_65 ) ;
if ( ! V_8 -> V_64 . V_65 ) {
F_47 ( L_173 ) ;
V_47 -> V_67 |= V_140 ;
return - 1 ;
}
V_8 -> V_64 . V_64 = V_64 ;
}
return 0 ;
}
#define F_148 0
if ( F_148 && V_47 -> V_161 . args )
F_139 ( V_47 -> V_161 . args ) ;
return 0 ;
V_279:
V_47 -> V_67 |= V_140 ;
F_30 ( V_15 , V_47 ) ;
return - 1 ;
}
int F_149 ( struct V_183 * V_184 , struct V_112 * V_64 ,
const char * V_65 , struct V_221 * V_222 ,
unsigned long long * V_148 , int V_281 )
{
if ( ! V_64 ) {
if ( V_281 )
F_112 ( V_184 , L_174 , V_65 ) ;
return - 1 ;
}
if ( F_94 ( V_64 , V_222 -> V_164 , V_148 ) ) {
if ( V_281 )
F_112 ( V_184 , L_175 , V_65 ) ;
return - 1 ;
}
return 0 ;
}
void * F_150 ( struct V_183 * V_184 , struct V_46 * V_47 ,
const char * V_65 , struct V_221 * V_222 ,
int * V_123 , int V_281 )
{
struct V_112 * V_64 ;
void * V_164 = V_222 -> V_164 ;
unsigned V_129 ;
int V_282 ;
if ( ! V_47 )
return NULL ;
V_64 = F_79 ( V_47 , V_65 ) ;
if ( ! V_64 ) {
if ( V_281 )
F_112 ( V_184 , L_174 , V_65 ) ;
return NULL ;
}
if ( ! V_123 )
V_123 = & V_282 ;
V_129 = V_64 -> V_129 ;
if ( V_64 -> V_67 & V_126 ) {
V_129 = F_90 ( V_47 -> V_15 ,
V_164 + V_129 , V_64 -> V_2 ) ;
* V_123 = V_129 >> 16 ;
V_129 &= 0xffff ;
} else
* V_123 = V_64 -> V_2 ;
return V_164 + V_129 ;
}
int F_151 ( struct V_183 * V_184 , struct V_46 * V_47 ,
const char * V_65 , struct V_221 * V_222 ,
unsigned long long * V_148 , int V_281 )
{
struct V_112 * V_64 ;
if ( ! V_47 )
return - 1 ;
V_64 = F_79 ( V_47 , V_65 ) ;
return F_149 ( V_184 , V_64 , V_65 , V_222 , V_148 , V_281 ) ;
}
int F_152 ( struct V_183 * V_184 , struct V_46 * V_47 ,
const char * V_65 , struct V_221 * V_222 ,
unsigned long long * V_148 , int V_281 )
{
struct V_112 * V_64 ;
if ( ! V_47 )
return - 1 ;
V_64 = F_89 ( V_47 , V_65 ) ;
return F_149 ( V_184 , V_64 , V_65 , V_222 , V_148 , V_281 ) ;
}
int F_153 ( struct V_183 * V_184 , struct V_46 * V_47 ,
const char * V_65 , struct V_221 * V_222 ,
unsigned long long * V_148 , int V_281 )
{
struct V_112 * V_64 ;
if ( ! V_47 )
return - 1 ;
V_64 = F_69 ( V_47 , V_65 ) ;
return F_149 ( V_184 , V_64 , V_65 , V_222 , V_148 , V_281 ) ;
}
int F_154 ( struct V_183 * V_184 , const char * V_45 ,
struct V_46 * V_47 , const char * V_65 ,
struct V_221 * V_222 , int V_281 )
{
struct V_112 * V_64 = F_79 ( V_47 , V_65 ) ;
unsigned long long V_148 ;
if ( ! V_64 )
goto V_283;
if ( F_94 ( V_64 , V_222 -> V_164 , & V_148 ) )
goto V_283;
return F_112 ( V_184 , V_45 , V_148 ) ;
V_283:
if ( V_281 )
F_112 ( V_184 , L_176 , V_65 ) ;
return - 1 ;
}
static void F_84 ( struct V_155 * V_35 )
{
struct V_193 * V_197 ;
free ( V_35 -> V_65 ) ;
while ( V_35 -> V_197 ) {
V_197 = V_35 -> V_197 ;
V_35 -> V_197 = V_197 -> V_23 ;
free ( V_197 ) ;
}
free ( V_35 ) ;
}
int F_155 ( struct V_15 * V_15 ,
T_1 V_35 ,
enum V_284 V_285 ,
char * V_65 , ... )
{
struct V_155 * V_192 ;
struct V_193 * * V_286 ;
struct V_193 * V_194 ;
enum V_284 type ;
T_2 V_287 ;
V_192 = F_82 ( V_15 , V_65 ) ;
if ( V_192 ) {
F_146 ( L_177 , V_65 ) ;
F_83 ( V_15 , V_65 ) ;
}
V_192 = F_7 ( sizeof( * V_192 ) ) ;
memset ( V_192 , 0 , sizeof( * V_192 ) ) ;
V_192 -> V_285 = V_285 ;
V_192 -> V_65 = F_13 ( V_65 ) ;
V_192 -> V_35 = V_35 ;
if ( ! V_192 -> V_65 )
F_14 ( L_178 ) ;
V_286 = & ( V_192 -> V_197 ) ;
va_start ( V_287 , V_65 ) ;
for (; ; ) {
type = va_arg ( V_287 , enum V_284 ) ;
if ( type == V_288 )
break;
if ( type < 0 || type >= V_289 ) {
F_156 ( L_179 , type ) ;
goto V_138;
}
V_194 = F_7 ( sizeof( * V_194 ) ) ;
V_194 -> type = type ;
V_194 -> V_23 = NULL ;
* V_286 = V_194 ;
V_286 = & ( V_194 -> V_23 ) ;
V_192 -> V_160 ++ ;
}
va_end ( V_287 ) ;
V_192 -> V_23 = V_15 -> V_157 ;
V_15 -> V_157 = V_192 ;
return 0 ;
V_138:
va_end ( V_287 ) ;
F_84 ( V_192 ) ;
return - 1 ;
}
int F_157 ( struct V_15 * V_15 ,
int V_50 , char * V_274 , char * V_275 ,
T_3 V_35 ,
void * V_242 )
{
struct V_46 * V_47 ;
struct V_276 * V_277 ;
if ( V_50 >= 0 ) {
V_47 = F_103 ( V_15 , V_50 ) ;
if ( ! V_47 )
goto V_290;
if ( V_275 && ( strcmp ( V_275 , V_47 -> V_65 ) != 0 ) )
goto V_290;
if ( V_274 && ( strcmp ( V_274 , V_47 -> system ) != 0 ) )
goto V_290;
} else {
V_47 = F_104 ( V_15 , V_274 , V_275 ) ;
if ( ! V_47 )
goto V_290;
}
F_146 ( L_166 ,
V_47 -> V_50 , V_47 -> system , V_47 -> V_65 ) ;
V_47 -> V_241 = V_35 ;
V_47 -> V_242 = V_242 ;
return 0 ;
V_290:
V_277 = F_7 ( sizeof( * V_277 ) ) ;
memset ( V_277 , 0 , sizeof( * V_277 ) ) ;
V_277 -> V_50 = V_50 ;
if ( V_275 )
V_277 -> V_275 = F_13 ( V_275 ) ;
if ( V_274 )
V_277 -> V_274 = F_13 ( V_274 ) ;
if ( ( V_275 && ! V_277 -> V_275 ) ||
( V_274 && ! V_277 -> V_274 ) ) {
F_14 ( L_180 ) ;
}
V_277 -> V_35 = V_35 ;
V_277 -> V_23 = V_15 -> V_278 ;
V_15 -> V_278 = V_277 ;
V_277 -> V_242 = V_242 ;
return - 1 ;
}
struct V_15 * F_158 ( void )
{
struct V_15 * V_15 ;
V_15 = malloc ( sizeof( * V_15 ) ) ;
if ( ! V_15 )
return NULL ;
memset ( V_15 , 0 , sizeof( * V_15 ) ) ;
V_15 -> V_291 = 1 ;
return V_15 ;
}
void F_159 ( struct V_15 * V_15 )
{
V_15 -> V_291 ++ ;
}
static void F_160 ( struct V_112 * V_64 )
{
struct V_112 * V_23 ;
while ( V_64 ) {
V_23 = V_64 -> V_23 ;
free ( V_64 -> type ) ;
free ( V_64 -> V_65 ) ;
free ( V_64 ) ;
V_64 = V_23 ;
}
}
static void F_161 ( struct V_132 * V_132 )
{
F_160 ( V_132 -> V_133 ) ;
F_160 ( V_132 -> V_114 ) ;
}
static void F_162 ( struct V_46 * V_47 )
{
free ( V_47 -> V_65 ) ;
free ( V_47 -> system ) ;
F_161 ( & V_47 -> V_132 ) ;
free ( V_47 -> V_161 . V_132 ) ;
F_118 ( V_47 -> V_161 . args ) ;
free ( V_47 ) ;
}
void F_163 ( struct V_15 * V_15 )
{
struct V_16 * V_17 , * V_292 ;
struct V_32 * V_33 , * V_293 ;
struct V_41 * V_42 , * V_294 ;
struct V_155 * V_295 ;
struct V_276 * V_277 ;
int V_20 ;
if ( ! V_15 )
return;
V_17 = V_15 -> V_17 ;
V_33 = V_15 -> V_33 ;
V_42 = V_15 -> V_42 ;
V_15 -> V_291 -- ;
if ( V_15 -> V_291 )
return;
if ( V_15 -> V_19 ) {
for ( V_20 = 0 ; V_20 < V_15 -> V_21 ; V_20 ++ )
free ( V_15 -> V_19 [ V_20 ] . V_22 ) ;
free ( V_15 -> V_19 ) ;
}
while ( V_17 ) {
V_292 = V_17 -> V_23 ;
free ( V_17 -> V_22 ) ;
free ( V_17 ) ;
V_17 = V_292 ;
}
if ( V_15 -> V_28 ) {
for ( V_20 = 0 ; V_20 < V_15 -> V_34 ; V_20 ++ ) {
free ( V_15 -> V_28 [ V_20 ] . V_35 ) ;
free ( V_15 -> V_28 [ V_20 ] . V_36 ) ;
}
free ( V_15 -> V_28 ) ;
}
while ( V_33 ) {
V_293 = V_33 -> V_23 ;
free ( V_33 -> V_35 ) ;
free ( V_33 -> V_36 ) ;
free ( V_33 ) ;
V_33 = V_293 ;
}
while ( V_15 -> V_157 ) {
V_295 = V_15 -> V_157 ;
V_15 -> V_157 = V_295 -> V_23 ;
F_84 ( V_295 ) ;
}
if ( V_15 -> V_38 ) {
for ( V_20 = 0 ; V_20 < V_15 -> V_43 ; V_20 ++ )
free ( V_15 -> V_38 [ V_20 ] . V_44 ) ;
free ( V_15 -> V_38 ) ;
}
while ( V_42 ) {
V_294 = V_42 -> V_23 ;
free ( V_42 -> V_44 ) ;
free ( V_42 ) ;
V_42 = V_294 ;
}
for ( V_20 = 0 ; V_20 < V_15 -> V_49 ; V_20 ++ )
F_162 ( V_15 -> V_48 [ V_20 ] ) ;
while ( V_15 -> V_278 ) {
V_277 = V_15 -> V_278 ;
V_15 -> V_278 = V_277 -> V_23 ;
F_144 ( V_277 ) ;
}
free ( V_15 -> V_48 ) ;
free ( V_15 -> V_258 ) ;
free ( V_15 ) ;
}
void F_164 ( struct V_15 * V_15 )
{
F_163 ( V_15 ) ;
}
