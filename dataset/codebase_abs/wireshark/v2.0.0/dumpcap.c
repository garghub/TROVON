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
#ifdef F_12
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
F_17 ( const char * V_15 , T_6 V_16 )
{
if ( V_17 ) {
T_7 * V_18 ;
V_18 = F_18 ( V_15 , V_16 ) ;
F_19 ( 2 , V_18 , L_59 ) ;
F_20 ( V_18 ) ;
} else {
fprintf ( V_19 , L_60 ) ;
vfprintf ( V_19 , V_15 , V_16 ) ;
fprintf ( V_19 , L_4 ) ;
}
}
static void
F_21 ( const char * V_15 , T_6 V_16 )
{
if ( V_17 ) {
T_7 * V_18 ;
V_18 = F_18 ( V_15 , V_16 ) ;
F_19 ( 2 , V_18 , L_59 ) ;
F_20 ( V_18 ) ;
} else {
vfprintf ( V_19 , V_15 , V_16 ) ;
fprintf ( V_19 , L_4 ) ;
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
F_22 ( const char * T_8 V_2 ) {
#endif
}
static void
F_23 ( void )
{
T_9 V_20 = F_24 () ;
F_22 ( L_61 ) ;
if ( F_25 ( V_20 ) ) {
F_26 ( L_62 , F_27 ( V_21 ) ) ;
}
F_22 ( L_63 ) ;
F_28 ( V_20 ) ;
}
static void
F_29 ( const char * V_22 ,
const char * V_23 ,
char * V_24 , T_10 V_25 ,
char * V_26 ,
T_10 V_27 )
{
#ifndef F_6
const char * V_28 ;
static const char V_29 [] = L_64 ;
#endif
F_30 ( V_24 , ( V_30 ) V_25 ,
L_65 ,
V_23 , V_22 ) ;
#ifdef F_6
if ( ! V_31 ) {
F_30 ( V_26 , ( V_30 ) V_27 ,
L_4
L_66
L_4
L_67
L_4
L_68
L_69 ) ;
} else {
F_30 ( V_26 , ( V_30 ) V_27 ,
L_4
L_70
L_4
L_4
L_71
L_4
L_72
L_73 ,
V_23 ) ;
}
#else
if ( strncmp ( V_22 , V_29 , sizeof V_29 - 1 ) == 0 )
V_28 =
L_74
L_75
L_76
L_77
L_4
L_78
L_79
L_80
L_81
L_82 ;
else
V_28 = L_59 ;
F_30 ( V_26 , ( V_30 ) V_27 ,
L_83
L_84 , V_28 ) ;
#endif
}
static T_11
F_31 ( T_12 * V_32 , int V_33 , char * V_34 ,
char * V_24 , T_10 V_25 ,
char * V_26 , T_10 V_27 )
{
char * V_35 ;
if ( V_33 == - 1 )
return TRUE ;
#ifdef F_32
if ( F_33 ( V_32 , V_33 ) == 0 )
return TRUE ;
V_35 = F_34 ( V_32 ) ;
#else
if ( F_35 ( V_32 , V_34 ) == V_33 )
return TRUE ;
V_35 =
L_85 ;
#endif
F_30 ( V_24 , ( V_30 ) V_25 , L_86 ,
V_34 , V_35 ) ;
if ( strstr ( V_35 , L_87 ) == NULL )
F_30 ( V_26 , ( V_30 ) V_27 , V_36 ) ;
else
V_26 [ 0 ] = '\0' ;
return FALSE ;
}
static T_11
F_36 ( const char * V_23 , T_12 * V_32 ,
struct V_37 * V_38 , const char * V_39 )
{
T_13 V_40 , V_41 ;
T_7 V_42 [ V_43 ] ;
if ( F_37 ( V_23 , & V_40 , & V_41 , V_42 ) < 0 ) {
V_41 = 0 ;
}
F_38 (cast-qual)
if ( F_39 ( V_32 , V_38 , ( char * ) V_39 , 1 , V_41 ) < 0 )
return FALSE ;
F_40 (cast-qual)
return TRUE ;
}
static T_11
F_41 ( T_14 * V_44 )
{
T_15 V_45 ;
T_12 * V_32 ;
T_7 V_22 [ V_43 ] ;
char V_24 [ V_46 + 1 ] ;
char V_26 [ V_46 + 1 ] ;
struct V_37 V_38 ;
struct V_47 * V_48 ;
T_16 V_49 ;
T_17 V_50 ;
for ( V_50 = 0 ; V_50 < V_44 -> V_51 -> V_52 ; V_50 ++ ) {
V_45 = F_42 ( V_44 -> V_51 , T_15 , V_50 ) ;
V_32 = F_43 ( V_44 , & V_45 , & V_22 ) ;
if ( V_32 == NULL ) {
F_29 ( V_22 ,
V_45 . V_34 ,
V_24 , sizeof V_24 ,
V_26 ,
sizeof V_26 ) ;
F_44 ( V_24 , V_26 ) ;
return FALSE ;
}
if ( ! F_31 ( V_32 , V_45 . V_33 , V_45 . V_34 ,
V_24 , sizeof V_24 ,
V_26 , sizeof V_26 ) ) {
F_45 ( V_32 ) ;
F_44 ( V_24 , V_26 ) ;
return FALSE ;
}
if ( ! F_36 ( V_45 . V_34 , V_32 , & V_38 ,
V_45 . V_39 ) ) {
F_45 ( V_32 ) ;
F_46 ( V_44 , V_50 , V_24 ) ;
return FALSE ;
}
F_45 ( V_32 ) ;
V_48 = V_38 . V_53 ;
for ( V_49 = 0 ; V_49 < V_38 . V_54 ; V_48 ++ , V_49 ++ )
printf ( L_88 , F_47 ( V_48 , V_49 ) ) ;
}
#ifndef F_48
F_49 () ;
#else
F_23 () ;
#endif
if ( V_17 ) {
F_50 ( 2 , V_55 , NULL ) ;
}
return TRUE ;
}
static int
F_35 ( T_12 * V_56 , const char * T_18
#ifndef F_51
V_2
#endif
)
{
int V_33 ;
#ifdef F_51
const char * V_57 ;
#endif
V_33 = F_52 ( V_56 ) ;
#ifdef F_51
V_57 = strchr ( T_18 , '/' ) ;
if ( V_57 == NULL )
V_57 = T_18 ;
if ( strncmp ( V_57 , L_89 , 2 ) == 0 ) {
if ( V_33 == 6 ) {
V_33 = 1 ;
}
} else if ( strncmp ( V_57 , L_90 , 2 ) == 0 ) {
if ( V_33 == 7 ) {
V_33 = 1 ;
}
} else if ( strncmp ( V_57 , L_91 , 2 ) == 0 ) {
if ( V_33 == 9 ) {
V_33 = 6 ;
}
} else if ( strncmp ( V_57 , L_92 , 2 ) == 0 ) {
if ( V_33 == 15 ) {
V_33 = 10 ;
}
} else if ( strncmp ( V_57 , L_93 , 2 ) == 0 ) {
if ( V_33 == 24 ) {
V_33 = 0 ;
}
}
#endif
return V_33 ;
}
static T_19 *
F_53 ( int V_58 )
{
T_19 * V_59 ;
const char * V_60 ;
V_59 = ( T_19 * ) F_54 ( sizeof ( T_19 ) ) ;
V_59 -> V_58 = V_58 ;
V_60 = F_55 ( V_58 ) ;
if ( V_60 != NULL )
V_59 -> V_34 = F_56 ( V_60 ) ;
else
V_59 -> V_34 = F_57 ( L_94 , V_58 ) ;
V_60 = F_58 ( V_58 ) ;
if ( V_60 != NULL )
V_59 -> V_61 = F_56 ( V_60 ) ;
else
V_59 -> V_61 = NULL ;
return V_59 ;
}
static T_11
F_59 ( const char * V_62 )
{
int V_1 ;
struct V_63 V_64 ;
T_20 V_65 ;
V_1 = F_60 ( V_66 , V_67 , 0 ) ;
if ( V_1 == - 1 )
return FALSE ;
memset ( & V_64 , 0 , sizeof V_64 ) ;
F_61 ( V_64 . V_68 , V_62 , sizeof V_64 . V_68 ) ;
memset ( & V_65 , 0 , sizeof V_65 ) ;
V_64 . V_69 = ( V_70 ) & V_65 ;
#if F_62 ( V_71 )
if ( F_63 ( V_1 , V_71 , & V_64 ) == 0 ) {
F_4 ( V_1 ) ;
return TRUE ;
}
#else
if ( F_63 ( V_1 , V_72 , & V_64 ) == 0 ) {
F_4 ( V_1 ) ;
return TRUE ;
}
#endif
F_4 ( V_1 ) ;
return FALSE ;
}
static T_11
F_59 ( const char * V_62 V_2 )
{
return FALSE ;
}
static T_21 *
F_64 ( T_15 * V_45 , char * * V_73 )
{
T_21 * V_20 ;
char V_74 [ V_43 ] ;
T_12 * V_56 ;
#ifdef F_11
int V_75 ;
#endif
int V_76 ;
#ifdef F_65
int * V_77 ;
int V_49 , V_78 ;
#endif
T_19 * V_59 ;
V_20 = ( T_21 * ) F_54 ( sizeof *V_20 ) ;
V_74 [ 0 ] = '\0' ;
#ifdef F_66
#ifdef F_14
if ( strncmp ( V_45 -> V_34 , L_95 , 8 ) == 0 ) {
struct V_79 V_80 ;
V_80 . type = V_45 -> V_81 == V_82 ?
V_83 : V_84 ;
V_80 . V_85 = V_45 -> V_86 ;
V_80 . V_87 = V_45 -> V_88 ;
V_56 = F_67 ( V_45 -> V_34 , V_89 , 0 , 0 , & V_80 , V_74 ) ;
} else
#endif
V_56 = F_67 ( V_45 -> V_34 , V_89 , 0 , 0 , NULL , V_74 ) ;
V_20 -> V_90 = FALSE ;
if ( V_56 == NULL ) {
if ( V_73 != NULL )
* V_73 = F_56 ( V_74 [ 0 ] == '\0' ? L_96 : V_74 ) ;
F_20 ( V_20 ) ;
return NULL ;
}
#elif F_62 ( F_11 )
V_56 = F_68 ( V_45 -> V_34 , V_74 ) ;
if ( V_56 == NULL ) {
if ( V_73 != NULL )
* V_73 = F_56 ( V_74 ) ;
F_20 ( V_20 ) ;
return NULL ;
}
if ( F_59 ( V_45 -> V_34 ) ) {
V_75 = 0 ;
} else {
V_75 = F_69 ( V_56 ) ;
}
if ( V_75 < 0 ) {
if ( V_75 == V_91 )
* V_73 = F_57 ( L_97 ,
F_34 ( V_56 ) ) ;
else
* V_73 = F_56 ( F_70 ( V_75 ) ) ;
F_45 ( V_56 ) ;
F_20 ( V_20 ) ;
return NULL ;
}
if ( V_75 == 0 )
V_20 -> V_90 = FALSE ;
else if ( V_75 == 1 ) {
V_20 -> V_90 = TRUE ;
if ( V_45 -> V_92 )
F_71 ( V_56 , 1 ) ;
} else {
if ( V_73 != NULL ) {
* V_73 = F_57 ( L_98 ,
V_75 ) ;
}
F_45 ( V_56 ) ;
F_20 ( V_20 ) ;
return NULL ;
}
V_75 = F_72 ( V_56 ) ;
if ( V_75 < 0 ) {
if ( V_73 != NULL ) {
if ( V_75 == V_91 )
* V_73 = F_57 ( L_99 ,
F_34 ( V_56 ) ) ;
else
* V_73 = F_56 ( F_70 ( V_75 ) ) ;
}
F_45 ( V_56 ) ;
F_20 ( V_20 ) ;
return NULL ;
}
#else
V_56 = F_73 ( V_45 -> V_34 , V_89 , 0 , 0 , V_74 ) ;
V_20 -> V_90 = FALSE ;
if ( V_56 == NULL ) {
if ( V_73 != NULL )
* V_73 = F_56 ( V_74 [ 0 ] == '\0' ? L_96 : V_74 ) ;
F_20 ( V_20 ) ;
return NULL ;
}
#endif
V_76 = F_35 ( V_56 , V_45 -> V_34 ) ;
#ifdef F_65
V_78 = F_74 ( V_56 , & V_77 ) ;
if ( V_78 == 0 || V_77 == NULL ) {
F_45 ( V_56 ) ;
if ( V_73 != NULL )
* V_73 = NULL ;
F_20 ( V_20 ) ;
return NULL ;
}
V_20 -> V_93 = NULL ;
for ( V_49 = 0 ; V_49 < V_78 ; V_49 ++ ) {
V_59 = F_53 ( V_77 [ V_49 ] ) ;
if ( V_77 [ V_49 ] == V_76 )
V_20 -> V_93 = F_75 ( V_20 -> V_93 ,
V_59 ) ;
else
V_20 -> V_93 = F_76 ( V_20 -> V_93 ,
V_59 ) ;
}
#ifdef F_77
F_78 ( V_77 ) ;
#else
#ifndef F_6
#define F_79 free
F_79 ( V_77 ) ;
#endif
#endif
#else
V_59 = F_53 ( V_76 ) ;
V_20 -> V_93 = F_76 ( V_20 -> V_93 ,
V_59 ) ;
#endif
F_45 ( V_56 ) ;
if ( V_73 != NULL )
* V_73 = NULL ;
return V_20 ;
}
static void
F_80 ( T_22 * V_94 )
{
int V_49 ;
T_22 * V_95 ;
T_23 * V_96 ;
T_24 * V_97 ;
T_25 * V_98 ;
char V_99 [ V_100 ] ;
if ( V_17 ) {
F_50 ( 2 , V_55 , NULL ) ;
}
V_49 = 1 ;
for ( V_95 = F_81 ( V_94 ) ; V_95 != NULL ;
V_95 = F_82 ( V_95 ) ) {
V_96 = ( T_23 * ) V_95 -> V_101 ;
printf ( L_100 , V_49 ++ , V_96 -> V_34 ) ;
if ( V_96 -> V_102 != NULL )
printf ( L_101 , V_96 -> V_102 ) ;
else
printf ( L_102 ) ;
if ( V_96 -> V_103 != NULL )
printf ( L_101 , V_96 -> V_103 ) ;
else
printf ( L_102 ) ;
printf ( L_103 , V_96 -> type ) ;
for ( V_97 = F_83 ( V_96 -> V_104 , 0 ) ; V_97 != NULL ;
V_97 = F_84 ( V_97 ) ) {
if ( V_97 != F_83 ( V_96 -> V_104 , 0 ) )
printf ( L_104 ) ;
V_98 = ( T_25 * ) V_97 -> V_101 ;
switch( V_98 -> V_105 ) {
case V_106 :
if ( F_85 ( V_107 , & V_98 -> V_97 . V_108 , V_99 ,
V_100 ) ) {
printf ( L_105 , V_99 ) ;
} else {
printf ( L_106 ) ;
}
break;
case V_109 :
if ( F_85 ( V_110 , & V_98 -> V_97 . V_111 ,
V_99 , V_100 ) ) {
printf ( L_105 , V_99 ) ;
} else {
printf ( L_107 ) ;
}
break;
default:
printf ( L_108 , V_98 -> V_105 ) ;
}
}
if ( V_96 -> V_112 )
printf ( L_109 ) ;
else
printf ( L_110 ) ;
#ifdef F_86
printf ( L_111 , V_96 -> V_113 ) ;
#endif
printf ( L_4 ) ;
}
}
static void
F_87 ( T_21 * V_20 )
{
T_22 * V_114 ;
T_19 * V_59 ;
const T_7 * V_115 ;
if ( V_17 ) {
F_50 ( 2 , V_55 , NULL ) ;
}
if ( V_20 -> V_90 )
printf ( L_112 ) ;
else
printf ( L_113 ) ;
for ( V_114 = V_20 -> V_93 ; V_114 != NULL ;
V_114 = F_82 ( V_114 ) ) {
V_59 = ( T_19 * ) V_114 -> V_101 ;
if ( V_59 -> V_61 != NULL )
V_115 = V_59 -> V_61 ;
else
V_115 = L_114 ;
printf ( L_115 , V_59 -> V_58 , V_59 -> V_34 ,
V_115 ) ;
}
}
static int
F_88 ( T_11 V_116 )
{
T_22 * V_94 , * V_95 , * V_117 = NULL , * V_118 ;
T_23 * V_96 ;
T_26 * V_119 ;
int V_120 ;
T_7 * V_73 ;
T_12 * V_56 ;
char V_74 [ V_43 ] ;
struct V_121 V_122 ;
V_94 = F_89 ( & V_120 , & V_73 ) ;
if ( V_94 == NULL ) {
if ( V_120 == 0 )
F_26 ( L_116 ) ;
else {
F_26 ( L_105 , V_73 ) ;
F_20 ( V_73 ) ;
}
return V_120 ;
}
for ( V_95 = F_81 ( V_94 ) ; V_95 != NULL ; V_95 = F_82 ( V_95 ) ) {
V_96 = ( T_23 * ) V_95 -> V_101 ;
#ifdef F_16
if ( ! strncmp ( V_96 -> V_34 , L_117 , 2 ) ) {
F_90 ( V_123 , V_124 , L_118 ,
V_96 -> V_34 ) ;
continue;
}
#endif
#ifdef F_66
V_56 = F_67 ( V_96 -> V_34 , V_89 , 0 , 0 , NULL , V_74 ) ;
#else
V_56 = F_73 ( V_96 -> V_34 , V_89 , 0 , 0 , V_74 ) ;
#endif
if ( V_56 ) {
V_119 = ( T_26 * ) F_54 ( sizeof( T_26 ) ) ;
V_119 -> V_34 = F_56 ( V_96 -> V_34 ) ;
V_119 -> V_56 = V_56 ;
V_117 = F_76 ( V_117 , V_119 ) ;
}
}
if ( ! V_117 ) {
F_26 ( L_116 ) ;
return 2 ;
}
if ( V_17 ) {
F_50 ( 2 , V_55 , NULL ) ;
}
if ( ! V_116 ) {
printf ( L_119 , L_120 , L_121 ,
L_122 ) ;
}
V_125 . V_126 = TRUE ;
while ( V_125 . V_126 ) {
for ( V_118 = F_81 ( V_117 ) ; V_118 != NULL ; V_118 = F_82 ( V_118 ) ) {
V_119 = ( T_26 * ) V_118 -> V_101 ;
F_91 ( V_119 -> V_56 , & V_122 ) ;
if ( ! V_116 ) {
printf ( L_123 , V_119 -> V_34 ,
V_122 . V_127 , V_122 . V_128 ) ;
} else {
printf ( L_124 , V_119 -> V_34 ,
V_122 . V_127 , V_122 . V_128 ) ;
fflush ( stdout ) ;
}
}
#ifdef F_6
if ( ! F_92 () ) {
V_125 . V_126 = FALSE ;
}
F_93 ( 1 * 1000 ) ;
#else
F_94 ( 1 ) ;
#endif
}
for ( V_118 = F_81 ( V_117 ) ; V_118 != NULL ; V_118 = F_82 ( V_118 ) ) {
V_119 = ( T_26 * ) V_118 -> V_101 ;
F_45 ( V_119 -> V_56 ) ;
F_20 ( V_119 -> V_34 ) ;
F_20 ( V_119 ) ;
}
F_95 ( V_117 ) ;
F_96 ( V_94 ) ;
return 0 ;
}
static BOOL T_27
F_97 ( T_28 V_129 )
{
F_90 ( V_123 , V_130 ,
L_125 ) ;
F_90 ( V_123 , V_124 ,
L_126 , V_129 ) ;
if ( V_17 || ( V_129 != V_131 ) ) {
F_98 () ;
return TRUE ;
} else {
return FALSE ;
}
}
static void
F_97 ( int T_29 V_2 )
{
F_98 () ;
}
static void
F_99 ( T_11 V_132 )
{
if ( ! V_17 && V_132 ) {
fprintf ( V_19 , L_127 , V_125 . V_133 ) ;
fflush ( V_19 ) ;
}
}
static void
F_100 ( void )
{
F_99 ( V_134 ) ;
V_135 = FALSE ;
}
static void
F_101 ( int T_29 V_2 )
{
int V_136 = V_21 ;
if ( V_137 )
V_135 = TRUE ;
else
F_100 () ;
V_21 = V_136 ;
}
static void
F_102 ( int V_75 )
{
#ifdef F_6
F_103 () ;
#ifdef F_104
printf ( L_128 ) ;
F_105 () ;
#endif
#endif
exit ( V_75 ) ;
}
static void
F_106 ( void )
{
if ( F_107 () ) {
T_30 V_138 [ 2 ] = { V_139 , V_140 } ;
int V_141 = sizeof( V_138 ) / sizeof( T_30 ) ;
T_9 V_20 = F_24 () ;
F_22 ( L_129 ) ;
if ( F_108 ( V_142 , 1 , 0 , 0 , 0 ) == - 1 ) {
F_26 ( L_130 , F_27 ( V_21 ) ) ;
}
F_109 ( V_20 , V_143 , V_141 , V_138 , V_144 ) ;
F_109 ( V_20 , V_145 , V_141 , V_138 , V_144 ) ;
if ( F_25 ( V_20 ) ) {
F_26 ( L_62 , F_27 ( V_21 ) ) ;
}
F_22 ( L_131 ) ;
F_49 () ;
F_22 ( L_132 ) ;
F_109 ( V_20 , V_146 , V_141 , V_138 , V_144 ) ;
if ( F_25 ( V_20 ) ) {
F_26 ( L_62 , F_27 ( V_21 ) ) ;
}
F_22 ( L_133 ) ;
F_28 ( V_20 ) ;
}
}
static void
F_110 ( T_11 V_147 , struct V_148 * V_149 , struct V_150 * V_151 )
{
if ( V_147 ) {
V_151 -> V_152 = F_111 ( V_151 -> V_152 ) ;
V_151 -> V_153 = F_111 ( V_151 -> V_153 ) ;
V_151 -> V_154 = F_111 ( V_151 -> V_154 ) ;
V_151 -> V_155 = F_111 ( V_151 -> V_155 ) ;
}
if ( V_149 -> V_156 == 2 &&
( V_149 -> V_157 < 3 ||
( V_149 -> V_157 == 3 && V_151 -> V_154 > V_151 -> V_155 ) ) ) {
V_8 V_158 ;
V_158 = V_151 -> V_155 ;
V_151 -> V_155 = V_151 -> V_154 ;
V_151 -> V_154 = V_158 ;
}
}
static T_1
F_112 ( int V_159 , char * V_160 , T_10 V_161 , T_11 T_31 V_2 )
{
#ifdef F_6
if ( T_31 ) {
return F_113 ( V_159 , V_160 , ( int ) V_161 , 0 ) ;
} else {
return - 1 ;
}
#else
return F_114 ( V_159 , V_160 , V_161 ) ;
#endif
}
static void * F_115 ( void * V_162 )
{
T_32 * V_163 ;
#ifdef F_6
BOOL V_164 ;
T_28 V_165 , V_166 , V_167 ;
#else
T_10 V_167 ;
int V_165 ;
#endif
V_163 = ( T_32 * ) V_162 ;
while ( V_163 -> V_168 == V_169 ) {
F_116 ( V_163 -> V_170 ) ;
F_117 ( V_163 -> V_171 ) ;
V_167 = 0 ;
while ( V_167 < V_163 -> V_172 ) {
if ( ( V_163 -> V_173 )
#ifndef F_6
|| 1
#endif
)
{
V_165 = F_112 ( V_163 -> V_174 , V_163 -> V_175 + V_167 ,
V_163 -> V_172 - V_167 , V_163 -> V_173 ) ;
if ( V_165 <= 0 ) {
if ( V_165 == 0 ) {
V_163 -> V_168 = V_176 ;
V_167 = 0 ;
break;
} else {
V_163 -> V_168 = V_177 ;
V_167 = - 1 ;
break;
}
} else {
V_167 += V_165 ;
}
}
#ifdef F_6
else
{
V_164 = F_118 ( V_163 -> V_178 , V_163 -> V_175 + V_167 ,
V_163 -> V_172 - V_167 ,
& V_165 , NULL ) ;
V_167 += V_165 ;
if ( ! V_164 ) {
V_166 = F_119 () ;
if ( V_166 == V_179 ) {
continue;
} else if ( V_166 == V_180 || V_166 == V_181 || V_166 == V_182 ) {
V_163 -> V_168 = V_176 ;
V_167 = 0 ;
break;
}
V_163 -> V_168 = V_177 ;
V_167 = - 1 ;
break;
} else if ( V_165 == 0 && V_163 -> V_172 > 0 ) {
V_163 -> V_168 = V_176 ;
V_167 = 0 ;
break;
}
}
#endif
}
V_163 -> V_183 = V_167 ;
if ( V_163 -> V_183 >= V_163 -> V_172 ) {
F_120 ( V_163 -> V_184 , V_163 -> V_175 ) ;
}
F_121 ( V_163 -> V_171 ) ;
}
return NULL ;
}
static int
F_122 ( int V_159 )
{
T_33 V_185 ;
struct V_7 V_186 ;
F_123 ( & V_185 ) ;
F_124 ( V_159 , & V_185 ) ;
V_186 . V_11 = V_187 / 1000000 ;
V_186 . V_12 = V_187 % 1000000 ;
return F_125 ( V_159 + 1 , & V_185 , NULL , NULL , & V_186 ) ;
}
static int
F_126 ( char * V_188 , T_32 * V_163 , char * V_24 , int V_189 )
{
char * V_190 = V_188 + 4 ;
struct V_191 V_192 ;
char V_160 [ 16 ] ;
char * V_193 ;
unsigned long V_194 ;
T_10 V_52 ;
int V_1 ;
memset ( & V_192 , 0 , sizeof( V_192 ) ) ;
V_193 = strchr ( V_190 , ':' ) ;
if ( V_193 == NULL ) {
V_52 = strlen ( V_190 ) ;
V_194 = V_195 ;
}
else {
V_52 = V_193 - V_190 ;
V_194 = strtoul ( V_193 + 1 , & V_193 , 10 ) ;
if ( * V_193 || V_194 > 65535 ) {
goto V_196;
}
}
if ( V_52 > 15 ) {
goto V_196;
}
F_30 ( V_160 , ( V_30 ) V_52 + 1 , L_105 , V_190 ) ;
V_160 [ V_52 ] = '\0' ;
if ( F_127 ( V_107 , V_160 , & V_192 . V_197 ) <= 0 ) {
goto V_196;
}
V_192 . V_198 = V_107 ;
V_192 . V_199 = F_128 ( ( V_200 ) V_194 ) ;
if ( ( ( V_1 = ( int ) F_60 ( V_107 , V_201 , 0 ) ) < 0 ) ||
( F_129 ( V_1 , (struct V_202 * ) & V_192 , sizeof( V_192 ) ) < 0 ) ) {
#ifdef F_6
T_34 V_203 = NULL ;
int V_204 ;
V_204 = F_130 () ;
F_131 ( V_205 |
V_206 |
V_207 ,
NULL , V_204 , F_132 ( V_208 , V_209 ) ,
( T_34 ) & V_203 , 0 , NULL ) ;
#endif
F_30 ( V_24 , V_189 ,
L_134
#ifdef F_6
L_135 , V_204 , V_203 ? ( char * ) V_203 : L_136 ) ;
if ( V_203 )
F_133 ( V_203 ) ;
#else
L_137 , V_21 , F_27 ( V_21 ) ) ;
#endif
V_163 -> V_168 = V_177 ;
if ( V_1 >= 0 )
F_134 ( V_1 , TRUE ) ;
return - 1 ;
}
void
F_134 ( int V_159 , T_11 T_31 V_2 )
{
#ifdef F_6
if ( T_31 ) {
F_135 ( V_159 ) ;
}
#else
F_136 ( V_159 ) ;
#endif
}
static void
F_137 ( char * V_188 ,
T_32 * V_163 ,
struct V_148 * V_149 ,
char * V_24 , int V_189 )
{
#ifndef F_6
T_35 V_210 ;
struct V_211 V_192 ;
#else
char * V_212 , * V_213 ;
T_36 * V_73 ;
T_15 V_45 ;
#ifdef F_86
char * V_214 ;
T_11 V_215 ;
#endif
#endif
T_1 V_165 ;
int V_1 = - 1 , V_216 ;
T_10 V_167 ;
V_8 V_217 = 0 ;
V_163 -> V_174 = - 1 ;
#ifdef F_6
V_163 -> V_178 = V_218 ;
#endif
F_90 ( V_123 , V_124 , L_138 , V_188 ) ;
if ( strcmp ( V_188 , L_139 ) == 0 ) {
#ifndef F_6
V_1 = 0 ;
#else
V_163 -> V_178 = F_138 ( V_219 ) ;
#endif
} else if ( ! strncmp ( V_188 , L_140 , 4 ) ) {
if ( ( V_1 = F_126 ( V_188 , V_163 , V_24 , V_189 ) ) < 0 ) {
return;
}
} else {
#ifndef F_6
if ( F_139 ( V_188 , & V_210 ) < 0 ) {
if ( V_21 == V_220 || V_21 == V_221 )
V_163 -> V_168 = V_222 ;
else {
F_30 ( V_24 , V_189 ,
L_141
L_142 , F_27 ( V_21 ) ) ;
V_163 -> V_168 = V_177 ;
}
return;
}
if ( F_140 ( V_210 . V_223 ) ) {
V_1 = F_2 ( V_188 , V_224 | V_225 , 0000 ) ;
if ( V_1 == - 1 ) {
F_30 ( V_24 , V_189 ,
L_141
L_143 , F_27 ( V_21 ) ) ;
V_163 -> V_168 = V_177 ;
return;
}
} else if ( F_141 ( V_210 . V_223 ) ) {
V_1 = F_60 ( V_226 , V_201 , 0 ) ;
if ( V_1 == - 1 ) {
F_30 ( V_24 , V_189 ,
L_141
L_144 , F_27 ( V_21 ) ) ;
V_163 -> V_168 = V_177 ;
return;
}
V_192 . V_227 = V_226 ;
if ( F_61 ( V_192 . V_228 , V_188 , sizeof V_192 . V_228 ) > sizeof V_192 . V_228 ) {
F_30 ( V_24 , V_189 ,
L_145
L_146 ) ;
V_163 -> V_168 = V_177 ;
F_136 ( V_1 ) ;
return;
}
V_165 = F_129 ( V_1 , (struct V_202 * ) & V_192 , sizeof V_192 ) ;
if ( V_165 == - 1 ) {
F_30 ( V_24 , V_189 ,
L_145
L_147 , F_27 ( V_21 ) ) ;
V_163 -> V_168 = V_177 ;
F_136 ( V_1 ) ;
return;
}
} else {
if ( F_142 ( V_210 . V_223 ) ) {
V_163 -> V_168 = V_222 ;
} else {
F_30 ( V_24 , V_189 ,
L_148
L_149 , V_188 ) ;
V_163 -> V_168 = V_177 ;
}
return;
}
#else
#define F_143 "\\pipe\\"
V_212 = F_56 ( V_188 ) ;
if ( ( V_213 = strstr ( V_212 , L_150 ) ) == V_212 ) {
V_213 = strchr ( V_212 + 3 , '\\' ) ;
if ( V_213 && F_144 ( V_213 , F_143 , strlen ( F_143 ) ) != 0 )
V_213 = NULL ;
}
F_20 ( V_212 ) ;
if ( ! V_213 ) {
F_30 ( V_24 , V_189 ,
L_148
L_151 , V_188 ) ;
V_163 -> V_168 = V_222 ;
return;
}
V_45 = F_42 ( V_229 . V_51 , T_15 , 0 ) ;
#ifdef F_86
V_214 = F_145 ( L_152 , V_230 , NULL ) ;
V_215 = strstr ( V_45 . V_34 , V_214 ) ? TRUE : FALSE ;
F_20 ( V_214 ) ;
#endif
while ( 1 ) {
#ifdef F_86
if( V_215 )
V_163 -> V_178 = F_138 ( V_219 ) ;
else
#endif
V_163 -> V_178 = F_146 ( F_147 ( V_188 ) , V_231 , 0 , NULL ,
V_232 , 0 , NULL ) ;
if ( V_163 -> V_178 != V_218 )
break;
if ( F_119 () != V_233 ) {
F_131 ( V_205 | V_206 | V_207 ,
NULL , F_119 () , 0 , ( T_34 ) & V_73 , 0 , NULL ) ;
F_30 ( V_24 , V_189 ,
L_153
L_154 ,
V_188 , F_148 ( V_73 ) , F_119 () ) ;
F_133 ( V_73 ) ;
V_163 -> V_168 = V_177 ;
return;
}
if ( ! F_149 ( F_147 ( V_188 ) , 30 * 1000 ) ) {
F_131 ( V_205 | V_206 | V_207 ,
NULL , F_119 () , 0 , ( T_34 ) & V_73 , 0 , NULL ) ;
F_30 ( V_24 , V_189 ,
L_155
L_156 ,
V_188 , F_148 ( V_73 ) , F_119 () ) ;
F_133 ( V_73 ) ;
V_163 -> V_168 = V_177 ;
return;
}
}
#endif
}
V_163 -> V_234 = TRUE ;
#ifdef F_6
if ( V_163 -> V_173 )
#endif
{
V_167 = 0 ;
while ( V_167 < sizeof V_217 ) {
if ( V_1 == - 1 ) {
F_30 ( V_24 , V_189 , L_157 ) ;
goto error;
}
V_216 = F_122 ( V_1 ) ;
if ( V_216 < 0 ) {
F_30 ( V_24 , V_189 ,
L_158 , F_27 ( V_21 ) ) ;
goto error;
} else if ( V_216 > 0 ) {
V_165 = F_112 ( V_1 , ( ( char * ) & V_217 ) + V_167 ,
sizeof V_217 - V_167 ,
V_163 -> V_173 ) ;
if ( V_165 <= 0 ) {
if ( V_165 == 0 )
F_30 ( V_24 , V_189 , L_159 ) ;
else
F_30 ( V_24 , V_189 , L_160 ,
F_27 ( V_21 ) ) ;
goto error;
}
V_167 += V_165 ;
}
}
}
#ifdef F_6
else {
#if F_150 ( 2 , 31 , 0 )
F_151 ( L_161 , & F_115 , V_163 ) ;
#else
F_152 ( & F_115 , V_163 , FALSE , NULL ) ;
#endif
V_163 -> V_175 = ( char * ) & V_217 ;
V_163 -> V_183 = 0 ;
V_163 -> V_172 = sizeof( V_217 ) ;
F_120 ( V_163 -> V_170 , V_163 -> V_175 ) ;
F_116 ( V_163 -> V_184 ) ;
if ( V_163 -> V_183 <= 0 ) {
if ( V_163 -> V_183 == 0 )
F_30 ( V_24 , V_189 , L_159 ) ;
else
F_30 ( V_24 , V_189 , L_160 ,
F_27 ( V_21 ) ) ;
goto error;
}
}
#endif
switch ( V_217 ) {
case V_235 :
case V_236 :
V_163 -> V_237 = FALSE ;
V_163 -> V_238 = FALSE ;
V_163 -> V_239 = V_217 == V_236 ;
break;
case V_240 :
V_163 -> V_237 = FALSE ;
V_163 -> V_238 = TRUE ;
break;
case V_241 :
case V_242 :
V_163 -> V_237 = TRUE ;
V_163 -> V_238 = FALSE ;
V_163 -> V_239 = V_217 == V_242 ;
break;
case V_243 :
V_163 -> V_237 = TRUE ;
V_163 -> V_238 = TRUE ;
break;
default:
F_30 ( V_24 , V_189 , L_162 ) ;
goto error;
}
#ifdef F_6
if ( V_163 -> V_173 )
#endif
{
V_167 = 0 ;
while ( V_167 < sizeof( struct V_148 ) ) {
V_216 = F_122 ( V_1 ) ;
if ( V_216 < 0 ) {
F_30 ( V_24 , V_189 ,
L_158 , F_27 ( V_21 ) ) ;
goto error;
} else if ( V_216 > 0 ) {
V_165 = F_112 ( V_1 , ( ( char * ) V_149 ) + V_167 ,
sizeof( struct V_148 ) - V_167 ,
V_163 -> V_173 ) ;
if ( V_165 <= 0 ) {
if ( V_165 == 0 )
F_30 ( V_24 , V_189 , L_163 ) ;
else
F_30 ( V_24 , V_189 , L_164 ,
F_27 ( V_21 ) ) ;
goto error;
}
V_167 += V_165 ;
}
}
}
#ifdef F_6
else {
V_163 -> V_175 = ( char * ) V_149 ;
V_163 -> V_183 = 0 ;
V_163 -> V_172 = sizeof( struct V_148 ) ;
F_120 ( V_163 -> V_170 , V_163 -> V_175 ) ;
F_116 ( V_163 -> V_184 ) ;
if ( V_163 -> V_183 <= 0 ) {
if ( V_163 -> V_183 == 0 )
F_30 ( V_24 , V_189 , L_163 ) ;
else
F_30 ( V_24 , V_189 , L_165 ,
F_27 ( V_21 ) ) ;
goto error;
}
}
#endif
if ( V_163 -> V_237 ) {
V_149 -> V_156 = F_153 ( V_149 -> V_156 ) ;
V_149 -> V_157 = F_153 ( V_149 -> V_157 ) ;
V_149 -> V_244 = F_111 ( V_149 -> V_244 ) ;
V_149 -> V_245 = F_111 ( V_149 -> V_245 ) ;
}
V_163 -> V_33 = V_149 -> V_245 ;
if ( V_149 -> V_156 < 2 ) {
F_30 ( V_24 , V_189 , L_166 ) ;
goto error;
}
V_163 -> V_246 = V_247 ;
V_163 -> V_168 = V_169 ;
V_163 -> V_174 = V_1 ;
return;
error:
F_90 ( V_123 , V_124 , L_167 , V_24 ) ;
V_163 -> V_168 = V_177 ;
F_134 ( V_1 , V_163 -> V_173 ) ;
V_163 -> V_174 = - 1 ;
}
static int
F_154 ( T_37 * V_248 , T_32 * V_163 , T_38 * V_101 , char * V_24 , int V_189 )
{
struct V_249 V_250 ;
enum { V_251 , V_252 , V_253 , V_254 ,
V_255 } V_256 ;
#ifdef F_6
#if ! F_150 ( 2 , 31 , 18 )
T_39 V_257 ;
#endif
T_40 V_258 ;
T_36 * V_73 ;
#endif
T_1 V_165 ;
#ifdef F_155
F_90 ( V_123 , V_124 , L_168 ) ;
#endif
switch ( V_163 -> V_246 ) {
case V_247 :
#ifdef F_6
if ( F_156 ( V_163 -> V_171 ) ) {
#endif
V_163 -> V_246 = V_259 ;
V_163 -> V_172 = V_163 -> V_238 ?
sizeof( struct V_260 ) : sizeof( struct V_150 ) ;
V_163 -> V_183 = 0 ;
#ifdef F_6
V_163 -> V_175 = ( char * ) & V_163 -> V_261 ;
F_120 ( V_163 -> V_170 , V_163 -> V_175 ) ;
F_121 ( V_163 -> V_171 ) ;
}
#endif
case V_259 :
#ifdef F_6
if ( V_163 -> V_173 )
#endif
{
V_165 = F_112 ( V_163 -> V_174 , ( ( char * ) & V_163 -> V_261 ) + V_163 -> V_183 ,
V_163 -> V_172 - V_163 -> V_183 , V_163 -> V_173 ) ;
if ( V_165 <= 0 ) {
if ( V_165 == 0 )
V_256 = V_253 ;
else
V_256 = V_254 ;
break;
}
V_163 -> V_183 += V_165 ;
}
#ifdef F_6
else {
#if F_150 ( 2 , 31 , 18 )
V_258 = F_157 ( V_163 -> V_184 , V_187 ) ;
#else
F_158 ( & V_257 ) ;
F_159 ( & V_257 , V_187 ) ;
V_258 = F_160 ( V_163 -> V_184 , & V_257 ) ;
#endif
if ( V_163 -> V_168 == V_176 ) {
V_256 = V_253 ;
break;
} else if ( V_163 -> V_168 == V_177 ) {
V_256 = V_254 ;
break;
}
if ( ! V_258 ) {
return 0 ;
}
}
#endif
if ( V_163 -> V_183 < V_163 -> V_172 )
return 0 ;
V_256 = V_251 ;
break;
case V_262 :
#ifdef F_6
if ( F_156 ( V_163 -> V_171 ) ) {
#endif
V_163 -> V_246 = V_263 ;
V_163 -> V_172 = V_163 -> V_261 . V_149 . V_154 ;
V_163 -> V_183 = 0 ;
#ifdef F_6
V_163 -> V_175 = ( char * ) V_101 ;
F_120 ( V_163 -> V_170 , V_163 -> V_175 ) ;
F_121 ( V_163 -> V_171 ) ;
}
#endif
case V_263 :
#ifdef F_6
if ( V_163 -> V_173 )
#endif
{
V_165 = F_112 ( V_163 -> V_174 ,
V_101 + V_163 -> V_183 ,
V_163 -> V_172 - V_163 -> V_183 ,
V_163 -> V_173 ) ;
if ( V_165 <= 0 ) {
if ( V_165 == 0 )
V_256 = V_253 ;
else
V_256 = V_254 ;
break;
}
V_163 -> V_183 += V_165 ;
}
#ifdef F_6
else {
#if F_150 ( 2 , 31 , 18 )
V_258 = F_157 ( V_163 -> V_184 , V_187 ) ;
#else
F_158 ( & V_257 ) ;
F_159 ( & V_257 , V_187 ) ;
V_258 = F_160 ( V_163 -> V_184 , & V_257 ) ;
#endif
if ( V_163 -> V_168 == V_176 ) {
V_256 = V_253 ;
break;
} else if ( V_163 -> V_168 == V_177 ) {
V_256 = V_254 ;
break;
}
if ( ! V_258 ) {
return 0 ;
}
}
#endif
if ( V_163 -> V_183 < V_163 -> V_172 )
return 0 ;
V_256 = V_252 ;
break;
default:
F_30 ( V_24 , V_189 , L_169 ) ;
V_256 = V_255 ;
}
switch ( V_256 ) {
case V_251 :
F_110 ( V_163 -> V_237 , & V_163 -> V_264 ,
& V_163 -> V_261 . V_149 ) ;
if ( V_163 -> V_261 . V_149 . V_154 > V_265 ) {
F_30 ( V_24 , V_189 , L_170 ,
V_248 -> V_133 + 1 , V_163 -> V_261 . V_149 . V_154 ) ;
break;
}
if ( V_163 -> V_261 . V_149 . V_154 ) {
V_163 -> V_246 = V_262 ;
return 0 ;
}
case V_252 :
V_250 . V_266 . V_11 = V_163 -> V_261 . V_149 . V_152 ;
V_250 . V_266 . V_12 = V_163 -> V_261 . V_149 . V_153 ;
V_250 . V_267 = V_163 -> V_261 . V_149 . V_154 ;
V_250 . V_52 = V_163 -> V_261 . V_149 . V_155 ;
if ( V_268 ) {
F_161 ( ( V_269 * ) V_163 , & V_250 , V_101 ) ;
} else {
F_162 ( ( V_269 * ) V_163 , & V_250 , V_101 ) ;
}
V_163 -> V_246 = V_247 ;
return 1 ;
case V_253 :
V_163 -> V_168 = V_176 ;
return - 1 ;
case V_254 :
#ifdef F_6
F_131 ( V_205 | V_206 | V_207 ,
NULL , F_119 () , 0 , ( T_34 ) & V_73 , 0 , NULL ) ;
F_30 ( V_24 , V_189 ,
L_171 ,
F_148 ( V_73 ) , F_119 () ) ;
F_133 ( V_73 ) ;
#else
F_30 ( V_24 , V_189 , L_172 ,
F_27 ( V_21 ) ) ;
#endif
case V_255 :
break;
}
V_163 -> V_168 = V_177 ;
return - 1 ;
}
static void F_163 ( T_37 * V_248 )
{
T_17 V_49 ;
T_32 * V_163 ;
F_90 ( V_123 , V_124 , L_173 ) ;
for ( V_49 = 0 ; V_49 < V_248 -> V_270 -> V_52 ; V_49 ++ ) {
V_163 = F_42 ( V_248 -> V_270 , T_32 * , V_49 ) ;
if ( V_163 -> V_174 >= 0 ) {
F_164 ( V_163 -> V_234 ) ;
F_134 ( V_163 -> V_174 , V_163 -> V_173 ) ;
V_163 -> V_174 = - 1 ;
}
#ifdef F_6
if ( V_163 -> V_178 != V_218 ) {
F_165 ( V_163 -> V_178 ) ;
V_163 -> V_178 = V_218 ;
}
#endif
if ( V_163 -> V_32 != NULL ) {
F_90 ( V_123 , V_124 , L_174 , ( void * ) V_163 -> V_32 ) ;
F_45 ( V_163 -> V_32 ) ;
V_163 -> V_32 = NULL ;
}
}
V_248 -> V_126 = FALSE ;
#ifdef F_6
F_103 () ;
#endif
}
static T_41
F_166 ( T_12 * V_32 , T_11 V_234 ,
const T_7 * V_34 , const T_7 * V_39 )
{
struct V_37 V_38 ;
F_90 ( V_123 , V_124 , L_175 , V_39 ) ;
if ( V_39 && ! V_234 ) {
if ( ! F_36 ( V_34 , V_32 , & V_38 , V_39 ) ) {
return V_271 ;
}
if ( F_167 ( V_32 , & V_38 ) < 0 ) {
#ifdef F_168
F_169 ( & V_38 ) ;
#endif
return V_272 ;
}
#ifdef F_168
F_169 ( & V_38 ) ;
#endif
}
return V_273 ;
}
static T_11
F_170 ( T_14 * V_44 , T_37 * V_248 , char * V_24 , int V_25 )
{
int V_120 ;
T_17 V_49 ;
T_32 * V_163 ;
T_15 V_45 ;
T_11 V_274 ;
F_90 ( V_123 , V_124 , L_176 ) ;
if ( ( V_44 -> V_275 == FALSE ) &&
( V_44 -> V_51 -> V_52 > 1 ) ) {
F_30 ( V_24 , V_25 ,
L_177 ) ;
return FALSE ;
}
if ( V_44 -> V_276 ) {
V_248 -> V_277 = F_171 ( & V_120 ) ;
} else {
V_248 -> V_277 = F_172 ( V_248 -> V_278 , L_178 ) ;
if ( V_248 -> V_277 == NULL ) {
V_120 = V_21 ;
}
}
if ( V_248 -> V_277 ) {
if ( V_44 -> V_275 ) {
char * V_279 ;
T_42 * V_280 ;
V_280 = F_173 ( L_59 ) ;
F_174 ( V_280 ) ;
V_279 = F_57 ( L_179 , F_175 () ) ;
V_274 = F_176 ( V_248 -> V_277 ,
( const char * ) V_44 -> V_281 ,
NULL ,
V_280 -> V_282 ,
V_279 ,
- 1 ,
& V_248 -> V_283 ,
& V_120 ) ;
F_20 ( V_279 ) ;
for ( V_49 = 0 ; V_274 && ( V_49 < V_44 -> V_51 -> V_52 ) ; V_49 ++ ) {
V_45 = F_42 ( V_44 -> V_51 , T_15 , V_49 ) ;
V_163 = F_42 ( V_248 -> V_270 , T_32 * , V_49 ) ;
if ( V_163 -> V_234 ) {
V_163 -> V_244 = V_163 -> V_264 . V_244 ;
} else {
V_163 -> V_244 = F_177 ( V_163 -> V_32 ) ;
}
V_274 = F_178 ( V_125 . V_277 ,
NULL ,
V_45 . V_34 ,
V_45 . V_284 ,
V_45 . V_39 ,
V_280 -> V_282 ,
V_163 -> V_33 ,
V_163 -> V_244 ,
& ( V_125 . V_283 ) ,
0 ,
V_163 -> V_239 ? 9 : 6 ,
& V_125 . V_120 ) ;
}
F_179 ( V_280 , TRUE ) ;
} else {
V_163 = F_42 ( V_248 -> V_270 , T_32 * , 0 ) ;
if ( V_163 -> V_234 ) {
V_163 -> V_244 = V_163 -> V_264 . V_244 ;
} else {
V_163 -> V_244 = F_177 ( V_163 -> V_32 ) ;
}
V_274 = F_180 ( V_248 -> V_277 , V_163 -> V_33 , V_163 -> V_244 ,
V_163 -> V_239 , & V_248 -> V_283 , & V_120 ) ;
}
if ( ! V_274 ) {
fclose ( V_248 -> V_277 ) ;
V_248 -> V_277 = NULL ;
}
}
if ( V_248 -> V_277 == NULL ) {
switch ( V_120 ) {
default:
if ( V_120 < 0 ) {
F_30 ( V_24 , V_25 ,
L_180
L_181 ,
V_44 -> V_285 , V_120 ) ;
} else {
F_30 ( V_24 , V_25 ,
L_180
L_182 ,
V_44 -> V_285 , F_27 ( V_120 ) ) ;
}
break;
}
return FALSE ;
}
return TRUE ;
}
static T_11
F_181 ( T_14 * V_44 , T_37 * V_248 , int * V_286 )
{
unsigned int V_49 ;
T_32 * V_163 ;
T_3 V_287 = F_5 () ;
F_90 ( V_123 , V_124 , L_183 ) ;
if ( V_44 -> V_276 ) {
return F_182 ( & V_44 -> V_285 , V_286 ) ;
} else {
if ( V_44 -> V_275 ) {
for ( V_49 = 0 ; V_49 < V_125 . V_270 -> V_52 ; V_49 ++ ) {
V_163 = F_42 ( V_125 . V_270 , T_32 * , V_49 ) ;
if ( ! V_163 -> V_234 ) {
T_3 V_288 , V_289 ;
struct V_121 V_290 ;
if ( F_91 ( V_163 -> V_32 , & V_290 ) >= 0 ) {
V_288 = V_163 -> V_291 ;
V_289 = V_290 . V_128 + V_163 -> V_292 + V_163 -> V_293 ;
} else {
V_288 = V_294 ;
V_289 = V_294 ;
}
F_183 ( V_248 -> V_277 ,
V_49 ,
& V_248 -> V_283 ,
L_184 ,
V_295 ,
V_287 ,
V_288 ,
V_289 ,
V_286 ) ;
}
}
}
if ( fclose ( V_248 -> V_277 ) == V_296 ) {
if ( V_286 != NULL ) {
* V_286 = V_21 ;
}
return ( FALSE ) ;
} else {
return ( TRUE ) ;
}
}
}
static int
F_184 ( T_37 * V_248 ,
char * V_24 , int V_25 , T_32 * V_163 )
{
int V_297 ;
T_43 V_298 ;
T_38 V_299 [ V_265 ] ;
#ifndef F_6
int V_216 ;
#endif
V_298 = V_248 -> V_133 ;
if ( V_163 -> V_234 ) {
#ifdef F_155
F_90 ( V_123 , V_124 , L_185 ) ;
#endif
#ifndef F_6
V_216 = F_122 ( V_163 -> V_174 ) ;
if ( V_216 <= 0 ) {
if ( V_216 < 0 && V_21 != V_300 ) {
F_30 ( V_24 , V_25 ,
L_158 , F_27 ( V_21 ) ) ;
F_44 ( V_24 , V_36 ) ;
V_248 -> V_126 = FALSE ;
}
} else {
#endif
V_297 = F_154 ( V_248 , V_163 , V_299 , V_24 , V_25 ) ;
if ( V_297 < 0 ) {
V_248 -> V_126 = FALSE ;
}
#ifndef F_6
}
#endif
}
else
{
#ifdef F_185
#ifdef F_155
F_90 ( V_123 , V_124 , L_186 ) ;
#endif
if ( V_163 -> V_301 != - 1 ) {
V_216 = F_122 ( V_163 -> V_301 ) ;
if ( V_216 > 0 ) {
if ( V_268 ) {
V_297 = F_186 ( V_163 -> V_32 , 1 , F_161 , ( V_269 * ) V_163 ) ;
} else {
V_297 = F_186 ( V_163 -> V_32 , 1 , F_162 , ( V_269 * ) V_163 ) ;
}
if ( V_297 < 0 ) {
if ( V_297 == - 1 ) {
V_163 -> V_302 = TRUE ;
}
V_248 -> V_126 = FALSE ;
}
} else {
if ( V_216 < 0 && V_21 != V_300 ) {
F_30 ( V_24 , V_25 ,
L_158 , F_27 ( V_21 ) ) ;
F_44 ( V_24 , V_36 ) ;
V_248 -> V_126 = FALSE ;
}
}
}
else
#endif
{
#if 1
#ifdef F_155
F_90 ( V_123 , V_124 , L_187 ) ;
#endif
#ifdef F_6
if ( V_268 ) {
V_297 = F_186 ( V_163 -> V_32 , 1 , F_161 , ( V_269 * ) V_163 ) ;
} else {
V_297 = F_186 ( V_163 -> V_32 , 1 , F_162 , ( V_269 * ) V_163 ) ;
}
#else
if ( V_268 ) {
V_297 = F_186 ( V_163 -> V_32 , - 1 , F_161 , ( V_269 * ) V_163 ) ;
} else {
V_297 = F_186 ( V_163 -> V_32 , - 1 , F_162 , ( V_269 * ) V_163 ) ;
}
#endif
if ( V_297 < 0 ) {
if ( V_297 == - 1 ) {
V_163 -> V_302 = TRUE ;
}
V_248 -> V_126 = FALSE ;
}
#else
#ifdef F_155
F_90 ( V_123 , V_124 , L_188 ) ;
#endif
{
int V_303 ;
struct V_249 * V_304 ;
V_269 * V_305 ;
V_303 = 0 ;
while( V_248 -> V_126 &&
( V_303 = F_187 ( V_163 -> V_32 , & V_304 , & V_305 ) ) == 1 ) {
if ( V_268 ) {
F_161 ( ( V_269 * ) V_163 , V_304 , V_305 ) ;
} else {
F_162 ( ( V_269 * ) V_163 , V_304 , V_305 ) ;
}
}
if ( V_303 < 0 ) {
V_163 -> V_302 = TRUE ;
V_248 -> V_126 = FALSE ;
}
}
#endif
}
}
#ifdef F_155
F_90 ( V_123 , V_124 , L_189 , V_297 , F_188 ( V_297 , L_59 , L_190 ) ) ;
#endif
return V_248 -> V_133 - V_298 ;
}
static T_42 *
F_189 ( const char * V_23 )
{
T_7 * V_306 ;
T_42 * V_307 ;
V_306 = strchr ( V_23 , '{' ) ;
if ( V_306 == NULL )
return F_173 ( V_23 ) ;
V_307 = F_173 ( V_306 + 1 ) ;
V_306 = strchr ( V_307 -> V_282 , '}' ) ;
if ( V_306 == NULL )
return V_307 ;
V_307 = F_190 ( V_307 , V_306 - V_307 -> V_282 ) ;
return V_307 ;
}
static T_11
F_191 ( T_14 * V_44 , int * V_278 ,
char * V_24 , int V_25 )
{
char * V_308 ;
T_7 * V_309 ;
T_7 * V_310 ;
T_11 V_311 ;
F_90 ( V_123 , V_124 , L_191 ,
( V_44 -> V_285 ) ? V_44 -> V_285 : L_192 ) ;
if ( V_44 -> V_285 != NULL ) {
V_309 = F_56 ( V_44 -> V_285 ) ;
if ( V_44 -> V_312 == TRUE ) {
if ( V_44 -> V_276 ) {
F_30 ( V_24 , V_25 ,
L_193 ) ;
F_20 ( V_309 ) ;
return FALSE ;
}
if ( strcmp ( V_309 , L_139 ) == 0 ) {
* V_278 = 1 ;
#ifdef F_6
F_192 ( 1 , V_313 ) ;
#endif
}
}
else {
if ( V_44 -> V_276 ) {
* V_278 = F_193 ( V_309 ,
( V_44 -> V_314 ) ? V_44 -> V_315 : 0 ,
V_44 -> V_316 ) ;
if ( * V_278 != - 1 ) {
F_20 ( V_309 ) ;
V_309 = F_56 ( F_194 () ) ;
}
} else {
* V_278 = F_2 ( V_309 , V_317 | V_313 | V_318 | V_319 ,
( V_44 -> V_316 ) ? 0640 : 0600 ) ;
}
}
V_311 = FALSE ;
} else {
if ( V_229 . V_51 -> V_52 > 1 ) {
V_310 = F_57 ( L_194 , V_229 . V_51 -> V_52 ) ;
} else {
T_7 * V_320 ;
V_320 = F_195 ( F_42 ( V_229 . V_51 , T_15 , 0 ) . V_321 ) ;
#ifdef F_6
if ( strncmp ( L_195 , V_320 , 5 ) == 0 )
{
T_42 * V_23 ;
V_23 = F_189 ( V_320 ) ;
F_20 ( V_320 ) ;
V_320 = F_56 ( V_23 -> V_282 ) ;
F_179 ( V_23 , TRUE ) ;
}
#endif
if ( V_44 -> V_275 ) {
V_310 = F_145 ( L_196 , V_320 , NULL ) ;
} else{
V_310 = F_145 ( L_197 , V_320 , NULL ) ;
}
F_20 ( V_320 ) ;
}
* V_278 = F_196 ( & V_308 , V_310 ) ;
F_20 ( V_310 ) ;
V_309 = F_56 ( V_308 ) ;
V_311 = TRUE ;
}
if ( * V_278 == - 1 ) {
if ( V_311 ) {
F_30 ( V_24 , V_25 ,
L_198
L_199 , V_309 , F_27 ( V_21 ) ) ;
} else {
if ( V_44 -> V_276 ) {
F_197 () ;
}
F_30 ( V_24 , V_25 ,
L_200
L_199 , V_309 ,
F_27 ( V_21 ) ) ;
}
F_20 ( V_309 ) ;
return FALSE ;
}
if ( V_44 -> V_285 != NULL ) {
F_20 ( V_44 -> V_285 ) ;
}
V_44 -> V_285 = V_309 ;
return TRUE ;
}
static T_11
F_198 ( T_14 * V_44 ,
T_44 * V_322 ,
T_44 * V_323 ,
T_44 * V_324 )
{
T_17 V_49 ;
T_32 * V_163 ;
T_15 V_45 ;
T_11 V_274 ;
if ( V_44 -> V_276 ) {
if ( V_322 != NULL &&
F_199 ( V_322 , ( T_3 ) ++ V_125 . V_325 ) ) {
V_125 . V_126 = FALSE ;
return FALSE ;
}
if ( F_200 ( & V_125 . V_277 , & V_44 -> V_285 ,
& V_125 . V_278 , & V_125 . V_120 ) ) {
V_125 . V_283 = 0 ;
if ( V_44 -> V_275 ) {
char * V_279 ;
T_42 * V_280 ;
V_280 = F_173 ( L_59 ) ;
F_174 ( V_280 ) ;
V_279 = F_57 ( L_179 , F_175 () ) ;
V_274 = F_176 ( V_125 . V_277 ,
NULL ,
NULL ,
V_280 -> V_282 ,
V_279 ,
- 1 ,
& ( V_125 . V_283 ) ,
& V_125 . V_120 ) ;
F_20 ( V_279 ) ;
for ( V_49 = 0 ; V_274 && ( V_49 < V_44 -> V_51 -> V_52 ) ; V_49 ++ ) {
V_45 = F_42 ( V_44 -> V_51 , T_15 , V_49 ) ;
V_163 = F_42 ( V_125 . V_270 , T_32 * , V_49 ) ;
V_274 = F_178 ( V_125 . V_277 ,
NULL ,
V_45 . V_34 ,
V_45 . V_284 ,
V_45 . V_39 ,
V_280 -> V_282 ,
V_163 -> V_33 ,
V_163 -> V_244 ,
& ( V_125 . V_283 ) ,
0 ,
V_163 -> V_239 ? 9 : 6 ,
& V_125 . V_120 ) ;
}
F_179 ( V_280 , TRUE ) ;
} else {
V_163 = F_42 ( V_125 . V_270 , T_32 * , 0 ) ;
V_274 = F_180 ( V_125 . V_277 , V_163 -> V_33 , V_163 -> V_244 ,
V_163 -> V_239 , & V_125 . V_283 , & V_125 . V_120 ) ;
}
if ( ! V_274 ) {
fclose ( V_125 . V_277 ) ;
V_125 . V_277 = NULL ;
V_125 . V_126 = FALSE ;
return FALSE ;
}
if ( V_323 )
F_201 ( V_323 ) ;
if ( V_324 )
F_201 ( V_324 ) ;
fflush ( V_125 . V_277 ) ;
if ( ! V_134 )
F_202 ( V_125 . V_326 ) ;
V_125 . V_326 = 0 ;
F_203 ( V_44 -> V_285 ) ;
} else {
V_125 . V_126 = FALSE ;
return FALSE ;
}
} else {
V_125 . V_126 = FALSE ;
return FALSE ;
}
return TRUE ;
}
static void *
F_204 ( void * V_162 )
{
T_32 * V_163 ;
char V_24 [ V_46 + 1 ] ;
V_163 = ( T_32 * ) V_162 ;
F_90 ( V_123 , V_130 , L_201 ,
V_163 -> V_327 ) ;
while ( V_125 . V_126 ) {
F_184 ( & V_125 , V_24 , sizeof( V_24 ) , V_163 ) ;
}
F_90 ( V_123 , V_130 , L_202 ,
V_163 -> V_327 ) ;
F_205 ( NULL ) ;
return ( NULL ) ;
}
static void
F_98 ( void )
{
#ifdef F_206
T_17 V_49 ;
T_32 * V_163 ;
for ( V_49 = 0 ; V_49 < V_125 . V_270 -> V_52 ; V_49 ++ ) {
V_163 = F_42 ( V_125 . V_270 , T_32 * , V_49 ) ;
if ( V_163 -> V_32 != NULL )
F_207 ( V_163 -> V_32 ) ;
}
#endif
V_125 . V_126 = FALSE ;
}
static void
F_208 ( char * V_24 , int V_328 , const char * V_329 ,
int V_120 , T_11 V_330 )
{
switch ( V_120 ) {
case V_331 :
F_30 ( V_24 , V_328 ,
L_203
L_204
L_205
L_206 ,
V_329 ) ;
break;
#ifdef F_209
case F_209 :
F_30 ( V_24 , V_328 ,
L_203
L_204
L_207
L_208
L_209 ,
V_329 ) ;
break;
#endif
default:
if ( V_330 ) {
F_30 ( V_24 , V_328 ,
L_210
L_211 ,
V_329 , F_27 ( V_120 ) ) ;
} else {
F_30 ( V_24 , V_328 ,
L_212
L_204
L_213 ,
V_329 , F_27 ( V_120 ) ) ;
}
break;
}
}
static void
F_162 ( V_269 * V_332 , const struct V_249 * V_250 ,
const V_269 * V_333 )
{
T_32 * V_163 = ( T_32 * ) ( void * ) V_332 ;
int V_120 ;
T_17 V_334 = V_163 -> V_239 ? 1000000000 : 1000000 ;
if ( ! V_125 . V_126 ) {
V_163 -> V_293 ++ ;
return;
}
if ( V_125 . V_277 ) {
T_11 V_274 ;
if ( V_229 . V_275 ) {
V_274 = F_210 ( V_125 . V_277 ,
NULL ,
V_250 -> V_266 . V_11 , ( V_335 ) V_250 -> V_266 . V_12 ,
V_250 -> V_267 , V_250 -> V_52 ,
V_163 -> V_327 ,
V_334 ,
V_333 , 0 ,
& V_125 . V_283 , & V_120 ) ;
} else {
V_274 = F_211 ( V_125 . V_277 ,
V_250 -> V_266 . V_11 , ( V_335 ) V_250 -> V_266 . V_12 ,
V_250 -> V_267 , V_250 -> V_52 ,
V_333 ,
& V_125 . V_283 , & V_120 ) ;
}
if ( ! V_274 ) {
V_125 . V_126 = FALSE ;
V_125 . V_120 = V_120 ;
V_163 -> V_292 ++ ;
} else {
#if F_62 ( F_104 ) || F_62 ( V_336 )
F_90 ( V_123 , V_130 ,
L_214 ,
V_250 -> V_267 , V_163 -> V_327 ) ;
#endif
V_125 . V_133 ++ ;
V_163 -> V_291 ++ ;
if ( ( V_125 . V_337 > 0 ) && ( V_125 . V_133 >= V_125 . V_337 ) ) {
V_125 . V_126 = FALSE ;
}
}
}
}
static void
F_161 ( V_269 * V_332 , const struct V_249 * V_250 ,
const V_269 * V_333 )
{
T_32 * V_163 = ( T_32 * ) ( void * ) V_332 ;
T_45 * V_338 ;
T_11 V_339 ;
if ( ! V_125 . V_126 ) {
V_163 -> V_293 ++ ;
return;
}
V_338 = ( T_45 * ) F_54 ( sizeof( T_45 ) ) ;
if ( V_338 == NULL ) {
V_163 -> V_292 ++ ;
return;
}
V_338 -> V_163 = V_163 ;
V_338 -> V_250 = * V_250 ;
V_338 -> V_333 = ( V_269 * ) F_54 ( V_250 -> V_267 ) ;
if ( V_338 -> V_333 == NULL ) {
V_163 -> V_292 ++ ;
F_20 ( V_338 ) ;
return;
}
memcpy ( V_338 -> V_333 , V_333 , V_250 -> V_267 ) ;
F_212 ( V_340 ) ;
if ( ( ( V_341 == 0 ) || ( V_342 < V_341 ) ) &&
( ( V_343 == 0 ) || ( V_344 < V_343 ) ) ) {
V_339 = FALSE ;
F_213 ( V_340 , V_338 ) ;
V_342 += V_250 -> V_267 ;
V_344 += 1 ;
} else {
V_339 = TRUE ;
}
F_214 ( V_340 ) ;
if ( V_339 ) {
V_163 -> V_292 ++ ;
F_20 ( V_338 -> V_333 ) ;
F_20 ( V_338 ) ;
F_90 ( V_123 , V_130 ,
L_215 ,
V_250 -> V_267 , V_163 -> V_327 ) ;
} else {
V_163 -> V_291 ++ ;
F_90 ( V_123 , V_130 ,
L_216 ,
V_250 -> V_267 , V_163 -> V_327 ) ;
}
F_90 ( V_123 , V_130 ,
L_217 V_345 L_218 V_345 L_219 ,
V_342 , V_344 ) ;
}
static int
F_215 ( const char * V_23 , const char * V_346 )
{
int V_347 = 0 , type , V_348 ;
T_7 * * V_349 = NULL ;
V_349 = F_216 ( V_346 , L_104 , 2 ) ;
if ( V_349 [ 0 ] )
V_347 = atoi ( V_349 [ 0 ] ) ;
if ( V_349 [ 1 ] ) {
type = F_217 ( V_349 [ 1 ] ) ;
if ( type == - 1 ) {
V_348 = V_350 ;
goto V_351;
}
}
else
type = - 1 ;
V_348 = F_218 () ;
if ( V_348 ) {
F_26 ( L_220 , abs ( V_348 ) , F_27 ( abs ( V_348 ) ) ) ;
V_348 = 2 ;
goto V_351;
}
V_348 = F_219 ( V_23 , V_347 , type ) ;
if ( V_348 ) {
F_26 ( L_221 , abs ( V_348 ) , F_27 ( abs ( V_348 ) ) ) ;
V_348 = 2 ;
goto V_351;
}
if ( V_17 )
F_50 ( 2 , V_55 , NULL ) ;
V_348 = 0 ;
V_351:
F_220 ( V_349 ) ;
return V_348 ;
}
static void
F_221 ( T_42 * V_282 )
{
F_222 ( V_282 , L_222 ) ;
F_223 ( V_282 ) ;
F_222 ( V_282 , L_222 ) ;
#ifdef F_224
F_222 ( V_282 , L_223 ) ;
#ifdef F_225
F_222 ( V_282 , F_225 ) ;
#else
F_222 ( V_282 , L_224 ) ;
#endif
#else
F_222 ( V_282 , L_225 ) ;
#endif
}
static void
F_226 ( T_42 * V_282 )
{
F_222 ( V_282 , L_222 ) ;
F_227 ( V_282 ) ;
#if F_62 ( F_224 ) && ! F_62 ( F_6 )
F_228 ( V_282 , L_226 , F_229 () ) ;
#endif
}
int
main ( int V_352 , char * V_353 [] )
{
T_42 * V_354 ;
T_42 * V_355 ;
int V_346 ;
F_38 (cast-qual)
static const struct V_356 V_357 [] = {
{ ( char * ) L_227 , V_358 , NULL , 'h' } ,
{ ( char * ) L_228 , V_358 , NULL , 'v' } ,
V_359
{ 0 , 0 , 0 , 0 }
} ;
F_40 (cast-qual)
T_11 V_360 = FALSE ;
#ifdef F_6
T_46 V_361 ;
#else
struct V_362 V_363 , V_364 ;
#endif
T_11 V_365 = TRUE ;
T_11 V_366 ;
struct V_121 V_290 ;
T_47 V_367 ;
T_11 V_368 = FALSE ;
T_11 V_369 = FALSE ;
#ifdef F_13
T_11 V_370 = FALSE ;
#endif
T_11 V_371 = FALSE ;
T_7 * V_372 = NULL ;
T_11 V_116 = FALSE ;
T_11 V_373 = FALSE ;
int V_75 , V_374 = 0 ;
T_43 V_49 ;
T_17 V_50 ;
#if F_62 ( V_375 ) && F_62 ( V_376 )
struct V_377 V_378 ;
#endif
T_42 * V_282 ;
F_230 ( F_17 , F_21 ) ;
V_354 = F_231 ( NULL , F_221 ) ;
V_355 = F_232 ( F_226 ) ;
F_233 ( L_229
L_4
L_105
L_4
L_105 ,
F_175 () , V_354 -> V_282 , V_355 -> V_282 ) ;
#ifdef F_6
F_234 ( V_352 , V_353 ) ;
F_235 () ;
F_236 () ;
#endif
#ifdef F_13
#define F_237 "d"
#else
#define F_237 ""
#endif
#ifdef F_14
#define F_238 "r"
#define F_239 "u"
#else
#define F_238 ""
#define F_239 ""
#endif
#ifdef F_15
#define F_240 "m:"
#else
#define F_240 ""
#endif
#define F_241 OPTSTRING_CAPTURE_COMMON "C:" OPTSTRING_d "gh" "k:" OPTSTRING_m "MN:nPq" OPTSTRING_r "St" OPTSTRING_u "vw:Z:"
#ifdef V_336
if ( ( V_379 = F_242 ( L_230 , L_231 ) ) == NULL ) {
fprintf ( V_19 , L_232 ) ;
exit ( 1 ) ;
}
#endif
#if F_62 ( V_375 ) && F_62 ( V_376 )
if ( F_243 ( & V_378 ) == 0 ) {
if ( strcmp ( V_378 . V_380 , L_233 ) == 0 ||
strcmp ( V_378 . V_380 , L_234 ) == 0 ||
strcmp ( V_378 . V_380 , L_235 ) == 0 )
V_381 = TRUE ;
}
#endif
for ( V_49 = 1 ; V_49 < V_352 ; V_49 ++ ) {
if ( strcmp ( L_236 , V_353 [ V_49 ] ) == 0 ) {
V_17 = TRUE ;
V_116 = TRUE ;
#ifdef F_6
F_192 ( 2 , V_313 ) ;
#endif
}
}
V_367 =
( T_47 ) (
V_382 |
V_383 |
V_384 |
V_385 |
V_130 |
V_124 |
V_386 |
V_387 ) ;
F_244 ( NULL ,
V_367 ,
V_388 , NULL ) ;
F_244 ( V_389 ,
V_367 ,
V_388 , NULL ) ;
F_244 ( V_390 ,
V_367 ,
V_388 , NULL ) ;
F_244 ( V_123 ,
V_367 ,
V_388 , NULL ) ;
V_125 . V_270 = F_245 ( FALSE , FALSE , sizeof( T_32 * ) ) ;
#if ! F_150 ( 2 , 31 , 0 )
F_246 ( NULL ) ;
#endif
#ifdef F_6
F_247 () ;
F_248 ( F_249 ( 1 , 1 ) , & V_361 ) ;
F_250 ( F_97 , TRUE ) ;
#else
memset ( & V_363 , 0 , sizeof( V_363 ) ) ;
V_363 . V_391 = F_97 ;
V_363 . V_392 = 0 ;
F_251 ( & V_363 . V_393 ) ;
V_362 ( V_394 , & V_363 , NULL ) ;
V_362 ( V_395 , & V_363 , NULL ) ;
V_362 ( V_396 , & V_363 , NULL ) ;
V_362 ( V_397 , NULL , & V_364 ) ;
if ( V_364 . V_391 == V_398 )
V_362 ( V_397 , & V_363 , NULL ) ;
#ifdef F_252
V_363 . V_391 = F_101 ;
V_363 . V_392 = V_399 ;
F_251 ( & V_363 . V_393 ) ;
V_362 ( F_252 , & V_363 , NULL ) ;
#endif
#endif
#ifdef F_16
F_1 () ;
#endif
F_253 () ;
#ifdef F_48
F_106 () ;
#endif
F_254 ( & V_229 ) ;
V_229 . V_400 = TRUE ;
V_229 . V_314 = TRUE ;
V_229 . V_17 = V_17 ;
while ( ( V_346 = F_255 ( V_352 , V_353 , F_241 , V_357 , NULL ) ) != - 1 ) {
switch ( V_346 ) {
case 'h' :
printf ( L_229
L_237
L_238 ,
F_175 () ) ;
F_10 ( stdout ) ;
F_102 ( 0 ) ;
break;
case 'v' :
{
F_256 ( L_239 , V_354 , V_355 ) ;
F_179 ( V_354 , TRUE ) ;
F_179 ( V_355 , TRUE ) ;
F_102 ( 0 ) ;
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
case V_401 :
#ifdef F_14
case 'u' :
case 'r' :
case 'A' :
#endif
#ifdef F_15
case 'm' :
#endif
#ifdef F_12
case 'B' :
#endif
#ifdef F_11
case 'I' :
#endif
V_75 = F_257 ( & V_229 , V_346 , V_402 , & V_365 ) ;
if ( V_75 != 0 ) {
F_102 ( V_75 ) ;
}
break;
case 'Z' :
V_17 = TRUE ;
#ifdef F_6
F_192 ( 2 , V_313 ) ;
if ( strcmp ( V_402 , V_403 ) != 0 ) {
V_404 = F_57 ( V_405 , V_402 ) ;
V_406 = F_146 ( F_147 ( V_404 ) ,
V_231 , 0 , NULL , V_232 , 0 , NULL ) ;
if ( V_406 == V_218 ) {
F_90 ( V_123 , V_130 ,
L_240 ,
V_404 ) ;
F_102 ( 1 ) ;
}
}
#endif
break;
case 'q' :
V_134 = TRUE ;
break;
case 't' :
V_268 = TRUE ;
break;
case 'D' :
if ( ! V_368 ) {
V_368 = TRUE ;
V_374 ++ ;
}
break;
case 'L' :
if ( ! V_369 ) {
V_369 = TRUE ;
V_374 ++ ;
}
break;
#ifdef F_13
case 'd' :
if ( ! V_370 ) {
V_370 = TRUE ;
V_374 ++ ;
}
break;
#endif
case 'S' :
if ( ! V_373 ) {
V_373 = TRUE ;
V_374 ++ ;
}
break;
case 'k' :
if ( ! V_371 ) {
V_371 = TRUE ;
V_372 = V_402 ;
V_374 ++ ;
} else {
F_26 ( L_241 ) ;
V_360 = TRUE ;
}
break;
case 'M' :
V_116 = TRUE ;
break;
case 'C' :
V_341 = F_258 ( V_402 , L_242 ) ;
break;
case 'N' :
V_343 = F_258 ( V_402 , L_243 ) ;
break;
default:
F_26 ( L_244 , V_353 [ V_407 - 1 ] ) ;
case '?' :
V_360 = TRUE ;
break;
}
}
if ( ! V_360 ) {
V_352 -= V_407 ;
V_353 += V_407 ;
if ( V_352 >= 1 ) {
V_352 -- ;
V_353 ++ ;
}
if ( V_352 != 0 ) {
F_26 ( L_245 , V_353 [ 0 ] ) ;
V_360 = TRUE ;
}
}
if ( ( V_341 > 0 ) || ( V_343 > 0 ) ) {
V_268 = TRUE ;
}
if ( ( V_341 == 0 ) && ( V_343 == 0 ) ) {
V_341 = 1000 * 1000 ;
V_343 = 1000 ;
}
if ( V_360 ) {
F_10 ( V_19 ) ;
F_102 ( 1 ) ;
}
if ( V_374 > 1 ) {
#ifdef F_13
F_26 ( L_246 ) ;
#else
F_26 ( L_247 ) ;
#endif
F_102 ( 1 ) ;
} else if ( V_374 == 1 ) {
if ( V_229 . V_276 ) {
F_26 ( L_248 ) ;
F_102 ( 1 ) ;
}
} else {
if ( V_229 . V_51 -> V_52 > 1 ) {
V_268 = TRUE ;
V_229 . V_275 = TRUE ;
}
if ( V_229 . V_281 &&
( ! V_229 . V_275 || V_229 . V_276 ) ) {
F_26 ( L_249 ) ;
F_102 ( 1 ) ;
}
if ( V_229 . V_276 ) {
if ( V_229 . V_285 == NULL ) {
F_26 ( L_250 ) ;
V_229 . V_276 = FALSE ;
}
if ( ! V_229 . V_408 && ! V_229 . V_409 ) {
F_26 ( L_251 ) ;
#if 0
global_capture_opts.multi_files_on = FALSE;
#endif
}
}
}
if ( V_368 ) {
T_22 * V_94 ;
int V_120 ;
T_7 * V_73 ;
V_94 = F_259 ( & V_120 , & V_73 , NULL ) ;
if ( V_94 == NULL ) {
if ( V_120 == 0 ) {
if ( ! V_116 ) {
F_26 ( L_116 ) ;
F_102 ( 2 ) ;
}
} else {
F_26 ( L_105 , V_73 ) ;
F_20 ( V_73 ) ;
F_102 ( 2 ) ;
}
}
if ( V_116 )
F_80 ( V_94 ) ;
else
F_260 ( V_94 ) ;
F_96 ( V_94 ) ;
F_102 ( 0 ) ;
}
if ( V_373 ) {
V_75 = F_88 ( V_116 ) ;
F_102 ( V_75 ) ;
}
if ( V_371 ) {
T_15 V_45 ;
if ( V_229 . V_51 -> V_52 != 1 ) {
F_26 ( L_252 ) ;
F_102 ( 2 ) ;
}
V_45 = F_42 ( V_229 . V_51 , T_15 , 0 ) ;
V_75 = F_215 ( V_45 . V_34 , V_372 ) ;
F_102 ( V_75 ) ;
}
V_75 = F_261 ( & V_229 , NULL ) ;
if ( V_75 != 0 ) {
F_102 ( V_75 ) ;
}
if ( V_369 ) {
T_21 * V_20 ;
T_7 * V_73 ;
T_17 V_410 ;
for ( V_410 = 0 ; V_410 < V_229 . V_51 -> V_52 ; V_410 ++ ) {
T_15 V_45 ;
V_45 = F_42 ( V_229 . V_51 , T_15 , V_410 ) ;
V_20 = F_64 ( & V_45 , & V_73 ) ;
if ( V_20 == NULL ) {
F_26 ( L_253
L_254
L_255 , V_45 . V_34 , V_73 ) ;
F_20 ( V_73 ) ;
F_102 ( 2 ) ;
}
if ( V_20 -> V_93 == NULL ) {
F_26 ( L_256 , V_45 . V_34 ) ;
F_102 ( 2 ) ;
}
if ( V_116 )
F_87 ( V_20 ) ;
else
F_262 ( V_20 , V_45 . V_34 ,
V_45 . V_92 ) ;
F_263 ( V_20 ) ;
}
F_102 ( 0 ) ;
}
if ( V_17 ) {
for ( V_50 = 0 ; V_50 < V_229 . V_51 -> V_52 ; V_50 ++ ) {
T_15 V_45 ;
V_45 = F_42 ( V_229 . V_51 , T_15 , V_50 ) ;
F_90 ( V_123 , V_124 , L_257 ,
V_45 . V_34 ) ;
}
} else {
V_282 = F_173 ( L_59 ) ;
#ifdef F_6
if ( V_229 . V_51 -> V_52 < 2 )
#else
if ( V_229 . V_51 -> V_52 < 4 )
#endif
{
for ( V_50 = 0 ; V_50 < V_229 . V_51 -> V_52 ; V_50 ++ ) {
T_15 V_45 ;
V_45 = F_42 ( V_229 . V_51 , T_15 , V_50 ) ;
if ( V_50 > 0 ) {
if ( V_229 . V_51 -> V_52 > 2 ) {
F_228 ( V_282 , L_104 ) ;
}
F_228 ( V_282 , L_258 ) ;
if ( V_50 == V_229 . V_51 -> V_52 - 1 ) {
F_228 ( V_282 , L_259 ) ;
}
}
F_228 ( V_282 , L_260 , V_45 . V_321 ) ;
}
} else {
F_228 ( V_282 , L_261 , V_229 . V_51 -> V_52 ) ;
}
fprintf ( V_19 , L_262 , V_282 -> V_282 ) ;
F_179 ( V_282 , TRUE ) ;
}
F_264 ( & V_229 , V_89 ) ;
#ifdef F_13
if ( V_370 ) {
F_41 ( & V_229 ) ;
F_102 ( 0 ) ;
}
#endif
F_265 ( & V_229 ) ;
fflush ( V_19 ) ;
if ( F_266 ( & V_229 , & V_366 , & V_290 ) == TRUE ) {
F_102 ( 0 ) ;
} else {
F_102 ( 1 ) ;
}
return 0 ;
}
static void
V_388 ( const char * V_411 , T_47 V_412 ,
const char * V_413 , T_40 T_48 V_2 )
{
T_49 V_414 ;
struct V_415 * V_416 ;
const char * V_417 ;
T_7 * V_18 ;
if ( ! ( V_412 & V_418 & ~ ( V_124 | V_130 ) ) ) {
#if ! F_62 ( F_104 ) && ! F_62 ( V_336 )
return;
#endif
}
time ( & V_414 ) ;
V_416 = localtime ( & V_414 ) ;
switch( V_412 & V_418 ) {
case V_382 :
V_417 = L_263 ;
break;
case V_383 :
V_417 = L_264 ;
break;
case V_384 :
V_417 = L_265 ;
break;
case V_385 :
V_417 = L_266 ;
break;
case V_130 :
V_417 = L_267 ;
break;
case V_124 :
V_417 = L_268 ;
break;
default:
fprintf ( V_19 , L_269 , V_412 ) ;
V_417 = NULL ;
F_267 () ;
}
if ( V_412 & V_385 ) {
V_18 = F_57 ( L_88 , V_413 ) ;
} else {
V_18 = F_57 ( L_270 ,
V_416 -> V_419 , V_416 -> V_420 , V_416 -> V_421 ,
V_411 != NULL ? V_411 : L_59 ,
V_417 , V_413 ) ;
}
#if F_62 ( F_104 ) || F_62 ( V_336 )
if ( ! ( V_412 & V_418 & ~ ( V_124 | V_130 ) ) ) {
#ifdef F_104
fprintf ( V_19 , L_105 , V_18 ) ;
fflush ( V_19 ) ;
#endif
#ifdef V_336
fprintf ( V_379 , L_105 , V_18 ) ;
fflush ( V_379 ) ;
#endif
F_20 ( V_18 ) ;
return;
}
#endif
if ( V_17 ) {
F_19 ( 2 , V_18 , L_59 ) ;
} else {
fprintf ( V_19 , L_105 , V_18 ) ;
fflush ( V_19 ) ;
}
F_20 ( V_18 ) ;
}
static void
F_202 ( unsigned int V_133 )
{
char V_422 [ V_423 + 1 + 1 ] ;
static unsigned int V_424 = 0 ;
if ( V_17 ) {
F_30 ( V_422 , sizeof( V_422 ) , L_271 , V_133 ) ;
F_90 ( V_123 , V_124 , L_272 , V_422 ) ;
F_50 ( 2 , V_425 , V_422 ) ;
} else {
V_424 += V_133 ;
fprintf ( V_19 , L_273 , V_424 ) ;
fflush ( V_19 ) ;
}
}
static void
F_203 ( const char * V_426 )
{
if ( V_17 ) {
F_90 ( V_123 , V_124 , L_274 , V_426 ) ;
F_50 ( 2 , V_427 , V_426 ) ;
} else {
#ifdef F_252
V_137 = TRUE ;
#endif
fprintf ( V_19 , L_275 , V_426 ) ;
fflush ( V_19 ) ;
#ifdef F_252
V_137 = FALSE ;
if ( V_135 )
F_100 () ;
#endif
}
}
static void
F_46 ( T_14 * V_44 , T_17 V_49 , const char * V_24 )
{
T_15 V_45 ;
char V_422 [ V_46 + 1 + 6 ] ;
if ( V_49 < V_44 -> V_51 -> V_52 ) {
if ( V_17 ) {
F_30 ( V_422 , sizeof( V_422 ) , L_276 , V_49 , V_24 ) ;
F_90 ( V_123 , V_124 , L_277 , V_24 ) ;
F_50 ( 2 , V_428 , V_422 ) ;
} else {
V_45 = F_42 ( V_44 -> V_51 , T_15 , V_49 ) ;
F_26 (
L_278
L_4
L_279
L_280 ,
V_45 . V_39 , V_45 . V_34 , V_24 ) ;
}
}
}
static void
F_44 ( const char * V_429 , const char * V_430 )
{
if ( V_17 ) {
F_90 ( V_123 , V_124 ,
L_281 , V_429 ) ;
F_90 ( V_123 , V_124 ,
L_282 , V_430 ) ;
F_19 ( 2 , V_429 , V_430 ) ;
} else {
F_26 ( L_105 , V_429 ) ;
if ( V_430 [ 0 ] != '\0' )
F_268 ( L_105 , V_430 ) ;
}
}
static void
F_269 ( V_8 V_291 , V_8 V_431 , V_8 V_432 , V_8 V_293 , V_8 V_433 , T_7 * V_34 )
{
char V_422 [ V_423 + 1 + 1 ] ;
V_8 V_434 = V_431 + V_432 + V_293 ;
F_30 ( V_422 , sizeof( V_422 ) , L_271 , V_434 ) ;
if ( V_17 ) {
F_90 ( V_123 , V_124 ,
L_283 ,
V_34 , V_291 , V_434 , V_431 , V_432 , V_293 , V_433 ) ;
F_50 ( 2 , V_435 , V_422 ) ;
} else {
fprintf ( V_19 ,
L_284 ,
V_34 , V_291 , V_434 , V_431 , V_432 , V_293 , V_433 ,
V_291 ? 100.0 * V_291 / ( V_291 + V_434 ) : 0.0 ) ;
fflush ( V_19 ) ;
}
}
static T_11
F_92 ( void )
{
T_28 V_436 = 0 ;
T_11 V_256 ;
if ( ! V_17 ) {
return TRUE ;
}
if ( ! V_404 || ! V_406 ) {
F_90 ( V_123 , V_130 ,
L_285 ) ;
return FALSE ;
}
V_256 = F_270 ( V_406 , NULL , 0 , NULL , & V_436 , NULL ) ;
if ( ! V_256 || V_436 > 0 ) {
F_90 ( V_123 , V_130 ,
L_286 , V_404 ) ;
F_90 ( V_123 , V_124 ,
L_287 , V_404 ,
V_406 , V_256 , V_436 ) ;
return FALSE ;
} else {
return TRUE ;
}
}
