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
case V_92 :
free ( V_66 -> V_93 . V_94 ) ;
break;
case V_95 :
free ( V_66 -> V_96 . V_96 ) ;
F_35 ( V_66 -> V_96 . V_97 ) ;
F_35 ( V_66 -> V_96 . V_98 ) ;
break;
case V_99 :
while ( V_66 -> V_35 . args ) {
V_67 = V_66 -> V_35 . args ;
V_66 -> V_35 . args = V_67 -> V_22 ;
F_35 ( V_67 ) ;
}
break;
case V_100 :
default:
break;
}
free ( V_66 ) ;
}
static enum V_57 F_36 ( int V_101 )
{
if ( V_101 == '\n' )
return V_102 ;
if ( isspace ( V_101 ) )
return V_103 ;
if ( isalnum ( V_101 ) || V_101 == '_' )
return V_58 ;
if ( V_101 == '\'' )
return V_59 ;
if ( V_101 == '"' )
return V_104 ;
if ( ! isprint ( V_101 ) )
return V_105 ;
if ( V_101 == '(' || V_101 == ')' || V_101 == ',' )
return V_61 ;
return V_106 ;
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
static int F_40 ( char * * V_107 , char * V_1 , int V_2 )
{
char * V_108 = realloc ( * V_107 , V_2 ) ;
if ( ! V_108 ) {
free ( * V_107 ) ;
* V_107 = NULL ;
return - 1 ;
}
if ( ! * V_107 )
strcpy ( V_108 , V_1 ) ;
else
strcat ( V_108 , V_1 ) ;
* V_107 = V_108 ;
return 0 ;
}
static enum V_57 F_41 ( char * * V_107 )
{
char V_1 [ V_109 ] ;
int V_101 , V_110 , V_111 , V_112 ;
int V_19 = 0 ;
int V_113 = 0 ;
enum V_57 type ;
* V_107 = NULL ;
V_101 = F_37 () ;
if ( V_101 < 0 )
return V_105 ;
type = F_36 ( V_101 ) ;
if ( type == V_105 )
return type ;
V_1 [ V_19 ++ ] = V_101 ;
switch ( type ) {
case V_102 :
case V_61 :
if ( F_42 ( V_107 , L_9 , V_101 ) < 0 )
return V_60 ;
return type ;
case V_106 :
switch ( V_101 ) {
case '-' :
V_112 = F_38 () ;
if ( V_112 == '>' ) {
V_1 [ V_19 ++ ] = F_37 () ;
break;
}
case '+' :
case '|' :
case '&' :
case '>' :
case '<' :
V_110 = V_101 ;
V_101 = F_38 () ;
if ( V_101 != V_110 )
goto V_114;
V_1 [ V_19 ++ ] = F_37 () ;
switch ( V_110 ) {
case '>' :
case '<' :
goto V_114;
default:
break;
}
break;
case '!' :
case '=' :
goto V_114;
default:
break;
}
V_1 [ V_19 ] = 0 ;
* V_107 = F_12 ( V_1 ) ;
return type ;
V_114:
V_101 = F_38 () ;
if ( V_101 == '=' )
V_1 [ V_19 ++ ] = F_37 () ;
goto V_115;
case V_104 :
case V_59 :
V_19 -- ;
V_111 = V_101 ;
V_110 = 0 ;
V_116:
do {
if ( V_19 == ( V_109 - 1 ) ) {
V_1 [ V_19 ] = 0 ;
V_113 += V_109 ;
if ( F_40 ( V_107 , V_1 , V_113 ) < 0 )
return V_105 ;
V_19 = 0 ;
}
V_110 = V_101 ;
V_101 = F_37 () ;
V_1 [ V_19 ++ ] = V_101 ;
if ( V_101 == '\\' && V_110 == '\\' )
V_110 = 0 ;
} while ( V_101 != V_111 || V_110 == '\\' );
V_19 -- ;
if ( type == V_104 ) {
unsigned long long V_117 = V_5 ;
do {
V_101 = F_37 () ;
} while ( isspace ( V_101 ) );
if ( V_101 == '"' )
goto V_116;
V_5 = V_117 ;
}
goto V_115;
case V_60 ... V_103 :
case V_58 :
default:
break;
}
while ( F_36 ( F_38 () ) == type ) {
if ( V_19 == ( V_109 - 1 ) ) {
V_1 [ V_19 ] = 0 ;
V_113 += V_109 ;
if ( F_40 ( V_107 , V_1 , V_113 ) < 0 )
return V_105 ;
V_19 = 0 ;
}
V_101 = F_37 () ;
V_1 [ V_19 ++ ] = V_101 ;
}
V_115:
V_1 [ V_19 ] = 0 ;
if ( F_40 ( V_107 , V_1 , V_113 + V_19 + 1 ) < 0 )
return V_105 ;
if ( type == V_58 ) {
if ( strcmp ( * V_107 , L_10 ) == 0 ) {
free ( * V_107 ) ;
* V_107 = NULL ;
return F_43 ( L_11 , V_107 ) ;
} else if ( strcmp ( * V_107 , L_12 ) == 0 ) {
free ( * V_107 ) ;
* V_107 = NULL ;
return F_43 ( L_13 , V_107 ) ;
} else if ( strcmp ( * V_107 , L_14 ) == 0 ) {
free ( * V_107 ) ;
* V_107 = NULL ;
return F_43 ( L_15 , V_107 ) ;
}
}
return type ;
}
static enum V_57 F_43 ( const char * V_65 , char * * V_107 )
{
const char * V_118 ;
unsigned long long V_117 ;
unsigned long long V_119 ;
enum V_57 type ;
V_118 = V_3 ;
V_117 = V_5 ;
V_119 = V_4 ;
F_1 ( V_65 , strlen ( V_65 ) ) ;
type = F_41 ( V_107 ) ;
V_3 = V_118 ;
V_5 = V_117 ;
V_4 = V_119 ;
return type ;
}
static void F_44 ( char * V_107 )
{
if ( V_107 )
free ( V_107 ) ;
}
static enum V_57 F_45 ( char * * V_107 )
{
enum V_57 type ;
for (; ; ) {
type = F_41 ( V_107 ) ;
if ( type != V_103 )
return type ;
F_44 ( * V_107 ) ;
}
* V_107 = NULL ;
return V_105 ;
}
enum V_57 F_46 ( char * * V_107 )
{
return F_45 ( V_107 ) ;
}
void F_47 ( char * V_120 )
{
F_44 ( V_120 ) ;
}
static enum V_57 F_48 ( char * * V_107 )
{
enum V_57 type ;
for (; ; ) {
type = F_41 ( V_107 ) ;
if ( type != V_103 && type != V_102 )
return type ;
F_44 ( * V_107 ) ;
* V_107 = NULL ;
}
* V_107 = NULL ;
return V_105 ;
}
static int F_49 ( enum V_57 type , enum V_57 V_121 )
{
if ( type != V_121 ) {
F_50 ( L_16 ,
V_121 , type ) ;
return - 1 ;
}
return 0 ;
}
static int F_51 ( enum V_57 type , const char * V_120 ,
enum V_57 V_121 , const char * V_122 )
{
if ( type != V_121 ) {
F_50 ( L_16 ,
V_121 , type ) ;
return - 1 ;
}
if ( strcmp ( V_120 , V_122 ) != 0 ) {
F_50 ( L_17 ,
V_122 , V_120 ) ;
return - 1 ;
}
return 0 ;
}
static int F_52 ( enum V_57 V_121 , char * * V_107 , int V_123 )
{
enum V_57 type ;
if ( V_123 )
type = F_45 ( V_107 ) ;
else
type = F_48 ( V_107 ) ;
return F_49 ( type , V_121 ) ;
}
static int F_53 ( enum V_57 V_121 , char * * V_107 )
{
return F_52 ( V_121 , V_107 , 1 ) ;
}
static int F_54 ( enum V_57 V_121 , const char * V_65 ,
int V_123 )
{
enum V_57 type ;
char * V_120 ;
int V_124 ;
if ( V_123 )
type = F_45 ( & V_120 ) ;
else
type = F_48 ( & V_120 ) ;
V_124 = F_51 ( type , V_120 , V_121 , V_65 ) ;
F_44 ( V_120 ) ;
return V_124 ;
}
static int F_55 ( enum V_57 V_121 , const char * V_65 )
{
return F_54 ( V_121 , V_65 , 1 ) ;
}
static int F_56 ( enum V_57 V_121 , const char * V_65 )
{
return F_54 ( V_121 , V_65 , 0 ) ;
}
static char * F_57 ( void )
{
char * V_120 ;
if ( F_55 ( V_58 , L_18 ) < 0 )
return NULL ;
if ( F_55 ( V_106 , L_19 ) < 0 )
return NULL ;
if ( F_53 ( V_58 , & V_120 ) < 0 )
goto V_125;
return V_120 ;
V_125:
F_44 ( V_120 ) ;
return NULL ;
}
static int F_58 ( void )
{
char * V_120 ;
int V_56 ;
if ( F_56 ( V_58 , L_20 ) < 0 )
return - 1 ;
if ( F_55 ( V_106 , L_19 ) < 0 )
return - 1 ;
if ( F_53 ( V_58 , & V_120 ) < 0 )
goto V_125;
V_56 = strtoul ( V_120 , NULL , 0 ) ;
F_44 ( V_120 ) ;
return V_56 ;
V_125:
F_44 ( V_120 ) ;
return - 1 ;
}
static int F_59 ( struct V_126 * V_71 )
{
if ( ( V_71 -> V_74 & V_127 ) &&
( strstr ( V_71 -> type , L_21 ) || strstr ( V_71 -> type , L_22 ) ||
strstr ( V_71 -> type , L_23 ) ) )
return 1 ;
return 0 ;
}
static int F_60 ( struct V_126 * V_71 )
{
if ( strncmp ( V_71 -> type , L_24 , 10 ) == 0 )
return 1 ;
return 0 ;
}
static int F_61 ( struct V_126 * V_71 )
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
} V_128 [] = {
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
for ( V_19 = 0 ; V_128 [ V_19 ] . type ; V_19 ++ ) {
if ( ! strcmp ( V_128 [ V_19 ] . type , V_72 ) )
return V_128 [ V_19 ] . V_2 ;
}
return 0 ;
}
static int F_63 ( struct V_52 * V_53 , struct V_126 * * V_129 )
{
struct V_126 * V_71 = NULL ;
enum V_57 type ;
char * V_120 ;
char * V_130 ;
int V_83 = 0 ;
do {
unsigned int V_131 = 0 ;
type = F_45 ( & V_120 ) ;
if ( type == V_102 ) {
F_44 ( V_120 ) ;
return V_83 ;
}
V_83 ++ ;
if ( F_51 ( type , V_120 , V_58 , L_32 ) )
goto V_125;
F_44 ( V_120 ) ;
type = F_45 ( & V_120 ) ;
if ( V_53 -> V_74 & V_132 &&
type == V_58 && strcmp ( V_120 , L_33 ) == 0 ) {
F_44 ( V_120 ) ;
type = F_45 ( & V_120 ) ;
}
if ( F_51 ( type , V_120 , V_106 , L_19 ) < 0 )
goto V_125;
F_44 ( V_120 ) ;
if ( F_53 ( V_58 , & V_120 ) < 0 )
goto V_125;
V_130 = V_120 ;
V_71 = calloc ( 1 , sizeof( * V_71 ) ) ;
if ( ! V_71 )
goto V_125;
V_71 -> V_53 = V_53 ;
for (; ; ) {
type = F_45 ( & V_120 ) ;
if ( type == V_58 ||
( type == V_106 && strcmp ( V_120 , L_34 ) == 0 ) ||
( V_53 -> V_74 & V_132 &&
type == V_106 && strcmp ( V_120 , L_35 ) == 0 ) ) {
if ( strcmp ( V_120 , L_34 ) == 0 )
V_71 -> V_74 |= V_133 ;
if ( V_71 -> type ) {
char * V_134 ;
V_134 = realloc ( V_71 -> type ,
strlen ( V_71 -> type ) +
strlen ( V_130 ) + 2 ) ;
if ( ! V_134 ) {
free ( V_130 ) ;
goto V_125;
}
V_71 -> type = V_134 ;
strcat ( V_71 -> type , L_36 ) ;
strcat ( V_71 -> type , V_130 ) ;
free ( V_130 ) ;
} else
V_71 -> type = V_130 ;
V_130 = V_120 ;
continue;
}
break;
}
if ( ! V_71 -> type ) {
F_64 ( V_53 , L_37 , V_135 ) ;
goto V_125;
}
V_71 -> V_72 = V_71 -> V_136 = V_130 ;
if ( F_49 ( type , V_106 ) )
goto V_125;
if ( strcmp ( V_120 , L_38 ) == 0 ) {
enum V_57 V_137 = type ;
char * V_138 = V_120 ;
char * V_139 ;
int V_140 ;
V_71 -> V_74 |= V_127 ;
type = F_45 ( & V_120 ) ;
if ( type == V_58 )
V_71 -> V_141 = strtoul ( V_120 , NULL , 0 ) ;
else
V_71 -> V_141 = 0 ;
while ( strcmp ( V_120 , L_39 ) != 0 ) {
if ( V_137 == V_58 &&
type == V_58 )
V_140 = 2 ;
else
V_140 = 1 ;
V_137 = type ;
V_139 = realloc ( V_138 ,
strlen ( V_138 ) +
strlen ( V_120 ) + V_140 ) ;
if ( ! V_139 ) {
free ( V_138 ) ;
goto V_125;
}
V_138 = V_139 ;
if ( V_140 == 2 )
strcat ( V_138 , L_36 ) ;
strcat ( V_138 , V_120 ) ;
V_71 -> V_141 = strtoul ( V_120 , NULL , 0 ) ;
F_44 ( V_120 ) ;
type = F_45 ( & V_120 ) ;
if ( type == V_105 ) {
F_64 ( V_53 , L_40 ) ;
goto V_125;
}
}
F_44 ( V_120 ) ;
V_139 = realloc ( V_138 , strlen ( V_138 ) + 2 ) ;
if ( ! V_139 ) {
free ( V_138 ) ;
goto V_125;
}
V_138 = V_139 ;
strcat ( V_138 , L_39 ) ;
type = F_45 ( & V_120 ) ;
if ( type == V_58 ) {
char * V_134 ;
V_134 = realloc ( V_71 -> type ,
strlen ( V_71 -> type ) +
strlen ( V_71 -> V_72 ) +
strlen ( V_138 ) + 2 ) ;
if ( ! V_134 ) {
free ( V_138 ) ;
goto V_125;
}
V_71 -> type = V_134 ;
strcat ( V_71 -> type , L_36 ) ;
strcat ( V_71 -> type , V_71 -> V_72 ) ;
V_131 = F_62 ( V_71 -> V_72 ) ;
F_44 ( V_71 -> V_72 ) ;
strcat ( V_71 -> type , V_138 ) ;
V_71 -> V_72 = V_71 -> V_136 = V_120 ;
type = F_45 ( & V_120 ) ;
} else {
char * V_134 ;
V_134 = realloc ( V_71 -> type ,
strlen ( V_71 -> type ) +
strlen ( V_138 ) + 1 ) ;
if ( ! V_134 ) {
free ( V_138 ) ;
goto V_125;
}
V_71 -> type = V_134 ;
strcat ( V_71 -> type , V_138 ) ;
}
free ( V_138 ) ;
}
if ( F_59 ( V_71 ) )
V_71 -> V_74 |= V_142 ;
if ( F_60 ( V_71 ) )
V_71 -> V_74 |= V_143 ;
if ( F_61 ( V_71 ) )
V_71 -> V_74 |= V_144 ;
if ( F_51 ( type , V_120 , V_106 , L_41 ) )
goto V_125;
F_44 ( V_120 ) ;
if ( F_55 ( V_58 , L_42 ) < 0 )
goto V_145;
if ( F_55 ( V_106 , L_19 ) < 0 )
goto V_145;
if ( F_53 ( V_58 , & V_120 ) )
goto V_125;
V_71 -> V_146 = strtoul ( V_120 , NULL , 0 ) ;
F_44 ( V_120 ) ;
if ( F_55 ( V_106 , L_41 ) < 0 )
goto V_145;
if ( F_55 ( V_58 , L_43 ) < 0 )
goto V_145;
if ( F_55 ( V_106 , L_19 ) < 0 )
goto V_145;
if ( F_53 ( V_58 , & V_120 ) )
goto V_125;
V_71 -> V_2 = strtoul ( V_120 , NULL , 0 ) ;
F_44 ( V_120 ) ;
if ( F_55 ( V_106 , L_41 ) < 0 )
goto V_145;
type = F_45 ( & V_120 ) ;
if ( type != V_102 ) {
if ( F_51 ( type , V_120 , V_58 , L_44 ) )
goto V_125;
F_44 ( V_120 ) ;
if ( F_55 ( V_106 , L_19 ) < 0 )
goto V_145;
if ( F_53 ( V_58 , & V_120 ) )
goto V_125;
if ( strtoul ( V_120 , NULL , 0 ) )
V_71 -> V_74 |= V_147 ;
F_44 ( V_120 ) ;
if ( F_55 ( V_106 , L_41 ) < 0 )
goto V_145;
if ( F_53 ( V_102 , & V_120 ) )
goto V_125;
}
F_44 ( V_120 ) ;
if ( V_71 -> V_74 & V_127 ) {
if ( V_71 -> V_141 )
V_71 -> V_148 = V_71 -> V_2 / V_71 -> V_141 ;
else if ( V_71 -> V_74 & V_143 )
V_71 -> V_148 = V_131 ;
else if ( V_71 -> V_74 & V_142 )
V_71 -> V_148 = 1 ;
else if ( V_71 -> V_74 & V_144 )
V_71 -> V_148 = V_53 -> V_14 ?
V_53 -> V_14 -> V_149 :
sizeof( long ) ;
} else
V_71 -> V_148 = V_71 -> V_2 ;
* V_129 = V_71 ;
V_129 = & V_71 -> V_22 ;
} while ( 1 );
return 0 ;
V_125:
F_44 ( V_120 ) ;
V_145:
if ( V_71 ) {
free ( V_71 -> type ) ;
free ( V_71 -> V_72 ) ;
free ( V_71 ) ;
}
return - 1 ;
}
static int F_65 ( struct V_52 * V_53 )
{
char * V_120 ;
int V_124 ;
if ( F_56 ( V_58 , L_45 ) < 0 )
return - 1 ;
if ( F_55 ( V_106 , L_19 ) < 0 )
return - 1 ;
if ( F_53 ( V_102 , & V_120 ) )
goto V_125;
F_44 ( V_120 ) ;
V_124 = F_63 ( V_53 , & V_53 -> V_150 . V_151 ) ;
if ( V_124 < 0 )
return V_124 ;
V_53 -> V_150 . V_152 = V_124 ;
V_124 = F_63 ( V_53 , & V_53 -> V_150 . V_129 ) ;
if ( V_124 < 0 )
return V_124 ;
V_53 -> V_150 . V_153 = V_124 ;
return 0 ;
V_125:
F_44 ( V_120 ) ;
return - 1 ;
}
static enum V_57
F_66 ( struct V_52 * V_53 , struct V_7 * V_66 , char * * V_107 )
{
enum V_57 type ;
char * V_120 ;
type = F_45 ( & V_120 ) ;
* V_107 = V_120 ;
return F_67 ( V_53 , V_66 , V_107 , type ) ;
}
static enum V_57
F_68 ( struct V_52 * V_53 , struct V_7 * V_66 , char * * V_107 )
{
enum V_57 type ;
type = F_66 ( V_53 , V_66 , V_107 ) ;
while ( type == V_106 ) {
type = F_69 ( V_53 , V_66 , V_107 ) ;
}
return type ;
}
static enum V_57
F_70 ( struct V_52 * V_53 , struct V_7 * V_154 , char * * V_107 )
{
struct V_7 * V_66 , * V_97 , * V_98 ;
enum V_57 type ;
char * V_120 = NULL ;
V_66 = F_6 () ;
V_97 = F_6 () ;
V_98 = F_6 () ;
if ( ! V_66 || ! V_97 || ! V_98 ) {
F_64 ( V_53 , L_46 , V_135 ) ;
F_35 ( V_97 ) ;
F_35 ( V_98 ) ;
goto V_41;
}
V_66 -> type = V_95 ;
V_66 -> V_96 . V_97 = V_97 ;
V_66 -> V_96 . V_98 = V_98 ;
* V_107 = NULL ;
type = F_66 ( V_53 , V_97 , & V_120 ) ;
V_155:
if ( type == V_60 )
goto V_41;
if ( type == V_106 && strcmp ( V_120 , L_19 ) != 0 ) {
type = F_69 ( V_53 , V_97 , & V_120 ) ;
goto V_155;
}
if ( F_51 ( type , V_120 , V_106 , L_19 ) )
goto V_41;
V_66 -> V_96 . V_96 = V_120 ;
type = F_66 ( V_53 , V_98 , & V_120 ) ;
V_154 -> V_96 . V_98 = V_66 ;
* V_107 = V_120 ;
return type ;
V_41:
V_154 -> V_96 . V_98 = NULL ;
F_44 ( V_120 ) ;
F_35 ( V_66 ) ;
return V_60 ;
}
static enum V_57
F_71 ( struct V_52 * V_53 , struct V_7 * V_154 , char * * V_107 )
{
struct V_7 * V_66 ;
enum V_57 type ;
char * V_120 = NULL ;
V_66 = F_6 () ;
if ( ! V_66 ) {
F_64 ( V_53 , L_46 , V_135 ) ;
* V_107 = NULL ;
return V_60 ;
}
* V_107 = NULL ;
type = F_66 ( V_53 , V_66 , & V_120 ) ;
if ( F_51 ( type , V_120 , V_106 , L_39 ) )
goto V_41;
V_154 -> V_96 . V_98 = V_66 ;
F_44 ( V_120 ) ;
type = F_48 ( & V_120 ) ;
* V_107 = V_120 ;
return type ;
V_41:
F_44 ( V_120 ) ;
F_35 ( V_66 ) ;
return V_60 ;
}
static int F_72 ( char * V_96 )
{
if ( ! V_96 [ 1 ] ) {
switch ( V_96 [ 0 ] ) {
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
F_50 ( L_47 , V_96 [ 0 ] ) ;
return - 1 ;
}
} else {
if ( strcmp ( V_96 , L_48 ) == 0 ||
strcmp ( V_96 , L_49 ) == 0 ) {
return 3 ;
} else if ( strcmp ( V_96 , L_50 ) == 0 ||
strcmp ( V_96 , L_51 ) == 0 ) {
return 8 ;
} else if ( strcmp ( V_96 , L_52 ) == 0 ||
strcmp ( V_96 , L_53 ) == 0 ) {
return 9 ;
} else if ( strcmp ( V_96 , L_54 ) == 0 ||
strcmp ( V_96 , L_55 ) == 0 ) {
return 10 ;
} else if ( strcmp ( V_96 , L_56 ) == 0 ) {
return 14 ;
} else if ( strcmp ( V_96 , L_57 ) == 0 ) {
return 15 ;
} else {
F_50 ( L_58 , V_96 ) ;
return - 1 ;
}
}
}
static int F_73 ( struct V_7 * V_66 )
{
if ( ! V_66 -> V_96 . V_97 || V_66 -> V_96 . V_97 -> type == V_100 )
V_66 -> V_96 . V_156 = 0 ;
else
V_66 -> V_96 . V_156 = F_72 ( V_66 -> V_96 . V_96 ) ;
return V_66 -> V_96 . V_156 ;
}
static enum V_57
F_69 ( struct V_52 * V_53 , struct V_7 * V_66 , char * * V_107 )
{
struct V_7 * V_97 , * V_98 = NULL ;
enum V_57 type ;
char * V_120 ;
V_120 = * V_107 ;
if ( V_66 -> type == V_95 && ! V_66 -> V_96 . V_97 ) {
if ( V_120 [ 1 ] ) {
F_64 ( V_53 , L_59 , V_120 ) ;
goto V_41;
}
switch ( V_120 [ 0 ] ) {
case '~' :
case '!' :
case '+' :
case '-' :
break;
default:
F_64 ( V_53 , L_59 , V_120 ) ;
goto V_41;
}
V_97 = F_6 () ;
if ( ! V_97 )
goto V_157;
V_97 -> type = V_100 ;
V_66 -> V_96 . V_97 = V_97 ;
V_98 = F_6 () ;
if ( ! V_98 )
goto V_157;
V_66 -> V_96 . V_98 = V_98 ;
* V_107 = NULL ;
type = F_66 ( V_53 , V_98 , V_107 ) ;
} else if ( strcmp ( V_120 , L_60 ) == 0 ) {
V_97 = F_6 () ;
if ( ! V_97 )
goto V_157;
* V_97 = * V_66 ;
V_66 -> type = V_95 ;
V_66 -> V_96 . V_96 = V_120 ;
V_66 -> V_96 . V_97 = V_97 ;
V_66 -> V_96 . V_156 = 0 ;
type = F_70 ( V_53 , V_66 , V_107 ) ;
} else if ( strcmp ( V_120 , L_50 ) == 0 ||
strcmp ( V_120 , L_51 ) == 0 ||
strcmp ( V_120 , L_61 ) == 0 ||
strcmp ( V_120 , L_62 ) == 0 ||
strcmp ( V_120 , L_56 ) == 0 ||
strcmp ( V_120 , L_57 ) == 0 ||
strcmp ( V_120 , L_63 ) == 0 ||
strcmp ( V_120 , L_64 ) == 0 ||
strcmp ( V_120 , L_34 ) == 0 ||
strcmp ( V_120 , L_65 ) == 0 ||
strcmp ( V_120 , L_66 ) == 0 ||
strcmp ( V_120 , L_67 ) == 0 ||
strcmp ( V_120 , L_68 ) == 0 ||
strcmp ( V_120 , L_53 ) == 0 ||
strcmp ( V_120 , L_52 ) == 0 ||
strcmp ( V_120 , L_54 ) == 0 ||
strcmp ( V_120 , L_55 ) == 0 ) {
V_97 = F_6 () ;
if ( ! V_97 )
goto V_157;
* V_97 = * V_66 ;
V_66 -> type = V_95 ;
V_66 -> V_96 . V_96 = V_120 ;
V_66 -> V_96 . V_97 = V_97 ;
V_66 -> V_96 . V_98 = NULL ;
if ( F_73 ( V_66 ) == - 1 ) {
V_53 -> V_74 |= V_158 ;
V_66 -> V_96 . V_96 = NULL ;
goto V_41;
}
type = F_48 ( & V_120 ) ;
* V_107 = V_120 ;
if ( ( strcmp ( V_66 -> V_96 . V_96 , L_34 ) == 0 ) &&
type == V_61 && ( strcmp ( V_120 , L_69 ) == 0 ) ) {
char * V_159 ;
if ( V_97 -> type != V_68 ) {
F_64 ( V_53 , L_70 ) ;
goto V_41;
}
V_159 = realloc ( V_97 -> V_69 . V_69 ,
strlen ( V_97 -> V_69 . V_69 ) + 3 ) ;
if ( ! V_159 )
goto V_157;
V_97 -> V_69 . V_69 = V_159 ;
strcat ( V_97 -> V_69 . V_69 , L_71 ) ;
free ( V_66 -> V_96 . V_96 ) ;
* V_66 = * V_97 ;
free ( V_97 ) ;
return type ;
}
V_98 = F_6 () ;
if ( ! V_98 )
goto V_157;
type = F_67 ( V_53 , V_98 , V_107 , type ) ;
if ( type == V_60 ) {
F_35 ( V_98 ) ;
V_120 = NULL ;
goto V_41;
}
if ( V_98 -> type == V_95 &&
F_72 ( V_66 -> V_96 . V_96 ) < F_72 ( V_98 -> V_96 . V_96 ) ) {
struct V_7 V_160 ;
V_66 -> V_96 . V_98 = V_98 -> V_96 . V_97 ;
V_160 = * V_66 ;
* V_66 = * V_98 ;
* V_98 = V_160 ;
V_66 -> V_96 . V_97 = V_98 ;
} else {
V_66 -> V_96 . V_98 = V_98 ;
}
} else if ( strcmp ( V_120 , L_38 ) == 0 ) {
V_97 = F_6 () ;
if ( ! V_97 )
goto V_157;
* V_97 = * V_66 ;
V_66 -> type = V_95 ;
V_66 -> V_96 . V_96 = V_120 ;
V_66 -> V_96 . V_97 = V_97 ;
V_66 -> V_96 . V_156 = 0 ;
type = F_71 ( V_53 , V_66 , V_107 ) ;
} else {
F_64 ( V_53 , L_58 , V_120 ) ;
V_53 -> V_74 |= V_158 ;
goto V_41;
}
if ( type == V_106 && strcmp ( * V_107 , L_19 ) != 0 ) {
int V_156 ;
V_156 = F_72 ( * V_107 ) ;
if ( V_156 > V_66 -> V_96 . V_156 )
return F_69 ( V_53 , V_66 , V_107 ) ;
return F_69 ( V_53 , V_98 , V_107 ) ;
}
return type ;
V_157:
F_64 ( V_53 , L_46 , V_135 ) ;
V_41:
F_44 ( V_120 ) ;
* V_107 = NULL ;
return V_60 ;
}
static enum V_57
F_74 ( struct V_52 * V_53 V_161 , struct V_7 * V_66 ,
char * * V_107 )
{
enum V_57 type ;
char * V_71 ;
char * V_120 ;
if ( F_55 ( V_106 , L_72 ) < 0 )
goto V_162;
if ( F_53 ( V_58 , & V_120 ) < 0 )
goto V_41;
V_71 = V_120 ;
V_66 -> type = V_70 ;
V_66 -> V_71 . V_72 = V_71 ;
if ( V_163 ) {
V_66 -> V_71 . V_71 = F_75 ( V_53 , V_66 -> V_71 . V_72 ) ;
V_66 -> V_71 . V_71 -> V_74 |= V_164 ;
V_163 = 0 ;
} else if ( V_165 ) {
V_66 -> V_71 . V_71 = F_75 ( V_53 , V_66 -> V_71 . V_72 ) ;
V_66 -> V_71 . V_71 -> V_74 |= V_166 ;
V_165 = 0 ;
}
type = F_45 ( & V_120 ) ;
* V_107 = V_120 ;
return type ;
V_41:
F_44 ( V_120 ) ;
V_162:
* V_107 = NULL ;
return V_60 ;
}
static int F_76 ( struct V_52 * V_53 , char * V_167 ,
struct V_7 * * V_7 )
{
struct V_7 * V_71 ;
enum V_57 type ;
char * V_120 ;
int V_124 = 0 ;
V_71 = F_6 () ;
if ( ! V_71 ) {
F_64 ( V_53 , L_46 , V_135 ) ;
V_24 = V_26 ;
return - 1 ;
}
type = F_66 ( V_53 , V_71 , & V_120 ) ;
if ( F_51 ( type , V_120 , V_61 , V_167 ) ) {
V_24 = V_168 ;
V_124 = - 1 ;
F_35 ( V_71 ) ;
goto V_169;
}
* V_7 = V_71 ;
V_169:
F_44 ( V_120 ) ;
return V_124 ;
}
static unsigned long long
F_77 ( unsigned long long V_170 , const char * type , int V_171 )
{
int V_172 = 0 ;
char * V_173 ;
int V_140 ;
V_140 = strlen ( type ) ;
if ( V_171 ) {
if ( type [ V_140 - 1 ] != '*' ) {
F_50 ( L_73 ) ;
return V_170 ;
}
V_173 = malloc ( V_140 ) ;
if ( ! V_173 ) {
F_50 ( L_46 , V_135 ) ;
return V_170 ;
}
memcpy ( V_173 , type , V_140 ) ;
V_173 [ V_140 - 2 ] = 0 ;
V_170 = F_77 ( V_170 , V_173 , 0 ) ;
free ( V_173 ) ;
return V_170 ;
}
if ( type [ V_140 - 1 ] == '*' )
return V_170 ;
if ( strncmp ( type , L_74 , 6 ) == 0 )
return V_170 ;
if ( strcmp ( type , L_22 ) == 0 )
return V_170 & 0xff ;
if ( strcmp ( type , L_26 ) == 0 )
return V_170 & 0xffff ;
if ( strcmp ( type , L_27 ) == 0 )
return V_170 & 0xffffffff ;
if ( strcmp ( type , L_28 ) == 0 ||
strcmp ( type , L_31 ) )
return V_170 ;
if ( strcmp ( type , L_23 ) == 0 )
return ( unsigned long long ) ( char ) V_170 & 0xff ;
if ( strcmp ( type , L_29 ) == 0 )
return ( unsigned long long ) ( short ) V_170 & 0xffff ;
if ( strcmp ( type , L_30 ) == 0 )
return ( unsigned long long ) ( int ) V_170 & 0xffffffff ;
if ( strncmp ( type , L_75 , 9 ) == 0 ) {
V_172 = 0 ;
type += 9 ;
}
if ( strcmp ( type , L_21 ) == 0 ) {
if ( V_172 )
return ( unsigned long long ) ( char ) V_170 & 0xff ;
else
return V_170 & 0xff ;
}
if ( strcmp ( type , L_76 ) == 0 ) {
if ( V_172 )
return ( unsigned long long ) ( short ) V_170 & 0xffff ;
else
return V_170 & 0xffff ;
}
if ( strcmp ( type , L_77 ) == 0 ) {
if ( V_172 )
return ( unsigned long long ) ( int ) V_170 & 0xffffffff ;
else
return V_170 & 0xffffffff ;
}
return V_170 ;
}
static unsigned long long
F_78 ( unsigned long long V_170 , struct V_7 * V_66 , int V_171 )
{
if ( V_66 -> type != V_85 ) {
F_50 ( L_78 ) ;
return 0 ;
}
return F_77 ( V_170 , V_66 -> V_86 . type , V_171 ) ;
}
static int F_79 ( struct V_7 * V_66 , long long * V_170 )
{
long long V_97 , V_98 ;
int V_124 = 1 ;
switch ( V_66 -> type ) {
case V_68 :
* V_170 = strtoll ( V_66 -> V_69 . V_69 , NULL , 0 ) ;
break;
case V_85 :
V_124 = F_79 ( V_66 -> V_86 . V_17 , V_170 ) ;
if ( ! V_124 )
break;
* V_170 = F_78 ( * V_170 , V_66 , 0 ) ;
break;
case V_95 :
switch ( V_66 -> V_96 . V_96 [ 0 ] ) {
case '|' :
V_124 = F_79 ( V_66 -> V_96 . V_97 , & V_97 ) ;
if ( ! V_124 )
break;
V_124 = F_79 ( V_66 -> V_96 . V_98 , & V_98 ) ;
if ( ! V_124 )
break;
if ( V_66 -> V_96 . V_96 [ 1 ] )
* V_170 = V_97 || V_98 ;
else
* V_170 = V_97 | V_98 ;
break;
case '&' :
V_124 = F_79 ( V_66 -> V_96 . V_97 , & V_97 ) ;
if ( ! V_124 )
break;
V_124 = F_79 ( V_66 -> V_96 . V_98 , & V_98 ) ;
if ( ! V_124 )
break;
if ( V_66 -> V_96 . V_96 [ 1 ] )
* V_170 = V_97 && V_98 ;
else
* V_170 = V_97 & V_98 ;
break;
case '<' :
V_124 = F_79 ( V_66 -> V_96 . V_97 , & V_97 ) ;
if ( ! V_124 )
break;
V_124 = F_79 ( V_66 -> V_96 . V_98 , & V_98 ) ;
if ( ! V_124 )
break;
switch ( V_66 -> V_96 . V_96 [ 1 ] ) {
case 0 :
* V_170 = V_97 < V_98 ;
break;
case '<' :
* V_170 = V_97 << V_98 ;
break;
case '=' :
* V_170 = V_97 <= V_98 ;
break;
default:
F_50 ( L_58 , V_66 -> V_96 . V_96 ) ;
V_124 = 0 ;
}
break;
case '>' :
V_124 = F_79 ( V_66 -> V_96 . V_97 , & V_97 ) ;
if ( ! V_124 )
break;
V_124 = F_79 ( V_66 -> V_96 . V_98 , & V_98 ) ;
if ( ! V_124 )
break;
switch ( V_66 -> V_96 . V_96 [ 1 ] ) {
case 0 :
* V_170 = V_97 > V_98 ;
break;
case '>' :
* V_170 = V_97 >> V_98 ;
break;
case '=' :
* V_170 = V_97 >= V_98 ;
break;
default:
F_50 ( L_58 , V_66 -> V_96 . V_96 ) ;
V_124 = 0 ;
}
break;
case '=' :
V_124 = F_79 ( V_66 -> V_96 . V_97 , & V_97 ) ;
if ( ! V_124 )
break;
V_124 = F_79 ( V_66 -> V_96 . V_98 , & V_98 ) ;
if ( ! V_124 )
break;
if ( V_66 -> V_96 . V_96 [ 1 ] != '=' ) {
F_50 ( L_58 , V_66 -> V_96 . V_96 ) ;
V_124 = 0 ;
} else
* V_170 = V_97 == V_98 ;
break;
case '!' :
V_124 = F_79 ( V_66 -> V_96 . V_97 , & V_97 ) ;
if ( ! V_124 )
break;
V_124 = F_79 ( V_66 -> V_96 . V_98 , & V_98 ) ;
if ( ! V_124 )
break;
switch ( V_66 -> V_96 . V_96 [ 1 ] ) {
case '=' :
* V_170 = V_97 != V_98 ;
break;
default:
F_50 ( L_58 , V_66 -> V_96 . V_96 ) ;
V_124 = 0 ;
}
break;
case '-' :
if ( V_66 -> V_96 . V_97 -> type == V_100 )
V_97 = 0 ;
else
V_124 = F_79 ( V_66 -> V_96 . V_97 , & V_97 ) ;
if ( ! V_124 )
break;
V_124 = F_79 ( V_66 -> V_96 . V_98 , & V_98 ) ;
if ( ! V_124 )
break;
* V_170 = V_97 - V_98 ;
break;
case '+' :
if ( V_66 -> V_96 . V_97 -> type == V_100 )
V_97 = 0 ;
else
V_124 = F_79 ( V_66 -> V_96 . V_97 , & V_97 ) ;
if ( ! V_124 )
break;
V_124 = F_79 ( V_66 -> V_96 . V_98 , & V_98 ) ;
if ( ! V_124 )
break;
* V_170 = V_97 + V_98 ;
break;
default:
F_50 ( L_58 , V_66 -> V_96 . V_96 ) ;
V_124 = 0 ;
}
break;
case V_100 :
case V_70 ... V_76 :
case V_87 :
case V_88 :
case V_89 :
default:
F_50 ( L_79 , V_66 -> type ) ;
V_124 = 0 ;
}
return V_124 ;
}
static char * F_80 ( struct V_7 * V_66 )
{
long long V_170 ;
static char V_1 [ 20 ] ;
switch ( V_66 -> type ) {
case V_68 :
return V_66 -> V_69 . V_69 ;
case V_85 :
return F_80 ( V_66 -> V_86 . V_17 ) ;
case V_95 :
if ( ! F_79 ( V_66 , & V_170 ) )
break;
sprintf ( V_1 , L_80 , V_170 ) ;
return V_1 ;
case V_100 :
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
F_81 ( struct V_52 * V_53 , struct V_62 * * V_174 , char * * V_107 )
{
enum V_57 type ;
struct V_7 * V_66 = NULL ;
struct V_62 * V_71 ;
char * V_120 = * V_107 ;
char * V_64 ;
do {
F_44 ( V_120 ) ;
type = F_48 ( & V_120 ) ;
if ( F_51 ( type , V_120 , V_106 , L_81 ) )
break;
V_66 = F_6 () ;
if ( ! V_66 )
goto V_41;
F_44 ( V_120 ) ;
type = F_66 ( V_53 , V_66 , & V_120 ) ;
if ( type == V_106 )
type = F_69 ( V_53 , V_66 , & V_120 ) ;
if ( type == V_60 )
goto V_41;
if ( F_51 ( type , V_120 , V_61 , L_82 ) )
goto V_41;
V_71 = calloc ( 1 , sizeof( * V_71 ) ) ;
if ( ! V_71 )
goto V_41;
V_64 = F_80 ( V_66 ) ;
if ( V_64 == NULL )
goto V_175;
V_71 -> V_64 = F_12 ( V_64 ) ;
if ( V_71 -> V_64 == NULL )
goto V_175;
F_35 ( V_66 ) ;
V_66 = F_6 () ;
if ( ! V_66 )
goto V_41;
F_44 ( V_120 ) ;
type = F_66 ( V_53 , V_66 , & V_120 ) ;
if ( F_51 ( type , V_120 , V_106 , L_83 ) )
goto V_175;
V_64 = F_80 ( V_66 ) ;
if ( V_64 == NULL )
goto V_175;
V_71 -> V_65 = F_12 ( V_64 ) ;
if ( V_71 -> V_65 == NULL )
goto V_175;
F_35 ( V_66 ) ;
V_66 = NULL ;
* V_174 = V_71 ;
V_174 = & V_71 -> V_22 ;
F_44 ( V_120 ) ;
type = F_48 ( & V_120 ) ;
} while ( type == V_61 && strcmp ( V_120 , L_82 ) == 0 );
* V_107 = V_120 ;
return type ;
V_175:
F_34 ( V_71 ) ;
V_41:
F_35 ( V_66 ) ;
F_44 ( V_120 ) ;
* V_107 = NULL ;
return V_60 ;
}
static enum V_57
F_82 ( struct V_52 * V_53 , struct V_7 * V_66 , char * * V_107 )
{
struct V_7 * V_71 ;
enum V_57 type ;
char * V_120 = NULL ;
memset ( V_66 , 0 , sizeof( * V_66 ) ) ;
V_66 -> type = V_73 ;
V_71 = F_6 () ;
if ( ! V_71 ) {
F_64 ( V_53 , L_46 , V_135 ) ;
goto V_41;
}
type = F_68 ( V_53 , V_71 , & V_120 ) ;
while ( type == V_106 )
type = F_69 ( V_53 , V_71 , & V_120 ) ;
if ( F_51 ( type , V_120 , V_61 , L_82 ) )
goto V_175;
F_44 ( V_120 ) ;
V_66 -> V_74 . V_71 = V_71 ;
type = F_48 ( & V_120 ) ;
if ( F_33 ( type ) ) {
V_66 -> V_74 . V_75 = V_120 ;
type = F_48 ( & V_120 ) ;
}
if ( F_51 ( type , V_120 , V_61 , L_82 ) )
goto V_41;
type = F_81 ( V_53 , & V_66 -> V_74 . V_74 , & V_120 ) ;
if ( F_51 ( type , V_120 , V_61 , L_69 ) )
goto V_41;
F_44 ( V_120 ) ;
type = F_48 ( V_107 ) ;
return type ;
V_175:
F_35 ( V_71 ) ;
V_41:
F_44 ( V_120 ) ;
* V_107 = NULL ;
return V_60 ;
}
static enum V_57
F_83 ( struct V_52 * V_53 , struct V_7 * V_66 , char * * V_107 )
{
struct V_7 * V_71 ;
enum V_57 type ;
char * V_120 = NULL ;
memset ( V_66 , 0 , sizeof( * V_66 ) ) ;
V_66 -> type = V_76 ;
V_71 = F_6 () ;
if ( ! V_71 ) {
F_64 ( V_53 , L_46 , V_135 ) ;
goto V_41;
}
type = F_68 ( V_53 , V_71 , & V_120 ) ;
if ( F_51 ( type , V_120 , V_61 , L_82 ) )
goto V_175;
V_66 -> V_77 . V_71 = V_71 ;
type = F_81 ( V_53 , & V_66 -> V_77 . V_78 , & V_120 ) ;
if ( F_51 ( type , V_120 , V_61 , L_69 ) )
goto V_41;
F_44 ( V_120 ) ;
type = F_48 ( V_107 ) ;
return type ;
V_175:
F_35 ( V_71 ) ;
V_41:
F_44 ( V_120 ) ;
* V_107 = NULL ;
return V_60 ;
}
static enum V_57
F_84 ( struct V_52 * V_53 , struct V_7 * V_66 , char * * V_107 )
{
memset ( V_66 , 0 , sizeof( * V_66 ) ) ;
V_66 -> type = V_79 ;
if ( F_76 ( V_53 , L_82 , & V_66 -> V_80 . V_71 ) )
goto V_115;
if ( F_76 ( V_53 , L_69 , & V_66 -> V_80 . V_2 ) )
goto V_176;
return F_48 ( V_107 ) ;
V_176:
F_35 ( V_66 -> V_80 . V_71 ) ;
V_115:
* V_107 = NULL ;
return V_60 ;
}
static enum V_57
F_85 ( struct V_52 * V_53 , struct V_7 * V_66 , char * * V_107 )
{
memset ( V_66 , 0 , sizeof( * V_66 ) ) ;
V_66 -> type = V_81 ;
if ( F_76 ( V_53 , L_82 , & V_66 -> V_82 . V_71 ) )
goto V_115;
if ( F_76 ( V_53 , L_82 , & V_66 -> V_82 . V_83 ) )
goto V_176;
if ( F_76 ( V_53 , L_69 , & V_66 -> V_82 . V_84 ) )
goto V_177;
return F_48 ( V_107 ) ;
V_177:
F_35 ( V_66 -> V_82 . V_83 ) ;
V_176:
F_35 ( V_66 -> V_82 . V_71 ) ;
V_115:
* V_107 = NULL ;
return V_60 ;
}
static enum V_57
F_86 ( struct V_52 * V_53 , struct V_7 * V_66 , char * * V_107 )
{
struct V_126 * V_71 ;
enum V_57 type ;
char * V_120 ;
memset ( V_66 , 0 , sizeof( * V_66 ) ) ;
V_66 -> type = V_91 ;
type = F_45 ( & V_120 ) ;
* V_107 = V_120 ;
if ( type != V_58 )
goto V_41;
V_71 = F_87 ( V_53 , V_120 ) ;
if ( ! V_71 )
goto V_41;
V_66 -> V_93 . V_71 = V_71 ;
V_66 -> V_93 . V_94 = 0 ;
if ( F_55 ( V_61 , L_69 ) < 0 )
goto V_41;
F_44 ( V_120 ) ;
type = F_48 ( & V_120 ) ;
* V_107 = V_120 ;
if ( type != V_106 || strcmp ( V_120 , L_38 ) != 0 )
return type ;
F_44 ( V_120 ) ;
V_66 = F_6 () ;
if ( ! V_66 ) {
F_64 ( V_53 , L_46 , V_135 ) ;
* V_107 = NULL ;
return V_60 ;
}
type = F_66 ( V_53 , V_66 , & V_120 ) ;
if ( type == V_60 )
goto V_178;
if ( ! F_51 ( type , V_120 , V_106 , L_39 ) )
goto V_178;
F_44 ( V_120 ) ;
type = F_48 ( V_107 ) ;
return type ;
V_178:
F_35 ( V_66 ) ;
V_41:
F_44 ( V_120 ) ;
* V_107 = NULL ;
return V_60 ;
}
static enum V_57
F_88 ( struct V_52 * V_53 , struct V_7 * V_66 ,
char * * V_107 )
{
struct V_126 * V_71 ;
enum V_57 type ;
char * V_120 ;
if ( F_53 ( V_58 , & V_120 ) < 0 )
goto V_41;
V_66 -> type = V_92 ;
V_71 = F_87 ( V_53 , V_120 ) ;
if ( ! V_71 )
goto V_41;
V_66 -> V_93 . V_71 = V_71 ;
V_66 -> V_93 . V_94 = 0 ;
if ( F_55 ( V_61 , L_69 ) < 0 )
goto V_162;
type = F_45 ( & V_120 ) ;
* V_107 = V_120 ;
return type ;
V_41:
F_44 ( V_120 ) ;
V_162:
* V_107 = NULL ;
return V_60 ;
}
static enum V_57
F_89 ( struct V_52 * V_53 , struct V_7 * V_66 , char * * V_107 )
{
struct V_7 * V_179 ;
enum V_57 type ;
char * V_120 ;
type = F_66 ( V_53 , V_66 , & V_120 ) ;
if ( type == V_60 )
goto V_41;
if ( type == V_106 )
type = F_69 ( V_53 , V_66 , & V_120 ) ;
if ( type == V_60 )
goto V_41;
if ( F_51 ( type , V_120 , V_61 , L_69 ) )
goto V_41;
F_44 ( V_120 ) ;
type = F_48 ( & V_120 ) ;
if ( F_33 ( type ) ||
( type == V_61 && strcmp ( V_120 , L_84 ) == 0 ) ) {
if ( V_66 -> type != V_68 ) {
F_64 ( V_53 , L_85 ) ;
goto V_41;
}
V_179 = F_6 () ;
if ( ! V_179 ) {
F_64 ( V_53 , L_46 ,
V_135 ) ;
goto V_41;
}
V_66 -> type = V_85 ;
V_66 -> V_86 . type = V_66 -> V_69 . V_69 ;
V_66 -> V_86 . V_17 = V_179 ;
type = F_67 ( V_53 , V_179 , & V_120 , type ) ;
}
* V_107 = V_120 ;
return type ;
V_41:
F_44 ( V_120 ) ;
* V_107 = NULL ;
return V_60 ;
}
static enum V_57
F_90 ( struct V_52 * V_53 V_161 , struct V_7 * V_66 ,
char * * V_107 )
{
enum V_57 type ;
char * V_120 ;
if ( F_53 ( V_58 , & V_120 ) < 0 )
goto V_41;
V_66 -> type = V_87 ;
V_66 -> string . string = V_120 ;
V_66 -> string . V_146 = - 1 ;
if ( F_55 ( V_61 , L_69 ) < 0 )
goto V_162;
type = F_45 ( & V_120 ) ;
* V_107 = V_120 ;
return type ;
V_41:
F_44 ( V_120 ) ;
V_162:
* V_107 = NULL ;
return V_60 ;
}
static enum V_57
F_91 ( struct V_52 * V_53 V_161 , struct V_7 * V_66 ,
char * * V_107 )
{
enum V_57 type ;
char * V_120 ;
if ( F_53 ( V_58 , & V_120 ) < 0 )
goto V_41;
V_66 -> type = V_89 ;
V_66 -> V_90 . V_90 = V_120 ;
V_66 -> V_90 . V_146 = - 1 ;
if ( F_55 ( V_61 , L_69 ) < 0 )
goto V_162;
type = F_45 ( & V_120 ) ;
* V_107 = V_120 ;
return type ;
V_41:
F_44 ( V_120 ) ;
V_162:
* V_107 = NULL ;
return V_60 ;
}
static struct V_180 *
F_92 ( struct V_14 * V_14 , char * V_181 )
{
struct V_180 * V_35 ;
if ( ! V_14 )
return NULL ;
for ( V_35 = V_14 -> V_182 ; V_35 ; V_35 = V_35 -> V_22 ) {
if ( strcmp ( V_35 -> V_72 , V_181 ) == 0 )
break;
}
return V_35 ;
}
static void F_93 ( struct V_14 * V_14 , char * V_181 )
{
struct V_180 * V_35 ;
struct V_180 * * V_22 ;
V_22 = & V_14 -> V_182 ;
while ( ( V_35 = * V_22 ) ) {
if ( strcmp ( V_35 -> V_72 , V_181 ) == 0 ) {
* V_22 = V_35 -> V_22 ;
F_94 ( V_35 ) ;
break;
}
V_22 = & V_35 -> V_22 ;
}
}
static enum V_57
F_95 ( struct V_52 * V_53 , struct V_180 * V_35 ,
struct V_7 * V_66 , char * * V_107 )
{
struct V_7 * * V_183 ;
struct V_7 * V_67 ;
enum V_57 type ;
char * V_120 ;
int V_19 ;
V_66 -> type = V_99 ;
V_66 -> V_35 . V_35 = V_35 ;
* V_107 = NULL ;
V_183 = & ( V_66 -> V_35 . args ) ;
for ( V_19 = 0 ; V_19 < V_35 -> V_184 ; V_19 ++ ) {
V_67 = F_6 () ;
if ( ! V_67 ) {
F_64 ( V_53 , L_46 ,
V_135 ) ;
return V_60 ;
}
type = F_66 ( V_53 , V_67 , & V_120 ) ;
if ( V_19 < ( V_35 -> V_184 - 1 ) ) {
if ( type != V_61 || strcmp ( V_120 , L_82 ) != 0 ) {
F_64 ( V_53 ,
L_86 ,
V_35 -> V_72 , V_35 -> V_184 ,
V_53 -> V_72 , V_19 + 1 ) ;
goto V_185;
}
} else {
if ( type != V_61 || strcmp ( V_120 , L_69 ) != 0 ) {
F_64 ( V_53 ,
L_87 ,
V_35 -> V_72 , V_35 -> V_184 , V_53 -> V_72 ) ;
goto V_185;
}
}
* V_183 = V_67 ;
V_183 = & ( V_67 -> V_22 ) ;
F_44 ( V_120 ) ;
}
type = F_45 ( & V_120 ) ;
* V_107 = V_120 ;
return type ;
V_185:
F_35 ( V_67 ) ;
F_44 ( V_120 ) ;
return V_60 ;
}
static enum V_57
F_96 ( struct V_52 * V_53 , struct V_7 * V_66 ,
char * V_120 , char * * V_107 )
{
struct V_180 * V_35 ;
if ( strcmp ( V_120 , L_88 ) == 0 ) {
F_44 ( V_120 ) ;
V_163 = 1 ;
return F_82 ( V_53 , V_66 , V_107 ) ;
}
if ( strcmp ( V_120 , L_89 ) == 0 ) {
F_44 ( V_120 ) ;
V_165 = 1 ;
return F_83 ( V_53 , V_66 , V_107 ) ;
}
if ( strcmp ( V_120 , L_90 ) == 0 ) {
F_44 ( V_120 ) ;
return F_84 ( V_53 , V_66 , V_107 ) ;
}
if ( strcmp ( V_120 , L_91 ) == 0 ) {
F_44 ( V_120 ) ;
return F_85 ( V_53 , V_66 , V_107 ) ;
}
if ( strcmp ( V_120 , L_92 ) == 0 ) {
F_44 ( V_120 ) ;
return F_90 ( V_53 , V_66 , V_107 ) ;
}
if ( strcmp ( V_120 , L_93 ) == 0 ) {
F_44 ( V_120 ) ;
return F_91 ( V_53 , V_66 , V_107 ) ;
}
if ( strcmp ( V_120 , L_94 ) == 0 ) {
F_44 ( V_120 ) ;
return F_86 ( V_53 , V_66 , V_107 ) ;
}
if ( strcmp ( V_120 , L_95 ) == 0 ) {
F_44 ( V_120 ) ;
return F_88 ( V_53 , V_66 , V_107 ) ;
}
V_35 = F_92 ( V_53 -> V_14 , V_120 ) ;
if ( V_35 ) {
F_44 ( V_120 ) ;
return F_95 ( V_53 , V_35 , V_66 , V_107 ) ;
}
F_64 ( V_53 , L_96 , V_120 ) ;
F_44 ( V_120 ) ;
return V_60 ;
}
static enum V_57
F_67 ( struct V_52 * V_53 , struct V_7 * V_66 ,
char * * V_107 , enum V_57 type )
{
char * V_120 ;
char * V_69 ;
V_120 = * V_107 ;
switch ( type ) {
case V_58 :
if ( strcmp ( V_120 , L_97 ) == 0 ) {
F_44 ( V_120 ) ;
type = F_74 ( V_53 , V_66 , & V_120 ) ;
break;
}
V_69 = V_120 ;
type = F_48 ( & V_120 ) ;
if ( type == V_61 && strcmp ( V_120 , L_84 ) == 0 ) {
F_44 ( V_120 ) ;
V_120 = NULL ;
type = F_96 ( V_53 , V_66 , V_69 , & V_120 ) ;
break;
}
while ( type == V_58 ) {
char * V_159 ;
V_159 = realloc ( V_69 ,
strlen ( V_69 ) + strlen ( V_120 ) + 2 ) ;
if ( ! V_159 ) {
free ( V_69 ) ;
* V_107 = NULL ;
F_44 ( V_120 ) ;
return V_60 ;
}
V_69 = V_159 ;
strcat ( V_69 , L_36 ) ;
strcat ( V_69 , V_120 ) ;
F_44 ( V_120 ) ;
type = F_48 ( & V_120 ) ;
}
V_66 -> type = V_68 ;
V_66 -> V_69 . V_69 = V_69 ;
break;
case V_104 :
case V_59 :
V_66 -> type = V_68 ;
V_66 -> V_69 . V_69 = V_120 ;
type = F_48 ( & V_120 ) ;
break;
case V_61 :
if ( strcmp ( V_120 , L_84 ) == 0 ) {
F_44 ( V_120 ) ;
type = F_89 ( V_53 , V_66 , & V_120 ) ;
break;
}
case V_106 :
V_66 -> type = V_95 ;
V_66 -> V_96 . V_96 = V_120 ;
V_66 -> V_96 . V_97 = NULL ;
type = F_69 ( V_53 , V_66 , & V_120 ) ;
if ( type == V_60 )
V_66 -> V_96 . V_96 = NULL ;
break;
case V_60 ... V_102 :
default:
F_64 ( V_53 , L_98 , type ) ;
return V_60 ;
}
* V_107 = V_120 ;
return type ;
}
static int F_97 ( struct V_52 * V_53 , struct V_7 * * V_174 )
{
enum V_57 type = V_60 ;
struct V_7 * V_66 ;
char * V_120 ;
int args = 0 ;
do {
if ( type == V_102 ) {
type = F_48 ( & V_120 ) ;
continue;
}
V_66 = F_6 () ;
if ( ! V_66 ) {
F_64 ( V_53 , L_46 ,
V_135 ) ;
return - 1 ;
}
type = F_66 ( V_53 , V_66 , & V_120 ) ;
if ( type == V_60 ) {
F_44 ( V_120 ) ;
F_35 ( V_66 ) ;
return - 1 ;
}
* V_174 = V_66 ;
args ++ ;
if ( type == V_106 ) {
type = F_69 ( V_53 , V_66 , & V_120 ) ;
F_44 ( V_120 ) ;
if ( type == V_60 ) {
* V_174 = NULL ;
F_35 ( V_66 ) ;
return - 1 ;
}
V_174 = & V_66 -> V_22 ;
continue;
}
if ( type == V_61 && strcmp ( V_120 , L_82 ) == 0 ) {
F_44 ( V_120 ) ;
* V_174 = V_66 ;
V_174 = & V_66 -> V_22 ;
continue;
}
break;
} while ( type != V_105 );
if ( type != V_105 && type != V_60 )
F_44 ( V_120 ) ;
return args ;
}
static int F_98 ( struct V_52 * V_53 )
{
enum V_57 type ;
char * V_120 ;
int V_124 ;
if ( F_56 ( V_58 , L_99 ) < 0 )
return - 1 ;
if ( F_55 ( V_58 , L_100 ) < 0 )
return - 1 ;
if ( F_55 ( V_106 , L_19 ) < 0 )
return - 1 ;
if ( F_53 ( V_104 , & V_120 ) < 0 )
goto V_125;
V_116:
V_53 -> V_186 . V_150 = V_120 ;
V_53 -> V_186 . args = NULL ;
type = F_48 ( & V_120 ) ;
if ( type == V_105 )
return 0 ;
if ( type == V_104 ) {
char * V_187 ;
if ( F_42 ( & V_187 , L_101 , V_53 -> V_186 . V_150 , V_120 ) < 0 )
goto V_125;
F_44 ( V_120 ) ;
F_44 ( V_53 -> V_186 . V_150 ) ;
V_53 -> V_186 . V_150 = NULL ;
V_120 = V_187 ;
goto V_116;
}
if ( F_51 ( type , V_120 , V_61 , L_82 ) )
goto V_125;
F_44 ( V_120 ) ;
V_124 = F_97 ( V_53 , & V_53 -> V_186 . args ) ;
if ( V_124 < 0 )
return - 1 ;
return V_124 ;
V_125:
F_44 ( V_120 ) ;
return - 1 ;
}
struct V_126 *
F_99 ( struct V_52 * V_53 , const char * V_72 )
{
struct V_126 * V_150 ;
for ( V_150 = V_53 -> V_150 . V_151 ;
V_150 ; V_150 = V_150 -> V_22 ) {
if ( strcmp ( V_150 -> V_72 , V_72 ) == 0 )
break;
}
return V_150 ;
}
struct V_126 *
F_87 ( struct V_52 * V_53 , const char * V_72 )
{
struct V_126 * V_150 ;
for ( V_150 = V_53 -> V_150 . V_129 ;
V_150 ; V_150 = V_150 -> V_22 ) {
if ( strcmp ( V_150 -> V_72 , V_72 ) == 0 )
break;
}
return V_150 ;
}
struct V_126 *
F_75 ( struct V_52 * V_53 , const char * V_72 )
{
struct V_126 * V_150 ;
V_150 = F_99 ( V_53 , V_72 ) ;
if ( V_150 )
return V_150 ;
return F_87 ( V_53 , V_72 ) ;
}
unsigned long long F_100 ( struct V_14 * V_14 ,
const void * V_188 , int V_2 )
{
switch ( V_2 ) {
case 1 :
return * ( unsigned char * ) V_188 ;
case 2 :
return F_101 ( V_14 , V_188 ) ;
case 4 :
return F_102 ( V_14 , V_188 ) ;
case 8 :
return F_103 ( V_14 , V_188 ) ;
default:
return 0 ;
}
}
int F_104 ( struct V_126 * V_71 , const void * V_189 ,
unsigned long long * V_64 )
{
if ( ! V_71 )
return - 1 ;
switch ( V_71 -> V_2 ) {
case 1 :
case 2 :
case 4 :
case 8 :
* V_64 = F_100 ( V_71 -> V_53 -> V_14 ,
V_189 + V_71 -> V_146 , V_71 -> V_2 ) ;
return 0 ;
default:
return - 1 ;
}
}
static int F_105 ( struct V_14 * V_14 ,
const char * type , int * V_146 , int * V_2 )
{
struct V_52 * V_53 ;
struct V_126 * V_71 ;
if ( ! V_14 -> V_54 ) {
F_50 ( L_102 ) ;
return - 1 ;
}
V_53 = V_14 -> V_54 [ 0 ] ;
V_71 = F_99 ( V_53 , type ) ;
if ( ! V_71 )
return - 1 ;
* V_146 = V_71 -> V_146 ;
* V_2 = V_71 -> V_2 ;
return 0 ;
}
static int F_106 ( struct V_14 * V_14 , void * V_189 ,
int * V_2 , int * V_146 , const char * V_72 )
{
int V_124 ;
if ( ! * V_2 ) {
V_124 = F_105 ( V_14 , V_72 , V_146 , V_2 ) ;
if ( V_124 < 0 )
return V_124 ;
}
return F_100 ( V_14 , V_189 + * V_146 , * V_2 ) ;
}
static int F_107 ( struct V_14 * V_14 , void * V_189 )
{
return F_106 ( V_14 , V_189 ,
& V_14 -> F_62 , & V_14 -> V_190 ,
L_103 ) ;
}
static int F_108 ( struct V_14 * V_14 , void * V_189 )
{
return F_106 ( V_14 , V_189 ,
& V_14 -> V_191 , & V_14 -> V_192 ,
L_104 ) ;
}
static int F_109 ( struct V_14 * V_14 , void * V_189 )
{
return F_106 ( V_14 , V_189 ,
& V_14 -> V_193 , & V_14 -> V_194 ,
L_105 ) ;
}
static int F_110 ( struct V_14 * V_14 , void * V_189 )
{
return F_106 ( V_14 , V_189 ,
& V_14 -> V_195 , & V_14 -> V_196 ,
L_106 ) ;
}
static int F_111 ( struct V_14 * V_14 , void * V_189 )
{
return F_106 ( V_14 , V_189 ,
& V_14 -> V_197 , & V_14 -> V_198 ,
L_107 ) ;
}
static int F_112 ( struct V_14 * V_14 , void * V_189 )
{
return F_106 ( V_14 , V_189 ,
& V_14 -> V_197 , & V_14 -> V_198 ,
L_108 ) ;
}
struct V_52 * F_113 ( struct V_14 * V_14 , int V_56 )
{
struct V_52 * * V_199 ;
struct V_52 V_23 ;
struct V_52 * V_200 = & V_23 ;
if ( V_14 -> V_201 && V_14 -> V_201 -> V_56 == V_56 )
return V_14 -> V_201 ;
V_23 . V_56 = V_56 ;
V_199 = bsearch ( & V_200 , V_14 -> V_54 , V_14 -> V_55 ,
sizeof( * V_14 -> V_54 ) , V_202 ) ;
if ( V_199 ) {
V_14 -> V_201 = * V_199 ;
return * V_199 ;
}
return NULL ;
}
struct V_52 *
F_114 ( struct V_14 * V_14 ,
const char * V_203 , const char * V_72 )
{
struct V_52 * V_53 ;
int V_19 ;
if ( V_14 -> V_201 &&
strcmp ( V_14 -> V_201 -> V_72 , V_72 ) == 0 &&
( ! V_203 || strcmp ( V_14 -> V_201 -> system , V_203 ) == 0 ) )
return V_14 -> V_201 ;
for ( V_19 = 0 ; V_19 < V_14 -> V_55 ; V_19 ++ ) {
V_53 = V_14 -> V_54 [ V_19 ] ;
if ( strcmp ( V_53 -> V_72 , V_72 ) == 0 ) {
if ( ! V_203 )
break;
if ( strcmp ( V_53 -> system , V_203 ) == 0 )
break;
}
}
if ( V_19 == V_14 -> V_55 )
V_53 = NULL ;
V_14 -> V_201 = V_53 ;
return V_53 ;
}
static unsigned long long
F_115 ( void * V_189 , int V_2 , struct V_52 * V_53 , struct V_7 * V_66 )
{
struct V_14 * V_14 = V_53 -> V_14 ;
unsigned long long V_170 = 0 ;
unsigned long long V_97 , V_98 ;
struct V_7 * V_204 = NULL ;
struct V_7 * V_205 ;
unsigned long V_146 ;
unsigned int V_206 ;
switch ( V_66 -> type ) {
case V_100 :
return 0 ;
case V_68 :
return F_116 ( V_66 -> V_69 . V_69 , NULL , 0 ) ;
case V_70 :
if ( ! V_66 -> V_71 . V_71 ) {
V_66 -> V_71 . V_71 = F_75 ( V_53 , V_66 -> V_71 . V_72 ) ;
if ( ! V_66 -> V_71 . V_71 )
goto V_207;
}
V_170 = F_100 ( V_14 , V_189 + V_66 -> V_71 . V_71 -> V_146 ,
V_66 -> V_71 . V_71 -> V_2 ) ;
break;
case V_73 :
case V_76 :
case V_81 :
case V_79 :
break;
case V_85 :
V_170 = F_115 ( V_189 , V_2 , V_53 , V_66 -> V_86 . V_17 ) ;
return F_78 ( V_170 , V_66 , 0 ) ;
case V_87 :
case V_88 :
case V_89 :
return 0 ;
case V_99 : {
struct V_208 V_209 ;
F_117 ( & V_209 ) ;
V_170 = F_118 ( & V_209 , V_189 , V_2 , V_53 , V_66 ) ;
F_119 ( & V_209 ) ;
return V_170 ;
}
case V_95 :
if ( strcmp ( V_66 -> V_96 . V_96 , L_38 ) == 0 ) {
V_98 = F_115 ( V_189 , V_2 , V_53 , V_66 -> V_96 . V_98 ) ;
V_205 = V_66 -> V_96 . V_97 ;
while ( V_205 -> type == V_85 ) {
if ( ! V_204 )
V_204 = V_205 ;
V_205 = V_205 -> V_86 . V_17 ;
}
V_206 = V_14 -> V_149 ;
switch ( V_205 -> type ) {
case V_91 :
V_146 = F_100 ( V_14 ,
V_189 + V_205 -> V_93 . V_71 -> V_146 ,
V_205 -> V_93 . V_71 -> V_2 ) ;
if ( V_205 -> V_93 . V_71 -> V_148 )
V_206 = V_205 -> V_93 . V_71 -> V_148 ;
V_146 &= 0xffff ;
V_146 += V_98 ;
break;
case V_70 :
if ( ! V_205 -> V_71 . V_71 ) {
V_205 -> V_71 . V_71 =
F_75 ( V_53 , V_205 -> V_71 . V_72 ) ;
if ( ! V_205 -> V_71 . V_71 ) {
V_66 = V_205 ;
goto V_207;
}
}
V_206 = V_205 -> V_71 . V_71 -> V_148 ;
V_146 = V_205 -> V_71 . V_71 -> V_146 +
V_98 * V_205 -> V_71 . V_71 -> V_148 ;
break;
default:
goto V_210;
}
V_170 = F_100 ( V_14 ,
V_189 + V_146 , V_206 ) ;
if ( V_204 )
V_170 = F_78 ( V_170 , V_204 , 1 ) ;
break;
} else if ( strcmp ( V_66 -> V_96 . V_96 , L_60 ) == 0 ) {
V_97 = F_115 ( V_189 , V_2 , V_53 , V_66 -> V_96 . V_97 ) ;
V_66 = V_66 -> V_96 . V_98 ;
if ( V_97 )
V_170 = F_115 ( V_189 , V_2 , V_53 , V_66 -> V_96 . V_97 ) ;
else
V_170 = F_115 ( V_189 , V_2 , V_53 , V_66 -> V_96 . V_98 ) ;
break;
}
V_210:
V_97 = F_115 ( V_189 , V_2 , V_53 , V_66 -> V_96 . V_97 ) ;
V_98 = F_115 ( V_189 , V_2 , V_53 , V_66 -> V_96 . V_98 ) ;
switch ( V_66 -> V_96 . V_96 [ 0 ] ) {
case '!' :
switch ( V_66 -> V_96 . V_96 [ 1 ] ) {
case 0 :
V_170 = ! V_98 ;
break;
case '=' :
V_170 = V_97 != V_98 ;
break;
default:
goto V_211;
}
break;
case '~' :
V_170 = ~ V_98 ;
break;
case '|' :
if ( V_66 -> V_96 . V_96 [ 1 ] )
V_170 = V_97 || V_98 ;
else
V_170 = V_97 | V_98 ;
break;
case '&' :
if ( V_66 -> V_96 . V_96 [ 1 ] )
V_170 = V_97 && V_98 ;
else
V_170 = V_97 & V_98 ;
break;
case '<' :
switch ( V_66 -> V_96 . V_96 [ 1 ] ) {
case 0 :
V_170 = V_97 < V_98 ;
break;
case '<' :
V_170 = V_97 << V_98 ;
break;
case '=' :
V_170 = V_97 <= V_98 ;
break;
default:
goto V_211;
}
break;
case '>' :
switch ( V_66 -> V_96 . V_96 [ 1 ] ) {
case 0 :
V_170 = V_97 > V_98 ;
break;
case '>' :
V_170 = V_97 >> V_98 ;
break;
case '=' :
V_170 = V_97 >= V_98 ;
break;
default:
goto V_211;
}
break;
case '=' :
if ( V_66 -> V_96 . V_96 [ 1 ] != '=' )
goto V_211;
V_170 = V_97 == V_98 ;
break;
case '-' :
V_170 = V_97 - V_98 ;
break;
case '+' :
V_170 = V_97 + V_98 ;
break;
case '/' :
V_170 = V_97 / V_98 ;
break;
case '*' :
V_170 = V_97 * V_98 ;
break;
default:
goto V_211;
}
break;
case V_92 :
V_146 = F_100 ( V_14 ,
V_189 + V_66 -> V_93 . V_71 -> V_146 ,
V_66 -> V_93 . V_71 -> V_2 ) ;
V_170 = ( unsigned long long ) ( V_146 >> 16 ) ;
break;
case V_91 :
V_146 = F_100 ( V_14 ,
V_189 + V_66 -> V_93 . V_71 -> V_146 ,
V_66 -> V_93 . V_71 -> V_2 ) ;
V_146 &= 0xffff ;
V_170 = ( unsigned long long ) ( ( unsigned long ) V_189 + V_146 ) ;
break;
default:
return 0 ;
}
return V_170 ;
V_211:
F_64 ( V_53 , L_109 , V_135 , V_66 -> V_96 . V_96 ) ;
return 0 ;
V_207:
F_64 ( V_53 , L_110 ,
V_135 , V_66 -> V_71 . V_72 ) ;
return 0 ;
}
static long long F_120 ( const char * V_212 )
{
int V_19 ;
if ( isdigit ( V_212 [ 0 ] ) )
return F_116 ( V_212 , NULL , 0 ) ;
for ( V_19 = 0 ; V_19 < ( int ) ( sizeof( V_74 ) / sizeof( V_74 [ 0 ] ) ) ; V_19 ++ )
if ( strcmp ( V_74 [ V_19 ] . V_72 , V_212 ) == 0 )
return V_74 [ V_19 ] . V_64 ;
return - 1LL ;
}
static void F_121 ( struct V_208 * V_209 , const char * V_150 ,
int V_213 , const char * V_65 )
{
if ( V_213 >= 0 )
F_122 ( V_209 , V_150 , V_213 , V_65 ) ;
else
F_122 ( V_209 , V_150 , V_65 ) ;
}
static void F_123 ( struct V_14 * V_14 ,
struct V_208 * V_209 , const char * V_150 ,
int V_213 , const void * V_189 , int V_2 )
{
int V_214 = V_2 * 8 ;
int V_215 = ( V_214 + 3 ) / 4 ;
int V_140 = 0 ;
char V_1 [ 3 ] ;
char * V_65 ;
int V_94 ;
int V_19 ;
V_215 += ( V_214 - 1 ) / 32 ;
V_65 = malloc ( V_215 + 1 ) ;
if ( ! V_65 ) {
F_50 ( L_46 , V_135 ) ;
return;
}
V_65 [ V_215 ] = 0 ;
for ( V_19 = V_215 - 2 ; V_19 >= 0 ; V_19 -= 2 ) {
if ( V_14 -> V_216 )
V_94 = V_2 - ( V_140 + 1 ) ;
else
V_94 = V_140 ;
snprintf ( V_1 , 3 , L_111 , * ( ( unsigned char * ) V_189 + V_94 ) ) ;
memcpy ( V_65 + V_19 , V_1 , 2 ) ;
V_140 ++ ;
if ( ! ( V_140 & 3 ) && V_19 > 0 ) {
V_19 -- ;
V_65 [ V_19 ] = ',' ;
}
}
if ( V_213 >= 0 )
F_122 ( V_209 , V_150 , V_213 , V_65 ) ;
else
F_122 ( V_209 , V_150 , V_65 ) ;
free ( V_65 ) ;
}
static void F_124 ( struct V_208 * V_209 , void * V_189 , int V_2 ,
struct V_52 * V_53 , const char * V_150 ,
int V_213 , struct V_7 * V_66 )
{
struct V_14 * V_14 = V_53 -> V_14 ;
struct V_62 * V_212 ;
struct V_126 * V_71 ;
struct V_43 * V_49 ;
long long V_170 , V_217 ;
unsigned long long V_31 ;
char * V_65 ;
unsigned char * V_80 ;
int V_218 ;
int V_19 , V_140 ;
switch ( V_66 -> type ) {
case V_100 :
return;
case V_68 :
F_121 ( V_209 , V_150 , V_213 , V_66 -> V_69 . V_69 ) ;
return;
case V_70 :
V_71 = V_66 -> V_71 . V_71 ;
if ( ! V_71 ) {
V_71 = F_75 ( V_53 , V_66 -> V_71 . V_72 ) ;
if ( ! V_71 ) {
V_65 = V_66 -> V_71 . V_72 ;
goto V_207;
}
V_66 -> V_71 . V_71 = V_71 ;
}
V_140 = V_71 -> V_2 ? : V_2 - V_71 -> V_146 ;
if ( ! ( V_71 -> V_74 & V_127 ) &&
V_71 -> V_2 == V_14 -> V_149 ) {
V_31 = ( V_14 -> V_149 == 8 ) ?
* ( unsigned long long * ) ( V_189 + V_71 -> V_146 ) :
( unsigned long long ) * ( unsigned int * ) ( V_189 + V_71 -> V_146 ) ;
V_49 = F_28 ( V_14 , V_31 ) ;
if ( V_49 )
F_125 ( V_209 , V_49 -> V_49 ) ;
else
F_122 ( V_209 , L_112 , V_31 ) ;
break;
}
V_65 = malloc ( V_140 + 1 ) ;
if ( ! V_65 ) {
F_64 ( V_53 , L_46 ,
V_135 ) ;
return;
}
memcpy ( V_65 , V_189 + V_71 -> V_146 , V_140 ) ;
V_65 [ V_140 ] = 0 ;
F_121 ( V_209 , V_150 , V_213 , V_65 ) ;
free ( V_65 ) ;
break;
case V_73 :
V_170 = F_115 ( V_189 , V_2 , V_53 , V_66 -> V_74 . V_71 ) ;
V_218 = 0 ;
for ( V_212 = V_66 -> V_74 . V_74 ; V_212 ; V_212 = V_212 -> V_22 ) {
V_217 = F_120 ( V_212 -> V_64 ) ;
if ( ! V_170 && V_217 < 0 ) {
F_121 ( V_209 , V_150 , V_213 , V_212 -> V_65 ) ;
break;
}
if ( V_217 > 0 && ( V_170 & V_217 ) == V_217 ) {
if ( V_218 && V_66 -> V_74 . V_75 )
F_125 ( V_209 , V_66 -> V_74 . V_75 ) ;
F_121 ( V_209 , V_150 , V_213 , V_212 -> V_65 ) ;
V_218 = 1 ;
V_170 &= ~ V_217 ;
}
}
break;
case V_76 :
V_170 = F_115 ( V_189 , V_2 , V_53 , V_66 -> V_77 . V_71 ) ;
for ( V_212 = V_66 -> V_77 . V_78 ; V_212 ; V_212 = V_212 -> V_22 ) {
V_217 = F_120 ( V_212 -> V_64 ) ;
if ( V_170 == V_217 ) {
F_121 ( V_209 , V_150 , V_213 , V_212 -> V_65 ) ;
break;
}
}
break;
case V_79 :
if ( V_66 -> V_80 . V_71 -> type == V_91 ) {
unsigned long V_146 ;
V_146 = F_100 ( V_14 ,
V_189 + V_66 -> V_80 . V_71 -> V_93 . V_71 -> V_146 ,
V_66 -> V_80 . V_71 -> V_93 . V_71 -> V_2 ) ;
V_80 = V_189 + ( V_146 & 0xffff ) ;
} else {
V_71 = V_66 -> V_80 . V_71 -> V_71 . V_71 ;
if ( ! V_71 ) {
V_65 = V_66 -> V_80 . V_71 -> V_71 . V_72 ;
V_71 = F_75 ( V_53 , V_65 ) ;
if ( ! V_71 )
goto V_207;
V_66 -> V_80 . V_71 -> V_71 . V_71 = V_71 ;
}
V_80 = V_189 + V_71 -> V_146 ;
}
V_140 = F_115 ( V_189 , V_2 , V_53 , V_66 -> V_80 . V_2 ) ;
for ( V_19 = 0 ; V_19 < V_140 ; V_19 ++ ) {
if ( V_19 )
F_126 ( V_209 , ' ' ) ;
F_122 ( V_209 , L_111 , V_80 [ V_19 ] ) ;
}
break;
case V_81 : {
void * V_219 ;
int V_84 ;
if ( V_66 -> V_82 . V_71 -> type == V_91 ) {
unsigned long V_146 ;
struct V_126 * V_71 =
V_66 -> V_82 . V_71 -> V_93 . V_71 ;
V_146 = F_100 ( V_14 ,
V_189 + V_71 -> V_146 ,
V_71 -> V_2 ) ;
V_219 = V_189 + ( V_146 & 0xffff ) ;
} else {
V_71 = V_66 -> V_82 . V_71 -> V_71 . V_71 ;
if ( ! V_71 ) {
V_65 = V_66 -> V_82 . V_71 -> V_71 . V_72 ;
V_71 = F_75 ( V_53 , V_65 ) ;
if ( ! V_71 )
goto V_207;
V_66 -> V_82 . V_71 -> V_71 . V_71 = V_71 ;
}
V_219 = V_189 + V_71 -> V_146 ;
}
V_140 = F_115 ( V_189 , V_2 , V_53 , V_66 -> V_82 . V_83 ) ;
V_84 = F_115 ( V_189 , V_2 , V_53 ,
V_66 -> V_82 . V_84 ) ;
for ( V_19 = 0 ; V_19 < V_140 ; V_19 ++ ) {
if ( V_19 )
F_126 ( V_209 , ' ' ) ;
if ( V_84 == 1 ) {
F_122 ( V_209 , L_113 , * ( V_220 * ) V_219 ) ;
} else if ( V_84 == 2 ) {
F_122 ( V_209 , L_113 , * ( V_221 * ) V_219 ) ;
} else if ( V_84 == 4 ) {
F_122 ( V_209 , L_113 , * ( V_222 * ) V_219 ) ;
} else if ( V_84 == 8 ) {
F_122 ( V_209 , L_114 V_223 , * ( V_224 * ) V_219 ) ;
} else {
F_122 ( V_209 , L_115 ,
V_84 , * ( V_220 * ) V_219 ) ;
V_84 = 1 ;
}
V_219 += V_84 ;
}
break;
}
case V_85 :
break;
case V_87 : {
int V_225 ;
if ( V_66 -> string . V_146 == - 1 ) {
struct V_126 * V_226 ;
V_226 = F_75 ( V_53 , V_66 -> string . string ) ;
V_66 -> string . V_146 = V_226 -> V_146 ;
}
V_225 = F_102 ( V_14 , V_189 + V_66 -> string . V_146 ) ;
V_225 &= 0xffff ;
F_121 ( V_209 , V_150 , V_213 , ( ( char * ) V_189 ) + V_225 ) ;
break;
}
case V_88 :
F_121 ( V_209 , V_150 , V_213 , V_66 -> string . string ) ;
break;
case V_89 : {
int V_227 ;
int V_228 ;
if ( V_66 -> V_90 . V_146 == - 1 ) {
struct V_126 * V_226 ;
V_226 = F_75 ( V_53 , V_66 -> V_90 . V_90 ) ;
V_66 -> V_90 . V_146 = V_226 -> V_146 ;
}
V_227 = F_102 ( V_14 , V_189 + V_66 -> V_90 . V_146 ) ;
V_228 = V_227 >> 16 ;
V_227 &= 0xffff ;
F_123 ( V_14 , V_209 , V_150 , V_213 ,
V_189 + V_227 , V_228 ) ;
break;
}
case V_95 :
if ( V_66 -> V_96 . V_96 [ 0 ] != '?' )
return;
V_170 = F_115 ( V_189 , V_2 , V_53 , V_66 -> V_96 . V_97 ) ;
if ( V_170 )
F_124 ( V_209 , V_189 , V_2 , V_53 ,
V_150 , V_213 , V_66 -> V_96 . V_98 -> V_96 . V_97 ) ;
else
F_124 ( V_209 , V_189 , V_2 , V_53 ,
V_150 , V_213 , V_66 -> V_96 . V_98 -> V_96 . V_98 ) ;
break;
case V_99 :
F_118 ( V_209 , V_189 , V_2 , V_53 , V_66 ) ;
break;
default:
break;
}
return;
V_207:
F_64 ( V_53 , L_110 ,
V_135 , V_66 -> V_71 . V_72 ) ;
}
static unsigned long long
F_118 ( struct V_208 * V_209 , void * V_189 , int V_2 ,
struct V_52 * V_53 , struct V_7 * V_66 )
{
struct V_180 * V_229 = V_66 -> V_35 . V_35 ;
struct V_230 * V_231 ;
unsigned long long * args ;
unsigned long long V_124 ;
struct V_7 * V_67 ;
struct V_208 V_65 ;
struct V_232 {
struct V_232 * V_22 ;
char * V_65 ;
} * V_233 = NULL , * string ;
int V_19 ;
if ( ! V_229 -> V_184 ) {
V_124 = (* V_229 -> V_35 )( V_209 , NULL ) ;
goto V_115;
}
V_67 = V_66 -> V_35 . args ;
V_231 = V_229 -> V_234 ;
V_124 = V_235 ;
args = malloc ( sizeof( * args ) * V_229 -> V_184 ) ;
if ( ! args )
goto V_115;
for ( V_19 = 0 ; V_19 < V_229 -> V_184 ; V_19 ++ ) {
switch ( V_231 -> type ) {
case V_236 :
case V_237 :
case V_238 :
args [ V_19 ] = F_115 ( V_189 , V_2 , V_53 , V_67 ) ;
break;
case V_239 :
F_117 ( & V_65 ) ;
F_124 ( & V_65 , V_189 , V_2 , V_53 , L_116 , - 1 , V_67 ) ;
F_127 ( & V_65 ) ;
string = malloc ( sizeof( * string ) ) ;
if ( ! string ) {
F_64 ( V_53 , L_117 ,
V_135 , __LINE__ ) ;
goto V_41;
}
string -> V_22 = V_233 ;
string -> V_65 = F_12 ( V_65 . V_240 ) ;
if ( ! string -> V_65 ) {
free ( string ) ;
F_64 ( V_53 , L_117 ,
V_135 , __LINE__ ) ;
goto V_41;
}
args [ V_19 ] = ( V_241 ) string -> V_65 ;
V_233 = string ;
F_119 ( & V_65 ) ;
break;
default:
F_64 ( V_53 , L_118 ) ;
goto V_41;
}
V_67 = V_67 -> V_22 ;
V_231 = V_231 -> V_22 ;
}
V_124 = (* V_229 -> V_35 )( V_209 , args ) ;
V_41:
free ( args ) ;
while ( V_233 ) {
string = V_233 ;
V_233 = string -> V_22 ;
free ( string -> V_65 ) ;
free ( string ) ;
}
V_115:
return V_124 ;
}
static void F_128 ( struct V_7 * args )
{
struct V_7 * V_22 ;
while ( args ) {
V_22 = args -> V_22 ;
F_35 ( args ) ;
args = V_22 ;
}
}
static struct V_7 * F_129 ( char * V_50 , void * V_189 , int V_2 , struct V_52 * V_53 )
{
struct V_14 * V_14 = V_53 -> V_14 ;
struct V_126 * V_71 , * V_242 ;
struct V_7 * args , * V_66 , * * V_22 ;
unsigned long long V_243 , V_170 ;
char * V_188 ;
void * V_244 ;
int V_245 ;
V_71 = V_14 -> V_246 ;
V_242 = V_14 -> V_247 ;
if ( ! V_71 ) {
V_71 = F_87 ( V_53 , L_119 ) ;
if ( ! V_71 ) {
F_64 ( V_53 , L_120 ) ;
return NULL ;
}
V_242 = F_87 ( V_53 , L_121 ) ;
if ( ! V_242 ) {
F_64 ( V_53 , L_122 ) ;
return NULL ;
}
V_14 -> V_246 = V_71 ;
V_14 -> V_247 = V_242 ;
}
V_243 = F_100 ( V_14 , V_189 + V_242 -> V_146 , V_242 -> V_2 ) ;
args = F_6 () ;
if ( ! args ) {
F_64 ( V_53 , L_123 ,
V_135 , __LINE__ ) ;
return NULL ;
}
V_66 = args ;
V_66 -> V_22 = NULL ;
V_22 = & V_66 -> V_22 ;
V_66 -> type = V_68 ;
if ( F_42 ( & V_66 -> V_69 . V_69 , L_80 , V_243 ) < 0 )
goto V_41;
for ( V_188 = V_50 + 5 , V_244 = V_189 + V_71 -> V_146 ;
V_244 < V_189 + V_2 && * V_188 ; V_188 ++ ) {
int V_248 = 0 ;
if ( * V_188 == '%' ) {
V_249:
V_188 ++ ;
switch ( * V_188 ) {
case '%' :
break;
case 'l' :
V_248 ++ ;
goto V_249;
case 'L' :
V_248 = 2 ;
goto V_249;
case '0' ... '9' :
goto V_249;
case '.' :
goto V_249;
case 'z' :
case 'Z' :
V_248 = 1 ;
goto V_249;
case 'p' :
V_248 = 1 ;
case 'd' :
case 'u' :
case 'x' :
case 'i' :
switch ( V_248 ) {
case 0 :
V_245 = 4 ;
break;
case 1 :
V_245 = V_14 -> V_149 ;
break;
case 2 :
V_245 = 8 ;
break;
default:
V_245 = V_248 ;
break;
}
case '*' :
if ( * V_188 == '*' )
V_245 = 4 ;
V_244 = ( void * ) ( ( ( unsigned long ) V_244 + 3 ) &
~ 3 ) ;
V_170 = F_100 ( V_14 , V_244 , V_245 ) ;
V_244 += V_245 ;
V_66 = F_6 () ;
if ( ! V_66 ) {
F_64 ( V_53 , L_123 ,
V_135 , __LINE__ ) ;
goto V_41;
}
V_66 -> V_22 = NULL ;
V_66 -> type = V_68 ;
if ( F_42 ( & V_66 -> V_69 . V_69 , L_80 , V_170 ) < 0 ) {
free ( V_66 ) ;
goto V_41;
}
* V_22 = V_66 ;
V_22 = & V_66 -> V_22 ;
if ( * V_188 == '*' )
goto V_249;
break;
case 's' :
V_66 = F_6 () ;
if ( ! V_66 ) {
F_64 ( V_53 , L_123 ,
V_135 , __LINE__ ) ;
goto V_41;
}
V_66 -> V_22 = NULL ;
V_66 -> type = V_88 ;
V_66 -> string . string = F_12 ( V_244 ) ;
if ( ! V_66 -> string . string )
goto V_41;
V_244 += strlen ( V_244 ) + 1 ;
* V_22 = V_66 ;
V_22 = & V_66 -> V_22 ;
default:
break;
}
}
}
return args ;
V_41:
F_128 ( args ) ;
return NULL ;
}
static char *
F_130 ( void * V_189 , int V_2 V_161 ,
struct V_52 * V_53 )
{
struct V_14 * V_14 = V_53 -> V_14 ;
unsigned long long V_31 ;
struct V_126 * V_71 ;
struct V_43 * V_49 ;
char * V_150 ;
V_71 = V_14 -> V_250 ;
if ( ! V_71 ) {
V_71 = F_87 ( V_53 , L_100 ) ;
if ( ! V_71 ) {
F_64 ( V_53 , L_124 ) ;
return NULL ;
}
V_14 -> V_250 = V_71 ;
}
V_31 = F_100 ( V_14 , V_189 + V_71 -> V_146 , V_71 -> V_2 ) ;
V_49 = F_28 ( V_14 , V_31 ) ;
if ( ! V_49 ) {
if ( F_42 ( & V_150 , L_125 , V_31 ) < 0 )
return NULL ;
return V_150 ;
}
if ( F_42 ( & V_150 , L_126 , L_127 , V_49 -> V_49 ) < 0 )
return NULL ;
return V_150 ;
}
static void F_131 ( struct V_208 * V_209 , int V_251 , void * V_189 , int V_2 ,
struct V_52 * V_53 , struct V_7 * V_66 )
{
unsigned char * V_1 ;
const char * V_50 = L_128 ;
if ( V_66 -> type == V_99 ) {
F_118 ( V_209 , V_189 , V_2 , V_53 , V_66 ) ;
return;
}
if ( V_66 -> type != V_70 ) {
F_122 ( V_209 , L_129 ,
V_66 -> type ) ;
return;
}
if ( V_251 == 'm' )
V_50 = L_130 ;
if ( ! V_66 -> V_71 . V_71 ) {
V_66 -> V_71 . V_71 =
F_75 ( V_53 , V_66 -> V_71 . V_72 ) ;
if ( ! V_66 -> V_71 . V_71 ) {
F_64 ( V_53 , L_110 ,
V_135 , V_66 -> V_71 . V_72 ) ;
return;
}
}
if ( V_66 -> V_71 . V_71 -> V_2 != 6 ) {
F_122 ( V_209 , L_131 ) ;
return;
}
V_1 = V_189 + V_66 -> V_71 . V_71 -> V_146 ;
F_122 ( V_209 , V_50 , V_1 [ 0 ] , V_1 [ 1 ] , V_1 [ 2 ] , V_1 [ 3 ] , V_1 [ 4 ] , V_1 [ 5 ] ) ;
}
static void F_132 ( struct V_208 * V_209 , char V_19 , unsigned char * V_1 )
{
const char * V_50 ;
if ( V_19 == 'i' )
V_50 = L_132 ;
else
V_50 = L_133 ;
F_122 ( V_209 , V_50 , V_1 [ 0 ] , V_1 [ 1 ] , V_1 [ 2 ] , V_1 [ 3 ] ) ;
}
static inline bool F_133 ( const struct V_252 * V_8 )
{
return ( ( unsigned long ) ( V_8 -> V_253 [ 0 ] | V_8 -> V_253 [ 1 ] ) |
( unsigned long ) ( V_8 -> V_253 [ 2 ] ^ F_134 ( 0x0000ffff ) ) ) == 0UL ;
}
static inline bool F_135 ( const struct V_252 * V_31 )
{
return ( V_31 -> V_253 [ 2 ] | F_134 ( 0x02000000 ) ) == F_134 ( 0x02005EFE ) ;
}
static void F_136 ( struct V_208 * V_209 , unsigned char * V_31 )
{
int V_19 , V_254 , V_255 ;
unsigned char V_256 [ 8 ] ;
int V_257 = 1 ;
int V_258 = - 1 ;
V_221 V_259 ;
V_220 V_260 , V_261 ;
bool V_262 = false ;
bool V_263 ;
struct V_252 V_264 ;
memcpy ( & V_264 , V_31 , sizeof( struct V_252 ) ) ;
V_263 = F_133 ( & V_264 ) || F_135 ( & V_264 ) ;
memset ( V_256 , 0 , sizeof( V_256 ) ) ;
if ( V_263 )
V_255 = 6 ;
else
V_255 = 8 ;
for ( V_19 = 0 ; V_19 < V_255 ; V_19 ++ ) {
for ( V_254 = V_19 ; V_254 < V_255 ; V_254 ++ ) {
if ( V_264 . V_265 [ V_254 ] != 0 )
break;
V_256 [ V_19 ] ++ ;
}
}
for ( V_19 = 0 ; V_19 < V_255 ; V_19 ++ ) {
if ( V_256 [ V_19 ] > V_257 ) {
V_257 = V_256 [ V_19 ] ;
V_258 = V_19 ;
}
}
if ( V_257 == 1 )
V_258 = - 1 ;
for ( V_19 = 0 ; V_19 < V_255 ; V_19 ++ ) {
if ( V_19 == V_258 ) {
if ( V_262 || V_19 == 0 )
F_122 ( V_209 , L_19 ) ;
F_122 ( V_209 , L_19 ) ;
V_262 = false ;
V_19 += V_257 - 1 ;
continue;
}
if ( V_262 ) {
F_122 ( V_209 , L_19 ) ;
V_262 = false ;
}
V_259 = F_137 ( V_264 . V_265 [ V_19 ] ) ;
V_260 = V_259 >> 8 ;
V_261 = V_259 & 0xff ;
if ( V_260 )
F_122 ( V_209 , L_134 , V_260 , V_261 ) ;
else
F_122 ( V_209 , L_135 , V_261 ) ;
V_262 = true ;
}
if ( V_263 ) {
if ( V_262 )
F_122 ( V_209 , L_19 ) ;
F_132 ( V_209 , 'I' , & V_264 . V_266 [ 12 ] ) ;
}
return;
}
static void F_138 ( struct V_208 * V_209 , char V_19 , unsigned char * V_1 )
{
int V_254 ;
for ( V_254 = 0 ; V_254 < 16 ; V_254 += 2 ) {
F_122 ( V_209 , L_136 , V_1 [ V_254 ] , V_1 [ V_254 + 1 ] ) ;
if ( V_19 == 'I' && V_254 < 14 )
F_122 ( V_209 , L_19 ) ;
}
}
static int F_139 ( struct V_208 * V_209 , const char * V_188 , char V_19 ,
void * V_189 , int V_2 , struct V_52 * V_53 ,
struct V_7 * V_66 )
{
unsigned char * V_1 ;
if ( V_66 -> type == V_99 ) {
F_118 ( V_209 , V_189 , V_2 , V_53 , V_66 ) ;
return 0 ;
}
if ( V_66 -> type != V_70 ) {
F_122 ( V_209 , L_129 , V_66 -> type ) ;
return 0 ;
}
if ( ! V_66 -> V_71 . V_71 ) {
V_66 -> V_71 . V_71 =
F_75 ( V_53 , V_66 -> V_71 . V_72 ) ;
if ( ! V_66 -> V_71 . V_71 ) {
F_50 ( L_110 ,
V_135 , V_66 -> V_71 . V_72 ) ;
return 0 ;
}
}
V_1 = V_189 + V_66 -> V_71 . V_71 -> V_146 ;
if ( V_66 -> V_71 . V_71 -> V_2 != 4 ) {
F_122 ( V_209 , L_137 ) ;
return 0 ;
}
F_132 ( V_209 , V_19 , V_1 ) ;
return 0 ;
}
static int F_140 ( struct V_208 * V_209 , const char * V_188 , char V_19 ,
void * V_189 , int V_2 , struct V_52 * V_53 ,
struct V_7 * V_66 )
{
char V_267 = 0 ;
unsigned char * V_1 ;
int V_268 = 0 ;
if ( V_19 == 'I' && * V_188 == 'c' ) {
V_267 = 1 ;
V_188 ++ ;
V_268 ++ ;
}
if ( V_66 -> type == V_99 ) {
F_118 ( V_209 , V_189 , V_2 , V_53 , V_66 ) ;
return V_268 ;
}
if ( V_66 -> type != V_70 ) {
F_122 ( V_209 , L_129 , V_66 -> type ) ;
return V_268 ;
}
if ( ! V_66 -> V_71 . V_71 ) {
V_66 -> V_71 . V_71 =
F_75 ( V_53 , V_66 -> V_71 . V_72 ) ;
if ( ! V_66 -> V_71 . V_71 ) {
F_50 ( L_110 ,
V_135 , V_66 -> V_71 . V_72 ) ;
return V_268 ;
}
}
V_1 = V_189 + V_66 -> V_71 . V_71 -> V_146 ;
if ( V_66 -> V_71 . V_71 -> V_2 != 16 ) {
F_122 ( V_209 , L_138 ) ;
return V_268 ;
}
if ( V_267 )
F_136 ( V_209 , V_1 ) ;
else
F_138 ( V_209 , V_19 , V_1 ) ;
return V_268 ;
}
static int F_141 ( struct V_208 * V_209 , const char * V_188 , char V_19 ,
void * V_189 , int V_2 , struct V_52 * V_53 ,
struct V_7 * V_66 )
{
char V_267 = 0 , V_269 = 0 ;
unsigned char * V_1 ;
struct V_270 * V_271 ;
int V_268 = 0 ;
if ( V_19 == 'I' ) {
if ( * V_188 == 'p' ) {
V_269 = 1 ;
V_188 ++ ;
V_268 ++ ;
}
if ( * V_188 == 'c' ) {
V_267 = 1 ;
V_188 ++ ;
V_268 ++ ;
}
}
if ( V_66 -> type == V_99 ) {
F_118 ( V_209 , V_189 , V_2 , V_53 , V_66 ) ;
return V_268 ;
}
if ( V_66 -> type != V_70 ) {
F_122 ( V_209 , L_129 , V_66 -> type ) ;
return V_268 ;
}
if ( ! V_66 -> V_71 . V_71 ) {
V_66 -> V_71 . V_71 =
F_75 ( V_53 , V_66 -> V_71 . V_72 ) ;
if ( ! V_66 -> V_71 . V_71 ) {
F_50 ( L_110 ,
V_135 , V_66 -> V_71 . V_72 ) ;
return V_268 ;
}
}
V_271 = (struct V_270 * ) ( V_189 + V_66 -> V_71 . V_71 -> V_146 ) ;
if ( V_271 -> V_272 == V_273 ) {
struct V_274 * V_275 = (struct V_274 * ) V_271 ;
if ( V_66 -> V_71 . V_71 -> V_2 < sizeof( struct V_274 ) ) {
F_122 ( V_209 , L_137 ) ;
return V_268 ;
}
F_132 ( V_209 , V_19 , ( unsigned char * ) & V_275 -> V_276 ) ;
if ( V_269 )
F_122 ( V_209 , L_139 , F_137 ( V_275 -> V_277 ) ) ;
} else if ( V_271 -> V_272 == V_278 ) {
struct V_279 * V_280 = (struct V_279 * ) V_271 ;
if ( V_66 -> V_71 . V_71 -> V_2 < sizeof( struct V_279 ) ) {
F_122 ( V_209 , L_138 ) ;
return V_268 ;
}
if ( V_269 )
F_122 ( V_209 , L_38 ) ;
V_1 = ( unsigned char * ) & V_280 -> V_281 ;
if ( V_267 )
F_136 ( V_209 , V_1 ) ;
else
F_138 ( V_209 , V_19 , V_1 ) ;
if ( V_269 )
F_122 ( V_209 , L_140 , F_137 ( V_280 -> V_282 ) ) ;
}
return V_268 ;
}
static int F_142 ( struct V_208 * V_209 , const char * V_188 ,
void * V_189 , int V_2 , struct V_52 * V_53 ,
struct V_7 * V_66 )
{
char V_19 = * V_188 ;
char V_283 ;
int V_268 = 0 ;
V_188 ++ ;
V_268 ++ ;
V_283 = * V_188 ;
V_188 ++ ;
V_268 ++ ;
switch ( V_283 ) {
case '4' :
V_268 += F_139 ( V_209 , V_188 , V_19 , V_189 , V_2 , V_53 , V_66 ) ;
break;
case '6' :
V_268 += F_140 ( V_209 , V_188 , V_19 , V_189 , V_2 , V_53 , V_66 ) ;
break;
case 'S' :
V_268 += F_141 ( V_209 , V_188 , V_19 , V_189 , V_2 , V_53 , V_66 ) ;
break;
default:
return 0 ;
}
return V_268 ;
}
static int F_143 ( char * V_51 , unsigned int V_140 )
{
unsigned int V_19 ;
for ( V_19 = 0 ; V_19 < V_140 && V_51 [ V_19 ] ; V_19 ++ )
if ( ! isprint ( V_51 [ V_19 ] ) && ! isspace ( V_51 [ V_19 ] ) )
return 0 ;
return 1 ;
}
void F_144 ( struct V_208 * V_209 , void * V_189 ,
struct V_126 * V_71 )
{
unsigned long long V_170 ;
unsigned int V_146 , V_140 , V_19 ;
struct V_14 * V_14 = V_71 -> V_53 -> V_14 ;
if ( V_71 -> V_74 & V_127 ) {
V_146 = V_71 -> V_146 ;
V_140 = V_71 -> V_2 ;
if ( V_71 -> V_74 & V_143 ) {
V_170 = F_100 ( V_14 , V_189 + V_146 , V_140 ) ;
V_146 = V_170 ;
V_140 = V_146 >> 16 ;
V_146 &= 0xffff ;
}
if ( V_71 -> V_74 & V_142 &&
F_143 ( V_189 + V_146 , V_140 ) ) {
F_122 ( V_209 , L_116 , ( char * ) V_189 + V_146 ) ;
} else {
F_125 ( V_209 , L_141 ) ;
for ( V_19 = 0 ; V_19 < V_140 ; V_19 ++ ) {
if ( V_19 )
F_125 ( V_209 , L_142 ) ;
F_122 ( V_209 , L_111 ,
* ( ( unsigned char * ) V_189 + V_146 + V_19 ) ) ;
}
F_126 ( V_209 , ']' ) ;
V_71 -> V_74 &= ~ V_142 ;
}
} else {
V_170 = F_100 ( V_14 , V_189 + V_71 -> V_146 ,
V_71 -> V_2 ) ;
if ( V_71 -> V_74 & V_133 ) {
F_122 ( V_209 , L_143 , V_170 ) ;
} else if ( V_71 -> V_74 & V_147 ) {
switch ( V_71 -> V_2 ) {
case 4 :
if ( V_71 -> V_74 & V_144 )
F_122 ( V_209 , L_144 , ( int ) V_170 ) ;
else
F_122 ( V_209 , L_145 , ( int ) V_170 ) ;
break;
case 2 :
F_122 ( V_209 , L_146 , ( short ) V_170 ) ;
break;
case 1 :
F_122 ( V_209 , L_147 , ( char ) V_170 ) ;
break;
default:
F_122 ( V_209 , L_80 , V_170 ) ;
}
} else {
if ( V_71 -> V_74 & V_144 )
F_122 ( V_209 , L_143 , V_170 ) ;
else
F_122 ( V_209 , L_148 , V_170 ) ;
}
}
}
void F_145 ( struct V_208 * V_209 , void * V_189 ,
int V_2 V_161 , struct V_52 * V_53 )
{
struct V_126 * V_71 ;
V_71 = V_53 -> V_150 . V_129 ;
while ( V_71 ) {
F_122 ( V_209 , L_149 , V_71 -> V_72 ) ;
F_144 ( V_209 , V_189 , V_71 ) ;
V_71 = V_71 -> V_22 ;
}
}
static void F_146 ( struct V_208 * V_209 , void * V_189 , int V_2 , struct V_52 * V_53 )
{
struct V_14 * V_14 = V_53 -> V_14 ;
struct V_186 * V_186 = & V_53 -> V_186 ;
struct V_7 * V_66 = V_186 -> args ;
struct V_7 * args = NULL ;
const char * V_188 = V_186 -> V_150 ;
unsigned long long V_170 ;
struct V_28 * V_35 ;
const char * V_284 ;
struct V_208 V_51 ;
char * V_285 = NULL ;
char V_150 [ 32 ] ;
int V_286 ;
int V_287 ;
int V_213 ;
int V_140 ;
int V_248 ;
if ( V_53 -> V_74 & V_158 ) {
F_122 ( V_209 , L_150 ) ;
F_145 ( V_209 , V_189 , V_2 , V_53 ) ;
return;
}
if ( V_53 -> V_74 & V_288 ) {
V_285 = F_130 ( V_189 , V_2 , V_53 ) ;
args = F_129 ( V_285 , V_189 , V_2 , V_53 ) ;
V_66 = args ;
V_188 = V_285 ;
}
for (; * V_188 ; V_188 ++ ) {
V_248 = 0 ;
if ( * V_188 == '\\' ) {
V_188 ++ ;
switch ( * V_188 ) {
case 'n' :
F_126 ( V_209 , '\n' ) ;
break;
case 't' :
F_126 ( V_209 , '\t' ) ;
break;
case 'r' :
F_126 ( V_209 , '\r' ) ;
break;
case '\\' :
F_126 ( V_209 , '\\' ) ;
break;
default:
F_126 ( V_209 , * V_188 ) ;
break;
}
} else if ( * V_188 == '%' ) {
V_284 = V_188 ;
V_286 = 0 ;
V_287 = 0 ;
V_289:
V_188 ++ ;
switch ( * V_188 ) {
case '%' :
F_126 ( V_209 , '%' ) ;
break;
case '#' :
goto V_289;
case 'h' :
V_248 -- ;
goto V_289;
case 'l' :
V_248 ++ ;
goto V_289;
case 'L' :
V_248 = 2 ;
goto V_289;
case '*' :
if ( ! V_66 ) {
F_64 ( V_53 , L_151 ) ;
V_53 -> V_74 |= V_158 ;
goto V_290;
}
V_213 = F_115 ( V_189 , V_2 , V_53 , V_66 ) ;
V_287 = 1 ;
V_66 = V_66 -> V_22 ;
goto V_289;
case '.' :
case 'z' :
case 'Z' :
case '0' ... '9' :
case '-' :
goto V_289;
case 'p' :
if ( V_14 -> V_149 == 4 )
V_248 = 1 ;
else
V_248 = 2 ;
if ( * ( V_188 + 1 ) == 'F' || * ( V_188 + 1 ) == 'f' ||
* ( V_188 + 1 ) == 'S' || * ( V_188 + 1 ) == 's' ) {
V_188 ++ ;
V_286 = * V_188 ;
} else if ( * ( V_188 + 1 ) == 'M' || * ( V_188 + 1 ) == 'm' ) {
F_131 ( V_209 , * ( V_188 + 1 ) , V_189 , V_2 , V_53 , V_66 ) ;
V_188 ++ ;
V_66 = V_66 -> V_22 ;
break;
} else if ( * ( V_188 + 1 ) == 'I' || * ( V_188 + 1 ) == 'i' ) {
int V_291 ;
V_291 = F_142 ( V_209 , V_188 + 1 , V_189 , V_2 , V_53 , V_66 ) ;
if ( V_291 > 0 ) {
V_188 += V_291 ;
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
F_64 ( V_53 , L_151 ) ;
V_53 -> V_74 |= V_158 ;
goto V_290;
}
V_140 = ( ( unsigned long ) V_188 + 1 ) -
( unsigned long ) V_284 ;
if ( V_140 > 31 ) {
F_64 ( V_53 , L_152 ) ;
V_53 -> V_74 |= V_158 ;
V_140 = 31 ;
}
memcpy ( V_150 , V_284 , V_140 ) ;
V_150 [ V_140 ] = 0 ;
V_170 = F_115 ( V_189 , V_2 , V_53 , V_66 ) ;
V_66 = V_66 -> V_22 ;
if ( V_286 ) {
V_35 = F_21 ( V_14 , V_170 ) ;
if ( V_35 ) {
F_125 ( V_209 , V_35 -> V_35 ) ;
if ( V_286 == 'F' )
F_122 ( V_209 ,
L_153 ,
V_170 - V_35 -> V_31 ) ;
break;
}
}
if ( V_14 -> V_149 == 8 && V_248 &&
sizeof( long ) != 8 ) {
char * V_51 ;
if ( V_248 == 1 && ( V_51 = strchr ( V_150 , 'l' ) ) )
memmove ( V_51 + 1 , V_51 , strlen ( V_51 ) + 1 ) ;
else if ( strcmp ( V_150 , L_154 ) == 0 )
strcpy ( V_150 , L_143 ) ;
V_248 = 2 ;
}
switch ( V_248 ) {
case - 2 :
if ( V_287 )
F_122 ( V_209 , V_150 , V_213 , ( char ) V_170 ) ;
else
F_122 ( V_209 , V_150 , ( char ) V_170 ) ;
break;
case - 1 :
if ( V_287 )
F_122 ( V_209 , V_150 , V_213 , ( short ) V_170 ) ;
else
F_122 ( V_209 , V_150 , ( short ) V_170 ) ;
break;
case 0 :
if ( V_287 )
F_122 ( V_209 , V_150 , V_213 , ( int ) V_170 ) ;
else
F_122 ( V_209 , V_150 , ( int ) V_170 ) ;
break;
case 1 :
if ( V_287 )
F_122 ( V_209 , V_150 , V_213 , ( long ) V_170 ) ;
else
F_122 ( V_209 , V_150 , ( long ) V_170 ) ;
break;
case 2 :
if ( V_287 )
F_122 ( V_209 , V_150 , V_213 ,
( long long ) V_170 ) ;
else
F_122 ( V_209 , V_150 , ( long long ) V_170 ) ;
break;
default:
F_64 ( V_53 , L_155 , V_248 ) ;
V_53 -> V_74 |= V_158 ;
}
break;
case 's' :
if ( ! V_66 ) {
F_64 ( V_53 , L_156 ) ;
V_53 -> V_74 |= V_158 ;
goto V_290;
}
V_140 = ( ( unsigned long ) V_188 + 1 ) -
( unsigned long ) V_284 ;
if ( V_140 > 31 ) {
F_64 ( V_53 , L_152 ) ;
V_53 -> V_74 |= V_158 ;
V_140 = 31 ;
}
memcpy ( V_150 , V_284 , V_140 ) ;
V_150 [ V_140 ] = 0 ;
if ( ! V_287 )
V_213 = - 1 ;
F_117 ( & V_51 ) ;
F_124 ( & V_51 , V_189 , V_2 , V_53 ,
V_150 , V_213 , V_66 ) ;
F_127 ( & V_51 ) ;
F_125 ( V_209 , V_51 . V_240 ) ;
F_119 ( & V_51 ) ;
V_66 = V_66 -> V_22 ;
break;
default:
F_122 ( V_209 , L_157 , * V_188 ) ;
}
} else
F_126 ( V_209 , * V_188 ) ;
}
if ( V_53 -> V_74 & V_158 ) {
V_290:
F_122 ( V_209 , L_150 ) ;
}
if ( args ) {
F_128 ( args ) ;
free ( V_285 ) ;
}
}
void F_147 ( struct V_14 * V_14 ,
struct V_208 * V_209 , struct V_292 * V_293 )
{
static int V_294 = 1 ;
static int V_295 = 1 ;
static int V_296 ;
static int V_297 ;
unsigned int V_298 ;
unsigned int V_299 ;
int V_300 ;
int V_301 ;
int V_302 ;
int V_303 ;
void * V_189 = V_293 -> V_189 ;
V_298 = F_110 ( V_14 , V_189 ) ;
V_299 = F_109 ( V_14 , V_189 ) ;
if ( V_296 )
V_300 = F_111 ( V_14 , V_189 ) ;
else if ( V_294 ) {
V_300 = F_111 ( V_14 , V_189 ) ;
if ( V_300 < 0 )
V_294 = 0 ;
else
V_296 = 1 ;
}
if ( V_297 )
V_301 = F_112 ( V_14 , V_189 ) ;
else if ( V_295 ) {
V_301 = F_112 ( V_14 , V_189 ) ;
if ( V_301 < 0 )
V_295 = 0 ;
else
V_297 = 1 ;
}
V_302 = V_298 & V_304 ;
V_303 = V_298 & V_305 ;
F_122 ( V_209 , L_158 ,
( V_298 & V_306 ) ? 'd' :
( V_298 & V_307 ) ?
'X' : '.' ,
( V_298 & V_308 ) ?
'N' : '.' ,
( V_302 && V_303 ) ? 'H' :
V_302 ? 'h' : V_303 ? 's' : '.' ) ;
if ( V_299 )
F_122 ( V_209 , L_135 , V_299 ) ;
else
F_126 ( V_209 , '.' ) ;
if ( V_297 ) {
if ( V_301 < 0 )
F_126 ( V_209 , '.' ) ;
else
F_122 ( V_209 , L_145 , V_301 ) ;
}
if ( V_296 ) {
if ( V_300 < 0 )
F_126 ( V_209 , '.' ) ;
else
F_122 ( V_209 , L_145 , V_300 ) ;
}
F_127 ( V_209 ) ;
}
int F_148 ( struct V_14 * V_14 , struct V_292 * V_309 )
{
return F_107 ( V_14 , V_309 -> V_189 ) ;
}
struct V_52 * F_149 ( struct V_14 * V_14 , int type )
{
return F_113 ( V_14 , type ) ;
}
int F_150 ( struct V_14 * V_14 , struct V_292 * V_309 )
{
return F_108 ( V_14 , V_309 -> V_189 ) ;
}
const char * F_151 ( struct V_14 * V_14 , int V_13 )
{
const char * V_21 ;
V_21 = F_9 ( V_14 , V_13 ) ;
return V_21 ;
}
static struct V_10 *
F_152 ( struct V_14 * V_14 , const char * V_21 , struct V_10 * V_22 )
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
struct V_10 * F_153 ( struct V_14 * V_14 , const char * V_21 ,
struct V_10 * V_22 )
{
struct V_10 * V_10 ;
if ( ! V_14 -> V_18 )
return F_152 ( V_14 , V_21 , V_22 ) ;
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
int F_154 ( struct V_14 * V_14 , struct V_10 * V_10 )
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
void F_155 ( struct V_208 * V_209 , struct V_52 * V_53 ,
struct V_292 * V_293 )
{
int V_310 = 1 ;
if ( V_53 -> V_14 -> V_311 || ( V_53 -> V_74 & V_312 ) )
F_145 ( V_209 , V_293 -> V_189 , V_293 -> V_2 , V_53 ) ;
else {
if ( V_53 -> V_313 && ! ( V_53 -> V_74 & V_314 ) )
V_310 = V_53 -> V_313 ( V_209 , V_293 , V_53 ,
V_53 -> V_315 ) ;
if ( V_310 )
F_146 ( V_209 , V_293 -> V_189 , V_293 -> V_2 , V_53 ) ;
}
F_127 ( V_209 ) ;
}
static bool F_156 ( char * V_27 , bool V_316 )
{
if ( ! V_316 )
return true ;
if ( ! strcmp ( V_27 , L_159 ) || ! strcmp ( V_27 , L_160 )
|| ! strcmp ( V_27 , L_161 ) || ! strcmp ( V_27 , L_162 ) )
return true ;
return false ;
}
void F_157 ( struct V_14 * V_14 , struct V_208 * V_209 ,
struct V_292 * V_293 , bool V_316 )
{
static const char * V_317 = L_163 ;
struct V_52 * V_53 ;
unsigned long V_318 ;
unsigned long V_319 ;
unsigned long V_320 ;
const char * V_21 ;
void * V_189 = V_293 -> V_189 ;
int type ;
int V_13 ;
int V_140 ;
int V_51 ;
bool V_321 ;
V_321 = F_156 ( V_14 -> V_27 ,
V_316 ) ;
if ( V_321 ) {
V_318 = V_293 -> V_322 / V_323 ;
V_320 = V_293 -> V_322 - V_318 * V_323 ;
}
if ( V_293 -> V_2 < 0 ) {
F_50 ( L_164 , V_293 -> V_2 ) ;
return;
}
type = F_107 ( V_14 , V_189 ) ;
V_53 = F_113 ( V_14 , type ) ;
if ( ! V_53 ) {
F_50 ( L_165 , type ) ;
return;
}
V_13 = F_108 ( V_14 , V_189 ) ;
V_21 = F_9 ( V_14 , V_13 ) ;
if ( V_14 -> V_324 ) {
F_122 ( V_209 , L_166 ,
V_21 , V_13 , V_293 -> V_325 ) ;
F_147 ( V_14 , V_209 , V_293 ) ;
} else
F_122 ( V_209 , L_167 , V_21 , V_13 , V_293 -> V_325 ) ;
if ( V_321 ) {
if ( V_14 -> V_74 & V_326 ) {
V_319 = V_320 ;
V_51 = 9 ;
} else {
V_319 = ( V_320 + 500 ) / V_327 ;
V_51 = 6 ;
}
F_122 ( V_209 , L_168 ,
V_318 , V_51 , V_319 , V_53 -> V_72 ) ;
} else
F_122 ( V_209 , L_169 ,
V_293 -> V_322 , V_53 -> V_72 ) ;
V_140 = strlen ( V_53 -> V_72 ) ;
if ( V_140 < 20 )
F_122 ( V_209 , L_170 , 20 - V_140 , V_317 ) ;
F_155 ( V_209 , V_53 , V_293 ) ;
}
static int V_202 ( const void * V_8 , const void * V_9 )
{
struct V_52 * const * V_328 = V_8 ;
struct V_52 * const * V_329 = V_9 ;
if ( ( * V_328 ) -> V_56 < ( * V_329 ) -> V_56 )
return - 1 ;
if ( ( * V_328 ) -> V_56 > ( * V_329 ) -> V_56 )
return 1 ;
return 0 ;
}
static int F_158 ( const void * V_8 , const void * V_9 )
{
struct V_52 * const * V_328 = V_8 ;
struct V_52 * const * V_329 = V_9 ;
int V_330 ;
V_330 = strcmp ( ( * V_328 ) -> V_72 , ( * V_329 ) -> V_72 ) ;
if ( V_330 )
return V_330 ;
V_330 = strcmp ( ( * V_328 ) -> system , ( * V_329 ) -> system ) ;
if ( V_330 )
return V_330 ;
return V_202 ( V_8 , V_9 ) ;
}
static int F_159 ( const void * V_8 , const void * V_9 )
{
struct V_52 * const * V_328 = V_8 ;
struct V_52 * const * V_329 = V_9 ;
int V_330 ;
V_330 = strcmp ( ( * V_328 ) -> system , ( * V_329 ) -> system ) ;
if ( V_330 )
return V_330 ;
V_330 = strcmp ( ( * V_328 ) -> V_72 , ( * V_329 ) -> V_72 ) ;
if ( V_330 )
return V_330 ;
return V_202 ( V_8 , V_9 ) ;
}
struct V_52 * * F_160 ( struct V_14 * V_14 , enum V_331 V_332 )
{
struct V_52 * * V_54 ;
int (* F_161)( const void * V_8 , const void * V_9 );
V_54 = V_14 -> V_333 ;
if ( V_54 && V_14 -> V_137 == V_332 )
return V_54 ;
if ( ! V_54 ) {
V_54 = malloc ( sizeof( * V_54 ) * ( V_14 -> V_55 + 1 ) ) ;
if ( ! V_54 )
return NULL ;
memcpy ( V_54 , V_14 -> V_54 , sizeof( * V_54 ) * V_14 -> V_55 ) ;
V_54 [ V_14 -> V_55 ] = NULL ;
V_14 -> V_333 = V_54 ;
if ( V_332 == V_334 ) {
V_14 -> V_137 = V_332 ;
return V_54 ;
}
}
switch ( V_332 ) {
case V_334 :
F_161 = V_202 ;
break;
case V_335 :
F_161 = F_158 ;
break;
case V_336 :
F_161 = F_159 ;
break;
default:
return V_54 ;
}
qsort ( V_54 , V_14 -> V_55 , sizeof( * V_54 ) , F_161 ) ;
V_14 -> V_137 = V_332 ;
return V_54 ;
}
static struct V_126 * *
F_162 ( const char * type , const char * V_72 ,
int V_83 , struct V_126 * V_174 )
{
struct V_126 * * V_129 ;
struct V_126 * V_71 ;
int V_19 = 0 ;
V_129 = malloc ( sizeof( * V_129 ) * ( V_83 + 1 ) ) ;
if ( ! V_129 )
return NULL ;
for ( V_71 = V_174 ; V_71 ; V_71 = V_71 -> V_22 ) {
V_129 [ V_19 ++ ] = V_71 ;
if ( V_19 == V_83 + 1 ) {
F_50 ( L_171 ,
V_72 , type ) ;
V_19 -- ;
break;
}
}
if ( V_19 != V_83 )
F_50 ( L_172 ,
V_72 , type ) ;
V_129 [ V_19 ] = NULL ;
return V_129 ;
}
struct V_126 * * F_163 ( struct V_52 * V_53 )
{
return F_162 ( L_173 , V_53 -> V_72 ,
V_53 -> V_150 . V_152 ,
V_53 -> V_150 . V_151 ) ;
}
struct V_126 * * F_164 ( struct V_52 * V_53 )
{
return F_162 ( L_174 , V_53 -> V_72 ,
V_53 -> V_150 . V_153 ,
V_53 -> V_150 . V_129 ) ;
}
static void F_165 ( struct V_208 * V_209 , struct V_62 * V_71 )
{
F_122 ( V_209 , L_175 , V_71 -> V_64 , V_71 -> V_65 ) ;
if ( V_71 -> V_22 ) {
F_125 ( V_209 , L_142 ) ;
F_165 ( V_209 , V_71 -> V_22 ) ;
}
}
static void F_166 ( struct V_7 * args )
{
int V_337 = 1 ;
struct V_208 V_209 ;
switch ( args -> type ) {
case V_100 :
printf ( L_176 ) ;
break;
case V_68 :
printf ( L_116 , args -> V_69 . V_69 ) ;
break;
case V_70 :
printf ( L_177 , args -> V_71 . V_72 ) ;
break;
case V_73 :
printf ( L_178 ) ;
F_166 ( args -> V_74 . V_71 ) ;
printf ( L_179 , args -> V_74 . V_75 ) ;
F_117 ( & V_209 ) ;
F_165 ( & V_209 , args -> V_74 . V_74 ) ;
F_167 ( & V_209 ) ;
F_119 ( & V_209 ) ;
printf ( L_69 ) ;
break;
case V_76 :
printf ( L_180 ) ;
F_166 ( args -> V_77 . V_71 ) ;
printf ( L_142 ) ;
F_117 ( & V_209 ) ;
F_165 ( & V_209 , args -> V_77 . V_78 ) ;
F_167 ( & V_209 ) ;
F_119 ( & V_209 ) ;
printf ( L_69 ) ;
break;
case V_79 :
printf ( L_181 ) ;
F_166 ( args -> V_80 . V_71 ) ;
printf ( L_142 ) ;
F_166 ( args -> V_80 . V_2 ) ;
printf ( L_69 ) ;
break;
case V_81 :
printf ( L_182 ) ;
F_166 ( args -> V_82 . V_71 ) ;
printf ( L_142 ) ;
F_166 ( args -> V_82 . V_83 ) ;
printf ( L_142 ) ;
F_166 ( args -> V_82 . V_84 ) ;
printf ( L_69 ) ;
break;
case V_87 :
case V_88 :
printf ( L_183 , args -> string . string ) ;
break;
case V_89 :
printf ( L_184 , args -> V_90 . V_90 ) ;
break;
case V_85 :
printf ( L_185 , args -> V_86 . type ) ;
F_166 ( args -> V_86 . V_17 ) ;
break;
case V_95 :
if ( strcmp ( args -> V_96 . V_96 , L_19 ) == 0 )
V_337 = 0 ;
if ( V_337 )
printf ( L_84 ) ;
F_166 ( args -> V_96 . V_97 ) ;
printf ( L_186 , args -> V_96 . V_96 ) ;
F_166 ( args -> V_96 . V_98 ) ;
if ( V_337 )
printf ( L_69 ) ;
break;
default:
return;
}
if ( args -> V_22 ) {
printf ( L_6 ) ;
F_166 ( args -> V_22 ) ;
}
}
static void F_168 ( const char * V_71 ,
int * V_146 , int * V_2 , int V_338 )
{
unsigned long long V_117 ;
unsigned long long V_119 ;
char * V_120 ;
int type ;
V_117 = V_5 ;
V_119 = V_4 ;
if ( F_55 ( V_58 , L_32 ) < 0 )
return;
if ( F_55 ( V_106 , L_19 ) < 0 )
return;
if ( F_53 ( V_58 , & V_120 ) < 0 )
goto V_125;
F_44 ( V_120 ) ;
if ( V_338 ) {
if ( F_55 ( V_58 , V_71 ) < 0 )
return;
} else {
if ( F_53 ( V_58 , & V_120 ) < 0 )
goto V_125;
if ( strcmp ( V_120 , V_71 ) != 0 )
goto V_339;
F_44 ( V_120 ) ;
}
if ( F_55 ( V_106 , L_41 ) < 0 )
return;
if ( F_55 ( V_58 , L_42 ) < 0 )
return;
if ( F_55 ( V_106 , L_19 ) < 0 )
return;
if ( F_53 ( V_58 , & V_120 ) < 0 )
goto V_125;
* V_146 = atoi ( V_120 ) ;
F_44 ( V_120 ) ;
if ( F_55 ( V_106 , L_41 ) < 0 )
return;
if ( F_55 ( V_58 , L_43 ) < 0 )
return;
if ( F_55 ( V_106 , L_19 ) < 0 )
return;
if ( F_53 ( V_58 , & V_120 ) < 0 )
goto V_125;
* V_2 = atoi ( V_120 ) ;
F_44 ( V_120 ) ;
if ( F_55 ( V_106 , L_41 ) < 0 )
return;
type = F_45 ( & V_120 ) ;
if ( type != V_102 ) {
if ( type != V_58 )
goto V_125;
if ( strcmp ( V_120 , L_44 ) != 0 )
goto V_125;
F_44 ( V_120 ) ;
if ( F_55 ( V_106 , L_19 ) < 0 )
return;
if ( F_53 ( V_58 , & V_120 ) )
goto V_125;
F_44 ( V_120 ) ;
if ( F_55 ( V_106 , L_41 ) < 0 )
return;
if ( F_53 ( V_102 , & V_120 ) )
goto V_125;
}
V_125:
F_44 ( V_120 ) ;
return;
V_339:
V_5 = V_117 ;
V_4 = V_119 ;
* V_146 = 0 ;
* V_2 = 0 ;
F_44 ( V_120 ) ;
}
int F_169 ( struct V_14 * V_14 , char * V_1 , unsigned long V_2 ,
int V_149 )
{
int V_340 ;
if ( ! V_2 ) {
V_14 -> V_341 = sizeof( long long ) ;
V_14 -> V_342 = V_149 ;
V_14 -> V_343 = sizeof( long long ) + V_149 ;
V_14 -> V_344 = 1 ;
return - 1 ;
}
F_1 ( V_1 , V_2 ) ;
F_168 ( L_187 , & V_14 -> V_345 ,
& V_14 -> V_341 , 1 ) ;
F_168 ( L_188 , & V_14 -> V_346 ,
& V_14 -> V_342 , 1 ) ;
F_168 ( L_189 , & V_14 -> V_347 ,
& V_340 , 0 ) ;
F_168 ( L_190 , & V_14 -> V_343 ,
& V_14 -> V_348 , 1 ) ;
return 0 ;
}
static int F_170 ( struct V_52 * V_53 ,
int V_56 , const char * V_349 ,
const char * V_350 )
{
if ( V_56 >= 0 && V_56 != V_53 -> V_56 )
return 0 ;
if ( V_350 && ( strcmp ( V_350 , V_53 -> V_72 ) != 0 ) )
return 0 ;
if ( V_349 && ( strcmp ( V_349 , V_53 -> system ) != 0 ) )
return 0 ;
return 1 ;
}
static void F_171 ( struct V_351 * V_352 )
{
free ( ( void * ) V_352 -> V_349 ) ;
free ( ( void * ) V_352 -> V_350 ) ;
free ( V_352 ) ;
}
static int F_172 ( struct V_14 * V_14 , struct V_52 * V_53 )
{
struct V_351 * V_352 , * * V_22 ;
for ( V_22 = & V_14 -> V_353 ; * V_22 ;
V_22 = & ( * V_22 ) -> V_22 ) {
V_352 = * V_22 ;
if ( F_170 ( V_53 , V_352 -> V_56 ,
V_352 -> V_349 ,
V_352 -> V_350 ) )
break;
}
if ( ! ( * V_22 ) )
return 0 ;
F_173 ( L_191 ,
V_53 -> V_56 , V_53 -> system , V_53 -> V_72 ) ;
V_53 -> V_313 = V_352 -> V_35 ;
V_53 -> V_315 = V_352 -> V_315 ;
* V_22 = V_352 -> V_22 ;
F_171 ( V_352 ) ;
return 1 ;
}
enum V_354 F_174 ( struct V_52 * * V_355 ,
struct V_14 * V_14 , const char * V_1 ,
unsigned long V_2 , const char * V_203 )
{
struct V_52 * V_53 ;
int V_124 ;
F_1 ( V_1 , V_2 ) ;
* V_355 = V_53 = F_31 () ;
if ( ! V_53 )
return V_356 ;
V_53 -> V_72 = F_57 () ;
if ( ! V_53 -> V_72 ) {
V_124 = V_356 ;
goto V_357;
}
if ( strcmp ( V_203 , L_192 ) == 0 ) {
V_53 -> V_74 |= V_132 ;
if ( strcmp ( V_53 -> V_72 , L_193 ) == 0 )
V_53 -> V_74 |= V_288 ;
}
V_53 -> V_56 = F_58 () ;
if ( V_53 -> V_56 < 0 ) {
V_124 = V_358 ;
goto V_357;
}
V_53 -> system = F_12 ( V_203 ) ;
if ( ! V_53 -> system ) {
V_124 = V_356 ;
goto V_357;
}
V_53 -> V_14 = V_14 ;
V_124 = F_65 ( V_53 ) ;
if ( V_124 < 0 ) {
V_124 = V_359 ;
goto V_360;
}
if ( V_14 && F_172 ( V_14 , V_53 ) )
V_361 = 0 ;
V_124 = F_98 ( V_53 ) ;
V_361 = 1 ;
if ( V_124 < 0 ) {
V_124 = V_362 ;
goto V_360;
}
if ( ! V_124 && ( V_53 -> V_74 & V_132 ) ) {
struct V_126 * V_71 ;
struct V_7 * V_66 , * * V_174 ;
V_174 = & V_53 -> V_186 . args ;
for ( V_71 = V_53 -> V_150 . V_129 ; V_71 ; V_71 = V_71 -> V_22 ) {
V_66 = F_6 () ;
if ( ! V_66 ) {
V_53 -> V_74 |= V_158 ;
return V_363 ;
}
V_66 -> type = V_70 ;
V_66 -> V_71 . V_72 = F_12 ( V_71 -> V_72 ) ;
if ( ! V_66 -> V_71 . V_72 ) {
V_53 -> V_74 |= V_158 ;
F_35 ( V_66 ) ;
return V_363 ;
}
V_66 -> V_71 . V_71 = V_71 ;
* V_174 = V_66 ;
V_174 = & V_66 -> V_22 ;
}
return 0 ;
}
return 0 ;
V_360:
V_53 -> V_74 |= V_158 ;
return V_124 ;
V_357:
free ( V_53 -> system ) ;
free ( V_53 -> V_72 ) ;
free ( V_53 ) ;
* V_355 = NULL ;
return V_124 ;
}
static enum V_354
F_175 ( struct V_14 * V_14 ,
struct V_52 * * V_355 ,
const char * V_1 , unsigned long V_2 ,
const char * V_203 )
{
int V_124 = F_174 ( V_355 , V_14 , V_1 , V_2 , V_203 ) ;
struct V_52 * V_53 = * V_355 ;
if ( V_53 == NULL )
return V_124 ;
if ( V_14 && F_32 ( V_14 , V_53 ) ) {
V_124 = V_356 ;
goto V_364;
}
#define F_176 0
if ( F_176 && V_53 -> V_186 . args )
F_166 ( V_53 -> V_186 . args ) ;
return 0 ;
V_364:
F_177 ( V_53 ) ;
return V_124 ;
}
enum V_354 F_178 ( struct V_14 * V_14 ,
struct V_52 * * V_355 ,
const char * V_1 ,
unsigned long V_2 , const char * V_203 )
{
return F_175 ( V_14 , V_355 , V_1 , V_2 , V_203 ) ;
}
enum V_354 F_179 ( struct V_14 * V_14 , const char * V_1 ,
unsigned long V_2 , const char * V_203 )
{
struct V_52 * V_53 = NULL ;
return F_175 ( V_14 , & V_53 , V_1 , V_2 , V_203 ) ;
}
int F_180 ( struct V_14 * V_14 V_161 ,
enum V_354 V_365 , char * V_1 , T_2 V_366 )
{
int V_367 ;
const char * V_368 ;
if ( V_365 >= 0 ) {
V_368 = F_181 ( V_365 , V_1 , V_366 ) ;
if ( V_368 != V_1 ) {
T_2 V_140 = strlen ( V_368 ) ;
memcpy ( V_1 , V_368 , F_182 ( V_366 - 1 , V_140 ) ) ;
* ( V_1 + F_182 ( V_366 - 1 , V_140 ) ) = '\0' ;
}
return 0 ;
}
if ( V_365 <= V_369 ||
V_365 >= V_370 )
return - 1 ;
V_367 = V_365 - V_369 - 1 ;
V_368 = V_371 [ V_367 ] ;
snprintf ( V_1 , V_366 , L_116 , V_368 ) ;
return 0 ;
}
int F_183 ( struct V_208 * V_209 , struct V_126 * V_71 ,
const char * V_72 , struct V_292 * V_293 ,
unsigned long long * V_170 , int V_185 )
{
if ( ! V_71 ) {
if ( V_185 )
F_122 ( V_209 , L_194 , V_72 ) ;
return - 1 ;
}
if ( F_104 ( V_71 , V_293 -> V_189 , V_170 ) ) {
if ( V_185 )
F_122 ( V_209 , L_195 , V_72 ) ;
return - 1 ;
}
return 0 ;
}
void * F_184 ( struct V_208 * V_209 , struct V_52 * V_53 ,
const char * V_72 , struct V_292 * V_293 ,
int * V_140 , int V_185 )
{
struct V_126 * V_71 ;
void * V_189 = V_293 -> V_189 ;
unsigned V_146 ;
int V_372 ;
if ( ! V_53 )
return NULL ;
V_71 = F_87 ( V_53 , V_72 ) ;
if ( ! V_71 ) {
if ( V_185 )
F_122 ( V_209 , L_194 , V_72 ) ;
return NULL ;
}
if ( ! V_140 )
V_140 = & V_372 ;
V_146 = V_71 -> V_146 ;
if ( V_71 -> V_74 & V_143 ) {
V_146 = F_100 ( V_53 -> V_14 ,
V_189 + V_146 , V_71 -> V_2 ) ;
* V_140 = V_146 >> 16 ;
V_146 &= 0xffff ;
} else
* V_140 = V_71 -> V_2 ;
return V_189 + V_146 ;
}
int F_185 ( struct V_208 * V_209 , struct V_52 * V_53 ,
const char * V_72 , struct V_292 * V_293 ,
unsigned long long * V_170 , int V_185 )
{
struct V_126 * V_71 ;
if ( ! V_53 )
return - 1 ;
V_71 = F_87 ( V_53 , V_72 ) ;
return F_183 ( V_209 , V_71 , V_72 , V_293 , V_170 , V_185 ) ;
}
int F_186 ( struct V_208 * V_209 , struct V_52 * V_53 ,
const char * V_72 , struct V_292 * V_293 ,
unsigned long long * V_170 , int V_185 )
{
struct V_126 * V_71 ;
if ( ! V_53 )
return - 1 ;
V_71 = F_99 ( V_53 , V_72 ) ;
return F_183 ( V_209 , V_71 , V_72 , V_293 , V_170 , V_185 ) ;
}
int F_187 ( struct V_208 * V_209 , struct V_52 * V_53 ,
const char * V_72 , struct V_292 * V_293 ,
unsigned long long * V_170 , int V_185 )
{
struct V_126 * V_71 ;
if ( ! V_53 )
return - 1 ;
V_71 = F_75 ( V_53 , V_72 ) ;
return F_183 ( V_209 , V_71 , V_72 , V_293 , V_170 , V_185 ) ;
}
int F_188 ( struct V_208 * V_209 , const char * V_50 ,
struct V_52 * V_53 , const char * V_72 ,
struct V_292 * V_293 , int V_185 )
{
struct V_126 * V_71 = F_87 ( V_53 , V_72 ) ;
unsigned long long V_170 ;
if ( ! V_71 )
goto V_373;
if ( F_104 ( V_71 , V_293 -> V_189 , & V_170 ) )
goto V_373;
return F_122 ( V_209 , V_50 , V_170 ) ;
V_373:
if ( V_185 )
F_122 ( V_209 , L_196 , V_72 ) ;
return - 1 ;
}
int F_189 ( struct V_208 * V_209 , const char * V_50 ,
struct V_52 * V_53 , const char * V_72 ,
struct V_292 * V_293 , int V_185 )
{
struct V_126 * V_71 = F_87 ( V_53 , V_72 ) ;
struct V_14 * V_14 = V_53 -> V_14 ;
unsigned long long V_170 ;
struct V_28 * V_35 ;
char V_160 [ 128 ] ;
if ( ! V_71 )
goto V_373;
if ( F_104 ( V_71 , V_293 -> V_189 , & V_170 ) )
goto V_373;
V_35 = F_21 ( V_14 , V_170 ) ;
if ( V_35 )
snprintf ( V_160 , 128 , L_197 , V_35 -> V_35 , V_35 -> V_31 - V_170 ) ;
else
sprintf ( V_160 , L_198 , V_170 ) ;
return F_122 ( V_209 , V_50 , V_160 ) ;
V_373:
if ( V_185 )
F_122 ( V_209 , L_196 , V_72 ) ;
return - 1 ;
}
static void F_94 ( struct V_180 * V_35 )
{
struct V_230 * V_234 ;
free ( V_35 -> V_72 ) ;
while ( V_35 -> V_234 ) {
V_234 = V_35 -> V_234 ;
V_35 -> V_234 = V_234 -> V_22 ;
free ( V_234 ) ;
}
free ( V_35 ) ;
}
int F_190 ( struct V_14 * V_14 ,
T_3 V_35 ,
enum V_374 V_375 ,
char * V_72 , ... )
{
struct V_180 * V_229 ;
struct V_230 * * V_376 ;
struct V_230 * V_231 ;
enum V_374 type ;
T_4 V_377 ;
int V_124 ;
V_229 = F_92 ( V_14 , V_72 ) ;
if ( V_229 ) {
F_173 ( L_199 , V_72 ) ;
F_93 ( V_14 , V_72 ) ;
}
V_229 = calloc ( 1 , sizeof( * V_229 ) ) ;
if ( ! V_229 ) {
F_50 ( L_200 ) ;
return V_356 ;
}
V_229 -> V_375 = V_375 ;
V_229 -> V_72 = F_12 ( V_72 ) ;
V_229 -> V_35 = V_35 ;
if ( ! V_229 -> V_72 ) {
F_50 ( L_201 ) ;
free ( V_229 ) ;
return V_356 ;
}
V_376 = & ( V_229 -> V_234 ) ;
va_start ( V_377 , V_72 ) ;
for (; ; ) {
type = va_arg ( V_377 , enum V_374 ) ;
if ( type == V_378 )
break;
if ( type >= V_379 ) {
F_50 ( L_202 , type ) ;
V_124 = V_380 ;
goto V_41;
}
V_231 = malloc ( sizeof( * V_231 ) ) ;
if ( ! V_231 ) {
F_50 ( L_203 ) ;
V_124 = V_356 ;
goto V_41;
}
V_231 -> type = type ;
V_231 -> V_22 = NULL ;
* V_376 = V_231 ;
V_376 = & ( V_231 -> V_22 ) ;
V_229 -> V_184 ++ ;
}
va_end ( V_377 ) ;
V_229 -> V_22 = V_14 -> V_182 ;
V_14 -> V_182 = V_229 ;
return 0 ;
V_41:
va_end ( V_377 ) ;
F_94 ( V_229 ) ;
return V_124 ;
}
int F_191 ( struct V_14 * V_14 ,
T_3 V_35 , char * V_72 )
{
struct V_180 * V_229 ;
V_229 = F_92 ( V_14 , V_72 ) ;
if ( V_229 && V_229 -> V_35 == V_35 ) {
F_93 ( V_14 , V_72 ) ;
return 0 ;
}
return - 1 ;
}
static struct V_52 * F_192 ( struct V_14 * V_14 , int V_56 ,
const char * V_349 ,
const char * V_350 )
{
struct V_52 * V_53 ;
if ( V_56 >= 0 ) {
V_53 = F_113 ( V_14 , V_56 ) ;
if ( ! V_53 )
return NULL ;
if ( V_350 && ( strcmp ( V_350 , V_53 -> V_72 ) != 0 ) )
return NULL ;
if ( V_349 && ( strcmp ( V_349 , V_53 -> system ) != 0 ) )
return NULL ;
} else {
V_53 = F_114 ( V_14 , V_349 , V_350 ) ;
if ( ! V_53 )
return NULL ;
}
return V_53 ;
}
int F_193 ( struct V_14 * V_14 , int V_56 ,
const char * V_349 , const char * V_350 ,
T_5 V_35 , void * V_315 )
{
struct V_52 * V_53 ;
struct V_351 * V_352 ;
V_53 = F_192 ( V_14 , V_56 , V_349 , V_350 ) ;
if ( V_53 == NULL )
goto V_381;
F_173 ( L_191 ,
V_53 -> V_56 , V_53 -> system , V_53 -> V_72 ) ;
V_53 -> V_313 = V_35 ;
V_53 -> V_315 = V_315 ;
return 0 ;
V_381:
V_352 = calloc ( 1 , sizeof( * V_352 ) ) ;
if ( ! V_352 ) {
F_50 ( L_204 ) ;
return V_356 ;
}
V_352 -> V_56 = V_56 ;
if ( V_350 )
V_352 -> V_350 = F_12 ( V_350 ) ;
if ( V_349 )
V_352 -> V_349 = F_12 ( V_349 ) ;
if ( ( V_350 && ! V_352 -> V_350 ) ||
( V_349 && ! V_352 -> V_349 ) ) {
F_50 ( L_205 ) ;
free ( ( void * ) V_352 -> V_350 ) ;
free ( ( void * ) V_352 -> V_349 ) ;
free ( V_352 ) ;
return V_356 ;
}
V_352 -> V_35 = V_35 ;
V_352 -> V_22 = V_14 -> V_353 ;
V_14 -> V_353 = V_352 ;
V_352 -> V_315 = V_315 ;
return - 1 ;
}
static int F_194 ( struct V_351 * V_313 , int V_56 ,
const char * V_349 , const char * V_350 ,
T_5 V_35 , void * V_315 )
{
if ( V_56 >= 0 && V_56 != V_313 -> V_56 )
return 0 ;
if ( V_350 && ( strcmp ( V_350 , V_313 -> V_350 ) != 0 ) )
return 0 ;
if ( V_349 && ( strcmp ( V_349 , V_313 -> V_349 ) != 0 ) )
return 0 ;
if ( V_35 != V_313 -> V_35 || V_315 != V_313 -> V_315 )
return 0 ;
return 1 ;
}
int F_195 ( struct V_14 * V_14 , int V_56 ,
const char * V_349 , const char * V_350 ,
T_5 V_35 , void * V_315 )
{
struct V_52 * V_53 ;
struct V_351 * V_352 ;
struct V_351 * * V_22 ;
V_53 = F_192 ( V_14 , V_56 , V_349 , V_350 ) ;
if ( V_53 == NULL )
goto V_381;
if ( V_53 -> V_313 == V_35 && V_53 -> V_315 == V_315 ) {
F_173 ( L_206 ,
V_53 -> V_56 , V_53 -> system , V_53 -> V_72 ) ;
V_53 -> V_313 = NULL ;
V_53 -> V_315 = NULL ;
return 0 ;
}
V_381:
for ( V_22 = & V_14 -> V_353 ; * V_22 ; V_22 = & ( * V_22 ) -> V_22 ) {
V_352 = * V_22 ;
if ( F_194 ( V_352 , V_56 , V_349 , V_350 ,
V_35 , V_315 ) )
break;
}
if ( ! ( * V_22 ) )
return - 1 ;
* V_22 = V_352 -> V_22 ;
F_171 ( V_352 ) ;
return 0 ;
}
struct V_14 * F_196 ( void )
{
struct V_14 * V_14 = calloc ( 1 , sizeof( * V_14 ) ) ;
if ( V_14 )
V_14 -> V_382 = 1 ;
return V_14 ;
}
void F_197 ( struct V_14 * V_14 )
{
V_14 -> V_382 ++ ;
}
void F_198 ( struct V_126 * V_71 )
{
free ( V_71 -> type ) ;
if ( V_71 -> V_136 != V_71 -> V_72 )
free ( V_71 -> V_136 ) ;
free ( V_71 -> V_72 ) ;
free ( V_71 ) ;
}
static void F_199 ( struct V_126 * V_71 )
{
struct V_126 * V_22 ;
while ( V_71 ) {
V_22 = V_71 -> V_22 ;
F_198 ( V_71 ) ;
V_71 = V_22 ;
}
}
static void F_200 ( struct V_150 * V_150 )
{
F_199 ( V_150 -> V_151 ) ;
F_199 ( V_150 -> V_129 ) ;
}
void F_177 ( struct V_52 * V_53 )
{
free ( V_53 -> V_72 ) ;
free ( V_53 -> system ) ;
F_200 ( & V_53 -> V_150 ) ;
free ( V_53 -> V_186 . V_150 ) ;
F_128 ( V_53 -> V_186 . args ) ;
free ( V_53 ) ;
}
void F_201 ( struct V_14 * V_14 )
{
struct V_15 * V_16 , * V_383 ;
struct V_32 * V_33 , * V_384 ;
struct V_46 * V_47 , * V_385 ;
struct V_180 * V_386 ;
struct V_351 * V_352 ;
int V_19 ;
if ( ! V_14 )
return;
V_16 = V_14 -> V_16 ;
V_33 = V_14 -> V_33 ;
V_47 = V_14 -> V_47 ;
V_14 -> V_382 -- ;
if ( V_14 -> V_382 )
return;
if ( V_14 -> V_18 ) {
for ( V_19 = 0 ; V_19 < V_14 -> V_20 ; V_19 ++ )
free ( V_14 -> V_18 [ V_19 ] . V_21 ) ;
free ( V_14 -> V_18 ) ;
}
while ( V_16 ) {
V_383 = V_16 -> V_22 ;
free ( V_16 -> V_21 ) ;
free ( V_16 ) ;
V_16 = V_383 ;
}
if ( V_14 -> V_28 ) {
for ( V_19 = 0 ; V_19 < ( int ) V_14 -> V_34 ; V_19 ++ ) {
free ( V_14 -> V_28 [ V_19 ] . V_35 ) ;
free ( V_14 -> V_28 [ V_19 ] . V_36 ) ;
}
free ( V_14 -> V_28 ) ;
}
while ( V_33 ) {
V_384 = V_33 -> V_22 ;
free ( V_33 -> V_35 ) ;
free ( V_33 -> V_36 ) ;
free ( V_33 ) ;
V_33 = V_384 ;
}
while ( V_14 -> V_182 ) {
V_386 = V_14 -> V_182 ;
V_14 -> V_182 = V_386 -> V_22 ;
F_94 ( V_386 ) ;
}
if ( V_14 -> V_43 ) {
for ( V_19 = 0 ; V_19 < ( int ) V_14 -> V_48 ; V_19 ++ )
free ( V_14 -> V_43 [ V_19 ] . V_49 ) ;
free ( V_14 -> V_43 ) ;
}
while ( V_47 ) {
V_385 = V_47 -> V_22 ;
free ( V_47 -> V_49 ) ;
free ( V_47 ) ;
V_47 = V_385 ;
}
for ( V_19 = 0 ; V_19 < V_14 -> V_55 ; V_19 ++ )
F_177 ( V_14 -> V_54 [ V_19 ] ) ;
while ( V_14 -> V_353 ) {
V_352 = V_14 -> V_353 ;
V_14 -> V_353 = V_352 -> V_22 ;
F_171 ( V_352 ) ;
}
free ( V_14 -> V_27 ) ;
free ( V_14 -> V_54 ) ;
free ( V_14 -> V_333 ) ;
free ( V_14 -> V_38 ) ;
free ( V_14 ) ;
}
void F_202 ( struct V_14 * V_14 )
{
F_201 ( V_14 ) ;
}
