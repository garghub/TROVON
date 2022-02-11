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
V_11 = strchr ( V_5 , '>' ) ;
if ( V_11 == NULL )
return - 1 ;
* V_11 = '\0' ;
V_2 -> V_6 . V_5 = F_8 ( V_5 ) ;
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
static int F_9 ( struct V_7 * V_7 , char * V_8 , T_1 V_9 ,
struct V_1 * V_2 )
{
if ( V_2 -> V_6 . V_5 )
return F_4 ( V_8 , V_9 , L_1 , V_7 -> V_5 , V_2 -> V_6 . V_5 ) ;
if ( V_2 -> V_6 . V_12 == 0 )
return F_3 ( V_7 , V_8 , V_9 , V_2 ) ;
return F_4 ( V_8 , V_9 , L_2 V_14 , V_7 -> V_5 , V_2 -> V_6 . V_12 ) ;
}
bool F_10 ( const struct V_7 * V_7 )
{
return V_7 -> V_2 == & V_15 ;
}
static int F_11 ( struct V_1 * V_2 )
{
const char * V_16 = strchr ( V_2 -> V_4 , '+' ) ;
V_2 -> V_6 . V_12 = F_7 ( V_2 -> V_4 , NULL , 16 ) ;
if ( V_16 ++ != NULL )
V_2 -> V_6 . V_17 = F_7 ( V_16 , NULL , 16 ) ;
else
V_2 -> V_6 . V_17 = V_18 ;
return 0 ;
}
static int F_12 ( struct V_7 * V_7 , char * V_8 , T_1 V_9 ,
struct V_1 * V_2 )
{
return F_4 ( V_8 , V_9 , L_3 V_14 , V_7 -> V_5 , V_2 -> V_6 . V_17 ) ;
}
bool F_13 ( const struct V_7 * V_7 )
{
return V_7 -> V_2 == & V_19 ;
}
static int F_14 ( char * V_4 , char * V_20 , T_2 * V_21 , char * * V_22 )
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
* V_22 = F_8 ( V_5 ) ;
* V_23 = '>' ;
return 0 ;
}
static int F_15 ( struct V_1 * V_2 )
{
char * V_5 ;
V_2 -> V_24 . V_2 = F_16 ( sizeof( * V_2 -> V_24 . V_2 ) ) ;
if ( V_2 -> V_24 . V_2 == NULL )
return 0 ;
if ( F_17 ( V_2 -> V_4 , & V_5 , & V_2 -> V_24 . V_2 -> V_4 ) < 0 )
goto V_25;
V_2 -> V_24 . V_7 = F_18 ( V_5 ) ;
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
static int F_19 ( struct V_7 * V_7 , char * V_8 , T_1 V_9 ,
struct V_1 * V_2 )
{
int V_27 ;
if ( V_2 -> V_24 . V_7 == NULL )
return F_3 ( V_7 , V_8 , V_9 , V_2 ) ;
V_27 = F_4 ( V_8 , V_9 , L_5 , V_7 -> V_5 ) ;
return V_27 + F_5 ( V_2 -> V_24 . V_7 , V_8 + V_27 ,
V_9 - V_27 , V_2 -> V_24 . V_2 ) ;
}
static void F_20 ( struct V_1 * V_2 )
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
static int F_21 ( struct V_1 * V_2 )
{
char * V_16 = strchr ( V_2 -> V_4 , ',' ) , * V_6 , * V_20 , V_28 ;
if ( V_16 == NULL )
return - 1 ;
* V_16 = '\0' ;
V_2 -> V_3 . V_4 = F_8 ( V_2 -> V_4 ) ;
* V_16 = ',' ;
if ( V_2 -> V_3 . V_4 == NULL )
return - 1 ;
V_6 = ++ V_16 ;
V_20 = strchr ( V_16 , '#' ) ;
if ( V_20 != NULL )
V_16 = V_20 - 1 ;
else
V_16 = strchr ( V_16 , '\0' ) - 1 ;
while ( V_16 > V_6 && isspace ( V_16 [ 0 ] ) )
-- V_16 ;
V_16 ++ ;
V_28 = * V_16 ;
* V_16 = '\0' ;
V_2 -> V_6 . V_4 = F_8 ( V_6 ) ;
* V_16 = V_28 ;
if ( V_2 -> V_6 . V_4 == NULL )
goto V_29;
if ( V_20 == NULL )
return 0 ;
while ( V_20 [ 0 ] != '\0' && isspace ( V_20 [ 0 ] ) )
++ V_20 ;
F_14 ( V_2 -> V_3 . V_4 , V_20 , & V_2 -> V_3 . V_12 , & V_2 -> V_3 . V_5 ) ;
F_14 ( V_2 -> V_6 . V_4 , V_20 , & V_2 -> V_6 . V_12 , & V_2 -> V_6 . V_5 ) ;
return 0 ;
V_29:
F_2 ( & V_2 -> V_3 . V_4 ) ;
return - 1 ;
}
static int F_22 ( struct V_7 * V_7 , char * V_8 , T_1 V_9 ,
struct V_1 * V_2 )
{
return F_4 ( V_8 , V_9 , L_6 , V_7 -> V_5 ,
V_2 -> V_3 . V_5 ? : V_2 -> V_3 . V_4 ,
V_2 -> V_6 . V_5 ? : V_2 -> V_6 . V_4 ) ;
}
static int F_23 ( struct V_1 * V_2 )
{
char * V_6 , * V_20 , * V_16 , V_28 ;
V_6 = V_16 = V_2 -> V_4 ;
while ( V_16 [ 0 ] != '\0' && ! isspace ( V_16 [ 0 ] ) )
++ V_16 ;
V_28 = * V_16 ;
* V_16 = '\0' ;
V_2 -> V_6 . V_4 = F_8 ( V_6 ) ;
* V_16 = V_28 ;
if ( V_2 -> V_6 . V_4 == NULL )
return - 1 ;
V_20 = strchr ( V_16 , '#' ) ;
if ( V_20 == NULL )
return 0 ;
while ( V_20 [ 0 ] != '\0' && isspace ( V_20 [ 0 ] ) )
++ V_20 ;
F_14 ( V_2 -> V_6 . V_4 , V_20 , & V_2 -> V_6 . V_12 , & V_2 -> V_6 . V_5 ) ;
return 0 ;
}
static int F_24 ( struct V_7 * V_7 , char * V_8 , T_1 V_9 ,
struct V_1 * V_2 )
{
return F_4 ( V_8 , V_9 , L_1 , V_7 -> V_5 ,
V_2 -> V_6 . V_5 ? : V_2 -> V_6 . V_4 ) ;
}
static int F_25 ( struct V_7 * V_7 V_30 , char * V_8 , T_1 V_9 ,
struct V_1 * V_2 V_30 )
{
return F_4 ( V_8 , V_9 , L_7 , L_8 ) ;
}
static int F_26 ( const void * V_5 , const void * V_31 )
{
const struct V_7 * V_7 = V_31 ;
return strcmp ( V_5 , V_7 -> V_5 ) ;
}
static struct V_7 * F_18 ( const char * V_5 )
{
const int V_32 = F_27 ( V_33 ) ;
return bsearch ( V_5 , V_33 , V_32 , sizeof( struct V_7 ) , F_26 ) ;
}
int F_28 ( struct V_34 * V_34 V_30 , struct V_35 * V_36 )
{
struct V_37 * V_38 = F_29 ( V_36 ) ;
F_30 ( & V_38 -> V_39 , NULL ) ;
return 0 ;
}
int F_31 ( struct V_35 * V_36 )
{
struct V_37 * V_38 = F_29 ( V_36 ) ;
const T_1 V_9 = F_32 ( V_36 ) ;
T_1 V_40 ;
if ( V_9 > ( V_41 - sizeof( struct V_42 ) ) / sizeof( T_2 ) )
return - 1 ;
V_40 = ( sizeof( struct V_42 ) + V_9 * sizeof( T_2 ) ) ;
if ( V_40 > ( V_41 - sizeof( * V_38 -> V_43 ) )
/ V_44 . V_45 )
return - 1 ;
V_38 -> V_43 = F_16 ( sizeof( * V_38 -> V_43 ) + V_44 . V_45 * V_40 ) ;
if ( V_38 -> V_43 == NULL )
return - 1 ;
V_38 -> V_43 -> V_40 = V_40 ;
V_38 -> V_43 -> V_46 = V_44 . V_45 ;
F_33 ( & V_38 -> V_43 -> V_3 ) ;
return 0 ;
}
static int F_34 ( struct V_35 * V_36 )
{
struct V_37 * V_38 = F_29 ( V_36 ) ;
const T_1 V_9 = F_32 ( V_36 ) ;
V_38 -> V_43 -> V_47 = calloc ( V_9 , sizeof( struct V_48 ) ) ;
if ( V_38 -> V_43 -> V_47 == NULL )
return - 1 ;
return 0 ;
}
void F_35 ( struct V_35 * V_36 )
{
struct V_37 * V_38 = F_29 ( V_36 ) ;
F_36 ( & V_38 -> V_39 ) ;
if ( V_38 -> V_43 != NULL ) {
memset ( V_38 -> V_43 -> V_49 , 0 ,
V_38 -> V_43 -> V_46 * V_38 -> V_43 -> V_40 ) ;
if ( V_38 -> V_43 -> V_47 )
memset ( V_38 -> V_43 -> V_47 , 0 ,
F_32 ( V_36 ) * sizeof( struct V_48 ) ) ;
}
F_37 ( & V_38 -> V_39 ) ;
}
static int F_38 ( struct V_37 * V_38 ,
T_2 V_50 ,
unsigned V_17 , unsigned V_51 ,
unsigned V_52 )
{
struct V_48 * V_53 ;
V_53 = V_38 -> V_43 -> V_47 ;
V_53 [ V_17 ] . V_54 ++ ;
V_53 [ V_17 ] . V_55 += V_51 ;
if ( ! V_52 && V_53 [ V_17 ] . V_52 )
return 0 ;
if ( V_53 [ V_17 ] . V_56 ) {
if ( V_52 && ( ! V_53 [ V_17 ] . V_52 ||
V_53 [ V_17 ] . V_50 > V_50 ) ) {
V_53 [ V_17 ] . V_52 = 0 ;
V_53 [ V_17 ] . V_51 = 0 ;
V_53 [ V_17 ] . V_56 = 0 ;
if ( V_53 [ V_17 ] . V_57 < 0xffff )
V_53 [ V_17 ] . V_57 ++ ;
} else if ( V_52 &&
V_53 [ V_17 ] . V_50 < V_50 )
return 0 ;
}
V_53 [ V_17 ] . V_52 = V_52 ;
V_53 [ V_17 ] . V_50 = V_50 ;
V_53 [ V_17 ] . V_51 += V_51 ;
V_53 [ V_17 ] . V_56 ++ ;
return 0 ;
}
static int F_39 ( struct V_35 * V_36 , struct V_34 * V_34 ,
struct V_37 * V_38 , int V_58 , T_2 V_12 )
{
unsigned V_17 ;
struct V_42 * V_59 ;
F_40 ( L_9 V_14 L_10 , V_60 , V_34 -> V_61 ( V_34 , V_12 ) ) ;
if ( V_12 < V_36 -> V_50 || V_12 >= V_36 -> V_62 ) {
F_41 ( L_11 V_14 L_12 V_14 L_13 V_14 L_10 ,
V_60 , __LINE__ , V_36 -> V_5 , V_36 -> V_50 , V_12 , V_36 -> V_62 ) ;
return - V_63 ;
}
V_17 = V_12 - V_36 -> V_50 ;
V_59 = F_42 ( V_38 , V_58 ) ;
V_59 -> V_64 ++ ;
V_59 -> V_12 [ V_17 ] ++ ;
F_40 ( L_14 V_14 L_15 V_14 L_16 V_14
L_17 V_65 L_10 , V_36 -> V_50 , V_36 -> V_5 ,
V_12 , V_12 - V_36 -> V_50 , V_58 , V_59 -> V_12 [ V_17 ] ) ;
return 0 ;
}
static struct V_37 * F_43 ( struct V_35 * V_36 , bool V_51 )
{
struct V_37 * V_38 = F_29 ( V_36 ) ;
if ( V_38 -> V_43 == NULL ) {
if ( F_31 ( V_36 ) < 0 )
return NULL ;
}
if ( ! V_38 -> V_43 -> V_47 && V_51 ) {
if ( F_34 ( V_36 ) < 0 )
return NULL ;
}
return V_38 ;
}
static int F_44 ( struct V_35 * V_36 , struct V_34 * V_34 ,
int V_58 , T_2 V_12 )
{
struct V_37 * V_38 ;
if ( V_36 == NULL )
return 0 ;
V_38 = F_43 ( V_36 , false ) ;
if ( V_38 == NULL )
return - V_66 ;
return F_39 ( V_36 , V_34 , V_38 , V_58 , V_12 ) ;
}
static int F_45 ( T_2 V_12 , T_2 V_50 ,
struct V_35 * V_36 , unsigned V_51 )
{
struct V_37 * V_38 ;
unsigned V_17 ;
if ( V_36 == NULL )
return 0 ;
V_38 = F_43 ( V_36 , true ) ;
if ( V_38 == NULL )
return - V_66 ;
if ( V_12 < V_36 -> V_50 || V_12 >= V_36 -> V_62 )
return - V_63 ;
if ( V_50 ) {
if ( V_50 < V_36 -> V_50 || V_50 >= V_36 -> V_62 )
return - V_63 ;
if ( V_50 >= V_12 )
V_50 = 0 ;
}
V_17 = V_12 - V_36 -> V_50 ;
return F_38 ( V_38 ,
V_50 ? V_50 - V_36 -> V_50 : 0 ,
V_17 , V_51 ,
! ! V_50 ) ;
}
int F_46 ( struct V_67 * V_68 ,
struct V_67 * V_50 ,
unsigned V_51 )
{
T_2 V_69 = 0 ;
int V_70 ;
if ( ! V_51 )
return 0 ;
if ( V_50 &&
( V_50 -> V_36 == V_68 -> V_36 ||
( V_68 -> V_36 &&
V_50 -> V_12 == V_68 -> V_36 -> V_50 + V_68 -> V_34 -> V_50 ) ) )
V_69 = V_50 -> V_71 ;
if ( V_69 == 0 )
F_47 ( L_18 V_14 L_19 V_14 L_20 V_14 L_21 V_14 L_10 ,
V_68 -> V_12 ,
V_50 ? V_50 -> V_12 : 0 ,
V_68 -> V_36 ? V_68 -> V_36 -> V_50 + V_68 -> V_34 -> V_50 : 0 ,
V_69 ) ;
V_70 = F_45 ( V_68 -> V_71 , V_69 , V_68 -> V_36 , V_51 ) ;
if ( V_70 )
F_47 ( L_22 , V_70 ) ;
return V_70 ;
}
int F_48 ( struct V_67 * V_68 , int V_58 )
{
return F_44 ( V_68 -> V_36 , V_68 -> V_34 , V_58 , V_68 -> V_71 ) ;
}
int F_49 ( struct V_72 * V_73 , int V_58 , T_2 V_74 )
{
return F_44 ( V_73 -> V_75 . V_36 , V_73 -> V_75 . V_34 , V_58 , V_74 ) ;
}
static void F_50 ( struct V_76 * V_77 )
{
V_77 -> V_7 = F_18 ( V_77 -> V_5 ) ;
if ( V_77 -> V_7 == NULL )
return;
if ( ! V_77 -> V_7 -> V_2 )
return;
if ( V_77 -> V_7 -> V_2 -> V_26 && V_77 -> V_7 -> V_2 -> V_26 ( & V_77 -> V_2 ) < 0 )
V_77 -> V_7 = NULL ;
}
static int F_17 ( char * line , char * * V_22 , char * * V_78 )
{
char * V_5 = line , V_79 ;
while ( isspace ( V_5 [ 0 ] ) )
++ V_5 ;
if ( V_5 [ 0 ] == '\0' )
return - 1 ;
* V_78 = V_5 + 1 ;
while ( ( * V_78 ) [ 0 ] != '\0' && ! isspace ( ( * V_78 ) [ 0 ] ) )
++ * V_78 ;
V_79 = ( * V_78 ) [ 0 ] ;
( * V_78 ) [ 0 ] = '\0' ;
* V_22 = F_8 ( V_5 ) ;
if ( * V_22 == NULL )
goto V_80;
( * V_78 ) [ 0 ] = V_79 ;
if ( ( * V_78 ) [ 0 ] != '\0' ) {
( * V_78 ) ++ ;
while ( isspace ( ( * V_78 ) [ 0 ] ) )
++ ( * V_78 ) ;
}
return 0 ;
V_80:
F_2 ( V_22 ) ;
return - 1 ;
}
static struct V_76 * F_51 ( T_3 V_17 , char * line ,
T_1 V_81 , int V_82 )
{
struct V_76 * V_77 = F_16 ( sizeof( * V_77 ) + V_81 ) ;
if ( V_77 != NULL ) {
V_77 -> V_17 = V_17 ;
V_77 -> line = F_8 ( line ) ;
V_77 -> V_82 = V_82 ;
if ( V_77 -> line == NULL )
goto V_83;
if ( V_17 != - 1 ) {
if ( F_17 ( V_77 -> line , & V_77 -> V_5 , & V_77 -> V_2 . V_4 ) < 0 )
goto V_84;
F_50 ( V_77 ) ;
}
}
return V_77 ;
V_84:
F_2 ( & V_77 -> line ) ;
V_83:
free ( V_77 ) ;
return NULL ;
}
void F_52 ( struct V_76 * V_77 )
{
F_2 ( & V_77 -> line ) ;
F_2 ( & V_77 -> V_5 ) ;
if ( V_77 -> V_7 && V_77 -> V_7 -> V_2 -> free )
V_77 -> V_7 -> V_2 -> free ( & V_77 -> V_2 ) ;
else
F_1 ( & V_77 -> V_2 ) ;
free ( V_77 ) ;
}
int F_53 ( struct V_76 * V_77 , char * V_8 , T_1 V_9 , bool V_4 )
{
if ( V_4 || ! V_77 -> V_7 )
return F_4 ( V_8 , V_9 , L_1 , V_77 -> V_5 , V_77 -> V_2 . V_4 ) ;
return F_5 ( V_77 -> V_7 , V_8 , V_9 , & V_77 -> V_2 ) ;
}
static void F_54 ( struct V_85 * V_86 , struct V_76 * line )
{
F_55 ( & line -> V_87 , V_86 ) ;
}
struct V_76 * F_56 ( struct V_85 * V_86 , struct V_76 * V_88 )
{
F_57 (pos, head, node)
if ( V_88 -> V_17 >= 0 )
return V_88 ;
return NULL ;
}
double F_58 ( struct V_37 * V_38 , int V_58 , T_3 V_17 ,
T_3 V_62 , const char * * V_89 , T_2 * V_90 )
{
struct V_91 * V_92 = V_38 -> V_43 -> V_93 ;
double V_94 = 0.0 ;
* V_90 = 0 ;
if ( V_92 ) {
T_1 V_95 = sizeof( * V_92 ) +
sizeof( V_92 -> V_96 ) * ( V_92 -> V_97 - 1 ) ;
while ( V_17 < V_62 ) {
V_92 = ( void * ) V_38 -> V_43 -> V_93 +
( V_95 * V_17 ) ;
if ( * V_89 == NULL )
* V_89 = V_92 -> V_89 ;
V_94 += V_92 -> V_96 [ V_58 ] . V_94 ;
* V_90 += V_92 -> V_96 [ V_58 ] . V_98 ;
V_17 ++ ;
}
} else {
struct V_42 * V_59 = F_42 ( V_38 , V_58 ) ;
unsigned int V_99 = 0 ;
while ( V_17 < V_62 )
V_99 += V_59 -> V_12 [ V_17 ++ ] ;
if ( V_59 -> V_64 ) {
* V_90 = V_99 ;
V_94 = 100.0 * V_99 / V_59 -> V_64 ;
}
}
return V_94 ;
}
static int F_59 ( struct V_76 * V_77 , struct V_35 * V_36 , T_2 V_50 ,
struct V_100 * V_101 , T_2 V_102 , int V_103 , int V_27 ,
int V_104 , struct V_76 * V_105 )
{
static const char * V_106 ;
static const char * V_107 ;
if ( V_77 -> V_17 != - 1 ) {
const char * V_89 = NULL ;
T_2 V_90 ;
double V_94 , V_108 = 0.0 ;
double * V_109 = & V_94 ;
T_2 * V_110 = & V_90 ;
int V_111 , V_112 = 1 ;
const char * V_113 ;
struct V_37 * V_38 = F_29 ( V_36 ) ;
T_3 V_17 = V_77 -> V_17 ;
const T_2 V_12 = V_50 + V_17 ;
struct V_76 * V_114 ;
V_114 = F_56 ( & V_38 -> V_43 -> V_3 , V_77 ) ;
if ( F_60 ( V_101 ) ) {
V_112 = V_101 -> V_115 ;
V_109 = calloc ( V_112 , sizeof( double ) ) ;
V_110 = calloc ( V_112 , sizeof( T_2 ) ) ;
if ( V_109 == NULL || V_110 == NULL ) {
return - 1 ;
}
}
for ( V_111 = 0 ; V_111 < V_112 ; V_111 ++ ) {
V_94 = F_58 ( V_38 ,
V_38 -> V_43 -> V_93 ? V_111 : V_101 -> V_116 + V_111 ,
V_17 ,
V_114 ? V_114 -> V_17 : ( T_3 ) V_102 ,
& V_89 , & V_90 ) ;
V_109 [ V_111 ] = V_94 ;
V_110 [ V_111 ] = V_90 ;
if ( V_94 > V_108 )
V_108 = V_94 ;
}
if ( V_108 < V_103 )
return - 1 ;
if ( V_104 && V_27 >= V_104 )
return 1 ;
if ( V_105 != NULL ) {
F_61 (queue, &notes->src->source, node) {
if ( V_105 == V_77 )
break;
F_59 ( V_105 , V_36 , V_50 , V_101 , V_102 ,
0 , 0 , 1 , NULL ) ;
}
}
V_113 = F_62 ( V_108 ) ;
if ( V_89 ) {
if ( ! V_106 || strcmp ( V_106 , V_89 )
|| V_113 != V_107 ) {
F_63 ( stdout , V_113 , L_23 , V_89 ) ;
V_106 = V_89 ;
V_107 = V_113 ;
}
}
for ( V_111 = 0 ; V_111 < V_112 ; V_111 ++ ) {
V_94 = V_109 [ V_111 ] ;
V_90 = V_110 [ V_111 ] ;
V_113 = F_62 ( V_94 ) ;
if ( V_44 . V_117 )
F_63 ( stdout , V_113 , L_24 V_65 ,
V_90 ) ;
else
F_63 ( stdout , V_113 , L_25 , V_94 ) ;
}
printf ( L_26 ) ;
F_63 ( stdout , V_118 , L_27 V_14 L_28 , V_12 ) ;
F_63 ( stdout , V_119 , L_29 , V_77 -> line ) ;
if ( V_109 != & V_94 )
free ( V_109 ) ;
if ( V_110 != & V_90 )
free ( V_110 ) ;
} else if ( V_104 && V_27 >= V_104 )
return 1 ;
else {
int V_120 = 8 ;
if ( V_105 )
return - 1 ;
if ( F_60 ( V_101 ) )
V_120 *= V_101 -> V_115 ;
if ( ! * V_77 -> line )
printf ( L_30 , V_120 , L_31 ) ;
else
printf ( L_32 , V_120 , L_31 , V_77 -> line ) ;
}
return 0 ;
}
static int F_64 ( struct V_35 * V_36 , struct V_34 * V_34 ,
T_4 * V_121 , T_1 V_81 ,
int * V_82 )
{
struct V_37 * V_38 = F_29 ( V_36 ) ;
struct V_76 * V_77 ;
char * line = NULL , * V_122 , * V_79 , * V_123 , * V_124 ;
T_1 V_125 ;
T_3 V_126 , V_17 = - 1 ;
T_5 V_127 [ 2 ] ;
if ( F_65 ( & line , & V_125 , V_121 ) < 0 )
return - 1 ;
if ( ! line )
return - 1 ;
while ( V_125 != 0 && isspace ( line [ V_125 - 1 ] ) )
line [ -- V_125 ] = '\0' ;
V_124 = strchr ( line , '\n' ) ;
if ( V_124 )
* V_124 = 0 ;
V_126 = - 1 ;
V_122 = line ;
if ( regexec ( & V_128 , line , 2 , V_127 , 0 ) == 0 ) {
* V_82 = atoi ( line + V_127 [ 1 ] . V_129 ) ;
return 0 ;
}
V_79 = line ;
while ( * V_79 ) {
if ( * V_79 != ' ' )
break;
V_79 ++ ;
}
if ( * V_79 ) {
V_126 = F_7 ( V_79 , & V_123 , 16 ) ;
if ( * V_123 != ':' || V_79 == V_123 || V_123 [ 1 ] == '\0' )
V_126 = - 1 ;
}
if ( V_126 != - 1 ) {
T_2 V_50 = F_66 ( V_34 , V_36 -> V_50 ) ,
V_62 = F_66 ( V_34 , V_36 -> V_62 ) ;
V_17 = V_126 - V_50 ;
if ( ( T_2 ) V_126 < V_50 || ( T_2 ) V_126 >= V_62 )
V_17 = - 1 ;
else
V_122 = V_123 + 1 ;
}
V_77 = F_51 ( V_17 , V_122 , V_81 , * V_82 ) ;
free ( line ) ;
( * V_82 ) ++ ;
if ( V_77 == NULL )
return - 1 ;
if ( V_77 -> V_2 . V_6 . V_17 == V_18 )
V_77 -> V_2 . V_6 . V_17 = V_77 -> V_2 . V_6 . V_12 -
F_66 ( V_34 , V_36 -> V_50 ) ;
if ( V_77 -> V_7 && F_10 ( V_77 -> V_7 ) && ! V_77 -> V_2 . V_6 . V_5 ) {
struct V_67 V_6 = {
. V_34 = V_34 ,
. V_12 = V_77 -> V_2 . V_6 . V_12 ,
} ;
if ( ! F_67 ( & V_6 , NULL ) &&
V_6 . V_36 -> V_50 == V_6 . V_71 )
V_77 -> V_2 . V_6 . V_5 = F_8 ( V_6 . V_36 -> V_5 ) ;
}
F_54 ( & V_38 -> V_43 -> V_3 , V_77 ) ;
return 0 ;
}
int F_68 ( struct V_35 * V_36 , struct V_34 * V_34 , T_1 V_81 )
{
struct V_130 * V_130 = V_34 -> V_130 ;
char * V_131 = F_69 ( V_130 , NULL , 0 ) ;
bool V_132 = true ;
char V_133 [ V_134 * 2 ] ;
T_4 * V_121 ;
int V_70 = 0 ;
char V_135 [ V_134 ] ;
struct V_136 V_137 ;
bool V_138 = false ;
int V_139 = 0 ;
int V_140 ;
if ( V_131 )
F_70 ( V_135 , V_131 ) ;
if ( V_131 == NULL ) {
if ( V_130 -> V_141 ) {
F_71 ( L_33 ,
V_36 -> V_5 ) ;
return - V_66 ;
}
goto V_142;
} else if ( F_72 ( V_130 ) ) {
goto V_142;
} else if ( F_73 ( V_135 , V_133 , sizeof( V_133 ) ) < 0 ||
strstr ( V_133 , L_34 ) ||
F_74 ( V_135 , V_143 ) ) {
free ( V_131 ) ;
V_142:
V_131 = ( char * ) V_130 -> V_144 ;
F_70 ( V_135 , V_131 ) ;
V_132 = false ;
}
if ( V_130 -> V_145 == V_146 &&
! F_72 ( V_130 ) ) {
char V_8 [ V_147 * 2 + 16 ] = L_35 ;
char * V_148 = NULL ;
if ( V_130 -> V_149 )
goto V_150;
if ( V_130 -> V_141 ) {
F_75 ( V_130 -> V_151 ,
sizeof( V_130 -> V_151 ) , V_8 + 15 ) ;
V_148 = V_8 ;
}
V_70 = - V_152 ;
V_130 -> V_149 = 1 ;
F_71 ( L_36
L_37
L_38
L_39
L_40
L_41
L_42 ,
V_36 -> V_5 , V_148 ? : L_43 ) ;
goto V_150;
}
F_41 ( L_44 V_14 L_13 V_14 L_10 , V_60 ,
V_131 , V_36 -> V_5 , V_34 -> V_61 ( V_34 , V_36 -> V_50 ) ,
V_34 -> V_61 ( V_34 , V_36 -> V_62 ) ) ;
F_41 ( L_45 ,
V_130 , V_130 -> V_144 , V_36 , V_36 -> V_5 ) ;
if ( F_72 ( V_130 ) ) {
V_137 . V_153 = V_135 ;
V_137 . V_12 = F_66 ( V_34 , V_36 -> V_50 ) ;
V_137 . V_154 = V_36 -> V_50 ;
V_137 . V_102 = V_36 -> V_62 - V_36 -> V_50 ;
if ( ! F_76 ( & V_137 ) ) {
V_138 = true ;
F_77 ( V_135 , V_137 . V_155 ,
sizeof( V_135 ) ) ;
if ( V_132 ) {
free ( V_131 ) ;
V_132 = false ;
}
V_131 = V_135 ;
}
} else if ( F_78 ( V_130 ) ) {
char V_79 [ V_134 ] ;
struct V_156 V_157 ;
int V_158 ;
bool V_159 ;
if ( F_79 ( & V_157 , V_135 ) )
goto V_150;
snprintf ( V_79 , V_134 , L_46 ) ;
V_158 = F_80 ( V_79 ) ;
if ( V_158 < 0 ) {
free ( V_157 . V_160 ) ;
goto V_150;
}
V_159 = F_81 ( V_157 . V_160 , V_135 , V_158 ) ;
if ( V_159 )
F_71 ( L_47 , V_157 . V_160 , V_135 ) ;
free ( V_157 . V_160 ) ;
F_82 ( V_158 ) ;
if ( ! V_159 )
goto V_150;
strcpy ( V_135 , V_79 ) ;
}
snprintf ( V_133 , sizeof( V_133 ) ,
L_48 V_14
L_49 V_14
L_50 ,
V_161 ? V_161 : L_51 ,
V_162 ? L_52 : L_43 ,
V_162 ? V_162 : L_43 ,
F_66 ( V_34 , V_36 -> V_50 ) ,
F_66 ( V_34 , V_36 -> V_62 ) ,
V_44 . V_163 ? L_43 : L_53 ,
V_44 . V_164 ? L_54 : L_43 ,
V_135 , V_131 ) ;
F_41 ( L_55 , V_133 ) ;
V_121 = F_83 ( V_133 , L_56 ) ;
if ( ! V_121 ) {
F_71 ( L_57 , V_133 ) ;
goto V_165;
}
V_140 = 0 ;
while ( ! feof ( V_121 ) ) {
if ( F_64 ( V_36 , V_34 , V_121 , V_81 ,
& V_139 ) < 0 )
break;
V_140 ++ ;
}
if ( V_140 == 0 )
F_71 ( L_58 , V_133 ) ;
if ( F_72 ( V_130 ) )
F_84 ( V_36 ) ;
F_85 ( V_121 ) ;
V_165:
if ( F_78 ( V_130 ) )
F_86 ( V_135 ) ;
V_150:
if ( V_138 )
F_87 ( & V_137 ) ;
if ( V_132 )
free ( V_131 ) ;
return V_70 ;
}
static void F_88 ( struct V_166 * V_167 , struct V_91 * V_92 )
{
struct V_91 * V_168 ;
struct V_169 * * V_170 = & V_167 -> V_169 ;
struct V_169 * V_171 = NULL ;
int V_111 , V_159 ;
while ( * V_170 != NULL ) {
V_171 = * V_170 ;
V_168 = F_89 ( V_171 , struct V_91 , V_87 ) ;
V_159 = strcmp ( V_168 -> V_89 , V_92 -> V_89 ) ;
if ( V_159 == 0 ) {
for ( V_111 = 0 ; V_111 < V_92 -> V_97 ; V_111 ++ )
V_168 -> V_96 [ V_111 ] . V_172 += V_92 -> V_96 [ V_111 ] . V_94 ;
return;
}
if ( V_159 < 0 )
V_170 = & ( * V_170 ) -> V_173 ;
else
V_170 = & ( * V_170 ) -> V_174 ;
}
for ( V_111 = 0 ; V_111 < V_92 -> V_97 ; V_111 ++ )
V_92 -> V_96 [ V_111 ] . V_172 = V_92 -> V_96 [ V_111 ] . V_94 ;
F_90 ( & V_92 -> V_87 , V_171 , V_170 ) ;
F_91 ( & V_92 -> V_87 , V_167 ) ;
}
static int F_92 ( struct V_91 * V_175 , struct V_91 * V_176 )
{
int V_111 ;
for ( V_111 = 0 ; V_111 < V_175 -> V_97 ; V_111 ++ ) {
if ( V_175 -> V_96 [ V_111 ] . V_172 == V_176 -> V_96 [ V_111 ] . V_172 )
continue;
return V_175 -> V_96 [ V_111 ] . V_172 > V_176 -> V_96 [ V_111 ] . V_172 ;
}
return 0 ;
}
static void F_93 ( struct V_166 * V_167 , struct V_91 * V_92 )
{
struct V_91 * V_168 ;
struct V_169 * * V_170 = & V_167 -> V_169 ;
struct V_169 * V_171 = NULL ;
while ( * V_170 != NULL ) {
V_171 = * V_170 ;
V_168 = F_89 ( V_171 , struct V_91 , V_87 ) ;
if ( F_92 ( V_92 , V_168 ) )
V_170 = & ( * V_170 ) -> V_173 ;
else
V_170 = & ( * V_170 ) -> V_174 ;
}
F_90 ( & V_92 -> V_87 , V_171 , V_170 ) ;
F_91 ( & V_92 -> V_87 , V_167 ) ;
}
static void F_94 ( struct V_166 * V_177 , struct V_166 * V_178 )
{
struct V_91 * V_92 ;
struct V_169 * V_87 ;
V_87 = F_95 ( V_178 ) ;
while ( V_87 ) {
struct V_169 * V_114 ;
V_92 = F_89 ( V_87 , struct V_91 , V_87 ) ;
V_114 = F_96 ( V_87 ) ;
F_97 ( V_87 , V_178 ) ;
F_93 ( V_177 , V_92 ) ;
V_87 = V_114 ;
}
}
static void F_98 ( struct V_35 * V_36 , int V_102 )
{
struct V_37 * V_38 = F_29 ( V_36 ) ;
struct V_91 * V_92 = V_38 -> V_43 -> V_93 ;
T_1 V_95 ;
int V_111 ;
V_95 = sizeof( * V_92 ) +
( sizeof( V_92 -> V_96 ) * ( V_92 -> V_97 - 1 ) ) ;
for ( V_111 = 0 ; V_111 < V_102 ; V_111 ++ ) {
F_99 ( V_92 -> V_89 ) ;
V_92 = ( void * ) V_92 + V_95 ;
}
F_2 ( & V_38 -> V_43 -> V_93 ) ;
}
static int F_100 ( struct V_35 * V_36 , struct V_34 * V_34 ,
struct V_100 * V_101 ,
struct V_166 * V_167 , int V_102 )
{
T_2 V_50 ;
int V_111 , V_179 ;
int V_58 = V_101 -> V_116 ;
struct V_91 * V_92 ;
struct V_37 * V_38 = F_29 ( V_36 ) ;
struct V_42 * V_59 = F_42 ( V_38 , V_58 ) ;
struct V_166 V_180 = V_181 ;
int V_97 = 1 ;
T_2 V_182 = V_59 -> V_64 ;
T_1 V_95 = sizeof( struct V_91 ) ;
if ( F_60 ( V_101 ) ) {
for ( V_111 = 1 ; V_111 < V_101 -> V_115 ; V_111 ++ ) {
V_59 = F_42 ( V_38 , V_58 + V_111 ) ;
V_182 += V_59 -> V_64 ;
}
V_97 = V_101 -> V_115 ;
V_95 += ( V_97 - 1 ) * sizeof( V_92 -> V_96 ) ;
}
if ( ! V_182 )
return 0 ;
V_92 = V_38 -> V_43 -> V_93 = calloc ( V_102 , V_95 ) ;
if ( ! V_38 -> V_43 -> V_93 )
return - 1 ;
V_50 = F_66 ( V_34 , V_36 -> V_50 ) ;
for ( V_111 = 0 ; V_111 < V_102 ; V_111 ++ ) {
T_2 V_17 ;
double V_183 = 0.0 ;
V_92 -> V_97 = V_97 ;
for ( V_179 = 0 ; V_179 < V_97 ; V_179 ++ ) {
V_59 = F_42 ( V_38 , V_58 + V_179 ) ;
V_92 -> V_96 [ V_179 ] . V_94 = 100.0 * V_59 -> V_12 [ V_111 ] / V_59 -> V_64 ;
if ( V_92 -> V_96 [ V_179 ] . V_94 > V_183 )
V_183 = V_92 -> V_96 [ V_179 ] . V_94 ;
}
if ( V_183 <= 0.5 )
goto V_114;
V_17 = V_50 + V_111 ;
V_92 -> V_89 = F_101 ( V_34 -> V_130 , V_17 , NULL , false ) ;
F_88 ( & V_180 , V_92 ) ;
V_114:
V_92 = ( void * ) V_92 + V_95 ;
}
F_94 ( V_167 , & V_180 ) ;
return 0 ;
}
static void F_102 ( struct V_166 * V_167 , const char * V_131 )
{
struct V_91 * V_92 ;
struct V_169 * V_87 ;
printf ( L_59 , V_131 ) ;
printf ( L_60 ) ;
if ( F_103 ( V_167 ) ) {
printf ( L_61 , V_184 ) ;
return;
}
V_87 = F_95 ( V_167 ) ;
while ( V_87 ) {
double V_94 , V_183 = 0.0 ;
const char * V_113 ;
char * V_89 ;
int V_111 ;
V_92 = F_89 ( V_87 , struct V_91 , V_87 ) ;
for ( V_111 = 0 ; V_111 < V_92 -> V_97 ; V_111 ++ ) {
V_94 = V_92 -> V_96 [ V_111 ] . V_172 ;
V_113 = F_62 ( V_94 ) ;
F_63 ( stdout , V_113 , L_25 , V_94 ) ;
if ( V_94 > V_183 )
V_183 = V_94 ;
}
V_89 = V_92 -> V_89 ;
V_113 = F_62 ( V_183 ) ;
F_63 ( stdout , V_113 , L_62 , V_89 ) ;
V_87 = F_96 ( V_87 ) ;
}
}
static void F_104 ( struct V_35 * V_36 , struct V_100 * V_101 )
{
struct V_37 * V_38 = F_29 ( V_36 ) ;
struct V_42 * V_59 = F_42 ( V_38 , V_101 -> V_116 ) ;
T_2 V_102 = F_32 ( V_36 ) , V_17 ;
for ( V_17 = 0 ; V_17 < V_102 ; ++ V_17 )
if ( V_59 -> V_12 [ V_17 ] != 0 )
printf ( L_63 V_14 L_64 V_65 L_10 , V_185 / 2 ,
V_36 -> V_50 + V_17 , V_59 -> V_12 [ V_17 ] ) ;
printf ( L_65 V_65 L_10 , V_185 / 2 , L_66 , V_59 -> V_64 ) ;
}
int F_105 ( struct V_35 * V_36 , struct V_34 * V_34 ,
struct V_100 * V_101 , bool V_186 ,
int V_103 , int V_104 , int V_187 )
{
struct V_130 * V_130 = V_34 -> V_130 ;
char * V_131 ;
const char * V_188 ;
const char * V_189 = F_106 ( V_101 ) ;
struct V_37 * V_38 = F_29 ( V_36 ) ;
struct V_76 * V_88 , * V_105 = NULL ;
T_2 V_50 = F_66 ( V_34 , V_36 -> V_50 ) ;
int V_27 = 2 , V_190 = 0 ;
int V_191 = 0 ;
T_2 V_102 ;
int V_120 = 8 ;
int V_192 , V_193 , V_194 ;
V_131 = F_8 ( V_130 -> V_144 ) ;
if ( ! V_131 )
return - V_66 ;
if ( V_186 )
V_188 = V_131 ;
else
V_188 = F_107 ( V_131 ) ;
V_102 = F_32 ( V_36 ) ;
V_192 = strlen ( V_188 ) ;
V_193 = strlen ( V_189 ) ;
if ( F_60 ( V_101 ) )
V_120 *= V_101 -> V_115 ;
printf ( L_67 ,
V_120 , V_120 , L_68 , V_188 , V_189 ) ;
V_194 = V_120 + V_192 + V_193 ;
printf ( L_69 ,
V_194 , V_194 , V_195 ) ;
if ( V_196 )
F_104 ( V_36 , V_101 ) ;
F_108 (pos, &notes->src->source, node) {
if ( V_187 && V_105 == NULL ) {
V_105 = V_88 ;
V_190 = 0 ;
}
switch ( F_59 ( V_88 , V_36 , V_50 , V_101 , V_102 ,
V_103 , V_27 , V_104 ,
V_105 ) ) {
case 0 :
++ V_27 ;
if ( V_187 ) {
V_27 += V_190 ;
V_105 = NULL ;
V_190 = 0 ;
}
break;
case 1 :
++ V_191 ;
break;
case - 1 :
default:
if ( ! V_187 )
break;
if ( V_190 == V_187 )
V_105 = F_109 ( V_105 -> V_87 . V_114 , F_110 ( * V_105 ) , V_87 ) ;
else
++ V_190 ;
break;
}
}
free ( V_131 ) ;
return V_191 ;
}
void F_111 ( struct V_35 * V_36 , int V_58 )
{
struct V_37 * V_38 = F_29 ( V_36 ) ;
struct V_42 * V_59 = F_42 ( V_38 , V_58 ) ;
memset ( V_59 , 0 , V_38 -> V_43 -> V_40 ) ;
}
void F_112 ( struct V_35 * V_36 , int V_58 )
{
struct V_37 * V_38 = F_29 ( V_36 ) ;
struct V_42 * V_59 = F_42 ( V_38 , V_58 ) ;
int V_102 = F_32 ( V_36 ) , V_17 ;
V_59 -> V_64 = 0 ;
for ( V_17 = 0 ; V_17 < V_102 ; ++ V_17 ) {
V_59 -> V_12 [ V_17 ] = V_59 -> V_12 [ V_17 ] * 7 / 8 ;
V_59 -> V_64 += V_59 -> V_12 [ V_17 ] ;
}
}
void F_113 ( struct V_85 * V_86 )
{
struct V_76 * V_88 , * V_197 ;
F_114 (pos, n, head, node) {
F_115 ( & V_88 -> V_87 ) ;
F_52 ( V_88 ) ;
}
}
static T_1 F_116 ( struct V_76 * V_77 , T_4 * V_198 )
{
T_1 V_27 ;
if ( V_77 -> V_17 == - 1 )
return fprintf ( V_198 , L_29 , V_77 -> line ) ;
V_27 = fprintf ( V_198 , L_14 V_14 L_23 , V_77 -> V_17 , V_77 -> V_5 ) ;
if ( V_77 -> V_2 . V_4 [ 0 ] != '\0' ) {
V_27 += fprintf ( V_198 , L_70 , 6 - ( int ) V_27 , L_31 ,
V_77 -> V_2 . V_4 ) ;
}
return V_27 + fprintf ( V_198 , L_10 ) ;
}
T_1 F_117 ( struct V_85 * V_86 , T_4 * V_198 )
{
struct V_76 * V_88 ;
T_1 V_27 = 0 ;
F_108 (pos, head, node)
V_27 += F_116 ( V_88 , V_198 ) ;
return V_27 ;
}
int F_118 ( struct V_35 * V_36 , struct V_34 * V_34 ,
struct V_100 * V_101 , bool V_199 ,
bool V_186 , int V_103 , int V_104 )
{
struct V_130 * V_130 = V_34 -> V_130 ;
struct V_166 V_91 = V_181 ;
T_2 V_102 ;
if ( F_68 ( V_36 , V_34 , 0 ) < 0 )
return - 1 ;
V_102 = F_32 ( V_36 ) ;
if ( V_199 ) {
V_200 = V_186 ;
F_100 ( V_36 , V_34 , V_101 , & V_91 , V_102 ) ;
F_102 ( & V_91 , V_130 -> V_144 ) ;
}
F_105 ( V_36 , V_34 , V_101 , V_186 ,
V_103 , V_104 , 0 ) ;
if ( V_199 )
F_98 ( V_36 , V_102 ) ;
F_113 ( & F_29 ( V_36 ) -> V_43 -> V_3 ) ;
return 0 ;
}
int F_119 ( struct V_72 * V_73 , T_1 V_81 )
{
return F_68 ( V_73 -> V_75 . V_36 , V_73 -> V_75 . V_34 , V_81 ) ;
}
bool F_120 ( void )
{
return V_201 == 1 && V_202 ;
}
