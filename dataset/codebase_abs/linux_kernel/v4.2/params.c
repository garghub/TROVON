static inline void F_1 ( struct V_1 * V_2 )
{
F_2 ( ! F_3 ( F_4 ( V_2 ) ) ) ;
}
static inline void F_1 ( struct V_1 * V_2 )
{
}
static void * F_5 ( unsigned int V_3 )
{
struct V_4 * V_5 ;
V_5 = F_6 ( sizeof( * V_5 ) + V_3 , V_6 ) ;
if ( ! V_5 )
return NULL ;
F_7 ( & V_7 ) ;
F_8 ( & V_5 -> V_8 , & V_9 ) ;
F_9 ( & V_7 ) ;
return V_5 -> V_10 ;
}
static void F_10 ( void * V_11 )
{
struct V_4 * V_5 ;
F_7 ( & V_7 ) ;
F_11 (p, &kmalloced_params, list) {
if ( V_5 -> V_10 == V_11 ) {
F_12 ( & V_5 -> V_8 ) ;
F_13 ( V_5 ) ;
break;
}
}
F_9 ( & V_7 ) ;
}
static char F_14 ( char V_12 )
{
if ( V_12 == '-' )
return '_' ;
return V_12 ;
}
bool F_15 ( const char * V_13 , const char * V_14 , T_1 V_15 )
{
T_1 V_16 ;
for ( V_16 = 0 ; V_16 < V_15 ; V_16 ++ ) {
if ( F_14 ( V_13 [ V_16 ] ) != F_14 ( V_14 [ V_16 ] ) )
return false ;
}
return true ;
}
bool F_16 ( const char * V_13 , const char * V_14 )
{
return F_15 ( V_13 , V_14 , strlen ( V_13 ) + 1 ) ;
}
static void F_17 ( const struct V_17 * V_18 )
{
if ( V_18 -> V_19 & V_20 ) {
F_18 ( L_1 ,
V_18 -> V_21 ) ;
F_19 ( V_22 , V_23 ) ;
}
}
static int F_20 ( char * V_11 ,
char * V_10 ,
const char * V_24 ,
const struct V_17 * V_25 ,
unsigned V_26 ,
T_2 V_27 ,
T_2 V_28 ,
void * V_29 ,
int (* F_21)( char * V_11 , char * V_10 ,
const char * V_24 , void * V_29 ) )
{
unsigned int V_16 ;
int V_30 ;
for ( V_16 = 0 ; V_16 < V_26 ; V_16 ++ ) {
if ( F_16 ( V_11 , V_25 [ V_16 ] . V_21 ) ) {
if ( V_25 [ V_16 ] . V_31 < V_27
|| V_25 [ V_16 ] . V_31 > V_28 )
return 0 ;
if ( ! V_10 &&
! ( V_25 [ V_16 ] . V_32 -> V_19 & V_33 ) )
return - V_34 ;
F_22 ( L_2 , V_11 ,
V_25 [ V_16 ] . V_32 -> V_35 ) ;
F_23 ( V_25 [ V_16 ] . V_2 ) ;
F_17 ( & V_25 [ V_16 ] ) ;
V_30 = V_25 [ V_16 ] . V_32 -> V_35 ( V_10 , & V_25 [ V_16 ] ) ;
F_24 ( V_25 [ V_16 ] . V_2 ) ;
return V_30 ;
}
}
if ( F_21 ) {
F_22 ( L_3 , V_24 , V_11 , V_10 ) ;
return F_21 ( V_11 , V_10 , V_24 , V_29 ) ;
}
F_22 ( L_4 , V_11 ) ;
return - V_36 ;
}
static char * F_25 ( char * args , char * * V_11 , char * * V_10 )
{
unsigned int V_16 , V_37 = 0 ;
int V_38 = 0 , V_39 = 0 ;
char * V_40 ;
if ( * args == '"' ) {
args ++ ;
V_38 = 1 ;
V_39 = 1 ;
}
for ( V_16 = 0 ; args [ V_16 ] ; V_16 ++ ) {
if ( isspace ( args [ V_16 ] ) && ! V_38 )
break;
if ( V_37 == 0 ) {
if ( args [ V_16 ] == '=' )
V_37 = V_16 ;
}
if ( args [ V_16 ] == '"' )
V_38 = ! V_38 ;
}
* V_11 = args ;
if ( ! V_37 )
* V_10 = NULL ;
else {
args [ V_37 ] = '\0' ;
* V_10 = args + V_37 + 1 ;
if ( * * V_10 == '"' ) {
( * V_10 ) ++ ;
if ( args [ V_16 - 1 ] == '"' )
args [ V_16 - 1 ] = '\0' ;
}
}
if ( V_39 && args [ V_16 - 1 ] == '"' )
args [ V_16 - 1 ] = '\0' ;
if ( args [ V_16 ] ) {
args [ V_16 ] = '\0' ;
V_40 = args + V_16 + 1 ;
} else
V_40 = args + V_16 ;
return F_26 ( V_40 ) ;
}
char * F_27 ( const char * V_24 ,
char * args ,
const struct V_17 * V_25 ,
unsigned V_41 ,
T_2 V_27 ,
T_2 V_28 ,
void * V_29 ,
int (* F_28)( char * V_11 , char * V_10 ,
const char * V_24 , void * V_29 ) )
{
char * V_11 , * V_10 ;
args = F_26 ( args ) ;
if ( * args )
F_22 ( L_5 , V_24 , args ) ;
while ( * args ) {
int V_42 ;
int V_43 ;
args = F_25 ( args , & V_11 , & V_10 ) ;
if ( ! V_10 && strcmp ( V_11 , L_6 ) == 0 )
return args ;
V_43 = F_29 () ;
V_42 = F_20 ( V_11 , V_10 , V_24 , V_25 , V_41 ,
V_27 , V_28 , V_29 , F_28 ) ;
if ( V_43 && ! F_29 () )
F_18 ( L_7 ,
V_24 , V_11 ) ;
switch ( V_42 ) {
case - V_36 :
F_30 ( L_8 , V_24 , V_11 ) ;
return F_31 ( V_42 ) ;
case - V_44 :
F_30 ( L_9 ,
V_24 , V_10 ? : L_10 , V_11 ) ;
return F_31 ( V_42 ) ;
case 0 :
break;
default:
F_30 ( L_11 ,
V_24 , V_10 ? : L_10 , V_11 ) ;
return F_31 ( V_42 ) ;
}
}
return NULL ;
}
int F_32 ( const char * V_10 , const struct V_17 * V_18 )
{
if ( strlen ( V_10 ) > 1024 ) {
F_30 ( L_12 , V_18 -> V_21 ) ;
return - V_44 ;
}
F_10 ( * ( char * * ) V_18 -> V_29 ) ;
if ( F_33 () ) {
* ( char * * ) V_18 -> V_29 = F_5 ( strlen ( V_10 ) + 1 ) ;
if ( ! * ( char * * ) V_18 -> V_29 )
return - V_45 ;
strcpy ( * ( char * * ) V_18 -> V_29 , V_10 ) ;
} else
* ( const char * * ) V_18 -> V_29 = V_10 ;
return 0 ;
}
int F_34 ( char * V_46 , const struct V_17 * V_18 )
{
return F_35 ( V_46 , V_47 , L_13 , * ( ( char * * ) V_18 -> V_29 ) ) ;
}
static void F_36 ( void * V_29 )
{
F_10 ( * ( ( char * * ) V_29 ) ) ;
}
int F_37 ( const char * V_10 , const struct V_17 * V_18 )
{
if ( ! V_10 ) V_10 = L_14 ;
return F_38 ( V_10 , V_18 -> V_29 ) ;
}
int F_39 ( char * V_46 , const struct V_17 * V_18 )
{
return sprintf ( V_46 , L_15 , * ( bool * ) V_18 -> V_29 ? 'Y' : 'N' ) ;
}
int F_40 ( const char * V_10 , const struct V_17 * V_18 )
{
int V_30 = 0 ;
bool V_48 ;
bool V_49 = * ( bool * ) V_18 -> V_29 ;
struct V_17 V_50 = * V_18 ;
V_50 . V_29 = & V_48 ;
V_30 = F_37 ( V_10 , & V_50 ) ;
if ( V_30 )
return V_30 ;
if ( ! V_48 && V_49 )
return - V_51 ;
if ( V_48 )
V_30 = F_37 ( V_10 , V_18 ) ;
return V_30 ;
}
int F_41 ( const char * V_10 , const struct V_17 * V_18 )
{
int V_42 ;
bool V_52 ;
struct V_17 V_53 ;
V_53 . V_29 = & V_52 ;
V_42 = F_37 ( V_10 , & V_53 ) ;
if ( V_42 == 0 )
* ( bool * ) V_18 -> V_29 = ! V_52 ;
return V_42 ;
}
int F_42 ( char * V_46 , const struct V_17 * V_18 )
{
return sprintf ( V_46 , L_15 , ( * ( bool * ) V_18 -> V_29 ) ? 'N' : 'Y' ) ;
}
int F_43 ( const char * V_10 , const struct V_17 * V_18 )
{
struct V_17 V_54 = * V_18 ;
bool V_55 ;
int V_42 ;
V_54 . V_29 = & V_55 ;
V_42 = F_37 ( V_10 , & V_54 ) ;
if ( V_42 == 0 )
* ( int * ) V_18 -> V_29 = V_55 ;
return V_42 ;
}
static int F_44 ( struct V_1 * V_2 ,
const char * V_21 ,
const char * V_10 ,
unsigned int V_56 , unsigned int V_57 ,
void * V_58 , int V_59 ,
int (* V_35)( const char * , const struct V_17 * V_18 ) ,
T_2 V_31 ,
unsigned int * V_41 )
{
int V_42 ;
struct V_17 V_18 ;
char V_60 ;
V_18 . V_21 = V_21 ;
V_18 . V_29 = V_58 ;
V_18 . V_31 = V_31 ;
* V_41 = 0 ;
do {
int V_61 ;
if ( * V_41 == V_57 ) {
F_30 ( L_16 , V_21 , V_57 ) ;
return - V_34 ;
}
V_61 = strcspn ( V_10 , L_17 ) ;
V_60 = V_10 [ V_61 ] ;
( ( char * ) V_10 ) [ V_61 ] = '\0' ;
F_1 ( V_2 ) ;
V_42 = V_35 ( V_10 , & V_18 ) ;
if ( V_42 != 0 )
return V_42 ;
V_18 . V_29 += V_59 ;
V_10 += V_61 + 1 ;
( * V_41 ) ++ ;
} while ( V_60 == ',' );
if ( * V_41 < V_56 ) {
F_30 ( L_18 , V_21 , V_56 ) ;
return - V_34 ;
}
return 0 ;
}
static int F_45 ( const char * V_10 , const struct V_17 * V_18 )
{
const struct V_62 * V_63 = V_18 -> V_63 ;
unsigned int V_64 ;
return F_44 ( V_18 -> V_2 , V_18 -> V_21 , V_10 , 1 , V_63 -> V_57 , V_63 -> V_58 ,
V_63 -> V_59 , V_63 -> V_32 -> V_35 , V_18 -> V_31 ,
V_63 -> V_41 ? : & V_64 ) ;
}
static int F_46 ( char * V_46 , const struct V_17 * V_18 )
{
int V_16 , V_65 , V_42 ;
const struct V_62 * V_63 = V_18 -> V_63 ;
struct V_17 V_5 = * V_18 ;
for ( V_16 = V_65 = 0 ; V_16 < ( V_63 -> V_41 ? * V_63 -> V_41 : V_63 -> V_57 ) ; V_16 ++ ) {
if ( V_16 )
V_46 [ V_65 ++ ] = ',' ;
V_5 . V_29 = V_63 -> V_58 + V_63 -> V_59 * V_16 ;
F_1 ( V_5 . V_2 ) ;
V_42 = V_63 -> V_32 -> V_66 ( V_46 + V_65 , & V_5 ) ;
if ( V_42 < 0 )
return V_42 ;
V_65 += V_42 ;
}
V_46 [ V_65 ] = '\0' ;
return V_65 ;
}
static void F_47 ( void * V_29 )
{
unsigned int V_16 ;
const struct V_62 * V_63 = V_29 ;
if ( V_63 -> V_32 -> free )
for ( V_16 = 0 ; V_16 < ( V_63 -> V_41 ? * V_63 -> V_41 : V_63 -> V_57 ) ; V_16 ++ )
V_63 -> V_32 -> free ( V_63 -> V_58 + V_63 -> V_59 * V_16 ) ;
}
int F_48 ( const char * V_10 , const struct V_17 * V_18 )
{
const struct V_67 * V_68 = V_18 -> V_69 ;
if ( strlen ( V_10 ) + 1 > V_68 -> V_70 ) {
F_30 ( L_19 ,
V_18 -> V_21 , V_68 -> V_70 - 1 ) ;
return - V_44 ;
}
strcpy ( V_68 -> string , V_10 ) ;
return 0 ;
}
int F_49 ( char * V_46 , const struct V_17 * V_18 )
{
const struct V_67 * V_68 = V_18 -> V_69 ;
return F_50 ( V_46 , V_68 -> string , V_68 -> V_70 ) ;
}
static T_3 F_51 ( struct V_71 * V_72 ,
struct V_73 * V_74 , char * V_75 )
{
int V_76 ;
struct V_77 * V_78 = F_52 ( V_72 ) ;
if ( ! V_78 -> V_11 -> V_32 -> V_66 )
return - V_79 ;
F_23 ( V_74 -> V_2 ) ;
V_76 = V_78 -> V_11 -> V_32 -> V_66 ( V_75 , V_78 -> V_11 ) ;
F_24 ( V_74 -> V_2 ) ;
if ( V_76 > 0 ) {
strcat ( V_75 , L_20 ) ;
++ V_76 ;
}
return V_76 ;
}
static T_3 F_53 ( struct V_71 * V_72 ,
struct V_73 * V_74 ,
const char * V_75 , T_1 V_61 )
{
int V_30 ;
struct V_77 * V_78 = F_52 ( V_72 ) ;
if ( ! V_78 -> V_11 -> V_32 -> V_35 )
return - V_79 ;
F_23 ( V_74 -> V_2 ) ;
F_17 ( V_78 -> V_11 ) ;
V_30 = V_78 -> V_11 -> V_32 -> V_35 ( V_75 , V_78 -> V_11 ) ;
F_24 ( V_74 -> V_2 ) ;
if ( ! V_30 )
return V_61 ;
return V_30 ;
}
void F_23 ( struct V_1 * V_2 )
{
F_54 ( F_4 ( V_2 ) ) ;
}
void F_24 ( struct V_1 * V_2 )
{
F_55 ( F_4 ( V_2 ) ) ;
}
static T_4 int F_56 ( struct V_73 * V_74 ,
const struct V_17 * V_18 ,
const char * V_21 )
{
struct V_80 * V_81 ;
struct V_78 * * V_82 ;
unsigned int V_16 ;
F_2 ( ! V_18 -> V_83 ) ;
if ( ! V_74 -> V_84 ) {
V_74 -> V_84 = F_57 ( sizeof( * V_74 -> V_84 ) , V_6 ) ;
if ( ! V_74 -> V_84 )
return - V_45 ;
V_74 -> V_84 -> V_85 . V_21 = L_21 ;
V_74 -> V_84 -> V_85 . V_86 = F_57 ( sizeof( V_74 -> V_84 -> V_85 . V_86 [ 0 ] ) ,
V_6 ) ;
if ( ! V_74 -> V_84 -> V_85 . V_86 )
return - V_45 ;
}
V_81 = F_58 ( V_74 -> V_84 ,
sizeof( * V_74 -> V_84 ) +
sizeof( V_74 -> V_84 -> V_86 [ 0 ] ) * ( V_74 -> V_84 -> V_41 + 1 ) ,
V_6 ) ;
if ( ! V_81 )
return - V_45 ;
V_74 -> V_84 = V_81 ;
V_82 = F_58 ( V_74 -> V_84 -> V_85 . V_86 ,
sizeof( V_74 -> V_84 -> V_85 . V_86 [ 0 ] ) * ( V_74 -> V_84 -> V_41 + 2 ) ,
V_6 ) ;
if ( ! V_82 )
return - V_45 ;
V_74 -> V_84 -> V_85 . V_86 = V_82 ;
memset ( & V_74 -> V_84 -> V_86 [ V_74 -> V_84 -> V_41 ] , 0 , sizeof( V_74 -> V_84 -> V_86 [ 0 ] ) ) ;
F_59 ( & V_74 -> V_84 -> V_86 [ V_74 -> V_84 -> V_41 ] . V_72 . V_87 ) ;
V_74 -> V_84 -> V_86 [ V_74 -> V_84 -> V_41 ] . V_11 = V_18 ;
V_74 -> V_84 -> V_86 [ V_74 -> V_84 -> V_41 ] . V_72 . V_88 = F_51 ;
if ( ( V_18 -> V_83 & ( V_89 | V_90 | V_91 ) ) != 0 )
V_74 -> V_84 -> V_86 [ V_74 -> V_84 -> V_41 ] . V_72 . V_92 = F_53 ;
else
V_74 -> V_84 -> V_86 [ V_74 -> V_84 -> V_41 ] . V_72 . V_92 = NULL ;
V_74 -> V_84 -> V_86 [ V_74 -> V_84 -> V_41 ] . V_72 . V_87 . V_21 = ( char * ) V_21 ;
V_74 -> V_84 -> V_86 [ V_74 -> V_84 -> V_41 ] . V_72 . V_87 . V_93 = V_18 -> V_83 ;
V_74 -> V_84 -> V_41 ++ ;
for ( V_16 = 0 ; V_16 < V_74 -> V_84 -> V_41 ; V_16 ++ )
V_74 -> V_84 -> V_85 . V_86 [ V_16 ] = & V_74 -> V_84 -> V_86 [ V_16 ] . V_72 . V_87 ;
V_74 -> V_84 -> V_85 . V_86 [ V_74 -> V_84 -> V_41 ] = NULL ;
return 0 ;
}
static void F_60 ( struct V_73 * V_74 )
{
if ( V_74 -> V_84 )
F_13 ( V_74 -> V_84 -> V_85 . V_86 ) ;
F_13 ( V_74 -> V_84 ) ;
V_74 -> V_84 = NULL ;
}
int F_61 ( struct V_1 * V_2 ,
const struct V_17 * V_94 ,
unsigned int V_26 )
{
int V_16 , V_30 ;
bool V_25 = false ;
for ( V_16 = 0 ; V_16 < V_26 ; V_16 ++ ) {
if ( V_94 [ V_16 ] . V_83 == 0 )
continue;
V_30 = F_56 ( & V_2 -> V_95 , & V_94 [ V_16 ] , V_94 [ V_16 ] . V_21 ) ;
if ( V_30 ) {
F_60 ( & V_2 -> V_95 ) ;
return V_30 ;
}
V_25 = true ;
}
if ( ! V_25 )
return 0 ;
V_30 = F_62 ( & V_2 -> V_95 . V_96 , & V_2 -> V_95 . V_84 -> V_85 ) ;
if ( V_30 )
F_60 ( & V_2 -> V_95 ) ;
return V_30 ;
}
void F_63 ( struct V_1 * V_2 )
{
if ( V_2 -> V_95 . V_84 ) {
F_64 ( & V_2 -> V_95 . V_96 , & V_2 -> V_95 . V_84 -> V_85 ) ;
F_60 ( & V_2 -> V_95 ) ;
}
}
void F_65 ( const struct V_17 * V_25 , unsigned V_41 )
{
unsigned int V_16 ;
for ( V_16 = 0 ; V_16 < V_41 ; V_16 ++ )
if ( V_25 [ V_16 ] . V_32 -> free )
V_25 [ V_16 ] . V_32 -> free ( V_25 [ V_16 ] . V_29 ) ;
}
static struct V_73 * T_5 F_66 ( const char * V_21 )
{
struct V_73 * V_74 ;
struct V_97 * V_96 ;
int V_30 ;
V_96 = F_67 ( V_98 , V_21 ) ;
if ( V_96 ) {
V_74 = F_68 ( V_96 ) ;
} else {
V_74 = F_57 ( sizeof( struct V_73 ) , V_6 ) ;
F_2 ( ! V_74 ) ;
V_74 -> V_2 = V_99 ;
V_74 -> V_96 . V_100 = V_98 ;
V_30 = F_69 ( & V_74 -> V_96 , & V_101 , NULL ,
L_13 , V_21 ) ;
#ifdef F_70
if ( ! V_30 )
V_30 = F_71 ( & V_74 -> V_96 , & V_102 . V_87 ) ;
#endif
if ( V_30 ) {
F_72 ( & V_74 -> V_96 ) ;
F_73 ( L_22 ,
V_21 , V_30 ) ;
return NULL ;
}
F_74 ( & V_74 -> V_96 ) ;
}
return V_74 ;
}
static void T_5 F_75 ( const char * V_21 ,
const struct V_17 * V_94 ,
unsigned int V_103 )
{
struct V_73 * V_74 ;
int V_30 ;
V_74 = F_66 ( V_21 ) ;
if ( ! V_74 )
return;
if ( V_74 -> V_84 )
F_64 ( & V_74 -> V_96 , & V_74 -> V_84 -> V_85 ) ;
V_30 = F_56 ( V_74 , V_94 , V_94 -> V_21 + V_103 ) ;
F_2 ( V_30 ) ;
V_30 = F_62 ( & V_74 -> V_96 , & V_74 -> V_84 -> V_85 ) ;
F_2 ( V_30 ) ;
F_76 ( & V_74 -> V_96 , V_104 ) ;
F_72 ( & V_74 -> V_96 ) ;
}
static void T_5 F_77 ( void )
{
const struct V_17 * V_18 ;
unsigned int V_105 ;
char V_106 [ V_107 ] ;
for ( V_18 = V_108 ; V_18 < V_109 ; V_18 ++ ) {
char * V_110 ;
if ( V_18 -> V_83 == 0 )
continue;
V_110 = strchr ( V_18 -> V_21 , '.' ) ;
if ( ! V_110 ) {
strcpy ( V_106 , L_23 ) ;
V_105 = 0 ;
} else {
V_105 = V_110 - V_18 -> V_21 + 1 ;
F_50 ( V_106 , V_18 -> V_21 , V_105 ) ;
}
F_75 ( V_106 , V_18 , V_105 ) ;
}
}
T_3 F_78 ( struct V_71 * V_72 ,
struct V_73 * V_74 , char * V_75 )
{
struct V_111 * V_112 =
F_79 ( V_72 , struct V_111 , V_72 ) ;
return F_35 ( V_75 , V_47 , L_24 , V_112 -> V_113 ) ;
}
static void T_5 F_80 ( void )
{
const struct V_111 * * V_5 ;
struct V_73 * V_74 ;
int V_30 ;
for ( V_5 = V_114 ; V_5 < V_115 ; V_5 ++ ) {
const struct V_111 * V_112 = * V_5 ;
V_74 = F_66 ( V_112 -> V_116 ) ;
if ( V_74 ) {
V_30 = F_71 ( & V_74 -> V_96 , & V_112 -> V_72 . V_87 ) ;
F_81 ( V_30 ) ;
F_76 ( & V_74 -> V_96 , V_104 ) ;
F_72 ( & V_74 -> V_96 ) ;
}
}
}
static T_3 F_82 ( struct V_97 * V_96 ,
struct V_78 * V_87 ,
char * V_75 )
{
struct V_71 * V_78 ;
struct V_73 * V_74 ;
int V_42 ;
V_78 = F_83 ( V_87 ) ;
V_74 = F_68 ( V_96 ) ;
if ( ! V_78 -> V_88 )
return - V_117 ;
V_42 = V_78 -> V_88 ( V_78 , V_74 , V_75 ) ;
return V_42 ;
}
static T_3 F_84 ( struct V_97 * V_96 ,
struct V_78 * V_87 ,
const char * V_75 , T_1 V_61 )
{
struct V_71 * V_78 ;
struct V_73 * V_74 ;
int V_42 ;
V_78 = F_83 ( V_87 ) ;
V_74 = F_68 ( V_96 ) ;
if ( ! V_78 -> V_92 )
return - V_117 ;
V_42 = V_78 -> V_92 ( V_78 , V_74 , V_75 , V_61 ) ;
return V_42 ;
}
static int F_85 ( struct V_100 * V_100 , struct V_97 * V_96 )
{
struct V_118 * V_119 = F_86 ( V_96 ) ;
if ( V_119 == & V_101 )
return 1 ;
return 0 ;
}
static void F_87 ( struct V_97 * V_96 )
{
struct V_73 * V_74 = F_68 ( V_96 ) ;
F_88 ( V_74 -> V_120 ) ;
}
static int T_5 F_89 ( void )
{
V_98 = F_90 ( L_25 , & V_121 , NULL ) ;
if ( ! V_98 ) {
F_91 ( V_122 L_26 ,
__FILE__ , __LINE__ ) ;
return - V_45 ;
}
V_123 = 1 ;
F_80 () ;
F_77 () ;
return 0 ;
}
