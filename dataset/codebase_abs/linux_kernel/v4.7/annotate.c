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
static int F_27 ( const void * V_5 , const void * V_31 )
{
const struct V_7 * V_7 = V_31 ;
return strcmp ( V_5 , V_7 -> V_5 ) ;
}
static int F_28 ( const void * V_32 , const void * V_33 )
{
const struct V_7 * V_34 = V_32 ;
const struct V_7 * V_35 = V_33 ;
return strcmp ( V_34 -> V_5 , V_35 -> V_5 ) ;
}
static void F_29 ( void )
{
const int V_36 = F_30 ( V_37 ) ;
qsort ( V_37 , V_36 , sizeof( struct V_7 ) , F_28 ) ;
}
static struct V_7 * F_19 ( const char * V_5 )
{
const int V_36 = F_30 ( V_37 ) ;
static bool V_38 ;
if ( ! V_38 ) {
F_29 () ;
V_38 = true ;
}
return bsearch ( V_5 , V_37 , V_36 , sizeof( struct V_7 ) , F_27 ) ;
}
int F_31 ( struct V_39 * V_39 V_30 , struct V_40 * V_41 )
{
struct V_42 * V_43 = F_32 ( V_41 ) ;
F_33 ( & V_43 -> V_44 , NULL ) ;
return 0 ;
}
int F_34 ( struct V_40 * V_41 )
{
struct V_42 * V_43 = F_32 ( V_41 ) ;
const T_1 V_9 = F_35 ( V_41 ) ;
T_1 V_45 ;
if ( V_9 > ( V_46 - sizeof( struct V_47 ) ) / sizeof( T_2 ) )
return - 1 ;
V_45 = ( sizeof( struct V_47 ) + V_9 * sizeof( T_2 ) ) ;
if ( V_45 > ( V_46 - sizeof( * V_43 -> V_48 ) )
/ V_49 . V_50 )
return - 1 ;
V_43 -> V_48 = F_17 ( sizeof( * V_43 -> V_48 ) + V_49 . V_50 * V_45 ) ;
if ( V_43 -> V_48 == NULL )
return - 1 ;
V_43 -> V_48 -> V_45 = V_45 ;
V_43 -> V_48 -> V_51 = V_49 . V_50 ;
F_36 ( & V_43 -> V_48 -> V_3 ) ;
return 0 ;
}
static int F_37 ( struct V_40 * V_41 )
{
struct V_42 * V_43 = F_32 ( V_41 ) ;
const T_1 V_9 = F_35 ( V_41 ) ;
V_43 -> V_48 -> V_52 = calloc ( V_9 , sizeof( struct V_53 ) ) ;
if ( V_43 -> V_48 -> V_52 == NULL )
return - 1 ;
return 0 ;
}
void F_38 ( struct V_40 * V_41 )
{
struct V_42 * V_43 = F_32 ( V_41 ) ;
F_39 ( & V_43 -> V_44 ) ;
if ( V_43 -> V_48 != NULL ) {
memset ( V_43 -> V_48 -> V_54 , 0 ,
V_43 -> V_48 -> V_51 * V_43 -> V_48 -> V_45 ) ;
if ( V_43 -> V_48 -> V_52 )
memset ( V_43 -> V_48 -> V_52 , 0 ,
F_35 ( V_41 ) * sizeof( struct V_53 ) ) ;
}
F_40 ( & V_43 -> V_44 ) ;
}
static int F_41 ( struct V_42 * V_43 ,
T_2 V_55 ,
unsigned V_17 , unsigned V_56 ,
unsigned V_57 )
{
struct V_53 * V_58 ;
V_58 = V_43 -> V_48 -> V_52 ;
V_58 [ V_17 ] . V_59 ++ ;
V_58 [ V_17 ] . V_60 += V_56 ;
if ( ! V_57 && V_58 [ V_17 ] . V_57 )
return 0 ;
if ( V_58 [ V_17 ] . V_61 ) {
if ( V_57 && ( ! V_58 [ V_17 ] . V_57 ||
V_58 [ V_17 ] . V_55 > V_55 ) ) {
V_58 [ V_17 ] . V_57 = 0 ;
V_58 [ V_17 ] . V_56 = 0 ;
V_58 [ V_17 ] . V_61 = 0 ;
if ( V_58 [ V_17 ] . V_62 < 0xffff )
V_58 [ V_17 ] . V_62 ++ ;
} else if ( V_57 &&
V_58 [ V_17 ] . V_55 < V_55 )
return 0 ;
}
V_58 [ V_17 ] . V_57 = V_57 ;
V_58 [ V_17 ] . V_55 = V_55 ;
V_58 [ V_17 ] . V_56 += V_56 ;
V_58 [ V_17 ] . V_61 ++ ;
return 0 ;
}
static int F_42 ( struct V_40 * V_41 , struct V_39 * V_39 ,
struct V_42 * V_43 , int V_63 , T_2 V_12 )
{
unsigned V_17 ;
struct V_47 * V_64 ;
F_43 ( L_9 V_14 L_10 , V_65 , V_39 -> V_66 ( V_39 , V_12 ) ) ;
if ( V_12 < V_41 -> V_55 || V_12 >= V_41 -> V_67 ) {
F_44 ( L_11 V_14 L_12 V_14 L_13 V_14 L_10 ,
V_65 , __LINE__ , V_41 -> V_5 , V_41 -> V_55 , V_12 , V_41 -> V_67 ) ;
return - V_68 ;
}
V_17 = V_12 - V_41 -> V_55 ;
V_64 = F_45 ( V_43 , V_63 ) ;
V_64 -> V_69 ++ ;
V_64 -> V_12 [ V_17 ] ++ ;
F_43 ( L_14 V_14 L_15 V_14 L_16 V_14
L_17 V_70 L_10 , V_41 -> V_55 , V_41 -> V_5 ,
V_12 , V_12 - V_41 -> V_55 , V_63 , V_64 -> V_12 [ V_17 ] ) ;
return 0 ;
}
static struct V_42 * F_46 ( struct V_40 * V_41 , bool V_56 )
{
struct V_42 * V_43 = F_32 ( V_41 ) ;
if ( V_43 -> V_48 == NULL ) {
if ( F_34 ( V_41 ) < 0 )
return NULL ;
}
if ( ! V_43 -> V_48 -> V_52 && V_56 ) {
if ( F_37 ( V_41 ) < 0 )
return NULL ;
}
return V_43 ;
}
static int F_47 ( struct V_40 * V_41 , struct V_39 * V_39 ,
int V_63 , T_2 V_12 )
{
struct V_42 * V_43 ;
if ( V_41 == NULL )
return 0 ;
V_43 = F_46 ( V_41 , false ) ;
if ( V_43 == NULL )
return - V_71 ;
return F_42 ( V_41 , V_39 , V_43 , V_63 , V_12 ) ;
}
static int F_48 ( T_2 V_12 , T_2 V_55 ,
struct V_40 * V_41 , unsigned V_56 )
{
struct V_42 * V_43 ;
unsigned V_17 ;
if ( V_41 == NULL )
return 0 ;
V_43 = F_46 ( V_41 , true ) ;
if ( V_43 == NULL )
return - V_71 ;
if ( V_12 < V_41 -> V_55 || V_12 >= V_41 -> V_67 )
return - V_68 ;
if ( V_55 ) {
if ( V_55 < V_41 -> V_55 || V_55 >= V_41 -> V_67 )
return - V_68 ;
if ( V_55 >= V_12 )
V_55 = 0 ;
}
V_17 = V_12 - V_41 -> V_55 ;
return F_41 ( V_43 ,
V_55 ? V_55 - V_41 -> V_55 : 0 ,
V_17 , V_56 ,
! ! V_55 ) ;
}
int F_49 ( struct V_72 * V_73 ,
struct V_72 * V_55 ,
unsigned V_56 )
{
T_2 V_74 = 0 ;
int V_75 ;
if ( ! V_56 )
return 0 ;
if ( V_55 &&
( V_55 -> V_41 == V_73 -> V_41 ||
( V_73 -> V_41 &&
V_55 -> V_12 == V_73 -> V_41 -> V_55 + V_73 -> V_39 -> V_55 ) ) )
V_74 = V_55 -> V_76 ;
if ( V_74 == 0 )
F_50 ( L_18 V_14 L_19 V_14 L_20 V_14 L_21 V_14 L_10 ,
V_73 -> V_12 ,
V_55 ? V_55 -> V_12 : 0 ,
V_73 -> V_41 ? V_73 -> V_41 -> V_55 + V_73 -> V_39 -> V_55 : 0 ,
V_74 ) ;
V_75 = F_48 ( V_73 -> V_76 , V_74 , V_73 -> V_41 , V_56 ) ;
if ( V_75 )
F_50 ( L_22 , V_75 ) ;
return V_75 ;
}
int F_51 ( struct V_72 * V_73 , int V_63 )
{
return F_47 ( V_73 -> V_41 , V_73 -> V_39 , V_63 , V_73 -> V_76 ) ;
}
int F_52 ( struct V_77 * V_78 , int V_63 , T_2 V_79 )
{
return F_47 ( V_78 -> V_80 . V_41 , V_78 -> V_80 . V_39 , V_63 , V_79 ) ;
}
static void F_53 ( struct V_81 * V_82 )
{
V_82 -> V_7 = F_19 ( V_82 -> V_5 ) ;
if ( V_82 -> V_7 == NULL )
return;
if ( ! V_82 -> V_7 -> V_2 )
return;
if ( V_82 -> V_7 -> V_2 -> V_26 && V_82 -> V_7 -> V_2 -> V_26 ( & V_82 -> V_2 ) < 0 )
V_82 -> V_7 = NULL ;
}
static int F_18 ( char * line , char * * V_22 , char * * V_83 )
{
char * V_5 = line , V_84 ;
while ( isspace ( V_5 [ 0 ] ) )
++ V_5 ;
if ( V_5 [ 0 ] == '\0' )
return - 1 ;
* V_83 = V_5 + 1 ;
while ( ( * V_83 ) [ 0 ] != '\0' && ! isspace ( ( * V_83 ) [ 0 ] ) )
++ * V_83 ;
V_84 = ( * V_83 ) [ 0 ] ;
( * V_83 ) [ 0 ] = '\0' ;
* V_22 = F_9 ( V_5 ) ;
if ( * V_22 == NULL )
goto V_85;
( * V_83 ) [ 0 ] = V_84 ;
if ( ( * V_83 ) [ 0 ] != '\0' ) {
( * V_83 ) ++ ;
while ( isspace ( ( * V_83 ) [ 0 ] ) )
++ ( * V_83 ) ;
}
return 0 ;
V_85:
F_2 ( V_22 ) ;
return - 1 ;
}
static struct V_81 * F_54 ( T_3 V_17 , char * line ,
T_1 V_86 , int V_87 )
{
struct V_81 * V_82 = F_17 ( sizeof( * V_82 ) + V_86 ) ;
if ( V_82 != NULL ) {
V_82 -> V_17 = V_17 ;
V_82 -> line = F_9 ( line ) ;
V_82 -> V_87 = V_87 ;
if ( V_82 -> line == NULL )
goto V_88;
if ( V_17 != - 1 ) {
if ( F_18 ( V_82 -> line , & V_82 -> V_5 , & V_82 -> V_2 . V_4 ) < 0 )
goto V_89;
F_53 ( V_82 ) ;
}
}
return V_82 ;
V_89:
F_2 ( & V_82 -> line ) ;
V_88:
free ( V_82 ) ;
return NULL ;
}
void F_55 ( struct V_81 * V_82 )
{
F_2 ( & V_82 -> line ) ;
F_2 ( & V_82 -> V_5 ) ;
if ( V_82 -> V_7 && V_82 -> V_7 -> V_2 -> free )
V_82 -> V_7 -> V_2 -> free ( & V_82 -> V_2 ) ;
else
F_1 ( & V_82 -> V_2 ) ;
free ( V_82 ) ;
}
int F_56 ( struct V_81 * V_82 , char * V_8 , T_1 V_9 , bool V_4 )
{
if ( V_4 || ! V_82 -> V_7 )
return F_4 ( V_8 , V_9 , L_1 , V_82 -> V_5 , V_82 -> V_2 . V_4 ) ;
return F_5 ( V_82 -> V_7 , V_8 , V_9 , & V_82 -> V_2 ) ;
}
static void F_57 ( struct V_90 * V_91 , struct V_81 * line )
{
F_58 ( & line -> V_92 , V_91 ) ;
}
struct V_81 * F_59 ( struct V_90 * V_91 , struct V_81 * V_93 )
{
F_60 (pos, head, node)
if ( V_93 -> V_17 >= 0 )
return V_93 ;
return NULL ;
}
double F_61 ( struct V_42 * V_43 , int V_63 , T_3 V_17 ,
T_3 V_67 , const char * * V_94 , T_2 * V_95 )
{
struct V_96 * V_97 = V_43 -> V_48 -> V_98 ;
double V_99 = 0.0 ;
* V_95 = 0 ;
if ( V_97 ) {
T_1 V_100 = sizeof( * V_97 ) +
sizeof( V_97 -> V_101 ) * ( V_97 -> V_102 - 1 ) ;
while ( V_17 < V_67 ) {
V_97 = ( void * ) V_43 -> V_48 -> V_98 +
( V_100 * V_17 ) ;
if ( * V_94 == NULL )
* V_94 = V_97 -> V_94 ;
V_99 += V_97 -> V_101 [ V_63 ] . V_99 ;
* V_95 += V_97 -> V_101 [ V_63 ] . V_103 ;
V_17 ++ ;
}
} else {
struct V_47 * V_64 = F_45 ( V_43 , V_63 ) ;
unsigned int V_104 = 0 ;
while ( V_17 < V_67 )
V_104 += V_64 -> V_12 [ V_17 ++ ] ;
if ( V_64 -> V_69 ) {
* V_95 = V_104 ;
V_99 = 100.0 * V_104 / V_64 -> V_69 ;
}
}
return V_99 ;
}
static int F_62 ( struct V_81 * V_82 , struct V_40 * V_41 , T_2 V_55 ,
struct V_105 * V_106 , T_2 V_107 , int V_108 , int V_27 ,
int V_109 , struct V_81 * V_110 )
{
static const char * V_111 ;
static const char * V_112 ;
if ( V_82 -> V_17 != - 1 ) {
const char * V_94 = NULL ;
T_2 V_95 ;
double V_99 , V_113 = 0.0 ;
double * V_114 = & V_99 ;
T_2 * V_115 = & V_95 ;
int V_116 , V_117 = 1 ;
const char * V_118 ;
struct V_42 * V_43 = F_32 ( V_41 ) ;
T_3 V_17 = V_82 -> V_17 ;
const T_2 V_12 = V_55 + V_17 ;
struct V_81 * V_119 ;
V_119 = F_59 ( & V_43 -> V_48 -> V_3 , V_82 ) ;
if ( F_63 ( V_106 ) ) {
V_117 = V_106 -> V_120 ;
V_114 = calloc ( V_117 , sizeof( double ) ) ;
V_115 = calloc ( V_117 , sizeof( T_2 ) ) ;
if ( V_114 == NULL || V_115 == NULL ) {
return - 1 ;
}
}
for ( V_116 = 0 ; V_116 < V_117 ; V_116 ++ ) {
V_99 = F_61 ( V_43 ,
V_43 -> V_48 -> V_98 ? V_116 : V_106 -> V_121 + V_116 ,
V_17 ,
V_119 ? V_119 -> V_17 : ( T_3 ) V_107 ,
& V_94 , & V_95 ) ;
V_114 [ V_116 ] = V_99 ;
V_115 [ V_116 ] = V_95 ;
if ( V_99 > V_113 )
V_113 = V_99 ;
}
if ( V_113 < V_108 )
return - 1 ;
if ( V_109 && V_27 >= V_109 )
return 1 ;
if ( V_110 != NULL ) {
F_64 (queue, &notes->src->source, node) {
if ( V_110 == V_82 )
break;
F_62 ( V_110 , V_41 , V_55 , V_106 , V_107 ,
0 , 0 , 1 , NULL ) ;
}
}
V_118 = F_65 ( V_113 ) ;
if ( V_94 ) {
if ( ! V_111 || strcmp ( V_111 , V_94 )
|| V_118 != V_112 ) {
F_66 ( stdout , V_118 , L_23 , V_94 ) ;
V_111 = V_94 ;
V_112 = V_118 ;
}
}
for ( V_116 = 0 ; V_116 < V_117 ; V_116 ++ ) {
V_99 = V_114 [ V_116 ] ;
V_95 = V_115 [ V_116 ] ;
V_118 = F_65 ( V_99 ) ;
if ( V_49 . V_122 )
F_66 ( stdout , V_118 , L_24 V_70 ,
V_95 ) ;
else
F_66 ( stdout , V_118 , L_25 , V_99 ) ;
}
printf ( L_26 ) ;
F_66 ( stdout , V_123 , L_27 V_14 L_28 , V_12 ) ;
F_66 ( stdout , V_124 , L_29 , V_82 -> line ) ;
if ( V_114 != & V_99 )
free ( V_114 ) ;
if ( V_115 != & V_95 )
free ( V_115 ) ;
} else if ( V_109 && V_27 >= V_109 )
return 1 ;
else {
int V_125 = 8 ;
if ( V_110 )
return - 1 ;
if ( F_63 ( V_106 ) )
V_125 *= V_106 -> V_120 ;
if ( ! * V_82 -> line )
printf ( L_30 , V_125 , L_31 ) ;
else
printf ( L_32 , V_125 , L_31 , V_82 -> line ) ;
}
return 0 ;
}
static int F_67 ( struct V_40 * V_41 , struct V_39 * V_39 ,
T_4 * V_126 , T_1 V_86 ,
int * V_87 )
{
struct V_42 * V_43 = F_32 ( V_41 ) ;
struct V_81 * V_82 ;
char * line = NULL , * V_127 , * V_84 , * V_128 , * V_129 ;
T_1 V_130 ;
T_3 V_131 , V_17 = - 1 ;
T_5 V_132 [ 2 ] ;
if ( F_68 ( & line , & V_130 , V_126 ) < 0 )
return - 1 ;
if ( ! line )
return - 1 ;
while ( V_130 != 0 && isspace ( line [ V_130 - 1 ] ) )
line [ -- V_130 ] = '\0' ;
V_129 = strchr ( line , '\n' ) ;
if ( V_129 )
* V_129 = 0 ;
V_131 = - 1 ;
V_127 = line ;
if ( regexec ( & V_133 , line , 2 , V_132 , 0 ) == 0 ) {
* V_87 = atoi ( line + V_132 [ 1 ] . V_134 ) ;
return 0 ;
}
V_84 = line ;
while ( * V_84 ) {
if ( * V_84 != ' ' )
break;
V_84 ++ ;
}
if ( * V_84 ) {
V_131 = F_7 ( V_84 , & V_128 , 16 ) ;
if ( * V_128 != ':' || V_84 == V_128 || V_128 [ 1 ] == '\0' )
V_131 = - 1 ;
}
if ( V_131 != - 1 ) {
T_2 V_55 = F_69 ( V_39 , V_41 -> V_55 ) ,
V_67 = F_69 ( V_39 , V_41 -> V_67 ) ;
V_17 = V_131 - V_55 ;
if ( ( T_2 ) V_131 < V_55 || ( T_2 ) V_131 >= V_67 )
V_17 = - 1 ;
else
V_127 = V_128 + 1 ;
}
V_82 = F_54 ( V_17 , V_127 , V_86 , * V_87 ) ;
free ( line ) ;
( * V_87 ) ++ ;
if ( V_82 == NULL )
return - 1 ;
if ( V_82 -> V_2 . V_6 . V_17 == V_18 )
V_82 -> V_2 . V_6 . V_17 = V_82 -> V_2 . V_6 . V_12 -
F_69 ( V_39 , V_41 -> V_55 ) ;
if ( V_82 -> V_7 && F_11 ( V_82 -> V_7 ) && ! V_82 -> V_2 . V_6 . V_5 ) {
struct V_72 V_6 = {
. V_39 = V_39 ,
. V_12 = V_82 -> V_2 . V_6 . V_12 ,
} ;
if ( ! F_70 ( & V_6 , NULL ) &&
V_6 . V_41 -> V_55 == V_6 . V_76 )
V_82 -> V_2 . V_6 . V_5 = F_9 ( V_6 . V_41 -> V_5 ) ;
}
F_57 ( & V_43 -> V_48 -> V_3 , V_82 ) ;
return 0 ;
}
int F_71 ( struct V_40 * V_41 , struct V_39 * V_39 , T_1 V_86 )
{
struct V_135 * V_135 = V_39 -> V_135 ;
char * V_136 = F_72 ( V_135 , NULL , 0 ) ;
bool V_137 = true ;
char V_138 [ V_139 * 2 ] ;
T_4 * V_126 ;
int V_75 = 0 ;
char V_140 [ V_139 ] ;
struct V_141 V_142 ;
bool V_143 = false ;
int V_144 = 0 ;
int V_145 ;
if ( V_136 )
F_73 ( V_140 , V_136 ) ;
if ( V_136 == NULL ) {
if ( V_135 -> V_146 ) {
F_74 ( L_33 ,
V_41 -> V_5 ) ;
return - V_71 ;
}
goto V_147;
} else if ( F_75 ( V_135 ) ) {
goto V_147;
} else if ( F_76 ( V_140 , V_138 , sizeof( V_138 ) ) < 0 ||
strstr ( V_138 , V_148 ) ||
F_77 ( V_140 , V_149 ) ) {
free ( V_136 ) ;
V_147:
V_136 = ( char * ) V_135 -> V_150 ;
F_73 ( V_140 , V_136 ) ;
V_137 = false ;
}
if ( V_135 -> V_151 == V_152 &&
! F_75 ( V_135 ) ) {
char V_8 [ V_153 + 15 ] = L_34 ;
char * V_154 = NULL ;
if ( V_135 -> V_155 )
goto V_156;
if ( V_135 -> V_146 ) {
F_78 ( V_135 -> V_157 ,
sizeof( V_135 -> V_157 ) , V_8 + 15 ) ;
V_154 = V_8 ;
}
V_75 = - V_158 ;
V_135 -> V_155 = 1 ;
F_74 ( L_35
L_36
L_37
L_38
L_39
L_40
L_41 ,
V_41 -> V_5 , V_154 ? : L_42 ) ;
goto V_156;
}
F_44 ( L_43 V_14 L_13 V_14 L_10 , V_65 ,
V_136 , V_41 -> V_5 , V_39 -> V_66 ( V_39 , V_41 -> V_55 ) ,
V_39 -> V_66 ( V_39 , V_41 -> V_67 ) ) ;
F_44 ( L_44 ,
V_135 , V_135 -> V_150 , V_41 , V_41 -> V_5 ) ;
if ( F_75 ( V_135 ) ) {
V_142 . V_159 = V_140 ;
V_142 . V_12 = F_69 ( V_39 , V_41 -> V_55 ) ;
V_142 . V_160 = V_41 -> V_55 ;
V_142 . V_107 = V_41 -> V_67 - V_41 -> V_55 ;
if ( ! F_79 ( & V_142 ) ) {
V_143 = true ;
F_80 ( V_140 , V_142 . V_161 ,
sizeof( V_140 ) ) ;
if ( V_137 ) {
free ( V_136 ) ;
V_137 = false ;
}
V_136 = V_140 ;
}
} else if ( F_81 ( V_135 ) ) {
char V_84 [ V_139 ] ;
struct V_162 V_163 ;
int V_164 ;
bool V_165 ;
if ( F_82 ( & V_163 , V_140 ) )
goto V_156;
snprintf ( V_84 , V_139 , L_45 ) ;
V_164 = F_83 ( V_84 ) ;
if ( V_164 < 0 ) {
free ( V_163 . V_166 ) ;
goto V_156;
}
V_165 = F_84 ( V_163 . V_166 , V_140 , V_164 ) ;
if ( V_165 )
F_74 ( L_46 , V_163 . V_166 , V_140 ) ;
free ( V_163 . V_166 ) ;
F_85 ( V_164 ) ;
if ( ! V_165 )
goto V_156;
strcpy ( V_140 , V_84 ) ;
}
snprintf ( V_138 , sizeof( V_138 ) ,
L_47 V_14
L_48 V_14
L_49 ,
V_167 ? V_167 : L_50 ,
V_168 ? L_51 : L_42 ,
V_168 ? V_168 : L_42 ,
F_69 ( V_39 , V_41 -> V_55 ) ,
F_69 ( V_39 , V_41 -> V_67 ) ,
V_49 . V_169 ? L_42 : L_52 ,
V_49 . V_170 ? L_53 : L_42 ,
V_140 , V_136 ) ;
F_44 ( L_54 , V_138 ) ;
V_126 = F_86 ( V_138 , L_55 ) ;
if ( ! V_126 ) {
F_74 ( L_56 , V_138 ) ;
goto V_171;
}
V_145 = 0 ;
while ( ! feof ( V_126 ) ) {
if ( F_67 ( V_41 , V_39 , V_126 , V_86 ,
& V_144 ) < 0 )
break;
V_145 ++ ;
}
if ( V_145 == 0 )
F_74 ( L_57 , V_138 ) ;
if ( F_75 ( V_135 ) )
F_87 ( V_41 ) ;
F_88 ( V_126 ) ;
V_171:
if ( F_81 ( V_135 ) )
F_89 ( V_140 ) ;
V_156:
if ( V_143 )
F_90 ( & V_142 ) ;
if ( V_137 )
free ( V_136 ) ;
return V_75 ;
}
static void F_91 ( struct V_172 * V_173 , struct V_96 * V_97 )
{
struct V_96 * V_174 ;
struct V_175 * * V_176 = & V_173 -> V_175 ;
struct V_175 * V_177 = NULL ;
int V_116 , V_165 ;
while ( * V_176 != NULL ) {
V_177 = * V_176 ;
V_174 = F_92 ( V_177 , struct V_96 , V_92 ) ;
V_165 = strcmp ( V_174 -> V_94 , V_97 -> V_94 ) ;
if ( V_165 == 0 ) {
for ( V_116 = 0 ; V_116 < V_97 -> V_102 ; V_116 ++ )
V_174 -> V_101 [ V_116 ] . V_178 += V_97 -> V_101 [ V_116 ] . V_99 ;
return;
}
if ( V_165 < 0 )
V_176 = & ( * V_176 ) -> V_179 ;
else
V_176 = & ( * V_176 ) -> V_180 ;
}
for ( V_116 = 0 ; V_116 < V_97 -> V_102 ; V_116 ++ )
V_97 -> V_101 [ V_116 ] . V_178 = V_97 -> V_101 [ V_116 ] . V_99 ;
F_93 ( & V_97 -> V_92 , V_177 , V_176 ) ;
F_94 ( & V_97 -> V_92 , V_173 ) ;
}
static int F_95 ( struct V_96 * V_32 , struct V_96 * V_33 )
{
int V_116 ;
for ( V_116 = 0 ; V_116 < V_32 -> V_102 ; V_116 ++ ) {
if ( V_32 -> V_101 [ V_116 ] . V_178 == V_33 -> V_101 [ V_116 ] . V_178 )
continue;
return V_32 -> V_101 [ V_116 ] . V_178 > V_33 -> V_101 [ V_116 ] . V_178 ;
}
return 0 ;
}
static void F_96 ( struct V_172 * V_173 , struct V_96 * V_97 )
{
struct V_96 * V_174 ;
struct V_175 * * V_176 = & V_173 -> V_175 ;
struct V_175 * V_177 = NULL ;
while ( * V_176 != NULL ) {
V_177 = * V_176 ;
V_174 = F_92 ( V_177 , struct V_96 , V_92 ) ;
if ( F_95 ( V_97 , V_174 ) )
V_176 = & ( * V_176 ) -> V_179 ;
else
V_176 = & ( * V_176 ) -> V_180 ;
}
F_93 ( & V_97 -> V_92 , V_177 , V_176 ) ;
F_94 ( & V_97 -> V_92 , V_173 ) ;
}
static void F_97 ( struct V_172 * V_181 , struct V_172 * V_182 )
{
struct V_96 * V_97 ;
struct V_175 * V_92 ;
V_92 = F_98 ( V_182 ) ;
while ( V_92 ) {
struct V_175 * V_119 ;
V_97 = F_92 ( V_92 , struct V_96 , V_92 ) ;
V_119 = F_99 ( V_92 ) ;
F_100 ( V_92 , V_182 ) ;
F_96 ( V_181 , V_97 ) ;
V_92 = V_119 ;
}
}
static void F_101 ( struct V_40 * V_41 , int V_107 )
{
struct V_42 * V_43 = F_32 ( V_41 ) ;
struct V_96 * V_97 = V_43 -> V_48 -> V_98 ;
T_1 V_100 ;
int V_116 ;
V_100 = sizeof( * V_97 ) +
( sizeof( V_97 -> V_101 ) * ( V_97 -> V_102 - 1 ) ) ;
for ( V_116 = 0 ; V_116 < V_107 ; V_116 ++ ) {
F_102 ( V_97 -> V_94 ) ;
V_97 = ( void * ) V_97 + V_100 ;
}
F_2 ( & V_43 -> V_48 -> V_98 ) ;
}
static int F_103 ( struct V_40 * V_41 , struct V_39 * V_39 ,
struct V_105 * V_106 ,
struct V_172 * V_173 , int V_107 )
{
T_2 V_55 ;
int V_116 , V_183 ;
int V_63 = V_106 -> V_121 ;
struct V_96 * V_97 ;
struct V_42 * V_43 = F_32 ( V_41 ) ;
struct V_47 * V_64 = F_45 ( V_43 , V_63 ) ;
struct V_172 V_184 = V_185 ;
int V_102 = 1 ;
T_2 V_186 = V_64 -> V_69 ;
T_1 V_100 = sizeof( struct V_96 ) ;
if ( F_63 ( V_106 ) ) {
for ( V_116 = 1 ; V_116 < V_106 -> V_120 ; V_116 ++ ) {
V_64 = F_45 ( V_43 , V_63 + V_116 ) ;
V_186 += V_64 -> V_69 ;
}
V_102 = V_106 -> V_120 ;
V_100 += ( V_102 - 1 ) * sizeof( V_97 -> V_101 ) ;
}
if ( ! V_186 )
return 0 ;
V_97 = V_43 -> V_48 -> V_98 = calloc ( V_107 , V_100 ) ;
if ( ! V_43 -> V_48 -> V_98 )
return - 1 ;
V_55 = F_69 ( V_39 , V_41 -> V_55 ) ;
for ( V_116 = 0 ; V_116 < V_107 ; V_116 ++ ) {
T_2 V_17 ;
double V_187 = 0.0 ;
V_97 -> V_102 = V_102 ;
for ( V_183 = 0 ; V_183 < V_102 ; V_183 ++ ) {
V_64 = F_45 ( V_43 , V_63 + V_183 ) ;
V_97 -> V_101 [ V_183 ] . V_99 = 100.0 * V_64 -> V_12 [ V_116 ] / V_64 -> V_69 ;
if ( V_97 -> V_101 [ V_183 ] . V_99 > V_187 )
V_187 = V_97 -> V_101 [ V_183 ] . V_99 ;
}
if ( V_187 <= 0.5 )
goto V_119;
V_17 = V_55 + V_116 ;
V_97 -> V_94 = F_104 ( V_39 -> V_135 , V_17 , NULL , false ) ;
F_91 ( & V_184 , V_97 ) ;
V_119:
V_97 = ( void * ) V_97 + V_100 ;
}
F_97 ( V_173 , & V_184 ) ;
return 0 ;
}
static void F_105 ( struct V_172 * V_173 , const char * V_136 )
{
struct V_96 * V_97 ;
struct V_175 * V_92 ;
printf ( L_58 , V_136 ) ;
printf ( L_59 ) ;
if ( F_106 ( V_173 ) ) {
printf ( L_60 , V_188 ) ;
return;
}
V_92 = F_98 ( V_173 ) ;
while ( V_92 ) {
double V_99 , V_187 = 0.0 ;
const char * V_118 ;
char * V_94 ;
int V_116 ;
V_97 = F_92 ( V_92 , struct V_96 , V_92 ) ;
for ( V_116 = 0 ; V_116 < V_97 -> V_102 ; V_116 ++ ) {
V_99 = V_97 -> V_101 [ V_116 ] . V_178 ;
V_118 = F_65 ( V_99 ) ;
F_66 ( stdout , V_118 , L_25 , V_99 ) ;
if ( V_99 > V_187 )
V_187 = V_99 ;
}
V_94 = V_97 -> V_94 ;
V_118 = F_65 ( V_187 ) ;
F_66 ( stdout , V_118 , L_61 , V_94 ) ;
V_92 = F_99 ( V_92 ) ;
}
}
static void F_107 ( struct V_40 * V_41 , struct V_105 * V_106 )
{
struct V_42 * V_43 = F_32 ( V_41 ) ;
struct V_47 * V_64 = F_45 ( V_43 , V_106 -> V_121 ) ;
T_2 V_107 = F_35 ( V_41 ) , V_17 ;
for ( V_17 = 0 ; V_17 < V_107 ; ++ V_17 )
if ( V_64 -> V_12 [ V_17 ] != 0 )
printf ( L_62 V_14 L_63 V_70 L_10 , V_189 / 2 ,
V_41 -> V_55 + V_17 , V_64 -> V_12 [ V_17 ] ) ;
printf ( L_64 V_70 L_10 , V_189 / 2 , L_65 , V_64 -> V_69 ) ;
}
int F_108 ( struct V_40 * V_41 , struct V_39 * V_39 ,
struct V_105 * V_106 , bool V_190 ,
int V_108 , int V_109 , int V_191 )
{
struct V_135 * V_135 = V_39 -> V_135 ;
char * V_136 ;
const char * V_192 ;
const char * V_193 = F_109 ( V_106 ) ;
struct V_42 * V_43 = F_32 ( V_41 ) ;
struct V_81 * V_93 , * V_110 = NULL ;
T_2 V_55 = F_69 ( V_39 , V_41 -> V_55 ) ;
int V_27 = 2 , V_194 = 0 ;
int V_195 = 0 ;
T_2 V_107 ;
int V_125 = 8 ;
int V_196 , V_197 , V_198 ;
V_136 = F_9 ( V_135 -> V_150 ) ;
if ( ! V_136 )
return - V_71 ;
if ( V_190 )
V_192 = V_136 ;
else
V_192 = F_110 ( V_136 ) ;
V_107 = F_35 ( V_41 ) ;
V_196 = strlen ( V_192 ) ;
V_197 = strlen ( V_193 ) ;
if ( F_63 ( V_106 ) )
V_125 *= V_106 -> V_120 ;
printf ( L_66 ,
V_125 , V_125 , L_67 , V_192 , V_193 ) ;
V_198 = V_125 + V_196 + V_197 ;
printf ( L_68 ,
V_198 , V_198 , V_199 ) ;
if ( V_200 )
F_107 ( V_41 , V_106 ) ;
F_111 (pos, &notes->src->source, node) {
if ( V_191 && V_110 == NULL ) {
V_110 = V_93 ;
V_194 = 0 ;
}
switch ( F_62 ( V_93 , V_41 , V_55 , V_106 , V_107 ,
V_108 , V_27 , V_109 ,
V_110 ) ) {
case 0 :
++ V_27 ;
if ( V_191 ) {
V_27 += V_194 ;
V_110 = NULL ;
V_194 = 0 ;
}
break;
case 1 :
++ V_195 ;
break;
case - 1 :
default:
if ( ! V_191 )
break;
if ( V_194 == V_191 )
V_110 = F_112 ( V_110 -> V_92 . V_119 , F_113 ( * V_110 ) , V_92 ) ;
else
++ V_194 ;
break;
}
}
free ( V_136 ) ;
return V_195 ;
}
void F_114 ( struct V_40 * V_41 , int V_63 )
{
struct V_42 * V_43 = F_32 ( V_41 ) ;
struct V_47 * V_64 = F_45 ( V_43 , V_63 ) ;
memset ( V_64 , 0 , V_43 -> V_48 -> V_45 ) ;
}
void F_115 ( struct V_40 * V_41 , int V_63 )
{
struct V_42 * V_43 = F_32 ( V_41 ) ;
struct V_47 * V_64 = F_45 ( V_43 , V_63 ) ;
int V_107 = F_35 ( V_41 ) , V_17 ;
V_64 -> V_69 = 0 ;
for ( V_17 = 0 ; V_17 < V_107 ; ++ V_17 ) {
V_64 -> V_12 [ V_17 ] = V_64 -> V_12 [ V_17 ] * 7 / 8 ;
V_64 -> V_69 += V_64 -> V_12 [ V_17 ] ;
}
}
void F_116 ( struct V_90 * V_91 )
{
struct V_81 * V_93 , * V_201 ;
F_117 (pos, n, head, node) {
F_118 ( & V_93 -> V_92 ) ;
F_55 ( V_93 ) ;
}
}
static T_1 F_119 ( struct V_81 * V_82 , T_4 * V_202 )
{
T_1 V_27 ;
if ( V_82 -> V_17 == - 1 )
return fprintf ( V_202 , L_29 , V_82 -> line ) ;
V_27 = fprintf ( V_202 , L_14 V_14 L_23 , V_82 -> V_17 , V_82 -> V_5 ) ;
if ( V_82 -> V_2 . V_4 [ 0 ] != '\0' ) {
V_27 += fprintf ( V_202 , L_69 , 6 - ( int ) V_27 , L_31 ,
V_82 -> V_2 . V_4 ) ;
}
return V_27 + fprintf ( V_202 , L_10 ) ;
}
T_1 F_120 ( struct V_90 * V_91 , T_4 * V_202 )
{
struct V_81 * V_93 ;
T_1 V_27 = 0 ;
F_111 (pos, head, node)
V_27 += F_119 ( V_93 , V_202 ) ;
return V_27 ;
}
int F_121 ( struct V_40 * V_41 , struct V_39 * V_39 ,
struct V_105 * V_106 , bool V_203 ,
bool V_190 , int V_108 , int V_109 )
{
struct V_135 * V_135 = V_39 -> V_135 ;
struct V_172 V_96 = V_185 ;
T_2 V_107 ;
if ( F_71 ( V_41 , V_39 , 0 ) < 0 )
return - 1 ;
V_107 = F_35 ( V_41 ) ;
if ( V_203 ) {
V_204 = V_190 ;
F_103 ( V_41 , V_39 , V_106 , & V_96 , V_107 ) ;
F_105 ( & V_96 , V_135 -> V_150 ) ;
}
F_108 ( V_41 , V_39 , V_106 , V_190 ,
V_108 , V_109 , 0 ) ;
if ( V_203 )
F_101 ( V_41 , V_107 ) ;
F_116 ( & F_32 ( V_41 ) -> V_48 -> V_3 ) ;
return 0 ;
}
int F_122 ( struct V_77 * V_78 , T_1 V_86 )
{
return F_71 ( V_78 -> V_80 . V_41 , V_78 -> V_80 . V_39 , V_86 ) ;
}
bool F_123 ( void )
{
return V_205 == 1 && V_206 . V_41 ;
}
