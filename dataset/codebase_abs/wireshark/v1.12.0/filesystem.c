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
static const char *
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
V_31 = F_23 ( V_33 ) ;
return V_31 ;
} else {
if ( getenv ( L_11 ) && ! F_24 () ) {
V_31 = F_23 ( getenv ( L_11 ) ) ;
}
#ifdef V_10
else if ( V_34 != NULL ) {
V_31 = F_25 ( L_12 ,
V_34 ) ;
}
#endif
else {
V_31 = V_35 ;
}
}
#endif
return V_31 ;
}
static void
F_26 ( void )
{
#ifdef F_2
V_36 = F_25 ( L_13 , F_21 () ,
V_37 ) ;
if ( F_6 ( V_36 ) != V_8 ) {
F_27 ( ( V_38 ) V_36 ) ;
V_36 = F_25 ( L_14 , F_21 () ) ;
V_32 = TRUE ;
}
#else
if ( V_32 ) {
V_36 = F_25 ( L_15 , F_21 () ) ;
} else {
if ( getenv ( L_16 ) && ! F_24 () ) {
V_36 = F_23 ( getenv ( L_16 ) ) ;
}
#ifdef V_10
else if ( V_34 != NULL ) {
V_36 = F_25 ( L_17 ,
V_34 ) ;
}
#endif
else {
V_36 = V_39 ;
}
}
#endif
}
const char *
F_28 ( void )
{
#ifdef F_29
if ( ! V_36 ) F_26 () ;
return V_36 ;
#else
return NULL ;
#endif
}
static void
F_30 ( void )
{
#ifdef F_2
V_40 = F_25 ( L_18 , F_21 () ,
V_37 ) ;
if ( F_6 ( V_40 ) != V_8 ) {
F_27 ( ( V_38 ) V_40 ) ;
V_40 = F_25 ( L_19 , F_21 () ) ;
V_32 = TRUE ;
}
#else
if ( V_32 ) {
V_40 = F_25 ( L_20 , F_20 () ) ;
} else {
if ( getenv ( L_21 ) && ! F_24 () ) {
V_40 = F_23 ( getenv ( L_21 ) ) ;
}
#ifdef V_10
else if ( V_34 != NULL ) {
V_40 = F_25 ( L_22 ,
V_34 ) ;
}
#endif
else {
V_40 = V_41 ;
}
}
#endif
}
const char *
F_31 ( void )
{
#if F_12 ( V_42 ) || F_12 ( V_43 )
if ( ! V_40 ) F_30 () ;
return V_40 ;
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
return L_23 ;
#endif
}
void
F_34 ( const T_5 * V_44 )
{
F_27 ( V_45 ) ;
if ( V_44 && strlen ( V_44 ) > 0 &&
strcmp ( V_44 , V_46 ) != 0 ) {
V_45 = F_23 ( V_44 ) ;
} else {
V_45 = NULL ;
}
}
const char *
F_35 ( void )
{
if ( V_45 ) {
return V_45 ;
} else {
return V_46 ;
}
}
T_4
F_36 ( void )
{
return ( ! V_45 || strcmp ( V_45 , V_46 ) == 0 ) ? TRUE : FALSE ;
}
T_4
F_37 ( void )
{
T_6 * V_47 ;
T_7 * V_48 ;
const T_5 * V_49 = F_38 () ;
T_5 * V_4 ;
T_4 V_50 = FALSE ;
if ( ( F_6 ( V_49 ) == V_8 ) &&
( ( V_47 = F_39 ( V_49 , 0 , NULL ) ) != NULL ) )
{
while ( ( V_48 = F_40 ( V_47 ) ) != NULL ) {
V_4 = F_25 ( L_24 , V_49 , V_51 ,
F_41 ( V_48 ) ) ;
if ( F_6 ( V_4 ) == V_8 ) {
V_50 = TRUE ;
F_27 ( V_4 ) ;
break;
}
F_27 ( V_4 ) ;
}
F_42 ( V_47 ) ;
}
return V_50 ;
}
void
F_43 ( T_4 V_52 )
{
if ( V_52 ) {
V_53 = F_44 ( V_54 , V_55 ) ;
}
V_56 = V_52 ;
}
static const char *
F_45 ( void )
{
#ifdef F_2
char * V_57 ;
char * V_58 ;
char * V_59 ;
#else
const char * V_60 ;
struct V_61 * V_62 ;
#endif
if ( V_63 != NULL )
return V_63 ;
#ifdef F_2
V_59 = F_22 ( L_25 ) ;
if ( V_59 != NULL ) {
V_63 = V_59 ;
return V_63 ;
}
V_59 = F_22 ( L_26 ) ;
if ( V_59 != NULL ) {
V_63 = V_59 ;
} else {
V_57 = F_22 ( L_27 ) ;
if ( V_57 != NULL ) {
V_63 = F_25 ( L_28 V_51 L_28 ,
V_57 , V_64 ) ;
} else {
V_58 = F_22 ( L_29 ) ;
if ( V_58 != NULL ) {
V_63 = F_25 (
L_28 V_51 L_30 V_51 L_28 ,
V_58 , V_64 ) ;
} else {
V_63 = F_25 ( L_31 V_51 L_28 , V_64 ) ;
}
}
}
#else
V_60 = getenv ( L_32 ) ;
if ( V_60 == NULL ) {
V_62 = F_46 ( F_47 () ) ;
if ( V_62 != NULL ) {
V_60 = V_62 -> V_65 ;
} else {
V_60 = L_33 ;
}
}
V_63 = F_25 ( L_28 V_51 L_28 , V_60 , V_64 ) ;
#endif
return V_63 ;
}
void
F_48 ( const char * V_66 )
{
F_27 ( V_63 ) ;
V_63 = F_23 ( V_66 ) ;
}
const char *
F_49 ( void )
{
static char * V_67 = NULL ;
F_27 ( V_67 ) ;
V_67 = F_25 ( L_24 , F_45 () ,
V_51 , V_68 ) ;
return V_67 ;
}
const char *
F_38 ( void )
{
static char * V_69 = NULL ;
if ( ! V_69 ) {
V_69 = F_25 ( L_24 , F_21 () ,
V_51 , V_68 ) ;
}
return V_69 ;
}
static const char *
F_50 ( const T_5 * V_44 )
{
static char * V_70 = NULL ;
F_27 ( V_70 ) ;
if ( V_44 && strlen ( V_44 ) > 0 &&
strcmp ( V_44 , V_46 ) != 0 ) {
V_70 = F_25 ( L_24 , F_49 () ,
V_51 , V_44 ) ;
} else {
V_70 = F_23 ( F_45 () ) ;
}
return V_70 ;
}
T_4
F_51 ( const T_5 * V_44 , T_4 V_71 )
{
if ( V_71 ) {
T_5 * V_1 = F_25 ( L_24 , F_38 () ,
V_51 , V_44 ) ;
if ( F_6 ( V_1 ) == V_8 ) {
F_27 ( V_1 ) ;
return TRUE ;
}
F_27 ( V_1 ) ;
} else {
if ( F_6 ( F_50 ( V_44 ) ) == V_8 ) {
return TRUE ;
}
}
return FALSE ;
}
static int
F_52 ( const char * V_72 , char * * V_73 )
{
T_6 * V_47 ;
T_7 * V_48 ;
T_5 * V_4 ;
int V_74 = 0 ;
if ( ( V_47 = F_39 ( V_72 , 0 , NULL ) ) != NULL ) {
while ( ( V_48 = F_40 ( V_47 ) ) != NULL ) {
V_4 = F_25 ( L_24 , V_72 , V_51 ,
F_41 ( V_48 ) ) ;
if ( F_6 ( V_4 ) != V_8 ) {
V_74 = F_53 ( V_4 ) ;
#if 0
} else {
ret = delete_directory (filename, pf_dir_path_return);
#endif
}
if ( V_74 != 0 ) {
* V_73 = V_4 ;
break;
}
F_27 ( V_4 ) ;
}
F_42 ( V_47 ) ;
}
if ( V_74 == 0 && ( V_74 = F_53 ( V_72 ) ) != 0 ) {
* V_73 = F_23 ( V_72 ) ;
}
return V_74 ;
}
int
F_54 ( const char * V_44 , char * * V_73 )
{
const char * V_75 = F_50 ( V_44 ) ;
int V_74 = 0 ;
if ( F_6 ( V_75 ) == V_8 ) {
V_74 = F_52 ( V_75 , V_73 ) ;
}
return V_74 ;
}
int
F_55 ( const char * V_76 , const char * V_77 ,
char * * V_78 , char * * V_79 )
{
char * V_80 = F_23 ( F_50 ( V_76 ) ) ;
char * V_81 = F_23 ( F_50 ( V_77 ) ) ;
int V_74 = 0 ;
V_74 = F_56 ( V_80 , V_81 ) ;
if ( V_74 != 0 ) {
* V_78 = F_23 ( V_80 ) ;
* V_79 = F_23 ( V_81 ) ;
}
F_27 ( V_80 ) ;
F_27 ( V_81 ) ;
return V_74 ;
}
int
F_57 ( const char * V_44 , char * * V_73 )
{
const char * V_82 ;
#ifdef F_2
char * V_83 , * V_84 ;
T_3 V_85 ;
#endif
T_1 V_86 ;
int V_74 ;
if ( V_44 ) {
if ( F_57 ( NULL , V_73 ) == - 1 ) {
return - 1 ;
}
V_82 = F_49 () ;
if ( F_7 ( V_82 , & V_86 ) != 0 && V_6 == V_87 ) {
V_74 = F_58 ( V_82 , 0755 ) ;
if ( V_74 == - 1 ) {
* V_73 = F_23 ( V_82 ) ;
return V_74 ;
}
}
}
V_82 = F_50 ( V_44 ) ;
if ( F_7 ( V_82 , & V_86 ) != 0 && V_6 == V_87 ) {
#ifdef F_2
V_83 = F_23 ( V_82 ) ;
V_84 = F_5 ( V_83 ) ;
V_85 = strlen ( V_84 ) ;
if ( V_85 > 0
&& V_84 [ V_85 - 1 ] != ':'
&& F_7 ( V_84 , & V_86 ) != 0 ) {
V_74 = F_58 ( V_84 , 0755 ) ;
if ( V_74 == - 1 ) {
* V_73 = V_84 ;
return - 1 ;
}
}
F_27 ( V_83 ) ;
V_74 = F_58 ( V_82 , 0755 ) ;
#else
V_74 = F_58 ( V_82 , 0755 ) ;
#endif
} else {
V_74 = 0 ;
}
if ( V_74 == - 1 )
* V_73 = F_23 ( V_82 ) ;
return V_74 ;
}
int
F_59 ( char * * V_73 )
{
return F_57 ( V_45 , V_73 ) ;
}
int
F_60 ( const char * V_77 , const char * V_76 , T_4 V_88 ,
char * * V_89 , char * * V_79 , char * * V_78 )
{
T_5 * V_80 ;
T_5 * V_81 = F_23 ( F_50 ( V_77 ) ) ;
T_5 * V_4 , * V_90 , * V_91 ;
T_8 * V_92 , * V_48 ;
if ( V_88 ) {
if ( strcmp ( V_76 , V_46 ) == 0 ) {
V_80 = F_23 ( F_38 () ) ;
} else {
V_80 = F_25 ( L_24 , F_38 () , V_51 , V_76 ) ;
}
} else {
V_80 = F_23 ( F_50 ( V_76 ) ) ;
}
V_92 = F_61 ( V_53 ) ;
V_48 = F_62 ( V_92 ) ;
while ( V_48 ) {
V_4 = ( T_5 * ) V_48 -> V_93 ;
V_90 = F_25 ( L_24 , V_80 , V_51 , V_4 ) ;
V_91 = F_25 ( L_24 , V_81 , V_51 , V_4 ) ;
if ( F_63 ( V_90 ) && ! F_64 ( V_90 , V_91 ) ) {
* V_89 = F_23 ( V_4 ) ;
* V_79 = V_81 ;
* V_78 = V_80 ;
F_27 ( V_90 ) ;
F_27 ( V_91 ) ;
return - 1 ;
}
F_27 ( V_90 ) ;
F_27 ( V_91 ) ;
V_48 = F_65 ( V_48 ) ;
}
F_66 ( V_92 ) ;
F_27 ( V_80 ) ;
F_27 ( V_81 ) ;
return 0 ;
}
extern const char *
F_67 ( void )
{
#ifdef F_2
char * V_94 ;
T_9 V_95 [ V_96 ] ;
if ( V_97 != NULL )
return V_97 ;
V_94 = F_22 ( L_34 ) ;
if ( V_94 != NULL ) {
V_97 = F_25 ( L_35 , V_94 , V_98 ) ;
return V_97 ;
} else {
if ( F_68 ( NULL , V_95 , V_99 , FALSE ) ) {
V_97 = F_69 ( V_95 , - 1 , NULL , NULL , NULL ) ;
return V_97 ;
} else {
return L_36 ;
}
}
#else
return L_36 ;
#endif
}
void
F_70 ( const char * V_66 )
{
F_27 ( V_97 ) ;
V_97 = F_23 ( V_66 ) ;
}
static const char *
F_71 ( void )
{
static const char * V_100 = NULL ;
char * V_101 , * V_102 ;
char * V_103 ;
char * V_104 ;
if ( V_100 )
return V_100 ;
V_101 = F_22 ( L_37 ) ;
if ( V_101 != NULL ) {
V_102 = F_22 ( L_38 ) ;
if ( V_102 != NULL ) {
V_103 = F_25 ( L_35 , V_101 , V_102 ) ;
V_104 = F_1 ( V_103 ) ;
if ( V_104 != NULL && * ( V_104 + 1 ) == '\0' ) {
* V_104 = '\0' ;
}
V_100 = V_103 ;
} else
V_100 = V_101 ;
} else {
V_100 = L_31 ;
}
return V_100 ;
}
char *
F_72 ( const char * V_4 , T_4 V_105 )
{
char * V_1 ;
if ( V_56 && V_105 && ! F_73 ( V_53 , V_4 ) ) {
F_74 ( V_53 , F_23 ( V_4 ) , F_23 ( V_4 ) ) ;
}
if ( V_105 ) {
V_1 = F_25 ( L_28 V_51 L_28 ,
F_50 ( V_45 ) , V_4 ) ;
} else {
V_1 = F_25 ( L_28 V_51 L_28 ,
F_50 ( NULL ) , V_4 ) ;
}
return V_1 ;
}
char *
F_75 ( const char * V_4 )
{
if ( V_32 && ! strcmp ( V_4 , L_39 ) ) {
return F_25 ( L_28 V_51 L_28 , F_20 () , V_4 ) ;
} else {
return F_25 ( L_28 V_51 L_28 , F_21 () , V_4 ) ;
}
}
char *
F_76 ( void )
{
return F_72 ( V_106 , FALSE ) ;
}
const char *
F_77 ( int V_107 , T_4 V_108 )
{
const char * V_109 ;
static char V_110 [ 1024 + 1 ] ;
switch ( V_107 ) {
case V_87 :
if ( V_108 )
V_109 = L_40 ;
else
V_109 = L_41 ;
break;
case V_111 :
if ( V_108 )
V_109 = L_42 ;
else
V_109 = L_43 ;
break;
case V_8 :
V_109 = L_44 ;
break;
case V_112 :
V_109 = L_45 ;
break;
#ifdef F_78
case F_78 :
V_109 = L_46 ;
break;
#endif
case V_113 :
V_109 = L_47 ;
break;
case V_23 :
#if V_114 == 4
#define F_79 "it can't be handled by a 32-bit application"
#else
#if F_12 ( F_2 )
#define F_79 "the pagefile is too small"
#elif F_12 ( V_10 )
#define F_79 "your system ran out of swap file space"
#else
#define F_79 "your system is out of swap space"
#endif
#endif
if ( V_108 )
V_109 = L_48 F_79 L_49 ;
else
V_109 = L_50 F_79 L_49 ;
break;
default:
F_80 ( V_110 , sizeof( V_110 ) ,
L_51 ,
V_108 ? L_52 : L_53 ,
F_81 ( V_107 ) ) ;
V_109 = V_110 ;
break;
}
return V_109 ;
}
const char *
F_82 ( int V_107 )
{
const char * V_109 ;
static char V_110 [ 1024 + 1 ] ;
switch ( V_107 ) {
case V_112 :
V_109 = L_54 ;
break;
#ifdef F_78
case F_78 :
V_109 = L_55 ;
break;
#endif
default:
F_80 ( V_110 , sizeof( V_110 ) ,
L_56 ,
F_81 ( V_107 ) ) ;
V_109 = V_110 ;
break;
}
return V_109 ;
}
T_4
F_63 ( const char * V_115 )
{
T_1 V_116 ;
if ( ! V_115 ) {
return FALSE ;
}
#ifdef F_2
V_116 . V_117 = 1 ;
F_7 ( V_115 , & V_116 ) ;
if ( V_116 . V_117 == 0 ) {
return TRUE ;
} else {
return FALSE ;
}
#else
if ( F_7 ( V_115 , & V_116 ) != 0 && V_6 == V_87 ) {
return FALSE ;
} else {
return TRUE ;
}
#endif
}
T_4
F_83 ( const char * V_118 , const char * V_119 )
{
#ifdef F_2
char V_120 [ V_96 ] , V_121 [ V_96 ] ;
if( F_84 ( V_120 , V_118 , V_96 ) == NULL ) {
return FALSE ;
}
if( F_84 ( V_121 , V_119 , V_96 ) == NULL ) {
return FALSE ;
}
if( strcmp ( V_120 , V_121 ) == 0 ) {
return TRUE ;
} else {
return FALSE ;
}
#else
T_1 V_122 , V_123 ;
if ( F_7 ( V_118 , & V_122 ) == - 1 )
return FALSE ;
if ( F_7 ( V_119 , & V_123 ) == - 1 )
return FALSE ;
return ( V_122 . V_124 == V_123 . V_124 &&
V_122 . V_117 == V_123 . V_117 ) ;
#endif
}
T_4
F_64 ( const char * V_125 , const char * V_126 )
{
int V_127 , V_128 , V_107 ;
T_10 V_129 , V_130 ;
T_11 * V_131 = NULL ;
V_127 = F_85 ( V_125 , V_132 | V_133 , 0000 ) ;
if ( V_127 < 0 ) {
F_86 ( V_125 , V_6 , FALSE ) ;
goto V_134;
}
V_128 = F_85 ( V_126 , V_135 | V_136 | V_137 | V_133 , 0644 ) ;
if ( V_128 < 0 ) {
F_86 ( V_126 , V_6 , TRUE ) ;
F_87 ( V_127 ) ;
goto V_134;
}
#define F_88 65536
V_131 = ( T_11 * ) F_13 ( F_88 ) ;
while ( ( V_129 = F_89 ( V_127 , V_131 , F_88 ) ) > 0 ) {
V_130 = F_90 ( V_128 , V_131 , V_129 ) ;
if ( V_130 < V_129 ) {
if ( V_130 < 0 )
V_107 = V_6 ;
else
V_107 = V_138 ;
F_91 ( V_126 , V_107 ) ;
F_87 ( V_127 ) ;
F_87 ( V_128 ) ;
goto V_134;
}
}
if ( V_129 < 0 ) {
V_107 = V_6 ;
F_92 ( V_125 , V_107 ) ;
F_87 ( V_127 ) ;
F_87 ( V_128 ) ;
goto V_134;
}
F_87 ( V_127 ) ;
if ( F_87 ( V_128 ) < 0 ) {
F_91 ( V_126 , V_6 ) ;
goto V_134;
}
F_27 ( V_131 ) ;
V_131 = NULL ;
return TRUE ;
V_134:
F_27 ( V_131 ) ;
return FALSE ;
}
