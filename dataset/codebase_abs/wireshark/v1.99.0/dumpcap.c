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
F_10 ( T_5 * V_13 )
{
fprintf ( V_13 , L_3 ) ;
fprintf ( V_13 , L_4 ) ;
fprintf ( V_13 , L_5 ) ;
fprintf ( V_13 , L_6
L_7
L_8
L_9 ) ;
fprintf ( V_13 , L_10 ) ;
fprintf ( V_13 , L_11 ) ;
fprintf ( V_13 , L_12 ) ;
#ifdef F_11
fprintf ( V_13 , L_13 ) ;
#endif
#if F_12 ( F_6 ) || F_12 ( F_11 )
fprintf ( V_13 , L_14 , V_14 ) ;
#endif
fprintf ( V_13 , L_15 ) ;
fprintf ( V_13 , L_16 ) ;
fprintf ( V_13 , L_17 ) ;
#ifdef F_13
fprintf ( V_13 , L_18 ) ;
#endif
fprintf ( V_13 , L_19 ) ;
fprintf ( V_13 , L_20 ) ;
fprintf ( V_13 , L_21 ) ;
fprintf ( V_13 , L_4 ) ;
#ifdef F_14
fprintf ( V_13 , L_22 ) ;
fprintf ( V_13 , L_23 ) ;
fprintf ( V_13 , L_24 ) ;
fprintf ( V_13 , L_25 ) ;
#ifdef F_15
fprintf ( V_13 , L_26 ) ;
fprintf ( V_13 , L_27 ) ;
fprintf ( V_13 , L_28 ) ;
#endif
#endif
fprintf ( V_13 , L_29 ) ;
fprintf ( V_13 , L_30 ) ;
fprintf ( V_13 , L_31 ) ;
fprintf ( V_13 , L_32 ) ;
fprintf ( V_13 , L_33 ) ;
fprintf ( V_13 , L_34 ) ;
fprintf ( V_13 , L_35 ) ;
fprintf ( V_13 , L_36 ) ;
fprintf ( V_13 , L_37 ) ;
fprintf ( V_13 , L_38 ) ;
fprintf ( V_13 , L_39 ) ;
fprintf ( V_13 , L_40 ) ;
fprintf ( V_13 , L_41 ) ;
fprintf ( V_13 , L_42 ) ;
fprintf ( V_13 , L_43 ) ;
fprintf ( V_13 , L_44 ) ;
fprintf ( V_13 , L_4 ) ;
fprintf ( V_13 , L_45 ) ;
fprintf ( V_13 , L_46 ) ;
fprintf ( V_13 , L_47 ) ;
fprintf ( V_13 , L_48 ) ;
fprintf ( V_13 , L_49 ) ;
fprintf ( V_13 , L_50 ) ;
fprintf ( V_13 , L_51 ) ;
fprintf ( V_13 , L_52 ) ;
fprintf ( V_13 , L_4 ) ;
#ifdef F_16
fprintf ( V_13 , L_53 ) ;
fprintf ( V_13 , L_54 ) ;
fprintf ( V_13 , L_55 ) ;
fprintf ( V_13 , L_4 ) ;
#endif
fprintf ( V_13 , L_56 ) ;
fprintf ( V_13 , L_57 ) ;
fprintf ( V_13 , L_4 ) ;
fprintf ( V_13 , L_58 ) ;
}
static void
F_17 ( T_6 * V_15 , T_6 * V_16 )
{
printf ( L_59
L_4
L_60
L_4
L_60
L_4
L_60 ,
F_18 () , F_19 () , V_15 -> V_17 , V_16 -> V_17 ) ;
}
static void
F_20 ( const char * V_18 , T_7 V_19 )
{
if ( V_20 ) {
T_8 * V_21 ;
V_21 = F_21 ( V_18 , V_19 ) ;
F_22 ( 2 , V_21 , L_61 ) ;
F_23 ( V_21 ) ;
} else {
fprintf ( V_22 , L_62 ) ;
vfprintf ( V_22 , V_18 , V_19 ) ;
fprintf ( V_22 , L_4 ) ;
}
}
static void
F_24 ( const char * V_18 , T_7 V_19 )
{
if ( V_20 ) {
T_8 * V_21 ;
V_21 = F_21 ( V_18 , V_19 ) ;
F_22 ( 2 , V_21 , L_61 ) ;
F_23 ( V_21 ) ;
} else {
vfprintf ( V_22 , V_18 , V_19 ) ;
fprintf ( V_22 , L_4 ) ;
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
F_25 ( const char * T_9 V_2 ) {
#endif
}
static void
F_26 ( void )
{
T_10 V_23 = F_27 () ;
F_25 ( L_63 ) ;
if ( F_28 ( V_23 ) ) {
F_29 ( L_64 , F_30 ( V_24 ) ) ;
}
F_25 ( L_65 ) ;
F_31 ( V_23 ) ;
}
static void
F_32 ( const char * V_25 ,
const char * V_26 ,
char * V_27 , T_11 V_28 ,
char * V_29 ,
T_11 V_30 )
{
#ifndef F_6
const char * V_31 ;
static const char V_32 [] = L_66 ;
#endif
F_33 ( V_27 , ( V_33 ) V_28 ,
L_67 ,
V_26 , V_25 ) ;
#ifdef F_6
if ( ! V_34 ) {
F_33 ( V_29 , ( V_33 ) V_30 ,
L_4
L_68
L_4
L_69
L_4
L_70
L_4
L_71
L_4
L_70
L_4
L_72
L_4
L_73
L_74 ) ;
} else {
F_33 ( V_29 , ( V_33 ) V_30 ,
L_4
L_75
L_4
L_4
L_76
L_4
L_77
L_78 ,
V_26 ) ;
}
#else
if ( strncmp ( V_25 , V_32 , sizeof V_32 - 1 ) == 0 )
V_31 =
L_79
L_80
L_81
L_82
L_4
L_83
L_84
L_85
L_86
L_87 ;
else
V_31 = L_61 ;
F_33 ( V_29 , ( V_33 ) V_30 ,
L_88
L_89 , V_31 ) ;
#endif
}
static T_12
F_34 ( T_13 * V_35 , int V_36 , char * V_37 ,
char * V_27 , T_11 V_28 ,
char * V_29 , T_11 V_30 )
{
char * V_38 ;
if ( V_36 == - 1 )
return TRUE ;
#ifdef F_35
if ( F_36 ( V_35 , V_36 ) == 0 )
return TRUE ;
V_38 = F_37 ( V_35 ) ;
#else
if ( F_38 ( V_35 , V_37 ) == V_36 )
return TRUE ;
V_38 =
L_90 ;
#endif
F_33 ( V_27 , ( V_33 ) V_28 , L_91 ,
V_37 , V_38 ) ;
if ( strstr ( V_38 , L_92 ) == NULL )
F_33 ( V_29 , ( V_33 ) V_30 , V_39 ) ;
else
V_29 [ 0 ] = '\0' ;
return FALSE ;
}
static T_12
F_39 ( const char * V_26 , T_13 * V_35 ,
struct V_40 * V_41 , const char * V_42 )
{
T_14 V_43 , V_44 ;
T_8 V_45 [ V_46 ] ;
if ( F_40 ( V_26 , & V_43 , & V_44 , V_45 ) < 0 ) {
V_44 = 0 ;
}
if ( F_41 ( V_35 , V_41 , ( char * ) V_42 , 1 , V_44 ) < 0 )
return FALSE ;
return TRUE ;
}
static T_12
F_42 ( T_15 * V_47 )
{
T_16 V_48 ;
T_13 * V_35 ;
T_8 V_25 [ V_46 ] ;
char V_27 [ V_49 + 1 ] ;
char V_29 [ V_49 + 1 ] ;
struct V_40 V_41 ;
struct V_50 * V_51 ;
T_17 V_52 ;
T_18 V_53 ;
for ( V_53 = 0 ; V_53 < V_47 -> V_54 -> V_55 ; V_53 ++ ) {
V_48 = F_43 ( V_47 -> V_54 , T_16 , V_53 ) ;
V_35 = F_44 ( V_47 , & V_48 , & V_25 ) ;
if ( V_35 == NULL ) {
F_32 ( V_25 ,
V_48 . V_37 ,
V_27 , sizeof V_27 ,
V_29 ,
sizeof V_29 ) ;
F_45 ( V_27 , V_29 ) ;
return FALSE ;
}
if ( ! F_34 ( V_35 , V_48 . V_36 , V_48 . V_37 ,
V_27 , sizeof V_27 ,
V_29 , sizeof V_29 ) ) {
F_46 ( V_35 ) ;
F_45 ( V_27 , V_29 ) ;
return FALSE ;
}
if ( ! F_39 ( V_48 . V_37 , V_35 , & V_41 ,
V_48 . V_42 ) ) {
F_46 ( V_35 ) ;
F_47 ( V_47 , V_53 , V_27 ) ;
return FALSE ;
}
F_46 ( V_35 ) ;
V_51 = V_41 . V_56 ;
for ( V_52 = 0 ; V_52 < V_41 . V_57 ; V_51 ++ , V_52 ++ )
printf ( L_93 , F_48 ( V_51 , V_52 ) ) ;
}
#ifndef F_49
F_50 () ;
#else
F_26 () ;
#endif
if ( V_20 ) {
F_51 ( 2 , V_58 , NULL ) ;
}
return TRUE ;
}
static int
F_38 ( T_13 * V_59 , const char * T_19
#ifndef F_52
V_2
#endif
)
{
int V_36 ;
#ifdef F_52
const char * V_60 ;
#endif
V_36 = F_53 ( V_59 ) ;
#ifdef F_52
V_60 = strchr ( T_19 , '/' ) ;
if ( V_60 == NULL )
V_60 = T_19 ;
if ( strncmp ( V_60 , L_94 , 2 ) == 0 ) {
if ( V_36 == 6 ) {
V_36 = 1 ;
}
} else if ( strncmp ( V_60 , L_95 , 2 ) == 0 ) {
if ( V_36 == 7 ) {
V_36 = 1 ;
}
} else if ( strncmp ( V_60 , L_96 , 2 ) == 0 ) {
if ( V_36 == 9 ) {
V_36 = 6 ;
}
} else if ( strncmp ( V_60 , L_97 , 2 ) == 0 ) {
if ( V_36 == 15 ) {
V_36 = 10 ;
}
} else if ( strncmp ( V_60 , L_98 , 2 ) == 0 ) {
if ( V_36 == 24 ) {
V_36 = 0 ;
}
}
#endif
return V_36 ;
}
static T_20 *
F_54 ( int V_61 )
{
T_20 * V_62 ;
const char * V_63 ;
V_62 = ( T_20 * ) F_55 ( sizeof ( T_20 ) ) ;
V_62 -> V_61 = V_61 ;
V_63 = F_56 ( V_61 ) ;
if ( V_63 != NULL )
V_62 -> V_37 = F_57 ( V_63 ) ;
else
V_62 -> V_37 = F_58 ( L_99 , V_61 ) ;
V_63 = F_59 ( V_61 ) ;
if ( V_63 != NULL )
V_62 -> V_64 = F_57 ( V_63 ) ;
else
V_62 -> V_64 = NULL ;
return V_62 ;
}
static T_21 *
F_60 ( const char * T_19 , T_12 T_22
#ifndef F_11
V_2
#endif
, char * * V_65 )
{
T_21 * V_23 ;
char V_66 [ V_46 ] ;
T_13 * V_59 ;
#ifdef F_11
int V_67 ;
#endif
int V_68 ;
#ifdef F_61
int * V_69 ;
int V_52 , V_70 ;
#endif
T_20 * V_62 ;
V_23 = ( T_21 * ) F_55 ( sizeof *V_23 ) ;
V_66 [ 0 ] = '\0' ;
#ifdef F_62
V_59 = F_63 ( T_19 , V_71 , 0 , 0 , NULL , V_66 ) ;
V_23 -> V_72 = FALSE ;
if ( V_59 == NULL ) {
if ( V_65 != NULL )
* V_65 = F_57 ( V_66 [ 0 ] == '\0' ? L_100 : V_66 ) ;
F_23 ( V_23 ) ;
return NULL ;
}
#elif F_12 ( F_11 )
V_59 = F_64 ( T_19 , V_66 ) ;
if ( V_59 == NULL ) {
if ( V_65 != NULL )
* V_65 = F_57 ( V_66 ) ;
F_23 ( V_23 ) ;
return NULL ;
}
V_67 = F_65 ( V_59 ) ;
if ( V_67 < 0 ) {
if ( V_67 == V_73 )
* V_65 = F_58 ( L_101 ,
F_37 ( V_59 ) ) ;
else
* V_65 = F_57 ( F_66 ( V_67 ) ) ;
F_46 ( V_59 ) ;
F_23 ( V_23 ) ;
return NULL ;
}
if ( V_67 == 0 )
V_23 -> V_72 = FALSE ;
else if ( V_67 == 1 ) {
V_23 -> V_72 = TRUE ;
if ( T_22 )
F_67 ( V_59 , 1 ) ;
} else {
if ( V_65 != NULL ) {
* V_65 = F_58 ( L_102 ,
V_67 ) ;
}
F_46 ( V_59 ) ;
F_23 ( V_23 ) ;
return NULL ;
}
V_67 = F_68 ( V_59 ) ;
if ( V_67 < 0 ) {
if ( V_65 != NULL ) {
if ( V_67 == V_73 )
* V_65 = F_58 ( L_103 ,
F_37 ( V_59 ) ) ;
else
* V_65 = F_57 ( F_66 ( V_67 ) ) ;
}
F_46 ( V_59 ) ;
F_23 ( V_23 ) ;
return NULL ;
}
#else
V_59 = F_69 ( T_19 , V_71 , 0 , 0 , V_66 ) ;
V_23 -> V_72 = FALSE ;
if ( V_59 == NULL ) {
if ( V_65 != NULL )
* V_65 = F_57 ( V_66 [ 0 ] == '\0' ? L_100 : V_66 ) ;
F_23 ( V_23 ) ;
return NULL ;
}
#endif
V_68 = F_38 ( V_59 , T_19 ) ;
#ifdef F_61
V_70 = F_70 ( V_59 , & V_69 ) ;
if ( V_70 == 0 || V_69 == NULL ) {
F_46 ( V_59 ) ;
if ( V_65 != NULL )
* V_65 = NULL ;
F_23 ( V_23 ) ;
return NULL ;
}
V_23 -> V_74 = NULL ;
for ( V_52 = 0 ; V_52 < V_70 ; V_52 ++ ) {
V_62 = F_54 ( V_69 [ V_52 ] ) ;
if ( V_69 [ V_52 ] == V_68 )
V_23 -> V_74 = F_71 ( V_23 -> V_74 ,
V_62 ) ;
else
V_23 -> V_74 = F_72 ( V_23 -> V_74 ,
V_62 ) ;
}
#ifdef F_73
F_74 ( V_69 ) ;
#else
#ifndef F_6
#define F_75 free
F_75 ( V_69 ) ;
#endif
#endif
#else
V_62 = F_54 ( V_68 ) ;
V_23 -> V_74 = F_72 ( V_23 -> V_74 ,
V_62 ) ;
#endif
F_46 ( V_59 ) ;
if ( V_65 != NULL )
* V_65 = NULL ;
return V_23 ;
}
static void
F_76 ( T_23 * V_75 )
{
int V_52 ;
T_23 * V_76 ;
T_24 * V_77 ;
T_25 * V_78 ;
T_26 * V_79 ;
char V_80 [ V_81 ] ;
if ( V_20 ) {
F_51 ( 2 , V_58 , NULL ) ;
}
V_52 = 1 ;
for ( V_76 = F_77 ( V_75 ) ; V_76 != NULL ;
V_76 = F_78 ( V_76 ) ) {
V_77 = ( T_24 * ) V_76 -> V_82 ;
printf ( L_104 , V_52 ++ , V_77 -> V_37 ) ;
if ( V_77 -> V_83 != NULL )
printf ( L_105 , V_77 -> V_83 ) ;
else
printf ( L_106 ) ;
if ( V_77 -> V_84 != NULL )
printf ( L_105 , V_77 -> V_84 ) ;
else
printf ( L_106 ) ;
printf ( L_107 , V_77 -> type ) ;
for ( V_78 = F_79 ( V_77 -> V_85 , 0 ) ; V_78 != NULL ;
V_78 = F_80 ( V_78 ) ) {
if ( V_78 != F_79 ( V_77 -> V_85 , 0 ) )
printf ( L_108 ) ;
V_79 = ( T_26 * ) V_78 -> V_82 ;
switch( V_79 -> V_86 ) {
case V_87 :
if ( F_81 ( V_88 , & V_79 -> V_78 . V_89 , V_80 ,
V_81 ) ) {
printf ( L_60 , V_80 ) ;
} else {
printf ( L_109 ) ;
}
break;
case V_90 :
if ( F_81 ( V_91 , & V_79 -> V_78 . V_92 ,
V_80 , V_81 ) ) {
printf ( L_60 , V_80 ) ;
} else {
printf ( L_110 ) ;
}
break;
default:
printf ( L_111 , V_79 -> V_86 ) ;
}
}
if ( V_77 -> V_93 )
printf ( L_112 ) ;
else
printf ( L_113 ) ;
#ifdef F_82
printf ( L_114 , V_77 -> V_94 ) ;
#endif
printf ( L_4 ) ;
}
}
static void
F_83 ( T_21 * V_23 )
{
T_23 * V_95 ;
T_20 * V_62 ;
const T_8 * V_96 ;
if ( V_20 ) {
F_51 ( 2 , V_58 , NULL ) ;
}
if ( V_23 -> V_72 )
printf ( L_115 ) ;
else
printf ( L_116 ) ;
for ( V_95 = V_23 -> V_74 ; V_95 != NULL ;
V_95 = F_78 ( V_95 ) ) {
V_62 = ( T_20 * ) V_95 -> V_82 ;
if ( V_62 -> V_64 != NULL )
V_96 = V_62 -> V_64 ;
else
V_96 = L_117 ;
printf ( L_118 , V_62 -> V_61 , V_62 -> V_37 ,
V_96 ) ;
}
}
static int
F_84 ( T_12 V_97 )
{
T_23 * V_75 , * V_76 , * V_98 = NULL , * V_99 ;
T_24 * V_77 ;
T_27 * V_100 ;
int V_101 ;
T_8 * V_65 ;
T_13 * V_59 ;
char V_66 [ V_46 ] ;
struct V_102 V_103 ;
V_75 = F_85 ( & V_101 , & V_65 ) ;
if ( V_75 == NULL ) {
if ( V_101 == 0 )
F_29 ( L_119 ) ;
else {
F_29 ( L_60 , V_65 ) ;
F_23 ( V_65 ) ;
}
return V_101 ;
}
for ( V_76 = F_77 ( V_75 ) ; V_76 != NULL ; V_76 = F_78 ( V_76 ) ) {
V_77 = ( T_24 * ) V_76 -> V_82 ;
#ifdef F_62
V_59 = F_63 ( V_77 -> V_37 , V_71 , 0 , 0 , NULL , V_66 ) ;
#else
V_59 = F_69 ( V_77 -> V_37 , V_71 , 0 , 0 , V_66 ) ;
#endif
if ( V_59 ) {
V_100 = ( T_27 * ) F_55 ( sizeof( T_27 ) ) ;
V_100 -> V_37 = F_57 ( V_77 -> V_37 ) ;
V_100 -> V_59 = V_59 ;
V_98 = F_72 ( V_98 , V_100 ) ;
}
}
if ( ! V_98 ) {
F_29 ( L_119 ) ;
return 2 ;
}
if ( V_20 ) {
F_51 ( 2 , V_58 , NULL ) ;
}
if ( ! V_97 ) {
printf ( L_120 , L_121 , L_122 ,
L_123 ) ;
}
V_104 . V_105 = TRUE ;
while ( V_104 . V_105 ) {
for ( V_99 = F_77 ( V_98 ) ; V_99 != NULL ; V_99 = F_78 ( V_99 ) ) {
V_100 = ( T_27 * ) V_99 -> V_82 ;
F_86 ( V_100 -> V_59 , & V_103 ) ;
if ( ! V_97 ) {
printf ( L_124 , V_100 -> V_37 ,
V_103 . V_106 , V_103 . V_107 ) ;
} else {
printf ( L_125 , V_100 -> V_37 ,
V_103 . V_106 , V_103 . V_107 ) ;
fflush ( stdout ) ;
}
}
#ifdef F_6
if ( ! F_87 () ) {
V_104 . V_105 = FALSE ;
}
F_88 ( 1 * 1000 ) ;
#else
F_89 ( 1 ) ;
#endif
}
for ( V_99 = F_77 ( V_98 ) ; V_99 != NULL ; V_99 = F_78 ( V_99 ) ) {
V_100 = ( T_27 * ) V_99 -> V_82 ;
F_46 ( V_100 -> V_59 ) ;
F_23 ( V_100 -> V_37 ) ;
F_23 ( V_100 ) ;
}
F_90 ( V_98 ) ;
F_91 ( V_75 ) ;
return 0 ;
}
static BOOL T_28
F_92 ( T_29 V_108 )
{
F_93 ( V_109 , V_110 ,
L_126 ) ;
F_93 ( V_109 , V_111 ,
L_127 , V_108 ) ;
if ( V_20 || ( V_108 != V_112 ) ) {
F_94 () ;
return TRUE ;
} else {
return FALSE ;
}
}
static void
F_92 ( int T_30 V_2 )
{
F_94 () ;
}
static void
F_95 ( T_12 V_113 )
{
if ( ! V_20 && V_113 ) {
fprintf ( V_22 , L_128 , V_104 . V_114 ) ;
fflush ( V_22 ) ;
}
}
static void
F_96 ( void )
{
F_95 ( V_115 ) ;
V_116 = FALSE ;
}
static void
F_97 ( int T_30 V_2 )
{
int V_117 = V_24 ;
if ( V_118 )
V_116 = TRUE ;
else
F_96 () ;
V_24 = V_117 ;
}
static void
F_98 ( int V_67 )
{
#ifdef F_6
F_99 () ;
#ifdef F_100
printf ( L_129 ) ;
F_101 () ;
#endif
#endif
exit ( V_67 ) ;
}
static void
F_102 ( void )
{
if ( F_103 () ) {
T_31 V_119 [ 2 ] = { V_120 , V_121 } ;
int V_122 = sizeof( V_119 ) / sizeof( T_31 ) ;
T_10 V_23 = F_27 () ;
F_25 ( L_130 ) ;
if ( F_104 ( V_123 , 1 , 0 , 0 , 0 ) == - 1 ) {
F_29 ( L_131 , F_30 ( V_24 ) ) ;
}
F_105 ( V_23 , V_124 , V_122 , V_119 , V_125 ) ;
F_105 ( V_23 , V_126 , V_122 , V_119 , V_125 ) ;
if ( F_28 ( V_23 ) ) {
F_29 ( L_64 , F_30 ( V_24 ) ) ;
}
F_25 ( L_132 ) ;
F_50 () ;
F_25 ( L_133 ) ;
F_105 ( V_23 , V_127 , V_122 , V_119 , V_125 ) ;
if ( F_28 ( V_23 ) ) {
F_29 ( L_64 , F_30 ( V_24 ) ) ;
}
F_25 ( L_134 ) ;
F_31 ( V_23 ) ;
}
}
static void
F_106 ( T_12 V_128 , struct V_129 * V_130 , struct V_131 * V_132 )
{
if ( V_128 ) {
V_132 -> V_133 = F_107 ( V_132 -> V_133 ) ;
V_132 -> V_134 = F_107 ( V_132 -> V_134 ) ;
V_132 -> V_135 = F_107 ( V_132 -> V_135 ) ;
V_132 -> V_136 = F_107 ( V_132 -> V_136 ) ;
}
if ( V_130 -> V_137 == 2 &&
( V_130 -> V_138 < 3 ||
( V_130 -> V_138 == 3 && V_132 -> V_135 > V_132 -> V_136 ) ) ) {
V_8 V_139 ;
V_139 = V_132 -> V_136 ;
V_132 -> V_136 = V_132 -> V_135 ;
V_132 -> V_135 = V_139 ;
}
}
static T_1
F_108 ( int V_140 , char * V_141 , T_11 V_142 , T_12 T_32 V_2 )
{
#ifdef F_6
if ( T_32 ) {
return F_109 ( V_140 , V_141 , ( int ) V_142 , 0 ) ;
} else {
return - 1 ;
}
#else
return F_110 ( V_140 , V_141 , V_142 ) ;
#endif
}
static void * F_111 ( void * V_143 )
{
T_33 * V_144 ;
#ifdef F_6
BOOL V_145 ;
T_29 V_146 , V_147 , V_148 ;
#else
T_11 V_148 ;
int V_146 ;
#endif
V_144 = ( T_33 * ) V_143 ;
while ( V_144 -> V_149 == V_150 ) {
F_112 ( V_144 -> V_151 ) ;
F_113 ( V_144 -> V_152 ) ;
V_148 = 0 ;
while ( V_148 < V_144 -> V_153 ) {
if ( ( V_144 -> V_154 )
#ifndef F_6
|| 1
#endif
)
{
V_146 = F_108 ( V_144 -> V_155 , V_144 -> V_156 + V_148 ,
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
#ifdef F_6
else
{
V_145 = F_114 ( V_144 -> V_159 , V_144 -> V_156 + V_148 ,
V_144 -> V_153 - V_148 ,
& V_146 , NULL ) ;
V_148 += V_146 ;
if ( ! V_145 ) {
V_147 = F_115 () ;
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
F_116 ( V_144 -> V_165 , V_144 -> V_156 ) ;
}
F_117 ( V_144 -> V_152 ) ;
}
return NULL ;
}
static int
F_118 ( int V_140 )
{
T_34 V_166 ;
struct V_7 V_167 ;
F_119 ( & V_166 ) ;
F_120 ( V_140 , & V_166 ) ;
V_167 . V_11 = V_168 / 1000000 ;
V_167 . V_12 = V_168 % 1000000 ;
return F_121 ( V_140 + 1 , & V_166 , NULL , NULL , & V_167 ) ;
}
static int
F_122 ( char * V_169 , T_33 * V_144 , char * V_27 , int V_170 )
{
char * V_171 = V_169 + 4 ;
struct V_172 V_173 ;
char V_141 [ 16 ] ;
char * V_174 ;
unsigned long V_175 ;
T_11 V_55 ;
int V_1 ;
memset ( & V_173 , 0 , sizeof( V_173 ) ) ;
V_174 = strchr ( V_171 , ':' ) ;
if ( V_174 == NULL ) {
V_55 = strlen ( V_171 ) ;
V_175 = V_176 ;
}
else {
V_55 = V_174 - V_171 ;
V_175 = strtoul ( V_174 + 1 , & V_174 , 10 ) ;
if ( * V_174 || V_175 > 65535 ) {
goto V_177;
}
}
if ( V_55 > 15 ) {
goto V_177;
}
F_33 ( V_141 , ( V_33 ) V_55 + 1 , L_60 , V_171 ) ;
V_141 [ V_55 ] = '\0' ;
if ( F_123 ( V_88 , V_141 , & V_173 . V_178 ) <= 0 ) {
goto V_177;
}
V_173 . V_179 = V_88 ;
V_173 . V_180 = F_124 ( ( V_181 ) V_175 ) ;
if ( ( ( V_1 = ( int ) F_125 ( V_88 , V_182 , 0 ) ) < 0 ) ||
( F_126 ( V_1 , (struct V_183 * ) & V_173 , sizeof( V_173 ) ) < 0 ) ) {
#ifdef F_6
T_35 V_184 = NULL ;
int V_185 ;
V_185 = F_127 () ;
F_128 ( V_186 |
V_187 |
V_188 ,
NULL , V_185 , F_129 ( V_189 , V_190 ) ,
( T_35 ) & V_184 , 0 , NULL ) ;
#endif
F_33 ( V_27 , V_170 ,
L_135
#ifdef F_6
L_136 , V_185 , V_184 ? ( char * ) V_184 : L_137 ) ;
if ( V_184 )
F_130 ( V_184 ) ;
#else
L_138 , V_24 , F_30 ( V_24 ) ) ;
#endif
V_144 -> V_149 = V_158 ;
if ( V_1 >= 0 )
F_131 ( V_1 , TRUE ) ;
return - 1 ;
}
void
F_131 ( int V_140 , T_12 T_32 V_2 )
{
#ifdef F_6
if ( T_32 ) {
F_132 ( V_140 ) ;
}
#else
F_133 ( V_140 ) ;
#endif
}
static void
F_134 ( char * V_169 ,
T_33 * V_144 ,
struct V_129 * V_130 ,
char * V_27 , int V_170 )
{
#ifndef F_6
T_36 V_191 ;
struct V_192 V_173 ;
#else
char * V_193 , * V_194 ;
T_37 * V_65 ;
T_16 V_48 ;
#endif
T_1 V_146 ;
int V_1 = - 1 , V_195 ;
T_11 V_148 ;
V_8 V_196 = 0 ;
V_144 -> V_155 = - 1 ;
#ifdef F_6
V_144 -> V_159 = V_197 ;
#endif
F_93 ( V_109 , V_111 , L_139 , V_169 ) ;
if ( strcmp ( V_169 , L_140 ) == 0 ) {
#ifndef F_6
V_1 = 0 ;
#else
V_144 -> V_159 = F_135 ( V_198 ) ;
#endif
} else if ( ! strncmp ( V_169 , L_141 , 4 ) ) {
if ( ( V_1 = F_122 ( V_169 , V_144 , V_27 , V_170 ) ) < 0 ) {
return;
}
} else {
#ifndef F_6
if ( F_136 ( V_169 , & V_191 ) < 0 ) {
if ( V_24 == V_199 || V_24 == V_200 )
V_144 -> V_149 = V_201 ;
else {
F_33 ( V_27 , V_170 ,
L_142
L_143 , F_30 ( V_24 ) ) ;
V_144 -> V_149 = V_158 ;
}
return;
}
if ( F_137 ( V_191 . V_202 ) ) {
V_1 = F_2 ( V_169 , V_203 | V_204 , 0000 ) ;
if ( V_1 == - 1 ) {
F_33 ( V_27 , V_170 ,
L_142
L_144 , F_30 ( V_24 ) ) ;
V_144 -> V_149 = V_158 ;
return;
}
} else if ( F_138 ( V_191 . V_202 ) ) {
V_1 = F_125 ( V_205 , V_182 , 0 ) ;
if ( V_1 == - 1 ) {
F_33 ( V_27 , V_170 ,
L_142
L_145 , F_30 ( V_24 ) ) ;
V_144 -> V_149 = V_158 ;
return;
}
V_173 . V_206 = V_205 ;
if ( F_139 ( V_173 . V_207 , V_169 , sizeof V_173 . V_207 ) > sizeof V_173 . V_207 ) {
F_33 ( V_27 , V_170 ,
L_146
L_147 ) ;
V_144 -> V_149 = V_158 ;
F_133 ( V_1 ) ;
return;
}
V_146 = F_126 ( V_1 , (struct V_183 * ) & V_173 , sizeof V_173 ) ;
if ( V_146 == - 1 ) {
F_33 ( V_27 , V_170 ,
L_146
L_148 , F_30 ( V_24 ) ) ;
V_144 -> V_149 = V_158 ;
F_133 ( V_1 ) ;
return;
}
} else {
if ( F_140 ( V_191 . V_202 ) ) {
V_144 -> V_149 = V_201 ;
} else {
F_33 ( V_27 , V_170 ,
L_149
L_150 , V_169 ) ;
V_144 -> V_149 = V_158 ;
}
return;
}
#else
#define F_141 "\\pipe\\"
V_193 = F_57 ( V_169 ) ;
if ( ( V_194 = strstr ( V_193 , L_151 ) ) == V_193 ) {
V_194 = strchr ( V_193 + 3 , '\\' ) ;
if ( V_194 && F_142 ( V_194 , F_141 , strlen ( F_141 ) ) != 0 )
V_194 = NULL ;
}
F_23 ( V_193 ) ;
if ( ! V_194 ) {
F_33 ( V_27 , V_170 ,
L_149
L_152 , V_169 ) ;
V_144 -> V_149 = V_201 ;
return;
}
V_48 = F_43 ( V_208 . V_54 , T_16 , 0 ) ;
while ( 1 ) {
if( strncmp ( V_48 . V_37 , L_153 , 9 ) == 0 )
V_144 -> V_159 = F_135 ( V_198 ) ;
else
V_144 -> V_159 = F_143 ( F_144 ( V_169 ) , V_209 , 0 , NULL ,
V_210 , 0 , NULL ) ;
if ( V_144 -> V_159 != V_197 )
break;
if ( F_115 () != V_211 ) {
F_128 ( V_186 | V_187 | V_188 ,
NULL , F_115 () , 0 , ( T_35 ) & V_65 , 0 , NULL ) ;
F_33 ( V_27 , V_170 ,
L_154
L_155 ,
V_169 , F_145 ( V_65 ) , F_115 () ) ;
F_130 ( V_65 ) ;
V_144 -> V_149 = V_158 ;
return;
}
if ( ! F_146 ( F_144 ( V_169 ) , 30 * 1000 ) ) {
F_128 ( V_186 | V_187 | V_188 ,
NULL , F_115 () , 0 , ( T_35 ) & V_65 , 0 , NULL ) ;
F_33 ( V_27 , V_170 ,
L_156
L_157 ,
V_169 , F_145 ( V_65 ) , F_115 () ) ;
F_130 ( V_65 ) ;
V_144 -> V_149 = V_158 ;
return;
}
}
#endif
}
V_144 -> V_212 = TRUE ;
#ifdef F_6
if ( V_144 -> V_154 )
#endif
{
V_148 = 0 ;
while ( V_148 < sizeof V_196 ) {
if ( V_1 == - 1 ) {
F_33 ( V_27 , V_170 , L_158 ) ;
goto error;
}
V_195 = F_118 ( V_1 ) ;
if ( V_195 < 0 ) {
F_33 ( V_27 , V_170 ,
L_159 , F_30 ( V_24 ) ) ;
goto error;
} else if ( V_195 > 0 ) {
V_146 = F_108 ( V_1 , ( ( char * ) & V_196 ) + V_148 ,
sizeof V_196 - V_148 ,
V_144 -> V_154 ) ;
if ( V_146 <= 0 ) {
if ( V_146 == 0 )
F_33 ( V_27 , V_170 , L_160 ) ;
else
F_33 ( V_27 , V_170 , L_161 ,
F_30 ( V_24 ) ) ;
goto error;
}
V_148 += V_146 ;
}
}
}
#ifdef F_6
else {
#if F_147 ( 2 , 31 , 0 )
F_148 ( L_162 , & F_111 , V_144 ) ;
#else
F_149 ( & F_111 , V_144 , FALSE , NULL ) ;
#endif
V_144 -> V_156 = ( char * ) & V_196 ;
V_144 -> V_164 = 0 ;
V_144 -> V_153 = sizeof( V_196 ) ;
F_116 ( V_144 -> V_151 , V_144 -> V_156 ) ;
F_112 ( V_144 -> V_165 ) ;
if ( V_144 -> V_164 <= 0 ) {
if ( V_144 -> V_164 == 0 )
F_33 ( V_27 , V_170 , L_160 ) ;
else
F_33 ( V_27 , V_170 , L_161 ,
F_30 ( V_24 ) ) ;
goto error;
}
}
#endif
switch ( V_196 ) {
case V_213 :
case V_214 :
V_144 -> V_215 = FALSE ;
V_144 -> V_216 = FALSE ;
V_144 -> V_217 = V_196 == V_214 ;
break;
case V_218 :
V_144 -> V_215 = FALSE ;
V_144 -> V_216 = TRUE ;
break;
case V_219 :
case V_220 :
V_144 -> V_215 = TRUE ;
V_144 -> V_216 = FALSE ;
V_144 -> V_217 = V_196 == V_220 ;
break;
case V_221 :
V_144 -> V_215 = TRUE ;
V_144 -> V_216 = TRUE ;
break;
default:
F_33 ( V_27 , V_170 , L_163 ) ;
goto error;
}
#ifdef F_6
if ( V_144 -> V_154 )
#endif
{
V_148 = 0 ;
while ( V_148 < sizeof( struct V_129 ) ) {
V_195 = F_118 ( V_1 ) ;
if ( V_195 < 0 ) {
F_33 ( V_27 , V_170 ,
L_159 , F_30 ( V_24 ) ) ;
goto error;
} else if ( V_195 > 0 ) {
V_146 = F_108 ( V_1 , ( ( char * ) V_130 ) + V_148 ,
sizeof( struct V_129 ) - V_148 ,
V_144 -> V_154 ) ;
if ( V_146 <= 0 ) {
if ( V_146 == 0 )
F_33 ( V_27 , V_170 , L_164 ) ;
else
F_33 ( V_27 , V_170 , L_165 ,
F_30 ( V_24 ) ) ;
goto error;
}
V_148 += V_146 ;
}
}
}
#ifdef F_6
else {
V_144 -> V_156 = ( char * ) V_130 ;
V_144 -> V_164 = 0 ;
V_144 -> V_153 = sizeof( struct V_129 ) ;
F_116 ( V_144 -> V_151 , V_144 -> V_156 ) ;
F_112 ( V_144 -> V_165 ) ;
if ( V_144 -> V_164 <= 0 ) {
if ( V_144 -> V_164 == 0 )
F_33 ( V_27 , V_170 , L_164 ) ;
else
F_33 ( V_27 , V_170 , L_166 ,
F_30 ( V_24 ) ) ;
goto error;
}
}
#endif
if ( V_144 -> V_215 ) {
V_130 -> V_137 = F_150 ( V_130 -> V_137 ) ;
V_130 -> V_138 = F_150 ( V_130 -> V_138 ) ;
V_130 -> V_222 = F_107 ( V_130 -> V_222 ) ;
V_130 -> V_223 = F_107 ( V_130 -> V_223 ) ;
}
V_144 -> V_36 = V_130 -> V_223 ;
if ( V_130 -> V_137 < 2 ) {
F_33 ( V_27 , V_170 , L_167 ) ;
goto error;
}
V_144 -> V_224 = V_225 ;
V_144 -> V_149 = V_150 ;
V_144 -> V_155 = V_1 ;
return;
error:
F_93 ( V_109 , V_111 , L_168 , V_27 ) ;
V_144 -> V_149 = V_158 ;
F_131 ( V_1 , V_144 -> V_154 ) ;
V_144 -> V_155 = - 1 ;
}
static int
F_151 ( T_38 * V_226 , T_33 * V_144 , T_39 * V_82 , char * V_27 , int V_170 )
{
struct V_227 V_228 ;
enum { V_229 , V_230 , V_231 , V_232 ,
V_233 } V_234 ;
#ifdef F_6
#if ! F_147 ( 2 , 31 , 18 )
T_40 V_235 ;
#endif
T_41 V_236 ;
T_37 * V_65 ;
#endif
T_1 V_146 ;
#ifdef F_152
F_93 ( V_109 , V_111 , L_169 ) ;
#endif
switch ( V_144 -> V_224 ) {
case V_225 :
#ifdef F_6
if ( F_153 ( V_144 -> V_152 ) ) {
#endif
V_144 -> V_224 = V_237 ;
V_144 -> V_153 = V_144 -> V_216 ?
sizeof( struct V_238 ) : sizeof( struct V_131 ) ;
V_144 -> V_164 = 0 ;
#ifdef F_6
V_144 -> V_156 = ( char * ) & V_144 -> V_239 ;
F_116 ( V_144 -> V_151 , V_144 -> V_156 ) ;
F_117 ( V_144 -> V_152 ) ;
}
#endif
case V_237 :
#ifdef F_6
if ( V_144 -> V_154 )
#endif
{
V_146 = F_108 ( V_144 -> V_155 , ( ( char * ) & V_144 -> V_239 ) + V_144 -> V_164 ,
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
#ifdef F_6
else {
#if F_147 ( 2 , 31 , 18 )
V_236 = F_154 ( V_144 -> V_165 , V_168 ) ;
#else
F_155 ( & V_235 ) ;
F_156 ( & V_235 , V_168 ) ;
V_236 = F_157 ( V_144 -> V_165 , & V_235 ) ;
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
#ifdef F_6
if ( F_153 ( V_144 -> V_152 ) ) {
#endif
V_144 -> V_224 = V_241 ;
V_144 -> V_153 = V_144 -> V_239 . V_130 . V_135 ;
V_144 -> V_164 = 0 ;
#ifdef F_6
V_144 -> V_156 = ( char * ) V_82 ;
F_116 ( V_144 -> V_151 , V_144 -> V_156 ) ;
F_117 ( V_144 -> V_152 ) ;
}
#endif
case V_241 :
#ifdef F_6
if ( V_144 -> V_154 )
#endif
{
V_146 = F_108 ( V_144 -> V_155 ,
V_82 + V_144 -> V_164 ,
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
#ifdef F_6
else {
#if F_147 ( 2 , 31 , 18 )
V_236 = F_154 ( V_144 -> V_165 , V_168 ) ;
#else
F_155 ( & V_235 ) ;
F_156 ( & V_235 , V_168 ) ;
V_236 = F_157 ( V_144 -> V_165 , & V_235 ) ;
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
F_33 ( V_27 , V_170 , L_170 ) ;
V_234 = V_233 ;
}
switch ( V_234 ) {
case V_229 :
F_106 ( V_144 -> V_215 , & V_144 -> V_242 ,
& V_144 -> V_239 . V_130 ) ;
if ( V_144 -> V_239 . V_130 . V_135 > V_243 ) {
F_33 ( V_27 , V_170 , L_171 ,
V_226 -> V_114 + 1 , V_144 -> V_239 . V_130 . V_135 ) ;
break;
}
if ( V_144 -> V_239 . V_130 . V_135 ) {
V_144 -> V_224 = V_240 ;
return 0 ;
}
case V_230 :
V_228 . V_244 . V_11 = V_144 -> V_239 . V_130 . V_133 ;
V_228 . V_244 . V_12 = V_144 -> V_239 . V_130 . V_134 ;
V_228 . V_245 = V_144 -> V_239 . V_130 . V_135 ;
V_228 . V_55 = V_144 -> V_239 . V_130 . V_136 ;
if ( V_246 ) {
F_158 ( ( V_247 * ) V_144 , & V_228 , V_82 ) ;
} else {
F_159 ( ( V_247 * ) V_144 , & V_228 , V_82 ) ;
}
V_144 -> V_224 = V_225 ;
return 1 ;
case V_231 :
V_144 -> V_149 = V_157 ;
return - 1 ;
case V_232 :
#ifdef F_6
F_128 ( V_186 | V_187 | V_188 ,
NULL , F_115 () , 0 , ( T_35 ) & V_65 , 0 , NULL ) ;
F_33 ( V_27 , V_170 ,
L_172 ,
F_145 ( V_65 ) , F_115 () ) ;
F_130 ( V_65 ) ;
#else
F_33 ( V_27 , V_170 , L_173 ,
F_30 ( V_24 ) ) ;
#endif
case V_233 :
break;
}
V_144 -> V_149 = V_158 ;
return - 1 ;
}
static void F_160 ( T_38 * V_226 )
{
T_18 V_52 ;
T_33 * V_144 ;
F_93 ( V_109 , V_111 , L_174 ) ;
for ( V_52 = 0 ; V_52 < V_226 -> V_248 -> V_55 ; V_52 ++ ) {
V_144 = F_43 ( V_226 -> V_248 , T_33 * , V_52 ) ;
if ( V_144 -> V_155 >= 0 ) {
F_161 ( V_144 -> V_212 ) ;
F_131 ( V_144 -> V_155 , V_144 -> V_154 ) ;
V_144 -> V_155 = - 1 ;
}
#ifdef F_6
if ( V_144 -> V_159 != V_197 ) {
F_162 ( V_144 -> V_159 ) ;
V_144 -> V_159 = V_197 ;
}
#endif
if ( V_144 -> V_35 != NULL ) {
F_93 ( V_109 , V_111 , L_175 , ( void * ) V_144 -> V_35 ) ;
F_46 ( V_144 -> V_35 ) ;
V_144 -> V_35 = NULL ;
}
}
V_226 -> V_105 = FALSE ;
#ifdef F_6
F_99 () ;
#endif
}
static T_42
F_163 ( T_13 * V_35 , T_12 V_212 ,
const T_8 * V_37 , const T_8 * V_42 )
{
struct V_40 V_41 ;
F_93 ( V_109 , V_111 , L_176 , V_42 ) ;
if ( V_42 && ! V_212 ) {
if ( ! F_39 ( V_37 , V_35 , & V_41 , V_42 ) ) {
return V_249 ;
}
if ( F_164 ( V_35 , & V_41 ) < 0 ) {
#ifdef F_165
F_166 ( & V_41 ) ;
#endif
return V_250 ;
}
#ifdef F_165
F_166 ( & V_41 ) ;
#endif
}
return V_251 ;
}
static T_12
F_167 ( T_15 * V_47 , T_38 * V_226 , char * V_27 , int V_28 )
{
int V_101 ;
T_18 V_52 ;
T_33 * V_144 ;
T_16 V_48 ;
T_12 V_252 ;
F_93 ( V_109 , V_111 , L_177 ) ;
if ( ( V_47 -> V_253 == FALSE ) &&
( V_47 -> V_54 -> V_55 > 1 ) ) {
F_33 ( V_27 , V_28 ,
L_178 ) ;
return FALSE ;
}
if ( V_47 -> V_254 ) {
V_226 -> V_255 = F_168 ( & V_101 ) ;
} else {
V_226 -> V_255 = F_169 ( V_226 -> V_256 , L_179 ) ;
if ( V_226 -> V_255 == NULL ) {
V_101 = V_24 ;
}
}
if ( V_226 -> V_255 ) {
if ( V_47 -> V_253 ) {
char V_257 [ 100 ] ;
T_6 * V_258 ;
V_258 = F_170 ( L_61 ) ;
F_171 ( V_258 ) ;
F_33 ( V_257 , sizeof( V_257 ) , L_180 , F_18 () ) ;
V_252 = F_172 ( V_226 -> V_255 ,
( const char * ) V_47 -> V_259 ,
NULL ,
V_258 -> V_17 ,
V_257 ,
- 1 ,
& V_226 -> V_260 ,
& V_101 ) ;
for ( V_52 = 0 ; V_252 && ( V_52 < V_47 -> V_54 -> V_55 ) ; V_52 ++ ) {
V_48 = F_43 ( V_47 -> V_54 , T_16 , V_52 ) ;
V_144 = F_43 ( V_226 -> V_248 , T_33 * , V_52 ) ;
if ( V_144 -> V_212 ) {
V_144 -> V_222 = V_144 -> V_242 . V_222 ;
} else {
V_144 -> V_222 = F_173 ( V_144 -> V_35 ) ;
}
V_252 = F_174 ( V_104 . V_255 ,
NULL ,
V_48 . V_37 ,
V_48 . V_261 ,
V_48 . V_42 ,
V_258 -> V_17 ,
V_144 -> V_36 ,
V_144 -> V_222 ,
& ( V_104 . V_260 ) ,
0 ,
V_144 -> V_217 ? 9 : 6 ,
& V_104 . V_101 ) ;
}
F_175 ( V_258 , TRUE ) ;
} else {
V_144 = F_43 ( V_226 -> V_248 , T_33 * , 0 ) ;
if ( V_144 -> V_212 ) {
V_144 -> V_222 = V_144 -> V_242 . V_222 ;
} else {
V_144 -> V_222 = F_173 ( V_144 -> V_35 ) ;
}
V_252 = F_176 ( V_226 -> V_255 , V_144 -> V_36 , V_144 -> V_222 ,
V_144 -> V_217 , & V_226 -> V_260 , & V_101 ) ;
}
if ( ! V_252 ) {
fclose ( V_226 -> V_255 ) ;
V_226 -> V_255 = NULL ;
}
}
if ( V_226 -> V_255 == NULL ) {
switch ( V_101 ) {
default:
if ( V_101 < 0 ) {
F_33 ( V_27 , V_28 ,
L_181
L_182 ,
V_47 -> V_262 , V_101 ) ;
} else {
F_33 ( V_27 , V_28 ,
L_181
L_183 ,
V_47 -> V_262 , F_30 ( V_101 ) ) ;
}
break;
}
return FALSE ;
}
return TRUE ;
}
static T_12
F_177 ( T_15 * V_47 , T_38 * V_226 , int * V_263 )
{
unsigned int V_52 ;
T_33 * V_144 ;
T_3 V_264 = F_5 () ;
F_93 ( V_109 , V_111 , L_184 ) ;
if ( V_47 -> V_254 ) {
return F_178 ( & V_47 -> V_262 , V_263 ) ;
} else {
if ( V_47 -> V_253 ) {
for ( V_52 = 0 ; V_52 < V_104 . V_248 -> V_55 ; V_52 ++ ) {
V_144 = F_43 ( V_104 . V_248 , T_33 * , V_52 ) ;
if ( ! V_144 -> V_212 ) {
T_3 V_265 , V_266 ;
struct V_102 V_267 ;
if ( F_86 ( V_144 -> V_35 , & V_267 ) >= 0 ) {
V_265 = V_144 -> V_268 ;
V_266 = V_267 . V_107 + V_144 -> V_269 + V_144 -> V_270 ;
} else {
V_265 = V_271 ;
V_266 = V_271 ;
}
F_179 ( V_226 -> V_255 ,
V_52 ,
& V_226 -> V_260 ,
L_185 ,
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
F_180 ( T_38 * V_226 ,
char * V_27 , int V_28 , T_33 * V_144 )
{
int V_274 ;
T_43 V_275 ;
T_39 V_276 [ V_243 ] ;
#ifndef F_6
int V_195 ;
#endif
V_275 = V_226 -> V_114 ;
if ( V_144 -> V_212 ) {
#ifdef F_152
F_93 ( V_109 , V_111 , L_186 ) ;
#endif
#ifndef F_6
V_195 = F_118 ( V_144 -> V_155 ) ;
if ( V_195 <= 0 ) {
if ( V_195 < 0 && V_24 != V_277 ) {
F_33 ( V_27 , V_28 ,
L_159 , F_30 ( V_24 ) ) ;
F_45 ( V_27 , V_39 ) ;
V_226 -> V_105 = FALSE ;
}
} else {
#endif
V_274 = F_151 ( V_226 , V_144 , V_276 , V_27 , V_28 ) ;
if ( V_274 < 0 ) {
V_226 -> V_105 = FALSE ;
}
#ifndef F_6
}
#endif
}
else
{
#ifdef F_181
#ifdef F_152
F_93 ( V_109 , V_111 , L_187 ) ;
#endif
if ( V_144 -> V_278 != - 1 ) {
V_195 = F_118 ( V_144 -> V_278 ) ;
if ( V_195 > 0 ) {
if ( V_246 ) {
V_274 = F_182 ( V_144 -> V_35 , 1 , F_158 , ( V_247 * ) V_144 ) ;
} else {
V_274 = F_182 ( V_144 -> V_35 , 1 , F_159 , ( V_247 * ) V_144 ) ;
}
if ( V_274 < 0 ) {
if ( V_274 == - 1 ) {
V_144 -> V_279 = TRUE ;
}
V_226 -> V_105 = FALSE ;
}
} else {
if ( V_195 < 0 && V_24 != V_277 ) {
F_33 ( V_27 , V_28 ,
L_159 , F_30 ( V_24 ) ) ;
F_45 ( V_27 , V_39 ) ;
V_226 -> V_105 = FALSE ;
}
}
}
else
#endif
{
#if 1
#ifdef F_152
F_93 ( V_109 , V_111 , L_188 ) ;
#endif
#ifdef F_6
if ( V_246 ) {
V_274 = F_182 ( V_144 -> V_35 , 1 , F_158 , ( V_247 * ) V_144 ) ;
} else {
V_274 = F_182 ( V_144 -> V_35 , 1 , F_159 , ( V_247 * ) V_144 ) ;
}
#else
if ( V_246 ) {
V_274 = F_182 ( V_144 -> V_35 , - 1 , F_158 , ( V_247 * ) V_144 ) ;
} else {
V_274 = F_182 ( V_144 -> V_35 , - 1 , F_159 , ( V_247 * ) V_144 ) ;
}
#endif
if ( V_274 < 0 ) {
if ( V_274 == - 1 ) {
V_144 -> V_279 = TRUE ;
}
V_226 -> V_105 = FALSE ;
}
#else
#ifdef F_152
F_93 ( V_109 , V_111 , L_189 ) ;
#endif
{
int V_280 ;
struct V_227 * V_281 ;
V_247 * V_282 ;
V_280 = 0 ;
while( V_226 -> V_105 &&
( V_280 = F_183 ( V_144 -> V_35 , & V_281 , & V_282 ) ) == 1 ) {
if ( V_246 ) {
F_158 ( ( V_247 * ) V_144 , V_281 , V_282 ) ;
} else {
F_159 ( ( V_247 * ) V_144 , V_281 , V_282 ) ;
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
#ifdef F_152
F_93 ( V_109 , V_111 , L_190 , V_274 , F_184 ( V_274 , L_61 , L_191 ) ) ;
#endif
return V_226 -> V_114 - V_275 ;
}
static T_6 *
F_185 ( const char * V_26 )
{
T_8 * V_283 ;
T_6 * V_284 ;
V_283 = strchr ( V_26 , '{' ) ;
if ( V_283 == NULL )
return F_170 ( V_26 ) ;
V_284 = F_170 ( V_283 + 1 ) ;
V_283 = strchr ( V_284 -> V_17 , '}' ) ;
if ( V_283 == NULL )
return V_284 ;
V_284 = F_186 ( V_284 , V_283 - V_284 -> V_17 ) ;
return V_284 ;
}
static T_12
F_187 ( T_15 * V_47 , int * V_256 ,
char * V_27 , int V_28 )
{
char * V_285 ;
T_8 * V_286 ;
T_8 * V_287 ;
T_12 V_288 ;
F_93 ( V_109 , V_111 , L_192 ,
( V_47 -> V_262 ) ? V_47 -> V_262 : L_193 ) ;
if ( V_47 -> V_262 != NULL ) {
V_286 = F_57 ( V_47 -> V_262 ) ;
if ( V_47 -> V_289 == TRUE ) {
if ( V_47 -> V_254 ) {
F_33 ( V_27 , V_28 ,
L_194 ) ;
F_23 ( V_286 ) ;
return FALSE ;
}
if ( strcmp ( V_286 , L_140 ) == 0 ) {
* V_256 = 1 ;
#ifdef F_6
F_188 ( 1 , V_290 ) ;
#endif
}
}
else {
if ( V_47 -> V_254 ) {
* V_256 = F_189 ( V_286 ,
( V_47 -> V_291 ) ? V_47 -> V_292 : 0 ,
V_47 -> V_293 ) ;
if ( * V_256 != - 1 ) {
F_23 ( V_286 ) ;
V_286 = F_57 ( F_190 () ) ;
}
} else {
* V_256 = F_2 ( V_286 , V_294 | V_290 | V_295 | V_296 ,
( V_47 -> V_293 ) ? 0640 : 0600 ) ;
}
}
V_288 = FALSE ;
} else {
if ( V_208 . V_54 -> V_55 > 1 ) {
V_287 = F_58 ( L_195 , V_208 . V_54 -> V_55 ) ;
} else {
T_8 * V_297 ;
V_297 = F_191 ( F_43 ( V_208 . V_54 , T_16 , 0 ) . V_298 ) ;
#ifdef F_6
if ( strncmp ( L_196 , V_297 , 5 ) == 0 )
{
T_6 * V_26 ;
V_26 = F_185 ( V_297 ) ;
F_23 ( V_297 ) ;
V_297 = F_57 ( V_26 -> V_17 ) ;
F_175 ( V_26 , TRUE ) ;
}
#endif
if ( V_47 -> V_253 ) {
V_287 = F_192 ( L_197 , V_297 , NULL ) ;
} else{
V_287 = F_192 ( L_198 , V_297 , NULL ) ;
}
F_23 ( V_297 ) ;
}
* V_256 = F_193 ( & V_285 , V_287 ) ;
F_23 ( V_287 ) ;
V_286 = F_57 ( V_285 ) ;
V_288 = TRUE ;
}
if ( * V_256 == - 1 ) {
if ( V_288 ) {
F_33 ( V_27 , V_28 ,
L_199
L_200 , V_286 , F_30 ( V_24 ) ) ;
} else {
if ( V_47 -> V_254 ) {
F_194 () ;
}
F_33 ( V_27 , V_28 ,
L_201
L_200 , V_286 ,
F_30 ( V_24 ) ) ;
}
F_23 ( V_286 ) ;
return FALSE ;
}
if ( V_47 -> V_262 != NULL ) {
F_23 ( V_47 -> V_262 ) ;
}
V_47 -> V_262 = V_286 ;
return TRUE ;
}
static T_12
F_195 ( T_15 * V_47 ,
T_44 * V_299 ,
T_44 * V_300 ,
T_44 * V_301 )
{
T_18 V_52 ;
T_33 * V_144 ;
T_16 V_48 ;
T_12 V_252 ;
if ( V_47 -> V_254 ) {
if ( V_299 != NULL &&
F_196 ( V_299 , ++ V_104 . V_302 ) ) {
V_104 . V_105 = FALSE ;
return FALSE ;
}
if ( F_197 ( & V_104 . V_255 , & V_47 -> V_262 ,
& V_104 . V_256 , & V_104 . V_101 ) ) {
V_104 . V_260 = 0 ;
if ( V_47 -> V_253 ) {
char V_257 [ 100 ] ;
T_6 * V_258 ;
V_258 = F_170 ( L_61 ) ;
F_171 ( V_258 ) ;
F_33 ( V_257 , sizeof( V_257 ) , L_180 , F_18 () ) ;
V_252 = F_172 ( V_104 . V_255 ,
NULL ,
NULL ,
V_258 -> V_17 ,
V_257 ,
- 1 ,
& ( V_104 . V_260 ) ,
& V_104 . V_101 ) ;
for ( V_52 = 0 ; V_252 && ( V_52 < V_47 -> V_54 -> V_55 ) ; V_52 ++ ) {
V_48 = F_43 ( V_47 -> V_54 , T_16 , V_52 ) ;
V_144 = F_43 ( V_104 . V_248 , T_33 * , V_52 ) ;
V_252 = F_174 ( V_104 . V_255 ,
NULL ,
V_48 . V_37 ,
V_48 . V_261 ,
V_48 . V_42 ,
V_258 -> V_17 ,
V_144 -> V_36 ,
V_144 -> V_222 ,
& ( V_104 . V_260 ) ,
0 ,
V_144 -> V_217 ? 9 : 6 ,
& V_104 . V_101 ) ;
}
F_175 ( V_258 , TRUE ) ;
} else {
V_144 = F_43 ( V_104 . V_248 , T_33 * , 0 ) ;
V_252 = F_176 ( V_104 . V_255 , V_144 -> V_36 , V_144 -> V_222 ,
V_144 -> V_217 , & V_104 . V_260 , & V_104 . V_101 ) ;
}
if ( ! V_252 ) {
fclose ( V_104 . V_255 ) ;
V_104 . V_255 = NULL ;
V_104 . V_105 = FALSE ;
return FALSE ;
}
if ( V_300 )
F_198 ( V_300 ) ;
if ( V_301 )
F_198 ( V_301 ) ;
fflush ( V_104 . V_255 ) ;
if ( ! V_115 )
F_199 ( V_104 . V_303 ) ;
V_104 . V_303 = 0 ;
F_200 ( V_47 -> V_262 ) ;
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
F_201 ( void * V_143 )
{
T_33 * V_144 ;
char V_27 [ V_49 + 1 ] ;
V_144 = ( T_33 * ) V_143 ;
F_93 ( V_109 , V_110 , L_202 ,
V_144 -> V_304 ) ;
while ( V_104 . V_105 ) {
F_180 ( & V_104 , V_27 , sizeof( V_27 ) , V_144 ) ;
}
F_93 ( V_109 , V_110 , L_203 ,
V_144 -> V_304 ) ;
F_202 ( NULL ) ;
return ( NULL ) ;
}
static void
F_94 ( void )
{
#ifdef F_203
T_18 V_52 ;
T_33 * V_144 ;
for ( V_52 = 0 ; V_52 < V_104 . V_248 -> V_55 ; V_52 ++ ) {
V_144 = F_43 ( V_104 . V_248 , T_33 * , V_52 ) ;
if ( V_144 -> V_35 != NULL )
F_204 ( V_144 -> V_35 ) ;
}
#endif
V_104 . V_105 = FALSE ;
}
static void
F_205 ( char * V_27 , int V_305 , const char * V_306 ,
int V_101 , T_12 V_307 )
{
switch ( V_101 ) {
case V_308 :
F_33 ( V_27 , V_305 ,
L_204
L_205
L_206
L_207 ,
V_306 ) ;
break;
#ifdef F_206
case F_206 :
F_33 ( V_27 , V_305 ,
L_204
L_205
L_208
L_209
L_210 ,
V_306 ) ;
break;
#endif
default:
if ( V_307 ) {
F_33 ( V_27 , V_305 ,
L_211
L_212 ,
V_306 , F_30 ( V_101 ) ) ;
} else {
F_33 ( V_27 , V_305 ,
L_213
L_205
L_214 ,
V_306 , F_30 ( V_101 ) ) ;
}
break;
}
}
static void
F_159 ( V_247 * V_309 , const struct V_227 * V_228 ,
const V_247 * V_310 )
{
T_33 * V_144 = ( T_33 * ) ( void * ) V_309 ;
int V_101 ;
T_18 V_311 = V_144 -> V_217 ? 1000000000 : 1000000 ;
if ( ! V_104 . V_105 ) {
V_144 -> V_270 ++ ;
return;
}
if ( V_104 . V_255 ) {
T_12 V_252 ;
if ( V_208 . V_253 ) {
V_252 = F_207 ( V_104 . V_255 ,
NULL ,
V_228 -> V_244 . V_11 , ( V_312 ) V_228 -> V_244 . V_12 ,
V_228 -> V_245 , V_228 -> V_55 ,
V_144 -> V_304 ,
V_311 ,
V_310 , 0 ,
& V_104 . V_260 , & V_101 ) ;
} else {
V_252 = F_208 ( V_104 . V_255 ,
V_228 -> V_244 . V_11 , ( V_312 ) V_228 -> V_244 . V_12 ,
V_228 -> V_245 , V_228 -> V_55 ,
V_310 ,
& V_104 . V_260 , & V_101 ) ;
}
if ( ! V_252 ) {
V_104 . V_105 = FALSE ;
V_104 . V_101 = V_101 ;
V_144 -> V_269 ++ ;
} else {
#if F_12 ( F_100 ) || F_12 ( V_313 )
F_93 ( V_109 , V_110 ,
L_215 ,
V_228 -> V_245 , V_144 -> V_304 ) ;
#endif
V_104 . V_114 ++ ;
V_144 -> V_268 ++ ;
if ( ( V_104 . V_314 > 0 ) && ( V_104 . V_114 >= V_104 . V_314 ) ) {
V_104 . V_105 = FALSE ;
}
}
}
}
static void
F_158 ( V_247 * V_309 , const struct V_227 * V_228 ,
const V_247 * V_310 )
{
T_33 * V_144 = ( T_33 * ) ( void * ) V_309 ;
T_45 * V_315 ;
T_12 V_316 ;
if ( ! V_104 . V_105 ) {
V_144 -> V_270 ++ ;
return;
}
V_315 = ( T_45 * ) F_55 ( sizeof( T_45 ) ) ;
if ( V_315 == NULL ) {
V_144 -> V_269 ++ ;
return;
}
V_315 -> V_144 = V_144 ;
V_315 -> V_228 = * V_228 ;
V_315 -> V_310 = ( V_247 * ) F_55 ( V_228 -> V_245 ) ;
if ( V_315 -> V_310 == NULL ) {
V_144 -> V_269 ++ ;
F_23 ( V_315 ) ;
return;
}
memcpy ( V_315 -> V_310 , V_310 , V_228 -> V_245 ) ;
F_209 ( V_317 ) ;
if ( ( ( V_318 == 0 ) || ( V_319 < V_318 ) ) &&
( ( V_320 == 0 ) || ( V_321 < V_320 ) ) ) {
V_316 = FALSE ;
F_210 ( V_317 , V_315 ) ;
V_319 += V_228 -> V_245 ;
V_321 += 1 ;
} else {
V_316 = TRUE ;
}
F_211 ( V_317 ) ;
if ( V_316 ) {
V_144 -> V_269 ++ ;
F_23 ( V_315 -> V_310 ) ;
F_23 ( V_315 ) ;
F_93 ( V_109 , V_110 ,
L_216 ,
V_228 -> V_245 , V_144 -> V_304 ) ;
} else {
V_144 -> V_268 ++ ;
F_93 ( V_109 , V_110 ,
L_217 ,
V_228 -> V_245 , V_144 -> V_304 ) ;
}
F_93 ( V_109 , V_110 ,
L_218 V_322 L_219 V_322 L_220 ,
V_319 , V_321 ) ;
}
static int
F_212 ( const char * V_26 , const char * V_323 )
{
int V_324 = 0 , type , V_325 ;
T_8 * * V_326 = NULL ;
V_326 = F_213 ( V_323 , L_108 , 2 ) ;
if ( V_326 [ 0 ] )
V_324 = atoi ( V_326 [ 0 ] ) ;
if ( V_326 [ 1 ] ) {
type = F_214 ( V_326 [ 1 ] ) ;
if ( type == - 1 ) {
V_325 = V_327 ;
goto V_328;
}
}
else
type = - 1 ;
V_325 = F_215 () ;
if ( V_325 ) {
F_29 ( L_221 , abs ( V_325 ) , F_30 ( abs ( V_325 ) ) ) ;
V_325 = 2 ;
goto V_328;
}
V_325 = F_216 ( V_26 , V_324 , type ) ;
if ( V_325 ) {
F_29 ( L_222 , abs ( V_325 ) , F_30 ( abs ( V_325 ) ) ) ;
V_325 = 2 ;
goto V_328;
}
if ( V_20 )
F_51 ( 2 , V_58 , NULL ) ;
V_325 = 0 ;
V_328:
F_217 ( V_326 ) ;
return V_325 ;
}
static void
F_218 ( T_6 * V_17 )
{
F_219 ( V_17 , L_223 ) ;
F_220 ( V_17 ) ;
F_219 ( V_17 , L_223 ) ;
#ifdef F_221
F_219 ( V_17 , L_224 ) ;
#ifdef F_222
F_219 ( V_17 , F_222 ) ;
#else
F_219 ( V_17 , L_225 ) ;
#endif
#else
F_219 ( V_17 , L_226 ) ;
#endif
}
static void
F_223 ( T_6 * V_17 )
{
F_219 ( V_17 , L_223 ) ;
F_224 ( V_17 ) ;
#if F_12 ( F_221 ) && ! F_12 ( F_6 )
F_225 ( V_17 , L_227 , F_226 () ) ;
#endif
}
int
main ( int V_329 , char * V_330 [] )
{
T_6 * V_15 ;
T_6 * V_16 ;
int V_323 ;
static const struct V_331 V_332 [] = {
{ ( char * ) L_228 , V_333 , NULL , 'h' } ,
{ ( char * ) L_229 , V_333 , NULL , 'v' } ,
V_334
{ 0 , 0 , 0 , 0 }
} ;
T_12 V_335 = FALSE ;
#ifdef F_6
T_46 V_336 ;
#else
struct V_337 V_338 , V_339 ;
#endif
T_12 V_340 = TRUE ;
T_12 V_341 ;
struct V_102 V_267 ;
T_47 V_342 ;
T_12 V_343 = FALSE ;
T_12 V_344 = FALSE ;
#ifdef F_13
T_12 V_345 = FALSE ;
#endif
T_12 V_346 = FALSE ;
T_8 * V_347 = NULL ;
T_12 V_97 = FALSE ;
T_12 V_348 = FALSE ;
int V_67 , V_349 = 0 ;
T_43 V_52 ;
T_18 V_53 ;
#if F_12 ( V_350 ) && F_12 ( V_351 )
struct V_352 V_353 ;
#endif
T_6 * V_17 ;
F_227 ( F_20 , F_24 ) ;
V_15 = F_170 ( L_230 ) ;
F_228 ( V_15 , NULL , F_218 ) ;
V_16 = F_170 ( L_231 ) ;
F_229 ( V_16 , F_223 ) ;
F_230 ( L_59
L_4
L_60
L_4
L_60 ,
F_18 () , V_15 -> V_17 , V_16 -> V_17 ) ;
#ifdef F_6
F_231 ( V_329 , V_330 ) ;
F_232 () ;
F_233 () ;
#endif
#ifdef F_13
#define F_234 "d"
#else
#define F_234 ""
#endif
#ifdef F_14
#define F_235 "r"
#define F_236 "u"
#else
#define F_235 ""
#define F_236 ""
#endif
#ifdef F_15
#define F_237 "m:"
#else
#define F_237 ""
#endif
#define F_238 OPTSTRING_CAPTURE_COMMON "C:" OPTSTRING_d "gh" "k:" OPTSTRING_m "MN:nPq" OPTSTRING_r "St" OPTSTRING_u "vw:Z:"
#ifdef V_313
if ( ( V_354 = F_239 ( L_232 , L_233 ) ) == NULL ) {
fprintf ( V_22 , L_234 ) ;
exit ( 1 ) ;
}
#endif
#if F_12 ( V_350 ) && F_12 ( V_351 )
if ( F_240 ( & V_353 ) == 0 ) {
if ( strcmp ( V_353 . V_355 , L_235 ) == 0 ||
strcmp ( V_353 . V_355 , L_236 ) == 0 ||
strcmp ( V_353 . V_355 , L_237 ) == 0 )
V_356 = TRUE ;
}
#endif
for ( V_52 = 1 ; V_52 < V_329 ; V_52 ++ ) {
if ( strcmp ( L_238 , V_330 [ V_52 ] ) == 0 ) {
V_20 = TRUE ;
V_97 = TRUE ;
#ifdef F_6
F_188 ( 2 , V_290 ) ;
#endif
}
}
V_342 =
( T_47 ) (
V_357 |
V_358 |
V_359 |
V_360 |
V_110 |
V_111 |
V_361 |
V_362 ) ;
F_241 ( NULL ,
V_342 ,
V_363 , NULL ) ;
F_241 ( V_364 ,
V_342 ,
V_363 , NULL ) ;
F_241 ( V_365 ,
V_342 ,
V_363 , NULL ) ;
F_241 ( V_109 ,
V_342 ,
V_363 , NULL ) ;
V_104 . V_248 = F_242 ( FALSE , FALSE , sizeof( T_33 * ) ) ;
#if ! F_147 ( 2 , 31 , 0 )
F_243 ( NULL ) ;
#endif
#ifdef F_6
F_244 () ;
F_245 ( F_246 ( 1 , 1 ) , & V_336 ) ;
F_247 ( F_92 , TRUE ) ;
#else
memset ( & V_338 , 0 , sizeof( V_338 ) ) ;
V_338 . V_366 = F_92 ;
V_338 . V_367 = 0 ;
F_248 ( & V_338 . V_368 ) ;
V_337 ( V_369 , & V_338 , NULL ) ;
V_337 ( V_370 , & V_338 , NULL ) ;
V_337 ( V_371 , & V_338 , NULL ) ;
V_337 ( V_372 , NULL , & V_339 ) ;
if ( V_339 . V_366 == V_373 )
V_337 ( V_372 , & V_338 , NULL ) ;
#ifdef F_249
V_338 . V_366 = F_97 ;
V_338 . V_367 = V_374 ;
F_248 ( & V_338 . V_368 ) ;
V_337 ( F_249 , & V_338 , NULL ) ;
#endif
#endif
#ifdef F_16
F_1 () ;
#endif
F_250 () ;
#ifdef F_49
F_102 () ;
#endif
F_251 ( & V_208 ) ;
V_208 . V_375 = TRUE ;
V_208 . V_291 = TRUE ;
V_208 . V_20 = V_20 ;
while ( ( V_323 = F_252 ( V_329 , V_330 , F_238 , V_332 , NULL ) ) != - 1 ) {
switch ( V_323 ) {
case 'h' :
printf ( L_59
L_239
L_240 ,
F_18 () ) ;
F_10 ( stdout ) ;
F_98 ( 0 ) ;
break;
case 'v' :
{
F_17 ( V_15 , V_16 ) ;
F_175 ( V_15 , TRUE ) ;
F_175 ( V_16 , TRUE ) ;
F_98 ( 0 ) ;
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
case V_376 :
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
V_67 = F_253 ( & V_208 , V_323 , V_377 , & V_340 ) ;
if ( V_67 != 0 ) {
F_98 ( V_67 ) ;
}
break;
case 'Z' :
V_20 = TRUE ;
#ifdef F_6
F_188 ( 2 , V_290 ) ;
if ( strcmp ( V_377 , V_378 ) != 0 ) {
V_379 = F_58 ( V_380 , V_377 ) ;
V_381 = F_143 ( F_144 ( V_379 ) ,
V_209 , 0 , NULL , V_210 , 0 , NULL ) ;
if ( V_381 == V_197 ) {
F_93 ( V_109 , V_110 ,
L_241 ,
V_379 ) ;
F_98 ( 1 ) ;
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
V_343 = TRUE ;
V_349 ++ ;
break;
case 'L' :
V_344 = TRUE ;
V_349 ++ ;
break;
#ifdef F_13
case 'd' :
V_345 = TRUE ;
V_349 ++ ;
break;
#endif
case 'S' :
V_348 = TRUE ;
V_349 ++ ;
break;
case 'k' :
V_346 = TRUE ;
V_347 = V_377 ;
V_349 ++ ;
break;
case 'M' :
V_97 = TRUE ;
break;
case 'C' :
V_318 = F_254 ( V_377 , L_242 ) ;
break;
case 'N' :
V_320 = F_254 ( V_377 , L_243 ) ;
break;
default:
F_29 ( L_244 , V_330 [ V_382 - 1 ] ) ;
case '?' :
V_335 = TRUE ;
break;
}
}
if ( ! V_335 ) {
V_329 -= V_382 ;
V_330 += V_382 ;
if ( V_329 >= 1 ) {
V_329 -- ;
V_330 ++ ;
}
if ( V_329 != 0 ) {
F_29 ( L_245 , V_330 [ 0 ] ) ;
V_335 = TRUE ;
}
}
if ( ( V_318 > 0 ) || ( V_320 > 0 ) ) {
V_246 = TRUE ;
}
if ( ( V_318 == 0 ) && ( V_320 == 0 ) ) {
V_318 = 1000 * 1000 ;
V_320 = 1000 ;
}
if ( V_335 ) {
F_10 ( V_22 ) ;
F_98 ( 1 ) ;
}
if ( V_349 > 1 ) {
F_29 ( L_246 ) ;
F_98 ( 1 ) ;
} else if ( V_349 == 1 ) {
if ( V_208 . V_254 ) {
F_29 ( L_247 ) ;
F_98 ( 1 ) ;
}
} else {
if ( V_208 . V_54 -> V_55 > 1 ) {
V_246 = TRUE ;
V_208 . V_253 = TRUE ;
}
if ( V_208 . V_259 &&
( ! V_208 . V_253 || V_208 . V_254 ) ) {
F_29 ( L_248 ) ;
F_98 ( 1 ) ;
}
if ( V_208 . V_254 ) {
if ( V_208 . V_262 == NULL ) {
F_29 ( L_249 ) ;
V_208 . V_254 = FALSE ;
}
if ( ! V_208 . V_383 && ! V_208 . V_384 ) {
F_29 ( L_250 ) ;
#if 0
global_capture_opts.multi_files_on = FALSE;
#endif
}
}
}
if ( V_343 ) {
T_23 * V_75 ;
int V_101 ;
T_8 * V_65 ;
V_75 = F_255 ( & V_101 , & V_65 , NULL ) ;
if ( V_75 == NULL ) {
if ( V_101 == 0 ) {
if ( ! V_97 ) {
F_29 ( L_119 ) ;
F_98 ( 2 ) ;
}
} else {
F_29 ( L_60 , V_65 ) ;
F_23 ( V_65 ) ;
F_98 ( 2 ) ;
}
}
if ( V_97 )
F_76 ( V_75 ) ;
else
F_256 ( V_75 ) ;
F_91 ( V_75 ) ;
F_98 ( 0 ) ;
}
if ( V_348 ) {
V_67 = F_84 ( V_97 ) ;
F_98 ( V_67 ) ;
}
if ( V_346 ) {
T_16 V_48 ;
if ( V_208 . V_54 -> V_55 != 1 ) {
F_29 ( L_251 ) ;
F_98 ( 2 ) ;
}
V_48 = F_43 ( V_208 . V_54 , T_16 , 0 ) ;
V_67 = F_212 ( V_48 . V_37 , V_347 ) ;
F_98 ( V_67 ) ;
}
V_67 = F_257 ( & V_208 , NULL ) ;
if ( V_67 != 0 ) {
F_98 ( V_67 ) ;
}
if ( V_20 ) {
for ( V_53 = 0 ; V_53 < V_208 . V_54 -> V_55 ; V_53 ++ ) {
T_16 V_48 ;
V_48 = F_43 ( V_208 . V_54 , T_16 , V_53 ) ;
F_93 ( V_109 , V_111 , L_252 ,
V_48 . V_37 ) ;
}
} else {
V_17 = F_170 ( L_61 ) ;
#ifdef F_6
if ( V_208 . V_54 -> V_55 < 2 )
#else
if ( V_208 . V_54 -> V_55 < 4 )
#endif
{
for ( V_53 = 0 ; V_53 < V_208 . V_54 -> V_55 ; V_53 ++ ) {
T_16 V_48 ;
V_48 = F_43 ( V_208 . V_54 , T_16 , V_53 ) ;
if ( V_53 > 0 ) {
if ( V_208 . V_54 -> V_55 > 2 ) {
F_225 ( V_17 , L_108 ) ;
}
F_225 ( V_17 , L_253 ) ;
if ( V_53 == V_208 . V_54 -> V_55 - 1 ) {
F_225 ( V_17 , L_254 ) ;
}
}
F_225 ( V_17 , L_255 , V_48 . V_298 ) ;
}
} else {
F_225 ( V_17 , L_256 , V_208 . V_54 -> V_55 ) ;
}
fprintf ( V_22 , L_257 , V_17 -> V_17 ) ;
F_175 ( V_17 , TRUE ) ;
}
if ( V_344 ) {
T_21 * V_23 ;
T_8 * V_65 ;
T_18 V_385 ;
for ( V_385 = 0 ; V_385 < V_208 . V_54 -> V_55 ; V_385 ++ ) {
T_16 V_48 ;
V_48 = F_43 ( V_208 . V_54 , T_16 , V_385 ) ;
V_23 = F_60 ( V_48 . V_37 ,
V_48 . T_22 , & V_65 ) ;
if ( V_23 == NULL ) {
F_29 ( L_258
L_259
L_260 , V_48 . V_37 , V_65 ) ;
F_23 ( V_65 ) ;
F_98 ( 2 ) ;
}
if ( V_23 -> V_74 == NULL ) {
F_29 ( L_261 , V_48 . V_37 ) ;
F_98 ( 2 ) ;
}
if ( V_97 )
F_83 ( V_23 ) ;
else
F_258 ( V_23 , V_48 . V_37 ,
V_48 . T_22 ) ;
F_259 ( V_23 ) ;
}
F_98 ( 0 ) ;
}
F_260 ( & V_208 , V_71 ) ;
#ifdef F_13
if ( V_345 ) {
F_42 ( & V_208 ) ;
F_98 ( 0 ) ;
}
#endif
F_261 ( & V_208 ) ;
fflush ( V_22 ) ;
if ( F_262 ( & V_208 , & V_341 , & V_267 ) == TRUE ) {
F_98 ( 0 ) ;
} else {
F_98 ( 1 ) ;
}
return 0 ;
}
static void
V_363 ( const char * V_386 , T_47 V_387 ,
const char * V_388 , T_41 T_48 V_2 )
{
T_49 V_389 ;
struct V_390 * V_391 ;
const char * V_392 ;
T_8 * V_21 ;
if ( ! ( V_387 & V_393 & ~ ( V_111 | V_110 ) ) ) {
#if ! F_12 ( F_100 ) && ! F_12 ( V_313 )
return;
#endif
}
time ( & V_389 ) ;
V_391 = localtime ( & V_389 ) ;
switch( V_387 & V_393 ) {
case V_357 :
V_392 = L_262 ;
break;
case V_358 :
V_392 = L_263 ;
break;
case V_359 :
V_392 = L_264 ;
break;
case V_360 :
V_392 = L_265 ;
break;
case V_110 :
V_392 = L_266 ;
break;
case V_111 :
V_392 = L_267 ;
break;
default:
fprintf ( V_22 , L_268 , V_387 ) ;
V_392 = NULL ;
F_263 () ;
}
if ( V_387 & V_360 ) {
V_21 = F_58 ( L_93 , V_388 ) ;
} else {
V_21 = F_58 ( L_269 ,
V_391 -> V_394 , V_391 -> V_395 , V_391 -> V_396 ,
V_386 != NULL ? V_386 : L_61 ,
V_392 , V_388 ) ;
}
#if F_12 ( F_100 ) || F_12 ( V_313 )
if ( ! ( V_387 & V_393 & ~ ( V_111 | V_110 ) ) ) {
#ifdef F_100
fprintf ( V_22 , L_60 , V_21 ) ;
fflush ( V_22 ) ;
#endif
#ifdef V_313
fprintf ( V_354 , L_60 , V_21 ) ;
fflush ( V_354 ) ;
#endif
F_23 ( V_21 ) ;
return;
}
#endif
if ( V_20 ) {
F_22 ( 2 , V_21 , L_61 ) ;
} else {
fprintf ( V_22 , L_60 , V_21 ) ;
fflush ( V_22 ) ;
}
F_23 ( V_21 ) ;
}
static void
F_199 ( unsigned int V_114 )
{
char V_397 [ V_398 + 1 + 1 ] ;
static unsigned int V_399 = 0 ;
if ( V_20 ) {
F_33 ( V_397 , sizeof( V_397 ) , L_270 , V_114 ) ;
F_93 ( V_109 , V_111 , L_271 , V_397 ) ;
F_51 ( 2 , V_400 , V_397 ) ;
} else {
V_399 += V_114 ;
fprintf ( V_22 , L_272 , V_399 ) ;
fflush ( V_22 ) ;
}
}
static void
F_200 ( const char * V_401 )
{
if ( V_20 ) {
F_93 ( V_109 , V_111 , L_273 , V_401 ) ;
F_51 ( 2 , V_402 , V_401 ) ;
} else {
#ifdef F_249
V_118 = TRUE ;
#endif
fprintf ( V_22 , L_274 , V_401 ) ;
fflush ( V_22 ) ;
#ifdef F_249
V_118 = FALSE ;
if ( V_116 )
F_96 () ;
#endif
}
}
static void
F_47 ( T_15 * V_47 , T_18 V_52 , const char * V_27 )
{
T_16 V_48 ;
char V_397 [ V_49 + 1 + 6 ] ;
if ( V_52 < V_47 -> V_54 -> V_55 ) {
if ( V_20 ) {
F_33 ( V_397 , sizeof( V_397 ) , L_275 , V_52 , V_27 ) ;
F_93 ( V_109 , V_111 , L_276 , V_27 ) ;
F_51 ( 2 , V_403 , V_397 ) ;
} else {
V_48 = F_43 ( V_47 -> V_54 , T_16 , V_52 ) ;
F_29 (
L_277
L_4
L_278
L_279 ,
V_48 . V_42 , V_48 . V_37 , V_27 ) ;
}
}
}
static void
F_45 ( const char * V_404 , const char * V_405 )
{
if ( V_20 ) {
F_93 ( V_109 , V_111 ,
L_280 , V_404 ) ;
F_93 ( V_109 , V_111 ,
L_281 , V_405 ) ;
F_22 ( 2 , V_404 , V_405 ) ;
} else {
F_29 ( L_60 , V_404 ) ;
if ( V_405 [ 0 ] != '\0' )
F_264 ( L_60 , V_405 ) ;
}
}
static void
F_265 ( V_8 V_268 , V_8 V_406 , V_8 V_407 , V_8 V_270 , V_8 V_408 , T_8 * V_37 )
{
char V_397 [ V_398 + 1 + 1 ] ;
V_8 V_409 = V_406 + V_407 + V_270 ;
F_33 ( V_397 , sizeof( V_397 ) , L_270 , V_409 ) ;
if ( V_20 ) {
F_93 ( V_109 , V_111 ,
L_282 ,
V_37 , V_268 , V_409 , V_406 , V_407 , V_270 , V_408 ) ;
F_51 ( 2 , V_410 , V_397 ) ;
} else {
fprintf ( V_22 ,
L_283 ,
V_37 , V_268 , V_409 , V_406 , V_407 , V_270 , V_408 ,
V_268 ? 100.0 * V_268 / ( V_268 + V_409 ) : 0.0 ) ;
fflush ( V_22 ) ;
}
}
static T_12
F_87 ( void )
{
T_29 V_411 = 0 ;
T_12 V_234 ;
if ( ! V_20 ) {
return TRUE ;
}
if ( ! V_379 || ! V_381 ) {
F_93 ( V_109 , V_110 ,
L_284 ) ;
return FALSE ;
}
V_234 = F_266 ( V_381 , NULL , 0 , NULL , & V_411 , NULL ) ;
if ( ! V_234 || V_411 > 0 ) {
F_93 ( V_109 , V_110 ,
L_285 , V_379 ) ;
F_93 ( V_109 , V_111 ,
L_286 , V_379 ,
V_381 , V_234 , V_411 ) ;
return FALSE ;
} else {
return TRUE ;
}
}
