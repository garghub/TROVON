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
char *
F_20 ( const char * T_5
#ifdef F_2
V_30
#endif
, void * T_6
#if F_12 ( F_2 ) || ! F_12 ( V_31 )
V_30
#endif
)
{
#ifdef F_2
T_7 V_32 [ V_33 + 2 ] ;
char * V_34 ;
T_8 error ;
T_7 * V_35 ;
T_9 * V_36 ;
T_4 V_37 ;
if ( F_21 ( NULL , V_32 , F_22 ( V_32 ) ) != 0 && F_23 () != V_38 ) {
V_34 = F_24 ( V_32 ) ;
V_39 = F_25 ( V_34 ) ;
if ( V_39 != NULL ) {
return NULL ;
} else {
return F_26 ( L_9 ,
V_34 ) ;
}
} else {
error = F_23 () ;
if ( F_27 ( V_40 | V_41 | V_42 ,
NULL , error , 0 , ( V_43 ) & V_35 , 0 , NULL ) == 0 ) {
return F_26 ( L_10 ,
error , F_23 () ) ;
}
V_36 = F_24 ( V_35 ) ;
F_28 ( V_35 ) ;
V_37 = strlen ( V_36 ) ;
if ( V_37 >= 2 ) {
V_36 [ V_37 - 1 ] = '\0' ;
V_36 [ V_37 - 2 ] = '\0' ;
}
return F_26 ( L_11 ,
V_36 , error ) ;
}
#else
#ifdef V_31
T_10 V_44 ;
#endif
const char * V_45 ;
char * V_34 ;
char * V_46 ;
long V_47 ;
char * V_48 ;
char * V_49 , * V_50 ;
T_4 V_51 , V_52 ;
char * V_53 ;
char * V_1 ;
char * V_54 ;
if ( getenv ( L_12 ) != NULL
&& ! F_29 () )
V_55 = TRUE ;
V_45 = F_11 () ;
#ifdef V_31
if ( T_6 != NULL && V_45 == NULL ) {
if ( F_30 ( T_6 , & V_44 ) )
V_45 = V_44 . V_56 ;
}
#endif
if ( V_45 == NULL ) {
V_45 = T_5 ;
}
if ( V_45 [ 0 ] == '/' ) {
V_34 = F_31 ( V_45 ) ;
} else if ( strchr ( V_45 , '/' ) != NULL ) {
V_47 = F_32 ( L_13 , V_57 ) ;
if ( V_47 == - 1 ) {
return F_26 ( L_14 ,
F_33 ( V_6 ) ) ;
}
V_46 = ( char * ) F_13 ( V_47 ) ;
if ( F_34 ( V_46 , V_47 ) == NULL ) {
F_35 ( V_46 ) ;
return F_26 ( L_15 ,
F_33 ( V_6 ) ) ;
}
V_1 = F_26 ( L_16 , V_46 , V_45 ) ;
F_35 ( V_46 ) ;
V_34 = V_1 ;
} else {
V_34 = NULL ;
V_48 = getenv ( L_17 ) ;
V_49 = V_48 ;
if ( V_49 != NULL ) {
while ( * V_49 != '\0' ) {
V_50 = strchr ( V_49 , ':' ) ;
if ( V_50 == NULL )
V_50 = V_49 + strlen ( V_49 ) ;
V_51 = V_50 - V_49 ;
V_52 = V_51 + 1
+ strlen ( V_45 ) + 1 ;
V_1 = ( char * ) F_13 ( V_52 ) ;
memcpy ( V_1 , V_49 , V_51 ) ;
V_1 [ V_51 ] = '\0' ;
F_36 ( V_1 , L_18 , V_52 ) ;
F_36 ( V_1 , V_45 , V_52 ) ;
if ( F_37 ( V_1 , V_58 ) == 0 ) {
V_34 = V_1 ;
break;
}
if ( * V_50 == '\0' ) {
break;
}
if ( * V_50 == ':' )
V_50 ++ ;
V_49 = V_50 ;
F_35 ( V_1 ) ;
}
if ( V_34 == NULL ) {
return F_26 ( L_19 ,
V_45 , V_48 ) ;
}
} else {
return F_31 ( L_20 ) ;
}
}
V_54 = strrchr ( V_34 , '/' ) ;
if ( V_54 != NULL ) {
* V_54 = '\0' ;
V_54 = strrchr ( V_34 , '/' ) ;
if ( V_54 != NULL ) {
if ( strcmp ( V_54 , L_21 ) == 0 ) {
* V_54 = '\0' ;
if ( ! F_29 () )
V_55 = TRUE ;
}
#ifdef V_10
else {
if ( ! F_29 () ) {
char * V_59 , * V_60 ;
V_59 = strchr ( V_34 , '\0' ) ;
V_60 = V_59 ;
for (; ; ) {
while ( V_60 >= V_34 && * V_60 != '/' )
V_60 -- ;
if ( V_60 == V_34 ) {
break;
}
if ( strncmp ( V_60 , L_22 , V_59 - V_60 ) == 0 ) {
V_61 = ( char * ) F_13 ( V_60 - V_34 + 1 ) ;
memcpy ( V_61 , V_34 , V_60 - V_34 ) ;
V_61 [ V_60 - V_34 ] = '\0' ;
break;
}
V_59 = V_60 ;
V_60 -- ;
}
}
}
#endif
}
V_39 = V_34 ;
return NULL ;
} else {
V_53 = F_26 ( L_23 , V_34 ) ;
F_35 ( V_34 ) ;
return V_53 ;
}
#endif
}
const char *
F_38 ( void )
{
return V_39 ;
}
const char *
F_39 ( void )
{
#ifdef F_2
char * V_62 ;
#endif
static const char * V_63 = NULL ;
if ( V_63 != NULL )
return V_63 ;
#ifdef F_2
V_62 = F_40 ( L_24 ) ;
if ( V_62 != NULL ) {
V_63 = V_62 ;
} else {
if ( V_39 != NULL ) {
V_63 = V_39 ;
} else {
V_63 = L_25 ;
}
}
#else
if ( V_55 ) {
V_63 = F_31 ( V_64 ) ;
return V_63 ;
} else {
if ( getenv ( L_26 ) && ! F_29 () ) {
V_63 = F_31 ( getenv ( L_26 ) ) ;
}
#ifdef V_10
else if ( V_61 != NULL ) {
V_63 = F_26 ( L_27 ,
V_61 ) ;
}
#endif
else {
V_63 = V_65 ;
}
}
#endif
return V_63 ;
}
static void
F_41 ( void )
{
#ifdef F_2
V_66 = F_26 ( L_28 , F_39 () ,
V_67 ) ;
if ( F_6 ( V_66 ) != V_8 ) {
F_35 ( ( V_68 ) V_66 ) ;
V_66 = F_26 ( L_29 , F_39 () ) ;
V_55 = TRUE ;
}
#else
if ( V_55 ) {
V_66 = F_26 ( L_30 , F_38 () ) ;
} else {
if ( getenv ( L_31 ) && ! F_29 () ) {
V_66 = F_31 ( getenv ( L_31 ) ) ;
}
#ifdef V_10
else if ( V_61 != NULL ) {
V_66 = F_26 ( L_32 ,
V_61 ) ;
}
#endif
else {
V_66 = V_69 ;
}
}
#endif
}
const char *
F_42 ( void )
{
#if F_12 ( V_70 ) || F_12 ( V_71 )
if ( ! V_66 ) F_41 () ;
return V_66 ;
#else
return NULL ;
#endif
}
static void F_43 ( void ) {
#ifdef F_2
char * V_72 ;
V_72 = F_40 ( L_33 ) ;
if ( V_72 ) {
V_73 = F_31 ( V_72 ) ;
} else {
V_73 = F_26 ( L_34 , F_39 () ) ;
}
#else
if ( V_55 ) {
V_73 = F_26 ( L_35 , F_38 () ) ;
} else {
if ( getenv ( L_33 ) && ! F_29 () ) {
V_73 = F_31 ( getenv ( L_33 ) ) ;
}
#ifdef V_10
else if ( V_61 != NULL ) {
V_73 = F_26 ( L_36 ,
V_61 ) ;
}
#endif
else {
V_73 = V_74 ;
}
}
#endif
}
const char *
F_44 ( void ) {
#if F_12 ( V_75 )
if ( ! V_73 )
F_43 () ;
return V_73 ;
#else
return NULL ;
#endif
}
T_11
F_45 ( void )
{
return V_55 ;
}
const char *
F_46 ( void )
{
#ifdef F_2
return F_39 () ;
#else
return L_37 ;
#endif
}
void
F_47 ( const T_12 * V_76 )
{
F_35 ( V_77 ) ;
if ( V_76 && strlen ( V_76 ) > 0 &&
strcmp ( V_76 , V_78 ) != 0 ) {
V_77 = F_31 ( V_76 ) ;
} else {
V_77 = NULL ;
}
}
const char *
F_48 ( void )
{
if ( V_77 ) {
return V_77 ;
} else {
return V_78 ;
}
}
T_11
F_49 ( void )
{
return ( ! V_77 || strcmp ( V_77 , V_78 ) == 0 ) ? TRUE : FALSE ;
}
T_11
F_50 ( void )
{
T_13 * V_79 ;
T_14 * V_80 ;
const T_12 * V_81 = F_51 () ;
T_12 * V_4 ;
T_11 V_82 = FALSE ;
if ( ( F_6 ( V_81 ) == V_8 ) &&
( ( V_79 = F_52 ( V_81 , 0 , NULL ) ) != NULL ) )
{
while ( ( V_80 = F_53 ( V_79 ) ) != NULL ) {
V_4 = F_26 ( L_38 , V_81 , V_83 ,
F_54 ( V_80 ) ) ;
if ( F_6 ( V_4 ) == V_8 ) {
V_82 = TRUE ;
F_35 ( V_4 ) ;
break;
}
F_35 ( V_4 ) ;
}
F_55 ( V_79 ) ;
}
return V_82 ;
}
void
F_56 ( T_11 V_84 )
{
if ( V_84 ) {
V_85 = F_57 ( V_86 , V_87 ) ;
}
V_88 = V_84 ;
}
static const char *
F_58 ( void )
{
#ifdef F_2
const char * V_89 ;
#else
char * V_90 , * V_1 ;
struct V_91 * V_92 ;
const char * V_93 ;
#endif
if ( V_94 != NULL )
return V_94 ;
#ifdef F_2
V_89 = F_40 ( L_39 ) ;
if ( V_89 != NULL ) {
V_94 = F_31 ( V_89 ) ;
return V_94 ;
}
V_89 = F_40 ( L_40 ) ;
if ( V_89 != NULL ) {
V_94 = F_31 ( V_89 ) ;
return V_94 ;
}
V_89 = F_40 ( L_41 ) ;
if ( V_89 != NULL ) {
V_94 = F_59 ( V_89 , L_42 , NULL ) ;
return V_94 ;
}
V_89 = F_40 ( L_43 ) ;
if ( V_89 != NULL ) {
V_94 = F_59 ( V_89 , L_44 , L_42 , NULL ) ;
return V_94 ;
}
V_94 = F_59 ( L_45 , L_42 , NULL ) ;
return V_94 ;
#else
V_90 = F_59 ( F_60 () , L_46 , NULL ) ;
if ( F_61 ( V_90 , V_95 ) ) {
V_94 = V_90 ;
return V_94 ;
}
V_93 = getenv ( L_47 ) ;
if ( V_93 == NULL ) {
V_92 = F_62 ( F_63 () ) ;
if ( V_92 != NULL ) {
V_93 = V_92 -> V_96 ;
} else {
V_93 = L_48 ;
}
}
V_1 = F_59 ( V_93 , L_49 , NULL ) ;
if ( F_61 ( V_1 , V_95 ) ) {
F_35 ( V_90 ) ;
V_94 = V_1 ;
return V_94 ;
}
F_35 ( V_1 ) ;
V_94 = V_90 ;
return V_94 ;
#endif
}
void
F_64 ( const char * V_60 )
{
F_35 ( V_94 ) ;
V_94 = F_31 ( V_60 ) ;
}
const char *
F_65 ( void )
{
static char * V_97 = NULL ;
F_35 ( V_97 ) ;
V_97 = F_26 ( L_38 , F_58 () ,
V_83 , V_98 ) ;
return V_97 ;
}
const char *
F_51 ( void )
{
static char * V_99 = NULL ;
if ( ! V_99 ) {
V_99 = F_26 ( L_38 , F_39 () ,
V_83 , V_98 ) ;
}
return V_99 ;
}
static const char *
F_66 ( const T_12 * V_76 )
{
static char * V_100 = NULL ;
F_35 ( V_100 ) ;
if ( V_76 && strlen ( V_76 ) > 0 &&
strcmp ( V_76 , V_78 ) != 0 ) {
V_100 = F_26 ( L_38 , F_65 () ,
V_83 , V_76 ) ;
} else {
V_100 = F_31 ( F_58 () ) ;
}
return V_100 ;
}
T_11
F_67 ( const T_12 * V_76 , T_11 V_101 )
{
if ( V_101 ) {
T_12 * V_1 = F_26 ( L_38 , F_51 () ,
V_83 , V_76 ) ;
if ( F_6 ( V_1 ) == V_8 ) {
F_35 ( V_1 ) ;
return TRUE ;
}
F_35 ( V_1 ) ;
} else {
if ( F_6 ( F_66 ( V_76 ) ) == V_8 ) {
return TRUE ;
}
}
return FALSE ;
}
static int
F_68 ( const char * V_102 , char * * V_103 )
{
T_13 * V_79 ;
T_14 * V_80 ;
T_12 * V_4 ;
int V_104 = 0 ;
if ( ( V_79 = F_52 ( V_102 , 0 , NULL ) ) != NULL ) {
while ( ( V_80 = F_53 ( V_79 ) ) != NULL ) {
V_4 = F_26 ( L_38 , V_102 , V_83 ,
F_54 ( V_80 ) ) ;
if ( F_6 ( V_4 ) != V_8 ) {
V_104 = F_69 ( V_4 ) ;
#if 0
} else {
ret = delete_directory (filename, pf_dir_path_return);
#endif
}
if ( V_104 != 0 ) {
* V_103 = V_4 ;
break;
}
F_35 ( V_4 ) ;
}
F_55 ( V_79 ) ;
}
if ( V_104 == 0 && ( V_104 = F_69 ( V_102 ) ) != 0 ) {
* V_103 = F_31 ( V_102 ) ;
}
return V_104 ;
}
int
F_70 ( const char * V_76 , char * * V_103 )
{
const char * V_105 = F_66 ( V_76 ) ;
int V_104 = 0 ;
if ( F_6 ( V_105 ) == V_8 ) {
V_104 = F_68 ( V_105 , V_103 ) ;
}
return V_104 ;
}
int
F_71 ( const char * V_106 , const char * V_107 ,
char * * V_108 , char * * V_109 )
{
char * V_110 = F_31 ( F_66 ( V_106 ) ) ;
char * V_111 = F_31 ( F_66 ( V_107 ) ) ;
int V_104 = 0 ;
V_104 = F_72 ( V_110 , V_111 ) ;
if ( V_104 != 0 ) {
* V_108 = F_31 ( V_110 ) ;
* V_109 = F_31 ( V_111 ) ;
}
F_35 ( V_110 ) ;
F_35 ( V_111 ) ;
return V_104 ;
}
int
F_73 ( const char * V_76 , char * * V_103 )
{
const char * V_112 ;
#ifdef F_2
char * V_113 , * V_114 ;
T_4 V_115 ;
#endif
T_1 V_116 ;
int V_104 ;
if ( V_76 ) {
if ( F_73 ( NULL , V_103 ) == - 1 ) {
return - 1 ;
}
V_112 = F_65 () ;
if ( F_7 ( V_112 , & V_116 ) != 0 && V_6 == V_117 ) {
V_104 = F_74 ( V_112 , 0755 ) ;
if ( V_104 == - 1 ) {
* V_103 = F_31 ( V_112 ) ;
return V_104 ;
}
}
}
V_112 = F_66 ( V_76 ) ;
if ( F_7 ( V_112 , & V_116 ) != 0 && V_6 == V_117 ) {
#ifdef F_2
V_113 = F_31 ( V_112 ) ;
V_114 = F_5 ( V_113 ) ;
V_115 = strlen ( V_114 ) ;
if ( V_115 > 0
&& V_114 [ V_115 - 1 ] != ':'
&& F_7 ( V_114 , & V_116 ) != 0 ) {
V_104 = F_74 ( V_114 , 0755 ) ;
if ( V_104 == - 1 ) {
* V_103 = V_114 ;
return - 1 ;
}
}
F_35 ( V_113 ) ;
V_104 = F_74 ( V_112 , 0755 ) ;
#else
V_104 = F_75 ( V_112 , 0755 ) ;
#endif
} else {
V_104 = 0 ;
}
if ( V_104 == - 1 )
* V_103 = F_31 ( V_112 ) ;
return V_104 ;
}
int
F_76 ( char * * V_103 )
{
return F_73 ( V_77 , V_103 ) ;
}
int
F_77 ( const char * V_107 , const char * V_106 , T_11 V_118 ,
char * * V_119 , char * * V_109 , char * * V_108 )
{
T_12 * V_110 ;
T_12 * V_111 = F_31 ( F_66 ( V_107 ) ) ;
T_12 * V_4 , * V_120 , * V_121 ;
T_15 * V_122 , * V_80 ;
if ( V_118 ) {
if ( strcmp ( V_106 , V_78 ) == 0 ) {
V_110 = F_31 ( F_51 () ) ;
} else {
V_110 = F_26 ( L_38 , F_51 () , V_83 , V_106 ) ;
}
} else {
V_110 = F_31 ( F_66 ( V_106 ) ) ;
}
V_122 = F_78 ( V_85 ) ;
V_80 = F_79 ( V_122 ) ;
while ( V_80 ) {
V_4 = ( T_12 * ) V_80 -> V_123 ;
V_120 = F_26 ( L_38 , V_110 , V_83 , V_4 ) ;
V_121 = F_26 ( L_38 , V_111 , V_83 , V_4 ) ;
if ( F_80 ( V_120 ) && ! F_81 ( V_120 , V_121 ) ) {
* V_119 = F_31 ( V_4 ) ;
* V_109 = V_111 ;
* V_108 = V_110 ;
F_35 ( V_120 ) ;
F_35 ( V_121 ) ;
return - 1 ;
}
F_35 ( V_120 ) ;
F_35 ( V_121 ) ;
V_80 = F_82 ( V_80 ) ;
}
F_83 ( V_122 ) ;
F_35 ( V_110 ) ;
F_35 ( V_111 ) ;
return 0 ;
}
extern const char *
F_84 ( void )
{
#ifdef F_2
char * V_124 ;
T_7 V_125 [ V_126 ] ;
if ( V_127 != NULL )
return V_127 ;
V_124 = F_40 ( L_50 ) ;
if ( V_124 != NULL ) {
V_127 = F_26 ( L_51 , V_124 , V_128 ) ;
return V_127 ;
} else {
if ( F_85 ( NULL , V_125 , V_129 , FALSE ) ) {
V_127 = F_86 ( V_125 , - 1 , NULL , NULL , NULL ) ;
return V_127 ;
} else {
return L_52 ;
}
}
#else
return L_52 ;
#endif
}
void
F_87 ( const char * V_60 )
{
F_35 ( V_127 ) ;
V_127 = F_31 ( V_60 ) ;
}
static const char *
F_88 ( void )
{
static const char * V_130 = NULL ;
char * V_131 , * V_132 ;
char * V_133 ;
char * V_134 ;
if ( V_130 )
return V_130 ;
V_131 = F_40 ( L_53 ) ;
if ( V_131 != NULL ) {
V_132 = F_40 ( L_54 ) ;
if ( V_132 != NULL ) {
V_133 = F_26 ( L_51 , V_131 , V_132 ) ;
V_134 = F_1 ( V_133 ) ;
if ( V_134 != NULL && * ( V_134 + 1 ) == '\0' ) {
* V_134 = '\0' ;
}
V_130 = V_133 ;
} else
V_130 = V_131 ;
} else {
V_130 = L_45 ;
}
return V_130 ;
}
char *
F_89 ( const char * V_4 , T_11 V_135 )
{
char * V_1 ;
if ( V_88 && V_135 && ! F_90 ( V_85 , V_4 ) ) {
F_91 ( V_85 , F_31 ( V_4 ) , F_31 ( V_4 ) ) ;
}
if ( V_135 ) {
V_1 = F_26 ( L_55 V_83 L_55 ,
F_66 ( V_77 ) , V_4 ) ;
} else {
V_1 = F_26 ( L_55 V_83 L_55 ,
F_66 ( NULL ) , V_4 ) ;
}
return V_1 ;
}
char *
F_92 ( const char * V_4 )
{
if ( V_55 &&
( ! strcmp ( V_4 , L_56 ) ||
! strcmp ( V_4 , L_57 ) ) ) {
return F_26 ( L_55 V_83 L_55 , F_38 () , V_4 ) ;
} else {
return F_26 ( L_55 V_83 L_55 , F_39 () , V_4 ) ;
}
}
char *
F_93 ( void )
{
return F_89 ( V_136 , FALSE ) ;
}
const char *
F_94 ( int V_137 , T_11 V_138 )
{
const char * V_139 ;
static char V_140 [ 1024 + 1 ] ;
switch ( V_137 ) {
case V_117 :
if ( V_138 )
V_139 = L_58 ;
else
V_139 = L_59 ;
break;
case V_141 :
if ( V_138 )
V_139 = L_60 ;
else
V_139 = L_61 ;
break;
case V_8 :
V_139 = L_62 ;
break;
case V_142 :
V_139 = L_63 ;
break;
#ifdef F_95
case F_95 :
V_139 = L_64 ;
break;
#endif
case V_143 :
V_139 = L_65 ;
break;
case V_24 :
#if V_144 == 4
#define F_96 "it can't be handled by a 32-bit application"
#else
#if F_12 ( F_2 )
#define F_96 "the pagefile is too small"
#elif F_12 ( V_10 )
#define F_96 "your system ran out of swap file space"
#else
#define F_96 "your system is out of swap space"
#endif
#endif
if ( V_138 )
V_139 = L_66 F_96 L_13 ;
else
V_139 = L_67 F_96 L_13 ;
break;
default:
F_97 ( V_140 , sizeof( V_140 ) ,
L_68 ,
V_138 ? L_69 : L_70 ,
F_33 ( V_137 ) ) ;
V_139 = V_140 ;
break;
}
return V_139 ;
}
const char *
F_98 ( int V_137 )
{
const char * V_139 ;
static char V_140 [ 1024 + 1 ] ;
switch ( V_137 ) {
case V_142 :
V_139 = L_71 ;
break;
#ifdef F_95
case F_95 :
V_139 = L_72 ;
break;
#endif
default:
F_97 ( V_140 , sizeof( V_140 ) ,
L_73 ,
F_33 ( V_137 ) ) ;
V_139 = V_140 ;
break;
}
return V_139 ;
}
T_11
F_80 ( const char * V_145 )
{
T_1 V_146 ;
if ( ! V_145 ) {
return FALSE ;
}
#if F_12 ( V_147 ) && V_147 < 1900
V_146 . V_148 = 1 ;
F_7 ( V_145 , & V_146 ) ;
if ( V_146 . V_148 == 0 ) {
return TRUE ;
} else {
return FALSE ;
}
#else
if ( F_7 ( V_145 , & V_146 ) != 0 && V_6 == V_117 ) {
return FALSE ;
} else {
return TRUE ;
}
#endif
}
T_11
F_99 ( const char * V_149 , const char * V_150 )
{
#ifdef F_2
char V_151 [ V_126 ] , V_152 [ V_126 ] ;
if( F_100 ( V_151 , V_149 , V_126 ) == NULL ) {
return FALSE ;
}
if( F_100 ( V_152 , V_150 , V_126 ) == NULL ) {
return FALSE ;
}
if( strcmp ( V_151 , V_152 ) == 0 ) {
return TRUE ;
} else {
return FALSE ;
}
#else
T_1 V_153 , V_154 ;
if ( F_7 ( V_149 , & V_153 ) == - 1 )
return FALSE ;
if ( F_7 ( V_150 , & V_154 ) == - 1 )
return FALSE ;
return ( V_153 . V_155 == V_154 . V_155 &&
V_153 . V_148 == V_154 . V_148 ) ;
#endif
}
T_11
F_81 ( const char * V_156 , const char * V_157 )
{
int V_158 , V_159 , V_137 ;
T_3 V_160 , V_161 ;
T_16 * V_162 = NULL ;
V_158 = F_101 ( V_156 , V_163 | V_164 , 0000 ) ;
if ( V_158 < 0 ) {
F_102 ( V_156 , V_6 , FALSE ) ;
goto V_165;
}
V_159 = F_101 ( V_157 , V_166 | V_167 | V_168 | V_164 , 0644 ) ;
if ( V_159 < 0 ) {
F_102 ( V_157 , V_6 , TRUE ) ;
F_103 ( V_158 ) ;
goto V_165;
}
#define F_104 65536
V_162 = ( T_16 * ) F_13 ( F_104 ) ;
while ( ( V_160 = F_105 ( V_158 , V_162 , F_104 ) ) > 0 ) {
V_161 = F_106 ( V_159 , V_162 , V_160 ) ;
if ( V_161 < V_160 ) {
if ( V_161 < 0 )
V_137 = V_6 ;
else
V_137 = V_169 ;
F_107 ( V_157 , V_137 ) ;
F_103 ( V_158 ) ;
F_103 ( V_159 ) ;
goto V_165;
}
}
if ( V_160 < 0 ) {
V_137 = V_6 ;
F_108 ( V_156 , V_137 ) ;
F_103 ( V_158 ) ;
F_103 ( V_159 ) ;
goto V_165;
}
F_103 ( V_158 ) ;
if ( F_103 ( V_159 ) < 0 ) {
F_107 ( V_157 , V_6 ) ;
goto V_165;
}
F_35 ( V_162 ) ;
V_162 = NULL ;
return TRUE ;
V_165:
F_35 ( V_162 ) ;
return FALSE ;
}
