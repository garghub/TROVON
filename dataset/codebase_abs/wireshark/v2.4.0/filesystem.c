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
#ifdef F_22
V_31 = F_22 ;
#else
V_31 = V_33 ;
#endif
return V_31 ;
} else {
if ( F_23 ( L_10 ) && ! F_24 () ) {
V_31 = F_25 ( F_23 ( L_10 ) ) ;
}
#ifdef V_10
else if ( V_34 != NULL ) {
V_31 = F_26 ( L_11 ,
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
F_27 ( void )
{
#ifdef F_2
V_36 = F_28 ( F_21 () , L_12 , V_37 , ( V_38 * ) NULL ) ;
if ( F_6 ( V_36 ) != V_8 ) {
F_29 ( V_36 ) ;
V_36 = F_28 ( F_21 () , L_12 , ( V_38 * ) NULL ) ;
V_32 = TRUE ;
}
#else
if ( V_32 ) {
V_36 = F_28 ( F_20 () , L_12 , ( V_38 * ) NULL ) ;
} else {
if ( F_23 ( L_13 ) && ! F_24 () ) {
V_36 = F_25 ( F_23 ( L_13 ) ) ;
}
#ifdef V_10
else if ( V_34 != NULL ) {
V_36 = F_28 ( V_34 , L_14 , ( V_38 * ) NULL ) ;
}
#endif
else {
V_36 = F_25 ( V_39 ) ;
}
}
#endif
}
const char *
F_30 ( void )
{
#if F_12 ( V_40 ) || F_12 ( V_41 )
if ( ! V_36 ) F_27 () ;
return V_36 ;
#else
return NULL ;
#endif
}
static void F_31 ( void ) {
#ifdef F_2
const char * V_42 ;
V_42 = F_23 ( L_15 ) ;
if ( V_42 ) {
V_43 = F_25 ( V_42 ) ;
} else {
V_43 = F_28 ( F_21 () , L_16 , ( V_38 * ) NULL ) ;
}
#else
if ( V_32 ) {
V_43 = F_28 ( F_20 () , L_16 , ( V_38 * ) NULL ) ;
} else {
if ( F_23 ( L_15 ) && ! F_24 () ) {
V_43 = F_25 ( F_23 ( L_15 ) ) ;
}
#ifdef V_10
else if ( V_34 != NULL ) {
V_43 = F_28 ( V_34 , L_17 , ( V_38 * ) NULL ) ;
}
#endif
else {
V_43 = F_25 ( V_44 ) ;
}
}
#endif
}
const char *
F_32 ( void ) {
#if F_12 ( V_45 )
if ( ! V_43 )
F_31 () ;
return V_43 ;
#else
return NULL ;
#endif
}
T_5
F_33 ( void )
{
return V_32 ;
}
const char *
F_34 ( void )
{
#ifdef F_2
return F_21 () ;
#else
return L_18 ;
#endif
}
void
F_35 ( const V_38 * V_46 )
{
F_29 ( V_47 ) ;
if ( V_46 && strlen ( V_46 ) > 0 &&
strcmp ( V_46 , V_48 ) != 0 ) {
V_47 = F_25 ( V_46 ) ;
} else {
V_47 = NULL ;
}
}
const char *
F_36 ( void )
{
if ( V_47 ) {
return V_47 ;
} else {
return V_48 ;
}
}
T_5
F_37 ( void )
{
return ( ! V_47 || strcmp ( V_47 , V_48 ) == 0 ) ? TRUE : FALSE ;
}
T_5
F_38 ( void )
{
T_6 * V_49 ;
T_7 * V_50 ;
V_38 * V_51 = F_39 () ;
V_38 * V_4 ;
T_5 V_52 = FALSE ;
if ( ( F_6 ( V_51 ) == V_8 ) &&
( ( V_49 = F_40 ( V_51 , 0 , NULL ) ) != NULL ) )
{
while ( ( V_50 = F_41 ( V_49 ) ) != NULL ) {
V_4 = F_26 ( L_19 , V_51 , V_53 ,
F_42 ( V_50 ) ) ;
if ( F_6 ( V_4 ) == V_8 ) {
V_52 = TRUE ;
F_29 ( V_4 ) ;
break;
}
F_29 ( V_4 ) ;
}
F_43 ( V_49 ) ;
}
F_29 ( V_51 ) ;
return V_52 ;
}
void
F_44 ( T_5 V_54 )
{
if ( V_54 ) {
V_55 = F_45 ( V_56 , V_57 ) ;
}
V_58 = V_54 ;
}
static const char *
F_46 ( void )
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
V_59 = F_23 ( L_20 ) ;
if ( V_59 != NULL ) {
V_64 = F_25 ( V_59 ) ;
return V_64 ;
}
V_59 = F_23 ( L_21 ) ;
if ( V_59 != NULL ) {
V_64 = F_28 ( V_59 , L_22 , NULL ) ;
return V_64 ;
}
V_59 = F_23 ( L_23 ) ;
if ( V_59 != NULL ) {
V_64 = F_28 ( V_59 , L_24 , L_22 , NULL ) ;
return V_64 ;
}
V_64 = F_28 ( L_25 , L_22 , NULL ) ;
return V_64 ;
#else
V_60 = F_28 ( F_47 () , L_26 , NULL ) ;
if ( F_48 ( V_60 , V_65 ) ) {
V_64 = V_60 ;
return V_64 ;
}
V_63 = F_23 ( L_27 ) ;
if ( V_63 == NULL ) {
V_62 = F_49 ( F_50 () ) ;
if ( V_62 != NULL ) {
V_63 = V_62 -> V_66 ;
} else {
V_63 = L_28 ;
}
}
V_1 = F_28 ( V_63 , L_29 , NULL ) ;
if ( F_48 ( V_1 , V_65 ) ) {
F_29 ( V_60 ) ;
V_64 = V_1 ;
return V_64 ;
}
F_29 ( V_1 ) ;
V_64 = V_60 ;
return V_64 ;
#endif
}
void
F_51 ( const char * V_67 )
{
F_29 ( V_64 ) ;
V_64 = F_25 ( V_67 ) ;
}
char *
F_52 ( void )
{
return F_26 ( L_19 , F_46 () ,
V_53 , V_68 ) ;
}
int
F_53 ( char * * V_69 )
{
char * V_70 ;
T_1 V_71 ;
if ( F_54 ( NULL , V_69 ) == - 1 ) {
return - 1 ;
}
V_70 = F_52 () ;
if ( F_7 ( V_70 , & V_71 ) != 0 ) {
if ( V_6 != V_72 ) {
* V_69 = V_70 ;
return - 1 ;
}
int V_73 = F_55 ( V_70 , 0755 ) ;
if ( V_73 == - 1 ) {
* V_69 = V_70 ;
return V_73 ;
}
}
F_29 ( V_70 ) ;
return 0 ;
}
char *
F_39 ( void )
{
return F_26 ( L_19 , F_21 () ,
V_53 , V_68 ) ;
}
static char *
F_56 ( const V_38 * V_46 )
{
char * V_74 = NULL , * V_75 ;
if ( V_46 && strlen ( V_46 ) > 0 &&
strcmp ( V_46 , V_48 ) != 0 ) {
V_75 = F_52 () ;
V_74 = F_26 ( L_19 , V_75 ,
V_53 , V_46 ) ;
F_29 ( V_75 ) ;
} else {
V_74 = F_25 ( F_46 () ) ;
}
return V_74 ;
}
T_5
F_57 ( const V_38 * V_46 , T_5 V_76 )
{
V_38 * V_1 = NULL , * V_77 ;
if ( V_76 ) {
V_77 = F_39 () ;
V_1 = F_26 ( L_19 , V_77 ,
V_53 , V_46 ) ;
F_29 ( V_77 ) ;
if ( F_6 ( V_1 ) == V_8 ) {
F_29 ( V_1 ) ;
return TRUE ;
}
} else {
V_1 = F_56 ( V_46 ) ;
if ( F_6 ( V_1 ) == V_8 ) {
F_29 ( V_1 ) ;
return TRUE ;
}
}
F_29 ( V_1 ) ;
return FALSE ;
}
static int
F_58 ( const char * V_78 , char * * V_69 )
{
T_6 * V_49 ;
T_7 * V_50 ;
V_38 * V_4 ;
int V_73 = 0 ;
if ( ( V_49 = F_40 ( V_78 , 0 , NULL ) ) != NULL ) {
while ( ( V_50 = F_41 ( V_49 ) ) != NULL ) {
V_4 = F_26 ( L_19 , V_78 , V_53 ,
F_42 ( V_50 ) ) ;
if ( F_6 ( V_4 ) != V_8 ) {
V_73 = F_59 ( V_4 ) ;
#if 0
} else {
ret = delete_directory (filename, pf_dir_path_return);
#endif
}
if ( V_73 != 0 ) {
* V_69 = V_4 ;
break;
}
F_29 ( V_4 ) ;
}
F_43 ( V_49 ) ;
}
if ( V_73 == 0 && ( V_73 = F_59 ( V_78 ) ) != 0 ) {
* V_69 = F_25 ( V_78 ) ;
}
return V_73 ;
}
static int
F_60 ( char * * V_69 )
{
char * V_75 = F_56 ( NULL ) ;
V_38 * V_4 , * V_79 ;
T_8 * V_80 , * V_50 ;
int V_73 = 0 ;
V_80 = F_61 ( V_55 ) ;
V_50 = F_62 ( V_80 ) ;
while ( V_50 ) {
V_4 = ( V_38 * ) V_50 -> V_81 ;
V_79 = F_26 ( L_19 , V_75 , V_53 , V_4 ) ;
if ( F_63 ( V_79 ) ) {
V_73 = F_59 ( V_79 ) ;
if ( V_73 != 0 ) {
* V_69 = V_75 ;
F_29 ( V_79 ) ;
return V_73 ;
}
}
F_29 ( V_79 ) ;
V_50 = F_64 ( V_50 ) ;
}
F_65 ( V_80 ) ;
F_29 ( V_75 ) ;
return 0 ;
}
int
F_66 ( const char * V_46 , char * * V_69 )
{
if ( strcmp ( V_46 , V_48 ) == 0 ) {
return F_60 ( V_69 ) ;
}
char * V_75 = F_56 ( V_46 ) ;
int V_73 = 0 ;
if ( F_6 ( V_75 ) == V_8 ) {
V_73 = F_58 ( V_75 , V_69 ) ;
}
F_29 ( V_75 ) ;
return V_73 ;
}
int
F_67 ( const char * V_82 , const char * V_83 ,
char * * V_84 , char * * V_85 )
{
char * V_86 = F_56 ( V_82 ) ;
char * V_87 = F_56 ( V_83 ) ;
int V_73 = 0 ;
V_73 = F_68 ( V_86 , V_87 ) ;
if ( V_73 != 0 ) {
* V_84 = V_86 ;
* V_85 = V_87 ;
return V_73 ;
}
F_29 ( V_86 ) ;
F_29 ( V_87 ) ;
return 0 ;
}
int
F_54 ( const char * V_46 , char * * V_69 )
{
char * V_70 ;
#ifdef F_2
char * V_88 , * V_89 ;
T_4 V_90 ;
int V_91 ;
#endif
T_1 V_71 ;
int V_73 ;
if ( V_46 ) {
if ( F_53 ( V_69 ) == - 1 ) {
return - 1 ;
}
}
V_70 = F_56 ( V_46 ) ;
if ( F_7 ( V_70 , & V_71 ) != 0 ) {
if ( V_6 != V_72 ) {
* V_69 = V_70 ;
return - 1 ;
}
#ifdef F_2
V_88 = F_25 ( V_70 ) ;
V_89 = F_5 ( V_88 ) ;
V_90 = strlen ( V_89 ) ;
if ( V_90 > 0
&& V_89 [ V_90 - 1 ] != ':'
&& F_7 ( V_89 , & V_71 ) != 0 ) {
if ( V_6 != V_72 ) {
* V_69 = V_70 ;
V_91 = V_6 ;
F_29 ( V_88 ) ;
V_6 = V_91 ;
return - 1 ;
}
V_73 = F_55 ( V_89 , 0755 ) ;
if ( V_73 == - 1 ) {
* V_69 = V_89 ;
V_91 = V_6 ;
F_29 ( V_70 ) ;
V_6 = V_91 ;
return - 1 ;
}
}
F_29 ( V_88 ) ;
V_73 = F_55 ( V_70 , 0755 ) ;
#else
V_73 = F_69 ( V_70 , 0755 ) ;
#endif
} else {
V_73 = 0 ;
}
if ( V_73 == - 1 )
* V_69 = V_70 ;
else
F_29 ( V_70 ) ;
return V_73 ;
}
int
F_70 ( char * * V_69 )
{
return F_54 ( V_47 , V_69 ) ;
}
int
F_71 ( const char * V_83 , const char * V_82 , T_5 V_92 ,
char * * V_93 , char * * V_85 , char * * V_84 )
{
V_38 * V_86 ;
V_38 * V_87 = F_56 ( V_83 ) ;
V_38 * V_4 , * V_94 , * V_95 , * V_77 ;
T_8 * V_80 , * V_50 ;
if ( V_92 ) {
if ( strcmp ( V_82 , V_48 ) == 0 ) {
V_86 = F_39 () ;
} else {
V_77 = F_39 () ;
V_86 = F_26 ( L_19 , V_77 , V_53 , V_82 ) ;
F_29 ( V_77 ) ;
}
} else {
V_86 = F_56 ( V_82 ) ;
}
V_80 = F_61 ( V_55 ) ;
V_50 = F_62 ( V_80 ) ;
while ( V_50 ) {
V_4 = ( V_38 * ) V_50 -> V_81 ;
V_94 = F_26 ( L_19 , V_86 , V_53 , V_4 ) ;
V_95 = F_26 ( L_19 , V_87 , V_53 , V_4 ) ;
if ( F_63 ( V_94 ) && ! F_72 ( V_94 , V_95 ) ) {
* V_93 = F_25 ( V_4 ) ;
* V_85 = V_87 ;
* V_84 = V_86 ;
F_29 ( V_94 ) ;
F_29 ( V_95 ) ;
return - 1 ;
}
F_29 ( V_94 ) ;
F_29 ( V_95 ) ;
V_50 = F_64 ( V_50 ) ;
}
F_65 ( V_80 ) ;
F_29 ( V_86 ) ;
F_29 ( V_87 ) ;
return 0 ;
}
extern const char *
F_73 ( void )
{
#ifdef F_2
T_9 V_96 [ V_97 ] ;
if ( V_98 != NULL )
return V_98 ;
if ( F_74 ( NULL , V_96 , V_99 , FALSE ) ) {
V_98 = F_75 ( V_96 , - 1 , NULL , NULL , NULL ) ;
return V_98 ;
} else {
return L_30 ;
}
#else
return L_30 ;
#endif
}
void
F_76 ( const char * V_67 )
{
F_29 ( V_98 ) ;
V_98 = F_25 ( V_67 ) ;
}
static const char *
F_77 ( void )
{
static const char * V_100 = NULL ;
const char * V_101 , * V_102 ;
char * V_103 ;
char * V_104 ;
if ( V_100 )
return V_100 ;
V_101 = F_23 ( L_31 ) ;
if ( V_101 != NULL ) {
V_102 = F_23 ( L_32 ) ;
if ( V_102 != NULL ) {
V_103 = F_26 ( L_33 , V_101 , V_102 ) ;
V_104 = F_1 ( V_103 ) ;
if ( V_104 != NULL && * ( V_104 + 1 ) == '\0' ) {
* V_104 = '\0' ;
}
V_100 = V_103 ;
} else
V_100 = V_101 ;
} else {
V_100 = L_25 ;
}
return V_100 ;
}
char *
F_78 ( const char * V_4 , T_5 V_105 )
{
char * V_1 , * V_49 = NULL ;
if ( V_58 && V_105 && ! F_79 ( V_55 , V_4 ) ) {
F_80 ( V_55 , F_25 ( V_4 ) , F_25 ( V_4 ) ) ;
}
if ( V_105 ) {
V_49 = F_56 ( V_47 ) ;
V_1 = F_26 ( L_34 V_53 L_34 ,
V_49 , V_4 ) ;
} else {
V_49 = F_56 ( NULL ) ;
V_1 = F_26 ( L_34 V_53 L_34 ,
V_49 , V_4 ) ;
}
F_29 ( V_49 ) ;
return V_1 ;
}
char *
F_81 ( const char * V_4 )
{
if ( V_32 &&
( ! strcmp ( V_4 , L_35 ) ||
! strcmp ( V_4 , L_36 ) ) ) {
return F_26 ( L_34 V_53 L_34 , F_20 () , V_4 ) ;
} else {
return F_26 ( L_34 V_53 L_34 , F_21 () , V_4 ) ;
}
}
char *
F_82 ( void )
{
return F_78 ( V_106 , FALSE ) ;
}
const char *
F_83 ( int V_107 , T_5 V_108 )
{
const char * V_109 ;
static char V_110 [ 1024 + 1 ] ;
switch ( V_107 ) {
case V_72 :
if ( V_108 )
V_109 = L_37 ;
else
V_109 = L_38 ;
break;
case V_111 :
if ( V_108 )
V_109 = L_39 ;
else
V_109 = L_40 ;
break;
case V_8 :
V_109 = L_41 ;
break;
case V_112 :
V_109 = L_42 ;
break;
#ifdef F_84
case F_84 :
V_109 = L_43 ;
break;
#endif
case V_113 :
V_109 = L_44 ;
break;
#ifdef F_85
case F_85 :
V_109 = L_45 V_114 L_46 ;
break;
#endif
case V_24 :
#if V_115 == 4
#define F_86 "it can't be handled by a 32-bit application"
#else
#if F_12 ( F_2 )
#define F_86 "the pagefile is too small"
#elif F_12 ( V_10 )
#define F_86 "your system ran out of swap file space"
#else
#define F_86 "your system is out of swap space"
#endif
#endif
if ( V_108 )
V_109 = L_47 F_86 L_48 ;
else
V_109 = L_49 F_86 L_48 ;
break;
default:
F_87 ( V_110 , sizeof( V_110 ) ,
L_50 ,
V_108 ? L_51 : L_52 ,
F_88 ( V_107 ) ) ;
V_109 = V_110 ;
break;
}
return V_109 ;
}
const char *
F_89 ( int V_107 )
{
const char * V_109 ;
static char V_110 [ 1024 + 1 ] ;
switch ( V_107 ) {
case V_112 :
V_109 = L_53 ;
break;
#ifdef F_84
case F_84 :
V_109 = L_54 ;
break;
#endif
default:
F_87 ( V_110 , sizeof( V_110 ) ,
L_55 ,
F_88 ( V_107 ) ) ;
V_109 = V_110 ;
break;
}
return V_109 ;
}
T_5
F_63 ( const char * V_116 )
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
if ( F_7 ( V_116 , & V_117 ) != 0 && V_6 == V_72 ) {
return FALSE ;
} else {
return TRUE ;
}
#endif
}
T_5
F_90 ( const char * V_120 , const char * V_121 )
{
#ifdef F_2
char V_122 [ V_97 ] , V_123 [ V_97 ] ;
if( F_91 ( V_122 , V_120 , V_97 ) == NULL ) {
return FALSE ;
}
if( F_91 ( V_123 , V_121 , V_97 ) == NULL ) {
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
F_72 ( const char * V_127 , const char * V_128 )
{
int V_129 , V_130 , V_107 ;
T_3 V_131 , V_132 ;
T_10 * V_133 = NULL ;
V_129 = F_92 ( V_127 , V_134 | V_135 , 0000 ) ;
if ( V_129 < 0 ) {
F_93 ( V_127 , V_6 , FALSE ) ;
goto V_136;
}
V_130 = F_92 ( V_128 , V_137 | V_138 | V_139 | V_135 , 0644 ) ;
if ( V_130 < 0 ) {
F_93 ( V_128 , V_6 , TRUE ) ;
F_94 ( V_129 ) ;
goto V_136;
}
#define F_95 65536
V_133 = ( T_10 * ) F_13 ( F_95 ) ;
while ( ( V_131 = F_96 ( V_129 , V_133 , F_95 ) ) > 0 ) {
V_132 = F_97 ( V_130 , V_133 , V_131 ) ;
if ( V_132 < V_131 ) {
if ( V_132 < 0 )
V_107 = V_6 ;
else
V_107 = V_140 ;
F_98 ( V_128 , V_107 ) ;
F_94 ( V_129 ) ;
F_94 ( V_130 ) ;
goto V_136;
}
}
if ( V_131 < 0 ) {
V_107 = V_6 ;
F_99 ( V_127 , V_107 ) ;
F_94 ( V_129 ) ;
F_94 ( V_130 ) ;
goto V_136;
}
F_94 ( V_129 ) ;
if ( F_94 ( V_130 ) < 0 ) {
F_98 ( V_128 , V_6 ) ;
goto V_136;
}
F_29 ( V_133 ) ;
V_133 = NULL ;
return TRUE ;
V_136:
F_29 ( V_133 ) ;
return FALSE ;
}
V_38 *
F_100 ( const V_38 * V_4 )
{
V_38 * V_141 ;
V_38 * V_142 ;
if( F_101 ( V_4 ) ) {
V_141 = F_25 ( V_4 ) ;
} else if( F_33 () ) {
V_141 = F_26 ( L_56 , F_21 () , V_4 ) ;
} else {
V_141 = F_26 ( L_57 , F_21 () , V_4 ) ;
}
V_142 = F_102 ( V_141 , NULL , NULL ) ;
F_29 ( V_141 ) ;
return V_142 ;
}
void
F_103 ( void )
{
F_29 ( V_64 ) ;
V_64 = NULL ;
F_29 ( V_98 ) ;
V_98 = NULL ;
F_29 ( V_47 ) ;
V_47 = NULL ;
F_29 ( V_30 ) ;
V_30 = NULL ;
#if F_12 ( V_40 ) || F_12 ( V_41 )
F_29 ( V_36 ) ;
V_36 = NULL ;
#endif
#ifdef V_45
F_29 ( V_43 ) ;
V_43 = NULL ;
#endif
}
