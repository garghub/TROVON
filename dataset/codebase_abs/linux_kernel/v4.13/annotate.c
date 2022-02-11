static int F_1 ( struct V_1 * V_1 )
{
struct V_2 * V_3 ;
T_1 V_4 ;
if ( V_1 -> V_5 == 0 && V_1 -> V_6 )
goto V_7;
V_4 = V_1 -> V_5 + 128 ;
V_3 = realloc ( V_1 -> V_6 , V_4 * sizeof( struct V_2 ) ) ;
if ( V_3 == NULL )
return - 1 ;
V_8:
V_1 -> V_6 = V_3 ;
V_1 -> V_5 = V_4 ;
return 0 ;
V_7:
V_4 = V_1 -> V_9 + 128 ;
V_3 = calloc ( V_4 , sizeof( struct V_2 ) ) ;
if ( V_3 == NULL )
return - 1 ;
memcpy ( V_3 , V_1 -> V_6 , V_1 -> V_9 ) ;
goto V_8;
}
static int F_2 ( struct V_1 * V_1 , const char * V_10 , struct V_11 * V_12 )
{
struct V_2 * V_2 ;
if ( V_1 -> V_9 == V_1 -> V_5 &&
F_1 ( V_1 ) )
return - 1 ;
V_2 = & V_1 -> V_6 [ V_1 -> V_9 ] ;
V_2 -> V_10 = F_3 ( V_10 ) ;
if ( ! V_2 -> V_10 )
return - 1 ;
V_2 -> V_12 = V_12 ;
V_1 -> V_9 ++ ;
F_4 ( V_1 ) ;
return 0 ;
}
static void F_5 ( struct V_13 * V_12 )
{
if ( V_12 == NULL )
return;
F_6 ( & V_12 -> V_14 . V_15 ) ;
F_6 ( & V_12 -> V_14 . V_10 ) ;
F_6 ( & V_12 -> V_16 . V_15 ) ;
F_6 ( & V_12 -> V_16 . V_10 ) ;
}
static int F_7 ( struct V_2 * V_2 , char * V_17 , T_1 V_18 ,
struct V_13 * V_12 )
{
return F_8 ( V_17 , V_18 , L_1 , V_2 -> V_10 , V_12 -> V_15 ) ;
}
int F_9 ( struct V_2 * V_2 , char * V_17 , T_1 V_18 ,
struct V_13 * V_12 )
{
if ( V_2 -> V_12 -> F_8 )
return V_2 -> V_12 -> F_8 ( V_2 , V_17 , V_18 , V_12 ) ;
return F_7 ( V_2 , V_17 , V_18 , V_12 ) ;
}
static int F_10 ( struct V_1 * V_1 , struct V_13 * V_12 , struct V_19 * V_19 )
{
char * V_20 , * V_21 , * V_10 ;
V_12 -> V_16 . V_22 = F_11 ( V_12 -> V_15 , & V_20 , 16 ) ;
V_10 = strchr ( V_20 , '<' ) ;
if ( V_10 == NULL )
goto V_23;
V_10 ++ ;
if ( V_1 -> V_24 . V_25 &&
strchr ( V_10 , V_1 -> V_24 . V_25 ) )
return - 1 ;
V_21 = strchr ( V_10 , '>' ) ;
if ( V_21 == NULL )
return - 1 ;
* V_21 = '\0' ;
V_12 -> V_16 . V_10 = F_3 ( V_10 ) ;
* V_21 = '>' ;
return V_12 -> V_16 . V_10 == NULL ? - 1 : 0 ;
V_23:
V_21 = strchr ( V_20 , '*' ) ;
if ( V_21 == NULL ) {
struct V_26 * V_27 = F_12 ( V_19 , V_19 -> V_28 ( V_19 , V_12 -> V_16 . V_22 ) ) ;
if ( V_27 != NULL )
V_12 -> V_16 . V_10 = F_3 ( V_27 -> V_10 ) ;
else
V_12 -> V_16 . V_22 = 0 ;
return 0 ;
}
V_12 -> V_16 . V_22 = F_11 ( V_21 + 1 , NULL , 16 ) ;
return 0 ;
}
static int F_13 ( struct V_2 * V_2 , char * V_17 , T_1 V_18 ,
struct V_13 * V_12 )
{
if ( V_12 -> V_16 . V_10 )
return F_8 ( V_17 , V_18 , L_1 , V_2 -> V_10 , V_12 -> V_16 . V_10 ) ;
if ( V_12 -> V_16 . V_22 == 0 )
return F_7 ( V_2 , V_17 , V_18 , V_12 ) ;
return F_8 ( V_17 , V_18 , L_2 V_29 , V_2 -> V_10 , V_12 -> V_16 . V_22 ) ;
}
bool F_14 ( const struct V_2 * V_2 )
{
return V_2 -> V_12 == & V_30 ;
}
static int F_15 ( struct V_1 * V_1 V_31 , struct V_13 * V_12 , struct V_19 * V_19 V_31 )
{
const char * V_32 = strchr ( V_12 -> V_15 , '+' ) ;
const char * V_33 = strchr ( V_12 -> V_15 , ',' ) ;
if ( V_33 ++ != NULL ) {
V_12 -> V_16 . V_22 = F_11 ( V_33 , NULL , 16 ) ;
if ( ! V_12 -> V_16 . V_22 ) {
V_33 = strchr ( V_33 , ',' ) ;
if ( V_33 ++ != NULL )
V_12 -> V_16 . V_22 = F_11 ( V_33 , NULL , 16 ) ;
}
} else {
V_12 -> V_16 . V_22 = F_11 ( V_12 -> V_15 , NULL , 16 ) ;
}
if ( V_32 ++ != NULL ) {
V_12 -> V_16 . V_34 = F_11 ( V_32 , NULL , 16 ) ;
V_12 -> V_16 . V_35 = true ;
} else {
V_12 -> V_16 . V_35 = false ;
}
return 0 ;
}
static int F_16 ( struct V_2 * V_2 , char * V_17 , T_1 V_18 ,
struct V_13 * V_12 )
{
const char * V_33 = strchr ( V_12 -> V_15 , ',' ) ;
if ( ! V_12 -> V_16 . V_22 || V_12 -> V_16 . V_34 < 0 )
return F_7 ( V_2 , V_17 , V_18 , V_12 ) ;
if ( V_33 != NULL ) {
const char * V_36 = strchr ( V_33 + 1 , ',' ) ;
if ( V_36 != NULL )
V_33 = V_36 ;
V_33 ++ ;
if ( * V_33 == ' ' )
V_33 ++ ;
}
return F_8 ( V_17 , V_18 , L_3 V_29 ,
V_2 -> V_10 , V_33 ? V_33 - V_12 -> V_15 : 0 , V_12 -> V_15 ,
V_12 -> V_16 . V_34 ) ;
}
bool F_17 ( const struct V_2 * V_2 )
{
return V_2 -> V_12 == & V_37 ;
}
static int F_18 ( char * V_15 , char * V_38 , T_2 * V_39 , char * * V_40 )
{
char * V_20 , * V_10 , * V_41 ;
if ( strstr ( V_15 , L_4 ) == NULL )
return 0 ;
* V_39 = F_11 ( V_38 , & V_20 , 16 ) ;
V_10 = strchr ( V_20 , '<' ) ;
if ( V_10 == NULL )
return - 1 ;
V_10 ++ ;
V_41 = strchr ( V_10 , '>' ) ;
if ( V_41 == NULL )
return 0 ;
* V_41 = '\0' ;
* V_40 = F_3 ( V_10 ) ;
* V_41 = '>' ;
return 0 ;
}
static int F_19 ( struct V_1 * V_1 , struct V_13 * V_12 , struct V_19 * V_19 )
{
V_12 -> V_42 . V_12 = F_20 ( sizeof( * V_12 -> V_42 . V_12 ) ) ;
if ( V_12 -> V_42 . V_12 == NULL )
return 0 ;
if ( F_21 ( V_12 -> V_15 , & V_12 -> V_42 . V_2 . V_10 , & V_12 -> V_42 . V_12 -> V_15 ) < 0 )
goto V_43;
V_12 -> V_42 . V_2 . V_12 = F_22 ( V_1 , V_12 -> V_42 . V_2 . V_10 ) ;
if ( V_12 -> V_42 . V_2 . V_12 == NULL )
goto V_43;
if ( V_12 -> V_42 . V_2 . V_12 -> V_44 &&
V_12 -> V_42 . V_2 . V_12 -> V_44 ( V_1 , V_12 -> V_42 . V_12 , V_19 ) < 0 )
goto V_43;
return 0 ;
V_43:
F_6 ( & V_12 -> V_42 . V_12 ) ;
return 0 ;
}
static int F_23 ( struct V_2 * V_2 , char * V_17 , T_1 V_18 ,
struct V_13 * V_12 )
{
int V_45 ;
if ( V_12 -> V_42 . V_2 . V_12 == NULL )
return F_7 ( V_2 , V_17 , V_18 , V_12 ) ;
V_45 = F_8 ( V_17 , V_18 , L_5 , V_2 -> V_10 ) ;
return V_45 + F_9 ( & V_12 -> V_42 . V_2 , V_17 + V_45 ,
V_18 - V_45 , V_12 -> V_42 . V_12 ) ;
}
static void F_24 ( struct V_13 * V_12 )
{
struct V_2 * V_2 = & V_12 -> V_42 . V_2 ;
if ( V_2 -> V_12 && V_2 -> V_12 -> free )
V_2 -> V_12 -> free ( V_12 -> V_42 . V_12 ) ;
else
F_5 ( V_12 -> V_42 . V_12 ) ;
F_6 ( & V_12 -> V_42 . V_12 ) ;
F_6 ( & V_12 -> V_16 . V_15 ) ;
F_6 ( & V_12 -> V_16 . V_10 ) ;
}
static int F_25 ( struct V_1 * V_1 , struct V_13 * V_12 , struct V_19 * V_19 V_31 )
{
char * V_32 = strchr ( V_12 -> V_15 , ',' ) , * V_16 , * V_38 , V_46 ;
if ( V_32 == NULL )
return - 1 ;
* V_32 = '\0' ;
V_12 -> V_14 . V_15 = F_3 ( V_12 -> V_15 ) ;
* V_32 = ',' ;
if ( V_12 -> V_14 . V_15 == NULL )
return - 1 ;
V_16 = ++ V_32 ;
V_38 = strchr ( V_32 , V_1 -> V_24 . V_47 ) ;
if ( V_38 != NULL )
V_32 = V_38 - 1 ;
else
V_32 = strchr ( V_32 , '\0' ) - 1 ;
while ( V_32 > V_16 && isspace ( V_32 [ 0 ] ) )
-- V_32 ;
V_32 ++ ;
V_46 = * V_32 ;
* V_32 = '\0' ;
V_12 -> V_16 . V_15 = F_3 ( V_16 ) ;
* V_32 = V_46 ;
if ( V_12 -> V_16 . V_15 == NULL )
goto V_48;
if ( V_38 == NULL )
return 0 ;
V_38 = F_26 ( V_38 ) ;
F_18 ( V_12 -> V_14 . V_15 , V_38 , & V_12 -> V_14 . V_22 , & V_12 -> V_14 . V_10 ) ;
F_18 ( V_12 -> V_16 . V_15 , V_38 , & V_12 -> V_16 . V_22 , & V_12 -> V_16 . V_10 ) ;
return 0 ;
V_48:
F_6 ( & V_12 -> V_14 . V_15 ) ;
return - 1 ;
}
static int F_27 ( struct V_2 * V_2 , char * V_17 , T_1 V_18 ,
struct V_13 * V_12 )
{
return F_8 ( V_17 , V_18 , L_6 , V_2 -> V_10 ,
V_12 -> V_14 . V_10 ? : V_12 -> V_14 . V_15 ,
V_12 -> V_16 . V_10 ? : V_12 -> V_16 . V_15 ) ;
}
static int F_28 ( struct V_1 * V_1 V_31 , struct V_13 * V_12 , struct V_19 * V_19 V_31 )
{
char * V_16 , * V_38 , * V_32 , V_46 ;
V_16 = V_32 = V_12 -> V_15 ;
while ( V_32 [ 0 ] != '\0' && ! isspace ( V_32 [ 0 ] ) )
++ V_32 ;
V_46 = * V_32 ;
* V_32 = '\0' ;
V_12 -> V_16 . V_15 = F_3 ( V_16 ) ;
* V_32 = V_46 ;
if ( V_12 -> V_16 . V_15 == NULL )
return - 1 ;
V_38 = strchr ( V_32 , V_1 -> V_24 . V_47 ) ;
if ( V_38 == NULL )
return 0 ;
V_38 = F_26 ( V_38 ) ;
F_18 ( V_12 -> V_16 . V_15 , V_38 , & V_12 -> V_16 . V_22 , & V_12 -> V_16 . V_10 ) ;
return 0 ;
}
static int F_29 ( struct V_2 * V_2 , char * V_17 , T_1 V_18 ,
struct V_13 * V_12 )
{
return F_8 ( V_17 , V_18 , L_1 , V_2 -> V_10 ,
V_12 -> V_16 . V_10 ? : V_12 -> V_16 . V_15 ) ;
}
static int F_30 ( struct V_2 * V_2 V_31 , char * V_17 , T_1 V_18 ,
struct V_13 * V_12 V_31 )
{
return F_8 ( V_17 , V_18 , L_7 , L_8 ) ;
}
bool F_31 ( const struct V_2 * V_2 )
{
return V_2 -> V_12 == & V_49 ;
}
static int F_32 ( const void * V_10 , const void * V_50 )
{
const struct V_2 * V_2 = V_50 ;
return strcmp ( V_10 , V_2 -> V_10 ) ;
}
static int F_33 ( const void * V_51 , const void * V_52 )
{
const struct V_2 * V_53 = V_51 ;
const struct V_2 * V_54 = V_52 ;
return strcmp ( V_53 -> V_10 , V_54 -> V_10 ) ;
}
static void F_4 ( struct V_1 * V_1 )
{
const int V_55 = V_1 -> V_9 ;
qsort ( V_1 -> V_6 , V_55 , sizeof( struct V_2 ) , F_33 ) ;
}
static struct V_11 * F_34 ( struct V_1 * V_1 , const char * V_10 )
{
struct V_2 * V_2 ;
const int V_55 = V_1 -> V_9 ;
if ( ! V_1 -> V_56 ) {
F_4 ( V_1 ) ;
V_1 -> V_56 = true ;
}
V_2 = bsearch ( V_10 , V_1 -> V_6 , V_55 , sizeof( struct V_2 ) , F_32 ) ;
return V_2 ? V_2 -> V_12 : NULL ;
}
static struct V_11 * F_22 ( struct V_1 * V_1 , const char * V_10 )
{
struct V_11 * V_12 = F_34 ( V_1 , V_10 ) ;
if ( ! V_12 && V_1 -> V_57 )
V_12 = V_1 -> V_57 ( V_1 , V_10 ) ;
return V_12 ;
}
static int F_35 ( const void * V_10 , const void * V_58 )
{
const struct V_1 * V_1 = V_58 ;
return strcmp ( V_10 , V_1 -> V_10 ) ;
}
static int F_36 ( const void * V_51 , const void * V_52 )
{
const struct V_1 * V_59 = V_51 ;
const struct V_1 * V_60 = V_52 ;
return strcmp ( V_59 -> V_10 , V_60 -> V_10 ) ;
}
static void F_37 ( void )
{
const int V_55 = F_38 ( V_61 ) ;
qsort ( V_61 , V_55 , sizeof( struct V_1 ) , F_36 ) ;
}
static struct V_1 * F_39 ( const char * V_10 )
{
const int V_55 = F_38 ( V_61 ) ;
static bool V_62 ;
if ( ! V_62 ) {
F_37 () ;
V_62 = true ;
}
return bsearch ( V_10 , V_61 , V_55 , sizeof( struct V_1 ) , F_35 ) ;
}
int F_40 ( struct V_26 * V_27 )
{
struct V_63 * V_64 = F_41 ( V_27 ) ;
const T_1 V_18 = F_42 ( V_27 ) ;
T_1 V_65 ;
if ( V_18 > ( V_66 - sizeof( struct V_67 ) ) / sizeof( T_2 ) )
return - 1 ;
V_65 = ( sizeof( struct V_67 ) + V_18 * sizeof( T_2 ) ) ;
if ( V_65 > ( V_66 - sizeof( * V_64 -> V_68 ) )
/ V_69 . V_70 )
return - 1 ;
V_64 -> V_68 = F_20 ( sizeof( * V_64 -> V_68 ) + V_69 . V_70 * V_65 ) ;
if ( V_64 -> V_68 == NULL )
return - 1 ;
V_64 -> V_68 -> V_65 = V_65 ;
V_64 -> V_68 -> V_71 = V_69 . V_70 ;
F_43 ( & V_64 -> V_68 -> V_14 ) ;
return 0 ;
}
static int F_44 ( struct V_26 * V_27 )
{
struct V_63 * V_64 = F_41 ( V_27 ) ;
const T_1 V_18 = F_42 ( V_27 ) ;
V_64 -> V_68 -> V_72 = calloc ( V_18 , sizeof( struct V_73 ) ) ;
if ( V_64 -> V_68 -> V_72 == NULL )
return - 1 ;
return 0 ;
}
void F_45 ( struct V_26 * V_27 )
{
struct V_63 * V_64 = F_41 ( V_27 ) ;
F_46 ( & V_64 -> V_74 ) ;
if ( V_64 -> V_68 != NULL ) {
memset ( V_64 -> V_68 -> V_75 , 0 ,
V_64 -> V_68 -> V_71 * V_64 -> V_68 -> V_65 ) ;
if ( V_64 -> V_68 -> V_72 )
memset ( V_64 -> V_68 -> V_72 , 0 ,
F_42 ( V_27 ) * sizeof( struct V_73 ) ) ;
}
F_47 ( & V_64 -> V_74 ) ;
}
static int F_48 ( struct V_63 * V_64 ,
T_2 V_76 ,
unsigned V_34 , unsigned V_77 ,
unsigned V_78 )
{
struct V_73 * V_79 ;
V_79 = V_64 -> V_68 -> V_72 ;
V_79 [ V_34 ] . V_80 ++ ;
V_79 [ V_34 ] . V_81 += V_77 ;
if ( ! V_78 && V_79 [ V_34 ] . V_78 )
return 0 ;
if ( V_79 [ V_34 ] . V_82 ) {
if ( V_78 && ( ! V_79 [ V_34 ] . V_78 ||
V_79 [ V_34 ] . V_76 > V_76 ) ) {
V_79 [ V_34 ] . V_78 = 0 ;
V_79 [ V_34 ] . V_77 = 0 ;
V_79 [ V_34 ] . V_82 = 0 ;
if ( V_79 [ V_34 ] . V_83 < 0xffff )
V_79 [ V_34 ] . V_83 ++ ;
} else if ( V_78 &&
V_79 [ V_34 ] . V_76 < V_76 )
return 0 ;
}
V_79 [ V_34 ] . V_78 = V_78 ;
V_79 [ V_34 ] . V_76 = V_76 ;
V_79 [ V_34 ] . V_77 += V_77 ;
V_79 [ V_34 ] . V_82 ++ ;
return 0 ;
}
static int F_49 ( struct V_26 * V_27 , struct V_19 * V_19 ,
struct V_63 * V_64 , int V_84 , T_2 V_22 )
{
unsigned V_34 ;
struct V_67 * V_85 ;
F_50 ( L_9 V_29 L_10 , V_86 , V_19 -> V_87 ( V_19 , V_22 ) ) ;
if ( ( V_22 < V_27 -> V_76 || V_22 >= V_27 -> V_88 ) &&
( V_22 != V_27 -> V_88 || V_27 -> V_76 != V_27 -> V_88 ) ) {
F_51 ( L_11 V_29 L_12 V_29 L_13 V_29 L_10 ,
V_86 , __LINE__ , V_27 -> V_10 , V_27 -> V_76 , V_22 , V_27 -> V_88 ) ;
return - V_89 ;
}
V_34 = V_22 - V_27 -> V_76 ;
V_85 = F_52 ( V_64 , V_84 ) ;
V_85 -> V_90 ++ ;
V_85 -> V_22 [ V_34 ] ++ ;
F_50 ( L_14 V_29 L_15 V_29 L_16 V_29
L_17 V_91 L_10 , V_27 -> V_76 , V_27 -> V_10 ,
V_22 , V_22 - V_27 -> V_76 , V_84 , V_85 -> V_22 [ V_34 ] ) ;
return 0 ;
}
static struct V_63 * F_53 ( struct V_26 * V_27 , bool V_77 )
{
struct V_63 * V_64 = F_41 ( V_27 ) ;
if ( V_64 -> V_68 == NULL ) {
if ( F_40 ( V_27 ) < 0 )
return NULL ;
}
if ( ! V_64 -> V_68 -> V_72 && V_77 ) {
if ( F_44 ( V_27 ) < 0 )
return NULL ;
}
return V_64 ;
}
static int F_54 ( struct V_26 * V_27 , struct V_19 * V_19 ,
int V_84 , T_2 V_22 )
{
struct V_63 * V_64 ;
if ( V_27 == NULL )
return 0 ;
V_64 = F_53 ( V_27 , false ) ;
if ( V_64 == NULL )
return - V_92 ;
return F_49 ( V_27 , V_19 , V_64 , V_84 , V_22 ) ;
}
static int F_55 ( T_2 V_22 , T_2 V_76 ,
struct V_26 * V_27 , unsigned V_77 )
{
struct V_63 * V_64 ;
unsigned V_34 ;
if ( V_27 == NULL )
return 0 ;
V_64 = F_53 ( V_27 , true ) ;
if ( V_64 == NULL )
return - V_92 ;
if ( V_22 < V_27 -> V_76 || V_22 >= V_27 -> V_88 )
return - V_89 ;
if ( V_76 ) {
if ( V_76 < V_27 -> V_76 || V_76 >= V_27 -> V_88 )
return - V_89 ;
if ( V_76 >= V_22 )
V_76 = 0 ;
}
V_34 = V_22 - V_27 -> V_76 ;
return F_48 ( V_64 ,
V_76 ? V_76 - V_27 -> V_76 : 0 ,
V_34 , V_77 ,
! ! V_76 ) ;
}
int F_56 ( struct V_93 * V_94 ,
struct V_93 * V_76 ,
unsigned V_77 )
{
T_2 V_95 = 0 ;
int V_96 ;
if ( ! V_77 )
return 0 ;
if ( V_76 &&
( V_76 -> V_27 == V_94 -> V_27 ||
( V_94 -> V_27 &&
V_76 -> V_22 == V_94 -> V_27 -> V_76 + V_94 -> V_19 -> V_76 ) ) )
V_95 = V_76 -> V_97 ;
if ( V_95 == 0 )
F_57 ( L_18 V_29 L_19 V_29 L_20 V_29 L_21 V_29 L_10 ,
V_94 -> V_22 ,
V_76 ? V_76 -> V_22 : 0 ,
V_94 -> V_27 ? V_94 -> V_27 -> V_76 + V_94 -> V_19 -> V_76 : 0 ,
V_95 ) ;
V_96 = F_55 ( V_94 -> V_97 , V_95 , V_94 -> V_27 , V_77 ) ;
if ( V_96 )
F_57 ( L_22 , V_96 ) ;
return V_96 ;
}
int F_58 ( struct V_93 * V_94 , int V_84 )
{
return F_54 ( V_94 -> V_27 , V_94 -> V_19 , V_84 , V_94 -> V_97 ) ;
}
int F_59 ( struct V_98 * V_99 , int V_84 , T_2 V_100 )
{
return F_54 ( V_99 -> V_101 . V_27 , V_99 -> V_101 . V_19 , V_84 , V_100 ) ;
}
static void F_60 ( struct V_102 * V_103 , struct V_1 * V_1 , struct V_19 * V_19 )
{
V_103 -> V_2 . V_12 = F_22 ( V_1 , V_103 -> V_2 . V_10 ) ;
if ( ! V_103 -> V_2 . V_12 )
return;
if ( V_103 -> V_2 . V_12 -> V_44 && V_103 -> V_2 . V_12 -> V_44 ( V_1 , & V_103 -> V_12 , V_19 ) < 0 )
V_103 -> V_2 . V_12 = NULL ;
}
static int F_21 ( char * line , const char * * V_40 , char * * V_104 )
{
char V_105 , * V_10 = F_26 ( line ) ;
if ( V_10 [ 0 ] == '\0' )
return - 1 ;
* V_104 = V_10 + 1 ;
while ( ( * V_104 ) [ 0 ] != '\0' && ! isspace ( ( * V_104 ) [ 0 ] ) )
++ * V_104 ;
V_105 = ( * V_104 ) [ 0 ] ;
( * V_104 ) [ 0 ] = '\0' ;
* V_40 = F_3 ( V_10 ) ;
if ( * V_40 == NULL )
goto V_106;
( * V_104 ) [ 0 ] = V_105 ;
* V_104 = F_26 ( * V_104 ) ;
return 0 ;
V_106:
free ( ( void * ) V_40 ) ;
* V_40 = NULL ;
return - 1 ;
}
static struct V_102 * F_61 ( T_3 V_34 , char * line ,
T_1 V_107 , int V_108 ,
struct V_1 * V_1 ,
struct V_19 * V_19 )
{
struct V_102 * V_103 = F_20 ( sizeof( * V_103 ) + V_107 ) ;
if ( V_103 != NULL ) {
V_103 -> V_34 = V_34 ;
V_103 -> line = F_3 ( line ) ;
V_103 -> V_108 = V_108 ;
if ( V_103 -> line == NULL )
goto V_109;
if ( V_34 != - 1 ) {
if ( F_21 ( V_103 -> line , & V_103 -> V_2 . V_10 , & V_103 -> V_12 . V_15 ) < 0 )
goto V_110;
F_60 ( V_103 , V_1 , V_19 ) ;
}
}
return V_103 ;
V_110:
F_6 ( & V_103 -> line ) ;
V_109:
free ( V_103 ) ;
return NULL ;
}
void F_62 ( struct V_102 * V_103 )
{
F_6 ( & V_103 -> line ) ;
if ( V_103 -> V_2 . V_12 && V_103 -> V_2 . V_12 -> free )
V_103 -> V_2 . V_12 -> free ( & V_103 -> V_12 ) ;
else
F_5 ( & V_103 -> V_12 ) ;
free ( ( void * ) V_103 -> V_2 . V_10 ) ;
V_103 -> V_2 . V_10 = NULL ;
free ( V_103 ) ;
}
int F_63 ( struct V_102 * V_103 , char * V_17 , T_1 V_18 , bool V_15 )
{
if ( V_15 || ! V_103 -> V_2 . V_12 )
return F_8 ( V_17 , V_18 , L_1 , V_103 -> V_2 . V_10 , V_103 -> V_12 . V_15 ) ;
return F_9 ( & V_103 -> V_2 , V_17 , V_18 , & V_103 -> V_12 ) ;
}
static void F_64 ( struct V_111 * V_112 , struct V_102 * line )
{
F_65 ( & line -> V_113 , V_112 ) ;
}
struct V_102 * F_66 ( struct V_111 * V_112 , struct V_102 * V_114 )
{
F_67 (pos, head, node)
if ( V_114 -> V_34 >= 0 )
return V_114 ;
return NULL ;
}
double F_68 ( struct V_63 * V_64 , int V_84 , T_3 V_34 ,
T_3 V_88 , const char * * V_115 , T_2 * V_116 )
{
struct V_117 * V_118 = V_64 -> V_68 -> V_119 ;
double V_120 = 0.0 ;
* V_116 = 0 ;
if ( V_118 ) {
T_1 V_121 = sizeof( * V_118 ) +
sizeof( V_118 -> V_122 ) * ( V_118 -> V_123 - 1 ) ;
while ( V_34 < V_88 ) {
V_118 = ( void * ) V_64 -> V_68 -> V_119 +
( V_121 * V_34 ) ;
if ( * V_115 == NULL )
* V_115 = V_118 -> V_115 ;
V_120 += V_118 -> V_122 [ V_84 ] . V_120 ;
* V_116 += V_118 -> V_122 [ V_84 ] . V_124 ;
V_34 ++ ;
}
} else {
struct V_67 * V_85 = F_52 ( V_64 , V_84 ) ;
unsigned int V_125 = 0 ;
while ( V_34 < V_88 )
V_125 += V_85 -> V_22 [ V_34 ++ ] ;
if ( V_85 -> V_90 ) {
* V_116 = V_125 ;
V_120 = 100.0 * V_125 / V_85 -> V_90 ;
}
}
return V_120 ;
}
static const char * F_69 ( struct V_126 * V_127 )
{
double V_128 = F_70 ( V_127 ) ;
if ( V_128 >= 0 ) {
if ( V_128 > 0.75 )
return V_129 ;
if ( V_128 < 0.01 )
return V_130 ;
}
return V_131 ;
}
static const char * F_71 ( struct V_126 * V_127 )
{
double V_128 = F_70 ( V_127 ) ;
if ( V_128 >= 0 ) {
if ( V_128 < 0.01 )
return V_130 ;
}
return V_132 ;
}
static void F_72 ( struct V_126 * V_127 , T_2 V_22 )
{
bool V_133 = true ;
if ( ! V_127 )
return;
#if 1
if ( V_127 -> V_134 && V_127 -> V_76 == V_22 ) {
struct V_126 * V_135 = V_127 ;
double V_136 ;
while ( ! V_135 -> V_137 )
V_135 = F_73 ( V_135 ) ;
V_136 = 100 * ( double ) V_127 -> V_138 / V_135 -> V_139 ;
if ( V_136 > 0.1 ) {
if ( V_133 ) {
V_133 = false ;
printf ( L_23 ) ;
}
printf ( L_24 , V_136 ) ;
}
}
#endif
if ( V_127 -> V_137 && V_127 -> V_88 == V_22 ) {
double V_136 = 100 * ( double ) V_127 -> V_140 / V_127 -> V_139 ;
if ( V_136 > 0.1 ) {
if ( V_133 ) {
V_133 = false ;
printf ( L_23 ) ;
}
printf ( L_25 , V_136 , 100 * ( double ) V_127 -> V_141 / V_127 -> V_140 ) ;
}
}
}
static int F_74 ( struct V_102 * V_103 , struct V_26 * V_27 , T_2 V_76 ,
struct V_142 * V_143 , T_2 V_144 , int V_145 , int V_45 ,
int V_146 , struct V_102 * V_147 )
{
static const char * V_148 ;
static const char * V_149 ;
if ( V_103 -> V_34 != - 1 ) {
const char * V_115 = NULL ;
T_2 V_116 ;
double V_120 , V_150 = 0.0 ;
double * V_151 = & V_120 ;
T_2 * V_152 = & V_116 ;
int V_153 , V_154 = 1 ;
const char * V_155 ;
struct V_63 * V_64 = F_41 ( V_27 ) ;
T_3 V_34 = V_103 -> V_34 ;
const T_2 V_22 = V_76 + V_34 ;
struct V_102 * V_156 ;
struct V_126 * V_127 ;
V_156 = F_66 ( & V_64 -> V_68 -> V_14 , V_103 ) ;
if ( F_75 ( V_143 ) ) {
V_154 = V_143 -> V_157 ;
V_151 = calloc ( V_154 , sizeof( double ) ) ;
V_152 = calloc ( V_154 , sizeof( T_2 ) ) ;
if ( V_151 == NULL || V_152 == NULL ) {
return - 1 ;
}
}
for ( V_153 = 0 ; V_153 < V_154 ; V_153 ++ ) {
V_120 = F_68 ( V_64 ,
V_64 -> V_68 -> V_119 ? V_153 : V_143 -> V_158 + V_153 ,
V_34 ,
V_156 ? V_156 -> V_34 : ( T_3 ) V_144 ,
& V_115 , & V_116 ) ;
V_151 [ V_153 ] = V_120 ;
V_152 [ V_153 ] = V_116 ;
if ( V_120 > V_150 )
V_150 = V_120 ;
}
if ( V_150 < V_145 )
return - 1 ;
if ( V_146 && V_45 >= V_146 )
return 1 ;
if ( V_147 != NULL ) {
F_76 (queue, &notes->src->source, node) {
if ( V_147 == V_103 )
break;
F_74 ( V_147 , V_27 , V_76 , V_143 , V_144 ,
0 , 0 , 1 , NULL ) ;
}
}
V_155 = F_77 ( V_150 ) ;
if ( V_115 ) {
if ( ! V_148 || strcmp ( V_148 , V_115 )
|| V_155 != V_149 ) {
F_78 ( stdout , V_155 , L_26 , V_115 ) ;
V_148 = V_115 ;
V_149 = V_155 ;
}
}
for ( V_153 = 0 ; V_153 < V_154 ; V_153 ++ ) {
V_120 = V_151 [ V_153 ] ;
V_116 = V_152 [ V_153 ] ;
V_155 = F_77 ( V_120 ) ;
if ( V_69 . V_159 )
F_78 ( stdout , V_155 , L_27 V_91 ,
V_116 ) ;
else
F_78 ( stdout , V_155 , L_28 , V_120 ) ;
}
printf ( L_29 ) ;
V_127 = F_79 ( V_22 ) ;
F_78 ( stdout , F_69 ( V_127 ) , L_30 V_29 L_31 , V_22 ) ;
F_78 ( stdout , F_71 ( V_127 ) , L_32 , V_103 -> line ) ;
F_72 ( V_127 , V_22 ) ;
printf ( L_10 ) ;
if ( V_151 != & V_120 )
free ( V_151 ) ;
if ( V_152 != & V_116 )
free ( V_152 ) ;
} else if ( V_146 && V_45 >= V_146 )
return 1 ;
else {
int V_160 = 8 ;
if ( V_147 )
return - 1 ;
if ( F_75 ( V_143 ) )
V_160 *= V_143 -> V_157 ;
if ( ! * V_103 -> line )
printf ( L_33 , V_160 , L_34 ) ;
else
printf ( L_35 , V_160 , L_34 , V_103 -> line ) ;
}
return 0 ;
}
static int F_80 ( struct V_26 * V_27 , struct V_19 * V_19 ,
struct V_1 * V_1 ,
T_4 * V_161 , T_1 V_107 ,
int * V_108 )
{
struct V_63 * V_64 = F_41 ( V_27 ) ;
struct V_102 * V_103 ;
char * line = NULL , * V_162 , * V_105 , * V_163 ;
T_1 V_164 ;
T_3 V_165 , V_34 = - 1 ;
T_5 V_166 [ 2 ] ;
if ( F_81 ( & line , & V_164 , V_161 ) < 0 )
return - 1 ;
if ( ! line )
return - 1 ;
V_165 = - 1 ;
V_162 = F_82 ( line ) ;
if ( regexec ( & V_167 , V_162 , 2 , V_166 , 0 ) == 0 ) {
* V_108 = atoi ( V_162 + V_166 [ 1 ] . V_168 ) ;
return 0 ;
}
V_105 = F_26 ( V_162 ) ;
if ( * V_105 ) {
V_165 = F_11 ( V_105 , & V_163 , 16 ) ;
if ( * V_163 != ':' || V_105 == V_163 || V_163 [ 1 ] == '\0' )
V_165 = - 1 ;
}
if ( V_165 != - 1 ) {
T_2 V_76 = F_83 ( V_19 , V_27 -> V_76 ) ,
V_88 = F_83 ( V_19 , V_27 -> V_88 ) ;
V_34 = V_165 - V_76 ;
if ( ( T_2 ) V_165 < V_76 || ( T_2 ) V_165 >= V_88 )
V_34 = - 1 ;
else
V_162 = V_163 + 1 ;
}
V_103 = F_61 ( V_34 , V_162 , V_107 , * V_108 , V_1 , V_19 ) ;
free ( line ) ;
( * V_108 ) ++ ;
if ( V_103 == NULL )
return - 1 ;
if ( ! F_84 ( V_103 ) ) {
V_103 -> V_12 . V_16 . V_34 = V_103 -> V_12 . V_16 . V_22 -
F_83 ( V_19 , V_27 -> V_76 ) ;
V_103 -> V_12 . V_16 . V_35 = true ;
}
if ( V_103 -> V_2 . V_12 && F_14 ( & V_103 -> V_2 ) && ! V_103 -> V_12 . V_16 . V_10 ) {
struct V_93 V_16 = {
. V_19 = V_19 ,
. V_22 = V_103 -> V_12 . V_16 . V_22 ,
} ;
if ( ! F_85 ( & V_16 ) &&
V_16 . V_27 -> V_76 == V_16 . V_97 )
V_103 -> V_12 . V_16 . V_10 = F_3 ( V_16 . V_27 -> V_10 ) ;
}
F_64 ( & V_64 -> V_68 -> V_14 , V_103 ) ;
return 0 ;
}
int F_86 ( struct V_26 * V_27 V_31 , struct V_19 * V_19 ,
int V_169 , char * V_170 , T_1 V_171 )
{
struct V_172 * V_172 = V_19 -> V_172 ;
F_87 ( V_171 == 0 ) ;
if ( V_169 >= 0 ) {
F_88 ( V_169 , V_170 , V_171 ) ;
return 0 ;
}
switch ( V_169 ) {
case V_173 : {
char V_17 [ V_174 + 15 ] = L_36 ;
char * V_175 = NULL ;
if ( V_172 -> V_176 ) {
F_89 ( V_172 -> V_177 ,
sizeof( V_172 -> V_177 ) , V_17 + 15 ) ;
V_175 = V_17 ;
}
F_8 ( V_170 , V_171 ,
L_37
L_38
L_39
L_40
L_41
L_42 , V_175 ? : L_43 ) ;
}
break;
default:
F_8 ( V_170 , V_171 , L_44 , V_169 ) ;
break;
}
return 0 ;
}
static int F_90 ( struct V_172 * V_172 , char * V_178 , T_1 V_179 )
{
char V_180 [ V_181 ] ;
char * V_182 ;
char * V_183 = NULL ;
char * V_114 ;
if ( V_172 -> V_184 == V_185 &&
! F_91 ( V_172 ) )
return V_173 ;
V_182 = F_92 ( V_172 , NULL , 0 ) ;
if ( V_182 ) {
F_93 ( V_178 , V_179 , V_182 ) ;
free ( V_182 ) ;
} else {
if ( V_172 -> V_176 )
return V_92 ;
goto V_186;
}
V_183 = F_3 ( V_178 ) ;
if ( ! V_183 )
return - 1 ;
V_114 = strrchr ( V_183 , '/' ) ;
if ( V_114 && strlen ( V_114 ) < V_174 - 2 )
F_94 ( V_183 ) ;
if ( F_91 ( V_172 ) ||
F_95 ( V_183 , V_180 , sizeof( V_180 ) ) < 0 ||
strstr ( V_180 , V_187 ) ||
F_96 ( V_178 , V_188 ) ) {
V_186:
F_93 ( V_178 , V_179 , V_172 -> V_189 ) ;
}
free ( V_183 ) ;
return 0 ;
}
static const char * F_97 ( const char * V_190 )
{
struct V_191 V_192 ;
if ( ! V_190 ) {
if ( F_98 ( & V_192 ) < 0 )
return NULL ;
V_190 = V_192 . V_193 ;
}
return F_99 ( ( char * ) V_190 ) ;
}
int F_100 ( struct V_26 * V_27 , struct V_19 * V_19 ,
const char * V_190 , T_1 V_107 ,
struct V_1 * * V_194 )
{
struct V_172 * V_172 = V_19 -> V_172 ;
char V_195 [ V_181 * 2 ] ;
struct V_1 * V_1 = NULL ;
T_4 * V_161 ;
char V_196 [ V_181 ] ;
struct V_197 V_198 ;
bool V_199 = false ;
int V_200 [ 2 ] ;
int V_201 = 0 ;
int V_202 ;
T_6 V_203 ;
int V_96 = F_90 ( V_172 , V_196 , sizeof( V_196 ) ) ;
if ( V_96 )
return V_96 ;
V_190 = F_97 ( V_190 ) ;
if ( ! V_190 )
return - 1 ;
V_1 = F_39 ( V_190 ) ;
if ( V_1 == NULL )
return - V_204 ;
if ( V_194 )
* V_194 = V_1 ;
if ( V_1 -> V_205 ) {
V_96 = V_1 -> V_205 ( V_1 ) ;
if ( V_96 ) {
F_101 ( L_45 , V_86 , V_1 -> V_10 ) ;
return V_96 ;
}
}
F_51 ( L_46 V_29 L_13 V_29 L_10 , V_86 ,
V_196 , V_27 -> V_10 , V_19 -> V_87 ( V_19 , V_27 -> V_76 ) ,
V_19 -> V_87 ( V_19 , V_27 -> V_88 ) ) ;
F_51 ( L_47 ,
V_172 , V_172 -> V_189 , V_27 , V_27 -> V_10 ) ;
if ( F_91 ( V_172 ) ) {
V_198 . V_206 = V_196 ;
V_198 . V_22 = F_83 ( V_19 , V_27 -> V_76 ) ;
V_198 . V_207 = V_27 -> V_76 ;
V_198 . V_144 = V_27 -> V_88 - V_27 -> V_76 ;
if ( ! F_102 ( & V_198 ) ) {
V_199 = true ;
F_103 ( V_196 , V_198 . V_208 ,
sizeof( V_196 ) ) ;
}
} else if ( F_104 ( V_172 ) ) {
char V_105 [ V_209 ] ;
if ( F_105 ( V_172 , V_196 ,
V_105 , sizeof( V_105 ) ) < 0 )
goto V_210;
strcpy ( V_196 , V_105 ) ;
}
snprintf ( V_195 , sizeof( V_195 ) ,
L_48 V_29
L_49 V_29
L_50 ,
V_211 ? V_211 : L_51 ,
V_212 ? L_52 : L_43 ,
V_212 ? V_212 : L_43 ,
F_83 ( V_19 , V_27 -> V_76 ) ,
F_83 ( V_19 , V_27 -> V_88 ) ,
V_69 . V_213 ? L_43 : L_53 ,
V_69 . V_214 ? L_54 : L_43 ,
V_196 , V_196 ) ;
F_51 ( L_55 , V_195 ) ;
V_96 = - 1 ;
if ( F_106 ( V_200 ) < 0 ) {
F_101 ( L_56 , V_195 ) ;
goto V_215;
}
V_203 = F_107 () ;
if ( V_203 < 0 ) {
F_101 ( L_57 , V_195 ) ;
goto V_216;
}
if ( V_203 == 0 ) {
F_108 ( V_200 [ 0 ] ) ;
F_109 ( V_200 [ 1 ] , 1 ) ;
F_108 ( V_200 [ 1 ] ) ;
F_110 ( L_58 , L_59 , L_60 , V_195 , NULL ) ;
perror ( V_195 ) ;
exit ( - 1 ) ;
}
F_108 ( V_200 [ 1 ] ) ;
V_161 = fdopen ( V_200 [ 0 ] , L_61 ) ;
if ( ! V_161 ) {
F_101 ( L_62 , V_195 ) ;
goto V_215;
}
V_202 = 0 ;
while ( ! feof ( V_161 ) ) {
if ( F_80 ( V_27 , V_19 , V_1 , V_161 , V_107 ,
& V_201 ) < 0 )
break;
V_202 ++ ;
}
if ( V_202 == 0 )
F_101 ( L_63 , V_195 ) ;
if ( F_91 ( V_172 ) )
F_111 ( V_27 ) ;
fclose ( V_161 ) ;
V_96 = 0 ;
V_215:
F_108 ( V_200 [ 0 ] ) ;
if ( F_104 ( V_172 ) )
F_112 ( V_196 ) ;
if ( V_199 )
F_113 ( & V_198 ) ;
V_210:
return V_96 ;
V_216:
F_108 ( V_200 [ 1 ] ) ;
goto V_215;
}
static void F_114 ( struct V_217 * V_218 , struct V_117 * V_118 )
{
struct V_117 * V_219 ;
struct V_220 * * V_136 = & V_218 -> V_220 ;
struct V_220 * V_221 = NULL ;
int V_153 , V_222 ;
while ( * V_136 != NULL ) {
V_221 = * V_136 ;
V_219 = F_115 ( V_221 , struct V_117 , V_113 ) ;
V_222 = strcmp ( V_219 -> V_115 , V_118 -> V_115 ) ;
if ( V_222 == 0 ) {
for ( V_153 = 0 ; V_153 < V_118 -> V_123 ; V_153 ++ )
V_219 -> V_122 [ V_153 ] . V_223 += V_118 -> V_122 [ V_153 ] . V_120 ;
return;
}
if ( V_222 < 0 )
V_136 = & ( * V_136 ) -> V_224 ;
else
V_136 = & ( * V_136 ) -> V_225 ;
}
for ( V_153 = 0 ; V_153 < V_118 -> V_123 ; V_153 ++ )
V_118 -> V_122 [ V_153 ] . V_223 = V_118 -> V_122 [ V_153 ] . V_120 ;
F_116 ( & V_118 -> V_113 , V_221 , V_136 ) ;
F_117 ( & V_118 -> V_113 , V_218 ) ;
}
static int F_118 ( struct V_117 * V_51 , struct V_117 * V_52 )
{
int V_153 ;
for ( V_153 = 0 ; V_153 < V_51 -> V_123 ; V_153 ++ ) {
if ( V_51 -> V_122 [ V_153 ] . V_223 == V_52 -> V_122 [ V_153 ] . V_223 )
continue;
return V_51 -> V_122 [ V_153 ] . V_223 > V_52 -> V_122 [ V_153 ] . V_223 ;
}
return 0 ;
}
static void F_119 ( struct V_217 * V_218 , struct V_117 * V_118 )
{
struct V_117 * V_219 ;
struct V_220 * * V_136 = & V_218 -> V_220 ;
struct V_220 * V_221 = NULL ;
while ( * V_136 != NULL ) {
V_221 = * V_136 ;
V_219 = F_115 ( V_221 , struct V_117 , V_113 ) ;
if ( F_118 ( V_118 , V_219 ) )
V_136 = & ( * V_136 ) -> V_224 ;
else
V_136 = & ( * V_136 ) -> V_225 ;
}
F_116 ( & V_118 -> V_113 , V_221 , V_136 ) ;
F_117 ( & V_118 -> V_113 , V_218 ) ;
}
static void F_120 ( struct V_217 * V_226 , struct V_217 * V_227 )
{
struct V_117 * V_118 ;
struct V_220 * V_113 ;
V_113 = F_121 ( V_227 ) ;
while ( V_113 ) {
struct V_220 * V_156 ;
V_118 = F_115 ( V_113 , struct V_117 , V_113 ) ;
V_156 = F_122 ( V_113 ) ;
F_123 ( V_113 , V_227 ) ;
F_119 ( V_226 , V_118 ) ;
V_113 = V_156 ;
}
}
static void F_124 ( struct V_26 * V_27 , int V_144 )
{
struct V_63 * V_64 = F_41 ( V_27 ) ;
struct V_117 * V_118 = V_64 -> V_68 -> V_119 ;
T_1 V_121 ;
int V_153 ;
V_121 = sizeof( * V_118 ) +
( sizeof( V_118 -> V_122 ) * ( V_118 -> V_123 - 1 ) ) ;
for ( V_153 = 0 ; V_153 < V_144 ; V_153 ++ ) {
F_125 ( V_118 -> V_115 ) ;
V_118 = ( void * ) V_118 + V_121 ;
}
F_6 ( & V_64 -> V_68 -> V_119 ) ;
}
static int F_126 ( struct V_26 * V_27 , struct V_19 * V_19 ,
struct V_142 * V_143 ,
struct V_217 * V_218 , int V_144 )
{
T_2 V_76 ;
int V_153 , V_228 ;
int V_84 = V_143 -> V_158 ;
struct V_117 * V_118 ;
struct V_63 * V_64 = F_41 ( V_27 ) ;
struct V_67 * V_85 = F_52 ( V_64 , V_84 ) ;
struct V_217 V_229 = V_230 ;
int V_123 = 1 ;
T_2 V_231 = V_85 -> V_90 ;
T_1 V_121 = sizeof( struct V_117 ) ;
if ( F_75 ( V_143 ) ) {
for ( V_153 = 1 ; V_153 < V_143 -> V_157 ; V_153 ++ ) {
V_85 = F_52 ( V_64 , V_84 + V_153 ) ;
V_231 += V_85 -> V_90 ;
}
V_123 = V_143 -> V_157 ;
V_121 += ( V_123 - 1 ) * sizeof( V_118 -> V_122 ) ;
}
if ( ! V_231 )
return 0 ;
V_118 = V_64 -> V_68 -> V_119 = calloc ( V_144 , V_121 ) ;
if ( ! V_64 -> V_68 -> V_119 )
return - 1 ;
V_76 = F_83 ( V_19 , V_27 -> V_76 ) ;
for ( V_153 = 0 ; V_153 < V_144 ; V_153 ++ ) {
T_2 V_34 , V_116 ;
double V_232 = 0.0 ;
V_118 -> V_123 = V_123 ;
for ( V_228 = 0 ; V_228 < V_123 ; V_228 ++ ) {
double V_120 = 0.0 ;
V_85 = F_52 ( V_64 , V_84 + V_228 ) ;
V_116 = V_85 -> V_22 [ V_153 ] ;
if ( V_85 -> V_90 )
V_120 = 100.0 * V_116 / V_85 -> V_90 ;
if ( V_120 > V_232 )
V_232 = V_120 ;
V_118 -> V_122 [ V_228 ] . V_120 = V_120 ;
V_118 -> V_122 [ V_228 ] . V_124 = V_116 ;
}
if ( V_232 <= 0.5 )
goto V_156;
V_34 = V_76 + V_153 ;
V_118 -> V_115 = F_127 ( V_19 -> V_172 , V_34 , NULL ,
false , true ) ;
F_114 ( & V_229 , V_118 ) ;
V_156:
V_118 = ( void * ) V_118 + V_121 ;
}
F_120 ( V_218 , & V_229 ) ;
return 0 ;
}
static void F_128 ( struct V_217 * V_218 , const char * V_178 )
{
struct V_117 * V_118 ;
struct V_220 * V_113 ;
printf ( L_64 , V_178 ) ;
printf ( L_65 ) ;
if ( F_129 ( V_218 ) ) {
printf ( L_66 , V_233 ) ;
return;
}
V_113 = F_121 ( V_218 ) ;
while ( V_113 ) {
double V_120 , V_232 = 0.0 ;
const char * V_155 ;
char * V_115 ;
int V_153 ;
V_118 = F_115 ( V_113 , struct V_117 , V_113 ) ;
for ( V_153 = 0 ; V_153 < V_118 -> V_123 ; V_153 ++ ) {
V_120 = V_118 -> V_122 [ V_153 ] . V_223 ;
V_155 = F_77 ( V_120 ) ;
F_78 ( stdout , V_155 , L_28 , V_120 ) ;
if ( V_120 > V_232 )
V_232 = V_120 ;
}
V_115 = V_118 -> V_115 ;
V_155 = F_77 ( V_232 ) ;
F_78 ( stdout , V_155 , L_67 , V_115 ) ;
V_113 = F_122 ( V_113 ) ;
}
}
static void F_130 ( struct V_26 * V_27 , struct V_142 * V_143 )
{
struct V_63 * V_64 = F_41 ( V_27 ) ;
struct V_67 * V_85 = F_52 ( V_64 , V_143 -> V_158 ) ;
T_2 V_144 = F_42 ( V_27 ) , V_34 ;
for ( V_34 = 0 ; V_34 < V_144 ; ++ V_34 )
if ( V_85 -> V_22 [ V_34 ] != 0 )
printf ( L_68 V_29 L_69 V_91 L_10 , V_234 / 2 ,
V_27 -> V_76 + V_34 , V_85 -> V_22 [ V_34 ] ) ;
printf ( L_70 V_91 L_10 , V_234 / 2 , L_71 , V_85 -> V_90 ) ;
}
int F_131 ( struct V_26 * V_27 , struct V_19 * V_19 ,
struct V_142 * V_143 , bool V_235 ,
int V_145 , int V_146 , int V_236 )
{
struct V_172 * V_172 = V_19 -> V_172 ;
char * V_178 ;
const char * V_237 ;
const char * V_238 = F_132 ( V_143 ) ;
struct V_63 * V_64 = F_41 ( V_27 ) ;
struct V_67 * V_85 = F_52 ( V_64 , V_143 -> V_158 ) ;
struct V_102 * V_114 , * V_147 = NULL ;
T_2 V_76 = F_83 ( V_19 , V_27 -> V_76 ) ;
int V_45 = 2 , V_239 = 0 ;
int V_240 = 0 ;
T_2 V_144 ;
int V_160 = 8 ;
int V_241 ;
V_178 = F_3 ( V_172 -> V_189 ) ;
if ( ! V_178 )
return - V_92 ;
if ( V_235 )
V_237 = V_178 ;
else
V_237 = F_133 ( V_178 ) ;
V_144 = F_42 ( V_27 ) ;
if ( F_75 ( V_143 ) )
V_160 *= V_143 -> V_157 ;
V_241 = printf ( L_72 V_91 L_73 ,
V_160 , V_160 , L_74 , V_237 , V_238 , V_85 -> V_90 ) ;
printf ( L_75 ,
V_241 , V_241 , V_242 ) ;
if ( V_243 > 0 )
F_130 ( V_27 , V_143 ) ;
F_134 (pos, &notes->src->source, node) {
if ( V_236 && V_147 == NULL ) {
V_147 = V_114 ;
V_239 = 0 ;
}
switch ( F_74 ( V_114 , V_27 , V_76 , V_143 , V_144 ,
V_145 , V_45 , V_146 ,
V_147 ) ) {
case 0 :
++ V_45 ;
if ( V_236 ) {
V_45 += V_239 ;
V_147 = NULL ;
V_239 = 0 ;
}
break;
case 1 :
++ V_240 ;
break;
case - 1 :
default:
if ( ! V_236 )
break;
if ( V_239 == V_236 )
V_147 = F_135 ( V_147 -> V_113 . V_156 , F_136 ( * V_147 ) , V_113 ) ;
else
++ V_239 ;
break;
}
}
free ( V_178 ) ;
return V_240 ;
}
void F_137 ( struct V_26 * V_27 , int V_84 )
{
struct V_63 * V_64 = F_41 ( V_27 ) ;
struct V_67 * V_85 = F_52 ( V_64 , V_84 ) ;
memset ( V_85 , 0 , V_64 -> V_68 -> V_65 ) ;
}
void F_138 ( struct V_26 * V_27 , int V_84 )
{
struct V_63 * V_64 = F_41 ( V_27 ) ;
struct V_67 * V_85 = F_52 ( V_64 , V_84 ) ;
int V_144 = F_42 ( V_27 ) , V_34 ;
V_85 -> V_90 = 0 ;
for ( V_34 = 0 ; V_34 < V_144 ; ++ V_34 ) {
V_85 -> V_22 [ V_34 ] = V_85 -> V_22 [ V_34 ] * 7 / 8 ;
V_85 -> V_90 += V_85 -> V_22 [ V_34 ] ;
}
}
void F_139 ( struct V_111 * V_112 )
{
struct V_102 * V_114 , * V_244 ;
F_140 (pos, n, head, node) {
F_141 ( & V_114 -> V_113 ) ;
F_62 ( V_114 ) ;
}
}
static T_1 F_142 ( struct V_102 * V_103 , T_4 * V_245 )
{
T_1 V_45 ;
if ( V_103 -> V_34 == - 1 )
return fprintf ( V_245 , L_76 , V_103 -> line ) ;
V_45 = fprintf ( V_245 , L_14 V_29 L_26 , V_103 -> V_34 , V_103 -> V_2 . V_10 ) ;
if ( V_103 -> V_12 . V_15 [ 0 ] != '\0' ) {
V_45 += fprintf ( V_245 , L_77 , 6 - ( int ) V_45 , L_34 ,
V_103 -> V_12 . V_15 ) ;
}
return V_45 + fprintf ( V_245 , L_10 ) ;
}
T_1 F_143 ( struct V_111 * V_112 , T_4 * V_245 )
{
struct V_102 * V_114 ;
T_1 V_45 = 0 ;
F_134 (pos, head, node)
V_45 += F_142 ( V_114 , V_245 ) ;
return V_45 ;
}
int F_144 ( struct V_26 * V_27 , struct V_19 * V_19 ,
struct V_142 * V_143 , bool V_246 ,
bool V_235 , int V_145 , int V_146 )
{
struct V_172 * V_172 = V_19 -> V_172 ;
struct V_217 V_117 = V_230 ;
T_2 V_144 ;
if ( F_100 ( V_27 , V_19 , F_145 ( V_143 ) ,
0 , NULL ) < 0 )
return - 1 ;
V_144 = F_42 ( V_27 ) ;
if ( V_246 ) {
V_247 = V_235 ;
F_126 ( V_27 , V_19 , V_143 , & V_117 , V_144 ) ;
F_128 ( & V_117 , V_172 -> V_189 ) ;
}
F_131 ( V_27 , V_19 , V_143 , V_235 ,
V_145 , V_146 , 0 ) ;
if ( V_246 )
F_124 ( V_27 , V_144 ) ;
F_139 ( & F_41 ( V_27 ) -> V_68 -> V_14 ) ;
return 0 ;
}
bool F_146 ( void )
{
return V_248 == 1 && V_249 . V_27 ;
}
