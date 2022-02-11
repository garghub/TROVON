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
T_2 V_17 ,
T_2 V_18 ,
int (* F_12)( char * V_8 , char * V_7 ) )
{
unsigned int V_13 ;
int V_19 ;
for ( V_13 = 0 ; V_13 < V_16 ; V_13 ++ ) {
if ( F_10 ( V_8 , V_15 [ V_13 ] . V_20 ) ) {
if ( V_15 [ V_13 ] . V_21 < V_17
|| V_15 [ V_13 ] . V_21 > V_18 )
return 0 ;
if ( ! V_7 && V_15 [ V_13 ] . V_22 -> V_23 != V_24
&& V_15 [ V_13 ] . V_22 -> V_23 != V_25 )
return - V_26 ;
F_13 ( L_1 ,
V_15 [ V_13 ] . V_22 -> V_23 ) ;
F_14 ( & V_27 ) ;
V_19 = V_15 [ V_13 ] . V_22 -> V_23 ( V_7 , & V_15 [ V_13 ] ) ;
F_15 ( & V_27 ) ;
return V_19 ;
}
}
if ( F_12 ) {
F_13 ( L_2 , F_12 ) ;
return F_12 ( V_8 , V_7 ) ;
}
F_13 ( L_3 , V_8 ) ;
return - V_28 ;
}
static char * F_16 ( char * args , char * * V_8 , char * * V_7 )
{
unsigned int V_13 , V_29 = 0 ;
int V_30 = 0 , V_31 = 0 ;
char * V_32 ;
if ( * args == '"' ) {
args ++ ;
V_30 = 1 ;
V_31 = 1 ;
}
for ( V_13 = 0 ; args [ V_13 ] ; V_13 ++ ) {
if ( isspace ( args [ V_13 ] ) && ! V_30 )
break;
if ( V_29 == 0 ) {
if ( args [ V_13 ] == '=' )
V_29 = V_13 ;
}
if ( args [ V_13 ] == '"' )
V_30 = ! V_30 ;
}
* V_8 = args ;
if ( ! V_29 )
* V_7 = NULL ;
else {
args [ V_29 ] = '\0' ;
* V_7 = args + V_29 + 1 ;
if ( * * V_7 == '"' ) {
( * V_7 ) ++ ;
if ( args [ V_13 - 1 ] == '"' )
args [ V_13 - 1 ] = '\0' ;
}
if ( V_31 && args [ V_13 - 1 ] == '"' )
args [ V_13 - 1 ] = '\0' ;
}
if ( args [ V_13 ] ) {
args [ V_13 ] = '\0' ;
V_32 = args + V_13 + 1 ;
} else
V_32 = args + V_13 ;
return F_17 ( V_32 ) ;
}
int F_18 ( const char * V_20 ,
char * args ,
const struct V_14 * V_15 ,
unsigned V_33 ,
T_2 V_17 ,
T_2 V_18 ,
int (* F_19)( char * V_8 , char * V_7 ) )
{
char * V_8 , * V_7 ;
F_13 ( L_4 , args ) ;
args = F_17 ( args ) ;
while ( * args ) {
int V_34 ;
int V_35 ;
args = F_16 ( args , & V_8 , & V_7 ) ;
V_35 = F_20 () ;
V_34 = F_11 ( V_8 , V_7 , V_15 , V_33 ,
V_17 , V_18 , F_19 ) ;
if ( V_35 && ! F_20 () ) {
F_21 ( V_36 L_5
L_6 , V_8 ) ;
}
switch ( V_34 ) {
case - V_28 :
F_21 ( V_37 L_7 ,
V_20 , V_8 ) ;
return V_34 ;
case - V_38 :
F_21 ( V_37
L_8 ,
V_20 , V_7 ? : L_9 , V_8 ) ;
return V_34 ;
case 0 :
break;
default:
F_21 ( V_37
L_10 ,
V_20 , V_7 ? : L_9 , V_8 ) ;
return V_34 ;
}
}
return 0 ;
}
int F_22 ( const char * V_7 , const struct V_14 * V_39 )
{
if ( strlen ( V_7 ) > 1024 ) {
F_21 ( V_37 L_11 ,
V_39 -> V_20 ) ;
return - V_38 ;
}
F_4 ( * ( char * * ) V_39 -> V_40 ) ;
if ( F_23 () ) {
* ( char * * ) V_39 -> V_40 = F_1 ( strlen ( V_7 ) + 1 ) ;
if ( ! * ( char * * ) V_39 -> V_40 )
return - V_41 ;
strcpy ( * ( char * * ) V_39 -> V_40 , V_7 ) ;
} else
* ( const char * * ) V_39 -> V_40 = V_7 ;
return 0 ;
}
int F_24 ( char * V_42 , const struct V_14 * V_39 )
{
return sprintf ( V_42 , L_12 , * ( ( char * * ) V_39 -> V_40 ) ) ;
}
static void F_25 ( void * V_40 )
{
F_4 ( * ( ( char * * ) V_40 ) ) ;
}
int V_24 ( const char * V_7 , const struct V_14 * V_39 )
{
if ( ! V_7 ) V_7 = L_13 ;
return F_26 ( V_7 , V_39 -> V_40 ) ;
}
int F_27 ( char * V_42 , const struct V_14 * V_39 )
{
return sprintf ( V_42 , L_14 , * ( bool * ) V_39 -> V_40 ? 'Y' : 'N' ) ;
}
int F_28 ( const char * V_7 , const struct V_14 * V_39 )
{
int V_34 ;
bool V_43 ;
struct V_14 V_44 ;
V_44 . V_40 = & V_43 ;
V_34 = V_24 ( V_7 , & V_44 ) ;
if ( V_34 == 0 )
* ( bool * ) V_39 -> V_40 = ! V_43 ;
return V_34 ;
}
int F_29 ( char * V_42 , const struct V_14 * V_39 )
{
return sprintf ( V_42 , L_14 , ( * ( bool * ) V_39 -> V_40 ) ? 'N' : 'Y' ) ;
}
int V_25 ( const char * V_7 , const struct V_14 * V_39 )
{
struct V_14 V_45 ;
bool V_46 ;
int V_34 ;
V_45 = * V_39 ;
V_45 . V_40 = & V_46 ;
V_34 = V_24 ( V_7 , & V_45 ) ;
if ( V_34 == 0 )
* ( int * ) V_39 -> V_40 = V_46 ;
return V_34 ;
}
static int F_30 ( const char * V_20 ,
const char * V_7 ,
unsigned int V_47 , unsigned int V_48 ,
void * V_49 , int V_50 ,
int (* V_23)( const char * , const struct V_14 * V_39 ) ,
T_2 V_21 ,
unsigned int * V_33 )
{
int V_34 ;
struct V_14 V_39 ;
char V_51 ;
V_39 . V_20 = V_20 ;
V_39 . V_40 = V_49 ;
V_39 . V_21 = V_21 ;
* V_33 = 0 ;
do {
int V_52 ;
if ( * V_33 == V_48 ) {
F_21 ( V_37 L_15 ,
V_20 , V_48 ) ;
return - V_26 ;
}
V_52 = strcspn ( V_7 , L_16 ) ;
V_51 = V_7 [ V_52 ] ;
( ( char * ) V_7 ) [ V_52 ] = '\0' ;
F_31 ( ! F_32 ( & V_27 ) ) ;
V_34 = V_23 ( V_7 , & V_39 ) ;
if ( V_34 != 0 )
return V_34 ;
V_39 . V_40 += V_50 ;
V_7 += V_52 + 1 ;
( * V_33 ) ++ ;
} while ( V_51 == ',' );
if ( * V_33 < V_47 ) {
F_21 ( V_37 L_17 ,
V_20 , V_47 ) ;
return - V_26 ;
}
return 0 ;
}
static int F_33 ( const char * V_7 , const struct V_14 * V_39 )
{
const struct V_53 * V_54 = V_39 -> V_54 ;
unsigned int V_55 ;
return F_30 ( V_39 -> V_20 , V_7 , 1 , V_54 -> V_48 , V_54 -> V_49 ,
V_54 -> V_50 , V_54 -> V_22 -> V_23 , V_39 -> V_21 ,
V_54 -> V_33 ? : & V_55 ) ;
}
static int F_34 ( char * V_42 , const struct V_14 * V_39 )
{
int V_13 , V_56 , V_34 ;
const struct V_53 * V_54 = V_39 -> V_54 ;
struct V_14 V_3 ;
V_3 = * V_39 ;
for ( V_13 = V_56 = 0 ; V_13 < ( V_54 -> V_33 ? * V_54 -> V_33 : V_54 -> V_48 ) ; V_13 ++ ) {
if ( V_13 )
V_42 [ V_56 ++ ] = ',' ;
V_3 . V_40 = V_54 -> V_49 + V_54 -> V_50 * V_13 ;
F_31 ( ! F_32 ( & V_27 ) ) ;
V_34 = V_54 -> V_22 -> V_57 ( V_42 + V_56 , & V_3 ) ;
if ( V_34 < 0 )
return V_34 ;
V_56 += V_34 ;
}
V_42 [ V_56 ] = '\0' ;
return V_56 ;
}
static void F_35 ( void * V_40 )
{
unsigned int V_13 ;
const struct V_53 * V_54 = V_40 ;
if ( V_54 -> V_22 -> free )
for ( V_13 = 0 ; V_13 < ( V_54 -> V_33 ? * V_54 -> V_33 : V_54 -> V_48 ) ; V_13 ++ )
V_54 -> V_22 -> free ( V_54 -> V_49 + V_54 -> V_50 * V_13 ) ;
}
int F_36 ( const char * V_7 , const struct V_14 * V_39 )
{
const struct V_58 * V_59 = V_39 -> V_60 ;
if ( strlen ( V_7 ) + 1 > V_59 -> V_61 ) {
F_21 ( V_37 L_18 ,
V_39 -> V_20 , V_59 -> V_61 - 1 ) ;
return - V_38 ;
}
strcpy ( V_59 -> string , V_7 ) ;
return 0 ;
}
int F_37 ( char * V_42 , const struct V_14 * V_39 )
{
const struct V_58 * V_59 = V_39 -> V_60 ;
return F_38 ( V_42 , V_59 -> string , V_59 -> V_61 ) ;
}
static T_3 F_39 ( struct V_62 * V_63 ,
struct V_64 * V_65 , char * V_66 )
{
int V_67 ;
struct V_68 * V_69 = F_40 ( V_63 ) ;
if ( ! V_69 -> V_8 -> V_22 -> V_57 )
return - V_70 ;
F_14 ( & V_27 ) ;
V_67 = V_69 -> V_8 -> V_22 -> V_57 ( V_66 , V_69 -> V_8 ) ;
F_15 ( & V_27 ) ;
if ( V_67 > 0 ) {
strcat ( V_66 , L_19 ) ;
++ V_67 ;
}
return V_67 ;
}
static T_3 F_41 ( struct V_62 * V_63 ,
struct V_64 * V_71 ,
const char * V_66 , T_1 V_52 )
{
int V_19 ;
struct V_68 * V_69 = F_40 ( V_63 ) ;
if ( ! V_69 -> V_8 -> V_22 -> V_23 )
return - V_70 ;
F_14 ( & V_27 ) ;
V_19 = V_69 -> V_8 -> V_22 -> V_23 ( V_66 , V_69 -> V_8 ) ;
F_15 ( & V_27 ) ;
if ( ! V_19 )
return V_52 ;
return V_19 ;
}
void F_42 ( void )
{
F_14 ( & V_27 ) ;
}
void F_43 ( void )
{
F_15 ( & V_27 ) ;
}
static T_4 int F_44 ( struct V_64 * V_65 ,
const struct V_14 * V_39 ,
const char * V_20 )
{
struct V_72 * V_73 ;
struct V_69 * * V_74 ;
int V_19 , V_33 ;
F_31 ( ! V_39 -> V_75 ) ;
if ( ! V_65 -> V_76 ) {
V_33 = 0 ;
V_74 = NULL ;
} else {
V_33 = V_65 -> V_76 -> V_33 ;
V_74 = V_65 -> V_76 -> V_77 . V_74 ;
}
V_73 = F_45 ( V_65 -> V_76 ,
sizeof( * V_65 -> V_76 ) + sizeof( V_65 -> V_76 -> V_74 [ 0 ] ) * ( V_33 + 1 ) ,
V_4 ) ;
if ( ! V_73 ) {
F_7 ( V_65 -> V_76 ) ;
V_19 = - V_41 ;
goto V_78;
}
V_74 = F_45 ( V_74 , sizeof( V_73 -> V_77 . V_74 [ 0 ] ) * ( V_33 + 2 ) , V_4 ) ;
if ( ! V_74 ) {
V_19 = - V_41 ;
goto V_79;
}
memset ( V_73 , 0 , sizeof( * V_73 ) ) ;
memset ( & V_73 -> V_74 [ V_33 ] , 0 , sizeof( V_73 -> V_74 [ V_33 ] ) ) ;
memset ( & V_74 [ V_33 ] , 0 , sizeof( V_74 [ V_33 ] ) ) ;
V_73 -> V_77 . V_20 = L_20 ;
V_73 -> V_77 . V_74 = V_74 ;
F_46 ( & V_73 -> V_74 [ V_33 ] . V_63 . V_80 ) ;
V_73 -> V_74 [ V_33 ] . V_8 = V_39 ;
V_73 -> V_74 [ V_33 ] . V_63 . V_81 = F_39 ;
V_73 -> V_74 [ V_33 ] . V_63 . V_82 = F_41 ;
V_73 -> V_74 [ V_33 ] . V_63 . V_80 . V_20 = ( char * ) V_20 ;
V_73 -> V_74 [ V_33 ] . V_63 . V_80 . V_83 = V_39 -> V_75 ;
V_73 -> V_33 = V_33 + 1 ;
for ( V_33 = 0 ; V_33 < V_73 -> V_33 ; V_33 ++ )
V_73 -> V_77 . V_74 [ V_33 ] = & V_73 -> V_74 [ V_33 ] . V_63 . V_80 ;
V_73 -> V_77 . V_74 [ V_33 ] = NULL ;
V_65 -> V_76 = V_73 ;
return 0 ;
V_79:
F_7 ( V_73 ) ;
V_78:
V_65 -> V_76 = NULL ;
return V_19 ;
}
static void F_47 ( struct V_64 * V_65 )
{
F_7 ( V_65 -> V_76 -> V_77 . V_74 ) ;
F_7 ( V_65 -> V_76 ) ;
V_65 -> V_76 = NULL ;
}
int F_48 ( struct V_84 * V_85 ,
const struct V_14 * V_86 ,
unsigned int V_16 )
{
int V_13 , V_19 ;
bool V_15 = false ;
for ( V_13 = 0 ; V_13 < V_16 ; V_13 ++ ) {
if ( V_86 [ V_13 ] . V_75 == 0 )
continue;
V_19 = F_44 ( & V_85 -> V_87 , & V_86 [ V_13 ] , V_86 [ V_13 ] . V_20 ) ;
if ( V_19 )
return V_19 ;
V_15 = true ;
}
if ( ! V_15 )
return 0 ;
V_19 = F_49 ( & V_85 -> V_87 . V_88 , & V_85 -> V_87 . V_76 -> V_77 ) ;
if ( V_19 )
F_47 ( & V_85 -> V_87 ) ;
return V_19 ;
}
void F_50 ( struct V_84 * V_85 )
{
if ( V_85 -> V_87 . V_76 ) {
F_51 ( & V_85 -> V_87 . V_88 , & V_85 -> V_87 . V_76 -> V_77 ) ;
F_47 ( & V_85 -> V_87 ) ;
}
}
void F_52 ( const struct V_14 * V_15 , unsigned V_33 )
{
unsigned int V_13 ;
for ( V_13 = 0 ; V_13 < V_33 ; V_13 ++ )
if ( V_15 [ V_13 ] . V_22 -> free )
V_15 [ V_13 ] . V_22 -> free ( V_15 [ V_13 ] . V_40 ) ;
}
static struct V_64 * T_5 F_53 ( const char * V_20 )
{
struct V_64 * V_65 ;
struct V_89 * V_88 ;
int V_19 ;
V_88 = F_54 ( V_90 , V_20 ) ;
if ( V_88 ) {
V_65 = F_55 ( V_88 ) ;
} else {
V_65 = F_56 ( sizeof( struct V_64 ) , V_4 ) ;
F_31 ( ! V_65 ) ;
V_65 -> V_85 = V_91 ;
V_65 -> V_88 . V_92 = V_90 ;
V_19 = F_57 ( & V_65 -> V_88 , & V_93 , NULL ,
L_12 , V_20 ) ;
#ifdef F_58
if ( ! V_19 )
V_19 = F_59 ( & V_65 -> V_88 , & V_94 . V_80 ) ;
#endif
if ( V_19 ) {
F_60 ( & V_65 -> V_88 ) ;
F_21 ( V_37
L_21 ,
V_20 , V_19 ) ;
F_21 ( V_37
L_22 ) ;
return NULL ;
}
F_61 ( & V_65 -> V_88 ) ;
}
return V_65 ;
}
static void T_5 F_62 ( const char * V_20 ,
struct V_14 * V_86 ,
unsigned int V_95 )
{
struct V_64 * V_65 ;
int V_19 ;
V_65 = F_53 ( V_20 ) ;
if ( ! V_65 )
return;
if ( V_65 -> V_76 )
F_51 ( & V_65 -> V_88 , & V_65 -> V_76 -> V_77 ) ;
V_19 = F_44 ( V_65 , V_86 , V_86 -> V_20 + V_95 ) ;
F_31 ( V_19 ) ;
V_19 = F_49 ( & V_65 -> V_88 , & V_65 -> V_76 -> V_77 ) ;
F_31 ( V_19 ) ;
F_63 ( & V_65 -> V_88 , V_96 ) ;
F_60 ( & V_65 -> V_88 ) ;
}
static void T_5 F_64 ( void )
{
struct V_14 * V_39 ;
unsigned int V_97 ;
char V_98 [ V_99 ] ;
for ( V_39 = V_100 ; V_39 < V_101 ; V_39 ++ ) {
char * V_102 ;
if ( V_39 -> V_75 == 0 )
continue;
V_102 = strchr ( V_39 -> V_20 , '.' ) ;
if ( ! V_102 ) {
strcpy ( V_98 , L_23 ) ;
V_97 = 0 ;
} else {
V_97 = V_102 - V_39 -> V_20 + 1 ;
F_38 ( V_98 , V_39 -> V_20 , V_97 ) ;
}
F_62 ( V_98 , V_39 , V_97 ) ;
}
}
T_3 F_65 ( struct V_62 * V_63 ,
struct V_64 * V_65 , char * V_66 )
{
struct V_103 * V_104 =
F_66 ( V_63 , struct V_103 , V_63 ) ;
return sprintf ( V_66 , L_24 , V_104 -> V_105 ) ;
}
static void T_5 F_67 ( void )
{
const struct V_103 * * V_3 ;
struct V_64 * V_65 ;
int V_19 ;
for ( V_3 = V_106 ; V_3 < V_107 ; V_3 ++ ) {
const struct V_103 * V_104 = * V_3 ;
V_65 = F_53 ( V_104 -> V_108 ) ;
if ( V_65 ) {
V_19 = F_59 ( & V_65 -> V_88 , & V_104 -> V_63 . V_80 ) ;
F_63 ( & V_65 -> V_88 , V_96 ) ;
F_60 ( & V_65 -> V_88 ) ;
}
}
}
static T_3 F_68 ( struct V_89 * V_88 ,
struct V_69 * V_80 ,
char * V_66 )
{
struct V_62 * V_69 ;
struct V_64 * V_65 ;
int V_34 ;
V_69 = F_69 ( V_80 ) ;
V_65 = F_55 ( V_88 ) ;
if ( ! V_69 -> V_81 )
return - V_109 ;
V_34 = V_69 -> V_81 ( V_69 , V_65 , V_66 ) ;
return V_34 ;
}
static T_3 F_70 ( struct V_89 * V_88 ,
struct V_69 * V_80 ,
const char * V_66 , T_1 V_52 )
{
struct V_62 * V_69 ;
struct V_64 * V_65 ;
int V_34 ;
V_69 = F_69 ( V_80 ) ;
V_65 = F_55 ( V_88 ) ;
if ( ! V_69 -> V_82 )
return - V_109 ;
V_34 = V_69 -> V_82 ( V_69 , V_65 , V_66 , V_52 ) ;
return V_34 ;
}
static int F_71 ( struct V_92 * V_92 , struct V_89 * V_88 )
{
struct V_110 * V_111 = F_72 ( V_88 ) ;
if ( V_111 == & V_93 )
return 1 ;
return 0 ;
}
static int T_5 F_73 ( void )
{
V_90 = F_74 ( L_25 , & V_112 , NULL ) ;
if ( ! V_90 ) {
F_21 ( V_36 L_26 ,
__FILE__ , __LINE__ ) ;
return - V_41 ;
}
V_113 = 1 ;
F_67 () ;
F_64 () ;
return 0 ;
}
