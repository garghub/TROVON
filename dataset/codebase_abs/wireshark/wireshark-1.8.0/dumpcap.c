static T_1
F_1 ( void ) {
T_1 V_1 ;
#ifdef F_2
T_2 V_2 ;
#else
struct V_3 V_2 ;
#endif
#ifdef F_2
F_3 ( & V_2 ) ;
V_1 = ( ( ( T_1 ) ( V_4 ) V_2 . V_5 ) << 32 ) +
( V_4 ) V_2 . V_6 ;
V_1 /= 10 ;
V_1 -= F_4 ( 11644473600000000U ) ;
#else
F_5 ( & V_2 , NULL ) ;
V_1 = ( T_1 ) ( V_2 . V_7 ) * 1000000 +
( T_1 ) ( V_2 . V_8 ) ;
#endif
return V_1 ;
}
static void
F_6 ( T_3 V_9 )
{
T_4 * V_10 ;
if ( V_9 ) {
V_10 = stdout ;
fprintf ( V_10 ,
L_1 V_11 L_2
L_3
L_4 ,
V_12 ) ;
} else {
V_10 = V_13 ;
}
fprintf ( V_10 , L_5 ) ;
fprintf ( V_10 , L_6 ) ;
fprintf ( V_10 , L_7 ) ;
fprintf ( V_10 , L_8 ) ;
fprintf ( V_10 , L_9 ) ;
fprintf ( V_10 , L_10 ) ;
fprintf ( V_10 , L_11 ) ;
#ifdef F_7
fprintf ( V_10 , L_12 ) ;
#endif
#if F_8 ( F_2 ) || F_8 ( F_7 )
fprintf ( V_10 , L_13 ) ;
#endif
fprintf ( V_10 , L_14 ) ;
fprintf ( V_10 , L_15 ) ;
fprintf ( V_10 , L_16 ) ;
#ifdef F_9
fprintf ( V_10 , L_17 ) ;
#endif
fprintf ( V_10 , L_18 ) ;
fprintf ( V_10 , L_19 ) ;
fprintf ( V_10 , L_6 ) ;
#ifdef F_10
fprintf ( V_10 , L_20 ) ;
fprintf ( V_10 , L_21 ) ;
fprintf ( V_10 , L_22 ) ;
fprintf ( V_10 , L_23 ) ;
#ifdef F_11
fprintf ( V_10 , L_24 ) ;
fprintf ( V_10 , L_25 ) ;
fprintf ( V_10 , L_26 ) ;
#endif
#endif
fprintf ( V_10 , L_27 ) ;
fprintf ( V_10 , L_28 ) ;
fprintf ( V_10 , L_29 ) ;
fprintf ( V_10 , L_30 ) ;
fprintf ( V_10 , L_31 ) ;
fprintf ( V_10 , L_32 ) ;
fprintf ( V_10 , L_33 ) ;
fprintf ( V_10 , L_34 ) ;
fprintf ( V_10 , L_35 ) ;
fprintf ( V_10 , L_36 ) ;
fprintf ( V_10 , L_37 ) ;
fprintf ( V_10 , L_38 ) ;
fprintf ( V_10 , L_39 ) ;
fprintf ( V_10 , L_6 ) ;
fprintf ( V_10 , L_40 ) ;
fprintf ( V_10 , L_41 ) ;
fprintf ( V_10 , L_42 ) ;
fprintf ( V_10 , L_43 ) ;
fprintf ( V_10 , L_44 ) ;
fprintf ( V_10 , L_6 ) ;
fprintf ( V_10 , L_45 ) ;
fprintf ( V_10 , L_46 ) ;
fprintf ( V_10 , L_6 ) ;
fprintf ( V_10 , L_47 ) ;
}
static void
F_12 ( T_5 * V_14 , T_5 * V_15 )
{
printf (
L_1 V_11 L_2
L_6
L_2
L_2
L_2
L_4 ,
V_12 , F_13 () , V_14 -> V_16 , V_15 -> V_16 ) ;
}
void
F_14 ( const char * V_17 , T_6 V_18 )
{
vfprintf ( V_13 , V_17 , V_18 ) ;
}
void
F_15 ( const char * V_17 , ... )
{
T_6 V_18 ;
va_start ( V_18 , V_17 ) ;
F_14 ( V_17 , V_18 ) ;
va_end ( V_18 ) ;
}
void
F_16 ( const char * V_17 , ... )
{
T_6 V_18 ;
if( V_19 ) {
T_7 * V_20 ;
va_start ( V_18 , V_17 ) ;
V_20 = F_17 ( V_17 , V_18 ) ;
F_18 ( 2 , V_20 , L_48 ) ;
F_19 ( V_20 ) ;
va_end ( V_18 ) ;
} else {
va_start ( V_18 , V_17 ) ;
fprintf ( V_13 , L_49 ) ;
vfprintf ( V_13 , V_17 , V_18 ) ;
fprintf ( V_13 , L_6 ) ;
va_end ( V_18 ) ;
}
}
void
F_20 ( const char * V_17 , ... )
{
T_6 V_18 ;
if( V_19 ) {
T_7 * V_20 ;
va_start ( V_18 , V_17 ) ;
V_20 = F_17 ( V_17 , V_18 ) ;
F_18 ( 2 , V_20 , L_48 ) ;
F_19 ( V_20 ) ;
va_end ( V_18 ) ;
} else {
va_start ( V_18 , V_17 ) ;
vfprintf ( V_13 , V_17 , V_18 ) ;
fprintf ( V_13 , L_6 ) ;
va_end ( V_18 ) ;
}
}
static void
#if 0
print_caps(const char *pfx) {
cap_t caps = cap_get_proc();
g_log(LOG_DOMAIN_CAPTURE_CHILD, G_LOG_LEVEL_DEBUG,
"%s: EUID: %d Capabilities: %s", pfx,
geteuid(), cap_to_text(caps, NULL));
cap_free(caps);
#else
F_21 ( const char * T_8 V_21 ) {
#endif
}
static void
F_22 ( void )
{
T_9 V_22 = F_23 () ;
F_21 ( L_50 ) ;
if ( F_24 ( V_22 ) ) {
F_16 ( L_51 , F_25 ( V_23 ) ) ;
}
F_21 ( L_52 ) ;
F_26 ( V_22 ) ;
}
static void
F_27 ( const char * V_24 ,
const char * T_10
#ifndef F_2
V_21
#endif
,
char * V_25 , T_11 V_26 ,
char * V_27 ,
T_11 V_28 )
{
#ifndef F_2
const char * V_29 ;
static const char V_30 [] = L_53 ;
#endif
F_28 ( V_25 , ( V_31 ) V_26 ,
L_54 , V_24 ) ;
#ifdef F_2
if ( ! V_32 ) {
F_28 ( V_27 , ( V_31 ) V_28 ,
L_6
L_55
L_6
L_56
L_6
L_57
L_6
L_58
L_6
L_57
L_6
L_59
L_6
L_60
L_61 ) ;
} else {
F_28 ( V_27 , ( V_31 ) V_28 ,
L_6
L_62
L_6
L_6
L_63
L_6
L_64
L_65 ,
T_10 ) ;
}
#else
if ( strncmp ( V_24 , V_30 , sizeof V_30 - 1 ) == 0 )
V_29 =
L_66
L_67
L_68
L_69
L_6
L_70
L_71
L_72
L_73
L_74 ;
else
V_29 = L_48 ;
F_28 ( V_27 , ( V_31 ) V_28 ,
L_75
L_76 , V_29 ) ;
#endif
}
static T_3
F_29 ( T_12 * V_33 , int V_34 ,
#ifdef F_30
char * T_13 V_21 ,
#else
char * T_13 ,
#endif
char * V_25 , T_11 V_26 ,
char * V_27 , T_11 V_28 )
{
char * V_35 ;
if ( V_34 == - 1 )
return TRUE ;
#ifdef F_30
if ( F_31 ( V_33 , V_34 ) == 0 )
return TRUE ;
V_35 = F_32 ( V_33 ) ;
#else
if ( F_33 ( V_33 , T_13 ) == V_34 )
return TRUE ;
V_35 =
L_77 ;
#endif
F_28 ( V_25 , ( V_31 ) V_26 , L_78 ,
V_35 ) ;
if ( strstr ( V_35 , L_79 ) == NULL )
F_28 ( V_27 , ( V_31 ) V_28 , V_36 ) ;
else
V_27 [ 0 ] = '\0' ;
return FALSE ;
}
static T_3
F_34 ( const char * T_10 , T_12 * V_33 ,
struct V_37 * V_38 , const char * V_39 )
{
T_14 V_40 , V_41 ;
T_7 V_42 [ V_43 ] ;
if ( F_35 ( T_10 , & V_40 , & V_41 , V_42 ) < 0 ) {
V_41 = 0 ;
}
if ( F_36 ( V_33 , V_38 , ( char * ) V_39 , 1 , V_41 ) < 0 )
return FALSE ;
return TRUE ;
}
static T_3
F_37 ( T_15 * V_44 )
{
T_16 V_45 ;
T_12 * V_33 ;
T_7 V_24 [ V_43 ] ;
char V_25 [ V_46 + 1 ] ;
char V_27 [ V_46 + 1 ] ;
struct V_37 V_38 ;
struct V_47 * V_48 ;
T_17 V_49 ;
T_18 V_50 ;
for ( V_50 = 0 ; V_50 < V_44 -> V_51 -> V_52 ; V_50 ++ ) {
V_45 = F_38 ( V_44 -> V_51 , T_16 , V_50 ) ;
V_33 = F_39 ( & V_45 , & V_24 ) ;
if ( V_33 == NULL ) {
F_27 ( V_24 ,
V_45 . T_13 ,
V_25 , sizeof V_25 ,
V_27 ,
sizeof V_27 ) ;
F_40 ( V_25 , V_27 ) ;
return FALSE ;
}
if ( ! F_29 ( V_33 , V_45 . V_34 , V_45 . T_13 ,
V_25 , sizeof V_25 ,
V_27 , sizeof V_27 ) ) {
F_41 ( V_33 ) ;
F_40 ( V_25 , V_27 ) ;
return FALSE ;
}
if ( ! F_34 ( V_45 . T_13 , V_33 , & V_38 ,
V_45 . V_39 ) ) {
F_41 ( V_33 ) ;
F_42 ( V_44 , V_50 , V_25 ) ;
return FALSE ;
}
F_41 ( V_33 ) ;
V_48 = V_38 . V_53 ;
for ( V_49 = 0 ; V_49 < V_38 . V_54 ; V_48 ++ , V_49 ++ )
printf ( L_2 , F_43 ( V_48 , V_49 ) ) ;
}
#ifndef F_44
F_45 () ;
#else
F_22 () ;
#endif
if ( V_19 ) {
F_46 ( 2 , V_55 , NULL ) ;
}
return TRUE ;
}
T_19 *
F_47 ( int * V_56 , char * * V_57 )
{
return F_48 ( V_56 , V_57 ) ;
}
static int
F_33 ( T_12 * V_58 , const char * T_20
#ifndef F_49
V_21
#endif
)
{
int V_34 ;
#ifdef F_49
const char * V_59 ;
#endif
V_34 = F_50 ( V_58 ) ;
#ifdef F_49
V_59 = strchr ( T_20 , '/' ) ;
if ( V_59 == NULL )
V_59 = T_20 ;
if ( strncmp ( V_59 , L_80 , 2 ) == 0 ) {
if ( V_34 == 6 ) {
V_34 = 1 ;
}
} else if ( strncmp ( V_59 , L_81 , 2 ) == 0 ) {
if ( V_34 == 7 ) {
V_34 = 1 ;
}
} else if ( strncmp ( V_59 , L_82 , 2 ) == 0 ) {
if ( V_34 == 9 ) {
V_34 = 6 ;
}
} else if ( strncmp ( V_59 , L_83 , 2 ) == 0 ) {
if ( V_34 == 15 ) {
V_34 = 10 ;
}
} else if ( strncmp ( V_59 , L_84 , 2 ) == 0 ) {
if ( V_34 == 24 ) {
V_34 = 0 ;
}
}
#endif
return V_34 ;
}
static T_21 *
F_51 ( int V_60 )
{
T_21 * V_61 ;
const char * V_62 ;
V_61 = ( T_21 * ) F_52 ( sizeof ( T_21 ) ) ;
V_61 -> V_60 = V_60 ;
V_62 = F_53 ( V_60 ) ;
if ( V_62 != NULL )
V_61 -> T_13 = F_54 ( V_62 ) ;
else
V_61 -> T_13 = F_55 ( L_85 , V_60 ) ;
V_62 = F_56 ( V_60 ) ;
if ( V_62 != NULL )
V_61 -> V_63 = F_54 ( V_62 ) ;
else
V_61 -> V_63 = NULL ;
return V_61 ;
}
static T_22 *
F_57 ( const char * T_20 , T_3 T_23
#ifndef F_7
V_21
#endif
, char * * V_57 )
{
T_22 * V_22 ;
char V_64 [ V_43 ] ;
T_12 * V_58 ;
#ifdef F_7
int V_65 ;
#endif
int V_66 ;
#ifdef F_58
int * V_67 ;
int V_49 , V_68 ;
#endif
T_21 * V_61 ;
V_22 = F_52 ( sizeof *V_22 ) ;
V_64 [ 0 ] = '\0' ;
#ifdef F_59
V_58 = F_60 ( T_20 , V_69 , 0 , 0 , NULL , V_64 ) ;
V_22 -> V_70 = FALSE ;
if ( V_58 == NULL ) {
if ( V_57 != NULL )
* V_57 = F_54 ( V_64 [ 0 ] == '\0' ? L_86 : V_64 ) ;
F_19 ( V_22 ) ;
return NULL ;
}
#elif F_8 ( F_7 )
V_58 = F_61 ( T_20 , V_64 ) ;
if ( V_58 == NULL ) {
if ( V_57 != NULL )
* V_57 = F_54 ( V_64 ) ;
F_19 ( V_22 ) ;
return NULL ;
}
V_65 = F_62 ( V_58 ) ;
if ( V_65 < 0 ) {
if ( V_65 == V_71 )
* V_57 = F_55 ( L_87 ,
F_32 ( V_58 ) ) ;
else
* V_57 = F_54 ( F_63 ( V_65 ) ) ;
F_41 ( V_58 ) ;
F_19 ( V_22 ) ;
return NULL ;
}
if ( V_65 == 0 )
V_22 -> V_70 = FALSE ;
else if ( V_65 == 1 ) {
V_22 -> V_70 = TRUE ;
if ( T_23 )
F_64 ( V_58 , 1 ) ;
} else {
if ( V_57 != NULL ) {
* V_57 = F_55 ( L_88 ,
V_65 ) ;
}
F_41 ( V_58 ) ;
F_19 ( V_22 ) ;
return NULL ;
}
V_65 = F_65 ( V_58 ) ;
if ( V_65 < 0 ) {
if ( V_57 != NULL ) {
if ( V_65 == V_71 )
* V_57 = F_55 ( L_89 ,
F_32 ( V_58 ) ) ;
else
* V_57 = F_54 ( F_63 ( V_65 ) ) ;
}
F_41 ( V_58 ) ;
F_19 ( V_22 ) ;
return NULL ;
}
#else
V_58 = F_66 ( T_20 , V_69 , 0 , 0 , V_64 ) ;
V_22 -> V_70 = FALSE ;
if ( V_58 == NULL ) {
if ( V_57 != NULL )
* V_57 = F_54 ( V_64 [ 0 ] == '\0' ? L_86 : V_64 ) ;
F_19 ( V_22 ) ;
return NULL ;
}
#endif
V_66 = F_33 ( V_58 , T_20 ) ;
#ifdef F_58
V_68 = F_67 ( V_58 , & V_67 ) ;
if ( V_68 == 0 || V_67 == NULL ) {
F_41 ( V_58 ) ;
if ( V_57 != NULL )
* V_57 = NULL ;
F_19 ( V_22 ) ;
return NULL ;
}
V_22 -> V_72 = NULL ;
for ( V_49 = 0 ; V_49 < V_68 ; V_49 ++ ) {
V_61 = F_51 ( V_67 [ V_49 ] ) ;
if ( V_67 [ V_49 ] == V_66 )
V_22 -> V_72 = F_68 ( V_22 -> V_72 ,
V_61 ) ;
else
V_22 -> V_72 = F_69 ( V_22 -> V_72 ,
V_61 ) ;
}
#ifdef F_70
F_71 ( V_67 ) ;
#else
#ifndef F_2
#define F_72 free
F_72 ( V_67 ) ;
#endif
#endif
#else
V_61 = F_51 ( V_66 ) ;
V_22 -> V_72 = F_69 ( V_22 -> V_72 ,
V_61 ) ;
#endif
F_41 ( V_58 ) ;
if ( V_57 != NULL )
* V_57 = NULL ;
return V_22 ;
}
static void
F_73 ( T_19 * V_73 )
{
int V_49 ;
T_19 * V_74 ;
T_24 * V_75 ;
T_25 * V_76 ;
T_26 * V_77 ;
char V_78 [ V_79 ] ;
if ( V_19 ) {
F_46 ( 2 , V_55 , NULL ) ;
}
V_49 = 1 ;
for ( V_74 = F_74 ( V_73 ) ; V_74 != NULL ;
V_74 = F_75 ( V_74 ) ) {
V_75 = ( T_24 * ) V_74 -> V_80 ;
printf ( L_90 , V_49 ++ , V_75 -> T_13 ) ;
if ( V_75 -> V_63 != NULL )
printf ( L_91 , V_75 -> V_63 ) ;
else
printf ( L_92 ) ;
for( V_76 = F_76 ( V_75 -> V_81 , 0 ) ; V_76 != NULL ;
V_76 = F_77 ( V_76 ) ) {
if ( V_76 != F_76 ( V_75 -> V_81 , 0 ) )
printf ( L_93 ) ;
V_77 = ( T_26 * ) V_76 -> V_80 ;
switch( V_77 -> V_82 ) {
case V_83 :
if ( F_78 ( V_84 , & V_77 -> V_76 . V_85 , V_78 ,
V_79 ) ) {
printf ( L_94 , V_78 ) ;
} else {
printf ( L_95 ) ;
}
break;
case V_86 :
if ( F_78 ( V_87 , & V_77 -> V_76 . V_88 ,
V_78 , V_79 ) ) {
printf ( L_94 , V_78 ) ;
} else {
printf ( L_96 ) ;
}
break;
default:
printf ( L_97 , V_77 -> V_82 ) ;
}
}
if ( V_75 -> V_89 )
printf ( L_98 ) ;
else
printf ( L_99 ) ;
printf ( L_6 ) ;
}
}
static void
F_79 ( T_22 * V_22 )
{
T_19 * V_90 ;
T_21 * V_61 ;
const T_7 * V_91 ;
if ( V_19 ) {
F_46 ( 2 , V_55 , NULL ) ;
}
if ( V_22 -> V_70 )
printf ( L_100 ) ;
else
printf ( L_101 ) ;
for ( V_90 = V_22 -> V_72 ; V_90 != NULL ;
V_90 = F_75 ( V_90 ) ) {
V_61 = ( T_21 * ) V_90 -> V_80 ;
if ( V_61 -> V_63 != NULL )
V_91 = V_61 -> V_63 ;
else
V_91 = L_102 ;
printf ( L_103 , V_61 -> V_60 , V_61 -> T_13 ,
V_91 ) ;
}
}
static int
F_80 ( T_3 V_92 )
{
T_19 * V_73 , * V_74 , * V_93 = NULL , * V_94 ;
T_24 * V_75 ;
T_27 * V_95 ;
int V_56 ;
T_7 * V_57 ;
T_12 * V_58 ;
char V_64 [ V_43 ] ;
struct V_96 V_97 ;
V_73 = F_48 ( & V_56 , & V_57 ) ;
if ( V_73 == NULL ) {
switch ( V_56 ) {
case V_98 :
case V_99 :
F_16 ( L_94 , V_57 ) ;
F_19 ( V_57 ) ;
break;
case V_100 :
F_16 ( L_104 ) ;
break;
}
return V_56 ;
}
for ( V_74 = F_74 ( V_73 ) ; V_74 != NULL ; V_74 = F_75 ( V_74 ) ) {
V_75 = ( T_24 * ) V_74 -> V_80 ;
#ifdef F_59
V_58 = F_60 ( V_75 -> T_13 , V_69 , 0 , 0 , NULL , V_64 ) ;
#else
V_58 = F_66 ( V_75 -> T_13 , V_69 , 0 , 0 , V_64 ) ;
#endif
if ( V_58 ) {
V_95 = ( T_27 * ) F_52 ( sizeof( T_27 ) ) ;
V_95 -> T_13 = F_54 ( V_75 -> T_13 ) ;
V_95 -> V_58 = V_58 ;
V_93 = F_69 ( V_93 , V_95 ) ;
}
}
if ( ! V_93 ) {
F_16 ( L_104 ) ;
return 2 ;
}
if ( V_19 ) {
F_46 ( 2 , V_55 , NULL ) ;
}
if ( ! V_92 ) {
printf ( L_105 , L_106 , L_107 ,
L_108 ) ;
}
V_101 . V_102 = TRUE ;
while ( V_101 . V_102 ) {
for ( V_94 = F_74 ( V_93 ) ; V_94 != NULL ; V_94 = F_75 ( V_94 ) ) {
V_95 = ( T_27 * ) V_94 -> V_80 ;
F_81 ( V_95 -> V_58 , & V_97 ) ;
if ( ! V_92 ) {
printf ( L_109 , V_95 -> T_13 ,
V_97 . V_103 , V_97 . V_104 ) ;
} else {
printf ( L_110 , V_95 -> T_13 ,
V_97 . V_103 , V_97 . V_104 ) ;
fflush ( stdout ) ;
}
}
#ifdef F_2
F_82 ( 1 * 1000 ) ;
#else
F_83 ( 1 ) ;
#endif
}
for ( V_94 = F_74 ( V_93 ) ; V_94 != NULL ; V_94 = F_75 ( V_94 ) ) {
V_95 = ( T_27 * ) V_94 -> V_80 ;
F_41 ( V_95 -> V_58 ) ;
F_19 ( V_95 -> T_13 ) ;
F_19 ( V_95 ) ;
}
F_84 ( V_93 ) ;
F_85 ( V_73 ) ;
return 0 ;
}
static BOOL T_28
F_86 ( T_29 V_105 )
{
F_87 ( V_106 , V_107 ,
L_111 ) ;
F_87 ( V_106 , V_108 ,
L_112 , V_105 ) ;
if ( V_19 || ( V_105 != V_109 ) ) {
F_88 () ;
return TRUE ;
} else {
return FALSE ;
}
}
static void
F_86 ( int T_30 V_21 )
{
F_88 () ;
}
static void
F_89 ( T_3 V_110 )
{
if ( ! V_19 && V_110 ) {
fprintf ( V_13 , L_113 , V_101 . V_111 ) ;
fflush ( V_13 ) ;
}
}
static void
F_90 ( void )
{
F_89 ( V_112 ) ;
V_113 = FALSE ;
}
static void
F_91 ( int T_30 V_21 )
{
int V_114 = V_23 ;
if ( V_115 )
V_113 = TRUE ;
else
F_90 () ;
V_23 = V_114 ;
}
static void
F_92 ( int V_65 )
{
#ifdef F_2
F_93 () ;
#ifdef F_94
printf ( L_114 ) ;
F_95 () ;
#endif
#endif
exit ( V_65 ) ;
}
static void
F_96 ( void )
{
if ( F_97 () ) {
T_31 V_116 [ 2 ] = { V_117 , V_118 } ;
int V_119 = sizeof( V_116 ) / sizeof( T_31 ) ;
T_9 V_22 = F_23 () ;
F_21 ( L_115 ) ;
if ( F_98 ( V_120 , 1 , 0 , 0 , 0 ) == - 1 ) {
F_16 ( L_116 , F_25 ( V_23 ) ) ;
}
F_99 ( V_22 , V_121 , V_119 , V_116 , V_122 ) ;
F_99 ( V_22 , V_123 , V_119 , V_116 , V_122 ) ;
if ( F_24 ( V_22 ) ) {
F_16 ( L_51 , F_25 ( V_23 ) ) ;
}
F_21 ( L_117 ) ;
F_45 () ;
F_21 ( L_118 ) ;
F_99 ( V_22 , V_124 , V_119 , V_116 , V_122 ) ;
if ( F_24 ( V_22 ) ) {
F_16 ( L_51 , F_25 ( V_23 ) ) ;
}
F_21 ( L_119 ) ;
F_26 ( V_22 ) ;
}
}
static void
F_100 ( T_3 V_125 , struct V_126 * V_127 , struct V_128 * V_129 )
{
if ( V_125 ) {
V_129 -> V_130 = F_101 ( V_129 -> V_130 ) ;
V_129 -> V_131 = F_101 ( V_129 -> V_131 ) ;
V_129 -> V_132 = F_101 ( V_129 -> V_132 ) ;
V_129 -> V_133 = F_101 ( V_129 -> V_133 ) ;
}
if ( V_127 -> V_134 == 2 &&
( V_127 -> V_135 < 3 ||
( V_127 -> V_135 == 3 && V_129 -> V_132 > V_129 -> V_133 ) ) ) {
V_4 V_136 ;
V_136 = V_129 -> V_133 ;
V_129 -> V_133 = V_129 -> V_132 ;
V_129 -> V_132 = V_136 ;
}
}
static void * F_102 ( void * V_137 )
{
T_32 * V_138 ;
int V_139 ;
#ifdef F_2
BOOL V_140 ;
T_29 V_141 , V_142 ;
#else
int V_141 ;
#endif
V_138 = ( T_32 * ) V_137 ;
while ( V_138 -> V_143 == V_144 ) {
F_103 ( V_138 -> V_145 ) ;
F_104 ( V_138 -> V_146 ) ;
V_139 = 0 ;
while ( V_139 < ( int ) V_138 -> V_147 ) {
#ifdef F_2
V_140 = F_105 ( V_138 -> V_148 , V_138 -> V_149 + V_139 ,
V_138 -> V_147 - V_139 ,
& V_141 , NULL ) ;
V_139 += V_141 ;
if ( ! V_140 ) {
V_142 = F_106 () ;
if ( V_142 == V_150 ) {
continue;
} else if ( V_142 == V_151 || V_142 == V_152 || V_142 == V_153 ) {
V_138 -> V_143 = V_154 ;
V_139 = 0 ;
break;
}
V_138 -> V_143 = V_155 ;
V_139 = - 1 ;
break;
} else if ( V_141 == 0 && V_138 -> V_147 > 0 ) {
V_138 -> V_143 = V_154 ;
V_139 = 0 ;
break;
}
#else
V_141 = F_107 ( V_138 -> V_156 , V_138 -> V_149 + V_139 ,
V_138 -> V_147 - V_139 ) ;
if ( V_141 <= 0 ) {
if ( V_141 == 0 ) {
V_138 -> V_143 = V_154 ;
V_139 = 0 ;
break;
} else {
V_138 -> V_143 = V_155 ;
V_139 = - 1 ;
break;
}
} else {
V_139 += V_141 ;
}
#endif
}
V_138 -> V_157 = V_139 ;
if ( V_138 -> V_157 >= V_138 -> V_147 ) {
F_108 ( V_138 -> V_158 , V_138 -> V_149 ) ;
}
F_109 ( V_138 -> V_146 ) ;
}
return NULL ;
}
static int
F_110 ( int V_159 )
{
T_33 V_160 ;
struct V_3 V_161 ;
F_111 ( & V_160 ) ;
F_112 ( V_159 , & V_160 ) ;
V_161 . V_7 = V_162 / 1000000 ;
V_161 . V_8 = V_162 % 1000000 ;
return F_113 ( V_159 + 1 , & V_160 , NULL , NULL , & V_161 ) ;
}
static void
F_114 ( char * V_163 ,
T_32 * V_138 ,
struct V_126 * V_127 ,
char * V_25 , int V_164 )
{
#ifndef F_2
T_34 V_165 ;
struct V_166 V_167 ;
int V_141 ;
int V_168 ;
#else
#if 1
char * V_169 , * V_170 ;
T_35 * V_57 ;
#endif
#endif
#ifndef F_2
int V_171 ;
unsigned int V_139 ;
#endif
V_4 V_172 = 0 ;
#ifndef F_2
V_138 -> V_156 = - 1 ;
#else
V_138 -> V_148 = V_173 ;
#endif
F_87 ( V_106 , V_108 , L_120 , V_163 ) ;
if ( strcmp ( V_163 , L_121 ) == 0 ) {
#ifndef F_2
V_168 = 0 ;
#else
V_138 -> V_148 = F_115 ( V_174 ) ;
#endif
} else {
#ifndef F_2
if ( F_116 ( V_163 , & V_165 ) < 0 ) {
if ( V_23 == V_175 || V_23 == V_176 )
V_138 -> V_143 = V_177 ;
else {
F_28 ( V_25 , V_164 ,
L_122
L_123 , F_25 ( V_23 ) ) ;
V_138 -> V_143 = V_155 ;
}
return;
}
if ( F_117 ( V_165 . V_178 ) ) {
V_168 = F_118 ( V_163 , V_179 | V_180 , 0000 ) ;
if ( V_168 == - 1 ) {
F_28 ( V_25 , V_164 ,
L_122
L_124 , F_25 ( V_23 ) ) ;
V_138 -> V_143 = V_155 ;
return;
}
} else if ( F_119 ( V_165 . V_178 ) ) {
V_168 = F_120 ( V_181 , V_182 , 0 ) ;
if ( V_168 == - 1 ) {
F_28 ( V_25 , V_164 ,
L_122
L_125 , F_25 ( V_23 ) ) ;
V_138 -> V_143 = V_155 ;
return;
}
V_167 . V_183 = V_181 ;
if ( F_121 ( V_167 . V_184 , V_163 , sizeof V_167 . V_184 ) > sizeof V_167 . V_184 ) {
F_28 ( V_25 , V_164 ,
L_126
L_127 ) ;
V_138 -> V_143 = V_155 ;
F_122 ( V_168 ) ;
return;
}
V_141 = F_123 ( V_168 , (struct V_185 * ) & V_167 , sizeof V_167 ) ;
if ( V_141 == - 1 ) {
F_28 ( V_25 , V_164 ,
L_126
L_128 , F_25 ( V_23 ) ) ;
V_138 -> V_143 = V_155 ;
F_122 ( V_168 ) ;
return;
}
} else {
if ( F_124 ( V_165 . V_178 ) ) {
V_138 -> V_143 = V_177 ;
} else
{
F_28 ( V_25 , V_164 ,
L_129
L_130 , V_163 ) ;
V_138 -> V_143 = V_155 ;
}
return;
}
#else
#define F_125 "\\pipe\\"
V_169 = F_54 ( V_163 ) ;
if ( ( V_170 = strstr ( V_169 , L_131 ) ) == V_169 ) {
V_170 = strchr ( V_169 + 3 , '\\' ) ;
if ( V_170 && F_126 ( V_170 , F_125 , strlen ( F_125 ) ) != 0 )
V_170 = NULL ;
}
F_19 ( V_169 ) ;
if ( ! V_170 ) {
F_28 ( V_25 , V_164 ,
L_129
L_132 , V_163 ) ;
V_138 -> V_143 = V_177 ;
return;
}
while ( 1 ) {
V_138 -> V_148 = F_127 ( F_128 ( V_163 ) , V_186 , 0 , NULL ,
V_187 , 0 , NULL ) ;
if ( V_138 -> V_148 != V_173 )
break;
if ( F_106 () != V_188 ) {
F_129 ( V_189 | V_190 ,
NULL , F_106 () , 0 , ( V_191 ) & V_57 , 0 , NULL ) ;
F_28 ( V_25 , V_164 ,
L_133
L_134 ,
V_163 , F_130 ( V_57 ) , F_106 () ) ;
F_131 ( V_57 ) ;
V_138 -> V_143 = V_155 ;
return;
}
if ( ! F_132 ( F_128 ( V_163 ) , 30 * 1000 ) ) {
F_129 ( V_189 | V_190 ,
NULL , F_106 () , 0 , ( V_191 ) & V_57 , 0 , NULL ) ;
F_28 ( V_25 , V_164 ,
L_135
L_136 ,
V_163 , F_130 ( V_57 ) , F_106 () ) ;
F_131 ( V_57 ) ;
V_138 -> V_143 = V_155 ;
return;
}
}
#endif
}
V_138 -> V_192 = TRUE ;
#ifndef F_2
V_139 = 0 ;
while ( V_139 < sizeof V_172 ) {
V_171 = F_110 ( V_168 ) ;
if ( V_171 < 0 ) {
F_28 ( V_25 , V_164 ,
L_137 , F_25 ( V_23 ) ) ;
goto error;
} else if ( V_171 > 0 ) {
V_141 = F_107 ( V_168 , ( ( char * ) & V_172 ) + V_139 , sizeof V_172 - V_139 ) ;
if ( V_141 <= 0 ) {
if ( V_141 == 0 )
F_28 ( V_25 , V_164 , L_138 ) ;
else
F_28 ( V_25 , V_164 , L_139 ,
F_25 ( V_23 ) ) ;
goto error;
}
V_139 += V_141 ;
}
}
#else
F_133 ( & F_102 , V_138 , FALSE , NULL ) ;
V_138 -> V_149 = ( char * ) & V_172 ;
V_138 -> V_157 = 0 ;
V_138 -> V_147 = sizeof( V_172 ) ;
F_108 ( V_138 -> V_145 , V_138 -> V_149 ) ;
F_103 ( V_138 -> V_158 ) ;
if ( V_138 -> V_157 <= 0 ) {
if ( V_138 -> V_157 == 0 )
F_28 ( V_25 , V_164 , L_138 ) ;
else
F_28 ( V_25 , V_164 , L_139 ,
F_25 ( V_23 ) ) ;
goto error;
}
#endif
switch ( V_172 ) {
case V_193 :
case V_194 :
V_138 -> V_195 = FALSE ;
V_138 -> V_196 = FALSE ;
V_138 -> V_197 = V_172 == V_194 ;
break;
case V_198 :
V_138 -> V_195 = FALSE ;
V_138 -> V_196 = TRUE ;
break;
case V_199 :
case V_200 :
V_138 -> V_195 = TRUE ;
V_138 -> V_196 = FALSE ;
V_138 -> V_197 = V_172 == V_200 ;
break;
case V_201 :
V_138 -> V_195 = TRUE ;
V_138 -> V_196 = TRUE ;
break;
default:
F_28 ( V_25 , V_164 , L_140 ) ;
goto error;
}
#ifndef F_2
V_139 = 0 ;
while ( V_139 < sizeof( struct V_126 ) ) {
V_171 = F_110 ( V_168 ) ;
if ( V_171 < 0 ) {
F_28 ( V_25 , V_164 ,
L_137 , F_25 ( V_23 ) ) ;
goto error;
} else if ( V_171 > 0 ) {
V_141 = F_107 ( V_168 , ( ( char * ) V_127 ) + V_139 ,
sizeof( struct V_126 ) - V_139 ) ;
if ( V_141 <= 0 ) {
if ( V_141 == 0 )
F_28 ( V_25 , V_164 , L_141 ) ;
else
F_28 ( V_25 , V_164 , L_142 ,
F_25 ( V_23 ) ) ;
goto error;
}
V_139 += V_141 ;
}
}
#else
V_138 -> V_149 = ( char * ) V_127 ;
V_138 -> V_157 = 0 ;
V_138 -> V_147 = sizeof( struct V_126 ) ;
F_108 ( V_138 -> V_145 , V_138 -> V_149 ) ;
F_103 ( V_138 -> V_158 ) ;
if ( V_138 -> V_157 <= 0 ) {
if ( V_138 -> V_157 == 0 )
F_28 ( V_25 , V_164 , L_141 ) ;
else
F_28 ( V_25 , V_164 , L_143 ,
F_25 ( V_23 ) ) ;
goto error;
}
#endif
if ( V_138 -> V_195 ) {
V_127 -> V_134 = F_134 ( V_127 -> V_134 ) ;
V_127 -> V_135 = F_134 ( V_127 -> V_135 ) ;
V_127 -> V_202 = F_101 ( V_127 -> V_202 ) ;
V_127 -> V_203 = F_101 ( V_127 -> V_203 ) ;
}
V_138 -> V_34 = V_127 -> V_203 ;
if ( V_127 -> V_134 < 2 ) {
F_28 ( V_25 , V_164 , L_144 ) ;
goto error;
}
V_138 -> V_204 = V_205 ;
V_138 -> V_143 = V_144 ;
#ifndef F_2
V_138 -> V_156 = V_168 ;
#endif
return;
error:
F_87 ( V_106 , V_108 , L_145 , V_25 ) ;
V_138 -> V_143 = V_155 ;
#ifndef F_2
F_122 ( V_168 ) ;
V_138 -> V_156 = - 1 ;
#endif
return;
}
static int
F_135 ( T_36 * V_206 , T_32 * V_138 , T_37 * V_80 , char * V_25 , int V_164 )
{
struct V_207 V_208 ;
enum { V_209 , V_210 , V_211 , V_212 ,
V_213 } V_214 ;
#ifdef F_2
#if ! F_136 ( 2 , 31 , 18 )
T_38 V_215 ;
#endif
T_39 V_216 ;
#else
int V_141 ;
#endif
#ifdef F_2
T_35 * V_57 ;
#endif
#ifdef F_137
F_87 ( V_106 , V_108 , L_146 ) ;
#endif
switch ( V_138 -> V_204 ) {
case V_205 :
#ifdef F_2
if ( F_138 ( V_138 -> V_146 ) ) {
#endif
V_138 -> V_204 = V_217 ;
V_138 -> V_147 = V_138 -> V_196 ?
sizeof( struct V_218 ) : sizeof( struct V_128 ) ;
V_138 -> V_157 = 0 ;
#ifdef F_2
V_138 -> V_149 = ( char * ) & V_138 -> V_219 ;
F_108 ( V_138 -> V_145 , V_138 -> V_149 ) ;
F_109 ( V_138 -> V_146 ) ;
}
#endif
case V_217 :
#ifndef F_2
V_141 = F_107 ( V_138 -> V_156 , ( ( char * ) & V_138 -> V_219 ) + V_138 -> V_157 ,
V_138 -> V_147 - V_138 -> V_157 ) ;
if ( V_141 <= 0 ) {
if ( V_141 == 0 )
V_214 = V_211 ;
else
V_214 = V_212 ;
break;
}
V_138 -> V_157 += V_141 ;
#else
#if F_136 ( 2 , 31 , 18 )
V_216 = F_139 ( V_138 -> V_158 , V_162 ) ;
#else
F_140 ( & V_215 ) ;
F_141 ( & V_215 , V_162 ) ;
V_216 = F_142 ( V_138 -> V_158 , & V_215 ) ;
#endif
if ( V_138 -> V_143 == V_154 ) {
V_214 = V_211 ;
break;
} else if ( V_138 -> V_143 == V_155 ) {
V_214 = V_212 ;
break;
}
if ( ! V_216 ) {
return 0 ;
}
#endif
if ( ( V_138 -> V_157 ) < V_138 -> V_147 )
return 0 ;
V_214 = V_209 ;
break;
case V_220 :
#ifdef F_2
if ( F_138 ( V_138 -> V_146 ) ) {
#endif
V_138 -> V_204 = V_221 ;
V_138 -> V_147 = V_138 -> V_219 . V_127 . V_132 ;
V_138 -> V_157 = 0 ;
#ifdef F_2
V_138 -> V_149 = ( char * ) V_80 ;
F_108 ( V_138 -> V_145 , V_138 -> V_149 ) ;
F_109 ( V_138 -> V_146 ) ;
}
#endif
case V_221 :
#ifndef F_2
V_141 = F_107 ( V_138 -> V_156 , V_80 + V_138 -> V_157 ,
V_138 -> V_147 - V_138 -> V_157 ) ;
if ( V_141 <= 0 ) {
if ( V_141 == 0 )
V_214 = V_211 ;
else
V_214 = V_212 ;
break;
}
V_138 -> V_157 += V_141 ;
#else
#if F_136 ( 2 , 31 , 18 )
V_216 = F_139 ( V_138 -> V_158 , V_162 ) ;
#else
F_140 ( & V_215 ) ;
F_141 ( & V_215 , V_162 ) ;
V_216 = F_142 ( V_138 -> V_158 , & V_215 ) ;
#endif
if ( V_138 -> V_143 == V_154 ) {
V_214 = V_211 ;
break;
} else if ( V_138 -> V_143 == V_155 ) {
V_214 = V_212 ;
break;
}
if ( ! V_216 ) {
return 0 ;
}
#endif
if ( ( V_138 -> V_157 ) < V_138 -> V_147 )
return 0 ;
V_214 = V_210 ;
break;
default:
F_28 ( V_25 , V_164 , L_147 ) ;
V_214 = V_213 ;
}
switch ( V_214 ) {
case V_209 :
F_100 ( V_138 -> V_195 , & V_138 -> V_222 ,
& V_138 -> V_219 . V_127 ) ;
if ( V_138 -> V_219 . V_127 . V_132 > V_223 ) {
F_28 ( V_25 , V_164 , L_148 ,
V_206 -> V_111 + 1 , V_138 -> V_219 . V_127 . V_132 ) ;
break;
}
if ( V_138 -> V_219 . V_127 . V_132 ) {
V_138 -> V_204 = V_220 ;
return 0 ;
}
case V_210 :
V_208 . V_224 . V_7 = V_138 -> V_219 . V_127 . V_130 ;
V_208 . V_224 . V_8 = V_138 -> V_219 . V_127 . V_131 ;
V_208 . V_225 = V_138 -> V_219 . V_127 . V_132 ;
V_208 . V_52 = V_138 -> V_219 . V_127 . V_133 ;
if ( V_226 ) {
F_143 ( ( V_227 * ) V_138 , & V_208 , V_80 ) ;
} else {
F_144 ( ( V_227 * ) V_138 , & V_208 , V_80 ) ;
}
V_138 -> V_204 = V_205 ;
return 1 ;
case V_211 :
V_138 -> V_143 = V_154 ;
return - 1 ;
case V_212 :
#ifdef F_2
F_129 ( V_189 | V_190 ,
NULL , F_106 () , 0 , ( V_191 ) & V_57 , 0 , NULL ) ;
F_28 ( V_25 , V_164 ,
L_149 ,
F_130 ( V_57 ) , F_106 () ) ;
F_131 ( V_57 ) ;
#else
F_28 ( V_25 , V_164 , L_150 ,
F_25 ( V_23 ) ) ;
#endif
case V_213 :
break;
}
V_138 -> V_143 = V_155 ;
return - 1 ;
}
static void F_145 ( T_36 * V_206 )
{
T_18 V_49 ;
T_32 * V_138 ;
F_87 ( V_106 , V_108 , L_151 ) ;
for ( V_49 = 0 ; V_49 < V_206 -> V_228 -> V_52 ; V_49 ++ ) {
V_138 = F_38 ( V_206 -> V_228 , T_32 * , V_49 ) ;
#ifndef F_2
if ( V_138 -> V_156 >= 0 ) {
F_146 ( V_138 -> V_192 ) ;
F_122 ( V_138 -> V_156 ) ;
V_138 -> V_156 = - 1 ;
}
#else
if ( V_138 -> V_148 != V_173 ) {
F_147 ( V_138 -> V_148 ) ;
V_138 -> V_148 = V_173 ;
}
#endif
if ( V_138 -> V_33 != NULL ) {
F_87 ( V_106 , V_108 , L_152 , ( void * ) V_138 -> V_33 ) ;
F_41 ( V_138 -> V_33 ) ;
V_138 -> V_33 = NULL ;
}
}
V_206 -> V_102 = FALSE ;
#ifdef F_2
F_93 () ;
#endif
}
static T_40
F_148 ( T_12 * V_33 , T_3 V_192 ,
const T_7 * T_13 , const T_7 * V_39 )
{
struct V_37 V_38 ;
F_87 ( V_106 , V_108 , L_153 , V_39 ) ;
if ( V_39 && ! V_192 ) {
if ( ! F_34 ( T_13 , V_33 , & V_38 , V_39 ) ) {
return V_229 ;
}
if ( F_149 ( V_33 , & V_38 ) < 0 ) {
#ifdef F_150
F_151 ( & V_38 ) ;
#endif
return V_230 ;
}
#ifdef F_150
F_151 ( & V_38 ) ;
#endif
}
return V_231 ;
}
static T_3
F_152 ( T_15 * V_44 , T_36 * V_206 , char * V_25 , int V_26 )
{
int V_56 ;
T_18 V_49 ;
T_32 * V_138 ;
T_16 V_45 ;
T_3 V_232 ;
F_87 ( V_106 , V_108 , L_154 ) ;
if ( ( V_44 -> V_233 == FALSE ) &&
( V_44 -> V_51 -> V_52 > 1 ) ) {
F_28 ( V_25 , V_26 ,
L_155 ) ;
return FALSE ;
}
if ( V_44 -> V_234 ) {
V_206 -> V_235 = F_153 ( & V_56 ) ;
} else {
V_206 -> V_235 = F_154 ( V_206 -> V_236 , & V_56 ) ;
}
if ( V_206 -> V_235 ) {
if ( V_44 -> V_233 ) {
char V_237 [ 100 ] ;
T_5 * V_238 ;
V_238 = F_155 ( L_48 ) ;
F_156 ( V_238 ) ;
F_28 ( V_237 , sizeof( V_237 ) , L_1 V_11 L_94 , V_12 ) ;
V_232 = F_157 ( V_206 -> V_235 ,
NULL ,
NULL ,
V_238 -> V_16 ,
V_237 ,
- 1 ,
& V_206 -> V_239 ,
& V_56 ) ;
for ( V_49 = 0 ; V_232 && ( V_49 < V_44 -> V_51 -> V_52 ) ; V_49 ++ ) {
V_45 = F_38 ( V_44 -> V_51 , T_16 , V_49 ) ;
V_138 = F_38 ( V_206 -> V_228 , T_32 * , V_49 ) ;
if ( V_138 -> V_192 ) {
V_138 -> V_202 = V_138 -> V_222 . V_202 ;
} else {
V_138 -> V_202 = F_158 ( V_138 -> V_33 ) ;
}
V_232 = F_159 ( V_101 . V_235 ,
NULL ,
V_45 . T_13 ,
V_45 . V_240 ,
V_45 . V_39 ,
V_238 -> V_16 ,
V_138 -> V_34 ,
V_138 -> V_202 ,
& ( V_101 . V_239 ) ,
0 ,
V_138 -> V_197 ? 9 : 6 ,
& V_101 . V_56 ) ;
}
F_160 ( V_238 , TRUE ) ;
} else {
V_138 = F_38 ( V_206 -> V_228 , T_32 * , 0 ) ;
if ( V_138 -> V_192 ) {
V_138 -> V_202 = V_138 -> V_222 . V_202 ;
} else {
V_138 -> V_202 = F_158 ( V_138 -> V_33 ) ;
}
V_232 = F_161 ( V_206 -> V_235 , V_138 -> V_34 , V_138 -> V_202 ,
V_138 -> V_197 , & V_206 -> V_239 , & V_56 ) ;
}
if ( ! V_232 ) {
fclose ( V_206 -> V_235 ) ;
V_206 -> V_235 = NULL ;
}
}
if ( V_206 -> V_235 == NULL ) {
switch ( V_56 ) {
default:
if ( V_56 < 0 ) {
F_28 ( V_25 , V_26 ,
L_156
L_157 ,
V_44 -> V_241 , V_56 ) ;
} else {
F_28 ( V_25 , V_26 ,
L_156
L_158 ,
V_44 -> V_241 , F_25 ( V_56 ) ) ;
}
break;
}
return FALSE ;
}
return TRUE ;
}
static T_3
F_162 ( T_15 * V_44 , T_36 * V_206 , int * V_242 )
{
unsigned int V_49 ;
T_32 * V_138 ;
T_1 V_243 = F_1 () ;
F_87 ( V_106 , V_108 , L_159 ) ;
if ( V_44 -> V_234 ) {
return F_163 ( & V_44 -> V_241 , V_242 ) ;
} else {
if ( V_44 -> V_233 ) {
for ( V_49 = 0 ; V_49 < V_101 . V_228 -> V_52 ; V_49 ++ ) {
V_138 = F_38 ( V_101 . V_228 , T_32 * , V_49 ) ;
if ( ! V_138 -> V_192 ) {
T_1 V_244 , V_245 ;
struct V_96 V_246 ;
if ( F_81 ( V_138 -> V_33 , & V_246 ) >= 0 ) {
V_244 = V_138 -> V_247 ;
V_245 = V_246 . V_104 + V_138 -> V_248 ;
} else {
V_244 = V_249 ;
V_245 = V_249 ;
}
F_164 ( V_206 -> V_235 ,
V_49 ,
& V_206 -> V_239 ,
L_160 ,
V_250 ,
V_243 ,
V_244 ,
V_245 ,
V_242 ) ;
}
}
}
return F_165 ( V_206 -> V_235 , V_242 ) ;
}
}
static int
F_166 ( T_36 * V_206 ,
char * V_25 , int V_26 , T_32 * V_138 )
{
int V_251 ;
T_41 V_252 ;
T_37 V_253 [ V_223 ] ;
#ifndef F_2
int V_171 ;
#endif
V_252 = V_206 -> V_111 ;
if ( V_138 -> V_192 ) {
#ifdef F_137
F_87 ( V_106 , V_108 , L_161 ) ;
#endif
#ifndef F_2
V_171 = F_110 ( V_138 -> V_156 ) ;
if ( V_171 <= 0 ) {
if ( V_171 < 0 && V_23 != V_254 ) {
F_28 ( V_25 , V_26 ,
L_137 , F_25 ( V_23 ) ) ;
F_40 ( V_25 , V_36 ) ;
V_206 -> V_102 = FALSE ;
}
} else {
#endif
V_251 = F_135 ( V_206 , V_138 , V_253 , V_25 , V_26 ) ;
if ( V_251 < 0 ) {
V_206 -> V_102 = FALSE ;
}
#ifndef F_2
}
#endif
}
else
{
#ifdef F_167
#ifdef F_137
F_87 ( V_106 , V_108 , L_162 ) ;
#endif
if ( V_138 -> V_255 != - 1 ) {
V_171 = F_110 ( V_138 -> V_255 ) ;
if ( V_171 > 0 ) {
if ( V_226 ) {
V_251 = F_168 ( V_138 -> V_33 , 1 , F_143 , ( V_227 * ) V_138 ) ;
} else {
V_251 = F_168 ( V_138 -> V_33 , 1 , F_144 , ( V_227 * ) V_138 ) ;
}
if ( V_251 < 0 ) {
if ( V_251 == - 1 ) {
V_138 -> V_256 = TRUE ;
}
V_206 -> V_102 = FALSE ;
}
} else {
if ( V_171 < 0 && V_23 != V_254 ) {
F_28 ( V_25 , V_26 ,
L_137 , F_25 ( V_23 ) ) ;
F_40 ( V_25 , V_36 ) ;
V_206 -> V_102 = FALSE ;
}
}
}
else
#endif
{
#if 1
#ifdef F_137
F_87 ( V_106 , V_108 , L_163 ) ;
#endif
#ifdef F_2
if ( V_226 ) {
V_251 = F_168 ( V_138 -> V_33 , 1 , F_143 , ( V_227 * ) V_138 ) ;
} else {
V_251 = F_168 ( V_138 -> V_33 , 1 , F_144 , ( V_227 * ) V_138 ) ;
}
#else
if ( V_226 ) {
V_251 = F_168 ( V_138 -> V_33 , - 1 , F_143 , ( V_227 * ) V_138 ) ;
} else {
V_251 = F_168 ( V_138 -> V_33 , - 1 , F_144 , ( V_227 * ) V_138 ) ;
}
#endif
if ( V_251 < 0 ) {
if ( V_251 == - 1 ) {
V_138 -> V_256 = TRUE ;
}
V_206 -> V_102 = FALSE ;
}
#else
#ifdef F_137
F_87 ( V_106 , V_108 , L_164 ) ;
#endif
{
int V_257 ;
struct V_207 * V_258 ;
V_227 * V_259 ;
V_257 = 0 ;
while( V_206 -> V_102 &&
( V_257 = F_169 ( V_138 -> V_33 , & V_258 , & V_259 ) ) == 1 ) {
if ( V_226 ) {
F_143 ( ( V_227 * ) V_138 , V_258 , V_259 ) ;
} else {
F_144 ( ( V_227 * ) V_138 , V_258 , V_259 ) ;
}
}
if( V_257 < 0 ) {
V_138 -> V_256 = TRUE ;
V_206 -> V_102 = FALSE ;
}
}
#endif
}
}
#ifdef F_137
F_87 ( V_106 , V_108 , L_165 , V_251 , F_170 ( V_251 , L_48 , L_166 ) ) ;
#endif
return V_206 -> V_111 - V_252 ;
}
static T_5 *
F_171 ( const char * T_10 )
{
T_7 * V_260 ;
T_5 * V_261 ;
V_260 = strchr ( T_10 , '{' ) ;
if ( V_260 == NULL )
return F_155 ( T_10 ) ;
V_261 = F_155 ( V_260 + 1 ) ;
V_260 = strchr ( V_261 -> V_16 , '}' ) ;
if ( V_260 == NULL )
return V_261 ;
V_261 = F_172 ( V_261 , V_260 - V_261 -> V_16 ) ;
return V_261 ;
}
static T_3
F_173 ( T_15 * V_44 , int * V_236 ,
char * V_25 , int V_26 )
{
char * V_262 ;
T_7 * V_263 ;
T_7 * V_264 ;
T_3 V_265 ;
F_87 ( V_106 , V_108 , L_167 ,
( V_44 -> V_241 ) ? V_44 -> V_241 : L_168 ) ;
if ( V_44 -> V_241 != NULL ) {
V_263 = F_54 ( V_44 -> V_241 ) ;
if ( V_44 -> V_266 == TRUE ) {
if ( V_44 -> V_234 ) {
F_28 ( V_25 , V_26 ,
L_169 ) ;
F_19 ( V_263 ) ;
return FALSE ;
}
if ( strcmp ( V_263 , L_121 ) == 0 ) {
* V_236 = 1 ;
#ifdef F_2
F_174 ( 1 , V_267 ) ;
#endif
}
}
else {
if ( V_44 -> V_234 ) {
* V_236 = F_175 ( V_263 ,
( V_44 -> V_268 ) ? V_44 -> V_269 : 0 ,
V_44 -> V_270 ) ;
if( * V_236 != - 1 ) {
F_19 ( V_263 ) ;
V_263 = F_54 ( F_176 () ) ;
}
} else {
* V_236 = F_118 ( V_263 , V_271 | V_267 | V_272 | V_273 ,
( V_44 -> V_270 ) ? 0640 : 0600 ) ;
}
}
V_265 = FALSE ;
} else {
if ( V_274 . V_51 -> V_52 > 1 ) {
V_264 = F_55 ( L_170 , V_274 . V_51 -> V_52 ) ;
} else {
T_7 * V_275 ;
#ifdef F_2
T_5 * T_10 ;
T_10 = F_171 ( F_38 ( V_274 . V_51 , T_16 , 0 ) . T_13 ) ;
V_275 = F_177 ( T_10 -> V_16 ) ;
F_160 ( T_10 , TRUE ) ;
#else
V_275 = F_177 ( F_38 ( V_274 . V_51 , T_16 , 0 ) . T_13 ) ;
#endif
V_264 = F_178 ( L_171 , V_275 , NULL ) ;
F_19 ( V_275 ) ;
}
* V_236 = F_179 ( & V_262 , V_264 ) ;
F_19 ( V_264 ) ;
V_263 = F_54 ( V_262 ) ;
V_265 = TRUE ;
}
if ( * V_236 == - 1 ) {
if ( V_265 ) {
F_28 ( V_25 , V_26 ,
L_172
L_173 , V_263 , F_25 ( V_23 ) ) ;
} else {
if ( V_44 -> V_234 ) {
F_180 () ;
}
F_28 ( V_25 , V_26 ,
L_174
L_173 , V_263 ,
F_25 ( V_23 ) ) ;
}
F_19 ( V_263 ) ;
return FALSE ;
}
if( V_44 -> V_241 != NULL ) {
F_19 ( V_44 -> V_241 ) ;
}
V_44 -> V_241 = V_263 ;
return TRUE ;
}
static T_3
F_181 ( T_15 * V_44 ,
T_42 * V_276 ,
T_42 * V_277 ,
T_42 * V_278 )
{
T_18 V_49 ;
T_32 * V_138 ;
T_16 V_45 ;
T_3 V_232 ;
if ( V_44 -> V_234 ) {
if ( V_276 != NULL &&
F_182 ( V_276 , ++ V_101 . V_279 ) ) {
V_101 . V_102 = FALSE ;
return FALSE ;
}
if ( F_183 ( & V_101 . V_235 , & V_44 -> V_241 ,
& V_101 . V_236 , & V_101 . V_56 ) ) {
V_101 . V_239 = 0 ;
if ( V_44 -> V_233 ) {
char V_237 [ 100 ] ;
T_5 * V_238 ;
V_238 = F_155 ( L_48 ) ;
F_156 ( V_238 ) ;
F_28 ( V_237 , sizeof( V_237 ) , L_1 V_11 L_94 , V_12 ) ;
V_232 = F_157 ( V_101 . V_235 ,
NULL ,
NULL ,
V_238 -> V_16 ,
V_237 ,
- 1 ,
& ( V_101 . V_239 ) ,
& V_101 . V_56 ) ;
for ( V_49 = 0 ; V_232 && ( V_49 < V_44 -> V_51 -> V_52 ) ; V_49 ++ ) {
V_45 = F_38 ( V_44 -> V_51 , T_16 , V_49 ) ;
V_138 = F_38 ( V_101 . V_228 , T_32 * , V_49 ) ;
V_232 = F_159 ( V_101 . V_235 ,
NULL ,
V_45 . T_13 ,
V_45 . V_240 ,
V_45 . V_39 ,
V_238 -> V_16 ,
V_138 -> V_34 ,
V_138 -> V_202 ,
& ( V_101 . V_239 ) ,
0 ,
V_138 -> V_197 ? 9 : 6 ,
& V_101 . V_56 ) ;
}
F_160 ( V_238 , TRUE ) ;
} else {
V_138 = F_38 ( V_101 . V_228 , T_32 * , 0 ) ;
V_232 = F_161 ( V_101 . V_235 , V_138 -> V_34 , V_138 -> V_202 ,
V_138 -> V_197 , & V_101 . V_239 , & V_101 . V_56 ) ;
}
if ( ! V_232 ) {
fclose ( V_101 . V_235 ) ;
V_101 . V_235 = NULL ;
V_101 . V_102 = FALSE ;
return FALSE ;
}
if ( V_277 )
F_184 ( V_277 ) ;
if ( V_278 )
F_184 ( V_278 ) ;
F_185 ( V_101 . V_235 , NULL ) ;
if ( ! V_112 )
F_186 ( V_101 . V_280 ) ;
V_101 . V_280 = 0 ;
F_187 ( V_44 -> V_241 ) ;
} else {
V_101 . V_102 = FALSE ;
return FALSE ;
}
} else {
V_101 . V_102 = FALSE ;
return FALSE ;
}
return TRUE ;
}
static void *
F_188 ( void * V_137 )
{
T_32 * V_138 ;
char V_25 [ V_46 + 1 ] ;
V_138 = ( T_32 * ) V_137 ;
F_87 ( V_106 , V_107 , L_175 ,
V_138 -> V_281 ) ;
while ( V_101 . V_102 ) {
F_166 ( & V_101 , V_25 , sizeof( V_25 ) , V_138 ) ;
}
F_87 ( V_106 , V_107 , L_176 ,
V_138 -> V_281 ) ;
F_189 ( NULL ) ;
return ( NULL ) ;
}
static void F_88 ( void )
{
#ifdef F_190
T_18 V_49 ;
T_32 * V_138 ;
for ( V_49 = 0 ; V_49 < V_101 . V_228 -> V_52 ; V_49 ++ ) {
V_138 = F_38 ( V_101 . V_228 , T_32 * , V_49 ) ;
if ( V_138 -> V_33 != NULL )
F_191 ( V_138 -> V_33 ) ;
}
#endif
V_101 . V_102 = FALSE ;
}
static void
F_192 ( char * V_25 , int V_282 , const char * V_283 ,
int V_56 , T_3 V_284 )
{
switch ( V_56 ) {
case V_285 :
F_28 ( V_25 , V_282 ,
L_177
L_178
L_179
L_180 ,
V_283 ) ;
break;
#ifdef F_193
case F_193 :
F_28 ( V_25 , V_282 ,
L_177
L_178
L_181
L_182
L_183 ,
V_283 ) ;
break;
#endif
default:
if ( V_284 ) {
F_28 ( V_25 , V_282 ,
L_184
L_185 ,
V_283 , F_25 ( V_56 ) ) ;
} else {
F_28 ( V_25 , V_282 ,
L_186
L_178
L_187 ,
V_283 , F_25 ( V_56 ) ) ;
}
break;
}
}
static void
F_144 ( V_227 * V_286 , const struct V_207 * V_208 ,
const V_227 * V_287 )
{
T_32 * V_138 = ( T_32 * ) ( void * ) V_286 ;
int V_56 ;
T_18 V_288 = V_138 -> V_197 ? 1000000000 : 1000000 ;
if ( ! V_101 . V_102 )
return;
if ( V_101 . V_235 ) {
T_3 V_232 ;
if ( V_274 . V_233 ) {
V_232 = F_194 ( V_101 . V_235 , V_208 , V_138 -> V_281 , V_288 , V_287 , & V_101 . V_239 , & V_56 ) ;
} else {
V_232 = F_195 ( V_101 . V_235 , V_208 , V_287 , & V_101 . V_239 , & V_56 ) ;
}
if ( ! V_232 ) {
V_101 . V_102 = FALSE ;
V_101 . V_56 = V_56 ;
} else {
F_87 ( V_106 , V_107 ,
L_188 ,
V_208 -> V_225 , V_138 -> V_281 ) ;
V_101 . V_111 ++ ;
if ( ( V_101 . V_289 > 0 ) && ( V_101 . V_111 >= V_101 . V_289 ) ) {
V_101 . V_102 = FALSE ;
}
}
}
}
static void
F_143 ( V_227 * V_286 , const struct V_207 * V_208 ,
const V_227 * V_287 )
{
T_32 * V_138 = ( T_32 * ) ( void * ) V_286 ;
T_43 * V_290 ;
T_3 V_291 ;
if ( ! V_101 . V_102 ) {
V_138 -> V_248 ++ ;
return;
}
V_290 = ( T_43 * ) F_52 ( sizeof( T_43 ) ) ;
if ( V_290 == NULL ) {
V_138 -> V_248 ++ ;
return;
}
V_290 -> V_138 = V_138 ;
V_290 -> V_208 = * V_208 ;
V_290 -> V_287 = ( V_227 * ) F_52 ( V_208 -> V_225 ) ;
if ( V_290 -> V_287 == NULL ) {
V_138 -> V_248 ++ ;
F_19 ( V_290 ) ;
return;
}
memcpy ( V_290 -> V_287 , V_287 , V_208 -> V_225 ) ;
F_196 ( V_292 ) ;
if ( ( ( V_293 > 0 ) && ( V_294 < V_293 ) ) &&
( ( V_295 > 0 ) && ( V_296 < V_295 ) ) ) {
V_291 = FALSE ;
F_197 ( V_292 , V_290 ) ;
V_294 += V_208 -> V_225 ;
V_296 += 1 ;
} else {
V_291 = TRUE ;
}
F_198 ( V_292 ) ;
if ( V_291 ) {
V_138 -> V_248 ++ ;
F_19 ( V_290 -> V_287 ) ;
F_19 ( V_290 ) ;
F_87 ( V_106 , V_107 ,
L_189 ,
V_208 -> V_225 , V_138 -> V_281 ) ;
} else {
V_138 -> V_247 ++ ;
F_87 ( V_106 , V_107 ,
L_190 ,
V_208 -> V_225 , V_138 -> V_281 ) ;
}
F_87 ( V_106 , V_107 ,
L_191 V_297 L_192 V_297 L_193 ,
V_294 , V_296 ) ;
}
static void
F_199 ( const char * V_298 , T_44 V_299 ,
const char * V_300 , T_39 T_45 V_21 )
{
T_46 V_301 ;
struct V_302 * V_303 ;
const char * V_304 ;
T_7 * V_20 ;
if( ! ( V_299 & V_305 & ~ ( V_108 | V_107 ) ) ) {
#if ! F_8 ( F_94 ) && ! F_8 ( V_306 )
return;
#endif
}
time ( & V_301 ) ;
V_303 = localtime ( & V_301 ) ;
switch( V_299 & V_305 ) {
case V_307 :
V_304 = L_194 ;
break;
case V_308 :
V_304 = L_195 ;
break;
case V_309 :
V_304 = L_196 ;
break;
case V_310 :
V_304 = L_197 ;
break;
case V_107 :
V_304 = L_198 ;
break;
case V_108 :
V_304 = L_199 ;
break;
default:
fprintf ( V_13 , L_200 , V_299 ) ;
V_304 = NULL ;
F_200 () ;
}
if( V_299 & V_310 ) {
V_20 = F_55 ( L_2 , V_300 ) ;
} else {
V_20 = F_55 ( L_201 ,
V_303 -> V_311 , V_303 -> V_312 , V_303 -> V_313 ,
V_298 != NULL ? V_298 : L_48 ,
V_304 , V_300 ) ;
}
#if F_8 ( F_94 ) || F_8 ( V_306 )
if( ! ( V_299 & V_305 & ~ ( V_108 | V_107 ) ) ) {
#ifdef F_94
fprintf ( V_13 , L_94 , V_20 ) ;
fflush ( V_13 ) ;
#endif
#ifdef V_306
fprintf ( V_314 , L_94 , V_20 ) ;
fflush ( V_314 ) ;
#endif
F_19 ( V_20 ) ;
return;
}
#endif
if ( V_19 ) {
F_18 ( 2 , V_20 , L_48 ) ;
} else {
fprintf ( V_13 , L_94 , V_20 ) ;
fflush ( V_13 ) ;
}
F_19 ( V_20 ) ;
}
static void
F_186 ( int V_111 )
{
char V_315 [ V_316 + 1 + 1 ] ;
static int V_317 = 0 ;
if( V_19 ) {
F_28 ( V_315 , sizeof( V_315 ) , L_202 , V_111 ) ;
F_87 ( V_106 , V_108 , L_203 , V_315 ) ;
F_46 ( 2 , V_318 , V_315 ) ;
} else {
V_317 += V_111 ;
fprintf ( V_13 , L_204 , V_317 ) ;
fflush ( V_13 ) ;
}
}
static void
F_187 ( const char * V_319 )
{
if( V_19 ) {
F_87 ( V_106 , V_108 , L_205 , V_319 ) ;
F_46 ( 2 , V_320 , V_319 ) ;
} else {
#ifdef F_201
V_115 = TRUE ;
#endif
fprintf ( V_13 , L_206 , V_319 ) ;
fflush ( V_13 ) ;
#ifdef F_201
V_115 = FALSE ;
if ( V_113 )
F_90 () ;
#endif
}
}
static void
F_42 ( T_15 * V_44 , T_18 V_49 , const char * V_25 )
{
T_16 V_45 ;
char V_315 [ V_46 + 1 + 6 ] ;
if ( V_49 < V_44 -> V_51 -> V_52 ) {
if ( V_19 ) {
F_28 ( V_315 , sizeof( V_315 ) , L_207 , V_49 , V_25 ) ;
F_87 ( V_106 , V_108 , L_208 , V_25 ) ;
F_46 ( 2 , V_321 , V_315 ) ;
} else {
V_45 = F_38 ( V_44 -> V_51 , T_16 , V_49 ) ;
F_16 (
L_209
L_6
L_210
L_211 ,
V_45 . V_39 , V_45 . T_13 , V_25 ) ;
}
}
}
static void
F_40 ( const char * V_322 , const char * V_323 )
{
if( V_19 ) {
F_87 ( V_106 , V_108 ,
L_212 , V_322 ) ;
F_87 ( V_106 , V_108 ,
L_213 , V_323 ) ;
F_18 ( 2 , V_322 , V_323 ) ;
} else {
F_16 ( L_94 , V_322 ) ;
if ( V_323 [ 0 ] != '\0' )
F_20 ( L_94 , V_323 ) ;
}
}
static void
F_202 ( V_4 V_247 , V_4 V_324 , T_7 * T_13 )
{
char V_315 [ V_316 + 1 + 1 ] ;
F_28 ( V_315 , sizeof( V_315 ) , L_214 , V_324 ) ;
if( V_19 ) {
F_87 ( V_106 , V_108 ,
L_215 ,
T_13 , V_247 , V_324 ) ;
F_46 ( 2 , V_325 , V_315 ) ;
} else {
fprintf ( V_13 ,
L_216 ,
T_13 , V_247 , V_324 ,
V_247 ? 100.0 * V_247 / ( V_247 + V_324 ) : 0.0 ) ;
fflush ( V_13 ) ;
}
}
static T_3
F_203 ( void )
{
T_29 V_326 = 0 ;
T_3 V_214 ;
if( ! V_19 ) {
return TRUE ;
}
if( ! V_327 || ! V_328 ) {
F_87 ( V_106 , V_107 ,
L_217 ) ;
return FALSE ;
}
V_214 = F_204 ( V_328 , NULL , 0 , NULL , & V_326 , NULL ) ;
if( ! V_214 || V_326 > 0 ) {
F_87 ( V_106 , V_107 ,
L_218 , V_327 ) ;
F_87 ( V_106 , V_108 ,
L_219 , V_327 ,
V_328 , V_214 , V_326 ) ;
return FALSE ;
} else {
return TRUE ;
}
}
