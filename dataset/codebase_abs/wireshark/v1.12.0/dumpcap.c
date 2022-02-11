static void
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
V_5 -= F_8 ( 11644473600000000 ) ;
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
const char * V_29 ,
char * V_30 , T_12 V_31 ,
char * V_32 ,
T_12 V_33 )
{
#ifndef F_6
const char * V_34 ;
static const char V_35 [] = L_68 ;
#endif
F_31 ( V_30 , ( V_36 ) V_31 ,
L_69 ,
V_29 , V_28 ) ;
#ifdef F_6
if ( ! V_37 ) {
F_31 ( V_32 , ( V_36 ) V_33 ,
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
F_31 ( V_32 , ( V_36 ) V_33 ,
L_8
L_77
L_8
L_8
L_78
L_8
L_79
L_80 ,
V_29 ) ;
}
#else
if ( strncmp ( V_28 , V_35 , sizeof V_35 - 1 ) == 0 )
V_34 =
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
V_34 = L_63 ;
F_31 ( V_32 , ( V_36 ) V_33 ,
L_90
L_91 , V_34 ) ;
#endif
}
static T_5
F_32 ( T_13 * V_38 , int V_39 , char * V_40 ,
char * V_30 , T_12 V_31 ,
char * V_32 , T_12 V_33 )
{
char * V_41 ;
if ( V_39 == - 1 )
return TRUE ;
#ifdef F_33
if ( F_34 ( V_38 , V_39 ) == 0 )
return TRUE ;
V_41 = F_35 ( V_38 ) ;
#else
if ( F_36 ( V_38 , V_40 ) == V_39 )
return TRUE ;
V_41 =
L_92 ;
#endif
F_31 ( V_30 , ( V_36 ) V_31 , L_93 ,
V_40 , V_41 ) ;
if ( strstr ( V_41 , L_94 ) == NULL )
F_31 ( V_32 , ( V_36 ) V_33 , V_42 ) ;
else
V_32 [ 0 ] = '\0' ;
return FALSE ;
}
static T_5
F_37 ( const char * V_29 , T_13 * V_38 ,
struct V_43 * V_44 , const char * V_45 )
{
T_14 V_46 , V_47 ;
T_9 V_48 [ V_49 ] ;
if ( F_38 ( V_29 , & V_46 , & V_47 , V_48 ) < 0 ) {
V_47 = 0 ;
}
if ( F_39 ( V_38 , V_44 , ( char * ) V_45 , 1 , V_47 ) < 0 )
return FALSE ;
return TRUE ;
}
static T_5
F_40 ( T_15 * V_50 )
{
T_16 V_51 ;
T_13 * V_38 ;
T_9 V_28 [ V_49 ] ;
char V_30 [ V_52 + 1 ] ;
char V_32 [ V_52 + 1 ] ;
struct V_43 V_44 ;
struct V_53 * V_54 ;
T_17 V_55 ;
T_18 V_56 ;
for ( V_56 = 0 ; V_56 < V_50 -> V_57 -> V_58 ; V_56 ++ ) {
V_51 = F_41 ( V_50 -> V_57 , T_16 , V_56 ) ;
V_38 = F_42 ( & V_51 , & V_28 ) ;
if ( V_38 == NULL ) {
F_30 ( V_28 ,
V_51 . V_40 ,
V_30 , sizeof V_30 ,
V_32 ,
sizeof V_32 ) ;
F_43 ( V_30 , V_32 ) ;
return FALSE ;
}
if ( ! F_32 ( V_38 , V_51 . V_39 , V_51 . V_40 ,
V_30 , sizeof V_30 ,
V_32 , sizeof V_32 ) ) {
F_44 ( V_38 ) ;
F_43 ( V_30 , V_32 ) ;
return FALSE ;
}
if ( ! F_37 ( V_51 . V_40 , V_38 , & V_44 ,
V_51 . V_45 ) ) {
F_44 ( V_38 ) ;
F_45 ( V_50 , V_56 , V_30 ) ;
return FALSE ;
}
F_44 ( V_38 ) ;
V_54 = V_44 . V_59 ;
for ( V_55 = 0 ; V_55 < V_44 . V_60 ; V_54 ++ , V_55 ++ )
printf ( L_4 , F_46 ( V_54 , V_55 ) ) ;
}
#ifndef F_47
F_48 () ;
#else
F_25 () ;
#endif
if ( V_24 ) {
F_49 ( 2 , V_61 , NULL ) ;
}
return TRUE ;
}
static int
F_36 ( T_13 * V_62 , const char * T_19
#ifndef F_50
V_2
#endif
)
{
int V_39 ;
#ifdef F_50
const char * V_63 ;
#endif
V_39 = F_51 ( V_62 ) ;
#ifdef F_50
V_63 = strchr ( T_19 , '/' ) ;
if ( V_63 == NULL )
V_63 = T_19 ;
if ( strncmp ( V_63 , L_95 , 2 ) == 0 ) {
if ( V_39 == 6 ) {
V_39 = 1 ;
}
} else if ( strncmp ( V_63 , L_96 , 2 ) == 0 ) {
if ( V_39 == 7 ) {
V_39 = 1 ;
}
} else if ( strncmp ( V_63 , L_97 , 2 ) == 0 ) {
if ( V_39 == 9 ) {
V_39 = 6 ;
}
} else if ( strncmp ( V_63 , L_98 , 2 ) == 0 ) {
if ( V_39 == 15 ) {
V_39 = 10 ;
}
} else if ( strncmp ( V_63 , L_99 , 2 ) == 0 ) {
if ( V_39 == 24 ) {
V_39 = 0 ;
}
}
#endif
return V_39 ;
}
static T_20 *
F_52 ( int V_64 )
{
T_20 * V_65 ;
const char * V_66 ;
V_65 = ( T_20 * ) F_53 ( sizeof ( T_20 ) ) ;
V_65 -> V_64 = V_64 ;
V_66 = F_54 ( V_64 ) ;
if ( V_66 != NULL )
V_65 -> V_40 = F_55 ( V_66 ) ;
else
V_65 -> V_40 = F_56 ( L_100 , V_64 ) ;
V_66 = F_57 ( V_64 ) ;
if ( V_66 != NULL )
V_65 -> V_67 = F_55 ( V_66 ) ;
else
V_65 -> V_67 = NULL ;
return V_65 ;
}
static T_21 *
F_58 ( const char * T_19 , T_5 T_22
#ifndef F_11
V_2
#endif
, char * * V_68 )
{
T_21 * V_26 ;
char V_69 [ V_49 ] ;
T_13 * V_62 ;
#ifdef F_11
int V_70 ;
#endif
int V_71 ;
#ifdef F_59
int * V_72 ;
int V_55 , V_73 ;
#endif
T_20 * V_65 ;
V_26 = ( T_21 * ) F_53 ( sizeof *V_26 ) ;
V_69 [ 0 ] = '\0' ;
#ifdef F_60
V_62 = F_61 ( T_19 , V_74 , 0 , 0 , NULL , V_69 ) ;
V_26 -> V_75 = FALSE ;
if ( V_62 == NULL ) {
if ( V_68 != NULL )
* V_68 = F_55 ( V_69 [ 0 ] == '\0' ? L_101 : V_69 ) ;
F_22 ( V_26 ) ;
return NULL ;
}
#elif F_12 ( F_11 )
V_62 = F_62 ( T_19 , V_69 ) ;
if ( V_62 == NULL ) {
if ( V_68 != NULL )
* V_68 = F_55 ( V_69 ) ;
F_22 ( V_26 ) ;
return NULL ;
}
V_70 = F_63 ( V_62 ) ;
if ( V_70 < 0 ) {
if ( V_70 == V_76 )
* V_68 = F_56 ( L_102 ,
F_35 ( V_62 ) ) ;
else
* V_68 = F_55 ( F_64 ( V_70 ) ) ;
F_44 ( V_62 ) ;
F_22 ( V_26 ) ;
return NULL ;
}
if ( V_70 == 0 )
V_26 -> V_75 = FALSE ;
else if ( V_70 == 1 ) {
V_26 -> V_75 = TRUE ;
if ( T_22 )
F_65 ( V_62 , 1 ) ;
} else {
if ( V_68 != NULL ) {
* V_68 = F_56 ( L_103 ,
V_70 ) ;
}
F_44 ( V_62 ) ;
F_22 ( V_26 ) ;
return NULL ;
}
V_70 = F_66 ( V_62 ) ;
if ( V_70 < 0 ) {
if ( V_68 != NULL ) {
if ( V_70 == V_76 )
* V_68 = F_56 ( L_104 ,
F_35 ( V_62 ) ) ;
else
* V_68 = F_55 ( F_64 ( V_70 ) ) ;
}
F_44 ( V_62 ) ;
F_22 ( V_26 ) ;
return NULL ;
}
#else
V_62 = F_67 ( T_19 , V_74 , 0 , 0 , V_69 ) ;
V_26 -> V_75 = FALSE ;
if ( V_62 == NULL ) {
if ( V_68 != NULL )
* V_68 = F_55 ( V_69 [ 0 ] == '\0' ? L_101 : V_69 ) ;
F_22 ( V_26 ) ;
return NULL ;
}
#endif
V_71 = F_36 ( V_62 , T_19 ) ;
#ifdef F_59
V_73 = F_68 ( V_62 , & V_72 ) ;
if ( V_73 == 0 || V_72 == NULL ) {
F_44 ( V_62 ) ;
if ( V_68 != NULL )
* V_68 = NULL ;
F_22 ( V_26 ) ;
return NULL ;
}
V_26 -> V_77 = NULL ;
for ( V_55 = 0 ; V_55 < V_73 ; V_55 ++ ) {
V_65 = F_52 ( V_72 [ V_55 ] ) ;
if ( V_72 [ V_55 ] == V_71 )
V_26 -> V_77 = F_69 ( V_26 -> V_77 ,
V_65 ) ;
else
V_26 -> V_77 = F_70 ( V_26 -> V_77 ,
V_65 ) ;
}
#ifdef F_71
F_72 ( V_72 ) ;
#else
#ifndef F_6
#define F_73 free
F_73 ( V_72 ) ;
#endif
#endif
#else
V_65 = F_52 ( V_71 ) ;
V_26 -> V_77 = F_70 ( V_26 -> V_77 ,
V_65 ) ;
#endif
F_44 ( V_62 ) ;
if ( V_68 != NULL )
* V_68 = NULL ;
return V_26 ;
}
static void
F_74 ( T_23 * V_78 )
{
int V_55 ;
T_23 * V_79 ;
T_24 * V_80 ;
T_25 * V_81 ;
T_26 * V_82 ;
char V_83 [ V_84 ] ;
if ( V_24 ) {
F_49 ( 2 , V_61 , NULL ) ;
}
V_55 = 1 ;
for ( V_79 = F_75 ( V_78 ) ; V_79 != NULL ;
V_79 = F_76 ( V_79 ) ) {
V_80 = ( T_24 * ) V_79 -> V_85 ;
printf ( L_105 , V_55 ++ , V_80 -> V_40 ) ;
if ( V_80 -> V_86 != NULL )
printf ( L_106 , V_80 -> V_86 ) ;
else
printf ( L_107 ) ;
if ( V_80 -> V_87 != NULL )
printf ( L_106 , V_80 -> V_87 ) ;
else
printf ( L_107 ) ;
printf ( L_108 , V_80 -> type ) ;
for ( V_81 = F_77 ( V_80 -> V_88 , 0 ) ; V_81 != NULL ;
V_81 = F_78 ( V_81 ) ) {
if ( V_81 != F_77 ( V_80 -> V_88 , 0 ) )
printf ( L_109 ) ;
V_82 = ( T_26 * ) V_81 -> V_85 ;
switch( V_82 -> V_89 ) {
case V_90 :
if ( F_79 ( V_91 , & V_82 -> V_81 . V_92 , V_83 ,
V_84 ) ) {
printf ( L_110 , V_83 ) ;
} else {
printf ( L_111 ) ;
}
break;
case V_93 :
if ( F_79 ( V_94 , & V_82 -> V_81 . V_95 ,
V_83 , V_84 ) ) {
printf ( L_110 , V_83 ) ;
} else {
printf ( L_112 ) ;
}
break;
default:
printf ( L_113 , V_82 -> V_89 ) ;
}
}
if ( V_80 -> V_96 )
printf ( L_114 ) ;
else
printf ( L_115 ) ;
printf ( L_8 ) ;
}
}
static void
F_80 ( T_21 * V_26 )
{
T_23 * V_97 ;
T_20 * V_65 ;
const T_9 * V_98 ;
if ( V_24 ) {
F_49 ( 2 , V_61 , NULL ) ;
}
if ( V_26 -> V_75 )
printf ( L_116 ) ;
else
printf ( L_117 ) ;
for ( V_97 = V_26 -> V_77 ; V_97 != NULL ;
V_97 = F_76 ( V_97 ) ) {
V_65 = ( T_20 * ) V_97 -> V_85 ;
if ( V_65 -> V_67 != NULL )
V_98 = V_65 -> V_67 ;
else
V_98 = L_118 ;
printf ( L_119 , V_65 -> V_64 , V_65 -> V_40 ,
V_98 ) ;
}
}
static int
F_81 ( T_5 V_99 )
{
T_23 * V_78 , * V_79 , * V_100 = NULL , * V_101 ;
T_24 * V_80 ;
T_27 * V_102 ;
int V_103 ;
T_9 * V_68 ;
T_13 * V_62 ;
char V_69 [ V_49 ] ;
struct V_104 V_105 ;
V_78 = F_82 ( & V_103 , & V_68 ) ;
if ( V_78 == NULL ) {
switch ( V_103 ) {
case V_106 :
case V_107 :
F_19 ( L_110 , V_68 ) ;
F_22 ( V_68 ) ;
break;
case V_108 :
F_19 ( L_120 ) ;
break;
}
return V_103 ;
}
for ( V_79 = F_75 ( V_78 ) ; V_79 != NULL ; V_79 = F_76 ( V_79 ) ) {
V_80 = ( T_24 * ) V_79 -> V_85 ;
#ifdef F_60
V_62 = F_61 ( V_80 -> V_40 , V_74 , 0 , 0 , NULL , V_69 ) ;
#else
V_62 = F_67 ( V_80 -> V_40 , V_74 , 0 , 0 , V_69 ) ;
#endif
if ( V_62 ) {
V_102 = ( T_27 * ) F_53 ( sizeof( T_27 ) ) ;
V_102 -> V_40 = F_55 ( V_80 -> V_40 ) ;
V_102 -> V_62 = V_62 ;
V_100 = F_70 ( V_100 , V_102 ) ;
}
}
if ( ! V_100 ) {
F_19 ( L_120 ) ;
return 2 ;
}
if ( V_24 ) {
F_49 ( 2 , V_61 , NULL ) ;
}
if ( ! V_99 ) {
printf ( L_121 , L_122 , L_123 ,
L_124 ) ;
}
V_109 . V_110 = TRUE ;
while ( V_109 . V_110 ) {
for ( V_101 = F_75 ( V_100 ) ; V_101 != NULL ; V_101 = F_76 ( V_101 ) ) {
V_102 = ( T_27 * ) V_101 -> V_85 ;
F_83 ( V_102 -> V_62 , & V_105 ) ;
if ( ! V_99 ) {
printf ( L_125 , V_102 -> V_40 ,
V_105 . V_111 , V_105 . V_112 ) ;
} else {
printf ( L_126 , V_102 -> V_40 ,
V_105 . V_111 , V_105 . V_112 ) ;
fflush ( stdout ) ;
}
}
#ifdef F_6
if ( ! F_84 () ) {
V_109 . V_110 = FALSE ;
}
F_85 ( 1 * 1000 ) ;
#else
F_86 ( 1 ) ;
#endif
}
for ( V_101 = F_75 ( V_100 ) ; V_101 != NULL ; V_101 = F_76 ( V_101 ) ) {
V_102 = ( T_27 * ) V_101 -> V_85 ;
F_44 ( V_102 -> V_62 ) ;
F_22 ( V_102 -> V_40 ) ;
F_22 ( V_102 ) ;
}
F_87 ( V_100 ) ;
F_88 ( V_78 ) ;
return 0 ;
}
static BOOL T_28
F_89 ( T_29 V_113 )
{
F_90 ( V_114 , V_115 ,
L_127 ) ;
F_90 ( V_114 , V_116 ,
L_128 , V_113 ) ;
if ( V_24 || ( V_113 != V_117 ) ) {
F_91 () ;
return TRUE ;
} else {
return FALSE ;
}
}
static void
F_89 ( int T_30 V_2 )
{
F_91 () ;
}
static void
F_92 ( T_5 V_118 )
{
if ( ! V_24 && V_118 ) {
fprintf ( V_17 , L_129 , V_109 . V_119 ) ;
fflush ( V_17 ) ;
}
}
static void
F_93 ( void )
{
F_92 ( V_120 ) ;
V_121 = FALSE ;
}
static void
F_94 ( int T_30 V_2 )
{
int V_122 = V_27 ;
if ( V_123 )
V_121 = TRUE ;
else
F_93 () ;
V_27 = V_122 ;
}
static void
F_95 ( int V_70 )
{
#ifdef F_6
F_96 () ;
#ifdef F_97
printf ( L_130 ) ;
F_98 () ;
#endif
#endif
exit ( V_70 ) ;
}
static void
F_99 ( void )
{
if ( F_100 () ) {
T_31 V_124 [ 2 ] = { V_125 , V_126 } ;
int V_127 = sizeof( V_124 ) / sizeof( T_31 ) ;
T_11 V_26 = F_26 () ;
F_24 ( L_131 ) ;
if ( F_101 ( V_128 , 1 , 0 , 0 , 0 ) == - 1 ) {
F_19 ( L_132 , F_28 ( V_27 ) ) ;
}
F_102 ( V_26 , V_129 , V_127 , V_124 , V_130 ) ;
F_102 ( V_26 , V_131 , V_127 , V_124 , V_130 ) ;
if ( F_27 ( V_26 ) ) {
F_19 ( L_66 , F_28 ( V_27 ) ) ;
}
F_24 ( L_133 ) ;
F_48 () ;
F_24 ( L_134 ) ;
F_102 ( V_26 , V_132 , V_127 , V_124 , V_130 ) ;
if ( F_27 ( V_26 ) ) {
F_19 ( L_66 , F_28 ( V_27 ) ) ;
}
F_24 ( L_135 ) ;
F_29 ( V_26 ) ;
}
}
static void
F_103 ( T_5 V_133 , struct V_134 * V_135 , struct V_136 * V_137 )
{
if ( V_133 ) {
V_137 -> V_138 = F_104 ( V_137 -> V_138 ) ;
V_137 -> V_139 = F_104 ( V_137 -> V_139 ) ;
V_137 -> V_140 = F_104 ( V_137 -> V_140 ) ;
V_137 -> V_141 = F_104 ( V_137 -> V_141 ) ;
}
if ( V_135 -> V_142 == 2 &&
( V_135 -> V_143 < 3 ||
( V_135 -> V_143 == 3 && V_137 -> V_140 > V_137 -> V_141 ) ) ) {
V_8 V_144 ;
V_144 = V_137 -> V_141 ;
V_137 -> V_141 = V_137 -> V_140 ;
V_137 -> V_140 = V_144 ;
}
}
static T_1
F_105 ( int V_145 , char * V_146 , T_12 V_147 , T_5 T_32 V_2 )
{
#ifdef F_6
if ( T_32 ) {
return F_106 ( V_145 , V_146 , ( int ) V_147 , 0 ) ;
} else {
return - 1 ;
}
#else
return F_107 ( V_145 , V_146 , V_147 ) ;
#endif
}
static void * F_108 ( void * V_148 )
{
T_33 * V_149 ;
#ifdef F_6
BOOL V_150 ;
T_29 V_151 , V_152 , V_153 ;
#else
T_12 V_153 ;
int V_151 ;
#endif
V_149 = ( T_33 * ) V_148 ;
while ( V_149 -> V_154 == V_155 ) {
F_109 ( V_149 -> V_156 ) ;
F_110 ( V_149 -> V_157 ) ;
V_153 = 0 ;
while ( V_153 < V_149 -> V_158 ) {
if ( ( V_149 -> V_159 )
#ifndef F_6
|| 1
#endif
)
{
V_151 = F_105 ( V_149 -> V_160 , V_149 -> V_161 + V_153 ,
V_149 -> V_158 - V_153 , V_149 -> V_159 ) ;
if ( V_151 <= 0 ) {
if ( V_151 == 0 ) {
V_149 -> V_154 = V_162 ;
V_153 = 0 ;
break;
} else {
V_149 -> V_154 = V_163 ;
V_153 = - 1 ;
break;
}
} else {
V_153 += V_151 ;
}
}
#ifdef F_6
else
{
V_150 = F_111 ( V_149 -> V_164 , V_149 -> V_161 + V_153 ,
V_149 -> V_158 - V_153 ,
& V_151 , NULL ) ;
V_153 += V_151 ;
if ( ! V_150 ) {
V_152 = F_112 () ;
if ( V_152 == V_165 ) {
continue;
} else if ( V_152 == V_166 || V_152 == V_167 || V_152 == V_168 ) {
V_149 -> V_154 = V_162 ;
V_153 = 0 ;
break;
}
V_149 -> V_154 = V_163 ;
V_153 = - 1 ;
break;
} else if ( V_151 == 0 && V_149 -> V_158 > 0 ) {
V_149 -> V_154 = V_162 ;
V_153 = 0 ;
break;
}
}
#endif
}
V_149 -> V_169 = V_153 ;
if ( V_149 -> V_169 >= V_149 -> V_158 ) {
F_113 ( V_149 -> V_170 , V_149 -> V_161 ) ;
}
F_114 ( V_149 -> V_157 ) ;
}
return NULL ;
}
static int
F_115 ( int V_145 )
{
T_34 V_171 ;
struct V_7 V_172 ;
F_116 ( & V_171 ) ;
F_117 ( V_145 , & V_171 ) ;
V_172 . V_11 = V_173 / 1000000 ;
V_172 . V_12 = V_173 % 1000000 ;
return F_118 ( V_145 + 1 , & V_171 , NULL , NULL , & V_172 ) ;
}
static int
F_119 ( char * V_174 , T_33 * V_149 , char * V_30 , int V_175 )
{
char * V_176 = V_174 + 4 ;
struct V_177 V_178 ;
char V_146 [ 16 ] ;
char * V_179 ;
unsigned long V_180 ;
T_12 V_58 ;
int V_1 ;
memset ( & V_178 , 0 , sizeof( V_178 ) ) ;
V_179 = strchr ( V_176 , ':' ) ;
if ( V_179 == NULL ) {
V_58 = strlen ( V_176 ) ;
V_180 = V_181 ;
}
else {
V_58 = V_179 - V_176 ;
V_180 = strtoul ( V_179 + 1 , & V_179 , 10 ) ;
if ( * V_179 || V_180 > 65535 ) {
goto V_182;
}
}
if ( V_58 > 15 ) {
goto V_182;
}
strncpy ( V_146 , V_176 , V_58 ) ;
V_146 [ V_58 ] = '\0' ;
if ( F_120 ( V_91 , V_146 , & V_178 . V_183 ) <= 0 ) {
goto V_182;
}
V_178 . V_184 = V_91 ;
V_178 . V_185 = F_121 ( ( V_186 ) V_180 ) ;
if ( ( ( V_1 = ( int ) F_122 ( V_91 , V_187 , 0 ) ) < 0 ) ||
( F_123 ( V_1 , (struct V_188 * ) & V_178 , sizeof( V_178 ) ) < 0 ) ) {
#ifdef F_6
T_35 V_189 = NULL ;
int V_190 ;
V_190 = F_124 () ;
F_125 ( V_191 |
V_192 |
V_193 ,
NULL , V_190 , F_126 ( V_194 , V_195 ) ,
( T_35 ) & V_189 , 0 , NULL ) ;
#endif
F_31 ( V_30 , V_175 ,
L_136
#ifdef F_6
L_137 , V_190 , V_189 ? ( char * ) V_189 : L_138 ) ;
if ( V_189 )
F_127 ( V_189 ) ;
#else
L_139 , V_27 , strerror ( V_27 ) ) ;
#endif
V_149 -> V_154 = V_163 ;
if ( V_1 >= 0 )
F_128 ( V_1 , TRUE ) ;
return - 1 ;
}
void
F_128 ( int V_145 , T_5 T_32 V_2 )
{
#ifdef F_6
if ( T_32 ) {
F_129 ( V_145 ) ;
}
#else
F_130 ( V_145 ) ;
#endif
}
static void
F_131 ( char * V_174 ,
T_33 * V_149 ,
struct V_134 * V_135 ,
char * V_30 , int V_175 )
{
#ifndef F_6
T_36 V_196 ;
struct V_197 V_178 ;
#else
char * V_198 , * V_199 ;
T_37 * V_68 ;
#endif
T_1 V_151 ;
int V_1 = - 1 , V_200 ;
T_12 V_153 ;
V_8 V_201 = 0 ;
V_149 -> V_160 = - 1 ;
#ifdef F_6
V_149 -> V_164 = V_202 ;
#endif
F_90 ( V_114 , V_116 , L_140 , V_174 ) ;
if ( strcmp ( V_174 , L_141 ) == 0 ) {
#ifndef F_6
V_1 = 0 ;
#else
V_149 -> V_164 = F_132 ( V_203 ) ;
#endif
} else if ( ! strncmp ( V_174 , L_142 , 4 ) ) {
if ( ( V_1 = F_119 ( V_174 , V_149 , V_30 , V_175 ) ) < 0 ) {
return;
}
} else {
#ifndef F_6
if ( F_133 ( V_174 , & V_196 ) < 0 ) {
if ( V_27 == V_204 || V_27 == V_205 )
V_149 -> V_154 = V_206 ;
else {
F_31 ( V_30 , V_175 ,
L_143
L_144 , F_28 ( V_27 ) ) ;
V_149 -> V_154 = V_163 ;
}
return;
}
if ( F_134 ( V_196 . V_207 ) ) {
V_1 = F_135 ( V_174 , V_208 | V_209 , 0000 ) ;
if ( V_1 == - 1 ) {
F_31 ( V_30 , V_175 ,
L_143
L_145 , F_28 ( V_27 ) ) ;
V_149 -> V_154 = V_163 ;
return;
}
} else if ( F_136 ( V_196 . V_207 ) ) {
V_1 = F_122 ( V_210 , V_187 , 0 ) ;
if ( V_1 == - 1 ) {
F_31 ( V_30 , V_175 ,
L_143
L_146 , F_28 ( V_27 ) ) ;
V_149 -> V_154 = V_163 ;
return;
}
V_178 . V_211 = V_210 ;
if ( F_137 ( V_178 . V_212 , V_174 , sizeof V_178 . V_212 ) > sizeof V_178 . V_212 ) {
F_31 ( V_30 , V_175 ,
L_147
L_148 ) ;
V_149 -> V_154 = V_163 ;
F_130 ( V_1 ) ;
return;
}
V_151 = F_123 ( V_1 , (struct V_188 * ) & V_178 , sizeof V_178 ) ;
if ( V_151 == - 1 ) {
F_31 ( V_30 , V_175 ,
L_147
L_149 , F_28 ( V_27 ) ) ;
V_149 -> V_154 = V_163 ;
F_130 ( V_1 ) ;
return;
}
} else {
if ( F_138 ( V_196 . V_207 ) ) {
V_149 -> V_154 = V_206 ;
} else {
F_31 ( V_30 , V_175 ,
L_150
L_151 , V_174 ) ;
V_149 -> V_154 = V_163 ;
}
return;
}
#else
#define F_139 "\\pipe\\"
V_198 = F_55 ( V_174 ) ;
if ( ( V_199 = strstr ( V_198 , L_152 ) ) == V_198 ) {
V_199 = strchr ( V_198 + 3 , '\\' ) ;
if ( V_199 && F_140 ( V_199 , F_139 , strlen ( F_139 ) ) != 0 )
V_199 = NULL ;
}
F_22 ( V_198 ) ;
if ( ! V_199 ) {
F_31 ( V_30 , V_175 ,
L_150
L_153 , V_174 ) ;
V_149 -> V_154 = V_206 ;
return;
}
while ( 1 ) {
V_149 -> V_164 = F_141 ( F_142 ( V_174 ) , V_213 , 0 , NULL ,
V_214 , 0 , NULL ) ;
if ( V_149 -> V_164 != V_202 )
break;
if ( F_112 () != V_215 ) {
F_125 ( V_191 | V_192 | V_193 ,
NULL , F_112 () , 0 , ( T_35 ) & V_68 , 0 , NULL ) ;
F_31 ( V_30 , V_175 ,
L_154
L_155 ,
V_174 , F_143 ( V_68 ) , F_112 () ) ;
F_127 ( V_68 ) ;
V_149 -> V_154 = V_163 ;
return;
}
if ( ! F_144 ( F_142 ( V_174 ) , 30 * 1000 ) ) {
F_125 ( V_191 | V_192 | V_193 ,
NULL , F_112 () , 0 , ( T_35 ) & V_68 , 0 , NULL ) ;
F_31 ( V_30 , V_175 ,
L_156
L_157 ,
V_174 , F_143 ( V_68 ) , F_112 () ) ;
F_127 ( V_68 ) ;
V_149 -> V_154 = V_163 ;
return;
}
}
#endif
}
V_149 -> V_216 = TRUE ;
#ifdef F_6
if ( V_149 -> V_159 )
#endif
{
V_153 = 0 ;
while ( V_153 < sizeof V_201 ) {
if ( V_1 == - 1 ) {
F_31 ( V_30 , V_175 , L_158 ) ;
goto error;
}
V_200 = F_115 ( V_1 ) ;
if ( V_200 < 0 ) {
F_31 ( V_30 , V_175 ,
L_159 , F_28 ( V_27 ) ) ;
goto error;
} else if ( V_200 > 0 ) {
V_151 = F_105 ( V_1 , ( ( char * ) & V_201 ) + V_153 ,
sizeof V_201 - V_153 ,
V_149 -> V_159 ) ;
if ( V_151 <= 0 ) {
if ( V_151 == 0 )
F_31 ( V_30 , V_175 , L_160 ) ;
else
F_31 ( V_30 , V_175 , L_161 ,
F_28 ( V_27 ) ) ;
goto error;
}
V_153 += V_151 ;
}
}
}
#ifdef F_6
else {
#if F_145 ( 2 , 31 , 0 )
F_146 ( L_162 , & F_108 , V_149 ) ;
#else
F_147 ( & F_108 , V_149 , FALSE , NULL ) ;
#endif
V_149 -> V_161 = ( char * ) & V_201 ;
V_149 -> V_169 = 0 ;
V_149 -> V_158 = sizeof( V_201 ) ;
F_113 ( V_149 -> V_156 , V_149 -> V_161 ) ;
F_109 ( V_149 -> V_170 ) ;
if ( V_149 -> V_169 <= 0 ) {
if ( V_149 -> V_169 == 0 )
F_31 ( V_30 , V_175 , L_160 ) ;
else
F_31 ( V_30 , V_175 , L_161 ,
F_28 ( V_27 ) ) ;
goto error;
}
}
#endif
switch ( V_201 ) {
case V_217 :
case V_218 :
V_149 -> V_219 = FALSE ;
V_149 -> V_220 = FALSE ;
V_149 -> V_221 = V_201 == V_218 ;
break;
case V_222 :
V_149 -> V_219 = FALSE ;
V_149 -> V_220 = TRUE ;
break;
case V_223 :
case V_224 :
V_149 -> V_219 = TRUE ;
V_149 -> V_220 = FALSE ;
V_149 -> V_221 = V_201 == V_224 ;
break;
case V_225 :
V_149 -> V_219 = TRUE ;
V_149 -> V_220 = TRUE ;
break;
default:
F_31 ( V_30 , V_175 , L_163 ) ;
goto error;
}
#ifdef F_6
if ( V_149 -> V_159 )
#endif
{
V_153 = 0 ;
while ( V_153 < sizeof( struct V_134 ) ) {
V_200 = F_115 ( V_1 ) ;
if ( V_200 < 0 ) {
F_31 ( V_30 , V_175 ,
L_159 , F_28 ( V_27 ) ) ;
goto error;
} else if ( V_200 > 0 ) {
V_151 = F_105 ( V_1 , ( ( char * ) V_135 ) + V_153 ,
sizeof( struct V_134 ) - V_153 ,
V_149 -> V_159 ) ;
if ( V_151 <= 0 ) {
if ( V_151 == 0 )
F_31 ( V_30 , V_175 , L_164 ) ;
else
F_31 ( V_30 , V_175 , L_165 ,
F_28 ( V_27 ) ) ;
goto error;
}
V_153 += V_151 ;
}
}
}
#ifdef F_6
else {
V_149 -> V_161 = ( char * ) V_135 ;
V_149 -> V_169 = 0 ;
V_149 -> V_158 = sizeof( struct V_134 ) ;
F_113 ( V_149 -> V_156 , V_149 -> V_161 ) ;
F_109 ( V_149 -> V_170 ) ;
if ( V_149 -> V_169 <= 0 ) {
if ( V_149 -> V_169 == 0 )
F_31 ( V_30 , V_175 , L_164 ) ;
else
F_31 ( V_30 , V_175 , L_166 ,
F_28 ( V_27 ) ) ;
goto error;
}
}
#endif
if ( V_149 -> V_219 ) {
V_135 -> V_142 = F_148 ( V_135 -> V_142 ) ;
V_135 -> V_143 = F_148 ( V_135 -> V_143 ) ;
V_135 -> V_226 = F_104 ( V_135 -> V_226 ) ;
V_135 -> V_227 = F_104 ( V_135 -> V_227 ) ;
}
V_149 -> V_39 = V_135 -> V_227 ;
if ( V_135 -> V_142 < 2 ) {
F_31 ( V_30 , V_175 , L_167 ) ;
goto error;
}
V_149 -> V_228 = V_229 ;
V_149 -> V_154 = V_155 ;
V_149 -> V_160 = V_1 ;
return;
error:
F_90 ( V_114 , V_116 , L_168 , V_30 ) ;
V_149 -> V_154 = V_163 ;
F_128 ( V_1 , V_149 -> V_159 ) ;
V_149 -> V_160 = - 1 ;
}
static int
F_149 ( T_38 * V_230 , T_33 * V_149 , T_39 * V_85 , char * V_30 , int V_175 )
{
struct V_231 V_232 ;
enum { V_233 , V_234 , V_235 , V_236 ,
V_237 } V_238 ;
#ifdef F_6
#if ! F_145 ( 2 , 31 , 18 )
T_40 V_239 ;
#endif
T_41 V_240 ;
T_37 * V_68 ;
#endif
T_1 V_151 ;
#ifdef F_150
F_90 ( V_114 , V_116 , L_169 ) ;
#endif
switch ( V_149 -> V_228 ) {
case V_229 :
#ifdef F_6
if ( F_151 ( V_149 -> V_157 ) ) {
#endif
V_149 -> V_228 = V_241 ;
V_149 -> V_158 = V_149 -> V_220 ?
sizeof( struct V_242 ) : sizeof( struct V_136 ) ;
V_149 -> V_169 = 0 ;
#ifdef F_6
V_149 -> V_161 = ( char * ) & V_149 -> V_243 ;
F_113 ( V_149 -> V_156 , V_149 -> V_161 ) ;
F_114 ( V_149 -> V_157 ) ;
}
#endif
case V_241 :
#ifdef F_6
if ( V_149 -> V_159 )
#endif
{
V_151 = F_105 ( V_149 -> V_160 , ( ( char * ) & V_149 -> V_243 ) + V_149 -> V_169 ,
V_149 -> V_158 - V_149 -> V_169 , V_149 -> V_159 ) ;
if ( V_151 <= 0 ) {
if ( V_151 == 0 )
V_238 = V_235 ;
else
V_238 = V_236 ;
break;
}
V_149 -> V_169 += V_151 ;
}
#ifdef F_6
else {
#if F_145 ( 2 , 31 , 18 )
V_240 = F_152 ( V_149 -> V_170 , V_173 ) ;
#else
F_153 ( & V_239 ) ;
F_154 ( & V_239 , V_173 ) ;
V_240 = F_155 ( V_149 -> V_170 , & V_239 ) ;
#endif
if ( V_149 -> V_154 == V_162 ) {
V_238 = V_235 ;
break;
} else if ( V_149 -> V_154 == V_163 ) {
V_238 = V_236 ;
break;
}
if ( ! V_240 ) {
return 0 ;
}
}
#endif
if ( V_149 -> V_169 < V_149 -> V_158 )
return 0 ;
V_238 = V_233 ;
break;
case V_244 :
#ifdef F_6
if ( F_151 ( V_149 -> V_157 ) ) {
#endif
V_149 -> V_228 = V_245 ;
V_149 -> V_158 = V_149 -> V_243 . V_135 . V_140 ;
V_149 -> V_169 = 0 ;
#ifdef F_6
V_149 -> V_161 = ( char * ) V_85 ;
F_113 ( V_149 -> V_156 , V_149 -> V_161 ) ;
F_114 ( V_149 -> V_157 ) ;
}
#endif
case V_245 :
#ifdef F_6
if ( V_149 -> V_159 )
#endif
{
V_151 = F_105 ( V_149 -> V_160 ,
V_85 + V_149 -> V_169 ,
V_149 -> V_158 - V_149 -> V_169 ,
V_149 -> V_159 ) ;
if ( V_151 <= 0 ) {
if ( V_151 == 0 )
V_238 = V_235 ;
else
V_238 = V_236 ;
break;
}
V_149 -> V_169 += V_151 ;
}
#ifdef F_6
else {
#if F_145 ( 2 , 31 , 18 )
V_240 = F_152 ( V_149 -> V_170 , V_173 ) ;
#else
F_153 ( & V_239 ) ;
F_154 ( & V_239 , V_173 ) ;
V_240 = F_155 ( V_149 -> V_170 , & V_239 ) ;
#endif
if ( V_149 -> V_154 == V_162 ) {
V_238 = V_235 ;
break;
} else if ( V_149 -> V_154 == V_163 ) {
V_238 = V_236 ;
break;
}
if ( ! V_240 ) {
return 0 ;
}
}
#endif
if ( V_149 -> V_169 < V_149 -> V_158 )
return 0 ;
V_238 = V_234 ;
break;
default:
F_31 ( V_30 , V_175 , L_170 ) ;
V_238 = V_237 ;
}
switch ( V_238 ) {
case V_233 :
F_103 ( V_149 -> V_219 , & V_149 -> V_246 ,
& V_149 -> V_243 . V_135 ) ;
if ( V_149 -> V_243 . V_135 . V_140 > V_247 ) {
F_31 ( V_30 , V_175 , L_171 ,
V_230 -> V_119 + 1 , V_149 -> V_243 . V_135 . V_140 ) ;
break;
}
if ( V_149 -> V_243 . V_135 . V_140 ) {
V_149 -> V_228 = V_244 ;
return 0 ;
}
case V_234 :
V_232 . V_248 . V_11 = V_149 -> V_243 . V_135 . V_138 ;
V_232 . V_248 . V_12 = V_149 -> V_243 . V_135 . V_139 ;
V_232 . V_249 = V_149 -> V_243 . V_135 . V_140 ;
V_232 . V_58 = V_149 -> V_243 . V_135 . V_141 ;
if ( V_250 ) {
F_156 ( ( V_251 * ) V_149 , & V_232 , V_85 ) ;
} else {
F_157 ( ( V_251 * ) V_149 , & V_232 , V_85 ) ;
}
V_149 -> V_228 = V_229 ;
return 1 ;
case V_235 :
V_149 -> V_154 = V_162 ;
return - 1 ;
case V_236 :
#ifdef F_6
F_125 ( V_191 | V_192 | V_193 ,
NULL , F_112 () , 0 , ( T_35 ) & V_68 , 0 , NULL ) ;
F_31 ( V_30 , V_175 ,
L_172 ,
F_143 ( V_68 ) , F_112 () ) ;
F_127 ( V_68 ) ;
#else
F_31 ( V_30 , V_175 , L_173 ,
F_28 ( V_27 ) ) ;
#endif
case V_237 :
break;
}
V_149 -> V_154 = V_163 ;
return - 1 ;
}
static void F_158 ( T_38 * V_230 )
{
T_18 V_55 ;
T_33 * V_149 ;
F_90 ( V_114 , V_116 , L_174 ) ;
for ( V_55 = 0 ; V_55 < V_230 -> V_252 -> V_58 ; V_55 ++ ) {
V_149 = F_41 ( V_230 -> V_252 , T_33 * , V_55 ) ;
if ( V_149 -> V_160 >= 0 ) {
F_159 ( V_149 -> V_216 ) ;
F_128 ( V_149 -> V_160 , V_149 -> V_159 ) ;
V_149 -> V_160 = - 1 ;
}
#ifdef F_6
if ( V_149 -> V_164 != V_202 ) {
F_160 ( V_149 -> V_164 ) ;
V_149 -> V_164 = V_202 ;
}
#endif
if ( V_149 -> V_38 != NULL ) {
F_90 ( V_114 , V_116 , L_175 , ( void * ) V_149 -> V_38 ) ;
F_44 ( V_149 -> V_38 ) ;
V_149 -> V_38 = NULL ;
}
}
V_230 -> V_110 = FALSE ;
#ifdef F_6
F_96 () ;
#endif
}
static T_42
F_161 ( T_13 * V_38 , T_5 V_216 ,
const T_9 * V_40 , const T_9 * V_45 )
{
struct V_43 V_44 ;
F_90 ( V_114 , V_116 , L_176 , V_45 ) ;
if ( V_45 && ! V_216 ) {
if ( ! F_37 ( V_40 , V_38 , & V_44 , V_45 ) ) {
return V_253 ;
}
if ( F_162 ( V_38 , & V_44 ) < 0 ) {
#ifdef F_163
F_164 ( & V_44 ) ;
#endif
return V_254 ;
}
#ifdef F_163
F_164 ( & V_44 ) ;
#endif
}
return V_255 ;
}
static T_5
F_165 ( T_15 * V_50 , T_38 * V_230 , char * V_30 , int V_31 )
{
int V_103 ;
T_18 V_55 ;
T_33 * V_149 ;
T_16 V_51 ;
T_5 V_256 ;
F_90 ( V_114 , V_116 , L_177 ) ;
if ( ( V_50 -> V_257 == FALSE ) &&
( V_50 -> V_57 -> V_58 > 1 ) ) {
F_31 ( V_30 , V_31 ,
L_178 ) ;
return FALSE ;
}
if ( V_50 -> V_258 ) {
V_230 -> V_259 = F_166 ( & V_103 ) ;
} else {
V_230 -> V_259 = F_167 ( V_230 -> V_260 , L_179 ) ;
if ( V_230 -> V_259 == NULL ) {
V_103 = V_27 ;
}
}
if ( V_230 -> V_259 ) {
if ( V_50 -> V_257 ) {
char V_261 [ 100 ] ;
T_7 * V_262 ;
V_262 = F_168 ( L_63 ) ;
F_169 ( V_262 ) ;
F_31 ( V_261 , sizeof( V_261 ) , L_3 V_15 L_110 , V_16 ) ;
V_256 = F_170 ( V_230 -> V_259 ,
( const char * ) V_50 -> V_263 ,
NULL ,
V_262 -> V_21 ,
V_261 ,
- 1 ,
& V_230 -> V_264 ,
& V_103 ) ;
for ( V_55 = 0 ; V_256 && ( V_55 < V_50 -> V_57 -> V_58 ) ; V_55 ++ ) {
V_51 = F_41 ( V_50 -> V_57 , T_16 , V_55 ) ;
V_149 = F_41 ( V_230 -> V_252 , T_33 * , V_55 ) ;
if ( V_149 -> V_216 ) {
V_149 -> V_226 = V_149 -> V_246 . V_226 ;
} else {
V_149 -> V_226 = F_171 ( V_149 -> V_38 ) ;
}
V_256 = F_172 ( V_109 . V_259 ,
NULL ,
V_51 . V_40 ,
V_51 . V_265 ,
V_51 . V_45 ,
V_262 -> V_21 ,
V_149 -> V_39 ,
V_149 -> V_226 ,
& ( V_109 . V_264 ) ,
0 ,
V_149 -> V_221 ? 9 : 6 ,
& V_109 . V_103 ) ;
}
F_173 ( V_262 , TRUE ) ;
} else {
V_149 = F_41 ( V_230 -> V_252 , T_33 * , 0 ) ;
if ( V_149 -> V_216 ) {
V_149 -> V_226 = V_149 -> V_246 . V_226 ;
} else {
V_149 -> V_226 = F_171 ( V_149 -> V_38 ) ;
}
V_256 = F_174 ( V_230 -> V_259 , V_149 -> V_39 , V_149 -> V_226 ,
V_149 -> V_221 , & V_230 -> V_264 , & V_103 ) ;
}
if ( ! V_256 ) {
fclose ( V_230 -> V_259 ) ;
V_230 -> V_259 = NULL ;
}
}
if ( V_230 -> V_259 == NULL ) {
switch ( V_103 ) {
default:
if ( V_103 < 0 ) {
F_31 ( V_30 , V_31 ,
L_180
L_181 ,
V_50 -> V_266 , V_103 ) ;
} else {
F_31 ( V_30 , V_31 ,
L_180
L_182 ,
V_50 -> V_266 , F_28 ( V_103 ) ) ;
}
break;
}
return FALSE ;
}
return TRUE ;
}
static T_5
F_175 ( T_15 * V_50 , T_38 * V_230 , int * V_267 )
{
unsigned int V_55 ;
T_33 * V_149 ;
T_3 V_268 = F_5 () ;
F_90 ( V_114 , V_116 , L_183 ) ;
if ( V_50 -> V_258 ) {
return F_176 ( & V_50 -> V_266 , V_267 ) ;
} else {
if ( V_50 -> V_257 ) {
for ( V_55 = 0 ; V_55 < V_109 . V_252 -> V_58 ; V_55 ++ ) {
V_149 = F_41 ( V_109 . V_252 , T_33 * , V_55 ) ;
if ( ! V_149 -> V_216 ) {
T_3 V_269 , V_270 ;
struct V_104 V_271 ;
if ( F_83 ( V_149 -> V_38 , & V_271 ) >= 0 ) {
V_269 = V_149 -> V_272 ;
V_270 = V_271 . V_112 + V_149 -> V_273 + V_149 -> V_274 ;
} else {
V_269 = V_275 ;
V_270 = V_275 ;
}
F_177 ( V_230 -> V_259 ,
V_55 ,
& V_230 -> V_264 ,
L_184 ,
V_276 ,
V_268 ,
V_269 ,
V_270 ,
V_267 ) ;
}
}
}
if ( fclose ( V_230 -> V_259 ) == V_277 ) {
if ( V_267 != NULL ) {
* V_267 = V_27 ;
}
return ( FALSE ) ;
} else {
return ( TRUE ) ;
}
}
}
static int
F_178 ( T_38 * V_230 ,
char * V_30 , int V_31 , T_33 * V_149 )
{
int V_278 ;
T_43 V_279 ;
T_39 V_280 [ V_247 ] ;
#ifndef F_6
int V_200 ;
#endif
V_279 = V_230 -> V_119 ;
if ( V_149 -> V_216 ) {
#ifdef F_150
F_90 ( V_114 , V_116 , L_185 ) ;
#endif
#ifndef F_6
V_200 = F_115 ( V_149 -> V_160 ) ;
if ( V_200 <= 0 ) {
if ( V_200 < 0 && V_27 != V_281 ) {
F_31 ( V_30 , V_31 ,
L_159 , F_28 ( V_27 ) ) ;
F_43 ( V_30 , V_42 ) ;
V_230 -> V_110 = FALSE ;
}
} else {
#endif
V_278 = F_149 ( V_230 , V_149 , V_280 , V_30 , V_31 ) ;
if ( V_278 < 0 ) {
V_230 -> V_110 = FALSE ;
}
#ifndef F_6
}
#endif
}
else
{
#ifdef F_179
#ifdef F_150
F_90 ( V_114 , V_116 , L_186 ) ;
#endif
if ( V_149 -> V_282 != - 1 ) {
V_200 = F_115 ( V_149 -> V_282 ) ;
if ( V_200 > 0 ) {
if ( V_250 ) {
V_278 = F_180 ( V_149 -> V_38 , 1 , F_156 , ( V_251 * ) V_149 ) ;
} else {
V_278 = F_180 ( V_149 -> V_38 , 1 , F_157 , ( V_251 * ) V_149 ) ;
}
if ( V_278 < 0 ) {
if ( V_278 == - 1 ) {
V_149 -> V_283 = TRUE ;
}
V_230 -> V_110 = FALSE ;
}
} else {
if ( V_200 < 0 && V_27 != V_281 ) {
F_31 ( V_30 , V_31 ,
L_159 , F_28 ( V_27 ) ) ;
F_43 ( V_30 , V_42 ) ;
V_230 -> V_110 = FALSE ;
}
}
}
else
#endif
{
#if 1
#ifdef F_150
F_90 ( V_114 , V_116 , L_187 ) ;
#endif
#ifdef F_6
if ( V_250 ) {
V_278 = F_180 ( V_149 -> V_38 , 1 , F_156 , ( V_251 * ) V_149 ) ;
} else {
V_278 = F_180 ( V_149 -> V_38 , 1 , F_157 , ( V_251 * ) V_149 ) ;
}
#else
if ( V_250 ) {
V_278 = F_180 ( V_149 -> V_38 , - 1 , F_156 , ( V_251 * ) V_149 ) ;
} else {
V_278 = F_180 ( V_149 -> V_38 , - 1 , F_157 , ( V_251 * ) V_149 ) ;
}
#endif
if ( V_278 < 0 ) {
if ( V_278 == - 1 ) {
V_149 -> V_283 = TRUE ;
}
V_230 -> V_110 = FALSE ;
}
#else
#ifdef F_150
F_90 ( V_114 , V_116 , L_188 ) ;
#endif
{
int V_284 ;
struct V_231 * V_285 ;
V_251 * V_286 ;
V_284 = 0 ;
while( V_230 -> V_110 &&
( V_284 = F_181 ( V_149 -> V_38 , & V_285 , & V_286 ) ) == 1 ) {
if ( V_250 ) {
F_156 ( ( V_251 * ) V_149 , V_285 , V_286 ) ;
} else {
F_157 ( ( V_251 * ) V_149 , V_285 , V_286 ) ;
}
}
if ( V_284 < 0 ) {
V_149 -> V_283 = TRUE ;
V_230 -> V_110 = FALSE ;
}
}
#endif
}
}
#ifdef F_150
F_90 ( V_114 , V_116 , L_189 , V_278 , F_182 ( V_278 , L_63 , L_190 ) ) ;
#endif
return V_230 -> V_119 - V_279 ;
}
static T_7 *
F_183 ( const char * V_29 )
{
T_9 * V_287 ;
T_7 * V_288 ;
V_287 = strchr ( V_29 , '{' ) ;
if ( V_287 == NULL )
return F_168 ( V_29 ) ;
V_288 = F_168 ( V_287 + 1 ) ;
V_287 = strchr ( V_288 -> V_21 , '}' ) ;
if ( V_287 == NULL )
return V_288 ;
V_288 = F_184 ( V_288 , V_287 - V_288 -> V_21 ) ;
return V_288 ;
}
static T_5
F_185 ( T_15 * V_50 , int * V_260 ,
char * V_30 , int V_31 )
{
char * V_289 ;
T_9 * V_290 ;
T_9 * V_291 ;
T_5 V_292 ;
F_90 ( V_114 , V_116 , L_191 ,
( V_50 -> V_266 ) ? V_50 -> V_266 : L_192 ) ;
if ( V_50 -> V_266 != NULL ) {
V_290 = F_55 ( V_50 -> V_266 ) ;
if ( V_50 -> V_293 == TRUE ) {
if ( V_50 -> V_258 ) {
F_31 ( V_30 , V_31 ,
L_193 ) ;
F_22 ( V_290 ) ;
return FALSE ;
}
if ( strcmp ( V_290 , L_141 ) == 0 ) {
* V_260 = 1 ;
#ifdef F_6
F_186 ( 1 , V_294 ) ;
#endif
}
}
else {
if ( V_50 -> V_258 ) {
* V_260 = F_187 ( V_290 ,
( V_50 -> V_295 ) ? V_50 -> V_296 : 0 ,
V_50 -> V_297 ) ;
if ( * V_260 != - 1 ) {
F_22 ( V_290 ) ;
V_290 = F_55 ( F_188 () ) ;
}
} else {
* V_260 = F_135 ( V_290 , V_298 | V_294 | V_299 | V_300 ,
( V_50 -> V_297 ) ? 0640 : 0600 ) ;
}
}
V_292 = FALSE ;
} else {
if ( V_301 . V_57 -> V_58 > 1 ) {
V_291 = F_56 ( L_194 , V_301 . V_57 -> V_58 ) ;
} else {
T_9 * V_302 ;
V_302 = F_189 ( F_41 ( V_301 . V_57 , T_16 , 0 ) . V_303 ) ;
#ifdef F_6
if ( strncmp ( L_195 , V_302 , 5 ) == 0 )
{
T_7 * V_29 ;
V_29 = F_183 ( V_302 ) ;
F_22 ( V_302 ) ;
V_302 = F_55 ( V_29 -> V_21 ) ;
F_173 ( V_29 , TRUE ) ;
}
#endif
if ( V_50 -> V_257 ) {
V_291 = F_190 ( L_196 , V_302 , NULL ) ;
} else{
V_291 = F_190 ( L_197 , V_302 , NULL ) ;
}
F_22 ( V_302 ) ;
}
* V_260 = F_191 ( & V_289 , V_291 ) ;
F_22 ( V_291 ) ;
V_290 = F_55 ( V_289 ) ;
V_292 = TRUE ;
}
if ( * V_260 == - 1 ) {
if ( V_292 ) {
F_31 ( V_30 , V_31 ,
L_198
L_199 , V_290 , F_28 ( V_27 ) ) ;
} else {
if ( V_50 -> V_258 ) {
F_192 () ;
}
F_31 ( V_30 , V_31 ,
L_200
L_199 , V_290 ,
F_28 ( V_27 ) ) ;
}
F_22 ( V_290 ) ;
return FALSE ;
}
if ( V_50 -> V_266 != NULL ) {
F_22 ( V_50 -> V_266 ) ;
}
V_50 -> V_266 = V_290 ;
return TRUE ;
}
static T_5
F_193 ( T_15 * V_50 ,
T_44 * V_304 ,
T_44 * V_305 ,
T_44 * V_306 )
{
T_18 V_55 ;
T_33 * V_149 ;
T_16 V_51 ;
T_5 V_256 ;
if ( V_50 -> V_258 ) {
if ( V_304 != NULL &&
F_194 ( V_304 , ++ V_109 . V_307 ) ) {
V_109 . V_110 = FALSE ;
return FALSE ;
}
if ( F_195 ( & V_109 . V_259 , & V_50 -> V_266 ,
& V_109 . V_260 , & V_109 . V_103 ) ) {
V_109 . V_264 = 0 ;
if ( V_50 -> V_257 ) {
char V_261 [ 100 ] ;
T_7 * V_262 ;
V_262 = F_168 ( L_63 ) ;
F_169 ( V_262 ) ;
F_31 ( V_261 , sizeof( V_261 ) , L_3 V_15 L_110 , V_16 ) ;
V_256 = F_170 ( V_109 . V_259 ,
NULL ,
NULL ,
V_262 -> V_21 ,
V_261 ,
- 1 ,
& ( V_109 . V_264 ) ,
& V_109 . V_103 ) ;
for ( V_55 = 0 ; V_256 && ( V_55 < V_50 -> V_57 -> V_58 ) ; V_55 ++ ) {
V_51 = F_41 ( V_50 -> V_57 , T_16 , V_55 ) ;
V_149 = F_41 ( V_109 . V_252 , T_33 * , V_55 ) ;
V_256 = F_172 ( V_109 . V_259 ,
NULL ,
V_51 . V_40 ,
V_51 . V_265 ,
V_51 . V_45 ,
V_262 -> V_21 ,
V_149 -> V_39 ,
V_149 -> V_226 ,
& ( V_109 . V_264 ) ,
0 ,
V_149 -> V_221 ? 9 : 6 ,
& V_109 . V_103 ) ;
}
F_173 ( V_262 , TRUE ) ;
} else {
V_149 = F_41 ( V_109 . V_252 , T_33 * , 0 ) ;
V_256 = F_174 ( V_109 . V_259 , V_149 -> V_39 , V_149 -> V_226 ,
V_149 -> V_221 , & V_109 . V_264 , & V_109 . V_103 ) ;
}
if ( ! V_256 ) {
fclose ( V_109 . V_259 ) ;
V_109 . V_259 = NULL ;
V_109 . V_110 = FALSE ;
return FALSE ;
}
if ( V_305 )
F_196 ( V_305 ) ;
if ( V_306 )
F_196 ( V_306 ) ;
fflush ( V_109 . V_259 ) ;
if ( ! V_120 )
F_197 ( V_109 . V_308 ) ;
V_109 . V_308 = 0 ;
F_198 ( V_50 -> V_266 ) ;
} else {
V_109 . V_110 = FALSE ;
return FALSE ;
}
} else {
V_109 . V_110 = FALSE ;
return FALSE ;
}
return TRUE ;
}
static void *
F_199 ( void * V_148 )
{
T_33 * V_149 ;
char V_30 [ V_52 + 1 ] ;
V_149 = ( T_33 * ) V_148 ;
F_90 ( V_114 , V_115 , L_201 ,
V_149 -> V_309 ) ;
while ( V_109 . V_110 ) {
F_178 ( & V_109 , V_30 , sizeof( V_30 ) , V_149 ) ;
}
F_90 ( V_114 , V_115 , L_202 ,
V_149 -> V_309 ) ;
F_200 ( NULL ) ;
return ( NULL ) ;
}
static void
F_91 ( void )
{
#ifdef F_201
T_18 V_55 ;
T_33 * V_149 ;
for ( V_55 = 0 ; V_55 < V_109 . V_252 -> V_58 ; V_55 ++ ) {
V_149 = F_41 ( V_109 . V_252 , T_33 * , V_55 ) ;
if ( V_149 -> V_38 != NULL )
F_202 ( V_149 -> V_38 ) ;
}
#endif
V_109 . V_110 = FALSE ;
}
static void
F_203 ( char * V_30 , int V_310 , const char * V_311 ,
int V_103 , T_5 V_312 )
{
switch ( V_103 ) {
case V_313 :
F_31 ( V_30 , V_310 ,
L_203
L_204
L_205
L_206 ,
V_311 ) ;
break;
#ifdef F_204
case F_204 :
F_31 ( V_30 , V_310 ,
L_203
L_204
L_207
L_208
L_209 ,
V_311 ) ;
break;
#endif
default:
if ( V_312 ) {
F_31 ( V_30 , V_310 ,
L_210
L_211 ,
V_311 , F_28 ( V_103 ) ) ;
} else {
F_31 ( V_30 , V_310 ,
L_212
L_204
L_213 ,
V_311 , F_28 ( V_103 ) ) ;
}
break;
}
}
static void
F_157 ( V_251 * V_314 , const struct V_231 * V_232 ,
const V_251 * V_315 )
{
T_33 * V_149 = ( T_33 * ) ( void * ) V_314 ;
int V_103 ;
T_18 V_316 = V_149 -> V_221 ? 1000000000 : 1000000 ;
if ( ! V_109 . V_110 ) {
V_149 -> V_274 ++ ;
return;
}
if ( V_109 . V_259 ) {
T_5 V_256 ;
if ( V_301 . V_257 ) {
V_256 = F_205 ( V_109 . V_259 ,
NULL ,
V_232 -> V_248 . V_11 , ( V_317 ) V_232 -> V_248 . V_12 ,
V_232 -> V_249 , V_232 -> V_58 ,
V_149 -> V_309 ,
V_316 ,
V_315 , 0 ,
& V_109 . V_264 , & V_103 ) ;
} else {
V_256 = F_206 ( V_109 . V_259 ,
V_232 -> V_248 . V_11 , ( V_317 ) V_232 -> V_248 . V_12 ,
V_232 -> V_249 , V_232 -> V_58 ,
V_315 ,
& V_109 . V_264 , & V_103 ) ;
}
if ( ! V_256 ) {
V_109 . V_110 = FALSE ;
V_109 . V_103 = V_103 ;
V_149 -> V_273 ++ ;
} else {
#if F_12 ( F_97 ) || F_12 ( V_318 )
F_90 ( V_114 , V_115 ,
L_214 ,
V_232 -> V_249 , V_149 -> V_309 ) ;
#endif
V_109 . V_119 ++ ;
V_149 -> V_272 ++ ;
if ( ( V_109 . V_319 > 0 ) && ( V_109 . V_119 >= V_109 . V_319 ) ) {
V_109 . V_110 = FALSE ;
}
}
}
}
static void
F_156 ( V_251 * V_314 , const struct V_231 * V_232 ,
const V_251 * V_315 )
{
T_33 * V_149 = ( T_33 * ) ( void * ) V_314 ;
T_45 * V_320 ;
T_5 V_321 ;
if ( ! V_109 . V_110 ) {
V_149 -> V_274 ++ ;
return;
}
V_320 = ( T_45 * ) F_53 ( sizeof( T_45 ) ) ;
if ( V_320 == NULL ) {
V_149 -> V_273 ++ ;
return;
}
V_320 -> V_149 = V_149 ;
V_320 -> V_232 = * V_232 ;
V_320 -> V_315 = ( V_251 * ) F_53 ( V_232 -> V_249 ) ;
if ( V_320 -> V_315 == NULL ) {
V_149 -> V_273 ++ ;
F_22 ( V_320 ) ;
return;
}
memcpy ( V_320 -> V_315 , V_315 , V_232 -> V_249 ) ;
F_207 ( V_322 ) ;
if ( ( ( V_323 == 0 ) || ( V_324 < V_323 ) ) &&
( ( V_325 == 0 ) || ( V_326 < V_325 ) ) ) {
V_321 = FALSE ;
F_208 ( V_322 , V_320 ) ;
V_324 += V_232 -> V_249 ;
V_326 += 1 ;
} else {
V_321 = TRUE ;
}
F_209 ( V_322 ) ;
if ( V_321 ) {
V_149 -> V_273 ++ ;
F_22 ( V_320 -> V_315 ) ;
F_22 ( V_320 ) ;
F_90 ( V_114 , V_115 ,
L_215 ,
V_232 -> V_249 , V_149 -> V_309 ) ;
} else {
V_149 -> V_272 ++ ;
F_90 ( V_114 , V_115 ,
L_216 ,
V_232 -> V_249 , V_149 -> V_309 ) ;
}
F_90 ( V_114 , V_115 ,
L_217 V_327 L_218 V_327 L_219 ,
V_324 , V_326 ) ;
}
static int
F_210 ( const char * V_29 , const char * V_328 )
{
int V_329 = 0 , type , V_330 ;
T_9 * * V_331 = NULL ;
V_331 = F_211 ( V_328 , L_109 , 2 ) ;
if ( V_331 [ 0 ] )
V_329 = atoi ( V_331 [ 0 ] ) ;
if ( V_331 [ 1 ] ) {
type = F_212 ( V_331 [ 1 ] ) ;
if ( type == - 1 ) {
V_330 = V_332 ;
goto V_333;
}
}
else
type = - 1 ;
V_330 = F_213 () ;
if ( V_330 ) {
F_19 ( L_220 , abs ( V_330 ) , F_28 ( abs ( V_330 ) ) ) ;
V_330 = 2 ;
goto V_333;
}
V_330 = F_214 ( V_29 , V_329 , type ) ;
if ( V_330 ) {
F_19 ( L_221 , abs ( V_330 ) , F_28 ( abs ( V_330 ) ) ) ;
V_330 = 2 ;
goto V_333;
}
if ( V_24 )
F_49 ( 2 , V_61 , NULL ) ;
V_330 = 0 ;
V_333:
F_215 ( V_331 ) ;
return V_330 ;
}
int
main ( int V_334 , char * V_335 [] )
{
T_7 * V_19 ;
T_7 * V_20 ;
int V_328 ;
struct V_336 V_337 [] = {
{ ( char * ) L_222 , V_338 , NULL , V_339 } ,
{ 0 , 0 , 0 , 0 }
} ;
T_5 V_340 = FALSE ;
#ifdef F_6
T_46 V_341 ;
#else
struct V_342 V_343 , V_344 ;
#endif
T_5 V_345 = TRUE ;
T_5 V_346 ;
struct V_104 V_271 ;
T_47 V_347 ;
T_5 V_348 = FALSE ;
T_5 V_349 = FALSE ;
#ifdef F_13
T_5 V_350 = FALSE ;
#endif
T_5 V_351 = FALSE ;
T_9 * V_352 = NULL ;
T_5 V_99 = FALSE ;
T_5 V_353 = FALSE ;
int V_70 , V_354 = 0 ;
T_43 V_55 ;
T_18 V_56 ;
#if F_12 ( V_355 ) && F_12 ( V_356 )
struct V_357 V_358 ;
#endif
T_7 * V_21 ;
V_19 = F_168 ( L_223 ) ;
F_216 ( V_19 , NULL , NULL ) ;
V_20 = F_168 ( L_224 ) ;
F_217 ( V_20 , NULL ) ;
F_218 ( L_3 V_15 L_4
L_8
L_110
L_8
L_110 ,
V_16 , V_19 -> V_21 , V_20 -> V_21 ) ;
#ifdef F_6
F_219 ( V_334 , V_335 ) ;
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
#ifdef V_318
if ( ( V_359 = F_230 ( L_225 , L_226 ) ) == NULL ) {
fprintf ( V_17 , L_227 ) ;
exit ( 1 ) ;
}
#endif
#if F_12 ( V_355 ) && F_12 ( V_356 )
if ( F_231 ( & V_358 ) == 0 ) {
if ( strcmp ( V_358 . V_360 , L_228 ) == 0 ||
strcmp ( V_358 . V_360 , L_229 ) == 0 ||
strcmp ( V_358 . V_360 , L_230 ) == 0 )
V_361 = TRUE ;
}
#endif
for ( V_55 = 1 ; V_55 < V_334 ; V_55 ++ ) {
if ( strcmp ( L_231 , V_335 [ V_55 ] ) == 0 ) {
V_24 = TRUE ;
V_99 = TRUE ;
#ifdef F_6
F_186 ( 2 , V_294 ) ;
#endif
}
}
V_347 =
( T_47 ) (
V_362 |
V_363 |
V_364 |
V_365 |
V_115 |
V_116 |
V_366 |
V_367 ) ;
F_232 ( NULL ,
V_347 ,
V_368 , NULL ) ;
F_232 ( V_369 ,
V_347 ,
V_368 , NULL ) ;
F_232 ( V_370 ,
V_347 ,
V_368 , NULL ) ;
F_232 ( V_114 ,
V_347 ,
V_368 , NULL ) ;
V_109 . V_252 = F_233 ( FALSE , FALSE , sizeof( T_33 * ) ) ;
#if ! F_145 ( 2 , 31 , 0 )
F_234 ( NULL ) ;
#endif
#ifdef F_6
F_235 () ;
F_236 ( F_237 ( 1 , 1 ) , & V_341 ) ;
F_238 ( F_89 , TRUE ) ;
#else
memset ( & V_343 , 0 , sizeof( V_343 ) ) ;
V_343 . V_371 = F_89 ;
V_343 . V_372 = 0 ;
F_239 ( & V_343 . V_373 ) ;
V_342 ( V_374 , & V_343 , NULL ) ;
V_342 ( V_375 , & V_343 , NULL ) ;
V_342 ( V_376 , & V_343 , NULL ) ;
V_342 ( V_377 , NULL , & V_344 ) ;
if ( V_344 . V_371 == V_378 )
V_342 ( V_377 , & V_343 , NULL ) ;
#ifdef F_240
V_343 . V_371 = F_94 ;
V_343 . V_372 = V_379 ;
F_239 ( & V_343 . V_373 ) ;
V_342 ( F_240 , & V_343 , NULL ) ;
#endif
#endif
#ifdef F_16
F_1 () ;
#endif
F_241 () ;
#ifdef F_47
F_99 () ;
#endif
F_242 ( & V_301 ) ;
V_301 . V_380 = TRUE ;
V_301 . V_295 = TRUE ;
V_301 . V_24 = V_24 ;
while ( ( V_328 = F_243 ( V_334 , V_335 , F_229 , V_337 , NULL ) ) != - 1 ) {
switch ( V_328 ) {
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
case V_339 :
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
V_70 = F_244 ( & V_301 , V_328 , V_381 , & V_345 ) ;
if ( V_70 != 0 ) {
F_95 ( V_70 ) ;
}
break;
case 'Z' :
V_24 = TRUE ;
#ifdef F_6
F_186 ( 2 , V_294 ) ;
if ( strcmp ( V_381 , V_382 ) != 0 ) {
V_383 = F_56 ( V_384 , V_381 ) ;
V_385 = F_141 ( F_142 ( V_383 ) ,
V_213 , 0 , NULL , V_214 , 0 , NULL ) ;
if ( V_385 == V_202 ) {
F_90 ( V_114 , V_115 ,
L_232 ,
V_383 ) ;
F_95 ( 1 ) ;
}
}
#endif
break;
case 'q' :
V_120 = TRUE ;
break;
case 't' :
V_250 = TRUE ;
break;
case 'D' :
V_348 = TRUE ;
V_354 ++ ;
break;
case 'L' :
V_349 = TRUE ;
V_354 ++ ;
break;
#ifdef F_13
case 'd' :
V_350 = TRUE ;
V_354 ++ ;
break;
#endif
case 'S' :
V_353 = TRUE ;
V_354 ++ ;
break;
case 'k' :
V_351 = TRUE ;
V_352 = V_381 ;
V_354 ++ ;
break;
case 'M' :
V_99 = TRUE ;
break;
case 'C' :
V_323 = F_245 ( V_381 , L_233 ) ;
break;
case 'N' :
V_325 = F_245 ( V_381 , L_234 ) ;
break;
default:
F_19 ( L_235 , V_335 [ V_386 - 1 ] ) ;
case '?' :
V_340 = TRUE ;
break;
}
}
if ( ! V_340 ) {
V_334 -= V_386 ;
V_335 += V_386 ;
if ( V_334 >= 1 ) {
V_334 -- ;
V_335 ++ ;
}
if ( V_334 != 0 ) {
F_19 ( L_236 , V_335 [ 0 ] ) ;
V_340 = TRUE ;
}
}
if ( ( V_323 > 0 ) || ( V_325 > 0 ) ) {
V_250 = TRUE ;
}
if ( ( V_323 == 0 ) && ( V_325 == 0 ) ) {
V_323 = 1000 * 1000 ;
V_325 = 1000 ;
}
if ( V_340 ) {
F_10 ( FALSE ) ;
F_95 ( 1 ) ;
}
if ( V_354 > 1 ) {
F_19 ( L_237 ) ;
F_95 ( 1 ) ;
} else if ( V_354 == 1 ) {
if ( V_301 . V_258 ) {
F_19 ( L_238 ) ;
F_95 ( 1 ) ;
}
} else {
if ( V_301 . V_57 -> V_58 > 1 ) {
V_250 = TRUE ;
V_301 . V_257 = TRUE ;
}
if ( V_301 . V_263 &&
( ! V_301 . V_257 || V_301 . V_258 ) ) {
F_19 ( L_239 ) ;
F_95 ( 1 ) ;
}
if ( V_301 . V_258 ) {
if ( V_301 . V_266 == NULL ) {
F_19 ( L_240 ) ;
V_301 . V_258 = FALSE ;
}
if ( ! V_301 . V_387 && ! V_301 . V_388 ) {
F_19 ( L_241 ) ;
#if 0
global_capture_opts.multi_files_on = FALSE;
#endif
}
}
}
if ( V_348 ) {
T_23 * V_78 ;
int V_103 ;
T_9 * V_68 ;
V_78 = F_246 ( & V_103 , & V_68 , NULL ) ;
if ( V_78 == NULL ) {
switch ( V_103 ) {
case V_106 :
case V_107 :
F_19 ( L_110 , V_68 ) ;
F_22 ( V_68 ) ;
F_95 ( 2 ) ;
break;
case V_108 :
if ( ! V_99 ) {
F_19 ( L_120 ) ;
F_95 ( 2 ) ;
}
break;
}
}
if ( V_99 )
F_74 ( V_78 ) ;
else
F_247 ( V_78 ) ;
F_88 ( V_78 ) ;
F_95 ( 0 ) ;
}
if ( V_353 ) {
V_70 = F_81 ( V_99 ) ;
F_95 ( V_70 ) ;
}
if ( V_351 ) {
T_16 V_51 ;
if ( V_301 . V_57 -> V_58 != 1 ) {
F_19 ( L_242 ) ;
F_95 ( 2 ) ;
}
V_51 = F_41 ( V_301 . V_57 , T_16 , 0 ) ;
V_70 = F_210 ( V_51 . V_40 , V_352 ) ;
F_95 ( V_70 ) ;
}
V_70 = F_248 ( & V_301 , NULL ) ;
if ( V_70 != 0 ) {
F_95 ( V_70 ) ;
}
if ( V_24 ) {
for ( V_56 = 0 ; V_56 < V_301 . V_57 -> V_58 ; V_56 ++ ) {
T_16 V_51 ;
V_51 = F_41 ( V_301 . V_57 , T_16 , V_56 ) ;
F_90 ( V_114 , V_116 , L_243 ,
V_51 . V_40 ) ;
}
} else {
V_21 = F_168 ( L_63 ) ;
#ifdef F_6
if ( V_301 . V_57 -> V_58 < 2 )
#else
if ( V_301 . V_57 -> V_58 < 4 )
#endif
{
for ( V_56 = 0 ; V_56 < V_301 . V_57 -> V_58 ; V_56 ++ ) {
T_16 V_51 ;
V_51 = F_41 ( V_301 . V_57 , T_16 , V_56 ) ;
if ( V_56 > 0 ) {
if ( V_301 . V_57 -> V_58 > 2 ) {
F_249 ( V_21 , L_109 ) ;
}
F_249 ( V_21 , L_244 ) ;
if ( V_56 == V_301 . V_57 -> V_58 - 1 ) {
F_249 ( V_21 , L_245 ) ;
}
}
F_249 ( V_21 , L_246 , V_51 . V_303 ) ;
}
} else {
F_249 ( V_21 , L_247 , V_301 . V_57 -> V_58 ) ;
}
fprintf ( V_17 , L_248 , V_21 -> V_21 ) ;
F_173 ( V_21 , TRUE ) ;
}
if ( V_349 ) {
T_21 * V_26 ;
T_9 * V_68 ;
T_18 V_389 ;
for ( V_389 = 0 ; V_389 < V_301 . V_57 -> V_58 ; V_389 ++ ) {
T_16 V_51 ;
V_51 = F_41 ( V_301 . V_57 , T_16 , V_389 ) ;
V_26 = F_58 ( V_51 . V_40 ,
V_51 . T_22 , & V_68 ) ;
if ( V_26 == NULL ) {
F_19 ( L_249
L_250
L_251 , V_51 . V_40 , V_68 ) ;
F_22 ( V_68 ) ;
F_95 ( 2 ) ;
}
if ( V_26 -> V_77 == NULL ) {
F_19 ( L_252 , V_51 . V_40 ) ;
F_95 ( 2 ) ;
}
if ( V_99 )
F_80 ( V_26 ) ;
else
F_250 ( V_26 , V_51 . V_40 ,
V_51 . T_22 ) ;
F_251 ( V_26 ) ;
}
F_95 ( 0 ) ;
}
F_252 ( & V_301 , V_74 ) ;
#ifdef F_13
if ( V_350 ) {
F_40 ( & V_301 ) ;
F_95 ( 0 ) ;
}
#endif
F_253 ( & V_301 ) ;
fflush ( V_17 ) ;
if ( F_254 ( & V_301 , & V_346 , & V_271 ) == TRUE ) {
F_95 ( 0 ) ;
} else {
F_95 ( 1 ) ;
}
return 0 ;
}
static void
V_368 ( const char * V_390 , T_47 V_391 ,
const char * V_392 , T_41 T_48 V_2 )
{
T_49 V_393 ;
struct V_394 * V_395 ;
const char * V_396 ;
T_9 * V_25 ;
if ( ! ( V_391 & V_397 & ~ ( V_116 | V_115 ) ) ) {
#if ! F_12 ( F_97 ) && ! F_12 ( V_318 )
return;
#endif
}
time ( & V_393 ) ;
V_395 = localtime ( & V_393 ) ;
switch( V_391 & V_397 ) {
case V_362 :
V_396 = L_253 ;
break;
case V_363 :
V_396 = L_254 ;
break;
case V_364 :
V_396 = L_255 ;
break;
case V_365 :
V_396 = L_256 ;
break;
case V_115 :
V_396 = L_257 ;
break;
case V_116 :
V_396 = L_258 ;
break;
default:
fprintf ( V_17 , L_259 , V_391 ) ;
V_396 = NULL ;
F_255 () ;
}
if ( V_391 & V_365 ) {
V_25 = F_56 ( L_4 , V_392 ) ;
} else {
V_25 = F_56 ( L_260 ,
V_395 -> V_398 , V_395 -> V_399 , V_395 -> V_400 ,
V_390 != NULL ? V_390 : L_63 ,
V_396 , V_392 ) ;
}
#if F_12 ( F_97 ) || F_12 ( V_318 )
if ( ! ( V_391 & V_397 & ~ ( V_116 | V_115 ) ) ) {
#ifdef F_97
fprintf ( V_17 , L_110 , V_25 ) ;
fflush ( V_17 ) ;
#endif
#ifdef V_318
fprintf ( V_359 , L_110 , V_25 ) ;
fflush ( V_359 ) ;
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
F_197 ( unsigned int V_119 )
{
char V_401 [ V_402 + 1 + 1 ] ;
static unsigned int V_403 = 0 ;
if ( V_24 ) {
F_31 ( V_401 , sizeof( V_401 ) , L_261 , V_119 ) ;
F_90 ( V_114 , V_116 , L_262 , V_401 ) ;
F_49 ( 2 , V_404 , V_401 ) ;
} else {
V_403 += V_119 ;
fprintf ( V_17 , L_263 , V_403 ) ;
fflush ( V_17 ) ;
}
}
static void
F_198 ( const char * V_405 )
{
if ( V_24 ) {
F_90 ( V_114 , V_116 , L_264 , V_405 ) ;
F_49 ( 2 , V_406 , V_405 ) ;
} else {
#ifdef F_240
V_123 = TRUE ;
#endif
fprintf ( V_17 , L_265 , V_405 ) ;
fflush ( V_17 ) ;
#ifdef F_240
V_123 = FALSE ;
if ( V_121 )
F_93 () ;
#endif
}
}
static void
F_45 ( T_15 * V_50 , T_18 V_55 , const char * V_30 )
{
T_16 V_51 ;
char V_401 [ V_52 + 1 + 6 ] ;
if ( V_55 < V_50 -> V_57 -> V_58 ) {
if ( V_24 ) {
F_31 ( V_401 , sizeof( V_401 ) , L_266 , V_55 , V_30 ) ;
F_90 ( V_114 , V_116 , L_267 , V_30 ) ;
F_49 ( 2 , V_407 , V_401 ) ;
} else {
V_51 = F_41 ( V_50 -> V_57 , T_16 , V_55 ) ;
F_19 (
L_268
L_8
L_269
L_270 ,
V_51 . V_45 , V_51 . V_40 , V_30 ) ;
}
}
}
static void
F_43 ( const char * V_408 , const char * V_409 )
{
if ( V_24 ) {
F_90 ( V_114 , V_116 ,
L_271 , V_408 ) ;
F_90 ( V_114 , V_116 ,
L_272 , V_409 ) ;
F_21 ( 2 , V_408 , V_409 ) ;
} else {
F_19 ( L_110 , V_408 ) ;
if ( V_409 [ 0 ] != '\0' )
F_23 ( L_110 , V_409 ) ;
}
}
static void
F_256 ( V_8 V_272 , V_8 V_410 , V_8 V_411 , V_8 V_274 , V_8 V_412 , T_9 * V_40 )
{
char V_401 [ V_402 + 1 + 1 ] ;
V_8 V_413 = V_410 + V_411 + V_274 ;
F_31 ( V_401 , sizeof( V_401 ) , L_261 , V_413 ) ;
if ( V_24 ) {
F_90 ( V_114 , V_116 ,
L_273 ,
V_40 , V_272 , V_413 , V_410 , V_411 , V_274 , V_412 ) ;
F_49 ( 2 , V_414 , V_401 ) ;
} else {
fprintf ( V_17 ,
L_274 ,
V_40 , V_272 , V_413 , V_410 , V_411 , V_274 , V_412 ,
V_272 ? 100.0 * V_272 / ( V_272 + V_413 ) : 0.0 ) ;
fflush ( V_17 ) ;
}
}
static T_5
F_84 ( void )
{
T_29 V_415 = 0 ;
T_5 V_238 ;
if ( ! V_24 ) {
return TRUE ;
}
if ( ! V_383 || ! V_385 ) {
F_90 ( V_114 , V_115 ,
L_275 ) ;
return FALSE ;
}
V_238 = F_257 ( V_385 , NULL , 0 , NULL , & V_415 , NULL ) ;
if ( ! V_238 || V_415 > 0 ) {
F_90 ( V_114 , V_115 ,
L_276 , V_383 ) ;
F_90 ( V_114 , V_116 ,
L_277 , V_383 ,
V_385 , V_238 , V_415 ) ;
return FALSE ;
} else {
return TRUE ;
}
}
