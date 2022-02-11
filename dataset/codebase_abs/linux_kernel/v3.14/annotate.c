static void F_1 ( struct V_1 * V_2 )
{
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
if ( V_2 -> V_24 . V_7 == NULL )
goto V_25;
if ( ! V_2 -> V_24 . V_7 -> V_2 )
return 0 ;
if ( V_2 -> V_24 . V_7 -> V_2 -> V_26 )
V_2 -> V_24 . V_7 -> V_2 -> V_26 ( V_2 -> V_24 . V_2 ) ;
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
while ( V_16 [ 0 ] != '\0' && ! isspace ( V_16 [ 0 ] ) )
++ V_16 ;
V_28 = * V_16 ;
* V_16 = '\0' ;
V_2 -> V_6 . V_4 = F_8 ( V_6 ) ;
* V_16 = V_28 ;
if ( V_2 -> V_6 . V_4 == NULL )
goto V_29;
V_20 = strchr ( V_16 , '#' ) ;
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
if ( V_12 < V_36 -> V_52 || V_12 > V_36 -> V_53 )
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
if ( V_66 -> V_7 -> V_2 -> V_26 )
V_66 -> V_7 -> V_2 -> V_26 ( & V_66 -> V_2 ) ;
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
static struct V_65 * F_44 ( T_3 V_17 , char * line , T_1 V_70 )
{
struct V_65 * V_66 = F_16 ( sizeof( * V_66 ) + V_70 ) ;
if ( V_66 != NULL ) {
V_66 -> V_17 = V_17 ;
V_66 -> line = F_8 ( line ) ;
if ( V_66 -> line == NULL )
goto V_71;
if ( V_17 != - 1 ) {
if ( F_17 ( V_66 -> line , & V_66 -> V_5 , & V_66 -> V_2 . V_4 ) < 0 )
goto V_72;
F_43 ( V_66 ) ;
}
}
return V_66 ;
V_72:
F_2 ( & V_66 -> line ) ;
V_71:
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
static void F_47 ( struct V_73 * V_74 , struct V_65 * line )
{
F_48 ( & line -> V_75 , V_74 ) ;
}
struct V_65 * F_49 ( struct V_73 * V_74 , struct V_65 * V_76 )
{
F_50 (pos, head, node)
if ( V_76 -> V_17 >= 0 )
return V_76 ;
return NULL ;
}
double F_51 ( struct V_37 * V_38 , int V_48 , T_3 V_17 ,
T_3 V_53 , const char * * V_77 )
{
struct V_78 * V_79 = V_38 -> V_43 -> V_80 ;
double V_81 = 0.0 ;
if ( V_79 ) {
T_1 V_82 = sizeof( * V_79 ) +
sizeof( V_79 -> V_83 ) * ( V_79 -> V_84 - 1 ) ;
while ( V_17 < V_53 ) {
V_79 = ( void * ) V_38 -> V_43 -> V_80 +
( V_82 * V_17 ) ;
if ( * V_77 == NULL )
* V_77 = V_79 -> V_77 ;
V_81 += V_79 -> V_83 [ V_48 ] . V_81 ;
V_17 ++ ;
}
} else {
struct V_42 * V_49 = F_39 ( V_38 , V_48 ) ;
unsigned int V_85 = 0 ;
while ( V_17 < V_53 )
V_85 += V_49 -> V_12 [ V_17 ++ ] ;
if ( V_49 -> V_55 )
V_81 = 100.0 * V_85 / V_49 -> V_55 ;
}
return V_81 ;
}
static int F_52 ( struct V_65 * V_66 , struct V_35 * V_36 , T_2 V_52 ,
struct V_86 * V_87 , T_2 V_88 , int V_89 , int V_27 ,
int V_90 , struct V_65 * V_91 )
{
static const char * V_92 ;
static const char * V_93 ;
if ( V_66 -> V_17 != - 1 ) {
const char * V_77 = NULL ;
double V_81 , V_94 = 0.0 ;
double * V_95 = & V_81 ;
int V_96 , V_97 = 1 ;
const char * V_98 ;
struct V_37 * V_38 = F_29 ( V_36 ) ;
T_3 V_17 = V_66 -> V_17 ;
const T_2 V_12 = V_52 + V_17 ;
struct V_65 * V_99 ;
V_99 = F_49 ( & V_38 -> V_43 -> V_3 , V_66 ) ;
if ( F_53 ( V_87 ) ) {
V_97 = V_87 -> V_100 ;
V_95 = calloc ( V_97 , sizeof( double ) ) ;
if ( V_95 == NULL )
return - 1 ;
}
for ( V_96 = 0 ; V_96 < V_97 ; V_96 ++ ) {
V_81 = F_51 ( V_38 ,
V_38 -> V_43 -> V_80 ? V_96 : V_87 -> V_101 + V_96 ,
V_17 ,
V_99 ? V_99 -> V_17 : ( T_3 ) V_88 ,
& V_77 ) ;
V_95 [ V_96 ] = V_81 ;
if ( V_81 > V_94 )
V_94 = V_81 ;
}
if ( V_94 < V_89 )
return - 1 ;
if ( V_90 && V_27 >= V_90 )
return 1 ;
if ( V_91 != NULL ) {
F_54 (queue, &notes->src->source, node) {
if ( V_91 == V_66 )
break;
F_52 ( V_91 , V_36 , V_52 , V_87 , V_88 ,
0 , 0 , 1 , NULL ) ;
}
}
V_98 = F_55 ( V_94 ) ;
if ( V_77 ) {
if ( ! V_92 || strcmp ( V_92 , V_77 )
|| V_98 != V_93 ) {
F_56 ( stdout , V_98 , L_15 , V_77 ) ;
V_92 = V_77 ;
V_93 = V_98 ;
}
}
for ( V_96 = 0 ; V_96 < V_97 ; V_96 ++ ) {
V_81 = V_95 [ V_96 ] ;
V_98 = F_55 ( V_81 ) ;
F_56 ( stdout , V_98 , L_16 , V_81 ) ;
}
printf ( L_17 ) ;
F_56 ( stdout , V_102 , L_18 V_14 L_19 , V_12 ) ;
F_56 ( stdout , V_103 , L_20 , V_66 -> line ) ;
if ( V_95 != & V_81 )
free ( V_95 ) ;
} else if ( V_90 && V_27 >= V_90 )
return 1 ;
else {
int V_104 = 8 ;
if ( V_91 )
return - 1 ;
if ( F_53 ( V_87 ) )
V_104 *= V_87 -> V_100 ;
if ( ! * V_66 -> line )
printf ( L_21 , V_104 , L_22 ) ;
else
printf ( L_23 , V_104 , L_22 , V_66 -> line ) ;
}
return 0 ;
}
static int F_57 ( struct V_35 * V_36 , struct V_34 * V_34 ,
T_4 * V_105 , T_1 V_70 )
{
struct V_37 * V_38 = F_29 ( V_36 ) ;
struct V_65 * V_66 ;
char * line = NULL , * V_106 , * V_68 , * V_107 , * V_108 ;
T_1 V_109 ;
T_3 V_110 , V_17 = - 1 ;
if ( F_58 ( & line , & V_109 , V_105 ) < 0 )
return - 1 ;
if ( ! line )
return - 1 ;
while ( V_109 != 0 && isspace ( line [ V_109 - 1 ] ) )
line [ -- V_109 ] = '\0' ;
V_108 = strchr ( line , '\n' ) ;
if ( V_108 )
* V_108 = 0 ;
V_110 = - 1 ;
V_106 = line ;
V_68 = line ;
while ( * V_68 ) {
if ( * V_68 != ' ' )
break;
V_68 ++ ;
}
if ( * V_68 ) {
V_110 = F_7 ( V_68 , & V_107 , 16 ) ;
if ( * V_107 != ':' || V_68 == V_107 || V_107 [ 1 ] == '\0' )
V_110 = - 1 ;
}
if ( V_110 != - 1 ) {
T_2 V_52 = F_59 ( V_34 , V_36 -> V_52 ) ,
V_53 = F_59 ( V_34 , V_36 -> V_53 ) ;
V_17 = V_110 - V_52 ;
if ( ( T_2 ) V_110 < V_52 || ( T_2 ) V_110 > V_53 )
V_17 = - 1 ;
else
V_106 = V_107 + 1 ;
}
V_66 = F_44 ( V_17 , V_106 , V_70 ) ;
free ( line ) ;
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
static void F_61 ( struct V_35 * V_36 )
{
struct V_37 * V_38 = F_29 ( V_36 ) ;
struct V_73 * V_111 = & V_38 -> V_43 -> V_3 ;
struct V_65 * V_66 ;
while ( ! F_62 ( V_111 ) ) {
V_66 = F_63 ( V_111 -> V_28 , struct V_65 , V_75 ) ;
if ( V_66 -> V_7 && V_66 -> V_7 -> V_2 ) {
if ( V_66 -> V_7 -> V_2 != & V_112 )
return;
} else {
if ( ! strstr ( V_66 -> line , L_24 ) &&
! strstr ( V_66 -> line , L_25 ) &&
! strstr ( V_66 -> line , L_26 ) )
return;
}
F_64 ( & V_66 -> V_75 ) ;
F_45 ( V_66 ) ;
}
}
int F_65 ( struct V_35 * V_36 , struct V_34 * V_34 , T_1 V_70 )
{
struct V_113 * V_113 = V_34 -> V_113 ;
char * V_114 = F_66 ( V_113 , NULL , 0 ) ;
bool V_115 = true ;
char V_116 [ V_117 * 2 ] ;
T_4 * V_105 ;
int V_118 = 0 ;
char V_119 [ V_117 ] ;
struct V_120 V_121 ;
bool V_122 = false ;
if ( V_114 ) {
snprintf ( V_119 , sizeof( V_119 ) , L_27 ,
V_44 . V_123 , V_114 ) ;
}
if ( V_114 == NULL ) {
if ( V_113 -> V_124 ) {
F_67 ( L_28 ,
V_36 -> V_5 ) ;
return - V_57 ;
}
goto V_125;
} else if ( F_68 ( V_119 , V_116 , sizeof( V_116 ) ) < 0 ||
strstr ( V_116 , L_29 ) ||
F_69 ( V_119 , V_126 ) ) {
free ( V_114 ) ;
V_125:
V_114 = ( char * ) V_113 -> V_127 ;
snprintf ( V_119 , sizeof( V_119 ) , L_27 ,
V_44 . V_123 , V_114 ) ;
V_115 = false ;
}
if ( V_113 -> V_128 == V_129 &&
! F_70 ( V_113 ) ) {
char V_8 [ V_130 * 2 + 16 ] = L_30 ;
char * V_131 = NULL ;
if ( V_113 -> V_132 )
goto V_133;
if ( V_113 -> V_124 ) {
F_71 ( V_113 -> V_134 ,
sizeof( V_113 -> V_134 ) , V_8 + 15 ) ;
V_131 = V_8 ;
}
V_118 = - V_135 ;
V_113 -> V_132 = 1 ;
F_67 ( L_31
L_32
L_33
L_34
L_35
L_36 ,
V_36 -> V_5 , V_131 ? : L_37 ) ;
goto V_133;
}
F_72 ( L_38 V_14 L_39 V_14 L_10 , V_50 ,
V_114 , V_36 -> V_5 , V_34 -> V_51 ( V_34 , V_36 -> V_52 ) ,
V_34 -> V_51 ( V_34 , V_36 -> V_53 ) ) ;
F_72 ( L_40 ,
V_113 , V_113 -> V_127 , V_36 , V_36 -> V_5 ) ;
if ( F_70 ( V_113 ) ) {
V_121 . V_136 = V_119 ;
V_121 . V_12 = F_59 ( V_34 , V_36 -> V_52 ) ;
V_121 . V_137 = V_36 -> V_52 ;
V_121 . V_88 = V_36 -> V_53 + 1 - V_36 -> V_52 ;
if ( ! F_73 ( & V_121 ) ) {
V_122 = true ;
F_74 ( V_119 , V_121 . V_138 ,
sizeof( V_119 ) ) ;
if ( V_115 ) {
free ( V_114 ) ;
V_115 = false ;
}
V_114 = V_119 ;
}
}
snprintf ( V_116 , sizeof( V_116 ) ,
L_41 V_14
L_42 V_14
L_43 ,
V_139 ? V_139 : L_44 ,
V_140 ? L_45 : L_37 ,
V_140 ? V_140 : L_37 ,
F_59 ( V_34 , V_36 -> V_52 ) ,
F_59 ( V_34 , V_36 -> V_53 + 1 ) ,
V_44 . V_141 ? L_37 : L_46 ,
V_44 . V_142 ? L_47 : L_37 ,
V_119 , V_114 ) ;
F_72 ( L_48 , V_116 ) ;
V_105 = F_75 ( V_116 , L_49 ) ;
if ( ! V_105 )
goto V_133;
while ( ! feof ( V_105 ) )
if ( F_57 ( V_36 , V_34 , V_105 , V_70 ) < 0 )
break;
if ( F_70 ( V_113 ) )
F_61 ( V_36 ) ;
F_76 ( V_105 ) ;
V_133:
if ( V_122 )
F_77 ( & V_121 ) ;
if ( V_115 )
free ( V_114 ) ;
return V_118 ;
}
static void F_78 ( struct V_143 * V_144 , struct V_78 * V_79 )
{
struct V_78 * V_145 ;
struct V_146 * * V_83 = & V_144 -> V_146 ;
struct V_146 * V_147 = NULL ;
int V_96 , V_148 ;
while ( * V_83 != NULL ) {
V_147 = * V_83 ;
V_145 = F_79 ( V_147 , struct V_78 , V_75 ) ;
V_148 = strcmp ( V_145 -> V_77 , V_79 -> V_77 ) ;
if ( V_148 == 0 ) {
for ( V_96 = 0 ; V_96 < V_79 -> V_84 ; V_96 ++ )
V_145 -> V_83 [ V_96 ] . V_149 += V_79 -> V_83 [ V_96 ] . V_81 ;
return;
}
if ( V_148 < 0 )
V_83 = & ( * V_83 ) -> V_150 ;
else
V_83 = & ( * V_83 ) -> V_151 ;
}
for ( V_96 = 0 ; V_96 < V_79 -> V_84 ; V_96 ++ )
V_79 -> V_83 [ V_96 ] . V_149 = V_79 -> V_83 [ V_96 ] . V_81 ;
F_80 ( & V_79 -> V_75 , V_147 , V_83 ) ;
F_81 ( & V_79 -> V_75 , V_144 ) ;
}
static int F_82 ( struct V_78 * V_152 , struct V_78 * V_153 )
{
int V_96 ;
for ( V_96 = 0 ; V_96 < V_152 -> V_84 ; V_96 ++ ) {
if ( V_152 -> V_83 [ V_96 ] . V_149 == V_153 -> V_83 [ V_96 ] . V_149 )
continue;
return V_152 -> V_83 [ V_96 ] . V_149 > V_153 -> V_83 [ V_96 ] . V_149 ;
}
return 0 ;
}
static void F_83 ( struct V_143 * V_144 , struct V_78 * V_79 )
{
struct V_78 * V_145 ;
struct V_146 * * V_83 = & V_144 -> V_146 ;
struct V_146 * V_147 = NULL ;
while ( * V_83 != NULL ) {
V_147 = * V_83 ;
V_145 = F_79 ( V_147 , struct V_78 , V_75 ) ;
if ( F_82 ( V_79 , V_145 ) )
V_83 = & ( * V_83 ) -> V_150 ;
else
V_83 = & ( * V_83 ) -> V_151 ;
}
F_80 ( & V_79 -> V_75 , V_147 , V_83 ) ;
F_81 ( & V_79 -> V_75 , V_144 ) ;
}
static void F_84 ( struct V_143 * V_154 , struct V_143 * V_155 )
{
struct V_78 * V_79 ;
struct V_146 * V_75 ;
V_75 = F_85 ( V_155 ) ;
while ( V_75 ) {
struct V_146 * V_99 ;
V_79 = F_79 ( V_75 , struct V_78 , V_75 ) ;
V_99 = F_86 ( V_75 ) ;
F_87 ( V_75 , V_155 ) ;
F_83 ( V_154 , V_79 ) ;
V_75 = V_99 ;
}
}
static void F_88 ( struct V_35 * V_36 , int V_88 )
{
struct V_37 * V_38 = F_29 ( V_36 ) ;
struct V_78 * V_79 = V_38 -> V_43 -> V_80 ;
T_1 V_82 ;
int V_96 ;
V_82 = sizeof( * V_79 ) +
( sizeof( V_79 -> V_83 ) * ( V_79 -> V_84 - 1 ) ) ;
for ( V_96 = 0 ; V_96 < V_88 ; V_96 ++ ) {
F_89 ( V_79 -> V_77 ) ;
V_79 = ( void * ) V_79 + V_82 ;
}
F_2 ( & V_38 -> V_43 -> V_80 ) ;
}
static int F_90 ( struct V_35 * V_36 , struct V_34 * V_34 ,
struct V_86 * V_87 ,
struct V_143 * V_144 , int V_88 )
{
T_2 V_52 ;
int V_96 , V_156 ;
int V_48 = V_87 -> V_101 ;
struct V_78 * V_79 ;
struct V_37 * V_38 = F_29 ( V_36 ) ;
struct V_42 * V_49 = F_39 ( V_38 , V_48 ) ;
struct V_143 V_157 = V_158 ;
int V_84 = 1 ;
T_2 V_159 = V_49 -> V_55 ;
T_1 V_82 = sizeof( struct V_78 ) ;
if ( F_53 ( V_87 ) ) {
for ( V_96 = 1 ; V_96 < V_87 -> V_100 ; V_96 ++ ) {
V_49 = F_39 ( V_38 , V_48 + V_96 ) ;
V_159 += V_49 -> V_55 ;
}
V_84 = V_87 -> V_100 ;
V_82 += ( V_84 - 1 ) * sizeof( V_79 -> V_83 ) ;
}
if ( ! V_159 )
return 0 ;
V_79 = V_38 -> V_43 -> V_80 = calloc ( V_88 , V_82 ) ;
if ( ! V_38 -> V_43 -> V_80 )
return - 1 ;
V_52 = F_59 ( V_34 , V_36 -> V_52 ) ;
for ( V_96 = 0 ; V_96 < V_88 ; V_96 ++ ) {
T_2 V_17 ;
double V_160 = 0.0 ;
V_79 -> V_84 = V_84 ;
for ( V_156 = 0 ; V_156 < V_84 ; V_156 ++ ) {
V_49 = F_39 ( V_38 , V_48 + V_156 ) ;
V_79 -> V_83 [ V_156 ] . V_81 = 100.0 * V_49 -> V_12 [ V_96 ] / V_49 -> V_55 ;
if ( V_79 -> V_83 [ V_156 ] . V_81 > V_160 )
V_160 = V_79 -> V_83 [ V_156 ] . V_81 ;
}
if ( V_160 <= 0.5 )
goto V_99;
V_17 = V_52 + V_96 ;
V_79 -> V_77 = F_91 ( V_34 -> V_113 , V_17 ) ;
F_78 ( & V_157 , V_79 ) ;
V_99:
V_79 = ( void * ) V_79 + V_82 ;
}
F_84 ( V_144 , & V_157 ) ;
return 0 ;
}
static void F_92 ( struct V_143 * V_144 , const char * V_114 )
{
struct V_78 * V_79 ;
struct V_146 * V_75 ;
printf ( L_50 , V_114 ) ;
printf ( L_51 ) ;
if ( F_93 ( V_144 ) ) {
printf ( L_52 , V_161 ) ;
return;
}
V_75 = F_85 ( V_144 ) ;
while ( V_75 ) {
double V_81 , V_160 = 0.0 ;
const char * V_98 ;
char * V_77 ;
int V_96 ;
V_79 = F_79 ( V_75 , struct V_78 , V_75 ) ;
for ( V_96 = 0 ; V_96 < V_79 -> V_84 ; V_96 ++ ) {
V_81 = V_79 -> V_83 [ V_96 ] . V_149 ;
V_98 = F_55 ( V_81 ) ;
F_56 ( stdout , V_98 , L_16 , V_81 ) ;
if ( V_81 > V_160 )
V_160 = V_81 ;
}
V_77 = V_79 -> V_77 ;
V_98 = F_55 ( V_160 ) ;
F_56 ( stdout , V_98 , L_53 , V_77 ) ;
V_75 = F_86 ( V_75 ) ;
}
}
static void F_94 ( struct V_35 * V_36 , struct V_86 * V_87 )
{
struct V_37 * V_38 = F_29 ( V_36 ) ;
struct V_42 * V_49 = F_39 ( V_38 , V_87 -> V_101 ) ;
T_2 V_88 = F_32 ( V_36 ) , V_17 ;
for ( V_17 = 0 ; V_17 < V_88 ; ++ V_17 )
if ( V_49 -> V_12 [ V_17 ] != 0 )
printf ( L_54 V_14 L_55 V_56 L_10 , V_162 / 2 ,
V_36 -> V_52 + V_17 , V_49 -> V_12 [ V_17 ] ) ;
printf ( L_56 V_56 L_10 , V_162 / 2 , L_57 , V_49 -> V_55 ) ;
}
int F_95 ( struct V_35 * V_36 , struct V_34 * V_34 ,
struct V_86 * V_87 , bool V_163 ,
int V_89 , int V_90 , int V_164 )
{
struct V_113 * V_113 = V_34 -> V_113 ;
char * V_114 ;
const char * V_165 ;
struct V_37 * V_38 = F_29 ( V_36 ) ;
struct V_65 * V_76 , * V_91 = NULL ;
T_2 V_52 = F_59 ( V_34 , V_36 -> V_52 ) ;
int V_27 = 2 , V_166 = 0 ;
int V_167 = 0 ;
T_2 V_88 ;
int V_104 = 8 ;
int V_168 ;
V_114 = F_8 ( V_113 -> V_127 ) ;
if ( ! V_114 )
return - V_57 ;
if ( V_163 )
V_165 = V_114 ;
else
V_165 = F_96 ( V_114 ) ;
V_88 = F_32 ( V_36 ) ;
V_168 = strlen ( V_165 ) ;
if ( F_53 ( V_87 ) )
V_104 *= V_87 -> V_100 ;
printf ( L_58 ,
V_104 , V_104 , L_59 , V_165 ) ;
printf ( L_60 ,
V_104 + V_168 , V_104 + V_168 , V_169 ) ;
if ( V_170 )
F_94 ( V_36 , V_87 ) ;
F_97 (pos, &notes->src->source, node) {
if ( V_164 && V_91 == NULL ) {
V_91 = V_76 ;
V_166 = 0 ;
}
switch ( F_52 ( V_76 , V_36 , V_52 , V_87 , V_88 ,
V_89 , V_27 , V_90 ,
V_91 ) ) {
case 0 :
++ V_27 ;
if ( V_164 ) {
V_27 += V_166 ;
V_91 = NULL ;
V_166 = 0 ;
}
break;
case 1 :
++ V_167 ;
break;
case - 1 :
default:
if ( ! V_164 )
break;
if ( V_166 == V_164 )
V_91 = F_63 ( V_91 -> V_75 . V_99 , F_98 ( * V_91 ) , V_75 ) ;
else
++ V_166 ;
break;
}
}
free ( V_114 ) ;
return V_167 ;
}
void F_99 ( struct V_35 * V_36 , int V_48 )
{
struct V_37 * V_38 = F_29 ( V_36 ) ;
struct V_42 * V_49 = F_39 ( V_38 , V_48 ) ;
memset ( V_49 , 0 , V_38 -> V_43 -> V_40 ) ;
}
void F_100 ( struct V_35 * V_36 , int V_48 )
{
struct V_37 * V_38 = F_29 ( V_36 ) ;
struct V_42 * V_49 = F_39 ( V_38 , V_48 ) ;
int V_88 = F_32 ( V_36 ) , V_17 ;
V_49 -> V_55 = 0 ;
for ( V_17 = 0 ; V_17 < V_88 ; ++ V_17 ) {
V_49 -> V_12 [ V_17 ] = V_49 -> V_12 [ V_17 ] * 7 / 8 ;
V_49 -> V_55 += V_49 -> V_12 [ V_17 ] ;
}
}
void F_101 ( struct V_73 * V_74 )
{
struct V_65 * V_76 , * V_171 ;
F_102 (pos, n, head, node) {
F_64 ( & V_76 -> V_75 ) ;
F_45 ( V_76 ) ;
}
}
static T_1 F_103 ( struct V_65 * V_66 , T_4 * V_172 )
{
T_1 V_27 ;
if ( V_66 -> V_17 == - 1 )
return fprintf ( V_172 , L_20 , V_66 -> line ) ;
V_27 = fprintf ( V_172 , L_11 V_14 L_15 , V_66 -> V_17 , V_66 -> V_5 ) ;
if ( V_66 -> V_2 . V_4 [ 0 ] != '\0' ) {
V_27 += fprintf ( V_172 , L_61 , 6 - ( int ) V_27 , L_22 ,
V_66 -> V_2 . V_4 ) ;
}
return V_27 + fprintf ( V_172 , L_10 ) ;
}
T_1 F_104 ( struct V_73 * V_74 , T_4 * V_172 )
{
struct V_65 * V_76 ;
T_1 V_27 = 0 ;
F_97 (pos, head, node)
V_27 += F_103 ( V_76 , V_172 ) ;
return V_27 ;
}
int F_105 ( struct V_35 * V_36 , struct V_34 * V_34 ,
struct V_86 * V_87 , bool V_173 ,
bool V_163 , int V_89 , int V_90 )
{
struct V_113 * V_113 = V_34 -> V_113 ;
struct V_143 V_78 = V_158 ;
T_2 V_88 ;
if ( F_65 ( V_36 , V_34 , 0 ) < 0 )
return - 1 ;
V_88 = F_32 ( V_36 ) ;
if ( V_173 ) {
F_90 ( V_36 , V_34 , V_87 , & V_78 , V_88 ) ;
F_92 ( & V_78 , V_113 -> V_127 ) ;
}
F_95 ( V_36 , V_34 , V_87 , V_163 ,
V_89 , V_90 , 0 ) ;
if ( V_173 )
F_88 ( V_36 , V_88 ) ;
F_101 ( & F_29 ( V_36 ) -> V_43 -> V_3 ) ;
return 0 ;
}
int F_106 ( struct V_61 * V_62 , T_1 V_70 )
{
return F_65 ( V_62 -> V_64 . V_36 , V_62 -> V_64 . V_34 , V_70 ) ;
}
bool F_107 ( void )
{
return V_174 == 1 && V_175 ;
}
