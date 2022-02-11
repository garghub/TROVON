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
fprintf ( V_13 , L_19
L_20 ) ;
fprintf ( V_13 , L_21 ) ;
fprintf ( V_13 , L_22 ) ;
fprintf ( V_13 , L_4 ) ;
#ifdef F_14
fprintf ( V_13 , L_23 ) ;
fprintf ( V_13 , L_24 ) ;
fprintf ( V_13 , L_25 ) ;
fprintf ( V_13 , L_26 ) ;
#ifdef F_15
fprintf ( V_13 , L_27 ) ;
fprintf ( V_13 , L_28 ) ;
fprintf ( V_13 , L_29 ) ;
#endif
#endif
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
fprintf ( V_13 , L_45 ) ;
fprintf ( V_13 , L_4 ) ;
fprintf ( V_13 , L_46 ) ;
fprintf ( V_13 , L_47 ) ;
fprintf ( V_13 , L_48 ) ;
fprintf ( V_13 , L_49 ) ;
fprintf ( V_13 , L_50 ) ;
fprintf ( V_13 , L_51 ) ;
fprintf ( V_13 , L_52 ) ;
fprintf ( V_13 , L_53 ) ;
fprintf ( V_13 , L_4 ) ;
#ifdef F_16
fprintf ( V_13 , L_54 ) ;
fprintf ( V_13 , L_55 ) ;
fprintf ( V_13 , L_56 ) ;
fprintf ( V_13 , L_4 ) ;
#endif
fprintf ( V_13 , L_57 ) ;
fprintf ( V_13 , L_58 ) ;
fprintf ( V_13 , L_4 ) ;
fprintf ( V_13 , L_59 ) ;
}
static void
F_17 ( const char * V_15 , T_6 V_16 )
{
if ( V_17 ) {
T_7 * V_18 ;
V_18 = F_18 ( V_15 , V_16 ) ;
F_19 ( 2 , V_18 , L_60 ) ;
F_20 ( V_18 ) ;
} else {
fprintf ( V_19 , L_61 ) ;
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
F_19 ( 2 , V_18 , L_60 ) ;
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
F_22 ( L_62 ) ;
if ( F_25 ( V_20 ) ) {
F_26 ( L_63 , F_27 ( V_21 ) ) ;
}
F_22 ( L_64 ) ;
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
static const char V_29 [] = L_65 ;
#endif
F_30 ( V_24 , ( V_30 ) V_25 ,
L_66 ,
V_23 , V_22 ) ;
#ifdef F_6
if ( ! V_31 ) {
F_30 ( V_26 , ( V_30 ) V_27 ,
L_4
L_67
L_4
L_68
L_4
L_69
L_70 ) ;
} else {
F_30 ( V_26 , ( V_30 ) V_27 ,
L_4
L_71
L_4
L_4
L_72
L_4
L_73
L_74 ,
V_23 ) ;
}
#else
if ( strncmp ( V_22 , V_29 , sizeof V_29 - 1 ) == 0 )
V_28 =
L_75
L_76
L_77
L_78
L_4
L_79
L_80
L_81
L_82
L_83 ;
else
V_28 = L_60 ;
F_30 ( V_26 , ( V_30 ) V_27 ,
L_84
L_85 , V_28 ) ;
#endif
}
static T_11
F_31 ( const char * V_23 , T_12 * V_32 ,
struct V_33 * V_34 , const char * V_35 )
{
T_13 V_36 , V_37 ;
T_7 V_38 [ V_39 ] ;
if ( F_32 ( V_23 , & V_36 , & V_37 , V_38 ) < 0 ) {
V_37 = 0 ;
}
F_33 (cast-qual)
if ( F_34 ( V_32 , V_34 , ( char * ) V_35 , 1 , V_37 ) < 0 )
return FALSE ;
F_35 (cast-qual)
return TRUE ;
}
static T_11
F_36 ( T_14 * V_40 )
{
T_15 V_41 ;
T_12 * V_32 ;
T_7 V_22 [ V_39 ] ;
char V_24 [ V_42 + 1 ] ;
char V_26 [ V_42 + 1 ] ;
struct V_33 V_34 ;
struct V_43 * V_44 ;
T_16 V_45 ;
T_17 V_46 ;
for ( V_46 = 0 ; V_46 < V_40 -> V_47 -> V_48 ; V_46 ++ ) {
V_41 = F_37 ( V_40 -> V_47 , T_15 , V_46 ) ;
V_32 = F_38 ( V_40 , & V_41 ,
V_49 , & V_22 ) ;
if ( V_32 == NULL ) {
F_29 ( V_22 ,
V_41 . V_50 ,
V_24 , sizeof V_24 ,
V_26 ,
sizeof V_26 ) ;
F_39 ( V_24 , V_26 ) ;
return FALSE ;
}
if ( ! F_40 ( V_32 , V_41 . V_51 , V_41 . V_50 ,
V_24 , sizeof V_24 ,
V_26 , sizeof V_26 ) ) {
F_41 ( V_32 ) ;
F_39 ( V_24 , V_26 ) ;
return FALSE ;
}
if ( ! F_31 ( V_41 . V_50 , V_32 , & V_34 ,
V_41 . V_35 ) ) {
F_41 ( V_32 ) ;
F_42 ( V_40 , V_46 , V_24 ) ;
return FALSE ;
}
F_41 ( V_32 ) ;
V_44 = V_34 . V_52 ;
for ( V_45 = 0 ; V_45 < V_34 . V_53 ; V_44 ++ , V_45 ++ )
printf ( L_86 , F_43 ( V_44 , V_45 ) ) ;
}
#ifndef F_44
F_45 () ;
#else
F_23 () ;
#endif
if ( V_17 ) {
F_46 ( 2 , V_54 , NULL ) ;
}
return TRUE ;
}
static void
F_47 ( T_18 * V_55 )
{
int V_45 ;
T_18 * V_56 ;
T_19 * V_57 ;
T_20 * V_58 ;
T_21 * V_59 ;
char V_60 [ V_61 ] ;
if ( V_17 ) {
F_46 ( 2 , V_54 , NULL ) ;
}
V_45 = 1 ;
for ( V_56 = F_48 ( V_55 ) ; V_56 != NULL ;
V_56 = F_49 ( V_56 ) ) {
V_57 = ( T_19 * ) V_56 -> V_62 ;
printf ( L_87 , V_45 ++ , V_57 -> V_50 ) ;
if ( V_57 -> V_63 != NULL )
printf ( L_88 , V_57 -> V_63 ) ;
else
printf ( L_89 ) ;
if ( V_57 -> V_64 != NULL )
printf ( L_88 , V_57 -> V_64 ) ;
else
printf ( L_89 ) ;
printf ( L_90 , V_57 -> type ) ;
for ( V_58 = F_50 ( V_57 -> V_65 , 0 ) ; V_58 != NULL ;
V_58 = F_51 ( V_58 ) ) {
if ( V_58 != F_50 ( V_57 -> V_65 , 0 ) )
printf ( L_91 ) ;
V_59 = ( T_21 * ) V_58 -> V_62 ;
switch( V_59 -> V_66 ) {
case V_67 :
if ( F_52 ( & V_59 -> V_58 . V_68 , V_60 ,
V_61 ) ) {
printf ( L_92 , V_60 ) ;
} else {
printf ( L_93 ) ;
}
break;
case V_69 :
if ( F_53 ( & V_59 -> V_58 . V_70 ,
V_60 , V_61 ) ) {
printf ( L_92 , V_60 ) ;
} else {
printf ( L_94 ) ;
}
break;
default:
printf ( L_95 , V_59 -> V_66 ) ;
}
}
if ( V_57 -> V_71 )
printf ( L_96 ) ;
else
printf ( L_97 ) ;
#ifdef F_54
printf ( L_98 , V_57 -> V_72 ) ;
#endif
printf ( L_4 ) ;
}
}
static void
F_55 ( T_22 * V_20 )
{
T_18 * V_73 ;
T_23 * V_74 ;
const T_7 * V_75 ;
if ( V_17 ) {
F_46 ( 2 , V_54 , NULL ) ;
}
if ( V_20 -> V_76 )
printf ( L_99 ) ;
else
printf ( L_100 ) ;
for ( V_73 = V_20 -> V_77 ; V_73 != NULL ;
V_73 = F_49 ( V_73 ) ) {
V_74 = ( T_23 * ) V_73 -> V_62 ;
if ( V_74 -> V_78 != NULL )
V_75 = V_74 -> V_78 ;
else
V_75 = L_101 ;
printf ( L_102 , V_74 -> V_79 , V_74 -> V_50 ,
V_75 ) ;
}
}
static int
F_56 ( T_11 V_80 )
{
T_18 * V_55 , * V_56 , * V_81 = NULL , * V_82 ;
T_19 * V_57 ;
T_24 * V_83 ;
int V_84 ;
T_7 * V_85 ;
T_12 * V_86 ;
char V_87 [ V_39 ] ;
struct V_88 V_89 ;
V_55 = F_57 ( & V_84 , & V_85 ) ;
if ( V_55 == NULL ) {
if ( V_84 == 0 )
F_26 ( L_103 ) ;
else {
F_26 ( L_92 , V_85 ) ;
F_20 ( V_85 ) ;
}
return V_84 ;
}
for ( V_56 = F_48 ( V_55 ) ; V_56 != NULL ; V_56 = F_49 ( V_56 ) ) {
V_57 = ( T_19 * ) V_56 -> V_62 ;
#ifdef F_16
if ( ! strncmp ( V_57 -> V_50 , L_104 , 2 ) ) {
F_58 ( V_90 , V_91 , L_105 ,
V_57 -> V_50 ) ;
continue;
}
#endif
#ifdef F_59
V_86 = F_60 ( V_57 -> V_50 , V_92 , 0 , 0 , NULL , V_87 ) ;
#else
V_86 = F_61 ( V_57 -> V_50 , V_92 , 0 , 0 , V_87 ) ;
#endif
if ( V_86 ) {
V_83 = ( T_24 * ) F_62 ( sizeof( T_24 ) ) ;
V_83 -> V_50 = F_63 ( V_57 -> V_50 ) ;
V_83 -> V_86 = V_86 ;
V_81 = F_64 ( V_81 , V_83 ) ;
}
}
if ( ! V_81 ) {
F_26 ( L_103 ) ;
return 2 ;
}
if ( V_17 ) {
F_46 ( 2 , V_54 , NULL ) ;
}
if ( ! V_80 ) {
printf ( L_106 , L_107 , L_108 ,
L_109 ) ;
}
V_93 . V_94 = TRUE ;
while ( V_93 . V_94 ) {
for ( V_82 = F_48 ( V_81 ) ; V_82 != NULL ; V_82 = F_49 ( V_82 ) ) {
V_83 = ( T_24 * ) V_82 -> V_62 ;
F_65 ( V_83 -> V_86 , & V_89 ) ;
if ( ! V_80 ) {
printf ( L_110 , V_83 -> V_50 ,
V_89 . V_95 , V_89 . V_96 ) ;
} else {
printf ( L_111 , V_83 -> V_50 ,
V_89 . V_95 , V_89 . V_96 ) ;
fflush ( stdout ) ;
}
}
#ifdef F_6
if ( ! F_66 () ) {
V_93 . V_94 = FALSE ;
}
F_67 ( 1 * 1000 ) ;
#else
F_68 ( 1 ) ;
#endif
}
for ( V_82 = F_48 ( V_81 ) ; V_82 != NULL ; V_82 = F_49 ( V_82 ) ) {
V_83 = ( T_24 * ) V_82 -> V_62 ;
F_41 ( V_83 -> V_86 ) ;
F_20 ( V_83 -> V_50 ) ;
F_20 ( V_83 ) ;
}
F_69 ( V_81 ) ;
F_70 ( V_55 ) ;
return 0 ;
}
static BOOL T_25
F_71 ( T_26 V_97 )
{
F_58 ( V_90 , V_98 ,
L_112 ) ;
F_58 ( V_90 , V_91 ,
L_113 , V_97 ) ;
if ( V_17 || ( V_97 != V_99 ) ) {
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
F_73 ( T_11 V_100 )
{
if ( ! V_17 && V_100 ) {
fprintf ( V_19 , L_114 , V_93 . V_101 ) ;
fflush ( V_19 ) ;
}
}
static void
F_74 ( void )
{
F_73 ( V_102 ) ;
V_103 = FALSE ;
}
static void
F_75 ( int T_27 V_2 )
{
int V_104 = V_21 ;
if ( V_105 )
V_103 = TRUE ;
else
F_74 () ;
V_21 = V_104 ;
}
static void
F_76 ( int V_106 )
{
#ifdef F_6
F_77 () ;
#ifdef F_78
printf ( L_115 ) ;
F_79 () ;
#endif
#endif
exit ( V_106 ) ;
}
static void
F_80 ( void )
{
if ( F_81 () ) {
T_28 V_107 [ 2 ] = { V_108 , V_109 } ;
int V_110 = sizeof( V_107 ) / sizeof( T_28 ) ;
T_9 V_20 = F_24 () ;
F_22 ( L_116 ) ;
if ( F_82 ( V_111 , 1 , 0 , 0 , 0 ) == - 1 ) {
F_26 ( L_117 , F_27 ( V_21 ) ) ;
}
F_83 ( V_20 , V_112 , V_110 , V_107 , V_113 ) ;
F_83 ( V_20 , V_114 , V_110 , V_107 , V_113 ) ;
if ( F_25 ( V_20 ) ) {
F_26 ( L_63 , F_27 ( V_21 ) ) ;
}
F_22 ( L_118 ) ;
F_45 () ;
F_22 ( L_119 ) ;
F_83 ( V_20 , V_115 , V_110 , V_107 , V_113 ) ;
if ( F_25 ( V_20 ) ) {
F_26 ( L_63 , F_27 ( V_21 ) ) ;
}
F_22 ( L_120 ) ;
F_28 ( V_20 ) ;
}
}
static void
F_84 ( T_11 V_116 , struct V_117 * V_118 , struct V_119 * V_120 )
{
if ( V_116 ) {
V_120 -> V_121 = F_85 ( V_120 -> V_121 ) ;
V_120 -> V_122 = F_85 ( V_120 -> V_122 ) ;
V_120 -> V_123 = F_85 ( V_120 -> V_123 ) ;
V_120 -> V_124 = F_85 ( V_120 -> V_124 ) ;
}
if ( V_118 -> V_125 == 2 &&
( V_118 -> V_126 < 3 ||
( V_118 -> V_126 == 3 && V_120 -> V_123 > V_120 -> V_124 ) ) ) {
V_8 V_127 ;
V_127 = V_120 -> V_124 ;
V_120 -> V_124 = V_120 -> V_123 ;
V_120 -> V_123 = V_127 ;
}
}
static T_1
F_86 ( int V_128 , char * V_129 , T_10 V_130 , T_11 T_29 V_2 )
{
#ifdef F_6
if ( T_29 ) {
return F_87 ( V_128 , V_129 , ( int ) V_130 , 0 ) ;
} else {
return - 1 ;
}
#else
return F_88 ( V_128 , V_129 , V_130 ) ;
#endif
}
static void * F_89 ( void * V_131 )
{
T_30 * V_132 ;
#ifdef F_6
BOOL V_133 ;
T_26 V_134 , V_135 , V_136 ;
#else
T_10 V_136 ;
int V_134 ;
#endif
V_132 = ( T_30 * ) V_131 ;
while ( V_132 -> V_137 == V_138 ) {
F_90 ( V_132 -> V_139 ) ;
F_91 ( V_132 -> V_140 ) ;
V_136 = 0 ;
while ( V_136 < V_132 -> V_141 ) {
if ( ( V_132 -> V_142 )
#ifndef F_6
|| 1
#endif
)
{
V_134 = F_86 ( V_132 -> V_143 , V_132 -> V_144 + V_136 ,
V_132 -> V_141 - V_136 , V_132 -> V_142 ) ;
if ( V_134 <= 0 ) {
if ( V_134 == 0 ) {
V_132 -> V_137 = V_145 ;
V_136 = 0 ;
break;
} else {
V_132 -> V_137 = V_146 ;
V_136 = - 1 ;
break;
}
} else {
V_136 += V_134 ;
}
}
#ifdef F_6
else
{
V_133 = F_92 ( V_132 -> V_147 , V_132 -> V_144 + V_136 ,
V_132 -> V_141 - V_136 ,
& V_134 , NULL ) ;
V_136 += V_134 ;
if ( ! V_133 ) {
V_135 = F_93 () ;
if ( V_135 == V_148 ) {
continue;
} else if ( V_135 == V_149 || V_135 == V_150 || V_135 == V_151 ) {
V_132 -> V_137 = V_145 ;
V_136 = 0 ;
break;
}
V_132 -> V_137 = V_146 ;
V_136 = - 1 ;
break;
} else if ( V_134 == 0 && V_132 -> V_141 > 0 ) {
V_132 -> V_137 = V_145 ;
V_136 = 0 ;
break;
}
}
#endif
}
V_132 -> V_152 = V_136 ;
if ( V_132 -> V_152 >= V_132 -> V_141 ) {
F_94 ( V_132 -> V_153 , V_132 -> V_144 ) ;
}
F_95 ( V_132 -> V_140 ) ;
}
return NULL ;
}
static int
F_96 ( int V_128 )
{
T_31 V_154 ;
struct V_7 V_155 ;
F_97 ( & V_154 ) ;
F_98 ( V_128 , & V_154 ) ;
V_155 . V_11 = V_156 / 1000000 ;
V_155 . V_12 = V_156 % 1000000 ;
return F_99 ( V_128 + 1 , & V_154 , NULL , NULL , & V_155 ) ;
}
static int
F_100 ( char * V_157 , T_30 * V_132 , char * V_24 , int V_158 )
{
char * V_159 = V_157 + 4 ;
struct V_160 V_161 ;
char V_129 [ 16 ] ;
char * V_162 ;
unsigned long V_163 ;
T_10 V_48 ;
int V_1 ;
memset ( & V_161 , 0 , sizeof( V_161 ) ) ;
V_162 = strchr ( V_159 , ':' ) ;
if ( V_162 == NULL ) {
V_48 = strlen ( V_159 ) ;
V_163 = V_164 ;
}
else {
V_48 = V_162 - V_159 ;
V_163 = strtoul ( V_162 + 1 , & V_162 , 10 ) ;
if ( * V_162 || V_163 > 65535 ) {
goto V_165;
}
}
if ( V_48 > 15 ) {
goto V_165;
}
F_30 ( V_129 , ( V_30 ) V_48 + 1 , L_92 , V_159 ) ;
V_129 [ V_48 ] = '\0' ;
if ( ! F_101 ( V_129 , ( V_8 * ) & V_161 . V_166 ) ) {
goto V_165;
}
V_161 . V_167 = V_168 ;
V_161 . V_169 = F_102 ( ( V_170 ) V_163 ) ;
if ( ( ( V_1 = ( int ) F_103 ( V_168 , V_171 , 0 ) ) < 0 ) ||
( F_104 ( V_1 , (struct V_172 * ) & V_161 , sizeof( V_161 ) ) < 0 ) ) {
#ifdef F_6
T_32 V_173 = NULL ;
int V_174 ;
V_174 = F_105 () ;
F_106 ( V_175 |
V_176 |
V_177 ,
NULL , V_174 , F_107 ( V_178 , V_179 ) ,
( T_32 ) & V_173 , 0 , NULL ) ;
#endif
F_30 ( V_24 , V_158 ,
L_121
#ifdef F_6
L_122 , V_174 , V_173 ? ( char * ) V_173 : L_123 ) ;
if ( V_173 )
F_108 ( V_173 ) ;
#else
L_124 , V_21 , F_27 ( V_21 ) ) ;
#endif
V_132 -> V_137 = V_146 ;
if ( V_1 >= 0 )
F_109 ( V_1 , TRUE ) ;
return - 1 ;
}
void
F_109 ( int V_128 , T_11 T_29 V_2 )
{
#ifdef F_6
if ( T_29 ) {
F_110 ( V_128 ) ;
}
#else
F_4 ( V_128 ) ;
#endif
}
static void
F_111 ( char * V_157 ,
T_30 * V_132 ,
struct V_117 * V_118 ,
char * V_24 , int V_158 )
{
#ifndef F_6
T_33 V_180 ;
struct V_181 V_161 ;
#else
char * V_182 , * V_183 ;
T_34 * V_85 ;
T_15 V_41 ;
#ifdef F_54
char * V_184 ;
T_11 V_185 ;
#endif
#endif
T_1 V_134 ;
int V_1 = - 1 , V_186 ;
T_10 V_136 ;
V_8 V_187 = 0 ;
V_132 -> V_143 = - 1 ;
#ifdef F_6
V_132 -> V_147 = V_188 ;
#endif
F_58 ( V_90 , V_91 , L_125 , V_157 ) ;
if ( strcmp ( V_157 , L_126 ) == 0 ) {
#ifndef F_6
V_1 = 0 ;
#else
V_132 -> V_147 = F_112 ( V_189 ) ;
#endif
} else if ( ! strncmp ( V_157 , L_127 , 4 ) ) {
if ( ( V_1 = F_100 ( V_157 , V_132 , V_24 , V_158 ) ) < 0 ) {
return;
}
} else {
#ifndef F_6
if ( F_113 ( V_157 , & V_180 ) < 0 ) {
if ( V_21 == V_190 || V_21 == V_191 )
V_132 -> V_137 = V_192 ;
else {
F_30 ( V_24 , V_158 ,
L_128
L_129 , F_27 ( V_21 ) ) ;
V_132 -> V_137 = V_146 ;
}
return;
}
if ( F_114 ( V_180 . V_193 ) ) {
V_1 = F_2 ( V_157 , V_194 | V_195 , 0000 ) ;
if ( V_1 == - 1 ) {
F_30 ( V_24 , V_158 ,
L_128
L_130 , F_27 ( V_21 ) ) ;
V_132 -> V_137 = V_146 ;
return;
}
} else if ( F_115 ( V_180 . V_193 ) ) {
V_1 = F_103 ( V_196 , V_171 , 0 ) ;
if ( V_1 == - 1 ) {
F_30 ( V_24 , V_158 ,
L_128
L_131 , F_27 ( V_21 ) ) ;
V_132 -> V_137 = V_146 ;
return;
}
V_161 . V_197 = V_196 ;
if ( F_116 ( V_161 . V_198 , V_157 , sizeof V_161 . V_198 ) > sizeof V_161 . V_198 ) {
F_30 ( V_24 , V_158 ,
L_132
L_133 ) ;
V_132 -> V_137 = V_146 ;
F_4 ( V_1 ) ;
return;
}
V_134 = F_104 ( V_1 , (struct V_172 * ) & V_161 , sizeof V_161 ) ;
if ( V_134 == - 1 ) {
F_30 ( V_24 , V_158 ,
L_132
L_134 , F_27 ( V_21 ) ) ;
V_132 -> V_137 = V_146 ;
F_4 ( V_1 ) ;
return;
}
} else {
if ( F_117 ( V_180 . V_193 ) ) {
V_132 -> V_137 = V_192 ;
} else {
F_30 ( V_24 , V_158 ,
L_135
L_136 , V_157 ) ;
V_132 -> V_137 = V_146 ;
}
return;
}
#else
#define F_118 "\\pipe\\"
V_182 = F_63 ( V_157 ) ;
if ( ( V_183 = strstr ( V_182 , L_137 ) ) == V_182 ) {
V_183 = strchr ( V_182 + 3 , '\\' ) ;
if ( V_183 && F_119 ( V_183 , F_118 , strlen ( F_118 ) ) != 0 )
V_183 = NULL ;
}
F_20 ( V_182 ) ;
if ( ! V_183 ) {
F_30 ( V_24 , V_158 ,
L_135
L_138 , V_157 ) ;
V_132 -> V_137 = V_192 ;
return;
}
V_41 = F_37 ( V_199 . V_47 , T_15 , 0 ) ;
#ifdef F_54
V_184 = F_120 ( L_139 , V_200 , NULL ) ;
V_185 = strstr ( V_41 . V_50 , V_184 ) ? TRUE : FALSE ;
F_20 ( V_184 ) ;
#endif
while ( 1 ) {
#ifdef F_54
if( V_185 )
V_132 -> V_147 = F_112 ( V_189 ) ;
else
#endif
V_132 -> V_147 = F_121 ( F_122 ( V_157 ) , V_201 , 0 , NULL ,
V_202 , 0 , NULL ) ;
if ( V_132 -> V_147 != V_188 )
break;
if ( F_93 () != V_203 ) {
F_106 ( V_175 | V_176 | V_177 ,
NULL , F_93 () , 0 , ( T_32 ) & V_85 , 0 , NULL ) ;
F_30 ( V_24 , V_158 ,
L_140
L_141 ,
V_157 , F_123 ( V_85 ) , F_93 () ) ;
F_108 ( V_85 ) ;
V_132 -> V_137 = V_146 ;
return;
}
if ( ! F_124 ( F_122 ( V_157 ) , 30 * 1000 ) ) {
F_106 ( V_175 | V_176 | V_177 ,
NULL , F_93 () , 0 , ( T_32 ) & V_85 , 0 , NULL ) ;
F_30 ( V_24 , V_158 ,
L_142
L_143 ,
V_157 , F_123 ( V_85 ) , F_93 () ) ;
F_108 ( V_85 ) ;
V_132 -> V_137 = V_146 ;
return;
}
}
#endif
}
V_132 -> V_204 = TRUE ;
#ifdef F_6
if ( V_132 -> V_142 )
#endif
{
V_136 = 0 ;
while ( V_136 < sizeof V_187 ) {
if ( V_1 == - 1 ) {
F_30 ( V_24 , V_158 , L_144 ) ;
goto error;
}
V_186 = F_96 ( V_1 ) ;
if ( V_186 < 0 ) {
F_30 ( V_24 , V_158 ,
L_145 , F_27 ( V_21 ) ) ;
goto error;
} else if ( V_186 > 0 ) {
V_134 = F_86 ( V_1 , ( ( char * ) & V_187 ) + V_136 ,
sizeof V_187 - V_136 ,
V_132 -> V_142 ) ;
if ( V_134 <= 0 ) {
if ( V_134 == 0 )
F_30 ( V_24 , V_158 , L_146 ) ;
else
F_30 ( V_24 , V_158 , L_147 ,
F_27 ( V_21 ) ) ;
goto error;
}
V_136 += V_134 ;
}
}
}
#ifdef F_6
else {
#if F_125 ( 2 , 31 , 0 )
F_126 ( L_148 , & F_89 , V_132 ) ;
#else
F_127 ( & F_89 , V_132 , FALSE , NULL ) ;
#endif
V_132 -> V_144 = ( char * ) & V_187 ;
V_132 -> V_152 = 0 ;
V_132 -> V_141 = sizeof( V_187 ) ;
F_94 ( V_132 -> V_139 , V_132 -> V_144 ) ;
F_90 ( V_132 -> V_153 ) ;
if ( V_132 -> V_152 <= 0 ) {
if ( V_132 -> V_152 == 0 )
F_30 ( V_24 , V_158 , L_146 ) ;
else
F_30 ( V_24 , V_158 , L_147 ,
F_27 ( V_21 ) ) ;
goto error;
}
}
#endif
switch ( V_187 ) {
case V_205 :
case V_206 :
V_132 -> V_207 = FALSE ;
V_132 -> V_208 = FALSE ;
V_132 -> V_209 = V_187 == V_206 ;
break;
case V_210 :
V_132 -> V_207 = FALSE ;
V_132 -> V_208 = TRUE ;
break;
case V_211 :
case V_212 :
V_132 -> V_207 = TRUE ;
V_132 -> V_208 = FALSE ;
V_132 -> V_209 = V_187 == V_212 ;
break;
case V_213 :
V_132 -> V_207 = TRUE ;
V_132 -> V_208 = TRUE ;
break;
default:
F_30 ( V_24 , V_158 , L_149 ) ;
goto error;
}
#ifdef F_6
if ( V_132 -> V_142 )
#endif
{
V_136 = 0 ;
while ( V_136 < sizeof( struct V_117 ) ) {
V_186 = F_96 ( V_1 ) ;
if ( V_186 < 0 ) {
F_30 ( V_24 , V_158 ,
L_145 , F_27 ( V_21 ) ) ;
goto error;
} else if ( V_186 > 0 ) {
V_134 = F_86 ( V_1 , ( ( char * ) V_118 ) + V_136 ,
sizeof( struct V_117 ) - V_136 ,
V_132 -> V_142 ) ;
if ( V_134 <= 0 ) {
if ( V_134 == 0 )
F_30 ( V_24 , V_158 , L_150 ) ;
else
F_30 ( V_24 , V_158 , L_151 ,
F_27 ( V_21 ) ) ;
goto error;
}
V_136 += V_134 ;
}
}
}
#ifdef F_6
else {
V_132 -> V_144 = ( char * ) V_118 ;
V_132 -> V_152 = 0 ;
V_132 -> V_141 = sizeof( struct V_117 ) ;
F_94 ( V_132 -> V_139 , V_132 -> V_144 ) ;
F_90 ( V_132 -> V_153 ) ;
if ( V_132 -> V_152 <= 0 ) {
if ( V_132 -> V_152 == 0 )
F_30 ( V_24 , V_158 , L_150 ) ;
else
F_30 ( V_24 , V_158 , L_152 ,
F_27 ( V_21 ) ) ;
goto error;
}
}
#endif
if ( V_132 -> V_207 ) {
V_118 -> V_125 = F_128 ( V_118 -> V_125 ) ;
V_118 -> V_126 = F_128 ( V_118 -> V_126 ) ;
V_118 -> V_214 = F_85 ( V_118 -> V_214 ) ;
V_118 -> V_215 = F_85 ( V_118 -> V_215 ) ;
}
V_132 -> V_51 = V_118 -> V_215 ;
if ( V_118 -> V_125 < 2 ) {
F_30 ( V_24 , V_158 , L_153 ) ;
goto error;
}
V_132 -> V_216 = V_217 ;
V_132 -> V_137 = V_138 ;
V_132 -> V_143 = V_1 ;
return;
error:
F_58 ( V_90 , V_91 , L_154 , V_24 ) ;
V_132 -> V_137 = V_146 ;
F_109 ( V_1 , V_132 -> V_142 ) ;
V_132 -> V_143 = - 1 ;
}
static int
F_129 ( T_35 * V_218 , T_30 * V_132 , T_36 * V_62 , char * V_24 , int V_158 )
{
struct V_219 V_220 ;
enum { V_221 , V_222 , V_223 , V_224 ,
V_225 } V_226 ;
#ifdef F_6
#if ! F_125 ( 2 , 31 , 18 )
T_37 V_227 ;
#endif
T_38 V_228 ;
T_34 * V_85 ;
#endif
T_1 V_134 ;
#ifdef F_130
F_58 ( V_90 , V_91 , L_155 ) ;
#endif
switch ( V_132 -> V_216 ) {
case V_217 :
#ifdef F_6
if ( F_131 ( V_132 -> V_140 ) ) {
#endif
V_132 -> V_216 = V_229 ;
V_132 -> V_141 = V_132 -> V_208 ?
sizeof( struct V_230 ) : sizeof( struct V_119 ) ;
V_132 -> V_152 = 0 ;
#ifdef F_6
V_132 -> V_144 = ( char * ) & V_132 -> V_231 ;
F_94 ( V_132 -> V_139 , V_132 -> V_144 ) ;
F_95 ( V_132 -> V_140 ) ;
}
#endif
case V_229 :
#ifdef F_6
if ( V_132 -> V_142 )
#endif
{
V_134 = F_86 ( V_132 -> V_143 , ( ( char * ) & V_132 -> V_231 ) + V_132 -> V_152 ,
V_132 -> V_141 - V_132 -> V_152 , V_132 -> V_142 ) ;
if ( V_134 <= 0 ) {
if ( V_134 == 0 )
V_226 = V_223 ;
else
V_226 = V_224 ;
break;
}
V_132 -> V_152 += V_134 ;
}
#ifdef F_6
else {
#if F_125 ( 2 , 31 , 18 )
V_228 = F_132 ( V_132 -> V_153 , V_156 ) ;
#else
F_133 ( & V_227 ) ;
F_134 ( & V_227 , V_156 ) ;
V_228 = F_135 ( V_132 -> V_153 , & V_227 ) ;
#endif
if ( V_132 -> V_137 == V_145 ) {
V_226 = V_223 ;
break;
} else if ( V_132 -> V_137 == V_146 ) {
V_226 = V_224 ;
break;
}
if ( ! V_228 ) {
return 0 ;
}
}
#endif
if ( V_132 -> V_152 < V_132 -> V_141 )
return 0 ;
V_226 = V_221 ;
break;
case V_232 :
#ifdef F_6
if ( F_131 ( V_132 -> V_140 ) ) {
#endif
V_132 -> V_216 = V_233 ;
V_132 -> V_141 = V_132 -> V_231 . V_118 . V_123 ;
V_132 -> V_152 = 0 ;
#ifdef F_6
V_132 -> V_144 = ( char * ) V_62 ;
F_94 ( V_132 -> V_139 , V_132 -> V_144 ) ;
F_95 ( V_132 -> V_140 ) ;
}
#endif
case V_233 :
#ifdef F_6
if ( V_132 -> V_142 )
#endif
{
V_134 = F_86 ( V_132 -> V_143 ,
V_62 + V_132 -> V_152 ,
V_132 -> V_141 - V_132 -> V_152 ,
V_132 -> V_142 ) ;
if ( V_134 <= 0 ) {
if ( V_134 == 0 )
V_226 = V_223 ;
else
V_226 = V_224 ;
break;
}
V_132 -> V_152 += V_134 ;
}
#ifdef F_6
else {
#if F_125 ( 2 , 31 , 18 )
V_228 = F_132 ( V_132 -> V_153 , V_156 ) ;
#else
F_133 ( & V_227 ) ;
F_134 ( & V_227 , V_156 ) ;
V_228 = F_135 ( V_132 -> V_153 , & V_227 ) ;
#endif
if ( V_132 -> V_137 == V_145 ) {
V_226 = V_223 ;
break;
} else if ( V_132 -> V_137 == V_146 ) {
V_226 = V_224 ;
break;
}
if ( ! V_228 ) {
return 0 ;
}
}
#endif
if ( V_132 -> V_152 < V_132 -> V_141 )
return 0 ;
V_226 = V_222 ;
break;
default:
F_30 ( V_24 , V_158 , L_156 ) ;
V_226 = V_225 ;
}
switch ( V_226 ) {
case V_221 :
F_84 ( V_132 -> V_207 , & V_132 -> V_234 ,
& V_132 -> V_231 . V_118 ) ;
if ( V_132 -> V_231 . V_118 . V_123 > V_235 ) {
F_30 ( V_24 , V_158 , L_157 ,
V_218 -> V_101 + 1 , V_132 -> V_231 . V_118 . V_123 ) ;
break;
}
if ( V_132 -> V_231 . V_118 . V_123 ) {
V_132 -> V_216 = V_232 ;
return 0 ;
}
case V_222 :
V_220 . V_236 . V_11 = V_132 -> V_231 . V_118 . V_121 ;
V_220 . V_236 . V_12 = V_132 -> V_231 . V_118 . V_122 ;
V_220 . V_237 = V_132 -> V_231 . V_118 . V_123 ;
V_220 . V_48 = V_132 -> V_231 . V_118 . V_124 ;
if ( V_238 ) {
F_136 ( ( V_239 * ) V_132 , & V_220 , V_62 ) ;
} else {
F_137 ( ( V_239 * ) V_132 , & V_220 , V_62 ) ;
}
V_132 -> V_216 = V_217 ;
return 1 ;
case V_223 :
V_132 -> V_137 = V_145 ;
return - 1 ;
case V_224 :
#ifdef F_6
F_106 ( V_175 | V_176 | V_177 ,
NULL , F_93 () , 0 , ( T_32 ) & V_85 , 0 , NULL ) ;
F_30 ( V_24 , V_158 ,
L_158 ,
F_123 ( V_85 ) , F_93 () ) ;
F_108 ( V_85 ) ;
#else
F_30 ( V_24 , V_158 , L_159 ,
F_27 ( V_21 ) ) ;
#endif
case V_225 :
break;
}
V_132 -> V_137 = V_146 ;
return - 1 ;
}
static void F_138 ( T_35 * V_218 )
{
T_17 V_45 ;
T_30 * V_132 ;
F_58 ( V_90 , V_91 , L_160 ) ;
for ( V_45 = 0 ; V_45 < V_218 -> V_240 -> V_48 ; V_45 ++ ) {
V_132 = F_37 ( V_218 -> V_240 , T_30 * , V_45 ) ;
if ( V_132 -> V_143 >= 0 ) {
F_139 ( V_132 -> V_204 ) ;
F_109 ( V_132 -> V_143 , V_132 -> V_142 ) ;
V_132 -> V_143 = - 1 ;
}
#ifdef F_6
if ( V_132 -> V_147 != V_188 ) {
F_140 ( V_132 -> V_147 ) ;
V_132 -> V_147 = V_188 ;
}
#endif
if ( V_132 -> V_32 != NULL ) {
F_58 ( V_90 , V_91 , L_161 , ( void * ) V_132 -> V_32 ) ;
F_41 ( V_132 -> V_32 ) ;
V_132 -> V_32 = NULL ;
}
}
V_218 -> V_94 = FALSE ;
#ifdef F_6
F_77 () ;
#endif
}
static T_39
F_141 ( T_12 * V_32 , T_11 V_204 ,
const T_7 * V_50 , const T_7 * V_35 )
{
struct V_33 V_34 ;
F_58 ( V_90 , V_91 , L_162 , V_35 ) ;
if ( V_35 && ! V_204 ) {
if ( ! F_31 ( V_50 , V_32 , & V_34 , V_35 ) ) {
return V_241 ;
}
if ( F_142 ( V_32 , & V_34 ) < 0 ) {
#ifdef F_143
F_144 ( & V_34 ) ;
#endif
return V_242 ;
}
#ifdef F_143
F_144 ( & V_34 ) ;
#endif
}
return V_243 ;
}
static T_11
F_145 ( T_14 * V_40 , T_35 * V_218 , char * V_24 , int V_25 )
{
int V_84 ;
T_17 V_45 ;
T_30 * V_132 ;
T_15 V_41 ;
T_11 V_244 ;
F_58 ( V_90 , V_91 , L_163 ) ;
if ( ( V_40 -> V_245 == FALSE ) &&
( V_40 -> V_47 -> V_48 > 1 ) ) {
F_30 ( V_24 , V_25 ,
L_164 ) ;
return FALSE ;
}
if ( V_40 -> V_246 ) {
V_218 -> V_247 = F_146 ( & V_84 ) ;
} else {
V_218 -> V_247 = F_147 ( V_218 -> V_248 , L_165 ) ;
if ( V_218 -> V_247 == NULL ) {
V_84 = V_21 ;
}
}
if ( V_218 -> V_247 ) {
if ( V_40 -> V_245 ) {
char * V_249 ;
T_40 * V_250 ;
V_250 = F_148 ( L_60 ) ;
F_149 ( V_250 ) ;
V_249 = F_150 ( L_166 , F_151 () ) ;
V_244 = F_152 ( V_218 -> V_247 ,
( const char * ) V_40 -> V_251 ,
NULL ,
V_250 -> V_252 ,
V_249 ,
- 1 ,
& V_218 -> V_253 ,
& V_84 ) ;
F_20 ( V_249 ) ;
for ( V_45 = 0 ; V_244 && ( V_45 < V_40 -> V_47 -> V_48 ) ; V_45 ++ ) {
V_41 = F_37 ( V_40 -> V_47 , T_15 , V_45 ) ;
V_132 = F_37 ( V_218 -> V_240 , T_30 * , V_45 ) ;
if ( V_132 -> V_204 ) {
V_132 -> V_214 = V_132 -> V_234 . V_214 ;
} else {
V_132 -> V_214 = F_153 ( V_132 -> V_32 ) ;
}
V_244 = F_154 ( V_93 . V_247 ,
NULL ,
V_41 . V_50 ,
V_41 . V_254 ,
V_41 . V_35 ,
V_250 -> V_252 ,
V_132 -> V_51 ,
V_132 -> V_214 ,
& ( V_93 . V_253 ) ,
0 ,
V_132 -> V_209 ? 9 : 6 ,
& V_93 . V_84 ) ;
}
F_155 ( V_250 , TRUE ) ;
} else {
V_132 = F_37 ( V_218 -> V_240 , T_30 * , 0 ) ;
if ( V_132 -> V_204 ) {
V_132 -> V_214 = V_132 -> V_234 . V_214 ;
} else {
V_132 -> V_214 = F_153 ( V_132 -> V_32 ) ;
}
V_244 = F_156 ( V_218 -> V_247 , V_132 -> V_51 , V_132 -> V_214 ,
V_132 -> V_209 , & V_218 -> V_253 , & V_84 ) ;
}
if ( ! V_244 ) {
fclose ( V_218 -> V_247 ) ;
V_218 -> V_247 = NULL ;
}
}
if ( V_218 -> V_247 == NULL ) {
switch ( V_84 ) {
default:
if ( V_84 < 0 ) {
F_30 ( V_24 , V_25 ,
L_167
L_168 ,
V_40 -> V_255 , V_84 ) ;
} else {
F_30 ( V_24 , V_25 ,
L_167
L_169 ,
V_40 -> V_255 , F_27 ( V_84 ) ) ;
}
break;
}
return FALSE ;
}
return TRUE ;
}
static T_11
F_157 ( T_14 * V_40 , T_35 * V_218 , int * V_256 )
{
unsigned int V_45 ;
T_30 * V_132 ;
T_3 V_257 = F_5 () ;
F_58 ( V_90 , V_91 , L_170 ) ;
if ( V_40 -> V_246 ) {
return F_158 ( & V_40 -> V_255 , V_256 ) ;
} else {
if ( V_40 -> V_245 ) {
for ( V_45 = 0 ; V_45 < V_93 . V_240 -> V_48 ; V_45 ++ ) {
V_132 = F_37 ( V_93 . V_240 , T_30 * , V_45 ) ;
if ( ! V_132 -> V_204 ) {
T_3 V_258 , V_259 ;
struct V_88 V_260 ;
if ( F_65 ( V_132 -> V_32 , & V_260 ) >= 0 ) {
V_258 = V_132 -> V_261 ;
V_259 = V_260 . V_96 + V_132 -> V_262 + V_132 -> V_263 ;
} else {
V_258 = V_264 ;
V_259 = V_264 ;
}
F_159 ( V_218 -> V_247 ,
V_45 ,
& V_218 -> V_253 ,
L_171 ,
V_265 ,
V_257 ,
V_258 ,
V_259 ,
V_256 ) ;
}
}
}
if ( fclose ( V_218 -> V_247 ) == V_266 ) {
if ( V_256 != NULL ) {
* V_256 = V_21 ;
}
return ( FALSE ) ;
} else {
return ( TRUE ) ;
}
}
}
static int
F_160 ( T_35 * V_218 ,
char * V_24 , int V_25 , T_30 * V_132 )
{
int V_267 ;
T_41 V_268 ;
T_36 V_269 [ V_235 ] ;
#ifndef F_6
int V_186 ;
#endif
V_268 = V_218 -> V_101 ;
if ( V_132 -> V_204 ) {
#ifdef F_130
F_58 ( V_90 , V_91 , L_172 ) ;
#endif
#ifndef F_6
V_186 = F_96 ( V_132 -> V_143 ) ;
if ( V_186 <= 0 ) {
if ( V_186 < 0 && V_21 != V_270 ) {
F_30 ( V_24 , V_25 ,
L_145 , F_27 ( V_21 ) ) ;
F_39 ( V_24 , V_271 ) ;
V_218 -> V_94 = FALSE ;
}
} else {
#endif
V_267 = F_129 ( V_218 , V_132 , V_269 , V_24 , V_25 ) ;
if ( V_267 < 0 ) {
V_218 -> V_94 = FALSE ;
}
#ifndef F_6
}
#endif
}
else
{
#ifdef F_161
#ifdef F_130
F_58 ( V_90 , V_91 , L_173 ) ;
#endif
if ( V_132 -> V_272 != - 1 ) {
V_186 = F_96 ( V_132 -> V_272 ) ;
if ( V_186 > 0 ) {
if ( V_238 ) {
V_267 = F_162 ( V_132 -> V_32 , 1 , F_136 , ( V_239 * ) V_132 ) ;
} else {
V_267 = F_162 ( V_132 -> V_32 , 1 , F_137 , ( V_239 * ) V_132 ) ;
}
if ( V_267 < 0 ) {
if ( V_267 == - 1 ) {
V_132 -> V_273 = TRUE ;
}
V_218 -> V_94 = FALSE ;
}
} else {
if ( V_186 < 0 && V_21 != V_270 ) {
F_30 ( V_24 , V_25 ,
L_145 , F_27 ( V_21 ) ) ;
F_39 ( V_24 , V_271 ) ;
V_218 -> V_94 = FALSE ;
}
}
}
else
#endif
{
#if 1
#ifdef F_130
F_58 ( V_90 , V_91 , L_174 ) ;
#endif
#ifdef F_6
if ( V_238 ) {
V_267 = F_162 ( V_132 -> V_32 , 1 , F_136 , ( V_239 * ) V_132 ) ;
} else {
V_267 = F_162 ( V_132 -> V_32 , 1 , F_137 , ( V_239 * ) V_132 ) ;
}
#else
if ( V_238 ) {
V_267 = F_162 ( V_132 -> V_32 , - 1 , F_136 , ( V_239 * ) V_132 ) ;
} else {
V_267 = F_162 ( V_132 -> V_32 , - 1 , F_137 , ( V_239 * ) V_132 ) ;
}
#endif
if ( V_267 < 0 ) {
if ( V_267 == - 1 ) {
V_132 -> V_273 = TRUE ;
}
V_218 -> V_94 = FALSE ;
}
#else
#ifdef F_130
F_58 ( V_90 , V_91 , L_175 ) ;
#endif
{
int V_274 ;
struct V_219 * V_275 ;
V_239 * V_276 ;
V_274 = 0 ;
while( V_218 -> V_94 &&
( V_274 = F_163 ( V_132 -> V_32 , & V_275 , & V_276 ) ) == 1 ) {
if ( V_238 ) {
F_136 ( ( V_239 * ) V_132 , V_275 , V_276 ) ;
} else {
F_137 ( ( V_239 * ) V_132 , V_275 , V_276 ) ;
}
}
if ( V_274 < 0 ) {
V_132 -> V_273 = TRUE ;
V_218 -> V_94 = FALSE ;
}
}
#endif
}
}
#ifdef F_130
F_58 ( V_90 , V_91 , L_176 , V_267 , F_164 ( V_267 , L_60 , L_177 ) ) ;
#endif
return V_218 -> V_101 - V_268 ;
}
static T_40 *
F_165 ( const char * V_23 )
{
T_7 * V_277 ;
T_40 * V_278 ;
V_277 = strchr ( V_23 , '{' ) ;
if ( V_277 == NULL )
return F_148 ( V_23 ) ;
V_278 = F_148 ( V_277 + 1 ) ;
V_277 = strchr ( V_278 -> V_252 , '}' ) ;
if ( V_277 == NULL )
return V_278 ;
V_278 = F_166 ( V_278 , V_277 - V_278 -> V_252 ) ;
return V_278 ;
}
static T_11
F_167 ( T_14 * V_40 , int * V_248 ,
char * V_24 , int V_25 )
{
char * V_279 ;
T_7 * V_280 ;
T_7 * V_281 , * V_282 ;
T_11 V_283 ;
F_58 ( V_90 , V_91 , L_178 ,
( V_40 -> V_255 ) ? V_40 -> V_255 : L_179 ) ;
if ( V_40 -> V_255 != NULL ) {
V_280 = F_63 ( V_40 -> V_255 ) ;
if ( V_40 -> V_284 == TRUE ) {
if ( V_40 -> V_246 ) {
F_30 ( V_24 , V_25 ,
L_180 ) ;
F_20 ( V_280 ) ;
return FALSE ;
}
if ( strcmp ( V_280 , L_126 ) == 0 ) {
* V_248 = 1 ;
#ifdef F_6
F_168 ( 1 , V_285 ) ;
#endif
}
}
else {
if ( V_40 -> V_246 ) {
* V_248 = F_169 ( V_280 ,
( V_40 -> V_286 ) ? V_40 -> V_287 : 0 ,
V_40 -> V_288 ) ;
if ( * V_248 != - 1 ) {
F_20 ( V_280 ) ;
V_280 = F_63 ( F_170 () ) ;
}
} else {
* V_248 = F_2 ( V_280 , V_289 | V_285 | V_290 | V_291 ,
( V_40 -> V_288 ) ? 0640 : 0600 ) ;
}
}
V_283 = FALSE ;
} else {
if ( V_199 . V_47 -> V_48 > 1 ) {
V_281 = F_150 ( L_181 , V_199 . V_47 -> V_48 ) ;
if ( V_40 -> V_245 ) {
V_282 = L_182 ;
} else{
V_282 = L_183 ;
}
} else {
T_7 * V_292 ;
V_292 = F_171 ( F_37 ( V_199 . V_47 , T_15 , 0 ) . V_293 ) ;
#ifdef F_6
if ( strncmp ( L_184 , V_292 , 5 ) == 0 )
{
T_40 * V_23 ;
V_23 = F_165 ( V_292 ) ;
F_20 ( V_292 ) ;
V_292 = F_63 ( V_23 -> V_252 ) ;
F_155 ( V_23 , TRUE ) ;
}
#endif
if ( V_40 -> V_245 ) {
V_281 = F_120 ( L_185 , V_292 , NULL ) ;
V_282 = L_182 ;
} else{
V_281 = F_120 ( L_185 , V_292 , NULL ) ;
V_282 = L_183 ;
}
F_20 ( V_292 ) ;
}
* V_248 = F_172 ( & V_279 , V_281 , V_282 ) ;
F_20 ( V_281 ) ;
V_280 = F_63 ( V_279 ) ;
V_283 = TRUE ;
}
if ( * V_248 == - 1 ) {
if ( V_283 ) {
F_30 ( V_24 , V_25 ,
L_186
L_187 , V_280 , F_27 ( V_21 ) ) ;
} else {
if ( V_40 -> V_246 ) {
F_173 () ;
}
F_30 ( V_24 , V_25 ,
L_188
L_187 , V_280 ,
F_27 ( V_21 ) ) ;
}
F_20 ( V_280 ) ;
return FALSE ;
}
if ( V_40 -> V_255 != NULL ) {
F_20 ( V_40 -> V_255 ) ;
}
V_40 -> V_255 = V_280 ;
return TRUE ;
}
static T_11
F_174 ( T_14 * V_40 ,
T_42 * V_294 ,
T_42 * V_295 ,
T_42 * V_296 )
{
T_17 V_45 ;
T_30 * V_132 ;
T_15 V_41 ;
T_11 V_244 ;
if ( V_40 -> V_246 ) {
if ( V_294 != NULL &&
F_175 ( V_294 , ( T_3 ) ++ V_93 . V_297 ) ) {
V_93 . V_94 = FALSE ;
return FALSE ;
}
if ( F_176 ( & V_93 . V_247 , & V_40 -> V_255 ,
& V_93 . V_248 , & V_93 . V_84 ) ) {
V_93 . V_253 = 0 ;
if ( V_40 -> V_245 ) {
char * V_249 ;
T_40 * V_250 ;
V_250 = F_148 ( L_60 ) ;
F_149 ( V_250 ) ;
V_249 = F_150 ( L_166 , F_151 () ) ;
V_244 = F_152 ( V_93 . V_247 ,
NULL ,
NULL ,
V_250 -> V_252 ,
V_249 ,
- 1 ,
& ( V_93 . V_253 ) ,
& V_93 . V_84 ) ;
F_20 ( V_249 ) ;
for ( V_45 = 0 ; V_244 && ( V_45 < V_40 -> V_47 -> V_48 ) ; V_45 ++ ) {
V_41 = F_37 ( V_40 -> V_47 , T_15 , V_45 ) ;
V_132 = F_37 ( V_93 . V_240 , T_30 * , V_45 ) ;
V_244 = F_154 ( V_93 . V_247 ,
NULL ,
V_41 . V_50 ,
V_41 . V_254 ,
V_41 . V_35 ,
V_250 -> V_252 ,
V_132 -> V_51 ,
V_132 -> V_214 ,
& ( V_93 . V_253 ) ,
0 ,
V_132 -> V_209 ? 9 : 6 ,
& V_93 . V_84 ) ;
}
F_155 ( V_250 , TRUE ) ;
} else {
V_132 = F_37 ( V_93 . V_240 , T_30 * , 0 ) ;
V_244 = F_156 ( V_93 . V_247 , V_132 -> V_51 , V_132 -> V_214 ,
V_132 -> V_209 , & V_93 . V_253 , & V_93 . V_84 ) ;
}
if ( ! V_244 ) {
fclose ( V_93 . V_247 ) ;
V_93 . V_247 = NULL ;
V_93 . V_94 = FALSE ;
return FALSE ;
}
if ( V_295 )
F_177 ( V_295 ) ;
if ( V_296 )
F_177 ( V_296 ) ;
fflush ( V_93 . V_247 ) ;
if ( ! V_102 )
F_178 ( V_93 . V_298 ) ;
V_93 . V_298 = 0 ;
F_179 ( V_40 -> V_255 ) ;
} else {
V_93 . V_94 = FALSE ;
return FALSE ;
}
} else {
V_93 . V_94 = FALSE ;
return FALSE ;
}
return TRUE ;
}
static void *
F_180 ( void * V_131 )
{
T_30 * V_132 ;
char V_24 [ V_42 + 1 ] ;
V_132 = ( T_30 * ) V_131 ;
F_58 ( V_90 , V_98 , L_189 ,
V_132 -> V_299 ) ;
while ( V_93 . V_94 ) {
F_160 ( & V_93 , V_24 , sizeof( V_24 ) , V_132 ) ;
}
F_58 ( V_90 , V_98 , L_190 ,
V_132 -> V_299 ) ;
F_181 ( NULL ) ;
return ( NULL ) ;
}
static void
F_72 ( void )
{
#ifdef F_182
T_17 V_45 ;
T_30 * V_132 ;
for ( V_45 = 0 ; V_45 < V_93 . V_240 -> V_48 ; V_45 ++ ) {
V_132 = F_37 ( V_93 . V_240 , T_30 * , V_45 ) ;
if ( V_132 -> V_32 != NULL )
F_183 ( V_132 -> V_32 ) ;
}
#endif
V_93 . V_94 = FALSE ;
}
static void
F_184 ( char * V_24 , int V_300 , const char * V_301 ,
int V_84 , T_11 V_302 )
{
switch ( V_84 ) {
case V_303 :
F_30 ( V_24 , V_300 ,
L_191
L_192
L_193
L_194 ,
V_301 ) ;
break;
#ifdef F_185
case F_185 :
F_30 ( V_24 , V_300 ,
L_191
L_192
L_195
L_196
L_197 ,
V_301 ) ;
break;
#endif
default:
if ( V_302 ) {
F_30 ( V_24 , V_300 ,
L_198
L_199 ,
V_301 , F_27 ( V_84 ) ) ;
} else {
F_30 ( V_24 , V_300 ,
L_200
L_192
L_201 ,
V_301 , F_27 ( V_84 ) ) ;
}
break;
}
}
static void
F_137 ( V_239 * V_304 , const struct V_219 * V_220 ,
const V_239 * V_305 )
{
T_30 * V_132 = ( T_30 * ) ( void * ) V_304 ;
int V_84 ;
T_17 V_306 = V_132 -> V_209 ? 1000000000 : 1000000 ;
if ( ! V_93 . V_94 ) {
V_132 -> V_263 ++ ;
return;
}
if ( V_93 . V_247 ) {
T_11 V_244 ;
if ( V_199 . V_245 ) {
V_244 = F_186 ( V_93 . V_247 ,
NULL ,
V_220 -> V_236 . V_11 , ( V_307 ) V_220 -> V_236 . V_12 ,
V_220 -> V_237 , V_220 -> V_48 ,
V_132 -> V_299 ,
V_306 ,
V_305 , 0 ,
& V_93 . V_253 , & V_84 ) ;
} else {
V_244 = F_187 ( V_93 . V_247 ,
V_220 -> V_236 . V_11 , ( V_307 ) V_220 -> V_236 . V_12 ,
V_220 -> V_237 , V_220 -> V_48 ,
V_305 ,
& V_93 . V_253 , & V_84 ) ;
}
if ( ! V_244 ) {
V_93 . V_94 = FALSE ;
V_93 . V_84 = V_84 ;
V_132 -> V_262 ++ ;
} else {
#if F_188 ( F_78 ) || F_188 ( V_308 )
F_58 ( V_90 , V_98 ,
L_202 ,
V_220 -> V_237 , V_132 -> V_299 ) ;
#endif
V_93 . V_101 ++ ;
V_132 -> V_261 ++ ;
if ( ( V_93 . V_309 > 0 ) && ( V_93 . V_101 >= V_93 . V_309 ) ) {
V_93 . V_94 = FALSE ;
}
}
}
}
static void
F_136 ( V_239 * V_304 , const struct V_219 * V_220 ,
const V_239 * V_305 )
{
T_30 * V_132 = ( T_30 * ) ( void * ) V_304 ;
T_43 * V_310 ;
T_11 V_311 ;
if ( ! V_93 . V_94 ) {
V_132 -> V_263 ++ ;
return;
}
V_310 = ( T_43 * ) F_62 ( sizeof( T_43 ) ) ;
if ( V_310 == NULL ) {
V_132 -> V_262 ++ ;
return;
}
V_310 -> V_132 = V_132 ;
V_310 -> V_220 = * V_220 ;
V_310 -> V_305 = ( V_239 * ) F_62 ( V_220 -> V_237 ) ;
if ( V_310 -> V_305 == NULL ) {
V_132 -> V_262 ++ ;
F_20 ( V_310 ) ;
return;
}
memcpy ( V_310 -> V_305 , V_305 , V_220 -> V_237 ) ;
F_189 ( V_312 ) ;
if ( ( ( V_313 == 0 ) || ( V_314 < V_313 ) ) &&
( ( V_315 == 0 ) || ( V_316 < V_315 ) ) ) {
V_311 = FALSE ;
F_190 ( V_312 , V_310 ) ;
V_314 += V_220 -> V_237 ;
V_316 += 1 ;
} else {
V_311 = TRUE ;
}
F_191 ( V_312 ) ;
if ( V_311 ) {
V_132 -> V_262 ++ ;
F_20 ( V_310 -> V_305 ) ;
F_20 ( V_310 ) ;
F_58 ( V_90 , V_98 ,
L_203 ,
V_220 -> V_237 , V_132 -> V_299 ) ;
} else {
V_132 -> V_261 ++ ;
F_58 ( V_90 , V_98 ,
L_204 ,
V_220 -> V_237 , V_132 -> V_299 ) ;
}
F_58 ( V_90 , V_98 ,
L_205 V_317 L_206 V_317 L_207 ,
V_314 , V_316 ) ;
}
static int
F_192 ( const char * V_23 , const char * V_318 )
{
int V_319 = 0 ;
int type = - 1 ;
int V_320 = - 1 ;
int V_321 = - 1 ;
int args ;
int V_322 ;
T_7 * * V_323 = NULL ;
V_323 = F_193 ( V_318 , L_91 , 4 ) ;
for ( args = 0 ; V_323 [ args ] ; args ++ ) ;
if ( V_323 [ 0 ] )
V_319 = atoi ( V_323 [ 0 ] ) ;
if ( args >= 1 && V_323 [ 1 ] ) {
type = F_194 ( V_323 [ 1 ] ) ;
if ( type == - 1 ) {
V_322 = V_324 ;
goto V_325;
}
}
if ( args >= 2 && V_323 [ 2 ] )
V_320 = atoi ( V_323 [ 2 ] ) ;
if ( args >= 3 && V_323 [ 3 ] )
V_321 = atoi ( V_323 [ 3 ] ) ;
V_322 = F_195 () ;
if ( V_322 ) {
F_26 ( L_208 , abs ( V_322 ) , F_27 ( abs ( V_322 ) ) ) ;
V_322 = 2 ;
goto V_325;
}
V_322 = F_196 ( V_23 , V_319 , type , V_320 , V_321 ) ;
if ( V_322 ) {
F_26 ( L_209 , abs ( V_322 ) , F_27 ( abs ( V_322 ) ) ) ;
V_322 = 2 ;
goto V_325;
}
if ( V_17 )
F_46 ( 2 , V_54 , NULL ) ;
V_322 = 0 ;
V_325:
F_197 ( V_323 ) ;
return V_322 ;
}
static void
F_198 ( T_40 * V_252 )
{
F_199 ( V_252 , L_210 ) ;
F_200 ( V_252 ) ;
}
static void
F_201 ( T_40 * V_252 )
{
F_199 ( V_252 , L_210 ) ;
F_202 ( V_252 ) ;
}
int
main ( int V_326 , char * V_327 [] )
{
T_40 * V_328 ;
T_40 * V_329 ;
int V_318 ;
static const struct V_330 V_331 [] = {
{ L_211 , V_332 , NULL , 'h' } ,
{ L_212 , V_332 , NULL , 'v' } ,
V_333
{ 0 , 0 , 0 , 0 }
} ;
T_11 V_334 = FALSE ;
#ifdef F_6
T_44 V_335 ;
#else
struct V_336 V_337 , V_338 ;
#endif
T_11 V_339 = TRUE ;
T_11 V_340 ;
struct V_88 V_260 ;
T_45 V_341 ;
T_11 V_342 = FALSE ;
T_11 V_343 = FALSE ;
#ifdef F_13
T_11 V_344 = FALSE ;
#endif
T_11 V_345 = FALSE ;
T_7 * V_346 = NULL ;
T_11 V_80 = FALSE ;
T_11 V_347 = FALSE ;
int V_106 , V_348 = 0 ;
T_41 V_45 ;
T_17 V_46 ;
#if F_188 ( V_349 ) && F_188 ( V_350 )
struct V_351 V_352 ;
#endif
T_40 * V_252 ;
F_203 ( F_17 , F_21 ) ;
V_328 = F_204 ( NULL , F_198 ) ;
V_329 = F_205 ( F_201 ) ;
F_206 ( L_213
L_4
L_92
L_4
L_92 ,
F_151 () , V_328 -> V_252 , V_329 -> V_252 ) ;
#ifdef F_6
F_207 ( V_326 , V_327 ) ;
F_208 () ;
F_209 () ;
#endif
#ifdef F_13
#define F_210 "d"
#else
#define F_210 ""
#endif
#ifdef F_14
#define F_211 "r"
#define F_212 "u"
#else
#define F_211 ""
#define F_212 ""
#endif
#ifdef F_15
#define F_213 "m:"
#else
#define F_213 ""
#endif
#define F_214 OPTSTRING_CAPTURE_COMMON "C:" OPTSTRING_d "gh" "k:" OPTSTRING_m "MN:nPq" OPTSTRING_r "St" OPTSTRING_u "vw:Z:"
#ifdef V_308
if ( ( V_353 = F_215 ( L_214 , L_215 ) ) == NULL ) {
fprintf ( V_19 , L_216 ) ;
exit ( 1 ) ;
}
#endif
#if F_188 ( V_349 ) && F_188 ( V_350 )
if ( F_216 ( & V_352 ) == 0 ) {
if ( strcmp ( V_352 . V_354 , L_217 ) == 0 ||
strcmp ( V_352 . V_354 , L_218 ) == 0 ||
strcmp ( V_352 . V_354 , L_219 ) == 0 )
V_355 = TRUE ;
}
#endif
for ( V_45 = 1 ; V_45 < V_326 ; V_45 ++ ) {
if ( strcmp ( L_220 , V_327 [ V_45 ] ) == 0 ) {
V_17 = TRUE ;
V_80 = TRUE ;
#ifdef F_6
F_168 ( 2 , V_285 ) ;
#endif
}
}
V_341 =
( T_45 ) (
V_356 |
V_357 |
V_358 |
V_359 |
V_98 |
V_91 |
V_360 |
V_361 ) ;
F_217 ( NULL ,
V_341 ,
V_362 , NULL ) ;
F_217 ( V_363 ,
V_341 ,
V_362 , NULL ) ;
F_217 ( V_364 ,
V_341 ,
V_362 , NULL ) ;
F_217 ( V_90 ,
V_341 ,
V_362 , NULL ) ;
V_93 . V_240 = F_218 ( FALSE , FALSE , sizeof( T_30 * ) ) ;
#if ! F_125 ( 2 , 31 , 0 )
F_219 ( NULL ) ;
#endif
#ifdef F_6
F_220 () ;
F_221 ( F_222 ( 1 , 1 ) , & V_335 ) ;
F_223 ( F_71 , TRUE ) ;
#else
memset ( & V_337 , 0 , sizeof( V_337 ) ) ;
V_337 . V_365 = F_71 ;
V_337 . V_366 = 0 ;
F_224 ( & V_337 . V_367 ) ;
V_336 ( V_368 , & V_337 , NULL ) ;
V_336 ( V_369 , & V_337 , NULL ) ;
V_336 ( V_370 , & V_337 , NULL ) ;
V_336 ( V_371 , NULL , & V_338 ) ;
if ( V_338 . V_365 == V_372 )
V_336 ( V_371 , & V_337 , NULL ) ;
#ifdef F_225
V_337 . V_365 = F_75 ;
V_337 . V_366 = V_373 ;
F_224 ( & V_337 . V_367 ) ;
V_336 ( F_225 , & V_337 , NULL ) ;
#endif
#endif
#ifdef F_16
F_1 () ;
#endif
F_226 () ;
#ifdef F_44
F_80 () ;
#endif
F_227 ( & V_199 ) ;
V_199 . V_374 = TRUE ;
V_199 . V_286 = TRUE ;
V_199 . V_17 = V_17 ;
while ( ( V_318 = F_228 ( V_326 , V_327 , F_214 , V_331 , NULL ) ) != - 1 ) {
switch ( V_318 ) {
case 'h' :
printf ( L_213
L_221
L_222 ,
F_151 () ) ;
F_10 ( stdout ) ;
F_76 ( 0 ) ;
break;
case 'v' :
{
F_229 ( L_223 , V_328 , V_329 ) ;
F_155 ( V_328 , TRUE ) ;
F_155 ( V_329 , TRUE ) ;
F_76 ( 0 ) ;
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
case V_375 :
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
V_106 = F_230 ( & V_199 , V_318 , V_376 , & V_339 ) ;
if ( V_106 != 0 ) {
F_76 ( V_106 ) ;
}
break;
case 'Z' :
V_17 = TRUE ;
#ifdef F_6
F_168 ( 2 , V_285 ) ;
if ( strcmp ( V_376 , V_377 ) != 0 ) {
V_378 = F_150 ( V_379 , V_376 ) ;
V_380 = F_121 ( F_122 ( V_378 ) ,
V_201 , 0 , NULL , V_202 , 0 , NULL ) ;
if ( V_380 == V_188 ) {
F_58 ( V_90 , V_98 ,
L_224 ,
V_378 ) ;
F_76 ( 1 ) ;
}
}
#endif
break;
case 'q' :
V_102 = TRUE ;
break;
case 't' :
V_238 = TRUE ;
break;
case 'D' :
if ( ! V_342 ) {
V_342 = TRUE ;
V_348 ++ ;
}
break;
case 'L' :
if ( ! V_343 ) {
V_343 = TRUE ;
V_348 ++ ;
}
break;
#ifdef F_13
case 'd' :
if ( ! V_344 ) {
V_344 = TRUE ;
V_348 ++ ;
}
break;
#endif
case 'S' :
if ( ! V_347 ) {
V_347 = TRUE ;
V_348 ++ ;
}
break;
case 'k' :
if ( ! V_345 ) {
V_345 = TRUE ;
V_346 = V_376 ;
V_348 ++ ;
} else {
F_26 ( L_225 ) ;
V_334 = TRUE ;
}
break;
case 'M' :
V_80 = TRUE ;
break;
case 'C' :
V_313 = F_231 ( V_376 , L_226 ) ;
break;
case 'N' :
V_315 = F_231 ( V_376 , L_227 ) ;
break;
default:
F_26 ( L_228 , V_327 [ V_381 - 1 ] ) ;
case '?' :
V_334 = TRUE ;
break;
}
}
if ( ! V_334 ) {
V_326 -= V_381 ;
V_327 += V_381 ;
if ( V_326 >= 1 ) {
V_326 -- ;
V_327 ++ ;
}
if ( V_326 != 0 ) {
F_26 ( L_229 , V_327 [ 0 ] ) ;
V_334 = TRUE ;
}
}
if ( ( V_313 > 0 ) || ( V_315 > 0 ) ) {
V_238 = TRUE ;
}
if ( ( V_313 == 0 ) && ( V_315 == 0 ) ) {
V_313 = 1000 * 1000 ;
V_315 = 1000 ;
}
if ( V_334 ) {
F_10 ( V_19 ) ;
F_76 ( 1 ) ;
}
if ( V_348 > 1 ) {
#ifdef F_13
F_26 ( L_230 ) ;
#else
F_26 ( L_231 ) ;
#endif
F_76 ( 1 ) ;
} else if ( V_348 == 1 ) {
if ( V_199 . V_246 ) {
F_26 ( L_232 ) ;
F_76 ( 1 ) ;
}
} else {
if ( V_199 . V_47 -> V_48 > 1 ) {
V_238 = TRUE ;
V_199 . V_245 = TRUE ;
}
if ( V_199 . V_251 &&
( ! V_199 . V_245 || V_199 . V_246 ) ) {
F_26 ( L_233 ) ;
F_76 ( 1 ) ;
}
if ( V_199 . V_246 ) {
if ( V_199 . V_255 == NULL ) {
F_26 ( L_234 ) ;
V_199 . V_246 = FALSE ;
}
if ( ! V_199 . V_382 && ! V_199 . V_383 ) {
F_26 ( L_235 ) ;
#if 0
global_capture_opts.multi_files_on = FALSE;
#endif
}
}
}
if ( V_342 ) {
T_18 * V_55 ;
int V_84 ;
T_7 * V_85 ;
V_55 = F_232 ( & V_84 , & V_85 , NULL ) ;
if ( V_55 == NULL ) {
if ( V_84 == 0 ) {
if ( ! V_80 ) {
F_26 ( L_103 ) ;
F_76 ( 2 ) ;
}
} else {
F_26 ( L_92 , V_85 ) ;
F_20 ( V_85 ) ;
F_76 ( 2 ) ;
}
}
if ( V_80 )
F_47 ( V_55 ) ;
else
F_233 ( V_55 ) ;
F_70 ( V_55 ) ;
F_76 ( 0 ) ;
}
if ( V_347 ) {
V_106 = F_56 ( V_80 ) ;
F_76 ( V_106 ) ;
}
if ( V_345 ) {
T_15 V_41 ;
if ( V_199 . V_47 -> V_48 != 1 ) {
F_26 ( L_236 ) ;
F_76 ( 2 ) ;
}
V_41 = F_37 ( V_199 . V_47 , T_15 , 0 ) ;
V_106 = F_192 ( V_41 . V_50 , V_346 ) ;
F_76 ( V_106 ) ;
}
V_106 = F_234 ( & V_199 , NULL ) ;
if ( V_106 != 0 ) {
F_76 ( V_106 ) ;
}
if ( V_343 ) {
T_22 * V_20 ;
T_7 * V_85 ;
T_17 V_384 ;
for ( V_384 = 0 ; V_384 < V_199 . V_47 -> V_48 ; V_384 ++ ) {
T_15 V_41 ;
V_41 = F_37 ( V_199 . V_47 , T_15 , V_384 ) ;
V_20 = F_235 ( & V_41 , & V_85 ) ;
if ( V_20 == NULL ) {
F_26 ( L_237
L_238
L_239 , V_41 . V_50 , V_85 ) ;
F_20 ( V_85 ) ;
F_76 ( 2 ) ;
}
if ( V_20 -> V_77 == NULL ) {
F_26 ( L_240 , V_41 . V_50 ) ;
F_76 ( 2 ) ;
}
if ( V_80 )
F_55 ( V_20 ) ;
else
F_236 ( V_20 , V_41 . V_50 ,
V_41 . V_385 ) ;
F_237 ( V_20 ) ;
}
F_76 ( 0 ) ;
}
if ( V_17 ) {
for ( V_46 = 0 ; V_46 < V_199 . V_47 -> V_48 ; V_46 ++ ) {
T_15 V_41 ;
V_41 = F_37 ( V_199 . V_47 , T_15 , V_46 ) ;
F_58 ( V_90 , V_91 , L_241 ,
V_41 . V_50 ) ;
}
} else {
V_252 = F_148 ( L_60 ) ;
#ifdef F_6
if ( V_199 . V_47 -> V_48 < 2 )
#else
if ( V_199 . V_47 -> V_48 < 4 )
#endif
{
for ( V_46 = 0 ; V_46 < V_199 . V_47 -> V_48 ; V_46 ++ ) {
T_15 V_41 ;
V_41 = F_37 ( V_199 . V_47 , T_15 , V_46 ) ;
if ( V_46 > 0 ) {
if ( V_199 . V_47 -> V_48 > 2 ) {
F_238 ( V_252 , L_91 ) ;
}
F_238 ( V_252 , L_242 ) ;
if ( V_46 == V_199 . V_47 -> V_48 - 1 ) {
F_238 ( V_252 , L_243 ) ;
}
}
F_238 ( V_252 , L_244 , V_41 . V_293 ) ;
}
} else {
F_238 ( V_252 , L_245 , V_199 . V_47 -> V_48 ) ;
}
fprintf ( V_19 , L_246 , V_252 -> V_252 ) ;
F_155 ( V_252 , TRUE ) ;
}
F_239 ( & V_199 , V_92 ) ;
#ifdef F_13
if ( V_344 ) {
F_36 ( & V_199 ) ;
F_76 ( 0 ) ;
}
#endif
F_240 ( & V_199 ) ;
fflush ( V_19 ) ;
if ( F_241 ( & V_199 , & V_340 , & V_260 ) == TRUE ) {
F_76 ( 0 ) ;
} else {
F_76 ( 1 ) ;
}
return 0 ;
}
static void
V_362 ( const char * V_386 , T_45 V_387 ,
const char * V_388 , T_38 T_46 V_2 )
{
T_47 V_389 ;
struct V_390 * V_391 ;
const char * V_392 ;
T_7 * V_18 ;
if ( ! ( V_387 & V_393 & ~ ( V_91 | V_98 ) ) ) {
#if ! F_188 ( F_78 ) && ! F_188 ( V_308 )
return;
#endif
}
time ( & V_389 ) ;
V_391 = localtime ( & V_389 ) ;
switch( V_387 & V_393 ) {
case V_356 :
V_392 = L_247 ;
break;
case V_357 :
V_392 = L_248 ;
break;
case V_358 :
V_392 = L_249 ;
break;
case V_359 :
V_392 = L_250 ;
break;
case V_98 :
V_392 = L_251 ;
break;
case V_91 :
V_392 = L_252 ;
break;
default:
fprintf ( V_19 , L_253 , V_387 ) ;
V_392 = NULL ;
F_242 () ;
}
if ( V_387 & V_359 ) {
V_18 = F_150 ( L_86 , V_388 ) ;
} else {
V_18 = F_150 ( L_254 ,
V_391 -> V_394 , V_391 -> V_395 , V_391 -> V_396 ,
V_386 != NULL ? V_386 : L_60 ,
V_392 , V_388 ) ;
}
#if F_188 ( F_78 ) || F_188 ( V_308 )
if ( ! ( V_387 & V_393 & ~ ( V_91 | V_98 ) ) ) {
#ifdef F_78
fprintf ( V_19 , L_92 , V_18 ) ;
fflush ( V_19 ) ;
#endif
#ifdef V_308
fprintf ( V_353 , L_92 , V_18 ) ;
fflush ( V_353 ) ;
#endif
F_20 ( V_18 ) ;
return;
}
#endif
if ( V_17 ) {
F_19 ( 2 , V_18 , L_60 ) ;
} else {
fprintf ( V_19 , L_92 , V_18 ) ;
fflush ( V_19 ) ;
}
F_20 ( V_18 ) ;
}
static void
F_178 ( unsigned int V_101 )
{
char V_397 [ V_398 + 1 + 1 ] ;
static unsigned int V_399 = 0 ;
if ( V_17 ) {
F_30 ( V_397 , sizeof( V_397 ) , L_255 , V_101 ) ;
F_58 ( V_90 , V_91 , L_256 , V_397 ) ;
F_46 ( 2 , V_400 , V_397 ) ;
} else {
V_399 += V_101 ;
fprintf ( V_19 , L_257 , V_399 ) ;
fflush ( V_19 ) ;
}
}
static void
F_179 ( const char * V_401 )
{
if ( V_17 ) {
F_58 ( V_90 , V_91 , L_258 , V_401 ) ;
F_46 ( 2 , V_402 , V_401 ) ;
} else {
#ifdef F_225
V_105 = TRUE ;
#endif
fprintf ( V_19 , L_259 , V_401 ) ;
fflush ( V_19 ) ;
#ifdef F_225
V_105 = FALSE ;
if ( V_103 )
F_74 () ;
#endif
}
}
static void
F_42 ( T_14 * V_40 , T_17 V_45 , const char * V_24 )
{
T_15 V_41 ;
char V_397 [ V_42 + 1 + 6 ] ;
if ( V_45 < V_40 -> V_47 -> V_48 ) {
if ( V_17 ) {
F_30 ( V_397 , sizeof( V_397 ) , L_260 , V_45 , V_24 ) ;
F_58 ( V_90 , V_91 , L_261 , V_24 ) ;
F_46 ( 2 , V_403 , V_397 ) ;
} else {
V_41 = F_37 ( V_40 -> V_47 , T_15 , V_45 ) ;
F_26 (
L_262
L_4
L_263
L_264 ,
V_41 . V_35 , V_41 . V_50 , V_24 ) ;
}
}
}
static void
F_39 ( const char * V_404 , const char * V_405 )
{
if ( V_17 ) {
F_58 ( V_90 , V_91 ,
L_265 , V_404 ) ;
F_58 ( V_90 , V_91 ,
L_266 , V_405 ) ;
F_19 ( 2 , V_404 , V_405 ) ;
} else {
F_26 ( L_92 , V_404 ) ;
if ( V_405 [ 0 ] != '\0' )
F_243 ( L_92 , V_405 ) ;
}
}
static void
F_244 ( V_8 V_261 , V_8 V_406 , V_8 V_407 , V_8 V_263 , V_8 V_408 , T_7 * V_50 )
{
char V_397 [ V_398 + 1 + 1 ] ;
V_8 V_409 = V_406 + V_407 + V_263 ;
F_30 ( V_397 , sizeof( V_397 ) , L_255 , V_409 ) ;
if ( V_17 ) {
F_58 ( V_90 , V_91 ,
L_267 ,
V_50 , V_261 , V_409 , V_406 , V_407 , V_263 , V_408 ) ;
F_46 ( 2 , V_410 , V_397 ) ;
} else {
fprintf ( V_19 ,
L_268 ,
V_50 , V_261 , V_409 , V_406 , V_407 , V_263 , V_408 ,
V_261 ? 100.0 * V_261 / ( V_261 + V_409 ) : 0.0 ) ;
fflush ( V_19 ) ;
}
}
static T_11
F_66 ( void )
{
T_26 V_411 = 0 ;
T_11 V_226 ;
if ( ! V_17 ) {
return TRUE ;
}
if ( ! V_378 || ! V_380 ) {
F_58 ( V_90 , V_98 ,
L_269 ) ;
return FALSE ;
}
V_226 = F_245 ( V_380 , NULL , 0 , NULL , & V_411 , NULL ) ;
if ( ! V_226 || V_411 > 0 ) {
F_58 ( V_90 , V_98 ,
L_270 , V_378 ) ;
F_58 ( V_90 , V_91 ,
L_271 , V_378 ,
V_380 , V_226 , V_411 ) ;
return FALSE ;
} else {
return TRUE ;
}
}
