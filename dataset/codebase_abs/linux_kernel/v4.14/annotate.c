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
bool F_10 ( struct V_1 * V_1 , const char * V_19 , const char * V_20 )
{
if ( ! V_1 || ! V_1 -> V_21 )
return false ;
return V_1 -> V_21 ( V_1 , V_19 , V_20 ) ;
}
static int F_11 ( struct V_1 * V_1 , struct V_13 * V_12 , struct V_22 * V_22 )
{
char * V_23 , * V_24 , * V_10 ;
V_12 -> V_16 . V_25 = F_12 ( V_12 -> V_15 , & V_23 , 16 ) ;
V_10 = strchr ( V_23 , '<' ) ;
if ( V_10 == NULL )
goto V_26;
V_10 ++ ;
if ( V_1 -> V_27 . V_28 &&
strchr ( V_10 , V_1 -> V_27 . V_28 ) )
return - 1 ;
V_24 = strchr ( V_10 , '>' ) ;
if ( V_24 == NULL )
return - 1 ;
* V_24 = '\0' ;
V_12 -> V_16 . V_10 = F_3 ( V_10 ) ;
* V_24 = '>' ;
return V_12 -> V_16 . V_10 == NULL ? - 1 : 0 ;
V_26:
V_24 = strchr ( V_23 , '*' ) ;
if ( V_24 == NULL ) {
struct V_29 * V_30 = F_13 ( V_22 , V_22 -> V_31 ( V_22 , V_12 -> V_16 . V_25 ) ) ;
if ( V_30 != NULL )
V_12 -> V_16 . V_10 = F_3 ( V_30 -> V_10 ) ;
else
V_12 -> V_16 . V_25 = 0 ;
return 0 ;
}
V_12 -> V_16 . V_25 = F_12 ( V_24 + 1 , NULL , 16 ) ;
return 0 ;
}
static int F_14 ( struct V_2 * V_2 , char * V_17 , T_1 V_18 ,
struct V_13 * V_12 )
{
if ( V_12 -> V_16 . V_10 )
return F_8 ( V_17 , V_18 , L_1 , V_2 -> V_10 , V_12 -> V_16 . V_10 ) ;
if ( V_12 -> V_16 . V_25 == 0 )
return F_7 ( V_2 , V_17 , V_18 , V_12 ) ;
return F_8 ( V_17 , V_18 , L_2 V_32 , V_2 -> V_10 , V_12 -> V_16 . V_25 ) ;
}
bool F_15 ( const struct V_2 * V_2 )
{
return V_2 -> V_12 == & V_33 ;
}
static int F_16 ( struct V_1 * V_1 V_34 , struct V_13 * V_12 , struct V_22 * V_22 V_34 )
{
const char * V_35 = strchr ( V_12 -> V_15 , '+' ) ;
const char * V_36 = strchr ( V_12 -> V_15 , ',' ) ;
if ( V_36 ++ != NULL ) {
V_12 -> V_16 . V_25 = F_12 ( V_36 , NULL , 16 ) ;
if ( ! V_12 -> V_16 . V_25 ) {
V_36 = strchr ( V_36 , ',' ) ;
if ( V_36 ++ != NULL )
V_12 -> V_16 . V_25 = F_12 ( V_36 , NULL , 16 ) ;
}
} else {
V_12 -> V_16 . V_25 = F_12 ( V_12 -> V_15 , NULL , 16 ) ;
}
if ( V_35 ++ != NULL ) {
V_12 -> V_16 . V_37 = F_12 ( V_35 , NULL , 16 ) ;
V_12 -> V_16 . V_38 = true ;
} else {
V_12 -> V_16 . V_38 = false ;
}
return 0 ;
}
static int F_17 ( struct V_2 * V_2 , char * V_17 , T_1 V_18 ,
struct V_13 * V_12 )
{
const char * V_36 = strchr ( V_12 -> V_15 , ',' ) ;
if ( ! V_12 -> V_16 . V_25 || V_12 -> V_16 . V_37 < 0 )
return F_7 ( V_2 , V_17 , V_18 , V_12 ) ;
if ( V_36 != NULL ) {
const char * V_39 = strchr ( V_36 + 1 , ',' ) ;
if ( V_39 != NULL )
V_36 = V_39 ;
V_36 ++ ;
if ( * V_36 == ' ' )
V_36 ++ ;
}
return F_8 ( V_17 , V_18 , L_3 V_32 ,
V_2 -> V_10 , V_36 ? V_36 - V_12 -> V_15 : 0 , V_12 -> V_15 ,
V_12 -> V_16 . V_37 ) ;
}
bool F_18 ( const struct V_2 * V_2 )
{
return V_2 -> V_12 == & V_40 ;
}
static int F_19 ( char * V_15 , char * V_41 , T_2 * V_42 , char * * V_43 )
{
char * V_23 , * V_10 , * V_44 ;
if ( strstr ( V_15 , L_4 ) == NULL )
return 0 ;
* V_42 = F_12 ( V_41 , & V_23 , 16 ) ;
V_10 = strchr ( V_23 , '<' ) ;
if ( V_10 == NULL )
return - 1 ;
V_10 ++ ;
V_44 = strchr ( V_10 , '>' ) ;
if ( V_44 == NULL )
return 0 ;
* V_44 = '\0' ;
* V_43 = F_3 ( V_10 ) ;
* V_44 = '>' ;
return 0 ;
}
static int F_20 ( struct V_1 * V_1 , struct V_13 * V_12 , struct V_22 * V_22 )
{
V_12 -> V_45 . V_12 = F_21 ( sizeof( * V_12 -> V_45 . V_12 ) ) ;
if ( V_12 -> V_45 . V_12 == NULL )
return 0 ;
if ( F_22 ( V_12 -> V_15 , & V_12 -> V_45 . V_2 . V_10 , & V_12 -> V_45 . V_12 -> V_15 ) < 0 )
goto V_46;
V_12 -> V_45 . V_2 . V_12 = F_23 ( V_1 , V_12 -> V_45 . V_2 . V_10 ) ;
if ( V_12 -> V_45 . V_2 . V_12 == NULL )
goto V_46;
if ( V_12 -> V_45 . V_2 . V_12 -> V_47 &&
V_12 -> V_45 . V_2 . V_12 -> V_47 ( V_1 , V_12 -> V_45 . V_12 , V_22 ) < 0 )
goto V_46;
return 0 ;
V_46:
F_6 ( & V_12 -> V_45 . V_12 ) ;
return 0 ;
}
static int F_24 ( struct V_2 * V_2 , char * V_17 , T_1 V_18 ,
struct V_13 * V_12 )
{
int V_48 ;
if ( V_12 -> V_45 . V_2 . V_12 == NULL )
return F_7 ( V_2 , V_17 , V_18 , V_12 ) ;
V_48 = F_8 ( V_17 , V_18 , L_5 , V_2 -> V_10 ) ;
return V_48 + F_9 ( & V_12 -> V_45 . V_2 , V_17 + V_48 ,
V_18 - V_48 , V_12 -> V_45 . V_12 ) ;
}
static void F_25 ( struct V_13 * V_12 )
{
struct V_2 * V_2 = & V_12 -> V_45 . V_2 ;
if ( V_2 -> V_12 && V_2 -> V_12 -> free )
V_2 -> V_12 -> free ( V_12 -> V_45 . V_12 ) ;
else
F_5 ( V_12 -> V_45 . V_12 ) ;
F_6 ( & V_12 -> V_45 . V_12 ) ;
F_6 ( & V_12 -> V_16 . V_15 ) ;
F_6 ( & V_12 -> V_16 . V_10 ) ;
}
static int F_26 ( struct V_1 * V_1 , struct V_13 * V_12 , struct V_22 * V_22 V_34 )
{
char * V_35 = strchr ( V_12 -> V_15 , ',' ) , * V_16 , * V_41 , V_49 ;
if ( V_35 == NULL )
return - 1 ;
* V_35 = '\0' ;
V_12 -> V_14 . V_15 = F_3 ( V_12 -> V_15 ) ;
* V_35 = ',' ;
if ( V_12 -> V_14 . V_15 == NULL )
return - 1 ;
V_16 = ++ V_35 ;
V_41 = strchr ( V_35 , V_1 -> V_27 . V_50 ) ;
if ( V_41 != NULL )
V_35 = V_41 - 1 ;
else
V_35 = strchr ( V_35 , '\0' ) - 1 ;
while ( V_35 > V_16 && isspace ( V_35 [ 0 ] ) )
-- V_35 ;
V_35 ++ ;
V_49 = * V_35 ;
* V_35 = '\0' ;
V_12 -> V_16 . V_15 = F_3 ( V_16 ) ;
* V_35 = V_49 ;
if ( V_12 -> V_16 . V_15 == NULL )
goto V_51;
if ( V_41 == NULL )
return 0 ;
V_41 = F_27 ( V_41 ) ;
F_19 ( V_12 -> V_14 . V_15 , V_41 , & V_12 -> V_14 . V_25 , & V_12 -> V_14 . V_10 ) ;
F_19 ( V_12 -> V_16 . V_15 , V_41 , & V_12 -> V_16 . V_25 , & V_12 -> V_16 . V_10 ) ;
return 0 ;
V_51:
F_6 ( & V_12 -> V_14 . V_15 ) ;
return - 1 ;
}
static int F_28 ( struct V_2 * V_2 , char * V_17 , T_1 V_18 ,
struct V_13 * V_12 )
{
return F_8 ( V_17 , V_18 , L_6 , V_2 -> V_10 ,
V_12 -> V_14 . V_10 ? : V_12 -> V_14 . V_15 ,
V_12 -> V_16 . V_10 ? : V_12 -> V_16 . V_15 ) ;
}
static int F_29 ( struct V_1 * V_1 V_34 , struct V_13 * V_12 , struct V_22 * V_22 V_34 )
{
char * V_16 , * V_41 , * V_35 , V_49 ;
V_16 = V_35 = V_12 -> V_15 ;
while ( V_35 [ 0 ] != '\0' && ! isspace ( V_35 [ 0 ] ) )
++ V_35 ;
V_49 = * V_35 ;
* V_35 = '\0' ;
V_12 -> V_16 . V_15 = F_3 ( V_16 ) ;
* V_35 = V_49 ;
if ( V_12 -> V_16 . V_15 == NULL )
return - 1 ;
V_41 = strchr ( V_35 , V_1 -> V_27 . V_50 ) ;
if ( V_41 == NULL )
return 0 ;
V_41 = F_27 ( V_41 ) ;
F_19 ( V_12 -> V_16 . V_15 , V_41 , & V_12 -> V_16 . V_25 , & V_12 -> V_16 . V_10 ) ;
return 0 ;
}
static int F_30 ( struct V_2 * V_2 , char * V_17 , T_1 V_18 ,
struct V_13 * V_12 )
{
return F_8 ( V_17 , V_18 , L_1 , V_2 -> V_10 ,
V_12 -> V_16 . V_10 ? : V_12 -> V_16 . V_15 ) ;
}
static int F_31 ( struct V_2 * V_2 V_34 , char * V_17 , T_1 V_18 ,
struct V_13 * V_12 V_34 )
{
return F_8 ( V_17 , V_18 , L_7 , L_8 ) ;
}
bool F_32 ( const struct V_2 * V_2 )
{
return V_2 -> V_12 == & V_52 ;
}
bool F_33 ( const struct V_2 * V_2 )
{
return V_2 -> V_12 == & V_53 ;
}
static int F_34 ( const void * V_10 , const void * V_54 )
{
const struct V_2 * V_2 = V_54 ;
return strcmp ( V_10 , V_2 -> V_10 ) ;
}
static int F_35 ( const void * V_55 , const void * V_56 )
{
const struct V_2 * V_57 = V_55 ;
const struct V_2 * V_58 = V_56 ;
return strcmp ( V_57 -> V_10 , V_58 -> V_10 ) ;
}
static void F_4 ( struct V_1 * V_1 )
{
const int V_59 = V_1 -> V_9 ;
qsort ( V_1 -> V_6 , V_59 , sizeof( struct V_2 ) , F_35 ) ;
}
static struct V_11 * F_36 ( struct V_1 * V_1 , const char * V_10 )
{
struct V_2 * V_2 ;
const int V_59 = V_1 -> V_9 ;
if ( ! V_1 -> V_60 ) {
F_4 ( V_1 ) ;
V_1 -> V_60 = true ;
}
V_2 = bsearch ( V_10 , V_1 -> V_6 , V_59 , sizeof( struct V_2 ) , F_34 ) ;
return V_2 ? V_2 -> V_12 : NULL ;
}
static struct V_11 * F_23 ( struct V_1 * V_1 , const char * V_10 )
{
struct V_11 * V_12 = F_36 ( V_1 , V_10 ) ;
if ( ! V_12 && V_1 -> V_61 )
V_12 = V_1 -> V_61 ( V_1 , V_10 ) ;
return V_12 ;
}
static int F_37 ( const void * V_10 , const void * V_62 )
{
const struct V_1 * V_1 = V_62 ;
return strcmp ( V_10 , V_1 -> V_10 ) ;
}
static int F_38 ( const void * V_55 , const void * V_56 )
{
const struct V_1 * V_63 = V_55 ;
const struct V_1 * V_64 = V_56 ;
return strcmp ( V_63 -> V_10 , V_64 -> V_10 ) ;
}
static void F_39 ( void )
{
const int V_59 = F_40 ( V_65 ) ;
qsort ( V_65 , V_59 , sizeof( struct V_1 ) , F_38 ) ;
}
static struct V_1 * F_41 ( const char * V_10 )
{
const int V_59 = F_40 ( V_65 ) ;
static bool V_66 ;
if ( ! V_66 ) {
F_39 () ;
V_66 = true ;
}
return bsearch ( V_10 , V_65 , V_59 , sizeof( struct V_1 ) , F_37 ) ;
}
int F_42 ( struct V_29 * V_30 )
{
struct V_67 * V_68 = F_43 ( V_30 ) ;
T_1 V_18 = F_44 ( V_30 ) ;
T_1 V_69 ;
if ( V_18 == 0 )
V_18 = 1 ;
if ( V_18 > ( V_70 - sizeof( struct V_71 ) ) / sizeof( struct V_72 ) )
return - 1 ;
V_69 = ( sizeof( struct V_71 ) + V_18 * sizeof( struct V_72 ) ) ;
if ( V_69 > ( V_70 - sizeof( * V_68 -> V_73 ) )
/ V_74 . V_75 )
return - 1 ;
V_68 -> V_73 = F_21 ( sizeof( * V_68 -> V_73 ) + V_74 . V_75 * V_69 ) ;
if ( V_68 -> V_73 == NULL )
return - 1 ;
V_68 -> V_73 -> V_69 = V_69 ;
V_68 -> V_73 -> V_76 = V_74 . V_75 ;
F_45 ( & V_68 -> V_73 -> V_14 ) ;
return 0 ;
}
static int F_46 ( struct V_29 * V_30 )
{
struct V_67 * V_68 = F_43 ( V_30 ) ;
const T_1 V_18 = F_44 ( V_30 ) ;
V_68 -> V_73 -> V_77 = calloc ( V_18 , sizeof( struct V_78 ) ) ;
if ( V_68 -> V_73 -> V_77 == NULL )
return - 1 ;
return 0 ;
}
void F_47 ( struct V_29 * V_30 )
{
struct V_67 * V_68 = F_43 ( V_30 ) ;
F_48 ( & V_68 -> V_79 ) ;
if ( V_68 -> V_73 != NULL ) {
memset ( V_68 -> V_73 -> V_80 , 0 ,
V_68 -> V_73 -> V_76 * V_68 -> V_73 -> V_69 ) ;
if ( V_68 -> V_73 -> V_77 )
memset ( V_68 -> V_73 -> V_77 , 0 ,
F_44 ( V_30 ) * sizeof( struct V_78 ) ) ;
}
F_49 ( & V_68 -> V_79 ) ;
}
static int F_50 ( struct V_67 * V_68 ,
T_2 V_81 ,
unsigned V_37 , unsigned V_82 ,
unsigned V_83 )
{
struct V_78 * V_84 ;
V_84 = V_68 -> V_73 -> V_77 ;
V_84 [ V_37 ] . V_85 ++ ;
V_84 [ V_37 ] . V_86 += V_82 ;
if ( ! V_83 && V_84 [ V_37 ] . V_83 )
return 0 ;
if ( V_84 [ V_37 ] . V_87 ) {
if ( V_83 && ( ! V_84 [ V_37 ] . V_83 ||
V_84 [ V_37 ] . V_81 > V_81 ) ) {
V_84 [ V_37 ] . V_83 = 0 ;
V_84 [ V_37 ] . V_82 = 0 ;
V_84 [ V_37 ] . V_87 = 0 ;
if ( V_84 [ V_37 ] . V_88 < 0xffff )
V_84 [ V_37 ] . V_88 ++ ;
} else if ( V_83 &&
V_84 [ V_37 ] . V_81 < V_81 )
return 0 ;
}
V_84 [ V_37 ] . V_83 = V_83 ;
V_84 [ V_37 ] . V_81 = V_81 ;
V_84 [ V_37 ] . V_82 += V_82 ;
V_84 [ V_37 ] . V_87 ++ ;
return 0 ;
}
static int F_51 ( struct V_29 * V_30 , struct V_22 * V_22 ,
struct V_67 * V_68 , int V_89 , T_2 V_25 ,
struct V_90 * V_91 )
{
unsigned V_37 ;
struct V_71 * V_92 ;
F_52 ( L_9 V_32 L_10 , V_93 , V_22 -> V_94 ( V_22 , V_25 ) ) ;
if ( ( V_25 < V_30 -> V_81 || V_25 >= V_30 -> V_95 ) &&
( V_25 != V_30 -> V_95 || V_30 -> V_81 != V_30 -> V_95 ) ) {
F_53 ( L_11 V_32 L_12 V_32 L_13 V_32 L_10 ,
V_93 , __LINE__ , V_30 -> V_10 , V_30 -> V_81 , V_25 , V_30 -> V_95 ) ;
return - V_96 ;
}
V_37 = V_25 - V_30 -> V_81 ;
V_92 = F_54 ( V_68 , V_89 ) ;
V_92 -> V_97 ++ ;
V_92 -> V_25 [ V_37 ] . V_97 ++ ;
V_92 -> V_98 += V_91 -> V_98 ;
V_92 -> V_25 [ V_37 ] . V_98 += V_91 -> V_98 ;
F_52 ( L_14 V_32 L_15 V_32 L_16 V_32
L_17 V_99 L_18 V_99 L_10 ,
V_30 -> V_81 , V_30 -> V_10 , V_25 , V_25 - V_30 -> V_81 , V_89 ,
V_92 -> V_25 [ V_37 ] . V_97 , V_92 -> V_25 [ V_37 ] . V_98 ) ;
return 0 ;
}
static struct V_67 * F_55 ( struct V_29 * V_30 , bool V_82 )
{
struct V_67 * V_68 = F_43 ( V_30 ) ;
if ( V_68 -> V_73 == NULL ) {
if ( F_42 ( V_30 ) < 0 )
return NULL ;
}
if ( ! V_68 -> V_73 -> V_77 && V_82 ) {
if ( F_46 ( V_30 ) < 0 )
return NULL ;
}
return V_68 ;
}
static int F_56 ( struct V_29 * V_30 , struct V_22 * V_22 ,
int V_89 , T_2 V_25 ,
struct V_90 * V_91 )
{
struct V_67 * V_68 ;
if ( V_30 == NULL )
return 0 ;
V_68 = F_55 ( V_30 , false ) ;
if ( V_68 == NULL )
return - V_100 ;
return F_51 ( V_30 , V_22 , V_68 , V_89 , V_25 , V_91 ) ;
}
static int F_57 ( T_2 V_25 , T_2 V_81 ,
struct V_29 * V_30 , unsigned V_82 )
{
struct V_67 * V_68 ;
unsigned V_37 ;
if ( V_30 == NULL )
return 0 ;
V_68 = F_55 ( V_30 , true ) ;
if ( V_68 == NULL )
return - V_100 ;
if ( V_25 < V_30 -> V_81 || V_25 >= V_30 -> V_95 )
return - V_96 ;
if ( V_81 ) {
if ( V_81 < V_30 -> V_81 || V_81 >= V_30 -> V_95 )
return - V_96 ;
if ( V_81 >= V_25 )
V_81 = 0 ;
}
V_37 = V_25 - V_30 -> V_81 ;
return F_50 ( V_68 ,
V_81 ? V_81 - V_30 -> V_81 : 0 ,
V_37 , V_82 ,
! ! V_81 ) ;
}
int F_58 ( struct V_101 * V_102 ,
struct V_101 * V_81 ,
unsigned V_82 )
{
T_2 V_103 = 0 ;
int V_104 ;
if ( ! V_82 )
return 0 ;
if ( V_81 &&
( V_81 -> V_30 == V_102 -> V_30 ||
( V_102 -> V_30 &&
V_81 -> V_25 == V_102 -> V_30 -> V_81 + V_102 -> V_22 -> V_81 ) ) )
V_103 = V_81 -> V_105 ;
if ( V_103 == 0 )
F_59 ( L_19 V_32 L_20 V_32 L_21 V_32 L_22 V_32 L_10 ,
V_102 -> V_25 ,
V_81 ? V_81 -> V_25 : 0 ,
V_102 -> V_30 ? V_102 -> V_30 -> V_81 + V_102 -> V_22 -> V_81 : 0 ,
V_103 ) ;
V_104 = F_57 ( V_102 -> V_105 , V_103 , V_102 -> V_30 , V_82 ) ;
if ( V_104 )
F_59 ( L_23 , V_104 ) ;
return V_104 ;
}
int F_60 ( struct V_101 * V_102 , struct V_90 * V_91 ,
int V_89 )
{
return F_56 ( V_102 -> V_30 , V_102 -> V_22 , V_89 , V_102 -> V_105 , V_91 ) ;
}
int F_61 ( struct V_106 * V_107 , struct V_90 * V_91 ,
int V_89 , T_2 V_108 )
{
return F_56 ( V_107 -> V_109 . V_30 , V_107 -> V_109 . V_22 , V_89 , V_108 , V_91 ) ;
}
static void F_62 ( struct V_110 * V_111 , struct V_1 * V_1 , struct V_22 * V_22 )
{
V_111 -> V_2 . V_12 = F_23 ( V_1 , V_111 -> V_2 . V_10 ) ;
if ( ! V_111 -> V_2 . V_12 )
return;
if ( V_111 -> V_2 . V_12 -> V_47 && V_111 -> V_2 . V_12 -> V_47 ( V_1 , & V_111 -> V_12 , V_22 ) < 0 )
V_111 -> V_2 . V_12 = NULL ;
}
static int F_22 ( char * line , const char * * V_43 , char * * V_112 )
{
char V_113 , * V_10 = F_27 ( line ) ;
if ( V_10 [ 0 ] == '\0' )
return - 1 ;
* V_112 = V_10 + 1 ;
while ( ( * V_112 ) [ 0 ] != '\0' && ! isspace ( ( * V_112 ) [ 0 ] ) )
++ * V_112 ;
V_113 = ( * V_112 ) [ 0 ] ;
( * V_112 ) [ 0 ] = '\0' ;
* V_43 = F_3 ( V_10 ) ;
if ( * V_43 == NULL )
goto V_114;
( * V_112 ) [ 0 ] = V_113 ;
* V_112 = F_27 ( * V_112 ) ;
return 0 ;
V_114:
free ( ( void * ) V_43 ) ;
* V_43 = NULL ;
return - 1 ;
}
static struct V_110 * F_63 ( T_3 V_37 , char * line ,
T_1 V_115 , int V_116 ,
struct V_1 * V_1 ,
struct V_22 * V_22 )
{
struct V_110 * V_111 = F_21 ( sizeof( * V_111 ) + V_115 ) ;
if ( V_111 != NULL ) {
V_111 -> V_37 = V_37 ;
V_111 -> line = F_3 ( line ) ;
V_111 -> V_116 = V_116 ;
if ( V_111 -> line == NULL )
goto V_117;
if ( V_37 != - 1 ) {
if ( F_22 ( V_111 -> line , & V_111 -> V_2 . V_10 , & V_111 -> V_12 . V_15 ) < 0 )
goto V_118;
F_62 ( V_111 , V_1 , V_22 ) ;
}
}
return V_111 ;
V_118:
F_6 ( & V_111 -> line ) ;
V_117:
free ( V_111 ) ;
return NULL ;
}
void F_64 ( struct V_110 * V_111 )
{
F_6 ( & V_111 -> line ) ;
if ( V_111 -> V_2 . V_12 && V_111 -> V_2 . V_12 -> free )
V_111 -> V_2 . V_12 -> free ( & V_111 -> V_12 ) ;
else
F_5 ( & V_111 -> V_12 ) ;
free ( ( void * ) V_111 -> V_2 . V_10 ) ;
V_111 -> V_2 . V_10 = NULL ;
free ( V_111 ) ;
}
int F_65 ( struct V_110 * V_111 , char * V_17 , T_1 V_18 , bool V_15 )
{
if ( V_15 || ! V_111 -> V_2 . V_12 )
return F_8 ( V_17 , V_18 , L_1 , V_111 -> V_2 . V_10 , V_111 -> V_12 . V_15 ) ;
return F_9 ( & V_111 -> V_2 , V_17 , V_18 , & V_111 -> V_12 ) ;
}
static void F_66 ( struct V_119 * V_120 , struct V_110 * line )
{
F_67 ( & line -> V_121 , V_120 ) ;
}
struct V_110 * F_68 ( struct V_119 * V_120 , struct V_110 * V_122 )
{
F_69 (pos, head, node)
if ( V_122 -> V_37 >= 0 )
return V_122 ;
return NULL ;
}
double F_70 ( struct V_67 * V_68 , int V_89 , T_3 V_37 ,
T_3 V_95 , const char * * V_123 , struct V_72 * V_91 )
{
struct V_124 * V_125 = V_68 -> V_73 -> V_126 ;
double V_127 = 0.0 ;
V_91 -> V_97 = V_91 -> V_98 = 0 ;
if ( V_125 ) {
T_1 V_128 = sizeof( * V_125 ) +
sizeof( V_125 -> V_129 ) * ( V_125 -> V_130 - 1 ) ;
while ( V_37 < V_95 ) {
V_125 = ( void * ) V_68 -> V_73 -> V_126 +
( V_128 * V_37 ) ;
if ( * V_123 == NULL )
* V_123 = V_125 -> V_123 ;
V_127 += V_125 -> V_129 [ V_89 ] . V_127 ;
V_91 -> V_97 += V_125 -> V_129 [ V_89 ] . V_131 ;
V_37 ++ ;
}
} else {
struct V_71 * V_92 = F_54 ( V_68 , V_89 ) ;
unsigned int V_132 = 0 ;
T_2 V_98 = 0 ;
while ( V_37 < V_95 ) {
V_132 += V_92 -> V_25 [ V_37 ] . V_97 ;
V_98 += V_92 -> V_25 [ V_37 ] . V_98 ;
++ V_37 ;
}
if ( V_92 -> V_97 ) {
V_91 -> V_98 = V_98 ;
V_91 -> V_97 = V_132 ;
V_127 = 100.0 * V_132 / V_92 -> V_97 ;
}
}
return V_127 ;
}
static const char * F_71 ( struct V_133 * V_134 )
{
double V_135 = F_72 ( V_134 ) ;
if ( V_135 >= 0 ) {
if ( V_135 > 0.75 )
return V_136 ;
if ( V_135 < 0.01 )
return V_137 ;
}
return V_138 ;
}
static const char * F_73 ( struct V_133 * V_134 )
{
double V_135 = F_72 ( V_134 ) ;
if ( V_135 >= 0 ) {
if ( V_135 < 0.01 )
return V_137 ;
}
return V_139 ;
}
static void F_74 ( struct V_133 * V_134 , T_2 V_25 )
{
bool V_140 = true ;
if ( ! V_134 )
return;
#if 1
if ( V_134 -> V_141 && V_134 -> V_81 == V_25 ) {
struct V_133 * V_142 = V_134 ;
double V_143 ;
while ( ! V_142 -> V_144 )
V_142 = F_75 ( V_142 ) ;
V_143 = 100 * ( double ) V_134 -> V_145 / V_142 -> V_146 ;
if ( V_143 > 0.1 ) {
if ( V_140 ) {
V_140 = false ;
printf ( L_24 ) ;
}
printf ( L_25 , V_143 ) ;
}
}
#endif
if ( V_134 -> V_144 && V_134 -> V_95 == V_25 ) {
double V_143 = 100 * ( double ) V_134 -> V_147 / V_134 -> V_146 ;
if ( V_143 > 0.1 ) {
if ( V_140 ) {
V_140 = false ;
printf ( L_24 ) ;
}
printf ( L_26 , V_143 , 100 * ( double ) V_134 -> V_148 / V_134 -> V_147 ) ;
}
}
}
static int F_76 ( struct V_110 * V_111 , struct V_29 * V_30 , T_2 V_81 ,
struct V_149 * V_150 , T_2 V_151 , int V_152 , int V_48 ,
int V_153 , struct V_110 * V_154 )
{
static const char * V_155 ;
static const char * V_156 ;
if ( V_111 -> V_37 != - 1 ) {
const char * V_123 = NULL ;
double V_127 , V_157 = 0.0 ;
double * V_158 = & V_127 ;
struct V_72 V_91 ;
struct V_72 * V_159 = & V_91 ;
int V_160 , V_161 = 1 ;
const char * V_162 ;
struct V_67 * V_68 = F_43 ( V_30 ) ;
T_3 V_37 = V_111 -> V_37 ;
const T_2 V_25 = V_81 + V_37 ;
struct V_110 * V_163 ;
struct V_133 * V_134 ;
V_163 = F_68 ( & V_68 -> V_73 -> V_14 , V_111 ) ;
if ( F_77 ( V_150 ) ) {
V_161 = V_150 -> V_164 ;
V_158 = calloc ( V_161 , sizeof( double ) ) ;
V_159 = calloc ( V_161 , sizeof( struct V_72 ) ) ;
if ( V_158 == NULL || V_159 == NULL ) {
return - 1 ;
}
}
for ( V_160 = 0 ; V_160 < V_161 ; V_160 ++ ) {
V_127 = F_70 ( V_68 ,
V_68 -> V_73 -> V_126 ? V_160 : V_150 -> V_165 + V_160 ,
V_37 ,
V_163 ? V_163 -> V_37 : ( T_3 ) V_151 ,
& V_123 , & V_91 ) ;
V_158 [ V_160 ] = V_127 ;
V_159 [ V_160 ] = V_91 ;
if ( V_127 > V_157 )
V_157 = V_127 ;
}
if ( V_157 < V_152 )
return - 1 ;
if ( V_153 && V_48 >= V_153 )
return 1 ;
if ( V_154 != NULL ) {
F_78 (queue, &notes->src->source, node) {
if ( V_154 == V_111 )
break;
F_76 ( V_154 , V_30 , V_81 , V_150 , V_151 ,
0 , 0 , 1 , NULL ) ;
}
}
V_162 = F_79 ( V_157 ) ;
if ( V_123 ) {
if ( ! V_155 || strcmp ( V_155 , V_123 )
|| V_162 != V_156 ) {
F_80 ( stdout , V_162 , L_27 , V_123 ) ;
V_155 = V_123 ;
V_156 = V_162 ;
}
}
for ( V_160 = 0 ; V_160 < V_161 ; V_160 ++ ) {
V_127 = V_158 [ V_160 ] ;
V_91 = V_159 [ V_160 ] ;
V_162 = F_79 ( V_127 ) ;
if ( V_74 . V_166 )
F_80 ( stdout , V_162 , L_28 V_99 ,
V_91 . V_98 ) ;
else if ( V_74 . V_167 )
F_80 ( stdout , V_162 , L_29 V_99 ,
V_91 . V_97 ) ;
else
F_80 ( stdout , V_162 , L_30 , V_127 ) ;
}
printf ( L_31 ) ;
V_134 = F_81 ( V_25 ) ;
F_80 ( stdout , F_71 ( V_134 ) , L_32 V_32 L_33 , V_25 ) ;
F_80 ( stdout , F_73 ( V_134 ) , L_34 , V_111 -> line ) ;
F_74 ( V_134 , V_25 ) ;
printf ( L_10 ) ;
if ( V_158 != & V_127 )
free ( V_158 ) ;
if ( V_159 != & V_91 )
free ( V_159 ) ;
} else if ( V_153 && V_48 >= V_153 )
return 1 ;
else {
int V_168 = V_74 . V_166 ? 12 : 8 ;
if ( V_154 )
return - 1 ;
if ( F_77 ( V_150 ) )
V_168 *= V_150 -> V_164 ;
if ( ! * V_111 -> line )
printf ( L_35 , V_168 , L_36 ) ;
else
printf ( L_37 , V_168 , L_36 , V_111 -> line ) ;
}
return 0 ;
}
static int F_82 ( struct V_29 * V_30 , struct V_22 * V_22 ,
struct V_1 * V_1 ,
T_4 * V_169 , T_1 V_115 ,
int * V_116 )
{
struct V_67 * V_68 = F_43 ( V_30 ) ;
struct V_110 * V_111 ;
char * line = NULL , * V_170 , * V_113 , * V_171 ;
T_1 V_172 ;
T_3 V_173 , V_37 = - 1 ;
T_5 V_174 [ 2 ] ;
if ( F_83 ( & line , & V_172 , V_169 ) < 0 )
return - 1 ;
if ( ! line )
return - 1 ;
V_173 = - 1 ;
V_170 = F_84 ( line ) ;
if ( regexec ( & V_175 , V_170 , 2 , V_174 , 0 ) == 0 ) {
* V_116 = atoi ( V_170 + V_174 [ 1 ] . V_176 ) ;
return 0 ;
}
V_113 = F_27 ( V_170 ) ;
if ( * V_113 ) {
V_173 = F_12 ( V_113 , & V_171 , 16 ) ;
if ( * V_171 != ':' || V_113 == V_171 || V_171 [ 1 ] == '\0' )
V_173 = - 1 ;
}
if ( V_173 != - 1 ) {
T_2 V_81 = F_85 ( V_22 , V_30 -> V_81 ) ,
V_95 = F_85 ( V_22 , V_30 -> V_95 ) ;
V_37 = V_173 - V_81 ;
if ( ( T_2 ) V_173 < V_81 || ( T_2 ) V_173 >= V_95 )
V_37 = - 1 ;
else
V_170 = V_171 + 1 ;
}
V_111 = F_63 ( V_37 , V_170 , V_115 , * V_116 , V_1 , V_22 ) ;
free ( line ) ;
( * V_116 ) ++ ;
if ( V_111 == NULL )
return - 1 ;
if ( ! F_86 ( V_111 ) ) {
V_111 -> V_12 . V_16 . V_37 = V_111 -> V_12 . V_16 . V_25 -
F_85 ( V_22 , V_30 -> V_81 ) ;
V_111 -> V_12 . V_16 . V_38 = true ;
}
if ( V_111 -> V_2 . V_12 && F_15 ( & V_111 -> V_2 ) && ! V_111 -> V_12 . V_16 . V_10 ) {
struct V_101 V_16 = {
. V_22 = V_22 ,
. V_25 = V_111 -> V_12 . V_16 . V_25 ,
} ;
if ( ! F_87 ( & V_16 ) &&
V_16 . V_30 -> V_81 == V_16 . V_105 )
V_111 -> V_12 . V_16 . V_10 = F_3 ( V_16 . V_30 -> V_10 ) ;
}
F_66 ( & V_68 -> V_73 -> V_14 , V_111 ) ;
return 0 ;
}
int F_88 ( struct V_29 * V_30 V_34 , struct V_22 * V_22 ,
int V_177 , char * V_178 , T_1 V_179 )
{
struct V_180 * V_180 = V_22 -> V_180 ;
F_89 ( V_179 == 0 ) ;
if ( V_177 >= 0 ) {
F_90 ( V_177 , V_178 , V_179 ) ;
return 0 ;
}
switch ( V_177 ) {
case V_181 : {
char V_17 [ V_182 + 15 ] = L_38 ;
char * V_183 = NULL ;
if ( V_180 -> V_184 ) {
F_91 ( V_180 -> V_185 ,
sizeof( V_180 -> V_185 ) , V_17 + 15 ) ;
V_183 = V_17 ;
}
F_8 ( V_178 , V_179 ,
L_39
L_40
L_41
L_42
L_43
L_44 , V_183 ? : L_45 ) ;
}
break;
default:
F_8 ( V_178 , V_179 , L_46 , V_177 ) ;
break;
}
return 0 ;
}
static int F_92 ( struct V_180 * V_180 , char * V_186 , T_1 V_187 )
{
char V_188 [ V_189 ] ;
char * V_190 ;
char * V_191 = NULL ;
char * V_122 ;
if ( V_180 -> V_192 == V_193 &&
! F_93 ( V_180 ) )
return V_181 ;
V_190 = F_94 ( V_180 , NULL , 0 , false ) ;
if ( V_190 ) {
F_95 ( V_186 , V_187 , V_190 ) ;
free ( V_190 ) ;
} else {
if ( V_180 -> V_184 )
return V_100 ;
goto V_194;
}
V_191 = F_3 ( V_186 ) ;
if ( ! V_191 )
return - 1 ;
V_122 = strrchr ( V_191 , '/' ) ;
if ( V_122 && strlen ( V_122 ) < V_182 - 2 )
F_96 ( V_191 ) ;
if ( F_93 ( V_180 ) ||
F_97 ( V_191 , V_188 , sizeof( V_188 ) ) < 0 ||
strstr ( V_188 , V_195 ) ||
F_98 ( V_186 , V_196 ) ) {
V_194:
F_95 ( V_186 , V_187 , V_180 -> V_197 ) ;
}
free ( V_191 ) ;
return 0 ;
}
static const char * F_99 ( const char * V_198 )
{
struct V_199 V_200 ;
if ( ! V_198 ) {
if ( F_100 ( & V_200 ) < 0 )
return NULL ;
V_198 = V_200 . V_201 ;
}
return F_101 ( ( char * ) V_198 ) ;
}
int F_102 ( struct V_29 * V_30 , struct V_22 * V_22 ,
const char * V_198 , T_1 V_115 ,
struct V_1 * * V_202 , char * V_203 )
{
struct V_180 * V_180 = V_22 -> V_180 ;
char V_204 [ V_189 * 2 ] ;
struct V_1 * V_1 = NULL ;
T_4 * V_169 ;
char V_205 [ V_189 ] ;
struct V_206 V_207 ;
bool V_208 = false ;
int V_209 [ 2 ] ;
int V_210 = 0 ;
int V_211 ;
T_6 V_212 ;
int V_104 = F_92 ( V_180 , V_205 , sizeof( V_205 ) ) ;
if ( V_104 )
return V_104 ;
V_198 = F_99 ( V_198 ) ;
if ( ! V_198 )
return - 1 ;
V_1 = F_41 ( V_198 ) ;
if ( V_1 == NULL )
return - V_213 ;
if ( V_202 )
* V_202 = V_1 ;
if ( V_1 -> V_214 ) {
V_104 = V_1 -> V_214 ( V_1 ) ;
if ( V_104 ) {
F_103 ( L_47 , V_93 , V_1 -> V_10 ) ;
return V_104 ;
}
}
if ( V_1 -> V_215 && V_203 )
V_1 -> V_215 ( V_1 , V_203 ) ;
F_53 ( L_48 V_32 L_13 V_32 L_10 , V_93 ,
V_205 , V_30 -> V_10 , V_22 -> V_94 ( V_22 , V_30 -> V_81 ) ,
V_22 -> V_94 ( V_22 , V_30 -> V_95 ) ) ;
F_53 ( L_49 ,
V_180 , V_180 -> V_197 , V_30 , V_30 -> V_10 ) ;
if ( F_93 ( V_180 ) ) {
V_207 . V_216 = V_205 ;
V_207 . V_25 = F_85 ( V_22 , V_30 -> V_81 ) ;
V_207 . V_217 = V_30 -> V_81 ;
V_207 . V_151 = V_30 -> V_95 - V_30 -> V_81 ;
if ( ! F_104 ( & V_207 ) ) {
V_208 = true ;
F_105 ( V_205 , V_207 . V_218 ,
sizeof( V_205 ) ) ;
}
} else if ( F_106 ( V_180 ) ) {
char V_113 [ V_219 ] ;
if ( F_107 ( V_180 , V_205 ,
V_113 , sizeof( V_113 ) ) < 0 )
goto V_220;
strcpy ( V_205 , V_113 ) ;
}
snprintf ( V_204 , sizeof( V_204 ) ,
L_50 V_32
L_51 V_32
L_52 ,
V_221 ? V_221 : L_53 ,
V_222 ? L_54 : L_45 ,
V_222 ? V_222 : L_45 ,
F_85 ( V_22 , V_30 -> V_81 ) ,
F_85 ( V_22 , V_30 -> V_95 ) ,
V_74 . V_223 ? L_45 : L_55 ,
V_74 . V_224 ? L_56 : L_45 ,
V_205 , V_205 ) ;
F_53 ( L_57 , V_204 ) ;
V_104 = - 1 ;
if ( F_108 ( V_209 ) < 0 ) {
F_103 ( L_58 , V_204 ) ;
goto V_225;
}
V_212 = F_109 () ;
if ( V_212 < 0 ) {
F_103 ( L_59 , V_204 ) ;
goto V_226;
}
if ( V_212 == 0 ) {
F_110 ( V_209 [ 0 ] ) ;
F_111 ( V_209 [ 1 ] , 1 ) ;
F_110 ( V_209 [ 1 ] ) ;
F_112 ( L_60 , L_61 , L_62 , V_204 , NULL ) ;
perror ( V_204 ) ;
exit ( - 1 ) ;
}
F_110 ( V_209 [ 1 ] ) ;
V_169 = fdopen ( V_209 [ 0 ] , L_63 ) ;
if ( ! V_169 ) {
F_103 ( L_64 , V_204 ) ;
goto V_225;
}
V_211 = 0 ;
while ( ! feof ( V_169 ) ) {
if ( F_82 ( V_30 , V_22 , V_1 , V_169 , V_115 ,
& V_210 ) < 0 )
break;
V_211 ++ ;
}
if ( V_211 == 0 )
F_103 ( L_65 , V_204 ) ;
if ( F_93 ( V_180 ) )
F_113 ( V_30 ) ;
fclose ( V_169 ) ;
V_104 = 0 ;
V_225:
F_110 ( V_209 [ 0 ] ) ;
if ( F_106 ( V_180 ) )
F_114 ( V_205 ) ;
if ( V_208 )
F_115 ( & V_207 ) ;
V_220:
return V_104 ;
V_226:
F_110 ( V_209 [ 1 ] ) ;
goto V_225;
}
static void F_116 ( struct V_227 * V_228 , struct V_124 * V_125 )
{
struct V_124 * V_229 ;
struct V_230 * * V_143 = & V_228 -> V_230 ;
struct V_230 * V_231 = NULL ;
int V_160 , V_232 ;
while ( * V_143 != NULL ) {
V_231 = * V_143 ;
V_229 = F_117 ( V_231 , struct V_124 , V_121 ) ;
V_232 = strcmp ( V_229 -> V_123 , V_125 -> V_123 ) ;
if ( V_232 == 0 ) {
for ( V_160 = 0 ; V_160 < V_125 -> V_130 ; V_160 ++ )
V_229 -> V_129 [ V_160 ] . V_233 += V_125 -> V_129 [ V_160 ] . V_127 ;
return;
}
if ( V_232 < 0 )
V_143 = & ( * V_143 ) -> V_234 ;
else
V_143 = & ( * V_143 ) -> V_235 ;
}
for ( V_160 = 0 ; V_160 < V_125 -> V_130 ; V_160 ++ )
V_125 -> V_129 [ V_160 ] . V_233 = V_125 -> V_129 [ V_160 ] . V_127 ;
F_118 ( & V_125 -> V_121 , V_231 , V_143 ) ;
F_119 ( & V_125 -> V_121 , V_228 ) ;
}
static int F_120 ( struct V_124 * V_55 , struct V_124 * V_56 )
{
int V_160 ;
for ( V_160 = 0 ; V_160 < V_55 -> V_130 ; V_160 ++ ) {
if ( V_55 -> V_129 [ V_160 ] . V_233 == V_56 -> V_129 [ V_160 ] . V_233 )
continue;
return V_55 -> V_129 [ V_160 ] . V_233 > V_56 -> V_129 [ V_160 ] . V_233 ;
}
return 0 ;
}
static void F_121 ( struct V_227 * V_228 , struct V_124 * V_125 )
{
struct V_124 * V_229 ;
struct V_230 * * V_143 = & V_228 -> V_230 ;
struct V_230 * V_231 = NULL ;
while ( * V_143 != NULL ) {
V_231 = * V_143 ;
V_229 = F_117 ( V_231 , struct V_124 , V_121 ) ;
if ( F_120 ( V_125 , V_229 ) )
V_143 = & ( * V_143 ) -> V_234 ;
else
V_143 = & ( * V_143 ) -> V_235 ;
}
F_118 ( & V_125 -> V_121 , V_231 , V_143 ) ;
F_119 ( & V_125 -> V_121 , V_228 ) ;
}
static void F_122 ( struct V_227 * V_236 , struct V_227 * V_237 )
{
struct V_124 * V_125 ;
struct V_230 * V_121 ;
V_121 = F_123 ( V_237 ) ;
while ( V_121 ) {
struct V_230 * V_163 ;
V_125 = F_117 ( V_121 , struct V_124 , V_121 ) ;
V_163 = F_124 ( V_121 ) ;
F_125 ( V_121 , V_237 ) ;
F_121 ( V_236 , V_125 ) ;
V_121 = V_163 ;
}
}
static void F_126 ( struct V_29 * V_30 , int V_151 )
{
struct V_67 * V_68 = F_43 ( V_30 ) ;
struct V_124 * V_125 = V_68 -> V_73 -> V_126 ;
T_1 V_128 ;
int V_160 ;
V_128 = sizeof( * V_125 ) +
( sizeof( V_125 -> V_129 ) * ( V_125 -> V_130 - 1 ) ) ;
for ( V_160 = 0 ; V_160 < V_151 ; V_160 ++ ) {
F_127 ( V_125 -> V_123 ) ;
V_125 = ( void * ) V_125 + V_128 ;
}
F_6 ( & V_68 -> V_73 -> V_126 ) ;
}
static int F_128 ( struct V_29 * V_30 , struct V_22 * V_22 ,
struct V_149 * V_150 ,
struct V_227 * V_228 , int V_151 )
{
T_2 V_81 ;
int V_160 , V_238 ;
int V_89 = V_150 -> V_165 ;
struct V_124 * V_125 ;
struct V_67 * V_68 = F_43 ( V_30 ) ;
struct V_71 * V_92 = F_54 ( V_68 , V_89 ) ;
struct V_227 V_239 = V_240 ;
int V_130 = 1 ;
T_2 V_97 = V_92 -> V_97 ;
T_1 V_128 = sizeof( struct V_124 ) ;
if ( F_77 ( V_150 ) ) {
for ( V_160 = 1 ; V_160 < V_150 -> V_164 ; V_160 ++ ) {
V_92 = F_54 ( V_68 , V_89 + V_160 ) ;
V_97 += V_92 -> V_97 ;
}
V_130 = V_150 -> V_164 ;
V_128 += ( V_130 - 1 ) * sizeof( V_125 -> V_129 ) ;
}
if ( ! V_97 )
return 0 ;
V_125 = V_68 -> V_73 -> V_126 = calloc ( V_151 , V_128 ) ;
if ( ! V_68 -> V_73 -> V_126 )
return - 1 ;
V_81 = F_85 ( V_22 , V_30 -> V_81 ) ;
for ( V_160 = 0 ; V_160 < V_151 ; V_160 ++ ) {
T_2 V_37 ;
double V_241 = 0.0 ;
V_125 -> V_130 = V_130 ;
for ( V_238 = 0 ; V_238 < V_130 ; V_238 ++ ) {
double V_127 = 0.0 ;
V_92 = F_54 ( V_68 , V_89 + V_238 ) ;
V_97 = V_92 -> V_25 [ V_160 ] . V_97 ;
if ( V_92 -> V_97 )
V_127 = 100.0 * V_97 / V_92 -> V_97 ;
if ( V_127 > V_241 )
V_241 = V_127 ;
V_125 -> V_129 [ V_238 ] . V_127 = V_127 ;
V_125 -> V_129 [ V_238 ] . V_131 = V_97 ;
}
if ( V_241 <= 0.5 )
goto V_163;
V_37 = V_81 + V_160 ;
V_125 -> V_123 = F_129 ( V_22 -> V_180 , V_37 , NULL ,
false , true ) ;
F_116 ( & V_239 , V_125 ) ;
V_163:
V_125 = ( void * ) V_125 + V_128 ;
}
F_122 ( V_228 , & V_239 ) ;
return 0 ;
}
static void F_130 ( struct V_227 * V_228 , const char * V_186 )
{
struct V_124 * V_125 ;
struct V_230 * V_121 ;
printf ( L_66 , V_186 ) ;
printf ( L_67 ) ;
if ( F_131 ( V_228 ) ) {
printf ( L_68 , V_242 ) ;
return;
}
V_121 = F_123 ( V_228 ) ;
while ( V_121 ) {
double V_127 , V_241 = 0.0 ;
const char * V_162 ;
char * V_123 ;
int V_160 ;
V_125 = F_117 ( V_121 , struct V_124 , V_121 ) ;
for ( V_160 = 0 ; V_160 < V_125 -> V_130 ; V_160 ++ ) {
V_127 = V_125 -> V_129 [ V_160 ] . V_233 ;
V_162 = F_79 ( V_127 ) ;
F_80 ( stdout , V_162 , L_30 , V_127 ) ;
if ( V_127 > V_241 )
V_241 = V_127 ;
}
V_123 = V_125 -> V_123 ;
V_162 = F_79 ( V_241 ) ;
F_80 ( stdout , V_162 , L_69 , V_123 ) ;
V_121 = F_124 ( V_121 ) ;
}
}
static void F_132 ( struct V_29 * V_30 , struct V_149 * V_150 )
{
struct V_67 * V_68 = F_43 ( V_30 ) ;
struct V_71 * V_92 = F_54 ( V_68 , V_150 -> V_165 ) ;
T_2 V_151 = F_44 ( V_30 ) , V_37 ;
for ( V_37 = 0 ; V_37 < V_151 ; ++ V_37 )
if ( V_92 -> V_25 [ V_37 ] . V_97 != 0 )
printf ( L_70 V_32 L_71 V_99 L_10 , V_243 / 2 ,
V_30 -> V_81 + V_37 , V_92 -> V_25 [ V_37 ] . V_97 ) ;
printf ( L_72 V_99 L_10 , V_243 / 2 , L_73 , V_92 -> V_97 ) ;
}
int F_133 ( struct V_29 * V_30 , struct V_22 * V_22 ,
struct V_149 * V_150 , bool V_244 ,
int V_152 , int V_153 , int V_245 )
{
struct V_180 * V_180 = V_22 -> V_180 ;
char * V_186 ;
const char * V_246 ;
const char * V_247 = F_134 ( V_150 ) ;
struct V_67 * V_68 = F_43 ( V_30 ) ;
struct V_71 * V_92 = F_54 ( V_68 , V_150 -> V_165 ) ;
struct V_110 * V_122 , * V_154 = NULL ;
T_2 V_81 = F_85 ( V_22 , V_30 -> V_81 ) ;
int V_48 = 2 , V_248 = 0 ;
int V_249 = 0 ;
T_2 V_151 ;
int V_168 = V_74 . V_166 ? 12 : 8 ;
int V_250 ;
V_186 = F_3 ( V_180 -> V_197 ) ;
if ( ! V_186 )
return - V_100 ;
if ( V_244 )
V_246 = V_186 ;
else
V_246 = F_135 ( V_186 ) ;
V_151 = F_44 ( V_30 ) ;
if ( F_77 ( V_150 ) )
V_168 *= V_150 -> V_164 ;
V_250 = printf ( L_74 V_99 L_75 ,
V_168 , V_168 , V_74 . V_166 ? L_76 :
V_74 . V_167 ? L_77 : L_78 ,
V_246 , V_247 , V_92 -> V_97 ) ;
printf ( L_79 ,
V_250 , V_250 , V_251 ) ;
if ( V_252 > 0 )
F_132 ( V_30 , V_150 ) ;
F_136 (pos, &notes->src->source, node) {
if ( V_245 && V_154 == NULL ) {
V_154 = V_122 ;
V_248 = 0 ;
}
switch ( F_76 ( V_122 , V_30 , V_81 , V_150 , V_151 ,
V_152 , V_48 , V_153 ,
V_154 ) ) {
case 0 :
++ V_48 ;
if ( V_245 ) {
V_48 += V_248 ;
V_154 = NULL ;
V_248 = 0 ;
}
break;
case 1 :
++ V_249 ;
break;
case - 1 :
default:
if ( ! V_245 )
break;
if ( V_248 == V_245 )
V_154 = F_137 ( V_154 -> V_121 . V_163 , F_138 ( * V_154 ) , V_121 ) ;
else
++ V_248 ;
break;
}
}
free ( V_186 ) ;
return V_249 ;
}
void F_139 ( struct V_29 * V_30 , int V_89 )
{
struct V_67 * V_68 = F_43 ( V_30 ) ;
struct V_71 * V_92 = F_54 ( V_68 , V_89 ) ;
memset ( V_92 , 0 , V_68 -> V_73 -> V_69 ) ;
}
void F_140 ( struct V_29 * V_30 , int V_89 )
{
struct V_67 * V_68 = F_43 ( V_30 ) ;
struct V_71 * V_92 = F_54 ( V_68 , V_89 ) ;
int V_151 = F_44 ( V_30 ) , V_37 ;
V_92 -> V_97 = 0 ;
for ( V_37 = 0 ; V_37 < V_151 ; ++ V_37 ) {
V_92 -> V_25 [ V_37 ] . V_97 = V_92 -> V_25 [ V_37 ] . V_97 * 7 / 8 ;
V_92 -> V_97 += V_92 -> V_25 [ V_37 ] . V_97 ;
}
}
void F_141 ( struct V_119 * V_120 )
{
struct V_110 * V_122 , * V_253 ;
F_142 (pos, n, head, node) {
F_143 ( & V_122 -> V_121 ) ;
F_64 ( V_122 ) ;
}
}
static T_1 F_144 ( struct V_110 * V_111 , T_4 * V_254 )
{
T_1 V_48 ;
if ( V_111 -> V_37 == - 1 )
return fprintf ( V_254 , L_80 , V_111 -> line ) ;
V_48 = fprintf ( V_254 , L_14 V_32 L_27 , V_111 -> V_37 , V_111 -> V_2 . V_10 ) ;
if ( V_111 -> V_12 . V_15 [ 0 ] != '\0' ) {
V_48 += fprintf ( V_254 , L_81 , 6 - ( int ) V_48 , L_36 ,
V_111 -> V_12 . V_15 ) ;
}
return V_48 + fprintf ( V_254 , L_10 ) ;
}
T_1 F_145 ( struct V_119 * V_120 , T_4 * V_254 )
{
struct V_110 * V_122 ;
T_1 V_48 = 0 ;
F_136 (pos, head, node)
V_48 += F_144 ( V_122 , V_254 ) ;
return V_48 ;
}
int F_146 ( struct V_29 * V_30 , struct V_22 * V_22 ,
struct V_149 * V_150 , bool V_255 ,
bool V_244 , int V_152 , int V_153 )
{
struct V_180 * V_180 = V_22 -> V_180 ;
struct V_227 V_124 = V_240 ;
T_2 V_151 ;
if ( F_102 ( V_30 , V_22 , F_147 ( V_150 ) ,
0 , NULL , NULL ) < 0 )
return - 1 ;
V_151 = F_44 ( V_30 ) ;
if ( V_255 ) {
V_256 = V_244 ;
F_128 ( V_30 , V_22 , V_150 , & V_124 , V_151 ) ;
F_130 ( & V_124 , V_180 -> V_197 ) ;
}
F_133 ( V_30 , V_22 , V_150 , V_244 ,
V_152 , V_153 , 0 ) ;
if ( V_255 )
F_126 ( V_30 , V_151 ) ;
F_141 ( & F_43 ( V_30 ) -> V_73 -> V_14 ) ;
return 0 ;
}
bool F_148 ( void )
{
return V_257 == 1 && V_258 . V_30 ;
}
