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
static int F_40 ( struct V_35 * V_36 , struct V_34 * V_34 ,
int V_48 , T_2 V_12 )
{
struct V_37 * V_38 ;
if ( V_36 == NULL )
return 0 ;
V_38 = F_29 ( V_36 ) ;
if ( V_38 -> V_43 == NULL ) {
if ( F_31 ( V_36 ) < 0 )
return - V_57 ;
}
return F_37 ( V_36 , V_34 , V_38 , V_48 , V_12 ) ;
}
int F_41 ( struct V_58 * V_59 , int V_48 )
{
return F_40 ( V_59 -> V_36 , V_59 -> V_34 , V_48 , V_59 -> V_60 ) ;
}
int F_42 ( struct V_61 * V_62 , int V_48 , T_2 V_63 )
{
return F_40 ( V_62 -> V_64 . V_36 , V_62 -> V_64 . V_34 , V_48 , V_63 ) ;
}
static void F_43 ( struct V_65 * V_66 )
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
static struct V_65 * F_44 ( T_3 V_17 , char * line ,
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
F_43 ( V_66 ) ;
}
}
return V_66 ;
V_73:
F_2 ( & V_66 -> line ) ;
V_72:
free ( V_66 ) ;
return NULL ;
}
void F_45 ( struct V_65 * V_66 )
{
F_2 ( & V_66 -> line ) ;
F_2 ( & V_66 -> V_5 ) ;
if ( V_66 -> V_7 && V_66 -> V_7 -> V_2 -> free )
V_66 -> V_7 -> V_2 -> free ( & V_66 -> V_2 ) ;
else
F_1 ( & V_66 -> V_2 ) ;
free ( V_66 ) ;
}
int F_46 ( struct V_65 * V_66 , char * V_8 , T_1 V_9 , bool V_4 )
{
if ( V_4 || ! V_66 -> V_7 )
return F_4 ( V_8 , V_9 , L_1 , V_66 -> V_5 , V_66 -> V_2 . V_4 ) ;
return F_5 ( V_66 -> V_7 , V_8 , V_9 , & V_66 -> V_2 ) ;
}
static void F_47 ( struct V_74 * V_75 , struct V_65 * line )
{
F_48 ( & line -> V_76 , V_75 ) ;
}
struct V_65 * F_49 ( struct V_74 * V_75 , struct V_65 * V_77 )
{
F_50 (pos, head, node)
if ( V_77 -> V_17 >= 0 )
return V_77 ;
return NULL ;
}
double F_51 ( struct V_37 * V_38 , int V_48 , T_3 V_17 ,
T_3 V_53 , const char * * V_78 )
{
struct V_79 * V_80 = V_38 -> V_43 -> V_81 ;
double V_82 = 0.0 ;
if ( V_80 ) {
T_1 V_83 = sizeof( * V_80 ) +
sizeof( V_80 -> V_84 ) * ( V_80 -> V_85 - 1 ) ;
while ( V_17 < V_53 ) {
V_80 = ( void * ) V_38 -> V_43 -> V_81 +
( V_83 * V_17 ) ;
if ( * V_78 == NULL )
* V_78 = V_80 -> V_78 ;
V_82 += V_80 -> V_84 [ V_48 ] . V_82 ;
V_17 ++ ;
}
} else {
struct V_42 * V_49 = F_39 ( V_38 , V_48 ) ;
unsigned int V_86 = 0 ;
while ( V_17 < V_53 )
V_86 += V_49 -> V_12 [ V_17 ++ ] ;
if ( V_49 -> V_55 )
V_82 = 100.0 * V_86 / V_49 -> V_55 ;
}
return V_82 ;
}
static int F_52 ( struct V_65 * V_66 , struct V_35 * V_36 , T_2 V_52 ,
struct V_87 * V_88 , T_2 V_89 , int V_90 , int V_27 ,
int V_91 , struct V_65 * V_92 )
{
static const char * V_93 ;
static const char * V_94 ;
if ( V_66 -> V_17 != - 1 ) {
const char * V_78 = NULL ;
double V_82 , V_95 = 0.0 ;
double * V_96 = & V_82 ;
int V_97 , V_98 = 1 ;
const char * V_99 ;
struct V_37 * V_38 = F_29 ( V_36 ) ;
T_3 V_17 = V_66 -> V_17 ;
const T_2 V_12 = V_52 + V_17 ;
struct V_65 * V_100 ;
V_100 = F_49 ( & V_38 -> V_43 -> V_3 , V_66 ) ;
if ( F_53 ( V_88 ) ) {
V_98 = V_88 -> V_101 ;
V_96 = calloc ( V_98 , sizeof( double ) ) ;
if ( V_96 == NULL )
return - 1 ;
}
for ( V_97 = 0 ; V_97 < V_98 ; V_97 ++ ) {
V_82 = F_51 ( V_38 ,
V_38 -> V_43 -> V_81 ? V_97 : V_88 -> V_102 + V_97 ,
V_17 ,
V_100 ? V_100 -> V_17 : ( T_3 ) V_89 ,
& V_78 ) ;
V_96 [ V_97 ] = V_82 ;
if ( V_82 > V_95 )
V_95 = V_82 ;
}
if ( V_95 < V_90 )
return - 1 ;
if ( V_91 && V_27 >= V_91 )
return 1 ;
if ( V_92 != NULL ) {
F_54 (queue, &notes->src->source, node) {
if ( V_92 == V_66 )
break;
F_52 ( V_92 , V_36 , V_52 , V_88 , V_89 ,
0 , 0 , 1 , NULL ) ;
}
}
V_99 = F_55 ( V_95 ) ;
if ( V_78 ) {
if ( ! V_93 || strcmp ( V_93 , V_78 )
|| V_99 != V_94 ) {
F_56 ( stdout , V_99 , L_15 , V_78 ) ;
V_93 = V_78 ;
V_94 = V_99 ;
}
}
for ( V_97 = 0 ; V_97 < V_98 ; V_97 ++ ) {
V_82 = V_96 [ V_97 ] ;
V_99 = F_55 ( V_82 ) ;
F_56 ( stdout , V_99 , L_16 , V_82 ) ;
}
printf ( L_17 ) ;
F_56 ( stdout , V_103 , L_18 V_14 L_19 , V_12 ) ;
F_56 ( stdout , V_104 , L_20 , V_66 -> line ) ;
if ( V_96 != & V_82 )
free ( V_96 ) ;
} else if ( V_91 && V_27 >= V_91 )
return 1 ;
else {
int V_105 = 8 ;
if ( V_92 )
return - 1 ;
if ( F_53 ( V_88 ) )
V_105 *= V_88 -> V_101 ;
if ( ! * V_66 -> line )
printf ( L_21 , V_105 , L_22 ) ;
else
printf ( L_23 , V_105 , L_22 , V_66 -> line ) ;
}
return 0 ;
}
static int F_57 ( struct V_35 * V_36 , struct V_34 * V_34 ,
T_4 * V_106 , T_1 V_70 ,
int * V_71 )
{
struct V_37 * V_38 = F_29 ( V_36 ) ;
struct V_65 * V_66 ;
char * line = NULL , * V_107 , * V_68 , * V_108 , * V_109 ;
T_1 V_110 ;
T_3 V_111 , V_17 = - 1 ;
T_5 V_112 [ 2 ] ;
if ( F_58 ( & line , & V_110 , V_106 ) < 0 )
return - 1 ;
if ( ! line )
return - 1 ;
while ( V_110 != 0 && isspace ( line [ V_110 - 1 ] ) )
line [ -- V_110 ] = '\0' ;
V_109 = strchr ( line , '\n' ) ;
if ( V_109 )
* V_109 = 0 ;
V_111 = - 1 ;
V_107 = line ;
if ( regexec ( & V_113 , line , 2 , V_112 , 0 ) == 0 ) {
* V_71 = atoi ( line + V_112 [ 1 ] . V_114 ) ;
return 0 ;
}
V_68 = line ;
while ( * V_68 ) {
if ( * V_68 != ' ' )
break;
V_68 ++ ;
}
if ( * V_68 ) {
V_111 = F_7 ( V_68 , & V_108 , 16 ) ;
if ( * V_108 != ':' || V_68 == V_108 || V_108 [ 1 ] == '\0' )
V_111 = - 1 ;
}
if ( V_111 != - 1 ) {
T_2 V_52 = F_59 ( V_34 , V_36 -> V_52 ) ,
V_53 = F_59 ( V_34 , V_36 -> V_53 ) ;
V_17 = V_111 - V_52 ;
if ( ( T_2 ) V_111 < V_52 || ( T_2 ) V_111 >= V_53 )
V_17 = - 1 ;
else
V_107 = V_108 + 1 ;
}
V_66 = F_44 ( V_17 , V_107 , V_70 , * V_71 ) ;
free ( line ) ;
( * V_71 ) ++ ;
if ( V_66 == NULL )
return - 1 ;
if ( V_66 -> V_2 . V_6 . V_17 == V_18 )
V_66 -> V_2 . V_6 . V_17 = V_66 -> V_2 . V_6 . V_12 -
F_59 ( V_34 , V_36 -> V_52 ) ;
if ( V_66 -> V_7 && F_10 ( V_66 -> V_7 ) && ! V_66 -> V_2 . V_6 . V_5 ) {
struct V_58 V_6 = {
. V_34 = V_34 ,
. V_12 = V_66 -> V_2 . V_6 . V_12 ,
} ;
if ( ! F_60 ( & V_6 , NULL ) &&
V_6 . V_36 -> V_52 == V_6 . V_60 )
V_66 -> V_2 . V_6 . V_5 = F_8 ( V_6 . V_36 -> V_5 ) ;
}
F_47 ( & V_38 -> V_43 -> V_3 , V_66 ) ;
return 0 ;
}
int F_61 ( struct V_35 * V_36 , struct V_34 * V_34 , T_1 V_70 )
{
struct V_115 * V_115 = V_34 -> V_115 ;
char * V_116 = F_62 ( V_115 , NULL , 0 ) ;
bool V_117 = true ;
char V_118 [ V_119 * 2 ] ;
T_4 * V_106 ;
int V_120 = 0 ;
char V_121 [ V_119 ] ;
struct V_122 V_123 ;
bool V_124 = false ;
int V_125 = 0 ;
if ( V_116 )
F_63 ( V_121 , V_116 ) ;
if ( V_116 == NULL ) {
if ( V_115 -> V_126 ) {
F_64 ( L_24 ,
V_36 -> V_5 ) ;
return - V_57 ;
}
goto V_127;
} else if ( F_65 ( V_115 ) ) {
goto V_127;
} else if ( F_66 ( V_121 , V_118 , sizeof( V_118 ) ) < 0 ||
strstr ( V_118 , L_25 ) ||
F_67 ( V_121 , V_128 ) ) {
free ( V_116 ) ;
V_127:
V_116 = ( char * ) V_115 -> V_129 ;
F_63 ( V_121 , V_116 ) ;
V_117 = false ;
}
if ( V_115 -> V_130 == V_131 &&
! F_65 ( V_115 ) ) {
char V_8 [ V_132 * 2 + 16 ] = L_26 ;
char * V_133 = NULL ;
if ( V_115 -> V_134 )
goto V_135;
if ( V_115 -> V_126 ) {
F_68 ( V_115 -> V_136 ,
sizeof( V_115 -> V_136 ) , V_8 + 15 ) ;
V_133 = V_8 ;
}
V_120 = - V_137 ;
V_115 -> V_134 = 1 ;
F_64 ( L_27
L_28
L_29
L_30
L_31
L_32 ,
V_36 -> V_5 , V_133 ? : L_33 ) ;
goto V_135;
}
F_69 ( L_34 V_14 L_35 V_14 L_10 , V_50 ,
V_116 , V_36 -> V_5 , V_34 -> V_51 ( V_34 , V_36 -> V_52 ) ,
V_34 -> V_51 ( V_34 , V_36 -> V_53 ) ) ;
F_69 ( L_36 ,
V_115 , V_115 -> V_129 , V_36 , V_36 -> V_5 ) ;
if ( F_65 ( V_115 ) ) {
V_123 . V_138 = V_121 ;
V_123 . V_12 = F_59 ( V_34 , V_36 -> V_52 ) ;
V_123 . V_139 = V_36 -> V_52 ;
V_123 . V_89 = V_36 -> V_53 - V_36 -> V_52 ;
if ( ! F_70 ( & V_123 ) ) {
V_124 = true ;
F_71 ( V_121 , V_123 . V_140 ,
sizeof( V_121 ) ) ;
if ( V_117 ) {
free ( V_116 ) ;
V_117 = false ;
}
V_116 = V_121 ;
}
} else if ( F_72 ( V_115 ) ) {
char V_68 [ V_119 ] ;
struct V_141 V_142 ;
int V_143 ;
bool V_144 ;
if ( F_73 ( & V_142 , V_121 ) )
goto V_135;
snprintf ( V_68 , V_119 , L_37 ) ;
V_143 = F_74 ( V_68 ) ;
if ( V_143 < 0 ) {
free ( V_142 . V_145 ) ;
goto V_135;
}
V_144 = F_75 ( V_142 . V_145 , V_121 , V_143 ) ;
free ( V_142 . V_145 ) ;
F_76 ( V_143 ) ;
if ( ! V_144 )
goto V_135;
strcpy ( V_121 , V_68 ) ;
}
snprintf ( V_118 , sizeof( V_118 ) ,
L_38 V_14
L_39 V_14
L_40 ,
V_146 ? V_146 : L_41 ,
V_147 ? L_42 : L_33 ,
V_147 ? V_147 : L_33 ,
F_59 ( V_34 , V_36 -> V_52 ) ,
F_59 ( V_34 , V_36 -> V_53 ) ,
V_44 . V_148 ? L_33 : L_43 ,
V_44 . V_149 ? L_44 : L_33 ,
V_121 , V_116 ) ;
F_69 ( L_45 , V_118 ) ;
V_106 = F_77 ( V_118 , L_46 ) ;
if ( ! V_106 )
goto V_150;
while ( ! feof ( V_106 ) )
if ( F_57 ( V_36 , V_34 , V_106 , V_70 ,
& V_125 ) < 0 )
break;
if ( F_65 ( V_115 ) )
F_78 ( V_36 ) ;
F_79 ( V_106 ) ;
V_150:
if ( F_72 ( V_115 ) )
F_80 ( V_121 ) ;
V_135:
if ( V_124 )
F_81 ( & V_123 ) ;
if ( V_117 )
free ( V_116 ) ;
return V_120 ;
}
static void F_82 ( struct V_151 * V_152 , struct V_79 * V_80 )
{
struct V_79 * V_153 ;
struct V_154 * * V_84 = & V_152 -> V_154 ;
struct V_154 * V_155 = NULL ;
int V_97 , V_144 ;
while ( * V_84 != NULL ) {
V_155 = * V_84 ;
V_153 = F_83 ( V_155 , struct V_79 , V_76 ) ;
V_144 = strcmp ( V_153 -> V_78 , V_80 -> V_78 ) ;
if ( V_144 == 0 ) {
for ( V_97 = 0 ; V_97 < V_80 -> V_85 ; V_97 ++ )
V_153 -> V_84 [ V_97 ] . V_156 += V_80 -> V_84 [ V_97 ] . V_82 ;
return;
}
if ( V_144 < 0 )
V_84 = & ( * V_84 ) -> V_157 ;
else
V_84 = & ( * V_84 ) -> V_158 ;
}
for ( V_97 = 0 ; V_97 < V_80 -> V_85 ; V_97 ++ )
V_80 -> V_84 [ V_97 ] . V_156 = V_80 -> V_84 [ V_97 ] . V_82 ;
F_84 ( & V_80 -> V_76 , V_155 , V_84 ) ;
F_85 ( & V_80 -> V_76 , V_152 ) ;
}
static int F_86 ( struct V_79 * V_159 , struct V_79 * V_160 )
{
int V_97 ;
for ( V_97 = 0 ; V_97 < V_159 -> V_85 ; V_97 ++ ) {
if ( V_159 -> V_84 [ V_97 ] . V_156 == V_160 -> V_84 [ V_97 ] . V_156 )
continue;
return V_159 -> V_84 [ V_97 ] . V_156 > V_160 -> V_84 [ V_97 ] . V_156 ;
}
return 0 ;
}
static void F_87 ( struct V_151 * V_152 , struct V_79 * V_80 )
{
struct V_79 * V_153 ;
struct V_154 * * V_84 = & V_152 -> V_154 ;
struct V_154 * V_155 = NULL ;
while ( * V_84 != NULL ) {
V_155 = * V_84 ;
V_153 = F_83 ( V_155 , struct V_79 , V_76 ) ;
if ( F_86 ( V_80 , V_153 ) )
V_84 = & ( * V_84 ) -> V_157 ;
else
V_84 = & ( * V_84 ) -> V_158 ;
}
F_84 ( & V_80 -> V_76 , V_155 , V_84 ) ;
F_85 ( & V_80 -> V_76 , V_152 ) ;
}
static void F_88 ( struct V_151 * V_161 , struct V_151 * V_162 )
{
struct V_79 * V_80 ;
struct V_154 * V_76 ;
V_76 = F_89 ( V_162 ) ;
while ( V_76 ) {
struct V_154 * V_100 ;
V_80 = F_83 ( V_76 , struct V_79 , V_76 ) ;
V_100 = F_90 ( V_76 ) ;
F_91 ( V_76 , V_162 ) ;
F_87 ( V_161 , V_80 ) ;
V_76 = V_100 ;
}
}
static void F_92 ( struct V_35 * V_36 , int V_89 )
{
struct V_37 * V_38 = F_29 ( V_36 ) ;
struct V_79 * V_80 = V_38 -> V_43 -> V_81 ;
T_1 V_83 ;
int V_97 ;
V_83 = sizeof( * V_80 ) +
( sizeof( V_80 -> V_84 ) * ( V_80 -> V_85 - 1 ) ) ;
for ( V_97 = 0 ; V_97 < V_89 ; V_97 ++ ) {
F_93 ( V_80 -> V_78 ) ;
V_80 = ( void * ) V_80 + V_83 ;
}
F_2 ( & V_38 -> V_43 -> V_81 ) ;
}
static int F_94 ( struct V_35 * V_36 , struct V_34 * V_34 ,
struct V_87 * V_88 ,
struct V_151 * V_152 , int V_89 )
{
T_2 V_52 ;
int V_97 , V_163 ;
int V_48 = V_88 -> V_102 ;
struct V_79 * V_80 ;
struct V_37 * V_38 = F_29 ( V_36 ) ;
struct V_42 * V_49 = F_39 ( V_38 , V_48 ) ;
struct V_151 V_164 = V_165 ;
int V_85 = 1 ;
T_2 V_166 = V_49 -> V_55 ;
T_1 V_83 = sizeof( struct V_79 ) ;
if ( F_53 ( V_88 ) ) {
for ( V_97 = 1 ; V_97 < V_88 -> V_101 ; V_97 ++ ) {
V_49 = F_39 ( V_38 , V_48 + V_97 ) ;
V_166 += V_49 -> V_55 ;
}
V_85 = V_88 -> V_101 ;
V_83 += ( V_85 - 1 ) * sizeof( V_80 -> V_84 ) ;
}
if ( ! V_166 )
return 0 ;
V_80 = V_38 -> V_43 -> V_81 = calloc ( V_89 , V_83 ) ;
if ( ! V_38 -> V_43 -> V_81 )
return - 1 ;
V_52 = F_59 ( V_34 , V_36 -> V_52 ) ;
for ( V_97 = 0 ; V_97 < V_89 ; V_97 ++ ) {
T_2 V_17 ;
double V_167 = 0.0 ;
V_80 -> V_85 = V_85 ;
for ( V_163 = 0 ; V_163 < V_85 ; V_163 ++ ) {
V_49 = F_39 ( V_38 , V_48 + V_163 ) ;
V_80 -> V_84 [ V_163 ] . V_82 = 100.0 * V_49 -> V_12 [ V_97 ] / V_49 -> V_55 ;
if ( V_80 -> V_84 [ V_163 ] . V_82 > V_167 )
V_167 = V_80 -> V_84 [ V_163 ] . V_82 ;
}
if ( V_167 <= 0.5 )
goto V_100;
V_17 = V_52 + V_97 ;
V_80 -> V_78 = F_95 ( V_34 -> V_115 , V_17 , NULL , false ) ;
F_82 ( & V_164 , V_80 ) ;
V_100:
V_80 = ( void * ) V_80 + V_83 ;
}
F_88 ( V_152 , & V_164 ) ;
return 0 ;
}
static void F_96 ( struct V_151 * V_152 , const char * V_116 )
{
struct V_79 * V_80 ;
struct V_154 * V_76 ;
printf ( L_47 , V_116 ) ;
printf ( L_48 ) ;
if ( F_97 ( V_152 ) ) {
printf ( L_49 , V_168 ) ;
return;
}
V_76 = F_89 ( V_152 ) ;
while ( V_76 ) {
double V_82 , V_167 = 0.0 ;
const char * V_99 ;
char * V_78 ;
int V_97 ;
V_80 = F_83 ( V_76 , struct V_79 , V_76 ) ;
for ( V_97 = 0 ; V_97 < V_80 -> V_85 ; V_97 ++ ) {
V_82 = V_80 -> V_84 [ V_97 ] . V_156 ;
V_99 = F_55 ( V_82 ) ;
F_56 ( stdout , V_99 , L_16 , V_82 ) ;
if ( V_82 > V_167 )
V_167 = V_82 ;
}
V_78 = V_80 -> V_78 ;
V_99 = F_55 ( V_167 ) ;
F_56 ( stdout , V_99 , L_50 , V_78 ) ;
V_76 = F_90 ( V_76 ) ;
}
}
static void F_98 ( struct V_35 * V_36 , struct V_87 * V_88 )
{
struct V_37 * V_38 = F_29 ( V_36 ) ;
struct V_42 * V_49 = F_39 ( V_38 , V_88 -> V_102 ) ;
T_2 V_89 = F_32 ( V_36 ) , V_17 ;
for ( V_17 = 0 ; V_17 < V_89 ; ++ V_17 )
if ( V_49 -> V_12 [ V_17 ] != 0 )
printf ( L_51 V_14 L_52 V_56 L_10 , V_169 / 2 ,
V_36 -> V_52 + V_17 , V_49 -> V_12 [ V_17 ] ) ;
printf ( L_53 V_56 L_10 , V_169 / 2 , L_54 , V_49 -> V_55 ) ;
}
int F_99 ( struct V_35 * V_36 , struct V_34 * V_34 ,
struct V_87 * V_88 , bool V_170 ,
int V_90 , int V_91 , int V_171 )
{
struct V_115 * V_115 = V_34 -> V_115 ;
char * V_116 ;
const char * V_172 ;
const char * V_173 = F_100 ( V_88 ) ;
struct V_37 * V_38 = F_29 ( V_36 ) ;
struct V_65 * V_77 , * V_92 = NULL ;
T_2 V_52 = F_59 ( V_34 , V_36 -> V_52 ) ;
int V_27 = 2 , V_174 = 0 ;
int V_175 = 0 ;
T_2 V_89 ;
int V_105 = 8 ;
int V_176 , V_177 , V_178 ;
V_116 = F_8 ( V_115 -> V_129 ) ;
if ( ! V_116 )
return - V_57 ;
if ( V_170 )
V_172 = V_116 ;
else
V_172 = F_101 ( V_116 ) ;
V_89 = F_32 ( V_36 ) ;
V_176 = strlen ( V_172 ) ;
V_177 = strlen ( V_173 ) ;
if ( F_53 ( V_88 ) )
V_105 *= V_88 -> V_101 ;
printf ( L_55 ,
V_105 , V_105 , L_56 , V_172 , V_173 ) ;
V_178 = V_105 + V_176 + V_177 ;
printf ( L_57 ,
V_178 , V_178 , V_179 ) ;
if ( V_180 )
F_98 ( V_36 , V_88 ) ;
F_102 (pos, &notes->src->source, node) {
if ( V_171 && V_92 == NULL ) {
V_92 = V_77 ;
V_174 = 0 ;
}
switch ( F_52 ( V_77 , V_36 , V_52 , V_88 , V_89 ,
V_90 , V_27 , V_91 ,
V_92 ) ) {
case 0 :
++ V_27 ;
if ( V_171 ) {
V_27 += V_174 ;
V_92 = NULL ;
V_174 = 0 ;
}
break;
case 1 :
++ V_175 ;
break;
case - 1 :
default:
if ( ! V_171 )
break;
if ( V_174 == V_171 )
V_92 = F_103 ( V_92 -> V_76 . V_100 , F_104 ( * V_92 ) , V_76 ) ;
else
++ V_174 ;
break;
}
}
free ( V_116 ) ;
return V_175 ;
}
void F_105 ( struct V_35 * V_36 , int V_48 )
{
struct V_37 * V_38 = F_29 ( V_36 ) ;
struct V_42 * V_49 = F_39 ( V_38 , V_48 ) ;
memset ( V_49 , 0 , V_38 -> V_43 -> V_40 ) ;
}
void F_106 ( struct V_35 * V_36 , int V_48 )
{
struct V_37 * V_38 = F_29 ( V_36 ) ;
struct V_42 * V_49 = F_39 ( V_38 , V_48 ) ;
int V_89 = F_32 ( V_36 ) , V_17 ;
V_49 -> V_55 = 0 ;
for ( V_17 = 0 ; V_17 < V_89 ; ++ V_17 ) {
V_49 -> V_12 [ V_17 ] = V_49 -> V_12 [ V_17 ] * 7 / 8 ;
V_49 -> V_55 += V_49 -> V_12 [ V_17 ] ;
}
}
void F_107 ( struct V_74 * V_75 )
{
struct V_65 * V_77 , * V_181 ;
F_108 (pos, n, head, node) {
F_109 ( & V_77 -> V_76 ) ;
F_45 ( V_77 ) ;
}
}
static T_1 F_110 ( struct V_65 * V_66 , T_4 * V_182 )
{
T_1 V_27 ;
if ( V_66 -> V_17 == - 1 )
return fprintf ( V_182 , L_20 , V_66 -> line ) ;
V_27 = fprintf ( V_182 , L_11 V_14 L_15 , V_66 -> V_17 , V_66 -> V_5 ) ;
if ( V_66 -> V_2 . V_4 [ 0 ] != '\0' ) {
V_27 += fprintf ( V_182 , L_58 , 6 - ( int ) V_27 , L_22 ,
V_66 -> V_2 . V_4 ) ;
}
return V_27 + fprintf ( V_182 , L_10 ) ;
}
T_1 F_111 ( struct V_74 * V_75 , T_4 * V_182 )
{
struct V_65 * V_77 ;
T_1 V_27 = 0 ;
F_102 (pos, head, node)
V_27 += F_110 ( V_77 , V_182 ) ;
return V_27 ;
}
int F_112 ( struct V_35 * V_36 , struct V_34 * V_34 ,
struct V_87 * V_88 , bool V_183 ,
bool V_170 , int V_90 , int V_91 )
{
struct V_115 * V_115 = V_34 -> V_115 ;
struct V_151 V_79 = V_165 ;
T_2 V_89 ;
if ( F_61 ( V_36 , V_34 , 0 ) < 0 )
return - 1 ;
V_89 = F_32 ( V_36 ) ;
if ( V_183 ) {
F_94 ( V_36 , V_34 , V_88 , & V_79 , V_89 ) ;
F_96 ( & V_79 , V_115 -> V_129 ) ;
}
F_99 ( V_36 , V_34 , V_88 , V_170 ,
V_90 , V_91 , 0 ) ;
if ( V_183 )
F_92 ( V_36 , V_89 ) ;
F_107 ( & F_29 ( V_36 ) -> V_43 -> V_3 ) ;
return 0 ;
}
int F_113 ( struct V_61 * V_62 , T_1 V_70 )
{
return F_61 ( V_62 -> V_64 . V_36 , V_62 -> V_64 . V_34 , V_70 ) ;
}
bool F_114 ( void )
{
return V_184 == 1 && V_185 ;
}
