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
static char V_11 [ V_13 + 1 ] ;
T_3 V_17 ;
if ( F_16 ( & V_16 ) == - 1 )
return NULL ;
if ( strncmp ( V_16 . V_18 , L_1 , 2 ) == 0 )
return NULL ;
if ( strcmp ( V_16 . V_18 , L_2 ) == 0 ||
strncmp ( V_16 . V_18 , L_3 , 4 ) == 0 ||
strcmp ( V_16 . V_18 , L_4 ) == 0 ||
strncmp ( V_16 . V_18 , L_5 , 4 ) == 0 )
return NULL ;
if ( ( V_17 = F_17 ( L_6 , V_11 , V_13 ) ) == - 1 )
return NULL ;
V_11 [ V_17 ] = '\0' ;
return V_11 ;
#elif F_12 ( V_19 ) && F_12 ( V_20 )
int V_21 [ 4 ] ;
char * V_11 ;
T_4 V_12 ;
V_21 [ 0 ] = V_22 ;
V_21 [ 1 ] = V_23 ;
V_21 [ 2 ] = V_20 ;
V_21 [ 3 ] = - 1 ;
V_12 = V_13 ;
V_11 = ( char * ) F_13 ( V_12 ) ;
if ( F_18 ( V_21 , 4 , V_11 , & V_12 , NULL , 0 ) == - 1 ) {
if ( V_6 != V_24 )
return NULL ;
V_11 = ( char * ) F_15 ( V_11 , V_12 ) ;
if ( F_18 ( V_21 , 4 , V_11 , & V_12 , NULL , 0 ) == - 1 )
return NULL ;
}
return V_11 ;
#elif F_12 ( V_25 )
static char V_11 [ V_13 + 1 ] ;
T_3 V_17 ;
if ( ( V_17 = F_17 ( L_7 , V_11 , V_13 ) ) == - 1 )
return NULL ;
V_11 [ V_17 ] = '\0' ;
return V_11 ;
#elif F_12 ( V_26 )
static char V_11 [ V_13 + 1 ] ;
T_3 V_17 ;
if ( ( V_17 = F_17 ( L_8 , V_11 , V_13 ) ) == - 1 )
return NULL ;
V_11 [ V_17 ] = '\0' ;
return V_11 ;
#elif ( F_12 ( V_27 ) || F_12 ( V_28 ) ) && F_12 ( V_29 )
return F_19 () ;
#else
return NULL ;
#endif
}
const char *
F_20 ( void )
{
return V_30 ;
}
const char *
F_21 ( void )
{
static const char * V_31 = NULL ;
if ( V_31 != NULL )
return V_31 ;
#ifdef F_2
if ( V_30 != NULL ) {
V_31 = V_30 ;
} else {
V_31 = L_9 ;
}
#else
if ( V_32 ) {
V_31 = F_22 ( V_33 ) ;
return V_31 ;
} else {
if ( F_23 ( L_10 ) && ! F_24 () ) {
V_31 = F_22 ( F_23 ( L_10 ) ) ;
}
#ifdef V_10
else if ( V_34 != NULL ) {
V_31 = F_25 ( L_11 ,
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
V_36 = F_25 ( L_12 , F_21 () ,
V_37 ) ;
if ( F_6 ( V_36 ) != V_8 ) {
F_27 ( ( V_38 ) V_36 ) ;
V_36 = F_25 ( L_13 , F_21 () ) ;
V_32 = TRUE ;
}
#else
if ( V_32 ) {
V_36 = F_25 ( L_14 , F_20 () ) ;
} else {
if ( F_23 ( L_15 ) && ! F_24 () ) {
V_36 = F_22 ( F_23 ( L_15 ) ) ;
}
#ifdef V_10
else if ( V_34 != NULL ) {
V_36 = F_25 ( L_16 ,
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
const char * V_42 ;
V_42 = F_23 ( L_17 ) ;
if ( V_42 ) {
V_43 = F_22 ( V_42 ) ;
} else {
V_43 = F_25 ( L_18 , F_21 () ) ;
}
#else
if ( V_32 ) {
V_43 = F_25 ( L_19 , F_20 () ) ;
} else {
if ( F_23 ( L_17 ) && ! F_24 () ) {
V_43 = F_22 ( F_23 ( L_17 ) ) ;
}
#ifdef V_10
else if ( V_34 != NULL ) {
V_43 = F_25 ( L_20 ,
V_34 ) ;
}
#endif
else {
V_43 = V_44 ;
}
}
#endif
}
const char *
F_30 ( void ) {
#if F_12 ( V_45 )
if ( ! V_43 )
F_29 () ;
return V_43 ;
#else
return NULL ;
#endif
}
T_5
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
return L_21 ;
#endif
}
void
F_33 ( const T_6 * V_46 )
{
F_27 ( V_47 ) ;
if ( V_46 && strlen ( V_46 ) > 0 &&
strcmp ( V_46 , V_48 ) != 0 ) {
V_47 = F_22 ( V_46 ) ;
} else {
V_47 = NULL ;
}
}
const char *
F_34 ( void )
{
if ( V_47 ) {
return V_47 ;
} else {
return V_48 ;
}
}
T_5
F_35 ( void )
{
return ( ! V_47 || strcmp ( V_47 , V_48 ) == 0 ) ? TRUE : FALSE ;
}
T_5
F_36 ( void )
{
T_7 * V_49 ;
T_8 * V_50 ;
const T_6 * V_51 = F_37 () ;
T_6 * V_4 ;
T_5 V_52 = FALSE ;
if ( ( F_6 ( V_51 ) == V_8 ) &&
( ( V_49 = F_38 ( V_51 , 0 , NULL ) ) != NULL ) )
{
while ( ( V_50 = F_39 ( V_49 ) ) != NULL ) {
V_4 = F_25 ( L_22 , V_51 , V_53 ,
F_40 ( V_50 ) ) ;
if ( F_6 ( V_4 ) == V_8 ) {
V_52 = TRUE ;
F_27 ( V_4 ) ;
break;
}
F_27 ( V_4 ) ;
}
F_41 ( V_49 ) ;
}
return V_52 ;
}
void
F_42 ( T_5 V_54 )
{
if ( V_54 ) {
V_55 = F_43 ( V_56 , V_57 ) ;
}
V_58 = V_54 ;
}
static const char *
F_44 ( void )
{
#ifdef F_2
const char * V_59 ;
#else
char * V_60 , * V_1 ;
struct V_61 * V_62 ;
const char * V_63 ;
#endif
if ( V_64 != NULL )
return V_64 ;
#ifdef F_2
V_59 = F_23 ( L_23 ) ;
if ( V_59 != NULL ) {
V_64 = F_22 ( V_59 ) ;
return V_64 ;
}
V_59 = F_23 ( L_24 ) ;
if ( V_59 != NULL ) {
V_64 = F_45 ( V_59 , L_25 , NULL ) ;
return V_64 ;
}
V_59 = F_23 ( L_26 ) ;
if ( V_59 != NULL ) {
V_64 = F_45 ( V_59 , L_27 , L_25 , NULL ) ;
return V_64 ;
}
V_64 = F_45 ( L_28 , L_25 , NULL ) ;
return V_64 ;
#else
V_60 = F_45 ( F_46 () , L_29 , NULL ) ;
if ( F_47 ( V_60 , V_65 ) ) {
V_64 = V_60 ;
return V_64 ;
}
V_63 = F_23 ( L_30 ) ;
if ( V_63 == NULL ) {
V_62 = F_48 ( F_49 () ) ;
if ( V_62 != NULL ) {
V_63 = V_62 -> V_66 ;
} else {
V_63 = L_31 ;
}
}
V_1 = F_45 ( V_63 , L_32 , NULL ) ;
if ( F_47 ( V_1 , V_65 ) ) {
F_27 ( V_60 ) ;
V_64 = V_1 ;
return V_64 ;
}
F_27 ( V_1 ) ;
V_64 = V_60 ;
return V_64 ;
#endif
}
void
F_50 ( const char * V_67 )
{
F_27 ( V_64 ) ;
V_64 = F_22 ( V_67 ) ;
}
const char *
F_51 ( void )
{
static char * V_68 = NULL ;
F_27 ( V_68 ) ;
V_68 = F_25 ( L_22 , F_44 () ,
V_53 , V_69 ) ;
return V_68 ;
}
const char *
F_37 ( void )
{
static char * V_70 = NULL ;
if ( ! V_70 ) {
V_70 = F_25 ( L_22 , F_21 () ,
V_53 , V_69 ) ;
}
return V_70 ;
}
static const char *
F_52 ( const T_6 * V_46 )
{
static char * V_71 = NULL ;
F_27 ( V_71 ) ;
if ( V_46 && strlen ( V_46 ) > 0 &&
strcmp ( V_46 , V_48 ) != 0 ) {
V_71 = F_25 ( L_22 , F_51 () ,
V_53 , V_46 ) ;
} else {
V_71 = F_22 ( F_44 () ) ;
}
return V_71 ;
}
T_5
F_53 ( const T_6 * V_46 , T_5 V_72 )
{
if ( V_72 ) {
T_6 * V_1 = F_25 ( L_22 , F_37 () ,
V_53 , V_46 ) ;
if ( F_6 ( V_1 ) == V_8 ) {
F_27 ( V_1 ) ;
return TRUE ;
}
F_27 ( V_1 ) ;
} else {
if ( F_6 ( F_52 ( V_46 ) ) == V_8 ) {
return TRUE ;
}
}
return FALSE ;
}
static int
F_54 ( const char * V_73 , char * * V_74 )
{
T_7 * V_49 ;
T_8 * V_50 ;
T_6 * V_4 ;
int V_75 = 0 ;
if ( ( V_49 = F_38 ( V_73 , 0 , NULL ) ) != NULL ) {
while ( ( V_50 = F_39 ( V_49 ) ) != NULL ) {
V_4 = F_25 ( L_22 , V_73 , V_53 ,
F_40 ( V_50 ) ) ;
if ( F_6 ( V_4 ) != V_8 ) {
V_75 = F_55 ( V_4 ) ;
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
F_41 ( V_49 ) ;
}
if ( V_75 == 0 && ( V_75 = F_55 ( V_73 ) ) != 0 ) {
* V_74 = F_22 ( V_73 ) ;
}
return V_75 ;
}
int
F_56 ( const char * V_46 , char * * V_74 )
{
const char * V_76 = F_52 ( V_46 ) ;
int V_75 = 0 ;
if ( F_6 ( V_76 ) == V_8 ) {
V_75 = F_54 ( V_76 , V_74 ) ;
}
return V_75 ;
}
int
F_57 ( const char * V_77 , const char * V_78 ,
char * * V_79 , char * * V_80 )
{
char * V_81 = F_22 ( F_52 ( V_77 ) ) ;
char * V_82 = F_22 ( F_52 ( V_78 ) ) ;
int V_75 = 0 ;
V_75 = F_58 ( V_81 , V_82 ) ;
if ( V_75 != 0 ) {
* V_79 = F_22 ( V_81 ) ;
* V_80 = F_22 ( V_82 ) ;
}
F_27 ( V_81 ) ;
F_27 ( V_82 ) ;
return V_75 ;
}
int
F_59 ( const char * V_46 , char * * V_74 )
{
const char * V_83 ;
#ifdef F_2
char * V_84 , * V_85 ;
T_4 V_86 ;
#endif
T_1 V_87 ;
int V_75 ;
int V_88 ;
if ( V_46 ) {
if ( F_59 ( NULL , V_74 ) == - 1 ) {
return - 1 ;
}
V_83 = F_51 () ;
if ( F_7 ( V_83 , & V_87 ) != 0 ) {
if ( V_6 != V_89 ) {
V_88 = V_6 ;
* V_74 = F_22 ( V_83 ) ;
V_6 = V_88 ;
return - 1 ;
}
V_75 = F_60 ( V_83 , 0755 ) ;
if ( V_75 == - 1 ) {
* V_74 = F_22 ( V_83 ) ;
return V_75 ;
}
}
}
V_83 = F_52 ( V_46 ) ;
if ( F_7 ( V_83 , & V_87 ) != 0 ) {
if ( V_6 != V_89 ) {
V_88 = V_6 ;
* V_74 = F_22 ( V_83 ) ;
V_6 = V_88 ;
return - 1 ;
}
#ifdef F_2
V_84 = F_22 ( V_83 ) ;
V_85 = F_5 ( V_84 ) ;
V_86 = strlen ( V_85 ) ;
if ( V_86 > 0
&& V_85 [ V_86 - 1 ] != ':'
&& F_7 ( V_85 , & V_87 ) != 0 ) {
if ( V_6 != V_89 ) {
V_88 = V_6 ;
* V_74 = F_22 ( V_83 ) ;
V_6 = V_88 ;
return - 1 ;
}
V_75 = F_60 ( V_85 , 0755 ) ;
if ( V_75 == - 1 ) {
* V_74 = V_85 ;
return - 1 ;
}
}
F_27 ( V_84 ) ;
V_75 = F_60 ( V_83 , 0755 ) ;
#else
V_75 = F_61 ( V_83 , 0755 ) ;
#endif
} else {
V_75 = 0 ;
}
if ( V_75 == - 1 )
* V_74 = F_22 ( V_83 ) ;
return V_75 ;
}
int
F_62 ( char * * V_74 )
{
return F_59 ( V_47 , V_74 ) ;
}
int
F_63 ( const char * V_78 , const char * V_77 , T_5 V_90 ,
char * * V_91 , char * * V_80 , char * * V_79 )
{
T_6 * V_81 ;
T_6 * V_82 = F_22 ( F_52 ( V_78 ) ) ;
T_6 * V_4 , * V_92 , * V_93 ;
T_9 * V_94 , * V_50 ;
if ( V_90 ) {
if ( strcmp ( V_77 , V_48 ) == 0 ) {
V_81 = F_22 ( F_37 () ) ;
} else {
V_81 = F_25 ( L_22 , F_37 () , V_53 , V_77 ) ;
}
} else {
V_81 = F_22 ( F_52 ( V_77 ) ) ;
}
V_94 = F_64 ( V_55 ) ;
V_50 = F_65 ( V_94 ) ;
while ( V_50 ) {
V_4 = ( T_6 * ) V_50 -> V_95 ;
V_92 = F_25 ( L_22 , V_81 , V_53 , V_4 ) ;
V_93 = F_25 ( L_22 , V_82 , V_53 , V_4 ) ;
if ( F_66 ( V_92 ) && ! F_67 ( V_92 , V_93 ) ) {
* V_91 = F_22 ( V_4 ) ;
* V_80 = V_82 ;
* V_79 = V_81 ;
F_27 ( V_92 ) ;
F_27 ( V_93 ) ;
return - 1 ;
}
F_27 ( V_92 ) ;
F_27 ( V_93 ) ;
V_50 = F_68 ( V_50 ) ;
}
F_69 ( V_94 ) ;
F_27 ( V_81 ) ;
F_27 ( V_82 ) ;
return 0 ;
}
extern const char *
F_70 ( void )
{
#ifdef F_2
T_10 V_96 [ V_97 ] ;
if ( V_98 != NULL )
return V_98 ;
if ( F_71 ( NULL , V_96 , V_99 , FALSE ) ) {
V_98 = F_72 ( V_96 , - 1 , NULL , NULL , NULL ) ;
return V_98 ;
} else {
return L_33 ;
}
#else
return L_33 ;
#endif
}
void
F_73 ( const char * V_67 )
{
F_27 ( V_98 ) ;
V_98 = F_22 ( V_67 ) ;
}
static const char *
F_74 ( void )
{
static const char * V_100 = NULL ;
const char * V_101 , * V_102 ;
char * V_103 ;
char * V_104 ;
if ( V_100 )
return V_100 ;
V_101 = F_23 ( L_34 ) ;
if ( V_101 != NULL ) {
V_102 = F_23 ( L_35 ) ;
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
V_100 = L_28 ;
}
return V_100 ;
}
char *
F_75 ( const char * V_4 , T_5 V_105 )
{
char * V_1 ;
if ( V_58 && V_105 && ! F_76 ( V_55 , V_4 ) ) {
F_77 ( V_55 , F_22 ( V_4 ) , F_22 ( V_4 ) ) ;
}
if ( V_105 ) {
V_1 = F_25 ( L_37 V_53 L_37 ,
F_52 ( V_47 ) , V_4 ) ;
} else {
V_1 = F_25 ( L_37 V_53 L_37 ,
F_52 ( NULL ) , V_4 ) ;
}
return V_1 ;
}
char *
F_78 ( const char * V_4 )
{
if ( V_32 &&
( ! strcmp ( V_4 , L_38 ) ||
! strcmp ( V_4 , L_39 ) ) ) {
return F_25 ( L_37 V_53 L_37 , F_20 () , V_4 ) ;
} else {
return F_25 ( L_37 V_53 L_37 , F_21 () , V_4 ) ;
}
}
char *
F_79 ( void )
{
return F_75 ( V_106 , FALSE ) ;
}
const char *
F_80 ( int V_107 , T_5 V_108 )
{
const char * V_109 ;
static char V_110 [ 1024 + 1 ] ;
switch ( V_107 ) {
case V_89 :
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
#ifdef F_81
case F_81 :
V_109 = L_46 ;
break;
#endif
case V_113 :
V_109 = L_47 ;
break;
#ifdef F_82
case F_82 :
V_109 = L_48 V_114 L_49 ;
break;
#endif
case V_24 :
#if V_115 == 4
#define F_83 "it can't be handled by a 32-bit application"
#else
#if F_12 ( F_2 )
#define F_83 "the pagefile is too small"
#elif F_12 ( V_10 )
#define F_83 "your system ran out of swap file space"
#else
#define F_83 "your system is out of swap space"
#endif
#endif
if ( V_108 )
V_109 = L_50 F_83 L_51 ;
else
V_109 = L_52 F_83 L_51 ;
break;
default:
F_84 ( V_110 , sizeof( V_110 ) ,
L_53 ,
V_108 ? L_54 : L_55 ,
F_85 ( V_107 ) ) ;
V_109 = V_110 ;
break;
}
return V_109 ;
}
const char *
F_86 ( int V_107 )
{
const char * V_109 ;
static char V_110 [ 1024 + 1 ] ;
switch ( V_107 ) {
case V_112 :
V_109 = L_56 ;
break;
#ifdef F_81
case F_81 :
V_109 = L_57 ;
break;
#endif
default:
F_84 ( V_110 , sizeof( V_110 ) ,
L_58 ,
F_85 ( V_107 ) ) ;
V_109 = V_110 ;
break;
}
return V_109 ;
}
T_5
F_66 ( const char * V_116 )
{
T_1 V_117 ;
if ( ! V_116 ) {
return FALSE ;
}
#if F_12 ( V_118 ) && V_118 < 1900
V_117 . V_119 = 1 ;
F_7 ( V_116 , & V_117 ) ;
if ( V_117 . V_119 == 0 ) {
return TRUE ;
} else {
return FALSE ;
}
#else
if ( F_7 ( V_116 , & V_117 ) != 0 && V_6 == V_89 ) {
return FALSE ;
} else {
return TRUE ;
}
#endif
}
T_5
F_87 ( const char * V_120 , const char * V_121 )
{
#ifdef F_2
char V_122 [ V_97 ] , V_123 [ V_97 ] ;
if( F_88 ( V_122 , V_120 , V_97 ) == NULL ) {
return FALSE ;
}
if( F_88 ( V_123 , V_121 , V_97 ) == NULL ) {
return FALSE ;
}
if( strcmp ( V_122 , V_123 ) == 0 ) {
return TRUE ;
} else {
return FALSE ;
}
#else
T_1 V_124 , V_125 ;
if ( F_7 ( V_120 , & V_124 ) == - 1 )
return FALSE ;
if ( F_7 ( V_121 , & V_125 ) == - 1 )
return FALSE ;
return ( V_124 . V_126 == V_125 . V_126 &&
V_124 . V_119 == V_125 . V_119 ) ;
#endif
}
T_5
F_67 ( const char * V_127 , const char * V_128 )
{
int V_129 , V_130 , V_107 ;
T_3 V_131 , V_132 ;
T_11 * V_133 = NULL ;
V_129 = F_89 ( V_127 , V_134 | V_135 , 0000 ) ;
if ( V_129 < 0 ) {
F_90 ( V_127 , V_6 , FALSE ) ;
goto V_136;
}
V_130 = F_89 ( V_128 , V_137 | V_138 | V_139 | V_135 , 0644 ) ;
if ( V_130 < 0 ) {
F_90 ( V_128 , V_6 , TRUE ) ;
F_91 ( V_129 ) ;
goto V_136;
}
#define F_92 65536
V_133 = ( T_11 * ) F_13 ( F_92 ) ;
while ( ( V_131 = F_93 ( V_129 , V_133 , F_92 ) ) > 0 ) {
V_132 = F_94 ( V_130 , V_133 , V_131 ) ;
if ( V_132 < V_131 ) {
if ( V_132 < 0 )
V_107 = V_6 ;
else
V_107 = V_140 ;
F_95 ( V_128 , V_107 ) ;
F_91 ( V_129 ) ;
F_91 ( V_130 ) ;
goto V_136;
}
}
if ( V_131 < 0 ) {
V_107 = V_6 ;
F_96 ( V_127 , V_107 ) ;
F_91 ( V_129 ) ;
F_91 ( V_130 ) ;
goto V_136;
}
F_91 ( V_129 ) ;
if ( F_91 ( V_130 ) < 0 ) {
F_95 ( V_128 , V_6 ) ;
goto V_136;
}
F_27 ( V_133 ) ;
V_133 = NULL ;
return TRUE ;
V_136:
F_27 ( V_133 ) ;
return FALSE ;
}
