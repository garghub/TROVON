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
return V_10 ;
}
const char *
F_12 ( void )
{
#ifdef F_2
char * V_11 ;
#endif
static const char * V_12 = NULL ;
if ( V_12 != NULL )
return V_12 ;
#ifdef F_2
V_11 = F_13 ( L_1 ) ;
if ( V_11 != NULL ) {
V_12 = V_11 ;
} else {
if ( V_10 != NULL ) {
V_12 = V_10 ;
} else {
V_12 = L_2 ;
}
}
#else
if ( V_13 ) {
V_12 = getenv ( L_3 ) ;
if ( V_12 != NULL )
return V_12 ;
}
if ( V_13 && V_10 != NULL ) {
V_12 = V_10 ;
} else {
if ( getenv ( L_4 ) && ! F_14 () ) {
V_12 = F_15 ( getenv ( L_4 ) ) ;
} else {
V_12 = V_14 ;
}
}
#endif
return V_12 ;
}
static void
F_16 ( void )
{
#ifdef F_2
V_15 = F_17 ( L_5 , F_12 () ,
V_16 ) ;
if ( F_6 ( V_15 ) != V_8 ) {
F_18 ( ( V_17 ) V_15 ) ;
V_15 = F_17 ( L_6 , F_12 () ) ;
V_13 = TRUE ;
}
#else
if ( V_13 ) {
V_15 = F_17 ( L_7 , F_12 () ) ;
} else {
if ( getenv ( L_8 ) && ! F_14 () ) {
V_15 = F_15 ( getenv ( L_8 ) ) ;
} else {
V_15 = V_18 ;
}
}
#endif
}
const char *
F_19 ( void )
{
#ifdef F_20
if ( ! V_15 ) F_16 () ;
return V_15 ;
#else
return NULL ;
#endif
}
static void
F_21 ( void )
{
#ifdef F_2
V_19 = F_17 ( L_9 , F_12 () ,
V_16 ) ;
if ( F_6 ( V_19 ) != V_8 ) {
F_18 ( ( V_17 ) V_19 ) ;
V_19 = F_17 ( L_10 , F_12 () ) ;
V_13 = TRUE ;
}
#else
if ( V_13 ) {
V_19 = F_17 ( L_11 , F_12 () ) ;
} else {
if ( getenv ( L_12 ) && ! F_14 () ) {
V_19 = F_15 ( getenv ( L_12 ) ) ;
} else {
V_19 = V_20 ;
}
}
#endif
}
const char *
F_22 ( void )
{
#if F_23 ( V_21 ) || F_23 ( V_22 )
if ( ! V_19 ) F_21 () ;
return V_19 ;
#else
return NULL ;
#endif
}
T_2
F_24 ( void )
{
return V_13 ;
}
const char *
F_25 ( void )
{
#ifdef F_2
return F_12 () ;
#else
return L_13 ;
#endif
}
void
F_26 ( const T_3 * V_23 )
{
F_18 ( V_24 ) ;
if ( V_23 && strlen ( V_23 ) > 0 &&
strcmp ( V_23 , V_25 ) != 0 ) {
V_24 = F_15 ( V_23 ) ;
} else {
V_24 = NULL ;
}
}
const char *
F_27 ( void )
{
if ( V_24 ) {
return V_24 ;
} else {
return V_25 ;
}
}
T_2
F_28 ( void )
{
return ( ! V_24 || strcmp ( V_24 , V_25 ) == 0 ) ? TRUE : FALSE ;
}
T_2
F_29 ( void )
{
T_4 * V_26 ;
T_5 * V_27 ;
const T_3 * V_28 = F_30 () ;
T_3 * V_4 ;
T_2 V_29 = FALSE ;
if ( ( F_6 ( V_28 ) == V_8 ) &&
( ( V_26 = F_31 ( V_28 , 0 , NULL ) ) != NULL ) )
{
while ( ( V_27 = F_32 ( V_26 ) ) != NULL ) {
V_4 = F_17 ( L_14 , V_28 , V_30 ,
F_33 ( V_27 ) ) ;
if ( F_6 ( V_4 ) == V_8 ) {
V_29 = TRUE ;
F_18 ( V_4 ) ;
break;
}
F_18 ( V_4 ) ;
}
F_34 ( V_26 ) ;
}
return V_29 ;
}
void
F_35 ( T_2 V_31 )
{
if ( V_31 ) {
V_32 = F_36 ( V_33 , V_34 ) ;
}
V_35 = V_31 ;
}
static const char *
F_37 ( void )
{
#ifdef F_2
char * V_36 ;
char * V_37 ;
char * V_38 ;
#else
const char * V_39 ;
struct V_40 * V_41 ;
#endif
if ( V_42 != NULL )
return V_42 ;
#ifdef F_2
V_38 = F_13 ( L_15 ) ;
if ( V_38 != NULL ) {
V_42 = V_38 ;
} else {
V_36 = F_13 ( L_16 ) ;
if ( V_36 != NULL ) {
V_42 = F_17 ( L_17 V_30 L_17 ,
V_36 , V_43 ) ;
} else {
V_37 = F_13 ( L_18 ) ;
if ( V_37 != NULL ) {
V_42 = F_17 (
L_17 V_30 L_19 V_30 L_17 ,
V_37 , V_43 ) ;
} else {
V_42 = F_17 ( L_20 V_30 L_17 , V_43 ) ;
}
}
}
#else
V_39 = getenv ( L_21 ) ;
if ( V_39 == NULL ) {
V_41 = F_38 ( F_39 () ) ;
if ( V_41 != NULL ) {
V_39 = V_41 -> V_44 ;
} else {
V_39 = L_22 ;
}
}
V_42 = F_17 ( L_17 V_30 L_17 , V_39 , V_43 ) ;
#endif
return V_42 ;
}
const char *
F_40 ( void )
{
static char * V_45 = NULL ;
F_18 ( V_45 ) ;
V_45 = F_17 ( L_14 , F_37 () ,
V_30 , V_46 ) ;
return V_45 ;
}
const char *
F_30 ( void )
{
static char * V_47 = NULL ;
if ( ! V_47 ) {
V_47 = F_17 ( L_14 , F_12 () ,
V_30 , V_46 ) ;
}
return V_47 ;
}
static const char *
F_41 ( const T_3 * V_23 )
{
static char * V_48 = NULL ;
F_18 ( V_48 ) ;
if ( V_23 && strlen ( V_23 ) > 0 &&
strcmp ( V_23 , V_25 ) != 0 ) {
V_48 = F_17 ( L_14 , F_40 () ,
V_30 , V_23 ) ;
} else {
V_48 = F_15 ( F_37 () ) ;
}
return V_48 ;
}
T_2
F_42 ( const T_3 * V_23 , T_2 V_49 )
{
if ( V_49 ) {
T_3 * V_1 = F_17 ( L_14 , F_30 () ,
V_30 , V_23 ) ;
if ( F_6 ( V_1 ) == V_8 ) {
F_18 ( V_1 ) ;
return TRUE ;
}
F_18 ( V_1 ) ;
} else {
if ( F_6 ( F_41 ( V_23 ) ) == V_8 ) {
return TRUE ;
}
}
return FALSE ;
}
static int
F_43 ( const char * V_50 , char * * V_51 )
{
T_4 * V_26 ;
T_5 * V_27 ;
T_3 * V_4 ;
int V_52 = 0 ;
if ( ( V_26 = F_31 ( V_50 , 0 , NULL ) ) != NULL ) {
while ( ( V_27 = F_32 ( V_26 ) ) != NULL ) {
V_4 = F_17 ( L_14 , V_50 , V_30 ,
F_33 ( V_27 ) ) ;
if ( F_6 ( V_4 ) != V_8 ) {
V_52 = F_44 ( V_4 ) ;
#if 0
} else {
ret = delete_directory (filename, pf_dir_path_return);
#endif
}
if ( V_52 != 0 ) {
* V_51 = V_4 ;
break;
}
F_18 ( V_4 ) ;
}
F_34 ( V_26 ) ;
}
if ( V_52 == 0 && ( V_52 = F_44 ( V_50 ) ) != 0 ) {
* V_51 = F_15 ( V_50 ) ;
}
return V_52 ;
}
int
F_45 ( const char * V_23 , char * * V_51 )
{
const char * V_53 = F_41 ( V_23 ) ;
int V_52 = 0 ;
if ( F_6 ( V_53 ) == V_8 ) {
V_52 = F_43 ( V_53 , V_51 ) ;
}
return V_52 ;
}
int
F_46 ( const char * V_54 , const char * V_55 ,
char * * V_56 , char * * V_57 )
{
char * V_58 = F_15 ( F_41 ( V_54 ) ) ;
char * V_59 = F_15 ( F_41 ( V_55 ) ) ;
int V_52 = 0 ;
V_52 = F_47 ( V_58 , V_59 ) ;
if ( V_52 != 0 ) {
* V_56 = F_15 ( V_58 ) ;
* V_57 = F_15 ( V_59 ) ;
}
F_18 ( V_58 ) ;
F_18 ( V_59 ) ;
return V_52 ;
}
int
F_48 ( const char * V_23 , char * * V_51 )
{
const char * V_60 ;
#ifdef F_2
char * V_61 , * V_62 ;
T_6 V_63 ;
#endif
T_1 V_64 ;
int V_52 ;
if ( V_23 ) {
if ( F_48 ( NULL , V_51 ) == - 1 ) {
return - 1 ;
}
V_60 = F_40 () ;
if ( F_7 ( V_60 , & V_64 ) != 0 && V_6 == V_65 ) {
V_52 = F_49 ( V_60 , 0755 ) ;
if ( V_52 == - 1 ) {
* V_51 = F_15 ( V_60 ) ;
return V_52 ;
}
}
}
V_60 = F_41 ( V_23 ) ;
if ( F_7 ( V_60 , & V_64 ) != 0 && V_6 == V_65 ) {
#ifdef F_2
V_61 = F_15 ( V_60 ) ;
V_62 = F_5 ( V_61 ) ;
V_63 = strlen ( V_62 ) ;
if ( V_63 > 0
&& V_62 [ V_63 - 1 ] != ':'
&& F_7 ( V_62 , & V_64 ) != 0 ) {
V_52 = F_49 ( V_62 , 0755 ) ;
if ( V_52 == - 1 ) {
* V_51 = V_62 ;
return - 1 ;
}
}
F_18 ( V_61 ) ;
V_52 = F_49 ( V_60 , 0755 ) ;
#else
V_52 = F_49 ( V_60 , 0755 ) ;
#endif
} else {
V_52 = 0 ;
}
if ( V_52 == - 1 )
* V_51 = F_15 ( V_60 ) ;
return V_52 ;
}
int
F_50 ( char * * V_51 )
{
return F_48 ( V_24 , V_51 ) ;
}
int
F_51 ( const char * V_55 , const char * V_54 , T_2 V_66 ,
char * * V_67 , char * * V_57 , char * * V_56 )
{
T_3 * V_58 ;
T_3 * V_59 = F_15 ( F_41 ( V_55 ) ) ;
T_3 * V_4 , * V_68 , * V_69 ;
T_7 * V_70 , * V_27 ;
if ( V_66 ) {
if ( strcmp ( V_54 , V_25 ) == 0 ) {
V_58 = F_15 ( F_30 () ) ;
} else {
V_58 = F_17 ( L_14 , F_30 () , V_30 , V_54 ) ;
}
} else {
V_58 = F_15 ( F_41 ( V_54 ) ) ;
}
V_70 = F_52 ( V_32 ) ;
V_27 = F_53 ( V_70 ) ;
while ( V_27 ) {
V_4 = ( T_3 * ) V_27 -> V_71 ;
V_68 = F_17 ( L_14 , V_58 , V_30 , V_4 ) ;
V_69 = F_17 ( L_14 , V_59 , V_30 , V_4 ) ;
if ( F_54 ( V_68 ) && ! F_55 ( V_68 , V_69 ) ) {
* V_67 = F_15 ( V_4 ) ;
* V_57 = V_59 ;
* V_56 = V_58 ;
F_18 ( V_68 ) ;
F_18 ( V_69 ) ;
return - 1 ;
}
F_18 ( V_68 ) ;
F_18 ( V_69 ) ;
V_27 = F_56 ( V_27 ) ;
}
F_57 ( V_70 ) ;
F_18 ( V_58 ) ;
F_18 ( V_59 ) ;
return 0 ;
}
extern const char *
F_58 ( void )
{
#ifdef F_2
char * V_72 ;
T_8 V_73 [ V_74 ] ;
char * V_75 ;
BOOL V_76 ;
if ( V_77 != NULL )
return V_77 ;
V_72 = F_13 ( L_23 ) ;
if ( V_72 != NULL ) {
V_75 = F_17 ( L_24 , V_72 , V_78 ) ;
V_77 = V_75 ;
return V_75 ;
} else {
V_76 = F_59 ( NULL , V_73 , V_79 ,
FALSE ) ;
if( V_76 == TRUE ) {
V_75 = F_60 ( V_73 ) ;
V_77 = V_75 ;
return V_75 ;
} else {
return L_25 ;
}
}
#else
return L_25 ;
#endif
}
static const char *
F_61 ( void )
{
static const char * V_80 = NULL ;
char * V_81 , * V_82 ;
char * V_83 ;
char * V_84 ;
if ( V_80 )
return V_80 ;
V_81 = F_13 ( L_26 ) ;
if ( V_81 != NULL ) {
V_82 = F_13 ( L_27 ) ;
if ( V_82 != NULL ) {
V_83 = F_17 ( L_24 , V_81 , V_82 ) ;
V_84 = F_1 ( V_83 ) ;
if ( V_84 != NULL && * ( V_84 + 1 ) == '\0' ) {
* V_84 = '\0' ;
}
V_80 = V_83 ;
} else
V_80 = V_81 ;
} else {
V_80 = L_20 ;
}
return V_80 ;
}
char *
F_62 ( const char * V_4 , T_2 V_85 )
{
char * V_1 ;
if ( V_35 && V_85 && ! F_63 ( V_32 , V_4 ) ) {
F_64 ( V_32 , F_15 ( V_4 ) , F_15 ( V_4 ) ) ;
}
if ( V_85 ) {
V_1 = F_17 ( L_17 V_30 L_17 ,
F_41 ( V_24 ) , V_4 ) ;
} else {
V_1 = F_17 ( L_17 V_30 L_17 ,
F_41 ( NULL ) , V_4 ) ;
}
return V_1 ;
}
int
F_65 ( int T_9 V_86 , const char * V_87 )
{
T_3 * V_88 , * V_89 ;
V_89 = strchr ( V_87 , ':' ) ;
if ( V_89 == NULL ) {
return 1 ;
}
V_88 = V_89 ;
* V_88 ++ = '\0' ;
while ( isspace ( ( V_90 ) * V_88 ) )
V_88 ++ ;
if ( * V_88 == '\0' ) {
* V_89 = ':' ;
return 1 ;
}
if( F_6 ( V_88 ) != V_8 ) {
* V_89 = ':' ;
return 1 ;
}
if ( strcmp ( V_87 , L_28 ) == 0 ) {
V_42 = V_88 ;
} else if ( strcmp ( V_87 , L_29 ) == 0 ) {
V_77 = V_88 ;
} else {
return 1 ;
}
* V_89 = ':' ;
return 0 ;
}
char *
F_66 ( const char * V_4 )
{
return F_17 ( L_17 V_30 L_17 , F_12 () , V_4 ) ;
}
char *
F_67 ( void )
{
return F_62 ( V_91 , FALSE ) ;
}
T_2
F_68 ( const char * V_1 )
{
return F_69 ( V_1 ) == 0 ;
}
char * F_70 ( const char * V_4 )
{
return F_17 ( L_17 V_30 L_17 , F_71 () , V_4 ) ;
}
const char *
F_72 ( int V_92 , T_2 V_93 )
{
const char * V_94 ;
static char V_95 [ 1024 + 1 ] ;
switch ( V_92 ) {
case V_65 :
if ( V_93 )
V_94 = L_30 ;
else
V_94 = L_31 ;
break;
case V_96 :
if ( V_93 )
V_94 = L_32 ;
else
V_94 = L_33 ;
break;
case V_8 :
V_94 = L_34 ;
break;
case V_97 :
V_94 = L_35 ;
break;
#ifdef F_73
case F_73 :
V_94 = L_36 ;
break;
#endif
case V_98 :
V_94 = L_37 ;
break;
default:
F_74 ( V_95 , sizeof( V_95 ) ,
L_38 ,
V_93 ? L_39 : L_40 ,
F_75 ( V_92 ) ) ;
V_94 = V_95 ;
break;
}
return V_94 ;
}
const char *
F_76 ( int V_92 )
{
const char * V_94 ;
static char V_95 [ 1024 + 1 ] ;
switch ( V_92 ) {
case V_97 :
V_94 = L_41 ;
break;
#ifdef F_73
case F_73 :
V_94 = L_42 ;
break;
#endif
default:
F_74 ( V_95 , sizeof( V_95 ) ,
L_43 ,
F_75 ( V_92 ) ) ;
V_94 = V_95 ;
break;
}
return V_94 ;
}
T_2
F_54 ( const char * V_99 )
{
T_1 V_100 ;
if ( ! V_99 ) {
return FALSE ;
}
#ifdef F_2
V_100 . V_101 = 1 ;
F_7 ( V_99 , & V_100 ) ;
if ( V_100 . V_101 == 0 ) {
return TRUE ;
} else {
return FALSE ;
}
#else
if ( F_7 ( V_99 , & V_100 ) != 0 && V_6 == V_65 ) {
return FALSE ;
} else {
return TRUE ;
}
#endif
}
T_2
F_77 ( const char * V_102 , const char * V_103 )
{
#ifdef F_2
char V_104 [ V_74 ] , V_105 [ V_74 ] ;
if( F_78 ( V_104 , V_102 , V_74 ) == NULL ) {
return FALSE ;
}
if( F_78 ( V_105 , V_103 , V_74 ) == NULL ) {
return FALSE ;
}
if( strcmp ( V_104 , V_105 ) == 0 ) {
return TRUE ;
} else {
return FALSE ;
}
#else
T_1 V_106 , V_107 ;
if ( F_7 ( V_102 , & V_106 ) == - 1 )
return FALSE ;
if ( F_7 ( V_103 , & V_107 ) == - 1 )
return FALSE ;
return ( V_106 . V_108 == V_107 . V_108 &&
V_106 . V_101 == V_107 . V_101 ) ;
#endif
}
T_2
F_55 ( const char * V_109 , const char * V_110 )
{
int V_111 , V_112 , V_92 ;
T_10 V_113 , V_114 ;
T_11 * V_115 = NULL ;
V_111 = F_79 ( V_109 , V_116 | V_117 , 0000 ) ;
if ( V_111 < 0 ) {
F_80 ( V_109 , V_6 , FALSE ) ;
goto V_118;
}
V_112 = F_79 ( V_110 , V_119 | V_120 | V_121 | V_117 , 0644 ) ;
if ( V_112 < 0 ) {
F_80 ( V_110 , V_6 , TRUE ) ;
F_81 ( V_111 ) ;
goto V_118;
}
#define F_82 65536
V_115 = ( T_11 * ) F_83 ( F_82 ) ;
while ( ( V_113 = F_84 ( V_111 , V_115 , F_82 ) ) > 0 ) {
V_114 = F_85 ( V_112 , V_115 , V_113 ) ;
if ( V_114 < V_113 ) {
if ( V_114 < 0 )
V_92 = V_6 ;
else
V_92 = V_122 ;
F_86 ( V_110 , V_92 ) ;
F_81 ( V_111 ) ;
F_81 ( V_112 ) ;
goto V_118;
}
}
if ( V_113 < 0 ) {
V_92 = V_6 ;
F_87 ( V_109 , V_92 ) ;
F_81 ( V_111 ) ;
F_81 ( V_112 ) ;
goto V_118;
}
F_81 ( V_111 ) ;
if ( F_81 ( V_112 ) < 0 ) {
F_86 ( V_110 , V_6 ) ;
goto V_118;
}
F_18 ( V_115 ) ;
V_115 = NULL ;
return TRUE ;
V_118:
F_18 ( V_115 ) ;
return FALSE ;
}
