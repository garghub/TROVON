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
char * V_9 , * V_10 = NULL ;
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
T_15 * V_44 ;
T_15 * V_45 ;
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
int V_68 ;
T_18 * V_69 = F_34 () ;
T_19 V_70 ;
T_1 V_71 = FALSE ;
#define F_35 "d:F:hlnN:o:pr:R:sS:t:v"
static const char V_72 [] = F_35 ;
V_44 = F_29 ( L_41 ) ;
F_36 ( V_44 , NULL , V_73 ) ;
V_45 = F_29 ( L_42 ) ;
F_37 ( V_45 , NULL ) ;
F_38 ( L_1 V_3 L_2
L_5
L_6
L_5
L_6 ,
V_4 , V_44 -> V_42 , V_45 -> V_42 ) ;
#ifdef F_5
F_39 ( V_46 , V_47 ) ;
F_40 () ;
#endif
F_41 () ;
memset ( V_65 , 0 , sizeof( V_65 ) ) ;
memset ( V_74 , 0 , sizeof( V_74 ) ) ;
V_75 = 0 ;
V_76 = 0 ;
V_77 = F_34 () ;
V_48 = F_42 ( V_47 [ 0 ] , main ) ;
if ( V_48 != NULL ) {
fprintf ( V_5 , L_43 ,
V_48 ) ;
}
F_41 () ;
V_68 =
V_78 |
V_79 |
V_80 |
V_16 ;
F_43 ( NULL ,
( T_5 ) V_68 ,
F_3 , NULL ) ;
F_43 ( V_15 ,
( T_5 ) V_68 ,
F_3 , NULL ) ;
F_44 ( V_81 ) ;
F_45 ( V_82 ) ;
F_46 ( V_83 ) ;
F_47 ( V_84 , V_85 , NULL , NULL ,
V_86 , V_87 , V_88 ,
V_89 ) ;
setlocale ( V_90 , L_44 ) ;
V_66 = F_48 ( & V_57 , & V_58 , & V_53 ,
& V_59 , & V_60 , & V_54 ) ;
if ( V_53 != NULL ) {
if ( V_57 != 0 ) {
F_49 ( L_45 ,
V_54 , F_9 ( V_57 ) ) ;
}
if ( V_58 != 0 ) {
F_49 ( L_46 ,
V_54 , F_9 ( V_58 ) ) ;
}
}
if ( V_54 != NULL ) {
if ( V_59 != 0 ) {
F_49 ( L_47 , V_54 ,
F_9 ( V_59 ) ) ;
}
if ( V_60 != 0 ) {
F_49 ( L_48 ,
V_54 , F_9 ( V_60 ) ) ;
}
F_16 ( V_54 ) ;
V_54 = NULL ;
}
F_50 ( & V_55 , & V_61 , & V_62 ,
& V_56 , & V_63 , & V_64 ) ;
if ( V_55 != NULL ) {
if ( V_61 != 0 ) {
F_49 ( L_49 ,
V_55 , F_9 ( V_61 ) ) ;
}
if ( V_62 != 0 ) {
F_49 ( L_50 ,
V_55 , F_9 ( V_62 ) ) ;
}
F_16 ( V_55 ) ;
}
if ( V_56 != NULL ) {
if ( V_63 != 0 ) {
F_49 (
L_51 , V_56 ,
F_9 ( V_63 ) ) ;
}
if ( V_64 != 0 ) {
F_49 (
L_52 , V_56 ,
F_9 ( V_64 ) ) ;
}
F_16 ( V_56 ) ;
}
#ifdef F_5
F_51 () ;
#endif
F_52 ( & V_91 ) ;
V_92 = V_93 ;
V_39 = V_40 ;
while ( ( V_49 = F_53 ( V_46 , V_47 , V_72 ) ) != - 1 ) {
switch ( V_49 ) {
case 'd' :
if ( ! F_25 ( V_94 ) ) {
F_49 ( L_53 , V_94 ) ;
exit ( 1 ) ;
}
break;
case 'F' :
F_54 ( V_69 , F_14 ( V_94 ) ) ;
break;
case 'h' :
F_1 ( TRUE ) ;
exit ( 0 ) ;
break;
case 'l' :
V_95 = TRUE ;
break;
case 'n' :
V_96 . V_97 = FALSE ;
V_96 . V_98 = FALSE ;
V_96 . V_99 = FALSE ;
V_96 . V_100 = FALSE ;
break;
case 'N' :
V_67 = F_55 ( V_94 , & V_96 ) ;
if ( V_67 != '\0' ) {
F_49 ( L_54 ,
V_67 ) ;
exit ( 1 ) ;
}
break;
case 'o' :
switch ( F_31 ( V_94 ) ) {
case V_43 :
break;
case V_101 :
F_49 ( L_55 , V_94 ) ;
exit ( 1 ) ;
break;
case V_102 :
case V_103 :
F_49 ( L_56 , V_94 ) ;
exit ( 1 ) ;
break;
}
break;
case 'p' :
V_104 = TRUE ;
break;
case 'r' :
V_7 = F_14 ( V_94 ) ;
break;
case 'R' :
if( V_75 < ( int ) sizeof( V_65 ) / ( int ) sizeof( V_65 [ 0 ] ) ) {
V_65 [ V_75 ++ ] = V_94 ;
}
else {
F_49 ( L_57 ) ;
exit ( 1 ) ;
}
break;
case 's' :
V_71 = TRUE ;
break;
case 'S' :
if ( ! F_56 ( V_94 ) ) {
F_49 ( L_58 ) ;
exit ( 1 ) ;
}
break;
case 't' :
if ( strcmp ( V_94 , L_59 ) == 0 )
F_44 ( V_81 ) ;
else if ( strcmp ( V_94 , L_60 ) == 0 )
F_44 ( V_105 ) ;
else if ( strcmp ( V_94 , L_61 ) == 0 )
F_44 ( V_106 ) ;
else if ( strcmp ( V_94 , L_62 ) == 0 )
F_44 ( V_107 ) ;
else if ( strcmp ( V_94 , L_63 ) == 0 )
F_44 ( V_108 ) ;
else if ( strcmp ( V_94 , L_64 ) == 0 )
F_44 ( V_109 ) ;
else if ( strcmp ( V_94 , L_65 ) == 0 )
F_44 ( V_110 ) ;
else if ( strcmp ( V_94 , L_66 ) == 0 )
F_44 ( V_111 ) ;
else {
F_49 ( L_67 ,
V_94 ) ;
F_57 ( L_68 ) ;
F_57 ( L_69 ) ;
exit ( 1 ) ;
}
break;
case 'v' :
{
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
F_58 () ;
for ( V_70 = 0 ; V_70 < V_69 -> V_112 ; V_70 ++ ) {
F_59 ( ( char * ) F_60 ( V_69 , V_70 ) ) ;
}
F_61 ( V_69 , TRUE ) ;
printf ( L_5 ) ;
fflush ( stdout ) ;
if ( V_113 < V_46 ) {
if ( V_7 != NULL ) {
if ( V_75 != 0 ) {
F_49 ( L_70
L_71 ) ;
exit ( 1 ) ;
}
V_65 [ V_75 ] = F_62 ( V_46 , V_47 , V_113 ) ;
}
}
if ( V_39 == V_40 ) {
F_49 ( L_72 ) ;
exit ( 1 ) ;
}
if ( V_51 ) {
F_1 ( FALSE ) ;
exit ( 1 ) ;
}
#ifdef F_5
F_63 ( F_64 ( 1 , 1 ) , & V_52 ) ;
#endif
F_65 () ;
if ( V_55 == NULL && V_56 == NULL ) {
F_66 () ;
}
F_67 ( & V_91 . V_114 , V_66 -> V_115 , TRUE ) ;
if ( V_75 != 0 ) {
for ( V_50 = 0 ; V_50 < V_75 ; V_50 ++ ) {
if ( ! F_68 ( V_65 [ V_50 ] , & V_74 [ V_76 ] ) ) {
F_49 ( L_6 , V_116 ) ;
F_69 () ;
exit ( 2 ) ;
}
V_76 ++ ;
}
}
if ( V_7 ) {
F_70 () ;
if ( F_71 ( & V_91 , V_7 ) != V_117 ) {
F_69 () ;
exit ( 2 ) ;
}
if ( V_71 ) {
T_20 V_118 = sizeof( struct V_119 ) + sizeof( V_120 ) ;
T_3 V_121 [ sizeof( struct V_119 ) + sizeof( V_120 ) ] ;
while ( V_118 != 0 ) {
T_21 V_122 = F_72 ( V_123 , V_121 , ( int ) V_118 ) ;
if ( V_122 <= 0 ) {
F_49 ( L_73 ) ;
exit ( 2 ) ;
}
V_118 -= V_122 ;
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
F_45 ( V_124 ) ;
#endif
V_11 = F_73 ( & V_91 ) ;
if ( V_11 != 0 ) {
F_69 () ;
exit ( 2 ) ;
}
} else {
F_49 ( L_74 ) ;
exit ( 2 ) ;
}
F_69 () ;
return 0 ;
}
static T_1
F_74 ( struct V_125 * V_126 , T_22 * V_127 , int * V_11 , const T_3 * * V_128 , T_23 * V_129 ) {
struct V_130 V_131 ;
struct V_132 V_133 ;
T_21 V_134 = 0 ;
T_20 V_135 = sizeof( V_133 ) ;
T_22 * V_136 = ( T_22 * ) & V_133 ;
static T_3 V_12 [ 100 ] ;
if ( V_104 ) {
V_135 = sizeof( V_131 ) ;
V_136 = ( T_22 * ) & V_131 ;
}
while ( V_135 > 0 ) {
V_134 = F_72 ( V_123 , V_136 , ( int ) V_135 ) ;
if ( V_134 == 0 ) {
* V_11 = 0 ;
return FALSE ;
} else if ( V_134 < 0 ) {
* V_11 = V_137 ;
* V_128 = L_75 ;
return FALSE ;
}
V_135 -= V_134 ;
* V_129 += V_134 ;
V_136 += V_134 ;
}
if ( V_104 ) {
V_126 -> V_138 . V_139 = V_131 . V_138 . V_140 ;
V_126 -> V_138 . V_141 = V_131 . V_138 . V_142 * 1000 ;
V_126 -> V_143 = V_131 . V_143 ;
V_126 -> V_112 = V_131 . V_112 ;
} else {
V_126 -> V_138 . V_139 = V_133 . V_144 ;
V_126 -> V_138 . V_141 = V_133 . V_145 * 1000 ;
V_126 -> V_143 = V_133 . V_146 ;
V_126 -> V_112 = V_133 . V_147 ;
}
V_135 = V_126 -> V_143 ;
V_126 -> V_148 = V_39 ;
#if 0
printf("tv_sec: %d (%04x)\n", hdr.ts.tv_sec, hdr.ts.tv_sec);
printf("tv_usec: %d (%04x)\n", hdr.ts.tv_usec, hdr.ts.tv_usec);
printf("caplen: %d (%04x)\n", hdr.caplen, hdr.caplen);
printf("len: %d (%04x)\n", hdr.len, hdr.len);
#endif
if ( V_135 > V_149 ) {
* V_11 = V_150 ;
F_75 ( V_12 , 100 , L_76 ,
( unsigned long ) V_135 ) ;
* V_128 = V_12 ;
return FALSE ;
}
V_136 = V_127 ;
while ( V_135 > 0 ) {
V_134 = F_72 ( V_123 , V_136 , ( int ) V_135 ) ;
if ( V_134 == 0 ) {
* V_11 = V_151 ;
* V_128 = L_77 ;
return FALSE ;
} else if ( V_134 < 0 ) {
* V_11 = V_137 ;
* V_128 = L_78 ;
return FALSE ;
}
V_135 -= V_134 ;
* V_129 += V_134 ;
V_136 += V_134 ;
}
return TRUE ;
}
static int
F_73 ( T_24 * V_152 )
{
int V_11 ;
const T_3 * V_128 ;
T_23 V_129 = 0 ;
struct V_125 V_126 ;
T_22 V_127 [ V_149 ] ;
while ( F_74 ( & V_126 , V_127 , & V_11 , & V_128 , & V_129 ) ) {
F_76 ( V_152 , V_129 , & V_126 , V_127 ) ;
}
if ( V_11 != 0 ) {
switch ( V_11 ) {
case V_153 :
F_49 ( L_79 ,
V_152 -> V_154 , V_128 ) ;
break;
case V_137 :
F_49 ( L_80 ,
V_152 -> V_154 ) ;
break;
case V_151 :
F_49 ( L_81 ,
V_152 -> V_154 ) ;
break;
case V_150 :
F_49 ( L_82 ,
V_152 -> V_154 , V_128 ) ;
break;
case V_155 :
F_49 ( L_83 ,
V_152 -> V_154 , V_128 ) ;
break;
default:
F_49 ( L_84 ,
V_152 -> V_154 , F_77 ( V_11 ) ) ;
break;
}
}
return V_11 ;
}
static T_1
F_76 ( T_24 * V_152 , T_23 V_156 , struct V_125 * V_157 ,
const T_22 * V_127 )
{
T_25 V_158 ;
T_1 V_159 ;
T_26 V_160 ;
T_1 V_161 ;
int V_50 ;
if( V_157 -> V_112 == 0 )
{
printf ( L_85 , ( unsigned long int ) V_152 -> V_162 ,
( unsigned long int ) V_157 -> V_138 . V_139 ,
( unsigned long int ) V_157 -> V_138 . V_141 ) ;
fflush ( stdout ) ;
return FALSE ;
}
V_152 -> V_162 ++ ;
F_78 ( & V_158 , V_152 -> V_162 , V_157 , V_156 , V_163 ) ;
V_161 = TRUE ;
V_159 = TRUE ;
F_79 ( & V_160 , V_159 , FALSE ) ;
if ( V_75 > 0 ) {
for( V_50 = 0 ; V_50 < V_76 ; V_50 ++ ) {
F_80 ( & V_160 , V_74 [ V_50 ] ) ;
}
}
printf ( L_86 , ( unsigned long int ) V_152 -> V_162 ) ;
F_81 ( & V_158 , & V_152 -> V_164 ,
& V_165 , V_166 , V_167 ) ;
F_82 ( & V_160 , V_157 , V_127 , & V_158 , & V_152 -> V_114 ) ;
F_83 ( & V_158 , & V_163 ) ;
V_168 = V_158 ;
V_166 = & V_168 ;
V_169 = V_158 ;
V_167 = & V_169 ;
for( V_50 = 0 ; V_50 < V_75 ; V_50 ++ ) {
if ( V_74 [ V_50 ] )
V_161 = F_84 ( V_74 [ V_50 ] , & V_160 ) ;
else
V_161 = TRUE ;
printf ( L_87 , V_161 ? 1 : 0 ) ;
}
printf ( L_88 ) ;
if ( V_95 )
fflush ( stdout ) ;
if ( ferror ( stdout ) ) {
F_85 ( V_18 ) ;
exit ( 2 ) ;
}
F_86 ( & V_160 ) ;
F_87 ( & V_158 ) ;
return V_161 ;
}
static const char * F_88 ( T_27 * V_170 )
{
if ( ! V_170 ) {
return L_89 ;
}
if ( V_77 -> V_112 > 0 && V_170 -> V_171 ) {
return L_90 ;
}
switch( V_170 -> type ) {
case V_172 :
return L_91 ;
case V_173 :
return L_92 ;
case V_174 :
return L_93 ;
case V_175 :
return L_94 ;
case V_176 :
return L_95 ;
case V_177 :
return L_96 ;
case V_178 :
return L_97 ;
case V_179 :
return L_98 ;
case V_180 :
return L_99 ;
case V_181 :
return L_100 ;
case V_182 :
return L_101 ;
case V_183 :
return L_102 ;
case V_184 :
return L_103 ;
case V_185 :
return L_104 ;
case V_186 :
return L_105 ;
case V_187 :
return L_106 ;
case V_188 :
return L_107 ;
case V_189 :
return L_90 ;
case V_190 :
return L_108 ;
case V_191 :
return L_109 ;
case V_192 :
return L_110 ;
case V_193 :
return L_111 ;
case V_194 :
return L_112 ;
case V_195 :
return L_113 ;
case V_196 :
return L_114 ;
case V_197 :
return L_115 ;
case V_198 :
return L_116 ;
case V_199 :
return L_117 ;
case V_200 :
return L_118 ;
case V_201 :
return L_119 ;
case V_202 :
return L_120 ;
default:
return L_89 ;
} ;
}
static const char * F_89 ( T_28 V_203 )
{
switch( V_203 ) {
case V_204 :
return L_121 ;
case V_205 :
return L_122 ;
default:
return L_89 ;
}
}
static const char * F_90 ( T_29 V_206 )
{
switch( V_206 ) {
case V_207 :
return L_123 ;
case V_208 :
return L_124 ;
case V_209 :
return L_125 ;
case V_210 :
return L_126 ;
case V_211 :
return L_127 ;
case V_212 :
return L_128 ;
default:
return L_89 ;
}
}
static T_1 F_91 ( T_30 * V_213 , int V_214 )
{
T_27 * V_215 ;
static char * V_216 = NULL ;
char * V_217 = V_216 ;
static T_15 * V_218 = NULL ;
int V_219 = V_220 , V_221 ;
T_19 V_50 ;
T_31 * V_222 ;
V_120 V_223 ;
T_32 V_224 ;
const T_33 * V_225 = & V_226 ;
V_215 = V_213 -> V_215 ;
if ( ! V_216 ) {
V_216 = ( char * ) F_92 ( V_219 + 1 ) ;
V_217 = V_216 ;
}
if ( ! V_218 ) {
V_218 = F_29 ( L_44 ) ;
}
if( V_213 -> V_227 . V_228 -> V_229 )
{
V_221 = F_93 ( & V_213 -> V_227 , V_230 ) ;
while ( V_219 < V_221 ) {
V_219 *= 2 ;
V_216 = ( char * ) F_94 ( V_216 , V_219 + 1 ) ;
V_217 = V_216 ;
}
F_95 ( & V_213 -> V_227 ,
V_230 ,
V_216 ) ;
if ( ( V_213 -> V_227 . V_228 -> V_228 == V_189 || V_213 -> V_227 . V_228 -> V_228 == V_190 ) && V_221 > 2 ) {
V_216 [ V_221 - 1 ] = '\0' ;
V_217 ++ ;
}
}
if ( V_77 -> V_112 > 0 && V_213 -> V_215 -> V_171 ) {
F_96 ( V_218 , 0 ) ;
for ( V_50 = 0 ; V_50 < V_77 -> V_112 ; V_50 ++ ) {
V_222 = ( T_31 * ) F_60 ( V_77 , V_50 ) ;
if ( V_222 -> V_231 ) {
F_97 ( V_218 , V_222 -> V_231 ) ;
} else {
switch ( V_222 -> V_232 ) {
case V_233 :
F_97 ( V_218 , V_215 -> V_234 ) ;
break;
case V_235 :
F_97 ( V_218 , V_217 ) ;
break;
case V_236 :
switch( V_215 -> type ) {
case V_174 :
V_223 = F_98 ( & V_213 -> V_227 ) ;
V_225 = ( const struct T_33 * ) V_215 -> V_171 ;
F_97 ( V_218 , V_223 ? V_225 -> V_237 : V_225 -> V_238 ) ;
break;
case V_180 :
case V_181 :
case V_182 :
case V_183 :
F_99 ( ! V_215 -> V_239 ) ;
V_224 = F_100 ( & V_213 -> V_227 ) ;
if ( V_215 -> V_240 & V_241 ) {
F_97 ( V_218 , F_101 ( V_224 , F_102 ( V_215 -> V_171 ) , L_129 ) ) ;
} else if ( V_215 -> V_240 & V_242 ) {
F_97 ( V_218 , F_103 ( V_224 , ( const V_243 * ) V_215 -> V_171 , L_129 ) ) ;
} else {
F_97 ( V_218 , F_104 ( V_224 , F_105 ( V_215 -> V_171 ) , L_129 ) ) ;
}
break;
case V_175 :
case V_176 :
case V_177 :
case V_178 :
V_223 = F_98 ( & V_213 -> V_227 ) ;
if ( ! V_215 -> V_239 && V_215 -> V_240 & V_241 ) {
F_97 ( V_218 , F_101 ( V_223 , F_102 ( V_215 -> V_171 ) , L_129 ) ) ;
} else if ( V_215 -> V_240 & V_242 ) {
F_97 ( V_218 , F_103 ( V_223 , ( const V_243 * ) V_215 -> V_171 , L_129 ) ) ;
} else {
F_97 ( V_218 , F_104 ( V_223 , F_105 ( V_215 -> V_171 ) , L_129 ) ) ;
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
printf ( L_130 , V_214 , V_218 -> V_42 ) ;
return TRUE ;
}
if( V_213 -> V_227 . V_228 -> V_229 )
{
printf ( L_130 , V_214 , V_217 ) ;
return TRUE ;
}
printf ( L_131 , V_214 ) ;
return TRUE ;
}
static int
F_106 ( void * V_244 , T_34 * T_35 V_6 , T_26 * V_160 , const void * T_36 V_6 )
{
T_37 * V_245 = ( T_37 * ) V_244 ;
T_18 * V_246 ;
T_19 V_50 ;
V_246 = F_107 ( V_160 -> V_247 , V_245 -> V_248 ) ;
if( ! V_246 ) {
printf ( L_132 ) ;
return 0 ;
}
for ( V_50 = 0 ; V_50 < V_246 -> V_112 ; V_50 ++ ) {
F_91 ( ( T_30 * ) V_246 -> V_249 [ V_50 ] , V_245 -> V_214 ) ;
}
return 0 ;
}
static void
F_59 ( char * V_250 )
{
T_37 * V_245 ;
T_27 * V_170 ;
T_15 * V_251 ;
V_170 = F_108 ( V_250 ) ;
if( ! V_170 ) {
fprintf ( V_5 , L_133 , V_250 ) ;
exit ( 1 ) ;
}
switch ( V_170 -> type ) {
case V_187 :
printf ( L_134 ,
V_252 ,
F_88 ( V_170 ) ,
F_89 ( ( T_28 ) V_170 -> V_240 ) ) ;
break;
default:
printf ( L_134 ,
V_252 ,
F_88 ( V_170 ) ,
F_90 ( ( T_29 ) V_170 -> V_240 ) ) ;
break;
}
V_245 = ( T_37 * ) F_92 ( sizeof( T_37 ) ) ;
V_245 -> V_248 = V_170 -> V_253 ;
V_245 -> V_254 = V_250 ;
V_245 -> V_214 = V_252 ++ ;
V_251 = F_109 ( L_135 , V_245 , V_245 -> V_254 , V_255 , NULL , F_106 , NULL ) ;
if( V_251 ) {
fprintf ( V_5 , L_136 ,
V_251 -> V_42 ) ;
F_32 ( V_251 , TRUE ) ;
if( V_245 -> V_254 ) {
F_16 ( V_245 -> V_254 ) ;
}
F_16 ( V_245 ) ;
exit ( 1 ) ;
}
}
static void
F_110 ( T_38 V_232 , T_3 * V_231 ) {
T_31 * V_222 = ( T_31 * ) F_92 ( sizeof( T_31 ) ) ;
V_222 -> V_232 = V_232 ;
V_222 -> V_231 = F_14 ( V_231 ) ;
F_54 ( V_77 , V_222 ) ;
}
static T_1
F_56 ( T_3 * V_232 ) {
T_15 * V_256 = F_29 ( L_44 ) ;
T_20 V_112 ;
T_20 V_10 = 0 ;
if ( ! V_232 ) {
return FALSE ;
}
V_112 = strlen ( V_232 ) ;
F_111 ( V_77 , 0 ) ;
while ( V_10 < V_112 ) {
if ( V_232 [ V_10 ] == '%' ) {
if ( V_10 >= V_112 ) {
return FALSE ;
}
V_10 ++ ;
if ( V_256 -> V_112 > 0 ) {
F_110 ( V_257 , V_256 -> V_42 ) ;
F_96 ( V_256 , 0 ) ;
}
switch ( V_232 [ V_10 ] ) {
case 'D' :
F_110 ( V_233 , NULL ) ;
break;
case 'N' :
F_110 ( V_235 , NULL ) ;
break;
case 'S' :
F_110 ( V_236 , NULL ) ;
break;
case '%' :
F_112 ( V_256 , '%' ) ;
break;
default:
return FALSE ;
}
} else {
F_112 ( V_256 , V_232 [ V_10 ] ) ;
}
V_10 ++ ;
}
if ( V_256 -> V_112 > 0 ) {
F_110 ( V_257 , V_256 -> V_42 ) ;
}
F_32 ( V_256 , TRUE ) ;
return TRUE ;
}
static void
F_85 ( int V_11 )
{
switch ( V_11 ) {
case V_258 :
F_49 ( L_137
L_138 ) ;
break;
#ifdef F_113
case F_113 :
F_49 ( L_139
L_140 ) ;
break;
#endif
default:
F_49 ( L_141 ,
F_9 ( V_11 ) ) ;
break;
}
}
static void
V_87 ( const char * V_154 , int V_11 , T_1 V_259 )
{
fprintf ( V_5 , L_142 ) ;
fprintf ( V_5 , F_114 ( V_11 , V_259 ) , V_154 ) ;
fprintf ( V_5 , L_5 ) ;
}
T_39
F_71 ( T_24 * V_152 , const char * V_260 )
{
if ( ( V_123 = F_4 ( V_260 ) ) < 0 )
return V_261 ;
F_115 () ;
F_116 () ;
V_152 -> V_262 = NULL ;
V_152 -> V_263 = 0 ;
V_152 -> V_154 = F_14 ( V_260 ) ;
V_152 -> V_264 = FALSE ;
V_152 -> V_265 = FALSE ;
V_152 -> V_266 = V_267 ;
V_152 -> V_162 = 0 ;
V_152 -> V_268 = FALSE ;
V_152 -> V_269 = 0 ;
V_152 -> V_270 = FALSE ;
V_152 -> V_271 = V_149 ;
F_117 ( & V_152 -> V_164 ) ;
F_118 ( & V_165 ) ;
V_166 = NULL ;
V_167 = NULL ;
return V_117 ;
}
static void
V_86 ( const char * V_272 , T_40 V_273 )
{
fprintf ( V_5 , L_142 ) ;
vfprintf ( V_5 , V_272 , V_273 ) ;
fprintf ( V_5 , L_5 ) ;
}
static void
V_88 ( const char * V_154 , int V_11 )
{
F_49 ( L_143 ,
V_154 , F_9 ( V_11 ) ) ;
}
static void
V_89 ( const char * V_154 , int V_11 )
{
F_49 ( L_144 ,
V_154 , F_9 ( V_11 ) ) ;
}
void
F_49 ( const char * V_274 , ... )
{
T_40 V_273 ;
va_start ( V_273 , V_274 ) ;
fprintf ( V_5 , L_142 ) ;
vfprintf ( V_5 , V_274 , V_273 ) ;
fprintf ( V_5 , L_5 ) ;
va_end ( V_273 ) ;
}
void
F_57 ( const char * V_274 , ... )
{
T_40 V_273 ;
va_start ( V_273 , V_274 ) ;
vfprintf ( V_5 , V_274 , V_273 ) ;
fprintf ( V_5 , L_5 ) ;
va_end ( V_273 ) ;
}
