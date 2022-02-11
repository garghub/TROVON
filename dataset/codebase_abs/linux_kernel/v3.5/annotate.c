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
T_1 V_40 = ( sizeof( struct V_41 ) + V_9 * sizeof( T_2 ) ) ;
V_38 -> V_42 = F_15 ( sizeof( * V_38 -> V_42 ) + V_43 . V_44 * V_40 ) ;
if ( V_38 -> V_42 == NULL )
return - 1 ;
V_38 -> V_42 -> V_40 = V_40 ;
V_38 -> V_42 -> V_45 = V_43 . V_44 ;
F_32 ( & V_38 -> V_42 -> V_3 ) ;
return 0 ;
}
void F_33 ( struct V_35 * V_36 )
{
struct V_37 * V_38 = F_28 ( V_36 ) ;
F_34 ( & V_38 -> V_39 ) ;
if ( V_38 -> V_42 != NULL )
memset ( V_38 -> V_42 -> V_46 , 0 ,
V_38 -> V_42 -> V_45 * V_38 -> V_42 -> V_40 ) ;
F_35 ( & V_38 -> V_39 ) ;
}
int F_36 ( struct V_35 * V_36 , struct V_34 * V_34 ,
int V_47 , T_2 V_12 )
{
unsigned V_17 ;
struct V_37 * V_38 ;
struct V_41 * V_48 ;
V_38 = F_28 ( V_36 ) ;
if ( V_38 -> V_42 == NULL )
return - V_49 ;
F_37 ( L_9 V_14 L_10 , V_50 , V_34 -> V_51 ( V_34 , V_12 ) ) ;
if ( V_12 < V_36 -> V_52 || V_12 > V_36 -> V_53 )
return - V_54 ;
V_17 = V_12 - V_36 -> V_52 ;
V_48 = F_38 ( V_38 , V_47 ) ;
V_48 -> V_55 ++ ;
V_48 -> V_12 [ V_17 ] ++ ;
F_37 ( L_11 V_14 L_12 V_14 L_13 V_14
L_14 V_56 L_10 , V_36 -> V_52 , V_36 -> V_5 ,
V_12 , V_12 - V_36 -> V_52 , V_47 , V_48 -> V_12 [ V_17 ] ) ;
return 0 ;
}
static void F_39 ( struct V_57 * V_58 )
{
V_58 -> V_7 = F_17 ( V_58 -> V_5 ) ;
if ( V_58 -> V_7 == NULL )
return;
if ( ! V_58 -> V_7 -> V_2 )
return;
if ( V_58 -> V_7 -> V_2 -> V_26 )
V_58 -> V_7 -> V_2 -> V_26 ( & V_58 -> V_2 ) ;
}
static int F_16 ( char * line , char * * V_22 , char * * V_59 )
{
char * V_5 = line , V_60 ;
while ( isspace ( V_5 [ 0 ] ) )
++ V_5 ;
if ( V_5 [ 0 ] == '\0' )
return - 1 ;
* V_59 = V_5 + 1 ;
while ( ( * V_59 ) [ 0 ] != '\0' && ! isspace ( ( * V_59 ) [ 0 ] ) )
++ * V_59 ;
V_60 = ( * V_59 ) [ 0 ] ;
( * V_59 ) [ 0 ] = '\0' ;
* V_22 = F_7 ( V_5 ) ;
if ( * V_22 == NULL )
goto V_61;
( * V_59 ) [ 0 ] = V_60 ;
if ( ( * V_59 ) [ 0 ] != '\0' ) {
( * V_59 ) ++ ;
while ( isspace ( ( * V_59 ) [ 0 ] ) )
++ ( * V_59 ) ;
}
return 0 ;
V_61:
free ( * V_22 ) ;
* V_22 = NULL ;
return - 1 ;
}
static struct V_57 * F_40 ( T_3 V_17 , char * line , T_1 V_62 )
{
struct V_57 * V_58 = F_15 ( sizeof( * V_58 ) + V_62 ) ;
if ( V_58 != NULL ) {
V_58 -> V_17 = V_17 ;
V_58 -> line = F_7 ( line ) ;
if ( V_58 -> line == NULL )
goto V_63;
if ( V_17 != - 1 ) {
if ( F_16 ( V_58 -> line , & V_58 -> V_5 , & V_58 -> V_2 . V_4 ) < 0 )
goto V_64;
F_39 ( V_58 ) ;
}
}
return V_58 ;
V_64:
free ( V_58 -> line ) ;
V_63:
free ( V_58 ) ;
return NULL ;
}
void F_41 ( struct V_57 * V_58 )
{
free ( V_58 -> line ) ;
free ( V_58 -> V_5 ) ;
if ( V_58 -> V_7 && V_58 -> V_7 -> V_2 -> free )
V_58 -> V_7 -> V_2 -> free ( & V_58 -> V_2 ) ;
else
F_1 ( & V_58 -> V_2 ) ;
free ( V_58 ) ;
}
int F_42 ( struct V_57 * V_58 , char * V_8 , T_1 V_9 , bool V_4 )
{
if ( V_4 || ! V_58 -> V_7 )
return F_3 ( V_8 , V_9 , L_1 , V_58 -> V_5 , V_58 -> V_2 . V_4 ) ;
return F_4 ( V_58 -> V_7 , V_8 , V_9 , & V_58 -> V_2 ) ;
}
static void F_43 ( struct V_65 * V_66 , struct V_57 * line )
{
F_44 ( & line -> V_67 , V_66 ) ;
}
struct V_57 * F_45 ( struct V_65 * V_66 , struct V_57 * V_68 )
{
F_46 (pos, head, node)
if ( V_68 -> V_17 >= 0 )
return V_68 ;
return NULL ;
}
static int F_47 ( struct V_57 * V_58 , struct V_35 * V_36 , T_2 V_52 ,
int V_47 , T_2 V_69 , int V_70 , int V_27 ,
int V_71 , struct V_57 * V_72 )
{
static const char * V_73 ;
static const char * V_74 ;
if ( V_58 -> V_17 != - 1 ) {
const char * V_75 = NULL ;
unsigned int V_76 = 0 ;
double V_77 = 0.0 ;
const char * V_78 ;
struct V_37 * V_38 = F_28 ( V_36 ) ;
struct V_79 * V_80 = V_38 -> V_42 -> V_81 ;
struct V_41 * V_48 = F_38 ( V_38 , V_47 ) ;
T_3 V_17 = V_58 -> V_17 ;
const T_2 V_12 = V_52 + V_17 ;
struct V_57 * V_82 ;
V_82 = F_45 ( & V_38 -> V_42 -> V_3 , V_58 ) ;
while ( V_17 < ( T_3 ) V_69 &&
( V_82 == NULL || V_17 < V_82 -> V_17 ) ) {
if ( V_80 ) {
if ( V_75 == NULL )
V_75 = V_80 [ V_17 ] . V_75 ;
V_77 += V_80 [ V_17 ] . V_77 ;
} else
V_76 += V_48 -> V_12 [ V_17 ] ;
++ V_17 ;
}
if ( V_80 == NULL && V_48 -> V_55 )
V_77 = 100.0 * V_76 / V_48 -> V_55 ;
if ( V_77 < V_70 )
return - 1 ;
if ( V_71 && V_27 >= V_71 )
return 1 ;
if ( V_72 != NULL ) {
F_48 (queue, &notes->src->source, node) {
if ( V_72 == V_58 )
break;
F_47 ( V_72 , V_36 , V_52 , V_47 , V_69 ,
0 , 0 , 1 , NULL ) ;
}
}
V_78 = F_49 ( V_77 ) ;
if ( V_75 ) {
if ( ! V_73 || strcmp ( V_73 , V_75 )
|| V_78 != V_74 ) {
F_50 ( stdout , V_78 , L_15 , V_75 ) ;
V_73 = V_75 ;
V_74 = V_78 ;
}
}
F_50 ( stdout , V_78 , L_16 , V_77 ) ;
printf ( L_17 ) ;
F_50 ( stdout , V_83 , L_18 V_14 L_19 , V_12 ) ;
F_50 ( stdout , V_84 , L_20 , V_58 -> line ) ;
} else if ( V_71 && V_27 >= V_71 )
return 1 ;
else {
if ( V_72 )
return - 1 ;
if ( ! * V_58 -> line )
printf ( L_21 ) ;
else
printf ( L_22 , V_58 -> line ) ;
}
return 0 ;
}
static int F_51 ( struct V_35 * V_36 , struct V_34 * V_34 ,
T_4 * V_85 , T_1 V_62 )
{
struct V_37 * V_38 = F_28 ( V_36 ) ;
struct V_57 * V_58 ;
char * line = NULL , * V_86 , * V_60 , * V_87 , * V_88 ;
T_1 V_89 ;
T_3 V_90 , V_17 = - 1 ;
if ( F_52 ( & line , & V_89 , V_85 ) < 0 )
return - 1 ;
if ( ! line )
return - 1 ;
while ( V_89 != 0 && isspace ( line [ V_89 - 1 ] ) )
line [ -- V_89 ] = '\0' ;
V_88 = strchr ( line , '\n' ) ;
if ( V_88 )
* V_88 = 0 ;
V_90 = - 1 ;
V_86 = line ;
V_60 = line ;
while ( * V_60 ) {
if ( * V_60 != ' ' )
break;
V_60 ++ ;
}
if ( * V_60 ) {
V_90 = F_6 ( V_60 , & V_87 , 16 ) ;
if ( * V_87 != ':' || V_60 == V_87 || V_87 [ 1 ] == '\0' )
V_90 = - 1 ;
}
if ( V_90 != - 1 ) {
T_2 V_52 = F_53 ( V_34 , V_36 -> V_52 ) ,
V_53 = F_53 ( V_34 , V_36 -> V_53 ) ;
V_17 = V_90 - V_52 ;
if ( V_17 < 0 || ( T_2 ) V_90 > V_53 )
V_17 = - 1 ;
else
V_86 = V_87 + 1 ;
}
V_58 = F_40 ( V_17 , V_86 , V_62 ) ;
free ( line ) ;
if ( V_58 == NULL )
return - 1 ;
F_43 ( & V_38 -> V_42 -> V_3 , V_58 ) ;
return 0 ;
}
int F_54 ( struct V_35 * V_36 , struct V_34 * V_34 , T_1 V_62 )
{
struct V_91 * V_91 = V_34 -> V_91 ;
char * V_92 = F_55 ( V_91 , NULL , 0 ) ;
bool V_93 = true ;
char V_94 [ V_95 * 2 ] ;
T_4 * V_85 ;
int V_96 = 0 ;
char V_97 [ V_95 ] ;
if ( V_92 ) {
snprintf ( V_97 , sizeof( V_97 ) , L_23 ,
V_43 . V_98 , V_92 ) ;
}
if ( V_92 == NULL ) {
if ( V_91 -> V_99 ) {
F_56 ( L_24 ,
V_36 -> V_5 ) ;
return - V_49 ;
}
goto V_100;
} else if ( F_57 ( V_97 , V_94 , sizeof( V_94 ) ) < 0 ||
strstr ( V_94 , L_25 ) ||
F_58 ( V_97 , V_101 ) ) {
free ( V_92 ) ;
V_100:
V_92 = V_91 -> V_102 ;
snprintf ( V_97 , sizeof( V_97 ) , L_23 ,
V_43 . V_98 , V_92 ) ;
V_93 = false ;
}
if ( V_91 -> V_103 == V_104 ) {
char V_8 [ V_105 * 2 + 16 ] = L_26 ;
char * V_106 = NULL ;
if ( V_91 -> V_107 )
goto V_108;
if ( V_91 -> V_99 ) {
F_59 ( V_91 -> V_109 ,
sizeof( V_91 -> V_109 ) , V_8 + 15 ) ;
V_106 = V_8 ;
}
V_96 = - V_110 ;
V_91 -> V_107 = 1 ;
F_56 ( L_27
L_28
L_29
L_30
L_31
L_32 ,
V_36 -> V_5 , V_106 ? : L_33 ) ;
goto V_108;
}
F_60 ( L_34 V_14 L_35 V_14 L_10 , V_50 ,
V_92 , V_36 -> V_5 , V_34 -> V_51 ( V_34 , V_36 -> V_52 ) ,
V_34 -> V_51 ( V_34 , V_36 -> V_53 ) ) ;
F_60 ( L_36 ,
V_91 , V_91 -> V_102 , V_36 , V_36 -> V_5 ) ;
snprintf ( V_94 , sizeof( V_94 ) ,
L_37 V_14
L_38 V_14
L_39 ,
V_111 ? L_40 : L_33 ,
V_111 ? V_111 : L_33 ,
F_53 ( V_34 , V_36 -> V_52 ) ,
F_53 ( V_34 , V_36 -> V_53 + 1 ) ,
V_43 . V_112 ? L_33 : L_41 ,
V_43 . V_113 ? L_42 : L_33 ,
V_97 , V_92 ) ;
F_60 ( L_43 , V_94 ) ;
V_85 = F_61 ( V_94 , L_44 ) ;
if ( ! V_85 )
goto V_108;
while ( ! feof ( V_85 ) )
if ( F_51 ( V_36 , V_34 , V_85 , V_62 ) < 0 )
break;
F_62 ( V_85 ) ;
V_108:
if ( V_93 )
free ( V_92 ) ;
return V_96 ;
}
static void F_63 ( struct V_114 * V_115 , struct V_79 * V_80 )
{
struct V_79 * V_116 ;
struct V_117 * * V_118 = & V_115 -> V_117 ;
struct V_117 * V_119 = NULL ;
while ( * V_118 != NULL ) {
V_119 = * V_118 ;
V_116 = F_64 ( V_119 , struct V_79 , V_67 ) ;
if ( V_80 -> V_77 > V_116 -> V_77 )
V_118 = & ( * V_118 ) -> V_120 ;
else
V_118 = & ( * V_118 ) -> V_121 ;
}
F_65 ( & V_80 -> V_67 , V_119 , V_118 ) ;
F_66 ( & V_80 -> V_67 , V_115 ) ;
}
static void F_67 ( struct V_35 * V_36 , int V_69 )
{
struct V_37 * V_38 = F_28 ( V_36 ) ;
struct V_79 * V_80 = V_38 -> V_42 -> V_81 ;
int V_122 ;
for ( V_122 = 0 ; V_122 < V_69 ; V_122 ++ )
free ( V_80 [ V_122 ] . V_75 ) ;
free ( V_80 ) ;
V_38 -> V_42 -> V_81 = NULL ;
}
static int F_68 ( struct V_35 * V_36 , struct V_34 * V_34 ,
int V_47 , struct V_114 * V_115 , int V_69 ,
const char * V_92 )
{
T_2 V_52 ;
int V_122 ;
char V_123 [ V_95 * 2 ] ;
struct V_79 * V_80 ;
struct V_37 * V_38 = F_28 ( V_36 ) ;
struct V_41 * V_48 = F_38 ( V_38 , V_47 ) ;
if ( ! V_48 -> V_55 )
return 0 ;
V_80 = V_38 -> V_42 -> V_81 = calloc ( V_69 , sizeof( struct V_79 ) ) ;
if ( ! V_38 -> V_42 -> V_81 )
return - 1 ;
V_52 = F_53 ( V_34 , V_36 -> V_52 ) ;
for ( V_122 = 0 ; V_122 < V_69 ; V_122 ++ ) {
char * V_75 = NULL ;
T_1 V_89 ;
T_2 V_17 ;
T_4 * V_124 ;
V_80 [ V_122 ] . V_77 = 100.0 * V_48 -> V_12 [ V_122 ] / V_48 -> V_55 ;
if ( V_80 [ V_122 ] . V_77 <= 0.5 )
continue;
V_17 = V_52 + V_122 ;
sprintf ( V_123 , L_45 V_14 , V_92 , V_17 ) ;
V_124 = F_61 ( V_123 , L_44 ) ;
if ( ! V_124 )
continue;
if ( F_52 ( & V_75 , & V_89 , V_124 ) < 0 || ! V_89 )
goto V_82;
V_80 [ V_122 ] . V_75 = malloc ( sizeof( char ) * V_89 + 1 ) ;
if ( ! V_80 [ V_122 ] . V_75 )
goto V_82;
strcpy ( V_80 [ V_122 ] . V_75 , V_75 ) ;
F_63 ( V_115 , & V_80 [ V_122 ] ) ;
V_82:
F_62 ( V_124 ) ;
}
return 0 ;
}
static void F_69 ( struct V_114 * V_115 , const char * V_92 )
{
struct V_79 * V_80 ;
struct V_117 * V_67 ;
printf ( L_46 , V_92 ) ;
printf ( L_47 ) ;
if ( F_70 ( V_115 ) ) {
printf ( L_48 , V_125 ) ;
return;
}
V_67 = F_71 ( V_115 ) ;
while ( V_67 ) {
double V_77 ;
const char * V_78 ;
char * V_75 ;
V_80 = F_64 ( V_67 , struct V_79 , V_67 ) ;
V_77 = V_80 -> V_77 ;
V_78 = F_49 ( V_77 ) ;
V_75 = V_80 -> V_75 ;
F_50 ( stdout , V_78 , L_49 , V_77 , V_75 ) ;
V_67 = F_72 ( V_67 ) ;
}
}
static void F_73 ( struct V_35 * V_36 , int V_47 )
{
struct V_37 * V_38 = F_28 ( V_36 ) ;
struct V_41 * V_48 = F_38 ( V_38 , V_47 ) ;
T_2 V_69 = F_31 ( V_36 ) , V_17 ;
for ( V_17 = 0 ; V_17 < V_69 ; ++ V_17 )
if ( V_48 -> V_12 [ V_17 ] != 0 )
printf ( L_50 V_14 L_51 V_56 L_10 , V_126 / 2 ,
V_36 -> V_52 + V_17 , V_48 -> V_12 [ V_17 ] ) ;
printf ( L_52 V_56 L_10 , V_126 / 2 , L_53 , V_48 -> V_55 ) ;
}
int F_74 ( struct V_35 * V_36 , struct V_34 * V_34 , int V_47 ,
bool V_127 , int V_70 , int V_71 ,
int V_128 )
{
struct V_91 * V_91 = V_34 -> V_91 ;
const char * V_92 = V_91 -> V_102 , * V_129 ;
struct V_37 * V_38 = F_28 ( V_36 ) ;
struct V_57 * V_68 , * V_72 = NULL ;
T_2 V_52 = F_53 ( V_34 , V_36 -> V_52 ) ;
int V_27 = 2 , V_130 = 0 ;
int V_131 = 0 ;
T_2 V_69 ;
if ( V_127 )
V_129 = V_92 ;
else
V_129 = F_75 ( V_92 ) ;
V_69 = F_31 ( V_36 ) ;
printf ( L_54 , V_129 ) ;
printf ( L_55 ) ;
if ( V_132 )
F_73 ( V_36 , V_47 ) ;
F_76 (pos, &notes->src->source, node) {
if ( V_128 && V_72 == NULL ) {
V_72 = V_68 ;
V_130 = 0 ;
}
switch ( F_47 ( V_68 , V_36 , V_52 , V_47 , V_69 ,
V_70 , V_27 , V_71 ,
V_72 ) ) {
case 0 :
++ V_27 ;
if ( V_128 ) {
V_27 += V_130 ;
V_72 = NULL ;
V_130 = 0 ;
}
break;
case 1 :
++ V_131 ;
break;
case - 1 :
default:
if ( ! V_128 )
break;
if ( V_130 == V_128 )
V_72 = F_77 ( V_72 -> V_67 . V_82 , F_78 ( * V_72 ) , V_67 ) ;
else
++ V_130 ;
break;
}
}
return V_131 ;
}
void F_79 ( struct V_35 * V_36 , int V_47 )
{
struct V_37 * V_38 = F_28 ( V_36 ) ;
struct V_41 * V_48 = F_38 ( V_38 , V_47 ) ;
memset ( V_48 , 0 , V_38 -> V_42 -> V_40 ) ;
}
void F_80 ( struct V_35 * V_36 , int V_47 )
{
struct V_37 * V_38 = F_28 ( V_36 ) ;
struct V_41 * V_48 = F_38 ( V_38 , V_47 ) ;
int V_69 = F_31 ( V_36 ) , V_17 ;
V_48 -> V_55 = 0 ;
for ( V_17 = 0 ; V_17 < V_69 ; ++ V_17 ) {
V_48 -> V_12 [ V_17 ] = V_48 -> V_12 [ V_17 ] * 7 / 8 ;
V_48 -> V_55 += V_48 -> V_12 [ V_17 ] ;
}
}
void F_81 ( struct V_65 * V_66 )
{
struct V_57 * V_68 , * V_133 ;
F_82 (pos, n, head, node) {
F_83 ( & V_68 -> V_67 ) ;
F_41 ( V_68 ) ;
}
}
static T_1 F_84 ( struct V_57 * V_58 , T_4 * V_124 )
{
T_1 V_27 ;
if ( V_58 -> V_17 == - 1 )
return fprintf ( V_124 , L_20 , V_58 -> line ) ;
V_27 = fprintf ( V_124 , L_11 V_14 L_15 , V_58 -> V_17 , V_58 -> V_5 ) ;
if ( V_58 -> V_2 . V_4 [ 0 ] != '\0' ) {
V_27 += fprintf ( V_124 , L_56 , 6 - ( int ) V_27 , L_57 ,
V_58 -> V_2 . V_4 ) ;
}
return V_27 + fprintf ( V_124 , L_10 ) ;
}
T_1 F_85 ( struct V_65 * V_66 , T_4 * V_124 )
{
struct V_57 * V_68 ;
T_1 V_27 = 0 ;
F_76 (pos, head, node)
V_27 += F_84 ( V_68 , V_124 ) ;
return V_27 ;
}
int F_86 ( struct V_35 * V_36 , struct V_34 * V_34 , int V_47 ,
bool V_134 , bool V_127 , int V_70 ,
int V_71 )
{
struct V_91 * V_91 = V_34 -> V_91 ;
const char * V_92 = V_91 -> V_102 ;
struct V_114 V_79 = V_135 ;
T_2 V_69 ;
if ( F_54 ( V_36 , V_34 , 0 ) < 0 )
return - 1 ;
V_69 = F_31 ( V_36 ) ;
if ( V_134 ) {
F_68 ( V_36 , V_34 , V_47 , & V_79 ,
V_69 , V_92 ) ;
F_69 ( & V_79 , V_92 ) ;
}
F_74 ( V_36 , V_34 , V_47 , V_127 ,
V_70 , V_71 , 0 ) ;
if ( V_134 )
F_67 ( V_36 , V_69 ) ;
F_81 ( & F_28 ( V_36 ) -> V_42 -> V_3 ) ;
return 0 ;
}
