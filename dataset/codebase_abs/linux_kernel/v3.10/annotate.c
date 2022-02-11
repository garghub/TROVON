static void F_1 ( struct V_1 * V_2 )
{
free ( V_2 -> V_3 . V_4 ) ;
free ( V_2 -> V_3 . V_5 ) ;
free ( V_2 -> V_6 . V_4 ) ;
free ( V_2 -> V_6 . V_5 ) ;
}
static int F_2 ( struct V_7 * V_7 , char * V_8 , T_1 V_9 ,
struct V_1 * V_2 )
{
return F_3 ( V_8 , V_9 , L_1 , V_7 -> V_5 , V_2 -> V_4 ) ;
}
int F_4 ( struct V_7 * V_7 , char * V_8 , T_1 V_9 ,
struct V_1 * V_2 )
{
if ( V_7 -> V_2 -> F_3 )
return V_7 -> V_2 -> F_3 ( V_7 , V_8 , V_9 , V_2 ) ;
return F_2 ( V_7 , V_8 , V_9 , V_2 ) ;
}
static int F_5 ( struct V_1 * V_2 )
{
char * V_10 , * V_11 , * V_5 ;
V_2 -> V_6 . V_12 = F_6 ( V_2 -> V_4 , & V_10 , 16 ) ;
V_5 = strchr ( V_10 , '<' ) ;
if ( V_5 == NULL )
goto V_13;
V_5 ++ ;
V_11 = strchr ( V_5 , '>' ) ;
if ( V_11 == NULL )
return - 1 ;
* V_11 = '\0' ;
V_2 -> V_6 . V_5 = F_7 ( V_5 ) ;
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
V_2 -> V_6 . V_12 = F_6 ( V_11 + 1 , NULL , 16 ) ;
return 0 ;
}
static int F_8 ( struct V_7 * V_7 , char * V_8 , T_1 V_9 ,
struct V_1 * V_2 )
{
if ( V_2 -> V_6 . V_5 )
return F_3 ( V_8 , V_9 , L_1 , V_7 -> V_5 , V_2 -> V_6 . V_5 ) ;
if ( V_2 -> V_6 . V_12 == 0 )
return F_2 ( V_7 , V_8 , V_9 , V_2 ) ;
return F_3 ( V_8 , V_9 , L_2 V_14 , V_7 -> V_5 , V_2 -> V_6 . V_12 ) ;
}
bool F_9 ( const struct V_7 * V_7 )
{
return V_7 -> V_2 == & V_15 ;
}
static int F_10 ( struct V_1 * V_2 )
{
const char * V_16 = strchr ( V_2 -> V_4 , '+' ) ;
V_2 -> V_6 . V_12 = strtoll ( V_2 -> V_4 , NULL , 16 ) ;
if ( V_16 ++ != NULL )
V_2 -> V_6 . V_17 = strtoll ( V_16 , NULL , 16 ) ;
else
V_2 -> V_6 . V_17 = V_18 ;
return 0 ;
}
static int F_11 ( struct V_7 * V_7 , char * V_8 , T_1 V_9 ,
struct V_1 * V_2 )
{
return F_3 ( V_8 , V_9 , L_3 V_14 , V_7 -> V_5 , V_2 -> V_6 . V_17 ) ;
}
bool F_12 ( const struct V_7 * V_7 )
{
return V_7 -> V_2 == & V_19 ;
}
static int F_13 ( char * V_4 , char * V_20 , T_2 * V_21 , char * * V_22 )
{
char * V_10 , * V_5 , * V_23 ;
if ( strstr ( V_4 , L_4 ) == NULL )
return 0 ;
* V_21 = F_6 ( V_20 , & V_10 , 16 ) ;
V_5 = strchr ( V_10 , '<' ) ;
if ( V_5 == NULL )
return - 1 ;
V_5 ++ ;
V_23 = strchr ( V_5 , '>' ) ;
if ( V_23 == NULL )
return 0 ;
* V_23 = '\0' ;
* V_22 = F_7 ( V_5 ) ;
* V_23 = '>' ;
return 0 ;
}
static int F_14 ( struct V_1 * V_2 )
{
char * V_5 ;
V_2 -> V_24 . V_2 = F_15 ( sizeof( * V_2 -> V_24 . V_2 ) ) ;
if ( V_2 -> V_24 . V_2 == NULL )
return 0 ;
if ( F_16 ( V_2 -> V_4 , & V_5 , & V_2 -> V_24 . V_2 -> V_4 ) < 0 )
goto V_25;
V_2 -> V_24 . V_7 = F_17 ( V_5 ) ;
if ( V_2 -> V_24 . V_7 == NULL )
goto V_25;
if ( ! V_2 -> V_24 . V_7 -> V_2 )
return 0 ;
if ( V_2 -> V_24 . V_7 -> V_2 -> V_26 )
V_2 -> V_24 . V_7 -> V_2 -> V_26 ( V_2 -> V_24 . V_2 ) ;
return 0 ;
V_25:
free ( V_2 -> V_24 . V_2 ) ;
V_2 -> V_24 . V_2 = NULL ;
return 0 ;
}
static int F_18 ( struct V_7 * V_7 , char * V_8 , T_1 V_9 ,
struct V_1 * V_2 )
{
int V_27 ;
if ( V_2 -> V_24 . V_7 == NULL )
return F_2 ( V_7 , V_8 , V_9 , V_2 ) ;
V_27 = F_3 ( V_8 , V_9 , L_5 , V_7 -> V_5 ) ;
return V_27 + F_4 ( V_2 -> V_24 . V_7 , V_8 + V_27 ,
V_9 - V_27 , V_2 -> V_24 . V_2 ) ;
}
static void F_19 ( struct V_1 * V_2 )
{
free ( V_2 -> V_24 . V_2 ) ;
free ( V_2 -> V_6 . V_4 ) ;
free ( V_2 -> V_6 . V_5 ) ;
}
static int F_20 ( struct V_1 * V_2 )
{
char * V_16 = strchr ( V_2 -> V_4 , ',' ) , * V_6 , * V_20 , V_28 ;
if ( V_16 == NULL )
return - 1 ;
* V_16 = '\0' ;
V_2 -> V_3 . V_4 = F_7 ( V_2 -> V_4 ) ;
* V_16 = ',' ;
if ( V_2 -> V_3 . V_4 == NULL )
return - 1 ;
V_6 = ++ V_16 ;
while ( V_16 [ 0 ] != '\0' && ! isspace ( V_16 [ 0 ] ) )
++ V_16 ;
V_28 = * V_16 ;
* V_16 = '\0' ;
V_2 -> V_6 . V_4 = F_7 ( V_6 ) ;
* V_16 = V_28 ;
if ( V_2 -> V_6 . V_4 == NULL )
goto V_29;
V_20 = strchr ( V_16 , '#' ) ;
if ( V_20 == NULL )
return 0 ;
while ( V_20 [ 0 ] != '\0' && isspace ( V_20 [ 0 ] ) )
++ V_20 ;
F_13 ( V_2 -> V_3 . V_4 , V_20 , & V_2 -> V_3 . V_12 , & V_2 -> V_3 . V_5 ) ;
F_13 ( V_2 -> V_6 . V_4 , V_20 , & V_2 -> V_6 . V_12 , & V_2 -> V_6 . V_5 ) ;
return 0 ;
V_29:
free ( V_2 -> V_3 . V_4 ) ;
V_2 -> V_3 . V_4 = NULL ;
return - 1 ;
}
static int F_21 ( struct V_7 * V_7 , char * V_8 , T_1 V_9 ,
struct V_1 * V_2 )
{
return F_3 ( V_8 , V_9 , L_6 , V_7 -> V_5 ,
V_2 -> V_3 . V_5 ? : V_2 -> V_3 . V_4 ,
V_2 -> V_6 . V_5 ? : V_2 -> V_6 . V_4 ) ;
}
static int F_22 ( struct V_1 * V_2 )
{
char * V_6 , * V_20 , * V_16 , V_28 ;
V_6 = V_16 = V_2 -> V_4 ;
while ( V_16 [ 0 ] != '\0' && ! isspace ( V_16 [ 0 ] ) )
++ V_16 ;
V_28 = * V_16 ;
* V_16 = '\0' ;
V_2 -> V_6 . V_4 = F_7 ( V_6 ) ;
* V_16 = V_28 ;
if ( V_2 -> V_6 . V_4 == NULL )
return - 1 ;
V_20 = strchr ( V_16 , '#' ) ;
if ( V_20 == NULL )
return 0 ;
while ( V_20 [ 0 ] != '\0' && isspace ( V_20 [ 0 ] ) )
++ V_20 ;
F_13 ( V_2 -> V_6 . V_4 , V_20 , & V_2 -> V_6 . V_12 , & V_2 -> V_6 . V_5 ) ;
return 0 ;
}
static int F_23 ( struct V_7 * V_7 , char * V_8 , T_1 V_9 ,
struct V_1 * V_2 )
{
return F_3 ( V_8 , V_9 , L_1 , V_7 -> V_5 ,
V_2 -> V_6 . V_5 ? : V_2 -> V_6 . V_4 ) ;
}
static int F_24 ( struct V_7 * V_7 V_30 , char * V_8 , T_1 V_9 ,
struct V_1 * V_2 V_30 )
{
return F_3 ( V_8 , V_9 , L_7 , L_8 ) ;
}
static int F_25 ( const void * V_5 , const void * V_31 )
{
const struct V_7 * V_7 = V_31 ;
return strcmp ( V_5 , V_7 -> V_5 ) ;
}
static struct V_7 * F_17 ( const char * V_5 )
{
const int V_32 = F_26 ( V_33 ) ;
return bsearch ( V_5 , V_33 , V_32 , sizeof( struct V_7 ) , F_25 ) ;
}
int F_27 ( struct V_34 * V_34 V_30 , struct V_35 * V_36 )
{
struct V_37 * V_38 = F_28 ( V_36 ) ;
F_29 ( & V_38 -> V_39 , NULL ) ;
return 0 ;
}
int F_30 ( struct V_35 * V_36 )
{
struct V_37 * V_38 = F_28 ( V_36 ) ;
const T_1 V_9 = F_31 ( V_36 ) ;
T_1 V_40 ;
if ( V_9 > ( V_41 - sizeof( struct V_42 ) ) / sizeof( T_2 ) )
return - 1 ;
V_40 = ( sizeof( struct V_42 ) + V_9 * sizeof( T_2 ) ) ;
if ( V_40 > ( V_41 - sizeof( * V_38 -> V_43 ) )
/ V_44 . V_45 )
return - 1 ;
V_38 -> V_43 = F_15 ( sizeof( * V_38 -> V_43 ) + V_44 . V_45 * V_40 ) ;
if ( V_38 -> V_43 == NULL )
return - 1 ;
V_38 -> V_43 -> V_40 = V_40 ;
V_38 -> V_43 -> V_46 = V_44 . V_45 ;
F_32 ( & V_38 -> V_43 -> V_3 ) ;
return 0 ;
}
void F_33 ( struct V_35 * V_36 )
{
struct V_37 * V_38 = F_28 ( V_36 ) ;
F_34 ( & V_38 -> V_39 ) ;
if ( V_38 -> V_43 != NULL )
memset ( V_38 -> V_43 -> V_47 , 0 ,
V_38 -> V_43 -> V_46 * V_38 -> V_43 -> V_40 ) ;
F_35 ( & V_38 -> V_39 ) ;
}
int F_36 ( struct V_35 * V_36 , struct V_34 * V_34 ,
int V_48 , T_2 V_12 )
{
unsigned V_17 ;
struct V_37 * V_38 ;
struct V_42 * V_49 ;
V_38 = F_28 ( V_36 ) ;
if ( V_38 -> V_43 == NULL )
return - V_50 ;
F_37 ( L_9 V_14 L_10 , V_51 , V_34 -> V_52 ( V_34 , V_12 ) ) ;
if ( V_12 < V_36 -> V_53 || V_12 > V_36 -> V_54 )
return - V_55 ;
V_17 = V_12 - V_36 -> V_53 ;
V_49 = F_38 ( V_38 , V_48 ) ;
V_49 -> V_56 ++ ;
V_49 -> V_12 [ V_17 ] ++ ;
F_37 ( L_11 V_14 L_12 V_14 L_13 V_14
L_14 V_57 L_10 , V_36 -> V_53 , V_36 -> V_5 ,
V_12 , V_12 - V_36 -> V_53 , V_48 , V_49 -> V_12 [ V_17 ] ) ;
return 0 ;
}
static void F_39 ( struct V_58 * V_59 )
{
V_59 -> V_7 = F_17 ( V_59 -> V_5 ) ;
if ( V_59 -> V_7 == NULL )
return;
if ( ! V_59 -> V_7 -> V_2 )
return;
if ( V_59 -> V_7 -> V_2 -> V_26 )
V_59 -> V_7 -> V_2 -> V_26 ( & V_59 -> V_2 ) ;
}
static int F_16 ( char * line , char * * V_22 , char * * V_60 )
{
char * V_5 = line , V_61 ;
while ( isspace ( V_5 [ 0 ] ) )
++ V_5 ;
if ( V_5 [ 0 ] == '\0' )
return - 1 ;
* V_60 = V_5 + 1 ;
while ( ( * V_60 ) [ 0 ] != '\0' && ! isspace ( ( * V_60 ) [ 0 ] ) )
++ * V_60 ;
V_61 = ( * V_60 ) [ 0 ] ;
( * V_60 ) [ 0 ] = '\0' ;
* V_22 = F_7 ( V_5 ) ;
if ( * V_22 == NULL )
goto V_62;
( * V_60 ) [ 0 ] = V_61 ;
if ( ( * V_60 ) [ 0 ] != '\0' ) {
( * V_60 ) ++ ;
while ( isspace ( ( * V_60 ) [ 0 ] ) )
++ ( * V_60 ) ;
}
return 0 ;
V_62:
free ( * V_22 ) ;
* V_22 = NULL ;
return - 1 ;
}
static struct V_58 * F_40 ( T_3 V_17 , char * line , T_1 V_63 )
{
struct V_58 * V_59 = F_15 ( sizeof( * V_59 ) + V_63 ) ;
if ( V_59 != NULL ) {
V_59 -> V_17 = V_17 ;
V_59 -> line = F_7 ( line ) ;
if ( V_59 -> line == NULL )
goto V_64;
if ( V_17 != - 1 ) {
if ( F_16 ( V_59 -> line , & V_59 -> V_5 , & V_59 -> V_2 . V_4 ) < 0 )
goto V_65;
F_39 ( V_59 ) ;
}
}
return V_59 ;
V_65:
free ( V_59 -> line ) ;
V_64:
free ( V_59 ) ;
return NULL ;
}
void F_41 ( struct V_58 * V_59 )
{
free ( V_59 -> line ) ;
free ( V_59 -> V_5 ) ;
if ( V_59 -> V_7 && V_59 -> V_7 -> V_2 -> free )
V_59 -> V_7 -> V_2 -> free ( & V_59 -> V_2 ) ;
else
F_1 ( & V_59 -> V_2 ) ;
free ( V_59 ) ;
}
int F_42 ( struct V_58 * V_59 , char * V_8 , T_1 V_9 , bool V_4 )
{
if ( V_4 || ! V_59 -> V_7 )
return F_3 ( V_8 , V_9 , L_1 , V_59 -> V_5 , V_59 -> V_2 . V_4 ) ;
return F_4 ( V_59 -> V_7 , V_8 , V_9 , & V_59 -> V_2 ) ;
}
static void F_43 ( struct V_66 * V_67 , struct V_58 * line )
{
F_44 ( & line -> V_68 , V_67 ) ;
}
struct V_58 * F_45 ( struct V_66 * V_67 , struct V_58 * V_69 )
{
F_46 (pos, head, node)
if ( V_69 -> V_17 >= 0 )
return V_69 ;
return NULL ;
}
double F_47 ( struct V_37 * V_38 , int V_48 , T_3 V_17 ,
T_3 V_54 , const char * * V_70 )
{
struct V_71 * V_72 = V_38 -> V_43 -> V_73 ;
double V_74 = 0.0 ;
if ( V_72 ) {
T_1 V_75 = sizeof( * V_72 ) +
sizeof( V_72 -> V_76 ) * ( V_72 -> V_77 - 1 ) ;
while ( V_17 < V_54 ) {
V_72 = ( void * ) V_38 -> V_43 -> V_73 +
( V_75 * V_17 ) ;
if ( * V_70 == NULL )
* V_70 = V_72 -> V_70 ;
V_74 += V_72 -> V_76 [ V_48 ] . V_74 ;
V_17 ++ ;
}
} else {
struct V_42 * V_49 = F_38 ( V_38 , V_48 ) ;
unsigned int V_78 = 0 ;
while ( V_17 < V_54 )
V_78 += V_49 -> V_12 [ V_17 ++ ] ;
if ( V_49 -> V_56 )
V_74 = 100.0 * V_78 / V_49 -> V_56 ;
}
return V_74 ;
}
static int F_48 ( struct V_58 * V_59 , struct V_35 * V_36 , T_2 V_53 ,
struct V_79 * V_80 , T_2 V_81 , int V_82 , int V_27 ,
int V_83 , struct V_58 * V_84 )
{
static const char * V_85 ;
static const char * V_86 ;
if ( V_59 -> V_17 != - 1 ) {
const char * V_70 = NULL ;
double V_74 , V_87 = 0.0 ;
double * V_88 = & V_74 ;
int V_89 , V_90 = 1 ;
const char * V_91 ;
struct V_37 * V_38 = F_28 ( V_36 ) ;
T_3 V_17 = V_59 -> V_17 ;
const T_2 V_12 = V_53 + V_17 ;
struct V_58 * V_92 ;
V_92 = F_45 ( & V_38 -> V_43 -> V_3 , V_59 ) ;
if ( F_49 ( V_80 ) ) {
V_90 = V_80 -> V_93 ;
V_88 = calloc ( V_90 , sizeof( double ) ) ;
if ( V_88 == NULL )
return - 1 ;
}
for ( V_89 = 0 ; V_89 < V_90 ; V_89 ++ ) {
V_74 = F_47 ( V_38 ,
V_38 -> V_43 -> V_73 ? V_89 : V_80 -> V_94 + V_89 ,
V_17 ,
V_92 ? V_92 -> V_17 : ( T_3 ) V_81 ,
& V_70 ) ;
V_88 [ V_89 ] = V_74 ;
if ( V_74 > V_87 )
V_87 = V_74 ;
}
if ( V_87 < V_82 )
return - 1 ;
if ( V_83 && V_27 >= V_83 )
return 1 ;
if ( V_84 != NULL ) {
F_50 (queue, &notes->src->source, node) {
if ( V_84 == V_59 )
break;
F_48 ( V_84 , V_36 , V_53 , V_80 , V_81 ,
0 , 0 , 1 , NULL ) ;
}
}
V_91 = F_51 ( V_87 ) ;
if ( V_70 ) {
if ( ! V_85 || strcmp ( V_85 , V_70 )
|| V_91 != V_86 ) {
F_52 ( stdout , V_91 , L_15 , V_70 ) ;
V_85 = V_70 ;
V_86 = V_91 ;
}
}
for ( V_89 = 0 ; V_89 < V_90 ; V_89 ++ ) {
V_74 = V_88 [ V_89 ] ;
V_91 = F_51 ( V_74 ) ;
F_52 ( stdout , V_91 , L_16 , V_74 ) ;
}
printf ( L_17 ) ;
F_52 ( stdout , V_95 , L_18 V_14 L_19 , V_12 ) ;
F_52 ( stdout , V_96 , L_20 , V_59 -> line ) ;
if ( V_88 != & V_74 )
free ( V_88 ) ;
} else if ( V_83 && V_27 >= V_83 )
return 1 ;
else {
int V_97 = 8 ;
if ( V_84 )
return - 1 ;
if ( F_49 ( V_80 ) )
V_97 *= V_80 -> V_93 ;
if ( ! * V_59 -> line )
printf ( L_21 , V_97 , L_22 ) ;
else
printf ( L_23 , V_97 , L_22 , V_59 -> line ) ;
}
return 0 ;
}
static int F_53 ( struct V_35 * V_36 , struct V_34 * V_34 ,
T_4 * V_98 , T_1 V_63 )
{
struct V_37 * V_38 = F_28 ( V_36 ) ;
struct V_58 * V_59 ;
char * line = NULL , * V_99 , * V_61 , * V_100 , * V_101 ;
T_1 V_102 ;
T_3 V_103 , V_17 = - 1 ;
if ( F_54 ( & line , & V_102 , V_98 ) < 0 )
return - 1 ;
if ( ! line )
return - 1 ;
while ( V_102 != 0 && isspace ( line [ V_102 - 1 ] ) )
line [ -- V_102 ] = '\0' ;
V_101 = strchr ( line , '\n' ) ;
if ( V_101 )
* V_101 = 0 ;
V_103 = - 1 ;
V_99 = line ;
V_61 = line ;
while ( * V_61 ) {
if ( * V_61 != ' ' )
break;
V_61 ++ ;
}
if ( * V_61 ) {
V_103 = F_6 ( V_61 , & V_100 , 16 ) ;
if ( * V_100 != ':' || V_61 == V_100 || V_100 [ 1 ] == '\0' )
V_103 = - 1 ;
}
if ( V_103 != - 1 ) {
T_2 V_53 = F_55 ( V_34 , V_36 -> V_53 ) ,
V_54 = F_55 ( V_34 , V_36 -> V_54 ) ;
V_17 = V_103 - V_53 ;
if ( V_17 < 0 || ( T_2 ) V_103 > V_54 )
V_17 = - 1 ;
else
V_99 = V_100 + 1 ;
}
V_59 = F_40 ( V_17 , V_99 , V_63 ) ;
free ( line ) ;
if ( V_59 == NULL )
return - 1 ;
F_43 ( & V_38 -> V_43 -> V_3 , V_59 ) ;
return 0 ;
}
int F_56 ( struct V_35 * V_36 , struct V_34 * V_34 , T_1 V_63 )
{
struct V_104 * V_104 = V_34 -> V_104 ;
char * V_105 = F_57 ( V_104 , NULL , 0 ) ;
bool V_106 = true ;
char V_107 [ V_108 * 2 ] ;
T_4 * V_98 ;
int V_109 = 0 ;
char V_110 [ V_108 ] ;
if ( V_105 ) {
snprintf ( V_110 , sizeof( V_110 ) , L_24 ,
V_44 . V_111 , V_105 ) ;
}
if ( V_105 == NULL ) {
if ( V_104 -> V_112 ) {
F_58 ( L_25 ,
V_36 -> V_5 ) ;
return - V_50 ;
}
goto V_113;
} else if ( F_59 ( V_110 , V_107 , sizeof( V_107 ) ) < 0 ||
strstr ( V_107 , L_26 ) ||
F_60 ( V_110 , V_114 ) ) {
free ( V_105 ) ;
V_113:
V_105 = V_104 -> V_115 ;
snprintf ( V_110 , sizeof( V_110 ) , L_24 ,
V_44 . V_111 , V_105 ) ;
V_106 = false ;
}
if ( V_104 -> V_116 == V_117 ) {
char V_8 [ V_118 * 2 + 16 ] = L_27 ;
char * V_119 = NULL ;
if ( V_104 -> V_120 )
goto V_121;
if ( V_104 -> V_112 ) {
F_61 ( V_104 -> V_122 ,
sizeof( V_104 -> V_122 ) , V_8 + 15 ) ;
V_119 = V_8 ;
}
V_109 = - V_123 ;
V_104 -> V_120 = 1 ;
F_58 ( L_28
L_29
L_30
L_31
L_32
L_33 ,
V_36 -> V_5 , V_119 ? : L_34 ) ;
goto V_121;
}
F_62 ( L_35 V_14 L_36 V_14 L_10 , V_51 ,
V_105 , V_36 -> V_5 , V_34 -> V_52 ( V_34 , V_36 -> V_53 ) ,
V_34 -> V_52 ( V_34 , V_36 -> V_54 ) ) ;
F_62 ( L_37 ,
V_104 , V_104 -> V_115 , V_36 , V_36 -> V_5 ) ;
snprintf ( V_107 , sizeof( V_107 ) ,
L_38 V_14
L_39 V_14
L_40 ,
V_124 ? V_124 : L_41 ,
V_125 ? L_42 : L_34 ,
V_125 ? V_125 : L_34 ,
F_55 ( V_34 , V_36 -> V_53 ) ,
F_55 ( V_34 , V_36 -> V_54 + 1 ) ,
V_44 . V_126 ? L_34 : L_43 ,
V_44 . V_127 ? L_44 : L_34 ,
V_110 , V_105 ) ;
F_62 ( L_45 , V_107 ) ;
V_98 = F_63 ( V_107 , L_46 ) ;
if ( ! V_98 )
goto V_121;
while ( ! feof ( V_98 ) )
if ( F_53 ( V_36 , V_34 , V_98 , V_63 ) < 0 )
break;
F_64 ( V_98 ) ;
V_121:
if ( V_106 )
free ( V_105 ) ;
return V_109 ;
}
static void F_65 ( struct V_128 * V_129 , struct V_71 * V_72 )
{
struct V_71 * V_130 ;
struct V_131 * * V_76 = & V_129 -> V_131 ;
struct V_131 * V_132 = NULL ;
int V_89 , V_133 ;
while ( * V_76 != NULL ) {
V_132 = * V_76 ;
V_130 = F_66 ( V_132 , struct V_71 , V_68 ) ;
V_133 = strcmp ( V_130 -> V_70 , V_72 -> V_70 ) ;
if ( V_133 == 0 ) {
for ( V_89 = 0 ; V_89 < V_72 -> V_77 ; V_89 ++ )
V_130 -> V_76 [ V_89 ] . V_134 += V_72 -> V_76 [ V_89 ] . V_74 ;
return;
}
if ( V_133 < 0 )
V_76 = & ( * V_76 ) -> V_135 ;
else
V_76 = & ( * V_76 ) -> V_136 ;
}
for ( V_89 = 0 ; V_89 < V_72 -> V_77 ; V_89 ++ )
V_72 -> V_76 [ V_89 ] . V_134 = V_72 -> V_76 [ V_89 ] . V_74 ;
F_67 ( & V_72 -> V_68 , V_132 , V_76 ) ;
F_68 ( & V_72 -> V_68 , V_129 ) ;
}
static int F_69 ( struct V_71 * V_137 , struct V_71 * V_138 )
{
int V_89 ;
for ( V_89 = 0 ; V_89 < V_137 -> V_77 ; V_89 ++ ) {
if ( V_137 -> V_76 [ V_89 ] . V_134 == V_138 -> V_76 [ V_89 ] . V_134 )
continue;
return V_137 -> V_76 [ V_89 ] . V_134 > V_138 -> V_76 [ V_89 ] . V_134 ;
}
return 0 ;
}
static void F_70 ( struct V_128 * V_129 , struct V_71 * V_72 )
{
struct V_71 * V_130 ;
struct V_131 * * V_76 = & V_129 -> V_131 ;
struct V_131 * V_132 = NULL ;
while ( * V_76 != NULL ) {
V_132 = * V_76 ;
V_130 = F_66 ( V_132 , struct V_71 , V_68 ) ;
if ( F_69 ( V_72 , V_130 ) )
V_76 = & ( * V_76 ) -> V_135 ;
else
V_76 = & ( * V_76 ) -> V_136 ;
}
F_67 ( & V_72 -> V_68 , V_132 , V_76 ) ;
F_68 ( & V_72 -> V_68 , V_129 ) ;
}
static void F_71 ( struct V_128 * V_139 , struct V_128 * V_140 )
{
struct V_71 * V_72 ;
struct V_131 * V_68 ;
V_68 = F_72 ( V_140 ) ;
while ( V_68 ) {
struct V_131 * V_92 ;
V_72 = F_66 ( V_68 , struct V_71 , V_68 ) ;
V_92 = F_73 ( V_68 ) ;
F_74 ( V_68 , V_140 ) ;
F_70 ( V_139 , V_72 ) ;
V_68 = V_92 ;
}
}
static void F_75 ( struct V_35 * V_36 , int V_81 )
{
struct V_37 * V_38 = F_28 ( V_36 ) ;
struct V_71 * V_72 = V_38 -> V_43 -> V_73 ;
T_1 V_75 ;
int V_89 ;
V_75 = sizeof( * V_72 ) +
( sizeof( V_72 -> V_76 ) * ( V_72 -> V_77 - 1 ) ) ;
for ( V_89 = 0 ; V_89 < V_81 ; V_89 ++ ) {
free ( V_72 -> V_70 ) ;
V_72 = ( void * ) V_72 + V_75 ;
}
free ( V_38 -> V_43 -> V_73 ) ;
V_38 -> V_43 -> V_73 = NULL ;
}
static int F_76 ( struct V_35 * V_36 , struct V_34 * V_34 ,
struct V_79 * V_80 ,
struct V_128 * V_129 , int V_81 ,
const char * V_105 )
{
T_2 V_53 ;
int V_89 , V_141 ;
int V_48 = V_80 -> V_94 ;
char V_142 [ V_108 * 2 ] ;
struct V_71 * V_72 ;
struct V_37 * V_38 = F_28 ( V_36 ) ;
struct V_42 * V_49 = F_38 ( V_38 , V_48 ) ;
struct V_128 V_143 = V_144 ;
int V_77 = 1 ;
T_2 V_145 = V_49 -> V_56 ;
T_1 V_75 = sizeof( struct V_71 ) ;
if ( F_49 ( V_80 ) ) {
for ( V_89 = 1 ; V_89 < V_80 -> V_93 ; V_89 ++ ) {
V_49 = F_38 ( V_38 , V_48 + V_89 ) ;
V_145 += V_49 -> V_56 ;
}
V_77 = V_80 -> V_93 ;
V_75 += ( V_77 - 1 ) * sizeof( V_72 -> V_76 ) ;
}
if ( ! V_145 )
return 0 ;
V_72 = V_38 -> V_43 -> V_73 = calloc ( V_81 , V_75 ) ;
if ( ! V_38 -> V_43 -> V_73 )
return - 1 ;
V_53 = F_55 ( V_34 , V_36 -> V_53 ) ;
for ( V_89 = 0 ; V_89 < V_81 ; V_89 ++ ) {
char * V_70 = NULL ;
T_1 V_102 ;
T_2 V_17 ;
T_4 * V_146 ;
double V_147 = 0.0 ;
V_72 -> V_77 = V_77 ;
for ( V_141 = 0 ; V_141 < V_77 ; V_141 ++ ) {
V_49 = F_38 ( V_38 , V_48 + V_141 ) ;
V_72 -> V_76 [ V_141 ] . V_74 = 100.0 * V_49 -> V_12 [ V_89 ] / V_49 -> V_56 ;
if ( V_72 -> V_76 [ V_141 ] . V_74 > V_147 )
V_147 = V_72 -> V_76 [ V_141 ] . V_74 ;
}
if ( V_147 <= 0.5 )
goto V_92;
V_17 = V_53 + V_89 ;
sprintf ( V_142 , L_47 V_14 , V_105 , V_17 ) ;
V_146 = F_63 ( V_142 , L_46 ) ;
if ( ! V_146 )
goto V_92;
if ( F_54 ( & V_70 , & V_102 , V_146 ) < 0 || ! V_102 )
goto V_148;
V_72 -> V_70 = malloc ( sizeof( char ) * V_102 + 1 ) ;
if ( ! V_72 -> V_70 )
goto V_148;
strcpy ( V_72 -> V_70 , V_70 ) ;
F_65 ( & V_143 , V_72 ) ;
V_148:
F_64 ( V_146 ) ;
V_92:
V_72 = ( void * ) V_72 + V_75 ;
}
F_71 ( V_129 , & V_143 ) ;
return 0 ;
}
static void F_77 ( struct V_128 * V_129 , const char * V_105 )
{
struct V_71 * V_72 ;
struct V_131 * V_68 ;
printf ( L_48 , V_105 ) ;
printf ( L_49 ) ;
if ( F_78 ( V_129 ) ) {
printf ( L_50 , V_149 ) ;
return;
}
V_68 = F_72 ( V_129 ) ;
while ( V_68 ) {
double V_74 , V_147 = 0.0 ;
const char * V_91 ;
char * V_70 ;
int V_89 ;
V_72 = F_66 ( V_68 , struct V_71 , V_68 ) ;
for ( V_89 = 0 ; V_89 < V_72 -> V_77 ; V_89 ++ ) {
V_74 = V_72 -> V_76 [ V_89 ] . V_134 ;
V_91 = F_51 ( V_74 ) ;
F_52 ( stdout , V_91 , L_16 , V_74 ) ;
if ( V_74 > V_147 )
V_147 = V_74 ;
}
V_70 = V_72 -> V_70 ;
V_91 = F_51 ( V_147 ) ;
F_52 ( stdout , V_91 , L_15 , V_70 ) ;
V_68 = F_73 ( V_68 ) ;
}
}
static void F_79 ( struct V_35 * V_36 , struct V_79 * V_80 )
{
struct V_37 * V_38 = F_28 ( V_36 ) ;
struct V_42 * V_49 = F_38 ( V_38 , V_80 -> V_94 ) ;
T_2 V_81 = F_31 ( V_36 ) , V_17 ;
for ( V_17 = 0 ; V_17 < V_81 ; ++ V_17 )
if ( V_49 -> V_12 [ V_17 ] != 0 )
printf ( L_51 V_14 L_52 V_57 L_10 , V_150 / 2 ,
V_36 -> V_53 + V_17 , V_49 -> V_12 [ V_17 ] ) ;
printf ( L_53 V_57 L_10 , V_150 / 2 , L_54 , V_49 -> V_56 ) ;
}
int F_80 ( struct V_35 * V_36 , struct V_34 * V_34 ,
struct V_79 * V_80 , bool V_151 ,
int V_82 , int V_83 , int V_152 )
{
struct V_104 * V_104 = V_34 -> V_104 ;
char * V_105 ;
const char * V_153 ;
struct V_37 * V_38 = F_28 ( V_36 ) ;
struct V_58 * V_69 , * V_84 = NULL ;
T_2 V_53 = F_55 ( V_34 , V_36 -> V_53 ) ;
int V_27 = 2 , V_154 = 0 ;
int V_155 = 0 ;
T_2 V_81 ;
int V_97 = 8 ;
int V_156 ;
V_105 = F_7 ( V_104 -> V_115 ) ;
if ( ! V_105 )
return - V_50 ;
if ( V_151 )
V_153 = V_105 ;
else
V_153 = F_81 ( V_105 ) ;
V_81 = F_31 ( V_36 ) ;
V_156 = strlen ( V_153 ) ;
if ( F_49 ( V_80 ) )
V_97 *= V_80 -> V_93 ;
printf ( L_55 ,
V_97 , V_97 , L_56 , V_153 ) ;
printf ( L_57 ,
V_97 + V_156 , V_97 + V_156 , V_157 ) ;
if ( V_158 )
F_79 ( V_36 , V_80 ) ;
F_82 (pos, &notes->src->source, node) {
if ( V_152 && V_84 == NULL ) {
V_84 = V_69 ;
V_154 = 0 ;
}
switch ( F_48 ( V_69 , V_36 , V_53 , V_80 , V_81 ,
V_82 , V_27 , V_83 ,
V_84 ) ) {
case 0 :
++ V_27 ;
if ( V_152 ) {
V_27 += V_154 ;
V_84 = NULL ;
V_154 = 0 ;
}
break;
case 1 :
++ V_155 ;
break;
case - 1 :
default:
if ( ! V_152 )
break;
if ( V_154 == V_152 )
V_84 = F_83 ( V_84 -> V_68 . V_92 , F_84 ( * V_84 ) , V_68 ) ;
else
++ V_154 ;
break;
}
}
free ( V_105 ) ;
return V_155 ;
}
void F_85 ( struct V_35 * V_36 , int V_48 )
{
struct V_37 * V_38 = F_28 ( V_36 ) ;
struct V_42 * V_49 = F_38 ( V_38 , V_48 ) ;
memset ( V_49 , 0 , V_38 -> V_43 -> V_40 ) ;
}
void F_86 ( struct V_35 * V_36 , int V_48 )
{
struct V_37 * V_38 = F_28 ( V_36 ) ;
struct V_42 * V_49 = F_38 ( V_38 , V_48 ) ;
int V_81 = F_31 ( V_36 ) , V_17 ;
V_49 -> V_56 = 0 ;
for ( V_17 = 0 ; V_17 < V_81 ; ++ V_17 ) {
V_49 -> V_12 [ V_17 ] = V_49 -> V_12 [ V_17 ] * 7 / 8 ;
V_49 -> V_56 += V_49 -> V_12 [ V_17 ] ;
}
}
void F_87 ( struct V_66 * V_67 )
{
struct V_58 * V_69 , * V_159 ;
F_88 (pos, n, head, node) {
F_89 ( & V_69 -> V_68 ) ;
F_41 ( V_69 ) ;
}
}
static T_1 F_90 ( struct V_58 * V_59 , T_4 * V_146 )
{
T_1 V_27 ;
if ( V_59 -> V_17 == - 1 )
return fprintf ( V_146 , L_20 , V_59 -> line ) ;
V_27 = fprintf ( V_146 , L_11 V_14 L_15 , V_59 -> V_17 , V_59 -> V_5 ) ;
if ( V_59 -> V_2 . V_4 [ 0 ] != '\0' ) {
V_27 += fprintf ( V_146 , L_58 , 6 - ( int ) V_27 , L_22 ,
V_59 -> V_2 . V_4 ) ;
}
return V_27 + fprintf ( V_146 , L_10 ) ;
}
T_1 F_91 ( struct V_66 * V_67 , T_4 * V_146 )
{
struct V_58 * V_69 ;
T_1 V_27 = 0 ;
F_82 (pos, head, node)
V_27 += F_90 ( V_69 , V_146 ) ;
return V_27 ;
}
int F_92 ( struct V_35 * V_36 , struct V_34 * V_34 ,
struct V_79 * V_80 , bool V_160 ,
bool V_151 , int V_82 , int V_83 )
{
struct V_104 * V_104 = V_34 -> V_104 ;
const char * V_105 = V_104 -> V_115 ;
struct V_128 V_71 = V_144 ;
T_2 V_81 ;
if ( F_56 ( V_36 , V_34 , 0 ) < 0 )
return - 1 ;
V_81 = F_31 ( V_36 ) ;
if ( V_160 ) {
F_76 ( V_36 , V_34 , V_80 , & V_71 ,
V_81 , V_105 ) ;
F_77 ( & V_71 , V_105 ) ;
}
F_80 ( V_36 , V_34 , V_80 , V_151 ,
V_82 , V_83 , 0 ) ;
if ( V_160 )
F_75 ( V_36 , V_81 ) ;
F_87 ( & F_28 ( V_36 ) -> V_43 -> V_3 ) ;
return 0 ;
}
