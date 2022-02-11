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
fprintf ( V_10 , L_8
L_9
L_10
L_11 ) ;
fprintf ( V_10 , L_12 ) ;
fprintf ( V_10 , L_13 ) ;
fprintf ( V_10 , L_14 ) ;
#ifdef F_7
fprintf ( V_10 , L_15 ) ;
#endif
#if F_8 ( F_2 ) || F_8 ( F_7 )
fprintf ( V_10 , L_16 , V_14 ) ;
#endif
fprintf ( V_10 , L_17 ) ;
fprintf ( V_10 , L_18 ) ;
fprintf ( V_10 , L_19 ) ;
#ifdef F_9
fprintf ( V_10 , L_20 ) ;
#endif
fprintf ( V_10 , L_21 ) ;
fprintf ( V_10 , L_22 ) ;
fprintf ( V_10 , L_23 ) ;
fprintf ( V_10 , L_6 ) ;
#ifdef F_10
fprintf ( V_10 , L_24 ) ;
fprintf ( V_10 , L_25 ) ;
fprintf ( V_10 , L_26 ) ;
fprintf ( V_10 , L_27 ) ;
#ifdef F_11
fprintf ( V_10 , L_28 ) ;
fprintf ( V_10 , L_29 ) ;
fprintf ( V_10 , L_30 ) ;
#endif
#endif
fprintf ( V_10 , L_31 ) ;
fprintf ( V_10 , L_32 ) ;
fprintf ( V_10 , L_33 ) ;
fprintf ( V_10 , L_34 ) ;
fprintf ( V_10 , L_35 ) ;
fprintf ( V_10 , L_36 ) ;
fprintf ( V_10 , L_37 ) ;
fprintf ( V_10 , L_38 ) ;
fprintf ( V_10 , L_39 ) ;
fprintf ( V_10 , L_40 ) ;
fprintf ( V_10 , L_41 ) ;
fprintf ( V_10 , L_42 ) ;
fprintf ( V_10 , L_43 ) ;
fprintf ( V_10 , L_6 ) ;
fprintf ( V_10 , L_44 ) ;
fprintf ( V_10 , L_45 ) ;
fprintf ( V_10 , L_46 ) ;
fprintf ( V_10 , L_47 ) ;
fprintf ( V_10 , L_48 ) ;
fprintf ( V_10 , L_49 ) ;
fprintf ( V_10 , L_50 ) ;
fprintf ( V_10 , L_6 ) ;
fprintf ( V_10 , L_51 ) ;
fprintf ( V_10 , L_52 ) ;
fprintf ( V_10 , L_6 ) ;
fprintf ( V_10 , L_53 ) ;
}
static void
F_12 ( T_5 * V_15 , T_5 * V_16 )
{
printf (
L_1 V_11 L_2
L_6
L_2
L_2
L_2
L_4 ,
V_12 , F_13 () , V_15 -> V_17 , V_16 -> V_17 ) ;
}
void
F_14 ( const char * V_18 , ... )
{
T_6 V_19 ;
if ( V_20 ) {
T_7 * V_21 ;
va_start ( V_19 , V_18 ) ;
V_21 = F_15 ( V_18 , V_19 ) ;
F_16 ( 2 , V_21 , L_54 ) ;
F_17 ( V_21 ) ;
va_end ( V_19 ) ;
} else {
va_start ( V_19 , V_18 ) ;
fprintf ( V_13 , L_55 ) ;
vfprintf ( V_13 , V_18 , V_19 ) ;
fprintf ( V_13 , L_6 ) ;
va_end ( V_19 ) ;
}
}
void
F_18 ( const char * V_18 , ... )
{
T_6 V_19 ;
if ( V_20 ) {
T_7 * V_21 ;
va_start ( V_19 , V_18 ) ;
V_21 = F_15 ( V_18 , V_19 ) ;
F_16 ( 2 , V_21 , L_54 ) ;
F_17 ( V_21 ) ;
va_end ( V_19 ) ;
} else {
va_start ( V_19 , V_18 ) ;
vfprintf ( V_13 , V_18 , V_19 ) ;
fprintf ( V_13 , L_6 ) ;
va_end ( V_19 ) ;
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
F_19 ( const char * T_8 V_22 ) {
#endif
}
static void
F_20 ( void )
{
T_9 V_23 = F_21 () ;
F_19 ( L_56 ) ;
if ( F_22 ( V_23 ) ) {
F_14 ( L_57 , F_23 ( V_24 ) ) ;
}
F_19 ( L_58 ) ;
F_24 ( V_23 ) ;
}
static void
F_25 ( const char * V_25 ,
const char * T_10
#ifndef F_2
V_22
#endif
,
char * V_26 , T_11 V_27 ,
char * V_28 ,
T_11 V_29 )
{
#ifndef F_2
const char * V_30 ;
static const char V_31 [] = L_59 ;
#endif
F_26 ( V_26 , ( V_32 ) V_27 ,
L_60 , V_25 ) ;
#ifdef F_2
if ( ! V_33 ) {
F_26 ( V_28 , ( V_32 ) V_29 ,
L_6
L_61
L_6
L_62
L_6
L_63
L_6
L_64
L_6
L_63
L_6
L_65
L_6
L_66
L_67 ) ;
} else {
F_26 ( V_28 , ( V_32 ) V_29 ,
L_6
L_68
L_6
L_6
L_69
L_6
L_70
L_71 ,
T_10 ) ;
}
#else
if ( strncmp ( V_25 , V_31 , sizeof V_31 - 1 ) == 0 )
V_30 =
L_72
L_73
L_74
L_75
L_6
L_76
L_77
L_78
L_79
L_80 ;
else
V_30 = L_54 ;
F_26 ( V_28 , ( V_32 ) V_29 ,
L_81
L_82 , V_30 ) ;
#endif
}
static T_3
F_27 ( T_12 * V_34 , int V_35 ,
#ifdef F_28
char * T_13 V_22 ,
#else
char * T_13 ,
#endif
char * V_26 , T_11 V_27 ,
char * V_28 , T_11 V_29 )
{
char * V_36 ;
if ( V_35 == - 1 )
return TRUE ;
#ifdef F_28
if ( F_29 ( V_34 , V_35 ) == 0 )
return TRUE ;
V_36 = F_30 ( V_34 ) ;
#else
if ( F_31 ( V_34 , T_13 ) == V_35 )
return TRUE ;
V_36 =
L_83 ;
#endif
F_26 ( V_26 , ( V_32 ) V_27 , L_84 ,
V_36 ) ;
if ( strstr ( V_36 , L_85 ) == NULL )
F_26 ( V_28 , ( V_32 ) V_29 , V_37 ) ;
else
V_28 [ 0 ] = '\0' ;
return FALSE ;
}
static T_3
F_32 ( const char * T_10 , T_12 * V_34 ,
struct V_38 * V_39 , const char * V_40 )
{
T_14 V_41 , V_42 ;
T_7 V_43 [ V_44 ] ;
if ( F_33 ( T_10 , & V_41 , & V_42 , V_43 ) < 0 ) {
V_42 = 0 ;
}
if ( F_34 ( V_34 , V_39 , ( char * ) V_40 , 1 , V_42 ) < 0 )
return FALSE ;
return TRUE ;
}
static T_3
F_35 ( T_15 * V_45 )
{
T_16 V_46 ;
T_12 * V_34 ;
T_7 V_25 [ V_44 ] ;
char V_26 [ V_47 + 1 ] ;
char V_28 [ V_47 + 1 ] ;
struct V_38 V_39 ;
struct V_48 * V_49 ;
T_17 V_50 ;
T_18 V_51 ;
for ( V_51 = 0 ; V_51 < V_45 -> V_52 -> V_53 ; V_51 ++ ) {
V_46 = F_36 ( V_45 -> V_52 , T_16 , V_51 ) ;
V_34 = F_37 ( & V_46 , & V_25 ) ;
if ( V_34 == NULL ) {
F_25 ( V_25 ,
V_46 . T_13 ,
V_26 , sizeof V_26 ,
V_28 ,
sizeof V_28 ) ;
F_38 ( V_26 , V_28 ) ;
return FALSE ;
}
if ( ! F_27 ( V_34 , V_46 . V_35 , V_46 . T_13 ,
V_26 , sizeof V_26 ,
V_28 , sizeof V_28 ) ) {
F_39 ( V_34 ) ;
F_38 ( V_26 , V_28 ) ;
return FALSE ;
}
if ( ! F_32 ( V_46 . T_13 , V_34 , & V_39 ,
V_46 . V_40 ) ) {
F_39 ( V_34 ) ;
F_40 ( V_45 , V_51 , V_26 ) ;
return FALSE ;
}
F_39 ( V_34 ) ;
V_49 = V_39 . V_54 ;
for ( V_50 = 0 ; V_50 < V_39 . V_55 ; V_49 ++ , V_50 ++ )
printf ( L_2 , F_41 ( V_49 , V_50 ) ) ;
}
#ifndef F_42
F_43 () ;
#else
F_20 () ;
#endif
if ( V_20 ) {
F_44 ( 2 , V_56 , NULL ) ;
}
return TRUE ;
}
T_19 *
F_45 ( int * V_57 , char * * V_58 )
{
return F_46 ( V_57 , V_58 ) ;
}
static int
F_31 ( T_12 * V_59 , const char * T_20
#ifndef F_47
V_22
#endif
)
{
int V_35 ;
#ifdef F_47
const char * V_60 ;
#endif
V_35 = F_48 ( V_59 ) ;
#ifdef F_47
V_60 = strchr ( T_20 , '/' ) ;
if ( V_60 == NULL )
V_60 = T_20 ;
if ( strncmp ( V_60 , L_86 , 2 ) == 0 ) {
if ( V_35 == 6 ) {
V_35 = 1 ;
}
} else if ( strncmp ( V_60 , L_87 , 2 ) == 0 ) {
if ( V_35 == 7 ) {
V_35 = 1 ;
}
} else if ( strncmp ( V_60 , L_88 , 2 ) == 0 ) {
if ( V_35 == 9 ) {
V_35 = 6 ;
}
} else if ( strncmp ( V_60 , L_89 , 2 ) == 0 ) {
if ( V_35 == 15 ) {
V_35 = 10 ;
}
} else if ( strncmp ( V_60 , L_90 , 2 ) == 0 ) {
if ( V_35 == 24 ) {
V_35 = 0 ;
}
}
#endif
return V_35 ;
}
static T_21 *
F_49 ( int V_61 )
{
T_21 * V_62 ;
const char * V_63 ;
V_62 = ( T_21 * ) F_50 ( sizeof ( T_21 ) ) ;
V_62 -> V_61 = V_61 ;
V_63 = F_51 ( V_61 ) ;
if ( V_63 != NULL )
V_62 -> T_13 = F_52 ( V_63 ) ;
else
V_62 -> T_13 = F_53 ( L_91 , V_61 ) ;
V_63 = F_54 ( V_61 ) ;
if ( V_63 != NULL )
V_62 -> V_64 = F_52 ( V_63 ) ;
else
V_62 -> V_64 = NULL ;
return V_62 ;
}
static T_22 *
F_55 ( const char * T_20 , T_3 T_23
#ifndef F_7
V_22
#endif
, char * * V_58 )
{
T_22 * V_23 ;
char V_65 [ V_44 ] ;
T_12 * V_59 ;
#ifdef F_7
int V_66 ;
#endif
int V_67 ;
#ifdef F_56
int * V_68 ;
int V_50 , V_69 ;
#endif
T_21 * V_62 ;
V_23 = ( T_22 * ) F_50 ( sizeof *V_23 ) ;
V_65 [ 0 ] = '\0' ;
#ifdef F_57
V_59 = F_58 ( T_20 , V_70 , 0 , 0 , NULL , V_65 ) ;
V_23 -> V_71 = FALSE ;
if ( V_59 == NULL ) {
if ( V_58 != NULL )
* V_58 = F_52 ( V_65 [ 0 ] == '\0' ? L_92 : V_65 ) ;
F_17 ( V_23 ) ;
return NULL ;
}
#elif F_8 ( F_7 )
V_59 = F_59 ( T_20 , V_65 ) ;
if ( V_59 == NULL ) {
if ( V_58 != NULL )
* V_58 = F_52 ( V_65 ) ;
F_17 ( V_23 ) ;
return NULL ;
}
V_66 = F_60 ( V_59 ) ;
if ( V_66 < 0 ) {
if ( V_66 == V_72 )
* V_58 = F_53 ( L_93 ,
F_30 ( V_59 ) ) ;
else
* V_58 = F_52 ( F_61 ( V_66 ) ) ;
F_39 ( V_59 ) ;
F_17 ( V_23 ) ;
return NULL ;
}
if ( V_66 == 0 )
V_23 -> V_71 = FALSE ;
else if ( V_66 == 1 ) {
V_23 -> V_71 = TRUE ;
if ( T_23 )
F_62 ( V_59 , 1 ) ;
} else {
if ( V_58 != NULL ) {
* V_58 = F_53 ( L_94 ,
V_66 ) ;
}
F_39 ( V_59 ) ;
F_17 ( V_23 ) ;
return NULL ;
}
V_66 = F_63 ( V_59 ) ;
if ( V_66 < 0 ) {
if ( V_58 != NULL ) {
if ( V_66 == V_72 )
* V_58 = F_53 ( L_95 ,
F_30 ( V_59 ) ) ;
else
* V_58 = F_52 ( F_61 ( V_66 ) ) ;
}
F_39 ( V_59 ) ;
F_17 ( V_23 ) ;
return NULL ;
}
#else
V_59 = F_64 ( T_20 , V_70 , 0 , 0 , V_65 ) ;
V_23 -> V_71 = FALSE ;
if ( V_59 == NULL ) {
if ( V_58 != NULL )
* V_58 = F_52 ( V_65 [ 0 ] == '\0' ? L_92 : V_65 ) ;
F_17 ( V_23 ) ;
return NULL ;
}
#endif
V_67 = F_31 ( V_59 , T_20 ) ;
#ifdef F_56
V_69 = F_65 ( V_59 , & V_68 ) ;
if ( V_69 == 0 || V_68 == NULL ) {
F_39 ( V_59 ) ;
if ( V_58 != NULL )
* V_58 = NULL ;
F_17 ( V_23 ) ;
return NULL ;
}
V_23 -> V_73 = NULL ;
for ( V_50 = 0 ; V_50 < V_69 ; V_50 ++ ) {
V_62 = F_49 ( V_68 [ V_50 ] ) ;
if ( V_68 [ V_50 ] == V_67 )
V_23 -> V_73 = F_66 ( V_23 -> V_73 ,
V_62 ) ;
else
V_23 -> V_73 = F_67 ( V_23 -> V_73 ,
V_62 ) ;
}
#ifdef F_68
F_69 ( V_68 ) ;
#else
#ifndef F_2
#define F_70 free
F_70 ( V_68 ) ;
#endif
#endif
#else
V_62 = F_49 ( V_67 ) ;
V_23 -> V_73 = F_67 ( V_23 -> V_73 ,
V_62 ) ;
#endif
F_39 ( V_59 ) ;
if ( V_58 != NULL )
* V_58 = NULL ;
return V_23 ;
}
static void
F_71 ( T_19 * V_74 )
{
int V_50 ;
T_19 * V_75 ;
T_24 * V_76 ;
T_25 * V_77 ;
T_26 * V_78 ;
char V_79 [ V_80 ] ;
if ( V_20 ) {
F_44 ( 2 , V_56 , NULL ) ;
}
V_50 = 1 ;
for ( V_75 = F_72 ( V_74 ) ; V_75 != NULL ;
V_75 = F_73 ( V_75 ) ) {
V_76 = ( T_24 * ) V_75 -> V_81 ;
printf ( L_96 , V_50 ++ , V_76 -> T_13 ) ;
if ( V_76 -> V_82 != NULL )
printf ( L_97 , V_76 -> V_82 ) ;
else
printf ( L_98 ) ;
if ( V_76 -> V_83 != NULL )
printf ( L_97 , V_76 -> V_83 ) ;
else
printf ( L_98 ) ;
printf ( L_99 , V_76 -> type ) ;
for ( V_77 = F_74 ( V_76 -> V_84 , 0 ) ; V_77 != NULL ;
V_77 = F_75 ( V_77 ) ) {
if ( V_77 != F_74 ( V_76 -> V_84 , 0 ) )
printf ( L_100 ) ;
V_78 = ( T_26 * ) V_77 -> V_81 ;
switch( V_78 -> V_85 ) {
case V_86 :
if ( F_76 ( V_87 , & V_78 -> V_77 . V_88 , V_79 ,
V_80 ) ) {
printf ( L_101 , V_79 ) ;
} else {
printf ( L_102 ) ;
}
break;
case V_89 :
if ( F_76 ( V_90 , & V_78 -> V_77 . V_91 ,
V_79 , V_80 ) ) {
printf ( L_101 , V_79 ) ;
} else {
printf ( L_103 ) ;
}
break;
default:
printf ( L_104 , V_78 -> V_85 ) ;
}
}
if ( V_76 -> V_92 )
printf ( L_105 ) ;
else
printf ( L_106 ) ;
printf ( L_6 ) ;
}
}
static void
F_77 ( T_22 * V_23 )
{
T_19 * V_93 ;
T_21 * V_62 ;
const T_7 * V_94 ;
if ( V_20 ) {
F_44 ( 2 , V_56 , NULL ) ;
}
if ( V_23 -> V_71 )
printf ( L_107 ) ;
else
printf ( L_108 ) ;
for ( V_93 = V_23 -> V_73 ; V_93 != NULL ;
V_93 = F_73 ( V_93 ) ) {
V_62 = ( T_21 * ) V_93 -> V_81 ;
if ( V_62 -> V_64 != NULL )
V_94 = V_62 -> V_64 ;
else
V_94 = L_109 ;
printf ( L_110 , V_62 -> V_61 , V_62 -> T_13 ,
V_94 ) ;
}
}
static int
F_78 ( T_3 V_95 )
{
T_19 * V_74 , * V_75 , * V_96 = NULL , * V_97 ;
T_24 * V_76 ;
T_27 * V_98 ;
int V_57 ;
T_7 * V_58 ;
T_12 * V_59 ;
char V_65 [ V_44 ] ;
struct V_99 V_100 ;
V_74 = F_46 ( & V_57 , & V_58 ) ;
if ( V_74 == NULL ) {
switch ( V_57 ) {
case V_101 :
case V_102 :
F_14 ( L_101 , V_58 ) ;
F_17 ( V_58 ) ;
break;
case V_103 :
F_14 ( L_111 ) ;
break;
}
return V_57 ;
}
for ( V_75 = F_72 ( V_74 ) ; V_75 != NULL ; V_75 = F_73 ( V_75 ) ) {
V_76 = ( T_24 * ) V_75 -> V_81 ;
#ifdef F_57
V_59 = F_58 ( V_76 -> T_13 , V_70 , 0 , 0 , NULL , V_65 ) ;
#else
V_59 = F_64 ( V_76 -> T_13 , V_70 , 0 , 0 , V_65 ) ;
#endif
if ( V_59 ) {
V_98 = ( T_27 * ) F_50 ( sizeof( T_27 ) ) ;
V_98 -> T_13 = F_52 ( V_76 -> T_13 ) ;
V_98 -> V_59 = V_59 ;
V_96 = F_67 ( V_96 , V_98 ) ;
}
}
if ( ! V_96 ) {
F_14 ( L_111 ) ;
return 2 ;
}
if ( V_20 ) {
F_44 ( 2 , V_56 , NULL ) ;
}
if ( ! V_95 ) {
printf ( L_112 , L_113 , L_114 ,
L_115 ) ;
}
V_104 . V_105 = TRUE ;
while ( V_104 . V_105 ) {
for ( V_97 = F_72 ( V_96 ) ; V_97 != NULL ; V_97 = F_73 ( V_97 ) ) {
V_98 = ( T_27 * ) V_97 -> V_81 ;
F_79 ( V_98 -> V_59 , & V_100 ) ;
if ( ! V_95 ) {
printf ( L_116 , V_98 -> T_13 ,
V_100 . V_106 , V_100 . V_107 ) ;
} else {
printf ( L_117 , V_98 -> T_13 ,
V_100 . V_106 , V_100 . V_107 ) ;
fflush ( stdout ) ;
}
}
#ifdef F_2
F_80 ( 1 * 1000 ) ;
#else
F_81 ( 1 ) ;
#endif
}
for ( V_97 = F_72 ( V_96 ) ; V_97 != NULL ; V_97 = F_73 ( V_97 ) ) {
V_98 = ( T_27 * ) V_97 -> V_81 ;
F_39 ( V_98 -> V_59 ) ;
F_17 ( V_98 -> T_13 ) ;
F_17 ( V_98 ) ;
}
F_82 ( V_96 ) ;
F_83 ( V_74 ) ;
return 0 ;
}
static BOOL T_28
F_84 ( T_29 V_108 )
{
F_85 ( V_109 , V_110 ,
L_118 ) ;
F_85 ( V_109 , V_111 ,
L_119 , V_108 ) ;
if ( V_20 || ( V_108 != V_112 ) ) {
F_86 () ;
return TRUE ;
} else {
return FALSE ;
}
}
static void
F_84 ( int T_30 V_22 )
{
F_86 () ;
}
static void
F_87 ( T_3 V_113 )
{
if ( ! V_20 && V_113 ) {
fprintf ( V_13 , L_120 , V_104 . V_114 ) ;
fflush ( V_13 ) ;
}
}
static void
F_88 ( void )
{
F_87 ( V_115 ) ;
V_116 = FALSE ;
}
static void
F_89 ( int T_30 V_22 )
{
int V_117 = V_24 ;
if ( V_118 )
V_116 = TRUE ;
else
F_88 () ;
V_24 = V_117 ;
}
static void
F_90 ( int V_66 )
{
#ifdef F_2
F_91 () ;
#ifdef F_92
printf ( L_121 ) ;
F_93 () ;
#endif
#endif
exit ( V_66 ) ;
}
static void
F_94 ( void )
{
if ( F_95 () ) {
T_31 V_119 [ 2 ] = { V_120 , V_121 } ;
int V_122 = sizeof( V_119 ) / sizeof( T_31 ) ;
T_9 V_23 = F_21 () ;
F_19 ( L_122 ) ;
if ( F_96 ( V_123 , 1 , 0 , 0 , 0 ) == - 1 ) {
F_14 ( L_123 , F_23 ( V_24 ) ) ;
}
F_97 ( V_23 , V_124 , V_122 , V_119 , V_125 ) ;
F_97 ( V_23 , V_126 , V_122 , V_119 , V_125 ) ;
if ( F_22 ( V_23 ) ) {
F_14 ( L_57 , F_23 ( V_24 ) ) ;
}
F_19 ( L_124 ) ;
F_43 () ;
F_19 ( L_125 ) ;
F_97 ( V_23 , V_127 , V_122 , V_119 , V_125 ) ;
if ( F_22 ( V_23 ) ) {
F_14 ( L_57 , F_23 ( V_24 ) ) ;
}
F_19 ( L_126 ) ;
F_24 ( V_23 ) ;
}
}
static void
F_98 ( T_3 V_128 , struct V_129 * V_130 , struct V_131 * V_132 )
{
if ( V_128 ) {
V_132 -> V_133 = F_99 ( V_132 -> V_133 ) ;
V_132 -> V_134 = F_99 ( V_132 -> V_134 ) ;
V_132 -> V_135 = F_99 ( V_132 -> V_135 ) ;
V_132 -> V_136 = F_99 ( V_132 -> V_136 ) ;
}
if ( V_130 -> V_137 == 2 &&
( V_130 -> V_138 < 3 ||
( V_130 -> V_138 == 3 && V_132 -> V_135 > V_132 -> V_136 ) ) ) {
V_4 V_139 ;
V_139 = V_132 -> V_136 ;
V_132 -> V_136 = V_132 -> V_135 ;
V_132 -> V_135 = V_139 ;
}
}
static T_32
F_100 ( int V_140 , char * V_141 , T_11 V_142 , T_3 T_33 V_22 )
{
#ifdef F_2
if ( T_33 ) {
return F_101 ( V_140 , V_141 , ( int ) V_142 , 0 ) ;
} else {
return - 1 ;
}
#else
return F_102 ( V_140 , V_141 , V_142 ) ;
#endif
}
static void * F_103 ( void * V_143 )
{
T_34 * V_144 ;
#ifdef F_2
BOOL V_145 ;
T_29 V_146 , V_147 , V_148 ;
#else
T_11 V_148 ;
int V_146 ;
#endif
V_144 = ( T_34 * ) V_143 ;
while ( V_144 -> V_149 == V_150 ) {
F_104 ( V_144 -> V_151 ) ;
F_105 ( V_144 -> V_152 ) ;
V_148 = 0 ;
while ( V_148 < V_144 -> V_153 ) {
if ( ( V_144 -> V_154 )
#ifndef F_2
|| 1
#endif
)
{
V_146 = F_100 ( V_144 -> V_155 , V_144 -> V_156 + V_148 ,
V_144 -> V_153 - V_148 , V_144 -> V_154 ) ;
if ( V_146 <= 0 ) {
if ( V_146 == 0 ) {
V_144 -> V_149 = V_157 ;
V_148 = 0 ;
break;
} else {
V_144 -> V_149 = V_158 ;
V_148 = - 1 ;
break;
}
} else {
V_148 += V_146 ;
}
}
#ifdef F_2
else
{
V_145 = F_106 ( V_144 -> V_159 , V_144 -> V_156 + V_148 ,
V_144 -> V_153 - V_148 ,
& V_146 , NULL ) ;
V_148 += V_146 ;
if ( ! V_145 ) {
V_147 = F_107 () ;
if ( V_147 == V_160 ) {
continue;
} else if ( V_147 == V_161 || V_147 == V_162 || V_147 == V_163 ) {
V_144 -> V_149 = V_157 ;
V_148 = 0 ;
break;
}
V_144 -> V_149 = V_158 ;
V_148 = - 1 ;
break;
} else if ( V_146 == 0 && V_144 -> V_153 > 0 ) {
V_144 -> V_149 = V_157 ;
V_148 = 0 ;
break;
}
}
#endif
}
V_144 -> V_164 = V_148 ;
if ( V_144 -> V_164 >= V_144 -> V_153 ) {
F_108 ( V_144 -> V_165 , V_144 -> V_156 ) ;
}
F_109 ( V_144 -> V_152 ) ;
}
return NULL ;
}
static int
F_110 ( int V_140 )
{
T_35 V_166 ;
struct V_3 V_167 ;
F_111 ( & V_166 ) ;
F_112 ( V_140 , & V_166 ) ;
V_167 . V_7 = V_168 / 1000000 ;
V_167 . V_8 = V_168 % 1000000 ;
return F_113 ( V_140 + 1 , & V_166 , NULL , NULL , & V_167 ) ;
}
static int
F_114 ( char * V_169 , T_34 * V_144 , char * V_26 , int V_170 )
{
char * V_171 = V_169 + 4 ;
struct V_172 V_173 ;
char V_141 [ 16 ] ;
char * V_174 ;
unsigned long V_175 ;
T_11 V_53 ;
int V_176 ;
memset ( & V_173 , 0 , sizeof( V_173 ) ) ;
V_174 = strchr ( V_171 , ':' ) ;
if ( V_174 == NULL ) {
V_53 = strlen ( V_171 ) ;
V_175 = V_177 ;
}
else {
V_53 = V_174 - V_171 ;
V_175 = strtoul ( V_174 + 1 , & V_174 , 10 ) ;
if ( * V_174 || V_175 > 65535 ) {
goto V_178;
}
}
if ( V_53 > 15 ) {
goto V_178;
}
strncpy ( V_141 , V_171 , V_53 ) ;
V_141 [ V_53 ] = '\0' ;
if ( ! F_115 ( V_87 , V_141 , & V_173 . V_179 ) ) {
goto V_178;
}
V_173 . V_180 = V_87 ;
V_173 . V_181 = F_116 ( ( V_182 ) V_175 ) ;
if ( ( ( V_176 = ( int ) F_117 ( V_87 , V_183 , 0 ) ) < 0 ) ||
( F_118 ( V_176 , (struct V_184 * ) & V_173 , sizeof( V_173 ) ) < 0 ) ) {
#ifdef F_2
T_36 V_185 = NULL ;
int V_186 ;
V_186 = F_119 () ;
F_120 ( V_187 |
V_188 |
V_189 ,
NULL , V_186 , F_121 ( V_190 , V_191 ) ,
( T_36 ) & V_185 , 0 , NULL ) ;
#endif
F_26 ( V_26 , V_170 ,
L_127
#ifdef F_2
L_128 , V_186 , V_185 ? ( char * ) V_185 : L_129 ) ;
if ( V_185 )
F_122 ( V_185 ) ;
#else
L_130 , V_24 , strerror ( V_24 ) ) ;
#endif
V_144 -> V_149 = V_158 ;
if ( V_176 >= 0 )
F_123 ( V_176 , TRUE ) ;
return - 1 ;
}
void
F_123 ( int V_140 , T_3 T_33 V_22 )
{
#ifdef F_2
if ( T_33 ) {
F_124 ( V_140 ) ;
}
#else
F_125 ( V_140 ) ;
#endif
}
static void
F_126 ( char * V_169 ,
T_34 * V_144 ,
struct V_129 * V_130 ,
char * V_26 , int V_170 )
{
#ifndef F_2
T_37 V_192 ;
struct V_193 V_173 ;
#else
char * V_194 , * V_195 ;
T_38 * V_58 ;
#endif
T_32 V_146 ;
int V_176 , V_196 ;
T_11 V_148 ;
V_4 V_197 = 0 ;
V_144 -> V_155 = - 1 ;
#ifdef F_2
V_144 -> V_159 = V_198 ;
#endif
F_85 ( V_109 , V_111 , L_131 , V_169 ) ;
if ( strcmp ( V_169 , L_132 ) == 0 ) {
#ifndef F_2
V_176 = 0 ;
#else
V_144 -> V_159 = F_127 ( V_199 ) ;
#endif
} else if ( ! strncmp ( V_169 , L_133 , 4 ) ) {
if ( ( V_176 = F_114 ( V_169 , V_144 , V_26 , V_170 ) ) < 0 ) {
return;
}
} else {
#ifndef F_2
if ( F_128 ( V_169 , & V_192 ) < 0 ) {
if ( V_24 == V_200 || V_24 == V_201 )
V_144 -> V_149 = V_202 ;
else {
F_26 ( V_26 , V_170 ,
L_134
L_135 , F_23 ( V_24 ) ) ;
V_144 -> V_149 = V_158 ;
}
return;
}
if ( F_129 ( V_192 . V_203 ) ) {
V_176 = F_130 ( V_169 , V_204 | V_205 , 0000 ) ;
if ( V_176 == - 1 ) {
F_26 ( V_26 , V_170 ,
L_134
L_136 , F_23 ( V_24 ) ) ;
V_144 -> V_149 = V_158 ;
return;
}
} else if ( F_131 ( V_192 . V_203 ) ) {
V_176 = F_117 ( V_206 , V_183 , 0 ) ;
if ( V_176 == - 1 ) {
F_26 ( V_26 , V_170 ,
L_134
L_137 , F_23 ( V_24 ) ) ;
V_144 -> V_149 = V_158 ;
return;
}
V_173 . V_207 = V_206 ;
if ( F_132 ( V_173 . V_208 , V_169 , sizeof V_173 . V_208 ) > sizeof V_173 . V_208 ) {
F_26 ( V_26 , V_170 ,
L_138
L_139 ) ;
V_144 -> V_149 = V_158 ;
F_125 ( V_176 ) ;
return;
}
V_146 = F_118 ( V_176 , (struct V_184 * ) & V_173 , sizeof V_173 ) ;
if ( V_146 == - 1 ) {
F_26 ( V_26 , V_170 ,
L_138
L_140 , F_23 ( V_24 ) ) ;
V_144 -> V_149 = V_158 ;
F_125 ( V_176 ) ;
return;
}
} else {
if ( F_133 ( V_192 . V_203 ) ) {
V_144 -> V_149 = V_202 ;
} else {
F_26 ( V_26 , V_170 ,
L_141
L_142 , V_169 ) ;
V_144 -> V_149 = V_158 ;
}
return;
}
#else
#define F_134 "\\pipe\\"
V_194 = F_52 ( V_169 ) ;
if ( ( V_195 = strstr ( V_194 , L_143 ) ) == V_194 ) {
V_195 = strchr ( V_194 + 3 , '\\' ) ;
if ( V_195 && F_135 ( V_195 , F_134 , strlen ( F_134 ) ) != 0 )
V_195 = NULL ;
}
F_17 ( V_194 ) ;
if ( ! V_195 ) {
F_26 ( V_26 , V_170 ,
L_141
L_144 , V_169 ) ;
V_144 -> V_149 = V_202 ;
return;
}
while ( 1 ) {
V_144 -> V_159 = F_136 ( F_137 ( V_169 ) , V_209 , 0 , NULL ,
V_210 , 0 , NULL ) ;
if ( V_144 -> V_159 != V_198 )
break;
if ( F_107 () != V_211 ) {
F_120 ( V_187 | V_188 | V_189 ,
NULL , F_107 () , 0 , ( T_36 ) & V_58 , 0 , NULL ) ;
F_26 ( V_26 , V_170 ,
L_145
L_146 ,
V_169 , F_138 ( V_58 ) , F_107 () ) ;
F_122 ( V_58 ) ;
V_144 -> V_149 = V_158 ;
return;
}
if ( ! F_139 ( F_137 ( V_169 ) , 30 * 1000 ) ) {
F_120 ( V_187 | V_188 | V_189 ,
NULL , F_107 () , 0 , ( T_36 ) & V_58 , 0 , NULL ) ;
F_26 ( V_26 , V_170 ,
L_147
L_148 ,
V_169 , F_138 ( V_58 ) , F_107 () ) ;
F_122 ( V_58 ) ;
V_144 -> V_149 = V_158 ;
return;
}
}
#endif
}
V_144 -> V_212 = TRUE ;
#ifdef F_2
if ( V_144 -> V_154 )
#endif
{
V_148 = 0 ;
while ( V_148 < sizeof V_197 ) {
V_196 = F_110 ( V_176 ) ;
if ( V_196 < 0 ) {
F_26 ( V_26 , V_170 ,
L_149 , F_23 ( V_24 ) ) ;
goto error;
} else if ( V_196 > 0 ) {
V_146 = F_100 ( V_176 , ( ( char * ) & V_197 ) + V_148 ,
sizeof V_197 - V_148 ,
V_144 -> V_154 ) ;
if ( V_146 <= 0 ) {
if ( V_146 == 0 )
F_26 ( V_26 , V_170 , L_150 ) ;
else
F_26 ( V_26 , V_170 , L_151 ,
F_23 ( V_24 ) ) ;
goto error;
}
V_148 += V_146 ;
}
}
}
#ifdef F_2
else {
#if F_140 ( 2 , 31 , 0 )
F_141 ( L_152 , & F_103 , V_144 ) ;
#else
F_142 ( & F_103 , V_144 , FALSE , NULL ) ;
#endif
V_144 -> V_156 = ( char * ) & V_197 ;
V_144 -> V_164 = 0 ;
V_144 -> V_153 = sizeof( V_197 ) ;
F_108 ( V_144 -> V_151 , V_144 -> V_156 ) ;
F_104 ( V_144 -> V_165 ) ;
if ( V_144 -> V_164 <= 0 ) {
if ( V_144 -> V_164 == 0 )
F_26 ( V_26 , V_170 , L_150 ) ;
else
F_26 ( V_26 , V_170 , L_151 ,
F_23 ( V_24 ) ) ;
goto error;
}
}
#endif
switch ( V_197 ) {
case V_213 :
case V_214 :
V_144 -> V_215 = FALSE ;
V_144 -> V_216 = FALSE ;
V_144 -> V_217 = V_197 == V_214 ;
break;
case V_218 :
V_144 -> V_215 = FALSE ;
V_144 -> V_216 = TRUE ;
break;
case V_219 :
case V_220 :
V_144 -> V_215 = TRUE ;
V_144 -> V_216 = FALSE ;
V_144 -> V_217 = V_197 == V_220 ;
break;
case V_221 :
V_144 -> V_215 = TRUE ;
V_144 -> V_216 = TRUE ;
break;
default:
F_26 ( V_26 , V_170 , L_153 ) ;
goto error;
}
#ifdef F_2
if ( V_144 -> V_154 )
#endif
{
V_148 = 0 ;
while ( V_148 < sizeof( struct V_129 ) ) {
V_196 = F_110 ( V_176 ) ;
if ( V_196 < 0 ) {
F_26 ( V_26 , V_170 ,
L_149 , F_23 ( V_24 ) ) ;
goto error;
} else if ( V_196 > 0 ) {
V_146 = F_100 ( V_176 , ( ( char * ) V_130 ) + V_148 ,
sizeof( struct V_129 ) - V_148 ,
V_144 -> V_154 ) ;
if ( V_146 <= 0 ) {
if ( V_146 == 0 )
F_26 ( V_26 , V_170 , L_154 ) ;
else
F_26 ( V_26 , V_170 , L_155 ,
F_23 ( V_24 ) ) ;
goto error;
}
V_148 += V_146 ;
}
}
}
#ifdef F_2
else {
V_144 -> V_156 = ( char * ) V_130 ;
V_144 -> V_164 = 0 ;
V_144 -> V_153 = sizeof( struct V_129 ) ;
F_108 ( V_144 -> V_151 , V_144 -> V_156 ) ;
F_104 ( V_144 -> V_165 ) ;
if ( V_144 -> V_164 <= 0 ) {
if ( V_144 -> V_164 == 0 )
F_26 ( V_26 , V_170 , L_154 ) ;
else
F_26 ( V_26 , V_170 , L_156 ,
F_23 ( V_24 ) ) ;
goto error;
}
}
#endif
if ( V_144 -> V_215 ) {
V_130 -> V_137 = F_143 ( V_130 -> V_137 ) ;
V_130 -> V_138 = F_143 ( V_130 -> V_138 ) ;
V_130 -> V_222 = F_99 ( V_130 -> V_222 ) ;
V_130 -> V_223 = F_99 ( V_130 -> V_223 ) ;
}
V_144 -> V_35 = V_130 -> V_223 ;
if ( V_130 -> V_137 < 2 ) {
F_26 ( V_26 , V_170 , L_157 ) ;
goto error;
}
V_144 -> V_224 = V_225 ;
V_144 -> V_149 = V_150 ;
V_144 -> V_155 = V_176 ;
return;
error:
F_85 ( V_109 , V_111 , L_158 , V_26 ) ;
V_144 -> V_149 = V_158 ;
F_123 ( V_176 , V_144 -> V_154 ) ;
V_144 -> V_155 = - 1 ;
}
static int
F_144 ( T_39 * V_226 , T_34 * V_144 , T_40 * V_81 , char * V_26 , int V_170 )
{
struct V_227 V_228 ;
enum { V_229 , V_230 , V_231 , V_232 ,
V_233 } V_234 ;
#ifdef F_2
#if ! F_140 ( 2 , 31 , 18 )
T_41 V_235 ;
#endif
T_42 V_236 ;
T_38 * V_58 ;
#endif
T_32 V_146 ;
#ifdef F_145
F_85 ( V_109 , V_111 , L_159 ) ;
#endif
switch ( V_144 -> V_224 ) {
case V_225 :
#ifdef F_2
if ( F_146 ( V_144 -> V_152 ) ) {
#endif
V_144 -> V_224 = V_237 ;
V_144 -> V_153 = V_144 -> V_216 ?
sizeof( struct V_238 ) : sizeof( struct V_131 ) ;
V_144 -> V_164 = 0 ;
#ifdef F_2
V_144 -> V_156 = ( char * ) & V_144 -> V_239 ;
F_108 ( V_144 -> V_151 , V_144 -> V_156 ) ;
F_109 ( V_144 -> V_152 ) ;
}
#endif
case V_237 :
#ifdef F_2
if ( V_144 -> V_154 )
#endif
{
V_146 = F_100 ( V_144 -> V_155 , ( ( char * ) & V_144 -> V_239 ) + V_144 -> V_164 ,
V_144 -> V_153 - V_144 -> V_164 , V_144 -> V_154 ) ;
if ( V_146 <= 0 ) {
if ( V_146 == 0 )
V_234 = V_231 ;
else
V_234 = V_232 ;
break;
}
V_144 -> V_164 += V_146 ;
}
#ifdef F_2
else {
#if F_140 ( 2 , 31 , 18 )
V_236 = F_147 ( V_144 -> V_165 , V_168 ) ;
#else
F_148 ( & V_235 ) ;
F_149 ( & V_235 , V_168 ) ;
V_236 = F_150 ( V_144 -> V_165 , & V_235 ) ;
#endif
if ( V_144 -> V_149 == V_157 ) {
V_234 = V_231 ;
break;
} else if ( V_144 -> V_149 == V_158 ) {
V_234 = V_232 ;
break;
}
if ( ! V_236 ) {
return 0 ;
}
}
#endif
if ( V_144 -> V_164 < V_144 -> V_153 )
return 0 ;
V_234 = V_229 ;
break;
case V_240 :
#ifdef F_2
if ( F_146 ( V_144 -> V_152 ) ) {
#endif
V_144 -> V_224 = V_241 ;
V_144 -> V_153 = V_144 -> V_239 . V_130 . V_135 ;
V_144 -> V_164 = 0 ;
#ifdef F_2
V_144 -> V_156 = ( char * ) V_81 ;
F_108 ( V_144 -> V_151 , V_144 -> V_156 ) ;
F_109 ( V_144 -> V_152 ) ;
}
#endif
case V_241 :
#ifdef F_2
if ( V_144 -> V_154 )
#endif
{
V_146 = F_100 ( V_144 -> V_155 ,
V_81 + V_144 -> V_164 ,
V_144 -> V_153 - V_144 -> V_164 ,
V_144 -> V_154 ) ;
if ( V_146 <= 0 ) {
if ( V_146 == 0 )
V_234 = V_231 ;
else
V_234 = V_232 ;
break;
}
V_144 -> V_164 += V_146 ;
}
#ifdef F_2
else {
#if F_140 ( 2 , 31 , 18 )
V_236 = F_147 ( V_144 -> V_165 , V_168 ) ;
#else
F_148 ( & V_235 ) ;
F_149 ( & V_235 , V_168 ) ;
V_236 = F_150 ( V_144 -> V_165 , & V_235 ) ;
#endif
if ( V_144 -> V_149 == V_157 ) {
V_234 = V_231 ;
break;
} else if ( V_144 -> V_149 == V_158 ) {
V_234 = V_232 ;
break;
}
if ( ! V_236 ) {
return 0 ;
}
}
#endif
if ( V_144 -> V_164 < V_144 -> V_153 )
return 0 ;
V_234 = V_230 ;
break;
default:
F_26 ( V_26 , V_170 , L_160 ) ;
V_234 = V_233 ;
}
switch ( V_234 ) {
case V_229 :
F_98 ( V_144 -> V_215 , & V_144 -> V_242 ,
& V_144 -> V_239 . V_130 ) ;
if ( V_144 -> V_239 . V_130 . V_135 > V_243 ) {
F_26 ( V_26 , V_170 , L_161 ,
V_226 -> V_114 + 1 , V_144 -> V_239 . V_130 . V_135 ) ;
break;
}
if ( V_144 -> V_239 . V_130 . V_135 ) {
V_144 -> V_224 = V_240 ;
return 0 ;
}
case V_230 :
V_228 . V_244 . V_7 = V_144 -> V_239 . V_130 . V_133 ;
V_228 . V_244 . V_8 = V_144 -> V_239 . V_130 . V_134 ;
V_228 . V_245 = V_144 -> V_239 . V_130 . V_135 ;
V_228 . V_53 = V_144 -> V_239 . V_130 . V_136 ;
if ( V_246 ) {
F_151 ( ( V_247 * ) V_144 , & V_228 , V_81 ) ;
} else {
F_152 ( ( V_247 * ) V_144 , & V_228 , V_81 ) ;
}
V_144 -> V_224 = V_225 ;
return 1 ;
case V_231 :
V_144 -> V_149 = V_157 ;
return - 1 ;
case V_232 :
#ifdef F_2
F_120 ( V_187 | V_188 | V_189 ,
NULL , F_107 () , 0 , ( T_36 ) & V_58 , 0 , NULL ) ;
F_26 ( V_26 , V_170 ,
L_162 ,
F_138 ( V_58 ) , F_107 () ) ;
F_122 ( V_58 ) ;
#else
F_26 ( V_26 , V_170 , L_163 ,
F_23 ( V_24 ) ) ;
#endif
case V_233 :
break;
}
V_144 -> V_149 = V_158 ;
return - 1 ;
}
static void F_153 ( T_39 * V_226 )
{
T_18 V_50 ;
T_34 * V_144 ;
F_85 ( V_109 , V_111 , L_164 ) ;
for ( V_50 = 0 ; V_50 < V_226 -> V_248 -> V_53 ; V_50 ++ ) {
V_144 = F_36 ( V_226 -> V_248 , T_34 * , V_50 ) ;
if ( V_144 -> V_155 >= 0 ) {
F_154 ( V_144 -> V_212 ) ;
F_123 ( V_144 -> V_155 , V_144 -> V_154 ) ;
V_144 -> V_155 = - 1 ;
}
#ifdef F_2
if ( V_144 -> V_159 != V_198 ) {
F_155 ( V_144 -> V_159 ) ;
V_144 -> V_159 = V_198 ;
}
#endif
if ( V_144 -> V_34 != NULL ) {
F_85 ( V_109 , V_111 , L_165 , ( void * ) V_144 -> V_34 ) ;
F_39 ( V_144 -> V_34 ) ;
V_144 -> V_34 = NULL ;
}
}
V_226 -> V_105 = FALSE ;
#ifdef F_2
F_91 () ;
#endif
}
static T_43
F_156 ( T_12 * V_34 , T_3 V_212 ,
const T_7 * T_13 , const T_7 * V_40 )
{
struct V_38 V_39 ;
F_85 ( V_109 , V_111 , L_166 , V_40 ) ;
if ( V_40 && ! V_212 ) {
if ( ! F_32 ( T_13 , V_34 , & V_39 , V_40 ) ) {
return V_249 ;
}
if ( F_157 ( V_34 , & V_39 ) < 0 ) {
#ifdef F_158
F_159 ( & V_39 ) ;
#endif
return V_250 ;
}
#ifdef F_158
F_159 ( & V_39 ) ;
#endif
}
return V_251 ;
}
static T_3
F_160 ( T_15 * V_45 , T_39 * V_226 , char * V_26 , int V_27 )
{
int V_57 ;
T_18 V_50 ;
T_34 * V_144 ;
T_16 V_46 ;
T_3 V_252 ;
F_85 ( V_109 , V_111 , L_167 ) ;
if ( ( V_45 -> V_253 == FALSE ) &&
( V_45 -> V_52 -> V_53 > 1 ) ) {
F_26 ( V_26 , V_27 ,
L_168 ) ;
return FALSE ;
}
if ( V_45 -> V_254 ) {
V_226 -> V_255 = F_161 ( & V_57 ) ;
} else {
V_226 -> V_255 = F_162 ( V_226 -> V_256 , L_169 ) ;
if ( V_226 -> V_255 == NULL ) {
V_57 = V_24 ;
}
}
if ( V_226 -> V_255 ) {
if ( V_45 -> V_253 ) {
char V_257 [ 100 ] ;
T_5 * V_258 ;
V_258 = F_163 ( L_54 ) ;
F_164 ( V_258 ) ;
F_26 ( V_257 , sizeof( V_257 ) , L_1 V_11 L_101 , V_12 ) ;
V_252 = F_165 ( V_259 , V_226 -> V_255 ,
NULL ,
NULL ,
V_258 -> V_17 ,
V_257 ,
- 1 ,
& V_226 -> V_260 ,
& V_57 ) ;
for ( V_50 = 0 ; V_252 && ( V_50 < V_45 -> V_52 -> V_53 ) ; V_50 ++ ) {
V_46 = F_36 ( V_45 -> V_52 , T_16 , V_50 ) ;
V_144 = F_36 ( V_226 -> V_248 , T_34 * , V_50 ) ;
if ( V_144 -> V_212 ) {
V_144 -> V_222 = V_144 -> V_242 . V_222 ;
} else {
V_144 -> V_222 = F_166 ( V_144 -> V_34 ) ;
}
V_252 = F_167 ( V_259 , V_104 . V_255 ,
NULL ,
V_46 . T_13 ,
V_46 . V_261 ,
V_46 . V_40 ,
V_258 -> V_17 ,
V_144 -> V_35 ,
V_144 -> V_222 ,
& ( V_104 . V_260 ) ,
0 ,
V_144 -> V_217 ? 9 : 6 ,
& V_104 . V_57 ) ;
}
F_168 ( V_258 , TRUE ) ;
} else {
V_144 = F_36 ( V_226 -> V_248 , T_34 * , 0 ) ;
if ( V_144 -> V_212 ) {
V_144 -> V_222 = V_144 -> V_242 . V_222 ;
} else {
V_144 -> V_222 = F_166 ( V_144 -> V_34 ) ;
}
V_252 = F_169 ( V_259 , V_226 -> V_255 , V_144 -> V_35 , V_144 -> V_222 ,
V_144 -> V_217 , & V_226 -> V_260 , & V_57 ) ;
}
if ( ! V_252 ) {
fclose ( V_226 -> V_255 ) ;
V_226 -> V_255 = NULL ;
}
}
if ( V_226 -> V_255 == NULL ) {
switch ( V_57 ) {
default:
if ( V_57 < 0 ) {
F_26 ( V_26 , V_27 ,
L_170
L_171 ,
V_45 -> V_262 , V_57 ) ;
} else {
F_26 ( V_26 , V_27 ,
L_170
L_172 ,
V_45 -> V_262 , F_23 ( V_57 ) ) ;
}
break;
}
return FALSE ;
}
return TRUE ;
}
static T_3
F_170 ( T_15 * V_45 , T_39 * V_226 , int * V_263 )
{
unsigned int V_50 ;
T_34 * V_144 ;
T_1 V_264 = F_1 () ;
F_85 ( V_109 , V_111 , L_173 ) ;
if ( V_45 -> V_254 ) {
return F_171 ( & V_45 -> V_262 , V_263 ) ;
} else {
if ( V_45 -> V_253 ) {
for ( V_50 = 0 ; V_50 < V_104 . V_248 -> V_53 ; V_50 ++ ) {
V_144 = F_36 ( V_104 . V_248 , T_34 * , V_50 ) ;
if ( ! V_144 -> V_212 ) {
T_1 V_265 , V_266 ;
struct V_99 V_267 ;
if ( F_79 ( V_144 -> V_34 , & V_267 ) >= 0 ) {
V_265 = V_144 -> V_268 ;
V_266 = V_267 . V_107 + V_144 -> V_269 + V_144 -> V_270 ;
} else {
V_265 = V_271 ;
V_266 = V_271 ;
}
F_172 ( V_259 , V_226 -> V_255 ,
V_50 ,
& V_226 -> V_260 ,
L_174 ,
V_272 ,
V_264 ,
V_265 ,
V_266 ,
V_263 ) ;
}
}
}
if ( fclose ( V_226 -> V_255 ) == V_273 ) {
if ( V_263 != NULL ) {
* V_263 = V_24 ;
}
return ( FALSE ) ;
} else {
return ( TRUE ) ;
}
}
}
static int
F_173 ( T_39 * V_226 ,
char * V_26 , int V_27 , T_34 * V_144 )
{
int V_274 ;
T_44 V_275 ;
T_40 V_276 [ V_243 ] ;
#ifndef F_2
int V_196 ;
#endif
V_275 = V_226 -> V_114 ;
if ( V_144 -> V_212 ) {
#ifdef F_145
F_85 ( V_109 , V_111 , L_175 ) ;
#endif
#ifndef F_2
V_196 = F_110 ( V_144 -> V_155 ) ;
if ( V_196 <= 0 ) {
if ( V_196 < 0 && V_24 != V_277 ) {
F_26 ( V_26 , V_27 ,
L_149 , F_23 ( V_24 ) ) ;
F_38 ( V_26 , V_37 ) ;
V_226 -> V_105 = FALSE ;
}
} else {
#endif
V_274 = F_144 ( V_226 , V_144 , V_276 , V_26 , V_27 ) ;
if ( V_274 < 0 ) {
V_226 -> V_105 = FALSE ;
}
#ifndef F_2
}
#endif
}
else
{
#ifdef F_174
#ifdef F_145
F_85 ( V_109 , V_111 , L_176 ) ;
#endif
if ( V_144 -> V_278 != - 1 ) {
V_196 = F_110 ( V_144 -> V_278 ) ;
if ( V_196 > 0 ) {
if ( V_246 ) {
V_274 = F_175 ( V_144 -> V_34 , 1 , F_151 , ( V_247 * ) V_144 ) ;
} else {
V_274 = F_175 ( V_144 -> V_34 , 1 , F_152 , ( V_247 * ) V_144 ) ;
}
if ( V_274 < 0 ) {
if ( V_274 == - 1 ) {
V_144 -> V_279 = TRUE ;
}
V_226 -> V_105 = FALSE ;
}
} else {
if ( V_196 < 0 && V_24 != V_277 ) {
F_26 ( V_26 , V_27 ,
L_149 , F_23 ( V_24 ) ) ;
F_38 ( V_26 , V_37 ) ;
V_226 -> V_105 = FALSE ;
}
}
}
else
#endif
{
#if 1
#ifdef F_145
F_85 ( V_109 , V_111 , L_177 ) ;
#endif
#ifdef F_2
if ( V_246 ) {
V_274 = F_175 ( V_144 -> V_34 , 1 , F_151 , ( V_247 * ) V_144 ) ;
} else {
V_274 = F_175 ( V_144 -> V_34 , 1 , F_152 , ( V_247 * ) V_144 ) ;
}
#else
if ( V_246 ) {
V_274 = F_175 ( V_144 -> V_34 , - 1 , F_151 , ( V_247 * ) V_144 ) ;
} else {
V_274 = F_175 ( V_144 -> V_34 , - 1 , F_152 , ( V_247 * ) V_144 ) ;
}
#endif
if ( V_274 < 0 ) {
if ( V_274 == - 1 ) {
V_144 -> V_279 = TRUE ;
}
V_226 -> V_105 = FALSE ;
}
#else
#ifdef F_145
F_85 ( V_109 , V_111 , L_178 ) ;
#endif
{
int V_280 ;
struct V_227 * V_281 ;
V_247 * V_282 ;
V_280 = 0 ;
while( V_226 -> V_105 &&
( V_280 = F_176 ( V_144 -> V_34 , & V_281 , & V_282 ) ) == 1 ) {
if ( V_246 ) {
F_151 ( ( V_247 * ) V_144 , V_281 , V_282 ) ;
} else {
F_152 ( ( V_247 * ) V_144 , V_281 , V_282 ) ;
}
}
if ( V_280 < 0 ) {
V_144 -> V_279 = TRUE ;
V_226 -> V_105 = FALSE ;
}
}
#endif
}
}
#ifdef F_145
F_85 ( V_109 , V_111 , L_179 , V_274 , F_177 ( V_274 , L_54 , L_180 ) ) ;
#endif
return V_226 -> V_114 - V_275 ;
}
static T_5 *
F_178 ( const char * T_10 )
{
T_7 * V_283 ;
T_5 * V_284 ;
V_283 = strchr ( T_10 , '{' ) ;
if ( V_283 == NULL )
return F_163 ( T_10 ) ;
V_284 = F_163 ( V_283 + 1 ) ;
V_283 = strchr ( V_284 -> V_17 , '}' ) ;
if ( V_283 == NULL )
return V_284 ;
V_284 = F_179 ( V_284 , V_283 - V_284 -> V_17 ) ;
return V_284 ;
}
static T_3
F_180 ( T_15 * V_45 , int * V_256 ,
char * V_26 , int V_27 )
{
char * V_285 ;
T_7 * V_286 ;
T_7 * V_287 ;
T_3 V_288 ;
F_85 ( V_109 , V_111 , L_181 ,
( V_45 -> V_262 ) ? V_45 -> V_262 : L_182 ) ;
if ( V_45 -> V_262 != NULL ) {
V_286 = F_52 ( V_45 -> V_262 ) ;
if ( V_45 -> V_289 == TRUE ) {
if ( V_45 -> V_254 ) {
F_26 ( V_26 , V_27 ,
L_183 ) ;
F_17 ( V_286 ) ;
return FALSE ;
}
if ( strcmp ( V_286 , L_132 ) == 0 ) {
* V_256 = 1 ;
#ifdef F_2
F_181 ( 1 , V_290 ) ;
#endif
}
}
else {
if ( V_45 -> V_254 ) {
* V_256 = F_182 ( V_286 ,
( V_45 -> V_291 ) ? V_45 -> V_292 : 0 ,
V_45 -> V_293 ) ;
if ( * V_256 != - 1 ) {
F_17 ( V_286 ) ;
V_286 = F_52 ( F_183 () ) ;
}
} else {
* V_256 = F_130 ( V_286 , V_294 | V_290 | V_295 | V_296 ,
( V_45 -> V_293 ) ? 0640 : 0600 ) ;
}
}
V_288 = FALSE ;
} else {
if ( V_297 . V_52 -> V_53 > 1 ) {
V_287 = F_53 ( L_184 , V_297 . V_52 -> V_53 ) ;
} else {
T_7 * V_298 ;
V_298 = F_184 ( F_36 ( V_297 . V_52 , T_16 , 0 ) . V_299 ) ;
#ifdef F_2
if ( strncmp ( L_185 , V_298 , 5 ) == 0 )
{
T_5 * T_10 ;
T_10 = F_178 ( V_298 ) ;
F_17 ( V_298 ) ;
V_298 = F_52 ( T_10 -> V_17 ) ;
F_168 ( T_10 , TRUE ) ;
}
#endif
if ( V_45 -> V_253 ) {
V_287 = F_185 ( L_186 , V_298 , NULL ) ;
} else{
V_287 = F_185 ( L_187 , V_298 , NULL ) ;
}
F_17 ( V_298 ) ;
}
* V_256 = F_186 ( & V_285 , V_287 ) ;
F_17 ( V_287 ) ;
V_286 = F_52 ( V_285 ) ;
V_288 = TRUE ;
}
if ( * V_256 == - 1 ) {
if ( V_288 ) {
F_26 ( V_26 , V_27 ,
L_188
L_189 , V_286 , F_23 ( V_24 ) ) ;
} else {
if ( V_45 -> V_254 ) {
F_187 () ;
}
F_26 ( V_26 , V_27 ,
L_190
L_189 , V_286 ,
F_23 ( V_24 ) ) ;
}
F_17 ( V_286 ) ;
return FALSE ;
}
if ( V_45 -> V_262 != NULL ) {
F_17 ( V_45 -> V_262 ) ;
}
V_45 -> V_262 = V_286 ;
return TRUE ;
}
static T_3
F_188 ( T_15 * V_45 ,
T_45 * V_300 ,
T_45 * V_301 ,
T_45 * V_302 )
{
T_18 V_50 ;
T_34 * V_144 ;
T_16 V_46 ;
T_3 V_252 ;
if ( V_45 -> V_254 ) {
if ( V_300 != NULL &&
F_189 ( V_300 , ++ V_104 . V_303 ) ) {
V_104 . V_105 = FALSE ;
return FALSE ;
}
if ( F_190 ( & V_104 . V_255 , & V_45 -> V_262 ,
& V_104 . V_256 , & V_104 . V_57 ) ) {
V_104 . V_260 = 0 ;
if ( V_45 -> V_253 ) {
char V_257 [ 100 ] ;
T_5 * V_258 ;
V_258 = F_163 ( L_54 ) ;
F_164 ( V_258 ) ;
F_26 ( V_257 , sizeof( V_257 ) , L_1 V_11 L_101 , V_12 ) ;
V_252 = F_165 ( V_259 , V_104 . V_255 ,
NULL ,
NULL ,
V_258 -> V_17 ,
V_257 ,
- 1 ,
& ( V_104 . V_260 ) ,
& V_104 . V_57 ) ;
for ( V_50 = 0 ; V_252 && ( V_50 < V_45 -> V_52 -> V_53 ) ; V_50 ++ ) {
V_46 = F_36 ( V_45 -> V_52 , T_16 , V_50 ) ;
V_144 = F_36 ( V_104 . V_248 , T_34 * , V_50 ) ;
V_252 = F_167 ( V_259 , V_104 . V_255 ,
NULL ,
V_46 . T_13 ,
V_46 . V_261 ,
V_46 . V_40 ,
V_258 -> V_17 ,
V_144 -> V_35 ,
V_144 -> V_222 ,
& ( V_104 . V_260 ) ,
0 ,
V_144 -> V_217 ? 9 : 6 ,
& V_104 . V_57 ) ;
}
F_168 ( V_258 , TRUE ) ;
} else {
V_144 = F_36 ( V_104 . V_248 , T_34 * , 0 ) ;
V_252 = F_169 ( V_259 , V_104 . V_255 , V_144 -> V_35 , V_144 -> V_222 ,
V_144 -> V_217 , & V_104 . V_260 , & V_104 . V_57 ) ;
}
if ( ! V_252 ) {
fclose ( V_104 . V_255 ) ;
V_104 . V_255 = NULL ;
V_104 . V_105 = FALSE ;
return FALSE ;
}
if ( V_301 )
F_191 ( V_301 ) ;
if ( V_302 )
F_191 ( V_302 ) ;
fflush ( V_104 . V_255 ) ;
if ( ! V_115 )
F_192 ( V_104 . V_304 ) ;
V_104 . V_304 = 0 ;
F_193 ( V_45 -> V_262 ) ;
} else {
V_104 . V_105 = FALSE ;
return FALSE ;
}
} else {
V_104 . V_105 = FALSE ;
return FALSE ;
}
return TRUE ;
}
static void *
F_194 ( void * V_143 )
{
T_34 * V_144 ;
char V_26 [ V_47 + 1 ] ;
V_144 = ( T_34 * ) V_143 ;
F_85 ( V_109 , V_110 , L_191 ,
V_144 -> V_305 ) ;
while ( V_104 . V_105 ) {
F_173 ( & V_104 , V_26 , sizeof( V_26 ) , V_144 ) ;
}
F_85 ( V_109 , V_110 , L_192 ,
V_144 -> V_305 ) ;
F_195 ( NULL ) ;
return ( NULL ) ;
}
static void
F_86 ( void )
{
#ifdef F_196
T_18 V_50 ;
T_34 * V_144 ;
for ( V_50 = 0 ; V_50 < V_104 . V_248 -> V_53 ; V_50 ++ ) {
V_144 = F_36 ( V_104 . V_248 , T_34 * , V_50 ) ;
if ( V_144 -> V_34 != NULL )
F_197 ( V_144 -> V_34 ) ;
}
#endif
V_104 . V_105 = FALSE ;
}
static void
F_198 ( char * V_26 , int V_306 , const char * V_307 ,
int V_57 , T_3 V_308 )
{
switch ( V_57 ) {
case V_309 :
F_26 ( V_26 , V_306 ,
L_193
L_194
L_195
L_196 ,
V_307 ) ;
break;
#ifdef F_199
case F_199 :
F_26 ( V_26 , V_306 ,
L_193
L_194
L_197
L_198
L_199 ,
V_307 ) ;
break;
#endif
default:
if ( V_308 ) {
F_26 ( V_26 , V_306 ,
L_200
L_201 ,
V_307 , F_23 ( V_57 ) ) ;
} else {
F_26 ( V_26 , V_306 ,
L_202
L_194
L_203 ,
V_307 , F_23 ( V_57 ) ) ;
}
break;
}
}
static void
F_152 ( V_247 * V_310 , const struct V_227 * V_228 ,
const V_247 * V_311 )
{
T_34 * V_144 = ( T_34 * ) ( void * ) V_310 ;
int V_57 ;
T_18 V_312 = V_144 -> V_217 ? 1000000000 : 1000000 ;
if ( ! V_104 . V_105 ) {
V_144 -> V_270 ++ ;
return;
}
if ( V_104 . V_255 ) {
T_3 V_252 ;
if ( V_297 . V_253 ) {
V_252 = F_200 ( V_259 , V_104 . V_255 ,
NULL ,
V_228 -> V_244 . V_7 , V_228 -> V_244 . V_8 ,
V_228 -> V_245 , V_228 -> V_53 ,
V_144 -> V_305 ,
V_312 ,
V_311 , 0 ,
& V_104 . V_260 , & V_57 ) ;
} else {
V_252 = F_201 ( V_259 , V_104 . V_255 ,
V_228 -> V_244 . V_7 , V_228 -> V_244 . V_8 ,
V_228 -> V_245 , V_228 -> V_53 ,
V_311 ,
& V_104 . V_260 , & V_57 ) ;
}
if ( ! V_252 ) {
V_104 . V_105 = FALSE ;
V_104 . V_57 = V_57 ;
V_144 -> V_269 ++ ;
} else {
F_85 ( V_109 , V_110 ,
L_204 ,
V_228 -> V_245 , V_144 -> V_305 ) ;
V_104 . V_114 ++ ;
V_144 -> V_268 ++ ;
if ( ( V_104 . V_313 > 0 ) && ( V_104 . V_114 >= V_104 . V_313 ) ) {
V_104 . V_105 = FALSE ;
}
}
}
}
static void
F_151 ( V_247 * V_310 , const struct V_227 * V_228 ,
const V_247 * V_311 )
{
T_34 * V_144 = ( T_34 * ) ( void * ) V_310 ;
T_46 * V_314 ;
T_3 V_315 ;
if ( ! V_104 . V_105 ) {
V_144 -> V_270 ++ ;
return;
}
V_314 = ( T_46 * ) F_50 ( sizeof( T_46 ) ) ;
if ( V_314 == NULL ) {
V_144 -> V_269 ++ ;
return;
}
V_314 -> V_144 = V_144 ;
V_314 -> V_228 = * V_228 ;
V_314 -> V_311 = ( V_247 * ) F_50 ( V_228 -> V_245 ) ;
if ( V_314 -> V_311 == NULL ) {
V_144 -> V_269 ++ ;
F_17 ( V_314 ) ;
return;
}
memcpy ( V_314 -> V_311 , V_311 , V_228 -> V_245 ) ;
F_202 ( V_316 ) ;
if ( ( ( V_317 == 0 ) || ( V_318 < V_317 ) ) &&
( ( V_319 == 0 ) || ( V_320 < V_319 ) ) ) {
V_315 = FALSE ;
F_203 ( V_316 , V_314 ) ;
V_318 += V_228 -> V_245 ;
V_320 += 1 ;
} else {
V_315 = TRUE ;
}
F_204 ( V_316 ) ;
if ( V_315 ) {
V_144 -> V_269 ++ ;
F_17 ( V_314 -> V_311 ) ;
F_17 ( V_314 ) ;
F_85 ( V_109 , V_110 ,
L_205 ,
V_228 -> V_245 , V_144 -> V_305 ) ;
} else {
V_144 -> V_268 ++ ;
F_85 ( V_109 , V_110 ,
L_206 ,
V_228 -> V_245 , V_144 -> V_305 ) ;
}
F_85 ( V_109 , V_110 ,
L_207 V_321 L_208 V_321 L_209 ,
V_318 , V_320 ) ;
}
static int
F_205 ( const char * T_10 , const char * V_322 )
{
int V_323 = 0 , type , V_324 ;
T_7 * * V_325 = NULL ;
V_325 = F_206 ( V_322 , L_100 , 2 ) ;
if ( V_325 [ 0 ] )
V_323 = atoi ( V_325 [ 0 ] ) ;
if ( V_325 [ 1 ] ) {
type = F_207 ( V_325 [ 1 ] ) ;
if ( type == - 1 ) {
V_324 = V_326 ;
goto V_327;
}
}
else
type = - 1 ;
V_324 = F_208 () ;
if ( V_324 ) {
F_14 ( L_210 , abs ( V_324 ) , F_23 ( abs ( V_324 ) ) ) ;
V_324 = 2 ;
goto V_327;
}
V_324 = F_209 ( T_10 , V_323 , type ) ;
if ( V_324 ) {
F_14 ( L_211 , abs ( V_324 ) , F_23 ( abs ( V_324 ) ) ) ;
V_324 = 2 ;
goto V_327;
}
if ( V_20 )
F_44 ( 2 , V_56 , NULL ) ;
V_324 = 0 ;
V_327:
F_210 ( V_325 ) ;
return V_324 ;
}
int
main ( int V_328 , char * V_329 [] )
{
T_5 * V_15 ;
T_5 * V_16 ;
int V_322 ;
T_3 V_330 = FALSE ;
#ifdef F_2
T_47 V_331 ;
#else
struct V_332 V_333 , V_334 ;
#endif
T_3 V_335 = TRUE ;
T_3 V_336 ;
struct V_99 V_267 ;
T_48 V_337 ;
T_3 V_338 = FALSE ;
T_3 V_339 = FALSE ;
#ifdef F_9
T_3 V_340 = FALSE ;
#endif
T_3 V_341 = FALSE ;
T_7 * V_342 = NULL ;
T_3 V_95 = FALSE ;
T_3 V_343 = FALSE ;
int V_66 , V_344 = 0 ;
T_44 V_50 ;
T_18 V_51 ;
#if F_8 ( V_345 ) && F_8 ( V_346 )
struct V_347 V_348 ;
#endif
T_5 * V_17 ;
V_15 = F_163 ( L_212 ) ;
F_211 ( V_15 , NULL , NULL ) ;
V_16 = F_163 ( L_213 ) ;
F_212 ( V_16 , NULL ) ;
F_213 ( L_1 V_11 L_2
L_6
L_101
L_6
L_101 ,
V_12 , V_15 -> V_17 , V_16 -> V_17 ) ;
#ifdef F_2
F_214 ( V_328 , V_329 ) ;
F_215 () ;
F_216 () ;
#endif
#ifdef F_10
#define F_217 "A:"
#define F_218 "r"
#define F_219 "u"
#else
#define F_217 ""
#define F_218 ""
#define F_219 ""
#endif
#ifdef F_11
#define F_220 "m:"
#else
#define F_220 ""
#endif
#if F_8 ( F_2 ) || F_8 ( F_7 )
#define F_221 "B:"
#else
#define F_221 ""
#endif
#ifdef F_7
#define F_222 "I"
#else
#define F_222 ""
#endif
#ifdef F_9
#define F_223 "d"
#else
#define F_223 ""
#endif
#define F_224 "a:" OPTSTRING_A "b:" OPTSTRING_B "C:c:" OPTSTRING_d "Df:ghi:" OPTSTRING_I "k:L" OPTSTRING_m "MN:npPq" OPTSTRING_r "Ss:t" OPTSTRING_u "vw:y:Z:"
#ifdef F_225
if ( ( V_349 = F_226 ( L_214 , L_215 ) ) == NULL ) {
fprintf ( V_13 , L_216 ) ;
exit ( 1 ) ;
}
#endif
#if F_8 ( V_345 ) && F_8 ( V_346 )
if ( F_227 ( & V_348 ) == 0 ) {
if ( strcmp ( V_348 . V_350 , L_217 ) == 0 ||
strcmp ( V_348 . V_350 , L_218 ) == 0 ||
strcmp ( V_348 . V_350 , L_219 ) == 0 )
V_351 = TRUE ;
}
#endif
for ( V_50 = 1 ; V_50 < V_328 ; V_50 ++ ) {
if ( strcmp ( L_220 , V_329 [ V_50 ] ) == 0 ) {
V_20 = TRUE ;
V_95 = TRUE ;
#ifdef F_2
F_181 ( 2 , V_290 ) ;
#endif
}
}
V_337 =
( T_48 ) (
V_352 |
V_353 |
V_354 |
V_355 |
V_110 |
V_111 |
V_356 |
V_357 ) ;
F_228 ( NULL ,
V_337 ,
V_358 , NULL ) ;
F_228 ( V_359 ,
V_337 ,
V_358 , NULL ) ;
F_228 ( V_360 ,
V_337 ,
V_358 , NULL ) ;
F_228 ( V_109 ,
V_337 ,
V_358 , NULL ) ;
V_104 . V_248 = F_229 ( FALSE , FALSE , sizeof( T_34 * ) ) ;
#if ! F_140 ( 2 , 31 , 0 )
F_230 ( NULL ) ;
#endif
#ifdef F_2
F_231 () ;
F_232 ( F_233 ( 1 , 1 ) , & V_331 ) ;
F_234 ( F_84 , TRUE ) ;
#else
memset ( & V_333 , 0 , sizeof( V_333 ) ) ;
V_333 . V_361 = F_84 ;
V_333 . V_362 = 0 ;
F_235 ( & V_333 . V_363 ) ;
V_332 ( V_364 , & V_333 , NULL ) ;
V_332 ( V_365 , & V_333 , NULL ) ;
V_332 ( V_366 , & V_333 , NULL ) ;
V_332 ( V_367 , NULL , & V_334 ) ;
if ( V_334 . V_361 == V_368 )
V_332 ( V_367 , & V_333 , NULL ) ;
#ifdef F_236
V_333 . V_361 = F_89 ;
V_333 . V_362 = V_369 ;
F_235 ( & V_333 . V_363 ) ;
V_332 ( F_236 , & V_333 , NULL ) ;
#endif
#endif
F_237 () ;
#ifdef F_42
F_94 () ;
#endif
F_238 ( & V_297 ) ;
V_297 . V_370 = TRUE ;
V_297 . V_291 = TRUE ;
V_297 . V_20 = V_20 ;
while ( ( V_322 = F_239 ( V_328 , V_329 , F_224 ) ) != - 1 ) {
switch ( V_322 ) {
case 'h' :
F_6 ( TRUE ) ;
F_90 ( 0 ) ;
break;
case 'v' :
{
F_12 ( V_15 , V_16 ) ;
F_168 ( V_15 , TRUE ) ;
F_168 ( V_16 , TRUE ) ;
F_90 ( 0 ) ;
break;
}
case 'a' :
case 'b' :
case 'c' :
case 'f' :
case 'g' :
case 'i' :
case 'n' :
case 'p' :
case 'P' :
case 's' :
case 'w' :
case 'y' :
#ifdef F_10
case 'u' :
case 'r' :
case 'A' :
#endif
#ifdef F_11
case 'm' :
#endif
#if F_8 ( F_2 ) || F_8 ( F_7 )
case 'B' :
#endif
#ifdef F_7
case 'I' :
#endif
V_66 = F_240 ( & V_297 , V_322 , V_371 , & V_335 ) ;
if ( V_66 != 0 ) {
F_90 ( V_66 ) ;
}
break;
case 'Z' :
V_20 = TRUE ;
#ifdef F_2
F_181 ( 2 , V_290 ) ;
if ( strcmp ( V_371 , V_372 ) != 0 ) {
V_373 = F_53 ( V_374 , V_371 ) ;
V_375 = F_136 ( F_137 ( V_373 ) ,
V_209 , 0 , NULL , V_210 , 0 , NULL ) ;
if ( V_375 == V_198 ) {
F_85 ( V_109 , V_110 ,
L_221 ,
V_373 ) ;
F_90 ( 1 ) ;
}
}
#endif
break;
case 'q' :
V_115 = TRUE ;
break;
case 't' :
V_246 = TRUE ;
break;
case 'D' :
V_338 = TRUE ;
V_344 ++ ;
break;
case 'L' :
V_339 = TRUE ;
V_344 ++ ;
break;
#ifdef F_9
case 'd' :
V_340 = TRUE ;
V_344 ++ ;
break;
#endif
case 'S' :
V_343 = TRUE ;
V_344 ++ ;
break;
case 'k' :
V_341 = TRUE ;
V_342 = V_371 ;
V_344 ++ ;
break;
case 'M' :
V_95 = TRUE ;
break;
case 'C' :
V_317 = F_241 ( V_371 , L_222 ) ;
break;
case 'N' :
V_319 = F_241 ( V_371 , L_223 ) ;
break;
default:
F_14 ( L_224 , V_329 [ V_376 - 1 ] ) ;
case '?' :
V_330 = TRUE ;
break;
}
}
if ( ! V_330 ) {
V_328 -= V_376 ;
V_329 += V_376 ;
if ( V_328 >= 1 ) {
V_328 -- ;
V_329 ++ ;
}
if ( V_328 != 0 ) {
F_14 ( L_225 , V_329 [ 0 ] ) ;
V_330 = TRUE ;
}
}
if ( ( V_317 > 0 ) || ( V_319 > 0 ) ) {
V_246 = TRUE ;
}
if ( ( V_317 == 0 ) && ( V_319 == 0 ) ) {
V_317 = 1000 * 1000 ;
V_319 = 1000 ;
}
if ( V_330 ) {
F_6 ( FALSE ) ;
F_90 ( 1 ) ;
}
if ( V_344 > 1 ) {
F_14 ( L_226 ) ;
F_90 ( 1 ) ;
} else if ( V_344 == 1 ) {
if ( V_297 . V_254 ) {
F_14 ( L_227 ) ;
F_90 ( 1 ) ;
}
} else {
if ( V_297 . V_52 -> V_53 > 1 ) {
V_246 = TRUE ;
V_297 . V_253 = TRUE ;
}
if ( V_297 . V_254 ) {
if ( V_297 . V_262 == NULL ) {
F_14 ( L_228 ) ;
V_297 . V_254 = FALSE ;
}
if ( ! V_297 . V_377 && ! V_297 . V_378 ) {
F_14 ( L_229 ) ;
#if 0
global_capture_opts.multi_files_on = FALSE;
#endif
}
}
}
if ( V_338 ) {
T_19 * V_74 ;
int V_57 ;
T_7 * V_58 ;
V_74 = F_45 ( & V_57 , & V_58 ) ;
if ( V_74 == NULL ) {
switch ( V_57 ) {
case V_101 :
case V_102 :
F_14 ( L_101 , V_58 ) ;
F_17 ( V_58 ) ;
F_90 ( 2 ) ;
break;
case V_103 :
if ( ! V_95 ) {
F_14 ( L_111 ) ;
F_90 ( 2 ) ;
}
break;
}
}
if ( V_95 )
F_71 ( V_74 ) ;
else
F_242 ( V_74 ) ;
F_83 ( V_74 ) ;
F_90 ( 0 ) ;
}
if ( V_343 ) {
V_66 = F_78 ( V_95 ) ;
F_90 ( V_66 ) ;
}
if ( V_341 ) {
T_16 V_46 ;
if ( V_297 . V_52 -> V_53 != 1 ) {
F_14 ( L_230 ) ;
F_90 ( 2 ) ;
}
V_46 = F_36 ( V_297 . V_52 , T_16 , 0 ) ;
V_66 = F_205 ( V_46 . T_13 , V_342 ) ;
F_90 ( V_66 ) ;
}
V_66 = F_243 ( & V_297 , NULL ) ;
if ( V_66 != 0 ) {
F_90 ( V_66 ) ;
}
if ( V_20 ) {
for ( V_51 = 0 ; V_51 < V_297 . V_52 -> V_53 ; V_51 ++ ) {
T_16 V_46 ;
V_46 = F_36 ( V_297 . V_52 , T_16 , V_51 ) ;
F_85 ( V_109 , V_111 , L_231 ,
V_46 . T_13 ) ;
}
} else {
V_17 = F_163 ( L_54 ) ;
#ifdef F_2
if ( V_297 . V_52 -> V_53 < 2 )
#else
if ( V_297 . V_52 -> V_53 < 4 )
#endif
{
for ( V_51 = 0 ; V_51 < V_297 . V_52 -> V_53 ; V_51 ++ ) {
T_16 V_46 ;
V_46 = F_36 ( V_297 . V_52 , T_16 , V_51 ) ;
if ( V_51 > 0 ) {
if ( V_297 . V_52 -> V_53 > 2 ) {
F_244 ( V_17 , L_100 ) ;
}
F_244 ( V_17 , L_232 ) ;
if ( V_51 == V_297 . V_52 -> V_53 - 1 ) {
F_244 ( V_17 , L_233 ) ;
}
}
F_244 ( V_17 , L_234 , V_46 . V_299 ) ;
}
} else {
F_244 ( V_17 , L_235 , V_297 . V_52 -> V_53 ) ;
}
fprintf ( V_13 , L_236 , V_17 -> V_17 ) ;
F_168 ( V_17 , TRUE ) ;
}
if ( V_339 ) {
T_22 * V_23 ;
T_7 * V_58 ;
T_18 V_379 ;
for ( V_379 = 0 ; V_379 < V_297 . V_52 -> V_53 ; V_379 ++ ) {
T_16 V_46 ;
V_46 = F_36 ( V_297 . V_52 , T_16 , V_379 ) ;
V_23 = F_55 ( V_46 . T_13 ,
V_46 . T_23 , & V_58 ) ;
if ( V_23 == NULL ) {
F_14 ( L_237
L_238
L_239 , V_46 . T_13 , V_58 ) ;
F_17 ( V_58 ) ;
F_90 ( 2 ) ;
}
if ( V_23 -> V_73 == NULL ) {
F_14 ( L_240 , V_46 . T_13 ) ;
F_90 ( 2 ) ;
}
if ( V_95 )
F_77 ( V_23 ) ;
else
F_245 ( V_23 , V_46 . T_13 ,
V_46 . T_23 ) ;
F_246 ( V_23 ) ;
}
F_90 ( 0 ) ;
}
F_247 ( & V_297 , V_70 ) ;
#ifdef F_9
if ( V_340 ) {
F_35 ( & V_297 ) ;
F_90 ( 0 ) ;
}
#endif
F_248 ( & V_297 ) ;
fflush ( V_13 ) ;
if ( F_249 ( & V_297 , & V_336 , & V_267 ) == TRUE ) {
F_90 ( 0 ) ;
} else {
F_90 ( 1 ) ;
}
return 0 ;
}
static void
V_358 ( const char * V_380 , T_48 V_381 ,
const char * V_382 , T_42 T_49 V_22 )
{
T_50 V_383 ;
struct V_384 * V_385 ;
const char * V_386 ;
T_7 * V_21 ;
if ( ! ( V_381 & V_387 & ~ ( V_111 | V_110 ) ) ) {
#if ! F_8 ( F_92 ) && ! F_8 ( F_225 )
return;
#endif
}
time ( & V_383 ) ;
V_385 = localtime ( & V_383 ) ;
switch( V_381 & V_387 ) {
case V_352 :
V_386 = L_241 ;
break;
case V_353 :
V_386 = L_242 ;
break;
case V_354 :
V_386 = L_243 ;
break;
case V_355 :
V_386 = L_244 ;
break;
case V_110 :
V_386 = L_245 ;
break;
case V_111 :
V_386 = L_246 ;
break;
default:
fprintf ( V_13 , L_247 , V_381 ) ;
V_386 = NULL ;
F_250 () ;
}
if ( V_381 & V_355 ) {
V_21 = F_53 ( L_2 , V_382 ) ;
} else {
V_21 = F_53 ( L_248 ,
V_385 -> V_388 , V_385 -> V_389 , V_385 -> V_390 ,
V_380 != NULL ? V_380 : L_54 ,
V_386 , V_382 ) ;
}
#if F_8 ( F_92 ) || F_8 ( F_225 )
if ( ! ( V_381 & V_387 & ~ ( V_111 | V_110 ) ) ) {
#ifdef F_92
fprintf ( V_13 , L_101 , V_21 ) ;
fflush ( V_13 ) ;
#endif
#ifdef F_225
fprintf ( V_349 , L_101 , V_21 ) ;
fflush ( V_349 ) ;
#endif
F_17 ( V_21 ) ;
return;
}
#endif
if ( V_20 ) {
F_16 ( 2 , V_21 , L_54 ) ;
} else {
fprintf ( V_13 , L_101 , V_21 ) ;
fflush ( V_13 ) ;
}
F_17 ( V_21 ) ;
}
static void
F_192 ( unsigned int V_114 )
{
char V_391 [ V_392 + 1 + 1 ] ;
static unsigned int V_393 = 0 ;
if ( V_20 ) {
F_26 ( V_391 , sizeof( V_391 ) , L_249 , V_114 ) ;
F_85 ( V_109 , V_111 , L_250 , V_391 ) ;
F_44 ( 2 , V_394 , V_391 ) ;
} else {
V_393 += V_114 ;
fprintf ( V_13 , L_251 , V_393 ) ;
fflush ( V_13 ) ;
}
}
static void
F_193 ( const char * V_395 )
{
if ( V_20 ) {
F_85 ( V_109 , V_111 , L_252 , V_395 ) ;
F_44 ( 2 , V_396 , V_395 ) ;
} else {
#ifdef F_236
V_118 = TRUE ;
#endif
fprintf ( V_13 , L_253 , V_395 ) ;
fflush ( V_13 ) ;
#ifdef F_236
V_118 = FALSE ;
if ( V_116 )
F_88 () ;
#endif
}
}
static void
F_40 ( T_15 * V_45 , T_18 V_50 , const char * V_26 )
{
T_16 V_46 ;
char V_391 [ V_47 + 1 + 6 ] ;
if ( V_50 < V_45 -> V_52 -> V_53 ) {
if ( V_20 ) {
F_26 ( V_391 , sizeof( V_391 ) , L_254 , V_50 , V_26 ) ;
F_85 ( V_109 , V_111 , L_255 , V_26 ) ;
F_44 ( 2 , V_397 , V_391 ) ;
} else {
V_46 = F_36 ( V_45 -> V_52 , T_16 , V_50 ) ;
F_14 (
L_256
L_6
L_257
L_258 ,
V_46 . V_40 , V_46 . T_13 , V_26 ) ;
}
}
}
static void
F_38 ( const char * V_398 , const char * V_399 )
{
if ( V_20 ) {
F_85 ( V_109 , V_111 ,
L_259 , V_398 ) ;
F_85 ( V_109 , V_111 ,
L_260 , V_399 ) ;
F_16 ( 2 , V_398 , V_399 ) ;
} else {
F_14 ( L_101 , V_398 ) ;
if ( V_399 [ 0 ] != '\0' )
F_18 ( L_101 , V_399 ) ;
}
}
static void
F_251 ( V_4 V_268 , V_4 V_400 , V_4 V_401 , V_4 V_270 , T_7 * T_13 )
{
char V_391 [ V_392 + 1 + 1 ] ;
V_4 V_402 = V_400 + V_401 + V_270 ;
F_26 ( V_391 , sizeof( V_391 ) , L_249 , V_402 ) ;
if ( V_20 ) {
F_85 ( V_109 , V_111 ,
L_261 ,
T_13 , V_268 , V_402 , V_400 , V_401 , V_270 ) ;
F_44 ( 2 , V_403 , V_391 ) ;
} else {
fprintf ( V_13 ,
L_262 ,
T_13 , V_268 , V_402 , V_400 , V_401 , V_270 ,
V_268 ? 100.0 * V_268 / ( V_268 + V_402 ) : 0.0 ) ;
fflush ( V_13 ) ;
}
}
static T_3
F_252 ( void )
{
T_29 V_404 = 0 ;
T_3 V_234 ;
if ( ! V_20 ) {
return TRUE ;
}
if ( ! V_373 || ! V_375 ) {
F_85 ( V_109 , V_110 ,
L_263 ) ;
return FALSE ;
}
V_234 = F_253 ( V_375 , NULL , 0 , NULL , & V_404 , NULL ) ;
if ( ! V_234 || V_404 > 0 ) {
F_85 ( V_109 , V_110 ,
L_264 , V_373 ) ;
F_85 ( V_109 , V_111 ,
L_265 , V_373 ,
V_375 , V_234 , V_404 ) ;
return FALSE ;
} else {
return TRUE ;
}
}
