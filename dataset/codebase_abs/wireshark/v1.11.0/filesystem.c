char *
F_1 ( const char * V_1 )
{
char * V_2 ;
#ifdef F_2
char V_3 ;
V_2 = strchr ( V_1 , '\0' ) ;
while ( V_2 > V_1 ) {
V_3 = * -- V_2 ;
if ( V_3 == '\\' || V_3 == '/' )
return V_2 ;
}
return strchr ( V_1 , ':' ) ;
#else
V_2 = strrchr ( V_1 , '/' ) ;
return V_2 ;
#endif
}
const char *
F_3 ( const char * V_1 )
{
const char * V_4 ;
F_4 ( V_1 != NULL ) ;
V_4 = F_1 ( V_1 ) ;
if ( V_4 == NULL ) {
V_4 = V_1 ;
} else {
V_4 ++ ;
}
return V_4 ;
}
char *
F_5 ( char * V_1 )
{
char * V_2 ;
F_4 ( V_1 != NULL ) ;
V_2 = F_1 ( V_1 ) ;
if ( V_2 == NULL ) {
return NULL ;
}
* V_2 = '\0' ;
return V_1 ;
}
int
F_6 ( const char * V_1 )
{
T_1 V_5 ;
if ( F_7 ( V_1 , & V_5 ) < 0 )
return V_6 ;
if ( F_8 ( V_5 . V_7 ) )
return V_8 ;
else
return 0 ;
}
int
F_9 ( const char * V_1 )
{
T_1 V_5 ;
if ( F_7 ( V_1 , & V_5 ) < 0 )
return V_6 ;
if ( F_10 ( V_5 . V_7 ) )
return V_9 ;
else
return 0 ;
}
const char *
F_11 ( void )
{
#if F_12 ( V_10 )
char * V_11 ;
T_2 V_12 ;
V_12 = V_13 ;
V_11 = ( char * ) F_13 ( V_12 ) ;
if ( F_14 ( V_11 , & V_12 ) == - 1 ) {
V_11 = ( char * ) F_15 ( V_11 , V_12 ) ;
if ( F_14 ( V_11 , & V_12 ) == - 1 )
return NULL ;
}
return V_11 ;
#elif F_12 ( V_14 )
struct V_15 V_16 ;
static char V_11 [ V_13 ] ;
if ( F_16 ( & V_16 ) == - 1 )
return NULL ;
if ( strncmp ( V_16 . V_17 , L_1 , 2 ) == 0 )
return NULL ;
if ( strcmp ( V_16 . V_17 , L_2 ) == 0 ||
strncmp ( V_16 . V_17 , L_3 , 4 ) == 0 ||
strcmp ( V_16 . V_17 , L_4 ) == 0 ||
strncmp ( V_16 . V_17 , L_5 , 4 ) == 0 )
return NULL ;
if ( F_17 ( L_6 , V_11 , sizeof V_11 ) == - 1 )
return NULL ;
return V_11 ;
#elif F_12 ( V_18 ) && F_12 ( V_19 )
int V_20 [ 4 ] ;
char * V_11 ;
T_3 V_12 ;
V_20 [ 0 ] = V_21 ;
V_20 [ 1 ] = V_22 ;
V_20 [ 2 ] = V_19 ;
V_20 [ 3 ] = - 1 ;
V_12 = V_13 ;
V_11 = ( char * ) F_13 ( V_12 ) ;
if ( F_18 ( V_20 , 4 , V_11 , & V_12 , NULL , 0 ) == - 1 ) {
if ( V_6 != V_23 )
return NULL ;
V_11 = ( char * ) F_15 ( V_11 , V_12 ) ;
if ( F_18 ( V_20 , 4 , V_11 , & V_12 , NULL , 0 ) == - 1 )
return NULL ;
}
return V_11 ;
#elif F_12 ( V_24 )
static char V_11 [ V_13 ] ;
if ( F_17 ( L_7 , V_11 , sizeof V_11 ) == - 1 )
return NULL ;
return V_11 ;
#elif F_12 ( V_25 )
static char V_11 [ V_13 ] ;
if ( F_17 ( L_8 , V_11 , sizeof V_11 ) == - 1 )
return NULL ;
return V_11 ;
#elif ( F_12 ( V_26 ) || F_12 ( V_27 ) ) && F_12 ( V_28 )
return F_19 () ;
#else
return NULL ;
#endif
}
const char *
F_20 ( void )
{
return V_29 ;
}
const char *
F_21 ( void )
{
#ifdef F_2
char * V_30 ;
#endif
static const char * V_31 = NULL ;
if ( V_31 != NULL )
return V_31 ;
#ifdef F_2
V_30 = F_22 ( L_9 ) ;
if ( V_30 != NULL ) {
V_31 = V_30 ;
} else {
if ( V_29 != NULL ) {
V_31 = V_29 ;
} else {
V_31 = L_10 ;
}
}
#else
if ( V_32 ) {
V_31 = getenv ( L_11 ) ;
if ( V_31 != NULL )
return V_31 ;
}
if ( V_32 && V_29 != NULL ) {
V_31 = V_29 ;
} else {
if ( getenv ( L_12 ) && ! F_23 () ) {
V_31 = F_24 ( getenv ( L_12 ) ) ;
}
#ifdef V_10
else if ( V_33 != NULL ) {
V_31 = F_25 ( L_13 ,
V_33 ) ;
}
#endif
else {
V_31 = V_34 ;
}
}
#endif
return V_31 ;
}
static void
F_26 ( void )
{
#ifdef F_2
V_35 = F_25 ( L_14 , F_21 () ,
V_36 ) ;
if ( F_6 ( V_35 ) != V_8 ) {
F_27 ( ( V_37 ) V_35 ) ;
V_35 = F_25 ( L_15 , F_21 () ) ;
V_32 = TRUE ;
}
#else
if ( V_32 ) {
V_35 = F_25 ( L_16 , F_21 () ) ;
} else {
if ( getenv ( L_17 ) && ! F_23 () ) {
V_35 = F_24 ( getenv ( L_17 ) ) ;
}
#ifdef V_10
else if ( V_33 != NULL ) {
V_35 = F_25 ( L_18 ,
V_33 ) ;
}
#endif
else {
V_35 = V_38 ;
}
}
#endif
}
const char *
F_28 ( void )
{
#ifdef F_29
if ( ! V_35 ) F_26 () ;
return V_35 ;
#else
return NULL ;
#endif
}
static void
F_30 ( void )
{
#ifdef F_2
V_39 = F_25 ( L_19 , F_21 () ,
V_36 ) ;
if ( F_6 ( V_39 ) != V_8 ) {
F_27 ( ( V_37 ) V_39 ) ;
V_39 = F_25 ( L_20 , F_21 () ) ;
V_32 = TRUE ;
}
#else
if ( V_32 ) {
V_39 = F_25 ( L_21 , F_21 () ) ;
} else {
if ( getenv ( L_22 ) && ! F_23 () ) {
V_39 = F_24 ( getenv ( L_22 ) ) ;
}
#ifdef V_10
else if ( V_33 != NULL ) {
V_39 = F_25 ( L_23 ,
V_33 ) ;
}
#endif
else {
V_39 = V_40 ;
}
}
#endif
}
const char *
F_31 ( void )
{
#if F_12 ( V_41 ) || F_12 ( V_42 )
if ( ! V_39 ) F_30 () ;
return V_39 ;
#else
return NULL ;
#endif
}
T_4
F_32 ( void )
{
return V_32 ;
}
const char *
F_33 ( void )
{
#ifdef F_2
return F_21 () ;
#else
return L_24 ;
#endif
}
void
F_34 ( const T_5 * V_43 )
{
F_27 ( V_44 ) ;
if ( V_43 && strlen ( V_43 ) > 0 &&
strcmp ( V_43 , V_45 ) != 0 ) {
V_44 = F_24 ( V_43 ) ;
} else {
V_44 = NULL ;
}
}
const char *
F_35 ( void )
{
if ( V_44 ) {
return V_44 ;
} else {
return V_45 ;
}
}
T_4
F_36 ( void )
{
return ( ! V_44 || strcmp ( V_44 , V_45 ) == 0 ) ? TRUE : FALSE ;
}
T_4
F_37 ( void )
{
T_6 * V_46 ;
T_7 * V_47 ;
const T_5 * V_48 = F_38 () ;
T_5 * V_4 ;
T_4 V_49 = FALSE ;
if ( ( F_6 ( V_48 ) == V_8 ) &&
( ( V_46 = F_39 ( V_48 , 0 , NULL ) ) != NULL ) )
{
while ( ( V_47 = F_40 ( V_46 ) ) != NULL ) {
V_4 = F_25 ( L_25 , V_48 , V_50 ,
F_41 ( V_47 ) ) ;
if ( F_6 ( V_4 ) == V_8 ) {
V_49 = TRUE ;
F_27 ( V_4 ) ;
break;
}
F_27 ( V_4 ) ;
}
F_42 ( V_46 ) ;
}
return V_49 ;
}
void
F_43 ( T_4 V_51 )
{
if ( V_51 ) {
V_52 = F_44 ( V_53 , V_54 ) ;
}
V_55 = V_51 ;
}
static const char *
F_45 ( void )
{
#ifdef F_2
char * V_56 ;
char * V_57 ;
char * V_58 ;
#else
const char * V_59 ;
struct V_60 * V_61 ;
#endif
if ( V_62 != NULL )
return V_62 ;
#ifdef F_2
V_58 = F_22 ( L_26 ) ;
if ( V_58 != NULL ) {
V_62 = V_58 ;
return V_62 ;
}
V_58 = F_22 ( L_27 ) ;
if ( V_58 != NULL ) {
V_62 = V_58 ;
} else {
V_56 = F_22 ( L_28 ) ;
if ( V_56 != NULL ) {
V_62 = F_25 ( L_29 V_50 L_29 ,
V_56 , V_63 ) ;
} else {
V_57 = F_22 ( L_30 ) ;
if ( V_57 != NULL ) {
V_62 = F_25 (
L_29 V_50 L_31 V_50 L_29 ,
V_57 , V_63 ) ;
} else {
V_62 = F_25 ( L_32 V_50 L_29 , V_63 ) ;
}
}
}
#else
V_59 = getenv ( L_33 ) ;
if ( V_59 == NULL ) {
V_61 = F_46 ( F_47 () ) ;
if ( V_61 != NULL ) {
V_59 = V_61 -> V_64 ;
} else {
V_59 = L_34 ;
}
}
V_62 = F_25 ( L_29 V_50 L_29 , V_59 , V_63 ) ;
#endif
return V_62 ;
}
const char *
F_48 ( void )
{
static char * V_65 = NULL ;
F_27 ( V_65 ) ;
V_65 = F_25 ( L_25 , F_45 () ,
V_50 , V_66 ) ;
return V_65 ;
}
const char *
F_38 ( void )
{
static char * V_67 = NULL ;
if ( ! V_67 ) {
V_67 = F_25 ( L_25 , F_21 () ,
V_50 , V_66 ) ;
}
return V_67 ;
}
static const char *
F_49 ( const T_5 * V_43 )
{
static char * V_68 = NULL ;
F_27 ( V_68 ) ;
if ( V_43 && strlen ( V_43 ) > 0 &&
strcmp ( V_43 , V_45 ) != 0 ) {
V_68 = F_25 ( L_25 , F_48 () ,
V_50 , V_43 ) ;
} else {
V_68 = F_24 ( F_45 () ) ;
}
return V_68 ;
}
T_4
F_50 ( const T_5 * V_43 , T_4 V_69 )
{
if ( V_69 ) {
T_5 * V_1 = F_25 ( L_25 , F_38 () ,
V_50 , V_43 ) ;
if ( F_6 ( V_1 ) == V_8 ) {
F_27 ( V_1 ) ;
return TRUE ;
}
F_27 ( V_1 ) ;
} else {
if ( F_6 ( F_49 ( V_43 ) ) == V_8 ) {
return TRUE ;
}
}
return FALSE ;
}
static int
F_51 ( const char * V_70 , char * * V_71 )
{
T_6 * V_46 ;
T_7 * V_47 ;
T_5 * V_4 ;
int V_72 = 0 ;
if ( ( V_46 = F_39 ( V_70 , 0 , NULL ) ) != NULL ) {
while ( ( V_47 = F_40 ( V_46 ) ) != NULL ) {
V_4 = F_25 ( L_25 , V_70 , V_50 ,
F_41 ( V_47 ) ) ;
if ( F_6 ( V_4 ) != V_8 ) {
V_72 = F_52 ( V_4 ) ;
#if 0
} else {
ret = delete_directory (filename, pf_dir_path_return);
#endif
}
if ( V_72 != 0 ) {
* V_71 = V_4 ;
break;
}
F_27 ( V_4 ) ;
}
F_42 ( V_46 ) ;
}
if ( V_72 == 0 && ( V_72 = F_52 ( V_70 ) ) != 0 ) {
* V_71 = F_24 ( V_70 ) ;
}
return V_72 ;
}
int
F_53 ( const char * V_43 , char * * V_71 )
{
const char * V_73 = F_49 ( V_43 ) ;
int V_72 = 0 ;
if ( F_6 ( V_73 ) == V_8 ) {
V_72 = F_51 ( V_73 , V_71 ) ;
}
return V_72 ;
}
int
F_54 ( const char * V_74 , const char * V_75 ,
char * * V_76 , char * * V_77 )
{
char * V_78 = F_24 ( F_49 ( V_74 ) ) ;
char * V_79 = F_24 ( F_49 ( V_75 ) ) ;
int V_72 = 0 ;
V_72 = F_55 ( V_78 , V_79 ) ;
if ( V_72 != 0 ) {
* V_76 = F_24 ( V_78 ) ;
* V_77 = F_24 ( V_79 ) ;
}
F_27 ( V_78 ) ;
F_27 ( V_79 ) ;
return V_72 ;
}
int
F_56 ( const char * V_43 , char * * V_71 )
{
const char * V_80 ;
#ifdef F_2
char * V_81 , * V_82 ;
T_3 V_83 ;
#endif
T_1 V_84 ;
int V_72 ;
if ( V_43 ) {
if ( F_56 ( NULL , V_71 ) == - 1 ) {
return - 1 ;
}
V_80 = F_48 () ;
if ( F_7 ( V_80 , & V_84 ) != 0 && V_6 == V_85 ) {
V_72 = F_57 ( V_80 , 0755 ) ;
if ( V_72 == - 1 ) {
* V_71 = F_24 ( V_80 ) ;
return V_72 ;
}
}
}
V_80 = F_49 ( V_43 ) ;
if ( F_7 ( V_80 , & V_84 ) != 0 && V_6 == V_85 ) {
#ifdef F_2
V_81 = F_24 ( V_80 ) ;
V_82 = F_5 ( V_81 ) ;
V_83 = strlen ( V_82 ) ;
if ( V_83 > 0
&& V_82 [ V_83 - 1 ] != ':'
&& F_7 ( V_82 , & V_84 ) != 0 ) {
V_72 = F_57 ( V_82 , 0755 ) ;
if ( V_72 == - 1 ) {
* V_71 = V_82 ;
return - 1 ;
}
}
F_27 ( V_81 ) ;
V_72 = F_57 ( V_80 , 0755 ) ;
#else
V_72 = F_57 ( V_80 , 0755 ) ;
#endif
} else {
V_72 = 0 ;
}
if ( V_72 == - 1 )
* V_71 = F_24 ( V_80 ) ;
return V_72 ;
}
int
F_58 ( char * * V_71 )
{
return F_56 ( V_44 , V_71 ) ;
}
int
F_59 ( const char * V_75 , const char * V_74 , T_4 V_86 ,
char * * V_87 , char * * V_77 , char * * V_76 )
{
T_5 * V_78 ;
T_5 * V_79 = F_24 ( F_49 ( V_75 ) ) ;
T_5 * V_4 , * V_88 , * V_89 ;
T_8 * V_90 , * V_47 ;
if ( V_86 ) {
if ( strcmp ( V_74 , V_45 ) == 0 ) {
V_78 = F_24 ( F_38 () ) ;
} else {
V_78 = F_25 ( L_25 , F_38 () , V_50 , V_74 ) ;
}
} else {
V_78 = F_24 ( F_49 ( V_74 ) ) ;
}
V_90 = F_60 ( V_52 ) ;
V_47 = F_61 ( V_90 ) ;
while ( V_47 ) {
V_4 = ( T_5 * ) V_47 -> V_91 ;
V_88 = F_25 ( L_25 , V_78 , V_50 , V_4 ) ;
V_89 = F_25 ( L_25 , V_79 , V_50 , V_4 ) ;
if ( F_62 ( V_88 ) && ! F_63 ( V_88 , V_89 ) ) {
* V_87 = F_24 ( V_4 ) ;
* V_77 = V_79 ;
* V_76 = V_78 ;
F_27 ( V_88 ) ;
F_27 ( V_89 ) ;
return - 1 ;
}
F_27 ( V_88 ) ;
F_27 ( V_89 ) ;
V_47 = F_64 ( V_47 ) ;
}
F_65 ( V_90 ) ;
F_27 ( V_78 ) ;
F_27 ( V_79 ) ;
return 0 ;
}
extern const char *
F_66 ( void )
{
#ifdef F_2
char * V_92 ;
T_9 V_93 [ V_94 ] ;
char * V_95 ;
BOOL V_96 ;
if ( V_97 != NULL )
return V_97 ;
V_92 = F_22 ( L_35 ) ;
if ( V_92 != NULL ) {
V_95 = F_25 ( L_36 , V_92 , V_98 ) ;
V_97 = V_95 ;
return V_95 ;
} else {
V_96 = F_67 ( NULL , V_93 , V_99 ,
FALSE ) ;
if( V_96 == TRUE ) {
V_95 = F_68 ( V_93 ) ;
V_97 = V_95 ;
return V_95 ;
} else {
return L_37 ;
}
}
#else
return L_37 ;
#endif
}
static const char *
F_69 ( void )
{
static const char * V_100 = NULL ;
char * V_101 , * V_102 ;
char * V_103 ;
char * V_104 ;
if ( V_100 )
return V_100 ;
V_101 = F_22 ( L_38 ) ;
if ( V_101 != NULL ) {
V_102 = F_22 ( L_39 ) ;
if ( V_102 != NULL ) {
V_103 = F_25 ( L_36 , V_101 , V_102 ) ;
V_104 = F_1 ( V_103 ) ;
if ( V_104 != NULL && * ( V_104 + 1 ) == '\0' ) {
* V_104 = '\0' ;
}
V_100 = V_103 ;
} else
V_100 = V_101 ;
} else {
V_100 = L_32 ;
}
return V_100 ;
}
char *
F_70 ( const char * V_4 , T_4 V_105 )
{
char * V_1 ;
if ( V_55 && V_105 && ! F_71 ( V_52 , V_4 ) ) {
F_72 ( V_52 , F_24 ( V_4 ) , F_24 ( V_4 ) ) ;
}
if ( V_105 ) {
V_1 = F_25 ( L_29 V_50 L_29 ,
F_49 ( V_44 ) , V_4 ) ;
} else {
V_1 = F_25 ( L_29 V_50 L_29 ,
F_49 ( NULL ) , V_4 ) ;
}
return V_1 ;
}
int
F_73 ( int T_10 V_106 , const char * V_107 )
{
T_5 * V_108 , * V_109 ;
V_109 = strchr ( V_107 , ':' ) ;
if ( V_109 == NULL ) {
return 1 ;
}
V_108 = V_109 ;
* V_108 ++ = '\0' ;
while ( isspace ( ( V_110 ) * V_108 ) )
V_108 ++ ;
if ( * V_108 == '\0' ) {
* V_109 = ':' ;
return 1 ;
}
if( F_6 ( V_108 ) != V_8 ) {
* V_109 = ':' ;
return 1 ;
}
if ( strcmp ( V_107 , L_40 ) == 0 ) {
V_62 = V_108 ;
} else if ( strcmp ( V_107 , L_41 ) == 0 ) {
V_97 = V_108 ;
} else {
return 1 ;
}
* V_109 = ':' ;
return 0 ;
}
char *
F_74 ( const char * V_4 )
{
return F_25 ( L_29 V_50 L_29 , F_21 () , V_4 ) ;
}
char *
F_75 ( void )
{
return F_70 ( V_111 , FALSE ) ;
}
T_4
F_76 ( const char * V_1 )
{
return F_77 ( V_1 ) == 0 ;
}
char * F_78 ( const char * V_4 )
{
return F_25 ( L_29 V_50 L_29 , F_79 () , V_4 ) ;
}
const char *
F_80 ( int V_112 , T_4 V_113 )
{
const char * V_114 ;
static char V_115 [ 1024 + 1 ] ;
switch ( V_112 ) {
case V_85 :
if ( V_113 )
V_114 = L_42 ;
else
V_114 = L_43 ;
break;
case V_116 :
if ( V_113 )
V_114 = L_44 ;
else
V_114 = L_45 ;
break;
case V_8 :
V_114 = L_46 ;
break;
case V_117 :
V_114 = L_47 ;
break;
#ifdef F_81
case F_81 :
V_114 = L_48 ;
break;
#endif
case V_118 :
V_114 = L_49 ;
break;
case V_23 :
#if V_119 == 4
#define F_82 "it can't be handled by a 32-bit application"
#else
#if F_12 ( F_2 )
#define F_82 "the pagefile is too small"
#elif F_12 ( V_10 )
#define F_82 "your system ran out of swap file space"
#else
#define F_82 "your system is out of swap space"
#endif
#endif
if ( V_113 )
V_114 = L_50 F_82 L_51 ;
else
V_114 = L_52 F_82 L_51 ;
break;
default:
F_83 ( V_115 , sizeof( V_115 ) ,
L_53 ,
V_113 ? L_54 : L_55 ,
F_84 ( V_112 ) ) ;
V_114 = V_115 ;
break;
}
return V_114 ;
}
const char *
F_85 ( int V_112 )
{
const char * V_114 ;
static char V_115 [ 1024 + 1 ] ;
switch ( V_112 ) {
case V_117 :
V_114 = L_56 ;
break;
#ifdef F_81
case F_81 :
V_114 = L_57 ;
break;
#endif
default:
F_83 ( V_115 , sizeof( V_115 ) ,
L_58 ,
F_84 ( V_112 ) ) ;
V_114 = V_115 ;
break;
}
return V_114 ;
}
T_4
F_62 ( const char * V_120 )
{
T_1 V_121 ;
if ( ! V_120 ) {
return FALSE ;
}
#ifdef F_2
V_121 . V_122 = 1 ;
F_7 ( V_120 , & V_121 ) ;
if ( V_121 . V_122 == 0 ) {
return TRUE ;
} else {
return FALSE ;
}
#else
if ( F_7 ( V_120 , & V_121 ) != 0 && V_6 == V_85 ) {
return FALSE ;
} else {
return TRUE ;
}
#endif
}
T_4
F_86 ( const char * V_123 , const char * V_124 )
{
#ifdef F_2
char V_125 [ V_94 ] , V_126 [ V_94 ] ;
if( F_87 ( V_125 , V_123 , V_94 ) == NULL ) {
return FALSE ;
}
if( F_87 ( V_126 , V_124 , V_94 ) == NULL ) {
return FALSE ;
}
if( strcmp ( V_125 , V_126 ) == 0 ) {
return TRUE ;
} else {
return FALSE ;
}
#else
T_1 V_127 , V_128 ;
if ( F_7 ( V_123 , & V_127 ) == - 1 )
return FALSE ;
if ( F_7 ( V_124 , & V_128 ) == - 1 )
return FALSE ;
return ( V_127 . V_129 == V_128 . V_129 &&
V_127 . V_122 == V_128 . V_122 ) ;
#endif
}
T_4
F_63 ( const char * V_130 , const char * V_131 )
{
int V_132 , V_133 , V_112 ;
T_11 V_134 , V_135 ;
T_12 * V_136 = NULL ;
V_132 = F_88 ( V_130 , V_137 | V_138 , 0000 ) ;
if ( V_132 < 0 ) {
F_89 ( V_130 , V_6 , FALSE ) ;
goto V_139;
}
V_133 = F_88 ( V_131 , V_140 | V_141 | V_142 | V_138 , 0644 ) ;
if ( V_133 < 0 ) {
F_89 ( V_131 , V_6 , TRUE ) ;
F_90 ( V_132 ) ;
goto V_139;
}
#define F_91 65536
V_136 = ( T_12 * ) F_13 ( F_91 ) ;
while ( ( V_134 = F_92 ( V_132 , V_136 , F_91 ) ) > 0 ) {
V_135 = F_93 ( V_133 , V_136 , V_134 ) ;
if ( V_135 < V_134 ) {
if ( V_135 < 0 )
V_112 = V_6 ;
else
V_112 = V_143 ;
F_94 ( V_131 , V_112 ) ;
F_90 ( V_132 ) ;
F_90 ( V_133 ) ;
goto V_139;
}
}
if ( V_134 < 0 ) {
V_112 = V_6 ;
F_95 ( V_130 , V_112 ) ;
F_90 ( V_132 ) ;
F_90 ( V_133 ) ;
goto V_139;
}
F_90 ( V_132 ) ;
if ( F_90 ( V_133 ) < 0 ) {
F_94 ( V_131 , V_6 ) ;
goto V_139;
}
F_27 ( V_136 ) ;
V_136 = NULL ;
return TRUE ;
V_139:
F_27 ( V_136 ) ;
return FALSE ;
}
