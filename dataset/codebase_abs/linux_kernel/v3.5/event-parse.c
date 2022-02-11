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
printf ( L_4 ,
V_15 -> V_28 [ V_20 ] . V_31 ,
V_15 -> V_28 [ V_20 ] . V_35 ) ;
if ( V_15 -> V_28 [ V_20 ] . V_36 )
printf ( L_5 , V_15 -> V_28 [ V_20 ] . V_36 ) ;
else
printf ( L_6 ) ;
}
}
static int F_24 ( const void * V_9 , const void * V_10 )
{
const struct V_28 * V_29 = V_9 ;
const struct V_28 * V_30 = V_10 ;
if ( V_29 -> V_31 < V_30 -> V_31 )
return - 1 ;
if ( V_29 -> V_31 > V_30 -> V_31 )
return 1 ;
return 0 ;
}
static void F_25 ( struct V_15 * V_15 )
{
struct V_38 * V_39 ;
struct V_38 * V_18 ;
struct V_40 * V_40 ;
int V_20 ;
V_40 = F_7 ( sizeof( * V_40 ) * ( V_15 -> V_41 + 1 ) ) ;
V_39 = V_15 -> V_39 ;
V_20 = 0 ;
while ( V_39 ) {
V_40 [ V_20 ] . V_42 = V_39 -> V_42 ;
V_40 [ V_20 ] . V_31 = V_39 -> V_31 ;
V_20 ++ ;
V_18 = V_39 ;
V_39 = V_39 -> V_23 ;
free ( V_18 ) ;
}
qsort ( V_40 , V_15 -> V_41 , sizeof( * V_40 ) , F_24 ) ;
V_15 -> V_40 = V_40 ;
V_15 -> V_39 = NULL ;
}
static struct V_40 *
F_26 ( struct V_15 * V_15 , unsigned long long V_31 )
{
struct V_40 * V_42 ;
struct V_40 V_24 ;
if ( ! V_15 -> V_40 )
F_25 ( V_15 ) ;
V_24 . V_31 = V_31 ;
V_42 = bsearch ( & V_24 , V_15 -> V_40 , V_15 -> V_41 ,
sizeof( * V_15 -> V_40 ) , F_24 ) ;
return V_42 ;
}
int F_27 ( struct V_15 * V_15 , char * V_43 ,
unsigned long long V_31 )
{
struct V_38 * V_18 ;
V_18 = F_7 ( sizeof( * V_18 ) ) ;
V_18 -> V_23 = V_15 -> V_39 ;
V_15 -> V_39 = V_18 ;
V_18 -> V_42 = F_13 ( V_43 ) ;
V_18 -> V_31 = V_31 ;
V_15 -> V_41 ++ ;
return 0 ;
}
void F_28 ( struct V_15 * V_15 )
{
int V_20 ;
if ( ! V_15 -> V_40 )
F_25 ( V_15 ) ;
for ( V_20 = 0 ; V_20 < ( int ) V_15 -> V_41 ; V_20 ++ ) {
printf ( L_7 ,
V_15 -> V_40 [ V_20 ] . V_31 ,
V_15 -> V_40 [ V_20 ] . V_42 ) ;
}
}
static struct V_44 * F_29 ( void )
{
struct V_44 * V_45 ;
V_45 = F_7 ( sizeof( * V_45 ) ) ;
memset ( V_45 , 0 , sizeof( * V_45 ) ) ;
return V_45 ;
}
static void F_30 ( struct V_15 * V_15 , struct V_44 * V_45 )
{
int V_20 ;
if ( ! V_15 -> V_46 )
V_15 -> V_46 = F_7 ( sizeof( V_45 ) ) ;
else
V_15 -> V_46 =
realloc ( V_15 -> V_46 , sizeof( V_45 ) *
( V_15 -> V_47 + 1 ) ) ;
if ( ! V_15 -> V_46 )
F_14 ( L_8 ) ;
for ( V_20 = 0 ; V_20 < V_15 -> V_47 ; V_20 ++ ) {
if ( V_15 -> V_46 [ V_20 ] -> V_48 > V_45 -> V_48 )
break;
}
if ( V_20 < V_15 -> V_47 )
memmove ( & V_15 -> V_46 [ V_20 + 1 ] ,
& V_15 -> V_46 [ V_20 ] ,
sizeof( V_45 ) * ( V_15 -> V_47 - V_20 ) ) ;
V_15 -> V_46 [ V_20 ] = V_45 ;
V_15 -> V_47 ++ ;
V_45 -> V_15 = V_15 ;
}
static int F_31 ( enum V_49 type )
{
switch ( type ) {
case V_50 ... V_51 :
return 1 ;
case V_52 ... V_53 :
default:
return 0 ;
}
}
static void F_32 ( struct V_54 * V_55 )
{
struct V_54 * V_23 ;
while ( V_55 ) {
V_23 = V_55 -> V_23 ;
free ( V_55 -> V_56 ) ;
free ( V_55 -> V_57 ) ;
free ( V_55 ) ;
V_55 = V_23 ;
}
}
static void F_33 ( struct V_7 * V_8 )
{
struct V_7 * V_58 ;
if ( ! V_8 )
return;
switch ( V_8 -> type ) {
case V_59 :
free ( V_8 -> V_60 . V_60 ) ;
break;
case V_61 :
free ( V_8 -> V_62 . V_63 ) ;
break;
case V_64 :
F_33 ( V_8 -> V_65 . V_62 ) ;
free ( V_8 -> V_65 . V_66 ) ;
F_32 ( V_8 -> V_65 . V_65 ) ;
break;
case V_67 :
F_33 ( V_8 -> V_68 . V_62 ) ;
F_32 ( V_8 -> V_68 . V_69 ) ;
break;
case V_70 :
free ( V_8 -> V_71 . type ) ;
F_33 ( V_8 -> V_71 . V_18 ) ;
break;
case V_72 :
case V_73 :
free ( V_8 -> string . string ) ;
break;
case V_74 :
free ( V_8 -> V_75 . V_76 ) ;
break;
case V_77 :
free ( V_8 -> V_78 . V_78 ) ;
F_33 ( V_8 -> V_78 . V_79 ) ;
F_33 ( V_8 -> V_78 . V_80 ) ;
break;
case V_81 :
while ( V_8 -> V_35 . args ) {
V_58 = V_8 -> V_35 . args ;
V_8 -> V_35 . args = V_58 -> V_23 ;
F_33 ( V_58 ) ;
}
break;
case V_82 :
default:
break;
}
free ( V_8 ) ;
}
static enum V_49 F_34 ( int V_83 )
{
if ( V_83 == '\n' )
return V_84 ;
if ( isspace ( V_83 ) )
return V_85 ;
if ( isalnum ( V_83 ) || V_83 == '_' )
return V_50 ;
if ( V_83 == '\'' )
return V_51 ;
if ( V_83 == '"' )
return V_86 ;
if ( ! isprint ( V_83 ) )
return V_87 ;
if ( V_83 == '(' || V_83 == ')' || V_83 == ',' )
return V_53 ;
return V_88 ;
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
static enum V_49 F_38 ( char * * V_89 )
{
char V_1 [ V_90 ] ;
int V_83 , V_91 , V_92 , V_93 ;
int V_20 = 0 ;
int V_94 = 0 ;
enum V_49 type ;
* V_89 = NULL ;
V_83 = F_35 () ;
if ( V_83 < 0 )
return V_87 ;
type = F_34 ( V_83 ) ;
if ( type == V_87 )
return type ;
V_1 [ V_20 ++ ] = V_83 ;
switch ( type ) {
case V_84 :
case V_53 :
* V_89 = F_7 ( 2 ) ;
( * V_89 ) [ 0 ] = V_83 ;
( * V_89 ) [ 1 ] = 0 ;
return type ;
case V_88 :
switch ( V_83 ) {
case '-' :
V_93 = F_36 () ;
if ( V_93 == '>' ) {
V_1 [ V_20 ++ ] = F_35 () ;
break;
}
case '+' :
case '|' :
case '&' :
case '>' :
case '<' :
V_91 = V_83 ;
V_83 = F_36 () ;
if ( V_83 != V_91 )
goto V_95;
V_1 [ V_20 ++ ] = F_35 () ;
switch ( V_91 ) {
case '>' :
case '<' :
goto V_95;
default:
break;
}
break;
case '!' :
case '=' :
goto V_95;
default:
break;
}
V_1 [ V_20 ] = 0 ;
* V_89 = F_13 ( V_1 ) ;
return type ;
V_95:
V_83 = F_36 () ;
if ( V_83 == '=' )
V_1 [ V_20 ++ ] = F_35 () ;
goto V_96;
case V_86 :
case V_51 :
V_20 -- ;
V_92 = V_83 ;
V_91 = 0 ;
V_97:
do {
if ( V_20 == ( V_90 - 1 ) ) {
V_1 [ V_20 ] = 0 ;
if ( * V_89 ) {
* V_89 = realloc ( * V_89 , V_94 + V_90 ) ;
if ( ! * V_89 )
return V_87 ;
strcat ( * V_89 , V_1 ) ;
} else
* V_89 = F_13 ( V_1 ) ;
if ( ! * V_89 )
return V_87 ;
V_94 += V_90 ;
V_20 = 0 ;
}
V_91 = V_83 ;
V_83 = F_35 () ;
V_1 [ V_20 ++ ] = V_83 ;
if ( V_83 == '\\' && V_91 == '\\' )
V_91 = 0 ;
} while ( V_83 != V_92 || V_91 == '\\' );
V_20 -- ;
if ( type == V_86 ) {
unsigned long long V_98 = V_5 ;
do {
V_83 = F_35 () ;
} while ( isspace ( V_83 ) );
if ( V_83 == '"' )
goto V_97;
V_5 = V_98 ;
}
goto V_96;
case V_52 ... V_85 :
case V_50 :
default:
break;
}
while ( F_34 ( F_36 () ) == type ) {
if ( V_20 == ( V_90 - 1 ) ) {
V_1 [ V_20 ] = 0 ;
if ( * V_89 ) {
* V_89 = realloc ( * V_89 , V_94 + V_90 ) ;
if ( ! * V_89 )
return V_87 ;
strcat ( * V_89 , V_1 ) ;
} else
* V_89 = F_13 ( V_1 ) ;
if ( ! * V_89 )
return V_87 ;
V_94 += V_90 ;
V_20 = 0 ;
}
V_83 = F_35 () ;
V_1 [ V_20 ++ ] = V_83 ;
}
V_96:
V_1 [ V_20 ] = 0 ;
if ( * V_89 ) {
* V_89 = realloc ( * V_89 , V_94 + V_20 ) ;
if ( ! * V_89 )
return V_87 ;
strcat ( * V_89 , V_1 ) ;
} else
* V_89 = F_13 ( V_1 ) ;
if ( ! * V_89 )
return V_87 ;
if ( type == V_50 ) {
if ( strcmp ( * V_89 , L_9 ) == 0 ) {
free ( * V_89 ) ;
* V_89 = NULL ;
return F_39 ( L_10 , V_89 ) ;
} else if ( strcmp ( * V_89 , L_11 ) == 0 ) {
free ( * V_89 ) ;
* V_89 = NULL ;
return F_39 ( L_12 , V_89 ) ;
} else if ( strcmp ( * V_89 , L_13 ) == 0 ) {
free ( * V_89 ) ;
* V_89 = NULL ;
return F_39 ( L_14 , V_89 ) ;
}
}
return type ;
}
static enum V_49 F_39 ( const char * V_57 , char * * V_89 )
{
const char * V_99 ;
unsigned long long V_98 ;
unsigned long long V_100 ;
enum V_49 type ;
V_99 = V_3 ;
V_98 = V_5 ;
V_100 = V_4 ;
F_1 ( V_57 , strlen ( V_57 ) ) ;
type = F_38 ( V_89 ) ;
V_3 = V_99 ;
V_5 = V_98 ;
V_4 = V_100 ;
return type ;
}
static void F_40 ( char * V_89 )
{
if ( V_89 )
free ( V_89 ) ;
}
static enum V_49 F_41 ( char * * V_89 )
{
enum V_49 type ;
for (; ; ) {
type = F_38 ( V_89 ) ;
if ( type != V_85 )
return type ;
F_40 ( * V_89 ) ;
}
* V_89 = NULL ;
return V_87 ;
}
enum V_49 F_42 ( char * * V_89 )
{
return F_41 ( V_89 ) ;
}
void F_43 ( char * V_101 )
{
F_40 ( V_101 ) ;
}
static enum V_49 F_44 ( char * * V_89 )
{
enum V_49 type ;
for (; ; ) {
type = F_38 ( V_89 ) ;
if ( type != V_85 && type != V_84 )
return type ;
F_40 ( * V_89 ) ;
* V_89 = NULL ;
}
* V_89 = NULL ;
return V_87 ;
}
static int F_45 ( enum V_49 type , enum V_49 V_102 )
{
if ( type != V_102 ) {
F_46 ( L_15 ,
V_102 , type ) ;
return - 1 ;
}
return 0 ;
}
static int F_47 ( enum V_49 type , const char * V_101 ,
enum V_49 V_102 , const char * V_103 )
{
if ( type != V_102 ) {
F_46 ( L_15 ,
V_102 , type ) ;
return - 1 ;
}
if ( strcmp ( V_101 , V_103 ) != 0 ) {
F_46 ( L_16 ,
V_103 , V_101 ) ;
return - 1 ;
}
return 0 ;
}
static int F_48 ( enum V_49 V_102 , char * * V_89 , int V_104 )
{
enum V_49 type ;
if ( V_104 )
type = F_41 ( V_89 ) ;
else
type = F_44 ( V_89 ) ;
return F_45 ( type , V_102 ) ;
}
static int F_49 ( enum V_49 V_102 , char * * V_89 )
{
return F_48 ( V_102 , V_89 , 1 ) ;
}
static int F_50 ( enum V_49 V_102 , const char * V_57 ,
int V_104 )
{
enum V_49 type ;
char * V_101 ;
int V_105 ;
if ( V_104 )
type = F_41 ( & V_101 ) ;
else
type = F_44 ( & V_101 ) ;
V_105 = F_47 ( type , V_101 , V_102 , V_57 ) ;
F_40 ( V_101 ) ;
return V_105 ;
}
static int F_51 ( enum V_49 V_102 , const char * V_57 )
{
return F_50 ( V_102 , V_57 , 1 ) ;
}
static int F_52 ( enum V_49 V_102 , const char * V_57 )
{
return F_50 ( V_102 , V_57 , 0 ) ;
}
static char * F_53 ( void )
{
char * V_101 ;
if ( F_51 ( V_50 , L_17 ) < 0 )
return NULL ;
if ( F_51 ( V_88 , L_18 ) < 0 )
return NULL ;
if ( F_49 ( V_50 , & V_101 ) < 0 )
goto V_106;
return V_101 ;
V_106:
F_40 ( V_101 ) ;
return NULL ;
}
static int F_54 ( void )
{
char * V_101 ;
int V_48 ;
if ( F_52 ( V_50 , L_19 ) < 0 )
return - 1 ;
if ( F_51 ( V_88 , L_18 ) < 0 )
return - 1 ;
if ( F_49 ( V_50 , & V_101 ) < 0 )
goto V_106;
V_48 = strtoul ( V_101 , NULL , 0 ) ;
F_40 ( V_101 ) ;
return V_48 ;
V_106:
F_40 ( V_101 ) ;
return - 1 ;
}
static int F_55 ( struct V_107 * V_62 )
{
if ( ( V_62 -> V_65 & V_108 ) &&
( strstr ( V_62 -> type , L_20 ) || strstr ( V_62 -> type , L_21 ) ||
strstr ( V_62 -> type , L_22 ) ) )
return 1 ;
return 0 ;
}
static int F_56 ( struct V_107 * V_62 )
{
if ( strncmp ( V_62 -> type , L_23 , 10 ) == 0 )
return 1 ;
return 0 ;
}
static int F_57 ( struct V_107 * V_62 )
{
if ( strstr ( V_62 -> type , L_24 ) )
return 1 ;
return 0 ;
}
static int F_58 ( struct V_44 * V_45 , struct V_107 * * V_109 )
{
struct V_107 * V_62 = NULL ;
enum V_49 type ;
char * V_101 ;
char * V_110 ;
int V_111 = 0 ;
do {
type = F_41 ( & V_101 ) ;
if ( type == V_84 ) {
F_40 ( V_101 ) ;
return V_111 ;
}
V_111 ++ ;
if ( F_47 ( type , V_101 , V_50 , L_25 ) )
goto V_106;
F_40 ( V_101 ) ;
type = F_41 ( & V_101 ) ;
if ( V_45 -> V_65 & V_112 &&
type == V_50 && strcmp ( V_101 , L_26 ) == 0 ) {
F_40 ( V_101 ) ;
type = F_41 ( & V_101 ) ;
}
if ( F_47 ( type , V_101 , V_88 , L_18 ) < 0 )
goto V_106;
F_40 ( V_101 ) ;
if ( F_49 ( V_50 , & V_101 ) < 0 )
goto V_106;
V_110 = V_101 ;
V_62 = F_7 ( sizeof( * V_62 ) ) ;
memset ( V_62 , 0 , sizeof( * V_62 ) ) ;
V_62 -> V_45 = V_45 ;
for (; ; ) {
type = F_41 ( & V_101 ) ;
if ( type == V_50 ||
( type == V_88 && strcmp ( V_101 , L_27 ) == 0 ) ||
( V_45 -> V_65 & V_112 &&
type == V_88 && strcmp ( V_101 , L_28 ) == 0 ) ) {
if ( strcmp ( V_101 , L_27 ) == 0 )
V_62 -> V_65 |= V_113 ;
if ( V_62 -> type ) {
V_62 -> type = realloc ( V_62 -> type ,
strlen ( V_62 -> type ) +
strlen ( V_110 ) + 2 ) ;
strcat ( V_62 -> type , L_29 ) ;
strcat ( V_62 -> type , V_110 ) ;
free ( V_110 ) ;
} else
V_62 -> type = V_110 ;
V_110 = V_101 ;
continue;
}
break;
}
if ( ! V_62 -> type ) {
F_14 ( L_30 ) ;
goto V_106;
}
V_62 -> V_63 = V_110 ;
if ( F_45 ( type , V_88 ) )
goto V_106;
if ( strcmp ( V_101 , L_31 ) == 0 ) {
enum V_49 V_114 = type ;
char * V_115 = V_101 ;
int V_116 ;
V_62 -> V_65 |= V_108 ;
type = F_41 ( & V_101 ) ;
if ( type == V_50 )
V_62 -> V_117 = strtoul ( V_101 , NULL , 0 ) ;
else
V_62 -> V_117 = 0 ;
while ( strcmp ( V_101 , L_32 ) != 0 ) {
if ( V_114 == V_50 &&
type == V_50 )
V_116 = 2 ;
else
V_116 = 1 ;
V_114 = type ;
V_115 = realloc ( V_115 ,
strlen ( V_115 ) +
strlen ( V_101 ) + V_116 ) ;
if ( V_116 == 2 )
strcat ( V_115 , L_29 ) ;
strcat ( V_115 , V_101 ) ;
V_62 -> V_117 = strtoul ( V_101 , NULL , 0 ) ;
F_40 ( V_101 ) ;
type = F_41 ( & V_101 ) ;
if ( type == V_87 ) {
F_14 ( L_33 ) ;
goto V_106;
}
}
F_40 ( V_101 ) ;
V_115 = realloc ( V_115 , strlen ( V_115 ) + 2 ) ;
strcat ( V_115 , L_32 ) ;
type = F_41 ( & V_101 ) ;
if ( type == V_50 ) {
V_62 -> type = realloc ( V_62 -> type ,
strlen ( V_62 -> type ) +
strlen ( V_62 -> V_63 ) +
strlen ( V_115 ) + 2 ) ;
strcat ( V_62 -> type , L_29 ) ;
strcat ( V_62 -> type , V_62 -> V_63 ) ;
F_40 ( V_62 -> V_63 ) ;
strcat ( V_62 -> type , V_115 ) ;
V_62 -> V_63 = V_101 ;
type = F_41 ( & V_101 ) ;
} else {
V_62 -> type = realloc ( V_62 -> type ,
strlen ( V_62 -> type ) +
strlen ( V_115 ) + 1 ) ;
strcat ( V_62 -> type , V_115 ) ;
}
free ( V_115 ) ;
}
if ( F_55 ( V_62 ) )
V_62 -> V_65 |= V_118 ;
if ( F_56 ( V_62 ) )
V_62 -> V_65 |= V_119 ;
if ( F_57 ( V_62 ) )
V_62 -> V_65 |= V_120 ;
if ( F_47 ( type , V_101 , V_88 , L_34 ) )
goto V_106;
F_40 ( V_101 ) ;
if ( F_51 ( V_50 , L_35 ) < 0 )
goto V_121;
if ( F_51 ( V_88 , L_18 ) < 0 )
goto V_121;
if ( F_49 ( V_50 , & V_101 ) )
goto V_106;
V_62 -> V_122 = strtoul ( V_101 , NULL , 0 ) ;
F_40 ( V_101 ) ;
if ( F_51 ( V_88 , L_34 ) < 0 )
goto V_121;
if ( F_51 ( V_50 , L_36 ) < 0 )
goto V_121;
if ( F_51 ( V_88 , L_18 ) < 0 )
goto V_121;
if ( F_49 ( V_50 , & V_101 ) )
goto V_106;
V_62 -> V_2 = strtoul ( V_101 , NULL , 0 ) ;
F_40 ( V_101 ) ;
if ( F_51 ( V_88 , L_34 ) < 0 )
goto V_121;
type = F_41 ( & V_101 ) ;
if ( type != V_84 ) {
if ( F_47 ( type , V_101 , V_50 , L_37 ) )
goto V_106;
F_40 ( V_101 ) ;
if ( F_51 ( V_88 , L_18 ) < 0 )
goto V_121;
if ( F_49 ( V_50 , & V_101 ) )
goto V_106;
F_40 ( V_101 ) ;
if ( F_51 ( V_88 , L_34 ) < 0 )
goto V_121;
if ( F_49 ( V_84 , & V_101 ) )
goto V_106;
}
F_40 ( V_101 ) ;
if ( V_62 -> V_65 & V_108 ) {
if ( V_62 -> V_117 )
V_62 -> V_123 = V_62 -> V_2 / V_62 -> V_117 ;
else if ( V_62 -> V_65 & V_118 )
V_62 -> V_123 = 1 ;
else
V_62 -> V_123 = V_45 -> V_15 -> V_124 ;
} else
V_62 -> V_123 = V_62 -> V_2 ;
* V_109 = V_62 ;
V_109 = & V_62 -> V_23 ;
} while ( 1 );
return 0 ;
V_106:
F_40 ( V_101 ) ;
V_121:
if ( V_62 ) {
free ( V_62 -> type ) ;
free ( V_62 -> V_63 ) ;
free ( V_62 ) ;
}
return - 1 ;
}
static int F_59 ( struct V_44 * V_45 )
{
char * V_101 ;
int V_105 ;
if ( F_52 ( V_50 , L_38 ) < 0 )
return - 1 ;
if ( F_51 ( V_88 , L_18 ) < 0 )
return - 1 ;
if ( F_49 ( V_84 , & V_101 ) )
goto V_106;
F_40 ( V_101 ) ;
V_105 = F_58 ( V_45 , & V_45 -> V_125 . V_126 ) ;
if ( V_105 < 0 )
return V_105 ;
V_45 -> V_125 . V_127 = V_105 ;
V_105 = F_58 ( V_45 , & V_45 -> V_125 . V_109 ) ;
if ( V_105 < 0 )
return V_105 ;
V_45 -> V_125 . V_128 = V_105 ;
return 0 ;
V_106:
F_40 ( V_101 ) ;
return - 1 ;
}
static enum V_49
F_60 ( struct V_44 * V_45 , struct V_7 * V_8 , char * * V_89 )
{
enum V_49 type ;
char * V_101 ;
type = F_41 ( & V_101 ) ;
* V_89 = V_101 ;
return F_61 ( V_45 , V_8 , V_89 , type ) ;
}
static enum V_49
F_62 ( struct V_44 * V_45 , struct V_7 * V_129 , char * * V_89 )
{
struct V_7 * V_8 , * V_79 , * V_80 ;
enum V_49 type ;
char * V_101 = NULL ;
V_8 = F_6 () ;
V_79 = F_6 () ;
V_80 = F_6 () ;
V_8 -> type = V_77 ;
V_8 -> V_78 . V_79 = V_79 ;
V_8 -> V_78 . V_80 = V_80 ;
* V_89 = NULL ;
type = F_60 ( V_45 , V_79 , & V_101 ) ;
V_130:
if ( type == V_88 && strcmp ( V_101 , L_18 ) != 0 ) {
type = F_63 ( V_45 , V_79 , & V_101 ) ;
goto V_130;
}
if ( F_47 ( type , V_101 , V_88 , L_18 ) )
goto V_131;
V_8 -> V_78 . V_78 = V_101 ;
type = F_60 ( V_45 , V_80 , & V_101 ) ;
V_129 -> V_78 . V_80 = V_8 ;
* V_89 = V_101 ;
return type ;
V_131:
V_129 -> V_78 . V_80 = NULL ;
F_40 ( V_101 ) ;
F_33 ( V_8 ) ;
return V_52 ;
}
static enum V_49
F_64 ( struct V_44 * V_45 , struct V_7 * V_129 , char * * V_89 )
{
struct V_7 * V_8 ;
enum V_49 type ;
char * V_101 = NULL ;
V_8 = F_6 () ;
* V_89 = NULL ;
type = F_60 ( V_45 , V_8 , & V_101 ) ;
if ( F_47 ( type , V_101 , V_88 , L_32 ) )
goto V_131;
V_129 -> V_78 . V_80 = V_8 ;
F_40 ( V_101 ) ;
type = F_44 ( & V_101 ) ;
* V_89 = V_101 ;
return type ;
V_131:
F_40 ( * V_89 ) ;
* V_89 = NULL ;
F_33 ( V_8 ) ;
return V_52 ;
}
static int F_65 ( char * V_78 )
{
if ( ! V_78 [ 1 ] ) {
switch ( V_78 [ 0 ] ) {
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
F_46 ( L_39 , V_78 [ 0 ] ) ;
return - 1 ;
}
} else {
if ( strcmp ( V_78 , L_40 ) == 0 ||
strcmp ( V_78 , L_41 ) == 0 ) {
return 3 ;
} else if ( strcmp ( V_78 , L_42 ) == 0 ||
strcmp ( V_78 , L_43 ) == 0 ) {
return 8 ;
} else if ( strcmp ( V_78 , L_44 ) == 0 ||
strcmp ( V_78 , L_45 ) == 0 ) {
return 9 ;
} else if ( strcmp ( V_78 , L_46 ) == 0 ||
strcmp ( V_78 , L_47 ) == 0 ) {
return 10 ;
} else if ( strcmp ( V_78 , L_48 ) == 0 ) {
return 14 ;
} else if ( strcmp ( V_78 , L_49 ) == 0 ) {
return 15 ;
} else {
F_46 ( L_50 , V_78 ) ;
return - 1 ;
}
}
}
static int F_66 ( struct V_7 * V_8 )
{
if ( ! V_8 -> V_78 . V_79 || V_8 -> V_78 . V_79 -> type == V_82 )
V_8 -> V_78 . V_132 = 0 ;
else
V_8 -> V_78 . V_132 = F_65 ( V_8 -> V_78 . V_78 ) ;
return V_8 -> V_78 . V_132 ;
}
static enum V_49
F_63 ( struct V_44 * V_45 , struct V_7 * V_8 , char * * V_89 )
{
struct V_7 * V_79 , * V_80 = NULL ;
enum V_49 type ;
char * V_101 ;
V_101 = * V_89 ;
if ( V_8 -> type == V_77 && ! V_8 -> V_78 . V_79 ) {
if ( V_101 [ 1 ] ) {
F_14 ( L_51 , V_101 ) ;
goto V_131;
}
switch ( V_101 [ 0 ] ) {
case '~' :
case '!' :
case '+' :
case '-' :
break;
default:
F_46 ( L_51 , V_101 ) ;
goto V_131;
}
V_79 = F_6 () ;
V_79 -> type = V_82 ;
V_8 -> V_78 . V_79 = V_79 ;
V_80 = F_6 () ;
V_8 -> V_78 . V_80 = V_80 ;
* V_89 = NULL ;
type = F_60 ( V_45 , V_80 , V_89 ) ;
} else if ( strcmp ( V_101 , L_52 ) == 0 ) {
V_79 = F_6 () ;
* V_79 = * V_8 ;
V_8 -> type = V_77 ;
V_8 -> V_78 . V_78 = V_101 ;
V_8 -> V_78 . V_79 = V_79 ;
V_8 -> V_78 . V_132 = 0 ;
type = F_62 ( V_45 , V_8 , V_89 ) ;
} else if ( strcmp ( V_101 , L_42 ) == 0 ||
strcmp ( V_101 , L_43 ) == 0 ||
strcmp ( V_101 , L_53 ) == 0 ||
strcmp ( V_101 , L_54 ) == 0 ||
strcmp ( V_101 , L_48 ) == 0 ||
strcmp ( V_101 , L_49 ) == 0 ||
strcmp ( V_101 , L_55 ) == 0 ||
strcmp ( V_101 , L_56 ) == 0 ||
strcmp ( V_101 , L_27 ) == 0 ||
strcmp ( V_101 , L_57 ) == 0 ||
strcmp ( V_101 , L_58 ) == 0 ||
strcmp ( V_101 , L_59 ) == 0 ||
strcmp ( V_101 , L_60 ) == 0 ||
strcmp ( V_101 , L_46 ) == 0 ||
strcmp ( V_101 , L_47 ) == 0 ) {
V_79 = F_6 () ;
* V_79 = * V_8 ;
V_8 -> type = V_77 ;
V_8 -> V_78 . V_78 = V_101 ;
V_8 -> V_78 . V_79 = V_79 ;
if ( F_66 ( V_8 ) == - 1 ) {
V_45 -> V_65 |= V_133 ;
V_8 -> V_78 . V_78 = NULL ;
goto V_131;
}
type = F_44 ( & V_101 ) ;
* V_89 = V_101 ;
if ( ( strcmp ( V_8 -> V_78 . V_78 , L_27 ) == 0 ) &&
type == V_53 && ( strcmp ( V_101 , L_61 ) == 0 ) ) {
if ( V_79 -> type != V_59 )
F_14 ( L_62 ) ;
V_79 -> V_60 . V_60 = realloc ( V_79 -> V_60 . V_60 ,
strlen ( V_79 -> V_60 . V_60 ) + 3 ) ;
strcat ( V_79 -> V_60 . V_60 , L_63 ) ;
free ( V_8 -> V_78 . V_78 ) ;
* V_8 = * V_79 ;
free ( V_79 ) ;
return type ;
}
V_80 = F_6 () ;
type = F_61 ( V_45 , V_80 , V_89 , type ) ;
V_8 -> V_78 . V_80 = V_80 ;
} else if ( strcmp ( V_101 , L_31 ) == 0 ) {
V_79 = F_6 () ;
* V_79 = * V_8 ;
V_8 -> type = V_77 ;
V_8 -> V_78 . V_78 = V_101 ;
V_8 -> V_78 . V_79 = V_79 ;
V_8 -> V_78 . V_132 = 0 ;
type = F_64 ( V_45 , V_8 , V_89 ) ;
} else {
F_46 ( L_50 , V_101 ) ;
V_45 -> V_65 |= V_133 ;
goto V_131;
}
if ( type == V_88 && strcmp ( * V_89 , L_18 ) != 0 ) {
int V_132 ;
V_132 = F_65 ( * V_89 ) ;
if ( V_132 > V_8 -> V_78 . V_132 )
return F_63 ( V_45 , V_8 , V_89 ) ;
return F_63 ( V_45 , V_80 , V_89 ) ;
}
return type ;
V_131:
F_40 ( V_101 ) ;
* V_89 = NULL ;
return V_52 ;
}
static enum V_49
F_67 ( struct V_44 * V_45 V_134 , struct V_7 * V_8 ,
char * * V_89 )
{
enum V_49 type ;
char * V_62 ;
char * V_101 ;
if ( F_51 ( V_88 , L_64 ) < 0 )
goto V_135;
if ( F_49 ( V_50 , & V_101 ) < 0 )
goto V_131;
V_62 = V_101 ;
V_8 -> type = V_61 ;
V_8 -> V_62 . V_63 = V_62 ;
if ( V_136 ) {
V_8 -> V_62 . V_62 = F_68 ( V_45 , V_8 -> V_62 . V_63 ) ;
V_8 -> V_62 . V_62 -> V_65 |= V_137 ;
V_136 = 0 ;
} else if ( V_138 ) {
V_8 -> V_62 . V_62 = F_68 ( V_45 , V_8 -> V_62 . V_63 ) ;
V_8 -> V_62 . V_62 -> V_65 |= V_139 ;
V_138 = 0 ;
}
type = F_41 ( & V_101 ) ;
* V_89 = V_101 ;
return type ;
V_131:
F_40 ( V_101 ) ;
V_135:
* V_89 = NULL ;
return V_52 ;
}
static unsigned long long
F_69 ( unsigned long long V_140 , const char * type , int V_141 )
{
int V_142 = 0 ;
char * V_143 ;
int V_116 ;
V_116 = strlen ( type ) ;
if ( V_141 ) {
if ( type [ V_116 - 1 ] != '*' ) {
F_46 ( L_65 ) ;
return V_140 ;
}
V_143 = F_7 ( V_116 ) ;
memcpy ( V_143 , type , V_116 ) ;
V_143 [ V_116 - 2 ] = 0 ;
V_140 = F_69 ( V_140 , V_143 , 0 ) ;
free ( V_143 ) ;
return V_140 ;
}
if ( type [ V_116 - 1 ] == '*' )
return V_140 ;
if ( strncmp ( type , L_66 , 6 ) == 0 )
return V_140 ;
if ( strcmp ( type , L_21 ) == 0 )
return V_140 & 0xff ;
if ( strcmp ( type , L_67 ) == 0 )
return V_140 & 0xffff ;
if ( strcmp ( type , L_68 ) == 0 )
return V_140 & 0xffffffff ;
if ( strcmp ( type , L_69 ) == 0 ||
strcmp ( type , L_70 ) )
return V_140 ;
if ( strcmp ( type , L_22 ) == 0 )
return ( unsigned long long ) ( char ) V_140 & 0xff ;
if ( strcmp ( type , L_71 ) == 0 )
return ( unsigned long long ) ( short ) V_140 & 0xffff ;
if ( strcmp ( type , L_72 ) == 0 )
return ( unsigned long long ) ( int ) V_140 & 0xffffffff ;
if ( strncmp ( type , L_73 , 9 ) == 0 ) {
V_142 = 0 ;
type += 9 ;
}
if ( strcmp ( type , L_20 ) == 0 ) {
if ( V_142 )
return ( unsigned long long ) ( char ) V_140 & 0xff ;
else
return V_140 & 0xff ;
}
if ( strcmp ( type , L_74 ) == 0 ) {
if ( V_142 )
return ( unsigned long long ) ( short ) V_140 & 0xffff ;
else
return V_140 & 0xffff ;
}
if ( strcmp ( type , L_75 ) == 0 ) {
if ( V_142 )
return ( unsigned long long ) ( int ) V_140 & 0xffffffff ;
else
return V_140 & 0xffffffff ;
}
return V_140 ;
}
static unsigned long long
F_70 ( unsigned long long V_140 , struct V_7 * V_8 , int V_141 )
{
if ( V_8 -> type != V_70 )
F_14 ( L_76 ) ;
return F_69 ( V_140 , V_8 -> V_71 . type , V_141 ) ;
}
static int F_71 ( struct V_7 * V_8 , long long * V_140 )
{
long long V_79 , V_80 ;
int V_105 = 1 ;
switch ( V_8 -> type ) {
case V_59 :
* V_140 = strtoll ( V_8 -> V_60 . V_60 , NULL , 0 ) ;
break;
case V_70 :
V_105 = F_71 ( V_8 -> V_71 . V_18 , V_140 ) ;
if ( ! V_105 )
break;
* V_140 = F_70 ( * V_140 , V_8 , 0 ) ;
break;
case V_77 :
switch ( V_8 -> V_78 . V_78 [ 0 ] ) {
case '|' :
V_105 = F_71 ( V_8 -> V_78 . V_79 , & V_79 ) ;
if ( ! V_105 )
break;
V_105 = F_71 ( V_8 -> V_78 . V_80 , & V_80 ) ;
if ( ! V_105 )
break;
if ( V_8 -> V_78 . V_78 [ 1 ] )
* V_140 = V_79 || V_80 ;
else
* V_140 = V_79 | V_80 ;
break;
case '&' :
V_105 = F_71 ( V_8 -> V_78 . V_79 , & V_79 ) ;
if ( ! V_105 )
break;
V_105 = F_71 ( V_8 -> V_78 . V_80 , & V_80 ) ;
if ( ! V_105 )
break;
if ( V_8 -> V_78 . V_78 [ 1 ] )
* V_140 = V_79 && V_80 ;
else
* V_140 = V_79 & V_80 ;
break;
case '<' :
V_105 = F_71 ( V_8 -> V_78 . V_79 , & V_79 ) ;
if ( ! V_105 )
break;
V_105 = F_71 ( V_8 -> V_78 . V_80 , & V_80 ) ;
if ( ! V_105 )
break;
switch ( V_8 -> V_78 . V_78 [ 1 ] ) {
case 0 :
* V_140 = V_79 < V_80 ;
break;
case '<' :
* V_140 = V_79 << V_80 ;
break;
case '=' :
* V_140 = V_79 <= V_80 ;
break;
default:
F_46 ( L_50 , V_8 -> V_78 . V_78 ) ;
V_105 = 0 ;
}
break;
case '>' :
V_105 = F_71 ( V_8 -> V_78 . V_79 , & V_79 ) ;
if ( ! V_105 )
break;
V_105 = F_71 ( V_8 -> V_78 . V_80 , & V_80 ) ;
if ( ! V_105 )
break;
switch ( V_8 -> V_78 . V_78 [ 1 ] ) {
case 0 :
* V_140 = V_79 > V_80 ;
break;
case '>' :
* V_140 = V_79 >> V_80 ;
break;
case '=' :
* V_140 = V_79 >= V_80 ;
break;
default:
F_46 ( L_50 , V_8 -> V_78 . V_78 ) ;
V_105 = 0 ;
}
break;
case '=' :
V_105 = F_71 ( V_8 -> V_78 . V_79 , & V_79 ) ;
if ( ! V_105 )
break;
V_105 = F_71 ( V_8 -> V_78 . V_80 , & V_80 ) ;
if ( ! V_105 )
break;
if ( V_8 -> V_78 . V_78 [ 1 ] != '=' ) {
F_46 ( L_50 , V_8 -> V_78 . V_78 ) ;
V_105 = 0 ;
} else
* V_140 = V_79 == V_80 ;
break;
case '!' :
V_105 = F_71 ( V_8 -> V_78 . V_79 , & V_79 ) ;
if ( ! V_105 )
break;
V_105 = F_71 ( V_8 -> V_78 . V_80 , & V_80 ) ;
if ( ! V_105 )
break;
switch ( V_8 -> V_78 . V_78 [ 1 ] ) {
case '=' :
* V_140 = V_79 != V_80 ;
break;
default:
F_46 ( L_50 , V_8 -> V_78 . V_78 ) ;
V_105 = 0 ;
}
break;
case '-' :
if ( V_8 -> V_78 . V_79 -> type == V_82 )
V_79 = 0 ;
else
V_105 = F_71 ( V_8 -> V_78 . V_79 , & V_79 ) ;
if ( ! V_105 )
break;
V_105 = F_71 ( V_8 -> V_78 . V_80 , & V_80 ) ;
if ( ! V_105 )
break;
* V_140 = V_79 - V_80 ;
break;
case '+' :
if ( V_8 -> V_78 . V_79 -> type == V_82 )
V_79 = 0 ;
else
V_105 = F_71 ( V_8 -> V_78 . V_79 , & V_79 ) ;
if ( ! V_105 )
break;
V_105 = F_71 ( V_8 -> V_78 . V_80 , & V_80 ) ;
if ( ! V_105 )
break;
* V_140 = V_79 + V_80 ;
break;
default:
F_46 ( L_50 , V_8 -> V_78 . V_78 ) ;
V_105 = 0 ;
}
break;
case V_82 :
case V_61 ... V_67 :
case V_72 :
case V_73 :
default:
F_46 ( L_77 , V_8 -> type ) ;
V_105 = 0 ;
}
return V_105 ;
}
static char * F_72 ( struct V_7 * V_8 )
{
long long V_140 ;
static char V_1 [ 20 ] ;
switch ( V_8 -> type ) {
case V_59 :
return V_8 -> V_60 . V_60 ;
case V_70 :
return F_72 ( V_8 -> V_71 . V_18 ) ;
case V_77 :
if ( ! F_71 ( V_8 , & V_140 ) )
break;
sprintf ( V_1 , L_78 , V_140 ) ;
return V_1 ;
case V_82 :
case V_61 ... V_67 :
case V_72 :
case V_73 :
default:
F_14 ( L_77 , V_8 -> type ) ;
break;
}
return NULL ;
}
static enum V_49
F_73 ( struct V_44 * V_45 , struct V_54 * * V_144 , char * * V_89 )
{
enum V_49 type ;
struct V_7 * V_8 = NULL ;
struct V_54 * V_62 ;
char * V_101 = * V_89 ;
char * V_56 ;
do {
F_40 ( V_101 ) ;
type = F_44 ( & V_101 ) ;
if ( F_47 ( type , V_101 , V_88 , L_79 ) )
break;
V_8 = F_6 () ;
F_40 ( V_101 ) ;
type = F_60 ( V_45 , V_8 , & V_101 ) ;
if ( type == V_88 )
type = F_63 ( V_45 , V_8 , & V_101 ) ;
if ( type == V_52 )
goto V_131;
if ( F_47 ( type , V_101 , V_53 , L_80 ) )
goto V_131;
V_62 = F_7 ( sizeof( * V_62 ) ) ;
memset ( V_62 , 0 , sizeof( * V_62 ) ) ;
V_56 = F_72 ( V_8 ) ;
if ( V_56 == NULL )
goto V_131;
V_62 -> V_56 = F_13 ( V_56 ) ;
F_33 ( V_8 ) ;
V_8 = F_6 () ;
F_40 ( V_101 ) ;
type = F_60 ( V_45 , V_8 , & V_101 ) ;
if ( F_47 ( type , V_101 , V_88 , L_81 ) )
goto V_131;
V_56 = F_72 ( V_8 ) ;
if ( V_56 == NULL )
goto V_131;
V_62 -> V_57 = F_13 ( V_56 ) ;
F_33 ( V_8 ) ;
V_8 = NULL ;
* V_144 = V_62 ;
V_144 = & V_62 -> V_23 ;
F_40 ( V_101 ) ;
type = F_44 ( & V_101 ) ;
} while ( type == V_53 && strcmp ( V_101 , L_80 ) == 0 );
* V_89 = V_101 ;
return type ;
V_131:
F_33 ( V_8 ) ;
F_40 ( V_101 ) ;
* V_89 = NULL ;
return V_52 ;
}
static enum V_49
F_74 ( struct V_44 * V_45 , struct V_7 * V_8 , char * * V_89 )
{
struct V_7 * V_62 ;
enum V_49 type ;
char * V_101 ;
memset ( V_8 , 0 , sizeof( * V_8 ) ) ;
V_8 -> type = V_64 ;
V_62 = F_6 () ;
type = F_60 ( V_45 , V_62 , & V_101 ) ;
while ( type == V_88 )
type = F_63 ( V_45 , V_62 , & V_101 ) ;
if ( F_47 ( type , V_101 , V_53 , L_80 ) )
goto V_131;
F_40 ( V_101 ) ;
V_8 -> V_65 . V_62 = V_62 ;
type = F_44 ( & V_101 ) ;
if ( F_31 ( type ) ) {
V_8 -> V_65 . V_66 = V_101 ;
type = F_44 ( & V_101 ) ;
}
if ( F_47 ( type , V_101 , V_53 , L_80 ) )
goto V_131;
type = F_73 ( V_45 , & V_8 -> V_65 . V_65 , & V_101 ) ;
if ( F_47 ( type , V_101 , V_53 , L_61 ) )
goto V_131;
F_40 ( V_101 ) ;
type = F_44 ( V_89 ) ;
return type ;
V_131:
F_40 ( V_101 ) ;
* V_89 = NULL ;
return V_52 ;
}
static enum V_49
F_75 ( struct V_44 * V_45 , struct V_7 * V_8 , char * * V_89 )
{
struct V_7 * V_62 ;
enum V_49 type ;
char * V_101 ;
memset ( V_8 , 0 , sizeof( * V_8 ) ) ;
V_8 -> type = V_67 ;
V_62 = F_6 () ;
type = F_60 ( V_45 , V_62 , & V_101 ) ;
if ( F_47 ( type , V_101 , V_53 , L_80 ) )
goto V_131;
V_8 -> V_68 . V_62 = V_62 ;
type = F_73 ( V_45 , & V_8 -> V_68 . V_69 , & V_101 ) ;
if ( F_47 ( type , V_101 , V_53 , L_61 ) )
goto V_131;
F_40 ( V_101 ) ;
type = F_44 ( V_89 ) ;
return type ;
V_131:
F_40 ( V_101 ) ;
* V_89 = NULL ;
return V_52 ;
}
static enum V_49
F_76 ( struct V_44 * V_45 , struct V_7 * V_8 , char * * V_89 )
{
struct V_107 * V_62 ;
enum V_49 type ;
char * V_101 ;
memset ( V_8 , 0 , sizeof( * V_8 ) ) ;
V_8 -> type = V_74 ;
type = F_41 ( & V_101 ) ;
* V_89 = V_101 ;
if ( type != V_50 )
goto V_131;
V_62 = F_77 ( V_45 , V_101 ) ;
if ( ! V_62 )
goto V_131;
V_8 -> V_75 . V_62 = V_62 ;
V_8 -> V_75 . V_76 = 0 ;
if ( F_51 ( V_53 , L_61 ) < 0 )
goto V_131;
F_40 ( V_101 ) ;
type = F_44 ( & V_101 ) ;
* V_89 = V_101 ;
if ( type != V_88 || strcmp ( V_101 , L_31 ) != 0 )
return type ;
F_40 ( V_101 ) ;
V_8 = F_6 () ;
type = F_60 ( V_45 , V_8 , & V_101 ) ;
if ( type == V_52 )
goto V_145;
if ( ! F_47 ( type , V_101 , V_88 , L_32 ) )
goto V_145;
F_40 ( V_101 ) ;
type = F_44 ( V_89 ) ;
return type ;
V_145:
F_33 ( V_8 ) ;
V_131:
F_40 ( V_101 ) ;
* V_89 = NULL ;
return V_52 ;
}
static enum V_49
F_78 ( struct V_44 * V_45 , struct V_7 * V_8 , char * * V_89 )
{
struct V_7 * V_146 ;
enum V_49 type ;
char * V_101 ;
type = F_60 ( V_45 , V_8 , & V_101 ) ;
if ( type == V_52 )
goto V_131;
if ( type == V_88 )
type = F_63 ( V_45 , V_8 , & V_101 ) ;
if ( type == V_52 )
goto V_131;
if ( F_47 ( type , V_101 , V_53 , L_61 ) )
goto V_131;
F_40 ( V_101 ) ;
type = F_44 ( & V_101 ) ;
if ( F_31 ( type ) ||
( type == V_53 && strcmp ( V_101 , L_82 ) == 0 ) ) {
if ( V_8 -> type != V_59 )
F_14 ( L_83 ) ;
V_146 = F_6 () ;
V_8 -> type = V_70 ;
V_8 -> V_71 . type = V_8 -> V_60 . V_60 ;
V_8 -> V_71 . V_18 = V_146 ;
type = F_61 ( V_45 , V_146 , & V_101 , type ) ;
}
* V_89 = V_101 ;
return type ;
V_131:
F_40 ( V_101 ) ;
* V_89 = NULL ;
return V_52 ;
}
static enum V_49
F_79 ( struct V_44 * V_45 V_134 , struct V_7 * V_8 , char * * V_89 )
{
enum V_49 type ;
char * V_101 ;
if ( F_49 ( V_50 , & V_101 ) < 0 )
goto V_131;
V_8 -> type = V_72 ;
V_8 -> string . string = V_101 ;
V_8 -> string . V_122 = - 1 ;
if ( F_51 ( V_53 , L_61 ) < 0 )
goto V_135;
type = F_41 ( & V_101 ) ;
* V_89 = V_101 ;
return type ;
V_131:
F_40 ( V_101 ) ;
V_135:
* V_89 = NULL ;
return V_52 ;
}
static struct V_147 *
F_80 ( struct V_15 * V_15 , char * V_148 )
{
struct V_147 * V_35 ;
for ( V_35 = V_15 -> V_149 ; V_35 ; V_35 = V_35 -> V_23 ) {
if ( strcmp ( V_35 -> V_63 , V_148 ) == 0 )
break;
}
return V_35 ;
}
static void F_81 ( struct V_15 * V_15 , char * V_148 )
{
struct V_147 * V_35 ;
struct V_147 * * V_23 ;
V_23 = & V_15 -> V_149 ;
while ( ( V_35 = * V_23 ) ) {
if ( strcmp ( V_35 -> V_63 , V_148 ) == 0 ) {
* V_23 = V_35 -> V_23 ;
F_82 ( V_35 ) ;
break;
}
V_23 = & V_35 -> V_23 ;
}
}
static enum V_49
F_83 ( struct V_44 * V_45 , struct V_147 * V_35 ,
struct V_7 * V_8 , char * * V_89 )
{
struct V_7 * * V_150 ;
struct V_7 * V_58 ;
enum V_49 type ;
char * V_101 ;
char * V_151 ;
int V_20 ;
V_8 -> type = V_81 ;
V_8 -> V_35 . V_35 = V_35 ;
* V_89 = NULL ;
V_150 = & ( V_8 -> V_35 . args ) ;
for ( V_20 = 0 ; V_20 < V_35 -> V_152 ; V_20 ++ ) {
V_58 = F_6 () ;
type = F_60 ( V_45 , V_58 , & V_101 ) ;
if ( V_20 < ( V_35 -> V_152 - 1 ) )
V_151 = L_80 ;
else
V_151 = L_61 ;
if ( F_47 ( type , V_101 , V_53 , V_151 ) ) {
F_33 ( V_58 ) ;
F_40 ( V_101 ) ;
return V_52 ;
}
* V_150 = V_58 ;
V_150 = & ( V_58 -> V_23 ) ;
F_40 ( V_101 ) ;
}
type = F_41 ( & V_101 ) ;
* V_89 = V_101 ;
return type ;
}
static enum V_49
F_84 ( struct V_44 * V_45 , struct V_7 * V_8 ,
char * V_101 , char * * V_89 )
{
struct V_147 * V_35 ;
if ( strcmp ( V_101 , L_84 ) == 0 ) {
F_40 ( V_101 ) ;
V_136 = 1 ;
return F_74 ( V_45 , V_8 , V_89 ) ;
}
if ( strcmp ( V_101 , L_85 ) == 0 ) {
F_40 ( V_101 ) ;
V_138 = 1 ;
return F_75 ( V_45 , V_8 , V_89 ) ;
}
if ( strcmp ( V_101 , L_86 ) == 0 ) {
F_40 ( V_101 ) ;
return F_79 ( V_45 , V_8 , V_89 ) ;
}
if ( strcmp ( V_101 , L_87 ) == 0 ) {
F_40 ( V_101 ) ;
return F_76 ( V_45 , V_8 , V_89 ) ;
}
V_35 = F_80 ( V_45 -> V_15 , V_101 ) ;
if ( V_35 ) {
F_40 ( V_101 ) ;
return F_83 ( V_45 , V_35 , V_8 , V_89 ) ;
}
F_46 ( L_88 , V_101 ) ;
F_40 ( V_101 ) ;
return V_52 ;
}
static enum V_49
F_61 ( struct V_44 * V_45 , struct V_7 * V_8 ,
char * * V_89 , enum V_49 type )
{
char * V_101 ;
char * V_60 ;
V_101 = * V_89 ;
switch ( type ) {
case V_50 :
if ( strcmp ( V_101 , L_89 ) == 0 ) {
F_40 ( V_101 ) ;
type = F_67 ( V_45 , V_8 , & V_101 ) ;
break;
}
V_60 = V_101 ;
type = F_44 ( & V_101 ) ;
if ( type == V_53 && strcmp ( V_101 , L_82 ) == 0 ) {
F_40 ( V_101 ) ;
V_101 = NULL ;
type = F_84 ( V_45 , V_8 , V_60 , & V_101 ) ;
break;
}
while ( type == V_50 ) {
V_60 = realloc ( V_60 , strlen ( V_60 ) + strlen ( V_101 ) + 2 ) ;
strcat ( V_60 , L_29 ) ;
strcat ( V_60 , V_101 ) ;
F_40 ( V_101 ) ;
type = F_44 ( & V_101 ) ;
}
V_8 -> type = V_59 ;
V_8 -> V_60 . V_60 = V_60 ;
break;
case V_86 :
case V_51 :
V_8 -> type = V_59 ;
V_8 -> V_60 . V_60 = V_101 ;
type = F_44 ( & V_101 ) ;
break;
case V_53 :
if ( strcmp ( V_101 , L_82 ) == 0 ) {
F_40 ( V_101 ) ;
type = F_78 ( V_45 , V_8 , & V_101 ) ;
break;
}
case V_88 :
V_8 -> type = V_77 ;
V_8 -> V_78 . V_78 = V_101 ;
V_8 -> V_78 . V_79 = NULL ;
type = F_63 ( V_45 , V_8 , & V_101 ) ;
if ( type == V_52 )
V_8 -> V_78 . V_78 = NULL ;
break;
case V_52 ... V_84 :
default:
F_14 ( L_90 , type ) ;
}
* V_89 = V_101 ;
return type ;
}
static int F_85 ( struct V_44 * V_45 , struct V_7 * * V_144 )
{
enum V_49 type = V_52 ;
struct V_7 * V_8 ;
char * V_101 ;
int args = 0 ;
do {
if ( type == V_84 ) {
type = F_44 ( & V_101 ) ;
continue;
}
V_8 = F_6 () ;
type = F_60 ( V_45 , V_8 , & V_101 ) ;
if ( type == V_52 ) {
F_40 ( V_101 ) ;
F_33 ( V_8 ) ;
return - 1 ;
}
* V_144 = V_8 ;
args ++ ;
if ( type == V_88 ) {
type = F_63 ( V_45 , V_8 , & V_101 ) ;
F_40 ( V_101 ) ;
if ( type == V_52 ) {
* V_144 = NULL ;
F_33 ( V_8 ) ;
return - 1 ;
}
V_144 = & V_8 -> V_23 ;
continue;
}
if ( type == V_53 && strcmp ( V_101 , L_80 ) == 0 ) {
F_40 ( V_101 ) ;
* V_144 = V_8 ;
V_144 = & V_8 -> V_23 ;
continue;
}
break;
} while ( type != V_87 );
if ( type != V_87 && type != V_52 )
F_40 ( V_101 ) ;
return args ;
}
static int F_86 ( struct V_44 * V_45 )
{
enum V_49 type ;
char * V_101 ;
int V_105 ;
if ( F_52 ( V_50 , L_91 ) < 0 )
return - 1 ;
if ( F_51 ( V_50 , L_92 ) < 0 )
return - 1 ;
if ( F_51 ( V_88 , L_18 ) < 0 )
return - 1 ;
if ( F_49 ( V_86 , & V_101 ) < 0 )
goto V_106;
V_97:
V_45 -> V_153 . V_125 = V_101 ;
V_45 -> V_153 . args = NULL ;
type = F_44 ( & V_101 ) ;
if ( type == V_87 )
return 0 ;
if ( type == V_86 ) {
char * V_154 ;
V_154 = F_7 ( strlen ( V_45 -> V_153 . V_125 ) +
strlen ( V_101 ) + 1 ) ;
strcpy ( V_154 , V_45 -> V_153 . V_125 ) ;
strcat ( V_154 , V_101 ) ;
F_40 ( V_101 ) ;
F_40 ( V_45 -> V_153 . V_125 ) ;
V_45 -> V_153 . V_125 = NULL ;
V_101 = V_154 ;
goto V_97;
}
if ( F_47 ( type , V_101 , V_53 , L_80 ) )
goto V_106;
F_40 ( V_101 ) ;
V_105 = F_85 ( V_45 , & V_45 -> V_153 . args ) ;
if ( V_105 < 0 )
return - 1 ;
return V_105 ;
V_106:
F_40 ( V_101 ) ;
return - 1 ;
}
struct V_107 *
F_87 ( struct V_44 * V_45 , const char * V_63 )
{
struct V_107 * V_125 ;
for ( V_125 = V_45 -> V_125 . V_126 ;
V_125 ; V_125 = V_125 -> V_23 ) {
if ( strcmp ( V_125 -> V_63 , V_63 ) == 0 )
break;
}
return V_125 ;
}
struct V_107 *
F_77 ( struct V_44 * V_45 , const char * V_63 )
{
struct V_107 * V_125 ;
for ( V_125 = V_45 -> V_125 . V_109 ;
V_125 ; V_125 = V_125 -> V_23 ) {
if ( strcmp ( V_125 -> V_63 , V_63 ) == 0 )
break;
}
return V_125 ;
}
struct V_107 *
F_68 ( struct V_44 * V_45 , const char * V_63 )
{
struct V_107 * V_125 ;
V_125 = F_87 ( V_45 , V_63 ) ;
if ( V_125 )
return V_125 ;
return F_77 ( V_45 , V_63 ) ;
}
unsigned long long F_88 ( struct V_15 * V_15 ,
const void * V_155 , int V_2 )
{
switch ( V_2 ) {
case 1 :
return * ( unsigned char * ) V_155 ;
case 2 :
return F_89 ( V_15 , V_155 ) ;
case 4 :
return F_90 ( V_15 , V_155 ) ;
case 8 :
return F_91 ( V_15 , V_155 ) ;
default:
return 0 ;
}
}
int F_92 ( struct V_107 * V_62 , const void * V_156 ,
unsigned long long * V_56 )
{
if ( ! V_62 )
return - 1 ;
switch ( V_62 -> V_2 ) {
case 1 :
case 2 :
case 4 :
case 8 :
* V_56 = F_88 ( V_62 -> V_45 -> V_15 ,
V_156 + V_62 -> V_122 , V_62 -> V_2 ) ;
return 0 ;
default:
return - 1 ;
}
}
static int F_93 ( struct V_15 * V_15 ,
const char * type , int * V_122 , int * V_2 )
{
struct V_44 * V_45 ;
struct V_107 * V_62 ;
if ( ! V_15 -> V_46 )
F_14 ( L_93 ) ;
V_45 = V_15 -> V_46 [ 0 ] ;
V_62 = F_87 ( V_45 , type ) ;
if ( ! V_62 )
F_14 ( L_94 , type ) ;
* V_122 = V_62 -> V_122 ;
* V_2 = V_62 -> V_2 ;
return 0 ;
}
static int F_94 ( struct V_15 * V_15 , void * V_156 ,
int * V_2 , int * V_122 , const char * V_63 )
{
int V_105 ;
if ( ! * V_2 ) {
V_105 = F_93 ( V_15 , V_63 , V_122 , V_2 ) ;
if ( V_105 < 0 )
return V_105 ;
}
return F_88 ( V_15 , V_156 + * V_122 , * V_2 ) ;
}
static int F_95 ( struct V_15 * V_15 , void * V_156 )
{
return F_94 ( V_15 , V_156 ,
& V_15 -> V_157 , & V_15 -> V_158 ,
L_95 ) ;
}
static int F_96 ( struct V_15 * V_15 , void * V_156 )
{
return F_94 ( V_15 , V_156 ,
& V_15 -> V_159 , & V_15 -> V_160 ,
L_96 ) ;
}
static int F_97 ( struct V_15 * V_15 , void * V_156 )
{
return F_94 ( V_15 , V_156 ,
& V_15 -> V_161 , & V_15 -> V_162 ,
L_97 ) ;
}
static int F_98 ( struct V_15 * V_15 , void * V_156 )
{
return F_94 ( V_15 , V_156 ,
& V_15 -> V_163 , & V_15 -> V_164 ,
L_98 ) ;
}
static int F_99 ( struct V_15 * V_15 , void * V_156 )
{
int V_105 ;
V_105 = F_94 ( V_15 , V_156 ,
& V_15 -> V_165 , & V_15 -> V_166 ,
L_99 ) ;
if ( V_105 < 0 )
return - 1 ;
return V_105 ;
}
struct V_44 * F_100 ( struct V_15 * V_15 , int V_48 )
{
struct V_44 * * V_167 ;
struct V_44 V_24 ;
struct V_44 * V_168 = & V_24 ;
if ( V_15 -> V_169 && V_15 -> V_169 -> V_48 == V_48 )
return V_15 -> V_169 ;
V_24 . V_48 = V_48 ;
V_167 = bsearch ( & V_168 , V_15 -> V_46 , V_15 -> V_47 ,
sizeof( * V_15 -> V_46 ) , V_170 ) ;
if ( V_167 ) {
V_15 -> V_169 = * V_167 ;
return * V_167 ;
}
return NULL ;
}
struct V_44 *
F_101 ( struct V_15 * V_15 ,
const char * V_171 , const char * V_63 )
{
struct V_44 * V_45 ;
int V_20 ;
if ( V_15 -> V_169 &&
strcmp ( V_15 -> V_169 -> V_63 , V_63 ) == 0 &&
( ! V_171 || strcmp ( V_15 -> V_169 -> system , V_171 ) == 0 ) )
return V_15 -> V_169 ;
for ( V_20 = 0 ; V_20 < V_15 -> V_47 ; V_20 ++ ) {
V_45 = V_15 -> V_46 [ V_20 ] ;
if ( strcmp ( V_45 -> V_63 , V_63 ) == 0 ) {
if ( ! V_171 )
break;
if ( strcmp ( V_45 -> system , V_171 ) == 0 )
break;
}
}
if ( V_20 == V_15 -> V_47 )
V_45 = NULL ;
V_15 -> V_169 = V_45 ;
return V_45 ;
}
static unsigned long long
F_102 ( void * V_156 , int V_2 , struct V_44 * V_45 , struct V_7 * V_8 )
{
struct V_15 * V_15 = V_45 -> V_15 ;
unsigned long long V_140 = 0 ;
unsigned long long V_79 , V_80 ;
struct V_7 * V_172 = NULL ;
struct V_7 * V_173 ;
unsigned long V_122 ;
unsigned int V_174 ;
switch ( V_8 -> type ) {
case V_82 :
return 0 ;
case V_59 :
return F_103 ( V_8 -> V_60 . V_60 , NULL , 0 ) ;
case V_61 :
if ( ! V_8 -> V_62 . V_62 ) {
V_8 -> V_62 . V_62 = F_68 ( V_45 , V_8 -> V_62 . V_63 ) ;
if ( ! V_8 -> V_62 . V_62 )
F_14 ( L_100 , V_8 -> V_62 . V_63 ) ;
}
V_140 = F_88 ( V_15 , V_156 + V_8 -> V_62 . V_62 -> V_122 ,
V_8 -> V_62 . V_62 -> V_2 ) ;
break;
case V_64 :
case V_67 :
break;
case V_70 :
V_140 = F_102 ( V_156 , V_2 , V_45 , V_8 -> V_71 . V_18 ) ;
return F_70 ( V_140 , V_8 , 0 ) ;
case V_72 :
case V_73 :
return 0 ;
case V_81 : {
struct V_175 V_176 ;
F_104 ( & V_176 ) ;
V_140 = F_105 ( & V_176 , V_156 , V_2 , V_45 , V_8 ) ;
F_106 ( & V_176 ) ;
return V_140 ;
}
case V_77 :
if ( strcmp ( V_8 -> V_78 . V_78 , L_31 ) == 0 ) {
V_80 = F_102 ( V_156 , V_2 , V_45 , V_8 -> V_78 . V_80 ) ;
V_173 = V_8 -> V_78 . V_79 ;
while ( V_173 -> type == V_70 ) {
if ( ! V_172 )
V_172 = V_173 ;
V_173 = V_173 -> V_71 . V_18 ;
}
V_174 = V_15 -> V_124 ;
switch ( V_173 -> type ) {
case V_74 :
V_122 = F_88 ( V_15 ,
V_156 + V_173 -> V_75 . V_62 -> V_122 ,
V_173 -> V_75 . V_62 -> V_2 ) ;
if ( V_173 -> V_75 . V_62 -> V_123 )
V_174 = V_173 -> V_75 . V_62 -> V_123 ;
V_122 &= 0xffff ;
V_122 += V_80 ;
break;
case V_61 :
if ( ! V_173 -> V_62 . V_62 ) {
V_173 -> V_62 . V_62 =
F_68 ( V_45 , V_173 -> V_62 . V_63 ) ;
if ( ! V_173 -> V_62 . V_62 )
F_14 ( L_100 , V_173 -> V_62 . V_63 ) ;
}
V_174 = V_173 -> V_62 . V_62 -> V_123 ;
V_122 = V_173 -> V_62 . V_62 -> V_122 +
V_80 * V_173 -> V_62 . V_62 -> V_123 ;
break;
default:
goto V_177;
}
V_140 = F_88 ( V_15 ,
V_156 + V_122 , V_174 ) ;
if ( V_172 )
V_140 = F_70 ( V_140 , V_172 , 1 ) ;
break;
} else if ( strcmp ( V_8 -> V_78 . V_78 , L_52 ) == 0 ) {
V_79 = F_102 ( V_156 , V_2 , V_45 , V_8 -> V_78 . V_79 ) ;
V_8 = V_8 -> V_78 . V_80 ;
if ( V_79 )
V_140 = F_102 ( V_156 , V_2 , V_45 , V_8 -> V_78 . V_79 ) ;
else
V_140 = F_102 ( V_156 , V_2 , V_45 , V_8 -> V_78 . V_80 ) ;
break;
}
V_177:
V_79 = F_102 ( V_156 , V_2 , V_45 , V_8 -> V_78 . V_79 ) ;
V_80 = F_102 ( V_156 , V_2 , V_45 , V_8 -> V_78 . V_80 ) ;
switch ( V_8 -> V_78 . V_78 [ 0 ] ) {
case '!' :
switch ( V_8 -> V_78 . V_78 [ 1 ] ) {
case 0 :
V_140 = ! V_80 ;
break;
case '=' :
V_140 = V_79 != V_80 ;
break;
default:
F_14 ( L_50 , V_8 -> V_78 . V_78 ) ;
}
break;
case '~' :
V_140 = ~ V_80 ;
break;
case '|' :
if ( V_8 -> V_78 . V_78 [ 1 ] )
V_140 = V_79 || V_80 ;
else
V_140 = V_79 | V_80 ;
break;
case '&' :
if ( V_8 -> V_78 . V_78 [ 1 ] )
V_140 = V_79 && V_80 ;
else
V_140 = V_79 & V_80 ;
break;
case '<' :
switch ( V_8 -> V_78 . V_78 [ 1 ] ) {
case 0 :
V_140 = V_79 < V_80 ;
break;
case '<' :
V_140 = V_79 << V_80 ;
break;
case '=' :
V_140 = V_79 <= V_80 ;
break;
default:
F_14 ( L_50 , V_8 -> V_78 . V_78 ) ;
}
break;
case '>' :
switch ( V_8 -> V_78 . V_78 [ 1 ] ) {
case 0 :
V_140 = V_79 > V_80 ;
break;
case '>' :
V_140 = V_79 >> V_80 ;
break;
case '=' :
V_140 = V_79 >= V_80 ;
break;
default:
F_14 ( L_50 , V_8 -> V_78 . V_78 ) ;
}
break;
case '=' :
if ( V_8 -> V_78 . V_78 [ 1 ] != '=' )
F_14 ( L_50 , V_8 -> V_78 . V_78 ) ;
V_140 = V_79 == V_80 ;
break;
case '-' :
V_140 = V_79 - V_80 ;
break;
case '+' :
V_140 = V_79 + V_80 ;
break;
case '/' :
V_140 = V_79 / V_80 ;
break;
case '*' :
V_140 = V_79 * V_80 ;
break;
default:
F_14 ( L_50 , V_8 -> V_78 . V_78 ) ;
}
break;
default:
return 0 ;
}
return V_140 ;
}
static unsigned long long F_107 ( const char * V_178 )
{
int V_20 ;
if ( isdigit ( V_178 [ 0 ] ) )
return F_103 ( V_178 , NULL , 0 ) ;
for ( V_20 = 0 ; V_20 < ( int ) ( sizeof( V_65 ) / sizeof( V_65 [ 0 ] ) ) ; V_20 ++ )
if ( strcmp ( V_65 [ V_20 ] . V_63 , V_178 ) == 0 )
return V_65 [ V_20 ] . V_56 ;
return 0 ;
}
static void F_108 ( struct V_175 * V_176 , const char * V_125 ,
int V_179 , const char * V_57 )
{
if ( V_179 >= 0 )
F_109 ( V_176 , V_125 , V_179 , V_57 ) ;
else
F_109 ( V_176 , V_125 , V_57 ) ;
}
static void F_110 ( struct V_175 * V_176 , void * V_156 , int V_2 ,
struct V_44 * V_45 , const char * V_125 ,
int V_179 , struct V_7 * V_8 )
{
struct V_15 * V_15 = V_45 -> V_15 ;
struct V_54 * V_178 ;
unsigned long long V_140 , V_180 ;
unsigned long V_31 ;
char * V_57 ;
int V_181 ;
int V_116 ;
switch ( V_8 -> type ) {
case V_82 :
return;
case V_59 :
F_108 ( V_176 , V_125 , V_179 , V_8 -> V_60 . V_60 ) ;
return;
case V_61 :
if ( ! V_8 -> V_62 . V_62 ) {
V_8 -> V_62 . V_62 = F_68 ( V_45 , V_8 -> V_62 . V_63 ) ;
if ( ! V_8 -> V_62 . V_62 )
F_14 ( L_100 , V_8 -> V_62 . V_63 ) ;
}
V_116 = V_8 -> V_62 . V_62 -> V_2 ? : V_2 - V_8 -> V_62 . V_62 -> V_122 ;
if ( ! ( V_8 -> V_62 . V_62 -> V_65 & V_108 ) &&
V_8 -> V_62 . V_62 -> V_2 == V_15 -> V_124 ) {
V_31 = * ( unsigned long * ) ( V_156 + V_8 -> V_62 . V_62 -> V_122 ) ;
F_109 ( V_176 , L_101 , V_31 ) ;
break;
}
V_57 = F_7 ( V_116 + 1 ) ;
memcpy ( V_57 , V_156 + V_8 -> V_62 . V_62 -> V_122 , V_116 ) ;
V_57 [ V_116 ] = 0 ;
F_108 ( V_176 , V_125 , V_179 , V_57 ) ;
free ( V_57 ) ;
break;
case V_64 :
V_140 = F_102 ( V_156 , V_2 , V_45 , V_8 -> V_65 . V_62 ) ;
V_181 = 0 ;
for ( V_178 = V_8 -> V_65 . V_65 ; V_178 ; V_178 = V_178 -> V_23 ) {
V_180 = F_107 ( V_178 -> V_56 ) ;
if ( ! V_140 && ! V_180 ) {
F_108 ( V_176 , V_125 , V_179 , V_178 -> V_57 ) ;
break;
}
if ( V_180 && ( V_140 & V_180 ) == V_180 ) {
if ( V_181 && V_8 -> V_65 . V_66 )
F_111 ( V_176 , V_8 -> V_65 . V_66 ) ;
F_108 ( V_176 , V_125 , V_179 , V_178 -> V_57 ) ;
V_181 = 1 ;
V_140 &= ~ V_180 ;
}
}
break;
case V_67 :
V_140 = F_102 ( V_156 , V_2 , V_45 , V_8 -> V_68 . V_62 ) ;
for ( V_178 = V_8 -> V_68 . V_69 ; V_178 ; V_178 = V_178 -> V_23 ) {
V_180 = F_107 ( V_178 -> V_56 ) ;
if ( V_140 == V_180 ) {
F_108 ( V_176 , V_125 , V_179 , V_178 -> V_57 ) ;
break;
}
}
break;
case V_70 :
break;
case V_72 : {
int V_182 ;
if ( V_8 -> string . V_122 == - 1 ) {
struct V_107 * V_183 ;
V_183 = F_68 ( V_45 , V_8 -> string . string ) ;
V_8 -> string . V_122 = V_183 -> V_122 ;
}
V_182 = F_90 ( V_15 , V_156 + V_8 -> string . V_122 ) ;
V_182 &= 0xffff ;
F_108 ( V_176 , V_125 , V_179 , ( ( char * ) V_156 ) + V_182 ) ;
break;
}
case V_73 :
F_109 ( V_176 , V_125 , V_8 -> string . string ) ;
break;
case V_77 :
if ( V_8 -> V_78 . V_78 [ 0 ] != '?' )
return;
V_140 = F_102 ( V_156 , V_2 , V_45 , V_8 -> V_78 . V_79 ) ;
if ( V_140 )
F_110 ( V_176 , V_156 , V_2 , V_45 ,
V_125 , V_179 , V_8 -> V_78 . V_80 -> V_78 . V_79 ) ;
else
F_110 ( V_176 , V_156 , V_2 , V_45 ,
V_125 , V_179 , V_8 -> V_78 . V_80 -> V_78 . V_80 ) ;
break;
case V_81 :
F_105 ( V_176 , V_156 , V_2 , V_45 , V_8 ) ;
break;
default:
break;
}
}
static unsigned long long
F_105 ( struct V_175 * V_176 , void * V_156 , int V_2 ,
struct V_44 * V_45 , struct V_7 * V_8 )
{
struct V_147 * V_184 = V_8 -> V_35 . V_35 ;
struct V_185 * V_186 ;
unsigned long long * args ;
unsigned long long V_105 ;
struct V_7 * V_58 ;
struct V_175 V_57 ;
struct V_187 {
struct V_187 * V_23 ;
char * V_57 ;
} * V_188 = NULL , * string ;
int V_20 ;
if ( ! V_184 -> V_152 ) {
V_105 = (* V_184 -> V_35 )( V_176 , NULL ) ;
goto V_96;
}
V_58 = V_8 -> V_35 . args ;
V_186 = V_184 -> V_189 ;
args = F_7 ( sizeof( * args ) * V_184 -> V_152 ) ;
for ( V_20 = 0 ; V_20 < V_184 -> V_152 ; V_20 ++ ) {
switch ( V_186 -> type ) {
case V_190 :
case V_191 :
case V_192 :
args [ V_20 ] = F_102 ( V_156 , V_2 , V_45 , V_58 ) ;
break;
case V_193 :
F_104 ( & V_57 ) ;
F_110 ( & V_57 , V_156 , V_2 , V_45 , L_102 , - 1 , V_58 ) ;
F_112 ( & V_57 ) ;
string = F_7 ( sizeof( * string ) ) ;
string -> V_23 = V_188 ;
string -> V_57 = F_13 ( V_57 . V_194 ) ;
V_188 = string ;
F_106 ( & V_57 ) ;
break;
default:
F_14 ( L_103 ) ;
break;
}
V_58 = V_58 -> V_23 ;
V_186 = V_186 -> V_23 ;
}
V_105 = (* V_184 -> V_35 )( V_176 , args ) ;
free ( args ) ;
while ( V_188 ) {
string = V_188 ;
V_188 = string -> V_23 ;
free ( string -> V_57 ) ;
free ( string ) ;
}
V_96:
return V_105 ;
}
static struct V_7 * F_113 ( char * V_43 , void * V_156 , int V_2 , struct V_44 * V_45 )
{
struct V_15 * V_15 = V_45 -> V_15 ;
struct V_107 * V_62 , * V_195 ;
struct V_7 * args , * V_8 , * * V_23 ;
unsigned long long V_196 , V_140 ;
char * V_155 ;
void * V_197 ;
V_62 = V_15 -> V_198 ;
V_195 = V_15 -> V_199 ;
if ( ! V_62 ) {
V_62 = F_77 ( V_45 , L_104 ) ;
if ( ! V_62 )
F_14 ( L_105 ) ;
V_195 = F_77 ( V_45 , L_106 ) ;
if ( ! V_195 )
F_14 ( L_107 ) ;
V_15 -> V_198 = V_62 ;
V_15 -> V_199 = V_195 ;
}
V_196 = F_88 ( V_15 , V_156 + V_195 -> V_122 , V_195 -> V_2 ) ;
args = F_6 () ;
V_8 = args ;
V_8 -> V_23 = NULL ;
V_23 = & V_8 -> V_23 ;
V_8 -> type = V_59 ;
V_8 -> V_60 . V_60 = F_7 ( 32 ) ;
sprintf ( V_8 -> V_60 . V_60 , L_78 , V_196 ) ;
for ( V_155 = V_43 + 6 , V_197 = V_156 + V_62 -> V_122 ;
V_197 < V_156 + V_2 && * V_155 ; V_155 ++ ) {
int V_200 = 0 ;
if ( * V_155 == '%' ) {
V_201:
V_155 ++ ;
switch ( * V_155 ) {
case '%' :
break;
case 'l' :
V_200 ++ ;
goto V_201;
case 'L' :
V_200 = 2 ;
goto V_201;
case '0' ... '9' :
goto V_201;
case 'p' :
V_200 = 1 ;
case 'd' :
case 'u' :
case 'x' :
case 'i' :
V_197 = ( void * ) ( ( ( unsigned long ) V_197 + 3 ) &
~ 3 ) ;
switch ( V_200 ) {
case 0 :
V_200 = 4 ;
break;
case 1 :
V_200 = V_15 -> V_124 ;
break;
case 2 :
V_200 = 8 ;
default:
break;
}
V_140 = F_88 ( V_15 , V_197 , V_200 ) ;
V_197 += V_200 ;
V_8 = F_6 () ;
V_8 -> V_23 = NULL ;
V_8 -> type = V_59 ;
V_8 -> V_60 . V_60 = F_7 ( 32 ) ;
sprintf ( V_8 -> V_60 . V_60 , L_78 , V_140 ) ;
* V_23 = V_8 ;
V_23 = & V_8 -> V_23 ;
break;
case 's' :
V_8 = F_6 () ;
V_8 -> V_23 = NULL ;
V_8 -> type = V_73 ;
V_8 -> string . string = F_13 ( V_197 ) ;
V_197 += strlen ( V_197 ) + 1 ;
* V_23 = V_8 ;
V_23 = & V_8 -> V_23 ;
default:
break;
}
}
}
return args ;
}
static void F_114 ( struct V_7 * args )
{
struct V_7 * V_23 ;
while ( args ) {
V_23 = args -> V_23 ;
F_33 ( args ) ;
args = V_23 ;
}
}
static char *
F_115 ( void * V_156 , int V_2 V_134 , struct V_44 * V_45 )
{
struct V_15 * V_15 = V_45 -> V_15 ;
unsigned long long V_31 ;
struct V_107 * V_62 ;
struct V_40 * V_42 ;
char * V_125 ;
char * V_202 ;
V_62 = V_15 -> V_203 ;
if ( ! V_62 ) {
V_62 = F_77 ( V_45 , L_92 ) ;
if ( ! V_62 )
F_14 ( L_108 ) ;
V_15 -> V_203 = V_62 ;
}
V_31 = F_88 ( V_15 , V_156 + V_62 -> V_122 , V_62 -> V_2 ) ;
V_42 = F_26 ( V_15 , V_31 ) ;
if ( ! V_42 ) {
V_125 = F_7 ( 45 ) ;
sprintf ( V_125 , L_109 ,
V_31 ) ;
return V_125 ;
}
V_202 = V_42 -> V_42 ;
if ( * V_202 == '"' )
V_202 ++ ;
V_125 = F_7 ( strlen ( V_202 ) + 10 ) ;
sprintf ( V_125 , L_110 , L_111 , V_202 ) ;
V_202 = V_125 + strlen ( V_125 ) - 1 ;
if ( * V_202 == '"' )
* V_202 = 0 ;
V_202 -= 2 ;
if ( strcmp ( V_202 , L_112 ) == 0 )
* V_202 = 0 ;
return V_125 ;
}
static void F_116 ( struct V_175 * V_176 , int V_204 , void * V_156 , int V_2 ,
struct V_44 * V_45 , struct V_7 * V_8 )
{
unsigned char * V_1 ;
char * V_43 = L_113 ;
if ( V_8 -> type == V_81 ) {
F_105 ( V_176 , V_156 , V_2 , V_45 , V_8 ) ;
return;
}
if ( V_8 -> type != V_61 ) {
F_109 ( V_176 , L_114 ,
V_8 -> type ) ;
return;
}
if ( V_204 == 'm' )
V_43 = L_115 ;
if ( ! V_8 -> V_62 . V_62 ) {
V_8 -> V_62 . V_62 =
F_68 ( V_45 , V_8 -> V_62 . V_63 ) ;
if ( ! V_8 -> V_62 . V_62 )
F_14 ( L_100 , V_8 -> V_62 . V_63 ) ;
}
if ( V_8 -> V_62 . V_62 -> V_2 != 6 ) {
F_109 ( V_176 , L_116 ) ;
return;
}
V_1 = V_156 + V_8 -> V_62 . V_62 -> V_122 ;
F_109 ( V_176 , V_43 , V_1 [ 0 ] , V_1 [ 1 ] , V_1 [ 2 ] , V_1 [ 3 ] , V_1 [ 4 ] , V_1 [ 5 ] ) ;
}
static void F_117 ( struct V_175 * V_176 , void * V_156 , int V_2 ,
struct V_44 * V_45 )
{
struct V_107 * V_62 ;
unsigned long long V_140 ;
unsigned int V_122 , V_116 , V_20 ;
V_62 = V_45 -> V_125 . V_109 ;
while ( V_62 ) {
F_109 ( V_176 , L_117 , V_62 -> V_63 ) ;
if ( V_62 -> V_65 & V_108 ) {
V_122 = V_62 -> V_122 ;
V_116 = V_62 -> V_2 ;
if ( V_62 -> V_65 & V_119 ) {
V_140 = F_88 ( V_45 -> V_15 , V_156 + V_122 , V_116 ) ;
V_122 = V_140 ;
V_116 = V_122 >> 16 ;
V_122 &= 0xffff ;
}
if ( V_62 -> V_65 & V_118 ) {
F_109 ( V_176 , L_102 , ( char * ) V_156 + V_122 ) ;
} else {
F_111 ( V_176 , L_118 ) ;
for ( V_20 = 0 ; V_20 < V_116 ; V_20 ++ ) {
if ( V_20 )
F_111 ( V_176 , L_119 ) ;
F_109 ( V_176 , L_120 ,
* ( ( unsigned char * ) V_156 + V_122 + V_20 ) ) ;
}
F_118 ( V_176 , ']' ) ;
}
} else {
V_140 = F_88 ( V_45 -> V_15 , V_156 + V_62 -> V_122 ,
V_62 -> V_2 ) ;
if ( V_62 -> V_65 & V_113 ) {
F_109 ( V_176 , L_121 , V_140 ) ;
} else if ( V_62 -> V_65 & V_205 ) {
switch ( V_62 -> V_2 ) {
case 4 :
if ( V_62 -> V_65 & V_120 )
F_109 ( V_176 , L_122 , ( int ) V_140 ) ;
else
F_109 ( V_176 , L_123 , ( int ) V_140 ) ;
break;
case 2 :
F_109 ( V_176 , L_124 , ( short ) V_140 ) ;
break;
case 1 :
F_109 ( V_176 , L_125 , ( char ) V_140 ) ;
break;
default:
F_109 ( V_176 , L_78 , V_140 ) ;
}
} else {
if ( V_62 -> V_65 & V_120 )
F_109 ( V_176 , L_121 , V_140 ) ;
else
F_109 ( V_176 , L_126 , V_140 ) ;
}
}
V_62 = V_62 -> V_23 ;
}
}
static void F_119 ( struct V_175 * V_176 , void * V_156 , int V_2 , struct V_44 * V_45 )
{
struct V_15 * V_15 = V_45 -> V_15 ;
struct V_153 * V_153 = & V_45 -> V_153 ;
struct V_7 * V_8 = V_153 -> args ;
struct V_7 * args = NULL ;
const char * V_155 = V_153 -> V_125 ;
unsigned long long V_140 ;
struct V_28 * V_35 ;
const char * V_206 ;
char * V_207 = NULL ;
char V_125 [ 32 ] ;
int V_208 ;
int V_209 ;
int V_179 ;
int V_116 ;
int V_200 ;
if ( V_45 -> V_65 & V_133 ) {
F_109 ( V_176 , L_127 ) ;
F_117 ( V_176 , V_156 , V_2 , V_45 ) ;
return;
}
if ( V_45 -> V_65 & V_210 ) {
V_207 = F_115 ( V_156 , V_2 , V_45 ) ;
args = F_113 ( V_207 , V_156 , V_2 , V_45 ) ;
V_8 = args ;
V_155 = V_207 ;
}
for (; * V_155 ; V_155 ++ ) {
V_200 = 0 ;
if ( * V_155 == '\\' ) {
V_155 ++ ;
switch ( * V_155 ) {
case 'n' :
F_118 ( V_176 , '\n' ) ;
break;
case 't' :
F_118 ( V_176 , '\t' ) ;
break;
case 'r' :
F_118 ( V_176 , '\r' ) ;
break;
case '\\' :
F_118 ( V_176 , '\\' ) ;
break;
default:
F_118 ( V_176 , * V_155 ) ;
break;
}
} else if ( * V_155 == '%' ) {
V_206 = V_155 ;
V_208 = 0 ;
V_209 = 0 ;
V_211:
V_155 ++ ;
switch ( * V_155 ) {
case '%' :
F_118 ( V_176 , '%' ) ;
break;
case '#' :
goto V_211;
case 'h' :
V_200 -- ;
goto V_211;
case 'l' :
V_200 ++ ;
goto V_211;
case 'L' :
V_200 = 2 ;
goto V_211;
case '*' :
if ( ! V_8 )
F_14 ( L_128 ) ;
V_179 = F_102 ( V_156 , V_2 , V_45 , V_8 ) ;
V_209 = 1 ;
V_8 = V_8 -> V_23 ;
goto V_211;
case '.' :
case 'z' :
case 'Z' :
case '0' ... '9' :
goto V_211;
case 'p' :
if ( V_15 -> V_124 == 4 )
V_200 = 1 ;
else
V_200 = 2 ;
if ( * ( V_155 + 1 ) == 'F' ||
* ( V_155 + 1 ) == 'f' ) {
V_155 ++ ;
V_208 = * V_155 ;
} else if ( * ( V_155 + 1 ) == 'M' || * ( V_155 + 1 ) == 'm' ) {
F_116 ( V_176 , * ( V_155 + 1 ) , V_156 , V_2 , V_45 , V_8 ) ;
V_155 ++ ;
break;
}
case 'd' :
case 'i' :
case 'x' :
case 'X' :
case 'u' :
if ( ! V_8 )
F_14 ( L_128 ) ;
V_116 = ( ( unsigned long ) V_155 + 1 ) -
( unsigned long ) V_206 ;
if ( V_116 > 31 )
F_14 ( L_129 ) ;
memcpy ( V_125 , V_206 , V_116 ) ;
V_125 [ V_116 ] = 0 ;
V_140 = F_102 ( V_156 , V_2 , V_45 , V_8 ) ;
V_8 = V_8 -> V_23 ;
if ( V_208 ) {
V_35 = F_19 ( V_15 , V_140 ) ;
if ( V_35 ) {
F_111 ( V_176 , V_35 -> V_35 ) ;
if ( V_208 == 'F' )
F_109 ( V_176 ,
L_130 ,
V_140 - V_35 -> V_31 ) ;
break;
}
}
if ( V_15 -> V_124 == 8 && V_200 ) {
char * V_202 ;
V_200 = 2 ;
V_202 = strchr ( V_125 , 'l' ) ;
if ( V_202 )
memmove ( V_202 , V_202 + 1 , strlen ( V_202 ) + 1 ) ;
else if ( strcmp ( V_125 , L_131 ) == 0 )
strcpy ( V_125 , L_121 ) ;
}
switch ( V_200 ) {
case - 2 :
if ( V_209 )
F_109 ( V_176 , V_125 , V_179 , ( char ) V_140 ) ;
else
F_109 ( V_176 , V_125 , ( char ) V_140 ) ;
break;
case - 1 :
if ( V_209 )
F_109 ( V_176 , V_125 , V_179 , ( short ) V_140 ) ;
else
F_109 ( V_176 , V_125 , ( short ) V_140 ) ;
break;
case 0 :
if ( V_209 )
F_109 ( V_176 , V_125 , V_179 , ( int ) V_140 ) ;
else
F_109 ( V_176 , V_125 , ( int ) V_140 ) ;
break;
case 1 :
if ( V_209 )
F_109 ( V_176 , V_125 , V_179 , ( long ) V_140 ) ;
else
F_109 ( V_176 , V_125 , ( long ) V_140 ) ;
break;
case 2 :
if ( V_209 )
F_109 ( V_176 , V_125 , V_179 ,
( long long ) V_140 ) ;
else
F_109 ( V_176 , V_125 , ( long long ) V_140 ) ;
break;
default:
F_14 ( L_132 , V_200 ) ;
}
break;
case 's' :
if ( ! V_8 )
F_14 ( L_133 ) ;
V_116 = ( ( unsigned long ) V_155 + 1 ) -
( unsigned long ) V_206 ;
if ( V_116 > 31 )
F_14 ( L_129 ) ;
memcpy ( V_125 , V_206 , V_116 ) ;
V_125 [ V_116 ] = 0 ;
if ( ! V_209 )
V_179 = - 1 ;
F_110 ( V_176 , V_156 , V_2 , V_45 ,
V_125 , V_179 , V_8 ) ;
V_8 = V_8 -> V_23 ;
break;
default:
F_109 ( V_176 , L_134 , * V_155 ) ;
}
} else
F_118 ( V_176 , * V_155 ) ;
}
if ( args ) {
F_114 ( args ) ;
free ( V_207 ) ;
}
}
void F_120 ( struct V_15 * V_15 ,
struct V_175 * V_176 , struct V_212 * V_213 )
{
static int V_214 = 1 ;
static int V_215 ;
unsigned int V_216 ;
unsigned int V_217 ;
int V_218 ;
int V_219 ;
int V_220 ;
void * V_156 = V_213 -> V_156 ;
V_216 = F_98 ( V_15 , V_156 ) ;
V_217 = F_97 ( V_15 , V_156 ) ;
if ( V_214 ) {
struct V_107 * V_62 ;
struct V_44 * V_45 ;
V_214 = 0 ;
V_45 = V_15 -> V_46 [ 0 ] ;
V_62 = F_87 ( V_45 , L_99 ) ;
if ( V_62 )
V_215 = 1 ;
}
if ( V_215 )
V_218 = F_99 ( V_15 , V_156 ) ;
V_219 = V_216 & V_221 ;
V_220 = V_216 & V_222 ;
F_109 ( V_176 , L_135 ,
( V_216 & V_223 ) ? 'd' :
( V_216 & V_224 ) ?
'X' : '.' ,
( V_216 & V_225 ) ?
'N' : '.' ,
( V_219 && V_220 ) ? 'H' :
V_219 ? 'h' : V_220 ? 's' : '.' ) ;
if ( V_217 )
F_109 ( V_176 , L_136 , V_217 ) ;
else
F_118 ( V_176 , '.' ) ;
if ( V_215 ) {
if ( V_218 < 0 )
F_118 ( V_176 , '.' ) ;
else
F_109 ( V_176 , L_123 , V_218 ) ;
}
F_112 ( V_176 ) ;
}
int F_121 ( struct V_15 * V_15 , struct V_212 * V_226 )
{
return F_95 ( V_15 , V_226 -> V_156 ) ;
}
struct V_44 * F_122 ( struct V_15 * V_15 , int type )
{
return F_100 ( V_15 , type ) ;
}
int F_123 ( struct V_15 * V_15 , struct V_212 * V_226 )
{
return F_96 ( V_15 , V_226 -> V_156 ) ;
}
const char * F_124 ( struct V_15 * V_15 , int V_14 )
{
const char * V_22 ;
V_22 = F_10 ( V_15 , V_14 ) ;
return V_22 ;
}
void F_125 ( struct V_175 * V_176 , struct V_44 * V_45 ,
struct V_212 * V_213 )
{
int V_227 = 1 ;
if ( V_45 -> V_15 -> V_228 )
F_117 ( V_176 , V_213 -> V_156 , V_213 -> V_2 , V_45 ) ;
else {
if ( V_45 -> V_229 )
V_227 = V_45 -> V_229 ( V_176 , V_213 , V_45 ,
V_45 -> V_230 ) ;
if ( V_227 )
F_119 ( V_176 , V_213 -> V_156 , V_213 -> V_2 , V_45 ) ;
}
F_112 ( V_176 ) ;
}
void F_126 ( struct V_15 * V_15 , struct V_175 * V_176 ,
struct V_212 * V_213 )
{
static char * V_231 = L_137 ;
struct V_44 * V_45 ;
unsigned long V_232 ;
unsigned long V_233 ;
unsigned long V_234 ;
const char * V_22 ;
void * V_156 = V_213 -> V_156 ;
int type ;
int V_14 ;
int V_116 ;
int V_202 ;
V_232 = V_213 -> V_235 / V_236 ;
V_234 = V_213 -> V_235 - V_232 * V_236 ;
if ( V_213 -> V_2 < 0 ) {
F_46 ( L_138 , V_213 -> V_2 ) ;
return;
}
type = F_95 ( V_15 , V_156 ) ;
V_45 = F_100 ( V_15 , type ) ;
if ( ! V_45 ) {
F_46 ( L_139 , type ) ;
return;
}
V_14 = F_96 ( V_15 , V_156 ) ;
V_22 = F_10 ( V_15 , V_14 ) ;
if ( V_15 -> V_237 ) {
F_109 ( V_176 , L_140 ,
V_22 , V_14 , V_213 -> V_238 ) ;
F_120 ( V_15 , V_176 , V_213 ) ;
} else
F_109 ( V_176 , L_141 , V_22 , V_14 , V_213 -> V_238 ) ;
if ( V_15 -> V_65 & V_239 ) {
V_233 = V_234 ;
V_202 = 9 ;
} else {
V_233 = ( V_234 + 500 ) / V_240 ;
V_202 = 6 ;
}
F_109 ( V_176 , L_142 , V_232 , V_202 , V_233 , V_45 -> V_63 ) ;
V_116 = strlen ( V_45 -> V_63 ) ;
if ( V_116 < 20 )
F_109 ( V_176 , L_143 , 20 - V_116 , V_231 ) ;
F_125 ( V_176 , V_45 , V_213 ) ;
}
static int V_170 ( const void * V_9 , const void * V_10 )
{
struct V_44 * const * V_241 = V_9 ;
struct V_44 * const * V_242 = V_10 ;
if ( ( * V_241 ) -> V_48 < ( * V_242 ) -> V_48 )
return - 1 ;
if ( ( * V_241 ) -> V_48 > ( * V_242 ) -> V_48 )
return 1 ;
return 0 ;
}
static int F_127 ( const void * V_9 , const void * V_10 )
{
struct V_44 * const * V_241 = V_9 ;
struct V_44 * const * V_242 = V_10 ;
int V_243 ;
V_243 = strcmp ( ( * V_241 ) -> V_63 , ( * V_242 ) -> V_63 ) ;
if ( V_243 )
return V_243 ;
V_243 = strcmp ( ( * V_241 ) -> system , ( * V_242 ) -> system ) ;
if ( V_243 )
return V_243 ;
return V_170 ( V_9 , V_10 ) ;
}
static int F_128 ( const void * V_9 , const void * V_10 )
{
struct V_44 * const * V_241 = V_9 ;
struct V_44 * const * V_242 = V_10 ;
int V_243 ;
V_243 = strcmp ( ( * V_241 ) -> system , ( * V_242 ) -> system ) ;
if ( V_243 )
return V_243 ;
V_243 = strcmp ( ( * V_241 ) -> V_63 , ( * V_242 ) -> V_63 ) ;
if ( V_243 )
return V_243 ;
return V_170 ( V_9 , V_10 ) ;
}
struct V_44 * * F_129 ( struct V_15 * V_15 , enum V_244 V_245 )
{
struct V_44 * * V_46 ;
int (* F_130)( const void * V_9 , const void * V_10 );
V_46 = V_15 -> V_246 ;
if ( V_46 && V_15 -> V_114 == V_245 )
return V_46 ;
if ( ! V_46 ) {
V_46 = malloc ( sizeof( * V_46 ) * ( V_15 -> V_47 + 1 ) ) ;
if ( ! V_46 )
return NULL ;
memcpy ( V_46 , V_15 -> V_46 , sizeof( * V_46 ) * V_15 -> V_47 ) ;
V_46 [ V_15 -> V_47 ] = NULL ;
V_15 -> V_246 = V_46 ;
if ( V_245 == V_247 ) {
V_15 -> V_114 = V_245 ;
return V_46 ;
}
}
switch ( V_245 ) {
case V_247 :
F_130 = V_170 ;
break;
case V_248 :
F_130 = F_127 ;
break;
case V_249 :
F_130 = F_128 ;
break;
default:
return V_46 ;
}
qsort ( V_46 , V_15 -> V_47 , sizeof( * V_46 ) , F_130 ) ;
V_15 -> V_114 = V_245 ;
return V_46 ;
}
static struct V_107 * *
F_131 ( const char * type , const char * V_63 ,
int V_111 , struct V_107 * V_144 )
{
struct V_107 * * V_109 ;
struct V_107 * V_62 ;
int V_20 = 0 ;
V_109 = F_7 ( sizeof( * V_109 ) * ( V_111 + 1 ) ) ;
for ( V_62 = V_144 ; V_62 ; V_62 = V_62 -> V_23 ) {
V_109 [ V_20 ++ ] = V_62 ;
if ( V_20 == V_111 + 1 ) {
F_46 ( L_144 ,
V_63 , type ) ;
V_20 -- ;
break;
}
}
if ( V_20 != V_111 )
F_46 ( L_145 ,
V_63 , type ) ;
V_109 [ V_20 ] = NULL ;
return V_109 ;
}
struct V_107 * * F_132 ( struct V_44 * V_45 )
{
return F_131 ( L_146 , V_45 -> V_63 ,
V_45 -> V_125 . V_127 ,
V_45 -> V_125 . V_126 ) ;
}
struct V_107 * * F_133 ( struct V_44 * V_45 )
{
return F_131 ( L_147 , V_45 -> V_63 ,
V_45 -> V_125 . V_128 ,
V_45 -> V_125 . V_109 ) ;
}
static void F_134 ( struct V_175 * V_176 , struct V_54 * V_62 )
{
F_109 ( V_176 , L_148 , V_62 -> V_56 , V_62 -> V_57 ) ;
if ( V_62 -> V_23 ) {
F_111 ( V_176 , L_119 ) ;
F_134 ( V_176 , V_62 -> V_23 ) ;
}
}
static void F_135 ( struct V_7 * args )
{
int V_250 = 1 ;
struct V_175 V_176 ;
switch ( args -> type ) {
case V_82 :
printf ( L_149 ) ;
break;
case V_59 :
printf ( L_102 , args -> V_60 . V_60 ) ;
break;
case V_61 :
printf ( L_150 , args -> V_62 . V_63 ) ;
break;
case V_64 :
printf ( L_151 ) ;
F_135 ( args -> V_65 . V_62 ) ;
printf ( L_152 , args -> V_65 . V_66 ) ;
F_104 ( & V_176 ) ;
F_134 ( & V_176 , args -> V_65 . V_65 ) ;
F_136 ( & V_176 ) ;
F_106 ( & V_176 ) ;
printf ( L_61 ) ;
break;
case V_67 :
printf ( L_153 ) ;
F_135 ( args -> V_68 . V_62 ) ;
printf ( L_119 ) ;
F_104 ( & V_176 ) ;
F_134 ( & V_176 , args -> V_68 . V_69 ) ;
F_136 ( & V_176 ) ;
F_106 ( & V_176 ) ;
printf ( L_61 ) ;
break;
case V_72 :
case V_73 :
printf ( L_154 , args -> string . string ) ;
break;
case V_70 :
printf ( L_155 , args -> V_71 . type ) ;
F_135 ( args -> V_71 . V_18 ) ;
break;
case V_77 :
if ( strcmp ( args -> V_78 . V_78 , L_18 ) == 0 )
V_250 = 0 ;
if ( V_250 )
printf ( L_82 ) ;
F_135 ( args -> V_78 . V_79 ) ;
printf ( L_156 , args -> V_78 . V_78 ) ;
F_135 ( args -> V_78 . V_80 ) ;
if ( V_250 )
printf ( L_61 ) ;
break;
default:
return;
}
if ( args -> V_23 ) {
printf ( L_6 ) ;
F_135 ( args -> V_23 ) ;
}
}
static void F_137 ( const char * V_62 ,
int * V_122 , int * V_2 , int V_251 )
{
unsigned long long V_98 ;
unsigned long long V_100 ;
char * V_101 ;
int type ;
V_98 = V_5 ;
V_100 = V_4 ;
if ( F_51 ( V_50 , L_25 ) < 0 )
return;
if ( F_51 ( V_88 , L_18 ) < 0 )
return;
if ( F_49 ( V_50 , & V_101 ) < 0 )
goto V_106;
F_40 ( V_101 ) ;
if ( V_251 ) {
if ( F_51 ( V_50 , V_62 ) < 0 )
return;
} else {
if ( F_49 ( V_50 , & V_101 ) < 0 )
goto V_106;
if ( strcmp ( V_101 , V_62 ) != 0 )
goto V_252;
F_40 ( V_101 ) ;
}
if ( F_51 ( V_88 , L_34 ) < 0 )
return;
if ( F_51 ( V_50 , L_35 ) < 0 )
return;
if ( F_51 ( V_88 , L_18 ) < 0 )
return;
if ( F_49 ( V_50 , & V_101 ) < 0 )
goto V_106;
* V_122 = atoi ( V_101 ) ;
F_40 ( V_101 ) ;
if ( F_51 ( V_88 , L_34 ) < 0 )
return;
if ( F_51 ( V_50 , L_36 ) < 0 )
return;
if ( F_51 ( V_88 , L_18 ) < 0 )
return;
if ( F_49 ( V_50 , & V_101 ) < 0 )
goto V_106;
* V_2 = atoi ( V_101 ) ;
F_40 ( V_101 ) ;
if ( F_51 ( V_88 , L_34 ) < 0 )
return;
type = F_41 ( & V_101 ) ;
if ( type != V_84 ) {
if ( type != V_50 )
goto V_106;
if ( strcmp ( V_101 , L_37 ) != 0 )
goto V_106;
F_40 ( V_101 ) ;
if ( F_51 ( V_88 , L_18 ) < 0 )
return;
if ( F_49 ( V_50 , & V_101 ) )
goto V_106;
F_40 ( V_101 ) ;
if ( F_51 ( V_88 , L_34 ) < 0 )
return;
if ( F_49 ( V_84 , & V_101 ) )
goto V_106;
}
V_106:
F_40 ( V_101 ) ;
return;
V_252:
V_5 = V_98 ;
V_4 = V_100 ;
* V_122 = 0 ;
* V_2 = 0 ;
F_40 ( V_101 ) ;
}
int F_138 ( struct V_15 * V_15 , char * V_1 , unsigned long V_2 ,
int V_124 )
{
int V_253 ;
if ( ! V_2 ) {
V_15 -> V_254 = sizeof( long long ) ;
V_15 -> V_255 = V_124 ;
V_15 -> V_256 = sizeof( long long ) + V_124 ;
V_15 -> V_257 = 1 ;
return - 1 ;
}
F_1 ( V_1 , V_2 ) ;
F_137 ( L_157 , & V_15 -> V_258 ,
& V_15 -> V_254 , 1 ) ;
F_137 ( L_158 , & V_15 -> V_259 ,
& V_15 -> V_255 , 1 ) ;
F_137 ( L_159 , & V_15 -> V_260 ,
& V_253 , 0 ) ;
F_137 ( L_160 , & V_15 -> V_256 ,
& V_15 -> V_261 , 1 ) ;
return 0 ;
}
static int F_139 ( struct V_44 * V_45 ,
int V_48 , const char * V_262 ,
const char * V_263 )
{
if ( V_48 >= 0 && V_48 != V_45 -> V_48 )
return 0 ;
if ( V_263 && ( strcmp ( V_263 , V_45 -> V_63 ) != 0 ) )
return 0 ;
if ( V_262 && ( strcmp ( V_262 , V_45 -> system ) != 0 ) )
return 0 ;
return 1 ;
}
static void F_140 ( struct V_264 * V_265 )
{
free ( ( void * ) V_265 -> V_262 ) ;
free ( ( void * ) V_265 -> V_263 ) ;
free ( V_265 ) ;
}
static int F_141 ( struct V_15 * V_15 , struct V_44 * V_45 )
{
struct V_264 * V_265 , * * V_23 ;
for ( V_23 = & V_15 -> V_266 ; * V_23 ;
V_23 = & ( * V_23 ) -> V_23 ) {
V_265 = * V_23 ;
if ( F_139 ( V_45 , V_265 -> V_48 ,
V_265 -> V_262 ,
V_265 -> V_263 ) )
break;
}
if ( ! ( * V_23 ) )
return 0 ;
F_142 ( L_161 ,
V_45 -> V_48 , V_45 -> system , V_45 -> V_63 ) ;
V_45 -> V_229 = V_265 -> V_35 ;
V_45 -> V_230 = V_265 -> V_230 ;
* V_23 = V_265 -> V_23 ;
F_140 ( V_265 ) ;
return 1 ;
}
int F_143 ( struct V_15 * V_15 ,
const char * V_1 , unsigned long V_2 ,
const char * V_171 )
{
struct V_44 * V_45 ;
int V_105 ;
F_1 ( V_1 , V_2 ) ;
V_45 = F_29 () ;
if ( ! V_45 )
return - V_27 ;
V_45 -> V_63 = F_53 () ;
if ( ! V_45 -> V_63 ) {
free ( V_45 ) ;
return - 1 ;
}
if ( strcmp ( V_171 , L_162 ) == 0 ) {
V_45 -> V_65 |= V_112 ;
if ( strcmp ( V_45 -> V_63 , L_163 ) == 0 )
V_45 -> V_65 |= V_210 ;
}
V_45 -> V_48 = F_54 () ;
if ( V_45 -> V_48 < 0 )
F_14 ( L_164 ) ;
V_45 -> system = F_13 ( V_171 ) ;
V_45 -> V_15 = V_15 ;
V_105 = F_59 ( V_45 ) ;
if ( V_105 < 0 ) {
F_46 ( L_165 , V_45 -> V_63 ) ;
goto V_267;
}
if ( F_141 ( V_15 , V_45 ) )
V_268 = 0 ;
V_105 = F_86 ( V_45 ) ;
if ( V_105 < 0 ) {
F_46 ( L_166 ,
V_45 -> V_63 ) ;
V_268 = 1 ;
goto V_267;
}
V_268 = 1 ;
F_30 ( V_15 , V_45 ) ;
if ( ! V_105 && ( V_45 -> V_65 & V_112 ) ) {
struct V_107 * V_62 ;
struct V_7 * V_8 , * * V_144 ;
V_144 = & V_45 -> V_153 . args ;
for ( V_62 = V_45 -> V_125 . V_109 ; V_62 ; V_62 = V_62 -> V_23 ) {
V_8 = F_6 () ;
* V_144 = V_8 ;
V_144 = & V_8 -> V_23 ;
V_8 -> type = V_61 ;
V_8 -> V_62 . V_63 = F_13 ( V_62 -> V_63 ) ;
V_8 -> V_62 . V_62 = V_62 ;
}
return 0 ;
}
#define F_144 0
if ( F_144 && V_45 -> V_153 . args )
F_135 ( V_45 -> V_153 . args ) ;
return 0 ;
V_267:
V_45 -> V_65 |= V_133 ;
F_30 ( V_15 , V_45 ) ;
return - 1 ;
}
int F_145 ( struct V_175 * V_176 , struct V_107 * V_62 ,
const char * V_63 , struct V_212 * V_213 ,
unsigned long long * V_140 , int V_269 )
{
if ( ! V_62 ) {
if ( V_269 )
F_109 ( V_176 , L_167 , V_63 ) ;
return - 1 ;
}
if ( F_92 ( V_62 , V_213 -> V_156 , V_140 ) ) {
if ( V_269 )
F_109 ( V_176 , L_168 , V_63 ) ;
return - 1 ;
}
return 0 ;
}
void * F_146 ( struct V_175 * V_176 , struct V_44 * V_45 ,
const char * V_63 , struct V_212 * V_213 ,
int * V_116 , int V_269 )
{
struct V_107 * V_62 ;
void * V_156 = V_213 -> V_156 ;
unsigned V_122 ;
int V_270 ;
if ( ! V_45 )
return NULL ;
V_62 = F_77 ( V_45 , V_63 ) ;
if ( ! V_62 ) {
if ( V_269 )
F_109 ( V_176 , L_167 , V_63 ) ;
return NULL ;
}
if ( ! V_116 )
V_116 = & V_270 ;
V_122 = V_62 -> V_122 ;
if ( V_62 -> V_65 & V_119 ) {
V_122 = F_88 ( V_45 -> V_15 ,
V_156 + V_122 , V_62 -> V_2 ) ;
* V_116 = V_122 >> 16 ;
V_122 &= 0xffff ;
} else
* V_116 = V_62 -> V_2 ;
return V_156 + V_122 ;
}
int F_147 ( struct V_175 * V_176 , struct V_44 * V_45 ,
const char * V_63 , struct V_212 * V_213 ,
unsigned long long * V_140 , int V_269 )
{
struct V_107 * V_62 ;
if ( ! V_45 )
return - 1 ;
V_62 = F_77 ( V_45 , V_63 ) ;
return F_145 ( V_176 , V_62 , V_63 , V_213 , V_140 , V_269 ) ;
}
int F_148 ( struct V_175 * V_176 , struct V_44 * V_45 ,
const char * V_63 , struct V_212 * V_213 ,
unsigned long long * V_140 , int V_269 )
{
struct V_107 * V_62 ;
if ( ! V_45 )
return - 1 ;
V_62 = F_87 ( V_45 , V_63 ) ;
return F_145 ( V_176 , V_62 , V_63 , V_213 , V_140 , V_269 ) ;
}
int F_149 ( struct V_175 * V_176 , struct V_44 * V_45 ,
const char * V_63 , struct V_212 * V_213 ,
unsigned long long * V_140 , int V_269 )
{
struct V_107 * V_62 ;
if ( ! V_45 )
return - 1 ;
V_62 = F_68 ( V_45 , V_63 ) ;
return F_145 ( V_176 , V_62 , V_63 , V_213 , V_140 , V_269 ) ;
}
int F_150 ( struct V_175 * V_176 , const char * V_43 ,
struct V_44 * V_45 , const char * V_63 ,
struct V_212 * V_213 , int V_269 )
{
struct V_107 * V_62 = F_77 ( V_45 , V_63 ) ;
unsigned long long V_140 ;
if ( ! V_62 )
goto V_271;
if ( F_92 ( V_62 , V_213 -> V_156 , & V_140 ) )
goto V_271;
return F_109 ( V_176 , V_43 , V_140 ) ;
V_271:
if ( V_269 )
F_109 ( V_176 , L_169 , V_63 ) ;
return - 1 ;
}
static void F_82 ( struct V_147 * V_35 )
{
struct V_185 * V_189 ;
free ( V_35 -> V_63 ) ;
while ( V_35 -> V_189 ) {
V_189 = V_35 -> V_189 ;
V_35 -> V_189 = V_189 -> V_23 ;
free ( V_189 ) ;
}
free ( V_35 ) ;
}
int F_151 ( struct V_15 * V_15 ,
T_1 V_35 ,
enum V_272 V_273 ,
char * V_63 , ... )
{
struct V_147 * V_184 ;
struct V_185 * * V_274 ;
struct V_185 * V_186 ;
enum V_272 type ;
T_2 V_275 ;
V_184 = F_80 ( V_15 , V_63 ) ;
if ( V_184 ) {
F_142 ( L_170 , V_63 ) ;
F_81 ( V_15 , V_63 ) ;
}
V_184 = F_7 ( sizeof( * V_184 ) ) ;
memset ( V_184 , 0 , sizeof( * V_184 ) ) ;
V_184 -> V_273 = V_273 ;
V_184 -> V_63 = F_13 ( V_63 ) ;
V_184 -> V_35 = V_35 ;
if ( ! V_184 -> V_63 )
F_14 ( L_171 ) ;
V_274 = & ( V_184 -> V_189 ) ;
va_start ( V_275 , V_63 ) ;
for (; ; ) {
type = va_arg ( V_275 , enum V_272 ) ;
if ( type == V_276 )
break;
if ( type < 0 || type >= V_277 ) {
F_152 ( L_172 , type ) ;
goto V_131;
}
V_186 = F_7 ( sizeof( * V_186 ) ) ;
V_186 -> type = type ;
V_186 -> V_23 = NULL ;
* V_274 = V_186 ;
V_274 = & ( V_186 -> V_23 ) ;
V_184 -> V_152 ++ ;
}
va_end ( V_275 ) ;
V_184 -> V_23 = V_15 -> V_149 ;
V_15 -> V_149 = V_184 ;
return 0 ;
V_131:
va_end ( V_275 ) ;
F_82 ( V_184 ) ;
return - 1 ;
}
int F_153 ( struct V_15 * V_15 ,
int V_48 , char * V_262 , char * V_263 ,
T_3 V_35 ,
void * V_230 )
{
struct V_44 * V_45 ;
struct V_264 * V_265 ;
if ( V_48 >= 0 ) {
V_45 = F_100 ( V_15 , V_48 ) ;
if ( ! V_45 )
goto V_278;
if ( V_263 && ( strcmp ( V_263 , V_45 -> V_63 ) != 0 ) )
goto V_278;
if ( V_262 && ( strcmp ( V_262 , V_45 -> system ) != 0 ) )
goto V_278;
} else {
V_45 = F_101 ( V_15 , V_262 , V_263 ) ;
if ( ! V_45 )
goto V_278;
}
F_142 ( L_161 ,
V_45 -> V_48 , V_45 -> system , V_45 -> V_63 ) ;
V_45 -> V_229 = V_35 ;
V_45 -> V_230 = V_230 ;
return 0 ;
V_278:
V_265 = F_7 ( sizeof( * V_265 ) ) ;
memset ( V_265 , 0 , sizeof( * V_265 ) ) ;
V_265 -> V_48 = V_48 ;
if ( V_263 )
V_265 -> V_263 = F_13 ( V_263 ) ;
if ( V_262 )
V_265 -> V_262 = F_13 ( V_262 ) ;
V_265 -> V_35 = V_35 ;
V_265 -> V_23 = V_15 -> V_266 ;
V_15 -> V_266 = V_265 ;
V_265 -> V_230 = V_230 ;
return - 1 ;
}
struct V_15 * F_154 ( void )
{
struct V_15 * V_15 ;
V_15 = malloc ( sizeof( * V_15 ) ) ;
if ( ! V_15 )
return NULL ;
memset ( V_15 , 0 , sizeof( * V_15 ) ) ;
V_15 -> V_279 = 1 ;
return V_15 ;
}
void F_155 ( struct V_15 * V_15 )
{
V_15 -> V_279 ++ ;
}
static void F_156 ( struct V_107 * V_62 )
{
struct V_107 * V_23 ;
while ( V_62 ) {
V_23 = V_62 -> V_23 ;
free ( V_62 -> type ) ;
free ( V_62 -> V_63 ) ;
free ( V_62 ) ;
V_62 = V_23 ;
}
}
static void F_157 ( struct V_125 * V_125 )
{
F_156 ( V_125 -> V_126 ) ;
F_156 ( V_125 -> V_109 ) ;
}
static void F_158 ( struct V_44 * V_45 )
{
free ( V_45 -> V_63 ) ;
free ( V_45 -> system ) ;
F_157 ( & V_45 -> V_125 ) ;
free ( V_45 -> V_153 . V_125 ) ;
F_114 ( V_45 -> V_153 . args ) ;
free ( V_45 ) ;
}
void F_159 ( struct V_15 * V_15 )
{
struct V_16 * V_17 , * V_280 ;
struct V_32 * V_33 , * V_281 ;
struct V_38 * V_39 , * V_282 ;
struct V_147 * V_283 ;
struct V_264 * V_265 ;
int V_20 ;
if ( ! V_15 )
return;
V_17 = V_15 -> V_17 ;
V_33 = V_15 -> V_33 ;
V_39 = V_15 -> V_39 ;
V_15 -> V_279 -- ;
if ( V_15 -> V_279 )
return;
if ( V_15 -> V_19 ) {
for ( V_20 = 0 ; V_20 < V_15 -> V_21 ; V_20 ++ )
free ( V_15 -> V_19 [ V_20 ] . V_22 ) ;
free ( V_15 -> V_19 ) ;
}
while ( V_17 ) {
V_280 = V_17 -> V_23 ;
free ( V_17 -> V_22 ) ;
free ( V_17 ) ;
V_17 = V_280 ;
}
if ( V_15 -> V_28 ) {
for ( V_20 = 0 ; V_20 < V_15 -> V_34 ; V_20 ++ ) {
free ( V_15 -> V_28 [ V_20 ] . V_35 ) ;
free ( V_15 -> V_28 [ V_20 ] . V_36 ) ;
}
free ( V_15 -> V_28 ) ;
}
while ( V_33 ) {
V_281 = V_33 -> V_23 ;
free ( V_33 -> V_35 ) ;
free ( V_33 -> V_36 ) ;
free ( V_33 ) ;
V_33 = V_281 ;
}
while ( V_15 -> V_149 ) {
V_283 = V_15 -> V_149 ;
V_15 -> V_149 = V_283 -> V_23 ;
F_82 ( V_283 ) ;
}
if ( V_15 -> V_40 ) {
for ( V_20 = 0 ; V_20 < V_15 -> V_41 ; V_20 ++ )
free ( V_15 -> V_40 [ V_20 ] . V_42 ) ;
free ( V_15 -> V_40 ) ;
}
while ( V_39 ) {
V_282 = V_39 -> V_23 ;
free ( V_39 -> V_42 ) ;
free ( V_39 ) ;
V_39 = V_282 ;
}
for ( V_20 = 0 ; V_20 < V_15 -> V_47 ; V_20 ++ )
F_158 ( V_15 -> V_46 [ V_20 ] ) ;
while ( V_15 -> V_266 ) {
V_265 = V_15 -> V_266 ;
V_15 -> V_266 = V_265 -> V_23 ;
F_140 ( V_265 ) ;
}
free ( V_15 -> V_46 ) ;
free ( V_15 -> V_246 ) ;
free ( V_15 ) ;
}
void F_160 ( struct V_15 * V_15 )
{
F_159 ( V_15 ) ;
}
