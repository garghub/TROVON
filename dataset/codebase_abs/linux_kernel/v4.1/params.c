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
static void F_11 ( const struct V_14 * V_15 )
{
if ( V_15 -> V_16 & V_17 ) {
F_12 ( L_1 ,
V_15 -> V_18 ) ;
F_13 ( V_19 , V_20 ) ;
}
}
static int F_14 ( char * V_8 ,
char * V_7 ,
const char * V_21 ,
const struct V_14 * V_22 ,
unsigned V_23 ,
T_2 V_24 ,
T_2 V_25 ,
int (* F_15)( char * V_8 , char * V_7 ,
const char * V_21 ) )
{
unsigned int V_13 ;
int V_26 ;
for ( V_13 = 0 ; V_13 < V_23 ; V_13 ++ ) {
if ( F_10 ( V_8 , V_22 [ V_13 ] . V_18 ) ) {
if ( V_22 [ V_13 ] . V_27 < V_24
|| V_22 [ V_13 ] . V_27 > V_25 )
return 0 ;
if ( ! V_7 &&
! ( V_22 [ V_13 ] . V_28 -> V_16 & V_29 ) )
return - V_30 ;
F_16 ( L_2 , V_8 ,
V_22 [ V_13 ] . V_28 -> V_31 ) ;
F_17 ( & V_32 ) ;
F_11 ( & V_22 [ V_13 ] ) ;
V_26 = V_22 [ V_13 ] . V_28 -> V_31 ( V_7 , & V_22 [ V_13 ] ) ;
F_18 ( & V_32 ) ;
return V_26 ;
}
}
if ( F_15 ) {
F_16 ( L_3 , V_21 , V_8 , V_7 ) ;
return F_15 ( V_8 , V_7 , V_21 ) ;
}
F_16 ( L_4 , V_8 ) ;
return - V_33 ;
}
static char * F_19 ( char * args , char * * V_8 , char * * V_7 )
{
unsigned int V_13 , V_34 = 0 ;
int V_35 = 0 , V_36 = 0 ;
char * V_37 ;
if ( * args == '"' ) {
args ++ ;
V_35 = 1 ;
V_36 = 1 ;
}
for ( V_13 = 0 ; args [ V_13 ] ; V_13 ++ ) {
if ( isspace ( args [ V_13 ] ) && ! V_35 )
break;
if ( V_34 == 0 ) {
if ( args [ V_13 ] == '=' )
V_34 = V_13 ;
}
if ( args [ V_13 ] == '"' )
V_35 = ! V_35 ;
}
* V_8 = args ;
if ( ! V_34 )
* V_7 = NULL ;
else {
args [ V_34 ] = '\0' ;
* V_7 = args + V_34 + 1 ;
if ( * * V_7 == '"' ) {
( * V_7 ) ++ ;
if ( args [ V_13 - 1 ] == '"' )
args [ V_13 - 1 ] = '\0' ;
}
}
if ( V_36 && args [ V_13 - 1 ] == '"' )
args [ V_13 - 1 ] = '\0' ;
if ( args [ V_13 ] ) {
args [ V_13 ] = '\0' ;
V_37 = args + V_13 + 1 ;
} else
V_37 = args + V_13 ;
return F_20 ( V_37 ) ;
}
char * F_21 ( const char * V_21 ,
char * args ,
const struct V_14 * V_22 ,
unsigned V_38 ,
T_2 V_24 ,
T_2 V_25 ,
int (* F_22)( char * V_8 , char * V_7 , const char * V_21 ) )
{
char * V_8 , * V_7 ;
args = F_20 ( args ) ;
if ( * args )
F_16 ( L_5 , V_21 , args ) ;
while ( * args ) {
int V_39 ;
int V_40 ;
args = F_19 ( args , & V_8 , & V_7 ) ;
if ( ! V_7 && strcmp ( V_8 , L_6 ) == 0 )
return args ;
V_40 = F_23 () ;
V_39 = F_14 ( V_8 , V_7 , V_21 , V_22 , V_38 ,
V_24 , V_25 , F_22 ) ;
if ( V_40 && ! F_23 () )
F_12 ( L_7 ,
V_21 , V_8 ) ;
switch ( V_39 ) {
case - V_33 :
F_24 ( L_8 , V_21 , V_8 ) ;
return F_25 ( V_39 ) ;
case - V_41 :
F_24 ( L_9 ,
V_21 , V_7 ? : L_10 , V_8 ) ;
return F_25 ( V_39 ) ;
case 0 :
break;
default:
F_24 ( L_11 ,
V_21 , V_7 ? : L_10 , V_8 ) ;
return F_25 ( V_39 ) ;
}
}
return NULL ;
}
int F_26 ( const char * V_7 , const struct V_14 * V_15 )
{
if ( strlen ( V_7 ) > 1024 ) {
F_24 ( L_12 , V_15 -> V_18 ) ;
return - V_41 ;
}
F_4 ( * ( char * * ) V_15 -> V_42 ) ;
if ( F_27 () ) {
* ( char * * ) V_15 -> V_42 = F_1 ( strlen ( V_7 ) + 1 ) ;
if ( ! * ( char * * ) V_15 -> V_42 )
return - V_43 ;
strcpy ( * ( char * * ) V_15 -> V_42 , V_7 ) ;
} else
* ( const char * * ) V_15 -> V_42 = V_7 ;
return 0 ;
}
int F_28 ( char * V_44 , const struct V_14 * V_15 )
{
return F_29 ( V_44 , V_45 , L_13 , * ( ( char * * ) V_15 -> V_42 ) ) ;
}
static void F_30 ( void * V_42 )
{
F_4 ( * ( ( char * * ) V_42 ) ) ;
}
int F_31 ( const char * V_7 , const struct V_14 * V_15 )
{
if ( ! V_7 ) V_7 = L_14 ;
return F_32 ( V_7 , V_15 -> V_42 ) ;
}
int F_33 ( char * V_44 , const struct V_14 * V_15 )
{
return sprintf ( V_44 , L_15 , * ( bool * ) V_15 -> V_42 ? 'Y' : 'N' ) ;
}
int F_34 ( const char * V_7 , const struct V_14 * V_15 )
{
int V_39 ;
bool V_46 ;
struct V_14 V_47 ;
V_47 . V_42 = & V_46 ;
V_39 = F_31 ( V_7 , & V_47 ) ;
if ( V_39 == 0 )
* ( bool * ) V_15 -> V_42 = ! V_46 ;
return V_39 ;
}
int F_35 ( char * V_44 , const struct V_14 * V_15 )
{
return sprintf ( V_44 , L_15 , ( * ( bool * ) V_15 -> V_42 ) ? 'N' : 'Y' ) ;
}
int F_36 ( const char * V_7 , const struct V_14 * V_15 )
{
struct V_14 V_48 ;
bool V_49 ;
int V_39 ;
V_48 = * V_15 ;
V_48 . V_42 = & V_49 ;
V_39 = F_31 ( V_7 , & V_48 ) ;
if ( V_39 == 0 )
* ( int * ) V_15 -> V_42 = V_49 ;
return V_39 ;
}
static int F_37 ( const char * V_18 ,
const char * V_7 ,
unsigned int V_50 , unsigned int V_51 ,
void * V_52 , int V_53 ,
int (* V_31)( const char * , const struct V_14 * V_15 ) ,
T_2 V_27 ,
unsigned int * V_38 )
{
int V_39 ;
struct V_14 V_15 ;
char V_54 ;
V_15 . V_18 = V_18 ;
V_15 . V_42 = V_52 ;
V_15 . V_27 = V_27 ;
* V_38 = 0 ;
do {
int V_55 ;
if ( * V_38 == V_51 ) {
F_24 ( L_16 , V_18 , V_51 ) ;
return - V_30 ;
}
V_55 = strcspn ( V_7 , L_17 ) ;
V_54 = V_7 [ V_55 ] ;
( ( char * ) V_7 ) [ V_55 ] = '\0' ;
F_38 ( ! F_39 ( & V_32 ) ) ;
V_39 = V_31 ( V_7 , & V_15 ) ;
if ( V_39 != 0 )
return V_39 ;
V_15 . V_42 += V_53 ;
V_7 += V_55 + 1 ;
( * V_38 ) ++ ;
} while ( V_54 == ',' );
if ( * V_38 < V_50 ) {
F_24 ( L_18 , V_18 , V_50 ) ;
return - V_30 ;
}
return 0 ;
}
static int F_40 ( const char * V_7 , const struct V_14 * V_15 )
{
const struct V_56 * V_57 = V_15 -> V_57 ;
unsigned int V_58 ;
return F_37 ( V_15 -> V_18 , V_7 , 1 , V_57 -> V_51 , V_57 -> V_52 ,
V_57 -> V_53 , V_57 -> V_28 -> V_31 , V_15 -> V_27 ,
V_57 -> V_38 ? : & V_58 ) ;
}
static int F_41 ( char * V_44 , const struct V_14 * V_15 )
{
int V_13 , V_59 , V_39 ;
const struct V_56 * V_57 = V_15 -> V_57 ;
struct V_14 V_3 ;
V_3 = * V_15 ;
for ( V_13 = V_59 = 0 ; V_13 < ( V_57 -> V_38 ? * V_57 -> V_38 : V_57 -> V_51 ) ; V_13 ++ ) {
if ( V_13 )
V_44 [ V_59 ++ ] = ',' ;
V_3 . V_42 = V_57 -> V_52 + V_57 -> V_53 * V_13 ;
F_38 ( ! F_39 ( & V_32 ) ) ;
V_39 = V_57 -> V_28 -> V_60 ( V_44 + V_59 , & V_3 ) ;
if ( V_39 < 0 )
return V_39 ;
V_59 += V_39 ;
}
V_44 [ V_59 ] = '\0' ;
return V_59 ;
}
static void F_42 ( void * V_42 )
{
unsigned int V_13 ;
const struct V_56 * V_57 = V_42 ;
if ( V_57 -> V_28 -> free )
for ( V_13 = 0 ; V_13 < ( V_57 -> V_38 ? * V_57 -> V_38 : V_57 -> V_51 ) ; V_13 ++ )
V_57 -> V_28 -> free ( V_57 -> V_52 + V_57 -> V_53 * V_13 ) ;
}
int F_43 ( const char * V_7 , const struct V_14 * V_15 )
{
const struct V_61 * V_62 = V_15 -> V_63 ;
if ( strlen ( V_7 ) + 1 > V_62 -> V_64 ) {
F_24 ( L_19 ,
V_15 -> V_18 , V_62 -> V_64 - 1 ) ;
return - V_41 ;
}
strcpy ( V_62 -> string , V_7 ) ;
return 0 ;
}
int F_44 ( char * V_44 , const struct V_14 * V_15 )
{
const struct V_61 * V_62 = V_15 -> V_63 ;
return F_45 ( V_44 , V_62 -> string , V_62 -> V_64 ) ;
}
static T_3 F_46 ( struct V_65 * V_66 ,
struct V_67 * V_68 , char * V_69 )
{
int V_70 ;
struct V_71 * V_72 = F_47 ( V_66 ) ;
if ( ! V_72 -> V_8 -> V_28 -> V_60 )
return - V_73 ;
F_17 ( & V_32 ) ;
V_70 = V_72 -> V_8 -> V_28 -> V_60 ( V_69 , V_72 -> V_8 ) ;
F_18 ( & V_32 ) ;
if ( V_70 > 0 ) {
strcat ( V_69 , L_20 ) ;
++ V_70 ;
}
return V_70 ;
}
static T_3 F_48 ( struct V_65 * V_66 ,
struct V_67 * V_74 ,
const char * V_69 , T_1 V_55 )
{
int V_26 ;
struct V_71 * V_72 = F_47 ( V_66 ) ;
if ( ! V_72 -> V_8 -> V_28 -> V_31 )
return - V_73 ;
F_17 ( & V_32 ) ;
F_11 ( V_72 -> V_8 ) ;
V_26 = V_72 -> V_8 -> V_28 -> V_31 ( V_69 , V_72 -> V_8 ) ;
F_18 ( & V_32 ) ;
if ( ! V_26 )
return V_55 ;
return V_26 ;
}
void F_49 ( void )
{
F_17 ( & V_32 ) ;
}
void F_50 ( void )
{
F_18 ( & V_32 ) ;
}
static T_4 int F_51 ( struct V_67 * V_68 ,
const struct V_14 * V_15 ,
const char * V_18 )
{
struct V_75 * V_76 ;
struct V_72 * * V_77 ;
unsigned int V_13 ;
F_38 ( ! V_15 -> V_78 ) ;
if ( ! V_68 -> V_79 ) {
V_68 -> V_79 = F_52 ( sizeof( * V_68 -> V_79 ) , V_4 ) ;
if ( ! V_68 -> V_79 )
return - V_43 ;
V_68 -> V_79 -> V_80 . V_18 = L_21 ;
V_68 -> V_79 -> V_80 . V_81 = F_52 ( sizeof( V_68 -> V_79 -> V_80 . V_81 [ 0 ] ) ,
V_4 ) ;
if ( ! V_68 -> V_79 -> V_80 . V_81 )
return - V_43 ;
}
V_76 = F_53 ( V_68 -> V_79 ,
sizeof( * V_68 -> V_79 ) +
sizeof( V_68 -> V_79 -> V_81 [ 0 ] ) * ( V_68 -> V_79 -> V_38 + 1 ) ,
V_4 ) ;
if ( ! V_76 )
return - V_43 ;
V_68 -> V_79 = V_76 ;
V_77 = F_53 ( V_68 -> V_79 -> V_80 . V_81 ,
sizeof( V_68 -> V_79 -> V_80 . V_81 [ 0 ] ) * ( V_68 -> V_79 -> V_38 + 2 ) ,
V_4 ) ;
if ( ! V_77 )
return - V_43 ;
V_68 -> V_79 -> V_80 . V_81 = V_77 ;
memset ( & V_68 -> V_79 -> V_81 [ V_68 -> V_79 -> V_38 ] , 0 , sizeof( V_68 -> V_79 -> V_81 [ 0 ] ) ) ;
F_54 ( & V_68 -> V_79 -> V_81 [ V_68 -> V_79 -> V_38 ] . V_66 . V_82 ) ;
V_68 -> V_79 -> V_81 [ V_68 -> V_79 -> V_38 ] . V_8 = V_15 ;
V_68 -> V_79 -> V_81 [ V_68 -> V_79 -> V_38 ] . V_66 . V_83 = F_46 ;
if ( ( V_15 -> V_78 & ( V_84 | V_85 | V_86 ) ) != 0 )
V_68 -> V_79 -> V_81 [ V_68 -> V_79 -> V_38 ] . V_66 . V_87 = F_48 ;
else
V_68 -> V_79 -> V_81 [ V_68 -> V_79 -> V_38 ] . V_66 . V_87 = NULL ;
V_68 -> V_79 -> V_81 [ V_68 -> V_79 -> V_38 ] . V_66 . V_82 . V_18 = ( char * ) V_18 ;
V_68 -> V_79 -> V_81 [ V_68 -> V_79 -> V_38 ] . V_66 . V_82 . V_88 = V_15 -> V_78 ;
V_68 -> V_79 -> V_38 ++ ;
for ( V_13 = 0 ; V_13 < V_68 -> V_79 -> V_38 ; V_13 ++ )
V_68 -> V_79 -> V_80 . V_81 [ V_13 ] = & V_68 -> V_79 -> V_81 [ V_13 ] . V_66 . V_82 ;
V_68 -> V_79 -> V_80 . V_81 [ V_68 -> V_79 -> V_38 ] = NULL ;
return 0 ;
}
static void F_55 ( struct V_67 * V_68 )
{
if ( V_68 -> V_79 )
F_7 ( V_68 -> V_79 -> V_80 . V_81 ) ;
F_7 ( V_68 -> V_79 ) ;
V_68 -> V_79 = NULL ;
}
int F_56 ( struct V_89 * V_90 ,
const struct V_14 * V_91 ,
unsigned int V_23 )
{
int V_13 , V_26 ;
bool V_22 = false ;
for ( V_13 = 0 ; V_13 < V_23 ; V_13 ++ ) {
if ( V_91 [ V_13 ] . V_78 == 0 )
continue;
V_26 = F_51 ( & V_90 -> V_92 , & V_91 [ V_13 ] , V_91 [ V_13 ] . V_18 ) ;
if ( V_26 ) {
F_55 ( & V_90 -> V_92 ) ;
return V_26 ;
}
V_22 = true ;
}
if ( ! V_22 )
return 0 ;
V_26 = F_57 ( & V_90 -> V_92 . V_93 , & V_90 -> V_92 . V_79 -> V_80 ) ;
if ( V_26 )
F_55 ( & V_90 -> V_92 ) ;
return V_26 ;
}
void F_58 ( struct V_89 * V_90 )
{
if ( V_90 -> V_92 . V_79 ) {
F_59 ( & V_90 -> V_92 . V_93 , & V_90 -> V_92 . V_79 -> V_80 ) ;
F_55 ( & V_90 -> V_92 ) ;
}
}
void F_60 ( const struct V_14 * V_22 , unsigned V_38 )
{
unsigned int V_13 ;
for ( V_13 = 0 ; V_13 < V_38 ; V_13 ++ )
if ( V_22 [ V_13 ] . V_28 -> free )
V_22 [ V_13 ] . V_28 -> free ( V_22 [ V_13 ] . V_42 ) ;
}
static struct V_67 * T_5 F_61 ( const char * V_18 )
{
struct V_67 * V_68 ;
struct V_94 * V_93 ;
int V_26 ;
V_93 = F_62 ( V_95 , V_18 ) ;
if ( V_93 ) {
V_68 = F_63 ( V_93 ) ;
} else {
V_68 = F_52 ( sizeof( struct V_67 ) , V_4 ) ;
F_38 ( ! V_68 ) ;
V_68 -> V_90 = V_96 ;
V_68 -> V_93 . V_97 = V_95 ;
V_26 = F_64 ( & V_68 -> V_93 , & V_98 , NULL ,
L_13 , V_18 ) ;
#ifdef F_65
if ( ! V_26 )
V_26 = F_66 ( & V_68 -> V_93 , & V_99 . V_82 ) ;
#endif
if ( V_26 ) {
F_67 ( & V_68 -> V_93 ) ;
F_68 ( L_22 ,
V_18 , V_26 ) ;
return NULL ;
}
F_69 ( & V_68 -> V_93 ) ;
}
return V_68 ;
}
static void T_5 F_70 ( const char * V_18 ,
const struct V_14 * V_91 ,
unsigned int V_100 )
{
struct V_67 * V_68 ;
int V_26 ;
V_68 = F_61 ( V_18 ) ;
if ( ! V_68 )
return;
if ( V_68 -> V_79 )
F_59 ( & V_68 -> V_93 , & V_68 -> V_79 -> V_80 ) ;
V_26 = F_51 ( V_68 , V_91 , V_91 -> V_18 + V_100 ) ;
F_38 ( V_26 ) ;
V_26 = F_57 ( & V_68 -> V_93 , & V_68 -> V_79 -> V_80 ) ;
F_38 ( V_26 ) ;
F_71 ( & V_68 -> V_93 , V_101 ) ;
F_67 ( & V_68 -> V_93 ) ;
}
static void T_5 F_72 ( void )
{
const struct V_14 * V_15 ;
unsigned int V_102 ;
char V_103 [ V_104 ] ;
for ( V_15 = V_105 ; V_15 < V_106 ; V_15 ++ ) {
char * V_107 ;
if ( V_15 -> V_78 == 0 )
continue;
V_107 = strchr ( V_15 -> V_18 , '.' ) ;
if ( ! V_107 ) {
strcpy ( V_103 , L_23 ) ;
V_102 = 0 ;
} else {
V_102 = V_107 - V_15 -> V_18 + 1 ;
F_45 ( V_103 , V_15 -> V_18 , V_102 ) ;
}
F_70 ( V_103 , V_15 , V_102 ) ;
}
}
T_3 F_73 ( struct V_65 * V_66 ,
struct V_67 * V_68 , char * V_69 )
{
struct V_108 * V_109 =
F_74 ( V_66 , struct V_108 , V_66 ) ;
return F_29 ( V_69 , V_45 , L_24 , V_109 -> V_110 ) ;
}
static void T_5 F_75 ( void )
{
const struct V_108 * * V_3 ;
struct V_67 * V_68 ;
int V_26 ;
for ( V_3 = V_111 ; V_3 < V_112 ; V_3 ++ ) {
const struct V_108 * V_109 = * V_3 ;
V_68 = F_61 ( V_109 -> V_113 ) ;
if ( V_68 ) {
V_26 = F_66 ( & V_68 -> V_93 , & V_109 -> V_66 . V_82 ) ;
F_71 ( & V_68 -> V_93 , V_101 ) ;
F_67 ( & V_68 -> V_93 ) ;
}
}
}
static T_3 F_76 ( struct V_94 * V_93 ,
struct V_72 * V_82 ,
char * V_69 )
{
struct V_65 * V_72 ;
struct V_67 * V_68 ;
int V_39 ;
V_72 = F_77 ( V_82 ) ;
V_68 = F_63 ( V_93 ) ;
if ( ! V_72 -> V_83 )
return - V_114 ;
V_39 = V_72 -> V_83 ( V_72 , V_68 , V_69 ) ;
return V_39 ;
}
static T_3 F_78 ( struct V_94 * V_93 ,
struct V_72 * V_82 ,
const char * V_69 , T_1 V_55 )
{
struct V_65 * V_72 ;
struct V_67 * V_68 ;
int V_39 ;
V_72 = F_77 ( V_82 ) ;
V_68 = F_63 ( V_93 ) ;
if ( ! V_72 -> V_87 )
return - V_114 ;
V_39 = V_72 -> V_87 ( V_72 , V_68 , V_69 , V_55 ) ;
return V_39 ;
}
static int F_79 ( struct V_97 * V_97 , struct V_94 * V_93 )
{
struct V_115 * V_116 = F_80 ( V_93 ) ;
if ( V_116 == & V_98 )
return 1 ;
return 0 ;
}
static void F_81 ( struct V_94 * V_93 )
{
struct V_67 * V_68 = F_63 ( V_93 ) ;
F_82 ( V_68 -> V_117 ) ;
}
static int T_5 F_83 ( void )
{
V_95 = F_84 ( L_25 , & V_118 , NULL ) ;
if ( ! V_95 ) {
F_85 ( V_119 L_26 ,
__FILE__ , __LINE__ ) ;
return - V_43 ;
}
V_120 = 1 ;
F_75 () ;
F_72 () ;
return 0 ;
}
