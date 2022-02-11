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
static int F_14 ( const void * V_8 , const void * V_9 )
{
const struct V_27 * V_28 = V_8 ;
const struct V_27 * V_29 = V_9 ;
if ( V_28 -> V_30 < V_29 -> V_30 )
return - 1 ;
if ( V_28 -> V_30 > V_29 -> V_30 )
return 1 ;
return 0 ;
}
static int F_15 ( const void * V_8 , const void * V_9 )
{
const struct V_27 * V_28 = V_8 ;
const struct V_27 * V_29 = V_9 ;
if ( ( V_28 -> V_30 == V_29 -> V_30 ) ||
( V_28 -> V_30 > V_29 -> V_30 &&
V_28 -> V_30 < ( V_29 + 1 ) -> V_30 ) )
return 0 ;
if ( V_28 -> V_30 < V_29 -> V_30 )
return - 1 ;
return 1 ;
}
static int F_16 ( struct V_14 * V_14 )
{
struct V_31 * V_32 ;
struct V_31 * V_17 ;
struct V_27 * V_27 ;
int V_19 ;
V_27 = malloc ( sizeof( * V_27 ) * ( V_14 -> V_33 + 1 ) ) ;
if ( ! V_27 )
return - 1 ;
V_32 = V_14 -> V_32 ;
V_19 = 0 ;
while ( V_32 ) {
V_27 [ V_19 ] . V_34 = V_32 -> V_34 ;
V_27 [ V_19 ] . V_30 = V_32 -> V_30 ;
V_27 [ V_19 ] . V_35 = V_32 -> V_35 ;
V_19 ++ ;
V_17 = V_32 ;
V_32 = V_32 -> V_22 ;
free ( V_17 ) ;
}
qsort ( V_27 , V_14 -> V_33 , sizeof( * V_27 ) , F_14 ) ;
V_27 [ V_14 -> V_33 ] . V_34 = NULL ;
V_27 [ V_14 -> V_33 ] . V_30 = 0 ;
V_27 [ V_14 -> V_33 ] . V_35 = NULL ;
V_14 -> V_27 = V_27 ;
V_14 -> V_32 = NULL ;
return 0 ;
}
static struct V_27 *
F_17 ( struct V_14 * V_14 , unsigned long long V_30 )
{
struct V_27 * V_34 ;
struct V_27 V_23 ;
if ( ! V_14 -> V_27 )
F_16 ( V_14 ) ;
V_23 . V_30 = V_30 ;
V_34 = bsearch ( & V_23 , V_14 -> V_27 , V_14 -> V_33 ,
sizeof( * V_14 -> V_27 ) , F_15 ) ;
return V_34 ;
}
const char * F_18 ( struct V_14 * V_14 , unsigned long long V_30 )
{
struct V_27 * V_36 ;
V_36 = F_17 ( V_14 , V_30 ) ;
if ( ! V_36 )
return NULL ;
return V_36 -> V_34 ;
}
unsigned long long
F_19 ( struct V_14 * V_14 , unsigned long long V_30 )
{
struct V_27 * V_36 ;
V_36 = F_17 ( V_14 , V_30 ) ;
if ( ! V_36 )
return 0 ;
return V_36 -> V_30 ;
}
int F_20 ( struct V_14 * V_14 , char * V_34 ,
unsigned long long V_30 , char * V_35 )
{
struct V_31 * V_17 = malloc ( sizeof( * V_17 ) ) ;
if ( ! V_17 )
return - 1 ;
V_17 -> V_22 = V_14 -> V_32 ;
V_17 -> V_34 = F_12 ( V_34 ) ;
if ( ! V_17 -> V_34 )
goto V_37;
if ( V_35 ) {
V_17 -> V_35 = F_12 ( V_35 ) ;
if ( ! V_17 -> V_35 )
goto V_38;
} else
V_17 -> V_35 = NULL ;
V_17 -> V_30 = V_30 ;
V_14 -> V_32 = V_17 ;
V_14 -> V_33 ++ ;
return 0 ;
V_38:
free ( V_17 -> V_34 ) ;
V_17 -> V_34 = NULL ;
V_37:
free ( V_17 ) ;
V_24 = V_26 ;
return - 1 ;
}
void F_21 ( struct V_14 * V_14 )
{
int V_19 ;
if ( ! V_14 -> V_27 )
F_16 ( V_14 ) ;
for ( V_19 = 0 ; V_19 < ( int ) V_14 -> V_33 ; V_19 ++ ) {
printf ( L_4 ,
V_14 -> V_27 [ V_19 ] . V_30 ,
V_14 -> V_27 [ V_19 ] . V_34 ) ;
if ( V_14 -> V_27 [ V_19 ] . V_35 )
printf ( L_5 , V_14 -> V_27 [ V_19 ] . V_35 ) ;
else
printf ( L_6 ) ;
}
}
static int F_22 ( const void * V_8 , const void * V_9 )
{
const struct V_39 * V_40 = V_8 ;
const struct V_39 * V_41 = V_9 ;
if ( V_40 -> V_30 < V_41 -> V_30 )
return - 1 ;
if ( V_40 -> V_30 > V_41 -> V_30 )
return 1 ;
return 0 ;
}
static int F_23 ( struct V_14 * V_14 )
{
struct V_42 * V_43 ;
struct V_42 * V_17 ;
struct V_39 * V_39 ;
int V_19 ;
V_39 = malloc ( sizeof( * V_39 ) * ( V_14 -> V_44 + 1 ) ) ;
if ( ! V_39 )
return - 1 ;
V_43 = V_14 -> V_43 ;
V_19 = 0 ;
while ( V_43 ) {
V_39 [ V_19 ] . V_45 = V_43 -> V_45 ;
V_39 [ V_19 ] . V_30 = V_43 -> V_30 ;
V_19 ++ ;
V_17 = V_43 ;
V_43 = V_43 -> V_22 ;
free ( V_17 ) ;
}
qsort ( V_39 , V_14 -> V_44 , sizeof( * V_39 ) , F_22 ) ;
V_14 -> V_39 = V_39 ;
V_14 -> V_43 = NULL ;
return 0 ;
}
static struct V_39 *
F_24 ( struct V_14 * V_14 , unsigned long long V_30 )
{
struct V_39 * V_45 ;
struct V_39 V_23 ;
if ( ! V_14 -> V_39 && F_23 ( V_14 ) )
return NULL ;
V_23 . V_30 = V_30 ;
V_45 = bsearch ( & V_23 , V_14 -> V_39 , V_14 -> V_44 ,
sizeof( * V_14 -> V_39 ) , F_22 ) ;
return V_45 ;
}
int F_25 ( struct V_14 * V_14 , char * V_46 ,
unsigned long long V_30 )
{
struct V_42 * V_17 = malloc ( sizeof( * V_17 ) ) ;
if ( ! V_17 )
return - 1 ;
V_17 -> V_22 = V_14 -> V_43 ;
V_17 -> V_30 = V_30 ;
V_17 -> V_45 = F_12 ( V_46 ) ;
if ( ! V_17 -> V_45 )
goto V_37;
V_14 -> V_43 = V_17 ;
V_14 -> V_44 ++ ;
return 0 ;
V_37:
free ( V_17 ) ;
V_24 = V_26 ;
return - 1 ;
}
void F_26 ( struct V_14 * V_14 )
{
int V_19 ;
if ( ! V_14 -> V_39 )
F_23 ( V_14 ) ;
for ( V_19 = 0 ; V_19 < ( int ) V_14 -> V_44 ; V_19 ++ ) {
printf ( L_7 ,
V_14 -> V_39 [ V_19 ] . V_30 ,
V_14 -> V_39 [ V_19 ] . V_45 ) ;
}
}
static struct V_47 * F_27 ( void )
{
return calloc ( 1 , sizeof( struct V_47 ) ) ;
}
static int F_28 ( struct V_14 * V_14 , struct V_47 * V_48 )
{
int V_19 ;
struct V_47 * * V_49 = realloc ( V_14 -> V_49 , sizeof( V_48 ) *
( V_14 -> V_50 + 1 ) ) ;
if ( ! V_49 )
return - 1 ;
V_14 -> V_49 = V_49 ;
for ( V_19 = 0 ; V_19 < V_14 -> V_50 ; V_19 ++ ) {
if ( V_14 -> V_49 [ V_19 ] -> V_51 > V_48 -> V_51 )
break;
}
if ( V_19 < V_14 -> V_50 )
memmove ( & V_14 -> V_49 [ V_19 + 1 ] ,
& V_14 -> V_49 [ V_19 ] ,
sizeof( V_48 ) * ( V_14 -> V_50 - V_19 ) ) ;
V_14 -> V_49 [ V_19 ] = V_48 ;
V_14 -> V_50 ++ ;
V_48 -> V_14 = V_14 ;
return 0 ;
}
static int F_29 ( enum V_52 type )
{
switch ( type ) {
case V_53 ... V_54 :
return 1 ;
case V_55 ... V_56 :
default:
return 0 ;
}
}
static void F_30 ( struct V_57 * V_58 )
{
struct V_57 * V_22 ;
while ( V_58 ) {
V_22 = V_58 -> V_22 ;
free ( V_58 -> V_59 ) ;
free ( V_58 -> V_60 ) ;
free ( V_58 ) ;
V_58 = V_22 ;
}
}
static void F_31 ( struct V_7 * V_61 )
{
struct V_7 * V_62 ;
if ( ! V_61 )
return;
switch ( V_61 -> type ) {
case V_63 :
free ( V_61 -> V_64 . V_64 ) ;
break;
case V_65 :
free ( V_61 -> V_66 . V_67 ) ;
break;
case V_68 :
F_31 ( V_61 -> V_69 . V_66 ) ;
free ( V_61 -> V_69 . V_70 ) ;
F_30 ( V_61 -> V_69 . V_69 ) ;
break;
case V_71 :
F_31 ( V_61 -> V_72 . V_66 ) ;
F_30 ( V_61 -> V_72 . V_73 ) ;
break;
case V_74 :
F_31 ( V_61 -> V_75 . V_66 ) ;
F_31 ( V_61 -> V_75 . V_2 ) ;
break;
case V_76 :
free ( V_61 -> V_77 . type ) ;
F_31 ( V_61 -> V_77 . V_17 ) ;
break;
case V_78 :
case V_79 :
free ( V_61 -> string . string ) ;
break;
case V_80 :
free ( V_61 -> V_81 . V_82 ) ;
break;
case V_83 :
free ( V_61 -> V_84 . V_84 ) ;
F_31 ( V_61 -> V_84 . V_85 ) ;
F_31 ( V_61 -> V_84 . V_86 ) ;
break;
case V_87 :
while ( V_61 -> V_34 . args ) {
V_62 = V_61 -> V_34 . args ;
V_61 -> V_34 . args = V_62 -> V_22 ;
F_31 ( V_62 ) ;
}
break;
case V_88 :
default:
break;
}
free ( V_61 ) ;
}
static enum V_52 F_32 ( int V_89 )
{
if ( V_89 == '\n' )
return V_90 ;
if ( isspace ( V_89 ) )
return V_91 ;
if ( isalnum ( V_89 ) || V_89 == '_' )
return V_53 ;
if ( V_89 == '\'' )
return V_54 ;
if ( V_89 == '"' )
return V_92 ;
if ( ! isprint ( V_89 ) )
return V_93 ;
if ( V_89 == '(' || V_89 == ')' || V_89 == ',' )
return V_56 ;
return V_94 ;
}
static int F_33 ( void )
{
if ( V_5 >= V_4 )
return - 1 ;
return V_3 [ V_5 ++ ] ;
}
static int F_34 ( void )
{
if ( V_5 >= V_4 )
return - 1 ;
return V_3 [ V_5 ] ;
}
int F_35 ( void )
{
return F_34 () ;
}
static int F_36 ( char * * V_95 , char * V_1 , int V_2 )
{
char * V_96 = realloc ( * V_95 , V_2 ) ;
if ( ! V_96 ) {
free ( * V_95 ) ;
* V_95 = NULL ;
return - 1 ;
}
if ( ! * V_95 )
strcpy ( V_96 , V_1 ) ;
else
strcat ( V_96 , V_1 ) ;
* V_95 = V_96 ;
return 0 ;
}
static enum V_52 F_37 ( char * * V_95 )
{
char V_1 [ V_97 ] ;
int V_89 , V_98 , V_99 , V_100 ;
int V_19 = 0 ;
int V_101 = 0 ;
enum V_52 type ;
* V_95 = NULL ;
V_89 = F_33 () ;
if ( V_89 < 0 )
return V_93 ;
type = F_32 ( V_89 ) ;
if ( type == V_93 )
return type ;
V_1 [ V_19 ++ ] = V_89 ;
switch ( type ) {
case V_90 :
case V_56 :
if ( F_38 ( V_95 , L_8 , V_89 ) < 0 )
return V_55 ;
return type ;
case V_94 :
switch ( V_89 ) {
case '-' :
V_100 = F_34 () ;
if ( V_100 == '>' ) {
V_1 [ V_19 ++ ] = F_33 () ;
break;
}
case '+' :
case '|' :
case '&' :
case '>' :
case '<' :
V_98 = V_89 ;
V_89 = F_34 () ;
if ( V_89 != V_98 )
goto V_102;
V_1 [ V_19 ++ ] = F_33 () ;
switch ( V_98 ) {
case '>' :
case '<' :
goto V_102;
default:
break;
}
break;
case '!' :
case '=' :
goto V_102;
default:
break;
}
V_1 [ V_19 ] = 0 ;
* V_95 = F_12 ( V_1 ) ;
return type ;
V_102:
V_89 = F_34 () ;
if ( V_89 == '=' )
V_1 [ V_19 ++ ] = F_33 () ;
goto V_103;
case V_92 :
case V_54 :
V_19 -- ;
V_99 = V_89 ;
V_98 = 0 ;
V_104:
do {
if ( V_19 == ( V_97 - 1 ) ) {
V_1 [ V_19 ] = 0 ;
V_101 += V_97 ;
if ( F_36 ( V_95 , V_1 , V_101 ) < 0 )
return V_93 ;
V_19 = 0 ;
}
V_98 = V_89 ;
V_89 = F_33 () ;
V_1 [ V_19 ++ ] = V_89 ;
if ( V_89 == '\\' && V_98 == '\\' )
V_98 = 0 ;
} while ( V_89 != V_99 || V_98 == '\\' );
V_19 -- ;
if ( type == V_92 ) {
unsigned long long V_105 = V_5 ;
do {
V_89 = F_33 () ;
} while ( isspace ( V_89 ) );
if ( V_89 == '"' )
goto V_104;
V_5 = V_105 ;
}
goto V_103;
case V_55 ... V_91 :
case V_53 :
default:
break;
}
while ( F_32 ( F_34 () ) == type ) {
if ( V_19 == ( V_97 - 1 ) ) {
V_1 [ V_19 ] = 0 ;
V_101 += V_97 ;
if ( F_36 ( V_95 , V_1 , V_101 ) < 0 )
return V_93 ;
V_19 = 0 ;
}
V_89 = F_33 () ;
V_1 [ V_19 ++ ] = V_89 ;
}
V_103:
V_1 [ V_19 ] = 0 ;
if ( F_36 ( V_95 , V_1 , V_101 + V_19 + 1 ) < 0 )
return V_93 ;
if ( type == V_53 ) {
if ( strcmp ( * V_95 , L_9 ) == 0 ) {
free ( * V_95 ) ;
* V_95 = NULL ;
return F_39 ( L_10 , V_95 ) ;
} else if ( strcmp ( * V_95 , L_11 ) == 0 ) {
free ( * V_95 ) ;
* V_95 = NULL ;
return F_39 ( L_12 , V_95 ) ;
} else if ( strcmp ( * V_95 , L_13 ) == 0 ) {
free ( * V_95 ) ;
* V_95 = NULL ;
return F_39 ( L_14 , V_95 ) ;
}
}
return type ;
}
static enum V_52 F_39 ( const char * V_60 , char * * V_95 )
{
const char * V_106 ;
unsigned long long V_105 ;
unsigned long long V_107 ;
enum V_52 type ;
V_106 = V_3 ;
V_105 = V_5 ;
V_107 = V_4 ;
F_1 ( V_60 , strlen ( V_60 ) ) ;
type = F_37 ( V_95 ) ;
V_3 = V_106 ;
V_5 = V_105 ;
V_4 = V_107 ;
return type ;
}
static void F_40 ( char * V_95 )
{
if ( V_95 )
free ( V_95 ) ;
}
static enum V_52 F_41 ( char * * V_95 )
{
enum V_52 type ;
for (; ; ) {
type = F_37 ( V_95 ) ;
if ( type != V_91 )
return type ;
F_40 ( * V_95 ) ;
}
* V_95 = NULL ;
return V_93 ;
}
enum V_52 F_42 ( char * * V_95 )
{
return F_41 ( V_95 ) ;
}
void F_43 ( char * V_108 )
{
F_40 ( V_108 ) ;
}
static enum V_52 F_44 ( char * * V_95 )
{
enum V_52 type ;
for (; ; ) {
type = F_37 ( V_95 ) ;
if ( type != V_91 && type != V_90 )
return type ;
F_40 ( * V_95 ) ;
* V_95 = NULL ;
}
* V_95 = NULL ;
return V_93 ;
}
static int F_45 ( enum V_52 type , enum V_52 V_109 )
{
if ( type != V_109 ) {
F_46 ( L_15 ,
V_109 , type ) ;
return - 1 ;
}
return 0 ;
}
static int F_47 ( enum V_52 type , const char * V_108 ,
enum V_52 V_109 , const char * V_110 )
{
if ( type != V_109 ) {
F_46 ( L_15 ,
V_109 , type ) ;
return - 1 ;
}
if ( strcmp ( V_108 , V_110 ) != 0 ) {
F_46 ( L_16 ,
V_110 , V_108 ) ;
return - 1 ;
}
return 0 ;
}
static int F_48 ( enum V_52 V_109 , char * * V_95 , int V_111 )
{
enum V_52 type ;
if ( V_111 )
type = F_41 ( V_95 ) ;
else
type = F_44 ( V_95 ) ;
return F_45 ( type , V_109 ) ;
}
static int F_49 ( enum V_52 V_109 , char * * V_95 )
{
return F_48 ( V_109 , V_95 , 1 ) ;
}
static int F_50 ( enum V_52 V_109 , const char * V_60 ,
int V_111 )
{
enum V_52 type ;
char * V_108 ;
int V_112 ;
if ( V_111 )
type = F_41 ( & V_108 ) ;
else
type = F_44 ( & V_108 ) ;
V_112 = F_47 ( type , V_108 , V_109 , V_60 ) ;
F_40 ( V_108 ) ;
return V_112 ;
}
static int F_51 ( enum V_52 V_109 , const char * V_60 )
{
return F_50 ( V_109 , V_60 , 1 ) ;
}
static int F_52 ( enum V_52 V_109 , const char * V_60 )
{
return F_50 ( V_109 , V_60 , 0 ) ;
}
static char * F_53 ( void )
{
char * V_108 ;
if ( F_51 ( V_53 , L_17 ) < 0 )
return NULL ;
if ( F_51 ( V_94 , L_18 ) < 0 )
return NULL ;
if ( F_49 ( V_53 , & V_108 ) < 0 )
goto V_113;
return V_108 ;
V_113:
F_40 ( V_108 ) ;
return NULL ;
}
static int F_54 ( void )
{
char * V_108 ;
int V_51 ;
if ( F_52 ( V_53 , L_19 ) < 0 )
return - 1 ;
if ( F_51 ( V_94 , L_18 ) < 0 )
return - 1 ;
if ( F_49 ( V_53 , & V_108 ) < 0 )
goto V_113;
V_51 = strtoul ( V_108 , NULL , 0 ) ;
F_40 ( V_108 ) ;
return V_51 ;
V_113:
F_40 ( V_108 ) ;
return - 1 ;
}
static int F_55 ( struct V_114 * V_66 )
{
if ( ( V_66 -> V_69 & V_115 ) &&
( strstr ( V_66 -> type , L_20 ) || strstr ( V_66 -> type , L_21 ) ||
strstr ( V_66 -> type , L_22 ) ) )
return 1 ;
return 0 ;
}
static int F_56 ( struct V_114 * V_66 )
{
if ( strncmp ( V_66 -> type , L_23 , 10 ) == 0 )
return 1 ;
return 0 ;
}
static int F_57 ( struct V_114 * V_66 )
{
if ( strstr ( V_66 -> type , L_24 ) )
return 1 ;
return 0 ;
}
static int F_58 ( struct V_47 * V_48 , struct V_114 * * V_116 )
{
struct V_114 * V_66 = NULL ;
enum V_52 type ;
char * V_108 ;
char * V_117 ;
int V_118 = 0 ;
do {
type = F_41 ( & V_108 ) ;
if ( type == V_90 ) {
F_40 ( V_108 ) ;
return V_118 ;
}
V_118 ++ ;
if ( F_47 ( type , V_108 , V_53 , L_25 ) )
goto V_113;
F_40 ( V_108 ) ;
type = F_41 ( & V_108 ) ;
if ( V_48 -> V_69 & V_119 &&
type == V_53 && strcmp ( V_108 , L_26 ) == 0 ) {
F_40 ( V_108 ) ;
type = F_41 ( & V_108 ) ;
}
if ( F_47 ( type , V_108 , V_94 , L_18 ) < 0 )
goto V_113;
F_40 ( V_108 ) ;
if ( F_49 ( V_53 , & V_108 ) < 0 )
goto V_113;
V_117 = V_108 ;
V_66 = calloc ( 1 , sizeof( * V_66 ) ) ;
if ( ! V_66 )
goto V_113;
V_66 -> V_48 = V_48 ;
for (; ; ) {
type = F_41 ( & V_108 ) ;
if ( type == V_53 ||
( type == V_94 && strcmp ( V_108 , L_27 ) == 0 ) ||
( V_48 -> V_69 & V_119 &&
type == V_94 && strcmp ( V_108 , L_28 ) == 0 ) ) {
if ( strcmp ( V_108 , L_27 ) == 0 )
V_66 -> V_69 |= V_120 ;
if ( V_66 -> type ) {
char * V_121 ;
V_121 = realloc ( V_66 -> type ,
strlen ( V_66 -> type ) +
strlen ( V_117 ) + 2 ) ;
if ( ! V_121 ) {
free ( V_117 ) ;
goto V_113;
}
V_66 -> type = V_121 ;
strcat ( V_66 -> type , L_29 ) ;
strcat ( V_66 -> type , V_117 ) ;
free ( V_117 ) ;
} else
V_66 -> type = V_117 ;
V_117 = V_108 ;
continue;
}
break;
}
if ( ! V_66 -> type ) {
F_46 ( L_30 , V_122 ) ;
goto V_113;
}
V_66 -> V_67 = V_117 ;
if ( F_45 ( type , V_94 ) )
goto V_113;
if ( strcmp ( V_108 , L_31 ) == 0 ) {
enum V_52 V_123 = type ;
char * V_124 = V_108 ;
char * V_125 ;
int V_126 ;
V_66 -> V_69 |= V_115 ;
type = F_41 ( & V_108 ) ;
if ( type == V_53 )
V_66 -> V_127 = strtoul ( V_108 , NULL , 0 ) ;
else
V_66 -> V_127 = 0 ;
while ( strcmp ( V_108 , L_32 ) != 0 ) {
if ( V_123 == V_53 &&
type == V_53 )
V_126 = 2 ;
else
V_126 = 1 ;
V_123 = type ;
V_125 = realloc ( V_124 ,
strlen ( V_124 ) +
strlen ( V_108 ) + V_126 ) ;
if ( ! V_125 ) {
free ( V_124 ) ;
goto V_113;
}
V_124 = V_125 ;
if ( V_126 == 2 )
strcat ( V_124 , L_29 ) ;
strcat ( V_124 , V_108 ) ;
V_66 -> V_127 = strtoul ( V_108 , NULL , 0 ) ;
F_40 ( V_108 ) ;
type = F_41 ( & V_108 ) ;
if ( type == V_93 ) {
F_46 ( L_33 ) ;
goto V_113;
}
}
F_40 ( V_108 ) ;
V_125 = realloc ( V_124 , strlen ( V_124 ) + 2 ) ;
if ( ! V_125 ) {
free ( V_124 ) ;
goto V_113;
}
V_124 = V_125 ;
strcat ( V_124 , L_32 ) ;
type = F_41 ( & V_108 ) ;
if ( type == V_53 ) {
char * V_121 ;
V_121 = realloc ( V_66 -> type ,
strlen ( V_66 -> type ) +
strlen ( V_66 -> V_67 ) +
strlen ( V_124 ) + 2 ) ;
if ( ! V_121 ) {
free ( V_124 ) ;
goto V_113;
}
V_66 -> type = V_121 ;
strcat ( V_66 -> type , L_29 ) ;
strcat ( V_66 -> type , V_66 -> V_67 ) ;
F_40 ( V_66 -> V_67 ) ;
strcat ( V_66 -> type , V_124 ) ;
V_66 -> V_67 = V_108 ;
type = F_41 ( & V_108 ) ;
} else {
char * V_121 ;
V_121 = realloc ( V_66 -> type ,
strlen ( V_66 -> type ) +
strlen ( V_124 ) + 1 ) ;
if ( ! V_121 ) {
free ( V_124 ) ;
goto V_113;
}
V_66 -> type = V_121 ;
strcat ( V_66 -> type , V_124 ) ;
}
free ( V_124 ) ;
}
if ( F_55 ( V_66 ) )
V_66 -> V_69 |= V_128 ;
if ( F_56 ( V_66 ) )
V_66 -> V_69 |= V_129 ;
if ( F_57 ( V_66 ) )
V_66 -> V_69 |= V_130 ;
if ( F_47 ( type , V_108 , V_94 , L_34 ) )
goto V_113;
F_40 ( V_108 ) ;
if ( F_51 ( V_53 , L_35 ) < 0 )
goto V_131;
if ( F_51 ( V_94 , L_18 ) < 0 )
goto V_131;
if ( F_49 ( V_53 , & V_108 ) )
goto V_113;
V_66 -> V_132 = strtoul ( V_108 , NULL , 0 ) ;
F_40 ( V_108 ) ;
if ( F_51 ( V_94 , L_34 ) < 0 )
goto V_131;
if ( F_51 ( V_53 , L_36 ) < 0 )
goto V_131;
if ( F_51 ( V_94 , L_18 ) < 0 )
goto V_131;
if ( F_49 ( V_53 , & V_108 ) )
goto V_113;
V_66 -> V_2 = strtoul ( V_108 , NULL , 0 ) ;
F_40 ( V_108 ) ;
if ( F_51 ( V_94 , L_34 ) < 0 )
goto V_131;
type = F_41 ( & V_108 ) ;
if ( type != V_90 ) {
if ( F_47 ( type , V_108 , V_53 , L_37 ) )
goto V_113;
F_40 ( V_108 ) ;
if ( F_51 ( V_94 , L_18 ) < 0 )
goto V_131;
if ( F_49 ( V_53 , & V_108 ) )
goto V_113;
F_40 ( V_108 ) ;
if ( F_51 ( V_94 , L_34 ) < 0 )
goto V_131;
if ( F_49 ( V_90 , & V_108 ) )
goto V_113;
}
F_40 ( V_108 ) ;
if ( V_66 -> V_69 & V_115 ) {
if ( V_66 -> V_127 )
V_66 -> V_133 = V_66 -> V_2 / V_66 -> V_127 ;
else if ( V_66 -> V_69 & V_128 )
V_66 -> V_133 = 1 ;
else
V_66 -> V_133 = V_48 -> V_14 -> V_134 ;
} else
V_66 -> V_133 = V_66 -> V_2 ;
* V_116 = V_66 ;
V_116 = & V_66 -> V_22 ;
} while ( 1 );
return 0 ;
V_113:
F_40 ( V_108 ) ;
V_131:
if ( V_66 ) {
free ( V_66 -> type ) ;
free ( V_66 -> V_67 ) ;
free ( V_66 ) ;
}
return - 1 ;
}
static int F_59 ( struct V_47 * V_48 )
{
char * V_108 ;
int V_112 ;
if ( F_52 ( V_53 , L_38 ) < 0 )
return - 1 ;
if ( F_51 ( V_94 , L_18 ) < 0 )
return - 1 ;
if ( F_49 ( V_90 , & V_108 ) )
goto V_113;
F_40 ( V_108 ) ;
V_112 = F_58 ( V_48 , & V_48 -> V_135 . V_136 ) ;
if ( V_112 < 0 )
return V_112 ;
V_48 -> V_135 . V_137 = V_112 ;
V_112 = F_58 ( V_48 , & V_48 -> V_135 . V_116 ) ;
if ( V_112 < 0 )
return V_112 ;
V_48 -> V_135 . V_138 = V_112 ;
return 0 ;
V_113:
F_40 ( V_108 ) ;
return - 1 ;
}
static enum V_52
F_60 ( struct V_47 * V_48 , struct V_7 * V_61 , char * * V_95 )
{
enum V_52 type ;
char * V_108 ;
type = F_41 ( & V_108 ) ;
* V_95 = V_108 ;
return F_61 ( V_48 , V_61 , V_95 , type ) ;
}
static enum V_52
F_62 ( struct V_47 * V_48 , struct V_7 * V_139 , char * * V_95 )
{
struct V_7 * V_61 , * V_85 , * V_86 ;
enum V_52 type ;
char * V_108 = NULL ;
V_61 = F_6 () ;
V_85 = F_6 () ;
V_86 = F_6 () ;
if ( ! V_61 || ! V_85 || ! V_86 ) {
F_46 ( L_39 , V_122 ) ;
F_31 ( V_85 ) ;
F_31 ( V_86 ) ;
goto V_37;
}
V_61 -> type = V_83 ;
V_61 -> V_84 . V_85 = V_85 ;
V_61 -> V_84 . V_86 = V_86 ;
* V_95 = NULL ;
type = F_60 ( V_48 , V_85 , & V_108 ) ;
V_140:
if ( type == V_94 && strcmp ( V_108 , L_18 ) != 0 ) {
type = F_63 ( V_48 , V_85 , & V_108 ) ;
goto V_140;
}
if ( F_47 ( type , V_108 , V_94 , L_18 ) )
goto V_37;
V_61 -> V_84 . V_84 = V_108 ;
type = F_60 ( V_48 , V_86 , & V_108 ) ;
V_139 -> V_84 . V_86 = V_61 ;
* V_95 = V_108 ;
return type ;
V_37:
V_139 -> V_84 . V_86 = NULL ;
F_40 ( V_108 ) ;
F_31 ( V_61 ) ;
return V_55 ;
}
static enum V_52
F_64 ( struct V_47 * V_48 , struct V_7 * V_139 , char * * V_95 )
{
struct V_7 * V_61 ;
enum V_52 type ;
char * V_108 = NULL ;
V_61 = F_6 () ;
if ( ! V_61 ) {
F_46 ( L_39 , V_122 ) ;
* V_95 = NULL ;
return V_55 ;
}
* V_95 = NULL ;
type = F_60 ( V_48 , V_61 , & V_108 ) ;
if ( F_47 ( type , V_108 , V_94 , L_32 ) )
goto V_37;
V_139 -> V_84 . V_86 = V_61 ;
F_40 ( V_108 ) ;
type = F_44 ( & V_108 ) ;
* V_95 = V_108 ;
return type ;
V_37:
F_40 ( V_108 ) ;
F_31 ( V_61 ) ;
return V_55 ;
}
static int F_65 ( char * V_84 )
{
if ( ! V_84 [ 1 ] ) {
switch ( V_84 [ 0 ] ) {
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
F_46 ( L_40 , V_84 [ 0 ] ) ;
return - 1 ;
}
} else {
if ( strcmp ( V_84 , L_41 ) == 0 ||
strcmp ( V_84 , L_42 ) == 0 ) {
return 3 ;
} else if ( strcmp ( V_84 , L_43 ) == 0 ||
strcmp ( V_84 , L_44 ) == 0 ) {
return 8 ;
} else if ( strcmp ( V_84 , L_45 ) == 0 ||
strcmp ( V_84 , L_46 ) == 0 ) {
return 9 ;
} else if ( strcmp ( V_84 , L_47 ) == 0 ||
strcmp ( V_84 , L_48 ) == 0 ) {
return 10 ;
} else if ( strcmp ( V_84 , L_49 ) == 0 ) {
return 14 ;
} else if ( strcmp ( V_84 , L_50 ) == 0 ) {
return 15 ;
} else {
F_46 ( L_51 , V_84 ) ;
return - 1 ;
}
}
}
static int F_66 ( struct V_7 * V_61 )
{
if ( ! V_61 -> V_84 . V_85 || V_61 -> V_84 . V_85 -> type == V_88 )
V_61 -> V_84 . V_141 = 0 ;
else
V_61 -> V_84 . V_141 = F_65 ( V_61 -> V_84 . V_84 ) ;
return V_61 -> V_84 . V_141 ;
}
static enum V_52
F_63 ( struct V_47 * V_48 , struct V_7 * V_61 , char * * V_95 )
{
struct V_7 * V_85 , * V_86 = NULL ;
enum V_52 type ;
char * V_108 ;
V_108 = * V_95 ;
if ( V_61 -> type == V_83 && ! V_61 -> V_84 . V_85 ) {
if ( V_108 [ 1 ] ) {
F_46 ( L_52 , V_108 ) ;
goto V_37;
}
switch ( V_108 [ 0 ] ) {
case '~' :
case '!' :
case '+' :
case '-' :
break;
default:
F_46 ( L_52 , V_108 ) ;
goto V_37;
}
V_85 = F_6 () ;
if ( ! V_85 )
goto V_142;
V_85 -> type = V_88 ;
V_61 -> V_84 . V_85 = V_85 ;
V_86 = F_6 () ;
if ( ! V_86 )
goto V_142;
V_61 -> V_84 . V_86 = V_86 ;
* V_95 = NULL ;
type = F_60 ( V_48 , V_86 , V_95 ) ;
} else if ( strcmp ( V_108 , L_53 ) == 0 ) {
V_85 = F_6 () ;
if ( ! V_85 )
goto V_142;
* V_85 = * V_61 ;
V_61 -> type = V_83 ;
V_61 -> V_84 . V_84 = V_108 ;
V_61 -> V_84 . V_85 = V_85 ;
V_61 -> V_84 . V_141 = 0 ;
type = F_62 ( V_48 , V_61 , V_95 ) ;
} else if ( strcmp ( V_108 , L_43 ) == 0 ||
strcmp ( V_108 , L_44 ) == 0 ||
strcmp ( V_108 , L_54 ) == 0 ||
strcmp ( V_108 , L_55 ) == 0 ||
strcmp ( V_108 , L_49 ) == 0 ||
strcmp ( V_108 , L_50 ) == 0 ||
strcmp ( V_108 , L_56 ) == 0 ||
strcmp ( V_108 , L_57 ) == 0 ||
strcmp ( V_108 , L_27 ) == 0 ||
strcmp ( V_108 , L_58 ) == 0 ||
strcmp ( V_108 , L_59 ) == 0 ||
strcmp ( V_108 , L_60 ) == 0 ||
strcmp ( V_108 , L_61 ) == 0 ||
strcmp ( V_108 , L_47 ) == 0 ||
strcmp ( V_108 , L_48 ) == 0 ) {
V_85 = F_6 () ;
if ( ! V_85 )
goto V_142;
* V_85 = * V_61 ;
V_61 -> type = V_83 ;
V_61 -> V_84 . V_84 = V_108 ;
V_61 -> V_84 . V_85 = V_85 ;
V_61 -> V_84 . V_86 = NULL ;
if ( F_66 ( V_61 ) == - 1 ) {
V_48 -> V_69 |= V_143 ;
V_61 -> V_84 . V_84 = NULL ;
goto V_37;
}
type = F_44 ( & V_108 ) ;
* V_95 = V_108 ;
if ( ( strcmp ( V_61 -> V_84 . V_84 , L_27 ) == 0 ) &&
type == V_56 && ( strcmp ( V_108 , L_62 ) == 0 ) ) {
char * V_144 ;
if ( V_85 -> type != V_63 ) {
F_46 ( L_63 ) ;
goto V_37;
}
V_144 = realloc ( V_85 -> V_64 . V_64 ,
strlen ( V_85 -> V_64 . V_64 ) + 3 ) ;
if ( ! V_144 )
goto V_142;
V_85 -> V_64 . V_64 = V_144 ;
strcat ( V_85 -> V_64 . V_64 , L_64 ) ;
free ( V_61 -> V_84 . V_84 ) ;
* V_61 = * V_85 ;
free ( V_85 ) ;
return type ;
}
V_86 = F_6 () ;
if ( ! V_86 )
goto V_142;
type = F_61 ( V_48 , V_86 , V_95 , type ) ;
V_61 -> V_84 . V_86 = V_86 ;
} else if ( strcmp ( V_108 , L_31 ) == 0 ) {
V_85 = F_6 () ;
if ( ! V_85 )
goto V_142;
* V_85 = * V_61 ;
V_61 -> type = V_83 ;
V_61 -> V_84 . V_84 = V_108 ;
V_61 -> V_84 . V_85 = V_85 ;
V_61 -> V_84 . V_141 = 0 ;
type = F_64 ( V_48 , V_61 , V_95 ) ;
} else {
F_46 ( L_51 , V_108 ) ;
V_48 -> V_69 |= V_143 ;
goto V_37;
}
if ( type == V_94 && strcmp ( * V_95 , L_18 ) != 0 ) {
int V_141 ;
V_141 = F_65 ( * V_95 ) ;
if ( V_141 > V_61 -> V_84 . V_141 )
return F_63 ( V_48 , V_61 , V_95 ) ;
return F_63 ( V_48 , V_86 , V_95 ) ;
}
return type ;
V_142:
F_46 ( L_39 , V_122 ) ;
V_37:
F_40 ( V_108 ) ;
* V_95 = NULL ;
return V_55 ;
}
static enum V_52
F_67 ( struct V_47 * V_48 V_145 , struct V_7 * V_61 ,
char * * V_95 )
{
enum V_52 type ;
char * V_66 ;
char * V_108 ;
if ( F_51 ( V_94 , L_65 ) < 0 )
goto V_146;
if ( F_49 ( V_53 , & V_108 ) < 0 )
goto V_37;
V_66 = V_108 ;
V_61 -> type = V_65 ;
V_61 -> V_66 . V_67 = V_66 ;
if ( V_147 ) {
V_61 -> V_66 . V_66 = F_68 ( V_48 , V_61 -> V_66 . V_67 ) ;
V_61 -> V_66 . V_66 -> V_69 |= V_148 ;
V_147 = 0 ;
} else if ( V_149 ) {
V_61 -> V_66 . V_66 = F_68 ( V_48 , V_61 -> V_66 . V_67 ) ;
V_61 -> V_66 . V_66 -> V_69 |= V_150 ;
V_149 = 0 ;
}
type = F_41 ( & V_108 ) ;
* V_95 = V_108 ;
return type ;
V_37:
F_40 ( V_108 ) ;
V_146:
* V_95 = NULL ;
return V_55 ;
}
static unsigned long long
F_69 ( unsigned long long V_151 , const char * type , int V_152 )
{
int V_153 = 0 ;
char * V_154 ;
int V_126 ;
V_126 = strlen ( type ) ;
if ( V_152 ) {
if ( type [ V_126 - 1 ] != '*' ) {
F_46 ( L_66 ) ;
return V_151 ;
}
V_154 = malloc ( V_126 ) ;
if ( ! V_154 ) {
F_46 ( L_39 , V_122 ) ;
return V_151 ;
}
memcpy ( V_154 , type , V_126 ) ;
V_154 [ V_126 - 2 ] = 0 ;
V_151 = F_69 ( V_151 , V_154 , 0 ) ;
free ( V_154 ) ;
return V_151 ;
}
if ( type [ V_126 - 1 ] == '*' )
return V_151 ;
if ( strncmp ( type , L_67 , 6 ) == 0 )
return V_151 ;
if ( strcmp ( type , L_21 ) == 0 )
return V_151 & 0xff ;
if ( strcmp ( type , L_68 ) == 0 )
return V_151 & 0xffff ;
if ( strcmp ( type , L_69 ) == 0 )
return V_151 & 0xffffffff ;
if ( strcmp ( type , L_70 ) == 0 ||
strcmp ( type , L_71 ) )
return V_151 ;
if ( strcmp ( type , L_22 ) == 0 )
return ( unsigned long long ) ( char ) V_151 & 0xff ;
if ( strcmp ( type , L_72 ) == 0 )
return ( unsigned long long ) ( short ) V_151 & 0xffff ;
if ( strcmp ( type , L_73 ) == 0 )
return ( unsigned long long ) ( int ) V_151 & 0xffffffff ;
if ( strncmp ( type , L_74 , 9 ) == 0 ) {
V_153 = 0 ;
type += 9 ;
}
if ( strcmp ( type , L_20 ) == 0 ) {
if ( V_153 )
return ( unsigned long long ) ( char ) V_151 & 0xff ;
else
return V_151 & 0xff ;
}
if ( strcmp ( type , L_75 ) == 0 ) {
if ( V_153 )
return ( unsigned long long ) ( short ) V_151 & 0xffff ;
else
return V_151 & 0xffff ;
}
if ( strcmp ( type , L_76 ) == 0 ) {
if ( V_153 )
return ( unsigned long long ) ( int ) V_151 & 0xffffffff ;
else
return V_151 & 0xffffffff ;
}
return V_151 ;
}
static unsigned long long
F_70 ( unsigned long long V_151 , struct V_7 * V_61 , int V_152 )
{
if ( V_61 -> type != V_76 ) {
F_46 ( L_77 ) ;
return 0 ;
}
return F_69 ( V_151 , V_61 -> V_77 . type , V_152 ) ;
}
static int F_71 ( struct V_7 * V_61 , long long * V_151 )
{
long long V_85 , V_86 ;
int V_112 = 1 ;
switch ( V_61 -> type ) {
case V_63 :
* V_151 = strtoll ( V_61 -> V_64 . V_64 , NULL , 0 ) ;
break;
case V_76 :
V_112 = F_71 ( V_61 -> V_77 . V_17 , V_151 ) ;
if ( ! V_112 )
break;
* V_151 = F_70 ( * V_151 , V_61 , 0 ) ;
break;
case V_83 :
switch ( V_61 -> V_84 . V_84 [ 0 ] ) {
case '|' :
V_112 = F_71 ( V_61 -> V_84 . V_85 , & V_85 ) ;
if ( ! V_112 )
break;
V_112 = F_71 ( V_61 -> V_84 . V_86 , & V_86 ) ;
if ( ! V_112 )
break;
if ( V_61 -> V_84 . V_84 [ 1 ] )
* V_151 = V_85 || V_86 ;
else
* V_151 = V_85 | V_86 ;
break;
case '&' :
V_112 = F_71 ( V_61 -> V_84 . V_85 , & V_85 ) ;
if ( ! V_112 )
break;
V_112 = F_71 ( V_61 -> V_84 . V_86 , & V_86 ) ;
if ( ! V_112 )
break;
if ( V_61 -> V_84 . V_84 [ 1 ] )
* V_151 = V_85 && V_86 ;
else
* V_151 = V_85 & V_86 ;
break;
case '<' :
V_112 = F_71 ( V_61 -> V_84 . V_85 , & V_85 ) ;
if ( ! V_112 )
break;
V_112 = F_71 ( V_61 -> V_84 . V_86 , & V_86 ) ;
if ( ! V_112 )
break;
switch ( V_61 -> V_84 . V_84 [ 1 ] ) {
case 0 :
* V_151 = V_85 < V_86 ;
break;
case '<' :
* V_151 = V_85 << V_86 ;
break;
case '=' :
* V_151 = V_85 <= V_86 ;
break;
default:
F_46 ( L_51 , V_61 -> V_84 . V_84 ) ;
V_112 = 0 ;
}
break;
case '>' :
V_112 = F_71 ( V_61 -> V_84 . V_85 , & V_85 ) ;
if ( ! V_112 )
break;
V_112 = F_71 ( V_61 -> V_84 . V_86 , & V_86 ) ;
if ( ! V_112 )
break;
switch ( V_61 -> V_84 . V_84 [ 1 ] ) {
case 0 :
* V_151 = V_85 > V_86 ;
break;
case '>' :
* V_151 = V_85 >> V_86 ;
break;
case '=' :
* V_151 = V_85 >= V_86 ;
break;
default:
F_46 ( L_51 , V_61 -> V_84 . V_84 ) ;
V_112 = 0 ;
}
break;
case '=' :
V_112 = F_71 ( V_61 -> V_84 . V_85 , & V_85 ) ;
if ( ! V_112 )
break;
V_112 = F_71 ( V_61 -> V_84 . V_86 , & V_86 ) ;
if ( ! V_112 )
break;
if ( V_61 -> V_84 . V_84 [ 1 ] != '=' ) {
F_46 ( L_51 , V_61 -> V_84 . V_84 ) ;
V_112 = 0 ;
} else
* V_151 = V_85 == V_86 ;
break;
case '!' :
V_112 = F_71 ( V_61 -> V_84 . V_85 , & V_85 ) ;
if ( ! V_112 )
break;
V_112 = F_71 ( V_61 -> V_84 . V_86 , & V_86 ) ;
if ( ! V_112 )
break;
switch ( V_61 -> V_84 . V_84 [ 1 ] ) {
case '=' :
* V_151 = V_85 != V_86 ;
break;
default:
F_46 ( L_51 , V_61 -> V_84 . V_84 ) ;
V_112 = 0 ;
}
break;
case '-' :
if ( V_61 -> V_84 . V_85 -> type == V_88 )
V_85 = 0 ;
else
V_112 = F_71 ( V_61 -> V_84 . V_85 , & V_85 ) ;
if ( ! V_112 )
break;
V_112 = F_71 ( V_61 -> V_84 . V_86 , & V_86 ) ;
if ( ! V_112 )
break;
* V_151 = V_85 - V_86 ;
break;
case '+' :
if ( V_61 -> V_84 . V_85 -> type == V_88 )
V_85 = 0 ;
else
V_112 = F_71 ( V_61 -> V_84 . V_85 , & V_85 ) ;
if ( ! V_112 )
break;
V_112 = F_71 ( V_61 -> V_84 . V_86 , & V_86 ) ;
if ( ! V_112 )
break;
* V_151 = V_85 + V_86 ;
break;
default:
F_46 ( L_51 , V_61 -> V_84 . V_84 ) ;
V_112 = 0 ;
}
break;
case V_88 :
case V_65 ... V_71 :
case V_78 :
case V_79 :
default:
F_46 ( L_78 , V_61 -> type ) ;
V_112 = 0 ;
}
return V_112 ;
}
static char * F_72 ( struct V_7 * V_61 )
{
long long V_151 ;
static char V_1 [ 20 ] ;
switch ( V_61 -> type ) {
case V_63 :
return V_61 -> V_64 . V_64 ;
case V_76 :
return F_72 ( V_61 -> V_77 . V_17 ) ;
case V_83 :
if ( ! F_71 ( V_61 , & V_151 ) )
break;
sprintf ( V_1 , L_79 , V_151 ) ;
return V_1 ;
case V_88 :
case V_65 ... V_71 :
case V_78 :
case V_79 :
default:
F_46 ( L_78 , V_61 -> type ) ;
break;
}
return NULL ;
}
static enum V_52
F_73 ( struct V_47 * V_48 , struct V_57 * * V_155 , char * * V_95 )
{
enum V_52 type ;
struct V_7 * V_61 = NULL ;
struct V_57 * V_66 ;
char * V_108 = * V_95 ;
char * V_59 ;
do {
F_40 ( V_108 ) ;
type = F_44 ( & V_108 ) ;
if ( F_47 ( type , V_108 , V_94 , L_80 ) )
break;
V_61 = F_6 () ;
if ( ! V_61 )
goto V_37;
F_40 ( V_108 ) ;
type = F_60 ( V_48 , V_61 , & V_108 ) ;
if ( type == V_94 )
type = F_63 ( V_48 , V_61 , & V_108 ) ;
if ( type == V_55 )
goto V_37;
if ( F_47 ( type , V_108 , V_56 , L_81 ) )
goto V_37;
V_66 = calloc ( 1 , sizeof( * V_66 ) ) ;
if ( ! V_66 )
goto V_37;
V_59 = F_72 ( V_61 ) ;
if ( V_59 == NULL )
goto V_156;
V_66 -> V_59 = F_12 ( V_59 ) ;
if ( V_66 -> V_59 == NULL )
goto V_156;
F_31 ( V_61 ) ;
V_61 = F_6 () ;
if ( ! V_61 )
goto V_37;
F_40 ( V_108 ) ;
type = F_60 ( V_48 , V_61 , & V_108 ) ;
if ( F_47 ( type , V_108 , V_94 , L_82 ) )
goto V_156;
V_59 = F_72 ( V_61 ) ;
if ( V_59 == NULL )
goto V_156;
V_66 -> V_60 = F_12 ( V_59 ) ;
if ( V_66 -> V_60 == NULL )
goto V_156;
F_31 ( V_61 ) ;
V_61 = NULL ;
* V_155 = V_66 ;
V_155 = & V_66 -> V_22 ;
F_40 ( V_108 ) ;
type = F_44 ( & V_108 ) ;
} while ( type == V_56 && strcmp ( V_108 , L_81 ) == 0 );
* V_95 = V_108 ;
return type ;
V_156:
F_30 ( V_66 ) ;
V_37:
F_31 ( V_61 ) ;
F_40 ( V_108 ) ;
* V_95 = NULL ;
return V_55 ;
}
static enum V_52
F_74 ( struct V_47 * V_48 , struct V_7 * V_61 , char * * V_95 )
{
struct V_7 * V_66 ;
enum V_52 type ;
char * V_108 ;
memset ( V_61 , 0 , sizeof( * V_61 ) ) ;
V_61 -> type = V_68 ;
V_66 = F_6 () ;
if ( ! V_66 ) {
F_46 ( L_39 , V_122 ) ;
goto V_37;
}
type = F_60 ( V_48 , V_66 , & V_108 ) ;
while ( type == V_94 )
type = F_63 ( V_48 , V_66 , & V_108 ) ;
if ( F_47 ( type , V_108 , V_56 , L_81 ) )
goto V_156;
F_40 ( V_108 ) ;
V_61 -> V_69 . V_66 = V_66 ;
type = F_44 ( & V_108 ) ;
if ( F_29 ( type ) ) {
V_61 -> V_69 . V_70 = V_108 ;
type = F_44 ( & V_108 ) ;
}
if ( F_47 ( type , V_108 , V_56 , L_81 ) )
goto V_37;
type = F_73 ( V_48 , & V_61 -> V_69 . V_69 , & V_108 ) ;
if ( F_47 ( type , V_108 , V_56 , L_62 ) )
goto V_37;
F_40 ( V_108 ) ;
type = F_44 ( V_95 ) ;
return type ;
V_156:
F_31 ( V_66 ) ;
V_37:
F_40 ( V_108 ) ;
* V_95 = NULL ;
return V_55 ;
}
static enum V_52
F_75 ( struct V_47 * V_48 , struct V_7 * V_61 , char * * V_95 )
{
struct V_7 * V_66 ;
enum V_52 type ;
char * V_108 ;
memset ( V_61 , 0 , sizeof( * V_61 ) ) ;
V_61 -> type = V_71 ;
V_66 = F_6 () ;
if ( ! V_66 ) {
F_46 ( L_39 , V_122 ) ;
goto V_37;
}
type = F_60 ( V_48 , V_66 , & V_108 ) ;
if ( F_47 ( type , V_108 , V_56 , L_81 ) )
goto V_156;
V_61 -> V_72 . V_66 = V_66 ;
type = F_73 ( V_48 , & V_61 -> V_72 . V_73 , & V_108 ) ;
if ( F_47 ( type , V_108 , V_56 , L_62 ) )
goto V_37;
F_40 ( V_108 ) ;
type = F_44 ( V_95 ) ;
return type ;
V_156:
F_31 ( V_66 ) ;
V_37:
F_40 ( V_108 ) ;
* V_95 = NULL ;
return V_55 ;
}
static enum V_52
F_76 ( struct V_47 * V_48 , struct V_7 * V_61 , char * * V_95 )
{
struct V_7 * V_66 ;
enum V_52 type ;
char * V_108 ;
memset ( V_61 , 0 , sizeof( * V_61 ) ) ;
V_61 -> type = V_74 ;
V_66 = F_6 () ;
if ( ! V_66 ) {
F_46 ( L_39 , V_122 ) ;
goto V_37;
}
type = F_60 ( V_48 , V_66 , & V_108 ) ;
if ( F_47 ( type , V_108 , V_56 , L_81 ) )
goto V_37;
V_61 -> V_75 . V_66 = V_66 ;
F_40 ( V_108 ) ;
V_66 = F_6 () ;
if ( ! V_66 ) {
F_46 ( L_39 , V_122 ) ;
* V_95 = NULL ;
return V_55 ;
}
type = F_60 ( V_48 , V_66 , & V_108 ) ;
if ( F_47 ( type , V_108 , V_56 , L_62 ) )
goto V_37;
V_61 -> V_75 . V_2 = V_66 ;
F_40 ( V_108 ) ;
type = F_44 ( V_95 ) ;
return type ;
V_37:
F_31 ( V_66 ) ;
F_40 ( V_108 ) ;
* V_95 = NULL ;
return V_55 ;
}
static enum V_52
F_77 ( struct V_47 * V_48 , struct V_7 * V_61 , char * * V_95 )
{
struct V_114 * V_66 ;
enum V_52 type ;
char * V_108 ;
memset ( V_61 , 0 , sizeof( * V_61 ) ) ;
V_61 -> type = V_80 ;
type = F_41 ( & V_108 ) ;
* V_95 = V_108 ;
if ( type != V_53 )
goto V_37;
V_66 = F_78 ( V_48 , V_108 ) ;
if ( ! V_66 )
goto V_37;
V_61 -> V_81 . V_66 = V_66 ;
V_61 -> V_81 . V_82 = 0 ;
if ( F_51 ( V_56 , L_62 ) < 0 )
goto V_37;
F_40 ( V_108 ) ;
type = F_44 ( & V_108 ) ;
* V_95 = V_108 ;
if ( type != V_94 || strcmp ( V_108 , L_31 ) != 0 )
return type ;
F_40 ( V_108 ) ;
V_61 = F_6 () ;
if ( ! V_66 ) {
F_46 ( L_39 , V_122 ) ;
* V_95 = NULL ;
return V_55 ;
}
type = F_60 ( V_48 , V_61 , & V_108 ) ;
if ( type == V_55 )
goto V_157;
if ( ! F_47 ( type , V_108 , V_94 , L_32 ) )
goto V_157;
F_40 ( V_108 ) ;
type = F_44 ( V_95 ) ;
return type ;
V_157:
F_31 ( V_61 ) ;
V_37:
F_40 ( V_108 ) ;
* V_95 = NULL ;
return V_55 ;
}
static enum V_52
F_79 ( struct V_47 * V_48 , struct V_7 * V_61 , char * * V_95 )
{
struct V_7 * V_158 ;
enum V_52 type ;
char * V_108 ;
type = F_60 ( V_48 , V_61 , & V_108 ) ;
if ( type == V_55 )
goto V_37;
if ( type == V_94 )
type = F_63 ( V_48 , V_61 , & V_108 ) ;
if ( type == V_55 )
goto V_37;
if ( F_47 ( type , V_108 , V_56 , L_62 ) )
goto V_37;
F_40 ( V_108 ) ;
type = F_44 ( & V_108 ) ;
if ( F_29 ( type ) ||
( type == V_56 && strcmp ( V_108 , L_83 ) == 0 ) ) {
if ( V_61 -> type != V_63 ) {
F_46 ( L_84 ) ;
goto V_37;
}
V_158 = F_6 () ;
if ( ! V_158 ) {
F_46 ( L_39 , V_122 ) ;
goto V_37;
}
V_61 -> type = V_76 ;
V_61 -> V_77 . type = V_61 -> V_64 . V_64 ;
V_61 -> V_77 . V_17 = V_158 ;
type = F_61 ( V_48 , V_158 , & V_108 , type ) ;
}
* V_95 = V_108 ;
return type ;
V_37:
F_40 ( V_108 ) ;
* V_95 = NULL ;
return V_55 ;
}
static enum V_52
F_80 ( struct V_47 * V_48 V_145 , struct V_7 * V_61 ,
char * * V_95 )
{
enum V_52 type ;
char * V_108 ;
if ( F_49 ( V_53 , & V_108 ) < 0 )
goto V_37;
V_61 -> type = V_78 ;
V_61 -> string . string = V_108 ;
V_61 -> string . V_132 = - 1 ;
if ( F_51 ( V_56 , L_62 ) < 0 )
goto V_146;
type = F_41 ( & V_108 ) ;
* V_95 = V_108 ;
return type ;
V_37:
F_40 ( V_108 ) ;
V_146:
* V_95 = NULL ;
return V_55 ;
}
static struct V_159 *
F_81 ( struct V_14 * V_14 , char * V_160 )
{
struct V_159 * V_34 ;
if ( ! V_14 )
return NULL ;
for ( V_34 = V_14 -> V_161 ; V_34 ; V_34 = V_34 -> V_22 ) {
if ( strcmp ( V_34 -> V_67 , V_160 ) == 0 )
break;
}
return V_34 ;
}
static void F_82 ( struct V_14 * V_14 , char * V_160 )
{
struct V_159 * V_34 ;
struct V_159 * * V_22 ;
V_22 = & V_14 -> V_161 ;
while ( ( V_34 = * V_22 ) ) {
if ( strcmp ( V_34 -> V_67 , V_160 ) == 0 ) {
* V_22 = V_34 -> V_22 ;
F_83 ( V_34 ) ;
break;
}
V_22 = & V_34 -> V_22 ;
}
}
static enum V_52
F_84 ( struct V_47 * V_48 , struct V_159 * V_34 ,
struct V_7 * V_61 , char * * V_95 )
{
struct V_7 * * V_162 ;
struct V_7 * V_62 ;
enum V_52 type ;
char * V_108 ;
const char * V_163 ;
int V_19 ;
V_61 -> type = V_87 ;
V_61 -> V_34 . V_34 = V_34 ;
* V_95 = NULL ;
V_162 = & ( V_61 -> V_34 . args ) ;
for ( V_19 = 0 ; V_19 < V_34 -> V_164 ; V_19 ++ ) {
V_62 = F_6 () ;
if ( ! V_62 ) {
F_46 ( L_39 , V_122 ) ;
return V_55 ;
}
type = F_60 ( V_48 , V_62 , & V_108 ) ;
if ( V_19 < ( V_34 -> V_164 - 1 ) )
V_163 = L_81 ;
else
V_163 = L_62 ;
if ( F_47 ( type , V_108 , V_56 , V_163 ) ) {
F_31 ( V_62 ) ;
F_40 ( V_108 ) ;
return V_55 ;
}
* V_162 = V_62 ;
V_162 = & ( V_62 -> V_22 ) ;
F_40 ( V_108 ) ;
}
type = F_41 ( & V_108 ) ;
* V_95 = V_108 ;
return type ;
}
static enum V_52
F_85 ( struct V_47 * V_48 , struct V_7 * V_61 ,
char * V_108 , char * * V_95 )
{
struct V_159 * V_34 ;
if ( strcmp ( V_108 , L_85 ) == 0 ) {
F_40 ( V_108 ) ;
V_147 = 1 ;
return F_74 ( V_48 , V_61 , V_95 ) ;
}
if ( strcmp ( V_108 , L_86 ) == 0 ) {
F_40 ( V_108 ) ;
V_149 = 1 ;
return F_75 ( V_48 , V_61 , V_95 ) ;
}
if ( strcmp ( V_108 , L_87 ) == 0 ) {
F_40 ( V_108 ) ;
return F_76 ( V_48 , V_61 , V_95 ) ;
}
if ( strcmp ( V_108 , L_88 ) == 0 ) {
F_40 ( V_108 ) ;
return F_80 ( V_48 , V_61 , V_95 ) ;
}
if ( strcmp ( V_108 , L_89 ) == 0 ) {
F_40 ( V_108 ) ;
return F_77 ( V_48 , V_61 , V_95 ) ;
}
V_34 = F_81 ( V_48 -> V_14 , V_108 ) ;
if ( V_34 ) {
F_40 ( V_108 ) ;
return F_84 ( V_48 , V_34 , V_61 , V_95 ) ;
}
F_46 ( L_90 , V_108 ) ;
F_40 ( V_108 ) ;
return V_55 ;
}
static enum V_52
F_61 ( struct V_47 * V_48 , struct V_7 * V_61 ,
char * * V_95 , enum V_52 type )
{
char * V_108 ;
char * V_64 ;
V_108 = * V_95 ;
switch ( type ) {
case V_53 :
if ( strcmp ( V_108 , L_91 ) == 0 ) {
F_40 ( V_108 ) ;
type = F_67 ( V_48 , V_61 , & V_108 ) ;
break;
}
V_64 = V_108 ;
type = F_44 ( & V_108 ) ;
if ( type == V_56 && strcmp ( V_108 , L_83 ) == 0 ) {
F_40 ( V_108 ) ;
V_108 = NULL ;
type = F_85 ( V_48 , V_61 , V_64 , & V_108 ) ;
break;
}
while ( type == V_53 ) {
char * V_144 ;
V_144 = realloc ( V_64 ,
strlen ( V_64 ) + strlen ( V_108 ) + 2 ) ;
if ( ! V_144 ) {
free ( V_64 ) ;
* V_95 = NULL ;
F_40 ( V_108 ) ;
return V_55 ;
}
V_64 = V_144 ;
strcat ( V_64 , L_29 ) ;
strcat ( V_64 , V_108 ) ;
F_40 ( V_108 ) ;
type = F_44 ( & V_108 ) ;
}
V_61 -> type = V_63 ;
V_61 -> V_64 . V_64 = V_64 ;
break;
case V_92 :
case V_54 :
V_61 -> type = V_63 ;
V_61 -> V_64 . V_64 = V_108 ;
type = F_44 ( & V_108 ) ;
break;
case V_56 :
if ( strcmp ( V_108 , L_83 ) == 0 ) {
F_40 ( V_108 ) ;
type = F_79 ( V_48 , V_61 , & V_108 ) ;
break;
}
case V_94 :
V_61 -> type = V_83 ;
V_61 -> V_84 . V_84 = V_108 ;
V_61 -> V_84 . V_85 = NULL ;
type = F_63 ( V_48 , V_61 , & V_108 ) ;
if ( type == V_55 )
V_61 -> V_84 . V_84 = NULL ;
break;
case V_55 ... V_90 :
default:
F_46 ( L_92 , type ) ;
return V_55 ;
}
* V_95 = V_108 ;
return type ;
}
static int F_86 ( struct V_47 * V_48 , struct V_7 * * V_155 )
{
enum V_52 type = V_55 ;
struct V_7 * V_61 ;
char * V_108 ;
int args = 0 ;
do {
if ( type == V_90 ) {
type = F_44 ( & V_108 ) ;
continue;
}
V_61 = F_6 () ;
if ( ! V_61 ) {
F_46 ( L_39 , V_122 ) ;
return - 1 ;
}
type = F_60 ( V_48 , V_61 , & V_108 ) ;
if ( type == V_55 ) {
F_40 ( V_108 ) ;
F_31 ( V_61 ) ;
return - 1 ;
}
* V_155 = V_61 ;
args ++ ;
if ( type == V_94 ) {
type = F_63 ( V_48 , V_61 , & V_108 ) ;
F_40 ( V_108 ) ;
if ( type == V_55 ) {
* V_155 = NULL ;
F_31 ( V_61 ) ;
return - 1 ;
}
V_155 = & V_61 -> V_22 ;
continue;
}
if ( type == V_56 && strcmp ( V_108 , L_81 ) == 0 ) {
F_40 ( V_108 ) ;
* V_155 = V_61 ;
V_155 = & V_61 -> V_22 ;
continue;
}
break;
} while ( type != V_93 );
if ( type != V_93 && type != V_55 )
F_40 ( V_108 ) ;
return args ;
}
static int F_87 ( struct V_47 * V_48 )
{
enum V_52 type ;
char * V_108 ;
int V_112 ;
if ( F_52 ( V_53 , L_93 ) < 0 )
return - 1 ;
if ( F_51 ( V_53 , L_94 ) < 0 )
return - 1 ;
if ( F_51 ( V_94 , L_18 ) < 0 )
return - 1 ;
if ( F_49 ( V_92 , & V_108 ) < 0 )
goto V_113;
V_104:
V_48 -> V_165 . V_135 = V_108 ;
V_48 -> V_165 . args = NULL ;
type = F_44 ( & V_108 ) ;
if ( type == V_93 )
return 0 ;
if ( type == V_92 ) {
char * V_166 ;
if ( F_38 ( & V_166 , L_95 , V_48 -> V_165 . V_135 , V_108 ) < 0 )
goto V_113;
F_40 ( V_108 ) ;
F_40 ( V_48 -> V_165 . V_135 ) ;
V_48 -> V_165 . V_135 = NULL ;
V_108 = V_166 ;
goto V_104;
}
if ( F_47 ( type , V_108 , V_56 , L_81 ) )
goto V_113;
F_40 ( V_108 ) ;
V_112 = F_86 ( V_48 , & V_48 -> V_165 . args ) ;
if ( V_112 < 0 )
return - 1 ;
return V_112 ;
V_113:
F_40 ( V_108 ) ;
return - 1 ;
}
struct V_114 *
F_88 ( struct V_47 * V_48 , const char * V_67 )
{
struct V_114 * V_135 ;
for ( V_135 = V_48 -> V_135 . V_136 ;
V_135 ; V_135 = V_135 -> V_22 ) {
if ( strcmp ( V_135 -> V_67 , V_67 ) == 0 )
break;
}
return V_135 ;
}
struct V_114 *
F_78 ( struct V_47 * V_48 , const char * V_67 )
{
struct V_114 * V_135 ;
for ( V_135 = V_48 -> V_135 . V_116 ;
V_135 ; V_135 = V_135 -> V_22 ) {
if ( strcmp ( V_135 -> V_67 , V_67 ) == 0 )
break;
}
return V_135 ;
}
struct V_114 *
F_68 ( struct V_47 * V_48 , const char * V_67 )
{
struct V_114 * V_135 ;
V_135 = F_88 ( V_48 , V_67 ) ;
if ( V_135 )
return V_135 ;
return F_78 ( V_48 , V_67 ) ;
}
unsigned long long F_89 ( struct V_14 * V_14 ,
const void * V_167 , int V_2 )
{
switch ( V_2 ) {
case 1 :
return * ( unsigned char * ) V_167 ;
case 2 :
return F_90 ( V_14 , V_167 ) ;
case 4 :
return F_91 ( V_14 , V_167 ) ;
case 8 :
return F_92 ( V_14 , V_167 ) ;
default:
return 0 ;
}
}
int F_93 ( struct V_114 * V_66 , const void * V_168 ,
unsigned long long * V_59 )
{
if ( ! V_66 )
return - 1 ;
switch ( V_66 -> V_2 ) {
case 1 :
case 2 :
case 4 :
case 8 :
* V_59 = F_89 ( V_66 -> V_48 -> V_14 ,
V_168 + V_66 -> V_132 , V_66 -> V_2 ) ;
return 0 ;
default:
return - 1 ;
}
}
static int F_94 ( struct V_14 * V_14 ,
const char * type , int * V_132 , int * V_2 )
{
struct V_47 * V_48 ;
struct V_114 * V_66 ;
if ( ! V_14 -> V_49 ) {
F_46 ( L_96 ) ;
return - 1 ;
}
V_48 = V_14 -> V_49 [ 0 ] ;
V_66 = F_88 ( V_48 , type ) ;
if ( ! V_66 )
return - 1 ;
* V_132 = V_66 -> V_132 ;
* V_2 = V_66 -> V_2 ;
return 0 ;
}
static int F_95 ( struct V_14 * V_14 , void * V_168 ,
int * V_2 , int * V_132 , const char * V_67 )
{
int V_112 ;
if ( ! * V_2 ) {
V_112 = F_94 ( V_14 , V_67 , V_132 , V_2 ) ;
if ( V_112 < 0 )
return V_112 ;
}
return F_89 ( V_14 , V_168 + * V_132 , * V_2 ) ;
}
static int F_96 ( struct V_14 * V_14 , void * V_168 )
{
return F_95 ( V_14 , V_168 ,
& V_14 -> V_169 , & V_14 -> V_170 ,
L_97 ) ;
}
static int F_97 ( struct V_14 * V_14 , void * V_168 )
{
return F_95 ( V_14 , V_168 ,
& V_14 -> V_171 , & V_14 -> V_172 ,
L_98 ) ;
}
static int F_98 ( struct V_14 * V_14 , void * V_168 )
{
return F_95 ( V_14 , V_168 ,
& V_14 -> V_173 , & V_14 -> V_174 ,
L_99 ) ;
}
static int F_99 ( struct V_14 * V_14 , void * V_168 )
{
return F_95 ( V_14 , V_168 ,
& V_14 -> V_175 , & V_14 -> V_176 ,
L_100 ) ;
}
static int F_100 ( struct V_14 * V_14 , void * V_168 )
{
return F_95 ( V_14 , V_168 ,
& V_14 -> V_177 , & V_14 -> V_178 ,
L_101 ) ;
}
static int F_101 ( struct V_14 * V_14 , void * V_168 )
{
return F_95 ( V_14 , V_168 ,
& V_14 -> V_177 , & V_14 -> V_178 ,
L_102 ) ;
}
struct V_47 * F_102 ( struct V_14 * V_14 , int V_51 )
{
struct V_47 * * V_179 ;
struct V_47 V_23 ;
struct V_47 * V_180 = & V_23 ;
if ( V_14 -> V_181 && V_14 -> V_181 -> V_51 == V_51 )
return V_14 -> V_181 ;
V_23 . V_51 = V_51 ;
V_179 = bsearch ( & V_180 , V_14 -> V_49 , V_14 -> V_50 ,
sizeof( * V_14 -> V_49 ) , V_182 ) ;
if ( V_179 ) {
V_14 -> V_181 = * V_179 ;
return * V_179 ;
}
return NULL ;
}
struct V_47 *
F_103 ( struct V_14 * V_14 ,
const char * V_183 , const char * V_67 )
{
struct V_47 * V_48 ;
int V_19 ;
if ( V_14 -> V_181 &&
strcmp ( V_14 -> V_181 -> V_67 , V_67 ) == 0 &&
( ! V_183 || strcmp ( V_14 -> V_181 -> system , V_183 ) == 0 ) )
return V_14 -> V_181 ;
for ( V_19 = 0 ; V_19 < V_14 -> V_50 ; V_19 ++ ) {
V_48 = V_14 -> V_49 [ V_19 ] ;
if ( strcmp ( V_48 -> V_67 , V_67 ) == 0 ) {
if ( ! V_183 )
break;
if ( strcmp ( V_48 -> system , V_183 ) == 0 )
break;
}
}
if ( V_19 == V_14 -> V_50 )
V_48 = NULL ;
V_14 -> V_181 = V_48 ;
return V_48 ;
}
static unsigned long long
F_104 ( void * V_168 , int V_2 , struct V_47 * V_48 , struct V_7 * V_61 )
{
struct V_14 * V_14 = V_48 -> V_14 ;
unsigned long long V_151 = 0 ;
unsigned long long V_85 , V_86 ;
struct V_7 * V_184 = NULL ;
struct V_7 * V_185 ;
unsigned long V_132 ;
unsigned int V_186 ;
switch ( V_61 -> type ) {
case V_88 :
return 0 ;
case V_63 :
return F_105 ( V_61 -> V_64 . V_64 , NULL , 0 ) ;
case V_65 :
if ( ! V_61 -> V_66 . V_66 ) {
V_61 -> V_66 . V_66 = F_68 ( V_48 , V_61 -> V_66 . V_67 ) ;
if ( ! V_61 -> V_66 . V_66 )
goto V_187;
}
V_151 = F_89 ( V_14 , V_168 + V_61 -> V_66 . V_66 -> V_132 ,
V_61 -> V_66 . V_66 -> V_2 ) ;
break;
case V_68 :
case V_71 :
case V_74 :
break;
case V_76 :
V_151 = F_104 ( V_168 , V_2 , V_48 , V_61 -> V_77 . V_17 ) ;
return F_70 ( V_151 , V_61 , 0 ) ;
case V_78 :
case V_79 :
return 0 ;
case V_87 : {
struct V_188 V_189 ;
F_106 ( & V_189 ) ;
V_151 = F_107 ( & V_189 , V_168 , V_2 , V_48 , V_61 ) ;
F_108 ( & V_189 ) ;
return V_151 ;
}
case V_83 :
if ( strcmp ( V_61 -> V_84 . V_84 , L_31 ) == 0 ) {
V_86 = F_104 ( V_168 , V_2 , V_48 , V_61 -> V_84 . V_86 ) ;
V_185 = V_61 -> V_84 . V_85 ;
while ( V_185 -> type == V_76 ) {
if ( ! V_184 )
V_184 = V_185 ;
V_185 = V_185 -> V_77 . V_17 ;
}
V_186 = V_14 -> V_134 ;
switch ( V_185 -> type ) {
case V_80 :
V_132 = F_89 ( V_14 ,
V_168 + V_185 -> V_81 . V_66 -> V_132 ,
V_185 -> V_81 . V_66 -> V_2 ) ;
if ( V_185 -> V_81 . V_66 -> V_133 )
V_186 = V_185 -> V_81 . V_66 -> V_133 ;
V_132 &= 0xffff ;
V_132 += V_86 ;
break;
case V_65 :
if ( ! V_185 -> V_66 . V_66 ) {
V_185 -> V_66 . V_66 =
F_68 ( V_48 , V_185 -> V_66 . V_67 ) ;
if ( ! V_185 -> V_66 . V_66 ) {
V_61 = V_185 ;
goto V_187;
}
}
V_186 = V_185 -> V_66 . V_66 -> V_133 ;
V_132 = V_185 -> V_66 . V_66 -> V_132 +
V_86 * V_185 -> V_66 . V_66 -> V_133 ;
break;
default:
goto V_190;
}
V_151 = F_89 ( V_14 ,
V_168 + V_132 , V_186 ) ;
if ( V_184 )
V_151 = F_70 ( V_151 , V_184 , 1 ) ;
break;
} else if ( strcmp ( V_61 -> V_84 . V_84 , L_53 ) == 0 ) {
V_85 = F_104 ( V_168 , V_2 , V_48 , V_61 -> V_84 . V_85 ) ;
V_61 = V_61 -> V_84 . V_86 ;
if ( V_85 )
V_151 = F_104 ( V_168 , V_2 , V_48 , V_61 -> V_84 . V_85 ) ;
else
V_151 = F_104 ( V_168 , V_2 , V_48 , V_61 -> V_84 . V_86 ) ;
break;
}
V_190:
V_85 = F_104 ( V_168 , V_2 , V_48 , V_61 -> V_84 . V_85 ) ;
V_86 = F_104 ( V_168 , V_2 , V_48 , V_61 -> V_84 . V_86 ) ;
switch ( V_61 -> V_84 . V_84 [ 0 ] ) {
case '!' :
switch ( V_61 -> V_84 . V_84 [ 1 ] ) {
case 0 :
V_151 = ! V_86 ;
break;
case '=' :
V_151 = V_85 != V_86 ;
break;
default:
goto V_191;
}
break;
case '~' :
V_151 = ~ V_86 ;
break;
case '|' :
if ( V_61 -> V_84 . V_84 [ 1 ] )
V_151 = V_85 || V_86 ;
else
V_151 = V_85 | V_86 ;
break;
case '&' :
if ( V_61 -> V_84 . V_84 [ 1 ] )
V_151 = V_85 && V_86 ;
else
V_151 = V_85 & V_86 ;
break;
case '<' :
switch ( V_61 -> V_84 . V_84 [ 1 ] ) {
case 0 :
V_151 = V_85 < V_86 ;
break;
case '<' :
V_151 = V_85 << V_86 ;
break;
case '=' :
V_151 = V_85 <= V_86 ;
break;
default:
goto V_191;
}
break;
case '>' :
switch ( V_61 -> V_84 . V_84 [ 1 ] ) {
case 0 :
V_151 = V_85 > V_86 ;
break;
case '>' :
V_151 = V_85 >> V_86 ;
break;
case '=' :
V_151 = V_85 >= V_86 ;
break;
default:
goto V_191;
}
break;
case '=' :
if ( V_61 -> V_84 . V_84 [ 1 ] != '=' )
goto V_191;
V_151 = V_85 == V_86 ;
break;
case '-' :
V_151 = V_85 - V_86 ;
break;
case '+' :
V_151 = V_85 + V_86 ;
break;
case '/' :
V_151 = V_85 / V_86 ;
break;
case '*' :
V_151 = V_85 * V_86 ;
break;
default:
goto V_191;
}
break;
default:
return 0 ;
}
return V_151 ;
V_191:
F_46 ( L_103 , V_122 , V_61 -> V_84 . V_84 ) ;
return 0 ;
V_187:
F_46 ( L_104 , V_122 , V_61 -> V_66 . V_67 ) ;
return 0 ;
}
static unsigned long long F_109 ( const char * V_192 )
{
int V_19 ;
if ( isdigit ( V_192 [ 0 ] ) )
return F_105 ( V_192 , NULL , 0 ) ;
for ( V_19 = 0 ; V_19 < ( int ) ( sizeof( V_69 ) / sizeof( V_69 [ 0 ] ) ) ; V_19 ++ )
if ( strcmp ( V_69 [ V_19 ] . V_67 , V_192 ) == 0 )
return V_69 [ V_19 ] . V_59 ;
return 0 ;
}
static void F_110 ( struct V_188 * V_189 , const char * V_135 ,
int V_193 , const char * V_60 )
{
if ( V_193 >= 0 )
F_111 ( V_189 , V_135 , V_193 , V_60 ) ;
else
F_111 ( V_189 , V_135 , V_60 ) ;
}
static void F_112 ( struct V_188 * V_189 , void * V_168 , int V_2 ,
struct V_47 * V_48 , const char * V_135 ,
int V_193 , struct V_7 * V_61 )
{
struct V_14 * V_14 = V_48 -> V_14 ;
struct V_57 * V_192 ;
struct V_114 * V_66 ;
unsigned long long V_151 , V_194 ;
unsigned long V_30 ;
char * V_60 ;
unsigned char * V_75 ;
int V_195 ;
int V_19 , V_126 ;
switch ( V_61 -> type ) {
case V_88 :
return;
case V_63 :
F_110 ( V_189 , V_135 , V_193 , V_61 -> V_64 . V_64 ) ;
return;
case V_65 :
V_66 = V_61 -> V_66 . V_66 ;
if ( ! V_66 ) {
V_66 = F_68 ( V_48 , V_61 -> V_66 . V_67 ) ;
if ( ! V_66 ) {
V_60 = V_61 -> V_66 . V_67 ;
goto V_187;
}
V_61 -> V_66 . V_66 = V_66 ;
}
V_126 = V_66 -> V_2 ? : V_2 - V_66 -> V_132 ;
if ( ! ( V_66 -> V_69 & V_115 ) &&
V_66 -> V_2 == V_14 -> V_134 ) {
V_30 = * ( unsigned long * ) ( V_168 + V_66 -> V_132 ) ;
F_111 ( V_189 , L_105 , V_30 ) ;
break;
}
V_60 = malloc ( V_126 + 1 ) ;
if ( ! V_60 ) {
F_46 ( L_39 , V_122 ) ;
return;
}
memcpy ( V_60 , V_168 + V_66 -> V_132 , V_126 ) ;
V_60 [ V_126 ] = 0 ;
F_110 ( V_189 , V_135 , V_193 , V_60 ) ;
free ( V_60 ) ;
break;
case V_68 :
V_151 = F_104 ( V_168 , V_2 , V_48 , V_61 -> V_69 . V_66 ) ;
V_195 = 0 ;
for ( V_192 = V_61 -> V_69 . V_69 ; V_192 ; V_192 = V_192 -> V_22 ) {
V_194 = F_109 ( V_192 -> V_59 ) ;
if ( ! V_151 && ! V_194 ) {
F_110 ( V_189 , V_135 , V_193 , V_192 -> V_60 ) ;
break;
}
if ( V_194 && ( V_151 & V_194 ) == V_194 ) {
if ( V_195 && V_61 -> V_69 . V_70 )
F_113 ( V_189 , V_61 -> V_69 . V_70 ) ;
F_110 ( V_189 , V_135 , V_193 , V_192 -> V_60 ) ;
V_195 = 1 ;
V_151 &= ~ V_194 ;
}
}
break;
case V_71 :
V_151 = F_104 ( V_168 , V_2 , V_48 , V_61 -> V_72 . V_66 ) ;
for ( V_192 = V_61 -> V_72 . V_73 ; V_192 ; V_192 = V_192 -> V_22 ) {
V_194 = F_109 ( V_192 -> V_59 ) ;
if ( V_151 == V_194 ) {
F_110 ( V_189 , V_135 , V_193 , V_192 -> V_60 ) ;
break;
}
}
break;
case V_74 :
V_66 = V_61 -> V_75 . V_66 -> V_66 . V_66 ;
if ( ! V_66 ) {
V_60 = V_61 -> V_75 . V_66 -> V_66 . V_67 ;
V_66 = F_68 ( V_48 , V_60 ) ;
if ( ! V_66 )
goto V_187;
V_61 -> V_75 . V_66 -> V_66 . V_66 = V_66 ;
}
V_75 = V_168 + V_66 -> V_132 ;
V_126 = F_104 ( V_168 , V_2 , V_48 , V_61 -> V_75 . V_2 ) ;
for ( V_19 = 0 ; V_19 < V_126 ; V_19 ++ ) {
if ( V_19 )
F_114 ( V_189 , ' ' ) ;
F_111 ( V_189 , L_106 , V_75 [ V_19 ] ) ;
}
break;
case V_76 :
break;
case V_78 : {
int V_196 ;
if ( V_61 -> string . V_132 == - 1 ) {
struct V_114 * V_197 ;
V_197 = F_68 ( V_48 , V_61 -> string . string ) ;
V_61 -> string . V_132 = V_197 -> V_132 ;
}
V_196 = F_91 ( V_14 , V_168 + V_61 -> string . V_132 ) ;
V_196 &= 0xffff ;
F_110 ( V_189 , V_135 , V_193 , ( ( char * ) V_168 ) + V_196 ) ;
break;
}
case V_79 :
F_110 ( V_189 , V_135 , V_193 , V_61 -> string . string ) ;
break;
case V_83 :
if ( V_61 -> V_84 . V_84 [ 0 ] != '?' )
return;
V_151 = F_104 ( V_168 , V_2 , V_48 , V_61 -> V_84 . V_85 ) ;
if ( V_151 )
F_112 ( V_189 , V_168 , V_2 , V_48 ,
V_135 , V_193 , V_61 -> V_84 . V_86 -> V_84 . V_85 ) ;
else
F_112 ( V_189 , V_168 , V_2 , V_48 ,
V_135 , V_193 , V_61 -> V_84 . V_86 -> V_84 . V_86 ) ;
break;
case V_87 :
F_107 ( V_189 , V_168 , V_2 , V_48 , V_61 ) ;
break;
default:
break;
}
return;
V_187:
F_46 ( L_104 , V_122 , V_61 -> V_66 . V_67 ) ;
}
static unsigned long long
F_107 ( struct V_188 * V_189 , void * V_168 , int V_2 ,
struct V_47 * V_48 , struct V_7 * V_61 )
{
struct V_159 * V_198 = V_61 -> V_34 . V_34 ;
struct V_199 * V_200 ;
unsigned long long * args ;
unsigned long long V_112 ;
struct V_7 * V_62 ;
struct V_188 V_60 ;
struct V_201 {
struct V_201 * V_22 ;
char * V_60 ;
} * V_202 = NULL , * string ;
int V_19 ;
if ( ! V_198 -> V_164 ) {
V_112 = (* V_198 -> V_34 )( V_189 , NULL ) ;
goto V_103;
}
V_62 = V_61 -> V_34 . args ;
V_200 = V_198 -> V_203 ;
V_112 = V_204 ;
args = malloc ( sizeof( * args ) * V_198 -> V_164 ) ;
if ( ! args )
goto V_103;
for ( V_19 = 0 ; V_19 < V_198 -> V_164 ; V_19 ++ ) {
switch ( V_200 -> type ) {
case V_205 :
case V_206 :
case V_207 :
args [ V_19 ] = F_104 ( V_168 , V_2 , V_48 , V_62 ) ;
break;
case V_208 :
F_106 ( & V_60 ) ;
F_112 ( & V_60 , V_168 , V_2 , V_48 , L_107 , - 1 , V_62 ) ;
F_115 ( & V_60 ) ;
string = malloc ( sizeof( * string ) ) ;
if ( ! string ) {
F_46 ( L_108 , V_122 , __LINE__ ) ;
goto V_37;
}
string -> V_22 = V_202 ;
string -> V_60 = F_12 ( V_60 . V_209 ) ;
if ( ! string -> V_60 ) {
free ( string ) ;
F_46 ( L_108 , V_122 , __LINE__ ) ;
goto V_37;
}
args [ V_19 ] = ( V_210 ) string -> V_60 ;
V_202 = string ;
F_108 ( & V_60 ) ;
break;
default:
F_46 ( L_109 ) ;
goto V_37;
}
V_62 = V_62 -> V_22 ;
V_200 = V_200 -> V_22 ;
}
V_112 = (* V_198 -> V_34 )( V_189 , args ) ;
V_37:
free ( args ) ;
while ( V_202 ) {
string = V_202 ;
V_202 = string -> V_22 ;
free ( string -> V_60 ) ;
free ( string ) ;
}
V_103:
return V_112 ;
}
static void F_116 ( struct V_7 * args )
{
struct V_7 * V_22 ;
while ( args ) {
V_22 = args -> V_22 ;
F_31 ( args ) ;
args = V_22 ;
}
}
static struct V_7 * F_117 ( char * V_46 , void * V_168 , int V_2 , struct V_47 * V_48 )
{
struct V_14 * V_14 = V_48 -> V_14 ;
struct V_114 * V_66 , * V_211 ;
struct V_7 * args , * V_61 , * * V_22 ;
unsigned long long V_212 , V_151 ;
char * V_167 ;
void * V_213 ;
int V_214 ;
V_66 = V_14 -> V_215 ;
V_211 = V_14 -> V_216 ;
if ( ! V_66 ) {
V_66 = F_78 ( V_48 , L_110 ) ;
if ( ! V_66 ) {
F_46 ( L_111 ) ;
return NULL ;
}
V_211 = F_78 ( V_48 , L_112 ) ;
if ( ! V_211 ) {
F_46 ( L_113 ) ;
return NULL ;
}
V_14 -> V_215 = V_66 ;
V_14 -> V_216 = V_211 ;
}
V_212 = F_89 ( V_14 , V_168 + V_211 -> V_132 , V_211 -> V_2 ) ;
args = F_6 () ;
if ( ! args ) {
F_46 ( L_114 , V_122 , __LINE__ ) ;
return NULL ;
}
V_61 = args ;
V_61 -> V_22 = NULL ;
V_22 = & V_61 -> V_22 ;
V_61 -> type = V_63 ;
if ( F_38 ( & V_61 -> V_64 . V_64 , L_79 , V_212 ) < 0 )
goto V_37;
for ( V_167 = V_46 + 6 , V_213 = V_168 + V_66 -> V_132 ;
V_213 < V_168 + V_2 && * V_167 ; V_167 ++ ) {
int V_217 = 0 ;
if ( * V_167 == '%' ) {
V_218:
V_167 ++ ;
switch ( * V_167 ) {
case '%' :
break;
case 'l' :
V_217 ++ ;
goto V_218;
case 'L' :
V_217 = 2 ;
goto V_218;
case '0' ... '9' :
goto V_218;
case '.' :
goto V_218;
case 'p' :
V_217 = 1 ;
case 'd' :
case 'u' :
case 'x' :
case 'i' :
switch ( V_217 ) {
case 0 :
V_214 = 4 ;
break;
case 1 :
V_214 = V_14 -> V_134 ;
break;
case 2 :
V_214 = 8 ;
break;
default:
V_214 = V_217 ;
break;
}
case '*' :
if ( * V_167 == '*' )
V_214 = 4 ;
V_213 = ( void * ) ( ( ( unsigned long ) V_213 + 3 ) &
~ 3 ) ;
V_151 = F_89 ( V_14 , V_213 , V_214 ) ;
V_213 += V_214 ;
V_61 = F_6 () ;
if ( ! V_61 ) {
F_46 ( L_114 ,
V_122 , __LINE__ ) ;
goto V_37;
}
V_61 -> V_22 = NULL ;
V_61 -> type = V_63 ;
if ( F_38 ( & V_61 -> V_64 . V_64 , L_79 , V_151 ) < 0 ) {
free ( V_61 ) ;
goto V_37;
}
* V_22 = V_61 ;
V_22 = & V_61 -> V_22 ;
if ( * V_167 == '*' )
goto V_218;
break;
case 's' :
V_61 = F_6 () ;
if ( ! V_61 ) {
F_46 ( L_114 ,
V_122 , __LINE__ ) ;
goto V_37;
}
V_61 -> V_22 = NULL ;
V_61 -> type = V_79 ;
V_61 -> string . string = F_12 ( V_213 ) ;
if ( ! V_61 -> string . string )
goto V_37;
V_213 += strlen ( V_213 ) + 1 ;
* V_22 = V_61 ;
V_22 = & V_61 -> V_22 ;
default:
break;
}
}
}
return args ;
V_37:
F_116 ( args ) ;
return NULL ;
}
static char *
F_118 ( void * V_168 , int V_2 V_145 ,
struct V_47 * V_48 )
{
struct V_14 * V_14 = V_48 -> V_14 ;
unsigned long long V_30 ;
struct V_114 * V_66 ;
struct V_39 * V_45 ;
char * V_135 ;
char * V_219 ;
V_66 = V_14 -> V_220 ;
if ( ! V_66 ) {
V_66 = F_78 ( V_48 , L_94 ) ;
if ( ! V_66 ) {
F_46 ( L_115 ) ;
return NULL ;
}
V_14 -> V_220 = V_66 ;
}
V_30 = F_89 ( V_14 , V_168 + V_66 -> V_132 , V_66 -> V_2 ) ;
V_45 = F_24 ( V_14 , V_30 ) ;
if ( ! V_45 ) {
if ( F_38 ( & V_135 , L_116 , V_30 ) < 0 )
return NULL ;
return V_135 ;
}
V_219 = V_45 -> V_45 ;
if ( * V_219 == '"' )
V_219 ++ ;
if ( F_38 ( & V_135 , L_117 , L_118 , V_219 ) < 0 )
return NULL ;
V_219 = V_135 + strlen ( V_135 ) - 1 ;
if ( * V_219 == '"' )
* V_219 = 0 ;
V_219 -= 2 ;
if ( strcmp ( V_219 , L_119 ) == 0 )
* V_219 = 0 ;
return V_135 ;
}
static void F_119 ( struct V_188 * V_189 , int V_221 , void * V_168 , int V_2 ,
struct V_47 * V_48 , struct V_7 * V_61 )
{
unsigned char * V_1 ;
const char * V_46 = L_120 ;
if ( V_61 -> type == V_87 ) {
F_107 ( V_189 , V_168 , V_2 , V_48 , V_61 ) ;
return;
}
if ( V_61 -> type != V_65 ) {
F_111 ( V_189 , L_121 ,
V_61 -> type ) ;
return;
}
if ( V_221 == 'm' )
V_46 = L_122 ;
if ( ! V_61 -> V_66 . V_66 ) {
V_61 -> V_66 . V_66 =
F_68 ( V_48 , V_61 -> V_66 . V_67 ) ;
if ( ! V_61 -> V_66 . V_66 ) {
F_46 ( L_104 ,
V_122 , V_61 -> V_66 . V_67 ) ;
return;
}
}
if ( V_61 -> V_66 . V_66 -> V_2 != 6 ) {
F_111 ( V_189 , L_123 ) ;
return;
}
V_1 = V_168 + V_61 -> V_66 . V_66 -> V_132 ;
F_111 ( V_189 , V_46 , V_1 [ 0 ] , V_1 [ 1 ] , V_1 [ 2 ] , V_1 [ 3 ] , V_1 [ 4 ] , V_1 [ 5 ] ) ;
}
static int F_120 ( char * V_219 , unsigned int V_126 )
{
unsigned int V_19 ;
for ( V_19 = 0 ; V_19 < V_126 && V_219 [ V_19 ] ; V_19 ++ )
if ( ! isprint ( V_219 [ V_19 ] ) )
return 0 ;
return 1 ;
}
static void F_121 ( struct V_188 * V_189 , void * V_168 ,
int V_2 V_145 ,
struct V_47 * V_48 )
{
struct V_114 * V_66 ;
unsigned long long V_151 ;
unsigned int V_132 , V_126 , V_19 ;
V_66 = V_48 -> V_135 . V_116 ;
while ( V_66 ) {
F_111 ( V_189 , L_124 , V_66 -> V_67 ) ;
if ( V_66 -> V_69 & V_115 ) {
V_132 = V_66 -> V_132 ;
V_126 = V_66 -> V_2 ;
if ( V_66 -> V_69 & V_129 ) {
V_151 = F_89 ( V_48 -> V_14 , V_168 + V_132 , V_126 ) ;
V_132 = V_151 ;
V_126 = V_132 >> 16 ;
V_132 &= 0xffff ;
}
if ( V_66 -> V_69 & V_128 &&
F_120 ( V_168 + V_132 , V_126 ) ) {
F_111 ( V_189 , L_107 , ( char * ) V_168 + V_132 ) ;
} else {
F_113 ( V_189 , L_125 ) ;
for ( V_19 = 0 ; V_19 < V_126 ; V_19 ++ ) {
if ( V_19 )
F_113 ( V_189 , L_126 ) ;
F_111 ( V_189 , L_106 ,
* ( ( unsigned char * ) V_168 + V_132 + V_19 ) ) ;
}
F_114 ( V_189 , ']' ) ;
V_66 -> V_69 &= ~ V_128 ;
}
} else {
V_151 = F_89 ( V_48 -> V_14 , V_168 + V_66 -> V_132 ,
V_66 -> V_2 ) ;
if ( V_66 -> V_69 & V_120 ) {
F_111 ( V_189 , L_127 , V_151 ) ;
} else if ( V_66 -> V_69 & V_222 ) {
switch ( V_66 -> V_2 ) {
case 4 :
if ( V_66 -> V_69 & V_130 )
F_111 ( V_189 , L_128 , ( int ) V_151 ) ;
else
F_111 ( V_189 , L_129 , ( int ) V_151 ) ;
break;
case 2 :
F_111 ( V_189 , L_130 , ( short ) V_151 ) ;
break;
case 1 :
F_111 ( V_189 , L_131 , ( char ) V_151 ) ;
break;
default:
F_111 ( V_189 , L_79 , V_151 ) ;
}
} else {
if ( V_66 -> V_69 & V_130 )
F_111 ( V_189 , L_127 , V_151 ) ;
else
F_111 ( V_189 , L_132 , V_151 ) ;
}
}
V_66 = V_66 -> V_22 ;
}
}
static void F_122 ( struct V_188 * V_189 , void * V_168 , int V_2 , struct V_47 * V_48 )
{
struct V_14 * V_14 = V_48 -> V_14 ;
struct V_165 * V_165 = & V_48 -> V_165 ;
struct V_7 * V_61 = V_165 -> args ;
struct V_7 * args = NULL ;
const char * V_167 = V_165 -> V_135 ;
unsigned long long V_151 ;
struct V_27 * V_34 ;
const char * V_223 ;
char * V_224 = NULL ;
char V_135 [ 32 ] ;
int V_225 ;
int V_226 ;
int V_193 ;
int V_126 ;
int V_217 ;
if ( V_48 -> V_69 & V_143 ) {
F_111 ( V_189 , L_133 ) ;
F_121 ( V_189 , V_168 , V_2 , V_48 ) ;
return;
}
if ( V_48 -> V_69 & V_227 ) {
V_224 = F_118 ( V_168 , V_2 , V_48 ) ;
args = F_117 ( V_224 , V_168 , V_2 , V_48 ) ;
V_61 = args ;
V_167 = V_224 ;
}
for (; * V_167 ; V_167 ++ ) {
V_217 = 0 ;
if ( * V_167 == '\\' ) {
V_167 ++ ;
switch ( * V_167 ) {
case 'n' :
F_114 ( V_189 , '\n' ) ;
break;
case 't' :
F_114 ( V_189 , '\t' ) ;
break;
case 'r' :
F_114 ( V_189 , '\r' ) ;
break;
case '\\' :
F_114 ( V_189 , '\\' ) ;
break;
default:
F_114 ( V_189 , * V_167 ) ;
break;
}
} else if ( * V_167 == '%' ) {
V_223 = V_167 ;
V_225 = 0 ;
V_226 = 0 ;
V_228:
V_167 ++ ;
switch ( * V_167 ) {
case '%' :
F_114 ( V_189 , '%' ) ;
break;
case '#' :
goto V_228;
case 'h' :
V_217 -- ;
goto V_228;
case 'l' :
V_217 ++ ;
goto V_228;
case 'L' :
V_217 = 2 ;
goto V_228;
case '*' :
if ( ! V_61 ) {
F_46 ( L_134 ) ;
V_48 -> V_69 |= V_143 ;
goto V_229;
}
V_193 = F_104 ( V_168 , V_2 , V_48 , V_61 ) ;
V_226 = 1 ;
V_61 = V_61 -> V_22 ;
goto V_228;
case '.' :
case 'z' :
case 'Z' :
case '0' ... '9' :
goto V_228;
case 'p' :
if ( V_14 -> V_134 == 4 )
V_217 = 1 ;
else
V_217 = 2 ;
if ( * ( V_167 + 1 ) == 'F' ||
* ( V_167 + 1 ) == 'f' ) {
V_167 ++ ;
V_225 = * V_167 ;
} else if ( * ( V_167 + 1 ) == 'M' || * ( V_167 + 1 ) == 'm' ) {
F_119 ( V_189 , * ( V_167 + 1 ) , V_168 , V_2 , V_48 , V_61 ) ;
V_167 ++ ;
V_61 = V_61 -> V_22 ;
break;
}
case 'd' :
case 'i' :
case 'x' :
case 'X' :
case 'u' :
if ( ! V_61 ) {
F_46 ( L_134 ) ;
V_48 -> V_69 |= V_143 ;
goto V_229;
}
V_126 = ( ( unsigned long ) V_167 + 1 ) -
( unsigned long ) V_223 ;
if ( V_126 > 31 ) {
F_46 ( L_135 ) ;
V_48 -> V_69 |= V_143 ;
V_126 = 31 ;
}
memcpy ( V_135 , V_223 , V_126 ) ;
V_135 [ V_126 ] = 0 ;
V_151 = F_104 ( V_168 , V_2 , V_48 , V_61 ) ;
V_61 = V_61 -> V_22 ;
if ( V_225 ) {
V_34 = F_17 ( V_14 , V_151 ) ;
if ( V_34 ) {
F_113 ( V_189 , V_34 -> V_34 ) ;
if ( V_225 == 'F' )
F_111 ( V_189 ,
L_136 ,
V_151 - V_34 -> V_30 ) ;
break;
}
}
if ( V_14 -> V_134 == 8 && V_217 &&
sizeof( long ) != 8 ) {
char * V_219 ;
V_217 = 2 ;
V_219 = strchr ( V_135 , 'l' ) ;
if ( V_219 )
memmove ( V_219 + 1 , V_219 , strlen ( V_219 ) + 1 ) ;
else if ( strcmp ( V_135 , L_137 ) == 0 )
strcpy ( V_135 , L_127 ) ;
}
switch ( V_217 ) {
case - 2 :
if ( V_226 )
F_111 ( V_189 , V_135 , V_193 , ( char ) V_151 ) ;
else
F_111 ( V_189 , V_135 , ( char ) V_151 ) ;
break;
case - 1 :
if ( V_226 )
F_111 ( V_189 , V_135 , V_193 , ( short ) V_151 ) ;
else
F_111 ( V_189 , V_135 , ( short ) V_151 ) ;
break;
case 0 :
if ( V_226 )
F_111 ( V_189 , V_135 , V_193 , ( int ) V_151 ) ;
else
F_111 ( V_189 , V_135 , ( int ) V_151 ) ;
break;
case 1 :
if ( V_226 )
F_111 ( V_189 , V_135 , V_193 , ( long ) V_151 ) ;
else
F_111 ( V_189 , V_135 , ( long ) V_151 ) ;
break;
case 2 :
if ( V_226 )
F_111 ( V_189 , V_135 , V_193 ,
( long long ) V_151 ) ;
else
F_111 ( V_189 , V_135 , ( long long ) V_151 ) ;
break;
default:
F_46 ( L_138 , V_217 ) ;
V_48 -> V_69 |= V_143 ;
}
break;
case 's' :
if ( ! V_61 ) {
F_46 ( L_139 ) ;
V_48 -> V_69 |= V_143 ;
goto V_229;
}
V_126 = ( ( unsigned long ) V_167 + 1 ) -
( unsigned long ) V_223 ;
if ( V_126 > 31 ) {
F_46 ( L_135 ) ;
V_48 -> V_69 |= V_143 ;
V_126 = 31 ;
}
memcpy ( V_135 , V_223 , V_126 ) ;
V_135 [ V_126 ] = 0 ;
if ( ! V_226 )
V_193 = - 1 ;
F_112 ( V_189 , V_168 , V_2 , V_48 ,
V_135 , V_193 , V_61 ) ;
V_61 = V_61 -> V_22 ;
break;
default:
F_111 ( V_189 , L_140 , * V_167 ) ;
}
} else
F_114 ( V_189 , * V_167 ) ;
}
if ( V_48 -> V_69 & V_143 ) {
V_229:
F_111 ( V_189 , L_133 ) ;
}
if ( args ) {
F_116 ( args ) ;
free ( V_224 ) ;
}
}
void F_123 ( struct V_14 * V_14 ,
struct V_188 * V_189 , struct V_230 * V_231 )
{
static int V_232 = 1 ;
static int V_233 = 1 ;
static int V_234 ;
static int V_235 ;
unsigned int V_236 ;
unsigned int V_237 ;
int V_238 ;
int V_239 ;
int V_240 ;
int V_241 ;
void * V_168 = V_231 -> V_168 ;
V_236 = F_99 ( V_14 , V_168 ) ;
V_237 = F_98 ( V_14 , V_168 ) ;
if ( V_234 )
V_238 = F_100 ( V_14 , V_168 ) ;
else if ( V_232 ) {
V_238 = F_100 ( V_14 , V_168 ) ;
if ( V_238 < 0 )
V_232 = 0 ;
else
V_234 = 1 ;
}
if ( V_235 )
V_239 = F_101 ( V_14 , V_168 ) ;
else if ( V_233 ) {
V_239 = F_101 ( V_14 , V_168 ) ;
if ( V_239 < 0 )
V_233 = 0 ;
else
V_235 = 1 ;
}
V_240 = V_236 & V_242 ;
V_241 = V_236 & V_243 ;
F_111 ( V_189 , L_141 ,
( V_236 & V_244 ) ? 'd' :
( V_236 & V_245 ) ?
'X' : '.' ,
( V_236 & V_246 ) ?
'N' : '.' ,
( V_240 && V_241 ) ? 'H' :
V_240 ? 'h' : V_241 ? 's' : '.' ) ;
if ( V_237 )
F_111 ( V_189 , L_142 , V_237 ) ;
else
F_114 ( V_189 , '.' ) ;
if ( V_235 ) {
if ( V_239 < 0 )
F_114 ( V_189 , '.' ) ;
else
F_111 ( V_189 , L_129 , V_239 ) ;
}
if ( V_234 ) {
if ( V_238 < 0 )
F_114 ( V_189 , '.' ) ;
else
F_111 ( V_189 , L_129 , V_238 ) ;
}
F_115 ( V_189 ) ;
}
int F_124 ( struct V_14 * V_14 , struct V_230 * V_247 )
{
return F_96 ( V_14 , V_247 -> V_168 ) ;
}
struct V_47 * F_125 ( struct V_14 * V_14 , int type )
{
return F_102 ( V_14 , type ) ;
}
int F_126 ( struct V_14 * V_14 , struct V_230 * V_247 )
{
return F_97 ( V_14 , V_247 -> V_168 ) ;
}
const char * F_127 ( struct V_14 * V_14 , int V_13 )
{
const char * V_21 ;
V_21 = F_9 ( V_14 , V_13 ) ;
return V_21 ;
}
void F_128 ( struct V_188 * V_189 , struct V_47 * V_48 ,
struct V_230 * V_231 )
{
int V_248 = 1 ;
if ( V_48 -> V_14 -> V_249 )
F_121 ( V_189 , V_231 -> V_168 , V_231 -> V_2 , V_48 ) ;
else {
if ( V_48 -> V_250 )
V_248 = V_48 -> V_250 ( V_189 , V_231 , V_48 ,
V_48 -> V_251 ) ;
if ( V_248 )
F_122 ( V_189 , V_231 -> V_168 , V_231 -> V_2 , V_48 ) ;
}
F_115 ( V_189 ) ;
}
void F_129 ( struct V_14 * V_14 , struct V_188 * V_189 ,
struct V_230 * V_231 )
{
static const char * V_252 = L_143 ;
struct V_47 * V_48 ;
unsigned long V_253 ;
unsigned long V_254 ;
unsigned long V_255 ;
const char * V_21 ;
void * V_168 = V_231 -> V_168 ;
int type ;
int V_13 ;
int V_126 ;
int V_219 ;
V_253 = V_231 -> V_256 / V_257 ;
V_255 = V_231 -> V_256 - V_253 * V_257 ;
if ( V_231 -> V_2 < 0 ) {
F_46 ( L_144 , V_231 -> V_2 ) ;
return;
}
type = F_96 ( V_14 , V_168 ) ;
V_48 = F_102 ( V_14 , type ) ;
if ( ! V_48 ) {
F_46 ( L_145 , type ) ;
return;
}
V_13 = F_97 ( V_14 , V_168 ) ;
V_21 = F_9 ( V_14 , V_13 ) ;
if ( V_14 -> V_258 ) {
F_111 ( V_189 , L_146 ,
V_21 , V_13 , V_231 -> V_259 ) ;
F_123 ( V_14 , V_189 , V_231 ) ;
} else
F_111 ( V_189 , L_147 , V_21 , V_13 , V_231 -> V_259 ) ;
if ( V_14 -> V_69 & V_260 ) {
V_254 = V_255 ;
V_219 = 9 ;
} else {
V_254 = ( V_255 + 500 ) / V_261 ;
V_219 = 6 ;
}
F_111 ( V_189 , L_148 , V_253 , V_219 , V_254 , V_48 -> V_67 ) ;
V_126 = strlen ( V_48 -> V_67 ) ;
if ( V_126 < 20 )
F_111 ( V_189 , L_149 , 20 - V_126 , V_252 ) ;
F_128 ( V_189 , V_48 , V_231 ) ;
}
static int V_182 ( const void * V_8 , const void * V_9 )
{
struct V_47 * const * V_262 = V_8 ;
struct V_47 * const * V_263 = V_9 ;
if ( ( * V_262 ) -> V_51 < ( * V_263 ) -> V_51 )
return - 1 ;
if ( ( * V_262 ) -> V_51 > ( * V_263 ) -> V_51 )
return 1 ;
return 0 ;
}
static int F_130 ( const void * V_8 , const void * V_9 )
{
struct V_47 * const * V_262 = V_8 ;
struct V_47 * const * V_263 = V_9 ;
int V_264 ;
V_264 = strcmp ( ( * V_262 ) -> V_67 , ( * V_263 ) -> V_67 ) ;
if ( V_264 )
return V_264 ;
V_264 = strcmp ( ( * V_262 ) -> system , ( * V_263 ) -> system ) ;
if ( V_264 )
return V_264 ;
return V_182 ( V_8 , V_9 ) ;
}
static int F_131 ( const void * V_8 , const void * V_9 )
{
struct V_47 * const * V_262 = V_8 ;
struct V_47 * const * V_263 = V_9 ;
int V_264 ;
V_264 = strcmp ( ( * V_262 ) -> system , ( * V_263 ) -> system ) ;
if ( V_264 )
return V_264 ;
V_264 = strcmp ( ( * V_262 ) -> V_67 , ( * V_263 ) -> V_67 ) ;
if ( V_264 )
return V_264 ;
return V_182 ( V_8 , V_9 ) ;
}
struct V_47 * * F_132 ( struct V_14 * V_14 , enum V_265 V_266 )
{
struct V_47 * * V_49 ;
int (* F_133)( const void * V_8 , const void * V_9 );
V_49 = V_14 -> V_267 ;
if ( V_49 && V_14 -> V_123 == V_266 )
return V_49 ;
if ( ! V_49 ) {
V_49 = malloc ( sizeof( * V_49 ) * ( V_14 -> V_50 + 1 ) ) ;
if ( ! V_49 )
return NULL ;
memcpy ( V_49 , V_14 -> V_49 , sizeof( * V_49 ) * V_14 -> V_50 ) ;
V_49 [ V_14 -> V_50 ] = NULL ;
V_14 -> V_267 = V_49 ;
if ( V_266 == V_268 ) {
V_14 -> V_123 = V_266 ;
return V_49 ;
}
}
switch ( V_266 ) {
case V_268 :
F_133 = V_182 ;
break;
case V_269 :
F_133 = F_130 ;
break;
case V_270 :
F_133 = F_131 ;
break;
default:
return V_49 ;
}
qsort ( V_49 , V_14 -> V_50 , sizeof( * V_49 ) , F_133 ) ;
V_14 -> V_123 = V_266 ;
return V_49 ;
}
static struct V_114 * *
F_134 ( const char * type , const char * V_67 ,
int V_118 , struct V_114 * V_155 )
{
struct V_114 * * V_116 ;
struct V_114 * V_66 ;
int V_19 = 0 ;
V_116 = malloc ( sizeof( * V_116 ) * ( V_118 + 1 ) ) ;
if ( ! V_116 )
return NULL ;
for ( V_66 = V_155 ; V_66 ; V_66 = V_66 -> V_22 ) {
V_116 [ V_19 ++ ] = V_66 ;
if ( V_19 == V_118 + 1 ) {
F_46 ( L_150 ,
V_67 , type ) ;
V_19 -- ;
break;
}
}
if ( V_19 != V_118 )
F_46 ( L_151 ,
V_67 , type ) ;
V_116 [ V_19 ] = NULL ;
return V_116 ;
}
struct V_114 * * F_135 ( struct V_47 * V_48 )
{
return F_134 ( L_152 , V_48 -> V_67 ,
V_48 -> V_135 . V_137 ,
V_48 -> V_135 . V_136 ) ;
}
struct V_114 * * F_136 ( struct V_47 * V_48 )
{
return F_134 ( L_153 , V_48 -> V_67 ,
V_48 -> V_135 . V_138 ,
V_48 -> V_135 . V_116 ) ;
}
static void F_137 ( struct V_188 * V_189 , struct V_57 * V_66 )
{
F_111 ( V_189 , L_154 , V_66 -> V_59 , V_66 -> V_60 ) ;
if ( V_66 -> V_22 ) {
F_113 ( V_189 , L_126 ) ;
F_137 ( V_189 , V_66 -> V_22 ) ;
}
}
static void F_138 ( struct V_7 * args )
{
int V_271 = 1 ;
struct V_188 V_189 ;
switch ( args -> type ) {
case V_88 :
printf ( L_155 ) ;
break;
case V_63 :
printf ( L_107 , args -> V_64 . V_64 ) ;
break;
case V_65 :
printf ( L_156 , args -> V_66 . V_67 ) ;
break;
case V_68 :
printf ( L_157 ) ;
F_138 ( args -> V_69 . V_66 ) ;
printf ( L_158 , args -> V_69 . V_70 ) ;
F_106 ( & V_189 ) ;
F_137 ( & V_189 , args -> V_69 . V_69 ) ;
F_139 ( & V_189 ) ;
F_108 ( & V_189 ) ;
printf ( L_62 ) ;
break;
case V_71 :
printf ( L_159 ) ;
F_138 ( args -> V_72 . V_66 ) ;
printf ( L_126 ) ;
F_106 ( & V_189 ) ;
F_137 ( & V_189 , args -> V_72 . V_73 ) ;
F_139 ( & V_189 ) ;
F_108 ( & V_189 ) ;
printf ( L_62 ) ;
break;
case V_74 :
printf ( L_160 ) ;
F_138 ( args -> V_75 . V_66 ) ;
printf ( L_126 ) ;
F_138 ( args -> V_75 . V_2 ) ;
printf ( L_62 ) ;
break;
case V_78 :
case V_79 :
printf ( L_161 , args -> string . string ) ;
break;
case V_76 :
printf ( L_162 , args -> V_77 . type ) ;
F_138 ( args -> V_77 . V_17 ) ;
break;
case V_83 :
if ( strcmp ( args -> V_84 . V_84 , L_18 ) == 0 )
V_271 = 0 ;
if ( V_271 )
printf ( L_83 ) ;
F_138 ( args -> V_84 . V_85 ) ;
printf ( L_163 , args -> V_84 . V_84 ) ;
F_138 ( args -> V_84 . V_86 ) ;
if ( V_271 )
printf ( L_62 ) ;
break;
default:
return;
}
if ( args -> V_22 ) {
printf ( L_6 ) ;
F_138 ( args -> V_22 ) ;
}
}
static void F_140 ( const char * V_66 ,
int * V_132 , int * V_2 , int V_272 )
{
unsigned long long V_105 ;
unsigned long long V_107 ;
char * V_108 ;
int type ;
V_105 = V_5 ;
V_107 = V_4 ;
if ( F_51 ( V_53 , L_25 ) < 0 )
return;
if ( F_51 ( V_94 , L_18 ) < 0 )
return;
if ( F_49 ( V_53 , & V_108 ) < 0 )
goto V_113;
F_40 ( V_108 ) ;
if ( V_272 ) {
if ( F_51 ( V_53 , V_66 ) < 0 )
return;
} else {
if ( F_49 ( V_53 , & V_108 ) < 0 )
goto V_113;
if ( strcmp ( V_108 , V_66 ) != 0 )
goto V_273;
F_40 ( V_108 ) ;
}
if ( F_51 ( V_94 , L_34 ) < 0 )
return;
if ( F_51 ( V_53 , L_35 ) < 0 )
return;
if ( F_51 ( V_94 , L_18 ) < 0 )
return;
if ( F_49 ( V_53 , & V_108 ) < 0 )
goto V_113;
* V_132 = atoi ( V_108 ) ;
F_40 ( V_108 ) ;
if ( F_51 ( V_94 , L_34 ) < 0 )
return;
if ( F_51 ( V_53 , L_36 ) < 0 )
return;
if ( F_51 ( V_94 , L_18 ) < 0 )
return;
if ( F_49 ( V_53 , & V_108 ) < 0 )
goto V_113;
* V_2 = atoi ( V_108 ) ;
F_40 ( V_108 ) ;
if ( F_51 ( V_94 , L_34 ) < 0 )
return;
type = F_41 ( & V_108 ) ;
if ( type != V_90 ) {
if ( type != V_53 )
goto V_113;
if ( strcmp ( V_108 , L_37 ) != 0 )
goto V_113;
F_40 ( V_108 ) ;
if ( F_51 ( V_94 , L_18 ) < 0 )
return;
if ( F_49 ( V_53 , & V_108 ) )
goto V_113;
F_40 ( V_108 ) ;
if ( F_51 ( V_94 , L_34 ) < 0 )
return;
if ( F_49 ( V_90 , & V_108 ) )
goto V_113;
}
V_113:
F_40 ( V_108 ) ;
return;
V_273:
V_5 = V_105 ;
V_4 = V_107 ;
* V_132 = 0 ;
* V_2 = 0 ;
F_40 ( V_108 ) ;
}
int F_141 ( struct V_14 * V_14 , char * V_1 , unsigned long V_2 ,
int V_134 )
{
int V_274 ;
if ( ! V_2 ) {
V_14 -> V_275 = sizeof( long long ) ;
V_14 -> V_276 = V_134 ;
V_14 -> V_277 = sizeof( long long ) + V_134 ;
V_14 -> V_278 = 1 ;
return - 1 ;
}
F_1 ( V_1 , V_2 ) ;
F_140 ( L_164 , & V_14 -> V_279 ,
& V_14 -> V_275 , 1 ) ;
F_140 ( L_165 , & V_14 -> V_280 ,
& V_14 -> V_276 , 1 ) ;
F_140 ( L_166 , & V_14 -> V_281 ,
& V_274 , 0 ) ;
F_140 ( L_167 , & V_14 -> V_277 ,
& V_14 -> V_282 , 1 ) ;
return 0 ;
}
static int F_142 ( struct V_47 * V_48 ,
int V_51 , const char * V_283 ,
const char * V_284 )
{
if ( V_51 >= 0 && V_51 != V_48 -> V_51 )
return 0 ;
if ( V_284 && ( strcmp ( V_284 , V_48 -> V_67 ) != 0 ) )
return 0 ;
if ( V_283 && ( strcmp ( V_283 , V_48 -> system ) != 0 ) )
return 0 ;
return 1 ;
}
static void F_143 ( struct V_285 * V_286 )
{
free ( ( void * ) V_286 -> V_283 ) ;
free ( ( void * ) V_286 -> V_284 ) ;
free ( V_286 ) ;
}
static int F_144 ( struct V_14 * V_14 , struct V_47 * V_48 )
{
struct V_285 * V_286 , * * V_22 ;
for ( V_22 = & V_14 -> V_287 ; * V_22 ;
V_22 = & ( * V_22 ) -> V_22 ) {
V_286 = * V_22 ;
if ( F_142 ( V_48 , V_286 -> V_51 ,
V_286 -> V_283 ,
V_286 -> V_284 ) )
break;
}
if ( ! ( * V_22 ) )
return 0 ;
F_145 ( L_168 ,
V_48 -> V_51 , V_48 -> system , V_48 -> V_67 ) ;
V_48 -> V_250 = V_286 -> V_34 ;
V_48 -> V_251 = V_286 -> V_251 ;
* V_22 = V_286 -> V_22 ;
F_143 ( V_286 ) ;
return 1 ;
}
enum V_288 F_146 ( struct V_47 * * V_289 ,
struct V_14 * V_14 , const char * V_1 ,
unsigned long V_2 , const char * V_183 )
{
struct V_47 * V_48 ;
int V_112 ;
F_1 ( V_1 , V_2 ) ;
* V_289 = V_48 = F_27 () ;
if ( ! V_48 )
return V_290 ;
V_48 -> V_67 = F_53 () ;
if ( ! V_48 -> V_67 ) {
V_112 = V_290 ;
goto V_291;
}
if ( strcmp ( V_183 , L_169 ) == 0 ) {
V_48 -> V_69 |= V_119 ;
if ( strcmp ( V_48 -> V_67 , L_170 ) == 0 )
V_48 -> V_69 |= V_227 ;
}
V_48 -> V_51 = F_54 () ;
if ( V_48 -> V_51 < 0 ) {
V_112 = V_292 ;
goto V_291;
}
V_48 -> system = F_12 ( V_183 ) ;
if ( ! V_48 -> system ) {
V_112 = V_290 ;
goto V_291;
}
V_48 -> V_14 = V_14 ;
V_112 = F_59 ( V_48 ) ;
if ( V_112 < 0 ) {
V_112 = V_293 ;
goto V_294;
}
if ( V_14 && F_144 ( V_14 , V_48 ) )
V_295 = 0 ;
V_112 = F_87 ( V_48 ) ;
V_295 = 1 ;
if ( V_112 < 0 ) {
V_112 = V_296 ;
goto V_294;
}
if ( ! V_112 && ( V_48 -> V_69 & V_119 ) ) {
struct V_114 * V_66 ;
struct V_7 * V_61 , * * V_155 ;
V_155 = & V_48 -> V_165 . args ;
for ( V_66 = V_48 -> V_135 . V_116 ; V_66 ; V_66 = V_66 -> V_22 ) {
V_61 = F_6 () ;
if ( ! V_61 ) {
V_48 -> V_69 |= V_143 ;
return V_297 ;
}
V_61 -> type = V_65 ;
V_61 -> V_66 . V_67 = F_12 ( V_66 -> V_67 ) ;
if ( ! V_61 -> V_66 . V_67 ) {
V_48 -> V_69 |= V_143 ;
F_31 ( V_61 ) ;
return V_297 ;
}
V_61 -> V_66 . V_66 = V_66 ;
* V_155 = V_61 ;
V_155 = & V_61 -> V_22 ;
}
return 0 ;
}
return 0 ;
V_294:
V_48 -> V_69 |= V_143 ;
return V_112 ;
V_291:
free ( V_48 -> system ) ;
free ( V_48 -> V_67 ) ;
free ( V_48 ) ;
* V_289 = NULL ;
return V_112 ;
}
enum V_288 F_147 ( struct V_47 * * V_289 , const char * V_1 ,
unsigned long V_2 , const char * V_183 )
{
return F_146 ( V_289 , NULL , V_1 , V_2 , V_183 ) ;
}
enum V_288 F_148 ( struct V_14 * V_14 , const char * V_1 ,
unsigned long V_2 , const char * V_183 )
{
struct V_47 * V_48 = NULL ;
int V_112 = F_146 ( & V_48 , V_14 , V_1 , V_2 , V_183 ) ;
if ( V_48 == NULL )
return V_112 ;
if ( F_28 ( V_14 , V_48 ) ) {
V_112 = V_290 ;
goto V_298;
}
#define F_149 0
if ( F_149 && V_48 -> V_165 . args )
F_138 ( V_48 -> V_165 . args ) ;
return 0 ;
V_298:
F_150 ( V_48 ) ;
return V_112 ;
}
int F_151 ( struct V_14 * V_14 V_145 ,
enum V_288 V_299 , char * V_1 , T_1 V_300 )
{
int V_301 ;
const char * V_302 ;
if ( V_299 >= 0 ) {
V_302 = F_152 ( V_299 , V_1 , V_300 ) ;
if ( V_302 != V_1 ) {
T_1 V_126 = strlen ( V_302 ) ;
memcpy ( V_1 , V_302 , F_153 ( V_300 - 1 , V_126 ) ) ;
* ( V_1 + F_153 ( V_300 - 1 , V_126 ) ) = '\0' ;
}
return 0 ;
}
if ( V_299 <= V_303 ||
V_299 >= V_304 )
return - 1 ;
V_301 = V_299 - V_303 - 1 ;
V_302 = V_305 [ V_301 ] ;
switch ( V_299 ) {
case V_290 :
case V_306 :
case V_292 :
case V_293 :
case V_296 :
case V_297 :
case V_307 :
snprintf ( V_1 , V_300 , L_107 , V_302 ) ;
break;
default:
break;
}
return 0 ;
}
int F_154 ( struct V_188 * V_189 , struct V_114 * V_66 ,
const char * V_67 , struct V_230 * V_231 ,
unsigned long long * V_151 , int V_308 )
{
if ( ! V_66 ) {
if ( V_308 )
F_111 ( V_189 , L_171 , V_67 ) ;
return - 1 ;
}
if ( F_93 ( V_66 , V_231 -> V_168 , V_151 ) ) {
if ( V_308 )
F_111 ( V_189 , L_172 , V_67 ) ;
return - 1 ;
}
return 0 ;
}
void * F_155 ( struct V_188 * V_189 , struct V_47 * V_48 ,
const char * V_67 , struct V_230 * V_231 ,
int * V_126 , int V_308 )
{
struct V_114 * V_66 ;
void * V_168 = V_231 -> V_168 ;
unsigned V_132 ;
int V_309 ;
if ( ! V_48 )
return NULL ;
V_66 = F_78 ( V_48 , V_67 ) ;
if ( ! V_66 ) {
if ( V_308 )
F_111 ( V_189 , L_171 , V_67 ) ;
return NULL ;
}
if ( ! V_126 )
V_126 = & V_309 ;
V_132 = V_66 -> V_132 ;
if ( V_66 -> V_69 & V_129 ) {
V_132 = F_89 ( V_48 -> V_14 ,
V_168 + V_132 , V_66 -> V_2 ) ;
* V_126 = V_132 >> 16 ;
V_132 &= 0xffff ;
} else
* V_126 = V_66 -> V_2 ;
return V_168 + V_132 ;
}
int F_156 ( struct V_188 * V_189 , struct V_47 * V_48 ,
const char * V_67 , struct V_230 * V_231 ,
unsigned long long * V_151 , int V_308 )
{
struct V_114 * V_66 ;
if ( ! V_48 )
return - 1 ;
V_66 = F_78 ( V_48 , V_67 ) ;
return F_154 ( V_189 , V_66 , V_67 , V_231 , V_151 , V_308 ) ;
}
int F_157 ( struct V_188 * V_189 , struct V_47 * V_48 ,
const char * V_67 , struct V_230 * V_231 ,
unsigned long long * V_151 , int V_308 )
{
struct V_114 * V_66 ;
if ( ! V_48 )
return - 1 ;
V_66 = F_88 ( V_48 , V_67 ) ;
return F_154 ( V_189 , V_66 , V_67 , V_231 , V_151 , V_308 ) ;
}
int F_158 ( struct V_188 * V_189 , struct V_47 * V_48 ,
const char * V_67 , struct V_230 * V_231 ,
unsigned long long * V_151 , int V_308 )
{
struct V_114 * V_66 ;
if ( ! V_48 )
return - 1 ;
V_66 = F_68 ( V_48 , V_67 ) ;
return F_154 ( V_189 , V_66 , V_67 , V_231 , V_151 , V_308 ) ;
}
int F_159 ( struct V_188 * V_189 , const char * V_46 ,
struct V_47 * V_48 , const char * V_67 ,
struct V_230 * V_231 , int V_308 )
{
struct V_114 * V_66 = F_78 ( V_48 , V_67 ) ;
unsigned long long V_151 ;
if ( ! V_66 )
goto V_310;
if ( F_93 ( V_66 , V_231 -> V_168 , & V_151 ) )
goto V_310;
return F_111 ( V_189 , V_46 , V_151 ) ;
V_310:
if ( V_308 )
F_111 ( V_189 , L_173 , V_67 ) ;
return - 1 ;
}
static void F_83 ( struct V_159 * V_34 )
{
struct V_199 * V_203 ;
free ( V_34 -> V_67 ) ;
while ( V_34 -> V_203 ) {
V_203 = V_34 -> V_203 ;
V_34 -> V_203 = V_203 -> V_22 ;
free ( V_203 ) ;
}
free ( V_34 ) ;
}
int F_160 ( struct V_14 * V_14 ,
T_2 V_34 ,
enum V_311 V_312 ,
char * V_67 , ... )
{
struct V_159 * V_198 ;
struct V_199 * * V_313 ;
struct V_199 * V_200 ;
enum V_311 type ;
T_3 V_314 ;
int V_112 ;
V_198 = F_81 ( V_14 , V_67 ) ;
if ( V_198 ) {
F_145 ( L_174 , V_67 ) ;
F_82 ( V_14 , V_67 ) ;
}
V_198 = calloc ( 1 , sizeof( * V_198 ) ) ;
if ( ! V_198 ) {
F_46 ( L_175 ) ;
return V_290 ;
}
V_198 -> V_312 = V_312 ;
V_198 -> V_67 = F_12 ( V_67 ) ;
V_198 -> V_34 = V_34 ;
if ( ! V_198 -> V_67 ) {
F_46 ( L_176 ) ;
free ( V_198 ) ;
return V_290 ;
}
V_313 = & ( V_198 -> V_203 ) ;
va_start ( V_314 , V_67 ) ;
for (; ; ) {
type = va_arg ( V_314 , enum V_311 ) ;
if ( type == V_315 )
break;
if ( type >= V_316 ) {
F_46 ( L_177 , type ) ;
V_112 = V_307 ;
goto V_37;
}
V_200 = malloc ( sizeof( * V_200 ) ) ;
if ( ! V_200 ) {
F_46 ( L_178 ) ;
V_112 = V_290 ;
goto V_37;
}
V_200 -> type = type ;
V_200 -> V_22 = NULL ;
* V_313 = V_200 ;
V_313 = & ( V_200 -> V_22 ) ;
V_198 -> V_164 ++ ;
}
va_end ( V_314 ) ;
V_198 -> V_22 = V_14 -> V_161 ;
V_14 -> V_161 = V_198 ;
return 0 ;
V_37:
va_end ( V_314 ) ;
F_83 ( V_198 ) ;
return V_112 ;
}
int F_161 ( struct V_14 * V_14 ,
int V_51 , char * V_283 , char * V_284 ,
T_4 V_34 ,
void * V_251 )
{
struct V_47 * V_48 ;
struct V_285 * V_286 ;
if ( V_51 >= 0 ) {
V_48 = F_102 ( V_14 , V_51 ) ;
if ( ! V_48 )
goto V_317;
if ( V_284 && ( strcmp ( V_284 , V_48 -> V_67 ) != 0 ) )
goto V_317;
if ( V_283 && ( strcmp ( V_283 , V_48 -> system ) != 0 ) )
goto V_317;
} else {
V_48 = F_103 ( V_14 , V_283 , V_284 ) ;
if ( ! V_48 )
goto V_317;
}
F_145 ( L_168 ,
V_48 -> V_51 , V_48 -> system , V_48 -> V_67 ) ;
V_48 -> V_250 = V_34 ;
V_48 -> V_251 = V_251 ;
return 0 ;
V_317:
V_286 = calloc ( 1 , sizeof( * V_286 ) ) ;
if ( ! V_286 ) {
F_46 ( L_179 ) ;
return V_290 ;
}
V_286 -> V_51 = V_51 ;
if ( V_284 )
V_286 -> V_284 = F_12 ( V_284 ) ;
if ( V_283 )
V_286 -> V_283 = F_12 ( V_283 ) ;
if ( ( V_284 && ! V_286 -> V_284 ) ||
( V_283 && ! V_286 -> V_283 ) ) {
F_46 ( L_180 ) ;
free ( ( void * ) V_286 -> V_284 ) ;
free ( ( void * ) V_286 -> V_283 ) ;
free ( V_286 ) ;
return V_290 ;
}
V_286 -> V_34 = V_34 ;
V_286 -> V_22 = V_14 -> V_287 ;
V_14 -> V_287 = V_286 ;
V_286 -> V_251 = V_251 ;
return - 1 ;
}
struct V_14 * F_162 ( void )
{
struct V_14 * V_14 = calloc ( 1 , sizeof( * V_14 ) ) ;
if ( V_14 )
V_14 -> V_318 = 1 ;
return V_14 ;
}
void F_163 ( struct V_14 * V_14 )
{
V_14 -> V_318 ++ ;
}
static void F_164 ( struct V_114 * V_66 )
{
struct V_114 * V_22 ;
while ( V_66 ) {
V_22 = V_66 -> V_22 ;
free ( V_66 -> type ) ;
free ( V_66 -> V_67 ) ;
free ( V_66 ) ;
V_66 = V_22 ;
}
}
static void F_165 ( struct V_135 * V_135 )
{
F_164 ( V_135 -> V_136 ) ;
F_164 ( V_135 -> V_116 ) ;
}
void F_150 ( struct V_47 * V_48 )
{
free ( V_48 -> V_67 ) ;
free ( V_48 -> system ) ;
F_165 ( & V_48 -> V_135 ) ;
free ( V_48 -> V_165 . V_135 ) ;
F_116 ( V_48 -> V_165 . args ) ;
free ( V_48 ) ;
}
void F_166 ( struct V_14 * V_14 )
{
struct V_15 * V_16 , * V_319 ;
struct V_31 * V_32 , * V_320 ;
struct V_42 * V_43 , * V_321 ;
struct V_159 * V_322 ;
struct V_285 * V_286 ;
int V_19 ;
if ( ! V_14 )
return;
V_16 = V_14 -> V_16 ;
V_32 = V_14 -> V_32 ;
V_43 = V_14 -> V_43 ;
V_14 -> V_318 -- ;
if ( V_14 -> V_318 )
return;
if ( V_14 -> V_18 ) {
for ( V_19 = 0 ; V_19 < V_14 -> V_20 ; V_19 ++ )
free ( V_14 -> V_18 [ V_19 ] . V_21 ) ;
free ( V_14 -> V_18 ) ;
}
while ( V_16 ) {
V_319 = V_16 -> V_22 ;
free ( V_16 -> V_21 ) ;
free ( V_16 ) ;
V_16 = V_319 ;
}
if ( V_14 -> V_27 ) {
for ( V_19 = 0 ; V_19 < ( int ) V_14 -> V_33 ; V_19 ++ ) {
free ( V_14 -> V_27 [ V_19 ] . V_34 ) ;
free ( V_14 -> V_27 [ V_19 ] . V_35 ) ;
}
free ( V_14 -> V_27 ) ;
}
while ( V_32 ) {
V_320 = V_32 -> V_22 ;
free ( V_32 -> V_34 ) ;
free ( V_32 -> V_35 ) ;
free ( V_32 ) ;
V_32 = V_320 ;
}
while ( V_14 -> V_161 ) {
V_322 = V_14 -> V_161 ;
V_14 -> V_161 = V_322 -> V_22 ;
F_83 ( V_322 ) ;
}
if ( V_14 -> V_39 ) {
for ( V_19 = 0 ; V_19 < ( int ) V_14 -> V_44 ; V_19 ++ )
free ( V_14 -> V_39 [ V_19 ] . V_45 ) ;
free ( V_14 -> V_39 ) ;
}
while ( V_43 ) {
V_321 = V_43 -> V_22 ;
free ( V_43 -> V_45 ) ;
free ( V_43 ) ;
V_43 = V_321 ;
}
for ( V_19 = 0 ; V_19 < V_14 -> V_50 ; V_19 ++ )
F_150 ( V_14 -> V_49 [ V_19 ] ) ;
while ( V_14 -> V_287 ) {
V_286 = V_14 -> V_287 ;
V_14 -> V_287 = V_286 -> V_22 ;
F_143 ( V_286 ) ;
}
free ( V_14 -> V_49 ) ;
free ( V_14 -> V_267 ) ;
free ( V_14 ) ;
}
void F_167 ( struct V_14 * V_14 )
{
F_166 ( V_14 ) ;
}
