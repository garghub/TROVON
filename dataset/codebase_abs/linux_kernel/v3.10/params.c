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
const char * V_14 ,
const struct V_15 * V_16 ,
unsigned V_17 ,
T_2 V_18 ,
T_2 V_19 ,
int (* F_12)( char * V_8 , char * V_7 ,
const char * V_14 ) )
{
unsigned int V_13 ;
int V_20 ;
for ( V_13 = 0 ; V_13 < V_17 ; V_13 ++ ) {
if ( F_10 ( V_8 , V_16 [ V_13 ] . V_21 ) ) {
if ( V_16 [ V_13 ] . V_22 < V_18
|| V_16 [ V_13 ] . V_22 > V_19 )
return 0 ;
if ( ! V_7 && V_16 [ V_13 ] . V_23 -> V_24 != V_25
&& V_16 [ V_13 ] . V_23 -> V_24 != V_26 )
return - V_27 ;
F_13 ( L_1 , V_8 ,
V_16 [ V_13 ] . V_23 -> V_24 ) ;
F_14 ( & V_28 ) ;
V_20 = V_16 [ V_13 ] . V_23 -> V_24 ( V_7 , & V_16 [ V_13 ] ) ;
F_15 ( & V_28 ) ;
return V_20 ;
}
}
if ( F_12 ) {
F_13 ( L_2 , V_14 , V_8 , V_7 ) ;
return F_12 ( V_8 , V_7 , V_14 ) ;
}
F_13 ( L_3 , V_8 ) ;
return - V_29 ;
}
static char * F_16 ( char * args , char * * V_8 , char * * V_7 )
{
unsigned int V_13 , V_30 = 0 ;
int V_31 = 0 , V_32 = 0 ;
char * V_33 ;
if ( * args == '"' ) {
args ++ ;
V_31 = 1 ;
V_32 = 1 ;
}
for ( V_13 = 0 ; args [ V_13 ] ; V_13 ++ ) {
if ( isspace ( args [ V_13 ] ) && ! V_31 )
break;
if ( V_30 == 0 ) {
if ( args [ V_13 ] == '=' )
V_30 = V_13 ;
}
if ( args [ V_13 ] == '"' )
V_31 = ! V_31 ;
}
* V_8 = args ;
if ( ! V_30 )
* V_7 = NULL ;
else {
args [ V_30 ] = '\0' ;
* V_7 = args + V_30 + 1 ;
if ( * * V_7 == '"' ) {
( * V_7 ) ++ ;
if ( args [ V_13 - 1 ] == '"' )
args [ V_13 - 1 ] = '\0' ;
}
if ( V_32 && args [ V_13 - 1 ] == '"' )
args [ V_13 - 1 ] = '\0' ;
}
if ( args [ V_13 ] ) {
args [ V_13 ] = '\0' ;
V_33 = args + V_13 + 1 ;
} else
V_33 = args + V_13 ;
return F_17 ( V_33 ) ;
}
int F_18 ( const char * V_14 ,
char * args ,
const struct V_15 * V_16 ,
unsigned V_34 ,
T_2 V_18 ,
T_2 V_19 ,
int (* F_19)( char * V_8 , char * V_7 , const char * V_14 ) )
{
char * V_8 , * V_7 ;
args = F_17 ( args ) ;
if ( * args )
F_13 ( L_4 , V_14 , args ) ;
while ( * args ) {
int V_35 ;
int V_36 ;
args = F_16 ( args , & V_8 , & V_7 ) ;
V_36 = F_20 () ;
V_35 = F_11 ( V_8 , V_7 , V_14 , V_16 , V_34 ,
V_18 , V_19 , F_19 ) ;
if ( V_36 && ! F_20 () )
F_21 ( L_5 ,
V_14 , V_8 ) ;
switch ( V_35 ) {
case - V_29 :
F_22 ( L_6 , V_14 , V_8 ) ;
return V_35 ;
case - V_37 :
F_22 ( L_7 ,
V_14 , V_7 ? : L_8 , V_8 ) ;
return V_35 ;
case 0 :
break;
default:
F_22 ( L_9 ,
V_14 , V_7 ? : L_8 , V_8 ) ;
return V_35 ;
}
}
return 0 ;
}
int F_23 ( const char * V_7 , const struct V_15 * V_38 )
{
if ( strlen ( V_7 ) > 1024 ) {
F_22 ( L_10 , V_38 -> V_21 ) ;
return - V_37 ;
}
F_4 ( * ( char * * ) V_38 -> V_39 ) ;
if ( F_24 () ) {
* ( char * * ) V_38 -> V_39 = F_1 ( strlen ( V_7 ) + 1 ) ;
if ( ! * ( char * * ) V_38 -> V_39 )
return - V_40 ;
strcpy ( * ( char * * ) V_38 -> V_39 , V_7 ) ;
} else
* ( const char * * ) V_38 -> V_39 = V_7 ;
return 0 ;
}
int F_25 ( char * V_41 , const struct V_15 * V_38 )
{
return sprintf ( V_41 , L_11 , * ( ( char * * ) V_38 -> V_39 ) ) ;
}
static void F_26 ( void * V_39 )
{
F_4 ( * ( ( char * * ) V_39 ) ) ;
}
int V_25 ( const char * V_7 , const struct V_15 * V_38 )
{
if ( ! V_7 ) V_7 = L_12 ;
return F_27 ( V_7 , V_38 -> V_39 ) ;
}
int F_28 ( char * V_41 , const struct V_15 * V_38 )
{
return sprintf ( V_41 , L_13 , * ( bool * ) V_38 -> V_39 ? 'Y' : 'N' ) ;
}
int F_29 ( const char * V_7 , const struct V_15 * V_38 )
{
int V_35 ;
bool V_42 ;
struct V_15 V_43 ;
V_43 . V_39 = & V_42 ;
V_35 = V_25 ( V_7 , & V_43 ) ;
if ( V_35 == 0 )
* ( bool * ) V_38 -> V_39 = ! V_42 ;
return V_35 ;
}
int F_30 ( char * V_41 , const struct V_15 * V_38 )
{
return sprintf ( V_41 , L_13 , ( * ( bool * ) V_38 -> V_39 ) ? 'N' : 'Y' ) ;
}
int V_26 ( const char * V_7 , const struct V_15 * V_38 )
{
struct V_15 V_44 ;
bool V_45 ;
int V_35 ;
V_44 = * V_38 ;
V_44 . V_39 = & V_45 ;
V_35 = V_25 ( V_7 , & V_44 ) ;
if ( V_35 == 0 )
* ( int * ) V_38 -> V_39 = V_45 ;
return V_35 ;
}
static int F_31 ( const char * V_21 ,
const char * V_7 ,
unsigned int V_46 , unsigned int V_47 ,
void * V_48 , int V_49 ,
int (* V_24)( const char * , const struct V_15 * V_38 ) ,
T_2 V_22 ,
unsigned int * V_34 )
{
int V_35 ;
struct V_15 V_38 ;
char V_50 ;
V_38 . V_21 = V_21 ;
V_38 . V_39 = V_48 ;
V_38 . V_22 = V_22 ;
* V_34 = 0 ;
do {
int V_51 ;
if ( * V_34 == V_47 ) {
F_22 ( L_14 , V_21 , V_47 ) ;
return - V_27 ;
}
V_51 = strcspn ( V_7 , L_15 ) ;
V_50 = V_7 [ V_51 ] ;
( ( char * ) V_7 ) [ V_51 ] = '\0' ;
F_32 ( ! F_33 ( & V_28 ) ) ;
V_35 = V_24 ( V_7 , & V_38 ) ;
if ( V_35 != 0 )
return V_35 ;
V_38 . V_39 += V_49 ;
V_7 += V_51 + 1 ;
( * V_34 ) ++ ;
} while ( V_50 == ',' );
if ( * V_34 < V_46 ) {
F_22 ( L_16 , V_21 , V_46 ) ;
return - V_27 ;
}
return 0 ;
}
static int F_34 ( const char * V_7 , const struct V_15 * V_38 )
{
const struct V_52 * V_53 = V_38 -> V_53 ;
unsigned int V_54 ;
return F_31 ( V_38 -> V_21 , V_7 , 1 , V_53 -> V_47 , V_53 -> V_48 ,
V_53 -> V_49 , V_53 -> V_23 -> V_24 , V_38 -> V_22 ,
V_53 -> V_34 ? : & V_54 ) ;
}
static int F_35 ( char * V_41 , const struct V_15 * V_38 )
{
int V_13 , V_55 , V_35 ;
const struct V_52 * V_53 = V_38 -> V_53 ;
struct V_15 V_3 ;
V_3 = * V_38 ;
for ( V_13 = V_55 = 0 ; V_13 < ( V_53 -> V_34 ? * V_53 -> V_34 : V_53 -> V_47 ) ; V_13 ++ ) {
if ( V_13 )
V_41 [ V_55 ++ ] = ',' ;
V_3 . V_39 = V_53 -> V_48 + V_53 -> V_49 * V_13 ;
F_32 ( ! F_33 ( & V_28 ) ) ;
V_35 = V_53 -> V_23 -> V_56 ( V_41 + V_55 , & V_3 ) ;
if ( V_35 < 0 )
return V_35 ;
V_55 += V_35 ;
}
V_41 [ V_55 ] = '\0' ;
return V_55 ;
}
static void F_36 ( void * V_39 )
{
unsigned int V_13 ;
const struct V_52 * V_53 = V_39 ;
if ( V_53 -> V_23 -> free )
for ( V_13 = 0 ; V_13 < ( V_53 -> V_34 ? * V_53 -> V_34 : V_53 -> V_47 ) ; V_13 ++ )
V_53 -> V_23 -> free ( V_53 -> V_48 + V_53 -> V_49 * V_13 ) ;
}
int F_37 ( const char * V_7 , const struct V_15 * V_38 )
{
const struct V_57 * V_58 = V_38 -> V_59 ;
if ( strlen ( V_7 ) + 1 > V_58 -> V_60 ) {
F_22 ( L_17 ,
V_38 -> V_21 , V_58 -> V_60 - 1 ) ;
return - V_37 ;
}
strcpy ( V_58 -> string , V_7 ) ;
return 0 ;
}
int F_38 ( char * V_41 , const struct V_15 * V_38 )
{
const struct V_57 * V_58 = V_38 -> V_59 ;
return F_39 ( V_41 , V_58 -> string , V_58 -> V_60 ) ;
}
static T_3 F_40 ( struct V_61 * V_62 ,
struct V_63 * V_64 , char * V_65 )
{
int V_66 ;
struct V_67 * V_68 = F_41 ( V_62 ) ;
if ( ! V_68 -> V_8 -> V_23 -> V_56 )
return - V_69 ;
F_14 ( & V_28 ) ;
V_66 = V_68 -> V_8 -> V_23 -> V_56 ( V_65 , V_68 -> V_8 ) ;
F_15 ( & V_28 ) ;
if ( V_66 > 0 ) {
strcat ( V_65 , L_18 ) ;
++ V_66 ;
}
return V_66 ;
}
static T_3 F_42 ( struct V_61 * V_62 ,
struct V_63 * V_70 ,
const char * V_65 , T_1 V_51 )
{
int V_20 ;
struct V_67 * V_68 = F_41 ( V_62 ) ;
if ( ! V_68 -> V_8 -> V_23 -> V_24 )
return - V_69 ;
F_14 ( & V_28 ) ;
V_20 = V_68 -> V_8 -> V_23 -> V_24 ( V_65 , V_68 -> V_8 ) ;
F_15 ( & V_28 ) ;
if ( ! V_20 )
return V_51 ;
return V_20 ;
}
void F_43 ( void )
{
F_14 ( & V_28 ) ;
}
void F_44 ( void )
{
F_15 ( & V_28 ) ;
}
static T_4 int F_45 ( struct V_63 * V_64 ,
const struct V_15 * V_38 ,
const char * V_21 )
{
struct V_71 * V_72 ;
struct V_68 * * V_73 ;
int V_20 , V_34 ;
F_32 ( ! V_38 -> V_74 ) ;
if ( ! V_64 -> V_75 ) {
V_34 = 0 ;
V_73 = NULL ;
} else {
V_34 = V_64 -> V_75 -> V_34 ;
V_73 = V_64 -> V_75 -> V_76 . V_73 ;
}
V_72 = F_46 ( V_64 -> V_75 ,
sizeof( * V_64 -> V_75 ) + sizeof( V_64 -> V_75 -> V_73 [ 0 ] ) * ( V_34 + 1 ) ,
V_4 ) ;
if ( ! V_72 ) {
F_7 ( V_73 ) ;
V_20 = - V_40 ;
goto V_77;
}
V_73 = F_46 ( V_73 , sizeof( V_72 -> V_76 . V_73 [ 0 ] ) * ( V_34 + 2 ) , V_4 ) ;
if ( ! V_73 ) {
V_20 = - V_40 ;
goto V_78;
}
memset ( V_72 , 0 , sizeof( * V_72 ) ) ;
memset ( & V_72 -> V_73 [ V_34 ] , 0 , sizeof( V_72 -> V_73 [ V_34 ] ) ) ;
memset ( & V_73 [ V_34 ] , 0 , sizeof( V_73 [ V_34 ] ) ) ;
V_72 -> V_76 . V_21 = L_19 ;
V_72 -> V_76 . V_73 = V_73 ;
F_47 ( & V_72 -> V_73 [ V_34 ] . V_62 . V_79 ) ;
V_72 -> V_73 [ V_34 ] . V_8 = V_38 ;
V_72 -> V_73 [ V_34 ] . V_62 . V_80 = F_40 ;
V_72 -> V_73 [ V_34 ] . V_62 . V_81 = F_42 ;
V_72 -> V_73 [ V_34 ] . V_62 . V_79 . V_21 = ( char * ) V_21 ;
V_72 -> V_73 [ V_34 ] . V_62 . V_79 . V_82 = V_38 -> V_74 ;
V_72 -> V_34 = V_34 + 1 ;
for ( V_34 = 0 ; V_34 < V_72 -> V_34 ; V_34 ++ )
V_72 -> V_76 . V_73 [ V_34 ] = & V_72 -> V_73 [ V_34 ] . V_62 . V_79 ;
V_72 -> V_76 . V_73 [ V_34 ] = NULL ;
V_64 -> V_75 = V_72 ;
return 0 ;
V_78:
F_7 ( V_72 ) ;
V_77:
V_64 -> V_75 = NULL ;
return V_20 ;
}
static void F_48 ( struct V_63 * V_64 )
{
F_7 ( V_64 -> V_75 -> V_76 . V_73 ) ;
F_7 ( V_64 -> V_75 ) ;
V_64 -> V_75 = NULL ;
}
int F_49 ( struct V_83 * V_84 ,
const struct V_15 * V_85 ,
unsigned int V_17 )
{
int V_13 , V_20 ;
bool V_16 = false ;
for ( V_13 = 0 ; V_13 < V_17 ; V_13 ++ ) {
if ( V_85 [ V_13 ] . V_74 == 0 )
continue;
V_20 = F_45 ( & V_84 -> V_86 , & V_85 [ V_13 ] , V_85 [ V_13 ] . V_21 ) ;
if ( V_20 )
return V_20 ;
V_16 = true ;
}
if ( ! V_16 )
return 0 ;
V_20 = F_50 ( & V_84 -> V_86 . V_87 , & V_84 -> V_86 . V_75 -> V_76 ) ;
if ( V_20 )
F_48 ( & V_84 -> V_86 ) ;
return V_20 ;
}
void F_51 ( struct V_83 * V_84 )
{
if ( V_84 -> V_86 . V_75 ) {
F_52 ( & V_84 -> V_86 . V_87 , & V_84 -> V_86 . V_75 -> V_76 ) ;
F_48 ( & V_84 -> V_86 ) ;
}
}
void F_53 ( const struct V_15 * V_16 , unsigned V_34 )
{
unsigned int V_13 ;
for ( V_13 = 0 ; V_13 < V_34 ; V_13 ++ )
if ( V_16 [ V_13 ] . V_23 -> free )
V_16 [ V_13 ] . V_23 -> free ( V_16 [ V_13 ] . V_39 ) ;
}
static struct V_63 * T_5 F_54 ( const char * V_21 )
{
struct V_63 * V_64 ;
struct V_88 * V_87 ;
int V_20 ;
V_87 = F_55 ( V_89 , V_21 ) ;
if ( V_87 ) {
V_64 = F_56 ( V_87 ) ;
} else {
V_64 = F_57 ( sizeof( struct V_63 ) , V_4 ) ;
F_32 ( ! V_64 ) ;
V_64 -> V_84 = V_90 ;
V_64 -> V_87 . V_91 = V_89 ;
V_20 = F_58 ( & V_64 -> V_87 , & V_92 , NULL ,
L_11 , V_21 ) ;
#ifdef F_59
if ( ! V_20 )
V_20 = F_60 ( & V_64 -> V_87 , & V_93 . V_79 ) ;
#endif
if ( V_20 ) {
F_61 ( & V_64 -> V_87 ) ;
F_62 ( L_20 ,
V_21 , V_20 ) ;
return NULL ;
}
F_63 ( & V_64 -> V_87 ) ;
}
return V_64 ;
}
static void T_5 F_64 ( const char * V_21 ,
struct V_15 * V_85 ,
unsigned int V_94 )
{
struct V_63 * V_64 ;
int V_20 ;
V_64 = F_54 ( V_21 ) ;
if ( ! V_64 )
return;
if ( V_64 -> V_75 )
F_52 ( & V_64 -> V_87 , & V_64 -> V_75 -> V_76 ) ;
V_20 = F_45 ( V_64 , V_85 , V_85 -> V_21 + V_94 ) ;
F_32 ( V_20 ) ;
V_20 = F_50 ( & V_64 -> V_87 , & V_64 -> V_75 -> V_76 ) ;
F_32 ( V_20 ) ;
F_65 ( & V_64 -> V_87 , V_95 ) ;
F_61 ( & V_64 -> V_87 ) ;
}
static void T_5 F_66 ( void )
{
struct V_15 * V_38 ;
unsigned int V_96 ;
char V_97 [ V_98 ] ;
for ( V_38 = V_99 ; V_38 < V_100 ; V_38 ++ ) {
char * V_101 ;
if ( V_38 -> V_74 == 0 )
continue;
V_101 = strchr ( V_38 -> V_21 , '.' ) ;
if ( ! V_101 ) {
strcpy ( V_97 , L_21 ) ;
V_96 = 0 ;
} else {
V_96 = V_101 - V_38 -> V_21 + 1 ;
F_39 ( V_97 , V_38 -> V_21 , V_96 ) ;
}
F_64 ( V_97 , V_38 , V_96 ) ;
}
}
T_3 F_67 ( struct V_61 * V_62 ,
struct V_63 * V_64 , char * V_65 )
{
struct V_102 * V_103 =
F_68 ( V_62 , struct V_102 , V_62 ) ;
return sprintf ( V_65 , L_22 , V_103 -> V_104 ) ;
}
static void T_5 F_69 ( void )
{
const struct V_102 * * V_3 ;
struct V_63 * V_64 ;
int V_20 ;
for ( V_3 = V_105 ; V_3 < V_106 ; V_3 ++ ) {
const struct V_102 * V_103 = * V_3 ;
V_64 = F_54 ( V_103 -> V_107 ) ;
if ( V_64 ) {
V_20 = F_60 ( & V_64 -> V_87 , & V_103 -> V_62 . V_79 ) ;
F_65 ( & V_64 -> V_87 , V_95 ) ;
F_61 ( & V_64 -> V_87 ) ;
}
}
}
static T_3 F_70 ( struct V_88 * V_87 ,
struct V_68 * V_79 ,
char * V_65 )
{
struct V_61 * V_68 ;
struct V_63 * V_64 ;
int V_35 ;
V_68 = F_71 ( V_79 ) ;
V_64 = F_56 ( V_87 ) ;
if ( ! V_68 -> V_80 )
return - V_108 ;
V_35 = V_68 -> V_80 ( V_68 , V_64 , V_65 ) ;
return V_35 ;
}
static T_3 F_72 ( struct V_88 * V_87 ,
struct V_68 * V_79 ,
const char * V_65 , T_1 V_51 )
{
struct V_61 * V_68 ;
struct V_63 * V_64 ;
int V_35 ;
V_68 = F_71 ( V_79 ) ;
V_64 = F_56 ( V_87 ) ;
if ( ! V_68 -> V_81 )
return - V_108 ;
V_35 = V_68 -> V_81 ( V_68 , V_64 , V_65 , V_51 ) ;
return V_35 ;
}
static int F_73 ( struct V_91 * V_91 , struct V_88 * V_87 )
{
struct V_109 * V_110 = F_74 ( V_87 ) ;
if ( V_110 == & V_92 )
return 1 ;
return 0 ;
}
static int T_5 F_75 ( void )
{
V_89 = F_76 ( L_23 , & V_111 , NULL ) ;
if ( ! V_89 ) {
F_77 ( V_112 L_24 ,
__FILE__ , __LINE__ ) ;
return - V_40 ;
}
V_113 = 1 ;
F_69 () ;
F_66 () ;
return 0 ;
}
