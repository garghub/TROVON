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
case V_80 :
F_35 ( V_66 -> V_81 . V_71 ) ;
F_35 ( V_66 -> V_81 . V_2 ) ;
break;
case V_82 :
F_35 ( V_66 -> V_83 . V_71 ) ;
F_35 ( V_66 -> V_83 . V_84 ) ;
F_35 ( V_66 -> V_83 . V_85 ) ;
break;
case V_86 :
free ( V_66 -> V_87 . type ) ;
F_35 ( V_66 -> V_87 . V_17 ) ;
break;
case V_88 :
case V_89 :
free ( V_66 -> string . string ) ;
break;
case V_90 :
free ( V_66 -> V_91 . V_91 ) ;
break;
case V_92 :
case V_93 :
free ( V_66 -> V_94 . V_95 ) ;
break;
case V_96 :
free ( V_66 -> V_97 . V_97 ) ;
F_35 ( V_66 -> V_97 . V_98 ) ;
F_35 ( V_66 -> V_97 . V_99 ) ;
break;
case V_100 :
while ( V_66 -> V_35 . args ) {
V_67 = V_66 -> V_35 . args ;
V_66 -> V_35 . args = V_67 -> V_22 ;
F_35 ( V_67 ) ;
}
break;
case V_101 :
default:
break;
}
free ( V_66 ) ;
}
static enum V_57 F_36 ( int V_102 )
{
if ( V_102 == '\n' )
return V_103 ;
if ( isspace ( V_102 ) )
return V_104 ;
if ( isalnum ( V_102 ) || V_102 == '_' )
return V_58 ;
if ( V_102 == '\'' )
return V_59 ;
if ( V_102 == '"' )
return V_105 ;
if ( ! isprint ( V_102 ) )
return V_106 ;
if ( V_102 == '(' || V_102 == ')' || V_102 == ',' )
return V_61 ;
return V_107 ;
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
static int F_40 ( char * * V_108 , char * V_1 , int V_2 )
{
char * V_109 = realloc ( * V_108 , V_2 ) ;
if ( ! V_109 ) {
free ( * V_108 ) ;
* V_108 = NULL ;
return - 1 ;
}
if ( ! * V_108 )
strcpy ( V_109 , V_1 ) ;
else
strcat ( V_109 , V_1 ) ;
* V_108 = V_109 ;
return 0 ;
}
static enum V_57 F_41 ( char * * V_108 )
{
char V_1 [ V_110 ] ;
int V_102 , V_111 , V_112 , V_113 ;
int V_19 = 0 ;
int V_114 = 0 ;
enum V_57 type ;
* V_108 = NULL ;
V_102 = F_37 () ;
if ( V_102 < 0 )
return V_106 ;
type = F_36 ( V_102 ) ;
if ( type == V_106 )
return type ;
V_1 [ V_19 ++ ] = V_102 ;
switch ( type ) {
case V_103 :
case V_61 :
if ( F_42 ( V_108 , L_9 , V_102 ) < 0 )
return V_60 ;
return type ;
case V_107 :
switch ( V_102 ) {
case '-' :
V_113 = F_38 () ;
if ( V_113 == '>' ) {
V_1 [ V_19 ++ ] = F_37 () ;
break;
}
case '+' :
case '|' :
case '&' :
case '>' :
case '<' :
V_111 = V_102 ;
V_102 = F_38 () ;
if ( V_102 != V_111 )
goto V_115;
V_1 [ V_19 ++ ] = F_37 () ;
switch ( V_111 ) {
case '>' :
case '<' :
goto V_115;
default:
break;
}
break;
case '!' :
case '=' :
goto V_115;
default:
break;
}
V_1 [ V_19 ] = 0 ;
* V_108 = F_12 ( V_1 ) ;
return type ;
V_115:
V_102 = F_38 () ;
if ( V_102 == '=' )
V_1 [ V_19 ++ ] = F_37 () ;
goto V_116;
case V_105 :
case V_59 :
V_19 -- ;
V_112 = V_102 ;
V_111 = 0 ;
V_117:
do {
if ( V_19 == ( V_110 - 1 ) ) {
V_1 [ V_19 ] = 0 ;
V_114 += V_110 ;
if ( F_40 ( V_108 , V_1 , V_114 ) < 0 )
return V_106 ;
V_19 = 0 ;
}
V_111 = V_102 ;
V_102 = F_37 () ;
V_1 [ V_19 ++ ] = V_102 ;
if ( V_102 == '\\' && V_111 == '\\' )
V_111 = 0 ;
} while ( V_102 != V_112 || V_111 == '\\' );
V_19 -- ;
if ( type == V_105 ) {
unsigned long long V_118 = V_5 ;
do {
V_102 = F_37 () ;
} while ( isspace ( V_102 ) );
if ( V_102 == '"' )
goto V_117;
V_5 = V_118 ;
}
goto V_116;
case V_60 ... V_104 :
case V_58 :
default:
break;
}
while ( F_36 ( F_38 () ) == type ) {
if ( V_19 == ( V_110 - 1 ) ) {
V_1 [ V_19 ] = 0 ;
V_114 += V_110 ;
if ( F_40 ( V_108 , V_1 , V_114 ) < 0 )
return V_106 ;
V_19 = 0 ;
}
V_102 = F_37 () ;
V_1 [ V_19 ++ ] = V_102 ;
}
V_116:
V_1 [ V_19 ] = 0 ;
if ( F_40 ( V_108 , V_1 , V_114 + V_19 + 1 ) < 0 )
return V_106 ;
if ( type == V_58 ) {
if ( strcmp ( * V_108 , L_10 ) == 0 ) {
free ( * V_108 ) ;
* V_108 = NULL ;
return F_43 ( L_11 , V_108 ) ;
} else if ( strcmp ( * V_108 , L_12 ) == 0 ) {
free ( * V_108 ) ;
* V_108 = NULL ;
return F_43 ( L_13 , V_108 ) ;
} else if ( strcmp ( * V_108 , L_14 ) == 0 ) {
free ( * V_108 ) ;
* V_108 = NULL ;
return F_43 ( L_15 , V_108 ) ;
}
}
return type ;
}
static enum V_57 F_43 ( const char * V_65 , char * * V_108 )
{
const char * V_119 ;
unsigned long long V_118 ;
unsigned long long V_120 ;
enum V_57 type ;
V_119 = V_3 ;
V_118 = V_5 ;
V_120 = V_4 ;
F_1 ( V_65 , strlen ( V_65 ) ) ;
type = F_41 ( V_108 ) ;
V_3 = V_119 ;
V_5 = V_118 ;
V_4 = V_120 ;
return type ;
}
static void F_44 ( char * V_108 )
{
if ( V_108 )
free ( V_108 ) ;
}
static enum V_57 F_45 ( char * * V_108 )
{
enum V_57 type ;
for (; ; ) {
type = F_41 ( V_108 ) ;
if ( type != V_104 )
return type ;
F_44 ( * V_108 ) ;
}
* V_108 = NULL ;
return V_106 ;
}
enum V_57 F_46 ( char * * V_108 )
{
return F_45 ( V_108 ) ;
}
void F_47 ( char * V_121 )
{
F_44 ( V_121 ) ;
}
static enum V_57 F_48 ( char * * V_108 )
{
enum V_57 type ;
for (; ; ) {
type = F_41 ( V_108 ) ;
if ( type != V_104 && type != V_103 )
return type ;
F_44 ( * V_108 ) ;
* V_108 = NULL ;
}
* V_108 = NULL ;
return V_106 ;
}
static int F_49 ( enum V_57 type , enum V_57 V_122 )
{
if ( type != V_122 ) {
F_50 ( L_16 ,
V_122 , type ) ;
return - 1 ;
}
return 0 ;
}
static int F_51 ( enum V_57 type , const char * V_121 ,
enum V_57 V_122 , const char * V_123 )
{
if ( type != V_122 ) {
F_50 ( L_16 ,
V_122 , type ) ;
return - 1 ;
}
if ( strcmp ( V_121 , V_123 ) != 0 ) {
F_50 ( L_17 ,
V_123 , V_121 ) ;
return - 1 ;
}
return 0 ;
}
static int F_52 ( enum V_57 V_122 , char * * V_108 , int V_124 )
{
enum V_57 type ;
if ( V_124 )
type = F_45 ( V_108 ) ;
else
type = F_48 ( V_108 ) ;
return F_49 ( type , V_122 ) ;
}
static int F_53 ( enum V_57 V_122 , char * * V_108 )
{
return F_52 ( V_122 , V_108 , 1 ) ;
}
static int F_54 ( enum V_57 V_122 , const char * V_65 ,
int V_124 )
{
enum V_57 type ;
char * V_121 ;
int V_125 ;
if ( V_124 )
type = F_45 ( & V_121 ) ;
else
type = F_48 ( & V_121 ) ;
V_125 = F_51 ( type , V_121 , V_122 , V_65 ) ;
F_44 ( V_121 ) ;
return V_125 ;
}
static int F_55 ( enum V_57 V_122 , const char * V_65 )
{
return F_54 ( V_122 , V_65 , 1 ) ;
}
static int F_56 ( enum V_57 V_122 , const char * V_65 )
{
return F_54 ( V_122 , V_65 , 0 ) ;
}
static char * F_57 ( void )
{
char * V_121 ;
if ( F_55 ( V_58 , L_18 ) < 0 )
return NULL ;
if ( F_55 ( V_107 , L_19 ) < 0 )
return NULL ;
if ( F_53 ( V_58 , & V_121 ) < 0 )
goto V_126;
return V_121 ;
V_126:
F_44 ( V_121 ) ;
return NULL ;
}
static int F_58 ( void )
{
char * V_121 ;
int V_56 ;
if ( F_56 ( V_58 , L_20 ) < 0 )
return - 1 ;
if ( F_55 ( V_107 , L_19 ) < 0 )
return - 1 ;
if ( F_53 ( V_58 , & V_121 ) < 0 )
goto V_126;
V_56 = strtoul ( V_121 , NULL , 0 ) ;
F_44 ( V_121 ) ;
return V_56 ;
V_126:
F_44 ( V_121 ) ;
return - 1 ;
}
static int F_59 ( struct V_127 * V_71 )
{
if ( ( V_71 -> V_74 & V_128 ) &&
( strstr ( V_71 -> type , L_21 ) || strstr ( V_71 -> type , L_22 ) ||
strstr ( V_71 -> type , L_23 ) ) )
return 1 ;
return 0 ;
}
static int F_60 ( struct V_127 * V_71 )
{
if ( strncmp ( V_71 -> type , L_24 , 10 ) == 0 )
return 1 ;
return 0 ;
}
static int F_61 ( struct V_127 * V_71 )
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
} V_129 [] = {
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
for ( V_19 = 0 ; V_129 [ V_19 ] . type ; V_19 ++ ) {
if ( ! strcmp ( V_129 [ V_19 ] . type , V_72 ) )
return V_129 [ V_19 ] . V_2 ;
}
return 0 ;
}
static int F_63 ( struct V_52 * V_53 , struct V_127 * * V_130 )
{
struct V_127 * V_71 = NULL ;
enum V_57 type ;
char * V_121 ;
char * V_131 ;
int V_84 = 0 ;
do {
unsigned int V_132 = 0 ;
type = F_45 ( & V_121 ) ;
if ( type == V_103 ) {
F_44 ( V_121 ) ;
return V_84 ;
}
V_84 ++ ;
if ( F_51 ( type , V_121 , V_58 , L_32 ) )
goto V_126;
F_44 ( V_121 ) ;
type = F_45 ( & V_121 ) ;
if ( V_53 -> V_74 & V_133 &&
type == V_58 && strcmp ( V_121 , L_33 ) == 0 ) {
F_44 ( V_121 ) ;
type = F_45 ( & V_121 ) ;
}
if ( F_51 ( type , V_121 , V_107 , L_19 ) < 0 )
goto V_126;
F_44 ( V_121 ) ;
if ( F_53 ( V_58 , & V_121 ) < 0 )
goto V_126;
V_131 = V_121 ;
V_71 = calloc ( 1 , sizeof( * V_71 ) ) ;
if ( ! V_71 )
goto V_126;
V_71 -> V_53 = V_53 ;
for (; ; ) {
type = F_45 ( & V_121 ) ;
if ( type == V_58 ||
( type == V_107 && strcmp ( V_121 , L_34 ) == 0 ) ||
( V_53 -> V_74 & V_133 &&
type == V_107 && strcmp ( V_121 , L_35 ) == 0 ) ) {
if ( strcmp ( V_121 , L_34 ) == 0 )
V_71 -> V_74 |= V_134 ;
if ( V_71 -> type ) {
char * V_135 ;
V_135 = realloc ( V_71 -> type ,
strlen ( V_71 -> type ) +
strlen ( V_131 ) + 2 ) ;
if ( ! V_135 ) {
free ( V_131 ) ;
goto V_126;
}
V_71 -> type = V_135 ;
strcat ( V_71 -> type , L_36 ) ;
strcat ( V_71 -> type , V_131 ) ;
free ( V_131 ) ;
} else
V_71 -> type = V_131 ;
V_131 = V_121 ;
continue;
}
break;
}
if ( ! V_71 -> type ) {
F_64 ( V_53 , L_37 , V_136 ) ;
goto V_126;
}
V_71 -> V_72 = V_71 -> V_137 = V_131 ;
if ( F_49 ( type , V_107 ) )
goto V_126;
if ( strcmp ( V_121 , L_38 ) == 0 ) {
enum V_57 V_138 = type ;
char * V_139 = V_121 ;
char * V_140 ;
int V_141 ;
V_71 -> V_74 |= V_128 ;
type = F_45 ( & V_121 ) ;
if ( type == V_58 )
V_71 -> V_142 = strtoul ( V_121 , NULL , 0 ) ;
else
V_71 -> V_142 = 0 ;
while ( strcmp ( V_121 , L_39 ) != 0 ) {
if ( V_138 == V_58 &&
type == V_58 )
V_141 = 2 ;
else
V_141 = 1 ;
V_138 = type ;
V_140 = realloc ( V_139 ,
strlen ( V_139 ) +
strlen ( V_121 ) + V_141 ) ;
if ( ! V_140 ) {
free ( V_139 ) ;
goto V_126;
}
V_139 = V_140 ;
if ( V_141 == 2 )
strcat ( V_139 , L_36 ) ;
strcat ( V_139 , V_121 ) ;
V_71 -> V_142 = strtoul ( V_121 , NULL , 0 ) ;
F_44 ( V_121 ) ;
type = F_45 ( & V_121 ) ;
if ( type == V_106 ) {
F_64 ( V_53 , L_40 ) ;
goto V_126;
}
}
F_44 ( V_121 ) ;
V_140 = realloc ( V_139 , strlen ( V_139 ) + 2 ) ;
if ( ! V_140 ) {
free ( V_139 ) ;
goto V_126;
}
V_139 = V_140 ;
strcat ( V_139 , L_39 ) ;
type = F_45 ( & V_121 ) ;
if ( type == V_58 ) {
char * V_135 ;
V_135 = realloc ( V_71 -> type ,
strlen ( V_71 -> type ) +
strlen ( V_71 -> V_72 ) +
strlen ( V_139 ) + 2 ) ;
if ( ! V_135 ) {
free ( V_139 ) ;
goto V_126;
}
V_71 -> type = V_135 ;
strcat ( V_71 -> type , L_36 ) ;
strcat ( V_71 -> type , V_71 -> V_72 ) ;
V_132 = F_62 ( V_71 -> V_72 ) ;
F_44 ( V_71 -> V_72 ) ;
strcat ( V_71 -> type , V_139 ) ;
V_71 -> V_72 = V_71 -> V_137 = V_121 ;
type = F_45 ( & V_121 ) ;
} else {
char * V_135 ;
V_135 = realloc ( V_71 -> type ,
strlen ( V_71 -> type ) +
strlen ( V_139 ) + 1 ) ;
if ( ! V_135 ) {
free ( V_139 ) ;
goto V_126;
}
V_71 -> type = V_135 ;
strcat ( V_71 -> type , V_139 ) ;
}
free ( V_139 ) ;
}
if ( F_59 ( V_71 ) )
V_71 -> V_74 |= V_143 ;
if ( F_60 ( V_71 ) )
V_71 -> V_74 |= V_144 ;
if ( F_61 ( V_71 ) )
V_71 -> V_74 |= V_145 ;
if ( F_51 ( type , V_121 , V_107 , L_41 ) )
goto V_126;
F_44 ( V_121 ) ;
if ( F_55 ( V_58 , L_42 ) < 0 )
goto V_146;
if ( F_55 ( V_107 , L_19 ) < 0 )
goto V_146;
if ( F_53 ( V_58 , & V_121 ) )
goto V_126;
V_71 -> V_147 = strtoul ( V_121 , NULL , 0 ) ;
F_44 ( V_121 ) ;
if ( F_55 ( V_107 , L_41 ) < 0 )
goto V_146;
if ( F_55 ( V_58 , L_43 ) < 0 )
goto V_146;
if ( F_55 ( V_107 , L_19 ) < 0 )
goto V_146;
if ( F_53 ( V_58 , & V_121 ) )
goto V_126;
V_71 -> V_2 = strtoul ( V_121 , NULL , 0 ) ;
F_44 ( V_121 ) ;
if ( F_55 ( V_107 , L_41 ) < 0 )
goto V_146;
type = F_45 ( & V_121 ) ;
if ( type != V_103 ) {
if ( F_51 ( type , V_121 , V_58 , L_44 ) )
goto V_126;
F_44 ( V_121 ) ;
if ( F_55 ( V_107 , L_19 ) < 0 )
goto V_146;
if ( F_53 ( V_58 , & V_121 ) )
goto V_126;
if ( strtoul ( V_121 , NULL , 0 ) )
V_71 -> V_74 |= V_148 ;
F_44 ( V_121 ) ;
if ( F_55 ( V_107 , L_41 ) < 0 )
goto V_146;
if ( F_53 ( V_103 , & V_121 ) )
goto V_126;
}
F_44 ( V_121 ) ;
if ( V_71 -> V_74 & V_128 ) {
if ( V_71 -> V_142 )
V_71 -> V_149 = V_71 -> V_2 / V_71 -> V_142 ;
else if ( V_71 -> V_74 & V_144 )
V_71 -> V_149 = V_132 ;
else if ( V_71 -> V_74 & V_143 )
V_71 -> V_149 = 1 ;
else if ( V_71 -> V_74 & V_145 )
V_71 -> V_149 = V_53 -> V_14 ?
V_53 -> V_14 -> V_150 :
sizeof( long ) ;
} else
V_71 -> V_149 = V_71 -> V_2 ;
* V_130 = V_71 ;
V_130 = & V_71 -> V_22 ;
} while ( 1 );
return 0 ;
V_126:
F_44 ( V_121 ) ;
V_146:
if ( V_71 ) {
free ( V_71 -> type ) ;
free ( V_71 -> V_72 ) ;
free ( V_71 ) ;
}
return - 1 ;
}
static int F_65 ( struct V_52 * V_53 )
{
char * V_121 ;
int V_125 ;
if ( F_56 ( V_58 , L_45 ) < 0 )
return - 1 ;
if ( F_55 ( V_107 , L_19 ) < 0 )
return - 1 ;
if ( F_53 ( V_103 , & V_121 ) )
goto V_126;
F_44 ( V_121 ) ;
V_125 = F_63 ( V_53 , & V_53 -> V_151 . V_152 ) ;
if ( V_125 < 0 )
return V_125 ;
V_53 -> V_151 . V_153 = V_125 ;
V_125 = F_63 ( V_53 , & V_53 -> V_151 . V_130 ) ;
if ( V_125 < 0 )
return V_125 ;
V_53 -> V_151 . V_154 = V_125 ;
return 0 ;
V_126:
F_44 ( V_121 ) ;
return - 1 ;
}
static enum V_57
F_66 ( struct V_52 * V_53 , struct V_7 * V_66 , char * * V_108 )
{
enum V_57 type ;
char * V_121 ;
type = F_45 ( & V_121 ) ;
* V_108 = V_121 ;
return F_67 ( V_53 , V_66 , V_108 , type ) ;
}
static enum V_57
F_68 ( struct V_52 * V_53 , struct V_7 * V_66 , char * * V_108 )
{
enum V_57 type ;
type = F_66 ( V_53 , V_66 , V_108 ) ;
while ( type == V_107 ) {
type = F_69 ( V_53 , V_66 , V_108 ) ;
}
return type ;
}
static enum V_57
F_70 ( struct V_52 * V_53 , struct V_7 * V_155 , char * * V_108 )
{
struct V_7 * V_66 , * V_98 , * V_99 ;
enum V_57 type ;
char * V_121 = NULL ;
V_66 = F_6 () ;
V_98 = F_6 () ;
V_99 = F_6 () ;
if ( ! V_66 || ! V_98 || ! V_99 ) {
F_64 ( V_53 , L_46 , V_136 ) ;
F_35 ( V_98 ) ;
F_35 ( V_99 ) ;
goto V_41;
}
V_66 -> type = V_96 ;
V_66 -> V_97 . V_98 = V_98 ;
V_66 -> V_97 . V_99 = V_99 ;
* V_108 = NULL ;
type = F_66 ( V_53 , V_98 , & V_121 ) ;
V_156:
if ( type == V_60 )
goto V_41;
if ( type == V_107 && strcmp ( V_121 , L_19 ) != 0 ) {
type = F_69 ( V_53 , V_98 , & V_121 ) ;
goto V_156;
}
if ( F_51 ( type , V_121 , V_107 , L_19 ) )
goto V_41;
V_66 -> V_97 . V_97 = V_121 ;
type = F_66 ( V_53 , V_99 , & V_121 ) ;
V_155 -> V_97 . V_99 = V_66 ;
* V_108 = V_121 ;
return type ;
V_41:
V_155 -> V_97 . V_99 = NULL ;
F_44 ( V_121 ) ;
F_35 ( V_66 ) ;
return V_60 ;
}
static enum V_57
F_71 ( struct V_52 * V_53 , struct V_7 * V_155 , char * * V_108 )
{
struct V_7 * V_66 ;
enum V_57 type ;
char * V_121 = NULL ;
V_66 = F_6 () ;
if ( ! V_66 ) {
F_64 ( V_53 , L_46 , V_136 ) ;
* V_108 = NULL ;
return V_60 ;
}
* V_108 = NULL ;
type = F_66 ( V_53 , V_66 , & V_121 ) ;
if ( F_51 ( type , V_121 , V_107 , L_39 ) )
goto V_41;
V_155 -> V_97 . V_99 = V_66 ;
F_44 ( V_121 ) ;
type = F_48 ( & V_121 ) ;
* V_108 = V_121 ;
return type ;
V_41:
F_44 ( V_121 ) ;
F_35 ( V_66 ) ;
return V_60 ;
}
static int F_72 ( char * V_97 )
{
if ( ! V_97 [ 1 ] ) {
switch ( V_97 [ 0 ] ) {
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
F_50 ( L_47 , V_97 [ 0 ] ) ;
return - 1 ;
}
} else {
if ( strcmp ( V_97 , L_48 ) == 0 ||
strcmp ( V_97 , L_49 ) == 0 ) {
return 3 ;
} else if ( strcmp ( V_97 , L_50 ) == 0 ||
strcmp ( V_97 , L_51 ) == 0 ) {
return 8 ;
} else if ( strcmp ( V_97 , L_52 ) == 0 ||
strcmp ( V_97 , L_53 ) == 0 ) {
return 9 ;
} else if ( strcmp ( V_97 , L_54 ) == 0 ||
strcmp ( V_97 , L_55 ) == 0 ) {
return 10 ;
} else if ( strcmp ( V_97 , L_56 ) == 0 ) {
return 14 ;
} else if ( strcmp ( V_97 , L_57 ) == 0 ) {
return 15 ;
} else {
F_50 ( L_58 , V_97 ) ;
return - 1 ;
}
}
}
static int F_73 ( struct V_7 * V_66 )
{
if ( ! V_66 -> V_97 . V_98 || V_66 -> V_97 . V_98 -> type == V_101 )
V_66 -> V_97 . V_157 = 0 ;
else
V_66 -> V_97 . V_157 = F_72 ( V_66 -> V_97 . V_97 ) ;
return V_66 -> V_97 . V_157 ;
}
static enum V_57
F_69 ( struct V_52 * V_53 , struct V_7 * V_66 , char * * V_108 )
{
struct V_7 * V_98 , * V_99 = NULL ;
enum V_57 type ;
char * V_121 ;
V_121 = * V_108 ;
if ( V_66 -> type == V_96 && ! V_66 -> V_97 . V_98 ) {
if ( V_121 [ 1 ] ) {
F_64 ( V_53 , L_59 , V_121 ) ;
goto V_41;
}
switch ( V_121 [ 0 ] ) {
case '~' :
case '!' :
case '+' :
case '-' :
break;
default:
F_64 ( V_53 , L_59 , V_121 ) ;
goto V_41;
}
V_98 = F_6 () ;
if ( ! V_98 )
goto V_158;
V_98 -> type = V_101 ;
V_66 -> V_97 . V_98 = V_98 ;
V_99 = F_6 () ;
if ( ! V_99 )
goto V_158;
V_66 -> V_97 . V_99 = V_99 ;
* V_108 = NULL ;
type = F_66 ( V_53 , V_99 , V_108 ) ;
} else if ( strcmp ( V_121 , L_60 ) == 0 ) {
V_98 = F_6 () ;
if ( ! V_98 )
goto V_158;
* V_98 = * V_66 ;
V_66 -> type = V_96 ;
V_66 -> V_97 . V_97 = V_121 ;
V_66 -> V_97 . V_98 = V_98 ;
V_66 -> V_97 . V_157 = 0 ;
type = F_70 ( V_53 , V_66 , V_108 ) ;
} else if ( strcmp ( V_121 , L_50 ) == 0 ||
strcmp ( V_121 , L_51 ) == 0 ||
strcmp ( V_121 , L_61 ) == 0 ||
strcmp ( V_121 , L_62 ) == 0 ||
strcmp ( V_121 , L_56 ) == 0 ||
strcmp ( V_121 , L_57 ) == 0 ||
strcmp ( V_121 , L_63 ) == 0 ||
strcmp ( V_121 , L_64 ) == 0 ||
strcmp ( V_121 , L_34 ) == 0 ||
strcmp ( V_121 , L_65 ) == 0 ||
strcmp ( V_121 , L_66 ) == 0 ||
strcmp ( V_121 , L_67 ) == 0 ||
strcmp ( V_121 , L_68 ) == 0 ||
strcmp ( V_121 , L_69 ) == 0 ||
strcmp ( V_121 , L_53 ) == 0 ||
strcmp ( V_121 , L_52 ) == 0 ||
strcmp ( V_121 , L_54 ) == 0 ||
strcmp ( V_121 , L_55 ) == 0 ) {
V_98 = F_6 () ;
if ( ! V_98 )
goto V_158;
* V_98 = * V_66 ;
V_66 -> type = V_96 ;
V_66 -> V_97 . V_97 = V_121 ;
V_66 -> V_97 . V_98 = V_98 ;
V_66 -> V_97 . V_99 = NULL ;
if ( F_73 ( V_66 ) == - 1 ) {
V_53 -> V_74 |= V_159 ;
V_66 -> V_97 . V_97 = NULL ;
goto V_41;
}
type = F_48 ( & V_121 ) ;
* V_108 = V_121 ;
if ( ( strcmp ( V_66 -> V_97 . V_97 , L_34 ) == 0 ) &&
type == V_61 && ( strcmp ( V_121 , L_70 ) == 0 ) ) {
char * V_160 ;
if ( V_98 -> type != V_68 ) {
F_64 ( V_53 , L_71 ) ;
goto V_41;
}
V_160 = realloc ( V_98 -> V_69 . V_69 ,
strlen ( V_98 -> V_69 . V_69 ) + 3 ) ;
if ( ! V_160 )
goto V_158;
V_98 -> V_69 . V_69 = V_160 ;
strcat ( V_98 -> V_69 . V_69 , L_72 ) ;
free ( V_66 -> V_97 . V_97 ) ;
* V_66 = * V_98 ;
free ( V_98 ) ;
return type ;
}
V_99 = F_6 () ;
if ( ! V_99 )
goto V_158;
type = F_67 ( V_53 , V_99 , V_108 , type ) ;
if ( type == V_60 ) {
F_35 ( V_99 ) ;
V_121 = NULL ;
goto V_41;
}
if ( V_99 -> type == V_96 &&
F_72 ( V_66 -> V_97 . V_97 ) < F_72 ( V_99 -> V_97 . V_97 ) ) {
struct V_7 V_161 ;
V_66 -> V_97 . V_99 = V_99 -> V_97 . V_98 ;
V_161 = * V_66 ;
* V_66 = * V_99 ;
* V_99 = V_161 ;
V_66 -> V_97 . V_98 = V_99 ;
} else {
V_66 -> V_97 . V_99 = V_99 ;
}
} else if ( strcmp ( V_121 , L_38 ) == 0 ) {
V_98 = F_6 () ;
if ( ! V_98 )
goto V_158;
* V_98 = * V_66 ;
V_66 -> type = V_96 ;
V_66 -> V_97 . V_97 = V_121 ;
V_66 -> V_97 . V_98 = V_98 ;
V_66 -> V_97 . V_157 = 0 ;
type = F_71 ( V_53 , V_66 , V_108 ) ;
} else {
F_64 ( V_53 , L_58 , V_121 ) ;
V_53 -> V_74 |= V_159 ;
goto V_41;
}
if ( type == V_107 && strcmp ( * V_108 , L_19 ) != 0 ) {
int V_157 ;
V_157 = F_72 ( * V_108 ) ;
if ( V_157 > V_66 -> V_97 . V_157 )
return F_69 ( V_53 , V_66 , V_108 ) ;
return F_69 ( V_53 , V_99 , V_108 ) ;
}
return type ;
V_158:
F_64 ( V_53 , L_46 , V_136 ) ;
V_41:
F_44 ( V_121 ) ;
* V_108 = NULL ;
return V_60 ;
}
static enum V_57
F_74 ( struct V_52 * V_53 V_162 , struct V_7 * V_66 ,
char * * V_108 )
{
enum V_57 type ;
char * V_71 ;
char * V_121 ;
if ( F_55 ( V_107 , L_73 ) < 0 )
goto V_163;
if ( F_53 ( V_58 , & V_121 ) < 0 )
goto V_41;
V_71 = V_121 ;
V_66 -> type = V_70 ;
V_66 -> V_71 . V_72 = V_71 ;
if ( V_164 ) {
V_66 -> V_71 . V_71 = F_75 ( V_53 , V_66 -> V_71 . V_72 ) ;
V_66 -> V_71 . V_71 -> V_74 |= V_165 ;
V_164 = 0 ;
} else if ( V_166 ) {
V_66 -> V_71 . V_71 = F_75 ( V_53 , V_66 -> V_71 . V_72 ) ;
V_66 -> V_71 . V_71 -> V_74 |= V_167 ;
V_166 = 0 ;
}
type = F_45 ( & V_121 ) ;
* V_108 = V_121 ;
return type ;
V_41:
F_44 ( V_121 ) ;
V_163:
* V_108 = NULL ;
return V_60 ;
}
static int F_76 ( struct V_52 * V_53 , char * V_168 ,
struct V_7 * * V_7 )
{
struct V_7 * V_71 ;
enum V_57 type ;
char * V_121 ;
int V_125 = 0 ;
V_71 = F_6 () ;
if ( ! V_71 ) {
F_64 ( V_53 , L_46 , V_136 ) ;
V_24 = V_26 ;
return - 1 ;
}
type = F_66 ( V_53 , V_71 , & V_121 ) ;
if ( F_51 ( type , V_121 , V_61 , V_168 ) ) {
V_24 = V_169 ;
V_125 = - 1 ;
F_35 ( V_71 ) ;
goto V_170;
}
* V_7 = V_71 ;
V_170:
F_44 ( V_121 ) ;
return V_125 ;
}
static unsigned long long
F_77 ( unsigned long long V_171 , const char * type , int V_172 )
{
int V_173 = 0 ;
char * V_174 ;
int V_141 ;
V_141 = strlen ( type ) ;
if ( V_172 ) {
if ( type [ V_141 - 1 ] != '*' ) {
F_50 ( L_74 ) ;
return V_171 ;
}
V_174 = malloc ( V_141 ) ;
if ( ! V_174 ) {
F_50 ( L_46 , V_136 ) ;
return V_171 ;
}
memcpy ( V_174 , type , V_141 ) ;
V_174 [ V_141 - 2 ] = 0 ;
V_171 = F_77 ( V_171 , V_174 , 0 ) ;
free ( V_174 ) ;
return V_171 ;
}
if ( type [ V_141 - 1 ] == '*' )
return V_171 ;
if ( strncmp ( type , L_75 , 6 ) == 0 )
return V_171 ;
if ( strcmp ( type , L_22 ) == 0 )
return V_171 & 0xff ;
if ( strcmp ( type , L_26 ) == 0 )
return V_171 & 0xffff ;
if ( strcmp ( type , L_27 ) == 0 )
return V_171 & 0xffffffff ;
if ( strcmp ( type , L_28 ) == 0 ||
strcmp ( type , L_31 ) )
return V_171 ;
if ( strcmp ( type , L_23 ) == 0 )
return ( unsigned long long ) ( char ) V_171 & 0xff ;
if ( strcmp ( type , L_29 ) == 0 )
return ( unsigned long long ) ( short ) V_171 & 0xffff ;
if ( strcmp ( type , L_30 ) == 0 )
return ( unsigned long long ) ( int ) V_171 & 0xffffffff ;
if ( strncmp ( type , L_76 , 9 ) == 0 ) {
V_173 = 0 ;
type += 9 ;
}
if ( strcmp ( type , L_21 ) == 0 ) {
if ( V_173 )
return ( unsigned long long ) ( char ) V_171 & 0xff ;
else
return V_171 & 0xff ;
}
if ( strcmp ( type , L_77 ) == 0 ) {
if ( V_173 )
return ( unsigned long long ) ( short ) V_171 & 0xffff ;
else
return V_171 & 0xffff ;
}
if ( strcmp ( type , L_78 ) == 0 ) {
if ( V_173 )
return ( unsigned long long ) ( int ) V_171 & 0xffffffff ;
else
return V_171 & 0xffffffff ;
}
return V_171 ;
}
static unsigned long long
F_78 ( unsigned long long V_171 , struct V_7 * V_66 , int V_172 )
{
if ( V_66 -> type != V_86 ) {
F_50 ( L_79 ) ;
return 0 ;
}
return F_77 ( V_171 , V_66 -> V_87 . type , V_172 ) ;
}
static int F_79 ( struct V_7 * V_66 , long long * V_171 )
{
long long V_98 , V_99 ;
int V_125 = 1 ;
switch ( V_66 -> type ) {
case V_68 :
* V_171 = strtoll ( V_66 -> V_69 . V_69 , NULL , 0 ) ;
break;
case V_86 :
V_125 = F_79 ( V_66 -> V_87 . V_17 , V_171 ) ;
if ( ! V_125 )
break;
* V_171 = F_78 ( * V_171 , V_66 , 0 ) ;
break;
case V_96 :
switch ( V_66 -> V_97 . V_97 [ 0 ] ) {
case '|' :
V_125 = F_79 ( V_66 -> V_97 . V_98 , & V_98 ) ;
if ( ! V_125 )
break;
V_125 = F_79 ( V_66 -> V_97 . V_99 , & V_99 ) ;
if ( ! V_125 )
break;
if ( V_66 -> V_97 . V_97 [ 1 ] )
* V_171 = V_98 || V_99 ;
else
* V_171 = V_98 | V_99 ;
break;
case '&' :
V_125 = F_79 ( V_66 -> V_97 . V_98 , & V_98 ) ;
if ( ! V_125 )
break;
V_125 = F_79 ( V_66 -> V_97 . V_99 , & V_99 ) ;
if ( ! V_125 )
break;
if ( V_66 -> V_97 . V_97 [ 1 ] )
* V_171 = V_98 && V_99 ;
else
* V_171 = V_98 & V_99 ;
break;
case '<' :
V_125 = F_79 ( V_66 -> V_97 . V_98 , & V_98 ) ;
if ( ! V_125 )
break;
V_125 = F_79 ( V_66 -> V_97 . V_99 , & V_99 ) ;
if ( ! V_125 )
break;
switch ( V_66 -> V_97 . V_97 [ 1 ] ) {
case 0 :
* V_171 = V_98 < V_99 ;
break;
case '<' :
* V_171 = V_98 << V_99 ;
break;
case '=' :
* V_171 = V_98 <= V_99 ;
break;
default:
F_50 ( L_58 , V_66 -> V_97 . V_97 ) ;
V_125 = 0 ;
}
break;
case '>' :
V_125 = F_79 ( V_66 -> V_97 . V_98 , & V_98 ) ;
if ( ! V_125 )
break;
V_125 = F_79 ( V_66 -> V_97 . V_99 , & V_99 ) ;
if ( ! V_125 )
break;
switch ( V_66 -> V_97 . V_97 [ 1 ] ) {
case 0 :
* V_171 = V_98 > V_99 ;
break;
case '>' :
* V_171 = V_98 >> V_99 ;
break;
case '=' :
* V_171 = V_98 >= V_99 ;
break;
default:
F_50 ( L_58 , V_66 -> V_97 . V_97 ) ;
V_125 = 0 ;
}
break;
case '=' :
V_125 = F_79 ( V_66 -> V_97 . V_98 , & V_98 ) ;
if ( ! V_125 )
break;
V_125 = F_79 ( V_66 -> V_97 . V_99 , & V_99 ) ;
if ( ! V_125 )
break;
if ( V_66 -> V_97 . V_97 [ 1 ] != '=' ) {
F_50 ( L_58 , V_66 -> V_97 . V_97 ) ;
V_125 = 0 ;
} else
* V_171 = V_98 == V_99 ;
break;
case '!' :
V_125 = F_79 ( V_66 -> V_97 . V_98 , & V_98 ) ;
if ( ! V_125 )
break;
V_125 = F_79 ( V_66 -> V_97 . V_99 , & V_99 ) ;
if ( ! V_125 )
break;
switch ( V_66 -> V_97 . V_97 [ 1 ] ) {
case '=' :
* V_171 = V_98 != V_99 ;
break;
default:
F_50 ( L_58 , V_66 -> V_97 . V_97 ) ;
V_125 = 0 ;
}
break;
case '-' :
if ( V_66 -> V_97 . V_98 -> type == V_101 )
V_98 = 0 ;
else
V_125 = F_79 ( V_66 -> V_97 . V_98 , & V_98 ) ;
if ( ! V_125 )
break;
V_125 = F_79 ( V_66 -> V_97 . V_99 , & V_99 ) ;
if ( ! V_125 )
break;
* V_171 = V_98 - V_99 ;
break;
case '+' :
if ( V_66 -> V_97 . V_98 -> type == V_101 )
V_98 = 0 ;
else
V_125 = F_79 ( V_66 -> V_97 . V_98 , & V_98 ) ;
if ( ! V_125 )
break;
V_125 = F_79 ( V_66 -> V_97 . V_99 , & V_99 ) ;
if ( ! V_125 )
break;
* V_171 = V_98 + V_99 ;
break;
case '~' :
V_125 = F_79 ( V_66 -> V_97 . V_99 , & V_99 ) ;
if ( ! V_125 )
break;
* V_171 = ~ V_99 ;
break;
default:
F_50 ( L_58 , V_66 -> V_97 . V_97 ) ;
V_125 = 0 ;
}
break;
case V_101 :
case V_70 ... V_76 :
case V_88 :
case V_89 :
case V_90 :
default:
F_50 ( L_80 , V_66 -> type ) ;
V_125 = 0 ;
}
return V_125 ;
}
static char * F_80 ( struct V_7 * V_66 )
{
long long V_171 ;
static char V_1 [ 20 ] ;
switch ( V_66 -> type ) {
case V_68 :
return V_66 -> V_69 . V_69 ;
case V_86 :
return F_80 ( V_66 -> V_87 . V_17 ) ;
case V_96 :
if ( ! F_79 ( V_66 , & V_171 ) )
break;
sprintf ( V_1 , L_81 , V_171 ) ;
return V_1 ;
case V_101 :
case V_70 ... V_76 :
case V_88 :
case V_89 :
case V_90 :
default:
F_50 ( L_80 , V_66 -> type ) ;
break;
}
return NULL ;
}
static enum V_57
F_81 ( struct V_52 * V_53 , struct V_62 * * V_175 , char * * V_108 )
{
enum V_57 type ;
struct V_7 * V_66 = NULL ;
struct V_62 * V_71 ;
char * V_121 = * V_108 ;
char * V_64 ;
do {
F_44 ( V_121 ) ;
type = F_48 ( & V_121 ) ;
if ( F_51 ( type , V_121 , V_107 , L_82 ) )
break;
V_66 = F_6 () ;
if ( ! V_66 )
goto V_41;
F_44 ( V_121 ) ;
type = F_66 ( V_53 , V_66 , & V_121 ) ;
if ( type == V_107 )
type = F_69 ( V_53 , V_66 , & V_121 ) ;
if ( type == V_60 )
goto V_41;
if ( F_51 ( type , V_121 , V_61 , L_83 ) )
goto V_41;
V_71 = calloc ( 1 , sizeof( * V_71 ) ) ;
if ( ! V_71 )
goto V_41;
V_64 = F_80 ( V_66 ) ;
if ( V_64 == NULL )
goto V_176;
V_71 -> V_64 = F_12 ( V_64 ) ;
if ( V_71 -> V_64 == NULL )
goto V_176;
F_35 ( V_66 ) ;
V_66 = F_6 () ;
if ( ! V_66 )
goto V_41;
F_44 ( V_121 ) ;
type = F_66 ( V_53 , V_66 , & V_121 ) ;
if ( F_51 ( type , V_121 , V_107 , L_84 ) )
goto V_176;
V_64 = F_80 ( V_66 ) ;
if ( V_64 == NULL )
goto V_176;
V_71 -> V_65 = F_12 ( V_64 ) ;
if ( V_71 -> V_65 == NULL )
goto V_176;
F_35 ( V_66 ) ;
V_66 = NULL ;
* V_175 = V_71 ;
V_175 = & V_71 -> V_22 ;
F_44 ( V_121 ) ;
type = F_48 ( & V_121 ) ;
} while ( type == V_61 && strcmp ( V_121 , L_83 ) == 0 );
* V_108 = V_121 ;
return type ;
V_176:
F_34 ( V_71 ) ;
V_41:
F_35 ( V_66 ) ;
F_44 ( V_121 ) ;
* V_108 = NULL ;
return V_60 ;
}
static enum V_57
F_82 ( struct V_52 * V_53 , struct V_7 * V_66 , char * * V_108 )
{
struct V_7 * V_71 ;
enum V_57 type ;
char * V_121 = NULL ;
memset ( V_66 , 0 , sizeof( * V_66 ) ) ;
V_66 -> type = V_73 ;
V_71 = F_6 () ;
if ( ! V_71 ) {
F_64 ( V_53 , L_46 , V_136 ) ;
goto V_41;
}
type = F_68 ( V_53 , V_71 , & V_121 ) ;
while ( type == V_107 )
type = F_69 ( V_53 , V_71 , & V_121 ) ;
if ( F_51 ( type , V_121 , V_61 , L_83 ) )
goto V_176;
F_44 ( V_121 ) ;
V_66 -> V_74 . V_71 = V_71 ;
type = F_48 ( & V_121 ) ;
if ( F_33 ( type ) ) {
V_66 -> V_74 . V_75 = V_121 ;
type = F_48 ( & V_121 ) ;
}
if ( F_51 ( type , V_121 , V_61 , L_83 ) )
goto V_41;
type = F_81 ( V_53 , & V_66 -> V_74 . V_74 , & V_121 ) ;
if ( F_51 ( type , V_121 , V_61 , L_70 ) )
goto V_41;
F_44 ( V_121 ) ;
type = F_48 ( V_108 ) ;
return type ;
V_176:
F_35 ( V_71 ) ;
V_41:
F_44 ( V_121 ) ;
* V_108 = NULL ;
return V_60 ;
}
static enum V_57
F_83 ( struct V_52 * V_53 , struct V_7 * V_66 , char * * V_108 )
{
struct V_7 * V_71 ;
enum V_57 type ;
char * V_121 = NULL ;
memset ( V_66 , 0 , sizeof( * V_66 ) ) ;
V_66 -> type = V_76 ;
V_71 = F_6 () ;
if ( ! V_71 ) {
F_64 ( V_53 , L_46 , V_136 ) ;
goto V_41;
}
type = F_68 ( V_53 , V_71 , & V_121 ) ;
if ( F_51 ( type , V_121 , V_61 , L_83 ) )
goto V_176;
V_66 -> V_77 . V_71 = V_71 ;
type = F_81 ( V_53 , & V_66 -> V_77 . V_78 , & V_121 ) ;
if ( F_51 ( type , V_121 , V_61 , L_70 ) )
goto V_41;
F_44 ( V_121 ) ;
type = F_48 ( V_108 ) ;
return type ;
V_176:
F_35 ( V_71 ) ;
V_41:
F_44 ( V_121 ) ;
* V_108 = NULL ;
return V_60 ;
}
static enum V_57
F_84 ( struct V_52 * V_53 , struct V_7 * V_66 ,
char * * V_108 , enum V_177 type )
{
memset ( V_66 , 0 , sizeof( * V_66 ) ) ;
V_66 -> type = type ;
if ( F_76 ( V_53 , L_83 , & V_66 -> V_81 . V_71 ) )
goto V_116;
if ( F_76 ( V_53 , L_70 , & V_66 -> V_81 . V_2 ) )
goto V_178;
return F_48 ( V_108 ) ;
V_178:
F_35 ( V_66 -> V_81 . V_71 ) ;
V_66 -> V_81 . V_71 = NULL ;
V_116:
* V_108 = NULL ;
return V_60 ;
}
static enum V_57
F_85 ( struct V_52 * V_53 , struct V_7 * V_66 , char * * V_108 )
{
return F_84 ( V_53 , V_66 , V_108 , V_79 ) ;
}
static enum V_57
F_86 ( struct V_52 * V_53 , struct V_7 * V_66 ,
char * * V_108 )
{
return F_84 ( V_53 , V_66 , V_108 , V_80 ) ;
}
static enum V_57
F_87 ( struct V_52 * V_53 , struct V_7 * V_66 , char * * V_108 )
{
memset ( V_66 , 0 , sizeof( * V_66 ) ) ;
V_66 -> type = V_82 ;
if ( F_76 ( V_53 , L_83 , & V_66 -> V_83 . V_71 ) )
goto V_116;
if ( F_76 ( V_53 , L_83 , & V_66 -> V_83 . V_84 ) )
goto V_178;
if ( F_76 ( V_53 , L_70 , & V_66 -> V_83 . V_85 ) )
goto V_179;
return F_48 ( V_108 ) ;
V_179:
F_35 ( V_66 -> V_83 . V_84 ) ;
V_66 -> V_83 . V_84 = NULL ;
V_178:
F_35 ( V_66 -> V_83 . V_71 ) ;
V_66 -> V_83 . V_71 = NULL ;
V_116:
* V_108 = NULL ;
return V_60 ;
}
static enum V_57
F_88 ( struct V_52 * V_53 , struct V_7 * V_66 , char * * V_108 )
{
struct V_127 * V_71 ;
enum V_57 type ;
char * V_121 ;
memset ( V_66 , 0 , sizeof( * V_66 ) ) ;
V_66 -> type = V_92 ;
type = F_45 ( & V_121 ) ;
* V_108 = V_121 ;
if ( type != V_58 )
goto V_41;
V_71 = F_89 ( V_53 , V_121 ) ;
if ( ! V_71 )
goto V_41;
V_66 -> V_94 . V_71 = V_71 ;
V_66 -> V_94 . V_95 = 0 ;
if ( F_55 ( V_61 , L_70 ) < 0 )
goto V_41;
F_44 ( V_121 ) ;
type = F_48 ( & V_121 ) ;
* V_108 = V_121 ;
if ( type != V_107 || strcmp ( V_121 , L_38 ) != 0 )
return type ;
F_44 ( V_121 ) ;
V_66 = F_6 () ;
if ( ! V_66 ) {
F_64 ( V_53 , L_46 , V_136 ) ;
* V_108 = NULL ;
return V_60 ;
}
type = F_66 ( V_53 , V_66 , & V_121 ) ;
if ( type == V_60 )
goto V_180;
if ( ! F_51 ( type , V_121 , V_107 , L_39 ) )
goto V_180;
F_44 ( V_121 ) ;
type = F_48 ( V_108 ) ;
return type ;
V_180:
F_35 ( V_66 ) ;
V_41:
F_44 ( V_121 ) ;
* V_108 = NULL ;
return V_60 ;
}
static enum V_57
F_90 ( struct V_52 * V_53 , struct V_7 * V_66 ,
char * * V_108 )
{
struct V_127 * V_71 ;
enum V_57 type ;
char * V_121 ;
if ( F_53 ( V_58 , & V_121 ) < 0 )
goto V_41;
V_66 -> type = V_93 ;
V_71 = F_89 ( V_53 , V_121 ) ;
if ( ! V_71 )
goto V_41;
V_66 -> V_94 . V_71 = V_71 ;
V_66 -> V_94 . V_95 = 0 ;
if ( F_55 ( V_61 , L_70 ) < 0 )
goto V_163;
type = F_45 ( & V_121 ) ;
* V_108 = V_121 ;
return type ;
V_41:
F_44 ( V_121 ) ;
V_163:
* V_108 = NULL ;
return V_60 ;
}
static enum V_57
F_91 ( struct V_52 * V_53 , struct V_7 * V_66 , char * * V_108 )
{
struct V_7 * V_181 ;
enum V_57 type ;
char * V_121 ;
type = F_66 ( V_53 , V_66 , & V_121 ) ;
if ( type == V_60 )
goto V_41;
if ( type == V_107 )
type = F_69 ( V_53 , V_66 , & V_121 ) ;
if ( type == V_60 )
goto V_41;
if ( F_51 ( type , V_121 , V_61 , L_70 ) )
goto V_41;
F_44 ( V_121 ) ;
type = F_48 ( & V_121 ) ;
if ( F_33 ( type ) ||
( type == V_61 && strcmp ( V_121 , L_85 ) == 0 ) ) {
if ( V_66 -> type != V_68 ) {
F_64 ( V_53 , L_86 ) ;
goto V_41;
}
V_181 = F_6 () ;
if ( ! V_181 ) {
F_64 ( V_53 , L_46 ,
V_136 ) ;
goto V_41;
}
V_66 -> type = V_86 ;
V_66 -> V_87 . type = V_66 -> V_69 . V_69 ;
V_66 -> V_87 . V_17 = V_181 ;
type = F_67 ( V_53 , V_181 , & V_121 , type ) ;
}
* V_108 = V_121 ;
return type ;
V_41:
F_44 ( V_121 ) ;
* V_108 = NULL ;
return V_60 ;
}
static enum V_57
F_92 ( struct V_52 * V_53 V_162 , struct V_7 * V_66 ,
char * * V_108 )
{
enum V_57 type ;
char * V_121 ;
if ( F_53 ( V_58 , & V_121 ) < 0 )
goto V_41;
V_66 -> type = V_88 ;
V_66 -> string . string = V_121 ;
V_66 -> string . V_147 = - 1 ;
if ( F_55 ( V_61 , L_70 ) < 0 )
goto V_163;
type = F_45 ( & V_121 ) ;
* V_108 = V_121 ;
return type ;
V_41:
F_44 ( V_121 ) ;
V_163:
* V_108 = NULL ;
return V_60 ;
}
static enum V_57
F_93 ( struct V_52 * V_53 V_162 , struct V_7 * V_66 ,
char * * V_108 )
{
enum V_57 type ;
char * V_121 ;
if ( F_53 ( V_58 , & V_121 ) < 0 )
goto V_41;
V_66 -> type = V_90 ;
V_66 -> V_91 . V_91 = V_121 ;
V_66 -> V_91 . V_147 = - 1 ;
if ( F_55 ( V_61 , L_70 ) < 0 )
goto V_163;
type = F_45 ( & V_121 ) ;
* V_108 = V_121 ;
return type ;
V_41:
F_44 ( V_121 ) ;
V_163:
* V_108 = NULL ;
return V_60 ;
}
static struct V_182 *
F_94 ( struct V_14 * V_14 , char * V_183 )
{
struct V_182 * V_35 ;
if ( ! V_14 )
return NULL ;
for ( V_35 = V_14 -> V_184 ; V_35 ; V_35 = V_35 -> V_22 ) {
if ( strcmp ( V_35 -> V_72 , V_183 ) == 0 )
break;
}
return V_35 ;
}
static void F_95 ( struct V_14 * V_14 , char * V_183 )
{
struct V_182 * V_35 ;
struct V_182 * * V_22 ;
V_22 = & V_14 -> V_184 ;
while ( ( V_35 = * V_22 ) ) {
if ( strcmp ( V_35 -> V_72 , V_183 ) == 0 ) {
* V_22 = V_35 -> V_22 ;
F_96 ( V_35 ) ;
break;
}
V_22 = & V_35 -> V_22 ;
}
}
static enum V_57
F_97 ( struct V_52 * V_53 , struct V_182 * V_35 ,
struct V_7 * V_66 , char * * V_108 )
{
struct V_7 * * V_185 ;
struct V_7 * V_67 ;
enum V_57 type ;
char * V_121 ;
int V_19 ;
V_66 -> type = V_100 ;
V_66 -> V_35 . V_35 = V_35 ;
* V_108 = NULL ;
V_185 = & ( V_66 -> V_35 . args ) ;
for ( V_19 = 0 ; V_19 < V_35 -> V_186 ; V_19 ++ ) {
V_67 = F_6 () ;
if ( ! V_67 ) {
F_64 ( V_53 , L_46 ,
V_136 ) ;
return V_60 ;
}
type = F_66 ( V_53 , V_67 , & V_121 ) ;
if ( V_19 < ( V_35 -> V_186 - 1 ) ) {
if ( type != V_61 || strcmp ( V_121 , L_83 ) != 0 ) {
F_64 ( V_53 ,
L_87 ,
V_35 -> V_72 , V_35 -> V_186 ,
V_53 -> V_72 , V_19 + 1 ) ;
goto V_187;
}
} else {
if ( type != V_61 || strcmp ( V_121 , L_70 ) != 0 ) {
F_64 ( V_53 ,
L_88 ,
V_35 -> V_72 , V_35 -> V_186 , V_53 -> V_72 ) ;
goto V_187;
}
}
* V_185 = V_67 ;
V_185 = & ( V_67 -> V_22 ) ;
F_44 ( V_121 ) ;
}
type = F_45 ( & V_121 ) ;
* V_108 = V_121 ;
return type ;
V_187:
F_35 ( V_67 ) ;
F_44 ( V_121 ) ;
return V_60 ;
}
static enum V_57
F_98 ( struct V_52 * V_53 , struct V_7 * V_66 ,
char * V_121 , char * * V_108 )
{
struct V_182 * V_35 ;
if ( strcmp ( V_121 , L_89 ) == 0 ) {
F_44 ( V_121 ) ;
V_164 = 1 ;
return F_82 ( V_53 , V_66 , V_108 ) ;
}
if ( strcmp ( V_121 , L_90 ) == 0 ) {
F_44 ( V_121 ) ;
V_166 = 1 ;
return F_83 ( V_53 , V_66 , V_108 ) ;
}
if ( strcmp ( V_121 , L_91 ) == 0 ) {
F_44 ( V_121 ) ;
return F_85 ( V_53 , V_66 , V_108 ) ;
}
if ( strcmp ( V_121 , L_92 ) == 0 ) {
F_44 ( V_121 ) ;
return F_86 ( V_53 , V_66 , V_108 ) ;
}
if ( strcmp ( V_121 , L_93 ) == 0 ) {
F_44 ( V_121 ) ;
return F_87 ( V_53 , V_66 , V_108 ) ;
}
if ( strcmp ( V_121 , L_94 ) == 0 ) {
F_44 ( V_121 ) ;
return F_92 ( V_53 , V_66 , V_108 ) ;
}
if ( strcmp ( V_121 , L_95 ) == 0 ) {
F_44 ( V_121 ) ;
return F_93 ( V_53 , V_66 , V_108 ) ;
}
if ( strcmp ( V_121 , L_96 ) == 0 ) {
F_44 ( V_121 ) ;
return F_88 ( V_53 , V_66 , V_108 ) ;
}
if ( strcmp ( V_121 , L_97 ) == 0 ) {
F_44 ( V_121 ) ;
return F_90 ( V_53 , V_66 , V_108 ) ;
}
V_35 = F_94 ( V_53 -> V_14 , V_121 ) ;
if ( V_35 ) {
F_44 ( V_121 ) ;
return F_97 ( V_53 , V_35 , V_66 , V_108 ) ;
}
F_64 ( V_53 , L_98 , V_121 ) ;
F_44 ( V_121 ) ;
return V_60 ;
}
static enum V_57
F_67 ( struct V_52 * V_53 , struct V_7 * V_66 ,
char * * V_108 , enum V_57 type )
{
char * V_121 ;
char * V_69 ;
V_121 = * V_108 ;
switch ( type ) {
case V_58 :
if ( strcmp ( V_121 , L_99 ) == 0 ) {
F_44 ( V_121 ) ;
type = F_74 ( V_53 , V_66 , & V_121 ) ;
break;
}
V_69 = V_121 ;
type = F_48 ( & V_121 ) ;
if ( type == V_61 && strcmp ( V_121 , L_85 ) == 0 ) {
F_44 ( V_121 ) ;
V_121 = NULL ;
type = F_98 ( V_53 , V_66 , V_69 , & V_121 ) ;
break;
}
while ( type == V_58 ) {
char * V_160 ;
V_160 = realloc ( V_69 ,
strlen ( V_69 ) + strlen ( V_121 ) + 2 ) ;
if ( ! V_160 ) {
free ( V_69 ) ;
* V_108 = NULL ;
F_44 ( V_121 ) ;
return V_60 ;
}
V_69 = V_160 ;
strcat ( V_69 , L_36 ) ;
strcat ( V_69 , V_121 ) ;
F_44 ( V_121 ) ;
type = F_48 ( & V_121 ) ;
}
V_66 -> type = V_68 ;
V_66 -> V_69 . V_69 = V_69 ;
break;
case V_105 :
case V_59 :
V_66 -> type = V_68 ;
V_66 -> V_69 . V_69 = V_121 ;
type = F_48 ( & V_121 ) ;
break;
case V_61 :
if ( strcmp ( V_121 , L_85 ) == 0 ) {
F_44 ( V_121 ) ;
type = F_91 ( V_53 , V_66 , & V_121 ) ;
break;
}
case V_107 :
V_66 -> type = V_96 ;
V_66 -> V_97 . V_97 = V_121 ;
V_66 -> V_97 . V_98 = NULL ;
type = F_69 ( V_53 , V_66 , & V_121 ) ;
if ( type == V_60 )
V_66 -> V_97 . V_97 = NULL ;
break;
case V_60 ... V_103 :
default:
F_64 ( V_53 , L_100 , type ) ;
return V_60 ;
}
* V_108 = V_121 ;
return type ;
}
static int F_99 ( struct V_52 * V_53 , struct V_7 * * V_175 )
{
enum V_57 type = V_60 ;
struct V_7 * V_66 ;
char * V_121 ;
int args = 0 ;
do {
if ( type == V_103 ) {
type = F_48 ( & V_121 ) ;
continue;
}
V_66 = F_6 () ;
if ( ! V_66 ) {
F_64 ( V_53 , L_46 ,
V_136 ) ;
return - 1 ;
}
type = F_66 ( V_53 , V_66 , & V_121 ) ;
if ( type == V_60 ) {
F_44 ( V_121 ) ;
F_35 ( V_66 ) ;
return - 1 ;
}
* V_175 = V_66 ;
args ++ ;
if ( type == V_107 ) {
type = F_69 ( V_53 , V_66 , & V_121 ) ;
F_44 ( V_121 ) ;
if ( type == V_60 ) {
* V_175 = NULL ;
F_35 ( V_66 ) ;
return - 1 ;
}
V_175 = & V_66 -> V_22 ;
continue;
}
if ( type == V_61 && strcmp ( V_121 , L_83 ) == 0 ) {
F_44 ( V_121 ) ;
* V_175 = V_66 ;
V_175 = & V_66 -> V_22 ;
continue;
}
break;
} while ( type != V_106 );
if ( type != V_106 && type != V_60 )
F_44 ( V_121 ) ;
return args ;
}
static int F_100 ( struct V_52 * V_53 )
{
enum V_57 type ;
char * V_121 ;
int V_125 ;
if ( F_56 ( V_58 , L_101 ) < 0 )
return - 1 ;
if ( F_55 ( V_58 , L_102 ) < 0 )
return - 1 ;
if ( F_55 ( V_107 , L_19 ) < 0 )
return - 1 ;
if ( F_53 ( V_105 , & V_121 ) < 0 )
goto V_126;
V_117:
V_53 -> V_188 . V_151 = V_121 ;
V_53 -> V_188 . args = NULL ;
type = F_48 ( & V_121 ) ;
if ( type == V_106 )
return 0 ;
if ( type == V_105 ) {
char * V_189 ;
if ( F_42 ( & V_189 , L_103 , V_53 -> V_188 . V_151 , V_121 ) < 0 )
goto V_126;
F_44 ( V_121 ) ;
F_44 ( V_53 -> V_188 . V_151 ) ;
V_53 -> V_188 . V_151 = NULL ;
V_121 = V_189 ;
goto V_117;
}
if ( F_51 ( type , V_121 , V_61 , L_83 ) )
goto V_126;
F_44 ( V_121 ) ;
V_125 = F_99 ( V_53 , & V_53 -> V_188 . args ) ;
if ( V_125 < 0 )
return - 1 ;
return V_125 ;
V_126:
F_44 ( V_121 ) ;
return - 1 ;
}
struct V_127 *
F_101 ( struct V_52 * V_53 , const char * V_72 )
{
struct V_127 * V_151 ;
for ( V_151 = V_53 -> V_151 . V_152 ;
V_151 ; V_151 = V_151 -> V_22 ) {
if ( strcmp ( V_151 -> V_72 , V_72 ) == 0 )
break;
}
return V_151 ;
}
struct V_127 *
F_89 ( struct V_52 * V_53 , const char * V_72 )
{
struct V_127 * V_151 ;
for ( V_151 = V_53 -> V_151 . V_130 ;
V_151 ; V_151 = V_151 -> V_22 ) {
if ( strcmp ( V_151 -> V_72 , V_72 ) == 0 )
break;
}
return V_151 ;
}
struct V_127 *
F_75 ( struct V_52 * V_53 , const char * V_72 )
{
struct V_127 * V_151 ;
V_151 = F_101 ( V_53 , V_72 ) ;
if ( V_151 )
return V_151 ;
return F_89 ( V_53 , V_72 ) ;
}
unsigned long long F_102 ( struct V_14 * V_14 ,
const void * V_190 , int V_2 )
{
switch ( V_2 ) {
case 1 :
return * ( unsigned char * ) V_190 ;
case 2 :
return F_103 ( V_14 , V_190 ) ;
case 4 :
return F_104 ( V_14 , V_190 ) ;
case 8 :
return F_105 ( V_14 , V_190 ) ;
default:
return 0 ;
}
}
int F_106 ( struct V_127 * V_71 , const void * V_191 ,
unsigned long long * V_64 )
{
if ( ! V_71 )
return - 1 ;
switch ( V_71 -> V_2 ) {
case 1 :
case 2 :
case 4 :
case 8 :
* V_64 = F_102 ( V_71 -> V_53 -> V_14 ,
V_191 + V_71 -> V_147 , V_71 -> V_2 ) ;
return 0 ;
default:
return - 1 ;
}
}
static int F_107 ( struct V_14 * V_14 ,
const char * type , int * V_147 , int * V_2 )
{
struct V_52 * V_53 ;
struct V_127 * V_71 ;
if ( ! V_14 -> V_54 ) {
F_50 ( L_104 ) ;
return - 1 ;
}
V_53 = V_14 -> V_54 [ 0 ] ;
V_71 = F_101 ( V_53 , type ) ;
if ( ! V_71 )
return - 1 ;
* V_147 = V_71 -> V_147 ;
* V_2 = V_71 -> V_2 ;
return 0 ;
}
static int F_108 ( struct V_14 * V_14 , void * V_191 ,
int * V_2 , int * V_147 , const char * V_72 )
{
int V_125 ;
if ( ! * V_2 ) {
V_125 = F_107 ( V_14 , V_72 , V_147 , V_2 ) ;
if ( V_125 < 0 )
return V_125 ;
}
return F_102 ( V_14 , V_191 + * V_147 , * V_2 ) ;
}
static int F_109 ( struct V_14 * V_14 , void * V_191 )
{
return F_108 ( V_14 , V_191 ,
& V_14 -> F_62 , & V_14 -> V_192 ,
L_105 ) ;
}
static int F_110 ( struct V_14 * V_14 , void * V_191 )
{
return F_108 ( V_14 , V_191 ,
& V_14 -> V_193 , & V_14 -> V_194 ,
L_106 ) ;
}
static int F_111 ( struct V_14 * V_14 , void * V_191 )
{
return F_108 ( V_14 , V_191 ,
& V_14 -> V_195 , & V_14 -> V_196 ,
L_107 ) ;
}
static int F_112 ( struct V_14 * V_14 , void * V_191 )
{
return F_108 ( V_14 , V_191 ,
& V_14 -> V_197 , & V_14 -> V_198 ,
L_108 ) ;
}
static int F_113 ( struct V_14 * V_14 , void * V_191 )
{
return F_108 ( V_14 , V_191 ,
& V_14 -> V_199 , & V_14 -> V_200 ,
L_109 ) ;
}
static int F_114 ( struct V_14 * V_14 , void * V_191 )
{
return F_108 ( V_14 , V_191 ,
& V_14 -> V_199 , & V_14 -> V_200 ,
L_110 ) ;
}
struct V_52 * F_115 ( struct V_14 * V_14 , int V_56 )
{
struct V_52 * * V_201 ;
struct V_52 V_23 ;
struct V_52 * V_202 = & V_23 ;
if ( V_14 -> V_203 && V_14 -> V_203 -> V_56 == V_56 )
return V_14 -> V_203 ;
V_23 . V_56 = V_56 ;
V_201 = bsearch ( & V_202 , V_14 -> V_54 , V_14 -> V_55 ,
sizeof( * V_14 -> V_54 ) , V_204 ) ;
if ( V_201 ) {
V_14 -> V_203 = * V_201 ;
return * V_201 ;
}
return NULL ;
}
struct V_52 *
F_116 ( struct V_14 * V_14 ,
const char * V_205 , const char * V_72 )
{
struct V_52 * V_53 ;
int V_19 ;
if ( V_14 -> V_203 &&
strcmp ( V_14 -> V_203 -> V_72 , V_72 ) == 0 &&
( ! V_205 || strcmp ( V_14 -> V_203 -> system , V_205 ) == 0 ) )
return V_14 -> V_203 ;
for ( V_19 = 0 ; V_19 < V_14 -> V_55 ; V_19 ++ ) {
V_53 = V_14 -> V_54 [ V_19 ] ;
if ( strcmp ( V_53 -> V_72 , V_72 ) == 0 ) {
if ( ! V_205 )
break;
if ( strcmp ( V_53 -> system , V_205 ) == 0 )
break;
}
}
if ( V_19 == V_14 -> V_55 )
V_53 = NULL ;
V_14 -> V_203 = V_53 ;
return V_53 ;
}
static unsigned long long
F_117 ( void * V_191 , int V_2 , struct V_52 * V_53 , struct V_7 * V_66 )
{
struct V_14 * V_14 = V_53 -> V_14 ;
unsigned long long V_171 = 0 ;
unsigned long long V_98 , V_99 ;
struct V_7 * V_206 = NULL ;
struct V_7 * V_207 ;
unsigned long V_147 ;
unsigned int V_208 ;
switch ( V_66 -> type ) {
case V_101 :
return 0 ;
case V_68 :
return F_118 ( V_66 -> V_69 . V_69 , NULL , 0 ) ;
case V_70 :
if ( ! V_66 -> V_71 . V_71 ) {
V_66 -> V_71 . V_71 = F_75 ( V_53 , V_66 -> V_71 . V_72 ) ;
if ( ! V_66 -> V_71 . V_71 )
goto V_209;
}
V_171 = F_102 ( V_14 , V_191 + V_66 -> V_71 . V_71 -> V_147 ,
V_66 -> V_71 . V_71 -> V_2 ) ;
break;
case V_73 :
case V_76 :
case V_82 :
case V_79 :
case V_80 :
break;
case V_86 :
V_171 = F_117 ( V_191 , V_2 , V_53 , V_66 -> V_87 . V_17 ) ;
return F_78 ( V_171 , V_66 , 0 ) ;
case V_88 :
case V_89 :
case V_90 :
return 0 ;
case V_100 : {
struct V_210 V_211 ;
F_119 ( & V_211 ) ;
V_171 = F_120 ( & V_211 , V_191 , V_2 , V_53 , V_66 ) ;
F_121 ( & V_211 ) ;
return V_171 ;
}
case V_96 :
if ( strcmp ( V_66 -> V_97 . V_97 , L_38 ) == 0 ) {
V_99 = F_117 ( V_191 , V_2 , V_53 , V_66 -> V_97 . V_99 ) ;
V_207 = V_66 -> V_97 . V_98 ;
while ( V_207 -> type == V_86 ) {
if ( ! V_206 )
V_206 = V_207 ;
V_207 = V_207 -> V_87 . V_17 ;
}
V_208 = V_14 -> V_150 ;
switch ( V_207 -> type ) {
case V_92 :
V_147 = F_102 ( V_14 ,
V_191 + V_207 -> V_94 . V_71 -> V_147 ,
V_207 -> V_94 . V_71 -> V_2 ) ;
if ( V_207 -> V_94 . V_71 -> V_149 )
V_208 = V_207 -> V_94 . V_71 -> V_149 ;
V_147 &= 0xffff ;
V_147 += V_99 ;
break;
case V_70 :
if ( ! V_207 -> V_71 . V_71 ) {
V_207 -> V_71 . V_71 =
F_75 ( V_53 , V_207 -> V_71 . V_72 ) ;
if ( ! V_207 -> V_71 . V_71 ) {
V_66 = V_207 ;
goto V_209;
}
}
V_208 = V_207 -> V_71 . V_71 -> V_149 ;
V_147 = V_207 -> V_71 . V_71 -> V_147 +
V_99 * V_207 -> V_71 . V_71 -> V_149 ;
break;
default:
goto V_212;
}
V_171 = F_102 ( V_14 ,
V_191 + V_147 , V_208 ) ;
if ( V_206 )
V_171 = F_78 ( V_171 , V_206 , 1 ) ;
break;
} else if ( strcmp ( V_66 -> V_97 . V_97 , L_60 ) == 0 ) {
V_98 = F_117 ( V_191 , V_2 , V_53 , V_66 -> V_97 . V_98 ) ;
V_66 = V_66 -> V_97 . V_99 ;
if ( V_98 )
V_171 = F_117 ( V_191 , V_2 , V_53 , V_66 -> V_97 . V_98 ) ;
else
V_171 = F_117 ( V_191 , V_2 , V_53 , V_66 -> V_97 . V_99 ) ;
break;
}
V_212:
V_98 = F_117 ( V_191 , V_2 , V_53 , V_66 -> V_97 . V_98 ) ;
V_99 = F_117 ( V_191 , V_2 , V_53 , V_66 -> V_97 . V_99 ) ;
switch ( V_66 -> V_97 . V_97 [ 0 ] ) {
case '!' :
switch ( V_66 -> V_97 . V_97 [ 1 ] ) {
case 0 :
V_171 = ! V_99 ;
break;
case '=' :
V_171 = V_98 != V_99 ;
break;
default:
goto V_213;
}
break;
case '~' :
V_171 = ~ V_99 ;
break;
case '|' :
if ( V_66 -> V_97 . V_97 [ 1 ] )
V_171 = V_98 || V_99 ;
else
V_171 = V_98 | V_99 ;
break;
case '&' :
if ( V_66 -> V_97 . V_97 [ 1 ] )
V_171 = V_98 && V_99 ;
else
V_171 = V_98 & V_99 ;
break;
case '<' :
switch ( V_66 -> V_97 . V_97 [ 1 ] ) {
case 0 :
V_171 = V_98 < V_99 ;
break;
case '<' :
V_171 = V_98 << V_99 ;
break;
case '=' :
V_171 = V_98 <= V_99 ;
break;
default:
goto V_213;
}
break;
case '>' :
switch ( V_66 -> V_97 . V_97 [ 1 ] ) {
case 0 :
V_171 = V_98 > V_99 ;
break;
case '>' :
V_171 = V_98 >> V_99 ;
break;
case '=' :
V_171 = V_98 >= V_99 ;
break;
default:
goto V_213;
}
break;
case '=' :
if ( V_66 -> V_97 . V_97 [ 1 ] != '=' )
goto V_213;
V_171 = V_98 == V_99 ;
break;
case '-' :
V_171 = V_98 - V_99 ;
break;
case '+' :
V_171 = V_98 + V_99 ;
break;
case '/' :
V_171 = V_98 / V_99 ;
break;
case '%' :
V_171 = V_98 % V_99 ;
break;
case '*' :
V_171 = V_98 * V_99 ;
break;
default:
goto V_213;
}
break;
case V_93 :
V_147 = F_102 ( V_14 ,
V_191 + V_66 -> V_94 . V_71 -> V_147 ,
V_66 -> V_94 . V_71 -> V_2 ) ;
V_171 = ( unsigned long long ) ( V_147 >> 16 ) ;
break;
case V_92 :
V_147 = F_102 ( V_14 ,
V_191 + V_66 -> V_94 . V_71 -> V_147 ,
V_66 -> V_94 . V_71 -> V_2 ) ;
V_147 &= 0xffff ;
V_171 = ( unsigned long long ) ( ( unsigned long ) V_191 + V_147 ) ;
break;
default:
return 0 ;
}
return V_171 ;
V_213:
F_64 ( V_53 , L_111 , V_136 , V_66 -> V_97 . V_97 ) ;
return 0 ;
V_209:
F_64 ( V_53 , L_112 ,
V_136 , V_66 -> V_71 . V_72 ) ;
return 0 ;
}
static long long F_122 ( const char * V_214 )
{
int V_19 ;
if ( isdigit ( V_214 [ 0 ] ) )
return F_118 ( V_214 , NULL , 0 ) ;
for ( V_19 = 0 ; V_19 < ( int ) ( sizeof( V_74 ) / sizeof( V_74 [ 0 ] ) ) ; V_19 ++ )
if ( strcmp ( V_74 [ V_19 ] . V_72 , V_214 ) == 0 )
return V_74 [ V_19 ] . V_64 ;
return - 1LL ;
}
static void F_123 ( struct V_210 * V_211 , const char * V_151 ,
int V_215 , const char * V_65 )
{
if ( V_215 >= 0 )
F_124 ( V_211 , V_151 , V_215 , V_65 ) ;
else
F_124 ( V_211 , V_151 , V_65 ) ;
}
static void F_125 ( struct V_14 * V_14 ,
struct V_210 * V_211 , const char * V_151 ,
int V_215 , const void * V_191 , int V_2 )
{
int V_216 = V_2 * 8 ;
int V_217 = ( V_216 + 3 ) / 4 ;
int V_141 = 0 ;
char V_1 [ 3 ] ;
char * V_65 ;
int V_95 ;
int V_19 ;
V_217 += ( V_216 - 1 ) / 32 ;
V_65 = malloc ( V_217 + 1 ) ;
if ( ! V_65 ) {
F_50 ( L_46 , V_136 ) ;
return;
}
V_65 [ V_217 ] = 0 ;
for ( V_19 = V_217 - 2 ; V_19 >= 0 ; V_19 -= 2 ) {
if ( V_14 -> V_218 )
V_95 = V_2 - ( V_141 + 1 ) ;
else
V_95 = V_141 ;
snprintf ( V_1 , 3 , L_113 , * ( ( unsigned char * ) V_191 + V_95 ) ) ;
memcpy ( V_65 + V_19 , V_1 , 2 ) ;
V_141 ++ ;
if ( ! ( V_141 & 3 ) && V_19 > 0 ) {
V_19 -- ;
V_65 [ V_19 ] = ',' ;
}
}
if ( V_215 >= 0 )
F_124 ( V_211 , V_151 , V_215 , V_65 ) ;
else
F_124 ( V_211 , V_151 , V_65 ) ;
free ( V_65 ) ;
}
static void F_126 ( struct V_210 * V_211 , void * V_191 , int V_2 ,
struct V_52 * V_53 , const char * V_151 ,
int V_215 , struct V_7 * V_66 )
{
struct V_14 * V_14 = V_53 -> V_14 ;
struct V_62 * V_214 ;
struct V_127 * V_71 ;
struct V_43 * V_49 ;
long long V_171 , V_219 ;
unsigned long long V_31 ;
char * V_65 ;
unsigned char * V_81 ;
int V_220 ;
int V_19 , V_141 ;
switch ( V_66 -> type ) {
case V_101 :
return;
case V_68 :
F_123 ( V_211 , V_151 , V_215 , V_66 -> V_69 . V_69 ) ;
return;
case V_70 :
V_71 = V_66 -> V_71 . V_71 ;
if ( ! V_71 ) {
V_71 = F_75 ( V_53 , V_66 -> V_71 . V_72 ) ;
if ( ! V_71 ) {
V_65 = V_66 -> V_71 . V_72 ;
goto V_209;
}
V_66 -> V_71 . V_71 = V_71 ;
}
V_141 = V_71 -> V_2 ? : V_2 - V_71 -> V_147 ;
if ( ! ( V_71 -> V_74 & V_128 ) &&
V_71 -> V_2 == V_14 -> V_150 ) {
V_31 = ( V_14 -> V_150 == 8 ) ?
* ( unsigned long long * ) ( V_191 + V_71 -> V_147 ) :
( unsigned long long ) * ( unsigned int * ) ( V_191 + V_71 -> V_147 ) ;
V_49 = F_28 ( V_14 , V_31 ) ;
if ( V_49 )
F_127 ( V_211 , V_49 -> V_49 ) ;
else
F_124 ( V_211 , L_114 , V_31 ) ;
break;
}
V_65 = malloc ( V_141 + 1 ) ;
if ( ! V_65 ) {
F_64 ( V_53 , L_46 ,
V_136 ) ;
return;
}
memcpy ( V_65 , V_191 + V_71 -> V_147 , V_141 ) ;
V_65 [ V_141 ] = 0 ;
F_123 ( V_211 , V_151 , V_215 , V_65 ) ;
free ( V_65 ) ;
break;
case V_73 :
V_171 = F_117 ( V_191 , V_2 , V_53 , V_66 -> V_74 . V_71 ) ;
V_220 = 0 ;
for ( V_214 = V_66 -> V_74 . V_74 ; V_214 ; V_214 = V_214 -> V_22 ) {
V_219 = F_122 ( V_214 -> V_64 ) ;
if ( ! V_171 && V_219 < 0 ) {
F_123 ( V_211 , V_151 , V_215 , V_214 -> V_65 ) ;
break;
}
if ( V_219 > 0 && ( V_171 & V_219 ) == V_219 ) {
if ( V_220 && V_66 -> V_74 . V_75 )
F_127 ( V_211 , V_66 -> V_74 . V_75 ) ;
F_123 ( V_211 , V_151 , V_215 , V_214 -> V_65 ) ;
V_220 = 1 ;
V_171 &= ~ V_219 ;
}
}
break;
case V_76 :
V_171 = F_117 ( V_191 , V_2 , V_53 , V_66 -> V_77 . V_71 ) ;
for ( V_214 = V_66 -> V_77 . V_78 ; V_214 ; V_214 = V_214 -> V_22 ) {
V_219 = F_122 ( V_214 -> V_64 ) ;
if ( V_171 == V_219 ) {
F_123 ( V_211 , V_151 , V_215 , V_214 -> V_65 ) ;
break;
}
}
break;
case V_79 :
case V_80 :
if ( V_66 -> V_81 . V_71 -> type == V_92 ) {
unsigned long V_147 ;
V_147 = F_102 ( V_14 ,
V_191 + V_66 -> V_81 . V_71 -> V_94 . V_71 -> V_147 ,
V_66 -> V_81 . V_71 -> V_94 . V_71 -> V_2 ) ;
V_81 = V_191 + ( V_147 & 0xffff ) ;
} else {
V_71 = V_66 -> V_81 . V_71 -> V_71 . V_71 ;
if ( ! V_71 ) {
V_65 = V_66 -> V_81 . V_71 -> V_71 . V_72 ;
V_71 = F_75 ( V_53 , V_65 ) ;
if ( ! V_71 )
goto V_209;
V_66 -> V_81 . V_71 -> V_71 . V_71 = V_71 ;
}
V_81 = V_191 + V_71 -> V_147 ;
}
V_141 = F_117 ( V_191 , V_2 , V_53 , V_66 -> V_81 . V_2 ) ;
for ( V_19 = 0 ; V_19 < V_141 ; V_19 ++ ) {
if ( V_19 && V_66 -> type == V_79 )
F_128 ( V_211 , ' ' ) ;
F_124 ( V_211 , L_113 , V_81 [ V_19 ] ) ;
}
break;
case V_82 : {
void * V_221 ;
int V_85 ;
if ( V_66 -> V_83 . V_71 -> type == V_92 ) {
unsigned long V_147 ;
struct V_127 * V_71 =
V_66 -> V_83 . V_71 -> V_94 . V_71 ;
V_147 = F_102 ( V_14 ,
V_191 + V_71 -> V_147 ,
V_71 -> V_2 ) ;
V_221 = V_191 + ( V_147 & 0xffff ) ;
} else {
V_71 = V_66 -> V_83 . V_71 -> V_71 . V_71 ;
if ( ! V_71 ) {
V_65 = V_66 -> V_83 . V_71 -> V_71 . V_72 ;
V_71 = F_75 ( V_53 , V_65 ) ;
if ( ! V_71 )
goto V_209;
V_66 -> V_83 . V_71 -> V_71 . V_71 = V_71 ;
}
V_221 = V_191 + V_71 -> V_147 ;
}
V_141 = F_117 ( V_191 , V_2 , V_53 , V_66 -> V_83 . V_84 ) ;
V_85 = F_117 ( V_191 , V_2 , V_53 ,
V_66 -> V_83 . V_85 ) ;
for ( V_19 = 0 ; V_19 < V_141 ; V_19 ++ ) {
if ( V_19 )
F_128 ( V_211 , ' ' ) ;
if ( V_85 == 1 ) {
F_124 ( V_211 , L_115 , * ( V_222 * ) V_221 ) ;
} else if ( V_85 == 2 ) {
F_124 ( V_211 , L_115 , * ( V_223 * ) V_221 ) ;
} else if ( V_85 == 4 ) {
F_124 ( V_211 , L_115 , * ( V_224 * ) V_221 ) ;
} else if ( V_85 == 8 ) {
F_124 ( V_211 , L_67 V_225 , * ( V_226 * ) V_221 ) ;
} else {
F_124 ( V_211 , L_116 ,
V_85 , * ( V_222 * ) V_221 ) ;
V_85 = 1 ;
}
V_221 += V_85 ;
}
break;
}
case V_86 :
break;
case V_88 : {
int V_227 ;
if ( V_66 -> string . V_147 == - 1 ) {
struct V_127 * V_228 ;
V_228 = F_75 ( V_53 , V_66 -> string . string ) ;
V_66 -> string . V_147 = V_228 -> V_147 ;
}
V_227 = F_104 ( V_14 , V_191 + V_66 -> string . V_147 ) ;
V_227 &= 0xffff ;
F_123 ( V_211 , V_151 , V_215 , ( ( char * ) V_191 ) + V_227 ) ;
break;
}
case V_89 :
F_123 ( V_211 , V_151 , V_215 , V_66 -> string . string ) ;
break;
case V_90 : {
int V_229 ;
int V_230 ;
if ( V_66 -> V_91 . V_147 == - 1 ) {
struct V_127 * V_228 ;
V_228 = F_75 ( V_53 , V_66 -> V_91 . V_91 ) ;
V_66 -> V_91 . V_147 = V_228 -> V_147 ;
}
V_229 = F_104 ( V_14 , V_191 + V_66 -> V_91 . V_147 ) ;
V_230 = V_229 >> 16 ;
V_229 &= 0xffff ;
F_125 ( V_14 , V_211 , V_151 , V_215 ,
V_191 + V_229 , V_230 ) ;
break;
}
case V_96 :
if ( V_66 -> V_97 . V_97 [ 0 ] != '?' )
return;
V_171 = F_117 ( V_191 , V_2 , V_53 , V_66 -> V_97 . V_98 ) ;
if ( V_171 )
F_126 ( V_211 , V_191 , V_2 , V_53 ,
V_151 , V_215 , V_66 -> V_97 . V_99 -> V_97 . V_98 ) ;
else
F_126 ( V_211 , V_191 , V_2 , V_53 ,
V_151 , V_215 , V_66 -> V_97 . V_99 -> V_97 . V_99 ) ;
break;
case V_100 :
F_120 ( V_211 , V_191 , V_2 , V_53 , V_66 ) ;
break;
default:
break;
}
return;
V_209:
F_64 ( V_53 , L_112 ,
V_136 , V_66 -> V_71 . V_72 ) ;
}
static unsigned long long
F_120 ( struct V_210 * V_211 , void * V_191 , int V_2 ,
struct V_52 * V_53 , struct V_7 * V_66 )
{
struct V_182 * V_231 = V_66 -> V_35 . V_35 ;
struct V_232 * V_233 ;
unsigned long long * args ;
unsigned long long V_125 ;
struct V_7 * V_67 ;
struct V_210 V_65 ;
struct V_234 {
struct V_234 * V_22 ;
char * V_65 ;
} * V_235 = NULL , * string ;
int V_19 ;
if ( ! V_231 -> V_186 ) {
V_125 = (* V_231 -> V_35 )( V_211 , NULL ) ;
goto V_116;
}
V_67 = V_66 -> V_35 . args ;
V_233 = V_231 -> V_236 ;
V_125 = V_237 ;
args = malloc ( sizeof( * args ) * V_231 -> V_186 ) ;
if ( ! args )
goto V_116;
for ( V_19 = 0 ; V_19 < V_231 -> V_186 ; V_19 ++ ) {
switch ( V_233 -> type ) {
case V_238 :
case V_239 :
case V_240 :
args [ V_19 ] = F_117 ( V_191 , V_2 , V_53 , V_67 ) ;
break;
case V_241 :
F_119 ( & V_65 ) ;
F_126 ( & V_65 , V_191 , V_2 , V_53 , L_117 , - 1 , V_67 ) ;
F_129 ( & V_65 ) ;
string = malloc ( sizeof( * string ) ) ;
if ( ! string ) {
F_64 ( V_53 , L_118 ,
V_136 , __LINE__ ) ;
goto V_41;
}
string -> V_22 = V_235 ;
string -> V_65 = F_12 ( V_65 . V_242 ) ;
if ( ! string -> V_65 ) {
free ( string ) ;
F_64 ( V_53 , L_118 ,
V_136 , __LINE__ ) ;
goto V_41;
}
args [ V_19 ] = ( V_243 ) string -> V_65 ;
V_235 = string ;
F_121 ( & V_65 ) ;
break;
default:
F_64 ( V_53 , L_119 ) ;
goto V_41;
}
V_67 = V_67 -> V_22 ;
V_233 = V_233 -> V_22 ;
}
V_125 = (* V_231 -> V_35 )( V_211 , args ) ;
V_41:
free ( args ) ;
while ( V_235 ) {
string = V_235 ;
V_235 = string -> V_22 ;
free ( string -> V_65 ) ;
free ( string ) ;
}
V_116:
return V_125 ;
}
static void F_130 ( struct V_7 * args )
{
struct V_7 * V_22 ;
while ( args ) {
V_22 = args -> V_22 ;
F_35 ( args ) ;
args = V_22 ;
}
}
static struct V_7 * F_131 ( char * V_50 , void * V_191 , int V_2 , struct V_52 * V_53 )
{
struct V_14 * V_14 = V_53 -> V_14 ;
struct V_127 * V_71 , * V_244 ;
struct V_7 * args , * V_66 , * * V_22 ;
unsigned long long V_245 , V_171 ;
char * V_190 ;
void * V_246 ;
int V_247 ;
V_71 = V_14 -> V_248 ;
V_244 = V_14 -> V_249 ;
if ( ! V_71 ) {
V_71 = F_89 ( V_53 , L_120 ) ;
if ( ! V_71 ) {
F_64 ( V_53 , L_121 ) ;
return NULL ;
}
V_244 = F_89 ( V_53 , L_122 ) ;
if ( ! V_244 ) {
F_64 ( V_53 , L_123 ) ;
return NULL ;
}
V_14 -> V_248 = V_71 ;
V_14 -> V_249 = V_244 ;
}
V_245 = F_102 ( V_14 , V_191 + V_244 -> V_147 , V_244 -> V_2 ) ;
args = F_6 () ;
if ( ! args ) {
F_64 ( V_53 , L_124 ,
V_136 , __LINE__ ) ;
return NULL ;
}
V_66 = args ;
V_66 -> V_22 = NULL ;
V_22 = & V_66 -> V_22 ;
V_66 -> type = V_68 ;
if ( F_42 ( & V_66 -> V_69 . V_69 , L_81 , V_245 ) < 0 )
goto V_41;
for ( V_190 = V_50 + 5 , V_246 = V_191 + V_71 -> V_147 ;
V_246 < V_191 + V_2 && * V_190 ; V_190 ++ ) {
int V_250 = 0 ;
if ( * V_190 == '%' ) {
V_251:
V_190 ++ ;
switch ( * V_190 ) {
case '%' :
break;
case 'l' :
V_250 ++ ;
goto V_251;
case 'L' :
V_250 = 2 ;
goto V_251;
case '0' ... '9' :
goto V_251;
case '.' :
goto V_251;
case 'z' :
case 'Z' :
V_250 = 1 ;
goto V_251;
case 'p' :
V_250 = 1 ;
case 'd' :
case 'u' :
case 'x' :
case 'i' :
switch ( V_250 ) {
case 0 :
V_247 = 4 ;
break;
case 1 :
V_247 = V_14 -> V_150 ;
break;
case 2 :
V_247 = 8 ;
break;
default:
V_247 = V_250 ;
break;
}
case '*' :
if ( * V_190 == '*' )
V_247 = 4 ;
V_246 = ( void * ) ( ( ( unsigned long ) V_246 + 3 ) &
~ 3 ) ;
V_171 = F_102 ( V_14 , V_246 , V_247 ) ;
V_246 += V_247 ;
V_66 = F_6 () ;
if ( ! V_66 ) {
F_64 ( V_53 , L_124 ,
V_136 , __LINE__ ) ;
goto V_41;
}
V_66 -> V_22 = NULL ;
V_66 -> type = V_68 ;
if ( F_42 ( & V_66 -> V_69 . V_69 , L_81 , V_171 ) < 0 ) {
free ( V_66 ) ;
goto V_41;
}
* V_22 = V_66 ;
V_22 = & V_66 -> V_22 ;
if ( * V_190 == '*' )
goto V_251;
break;
case 's' :
V_66 = F_6 () ;
if ( ! V_66 ) {
F_64 ( V_53 , L_124 ,
V_136 , __LINE__ ) ;
goto V_41;
}
V_66 -> V_22 = NULL ;
V_66 -> type = V_89 ;
V_66 -> string . string = F_12 ( V_246 ) ;
if ( ! V_66 -> string . string )
goto V_41;
V_246 += strlen ( V_246 ) + 1 ;
* V_22 = V_66 ;
V_22 = & V_66 -> V_22 ;
default:
break;
}
}
}
return args ;
V_41:
F_130 ( args ) ;
return NULL ;
}
static char *
F_132 ( void * V_191 , int V_2 V_162 ,
struct V_52 * V_53 )
{
struct V_14 * V_14 = V_53 -> V_14 ;
unsigned long long V_31 ;
struct V_127 * V_71 ;
struct V_43 * V_49 ;
char * V_151 ;
V_71 = V_14 -> V_252 ;
if ( ! V_71 ) {
V_71 = F_89 ( V_53 , L_102 ) ;
if ( ! V_71 ) {
F_64 ( V_53 , L_125 ) ;
return NULL ;
}
V_14 -> V_252 = V_71 ;
}
V_31 = F_102 ( V_14 , V_191 + V_71 -> V_147 , V_71 -> V_2 ) ;
V_49 = F_28 ( V_14 , V_31 ) ;
if ( ! V_49 ) {
if ( F_42 ( & V_151 , L_126 , V_31 ) < 0 )
return NULL ;
return V_151 ;
}
if ( F_42 ( & V_151 , L_127 , L_128 , V_49 -> V_49 ) < 0 )
return NULL ;
return V_151 ;
}
static void F_133 ( struct V_210 * V_211 , int V_253 , void * V_191 , int V_2 ,
struct V_52 * V_53 , struct V_7 * V_66 )
{
unsigned char * V_1 ;
const char * V_50 = L_129 ;
if ( V_66 -> type == V_100 ) {
F_120 ( V_211 , V_191 , V_2 , V_53 , V_66 ) ;
return;
}
if ( V_66 -> type != V_70 ) {
F_124 ( V_211 , L_130 ,
V_66 -> type ) ;
return;
}
if ( V_253 == 'm' )
V_50 = L_131 ;
if ( ! V_66 -> V_71 . V_71 ) {
V_66 -> V_71 . V_71 =
F_75 ( V_53 , V_66 -> V_71 . V_72 ) ;
if ( ! V_66 -> V_71 . V_71 ) {
F_64 ( V_53 , L_112 ,
V_136 , V_66 -> V_71 . V_72 ) ;
return;
}
}
if ( V_66 -> V_71 . V_71 -> V_2 != 6 ) {
F_124 ( V_211 , L_132 ) ;
return;
}
V_1 = V_191 + V_66 -> V_71 . V_71 -> V_147 ;
F_124 ( V_211 , V_50 , V_1 [ 0 ] , V_1 [ 1 ] , V_1 [ 2 ] , V_1 [ 3 ] , V_1 [ 4 ] , V_1 [ 5 ] ) ;
}
static void F_134 ( struct V_210 * V_211 , char V_19 , unsigned char * V_1 )
{
const char * V_50 ;
if ( V_19 == 'i' )
V_50 = L_133 ;
else
V_50 = L_134 ;
F_124 ( V_211 , V_50 , V_1 [ 0 ] , V_1 [ 1 ] , V_1 [ 2 ] , V_1 [ 3 ] ) ;
}
static inline bool F_135 ( const struct V_254 * V_8 )
{
return ( ( unsigned long ) ( V_8 -> V_255 [ 0 ] | V_8 -> V_255 [ 1 ] ) |
( unsigned long ) ( V_8 -> V_255 [ 2 ] ^ F_136 ( 0x0000ffff ) ) ) == 0UL ;
}
static inline bool F_137 ( const struct V_254 * V_31 )
{
return ( V_31 -> V_255 [ 2 ] | F_136 ( 0x02000000 ) ) == F_136 ( 0x02005EFE ) ;
}
static void F_138 ( struct V_210 * V_211 , unsigned char * V_31 )
{
int V_19 , V_256 , V_257 ;
unsigned char V_258 [ 8 ] ;
int V_259 = 1 ;
int V_260 = - 1 ;
V_223 V_261 ;
V_222 V_262 , V_263 ;
bool V_264 = false ;
bool V_265 ;
struct V_254 V_266 ;
memcpy ( & V_266 , V_31 , sizeof( struct V_254 ) ) ;
V_265 = F_135 ( & V_266 ) || F_137 ( & V_266 ) ;
memset ( V_258 , 0 , sizeof( V_258 ) ) ;
if ( V_265 )
V_257 = 6 ;
else
V_257 = 8 ;
for ( V_19 = 0 ; V_19 < V_257 ; V_19 ++ ) {
for ( V_256 = V_19 ; V_256 < V_257 ; V_256 ++ ) {
if ( V_266 . V_267 [ V_256 ] != 0 )
break;
V_258 [ V_19 ] ++ ;
}
}
for ( V_19 = 0 ; V_19 < V_257 ; V_19 ++ ) {
if ( V_258 [ V_19 ] > V_259 ) {
V_259 = V_258 [ V_19 ] ;
V_260 = V_19 ;
}
}
if ( V_259 == 1 )
V_260 = - 1 ;
for ( V_19 = 0 ; V_19 < V_257 ; V_19 ++ ) {
if ( V_19 == V_260 ) {
if ( V_264 || V_19 == 0 )
F_124 ( V_211 , L_19 ) ;
F_124 ( V_211 , L_19 ) ;
V_264 = false ;
V_19 += V_259 - 1 ;
continue;
}
if ( V_264 ) {
F_124 ( V_211 , L_19 ) ;
V_264 = false ;
}
V_261 = F_139 ( V_266 . V_267 [ V_19 ] ) ;
V_262 = V_261 >> 8 ;
V_263 = V_261 & 0xff ;
if ( V_262 )
F_124 ( V_211 , L_135 , V_262 , V_263 ) ;
else
F_124 ( V_211 , L_136 , V_263 ) ;
V_264 = true ;
}
if ( V_265 ) {
if ( V_264 )
F_124 ( V_211 , L_19 ) ;
F_134 ( V_211 , 'I' , & V_266 . V_268 [ 12 ] ) ;
}
return;
}
static void F_140 ( struct V_210 * V_211 , char V_19 , unsigned char * V_1 )
{
int V_256 ;
for ( V_256 = 0 ; V_256 < 16 ; V_256 += 2 ) {
F_124 ( V_211 , L_137 , V_1 [ V_256 ] , V_1 [ V_256 + 1 ] ) ;
if ( V_19 == 'I' && V_256 < 14 )
F_124 ( V_211 , L_19 ) ;
}
}
static int F_141 ( struct V_210 * V_211 , const char * V_190 , char V_19 ,
void * V_191 , int V_2 , struct V_52 * V_53 ,
struct V_7 * V_66 )
{
unsigned char * V_1 ;
if ( V_66 -> type == V_100 ) {
F_120 ( V_211 , V_191 , V_2 , V_53 , V_66 ) ;
return 0 ;
}
if ( V_66 -> type != V_70 ) {
F_124 ( V_211 , L_130 , V_66 -> type ) ;
return 0 ;
}
if ( ! V_66 -> V_71 . V_71 ) {
V_66 -> V_71 . V_71 =
F_75 ( V_53 , V_66 -> V_71 . V_72 ) ;
if ( ! V_66 -> V_71 . V_71 ) {
F_50 ( L_112 ,
V_136 , V_66 -> V_71 . V_72 ) ;
return 0 ;
}
}
V_1 = V_191 + V_66 -> V_71 . V_71 -> V_147 ;
if ( V_66 -> V_71 . V_71 -> V_2 != 4 ) {
F_124 ( V_211 , L_138 ) ;
return 0 ;
}
F_134 ( V_211 , V_19 , V_1 ) ;
return 0 ;
}
static int F_142 ( struct V_210 * V_211 , const char * V_190 , char V_19 ,
void * V_191 , int V_2 , struct V_52 * V_53 ,
struct V_7 * V_66 )
{
char V_269 = 0 ;
unsigned char * V_1 ;
int V_270 = 0 ;
if ( V_19 == 'I' && * V_190 == 'c' ) {
V_269 = 1 ;
V_190 ++ ;
V_270 ++ ;
}
if ( V_66 -> type == V_100 ) {
F_120 ( V_211 , V_191 , V_2 , V_53 , V_66 ) ;
return V_270 ;
}
if ( V_66 -> type != V_70 ) {
F_124 ( V_211 , L_130 , V_66 -> type ) ;
return V_270 ;
}
if ( ! V_66 -> V_71 . V_71 ) {
V_66 -> V_71 . V_71 =
F_75 ( V_53 , V_66 -> V_71 . V_72 ) ;
if ( ! V_66 -> V_71 . V_71 ) {
F_50 ( L_112 ,
V_136 , V_66 -> V_71 . V_72 ) ;
return V_270 ;
}
}
V_1 = V_191 + V_66 -> V_71 . V_71 -> V_147 ;
if ( V_66 -> V_71 . V_71 -> V_2 != 16 ) {
F_124 ( V_211 , L_139 ) ;
return V_270 ;
}
if ( V_269 )
F_138 ( V_211 , V_1 ) ;
else
F_140 ( V_211 , V_19 , V_1 ) ;
return V_270 ;
}
static int F_143 ( struct V_210 * V_211 , const char * V_190 , char V_19 ,
void * V_191 , int V_2 , struct V_52 * V_53 ,
struct V_7 * V_66 )
{
char V_269 = 0 , V_271 = 0 ;
unsigned char * V_1 ;
struct V_272 * V_273 ;
int V_270 = 0 ;
if ( V_19 == 'I' ) {
if ( * V_190 == 'p' ) {
V_271 = 1 ;
V_190 ++ ;
V_270 ++ ;
}
if ( * V_190 == 'c' ) {
V_269 = 1 ;
V_190 ++ ;
V_270 ++ ;
}
}
if ( V_66 -> type == V_100 ) {
F_120 ( V_211 , V_191 , V_2 , V_53 , V_66 ) ;
return V_270 ;
}
if ( V_66 -> type != V_70 ) {
F_124 ( V_211 , L_130 , V_66 -> type ) ;
return V_270 ;
}
if ( ! V_66 -> V_71 . V_71 ) {
V_66 -> V_71 . V_71 =
F_75 ( V_53 , V_66 -> V_71 . V_72 ) ;
if ( ! V_66 -> V_71 . V_71 ) {
F_50 ( L_112 ,
V_136 , V_66 -> V_71 . V_72 ) ;
return V_270 ;
}
}
V_273 = (struct V_272 * ) ( V_191 + V_66 -> V_71 . V_71 -> V_147 ) ;
if ( V_273 -> V_274 == V_275 ) {
struct V_276 * V_277 = (struct V_276 * ) V_273 ;
if ( V_66 -> V_71 . V_71 -> V_2 < sizeof( struct V_276 ) ) {
F_124 ( V_211 , L_138 ) ;
return V_270 ;
}
F_134 ( V_211 , V_19 , ( unsigned char * ) & V_277 -> V_278 ) ;
if ( V_271 )
F_124 ( V_211 , L_140 , F_139 ( V_277 -> V_279 ) ) ;
} else if ( V_273 -> V_274 == V_280 ) {
struct V_281 * V_282 = (struct V_281 * ) V_273 ;
if ( V_66 -> V_71 . V_71 -> V_2 < sizeof( struct V_281 ) ) {
F_124 ( V_211 , L_139 ) ;
return V_270 ;
}
if ( V_271 )
F_124 ( V_211 , L_38 ) ;
V_1 = ( unsigned char * ) & V_282 -> V_283 ;
if ( V_269 )
F_138 ( V_211 , V_1 ) ;
else
F_140 ( V_211 , V_19 , V_1 ) ;
if ( V_271 )
F_124 ( V_211 , L_141 , F_139 ( V_282 -> V_284 ) ) ;
}
return V_270 ;
}
static int F_144 ( struct V_210 * V_211 , const char * V_190 ,
void * V_191 , int V_2 , struct V_52 * V_53 ,
struct V_7 * V_66 )
{
char V_19 = * V_190 ;
char V_285 ;
int V_270 = 0 ;
V_190 ++ ;
V_270 ++ ;
V_285 = * V_190 ;
V_190 ++ ;
V_270 ++ ;
switch ( V_285 ) {
case '4' :
V_270 += F_141 ( V_211 , V_190 , V_19 , V_191 , V_2 , V_53 , V_66 ) ;
break;
case '6' :
V_270 += F_142 ( V_211 , V_190 , V_19 , V_191 , V_2 , V_53 , V_66 ) ;
break;
case 'S' :
V_270 += F_143 ( V_211 , V_190 , V_19 , V_191 , V_2 , V_53 , V_66 ) ;
break;
default:
return 0 ;
}
return V_270 ;
}
static int F_145 ( char * V_51 , unsigned int V_141 )
{
unsigned int V_19 ;
for ( V_19 = 0 ; V_19 < V_141 && V_51 [ V_19 ] ; V_19 ++ )
if ( ! isprint ( V_51 [ V_19 ] ) && ! isspace ( V_51 [ V_19 ] ) )
return 0 ;
return 1 ;
}
void F_146 ( struct V_210 * V_211 , void * V_191 ,
struct V_127 * V_71 )
{
unsigned long long V_171 ;
unsigned int V_147 , V_141 , V_19 ;
struct V_14 * V_14 = V_71 -> V_53 -> V_14 ;
if ( V_71 -> V_74 & V_128 ) {
V_147 = V_71 -> V_147 ;
V_141 = V_71 -> V_2 ;
if ( V_71 -> V_74 & V_144 ) {
V_171 = F_102 ( V_14 , V_191 + V_147 , V_141 ) ;
V_147 = V_171 ;
V_141 = V_147 >> 16 ;
V_147 &= 0xffff ;
}
if ( V_71 -> V_74 & V_143 &&
F_145 ( V_191 + V_147 , V_141 ) ) {
F_124 ( V_211 , L_117 , ( char * ) V_191 + V_147 ) ;
} else {
F_127 ( V_211 , L_142 ) ;
for ( V_19 = 0 ; V_19 < V_141 ; V_19 ++ ) {
if ( V_19 )
F_127 ( V_211 , L_143 ) ;
F_124 ( V_211 , L_113 ,
* ( ( unsigned char * ) V_191 + V_147 + V_19 ) ) ;
}
F_128 ( V_211 , ']' ) ;
V_71 -> V_74 &= ~ V_143 ;
}
} else {
V_171 = F_102 ( V_14 , V_191 + V_71 -> V_147 ,
V_71 -> V_2 ) ;
if ( V_71 -> V_74 & V_134 ) {
F_124 ( V_211 , L_144 , V_171 ) ;
} else if ( V_71 -> V_74 & V_148 ) {
switch ( V_71 -> V_2 ) {
case 4 :
if ( V_71 -> V_74 & V_145 )
F_124 ( V_211 , L_145 , ( int ) V_171 ) ;
else
F_124 ( V_211 , L_146 , ( int ) V_171 ) ;
break;
case 2 :
F_124 ( V_211 , L_147 , ( short ) V_171 ) ;
break;
case 1 :
F_124 ( V_211 , L_148 , ( char ) V_171 ) ;
break;
default:
F_124 ( V_211 , L_81 , V_171 ) ;
}
} else {
if ( V_71 -> V_74 & V_145 )
F_124 ( V_211 , L_144 , V_171 ) ;
else
F_124 ( V_211 , L_149 , V_171 ) ;
}
}
}
void F_147 ( struct V_210 * V_211 , void * V_191 ,
int V_2 V_162 , struct V_52 * V_53 )
{
struct V_127 * V_71 ;
V_71 = V_53 -> V_151 . V_130 ;
while ( V_71 ) {
F_124 ( V_211 , L_150 , V_71 -> V_72 ) ;
F_146 ( V_211 , V_191 , V_71 ) ;
V_71 = V_71 -> V_22 ;
}
}
static void F_148 ( struct V_210 * V_211 , void * V_191 , int V_2 , struct V_52 * V_53 )
{
struct V_14 * V_14 = V_53 -> V_14 ;
struct V_188 * V_188 = & V_53 -> V_188 ;
struct V_7 * V_66 = V_188 -> args ;
struct V_7 * args = NULL ;
const char * V_190 = V_188 -> V_151 ;
unsigned long long V_171 ;
struct V_28 * V_35 ;
const char * V_286 ;
struct V_210 V_51 ;
char * V_287 = NULL ;
char V_151 [ 32 ] ;
int V_288 ;
int V_289 ;
int V_215 ;
int V_141 ;
int V_250 ;
if ( V_53 -> V_74 & V_159 ) {
F_124 ( V_211 , L_151 ) ;
F_147 ( V_211 , V_191 , V_2 , V_53 ) ;
return;
}
if ( V_53 -> V_74 & V_290 ) {
V_287 = F_132 ( V_191 , V_2 , V_53 ) ;
args = F_131 ( V_287 , V_191 , V_2 , V_53 ) ;
V_66 = args ;
V_190 = V_287 ;
}
for (; * V_190 ; V_190 ++ ) {
V_250 = 0 ;
if ( * V_190 == '\\' ) {
V_190 ++ ;
switch ( * V_190 ) {
case 'n' :
F_128 ( V_211 , '\n' ) ;
break;
case 't' :
F_128 ( V_211 , '\t' ) ;
break;
case 'r' :
F_128 ( V_211 , '\r' ) ;
break;
case '\\' :
F_128 ( V_211 , '\\' ) ;
break;
default:
F_128 ( V_211 , * V_190 ) ;
break;
}
} else if ( * V_190 == '%' ) {
V_286 = V_190 ;
V_288 = 0 ;
V_289 = 0 ;
V_291:
V_190 ++ ;
switch ( * V_190 ) {
case '%' :
F_128 ( V_211 , '%' ) ;
break;
case '#' :
goto V_291;
case 'h' :
V_250 -- ;
goto V_291;
case 'l' :
V_250 ++ ;
goto V_291;
case 'L' :
V_250 = 2 ;
goto V_291;
case '*' :
if ( ! V_66 ) {
F_64 ( V_53 , L_152 ) ;
V_53 -> V_74 |= V_159 ;
goto V_292;
}
V_215 = F_117 ( V_191 , V_2 , V_53 , V_66 ) ;
V_289 = 1 ;
V_66 = V_66 -> V_22 ;
goto V_291;
case '.' :
case 'z' :
case 'Z' :
case '0' ... '9' :
case '-' :
goto V_291;
case 'p' :
if ( V_14 -> V_150 == 4 )
V_250 = 1 ;
else
V_250 = 2 ;
if ( * ( V_190 + 1 ) == 'F' || * ( V_190 + 1 ) == 'f' ||
* ( V_190 + 1 ) == 'S' || * ( V_190 + 1 ) == 's' ) {
V_190 ++ ;
V_288 = * V_190 ;
} else if ( * ( V_190 + 1 ) == 'M' || * ( V_190 + 1 ) == 'm' ) {
F_133 ( V_211 , * ( V_190 + 1 ) , V_191 , V_2 , V_53 , V_66 ) ;
V_190 ++ ;
V_66 = V_66 -> V_22 ;
break;
} else if ( * ( V_190 + 1 ) == 'I' || * ( V_190 + 1 ) == 'i' ) {
int V_293 ;
V_293 = F_144 ( V_211 , V_190 + 1 , V_191 , V_2 , V_53 , V_66 ) ;
if ( V_293 > 0 ) {
V_190 += V_293 ;
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
F_64 ( V_53 , L_152 ) ;
V_53 -> V_74 |= V_159 ;
goto V_292;
}
V_141 = ( ( unsigned long ) V_190 + 1 ) -
( unsigned long ) V_286 ;
if ( V_141 > 31 ) {
F_64 ( V_53 , L_153 ) ;
V_53 -> V_74 |= V_159 ;
V_141 = 31 ;
}
memcpy ( V_151 , V_286 , V_141 ) ;
V_151 [ V_141 ] = 0 ;
V_171 = F_117 ( V_191 , V_2 , V_53 , V_66 ) ;
V_66 = V_66 -> V_22 ;
if ( V_288 ) {
V_35 = F_21 ( V_14 , V_171 ) ;
if ( V_35 ) {
F_127 ( V_211 , V_35 -> V_35 ) ;
if ( V_288 == 'F' )
F_124 ( V_211 ,
L_154 ,
V_171 - V_35 -> V_31 ) ;
break;
}
}
if ( V_14 -> V_150 == 8 && V_250 == 1 &&
sizeof( long ) != 8 ) {
char * V_51 ;
if ( V_250 == 1 && ( V_51 = strchr ( V_151 , 'l' ) ) )
memmove ( V_51 + 1 , V_51 , strlen ( V_51 ) + 1 ) ;
else if ( strcmp ( V_151 , L_155 ) == 0 )
strcpy ( V_151 , L_144 ) ;
V_250 = 2 ;
}
switch ( V_250 ) {
case - 2 :
if ( V_289 )
F_124 ( V_211 , V_151 , V_215 , ( char ) V_171 ) ;
else
F_124 ( V_211 , V_151 , ( char ) V_171 ) ;
break;
case - 1 :
if ( V_289 )
F_124 ( V_211 , V_151 , V_215 , ( short ) V_171 ) ;
else
F_124 ( V_211 , V_151 , ( short ) V_171 ) ;
break;
case 0 :
if ( V_289 )
F_124 ( V_211 , V_151 , V_215 , ( int ) V_171 ) ;
else
F_124 ( V_211 , V_151 , ( int ) V_171 ) ;
break;
case 1 :
if ( V_289 )
F_124 ( V_211 , V_151 , V_215 , ( long ) V_171 ) ;
else
F_124 ( V_211 , V_151 , ( long ) V_171 ) ;
break;
case 2 :
if ( V_289 )
F_124 ( V_211 , V_151 , V_215 ,
( long long ) V_171 ) ;
else
F_124 ( V_211 , V_151 , ( long long ) V_171 ) ;
break;
default:
F_64 ( V_53 , L_156 , V_250 ) ;
V_53 -> V_74 |= V_159 ;
}
break;
case 's' :
if ( ! V_66 ) {
F_64 ( V_53 , L_157 ) ;
V_53 -> V_74 |= V_159 ;
goto V_292;
}
V_141 = ( ( unsigned long ) V_190 + 1 ) -
( unsigned long ) V_286 ;
if ( V_141 > 31 ) {
F_64 ( V_53 , L_153 ) ;
V_53 -> V_74 |= V_159 ;
V_141 = 31 ;
}
memcpy ( V_151 , V_286 , V_141 ) ;
V_151 [ V_141 ] = 0 ;
if ( ! V_289 )
V_215 = - 1 ;
F_119 ( & V_51 ) ;
F_126 ( & V_51 , V_191 , V_2 , V_53 ,
V_151 , V_215 , V_66 ) ;
F_129 ( & V_51 ) ;
F_127 ( V_211 , V_51 . V_242 ) ;
F_121 ( & V_51 ) ;
V_66 = V_66 -> V_22 ;
break;
default:
F_124 ( V_211 , L_158 , * V_190 ) ;
}
} else
F_128 ( V_211 , * V_190 ) ;
}
if ( V_53 -> V_74 & V_159 ) {
V_292:
F_124 ( V_211 , L_151 ) ;
}
if ( args ) {
F_130 ( args ) ;
free ( V_287 ) ;
}
}
void F_149 ( struct V_14 * V_14 ,
struct V_210 * V_211 , struct V_294 * V_295 )
{
static int V_296 = 1 ;
static int V_297 = 1 ;
static int V_298 ;
static int V_299 ;
unsigned int V_300 ;
unsigned int V_301 ;
int V_302 ;
int V_303 ;
int V_304 ;
int V_305 ;
void * V_191 = V_295 -> V_191 ;
V_300 = F_112 ( V_14 , V_191 ) ;
V_301 = F_111 ( V_14 , V_191 ) ;
if ( V_298 )
V_302 = F_113 ( V_14 , V_191 ) ;
else if ( V_296 ) {
V_302 = F_113 ( V_14 , V_191 ) ;
if ( V_302 < 0 )
V_296 = 0 ;
else
V_298 = 1 ;
}
if ( V_299 )
V_303 = F_114 ( V_14 , V_191 ) ;
else if ( V_297 ) {
V_303 = F_114 ( V_14 , V_191 ) ;
if ( V_303 < 0 )
V_297 = 0 ;
else
V_299 = 1 ;
}
V_304 = V_300 & V_306 ;
V_305 = V_300 & V_307 ;
F_124 ( V_211 , L_159 ,
( V_300 & V_308 ) ? 'd' :
( V_300 & V_309 ) ?
'X' : '.' ,
( V_300 & V_310 ) ?
'N' : '.' ,
( V_304 && V_305 ) ? 'H' :
V_304 ? 'h' : V_305 ? 's' : '.' ) ;
if ( V_301 )
F_124 ( V_211 , L_136 , V_301 ) ;
else
F_128 ( V_211 , '.' ) ;
if ( V_299 ) {
if ( V_303 < 0 )
F_128 ( V_211 , '.' ) ;
else
F_124 ( V_211 , L_146 , V_303 ) ;
}
if ( V_298 ) {
if ( V_302 < 0 )
F_128 ( V_211 , '.' ) ;
else
F_124 ( V_211 , L_146 , V_302 ) ;
}
F_129 ( V_211 ) ;
}
int F_150 ( struct V_14 * V_14 , struct V_294 * V_311 )
{
return F_109 ( V_14 , V_311 -> V_191 ) ;
}
struct V_52 * F_151 ( struct V_14 * V_14 , int type )
{
return F_115 ( V_14 , type ) ;
}
int F_152 ( struct V_14 * V_14 , struct V_294 * V_311 )
{
return F_110 ( V_14 , V_311 -> V_191 ) ;
}
int F_153 ( struct V_14 * V_14 , struct V_294 * V_311 )
{
return F_111 ( V_14 , V_311 -> V_191 ) ;
}
int F_154 ( struct V_14 * V_14 , struct V_294 * V_311 )
{
return F_112 ( V_14 , V_311 -> V_191 ) ;
}
const char * F_155 ( struct V_14 * V_14 , int V_13 )
{
const char * V_21 ;
V_21 = F_9 ( V_14 , V_13 ) ;
return V_21 ;
}
static struct V_10 *
F_156 ( struct V_14 * V_14 , const char * V_21 , struct V_10 * V_22 )
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
struct V_10 * F_157 ( struct V_14 * V_14 , const char * V_21 ,
struct V_10 * V_22 )
{
struct V_10 * V_10 ;
if ( ! V_14 -> V_18 )
return F_156 ( V_14 , V_21 , V_22 ) ;
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
int F_158 ( struct V_14 * V_14 , struct V_10 * V_10 )
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
void F_159 ( struct V_210 * V_211 , struct V_52 * V_53 ,
struct V_294 * V_295 )
{
int V_312 = 1 ;
if ( V_53 -> V_14 -> V_313 || ( V_53 -> V_74 & V_314 ) )
F_147 ( V_211 , V_295 -> V_191 , V_295 -> V_2 , V_53 ) ;
else {
if ( V_53 -> V_315 && ! ( V_53 -> V_74 & V_316 ) )
V_312 = V_53 -> V_315 ( V_211 , V_295 , V_53 ,
V_53 -> V_317 ) ;
if ( V_312 )
F_148 ( V_211 , V_295 -> V_191 , V_295 -> V_2 , V_53 ) ;
}
F_129 ( V_211 ) ;
}
static bool F_160 ( char * V_27 , bool V_318 )
{
if ( ! V_318 )
return true ;
if ( ! strcmp ( V_27 , L_160 ) || ! strcmp ( V_27 , L_161 )
|| ! strcmp ( V_27 , L_162 ) || ! strcmp ( V_27 , L_163 ) )
return true ;
return false ;
}
struct V_52 *
F_161 ( struct V_14 * V_14 , struct V_294 * V_295 )
{
int type ;
if ( V_295 -> V_2 < 0 ) {
F_50 ( L_164 , V_295 -> V_2 ) ;
return NULL ;
}
type = F_109 ( V_14 , V_295 -> V_191 ) ;
return F_115 ( V_14 , type ) ;
}
void F_162 ( struct V_14 * V_14 , struct V_210 * V_211 ,
struct V_52 * V_53 ,
struct V_294 * V_295 )
{
void * V_191 = V_295 -> V_191 ;
const char * V_21 ;
int V_13 ;
V_13 = F_110 ( V_14 , V_191 ) ;
V_21 = F_9 ( V_14 , V_13 ) ;
if ( V_14 -> V_319 ) {
F_124 ( V_211 , L_165 ,
V_21 , V_13 , V_295 -> V_320 ) ;
} else
F_124 ( V_211 , L_166 , V_21 , V_13 , V_295 -> V_320 ) ;
}
void F_163 ( struct V_14 * V_14 , struct V_210 * V_211 ,
struct V_52 * V_53 ,
struct V_294 * V_295 ,
bool V_318 )
{
unsigned long V_321 ;
unsigned long V_322 ;
unsigned long V_323 ;
int V_51 ;
bool V_324 ;
V_324 = F_160 ( V_14 -> V_27 ,
V_318 ) ;
if ( V_324 ) {
V_321 = V_295 -> V_325 / V_326 ;
V_323 = V_295 -> V_325 - V_321 * V_326 ;
}
if ( V_14 -> V_319 ) {
F_149 ( V_14 , V_211 , V_295 ) ;
}
if ( V_324 ) {
if ( V_14 -> V_74 & V_327 ) {
V_322 = V_323 ;
V_51 = 9 ;
} else {
V_322 = ( V_323 + 500 ) / V_328 ;
if ( V_322 >= V_329 ) {
V_322 -= V_329 ;
V_321 ++ ;
}
V_51 = 6 ;
}
F_124 ( V_211 , L_167 , V_321 , V_51 , V_322 ) ;
} else
F_124 ( V_211 , L_168 , V_295 -> V_325 ) ;
}
void F_164 ( struct V_14 * V_14 , struct V_210 * V_211 ,
struct V_52 * V_53 ,
struct V_294 * V_295 )
{
static const char * V_330 = L_169 ;
int V_141 ;
F_124 ( V_211 , L_170 , V_53 -> V_72 ) ;
V_141 = strlen ( V_53 -> V_72 ) ;
if ( V_141 < 20 )
F_124 ( V_211 , L_171 , 20 - V_141 , V_330 ) ;
F_159 ( V_211 , V_53 , V_295 ) ;
}
void F_165 ( struct V_14 * V_14 , struct V_210 * V_211 ,
struct V_294 * V_295 , bool V_318 )
{
struct V_52 * V_53 ;
V_53 = F_161 ( V_14 , V_295 ) ;
if ( ! V_53 ) {
F_50 ( L_172 ,
F_109 ( V_14 , V_295 -> V_191 ) ) ;
return;
}
F_162 ( V_14 , V_211 , V_53 , V_295 ) ;
F_163 ( V_14 , V_211 , V_53 , V_295 , V_318 ) ;
F_164 ( V_14 , V_211 , V_53 , V_295 ) ;
}
static int V_204 ( const void * V_8 , const void * V_9 )
{
struct V_52 * const * V_331 = V_8 ;
struct V_52 * const * V_332 = V_9 ;
if ( ( * V_331 ) -> V_56 < ( * V_332 ) -> V_56 )
return - 1 ;
if ( ( * V_331 ) -> V_56 > ( * V_332 ) -> V_56 )
return 1 ;
return 0 ;
}
static int F_166 ( const void * V_8 , const void * V_9 )
{
struct V_52 * const * V_331 = V_8 ;
struct V_52 * const * V_332 = V_9 ;
int V_333 ;
V_333 = strcmp ( ( * V_331 ) -> V_72 , ( * V_332 ) -> V_72 ) ;
if ( V_333 )
return V_333 ;
V_333 = strcmp ( ( * V_331 ) -> system , ( * V_332 ) -> system ) ;
if ( V_333 )
return V_333 ;
return V_204 ( V_8 , V_9 ) ;
}
static int F_167 ( const void * V_8 , const void * V_9 )
{
struct V_52 * const * V_331 = V_8 ;
struct V_52 * const * V_332 = V_9 ;
int V_333 ;
V_333 = strcmp ( ( * V_331 ) -> system , ( * V_332 ) -> system ) ;
if ( V_333 )
return V_333 ;
V_333 = strcmp ( ( * V_331 ) -> V_72 , ( * V_332 ) -> V_72 ) ;
if ( V_333 )
return V_333 ;
return V_204 ( V_8 , V_9 ) ;
}
struct V_52 * * F_168 ( struct V_14 * V_14 , enum V_334 V_335 )
{
struct V_52 * * V_54 ;
int (* F_169)( const void * V_8 , const void * V_9 );
V_54 = V_14 -> V_336 ;
if ( V_54 && V_14 -> V_138 == V_335 )
return V_54 ;
if ( ! V_54 ) {
V_54 = malloc ( sizeof( * V_54 ) * ( V_14 -> V_55 + 1 ) ) ;
if ( ! V_54 )
return NULL ;
memcpy ( V_54 , V_14 -> V_54 , sizeof( * V_54 ) * V_14 -> V_55 ) ;
V_54 [ V_14 -> V_55 ] = NULL ;
V_14 -> V_336 = V_54 ;
if ( V_335 == V_337 ) {
V_14 -> V_138 = V_335 ;
return V_54 ;
}
}
switch ( V_335 ) {
case V_337 :
F_169 = V_204 ;
break;
case V_338 :
F_169 = F_166 ;
break;
case V_339 :
F_169 = F_167 ;
break;
default:
return V_54 ;
}
qsort ( V_54 , V_14 -> V_55 , sizeof( * V_54 ) , F_169 ) ;
V_14 -> V_138 = V_335 ;
return V_54 ;
}
static struct V_127 * *
F_170 ( const char * type , const char * V_72 ,
int V_84 , struct V_127 * V_175 )
{
struct V_127 * * V_130 ;
struct V_127 * V_71 ;
int V_19 = 0 ;
V_130 = malloc ( sizeof( * V_130 ) * ( V_84 + 1 ) ) ;
if ( ! V_130 )
return NULL ;
for ( V_71 = V_175 ; V_71 ; V_71 = V_71 -> V_22 ) {
V_130 [ V_19 ++ ] = V_71 ;
if ( V_19 == V_84 + 1 ) {
F_50 ( L_173 ,
V_72 , type ) ;
V_19 -- ;
break;
}
}
if ( V_19 != V_84 )
F_50 ( L_174 ,
V_72 , type ) ;
V_130 [ V_19 ] = NULL ;
return V_130 ;
}
struct V_127 * * F_171 ( struct V_52 * V_53 )
{
return F_170 ( L_175 , V_53 -> V_72 ,
V_53 -> V_151 . V_153 ,
V_53 -> V_151 . V_152 ) ;
}
struct V_127 * * F_172 ( struct V_52 * V_53 )
{
return F_170 ( L_176 , V_53 -> V_72 ,
V_53 -> V_151 . V_154 ,
V_53 -> V_151 . V_130 ) ;
}
static void F_173 ( struct V_210 * V_211 , struct V_62 * V_71 )
{
F_124 ( V_211 , L_177 , V_71 -> V_64 , V_71 -> V_65 ) ;
if ( V_71 -> V_22 ) {
F_127 ( V_211 , L_143 ) ;
F_173 ( V_211 , V_71 -> V_22 ) ;
}
}
static void F_174 ( struct V_7 * args )
{
int V_340 = 1 ;
struct V_210 V_211 ;
switch ( args -> type ) {
case V_101 :
printf ( L_178 ) ;
break;
case V_68 :
printf ( L_117 , args -> V_69 . V_69 ) ;
break;
case V_70 :
printf ( L_179 , args -> V_71 . V_72 ) ;
break;
case V_73 :
printf ( L_180 ) ;
F_174 ( args -> V_74 . V_71 ) ;
printf ( L_181 , args -> V_74 . V_75 ) ;
F_119 ( & V_211 ) ;
F_173 ( & V_211 , args -> V_74 . V_74 ) ;
F_175 ( & V_211 ) ;
F_121 ( & V_211 ) ;
printf ( L_70 ) ;
break;
case V_76 :
printf ( L_182 ) ;
F_174 ( args -> V_77 . V_71 ) ;
printf ( L_143 ) ;
F_119 ( & V_211 ) ;
F_173 ( & V_211 , args -> V_77 . V_78 ) ;
F_175 ( & V_211 ) ;
F_121 ( & V_211 ) ;
printf ( L_70 ) ;
break;
case V_79 :
printf ( L_183 ) ;
F_174 ( args -> V_81 . V_71 ) ;
printf ( L_143 ) ;
F_174 ( args -> V_81 . V_2 ) ;
printf ( L_70 ) ;
break;
case V_80 :
printf ( L_184 ) ;
F_174 ( args -> V_81 . V_71 ) ;
printf ( L_143 ) ;
F_174 ( args -> V_81 . V_2 ) ;
printf ( L_70 ) ;
break;
case V_82 :
printf ( L_185 ) ;
F_174 ( args -> V_83 . V_71 ) ;
printf ( L_143 ) ;
F_174 ( args -> V_83 . V_84 ) ;
printf ( L_143 ) ;
F_174 ( args -> V_83 . V_85 ) ;
printf ( L_70 ) ;
break;
case V_88 :
case V_89 :
printf ( L_186 , args -> string . string ) ;
break;
case V_90 :
printf ( L_187 , args -> V_91 . V_91 ) ;
break;
case V_86 :
printf ( L_188 , args -> V_87 . type ) ;
F_174 ( args -> V_87 . V_17 ) ;
break;
case V_96 :
if ( strcmp ( args -> V_97 . V_97 , L_19 ) == 0 )
V_340 = 0 ;
if ( V_340 )
printf ( L_85 ) ;
F_174 ( args -> V_97 . V_98 ) ;
printf ( L_189 , args -> V_97 . V_97 ) ;
F_174 ( args -> V_97 . V_99 ) ;
if ( V_340 )
printf ( L_70 ) ;
break;
default:
return;
}
if ( args -> V_22 ) {
printf ( L_6 ) ;
F_174 ( args -> V_22 ) ;
}
}
static void F_176 ( const char * V_71 ,
int * V_147 , int * V_2 , int V_341 )
{
unsigned long long V_118 ;
unsigned long long V_120 ;
char * V_121 ;
int type ;
V_118 = V_5 ;
V_120 = V_4 ;
if ( F_55 ( V_58 , L_32 ) < 0 )
return;
if ( F_55 ( V_107 , L_19 ) < 0 )
return;
if ( F_53 ( V_58 , & V_121 ) < 0 )
goto V_126;
F_44 ( V_121 ) ;
if ( V_341 ) {
if ( F_55 ( V_58 , V_71 ) < 0 )
return;
} else {
if ( F_53 ( V_58 , & V_121 ) < 0 )
goto V_126;
if ( strcmp ( V_121 , V_71 ) != 0 )
goto V_342;
F_44 ( V_121 ) ;
}
if ( F_55 ( V_107 , L_41 ) < 0 )
return;
if ( F_55 ( V_58 , L_42 ) < 0 )
return;
if ( F_55 ( V_107 , L_19 ) < 0 )
return;
if ( F_53 ( V_58 , & V_121 ) < 0 )
goto V_126;
* V_147 = atoi ( V_121 ) ;
F_44 ( V_121 ) ;
if ( F_55 ( V_107 , L_41 ) < 0 )
return;
if ( F_55 ( V_58 , L_43 ) < 0 )
return;
if ( F_55 ( V_107 , L_19 ) < 0 )
return;
if ( F_53 ( V_58 , & V_121 ) < 0 )
goto V_126;
* V_2 = atoi ( V_121 ) ;
F_44 ( V_121 ) ;
if ( F_55 ( V_107 , L_41 ) < 0 )
return;
type = F_45 ( & V_121 ) ;
if ( type != V_103 ) {
if ( type != V_58 )
goto V_126;
if ( strcmp ( V_121 , L_44 ) != 0 )
goto V_126;
F_44 ( V_121 ) ;
if ( F_55 ( V_107 , L_19 ) < 0 )
return;
if ( F_53 ( V_58 , & V_121 ) )
goto V_126;
F_44 ( V_121 ) ;
if ( F_55 ( V_107 , L_41 ) < 0 )
return;
if ( F_53 ( V_103 , & V_121 ) )
goto V_126;
}
V_126:
F_44 ( V_121 ) ;
return;
V_342:
V_5 = V_118 ;
V_4 = V_120 ;
* V_147 = 0 ;
* V_2 = 0 ;
F_44 ( V_121 ) ;
}
int F_177 ( struct V_14 * V_14 , char * V_1 , unsigned long V_2 ,
int V_150 )
{
int V_343 ;
if ( ! V_2 ) {
V_14 -> V_344 = sizeof( long long ) ;
V_14 -> V_345 = V_150 ;
V_14 -> V_346 = sizeof( long long ) + V_150 ;
V_14 -> V_347 = 1 ;
return - 1 ;
}
F_1 ( V_1 , V_2 ) ;
F_176 ( L_190 , & V_14 -> V_348 ,
& V_14 -> V_344 , 1 ) ;
F_176 ( L_191 , & V_14 -> V_349 ,
& V_14 -> V_345 , 1 ) ;
F_176 ( L_192 , & V_14 -> V_350 ,
& V_343 , 0 ) ;
F_176 ( L_193 , & V_14 -> V_346 ,
& V_14 -> V_351 , 1 ) ;
return 0 ;
}
static int F_178 ( struct V_52 * V_53 ,
int V_56 , const char * V_352 ,
const char * V_353 )
{
if ( V_56 >= 0 && V_56 != V_53 -> V_56 )
return 0 ;
if ( V_353 && ( strcmp ( V_353 , V_53 -> V_72 ) != 0 ) )
return 0 ;
if ( V_352 && ( strcmp ( V_352 , V_53 -> system ) != 0 ) )
return 0 ;
return 1 ;
}
static void F_179 ( struct V_354 * V_355 )
{
free ( ( void * ) V_355 -> V_352 ) ;
free ( ( void * ) V_355 -> V_353 ) ;
free ( V_355 ) ;
}
static int F_180 ( struct V_14 * V_14 , struct V_52 * V_53 )
{
struct V_354 * V_355 , * * V_22 ;
for ( V_22 = & V_14 -> V_356 ; * V_22 ;
V_22 = & ( * V_22 ) -> V_22 ) {
V_355 = * V_22 ;
if ( F_178 ( V_53 , V_355 -> V_56 ,
V_355 -> V_352 ,
V_355 -> V_353 ) )
break;
}
if ( ! ( * V_22 ) )
return 0 ;
F_181 ( L_194 ,
V_53 -> V_56 , V_53 -> system , V_53 -> V_72 ) ;
V_53 -> V_315 = V_355 -> V_35 ;
V_53 -> V_317 = V_355 -> V_317 ;
* V_22 = V_355 -> V_22 ;
F_179 ( V_355 ) ;
return 1 ;
}
enum V_357 F_182 ( struct V_52 * * V_358 ,
struct V_14 * V_14 , const char * V_1 ,
unsigned long V_2 , const char * V_205 )
{
struct V_52 * V_53 ;
int V_125 ;
F_1 ( V_1 , V_2 ) ;
* V_358 = V_53 = F_31 () ;
if ( ! V_53 )
return V_359 ;
V_53 -> V_72 = F_57 () ;
if ( ! V_53 -> V_72 ) {
V_125 = V_359 ;
goto V_360;
}
if ( strcmp ( V_205 , L_195 ) == 0 ) {
V_53 -> V_74 |= V_133 ;
if ( strcmp ( V_53 -> V_72 , L_196 ) == 0 )
V_53 -> V_74 |= V_290 ;
}
V_53 -> V_56 = F_58 () ;
if ( V_53 -> V_56 < 0 ) {
V_125 = V_361 ;
goto V_360;
}
V_53 -> system = F_12 ( V_205 ) ;
if ( ! V_53 -> system ) {
V_125 = V_359 ;
goto V_360;
}
V_53 -> V_14 = V_14 ;
V_125 = F_65 ( V_53 ) ;
if ( V_125 < 0 ) {
V_125 = V_362 ;
goto V_363;
}
if ( V_14 && F_180 ( V_14 , V_53 ) )
V_364 = 0 ;
V_125 = F_100 ( V_53 ) ;
V_364 = 1 ;
if ( V_125 < 0 ) {
V_125 = V_365 ;
goto V_363;
}
if ( ! V_125 && ( V_53 -> V_74 & V_133 ) ) {
struct V_127 * V_71 ;
struct V_7 * V_66 , * * V_175 ;
V_175 = & V_53 -> V_188 . args ;
for ( V_71 = V_53 -> V_151 . V_130 ; V_71 ; V_71 = V_71 -> V_22 ) {
V_66 = F_6 () ;
if ( ! V_66 ) {
V_53 -> V_74 |= V_159 ;
return V_366 ;
}
V_66 -> type = V_70 ;
V_66 -> V_71 . V_72 = F_12 ( V_71 -> V_72 ) ;
if ( ! V_66 -> V_71 . V_72 ) {
V_53 -> V_74 |= V_159 ;
F_35 ( V_66 ) ;
return V_366 ;
}
V_66 -> V_71 . V_71 = V_71 ;
* V_175 = V_66 ;
V_175 = & V_66 -> V_22 ;
}
return 0 ;
}
return 0 ;
V_363:
V_53 -> V_74 |= V_159 ;
return V_125 ;
V_360:
free ( V_53 -> system ) ;
free ( V_53 -> V_72 ) ;
free ( V_53 ) ;
* V_358 = NULL ;
return V_125 ;
}
static enum V_357
F_183 ( struct V_14 * V_14 ,
struct V_52 * * V_358 ,
const char * V_1 , unsigned long V_2 ,
const char * V_205 )
{
int V_125 = F_182 ( V_358 , V_14 , V_1 , V_2 , V_205 ) ;
struct V_52 * V_53 = * V_358 ;
if ( V_53 == NULL )
return V_125 ;
if ( V_14 && F_32 ( V_14 , V_53 ) ) {
V_125 = V_359 ;
goto V_367;
}
#define F_184 0
if ( F_184 && V_53 -> V_188 . args )
F_174 ( V_53 -> V_188 . args ) ;
return 0 ;
V_367:
F_185 ( V_53 ) ;
return V_125 ;
}
enum V_357 F_186 ( struct V_14 * V_14 ,
struct V_52 * * V_358 ,
const char * V_1 ,
unsigned long V_2 , const char * V_205 )
{
return F_183 ( V_14 , V_358 , V_1 , V_2 , V_205 ) ;
}
enum V_357 F_187 ( struct V_14 * V_14 , const char * V_1 ,
unsigned long V_2 , const char * V_205 )
{
struct V_52 * V_53 = NULL ;
return F_183 ( V_14 , & V_53 , V_1 , V_2 , V_205 ) ;
}
int F_188 ( struct V_14 * V_14 V_162 ,
enum V_357 V_368 , char * V_1 , T_2 V_369 )
{
int V_370 ;
const char * V_371 ;
if ( V_368 >= 0 ) {
F_189 ( V_368 , V_1 , V_369 ) ;
return 0 ;
}
if ( V_368 <= V_372 ||
V_368 >= V_373 )
return - 1 ;
V_370 = V_368 - V_372 - 1 ;
V_371 = V_374 [ V_370 ] ;
snprintf ( V_1 , V_369 , L_117 , V_371 ) ;
return 0 ;
}
int F_190 ( struct V_210 * V_211 , struct V_127 * V_71 ,
const char * V_72 , struct V_294 * V_295 ,
unsigned long long * V_171 , int V_187 )
{
if ( ! V_71 ) {
if ( V_187 )
F_124 ( V_211 , L_197 , V_72 ) ;
return - 1 ;
}
if ( F_106 ( V_71 , V_295 -> V_191 , V_171 ) ) {
if ( V_187 )
F_124 ( V_211 , L_198 , V_72 ) ;
return - 1 ;
}
return 0 ;
}
void * F_191 ( struct V_210 * V_211 , struct V_52 * V_53 ,
const char * V_72 , struct V_294 * V_295 ,
int * V_141 , int V_187 )
{
struct V_127 * V_71 ;
void * V_191 = V_295 -> V_191 ;
unsigned V_147 ;
int V_375 ;
if ( ! V_53 )
return NULL ;
V_71 = F_89 ( V_53 , V_72 ) ;
if ( ! V_71 ) {
if ( V_187 )
F_124 ( V_211 , L_197 , V_72 ) ;
return NULL ;
}
if ( ! V_141 )
V_141 = & V_375 ;
V_147 = V_71 -> V_147 ;
if ( V_71 -> V_74 & V_144 ) {
V_147 = F_102 ( V_53 -> V_14 ,
V_191 + V_147 , V_71 -> V_2 ) ;
* V_141 = V_147 >> 16 ;
V_147 &= 0xffff ;
} else
* V_141 = V_71 -> V_2 ;
return V_191 + V_147 ;
}
int F_192 ( struct V_210 * V_211 , struct V_52 * V_53 ,
const char * V_72 , struct V_294 * V_295 ,
unsigned long long * V_171 , int V_187 )
{
struct V_127 * V_71 ;
if ( ! V_53 )
return - 1 ;
V_71 = F_89 ( V_53 , V_72 ) ;
return F_190 ( V_211 , V_71 , V_72 , V_295 , V_171 , V_187 ) ;
}
int F_193 ( struct V_210 * V_211 , struct V_52 * V_53 ,
const char * V_72 , struct V_294 * V_295 ,
unsigned long long * V_171 , int V_187 )
{
struct V_127 * V_71 ;
if ( ! V_53 )
return - 1 ;
V_71 = F_101 ( V_53 , V_72 ) ;
return F_190 ( V_211 , V_71 , V_72 , V_295 , V_171 , V_187 ) ;
}
int F_194 ( struct V_210 * V_211 , struct V_52 * V_53 ,
const char * V_72 , struct V_294 * V_295 ,
unsigned long long * V_171 , int V_187 )
{
struct V_127 * V_71 ;
if ( ! V_53 )
return - 1 ;
V_71 = F_75 ( V_53 , V_72 ) ;
return F_190 ( V_211 , V_71 , V_72 , V_295 , V_171 , V_187 ) ;
}
int F_195 ( struct V_210 * V_211 , const char * V_50 ,
struct V_52 * V_53 , const char * V_72 ,
struct V_294 * V_295 , int V_187 )
{
struct V_127 * V_71 = F_89 ( V_53 , V_72 ) ;
unsigned long long V_171 ;
if ( ! V_71 )
goto V_376;
if ( F_106 ( V_71 , V_295 -> V_191 , & V_171 ) )
goto V_376;
return F_124 ( V_211 , V_50 , V_171 ) ;
V_376:
if ( V_187 )
F_124 ( V_211 , L_199 , V_72 ) ;
return - 1 ;
}
int F_196 ( struct V_210 * V_211 , const char * V_50 ,
struct V_52 * V_53 , const char * V_72 ,
struct V_294 * V_295 , int V_187 )
{
struct V_127 * V_71 = F_89 ( V_53 , V_72 ) ;
struct V_14 * V_14 = V_53 -> V_14 ;
unsigned long long V_171 ;
struct V_28 * V_35 ;
char V_161 [ 128 ] ;
if ( ! V_71 )
goto V_376;
if ( F_106 ( V_71 , V_295 -> V_191 , & V_171 ) )
goto V_376;
V_35 = F_21 ( V_14 , V_171 ) ;
if ( V_35 )
snprintf ( V_161 , 128 , L_200 , V_35 -> V_35 , V_35 -> V_31 - V_171 ) ;
else
sprintf ( V_161 , L_201 , V_171 ) ;
return F_124 ( V_211 , V_50 , V_161 ) ;
V_376:
if ( V_187 )
F_124 ( V_211 , L_199 , V_72 ) ;
return - 1 ;
}
static void F_96 ( struct V_182 * V_35 )
{
struct V_232 * V_236 ;
free ( V_35 -> V_72 ) ;
while ( V_35 -> V_236 ) {
V_236 = V_35 -> V_236 ;
V_35 -> V_236 = V_236 -> V_22 ;
free ( V_236 ) ;
}
free ( V_35 ) ;
}
int F_197 ( struct V_14 * V_14 ,
T_3 V_35 ,
enum V_377 V_378 ,
char * V_72 , ... )
{
struct V_182 * V_231 ;
struct V_232 * * V_379 ;
struct V_232 * V_233 ;
enum V_377 type ;
T_4 V_380 ;
int V_125 ;
V_231 = F_94 ( V_14 , V_72 ) ;
if ( V_231 ) {
F_181 ( L_202 , V_72 ) ;
F_95 ( V_14 , V_72 ) ;
}
V_231 = calloc ( 1 , sizeof( * V_231 ) ) ;
if ( ! V_231 ) {
F_50 ( L_203 ) ;
return V_359 ;
}
V_231 -> V_378 = V_378 ;
V_231 -> V_72 = F_12 ( V_72 ) ;
V_231 -> V_35 = V_35 ;
if ( ! V_231 -> V_72 ) {
F_50 ( L_204 ) ;
free ( V_231 ) ;
return V_359 ;
}
V_379 = & ( V_231 -> V_236 ) ;
va_start ( V_380 , V_72 ) ;
for (; ; ) {
type = va_arg ( V_380 , enum V_377 ) ;
if ( type == V_381 )
break;
if ( type >= V_382 ) {
F_50 ( L_205 , type ) ;
V_125 = V_383 ;
goto V_41;
}
V_233 = malloc ( sizeof( * V_233 ) ) ;
if ( ! V_233 ) {
F_50 ( L_206 ) ;
V_125 = V_359 ;
goto V_41;
}
V_233 -> type = type ;
V_233 -> V_22 = NULL ;
* V_379 = V_233 ;
V_379 = & ( V_233 -> V_22 ) ;
V_231 -> V_186 ++ ;
}
va_end ( V_380 ) ;
V_231 -> V_22 = V_14 -> V_184 ;
V_14 -> V_184 = V_231 ;
return 0 ;
V_41:
va_end ( V_380 ) ;
F_96 ( V_231 ) ;
return V_125 ;
}
int F_198 ( struct V_14 * V_14 ,
T_3 V_35 , char * V_72 )
{
struct V_182 * V_231 ;
V_231 = F_94 ( V_14 , V_72 ) ;
if ( V_231 && V_231 -> V_35 == V_35 ) {
F_95 ( V_14 , V_72 ) ;
return 0 ;
}
return - 1 ;
}
static struct V_52 * F_199 ( struct V_14 * V_14 , int V_56 ,
const char * V_352 ,
const char * V_353 )
{
struct V_52 * V_53 ;
if ( V_56 >= 0 ) {
V_53 = F_115 ( V_14 , V_56 ) ;
if ( ! V_53 )
return NULL ;
if ( V_353 && ( strcmp ( V_353 , V_53 -> V_72 ) != 0 ) )
return NULL ;
if ( V_352 && ( strcmp ( V_352 , V_53 -> system ) != 0 ) )
return NULL ;
} else {
V_53 = F_116 ( V_14 , V_352 , V_353 ) ;
if ( ! V_53 )
return NULL ;
}
return V_53 ;
}
int F_200 ( struct V_14 * V_14 , int V_56 ,
const char * V_352 , const char * V_353 ,
T_5 V_35 , void * V_317 )
{
struct V_52 * V_53 ;
struct V_354 * V_355 ;
V_53 = F_199 ( V_14 , V_56 , V_352 , V_353 ) ;
if ( V_53 == NULL )
goto V_384;
F_181 ( L_194 ,
V_53 -> V_56 , V_53 -> system , V_53 -> V_72 ) ;
V_53 -> V_315 = V_35 ;
V_53 -> V_317 = V_317 ;
return 0 ;
V_384:
V_355 = calloc ( 1 , sizeof( * V_355 ) ) ;
if ( ! V_355 ) {
F_50 ( L_207 ) ;
return V_359 ;
}
V_355 -> V_56 = V_56 ;
if ( V_353 )
V_355 -> V_353 = F_12 ( V_353 ) ;
if ( V_352 )
V_355 -> V_352 = F_12 ( V_352 ) ;
if ( ( V_353 && ! V_355 -> V_353 ) ||
( V_352 && ! V_355 -> V_352 ) ) {
F_50 ( L_208 ) ;
free ( ( void * ) V_355 -> V_353 ) ;
free ( ( void * ) V_355 -> V_352 ) ;
free ( V_355 ) ;
return V_359 ;
}
V_355 -> V_35 = V_35 ;
V_355 -> V_22 = V_14 -> V_356 ;
V_14 -> V_356 = V_355 ;
V_355 -> V_317 = V_317 ;
return - 1 ;
}
static int F_201 ( struct V_354 * V_315 , int V_56 ,
const char * V_352 , const char * V_353 ,
T_5 V_35 , void * V_317 )
{
if ( V_56 >= 0 && V_56 != V_315 -> V_56 )
return 0 ;
if ( V_353 && ( strcmp ( V_353 , V_315 -> V_353 ) != 0 ) )
return 0 ;
if ( V_352 && ( strcmp ( V_352 , V_315 -> V_352 ) != 0 ) )
return 0 ;
if ( V_35 != V_315 -> V_35 || V_317 != V_315 -> V_317 )
return 0 ;
return 1 ;
}
int F_202 ( struct V_14 * V_14 , int V_56 ,
const char * V_352 , const char * V_353 ,
T_5 V_35 , void * V_317 )
{
struct V_52 * V_53 ;
struct V_354 * V_355 ;
struct V_354 * * V_22 ;
V_53 = F_199 ( V_14 , V_56 , V_352 , V_353 ) ;
if ( V_53 == NULL )
goto V_384;
if ( V_53 -> V_315 == V_35 && V_53 -> V_317 == V_317 ) {
F_181 ( L_209 ,
V_53 -> V_56 , V_53 -> system , V_53 -> V_72 ) ;
V_53 -> V_315 = NULL ;
V_53 -> V_317 = NULL ;
return 0 ;
}
V_384:
for ( V_22 = & V_14 -> V_356 ; * V_22 ; V_22 = & ( * V_22 ) -> V_22 ) {
V_355 = * V_22 ;
if ( F_201 ( V_355 , V_56 , V_352 , V_353 ,
V_35 , V_317 ) )
break;
}
if ( ! ( * V_22 ) )
return - 1 ;
* V_22 = V_355 -> V_22 ;
F_179 ( V_355 ) ;
return 0 ;
}
struct V_14 * F_203 ( void )
{
struct V_14 * V_14 = calloc ( 1 , sizeof( * V_14 ) ) ;
if ( V_14 )
V_14 -> V_385 = 1 ;
return V_14 ;
}
void F_204 ( struct V_14 * V_14 )
{
V_14 -> V_385 ++ ;
}
void F_205 ( struct V_127 * V_71 )
{
free ( V_71 -> type ) ;
if ( V_71 -> V_137 != V_71 -> V_72 )
free ( V_71 -> V_137 ) ;
free ( V_71 -> V_72 ) ;
free ( V_71 ) ;
}
static void F_206 ( struct V_127 * V_71 )
{
struct V_127 * V_22 ;
while ( V_71 ) {
V_22 = V_71 -> V_22 ;
F_205 ( V_71 ) ;
V_71 = V_22 ;
}
}
static void F_207 ( struct V_151 * V_151 )
{
F_206 ( V_151 -> V_152 ) ;
F_206 ( V_151 -> V_130 ) ;
}
void F_185 ( struct V_52 * V_53 )
{
free ( V_53 -> V_72 ) ;
free ( V_53 -> system ) ;
F_207 ( & V_53 -> V_151 ) ;
free ( V_53 -> V_188 . V_151 ) ;
F_130 ( V_53 -> V_188 . args ) ;
free ( V_53 ) ;
}
void F_208 ( struct V_14 * V_14 )
{
struct V_15 * V_16 , * V_386 ;
struct V_32 * V_33 , * V_387 ;
struct V_46 * V_47 , * V_388 ;
struct V_182 * V_389 ;
struct V_354 * V_355 ;
int V_19 ;
if ( ! V_14 )
return;
V_16 = V_14 -> V_16 ;
V_33 = V_14 -> V_33 ;
V_47 = V_14 -> V_47 ;
V_14 -> V_385 -- ;
if ( V_14 -> V_385 )
return;
if ( V_14 -> V_18 ) {
for ( V_19 = 0 ; V_19 < V_14 -> V_20 ; V_19 ++ )
free ( V_14 -> V_18 [ V_19 ] . V_21 ) ;
free ( V_14 -> V_18 ) ;
}
while ( V_16 ) {
V_386 = V_16 -> V_22 ;
free ( V_16 -> V_21 ) ;
free ( V_16 ) ;
V_16 = V_386 ;
}
if ( V_14 -> V_28 ) {
for ( V_19 = 0 ; V_19 < ( int ) V_14 -> V_34 ; V_19 ++ ) {
free ( V_14 -> V_28 [ V_19 ] . V_35 ) ;
free ( V_14 -> V_28 [ V_19 ] . V_36 ) ;
}
free ( V_14 -> V_28 ) ;
}
while ( V_33 ) {
V_387 = V_33 -> V_22 ;
free ( V_33 -> V_35 ) ;
free ( V_33 -> V_36 ) ;
free ( V_33 ) ;
V_33 = V_387 ;
}
while ( V_14 -> V_184 ) {
V_389 = V_14 -> V_184 ;
V_14 -> V_184 = V_389 -> V_22 ;
F_96 ( V_389 ) ;
}
if ( V_14 -> V_43 ) {
for ( V_19 = 0 ; V_19 < ( int ) V_14 -> V_48 ; V_19 ++ )
free ( V_14 -> V_43 [ V_19 ] . V_49 ) ;
free ( V_14 -> V_43 ) ;
}
while ( V_47 ) {
V_388 = V_47 -> V_22 ;
free ( V_47 -> V_49 ) ;
free ( V_47 ) ;
V_47 = V_388 ;
}
for ( V_19 = 0 ; V_19 < V_14 -> V_55 ; V_19 ++ )
F_185 ( V_14 -> V_54 [ V_19 ] ) ;
while ( V_14 -> V_356 ) {
V_355 = V_14 -> V_356 ;
V_14 -> V_356 = V_355 -> V_22 ;
F_179 ( V_355 ) ;
}
free ( V_14 -> V_27 ) ;
free ( V_14 -> V_54 ) ;
free ( V_14 -> V_336 ) ;
free ( V_14 -> V_38 ) ;
free ( V_14 ) ;
}
void F_209 ( struct V_14 * V_14 )
{
F_208 ( V_14 ) ;
}
