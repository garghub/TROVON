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
static unsigned int F_58 ( const char * V_67 )
{
static struct {
const char * type ;
unsigned int V_2 ;
} V_116 [] = {
{ L_21 , 1 } ,
{ L_25 , 2 } ,
{ L_26 , 4 } ,
{ L_27 , 8 } ,
{ L_22 , 1 } ,
{ L_28 , 2 } ,
{ L_29 , 4 } ,
{ L_30 , 8 } ,
{ L_20 , 1 } ,
{ } ,
} ;
int V_19 ;
for ( V_19 = 0 ; V_116 [ V_19 ] . type ; V_19 ++ ) {
if ( ! strcmp ( V_116 [ V_19 ] . type , V_67 ) )
return V_116 [ V_19 ] . V_2 ;
}
return 0 ;
}
static int F_59 ( struct V_47 * V_48 , struct V_114 * * V_117 )
{
struct V_114 * V_66 = NULL ;
enum V_52 type ;
char * V_108 ;
char * V_118 ;
int V_119 = 0 ;
do {
unsigned int V_120 = 0 ;
type = F_41 ( & V_108 ) ;
if ( type == V_90 ) {
F_40 ( V_108 ) ;
return V_119 ;
}
V_119 ++ ;
if ( F_47 ( type , V_108 , V_53 , L_31 ) )
goto V_113;
F_40 ( V_108 ) ;
type = F_41 ( & V_108 ) ;
if ( V_48 -> V_69 & V_121 &&
type == V_53 && strcmp ( V_108 , L_32 ) == 0 ) {
F_40 ( V_108 ) ;
type = F_41 ( & V_108 ) ;
}
if ( F_47 ( type , V_108 , V_94 , L_18 ) < 0 )
goto V_113;
F_40 ( V_108 ) ;
if ( F_49 ( V_53 , & V_108 ) < 0 )
goto V_113;
V_118 = V_108 ;
V_66 = calloc ( 1 , sizeof( * V_66 ) ) ;
if ( ! V_66 )
goto V_113;
V_66 -> V_48 = V_48 ;
for (; ; ) {
type = F_41 ( & V_108 ) ;
if ( type == V_53 ||
( type == V_94 && strcmp ( V_108 , L_33 ) == 0 ) ||
( V_48 -> V_69 & V_121 &&
type == V_94 && strcmp ( V_108 , L_34 ) == 0 ) ) {
if ( strcmp ( V_108 , L_33 ) == 0 )
V_66 -> V_69 |= V_122 ;
if ( V_66 -> type ) {
char * V_123 ;
V_123 = realloc ( V_66 -> type ,
strlen ( V_66 -> type ) +
strlen ( V_118 ) + 2 ) ;
if ( ! V_123 ) {
free ( V_118 ) ;
goto V_113;
}
V_66 -> type = V_123 ;
strcat ( V_66 -> type , L_35 ) ;
strcat ( V_66 -> type , V_118 ) ;
free ( V_118 ) ;
} else
V_66 -> type = V_118 ;
V_118 = V_108 ;
continue;
}
break;
}
if ( ! V_66 -> type ) {
F_46 ( L_36 , V_124 ) ;
goto V_113;
}
V_66 -> V_67 = V_118 ;
if ( F_45 ( type , V_94 ) )
goto V_113;
if ( strcmp ( V_108 , L_37 ) == 0 ) {
enum V_52 V_125 = type ;
char * V_126 = V_108 ;
char * V_127 ;
int V_128 ;
V_66 -> V_69 |= V_115 ;
type = F_41 ( & V_108 ) ;
if ( type == V_53 )
V_66 -> V_129 = strtoul ( V_108 , NULL , 0 ) ;
else
V_66 -> V_129 = 0 ;
while ( strcmp ( V_108 , L_38 ) != 0 ) {
if ( V_125 == V_53 &&
type == V_53 )
V_128 = 2 ;
else
V_128 = 1 ;
V_125 = type ;
V_127 = realloc ( V_126 ,
strlen ( V_126 ) +
strlen ( V_108 ) + V_128 ) ;
if ( ! V_127 ) {
free ( V_126 ) ;
goto V_113;
}
V_126 = V_127 ;
if ( V_128 == 2 )
strcat ( V_126 , L_35 ) ;
strcat ( V_126 , V_108 ) ;
V_66 -> V_129 = strtoul ( V_108 , NULL , 0 ) ;
F_40 ( V_108 ) ;
type = F_41 ( & V_108 ) ;
if ( type == V_93 ) {
F_46 ( L_39 ) ;
goto V_113;
}
}
F_40 ( V_108 ) ;
V_127 = realloc ( V_126 , strlen ( V_126 ) + 2 ) ;
if ( ! V_127 ) {
free ( V_126 ) ;
goto V_113;
}
V_126 = V_127 ;
strcat ( V_126 , L_38 ) ;
type = F_41 ( & V_108 ) ;
if ( type == V_53 ) {
char * V_123 ;
V_123 = realloc ( V_66 -> type ,
strlen ( V_66 -> type ) +
strlen ( V_66 -> V_67 ) +
strlen ( V_126 ) + 2 ) ;
if ( ! V_123 ) {
free ( V_126 ) ;
goto V_113;
}
V_66 -> type = V_123 ;
strcat ( V_66 -> type , L_35 ) ;
strcat ( V_66 -> type , V_66 -> V_67 ) ;
V_120 = F_58 ( V_66 -> V_67 ) ;
F_40 ( V_66 -> V_67 ) ;
strcat ( V_66 -> type , V_126 ) ;
V_66 -> V_67 = V_108 ;
type = F_41 ( & V_108 ) ;
} else {
char * V_123 ;
V_123 = realloc ( V_66 -> type ,
strlen ( V_66 -> type ) +
strlen ( V_126 ) + 1 ) ;
if ( ! V_123 ) {
free ( V_126 ) ;
goto V_113;
}
V_66 -> type = V_123 ;
strcat ( V_66 -> type , V_126 ) ;
}
free ( V_126 ) ;
}
if ( F_55 ( V_66 ) )
V_66 -> V_69 |= V_130 ;
if ( F_56 ( V_66 ) )
V_66 -> V_69 |= V_131 ;
if ( F_57 ( V_66 ) )
V_66 -> V_69 |= V_132 ;
if ( F_47 ( type , V_108 , V_94 , L_40 ) )
goto V_113;
F_40 ( V_108 ) ;
if ( F_51 ( V_53 , L_41 ) < 0 )
goto V_133;
if ( F_51 ( V_94 , L_18 ) < 0 )
goto V_133;
if ( F_49 ( V_53 , & V_108 ) )
goto V_113;
V_66 -> V_134 = strtoul ( V_108 , NULL , 0 ) ;
F_40 ( V_108 ) ;
if ( F_51 ( V_94 , L_40 ) < 0 )
goto V_133;
if ( F_51 ( V_53 , L_42 ) < 0 )
goto V_133;
if ( F_51 ( V_94 , L_18 ) < 0 )
goto V_133;
if ( F_49 ( V_53 , & V_108 ) )
goto V_113;
V_66 -> V_2 = strtoul ( V_108 , NULL , 0 ) ;
F_40 ( V_108 ) ;
if ( F_51 ( V_94 , L_40 ) < 0 )
goto V_133;
type = F_41 ( & V_108 ) ;
if ( type != V_90 ) {
if ( F_47 ( type , V_108 , V_53 , L_43 ) )
goto V_113;
F_40 ( V_108 ) ;
if ( F_51 ( V_94 , L_18 ) < 0 )
goto V_133;
if ( F_49 ( V_53 , & V_108 ) )
goto V_113;
if ( strtoul ( V_108 , NULL , 0 ) )
V_66 -> V_69 |= V_135 ;
F_40 ( V_108 ) ;
if ( F_51 ( V_94 , L_40 ) < 0 )
goto V_133;
if ( F_49 ( V_90 , & V_108 ) )
goto V_113;
}
F_40 ( V_108 ) ;
if ( V_66 -> V_69 & V_115 ) {
if ( V_66 -> V_129 )
V_66 -> V_136 = V_66 -> V_2 / V_66 -> V_129 ;
else if ( V_66 -> V_69 & V_131 )
V_66 -> V_136 = V_120 ;
else if ( V_66 -> V_69 & V_130 )
V_66 -> V_136 = 1 ;
else if ( V_66 -> V_69 & V_132 )
V_66 -> V_136 = V_48 -> V_14 ?
V_48 -> V_14 -> V_137 :
sizeof( long ) ;
} else
V_66 -> V_136 = V_66 -> V_2 ;
* V_117 = V_66 ;
V_117 = & V_66 -> V_22 ;
} while ( 1 );
return 0 ;
V_113:
F_40 ( V_108 ) ;
V_133:
if ( V_66 ) {
free ( V_66 -> type ) ;
free ( V_66 -> V_67 ) ;
free ( V_66 ) ;
}
return - 1 ;
}
static int F_60 ( struct V_47 * V_48 )
{
char * V_108 ;
int V_112 ;
if ( F_52 ( V_53 , L_44 ) < 0 )
return - 1 ;
if ( F_51 ( V_94 , L_18 ) < 0 )
return - 1 ;
if ( F_49 ( V_90 , & V_108 ) )
goto V_113;
F_40 ( V_108 ) ;
V_112 = F_59 ( V_48 , & V_48 -> V_138 . V_139 ) ;
if ( V_112 < 0 )
return V_112 ;
V_48 -> V_138 . V_140 = V_112 ;
V_112 = F_59 ( V_48 , & V_48 -> V_138 . V_117 ) ;
if ( V_112 < 0 )
return V_112 ;
V_48 -> V_138 . V_141 = V_112 ;
return 0 ;
V_113:
F_40 ( V_108 ) ;
return - 1 ;
}
static enum V_52
F_61 ( struct V_47 * V_48 , struct V_7 * V_61 , char * * V_95 )
{
enum V_52 type ;
char * V_108 ;
type = F_41 ( & V_108 ) ;
* V_95 = V_108 ;
return F_62 ( V_48 , V_61 , V_95 , type ) ;
}
static enum V_52
F_63 ( struct V_47 * V_48 , struct V_7 * V_142 , char * * V_95 )
{
struct V_7 * V_61 , * V_85 , * V_86 ;
enum V_52 type ;
char * V_108 = NULL ;
V_61 = F_6 () ;
V_85 = F_6 () ;
V_86 = F_6 () ;
if ( ! V_61 || ! V_85 || ! V_86 ) {
F_46 ( L_45 , V_124 ) ;
F_31 ( V_85 ) ;
F_31 ( V_86 ) ;
goto V_37;
}
V_61 -> type = V_83 ;
V_61 -> V_84 . V_85 = V_85 ;
V_61 -> V_84 . V_86 = V_86 ;
* V_95 = NULL ;
type = F_61 ( V_48 , V_85 , & V_108 ) ;
V_143:
if ( type == V_94 && strcmp ( V_108 , L_18 ) != 0 ) {
type = F_64 ( V_48 , V_85 , & V_108 ) ;
goto V_143;
}
if ( F_47 ( type , V_108 , V_94 , L_18 ) )
goto V_37;
V_61 -> V_84 . V_84 = V_108 ;
type = F_61 ( V_48 , V_86 , & V_108 ) ;
V_142 -> V_84 . V_86 = V_61 ;
* V_95 = V_108 ;
return type ;
V_37:
V_142 -> V_84 . V_86 = NULL ;
F_40 ( V_108 ) ;
F_31 ( V_61 ) ;
return V_55 ;
}
static enum V_52
F_65 ( struct V_47 * V_48 , struct V_7 * V_142 , char * * V_95 )
{
struct V_7 * V_61 ;
enum V_52 type ;
char * V_108 = NULL ;
V_61 = F_6 () ;
if ( ! V_61 ) {
F_46 ( L_45 , V_124 ) ;
* V_95 = NULL ;
return V_55 ;
}
* V_95 = NULL ;
type = F_61 ( V_48 , V_61 , & V_108 ) ;
if ( F_47 ( type , V_108 , V_94 , L_38 ) )
goto V_37;
V_142 -> V_84 . V_86 = V_61 ;
F_40 ( V_108 ) ;
type = F_44 ( & V_108 ) ;
* V_95 = V_108 ;
return type ;
V_37:
F_40 ( V_108 ) ;
F_31 ( V_61 ) ;
return V_55 ;
}
static int F_66 ( char * V_84 )
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
F_46 ( L_46 , V_84 [ 0 ] ) ;
return - 1 ;
}
} else {
if ( strcmp ( V_84 , L_47 ) == 0 ||
strcmp ( V_84 , L_48 ) == 0 ) {
return 3 ;
} else if ( strcmp ( V_84 , L_49 ) == 0 ||
strcmp ( V_84 , L_50 ) == 0 ) {
return 8 ;
} else if ( strcmp ( V_84 , L_51 ) == 0 ||
strcmp ( V_84 , L_52 ) == 0 ) {
return 9 ;
} else if ( strcmp ( V_84 , L_53 ) == 0 ||
strcmp ( V_84 , L_54 ) == 0 ) {
return 10 ;
} else if ( strcmp ( V_84 , L_55 ) == 0 ) {
return 14 ;
} else if ( strcmp ( V_84 , L_56 ) == 0 ) {
return 15 ;
} else {
F_46 ( L_57 , V_84 ) ;
return - 1 ;
}
}
}
static int F_67 ( struct V_7 * V_61 )
{
if ( ! V_61 -> V_84 . V_85 || V_61 -> V_84 . V_85 -> type == V_88 )
V_61 -> V_84 . V_144 = 0 ;
else
V_61 -> V_84 . V_144 = F_66 ( V_61 -> V_84 . V_84 ) ;
return V_61 -> V_84 . V_144 ;
}
static enum V_52
F_64 ( struct V_47 * V_48 , struct V_7 * V_61 , char * * V_95 )
{
struct V_7 * V_85 , * V_86 = NULL ;
enum V_52 type ;
char * V_108 ;
V_108 = * V_95 ;
if ( V_61 -> type == V_83 && ! V_61 -> V_84 . V_85 ) {
if ( V_108 [ 1 ] ) {
F_46 ( L_58 , V_108 ) ;
goto V_37;
}
switch ( V_108 [ 0 ] ) {
case '~' :
case '!' :
case '+' :
case '-' :
break;
default:
F_46 ( L_58 , V_108 ) ;
goto V_37;
}
V_85 = F_6 () ;
if ( ! V_85 )
goto V_145;
V_85 -> type = V_88 ;
V_61 -> V_84 . V_85 = V_85 ;
V_86 = F_6 () ;
if ( ! V_86 )
goto V_145;
V_61 -> V_84 . V_86 = V_86 ;
* V_95 = NULL ;
type = F_61 ( V_48 , V_86 , V_95 ) ;
} else if ( strcmp ( V_108 , L_59 ) == 0 ) {
V_85 = F_6 () ;
if ( ! V_85 )
goto V_145;
* V_85 = * V_61 ;
V_61 -> type = V_83 ;
V_61 -> V_84 . V_84 = V_108 ;
V_61 -> V_84 . V_85 = V_85 ;
V_61 -> V_84 . V_144 = 0 ;
type = F_63 ( V_48 , V_61 , V_95 ) ;
} else if ( strcmp ( V_108 , L_49 ) == 0 ||
strcmp ( V_108 , L_50 ) == 0 ||
strcmp ( V_108 , L_60 ) == 0 ||
strcmp ( V_108 , L_61 ) == 0 ||
strcmp ( V_108 , L_55 ) == 0 ||
strcmp ( V_108 , L_56 ) == 0 ||
strcmp ( V_108 , L_62 ) == 0 ||
strcmp ( V_108 , L_63 ) == 0 ||
strcmp ( V_108 , L_33 ) == 0 ||
strcmp ( V_108 , L_64 ) == 0 ||
strcmp ( V_108 , L_65 ) == 0 ||
strcmp ( V_108 , L_66 ) == 0 ||
strcmp ( V_108 , L_67 ) == 0 ||
strcmp ( V_108 , L_52 ) == 0 ||
strcmp ( V_108 , L_51 ) == 0 ||
strcmp ( V_108 , L_53 ) == 0 ||
strcmp ( V_108 , L_54 ) == 0 ) {
V_85 = F_6 () ;
if ( ! V_85 )
goto V_145;
* V_85 = * V_61 ;
V_61 -> type = V_83 ;
V_61 -> V_84 . V_84 = V_108 ;
V_61 -> V_84 . V_85 = V_85 ;
V_61 -> V_84 . V_86 = NULL ;
if ( F_67 ( V_61 ) == - 1 ) {
V_48 -> V_69 |= V_146 ;
V_61 -> V_84 . V_84 = NULL ;
goto V_37;
}
type = F_44 ( & V_108 ) ;
* V_95 = V_108 ;
if ( ( strcmp ( V_61 -> V_84 . V_84 , L_33 ) == 0 ) &&
type == V_56 && ( strcmp ( V_108 , L_68 ) == 0 ) ) {
char * V_147 ;
if ( V_85 -> type != V_63 ) {
F_46 ( L_69 ) ;
goto V_37;
}
V_147 = realloc ( V_85 -> V_64 . V_64 ,
strlen ( V_85 -> V_64 . V_64 ) + 3 ) ;
if ( ! V_147 )
goto V_145;
V_85 -> V_64 . V_64 = V_147 ;
strcat ( V_85 -> V_64 . V_64 , L_70 ) ;
free ( V_61 -> V_84 . V_84 ) ;
* V_61 = * V_85 ;
free ( V_85 ) ;
return type ;
}
V_86 = F_6 () ;
if ( ! V_86 )
goto V_145;
type = F_62 ( V_48 , V_86 , V_95 , type ) ;
V_61 -> V_84 . V_86 = V_86 ;
} else if ( strcmp ( V_108 , L_37 ) == 0 ) {
V_85 = F_6 () ;
if ( ! V_85 )
goto V_145;
* V_85 = * V_61 ;
V_61 -> type = V_83 ;
V_61 -> V_84 . V_84 = V_108 ;
V_61 -> V_84 . V_85 = V_85 ;
V_61 -> V_84 . V_144 = 0 ;
type = F_65 ( V_48 , V_61 , V_95 ) ;
} else {
F_46 ( L_57 , V_108 ) ;
V_48 -> V_69 |= V_146 ;
goto V_37;
}
if ( type == V_94 && strcmp ( * V_95 , L_18 ) != 0 ) {
int V_144 ;
V_144 = F_66 ( * V_95 ) ;
if ( V_144 > V_61 -> V_84 . V_144 )
return F_64 ( V_48 , V_61 , V_95 ) ;
return F_64 ( V_48 , V_86 , V_95 ) ;
}
return type ;
V_145:
F_46 ( L_45 , V_124 ) ;
V_37:
F_40 ( V_108 ) ;
* V_95 = NULL ;
return V_55 ;
}
static enum V_52
F_68 ( struct V_47 * V_48 V_148 , struct V_7 * V_61 ,
char * * V_95 )
{
enum V_52 type ;
char * V_66 ;
char * V_108 ;
if ( F_51 ( V_94 , L_71 ) < 0 )
goto V_149;
if ( F_49 ( V_53 , & V_108 ) < 0 )
goto V_37;
V_66 = V_108 ;
V_61 -> type = V_65 ;
V_61 -> V_66 . V_67 = V_66 ;
if ( V_150 ) {
V_61 -> V_66 . V_66 = F_69 ( V_48 , V_61 -> V_66 . V_67 ) ;
V_61 -> V_66 . V_66 -> V_69 |= V_151 ;
V_150 = 0 ;
} else if ( V_152 ) {
V_61 -> V_66 . V_66 = F_69 ( V_48 , V_61 -> V_66 . V_67 ) ;
V_61 -> V_66 . V_66 -> V_69 |= V_153 ;
V_152 = 0 ;
}
type = F_41 ( & V_108 ) ;
* V_95 = V_108 ;
return type ;
V_37:
F_40 ( V_108 ) ;
V_149:
* V_95 = NULL ;
return V_55 ;
}
static unsigned long long
F_70 ( unsigned long long V_154 , const char * type , int V_155 )
{
int V_156 = 0 ;
char * V_157 ;
int V_128 ;
V_128 = strlen ( type ) ;
if ( V_155 ) {
if ( type [ V_128 - 1 ] != '*' ) {
F_46 ( L_72 ) ;
return V_154 ;
}
V_157 = malloc ( V_128 ) ;
if ( ! V_157 ) {
F_46 ( L_45 , V_124 ) ;
return V_154 ;
}
memcpy ( V_157 , type , V_128 ) ;
V_157 [ V_128 - 2 ] = 0 ;
V_154 = F_70 ( V_154 , V_157 , 0 ) ;
free ( V_157 ) ;
return V_154 ;
}
if ( type [ V_128 - 1 ] == '*' )
return V_154 ;
if ( strncmp ( type , L_73 , 6 ) == 0 )
return V_154 ;
if ( strcmp ( type , L_21 ) == 0 )
return V_154 & 0xff ;
if ( strcmp ( type , L_25 ) == 0 )
return V_154 & 0xffff ;
if ( strcmp ( type , L_26 ) == 0 )
return V_154 & 0xffffffff ;
if ( strcmp ( type , L_27 ) == 0 ||
strcmp ( type , L_30 ) )
return V_154 ;
if ( strcmp ( type , L_22 ) == 0 )
return ( unsigned long long ) ( char ) V_154 & 0xff ;
if ( strcmp ( type , L_28 ) == 0 )
return ( unsigned long long ) ( short ) V_154 & 0xffff ;
if ( strcmp ( type , L_29 ) == 0 )
return ( unsigned long long ) ( int ) V_154 & 0xffffffff ;
if ( strncmp ( type , L_74 , 9 ) == 0 ) {
V_156 = 0 ;
type += 9 ;
}
if ( strcmp ( type , L_20 ) == 0 ) {
if ( V_156 )
return ( unsigned long long ) ( char ) V_154 & 0xff ;
else
return V_154 & 0xff ;
}
if ( strcmp ( type , L_75 ) == 0 ) {
if ( V_156 )
return ( unsigned long long ) ( short ) V_154 & 0xffff ;
else
return V_154 & 0xffff ;
}
if ( strcmp ( type , L_76 ) == 0 ) {
if ( V_156 )
return ( unsigned long long ) ( int ) V_154 & 0xffffffff ;
else
return V_154 & 0xffffffff ;
}
return V_154 ;
}
static unsigned long long
F_71 ( unsigned long long V_154 , struct V_7 * V_61 , int V_155 )
{
if ( V_61 -> type != V_76 ) {
F_46 ( L_77 ) ;
return 0 ;
}
return F_70 ( V_154 , V_61 -> V_77 . type , V_155 ) ;
}
static int F_72 ( struct V_7 * V_61 , long long * V_154 )
{
long long V_85 , V_86 ;
int V_112 = 1 ;
switch ( V_61 -> type ) {
case V_63 :
* V_154 = strtoll ( V_61 -> V_64 . V_64 , NULL , 0 ) ;
break;
case V_76 :
V_112 = F_72 ( V_61 -> V_77 . V_17 , V_154 ) ;
if ( ! V_112 )
break;
* V_154 = F_71 ( * V_154 , V_61 , 0 ) ;
break;
case V_83 :
switch ( V_61 -> V_84 . V_84 [ 0 ] ) {
case '|' :
V_112 = F_72 ( V_61 -> V_84 . V_85 , & V_85 ) ;
if ( ! V_112 )
break;
V_112 = F_72 ( V_61 -> V_84 . V_86 , & V_86 ) ;
if ( ! V_112 )
break;
if ( V_61 -> V_84 . V_84 [ 1 ] )
* V_154 = V_85 || V_86 ;
else
* V_154 = V_85 | V_86 ;
break;
case '&' :
V_112 = F_72 ( V_61 -> V_84 . V_85 , & V_85 ) ;
if ( ! V_112 )
break;
V_112 = F_72 ( V_61 -> V_84 . V_86 , & V_86 ) ;
if ( ! V_112 )
break;
if ( V_61 -> V_84 . V_84 [ 1 ] )
* V_154 = V_85 && V_86 ;
else
* V_154 = V_85 & V_86 ;
break;
case '<' :
V_112 = F_72 ( V_61 -> V_84 . V_85 , & V_85 ) ;
if ( ! V_112 )
break;
V_112 = F_72 ( V_61 -> V_84 . V_86 , & V_86 ) ;
if ( ! V_112 )
break;
switch ( V_61 -> V_84 . V_84 [ 1 ] ) {
case 0 :
* V_154 = V_85 < V_86 ;
break;
case '<' :
* V_154 = V_85 << V_86 ;
break;
case '=' :
* V_154 = V_85 <= V_86 ;
break;
default:
F_46 ( L_57 , V_61 -> V_84 . V_84 ) ;
V_112 = 0 ;
}
break;
case '>' :
V_112 = F_72 ( V_61 -> V_84 . V_85 , & V_85 ) ;
if ( ! V_112 )
break;
V_112 = F_72 ( V_61 -> V_84 . V_86 , & V_86 ) ;
if ( ! V_112 )
break;
switch ( V_61 -> V_84 . V_84 [ 1 ] ) {
case 0 :
* V_154 = V_85 > V_86 ;
break;
case '>' :
* V_154 = V_85 >> V_86 ;
break;
case '=' :
* V_154 = V_85 >= V_86 ;
break;
default:
F_46 ( L_57 , V_61 -> V_84 . V_84 ) ;
V_112 = 0 ;
}
break;
case '=' :
V_112 = F_72 ( V_61 -> V_84 . V_85 , & V_85 ) ;
if ( ! V_112 )
break;
V_112 = F_72 ( V_61 -> V_84 . V_86 , & V_86 ) ;
if ( ! V_112 )
break;
if ( V_61 -> V_84 . V_84 [ 1 ] != '=' ) {
F_46 ( L_57 , V_61 -> V_84 . V_84 ) ;
V_112 = 0 ;
} else
* V_154 = V_85 == V_86 ;
break;
case '!' :
V_112 = F_72 ( V_61 -> V_84 . V_85 , & V_85 ) ;
if ( ! V_112 )
break;
V_112 = F_72 ( V_61 -> V_84 . V_86 , & V_86 ) ;
if ( ! V_112 )
break;
switch ( V_61 -> V_84 . V_84 [ 1 ] ) {
case '=' :
* V_154 = V_85 != V_86 ;
break;
default:
F_46 ( L_57 , V_61 -> V_84 . V_84 ) ;
V_112 = 0 ;
}
break;
case '-' :
if ( V_61 -> V_84 . V_85 -> type == V_88 )
V_85 = 0 ;
else
V_112 = F_72 ( V_61 -> V_84 . V_85 , & V_85 ) ;
if ( ! V_112 )
break;
V_112 = F_72 ( V_61 -> V_84 . V_86 , & V_86 ) ;
if ( ! V_112 )
break;
* V_154 = V_85 - V_86 ;
break;
case '+' :
if ( V_61 -> V_84 . V_85 -> type == V_88 )
V_85 = 0 ;
else
V_112 = F_72 ( V_61 -> V_84 . V_85 , & V_85 ) ;
if ( ! V_112 )
break;
V_112 = F_72 ( V_61 -> V_84 . V_86 , & V_86 ) ;
if ( ! V_112 )
break;
* V_154 = V_85 + V_86 ;
break;
default:
F_46 ( L_57 , V_61 -> V_84 . V_84 ) ;
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
static char * F_73 ( struct V_7 * V_61 )
{
long long V_154 ;
static char V_1 [ 20 ] ;
switch ( V_61 -> type ) {
case V_63 :
return V_61 -> V_64 . V_64 ;
case V_76 :
return F_73 ( V_61 -> V_77 . V_17 ) ;
case V_83 :
if ( ! F_72 ( V_61 , & V_154 ) )
break;
sprintf ( V_1 , L_79 , V_154 ) ;
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
F_74 ( struct V_47 * V_48 , struct V_57 * * V_158 , char * * V_95 )
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
type = F_61 ( V_48 , V_61 , & V_108 ) ;
if ( type == V_94 )
type = F_64 ( V_48 , V_61 , & V_108 ) ;
if ( type == V_55 )
goto V_37;
if ( F_47 ( type , V_108 , V_56 , L_81 ) )
goto V_37;
V_66 = calloc ( 1 , sizeof( * V_66 ) ) ;
if ( ! V_66 )
goto V_37;
V_59 = F_73 ( V_61 ) ;
if ( V_59 == NULL )
goto V_159;
V_66 -> V_59 = F_12 ( V_59 ) ;
if ( V_66 -> V_59 == NULL )
goto V_159;
F_31 ( V_61 ) ;
V_61 = F_6 () ;
if ( ! V_61 )
goto V_37;
F_40 ( V_108 ) ;
type = F_61 ( V_48 , V_61 , & V_108 ) ;
if ( F_47 ( type , V_108 , V_94 , L_82 ) )
goto V_159;
V_59 = F_73 ( V_61 ) ;
if ( V_59 == NULL )
goto V_159;
V_66 -> V_60 = F_12 ( V_59 ) ;
if ( V_66 -> V_60 == NULL )
goto V_159;
F_31 ( V_61 ) ;
V_61 = NULL ;
* V_158 = V_66 ;
V_158 = & V_66 -> V_22 ;
F_40 ( V_108 ) ;
type = F_44 ( & V_108 ) ;
} while ( type == V_56 && strcmp ( V_108 , L_81 ) == 0 );
* V_95 = V_108 ;
return type ;
V_159:
F_30 ( V_66 ) ;
V_37:
F_31 ( V_61 ) ;
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
V_61 -> type = V_68 ;
V_66 = F_6 () ;
if ( ! V_66 ) {
F_46 ( L_45 , V_124 ) ;
goto V_37;
}
type = F_61 ( V_48 , V_66 , & V_108 ) ;
while ( type == V_94 )
type = F_64 ( V_48 , V_66 , & V_108 ) ;
if ( F_47 ( type , V_108 , V_56 , L_81 ) )
goto V_159;
F_40 ( V_108 ) ;
V_61 -> V_69 . V_66 = V_66 ;
type = F_44 ( & V_108 ) ;
if ( F_29 ( type ) ) {
V_61 -> V_69 . V_70 = V_108 ;
type = F_44 ( & V_108 ) ;
}
if ( F_47 ( type , V_108 , V_56 , L_81 ) )
goto V_37;
type = F_74 ( V_48 , & V_61 -> V_69 . V_69 , & V_108 ) ;
if ( F_47 ( type , V_108 , V_56 , L_68 ) )
goto V_37;
F_40 ( V_108 ) ;
type = F_44 ( V_95 ) ;
return type ;
V_159:
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
V_61 -> type = V_71 ;
V_66 = F_6 () ;
if ( ! V_66 ) {
F_46 ( L_45 , V_124 ) ;
goto V_37;
}
type = F_61 ( V_48 , V_66 , & V_108 ) ;
if ( F_47 ( type , V_108 , V_56 , L_81 ) )
goto V_159;
V_61 -> V_72 . V_66 = V_66 ;
type = F_74 ( V_48 , & V_61 -> V_72 . V_73 , & V_108 ) ;
if ( F_47 ( type , V_108 , V_56 , L_68 ) )
goto V_37;
F_40 ( V_108 ) ;
type = F_44 ( V_95 ) ;
return type ;
V_159:
F_31 ( V_66 ) ;
V_37:
F_40 ( V_108 ) ;
* V_95 = NULL ;
return V_55 ;
}
static enum V_52
F_77 ( struct V_47 * V_48 , struct V_7 * V_61 , char * * V_95 )
{
struct V_7 * V_66 ;
enum V_52 type ;
char * V_108 ;
memset ( V_61 , 0 , sizeof( * V_61 ) ) ;
V_61 -> type = V_74 ;
V_66 = F_6 () ;
if ( ! V_66 ) {
F_46 ( L_45 , V_124 ) ;
goto V_37;
}
type = F_61 ( V_48 , V_66 , & V_108 ) ;
if ( F_47 ( type , V_108 , V_56 , L_81 ) )
goto V_37;
V_61 -> V_75 . V_66 = V_66 ;
F_40 ( V_108 ) ;
V_66 = F_6 () ;
if ( ! V_66 ) {
F_46 ( L_45 , V_124 ) ;
* V_95 = NULL ;
return V_55 ;
}
type = F_61 ( V_48 , V_66 , & V_108 ) ;
if ( F_47 ( type , V_108 , V_56 , L_68 ) )
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
F_78 ( struct V_47 * V_48 , struct V_7 * V_61 , char * * V_95 )
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
V_66 = F_79 ( V_48 , V_108 ) ;
if ( ! V_66 )
goto V_37;
V_61 -> V_81 . V_66 = V_66 ;
V_61 -> V_81 . V_82 = 0 ;
if ( F_51 ( V_56 , L_68 ) < 0 )
goto V_37;
F_40 ( V_108 ) ;
type = F_44 ( & V_108 ) ;
* V_95 = V_108 ;
if ( type != V_94 || strcmp ( V_108 , L_37 ) != 0 )
return type ;
F_40 ( V_108 ) ;
V_61 = F_6 () ;
if ( ! V_61 ) {
F_46 ( L_45 , V_124 ) ;
* V_95 = NULL ;
return V_55 ;
}
type = F_61 ( V_48 , V_61 , & V_108 ) ;
if ( type == V_55 )
goto V_160;
if ( ! F_47 ( type , V_108 , V_94 , L_38 ) )
goto V_160;
F_40 ( V_108 ) ;
type = F_44 ( V_95 ) ;
return type ;
V_160:
F_31 ( V_61 ) ;
V_37:
F_40 ( V_108 ) ;
* V_95 = NULL ;
return V_55 ;
}
static enum V_52
F_80 ( struct V_47 * V_48 , struct V_7 * V_61 , char * * V_95 )
{
struct V_7 * V_161 ;
enum V_52 type ;
char * V_108 ;
type = F_61 ( V_48 , V_61 , & V_108 ) ;
if ( type == V_55 )
goto V_37;
if ( type == V_94 )
type = F_64 ( V_48 , V_61 , & V_108 ) ;
if ( type == V_55 )
goto V_37;
if ( F_47 ( type , V_108 , V_56 , L_68 ) )
goto V_37;
F_40 ( V_108 ) ;
type = F_44 ( & V_108 ) ;
if ( F_29 ( type ) ||
( type == V_56 && strcmp ( V_108 , L_83 ) == 0 ) ) {
if ( V_61 -> type != V_63 ) {
F_46 ( L_84 ) ;
goto V_37;
}
V_161 = F_6 () ;
if ( ! V_161 ) {
F_46 ( L_45 , V_124 ) ;
goto V_37;
}
V_61 -> type = V_76 ;
V_61 -> V_77 . type = V_61 -> V_64 . V_64 ;
V_61 -> V_77 . V_17 = V_161 ;
type = F_62 ( V_48 , V_161 , & V_108 , type ) ;
}
* V_95 = V_108 ;
return type ;
V_37:
F_40 ( V_108 ) ;
* V_95 = NULL ;
return V_55 ;
}
static enum V_52
F_81 ( struct V_47 * V_48 V_148 , struct V_7 * V_61 ,
char * * V_95 )
{
enum V_52 type ;
char * V_108 ;
if ( F_49 ( V_53 , & V_108 ) < 0 )
goto V_37;
V_61 -> type = V_78 ;
V_61 -> string . string = V_108 ;
V_61 -> string . V_134 = - 1 ;
if ( F_51 ( V_56 , L_68 ) < 0 )
goto V_149;
type = F_41 ( & V_108 ) ;
* V_95 = V_108 ;
return type ;
V_37:
F_40 ( V_108 ) ;
V_149:
* V_95 = NULL ;
return V_55 ;
}
static struct V_162 *
F_82 ( struct V_14 * V_14 , char * V_163 )
{
struct V_162 * V_34 ;
if ( ! V_14 )
return NULL ;
for ( V_34 = V_14 -> V_164 ; V_34 ; V_34 = V_34 -> V_22 ) {
if ( strcmp ( V_34 -> V_67 , V_163 ) == 0 )
break;
}
return V_34 ;
}
static void F_83 ( struct V_14 * V_14 , char * V_163 )
{
struct V_162 * V_34 ;
struct V_162 * * V_22 ;
V_22 = & V_14 -> V_164 ;
while ( ( V_34 = * V_22 ) ) {
if ( strcmp ( V_34 -> V_67 , V_163 ) == 0 ) {
* V_22 = V_34 -> V_22 ;
F_84 ( V_34 ) ;
break;
}
V_22 = & V_34 -> V_22 ;
}
}
static enum V_52
F_85 ( struct V_47 * V_48 , struct V_162 * V_34 ,
struct V_7 * V_61 , char * * V_95 )
{
struct V_7 * * V_165 ;
struct V_7 * V_62 ;
enum V_52 type ;
char * V_108 ;
const char * V_166 ;
int V_19 ;
V_61 -> type = V_87 ;
V_61 -> V_34 . V_34 = V_34 ;
* V_95 = NULL ;
V_165 = & ( V_61 -> V_34 . args ) ;
for ( V_19 = 0 ; V_19 < V_34 -> V_167 ; V_19 ++ ) {
V_62 = F_6 () ;
if ( ! V_62 ) {
F_46 ( L_45 , V_124 ) ;
return V_55 ;
}
type = F_61 ( V_48 , V_62 , & V_108 ) ;
if ( V_19 < ( V_34 -> V_167 - 1 ) )
V_166 = L_81 ;
else
V_166 = L_68 ;
if ( F_47 ( type , V_108 , V_56 , V_166 ) ) {
F_31 ( V_62 ) ;
F_40 ( V_108 ) ;
return V_55 ;
}
* V_165 = V_62 ;
V_165 = & ( V_62 -> V_22 ) ;
F_40 ( V_108 ) ;
}
type = F_41 ( & V_108 ) ;
* V_95 = V_108 ;
return type ;
}
static enum V_52
F_86 ( struct V_47 * V_48 , struct V_7 * V_61 ,
char * V_108 , char * * V_95 )
{
struct V_162 * V_34 ;
if ( strcmp ( V_108 , L_85 ) == 0 ) {
F_40 ( V_108 ) ;
V_150 = 1 ;
return F_75 ( V_48 , V_61 , V_95 ) ;
}
if ( strcmp ( V_108 , L_86 ) == 0 ) {
F_40 ( V_108 ) ;
V_152 = 1 ;
return F_76 ( V_48 , V_61 , V_95 ) ;
}
if ( strcmp ( V_108 , L_87 ) == 0 ) {
F_40 ( V_108 ) ;
return F_77 ( V_48 , V_61 , V_95 ) ;
}
if ( strcmp ( V_108 , L_88 ) == 0 ) {
F_40 ( V_108 ) ;
return F_81 ( V_48 , V_61 , V_95 ) ;
}
if ( strcmp ( V_108 , L_89 ) == 0 ) {
F_40 ( V_108 ) ;
return F_78 ( V_48 , V_61 , V_95 ) ;
}
V_34 = F_82 ( V_48 -> V_14 , V_108 ) ;
if ( V_34 ) {
F_40 ( V_108 ) ;
return F_85 ( V_48 , V_34 , V_61 , V_95 ) ;
}
F_46 ( L_90 , V_108 ) ;
F_40 ( V_108 ) ;
return V_55 ;
}
static enum V_52
F_62 ( struct V_47 * V_48 , struct V_7 * V_61 ,
char * * V_95 , enum V_52 type )
{
char * V_108 ;
char * V_64 ;
V_108 = * V_95 ;
switch ( type ) {
case V_53 :
if ( strcmp ( V_108 , L_91 ) == 0 ) {
F_40 ( V_108 ) ;
type = F_68 ( V_48 , V_61 , & V_108 ) ;
break;
}
V_64 = V_108 ;
type = F_44 ( & V_108 ) ;
if ( type == V_56 && strcmp ( V_108 , L_83 ) == 0 ) {
F_40 ( V_108 ) ;
V_108 = NULL ;
type = F_86 ( V_48 , V_61 , V_64 , & V_108 ) ;
break;
}
while ( type == V_53 ) {
char * V_147 ;
V_147 = realloc ( V_64 ,
strlen ( V_64 ) + strlen ( V_108 ) + 2 ) ;
if ( ! V_147 ) {
free ( V_64 ) ;
* V_95 = NULL ;
F_40 ( V_108 ) ;
return V_55 ;
}
V_64 = V_147 ;
strcat ( V_64 , L_35 ) ;
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
type = F_80 ( V_48 , V_61 , & V_108 ) ;
break;
}
case V_94 :
V_61 -> type = V_83 ;
V_61 -> V_84 . V_84 = V_108 ;
V_61 -> V_84 . V_85 = NULL ;
type = F_64 ( V_48 , V_61 , & V_108 ) ;
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
static int F_87 ( struct V_47 * V_48 , struct V_7 * * V_158 )
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
F_46 ( L_45 , V_124 ) ;
return - 1 ;
}
type = F_61 ( V_48 , V_61 , & V_108 ) ;
if ( type == V_55 ) {
F_40 ( V_108 ) ;
F_31 ( V_61 ) ;
return - 1 ;
}
* V_158 = V_61 ;
args ++ ;
if ( type == V_94 ) {
type = F_64 ( V_48 , V_61 , & V_108 ) ;
F_40 ( V_108 ) ;
if ( type == V_55 ) {
* V_158 = NULL ;
F_31 ( V_61 ) ;
return - 1 ;
}
V_158 = & V_61 -> V_22 ;
continue;
}
if ( type == V_56 && strcmp ( V_108 , L_81 ) == 0 ) {
F_40 ( V_108 ) ;
* V_158 = V_61 ;
V_158 = & V_61 -> V_22 ;
continue;
}
break;
} while ( type != V_93 );
if ( type != V_93 && type != V_55 )
F_40 ( V_108 ) ;
return args ;
}
static int F_88 ( struct V_47 * V_48 )
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
V_48 -> V_168 . V_138 = V_108 ;
V_48 -> V_168 . args = NULL ;
type = F_44 ( & V_108 ) ;
if ( type == V_93 )
return 0 ;
if ( type == V_92 ) {
char * V_169 ;
if ( F_38 ( & V_169 , L_95 , V_48 -> V_168 . V_138 , V_108 ) < 0 )
goto V_113;
F_40 ( V_108 ) ;
F_40 ( V_48 -> V_168 . V_138 ) ;
V_48 -> V_168 . V_138 = NULL ;
V_108 = V_169 ;
goto V_104;
}
if ( F_47 ( type , V_108 , V_56 , L_81 ) )
goto V_113;
F_40 ( V_108 ) ;
V_112 = F_87 ( V_48 , & V_48 -> V_168 . args ) ;
if ( V_112 < 0 )
return - 1 ;
return V_112 ;
V_113:
F_40 ( V_108 ) ;
return - 1 ;
}
struct V_114 *
F_89 ( struct V_47 * V_48 , const char * V_67 )
{
struct V_114 * V_138 ;
for ( V_138 = V_48 -> V_138 . V_139 ;
V_138 ; V_138 = V_138 -> V_22 ) {
if ( strcmp ( V_138 -> V_67 , V_67 ) == 0 )
break;
}
return V_138 ;
}
struct V_114 *
F_79 ( struct V_47 * V_48 , const char * V_67 )
{
struct V_114 * V_138 ;
for ( V_138 = V_48 -> V_138 . V_117 ;
V_138 ; V_138 = V_138 -> V_22 ) {
if ( strcmp ( V_138 -> V_67 , V_67 ) == 0 )
break;
}
return V_138 ;
}
struct V_114 *
F_69 ( struct V_47 * V_48 , const char * V_67 )
{
struct V_114 * V_138 ;
V_138 = F_89 ( V_48 , V_67 ) ;
if ( V_138 )
return V_138 ;
return F_79 ( V_48 , V_67 ) ;
}
unsigned long long F_90 ( struct V_14 * V_14 ,
const void * V_170 , int V_2 )
{
switch ( V_2 ) {
case 1 :
return * ( unsigned char * ) V_170 ;
case 2 :
return F_91 ( V_14 , V_170 ) ;
case 4 :
return F_92 ( V_14 , V_170 ) ;
case 8 :
return F_93 ( V_14 , V_170 ) ;
default:
return 0 ;
}
}
int F_94 ( struct V_114 * V_66 , const void * V_171 ,
unsigned long long * V_59 )
{
if ( ! V_66 )
return - 1 ;
switch ( V_66 -> V_2 ) {
case 1 :
case 2 :
case 4 :
case 8 :
* V_59 = F_90 ( V_66 -> V_48 -> V_14 ,
V_171 + V_66 -> V_134 , V_66 -> V_2 ) ;
return 0 ;
default:
return - 1 ;
}
}
static int F_95 ( struct V_14 * V_14 ,
const char * type , int * V_134 , int * V_2 )
{
struct V_47 * V_48 ;
struct V_114 * V_66 ;
if ( ! V_14 -> V_49 ) {
F_46 ( L_96 ) ;
return - 1 ;
}
V_48 = V_14 -> V_49 [ 0 ] ;
V_66 = F_89 ( V_48 , type ) ;
if ( ! V_66 )
return - 1 ;
* V_134 = V_66 -> V_134 ;
* V_2 = V_66 -> V_2 ;
return 0 ;
}
static int F_96 ( struct V_14 * V_14 , void * V_171 ,
int * V_2 , int * V_134 , const char * V_67 )
{
int V_112 ;
if ( ! * V_2 ) {
V_112 = F_95 ( V_14 , V_67 , V_134 , V_2 ) ;
if ( V_112 < 0 )
return V_112 ;
}
return F_90 ( V_14 , V_171 + * V_134 , * V_2 ) ;
}
static int F_97 ( struct V_14 * V_14 , void * V_171 )
{
return F_96 ( V_14 , V_171 ,
& V_14 -> F_58 , & V_14 -> V_172 ,
L_97 ) ;
}
static int F_98 ( struct V_14 * V_14 , void * V_171 )
{
return F_96 ( V_14 , V_171 ,
& V_14 -> V_173 , & V_14 -> V_174 ,
L_98 ) ;
}
static int F_99 ( struct V_14 * V_14 , void * V_171 )
{
return F_96 ( V_14 , V_171 ,
& V_14 -> V_175 , & V_14 -> V_176 ,
L_99 ) ;
}
static int F_100 ( struct V_14 * V_14 , void * V_171 )
{
return F_96 ( V_14 , V_171 ,
& V_14 -> V_177 , & V_14 -> V_178 ,
L_100 ) ;
}
static int F_101 ( struct V_14 * V_14 , void * V_171 )
{
return F_96 ( V_14 , V_171 ,
& V_14 -> V_179 , & V_14 -> V_180 ,
L_101 ) ;
}
static int F_102 ( struct V_14 * V_14 , void * V_171 )
{
return F_96 ( V_14 , V_171 ,
& V_14 -> V_179 , & V_14 -> V_180 ,
L_102 ) ;
}
struct V_47 * F_103 ( struct V_14 * V_14 , int V_51 )
{
struct V_47 * * V_181 ;
struct V_47 V_23 ;
struct V_47 * V_182 = & V_23 ;
if ( V_14 -> V_183 && V_14 -> V_183 -> V_51 == V_51 )
return V_14 -> V_183 ;
V_23 . V_51 = V_51 ;
V_181 = bsearch ( & V_182 , V_14 -> V_49 , V_14 -> V_50 ,
sizeof( * V_14 -> V_49 ) , V_184 ) ;
if ( V_181 ) {
V_14 -> V_183 = * V_181 ;
return * V_181 ;
}
return NULL ;
}
struct V_47 *
F_104 ( struct V_14 * V_14 ,
const char * V_185 , const char * V_67 )
{
struct V_47 * V_48 ;
int V_19 ;
if ( V_14 -> V_183 &&
strcmp ( V_14 -> V_183 -> V_67 , V_67 ) == 0 &&
( ! V_185 || strcmp ( V_14 -> V_183 -> system , V_185 ) == 0 ) )
return V_14 -> V_183 ;
for ( V_19 = 0 ; V_19 < V_14 -> V_50 ; V_19 ++ ) {
V_48 = V_14 -> V_49 [ V_19 ] ;
if ( strcmp ( V_48 -> V_67 , V_67 ) == 0 ) {
if ( ! V_185 )
break;
if ( strcmp ( V_48 -> system , V_185 ) == 0 )
break;
}
}
if ( V_19 == V_14 -> V_50 )
V_48 = NULL ;
V_14 -> V_183 = V_48 ;
return V_48 ;
}
static unsigned long long
F_105 ( void * V_171 , int V_2 , struct V_47 * V_48 , struct V_7 * V_61 )
{
struct V_14 * V_14 = V_48 -> V_14 ;
unsigned long long V_154 = 0 ;
unsigned long long V_85 , V_86 ;
struct V_7 * V_186 = NULL ;
struct V_7 * V_187 ;
unsigned long V_134 ;
unsigned int V_188 ;
switch ( V_61 -> type ) {
case V_88 :
return 0 ;
case V_63 :
return F_106 ( V_61 -> V_64 . V_64 , NULL , 0 ) ;
case V_65 :
if ( ! V_61 -> V_66 . V_66 ) {
V_61 -> V_66 . V_66 = F_69 ( V_48 , V_61 -> V_66 . V_67 ) ;
if ( ! V_61 -> V_66 . V_66 )
goto V_189;
}
V_154 = F_90 ( V_14 , V_171 + V_61 -> V_66 . V_66 -> V_134 ,
V_61 -> V_66 . V_66 -> V_2 ) ;
break;
case V_68 :
case V_71 :
case V_74 :
break;
case V_76 :
V_154 = F_105 ( V_171 , V_2 , V_48 , V_61 -> V_77 . V_17 ) ;
return F_71 ( V_154 , V_61 , 0 ) ;
case V_78 :
case V_79 :
return 0 ;
case V_87 : {
struct V_190 V_191 ;
F_107 ( & V_191 ) ;
V_154 = F_108 ( & V_191 , V_171 , V_2 , V_48 , V_61 ) ;
F_109 ( & V_191 ) ;
return V_154 ;
}
case V_83 :
if ( strcmp ( V_61 -> V_84 . V_84 , L_37 ) == 0 ) {
V_86 = F_105 ( V_171 , V_2 , V_48 , V_61 -> V_84 . V_86 ) ;
V_187 = V_61 -> V_84 . V_85 ;
while ( V_187 -> type == V_76 ) {
if ( ! V_186 )
V_186 = V_187 ;
V_187 = V_187 -> V_77 . V_17 ;
}
V_188 = V_14 -> V_137 ;
switch ( V_187 -> type ) {
case V_80 :
V_134 = F_90 ( V_14 ,
V_171 + V_187 -> V_81 . V_66 -> V_134 ,
V_187 -> V_81 . V_66 -> V_2 ) ;
if ( V_187 -> V_81 . V_66 -> V_136 )
V_188 = V_187 -> V_81 . V_66 -> V_136 ;
V_134 &= 0xffff ;
V_134 += V_86 ;
break;
case V_65 :
if ( ! V_187 -> V_66 . V_66 ) {
V_187 -> V_66 . V_66 =
F_69 ( V_48 , V_187 -> V_66 . V_67 ) ;
if ( ! V_187 -> V_66 . V_66 ) {
V_61 = V_187 ;
goto V_189;
}
}
V_188 = V_187 -> V_66 . V_66 -> V_136 ;
V_134 = V_187 -> V_66 . V_66 -> V_134 +
V_86 * V_187 -> V_66 . V_66 -> V_136 ;
break;
default:
goto V_192;
}
V_154 = F_90 ( V_14 ,
V_171 + V_134 , V_188 ) ;
if ( V_186 )
V_154 = F_71 ( V_154 , V_186 , 1 ) ;
break;
} else if ( strcmp ( V_61 -> V_84 . V_84 , L_59 ) == 0 ) {
V_85 = F_105 ( V_171 , V_2 , V_48 , V_61 -> V_84 . V_85 ) ;
V_61 = V_61 -> V_84 . V_86 ;
if ( V_85 )
V_154 = F_105 ( V_171 , V_2 , V_48 , V_61 -> V_84 . V_85 ) ;
else
V_154 = F_105 ( V_171 , V_2 , V_48 , V_61 -> V_84 . V_86 ) ;
break;
}
V_192:
V_85 = F_105 ( V_171 , V_2 , V_48 , V_61 -> V_84 . V_85 ) ;
V_86 = F_105 ( V_171 , V_2 , V_48 , V_61 -> V_84 . V_86 ) ;
switch ( V_61 -> V_84 . V_84 [ 0 ] ) {
case '!' :
switch ( V_61 -> V_84 . V_84 [ 1 ] ) {
case 0 :
V_154 = ! V_86 ;
break;
case '=' :
V_154 = V_85 != V_86 ;
break;
default:
goto V_193;
}
break;
case '~' :
V_154 = ~ V_86 ;
break;
case '|' :
if ( V_61 -> V_84 . V_84 [ 1 ] )
V_154 = V_85 || V_86 ;
else
V_154 = V_85 | V_86 ;
break;
case '&' :
if ( V_61 -> V_84 . V_84 [ 1 ] )
V_154 = V_85 && V_86 ;
else
V_154 = V_85 & V_86 ;
break;
case '<' :
switch ( V_61 -> V_84 . V_84 [ 1 ] ) {
case 0 :
V_154 = V_85 < V_86 ;
break;
case '<' :
V_154 = V_85 << V_86 ;
break;
case '=' :
V_154 = V_85 <= V_86 ;
break;
default:
goto V_193;
}
break;
case '>' :
switch ( V_61 -> V_84 . V_84 [ 1 ] ) {
case 0 :
V_154 = V_85 > V_86 ;
break;
case '>' :
V_154 = V_85 >> V_86 ;
break;
case '=' :
V_154 = V_85 >= V_86 ;
break;
default:
goto V_193;
}
break;
case '=' :
if ( V_61 -> V_84 . V_84 [ 1 ] != '=' )
goto V_193;
V_154 = V_85 == V_86 ;
break;
case '-' :
V_154 = V_85 - V_86 ;
break;
case '+' :
V_154 = V_85 + V_86 ;
break;
case '/' :
V_154 = V_85 / V_86 ;
break;
case '*' :
V_154 = V_85 * V_86 ;
break;
default:
goto V_193;
}
break;
default:
return 0 ;
}
return V_154 ;
V_193:
F_46 ( L_103 , V_124 , V_61 -> V_84 . V_84 ) ;
return 0 ;
V_189:
F_46 ( L_104 , V_124 , V_61 -> V_66 . V_67 ) ;
return 0 ;
}
static unsigned long long F_110 ( const char * V_194 )
{
int V_19 ;
if ( isdigit ( V_194 [ 0 ] ) )
return F_106 ( V_194 , NULL , 0 ) ;
for ( V_19 = 0 ; V_19 < ( int ) ( sizeof( V_69 ) / sizeof( V_69 [ 0 ] ) ) ; V_19 ++ )
if ( strcmp ( V_69 [ V_19 ] . V_67 , V_194 ) == 0 )
return V_69 [ V_19 ] . V_59 ;
return 0 ;
}
static void F_111 ( struct V_190 * V_191 , const char * V_138 ,
int V_195 , const char * V_60 )
{
if ( V_195 >= 0 )
F_112 ( V_191 , V_138 , V_195 , V_60 ) ;
else
F_112 ( V_191 , V_138 , V_60 ) ;
}
static void F_113 ( struct V_190 * V_191 , void * V_171 , int V_2 ,
struct V_47 * V_48 , const char * V_138 ,
int V_195 , struct V_7 * V_61 )
{
struct V_14 * V_14 = V_48 -> V_14 ;
struct V_57 * V_194 ;
struct V_114 * V_66 ;
unsigned long long V_154 , V_196 ;
unsigned long V_30 ;
char * V_60 ;
unsigned char * V_75 ;
int V_197 ;
int V_19 , V_128 ;
switch ( V_61 -> type ) {
case V_88 :
return;
case V_63 :
F_111 ( V_191 , V_138 , V_195 , V_61 -> V_64 . V_64 ) ;
return;
case V_65 :
V_66 = V_61 -> V_66 . V_66 ;
if ( ! V_66 ) {
V_66 = F_69 ( V_48 , V_61 -> V_66 . V_67 ) ;
if ( ! V_66 ) {
V_60 = V_61 -> V_66 . V_67 ;
goto V_189;
}
V_61 -> V_66 . V_66 = V_66 ;
}
V_128 = V_66 -> V_2 ? : V_2 - V_66 -> V_134 ;
if ( ! ( V_66 -> V_69 & V_115 ) &&
V_66 -> V_2 == V_14 -> V_137 ) {
V_30 = * ( unsigned long * ) ( V_171 + V_66 -> V_134 ) ;
F_112 ( V_191 , L_105 , V_30 ) ;
break;
}
V_60 = malloc ( V_128 + 1 ) ;
if ( ! V_60 ) {
F_46 ( L_45 , V_124 ) ;
return;
}
memcpy ( V_60 , V_171 + V_66 -> V_134 , V_128 ) ;
V_60 [ V_128 ] = 0 ;
F_111 ( V_191 , V_138 , V_195 , V_60 ) ;
free ( V_60 ) ;
break;
case V_68 :
V_154 = F_105 ( V_171 , V_2 , V_48 , V_61 -> V_69 . V_66 ) ;
V_197 = 0 ;
for ( V_194 = V_61 -> V_69 . V_69 ; V_194 ; V_194 = V_194 -> V_22 ) {
V_196 = F_110 ( V_194 -> V_59 ) ;
if ( ! V_154 && ! V_196 ) {
F_111 ( V_191 , V_138 , V_195 , V_194 -> V_60 ) ;
break;
}
if ( V_196 && ( V_154 & V_196 ) == V_196 ) {
if ( V_197 && V_61 -> V_69 . V_70 )
F_114 ( V_191 , V_61 -> V_69 . V_70 ) ;
F_111 ( V_191 , V_138 , V_195 , V_194 -> V_60 ) ;
V_197 = 1 ;
V_154 &= ~ V_196 ;
}
}
break;
case V_71 :
V_154 = F_105 ( V_171 , V_2 , V_48 , V_61 -> V_72 . V_66 ) ;
for ( V_194 = V_61 -> V_72 . V_73 ; V_194 ; V_194 = V_194 -> V_22 ) {
V_196 = F_110 ( V_194 -> V_59 ) ;
if ( V_154 == V_196 ) {
F_111 ( V_191 , V_138 , V_195 , V_194 -> V_60 ) ;
break;
}
}
break;
case V_74 :
V_66 = V_61 -> V_75 . V_66 -> V_66 . V_66 ;
if ( ! V_66 ) {
V_60 = V_61 -> V_75 . V_66 -> V_66 . V_67 ;
V_66 = F_69 ( V_48 , V_60 ) ;
if ( ! V_66 )
goto V_189;
V_61 -> V_75 . V_66 -> V_66 . V_66 = V_66 ;
}
V_75 = V_171 + V_66 -> V_134 ;
V_128 = F_105 ( V_171 , V_2 , V_48 , V_61 -> V_75 . V_2 ) ;
for ( V_19 = 0 ; V_19 < V_128 ; V_19 ++ ) {
if ( V_19 )
F_115 ( V_191 , ' ' ) ;
F_112 ( V_191 , L_106 , V_75 [ V_19 ] ) ;
}
break;
case V_76 :
break;
case V_78 : {
int V_198 ;
if ( V_61 -> string . V_134 == - 1 ) {
struct V_114 * V_199 ;
V_199 = F_69 ( V_48 , V_61 -> string . string ) ;
V_61 -> string . V_134 = V_199 -> V_134 ;
}
V_198 = F_92 ( V_14 , V_171 + V_61 -> string . V_134 ) ;
V_198 &= 0xffff ;
F_111 ( V_191 , V_138 , V_195 , ( ( char * ) V_171 ) + V_198 ) ;
break;
}
case V_79 :
F_111 ( V_191 , V_138 , V_195 , V_61 -> string . string ) ;
break;
case V_83 :
if ( V_61 -> V_84 . V_84 [ 0 ] != '?' )
return;
V_154 = F_105 ( V_171 , V_2 , V_48 , V_61 -> V_84 . V_85 ) ;
if ( V_154 )
F_113 ( V_191 , V_171 , V_2 , V_48 ,
V_138 , V_195 , V_61 -> V_84 . V_86 -> V_84 . V_85 ) ;
else
F_113 ( V_191 , V_171 , V_2 , V_48 ,
V_138 , V_195 , V_61 -> V_84 . V_86 -> V_84 . V_86 ) ;
break;
case V_87 :
F_108 ( V_191 , V_171 , V_2 , V_48 , V_61 ) ;
break;
default:
break;
}
return;
V_189:
F_46 ( L_104 , V_124 , V_61 -> V_66 . V_67 ) ;
}
static unsigned long long
F_108 ( struct V_190 * V_191 , void * V_171 , int V_2 ,
struct V_47 * V_48 , struct V_7 * V_61 )
{
struct V_162 * V_200 = V_61 -> V_34 . V_34 ;
struct V_201 * V_202 ;
unsigned long long * args ;
unsigned long long V_112 ;
struct V_7 * V_62 ;
struct V_190 V_60 ;
struct V_203 {
struct V_203 * V_22 ;
char * V_60 ;
} * V_204 = NULL , * string ;
int V_19 ;
if ( ! V_200 -> V_167 ) {
V_112 = (* V_200 -> V_34 )( V_191 , NULL ) ;
goto V_103;
}
V_62 = V_61 -> V_34 . args ;
V_202 = V_200 -> V_205 ;
V_112 = V_206 ;
args = malloc ( sizeof( * args ) * V_200 -> V_167 ) ;
if ( ! args )
goto V_103;
for ( V_19 = 0 ; V_19 < V_200 -> V_167 ; V_19 ++ ) {
switch ( V_202 -> type ) {
case V_207 :
case V_208 :
case V_209 :
args [ V_19 ] = F_105 ( V_171 , V_2 , V_48 , V_62 ) ;
break;
case V_210 :
F_107 ( & V_60 ) ;
F_113 ( & V_60 , V_171 , V_2 , V_48 , L_107 , - 1 , V_62 ) ;
F_116 ( & V_60 ) ;
string = malloc ( sizeof( * string ) ) ;
if ( ! string ) {
F_46 ( L_108 , V_124 , __LINE__ ) ;
goto V_37;
}
string -> V_22 = V_204 ;
string -> V_60 = F_12 ( V_60 . V_211 ) ;
if ( ! string -> V_60 ) {
free ( string ) ;
F_46 ( L_108 , V_124 , __LINE__ ) ;
goto V_37;
}
args [ V_19 ] = ( V_212 ) string -> V_60 ;
V_204 = string ;
F_109 ( & V_60 ) ;
break;
default:
F_46 ( L_109 ) ;
goto V_37;
}
V_62 = V_62 -> V_22 ;
V_202 = V_202 -> V_22 ;
}
V_112 = (* V_200 -> V_34 )( V_191 , args ) ;
V_37:
free ( args ) ;
while ( V_204 ) {
string = V_204 ;
V_204 = string -> V_22 ;
free ( string -> V_60 ) ;
free ( string ) ;
}
V_103:
return V_112 ;
}
static void F_117 ( struct V_7 * args )
{
struct V_7 * V_22 ;
while ( args ) {
V_22 = args -> V_22 ;
F_31 ( args ) ;
args = V_22 ;
}
}
static struct V_7 * F_118 ( char * V_46 , void * V_171 , int V_2 , struct V_47 * V_48 )
{
struct V_14 * V_14 = V_48 -> V_14 ;
struct V_114 * V_66 , * V_213 ;
struct V_7 * args , * V_61 , * * V_22 ;
unsigned long long V_214 , V_154 ;
char * V_170 ;
void * V_215 ;
int V_216 ;
V_66 = V_14 -> V_217 ;
V_213 = V_14 -> V_218 ;
if ( ! V_66 ) {
V_66 = F_79 ( V_48 , L_110 ) ;
if ( ! V_66 ) {
F_46 ( L_111 ) ;
return NULL ;
}
V_213 = F_79 ( V_48 , L_112 ) ;
if ( ! V_213 ) {
F_46 ( L_113 ) ;
return NULL ;
}
V_14 -> V_217 = V_66 ;
V_14 -> V_218 = V_213 ;
}
V_214 = F_90 ( V_14 , V_171 + V_213 -> V_134 , V_213 -> V_2 ) ;
args = F_6 () ;
if ( ! args ) {
F_46 ( L_114 , V_124 , __LINE__ ) ;
return NULL ;
}
V_61 = args ;
V_61 -> V_22 = NULL ;
V_22 = & V_61 -> V_22 ;
V_61 -> type = V_63 ;
if ( F_38 ( & V_61 -> V_64 . V_64 , L_79 , V_214 ) < 0 )
goto V_37;
for ( V_170 = V_46 + 6 , V_215 = V_171 + V_66 -> V_134 ;
V_215 < V_171 + V_2 && * V_170 ; V_170 ++ ) {
int V_219 = 0 ;
if ( * V_170 == '%' ) {
V_220:
V_170 ++ ;
switch ( * V_170 ) {
case '%' :
break;
case 'l' :
V_219 ++ ;
goto V_220;
case 'L' :
V_219 = 2 ;
goto V_220;
case '0' ... '9' :
goto V_220;
case '.' :
goto V_220;
case 'p' :
V_219 = 1 ;
case 'd' :
case 'u' :
case 'x' :
case 'i' :
switch ( V_219 ) {
case 0 :
V_216 = 4 ;
break;
case 1 :
V_216 = V_14 -> V_137 ;
break;
case 2 :
V_216 = 8 ;
break;
default:
V_216 = V_219 ;
break;
}
case '*' :
if ( * V_170 == '*' )
V_216 = 4 ;
V_215 = ( void * ) ( ( ( unsigned long ) V_215 + 3 ) &
~ 3 ) ;
V_154 = F_90 ( V_14 , V_215 , V_216 ) ;
V_215 += V_216 ;
V_61 = F_6 () ;
if ( ! V_61 ) {
F_46 ( L_114 ,
V_124 , __LINE__ ) ;
goto V_37;
}
V_61 -> V_22 = NULL ;
V_61 -> type = V_63 ;
if ( F_38 ( & V_61 -> V_64 . V_64 , L_79 , V_154 ) < 0 ) {
free ( V_61 ) ;
goto V_37;
}
* V_22 = V_61 ;
V_22 = & V_61 -> V_22 ;
if ( * V_170 == '*' )
goto V_220;
break;
case 's' :
V_61 = F_6 () ;
if ( ! V_61 ) {
F_46 ( L_114 ,
V_124 , __LINE__ ) ;
goto V_37;
}
V_61 -> V_22 = NULL ;
V_61 -> type = V_79 ;
V_61 -> string . string = F_12 ( V_215 ) ;
if ( ! V_61 -> string . string )
goto V_37;
V_215 += strlen ( V_215 ) + 1 ;
* V_22 = V_61 ;
V_22 = & V_61 -> V_22 ;
default:
break;
}
}
}
return args ;
V_37:
F_117 ( args ) ;
return NULL ;
}
static char *
F_119 ( void * V_171 , int V_2 V_148 ,
struct V_47 * V_48 )
{
struct V_14 * V_14 = V_48 -> V_14 ;
unsigned long long V_30 ;
struct V_114 * V_66 ;
struct V_39 * V_45 ;
char * V_138 ;
char * V_221 ;
V_66 = V_14 -> V_222 ;
if ( ! V_66 ) {
V_66 = F_79 ( V_48 , L_94 ) ;
if ( ! V_66 ) {
F_46 ( L_115 ) ;
return NULL ;
}
V_14 -> V_222 = V_66 ;
}
V_30 = F_90 ( V_14 , V_171 + V_66 -> V_134 , V_66 -> V_2 ) ;
V_45 = F_24 ( V_14 , V_30 ) ;
if ( ! V_45 ) {
if ( F_38 ( & V_138 , L_116 , V_30 ) < 0 )
return NULL ;
return V_138 ;
}
V_221 = V_45 -> V_45 ;
if ( * V_221 == '"' )
V_221 ++ ;
if ( F_38 ( & V_138 , L_117 , L_118 , V_221 ) < 0 )
return NULL ;
V_221 = V_138 + strlen ( V_138 ) - 1 ;
if ( * V_221 == '"' )
* V_221 = 0 ;
V_221 -= 2 ;
if ( strcmp ( V_221 , L_119 ) == 0 )
* V_221 = 0 ;
return V_138 ;
}
static void F_120 ( struct V_190 * V_191 , int V_223 , void * V_171 , int V_2 ,
struct V_47 * V_48 , struct V_7 * V_61 )
{
unsigned char * V_1 ;
const char * V_46 = L_120 ;
if ( V_61 -> type == V_87 ) {
F_108 ( V_191 , V_171 , V_2 , V_48 , V_61 ) ;
return;
}
if ( V_61 -> type != V_65 ) {
F_112 ( V_191 , L_121 ,
V_61 -> type ) ;
return;
}
if ( V_223 == 'm' )
V_46 = L_122 ;
if ( ! V_61 -> V_66 . V_66 ) {
V_61 -> V_66 . V_66 =
F_69 ( V_48 , V_61 -> V_66 . V_67 ) ;
if ( ! V_61 -> V_66 . V_66 ) {
F_46 ( L_104 ,
V_124 , V_61 -> V_66 . V_67 ) ;
return;
}
}
if ( V_61 -> V_66 . V_66 -> V_2 != 6 ) {
F_112 ( V_191 , L_123 ) ;
return;
}
V_1 = V_171 + V_61 -> V_66 . V_66 -> V_134 ;
F_112 ( V_191 , V_46 , V_1 [ 0 ] , V_1 [ 1 ] , V_1 [ 2 ] , V_1 [ 3 ] , V_1 [ 4 ] , V_1 [ 5 ] ) ;
}
static int F_121 ( char * V_221 , unsigned int V_128 )
{
unsigned int V_19 ;
for ( V_19 = 0 ; V_19 < V_128 && V_221 [ V_19 ] ; V_19 ++ )
if ( ! isprint ( V_221 [ V_19 ] ) )
return 0 ;
return 1 ;
}
static void F_122 ( struct V_190 * V_191 , void * V_171 ,
int V_2 V_148 ,
struct V_47 * V_48 )
{
struct V_114 * V_66 ;
unsigned long long V_154 ;
unsigned int V_134 , V_128 , V_19 ;
V_66 = V_48 -> V_138 . V_117 ;
while ( V_66 ) {
F_112 ( V_191 , L_124 , V_66 -> V_67 ) ;
if ( V_66 -> V_69 & V_115 ) {
V_134 = V_66 -> V_134 ;
V_128 = V_66 -> V_2 ;
if ( V_66 -> V_69 & V_131 ) {
V_154 = F_90 ( V_48 -> V_14 , V_171 + V_134 , V_128 ) ;
V_134 = V_154 ;
V_128 = V_134 >> 16 ;
V_134 &= 0xffff ;
}
if ( V_66 -> V_69 & V_130 &&
F_121 ( V_171 + V_134 , V_128 ) ) {
F_112 ( V_191 , L_107 , ( char * ) V_171 + V_134 ) ;
} else {
F_114 ( V_191 , L_125 ) ;
for ( V_19 = 0 ; V_19 < V_128 ; V_19 ++ ) {
if ( V_19 )
F_114 ( V_191 , L_126 ) ;
F_112 ( V_191 , L_106 ,
* ( ( unsigned char * ) V_171 + V_134 + V_19 ) ) ;
}
F_115 ( V_191 , ']' ) ;
V_66 -> V_69 &= ~ V_130 ;
}
} else {
V_154 = F_90 ( V_48 -> V_14 , V_171 + V_66 -> V_134 ,
V_66 -> V_2 ) ;
if ( V_66 -> V_69 & V_122 ) {
F_112 ( V_191 , L_127 , V_154 ) ;
} else if ( V_66 -> V_69 & V_135 ) {
switch ( V_66 -> V_2 ) {
case 4 :
if ( V_66 -> V_69 & V_132 )
F_112 ( V_191 , L_128 , ( int ) V_154 ) ;
else
F_112 ( V_191 , L_129 , ( int ) V_154 ) ;
break;
case 2 :
F_112 ( V_191 , L_130 , ( short ) V_154 ) ;
break;
case 1 :
F_112 ( V_191 , L_131 , ( char ) V_154 ) ;
break;
default:
F_112 ( V_191 , L_79 , V_154 ) ;
}
} else {
if ( V_66 -> V_69 & V_132 )
F_112 ( V_191 , L_127 , V_154 ) ;
else
F_112 ( V_191 , L_132 , V_154 ) ;
}
}
V_66 = V_66 -> V_22 ;
}
}
static void F_123 ( struct V_190 * V_191 , void * V_171 , int V_2 , struct V_47 * V_48 )
{
struct V_14 * V_14 = V_48 -> V_14 ;
struct V_168 * V_168 = & V_48 -> V_168 ;
struct V_7 * V_61 = V_168 -> args ;
struct V_7 * args = NULL ;
const char * V_170 = V_168 -> V_138 ;
unsigned long long V_154 ;
struct V_27 * V_34 ;
const char * V_224 ;
char * V_225 = NULL ;
char V_138 [ 32 ] ;
int V_226 ;
int V_227 ;
int V_195 ;
int V_128 ;
int V_219 ;
if ( V_48 -> V_69 & V_146 ) {
F_112 ( V_191 , L_133 ) ;
F_122 ( V_191 , V_171 , V_2 , V_48 ) ;
return;
}
if ( V_48 -> V_69 & V_228 ) {
V_225 = F_119 ( V_171 , V_2 , V_48 ) ;
args = F_118 ( V_225 , V_171 , V_2 , V_48 ) ;
V_61 = args ;
V_170 = V_225 ;
}
for (; * V_170 ; V_170 ++ ) {
V_219 = 0 ;
if ( * V_170 == '\\' ) {
V_170 ++ ;
switch ( * V_170 ) {
case 'n' :
F_115 ( V_191 , '\n' ) ;
break;
case 't' :
F_115 ( V_191 , '\t' ) ;
break;
case 'r' :
F_115 ( V_191 , '\r' ) ;
break;
case '\\' :
F_115 ( V_191 , '\\' ) ;
break;
default:
F_115 ( V_191 , * V_170 ) ;
break;
}
} else if ( * V_170 == '%' ) {
V_224 = V_170 ;
V_226 = 0 ;
V_227 = 0 ;
V_229:
V_170 ++ ;
switch ( * V_170 ) {
case '%' :
F_115 ( V_191 , '%' ) ;
break;
case '#' :
goto V_229;
case 'h' :
V_219 -- ;
goto V_229;
case 'l' :
V_219 ++ ;
goto V_229;
case 'L' :
V_219 = 2 ;
goto V_229;
case '*' :
if ( ! V_61 ) {
F_46 ( L_134 ) ;
V_48 -> V_69 |= V_146 ;
goto V_230;
}
V_195 = F_105 ( V_171 , V_2 , V_48 , V_61 ) ;
V_227 = 1 ;
V_61 = V_61 -> V_22 ;
goto V_229;
case '.' :
case 'z' :
case 'Z' :
case '0' ... '9' :
goto V_229;
case 'p' :
if ( V_14 -> V_137 == 4 )
V_219 = 1 ;
else
V_219 = 2 ;
if ( * ( V_170 + 1 ) == 'F' ||
* ( V_170 + 1 ) == 'f' ) {
V_170 ++ ;
V_226 = * V_170 ;
} else if ( * ( V_170 + 1 ) == 'M' || * ( V_170 + 1 ) == 'm' ) {
F_120 ( V_191 , * ( V_170 + 1 ) , V_171 , V_2 , V_48 , V_61 ) ;
V_170 ++ ;
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
V_48 -> V_69 |= V_146 ;
goto V_230;
}
V_128 = ( ( unsigned long ) V_170 + 1 ) -
( unsigned long ) V_224 ;
if ( V_128 > 31 ) {
F_46 ( L_135 ) ;
V_48 -> V_69 |= V_146 ;
V_128 = 31 ;
}
memcpy ( V_138 , V_224 , V_128 ) ;
V_138 [ V_128 ] = 0 ;
V_154 = F_105 ( V_171 , V_2 , V_48 , V_61 ) ;
V_61 = V_61 -> V_22 ;
if ( V_226 ) {
V_34 = F_17 ( V_14 , V_154 ) ;
if ( V_34 ) {
F_114 ( V_191 , V_34 -> V_34 ) ;
if ( V_226 == 'F' )
F_112 ( V_191 ,
L_136 ,
V_154 - V_34 -> V_30 ) ;
break;
}
}
if ( V_14 -> V_137 == 8 && V_219 &&
sizeof( long ) != 8 ) {
char * V_221 ;
V_219 = 2 ;
V_221 = strchr ( V_138 , 'l' ) ;
if ( V_221 )
memmove ( V_221 + 1 , V_221 , strlen ( V_221 ) + 1 ) ;
else if ( strcmp ( V_138 , L_137 ) == 0 )
strcpy ( V_138 , L_127 ) ;
}
switch ( V_219 ) {
case - 2 :
if ( V_227 )
F_112 ( V_191 , V_138 , V_195 , ( char ) V_154 ) ;
else
F_112 ( V_191 , V_138 , ( char ) V_154 ) ;
break;
case - 1 :
if ( V_227 )
F_112 ( V_191 , V_138 , V_195 , ( short ) V_154 ) ;
else
F_112 ( V_191 , V_138 , ( short ) V_154 ) ;
break;
case 0 :
if ( V_227 )
F_112 ( V_191 , V_138 , V_195 , ( int ) V_154 ) ;
else
F_112 ( V_191 , V_138 , ( int ) V_154 ) ;
break;
case 1 :
if ( V_227 )
F_112 ( V_191 , V_138 , V_195 , ( long ) V_154 ) ;
else
F_112 ( V_191 , V_138 , ( long ) V_154 ) ;
break;
case 2 :
if ( V_227 )
F_112 ( V_191 , V_138 , V_195 ,
( long long ) V_154 ) ;
else
F_112 ( V_191 , V_138 , ( long long ) V_154 ) ;
break;
default:
F_46 ( L_138 , V_219 ) ;
V_48 -> V_69 |= V_146 ;
}
break;
case 's' :
if ( ! V_61 ) {
F_46 ( L_139 ) ;
V_48 -> V_69 |= V_146 ;
goto V_230;
}
V_128 = ( ( unsigned long ) V_170 + 1 ) -
( unsigned long ) V_224 ;
if ( V_128 > 31 ) {
F_46 ( L_135 ) ;
V_48 -> V_69 |= V_146 ;
V_128 = 31 ;
}
memcpy ( V_138 , V_224 , V_128 ) ;
V_138 [ V_128 ] = 0 ;
if ( ! V_227 )
V_195 = - 1 ;
F_113 ( V_191 , V_171 , V_2 , V_48 ,
V_138 , V_195 , V_61 ) ;
V_61 = V_61 -> V_22 ;
break;
default:
F_112 ( V_191 , L_140 , * V_170 ) ;
}
} else
F_115 ( V_191 , * V_170 ) ;
}
if ( V_48 -> V_69 & V_146 ) {
V_230:
F_112 ( V_191 , L_133 ) ;
}
if ( args ) {
F_117 ( args ) ;
free ( V_225 ) ;
}
}
void F_124 ( struct V_14 * V_14 ,
struct V_190 * V_191 , struct V_231 * V_232 )
{
static int V_233 = 1 ;
static int V_234 = 1 ;
static int V_235 ;
static int V_236 ;
unsigned int V_237 ;
unsigned int V_238 ;
int V_239 ;
int V_240 ;
int V_241 ;
int V_242 ;
void * V_171 = V_232 -> V_171 ;
V_237 = F_100 ( V_14 , V_171 ) ;
V_238 = F_99 ( V_14 , V_171 ) ;
if ( V_235 )
V_239 = F_101 ( V_14 , V_171 ) ;
else if ( V_233 ) {
V_239 = F_101 ( V_14 , V_171 ) ;
if ( V_239 < 0 )
V_233 = 0 ;
else
V_235 = 1 ;
}
if ( V_236 )
V_240 = F_102 ( V_14 , V_171 ) ;
else if ( V_234 ) {
V_240 = F_102 ( V_14 , V_171 ) ;
if ( V_240 < 0 )
V_234 = 0 ;
else
V_236 = 1 ;
}
V_241 = V_237 & V_243 ;
V_242 = V_237 & V_244 ;
F_112 ( V_191 , L_141 ,
( V_237 & V_245 ) ? 'd' :
( V_237 & V_246 ) ?
'X' : '.' ,
( V_237 & V_247 ) ?
'N' : '.' ,
( V_241 && V_242 ) ? 'H' :
V_241 ? 'h' : V_242 ? 's' : '.' ) ;
if ( V_238 )
F_112 ( V_191 , L_142 , V_238 ) ;
else
F_115 ( V_191 , '.' ) ;
if ( V_236 ) {
if ( V_240 < 0 )
F_115 ( V_191 , '.' ) ;
else
F_112 ( V_191 , L_129 , V_240 ) ;
}
if ( V_235 ) {
if ( V_239 < 0 )
F_115 ( V_191 , '.' ) ;
else
F_112 ( V_191 , L_129 , V_239 ) ;
}
F_116 ( V_191 ) ;
}
int F_125 ( struct V_14 * V_14 , struct V_231 * V_248 )
{
return F_97 ( V_14 , V_248 -> V_171 ) ;
}
struct V_47 * F_126 ( struct V_14 * V_14 , int type )
{
return F_103 ( V_14 , type ) ;
}
int F_127 ( struct V_14 * V_14 , struct V_231 * V_248 )
{
return F_98 ( V_14 , V_248 -> V_171 ) ;
}
const char * F_128 ( struct V_14 * V_14 , int V_13 )
{
const char * V_21 ;
V_21 = F_9 ( V_14 , V_13 ) ;
return V_21 ;
}
void F_129 ( struct V_190 * V_191 , struct V_47 * V_48 ,
struct V_231 * V_232 )
{
int V_249 = 1 ;
if ( V_48 -> V_14 -> V_250 )
F_122 ( V_191 , V_232 -> V_171 , V_232 -> V_2 , V_48 ) ;
else {
if ( V_48 -> V_251 )
V_249 = V_48 -> V_251 ( V_191 , V_232 , V_48 ,
V_48 -> V_252 ) ;
if ( V_249 )
F_123 ( V_191 , V_232 -> V_171 , V_232 -> V_2 , V_48 ) ;
}
F_116 ( V_191 ) ;
}
void F_130 ( struct V_14 * V_14 , struct V_190 * V_191 ,
struct V_231 * V_232 )
{
static const char * V_253 = L_143 ;
struct V_47 * V_48 ;
unsigned long V_254 ;
unsigned long V_255 ;
unsigned long V_256 ;
const char * V_21 ;
void * V_171 = V_232 -> V_171 ;
int type ;
int V_13 ;
int V_128 ;
int V_221 ;
V_254 = V_232 -> V_257 / V_258 ;
V_256 = V_232 -> V_257 - V_254 * V_258 ;
if ( V_232 -> V_2 < 0 ) {
F_46 ( L_144 , V_232 -> V_2 ) ;
return;
}
type = F_97 ( V_14 , V_171 ) ;
V_48 = F_103 ( V_14 , type ) ;
if ( ! V_48 ) {
F_46 ( L_145 , type ) ;
return;
}
V_13 = F_98 ( V_14 , V_171 ) ;
V_21 = F_9 ( V_14 , V_13 ) ;
if ( V_14 -> V_259 ) {
F_112 ( V_191 , L_146 ,
V_21 , V_13 , V_232 -> V_260 ) ;
F_124 ( V_14 , V_191 , V_232 ) ;
} else
F_112 ( V_191 , L_147 , V_21 , V_13 , V_232 -> V_260 ) ;
if ( V_14 -> V_69 & V_261 ) {
V_255 = V_256 ;
V_221 = 9 ;
} else {
V_255 = ( V_256 + 500 ) / V_262 ;
V_221 = 6 ;
}
F_112 ( V_191 , L_148 , V_254 , V_221 , V_255 , V_48 -> V_67 ) ;
V_128 = strlen ( V_48 -> V_67 ) ;
if ( V_128 < 20 )
F_112 ( V_191 , L_149 , 20 - V_128 , V_253 ) ;
F_129 ( V_191 , V_48 , V_232 ) ;
}
static int V_184 ( const void * V_8 , const void * V_9 )
{
struct V_47 * const * V_263 = V_8 ;
struct V_47 * const * V_264 = V_9 ;
if ( ( * V_263 ) -> V_51 < ( * V_264 ) -> V_51 )
return - 1 ;
if ( ( * V_263 ) -> V_51 > ( * V_264 ) -> V_51 )
return 1 ;
return 0 ;
}
static int F_131 ( const void * V_8 , const void * V_9 )
{
struct V_47 * const * V_263 = V_8 ;
struct V_47 * const * V_264 = V_9 ;
int V_265 ;
V_265 = strcmp ( ( * V_263 ) -> V_67 , ( * V_264 ) -> V_67 ) ;
if ( V_265 )
return V_265 ;
V_265 = strcmp ( ( * V_263 ) -> system , ( * V_264 ) -> system ) ;
if ( V_265 )
return V_265 ;
return V_184 ( V_8 , V_9 ) ;
}
static int F_132 ( const void * V_8 , const void * V_9 )
{
struct V_47 * const * V_263 = V_8 ;
struct V_47 * const * V_264 = V_9 ;
int V_265 ;
V_265 = strcmp ( ( * V_263 ) -> system , ( * V_264 ) -> system ) ;
if ( V_265 )
return V_265 ;
V_265 = strcmp ( ( * V_263 ) -> V_67 , ( * V_264 ) -> V_67 ) ;
if ( V_265 )
return V_265 ;
return V_184 ( V_8 , V_9 ) ;
}
struct V_47 * * F_133 ( struct V_14 * V_14 , enum V_266 V_267 )
{
struct V_47 * * V_49 ;
int (* F_134)( const void * V_8 , const void * V_9 );
V_49 = V_14 -> V_268 ;
if ( V_49 && V_14 -> V_125 == V_267 )
return V_49 ;
if ( ! V_49 ) {
V_49 = malloc ( sizeof( * V_49 ) * ( V_14 -> V_50 + 1 ) ) ;
if ( ! V_49 )
return NULL ;
memcpy ( V_49 , V_14 -> V_49 , sizeof( * V_49 ) * V_14 -> V_50 ) ;
V_49 [ V_14 -> V_50 ] = NULL ;
V_14 -> V_268 = V_49 ;
if ( V_267 == V_269 ) {
V_14 -> V_125 = V_267 ;
return V_49 ;
}
}
switch ( V_267 ) {
case V_269 :
F_134 = V_184 ;
break;
case V_270 :
F_134 = F_131 ;
break;
case V_271 :
F_134 = F_132 ;
break;
default:
return V_49 ;
}
qsort ( V_49 , V_14 -> V_50 , sizeof( * V_49 ) , F_134 ) ;
V_14 -> V_125 = V_267 ;
return V_49 ;
}
static struct V_114 * *
F_135 ( const char * type , const char * V_67 ,
int V_119 , struct V_114 * V_158 )
{
struct V_114 * * V_117 ;
struct V_114 * V_66 ;
int V_19 = 0 ;
V_117 = malloc ( sizeof( * V_117 ) * ( V_119 + 1 ) ) ;
if ( ! V_117 )
return NULL ;
for ( V_66 = V_158 ; V_66 ; V_66 = V_66 -> V_22 ) {
V_117 [ V_19 ++ ] = V_66 ;
if ( V_19 == V_119 + 1 ) {
F_46 ( L_150 ,
V_67 , type ) ;
V_19 -- ;
break;
}
}
if ( V_19 != V_119 )
F_46 ( L_151 ,
V_67 , type ) ;
V_117 [ V_19 ] = NULL ;
return V_117 ;
}
struct V_114 * * F_136 ( struct V_47 * V_48 )
{
return F_135 ( L_152 , V_48 -> V_67 ,
V_48 -> V_138 . V_140 ,
V_48 -> V_138 . V_139 ) ;
}
struct V_114 * * F_137 ( struct V_47 * V_48 )
{
return F_135 ( L_153 , V_48 -> V_67 ,
V_48 -> V_138 . V_141 ,
V_48 -> V_138 . V_117 ) ;
}
static void F_138 ( struct V_190 * V_191 , struct V_57 * V_66 )
{
F_112 ( V_191 , L_154 , V_66 -> V_59 , V_66 -> V_60 ) ;
if ( V_66 -> V_22 ) {
F_114 ( V_191 , L_126 ) ;
F_138 ( V_191 , V_66 -> V_22 ) ;
}
}
static void F_139 ( struct V_7 * args )
{
int V_272 = 1 ;
struct V_190 V_191 ;
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
F_139 ( args -> V_69 . V_66 ) ;
printf ( L_158 , args -> V_69 . V_70 ) ;
F_107 ( & V_191 ) ;
F_138 ( & V_191 , args -> V_69 . V_69 ) ;
F_140 ( & V_191 ) ;
F_109 ( & V_191 ) ;
printf ( L_68 ) ;
break;
case V_71 :
printf ( L_159 ) ;
F_139 ( args -> V_72 . V_66 ) ;
printf ( L_126 ) ;
F_107 ( & V_191 ) ;
F_138 ( & V_191 , args -> V_72 . V_73 ) ;
F_140 ( & V_191 ) ;
F_109 ( & V_191 ) ;
printf ( L_68 ) ;
break;
case V_74 :
printf ( L_160 ) ;
F_139 ( args -> V_75 . V_66 ) ;
printf ( L_126 ) ;
F_139 ( args -> V_75 . V_2 ) ;
printf ( L_68 ) ;
break;
case V_78 :
case V_79 :
printf ( L_161 , args -> string . string ) ;
break;
case V_76 :
printf ( L_162 , args -> V_77 . type ) ;
F_139 ( args -> V_77 . V_17 ) ;
break;
case V_83 :
if ( strcmp ( args -> V_84 . V_84 , L_18 ) == 0 )
V_272 = 0 ;
if ( V_272 )
printf ( L_83 ) ;
F_139 ( args -> V_84 . V_85 ) ;
printf ( L_163 , args -> V_84 . V_84 ) ;
F_139 ( args -> V_84 . V_86 ) ;
if ( V_272 )
printf ( L_68 ) ;
break;
default:
return;
}
if ( args -> V_22 ) {
printf ( L_6 ) ;
F_139 ( args -> V_22 ) ;
}
}
static void F_141 ( const char * V_66 ,
int * V_134 , int * V_2 , int V_273 )
{
unsigned long long V_105 ;
unsigned long long V_107 ;
char * V_108 ;
int type ;
V_105 = V_5 ;
V_107 = V_4 ;
if ( F_51 ( V_53 , L_31 ) < 0 )
return;
if ( F_51 ( V_94 , L_18 ) < 0 )
return;
if ( F_49 ( V_53 , & V_108 ) < 0 )
goto V_113;
F_40 ( V_108 ) ;
if ( V_273 ) {
if ( F_51 ( V_53 , V_66 ) < 0 )
return;
} else {
if ( F_49 ( V_53 , & V_108 ) < 0 )
goto V_113;
if ( strcmp ( V_108 , V_66 ) != 0 )
goto V_274;
F_40 ( V_108 ) ;
}
if ( F_51 ( V_94 , L_40 ) < 0 )
return;
if ( F_51 ( V_53 , L_41 ) < 0 )
return;
if ( F_51 ( V_94 , L_18 ) < 0 )
return;
if ( F_49 ( V_53 , & V_108 ) < 0 )
goto V_113;
* V_134 = atoi ( V_108 ) ;
F_40 ( V_108 ) ;
if ( F_51 ( V_94 , L_40 ) < 0 )
return;
if ( F_51 ( V_53 , L_42 ) < 0 )
return;
if ( F_51 ( V_94 , L_18 ) < 0 )
return;
if ( F_49 ( V_53 , & V_108 ) < 0 )
goto V_113;
* V_2 = atoi ( V_108 ) ;
F_40 ( V_108 ) ;
if ( F_51 ( V_94 , L_40 ) < 0 )
return;
type = F_41 ( & V_108 ) ;
if ( type != V_90 ) {
if ( type != V_53 )
goto V_113;
if ( strcmp ( V_108 , L_43 ) != 0 )
goto V_113;
F_40 ( V_108 ) ;
if ( F_51 ( V_94 , L_18 ) < 0 )
return;
if ( F_49 ( V_53 , & V_108 ) )
goto V_113;
F_40 ( V_108 ) ;
if ( F_51 ( V_94 , L_40 ) < 0 )
return;
if ( F_49 ( V_90 , & V_108 ) )
goto V_113;
}
V_113:
F_40 ( V_108 ) ;
return;
V_274:
V_5 = V_105 ;
V_4 = V_107 ;
* V_134 = 0 ;
* V_2 = 0 ;
F_40 ( V_108 ) ;
}
int F_142 ( struct V_14 * V_14 , char * V_1 , unsigned long V_2 ,
int V_137 )
{
int V_275 ;
if ( ! V_2 ) {
V_14 -> V_276 = sizeof( long long ) ;
V_14 -> V_277 = V_137 ;
V_14 -> V_278 = sizeof( long long ) + V_137 ;
V_14 -> V_279 = 1 ;
return - 1 ;
}
F_1 ( V_1 , V_2 ) ;
F_141 ( L_164 , & V_14 -> V_280 ,
& V_14 -> V_276 , 1 ) ;
F_141 ( L_165 , & V_14 -> V_281 ,
& V_14 -> V_277 , 1 ) ;
F_141 ( L_166 , & V_14 -> V_282 ,
& V_275 , 0 ) ;
F_141 ( L_167 , & V_14 -> V_278 ,
& V_14 -> V_283 , 1 ) ;
return 0 ;
}
static int F_143 ( struct V_47 * V_48 ,
int V_51 , const char * V_284 ,
const char * V_285 )
{
if ( V_51 >= 0 && V_51 != V_48 -> V_51 )
return 0 ;
if ( V_285 && ( strcmp ( V_285 , V_48 -> V_67 ) != 0 ) )
return 0 ;
if ( V_284 && ( strcmp ( V_284 , V_48 -> system ) != 0 ) )
return 0 ;
return 1 ;
}
static void F_144 ( struct V_286 * V_287 )
{
free ( ( void * ) V_287 -> V_284 ) ;
free ( ( void * ) V_287 -> V_285 ) ;
free ( V_287 ) ;
}
static int F_145 ( struct V_14 * V_14 , struct V_47 * V_48 )
{
struct V_286 * V_287 , * * V_22 ;
for ( V_22 = & V_14 -> V_288 ; * V_22 ;
V_22 = & ( * V_22 ) -> V_22 ) {
V_287 = * V_22 ;
if ( F_143 ( V_48 , V_287 -> V_51 ,
V_287 -> V_284 ,
V_287 -> V_285 ) )
break;
}
if ( ! ( * V_22 ) )
return 0 ;
F_146 ( L_168 ,
V_48 -> V_51 , V_48 -> system , V_48 -> V_67 ) ;
V_48 -> V_251 = V_287 -> V_34 ;
V_48 -> V_252 = V_287 -> V_252 ;
* V_22 = V_287 -> V_22 ;
F_144 ( V_287 ) ;
return 1 ;
}
enum V_289 F_147 ( struct V_47 * * V_290 ,
struct V_14 * V_14 , const char * V_1 ,
unsigned long V_2 , const char * V_185 )
{
struct V_47 * V_48 ;
int V_112 ;
F_1 ( V_1 , V_2 ) ;
* V_290 = V_48 = F_27 () ;
if ( ! V_48 )
return V_291 ;
V_48 -> V_67 = F_53 () ;
if ( ! V_48 -> V_67 ) {
V_112 = V_291 ;
goto V_292;
}
if ( strcmp ( V_185 , L_169 ) == 0 ) {
V_48 -> V_69 |= V_121 ;
if ( strcmp ( V_48 -> V_67 , L_170 ) == 0 )
V_48 -> V_69 |= V_228 ;
}
V_48 -> V_51 = F_54 () ;
if ( V_48 -> V_51 < 0 ) {
V_112 = V_293 ;
goto V_292;
}
V_48 -> system = F_12 ( V_185 ) ;
if ( ! V_48 -> system ) {
V_112 = V_291 ;
goto V_292;
}
V_48 -> V_14 = V_14 ;
V_112 = F_60 ( V_48 ) ;
if ( V_112 < 0 ) {
V_112 = V_294 ;
goto V_295;
}
if ( V_14 && F_145 ( V_14 , V_48 ) )
V_296 = 0 ;
V_112 = F_88 ( V_48 ) ;
V_296 = 1 ;
if ( V_112 < 0 ) {
V_112 = V_297 ;
goto V_295;
}
if ( ! V_112 && ( V_48 -> V_69 & V_121 ) ) {
struct V_114 * V_66 ;
struct V_7 * V_61 , * * V_158 ;
V_158 = & V_48 -> V_168 . args ;
for ( V_66 = V_48 -> V_138 . V_117 ; V_66 ; V_66 = V_66 -> V_22 ) {
V_61 = F_6 () ;
if ( ! V_61 ) {
V_48 -> V_69 |= V_146 ;
return V_298 ;
}
V_61 -> type = V_65 ;
V_61 -> V_66 . V_67 = F_12 ( V_66 -> V_67 ) ;
if ( ! V_61 -> V_66 . V_67 ) {
V_48 -> V_69 |= V_146 ;
F_31 ( V_61 ) ;
return V_298 ;
}
V_61 -> V_66 . V_66 = V_66 ;
* V_158 = V_61 ;
V_158 = & V_61 -> V_22 ;
}
return 0 ;
}
return 0 ;
V_295:
V_48 -> V_69 |= V_146 ;
return V_112 ;
V_292:
free ( V_48 -> system ) ;
free ( V_48 -> V_67 ) ;
free ( V_48 ) ;
* V_290 = NULL ;
return V_112 ;
}
enum V_289 F_148 ( struct V_47 * * V_290 , const char * V_1 ,
unsigned long V_2 , const char * V_185 )
{
return F_147 ( V_290 , NULL , V_1 , V_2 , V_185 ) ;
}
enum V_289 F_149 ( struct V_14 * V_14 , const char * V_1 ,
unsigned long V_2 , const char * V_185 )
{
struct V_47 * V_48 = NULL ;
int V_112 = F_147 ( & V_48 , V_14 , V_1 , V_2 , V_185 ) ;
if ( V_48 == NULL )
return V_112 ;
if ( F_28 ( V_14 , V_48 ) ) {
V_112 = V_291 ;
goto V_299;
}
#define F_150 0
if ( F_150 && V_48 -> V_168 . args )
F_139 ( V_48 -> V_168 . args ) ;
return 0 ;
V_299:
F_151 ( V_48 ) ;
return V_112 ;
}
int F_152 ( struct V_14 * V_14 V_148 ,
enum V_289 V_300 , char * V_1 , T_1 V_301 )
{
int V_302 ;
const char * V_303 ;
if ( V_300 >= 0 ) {
V_303 = F_153 ( V_300 , V_1 , V_301 ) ;
if ( V_303 != V_1 ) {
T_1 V_128 = strlen ( V_303 ) ;
memcpy ( V_1 , V_303 , F_154 ( V_301 - 1 , V_128 ) ) ;
* ( V_1 + F_154 ( V_301 - 1 , V_128 ) ) = '\0' ;
}
return 0 ;
}
if ( V_300 <= V_304 ||
V_300 >= V_305 )
return - 1 ;
V_302 = V_300 - V_304 - 1 ;
V_303 = V_306 [ V_302 ] ;
switch ( V_300 ) {
case V_291 :
case V_307 :
case V_293 :
case V_294 :
case V_297 :
case V_298 :
case V_308 :
snprintf ( V_1 , V_301 , L_107 , V_303 ) ;
break;
default:
break;
}
return 0 ;
}
int F_155 ( struct V_190 * V_191 , struct V_114 * V_66 ,
const char * V_67 , struct V_231 * V_232 ,
unsigned long long * V_154 , int V_309 )
{
if ( ! V_66 ) {
if ( V_309 )
F_112 ( V_191 , L_171 , V_67 ) ;
return - 1 ;
}
if ( F_94 ( V_66 , V_232 -> V_171 , V_154 ) ) {
if ( V_309 )
F_112 ( V_191 , L_172 , V_67 ) ;
return - 1 ;
}
return 0 ;
}
void * F_156 ( struct V_190 * V_191 , struct V_47 * V_48 ,
const char * V_67 , struct V_231 * V_232 ,
int * V_128 , int V_309 )
{
struct V_114 * V_66 ;
void * V_171 = V_232 -> V_171 ;
unsigned V_134 ;
int V_310 ;
if ( ! V_48 )
return NULL ;
V_66 = F_79 ( V_48 , V_67 ) ;
if ( ! V_66 ) {
if ( V_309 )
F_112 ( V_191 , L_171 , V_67 ) ;
return NULL ;
}
if ( ! V_128 )
V_128 = & V_310 ;
V_134 = V_66 -> V_134 ;
if ( V_66 -> V_69 & V_131 ) {
V_134 = F_90 ( V_48 -> V_14 ,
V_171 + V_134 , V_66 -> V_2 ) ;
* V_128 = V_134 >> 16 ;
V_134 &= 0xffff ;
} else
* V_128 = V_66 -> V_2 ;
return V_171 + V_134 ;
}
int F_157 ( struct V_190 * V_191 , struct V_47 * V_48 ,
const char * V_67 , struct V_231 * V_232 ,
unsigned long long * V_154 , int V_309 )
{
struct V_114 * V_66 ;
if ( ! V_48 )
return - 1 ;
V_66 = F_79 ( V_48 , V_67 ) ;
return F_155 ( V_191 , V_66 , V_67 , V_232 , V_154 , V_309 ) ;
}
int F_158 ( struct V_190 * V_191 , struct V_47 * V_48 ,
const char * V_67 , struct V_231 * V_232 ,
unsigned long long * V_154 , int V_309 )
{
struct V_114 * V_66 ;
if ( ! V_48 )
return - 1 ;
V_66 = F_89 ( V_48 , V_67 ) ;
return F_155 ( V_191 , V_66 , V_67 , V_232 , V_154 , V_309 ) ;
}
int F_159 ( struct V_190 * V_191 , struct V_47 * V_48 ,
const char * V_67 , struct V_231 * V_232 ,
unsigned long long * V_154 , int V_309 )
{
struct V_114 * V_66 ;
if ( ! V_48 )
return - 1 ;
V_66 = F_69 ( V_48 , V_67 ) ;
return F_155 ( V_191 , V_66 , V_67 , V_232 , V_154 , V_309 ) ;
}
int F_160 ( struct V_190 * V_191 , const char * V_46 ,
struct V_47 * V_48 , const char * V_67 ,
struct V_231 * V_232 , int V_309 )
{
struct V_114 * V_66 = F_79 ( V_48 , V_67 ) ;
unsigned long long V_154 ;
if ( ! V_66 )
goto V_311;
if ( F_94 ( V_66 , V_232 -> V_171 , & V_154 ) )
goto V_311;
return F_112 ( V_191 , V_46 , V_154 ) ;
V_311:
if ( V_309 )
F_112 ( V_191 , L_173 , V_67 ) ;
return - 1 ;
}
static void F_84 ( struct V_162 * V_34 )
{
struct V_201 * V_205 ;
free ( V_34 -> V_67 ) ;
while ( V_34 -> V_205 ) {
V_205 = V_34 -> V_205 ;
V_34 -> V_205 = V_205 -> V_22 ;
free ( V_205 ) ;
}
free ( V_34 ) ;
}
int F_161 ( struct V_14 * V_14 ,
T_2 V_34 ,
enum V_312 V_313 ,
char * V_67 , ... )
{
struct V_162 * V_200 ;
struct V_201 * * V_314 ;
struct V_201 * V_202 ;
enum V_312 type ;
T_3 V_315 ;
int V_112 ;
V_200 = F_82 ( V_14 , V_67 ) ;
if ( V_200 ) {
F_146 ( L_174 , V_67 ) ;
F_83 ( V_14 , V_67 ) ;
}
V_200 = calloc ( 1 , sizeof( * V_200 ) ) ;
if ( ! V_200 ) {
F_46 ( L_175 ) ;
return V_291 ;
}
V_200 -> V_313 = V_313 ;
V_200 -> V_67 = F_12 ( V_67 ) ;
V_200 -> V_34 = V_34 ;
if ( ! V_200 -> V_67 ) {
F_46 ( L_176 ) ;
free ( V_200 ) ;
return V_291 ;
}
V_314 = & ( V_200 -> V_205 ) ;
va_start ( V_315 , V_67 ) ;
for (; ; ) {
type = va_arg ( V_315 , enum V_312 ) ;
if ( type == V_316 )
break;
if ( type >= V_317 ) {
F_46 ( L_177 , type ) ;
V_112 = V_308 ;
goto V_37;
}
V_202 = malloc ( sizeof( * V_202 ) ) ;
if ( ! V_202 ) {
F_46 ( L_178 ) ;
V_112 = V_291 ;
goto V_37;
}
V_202 -> type = type ;
V_202 -> V_22 = NULL ;
* V_314 = V_202 ;
V_314 = & ( V_202 -> V_22 ) ;
V_200 -> V_167 ++ ;
}
va_end ( V_315 ) ;
V_200 -> V_22 = V_14 -> V_164 ;
V_14 -> V_164 = V_200 ;
return 0 ;
V_37:
va_end ( V_315 ) ;
F_84 ( V_200 ) ;
return V_112 ;
}
int F_162 ( struct V_14 * V_14 ,
int V_51 , char * V_284 , char * V_285 ,
T_4 V_34 ,
void * V_252 )
{
struct V_47 * V_48 ;
struct V_286 * V_287 ;
if ( V_51 >= 0 ) {
V_48 = F_103 ( V_14 , V_51 ) ;
if ( ! V_48 )
goto V_318;
if ( V_285 && ( strcmp ( V_285 , V_48 -> V_67 ) != 0 ) )
goto V_318;
if ( V_284 && ( strcmp ( V_284 , V_48 -> system ) != 0 ) )
goto V_318;
} else {
V_48 = F_104 ( V_14 , V_284 , V_285 ) ;
if ( ! V_48 )
goto V_318;
}
F_146 ( L_168 ,
V_48 -> V_51 , V_48 -> system , V_48 -> V_67 ) ;
V_48 -> V_251 = V_34 ;
V_48 -> V_252 = V_252 ;
return 0 ;
V_318:
V_287 = calloc ( 1 , sizeof( * V_287 ) ) ;
if ( ! V_287 ) {
F_46 ( L_179 ) ;
return V_291 ;
}
V_287 -> V_51 = V_51 ;
if ( V_285 )
V_287 -> V_285 = F_12 ( V_285 ) ;
if ( V_284 )
V_287 -> V_284 = F_12 ( V_284 ) ;
if ( ( V_285 && ! V_287 -> V_285 ) ||
( V_284 && ! V_287 -> V_284 ) ) {
F_46 ( L_180 ) ;
free ( ( void * ) V_287 -> V_285 ) ;
free ( ( void * ) V_287 -> V_284 ) ;
free ( V_287 ) ;
return V_291 ;
}
V_287 -> V_34 = V_34 ;
V_287 -> V_22 = V_14 -> V_288 ;
V_14 -> V_288 = V_287 ;
V_287 -> V_252 = V_252 ;
return - 1 ;
}
struct V_14 * F_163 ( void )
{
struct V_14 * V_14 = calloc ( 1 , sizeof( * V_14 ) ) ;
if ( V_14 )
V_14 -> V_319 = 1 ;
return V_14 ;
}
void F_164 ( struct V_14 * V_14 )
{
V_14 -> V_319 ++ ;
}
static void F_165 ( struct V_114 * V_66 )
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
static void F_166 ( struct V_138 * V_138 )
{
F_165 ( V_138 -> V_139 ) ;
F_165 ( V_138 -> V_117 ) ;
}
void F_151 ( struct V_47 * V_48 )
{
free ( V_48 -> V_67 ) ;
free ( V_48 -> system ) ;
F_166 ( & V_48 -> V_138 ) ;
free ( V_48 -> V_168 . V_138 ) ;
F_117 ( V_48 -> V_168 . args ) ;
free ( V_48 ) ;
}
void F_167 ( struct V_14 * V_14 )
{
struct V_15 * V_16 , * V_320 ;
struct V_31 * V_32 , * V_321 ;
struct V_42 * V_43 , * V_322 ;
struct V_162 * V_323 ;
struct V_286 * V_287 ;
int V_19 ;
if ( ! V_14 )
return;
V_16 = V_14 -> V_16 ;
V_32 = V_14 -> V_32 ;
V_43 = V_14 -> V_43 ;
V_14 -> V_319 -- ;
if ( V_14 -> V_319 )
return;
if ( V_14 -> V_18 ) {
for ( V_19 = 0 ; V_19 < V_14 -> V_20 ; V_19 ++ )
free ( V_14 -> V_18 [ V_19 ] . V_21 ) ;
free ( V_14 -> V_18 ) ;
}
while ( V_16 ) {
V_320 = V_16 -> V_22 ;
free ( V_16 -> V_21 ) ;
free ( V_16 ) ;
V_16 = V_320 ;
}
if ( V_14 -> V_27 ) {
for ( V_19 = 0 ; V_19 < ( int ) V_14 -> V_33 ; V_19 ++ ) {
free ( V_14 -> V_27 [ V_19 ] . V_34 ) ;
free ( V_14 -> V_27 [ V_19 ] . V_35 ) ;
}
free ( V_14 -> V_27 ) ;
}
while ( V_32 ) {
V_321 = V_32 -> V_22 ;
free ( V_32 -> V_34 ) ;
free ( V_32 -> V_35 ) ;
free ( V_32 ) ;
V_32 = V_321 ;
}
while ( V_14 -> V_164 ) {
V_323 = V_14 -> V_164 ;
V_14 -> V_164 = V_323 -> V_22 ;
F_84 ( V_323 ) ;
}
if ( V_14 -> V_39 ) {
for ( V_19 = 0 ; V_19 < ( int ) V_14 -> V_44 ; V_19 ++ )
free ( V_14 -> V_39 [ V_19 ] . V_45 ) ;
free ( V_14 -> V_39 ) ;
}
while ( V_43 ) {
V_322 = V_43 -> V_22 ;
free ( V_43 -> V_45 ) ;
free ( V_43 ) ;
V_43 = V_322 ;
}
for ( V_19 = 0 ; V_19 < V_14 -> V_50 ; V_19 ++ )
F_151 ( V_14 -> V_49 [ V_19 ] ) ;
while ( V_14 -> V_288 ) {
V_287 = V_14 -> V_288 ;
V_14 -> V_288 = V_287 -> V_22 ;
F_144 ( V_287 ) ;
}
free ( V_14 -> V_49 ) ;
free ( V_14 -> V_268 ) ;
free ( V_14 ) ;
}
void F_168 ( struct V_14 * V_14 )
{
F_167 ( V_14 ) ;
}
