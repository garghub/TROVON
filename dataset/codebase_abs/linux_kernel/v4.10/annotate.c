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
if ( V_33 ++ != NULL )
V_12 -> V_16 . V_22 = F_11 ( V_33 , NULL , 16 ) ;
else
V_12 -> V_16 . V_22 = F_11 ( V_12 -> V_15 , NULL , 16 ) ;
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
if ( ! V_12 -> V_16 . V_22 || V_12 -> V_16 . V_34 < 0 )
return F_7 ( V_2 , V_17 , V_18 , V_12 ) ;
return F_8 ( V_17 , V_18 , L_3 V_29 , V_2 -> V_10 , V_12 -> V_16 . V_34 ) ;
}
bool F_17 ( const struct V_2 * V_2 )
{
return V_2 -> V_12 == & V_36 ;
}
static int F_18 ( char * V_15 , char * V_37 , T_2 * V_38 , char * * V_39 )
{
char * V_20 , * V_10 , * V_40 ;
if ( strstr ( V_15 , L_4 ) == NULL )
return 0 ;
* V_38 = F_11 ( V_37 , & V_20 , 16 ) ;
V_10 = strchr ( V_20 , '<' ) ;
if ( V_10 == NULL )
return - 1 ;
V_10 ++ ;
V_40 = strchr ( V_10 , '>' ) ;
if ( V_40 == NULL )
return 0 ;
* V_40 = '\0' ;
* V_39 = F_3 ( V_10 ) ;
* V_40 = '>' ;
return 0 ;
}
static int F_19 ( struct V_1 * V_1 , struct V_13 * V_12 , struct V_19 * V_19 )
{
V_12 -> V_41 . V_12 = F_20 ( sizeof( * V_12 -> V_41 . V_12 ) ) ;
if ( V_12 -> V_41 . V_12 == NULL )
return 0 ;
if ( F_21 ( V_12 -> V_15 , & V_12 -> V_41 . V_2 . V_10 , & V_12 -> V_41 . V_12 -> V_15 ) < 0 )
goto V_42;
V_12 -> V_41 . V_2 . V_12 = F_22 ( V_1 , V_12 -> V_41 . V_2 . V_10 ) ;
if ( V_12 -> V_41 . V_2 . V_12 == NULL )
goto V_42;
if ( V_12 -> V_41 . V_2 . V_12 -> V_43 &&
V_12 -> V_41 . V_2 . V_12 -> V_43 ( V_1 , V_12 -> V_41 . V_12 , V_19 ) < 0 )
goto V_42;
return 0 ;
V_42:
F_6 ( & V_12 -> V_41 . V_12 ) ;
return 0 ;
}
static int F_23 ( struct V_2 * V_2 , char * V_17 , T_1 V_18 ,
struct V_13 * V_12 )
{
int V_44 ;
if ( V_12 -> V_41 . V_2 . V_12 == NULL )
return F_7 ( V_2 , V_17 , V_18 , V_12 ) ;
V_44 = F_8 ( V_17 , V_18 , L_5 , V_2 -> V_10 ) ;
return V_44 + F_9 ( & V_12 -> V_41 . V_2 , V_17 + V_44 ,
V_18 - V_44 , V_12 -> V_41 . V_12 ) ;
}
static void F_24 ( struct V_13 * V_12 )
{
struct V_2 * V_2 = & V_12 -> V_41 . V_2 ;
if ( V_2 -> V_12 && V_2 -> V_12 -> free )
V_2 -> V_12 -> free ( V_12 -> V_41 . V_12 ) ;
else
F_5 ( V_12 -> V_41 . V_12 ) ;
F_6 ( & V_12 -> V_41 . V_12 ) ;
F_6 ( & V_12 -> V_16 . V_15 ) ;
F_6 ( & V_12 -> V_16 . V_10 ) ;
}
static int F_25 ( struct V_1 * V_1 , struct V_13 * V_12 , struct V_19 * V_19 V_31 )
{
char * V_32 = strchr ( V_12 -> V_15 , ',' ) , * V_16 , * V_37 , V_45 ;
if ( V_32 == NULL )
return - 1 ;
* V_32 = '\0' ;
V_12 -> V_14 . V_15 = F_3 ( V_12 -> V_15 ) ;
* V_32 = ',' ;
if ( V_12 -> V_14 . V_15 == NULL )
return - 1 ;
V_16 = ++ V_32 ;
V_37 = strchr ( V_32 , V_1 -> V_24 . V_46 ) ;
if ( V_37 != NULL )
V_32 = V_37 - 1 ;
else
V_32 = strchr ( V_32 , '\0' ) - 1 ;
while ( V_32 > V_16 && isspace ( V_32 [ 0 ] ) )
-- V_32 ;
V_32 ++ ;
V_45 = * V_32 ;
* V_32 = '\0' ;
V_12 -> V_16 . V_15 = F_3 ( V_16 ) ;
* V_32 = V_45 ;
if ( V_12 -> V_16 . V_15 == NULL )
goto V_47;
if ( V_37 == NULL )
return 0 ;
while ( V_37 [ 0 ] != '\0' && isspace ( V_37 [ 0 ] ) )
++ V_37 ;
F_18 ( V_12 -> V_14 . V_15 , V_37 , & V_12 -> V_14 . V_22 , & V_12 -> V_14 . V_10 ) ;
F_18 ( V_12 -> V_16 . V_15 , V_37 , & V_12 -> V_16 . V_22 , & V_12 -> V_16 . V_10 ) ;
return 0 ;
V_47:
F_6 ( & V_12 -> V_14 . V_15 ) ;
return - 1 ;
}
static int F_26 ( struct V_2 * V_2 , char * V_17 , T_1 V_18 ,
struct V_13 * V_12 )
{
return F_8 ( V_17 , V_18 , L_6 , V_2 -> V_10 ,
V_12 -> V_14 . V_10 ? : V_12 -> V_14 . V_15 ,
V_12 -> V_16 . V_10 ? : V_12 -> V_16 . V_15 ) ;
}
static int F_27 ( struct V_1 * V_1 V_31 , struct V_13 * V_12 , struct V_19 * V_19 V_31 )
{
char * V_16 , * V_37 , * V_32 , V_45 ;
V_16 = V_32 = V_12 -> V_15 ;
while ( V_32 [ 0 ] != '\0' && ! isspace ( V_32 [ 0 ] ) )
++ V_32 ;
V_45 = * V_32 ;
* V_32 = '\0' ;
V_12 -> V_16 . V_15 = F_3 ( V_16 ) ;
* V_32 = V_45 ;
if ( V_12 -> V_16 . V_15 == NULL )
return - 1 ;
V_37 = strchr ( V_32 , V_1 -> V_24 . V_46 ) ;
if ( V_37 == NULL )
return 0 ;
while ( V_37 [ 0 ] != '\0' && isspace ( V_37 [ 0 ] ) )
++ V_37 ;
F_18 ( V_12 -> V_16 . V_15 , V_37 , & V_12 -> V_16 . V_22 , & V_12 -> V_16 . V_10 ) ;
return 0 ;
}
static int F_28 ( struct V_2 * V_2 , char * V_17 , T_1 V_18 ,
struct V_13 * V_12 )
{
return F_8 ( V_17 , V_18 , L_1 , V_2 -> V_10 ,
V_12 -> V_16 . V_10 ? : V_12 -> V_16 . V_15 ) ;
}
static int F_29 ( struct V_2 * V_2 V_31 , char * V_17 , T_1 V_18 ,
struct V_13 * V_12 V_31 )
{
return F_8 ( V_17 , V_18 , L_7 , L_8 ) ;
}
bool F_30 ( const struct V_2 * V_2 )
{
return V_2 -> V_12 == & V_48 ;
}
static int F_31 ( const void * V_10 , const void * V_49 )
{
const struct V_2 * V_2 = V_49 ;
return strcmp ( V_10 , V_2 -> V_10 ) ;
}
static int F_32 ( const void * V_50 , const void * V_51 )
{
const struct V_2 * V_52 = V_50 ;
const struct V_2 * V_53 = V_51 ;
return strcmp ( V_52 -> V_10 , V_53 -> V_10 ) ;
}
static void F_4 ( struct V_1 * V_1 )
{
const int V_54 = V_1 -> V_9 ;
qsort ( V_1 -> V_6 , V_54 , sizeof( struct V_2 ) , F_32 ) ;
}
static struct V_11 * F_33 ( struct V_1 * V_1 , const char * V_10 )
{
struct V_2 * V_2 ;
const int V_54 = V_1 -> V_9 ;
if ( ! V_1 -> V_55 ) {
F_4 ( V_1 ) ;
V_1 -> V_55 = true ;
}
V_2 = bsearch ( V_10 , V_1 -> V_6 , V_54 , sizeof( struct V_2 ) , F_31 ) ;
return V_2 ? V_2 -> V_12 : NULL ;
}
static struct V_11 * F_22 ( struct V_1 * V_1 , const char * V_10 )
{
struct V_11 * V_12 = F_33 ( V_1 , V_10 ) ;
if ( ! V_12 && V_1 -> V_56 )
V_12 = V_1 -> V_56 ( V_1 , V_10 ) ;
return V_12 ;
}
static int F_34 ( const void * V_10 , const void * V_57 )
{
const struct V_1 * V_1 = V_57 ;
return strcmp ( V_10 , V_1 -> V_10 ) ;
}
static int F_35 ( const void * V_50 , const void * V_51 )
{
const struct V_1 * V_58 = V_50 ;
const struct V_1 * V_59 = V_51 ;
return strcmp ( V_58 -> V_10 , V_59 -> V_10 ) ;
}
static void F_36 ( void )
{
const int V_54 = F_37 ( V_60 ) ;
qsort ( V_60 , V_54 , sizeof( struct V_1 ) , F_35 ) ;
}
static struct V_1 * F_38 ( const char * V_10 )
{
const int V_54 = F_37 ( V_60 ) ;
static bool V_61 ;
if ( ! V_61 ) {
F_36 () ;
V_61 = true ;
}
return bsearch ( V_10 , V_60 , V_54 , sizeof( struct V_1 ) , F_34 ) ;
}
int F_39 ( struct V_26 * V_27 )
{
struct V_62 * V_63 = F_40 ( V_27 ) ;
const T_1 V_18 = F_41 ( V_27 ) ;
T_1 V_64 ;
if ( V_18 > ( V_65 - sizeof( struct V_66 ) ) / sizeof( T_2 ) )
return - 1 ;
V_64 = ( sizeof( struct V_66 ) + V_18 * sizeof( T_2 ) ) ;
if ( V_64 > ( V_65 - sizeof( * V_63 -> V_67 ) )
/ V_68 . V_69 )
return - 1 ;
V_63 -> V_67 = F_20 ( sizeof( * V_63 -> V_67 ) + V_68 . V_69 * V_64 ) ;
if ( V_63 -> V_67 == NULL )
return - 1 ;
V_63 -> V_67 -> V_64 = V_64 ;
V_63 -> V_67 -> V_70 = V_68 . V_69 ;
F_42 ( & V_63 -> V_67 -> V_14 ) ;
return 0 ;
}
static int F_43 ( struct V_26 * V_27 )
{
struct V_62 * V_63 = F_40 ( V_27 ) ;
const T_1 V_18 = F_41 ( V_27 ) ;
V_63 -> V_67 -> V_71 = calloc ( V_18 , sizeof( struct V_72 ) ) ;
if ( V_63 -> V_67 -> V_71 == NULL )
return - 1 ;
return 0 ;
}
void F_44 ( struct V_26 * V_27 )
{
struct V_62 * V_63 = F_40 ( V_27 ) ;
F_45 ( & V_63 -> V_73 ) ;
if ( V_63 -> V_67 != NULL ) {
memset ( V_63 -> V_67 -> V_74 , 0 ,
V_63 -> V_67 -> V_70 * V_63 -> V_67 -> V_64 ) ;
if ( V_63 -> V_67 -> V_71 )
memset ( V_63 -> V_67 -> V_71 , 0 ,
F_41 ( V_27 ) * sizeof( struct V_72 ) ) ;
}
F_46 ( & V_63 -> V_73 ) ;
}
static int F_47 ( struct V_62 * V_63 ,
T_2 V_75 ,
unsigned V_34 , unsigned V_76 ,
unsigned V_77 )
{
struct V_72 * V_78 ;
V_78 = V_63 -> V_67 -> V_71 ;
V_78 [ V_34 ] . V_79 ++ ;
V_78 [ V_34 ] . V_80 += V_76 ;
if ( ! V_77 && V_78 [ V_34 ] . V_77 )
return 0 ;
if ( V_78 [ V_34 ] . V_81 ) {
if ( V_77 && ( ! V_78 [ V_34 ] . V_77 ||
V_78 [ V_34 ] . V_75 > V_75 ) ) {
V_78 [ V_34 ] . V_77 = 0 ;
V_78 [ V_34 ] . V_76 = 0 ;
V_78 [ V_34 ] . V_81 = 0 ;
if ( V_78 [ V_34 ] . V_82 < 0xffff )
V_78 [ V_34 ] . V_82 ++ ;
} else if ( V_77 &&
V_78 [ V_34 ] . V_75 < V_75 )
return 0 ;
}
V_78 [ V_34 ] . V_77 = V_77 ;
V_78 [ V_34 ] . V_75 = V_75 ;
V_78 [ V_34 ] . V_76 += V_76 ;
V_78 [ V_34 ] . V_81 ++ ;
return 0 ;
}
static int F_48 ( struct V_26 * V_27 , struct V_19 * V_19 ,
struct V_62 * V_63 , int V_83 , T_2 V_22 )
{
unsigned V_34 ;
struct V_66 * V_84 ;
F_49 ( L_9 V_29 L_10 , V_85 , V_19 -> V_86 ( V_19 , V_22 ) ) ;
if ( ( V_22 < V_27 -> V_75 || V_22 >= V_27 -> V_87 ) &&
( V_22 != V_27 -> V_87 || V_27 -> V_75 != V_27 -> V_87 ) ) {
F_50 ( L_11 V_29 L_12 V_29 L_13 V_29 L_10 ,
V_85 , __LINE__ , V_27 -> V_10 , V_27 -> V_75 , V_22 , V_27 -> V_87 ) ;
return - V_88 ;
}
V_34 = V_22 - V_27 -> V_75 ;
V_84 = F_51 ( V_63 , V_83 ) ;
V_84 -> V_89 ++ ;
V_84 -> V_22 [ V_34 ] ++ ;
F_49 ( L_14 V_29 L_15 V_29 L_16 V_29
L_17 V_90 L_10 , V_27 -> V_75 , V_27 -> V_10 ,
V_22 , V_22 - V_27 -> V_75 , V_83 , V_84 -> V_22 [ V_34 ] ) ;
return 0 ;
}
static struct V_62 * F_52 ( struct V_26 * V_27 , bool V_76 )
{
struct V_62 * V_63 = F_40 ( V_27 ) ;
if ( V_63 -> V_67 == NULL ) {
if ( F_39 ( V_27 ) < 0 )
return NULL ;
}
if ( ! V_63 -> V_67 -> V_71 && V_76 ) {
if ( F_43 ( V_27 ) < 0 )
return NULL ;
}
return V_63 ;
}
static int F_53 ( struct V_26 * V_27 , struct V_19 * V_19 ,
int V_83 , T_2 V_22 )
{
struct V_62 * V_63 ;
if ( V_27 == NULL )
return 0 ;
V_63 = F_52 ( V_27 , false ) ;
if ( V_63 == NULL )
return - V_91 ;
return F_48 ( V_27 , V_19 , V_63 , V_83 , V_22 ) ;
}
static int F_54 ( T_2 V_22 , T_2 V_75 ,
struct V_26 * V_27 , unsigned V_76 )
{
struct V_62 * V_63 ;
unsigned V_34 ;
if ( V_27 == NULL )
return 0 ;
V_63 = F_52 ( V_27 , true ) ;
if ( V_63 == NULL )
return - V_91 ;
if ( V_22 < V_27 -> V_75 || V_22 >= V_27 -> V_87 )
return - V_88 ;
if ( V_75 ) {
if ( V_75 < V_27 -> V_75 || V_75 >= V_27 -> V_87 )
return - V_88 ;
if ( V_75 >= V_22 )
V_75 = 0 ;
}
V_34 = V_22 - V_27 -> V_75 ;
return F_47 ( V_63 ,
V_75 ? V_75 - V_27 -> V_75 : 0 ,
V_34 , V_76 ,
! ! V_75 ) ;
}
int F_55 ( struct V_92 * V_93 ,
struct V_92 * V_75 ,
unsigned V_76 )
{
T_2 V_94 = 0 ;
int V_95 ;
if ( ! V_76 )
return 0 ;
if ( V_75 &&
( V_75 -> V_27 == V_93 -> V_27 ||
( V_93 -> V_27 &&
V_75 -> V_22 == V_93 -> V_27 -> V_75 + V_93 -> V_19 -> V_75 ) ) )
V_94 = V_75 -> V_96 ;
if ( V_94 == 0 )
F_56 ( L_18 V_29 L_19 V_29 L_20 V_29 L_21 V_29 L_10 ,
V_93 -> V_22 ,
V_75 ? V_75 -> V_22 : 0 ,
V_93 -> V_27 ? V_93 -> V_27 -> V_75 + V_93 -> V_19 -> V_75 : 0 ,
V_94 ) ;
V_95 = F_54 ( V_93 -> V_96 , V_94 , V_93 -> V_27 , V_76 ) ;
if ( V_95 )
F_56 ( L_22 , V_95 ) ;
return V_95 ;
}
int F_57 ( struct V_92 * V_93 , int V_83 )
{
return F_53 ( V_93 -> V_27 , V_93 -> V_19 , V_83 , V_93 -> V_96 ) ;
}
int F_58 ( struct V_97 * V_98 , int V_83 , T_2 V_99 )
{
return F_53 ( V_98 -> V_100 . V_27 , V_98 -> V_100 . V_19 , V_83 , V_99 ) ;
}
static void F_59 ( struct V_101 * V_102 , struct V_1 * V_1 , struct V_19 * V_19 )
{
V_102 -> V_2 . V_12 = F_22 ( V_1 , V_102 -> V_2 . V_10 ) ;
if ( ! V_102 -> V_2 . V_12 )
return;
if ( V_102 -> V_2 . V_12 -> V_43 && V_102 -> V_2 . V_12 -> V_43 ( V_1 , & V_102 -> V_12 , V_19 ) < 0 )
V_102 -> V_2 . V_12 = NULL ;
}
static int F_21 ( char * line , const char * * V_39 , char * * V_103 )
{
char * V_10 = line , V_104 ;
while ( isspace ( V_10 [ 0 ] ) )
++ V_10 ;
if ( V_10 [ 0 ] == '\0' )
return - 1 ;
* V_103 = V_10 + 1 ;
while ( ( * V_103 ) [ 0 ] != '\0' && ! isspace ( ( * V_103 ) [ 0 ] ) )
++ * V_103 ;
V_104 = ( * V_103 ) [ 0 ] ;
( * V_103 ) [ 0 ] = '\0' ;
* V_39 = F_3 ( V_10 ) ;
if ( * V_39 == NULL )
goto V_105;
( * V_103 ) [ 0 ] = V_104 ;
if ( ( * V_103 ) [ 0 ] != '\0' ) {
( * V_103 ) ++ ;
while ( isspace ( ( * V_103 ) [ 0 ] ) )
++ ( * V_103 ) ;
}
return 0 ;
V_105:
free ( ( void * ) V_39 ) ;
* V_39 = NULL ;
return - 1 ;
}
static struct V_101 * F_60 ( T_3 V_34 , char * line ,
T_1 V_106 , int V_107 ,
struct V_1 * V_1 ,
struct V_19 * V_19 )
{
struct V_101 * V_102 = F_20 ( sizeof( * V_102 ) + V_106 ) ;
if ( V_102 != NULL ) {
V_102 -> V_34 = V_34 ;
V_102 -> line = F_3 ( line ) ;
V_102 -> V_107 = V_107 ;
if ( V_102 -> line == NULL )
goto V_108;
if ( V_34 != - 1 ) {
if ( F_21 ( V_102 -> line , & V_102 -> V_2 . V_10 , & V_102 -> V_12 . V_15 ) < 0 )
goto V_109;
F_59 ( V_102 , V_1 , V_19 ) ;
}
}
return V_102 ;
V_109:
F_6 ( & V_102 -> line ) ;
V_108:
free ( V_102 ) ;
return NULL ;
}
void F_61 ( struct V_101 * V_102 )
{
F_6 ( & V_102 -> line ) ;
if ( V_102 -> V_2 . V_12 && V_102 -> V_2 . V_12 -> free )
V_102 -> V_2 . V_12 -> free ( & V_102 -> V_12 ) ;
else
F_5 ( & V_102 -> V_12 ) ;
free ( ( void * ) V_102 -> V_2 . V_10 ) ;
V_102 -> V_2 . V_10 = NULL ;
free ( V_102 ) ;
}
int F_62 ( struct V_101 * V_102 , char * V_17 , T_1 V_18 , bool V_15 )
{
if ( V_15 || ! V_102 -> V_2 . V_12 )
return F_8 ( V_17 , V_18 , L_1 , V_102 -> V_2 . V_10 , V_102 -> V_12 . V_15 ) ;
return F_9 ( & V_102 -> V_2 , V_17 , V_18 , & V_102 -> V_12 ) ;
}
static void F_63 ( struct V_110 * V_111 , struct V_101 * line )
{
F_64 ( & line -> V_112 , V_111 ) ;
}
struct V_101 * F_65 ( struct V_110 * V_111 , struct V_101 * V_113 )
{
F_66 (pos, head, node)
if ( V_113 -> V_34 >= 0 )
return V_113 ;
return NULL ;
}
double F_67 ( struct V_62 * V_63 , int V_83 , T_3 V_34 ,
T_3 V_87 , const char * * V_114 , T_2 * V_115 )
{
struct V_116 * V_117 = V_63 -> V_67 -> V_118 ;
double V_119 = 0.0 ;
* V_115 = 0 ;
if ( V_117 ) {
T_1 V_120 = sizeof( * V_117 ) +
sizeof( V_117 -> V_121 ) * ( V_117 -> V_122 - 1 ) ;
while ( V_34 < V_87 ) {
V_117 = ( void * ) V_63 -> V_67 -> V_118 +
( V_120 * V_34 ) ;
if ( * V_114 == NULL )
* V_114 = V_117 -> V_114 ;
V_119 += V_117 -> V_121 [ V_83 ] . V_119 ;
* V_115 += V_117 -> V_121 [ V_83 ] . V_123 ;
V_34 ++ ;
}
} else {
struct V_66 * V_84 = F_51 ( V_63 , V_83 ) ;
unsigned int V_124 = 0 ;
while ( V_34 < V_87 )
V_124 += V_84 -> V_22 [ V_34 ++ ] ;
if ( V_84 -> V_89 ) {
* V_115 = V_124 ;
V_119 = 100.0 * V_124 / V_84 -> V_89 ;
}
}
return V_119 ;
}
static const char * F_68 ( struct V_125 * V_126 )
{
double V_127 = F_69 ( V_126 ) ;
if ( V_127 >= 0 ) {
if ( V_127 > 0.75 )
return V_128 ;
if ( V_127 < 0.01 )
return V_129 ;
}
return V_130 ;
}
static const char * F_70 ( struct V_125 * V_126 )
{
double V_127 = F_69 ( V_126 ) ;
if ( V_127 >= 0 ) {
if ( V_127 < 0.01 )
return V_129 ;
}
return V_131 ;
}
static void F_71 ( struct V_125 * V_126 , T_2 V_22 )
{
bool V_132 = true ;
if ( ! V_126 )
return;
#if 1
if ( V_126 -> V_133 && V_126 -> V_75 == V_22 ) {
struct V_125 * V_134 = V_126 ;
double V_135 ;
while ( ! V_134 -> V_136 )
V_134 = F_72 ( V_134 ) ;
V_135 = 100 * ( double ) V_126 -> V_137 / V_134 -> V_138 ;
if ( V_135 > 0.1 ) {
if ( V_132 ) {
V_132 = false ;
printf ( L_23 ) ;
}
printf ( L_24 , V_135 ) ;
}
}
#endif
if ( V_126 -> V_136 && V_126 -> V_87 == V_22 ) {
double V_135 = 100 * ( double ) V_126 -> V_139 / V_126 -> V_138 ;
if ( V_135 > 0.1 ) {
if ( V_132 ) {
V_132 = false ;
printf ( L_23 ) ;
}
printf ( L_25 , V_135 , 100 * ( double ) V_126 -> V_140 / V_126 -> V_139 ) ;
}
}
}
static int F_73 ( struct V_101 * V_102 , struct V_26 * V_27 , T_2 V_75 ,
struct V_141 * V_142 , T_2 V_143 , int V_144 , int V_44 ,
int V_145 , struct V_101 * V_146 )
{
static const char * V_147 ;
static const char * V_148 ;
if ( V_102 -> V_34 != - 1 ) {
const char * V_114 = NULL ;
T_2 V_115 ;
double V_119 , V_149 = 0.0 ;
double * V_150 = & V_119 ;
T_2 * V_151 = & V_115 ;
int V_152 , V_153 = 1 ;
const char * V_154 ;
struct V_62 * V_63 = F_40 ( V_27 ) ;
T_3 V_34 = V_102 -> V_34 ;
const T_2 V_22 = V_75 + V_34 ;
struct V_101 * V_155 ;
struct V_125 * V_126 ;
V_155 = F_65 ( & V_63 -> V_67 -> V_14 , V_102 ) ;
if ( F_74 ( V_142 ) ) {
V_153 = V_142 -> V_156 ;
V_150 = calloc ( V_153 , sizeof( double ) ) ;
V_151 = calloc ( V_153 , sizeof( T_2 ) ) ;
if ( V_150 == NULL || V_151 == NULL ) {
return - 1 ;
}
}
for ( V_152 = 0 ; V_152 < V_153 ; V_152 ++ ) {
V_119 = F_67 ( V_63 ,
V_63 -> V_67 -> V_118 ? V_152 : V_142 -> V_157 + V_152 ,
V_34 ,
V_155 ? V_155 -> V_34 : ( T_3 ) V_143 ,
& V_114 , & V_115 ) ;
V_150 [ V_152 ] = V_119 ;
V_151 [ V_152 ] = V_115 ;
if ( V_119 > V_149 )
V_149 = V_119 ;
}
if ( V_149 < V_144 )
return - 1 ;
if ( V_145 && V_44 >= V_145 )
return 1 ;
if ( V_146 != NULL ) {
F_75 (queue, &notes->src->source, node) {
if ( V_146 == V_102 )
break;
F_73 ( V_146 , V_27 , V_75 , V_142 , V_143 ,
0 , 0 , 1 , NULL ) ;
}
}
V_154 = F_76 ( V_149 ) ;
if ( V_114 ) {
if ( ! V_147 || strcmp ( V_147 , V_114 )
|| V_154 != V_148 ) {
F_77 ( stdout , V_154 , L_26 , V_114 ) ;
V_147 = V_114 ;
V_148 = V_154 ;
}
}
for ( V_152 = 0 ; V_152 < V_153 ; V_152 ++ ) {
V_119 = V_150 [ V_152 ] ;
V_115 = V_151 [ V_152 ] ;
V_154 = F_76 ( V_119 ) ;
if ( V_68 . V_158 )
F_77 ( stdout , V_154 , L_27 V_90 ,
V_115 ) ;
else
F_77 ( stdout , V_154 , L_28 , V_119 ) ;
}
printf ( L_29 ) ;
V_126 = F_78 ( V_22 ) ;
F_77 ( stdout , F_68 ( V_126 ) , L_30 V_29 L_31 , V_22 ) ;
F_77 ( stdout , F_70 ( V_126 ) , L_32 , V_102 -> line ) ;
F_71 ( V_126 , V_22 ) ;
printf ( L_10 ) ;
if ( V_150 != & V_119 )
free ( V_150 ) ;
if ( V_151 != & V_115 )
free ( V_151 ) ;
} else if ( V_145 && V_44 >= V_145 )
return 1 ;
else {
int V_159 = 8 ;
if ( V_146 )
return - 1 ;
if ( F_74 ( V_142 ) )
V_159 *= V_142 -> V_156 ;
if ( ! * V_102 -> line )
printf ( L_33 , V_159 , L_34 ) ;
else
printf ( L_35 , V_159 , L_34 , V_102 -> line ) ;
}
return 0 ;
}
static int F_79 ( struct V_26 * V_27 , struct V_19 * V_19 ,
struct V_1 * V_1 ,
T_4 * V_160 , T_1 V_106 ,
int * V_107 )
{
struct V_62 * V_63 = F_40 ( V_27 ) ;
struct V_101 * V_102 ;
char * line = NULL , * V_161 , * V_104 , * V_162 , * V_33 ;
T_1 V_163 ;
T_3 V_164 , V_34 = - 1 ;
T_5 V_165 [ 2 ] ;
if ( F_80 ( & line , & V_163 , V_160 ) < 0 )
return - 1 ;
if ( ! line )
return - 1 ;
while ( V_163 != 0 && isspace ( line [ V_163 - 1 ] ) )
line [ -- V_163 ] = '\0' ;
V_33 = strchr ( line , '\n' ) ;
if ( V_33 )
* V_33 = 0 ;
V_164 = - 1 ;
V_161 = line ;
if ( regexec ( & V_166 , line , 2 , V_165 , 0 ) == 0 ) {
* V_107 = atoi ( line + V_165 [ 1 ] . V_167 ) ;
return 0 ;
}
V_104 = line ;
while ( * V_104 ) {
if ( * V_104 != ' ' )
break;
V_104 ++ ;
}
if ( * V_104 ) {
V_164 = F_11 ( V_104 , & V_162 , 16 ) ;
if ( * V_162 != ':' || V_104 == V_162 || V_162 [ 1 ] == '\0' )
V_164 = - 1 ;
}
if ( V_164 != - 1 ) {
T_2 V_75 = F_81 ( V_19 , V_27 -> V_75 ) ,
V_87 = F_81 ( V_19 , V_27 -> V_87 ) ;
V_34 = V_164 - V_75 ;
if ( ( T_2 ) V_164 < V_75 || ( T_2 ) V_164 >= V_87 )
V_34 = - 1 ;
else
V_161 = V_162 + 1 ;
}
V_102 = F_60 ( V_34 , V_161 , V_106 , * V_107 , V_1 , V_19 ) ;
free ( line ) ;
( * V_107 ) ++ ;
if ( V_102 == NULL )
return - 1 ;
if ( ! F_82 ( V_102 ) ) {
V_102 -> V_12 . V_16 . V_34 = V_102 -> V_12 . V_16 . V_22 -
F_81 ( V_19 , V_27 -> V_75 ) ;
V_102 -> V_12 . V_16 . V_35 = true ;
}
if ( V_102 -> V_2 . V_12 && F_14 ( & V_102 -> V_2 ) && ! V_102 -> V_12 . V_16 . V_10 ) {
struct V_92 V_16 = {
. V_19 = V_19 ,
. V_22 = V_102 -> V_12 . V_16 . V_22 ,
} ;
if ( ! F_83 ( & V_16 ) &&
V_16 . V_27 -> V_75 == V_16 . V_96 )
V_102 -> V_12 . V_16 . V_10 = F_3 ( V_16 . V_27 -> V_10 ) ;
}
F_63 ( & V_63 -> V_67 -> V_14 , V_102 ) ;
return 0 ;
}
int F_84 ( struct V_26 * V_27 V_31 , struct V_19 * V_19 ,
int V_168 , char * V_169 , T_1 V_170 )
{
struct V_171 * V_171 = V_19 -> V_171 ;
F_85 ( V_170 == 0 ) ;
if ( V_168 >= 0 ) {
F_86 ( V_168 , V_169 , V_170 ) ;
return 0 ;
}
switch ( V_168 ) {
case V_172 : {
char V_17 [ V_173 + 15 ] = L_36 ;
char * V_174 = NULL ;
if ( V_171 -> V_175 ) {
F_87 ( V_171 -> V_176 ,
sizeof( V_171 -> V_176 ) , V_17 + 15 ) ;
V_174 = V_17 ;
}
F_8 ( V_169 , V_170 ,
L_37
L_38
L_39
L_40
L_41
L_42 , V_174 ? : L_43 ) ;
}
break;
default:
F_8 ( V_169 , V_170 , L_44 , V_168 ) ;
break;
}
return 0 ;
}
static int F_88 ( struct V_171 * V_171 , char * V_177 , T_1 V_178 )
{
char V_179 [ V_180 ] ;
char * V_181 ;
if ( V_171 -> V_182 == V_183 &&
! F_89 ( V_171 ) )
return V_172 ;
V_181 = F_90 ( V_171 , NULL , 0 ) ;
if ( V_181 ) {
F_91 ( V_177 , V_178 , V_181 ) ;
free ( V_181 ) ;
} else {
if ( V_171 -> V_175 )
return V_91 ;
goto V_184;
}
if ( F_89 ( V_171 ) ||
F_92 ( V_177 , V_179 , sizeof( V_179 ) ) < 0 ||
strstr ( V_179 , V_185 ) ||
F_93 ( V_177 , V_186 ) ) {
V_184:
F_91 ( V_177 , V_178 , V_171 -> V_187 ) ;
}
return 0 ;
}
static const char * F_94 ( const char * V_188 )
{
struct V_189 V_190 ;
if ( ! V_188 ) {
if ( F_95 ( & V_190 ) < 0 )
return NULL ;
V_188 = V_190 . V_191 ;
}
return F_96 ( ( char * ) V_188 ) ;
}
int F_97 ( struct V_26 * V_27 , struct V_19 * V_19 , const char * V_188 , T_1 V_106 )
{
struct V_171 * V_171 = V_19 -> V_171 ;
char V_192 [ V_180 * 2 ] ;
struct V_1 * V_1 = NULL ;
T_4 * V_160 ;
char V_193 [ V_180 ] ;
struct V_194 V_195 ;
bool V_196 = false ;
int V_197 [ 2 ] ;
int V_198 = 0 ;
int V_199 ;
T_6 V_200 ;
int V_95 = F_88 ( V_171 , V_193 , sizeof( V_193 ) ) ;
if ( V_95 )
return V_95 ;
V_188 = F_94 ( V_188 ) ;
if ( ! V_188 )
return - 1 ;
V_1 = F_38 ( V_188 ) ;
if ( V_1 == NULL )
return - V_201 ;
if ( V_1 -> V_202 ) {
V_95 = V_1 -> V_202 ( V_1 ) ;
if ( V_95 ) {
F_98 ( L_45 , V_85 , V_1 -> V_10 ) ;
return V_95 ;
}
}
F_50 ( L_46 V_29 L_13 V_29 L_10 , V_85 ,
V_193 , V_27 -> V_10 , V_19 -> V_86 ( V_19 , V_27 -> V_75 ) ,
V_19 -> V_86 ( V_19 , V_27 -> V_87 ) ) ;
F_50 ( L_47 ,
V_171 , V_171 -> V_187 , V_27 , V_27 -> V_10 ) ;
if ( F_89 ( V_171 ) ) {
V_195 . V_203 = V_193 ;
V_195 . V_22 = F_81 ( V_19 , V_27 -> V_75 ) ;
V_195 . V_204 = V_27 -> V_75 ;
V_195 . V_143 = V_27 -> V_87 - V_27 -> V_75 ;
if ( ! F_99 ( & V_195 ) ) {
V_196 = true ;
F_100 ( V_193 , V_195 . V_205 ,
sizeof( V_193 ) ) ;
}
} else if ( F_101 ( V_171 ) ) {
char V_104 [ V_180 ] ;
struct V_206 V_207 ;
int V_208 ;
bool V_209 ;
if ( F_102 ( & V_207 , V_193 ) )
goto V_210;
snprintf ( V_104 , V_180 , L_48 ) ;
V_208 = F_103 ( V_104 ) ;
if ( V_208 < 0 ) {
free ( V_207 . V_211 ) ;
goto V_210;
}
V_209 = F_104 ( V_207 . V_211 , V_193 , V_208 ) ;
if ( V_209 )
F_98 ( L_49 , V_207 . V_211 , V_193 ) ;
free ( V_207 . V_211 ) ;
F_105 ( V_208 ) ;
if ( ! V_209 )
goto V_210;
strcpy ( V_193 , V_104 ) ;
}
snprintf ( V_192 , sizeof( V_192 ) ,
L_50 V_29
L_51 V_29
L_52 ,
V_212 ? V_212 : L_53 ,
V_213 ? L_54 : L_43 ,
V_213 ? V_213 : L_43 ,
F_81 ( V_19 , V_27 -> V_75 ) ,
F_81 ( V_19 , V_27 -> V_87 ) ,
V_68 . V_214 ? L_43 : L_55 ,
V_68 . V_215 ? L_56 : L_43 ,
V_193 , V_193 ) ;
F_50 ( L_57 , V_192 ) ;
V_95 = - 1 ;
if ( F_106 ( V_197 ) < 0 ) {
F_98 ( L_58 , V_192 ) ;
goto V_216;
}
V_200 = F_107 () ;
if ( V_200 < 0 ) {
F_98 ( L_59 , V_192 ) ;
goto V_217;
}
if ( V_200 == 0 ) {
F_105 ( V_197 [ 0 ] ) ;
F_108 ( V_197 [ 1 ] , 1 ) ;
F_105 ( V_197 [ 1 ] ) ;
F_109 ( L_60 , L_61 , L_62 , V_192 , NULL ) ;
perror ( V_192 ) ;
exit ( - 1 ) ;
}
F_105 ( V_197 [ 1 ] ) ;
V_160 = fdopen ( V_197 [ 0 ] , L_63 ) ;
if ( ! V_160 ) {
F_98 ( L_64 , V_192 ) ;
goto V_216;
}
V_199 = 0 ;
while ( ! feof ( V_160 ) ) {
if ( F_79 ( V_27 , V_19 , V_1 , V_160 , V_106 ,
& V_198 ) < 0 )
break;
V_199 ++ ;
}
if ( V_199 == 0 )
F_98 ( L_65 , V_192 ) ;
if ( F_89 ( V_171 ) )
F_110 ( V_27 ) ;
fclose ( V_160 ) ;
V_95 = 0 ;
V_216:
F_105 ( V_197 [ 0 ] ) ;
if ( F_101 ( V_171 ) )
F_111 ( V_193 ) ;
if ( V_196 )
F_112 ( & V_195 ) ;
V_210:
return V_95 ;
V_217:
F_105 ( V_197 [ 1 ] ) ;
goto V_216;
}
static void F_113 ( struct V_218 * V_219 , struct V_116 * V_117 )
{
struct V_116 * V_220 ;
struct V_221 * * V_135 = & V_219 -> V_221 ;
struct V_221 * V_222 = NULL ;
int V_152 , V_209 ;
while ( * V_135 != NULL ) {
V_222 = * V_135 ;
V_220 = F_114 ( V_222 , struct V_116 , V_112 ) ;
V_209 = strcmp ( V_220 -> V_114 , V_117 -> V_114 ) ;
if ( V_209 == 0 ) {
for ( V_152 = 0 ; V_152 < V_117 -> V_122 ; V_152 ++ )
V_220 -> V_121 [ V_152 ] . V_223 += V_117 -> V_121 [ V_152 ] . V_119 ;
return;
}
if ( V_209 < 0 )
V_135 = & ( * V_135 ) -> V_224 ;
else
V_135 = & ( * V_135 ) -> V_225 ;
}
for ( V_152 = 0 ; V_152 < V_117 -> V_122 ; V_152 ++ )
V_117 -> V_121 [ V_152 ] . V_223 = V_117 -> V_121 [ V_152 ] . V_119 ;
F_115 ( & V_117 -> V_112 , V_222 , V_135 ) ;
F_116 ( & V_117 -> V_112 , V_219 ) ;
}
static int F_117 ( struct V_116 * V_50 , struct V_116 * V_51 )
{
int V_152 ;
for ( V_152 = 0 ; V_152 < V_50 -> V_122 ; V_152 ++ ) {
if ( V_50 -> V_121 [ V_152 ] . V_223 == V_51 -> V_121 [ V_152 ] . V_223 )
continue;
return V_50 -> V_121 [ V_152 ] . V_223 > V_51 -> V_121 [ V_152 ] . V_223 ;
}
return 0 ;
}
static void F_118 ( struct V_218 * V_219 , struct V_116 * V_117 )
{
struct V_116 * V_220 ;
struct V_221 * * V_135 = & V_219 -> V_221 ;
struct V_221 * V_222 = NULL ;
while ( * V_135 != NULL ) {
V_222 = * V_135 ;
V_220 = F_114 ( V_222 , struct V_116 , V_112 ) ;
if ( F_117 ( V_117 , V_220 ) )
V_135 = & ( * V_135 ) -> V_224 ;
else
V_135 = & ( * V_135 ) -> V_225 ;
}
F_115 ( & V_117 -> V_112 , V_222 , V_135 ) ;
F_116 ( & V_117 -> V_112 , V_219 ) ;
}
static void F_119 ( struct V_218 * V_226 , struct V_218 * V_227 )
{
struct V_116 * V_117 ;
struct V_221 * V_112 ;
V_112 = F_120 ( V_227 ) ;
while ( V_112 ) {
struct V_221 * V_155 ;
V_117 = F_114 ( V_112 , struct V_116 , V_112 ) ;
V_155 = F_121 ( V_112 ) ;
F_122 ( V_112 , V_227 ) ;
F_118 ( V_226 , V_117 ) ;
V_112 = V_155 ;
}
}
static void F_123 ( struct V_26 * V_27 , int V_143 )
{
struct V_62 * V_63 = F_40 ( V_27 ) ;
struct V_116 * V_117 = V_63 -> V_67 -> V_118 ;
T_1 V_120 ;
int V_152 ;
V_120 = sizeof( * V_117 ) +
( sizeof( V_117 -> V_121 ) * ( V_117 -> V_122 - 1 ) ) ;
for ( V_152 = 0 ; V_152 < V_143 ; V_152 ++ ) {
F_124 ( V_117 -> V_114 ) ;
V_117 = ( void * ) V_117 + V_120 ;
}
F_6 ( & V_63 -> V_67 -> V_118 ) ;
}
static int F_125 ( struct V_26 * V_27 , struct V_19 * V_19 ,
struct V_141 * V_142 ,
struct V_218 * V_219 , int V_143 )
{
T_2 V_75 ;
int V_152 , V_228 ;
int V_83 = V_142 -> V_157 ;
struct V_116 * V_117 ;
struct V_62 * V_63 = F_40 ( V_27 ) ;
struct V_66 * V_84 = F_51 ( V_63 , V_83 ) ;
struct V_218 V_229 = V_230 ;
int V_122 = 1 ;
T_2 V_231 = V_84 -> V_89 ;
T_1 V_120 = sizeof( struct V_116 ) ;
if ( F_74 ( V_142 ) ) {
for ( V_152 = 1 ; V_152 < V_142 -> V_156 ; V_152 ++ ) {
V_84 = F_51 ( V_63 , V_83 + V_152 ) ;
V_231 += V_84 -> V_89 ;
}
V_122 = V_142 -> V_156 ;
V_120 += ( V_122 - 1 ) * sizeof( V_117 -> V_121 ) ;
}
if ( ! V_231 )
return 0 ;
V_117 = V_63 -> V_67 -> V_118 = calloc ( V_143 , V_120 ) ;
if ( ! V_63 -> V_67 -> V_118 )
return - 1 ;
V_75 = F_81 ( V_19 , V_27 -> V_75 ) ;
for ( V_152 = 0 ; V_152 < V_143 ; V_152 ++ ) {
T_2 V_34 ;
double V_232 = 0.0 ;
V_117 -> V_122 = V_122 ;
for ( V_228 = 0 ; V_228 < V_122 ; V_228 ++ ) {
V_84 = F_51 ( V_63 , V_83 + V_228 ) ;
V_117 -> V_121 [ V_228 ] . V_119 = 100.0 * V_84 -> V_22 [ V_152 ] / V_84 -> V_89 ;
if ( V_117 -> V_121 [ V_228 ] . V_119 > V_232 )
V_232 = V_117 -> V_121 [ V_228 ] . V_119 ;
}
if ( V_232 <= 0.5 )
goto V_155;
V_34 = V_75 + V_152 ;
V_117 -> V_114 = F_126 ( V_19 -> V_171 , V_34 , NULL , false ) ;
F_113 ( & V_229 , V_117 ) ;
V_155:
V_117 = ( void * ) V_117 + V_120 ;
}
F_119 ( V_219 , & V_229 ) ;
return 0 ;
}
static void F_127 ( struct V_218 * V_219 , const char * V_177 )
{
struct V_116 * V_117 ;
struct V_221 * V_112 ;
printf ( L_66 , V_177 ) ;
printf ( L_67 ) ;
if ( F_128 ( V_219 ) ) {
printf ( L_68 , V_233 ) ;
return;
}
V_112 = F_120 ( V_219 ) ;
while ( V_112 ) {
double V_119 , V_232 = 0.0 ;
const char * V_154 ;
char * V_114 ;
int V_152 ;
V_117 = F_114 ( V_112 , struct V_116 , V_112 ) ;
for ( V_152 = 0 ; V_152 < V_117 -> V_122 ; V_152 ++ ) {
V_119 = V_117 -> V_121 [ V_152 ] . V_223 ;
V_154 = F_76 ( V_119 ) ;
F_77 ( stdout , V_154 , L_28 , V_119 ) ;
if ( V_119 > V_232 )
V_232 = V_119 ;
}
V_114 = V_117 -> V_114 ;
V_154 = F_76 ( V_232 ) ;
F_77 ( stdout , V_154 , L_69 , V_114 ) ;
V_112 = F_121 ( V_112 ) ;
}
}
static void F_129 ( struct V_26 * V_27 , struct V_141 * V_142 )
{
struct V_62 * V_63 = F_40 ( V_27 ) ;
struct V_66 * V_84 = F_51 ( V_63 , V_142 -> V_157 ) ;
T_2 V_143 = F_41 ( V_27 ) , V_34 ;
for ( V_34 = 0 ; V_34 < V_143 ; ++ V_34 )
if ( V_84 -> V_22 [ V_34 ] != 0 )
printf ( L_70 V_29 L_71 V_90 L_10 , V_234 / 2 ,
V_27 -> V_75 + V_34 , V_84 -> V_22 [ V_34 ] ) ;
printf ( L_72 V_90 L_10 , V_234 / 2 , L_73 , V_84 -> V_89 ) ;
}
int F_130 ( struct V_26 * V_27 , struct V_19 * V_19 ,
struct V_141 * V_142 , bool V_235 ,
int V_144 , int V_145 , int V_236 )
{
struct V_171 * V_171 = V_19 -> V_171 ;
char * V_177 ;
const char * V_237 ;
const char * V_238 = F_131 ( V_142 ) ;
struct V_62 * V_63 = F_40 ( V_27 ) ;
struct V_66 * V_84 = F_51 ( V_63 , V_142 -> V_157 ) ;
struct V_101 * V_113 , * V_146 = NULL ;
T_2 V_75 = F_81 ( V_19 , V_27 -> V_75 ) ;
int V_44 = 2 , V_239 = 0 ;
int V_240 = 0 ;
T_2 V_143 ;
int V_159 = 8 ;
int V_241 ;
V_177 = F_3 ( V_171 -> V_187 ) ;
if ( ! V_177 )
return - V_91 ;
if ( V_235 )
V_237 = V_177 ;
else
V_237 = F_132 ( V_177 ) ;
V_143 = F_41 ( V_27 ) ;
if ( F_74 ( V_142 ) )
V_159 *= V_142 -> V_156 ;
V_241 = printf ( L_74 V_90 L_75 ,
V_159 , V_159 , L_76 , V_237 , V_238 , V_84 -> V_89 ) ;
printf ( L_77 ,
V_241 , V_241 , V_242 ) ;
if ( V_243 )
F_129 ( V_27 , V_142 ) ;
F_133 (pos, &notes->src->source, node) {
if ( V_236 && V_146 == NULL ) {
V_146 = V_113 ;
V_239 = 0 ;
}
switch ( F_73 ( V_113 , V_27 , V_75 , V_142 , V_143 ,
V_144 , V_44 , V_145 ,
V_146 ) ) {
case 0 :
++ V_44 ;
if ( V_236 ) {
V_44 += V_239 ;
V_146 = NULL ;
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
V_146 = F_134 ( V_146 -> V_112 . V_155 , F_135 ( * V_146 ) , V_112 ) ;
else
++ V_239 ;
break;
}
}
free ( V_177 ) ;
return V_240 ;
}
void F_136 ( struct V_26 * V_27 , int V_83 )
{
struct V_62 * V_63 = F_40 ( V_27 ) ;
struct V_66 * V_84 = F_51 ( V_63 , V_83 ) ;
memset ( V_84 , 0 , V_63 -> V_67 -> V_64 ) ;
}
void F_137 ( struct V_26 * V_27 , int V_83 )
{
struct V_62 * V_63 = F_40 ( V_27 ) ;
struct V_66 * V_84 = F_51 ( V_63 , V_83 ) ;
int V_143 = F_41 ( V_27 ) , V_34 ;
V_84 -> V_89 = 0 ;
for ( V_34 = 0 ; V_34 < V_143 ; ++ V_34 ) {
V_84 -> V_22 [ V_34 ] = V_84 -> V_22 [ V_34 ] * 7 / 8 ;
V_84 -> V_89 += V_84 -> V_22 [ V_34 ] ;
}
}
void F_138 ( struct V_110 * V_111 )
{
struct V_101 * V_113 , * V_244 ;
F_139 (pos, n, head, node) {
F_140 ( & V_113 -> V_112 ) ;
F_61 ( V_113 ) ;
}
}
static T_1 F_141 ( struct V_101 * V_102 , T_4 * V_245 )
{
T_1 V_44 ;
if ( V_102 -> V_34 == - 1 )
return fprintf ( V_245 , L_78 , V_102 -> line ) ;
V_44 = fprintf ( V_245 , L_14 V_29 L_26 , V_102 -> V_34 , V_102 -> V_2 . V_10 ) ;
if ( V_102 -> V_12 . V_15 [ 0 ] != '\0' ) {
V_44 += fprintf ( V_245 , L_79 , 6 - ( int ) V_44 , L_34 ,
V_102 -> V_12 . V_15 ) ;
}
return V_44 + fprintf ( V_245 , L_10 ) ;
}
T_1 F_142 ( struct V_110 * V_111 , T_4 * V_245 )
{
struct V_101 * V_113 ;
T_1 V_44 = 0 ;
F_133 (pos, head, node)
V_44 += F_141 ( V_113 , V_245 ) ;
return V_44 ;
}
int F_143 ( struct V_26 * V_27 , struct V_19 * V_19 ,
struct V_141 * V_142 , bool V_246 ,
bool V_235 , int V_144 , int V_145 )
{
struct V_171 * V_171 = V_19 -> V_171 ;
struct V_218 V_116 = V_230 ;
T_2 V_143 ;
if ( F_97 ( V_27 , V_19 , F_144 ( V_142 ) , 0 ) < 0 )
return - 1 ;
V_143 = F_41 ( V_27 ) ;
if ( V_246 ) {
V_247 = V_235 ;
F_125 ( V_27 , V_19 , V_142 , & V_116 , V_143 ) ;
F_127 ( & V_116 , V_171 -> V_187 ) ;
}
F_130 ( V_27 , V_19 , V_142 , V_235 ,
V_144 , V_145 , 0 ) ;
if ( V_246 )
F_123 ( V_27 , V_143 ) ;
F_138 ( & F_40 ( V_27 ) -> V_67 -> V_14 ) ;
return 0 ;
}
bool F_145 ( void )
{
return V_248 == 1 && V_249 . V_27 ;
}
