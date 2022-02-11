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
V_36 = F_25 ( L_15 , F_20 () ) ;
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
#if F_12 ( V_40 ) || F_12 ( V_41 )
if ( ! V_36 ) F_26 () ;
return V_36 ;
#else
return NULL ;
#endif
}
static void F_29 ( void ) {
#ifdef F_2
V_42 = F_25 ( L_18 , F_21 () ,
V_37 ) ;
if ( F_6 ( V_42 ) != V_8 ) {
F_27 ( ( V_38 ) V_42 ) ;
V_42 = F_25 ( L_19 , F_21 () ) ;
V_32 = TRUE ;
}
#else
if ( V_32 ) {
V_42 = F_25 ( L_20 , F_20 () ) ;
} else {
if ( getenv ( L_21 ) && ! F_24 () ) {
V_42 = F_23 ( getenv ( L_21 ) ) ;
}
#ifdef V_10
else if ( V_34 != NULL ) {
V_42 = F_25 ( L_22 ,
V_34 ) ;
}
#endif
else {
V_42 = V_43 ;
}
}
#endif
}
const char *
F_30 ( void ) {
#if F_12 ( V_44 )
if ( ! V_42 )
F_29 () ;
return V_42 ;
#else
return NULL ;
#endif
}
T_4
F_31 ( void )
{
return V_32 ;
}
const char *
F_32 ( void )
{
#ifdef F_2
return F_21 () ;
#else
return L_23 ;
#endif
}
void
F_33 ( const T_5 * V_45 )
{
F_27 ( V_46 ) ;
if ( V_45 && strlen ( V_45 ) > 0 &&
strcmp ( V_45 , V_47 ) != 0 ) {
V_46 = F_23 ( V_45 ) ;
} else {
V_46 = NULL ;
}
}
const char *
F_34 ( void )
{
if ( V_46 ) {
return V_46 ;
} else {
return V_47 ;
}
}
T_4
F_35 ( void )
{
return ( ! V_46 || strcmp ( V_46 , V_47 ) == 0 ) ? TRUE : FALSE ;
}
T_4
F_36 ( void )
{
T_6 * V_48 ;
T_7 * V_49 ;
const T_5 * V_50 = F_37 () ;
T_5 * V_4 ;
T_4 V_51 = FALSE ;
if ( ( F_6 ( V_50 ) == V_8 ) &&
( ( V_48 = F_38 ( V_50 , 0 , NULL ) ) != NULL ) )
{
while ( ( V_49 = F_39 ( V_48 ) ) != NULL ) {
V_4 = F_25 ( L_24 , V_50 , V_52 ,
F_40 ( V_49 ) ) ;
if ( F_6 ( V_4 ) == V_8 ) {
V_51 = TRUE ;
F_27 ( V_4 ) ;
break;
}
F_27 ( V_4 ) ;
}
F_41 ( V_48 ) ;
}
return V_51 ;
}
void
F_42 ( T_4 V_53 )
{
if ( V_53 ) {
V_54 = F_43 ( V_55 , V_56 ) ;
}
V_57 = V_53 ;
}
static const char *
F_44 ( void )
{
#ifdef F_2
char * V_58 ;
char * V_59 ;
char * V_60 ;
#else
const char * V_61 ;
struct V_62 * V_63 ;
#endif
if ( V_64 != NULL )
return V_64 ;
#ifdef F_2
V_60 = F_22 ( L_25 ) ;
if ( V_60 != NULL ) {
V_64 = V_60 ;
return V_64 ;
}
V_60 = F_22 ( L_26 ) ;
if ( V_60 != NULL ) {
V_64 = V_60 ;
} else {
V_58 = F_22 ( L_27 ) ;
if ( V_58 != NULL ) {
V_64 = F_25 ( L_28 V_52 L_28 ,
V_58 , V_65 ) ;
} else {
V_59 = F_22 ( L_29 ) ;
if ( V_59 != NULL ) {
V_64 = F_25 (
L_28 V_52 L_30 V_52 L_28 ,
V_59 , V_65 ) ;
} else {
V_64 = F_25 ( L_31 V_52 L_28 , V_65 ) ;
}
}
}
#else
V_61 = getenv ( L_32 ) ;
if ( V_61 == NULL ) {
V_63 = F_45 ( F_46 () ) ;
if ( V_63 != NULL ) {
V_61 = V_63 -> V_66 ;
} else {
V_61 = L_33 ;
}
}
V_64 = F_25 ( L_28 V_52 L_28 , V_61 , V_65 ) ;
#endif
return V_64 ;
}
void
F_47 ( const char * V_67 )
{
F_27 ( V_64 ) ;
V_64 = F_23 ( V_67 ) ;
}
const char *
F_48 ( void )
{
static char * V_68 = NULL ;
F_27 ( V_68 ) ;
V_68 = F_25 ( L_24 , F_44 () ,
V_52 , V_69 ) ;
return V_68 ;
}
const char *
F_37 ( void )
{
static char * V_70 = NULL ;
if ( ! V_70 ) {
V_70 = F_25 ( L_24 , F_21 () ,
V_52 , V_69 ) ;
}
return V_70 ;
}
static const char *
F_49 ( const T_5 * V_45 )
{
static char * V_71 = NULL ;
F_27 ( V_71 ) ;
if ( V_45 && strlen ( V_45 ) > 0 &&
strcmp ( V_45 , V_47 ) != 0 ) {
V_71 = F_25 ( L_24 , F_48 () ,
V_52 , V_45 ) ;
} else {
V_71 = F_23 ( F_44 () ) ;
}
return V_71 ;
}
T_4
F_50 ( const T_5 * V_45 , T_4 V_72 )
{
if ( V_72 ) {
T_5 * V_1 = F_25 ( L_24 , F_37 () ,
V_52 , V_45 ) ;
if ( F_6 ( V_1 ) == V_8 ) {
F_27 ( V_1 ) ;
return TRUE ;
}
F_27 ( V_1 ) ;
} else {
if ( F_6 ( F_49 ( V_45 ) ) == V_8 ) {
return TRUE ;
}
}
return FALSE ;
}
static int
F_51 ( const char * V_73 , char * * V_74 )
{
T_6 * V_48 ;
T_7 * V_49 ;
T_5 * V_4 ;
int V_75 = 0 ;
if ( ( V_48 = F_38 ( V_73 , 0 , NULL ) ) != NULL ) {
while ( ( V_49 = F_39 ( V_48 ) ) != NULL ) {
V_4 = F_25 ( L_24 , V_73 , V_52 ,
F_40 ( V_49 ) ) ;
if ( F_6 ( V_4 ) != V_8 ) {
V_75 = F_52 ( V_4 ) ;
#if 0
} else {
ret = delete_directory (filename, pf_dir_path_return);
#endif
}
if ( V_75 != 0 ) {
* V_74 = V_4 ;
break;
}
F_27 ( V_4 ) ;
}
F_41 ( V_48 ) ;
}
if ( V_75 == 0 && ( V_75 = F_52 ( V_73 ) ) != 0 ) {
* V_74 = F_23 ( V_73 ) ;
}
return V_75 ;
}
int
F_53 ( const char * V_45 , char * * V_74 )
{
const char * V_76 = F_49 ( V_45 ) ;
int V_75 = 0 ;
if ( F_6 ( V_76 ) == V_8 ) {
V_75 = F_51 ( V_76 , V_74 ) ;
}
return V_75 ;
}
int
F_54 ( const char * V_77 , const char * V_78 ,
char * * V_79 , char * * V_80 )
{
char * V_81 = F_23 ( F_49 ( V_77 ) ) ;
char * V_82 = F_23 ( F_49 ( V_78 ) ) ;
int V_75 = 0 ;
V_75 = F_55 ( V_81 , V_82 ) ;
if ( V_75 != 0 ) {
* V_79 = F_23 ( V_81 ) ;
* V_80 = F_23 ( V_82 ) ;
}
F_27 ( V_81 ) ;
F_27 ( V_82 ) ;
return V_75 ;
}
int
F_56 ( const char * V_45 , char * * V_74 )
{
const char * V_83 ;
#ifdef F_2
char * V_84 , * V_85 ;
T_3 V_86 ;
#endif
T_1 V_87 ;
int V_75 ;
if ( V_45 ) {
if ( F_56 ( NULL , V_74 ) == - 1 ) {
return - 1 ;
}
V_83 = F_48 () ;
if ( F_7 ( V_83 , & V_87 ) != 0 && V_6 == V_88 ) {
V_75 = F_57 ( V_83 , 0755 ) ;
if ( V_75 == - 1 ) {
* V_74 = F_23 ( V_83 ) ;
return V_75 ;
}
}
}
V_83 = F_49 ( V_45 ) ;
if ( F_7 ( V_83 , & V_87 ) != 0 && V_6 == V_88 ) {
#ifdef F_2
V_84 = F_23 ( V_83 ) ;
V_85 = F_5 ( V_84 ) ;
V_86 = strlen ( V_85 ) ;
if ( V_86 > 0
&& V_85 [ V_86 - 1 ] != ':'
&& F_7 ( V_85 , & V_87 ) != 0 ) {
V_75 = F_57 ( V_85 , 0755 ) ;
if ( V_75 == - 1 ) {
* V_74 = V_85 ;
return - 1 ;
}
}
F_27 ( V_84 ) ;
V_75 = F_57 ( V_83 , 0755 ) ;
#else
V_75 = F_57 ( V_83 , 0755 ) ;
#endif
} else {
V_75 = 0 ;
}
if ( V_75 == - 1 )
* V_74 = F_23 ( V_83 ) ;
return V_75 ;
}
int
F_58 ( char * * V_74 )
{
return F_56 ( V_46 , V_74 ) ;
}
int
F_59 ( const char * V_78 , const char * V_77 , T_4 V_89 ,
char * * V_90 , char * * V_80 , char * * V_79 )
{
T_5 * V_81 ;
T_5 * V_82 = F_23 ( F_49 ( V_78 ) ) ;
T_5 * V_4 , * V_91 , * V_92 ;
T_8 * V_93 , * V_49 ;
if ( V_89 ) {
if ( strcmp ( V_77 , V_47 ) == 0 ) {
V_81 = F_23 ( F_37 () ) ;
} else {
V_81 = F_25 ( L_24 , F_37 () , V_52 , V_77 ) ;
}
} else {
V_81 = F_23 ( F_49 ( V_77 ) ) ;
}
V_93 = F_60 ( V_54 ) ;
V_49 = F_61 ( V_93 ) ;
while ( V_49 ) {
V_4 = ( T_5 * ) V_49 -> V_94 ;
V_91 = F_25 ( L_24 , V_81 , V_52 , V_4 ) ;
V_92 = F_25 ( L_24 , V_82 , V_52 , V_4 ) ;
if ( F_62 ( V_91 ) && ! F_63 ( V_91 , V_92 ) ) {
* V_90 = F_23 ( V_4 ) ;
* V_80 = V_82 ;
* V_79 = V_81 ;
F_27 ( V_91 ) ;
F_27 ( V_92 ) ;
return - 1 ;
}
F_27 ( V_91 ) ;
F_27 ( V_92 ) ;
V_49 = F_64 ( V_49 ) ;
}
F_65 ( V_93 ) ;
F_27 ( V_81 ) ;
F_27 ( V_82 ) ;
return 0 ;
}
extern const char *
F_66 ( void )
{
#ifdef F_2
char * V_95 ;
T_9 V_96 [ V_97 ] ;
if ( V_98 != NULL )
return V_98 ;
V_95 = F_22 ( L_34 ) ;
if ( V_95 != NULL ) {
V_98 = F_25 ( L_35 , V_95 , V_99 ) ;
return V_98 ;
} else {
if ( F_67 ( NULL , V_96 , V_100 , FALSE ) ) {
V_98 = F_68 ( V_96 , - 1 , NULL , NULL , NULL ) ;
return V_98 ;
} else {
return L_36 ;
}
}
#else
return L_36 ;
#endif
}
void
F_69 ( const char * V_67 )
{
F_27 ( V_98 ) ;
V_98 = F_23 ( V_67 ) ;
}
static const char *
F_70 ( void )
{
static const char * V_101 = NULL ;
char * V_102 , * V_103 ;
char * V_104 ;
char * V_105 ;
if ( V_101 )
return V_101 ;
V_102 = F_22 ( L_37 ) ;
if ( V_102 != NULL ) {
V_103 = F_22 ( L_38 ) ;
if ( V_103 != NULL ) {
V_104 = F_25 ( L_35 , V_102 , V_103 ) ;
V_105 = F_1 ( V_104 ) ;
if ( V_105 != NULL && * ( V_105 + 1 ) == '\0' ) {
* V_105 = '\0' ;
}
V_101 = V_104 ;
} else
V_101 = V_102 ;
} else {
V_101 = L_31 ;
}
return V_101 ;
}
char *
F_71 ( const char * V_4 , T_4 V_106 )
{
char * V_1 ;
if ( V_57 && V_106 && ! F_72 ( V_54 , V_4 ) ) {
F_73 ( V_54 , F_23 ( V_4 ) , F_23 ( V_4 ) ) ;
}
if ( V_106 ) {
V_1 = F_25 ( L_28 V_52 L_28 ,
F_49 ( V_46 ) , V_4 ) ;
} else {
V_1 = F_25 ( L_28 V_52 L_28 ,
F_49 ( NULL ) , V_4 ) ;
}
return V_1 ;
}
char *
F_74 ( const char * V_4 )
{
if ( V_32 &&
( ! strcmp ( V_4 , L_39 ) ||
! strcmp ( V_4 , L_40 ) ) ) {
return F_25 ( L_28 V_52 L_28 , F_20 () , V_4 ) ;
} else {
return F_25 ( L_28 V_52 L_28 , F_21 () , V_4 ) ;
}
}
char *
F_75 ( void )
{
return F_71 ( V_107 , FALSE ) ;
}
const char *
F_76 ( int V_108 , T_4 V_109 )
{
const char * V_110 ;
static char V_111 [ 1024 + 1 ] ;
switch ( V_108 ) {
case V_88 :
if ( V_109 )
V_110 = L_41 ;
else
V_110 = L_42 ;
break;
case V_112 :
if ( V_109 )
V_110 = L_43 ;
else
V_110 = L_44 ;
break;
case V_8 :
V_110 = L_45 ;
break;
case V_113 :
V_110 = L_46 ;
break;
#ifdef F_77
case F_77 :
V_110 = L_47 ;
break;
#endif
case V_114 :
V_110 = L_48 ;
break;
case V_23 :
#if V_115 == 4
#define F_78 "it can't be handled by a 32-bit application"
#else
#if F_12 ( F_2 )
#define F_78 "the pagefile is too small"
#elif F_12 ( V_10 )
#define F_78 "your system ran out of swap file space"
#else
#define F_78 "your system is out of swap space"
#endif
#endif
if ( V_109 )
V_110 = L_49 F_78 L_50 ;
else
V_110 = L_51 F_78 L_50 ;
break;
default:
F_79 ( V_111 , sizeof( V_111 ) ,
L_52 ,
V_109 ? L_53 : L_54 ,
F_80 ( V_108 ) ) ;
V_110 = V_111 ;
break;
}
return V_110 ;
}
const char *
F_81 ( int V_108 )
{
const char * V_110 ;
static char V_111 [ 1024 + 1 ] ;
switch ( V_108 ) {
case V_113 :
V_110 = L_55 ;
break;
#ifdef F_77
case F_77 :
V_110 = L_56 ;
break;
#endif
default:
F_79 ( V_111 , sizeof( V_111 ) ,
L_57 ,
F_80 ( V_108 ) ) ;
V_110 = V_111 ;
break;
}
return V_110 ;
}
T_4
F_62 ( const char * V_116 )
{
T_1 V_117 ;
if ( ! V_116 ) {
return FALSE ;
}
#ifdef F_2
V_117 . V_118 = 1 ;
F_7 ( V_116 , & V_117 ) ;
if ( V_117 . V_118 == 0 ) {
return TRUE ;
} else {
return FALSE ;
}
#else
if ( F_7 ( V_116 , & V_117 ) != 0 && V_6 == V_88 ) {
return FALSE ;
} else {
return TRUE ;
}
#endif
}
T_4
F_82 ( const char * V_119 , const char * V_120 )
{
#ifdef F_2
char V_121 [ V_97 ] , V_122 [ V_97 ] ;
if( F_83 ( V_121 , V_119 , V_97 ) == NULL ) {
return FALSE ;
}
if( F_83 ( V_122 , V_120 , V_97 ) == NULL ) {
return FALSE ;
}
if( strcmp ( V_121 , V_122 ) == 0 ) {
return TRUE ;
} else {
return FALSE ;
}
#else
T_1 V_123 , V_124 ;
if ( F_7 ( V_119 , & V_123 ) == - 1 )
return FALSE ;
if ( F_7 ( V_120 , & V_124 ) == - 1 )
return FALSE ;
return ( V_123 . V_125 == V_124 . V_125 &&
V_123 . V_118 == V_124 . V_118 ) ;
#endif
}
T_4
F_63 ( const char * V_126 , const char * V_127 )
{
int V_128 , V_129 , V_108 ;
T_10 V_130 , V_131 ;
T_11 * V_132 = NULL ;
V_128 = F_84 ( V_126 , V_133 | V_134 , 0000 ) ;
if ( V_128 < 0 ) {
F_85 ( V_126 , V_6 , FALSE ) ;
goto V_135;
}
V_129 = F_84 ( V_127 , V_136 | V_137 | V_138 | V_134 , 0644 ) ;
if ( V_129 < 0 ) {
F_85 ( V_127 , V_6 , TRUE ) ;
F_86 ( V_128 ) ;
goto V_135;
}
#define F_87 65536
V_132 = ( T_11 * ) F_13 ( F_87 ) ;
while ( ( V_130 = F_88 ( V_128 , V_132 , F_87 ) ) > 0 ) {
V_131 = F_89 ( V_129 , V_132 , V_130 ) ;
if ( V_131 < V_130 ) {
if ( V_131 < 0 )
V_108 = V_6 ;
else
V_108 = V_139 ;
F_90 ( V_127 , V_108 ) ;
F_86 ( V_128 ) ;
F_86 ( V_129 ) ;
goto V_135;
}
}
if ( V_130 < 0 ) {
V_108 = V_6 ;
F_91 ( V_126 , V_108 ) ;
F_86 ( V_128 ) ;
F_86 ( V_129 ) ;
goto V_135;
}
F_86 ( V_128 ) ;
if ( F_86 ( V_129 ) < 0 ) {
F_90 ( V_127 , V_6 ) ;
goto V_135;
}
F_27 ( V_132 ) ;
V_132 = NULL ;
return TRUE ;
V_135:
F_27 ( V_132 ) ;
return FALSE ;
}
