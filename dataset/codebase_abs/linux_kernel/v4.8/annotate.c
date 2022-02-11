static void F_1 ( struct V_1 * V_2 )
{
if ( V_2 == NULL )
return;
F_2 ( & V_2 -> V_3 . V_4 ) ;
F_2 ( & V_2 -> V_3 . V_5 ) ;
F_2 ( & V_2 -> V_6 . V_4 ) ;
F_2 ( & V_2 -> V_6 . V_5 ) ;
}
static int F_3 ( struct V_7 * V_7 , char * V_8 , T_1 V_9 ,
struct V_1 * V_2 )
{
return F_4 ( V_8 , V_9 , L_1 , V_7 -> V_5 , V_2 -> V_4 ) ;
}
int F_5 ( struct V_7 * V_7 , char * V_8 , T_1 V_9 ,
struct V_1 * V_2 )
{
if ( V_7 -> V_2 -> F_4 )
return V_7 -> V_2 -> F_4 ( V_7 , V_8 , V_9 , V_2 ) ;
return F_3 ( V_7 , V_8 , V_9 , V_2 ) ;
}
static int F_6 ( struct V_1 * V_2 )
{
char * V_10 , * V_11 , * V_5 ;
V_2 -> V_6 . V_12 = F_7 ( V_2 -> V_4 , & V_10 , 16 ) ;
V_5 = strchr ( V_10 , '<' ) ;
if ( V_5 == NULL )
goto V_13;
V_5 ++ ;
#ifdef F_8
if ( strchr ( V_5 , '+' ) )
return - 1 ;
#endif
V_11 = strchr ( V_5 , '>' ) ;
if ( V_11 == NULL )
return - 1 ;
* V_11 = '\0' ;
V_2 -> V_6 . V_5 = F_9 ( V_5 ) ;
* V_11 = '>' ;
return V_2 -> V_6 . V_5 == NULL ? - 1 : 0 ;
V_13:
V_11 = strchr ( V_10 , '(' ) ;
if ( V_11 != NULL ) {
V_2 -> V_6 . V_12 = 0 ;
return 0 ;
}
V_11 = strchr ( V_10 , '*' ) ;
if ( V_11 == NULL )
return - 1 ;
V_2 -> V_6 . V_12 = F_7 ( V_11 + 1 , NULL , 16 ) ;
return 0 ;
}
static int F_10 ( struct V_7 * V_7 , char * V_8 , T_1 V_9 ,
struct V_1 * V_2 )
{
if ( V_2 -> V_6 . V_5 )
return F_4 ( V_8 , V_9 , L_1 , V_7 -> V_5 , V_2 -> V_6 . V_5 ) ;
if ( V_2 -> V_6 . V_12 == 0 )
return F_3 ( V_7 , V_8 , V_9 , V_2 ) ;
return F_4 ( V_8 , V_9 , L_2 V_14 , V_7 -> V_5 , V_2 -> V_6 . V_12 ) ;
}
bool F_11 ( const struct V_7 * V_7 )
{
return V_7 -> V_2 == & V_15 ;
}
static int F_12 ( struct V_1 * V_2 )
{
const char * V_16 = strchr ( V_2 -> V_4 , '+' ) ;
V_2 -> V_6 . V_12 = F_7 ( V_2 -> V_4 , NULL , 16 ) ;
if ( V_16 ++ != NULL )
V_2 -> V_6 . V_17 = F_7 ( V_16 , NULL , 16 ) ;
else
V_2 -> V_6 . V_17 = V_18 ;
return 0 ;
}
static int F_13 ( struct V_7 * V_7 , char * V_8 , T_1 V_9 ,
struct V_1 * V_2 )
{
return F_4 ( V_8 , V_9 , L_3 V_14 , V_7 -> V_5 , V_2 -> V_6 . V_17 ) ;
}
bool F_14 ( const struct V_7 * V_7 )
{
return V_7 -> V_2 == & V_19 ;
}
static int F_15 ( char * V_4 , char * V_20 , T_2 * V_21 , char * * V_22 )
{
char * V_10 , * V_5 , * V_23 ;
if ( strstr ( V_4 , L_4 ) == NULL )
return 0 ;
* V_21 = F_7 ( V_20 , & V_10 , 16 ) ;
V_5 = strchr ( V_10 , '<' ) ;
if ( V_5 == NULL )
return - 1 ;
V_5 ++ ;
V_23 = strchr ( V_5 , '>' ) ;
if ( V_23 == NULL )
return 0 ;
* V_23 = '\0' ;
* V_22 = F_9 ( V_5 ) ;
* V_23 = '>' ;
return 0 ;
}
static int F_16 ( struct V_1 * V_2 )
{
char * V_5 ;
V_2 -> V_24 . V_2 = F_17 ( sizeof( * V_2 -> V_24 . V_2 ) ) ;
if ( V_2 -> V_24 . V_2 == NULL )
return 0 ;
if ( F_18 ( V_2 -> V_4 , & V_5 , & V_2 -> V_24 . V_2 -> V_4 ) < 0 )
goto V_25;
V_2 -> V_24 . V_7 = F_19 ( V_5 ) ;
free ( V_5 ) ;
if ( V_2 -> V_24 . V_7 == NULL )
goto V_25;
if ( ! V_2 -> V_24 . V_7 -> V_2 )
return 0 ;
if ( V_2 -> V_24 . V_7 -> V_2 -> V_26 &&
V_2 -> V_24 . V_7 -> V_2 -> V_26 ( V_2 -> V_24 . V_2 ) < 0 )
goto V_25;
return 0 ;
V_25:
F_2 ( & V_2 -> V_24 . V_2 ) ;
return 0 ;
}
static int F_20 ( struct V_7 * V_7 , char * V_8 , T_1 V_9 ,
struct V_1 * V_2 )
{
int V_27 ;
if ( V_2 -> V_24 . V_7 == NULL )
return F_3 ( V_7 , V_8 , V_9 , V_2 ) ;
V_27 = F_4 ( V_8 , V_9 , L_5 , V_7 -> V_5 ) ;
return V_27 + F_5 ( V_2 -> V_24 . V_7 , V_8 + V_27 ,
V_9 - V_27 , V_2 -> V_24 . V_2 ) ;
}
static void F_21 ( struct V_1 * V_2 )
{
struct V_7 * V_7 = V_2 -> V_24 . V_7 ;
if ( V_7 && V_7 -> V_2 -> free )
V_7 -> V_2 -> free ( V_2 -> V_24 . V_2 ) ;
else
F_1 ( V_2 -> V_24 . V_2 ) ;
F_2 ( & V_2 -> V_24 . V_2 ) ;
F_2 ( & V_2 -> V_6 . V_4 ) ;
F_2 ( & V_2 -> V_6 . V_5 ) ;
}
static int F_22 ( struct V_1 * V_2 )
{
char * V_16 = strchr ( V_2 -> V_4 , ',' ) , * V_6 , * V_20 , V_28 ;
if ( V_16 == NULL )
return - 1 ;
* V_16 = '\0' ;
V_2 -> V_3 . V_4 = F_9 ( V_2 -> V_4 ) ;
* V_16 = ',' ;
if ( V_2 -> V_3 . V_4 == NULL )
return - 1 ;
V_6 = ++ V_16 ;
#ifdef F_8
V_20 = strchr ( V_16 , ';' ) ;
#else
V_20 = strchr ( V_16 , '#' ) ;
#endif
if ( V_20 != NULL )
V_16 = V_20 - 1 ;
else
V_16 = strchr ( V_16 , '\0' ) - 1 ;
while ( V_16 > V_6 && isspace ( V_16 [ 0 ] ) )
-- V_16 ;
V_16 ++ ;
V_28 = * V_16 ;
* V_16 = '\0' ;
V_2 -> V_6 . V_4 = F_9 ( V_6 ) ;
* V_16 = V_28 ;
if ( V_2 -> V_6 . V_4 == NULL )
goto V_29;
if ( V_20 == NULL )
return 0 ;
while ( V_20 [ 0 ] != '\0' && isspace ( V_20 [ 0 ] ) )
++ V_20 ;
F_15 ( V_2 -> V_3 . V_4 , V_20 , & V_2 -> V_3 . V_12 , & V_2 -> V_3 . V_5 ) ;
F_15 ( V_2 -> V_6 . V_4 , V_20 , & V_2 -> V_6 . V_12 , & V_2 -> V_6 . V_5 ) ;
return 0 ;
V_29:
F_2 ( & V_2 -> V_3 . V_4 ) ;
return - 1 ;
}
static int F_23 ( struct V_7 * V_7 , char * V_8 , T_1 V_9 ,
struct V_1 * V_2 )
{
return F_4 ( V_8 , V_9 , L_6 , V_7 -> V_5 ,
V_2 -> V_3 . V_5 ? : V_2 -> V_3 . V_4 ,
V_2 -> V_6 . V_5 ? : V_2 -> V_6 . V_4 ) ;
}
static int F_24 ( struct V_1 * V_2 )
{
char * V_6 , * V_20 , * V_16 , V_28 ;
V_6 = V_16 = V_2 -> V_4 ;
while ( V_16 [ 0 ] != '\0' && ! isspace ( V_16 [ 0 ] ) )
++ V_16 ;
V_28 = * V_16 ;
* V_16 = '\0' ;
V_2 -> V_6 . V_4 = F_9 ( V_6 ) ;
* V_16 = V_28 ;
if ( V_2 -> V_6 . V_4 == NULL )
return - 1 ;
V_20 = strchr ( V_16 , '#' ) ;
if ( V_20 == NULL )
return 0 ;
while ( V_20 [ 0 ] != '\0' && isspace ( V_20 [ 0 ] ) )
++ V_20 ;
F_15 ( V_2 -> V_6 . V_4 , V_20 , & V_2 -> V_6 . V_12 , & V_2 -> V_6 . V_5 ) ;
return 0 ;
}
static int F_25 ( struct V_7 * V_7 , char * V_8 , T_1 V_9 ,
struct V_1 * V_2 )
{
return F_4 ( V_8 , V_9 , L_1 , V_7 -> V_5 ,
V_2 -> V_6 . V_5 ? : V_2 -> V_6 . V_4 ) ;
}
static int F_26 ( struct V_7 * V_7 V_30 , char * V_8 , T_1 V_9 ,
struct V_1 * V_2 V_30 )
{
return F_4 ( V_8 , V_9 , L_7 , L_8 ) ;
}
bool F_27 ( const struct V_7 * V_7 )
{
return V_7 -> V_2 == & V_31 ;
}
static int F_28 ( const void * V_5 , const void * V_32 )
{
const struct V_7 * V_7 = V_32 ;
return strcmp ( V_5 , V_7 -> V_5 ) ;
}
static int F_29 ( const void * V_33 , const void * V_34 )
{
const struct V_7 * V_35 = V_33 ;
const struct V_7 * V_36 = V_34 ;
return strcmp ( V_35 -> V_5 , V_36 -> V_5 ) ;
}
static void F_30 ( void )
{
const int V_37 = F_31 ( V_38 ) ;
qsort ( V_38 , V_37 , sizeof( struct V_7 ) , F_29 ) ;
}
static struct V_7 * F_19 ( const char * V_5 )
{
const int V_37 = F_31 ( V_38 ) ;
static bool V_39 ;
if ( ! V_39 ) {
F_30 () ;
V_39 = true ;
}
return bsearch ( V_5 , V_38 , V_37 , sizeof( struct V_7 ) , F_28 ) ;
}
int F_32 ( struct V_40 * V_40 V_30 , struct V_41 * V_42 )
{
struct V_43 * V_44 = F_33 ( V_42 ) ;
F_34 ( & V_44 -> V_45 , NULL ) ;
return 0 ;
}
int F_35 ( struct V_41 * V_42 )
{
struct V_43 * V_44 = F_33 ( V_42 ) ;
const T_1 V_9 = F_36 ( V_42 ) ;
T_1 V_46 ;
if ( V_9 > ( V_47 - sizeof( struct V_48 ) ) / sizeof( T_2 ) )
return - 1 ;
V_46 = ( sizeof( struct V_48 ) + V_9 * sizeof( T_2 ) ) ;
if ( V_46 > ( V_47 - sizeof( * V_44 -> V_49 ) )
/ V_50 . V_51 )
return - 1 ;
V_44 -> V_49 = F_17 ( sizeof( * V_44 -> V_49 ) + V_50 . V_51 * V_46 ) ;
if ( V_44 -> V_49 == NULL )
return - 1 ;
V_44 -> V_49 -> V_46 = V_46 ;
V_44 -> V_49 -> V_52 = V_50 . V_51 ;
F_37 ( & V_44 -> V_49 -> V_3 ) ;
return 0 ;
}
static int F_38 ( struct V_41 * V_42 )
{
struct V_43 * V_44 = F_33 ( V_42 ) ;
const T_1 V_9 = F_36 ( V_42 ) ;
V_44 -> V_49 -> V_53 = calloc ( V_9 , sizeof( struct V_54 ) ) ;
if ( V_44 -> V_49 -> V_53 == NULL )
return - 1 ;
return 0 ;
}
void F_39 ( struct V_41 * V_42 )
{
struct V_43 * V_44 = F_33 ( V_42 ) ;
F_40 ( & V_44 -> V_45 ) ;
if ( V_44 -> V_49 != NULL ) {
memset ( V_44 -> V_49 -> V_55 , 0 ,
V_44 -> V_49 -> V_52 * V_44 -> V_49 -> V_46 ) ;
if ( V_44 -> V_49 -> V_53 )
memset ( V_44 -> V_49 -> V_53 , 0 ,
F_36 ( V_42 ) * sizeof( struct V_54 ) ) ;
}
F_41 ( & V_44 -> V_45 ) ;
}
static int F_42 ( struct V_43 * V_44 ,
T_2 V_56 ,
unsigned V_17 , unsigned V_57 ,
unsigned V_58 )
{
struct V_54 * V_59 ;
V_59 = V_44 -> V_49 -> V_53 ;
V_59 [ V_17 ] . V_60 ++ ;
V_59 [ V_17 ] . V_61 += V_57 ;
if ( ! V_58 && V_59 [ V_17 ] . V_58 )
return 0 ;
if ( V_59 [ V_17 ] . V_62 ) {
if ( V_58 && ( ! V_59 [ V_17 ] . V_58 ||
V_59 [ V_17 ] . V_56 > V_56 ) ) {
V_59 [ V_17 ] . V_58 = 0 ;
V_59 [ V_17 ] . V_57 = 0 ;
V_59 [ V_17 ] . V_62 = 0 ;
if ( V_59 [ V_17 ] . V_63 < 0xffff )
V_59 [ V_17 ] . V_63 ++ ;
} else if ( V_58 &&
V_59 [ V_17 ] . V_56 < V_56 )
return 0 ;
}
V_59 [ V_17 ] . V_58 = V_58 ;
V_59 [ V_17 ] . V_56 = V_56 ;
V_59 [ V_17 ] . V_57 += V_57 ;
V_59 [ V_17 ] . V_62 ++ ;
return 0 ;
}
static int F_43 ( struct V_41 * V_42 , struct V_40 * V_40 ,
struct V_43 * V_44 , int V_64 , T_2 V_12 )
{
unsigned V_17 ;
struct V_48 * V_65 ;
F_44 ( L_9 V_14 L_10 , V_66 , V_40 -> V_67 ( V_40 , V_12 ) ) ;
if ( V_12 < V_42 -> V_56 || V_12 >= V_42 -> V_68 ) {
F_45 ( L_11 V_14 L_12 V_14 L_13 V_14 L_10 ,
V_66 , __LINE__ , V_42 -> V_5 , V_42 -> V_56 , V_12 , V_42 -> V_68 ) ;
return - V_69 ;
}
V_17 = V_12 - V_42 -> V_56 ;
V_65 = F_46 ( V_44 , V_64 ) ;
V_65 -> V_70 ++ ;
V_65 -> V_12 [ V_17 ] ++ ;
F_44 ( L_14 V_14 L_15 V_14 L_16 V_14
L_17 V_71 L_10 , V_42 -> V_56 , V_42 -> V_5 ,
V_12 , V_12 - V_42 -> V_56 , V_64 , V_65 -> V_12 [ V_17 ] ) ;
return 0 ;
}
static struct V_43 * F_47 ( struct V_41 * V_42 , bool V_57 )
{
struct V_43 * V_44 = F_33 ( V_42 ) ;
if ( V_44 -> V_49 == NULL ) {
if ( F_35 ( V_42 ) < 0 )
return NULL ;
}
if ( ! V_44 -> V_49 -> V_53 && V_57 ) {
if ( F_38 ( V_42 ) < 0 )
return NULL ;
}
return V_44 ;
}
static int F_48 ( struct V_41 * V_42 , struct V_40 * V_40 ,
int V_64 , T_2 V_12 )
{
struct V_43 * V_44 ;
if ( V_42 == NULL )
return 0 ;
V_44 = F_47 ( V_42 , false ) ;
if ( V_44 == NULL )
return - V_72 ;
return F_43 ( V_42 , V_40 , V_44 , V_64 , V_12 ) ;
}
static int F_49 ( T_2 V_12 , T_2 V_56 ,
struct V_41 * V_42 , unsigned V_57 )
{
struct V_43 * V_44 ;
unsigned V_17 ;
if ( V_42 == NULL )
return 0 ;
V_44 = F_47 ( V_42 , true ) ;
if ( V_44 == NULL )
return - V_72 ;
if ( V_12 < V_42 -> V_56 || V_12 >= V_42 -> V_68 )
return - V_69 ;
if ( V_56 ) {
if ( V_56 < V_42 -> V_56 || V_56 >= V_42 -> V_68 )
return - V_69 ;
if ( V_56 >= V_12 )
V_56 = 0 ;
}
V_17 = V_12 - V_42 -> V_56 ;
return F_42 ( V_44 ,
V_56 ? V_56 - V_42 -> V_56 : 0 ,
V_17 , V_57 ,
! ! V_56 ) ;
}
int F_50 ( struct V_73 * V_74 ,
struct V_73 * V_56 ,
unsigned V_57 )
{
T_2 V_75 = 0 ;
int V_76 ;
if ( ! V_57 )
return 0 ;
if ( V_56 &&
( V_56 -> V_42 == V_74 -> V_42 ||
( V_74 -> V_42 &&
V_56 -> V_12 == V_74 -> V_42 -> V_56 + V_74 -> V_40 -> V_56 ) ) )
V_75 = V_56 -> V_77 ;
if ( V_75 == 0 )
F_51 ( L_18 V_14 L_19 V_14 L_20 V_14 L_21 V_14 L_10 ,
V_74 -> V_12 ,
V_56 ? V_56 -> V_12 : 0 ,
V_74 -> V_42 ? V_74 -> V_42 -> V_56 + V_74 -> V_40 -> V_56 : 0 ,
V_75 ) ;
V_76 = F_49 ( V_74 -> V_77 , V_75 , V_74 -> V_42 , V_57 ) ;
if ( V_76 )
F_51 ( L_22 , V_76 ) ;
return V_76 ;
}
int F_52 ( struct V_73 * V_74 , int V_64 )
{
return F_48 ( V_74 -> V_42 , V_74 -> V_40 , V_64 , V_74 -> V_77 ) ;
}
int F_53 ( struct V_78 * V_79 , int V_64 , T_2 V_80 )
{
return F_48 ( V_79 -> V_81 . V_42 , V_79 -> V_81 . V_40 , V_64 , V_80 ) ;
}
static void F_54 ( struct V_82 * V_83 )
{
V_83 -> V_7 = F_19 ( V_83 -> V_5 ) ;
if ( V_83 -> V_7 == NULL )
return;
if ( ! V_83 -> V_7 -> V_2 )
return;
if ( V_83 -> V_7 -> V_2 -> V_26 && V_83 -> V_7 -> V_2 -> V_26 ( & V_83 -> V_2 ) < 0 )
V_83 -> V_7 = NULL ;
}
static int F_18 ( char * line , char * * V_22 , char * * V_84 )
{
char * V_5 = line , V_85 ;
while ( isspace ( V_5 [ 0 ] ) )
++ V_5 ;
if ( V_5 [ 0 ] == '\0' )
return - 1 ;
* V_84 = V_5 + 1 ;
while ( ( * V_84 ) [ 0 ] != '\0' && ! isspace ( ( * V_84 ) [ 0 ] ) )
++ * V_84 ;
V_85 = ( * V_84 ) [ 0 ] ;
( * V_84 ) [ 0 ] = '\0' ;
* V_22 = F_9 ( V_5 ) ;
if ( * V_22 == NULL )
goto V_86;
( * V_84 ) [ 0 ] = V_85 ;
if ( ( * V_84 ) [ 0 ] != '\0' ) {
( * V_84 ) ++ ;
while ( isspace ( ( * V_84 ) [ 0 ] ) )
++ ( * V_84 ) ;
}
return 0 ;
V_86:
F_2 ( V_22 ) ;
return - 1 ;
}
static struct V_82 * F_55 ( T_3 V_17 , char * line ,
T_1 V_87 , int V_88 )
{
struct V_82 * V_83 = F_17 ( sizeof( * V_83 ) + V_87 ) ;
if ( V_83 != NULL ) {
V_83 -> V_17 = V_17 ;
V_83 -> line = F_9 ( line ) ;
V_83 -> V_88 = V_88 ;
if ( V_83 -> line == NULL )
goto V_89;
if ( V_17 != - 1 ) {
if ( F_18 ( V_83 -> line , & V_83 -> V_5 , & V_83 -> V_2 . V_4 ) < 0 )
goto V_90;
F_54 ( V_83 ) ;
}
}
return V_83 ;
V_90:
F_2 ( & V_83 -> line ) ;
V_89:
free ( V_83 ) ;
return NULL ;
}
void F_56 ( struct V_82 * V_83 )
{
F_2 ( & V_83 -> line ) ;
F_2 ( & V_83 -> V_5 ) ;
if ( V_83 -> V_7 && V_83 -> V_7 -> V_2 -> free )
V_83 -> V_7 -> V_2 -> free ( & V_83 -> V_2 ) ;
else
F_1 ( & V_83 -> V_2 ) ;
free ( V_83 ) ;
}
int F_57 ( struct V_82 * V_83 , char * V_8 , T_1 V_9 , bool V_4 )
{
if ( V_4 || ! V_83 -> V_7 )
return F_4 ( V_8 , V_9 , L_1 , V_83 -> V_5 , V_83 -> V_2 . V_4 ) ;
return F_5 ( V_83 -> V_7 , V_8 , V_9 , & V_83 -> V_2 ) ;
}
static void F_58 ( struct V_91 * V_92 , struct V_82 * line )
{
F_59 ( & line -> V_93 , V_92 ) ;
}
struct V_82 * F_60 ( struct V_91 * V_92 , struct V_82 * V_94 )
{
F_61 (pos, head, node)
if ( V_94 -> V_17 >= 0 )
return V_94 ;
return NULL ;
}
double F_62 ( struct V_43 * V_44 , int V_64 , T_3 V_17 ,
T_3 V_68 , const char * * V_95 , T_2 * V_96 )
{
struct V_97 * V_98 = V_44 -> V_49 -> V_99 ;
double V_100 = 0.0 ;
* V_96 = 0 ;
if ( V_98 ) {
T_1 V_101 = sizeof( * V_98 ) +
sizeof( V_98 -> V_102 ) * ( V_98 -> V_103 - 1 ) ;
while ( V_17 < V_68 ) {
V_98 = ( void * ) V_44 -> V_49 -> V_99 +
( V_101 * V_17 ) ;
if ( * V_95 == NULL )
* V_95 = V_98 -> V_95 ;
V_100 += V_98 -> V_102 [ V_64 ] . V_100 ;
* V_96 += V_98 -> V_102 [ V_64 ] . V_104 ;
V_17 ++ ;
}
} else {
struct V_48 * V_65 = F_46 ( V_44 , V_64 ) ;
unsigned int V_105 = 0 ;
while ( V_17 < V_68 )
V_105 += V_65 -> V_12 [ V_17 ++ ] ;
if ( V_65 -> V_70 ) {
* V_96 = V_105 ;
V_100 = 100.0 * V_105 / V_65 -> V_70 ;
}
}
return V_100 ;
}
static int F_63 ( struct V_82 * V_83 , struct V_41 * V_42 , T_2 V_56 ,
struct V_106 * V_107 , T_2 V_108 , int V_109 , int V_27 ,
int V_110 , struct V_82 * V_111 )
{
static const char * V_112 ;
static const char * V_113 ;
if ( V_83 -> V_17 != - 1 ) {
const char * V_95 = NULL ;
T_2 V_96 ;
double V_100 , V_114 = 0.0 ;
double * V_115 = & V_100 ;
T_2 * V_116 = & V_96 ;
int V_117 , V_118 = 1 ;
const char * V_119 ;
struct V_43 * V_44 = F_33 ( V_42 ) ;
T_3 V_17 = V_83 -> V_17 ;
const T_2 V_12 = V_56 + V_17 ;
struct V_82 * V_120 ;
V_120 = F_60 ( & V_44 -> V_49 -> V_3 , V_83 ) ;
if ( F_64 ( V_107 ) ) {
V_118 = V_107 -> V_121 ;
V_115 = calloc ( V_118 , sizeof( double ) ) ;
V_116 = calloc ( V_118 , sizeof( T_2 ) ) ;
if ( V_115 == NULL || V_116 == NULL ) {
return - 1 ;
}
}
for ( V_117 = 0 ; V_117 < V_118 ; V_117 ++ ) {
V_100 = F_62 ( V_44 ,
V_44 -> V_49 -> V_99 ? V_117 : V_107 -> V_122 + V_117 ,
V_17 ,
V_120 ? V_120 -> V_17 : ( T_3 ) V_108 ,
& V_95 , & V_96 ) ;
V_115 [ V_117 ] = V_100 ;
V_116 [ V_117 ] = V_96 ;
if ( V_100 > V_114 )
V_114 = V_100 ;
}
if ( V_114 < V_109 )
return - 1 ;
if ( V_110 && V_27 >= V_110 )
return 1 ;
if ( V_111 != NULL ) {
F_65 (queue, &notes->src->source, node) {
if ( V_111 == V_83 )
break;
F_63 ( V_111 , V_42 , V_56 , V_107 , V_108 ,
0 , 0 , 1 , NULL ) ;
}
}
V_119 = F_66 ( V_114 ) ;
if ( V_95 ) {
if ( ! V_112 || strcmp ( V_112 , V_95 )
|| V_119 != V_113 ) {
F_67 ( stdout , V_119 , L_23 , V_95 ) ;
V_112 = V_95 ;
V_113 = V_119 ;
}
}
for ( V_117 = 0 ; V_117 < V_118 ; V_117 ++ ) {
V_100 = V_115 [ V_117 ] ;
V_96 = V_116 [ V_117 ] ;
V_119 = F_66 ( V_100 ) ;
if ( V_50 . V_123 )
F_67 ( stdout , V_119 , L_24 V_71 ,
V_96 ) ;
else
F_67 ( stdout , V_119 , L_25 , V_100 ) ;
}
printf ( L_26 ) ;
F_67 ( stdout , V_124 , L_27 V_14 L_28 , V_12 ) ;
F_67 ( stdout , V_125 , L_29 , V_83 -> line ) ;
if ( V_115 != & V_100 )
free ( V_115 ) ;
if ( V_116 != & V_96 )
free ( V_116 ) ;
} else if ( V_110 && V_27 >= V_110 )
return 1 ;
else {
int V_126 = 8 ;
if ( V_111 )
return - 1 ;
if ( F_64 ( V_107 ) )
V_126 *= V_107 -> V_121 ;
if ( ! * V_83 -> line )
printf ( L_30 , V_126 , L_31 ) ;
else
printf ( L_32 , V_126 , L_31 , V_83 -> line ) ;
}
return 0 ;
}
static int F_68 ( struct V_41 * V_42 , struct V_40 * V_40 ,
T_4 * V_127 , T_1 V_87 ,
int * V_88 )
{
struct V_43 * V_44 = F_33 ( V_42 ) ;
struct V_82 * V_83 ;
char * line = NULL , * V_128 , * V_85 , * V_129 , * V_130 ;
T_1 V_131 ;
T_3 V_132 , V_17 = - 1 ;
T_5 V_133 [ 2 ] ;
if ( F_69 ( & line , & V_131 , V_127 ) < 0 )
return - 1 ;
if ( ! line )
return - 1 ;
while ( V_131 != 0 && isspace ( line [ V_131 - 1 ] ) )
line [ -- V_131 ] = '\0' ;
V_130 = strchr ( line , '\n' ) ;
if ( V_130 )
* V_130 = 0 ;
V_132 = - 1 ;
V_128 = line ;
if ( regexec ( & V_134 , line , 2 , V_133 , 0 ) == 0 ) {
* V_88 = atoi ( line + V_133 [ 1 ] . V_135 ) ;
return 0 ;
}
V_85 = line ;
while ( * V_85 ) {
if ( * V_85 != ' ' )
break;
V_85 ++ ;
}
if ( * V_85 ) {
V_132 = F_7 ( V_85 , & V_129 , 16 ) ;
if ( * V_129 != ':' || V_85 == V_129 || V_129 [ 1 ] == '\0' )
V_132 = - 1 ;
}
if ( V_132 != - 1 ) {
T_2 V_56 = F_70 ( V_40 , V_42 -> V_56 ) ,
V_68 = F_70 ( V_40 , V_42 -> V_68 ) ;
V_17 = V_132 - V_56 ;
if ( ( T_2 ) V_132 < V_56 || ( T_2 ) V_132 >= V_68 )
V_17 = - 1 ;
else
V_128 = V_129 + 1 ;
}
V_83 = F_55 ( V_17 , V_128 , V_87 , * V_88 ) ;
free ( line ) ;
( * V_88 ) ++ ;
if ( V_83 == NULL )
return - 1 ;
if ( V_83 -> V_2 . V_6 . V_17 == V_18 )
V_83 -> V_2 . V_6 . V_17 = V_83 -> V_2 . V_6 . V_12 -
F_70 ( V_40 , V_42 -> V_56 ) ;
if ( V_83 -> V_7 && F_11 ( V_83 -> V_7 ) && ! V_83 -> V_2 . V_6 . V_5 ) {
struct V_73 V_6 = {
. V_40 = V_40 ,
. V_12 = V_83 -> V_2 . V_6 . V_12 ,
} ;
if ( ! F_71 ( & V_6 , NULL ) &&
V_6 . V_42 -> V_56 == V_6 . V_77 )
V_83 -> V_2 . V_6 . V_5 = F_9 ( V_6 . V_42 -> V_5 ) ;
}
F_58 ( & V_44 -> V_49 -> V_3 , V_83 ) ;
return 0 ;
}
int F_72 ( struct V_41 * V_42 V_30 , struct V_40 * V_40 ,
int V_136 , char * V_137 , T_1 V_138 )
{
struct V_139 * V_139 = V_40 -> V_139 ;
F_73 ( V_138 == 0 ) ;
if ( V_136 >= 0 ) {
F_74 ( V_136 , V_137 , V_138 ) ;
return 0 ;
}
switch ( V_136 ) {
case V_140 : {
char V_8 [ V_141 + 15 ] = L_33 ;
char * V_142 = NULL ;
if ( V_139 -> V_143 ) {
F_75 ( V_139 -> V_144 ,
sizeof( V_139 -> V_144 ) , V_8 + 15 ) ;
V_142 = V_8 ;
}
F_4 ( V_137 , V_138 ,
L_34
L_35
L_36
L_37
L_38
L_39 , V_142 ? : L_40 ) ;
}
break;
default:
F_4 ( V_137 , V_138 , L_41 , V_136 ) ;
break;
}
return 0 ;
}
int F_76 ( struct V_41 * V_42 , struct V_40 * V_40 , T_1 V_87 )
{
struct V_139 * V_139 = V_40 -> V_139 ;
char * V_145 = F_77 ( V_139 , NULL , 0 ) ;
bool V_146 = true ;
char V_147 [ V_148 * 2 ] ;
T_4 * V_127 ;
int V_76 = 0 ;
char V_149 [ V_148 ] ;
struct V_150 V_151 ;
bool V_152 = false ;
int V_153 [ 2 ] ;
int V_154 = 0 ;
int V_155 ;
T_6 V_156 ;
if ( V_145 )
F_78 ( V_149 , V_145 ) ;
if ( V_145 == NULL ) {
if ( V_139 -> V_143 )
return V_72 ;
goto V_157;
} else if ( F_79 ( V_139 ) ||
F_80 ( V_149 , V_147 , sizeof( V_147 ) ) < 0 ||
strstr ( V_147 , V_158 ) ||
F_81 ( V_149 , V_159 ) ) {
free ( V_145 ) ;
V_157:
V_145 = ( char * ) V_139 -> V_160 ;
F_78 ( V_149 , V_145 ) ;
V_146 = false ;
}
if ( V_139 -> V_161 == V_162 &&
! F_79 ( V_139 ) ) {
V_76 = V_140 ;
goto V_163;
}
F_45 ( L_42 V_14 L_13 V_14 L_10 , V_66 ,
V_145 , V_42 -> V_5 , V_40 -> V_67 ( V_40 , V_42 -> V_56 ) ,
V_40 -> V_67 ( V_40 , V_42 -> V_68 ) ) ;
F_45 ( L_43 ,
V_139 , V_139 -> V_160 , V_42 , V_42 -> V_5 ) ;
if ( F_79 ( V_139 ) ) {
V_151 . V_164 = V_149 ;
V_151 . V_12 = F_70 ( V_40 , V_42 -> V_56 ) ;
V_151 . V_165 = V_42 -> V_56 ;
V_151 . V_108 = V_42 -> V_68 - V_42 -> V_56 ;
if ( ! F_82 ( & V_151 ) ) {
V_152 = true ;
F_83 ( V_149 , V_151 . V_166 ,
sizeof( V_149 ) ) ;
if ( V_146 ) {
free ( V_145 ) ;
V_146 = false ;
}
V_145 = V_149 ;
}
} else if ( F_84 ( V_139 ) ) {
char V_85 [ V_148 ] ;
struct V_167 V_168 ;
int V_169 ;
bool V_170 ;
if ( F_85 ( & V_168 , V_149 ) )
goto V_163;
snprintf ( V_85 , V_148 , L_44 ) ;
V_169 = F_86 ( V_85 ) ;
if ( V_169 < 0 ) {
free ( V_168 . V_171 ) ;
goto V_163;
}
V_170 = F_87 ( V_168 . V_171 , V_149 , V_169 ) ;
if ( V_170 )
F_88 ( L_45 , V_168 . V_171 , V_149 ) ;
free ( V_168 . V_171 ) ;
F_89 ( V_169 ) ;
if ( ! V_170 )
goto V_163;
strcpy ( V_149 , V_85 ) ;
}
snprintf ( V_147 , sizeof( V_147 ) ,
L_46 V_14
L_47 V_14
L_48 ,
V_172 ? V_172 : L_49 ,
V_173 ? L_50 : L_40 ,
V_173 ? V_173 : L_40 ,
F_70 ( V_40 , V_42 -> V_56 ) ,
F_70 ( V_40 , V_42 -> V_68 ) ,
V_50 . V_174 ? L_40 : L_51 ,
V_50 . V_175 ? L_52 : L_40 ,
V_149 , V_145 ) ;
F_45 ( L_53 , V_147 ) ;
V_76 = - 1 ;
if ( F_90 ( V_153 ) < 0 ) {
F_88 ( L_54 , V_147 ) ;
goto V_176;
}
V_156 = F_91 () ;
if ( V_156 < 0 ) {
F_88 ( L_55 , V_147 ) ;
goto V_177;
}
if ( V_156 == 0 ) {
F_89 ( V_153 [ 0 ] ) ;
F_92 ( V_153 [ 1 ] , 1 ) ;
F_89 ( V_153 [ 1 ] ) ;
F_93 ( L_56 , L_57 , L_58 , V_147 , NULL ) ;
perror ( V_147 ) ;
exit ( - 1 ) ;
}
F_89 ( V_153 [ 1 ] ) ;
V_127 = fdopen ( V_153 [ 0 ] , L_59 ) ;
if ( ! V_127 ) {
F_88 ( L_60 , V_147 ) ;
goto V_176;
}
V_155 = 0 ;
while ( ! feof ( V_127 ) ) {
if ( F_68 ( V_42 , V_40 , V_127 , V_87 ,
& V_154 ) < 0 )
break;
V_155 ++ ;
}
if ( V_155 == 0 )
F_88 ( L_61 , V_147 ) ;
if ( F_79 ( V_139 ) )
F_94 ( V_42 ) ;
fclose ( V_127 ) ;
V_76 = 0 ;
V_176:
F_89 ( V_153 [ 0 ] ) ;
if ( F_84 ( V_139 ) )
F_95 ( V_149 ) ;
V_163:
if ( V_152 )
F_96 ( & V_151 ) ;
if ( V_146 )
free ( V_145 ) ;
return V_76 ;
V_177:
F_89 ( V_153 [ 1 ] ) ;
goto V_176;
}
static void F_97 ( struct V_178 * V_179 , struct V_97 * V_98 )
{
struct V_97 * V_180 ;
struct V_181 * * V_182 = & V_179 -> V_181 ;
struct V_181 * V_183 = NULL ;
int V_117 , V_170 ;
while ( * V_182 != NULL ) {
V_183 = * V_182 ;
V_180 = F_98 ( V_183 , struct V_97 , V_93 ) ;
V_170 = strcmp ( V_180 -> V_95 , V_98 -> V_95 ) ;
if ( V_170 == 0 ) {
for ( V_117 = 0 ; V_117 < V_98 -> V_103 ; V_117 ++ )
V_180 -> V_102 [ V_117 ] . V_184 += V_98 -> V_102 [ V_117 ] . V_100 ;
return;
}
if ( V_170 < 0 )
V_182 = & ( * V_182 ) -> V_185 ;
else
V_182 = & ( * V_182 ) -> V_186 ;
}
for ( V_117 = 0 ; V_117 < V_98 -> V_103 ; V_117 ++ )
V_98 -> V_102 [ V_117 ] . V_184 = V_98 -> V_102 [ V_117 ] . V_100 ;
F_99 ( & V_98 -> V_93 , V_183 , V_182 ) ;
F_100 ( & V_98 -> V_93 , V_179 ) ;
}
static int F_101 ( struct V_97 * V_33 , struct V_97 * V_34 )
{
int V_117 ;
for ( V_117 = 0 ; V_117 < V_33 -> V_103 ; V_117 ++ ) {
if ( V_33 -> V_102 [ V_117 ] . V_184 == V_34 -> V_102 [ V_117 ] . V_184 )
continue;
return V_33 -> V_102 [ V_117 ] . V_184 > V_34 -> V_102 [ V_117 ] . V_184 ;
}
return 0 ;
}
static void F_102 ( struct V_178 * V_179 , struct V_97 * V_98 )
{
struct V_97 * V_180 ;
struct V_181 * * V_182 = & V_179 -> V_181 ;
struct V_181 * V_183 = NULL ;
while ( * V_182 != NULL ) {
V_183 = * V_182 ;
V_180 = F_98 ( V_183 , struct V_97 , V_93 ) ;
if ( F_101 ( V_98 , V_180 ) )
V_182 = & ( * V_182 ) -> V_185 ;
else
V_182 = & ( * V_182 ) -> V_186 ;
}
F_99 ( & V_98 -> V_93 , V_183 , V_182 ) ;
F_100 ( & V_98 -> V_93 , V_179 ) ;
}
static void F_103 ( struct V_178 * V_187 , struct V_178 * V_188 )
{
struct V_97 * V_98 ;
struct V_181 * V_93 ;
V_93 = F_104 ( V_188 ) ;
while ( V_93 ) {
struct V_181 * V_120 ;
V_98 = F_98 ( V_93 , struct V_97 , V_93 ) ;
V_120 = F_105 ( V_93 ) ;
F_106 ( V_93 , V_188 ) ;
F_102 ( V_187 , V_98 ) ;
V_93 = V_120 ;
}
}
static void F_107 ( struct V_41 * V_42 , int V_108 )
{
struct V_43 * V_44 = F_33 ( V_42 ) ;
struct V_97 * V_98 = V_44 -> V_49 -> V_99 ;
T_1 V_101 ;
int V_117 ;
V_101 = sizeof( * V_98 ) +
( sizeof( V_98 -> V_102 ) * ( V_98 -> V_103 - 1 ) ) ;
for ( V_117 = 0 ; V_117 < V_108 ; V_117 ++ ) {
F_108 ( V_98 -> V_95 ) ;
V_98 = ( void * ) V_98 + V_101 ;
}
F_2 ( & V_44 -> V_49 -> V_99 ) ;
}
static int F_109 ( struct V_41 * V_42 , struct V_40 * V_40 ,
struct V_106 * V_107 ,
struct V_178 * V_179 , int V_108 )
{
T_2 V_56 ;
int V_117 , V_189 ;
int V_64 = V_107 -> V_122 ;
struct V_97 * V_98 ;
struct V_43 * V_44 = F_33 ( V_42 ) ;
struct V_48 * V_65 = F_46 ( V_44 , V_64 ) ;
struct V_178 V_190 = V_191 ;
int V_103 = 1 ;
T_2 V_192 = V_65 -> V_70 ;
T_1 V_101 = sizeof( struct V_97 ) ;
if ( F_64 ( V_107 ) ) {
for ( V_117 = 1 ; V_117 < V_107 -> V_121 ; V_117 ++ ) {
V_65 = F_46 ( V_44 , V_64 + V_117 ) ;
V_192 += V_65 -> V_70 ;
}
V_103 = V_107 -> V_121 ;
V_101 += ( V_103 - 1 ) * sizeof( V_98 -> V_102 ) ;
}
if ( ! V_192 )
return 0 ;
V_98 = V_44 -> V_49 -> V_99 = calloc ( V_108 , V_101 ) ;
if ( ! V_44 -> V_49 -> V_99 )
return - 1 ;
V_56 = F_70 ( V_40 , V_42 -> V_56 ) ;
for ( V_117 = 0 ; V_117 < V_108 ; V_117 ++ ) {
T_2 V_17 ;
double V_193 = 0.0 ;
V_98 -> V_103 = V_103 ;
for ( V_189 = 0 ; V_189 < V_103 ; V_189 ++ ) {
V_65 = F_46 ( V_44 , V_64 + V_189 ) ;
V_98 -> V_102 [ V_189 ] . V_100 = 100.0 * V_65 -> V_12 [ V_117 ] / V_65 -> V_70 ;
if ( V_98 -> V_102 [ V_189 ] . V_100 > V_193 )
V_193 = V_98 -> V_102 [ V_189 ] . V_100 ;
}
if ( V_193 <= 0.5 )
goto V_120;
V_17 = V_56 + V_117 ;
V_98 -> V_95 = F_110 ( V_40 -> V_139 , V_17 , NULL , false ) ;
F_97 ( & V_190 , V_98 ) ;
V_120:
V_98 = ( void * ) V_98 + V_101 ;
}
F_103 ( V_179 , & V_190 ) ;
return 0 ;
}
static void F_111 ( struct V_178 * V_179 , const char * V_145 )
{
struct V_97 * V_98 ;
struct V_181 * V_93 ;
printf ( L_62 , V_145 ) ;
printf ( L_63 ) ;
if ( F_112 ( V_179 ) ) {
printf ( L_64 , V_194 ) ;
return;
}
V_93 = F_104 ( V_179 ) ;
while ( V_93 ) {
double V_100 , V_193 = 0.0 ;
const char * V_119 ;
char * V_95 ;
int V_117 ;
V_98 = F_98 ( V_93 , struct V_97 , V_93 ) ;
for ( V_117 = 0 ; V_117 < V_98 -> V_103 ; V_117 ++ ) {
V_100 = V_98 -> V_102 [ V_117 ] . V_184 ;
V_119 = F_66 ( V_100 ) ;
F_67 ( stdout , V_119 , L_25 , V_100 ) ;
if ( V_100 > V_193 )
V_193 = V_100 ;
}
V_95 = V_98 -> V_95 ;
V_119 = F_66 ( V_193 ) ;
F_67 ( stdout , V_119 , L_65 , V_95 ) ;
V_93 = F_105 ( V_93 ) ;
}
}
static void F_113 ( struct V_41 * V_42 , struct V_106 * V_107 )
{
struct V_43 * V_44 = F_33 ( V_42 ) ;
struct V_48 * V_65 = F_46 ( V_44 , V_107 -> V_122 ) ;
T_2 V_108 = F_36 ( V_42 ) , V_17 ;
for ( V_17 = 0 ; V_17 < V_108 ; ++ V_17 )
if ( V_65 -> V_12 [ V_17 ] != 0 )
printf ( L_66 V_14 L_67 V_71 L_10 , V_195 / 2 ,
V_42 -> V_56 + V_17 , V_65 -> V_12 [ V_17 ] ) ;
printf ( L_68 V_71 L_10 , V_195 / 2 , L_69 , V_65 -> V_70 ) ;
}
int F_114 ( struct V_41 * V_42 , struct V_40 * V_40 ,
struct V_106 * V_107 , bool V_196 ,
int V_109 , int V_110 , int V_197 )
{
struct V_139 * V_139 = V_40 -> V_139 ;
char * V_145 ;
const char * V_198 ;
const char * V_199 = F_115 ( V_107 ) ;
struct V_43 * V_44 = F_33 ( V_42 ) ;
struct V_48 * V_65 = F_46 ( V_44 , V_107 -> V_122 ) ;
struct V_82 * V_94 , * V_111 = NULL ;
T_2 V_56 = F_70 ( V_40 , V_42 -> V_56 ) ;
int V_27 = 2 , V_200 = 0 ;
int V_201 = 0 ;
T_2 V_108 ;
int V_126 = 8 ;
int V_202 ;
V_145 = F_9 ( V_139 -> V_160 ) ;
if ( ! V_145 )
return - V_72 ;
if ( V_196 )
V_198 = V_145 ;
else
V_198 = F_116 ( V_145 ) ;
V_108 = F_36 ( V_42 ) ;
if ( F_64 ( V_107 ) )
V_126 *= V_107 -> V_121 ;
V_202 = printf ( L_70 V_71 L_71 ,
V_126 , V_126 , L_72 , V_198 , V_199 , V_65 -> V_70 ) ;
printf ( L_73 ,
V_202 , V_202 , V_203 ) ;
if ( V_204 )
F_113 ( V_42 , V_107 ) ;
F_117 (pos, &notes->src->source, node) {
if ( V_197 && V_111 == NULL ) {
V_111 = V_94 ;
V_200 = 0 ;
}
switch ( F_63 ( V_94 , V_42 , V_56 , V_107 , V_108 ,
V_109 , V_27 , V_110 ,
V_111 ) ) {
case 0 :
++ V_27 ;
if ( V_197 ) {
V_27 += V_200 ;
V_111 = NULL ;
V_200 = 0 ;
}
break;
case 1 :
++ V_201 ;
break;
case - 1 :
default:
if ( ! V_197 )
break;
if ( V_200 == V_197 )
V_111 = F_118 ( V_111 -> V_93 . V_120 , F_119 ( * V_111 ) , V_93 ) ;
else
++ V_200 ;
break;
}
}
free ( V_145 ) ;
return V_201 ;
}
void F_120 ( struct V_41 * V_42 , int V_64 )
{
struct V_43 * V_44 = F_33 ( V_42 ) ;
struct V_48 * V_65 = F_46 ( V_44 , V_64 ) ;
memset ( V_65 , 0 , V_44 -> V_49 -> V_46 ) ;
}
void F_121 ( struct V_41 * V_42 , int V_64 )
{
struct V_43 * V_44 = F_33 ( V_42 ) ;
struct V_48 * V_65 = F_46 ( V_44 , V_64 ) ;
int V_108 = F_36 ( V_42 ) , V_17 ;
V_65 -> V_70 = 0 ;
for ( V_17 = 0 ; V_17 < V_108 ; ++ V_17 ) {
V_65 -> V_12 [ V_17 ] = V_65 -> V_12 [ V_17 ] * 7 / 8 ;
V_65 -> V_70 += V_65 -> V_12 [ V_17 ] ;
}
}
void F_122 ( struct V_91 * V_92 )
{
struct V_82 * V_94 , * V_205 ;
F_123 (pos, n, head, node) {
F_124 ( & V_94 -> V_93 ) ;
F_56 ( V_94 ) ;
}
}
static T_1 F_125 ( struct V_82 * V_83 , T_4 * V_206 )
{
T_1 V_27 ;
if ( V_83 -> V_17 == - 1 )
return fprintf ( V_206 , L_29 , V_83 -> line ) ;
V_27 = fprintf ( V_206 , L_14 V_14 L_23 , V_83 -> V_17 , V_83 -> V_5 ) ;
if ( V_83 -> V_2 . V_4 [ 0 ] != '\0' ) {
V_27 += fprintf ( V_206 , L_74 , 6 - ( int ) V_27 , L_31 ,
V_83 -> V_2 . V_4 ) ;
}
return V_27 + fprintf ( V_206 , L_10 ) ;
}
T_1 F_126 ( struct V_91 * V_92 , T_4 * V_206 )
{
struct V_82 * V_94 ;
T_1 V_27 = 0 ;
F_117 (pos, head, node)
V_27 += F_125 ( V_94 , V_206 ) ;
return V_27 ;
}
int F_127 ( struct V_41 * V_42 , struct V_40 * V_40 ,
struct V_106 * V_107 , bool V_207 ,
bool V_196 , int V_109 , int V_110 )
{
struct V_139 * V_139 = V_40 -> V_139 ;
struct V_178 V_97 = V_191 ;
T_2 V_108 ;
if ( F_76 ( V_42 , V_40 , 0 ) < 0 )
return - 1 ;
V_108 = F_36 ( V_42 ) ;
if ( V_207 ) {
V_208 = V_196 ;
F_109 ( V_42 , V_40 , V_107 , & V_97 , V_108 ) ;
F_111 ( & V_97 , V_139 -> V_160 ) ;
}
F_114 ( V_42 , V_40 , V_107 , V_196 ,
V_109 , V_110 , 0 ) ;
if ( V_207 )
F_107 ( V_42 , V_108 ) ;
F_122 ( & F_33 ( V_42 ) -> V_49 -> V_3 ) ;
return 0 ;
}
bool F_128 ( void )
{
return V_209 == 1 && V_210 . V_42 ;
}
