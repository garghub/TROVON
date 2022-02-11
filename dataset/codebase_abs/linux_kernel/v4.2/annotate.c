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
void F_34 ( struct V_35 * V_36 )
{
struct V_37 * V_38 = F_29 ( V_36 ) ;
F_35 ( & V_38 -> V_39 ) ;
if ( V_38 -> V_43 != NULL )
memset ( V_38 -> V_43 -> V_47 , 0 ,
V_38 -> V_43 -> V_46 * V_38 -> V_43 -> V_40 ) ;
F_36 ( & V_38 -> V_39 ) ;
}
static int F_37 ( struct V_35 * V_36 , struct V_34 * V_34 ,
struct V_37 * V_38 , int V_48 , T_2 V_12 )
{
unsigned V_17 ;
struct V_42 * V_49 ;
F_38 ( L_9 V_14 L_10 , V_50 , V_34 -> V_51 ( V_34 , V_12 ) ) ;
if ( V_12 < V_36 -> V_52 || V_12 >= V_36 -> V_53 )
return - V_54 ;
V_17 = V_12 - V_36 -> V_52 ;
V_49 = F_39 ( V_38 , V_48 ) ;
V_49 -> V_55 ++ ;
V_49 -> V_12 [ V_17 ] ++ ;
F_38 ( L_11 V_14 L_12 V_14 L_13 V_14
L_14 V_56 L_10 , V_36 -> V_52 , V_36 -> V_5 ,
V_12 , V_12 - V_36 -> V_52 , V_48 , V_49 -> V_12 [ V_17 ] ) ;
return 0 ;
}
static struct V_37 * F_40 ( struct V_35 * V_36 )
{
struct V_37 * V_38 = F_29 ( V_36 ) ;
if ( V_38 -> V_43 == NULL ) {
if ( F_31 ( V_36 ) < 0 )
return NULL ;
}
return V_38 ;
}
static int F_41 ( struct V_35 * V_36 , struct V_34 * V_34 ,
int V_48 , T_2 V_12 )
{
struct V_37 * V_38 ;
if ( V_36 == NULL )
return 0 ;
V_38 = F_40 ( V_36 ) ;
if ( V_38 == NULL )
return - V_57 ;
return F_37 ( V_36 , V_34 , V_38 , V_48 , V_12 ) ;
}
int F_42 ( struct V_58 * V_59 , int V_48 )
{
return F_41 ( V_59 -> V_36 , V_59 -> V_34 , V_48 , V_59 -> V_60 ) ;
}
int F_43 ( struct V_61 * V_62 , int V_48 , T_2 V_63 )
{
return F_41 ( V_62 -> V_64 . V_36 , V_62 -> V_64 . V_34 , V_48 , V_63 ) ;
}
static void F_44 ( struct V_65 * V_66 )
{
V_66 -> V_7 = F_18 ( V_66 -> V_5 ) ;
if ( V_66 -> V_7 == NULL )
return;
if ( ! V_66 -> V_7 -> V_2 )
return;
if ( V_66 -> V_7 -> V_2 -> V_26 && V_66 -> V_7 -> V_2 -> V_26 ( & V_66 -> V_2 ) < 0 )
V_66 -> V_7 = NULL ;
}
static int F_17 ( char * line , char * * V_22 , char * * V_67 )
{
char * V_5 = line , V_68 ;
while ( isspace ( V_5 [ 0 ] ) )
++ V_5 ;
if ( V_5 [ 0 ] == '\0' )
return - 1 ;
* V_67 = V_5 + 1 ;
while ( ( * V_67 ) [ 0 ] != '\0' && ! isspace ( ( * V_67 ) [ 0 ] ) )
++ * V_67 ;
V_68 = ( * V_67 ) [ 0 ] ;
( * V_67 ) [ 0 ] = '\0' ;
* V_22 = F_8 ( V_5 ) ;
if ( * V_22 == NULL )
goto V_69;
( * V_67 ) [ 0 ] = V_68 ;
if ( ( * V_67 ) [ 0 ] != '\0' ) {
( * V_67 ) ++ ;
while ( isspace ( ( * V_67 ) [ 0 ] ) )
++ ( * V_67 ) ;
}
return 0 ;
V_69:
F_2 ( V_22 ) ;
return - 1 ;
}
static struct V_65 * F_45 ( T_3 V_17 , char * line ,
T_1 V_70 , int V_71 )
{
struct V_65 * V_66 = F_16 ( sizeof( * V_66 ) + V_70 ) ;
if ( V_66 != NULL ) {
V_66 -> V_17 = V_17 ;
V_66 -> line = F_8 ( line ) ;
V_66 -> V_71 = V_71 ;
if ( V_66 -> line == NULL )
goto V_72;
if ( V_17 != - 1 ) {
if ( F_17 ( V_66 -> line , & V_66 -> V_5 , & V_66 -> V_2 . V_4 ) < 0 )
goto V_73;
F_44 ( V_66 ) ;
}
}
return V_66 ;
V_73:
F_2 ( & V_66 -> line ) ;
V_72:
free ( V_66 ) ;
return NULL ;
}
void F_46 ( struct V_65 * V_66 )
{
F_2 ( & V_66 -> line ) ;
F_2 ( & V_66 -> V_5 ) ;
if ( V_66 -> V_7 && V_66 -> V_7 -> V_2 -> free )
V_66 -> V_7 -> V_2 -> free ( & V_66 -> V_2 ) ;
else
F_1 ( & V_66 -> V_2 ) ;
free ( V_66 ) ;
}
int F_47 ( struct V_65 * V_66 , char * V_8 , T_1 V_9 , bool V_4 )
{
if ( V_4 || ! V_66 -> V_7 )
return F_4 ( V_8 , V_9 , L_1 , V_66 -> V_5 , V_66 -> V_2 . V_4 ) ;
return F_5 ( V_66 -> V_7 , V_8 , V_9 , & V_66 -> V_2 ) ;
}
static void F_48 ( struct V_74 * V_75 , struct V_65 * line )
{
F_49 ( & line -> V_76 , V_75 ) ;
}
struct V_65 * F_50 ( struct V_74 * V_75 , struct V_65 * V_77 )
{
F_51 (pos, head, node)
if ( V_77 -> V_17 >= 0 )
return V_77 ;
return NULL ;
}
double F_52 ( struct V_37 * V_38 , int V_48 , T_3 V_17 ,
T_3 V_53 , const char * * V_78 , T_2 * V_79 )
{
struct V_80 * V_81 = V_38 -> V_43 -> V_82 ;
double V_83 = 0.0 ;
* V_79 = 0 ;
if ( V_81 ) {
T_1 V_84 = sizeof( * V_81 ) +
sizeof( V_81 -> V_85 ) * ( V_81 -> V_86 - 1 ) ;
while ( V_17 < V_53 ) {
V_81 = ( void * ) V_38 -> V_43 -> V_82 +
( V_84 * V_17 ) ;
if ( * V_78 == NULL )
* V_78 = V_81 -> V_78 ;
V_83 += V_81 -> V_85 [ V_48 ] . V_83 ;
* V_79 += V_81 -> V_85 [ V_48 ] . V_87 ;
V_17 ++ ;
}
} else {
struct V_42 * V_49 = F_39 ( V_38 , V_48 ) ;
unsigned int V_88 = 0 ;
while ( V_17 < V_53 )
V_88 += V_49 -> V_12 [ V_17 ++ ] ;
if ( V_49 -> V_55 ) {
* V_79 = V_88 ;
V_83 = 100.0 * V_88 / V_49 -> V_55 ;
}
}
return V_83 ;
}
static int F_53 ( struct V_65 * V_66 , struct V_35 * V_36 , T_2 V_52 ,
struct V_89 * V_90 , T_2 V_91 , int V_92 , int V_27 ,
int V_93 , struct V_65 * V_94 )
{
static const char * V_95 ;
static const char * V_96 ;
if ( V_66 -> V_17 != - 1 ) {
const char * V_78 = NULL ;
T_2 V_79 ;
double V_83 , V_97 = 0.0 ;
double * V_98 = & V_83 ;
T_2 * V_99 = & V_79 ;
int V_100 , V_101 = 1 ;
const char * V_102 ;
struct V_37 * V_38 = F_29 ( V_36 ) ;
T_3 V_17 = V_66 -> V_17 ;
const T_2 V_12 = V_52 + V_17 ;
struct V_65 * V_103 ;
V_103 = F_50 ( & V_38 -> V_43 -> V_3 , V_66 ) ;
if ( F_54 ( V_90 ) ) {
V_101 = V_90 -> V_104 ;
V_98 = calloc ( V_101 , sizeof( double ) ) ;
V_99 = calloc ( V_101 , sizeof( T_2 ) ) ;
if ( V_98 == NULL || V_99 == NULL ) {
return - 1 ;
}
}
for ( V_100 = 0 ; V_100 < V_101 ; V_100 ++ ) {
V_83 = F_52 ( V_38 ,
V_38 -> V_43 -> V_82 ? V_100 : V_90 -> V_105 + V_100 ,
V_17 ,
V_103 ? V_103 -> V_17 : ( T_3 ) V_91 ,
& V_78 , & V_79 ) ;
V_98 [ V_100 ] = V_83 ;
V_99 [ V_100 ] = V_79 ;
if ( V_83 > V_97 )
V_97 = V_83 ;
}
if ( V_97 < V_92 )
return - 1 ;
if ( V_93 && V_27 >= V_93 )
return 1 ;
if ( V_94 != NULL ) {
F_55 (queue, &notes->src->source, node) {
if ( V_94 == V_66 )
break;
F_53 ( V_94 , V_36 , V_52 , V_90 , V_91 ,
0 , 0 , 1 , NULL ) ;
}
}
V_102 = F_56 ( V_97 ) ;
if ( V_78 ) {
if ( ! V_95 || strcmp ( V_95 , V_78 )
|| V_102 != V_96 ) {
F_57 ( stdout , V_102 , L_15 , V_78 ) ;
V_95 = V_78 ;
V_96 = V_102 ;
}
}
for ( V_100 = 0 ; V_100 < V_101 ; V_100 ++ ) {
V_83 = V_98 [ V_100 ] ;
V_79 = V_99 [ V_100 ] ;
V_102 = F_56 ( V_83 ) ;
if ( V_44 . V_106 )
F_57 ( stdout , V_102 , L_16 V_56 ,
V_79 ) ;
else
F_57 ( stdout , V_102 , L_17 , V_83 ) ;
}
printf ( L_18 ) ;
F_57 ( stdout , V_107 , L_19 V_14 L_20 , V_12 ) ;
F_57 ( stdout , V_108 , L_21 , V_66 -> line ) ;
if ( V_98 != & V_83 )
free ( V_98 ) ;
if ( V_99 != & V_79 )
free ( V_99 ) ;
} else if ( V_93 && V_27 >= V_93 )
return 1 ;
else {
int V_109 = 8 ;
if ( V_94 )
return - 1 ;
if ( F_54 ( V_90 ) )
V_109 *= V_90 -> V_104 ;
if ( ! * V_66 -> line )
printf ( L_22 , V_109 , L_23 ) ;
else
printf ( L_24 , V_109 , L_23 , V_66 -> line ) ;
}
return 0 ;
}
static int F_58 ( struct V_35 * V_36 , struct V_34 * V_34 ,
T_4 * V_110 , T_1 V_70 ,
int * V_71 )
{
struct V_37 * V_38 = F_29 ( V_36 ) ;
struct V_65 * V_66 ;
char * line = NULL , * V_111 , * V_68 , * V_112 , * V_113 ;
T_1 V_114 ;
T_3 V_115 , V_17 = - 1 ;
T_5 V_116 [ 2 ] ;
if ( F_59 ( & line , & V_114 , V_110 ) < 0 )
return - 1 ;
if ( ! line )
return - 1 ;
while ( V_114 != 0 && isspace ( line [ V_114 - 1 ] ) )
line [ -- V_114 ] = '\0' ;
V_113 = strchr ( line , '\n' ) ;
if ( V_113 )
* V_113 = 0 ;
V_115 = - 1 ;
V_111 = line ;
if ( regexec ( & V_117 , line , 2 , V_116 , 0 ) == 0 ) {
* V_71 = atoi ( line + V_116 [ 1 ] . V_118 ) ;
return 0 ;
}
V_68 = line ;
while ( * V_68 ) {
if ( * V_68 != ' ' )
break;
V_68 ++ ;
}
if ( * V_68 ) {
V_115 = F_7 ( V_68 , & V_112 , 16 ) ;
if ( * V_112 != ':' || V_68 == V_112 || V_112 [ 1 ] == '\0' )
V_115 = - 1 ;
}
if ( V_115 != - 1 ) {
T_2 V_52 = F_60 ( V_34 , V_36 -> V_52 ) ,
V_53 = F_60 ( V_34 , V_36 -> V_53 ) ;
V_17 = V_115 - V_52 ;
if ( ( T_2 ) V_115 < V_52 || ( T_2 ) V_115 >= V_53 )
V_17 = - 1 ;
else
V_111 = V_112 + 1 ;
}
V_66 = F_45 ( V_17 , V_111 , V_70 , * V_71 ) ;
free ( line ) ;
( * V_71 ) ++ ;
if ( V_66 == NULL )
return - 1 ;
if ( V_66 -> V_2 . V_6 . V_17 == V_18 )
V_66 -> V_2 . V_6 . V_17 = V_66 -> V_2 . V_6 . V_12 -
F_60 ( V_34 , V_36 -> V_52 ) ;
if ( V_66 -> V_7 && F_10 ( V_66 -> V_7 ) && ! V_66 -> V_2 . V_6 . V_5 ) {
struct V_58 V_6 = {
. V_34 = V_34 ,
. V_12 = V_66 -> V_2 . V_6 . V_12 ,
} ;
if ( ! F_61 ( & V_6 , NULL ) &&
V_6 . V_36 -> V_52 == V_6 . V_60 )
V_66 -> V_2 . V_6 . V_5 = F_8 ( V_6 . V_36 -> V_5 ) ;
}
F_48 ( & V_38 -> V_43 -> V_3 , V_66 ) ;
return 0 ;
}
int F_62 ( struct V_35 * V_36 , struct V_34 * V_34 , T_1 V_70 )
{
struct V_119 * V_119 = V_34 -> V_119 ;
char * V_120 = F_63 ( V_119 , NULL , 0 ) ;
bool V_121 = true ;
char V_122 [ V_123 * 2 ] ;
T_4 * V_110 ;
int V_124 = 0 ;
char V_125 [ V_123 ] ;
struct V_126 V_127 ;
bool V_128 = false ;
int V_129 = 0 ;
if ( V_120 )
F_64 ( V_125 , V_120 ) ;
if ( V_120 == NULL ) {
if ( V_119 -> V_130 ) {
F_65 ( L_25 ,
V_36 -> V_5 ) ;
return - V_57 ;
}
goto V_131;
} else if ( F_66 ( V_119 ) ) {
goto V_131;
} else if ( F_67 ( V_125 , V_122 , sizeof( V_122 ) ) < 0 ||
strstr ( V_122 , L_26 ) ||
F_68 ( V_125 , V_132 ) ) {
free ( V_120 ) ;
V_131:
V_120 = ( char * ) V_119 -> V_133 ;
F_64 ( V_125 , V_120 ) ;
V_121 = false ;
}
if ( V_119 -> V_134 == V_135 &&
! F_66 ( V_119 ) ) {
char V_8 [ V_136 * 2 + 16 ] = L_27 ;
char * V_137 = NULL ;
if ( V_119 -> V_138 )
goto V_139;
if ( V_119 -> V_130 ) {
F_69 ( V_119 -> V_140 ,
sizeof( V_119 -> V_140 ) , V_8 + 15 ) ;
V_137 = V_8 ;
}
V_124 = - V_141 ;
V_119 -> V_138 = 1 ;
F_65 ( L_28
L_29
L_30
L_31
L_32
L_33 ,
V_36 -> V_5 , V_137 ? : L_34 ) ;
goto V_139;
}
F_70 ( L_35 V_14 L_36 V_14 L_10 , V_50 ,
V_120 , V_36 -> V_5 , V_34 -> V_51 ( V_34 , V_36 -> V_52 ) ,
V_34 -> V_51 ( V_34 , V_36 -> V_53 ) ) ;
F_70 ( L_37 ,
V_119 , V_119 -> V_133 , V_36 , V_36 -> V_5 ) ;
if ( F_66 ( V_119 ) ) {
V_127 . V_142 = V_125 ;
V_127 . V_12 = F_60 ( V_34 , V_36 -> V_52 ) ;
V_127 . V_143 = V_36 -> V_52 ;
V_127 . V_91 = V_36 -> V_53 - V_36 -> V_52 ;
if ( ! F_71 ( & V_127 ) ) {
V_128 = true ;
F_72 ( V_125 , V_127 . V_144 ,
sizeof( V_125 ) ) ;
if ( V_121 ) {
free ( V_120 ) ;
V_121 = false ;
}
V_120 = V_125 ;
}
} else if ( F_73 ( V_119 ) ) {
char V_68 [ V_123 ] ;
struct V_145 V_146 ;
int V_147 ;
bool V_148 ;
if ( F_74 ( & V_146 , V_125 ) )
goto V_139;
snprintf ( V_68 , V_123 , L_38 ) ;
V_147 = F_75 ( V_68 ) ;
if ( V_147 < 0 ) {
free ( V_146 . V_149 ) ;
goto V_139;
}
V_148 = F_76 ( V_146 . V_149 , V_125 , V_147 ) ;
free ( V_146 . V_149 ) ;
F_77 ( V_147 ) ;
if ( ! V_148 )
goto V_139;
strcpy ( V_125 , V_68 ) ;
}
snprintf ( V_122 , sizeof( V_122 ) ,
L_39 V_14
L_40 V_14
L_41 ,
V_150 ? V_150 : L_42 ,
V_151 ? L_43 : L_34 ,
V_151 ? V_151 : L_34 ,
F_60 ( V_34 , V_36 -> V_52 ) ,
F_60 ( V_34 , V_36 -> V_53 ) ,
V_44 . V_152 ? L_34 : L_44 ,
V_44 . V_153 ? L_45 : L_34 ,
V_125 , V_120 ) ;
F_70 ( L_46 , V_122 ) ;
V_110 = F_78 ( V_122 , L_47 ) ;
if ( ! V_110 )
goto V_154;
while ( ! feof ( V_110 ) )
if ( F_58 ( V_36 , V_34 , V_110 , V_70 ,
& V_129 ) < 0 )
break;
if ( F_66 ( V_119 ) )
F_79 ( V_36 ) ;
F_80 ( V_110 ) ;
V_154:
if ( F_73 ( V_119 ) )
F_81 ( V_125 ) ;
V_139:
if ( V_128 )
F_82 ( & V_127 ) ;
if ( V_121 )
free ( V_120 ) ;
return V_124 ;
}
static void F_83 ( struct V_155 * V_156 , struct V_80 * V_81 )
{
struct V_80 * V_157 ;
struct V_158 * * V_159 = & V_156 -> V_158 ;
struct V_158 * V_160 = NULL ;
int V_100 , V_148 ;
while ( * V_159 != NULL ) {
V_160 = * V_159 ;
V_157 = F_84 ( V_160 , struct V_80 , V_76 ) ;
V_148 = strcmp ( V_157 -> V_78 , V_81 -> V_78 ) ;
if ( V_148 == 0 ) {
for ( V_100 = 0 ; V_100 < V_81 -> V_86 ; V_100 ++ )
V_157 -> V_85 [ V_100 ] . V_161 += V_81 -> V_85 [ V_100 ] . V_83 ;
return;
}
if ( V_148 < 0 )
V_159 = & ( * V_159 ) -> V_162 ;
else
V_159 = & ( * V_159 ) -> V_163 ;
}
for ( V_100 = 0 ; V_100 < V_81 -> V_86 ; V_100 ++ )
V_81 -> V_85 [ V_100 ] . V_161 = V_81 -> V_85 [ V_100 ] . V_83 ;
F_85 ( & V_81 -> V_76 , V_160 , V_159 ) ;
F_86 ( & V_81 -> V_76 , V_156 ) ;
}
static int F_87 ( struct V_80 * V_164 , struct V_80 * V_165 )
{
int V_100 ;
for ( V_100 = 0 ; V_100 < V_164 -> V_86 ; V_100 ++ ) {
if ( V_164 -> V_85 [ V_100 ] . V_161 == V_165 -> V_85 [ V_100 ] . V_161 )
continue;
return V_164 -> V_85 [ V_100 ] . V_161 > V_165 -> V_85 [ V_100 ] . V_161 ;
}
return 0 ;
}
static void F_88 ( struct V_155 * V_156 , struct V_80 * V_81 )
{
struct V_80 * V_157 ;
struct V_158 * * V_159 = & V_156 -> V_158 ;
struct V_158 * V_160 = NULL ;
while ( * V_159 != NULL ) {
V_160 = * V_159 ;
V_157 = F_84 ( V_160 , struct V_80 , V_76 ) ;
if ( F_87 ( V_81 , V_157 ) )
V_159 = & ( * V_159 ) -> V_162 ;
else
V_159 = & ( * V_159 ) -> V_163 ;
}
F_85 ( & V_81 -> V_76 , V_160 , V_159 ) ;
F_86 ( & V_81 -> V_76 , V_156 ) ;
}
static void F_89 ( struct V_155 * V_166 , struct V_155 * V_167 )
{
struct V_80 * V_81 ;
struct V_158 * V_76 ;
V_76 = F_90 ( V_167 ) ;
while ( V_76 ) {
struct V_158 * V_103 ;
V_81 = F_84 ( V_76 , struct V_80 , V_76 ) ;
V_103 = F_91 ( V_76 ) ;
F_92 ( V_76 , V_167 ) ;
F_88 ( V_166 , V_81 ) ;
V_76 = V_103 ;
}
}
static void F_93 ( struct V_35 * V_36 , int V_91 )
{
struct V_37 * V_38 = F_29 ( V_36 ) ;
struct V_80 * V_81 = V_38 -> V_43 -> V_82 ;
T_1 V_84 ;
int V_100 ;
V_84 = sizeof( * V_81 ) +
( sizeof( V_81 -> V_85 ) * ( V_81 -> V_86 - 1 ) ) ;
for ( V_100 = 0 ; V_100 < V_91 ; V_100 ++ ) {
F_94 ( V_81 -> V_78 ) ;
V_81 = ( void * ) V_81 + V_84 ;
}
F_2 ( & V_38 -> V_43 -> V_82 ) ;
}
static int F_95 ( struct V_35 * V_36 , struct V_34 * V_34 ,
struct V_89 * V_90 ,
struct V_155 * V_156 , int V_91 )
{
T_2 V_52 ;
int V_100 , V_168 ;
int V_48 = V_90 -> V_105 ;
struct V_80 * V_81 ;
struct V_37 * V_38 = F_29 ( V_36 ) ;
struct V_42 * V_49 = F_39 ( V_38 , V_48 ) ;
struct V_155 V_169 = V_170 ;
int V_86 = 1 ;
T_2 V_171 = V_49 -> V_55 ;
T_1 V_84 = sizeof( struct V_80 ) ;
if ( F_54 ( V_90 ) ) {
for ( V_100 = 1 ; V_100 < V_90 -> V_104 ; V_100 ++ ) {
V_49 = F_39 ( V_38 , V_48 + V_100 ) ;
V_171 += V_49 -> V_55 ;
}
V_86 = V_90 -> V_104 ;
V_84 += ( V_86 - 1 ) * sizeof( V_81 -> V_85 ) ;
}
if ( ! V_171 )
return 0 ;
V_81 = V_38 -> V_43 -> V_82 = calloc ( V_91 , V_84 ) ;
if ( ! V_38 -> V_43 -> V_82 )
return - 1 ;
V_52 = F_60 ( V_34 , V_36 -> V_52 ) ;
for ( V_100 = 0 ; V_100 < V_91 ; V_100 ++ ) {
T_2 V_17 ;
double V_172 = 0.0 ;
V_81 -> V_86 = V_86 ;
for ( V_168 = 0 ; V_168 < V_86 ; V_168 ++ ) {
V_49 = F_39 ( V_38 , V_48 + V_168 ) ;
V_81 -> V_85 [ V_168 ] . V_83 = 100.0 * V_49 -> V_12 [ V_100 ] / V_49 -> V_55 ;
if ( V_81 -> V_85 [ V_168 ] . V_83 > V_172 )
V_172 = V_81 -> V_85 [ V_168 ] . V_83 ;
}
if ( V_172 <= 0.5 )
goto V_103;
V_17 = V_52 + V_100 ;
V_81 -> V_78 = F_96 ( V_34 -> V_119 , V_17 , NULL , false ) ;
F_83 ( & V_169 , V_81 ) ;
V_103:
V_81 = ( void * ) V_81 + V_84 ;
}
F_89 ( V_156 , & V_169 ) ;
return 0 ;
}
static void F_97 ( struct V_155 * V_156 , const char * V_120 )
{
struct V_80 * V_81 ;
struct V_158 * V_76 ;
printf ( L_48 , V_120 ) ;
printf ( L_49 ) ;
if ( F_98 ( V_156 ) ) {
printf ( L_50 , V_173 ) ;
return;
}
V_76 = F_90 ( V_156 ) ;
while ( V_76 ) {
double V_83 , V_172 = 0.0 ;
const char * V_102 ;
char * V_78 ;
int V_100 ;
V_81 = F_84 ( V_76 , struct V_80 , V_76 ) ;
for ( V_100 = 0 ; V_100 < V_81 -> V_86 ; V_100 ++ ) {
V_83 = V_81 -> V_85 [ V_100 ] . V_161 ;
V_102 = F_56 ( V_83 ) ;
F_57 ( stdout , V_102 , L_17 , V_83 ) ;
if ( V_83 > V_172 )
V_172 = V_83 ;
}
V_78 = V_81 -> V_78 ;
V_102 = F_56 ( V_172 ) ;
F_57 ( stdout , V_102 , L_51 , V_78 ) ;
V_76 = F_91 ( V_76 ) ;
}
}
static void F_99 ( struct V_35 * V_36 , struct V_89 * V_90 )
{
struct V_37 * V_38 = F_29 ( V_36 ) ;
struct V_42 * V_49 = F_39 ( V_38 , V_90 -> V_105 ) ;
T_2 V_91 = F_32 ( V_36 ) , V_17 ;
for ( V_17 = 0 ; V_17 < V_91 ; ++ V_17 )
if ( V_49 -> V_12 [ V_17 ] != 0 )
printf ( L_52 V_14 L_53 V_56 L_10 , V_174 / 2 ,
V_36 -> V_52 + V_17 , V_49 -> V_12 [ V_17 ] ) ;
printf ( L_54 V_56 L_10 , V_174 / 2 , L_55 , V_49 -> V_55 ) ;
}
int F_100 ( struct V_35 * V_36 , struct V_34 * V_34 ,
struct V_89 * V_90 , bool V_175 ,
int V_92 , int V_93 , int V_176 )
{
struct V_119 * V_119 = V_34 -> V_119 ;
char * V_120 ;
const char * V_177 ;
const char * V_178 = F_101 ( V_90 ) ;
struct V_37 * V_38 = F_29 ( V_36 ) ;
struct V_65 * V_77 , * V_94 = NULL ;
T_2 V_52 = F_60 ( V_34 , V_36 -> V_52 ) ;
int V_27 = 2 , V_179 = 0 ;
int V_180 = 0 ;
T_2 V_91 ;
int V_109 = 8 ;
int V_181 , V_182 , V_183 ;
V_120 = F_8 ( V_119 -> V_133 ) ;
if ( ! V_120 )
return - V_57 ;
if ( V_175 )
V_177 = V_120 ;
else
V_177 = F_102 ( V_120 ) ;
V_91 = F_32 ( V_36 ) ;
V_181 = strlen ( V_177 ) ;
V_182 = strlen ( V_178 ) ;
if ( F_54 ( V_90 ) )
V_109 *= V_90 -> V_104 ;
printf ( L_56 ,
V_109 , V_109 , L_57 , V_177 , V_178 ) ;
V_183 = V_109 + V_181 + V_182 ;
printf ( L_58 ,
V_183 , V_183 , V_184 ) ;
if ( V_185 )
F_99 ( V_36 , V_90 ) ;
F_103 (pos, &notes->src->source, node) {
if ( V_176 && V_94 == NULL ) {
V_94 = V_77 ;
V_179 = 0 ;
}
switch ( F_53 ( V_77 , V_36 , V_52 , V_90 , V_91 ,
V_92 , V_27 , V_93 ,
V_94 ) ) {
case 0 :
++ V_27 ;
if ( V_176 ) {
V_27 += V_179 ;
V_94 = NULL ;
V_179 = 0 ;
}
break;
case 1 :
++ V_180 ;
break;
case - 1 :
default:
if ( ! V_176 )
break;
if ( V_179 == V_176 )
V_94 = F_104 ( V_94 -> V_76 . V_103 , F_105 ( * V_94 ) , V_76 ) ;
else
++ V_179 ;
break;
}
}
free ( V_120 ) ;
return V_180 ;
}
void F_106 ( struct V_35 * V_36 , int V_48 )
{
struct V_37 * V_38 = F_29 ( V_36 ) ;
struct V_42 * V_49 = F_39 ( V_38 , V_48 ) ;
memset ( V_49 , 0 , V_38 -> V_43 -> V_40 ) ;
}
void F_107 ( struct V_35 * V_36 , int V_48 )
{
struct V_37 * V_38 = F_29 ( V_36 ) ;
struct V_42 * V_49 = F_39 ( V_38 , V_48 ) ;
int V_91 = F_32 ( V_36 ) , V_17 ;
V_49 -> V_55 = 0 ;
for ( V_17 = 0 ; V_17 < V_91 ; ++ V_17 ) {
V_49 -> V_12 [ V_17 ] = V_49 -> V_12 [ V_17 ] * 7 / 8 ;
V_49 -> V_55 += V_49 -> V_12 [ V_17 ] ;
}
}
void F_108 ( struct V_74 * V_75 )
{
struct V_65 * V_77 , * V_186 ;
F_109 (pos, n, head, node) {
F_110 ( & V_77 -> V_76 ) ;
F_46 ( V_77 ) ;
}
}
static T_1 F_111 ( struct V_65 * V_66 , T_4 * V_187 )
{
T_1 V_27 ;
if ( V_66 -> V_17 == - 1 )
return fprintf ( V_187 , L_21 , V_66 -> line ) ;
V_27 = fprintf ( V_187 , L_11 V_14 L_15 , V_66 -> V_17 , V_66 -> V_5 ) ;
if ( V_66 -> V_2 . V_4 [ 0 ] != '\0' ) {
V_27 += fprintf ( V_187 , L_59 , 6 - ( int ) V_27 , L_23 ,
V_66 -> V_2 . V_4 ) ;
}
return V_27 + fprintf ( V_187 , L_10 ) ;
}
T_1 F_112 ( struct V_74 * V_75 , T_4 * V_187 )
{
struct V_65 * V_77 ;
T_1 V_27 = 0 ;
F_103 (pos, head, node)
V_27 += F_111 ( V_77 , V_187 ) ;
return V_27 ;
}
int F_113 ( struct V_35 * V_36 , struct V_34 * V_34 ,
struct V_89 * V_90 , bool V_188 ,
bool V_175 , int V_92 , int V_93 )
{
struct V_119 * V_119 = V_34 -> V_119 ;
struct V_155 V_80 = V_170 ;
T_2 V_91 ;
if ( F_62 ( V_36 , V_34 , 0 ) < 0 )
return - 1 ;
V_91 = F_32 ( V_36 ) ;
if ( V_188 ) {
F_95 ( V_36 , V_34 , V_90 , & V_80 , V_91 ) ;
F_97 ( & V_80 , V_119 -> V_133 ) ;
}
F_100 ( V_36 , V_34 , V_90 , V_175 ,
V_92 , V_93 , 0 ) ;
if ( V_188 )
F_93 ( V_36 , V_91 ) ;
F_108 ( & F_29 ( V_36 ) -> V_43 -> V_3 ) ;
return 0 ;
}
int F_114 ( struct V_61 * V_62 , T_1 V_70 )
{
return F_62 ( V_62 -> V_64 . V_36 , V_62 -> V_64 . V_34 , V_70 ) ;
}
bool F_115 ( void )
{
return V_189 == 1 && V_190 ;
}
