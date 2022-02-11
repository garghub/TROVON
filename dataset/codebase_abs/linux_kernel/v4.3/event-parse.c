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
int F_19 ( struct V_14 * V_14 ,
T_1 * V_35 , void * V_37 )
{
struct V_38 * V_39 = malloc ( sizeof( * V_39 ) ) ;
if ( V_39 == NULL )
return - 1 ;
V_39 -> V_35 = V_35 ;
V_39 -> V_37 = V_37 ;
free ( V_14 -> V_38 ) ;
V_14 -> V_38 = V_39 ;
return 0 ;
}
void F_20 ( struct V_14 * V_14 )
{
free ( V_14 -> V_38 ) ;
V_14 -> V_38 = NULL ;
}
static struct V_28 *
F_21 ( struct V_14 * V_14 , unsigned long long V_31 )
{
struct V_28 * V_40 ;
if ( ! V_14 -> V_38 )
return F_18 ( V_14 , V_31 ) ;
V_40 = & V_14 -> V_38 -> V_40 ;
V_40 -> V_36 = NULL ;
V_40 -> V_31 = V_31 ;
V_40 -> V_35 = V_14 -> V_38 -> V_35 ( V_14 -> V_38 -> V_37 ,
& V_40 -> V_31 , & V_40 -> V_36 ) ;
if ( V_40 -> V_35 == NULL )
return NULL ;
return V_40 ;
}
const char * F_22 ( struct V_14 * V_14 , unsigned long long V_31 )
{
struct V_28 * V_40 ;
V_40 = F_21 ( V_14 , V_31 ) ;
if ( ! V_40 )
return NULL ;
return V_40 -> V_35 ;
}
unsigned long long
F_23 ( struct V_14 * V_14 , unsigned long long V_31 )
{
struct V_28 * V_40 ;
V_40 = F_21 ( V_14 , V_31 ) ;
if ( ! V_40 )
return 0 ;
return V_40 -> V_31 ;
}
int F_24 ( struct V_14 * V_14 , char * V_35 ,
unsigned long long V_31 , char * V_36 )
{
struct V_32 * V_17 = malloc ( sizeof( * V_17 ) ) ;
if ( ! V_17 )
return - 1 ;
V_17 -> V_22 = V_14 -> V_33 ;
V_17 -> V_35 = F_12 ( V_35 ) ;
if ( ! V_17 -> V_35 )
goto V_41;
if ( V_36 ) {
V_17 -> V_36 = F_12 ( V_36 ) ;
if ( ! V_17 -> V_36 )
goto V_42;
} else
V_17 -> V_36 = NULL ;
V_17 -> V_31 = V_31 ;
V_14 -> V_33 = V_17 ;
V_14 -> V_34 ++ ;
return 0 ;
V_42:
free ( V_17 -> V_35 ) ;
V_17 -> V_35 = NULL ;
V_41:
free ( V_17 ) ;
V_24 = V_26 ;
return - 1 ;
}
void F_25 ( struct V_14 * V_14 )
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
static int F_26 ( const void * V_8 , const void * V_9 )
{
const struct V_43 * V_44 = V_8 ;
const struct V_43 * V_45 = V_9 ;
if ( V_44 -> V_31 < V_45 -> V_31 )
return - 1 ;
if ( V_44 -> V_31 > V_45 -> V_31 )
return 1 ;
return 0 ;
}
static int F_27 ( struct V_14 * V_14 )
{
struct V_46 * V_47 ;
struct V_46 * V_17 ;
struct V_43 * V_43 ;
int V_19 ;
V_43 = malloc ( sizeof( * V_43 ) * ( V_14 -> V_48 + 1 ) ) ;
if ( ! V_43 )
return - 1 ;
V_47 = V_14 -> V_47 ;
V_19 = 0 ;
while ( V_47 ) {
V_43 [ V_19 ] . V_49 = V_47 -> V_49 ;
V_43 [ V_19 ] . V_31 = V_47 -> V_31 ;
V_19 ++ ;
V_17 = V_47 ;
V_47 = V_47 -> V_22 ;
free ( V_17 ) ;
}
qsort ( V_43 , V_14 -> V_48 , sizeof( * V_43 ) , F_26 ) ;
V_14 -> V_43 = V_43 ;
V_14 -> V_47 = NULL ;
return 0 ;
}
static struct V_43 *
F_28 ( struct V_14 * V_14 , unsigned long long V_31 )
{
struct V_43 * V_49 ;
struct V_43 V_23 ;
if ( ! V_14 -> V_43 && F_27 ( V_14 ) )
return NULL ;
V_23 . V_31 = V_31 ;
V_49 = bsearch ( & V_23 , V_14 -> V_43 , V_14 -> V_48 ,
sizeof( * V_14 -> V_43 ) , F_26 ) ;
return V_49 ;
}
int F_29 ( struct V_14 * V_14 , const char * V_50 ,
unsigned long long V_31 )
{
struct V_46 * V_17 = malloc ( sizeof( * V_17 ) ) ;
char * V_51 ;
if ( ! V_17 )
return - 1 ;
V_17 -> V_22 = V_14 -> V_47 ;
V_17 -> V_31 = V_31 ;
if ( V_50 [ 0 ] == '"' )
V_50 ++ ;
V_17 -> V_49 = F_12 ( V_50 ) ;
if ( ! V_17 -> V_49 )
goto V_41;
V_51 = V_17 -> V_49 + strlen ( V_17 -> V_49 ) - 1 ;
if ( * V_51 == '"' )
* V_51 = 0 ;
V_51 -= 2 ;
if ( strcmp ( V_51 , L_7 ) == 0 )
* V_51 = 0 ;
V_14 -> V_47 = V_17 ;
V_14 -> V_48 ++ ;
return 0 ;
V_41:
free ( V_17 ) ;
V_24 = V_26 ;
return - 1 ;
}
void F_30 ( struct V_14 * V_14 )
{
int V_19 ;
if ( ! V_14 -> V_43 )
F_27 ( V_14 ) ;
for ( V_19 = 0 ; V_19 < ( int ) V_14 -> V_48 ; V_19 ++ ) {
printf ( L_8 ,
V_14 -> V_43 [ V_19 ] . V_31 ,
V_14 -> V_43 [ V_19 ] . V_49 ) ;
}
}
static struct V_52 * F_31 ( void )
{
return calloc ( 1 , sizeof( struct V_52 ) ) ;
}
static int F_32 ( struct V_14 * V_14 , struct V_52 * V_53 )
{
int V_19 ;
struct V_52 * * V_54 = realloc ( V_14 -> V_54 , sizeof( V_53 ) *
( V_14 -> V_55 + 1 ) ) ;
if ( ! V_54 )
return - 1 ;
V_14 -> V_54 = V_54 ;
for ( V_19 = 0 ; V_19 < V_14 -> V_55 ; V_19 ++ ) {
if ( V_14 -> V_54 [ V_19 ] -> V_56 > V_53 -> V_56 )
break;
}
if ( V_19 < V_14 -> V_55 )
memmove ( & V_14 -> V_54 [ V_19 + 1 ] ,
& V_14 -> V_54 [ V_19 ] ,
sizeof( V_53 ) * ( V_14 -> V_55 - V_19 ) ) ;
V_14 -> V_54 [ V_19 ] = V_53 ;
V_14 -> V_55 ++ ;
V_53 -> V_14 = V_14 ;
return 0 ;
}
static int F_33 ( enum V_57 type )
{
switch ( type ) {
case V_58 ... V_59 :
return 1 ;
case V_60 ... V_61 :
default:
return 0 ;
}
}
static void F_34 ( struct V_62 * V_63 )
{
struct V_62 * V_22 ;
while ( V_63 ) {
V_22 = V_63 -> V_22 ;
free ( V_63 -> V_64 ) ;
free ( V_63 -> V_65 ) ;
free ( V_63 ) ;
V_63 = V_22 ;
}
}
static void F_35 ( struct V_7 * V_66 )
{
struct V_7 * V_67 ;
if ( ! V_66 )
return;
switch ( V_66 -> type ) {
case V_68 :
free ( V_66 -> V_69 . V_69 ) ;
break;
case V_70 :
free ( V_66 -> V_71 . V_72 ) ;
break;
case V_73 :
F_35 ( V_66 -> V_74 . V_71 ) ;
free ( V_66 -> V_74 . V_75 ) ;
F_34 ( V_66 -> V_74 . V_74 ) ;
break;
case V_76 :
F_35 ( V_66 -> V_77 . V_71 ) ;
F_34 ( V_66 -> V_77 . V_78 ) ;
break;
case V_79 :
F_35 ( V_66 -> V_80 . V_71 ) ;
F_35 ( V_66 -> V_80 . V_2 ) ;
break;
case V_81 :
F_35 ( V_66 -> V_82 . V_71 ) ;
F_35 ( V_66 -> V_82 . V_83 ) ;
F_35 ( V_66 -> V_82 . V_84 ) ;
break;
case V_85 :
free ( V_66 -> V_86 . type ) ;
F_35 ( V_66 -> V_86 . V_17 ) ;
break;
case V_87 :
case V_88 :
free ( V_66 -> string . string ) ;
break;
case V_89 :
free ( V_66 -> V_90 . V_90 ) ;
break;
case V_91 :
free ( V_66 -> V_92 . V_93 ) ;
break;
case V_94 :
free ( V_66 -> V_95 . V_95 ) ;
F_35 ( V_66 -> V_95 . V_96 ) ;
F_35 ( V_66 -> V_95 . V_97 ) ;
break;
case V_98 :
while ( V_66 -> V_35 . args ) {
V_67 = V_66 -> V_35 . args ;
V_66 -> V_35 . args = V_67 -> V_22 ;
F_35 ( V_67 ) ;
}
break;
case V_99 :
default:
break;
}
free ( V_66 ) ;
}
static enum V_57 F_36 ( int V_100 )
{
if ( V_100 == '\n' )
return V_101 ;
if ( isspace ( V_100 ) )
return V_102 ;
if ( isalnum ( V_100 ) || V_100 == '_' )
return V_58 ;
if ( V_100 == '\'' )
return V_59 ;
if ( V_100 == '"' )
return V_103 ;
if ( ! isprint ( V_100 ) )
return V_104 ;
if ( V_100 == '(' || V_100 == ')' || V_100 == ',' )
return V_61 ;
return V_105 ;
}
static int F_37 ( void )
{
if ( V_5 >= V_4 )
return - 1 ;
return V_3 [ V_5 ++ ] ;
}
static int F_38 ( void )
{
if ( V_5 >= V_4 )
return - 1 ;
return V_3 [ V_5 ] ;
}
int F_39 ( void )
{
return F_38 () ;
}
static int F_40 ( char * * V_106 , char * V_1 , int V_2 )
{
char * V_107 = realloc ( * V_106 , V_2 ) ;
if ( ! V_107 ) {
free ( * V_106 ) ;
* V_106 = NULL ;
return - 1 ;
}
if ( ! * V_106 )
strcpy ( V_107 , V_1 ) ;
else
strcat ( V_107 , V_1 ) ;
* V_106 = V_107 ;
return 0 ;
}
static enum V_57 F_41 ( char * * V_106 )
{
char V_1 [ V_108 ] ;
int V_100 , V_109 , V_110 , V_111 ;
int V_19 = 0 ;
int V_112 = 0 ;
enum V_57 type ;
* V_106 = NULL ;
V_100 = F_37 () ;
if ( V_100 < 0 )
return V_104 ;
type = F_36 ( V_100 ) ;
if ( type == V_104 )
return type ;
V_1 [ V_19 ++ ] = V_100 ;
switch ( type ) {
case V_101 :
case V_61 :
if ( F_42 ( V_106 , L_9 , V_100 ) < 0 )
return V_60 ;
return type ;
case V_105 :
switch ( V_100 ) {
case '-' :
V_111 = F_38 () ;
if ( V_111 == '>' ) {
V_1 [ V_19 ++ ] = F_37 () ;
break;
}
case '+' :
case '|' :
case '&' :
case '>' :
case '<' :
V_109 = V_100 ;
V_100 = F_38 () ;
if ( V_100 != V_109 )
goto V_113;
V_1 [ V_19 ++ ] = F_37 () ;
switch ( V_109 ) {
case '>' :
case '<' :
goto V_113;
default:
break;
}
break;
case '!' :
case '=' :
goto V_113;
default:
break;
}
V_1 [ V_19 ] = 0 ;
* V_106 = F_12 ( V_1 ) ;
return type ;
V_113:
V_100 = F_38 () ;
if ( V_100 == '=' )
V_1 [ V_19 ++ ] = F_37 () ;
goto V_114;
case V_103 :
case V_59 :
V_19 -- ;
V_110 = V_100 ;
V_109 = 0 ;
V_115:
do {
if ( V_19 == ( V_108 - 1 ) ) {
V_1 [ V_19 ] = 0 ;
V_112 += V_108 ;
if ( F_40 ( V_106 , V_1 , V_112 ) < 0 )
return V_104 ;
V_19 = 0 ;
}
V_109 = V_100 ;
V_100 = F_37 () ;
V_1 [ V_19 ++ ] = V_100 ;
if ( V_100 == '\\' && V_109 == '\\' )
V_109 = 0 ;
} while ( V_100 != V_110 || V_109 == '\\' );
V_19 -- ;
if ( type == V_103 ) {
unsigned long long V_116 = V_5 ;
do {
V_100 = F_37 () ;
} while ( isspace ( V_100 ) );
if ( V_100 == '"' )
goto V_115;
V_5 = V_116 ;
}
goto V_114;
case V_60 ... V_102 :
case V_58 :
default:
break;
}
while ( F_36 ( F_38 () ) == type ) {
if ( V_19 == ( V_108 - 1 ) ) {
V_1 [ V_19 ] = 0 ;
V_112 += V_108 ;
if ( F_40 ( V_106 , V_1 , V_112 ) < 0 )
return V_104 ;
V_19 = 0 ;
}
V_100 = F_37 () ;
V_1 [ V_19 ++ ] = V_100 ;
}
V_114:
V_1 [ V_19 ] = 0 ;
if ( F_40 ( V_106 , V_1 , V_112 + V_19 + 1 ) < 0 )
return V_104 ;
if ( type == V_58 ) {
if ( strcmp ( * V_106 , L_10 ) == 0 ) {
free ( * V_106 ) ;
* V_106 = NULL ;
return F_43 ( L_11 , V_106 ) ;
} else if ( strcmp ( * V_106 , L_12 ) == 0 ) {
free ( * V_106 ) ;
* V_106 = NULL ;
return F_43 ( L_13 , V_106 ) ;
} else if ( strcmp ( * V_106 , L_14 ) == 0 ) {
free ( * V_106 ) ;
* V_106 = NULL ;
return F_43 ( L_15 , V_106 ) ;
}
}
return type ;
}
static enum V_57 F_43 ( const char * V_65 , char * * V_106 )
{
const char * V_117 ;
unsigned long long V_116 ;
unsigned long long V_118 ;
enum V_57 type ;
V_117 = V_3 ;
V_116 = V_5 ;
V_118 = V_4 ;
F_1 ( V_65 , strlen ( V_65 ) ) ;
type = F_41 ( V_106 ) ;
V_3 = V_117 ;
V_5 = V_116 ;
V_4 = V_118 ;
return type ;
}
static void F_44 ( char * V_106 )
{
if ( V_106 )
free ( V_106 ) ;
}
static enum V_57 F_45 ( char * * V_106 )
{
enum V_57 type ;
for (; ; ) {
type = F_41 ( V_106 ) ;
if ( type != V_102 )
return type ;
F_44 ( * V_106 ) ;
}
* V_106 = NULL ;
return V_104 ;
}
enum V_57 F_46 ( char * * V_106 )
{
return F_45 ( V_106 ) ;
}
void F_47 ( char * V_119 )
{
F_44 ( V_119 ) ;
}
static enum V_57 F_48 ( char * * V_106 )
{
enum V_57 type ;
for (; ; ) {
type = F_41 ( V_106 ) ;
if ( type != V_102 && type != V_101 )
return type ;
F_44 ( * V_106 ) ;
* V_106 = NULL ;
}
* V_106 = NULL ;
return V_104 ;
}
static int F_49 ( enum V_57 type , enum V_57 V_120 )
{
if ( type != V_120 ) {
F_50 ( L_16 ,
V_120 , type ) ;
return - 1 ;
}
return 0 ;
}
static int F_51 ( enum V_57 type , const char * V_119 ,
enum V_57 V_120 , const char * V_121 )
{
if ( type != V_120 ) {
F_50 ( L_16 ,
V_120 , type ) ;
return - 1 ;
}
if ( strcmp ( V_119 , V_121 ) != 0 ) {
F_50 ( L_17 ,
V_121 , V_119 ) ;
return - 1 ;
}
return 0 ;
}
static int F_52 ( enum V_57 V_120 , char * * V_106 , int V_122 )
{
enum V_57 type ;
if ( V_122 )
type = F_45 ( V_106 ) ;
else
type = F_48 ( V_106 ) ;
return F_49 ( type , V_120 ) ;
}
static int F_53 ( enum V_57 V_120 , char * * V_106 )
{
return F_52 ( V_120 , V_106 , 1 ) ;
}
static int F_54 ( enum V_57 V_120 , const char * V_65 ,
int V_122 )
{
enum V_57 type ;
char * V_119 ;
int V_123 ;
if ( V_122 )
type = F_45 ( & V_119 ) ;
else
type = F_48 ( & V_119 ) ;
V_123 = F_51 ( type , V_119 , V_120 , V_65 ) ;
F_44 ( V_119 ) ;
return V_123 ;
}
static int F_55 ( enum V_57 V_120 , const char * V_65 )
{
return F_54 ( V_120 , V_65 , 1 ) ;
}
static int F_56 ( enum V_57 V_120 , const char * V_65 )
{
return F_54 ( V_120 , V_65 , 0 ) ;
}
static char * F_57 ( void )
{
char * V_119 ;
if ( F_55 ( V_58 , L_18 ) < 0 )
return NULL ;
if ( F_55 ( V_105 , L_19 ) < 0 )
return NULL ;
if ( F_53 ( V_58 , & V_119 ) < 0 )
goto V_124;
return V_119 ;
V_124:
F_44 ( V_119 ) ;
return NULL ;
}
static int F_58 ( void )
{
char * V_119 ;
int V_56 ;
if ( F_56 ( V_58 , L_20 ) < 0 )
return - 1 ;
if ( F_55 ( V_105 , L_19 ) < 0 )
return - 1 ;
if ( F_53 ( V_58 , & V_119 ) < 0 )
goto V_124;
V_56 = strtoul ( V_119 , NULL , 0 ) ;
F_44 ( V_119 ) ;
return V_56 ;
V_124:
F_44 ( V_119 ) ;
return - 1 ;
}
static int F_59 ( struct V_125 * V_71 )
{
if ( ( V_71 -> V_74 & V_126 ) &&
( strstr ( V_71 -> type , L_21 ) || strstr ( V_71 -> type , L_22 ) ||
strstr ( V_71 -> type , L_23 ) ) )
return 1 ;
return 0 ;
}
static int F_60 ( struct V_125 * V_71 )
{
if ( strncmp ( V_71 -> type , L_24 , 10 ) == 0 )
return 1 ;
return 0 ;
}
static int F_61 ( struct V_125 * V_71 )
{
if ( strstr ( V_71 -> type , L_25 ) )
return 1 ;
return 0 ;
}
static unsigned int F_62 ( const char * V_72 )
{
static struct {
const char * type ;
unsigned int V_2 ;
} V_127 [] = {
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
for ( V_19 = 0 ; V_127 [ V_19 ] . type ; V_19 ++ ) {
if ( ! strcmp ( V_127 [ V_19 ] . type , V_72 ) )
return V_127 [ V_19 ] . V_2 ;
}
return 0 ;
}
static int F_63 ( struct V_52 * V_53 , struct V_125 * * V_128 )
{
struct V_125 * V_71 = NULL ;
enum V_57 type ;
char * V_119 ;
char * V_129 ;
int V_83 = 0 ;
do {
unsigned int V_130 = 0 ;
type = F_45 ( & V_119 ) ;
if ( type == V_101 ) {
F_44 ( V_119 ) ;
return V_83 ;
}
V_83 ++ ;
if ( F_51 ( type , V_119 , V_58 , L_32 ) )
goto V_124;
F_44 ( V_119 ) ;
type = F_45 ( & V_119 ) ;
if ( V_53 -> V_74 & V_131 &&
type == V_58 && strcmp ( V_119 , L_33 ) == 0 ) {
F_44 ( V_119 ) ;
type = F_45 ( & V_119 ) ;
}
if ( F_51 ( type , V_119 , V_105 , L_19 ) < 0 )
goto V_124;
F_44 ( V_119 ) ;
if ( F_53 ( V_58 , & V_119 ) < 0 )
goto V_124;
V_129 = V_119 ;
V_71 = calloc ( 1 , sizeof( * V_71 ) ) ;
if ( ! V_71 )
goto V_124;
V_71 -> V_53 = V_53 ;
for (; ; ) {
type = F_45 ( & V_119 ) ;
if ( type == V_58 ||
( type == V_105 && strcmp ( V_119 , L_34 ) == 0 ) ||
( V_53 -> V_74 & V_131 &&
type == V_105 && strcmp ( V_119 , L_35 ) == 0 ) ) {
if ( strcmp ( V_119 , L_34 ) == 0 )
V_71 -> V_74 |= V_132 ;
if ( V_71 -> type ) {
char * V_133 ;
V_133 = realloc ( V_71 -> type ,
strlen ( V_71 -> type ) +
strlen ( V_129 ) + 2 ) ;
if ( ! V_133 ) {
free ( V_129 ) ;
goto V_124;
}
V_71 -> type = V_133 ;
strcat ( V_71 -> type , L_36 ) ;
strcat ( V_71 -> type , V_129 ) ;
free ( V_129 ) ;
} else
V_71 -> type = V_129 ;
V_129 = V_119 ;
continue;
}
break;
}
if ( ! V_71 -> type ) {
F_64 ( V_53 , L_37 , V_134 ) ;
goto V_124;
}
V_71 -> V_72 = V_71 -> V_135 = V_129 ;
if ( F_49 ( type , V_105 ) )
goto V_124;
if ( strcmp ( V_119 , L_38 ) == 0 ) {
enum V_57 V_136 = type ;
char * V_137 = V_119 ;
char * V_138 ;
int V_139 ;
V_71 -> V_74 |= V_126 ;
type = F_45 ( & V_119 ) ;
if ( type == V_58 )
V_71 -> V_140 = strtoul ( V_119 , NULL , 0 ) ;
else
V_71 -> V_140 = 0 ;
while ( strcmp ( V_119 , L_39 ) != 0 ) {
if ( V_136 == V_58 &&
type == V_58 )
V_139 = 2 ;
else
V_139 = 1 ;
V_136 = type ;
V_138 = realloc ( V_137 ,
strlen ( V_137 ) +
strlen ( V_119 ) + V_139 ) ;
if ( ! V_138 ) {
free ( V_137 ) ;
goto V_124;
}
V_137 = V_138 ;
if ( V_139 == 2 )
strcat ( V_137 , L_36 ) ;
strcat ( V_137 , V_119 ) ;
V_71 -> V_140 = strtoul ( V_119 , NULL , 0 ) ;
F_44 ( V_119 ) ;
type = F_45 ( & V_119 ) ;
if ( type == V_104 ) {
F_64 ( V_53 , L_40 ) ;
goto V_124;
}
}
F_44 ( V_119 ) ;
V_138 = realloc ( V_137 , strlen ( V_137 ) + 2 ) ;
if ( ! V_138 ) {
free ( V_137 ) ;
goto V_124;
}
V_137 = V_138 ;
strcat ( V_137 , L_39 ) ;
type = F_45 ( & V_119 ) ;
if ( type == V_58 ) {
char * V_133 ;
V_133 = realloc ( V_71 -> type ,
strlen ( V_71 -> type ) +
strlen ( V_71 -> V_72 ) +
strlen ( V_137 ) + 2 ) ;
if ( ! V_133 ) {
free ( V_137 ) ;
goto V_124;
}
V_71 -> type = V_133 ;
strcat ( V_71 -> type , L_36 ) ;
strcat ( V_71 -> type , V_71 -> V_72 ) ;
V_130 = F_62 ( V_71 -> V_72 ) ;
F_44 ( V_71 -> V_72 ) ;
strcat ( V_71 -> type , V_137 ) ;
V_71 -> V_72 = V_71 -> V_135 = V_119 ;
type = F_45 ( & V_119 ) ;
} else {
char * V_133 ;
V_133 = realloc ( V_71 -> type ,
strlen ( V_71 -> type ) +
strlen ( V_137 ) + 1 ) ;
if ( ! V_133 ) {
free ( V_137 ) ;
goto V_124;
}
V_71 -> type = V_133 ;
strcat ( V_71 -> type , V_137 ) ;
}
free ( V_137 ) ;
}
if ( F_59 ( V_71 ) )
V_71 -> V_74 |= V_141 ;
if ( F_60 ( V_71 ) )
V_71 -> V_74 |= V_142 ;
if ( F_61 ( V_71 ) )
V_71 -> V_74 |= V_143 ;
if ( F_51 ( type , V_119 , V_105 , L_41 ) )
goto V_124;
F_44 ( V_119 ) ;
if ( F_55 ( V_58 , L_42 ) < 0 )
goto V_144;
if ( F_55 ( V_105 , L_19 ) < 0 )
goto V_144;
if ( F_53 ( V_58 , & V_119 ) )
goto V_124;
V_71 -> V_145 = strtoul ( V_119 , NULL , 0 ) ;
F_44 ( V_119 ) ;
if ( F_55 ( V_105 , L_41 ) < 0 )
goto V_144;
if ( F_55 ( V_58 , L_43 ) < 0 )
goto V_144;
if ( F_55 ( V_105 , L_19 ) < 0 )
goto V_144;
if ( F_53 ( V_58 , & V_119 ) )
goto V_124;
V_71 -> V_2 = strtoul ( V_119 , NULL , 0 ) ;
F_44 ( V_119 ) ;
if ( F_55 ( V_105 , L_41 ) < 0 )
goto V_144;
type = F_45 ( & V_119 ) ;
if ( type != V_101 ) {
if ( F_51 ( type , V_119 , V_58 , L_44 ) )
goto V_124;
F_44 ( V_119 ) ;
if ( F_55 ( V_105 , L_19 ) < 0 )
goto V_144;
if ( F_53 ( V_58 , & V_119 ) )
goto V_124;
if ( strtoul ( V_119 , NULL , 0 ) )
V_71 -> V_74 |= V_146 ;
F_44 ( V_119 ) ;
if ( F_55 ( V_105 , L_41 ) < 0 )
goto V_144;
if ( F_53 ( V_101 , & V_119 ) )
goto V_124;
}
F_44 ( V_119 ) ;
if ( V_71 -> V_74 & V_126 ) {
if ( V_71 -> V_140 )
V_71 -> V_147 = V_71 -> V_2 / V_71 -> V_140 ;
else if ( V_71 -> V_74 & V_142 )
V_71 -> V_147 = V_130 ;
else if ( V_71 -> V_74 & V_141 )
V_71 -> V_147 = 1 ;
else if ( V_71 -> V_74 & V_143 )
V_71 -> V_147 = V_53 -> V_14 ?
V_53 -> V_14 -> V_148 :
sizeof( long ) ;
} else
V_71 -> V_147 = V_71 -> V_2 ;
* V_128 = V_71 ;
V_128 = & V_71 -> V_22 ;
} while ( 1 );
return 0 ;
V_124:
F_44 ( V_119 ) ;
V_144:
if ( V_71 ) {
free ( V_71 -> type ) ;
free ( V_71 -> V_72 ) ;
free ( V_71 ) ;
}
return - 1 ;
}
static int F_65 ( struct V_52 * V_53 )
{
char * V_119 ;
int V_123 ;
if ( F_56 ( V_58 , L_45 ) < 0 )
return - 1 ;
if ( F_55 ( V_105 , L_19 ) < 0 )
return - 1 ;
if ( F_53 ( V_101 , & V_119 ) )
goto V_124;
F_44 ( V_119 ) ;
V_123 = F_63 ( V_53 , & V_53 -> V_149 . V_150 ) ;
if ( V_123 < 0 )
return V_123 ;
V_53 -> V_149 . V_151 = V_123 ;
V_123 = F_63 ( V_53 , & V_53 -> V_149 . V_128 ) ;
if ( V_123 < 0 )
return V_123 ;
V_53 -> V_149 . V_152 = V_123 ;
return 0 ;
V_124:
F_44 ( V_119 ) ;
return - 1 ;
}
static enum V_57
F_66 ( struct V_52 * V_53 , struct V_7 * V_66 , char * * V_106 )
{
enum V_57 type ;
char * V_119 ;
type = F_45 ( & V_119 ) ;
* V_106 = V_119 ;
return F_67 ( V_53 , V_66 , V_106 , type ) ;
}
static enum V_57
F_68 ( struct V_52 * V_53 , struct V_7 * V_66 , char * * V_106 )
{
enum V_57 type ;
type = F_66 ( V_53 , V_66 , V_106 ) ;
while ( type == V_105 ) {
type = F_69 ( V_53 , V_66 , V_106 ) ;
}
return type ;
}
static enum V_57
F_70 ( struct V_52 * V_53 , struct V_7 * V_153 , char * * V_106 )
{
struct V_7 * V_66 , * V_96 , * V_97 ;
enum V_57 type ;
char * V_119 = NULL ;
V_66 = F_6 () ;
V_96 = F_6 () ;
V_97 = F_6 () ;
if ( ! V_66 || ! V_96 || ! V_97 ) {
F_64 ( V_53 , L_46 , V_134 ) ;
F_35 ( V_96 ) ;
F_35 ( V_97 ) ;
goto V_41;
}
V_66 -> type = V_94 ;
V_66 -> V_95 . V_96 = V_96 ;
V_66 -> V_95 . V_97 = V_97 ;
* V_106 = NULL ;
type = F_66 ( V_53 , V_96 , & V_119 ) ;
V_154:
if ( type == V_60 )
goto V_41;
if ( type == V_105 && strcmp ( V_119 , L_19 ) != 0 ) {
type = F_69 ( V_53 , V_96 , & V_119 ) ;
goto V_154;
}
if ( F_51 ( type , V_119 , V_105 , L_19 ) )
goto V_41;
V_66 -> V_95 . V_95 = V_119 ;
type = F_66 ( V_53 , V_97 , & V_119 ) ;
V_153 -> V_95 . V_97 = V_66 ;
* V_106 = V_119 ;
return type ;
V_41:
V_153 -> V_95 . V_97 = NULL ;
F_44 ( V_119 ) ;
F_35 ( V_66 ) ;
return V_60 ;
}
static enum V_57
F_71 ( struct V_52 * V_53 , struct V_7 * V_153 , char * * V_106 )
{
struct V_7 * V_66 ;
enum V_57 type ;
char * V_119 = NULL ;
V_66 = F_6 () ;
if ( ! V_66 ) {
F_64 ( V_53 , L_46 , V_134 ) ;
* V_106 = NULL ;
return V_60 ;
}
* V_106 = NULL ;
type = F_66 ( V_53 , V_66 , & V_119 ) ;
if ( F_51 ( type , V_119 , V_105 , L_39 ) )
goto V_41;
V_153 -> V_95 . V_97 = V_66 ;
F_44 ( V_119 ) ;
type = F_48 ( & V_119 ) ;
* V_106 = V_119 ;
return type ;
V_41:
F_44 ( V_119 ) ;
F_35 ( V_66 ) ;
return V_60 ;
}
static int F_72 ( char * V_95 )
{
if ( ! V_95 [ 1 ] ) {
switch ( V_95 [ 0 ] ) {
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
F_50 ( L_47 , V_95 [ 0 ] ) ;
return - 1 ;
}
} else {
if ( strcmp ( V_95 , L_48 ) == 0 ||
strcmp ( V_95 , L_49 ) == 0 ) {
return 3 ;
} else if ( strcmp ( V_95 , L_50 ) == 0 ||
strcmp ( V_95 , L_51 ) == 0 ) {
return 8 ;
} else if ( strcmp ( V_95 , L_52 ) == 0 ||
strcmp ( V_95 , L_53 ) == 0 ) {
return 9 ;
} else if ( strcmp ( V_95 , L_54 ) == 0 ||
strcmp ( V_95 , L_55 ) == 0 ) {
return 10 ;
} else if ( strcmp ( V_95 , L_56 ) == 0 ) {
return 14 ;
} else if ( strcmp ( V_95 , L_57 ) == 0 ) {
return 15 ;
} else {
F_50 ( L_58 , V_95 ) ;
return - 1 ;
}
}
}
static int F_73 ( struct V_7 * V_66 )
{
if ( ! V_66 -> V_95 . V_96 || V_66 -> V_95 . V_96 -> type == V_99 )
V_66 -> V_95 . V_155 = 0 ;
else
V_66 -> V_95 . V_155 = F_72 ( V_66 -> V_95 . V_95 ) ;
return V_66 -> V_95 . V_155 ;
}
static enum V_57
F_69 ( struct V_52 * V_53 , struct V_7 * V_66 , char * * V_106 )
{
struct V_7 * V_96 , * V_97 = NULL ;
enum V_57 type ;
char * V_119 ;
V_119 = * V_106 ;
if ( V_66 -> type == V_94 && ! V_66 -> V_95 . V_96 ) {
if ( V_119 [ 1 ] ) {
F_64 ( V_53 , L_59 , V_119 ) ;
goto V_41;
}
switch ( V_119 [ 0 ] ) {
case '~' :
case '!' :
case '+' :
case '-' :
break;
default:
F_64 ( V_53 , L_59 , V_119 ) ;
goto V_41;
}
V_96 = F_6 () ;
if ( ! V_96 )
goto V_156;
V_96 -> type = V_99 ;
V_66 -> V_95 . V_96 = V_96 ;
V_97 = F_6 () ;
if ( ! V_97 )
goto V_156;
V_66 -> V_95 . V_97 = V_97 ;
* V_106 = NULL ;
type = F_66 ( V_53 , V_97 , V_106 ) ;
} else if ( strcmp ( V_119 , L_60 ) == 0 ) {
V_96 = F_6 () ;
if ( ! V_96 )
goto V_156;
* V_96 = * V_66 ;
V_66 -> type = V_94 ;
V_66 -> V_95 . V_95 = V_119 ;
V_66 -> V_95 . V_96 = V_96 ;
V_66 -> V_95 . V_155 = 0 ;
type = F_70 ( V_53 , V_66 , V_106 ) ;
} else if ( strcmp ( V_119 , L_50 ) == 0 ||
strcmp ( V_119 , L_51 ) == 0 ||
strcmp ( V_119 , L_61 ) == 0 ||
strcmp ( V_119 , L_62 ) == 0 ||
strcmp ( V_119 , L_56 ) == 0 ||
strcmp ( V_119 , L_57 ) == 0 ||
strcmp ( V_119 , L_63 ) == 0 ||
strcmp ( V_119 , L_64 ) == 0 ||
strcmp ( V_119 , L_34 ) == 0 ||
strcmp ( V_119 , L_65 ) == 0 ||
strcmp ( V_119 , L_66 ) == 0 ||
strcmp ( V_119 , L_67 ) == 0 ||
strcmp ( V_119 , L_68 ) == 0 ||
strcmp ( V_119 , L_53 ) == 0 ||
strcmp ( V_119 , L_52 ) == 0 ||
strcmp ( V_119 , L_54 ) == 0 ||
strcmp ( V_119 , L_55 ) == 0 ) {
V_96 = F_6 () ;
if ( ! V_96 )
goto V_156;
* V_96 = * V_66 ;
V_66 -> type = V_94 ;
V_66 -> V_95 . V_95 = V_119 ;
V_66 -> V_95 . V_96 = V_96 ;
V_66 -> V_95 . V_97 = NULL ;
if ( F_73 ( V_66 ) == - 1 ) {
V_53 -> V_74 |= V_157 ;
V_66 -> V_95 . V_95 = NULL ;
goto V_41;
}
type = F_48 ( & V_119 ) ;
* V_106 = V_119 ;
if ( ( strcmp ( V_66 -> V_95 . V_95 , L_34 ) == 0 ) &&
type == V_61 && ( strcmp ( V_119 , L_69 ) == 0 ) ) {
char * V_158 ;
if ( V_96 -> type != V_68 ) {
F_64 ( V_53 , L_70 ) ;
goto V_41;
}
V_158 = realloc ( V_96 -> V_69 . V_69 ,
strlen ( V_96 -> V_69 . V_69 ) + 3 ) ;
if ( ! V_158 )
goto V_156;
V_96 -> V_69 . V_69 = V_158 ;
strcat ( V_96 -> V_69 . V_69 , L_71 ) ;
free ( V_66 -> V_95 . V_95 ) ;
* V_66 = * V_96 ;
free ( V_96 ) ;
return type ;
}
V_97 = F_6 () ;
if ( ! V_97 )
goto V_156;
type = F_67 ( V_53 , V_97 , V_106 , type ) ;
if ( type == V_60 ) {
F_35 ( V_97 ) ;
V_119 = NULL ;
goto V_41;
}
if ( V_97 -> type == V_94 &&
F_72 ( V_66 -> V_95 . V_95 ) < F_72 ( V_97 -> V_95 . V_95 ) ) {
struct V_7 V_159 ;
V_66 -> V_95 . V_97 = V_97 -> V_95 . V_96 ;
V_159 = * V_66 ;
* V_66 = * V_97 ;
* V_97 = V_159 ;
V_66 -> V_95 . V_96 = V_97 ;
} else {
V_66 -> V_95 . V_97 = V_97 ;
}
} else if ( strcmp ( V_119 , L_38 ) == 0 ) {
V_96 = F_6 () ;
if ( ! V_96 )
goto V_156;
* V_96 = * V_66 ;
V_66 -> type = V_94 ;
V_66 -> V_95 . V_95 = V_119 ;
V_66 -> V_95 . V_96 = V_96 ;
V_66 -> V_95 . V_155 = 0 ;
type = F_71 ( V_53 , V_66 , V_106 ) ;
} else {
F_64 ( V_53 , L_58 , V_119 ) ;
V_53 -> V_74 |= V_157 ;
goto V_41;
}
if ( type == V_105 && strcmp ( * V_106 , L_19 ) != 0 ) {
int V_155 ;
V_155 = F_72 ( * V_106 ) ;
if ( V_155 > V_66 -> V_95 . V_155 )
return F_69 ( V_53 , V_66 , V_106 ) ;
return F_69 ( V_53 , V_97 , V_106 ) ;
}
return type ;
V_156:
F_64 ( V_53 , L_46 , V_134 ) ;
V_41:
F_44 ( V_119 ) ;
* V_106 = NULL ;
return V_60 ;
}
static enum V_57
F_74 ( struct V_52 * V_53 V_160 , struct V_7 * V_66 ,
char * * V_106 )
{
enum V_57 type ;
char * V_71 ;
char * V_119 ;
if ( F_55 ( V_105 , L_72 ) < 0 )
goto V_161;
if ( F_53 ( V_58 , & V_119 ) < 0 )
goto V_41;
V_71 = V_119 ;
V_66 -> type = V_70 ;
V_66 -> V_71 . V_72 = V_71 ;
if ( V_162 ) {
V_66 -> V_71 . V_71 = F_75 ( V_53 , V_66 -> V_71 . V_72 ) ;
V_66 -> V_71 . V_71 -> V_74 |= V_163 ;
V_162 = 0 ;
} else if ( V_164 ) {
V_66 -> V_71 . V_71 = F_75 ( V_53 , V_66 -> V_71 . V_72 ) ;
V_66 -> V_71 . V_71 -> V_74 |= V_165 ;
V_164 = 0 ;
}
type = F_45 ( & V_119 ) ;
* V_106 = V_119 ;
return type ;
V_41:
F_44 ( V_119 ) ;
V_161:
* V_106 = NULL ;
return V_60 ;
}
static int F_76 ( struct V_52 * V_53 , char * V_166 ,
struct V_7 * * V_7 )
{
struct V_7 * V_71 ;
enum V_57 type ;
char * V_119 ;
int V_123 = 0 ;
V_71 = F_6 () ;
if ( ! V_71 ) {
F_64 ( V_53 , L_46 , V_134 ) ;
V_24 = V_26 ;
return - 1 ;
}
type = F_66 ( V_53 , V_71 , & V_119 ) ;
if ( F_51 ( type , V_119 , V_61 , V_166 ) ) {
V_24 = V_167 ;
V_123 = - 1 ;
F_35 ( V_71 ) ;
goto V_168;
}
* V_7 = V_71 ;
V_168:
F_44 ( V_119 ) ;
return V_123 ;
}
static unsigned long long
F_77 ( unsigned long long V_169 , const char * type , int V_170 )
{
int V_171 = 0 ;
char * V_172 ;
int V_139 ;
V_139 = strlen ( type ) ;
if ( V_170 ) {
if ( type [ V_139 - 1 ] != '*' ) {
F_50 ( L_73 ) ;
return V_169 ;
}
V_172 = malloc ( V_139 ) ;
if ( ! V_172 ) {
F_50 ( L_46 , V_134 ) ;
return V_169 ;
}
memcpy ( V_172 , type , V_139 ) ;
V_172 [ V_139 - 2 ] = 0 ;
V_169 = F_77 ( V_169 , V_172 , 0 ) ;
free ( V_172 ) ;
return V_169 ;
}
if ( type [ V_139 - 1 ] == '*' )
return V_169 ;
if ( strncmp ( type , L_74 , 6 ) == 0 )
return V_169 ;
if ( strcmp ( type , L_22 ) == 0 )
return V_169 & 0xff ;
if ( strcmp ( type , L_26 ) == 0 )
return V_169 & 0xffff ;
if ( strcmp ( type , L_27 ) == 0 )
return V_169 & 0xffffffff ;
if ( strcmp ( type , L_28 ) == 0 ||
strcmp ( type , L_31 ) )
return V_169 ;
if ( strcmp ( type , L_23 ) == 0 )
return ( unsigned long long ) ( char ) V_169 & 0xff ;
if ( strcmp ( type , L_29 ) == 0 )
return ( unsigned long long ) ( short ) V_169 & 0xffff ;
if ( strcmp ( type , L_30 ) == 0 )
return ( unsigned long long ) ( int ) V_169 & 0xffffffff ;
if ( strncmp ( type , L_75 , 9 ) == 0 ) {
V_171 = 0 ;
type += 9 ;
}
if ( strcmp ( type , L_21 ) == 0 ) {
if ( V_171 )
return ( unsigned long long ) ( char ) V_169 & 0xff ;
else
return V_169 & 0xff ;
}
if ( strcmp ( type , L_76 ) == 0 ) {
if ( V_171 )
return ( unsigned long long ) ( short ) V_169 & 0xffff ;
else
return V_169 & 0xffff ;
}
if ( strcmp ( type , L_77 ) == 0 ) {
if ( V_171 )
return ( unsigned long long ) ( int ) V_169 & 0xffffffff ;
else
return V_169 & 0xffffffff ;
}
return V_169 ;
}
static unsigned long long
F_78 ( unsigned long long V_169 , struct V_7 * V_66 , int V_170 )
{
if ( V_66 -> type != V_85 ) {
F_50 ( L_78 ) ;
return 0 ;
}
return F_77 ( V_169 , V_66 -> V_86 . type , V_170 ) ;
}
static int F_79 ( struct V_7 * V_66 , long long * V_169 )
{
long long V_96 , V_97 ;
int V_123 = 1 ;
switch ( V_66 -> type ) {
case V_68 :
* V_169 = strtoll ( V_66 -> V_69 . V_69 , NULL , 0 ) ;
break;
case V_85 :
V_123 = F_79 ( V_66 -> V_86 . V_17 , V_169 ) ;
if ( ! V_123 )
break;
* V_169 = F_78 ( * V_169 , V_66 , 0 ) ;
break;
case V_94 :
switch ( V_66 -> V_95 . V_95 [ 0 ] ) {
case '|' :
V_123 = F_79 ( V_66 -> V_95 . V_96 , & V_96 ) ;
if ( ! V_123 )
break;
V_123 = F_79 ( V_66 -> V_95 . V_97 , & V_97 ) ;
if ( ! V_123 )
break;
if ( V_66 -> V_95 . V_95 [ 1 ] )
* V_169 = V_96 || V_97 ;
else
* V_169 = V_96 | V_97 ;
break;
case '&' :
V_123 = F_79 ( V_66 -> V_95 . V_96 , & V_96 ) ;
if ( ! V_123 )
break;
V_123 = F_79 ( V_66 -> V_95 . V_97 , & V_97 ) ;
if ( ! V_123 )
break;
if ( V_66 -> V_95 . V_95 [ 1 ] )
* V_169 = V_96 && V_97 ;
else
* V_169 = V_96 & V_97 ;
break;
case '<' :
V_123 = F_79 ( V_66 -> V_95 . V_96 , & V_96 ) ;
if ( ! V_123 )
break;
V_123 = F_79 ( V_66 -> V_95 . V_97 , & V_97 ) ;
if ( ! V_123 )
break;
switch ( V_66 -> V_95 . V_95 [ 1 ] ) {
case 0 :
* V_169 = V_96 < V_97 ;
break;
case '<' :
* V_169 = V_96 << V_97 ;
break;
case '=' :
* V_169 = V_96 <= V_97 ;
break;
default:
F_50 ( L_58 , V_66 -> V_95 . V_95 ) ;
V_123 = 0 ;
}
break;
case '>' :
V_123 = F_79 ( V_66 -> V_95 . V_96 , & V_96 ) ;
if ( ! V_123 )
break;
V_123 = F_79 ( V_66 -> V_95 . V_97 , & V_97 ) ;
if ( ! V_123 )
break;
switch ( V_66 -> V_95 . V_95 [ 1 ] ) {
case 0 :
* V_169 = V_96 > V_97 ;
break;
case '>' :
* V_169 = V_96 >> V_97 ;
break;
case '=' :
* V_169 = V_96 >= V_97 ;
break;
default:
F_50 ( L_58 , V_66 -> V_95 . V_95 ) ;
V_123 = 0 ;
}
break;
case '=' :
V_123 = F_79 ( V_66 -> V_95 . V_96 , & V_96 ) ;
if ( ! V_123 )
break;
V_123 = F_79 ( V_66 -> V_95 . V_97 , & V_97 ) ;
if ( ! V_123 )
break;
if ( V_66 -> V_95 . V_95 [ 1 ] != '=' ) {
F_50 ( L_58 , V_66 -> V_95 . V_95 ) ;
V_123 = 0 ;
} else
* V_169 = V_96 == V_97 ;
break;
case '!' :
V_123 = F_79 ( V_66 -> V_95 . V_96 , & V_96 ) ;
if ( ! V_123 )
break;
V_123 = F_79 ( V_66 -> V_95 . V_97 , & V_97 ) ;
if ( ! V_123 )
break;
switch ( V_66 -> V_95 . V_95 [ 1 ] ) {
case '=' :
* V_169 = V_96 != V_97 ;
break;
default:
F_50 ( L_58 , V_66 -> V_95 . V_95 ) ;
V_123 = 0 ;
}
break;
case '-' :
if ( V_66 -> V_95 . V_96 -> type == V_99 )
V_96 = 0 ;
else
V_123 = F_79 ( V_66 -> V_95 . V_96 , & V_96 ) ;
if ( ! V_123 )
break;
V_123 = F_79 ( V_66 -> V_95 . V_97 , & V_97 ) ;
if ( ! V_123 )
break;
* V_169 = V_96 - V_97 ;
break;
case '+' :
if ( V_66 -> V_95 . V_96 -> type == V_99 )
V_96 = 0 ;
else
V_123 = F_79 ( V_66 -> V_95 . V_96 , & V_96 ) ;
if ( ! V_123 )
break;
V_123 = F_79 ( V_66 -> V_95 . V_97 , & V_97 ) ;
if ( ! V_123 )
break;
* V_169 = V_96 + V_97 ;
break;
default:
F_50 ( L_58 , V_66 -> V_95 . V_95 ) ;
V_123 = 0 ;
}
break;
case V_99 :
case V_70 ... V_76 :
case V_87 :
case V_88 :
case V_89 :
default:
F_50 ( L_79 , V_66 -> type ) ;
V_123 = 0 ;
}
return V_123 ;
}
static char * F_80 ( struct V_7 * V_66 )
{
long long V_169 ;
static char V_1 [ 20 ] ;
switch ( V_66 -> type ) {
case V_68 :
return V_66 -> V_69 . V_69 ;
case V_85 :
return F_80 ( V_66 -> V_86 . V_17 ) ;
case V_94 :
if ( ! F_79 ( V_66 , & V_169 ) )
break;
sprintf ( V_1 , L_80 , V_169 ) ;
return V_1 ;
case V_99 :
case V_70 ... V_76 :
case V_87 :
case V_88 :
case V_89 :
default:
F_50 ( L_79 , V_66 -> type ) ;
break;
}
return NULL ;
}
static enum V_57
F_81 ( struct V_52 * V_53 , struct V_62 * * V_173 , char * * V_106 )
{
enum V_57 type ;
struct V_7 * V_66 = NULL ;
struct V_62 * V_71 ;
char * V_119 = * V_106 ;
char * V_64 ;
do {
F_44 ( V_119 ) ;
type = F_48 ( & V_119 ) ;
if ( F_51 ( type , V_119 , V_105 , L_81 ) )
break;
V_66 = F_6 () ;
if ( ! V_66 )
goto V_41;
F_44 ( V_119 ) ;
type = F_66 ( V_53 , V_66 , & V_119 ) ;
if ( type == V_105 )
type = F_69 ( V_53 , V_66 , & V_119 ) ;
if ( type == V_60 )
goto V_41;
if ( F_51 ( type , V_119 , V_61 , L_82 ) )
goto V_41;
V_71 = calloc ( 1 , sizeof( * V_71 ) ) ;
if ( ! V_71 )
goto V_41;
V_64 = F_80 ( V_66 ) ;
if ( V_64 == NULL )
goto V_174;
V_71 -> V_64 = F_12 ( V_64 ) ;
if ( V_71 -> V_64 == NULL )
goto V_174;
F_35 ( V_66 ) ;
V_66 = F_6 () ;
if ( ! V_66 )
goto V_41;
F_44 ( V_119 ) ;
type = F_66 ( V_53 , V_66 , & V_119 ) ;
if ( F_51 ( type , V_119 , V_105 , L_83 ) )
goto V_174;
V_64 = F_80 ( V_66 ) ;
if ( V_64 == NULL )
goto V_174;
V_71 -> V_65 = F_12 ( V_64 ) ;
if ( V_71 -> V_65 == NULL )
goto V_174;
F_35 ( V_66 ) ;
V_66 = NULL ;
* V_173 = V_71 ;
V_173 = & V_71 -> V_22 ;
F_44 ( V_119 ) ;
type = F_48 ( & V_119 ) ;
} while ( type == V_61 && strcmp ( V_119 , L_82 ) == 0 );
* V_106 = V_119 ;
return type ;
V_174:
F_34 ( V_71 ) ;
V_41:
F_35 ( V_66 ) ;
F_44 ( V_119 ) ;
* V_106 = NULL ;
return V_60 ;
}
static enum V_57
F_82 ( struct V_52 * V_53 , struct V_7 * V_66 , char * * V_106 )
{
struct V_7 * V_71 ;
enum V_57 type ;
char * V_119 = NULL ;
memset ( V_66 , 0 , sizeof( * V_66 ) ) ;
V_66 -> type = V_73 ;
V_71 = F_6 () ;
if ( ! V_71 ) {
F_64 ( V_53 , L_46 , V_134 ) ;
goto V_41;
}
type = F_68 ( V_53 , V_71 , & V_119 ) ;
while ( type == V_105 )
type = F_69 ( V_53 , V_71 , & V_119 ) ;
if ( F_51 ( type , V_119 , V_61 , L_82 ) )
goto V_174;
F_44 ( V_119 ) ;
V_66 -> V_74 . V_71 = V_71 ;
type = F_48 ( & V_119 ) ;
if ( F_33 ( type ) ) {
V_66 -> V_74 . V_75 = V_119 ;
type = F_48 ( & V_119 ) ;
}
if ( F_51 ( type , V_119 , V_61 , L_82 ) )
goto V_41;
type = F_81 ( V_53 , & V_66 -> V_74 . V_74 , & V_119 ) ;
if ( F_51 ( type , V_119 , V_61 , L_69 ) )
goto V_41;
F_44 ( V_119 ) ;
type = F_48 ( V_106 ) ;
return type ;
V_174:
F_35 ( V_71 ) ;
V_41:
F_44 ( V_119 ) ;
* V_106 = NULL ;
return V_60 ;
}
static enum V_57
F_83 ( struct V_52 * V_53 , struct V_7 * V_66 , char * * V_106 )
{
struct V_7 * V_71 ;
enum V_57 type ;
char * V_119 = NULL ;
memset ( V_66 , 0 , sizeof( * V_66 ) ) ;
V_66 -> type = V_76 ;
V_71 = F_6 () ;
if ( ! V_71 ) {
F_64 ( V_53 , L_46 , V_134 ) ;
goto V_41;
}
type = F_68 ( V_53 , V_71 , & V_119 ) ;
if ( F_51 ( type , V_119 , V_61 , L_82 ) )
goto V_174;
V_66 -> V_77 . V_71 = V_71 ;
type = F_81 ( V_53 , & V_66 -> V_77 . V_78 , & V_119 ) ;
if ( F_51 ( type , V_119 , V_61 , L_69 ) )
goto V_41;
F_44 ( V_119 ) ;
type = F_48 ( V_106 ) ;
return type ;
V_174:
F_35 ( V_71 ) ;
V_41:
F_44 ( V_119 ) ;
* V_106 = NULL ;
return V_60 ;
}
static enum V_57
F_84 ( struct V_52 * V_53 , struct V_7 * V_66 , char * * V_106 )
{
memset ( V_66 , 0 , sizeof( * V_66 ) ) ;
V_66 -> type = V_79 ;
if ( F_76 ( V_53 , L_82 , & V_66 -> V_80 . V_71 ) )
goto V_114;
if ( F_76 ( V_53 , L_69 , & V_66 -> V_80 . V_2 ) )
goto V_175;
return F_48 ( V_106 ) ;
V_175:
F_35 ( V_66 -> V_80 . V_71 ) ;
V_114:
* V_106 = NULL ;
return V_60 ;
}
static enum V_57
F_85 ( struct V_52 * V_53 , struct V_7 * V_66 , char * * V_106 )
{
memset ( V_66 , 0 , sizeof( * V_66 ) ) ;
V_66 -> type = V_81 ;
if ( F_76 ( V_53 , L_82 , & V_66 -> V_82 . V_71 ) )
goto V_114;
if ( F_76 ( V_53 , L_82 , & V_66 -> V_82 . V_83 ) )
goto V_175;
if ( F_76 ( V_53 , L_69 , & V_66 -> V_82 . V_84 ) )
goto V_176;
return F_48 ( V_106 ) ;
V_176:
F_35 ( V_66 -> V_82 . V_83 ) ;
V_175:
F_35 ( V_66 -> V_82 . V_71 ) ;
V_114:
* V_106 = NULL ;
return V_60 ;
}
static enum V_57
F_86 ( struct V_52 * V_53 , struct V_7 * V_66 , char * * V_106 )
{
struct V_125 * V_71 ;
enum V_57 type ;
char * V_119 ;
memset ( V_66 , 0 , sizeof( * V_66 ) ) ;
V_66 -> type = V_91 ;
type = F_45 ( & V_119 ) ;
* V_106 = V_119 ;
if ( type != V_58 )
goto V_41;
V_71 = F_87 ( V_53 , V_119 ) ;
if ( ! V_71 )
goto V_41;
V_66 -> V_92 . V_71 = V_71 ;
V_66 -> V_92 . V_93 = 0 ;
if ( F_55 ( V_61 , L_69 ) < 0 )
goto V_41;
F_44 ( V_119 ) ;
type = F_48 ( & V_119 ) ;
* V_106 = V_119 ;
if ( type != V_105 || strcmp ( V_119 , L_38 ) != 0 )
return type ;
F_44 ( V_119 ) ;
V_66 = F_6 () ;
if ( ! V_66 ) {
F_64 ( V_53 , L_46 , V_134 ) ;
* V_106 = NULL ;
return V_60 ;
}
type = F_66 ( V_53 , V_66 , & V_119 ) ;
if ( type == V_60 )
goto V_177;
if ( ! F_51 ( type , V_119 , V_105 , L_39 ) )
goto V_177;
F_44 ( V_119 ) ;
type = F_48 ( V_106 ) ;
return type ;
V_177:
F_35 ( V_66 ) ;
V_41:
F_44 ( V_119 ) ;
* V_106 = NULL ;
return V_60 ;
}
static enum V_57
F_88 ( struct V_52 * V_53 , struct V_7 * V_66 , char * * V_106 )
{
struct V_7 * V_178 ;
enum V_57 type ;
char * V_119 ;
type = F_66 ( V_53 , V_66 , & V_119 ) ;
if ( type == V_60 )
goto V_41;
if ( type == V_105 )
type = F_69 ( V_53 , V_66 , & V_119 ) ;
if ( type == V_60 )
goto V_41;
if ( F_51 ( type , V_119 , V_61 , L_69 ) )
goto V_41;
F_44 ( V_119 ) ;
type = F_48 ( & V_119 ) ;
if ( F_33 ( type ) ||
( type == V_61 && strcmp ( V_119 , L_84 ) == 0 ) ) {
if ( V_66 -> type != V_68 ) {
F_64 ( V_53 , L_85 ) ;
goto V_41;
}
V_178 = F_6 () ;
if ( ! V_178 ) {
F_64 ( V_53 , L_46 ,
V_134 ) ;
goto V_41;
}
V_66 -> type = V_85 ;
V_66 -> V_86 . type = V_66 -> V_69 . V_69 ;
V_66 -> V_86 . V_17 = V_178 ;
type = F_67 ( V_53 , V_178 , & V_119 , type ) ;
}
* V_106 = V_119 ;
return type ;
V_41:
F_44 ( V_119 ) ;
* V_106 = NULL ;
return V_60 ;
}
static enum V_57
F_89 ( struct V_52 * V_53 V_160 , struct V_7 * V_66 ,
char * * V_106 )
{
enum V_57 type ;
char * V_119 ;
if ( F_53 ( V_58 , & V_119 ) < 0 )
goto V_41;
V_66 -> type = V_87 ;
V_66 -> string . string = V_119 ;
V_66 -> string . V_145 = - 1 ;
if ( F_55 ( V_61 , L_69 ) < 0 )
goto V_161;
type = F_45 ( & V_119 ) ;
* V_106 = V_119 ;
return type ;
V_41:
F_44 ( V_119 ) ;
V_161:
* V_106 = NULL ;
return V_60 ;
}
static enum V_57
F_90 ( struct V_52 * V_53 V_160 , struct V_7 * V_66 ,
char * * V_106 )
{
enum V_57 type ;
char * V_119 ;
if ( F_53 ( V_58 , & V_119 ) < 0 )
goto V_41;
V_66 -> type = V_89 ;
V_66 -> V_90 . V_90 = V_119 ;
V_66 -> V_90 . V_145 = - 1 ;
if ( F_55 ( V_61 , L_69 ) < 0 )
goto V_161;
type = F_45 ( & V_119 ) ;
* V_106 = V_119 ;
return type ;
V_41:
F_44 ( V_119 ) ;
V_161:
* V_106 = NULL ;
return V_60 ;
}
static struct V_179 *
F_91 ( struct V_14 * V_14 , char * V_180 )
{
struct V_179 * V_35 ;
if ( ! V_14 )
return NULL ;
for ( V_35 = V_14 -> V_181 ; V_35 ; V_35 = V_35 -> V_22 ) {
if ( strcmp ( V_35 -> V_72 , V_180 ) == 0 )
break;
}
return V_35 ;
}
static void F_92 ( struct V_14 * V_14 , char * V_180 )
{
struct V_179 * V_35 ;
struct V_179 * * V_22 ;
V_22 = & V_14 -> V_181 ;
while ( ( V_35 = * V_22 ) ) {
if ( strcmp ( V_35 -> V_72 , V_180 ) == 0 ) {
* V_22 = V_35 -> V_22 ;
F_93 ( V_35 ) ;
break;
}
V_22 = & V_35 -> V_22 ;
}
}
static enum V_57
F_94 ( struct V_52 * V_53 , struct V_179 * V_35 ,
struct V_7 * V_66 , char * * V_106 )
{
struct V_7 * * V_182 ;
struct V_7 * V_67 ;
enum V_57 type ;
char * V_119 ;
int V_19 ;
V_66 -> type = V_98 ;
V_66 -> V_35 . V_35 = V_35 ;
* V_106 = NULL ;
V_182 = & ( V_66 -> V_35 . args ) ;
for ( V_19 = 0 ; V_19 < V_35 -> V_183 ; V_19 ++ ) {
V_67 = F_6 () ;
if ( ! V_67 ) {
F_64 ( V_53 , L_46 ,
V_134 ) ;
return V_60 ;
}
type = F_66 ( V_53 , V_67 , & V_119 ) ;
if ( V_19 < ( V_35 -> V_183 - 1 ) ) {
if ( type != V_61 || strcmp ( V_119 , L_82 ) != 0 ) {
F_64 ( V_53 ,
L_86 ,
V_35 -> V_72 , V_35 -> V_183 ,
V_53 -> V_72 , V_19 + 1 ) ;
goto V_184;
}
} else {
if ( type != V_61 || strcmp ( V_119 , L_69 ) != 0 ) {
F_64 ( V_53 ,
L_87 ,
V_35 -> V_72 , V_35 -> V_183 , V_53 -> V_72 ) ;
goto V_184;
}
}
* V_182 = V_67 ;
V_182 = & ( V_67 -> V_22 ) ;
F_44 ( V_119 ) ;
}
type = F_45 ( & V_119 ) ;
* V_106 = V_119 ;
return type ;
V_184:
F_35 ( V_67 ) ;
F_44 ( V_119 ) ;
return V_60 ;
}
static enum V_57
F_95 ( struct V_52 * V_53 , struct V_7 * V_66 ,
char * V_119 , char * * V_106 )
{
struct V_179 * V_35 ;
if ( strcmp ( V_119 , L_88 ) == 0 ) {
F_44 ( V_119 ) ;
V_162 = 1 ;
return F_82 ( V_53 , V_66 , V_106 ) ;
}
if ( strcmp ( V_119 , L_89 ) == 0 ) {
F_44 ( V_119 ) ;
V_164 = 1 ;
return F_83 ( V_53 , V_66 , V_106 ) ;
}
if ( strcmp ( V_119 , L_90 ) == 0 ) {
F_44 ( V_119 ) ;
return F_84 ( V_53 , V_66 , V_106 ) ;
}
if ( strcmp ( V_119 , L_91 ) == 0 ) {
F_44 ( V_119 ) ;
return F_85 ( V_53 , V_66 , V_106 ) ;
}
if ( strcmp ( V_119 , L_92 ) == 0 ) {
F_44 ( V_119 ) ;
return F_89 ( V_53 , V_66 , V_106 ) ;
}
if ( strcmp ( V_119 , L_93 ) == 0 ) {
F_44 ( V_119 ) ;
return F_90 ( V_53 , V_66 , V_106 ) ;
}
if ( strcmp ( V_119 , L_94 ) == 0 ) {
F_44 ( V_119 ) ;
return F_86 ( V_53 , V_66 , V_106 ) ;
}
V_35 = F_91 ( V_53 -> V_14 , V_119 ) ;
if ( V_35 ) {
F_44 ( V_119 ) ;
return F_94 ( V_53 , V_35 , V_66 , V_106 ) ;
}
F_64 ( V_53 , L_95 , V_119 ) ;
F_44 ( V_119 ) ;
return V_60 ;
}
static enum V_57
F_67 ( struct V_52 * V_53 , struct V_7 * V_66 ,
char * * V_106 , enum V_57 type )
{
char * V_119 ;
char * V_69 ;
V_119 = * V_106 ;
switch ( type ) {
case V_58 :
if ( strcmp ( V_119 , L_96 ) == 0 ) {
F_44 ( V_119 ) ;
type = F_74 ( V_53 , V_66 , & V_119 ) ;
break;
}
V_69 = V_119 ;
type = F_48 ( & V_119 ) ;
if ( type == V_61 && strcmp ( V_119 , L_84 ) == 0 ) {
F_44 ( V_119 ) ;
V_119 = NULL ;
type = F_95 ( V_53 , V_66 , V_69 , & V_119 ) ;
break;
}
while ( type == V_58 ) {
char * V_158 ;
V_158 = realloc ( V_69 ,
strlen ( V_69 ) + strlen ( V_119 ) + 2 ) ;
if ( ! V_158 ) {
free ( V_69 ) ;
* V_106 = NULL ;
F_44 ( V_119 ) ;
return V_60 ;
}
V_69 = V_158 ;
strcat ( V_69 , L_36 ) ;
strcat ( V_69 , V_119 ) ;
F_44 ( V_119 ) ;
type = F_48 ( & V_119 ) ;
}
V_66 -> type = V_68 ;
V_66 -> V_69 . V_69 = V_69 ;
break;
case V_103 :
case V_59 :
V_66 -> type = V_68 ;
V_66 -> V_69 . V_69 = V_119 ;
type = F_48 ( & V_119 ) ;
break;
case V_61 :
if ( strcmp ( V_119 , L_84 ) == 0 ) {
F_44 ( V_119 ) ;
type = F_88 ( V_53 , V_66 , & V_119 ) ;
break;
}
case V_105 :
V_66 -> type = V_94 ;
V_66 -> V_95 . V_95 = V_119 ;
V_66 -> V_95 . V_96 = NULL ;
type = F_69 ( V_53 , V_66 , & V_119 ) ;
if ( type == V_60 )
V_66 -> V_95 . V_95 = NULL ;
break;
case V_60 ... V_101 :
default:
F_64 ( V_53 , L_97 , type ) ;
return V_60 ;
}
* V_106 = V_119 ;
return type ;
}
static int F_96 ( struct V_52 * V_53 , struct V_7 * * V_173 )
{
enum V_57 type = V_60 ;
struct V_7 * V_66 ;
char * V_119 ;
int args = 0 ;
do {
if ( type == V_101 ) {
type = F_48 ( & V_119 ) ;
continue;
}
V_66 = F_6 () ;
if ( ! V_66 ) {
F_64 ( V_53 , L_46 ,
V_134 ) ;
return - 1 ;
}
type = F_66 ( V_53 , V_66 , & V_119 ) ;
if ( type == V_60 ) {
F_44 ( V_119 ) ;
F_35 ( V_66 ) ;
return - 1 ;
}
* V_173 = V_66 ;
args ++ ;
if ( type == V_105 ) {
type = F_69 ( V_53 , V_66 , & V_119 ) ;
F_44 ( V_119 ) ;
if ( type == V_60 ) {
* V_173 = NULL ;
F_35 ( V_66 ) ;
return - 1 ;
}
V_173 = & V_66 -> V_22 ;
continue;
}
if ( type == V_61 && strcmp ( V_119 , L_82 ) == 0 ) {
F_44 ( V_119 ) ;
* V_173 = V_66 ;
V_173 = & V_66 -> V_22 ;
continue;
}
break;
} while ( type != V_104 );
if ( type != V_104 && type != V_60 )
F_44 ( V_119 ) ;
return args ;
}
static int F_97 ( struct V_52 * V_53 )
{
enum V_57 type ;
char * V_119 ;
int V_123 ;
if ( F_56 ( V_58 , L_98 ) < 0 )
return - 1 ;
if ( F_55 ( V_58 , L_99 ) < 0 )
return - 1 ;
if ( F_55 ( V_105 , L_19 ) < 0 )
return - 1 ;
if ( F_53 ( V_103 , & V_119 ) < 0 )
goto V_124;
V_115:
V_53 -> V_185 . V_149 = V_119 ;
V_53 -> V_185 . args = NULL ;
type = F_48 ( & V_119 ) ;
if ( type == V_104 )
return 0 ;
if ( type == V_103 ) {
char * V_186 ;
if ( F_42 ( & V_186 , L_100 , V_53 -> V_185 . V_149 , V_119 ) < 0 )
goto V_124;
F_44 ( V_119 ) ;
F_44 ( V_53 -> V_185 . V_149 ) ;
V_53 -> V_185 . V_149 = NULL ;
V_119 = V_186 ;
goto V_115;
}
if ( F_51 ( type , V_119 , V_61 , L_82 ) )
goto V_124;
F_44 ( V_119 ) ;
V_123 = F_96 ( V_53 , & V_53 -> V_185 . args ) ;
if ( V_123 < 0 )
return - 1 ;
return V_123 ;
V_124:
F_44 ( V_119 ) ;
return - 1 ;
}
struct V_125 *
F_98 ( struct V_52 * V_53 , const char * V_72 )
{
struct V_125 * V_149 ;
for ( V_149 = V_53 -> V_149 . V_150 ;
V_149 ; V_149 = V_149 -> V_22 ) {
if ( strcmp ( V_149 -> V_72 , V_72 ) == 0 )
break;
}
return V_149 ;
}
struct V_125 *
F_87 ( struct V_52 * V_53 , const char * V_72 )
{
struct V_125 * V_149 ;
for ( V_149 = V_53 -> V_149 . V_128 ;
V_149 ; V_149 = V_149 -> V_22 ) {
if ( strcmp ( V_149 -> V_72 , V_72 ) == 0 )
break;
}
return V_149 ;
}
struct V_125 *
F_75 ( struct V_52 * V_53 , const char * V_72 )
{
struct V_125 * V_149 ;
V_149 = F_98 ( V_53 , V_72 ) ;
if ( V_149 )
return V_149 ;
return F_87 ( V_53 , V_72 ) ;
}
unsigned long long F_99 ( struct V_14 * V_14 ,
const void * V_187 , int V_2 )
{
switch ( V_2 ) {
case 1 :
return * ( unsigned char * ) V_187 ;
case 2 :
return F_100 ( V_14 , V_187 ) ;
case 4 :
return F_101 ( V_14 , V_187 ) ;
case 8 :
return F_102 ( V_14 , V_187 ) ;
default:
return 0 ;
}
}
int F_103 ( struct V_125 * V_71 , const void * V_188 ,
unsigned long long * V_64 )
{
if ( ! V_71 )
return - 1 ;
switch ( V_71 -> V_2 ) {
case 1 :
case 2 :
case 4 :
case 8 :
* V_64 = F_99 ( V_71 -> V_53 -> V_14 ,
V_188 + V_71 -> V_145 , V_71 -> V_2 ) ;
return 0 ;
default:
return - 1 ;
}
}
static int F_104 ( struct V_14 * V_14 ,
const char * type , int * V_145 , int * V_2 )
{
struct V_52 * V_53 ;
struct V_125 * V_71 ;
if ( ! V_14 -> V_54 ) {
F_50 ( L_101 ) ;
return - 1 ;
}
V_53 = V_14 -> V_54 [ 0 ] ;
V_71 = F_98 ( V_53 , type ) ;
if ( ! V_71 )
return - 1 ;
* V_145 = V_71 -> V_145 ;
* V_2 = V_71 -> V_2 ;
return 0 ;
}
static int F_105 ( struct V_14 * V_14 , void * V_188 ,
int * V_2 , int * V_145 , const char * V_72 )
{
int V_123 ;
if ( ! * V_2 ) {
V_123 = F_104 ( V_14 , V_72 , V_145 , V_2 ) ;
if ( V_123 < 0 )
return V_123 ;
}
return F_99 ( V_14 , V_188 + * V_145 , * V_2 ) ;
}
static int F_106 ( struct V_14 * V_14 , void * V_188 )
{
return F_105 ( V_14 , V_188 ,
& V_14 -> F_62 , & V_14 -> V_189 ,
L_102 ) ;
}
static int F_107 ( struct V_14 * V_14 , void * V_188 )
{
return F_105 ( V_14 , V_188 ,
& V_14 -> V_190 , & V_14 -> V_191 ,
L_103 ) ;
}
static int F_108 ( struct V_14 * V_14 , void * V_188 )
{
return F_105 ( V_14 , V_188 ,
& V_14 -> V_192 , & V_14 -> V_193 ,
L_104 ) ;
}
static int F_109 ( struct V_14 * V_14 , void * V_188 )
{
return F_105 ( V_14 , V_188 ,
& V_14 -> V_194 , & V_14 -> V_195 ,
L_105 ) ;
}
static int F_110 ( struct V_14 * V_14 , void * V_188 )
{
return F_105 ( V_14 , V_188 ,
& V_14 -> V_196 , & V_14 -> V_197 ,
L_106 ) ;
}
static int F_111 ( struct V_14 * V_14 , void * V_188 )
{
return F_105 ( V_14 , V_188 ,
& V_14 -> V_196 , & V_14 -> V_197 ,
L_107 ) ;
}
struct V_52 * F_112 ( struct V_14 * V_14 , int V_56 )
{
struct V_52 * * V_198 ;
struct V_52 V_23 ;
struct V_52 * V_199 = & V_23 ;
if ( V_14 -> V_200 && V_14 -> V_200 -> V_56 == V_56 )
return V_14 -> V_200 ;
V_23 . V_56 = V_56 ;
V_198 = bsearch ( & V_199 , V_14 -> V_54 , V_14 -> V_55 ,
sizeof( * V_14 -> V_54 ) , V_201 ) ;
if ( V_198 ) {
V_14 -> V_200 = * V_198 ;
return * V_198 ;
}
return NULL ;
}
struct V_52 *
F_113 ( struct V_14 * V_14 ,
const char * V_202 , const char * V_72 )
{
struct V_52 * V_53 ;
int V_19 ;
if ( V_14 -> V_200 &&
strcmp ( V_14 -> V_200 -> V_72 , V_72 ) == 0 &&
( ! V_202 || strcmp ( V_14 -> V_200 -> system , V_202 ) == 0 ) )
return V_14 -> V_200 ;
for ( V_19 = 0 ; V_19 < V_14 -> V_55 ; V_19 ++ ) {
V_53 = V_14 -> V_54 [ V_19 ] ;
if ( strcmp ( V_53 -> V_72 , V_72 ) == 0 ) {
if ( ! V_202 )
break;
if ( strcmp ( V_53 -> system , V_202 ) == 0 )
break;
}
}
if ( V_19 == V_14 -> V_55 )
V_53 = NULL ;
V_14 -> V_200 = V_53 ;
return V_53 ;
}
static unsigned long long
F_114 ( void * V_188 , int V_2 , struct V_52 * V_53 , struct V_7 * V_66 )
{
struct V_14 * V_14 = V_53 -> V_14 ;
unsigned long long V_169 = 0 ;
unsigned long long V_96 , V_97 ;
struct V_7 * V_203 = NULL ;
struct V_7 * V_204 ;
unsigned long V_145 ;
unsigned int V_205 ;
switch ( V_66 -> type ) {
case V_99 :
return 0 ;
case V_68 :
return F_115 ( V_66 -> V_69 . V_69 , NULL , 0 ) ;
case V_70 :
if ( ! V_66 -> V_71 . V_71 ) {
V_66 -> V_71 . V_71 = F_75 ( V_53 , V_66 -> V_71 . V_72 ) ;
if ( ! V_66 -> V_71 . V_71 )
goto V_206;
}
V_169 = F_99 ( V_14 , V_188 + V_66 -> V_71 . V_71 -> V_145 ,
V_66 -> V_71 . V_71 -> V_2 ) ;
break;
case V_73 :
case V_76 :
case V_81 :
case V_79 :
break;
case V_85 :
V_169 = F_114 ( V_188 , V_2 , V_53 , V_66 -> V_86 . V_17 ) ;
return F_78 ( V_169 , V_66 , 0 ) ;
case V_87 :
case V_88 :
case V_89 :
return 0 ;
case V_98 : {
struct V_207 V_208 ;
F_116 ( & V_208 ) ;
V_169 = F_117 ( & V_208 , V_188 , V_2 , V_53 , V_66 ) ;
F_118 ( & V_208 ) ;
return V_169 ;
}
case V_94 :
if ( strcmp ( V_66 -> V_95 . V_95 , L_38 ) == 0 ) {
V_97 = F_114 ( V_188 , V_2 , V_53 , V_66 -> V_95 . V_97 ) ;
V_204 = V_66 -> V_95 . V_96 ;
while ( V_204 -> type == V_85 ) {
if ( ! V_203 )
V_203 = V_204 ;
V_204 = V_204 -> V_86 . V_17 ;
}
V_205 = V_14 -> V_148 ;
switch ( V_204 -> type ) {
case V_91 :
V_145 = F_99 ( V_14 ,
V_188 + V_204 -> V_92 . V_71 -> V_145 ,
V_204 -> V_92 . V_71 -> V_2 ) ;
if ( V_204 -> V_92 . V_71 -> V_147 )
V_205 = V_204 -> V_92 . V_71 -> V_147 ;
V_145 &= 0xffff ;
V_145 += V_97 ;
break;
case V_70 :
if ( ! V_204 -> V_71 . V_71 ) {
V_204 -> V_71 . V_71 =
F_75 ( V_53 , V_204 -> V_71 . V_72 ) ;
if ( ! V_204 -> V_71 . V_71 ) {
V_66 = V_204 ;
goto V_206;
}
}
V_205 = V_204 -> V_71 . V_71 -> V_147 ;
V_145 = V_204 -> V_71 . V_71 -> V_145 +
V_97 * V_204 -> V_71 . V_71 -> V_147 ;
break;
default:
goto V_209;
}
V_169 = F_99 ( V_14 ,
V_188 + V_145 , V_205 ) ;
if ( V_203 )
V_169 = F_78 ( V_169 , V_203 , 1 ) ;
break;
} else if ( strcmp ( V_66 -> V_95 . V_95 , L_60 ) == 0 ) {
V_96 = F_114 ( V_188 , V_2 , V_53 , V_66 -> V_95 . V_96 ) ;
V_66 = V_66 -> V_95 . V_97 ;
if ( V_96 )
V_169 = F_114 ( V_188 , V_2 , V_53 , V_66 -> V_95 . V_96 ) ;
else
V_169 = F_114 ( V_188 , V_2 , V_53 , V_66 -> V_95 . V_97 ) ;
break;
}
V_209:
V_96 = F_114 ( V_188 , V_2 , V_53 , V_66 -> V_95 . V_96 ) ;
V_97 = F_114 ( V_188 , V_2 , V_53 , V_66 -> V_95 . V_97 ) ;
switch ( V_66 -> V_95 . V_95 [ 0 ] ) {
case '!' :
switch ( V_66 -> V_95 . V_95 [ 1 ] ) {
case 0 :
V_169 = ! V_97 ;
break;
case '=' :
V_169 = V_96 != V_97 ;
break;
default:
goto V_210;
}
break;
case '~' :
V_169 = ~ V_97 ;
break;
case '|' :
if ( V_66 -> V_95 . V_95 [ 1 ] )
V_169 = V_96 || V_97 ;
else
V_169 = V_96 | V_97 ;
break;
case '&' :
if ( V_66 -> V_95 . V_95 [ 1 ] )
V_169 = V_96 && V_97 ;
else
V_169 = V_96 & V_97 ;
break;
case '<' :
switch ( V_66 -> V_95 . V_95 [ 1 ] ) {
case 0 :
V_169 = V_96 < V_97 ;
break;
case '<' :
V_169 = V_96 << V_97 ;
break;
case '=' :
V_169 = V_96 <= V_97 ;
break;
default:
goto V_210;
}
break;
case '>' :
switch ( V_66 -> V_95 . V_95 [ 1 ] ) {
case 0 :
V_169 = V_96 > V_97 ;
break;
case '>' :
V_169 = V_96 >> V_97 ;
break;
case '=' :
V_169 = V_96 >= V_97 ;
break;
default:
goto V_210;
}
break;
case '=' :
if ( V_66 -> V_95 . V_95 [ 1 ] != '=' )
goto V_210;
V_169 = V_96 == V_97 ;
break;
case '-' :
V_169 = V_96 - V_97 ;
break;
case '+' :
V_169 = V_96 + V_97 ;
break;
case '/' :
V_169 = V_96 / V_97 ;
break;
case '*' :
V_169 = V_96 * V_97 ;
break;
default:
goto V_210;
}
break;
case V_91 :
V_145 = F_99 ( V_14 ,
V_188 + V_66 -> V_92 . V_71 -> V_145 ,
V_66 -> V_92 . V_71 -> V_2 ) ;
V_145 &= 0xffff ;
V_169 = ( unsigned long long ) ( ( unsigned long ) V_188 + V_145 ) ;
break;
default:
return 0 ;
}
return V_169 ;
V_210:
F_64 ( V_53 , L_108 , V_134 , V_66 -> V_95 . V_95 ) ;
return 0 ;
V_206:
F_64 ( V_53 , L_109 ,
V_134 , V_66 -> V_71 . V_72 ) ;
return 0 ;
}
static long long F_119 ( const char * V_211 )
{
int V_19 ;
if ( isdigit ( V_211 [ 0 ] ) )
return F_115 ( V_211 , NULL , 0 ) ;
for ( V_19 = 0 ; V_19 < ( int ) ( sizeof( V_74 ) / sizeof( V_74 [ 0 ] ) ) ; V_19 ++ )
if ( strcmp ( V_74 [ V_19 ] . V_72 , V_211 ) == 0 )
return V_74 [ V_19 ] . V_64 ;
return - 1LL ;
}
static void F_120 ( struct V_207 * V_208 , const char * V_149 ,
int V_212 , const char * V_65 )
{
if ( V_212 >= 0 )
F_121 ( V_208 , V_149 , V_212 , V_65 ) ;
else
F_121 ( V_208 , V_149 , V_65 ) ;
}
static void F_122 ( struct V_14 * V_14 ,
struct V_207 * V_208 , const char * V_149 ,
int V_212 , const void * V_188 , int V_2 )
{
int V_213 = V_2 * 8 ;
int V_214 = ( V_213 + 3 ) / 4 ;
int V_139 = 0 ;
char V_1 [ 3 ] ;
char * V_65 ;
int V_93 ;
int V_19 ;
V_214 += ( V_213 - 1 ) / 32 ;
V_65 = malloc ( V_214 + 1 ) ;
if ( ! V_65 ) {
F_50 ( L_46 , V_134 ) ;
return;
}
V_65 [ V_214 ] = 0 ;
for ( V_19 = V_214 - 2 ; V_19 >= 0 ; V_19 -= 2 ) {
if ( V_14 -> V_215 )
V_93 = V_2 - ( V_139 + 1 ) ;
else
V_93 = V_139 ;
snprintf ( V_1 , 3 , L_110 , * ( ( unsigned char * ) V_188 + V_93 ) ) ;
memcpy ( V_65 + V_19 , V_1 , 2 ) ;
V_139 ++ ;
if ( ! ( V_139 & 3 ) && V_19 > 0 ) {
V_19 -- ;
V_65 [ V_19 ] = ',' ;
}
}
if ( V_212 >= 0 )
F_121 ( V_208 , V_149 , V_212 , V_65 ) ;
else
F_121 ( V_208 , V_149 , V_65 ) ;
free ( V_65 ) ;
}
static void F_123 ( struct V_207 * V_208 , void * V_188 , int V_2 ,
struct V_52 * V_53 , const char * V_149 ,
int V_212 , struct V_7 * V_66 )
{
struct V_14 * V_14 = V_53 -> V_14 ;
struct V_62 * V_211 ;
struct V_125 * V_71 ;
struct V_43 * V_49 ;
long long V_169 , V_216 ;
unsigned long long V_31 ;
char * V_65 ;
unsigned char * V_80 ;
int V_217 ;
int V_19 , V_139 ;
switch ( V_66 -> type ) {
case V_99 :
return;
case V_68 :
F_120 ( V_208 , V_149 , V_212 , V_66 -> V_69 . V_69 ) ;
return;
case V_70 :
V_71 = V_66 -> V_71 . V_71 ;
if ( ! V_71 ) {
V_71 = F_75 ( V_53 , V_66 -> V_71 . V_72 ) ;
if ( ! V_71 ) {
V_65 = V_66 -> V_71 . V_72 ;
goto V_206;
}
V_66 -> V_71 . V_71 = V_71 ;
}
V_139 = V_71 -> V_2 ? : V_2 - V_71 -> V_145 ;
if ( ! ( V_71 -> V_74 & V_126 ) &&
V_71 -> V_2 == V_14 -> V_148 ) {
V_31 = ( V_14 -> V_148 == 8 ) ?
* ( unsigned long long * ) ( V_188 + V_71 -> V_145 ) :
( unsigned long long ) * ( unsigned int * ) ( V_188 + V_71 -> V_145 ) ;
V_49 = F_28 ( V_14 , V_31 ) ;
if ( V_49 )
F_124 ( V_208 , V_49 -> V_49 ) ;
else
F_121 ( V_208 , L_111 , V_31 ) ;
break;
}
V_65 = malloc ( V_139 + 1 ) ;
if ( ! V_65 ) {
F_64 ( V_53 , L_46 ,
V_134 ) ;
return;
}
memcpy ( V_65 , V_188 + V_71 -> V_145 , V_139 ) ;
V_65 [ V_139 ] = 0 ;
F_120 ( V_208 , V_149 , V_212 , V_65 ) ;
free ( V_65 ) ;
break;
case V_73 :
V_169 = F_114 ( V_188 , V_2 , V_53 , V_66 -> V_74 . V_71 ) ;
V_217 = 0 ;
for ( V_211 = V_66 -> V_74 . V_74 ; V_211 ; V_211 = V_211 -> V_22 ) {
V_216 = F_119 ( V_211 -> V_64 ) ;
if ( ! V_169 && V_216 < 0 ) {
F_120 ( V_208 , V_149 , V_212 , V_211 -> V_65 ) ;
break;
}
if ( V_216 > 0 && ( V_169 & V_216 ) == V_216 ) {
if ( V_217 && V_66 -> V_74 . V_75 )
F_124 ( V_208 , V_66 -> V_74 . V_75 ) ;
F_120 ( V_208 , V_149 , V_212 , V_211 -> V_65 ) ;
V_217 = 1 ;
V_169 &= ~ V_216 ;
}
}
break;
case V_76 :
V_169 = F_114 ( V_188 , V_2 , V_53 , V_66 -> V_77 . V_71 ) ;
for ( V_211 = V_66 -> V_77 . V_78 ; V_211 ; V_211 = V_211 -> V_22 ) {
V_216 = F_119 ( V_211 -> V_64 ) ;
if ( V_169 == V_216 ) {
F_120 ( V_208 , V_149 , V_212 , V_211 -> V_65 ) ;
break;
}
}
break;
case V_79 :
if ( V_66 -> V_80 . V_71 -> type == V_91 ) {
unsigned long V_145 ;
V_145 = F_99 ( V_14 ,
V_188 + V_66 -> V_80 . V_71 -> V_92 . V_71 -> V_145 ,
V_66 -> V_80 . V_71 -> V_92 . V_71 -> V_2 ) ;
V_80 = V_188 + ( V_145 & 0xffff ) ;
} else {
V_71 = V_66 -> V_80 . V_71 -> V_71 . V_71 ;
if ( ! V_71 ) {
V_65 = V_66 -> V_80 . V_71 -> V_71 . V_72 ;
V_71 = F_75 ( V_53 , V_65 ) ;
if ( ! V_71 )
goto V_206;
V_66 -> V_80 . V_71 -> V_71 . V_71 = V_71 ;
}
V_80 = V_188 + V_71 -> V_145 ;
}
V_139 = F_114 ( V_188 , V_2 , V_53 , V_66 -> V_80 . V_2 ) ;
for ( V_19 = 0 ; V_19 < V_139 ; V_19 ++ ) {
if ( V_19 )
F_125 ( V_208 , ' ' ) ;
F_121 ( V_208 , L_110 , V_80 [ V_19 ] ) ;
}
break;
case V_81 : {
void * V_218 ;
int V_84 ;
if ( V_66 -> V_82 . V_71 -> type == V_91 ) {
unsigned long V_145 ;
struct V_125 * V_71 =
V_66 -> V_82 . V_71 -> V_92 . V_71 ;
V_145 = F_99 ( V_14 ,
V_188 + V_71 -> V_145 ,
V_71 -> V_2 ) ;
V_218 = V_188 + ( V_145 & 0xffff ) ;
} else {
V_71 = V_66 -> V_82 . V_71 -> V_71 . V_71 ;
if ( ! V_71 ) {
V_65 = V_66 -> V_82 . V_71 -> V_71 . V_72 ;
V_71 = F_75 ( V_53 , V_65 ) ;
if ( ! V_71 )
goto V_206;
V_66 -> V_82 . V_71 -> V_71 . V_71 = V_71 ;
}
V_218 = V_188 + V_71 -> V_145 ;
}
V_139 = F_114 ( V_188 , V_2 , V_53 , V_66 -> V_82 . V_83 ) ;
V_84 = F_114 ( V_188 , V_2 , V_53 ,
V_66 -> V_82 . V_84 ) ;
for ( V_19 = 0 ; V_19 < V_139 ; V_19 ++ ) {
if ( V_19 )
F_125 ( V_208 , ' ' ) ;
if ( V_84 == 1 ) {
F_121 ( V_208 , L_112 , * ( V_219 * ) V_218 ) ;
} else if ( V_84 == 2 ) {
F_121 ( V_208 , L_112 , * ( V_220 * ) V_218 ) ;
} else if ( V_84 == 4 ) {
F_121 ( V_208 , L_112 , * ( V_221 * ) V_218 ) ;
} else if ( V_84 == 8 ) {
F_121 ( V_208 , L_113 V_222 , * ( V_223 * ) V_218 ) ;
} else {
F_121 ( V_208 , L_114 ,
V_84 , * ( V_219 * ) V_218 ) ;
V_84 = 1 ;
}
V_218 += V_84 ;
}
break;
}
case V_85 :
break;
case V_87 : {
int V_224 ;
if ( V_66 -> string . V_145 == - 1 ) {
struct V_125 * V_225 ;
V_225 = F_75 ( V_53 , V_66 -> string . string ) ;
V_66 -> string . V_145 = V_225 -> V_145 ;
}
V_224 = F_101 ( V_14 , V_188 + V_66 -> string . V_145 ) ;
V_224 &= 0xffff ;
F_120 ( V_208 , V_149 , V_212 , ( ( char * ) V_188 ) + V_224 ) ;
break;
}
case V_88 :
F_120 ( V_208 , V_149 , V_212 , V_66 -> string . string ) ;
break;
case V_89 : {
int V_226 ;
int V_227 ;
if ( V_66 -> V_90 . V_145 == - 1 ) {
struct V_125 * V_225 ;
V_225 = F_75 ( V_53 , V_66 -> V_90 . V_90 ) ;
V_66 -> V_90 . V_145 = V_225 -> V_145 ;
}
V_226 = F_101 ( V_14 , V_188 + V_66 -> V_90 . V_145 ) ;
V_227 = V_226 >> 16 ;
V_226 &= 0xffff ;
F_122 ( V_14 , V_208 , V_149 , V_212 ,
V_188 + V_226 , V_227 ) ;
break;
}
case V_94 :
if ( V_66 -> V_95 . V_95 [ 0 ] != '?' )
return;
V_169 = F_114 ( V_188 , V_2 , V_53 , V_66 -> V_95 . V_96 ) ;
if ( V_169 )
F_123 ( V_208 , V_188 , V_2 , V_53 ,
V_149 , V_212 , V_66 -> V_95 . V_97 -> V_95 . V_96 ) ;
else
F_123 ( V_208 , V_188 , V_2 , V_53 ,
V_149 , V_212 , V_66 -> V_95 . V_97 -> V_95 . V_97 ) ;
break;
case V_98 :
F_117 ( V_208 , V_188 , V_2 , V_53 , V_66 ) ;
break;
default:
break;
}
return;
V_206:
F_64 ( V_53 , L_109 ,
V_134 , V_66 -> V_71 . V_72 ) ;
}
static unsigned long long
F_117 ( struct V_207 * V_208 , void * V_188 , int V_2 ,
struct V_52 * V_53 , struct V_7 * V_66 )
{
struct V_179 * V_228 = V_66 -> V_35 . V_35 ;
struct V_229 * V_230 ;
unsigned long long * args ;
unsigned long long V_123 ;
struct V_7 * V_67 ;
struct V_207 V_65 ;
struct V_231 {
struct V_231 * V_22 ;
char * V_65 ;
} * V_232 = NULL , * string ;
int V_19 ;
if ( ! V_228 -> V_183 ) {
V_123 = (* V_228 -> V_35 )( V_208 , NULL ) ;
goto V_114;
}
V_67 = V_66 -> V_35 . args ;
V_230 = V_228 -> V_233 ;
V_123 = V_234 ;
args = malloc ( sizeof( * args ) * V_228 -> V_183 ) ;
if ( ! args )
goto V_114;
for ( V_19 = 0 ; V_19 < V_228 -> V_183 ; V_19 ++ ) {
switch ( V_230 -> type ) {
case V_235 :
case V_236 :
case V_237 :
args [ V_19 ] = F_114 ( V_188 , V_2 , V_53 , V_67 ) ;
break;
case V_238 :
F_116 ( & V_65 ) ;
F_123 ( & V_65 , V_188 , V_2 , V_53 , L_115 , - 1 , V_67 ) ;
F_126 ( & V_65 ) ;
string = malloc ( sizeof( * string ) ) ;
if ( ! string ) {
F_64 ( V_53 , L_116 ,
V_134 , __LINE__ ) ;
goto V_41;
}
string -> V_22 = V_232 ;
string -> V_65 = F_12 ( V_65 . V_239 ) ;
if ( ! string -> V_65 ) {
free ( string ) ;
F_64 ( V_53 , L_116 ,
V_134 , __LINE__ ) ;
goto V_41;
}
args [ V_19 ] = ( V_240 ) string -> V_65 ;
V_232 = string ;
F_118 ( & V_65 ) ;
break;
default:
F_64 ( V_53 , L_117 ) ;
goto V_41;
}
V_67 = V_67 -> V_22 ;
V_230 = V_230 -> V_22 ;
}
V_123 = (* V_228 -> V_35 )( V_208 , args ) ;
V_41:
free ( args ) ;
while ( V_232 ) {
string = V_232 ;
V_232 = string -> V_22 ;
free ( string -> V_65 ) ;
free ( string ) ;
}
V_114:
return V_123 ;
}
static void F_127 ( struct V_7 * args )
{
struct V_7 * V_22 ;
while ( args ) {
V_22 = args -> V_22 ;
F_35 ( args ) ;
args = V_22 ;
}
}
static struct V_7 * F_128 ( char * V_50 , void * V_188 , int V_2 , struct V_52 * V_53 )
{
struct V_14 * V_14 = V_53 -> V_14 ;
struct V_125 * V_71 , * V_241 ;
struct V_7 * args , * V_66 , * * V_22 ;
unsigned long long V_242 , V_169 ;
char * V_187 ;
void * V_243 ;
int V_244 ;
V_71 = V_14 -> V_245 ;
V_241 = V_14 -> V_246 ;
if ( ! V_71 ) {
V_71 = F_87 ( V_53 , L_118 ) ;
if ( ! V_71 ) {
F_64 ( V_53 , L_119 ) ;
return NULL ;
}
V_241 = F_87 ( V_53 , L_120 ) ;
if ( ! V_241 ) {
F_64 ( V_53 , L_121 ) ;
return NULL ;
}
V_14 -> V_245 = V_71 ;
V_14 -> V_246 = V_241 ;
}
V_242 = F_99 ( V_14 , V_188 + V_241 -> V_145 , V_241 -> V_2 ) ;
args = F_6 () ;
if ( ! args ) {
F_64 ( V_53 , L_122 ,
V_134 , __LINE__ ) ;
return NULL ;
}
V_66 = args ;
V_66 -> V_22 = NULL ;
V_22 = & V_66 -> V_22 ;
V_66 -> type = V_68 ;
if ( F_42 ( & V_66 -> V_69 . V_69 , L_80 , V_242 ) < 0 )
goto V_41;
for ( V_187 = V_50 + 5 , V_243 = V_188 + V_71 -> V_145 ;
V_243 < V_188 + V_2 && * V_187 ; V_187 ++ ) {
int V_247 = 0 ;
if ( * V_187 == '%' ) {
V_248:
V_187 ++ ;
switch ( * V_187 ) {
case '%' :
break;
case 'l' :
V_247 ++ ;
goto V_248;
case 'L' :
V_247 = 2 ;
goto V_248;
case '0' ... '9' :
goto V_248;
case '.' :
goto V_248;
case 'z' :
case 'Z' :
V_247 = 1 ;
goto V_248;
case 'p' :
V_247 = 1 ;
case 'd' :
case 'u' :
case 'x' :
case 'i' :
switch ( V_247 ) {
case 0 :
V_244 = 4 ;
break;
case 1 :
V_244 = V_14 -> V_148 ;
break;
case 2 :
V_244 = 8 ;
break;
default:
V_244 = V_247 ;
break;
}
case '*' :
if ( * V_187 == '*' )
V_244 = 4 ;
V_243 = ( void * ) ( ( ( unsigned long ) V_243 + 3 ) &
~ 3 ) ;
V_169 = F_99 ( V_14 , V_243 , V_244 ) ;
V_243 += V_244 ;
V_66 = F_6 () ;
if ( ! V_66 ) {
F_64 ( V_53 , L_122 ,
V_134 , __LINE__ ) ;
goto V_41;
}
V_66 -> V_22 = NULL ;
V_66 -> type = V_68 ;
if ( F_42 ( & V_66 -> V_69 . V_69 , L_80 , V_169 ) < 0 ) {
free ( V_66 ) ;
goto V_41;
}
* V_22 = V_66 ;
V_22 = & V_66 -> V_22 ;
if ( * V_187 == '*' )
goto V_248;
break;
case 's' :
V_66 = F_6 () ;
if ( ! V_66 ) {
F_64 ( V_53 , L_122 ,
V_134 , __LINE__ ) ;
goto V_41;
}
V_66 -> V_22 = NULL ;
V_66 -> type = V_88 ;
V_66 -> string . string = F_12 ( V_243 ) ;
if ( ! V_66 -> string . string )
goto V_41;
V_243 += strlen ( V_243 ) + 1 ;
* V_22 = V_66 ;
V_22 = & V_66 -> V_22 ;
default:
break;
}
}
}
return args ;
V_41:
F_127 ( args ) ;
return NULL ;
}
static char *
F_129 ( void * V_188 , int V_2 V_160 ,
struct V_52 * V_53 )
{
struct V_14 * V_14 = V_53 -> V_14 ;
unsigned long long V_31 ;
struct V_125 * V_71 ;
struct V_43 * V_49 ;
char * V_149 ;
V_71 = V_14 -> V_249 ;
if ( ! V_71 ) {
V_71 = F_87 ( V_53 , L_99 ) ;
if ( ! V_71 ) {
F_64 ( V_53 , L_123 ) ;
return NULL ;
}
V_14 -> V_249 = V_71 ;
}
V_31 = F_99 ( V_14 , V_188 + V_71 -> V_145 , V_71 -> V_2 ) ;
V_49 = F_28 ( V_14 , V_31 ) ;
if ( ! V_49 ) {
if ( F_42 ( & V_149 , L_124 , V_31 ) < 0 )
return NULL ;
return V_149 ;
}
if ( F_42 ( & V_149 , L_125 , L_126 , V_49 -> V_49 ) < 0 )
return NULL ;
return V_149 ;
}
static void F_130 ( struct V_207 * V_208 , int V_250 , void * V_188 , int V_2 ,
struct V_52 * V_53 , struct V_7 * V_66 )
{
unsigned char * V_1 ;
const char * V_50 = L_127 ;
if ( V_66 -> type == V_98 ) {
F_117 ( V_208 , V_188 , V_2 , V_53 , V_66 ) ;
return;
}
if ( V_66 -> type != V_70 ) {
F_121 ( V_208 , L_128 ,
V_66 -> type ) ;
return;
}
if ( V_250 == 'm' )
V_50 = L_129 ;
if ( ! V_66 -> V_71 . V_71 ) {
V_66 -> V_71 . V_71 =
F_75 ( V_53 , V_66 -> V_71 . V_72 ) ;
if ( ! V_66 -> V_71 . V_71 ) {
F_64 ( V_53 , L_109 ,
V_134 , V_66 -> V_71 . V_72 ) ;
return;
}
}
if ( V_66 -> V_71 . V_71 -> V_2 != 6 ) {
F_121 ( V_208 , L_130 ) ;
return;
}
V_1 = V_188 + V_66 -> V_71 . V_71 -> V_145 ;
F_121 ( V_208 , V_50 , V_1 [ 0 ] , V_1 [ 1 ] , V_1 [ 2 ] , V_1 [ 3 ] , V_1 [ 4 ] , V_1 [ 5 ] ) ;
}
static void F_131 ( struct V_207 * V_208 , char V_19 , unsigned char * V_1 )
{
const char * V_50 ;
if ( V_19 == 'i' )
V_50 = L_131 ;
else
V_50 = L_132 ;
F_121 ( V_208 , V_50 , V_1 [ 0 ] , V_1 [ 1 ] , V_1 [ 2 ] , V_1 [ 3 ] ) ;
}
static inline bool F_132 ( const struct V_251 * V_8 )
{
return ( ( unsigned long ) ( V_8 -> V_252 [ 0 ] | V_8 -> V_252 [ 1 ] ) |
( unsigned long ) ( V_8 -> V_252 [ 2 ] ^ F_133 ( 0x0000ffff ) ) ) == 0UL ;
}
static inline bool F_134 ( const struct V_251 * V_31 )
{
return ( V_31 -> V_252 [ 2 ] | F_133 ( 0x02000000 ) ) == F_133 ( 0x02005EFE ) ;
}
static void F_135 ( struct V_207 * V_208 , unsigned char * V_31 )
{
int V_19 , V_253 , V_254 ;
unsigned char V_255 [ 8 ] ;
int V_256 = 1 ;
int V_257 = - 1 ;
V_220 V_258 ;
V_219 V_259 , V_260 ;
bool V_261 = false ;
bool V_262 ;
struct V_251 V_263 ;
memcpy ( & V_263 , V_31 , sizeof( struct V_251 ) ) ;
V_262 = F_132 ( & V_263 ) || F_134 ( & V_263 ) ;
memset ( V_255 , 0 , sizeof( V_255 ) ) ;
if ( V_262 )
V_254 = 6 ;
else
V_254 = 8 ;
for ( V_19 = 0 ; V_19 < V_254 ; V_19 ++ ) {
for ( V_253 = V_19 ; V_253 < V_254 ; V_253 ++ ) {
if ( V_263 . V_264 [ V_253 ] != 0 )
break;
V_255 [ V_19 ] ++ ;
}
}
for ( V_19 = 0 ; V_19 < V_254 ; V_19 ++ ) {
if ( V_255 [ V_19 ] > V_256 ) {
V_256 = V_255 [ V_19 ] ;
V_257 = V_19 ;
}
}
if ( V_256 == 1 )
V_257 = - 1 ;
for ( V_19 = 0 ; V_19 < V_254 ; V_19 ++ ) {
if ( V_19 == V_257 ) {
if ( V_261 || V_19 == 0 )
F_121 ( V_208 , L_19 ) ;
F_121 ( V_208 , L_19 ) ;
V_261 = false ;
V_19 += V_256 - 1 ;
continue;
}
if ( V_261 ) {
F_121 ( V_208 , L_19 ) ;
V_261 = false ;
}
V_258 = F_136 ( V_263 . V_264 [ V_19 ] ) ;
V_259 = V_258 >> 8 ;
V_260 = V_258 & 0xff ;
if ( V_259 )
F_121 ( V_208 , L_133 , V_259 , V_260 ) ;
else
F_121 ( V_208 , L_134 , V_260 ) ;
V_261 = true ;
}
if ( V_262 ) {
if ( V_261 )
F_121 ( V_208 , L_19 ) ;
F_131 ( V_208 , 'I' , & V_263 . V_265 [ 12 ] ) ;
}
return;
}
static void F_137 ( struct V_207 * V_208 , char V_19 , unsigned char * V_1 )
{
int V_253 ;
for ( V_253 = 0 ; V_253 < 16 ; V_253 += 2 ) {
F_121 ( V_208 , L_135 , V_1 [ V_253 ] , V_1 [ V_253 + 1 ] ) ;
if ( V_19 == 'I' && V_253 < 14 )
F_121 ( V_208 , L_19 ) ;
}
}
static int F_138 ( struct V_207 * V_208 , const char * V_187 , char V_19 ,
void * V_188 , int V_2 , struct V_52 * V_53 ,
struct V_7 * V_66 )
{
unsigned char * V_1 ;
if ( V_66 -> type == V_98 ) {
F_117 ( V_208 , V_188 , V_2 , V_53 , V_66 ) ;
return 0 ;
}
if ( V_66 -> type != V_70 ) {
F_121 ( V_208 , L_128 , V_66 -> type ) ;
return 0 ;
}
if ( ! V_66 -> V_71 . V_71 ) {
V_66 -> V_71 . V_71 =
F_75 ( V_53 , V_66 -> V_71 . V_72 ) ;
if ( ! V_66 -> V_71 . V_71 ) {
F_50 ( L_109 ,
V_134 , V_66 -> V_71 . V_72 ) ;
return 0 ;
}
}
V_1 = V_188 + V_66 -> V_71 . V_71 -> V_145 ;
if ( V_66 -> V_71 . V_71 -> V_2 != 4 ) {
F_121 ( V_208 , L_136 ) ;
return 0 ;
}
F_131 ( V_208 , V_19 , V_1 ) ;
return 0 ;
}
static int F_139 ( struct V_207 * V_208 , const char * V_187 , char V_19 ,
void * V_188 , int V_2 , struct V_52 * V_53 ,
struct V_7 * V_66 )
{
char V_266 = 0 ;
unsigned char * V_1 ;
int V_267 = 0 ;
if ( V_19 == 'I' && * V_187 == 'c' ) {
V_266 = 1 ;
V_187 ++ ;
V_267 ++ ;
}
if ( V_66 -> type == V_98 ) {
F_117 ( V_208 , V_188 , V_2 , V_53 , V_66 ) ;
return V_267 ;
}
if ( V_66 -> type != V_70 ) {
F_121 ( V_208 , L_128 , V_66 -> type ) ;
return V_267 ;
}
if ( ! V_66 -> V_71 . V_71 ) {
V_66 -> V_71 . V_71 =
F_75 ( V_53 , V_66 -> V_71 . V_72 ) ;
if ( ! V_66 -> V_71 . V_71 ) {
F_50 ( L_109 ,
V_134 , V_66 -> V_71 . V_72 ) ;
return V_267 ;
}
}
V_1 = V_188 + V_66 -> V_71 . V_71 -> V_145 ;
if ( V_66 -> V_71 . V_71 -> V_2 != 16 ) {
F_121 ( V_208 , L_137 ) ;
return V_267 ;
}
if ( V_266 )
F_135 ( V_208 , V_1 ) ;
else
F_137 ( V_208 , V_19 , V_1 ) ;
return V_267 ;
}
static int F_140 ( struct V_207 * V_208 , const char * V_187 , char V_19 ,
void * V_188 , int V_2 , struct V_52 * V_53 ,
struct V_7 * V_66 )
{
char V_266 = 0 , V_268 = 0 ;
unsigned char * V_1 ;
struct V_269 * V_270 ;
int V_267 = 0 ;
if ( V_19 == 'I' ) {
if ( * V_187 == 'p' ) {
V_268 = 1 ;
V_187 ++ ;
V_267 ++ ;
}
if ( * V_187 == 'c' ) {
V_266 = 1 ;
V_187 ++ ;
V_267 ++ ;
}
}
if ( V_66 -> type == V_98 ) {
F_117 ( V_208 , V_188 , V_2 , V_53 , V_66 ) ;
return V_267 ;
}
if ( V_66 -> type != V_70 ) {
F_121 ( V_208 , L_128 , V_66 -> type ) ;
return V_267 ;
}
if ( ! V_66 -> V_71 . V_71 ) {
V_66 -> V_71 . V_71 =
F_75 ( V_53 , V_66 -> V_71 . V_72 ) ;
if ( ! V_66 -> V_71 . V_71 ) {
F_50 ( L_109 ,
V_134 , V_66 -> V_71 . V_72 ) ;
return V_267 ;
}
}
V_270 = (struct V_269 * ) ( V_188 + V_66 -> V_71 . V_71 -> V_145 ) ;
if ( V_270 -> V_271 == V_272 ) {
struct V_273 * V_274 = (struct V_273 * ) V_270 ;
if ( V_66 -> V_71 . V_71 -> V_2 < sizeof( struct V_273 ) ) {
F_121 ( V_208 , L_136 ) ;
return V_267 ;
}
F_131 ( V_208 , V_19 , ( unsigned char * ) & V_274 -> V_275 ) ;
if ( V_268 )
F_121 ( V_208 , L_138 , F_136 ( V_274 -> V_276 ) ) ;
} else if ( V_270 -> V_271 == V_277 ) {
struct V_278 * V_279 = (struct V_278 * ) V_270 ;
if ( V_66 -> V_71 . V_71 -> V_2 < sizeof( struct V_278 ) ) {
F_121 ( V_208 , L_137 ) ;
return V_267 ;
}
if ( V_268 )
F_121 ( V_208 , L_38 ) ;
V_1 = ( unsigned char * ) & V_279 -> V_280 ;
if ( V_266 )
F_135 ( V_208 , V_1 ) ;
else
F_137 ( V_208 , V_19 , V_1 ) ;
if ( V_268 )
F_121 ( V_208 , L_139 , F_136 ( V_279 -> V_281 ) ) ;
}
return V_267 ;
}
static int F_141 ( struct V_207 * V_208 , const char * V_187 ,
void * V_188 , int V_2 , struct V_52 * V_53 ,
struct V_7 * V_66 )
{
char V_19 = * V_187 ;
char V_282 ;
int V_267 = 0 ;
V_187 ++ ;
V_267 ++ ;
V_282 = * V_187 ;
V_187 ++ ;
V_267 ++ ;
switch ( V_282 ) {
case '4' :
V_267 += F_138 ( V_208 , V_187 , V_19 , V_188 , V_2 , V_53 , V_66 ) ;
break;
case '6' :
V_267 += F_139 ( V_208 , V_187 , V_19 , V_188 , V_2 , V_53 , V_66 ) ;
break;
case 'S' :
V_267 += F_140 ( V_208 , V_187 , V_19 , V_188 , V_2 , V_53 , V_66 ) ;
break;
default:
return 0 ;
}
return V_267 ;
}
static int F_142 ( char * V_51 , unsigned int V_139 )
{
unsigned int V_19 ;
for ( V_19 = 0 ; V_19 < V_139 && V_51 [ V_19 ] ; V_19 ++ )
if ( ! isprint ( V_51 [ V_19 ] ) && ! isspace ( V_51 [ V_19 ] ) )
return 0 ;
return 1 ;
}
static void F_143 ( struct V_207 * V_208 , void * V_188 ,
int V_2 V_160 ,
struct V_52 * V_53 )
{
struct V_125 * V_71 ;
unsigned long long V_169 ;
unsigned int V_145 , V_139 , V_19 ;
V_71 = V_53 -> V_149 . V_128 ;
while ( V_71 ) {
F_121 ( V_208 , L_140 , V_71 -> V_72 ) ;
if ( V_71 -> V_74 & V_126 ) {
V_145 = V_71 -> V_145 ;
V_139 = V_71 -> V_2 ;
if ( V_71 -> V_74 & V_142 ) {
V_169 = F_99 ( V_53 -> V_14 , V_188 + V_145 , V_139 ) ;
V_145 = V_169 ;
V_139 = V_145 >> 16 ;
V_145 &= 0xffff ;
}
if ( V_71 -> V_74 & V_141 &&
F_142 ( V_188 + V_145 , V_139 ) ) {
F_121 ( V_208 , L_115 , ( char * ) V_188 + V_145 ) ;
} else {
F_124 ( V_208 , L_141 ) ;
for ( V_19 = 0 ; V_19 < V_139 ; V_19 ++ ) {
if ( V_19 )
F_124 ( V_208 , L_142 ) ;
F_121 ( V_208 , L_110 ,
* ( ( unsigned char * ) V_188 + V_145 + V_19 ) ) ;
}
F_125 ( V_208 , ']' ) ;
V_71 -> V_74 &= ~ V_141 ;
}
} else {
V_169 = F_99 ( V_53 -> V_14 , V_188 + V_71 -> V_145 ,
V_71 -> V_2 ) ;
if ( V_71 -> V_74 & V_132 ) {
F_121 ( V_208 , L_143 , V_169 ) ;
} else if ( V_71 -> V_74 & V_146 ) {
switch ( V_71 -> V_2 ) {
case 4 :
if ( V_71 -> V_74 & V_143 )
F_121 ( V_208 , L_144 , ( int ) V_169 ) ;
else
F_121 ( V_208 , L_145 , ( int ) V_169 ) ;
break;
case 2 :
F_121 ( V_208 , L_146 , ( short ) V_169 ) ;
break;
case 1 :
F_121 ( V_208 , L_147 , ( char ) V_169 ) ;
break;
default:
F_121 ( V_208 , L_80 , V_169 ) ;
}
} else {
if ( V_71 -> V_74 & V_143 )
F_121 ( V_208 , L_143 , V_169 ) ;
else
F_121 ( V_208 , L_148 , V_169 ) ;
}
}
V_71 = V_71 -> V_22 ;
}
}
static void F_144 ( struct V_207 * V_208 , void * V_188 , int V_2 , struct V_52 * V_53 )
{
struct V_14 * V_14 = V_53 -> V_14 ;
struct V_185 * V_185 = & V_53 -> V_185 ;
struct V_7 * V_66 = V_185 -> args ;
struct V_7 * args = NULL ;
const char * V_187 = V_185 -> V_149 ;
unsigned long long V_169 ;
struct V_28 * V_35 ;
const char * V_283 ;
struct V_207 V_51 ;
char * V_284 = NULL ;
char V_149 [ 32 ] ;
int V_285 ;
int V_286 ;
int V_212 ;
int V_139 ;
int V_247 ;
if ( V_53 -> V_74 & V_157 ) {
F_121 ( V_208 , L_149 ) ;
F_143 ( V_208 , V_188 , V_2 , V_53 ) ;
return;
}
if ( V_53 -> V_74 & V_287 ) {
V_284 = F_129 ( V_188 , V_2 , V_53 ) ;
args = F_128 ( V_284 , V_188 , V_2 , V_53 ) ;
V_66 = args ;
V_187 = V_284 ;
}
for (; * V_187 ; V_187 ++ ) {
V_247 = 0 ;
if ( * V_187 == '\\' ) {
V_187 ++ ;
switch ( * V_187 ) {
case 'n' :
F_125 ( V_208 , '\n' ) ;
break;
case 't' :
F_125 ( V_208 , '\t' ) ;
break;
case 'r' :
F_125 ( V_208 , '\r' ) ;
break;
case '\\' :
F_125 ( V_208 , '\\' ) ;
break;
default:
F_125 ( V_208 , * V_187 ) ;
break;
}
} else if ( * V_187 == '%' ) {
V_283 = V_187 ;
V_285 = 0 ;
V_286 = 0 ;
V_288:
V_187 ++ ;
switch ( * V_187 ) {
case '%' :
F_125 ( V_208 , '%' ) ;
break;
case '#' :
goto V_288;
case 'h' :
V_247 -- ;
goto V_288;
case 'l' :
V_247 ++ ;
goto V_288;
case 'L' :
V_247 = 2 ;
goto V_288;
case '*' :
if ( ! V_66 ) {
F_64 ( V_53 , L_150 ) ;
V_53 -> V_74 |= V_157 ;
goto V_289;
}
V_212 = F_114 ( V_188 , V_2 , V_53 , V_66 ) ;
V_286 = 1 ;
V_66 = V_66 -> V_22 ;
goto V_288;
case '.' :
case 'z' :
case 'Z' :
case '0' ... '9' :
case '-' :
goto V_288;
case 'p' :
if ( V_14 -> V_148 == 4 )
V_247 = 1 ;
else
V_247 = 2 ;
if ( * ( V_187 + 1 ) == 'F' ||
* ( V_187 + 1 ) == 'f' ) {
V_187 ++ ;
V_285 = * V_187 ;
} else if ( * ( V_187 + 1 ) == 'M' || * ( V_187 + 1 ) == 'm' ) {
F_130 ( V_208 , * ( V_187 + 1 ) , V_188 , V_2 , V_53 , V_66 ) ;
V_187 ++ ;
V_66 = V_66 -> V_22 ;
break;
} else if ( * ( V_187 + 1 ) == 'I' || * ( V_187 + 1 ) == 'i' ) {
int V_290 ;
V_290 = F_141 ( V_208 , V_187 + 1 , V_188 , V_2 , V_53 , V_66 ) ;
if ( V_290 > 0 ) {
V_187 += V_290 ;
V_66 = V_66 -> V_22 ;
break;
}
}
case 'd' :
case 'i' :
case 'x' :
case 'X' :
case 'u' :
if ( ! V_66 ) {
F_64 ( V_53 , L_150 ) ;
V_53 -> V_74 |= V_157 ;
goto V_289;
}
V_139 = ( ( unsigned long ) V_187 + 1 ) -
( unsigned long ) V_283 ;
if ( V_139 > 31 ) {
F_64 ( V_53 , L_151 ) ;
V_53 -> V_74 |= V_157 ;
V_139 = 31 ;
}
memcpy ( V_149 , V_283 , V_139 ) ;
V_149 [ V_139 ] = 0 ;
V_169 = F_114 ( V_188 , V_2 , V_53 , V_66 ) ;
V_66 = V_66 -> V_22 ;
if ( V_285 ) {
V_35 = F_21 ( V_14 , V_169 ) ;
if ( V_35 ) {
F_124 ( V_208 , V_35 -> V_35 ) ;
if ( V_285 == 'F' )
F_121 ( V_208 ,
L_152 ,
V_169 - V_35 -> V_31 ) ;
break;
}
}
if ( V_14 -> V_148 == 8 && V_247 &&
sizeof( long ) != 8 ) {
char * V_51 ;
V_247 = 2 ;
V_51 = strchr ( V_149 , 'l' ) ;
if ( V_51 )
memmove ( V_51 + 1 , V_51 , strlen ( V_51 ) + 1 ) ;
else if ( strcmp ( V_149 , L_153 ) == 0 )
strcpy ( V_149 , L_143 ) ;
}
switch ( V_247 ) {
case - 2 :
if ( V_286 )
F_121 ( V_208 , V_149 , V_212 , ( char ) V_169 ) ;
else
F_121 ( V_208 , V_149 , ( char ) V_169 ) ;
break;
case - 1 :
if ( V_286 )
F_121 ( V_208 , V_149 , V_212 , ( short ) V_169 ) ;
else
F_121 ( V_208 , V_149 , ( short ) V_169 ) ;
break;
case 0 :
if ( V_286 )
F_121 ( V_208 , V_149 , V_212 , ( int ) V_169 ) ;
else
F_121 ( V_208 , V_149 , ( int ) V_169 ) ;
break;
case 1 :
if ( V_286 )
F_121 ( V_208 , V_149 , V_212 , ( long ) V_169 ) ;
else
F_121 ( V_208 , V_149 , ( long ) V_169 ) ;
break;
case 2 :
if ( V_286 )
F_121 ( V_208 , V_149 , V_212 ,
( long long ) V_169 ) ;
else
F_121 ( V_208 , V_149 , ( long long ) V_169 ) ;
break;
default:
F_64 ( V_53 , L_154 , V_247 ) ;
V_53 -> V_74 |= V_157 ;
}
break;
case 's' :
if ( ! V_66 ) {
F_64 ( V_53 , L_155 ) ;
V_53 -> V_74 |= V_157 ;
goto V_289;
}
V_139 = ( ( unsigned long ) V_187 + 1 ) -
( unsigned long ) V_283 ;
if ( V_139 > 31 ) {
F_64 ( V_53 , L_151 ) ;
V_53 -> V_74 |= V_157 ;
V_139 = 31 ;
}
memcpy ( V_149 , V_283 , V_139 ) ;
V_149 [ V_139 ] = 0 ;
if ( ! V_286 )
V_212 = - 1 ;
F_116 ( & V_51 ) ;
F_123 ( & V_51 , V_188 , V_2 , V_53 ,
V_149 , V_212 , V_66 ) ;
F_126 ( & V_51 ) ;
F_124 ( V_208 , V_51 . V_239 ) ;
F_118 ( & V_51 ) ;
V_66 = V_66 -> V_22 ;
break;
default:
F_121 ( V_208 , L_156 , * V_187 ) ;
}
} else
F_125 ( V_208 , * V_187 ) ;
}
if ( V_53 -> V_74 & V_157 ) {
V_289:
F_121 ( V_208 , L_149 ) ;
}
if ( args ) {
F_127 ( args ) ;
free ( V_284 ) ;
}
}
void F_145 ( struct V_14 * V_14 ,
struct V_207 * V_208 , struct V_291 * V_292 )
{
static int V_293 = 1 ;
static int V_294 = 1 ;
static int V_295 ;
static int V_296 ;
unsigned int V_297 ;
unsigned int V_298 ;
int V_299 ;
int V_300 ;
int V_301 ;
int V_302 ;
void * V_188 = V_292 -> V_188 ;
V_297 = F_109 ( V_14 , V_188 ) ;
V_298 = F_108 ( V_14 , V_188 ) ;
if ( V_295 )
V_299 = F_110 ( V_14 , V_188 ) ;
else if ( V_293 ) {
V_299 = F_110 ( V_14 , V_188 ) ;
if ( V_299 < 0 )
V_293 = 0 ;
else
V_295 = 1 ;
}
if ( V_296 )
V_300 = F_111 ( V_14 , V_188 ) ;
else if ( V_294 ) {
V_300 = F_111 ( V_14 , V_188 ) ;
if ( V_300 < 0 )
V_294 = 0 ;
else
V_296 = 1 ;
}
V_301 = V_297 & V_303 ;
V_302 = V_297 & V_304 ;
F_121 ( V_208 , L_157 ,
( V_297 & V_305 ) ? 'd' :
( V_297 & V_306 ) ?
'X' : '.' ,
( V_297 & V_307 ) ?
'N' : '.' ,
( V_301 && V_302 ) ? 'H' :
V_301 ? 'h' : V_302 ? 's' : '.' ) ;
if ( V_298 )
F_121 ( V_208 , L_134 , V_298 ) ;
else
F_125 ( V_208 , '.' ) ;
if ( V_296 ) {
if ( V_300 < 0 )
F_125 ( V_208 , '.' ) ;
else
F_121 ( V_208 , L_145 , V_300 ) ;
}
if ( V_295 ) {
if ( V_299 < 0 )
F_125 ( V_208 , '.' ) ;
else
F_121 ( V_208 , L_145 , V_299 ) ;
}
F_126 ( V_208 ) ;
}
int F_146 ( struct V_14 * V_14 , struct V_291 * V_308 )
{
return F_106 ( V_14 , V_308 -> V_188 ) ;
}
struct V_52 * F_147 ( struct V_14 * V_14 , int type )
{
return F_112 ( V_14 , type ) ;
}
int F_148 ( struct V_14 * V_14 , struct V_291 * V_308 )
{
return F_107 ( V_14 , V_308 -> V_188 ) ;
}
const char * F_149 ( struct V_14 * V_14 , int V_13 )
{
const char * V_21 ;
V_21 = F_9 ( V_14 , V_13 ) ;
return V_21 ;
}
static struct V_10 *
F_150 ( struct V_14 * V_14 , const char * V_21 , struct V_10 * V_22 )
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
struct V_10 * F_151 ( struct V_14 * V_14 , const char * V_21 ,
struct V_10 * V_22 )
{
struct V_10 * V_10 ;
if ( ! V_14 -> V_18 )
return F_150 ( V_14 , V_21 , V_22 ) ;
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
int F_152 ( struct V_14 * V_14 , struct V_10 * V_10 )
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
void F_153 ( struct V_207 * V_208 , struct V_52 * V_53 ,
struct V_291 * V_292 )
{
int V_309 = 1 ;
if ( V_53 -> V_14 -> V_310 || ( V_53 -> V_74 & V_311 ) )
F_143 ( V_208 , V_292 -> V_188 , V_292 -> V_2 , V_53 ) ;
else {
if ( V_53 -> V_312 && ! ( V_53 -> V_74 & V_313 ) )
V_309 = V_53 -> V_312 ( V_208 , V_292 , V_53 ,
V_53 -> V_314 ) ;
if ( V_309 )
F_144 ( V_208 , V_292 -> V_188 , V_292 -> V_2 , V_53 ) ;
}
F_126 ( V_208 ) ;
}
static bool F_154 ( char * V_27 , bool V_315 )
{
if ( ! V_315 )
return true ;
if ( ! strcmp ( V_27 , L_158 ) || ! strcmp ( V_27 , L_159 )
|| ! strcmp ( V_27 , L_160 ) || ! strcmp ( V_27 , L_161 ) )
return true ;
return false ;
}
void F_155 ( struct V_14 * V_14 , struct V_207 * V_208 ,
struct V_291 * V_292 , bool V_315 )
{
static const char * V_316 = L_162 ;
struct V_52 * V_53 ;
unsigned long V_317 ;
unsigned long V_318 ;
unsigned long V_319 ;
const char * V_21 ;
void * V_188 = V_292 -> V_188 ;
int type ;
int V_13 ;
int V_139 ;
int V_51 ;
bool V_320 ;
V_320 = F_154 ( V_14 -> V_27 ,
V_315 ) ;
if ( V_320 ) {
V_317 = V_292 -> V_321 / V_322 ;
V_319 = V_292 -> V_321 - V_317 * V_322 ;
}
if ( V_292 -> V_2 < 0 ) {
F_50 ( L_163 , V_292 -> V_2 ) ;
return;
}
type = F_106 ( V_14 , V_188 ) ;
V_53 = F_112 ( V_14 , type ) ;
if ( ! V_53 ) {
F_50 ( L_164 , type ) ;
return;
}
V_13 = F_107 ( V_14 , V_188 ) ;
V_21 = F_9 ( V_14 , V_13 ) ;
if ( V_14 -> V_323 ) {
F_121 ( V_208 , L_165 ,
V_21 , V_13 , V_292 -> V_324 ) ;
F_145 ( V_14 , V_208 , V_292 ) ;
} else
F_121 ( V_208 , L_166 , V_21 , V_13 , V_292 -> V_324 ) ;
if ( V_320 ) {
if ( V_14 -> V_74 & V_325 ) {
V_318 = V_319 ;
V_51 = 9 ;
} else {
V_318 = ( V_319 + 500 ) / V_326 ;
V_51 = 6 ;
}
F_121 ( V_208 , L_167 ,
V_317 , V_51 , V_318 , V_53 -> V_72 ) ;
} else
F_121 ( V_208 , L_168 ,
V_292 -> V_321 , V_53 -> V_72 ) ;
V_139 = strlen ( V_53 -> V_72 ) ;
if ( V_139 < 20 )
F_121 ( V_208 , L_169 , 20 - V_139 , V_316 ) ;
F_153 ( V_208 , V_53 , V_292 ) ;
}
static int V_201 ( const void * V_8 , const void * V_9 )
{
struct V_52 * const * V_327 = V_8 ;
struct V_52 * const * V_328 = V_9 ;
if ( ( * V_327 ) -> V_56 < ( * V_328 ) -> V_56 )
return - 1 ;
if ( ( * V_327 ) -> V_56 > ( * V_328 ) -> V_56 )
return 1 ;
return 0 ;
}
static int F_156 ( const void * V_8 , const void * V_9 )
{
struct V_52 * const * V_327 = V_8 ;
struct V_52 * const * V_328 = V_9 ;
int V_329 ;
V_329 = strcmp ( ( * V_327 ) -> V_72 , ( * V_328 ) -> V_72 ) ;
if ( V_329 )
return V_329 ;
V_329 = strcmp ( ( * V_327 ) -> system , ( * V_328 ) -> system ) ;
if ( V_329 )
return V_329 ;
return V_201 ( V_8 , V_9 ) ;
}
static int F_157 ( const void * V_8 , const void * V_9 )
{
struct V_52 * const * V_327 = V_8 ;
struct V_52 * const * V_328 = V_9 ;
int V_329 ;
V_329 = strcmp ( ( * V_327 ) -> system , ( * V_328 ) -> system ) ;
if ( V_329 )
return V_329 ;
V_329 = strcmp ( ( * V_327 ) -> V_72 , ( * V_328 ) -> V_72 ) ;
if ( V_329 )
return V_329 ;
return V_201 ( V_8 , V_9 ) ;
}
struct V_52 * * F_158 ( struct V_14 * V_14 , enum V_330 V_331 )
{
struct V_52 * * V_54 ;
int (* F_159)( const void * V_8 , const void * V_9 );
V_54 = V_14 -> V_332 ;
if ( V_54 && V_14 -> V_136 == V_331 )
return V_54 ;
if ( ! V_54 ) {
V_54 = malloc ( sizeof( * V_54 ) * ( V_14 -> V_55 + 1 ) ) ;
if ( ! V_54 )
return NULL ;
memcpy ( V_54 , V_14 -> V_54 , sizeof( * V_54 ) * V_14 -> V_55 ) ;
V_54 [ V_14 -> V_55 ] = NULL ;
V_14 -> V_332 = V_54 ;
if ( V_331 == V_333 ) {
V_14 -> V_136 = V_331 ;
return V_54 ;
}
}
switch ( V_331 ) {
case V_333 :
F_159 = V_201 ;
break;
case V_334 :
F_159 = F_156 ;
break;
case V_335 :
F_159 = F_157 ;
break;
default:
return V_54 ;
}
qsort ( V_54 , V_14 -> V_55 , sizeof( * V_54 ) , F_159 ) ;
V_14 -> V_136 = V_331 ;
return V_54 ;
}
static struct V_125 * *
F_160 ( const char * type , const char * V_72 ,
int V_83 , struct V_125 * V_173 )
{
struct V_125 * * V_128 ;
struct V_125 * V_71 ;
int V_19 = 0 ;
V_128 = malloc ( sizeof( * V_128 ) * ( V_83 + 1 ) ) ;
if ( ! V_128 )
return NULL ;
for ( V_71 = V_173 ; V_71 ; V_71 = V_71 -> V_22 ) {
V_128 [ V_19 ++ ] = V_71 ;
if ( V_19 == V_83 + 1 ) {
F_50 ( L_170 ,
V_72 , type ) ;
V_19 -- ;
break;
}
}
if ( V_19 != V_83 )
F_50 ( L_171 ,
V_72 , type ) ;
V_128 [ V_19 ] = NULL ;
return V_128 ;
}
struct V_125 * * F_161 ( struct V_52 * V_53 )
{
return F_160 ( L_172 , V_53 -> V_72 ,
V_53 -> V_149 . V_151 ,
V_53 -> V_149 . V_150 ) ;
}
struct V_125 * * F_162 ( struct V_52 * V_53 )
{
return F_160 ( L_173 , V_53 -> V_72 ,
V_53 -> V_149 . V_152 ,
V_53 -> V_149 . V_128 ) ;
}
static void F_163 ( struct V_207 * V_208 , struct V_62 * V_71 )
{
F_121 ( V_208 , L_174 , V_71 -> V_64 , V_71 -> V_65 ) ;
if ( V_71 -> V_22 ) {
F_124 ( V_208 , L_142 ) ;
F_163 ( V_208 , V_71 -> V_22 ) ;
}
}
static void F_164 ( struct V_7 * args )
{
int V_336 = 1 ;
struct V_207 V_208 ;
switch ( args -> type ) {
case V_99 :
printf ( L_175 ) ;
break;
case V_68 :
printf ( L_115 , args -> V_69 . V_69 ) ;
break;
case V_70 :
printf ( L_176 , args -> V_71 . V_72 ) ;
break;
case V_73 :
printf ( L_177 ) ;
F_164 ( args -> V_74 . V_71 ) ;
printf ( L_178 , args -> V_74 . V_75 ) ;
F_116 ( & V_208 ) ;
F_163 ( & V_208 , args -> V_74 . V_74 ) ;
F_165 ( & V_208 ) ;
F_118 ( & V_208 ) ;
printf ( L_69 ) ;
break;
case V_76 :
printf ( L_179 ) ;
F_164 ( args -> V_77 . V_71 ) ;
printf ( L_142 ) ;
F_116 ( & V_208 ) ;
F_163 ( & V_208 , args -> V_77 . V_78 ) ;
F_165 ( & V_208 ) ;
F_118 ( & V_208 ) ;
printf ( L_69 ) ;
break;
case V_79 :
printf ( L_180 ) ;
F_164 ( args -> V_80 . V_71 ) ;
printf ( L_142 ) ;
F_164 ( args -> V_80 . V_2 ) ;
printf ( L_69 ) ;
break;
case V_81 :
printf ( L_181 ) ;
F_164 ( args -> V_82 . V_71 ) ;
printf ( L_142 ) ;
F_164 ( args -> V_82 . V_83 ) ;
printf ( L_142 ) ;
F_164 ( args -> V_82 . V_84 ) ;
printf ( L_69 ) ;
break;
case V_87 :
case V_88 :
printf ( L_182 , args -> string . string ) ;
break;
case V_89 :
printf ( L_183 , args -> V_90 . V_90 ) ;
break;
case V_85 :
printf ( L_184 , args -> V_86 . type ) ;
F_164 ( args -> V_86 . V_17 ) ;
break;
case V_94 :
if ( strcmp ( args -> V_95 . V_95 , L_19 ) == 0 )
V_336 = 0 ;
if ( V_336 )
printf ( L_84 ) ;
F_164 ( args -> V_95 . V_96 ) ;
printf ( L_185 , args -> V_95 . V_95 ) ;
F_164 ( args -> V_95 . V_97 ) ;
if ( V_336 )
printf ( L_69 ) ;
break;
default:
return;
}
if ( args -> V_22 ) {
printf ( L_6 ) ;
F_164 ( args -> V_22 ) ;
}
}
static void F_166 ( const char * V_71 ,
int * V_145 , int * V_2 , int V_337 )
{
unsigned long long V_116 ;
unsigned long long V_118 ;
char * V_119 ;
int type ;
V_116 = V_5 ;
V_118 = V_4 ;
if ( F_55 ( V_58 , L_32 ) < 0 )
return;
if ( F_55 ( V_105 , L_19 ) < 0 )
return;
if ( F_53 ( V_58 , & V_119 ) < 0 )
goto V_124;
F_44 ( V_119 ) ;
if ( V_337 ) {
if ( F_55 ( V_58 , V_71 ) < 0 )
return;
} else {
if ( F_53 ( V_58 , & V_119 ) < 0 )
goto V_124;
if ( strcmp ( V_119 , V_71 ) != 0 )
goto V_338;
F_44 ( V_119 ) ;
}
if ( F_55 ( V_105 , L_41 ) < 0 )
return;
if ( F_55 ( V_58 , L_42 ) < 0 )
return;
if ( F_55 ( V_105 , L_19 ) < 0 )
return;
if ( F_53 ( V_58 , & V_119 ) < 0 )
goto V_124;
* V_145 = atoi ( V_119 ) ;
F_44 ( V_119 ) ;
if ( F_55 ( V_105 , L_41 ) < 0 )
return;
if ( F_55 ( V_58 , L_43 ) < 0 )
return;
if ( F_55 ( V_105 , L_19 ) < 0 )
return;
if ( F_53 ( V_58 , & V_119 ) < 0 )
goto V_124;
* V_2 = atoi ( V_119 ) ;
F_44 ( V_119 ) ;
if ( F_55 ( V_105 , L_41 ) < 0 )
return;
type = F_45 ( & V_119 ) ;
if ( type != V_101 ) {
if ( type != V_58 )
goto V_124;
if ( strcmp ( V_119 , L_44 ) != 0 )
goto V_124;
F_44 ( V_119 ) ;
if ( F_55 ( V_105 , L_19 ) < 0 )
return;
if ( F_53 ( V_58 , & V_119 ) )
goto V_124;
F_44 ( V_119 ) ;
if ( F_55 ( V_105 , L_41 ) < 0 )
return;
if ( F_53 ( V_101 , & V_119 ) )
goto V_124;
}
V_124:
F_44 ( V_119 ) ;
return;
V_338:
V_5 = V_116 ;
V_4 = V_118 ;
* V_145 = 0 ;
* V_2 = 0 ;
F_44 ( V_119 ) ;
}
int F_167 ( struct V_14 * V_14 , char * V_1 , unsigned long V_2 ,
int V_148 )
{
int V_339 ;
if ( ! V_2 ) {
V_14 -> V_340 = sizeof( long long ) ;
V_14 -> V_341 = V_148 ;
V_14 -> V_342 = sizeof( long long ) + V_148 ;
V_14 -> V_343 = 1 ;
return - 1 ;
}
F_1 ( V_1 , V_2 ) ;
F_166 ( L_186 , & V_14 -> V_344 ,
& V_14 -> V_340 , 1 ) ;
F_166 ( L_187 , & V_14 -> V_345 ,
& V_14 -> V_341 , 1 ) ;
F_166 ( L_188 , & V_14 -> V_346 ,
& V_339 , 0 ) ;
F_166 ( L_189 , & V_14 -> V_342 ,
& V_14 -> V_347 , 1 ) ;
return 0 ;
}
static int F_168 ( struct V_52 * V_53 ,
int V_56 , const char * V_348 ,
const char * V_349 )
{
if ( V_56 >= 0 && V_56 != V_53 -> V_56 )
return 0 ;
if ( V_349 && ( strcmp ( V_349 , V_53 -> V_72 ) != 0 ) )
return 0 ;
if ( V_348 && ( strcmp ( V_348 , V_53 -> system ) != 0 ) )
return 0 ;
return 1 ;
}
static void F_169 ( struct V_350 * V_351 )
{
free ( ( void * ) V_351 -> V_348 ) ;
free ( ( void * ) V_351 -> V_349 ) ;
free ( V_351 ) ;
}
static int F_170 ( struct V_14 * V_14 , struct V_52 * V_53 )
{
struct V_350 * V_351 , * * V_22 ;
for ( V_22 = & V_14 -> V_352 ; * V_22 ;
V_22 = & ( * V_22 ) -> V_22 ) {
V_351 = * V_22 ;
if ( F_168 ( V_53 , V_351 -> V_56 ,
V_351 -> V_348 ,
V_351 -> V_349 ) )
break;
}
if ( ! ( * V_22 ) )
return 0 ;
F_171 ( L_190 ,
V_53 -> V_56 , V_53 -> system , V_53 -> V_72 ) ;
V_53 -> V_312 = V_351 -> V_35 ;
V_53 -> V_314 = V_351 -> V_314 ;
* V_22 = V_351 -> V_22 ;
F_169 ( V_351 ) ;
return 1 ;
}
enum V_353 F_172 ( struct V_52 * * V_354 ,
struct V_14 * V_14 , const char * V_1 ,
unsigned long V_2 , const char * V_202 )
{
struct V_52 * V_53 ;
int V_123 ;
F_1 ( V_1 , V_2 ) ;
* V_354 = V_53 = F_31 () ;
if ( ! V_53 )
return V_355 ;
V_53 -> V_72 = F_57 () ;
if ( ! V_53 -> V_72 ) {
V_123 = V_355 ;
goto V_356;
}
if ( strcmp ( V_202 , L_191 ) == 0 ) {
V_53 -> V_74 |= V_131 ;
if ( strcmp ( V_53 -> V_72 , L_192 ) == 0 )
V_53 -> V_74 |= V_287 ;
}
V_53 -> V_56 = F_58 () ;
if ( V_53 -> V_56 < 0 ) {
V_123 = V_357 ;
goto V_356;
}
V_53 -> system = F_12 ( V_202 ) ;
if ( ! V_53 -> system ) {
V_123 = V_355 ;
goto V_356;
}
V_53 -> V_14 = V_14 ;
V_123 = F_65 ( V_53 ) ;
if ( V_123 < 0 ) {
V_123 = V_358 ;
goto V_359;
}
if ( V_14 && F_170 ( V_14 , V_53 ) )
V_360 = 0 ;
V_123 = F_97 ( V_53 ) ;
V_360 = 1 ;
if ( V_123 < 0 ) {
V_123 = V_361 ;
goto V_359;
}
if ( ! V_123 && ( V_53 -> V_74 & V_131 ) ) {
struct V_125 * V_71 ;
struct V_7 * V_66 , * * V_173 ;
V_173 = & V_53 -> V_185 . args ;
for ( V_71 = V_53 -> V_149 . V_128 ; V_71 ; V_71 = V_71 -> V_22 ) {
V_66 = F_6 () ;
if ( ! V_66 ) {
V_53 -> V_74 |= V_157 ;
return V_362 ;
}
V_66 -> type = V_70 ;
V_66 -> V_71 . V_72 = F_12 ( V_71 -> V_72 ) ;
if ( ! V_66 -> V_71 . V_72 ) {
V_53 -> V_74 |= V_157 ;
F_35 ( V_66 ) ;
return V_362 ;
}
V_66 -> V_71 . V_71 = V_71 ;
* V_173 = V_66 ;
V_173 = & V_66 -> V_22 ;
}
return 0 ;
}
return 0 ;
V_359:
V_53 -> V_74 |= V_157 ;
return V_123 ;
V_356:
free ( V_53 -> system ) ;
free ( V_53 -> V_72 ) ;
free ( V_53 ) ;
* V_354 = NULL ;
return V_123 ;
}
static enum V_353
F_173 ( struct V_14 * V_14 ,
struct V_52 * * V_354 ,
const char * V_1 , unsigned long V_2 ,
const char * V_202 )
{
int V_123 = F_172 ( V_354 , V_14 , V_1 , V_2 , V_202 ) ;
struct V_52 * V_53 = * V_354 ;
if ( V_53 == NULL )
return V_123 ;
if ( V_14 && F_32 ( V_14 , V_53 ) ) {
V_123 = V_355 ;
goto V_363;
}
#define F_174 0
if ( F_174 && V_53 -> V_185 . args )
F_164 ( V_53 -> V_185 . args ) ;
return 0 ;
V_363:
F_175 ( V_53 ) ;
return V_123 ;
}
enum V_353 F_176 ( struct V_14 * V_14 ,
struct V_52 * * V_354 ,
const char * V_1 ,
unsigned long V_2 , const char * V_202 )
{
return F_173 ( V_14 , V_354 , V_1 , V_2 , V_202 ) ;
}
enum V_353 F_177 ( struct V_14 * V_14 , const char * V_1 ,
unsigned long V_2 , const char * V_202 )
{
struct V_52 * V_53 = NULL ;
return F_173 ( V_14 , & V_53 , V_1 , V_2 , V_202 ) ;
}
int F_178 ( struct V_14 * V_14 V_160 ,
enum V_353 V_364 , char * V_1 , T_2 V_365 )
{
int V_366 ;
const char * V_367 ;
if ( V_364 >= 0 ) {
V_367 = F_179 ( V_364 , V_1 , V_365 ) ;
if ( V_367 != V_1 ) {
T_2 V_139 = strlen ( V_367 ) ;
memcpy ( V_1 , V_367 , F_180 ( V_365 - 1 , V_139 ) ) ;
* ( V_1 + F_180 ( V_365 - 1 , V_139 ) ) = '\0' ;
}
return 0 ;
}
if ( V_364 <= V_368 ||
V_364 >= V_369 )
return - 1 ;
V_366 = V_364 - V_368 - 1 ;
V_367 = V_370 [ V_366 ] ;
snprintf ( V_1 , V_365 , L_115 , V_367 ) ;
return 0 ;
}
int F_181 ( struct V_207 * V_208 , struct V_125 * V_71 ,
const char * V_72 , struct V_291 * V_292 ,
unsigned long long * V_169 , int V_184 )
{
if ( ! V_71 ) {
if ( V_184 )
F_121 ( V_208 , L_193 , V_72 ) ;
return - 1 ;
}
if ( F_103 ( V_71 , V_292 -> V_188 , V_169 ) ) {
if ( V_184 )
F_121 ( V_208 , L_194 , V_72 ) ;
return - 1 ;
}
return 0 ;
}
void * F_182 ( struct V_207 * V_208 , struct V_52 * V_53 ,
const char * V_72 , struct V_291 * V_292 ,
int * V_139 , int V_184 )
{
struct V_125 * V_71 ;
void * V_188 = V_292 -> V_188 ;
unsigned V_145 ;
int V_371 ;
if ( ! V_53 )
return NULL ;
V_71 = F_87 ( V_53 , V_72 ) ;
if ( ! V_71 ) {
if ( V_184 )
F_121 ( V_208 , L_193 , V_72 ) ;
return NULL ;
}
if ( ! V_139 )
V_139 = & V_371 ;
V_145 = V_71 -> V_145 ;
if ( V_71 -> V_74 & V_142 ) {
V_145 = F_99 ( V_53 -> V_14 ,
V_188 + V_145 , V_71 -> V_2 ) ;
* V_139 = V_145 >> 16 ;
V_145 &= 0xffff ;
} else
* V_139 = V_71 -> V_2 ;
return V_188 + V_145 ;
}
int F_183 ( struct V_207 * V_208 , struct V_52 * V_53 ,
const char * V_72 , struct V_291 * V_292 ,
unsigned long long * V_169 , int V_184 )
{
struct V_125 * V_71 ;
if ( ! V_53 )
return - 1 ;
V_71 = F_87 ( V_53 , V_72 ) ;
return F_181 ( V_208 , V_71 , V_72 , V_292 , V_169 , V_184 ) ;
}
int F_184 ( struct V_207 * V_208 , struct V_52 * V_53 ,
const char * V_72 , struct V_291 * V_292 ,
unsigned long long * V_169 , int V_184 )
{
struct V_125 * V_71 ;
if ( ! V_53 )
return - 1 ;
V_71 = F_98 ( V_53 , V_72 ) ;
return F_181 ( V_208 , V_71 , V_72 , V_292 , V_169 , V_184 ) ;
}
int F_185 ( struct V_207 * V_208 , struct V_52 * V_53 ,
const char * V_72 , struct V_291 * V_292 ,
unsigned long long * V_169 , int V_184 )
{
struct V_125 * V_71 ;
if ( ! V_53 )
return - 1 ;
V_71 = F_75 ( V_53 , V_72 ) ;
return F_181 ( V_208 , V_71 , V_72 , V_292 , V_169 , V_184 ) ;
}
int F_186 ( struct V_207 * V_208 , const char * V_50 ,
struct V_52 * V_53 , const char * V_72 ,
struct V_291 * V_292 , int V_184 )
{
struct V_125 * V_71 = F_87 ( V_53 , V_72 ) ;
unsigned long long V_169 ;
if ( ! V_71 )
goto V_372;
if ( F_103 ( V_71 , V_292 -> V_188 , & V_169 ) )
goto V_372;
return F_121 ( V_208 , V_50 , V_169 ) ;
V_372:
if ( V_184 )
F_121 ( V_208 , L_195 , V_72 ) ;
return - 1 ;
}
int F_187 ( struct V_207 * V_208 , const char * V_50 ,
struct V_52 * V_53 , const char * V_72 ,
struct V_291 * V_292 , int V_184 )
{
struct V_125 * V_71 = F_87 ( V_53 , V_72 ) ;
struct V_14 * V_14 = V_53 -> V_14 ;
unsigned long long V_169 ;
struct V_28 * V_35 ;
char V_159 [ 128 ] ;
if ( ! V_71 )
goto V_372;
if ( F_103 ( V_71 , V_292 -> V_188 , & V_169 ) )
goto V_372;
V_35 = F_21 ( V_14 , V_169 ) ;
if ( V_35 )
snprintf ( V_159 , 128 , L_196 , V_35 -> V_35 , V_35 -> V_31 - V_169 ) ;
else
sprintf ( V_159 , L_197 , V_169 ) ;
return F_121 ( V_208 , V_50 , V_159 ) ;
V_372:
if ( V_184 )
F_121 ( V_208 , L_195 , V_72 ) ;
return - 1 ;
}
static void F_93 ( struct V_179 * V_35 )
{
struct V_229 * V_233 ;
free ( V_35 -> V_72 ) ;
while ( V_35 -> V_233 ) {
V_233 = V_35 -> V_233 ;
V_35 -> V_233 = V_233 -> V_22 ;
free ( V_233 ) ;
}
free ( V_35 ) ;
}
int F_188 ( struct V_14 * V_14 ,
T_3 V_35 ,
enum V_373 V_374 ,
char * V_72 , ... )
{
struct V_179 * V_228 ;
struct V_229 * * V_375 ;
struct V_229 * V_230 ;
enum V_373 type ;
T_4 V_376 ;
int V_123 ;
V_228 = F_91 ( V_14 , V_72 ) ;
if ( V_228 ) {
F_171 ( L_198 , V_72 ) ;
F_92 ( V_14 , V_72 ) ;
}
V_228 = calloc ( 1 , sizeof( * V_228 ) ) ;
if ( ! V_228 ) {
F_50 ( L_199 ) ;
return V_355 ;
}
V_228 -> V_374 = V_374 ;
V_228 -> V_72 = F_12 ( V_72 ) ;
V_228 -> V_35 = V_35 ;
if ( ! V_228 -> V_72 ) {
F_50 ( L_200 ) ;
free ( V_228 ) ;
return V_355 ;
}
V_375 = & ( V_228 -> V_233 ) ;
va_start ( V_376 , V_72 ) ;
for (; ; ) {
type = va_arg ( V_376 , enum V_373 ) ;
if ( type == V_377 )
break;
if ( type >= V_378 ) {
F_50 ( L_201 , type ) ;
V_123 = V_379 ;
goto V_41;
}
V_230 = malloc ( sizeof( * V_230 ) ) ;
if ( ! V_230 ) {
F_50 ( L_202 ) ;
V_123 = V_355 ;
goto V_41;
}
V_230 -> type = type ;
V_230 -> V_22 = NULL ;
* V_375 = V_230 ;
V_375 = & ( V_230 -> V_22 ) ;
V_228 -> V_183 ++ ;
}
va_end ( V_376 ) ;
V_228 -> V_22 = V_14 -> V_181 ;
V_14 -> V_181 = V_228 ;
return 0 ;
V_41:
va_end ( V_376 ) ;
F_93 ( V_228 ) ;
return V_123 ;
}
int F_189 ( struct V_14 * V_14 ,
T_3 V_35 , char * V_72 )
{
struct V_179 * V_228 ;
V_228 = F_91 ( V_14 , V_72 ) ;
if ( V_228 && V_228 -> V_35 == V_35 ) {
F_92 ( V_14 , V_72 ) ;
return 0 ;
}
return - 1 ;
}
static struct V_52 * F_190 ( struct V_14 * V_14 , int V_56 ,
const char * V_348 ,
const char * V_349 )
{
struct V_52 * V_53 ;
if ( V_56 >= 0 ) {
V_53 = F_112 ( V_14 , V_56 ) ;
if ( ! V_53 )
return NULL ;
if ( V_349 && ( strcmp ( V_349 , V_53 -> V_72 ) != 0 ) )
return NULL ;
if ( V_348 && ( strcmp ( V_348 , V_53 -> system ) != 0 ) )
return NULL ;
} else {
V_53 = F_113 ( V_14 , V_348 , V_349 ) ;
if ( ! V_53 )
return NULL ;
}
return V_53 ;
}
int F_191 ( struct V_14 * V_14 , int V_56 ,
const char * V_348 , const char * V_349 ,
T_5 V_35 , void * V_314 )
{
struct V_52 * V_53 ;
struct V_350 * V_351 ;
V_53 = F_190 ( V_14 , V_56 , V_348 , V_349 ) ;
if ( V_53 == NULL )
goto V_380;
F_171 ( L_190 ,
V_53 -> V_56 , V_53 -> system , V_53 -> V_72 ) ;
V_53 -> V_312 = V_35 ;
V_53 -> V_314 = V_314 ;
return 0 ;
V_380:
V_351 = calloc ( 1 , sizeof( * V_351 ) ) ;
if ( ! V_351 ) {
F_50 ( L_203 ) ;
return V_355 ;
}
V_351 -> V_56 = V_56 ;
if ( V_349 )
V_351 -> V_349 = F_12 ( V_349 ) ;
if ( V_348 )
V_351 -> V_348 = F_12 ( V_348 ) ;
if ( ( V_349 && ! V_351 -> V_349 ) ||
( V_348 && ! V_351 -> V_348 ) ) {
F_50 ( L_204 ) ;
free ( ( void * ) V_351 -> V_349 ) ;
free ( ( void * ) V_351 -> V_348 ) ;
free ( V_351 ) ;
return V_355 ;
}
V_351 -> V_35 = V_35 ;
V_351 -> V_22 = V_14 -> V_352 ;
V_14 -> V_352 = V_351 ;
V_351 -> V_314 = V_314 ;
return - 1 ;
}
static int F_192 ( struct V_350 * V_312 , int V_56 ,
const char * V_348 , const char * V_349 ,
T_5 V_35 , void * V_314 )
{
if ( V_56 >= 0 && V_56 != V_312 -> V_56 )
return 0 ;
if ( V_349 && ( strcmp ( V_349 , V_312 -> V_349 ) != 0 ) )
return 0 ;
if ( V_348 && ( strcmp ( V_348 , V_312 -> V_348 ) != 0 ) )
return 0 ;
if ( V_35 != V_312 -> V_35 || V_314 != V_312 -> V_314 )
return 0 ;
return 1 ;
}
int F_193 ( struct V_14 * V_14 , int V_56 ,
const char * V_348 , const char * V_349 ,
T_5 V_35 , void * V_314 )
{
struct V_52 * V_53 ;
struct V_350 * V_351 ;
struct V_350 * * V_22 ;
V_53 = F_190 ( V_14 , V_56 , V_348 , V_349 ) ;
if ( V_53 == NULL )
goto V_380;
if ( V_53 -> V_312 == V_35 && V_53 -> V_314 == V_314 ) {
F_171 ( L_205 ,
V_53 -> V_56 , V_53 -> system , V_53 -> V_72 ) ;
V_53 -> V_312 = NULL ;
V_53 -> V_314 = NULL ;
return 0 ;
}
V_380:
for ( V_22 = & V_14 -> V_352 ; * V_22 ; V_22 = & ( * V_22 ) -> V_22 ) {
V_351 = * V_22 ;
if ( F_192 ( V_351 , V_56 , V_348 , V_349 ,
V_35 , V_314 ) )
break;
}
if ( ! ( * V_22 ) )
return - 1 ;
* V_22 = V_351 -> V_22 ;
F_169 ( V_351 ) ;
return 0 ;
}
struct V_14 * F_194 ( void )
{
struct V_14 * V_14 = calloc ( 1 , sizeof( * V_14 ) ) ;
if ( V_14 )
V_14 -> V_381 = 1 ;
return V_14 ;
}
void F_195 ( struct V_14 * V_14 )
{
V_14 -> V_381 ++ ;
}
void F_196 ( struct V_125 * V_71 )
{
free ( V_71 -> type ) ;
if ( V_71 -> V_135 != V_71 -> V_72 )
free ( V_71 -> V_135 ) ;
free ( V_71 -> V_72 ) ;
free ( V_71 ) ;
}
static void F_197 ( struct V_125 * V_71 )
{
struct V_125 * V_22 ;
while ( V_71 ) {
V_22 = V_71 -> V_22 ;
F_196 ( V_71 ) ;
V_71 = V_22 ;
}
}
static void F_198 ( struct V_149 * V_149 )
{
F_197 ( V_149 -> V_150 ) ;
F_197 ( V_149 -> V_128 ) ;
}
void F_175 ( struct V_52 * V_53 )
{
free ( V_53 -> V_72 ) ;
free ( V_53 -> system ) ;
F_198 ( & V_53 -> V_149 ) ;
free ( V_53 -> V_185 . V_149 ) ;
F_127 ( V_53 -> V_185 . args ) ;
free ( V_53 ) ;
}
void F_199 ( struct V_14 * V_14 )
{
struct V_15 * V_16 , * V_382 ;
struct V_32 * V_33 , * V_383 ;
struct V_46 * V_47 , * V_384 ;
struct V_179 * V_385 ;
struct V_350 * V_351 ;
int V_19 ;
if ( ! V_14 )
return;
V_16 = V_14 -> V_16 ;
V_33 = V_14 -> V_33 ;
V_47 = V_14 -> V_47 ;
V_14 -> V_381 -- ;
if ( V_14 -> V_381 )
return;
if ( V_14 -> V_18 ) {
for ( V_19 = 0 ; V_19 < V_14 -> V_20 ; V_19 ++ )
free ( V_14 -> V_18 [ V_19 ] . V_21 ) ;
free ( V_14 -> V_18 ) ;
}
while ( V_16 ) {
V_382 = V_16 -> V_22 ;
free ( V_16 -> V_21 ) ;
free ( V_16 ) ;
V_16 = V_382 ;
}
if ( V_14 -> V_28 ) {
for ( V_19 = 0 ; V_19 < ( int ) V_14 -> V_34 ; V_19 ++ ) {
free ( V_14 -> V_28 [ V_19 ] . V_35 ) ;
free ( V_14 -> V_28 [ V_19 ] . V_36 ) ;
}
free ( V_14 -> V_28 ) ;
}
while ( V_33 ) {
V_383 = V_33 -> V_22 ;
free ( V_33 -> V_35 ) ;
free ( V_33 -> V_36 ) ;
free ( V_33 ) ;
V_33 = V_383 ;
}
while ( V_14 -> V_181 ) {
V_385 = V_14 -> V_181 ;
V_14 -> V_181 = V_385 -> V_22 ;
F_93 ( V_385 ) ;
}
if ( V_14 -> V_43 ) {
for ( V_19 = 0 ; V_19 < ( int ) V_14 -> V_48 ; V_19 ++ )
free ( V_14 -> V_43 [ V_19 ] . V_49 ) ;
free ( V_14 -> V_43 ) ;
}
while ( V_47 ) {
V_384 = V_47 -> V_22 ;
free ( V_47 -> V_49 ) ;
free ( V_47 ) ;
V_47 = V_384 ;
}
for ( V_19 = 0 ; V_19 < V_14 -> V_55 ; V_19 ++ )
F_175 ( V_14 -> V_54 [ V_19 ] ) ;
while ( V_14 -> V_352 ) {
V_351 = V_14 -> V_352 ;
V_14 -> V_352 = V_351 -> V_22 ;
F_169 ( V_351 ) ;
}
free ( V_14 -> V_27 ) ;
free ( V_14 -> V_54 ) ;
free ( V_14 -> V_332 ) ;
free ( V_14 -> V_38 ) ;
free ( V_14 ) ;
}
void F_200 ( struct V_14 * V_14 )
{
F_199 ( V_14 ) ;
}
