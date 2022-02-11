static void
F_1 ( T_1 V_1 )
{
T_2 * V_2 ;
if ( V_1 ) {
V_2 = stdout ;
fprintf ( V_2 ,
L_1 V_3 L_2
L_3
L_4
L_5
L_6 ,
V_4 , F_2 () ) ;
} else {
V_2 = V_5 ;
}
fprintf ( V_2 , L_5 ) ;
fprintf ( V_2 , L_7 ) ;
fprintf ( V_2 , L_5 ) ;
fprintf ( V_2 , L_8 ) ;
fprintf ( V_2 , L_9 ) ;
fprintf ( V_2 , L_5 ) ;
fprintf ( V_2 , L_10 ) ;
fprintf ( V_2 , L_11 ) ;
fprintf ( V_2 , L_12 ) ;
fprintf ( V_2 , L_13 ) ;
fprintf ( V_2 , L_14 ) ;
fprintf ( V_2 , L_15 ) ;
fprintf ( V_2 , L_16 ) ;
fprintf ( V_2 , L_17 ) ;
fprintf ( V_2 , L_18 ) ;
fprintf ( V_2 , L_19 ) ;
fprintf ( V_2 , L_5 ) ;
fprintf ( V_2 , L_20 ) ;
fprintf ( V_2 , L_21 ) ;
fprintf ( V_2 , L_22 ) ;
fprintf ( V_2 , L_23 ) ;
fprintf ( V_2 , L_24 ) ;
fprintf ( V_2 , L_5 ) ;
fprintf ( V_2 , L_25 ) ;
fprintf ( V_2 , L_26 ) ;
fprintf ( V_2 , L_27 ) ;
fprintf ( V_2 , L_28 ) ;
}
static void
F_3 ( const T_3 * T_4 V_6 , T_5 T_6 V_6 ,
const T_3 * T_7 V_6 , T_8 T_9 V_6 )
{
}
static int
F_4 ( const char * V_7 )
{
#ifndef F_5
T_10 V_8 ;
#else
char * V_9 , * V_10 ;
T_11 V_11 ;
T_12 * V_12 ;
T_13 V_13 = NULL ;
#endif
int V_14 ;
F_6 ( V_15 , V_16 , L_29 , V_7 ) ;
if ( strcmp ( V_7 , L_30 ) == 0 ) {
V_14 = 0 ;
#ifdef F_5
F_7 ( 0 , V_17 ) ;
#endif
} else {
#ifndef F_5
if ( F_8 ( V_7 , & V_8 ) < 0 ) {
fprintf ( V_5 , L_31 ,
V_7 , F_9 ( V_18 ) ) ;
return - 1 ;
}
if ( ! F_10 ( V_8 . V_19 ) ) {
if ( F_11 ( V_8 . V_19 ) ) {
} else
{
fprintf ( V_5 , L_32 ,
V_7 ) ;
}
return - 1 ;
}
V_14 = F_12 ( V_7 , V_20 | V_21 , 0000 ) ;
if ( V_14 == - 1 ) {
fprintf ( V_5 , L_33 ,
V_7 , F_9 ( V_18 ) ) ;
return - 1 ;
}
#else
#define F_13 "\\pipe\\"
V_9 = F_14 ( V_7 ) ;
if ( strstr ( V_9 , L_34 ) == V_9 ) {
V_10 = strchr ( V_9 + 3 , '\\' ) ;
if ( V_10 && F_15 ( V_10 , F_13 , strlen ( F_13 ) ) != 0 )
V_10 = NULL ;
}
F_16 ( V_9 ) ;
if ( ! V_10 ) {
fprintf ( V_5 , L_32 ,
V_7 ) ;
return - 1 ;
}
while ( 1 ) {
V_13 = F_17 ( F_18 ( V_7 ) , V_22 , 0 , NULL ,
V_23 , 0 , NULL ) ;
if ( V_13 != V_24 )
break;
V_11 = F_19 () ;
if ( V_11 != V_25 ) {
F_20 ( V_26 | V_27 | V_28 ,
NULL , V_11 , 0 , ( V_29 ) & V_12 , 0 , NULL ) ;
fprintf ( V_5 , L_35 ,
V_7 , F_21 ( V_12 ) , V_11 ) ;
F_22 ( V_12 ) ;
return - 1 ;
}
if ( ! F_23 ( F_18 ( V_7 ) , 30 * 1000 ) ) {
V_11 = F_19 () ;
F_20 ( V_26 | V_27 | V_28 ,
NULL , V_11 , 0 , ( V_29 ) & V_12 , 0 , NULL ) ;
fprintf ( V_5 , L_36 ,
V_7 , F_21 ( V_12 ) , V_11 ) ;
F_22 ( V_12 ) ;
return - 1 ;
}
}
V_14 = F_24 ( ( long ) V_13 , V_30 ) ;
if ( V_14 == - 1 ) {
fprintf ( V_5 , L_33 ,
V_7 , F_9 ( V_18 ) ) ;
return - 1 ;
}
#endif
}
return V_14 ;
}
static T_1
F_25 ( const char * V_31 ) {
char * V_32 = strchr ( V_31 , ':' ) ;
char * V_33 ;
int V_34 ;
long V_35 ;
T_14 V_36 ;
T_15 * V_37 ;
if ( ! V_32 )
return FALSE ;
V_32 ++ ;
if ( strncmp ( V_31 , L_37 , strlen ( L_37 ) ) == 0 ) {
V_34 = F_26 ( V_32 ) ;
if ( V_34 == - 1 ) {
V_18 = 0 ;
V_35 = strtol ( V_32 , & V_33 , 10 ) ;
if ( V_33 == V_32 || * V_33 != '\0' || V_18 != 0 || V_35 > V_38 ) {
return FALSE ;
}
V_34 = ( int ) V_35 ;
}
V_39 = F_27 ( V_34 ) ;
if ( V_39 == V_40 ) {
return FALSE ;
}
return TRUE ;
} else if ( strncmp ( V_31 , L_38 , strlen ( L_38 ) ) == 0 ) {
V_36 = F_28 ( V_32 ) ;
if ( V_36 ) {
V_39 = V_41 ;
V_37 = F_29 ( L_39 ) ;
F_30 ( V_37 ,
L_40 ,
V_32 ) ;
if ( F_31 ( V_37 -> V_42 ) != V_43 ) {
F_32 ( V_37 , TRUE ) ;
return FALSE ;
}
F_32 ( V_37 , TRUE ) ;
return TRUE ;
}
}
return FALSE ;
}
static void
F_33 ( T_15 * V_44 , T_15 * V_45 )
{
printf ( L_1 V_3 L_2
L_5
L_6
L_5
L_6
L_5
L_6 ,
V_4 , F_2 () , V_44 -> V_42 ,
V_45 -> V_42 ) ;
}
int
main ( int V_46 , char * V_47 [] )
{
char * V_48 ;
int V_49 , V_50 ;
T_1 V_51 = FALSE ;
#ifdef F_5
T_16 V_52 ;
#endif
char * V_53 , * V_54 ;
char * V_55 , * V_56 ;
int V_57 , V_58 ;
int V_59 , V_60 ;
int V_61 , V_62 ;
int V_63 , V_64 ;
int V_11 ;
T_3 * V_7 = NULL ;
T_3 * V_65 [ 64 ] ;
T_17 * V_66 ;
char V_67 ;
T_5 V_68 ;
T_18 * V_69 = F_34 () ;
T_19 V_70 ;
T_1 V_71 = FALSE ;
#define F_35 "d:F:hlnN:o:pr:R:sS:t:v"
static const char V_72 [] = F_35 ;
#ifdef F_5
F_36 ( V_46 , V_47 ) ;
#endif
F_37 () ;
memset ( V_65 , 0 , sizeof( V_65 ) ) ;
memset ( V_73 , 0 , sizeof( V_73 ) ) ;
V_74 = 0 ;
V_75 = 0 ;
V_76 = F_34 () ;
V_48 = F_38 ( V_47 [ 0 ] , main ) ;
if ( V_48 != NULL ) {
fprintf ( V_5 , L_41 ,
V_48 ) ;
}
F_37 () ;
V_68 =
V_77 |
V_78 |
V_79 |
V_16 ;
F_39 ( NULL ,
V_68 ,
F_3 , NULL ) ;
F_39 ( V_15 ,
V_68 ,
F_3 , NULL ) ;
F_40 ( V_80 ) ;
F_41 ( V_81 ) ;
F_42 ( V_82 ) ;
F_43 ( V_83 , V_84 , NULL , NULL ,
V_85 , V_86 , V_87 ,
V_88 ) ;
F_44 () ;
setlocale ( V_89 , L_42 ) ;
V_66 = F_45 ( & V_57 , & V_58 , & V_53 ,
& V_59 , & V_60 , & V_54 ) ;
if ( V_53 != NULL ) {
if ( V_57 != 0 ) {
F_46 ( L_43 ,
V_54 , F_9 ( V_57 ) ) ;
}
if ( V_58 != 0 ) {
F_46 ( L_44 ,
V_54 , F_9 ( V_58 ) ) ;
}
}
if ( V_54 != NULL ) {
if ( V_59 != 0 ) {
F_46 ( L_45 , V_54 ,
F_9 ( V_59 ) ) ;
}
if ( V_60 != 0 ) {
F_46 ( L_46 ,
V_54 , F_9 ( V_60 ) ) ;
}
F_16 ( V_54 ) ;
V_54 = NULL ;
}
V_90 = V_66 -> V_91 ;
F_47 ( & V_55 , & V_61 , & V_62 ,
& V_56 , & V_63 , & V_64 ) ;
if ( V_55 != NULL ) {
if ( V_61 != 0 ) {
F_46 ( L_47 ,
V_55 , F_9 ( V_61 ) ) ;
}
if ( V_62 != 0 ) {
F_46 ( L_48 ,
V_55 , F_9 ( V_62 ) ) ;
}
F_16 ( V_55 ) ;
}
if ( V_56 != NULL ) {
if ( V_63 != 0 ) {
F_46 (
L_49 , V_56 ,
F_9 ( V_63 ) ) ;
}
if ( V_64 != 0 ) {
F_46 (
L_50 , V_56 ,
F_9 ( V_64 ) ) ;
}
F_16 ( V_56 ) ;
}
#ifdef F_5
F_48 () ;
#endif
F_49 ( & V_92 ) ;
V_93 = V_94 ;
V_39 = V_40 ;
while ( ( V_49 = F_50 ( V_46 , V_47 , V_72 ) ) != - 1 ) {
switch ( V_49 ) {
case 'd' :
if ( ! F_25 ( V_95 ) ) {
F_46 ( L_51 , V_95 ) ;
exit ( 1 ) ;
}
break;
case 'F' :
F_51 ( V_69 , F_14 ( V_95 ) ) ;
break;
case 'h' :
F_1 ( TRUE ) ;
exit ( 0 ) ;
break;
case 'l' :
V_96 = TRUE ;
break;
case 'n' :
V_90 = V_97 ;
break;
case 'N' :
if ( V_90 == V_98 )
V_90 = V_97 ;
V_67 = F_52 ( V_95 , & V_90 ) ;
if ( V_67 != '\0' ) {
F_46 ( L_52 ,
V_67 ) ;
exit ( 1 ) ;
}
break;
case 'o' :
switch ( F_31 ( V_95 ) ) {
case V_43 :
break;
case V_99 :
F_46 ( L_53 , V_95 ) ;
exit ( 1 ) ;
break;
case V_100 :
case V_101 :
F_46 ( L_54 , V_95 ) ;
exit ( 1 ) ;
break;
}
break;
case 'p' :
V_102 = TRUE ;
break;
case 'r' :
V_7 = F_14 ( V_95 ) ;
break;
case 'R' :
if( V_74 < ( int ) sizeof( V_65 ) / ( int ) sizeof( V_65 [ 0 ] ) ) {
V_65 [ V_74 ++ ] = V_95 ;
}
else {
F_46 ( L_55 ) ;
exit ( 1 ) ;
}
break;
case 's' :
V_71 = TRUE ;
break;
case 'S' :
if ( ! F_53 ( V_95 ) ) {
F_46 ( L_56 ) ;
exit ( 1 ) ;
}
break;
case 't' :
if ( strcmp ( V_95 , L_57 ) == 0 )
F_40 ( V_80 ) ;
else if ( strcmp ( V_95 , L_58 ) == 0 )
F_40 ( V_103 ) ;
else if ( strcmp ( V_95 , L_59 ) == 0 )
F_40 ( V_104 ) ;
else if ( strcmp ( V_95 , L_60 ) == 0 )
F_40 ( V_105 ) ;
else if ( strcmp ( V_95 , L_61 ) == 0 )
F_40 ( V_106 ) ;
else if ( strcmp ( V_95 , L_62 ) == 0 )
F_40 ( V_107 ) ;
else if ( strcmp ( V_95 , L_63 ) == 0 )
F_40 ( V_108 ) ;
else if ( strcmp ( V_95 , L_64 ) == 0 )
F_40 ( V_109 ) ;
else {
F_46 ( L_65 ,
V_95 ) ;
F_54 ( L_66 ) ;
F_54 ( L_67 ) ;
exit ( 1 ) ;
}
break;
case 'v' :
{
T_15 * V_44 ;
T_15 * V_45 ;
V_44 = F_29 ( L_68 ) ;
F_55 ( V_44 , NULL , V_110 ) ;
V_45 = F_29 ( L_69 ) ;
F_56 ( V_45 , NULL ) ;
F_33 ( V_44 , V_45 ) ;
F_32 ( V_44 , TRUE ) ;
F_32 ( V_45 , TRUE ) ;
exit ( 0 ) ;
break;
}
default:
case '?' :
F_1 ( TRUE ) ;
exit ( 1 ) ;
break;
}
}
F_57 () ;
for ( V_70 = 0 ; V_70 < V_69 -> V_111 ; V_70 ++ ) {
F_58 ( ( char * ) F_59 ( V_69 , V_70 ) ) ;
}
F_60 ( V_69 , TRUE ) ;
printf ( L_5 ) ;
fflush ( stdout ) ;
if ( V_112 < V_46 ) {
if ( V_7 != NULL ) {
if ( V_74 != 0 ) {
F_46 ( L_70
L_71 ) ;
exit ( 1 ) ;
}
V_65 [ V_74 ] = F_61 ( V_46 , V_47 , V_112 ) ;
}
}
if ( V_39 == V_40 ) {
F_46 ( L_72 ) ;
exit ( 1 ) ;
}
if ( V_51 ) {
F_1 ( FALSE ) ;
exit ( 1 ) ;
}
#ifdef F_5
F_62 ( F_63 ( 1 , 1 ) , & V_52 ) ;
#endif
F_64 () ;
if ( V_55 == NULL && V_56 == NULL ) {
F_65 () ;
}
F_66 ( & V_92 . V_113 , V_66 -> V_114 , TRUE ) ;
if ( V_74 != 0 ) {
for ( V_50 = 0 ; V_50 < V_74 ; V_50 ++ ) {
if ( ! F_67 ( V_65 [ V_50 ] , & V_73 [ V_75 ] ) ) {
F_46 ( L_6 , V_115 ) ;
F_68 () ;
exit ( 2 ) ;
}
V_75 ++ ;
}
}
if ( V_7 ) {
F_69 () ;
if ( F_70 ( & V_92 , V_7 ) != V_116 ) {
F_68 () ;
exit ( 2 ) ;
}
if ( V_71 ) {
T_19 V_117 = sizeof( struct V_118 ) + sizeof( V_119 ) ;
T_3 V_120 [ sizeof( struct V_118 ) + sizeof( V_119 ) ] ;
while ( V_117 > 0 ) {
T_19 V_121 = F_71 ( V_122 , V_120 , V_117 ) ;
if ( V_121 <= 0 ) {
F_46 ( L_73 ) ;
exit ( 2 ) ;
}
V_117 -= V_121 ;
}
}
#if 0
switch(wtap_file_tsprecision(cfile.wth)) {
case(WTAP_FILE_TSPREC_SEC):
timestamp_set_precision(TS_PREC_AUTO_SEC);
break;
case(WTAP_FILE_TSPREC_DSEC):
timestamp_set_precision(TS_PREC_AUTO_DSEC);
break;
case(WTAP_FILE_TSPREC_CSEC):
timestamp_set_precision(TS_PREC_AUTO_CSEC);
break;
case(WTAP_FILE_TSPREC_MSEC):
timestamp_set_precision(TS_PREC_AUTO_MSEC);
break;
case(WTAP_FILE_TSPREC_USEC):
timestamp_set_precision(TS_PREC_AUTO_USEC);
break;
case(WTAP_FILE_TSPREC_NSEC):
timestamp_set_precision(TS_PREC_AUTO_NSEC);
break;
default:
g_assert_not_reached();
}
#else
F_41 ( V_123 ) ;
#endif
V_11 = F_72 ( & V_92 ) ;
if ( V_11 != 0 ) {
F_68 () ;
exit ( 2 ) ;
}
} else {
F_46 ( L_74 ) ;
exit ( 2 ) ;
}
F_68 () ;
return 0 ;
}
static T_1
F_73 ( struct V_124 * V_125 , T_20 * V_126 , int * V_11 , const T_3 * * V_127 , T_21 * V_128 ) {
struct V_129 V_130 ;
struct V_131 V_132 ;
int V_133 = 0 ;
int V_134 = sizeof( V_132 ) ;
T_20 * V_135 = ( T_20 * ) & V_132 ;
static T_3 V_12 [ 100 ] ;
if ( V_102 ) {
V_134 = sizeof( V_130 ) ;
V_135 = ( T_20 * ) & V_130 ;
}
while ( V_134 > 0 ) {
V_133 = F_71 ( V_122 , V_135 , V_134 ) ;
if ( V_133 == 0 ) {
* V_11 = 0 ;
return FALSE ;
} else if ( V_133 < 0 ) {
* V_11 = V_136 ;
* V_127 = L_75 ;
return FALSE ;
}
V_134 -= V_133 ;
* V_128 += V_133 ;
V_135 += V_133 ;
}
if ( V_102 ) {
V_125 -> V_137 . V_138 = V_130 . V_137 . V_139 ;
V_125 -> V_137 . V_140 = V_130 . V_137 . V_141 * 1000 ;
V_125 -> V_142 = V_134 = V_130 . V_142 ;
V_125 -> V_111 = V_130 . V_111 ;
} else {
V_125 -> V_137 . V_138 = V_132 . V_143 ;
V_125 -> V_137 . V_140 = V_132 . V_144 * 1000 ;
V_125 -> V_142 = V_134 = V_132 . V_145 ;
V_125 -> V_111 = V_132 . V_146 ;
}
V_125 -> V_147 = V_39 ;
#if 0
printf("tv_sec: %d (%04x)\n", hdr.ts.tv_sec, hdr.ts.tv_sec);
printf("tv_usec: %d (%04x)\n", hdr.ts.tv_usec, hdr.ts.tv_usec);
printf("caplen: %d (%04x)\n", hdr.caplen, hdr.caplen);
printf("len: %d (%04x)\n", hdr.len, hdr.len);
#endif
if ( V_134 > V_148 ) {
* V_11 = V_149 ;
F_74 ( V_12 , 100 , L_76 , V_134 , V_134 ) ;
* V_127 = V_12 ;
return FALSE ;
}
V_135 = V_126 ;
while ( V_134 > 0 ) {
V_133 = F_71 ( V_122 , V_135 , V_134 ) ;
if ( V_133 == 0 ) {
* V_11 = V_150 ;
* V_127 = L_77 ;
return FALSE ;
} else if ( V_133 < 0 ) {
* V_11 = V_136 ;
* V_127 = L_78 ;
return FALSE ;
}
V_134 -= V_133 ;
* V_128 += V_133 ;
V_135 += V_133 ;
}
return TRUE ;
}
static int
F_72 ( T_22 * V_151 )
{
int V_11 ;
const T_3 * V_127 ;
T_21 V_128 = 0 ;
struct V_124 V_125 ;
T_20 V_126 [ V_148 ] ;
while ( F_73 ( & V_125 , V_126 , & V_11 , & V_127 , & V_128 ) ) {
F_75 ( V_151 , V_128 , & V_125 , V_126 ) ;
}
if ( V_11 != 0 ) {
switch ( V_11 ) {
case V_152 :
F_46 ( L_79 ,
V_151 -> V_153 , V_127 ) ;
break;
case V_136 :
F_46 ( L_80 ,
V_151 -> V_153 ) ;
break;
case V_150 :
F_46 ( L_81 ,
V_151 -> V_153 ) ;
break;
case V_149 :
F_46 ( L_82 ,
V_151 -> V_153 , V_127 ) ;
break;
case V_154 :
F_46 ( L_83 ,
V_151 -> V_153 , V_127 ) ;
break;
default:
F_46 ( L_84 ,
V_151 -> V_153 , F_76 ( V_11 ) ) ;
break;
}
}
return V_11 ;
}
static T_1
F_75 ( T_22 * V_151 , T_21 V_155 , const struct V_124 * V_156 ,
const T_20 * V_126 )
{
T_23 V_157 ;
T_1 V_158 ;
T_24 V_159 ;
T_1 V_160 ;
union V_161 V_162 ;
int V_50 ;
if( V_156 -> V_111 == 0 )
{
printf ( L_85 , ( unsigned long int ) V_151 -> V_163 ,
( unsigned long int ) V_156 -> V_137 . V_138 ,
( unsigned long int ) V_156 -> V_137 . V_140 ) ;
fflush ( stdout ) ;
return FALSE ;
}
memset ( & V_162 , 0 , sizeof( V_162 ) ) ;
V_151 -> V_163 ++ ;
F_77 ( & V_157 , V_151 -> V_163 , V_156 , V_155 , V_164 ) ;
V_160 = TRUE ;
V_158 = TRUE ;
F_78 ( & V_159 , V_158 , FALSE ) ;
if ( V_74 > 0 ) {
for( V_50 = 0 ; V_50 < V_75 ; V_50 ++ ) {
F_79 ( & V_159 , V_73 [ V_50 ] ) ;
}
}
F_80 ( & V_159 ) ;
printf ( L_86 , ( unsigned long int ) V_151 -> V_163 ) ;
F_81 ( & V_157 , & V_151 -> V_165 ,
& V_166 , & V_167 , & V_168 ) ;
F_82 ( & V_159 , & V_162 , V_126 , & V_157 , & V_151 -> V_113 ) ;
F_83 ( & V_159 ) ;
F_84 ( & V_157 , & V_164 , & V_167 ) ;
for( V_50 = 0 ; V_50 < V_74 ; V_50 ++ ) {
if ( V_73 [ V_50 ] )
V_160 = F_85 ( V_73 [ V_50 ] , & V_159 ) ;
else
V_160 = TRUE ;
printf ( L_87 , V_160 ? 1 : 0 ) ;
}
printf ( L_88 ) ;
if ( V_96 )
fflush ( stdout ) ;
if ( ferror ( stdout ) ) {
F_86 ( V_18 ) ;
exit ( 2 ) ;
}
F_87 ( & V_159 ) ;
F_88 ( & V_157 ) ;
return V_160 ;
}
static const char * F_89 ( T_25 * V_169 )
{
if ( ! V_169 ) {
return L_89 ;
}
if ( V_76 -> V_111 > 0 && V_169 -> V_170 ) {
return L_90 ;
}
switch( V_169 -> type ) {
case V_171 :
return L_91 ;
case V_172 :
return L_92 ;
case V_173 :
return L_93 ;
case V_174 :
return L_94 ;
case V_175 :
return L_95 ;
case V_176 :
return L_96 ;
case V_177 :
return L_97 ;
case V_178 :
return L_98 ;
case V_179 :
return L_99 ;
case V_180 :
return L_100 ;
case V_181 :
return L_101 ;
case V_182 :
return L_102 ;
case V_183 :
return L_103 ;
case V_184 :
return L_104 ;
case V_185 :
return L_105 ;
case V_186 :
return L_106 ;
case V_187 :
return L_107 ;
case V_188 :
return L_90 ;
case V_189 :
return L_108 ;
case V_190 :
return L_109 ;
case V_191 :
return L_110 ;
case V_192 :
return L_111 ;
case V_193 :
return L_112 ;
case V_194 :
return L_113 ;
case V_195 :
return L_114 ;
case V_196 :
return L_115 ;
case V_197 :
return L_116 ;
case V_198 :
return L_117 ;
case V_199 :
return L_118 ;
case V_200 :
return L_119 ;
case V_201 :
return L_120 ;
default:
return L_89 ;
} ;
}
static const char * F_90 ( T_26 V_202 )
{
switch( V_202 ) {
case V_203 :
return L_121 ;
case V_204 :
return L_122 ;
default:
return L_89 ;
}
}
static const char * F_91 ( T_27 V_205 )
{
switch( V_205 ) {
case V_206 :
return L_123 ;
case V_207 :
return L_124 ;
case V_208 :
return L_125 ;
case V_209 :
return L_126 ;
case V_210 :
return L_127 ;
case V_211 :
return L_128 ;
default:
return L_89 ;
}
}
static T_1 F_92 ( T_28 * V_212 , int V_213 )
{
T_25 * V_214 ;
static char * V_215 = NULL ;
char * V_216 = V_215 ;
static T_15 * V_217 = NULL ;
int V_218 = V_219 , V_220 ;
T_19 V_50 ;
T_29 * V_221 ;
V_119 V_222 ;
T_30 V_223 ;
const T_31 * V_224 = & V_225 ;
V_214 = V_212 -> V_214 ;
if ( ! V_215 ) {
V_215 = ( char * ) F_93 ( V_218 + 1 ) ;
V_216 = V_215 ;
}
if ( ! V_217 ) {
V_217 = F_29 ( L_42 ) ;
}
if( V_212 -> V_226 . V_227 -> V_228 )
{
V_220 = F_94 ( & V_212 -> V_226 , V_229 ) ;
while ( V_218 < V_220 ) {
V_218 *= 2 ;
V_215 = ( char * ) F_95 ( V_215 , V_218 + 1 ) ;
V_216 = V_215 ;
}
F_96 ( & V_212 -> V_226 ,
V_229 ,
V_215 ) ;
if ( ( V_212 -> V_226 . V_227 -> V_227 == V_188 || V_212 -> V_226 . V_227 -> V_227 == V_189 ) && V_220 > 2 ) {
V_215 [ V_220 - 1 ] = '\0' ;
V_216 ++ ;
}
}
if ( V_76 -> V_111 > 0 && V_212 -> V_214 -> V_170 ) {
F_97 ( V_217 , 0 ) ;
for ( V_50 = 0 ; V_50 < V_76 -> V_111 ; V_50 ++ ) {
V_221 = ( T_29 * ) F_59 ( V_76 , V_50 ) ;
if ( V_221 -> V_230 ) {
F_98 ( V_217 , V_221 -> V_230 ) ;
} else {
switch ( V_221 -> V_231 ) {
case V_232 :
F_98 ( V_217 , V_214 -> V_233 ) ;
break;
case V_234 :
F_98 ( V_217 , V_216 ) ;
break;
case V_235 :
switch( V_214 -> type ) {
case V_173 :
V_222 = F_99 ( & V_212 -> V_226 ) ;
V_224 = ( const struct T_31 * ) V_214 -> V_170 ;
F_98 ( V_217 , V_222 ? V_224 -> V_236 : V_224 -> V_237 ) ;
break;
case V_179 :
case V_180 :
case V_181 :
case V_182 :
F_100 ( ! V_214 -> V_238 ) ;
V_223 = F_101 ( & V_212 -> V_226 ) ;
if ( V_214 -> V_239 & V_240 ) {
F_98 ( V_217 , F_102 ( V_223 , F_103 ( V_214 -> V_170 ) , L_129 ) ) ;
} else if ( V_214 -> V_239 & V_241 ) {
F_98 ( V_217 , F_104 ( V_223 , ( const V_242 * ) V_214 -> V_170 , L_129 ) ) ;
} else {
F_98 ( V_217 , F_105 ( V_223 , F_106 ( V_214 -> V_170 ) , L_129 ) ) ;
}
break;
case V_174 :
case V_175 :
case V_176 :
case V_177 :
V_222 = F_99 ( & V_212 -> V_226 ) ;
if ( ! V_214 -> V_238 && V_214 -> V_239 & V_240 ) {
F_98 ( V_217 , F_102 ( V_222 , F_103 ( V_214 -> V_170 ) , L_129 ) ) ;
} else if ( V_214 -> V_239 & V_241 ) {
F_98 ( V_217 , F_104 ( V_222 , ( const V_242 * ) V_214 -> V_170 , L_129 ) ) ;
} else {
F_98 ( V_217 , F_105 ( V_222 , F_106 ( V_214 -> V_170 ) , L_129 ) ) ;
}
break;
default:
break;
}
break;
default:
break;
}
}
}
printf ( L_130 , V_213 , V_217 -> V_42 ) ;
return TRUE ;
}
if( V_212 -> V_226 . V_227 -> V_228 )
{
printf ( L_130 , V_213 , V_216 ) ;
return TRUE ;
}
printf ( L_131 , V_213 ) ;
return TRUE ;
}
static int
F_107 ( void * V_243 , T_32 * T_33 V_6 , T_24 * V_159 , const void * T_34 V_6 )
{
T_35 * V_244 = ( T_35 * ) V_243 ;
T_18 * V_245 ;
T_19 V_50 ;
V_245 = F_108 ( V_159 -> V_246 , V_244 -> V_247 ) ;
if( ! V_245 ) {
printf ( L_132 ) ;
return 0 ;
}
for ( V_50 = 0 ; V_50 < V_245 -> V_111 ; V_50 ++ ) {
F_92 ( ( T_28 * ) V_245 -> V_248 [ V_50 ] , V_244 -> V_213 ) ;
}
return 0 ;
}
static void
F_58 ( char * V_249 )
{
T_35 * V_244 ;
T_25 * V_169 ;
T_15 * V_250 ;
V_169 = F_109 ( V_249 ) ;
if( ! V_169 ) {
fprintf ( V_5 , L_133 , V_249 ) ;
exit ( 1 ) ;
}
switch ( V_169 -> type ) {
case V_186 :
printf ( L_134 ,
V_251 ,
F_89 ( V_169 ) ,
F_90 ( V_169 -> V_239 ) ) ;
break;
default:
printf ( L_134 ,
V_251 ,
F_89 ( V_169 ) ,
F_91 ( V_169 -> V_239 ) ) ;
break;
}
V_244 = ( T_35 * ) F_93 ( sizeof( T_35 ) ) ;
V_244 -> V_247 = V_169 -> V_252 ;
V_244 -> V_253 = V_249 ;
V_244 -> V_213 = V_251 ++ ;
V_250 = F_110 ( L_135 , V_244 , V_244 -> V_253 , V_254 , NULL , F_107 , NULL ) ;
if( V_250 ) {
fprintf ( V_5 , L_136 ,
V_250 -> V_42 ) ;
F_32 ( V_250 , TRUE ) ;
if( V_244 -> V_253 ) {
F_16 ( V_244 -> V_253 ) ;
}
F_16 ( V_244 ) ;
exit ( 1 ) ;
}
}
static void
F_111 ( T_36 V_231 , T_3 * V_230 ) {
T_29 * V_221 = ( T_29 * ) F_93 ( sizeof( T_29 ) ) ;
V_221 -> V_231 = V_231 ;
V_221 -> V_230 = F_14 ( V_230 ) ;
F_51 ( V_76 , V_221 ) ;
}
static T_1
F_53 ( T_3 * V_231 ) {
T_15 * V_255 = F_29 ( L_42 ) ;
T_37 V_111 ;
T_37 V_10 = 0 ;
if ( ! V_231 ) {
return FALSE ;
}
V_111 = strlen ( V_231 ) ;
F_112 ( V_76 , 0 ) ;
while ( V_10 < V_111 ) {
if ( V_231 [ V_10 ] == '%' ) {
if ( V_10 >= V_111 ) {
return FALSE ;
}
V_10 ++ ;
if ( V_255 -> V_111 > 0 ) {
F_111 ( V_256 , V_255 -> V_42 ) ;
F_97 ( V_255 , 0 ) ;
}
switch ( V_231 [ V_10 ] ) {
case 'D' :
F_111 ( V_232 , NULL ) ;
break;
case 'N' :
F_111 ( V_234 , NULL ) ;
break;
case 'S' :
F_111 ( V_235 , NULL ) ;
break;
case '%' :
F_113 ( V_255 , '%' ) ;
break;
default:
return FALSE ;
}
} else {
F_113 ( V_255 , V_231 [ V_10 ] ) ;
}
V_10 ++ ;
}
if ( V_255 -> V_111 > 0 ) {
F_111 ( V_256 , V_255 -> V_42 ) ;
}
F_32 ( V_255 , TRUE ) ;
return TRUE ;
}
static void
F_86 ( int V_11 )
{
switch ( V_11 ) {
case V_257 :
F_46 ( L_137
L_138 ) ;
break;
#ifdef F_114
case F_114 :
F_46 ( L_139
L_140 ) ;
break;
#endif
default:
F_46 ( L_141 ,
F_9 ( V_11 ) ) ;
break;
}
}
static void
V_86 ( const char * V_153 , int V_11 , T_1 V_258 )
{
fprintf ( V_5 , L_142 ) ;
fprintf ( V_5 , F_115 ( V_11 , V_258 ) , V_153 ) ;
fprintf ( V_5 , L_5 ) ;
}
T_38
F_70 ( T_22 * V_151 , const char * V_259 )
{
if ( ( V_122 = F_4 ( V_259 ) ) < 0 )
return V_260 ;
F_116 () ;
F_117 () ;
V_151 -> V_261 = NULL ;
V_151 -> V_262 = 0 ;
V_151 -> V_153 = F_14 ( V_259 ) ;
V_151 -> V_263 = FALSE ;
V_151 -> V_264 = FALSE ;
V_151 -> V_265 = V_266 ;
V_151 -> V_163 = 0 ;
V_151 -> V_267 = FALSE ;
V_151 -> V_268 = 0 ;
V_151 -> V_269 = FALSE ;
V_151 -> V_270 = V_148 ;
F_118 ( & V_151 -> V_165 ) ;
F_119 ( & V_166 ) ;
F_119 ( & V_167 ) ;
F_119 ( & V_168 ) ;
return V_116 ;
}
static void
V_85 ( const char * V_271 , T_39 V_272 )
{
fprintf ( V_5 , L_142 ) ;
vfprintf ( V_5 , V_271 , V_272 ) ;
fprintf ( V_5 , L_5 ) ;
}
static void
V_87 ( const char * V_153 , int V_11 )
{
F_46 ( L_143 ,
V_153 , F_9 ( V_11 ) ) ;
}
static void
V_88 ( const char * V_153 , int V_11 )
{
F_46 ( L_144 ,
V_153 , F_9 ( V_11 ) ) ;
}
void
F_46 ( const char * V_273 , ... )
{
T_39 V_272 ;
va_start ( V_272 , V_273 ) ;
fprintf ( V_5 , L_142 ) ;
vfprintf ( V_5 , V_273 , V_272 ) ;
fprintf ( V_5 , L_5 ) ;
va_end ( V_272 ) ;
}
void
F_54 ( const char * V_273 , ... )
{
T_39 V_272 ;
va_start ( V_272 , V_273 ) ;
vfprintf ( V_5 , V_273 , V_272 ) ;
fprintf ( V_5 , L_5 ) ;
va_end ( V_272 ) ;
}
