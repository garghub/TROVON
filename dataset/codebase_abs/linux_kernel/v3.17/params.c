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
if ( ! V_7 &&
! ( V_16 [ V_13 ] . V_23 -> V_24 & V_25 ) )
return - V_26 ;
F_13 ( L_1 , V_8 ,
V_16 [ V_13 ] . V_23 -> V_27 ) ;
F_14 ( & V_28 ) ;
V_20 = V_16 [ V_13 ] . V_23 -> V_27 ( V_7 , & V_16 [ V_13 ] ) ;
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
char * F_18 ( const char * V_14 ,
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
if ( ! V_7 && strcmp ( V_8 , L_5 ) == 0 )
return args ;
V_36 = F_20 () ;
V_35 = F_11 ( V_8 , V_7 , V_14 , V_16 , V_34 ,
V_18 , V_19 , F_19 ) ;
if ( V_36 && ! F_20 () )
F_21 ( L_6 ,
V_14 , V_8 ) ;
switch ( V_35 ) {
case - V_29 :
F_22 ( L_7 , V_14 , V_8 ) ;
return F_23 ( V_35 ) ;
case - V_37 :
F_22 ( L_8 ,
V_14 , V_7 ? : L_9 , V_8 ) ;
return F_23 ( V_35 ) ;
case 0 :
break;
default:
F_22 ( L_10 ,
V_14 , V_7 ? : L_9 , V_8 ) ;
return F_23 ( V_35 ) ;
}
}
return NULL ;
}
int F_24 ( const char * V_7 , const struct V_15 * V_38 )
{
if ( strlen ( V_7 ) > 1024 ) {
F_22 ( L_11 , V_38 -> V_21 ) ;
return - V_37 ;
}
F_4 ( * ( char * * ) V_38 -> V_39 ) ;
if ( F_25 () ) {
* ( char * * ) V_38 -> V_39 = F_1 ( strlen ( V_7 ) + 1 ) ;
if ( ! * ( char * * ) V_38 -> V_39 )
return - V_40 ;
strcpy ( * ( char * * ) V_38 -> V_39 , V_7 ) ;
} else
* ( const char * * ) V_38 -> V_39 = V_7 ;
return 0 ;
}
int F_26 ( char * V_41 , const struct V_15 * V_38 )
{
return F_27 ( V_41 , V_42 , L_12 , * ( ( char * * ) V_38 -> V_39 ) ) ;
}
static void F_28 ( void * V_39 )
{
F_4 ( * ( ( char * * ) V_39 ) ) ;
}
int F_29 ( const char * V_7 , const struct V_15 * V_38 )
{
if ( ! V_7 ) V_7 = L_13 ;
return F_30 ( V_7 , V_38 -> V_39 ) ;
}
int F_31 ( char * V_41 , const struct V_15 * V_38 )
{
return sprintf ( V_41 , L_14 , * ( bool * ) V_38 -> V_39 ? 'Y' : 'N' ) ;
}
int F_32 ( const char * V_7 , const struct V_15 * V_38 )
{
int V_35 ;
bool V_43 ;
struct V_15 V_44 ;
V_44 . V_39 = & V_43 ;
V_35 = F_29 ( V_7 , & V_44 ) ;
if ( V_35 == 0 )
* ( bool * ) V_38 -> V_39 = ! V_43 ;
return V_35 ;
}
int F_33 ( char * V_41 , const struct V_15 * V_38 )
{
return sprintf ( V_41 , L_14 , ( * ( bool * ) V_38 -> V_39 ) ? 'N' : 'Y' ) ;
}
int F_34 ( const char * V_7 , const struct V_15 * V_38 )
{
struct V_15 V_45 ;
bool V_46 ;
int V_35 ;
V_45 = * V_38 ;
V_45 . V_39 = & V_46 ;
V_35 = F_29 ( V_7 , & V_45 ) ;
if ( V_35 == 0 )
* ( int * ) V_38 -> V_39 = V_46 ;
return V_35 ;
}
static int F_35 ( const char * V_21 ,
const char * V_7 ,
unsigned int V_47 , unsigned int V_48 ,
void * V_49 , int V_50 ,
int (* V_27)( const char * , const struct V_15 * V_38 ) ,
T_2 V_22 ,
unsigned int * V_34 )
{
int V_35 ;
struct V_15 V_38 ;
char V_51 ;
V_38 . V_21 = V_21 ;
V_38 . V_39 = V_49 ;
V_38 . V_22 = V_22 ;
* V_34 = 0 ;
do {
int V_52 ;
if ( * V_34 == V_48 ) {
F_22 ( L_15 , V_21 , V_48 ) ;
return - V_26 ;
}
V_52 = strcspn ( V_7 , L_16 ) ;
V_51 = V_7 [ V_52 ] ;
( ( char * ) V_7 ) [ V_52 ] = '\0' ;
F_36 ( ! F_37 ( & V_28 ) ) ;
V_35 = V_27 ( V_7 , & V_38 ) ;
if ( V_35 != 0 )
return V_35 ;
V_38 . V_39 += V_50 ;
V_7 += V_52 + 1 ;
( * V_34 ) ++ ;
} while ( V_51 == ',' );
if ( * V_34 < V_47 ) {
F_22 ( L_17 , V_21 , V_47 ) ;
return - V_26 ;
}
return 0 ;
}
static int F_38 ( const char * V_7 , const struct V_15 * V_38 )
{
const struct V_53 * V_54 = V_38 -> V_54 ;
unsigned int V_55 ;
return F_35 ( V_38 -> V_21 , V_7 , 1 , V_54 -> V_48 , V_54 -> V_49 ,
V_54 -> V_50 , V_54 -> V_23 -> V_27 , V_38 -> V_22 ,
V_54 -> V_34 ? : & V_55 ) ;
}
static int F_39 ( char * V_41 , const struct V_15 * V_38 )
{
int V_13 , V_56 , V_35 ;
const struct V_53 * V_54 = V_38 -> V_54 ;
struct V_15 V_3 ;
V_3 = * V_38 ;
for ( V_13 = V_56 = 0 ; V_13 < ( V_54 -> V_34 ? * V_54 -> V_34 : V_54 -> V_48 ) ; V_13 ++ ) {
if ( V_13 )
V_41 [ V_56 ++ ] = ',' ;
V_3 . V_39 = V_54 -> V_49 + V_54 -> V_50 * V_13 ;
F_36 ( ! F_37 ( & V_28 ) ) ;
V_35 = V_54 -> V_23 -> V_57 ( V_41 + V_56 , & V_3 ) ;
if ( V_35 < 0 )
return V_35 ;
V_56 += V_35 ;
}
V_41 [ V_56 ] = '\0' ;
return V_56 ;
}
static void F_40 ( void * V_39 )
{
unsigned int V_13 ;
const struct V_53 * V_54 = V_39 ;
if ( V_54 -> V_23 -> free )
for ( V_13 = 0 ; V_13 < ( V_54 -> V_34 ? * V_54 -> V_34 : V_54 -> V_48 ) ; V_13 ++ )
V_54 -> V_23 -> free ( V_54 -> V_49 + V_54 -> V_50 * V_13 ) ;
}
int F_41 ( const char * V_7 , const struct V_15 * V_38 )
{
const struct V_58 * V_59 = V_38 -> V_60 ;
if ( strlen ( V_7 ) + 1 > V_59 -> V_61 ) {
F_22 ( L_18 ,
V_38 -> V_21 , V_59 -> V_61 - 1 ) ;
return - V_37 ;
}
strcpy ( V_59 -> string , V_7 ) ;
return 0 ;
}
int F_42 ( char * V_41 , const struct V_15 * V_38 )
{
const struct V_58 * V_59 = V_38 -> V_60 ;
return F_43 ( V_41 , V_59 -> string , V_59 -> V_61 ) ;
}
static T_3 F_44 ( struct V_62 * V_63 ,
struct V_64 * V_65 , char * V_66 )
{
int V_67 ;
struct V_68 * V_69 = F_45 ( V_63 ) ;
if ( ! V_69 -> V_8 -> V_23 -> V_57 )
return - V_70 ;
F_14 ( & V_28 ) ;
V_67 = V_69 -> V_8 -> V_23 -> V_57 ( V_66 , V_69 -> V_8 ) ;
F_15 ( & V_28 ) ;
if ( V_67 > 0 ) {
strcat ( V_66 , L_19 ) ;
++ V_67 ;
}
return V_67 ;
}
static T_3 F_46 ( struct V_62 * V_63 ,
struct V_64 * V_71 ,
const char * V_66 , T_1 V_52 )
{
int V_20 ;
struct V_68 * V_69 = F_45 ( V_63 ) ;
if ( ! V_69 -> V_8 -> V_23 -> V_27 )
return - V_70 ;
F_14 ( & V_28 ) ;
V_20 = V_69 -> V_8 -> V_23 -> V_27 ( V_66 , V_69 -> V_8 ) ;
F_15 ( & V_28 ) ;
if ( ! V_20 )
return V_52 ;
return V_20 ;
}
void F_47 ( void )
{
F_14 ( & V_28 ) ;
}
void F_48 ( void )
{
F_15 ( & V_28 ) ;
}
static T_4 int F_49 ( struct V_64 * V_65 ,
const struct V_15 * V_38 ,
const char * V_21 )
{
struct V_72 * V_73 ;
struct V_69 * * V_74 ;
int V_20 , V_34 ;
F_36 ( ! V_38 -> V_75 ) ;
if ( ! V_65 -> V_76 ) {
V_34 = 0 ;
V_74 = NULL ;
} else {
V_34 = V_65 -> V_76 -> V_34 ;
V_74 = V_65 -> V_76 -> V_77 . V_74 ;
}
V_73 = F_50 ( V_65 -> V_76 ,
sizeof( * V_65 -> V_76 ) + sizeof( V_65 -> V_76 -> V_74 [ 0 ] ) * ( V_34 + 1 ) ,
V_4 ) ;
if ( ! V_73 ) {
F_7 ( V_74 ) ;
V_20 = - V_40 ;
goto V_78;
}
V_74 = F_50 ( V_74 , sizeof( V_73 -> V_77 . V_74 [ 0 ] ) * ( V_34 + 2 ) , V_4 ) ;
if ( ! V_74 ) {
V_20 = - V_40 ;
goto V_79;
}
memset ( V_73 , 0 , sizeof( * V_73 ) ) ;
memset ( & V_73 -> V_74 [ V_34 ] , 0 , sizeof( V_73 -> V_74 [ V_34 ] ) ) ;
memset ( & V_74 [ V_34 ] , 0 , sizeof( V_74 [ V_34 ] ) ) ;
V_73 -> V_77 . V_21 = L_20 ;
V_73 -> V_77 . V_74 = V_74 ;
F_51 ( & V_73 -> V_74 [ V_34 ] . V_63 . V_80 ) ;
V_73 -> V_74 [ V_34 ] . V_8 = V_38 ;
V_73 -> V_74 [ V_34 ] . V_63 . V_81 = F_44 ;
V_73 -> V_74 [ V_34 ] . V_63 . V_82 = F_46 ;
V_73 -> V_74 [ V_34 ] . V_63 . V_80 . V_21 = ( char * ) V_21 ;
V_73 -> V_74 [ V_34 ] . V_63 . V_80 . V_83 = V_38 -> V_75 ;
V_73 -> V_34 = V_34 + 1 ;
for ( V_34 = 0 ; V_34 < V_73 -> V_34 ; V_34 ++ )
V_73 -> V_77 . V_74 [ V_34 ] = & V_73 -> V_74 [ V_34 ] . V_63 . V_80 ;
V_73 -> V_77 . V_74 [ V_34 ] = NULL ;
V_65 -> V_76 = V_73 ;
return 0 ;
V_79:
F_7 ( V_73 ) ;
V_78:
V_65 -> V_76 = NULL ;
return V_20 ;
}
static void F_52 ( struct V_64 * V_65 )
{
F_7 ( V_65 -> V_76 -> V_77 . V_74 ) ;
F_7 ( V_65 -> V_76 ) ;
V_65 -> V_76 = NULL ;
}
int F_53 ( struct V_84 * V_85 ,
const struct V_15 * V_86 ,
unsigned int V_17 )
{
int V_13 , V_20 ;
bool V_16 = false ;
for ( V_13 = 0 ; V_13 < V_17 ; V_13 ++ ) {
if ( V_86 [ V_13 ] . V_75 == 0 )
continue;
V_20 = F_49 ( & V_85 -> V_87 , & V_86 [ V_13 ] , V_86 [ V_13 ] . V_21 ) ;
if ( V_20 )
return V_20 ;
V_16 = true ;
}
if ( ! V_16 )
return 0 ;
V_20 = F_54 ( & V_85 -> V_87 . V_88 , & V_85 -> V_87 . V_76 -> V_77 ) ;
if ( V_20 )
F_52 ( & V_85 -> V_87 ) ;
return V_20 ;
}
void F_55 ( struct V_84 * V_85 )
{
if ( V_85 -> V_87 . V_76 ) {
F_56 ( & V_85 -> V_87 . V_88 , & V_85 -> V_87 . V_76 -> V_77 ) ;
F_52 ( & V_85 -> V_87 ) ;
}
}
void F_57 ( const struct V_15 * V_16 , unsigned V_34 )
{
unsigned int V_13 ;
for ( V_13 = 0 ; V_13 < V_34 ; V_13 ++ )
if ( V_16 [ V_13 ] . V_23 -> free )
V_16 [ V_13 ] . V_23 -> free ( V_16 [ V_13 ] . V_39 ) ;
}
static struct V_64 * T_5 F_58 ( const char * V_21 )
{
struct V_64 * V_65 ;
struct V_89 * V_88 ;
int V_20 ;
V_88 = F_59 ( V_90 , V_21 ) ;
if ( V_88 ) {
V_65 = F_60 ( V_88 ) ;
} else {
V_65 = F_61 ( sizeof( struct V_64 ) , V_4 ) ;
F_36 ( ! V_65 ) ;
V_65 -> V_85 = V_91 ;
V_65 -> V_88 . V_92 = V_90 ;
V_20 = F_62 ( & V_65 -> V_88 , & V_93 , NULL ,
L_12 , V_21 ) ;
#ifdef F_63
if ( ! V_20 )
V_20 = F_64 ( & V_65 -> V_88 , & V_94 . V_80 ) ;
#endif
if ( V_20 ) {
F_65 ( & V_65 -> V_88 ) ;
F_66 ( L_21 ,
V_21 , V_20 ) ;
return NULL ;
}
F_67 ( & V_65 -> V_88 ) ;
}
return V_65 ;
}
static void T_5 F_68 ( const char * V_21 ,
struct V_15 * V_86 ,
unsigned int V_95 )
{
struct V_64 * V_65 ;
int V_20 ;
V_65 = F_58 ( V_21 ) ;
if ( ! V_65 )
return;
if ( V_65 -> V_76 )
F_56 ( & V_65 -> V_88 , & V_65 -> V_76 -> V_77 ) ;
V_20 = F_49 ( V_65 , V_86 , V_86 -> V_21 + V_95 ) ;
F_36 ( V_20 ) ;
V_20 = F_54 ( & V_65 -> V_88 , & V_65 -> V_76 -> V_77 ) ;
F_36 ( V_20 ) ;
F_69 ( & V_65 -> V_88 , V_96 ) ;
F_65 ( & V_65 -> V_88 ) ;
}
static void T_5 F_70 ( void )
{
struct V_15 * V_38 ;
unsigned int V_97 ;
char V_98 [ V_99 ] ;
for ( V_38 = V_100 ; V_38 < V_101 ; V_38 ++ ) {
char * V_102 ;
if ( V_38 -> V_75 == 0 )
continue;
V_102 = strchr ( V_38 -> V_21 , '.' ) ;
if ( ! V_102 ) {
strcpy ( V_98 , L_22 ) ;
V_97 = 0 ;
} else {
V_97 = V_102 - V_38 -> V_21 + 1 ;
F_43 ( V_98 , V_38 -> V_21 , V_97 ) ;
}
F_68 ( V_98 , V_38 , V_97 ) ;
}
}
T_3 F_71 ( struct V_62 * V_63 ,
struct V_64 * V_65 , char * V_66 )
{
struct V_103 * V_104 =
F_72 ( V_63 , struct V_103 , V_63 ) ;
return F_27 ( V_66 , V_42 , L_23 , V_104 -> V_105 ) ;
}
static void T_5 F_73 ( void )
{
const struct V_103 * * V_3 ;
struct V_64 * V_65 ;
int V_20 ;
for ( V_3 = V_106 ; V_3 < V_107 ; V_3 ++ ) {
const struct V_103 * V_104 = * V_3 ;
V_65 = F_58 ( V_104 -> V_108 ) ;
if ( V_65 ) {
V_20 = F_64 ( & V_65 -> V_88 , & V_104 -> V_63 . V_80 ) ;
F_69 ( & V_65 -> V_88 , V_96 ) ;
F_65 ( & V_65 -> V_88 ) ;
}
}
}
static T_3 F_74 ( struct V_89 * V_88 ,
struct V_69 * V_80 ,
char * V_66 )
{
struct V_62 * V_69 ;
struct V_64 * V_65 ;
int V_35 ;
V_69 = F_75 ( V_80 ) ;
V_65 = F_60 ( V_88 ) ;
if ( ! V_69 -> V_81 )
return - V_109 ;
V_35 = V_69 -> V_81 ( V_69 , V_65 , V_66 ) ;
return V_35 ;
}
static T_3 F_76 ( struct V_89 * V_88 ,
struct V_69 * V_80 ,
const char * V_66 , T_1 V_52 )
{
struct V_62 * V_69 ;
struct V_64 * V_65 ;
int V_35 ;
V_69 = F_75 ( V_80 ) ;
V_65 = F_60 ( V_88 ) ;
if ( ! V_69 -> V_82 )
return - V_109 ;
V_35 = V_69 -> V_82 ( V_69 , V_65 , V_66 , V_52 ) ;
return V_35 ;
}
static int F_77 ( struct V_92 * V_92 , struct V_89 * V_88 )
{
struct V_110 * V_111 = F_78 ( V_88 ) ;
if ( V_111 == & V_93 )
return 1 ;
return 0 ;
}
static void F_79 ( struct V_89 * V_88 )
{
struct V_64 * V_65 = F_60 ( V_88 ) ;
F_80 ( V_65 -> V_112 ) ;
}
static int T_5 F_81 ( void )
{
V_90 = F_82 ( L_24 , & V_113 , NULL ) ;
if ( ! V_90 ) {
F_83 ( V_114 L_25 ,
__FILE__ , __LINE__ ) ;
return - V_40 ;
}
V_115 = 1 ;
F_73 () ;
F_70 () ;
return 0 ;
}
