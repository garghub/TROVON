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
static int F_6 ( struct V_1 * V_2 , struct V_10 * V_10 )
{
char * V_11 , * V_12 , * V_5 ;
V_2 -> V_6 . V_13 = F_7 ( V_2 -> V_4 , & V_11 , 16 ) ;
V_5 = strchr ( V_11 , '<' ) ;
if ( V_5 == NULL )
goto V_14;
V_5 ++ ;
#ifdef F_8
if ( strchr ( V_5 , '+' ) )
return - 1 ;
#endif
V_12 = strchr ( V_5 , '>' ) ;
if ( V_12 == NULL )
return - 1 ;
* V_12 = '\0' ;
V_2 -> V_6 . V_5 = F_9 ( V_5 ) ;
* V_12 = '>' ;
return V_2 -> V_6 . V_5 == NULL ? - 1 : 0 ;
V_14:
V_12 = strchr ( V_11 , '*' ) ;
if ( V_12 == NULL ) {
struct V_15 * V_16 = F_10 ( V_10 , V_10 -> V_17 ( V_10 , V_2 -> V_6 . V_13 ) ) ;
if ( V_16 != NULL )
V_2 -> V_6 . V_5 = F_9 ( V_16 -> V_5 ) ;
else
V_2 -> V_6 . V_13 = 0 ;
return 0 ;
}
V_2 -> V_6 . V_13 = F_7 ( V_12 + 1 , NULL , 16 ) ;
return 0 ;
}
static int F_11 ( struct V_7 * V_7 , char * V_8 , T_1 V_9 ,
struct V_1 * V_2 )
{
if ( V_2 -> V_6 . V_5 )
return F_4 ( V_8 , V_9 , L_1 , V_7 -> V_5 , V_2 -> V_6 . V_5 ) ;
if ( V_2 -> V_6 . V_13 == 0 )
return F_3 ( V_7 , V_8 , V_9 , V_2 ) ;
return F_4 ( V_8 , V_9 , L_2 V_18 , V_7 -> V_5 , V_2 -> V_6 . V_13 ) ;
}
bool F_12 ( const struct V_7 * V_7 )
{
return V_7 -> V_2 == & V_19 ;
}
static int F_13 ( struct V_1 * V_2 , struct V_10 * V_10 V_20 )
{
const char * V_21 = strchr ( V_2 -> V_4 , '+' ) ;
V_2 -> V_6 . V_13 = F_7 ( V_2 -> V_4 , NULL , 16 ) ;
if ( V_21 ++ != NULL )
V_2 -> V_6 . V_22 = F_7 ( V_21 , NULL , 16 ) ;
else
V_2 -> V_6 . V_22 = V_23 ;
return 0 ;
}
static int F_14 ( struct V_7 * V_7 , char * V_8 , T_1 V_9 ,
struct V_1 * V_2 )
{
return F_4 ( V_8 , V_9 , L_3 V_18 , V_7 -> V_5 , V_2 -> V_6 . V_22 ) ;
}
bool F_15 ( const struct V_7 * V_7 )
{
return V_7 -> V_2 == & V_24 ;
}
static int F_16 ( char * V_4 , char * V_25 , T_2 * V_26 , char * * V_27 )
{
char * V_11 , * V_5 , * V_28 ;
if ( strstr ( V_4 , L_4 ) == NULL )
return 0 ;
* V_26 = F_7 ( V_25 , & V_11 , 16 ) ;
V_5 = strchr ( V_11 , '<' ) ;
if ( V_5 == NULL )
return - 1 ;
V_5 ++ ;
V_28 = strchr ( V_5 , '>' ) ;
if ( V_28 == NULL )
return 0 ;
* V_28 = '\0' ;
* V_27 = F_9 ( V_5 ) ;
* V_28 = '>' ;
return 0 ;
}
static int F_17 ( struct V_1 * V_2 , struct V_10 * V_10 )
{
char * V_5 ;
V_2 -> V_29 . V_2 = F_18 ( sizeof( * V_2 -> V_29 . V_2 ) ) ;
if ( V_2 -> V_29 . V_2 == NULL )
return 0 ;
if ( F_19 ( V_2 -> V_4 , & V_5 , & V_2 -> V_29 . V_2 -> V_4 ) < 0 )
goto V_30;
V_2 -> V_29 . V_7 = F_20 ( V_5 ) ;
free ( V_5 ) ;
if ( V_2 -> V_29 . V_7 == NULL )
goto V_30;
if ( ! V_2 -> V_29 . V_7 -> V_2 )
return 0 ;
if ( V_2 -> V_29 . V_7 -> V_2 -> V_31 &&
V_2 -> V_29 . V_7 -> V_2 -> V_31 ( V_2 -> V_29 . V_2 , V_10 ) < 0 )
goto V_30;
return 0 ;
V_30:
F_2 ( & V_2 -> V_29 . V_2 ) ;
return 0 ;
}
static int F_21 ( struct V_7 * V_7 , char * V_8 , T_1 V_9 ,
struct V_1 * V_2 )
{
int V_32 ;
if ( V_2 -> V_29 . V_7 == NULL )
return F_3 ( V_7 , V_8 , V_9 , V_2 ) ;
V_32 = F_4 ( V_8 , V_9 , L_5 , V_7 -> V_5 ) ;
return V_32 + F_5 ( V_2 -> V_29 . V_7 , V_8 + V_32 ,
V_9 - V_32 , V_2 -> V_29 . V_2 ) ;
}
static void F_22 ( struct V_1 * V_2 )
{
struct V_7 * V_7 = V_2 -> V_29 . V_7 ;
if ( V_7 && V_7 -> V_2 -> free )
V_7 -> V_2 -> free ( V_2 -> V_29 . V_2 ) ;
else
F_1 ( V_2 -> V_29 . V_2 ) ;
F_2 ( & V_2 -> V_29 . V_2 ) ;
F_2 ( & V_2 -> V_6 . V_4 ) ;
F_2 ( & V_2 -> V_6 . V_5 ) ;
}
static int F_23 ( struct V_1 * V_2 , struct V_10 * V_10 V_20 )
{
char * V_21 = strchr ( V_2 -> V_4 , ',' ) , * V_6 , * V_25 , V_33 ;
if ( V_21 == NULL )
return - 1 ;
* V_21 = '\0' ;
V_2 -> V_3 . V_4 = F_9 ( V_2 -> V_4 ) ;
* V_21 = ',' ;
if ( V_2 -> V_3 . V_4 == NULL )
return - 1 ;
V_6 = ++ V_21 ;
#ifdef F_8
V_25 = strchr ( V_21 , ';' ) ;
#else
V_25 = strchr ( V_21 , '#' ) ;
#endif
if ( V_25 != NULL )
V_21 = V_25 - 1 ;
else
V_21 = strchr ( V_21 , '\0' ) - 1 ;
while ( V_21 > V_6 && isspace ( V_21 [ 0 ] ) )
-- V_21 ;
V_21 ++ ;
V_33 = * V_21 ;
* V_21 = '\0' ;
V_2 -> V_6 . V_4 = F_9 ( V_6 ) ;
* V_21 = V_33 ;
if ( V_2 -> V_6 . V_4 == NULL )
goto V_34;
if ( V_25 == NULL )
return 0 ;
while ( V_25 [ 0 ] != '\0' && isspace ( V_25 [ 0 ] ) )
++ V_25 ;
F_16 ( V_2 -> V_3 . V_4 , V_25 , & V_2 -> V_3 . V_13 , & V_2 -> V_3 . V_5 ) ;
F_16 ( V_2 -> V_6 . V_4 , V_25 , & V_2 -> V_6 . V_13 , & V_2 -> V_6 . V_5 ) ;
return 0 ;
V_34:
F_2 ( & V_2 -> V_3 . V_4 ) ;
return - 1 ;
}
static int F_24 ( struct V_7 * V_7 , char * V_8 , T_1 V_9 ,
struct V_1 * V_2 )
{
return F_4 ( V_8 , V_9 , L_6 , V_7 -> V_5 ,
V_2 -> V_3 . V_5 ? : V_2 -> V_3 . V_4 ,
V_2 -> V_6 . V_5 ? : V_2 -> V_6 . V_4 ) ;
}
static int F_25 ( struct V_1 * V_2 , struct V_10 * V_10 V_20 )
{
char * V_6 , * V_25 , * V_21 , V_33 ;
V_6 = V_21 = V_2 -> V_4 ;
while ( V_21 [ 0 ] != '\0' && ! isspace ( V_21 [ 0 ] ) )
++ V_21 ;
V_33 = * V_21 ;
* V_21 = '\0' ;
V_2 -> V_6 . V_4 = F_9 ( V_6 ) ;
* V_21 = V_33 ;
if ( V_2 -> V_6 . V_4 == NULL )
return - 1 ;
V_25 = strchr ( V_21 , '#' ) ;
if ( V_25 == NULL )
return 0 ;
while ( V_25 [ 0 ] != '\0' && isspace ( V_25 [ 0 ] ) )
++ V_25 ;
F_16 ( V_2 -> V_6 . V_4 , V_25 , & V_2 -> V_6 . V_13 , & V_2 -> V_6 . V_5 ) ;
return 0 ;
}
static int F_26 ( struct V_7 * V_7 , char * V_8 , T_1 V_9 ,
struct V_1 * V_2 )
{
return F_4 ( V_8 , V_9 , L_1 , V_7 -> V_5 ,
V_2 -> V_6 . V_5 ? : V_2 -> V_6 . V_4 ) ;
}
static int F_27 ( struct V_7 * V_7 V_20 , char * V_8 , T_1 V_9 ,
struct V_1 * V_2 V_20 )
{
return F_4 ( V_8 , V_9 , L_7 , L_8 ) ;
}
bool F_28 ( const struct V_7 * V_7 )
{
return V_7 -> V_2 == & V_35 ;
}
static int F_29 ( const void * V_5 , const void * V_36 )
{
const struct V_7 * V_7 = V_36 ;
return strcmp ( V_5 , V_7 -> V_5 ) ;
}
static int F_30 ( const void * V_37 , const void * V_38 )
{
const struct V_7 * V_39 = V_37 ;
const struct V_7 * V_40 = V_38 ;
return strcmp ( V_39 -> V_5 , V_40 -> V_5 ) ;
}
static void F_31 ( void )
{
const int V_41 = F_32 ( V_42 ) ;
qsort ( V_42 , V_41 , sizeof( struct V_7 ) , F_30 ) ;
}
static struct V_7 * F_20 ( const char * V_5 )
{
const int V_41 = F_32 ( V_42 ) ;
static bool V_43 ;
if ( ! V_43 ) {
F_31 () ;
V_43 = true ;
}
return bsearch ( V_5 , V_42 , V_41 , sizeof( struct V_7 ) , F_29 ) ;
}
int F_33 ( struct V_15 * V_16 )
{
struct V_44 * V_45 = F_34 ( V_16 ) ;
const T_1 V_9 = F_35 ( V_16 ) ;
T_1 V_46 ;
if ( V_9 > ( V_47 - sizeof( struct V_48 ) ) / sizeof( T_2 ) )
return - 1 ;
V_46 = ( sizeof( struct V_48 ) + V_9 * sizeof( T_2 ) ) ;
if ( V_46 > ( V_47 - sizeof( * V_45 -> V_49 ) )
/ V_50 . V_51 )
return - 1 ;
V_45 -> V_49 = F_18 ( sizeof( * V_45 -> V_49 ) + V_50 . V_51 * V_46 ) ;
if ( V_45 -> V_49 == NULL )
return - 1 ;
V_45 -> V_49 -> V_46 = V_46 ;
V_45 -> V_49 -> V_52 = V_50 . V_51 ;
F_36 ( & V_45 -> V_49 -> V_3 ) ;
return 0 ;
}
static int F_37 ( struct V_15 * V_16 )
{
struct V_44 * V_45 = F_34 ( V_16 ) ;
const T_1 V_9 = F_35 ( V_16 ) ;
V_45 -> V_49 -> V_53 = calloc ( V_9 , sizeof( struct V_54 ) ) ;
if ( V_45 -> V_49 -> V_53 == NULL )
return - 1 ;
return 0 ;
}
void F_38 ( struct V_15 * V_16 )
{
struct V_44 * V_45 = F_34 ( V_16 ) ;
F_39 ( & V_45 -> V_55 ) ;
if ( V_45 -> V_49 != NULL ) {
memset ( V_45 -> V_49 -> V_56 , 0 ,
V_45 -> V_49 -> V_52 * V_45 -> V_49 -> V_46 ) ;
if ( V_45 -> V_49 -> V_53 )
memset ( V_45 -> V_49 -> V_53 , 0 ,
F_35 ( V_16 ) * sizeof( struct V_54 ) ) ;
}
F_40 ( & V_45 -> V_55 ) ;
}
static int F_41 ( struct V_44 * V_45 ,
T_2 V_57 ,
unsigned V_22 , unsigned V_58 ,
unsigned V_59 )
{
struct V_54 * V_60 ;
V_60 = V_45 -> V_49 -> V_53 ;
V_60 [ V_22 ] . V_61 ++ ;
V_60 [ V_22 ] . V_62 += V_58 ;
if ( ! V_59 && V_60 [ V_22 ] . V_59 )
return 0 ;
if ( V_60 [ V_22 ] . V_63 ) {
if ( V_59 && ( ! V_60 [ V_22 ] . V_59 ||
V_60 [ V_22 ] . V_57 > V_57 ) ) {
V_60 [ V_22 ] . V_59 = 0 ;
V_60 [ V_22 ] . V_58 = 0 ;
V_60 [ V_22 ] . V_63 = 0 ;
if ( V_60 [ V_22 ] . V_64 < 0xffff )
V_60 [ V_22 ] . V_64 ++ ;
} else if ( V_59 &&
V_60 [ V_22 ] . V_57 < V_57 )
return 0 ;
}
V_60 [ V_22 ] . V_59 = V_59 ;
V_60 [ V_22 ] . V_57 = V_57 ;
V_60 [ V_22 ] . V_58 += V_58 ;
V_60 [ V_22 ] . V_63 ++ ;
return 0 ;
}
static int F_42 ( struct V_15 * V_16 , struct V_10 * V_10 ,
struct V_44 * V_45 , int V_65 , T_2 V_13 )
{
unsigned V_22 ;
struct V_48 * V_66 ;
F_43 ( L_9 V_18 L_10 , V_67 , V_10 -> V_68 ( V_10 , V_13 ) ) ;
if ( V_13 < V_16 -> V_57 || V_13 >= V_16 -> V_69 ) {
F_44 ( L_11 V_18 L_12 V_18 L_13 V_18 L_10 ,
V_67 , __LINE__ , V_16 -> V_5 , V_16 -> V_57 , V_13 , V_16 -> V_69 ) ;
return - V_70 ;
}
V_22 = V_13 - V_16 -> V_57 ;
V_66 = F_45 ( V_45 , V_65 ) ;
V_66 -> V_71 ++ ;
V_66 -> V_13 [ V_22 ] ++ ;
F_43 ( L_14 V_18 L_15 V_18 L_16 V_18
L_17 V_72 L_10 , V_16 -> V_57 , V_16 -> V_5 ,
V_13 , V_13 - V_16 -> V_57 , V_65 , V_66 -> V_13 [ V_22 ] ) ;
return 0 ;
}
static struct V_44 * F_46 ( struct V_15 * V_16 , bool V_58 )
{
struct V_44 * V_45 = F_34 ( V_16 ) ;
if ( V_45 -> V_49 == NULL ) {
if ( F_33 ( V_16 ) < 0 )
return NULL ;
}
if ( ! V_45 -> V_49 -> V_53 && V_58 ) {
if ( F_37 ( V_16 ) < 0 )
return NULL ;
}
return V_45 ;
}
static int F_47 ( struct V_15 * V_16 , struct V_10 * V_10 ,
int V_65 , T_2 V_13 )
{
struct V_44 * V_45 ;
if ( V_16 == NULL )
return 0 ;
V_45 = F_46 ( V_16 , false ) ;
if ( V_45 == NULL )
return - V_73 ;
return F_42 ( V_16 , V_10 , V_45 , V_65 , V_13 ) ;
}
static int F_48 ( T_2 V_13 , T_2 V_57 ,
struct V_15 * V_16 , unsigned V_58 )
{
struct V_44 * V_45 ;
unsigned V_22 ;
if ( V_16 == NULL )
return 0 ;
V_45 = F_46 ( V_16 , true ) ;
if ( V_45 == NULL )
return - V_73 ;
if ( V_13 < V_16 -> V_57 || V_13 >= V_16 -> V_69 )
return - V_70 ;
if ( V_57 ) {
if ( V_57 < V_16 -> V_57 || V_57 >= V_16 -> V_69 )
return - V_70 ;
if ( V_57 >= V_13 )
V_57 = 0 ;
}
V_22 = V_13 - V_16 -> V_57 ;
return F_41 ( V_45 ,
V_57 ? V_57 - V_16 -> V_57 : 0 ,
V_22 , V_58 ,
! ! V_57 ) ;
}
int F_49 ( struct V_74 * V_75 ,
struct V_74 * V_57 ,
unsigned V_58 )
{
T_2 V_76 = 0 ;
int V_77 ;
if ( ! V_58 )
return 0 ;
if ( V_57 &&
( V_57 -> V_16 == V_75 -> V_16 ||
( V_75 -> V_16 &&
V_57 -> V_13 == V_75 -> V_16 -> V_57 + V_75 -> V_10 -> V_57 ) ) )
V_76 = V_57 -> V_78 ;
if ( V_76 == 0 )
F_50 ( L_18 V_18 L_19 V_18 L_20 V_18 L_21 V_18 L_10 ,
V_75 -> V_13 ,
V_57 ? V_57 -> V_13 : 0 ,
V_75 -> V_16 ? V_75 -> V_16 -> V_57 + V_75 -> V_10 -> V_57 : 0 ,
V_76 ) ;
V_77 = F_48 ( V_75 -> V_78 , V_76 , V_75 -> V_16 , V_58 ) ;
if ( V_77 )
F_50 ( L_22 , V_77 ) ;
return V_77 ;
}
int F_51 ( struct V_74 * V_75 , int V_65 )
{
return F_47 ( V_75 -> V_16 , V_75 -> V_10 , V_65 , V_75 -> V_78 ) ;
}
int F_52 ( struct V_79 * V_80 , int V_65 , T_2 V_81 )
{
return F_47 ( V_80 -> V_82 . V_16 , V_80 -> V_82 . V_10 , V_65 , V_81 ) ;
}
static void F_53 ( struct V_83 * V_84 , struct V_10 * V_10 )
{
V_84 -> V_7 = F_20 ( V_84 -> V_5 ) ;
if ( V_84 -> V_7 == NULL )
return;
if ( ! V_84 -> V_7 -> V_2 )
return;
if ( V_84 -> V_7 -> V_2 -> V_31 && V_84 -> V_7 -> V_2 -> V_31 ( & V_84 -> V_2 , V_10 ) < 0 )
V_84 -> V_7 = NULL ;
}
static int F_19 ( char * line , char * * V_27 , char * * V_85 )
{
char * V_5 = line , V_86 ;
while ( isspace ( V_5 [ 0 ] ) )
++ V_5 ;
if ( V_5 [ 0 ] == '\0' )
return - 1 ;
* V_85 = V_5 + 1 ;
while ( ( * V_85 ) [ 0 ] != '\0' && ! isspace ( ( * V_85 ) [ 0 ] ) )
++ * V_85 ;
V_86 = ( * V_85 ) [ 0 ] ;
( * V_85 ) [ 0 ] = '\0' ;
* V_27 = F_9 ( V_5 ) ;
if ( * V_27 == NULL )
goto V_87;
( * V_85 ) [ 0 ] = V_86 ;
if ( ( * V_85 ) [ 0 ] != '\0' ) {
( * V_85 ) ++ ;
while ( isspace ( ( * V_85 ) [ 0 ] ) )
++ ( * V_85 ) ;
}
return 0 ;
V_87:
F_2 ( V_27 ) ;
return - 1 ;
}
static struct V_83 * F_54 ( T_3 V_22 , char * line ,
T_1 V_88 , int V_89 ,
struct V_10 * V_10 )
{
struct V_83 * V_84 = F_18 ( sizeof( * V_84 ) + V_88 ) ;
if ( V_84 != NULL ) {
V_84 -> V_22 = V_22 ;
V_84 -> line = F_9 ( line ) ;
V_84 -> V_89 = V_89 ;
if ( V_84 -> line == NULL )
goto V_90;
if ( V_22 != - 1 ) {
if ( F_19 ( V_84 -> line , & V_84 -> V_5 , & V_84 -> V_2 . V_4 ) < 0 )
goto V_91;
F_53 ( V_84 , V_10 ) ;
}
}
return V_84 ;
V_91:
F_2 ( & V_84 -> line ) ;
V_90:
free ( V_84 ) ;
return NULL ;
}
void F_55 ( struct V_83 * V_84 )
{
F_2 ( & V_84 -> line ) ;
F_2 ( & V_84 -> V_5 ) ;
if ( V_84 -> V_7 && V_84 -> V_7 -> V_2 -> free )
V_84 -> V_7 -> V_2 -> free ( & V_84 -> V_2 ) ;
else
F_1 ( & V_84 -> V_2 ) ;
free ( V_84 ) ;
}
int F_56 ( struct V_83 * V_84 , char * V_8 , T_1 V_9 , bool V_4 )
{
if ( V_4 || ! V_84 -> V_7 )
return F_4 ( V_8 , V_9 , L_1 , V_84 -> V_5 , V_84 -> V_2 . V_4 ) ;
return F_5 ( V_84 -> V_7 , V_8 , V_9 , & V_84 -> V_2 ) ;
}
static void F_57 ( struct V_92 * V_93 , struct V_83 * line )
{
F_58 ( & line -> V_94 , V_93 ) ;
}
struct V_83 * F_59 ( struct V_92 * V_93 , struct V_83 * V_95 )
{
F_60 (pos, head, node)
if ( V_95 -> V_22 >= 0 )
return V_95 ;
return NULL ;
}
double F_61 ( struct V_44 * V_45 , int V_65 , T_3 V_22 ,
T_3 V_69 , const char * * V_96 , T_2 * V_97 )
{
struct V_98 * V_99 = V_45 -> V_49 -> V_100 ;
double V_101 = 0.0 ;
* V_97 = 0 ;
if ( V_99 ) {
T_1 V_102 = sizeof( * V_99 ) +
sizeof( V_99 -> V_103 ) * ( V_99 -> V_104 - 1 ) ;
while ( V_22 < V_69 ) {
V_99 = ( void * ) V_45 -> V_49 -> V_100 +
( V_102 * V_22 ) ;
if ( * V_96 == NULL )
* V_96 = V_99 -> V_96 ;
V_101 += V_99 -> V_103 [ V_65 ] . V_101 ;
* V_97 += V_99 -> V_103 [ V_65 ] . V_105 ;
V_22 ++ ;
}
} else {
struct V_48 * V_66 = F_45 ( V_45 , V_65 ) ;
unsigned int V_106 = 0 ;
while ( V_22 < V_69 )
V_106 += V_66 -> V_13 [ V_22 ++ ] ;
if ( V_66 -> V_71 ) {
* V_97 = V_106 ;
V_101 = 100.0 * V_106 / V_66 -> V_71 ;
}
}
return V_101 ;
}
static const char * F_62 ( struct V_107 * V_108 )
{
double V_109 = F_63 ( V_108 ) ;
if ( V_109 >= 0 ) {
if ( V_109 > 0.75 )
return V_110 ;
if ( V_109 < 0.01 )
return V_111 ;
}
return V_112 ;
}
static const char * F_64 ( struct V_107 * V_108 )
{
double V_109 = F_63 ( V_108 ) ;
if ( V_109 >= 0 ) {
if ( V_109 < 0.01 )
return V_111 ;
}
return V_113 ;
}
static void F_65 ( struct V_107 * V_108 , T_2 V_13 )
{
bool V_114 = true ;
if ( ! V_108 )
return;
#if 1
if ( V_108 -> V_115 && V_108 -> V_57 == V_13 ) {
struct V_107 * V_116 = V_108 ;
double V_117 ;
while ( ! V_116 -> V_118 )
V_116 = F_66 ( V_116 ) ;
V_117 = 100 * ( double ) V_108 -> V_119 / V_116 -> V_120 ;
if ( V_117 > 0.1 ) {
if ( V_114 ) {
V_114 = false ;
printf ( L_23 ) ;
}
printf ( L_24 , V_117 ) ;
}
}
#endif
if ( V_108 -> V_118 && V_108 -> V_69 == V_13 ) {
double V_117 = 100 * ( double ) V_108 -> V_121 / V_108 -> V_120 ;
if ( V_117 > 0.1 ) {
if ( V_114 ) {
V_114 = false ;
printf ( L_23 ) ;
}
printf ( L_25 , V_117 , 100 * ( double ) V_108 -> V_122 / V_108 -> V_121 ) ;
}
}
}
static int F_67 ( struct V_83 * V_84 , struct V_15 * V_16 , T_2 V_57 ,
struct V_123 * V_124 , T_2 V_125 , int V_126 , int V_32 ,
int V_127 , struct V_83 * V_128 )
{
static const char * V_129 ;
static const char * V_130 ;
if ( V_84 -> V_22 != - 1 ) {
const char * V_96 = NULL ;
T_2 V_97 ;
double V_101 , V_131 = 0.0 ;
double * V_132 = & V_101 ;
T_2 * V_133 = & V_97 ;
int V_134 , V_135 = 1 ;
const char * V_136 ;
struct V_44 * V_45 = F_34 ( V_16 ) ;
T_3 V_22 = V_84 -> V_22 ;
const T_2 V_13 = V_57 + V_22 ;
struct V_83 * V_137 ;
struct V_107 * V_108 ;
V_137 = F_59 ( & V_45 -> V_49 -> V_3 , V_84 ) ;
if ( F_68 ( V_124 ) ) {
V_135 = V_124 -> V_138 ;
V_132 = calloc ( V_135 , sizeof( double ) ) ;
V_133 = calloc ( V_135 , sizeof( T_2 ) ) ;
if ( V_132 == NULL || V_133 == NULL ) {
return - 1 ;
}
}
for ( V_134 = 0 ; V_134 < V_135 ; V_134 ++ ) {
V_101 = F_61 ( V_45 ,
V_45 -> V_49 -> V_100 ? V_134 : V_124 -> V_139 + V_134 ,
V_22 ,
V_137 ? V_137 -> V_22 : ( T_3 ) V_125 ,
& V_96 , & V_97 ) ;
V_132 [ V_134 ] = V_101 ;
V_133 [ V_134 ] = V_97 ;
if ( V_101 > V_131 )
V_131 = V_101 ;
}
if ( V_131 < V_126 )
return - 1 ;
if ( V_127 && V_32 >= V_127 )
return 1 ;
if ( V_128 != NULL ) {
F_69 (queue, &notes->src->source, node) {
if ( V_128 == V_84 )
break;
F_67 ( V_128 , V_16 , V_57 , V_124 , V_125 ,
0 , 0 , 1 , NULL ) ;
}
}
V_136 = F_70 ( V_131 ) ;
if ( V_96 ) {
if ( ! V_129 || strcmp ( V_129 , V_96 )
|| V_136 != V_130 ) {
F_71 ( stdout , V_136 , L_26 , V_96 ) ;
V_129 = V_96 ;
V_130 = V_136 ;
}
}
for ( V_134 = 0 ; V_134 < V_135 ; V_134 ++ ) {
V_101 = V_132 [ V_134 ] ;
V_97 = V_133 [ V_134 ] ;
V_136 = F_70 ( V_101 ) ;
if ( V_50 . V_140 )
F_71 ( stdout , V_136 , L_27 V_72 ,
V_97 ) ;
else
F_71 ( stdout , V_136 , L_28 , V_101 ) ;
}
printf ( L_29 ) ;
V_108 = F_72 ( V_13 ) ;
F_71 ( stdout , F_62 ( V_108 ) , L_30 V_18 L_31 , V_13 ) ;
F_71 ( stdout , F_64 ( V_108 ) , L_32 , V_84 -> line ) ;
F_65 ( V_108 , V_13 ) ;
printf ( L_10 ) ;
if ( V_132 != & V_101 )
free ( V_132 ) ;
if ( V_133 != & V_97 )
free ( V_133 ) ;
} else if ( V_127 && V_32 >= V_127 )
return 1 ;
else {
int V_141 = 8 ;
if ( V_128 )
return - 1 ;
if ( F_68 ( V_124 ) )
V_141 *= V_124 -> V_138 ;
if ( ! * V_84 -> line )
printf ( L_33 , V_141 , L_34 ) ;
else
printf ( L_35 , V_141 , L_34 , V_84 -> line ) ;
}
return 0 ;
}
static int F_73 ( struct V_15 * V_16 , struct V_10 * V_10 ,
T_4 * V_142 , T_1 V_88 ,
int * V_89 )
{
struct V_44 * V_45 = F_34 ( V_16 ) ;
struct V_83 * V_84 ;
char * line = NULL , * V_143 , * V_86 , * V_144 , * V_145 ;
T_1 V_146 ;
T_3 V_147 , V_22 = - 1 ;
T_5 V_148 [ 2 ] ;
if ( F_74 ( & line , & V_146 , V_142 ) < 0 )
return - 1 ;
if ( ! line )
return - 1 ;
while ( V_146 != 0 && isspace ( line [ V_146 - 1 ] ) )
line [ -- V_146 ] = '\0' ;
V_145 = strchr ( line , '\n' ) ;
if ( V_145 )
* V_145 = 0 ;
V_147 = - 1 ;
V_143 = line ;
if ( regexec ( & V_149 , line , 2 , V_148 , 0 ) == 0 ) {
* V_89 = atoi ( line + V_148 [ 1 ] . V_150 ) ;
return 0 ;
}
V_86 = line ;
while ( * V_86 ) {
if ( * V_86 != ' ' )
break;
V_86 ++ ;
}
if ( * V_86 ) {
V_147 = F_7 ( V_86 , & V_144 , 16 ) ;
if ( * V_144 != ':' || V_86 == V_144 || V_144 [ 1 ] == '\0' )
V_147 = - 1 ;
}
if ( V_147 != - 1 ) {
T_2 V_57 = F_75 ( V_10 , V_16 -> V_57 ) ,
V_69 = F_75 ( V_10 , V_16 -> V_69 ) ;
V_22 = V_147 - V_57 ;
if ( ( T_2 ) V_147 < V_57 || ( T_2 ) V_147 >= V_69 )
V_22 = - 1 ;
else
V_143 = V_144 + 1 ;
}
V_84 = F_54 ( V_22 , V_143 , V_88 , * V_89 , V_10 ) ;
free ( line ) ;
( * V_89 ) ++ ;
if ( V_84 == NULL )
return - 1 ;
if ( V_84 -> V_2 . V_6 . V_22 == V_23 )
V_84 -> V_2 . V_6 . V_22 = V_84 -> V_2 . V_6 . V_13 -
F_75 ( V_10 , V_16 -> V_57 ) ;
if ( V_84 -> V_7 && F_12 ( V_84 -> V_7 ) && ! V_84 -> V_2 . V_6 . V_5 ) {
struct V_74 V_6 = {
. V_10 = V_10 ,
. V_13 = V_84 -> V_2 . V_6 . V_13 ,
} ;
if ( ! F_76 ( & V_6 ) &&
V_6 . V_16 -> V_57 == V_6 . V_78 )
V_84 -> V_2 . V_6 . V_5 = F_9 ( V_6 . V_16 -> V_5 ) ;
}
F_57 ( & V_45 -> V_49 -> V_3 , V_84 ) ;
return 0 ;
}
int F_77 ( struct V_15 * V_16 V_20 , struct V_10 * V_10 ,
int V_151 , char * V_152 , T_1 V_153 )
{
struct V_154 * V_154 = V_10 -> V_154 ;
F_78 ( V_153 == 0 ) ;
if ( V_151 >= 0 ) {
F_79 ( V_151 , V_152 , V_153 ) ;
return 0 ;
}
switch ( V_151 ) {
case V_155 : {
char V_8 [ V_156 + 15 ] = L_36 ;
char * V_157 = NULL ;
if ( V_154 -> V_158 ) {
F_80 ( V_154 -> V_159 ,
sizeof( V_154 -> V_159 ) , V_8 + 15 ) ;
V_157 = V_8 ;
}
F_4 ( V_152 , V_153 ,
L_37
L_38
L_39
L_40
L_41
L_42 , V_157 ? : L_43 ) ;
}
break;
default:
F_4 ( V_152 , V_153 , L_44 , V_151 ) ;
break;
}
return 0 ;
}
static int F_81 ( struct V_154 * V_154 , char * V_160 , T_1 V_161 )
{
char V_162 [ V_163 ] ;
char * V_164 ;
if ( V_154 -> V_165 == V_166 &&
! F_82 ( V_154 ) )
return V_155 ;
V_164 = F_83 ( V_154 , NULL , 0 ) ;
if ( V_164 ) {
F_84 ( V_160 , V_161 , V_164 ) ;
free ( V_164 ) ;
} else {
if ( V_154 -> V_158 )
return V_73 ;
goto V_167;
}
if ( F_82 ( V_154 ) ||
F_85 ( V_160 , V_162 , sizeof( V_162 ) ) < 0 ||
strstr ( V_162 , V_168 ) ||
F_86 ( V_160 , V_169 ) ) {
V_167:
F_84 ( V_160 , V_161 , V_154 -> V_170 ) ;
}
return 0 ;
}
int F_87 ( struct V_15 * V_16 , struct V_10 * V_10 , T_1 V_88 )
{
struct V_154 * V_154 = V_10 -> V_154 ;
char V_171 [ V_163 * 2 ] ;
T_4 * V_142 ;
char V_172 [ V_163 ] ;
struct V_173 V_174 ;
bool V_175 = false ;
int V_176 [ 2 ] ;
int V_177 = 0 ;
int V_178 ;
T_6 V_179 ;
int V_77 = F_81 ( V_154 , V_172 , sizeof( V_172 ) ) ;
if ( V_77 )
return V_77 ;
F_44 ( L_45 V_18 L_13 V_18 L_10 , V_67 ,
V_172 , V_16 -> V_5 , V_10 -> V_68 ( V_10 , V_16 -> V_57 ) ,
V_10 -> V_68 ( V_10 , V_16 -> V_69 ) ) ;
F_44 ( L_46 ,
V_154 , V_154 -> V_170 , V_16 , V_16 -> V_5 ) ;
if ( F_82 ( V_154 ) ) {
V_174 . V_180 = V_172 ;
V_174 . V_13 = F_75 ( V_10 , V_16 -> V_57 ) ;
V_174 . V_181 = V_16 -> V_57 ;
V_174 . V_125 = V_16 -> V_69 - V_16 -> V_57 ;
if ( ! F_88 ( & V_174 ) ) {
V_175 = true ;
F_89 ( V_172 , V_174 . V_182 ,
sizeof( V_172 ) ) ;
}
} else if ( F_90 ( V_154 ) ) {
char V_86 [ V_163 ] ;
struct V_183 V_184 ;
int V_185 ;
bool V_186 ;
if ( F_91 ( & V_184 , V_172 ) )
goto V_187;
snprintf ( V_86 , V_163 , L_47 ) ;
V_185 = F_92 ( V_86 ) ;
if ( V_185 < 0 ) {
free ( V_184 . V_188 ) ;
goto V_187;
}
V_186 = F_93 ( V_184 . V_188 , V_172 , V_185 ) ;
if ( V_186 )
F_94 ( L_48 , V_184 . V_188 , V_172 ) ;
free ( V_184 . V_188 ) ;
F_95 ( V_185 ) ;
if ( ! V_186 )
goto V_187;
strcpy ( V_172 , V_86 ) ;
}
snprintf ( V_171 , sizeof( V_171 ) ,
L_49 V_18
L_50 V_18
L_51 ,
V_189 ? V_189 : L_52 ,
V_190 ? L_53 : L_43 ,
V_190 ? V_190 : L_43 ,
F_75 ( V_10 , V_16 -> V_57 ) ,
F_75 ( V_10 , V_16 -> V_69 ) ,
V_50 . V_191 ? L_43 : L_54 ,
V_50 . V_192 ? L_55 : L_43 ,
V_172 , V_172 ) ;
F_44 ( L_56 , V_171 ) ;
V_77 = - 1 ;
if ( F_96 ( V_176 ) < 0 ) {
F_94 ( L_57 , V_171 ) ;
goto V_193;
}
V_179 = F_97 () ;
if ( V_179 < 0 ) {
F_94 ( L_58 , V_171 ) ;
goto V_194;
}
if ( V_179 == 0 ) {
F_95 ( V_176 [ 0 ] ) ;
F_98 ( V_176 [ 1 ] , 1 ) ;
F_95 ( V_176 [ 1 ] ) ;
F_99 ( L_59 , L_60 , L_61 , V_171 , NULL ) ;
perror ( V_171 ) ;
exit ( - 1 ) ;
}
F_95 ( V_176 [ 1 ] ) ;
V_142 = fdopen ( V_176 [ 0 ] , L_62 ) ;
if ( ! V_142 ) {
F_94 ( L_63 , V_171 ) ;
goto V_193;
}
V_178 = 0 ;
while ( ! feof ( V_142 ) ) {
if ( F_73 ( V_16 , V_10 , V_142 , V_88 ,
& V_177 ) < 0 )
break;
V_178 ++ ;
}
if ( V_178 == 0 )
F_94 ( L_64 , V_171 ) ;
if ( F_82 ( V_154 ) )
F_100 ( V_16 ) ;
fclose ( V_142 ) ;
V_77 = 0 ;
V_193:
F_95 ( V_176 [ 0 ] ) ;
if ( F_90 ( V_154 ) )
F_101 ( V_172 ) ;
if ( V_175 )
F_102 ( & V_174 ) ;
V_187:
return V_77 ;
V_194:
F_95 ( V_176 [ 1 ] ) ;
goto V_193;
}
static void F_103 ( struct V_195 * V_196 , struct V_98 * V_99 )
{
struct V_98 * V_197 ;
struct V_198 * * V_117 = & V_196 -> V_198 ;
struct V_198 * V_199 = NULL ;
int V_134 , V_186 ;
while ( * V_117 != NULL ) {
V_199 = * V_117 ;
V_197 = F_104 ( V_199 , struct V_98 , V_94 ) ;
V_186 = strcmp ( V_197 -> V_96 , V_99 -> V_96 ) ;
if ( V_186 == 0 ) {
for ( V_134 = 0 ; V_134 < V_99 -> V_104 ; V_134 ++ )
V_197 -> V_103 [ V_134 ] . V_200 += V_99 -> V_103 [ V_134 ] . V_101 ;
return;
}
if ( V_186 < 0 )
V_117 = & ( * V_117 ) -> V_201 ;
else
V_117 = & ( * V_117 ) -> V_202 ;
}
for ( V_134 = 0 ; V_134 < V_99 -> V_104 ; V_134 ++ )
V_99 -> V_103 [ V_134 ] . V_200 = V_99 -> V_103 [ V_134 ] . V_101 ;
F_105 ( & V_99 -> V_94 , V_199 , V_117 ) ;
F_106 ( & V_99 -> V_94 , V_196 ) ;
}
static int F_107 ( struct V_98 * V_37 , struct V_98 * V_38 )
{
int V_134 ;
for ( V_134 = 0 ; V_134 < V_37 -> V_104 ; V_134 ++ ) {
if ( V_37 -> V_103 [ V_134 ] . V_200 == V_38 -> V_103 [ V_134 ] . V_200 )
continue;
return V_37 -> V_103 [ V_134 ] . V_200 > V_38 -> V_103 [ V_134 ] . V_200 ;
}
return 0 ;
}
static void F_108 ( struct V_195 * V_196 , struct V_98 * V_99 )
{
struct V_98 * V_197 ;
struct V_198 * * V_117 = & V_196 -> V_198 ;
struct V_198 * V_199 = NULL ;
while ( * V_117 != NULL ) {
V_199 = * V_117 ;
V_197 = F_104 ( V_199 , struct V_98 , V_94 ) ;
if ( F_107 ( V_99 , V_197 ) )
V_117 = & ( * V_117 ) -> V_201 ;
else
V_117 = & ( * V_117 ) -> V_202 ;
}
F_105 ( & V_99 -> V_94 , V_199 , V_117 ) ;
F_106 ( & V_99 -> V_94 , V_196 ) ;
}
static void F_109 ( struct V_195 * V_203 , struct V_195 * V_204 )
{
struct V_98 * V_99 ;
struct V_198 * V_94 ;
V_94 = F_110 ( V_204 ) ;
while ( V_94 ) {
struct V_198 * V_137 ;
V_99 = F_104 ( V_94 , struct V_98 , V_94 ) ;
V_137 = F_111 ( V_94 ) ;
F_112 ( V_94 , V_204 ) ;
F_108 ( V_203 , V_99 ) ;
V_94 = V_137 ;
}
}
static void F_113 ( struct V_15 * V_16 , int V_125 )
{
struct V_44 * V_45 = F_34 ( V_16 ) ;
struct V_98 * V_99 = V_45 -> V_49 -> V_100 ;
T_1 V_102 ;
int V_134 ;
V_102 = sizeof( * V_99 ) +
( sizeof( V_99 -> V_103 ) * ( V_99 -> V_104 - 1 ) ) ;
for ( V_134 = 0 ; V_134 < V_125 ; V_134 ++ ) {
F_114 ( V_99 -> V_96 ) ;
V_99 = ( void * ) V_99 + V_102 ;
}
F_2 ( & V_45 -> V_49 -> V_100 ) ;
}
static int F_115 ( struct V_15 * V_16 , struct V_10 * V_10 ,
struct V_123 * V_124 ,
struct V_195 * V_196 , int V_125 )
{
T_2 V_57 ;
int V_134 , V_205 ;
int V_65 = V_124 -> V_139 ;
struct V_98 * V_99 ;
struct V_44 * V_45 = F_34 ( V_16 ) ;
struct V_48 * V_66 = F_45 ( V_45 , V_65 ) ;
struct V_195 V_206 = V_207 ;
int V_104 = 1 ;
T_2 V_208 = V_66 -> V_71 ;
T_1 V_102 = sizeof( struct V_98 ) ;
if ( F_68 ( V_124 ) ) {
for ( V_134 = 1 ; V_134 < V_124 -> V_138 ; V_134 ++ ) {
V_66 = F_45 ( V_45 , V_65 + V_134 ) ;
V_208 += V_66 -> V_71 ;
}
V_104 = V_124 -> V_138 ;
V_102 += ( V_104 - 1 ) * sizeof( V_99 -> V_103 ) ;
}
if ( ! V_208 )
return 0 ;
V_99 = V_45 -> V_49 -> V_100 = calloc ( V_125 , V_102 ) ;
if ( ! V_45 -> V_49 -> V_100 )
return - 1 ;
V_57 = F_75 ( V_10 , V_16 -> V_57 ) ;
for ( V_134 = 0 ; V_134 < V_125 ; V_134 ++ ) {
T_2 V_22 ;
double V_209 = 0.0 ;
V_99 -> V_104 = V_104 ;
for ( V_205 = 0 ; V_205 < V_104 ; V_205 ++ ) {
V_66 = F_45 ( V_45 , V_65 + V_205 ) ;
V_99 -> V_103 [ V_205 ] . V_101 = 100.0 * V_66 -> V_13 [ V_134 ] / V_66 -> V_71 ;
if ( V_99 -> V_103 [ V_205 ] . V_101 > V_209 )
V_209 = V_99 -> V_103 [ V_205 ] . V_101 ;
}
if ( V_209 <= 0.5 )
goto V_137;
V_22 = V_57 + V_134 ;
V_99 -> V_96 = F_116 ( V_10 -> V_154 , V_22 , NULL , false ) ;
F_103 ( & V_206 , V_99 ) ;
V_137:
V_99 = ( void * ) V_99 + V_102 ;
}
F_109 ( V_196 , & V_206 ) ;
return 0 ;
}
static void F_117 ( struct V_195 * V_196 , const char * V_160 )
{
struct V_98 * V_99 ;
struct V_198 * V_94 ;
printf ( L_65 , V_160 ) ;
printf ( L_66 ) ;
if ( F_118 ( V_196 ) ) {
printf ( L_67 , V_210 ) ;
return;
}
V_94 = F_110 ( V_196 ) ;
while ( V_94 ) {
double V_101 , V_209 = 0.0 ;
const char * V_136 ;
char * V_96 ;
int V_134 ;
V_99 = F_104 ( V_94 , struct V_98 , V_94 ) ;
for ( V_134 = 0 ; V_134 < V_99 -> V_104 ; V_134 ++ ) {
V_101 = V_99 -> V_103 [ V_134 ] . V_200 ;
V_136 = F_70 ( V_101 ) ;
F_71 ( stdout , V_136 , L_28 , V_101 ) ;
if ( V_101 > V_209 )
V_209 = V_101 ;
}
V_96 = V_99 -> V_96 ;
V_136 = F_70 ( V_209 ) ;
F_71 ( stdout , V_136 , L_68 , V_96 ) ;
V_94 = F_111 ( V_94 ) ;
}
}
static void F_119 ( struct V_15 * V_16 , struct V_123 * V_124 )
{
struct V_44 * V_45 = F_34 ( V_16 ) ;
struct V_48 * V_66 = F_45 ( V_45 , V_124 -> V_139 ) ;
T_2 V_125 = F_35 ( V_16 ) , V_22 ;
for ( V_22 = 0 ; V_22 < V_125 ; ++ V_22 )
if ( V_66 -> V_13 [ V_22 ] != 0 )
printf ( L_69 V_18 L_70 V_72 L_10 , V_211 / 2 ,
V_16 -> V_57 + V_22 , V_66 -> V_13 [ V_22 ] ) ;
printf ( L_71 V_72 L_10 , V_211 / 2 , L_72 , V_66 -> V_71 ) ;
}
int F_120 ( struct V_15 * V_16 , struct V_10 * V_10 ,
struct V_123 * V_124 , bool V_212 ,
int V_126 , int V_127 , int V_213 )
{
struct V_154 * V_154 = V_10 -> V_154 ;
char * V_160 ;
const char * V_214 ;
const char * V_215 = F_121 ( V_124 ) ;
struct V_44 * V_45 = F_34 ( V_16 ) ;
struct V_48 * V_66 = F_45 ( V_45 , V_124 -> V_139 ) ;
struct V_83 * V_95 , * V_128 = NULL ;
T_2 V_57 = F_75 ( V_10 , V_16 -> V_57 ) ;
int V_32 = 2 , V_216 = 0 ;
int V_217 = 0 ;
T_2 V_125 ;
int V_141 = 8 ;
int V_218 ;
V_160 = F_9 ( V_154 -> V_170 ) ;
if ( ! V_160 )
return - V_73 ;
if ( V_212 )
V_214 = V_160 ;
else
V_214 = F_122 ( V_160 ) ;
V_125 = F_35 ( V_16 ) ;
if ( F_68 ( V_124 ) )
V_141 *= V_124 -> V_138 ;
V_218 = printf ( L_73 V_72 L_74 ,
V_141 , V_141 , L_75 , V_214 , V_215 , V_66 -> V_71 ) ;
printf ( L_76 ,
V_218 , V_218 , V_219 ) ;
if ( V_220 )
F_119 ( V_16 , V_124 ) ;
F_123 (pos, &notes->src->source, node) {
if ( V_213 && V_128 == NULL ) {
V_128 = V_95 ;
V_216 = 0 ;
}
switch ( F_67 ( V_95 , V_16 , V_57 , V_124 , V_125 ,
V_126 , V_32 , V_127 ,
V_128 ) ) {
case 0 :
++ V_32 ;
if ( V_213 ) {
V_32 += V_216 ;
V_128 = NULL ;
V_216 = 0 ;
}
break;
case 1 :
++ V_217 ;
break;
case - 1 :
default:
if ( ! V_213 )
break;
if ( V_216 == V_213 )
V_128 = F_124 ( V_128 -> V_94 . V_137 , F_125 ( * V_128 ) , V_94 ) ;
else
++ V_216 ;
break;
}
}
free ( V_160 ) ;
return V_217 ;
}
void F_126 ( struct V_15 * V_16 , int V_65 )
{
struct V_44 * V_45 = F_34 ( V_16 ) ;
struct V_48 * V_66 = F_45 ( V_45 , V_65 ) ;
memset ( V_66 , 0 , V_45 -> V_49 -> V_46 ) ;
}
void F_127 ( struct V_15 * V_16 , int V_65 )
{
struct V_44 * V_45 = F_34 ( V_16 ) ;
struct V_48 * V_66 = F_45 ( V_45 , V_65 ) ;
int V_125 = F_35 ( V_16 ) , V_22 ;
V_66 -> V_71 = 0 ;
for ( V_22 = 0 ; V_22 < V_125 ; ++ V_22 ) {
V_66 -> V_13 [ V_22 ] = V_66 -> V_13 [ V_22 ] * 7 / 8 ;
V_66 -> V_71 += V_66 -> V_13 [ V_22 ] ;
}
}
void F_128 ( struct V_92 * V_93 )
{
struct V_83 * V_95 , * V_221 ;
F_129 (pos, n, head, node) {
F_130 ( & V_95 -> V_94 ) ;
F_55 ( V_95 ) ;
}
}
static T_1 F_131 ( struct V_83 * V_84 , T_4 * V_222 )
{
T_1 V_32 ;
if ( V_84 -> V_22 == - 1 )
return fprintf ( V_222 , L_77 , V_84 -> line ) ;
V_32 = fprintf ( V_222 , L_14 V_18 L_26 , V_84 -> V_22 , V_84 -> V_5 ) ;
if ( V_84 -> V_2 . V_4 [ 0 ] != '\0' ) {
V_32 += fprintf ( V_222 , L_78 , 6 - ( int ) V_32 , L_34 ,
V_84 -> V_2 . V_4 ) ;
}
return V_32 + fprintf ( V_222 , L_10 ) ;
}
T_1 F_132 ( struct V_92 * V_93 , T_4 * V_222 )
{
struct V_83 * V_95 ;
T_1 V_32 = 0 ;
F_123 (pos, head, node)
V_32 += F_131 ( V_95 , V_222 ) ;
return V_32 ;
}
int F_133 ( struct V_15 * V_16 , struct V_10 * V_10 ,
struct V_123 * V_124 , bool V_223 ,
bool V_212 , int V_126 , int V_127 )
{
struct V_154 * V_154 = V_10 -> V_154 ;
struct V_195 V_98 = V_207 ;
T_2 V_125 ;
if ( F_87 ( V_16 , V_10 , 0 ) < 0 )
return - 1 ;
V_125 = F_35 ( V_16 ) ;
if ( V_223 ) {
V_224 = V_212 ;
F_115 ( V_16 , V_10 , V_124 , & V_98 , V_125 ) ;
F_117 ( & V_98 , V_154 -> V_170 ) ;
}
F_120 ( V_16 , V_10 , V_124 , V_212 ,
V_126 , V_127 , 0 ) ;
if ( V_223 )
F_113 ( V_16 , V_125 ) ;
F_128 ( & F_34 ( V_16 ) -> V_49 -> V_3 ) ;
return 0 ;
}
bool F_134 ( void )
{
return V_225 == 1 && V_226 . V_16 ;
}
