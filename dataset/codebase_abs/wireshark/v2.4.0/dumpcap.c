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
#ifdef F_11
fprintf ( V_13 , L_11 ) ;
#else
fprintf ( V_13 , L_12 , V_14 ) ;
#endif
fprintf ( V_13 , L_13 ) ;
#ifdef F_11
fprintf ( V_13 , L_14 ) ;
#endif
#ifdef F_12
fprintf ( V_13 , L_15 , V_15 ) ;
#endif
fprintf ( V_13 , L_16 ) ;
fprintf ( V_13 , L_17 ) ;
fprintf ( V_13 , L_18 ) ;
#ifdef F_13
fprintf ( V_13 , L_19 ) ;
#endif
fprintf ( V_13 , L_20
L_21 ) ;
fprintf ( V_13 , L_22 ) ;
fprintf ( V_13 , L_23 ) ;
fprintf ( V_13 , L_4 ) ;
#ifdef F_14
fprintf ( V_13 , L_24 ) ;
fprintf ( V_13 , L_25 ) ;
fprintf ( V_13 , L_26 ) ;
fprintf ( V_13 , L_27 ) ;
#ifdef F_15
fprintf ( V_13 , L_28 ) ;
fprintf ( V_13 , L_29 ) ;
fprintf ( V_13 , L_30 ) ;
#endif
#endif
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
fprintf ( V_13 , L_45 ) ;
fprintf ( V_13 , L_46 ) ;
fprintf ( V_13 , L_4 ) ;
fprintf ( V_13 , L_47 ) ;
fprintf ( V_13 , L_48 ) ;
fprintf ( V_13 , L_49 ) ;
fprintf ( V_13 , L_50 ) ;
fprintf ( V_13 , L_51 ) ;
fprintf ( V_13 , L_52 ) ;
fprintf ( V_13 , L_53 ) ;
fprintf ( V_13 , L_54 ) ;
fprintf ( V_13 , L_4 ) ;
#ifdef F_16
fprintf ( V_13 , L_55 ) ;
fprintf ( V_13 , L_56 ) ;
fprintf ( V_13 , L_57 ) ;
fprintf ( V_13 , L_4 ) ;
#endif
fprintf ( V_13 , L_58 ) ;
fprintf ( V_13 , L_59 ) ;
fprintf ( V_13 , L_4 ) ;
fprintf ( V_13 , L_60 ) ;
}
static void
F_17 ( const char * V_16 , T_6 V_17 )
{
if ( V_18 ) {
T_7 * V_19 ;
V_19 = F_18 ( V_16 , V_17 ) ;
F_19 ( 2 , V_19 , L_61 ) ;
F_20 ( V_19 ) ;
} else {
fprintf ( V_20 , L_62 ) ;
vfprintf ( V_20 , V_16 , V_17 ) ;
fprintf ( V_20 , L_4 ) ;
}
}
static void
F_21 ( const char * V_16 , T_6 V_17 )
{
if ( V_18 ) {
T_7 * V_19 ;
V_19 = F_18 ( V_16 , V_17 ) ;
F_19 ( 2 , V_19 , L_61 ) ;
F_20 ( V_19 ) ;
} else {
vfprintf ( V_20 , V_16 , V_17 ) ;
fprintf ( V_20 , L_4 ) ;
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
T_9 V_21 = F_24 () ;
F_22 ( L_63 ) ;
if ( F_25 ( V_21 ) ) {
F_26 ( L_64 , F_27 ( V_22 ) ) ;
}
F_22 ( L_65 ) ;
F_28 ( V_21 ) ;
}
static void
F_29 ( const char * V_23 ,
const char * V_24 ,
char * V_25 , T_10 V_26 ,
char * V_27 ,
T_10 V_28 )
{
#ifndef F_6
const char * V_29 ;
static const char V_30 [] = L_66 ;
#endif
F_30 ( V_25 , ( V_31 ) V_26 ,
L_67 ,
V_24 , V_23 ) ;
#ifdef F_6
if ( ! V_32 ) {
F_30 ( V_27 , ( V_31 ) V_28 ,
L_4
L_68
L_4
L_69
L_4
L_70
L_71 ) ;
} else {
F_30 ( V_27 , ( V_31 ) V_28 ,
L_4
L_72
L_4
L_4
L_73
L_4
L_74
L_75 ,
V_24 ) ;
}
#else
if ( strncmp ( V_23 , V_30 , sizeof V_30 - 1 ) == 0 )
V_29 =
L_76
L_77
L_78
L_79
L_4
L_80
L_81
L_82
L_83
L_84 ;
else
V_29 = L_61 ;
F_30 ( V_27 , ( V_31 ) V_28 ,
L_85
L_86 , V_29 ) ;
#endif
}
static T_11
F_31 ( const char * V_24 , T_12 * V_33 ,
struct V_34 * V_35 , const char * V_36 )
{
T_13 V_37 , V_38 ;
T_7 V_39 [ V_40 ] ;
if ( F_32 ( V_24 , & V_37 , & V_38 , V_39 ) < 0 ) {
V_38 = 0 ;
}
F_33 (cast-qual)
if ( F_34 ( V_33 , V_35 , ( char * ) V_36 , 1 , V_38 ) < 0 )
return FALSE ;
F_35 (cast-qual)
return TRUE ;
}
static T_11
F_36 ( T_14 * V_41 )
{
T_15 V_42 ;
T_12 * V_33 ;
T_7 V_23 [ V_40 ] ;
char V_25 [ V_43 + 1 ] ;
char V_27 [ V_43 + 1 ] ;
struct V_34 V_35 ;
struct V_44 * V_45 ;
T_16 V_46 ;
T_17 V_47 ;
for ( V_47 = 0 ; V_47 < V_41 -> V_48 -> V_49 ; V_47 ++ ) {
V_42 = F_37 ( V_41 -> V_48 , T_15 , V_47 ) ;
V_33 = F_38 ( V_41 , & V_42 ,
V_50 , & V_23 ) ;
if ( V_33 == NULL ) {
F_29 ( V_23 ,
V_42 . V_51 ,
V_25 , sizeof V_25 ,
V_27 ,
sizeof V_27 ) ;
F_39 ( V_25 , V_27 ) ;
return FALSE ;
}
if ( ! F_40 ( V_33 , V_42 . V_52 , V_42 . V_51 ,
V_25 , sizeof V_25 ,
V_27 , sizeof V_27 ) ) {
F_41 ( V_33 ) ;
F_39 ( V_25 , V_27 ) ;
return FALSE ;
}
if ( ! F_31 ( V_42 . V_51 , V_33 , & V_35 ,
V_42 . V_36 ) ) {
F_41 ( V_33 ) ;
F_42 ( V_41 , V_47 , V_25 ) ;
return FALSE ;
}
F_41 ( V_33 ) ;
V_45 = V_35 . V_53 ;
for ( V_46 = 0 ; V_46 < V_35 . V_54 ; V_45 ++ , V_46 ++ )
printf ( L_87 , F_43 ( V_45 , V_46 ) ) ;
}
#ifndef F_44
F_45 () ;
#else
F_23 () ;
#endif
if ( V_18 ) {
F_46 ( 2 , V_55 , NULL ) ;
}
return TRUE ;
}
static void
F_47 ( T_18 * V_56 )
{
int V_46 ;
T_18 * V_57 ;
T_19 * V_58 ;
T_20 * V_59 ;
T_21 * V_60 ;
char V_61 [ V_62 ] ;
if ( V_18 ) {
F_46 ( 2 , V_55 , NULL ) ;
}
V_46 = 1 ;
for ( V_57 = F_48 ( V_56 ) ; V_57 != NULL ;
V_57 = F_49 ( V_57 ) ) {
V_58 = ( T_19 * ) V_57 -> V_63 ;
printf ( L_88 , V_46 ++ , V_58 -> V_51 ) ;
if ( V_58 -> V_64 != NULL )
printf ( L_89 , V_58 -> V_64 ) ;
else
printf ( L_90 ) ;
if ( V_58 -> V_65 != NULL )
printf ( L_89 , V_58 -> V_65 ) ;
else
printf ( L_90 ) ;
printf ( L_91 , V_58 -> type ) ;
for ( V_59 = F_50 ( V_58 -> V_66 , 0 ) ; V_59 != NULL ;
V_59 = F_51 ( V_59 ) ) {
if ( V_59 != F_50 ( V_58 -> V_66 , 0 ) )
printf ( L_92 ) ;
V_60 = ( T_21 * ) V_59 -> V_63 ;
switch( V_60 -> V_67 ) {
case V_68 :
if ( F_52 ( & V_60 -> V_59 . V_69 , V_61 ,
V_62 ) ) {
printf ( L_93 , V_61 ) ;
} else {
printf ( L_94 ) ;
}
break;
case V_70 :
if ( F_53 ( & V_60 -> V_59 . V_71 ,
V_61 , V_62 ) ) {
printf ( L_93 , V_61 ) ;
} else {
printf ( L_95 ) ;
}
break;
default:
printf ( L_96 , V_60 -> V_67 ) ;
}
}
if ( V_58 -> V_72 )
printf ( L_97 ) ;
else
printf ( L_98 ) ;
#ifdef F_54
printf ( L_99 , V_58 -> V_73 ) ;
#endif
printf ( L_4 ) ;
}
}
static void
F_55 ( T_22 * V_21 )
{
T_18 * V_74 ;
T_23 * V_75 ;
const T_7 * V_76 ;
if ( V_18 ) {
F_46 ( 2 , V_55 , NULL ) ;
}
if ( V_21 -> V_77 )
printf ( L_100 ) ;
else
printf ( L_101 ) ;
for ( V_74 = V_21 -> V_78 ; V_74 != NULL ;
V_74 = F_49 ( V_74 ) ) {
V_75 = ( T_23 * ) V_74 -> V_63 ;
if ( V_75 -> V_79 != NULL )
V_76 = V_75 -> V_79 ;
else
V_76 = L_102 ;
printf ( L_103 , V_75 -> V_80 , V_75 -> V_51 ,
V_76 ) ;
}
}
static int
F_56 ( T_11 V_81 )
{
T_18 * V_56 , * V_57 , * V_82 = NULL , * V_83 ;
T_19 * V_58 ;
T_24 * V_84 ;
int V_85 ;
T_7 * V_86 ;
T_12 * V_87 ;
char V_88 [ V_40 ] ;
struct V_89 V_90 ;
V_56 = F_57 ( & V_85 , & V_86 ) ;
if ( V_56 == NULL ) {
if ( V_85 == 0 )
F_26 ( L_104 ) ;
else {
F_26 ( L_93 , V_86 ) ;
F_20 ( V_86 ) ;
}
return V_85 ;
}
for ( V_57 = F_48 ( V_56 ) ; V_57 != NULL ; V_57 = F_49 ( V_57 ) ) {
V_58 = ( T_19 * ) V_57 -> V_63 ;
#ifdef F_16
if ( ! strncmp ( V_58 -> V_51 , L_105 , 2 ) ) {
F_58 ( V_91 , V_92 , L_106 ,
V_58 -> V_51 ) ;
continue;
}
#endif
#ifdef F_59
V_87 = F_60 ( V_58 -> V_51 , V_93 , 0 , 0 , NULL , V_88 ) ;
#else
V_87 = F_61 ( V_58 -> V_51 , V_93 , 0 , 0 , V_88 ) ;
#endif
if ( V_87 ) {
V_84 = ( T_24 * ) F_62 ( sizeof( T_24 ) ) ;
V_84 -> V_51 = F_63 ( V_58 -> V_51 ) ;
V_84 -> V_87 = V_87 ;
V_82 = F_64 ( V_82 , V_84 ) ;
}
}
if ( ! V_82 ) {
F_26 ( L_104 ) ;
return 2 ;
}
if ( V_18 ) {
F_46 ( 2 , V_55 , NULL ) ;
}
if ( ! V_81 ) {
printf ( L_107 , L_108 , L_109 ,
L_110 ) ;
}
V_94 . V_95 = TRUE ;
while ( V_94 . V_95 ) {
for ( V_83 = F_48 ( V_82 ) ; V_83 != NULL ; V_83 = F_49 ( V_83 ) ) {
V_84 = ( T_24 * ) V_83 -> V_63 ;
F_65 ( V_84 -> V_87 , & V_90 ) ;
if ( ! V_81 ) {
printf ( L_111 , V_84 -> V_51 ,
V_90 . V_96 , V_90 . V_97 ) ;
} else {
printf ( L_112 , V_84 -> V_51 ,
V_90 . V_96 , V_90 . V_97 ) ;
fflush ( stdout ) ;
}
}
#ifdef F_6
if ( ! F_66 () ) {
V_94 . V_95 = FALSE ;
}
F_67 ( 1 * 1000 ) ;
#else
F_68 ( 1 ) ;
#endif
}
for ( V_83 = F_48 ( V_82 ) ; V_83 != NULL ; V_83 = F_49 ( V_83 ) ) {
V_84 = ( T_24 * ) V_83 -> V_63 ;
F_41 ( V_84 -> V_87 ) ;
F_20 ( V_84 -> V_51 ) ;
F_20 ( V_84 ) ;
}
F_69 ( V_82 ) ;
F_70 ( V_56 ) ;
return 0 ;
}
static BOOL T_25
F_71 ( T_26 V_98 )
{
F_58 ( V_91 , V_99 ,
L_113 ) ;
F_58 ( V_91 , V_92 ,
L_114 , V_98 ) ;
if ( V_18 || ( V_98 != V_100 ) ) {
F_72 () ;
return TRUE ;
} else {
return FALSE ;
}
}
static void
F_71 ( int T_27 V_2 )
{
F_72 () ;
}
static void
F_73 ( T_11 V_101 )
{
if ( ! V_18 && V_101 ) {
fprintf ( V_20 , L_115 , V_94 . V_102 ) ;
fflush ( V_20 ) ;
}
}
static void
F_74 ( void )
{
F_73 ( V_103 ) ;
V_104 = FALSE ;
}
static void
F_75 ( int T_27 V_2 )
{
int V_105 = V_22 ;
if ( V_106 )
V_104 = TRUE ;
else
F_74 () ;
V_22 = V_105 ;
}
static void
F_76 ( int V_107 )
{
#ifdef F_6
F_77 () ;
#ifdef F_78
printf ( L_116 ) ;
F_79 () ;
#endif
#endif
F_80 ( & V_108 ) ;
exit ( V_107 ) ;
}
static void
F_81 ( void )
{
if ( F_82 () ) {
T_28 V_109 [ 2 ] = { V_110 , V_111 } ;
int V_112 = sizeof( V_109 ) / sizeof( T_28 ) ;
T_9 V_21 = F_24 () ;
F_22 ( L_117 ) ;
if ( F_83 ( V_113 , 1 , 0 , 0 , 0 ) == - 1 ) {
F_26 ( L_118 , F_27 ( V_22 ) ) ;
}
F_84 ( V_21 , V_114 , V_112 , V_109 , V_115 ) ;
F_84 ( V_21 , V_116 , V_112 , V_109 , V_115 ) ;
if ( F_25 ( V_21 ) ) {
F_26 ( L_64 , F_27 ( V_22 ) ) ;
}
F_22 ( L_119 ) ;
F_45 () ;
F_22 ( L_120 ) ;
F_84 ( V_21 , V_117 , V_112 , V_109 , V_115 ) ;
if ( F_25 ( V_21 ) ) {
F_26 ( L_64 , F_27 ( V_22 ) ) ;
}
F_22 ( L_121 ) ;
F_28 ( V_21 ) ;
}
}
static void
F_85 ( T_11 V_118 , struct V_119 * V_120 , struct V_121 * V_122 )
{
if ( V_118 ) {
V_122 -> V_123 = F_86 ( V_122 -> V_123 ) ;
V_122 -> V_124 = F_86 ( V_122 -> V_124 ) ;
V_122 -> V_125 = F_86 ( V_122 -> V_125 ) ;
V_122 -> V_126 = F_86 ( V_122 -> V_126 ) ;
}
if ( V_120 -> V_127 == 2 &&
( V_120 -> V_128 < 3 ||
( V_120 -> V_128 == 3 && V_122 -> V_125 > V_122 -> V_126 ) ) ) {
V_8 V_129 ;
V_129 = V_122 -> V_126 ;
V_122 -> V_126 = V_122 -> V_125 ;
V_122 -> V_125 = V_129 ;
}
}
static T_1
F_87 ( int V_130 , char * V_131 , T_10 V_132 , T_11 T_29 V_2 )
{
#ifdef F_6
if ( T_29 ) {
return F_88 ( V_130 , V_131 , ( int ) V_132 , 0 ) ;
} else {
return - 1 ;
}
#else
return F_89 ( V_130 , V_131 , V_132 ) ;
#endif
}
static void * F_90 ( void * V_133 )
{
T_30 * V_134 ;
#ifdef F_6
BOOL V_135 ;
T_26 V_136 , V_137 , V_138 ;
#else
T_10 V_138 ;
int V_136 ;
#endif
V_134 = ( T_30 * ) V_133 ;
while ( V_134 -> V_139 == V_140 ) {
F_91 ( V_134 -> V_141 ) ;
F_92 ( V_134 -> V_142 ) ;
V_138 = 0 ;
while ( V_138 < V_134 -> V_143 ) {
if ( ( V_134 -> V_144 )
#ifndef F_6
|| 1
#endif
)
{
V_136 = F_87 ( V_134 -> V_145 , V_134 -> V_146 + V_138 ,
V_134 -> V_143 - V_138 , V_134 -> V_144 ) ;
if ( V_136 <= 0 ) {
if ( V_136 == 0 ) {
V_134 -> V_139 = V_147 ;
V_138 = 0 ;
break;
} else {
V_134 -> V_139 = V_148 ;
V_138 = - 1 ;
break;
}
} else {
V_138 += V_136 ;
}
}
#ifdef F_6
else
{
V_135 = F_93 ( V_134 -> V_149 , V_134 -> V_146 + V_138 ,
V_134 -> V_143 - V_138 ,
& V_136 , NULL ) ;
V_138 += V_136 ;
if ( ! V_135 ) {
V_137 = F_94 () ;
if ( V_137 == V_150 ) {
continue;
} else if ( V_137 == V_151 || V_137 == V_152 || V_137 == V_153 ) {
V_134 -> V_139 = V_147 ;
V_138 = 0 ;
break;
}
V_134 -> V_139 = V_148 ;
V_138 = - 1 ;
break;
} else if ( V_136 == 0 && V_134 -> V_143 > 0 ) {
V_134 -> V_139 = V_147 ;
V_138 = 0 ;
break;
}
}
#endif
}
V_134 -> V_154 = V_138 ;
if ( V_134 -> V_154 >= V_134 -> V_143 ) {
F_95 ( V_134 -> V_155 , V_134 -> V_146 ) ;
}
F_96 ( V_134 -> V_142 ) ;
}
return NULL ;
}
static int
F_97 ( int V_130 )
{
T_31 V_156 ;
struct V_7 V_157 ;
F_98 ( & V_156 ) ;
F_99 ( V_130 , & V_156 ) ;
V_157 . V_11 = V_158 / 1000000 ;
V_157 . V_12 = V_158 % 1000000 ;
return F_100 ( V_130 + 1 , & V_156 , NULL , NULL , & V_157 ) ;
}
static int
F_101 ( char * V_159 , T_30 * V_134 , char * V_25 , int V_160 )
{
char * V_161 = V_159 + 4 ;
struct V_162 V_163 ;
char V_131 [ 16 ] ;
char * V_164 ;
unsigned long V_165 ;
T_10 V_49 ;
int V_1 ;
memset ( & V_163 , 0 , sizeof( V_163 ) ) ;
V_164 = strchr ( V_161 , ':' ) ;
if ( V_164 == NULL ) {
V_49 = strlen ( V_161 ) ;
V_165 = V_166 ;
}
else {
V_49 = V_164 - V_161 ;
V_165 = strtoul ( V_164 + 1 , & V_164 , 10 ) ;
if ( * V_164 || V_165 > 65535 ) {
goto V_167;
}
}
if ( V_49 > 15 ) {
goto V_167;
}
F_30 ( V_131 , ( V_31 ) V_49 + 1 , L_93 , V_161 ) ;
V_131 [ V_49 ] = '\0' ;
if ( ! F_102 ( V_131 , ( V_8 * ) & V_163 . V_168 ) ) {
goto V_167;
}
V_163 . V_169 = V_170 ;
V_163 . V_171 = F_103 ( ( V_172 ) V_165 ) ;
if ( ( ( V_1 = ( int ) F_104 ( V_170 , V_173 , 0 ) ) < 0 ) ||
( F_105 ( V_1 , (struct V_174 * ) & V_163 , sizeof( V_163 ) ) < 0 ) ) {
#ifdef F_6
T_32 V_175 = NULL ;
int V_176 ;
V_176 = F_106 () ;
F_107 ( V_177 |
V_178 |
V_179 ,
NULL , V_176 , F_108 ( V_180 , V_181 ) ,
( T_32 ) & V_175 , 0 , NULL ) ;
#endif
F_30 ( V_25 , V_160 ,
L_122
#ifdef F_6
L_123 , V_176 , V_175 ? ( char * ) V_175 : L_124 ) ;
if ( V_175 )
F_109 ( V_175 ) ;
#else
L_125 , V_22 , F_27 ( V_22 ) ) ;
#endif
V_134 -> V_139 = V_148 ;
if ( V_1 >= 0 )
F_110 ( V_1 , TRUE ) ;
return - 1 ;
}
void
F_110 ( int V_130 , T_11 T_29 V_2 )
{
#ifdef F_6
if ( T_29 ) {
F_111 ( V_130 ) ;
}
#else
F_4 ( V_130 ) ;
#endif
}
static void
F_112 ( char * V_159 ,
T_30 * V_134 ,
struct V_119 * V_120 ,
char * V_25 , int V_160 )
{
#ifndef F_6
T_33 V_182 ;
struct V_183 V_163 ;
#else
char * V_184 , * V_185 ;
T_34 * V_86 ;
#ifdef F_54
char * V_186 ;
#endif
#endif
#ifdef F_54
T_11 V_187 = FALSE ;
T_15 V_42 ;
#endif
T_1 V_136 ;
int V_1 = - 1 , V_188 ;
T_10 V_138 ;
V_8 V_189 = 0 ;
V_134 -> V_145 = - 1 ;
#ifdef F_6
V_134 -> V_149 = V_190 ;
#endif
F_58 ( V_91 , V_92 , L_126 , V_159 ) ;
if ( strcmp ( V_159 , L_127 ) == 0 ) {
#ifndef F_6
V_1 = 0 ;
#else
V_134 -> V_149 = F_113 ( V_191 ) ;
#endif
} else if ( ! strncmp ( V_159 , L_128 , 4 ) ) {
if ( ( V_1 = F_101 ( V_159 , V_134 , V_25 , V_160 ) ) < 0 ) {
return;
}
} else {
#ifdef F_54
V_42 = F_37 ( V_108 . V_48 , T_15 , 0 ) ;
#endif
#ifndef F_6
#ifdef F_54
if ( F_114 ( V_42 . V_51 , V_192 ) != NULL )
V_187 = TRUE ;
#endif
if ( F_115 ( V_159 , & V_182 ) < 0 ) {
if ( V_22 == V_193 || V_22 == V_194 )
V_134 -> V_139 = V_195 ;
else {
F_30 ( V_25 , V_160 ,
L_129
L_130 , F_27 ( V_22 ) ) ;
V_134 -> V_139 = V_148 ;
}
return;
}
if ( F_116 ( V_182 . V_196 ) ) {
V_1 = F_2 ( V_159 , V_197 | V_198 , 0000 ) ;
if ( V_1 == - 1 ) {
F_30 ( V_25 , V_160 ,
L_129
L_131 , F_27 ( V_22 ) ) ;
V_134 -> V_139 = V_148 ;
return;
}
} else if ( F_117 ( V_182 . V_196 ) ) {
V_1 = F_104 ( V_199 , V_173 , 0 ) ;
if ( V_1 == - 1 ) {
F_30 ( V_25 , V_160 ,
L_129
L_132 , F_27 ( V_22 ) ) ;
V_134 -> V_139 = V_148 ;
return;
}
V_163 . V_200 = V_199 ;
if ( F_118 ( V_163 . V_201 , V_159 , sizeof V_163 . V_201 ) > sizeof V_163 . V_201 ) {
F_30 ( V_25 , V_160 ,
L_133
L_134 ) ;
V_134 -> V_139 = V_148 ;
F_4 ( V_1 ) ;
return;
}
V_136 = F_105 ( V_1 , (struct V_174 * ) & V_163 , sizeof V_163 ) ;
if ( V_136 == - 1 ) {
F_30 ( V_25 , V_160 ,
L_133
L_135 , F_27 ( V_22 ) ) ;
V_134 -> V_139 = V_148 ;
F_4 ( V_1 ) ;
return;
}
} else {
if ( F_119 ( V_182 . V_196 ) ) {
V_134 -> V_139 = V_195 ;
} else {
F_30 ( V_25 , V_160 ,
L_136
L_137 , V_159 ) ;
V_134 -> V_139 = V_148 ;
}
return;
}
#else
#define F_120 "\\pipe\\"
V_184 = F_63 ( V_159 ) ;
if ( ( V_185 = strstr ( V_184 , L_138 ) ) == V_184 ) {
V_185 = strchr ( V_184 + 3 , '\\' ) ;
if ( V_185 && F_121 ( V_185 , F_120 , strlen ( F_120 ) ) != 0 )
V_185 = NULL ;
}
F_20 ( V_184 ) ;
if ( ! V_185 ) {
F_30 ( V_25 , V_160 ,
L_136
L_139 , V_159 ) ;
V_134 -> V_139 = V_195 ;
return;
}
#ifdef F_54
V_186 = F_122 ( L_140 , V_192 , NULL ) ;
V_187 = strstr ( V_42 . V_51 , V_186 ) ? TRUE : FALSE ;
F_20 ( V_186 ) ;
#endif
while ( 1 ) {
#ifdef F_54
if( V_187 )
V_134 -> V_149 = F_113 ( V_191 ) ;
else
#endif
V_134 -> V_149 = F_123 ( F_124 ( V_159 ) , V_202 , 0 , NULL ,
V_203 , 0 , NULL ) ;
if ( V_134 -> V_149 != V_190 )
break;
if ( F_94 () != V_204 ) {
F_107 ( V_177 | V_178 | V_179 ,
NULL , F_94 () , 0 , ( T_32 ) & V_86 , 0 , NULL ) ;
F_30 ( V_25 , V_160 ,
L_141
L_142 ,
V_159 , F_125 ( V_86 ) , F_94 () ) ;
F_109 ( V_86 ) ;
V_134 -> V_139 = V_148 ;
return;
}
if ( ! F_126 ( F_124 ( V_159 ) , 30 * 1000 ) ) {
F_107 ( V_177 | V_178 | V_179 ,
NULL , F_94 () , 0 , ( T_32 ) & V_86 , 0 , NULL ) ;
F_30 ( V_25 , V_160 ,
L_143
L_144 ,
V_159 , F_125 ( V_86 ) , F_94 () ) ;
F_109 ( V_86 ) ;
V_134 -> V_139 = V_148 ;
return;
}
}
#endif
}
V_134 -> V_205 = TRUE ;
V_134 -> V_206 = ( V_207 * ) F_62 ( 2048 ) ;
V_134 -> V_208 = 2048 ;
#ifdef F_6
if ( V_134 -> V_144 )
#endif
{
V_138 = 0 ;
while ( V_138 < sizeof V_189 ) {
if ( V_1 == - 1 ) {
F_30 ( V_25 , V_160 , L_145 ) ;
goto error;
}
V_188 = F_97 ( V_1 ) ;
if ( V_188 < 0 ) {
F_30 ( V_25 , V_160 ,
L_146 , F_27 ( V_22 ) ) ;
goto error;
} else if ( V_188 > 0 ) {
V_136 = F_87 ( V_1 , ( ( char * ) & V_189 ) + V_138 ,
sizeof V_189 - V_138 ,
V_134 -> V_144 ) ;
#ifdef F_54
if ( V_187 && V_136 <= 0 )
goto error;
#endif
if ( V_136 <= 0 ) {
if ( V_136 == 0 )
F_30 ( V_25 , V_160 , L_147 ) ;
else
F_30 ( V_25 , V_160 , L_148 ,
F_27 ( V_22 ) ) ;
goto error;
}
V_138 += V_136 ;
}
}
}
#ifdef F_6
else {
#if F_127 ( 2 , 31 , 0 )
F_128 ( L_149 , & F_90 , V_134 ) ;
#else
F_129 ( & F_90 , V_134 , FALSE , NULL ) ;
#endif
V_134 -> V_146 = ( char * ) & V_189 ;
V_134 -> V_154 = 0 ;
V_134 -> V_143 = sizeof( V_189 ) ;
F_95 ( V_134 -> V_141 , V_134 -> V_146 ) ;
F_91 ( V_134 -> V_155 ) ;
if ( V_134 -> V_154 <= 0 && V_187 )
goto error;
if ( V_134 -> V_154 <= 0 ) {
if ( V_134 -> V_154 == 0 )
F_30 ( V_25 , V_160 , L_147 ) ;
else
F_30 ( V_25 , V_160 , L_148 ,
F_27 ( V_22 ) ) ;
goto error;
}
}
#endif
switch ( V_189 ) {
case V_209 :
case V_210 :
V_134 -> V_211 = FALSE ;
V_134 -> V_212 = FALSE ;
V_134 -> V_213 = V_189 == V_210 ;
break;
case V_214 :
V_134 -> V_211 = FALSE ;
V_134 -> V_212 = TRUE ;
break;
case V_215 :
case V_216 :
V_134 -> V_211 = TRUE ;
V_134 -> V_212 = FALSE ;
V_134 -> V_213 = V_189 == V_216 ;
break;
case V_217 :
V_134 -> V_211 = TRUE ;
V_134 -> V_212 = TRUE ;
break;
case V_218 :
F_30 ( V_25 , V_160 , L_150 ) ;
goto error;
default:
F_30 ( V_25 , V_160 , L_151 ) ;
goto error;
}
#ifdef F_6
if ( V_134 -> V_144 )
#endif
{
V_138 = 0 ;
while ( V_138 < sizeof( struct V_119 ) ) {
V_188 = F_97 ( V_1 ) ;
if ( V_188 < 0 ) {
F_30 ( V_25 , V_160 ,
L_146 , F_27 ( V_22 ) ) ;
goto error;
} else if ( V_188 > 0 ) {
V_136 = F_87 ( V_1 , ( ( char * ) V_120 ) + V_138 ,
sizeof( struct V_119 ) - V_138 ,
V_134 -> V_144 ) ;
if ( V_136 <= 0 ) {
if ( V_136 == 0 )
F_30 ( V_25 , V_160 , L_152 ) ;
else
F_30 ( V_25 , V_160 , L_153 ,
F_27 ( V_22 ) ) ;
goto error;
}
V_138 += V_136 ;
}
}
}
#ifdef F_6
else {
V_134 -> V_146 = ( char * ) V_120 ;
V_134 -> V_154 = 0 ;
V_134 -> V_143 = sizeof( struct V_119 ) ;
F_95 ( V_134 -> V_141 , V_134 -> V_146 ) ;
F_91 ( V_134 -> V_155 ) ;
if ( V_134 -> V_154 <= 0 ) {
if ( V_134 -> V_154 == 0 )
F_30 ( V_25 , V_160 , L_152 ) ;
else
F_30 ( V_25 , V_160 , L_154 ,
F_27 ( V_22 ) ) ;
goto error;
}
}
#endif
if ( V_134 -> V_211 ) {
V_120 -> V_127 = F_130 ( V_120 -> V_127 ) ;
V_120 -> V_128 = F_130 ( V_120 -> V_128 ) ;
V_120 -> V_219 = F_86 ( V_120 -> V_219 ) ;
V_120 -> V_220 = F_86 ( V_120 -> V_220 ) ;
}
V_134 -> V_52 = V_120 -> V_220 ;
#ifdef F_131
if ( V_134 -> V_52 == F_131 ) {
V_134 -> V_221 = V_222 ;
} else
#endif
V_134 -> V_221 = V_14 ;
if ( V_120 -> V_127 < 2 ) {
F_30 ( V_25 , V_160 , L_155 ) ;
goto error;
}
V_134 -> V_223 = V_224 ;
V_134 -> V_139 = V_140 ;
V_134 -> V_145 = V_1 ;
return;
error:
F_58 ( V_91 , V_92 , L_156 , V_25 ) ;
V_134 -> V_139 = V_148 ;
F_110 ( V_1 , V_134 -> V_144 ) ;
V_134 -> V_145 = - 1 ;
#ifdef F_6
V_134 -> V_149 = V_190 ;
#endif
}
static int
F_132 ( T_35 * V_225 , T_30 * V_134 , char * V_25 , int V_160 )
{
struct V_226 V_227 ;
enum { V_228 , V_229 , V_230 , V_231 ,
V_232 } V_233 ;
#ifdef F_6
#if ! F_127 ( 2 , 31 , 18 )
T_36 V_234 ;
#endif
T_37 V_235 ;
T_34 * V_86 ;
#endif
T_1 V_136 ;
T_17 V_236 ;
#ifdef F_133
F_58 ( V_91 , V_92 , L_157 ) ;
#endif
switch ( V_134 -> V_223 ) {
case V_224 :
#ifdef F_6
if ( F_134 ( V_134 -> V_142 ) ) {
#endif
V_134 -> V_223 = V_237 ;
V_134 -> V_143 = V_134 -> V_212 ?
sizeof( struct V_238 ) : sizeof( struct V_121 ) ;
V_134 -> V_154 = 0 ;
#ifdef F_6
V_134 -> V_146 = ( char * ) & V_134 -> V_239 ;
F_95 ( V_134 -> V_141 , V_134 -> V_146 ) ;
F_96 ( V_134 -> V_142 ) ;
}
#endif
case V_237 :
#ifdef F_6
if ( V_134 -> V_144 )
#endif
{
V_136 = F_87 ( V_134 -> V_145 , ( ( char * ) & V_134 -> V_239 ) + V_134 -> V_154 ,
V_134 -> V_143 - V_134 -> V_154 , V_134 -> V_144 ) ;
if ( V_136 <= 0 ) {
if ( V_136 == 0 )
V_233 = V_230 ;
else
V_233 = V_231 ;
break;
}
V_134 -> V_154 += V_136 ;
}
#ifdef F_6
else {
#if F_127 ( 2 , 31 , 18 )
V_235 = F_135 ( V_134 -> V_155 , V_158 ) ;
#else
F_136 ( & V_234 ) ;
F_137 ( & V_234 , V_158 ) ;
V_235 = F_138 ( V_134 -> V_155 , & V_234 ) ;
#endif
if ( V_134 -> V_139 == V_147 ) {
V_233 = V_230 ;
break;
} else if ( V_134 -> V_139 == V_148 ) {
V_233 = V_231 ;
break;
}
if ( ! V_235 ) {
return 0 ;
}
}
#endif
if ( V_134 -> V_154 < V_134 -> V_143 )
return 0 ;
V_233 = V_228 ;
break;
case V_240 :
#ifdef F_6
if ( F_134 ( V_134 -> V_142 ) ) {
#endif
V_134 -> V_223 = V_241 ;
V_134 -> V_143 = V_134 -> V_239 . V_120 . V_125 ;
V_134 -> V_154 = 0 ;
#ifdef F_6
V_134 -> V_146 = V_134 -> V_206 ;
F_95 ( V_134 -> V_141 , V_134 -> V_146 ) ;
F_96 ( V_134 -> V_142 ) ;
}
#endif
case V_241 :
#ifdef F_6
if ( V_134 -> V_144 )
#endif
{
V_136 = F_87 ( V_134 -> V_145 ,
V_134 -> V_206 + V_134 -> V_154 ,
V_134 -> V_143 - V_134 -> V_154 ,
V_134 -> V_144 ) ;
if ( V_136 <= 0 ) {
if ( V_136 == 0 )
V_233 = V_230 ;
else
V_233 = V_231 ;
break;
}
V_134 -> V_154 += V_136 ;
}
#ifdef F_6
else {
#if F_127 ( 2 , 31 , 18 )
V_235 = F_135 ( V_134 -> V_155 , V_158 ) ;
#else
F_136 ( & V_234 ) ;
F_137 ( & V_234 , V_158 ) ;
V_235 = F_138 ( V_134 -> V_155 , & V_234 ) ;
#endif
if ( V_134 -> V_139 == V_147 ) {
V_233 = V_230 ;
break;
} else if ( V_134 -> V_139 == V_148 ) {
V_233 = V_231 ;
break;
}
if ( ! V_235 ) {
return 0 ;
}
}
#endif
if ( V_134 -> V_154 < V_134 -> V_143 )
return 0 ;
V_233 = V_229 ;
break;
default:
F_30 ( V_25 , V_160 , L_158 ) ;
V_233 = V_232 ;
}
switch ( V_233 ) {
case V_228 :
F_85 ( V_134 -> V_211 , & V_134 -> V_242 ,
& V_134 -> V_239 . V_120 ) ;
if ( V_134 -> V_239 . V_120 . V_125 > V_134 -> V_221 ) {
F_30 ( V_25 , V_160 , L_159 ,
V_225 -> V_102 + 1 , V_134 -> V_239 . V_120 . V_125 ) ;
break;
}
if ( V_134 -> V_239 . V_120 . V_125 > V_134 -> V_208 ) {
V_236 = V_134 -> V_239 . V_120 . V_125 ;
V_236 -- ;
V_236 |= V_236 >> 1 ;
V_236 |= V_236 >> 2 ;
V_236 |= V_236 >> 4 ;
V_236 |= V_236 >> 8 ;
V_236 |= V_236 >> 16 ;
V_236 ++ ;
V_134 -> V_206 = ( V_207 * ) F_139 ( V_134 -> V_206 , V_236 ) ;
V_134 -> V_208 = V_236 ;
}
if ( V_134 -> V_239 . V_120 . V_125 ) {
V_134 -> V_223 = V_240 ;
return 0 ;
}
case V_229 :
V_227 . V_243 . V_11 = V_134 -> V_239 . V_120 . V_123 ;
V_227 . V_243 . V_12 = V_134 -> V_239 . V_120 . V_124 ;
V_227 . V_244 = V_134 -> V_239 . V_120 . V_125 ;
V_227 . V_49 = V_134 -> V_239 . V_120 . V_126 ;
if ( V_245 ) {
F_140 ( ( V_246 * ) V_134 , & V_227 , V_134 -> V_206 ) ;
} else {
F_141 ( ( V_246 * ) V_134 , & V_227 , V_134 -> V_206 ) ;
}
V_134 -> V_223 = V_224 ;
return 1 ;
case V_230 :
V_134 -> V_139 = V_147 ;
return - 1 ;
case V_231 :
#ifdef F_6
F_107 ( V_177 | V_178 | V_179 ,
NULL , F_94 () , 0 , ( T_32 ) & V_86 , 0 , NULL ) ;
F_30 ( V_25 , V_160 ,
L_160 ,
F_125 ( V_86 ) , F_94 () ) ;
F_109 ( V_86 ) ;
#else
F_30 ( V_25 , V_160 , L_161 ,
F_27 ( V_22 ) ) ;
#endif
case V_232 :
break;
}
V_134 -> V_139 = V_148 ;
return - 1 ;
}
static void F_142 ( T_35 * V_225 )
{
T_17 V_46 ;
T_30 * V_134 ;
F_58 ( V_91 , V_92 , L_162 ) ;
for ( V_46 = 0 ; V_46 < V_225 -> V_247 -> V_49 ; V_46 ++ ) {
V_134 = F_37 ( V_225 -> V_247 , T_30 * , V_46 ) ;
if ( V_134 -> V_205 ) {
if ( V_134 -> V_145 >= 0 ) {
F_110 ( V_134 -> V_145 , V_134 -> V_144 ) ;
V_134 -> V_145 = - 1 ;
}
#ifdef F_6
if ( V_134 -> V_149 != V_190 ) {
F_143 ( V_134 -> V_149 ) ;
V_134 -> V_149 = V_190 ;
}
#endif
if ( V_134 -> V_206 != NULL ) {
F_20 ( V_134 -> V_206 ) ;
V_134 -> V_206 = NULL ;
}
} else {
if ( V_134 -> V_33 != NULL ) {
F_58 ( V_91 , V_92 , L_163 , ( void * ) V_134 -> V_33 ) ;
F_41 ( V_134 -> V_33 ) ;
V_134 -> V_33 = NULL ;
}
}
}
V_225 -> V_95 = FALSE ;
#ifdef F_6
F_77 () ;
#endif
}
static T_38
F_144 ( T_12 * V_33 , T_11 V_205 ,
const T_7 * V_51 , const T_7 * V_36 )
{
struct V_34 V_35 ;
F_58 ( V_91 , V_92 , L_164 , V_36 ) ;
if ( V_36 && ! V_205 ) {
if ( ! F_31 ( V_51 , V_33 , & V_35 , V_36 ) ) {
return V_248 ;
}
if ( F_145 ( V_33 , & V_35 ) < 0 ) {
#ifdef F_146
F_147 ( & V_35 ) ;
#endif
return V_249 ;
}
#ifdef F_146
F_147 ( & V_35 ) ;
#endif
}
return V_250 ;
}
static T_11
F_148 ( T_14 * V_41 , T_35 * V_225 , char * V_25 , int V_26 )
{
int V_85 ;
T_17 V_46 ;
T_30 * V_134 ;
T_15 V_42 ;
T_11 V_251 ;
F_58 ( V_91 , V_92 , L_165 ) ;
if ( ( V_41 -> V_252 == FALSE ) &&
( V_41 -> V_48 -> V_49 > 1 ) ) {
F_30 ( V_25 , V_26 ,
L_166 ) ;
return FALSE ;
}
if ( V_41 -> V_253 ) {
V_225 -> V_254 = F_149 ( & V_85 ) ;
} else {
V_225 -> V_254 = F_150 ( V_225 -> V_255 , L_167 ) ;
if ( V_225 -> V_254 == NULL ) {
V_85 = V_22 ;
}
}
if ( V_225 -> V_254 ) {
if ( V_41 -> V_252 ) {
char * V_256 ;
T_39 * V_257 ;
T_39 * V_258 ;
V_257 = F_151 ( L_61 ) ;
V_258 = F_151 ( L_61 ) ;
F_152 ( V_257 ) ;
F_153 ( V_258 ) ;
V_256 = F_154 ( L_168 , F_155 () ) ;
V_251 = F_156 ( V_225 -> V_254 ,
( const char * ) V_41 -> V_259 ,
V_257 -> V_260 ,
V_258 -> V_260 ,
V_256 ,
- 1 ,
& V_225 -> V_261 ,
& V_85 ) ;
F_157 ( V_257 , TRUE ) ;
F_20 ( V_256 ) ;
for ( V_46 = 0 ; V_251 && ( V_46 < V_41 -> V_48 -> V_49 ) ; V_46 ++ ) {
V_42 = F_37 ( V_41 -> V_48 , T_15 , V_46 ) ;
V_134 = F_37 ( V_225 -> V_247 , T_30 * , V_46 ) ;
if ( V_134 -> V_205 ) {
V_134 -> V_219 = V_134 -> V_242 . V_219 ;
} else {
V_134 -> V_219 = F_158 ( V_134 -> V_33 ) ;
}
V_251 = F_159 ( V_94 . V_254 ,
NULL ,
V_42 . V_51 ,
V_42 . V_262 ,
V_42 . V_36 ,
V_258 -> V_260 ,
V_134 -> V_52 ,
V_134 -> V_219 ,
& ( V_94 . V_261 ) ,
0 ,
V_134 -> V_213 ? 9 : 6 ,
& V_94 . V_85 ) ;
}
F_157 ( V_258 , TRUE ) ;
} else {
V_134 = F_37 ( V_225 -> V_247 , T_30 * , 0 ) ;
if ( V_134 -> V_205 ) {
V_134 -> V_219 = V_134 -> V_242 . V_219 ;
} else {
V_134 -> V_219 = F_158 ( V_134 -> V_33 ) ;
}
V_251 = F_160 ( V_225 -> V_254 , V_134 -> V_52 , V_134 -> V_219 ,
V_134 -> V_213 , & V_225 -> V_261 , & V_85 ) ;
}
if ( ! V_251 ) {
fclose ( V_225 -> V_254 ) ;
V_225 -> V_254 = NULL ;
}
}
if ( V_225 -> V_254 == NULL ) {
switch ( V_85 ) {
default:
if ( V_85 < 0 ) {
F_30 ( V_25 , V_26 ,
L_169
L_170 ,
V_41 -> V_263 , V_85 ) ;
} else {
F_30 ( V_25 , V_26 ,
L_169
L_171 ,
V_41 -> V_263 , F_27 ( V_85 ) ) ;
}
break;
}
return FALSE ;
}
return TRUE ;
}
static T_11
F_161 ( T_14 * V_41 , T_35 * V_225 , int * V_264 )
{
unsigned int V_46 ;
T_30 * V_134 ;
T_3 V_265 = F_5 () ;
F_58 ( V_91 , V_92 , L_172 ) ;
if ( V_41 -> V_253 ) {
return F_162 ( & V_41 -> V_263 , V_264 ) ;
} else {
if ( V_41 -> V_252 ) {
for ( V_46 = 0 ; V_46 < V_94 . V_247 -> V_49 ; V_46 ++ ) {
V_134 = F_37 ( V_94 . V_247 , T_30 * , V_46 ) ;
if ( ! V_134 -> V_205 ) {
T_3 V_266 , V_267 ;
struct V_89 V_268 ;
if ( F_65 ( V_134 -> V_33 , & V_268 ) >= 0 ) {
V_266 = V_134 -> V_269 ;
V_267 = V_268 . V_97 + V_134 -> V_270 + V_134 -> V_271 ;
} else {
V_266 = V_272 ;
V_267 = V_272 ;
}
F_163 ( V_225 -> V_254 ,
V_46 ,
& V_225 -> V_261 ,
L_173 ,
V_273 ,
V_265 ,
V_266 ,
V_267 ,
V_264 ) ;
}
}
}
if ( fclose ( V_225 -> V_254 ) == V_274 ) {
if ( V_264 != NULL ) {
* V_264 = V_22 ;
}
return ( FALSE ) ;
} else {
return ( TRUE ) ;
}
}
}
static int
F_164 ( T_35 * V_225 ,
char * V_25 , int V_26 , T_30 * V_134 )
{
int V_275 ;
T_40 V_276 ;
#ifndef F_6
int V_188 ;
#endif
V_276 = V_225 -> V_102 ;
if ( V_134 -> V_205 ) {
#ifdef F_133
F_58 ( V_91 , V_92 , L_174 ) ;
#endif
#ifndef F_6
V_188 = F_97 ( V_134 -> V_145 ) ;
if ( V_188 <= 0 ) {
if ( V_188 < 0 && V_22 != V_277 ) {
F_30 ( V_25 , V_26 ,
L_175 , F_27 ( V_22 ) ) ;
F_39 ( V_25 , V_278 ) ;
V_225 -> V_95 = FALSE ;
}
} else {
#endif
V_275 = F_132 ( V_225 , V_134 , V_25 , V_26 ) ;
if ( V_275 < 0 ) {
V_225 -> V_95 = FALSE ;
}
#ifndef F_6
}
#endif
}
else
{
#ifdef F_165
#ifdef F_133
F_58 ( V_91 , V_92 , L_176 ) ;
#endif
if ( V_134 -> V_279 != - 1 ) {
V_188 = F_97 ( V_134 -> V_279 ) ;
if ( V_188 > 0 ) {
if ( V_245 ) {
V_275 = F_166 ( V_134 -> V_33 , 1 , F_140 , ( V_246 * ) V_134 ) ;
} else {
V_275 = F_166 ( V_134 -> V_33 , 1 , F_141 , ( V_246 * ) V_134 ) ;
}
if ( V_275 < 0 ) {
if ( V_275 == - 1 ) {
V_134 -> V_280 = TRUE ;
}
V_225 -> V_95 = FALSE ;
}
} else {
if ( V_188 < 0 && V_22 != V_277 ) {
F_30 ( V_25 , V_26 ,
L_175 , F_27 ( V_22 ) ) ;
F_39 ( V_25 , V_278 ) ;
V_225 -> V_95 = FALSE ;
}
}
}
else
#endif
{
#if 1
#ifdef F_133
F_58 ( V_91 , V_92 , L_177 ) ;
#endif
#ifdef F_6
if ( V_245 ) {
V_275 = F_166 ( V_134 -> V_33 , 1 , F_140 , ( V_246 * ) V_134 ) ;
} else {
V_275 = F_166 ( V_134 -> V_33 , 1 , F_141 , ( V_246 * ) V_134 ) ;
}
#else
if ( V_245 ) {
V_275 = F_166 ( V_134 -> V_33 , - 1 , F_140 , ( V_246 * ) V_134 ) ;
} else {
V_275 = F_166 ( V_134 -> V_33 , - 1 , F_141 , ( V_246 * ) V_134 ) ;
}
#endif
if ( V_275 < 0 ) {
if ( V_275 == - 1 ) {
V_134 -> V_280 = TRUE ;
}
V_225 -> V_95 = FALSE ;
}
#else
#ifdef F_133
F_58 ( V_91 , V_92 , L_178 ) ;
#endif
{
int V_281 ;
struct V_226 * V_282 ;
V_246 * V_283 ;
V_281 = 0 ;
while( V_225 -> V_95 &&
( V_281 = F_167 ( V_134 -> V_33 , & V_282 , & V_283 ) ) == 1 ) {
if ( V_245 ) {
F_140 ( ( V_246 * ) V_134 , V_282 , V_283 ) ;
} else {
F_141 ( ( V_246 * ) V_134 , V_282 , V_283 ) ;
}
}
if ( V_281 < 0 ) {
V_134 -> V_280 = TRUE ;
V_225 -> V_95 = FALSE ;
}
}
#endif
}
}
#ifdef F_133
F_58 ( V_91 , V_92 , L_179 , V_275 , F_168 ( V_275 , L_61 , L_180 ) ) ;
#endif
return V_225 -> V_102 - V_276 ;
}
static T_39 *
F_169 ( const char * V_24 )
{
T_7 * V_284 ;
T_39 * V_285 ;
V_284 = strchr ( V_24 , '{' ) ;
if ( V_284 == NULL )
return F_151 ( V_24 ) ;
V_285 = F_151 ( V_284 + 1 ) ;
V_284 = strchr ( V_285 -> V_260 , '}' ) ;
if ( V_284 == NULL )
return V_285 ;
V_285 = F_170 ( V_285 , V_284 - V_285 -> V_260 ) ;
return V_285 ;
}
static T_11
F_171 ( T_14 * V_41 , int * V_255 ,
char * V_25 , int V_26 )
{
char * V_286 ;
T_7 * V_287 ;
T_7 * V_288 , * V_289 ;
T_11 V_290 ;
F_58 ( V_91 , V_92 , L_181 ,
( V_41 -> V_263 ) ? V_41 -> V_263 : L_182 ) ;
if ( V_41 -> V_263 != NULL ) {
V_287 = F_63 ( V_41 -> V_263 ) ;
if ( V_41 -> V_291 == TRUE ) {
if ( V_41 -> V_253 ) {
F_30 ( V_25 , V_26 ,
L_183 ) ;
F_20 ( V_287 ) ;
return FALSE ;
}
if ( strcmp ( V_287 , L_127 ) == 0 ) {
* V_255 = 1 ;
#ifdef F_6
F_172 ( 1 , V_292 ) ;
#endif
}
}
else {
if ( V_41 -> V_253 ) {
* V_255 = F_173 ( V_287 ,
( V_41 -> V_293 ) ? V_41 -> V_294 : 0 ,
V_41 -> V_295 ) ;
if ( * V_255 != - 1 ) {
F_20 ( V_287 ) ;
V_287 = F_63 ( F_174 () ) ;
}
} else {
* V_255 = F_2 ( V_287 , V_296 | V_292 | V_297 | V_298 ,
( V_41 -> V_295 ) ? 0640 : 0600 ) ;
}
}
V_290 = FALSE ;
} else {
if ( V_108 . V_48 -> V_49 > 1 ) {
V_288 = F_154 ( L_184 , V_108 . V_48 -> V_49 ) ;
if ( V_41 -> V_252 ) {
V_289 = L_185 ;
} else{
V_289 = L_186 ;
}
} else {
T_7 * V_299 ;
V_299 = F_175 ( F_37 ( V_108 . V_48 , T_15 , 0 ) . V_300 ) ;
#ifdef F_6
if ( strncmp ( L_187 , V_299 , 5 ) == 0 )
{
T_39 * V_24 ;
V_24 = F_169 ( V_299 ) ;
F_20 ( V_299 ) ;
V_299 = F_63 ( V_24 -> V_260 ) ;
F_157 ( V_24 , TRUE ) ;
}
#endif
if ( V_41 -> V_252 ) {
V_288 = F_122 ( L_188 , V_299 , NULL ) ;
V_289 = L_185 ;
} else{
V_288 = F_122 ( L_188 , V_299 , NULL ) ;
V_289 = L_186 ;
}
F_20 ( V_299 ) ;
}
* V_255 = F_176 ( & V_286 , V_288 , V_289 ) ;
F_20 ( V_288 ) ;
V_287 = F_63 ( V_286 ) ;
V_290 = TRUE ;
}
if ( * V_255 == - 1 ) {
if ( V_290 ) {
F_30 ( V_25 , V_26 ,
L_189
L_190 , V_287 , F_27 ( V_22 ) ) ;
} else {
if ( V_41 -> V_253 ) {
F_177 () ;
}
F_30 ( V_25 , V_26 ,
L_191
L_190 , V_287 ,
F_27 ( V_22 ) ) ;
}
F_20 ( V_287 ) ;
return FALSE ;
}
if ( V_41 -> V_263 != NULL ) {
F_20 ( V_41 -> V_263 ) ;
}
V_41 -> V_263 = V_287 ;
return TRUE ;
}
static T_11
F_178 ( T_14 * V_41 ,
T_41 * V_301 ,
T_41 * V_302 ,
T_41 * V_303 )
{
T_17 V_46 ;
T_30 * V_134 ;
T_15 V_42 ;
T_11 V_251 ;
if ( V_41 -> V_253 ) {
if ( V_301 != NULL &&
F_179 ( V_301 , ( T_3 ) ++ V_94 . V_304 ) ) {
V_94 . V_95 = FALSE ;
return FALSE ;
}
if ( F_180 ( & V_94 . V_254 , & V_41 -> V_263 ,
& V_94 . V_255 , & V_94 . V_85 ) ) {
V_94 . V_261 = 0 ;
if ( V_41 -> V_252 ) {
char * V_256 ;
T_39 * V_257 ;
T_39 * V_258 ;
V_257 = F_151 ( L_61 ) ;
V_258 = F_151 ( L_61 ) ;
F_152 ( V_257 ) ;
F_153 ( V_258 ) ;
V_256 = F_154 ( L_168 , F_155 () ) ;
V_251 = F_156 ( V_94 . V_254 ,
( const char * ) V_41 -> V_259 ,
V_257 -> V_260 ,
V_258 -> V_260 ,
V_256 ,
- 1 ,
& ( V_94 . V_261 ) ,
& V_94 . V_85 ) ;
F_157 ( V_257 , TRUE ) ;
F_20 ( V_256 ) ;
for ( V_46 = 0 ; V_251 && ( V_46 < V_41 -> V_48 -> V_49 ) ; V_46 ++ ) {
V_42 = F_37 ( V_41 -> V_48 , T_15 , V_46 ) ;
V_134 = F_37 ( V_94 . V_247 , T_30 * , V_46 ) ;
V_251 = F_159 ( V_94 . V_254 ,
NULL ,
V_42 . V_51 ,
V_42 . V_262 ,
V_42 . V_36 ,
V_258 -> V_260 ,
V_134 -> V_52 ,
V_134 -> V_219 ,
& ( V_94 . V_261 ) ,
0 ,
V_134 -> V_213 ? 9 : 6 ,
& V_94 . V_85 ) ;
}
F_157 ( V_258 , TRUE ) ;
} else {
V_134 = F_37 ( V_94 . V_247 , T_30 * , 0 ) ;
V_251 = F_160 ( V_94 . V_254 , V_134 -> V_52 , V_134 -> V_219 ,
V_134 -> V_213 , & V_94 . V_261 , & V_94 . V_85 ) ;
}
if ( ! V_251 ) {
fclose ( V_94 . V_254 ) ;
V_94 . V_254 = NULL ;
V_94 . V_95 = FALSE ;
return FALSE ;
}
if ( V_302 )
F_181 ( V_302 ) ;
if ( V_303 )
F_181 ( V_303 ) ;
fflush ( V_94 . V_254 ) ;
if ( ! V_103 )
F_182 ( V_94 . V_305 ) ;
V_94 . V_305 = 0 ;
F_183 ( V_41 -> V_263 ) ;
} else {
V_94 . V_95 = FALSE ;
return FALSE ;
}
} else {
V_94 . V_95 = FALSE ;
return FALSE ;
}
return TRUE ;
}
static void *
F_184 ( void * V_133 )
{
T_30 * V_134 ;
char V_25 [ V_43 + 1 ] ;
V_134 = ( T_30 * ) V_133 ;
F_58 ( V_91 , V_99 , L_192 ,
V_134 -> V_306 ) ;
while ( V_94 . V_95 ) {
F_164 ( & V_94 , V_25 , sizeof( V_25 ) , V_134 ) ;
}
F_58 ( V_91 , V_99 , L_193 ,
V_134 -> V_306 ) ;
F_185 ( NULL ) ;
return ( NULL ) ;
}
static void
F_72 ( void )
{
#ifdef F_186
T_17 V_46 ;
T_30 * V_134 ;
for ( V_46 = 0 ; V_46 < V_94 . V_247 -> V_49 ; V_46 ++ ) {
V_134 = F_37 ( V_94 . V_247 , T_30 * , V_46 ) ;
if ( V_134 -> V_33 != NULL )
F_187 ( V_134 -> V_33 ) ;
}
#endif
V_94 . V_95 = FALSE ;
}
static void
F_188 ( char * V_25 , int V_307 , const char * V_308 ,
int V_85 , T_11 V_309 )
{
switch ( V_85 ) {
case V_310 :
F_30 ( V_25 , V_307 ,
L_194
L_195
L_196
L_197 ,
V_308 ) ;
break;
#ifdef F_189
case F_189 :
F_30 ( V_25 , V_307 ,
L_194
L_195
L_198
L_199
L_200 ,
V_308 ) ;
break;
#endif
default:
if ( V_309 ) {
F_30 ( V_25 , V_307 ,
L_201
L_202 ,
V_308 , F_27 ( V_85 ) ) ;
} else {
F_30 ( V_25 , V_307 ,
L_203
L_195
L_204 ,
V_308 , F_27 ( V_85 ) ) ;
}
break;
}
}
static void
F_141 ( V_246 * V_311 , const struct V_226 * V_227 ,
const V_246 * V_312 )
{
T_30 * V_134 = ( T_30 * ) ( void * ) V_311 ;
int V_85 ;
T_17 V_313 = V_134 -> V_213 ? 1000000000 : 1000000 ;
if ( ! V_94 . V_95 ) {
V_134 -> V_271 ++ ;
return;
}
if ( V_94 . V_254 ) {
T_11 V_251 ;
if ( V_108 . V_252 ) {
V_251 = F_190 ( V_94 . V_254 ,
NULL ,
V_227 -> V_243 . V_11 , ( V_314 ) V_227 -> V_243 . V_12 ,
V_227 -> V_244 , V_227 -> V_49 ,
V_134 -> V_306 ,
V_313 ,
V_312 , 0 ,
& V_94 . V_261 , & V_85 ) ;
} else {
V_251 = F_191 ( V_94 . V_254 ,
V_227 -> V_243 . V_11 , ( V_314 ) V_227 -> V_243 . V_12 ,
V_227 -> V_244 , V_227 -> V_49 ,
V_312 ,
& V_94 . V_261 , & V_85 ) ;
}
if ( ! V_251 ) {
V_94 . V_95 = FALSE ;
V_94 . V_85 = V_85 ;
V_134 -> V_270 ++ ;
} else {
#if F_192 ( F_78 ) || F_192 ( V_315 )
F_58 ( V_91 , V_99 ,
L_205 ,
V_227 -> V_244 , V_134 -> V_306 ) ;
#endif
V_94 . V_102 ++ ;
V_134 -> V_269 ++ ;
if ( ( V_94 . V_316 > 0 ) && ( V_94 . V_102 >= V_94 . V_316 ) ) {
V_94 . V_95 = FALSE ;
}
}
}
}
static void
F_140 ( V_246 * V_311 , const struct V_226 * V_227 ,
const V_246 * V_312 )
{
T_30 * V_134 = ( T_30 * ) ( void * ) V_311 ;
T_42 * V_317 ;
T_11 V_318 ;
if ( ! V_94 . V_95 ) {
V_134 -> V_271 ++ ;
return;
}
V_317 = ( T_42 * ) F_62 ( sizeof( T_42 ) ) ;
if ( V_317 == NULL ) {
V_134 -> V_270 ++ ;
return;
}
V_317 -> V_134 = V_134 ;
V_317 -> V_227 = * V_227 ;
V_317 -> V_312 = ( V_246 * ) F_62 ( V_227 -> V_244 ) ;
if ( V_317 -> V_312 == NULL ) {
V_134 -> V_270 ++ ;
F_20 ( V_317 ) ;
return;
}
memcpy ( V_317 -> V_312 , V_312 , V_227 -> V_244 ) ;
F_193 ( V_319 ) ;
if ( ( ( V_320 == 0 ) || ( V_321 < V_320 ) ) &&
( ( V_322 == 0 ) || ( V_323 < V_322 ) ) ) {
V_318 = FALSE ;
F_194 ( V_319 , V_317 ) ;
V_321 += V_227 -> V_244 ;
V_323 += 1 ;
} else {
V_318 = TRUE ;
}
F_195 ( V_319 ) ;
if ( V_318 ) {
V_134 -> V_270 ++ ;
F_20 ( V_317 -> V_312 ) ;
F_20 ( V_317 ) ;
F_58 ( V_91 , V_99 ,
L_206 ,
V_227 -> V_244 , V_134 -> V_306 ) ;
} else {
V_134 -> V_269 ++ ;
F_58 ( V_91 , V_99 ,
L_207 ,
V_227 -> V_244 , V_134 -> V_306 ) ;
}
F_58 ( V_91 , V_99 ,
L_208 V_324 L_209 V_324 L_210 ,
V_321 , V_323 ) ;
}
static int
F_196 ( const char * V_24 , const char * V_325 )
{
V_8 V_326 = 0 ;
int type = - 1 ;
V_8 V_327 = 0 ;
V_8 V_328 = 0 ;
int args ;
int V_329 = 0 ;
T_7 * * V_330 = NULL ;
V_330 = F_197 ( V_325 , L_92 , 4 ) ;
for ( args = 0 ; V_330 [ args ] ; args ++ ) ;
if ( V_330 [ 0 ] )
V_326 = F_198 ( V_330 [ 0 ] , L_211 ) ;
if ( args >= 1 && V_330 [ 1 ] ) {
type = F_199 ( V_330 [ 1 ] ) ;
if ( type == - 1 ) {
F_26 ( L_212 , V_330 [ 1 ] ) ;
V_329 = V_331 ;
goto V_332;
}
}
if ( args >= 2 && V_330 [ 2 ] )
V_327 = F_198 ( V_330 [ 2 ] , L_213 ) ;
if ( args >= 3 && V_330 [ 3 ] )
V_328 = F_198 ( V_330 [ 3 ] , L_214 ) ;
V_329 = F_200 () ;
if ( V_329 ) {
F_26 ( L_215 , abs ( V_329 ) , F_27 ( abs ( V_329 ) ) ) ;
V_329 = 2 ;
goto V_332;
}
V_329 = F_201 ( V_24 , V_326 , type , V_327 , V_328 ) ;
if ( V_329 ) {
F_26 ( L_216 , abs ( V_329 ) , F_27 ( abs ( V_329 ) ) ) ;
V_329 = 2 ;
goto V_332;
}
if ( V_18 )
F_46 ( 2 , V_55 , NULL ) ;
V_332:
F_202 ( V_330 ) ;
return V_329 ;
}
static void
F_203 ( T_39 * V_260 )
{
F_204 ( V_260 , L_217 ) ;
F_205 ( V_260 ) ;
}
static void
F_206 ( T_39 * V_260 )
{
F_204 ( V_260 , L_217 ) ;
F_207 ( V_260 ) ;
}
int
main ( int V_333 , char * V_334 [] )
{
T_39 * V_335 ;
T_39 * V_336 ;
int V_325 ;
static const struct V_337 V_338 [] = {
{ L_218 , V_339 , NULL , 'h' } ,
{ L_219 , V_339 , NULL , 'v' } ,
V_340
{ 0 , 0 , 0 , 0 }
} ;
T_11 V_341 = FALSE ;
#ifdef F_6
int V_233 ;
T_43 V_342 ;
#else
struct V_343 V_344 , V_345 ;
#endif
T_11 V_346 = TRUE ;
T_11 V_347 ;
struct V_89 V_268 ;
T_44 V_348 ;
T_11 V_349 = FALSE ;
T_11 V_350 = FALSE ;
#ifdef F_13
T_11 V_351 = FALSE ;
#endif
T_11 V_352 = FALSE ;
T_7 * V_353 = NULL ;
T_11 V_81 = FALSE ;
T_11 V_354 = FALSE ;
int V_107 , V_355 = 0 ;
T_40 V_46 ;
T_17 V_47 ;
#if F_192 ( V_356 ) && F_192 ( V_357 )
struct V_358 V_359 ;
#endif
T_39 * V_260 ;
F_208 ( F_17 , F_21 ) ;
V_335 = F_209 ( NULL , F_203 ) ;
V_336 = F_210 ( F_206 ) ;
F_211 ( L_220
L_4
L_93
L_4
L_93 ,
F_155 () , V_335 -> V_260 , V_336 -> V_260 ) ;
F_157 ( V_335 , TRUE ) ;
F_157 ( V_336 , TRUE ) ;
#ifdef F_6
F_212 ( V_333 , V_334 ) ;
F_213 () ;
F_214 () ;
#endif
#ifdef F_13
#define F_215 "d"
#else
#define F_215 ""
#endif
#ifdef F_14
#define F_216 "r"
#define F_217 "u"
#else
#define F_216 ""
#define F_217 ""
#endif
#ifdef F_15
#define F_218 "m:"
#else
#define F_218 ""
#endif
#define F_219 OPTSTRING_CAPTURE_COMMON "C:" OPTSTRING_d "gh" "k:" OPTSTRING_m "MN:nPq" OPTSTRING_r "St" OPTSTRING_u "vw:Z:"
#ifdef V_315
if ( ( V_360 = F_220 ( L_221 , L_222 ) ) == NULL ) {
fprintf ( V_20 , L_223 ) ;
exit ( 1 ) ;
}
#endif
#if F_192 ( V_356 ) && F_192 ( V_357 )
if ( F_221 ( & V_359 ) == 0 ) {
if ( strcmp ( V_359 . V_361 , L_224 ) == 0 ||
strcmp ( V_359 . V_361 , L_225 ) == 0 ||
strcmp ( V_359 . V_361 , L_226 ) == 0 )
V_362 = TRUE ;
}
#endif
for ( V_46 = 1 ; V_46 < V_333 ; V_46 ++ ) {
if ( strcmp ( L_227 , V_334 [ V_46 ] ) == 0 ) {
V_18 = TRUE ;
V_81 = TRUE ;
#ifdef F_6
F_172 ( 2 , V_292 ) ;
#endif
}
}
V_348 =
( T_44 ) (
V_363 |
V_364 |
V_365 |
V_366 |
V_99 |
V_92 |
V_367 |
V_368 ) ;
F_222 ( NULL ,
V_348 ,
V_369 , NULL ) ;
F_222 ( V_370 ,
V_348 ,
V_369 , NULL ) ;
F_222 ( V_371 ,
V_348 ,
V_369 , NULL ) ;
F_222 ( V_91 ,
V_348 ,
V_369 , NULL ) ;
V_94 . V_247 = F_223 ( FALSE , FALSE , sizeof( T_30 * ) ) ;
#if ! F_127 ( 2 , 31 , 0 )
F_224 ( NULL ) ;
#endif
#ifdef F_6
F_225 () ;
V_233 = F_226 ( F_227 ( 1 , 1 ) , & V_342 ) ;
if ( V_233 != 0 )
{
F_58 ( V_91 , V_363 ,
L_228 , V_233 ) ;
F_76 ( 1 ) ;
}
F_228 ( F_71 , TRUE ) ;
#else
memset ( & V_344 , 0 , sizeof( V_344 ) ) ;
V_344 . V_372 = F_71 ;
V_344 . V_373 = 0 ;
F_229 ( & V_344 . V_374 ) ;
V_343 ( V_375 , & V_344 , NULL ) ;
V_343 ( V_376 , & V_344 , NULL ) ;
V_343 ( V_377 , & V_344 , NULL ) ;
V_343 ( V_378 , NULL , & V_345 ) ;
if ( V_345 . V_372 == V_379 )
V_343 ( V_378 , & V_344 , NULL ) ;
#ifdef F_230
V_344 . V_372 = F_75 ;
V_344 . V_373 = V_380 ;
F_229 ( & V_344 . V_374 ) ;
V_343 ( F_230 , & V_344 , NULL ) ;
#endif
#endif
#ifdef F_16
F_1 () ;
#endif
F_231 () ;
#ifdef F_44
F_81 () ;
#endif
F_232 ( & V_108 ) ;
V_108 . V_381 = TRUE ;
V_108 . V_293 = TRUE ;
V_108 . V_18 = V_18 ;
while ( ( V_325 = F_233 ( V_333 , V_334 , F_219 , V_338 , NULL ) ) != - 1 ) {
switch ( V_325 ) {
case 'h' :
printf ( L_220
L_229
L_230 ,
F_155 () ) ;
F_10 ( stdout ) ;
F_76 ( 0 ) ;
break;
case 'v' :
V_335 = F_209 ( NULL , F_203 ) ;
V_336 = F_210 ( F_206 ) ;
F_234 ( L_231 , V_335 , V_336 ) ;
F_157 ( V_335 , TRUE ) ;
F_157 ( V_336 , TRUE ) ;
F_76 ( 0 ) ;
break;
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
case V_382 :
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
V_107 = F_235 ( & V_108 , V_325 , V_383 , & V_346 ) ;
if ( V_107 != 0 ) {
F_76 ( V_107 ) ;
}
break;
case 'Z' :
V_18 = TRUE ;
#ifdef F_6
F_172 ( 2 , V_292 ) ;
if ( strcmp ( V_383 , V_384 ) != 0 ) {
V_385 = F_154 ( V_386 , V_383 ) ;
V_387 = F_123 ( F_124 ( V_385 ) ,
V_202 , 0 , NULL , V_203 , 0 , NULL ) ;
if ( V_387 == V_190 ) {
F_58 ( V_91 , V_99 ,
L_232 ,
V_385 ) ;
F_76 ( 1 ) ;
}
}
#endif
break;
case 'q' :
V_103 = TRUE ;
break;
case 't' :
V_245 = TRUE ;
break;
case 'D' :
if ( ! V_349 ) {
V_349 = TRUE ;
V_355 ++ ;
}
break;
case 'L' :
if ( ! V_350 ) {
V_350 = TRUE ;
V_355 ++ ;
}
break;
#ifdef F_13
case 'd' :
if ( ! V_351 ) {
V_351 = TRUE ;
V_355 ++ ;
}
break;
#endif
case 'S' :
if ( ! V_354 ) {
V_354 = TRUE ;
V_355 ++ ;
}
break;
case 'k' :
if ( ! V_352 ) {
V_352 = TRUE ;
V_353 = V_383 ;
V_355 ++ ;
} else {
F_26 ( L_233 ) ;
V_341 = TRUE ;
}
break;
case 'M' :
V_81 = TRUE ;
break;
case 'C' :
V_320 = F_236 ( V_383 , L_234 ) ;
break;
case 'N' :
V_322 = F_236 ( V_383 , L_235 ) ;
break;
default:
F_26 ( L_236 , V_334 [ V_388 - 1 ] ) ;
case '?' :
V_341 = TRUE ;
break;
}
}
if ( ! V_341 ) {
V_333 -= V_388 ;
V_334 += V_388 ;
if ( V_333 >= 1 ) {
V_333 -- ;
V_334 ++ ;
}
if ( V_333 != 0 ) {
F_26 ( L_237 , V_334 [ 0 ] ) ;
V_341 = TRUE ;
}
}
if ( ( V_320 > 0 ) || ( V_322 > 0 ) ) {
V_245 = TRUE ;
}
if ( ( V_320 == 0 ) && ( V_322 == 0 ) ) {
V_320 = 1000 * 1000 ;
V_322 = 1000 ;
}
if ( V_341 ) {
F_10 ( V_20 ) ;
F_76 ( 1 ) ;
}
if ( V_355 > 1 ) {
#ifdef F_13
F_26 ( L_238 ) ;
#else
F_26 ( L_239 ) ;
#endif
F_76 ( 1 ) ;
} else if ( V_355 == 1 ) {
if ( V_108 . V_253 ) {
F_26 ( L_240 ) ;
F_76 ( 1 ) ;
}
} else {
if ( V_108 . V_48 -> V_49 > 1 ) {
V_245 = TRUE ;
V_108 . V_252 = TRUE ;
}
if ( V_108 . V_259 &&
( ! V_108 . V_252 || V_108 . V_253 ) ) {
F_26 ( L_241 ) ;
F_76 ( 1 ) ;
}
if ( V_108 . V_253 ) {
if ( V_108 . V_263 == NULL ) {
F_26 ( L_242 ) ;
V_108 . V_253 = FALSE ;
}
if ( ! V_108 . V_389 && ! V_108 . V_390 ) {
F_26 ( L_243 ) ;
#if 0
global_capture_opts.multi_files_on = FALSE;
#endif
}
}
}
if ( V_349 ) {
T_18 * V_56 ;
int V_85 ;
T_7 * V_86 ;
V_56 = F_237 ( & V_85 , & V_86 , NULL ) ;
if ( V_56 == NULL ) {
if ( V_85 == 0 ) {
if ( ! V_81 ) {
F_26 ( L_104 ) ;
F_76 ( 2 ) ;
}
} else {
F_26 ( L_93 , V_86 ) ;
F_20 ( V_86 ) ;
F_76 ( 2 ) ;
}
}
if ( V_81 )
F_47 ( V_56 ) ;
else
F_238 ( V_56 ) ;
F_70 ( V_56 ) ;
F_76 ( 0 ) ;
}
if ( V_354 ) {
V_107 = F_56 ( V_81 ) ;
F_76 ( V_107 ) ;
}
if ( V_352 ) {
T_15 V_42 ;
if ( V_108 . V_48 -> V_49 != 1 ) {
F_26 ( L_244 ) ;
F_76 ( 2 ) ;
}
V_42 = F_37 ( V_108 . V_48 , T_15 , 0 ) ;
V_107 = F_196 ( V_42 . V_51 , V_353 ) ;
F_76 ( V_107 ) ;
}
V_107 = F_239 ( & V_108 , NULL ) ;
if ( V_107 != 0 ) {
F_76 ( V_107 ) ;
}
if ( V_350 ) {
T_22 * V_21 ;
T_7 * V_86 ;
T_17 V_391 ;
for ( V_391 = 0 ; V_391 < V_108 . V_48 -> V_49 ; V_391 ++ ) {
T_15 V_42 ;
V_42 = F_37 ( V_108 . V_48 , T_15 , V_391 ) ;
V_21 = F_240 ( & V_42 , & V_86 ) ;
if ( V_21 == NULL ) {
F_26 ( L_245
L_246
L_247 , V_42 . V_51 , V_86 ) ;
F_20 ( V_86 ) ;
F_76 ( 2 ) ;
}
if ( V_21 -> V_78 == NULL ) {
F_26 ( L_248 , V_42 . V_51 ) ;
F_76 ( 2 ) ;
}
if ( V_81 )
F_55 ( V_21 ) ;
else
F_241 ( V_21 , V_42 . V_51 ,
V_42 . V_392 ) ;
F_242 ( V_21 ) ;
}
F_76 ( 0 ) ;
}
if ( V_18 ) {
for ( V_47 = 0 ; V_47 < V_108 . V_48 -> V_49 ; V_47 ++ ) {
T_15 V_42 ;
V_42 = F_37 ( V_108 . V_48 , T_15 , V_47 ) ;
F_58 ( V_91 , V_92 , L_249 ,
V_42 . V_51 ) ;
}
} else {
V_260 = F_151 ( L_61 ) ;
#ifdef F_6
if ( V_108 . V_48 -> V_49 < 2 )
#else
if ( V_108 . V_48 -> V_49 < 4 )
#endif
{
for ( V_47 = 0 ; V_47 < V_108 . V_48 -> V_49 ; V_47 ++ ) {
T_15 V_42 ;
V_42 = F_37 ( V_108 . V_48 , T_15 , V_47 ) ;
if ( V_47 > 0 ) {
if ( V_108 . V_48 -> V_49 > 2 ) {
F_243 ( V_260 , L_92 ) ;
}
F_243 ( V_260 , L_250 ) ;
if ( V_47 == V_108 . V_48 -> V_49 - 1 ) {
F_243 ( V_260 , L_251 ) ;
}
}
F_243 ( V_260 , L_252 , V_42 . V_300 ) ;
}
} else {
F_243 ( V_260 , L_253 , V_108 . V_48 -> V_49 ) ;
}
fprintf ( V_20 , L_254 , V_260 -> V_260 ) ;
F_157 ( V_260 , TRUE ) ;
}
F_244 ( & V_108 , V_93 ) ;
#ifdef F_13
if ( V_351 ) {
F_36 ( & V_108 ) ;
F_76 ( 0 ) ;
}
#endif
F_245 ( & V_108 ) ;
fflush ( V_20 ) ;
if ( F_246 ( & V_108 , & V_347 , & V_268 ) == TRUE ) {
F_76 ( 0 ) ;
} else {
F_76 ( 1 ) ;
}
return 0 ;
}
static void
V_369 ( const char * V_393 , T_44 V_394 ,
const char * V_395 , T_37 T_45 V_2 )
{
T_46 V_396 ;
struct V_397 * V_398 ;
const char * V_399 ;
T_7 * V_19 ;
if ( ! ( V_394 & V_400 & ~ ( V_92 | V_99 ) ) ) {
#if ! F_192 ( F_78 ) && ! F_192 ( V_315 )
return;
#endif
}
switch( V_394 & V_400 ) {
case V_363 :
V_399 = L_255 ;
break;
case V_364 :
V_399 = L_256 ;
break;
case V_365 :
V_399 = L_257 ;
break;
case V_366 :
V_399 = L_258 ;
break;
case V_99 :
V_399 = L_259 ;
break;
case V_92 :
V_399 = L_260 ;
break;
default:
fprintf ( V_20 , L_261 , V_394 ) ;
V_399 = NULL ;
F_247 () ;
}
if ( V_394 & V_366 ) {
V_19 = F_154 ( L_87 , V_395 ) ;
} else {
time ( & V_396 ) ;
V_398 = localtime ( & V_396 ) ;
if ( V_398 != NULL )
V_19 = F_154 ( L_262 ,
V_398 -> V_401 , V_398 -> V_402 , V_398 -> V_403 ,
V_393 != NULL ? V_393 : L_61 ,
V_399 , V_395 ) ;
else
V_19 = F_154 ( L_263 ,
V_393 != NULL ? V_393 : L_61 ,
V_399 , V_395 ) ;
}
#if F_192 ( F_78 ) || F_192 ( V_315 )
if ( ! ( V_394 & V_400 & ~ ( V_92 | V_99 ) ) ) {
#ifdef F_78
fprintf ( V_20 , L_93 , V_19 ) ;
fflush ( V_20 ) ;
#endif
#ifdef V_315
fprintf ( V_360 , L_93 , V_19 ) ;
fflush ( V_360 ) ;
#endif
F_20 ( V_19 ) ;
return;
}
#endif
if ( V_18 ) {
F_19 ( 2 , V_19 , L_61 ) ;
} else {
fprintf ( V_20 , L_93 , V_19 ) ;
fflush ( V_20 ) ;
}
F_20 ( V_19 ) ;
}
static void
F_182 ( unsigned int V_102 )
{
char V_404 [ V_405 + 1 + 1 ] ;
static unsigned int V_406 = 0 ;
if ( V_18 ) {
F_30 ( V_404 , sizeof( V_404 ) , L_264 , V_102 ) ;
F_58 ( V_91 , V_92 , L_265 , V_404 ) ;
F_46 ( 2 , V_407 , V_404 ) ;
} else {
V_406 += V_102 ;
fprintf ( V_20 , L_266 , V_406 ) ;
fflush ( V_20 ) ;
}
}
static void
F_183 ( const char * V_408 )
{
if ( V_18 ) {
F_58 ( V_91 , V_92 , L_267 , V_408 ) ;
F_46 ( 2 , V_409 , V_408 ) ;
} else {
#ifdef F_230
V_106 = TRUE ;
#endif
fprintf ( V_20 , L_268 , V_408 ) ;
fflush ( V_20 ) ;
#ifdef F_230
V_106 = FALSE ;
if ( V_104 )
F_74 () ;
#endif
}
}
static void
F_42 ( T_14 * V_41 , T_17 V_46 , const char * V_25 )
{
T_15 V_42 ;
char V_404 [ V_43 + 1 + 6 ] ;
if ( V_46 < V_41 -> V_48 -> V_49 ) {
if ( V_18 ) {
F_30 ( V_404 , sizeof( V_404 ) , L_269 , V_46 , V_25 ) ;
F_58 ( V_91 , V_92 , L_270 , V_25 ) ;
F_46 ( 2 , V_410 , V_404 ) ;
} else {
V_42 = F_37 ( V_41 -> V_48 , T_15 , V_46 ) ;
F_26 (
L_271
L_4
L_272
L_273 ,
V_42 . V_36 , V_42 . V_51 , V_25 ) ;
}
}
}
static void
F_39 ( const char * V_411 , const char * V_412 )
{
if ( V_18 ) {
F_58 ( V_91 , V_92 ,
L_274 , V_411 ) ;
F_58 ( V_91 , V_92 ,
L_275 , V_412 ) ;
F_19 ( 2 , V_411 , V_412 ) ;
} else {
F_26 ( L_93 , V_411 ) ;
if ( V_412 [ 0 ] != '\0' )
F_248 ( L_93 , V_412 ) ;
}
}
static void
F_249 ( V_8 V_269 , V_8 V_413 , V_8 V_414 , V_8 V_271 , V_8 V_415 , T_7 * V_51 )
{
char V_404 [ V_405 + 1 + 1 ] ;
V_8 V_416 = V_413 + V_414 + V_271 ;
F_30 ( V_404 , sizeof( V_404 ) , L_264 , V_416 ) ;
if ( V_18 ) {
F_58 ( V_91 , V_92 ,
L_276 ,
V_51 , V_269 , V_416 , V_413 , V_414 , V_271 , V_415 ) ;
F_46 ( 2 , V_417 , V_404 ) ;
} else {
fprintf ( V_20 ,
L_277 ,
V_51 , V_269 , V_416 , V_413 , V_414 , V_271 , V_415 ,
V_269 ? 100.0 * V_269 / ( V_269 + V_416 ) : 0.0 ) ;
fflush ( V_20 ) ;
}
}
static T_11
F_66 ( void )
{
T_26 V_418 = 0 ;
T_11 V_233 ;
if ( ! V_18 ) {
return TRUE ;
}
if ( ! V_385 || ! V_387 ) {
F_58 ( V_91 , V_99 ,
L_278 ) ;
return FALSE ;
}
V_233 = F_250 ( V_387 , NULL , 0 , NULL , & V_418 , NULL ) ;
if ( ! V_233 || V_418 > 0 ) {
F_58 ( V_91 , V_99 ,
L_279 , V_385 ) ;
F_58 ( V_91 , V_92 ,
L_280 , V_385 ,
V_387 , V_233 , V_418 ) ;
return FALSE ;
} else {
return TRUE ;
}
}
