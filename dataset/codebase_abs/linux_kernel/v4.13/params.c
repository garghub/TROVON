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
char * F_25 ( const char * V_24 ,
char * args ,
const struct V_17 * V_25 ,
unsigned V_37 ,
T_2 V_27 ,
T_2 V_28 ,
void * V_29 ,
int (* F_26)( char * V_11 , char * V_10 ,
const char * V_24 , void * V_29 ) )
{
char * V_11 , * V_10 , * V_30 = NULL ;
args = F_27 ( args ) ;
if ( * args )
F_22 ( L_5 , V_24 , args ) ;
while ( * args ) {
int V_38 ;
int V_39 ;
args = F_28 ( args , & V_11 , & V_10 ) ;
if ( ! V_10 && strcmp ( V_11 , L_6 ) == 0 )
return V_30 ? : args ;
V_39 = F_29 () ;
V_38 = F_20 ( V_11 , V_10 , V_24 , V_25 , V_37 ,
V_27 , V_28 , V_29 , F_26 ) ;
if ( V_39 && ! F_29 () )
F_18 ( L_7 ,
V_24 , V_11 ) ;
switch ( V_38 ) {
case 0 :
continue;
case - V_36 :
F_30 ( L_8 , V_24 , V_11 ) ;
break;
case - V_40 :
F_30 ( L_9 ,
V_24 , V_10 ? : L_10 , V_11 ) ;
break;
default:
F_30 ( L_11 ,
V_24 , V_10 ? : L_10 , V_11 ) ;
break;
}
V_30 = F_31 ( V_38 ) ;
}
return V_30 ;
}
int F_32 ( const char * V_10 , const struct V_17 * V_18 )
{
if ( strlen ( V_10 ) > 1024 ) {
F_30 ( L_12 , V_18 -> V_21 ) ;
return - V_40 ;
}
F_10 ( * ( char * * ) V_18 -> V_29 ) ;
if ( F_33 () ) {
* ( char * * ) V_18 -> V_29 = F_5 ( strlen ( V_10 ) + 1 ) ;
if ( ! * ( char * * ) V_18 -> V_29 )
return - V_41 ;
strcpy ( * ( char * * ) V_18 -> V_29 , V_10 ) ;
} else
* ( const char * * ) V_18 -> V_29 = V_10 ;
return 0 ;
}
int F_34 ( char * V_42 , const struct V_17 * V_18 )
{
return F_35 ( V_42 , V_43 , L_13 , * ( ( char * * ) V_18 -> V_29 ) ) ;
}
void F_36 ( void * V_29 )
{
F_10 ( * ( ( char * * ) V_29 ) ) ;
}
int F_37 ( const char * V_10 , const struct V_17 * V_18 )
{
if ( ! V_10 ) V_10 = L_14 ;
return F_38 ( V_10 , V_18 -> V_29 ) ;
}
int F_39 ( char * V_42 , const struct V_17 * V_18 )
{
return sprintf ( V_42 , L_15 , * ( bool * ) V_18 -> V_29 ? 'Y' : 'N' ) ;
}
int F_40 ( const char * V_10 , const struct V_17 * V_18 )
{
int V_30 = 0 ;
bool V_44 ;
bool V_45 = * ( bool * ) V_18 -> V_29 ;
struct V_17 V_46 = * V_18 ;
V_46 . V_29 = & V_44 ;
V_30 = F_37 ( V_10 , & V_46 ) ;
if ( V_30 )
return V_30 ;
if ( ! V_44 && V_45 )
return - V_47 ;
if ( V_44 )
V_30 = F_37 ( V_10 , V_18 ) ;
return V_30 ;
}
int F_41 ( const char * V_10 , const struct V_17 * V_18 )
{
int V_38 ;
bool V_48 ;
struct V_17 V_49 ;
V_49 . V_29 = & V_48 ;
V_38 = F_37 ( V_10 , & V_49 ) ;
if ( V_38 == 0 )
* ( bool * ) V_18 -> V_29 = ! V_48 ;
return V_38 ;
}
int F_42 ( char * V_42 , const struct V_17 * V_18 )
{
return sprintf ( V_42 , L_15 , ( * ( bool * ) V_18 -> V_29 ) ? 'N' : 'Y' ) ;
}
int F_43 ( const char * V_10 , const struct V_17 * V_18 )
{
struct V_17 V_50 = * V_18 ;
bool V_51 ;
int V_38 ;
V_50 . V_29 = & V_51 ;
V_38 = F_37 ( V_10 , & V_50 ) ;
if ( V_38 == 0 )
* ( int * ) V_18 -> V_29 = V_51 ;
return V_38 ;
}
static int F_44 ( struct V_1 * V_2 ,
const char * V_21 ,
const char * V_10 ,
unsigned int V_52 , unsigned int V_53 ,
void * V_54 , int V_55 ,
int (* V_35)( const char * , const struct V_17 * V_18 ) ,
T_2 V_31 ,
unsigned int * V_37 )
{
int V_38 ;
struct V_17 V_18 ;
char V_56 ;
V_18 . V_21 = V_21 ;
V_18 . V_29 = V_54 ;
V_18 . V_31 = V_31 ;
* V_37 = 0 ;
do {
int V_57 ;
if ( * V_37 == V_53 ) {
F_30 ( L_16 , V_21 , V_53 ) ;
return - V_34 ;
}
V_57 = strcspn ( V_10 , L_17 ) ;
V_56 = V_10 [ V_57 ] ;
( ( char * ) V_10 ) [ V_57 ] = '\0' ;
F_1 ( V_2 ) ;
V_38 = V_35 ( V_10 , & V_18 ) ;
if ( V_38 != 0 )
return V_38 ;
V_18 . V_29 += V_55 ;
V_10 += V_57 + 1 ;
( * V_37 ) ++ ;
} while ( V_56 == ',' );
if ( * V_37 < V_52 ) {
F_30 ( L_18 , V_21 , V_52 ) ;
return - V_34 ;
}
return 0 ;
}
static int F_45 ( const char * V_10 , const struct V_17 * V_18 )
{
const struct V_58 * V_59 = V_18 -> V_59 ;
unsigned int V_60 ;
return F_44 ( V_18 -> V_2 , V_18 -> V_21 , V_10 , 1 , V_59 -> V_53 , V_59 -> V_54 ,
V_59 -> V_55 , V_59 -> V_32 -> V_35 , V_18 -> V_31 ,
V_59 -> V_37 ? : & V_60 ) ;
}
static int F_46 ( char * V_42 , const struct V_17 * V_18 )
{
int V_16 , V_61 , V_38 ;
const struct V_58 * V_59 = V_18 -> V_59 ;
struct V_17 V_5 = * V_18 ;
for ( V_16 = V_61 = 0 ; V_16 < ( V_59 -> V_37 ? * V_59 -> V_37 : V_59 -> V_53 ) ; V_16 ++ ) {
if ( V_16 )
V_42 [ V_61 ++ ] = ',' ;
V_5 . V_29 = V_59 -> V_54 + V_59 -> V_55 * V_16 ;
F_1 ( V_5 . V_2 ) ;
V_38 = V_59 -> V_32 -> V_62 ( V_42 + V_61 , & V_5 ) ;
if ( V_38 < 0 )
return V_38 ;
V_61 += V_38 ;
}
V_42 [ V_61 ] = '\0' ;
return V_61 ;
}
static void F_47 ( void * V_29 )
{
unsigned int V_16 ;
const struct V_58 * V_59 = V_29 ;
if ( V_59 -> V_32 -> free )
for ( V_16 = 0 ; V_16 < ( V_59 -> V_37 ? * V_59 -> V_37 : V_59 -> V_53 ) ; V_16 ++ )
V_59 -> V_32 -> free ( V_59 -> V_54 + V_59 -> V_55 * V_16 ) ;
}
int F_48 ( const char * V_10 , const struct V_17 * V_18 )
{
const struct V_63 * V_64 = V_18 -> V_65 ;
if ( strlen ( V_10 ) + 1 > V_64 -> V_66 ) {
F_30 ( L_19 ,
V_18 -> V_21 , V_64 -> V_66 - 1 ) ;
return - V_40 ;
}
strcpy ( V_64 -> string , V_10 ) ;
return 0 ;
}
int F_49 ( char * V_42 , const struct V_17 * V_18 )
{
const struct V_63 * V_64 = V_18 -> V_65 ;
return F_50 ( V_42 , V_64 -> string , V_64 -> V_66 ) ;
}
static T_3 F_51 ( struct V_67 * V_68 ,
struct V_69 * V_70 , char * V_71 )
{
int V_72 ;
struct V_73 * V_74 = F_52 ( V_68 ) ;
if ( ! V_74 -> V_11 -> V_32 -> V_62 )
return - V_75 ;
F_23 ( V_70 -> V_2 ) ;
V_72 = V_74 -> V_11 -> V_32 -> V_62 ( V_71 , V_74 -> V_11 ) ;
F_24 ( V_70 -> V_2 ) ;
if ( V_72 > 0 ) {
strcat ( V_71 , L_20 ) ;
++ V_72 ;
}
return V_72 ;
}
static T_3 F_53 ( struct V_67 * V_68 ,
struct V_69 * V_70 ,
const char * V_71 , T_1 V_57 )
{
int V_30 ;
struct V_73 * V_74 = F_52 ( V_68 ) ;
if ( ! V_74 -> V_11 -> V_32 -> V_35 )
return - V_75 ;
F_23 ( V_70 -> V_2 ) ;
F_17 ( V_74 -> V_11 ) ;
V_30 = V_74 -> V_11 -> V_32 -> V_35 ( V_71 , V_74 -> V_11 ) ;
F_24 ( V_70 -> V_2 ) ;
if ( ! V_30 )
return V_57 ;
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
static T_4 int F_56 ( struct V_69 * V_70 ,
const struct V_17 * V_18 ,
const char * V_21 )
{
struct V_76 * V_77 ;
struct V_74 * * V_78 ;
unsigned int V_16 ;
F_2 ( ! V_18 -> V_79 ) ;
if ( ! V_70 -> V_80 ) {
V_70 -> V_80 = F_57 ( sizeof( * V_70 -> V_80 ) , V_6 ) ;
if ( ! V_70 -> V_80 )
return - V_41 ;
V_70 -> V_80 -> V_81 . V_21 = L_21 ;
V_70 -> V_80 -> V_81 . V_82 = F_57 ( sizeof( V_70 -> V_80 -> V_81 . V_82 [ 0 ] ) ,
V_6 ) ;
if ( ! V_70 -> V_80 -> V_81 . V_82 )
return - V_41 ;
}
V_77 = F_58 ( V_70 -> V_80 ,
sizeof( * V_70 -> V_80 ) +
sizeof( V_70 -> V_80 -> V_82 [ 0 ] ) * ( V_70 -> V_80 -> V_37 + 1 ) ,
V_6 ) ;
if ( ! V_77 )
return - V_41 ;
V_70 -> V_80 = V_77 ;
V_78 = F_58 ( V_70 -> V_80 -> V_81 . V_82 ,
sizeof( V_70 -> V_80 -> V_81 . V_82 [ 0 ] ) * ( V_70 -> V_80 -> V_37 + 2 ) ,
V_6 ) ;
if ( ! V_78 )
return - V_41 ;
V_70 -> V_80 -> V_81 . V_82 = V_78 ;
memset ( & V_70 -> V_80 -> V_82 [ V_70 -> V_80 -> V_37 ] , 0 , sizeof( V_70 -> V_80 -> V_82 [ 0 ] ) ) ;
F_59 ( & V_70 -> V_80 -> V_82 [ V_70 -> V_80 -> V_37 ] . V_68 . V_83 ) ;
V_70 -> V_80 -> V_82 [ V_70 -> V_80 -> V_37 ] . V_11 = V_18 ;
V_70 -> V_80 -> V_82 [ V_70 -> V_80 -> V_37 ] . V_68 . V_84 = F_51 ;
if ( ( V_18 -> V_79 & ( V_85 | V_86 | V_87 ) ) != 0 )
V_70 -> V_80 -> V_82 [ V_70 -> V_80 -> V_37 ] . V_68 . V_88 = F_53 ;
else
V_70 -> V_80 -> V_82 [ V_70 -> V_80 -> V_37 ] . V_68 . V_88 = NULL ;
V_70 -> V_80 -> V_82 [ V_70 -> V_80 -> V_37 ] . V_68 . V_83 . V_21 = ( char * ) V_21 ;
V_70 -> V_80 -> V_82 [ V_70 -> V_80 -> V_37 ] . V_68 . V_83 . V_89 = V_18 -> V_79 ;
V_70 -> V_80 -> V_37 ++ ;
for ( V_16 = 0 ; V_16 < V_70 -> V_80 -> V_37 ; V_16 ++ )
V_70 -> V_80 -> V_81 . V_82 [ V_16 ] = & V_70 -> V_80 -> V_82 [ V_16 ] . V_68 . V_83 ;
V_70 -> V_80 -> V_81 . V_82 [ V_70 -> V_80 -> V_37 ] = NULL ;
return 0 ;
}
static void F_60 ( struct V_69 * V_70 )
{
if ( V_70 -> V_80 )
F_13 ( V_70 -> V_80 -> V_81 . V_82 ) ;
F_13 ( V_70 -> V_80 ) ;
V_70 -> V_80 = NULL ;
}
int F_61 ( struct V_1 * V_2 ,
const struct V_17 * V_90 ,
unsigned int V_26 )
{
int V_16 , V_30 ;
bool V_25 = false ;
for ( V_16 = 0 ; V_16 < V_26 ; V_16 ++ ) {
if ( V_90 [ V_16 ] . V_79 == 0 )
continue;
V_30 = F_56 ( & V_2 -> V_91 , & V_90 [ V_16 ] , V_90 [ V_16 ] . V_21 ) ;
if ( V_30 ) {
F_60 ( & V_2 -> V_91 ) ;
return V_30 ;
}
V_25 = true ;
}
if ( ! V_25 )
return 0 ;
V_30 = F_62 ( & V_2 -> V_91 . V_92 , & V_2 -> V_91 . V_80 -> V_81 ) ;
if ( V_30 )
F_60 ( & V_2 -> V_91 ) ;
return V_30 ;
}
void F_63 ( struct V_1 * V_2 )
{
if ( V_2 -> V_91 . V_80 ) {
F_64 ( & V_2 -> V_91 . V_92 , & V_2 -> V_91 . V_80 -> V_81 ) ;
F_60 ( & V_2 -> V_91 ) ;
}
}
void F_65 ( const struct V_17 * V_25 , unsigned V_37 )
{
unsigned int V_16 ;
for ( V_16 = 0 ; V_16 < V_37 ; V_16 ++ )
if ( V_25 [ V_16 ] . V_32 -> free )
V_25 [ V_16 ] . V_32 -> free ( V_25 [ V_16 ] . V_29 ) ;
}
static struct V_69 * T_5 F_66 ( const char * V_21 )
{
struct V_69 * V_70 ;
struct V_93 * V_92 ;
int V_30 ;
V_92 = F_67 ( V_94 , V_21 ) ;
if ( V_92 ) {
V_70 = F_68 ( V_92 ) ;
} else {
V_70 = F_57 ( sizeof( struct V_69 ) , V_6 ) ;
F_2 ( ! V_70 ) ;
V_70 -> V_2 = V_95 ;
V_70 -> V_92 . V_96 = V_94 ;
V_30 = F_69 ( & V_70 -> V_92 , & V_97 , NULL ,
L_13 , V_21 ) ;
#ifdef F_70
if ( ! V_30 )
V_30 = F_71 ( & V_70 -> V_92 , & V_98 . V_83 ) ;
#endif
if ( V_30 ) {
F_72 ( & V_70 -> V_92 ) ;
F_73 ( L_22 ,
V_21 , V_30 ) ;
return NULL ;
}
F_74 ( & V_70 -> V_92 ) ;
}
return V_70 ;
}
static void T_5 F_75 ( const char * V_21 ,
const struct V_17 * V_90 ,
unsigned int V_99 )
{
struct V_69 * V_70 ;
int V_30 ;
V_70 = F_66 ( V_21 ) ;
if ( ! V_70 )
return;
if ( V_70 -> V_80 )
F_64 ( & V_70 -> V_92 , & V_70 -> V_80 -> V_81 ) ;
V_30 = F_56 ( V_70 , V_90 , V_90 -> V_21 + V_99 ) ;
F_2 ( V_30 ) ;
V_30 = F_62 ( & V_70 -> V_92 , & V_70 -> V_80 -> V_81 ) ;
F_2 ( V_30 ) ;
F_76 ( & V_70 -> V_92 , V_100 ) ;
F_72 ( & V_70 -> V_92 ) ;
}
static void T_5 F_77 ( void )
{
const struct V_17 * V_18 ;
unsigned int V_101 ;
char V_102 [ V_103 ] ;
for ( V_18 = V_104 ; V_18 < V_105 ; V_18 ++ ) {
char * V_106 ;
if ( V_18 -> V_79 == 0 )
continue;
V_106 = strchr ( V_18 -> V_21 , '.' ) ;
if ( ! V_106 ) {
strcpy ( V_102 , L_23 ) ;
V_101 = 0 ;
} else {
V_101 = V_106 - V_18 -> V_21 + 1 ;
F_50 ( V_102 , V_18 -> V_21 , V_101 ) ;
}
F_75 ( V_102 , V_18 , V_101 ) ;
}
}
T_3 F_78 ( struct V_67 * V_68 ,
struct V_69 * V_70 , char * V_71 )
{
struct V_107 * V_108 =
F_79 ( V_68 , struct V_107 , V_68 ) ;
return F_35 ( V_71 , V_43 , L_24 , V_108 -> V_109 ) ;
}
static void T_5 F_80 ( void )
{
const struct V_107 * * V_5 ;
struct V_69 * V_70 ;
int V_30 ;
for ( V_5 = V_110 ; V_5 < V_111 ; V_5 ++ ) {
const struct V_107 * V_108 = * V_5 ;
V_70 = F_66 ( V_108 -> V_112 ) ;
if ( V_70 ) {
V_30 = F_71 ( & V_70 -> V_92 , & V_108 -> V_68 . V_83 ) ;
F_81 ( V_30 ) ;
F_76 ( & V_70 -> V_92 , V_100 ) ;
F_72 ( & V_70 -> V_92 ) ;
}
}
}
static T_3 F_82 ( struct V_93 * V_92 ,
struct V_74 * V_83 ,
char * V_71 )
{
struct V_67 * V_74 ;
struct V_69 * V_70 ;
int V_38 ;
V_74 = F_83 ( V_83 ) ;
V_70 = F_68 ( V_92 ) ;
if ( ! V_74 -> V_84 )
return - V_113 ;
V_38 = V_74 -> V_84 ( V_74 , V_70 , V_71 ) ;
return V_38 ;
}
static T_3 F_84 ( struct V_93 * V_92 ,
struct V_74 * V_83 ,
const char * V_71 , T_1 V_57 )
{
struct V_67 * V_74 ;
struct V_69 * V_70 ;
int V_38 ;
V_74 = F_83 ( V_83 ) ;
V_70 = F_68 ( V_92 ) ;
if ( ! V_74 -> V_88 )
return - V_113 ;
V_38 = V_74 -> V_88 ( V_74 , V_70 , V_71 , V_57 ) ;
return V_38 ;
}
static int F_85 ( struct V_96 * V_96 , struct V_93 * V_92 )
{
struct V_114 * V_115 = F_86 ( V_92 ) ;
if ( V_115 == & V_97 )
return 1 ;
return 0 ;
}
static void F_87 ( struct V_93 * V_92 )
{
struct V_69 * V_70 = F_68 ( V_92 ) ;
F_88 ( V_70 -> V_116 ) ;
}
static int T_5 F_89 ( void )
{
V_94 = F_90 ( L_25 , & V_117 , NULL ) ;
if ( ! V_94 ) {
F_91 ( V_118 L_26 ,
__FILE__ , __LINE__ ) ;
return - V_41 ;
}
V_119 = 1 ;
F_80 () ;
F_77 () ;
return 0 ;
}
