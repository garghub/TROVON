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
if ( ! V_7 && V_15 [ V_13 ] . V_19 -> V_20 != V_21
&& V_15 [ V_13 ] . V_19 -> V_20 != V_22 )
return - V_23 ;
F_13 ( L_1 ,
V_15 [ V_13 ] . V_19 -> V_20 ) ;
F_14 ( & V_24 ) ;
V_17 = V_15 [ V_13 ] . V_19 -> V_20 ( V_7 , & V_15 [ V_13 ] ) ;
F_15 ( & V_24 ) ;
return V_17 ;
}
}
if ( F_12 ) {
F_13 ( L_2 , F_12 ) ;
return F_12 ( V_8 , V_7 ) ;
}
F_13 ( L_3 , V_8 ) ;
return - V_25 ;
}
static char * F_16 ( char * args , char * * V_8 , char * * V_7 )
{
unsigned int V_13 , V_26 = 0 ;
int V_27 = 0 , V_28 = 0 ;
char * V_29 ;
if ( * args == '"' ) {
args ++ ;
V_27 = 1 ;
V_28 = 1 ;
}
for ( V_13 = 0 ; args [ V_13 ] ; V_13 ++ ) {
if ( isspace ( args [ V_13 ] ) && ! V_27 )
break;
if ( V_26 == 0 ) {
if ( args [ V_13 ] == '=' )
V_26 = V_13 ;
}
if ( args [ V_13 ] == '"' )
V_27 = ! V_27 ;
}
* V_8 = args ;
if ( ! V_26 )
* V_7 = NULL ;
else {
args [ V_26 ] = '\0' ;
* V_7 = args + V_26 + 1 ;
if ( * * V_7 == '"' ) {
( * V_7 ) ++ ;
if ( args [ V_13 - 1 ] == '"' )
args [ V_13 - 1 ] = '\0' ;
}
if ( V_28 && args [ V_13 - 1 ] == '"' )
args [ V_13 - 1 ] = '\0' ;
}
if ( args [ V_13 ] ) {
args [ V_13 ] = '\0' ;
V_29 = args + V_13 + 1 ;
} else
V_29 = args + V_13 ;
return F_17 ( V_29 ) ;
}
int F_18 ( const char * V_18 ,
char * args ,
const struct V_14 * V_15 ,
unsigned V_30 ,
int (* F_19)( char * V_8 , char * V_7 ) )
{
char * V_8 , * V_7 ;
F_13 ( L_4 , args ) ;
args = F_17 ( args ) ;
while ( * args ) {
int V_31 ;
int V_32 ;
args = F_16 ( args , & V_8 , & V_7 ) ;
V_32 = F_20 () ;
V_31 = F_11 ( V_8 , V_7 , V_15 , V_30 , F_19 ) ;
if ( V_32 && ! F_20 () ) {
F_21 ( V_33 L_5
L_6 , V_8 ) ;
}
switch ( V_31 ) {
case - V_25 :
F_21 ( V_34 L_7 ,
V_18 , V_8 ) ;
return V_31 ;
case - V_35 :
F_21 ( V_34
L_8 ,
V_18 , V_7 ? : L_9 , V_8 ) ;
return V_31 ;
case 0 :
break;
default:
F_21 ( V_34
L_10 ,
V_18 , V_7 ? : L_9 , V_8 ) ;
return V_31 ;
}
}
return 0 ;
}
int F_22 ( const char * V_7 , const struct V_14 * V_36 )
{
if ( strlen ( V_7 ) > 1024 ) {
F_21 ( V_34 L_11 ,
V_36 -> V_18 ) ;
return - V_35 ;
}
F_4 ( * ( char * * ) V_36 -> V_37 ) ;
if ( F_23 () ) {
* ( char * * ) V_36 -> V_37 = F_1 ( strlen ( V_7 ) + 1 ) ;
if ( ! * ( char * * ) V_36 -> V_37 )
return - V_38 ;
strcpy ( * ( char * * ) V_36 -> V_37 , V_7 ) ;
} else
* ( const char * * ) V_36 -> V_37 = V_7 ;
return 0 ;
}
int F_24 ( char * V_39 , const struct V_14 * V_36 )
{
return sprintf ( V_39 , L_12 , * ( ( char * * ) V_36 -> V_37 ) ) ;
}
static void F_25 ( void * V_37 )
{
F_4 ( * ( ( char * * ) V_37 ) ) ;
}
int V_21 ( const char * V_7 , const struct V_14 * V_36 )
{
bool V_40 ;
int V_31 ;
if ( ! V_7 ) V_7 = L_13 ;
V_31 = F_26 ( V_7 , & V_40 ) ;
if ( V_31 )
return V_31 ;
if ( V_36 -> V_41 & V_42 )
* ( bool * ) V_36 -> V_37 = V_40 ;
else
* ( int * ) V_36 -> V_37 = V_40 ;
return 0 ;
}
int F_27 ( char * V_39 , const struct V_14 * V_36 )
{
bool V_7 ;
if ( V_36 -> V_41 & V_42 )
V_7 = * ( bool * ) V_36 -> V_37 ;
else
V_7 = * ( int * ) V_36 -> V_37 ;
return sprintf ( V_39 , L_14 , V_7 ? 'Y' : 'N' ) ;
}
int F_28 ( const char * V_7 , const struct V_14 * V_36 )
{
int V_31 ;
bool V_43 ;
struct V_14 V_44 ;
V_44 . V_37 = & V_43 ;
V_44 . V_41 = V_42 ;
V_31 = V_21 ( V_7 , & V_44 ) ;
if ( V_31 == 0 )
* ( bool * ) V_36 -> V_37 = ! V_43 ;
return V_31 ;
}
int F_29 ( char * V_39 , const struct V_14 * V_36 )
{
return sprintf ( V_39 , L_14 , ( * ( bool * ) V_36 -> V_37 ) ? 'N' : 'Y' ) ;
}
int V_22 ( const char * V_7 , const struct V_14 * V_36 )
{
struct V_14 V_45 ;
bool V_40 ;
int V_31 ;
V_45 = * V_36 ;
V_45 . V_37 = & V_40 ;
V_45 . V_41 |= V_42 ;
V_31 = V_21 ( V_7 , & V_45 ) ;
if ( V_31 == 0 )
* ( int * ) V_36 -> V_37 = V_40 ;
return V_31 ;
}
static int F_30 ( const char * V_18 ,
const char * V_7 ,
unsigned int V_46 , unsigned int V_47 ,
void * V_48 , int V_49 ,
int (* V_20)( const char * , const struct V_14 * V_36 ) ,
T_2 V_41 ,
unsigned int * V_30 )
{
int V_31 ;
struct V_14 V_36 ;
char V_50 ;
V_36 . V_18 = V_18 ;
V_36 . V_37 = V_48 ;
V_36 . V_41 = V_41 ;
* V_30 = 0 ;
do {
int V_51 ;
if ( * V_30 == V_47 ) {
F_21 ( V_34 L_15 ,
V_18 , V_47 ) ;
return - V_23 ;
}
V_51 = strcspn ( V_7 , L_16 ) ;
V_50 = V_7 [ V_51 ] ;
( ( char * ) V_7 ) [ V_51 ] = '\0' ;
F_31 ( ! F_32 ( & V_24 ) ) ;
V_31 = V_20 ( V_7 , & V_36 ) ;
if ( V_31 != 0 )
return V_31 ;
V_36 . V_37 += V_49 ;
V_7 += V_51 + 1 ;
( * V_30 ) ++ ;
} while ( V_50 == ',' );
if ( * V_30 < V_46 ) {
F_21 ( V_34 L_17 ,
V_18 , V_46 ) ;
return - V_23 ;
}
return 0 ;
}
static int F_33 ( const char * V_7 , const struct V_14 * V_36 )
{
const struct V_52 * V_53 = V_36 -> V_53 ;
unsigned int V_54 ;
return F_30 ( V_36 -> V_18 , V_7 , 1 , V_53 -> V_47 , V_53 -> V_48 ,
V_53 -> V_49 , V_53 -> V_19 -> V_20 , V_36 -> V_41 ,
V_53 -> V_30 ? : & V_54 ) ;
}
static int F_34 ( char * V_39 , const struct V_14 * V_36 )
{
int V_13 , V_55 , V_31 ;
const struct V_52 * V_53 = V_36 -> V_53 ;
struct V_14 V_3 ;
V_3 = * V_36 ;
for ( V_13 = V_55 = 0 ; V_13 < ( V_53 -> V_30 ? * V_53 -> V_30 : V_53 -> V_47 ) ; V_13 ++ ) {
if ( V_13 )
V_39 [ V_55 ++ ] = ',' ;
V_3 . V_37 = V_53 -> V_48 + V_53 -> V_49 * V_13 ;
F_31 ( ! F_32 ( & V_24 ) ) ;
V_31 = V_53 -> V_19 -> V_56 ( V_39 + V_55 , & V_3 ) ;
if ( V_31 < 0 )
return V_31 ;
V_55 += V_31 ;
}
V_39 [ V_55 ] = '\0' ;
return V_55 ;
}
static void F_35 ( void * V_37 )
{
unsigned int V_13 ;
const struct V_52 * V_53 = V_37 ;
if ( V_53 -> V_19 -> free )
for ( V_13 = 0 ; V_13 < ( V_53 -> V_30 ? * V_53 -> V_30 : V_53 -> V_47 ) ; V_13 ++ )
V_53 -> V_19 -> free ( V_53 -> V_48 + V_53 -> V_49 * V_13 ) ;
}
int F_36 ( const char * V_7 , const struct V_14 * V_36 )
{
const struct V_57 * V_58 = V_36 -> V_59 ;
if ( strlen ( V_7 ) + 1 > V_58 -> V_60 ) {
F_21 ( V_34 L_18 ,
V_36 -> V_18 , V_58 -> V_60 - 1 ) ;
return - V_35 ;
}
strcpy ( V_58 -> string , V_7 ) ;
return 0 ;
}
int F_37 ( char * V_39 , const struct V_14 * V_36 )
{
const struct V_57 * V_58 = V_36 -> V_59 ;
return F_38 ( V_39 , V_58 -> string , V_58 -> V_60 ) ;
}
static T_3 F_39 ( struct V_61 * V_62 ,
struct V_63 * V_64 , char * V_65 )
{
int V_66 ;
struct V_67 * V_68 = F_40 ( V_62 ) ;
if ( ! V_68 -> V_8 -> V_19 -> V_56 )
return - V_69 ;
F_14 ( & V_24 ) ;
V_66 = V_68 -> V_8 -> V_19 -> V_56 ( V_65 , V_68 -> V_8 ) ;
F_15 ( & V_24 ) ;
if ( V_66 > 0 ) {
strcat ( V_65 , L_19 ) ;
++ V_66 ;
}
return V_66 ;
}
static T_3 F_41 ( struct V_61 * V_62 ,
struct V_63 * V_70 ,
const char * V_65 , T_1 V_51 )
{
int V_17 ;
struct V_67 * V_68 = F_40 ( V_62 ) ;
if ( ! V_68 -> V_8 -> V_19 -> V_20 )
return - V_69 ;
F_14 ( & V_24 ) ;
V_17 = V_68 -> V_8 -> V_19 -> V_20 ( V_65 , V_68 -> V_8 ) ;
F_15 ( & V_24 ) ;
if ( ! V_17 )
return V_51 ;
return V_17 ;
}
void F_42 ( void )
{
F_14 ( & V_24 ) ;
}
void F_43 ( void )
{
F_15 ( & V_24 ) ;
}
static T_4 int F_44 ( struct V_63 * V_64 ,
const struct V_14 * V_36 ,
const char * V_18 )
{
struct V_71 * V_72 ;
struct V_68 * * V_73 ;
int V_17 , V_30 ;
F_31 ( ! V_36 -> V_74 ) ;
if ( ! V_64 -> V_75 ) {
V_30 = 0 ;
V_73 = NULL ;
} else {
V_30 = V_64 -> V_75 -> V_30 ;
V_73 = V_64 -> V_75 -> V_76 . V_73 ;
}
V_72 = F_45 ( V_64 -> V_75 ,
sizeof( * V_64 -> V_75 ) + sizeof( V_64 -> V_75 -> V_73 [ 0 ] ) * ( V_30 + 1 ) ,
V_4 ) ;
if ( ! V_72 ) {
F_7 ( V_64 -> V_75 ) ;
V_17 = - V_38 ;
goto V_77;
}
V_73 = F_45 ( V_73 , sizeof( V_72 -> V_76 . V_73 [ 0 ] ) * ( V_30 + 2 ) , V_4 ) ;
if ( ! V_73 ) {
V_17 = - V_38 ;
goto V_78;
}
memset ( V_72 , 0 , sizeof( * V_72 ) ) ;
memset ( & V_72 -> V_73 [ V_30 ] , 0 , sizeof( V_72 -> V_73 [ V_30 ] ) ) ;
memset ( & V_73 [ V_30 ] , 0 , sizeof( V_73 [ V_30 ] ) ) ;
V_72 -> V_76 . V_18 = L_20 ;
V_72 -> V_76 . V_73 = V_73 ;
F_46 ( & V_72 -> V_73 [ V_30 ] . V_62 . V_79 ) ;
V_72 -> V_73 [ V_30 ] . V_8 = V_36 ;
V_72 -> V_73 [ V_30 ] . V_62 . V_80 = F_39 ;
V_72 -> V_73 [ V_30 ] . V_62 . V_81 = F_41 ;
V_72 -> V_73 [ V_30 ] . V_62 . V_79 . V_18 = ( char * ) V_18 ;
V_72 -> V_73 [ V_30 ] . V_62 . V_79 . V_82 = V_36 -> V_74 ;
V_72 -> V_30 = V_30 + 1 ;
for ( V_30 = 0 ; V_30 < V_72 -> V_30 ; V_30 ++ )
V_72 -> V_76 . V_73 [ V_30 ] = & V_72 -> V_73 [ V_30 ] . V_62 . V_79 ;
V_72 -> V_76 . V_73 [ V_30 ] = NULL ;
V_64 -> V_75 = V_72 ;
return 0 ;
V_78:
F_7 ( V_72 ) ;
V_77:
V_64 -> V_75 = NULL ;
return V_17 ;
}
static void F_47 ( struct V_63 * V_64 )
{
F_7 ( V_64 -> V_75 -> V_76 . V_73 ) ;
F_7 ( V_64 -> V_75 ) ;
V_64 -> V_75 = NULL ;
}
int F_48 ( struct V_83 * V_84 ,
const struct V_14 * V_85 ,
unsigned int V_16 )
{
int V_13 , V_17 ;
bool V_15 = false ;
for ( V_13 = 0 ; V_13 < V_16 ; V_13 ++ ) {
if ( V_85 [ V_13 ] . V_74 == 0 )
continue;
V_17 = F_44 ( & V_84 -> V_86 , & V_85 [ V_13 ] , V_85 [ V_13 ] . V_18 ) ;
if ( V_17 )
return V_17 ;
V_15 = true ;
}
if ( ! V_15 )
return 0 ;
V_17 = F_49 ( & V_84 -> V_86 . V_87 , & V_84 -> V_86 . V_75 -> V_76 ) ;
if ( V_17 )
F_47 ( & V_84 -> V_86 ) ;
return V_17 ;
}
void F_50 ( struct V_83 * V_84 )
{
if ( V_84 -> V_86 . V_75 ) {
F_51 ( & V_84 -> V_86 . V_87 , & V_84 -> V_86 . V_75 -> V_76 ) ;
F_47 ( & V_84 -> V_86 ) ;
}
}
void F_52 ( const struct V_14 * V_15 , unsigned V_30 )
{
unsigned int V_13 ;
for ( V_13 = 0 ; V_13 < V_30 ; V_13 ++ )
if ( V_15 [ V_13 ] . V_19 -> free )
V_15 [ V_13 ] . V_19 -> free ( V_15 [ V_13 ] . V_37 ) ;
}
static struct V_63 * T_5 F_53 ( const char * V_18 )
{
struct V_63 * V_64 ;
struct V_88 * V_87 ;
int V_17 ;
V_87 = F_54 ( V_89 , V_18 ) ;
if ( V_87 ) {
V_64 = F_55 ( V_87 ) ;
} else {
V_64 = F_56 ( sizeof( struct V_63 ) , V_4 ) ;
F_31 ( ! V_64 ) ;
V_64 -> V_84 = V_90 ;
V_64 -> V_87 . V_91 = V_89 ;
V_17 = F_57 ( & V_64 -> V_87 , & V_92 , NULL ,
L_12 , V_18 ) ;
#ifdef F_58
if ( ! V_17 )
V_17 = F_59 ( & V_64 -> V_87 , & V_93 . V_79 ) ;
#endif
if ( V_17 ) {
F_60 ( & V_64 -> V_87 ) ;
F_21 ( V_34
L_21 ,
V_18 , V_17 ) ;
F_21 ( V_34
L_22 ) ;
return NULL ;
}
F_61 ( & V_64 -> V_87 ) ;
}
return V_64 ;
}
static void T_5 F_62 ( const char * V_18 ,
struct V_14 * V_85 ,
unsigned int V_94 )
{
struct V_63 * V_64 ;
int V_17 ;
V_64 = F_53 ( V_18 ) ;
if ( ! V_64 )
return;
if ( V_64 -> V_75 )
F_51 ( & V_64 -> V_87 , & V_64 -> V_75 -> V_76 ) ;
V_17 = F_44 ( V_64 , V_85 , V_85 -> V_18 + V_94 ) ;
F_31 ( V_17 ) ;
V_17 = F_49 ( & V_64 -> V_87 , & V_64 -> V_75 -> V_76 ) ;
F_31 ( V_17 ) ;
F_63 ( & V_64 -> V_87 , V_95 ) ;
F_60 ( & V_64 -> V_87 ) ;
}
static void T_5 F_64 ( void )
{
struct V_14 * V_36 ;
unsigned int V_96 ;
char V_97 [ V_98 ] ;
for ( V_36 = V_99 ; V_36 < V_100 ; V_36 ++ ) {
char * V_101 ;
if ( V_36 -> V_74 == 0 )
continue;
V_101 = strchr ( V_36 -> V_18 , '.' ) ;
if ( ! V_101 ) {
strcpy ( V_97 , L_23 ) ;
V_96 = 0 ;
} else {
V_96 = V_101 - V_36 -> V_18 + 1 ;
F_38 ( V_97 , V_36 -> V_18 , V_96 ) ;
}
F_62 ( V_97 , V_36 , V_96 ) ;
}
}
T_3 F_65 ( struct V_61 * V_62 ,
struct V_63 * V_64 , char * V_65 )
{
struct V_102 * V_103 =
F_66 ( V_62 , struct V_102 , V_62 ) ;
return sprintf ( V_65 , L_24 , V_103 -> V_104 ) ;
}
static void T_5 F_67 ( void )
{
const struct V_102 * * V_3 ;
struct V_63 * V_64 ;
int V_17 ;
for ( V_3 = V_105 ; V_3 < V_106 ; V_3 ++ ) {
const struct V_102 * V_103 = * V_3 ;
V_64 = F_53 ( V_103 -> V_107 ) ;
if ( V_64 ) {
V_17 = F_59 ( & V_64 -> V_87 , & V_103 -> V_62 . V_79 ) ;
F_63 ( & V_64 -> V_87 , V_95 ) ;
F_60 ( & V_64 -> V_87 ) ;
}
}
}
static T_3 F_68 ( struct V_88 * V_87 ,
struct V_68 * V_79 ,
char * V_65 )
{
struct V_61 * V_68 ;
struct V_63 * V_64 ;
int V_31 ;
V_68 = F_69 ( V_79 ) ;
V_64 = F_55 ( V_87 ) ;
if ( ! V_68 -> V_80 )
return - V_108 ;
V_31 = V_68 -> V_80 ( V_68 , V_64 , V_65 ) ;
return V_31 ;
}
static T_3 F_70 ( struct V_88 * V_87 ,
struct V_68 * V_79 ,
const char * V_65 , T_1 V_51 )
{
struct V_61 * V_68 ;
struct V_63 * V_64 ;
int V_31 ;
V_68 = F_69 ( V_79 ) ;
V_64 = F_55 ( V_87 ) ;
if ( ! V_68 -> V_81 )
return - V_108 ;
V_31 = V_68 -> V_81 ( V_68 , V_64 , V_65 , V_51 ) ;
return V_31 ;
}
static int F_71 ( struct V_91 * V_91 , struct V_88 * V_87 )
{
struct V_109 * V_110 = F_72 ( V_87 ) ;
if ( V_110 == & V_92 )
return 1 ;
return 0 ;
}
static int T_5 F_73 ( void )
{
V_89 = F_74 ( L_25 , & V_111 , NULL ) ;
if ( ! V_89 ) {
F_21 ( V_33 L_26 ,
__FILE__ , __LINE__ ) ;
return - V_38 ;
}
V_112 = 1 ;
F_67 () ;
F_64 () ;
return 0 ;
}
