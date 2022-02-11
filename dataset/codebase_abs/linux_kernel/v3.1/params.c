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
static inline char F_8 ( char V_9 )
{
if ( V_9 == '-' )
return '_' ;
return V_9 ;
}
static inline int F_9 ( const char * V_10 , const char * V_11 )
{
unsigned int V_12 ;
for ( V_12 = 0 ; F_8 ( V_10 [ V_12 ] ) == V_11 [ V_12 ] ; V_12 ++ )
if ( V_10 [ V_12 ] == '\0' )
return 1 ;
return 0 ;
}
static int F_10 ( char * V_8 ,
char * V_7 ,
const struct V_13 * V_14 ,
unsigned V_15 ,
int (* F_11)( char * V_8 , char * V_7 ) )
{
unsigned int V_12 ;
int V_16 ;
for ( V_12 = 0 ; V_12 < V_15 ; V_12 ++ ) {
if ( F_9 ( V_8 , V_14 [ V_12 ] . V_17 ) ) {
if ( ! V_7 && V_14 [ V_12 ] . V_18 -> V_19 != V_20 )
return - V_21 ;
F_12 ( L_1 ,
V_14 [ V_12 ] . V_18 -> V_19 ) ;
F_13 ( & V_22 ) ;
V_16 = V_14 [ V_12 ] . V_18 -> V_19 ( V_7 , & V_14 [ V_12 ] ) ;
F_14 ( & V_22 ) ;
return V_16 ;
}
}
if ( F_11 ) {
F_12 ( L_2 , F_11 ) ;
return F_11 ( V_8 , V_7 ) ;
}
F_12 ( L_3 , V_8 ) ;
return - V_23 ;
}
static char * F_15 ( char * args , char * * V_8 , char * * V_7 )
{
unsigned int V_12 , V_24 = 0 ;
int V_25 = 0 , V_26 = 0 ;
char * V_27 ;
if ( * args == '"' ) {
args ++ ;
V_25 = 1 ;
V_26 = 1 ;
}
for ( V_12 = 0 ; args [ V_12 ] ; V_12 ++ ) {
if ( isspace ( args [ V_12 ] ) && ! V_25 )
break;
if ( V_24 == 0 ) {
if ( args [ V_12 ] == '=' )
V_24 = V_12 ;
}
if ( args [ V_12 ] == '"' )
V_25 = ! V_25 ;
}
* V_8 = args ;
if ( ! V_24 )
* V_7 = NULL ;
else {
args [ V_24 ] = '\0' ;
* V_7 = args + V_24 + 1 ;
if ( * * V_7 == '"' ) {
( * V_7 ) ++ ;
if ( args [ V_12 - 1 ] == '"' )
args [ V_12 - 1 ] = '\0' ;
}
if ( V_26 && args [ V_12 - 1 ] == '"' )
args [ V_12 - 1 ] = '\0' ;
}
if ( args [ V_12 ] ) {
args [ V_12 ] = '\0' ;
V_27 = args + V_12 + 1 ;
} else
V_27 = args + V_12 ;
return F_16 ( V_27 ) ;
}
int F_17 ( const char * V_17 ,
char * args ,
const struct V_13 * V_14 ,
unsigned V_28 ,
int (* F_18)( char * V_8 , char * V_7 ) )
{
char * V_8 , * V_7 ;
F_12 ( L_4 , args ) ;
args = F_16 ( args ) ;
while ( * args ) {
int V_29 ;
int V_30 ;
args = F_15 ( args , & V_8 , & V_7 ) ;
V_30 = F_19 () ;
V_29 = F_10 ( V_8 , V_7 , V_14 , V_28 , F_18 ) ;
if ( V_30 && ! F_19 () ) {
F_20 ( V_31 L_5
L_6 , V_8 ) ;
}
switch ( V_29 ) {
case - V_23 :
F_20 ( V_32 L_7 ,
V_17 , V_8 ) ;
return V_29 ;
case - V_33 :
F_20 ( V_32
L_8 ,
V_17 , V_7 ? : L_9 , V_8 ) ;
return V_29 ;
case 0 :
break;
default:
F_20 ( V_32
L_10 ,
V_17 , V_7 ? : L_9 , V_8 ) ;
return V_29 ;
}
}
return 0 ;
}
int F_21 ( const char * V_7 , const struct V_13 * V_34 )
{
if ( strlen ( V_7 ) > 1024 ) {
F_20 ( V_32 L_11 ,
V_34 -> V_17 ) ;
return - V_33 ;
}
F_4 ( * ( char * * ) V_34 -> V_35 ) ;
if ( F_22 () ) {
* ( char * * ) V_34 -> V_35 = F_1 ( strlen ( V_7 ) + 1 ) ;
if ( ! * ( char * * ) V_34 -> V_35 )
return - V_36 ;
strcpy ( * ( char * * ) V_34 -> V_35 , V_7 ) ;
} else
* ( const char * * ) V_34 -> V_35 = V_7 ;
return 0 ;
}
int F_23 ( char * V_37 , const struct V_13 * V_34 )
{
return sprintf ( V_37 , L_12 , * ( ( char * * ) V_34 -> V_35 ) ) ;
}
static void F_24 ( void * V_35 )
{
F_4 ( * ( ( char * * ) V_35 ) ) ;
}
int V_20 ( const char * V_7 , const struct V_13 * V_34 )
{
bool V_38 ;
int V_29 ;
if ( ! V_7 ) V_7 = L_13 ;
V_29 = F_25 ( V_7 , & V_38 ) ;
if ( V_29 )
return V_29 ;
if ( V_34 -> V_39 & V_40 )
* ( bool * ) V_34 -> V_35 = V_38 ;
else
* ( int * ) V_34 -> V_35 = V_38 ;
return 0 ;
}
int F_26 ( char * V_37 , const struct V_13 * V_34 )
{
bool V_7 ;
if ( V_34 -> V_39 & V_40 )
V_7 = * ( bool * ) V_34 -> V_35 ;
else
V_7 = * ( int * ) V_34 -> V_35 ;
return sprintf ( V_37 , L_14 , V_7 ? 'Y' : 'N' ) ;
}
int F_27 ( const char * V_7 , const struct V_13 * V_34 )
{
int V_29 ;
bool V_41 ;
struct V_13 V_42 ;
V_42 . V_35 = & V_41 ;
V_42 . V_39 = V_40 ;
V_29 = V_20 ( V_7 , & V_42 ) ;
if ( V_29 == 0 )
* ( bool * ) V_34 -> V_35 = ! V_41 ;
return V_29 ;
}
int F_28 ( char * V_37 , const struct V_13 * V_34 )
{
return sprintf ( V_37 , L_14 , ( * ( bool * ) V_34 -> V_35 ) ? 'N' : 'Y' ) ;
}
static int F_29 ( const char * V_17 ,
const char * V_7 ,
unsigned int V_43 , unsigned int V_44 ,
void * V_45 , int V_46 ,
int (* V_19)( const char * , const struct V_13 * V_34 ) ,
T_1 V_39 ,
unsigned int * V_28 )
{
int V_29 ;
struct V_13 V_34 ;
char V_47 ;
V_34 . V_17 = V_17 ;
V_34 . V_35 = V_45 ;
V_34 . V_39 = V_39 ;
* V_28 = 0 ;
do {
int V_48 ;
if ( * V_28 == V_44 ) {
F_20 ( V_32 L_15 ,
V_17 , V_44 ) ;
return - V_21 ;
}
V_48 = strcspn ( V_7 , L_16 ) ;
V_47 = V_7 [ V_48 ] ;
( ( char * ) V_7 ) [ V_48 ] = '\0' ;
F_30 ( ! F_31 ( & V_22 ) ) ;
V_29 = V_19 ( V_7 , & V_34 ) ;
if ( V_29 != 0 )
return V_29 ;
V_34 . V_35 += V_46 ;
V_7 += V_48 + 1 ;
( * V_28 ) ++ ;
} while ( V_47 == ',' );
if ( * V_28 < V_43 ) {
F_20 ( V_32 L_17 ,
V_17 , V_43 ) ;
return - V_21 ;
}
return 0 ;
}
static int F_32 ( const char * V_7 , const struct V_13 * V_34 )
{
const struct V_49 * V_50 = V_34 -> V_50 ;
unsigned int V_51 ;
return F_29 ( V_34 -> V_17 , V_7 , 1 , V_50 -> V_44 , V_50 -> V_45 ,
V_50 -> V_46 , V_50 -> V_18 -> V_19 , V_34 -> V_39 ,
V_50 -> V_28 ? : & V_51 ) ;
}
static int F_33 ( char * V_37 , const struct V_13 * V_34 )
{
int V_12 , V_52 , V_29 ;
const struct V_49 * V_50 = V_34 -> V_50 ;
struct V_13 V_3 ;
V_3 = * V_34 ;
for ( V_12 = V_52 = 0 ; V_12 < ( V_50 -> V_28 ? * V_50 -> V_28 : V_50 -> V_44 ) ; V_12 ++ ) {
if ( V_12 )
V_37 [ V_52 ++ ] = ',' ;
V_3 . V_35 = V_50 -> V_45 + V_50 -> V_46 * V_12 ;
F_30 ( ! F_31 ( & V_22 ) ) ;
V_29 = V_50 -> V_18 -> V_53 ( V_37 + V_52 , & V_3 ) ;
if ( V_29 < 0 )
return V_29 ;
V_52 += V_29 ;
}
V_37 [ V_52 ] = '\0' ;
return V_52 ;
}
static void F_34 ( void * V_35 )
{
unsigned int V_12 ;
const struct V_49 * V_50 = V_35 ;
if ( V_50 -> V_18 -> free )
for ( V_12 = 0 ; V_12 < ( V_50 -> V_28 ? * V_50 -> V_28 : V_50 -> V_44 ) ; V_12 ++ )
V_50 -> V_18 -> free ( V_50 -> V_45 + V_50 -> V_46 * V_12 ) ;
}
int F_35 ( const char * V_7 , const struct V_13 * V_34 )
{
const struct V_54 * V_55 = V_34 -> V_56 ;
if ( strlen ( V_7 ) + 1 > V_55 -> V_57 ) {
F_20 ( V_32 L_18 ,
V_34 -> V_17 , V_55 -> V_57 - 1 ) ;
return - V_33 ;
}
strcpy ( V_55 -> string , V_7 ) ;
return 0 ;
}
int F_36 ( char * V_37 , const struct V_13 * V_34 )
{
const struct V_54 * V_55 = V_34 -> V_56 ;
return F_37 ( V_37 , V_55 -> string , V_55 -> V_57 ) ;
}
static T_2 F_38 ( struct V_58 * V_59 ,
struct V_60 * V_61 , char * V_62 )
{
int V_63 ;
struct V_64 * V_65 = F_39 ( V_59 ) ;
if ( ! V_65 -> V_8 -> V_18 -> V_53 )
return - V_66 ;
F_13 ( & V_22 ) ;
V_63 = V_65 -> V_8 -> V_18 -> V_53 ( V_62 , V_65 -> V_8 ) ;
F_14 ( & V_22 ) ;
if ( V_63 > 0 ) {
strcat ( V_62 , L_19 ) ;
++ V_63 ;
}
return V_63 ;
}
static T_2 F_40 ( struct V_58 * V_59 ,
struct V_60 * V_67 ,
const char * V_62 , T_3 V_48 )
{
int V_16 ;
struct V_64 * V_65 = F_39 ( V_59 ) ;
if ( ! V_65 -> V_8 -> V_18 -> V_19 )
return - V_66 ;
F_13 ( & V_22 ) ;
V_16 = V_65 -> V_8 -> V_18 -> V_19 ( V_62 , V_65 -> V_8 ) ;
F_14 ( & V_22 ) ;
if ( ! V_16 )
return V_48 ;
return V_16 ;
}
void F_41 ( void )
{
F_13 ( & V_22 ) ;
}
void F_42 ( void )
{
F_14 ( & V_22 ) ;
}
static T_4 int F_43 ( struct V_60 * V_61 ,
const struct V_13 * V_34 ,
const char * V_17 )
{
struct V_68 * V_69 ;
struct V_65 * * V_70 ;
int V_16 , V_28 ;
F_30 ( ! V_34 -> V_71 ) ;
if ( ! V_61 -> V_72 ) {
V_28 = 0 ;
V_70 = NULL ;
} else {
V_28 = V_61 -> V_72 -> V_28 ;
V_70 = V_61 -> V_72 -> V_73 . V_70 ;
}
V_69 = F_44 ( V_61 -> V_72 ,
sizeof( * V_61 -> V_72 ) + sizeof( V_61 -> V_72 -> V_70 [ 0 ] ) * ( V_28 + 1 ) ,
V_4 ) ;
if ( ! V_69 ) {
F_7 ( V_61 -> V_72 ) ;
V_16 = - V_36 ;
goto V_74;
}
V_70 = F_44 ( V_70 , sizeof( V_69 -> V_73 . V_70 [ 0 ] ) * ( V_28 + 2 ) , V_4 ) ;
if ( ! V_70 ) {
V_16 = - V_36 ;
goto V_75;
}
memset ( V_69 , 0 , sizeof( * V_69 ) ) ;
memset ( & V_69 -> V_70 [ V_28 ] , 0 , sizeof( V_69 -> V_70 [ V_28 ] ) ) ;
memset ( & V_70 [ V_28 ] , 0 , sizeof( V_70 [ V_28 ] ) ) ;
V_69 -> V_73 . V_17 = L_20 ;
V_69 -> V_73 . V_70 = V_70 ;
F_45 ( & V_69 -> V_70 [ V_28 ] . V_59 . V_76 ) ;
V_69 -> V_70 [ V_28 ] . V_8 = V_34 ;
V_69 -> V_70 [ V_28 ] . V_59 . V_77 = F_38 ;
V_69 -> V_70 [ V_28 ] . V_59 . V_78 = F_40 ;
V_69 -> V_70 [ V_28 ] . V_59 . V_76 . V_17 = ( char * ) V_17 ;
V_69 -> V_70 [ V_28 ] . V_59 . V_76 . V_79 = V_34 -> V_71 ;
V_69 -> V_28 = V_28 + 1 ;
for ( V_28 = 0 ; V_28 < V_69 -> V_28 ; V_28 ++ )
V_69 -> V_73 . V_70 [ V_28 ] = & V_69 -> V_70 [ V_28 ] . V_59 . V_76 ;
V_69 -> V_73 . V_70 [ V_28 ] = NULL ;
V_61 -> V_72 = V_69 ;
return 0 ;
V_75:
F_7 ( V_69 ) ;
V_74:
V_61 -> V_72 = NULL ;
return V_16 ;
}
static void F_46 ( struct V_60 * V_61 )
{
F_7 ( V_61 -> V_72 -> V_73 . V_70 ) ;
F_7 ( V_61 -> V_72 ) ;
V_61 -> V_72 = NULL ;
}
int F_47 ( struct V_80 * V_81 ,
const struct V_13 * V_82 ,
unsigned int V_15 )
{
int V_12 , V_16 ;
bool V_14 = false ;
for ( V_12 = 0 ; V_12 < V_15 ; V_12 ++ ) {
if ( V_82 [ V_12 ] . V_71 == 0 )
continue;
V_16 = F_43 ( & V_81 -> V_83 , & V_82 [ V_12 ] , V_82 [ V_12 ] . V_17 ) ;
if ( V_16 )
return V_16 ;
V_14 = true ;
}
if ( ! V_14 )
return 0 ;
V_16 = F_48 ( & V_81 -> V_83 . V_84 , & V_81 -> V_83 . V_72 -> V_73 ) ;
if ( V_16 )
F_46 ( & V_81 -> V_83 ) ;
return V_16 ;
}
void F_49 ( struct V_80 * V_81 )
{
if ( V_81 -> V_83 . V_72 ) {
F_50 ( & V_81 -> V_83 . V_84 , & V_81 -> V_83 . V_72 -> V_73 ) ;
F_46 ( & V_81 -> V_83 ) ;
}
}
void F_51 ( const struct V_13 * V_14 , unsigned V_28 )
{
unsigned int V_12 ;
for ( V_12 = 0 ; V_12 < V_28 ; V_12 ++ )
if ( V_14 [ V_12 ] . V_18 -> free )
V_14 [ V_12 ] . V_18 -> free ( V_14 [ V_12 ] . V_35 ) ;
}
static struct V_60 * T_5 F_52 ( const char * V_17 )
{
struct V_60 * V_61 ;
struct V_85 * V_84 ;
int V_16 ;
V_84 = F_53 ( V_86 , V_17 ) ;
if ( V_84 ) {
V_61 = F_54 ( V_84 ) ;
} else {
V_61 = F_55 ( sizeof( struct V_60 ) , V_4 ) ;
F_30 ( ! V_61 ) ;
V_61 -> V_81 = V_87 ;
V_61 -> V_84 . V_88 = V_86 ;
V_16 = F_56 ( & V_61 -> V_84 , & V_89 , NULL ,
L_12 , V_17 ) ;
#ifdef F_57
if ( ! V_16 )
V_16 = F_58 ( & V_61 -> V_84 , & V_90 . V_76 ) ;
#endif
if ( V_16 ) {
F_59 ( & V_61 -> V_84 ) ;
F_20 ( V_32
L_21 ,
V_17 , V_16 ) ;
F_20 ( V_32
L_22 ) ;
return NULL ;
}
F_60 ( & V_61 -> V_84 ) ;
}
return V_61 ;
}
static void T_5 F_61 ( const char * V_17 ,
struct V_13 * V_82 ,
unsigned int V_91 )
{
struct V_60 * V_61 ;
int V_16 ;
V_61 = F_52 ( V_17 ) ;
if ( ! V_61 )
return;
if ( V_61 -> V_72 )
F_50 ( & V_61 -> V_84 , & V_61 -> V_72 -> V_73 ) ;
V_16 = F_43 ( V_61 , V_82 , V_82 -> V_17 + V_91 ) ;
F_30 ( V_16 ) ;
V_16 = F_48 ( & V_61 -> V_84 , & V_61 -> V_72 -> V_73 ) ;
F_30 ( V_16 ) ;
F_62 ( & V_61 -> V_84 , V_92 ) ;
F_59 ( & V_61 -> V_84 ) ;
}
static void T_5 F_63 ( void )
{
struct V_13 * V_34 ;
unsigned int V_93 ;
char V_94 [ V_95 ] ;
for ( V_34 = V_96 ; V_34 < V_97 ; V_34 ++ ) {
char * V_98 ;
if ( V_34 -> V_71 == 0 )
continue;
V_98 = strchr ( V_34 -> V_17 , '.' ) ;
if ( ! V_98 ) {
strcpy ( V_94 , L_23 ) ;
V_93 = 0 ;
} else {
V_93 = V_98 - V_34 -> V_17 + 1 ;
F_37 ( V_94 , V_34 -> V_17 , V_93 ) ;
}
F_61 ( V_94 , V_34 , V_93 ) ;
}
}
T_2 F_64 ( struct V_58 * V_59 ,
struct V_60 * V_61 , char * V_62 )
{
struct V_99 * V_100 =
F_65 ( V_59 , struct V_99 , V_59 ) ;
return sprintf ( V_62 , L_24 , V_100 -> V_101 ) ;
}
static void T_5 F_66 ( void )
{
const struct V_99 * * V_3 ;
struct V_60 * V_61 ;
int V_16 ;
for ( V_3 = V_102 ; V_3 < V_103 ; V_3 ++ ) {
const struct V_99 * V_100 = * V_3 ;
V_61 = F_52 ( V_100 -> V_104 ) ;
if ( V_61 ) {
V_16 = F_58 ( & V_61 -> V_84 , & V_100 -> V_59 . V_76 ) ;
F_62 ( & V_61 -> V_84 , V_92 ) ;
F_59 ( & V_61 -> V_84 ) ;
}
}
}
static T_2 F_67 ( struct V_85 * V_84 ,
struct V_65 * V_76 ,
char * V_62 )
{
struct V_58 * V_65 ;
struct V_60 * V_61 ;
int V_29 ;
V_65 = F_68 ( V_76 ) ;
V_61 = F_54 ( V_84 ) ;
if ( ! V_65 -> V_77 )
return - V_105 ;
V_29 = V_65 -> V_77 ( V_65 , V_61 , V_62 ) ;
return V_29 ;
}
static T_2 F_69 ( struct V_85 * V_84 ,
struct V_65 * V_76 ,
const char * V_62 , T_3 V_48 )
{
struct V_58 * V_65 ;
struct V_60 * V_61 ;
int V_29 ;
V_65 = F_68 ( V_76 ) ;
V_61 = F_54 ( V_84 ) ;
if ( ! V_65 -> V_78 )
return - V_105 ;
V_29 = V_65 -> V_78 ( V_65 , V_61 , V_62 , V_48 ) ;
return V_29 ;
}
static int F_70 ( struct V_88 * V_88 , struct V_85 * V_84 )
{
struct V_106 * V_107 = F_71 ( V_84 ) ;
if ( V_107 == & V_89 )
return 1 ;
return 0 ;
}
static int T_5 F_72 ( void )
{
V_86 = F_73 ( L_25 , & V_108 , NULL ) ;
if ( ! V_86 ) {
F_20 ( V_31 L_26 ,
__FILE__ , __LINE__ ) ;
return - V_36 ;
}
V_109 = 1 ;
F_66 () ;
F_63 () ;
return 0 ;
}
