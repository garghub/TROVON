static void * F_1 ( unsigned int V_1 )
{
struct V_2 * V_3 ;
V_3 = F_2 ( sizeof( * V_3 ) + V_1 , V_4 ) ;
if ( ! V_3 )
return NULL ;
F_3 ( & V_3 -> V_5 , & V_6 ) ;
return V_3 -> V_7 ;
}
static void F_4 ( void * V_8 )
{
struct V_2 * V_3 ;
F_5 (p, &kmalloced_params, list) {
if ( V_3 -> V_7 == V_8 ) {
F_6 ( & V_3 -> V_5 ) ;
F_7 ( V_3 ) ;
break;
}
}
}
static char F_8 ( char V_9 )
{
if ( V_9 == '-' )
return '_' ;
return V_9 ;
}
bool F_9 ( const char * V_10 , const char * V_11 , T_1 V_12 )
{
T_1 V_13 ;
for ( V_13 = 0 ; V_13 < V_12 ; V_13 ++ ) {
if ( F_8 ( V_10 [ V_13 ] ) != F_8 ( V_11 [ V_13 ] ) )
return false ;
}
return true ;
}
bool F_10 ( const char * V_10 , const char * V_11 )
{
return F_9 ( V_10 , V_11 , strlen ( V_10 ) + 1 ) ;
}
static int F_11 ( char * V_8 ,
char * V_7 ,
const struct V_14 * V_15 ,
unsigned V_16 ,
int (* F_12)( char * V_8 , char * V_7 ) )
{
unsigned int V_13 ;
int V_17 ;
for ( V_13 = 0 ; V_13 < V_16 ; V_13 ++ ) {
if ( F_10 ( V_8 , V_15 [ V_13 ] . V_18 ) ) {
if ( ! V_7 && V_15 [ V_13 ] . V_19 -> V_20 != V_21 )
return - V_22 ;
F_13 ( L_1 ,
V_15 [ V_13 ] . V_19 -> V_20 ) ;
F_14 ( & V_23 ) ;
V_17 = V_15 [ V_13 ] . V_19 -> V_20 ( V_7 , & V_15 [ V_13 ] ) ;
F_15 ( & V_23 ) ;
return V_17 ;
}
}
if ( F_12 ) {
F_13 ( L_2 , F_12 ) ;
return F_12 ( V_8 , V_7 ) ;
}
F_13 ( L_3 , V_8 ) ;
return - V_24 ;
}
static char * F_16 ( char * args , char * * V_8 , char * * V_7 )
{
unsigned int V_13 , V_25 = 0 ;
int V_26 = 0 , V_27 = 0 ;
char * V_28 ;
if ( * args == '"' ) {
args ++ ;
V_26 = 1 ;
V_27 = 1 ;
}
for ( V_13 = 0 ; args [ V_13 ] ; V_13 ++ ) {
if ( isspace ( args [ V_13 ] ) && ! V_26 )
break;
if ( V_25 == 0 ) {
if ( args [ V_13 ] == '=' )
V_25 = V_13 ;
}
if ( args [ V_13 ] == '"' )
V_26 = ! V_26 ;
}
* V_8 = args ;
if ( ! V_25 )
* V_7 = NULL ;
else {
args [ V_25 ] = '\0' ;
* V_7 = args + V_25 + 1 ;
if ( * * V_7 == '"' ) {
( * V_7 ) ++ ;
if ( args [ V_13 - 1 ] == '"' )
args [ V_13 - 1 ] = '\0' ;
}
if ( V_27 && args [ V_13 - 1 ] == '"' )
args [ V_13 - 1 ] = '\0' ;
}
if ( args [ V_13 ] ) {
args [ V_13 ] = '\0' ;
V_28 = args + V_13 + 1 ;
} else
V_28 = args + V_13 ;
return F_17 ( V_28 ) ;
}
int F_18 ( const char * V_18 ,
char * args ,
const struct V_14 * V_15 ,
unsigned V_29 ,
int (* F_19)( char * V_8 , char * V_7 ) )
{
char * V_8 , * V_7 ;
F_13 ( L_4 , args ) ;
args = F_17 ( args ) ;
while ( * args ) {
int V_30 ;
int V_31 ;
args = F_16 ( args , & V_8 , & V_7 ) ;
V_31 = F_20 () ;
V_30 = F_11 ( V_8 , V_7 , V_15 , V_29 , F_19 ) ;
if ( V_31 && ! F_20 () ) {
F_21 ( V_32 L_5
L_6 , V_8 ) ;
}
switch ( V_30 ) {
case - V_24 :
F_21 ( V_33 L_7 ,
V_18 , V_8 ) ;
return V_30 ;
case - V_34 :
F_21 ( V_33
L_8 ,
V_18 , V_7 ? : L_9 , V_8 ) ;
return V_30 ;
case 0 :
break;
default:
F_21 ( V_33
L_10 ,
V_18 , V_7 ? : L_9 , V_8 ) ;
return V_30 ;
}
}
return 0 ;
}
int F_22 ( const char * V_7 , const struct V_14 * V_35 )
{
if ( strlen ( V_7 ) > 1024 ) {
F_21 ( V_33 L_11 ,
V_35 -> V_18 ) ;
return - V_34 ;
}
F_4 ( * ( char * * ) V_35 -> V_36 ) ;
if ( F_23 () ) {
* ( char * * ) V_35 -> V_36 = F_1 ( strlen ( V_7 ) + 1 ) ;
if ( ! * ( char * * ) V_35 -> V_36 )
return - V_37 ;
strcpy ( * ( char * * ) V_35 -> V_36 , V_7 ) ;
} else
* ( const char * * ) V_35 -> V_36 = V_7 ;
return 0 ;
}
int F_24 ( char * V_38 , const struct V_14 * V_35 )
{
return sprintf ( V_38 , L_12 , * ( ( char * * ) V_35 -> V_36 ) ) ;
}
static void F_25 ( void * V_36 )
{
F_4 ( * ( ( char * * ) V_36 ) ) ;
}
int V_21 ( const char * V_7 , const struct V_14 * V_35 )
{
bool V_39 ;
int V_30 ;
if ( ! V_7 ) V_7 = L_13 ;
V_30 = F_26 ( V_7 , & V_39 ) ;
if ( V_30 )
return V_30 ;
if ( V_35 -> V_40 & V_41 )
* ( bool * ) V_35 -> V_36 = V_39 ;
else
* ( int * ) V_35 -> V_36 = V_39 ;
return 0 ;
}
int F_27 ( char * V_38 , const struct V_14 * V_35 )
{
bool V_7 ;
if ( V_35 -> V_40 & V_41 )
V_7 = * ( bool * ) V_35 -> V_36 ;
else
V_7 = * ( int * ) V_35 -> V_36 ;
return sprintf ( V_38 , L_14 , V_7 ? 'Y' : 'N' ) ;
}
int F_28 ( const char * V_7 , const struct V_14 * V_35 )
{
int V_30 ;
bool V_42 ;
struct V_14 V_43 ;
V_43 . V_36 = & V_42 ;
V_43 . V_40 = V_41 ;
V_30 = V_21 ( V_7 , & V_43 ) ;
if ( V_30 == 0 )
* ( bool * ) V_35 -> V_36 = ! V_42 ;
return V_30 ;
}
int F_29 ( char * V_38 , const struct V_14 * V_35 )
{
return sprintf ( V_38 , L_14 , ( * ( bool * ) V_35 -> V_36 ) ? 'N' : 'Y' ) ;
}
static int F_30 ( const char * V_18 ,
const char * V_7 ,
unsigned int V_44 , unsigned int V_45 ,
void * V_46 , int V_47 ,
int (* V_20)( const char * , const struct V_14 * V_35 ) ,
T_2 V_40 ,
unsigned int * V_29 )
{
int V_30 ;
struct V_14 V_35 ;
char V_48 ;
V_35 . V_18 = V_18 ;
V_35 . V_36 = V_46 ;
V_35 . V_40 = V_40 ;
* V_29 = 0 ;
do {
int V_49 ;
if ( * V_29 == V_45 ) {
F_21 ( V_33 L_15 ,
V_18 , V_45 ) ;
return - V_22 ;
}
V_49 = strcspn ( V_7 , L_16 ) ;
V_48 = V_7 [ V_49 ] ;
( ( char * ) V_7 ) [ V_49 ] = '\0' ;
F_31 ( ! F_32 ( & V_23 ) ) ;
V_30 = V_20 ( V_7 , & V_35 ) ;
if ( V_30 != 0 )
return V_30 ;
V_35 . V_36 += V_47 ;
V_7 += V_49 + 1 ;
( * V_29 ) ++ ;
} while ( V_48 == ',' );
if ( * V_29 < V_44 ) {
F_21 ( V_33 L_17 ,
V_18 , V_44 ) ;
return - V_22 ;
}
return 0 ;
}
static int F_33 ( const char * V_7 , const struct V_14 * V_35 )
{
const struct V_50 * V_51 = V_35 -> V_51 ;
unsigned int V_52 ;
return F_30 ( V_35 -> V_18 , V_7 , 1 , V_51 -> V_45 , V_51 -> V_46 ,
V_51 -> V_47 , V_51 -> V_19 -> V_20 , V_35 -> V_40 ,
V_51 -> V_29 ? : & V_52 ) ;
}
static int F_34 ( char * V_38 , const struct V_14 * V_35 )
{
int V_13 , V_53 , V_30 ;
const struct V_50 * V_51 = V_35 -> V_51 ;
struct V_14 V_3 ;
V_3 = * V_35 ;
for ( V_13 = V_53 = 0 ; V_13 < ( V_51 -> V_29 ? * V_51 -> V_29 : V_51 -> V_45 ) ; V_13 ++ ) {
if ( V_13 )
V_38 [ V_53 ++ ] = ',' ;
V_3 . V_36 = V_51 -> V_46 + V_51 -> V_47 * V_13 ;
F_31 ( ! F_32 ( & V_23 ) ) ;
V_30 = V_51 -> V_19 -> V_54 ( V_38 + V_53 , & V_3 ) ;
if ( V_30 < 0 )
return V_30 ;
V_53 += V_30 ;
}
V_38 [ V_53 ] = '\0' ;
return V_53 ;
}
static void F_35 ( void * V_36 )
{
unsigned int V_13 ;
const struct V_50 * V_51 = V_36 ;
if ( V_51 -> V_19 -> free )
for ( V_13 = 0 ; V_13 < ( V_51 -> V_29 ? * V_51 -> V_29 : V_51 -> V_45 ) ; V_13 ++ )
V_51 -> V_19 -> free ( V_51 -> V_46 + V_51 -> V_47 * V_13 ) ;
}
int F_36 ( const char * V_7 , const struct V_14 * V_35 )
{
const struct V_55 * V_56 = V_35 -> V_57 ;
if ( strlen ( V_7 ) + 1 > V_56 -> V_58 ) {
F_21 ( V_33 L_18 ,
V_35 -> V_18 , V_56 -> V_58 - 1 ) ;
return - V_34 ;
}
strcpy ( V_56 -> string , V_7 ) ;
return 0 ;
}
int F_37 ( char * V_38 , const struct V_14 * V_35 )
{
const struct V_55 * V_56 = V_35 -> V_57 ;
return F_38 ( V_38 , V_56 -> string , V_56 -> V_58 ) ;
}
static T_3 F_39 ( struct V_59 * V_60 ,
struct V_61 * V_62 , char * V_63 )
{
int V_64 ;
struct V_65 * V_66 = F_40 ( V_60 ) ;
if ( ! V_66 -> V_8 -> V_19 -> V_54 )
return - V_67 ;
F_14 ( & V_23 ) ;
V_64 = V_66 -> V_8 -> V_19 -> V_54 ( V_63 , V_66 -> V_8 ) ;
F_15 ( & V_23 ) ;
if ( V_64 > 0 ) {
strcat ( V_63 , L_19 ) ;
++ V_64 ;
}
return V_64 ;
}
static T_3 F_41 ( struct V_59 * V_60 ,
struct V_61 * V_68 ,
const char * V_63 , T_1 V_49 )
{
int V_17 ;
struct V_65 * V_66 = F_40 ( V_60 ) ;
if ( ! V_66 -> V_8 -> V_19 -> V_20 )
return - V_67 ;
F_14 ( & V_23 ) ;
V_17 = V_66 -> V_8 -> V_19 -> V_20 ( V_63 , V_66 -> V_8 ) ;
F_15 ( & V_23 ) ;
if ( ! V_17 )
return V_49 ;
return V_17 ;
}
void F_42 ( void )
{
F_14 ( & V_23 ) ;
}
void F_43 ( void )
{
F_15 ( & V_23 ) ;
}
static T_4 int F_44 ( struct V_61 * V_62 ,
const struct V_14 * V_35 ,
const char * V_18 )
{
struct V_69 * V_70 ;
struct V_66 * * V_71 ;
int V_17 , V_29 ;
F_31 ( ! V_35 -> V_72 ) ;
if ( ! V_62 -> V_73 ) {
V_29 = 0 ;
V_71 = NULL ;
} else {
V_29 = V_62 -> V_73 -> V_29 ;
V_71 = V_62 -> V_73 -> V_74 . V_71 ;
}
V_70 = F_45 ( V_62 -> V_73 ,
sizeof( * V_62 -> V_73 ) + sizeof( V_62 -> V_73 -> V_71 [ 0 ] ) * ( V_29 + 1 ) ,
V_4 ) ;
if ( ! V_70 ) {
F_7 ( V_62 -> V_73 ) ;
V_17 = - V_37 ;
goto V_75;
}
V_71 = F_45 ( V_71 , sizeof( V_70 -> V_74 . V_71 [ 0 ] ) * ( V_29 + 2 ) , V_4 ) ;
if ( ! V_71 ) {
V_17 = - V_37 ;
goto V_76;
}
memset ( V_70 , 0 , sizeof( * V_70 ) ) ;
memset ( & V_70 -> V_71 [ V_29 ] , 0 , sizeof( V_70 -> V_71 [ V_29 ] ) ) ;
memset ( & V_71 [ V_29 ] , 0 , sizeof( V_71 [ V_29 ] ) ) ;
V_70 -> V_74 . V_18 = L_20 ;
V_70 -> V_74 . V_71 = V_71 ;
F_46 ( & V_70 -> V_71 [ V_29 ] . V_60 . V_77 ) ;
V_70 -> V_71 [ V_29 ] . V_8 = V_35 ;
V_70 -> V_71 [ V_29 ] . V_60 . V_78 = F_39 ;
V_70 -> V_71 [ V_29 ] . V_60 . V_79 = F_41 ;
V_70 -> V_71 [ V_29 ] . V_60 . V_77 . V_18 = ( char * ) V_18 ;
V_70 -> V_71 [ V_29 ] . V_60 . V_77 . V_80 = V_35 -> V_72 ;
V_70 -> V_29 = V_29 + 1 ;
for ( V_29 = 0 ; V_29 < V_70 -> V_29 ; V_29 ++ )
V_70 -> V_74 . V_71 [ V_29 ] = & V_70 -> V_71 [ V_29 ] . V_60 . V_77 ;
V_70 -> V_74 . V_71 [ V_29 ] = NULL ;
V_62 -> V_73 = V_70 ;
return 0 ;
V_76:
F_7 ( V_70 ) ;
V_75:
V_62 -> V_73 = NULL ;
return V_17 ;
}
static void F_47 ( struct V_61 * V_62 )
{
F_7 ( V_62 -> V_73 -> V_74 . V_71 ) ;
F_7 ( V_62 -> V_73 ) ;
V_62 -> V_73 = NULL ;
}
int F_48 ( struct V_81 * V_82 ,
const struct V_14 * V_83 ,
unsigned int V_16 )
{
int V_13 , V_17 ;
bool V_15 = false ;
for ( V_13 = 0 ; V_13 < V_16 ; V_13 ++ ) {
if ( V_83 [ V_13 ] . V_72 == 0 )
continue;
V_17 = F_44 ( & V_82 -> V_84 , & V_83 [ V_13 ] , V_83 [ V_13 ] . V_18 ) ;
if ( V_17 )
return V_17 ;
V_15 = true ;
}
if ( ! V_15 )
return 0 ;
V_17 = F_49 ( & V_82 -> V_84 . V_85 , & V_82 -> V_84 . V_73 -> V_74 ) ;
if ( V_17 )
F_47 ( & V_82 -> V_84 ) ;
return V_17 ;
}
void F_50 ( struct V_81 * V_82 )
{
if ( V_82 -> V_84 . V_73 ) {
F_51 ( & V_82 -> V_84 . V_85 , & V_82 -> V_84 . V_73 -> V_74 ) ;
F_47 ( & V_82 -> V_84 ) ;
}
}
void F_52 ( const struct V_14 * V_15 , unsigned V_29 )
{
unsigned int V_13 ;
for ( V_13 = 0 ; V_13 < V_29 ; V_13 ++ )
if ( V_15 [ V_13 ] . V_19 -> free )
V_15 [ V_13 ] . V_19 -> free ( V_15 [ V_13 ] . V_36 ) ;
}
static struct V_61 * T_5 F_53 ( const char * V_18 )
{
struct V_61 * V_62 ;
struct V_86 * V_85 ;
int V_17 ;
V_85 = F_54 ( V_87 , V_18 ) ;
if ( V_85 ) {
V_62 = F_55 ( V_85 ) ;
} else {
V_62 = F_56 ( sizeof( struct V_61 ) , V_4 ) ;
F_31 ( ! V_62 ) ;
V_62 -> V_82 = V_88 ;
V_62 -> V_85 . V_89 = V_87 ;
V_17 = F_57 ( & V_62 -> V_85 , & V_90 , NULL ,
L_12 , V_18 ) ;
#ifdef F_58
if ( ! V_17 )
V_17 = F_59 ( & V_62 -> V_85 , & V_91 . V_77 ) ;
#endif
if ( V_17 ) {
F_60 ( & V_62 -> V_85 ) ;
F_21 ( V_33
L_21 ,
V_18 , V_17 ) ;
F_21 ( V_33
L_22 ) ;
return NULL ;
}
F_61 ( & V_62 -> V_85 ) ;
}
return V_62 ;
}
static void T_5 F_62 ( const char * V_18 ,
struct V_14 * V_83 ,
unsigned int V_92 )
{
struct V_61 * V_62 ;
int V_17 ;
V_62 = F_53 ( V_18 ) ;
if ( ! V_62 )
return;
if ( V_62 -> V_73 )
F_51 ( & V_62 -> V_85 , & V_62 -> V_73 -> V_74 ) ;
V_17 = F_44 ( V_62 , V_83 , V_83 -> V_18 + V_92 ) ;
F_31 ( V_17 ) ;
V_17 = F_49 ( & V_62 -> V_85 , & V_62 -> V_73 -> V_74 ) ;
F_31 ( V_17 ) ;
F_63 ( & V_62 -> V_85 , V_93 ) ;
F_60 ( & V_62 -> V_85 ) ;
}
static void T_5 F_64 ( void )
{
struct V_14 * V_35 ;
unsigned int V_94 ;
char V_95 [ V_96 ] ;
for ( V_35 = V_97 ; V_35 < V_98 ; V_35 ++ ) {
char * V_99 ;
if ( V_35 -> V_72 == 0 )
continue;
V_99 = strchr ( V_35 -> V_18 , '.' ) ;
if ( ! V_99 ) {
strcpy ( V_95 , L_23 ) ;
V_94 = 0 ;
} else {
V_94 = V_99 - V_35 -> V_18 + 1 ;
F_38 ( V_95 , V_35 -> V_18 , V_94 ) ;
}
F_62 ( V_95 , V_35 , V_94 ) ;
}
}
T_3 F_65 ( struct V_59 * V_60 ,
struct V_61 * V_62 , char * V_63 )
{
struct V_100 * V_101 =
F_66 ( V_60 , struct V_100 , V_60 ) ;
return sprintf ( V_63 , L_24 , V_101 -> V_102 ) ;
}
static void T_5 F_67 ( void )
{
const struct V_100 * * V_3 ;
struct V_61 * V_62 ;
int V_17 ;
for ( V_3 = V_103 ; V_3 < V_104 ; V_3 ++ ) {
const struct V_100 * V_101 = * V_3 ;
V_62 = F_53 ( V_101 -> V_105 ) ;
if ( V_62 ) {
V_17 = F_59 ( & V_62 -> V_85 , & V_101 -> V_60 . V_77 ) ;
F_63 ( & V_62 -> V_85 , V_93 ) ;
F_60 ( & V_62 -> V_85 ) ;
}
}
}
static T_3 F_68 ( struct V_86 * V_85 ,
struct V_66 * V_77 ,
char * V_63 )
{
struct V_59 * V_66 ;
struct V_61 * V_62 ;
int V_30 ;
V_66 = F_69 ( V_77 ) ;
V_62 = F_55 ( V_85 ) ;
if ( ! V_66 -> V_78 )
return - V_106 ;
V_30 = V_66 -> V_78 ( V_66 , V_62 , V_63 ) ;
return V_30 ;
}
static T_3 F_70 ( struct V_86 * V_85 ,
struct V_66 * V_77 ,
const char * V_63 , T_1 V_49 )
{
struct V_59 * V_66 ;
struct V_61 * V_62 ;
int V_30 ;
V_66 = F_69 ( V_77 ) ;
V_62 = F_55 ( V_85 ) ;
if ( ! V_66 -> V_79 )
return - V_106 ;
V_30 = V_66 -> V_79 ( V_66 , V_62 , V_63 , V_49 ) ;
return V_30 ;
}
static int F_71 ( struct V_89 * V_89 , struct V_86 * V_85 )
{
struct V_107 * V_108 = F_72 ( V_85 ) ;
if ( V_108 == & V_90 )
return 1 ;
return 0 ;
}
static int T_5 F_73 ( void )
{
V_87 = F_74 ( L_25 , & V_109 , NULL ) ;
if ( ! V_87 ) {
F_21 ( V_32 L_26 ,
__FILE__ , __LINE__ ) ;
return - V_37 ;
}
V_110 = 1 ;
F_67 () ;
F_64 () ;
return 0 ;
}
