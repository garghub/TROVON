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
static int F_47 ( struct V_58 * V_59 , struct V_35 * V_36 , T_2 V_53 ,
int V_48 , T_2 V_70 , int V_71 , int V_27 ,
int V_72 , struct V_58 * V_73 )
{
static const char * V_74 ;
static const char * V_75 ;
if ( V_59 -> V_17 != - 1 ) {
const char * V_76 = NULL ;
unsigned int V_77 = 0 ;
double V_78 = 0.0 ;
const char * V_79 ;
struct V_37 * V_38 = F_28 ( V_36 ) ;
struct V_80 * V_81 = V_38 -> V_43 -> V_82 ;
struct V_42 * V_49 = F_38 ( V_38 , V_48 ) ;
T_3 V_17 = V_59 -> V_17 ;
const T_2 V_12 = V_53 + V_17 ;
struct V_58 * V_83 ;
V_83 = F_45 ( & V_38 -> V_43 -> V_3 , V_59 ) ;
while ( V_17 < ( T_3 ) V_70 &&
( V_83 == NULL || V_17 < V_83 -> V_17 ) ) {
if ( V_81 ) {
if ( V_76 == NULL )
V_76 = V_81 [ V_17 ] . V_76 ;
V_78 += V_81 [ V_17 ] . V_78 ;
} else
V_77 += V_49 -> V_12 [ V_17 ] ;
++ V_17 ;
}
if ( V_81 == NULL && V_49 -> V_56 )
V_78 = 100.0 * V_77 / V_49 -> V_56 ;
if ( V_78 < V_71 )
return - 1 ;
if ( V_72 && V_27 >= V_72 )
return 1 ;
if ( V_73 != NULL ) {
F_48 (queue, &notes->src->source, node) {
if ( V_73 == V_59 )
break;
F_47 ( V_73 , V_36 , V_53 , V_48 , V_70 ,
0 , 0 , 1 , NULL ) ;
}
}
V_79 = F_49 ( V_78 ) ;
if ( V_76 ) {
if ( ! V_74 || strcmp ( V_74 , V_76 )
|| V_79 != V_75 ) {
F_50 ( stdout , V_79 , L_15 , V_76 ) ;
V_74 = V_76 ;
V_75 = V_79 ;
}
}
F_50 ( stdout , V_79 , L_16 , V_78 ) ;
printf ( L_17 ) ;
F_50 ( stdout , V_84 , L_18 V_14 L_19 , V_12 ) ;
F_50 ( stdout , V_85 , L_20 , V_59 -> line ) ;
} else if ( V_72 && V_27 >= V_72 )
return 1 ;
else {
if ( V_73 )
return - 1 ;
if ( ! * V_59 -> line )
printf ( L_21 ) ;
else
printf ( L_22 , V_59 -> line ) ;
}
return 0 ;
}
static int F_51 ( struct V_35 * V_36 , struct V_34 * V_34 ,
T_4 * V_86 , T_1 V_63 )
{
struct V_37 * V_38 = F_28 ( V_36 ) ;
struct V_58 * V_59 ;
char * line = NULL , * V_87 , * V_61 , * V_88 , * V_89 ;
T_1 V_90 ;
T_3 V_91 , V_17 = - 1 ;
if ( F_52 ( & line , & V_90 , V_86 ) < 0 )
return - 1 ;
if ( ! line )
return - 1 ;
while ( V_90 != 0 && isspace ( line [ V_90 - 1 ] ) )
line [ -- V_90 ] = '\0' ;
V_89 = strchr ( line , '\n' ) ;
if ( V_89 )
* V_89 = 0 ;
V_91 = - 1 ;
V_87 = line ;
V_61 = line ;
while ( * V_61 ) {
if ( * V_61 != ' ' )
break;
V_61 ++ ;
}
if ( * V_61 ) {
V_91 = F_6 ( V_61 , & V_88 , 16 ) ;
if ( * V_88 != ':' || V_61 == V_88 || V_88 [ 1 ] == '\0' )
V_91 = - 1 ;
}
if ( V_91 != - 1 ) {
T_2 V_53 = F_53 ( V_34 , V_36 -> V_53 ) ,
V_54 = F_53 ( V_34 , V_36 -> V_54 ) ;
V_17 = V_91 - V_53 ;
if ( V_17 < 0 || ( T_2 ) V_91 > V_54 )
V_17 = - 1 ;
else
V_87 = V_88 + 1 ;
}
V_59 = F_40 ( V_17 , V_87 , V_63 ) ;
free ( line ) ;
if ( V_59 == NULL )
return - 1 ;
F_43 ( & V_38 -> V_43 -> V_3 , V_59 ) ;
return 0 ;
}
int F_54 ( struct V_35 * V_36 , struct V_34 * V_34 , T_1 V_63 )
{
struct V_92 * V_92 = V_34 -> V_92 ;
char * V_93 = F_55 ( V_92 , NULL , 0 ) ;
bool V_94 = true ;
char V_95 [ V_96 * 2 ] ;
T_4 * V_86 ;
int V_97 = 0 ;
char V_98 [ V_96 ] ;
if ( V_93 ) {
snprintf ( V_98 , sizeof( V_98 ) , L_23 ,
V_44 . V_99 , V_93 ) ;
}
if ( V_93 == NULL ) {
if ( V_92 -> V_100 ) {
F_56 ( L_24 ,
V_36 -> V_5 ) ;
return - V_50 ;
}
goto V_101;
} else if ( F_57 ( V_98 , V_95 , sizeof( V_95 ) ) < 0 ||
strstr ( V_95 , L_25 ) ||
F_58 ( V_98 , V_102 ) ) {
free ( V_93 ) ;
V_101:
V_93 = V_92 -> V_103 ;
snprintf ( V_98 , sizeof( V_98 ) , L_23 ,
V_44 . V_99 , V_93 ) ;
V_94 = false ;
}
if ( V_92 -> V_104 == V_105 ) {
char V_8 [ V_106 * 2 + 16 ] = L_26 ;
char * V_107 = NULL ;
if ( V_92 -> V_108 )
goto V_109;
if ( V_92 -> V_100 ) {
F_59 ( V_92 -> V_110 ,
sizeof( V_92 -> V_110 ) , V_8 + 15 ) ;
V_107 = V_8 ;
}
V_97 = - V_111 ;
V_92 -> V_108 = 1 ;
F_56 ( L_27
L_28
L_29
L_30
L_31
L_32 ,
V_36 -> V_5 , V_107 ? : L_33 ) ;
goto V_109;
}
F_60 ( L_34 V_14 L_35 V_14 L_10 , V_51 ,
V_93 , V_36 -> V_5 , V_34 -> V_52 ( V_34 , V_36 -> V_53 ) ,
V_34 -> V_52 ( V_34 , V_36 -> V_54 ) ) ;
F_60 ( L_36 ,
V_92 , V_92 -> V_103 , V_36 , V_36 -> V_5 ) ;
snprintf ( V_95 , sizeof( V_95 ) ,
L_37 V_14
L_38 V_14
L_39 ,
V_112 ? L_40 : L_33 ,
V_112 ? V_112 : L_33 ,
F_53 ( V_34 , V_36 -> V_53 ) ,
F_53 ( V_34 , V_36 -> V_54 + 1 ) ,
V_44 . V_113 ? L_33 : L_41 ,
V_44 . V_114 ? L_42 : L_33 ,
V_98 , V_93 ) ;
F_60 ( L_43 , V_95 ) ;
V_86 = F_61 ( V_95 , L_44 ) ;
if ( ! V_86 )
goto V_109;
while ( ! feof ( V_86 ) )
if ( F_51 ( V_36 , V_34 , V_86 , V_63 ) < 0 )
break;
F_62 ( V_86 ) ;
V_109:
if ( V_94 )
free ( V_93 ) ;
return V_97 ;
}
static void F_63 ( struct V_115 * V_116 , struct V_80 * V_81 )
{
struct V_80 * V_117 ;
struct V_118 * * V_119 = & V_116 -> V_118 ;
struct V_118 * V_120 = NULL ;
while ( * V_119 != NULL ) {
V_120 = * V_119 ;
V_117 = F_64 ( V_120 , struct V_80 , V_68 ) ;
if ( V_81 -> V_78 > V_117 -> V_78 )
V_119 = & ( * V_119 ) -> V_121 ;
else
V_119 = & ( * V_119 ) -> V_122 ;
}
F_65 ( & V_81 -> V_68 , V_120 , V_119 ) ;
F_66 ( & V_81 -> V_68 , V_116 ) ;
}
static void F_67 ( struct V_35 * V_36 , int V_70 )
{
struct V_37 * V_38 = F_28 ( V_36 ) ;
struct V_80 * V_81 = V_38 -> V_43 -> V_82 ;
int V_123 ;
for ( V_123 = 0 ; V_123 < V_70 ; V_123 ++ )
free ( V_81 [ V_123 ] . V_76 ) ;
free ( V_81 ) ;
V_38 -> V_43 -> V_82 = NULL ;
}
static int F_68 ( struct V_35 * V_36 , struct V_34 * V_34 ,
int V_48 , struct V_115 * V_116 , int V_70 ,
const char * V_93 )
{
T_2 V_53 ;
int V_123 ;
char V_124 [ V_96 * 2 ] ;
struct V_80 * V_81 ;
struct V_37 * V_38 = F_28 ( V_36 ) ;
struct V_42 * V_49 = F_38 ( V_38 , V_48 ) ;
if ( ! V_49 -> V_56 )
return 0 ;
V_81 = V_38 -> V_43 -> V_82 = calloc ( V_70 , sizeof( struct V_80 ) ) ;
if ( ! V_38 -> V_43 -> V_82 )
return - 1 ;
V_53 = F_53 ( V_34 , V_36 -> V_53 ) ;
for ( V_123 = 0 ; V_123 < V_70 ; V_123 ++ ) {
char * V_76 = NULL ;
T_1 V_90 ;
T_2 V_17 ;
T_4 * V_125 ;
V_81 [ V_123 ] . V_78 = 100.0 * V_49 -> V_12 [ V_123 ] / V_49 -> V_56 ;
if ( V_81 [ V_123 ] . V_78 <= 0.5 )
continue;
V_17 = V_53 + V_123 ;
sprintf ( V_124 , L_45 V_14 , V_93 , V_17 ) ;
V_125 = F_61 ( V_124 , L_44 ) ;
if ( ! V_125 )
continue;
if ( F_52 ( & V_76 , & V_90 , V_125 ) < 0 || ! V_90 )
goto V_83;
V_81 [ V_123 ] . V_76 = malloc ( sizeof( char ) * V_90 + 1 ) ;
if ( ! V_81 [ V_123 ] . V_76 )
goto V_83;
strcpy ( V_81 [ V_123 ] . V_76 , V_76 ) ;
F_63 ( V_116 , & V_81 [ V_123 ] ) ;
V_83:
F_62 ( V_125 ) ;
}
return 0 ;
}
static void F_69 ( struct V_115 * V_116 , const char * V_93 )
{
struct V_80 * V_81 ;
struct V_118 * V_68 ;
printf ( L_46 , V_93 ) ;
printf ( L_47 ) ;
if ( F_70 ( V_116 ) ) {
printf ( L_48 , V_126 ) ;
return;
}
V_68 = F_71 ( V_116 ) ;
while ( V_68 ) {
double V_78 ;
const char * V_79 ;
char * V_76 ;
V_81 = F_64 ( V_68 , struct V_80 , V_68 ) ;
V_78 = V_81 -> V_78 ;
V_79 = F_49 ( V_78 ) ;
V_76 = V_81 -> V_76 ;
F_50 ( stdout , V_79 , L_49 , V_78 , V_76 ) ;
V_68 = F_72 ( V_68 ) ;
}
}
static void F_73 ( struct V_35 * V_36 , int V_48 )
{
struct V_37 * V_38 = F_28 ( V_36 ) ;
struct V_42 * V_49 = F_38 ( V_38 , V_48 ) ;
T_2 V_70 = F_31 ( V_36 ) , V_17 ;
for ( V_17 = 0 ; V_17 < V_70 ; ++ V_17 )
if ( V_49 -> V_12 [ V_17 ] != 0 )
printf ( L_50 V_14 L_51 V_57 L_10 , V_127 / 2 ,
V_36 -> V_53 + V_17 , V_49 -> V_12 [ V_17 ] ) ;
printf ( L_52 V_57 L_10 , V_127 / 2 , L_53 , V_49 -> V_56 ) ;
}
int F_74 ( struct V_35 * V_36 , struct V_34 * V_34 , int V_48 ,
bool V_128 , int V_71 , int V_72 ,
int V_129 )
{
struct V_92 * V_92 = V_34 -> V_92 ;
const char * V_93 = V_92 -> V_103 , * V_130 ;
struct V_37 * V_38 = F_28 ( V_36 ) ;
struct V_58 * V_69 , * V_73 = NULL ;
T_2 V_53 = F_53 ( V_34 , V_36 -> V_53 ) ;
int V_27 = 2 , V_131 = 0 ;
int V_132 = 0 ;
T_2 V_70 ;
if ( V_128 )
V_130 = V_93 ;
else
V_130 = F_75 ( V_93 ) ;
V_70 = F_31 ( V_36 ) ;
printf ( L_54 , V_130 ) ;
printf ( L_55 ) ;
if ( V_133 )
F_73 ( V_36 , V_48 ) ;
F_76 (pos, &notes->src->source, node) {
if ( V_129 && V_73 == NULL ) {
V_73 = V_69 ;
V_131 = 0 ;
}
switch ( F_47 ( V_69 , V_36 , V_53 , V_48 , V_70 ,
V_71 , V_27 , V_72 ,
V_73 ) ) {
case 0 :
++ V_27 ;
if ( V_129 ) {
V_27 += V_131 ;
V_73 = NULL ;
V_131 = 0 ;
}
break;
case 1 :
++ V_132 ;
break;
case - 1 :
default:
if ( ! V_129 )
break;
if ( V_131 == V_129 )
V_73 = F_77 ( V_73 -> V_68 . V_83 , F_78 ( * V_73 ) , V_68 ) ;
else
++ V_131 ;
break;
}
}
return V_132 ;
}
void F_79 ( struct V_35 * V_36 , int V_48 )
{
struct V_37 * V_38 = F_28 ( V_36 ) ;
struct V_42 * V_49 = F_38 ( V_38 , V_48 ) ;
memset ( V_49 , 0 , V_38 -> V_43 -> V_40 ) ;
}
void F_80 ( struct V_35 * V_36 , int V_48 )
{
struct V_37 * V_38 = F_28 ( V_36 ) ;
struct V_42 * V_49 = F_38 ( V_38 , V_48 ) ;
int V_70 = F_31 ( V_36 ) , V_17 ;
V_49 -> V_56 = 0 ;
for ( V_17 = 0 ; V_17 < V_70 ; ++ V_17 ) {
V_49 -> V_12 [ V_17 ] = V_49 -> V_12 [ V_17 ] * 7 / 8 ;
V_49 -> V_56 += V_49 -> V_12 [ V_17 ] ;
}
}
void F_81 ( struct V_66 * V_67 )
{
struct V_58 * V_69 , * V_134 ;
F_82 (pos, n, head, node) {
F_83 ( & V_69 -> V_68 ) ;
F_41 ( V_69 ) ;
}
}
static T_1 F_84 ( struct V_58 * V_59 , T_4 * V_125 )
{
T_1 V_27 ;
if ( V_59 -> V_17 == - 1 )
return fprintf ( V_125 , L_20 , V_59 -> line ) ;
V_27 = fprintf ( V_125 , L_11 V_14 L_15 , V_59 -> V_17 , V_59 -> V_5 ) ;
if ( V_59 -> V_2 . V_4 [ 0 ] != '\0' ) {
V_27 += fprintf ( V_125 , L_56 , 6 - ( int ) V_27 , L_57 ,
V_59 -> V_2 . V_4 ) ;
}
return V_27 + fprintf ( V_125 , L_10 ) ;
}
T_1 F_85 ( struct V_66 * V_67 , T_4 * V_125 )
{
struct V_58 * V_69 ;
T_1 V_27 = 0 ;
F_76 (pos, head, node)
V_27 += F_84 ( V_69 , V_125 ) ;
return V_27 ;
}
int F_86 ( struct V_35 * V_36 , struct V_34 * V_34 , int V_48 ,
bool V_135 , bool V_128 , int V_71 ,
int V_72 )
{
struct V_92 * V_92 = V_34 -> V_92 ;
const char * V_93 = V_92 -> V_103 ;
struct V_115 V_80 = V_136 ;
T_2 V_70 ;
if ( F_54 ( V_36 , V_34 , 0 ) < 0 )
return - 1 ;
V_70 = F_31 ( V_36 ) ;
if ( V_135 ) {
F_68 ( V_36 , V_34 , V_48 , & V_80 ,
V_70 , V_93 ) ;
F_69 ( & V_80 , V_93 ) ;
}
F_74 ( V_36 , V_34 , V_48 , V_128 ,
V_71 , V_72 , 0 ) ;
if ( V_135 )
F_67 ( V_36 , V_70 ) ;
F_81 ( & F_28 ( V_36 ) -> V_43 -> V_3 ) ;
return 0 ;
}
