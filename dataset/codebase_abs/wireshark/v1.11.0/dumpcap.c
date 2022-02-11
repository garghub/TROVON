void
F_1 ( void )
{
int V_1 ;
T_1 T_2 V_2 ;
static const char V_3 [] = L_1 ;
V_1 = F_2 ( V_3 , V_4 ) ;
if ( V_1 < 0 )
return;
T_2 = F_3 ( V_1 , L_2 , strlen ( L_2 ) ) ;
F_4 ( V_1 ) ;
}
static T_3
F_5 ( void ) {
T_3 V_5 ;
#ifdef F_6
T_4 V_6 ;
#else
struct V_7 V_6 ;
#endif
#ifdef F_6
F_7 ( & V_6 ) ;
V_5 = ( ( ( T_3 ) ( V_8 ) V_6 . V_9 ) << 32 ) +
( V_8 ) V_6 . V_10 ;
V_5 /= 10 ;
V_5 -= F_8 ( 11644473600000000U ) ;
#else
F_9 ( & V_6 , NULL ) ;
V_5 = ( T_3 ) ( V_6 . V_11 ) * 1000000 +
( T_3 ) ( V_6 . V_12 ) ;
#endif
return V_5 ;
}
static void
F_10 ( T_5 V_13 )
{
T_6 * V_14 ;
if ( V_13 ) {
V_14 = stdout ;
fprintf ( V_14 ,
L_3 V_15 L_4
L_5
L_6 ,
V_16 ) ;
} else {
V_14 = V_17 ;
}
fprintf ( V_14 , L_7 ) ;
fprintf ( V_14 , L_8 ) ;
fprintf ( V_14 , L_9 ) ;
fprintf ( V_14 , L_10
L_11
L_12
L_13 ) ;
fprintf ( V_14 , L_14 ) ;
fprintf ( V_14 , L_15 ) ;
fprintf ( V_14 , L_16 ) ;
#ifdef F_11
fprintf ( V_14 , L_17 ) ;
#endif
#if F_12 ( F_6 ) || F_12 ( F_11 )
fprintf ( V_14 , L_18 , V_18 ) ;
#endif
fprintf ( V_14 , L_19 ) ;
fprintf ( V_14 , L_20 ) ;
fprintf ( V_14 , L_21 ) ;
#ifdef F_13
fprintf ( V_14 , L_22 ) ;
#endif
fprintf ( V_14 , L_23 ) ;
fprintf ( V_14 , L_24 ) ;
fprintf ( V_14 , L_25 ) ;
fprintf ( V_14 , L_8 ) ;
#ifdef F_14
fprintf ( V_14 , L_26 ) ;
fprintf ( V_14 , L_27 ) ;
fprintf ( V_14 , L_28 ) ;
fprintf ( V_14 , L_29 ) ;
#ifdef F_15
fprintf ( V_14 , L_30 ) ;
fprintf ( V_14 , L_31 ) ;
fprintf ( V_14 , L_32 ) ;
#endif
#endif
fprintf ( V_14 , L_33 ) ;
fprintf ( V_14 , L_34 ) ;
fprintf ( V_14 , L_35 ) ;
fprintf ( V_14 , L_36 ) ;
fprintf ( V_14 , L_37 ) ;
fprintf ( V_14 , L_38 ) ;
fprintf ( V_14 , L_39 ) ;
fprintf ( V_14 , L_40 ) ;
fprintf ( V_14 , L_41 ) ;
fprintf ( V_14 , L_42 ) ;
fprintf ( V_14 , L_43 ) ;
fprintf ( V_14 , L_44 ) ;
fprintf ( V_14 , L_45 ) ;
fprintf ( V_14 , L_46 ) ;
fprintf ( V_14 , L_47 ) ;
fprintf ( V_14 , L_48 ) ;
fprintf ( V_14 , L_8 ) ;
fprintf ( V_14 , L_49 ) ;
fprintf ( V_14 , L_50 ) ;
fprintf ( V_14 , L_51 ) ;
fprintf ( V_14 , L_52 ) ;
fprintf ( V_14 , L_53 ) ;
fprintf ( V_14 , L_54 ) ;
fprintf ( V_14 , L_55 ) ;
fprintf ( V_14 , L_56 ) ;
fprintf ( V_14 , L_8 ) ;
#ifdef F_16
fprintf ( V_14 , L_57 ) ;
fprintf ( V_14 , L_58 ) ;
fprintf ( V_14 , L_59 ) ;
fprintf ( V_14 , L_8 ) ;
#endif
fprintf ( V_14 , L_60 ) ;
fprintf ( V_14 , L_61 ) ;
fprintf ( V_14 , L_8 ) ;
fprintf ( V_14 , L_62 ) ;
}
static void
F_17 ( T_7 * V_19 , T_7 * V_20 )
{
printf (
L_3 V_15 L_4
L_8
L_4
L_4
L_4
L_6 ,
V_16 , F_18 () , V_19 -> V_21 , V_20 -> V_21 ) ;
}
void
F_19 ( const char * V_22 , ... )
{
T_8 V_23 ;
if ( V_24 ) {
T_9 * V_25 ;
va_start ( V_23 , V_22 ) ;
V_25 = F_20 ( V_22 , V_23 ) ;
F_21 ( 2 , V_25 , L_63 ) ;
F_22 ( V_25 ) ;
va_end ( V_23 ) ;
} else {
va_start ( V_23 , V_22 ) ;
fprintf ( V_17 , L_64 ) ;
vfprintf ( V_17 , V_22 , V_23 ) ;
fprintf ( V_17 , L_8 ) ;
va_end ( V_23 ) ;
}
}
void
F_23 ( const char * V_22 , ... )
{
T_8 V_23 ;
if ( V_24 ) {
T_9 * V_25 ;
va_start ( V_23 , V_22 ) ;
V_25 = F_20 ( V_22 , V_23 ) ;
F_21 ( 2 , V_25 , L_63 ) ;
F_22 ( V_25 ) ;
va_end ( V_23 ) ;
} else {
va_start ( V_23 , V_22 ) ;
vfprintf ( V_17 , V_22 , V_23 ) ;
fprintf ( V_17 , L_8 ) ;
va_end ( V_23 ) ;
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
F_24 ( const char * T_10 V_2 ) {
#endif
}
static void
F_25 ( void )
{
T_11 V_26 = F_26 () ;
F_24 ( L_65 ) ;
if ( F_27 ( V_26 ) ) {
F_19 ( L_66 , F_28 ( V_27 ) ) ;
}
F_24 ( L_67 ) ;
F_29 ( V_26 ) ;
}
static void
F_30 ( const char * V_28 ,
const char * T_12
#ifndef F_6
V_2
#endif
,
char * V_29 , T_13 V_30 ,
char * V_31 ,
T_13 V_32 )
{
#ifndef F_6
const char * V_33 ;
static const char V_34 [] = L_68 ;
#endif
F_31 ( V_29 , ( V_35 ) V_30 ,
L_69 , V_28 ) ;
#ifdef F_6
if ( ! V_36 ) {
F_31 ( V_31 , ( V_35 ) V_32 ,
L_8
L_70
L_8
L_71
L_8
L_72
L_8
L_73
L_8
L_72
L_8
L_74
L_8
L_75
L_76 ) ;
} else {
F_31 ( V_31 , ( V_35 ) V_32 ,
L_8
L_77
L_8
L_8
L_78
L_8
L_79
L_80 ,
T_12 ) ;
}
#else
if ( strncmp ( V_28 , V_34 , sizeof V_34 - 1 ) == 0 )
V_33 =
L_81
L_82
L_83
L_84
L_8
L_85
L_86
L_87
L_88
L_89 ;
else
V_33 = L_63 ;
F_31 ( V_31 , ( V_35 ) V_32 ,
L_90
L_91 , V_33 ) ;
#endif
}
static T_5
F_32 ( T_14 * V_37 , int V_38 ,
#ifdef F_33
char * T_15 V_2 ,
#else
char * T_15 ,
#endif
char * V_29 , T_13 V_30 ,
char * V_31 , T_13 V_32 )
{
char * V_39 ;
if ( V_38 == - 1 )
return TRUE ;
#ifdef F_33
if ( F_34 ( V_37 , V_38 ) == 0 )
return TRUE ;
V_39 = F_35 ( V_37 ) ;
#else
if ( F_36 ( V_37 , T_15 ) == V_38 )
return TRUE ;
V_39 =
L_92 ;
#endif
F_31 ( V_29 , ( V_35 ) V_30 , L_93 ,
V_39 ) ;
if ( strstr ( V_39 , L_94 ) == NULL )
F_31 ( V_31 , ( V_35 ) V_32 , V_40 ) ;
else
V_31 [ 0 ] = '\0' ;
return FALSE ;
}
static T_5
F_37 ( const char * T_12 , T_14 * V_37 ,
struct V_41 * V_42 , const char * V_43 )
{
T_16 V_44 , V_45 ;
T_9 V_46 [ V_47 ] ;
if ( F_38 ( T_12 , & V_44 , & V_45 , V_46 ) < 0 ) {
V_45 = 0 ;
}
if ( F_39 ( V_37 , V_42 , ( char * ) V_43 , 1 , V_45 ) < 0 )
return FALSE ;
return TRUE ;
}
static T_5
F_40 ( T_17 * V_48 )
{
T_18 V_49 ;
T_14 * V_37 ;
T_9 V_28 [ V_47 ] ;
char V_29 [ V_50 + 1 ] ;
char V_31 [ V_50 + 1 ] ;
struct V_41 V_42 ;
struct V_51 * V_52 ;
T_19 V_53 ;
T_20 V_54 ;
for ( V_54 = 0 ; V_54 < V_48 -> V_55 -> V_56 ; V_54 ++ ) {
V_49 = F_41 ( V_48 -> V_55 , T_18 , V_54 ) ;
V_37 = F_42 ( & V_49 , & V_28 ) ;
if ( V_37 == NULL ) {
F_30 ( V_28 ,
V_49 . T_15 ,
V_29 , sizeof V_29 ,
V_31 ,
sizeof V_31 ) ;
F_43 ( V_29 , V_31 ) ;
return FALSE ;
}
if ( ! F_32 ( V_37 , V_49 . V_38 , V_49 . T_15 ,
V_29 , sizeof V_29 ,
V_31 , sizeof V_31 ) ) {
F_44 ( V_37 ) ;
F_43 ( V_29 , V_31 ) ;
return FALSE ;
}
if ( ! F_37 ( V_49 . T_15 , V_37 , & V_42 ,
V_49 . V_43 ) ) {
F_44 ( V_37 ) ;
F_45 ( V_48 , V_54 , V_29 ) ;
return FALSE ;
}
F_44 ( V_37 ) ;
V_52 = V_42 . V_57 ;
for ( V_53 = 0 ; V_53 < V_42 . V_58 ; V_52 ++ , V_53 ++ )
printf ( L_4 , F_46 ( V_52 , V_53 ) ) ;
}
#ifndef F_47
F_48 () ;
#else
F_25 () ;
#endif
if ( V_24 ) {
F_49 ( 2 , V_59 , NULL ) ;
}
return TRUE ;
}
static int
F_36 ( T_14 * V_60 , const char * T_21
#ifndef F_50
V_2
#endif
)
{
int V_38 ;
#ifdef F_50
const char * V_61 ;
#endif
V_38 = F_51 ( V_60 ) ;
#ifdef F_50
V_61 = strchr ( T_21 , '/' ) ;
if ( V_61 == NULL )
V_61 = T_21 ;
if ( strncmp ( V_61 , L_95 , 2 ) == 0 ) {
if ( V_38 == 6 ) {
V_38 = 1 ;
}
} else if ( strncmp ( V_61 , L_96 , 2 ) == 0 ) {
if ( V_38 == 7 ) {
V_38 = 1 ;
}
} else if ( strncmp ( V_61 , L_97 , 2 ) == 0 ) {
if ( V_38 == 9 ) {
V_38 = 6 ;
}
} else if ( strncmp ( V_61 , L_98 , 2 ) == 0 ) {
if ( V_38 == 15 ) {
V_38 = 10 ;
}
} else if ( strncmp ( V_61 , L_99 , 2 ) == 0 ) {
if ( V_38 == 24 ) {
V_38 = 0 ;
}
}
#endif
return V_38 ;
}
static T_22 *
F_52 ( int V_62 )
{
T_22 * V_63 ;
const char * V_64 ;
V_63 = ( T_22 * ) F_53 ( sizeof ( T_22 ) ) ;
V_63 -> V_62 = V_62 ;
V_64 = F_54 ( V_62 ) ;
if ( V_64 != NULL )
V_63 -> T_15 = F_55 ( V_64 ) ;
else
V_63 -> T_15 = F_56 ( L_100 , V_62 ) ;
V_64 = F_57 ( V_62 ) ;
if ( V_64 != NULL )
V_63 -> V_65 = F_55 ( V_64 ) ;
else
V_63 -> V_65 = NULL ;
return V_63 ;
}
static T_23 *
F_58 ( const char * T_21 , T_5 T_24
#ifndef F_11
V_2
#endif
, char * * V_66 )
{
T_23 * V_26 ;
char V_67 [ V_47 ] ;
T_14 * V_60 ;
#ifdef F_11
int V_68 ;
#endif
int V_69 ;
#ifdef F_59
int * V_70 ;
int V_53 , V_71 ;
#endif
T_22 * V_63 ;
V_26 = ( T_23 * ) F_53 ( sizeof *V_26 ) ;
V_67 [ 0 ] = '\0' ;
#ifdef F_60
V_60 = F_61 ( T_21 , V_72 , 0 , 0 , NULL , V_67 ) ;
V_26 -> V_73 = FALSE ;
if ( V_60 == NULL ) {
if ( V_66 != NULL )
* V_66 = F_55 ( V_67 [ 0 ] == '\0' ? L_101 : V_67 ) ;
F_22 ( V_26 ) ;
return NULL ;
}
#elif F_12 ( F_11 )
V_60 = F_62 ( T_21 , V_67 ) ;
if ( V_60 == NULL ) {
if ( V_66 != NULL )
* V_66 = F_55 ( V_67 ) ;
F_22 ( V_26 ) ;
return NULL ;
}
V_68 = F_63 ( V_60 ) ;
if ( V_68 < 0 ) {
if ( V_68 == V_74 )
* V_66 = F_56 ( L_102 ,
F_35 ( V_60 ) ) ;
else
* V_66 = F_55 ( F_64 ( V_68 ) ) ;
F_44 ( V_60 ) ;
F_22 ( V_26 ) ;
return NULL ;
}
if ( V_68 == 0 )
V_26 -> V_73 = FALSE ;
else if ( V_68 == 1 ) {
V_26 -> V_73 = TRUE ;
if ( T_24 )
F_65 ( V_60 , 1 ) ;
} else {
if ( V_66 != NULL ) {
* V_66 = F_56 ( L_103 ,
V_68 ) ;
}
F_44 ( V_60 ) ;
F_22 ( V_26 ) ;
return NULL ;
}
V_68 = F_66 ( V_60 ) ;
if ( V_68 < 0 ) {
if ( V_66 != NULL ) {
if ( V_68 == V_74 )
* V_66 = F_56 ( L_104 ,
F_35 ( V_60 ) ) ;
else
* V_66 = F_55 ( F_64 ( V_68 ) ) ;
}
F_44 ( V_60 ) ;
F_22 ( V_26 ) ;
return NULL ;
}
#else
V_60 = F_67 ( T_21 , V_72 , 0 , 0 , V_67 ) ;
V_26 -> V_73 = FALSE ;
if ( V_60 == NULL ) {
if ( V_66 != NULL )
* V_66 = F_55 ( V_67 [ 0 ] == '\0' ? L_101 : V_67 ) ;
F_22 ( V_26 ) ;
return NULL ;
}
#endif
V_69 = F_36 ( V_60 , T_21 ) ;
#ifdef F_59
V_71 = F_68 ( V_60 , & V_70 ) ;
if ( V_71 == 0 || V_70 == NULL ) {
F_44 ( V_60 ) ;
if ( V_66 != NULL )
* V_66 = NULL ;
F_22 ( V_26 ) ;
return NULL ;
}
V_26 -> V_75 = NULL ;
for ( V_53 = 0 ; V_53 < V_71 ; V_53 ++ ) {
V_63 = F_52 ( V_70 [ V_53 ] ) ;
if ( V_70 [ V_53 ] == V_69 )
V_26 -> V_75 = F_69 ( V_26 -> V_75 ,
V_63 ) ;
else
V_26 -> V_75 = F_70 ( V_26 -> V_75 ,
V_63 ) ;
}
#ifdef F_71
F_72 ( V_70 ) ;
#else
#ifndef F_6
#define F_73 free
F_73 ( V_70 ) ;
#endif
#endif
#else
V_63 = F_52 ( V_69 ) ;
V_26 -> V_75 = F_70 ( V_26 -> V_75 ,
V_63 ) ;
#endif
F_44 ( V_60 ) ;
if ( V_66 != NULL )
* V_66 = NULL ;
return V_26 ;
}
static void
F_74 ( T_25 * V_76 )
{
int V_53 ;
T_25 * V_77 ;
T_26 * V_78 ;
T_27 * V_79 ;
T_28 * V_80 ;
char V_81 [ V_82 ] ;
if ( V_24 ) {
F_49 ( 2 , V_59 , NULL ) ;
}
V_53 = 1 ;
for ( V_77 = F_75 ( V_76 ) ; V_77 != NULL ;
V_77 = F_76 ( V_77 ) ) {
V_78 = ( T_26 * ) V_77 -> V_83 ;
printf ( L_105 , V_53 ++ , V_78 -> T_15 ) ;
if ( V_78 -> V_84 != NULL )
printf ( L_106 , V_78 -> V_84 ) ;
else
printf ( L_107 ) ;
if ( V_78 -> V_85 != NULL )
printf ( L_106 , V_78 -> V_85 ) ;
else
printf ( L_107 ) ;
printf ( L_108 , V_78 -> type ) ;
for ( V_79 = F_77 ( V_78 -> V_86 , 0 ) ; V_79 != NULL ;
V_79 = F_78 ( V_79 ) ) {
if ( V_79 != F_77 ( V_78 -> V_86 , 0 ) )
printf ( L_109 ) ;
V_80 = ( T_28 * ) V_79 -> V_83 ;
switch( V_80 -> V_87 ) {
case V_88 :
if ( F_79 ( V_89 , & V_80 -> V_79 . V_90 , V_81 ,
V_82 ) ) {
printf ( L_110 , V_81 ) ;
} else {
printf ( L_111 ) ;
}
break;
case V_91 :
if ( F_79 ( V_92 , & V_80 -> V_79 . V_93 ,
V_81 , V_82 ) ) {
printf ( L_110 , V_81 ) ;
} else {
printf ( L_112 ) ;
}
break;
default:
printf ( L_113 , V_80 -> V_87 ) ;
}
}
if ( V_78 -> V_94 )
printf ( L_114 ) ;
else
printf ( L_115 ) ;
printf ( L_8 ) ;
}
}
static void
F_80 ( T_23 * V_26 )
{
T_25 * V_95 ;
T_22 * V_63 ;
const T_9 * V_96 ;
if ( V_24 ) {
F_49 ( 2 , V_59 , NULL ) ;
}
if ( V_26 -> V_73 )
printf ( L_116 ) ;
else
printf ( L_117 ) ;
for ( V_95 = V_26 -> V_75 ; V_95 != NULL ;
V_95 = F_76 ( V_95 ) ) {
V_63 = ( T_22 * ) V_95 -> V_83 ;
if ( V_63 -> V_65 != NULL )
V_96 = V_63 -> V_65 ;
else
V_96 = L_118 ;
printf ( L_119 , V_63 -> V_62 , V_63 -> T_15 ,
V_96 ) ;
}
}
static int
F_81 ( T_5 V_97 )
{
T_25 * V_76 , * V_77 , * V_98 = NULL , * V_99 ;
T_26 * V_78 ;
T_29 * V_100 ;
int V_101 ;
T_9 * V_66 ;
T_14 * V_60 ;
char V_67 [ V_47 ] ;
struct V_102 V_103 ;
V_76 = F_82 ( & V_101 , & V_66 ) ;
if ( V_76 == NULL ) {
switch ( V_101 ) {
case V_104 :
case V_105 :
F_19 ( L_110 , V_66 ) ;
F_22 ( V_66 ) ;
break;
case V_106 :
F_19 ( L_120 ) ;
break;
}
return V_101 ;
}
for ( V_77 = F_75 ( V_76 ) ; V_77 != NULL ; V_77 = F_76 ( V_77 ) ) {
V_78 = ( T_26 * ) V_77 -> V_83 ;
#ifdef F_60
V_60 = F_61 ( V_78 -> T_15 , V_72 , 0 , 0 , NULL , V_67 ) ;
#else
V_60 = F_67 ( V_78 -> T_15 , V_72 , 0 , 0 , V_67 ) ;
#endif
if ( V_60 ) {
V_100 = ( T_29 * ) F_53 ( sizeof( T_29 ) ) ;
V_100 -> T_15 = F_55 ( V_78 -> T_15 ) ;
V_100 -> V_60 = V_60 ;
V_98 = F_70 ( V_98 , V_100 ) ;
}
}
if ( ! V_98 ) {
F_19 ( L_120 ) ;
return 2 ;
}
if ( V_24 ) {
F_49 ( 2 , V_59 , NULL ) ;
}
if ( ! V_97 ) {
printf ( L_121 , L_122 , L_123 ,
L_124 ) ;
}
V_107 . V_108 = TRUE ;
while ( V_107 . V_108 ) {
for ( V_99 = F_75 ( V_98 ) ; V_99 != NULL ; V_99 = F_76 ( V_99 ) ) {
V_100 = ( T_29 * ) V_99 -> V_83 ;
F_83 ( V_100 -> V_60 , & V_103 ) ;
if ( ! V_97 ) {
printf ( L_125 , V_100 -> T_15 ,
V_103 . V_109 , V_103 . V_110 ) ;
} else {
printf ( L_126 , V_100 -> T_15 ,
V_103 . V_109 , V_103 . V_110 ) ;
fflush ( stdout ) ;
}
}
#ifdef F_6
if ( ! F_84 () ) {
V_107 . V_108 = FALSE ;
}
F_85 ( 1 * 1000 ) ;
#else
F_86 ( 1 ) ;
#endif
}
for ( V_99 = F_75 ( V_98 ) ; V_99 != NULL ; V_99 = F_76 ( V_99 ) ) {
V_100 = ( T_29 * ) V_99 -> V_83 ;
F_44 ( V_100 -> V_60 ) ;
F_22 ( V_100 -> T_15 ) ;
F_22 ( V_100 ) ;
}
F_87 ( V_98 ) ;
F_88 ( V_76 ) ;
return 0 ;
}
static BOOL T_30
F_89 ( T_31 V_111 )
{
F_90 ( V_112 , V_113 ,
L_127 ) ;
F_90 ( V_112 , V_114 ,
L_128 , V_111 ) ;
if ( V_24 || ( V_111 != V_115 ) ) {
F_91 () ;
return TRUE ;
} else {
return FALSE ;
}
}
static void
F_89 ( int T_32 V_2 )
{
F_91 () ;
}
static void
F_92 ( T_5 V_116 )
{
if ( ! V_24 && V_116 ) {
fprintf ( V_17 , L_129 , V_107 . V_117 ) ;
fflush ( V_17 ) ;
}
}
static void
F_93 ( void )
{
F_92 ( V_118 ) ;
V_119 = FALSE ;
}
static void
F_94 ( int T_32 V_2 )
{
int V_120 = V_27 ;
if ( V_121 )
V_119 = TRUE ;
else
F_93 () ;
V_27 = V_120 ;
}
static void
F_95 ( int V_68 )
{
#ifdef F_6
F_96 () ;
#ifdef F_97
printf ( L_130 ) ;
F_98 () ;
#endif
#endif
exit ( V_68 ) ;
}
static void
F_99 ( void )
{
if ( F_100 () ) {
T_33 V_122 [ 2 ] = { V_123 , V_124 } ;
int V_125 = sizeof( V_122 ) / sizeof( T_33 ) ;
T_11 V_26 = F_26 () ;
F_24 ( L_131 ) ;
if ( F_101 ( V_126 , 1 , 0 , 0 , 0 ) == - 1 ) {
F_19 ( L_132 , F_28 ( V_27 ) ) ;
}
F_102 ( V_26 , V_127 , V_125 , V_122 , V_128 ) ;
F_102 ( V_26 , V_129 , V_125 , V_122 , V_128 ) ;
if ( F_27 ( V_26 ) ) {
F_19 ( L_66 , F_28 ( V_27 ) ) ;
}
F_24 ( L_133 ) ;
F_48 () ;
F_24 ( L_134 ) ;
F_102 ( V_26 , V_130 , V_125 , V_122 , V_128 ) ;
if ( F_27 ( V_26 ) ) {
F_19 ( L_66 , F_28 ( V_27 ) ) ;
}
F_24 ( L_135 ) ;
F_29 ( V_26 ) ;
}
}
static void
F_103 ( T_5 V_131 , struct V_132 * V_133 , struct V_134 * V_135 )
{
if ( V_131 ) {
V_135 -> V_136 = F_104 ( V_135 -> V_136 ) ;
V_135 -> V_137 = F_104 ( V_135 -> V_137 ) ;
V_135 -> V_138 = F_104 ( V_135 -> V_138 ) ;
V_135 -> V_139 = F_104 ( V_135 -> V_139 ) ;
}
if ( V_133 -> V_140 == 2 &&
( V_133 -> V_141 < 3 ||
( V_133 -> V_141 == 3 && V_135 -> V_138 > V_135 -> V_139 ) ) ) {
V_8 V_142 ;
V_142 = V_135 -> V_139 ;
V_135 -> V_139 = V_135 -> V_138 ;
V_135 -> V_138 = V_142 ;
}
}
static T_1
F_105 ( int V_143 , char * V_144 , T_13 V_145 , T_5 T_34 V_2 )
{
#ifdef F_6
if ( T_34 ) {
return F_106 ( V_143 , V_144 , ( int ) V_145 , 0 ) ;
} else {
return - 1 ;
}
#else
return F_107 ( V_143 , V_144 , V_145 ) ;
#endif
}
static void * F_108 ( void * V_146 )
{
T_35 * V_147 ;
#ifdef F_6
BOOL V_148 ;
T_31 V_149 , V_150 , V_151 ;
#else
T_13 V_151 ;
int V_149 ;
#endif
V_147 = ( T_35 * ) V_146 ;
while ( V_147 -> V_152 == V_153 ) {
F_109 ( V_147 -> V_154 ) ;
F_110 ( V_147 -> V_155 ) ;
V_151 = 0 ;
while ( V_151 < V_147 -> V_156 ) {
if ( ( V_147 -> V_157 )
#ifndef F_6
|| 1
#endif
)
{
V_149 = F_105 ( V_147 -> V_158 , V_147 -> V_159 + V_151 ,
V_147 -> V_156 - V_151 , V_147 -> V_157 ) ;
if ( V_149 <= 0 ) {
if ( V_149 == 0 ) {
V_147 -> V_152 = V_160 ;
V_151 = 0 ;
break;
} else {
V_147 -> V_152 = V_161 ;
V_151 = - 1 ;
break;
}
} else {
V_151 += V_149 ;
}
}
#ifdef F_6
else
{
V_148 = F_111 ( V_147 -> V_162 , V_147 -> V_159 + V_151 ,
V_147 -> V_156 - V_151 ,
& V_149 , NULL ) ;
V_151 += V_149 ;
if ( ! V_148 ) {
V_150 = F_112 () ;
if ( V_150 == V_163 ) {
continue;
} else if ( V_150 == V_164 || V_150 == V_165 || V_150 == V_166 ) {
V_147 -> V_152 = V_160 ;
V_151 = 0 ;
break;
}
V_147 -> V_152 = V_161 ;
V_151 = - 1 ;
break;
} else if ( V_149 == 0 && V_147 -> V_156 > 0 ) {
V_147 -> V_152 = V_160 ;
V_151 = 0 ;
break;
}
}
#endif
}
V_147 -> V_167 = V_151 ;
if ( V_147 -> V_167 >= V_147 -> V_156 ) {
F_113 ( V_147 -> V_168 , V_147 -> V_159 ) ;
}
F_114 ( V_147 -> V_155 ) ;
}
return NULL ;
}
static int
F_115 ( int V_143 )
{
T_36 V_169 ;
struct V_7 V_170 ;
F_116 ( & V_169 ) ;
F_117 ( V_143 , & V_169 ) ;
V_170 . V_11 = V_171 / 1000000 ;
V_170 . V_12 = V_171 % 1000000 ;
return F_118 ( V_143 + 1 , & V_169 , NULL , NULL , & V_170 ) ;
}
static int
F_119 ( char * V_172 , T_35 * V_147 , char * V_29 , int V_173 )
{
char * V_174 = V_172 + 4 ;
struct V_175 V_176 ;
char V_144 [ 16 ] ;
char * V_177 ;
unsigned long V_178 ;
T_13 V_56 ;
int V_1 ;
memset ( & V_176 , 0 , sizeof( V_176 ) ) ;
V_177 = strchr ( V_174 , ':' ) ;
if ( V_177 == NULL ) {
V_56 = strlen ( V_174 ) ;
V_178 = V_179 ;
}
else {
V_56 = V_177 - V_174 ;
V_178 = strtoul ( V_177 + 1 , & V_177 , 10 ) ;
if ( * V_177 || V_178 > 65535 ) {
goto V_180;
}
}
if ( V_56 > 15 ) {
goto V_180;
}
strncpy ( V_144 , V_174 , V_56 ) ;
V_144 [ V_56 ] = '\0' ;
if ( F_120 ( V_89 , V_144 , & V_176 . V_181 ) <= 0 ) {
goto V_180;
}
V_176 . V_182 = V_89 ;
V_176 . V_183 = F_121 ( ( V_184 ) V_178 ) ;
if ( ( ( V_1 = ( int ) F_122 ( V_89 , V_185 , 0 ) ) < 0 ) ||
( F_123 ( V_1 , (struct V_186 * ) & V_176 , sizeof( V_176 ) ) < 0 ) ) {
#ifdef F_6
T_37 V_187 = NULL ;
int V_188 ;
V_188 = F_124 () ;
F_125 ( V_189 |
V_190 |
V_191 ,
NULL , V_188 , F_126 ( V_192 , V_193 ) ,
( T_37 ) & V_187 , 0 , NULL ) ;
#endif
F_31 ( V_29 , V_173 ,
L_136
#ifdef F_6
L_137 , V_188 , V_187 ? ( char * ) V_187 : L_138 ) ;
if ( V_187 )
F_127 ( V_187 ) ;
#else
L_139 , V_27 , strerror ( V_27 ) ) ;
#endif
V_147 -> V_152 = V_161 ;
if ( V_1 >= 0 )
F_128 ( V_1 , TRUE ) ;
return - 1 ;
}
void
F_128 ( int V_143 , T_5 T_34 V_2 )
{
#ifdef F_6
if ( T_34 ) {
F_129 ( V_143 ) ;
}
#else
F_130 ( V_143 ) ;
#endif
}
static void
F_131 ( char * V_172 ,
T_35 * V_147 ,
struct V_132 * V_133 ,
char * V_29 , int V_173 )
{
#ifndef F_6
T_38 V_194 ;
struct V_195 V_176 ;
#else
char * V_196 , * V_197 ;
T_39 * V_66 ;
#endif
T_1 V_149 ;
int V_1 , V_198 ;
T_13 V_151 ;
V_8 V_199 = 0 ;
V_147 -> V_158 = - 1 ;
#ifdef F_6
V_147 -> V_162 = V_200 ;
#endif
F_90 ( V_112 , V_114 , L_140 , V_172 ) ;
if ( strcmp ( V_172 , L_141 ) == 0 ) {
#ifndef F_6
V_1 = 0 ;
#else
V_147 -> V_162 = F_132 ( V_201 ) ;
#endif
} else if ( ! strncmp ( V_172 , L_142 , 4 ) ) {
if ( ( V_1 = F_119 ( V_172 , V_147 , V_29 , V_173 ) ) < 0 ) {
return;
}
} else {
#ifndef F_6
if ( F_133 ( V_172 , & V_194 ) < 0 ) {
if ( V_27 == V_202 || V_27 == V_203 )
V_147 -> V_152 = V_204 ;
else {
F_31 ( V_29 , V_173 ,
L_143
L_144 , F_28 ( V_27 ) ) ;
V_147 -> V_152 = V_161 ;
}
return;
}
if ( F_134 ( V_194 . V_205 ) ) {
V_1 = F_135 ( V_172 , V_206 | V_207 , 0000 ) ;
if ( V_1 == - 1 ) {
F_31 ( V_29 , V_173 ,
L_143
L_145 , F_28 ( V_27 ) ) ;
V_147 -> V_152 = V_161 ;
return;
}
} else if ( F_136 ( V_194 . V_205 ) ) {
V_1 = F_122 ( V_208 , V_185 , 0 ) ;
if ( V_1 == - 1 ) {
F_31 ( V_29 , V_173 ,
L_143
L_146 , F_28 ( V_27 ) ) ;
V_147 -> V_152 = V_161 ;
return;
}
V_176 . V_209 = V_208 ;
if ( F_137 ( V_176 . V_210 , V_172 , sizeof V_176 . V_210 ) > sizeof V_176 . V_210 ) {
F_31 ( V_29 , V_173 ,
L_147
L_148 ) ;
V_147 -> V_152 = V_161 ;
F_130 ( V_1 ) ;
return;
}
V_149 = F_123 ( V_1 , (struct V_186 * ) & V_176 , sizeof V_176 ) ;
if ( V_149 == - 1 ) {
F_31 ( V_29 , V_173 ,
L_147
L_149 , F_28 ( V_27 ) ) ;
V_147 -> V_152 = V_161 ;
F_130 ( V_1 ) ;
return;
}
} else {
if ( F_138 ( V_194 . V_205 ) ) {
V_147 -> V_152 = V_204 ;
} else {
F_31 ( V_29 , V_173 ,
L_150
L_151 , V_172 ) ;
V_147 -> V_152 = V_161 ;
}
return;
}
#else
#define F_139 "\\pipe\\"
V_196 = F_55 ( V_172 ) ;
if ( ( V_197 = strstr ( V_196 , L_152 ) ) == V_196 ) {
V_197 = strchr ( V_196 + 3 , '\\' ) ;
if ( V_197 && F_140 ( V_197 , F_139 , strlen ( F_139 ) ) != 0 )
V_197 = NULL ;
}
F_22 ( V_196 ) ;
if ( ! V_197 ) {
F_31 ( V_29 , V_173 ,
L_150
L_153 , V_172 ) ;
V_147 -> V_152 = V_204 ;
return;
}
while ( 1 ) {
V_147 -> V_162 = F_141 ( F_142 ( V_172 ) , V_211 , 0 , NULL ,
V_212 , 0 , NULL ) ;
if ( V_147 -> V_162 != V_200 )
break;
if ( F_112 () != V_213 ) {
F_125 ( V_189 | V_190 | V_191 ,
NULL , F_112 () , 0 , ( T_37 ) & V_66 , 0 , NULL ) ;
F_31 ( V_29 , V_173 ,
L_154
L_155 ,
V_172 , F_143 ( V_66 ) , F_112 () ) ;
F_127 ( V_66 ) ;
V_147 -> V_152 = V_161 ;
return;
}
if ( ! F_144 ( F_142 ( V_172 ) , 30 * 1000 ) ) {
F_125 ( V_189 | V_190 | V_191 ,
NULL , F_112 () , 0 , ( T_37 ) & V_66 , 0 , NULL ) ;
F_31 ( V_29 , V_173 ,
L_156
L_157 ,
V_172 , F_143 ( V_66 ) , F_112 () ) ;
F_127 ( V_66 ) ;
V_147 -> V_152 = V_161 ;
return;
}
}
#endif
}
V_147 -> V_214 = TRUE ;
#ifdef F_6
if ( V_147 -> V_157 )
#endif
{
V_151 = 0 ;
while ( V_151 < sizeof V_199 ) {
V_198 = F_115 ( V_1 ) ;
if ( V_198 < 0 ) {
F_31 ( V_29 , V_173 ,
L_158 , F_28 ( V_27 ) ) ;
goto error;
} else if ( V_198 > 0 ) {
V_149 = F_105 ( V_1 , ( ( char * ) & V_199 ) + V_151 ,
sizeof V_199 - V_151 ,
V_147 -> V_157 ) ;
if ( V_149 <= 0 ) {
if ( V_149 == 0 )
F_31 ( V_29 , V_173 , L_159 ) ;
else
F_31 ( V_29 , V_173 , L_160 ,
F_28 ( V_27 ) ) ;
goto error;
}
V_151 += V_149 ;
}
}
}
#ifdef F_6
else {
#if F_145 ( 2 , 31 , 0 )
F_146 ( L_161 , & F_108 , V_147 ) ;
#else
F_147 ( & F_108 , V_147 , FALSE , NULL ) ;
#endif
V_147 -> V_159 = ( char * ) & V_199 ;
V_147 -> V_167 = 0 ;
V_147 -> V_156 = sizeof( V_199 ) ;
F_113 ( V_147 -> V_154 , V_147 -> V_159 ) ;
F_109 ( V_147 -> V_168 ) ;
if ( V_147 -> V_167 <= 0 ) {
if ( V_147 -> V_167 == 0 )
F_31 ( V_29 , V_173 , L_159 ) ;
else
F_31 ( V_29 , V_173 , L_160 ,
F_28 ( V_27 ) ) ;
goto error;
}
}
#endif
switch ( V_199 ) {
case V_215 :
case V_216 :
V_147 -> V_217 = FALSE ;
V_147 -> V_218 = FALSE ;
V_147 -> V_219 = V_199 == V_216 ;
break;
case V_220 :
V_147 -> V_217 = FALSE ;
V_147 -> V_218 = TRUE ;
break;
case V_221 :
case V_222 :
V_147 -> V_217 = TRUE ;
V_147 -> V_218 = FALSE ;
V_147 -> V_219 = V_199 == V_222 ;
break;
case V_223 :
V_147 -> V_217 = TRUE ;
V_147 -> V_218 = TRUE ;
break;
default:
F_31 ( V_29 , V_173 , L_162 ) ;
goto error;
}
#ifdef F_6
if ( V_147 -> V_157 )
#endif
{
V_151 = 0 ;
while ( V_151 < sizeof( struct V_132 ) ) {
V_198 = F_115 ( V_1 ) ;
if ( V_198 < 0 ) {
F_31 ( V_29 , V_173 ,
L_158 , F_28 ( V_27 ) ) ;
goto error;
} else if ( V_198 > 0 ) {
V_149 = F_105 ( V_1 , ( ( char * ) V_133 ) + V_151 ,
sizeof( struct V_132 ) - V_151 ,
V_147 -> V_157 ) ;
if ( V_149 <= 0 ) {
if ( V_149 == 0 )
F_31 ( V_29 , V_173 , L_163 ) ;
else
F_31 ( V_29 , V_173 , L_164 ,
F_28 ( V_27 ) ) ;
goto error;
}
V_151 += V_149 ;
}
}
}
#ifdef F_6
else {
V_147 -> V_159 = ( char * ) V_133 ;
V_147 -> V_167 = 0 ;
V_147 -> V_156 = sizeof( struct V_132 ) ;
F_113 ( V_147 -> V_154 , V_147 -> V_159 ) ;
F_109 ( V_147 -> V_168 ) ;
if ( V_147 -> V_167 <= 0 ) {
if ( V_147 -> V_167 == 0 )
F_31 ( V_29 , V_173 , L_163 ) ;
else
F_31 ( V_29 , V_173 , L_165 ,
F_28 ( V_27 ) ) ;
goto error;
}
}
#endif
if ( V_147 -> V_217 ) {
V_133 -> V_140 = F_148 ( V_133 -> V_140 ) ;
V_133 -> V_141 = F_148 ( V_133 -> V_141 ) ;
V_133 -> V_224 = F_104 ( V_133 -> V_224 ) ;
V_133 -> V_225 = F_104 ( V_133 -> V_225 ) ;
}
V_147 -> V_38 = V_133 -> V_225 ;
if ( V_133 -> V_140 < 2 ) {
F_31 ( V_29 , V_173 , L_166 ) ;
goto error;
}
V_147 -> V_226 = V_227 ;
V_147 -> V_152 = V_153 ;
V_147 -> V_158 = V_1 ;
return;
error:
F_90 ( V_112 , V_114 , L_167 , V_29 ) ;
V_147 -> V_152 = V_161 ;
F_128 ( V_1 , V_147 -> V_157 ) ;
V_147 -> V_158 = - 1 ;
}
static int
F_149 ( T_40 * V_228 , T_35 * V_147 , T_41 * V_83 , char * V_29 , int V_173 )
{
struct V_229 V_230 ;
enum { V_231 , V_232 , V_233 , V_234 ,
V_235 } V_236 ;
#ifdef F_6
#if ! F_145 ( 2 , 31 , 18 )
T_42 V_237 ;
#endif
T_43 V_238 ;
T_39 * V_66 ;
#endif
T_1 V_149 ;
#ifdef F_150
F_90 ( V_112 , V_114 , L_168 ) ;
#endif
switch ( V_147 -> V_226 ) {
case V_227 :
#ifdef F_6
if ( F_151 ( V_147 -> V_155 ) ) {
#endif
V_147 -> V_226 = V_239 ;
V_147 -> V_156 = V_147 -> V_218 ?
sizeof( struct V_240 ) : sizeof( struct V_134 ) ;
V_147 -> V_167 = 0 ;
#ifdef F_6
V_147 -> V_159 = ( char * ) & V_147 -> V_241 ;
F_113 ( V_147 -> V_154 , V_147 -> V_159 ) ;
F_114 ( V_147 -> V_155 ) ;
}
#endif
case V_239 :
#ifdef F_6
if ( V_147 -> V_157 )
#endif
{
V_149 = F_105 ( V_147 -> V_158 , ( ( char * ) & V_147 -> V_241 ) + V_147 -> V_167 ,
V_147 -> V_156 - V_147 -> V_167 , V_147 -> V_157 ) ;
if ( V_149 <= 0 ) {
if ( V_149 == 0 )
V_236 = V_233 ;
else
V_236 = V_234 ;
break;
}
V_147 -> V_167 += V_149 ;
}
#ifdef F_6
else {
#if F_145 ( 2 , 31 , 18 )
V_238 = F_152 ( V_147 -> V_168 , V_171 ) ;
#else
F_153 ( & V_237 ) ;
F_154 ( & V_237 , V_171 ) ;
V_238 = F_155 ( V_147 -> V_168 , & V_237 ) ;
#endif
if ( V_147 -> V_152 == V_160 ) {
V_236 = V_233 ;
break;
} else if ( V_147 -> V_152 == V_161 ) {
V_236 = V_234 ;
break;
}
if ( ! V_238 ) {
return 0 ;
}
}
#endif
if ( V_147 -> V_167 < V_147 -> V_156 )
return 0 ;
V_236 = V_231 ;
break;
case V_242 :
#ifdef F_6
if ( F_151 ( V_147 -> V_155 ) ) {
#endif
V_147 -> V_226 = V_243 ;
V_147 -> V_156 = V_147 -> V_241 . V_133 . V_138 ;
V_147 -> V_167 = 0 ;
#ifdef F_6
V_147 -> V_159 = ( char * ) V_83 ;
F_113 ( V_147 -> V_154 , V_147 -> V_159 ) ;
F_114 ( V_147 -> V_155 ) ;
}
#endif
case V_243 :
#ifdef F_6
if ( V_147 -> V_157 )
#endif
{
V_149 = F_105 ( V_147 -> V_158 ,
V_83 + V_147 -> V_167 ,
V_147 -> V_156 - V_147 -> V_167 ,
V_147 -> V_157 ) ;
if ( V_149 <= 0 ) {
if ( V_149 == 0 )
V_236 = V_233 ;
else
V_236 = V_234 ;
break;
}
V_147 -> V_167 += V_149 ;
}
#ifdef F_6
else {
#if F_145 ( 2 , 31 , 18 )
V_238 = F_152 ( V_147 -> V_168 , V_171 ) ;
#else
F_153 ( & V_237 ) ;
F_154 ( & V_237 , V_171 ) ;
V_238 = F_155 ( V_147 -> V_168 , & V_237 ) ;
#endif
if ( V_147 -> V_152 == V_160 ) {
V_236 = V_233 ;
break;
} else if ( V_147 -> V_152 == V_161 ) {
V_236 = V_234 ;
break;
}
if ( ! V_238 ) {
return 0 ;
}
}
#endif
if ( V_147 -> V_167 < V_147 -> V_156 )
return 0 ;
V_236 = V_232 ;
break;
default:
F_31 ( V_29 , V_173 , L_169 ) ;
V_236 = V_235 ;
}
switch ( V_236 ) {
case V_231 :
F_103 ( V_147 -> V_217 , & V_147 -> V_244 ,
& V_147 -> V_241 . V_133 ) ;
if ( V_147 -> V_241 . V_133 . V_138 > V_245 ) {
F_31 ( V_29 , V_173 , L_170 ,
V_228 -> V_117 + 1 , V_147 -> V_241 . V_133 . V_138 ) ;
break;
}
if ( V_147 -> V_241 . V_133 . V_138 ) {
V_147 -> V_226 = V_242 ;
return 0 ;
}
case V_232 :
V_230 . V_246 . V_11 = V_147 -> V_241 . V_133 . V_136 ;
V_230 . V_246 . V_12 = V_147 -> V_241 . V_133 . V_137 ;
V_230 . V_247 = V_147 -> V_241 . V_133 . V_138 ;
V_230 . V_56 = V_147 -> V_241 . V_133 . V_139 ;
if ( V_248 ) {
F_156 ( ( V_249 * ) V_147 , & V_230 , V_83 ) ;
} else {
F_157 ( ( V_249 * ) V_147 , & V_230 , V_83 ) ;
}
V_147 -> V_226 = V_227 ;
return 1 ;
case V_233 :
V_147 -> V_152 = V_160 ;
return - 1 ;
case V_234 :
#ifdef F_6
F_125 ( V_189 | V_190 | V_191 ,
NULL , F_112 () , 0 , ( T_37 ) & V_66 , 0 , NULL ) ;
F_31 ( V_29 , V_173 ,
L_171 ,
F_143 ( V_66 ) , F_112 () ) ;
F_127 ( V_66 ) ;
#else
F_31 ( V_29 , V_173 , L_172 ,
F_28 ( V_27 ) ) ;
#endif
case V_235 :
break;
}
V_147 -> V_152 = V_161 ;
return - 1 ;
}
static void F_158 ( T_40 * V_228 )
{
T_20 V_53 ;
T_35 * V_147 ;
F_90 ( V_112 , V_114 , L_173 ) ;
for ( V_53 = 0 ; V_53 < V_228 -> V_250 -> V_56 ; V_53 ++ ) {
V_147 = F_41 ( V_228 -> V_250 , T_35 * , V_53 ) ;
if ( V_147 -> V_158 >= 0 ) {
F_159 ( V_147 -> V_214 ) ;
F_128 ( V_147 -> V_158 , V_147 -> V_157 ) ;
V_147 -> V_158 = - 1 ;
}
#ifdef F_6
if ( V_147 -> V_162 != V_200 ) {
F_160 ( V_147 -> V_162 ) ;
V_147 -> V_162 = V_200 ;
}
#endif
if ( V_147 -> V_37 != NULL ) {
F_90 ( V_112 , V_114 , L_174 , ( void * ) V_147 -> V_37 ) ;
F_44 ( V_147 -> V_37 ) ;
V_147 -> V_37 = NULL ;
}
}
V_228 -> V_108 = FALSE ;
#ifdef F_6
F_96 () ;
#endif
}
static T_44
F_161 ( T_14 * V_37 , T_5 V_214 ,
const T_9 * T_15 , const T_9 * V_43 )
{
struct V_41 V_42 ;
F_90 ( V_112 , V_114 , L_175 , V_43 ) ;
if ( V_43 && ! V_214 ) {
if ( ! F_37 ( T_15 , V_37 , & V_42 , V_43 ) ) {
return V_251 ;
}
if ( F_162 ( V_37 , & V_42 ) < 0 ) {
#ifdef F_163
F_164 ( & V_42 ) ;
#endif
return V_252 ;
}
#ifdef F_163
F_164 ( & V_42 ) ;
#endif
}
return V_253 ;
}
static T_5
F_165 ( T_17 * V_48 , T_40 * V_228 , char * V_29 , int V_30 )
{
int V_101 ;
T_20 V_53 ;
T_35 * V_147 ;
T_18 V_49 ;
T_5 V_254 ;
F_90 ( V_112 , V_114 , L_176 ) ;
if ( ( V_48 -> V_255 == FALSE ) &&
( V_48 -> V_55 -> V_56 > 1 ) ) {
F_31 ( V_29 , V_30 ,
L_177 ) ;
return FALSE ;
}
if ( V_48 -> V_256 ) {
V_228 -> V_257 = F_166 ( & V_101 ) ;
} else {
V_228 -> V_257 = F_167 ( V_228 -> V_258 , L_178 ) ;
if ( V_228 -> V_257 == NULL ) {
V_101 = V_27 ;
}
}
if ( V_228 -> V_257 ) {
if ( V_48 -> V_255 ) {
char V_259 [ 100 ] ;
T_7 * V_260 ;
V_260 = F_168 ( L_63 ) ;
F_169 ( V_260 ) ;
F_31 ( V_259 , sizeof( V_259 ) , L_3 V_15 L_110 , V_16 ) ;
V_254 = F_170 ( V_228 -> V_257 ,
( const char * ) V_48 -> V_261 ,
NULL ,
V_260 -> V_21 ,
V_259 ,
- 1 ,
& V_228 -> V_262 ,
& V_101 ) ;
for ( V_53 = 0 ; V_254 && ( V_53 < V_48 -> V_55 -> V_56 ) ; V_53 ++ ) {
V_49 = F_41 ( V_48 -> V_55 , T_18 , V_53 ) ;
V_147 = F_41 ( V_228 -> V_250 , T_35 * , V_53 ) ;
if ( V_147 -> V_214 ) {
V_147 -> V_224 = V_147 -> V_244 . V_224 ;
} else {
V_147 -> V_224 = F_171 ( V_147 -> V_37 ) ;
}
V_254 = F_172 ( V_107 . V_257 ,
NULL ,
V_49 . T_15 ,
V_49 . V_263 ,
V_49 . V_43 ,
V_260 -> V_21 ,
V_147 -> V_38 ,
V_147 -> V_224 ,
& ( V_107 . V_262 ) ,
0 ,
V_147 -> V_219 ? 9 : 6 ,
& V_107 . V_101 ) ;
}
F_173 ( V_260 , TRUE ) ;
} else {
V_147 = F_41 ( V_228 -> V_250 , T_35 * , 0 ) ;
if ( V_147 -> V_214 ) {
V_147 -> V_224 = V_147 -> V_244 . V_224 ;
} else {
V_147 -> V_224 = F_171 ( V_147 -> V_37 ) ;
}
V_254 = F_174 ( V_228 -> V_257 , V_147 -> V_38 , V_147 -> V_224 ,
V_147 -> V_219 , & V_228 -> V_262 , & V_101 ) ;
}
if ( ! V_254 ) {
fclose ( V_228 -> V_257 ) ;
V_228 -> V_257 = NULL ;
}
}
if ( V_228 -> V_257 == NULL ) {
switch ( V_101 ) {
default:
if ( V_101 < 0 ) {
F_31 ( V_29 , V_30 ,
L_179
L_180 ,
V_48 -> V_264 , V_101 ) ;
} else {
F_31 ( V_29 , V_30 ,
L_179
L_181 ,
V_48 -> V_264 , F_28 ( V_101 ) ) ;
}
break;
}
return FALSE ;
}
return TRUE ;
}
static T_5
F_175 ( T_17 * V_48 , T_40 * V_228 , int * V_265 )
{
unsigned int V_53 ;
T_35 * V_147 ;
T_3 V_266 = F_5 () ;
F_90 ( V_112 , V_114 , L_182 ) ;
if ( V_48 -> V_256 ) {
return F_176 ( & V_48 -> V_264 , V_265 ) ;
} else {
if ( V_48 -> V_255 ) {
for ( V_53 = 0 ; V_53 < V_107 . V_250 -> V_56 ; V_53 ++ ) {
V_147 = F_41 ( V_107 . V_250 , T_35 * , V_53 ) ;
if ( ! V_147 -> V_214 ) {
T_3 V_267 , V_268 ;
struct V_102 V_269 ;
if ( F_83 ( V_147 -> V_37 , & V_269 ) >= 0 ) {
V_267 = V_147 -> V_270 ;
V_268 = V_269 . V_110 + V_147 -> V_271 + V_147 -> V_272 ;
} else {
V_267 = V_273 ;
V_268 = V_273 ;
}
F_177 ( V_228 -> V_257 ,
V_53 ,
& V_228 -> V_262 ,
L_183 ,
V_274 ,
V_266 ,
V_267 ,
V_268 ,
V_265 ) ;
}
}
}
if ( fclose ( V_228 -> V_257 ) == V_275 ) {
if ( V_265 != NULL ) {
* V_265 = V_27 ;
}
return ( FALSE ) ;
} else {
return ( TRUE ) ;
}
}
}
static int
F_178 ( T_40 * V_228 ,
char * V_29 , int V_30 , T_35 * V_147 )
{
int V_276 ;
T_45 V_277 ;
T_41 V_278 [ V_245 ] ;
#ifndef F_6
int V_198 ;
#endif
V_277 = V_228 -> V_117 ;
if ( V_147 -> V_214 ) {
#ifdef F_150
F_90 ( V_112 , V_114 , L_184 ) ;
#endif
#ifndef F_6
V_198 = F_115 ( V_147 -> V_158 ) ;
if ( V_198 <= 0 ) {
if ( V_198 < 0 && V_27 != V_279 ) {
F_31 ( V_29 , V_30 ,
L_158 , F_28 ( V_27 ) ) ;
F_43 ( V_29 , V_40 ) ;
V_228 -> V_108 = FALSE ;
}
} else {
#endif
V_276 = F_149 ( V_228 , V_147 , V_278 , V_29 , V_30 ) ;
if ( V_276 < 0 ) {
V_228 -> V_108 = FALSE ;
}
#ifndef F_6
}
#endif
}
else
{
#ifdef F_179
#ifdef F_150
F_90 ( V_112 , V_114 , L_185 ) ;
#endif
if ( V_147 -> V_280 != - 1 ) {
V_198 = F_115 ( V_147 -> V_280 ) ;
if ( V_198 > 0 ) {
if ( V_248 ) {
V_276 = F_180 ( V_147 -> V_37 , 1 , F_156 , ( V_249 * ) V_147 ) ;
} else {
V_276 = F_180 ( V_147 -> V_37 , 1 , F_157 , ( V_249 * ) V_147 ) ;
}
if ( V_276 < 0 ) {
if ( V_276 == - 1 ) {
V_147 -> V_281 = TRUE ;
}
V_228 -> V_108 = FALSE ;
}
} else {
if ( V_198 < 0 && V_27 != V_279 ) {
F_31 ( V_29 , V_30 ,
L_158 , F_28 ( V_27 ) ) ;
F_43 ( V_29 , V_40 ) ;
V_228 -> V_108 = FALSE ;
}
}
}
else
#endif
{
#if 1
#ifdef F_150
F_90 ( V_112 , V_114 , L_186 ) ;
#endif
#ifdef F_6
if ( V_248 ) {
V_276 = F_180 ( V_147 -> V_37 , 1 , F_156 , ( V_249 * ) V_147 ) ;
} else {
V_276 = F_180 ( V_147 -> V_37 , 1 , F_157 , ( V_249 * ) V_147 ) ;
}
#else
if ( V_248 ) {
V_276 = F_180 ( V_147 -> V_37 , - 1 , F_156 , ( V_249 * ) V_147 ) ;
} else {
V_276 = F_180 ( V_147 -> V_37 , - 1 , F_157 , ( V_249 * ) V_147 ) ;
}
#endif
if ( V_276 < 0 ) {
if ( V_276 == - 1 ) {
V_147 -> V_281 = TRUE ;
}
V_228 -> V_108 = FALSE ;
}
#else
#ifdef F_150
F_90 ( V_112 , V_114 , L_187 ) ;
#endif
{
int V_282 ;
struct V_229 * V_283 ;
V_249 * V_284 ;
V_282 = 0 ;
while( V_228 -> V_108 &&
( V_282 = F_181 ( V_147 -> V_37 , & V_283 , & V_284 ) ) == 1 ) {
if ( V_248 ) {
F_156 ( ( V_249 * ) V_147 , V_283 , V_284 ) ;
} else {
F_157 ( ( V_249 * ) V_147 , V_283 , V_284 ) ;
}
}
if ( V_282 < 0 ) {
V_147 -> V_281 = TRUE ;
V_228 -> V_108 = FALSE ;
}
}
#endif
}
}
#ifdef F_150
F_90 ( V_112 , V_114 , L_188 , V_276 , F_182 ( V_276 , L_63 , L_189 ) ) ;
#endif
return V_228 -> V_117 - V_277 ;
}
static T_7 *
F_183 ( const char * T_12 )
{
T_9 * V_285 ;
T_7 * V_286 ;
V_285 = strchr ( T_12 , '{' ) ;
if ( V_285 == NULL )
return F_168 ( T_12 ) ;
V_286 = F_168 ( V_285 + 1 ) ;
V_285 = strchr ( V_286 -> V_21 , '}' ) ;
if ( V_285 == NULL )
return V_286 ;
V_286 = F_184 ( V_286 , V_285 - V_286 -> V_21 ) ;
return V_286 ;
}
static T_5
F_185 ( T_17 * V_48 , int * V_258 ,
char * V_29 , int V_30 )
{
char * V_287 ;
T_9 * V_288 ;
T_9 * V_289 ;
T_5 V_290 ;
F_90 ( V_112 , V_114 , L_190 ,
( V_48 -> V_264 ) ? V_48 -> V_264 : L_191 ) ;
if ( V_48 -> V_264 != NULL ) {
V_288 = F_55 ( V_48 -> V_264 ) ;
if ( V_48 -> V_291 == TRUE ) {
if ( V_48 -> V_256 ) {
F_31 ( V_29 , V_30 ,
L_192 ) ;
F_22 ( V_288 ) ;
return FALSE ;
}
if ( strcmp ( V_288 , L_141 ) == 0 ) {
* V_258 = 1 ;
#ifdef F_6
F_186 ( 1 , V_292 ) ;
#endif
}
}
else {
if ( V_48 -> V_256 ) {
* V_258 = F_187 ( V_288 ,
( V_48 -> V_293 ) ? V_48 -> V_294 : 0 ,
V_48 -> V_295 ) ;
if ( * V_258 != - 1 ) {
F_22 ( V_288 ) ;
V_288 = F_55 ( F_188 () ) ;
}
} else {
* V_258 = F_135 ( V_288 , V_296 | V_292 | V_297 | V_298 ,
( V_48 -> V_295 ) ? 0640 : 0600 ) ;
}
}
V_290 = FALSE ;
} else {
if ( V_299 . V_55 -> V_56 > 1 ) {
V_289 = F_56 ( L_193 , V_299 . V_55 -> V_56 ) ;
} else {
T_9 * V_300 ;
V_300 = F_189 ( F_41 ( V_299 . V_55 , T_18 , 0 ) . V_301 ) ;
#ifdef F_6
if ( strncmp ( L_194 , V_300 , 5 ) == 0 )
{
T_7 * T_12 ;
T_12 = F_183 ( V_300 ) ;
F_22 ( V_300 ) ;
V_300 = F_55 ( T_12 -> V_21 ) ;
F_173 ( T_12 , TRUE ) ;
}
#endif
if ( V_48 -> V_255 ) {
V_289 = F_190 ( L_195 , V_300 , NULL ) ;
} else{
V_289 = F_190 ( L_196 , V_300 , NULL ) ;
}
F_22 ( V_300 ) ;
}
* V_258 = F_191 ( & V_287 , V_289 ) ;
F_22 ( V_289 ) ;
V_288 = F_55 ( V_287 ) ;
V_290 = TRUE ;
}
if ( * V_258 == - 1 ) {
if ( V_290 ) {
F_31 ( V_29 , V_30 ,
L_197
L_198 , V_288 , F_28 ( V_27 ) ) ;
} else {
if ( V_48 -> V_256 ) {
F_192 () ;
}
F_31 ( V_29 , V_30 ,
L_199
L_198 , V_288 ,
F_28 ( V_27 ) ) ;
}
F_22 ( V_288 ) ;
return FALSE ;
}
if ( V_48 -> V_264 != NULL ) {
F_22 ( V_48 -> V_264 ) ;
}
V_48 -> V_264 = V_288 ;
return TRUE ;
}
static T_5
F_193 ( T_17 * V_48 ,
T_46 * V_302 ,
T_46 * V_303 ,
T_46 * V_304 )
{
T_20 V_53 ;
T_35 * V_147 ;
T_18 V_49 ;
T_5 V_254 ;
if ( V_48 -> V_256 ) {
if ( V_302 != NULL &&
F_194 ( V_302 , ++ V_107 . V_305 ) ) {
V_107 . V_108 = FALSE ;
return FALSE ;
}
if ( F_195 ( & V_107 . V_257 , & V_48 -> V_264 ,
& V_107 . V_258 , & V_107 . V_101 ) ) {
V_107 . V_262 = 0 ;
if ( V_48 -> V_255 ) {
char V_259 [ 100 ] ;
T_7 * V_260 ;
V_260 = F_168 ( L_63 ) ;
F_169 ( V_260 ) ;
F_31 ( V_259 , sizeof( V_259 ) , L_3 V_15 L_110 , V_16 ) ;
V_254 = F_170 ( V_107 . V_257 ,
NULL ,
NULL ,
V_260 -> V_21 ,
V_259 ,
- 1 ,
& ( V_107 . V_262 ) ,
& V_107 . V_101 ) ;
for ( V_53 = 0 ; V_254 && ( V_53 < V_48 -> V_55 -> V_56 ) ; V_53 ++ ) {
V_49 = F_41 ( V_48 -> V_55 , T_18 , V_53 ) ;
V_147 = F_41 ( V_107 . V_250 , T_35 * , V_53 ) ;
V_254 = F_172 ( V_107 . V_257 ,
NULL ,
V_49 . T_15 ,
V_49 . V_263 ,
V_49 . V_43 ,
V_260 -> V_21 ,
V_147 -> V_38 ,
V_147 -> V_224 ,
& ( V_107 . V_262 ) ,
0 ,
V_147 -> V_219 ? 9 : 6 ,
& V_107 . V_101 ) ;
}
F_173 ( V_260 , TRUE ) ;
} else {
V_147 = F_41 ( V_107 . V_250 , T_35 * , 0 ) ;
V_254 = F_174 ( V_107 . V_257 , V_147 -> V_38 , V_147 -> V_224 ,
V_147 -> V_219 , & V_107 . V_262 , & V_107 . V_101 ) ;
}
if ( ! V_254 ) {
fclose ( V_107 . V_257 ) ;
V_107 . V_257 = NULL ;
V_107 . V_108 = FALSE ;
return FALSE ;
}
if ( V_303 )
F_196 ( V_303 ) ;
if ( V_304 )
F_196 ( V_304 ) ;
fflush ( V_107 . V_257 ) ;
if ( ! V_118 )
F_197 ( V_107 . V_306 ) ;
V_107 . V_306 = 0 ;
F_198 ( V_48 -> V_264 ) ;
} else {
V_107 . V_108 = FALSE ;
return FALSE ;
}
} else {
V_107 . V_108 = FALSE ;
return FALSE ;
}
return TRUE ;
}
static void *
F_199 ( void * V_146 )
{
T_35 * V_147 ;
char V_29 [ V_50 + 1 ] ;
V_147 = ( T_35 * ) V_146 ;
F_90 ( V_112 , V_113 , L_200 ,
V_147 -> V_307 ) ;
while ( V_107 . V_108 ) {
F_178 ( & V_107 , V_29 , sizeof( V_29 ) , V_147 ) ;
}
F_90 ( V_112 , V_113 , L_201 ,
V_147 -> V_307 ) ;
F_200 ( NULL ) ;
return ( NULL ) ;
}
static void
F_91 ( void )
{
#ifdef F_201
T_20 V_53 ;
T_35 * V_147 ;
for ( V_53 = 0 ; V_53 < V_107 . V_250 -> V_56 ; V_53 ++ ) {
V_147 = F_41 ( V_107 . V_250 , T_35 * , V_53 ) ;
if ( V_147 -> V_37 != NULL )
F_202 ( V_147 -> V_37 ) ;
}
#endif
V_107 . V_108 = FALSE ;
}
static void
F_203 ( char * V_29 , int V_308 , const char * V_309 ,
int V_101 , T_5 V_310 )
{
switch ( V_101 ) {
case V_311 :
F_31 ( V_29 , V_308 ,
L_202
L_203
L_204
L_205 ,
V_309 ) ;
break;
#ifdef F_204
case F_204 :
F_31 ( V_29 , V_308 ,
L_202
L_203
L_206
L_207
L_208 ,
V_309 ) ;
break;
#endif
default:
if ( V_310 ) {
F_31 ( V_29 , V_308 ,
L_209
L_210 ,
V_309 , F_28 ( V_101 ) ) ;
} else {
F_31 ( V_29 , V_308 ,
L_211
L_203
L_212 ,
V_309 , F_28 ( V_101 ) ) ;
}
break;
}
}
static void
F_157 ( V_249 * V_312 , const struct V_229 * V_230 ,
const V_249 * V_313 )
{
T_35 * V_147 = ( T_35 * ) ( void * ) V_312 ;
int V_101 ;
T_20 V_314 = V_147 -> V_219 ? 1000000000 : 1000000 ;
if ( ! V_107 . V_108 ) {
V_147 -> V_272 ++ ;
return;
}
if ( V_107 . V_257 ) {
T_5 V_254 ;
if ( V_299 . V_255 ) {
V_254 = F_205 ( V_107 . V_257 ,
NULL ,
V_230 -> V_246 . V_11 , ( V_315 ) V_230 -> V_246 . V_12 ,
V_230 -> V_247 , V_230 -> V_56 ,
V_147 -> V_307 ,
V_314 ,
V_313 , 0 ,
& V_107 . V_262 , & V_101 ) ;
} else {
V_254 = F_206 ( V_107 . V_257 ,
V_230 -> V_246 . V_11 , ( V_315 ) V_230 -> V_246 . V_12 ,
V_230 -> V_247 , V_230 -> V_56 ,
V_313 ,
& V_107 . V_262 , & V_101 ) ;
}
if ( ! V_254 ) {
V_107 . V_108 = FALSE ;
V_107 . V_101 = V_101 ;
V_147 -> V_271 ++ ;
} else {
F_90 ( V_112 , V_113 ,
L_213 ,
V_230 -> V_247 , V_147 -> V_307 ) ;
V_107 . V_117 ++ ;
V_147 -> V_270 ++ ;
if ( ( V_107 . V_316 > 0 ) && ( V_107 . V_117 >= V_107 . V_316 ) ) {
V_107 . V_108 = FALSE ;
}
}
}
}
static void
F_156 ( V_249 * V_312 , const struct V_229 * V_230 ,
const V_249 * V_313 )
{
T_35 * V_147 = ( T_35 * ) ( void * ) V_312 ;
T_47 * V_317 ;
T_5 V_318 ;
if ( ! V_107 . V_108 ) {
V_147 -> V_272 ++ ;
return;
}
V_317 = ( T_47 * ) F_53 ( sizeof( T_47 ) ) ;
if ( V_317 == NULL ) {
V_147 -> V_271 ++ ;
return;
}
V_317 -> V_147 = V_147 ;
V_317 -> V_230 = * V_230 ;
V_317 -> V_313 = ( V_249 * ) F_53 ( V_230 -> V_247 ) ;
if ( V_317 -> V_313 == NULL ) {
V_147 -> V_271 ++ ;
F_22 ( V_317 ) ;
return;
}
memcpy ( V_317 -> V_313 , V_313 , V_230 -> V_247 ) ;
F_207 ( V_319 ) ;
if ( ( ( V_320 == 0 ) || ( V_321 < V_320 ) ) &&
( ( V_322 == 0 ) || ( V_323 < V_322 ) ) ) {
V_318 = FALSE ;
F_208 ( V_319 , V_317 ) ;
V_321 += V_230 -> V_247 ;
V_323 += 1 ;
} else {
V_318 = TRUE ;
}
F_209 ( V_319 ) ;
if ( V_318 ) {
V_147 -> V_271 ++ ;
F_22 ( V_317 -> V_313 ) ;
F_22 ( V_317 ) ;
F_90 ( V_112 , V_113 ,
L_214 ,
V_230 -> V_247 , V_147 -> V_307 ) ;
} else {
V_147 -> V_270 ++ ;
F_90 ( V_112 , V_113 ,
L_215 ,
V_230 -> V_247 , V_147 -> V_307 ) ;
}
F_90 ( V_112 , V_113 ,
L_216 V_324 L_217 V_324 L_218 ,
V_321 , V_323 ) ;
}
static int
F_210 ( const char * T_12 , const char * V_325 )
{
int V_326 = 0 , type , V_327 ;
T_9 * * V_328 = NULL ;
V_328 = F_211 ( V_325 , L_109 , 2 ) ;
if ( V_328 [ 0 ] )
V_326 = atoi ( V_328 [ 0 ] ) ;
if ( V_328 [ 1 ] ) {
type = F_212 ( V_328 [ 1 ] ) ;
if ( type == - 1 ) {
V_327 = V_329 ;
goto V_330;
}
}
else
type = - 1 ;
V_327 = F_213 () ;
if ( V_327 ) {
F_19 ( L_219 , abs ( V_327 ) , F_28 ( abs ( V_327 ) ) ) ;
V_327 = 2 ;
goto V_330;
}
V_327 = F_214 ( T_12 , V_326 , type ) ;
if ( V_327 ) {
F_19 ( L_220 , abs ( V_327 ) , F_28 ( abs ( V_327 ) ) ) ;
V_327 = 2 ;
goto V_330;
}
if ( V_24 )
F_49 ( 2 , V_59 , NULL ) ;
V_327 = 0 ;
V_330:
F_215 ( V_328 ) ;
return V_327 ;
}
int
main ( int V_331 , char * V_332 [] )
{
T_7 * V_19 ;
T_7 * V_20 ;
int V_325 ;
struct V_333 V_334 [] = {
{ ( char * ) L_221 , V_335 , NULL , V_336 } ,
{ 0 , 0 , 0 , 0 }
} ;
T_5 V_337 = FALSE ;
#ifdef F_6
T_48 V_338 ;
#else
struct V_339 V_340 , V_341 ;
#endif
T_5 V_342 = TRUE ;
T_5 V_343 ;
struct V_102 V_269 ;
T_49 V_344 ;
T_5 V_345 = FALSE ;
T_5 V_346 = FALSE ;
#ifdef F_13
T_5 V_347 = FALSE ;
#endif
T_5 V_348 = FALSE ;
T_9 * V_349 = NULL ;
T_5 V_97 = FALSE ;
T_5 V_350 = FALSE ;
int V_68 , V_351 = 0 ;
T_45 V_53 ;
T_20 V_54 ;
#if F_12 ( V_352 ) && F_12 ( V_353 )
struct V_354 V_355 ;
#endif
T_7 * V_21 ;
V_19 = F_168 ( L_222 ) ;
F_216 ( V_19 , NULL , NULL ) ;
V_20 = F_168 ( L_223 ) ;
F_217 ( V_20 , NULL ) ;
F_218 ( L_3 V_15 L_4
L_8
L_110
L_8
L_110 ,
V_16 , V_19 -> V_21 , V_20 -> V_21 ) ;
#ifdef F_6
F_219 ( V_331 , V_332 ) ;
F_220 () ;
F_221 () ;
#endif
#ifdef F_14
#define F_222 "A:"
#define F_223 "r"
#define F_224 "u"
#else
#define F_222 ""
#define F_223 ""
#define F_224 ""
#endif
#ifdef F_15
#define F_225 "m:"
#else
#define F_225 ""
#endif
#if F_12 ( F_6 ) || F_12 ( F_11 )
#define F_226 "B:"
#else
#define F_226 ""
#endif
#ifdef F_11
#define F_227 "I"
#else
#define F_227 ""
#endif
#ifdef F_13
#define F_228 "d"
#else
#define F_228 ""
#endif
#define F_229 "a:" OPTSTRING_A "b:" OPTSTRING_B "C:c:" OPTSTRING_d "Df:ghi:" OPTSTRING_I "k:L" OPTSTRING_m "MN:npPq" OPTSTRING_r "Ss:t" OPTSTRING_u "vw:y:Z:"
#ifdef F_230
if ( ( V_356 = F_231 ( L_224 , L_225 ) ) == NULL ) {
fprintf ( V_17 , L_226 ) ;
exit ( 1 ) ;
}
#endif
#if F_12 ( V_352 ) && F_12 ( V_353 )
if ( F_232 ( & V_355 ) == 0 ) {
if ( strcmp ( V_355 . V_357 , L_227 ) == 0 ||
strcmp ( V_355 . V_357 , L_228 ) == 0 ||
strcmp ( V_355 . V_357 , L_229 ) == 0 )
V_358 = TRUE ;
}
#endif
for ( V_53 = 1 ; V_53 < V_331 ; V_53 ++ ) {
if ( strcmp ( L_230 , V_332 [ V_53 ] ) == 0 ) {
V_24 = TRUE ;
V_97 = TRUE ;
#ifdef F_6
F_186 ( 2 , V_292 ) ;
#endif
}
}
V_344 =
( T_49 ) (
V_359 |
V_360 |
V_361 |
V_362 |
V_113 |
V_114 |
V_363 |
V_364 ) ;
F_233 ( NULL ,
V_344 ,
V_365 , NULL ) ;
F_233 ( V_366 ,
V_344 ,
V_365 , NULL ) ;
F_233 ( V_367 ,
V_344 ,
V_365 , NULL ) ;
F_233 ( V_112 ,
V_344 ,
V_365 , NULL ) ;
V_107 . V_250 = F_234 ( FALSE , FALSE , sizeof( T_35 * ) ) ;
#if ! F_145 ( 2 , 31 , 0 )
F_235 ( NULL ) ;
#endif
#ifdef F_6
F_236 () ;
F_237 ( F_238 ( 1 , 1 ) , & V_338 ) ;
F_239 ( F_89 , TRUE ) ;
#else
memset ( & V_340 , 0 , sizeof( V_340 ) ) ;
V_340 . V_368 = F_89 ;
V_340 . V_369 = 0 ;
F_240 ( & V_340 . V_370 ) ;
V_339 ( V_371 , & V_340 , NULL ) ;
V_339 ( V_372 , & V_340 , NULL ) ;
V_339 ( V_373 , & V_340 , NULL ) ;
V_339 ( V_374 , NULL , & V_341 ) ;
if ( V_341 . V_368 == V_375 )
V_339 ( V_374 , & V_340 , NULL ) ;
#ifdef F_241
V_340 . V_368 = F_94 ;
V_340 . V_369 = V_376 ;
F_240 ( & V_340 . V_370 ) ;
V_339 ( F_241 , & V_340 , NULL ) ;
#endif
#endif
#ifdef F_16
F_1 () ;
#endif
F_242 () ;
#ifdef F_47
F_99 () ;
#endif
F_243 ( & V_299 ) ;
V_299 . V_377 = TRUE ;
V_299 . V_293 = TRUE ;
V_299 . V_24 = V_24 ;
while ( ( V_325 = F_244 ( V_331 , V_332 , F_229 , V_334 , NULL ) ) != - 1 ) {
switch ( V_325 ) {
case 'h' :
F_10 ( TRUE ) ;
F_95 ( 0 ) ;
break;
case 'v' :
{
F_17 ( V_19 , V_20 ) ;
F_173 ( V_19 , TRUE ) ;
F_173 ( V_20 , TRUE ) ;
F_95 ( 0 ) ;
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
case V_336 :
#ifdef F_14
case 'u' :
case 'r' :
case 'A' :
#endif
#ifdef F_15
case 'm' :
#endif
#if F_12 ( F_6 ) || F_12 ( F_11 )
case 'B' :
#endif
#ifdef F_11
case 'I' :
#endif
V_68 = F_245 ( & V_299 , V_325 , V_378 , & V_342 ) ;
if ( V_68 != 0 ) {
F_95 ( V_68 ) ;
}
break;
case 'Z' :
V_24 = TRUE ;
#ifdef F_6
F_186 ( 2 , V_292 ) ;
if ( strcmp ( V_378 , V_379 ) != 0 ) {
V_380 = F_56 ( V_381 , V_378 ) ;
V_382 = F_141 ( F_142 ( V_380 ) ,
V_211 , 0 , NULL , V_212 , 0 , NULL ) ;
if ( V_382 == V_200 ) {
F_90 ( V_112 , V_113 ,
L_231 ,
V_380 ) ;
F_95 ( 1 ) ;
}
}
#endif
break;
case 'q' :
V_118 = TRUE ;
break;
case 't' :
V_248 = TRUE ;
break;
case 'D' :
V_345 = TRUE ;
V_351 ++ ;
break;
case 'L' :
V_346 = TRUE ;
V_351 ++ ;
break;
#ifdef F_13
case 'd' :
V_347 = TRUE ;
V_351 ++ ;
break;
#endif
case 'S' :
V_350 = TRUE ;
V_351 ++ ;
break;
case 'k' :
V_348 = TRUE ;
V_349 = V_378 ;
V_351 ++ ;
break;
case 'M' :
V_97 = TRUE ;
break;
case 'C' :
V_320 = F_246 ( V_378 , L_232 ) ;
break;
case 'N' :
V_322 = F_246 ( V_378 , L_233 ) ;
break;
default:
F_19 ( L_234 , V_332 [ V_383 - 1 ] ) ;
case '?' :
V_337 = TRUE ;
break;
}
}
if ( ! V_337 ) {
V_331 -= V_383 ;
V_332 += V_383 ;
if ( V_331 >= 1 ) {
V_331 -- ;
V_332 ++ ;
}
if ( V_331 != 0 ) {
F_19 ( L_235 , V_332 [ 0 ] ) ;
V_337 = TRUE ;
}
}
if ( ( V_320 > 0 ) || ( V_322 > 0 ) ) {
V_248 = TRUE ;
}
if ( ( V_320 == 0 ) && ( V_322 == 0 ) ) {
V_320 = 1000 * 1000 ;
V_322 = 1000 ;
}
if ( V_337 ) {
F_10 ( FALSE ) ;
F_95 ( 1 ) ;
}
if ( V_351 > 1 ) {
F_19 ( L_236 ) ;
F_95 ( 1 ) ;
} else if ( V_351 == 1 ) {
if ( V_299 . V_256 ) {
F_19 ( L_237 ) ;
F_95 ( 1 ) ;
}
} else {
if ( V_299 . V_55 -> V_56 > 1 ) {
V_248 = TRUE ;
V_299 . V_255 = TRUE ;
}
if ( V_299 . V_261 &&
( ! V_299 . V_255 || V_299 . V_256 ) ) {
F_19 ( L_238 ) ;
F_95 ( 1 ) ;
}
if ( V_299 . V_256 ) {
if ( V_299 . V_264 == NULL ) {
F_19 ( L_239 ) ;
V_299 . V_256 = FALSE ;
}
if ( ! V_299 . V_384 && ! V_299 . V_385 ) {
F_19 ( L_240 ) ;
#if 0
global_capture_opts.multi_files_on = FALSE;
#endif
}
}
}
if ( V_345 ) {
T_25 * V_76 ;
int V_101 ;
T_9 * V_66 ;
V_76 = F_247 ( & V_101 , & V_66 , NULL ) ;
if ( V_76 == NULL ) {
switch ( V_101 ) {
case V_104 :
case V_105 :
F_19 ( L_110 , V_66 ) ;
F_22 ( V_66 ) ;
F_95 ( 2 ) ;
break;
case V_106 :
if ( ! V_97 ) {
F_19 ( L_120 ) ;
F_95 ( 2 ) ;
}
break;
}
}
if ( V_97 )
F_74 ( V_76 ) ;
else
F_248 ( V_76 ) ;
F_88 ( V_76 ) ;
F_95 ( 0 ) ;
}
if ( V_350 ) {
V_68 = F_81 ( V_97 ) ;
F_95 ( V_68 ) ;
}
if ( V_348 ) {
T_18 V_49 ;
if ( V_299 . V_55 -> V_56 != 1 ) {
F_19 ( L_241 ) ;
F_95 ( 2 ) ;
}
V_49 = F_41 ( V_299 . V_55 , T_18 , 0 ) ;
V_68 = F_210 ( V_49 . T_15 , V_349 ) ;
F_95 ( V_68 ) ;
}
V_68 = F_249 ( & V_299 , NULL ) ;
if ( V_68 != 0 ) {
F_95 ( V_68 ) ;
}
if ( V_24 ) {
for ( V_54 = 0 ; V_54 < V_299 . V_55 -> V_56 ; V_54 ++ ) {
T_18 V_49 ;
V_49 = F_41 ( V_299 . V_55 , T_18 , V_54 ) ;
F_90 ( V_112 , V_114 , L_242 ,
V_49 . T_15 ) ;
}
} else {
V_21 = F_168 ( L_63 ) ;
#ifdef F_6
if ( V_299 . V_55 -> V_56 < 2 )
#else
if ( V_299 . V_55 -> V_56 < 4 )
#endif
{
for ( V_54 = 0 ; V_54 < V_299 . V_55 -> V_56 ; V_54 ++ ) {
T_18 V_49 ;
V_49 = F_41 ( V_299 . V_55 , T_18 , V_54 ) ;
if ( V_54 > 0 ) {
if ( V_299 . V_55 -> V_56 > 2 ) {
F_250 ( V_21 , L_109 ) ;
}
F_250 ( V_21 , L_243 ) ;
if ( V_54 == V_299 . V_55 -> V_56 - 1 ) {
F_250 ( V_21 , L_244 ) ;
}
}
F_250 ( V_21 , L_245 , V_49 . V_301 ) ;
}
} else {
F_250 ( V_21 , L_246 , V_299 . V_55 -> V_56 ) ;
}
fprintf ( V_17 , L_247 , V_21 -> V_21 ) ;
F_173 ( V_21 , TRUE ) ;
}
if ( V_346 ) {
T_23 * V_26 ;
T_9 * V_66 ;
T_20 V_386 ;
for ( V_386 = 0 ; V_386 < V_299 . V_55 -> V_56 ; V_386 ++ ) {
T_18 V_49 ;
V_49 = F_41 ( V_299 . V_55 , T_18 , V_386 ) ;
V_26 = F_58 ( V_49 . T_15 ,
V_49 . T_24 , & V_66 ) ;
if ( V_26 == NULL ) {
F_19 ( L_248
L_249
L_250 , V_49 . T_15 , V_66 ) ;
F_22 ( V_66 ) ;
F_95 ( 2 ) ;
}
if ( V_26 -> V_75 == NULL ) {
F_19 ( L_251 , V_49 . T_15 ) ;
F_95 ( 2 ) ;
}
if ( V_97 )
F_80 ( V_26 ) ;
else
F_251 ( V_26 , V_49 . T_15 ,
V_49 . T_24 ) ;
F_252 ( V_26 ) ;
}
F_95 ( 0 ) ;
}
F_253 ( & V_299 , V_72 ) ;
#ifdef F_13
if ( V_347 ) {
F_40 ( & V_299 ) ;
F_95 ( 0 ) ;
}
#endif
F_254 ( & V_299 ) ;
fflush ( V_17 ) ;
if ( F_255 ( & V_299 , & V_343 , & V_269 ) == TRUE ) {
F_95 ( 0 ) ;
} else {
F_95 ( 1 ) ;
}
return 0 ;
}
static void
V_365 ( const char * V_387 , T_49 V_388 ,
const char * V_389 , T_43 T_50 V_2 )
{
T_51 V_390 ;
struct V_391 * V_392 ;
const char * V_393 ;
T_9 * V_25 ;
if ( ! ( V_388 & V_394 & ~ ( V_114 | V_113 ) ) ) {
#if ! F_12 ( F_97 ) && ! F_12 ( F_230 )
return;
#endif
}
time ( & V_390 ) ;
V_392 = localtime ( & V_390 ) ;
switch( V_388 & V_394 ) {
case V_359 :
V_393 = L_252 ;
break;
case V_360 :
V_393 = L_253 ;
break;
case V_361 :
V_393 = L_254 ;
break;
case V_362 :
V_393 = L_255 ;
break;
case V_113 :
V_393 = L_256 ;
break;
case V_114 :
V_393 = L_257 ;
break;
default:
fprintf ( V_17 , L_258 , V_388 ) ;
V_393 = NULL ;
F_256 () ;
}
if ( V_388 & V_362 ) {
V_25 = F_56 ( L_4 , V_389 ) ;
} else {
V_25 = F_56 ( L_259 ,
V_392 -> V_395 , V_392 -> V_396 , V_392 -> V_397 ,
V_387 != NULL ? V_387 : L_63 ,
V_393 , V_389 ) ;
}
#if F_12 ( F_97 ) || F_12 ( F_230 )
if ( ! ( V_388 & V_394 & ~ ( V_114 | V_113 ) ) ) {
#ifdef F_97
fprintf ( V_17 , L_110 , V_25 ) ;
fflush ( V_17 ) ;
#endif
#ifdef F_230
fprintf ( V_356 , L_110 , V_25 ) ;
fflush ( V_356 ) ;
#endif
F_22 ( V_25 ) ;
return;
}
#endif
if ( V_24 ) {
F_21 ( 2 , V_25 , L_63 ) ;
} else {
fprintf ( V_17 , L_110 , V_25 ) ;
fflush ( V_17 ) ;
}
F_22 ( V_25 ) ;
}
static void
F_197 ( unsigned int V_117 )
{
char V_398 [ V_399 + 1 + 1 ] ;
static unsigned int V_400 = 0 ;
if ( V_24 ) {
F_31 ( V_398 , sizeof( V_398 ) , L_260 , V_117 ) ;
F_90 ( V_112 , V_114 , L_261 , V_398 ) ;
F_49 ( 2 , V_401 , V_398 ) ;
} else {
V_400 += V_117 ;
fprintf ( V_17 , L_262 , V_400 ) ;
fflush ( V_17 ) ;
}
}
static void
F_198 ( const char * V_402 )
{
if ( V_24 ) {
F_90 ( V_112 , V_114 , L_263 , V_402 ) ;
F_49 ( 2 , V_403 , V_402 ) ;
} else {
#ifdef F_241
V_121 = TRUE ;
#endif
fprintf ( V_17 , L_264 , V_402 ) ;
fflush ( V_17 ) ;
#ifdef F_241
V_121 = FALSE ;
if ( V_119 )
F_93 () ;
#endif
}
}
static void
F_45 ( T_17 * V_48 , T_20 V_53 , const char * V_29 )
{
T_18 V_49 ;
char V_398 [ V_50 + 1 + 6 ] ;
if ( V_53 < V_48 -> V_55 -> V_56 ) {
if ( V_24 ) {
F_31 ( V_398 , sizeof( V_398 ) , L_265 , V_53 , V_29 ) ;
F_90 ( V_112 , V_114 , L_266 , V_29 ) ;
F_49 ( 2 , V_404 , V_398 ) ;
} else {
V_49 = F_41 ( V_48 -> V_55 , T_18 , V_53 ) ;
F_19 (
L_267
L_8
L_268
L_269 ,
V_49 . V_43 , V_49 . T_15 , V_29 ) ;
}
}
}
static void
F_43 ( const char * V_405 , const char * V_406 )
{
if ( V_24 ) {
F_90 ( V_112 , V_114 ,
L_270 , V_405 ) ;
F_90 ( V_112 , V_114 ,
L_271 , V_406 ) ;
F_21 ( 2 , V_405 , V_406 ) ;
} else {
F_19 ( L_110 , V_405 ) ;
if ( V_406 [ 0 ] != '\0' )
F_23 ( L_110 , V_406 ) ;
}
}
static void
F_257 ( V_8 V_270 , V_8 V_407 , V_8 V_408 , V_8 V_272 , T_9 * T_15 )
{
char V_398 [ V_399 + 1 + 1 ] ;
V_8 V_409 = V_407 + V_408 + V_272 ;
F_31 ( V_398 , sizeof( V_398 ) , L_260 , V_409 ) ;
if ( V_24 ) {
F_90 ( V_112 , V_114 ,
L_272 ,
T_15 , V_270 , V_409 , V_407 , V_408 , V_272 ) ;
F_49 ( 2 , V_410 , V_398 ) ;
} else {
fprintf ( V_17 ,
L_273 ,
T_15 , V_270 , V_409 , V_407 , V_408 , V_272 ,
V_270 ? 100.0 * V_270 / ( V_270 + V_409 ) : 0.0 ) ;
fflush ( V_17 ) ;
}
}
static T_5
F_84 ( void )
{
T_31 V_411 = 0 ;
T_5 V_236 ;
if ( ! V_24 ) {
return TRUE ;
}
if ( ! V_380 || ! V_382 ) {
F_90 ( V_112 , V_113 ,
L_274 ) ;
return FALSE ;
}
V_236 = F_258 ( V_382 , NULL , 0 , NULL , & V_411 , NULL ) ;
if ( ! V_236 || V_411 > 0 ) {
F_90 ( V_112 , V_113 ,
L_275 , V_380 ) ;
F_90 ( V_112 , V_114 ,
L_276 , V_380 ,
V_382 , V_236 , V_411 ) ;
return FALSE ;
} else {
return TRUE ;
}
}
