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
F_44 ( V_81 , V_82 , V_83 ,
V_84 ) ;
F_45 ( V_85 ) ;
F_46 ( V_86 ) ;
F_47 ( V_87 ) ;
F_48 ( V_88 , V_89 , NULL , NULL ) ;
setlocale ( V_90 , L_44 ) ;
V_66 = F_49 ( & V_57 , & V_58 , & V_53 ,
& V_59 , & V_60 , & V_54 ) ;
if ( V_53 != NULL ) {
if ( V_57 != 0 ) {
F_50 ( L_45 ,
V_54 , F_9 ( V_57 ) ) ;
}
if ( V_58 != 0 ) {
F_50 ( L_46 ,
V_54 , F_9 ( V_58 ) ) ;
}
}
if ( V_54 != NULL ) {
if ( V_59 != 0 ) {
F_50 ( L_47 , V_54 ,
F_9 ( V_59 ) ) ;
}
if ( V_60 != 0 ) {
F_50 ( L_48 ,
V_54 , F_9 ( V_60 ) ) ;
}
F_16 ( V_54 ) ;
V_54 = NULL ;
}
F_51 ( & V_55 , & V_61 , & V_62 ,
& V_56 , & V_63 , & V_64 ) ;
if ( V_55 != NULL ) {
if ( V_61 != 0 ) {
F_50 ( L_49 ,
V_55 , F_9 ( V_61 ) ) ;
}
if ( V_62 != 0 ) {
F_50 ( L_50 ,
V_55 , F_9 ( V_62 ) ) ;
}
F_16 ( V_55 ) ;
}
if ( V_56 != NULL ) {
if ( V_63 != 0 ) {
F_50 (
L_51 , V_56 ,
F_9 ( V_63 ) ) ;
}
if ( V_64 != 0 ) {
F_50 (
L_52 , V_56 ,
F_9 ( V_64 ) ) ;
}
F_16 ( V_56 ) ;
}
#ifdef F_5
F_52 () ;
#endif
F_53 ( & V_91 ) ;
V_92 = V_93 ;
V_39 = V_40 ;
while ( ( V_49 = F_54 ( V_46 , V_47 , V_72 ) ) != - 1 ) {
switch ( V_49 ) {
case 'd' :
if ( ! F_25 ( V_94 ) ) {
F_50 ( L_53 , V_94 ) ;
exit ( 1 ) ;
}
break;
case 'F' :
F_55 ( V_69 , F_14 ( V_94 ) ) ;
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
V_67 = F_56 ( V_94 , & V_96 ) ;
if ( V_67 != '\0' ) {
F_50 ( L_54 ,
V_67 ) ;
exit ( 1 ) ;
}
break;
case 'o' :
switch ( F_31 ( V_94 ) ) {
case V_43 :
break;
case V_101 :
F_50 ( L_55 , V_94 ) ;
exit ( 1 ) ;
break;
case V_102 :
case V_103 :
F_50 ( L_56 , V_94 ) ;
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
F_50 ( L_57 ) ;
exit ( 1 ) ;
}
break;
case 's' :
V_71 = TRUE ;
break;
case 'S' :
if ( ! F_57 ( V_94 ) ) {
F_50 ( L_58 ) ;
exit ( 1 ) ;
}
break;
case 't' :
if ( strcmp ( V_94 , L_59 ) == 0 )
F_45 ( V_85 ) ;
else if ( strcmp ( V_94 , L_60 ) == 0 )
F_45 ( V_105 ) ;
else if ( strcmp ( V_94 , L_61 ) == 0 )
F_45 ( V_106 ) ;
else if ( strcmp ( V_94 , L_62 ) == 0 )
F_45 ( V_107 ) ;
else if ( strcmp ( V_94 , L_63 ) == 0 )
F_45 ( V_108 ) ;
else if ( strcmp ( V_94 , L_64 ) == 0 )
F_45 ( V_109 ) ;
else if ( strcmp ( V_94 , L_65 ) == 0 )
F_45 ( V_110 ) ;
else if ( strcmp ( V_94 , L_66 ) == 0 )
F_45 ( V_111 ) ;
else if ( strcmp ( V_94 , L_67 ) == 0 )
F_45 ( V_112 ) ;
else if ( strcmp ( V_94 , L_68 ) == 0 )
F_45 ( V_113 ) ;
else {
F_50 ( L_69 ,
V_94 ) ;
F_58 (
L_70 ) ;
F_58 (
L_71 ) ;
F_58 (
L_72 ) ;
F_58 (
L_73 ) ;
F_58 (
L_74 ) ;
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
F_59 () ;
for ( V_70 = 0 ; V_70 < V_69 -> V_114 ; V_70 ++ ) {
F_60 ( ( char * ) F_61 ( V_69 , V_70 ) ) ;
}
F_62 ( V_69 , TRUE ) ;
printf ( L_5 ) ;
fflush ( stdout ) ;
if ( V_115 < V_46 ) {
if ( V_7 != NULL ) {
if ( V_75 != 0 ) {
F_50 ( L_75
L_76 ) ;
exit ( 1 ) ;
}
V_65 [ V_75 ] = F_63 ( V_46 , V_47 , V_115 ) ;
}
}
if ( V_39 == V_40 ) {
F_50 ( L_77 ) ;
exit ( 1 ) ;
}
if ( V_51 ) {
F_1 ( FALSE ) ;
exit ( 1 ) ;
}
#ifdef F_5
F_64 ( F_65 ( 1 , 1 ) , & V_52 ) ;
#endif
F_66 () ;
if ( V_55 == NULL && V_56 == NULL ) {
F_67 () ;
}
F_68 ( & V_91 . V_116 , V_66 -> V_117 , TRUE ) ;
if ( V_75 != 0 ) {
for ( V_50 = 0 ; V_50 < V_75 ; V_50 ++ ) {
if ( ! F_69 ( V_65 [ V_50 ] , & V_74 [ V_76 ] ) ) {
F_50 ( L_6 , V_118 ) ;
F_70 ( V_91 . V_119 ) ;
F_71 () ;
exit ( 2 ) ;
}
V_76 ++ ;
}
}
if ( V_7 ) {
F_72 () ;
if ( F_73 ( & V_91 , V_7 ) != V_120 ) {
F_70 ( V_91 . V_119 ) ;
F_71 () ;
exit ( 2 ) ;
}
if ( V_71 ) {
T_20 V_121 = sizeof( struct V_122 ) + sizeof( V_123 ) ;
T_3 V_124 [ sizeof( struct V_122 ) + sizeof( V_123 ) ] ;
while ( V_121 != 0 ) {
T_21 V_125 = F_74 ( V_126 , V_124 , ( int ) V_121 ) ;
if ( V_125 <= 0 ) {
F_50 ( L_78 ) ;
exit ( 2 ) ;
}
V_121 -= V_125 ;
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
F_46 ( V_127 ) ;
#endif
V_11 = F_75 ( & V_91 ) ;
if ( V_11 != 0 ) {
F_70 ( V_91 . V_119 ) ;
F_71 () ;
exit ( 2 ) ;
}
} else {
F_50 ( L_79 ) ;
exit ( 2 ) ;
}
F_70 ( V_91 . V_119 ) ;
F_71 () ;
return 0 ;
}
static T_1
F_76 ( struct V_128 * V_129 , T_22 * V_130 , int * V_11 , const T_3 * * V_131 , T_23 * V_132 ) {
struct V_133 V_134 ;
struct V_135 V_136 ;
T_21 V_137 = 0 ;
T_20 V_138 = sizeof( V_136 ) ;
T_22 * V_139 = ( T_22 * ) & V_136 ;
static T_3 V_12 [ 100 ] ;
if ( V_104 ) {
V_138 = sizeof( V_134 ) ;
V_139 = ( T_22 * ) & V_134 ;
}
while ( V_138 > 0 ) {
V_137 = F_74 ( V_126 , V_139 , ( int ) V_138 ) ;
if ( V_137 == 0 ) {
* V_11 = 0 ;
return FALSE ;
} else if ( V_137 < 0 ) {
* V_11 = V_140 ;
* V_131 = L_80 ;
return FALSE ;
}
V_138 -= V_137 ;
* V_132 += V_137 ;
V_139 += V_137 ;
}
if ( V_104 ) {
V_129 -> V_141 . V_142 = V_134 . V_141 . V_143 ;
V_129 -> V_141 . V_144 = ( V_145 ) V_134 . V_141 . V_146 * 1000 ;
V_129 -> V_147 = V_134 . V_147 ;
V_129 -> V_114 = V_134 . V_114 ;
} else {
V_129 -> V_141 . V_142 = V_136 . V_148 ;
V_129 -> V_141 . V_144 = V_136 . V_149 * 1000 ;
V_129 -> V_147 = V_136 . V_150 ;
V_129 -> V_114 = V_136 . V_151 ;
}
V_138 = V_129 -> V_147 ;
V_129 -> V_152 = V_39 ;
#if 0
printf("mem_hdr: %lu disk_hdr: %lu\n", sizeof(mem_hdr), sizeof(disk_hdr));
printf("tv_sec: %u (%04x)\n", (unsigned int) phdr->ts.secs, (unsigned int) phdr->ts.secs);
printf("tv_nsec: %d (%04x)\n", phdr->ts.nsecs, phdr->ts.nsecs);
printf("caplen: %d (%04x)\n", phdr->caplen, phdr->caplen);
printf("len: %d (%04x)\n", phdr->len, phdr->len);
#endif
if ( V_138 > V_153 ) {
* V_11 = V_154 ;
F_77 ( V_12 , 100 , L_81 ,
( unsigned long ) V_138 ) ;
* V_131 = V_12 ;
return FALSE ;
}
V_139 = V_130 ;
while ( V_138 > 0 ) {
V_137 = F_74 ( V_126 , V_139 , ( int ) V_138 ) ;
if ( V_137 == 0 ) {
* V_11 = V_155 ;
* V_131 = L_82 ;
return FALSE ;
} else if ( V_137 < 0 ) {
* V_11 = V_140 ;
* V_131 = L_83 ;
return FALSE ;
}
V_138 -= V_137 ;
* V_132 += V_137 ;
V_139 += V_137 ;
}
return TRUE ;
}
static int
F_75 ( T_24 * V_156 )
{
int V_11 ;
const T_3 * V_131 ;
T_23 V_132 = 0 ;
T_22 V_130 [ V_153 ] ;
struct V_128 V_129 ;
T_25 V_157 ;
memset ( & V_129 , 0 , sizeof( V_129 ) ) ;
F_78 ( & V_157 , V_156 -> V_119 , TRUE , FALSE ) ;
while ( F_76 ( & V_129 , V_130 , & V_11 , & V_131 , & V_132 ) ) {
F_79 ( V_156 , & V_157 , V_132 , & V_129 , V_130 ) ;
}
F_80 ( & V_157 ) ;
if ( V_11 != 0 ) {
switch ( V_11 ) {
case V_158 :
F_50 ( L_84 ,
V_156 -> V_159 , V_131 ) ;
break;
case V_140 :
F_50 ( L_85 ,
V_156 -> V_159 ) ;
break;
case V_155 :
F_50 ( L_86 ,
V_156 -> V_159 ) ;
break;
case V_154 :
F_50 ( L_87 ,
V_156 -> V_159 , V_131 ) ;
break;
case V_160 :
F_50 ( L_88 ,
V_156 -> V_159 , V_131 ) ;
break;
default:
F_50 ( L_89 ,
V_156 -> V_159 , F_81 ( V_11 ) ) ;
break;
}
}
return V_11 ;
}
static T_1
F_79 ( T_24 * V_156 , T_25 * V_157 , T_23 V_161 ,
struct V_128 * V_162 , const T_22 * V_130 )
{
T_26 V_163 ;
T_1 V_164 ;
int V_50 ;
if( V_162 -> V_114 == 0 )
{
printf ( L_90 , ( unsigned long int ) V_156 -> V_165 ,
( unsigned long int ) V_162 -> V_141 . V_142 ,
( unsigned long int ) V_162 -> V_141 . V_144 ) ;
fflush ( stdout ) ;
return FALSE ;
}
V_156 -> V_165 ++ ;
F_82 ( & V_163 , V_156 -> V_165 , V_162 , V_161 , V_166 ) ;
V_164 = TRUE ;
if ( V_75 > 0 ) {
for( V_50 = 0 ; V_50 < V_76 ; V_50 ++ ) {
F_83 ( V_157 , V_74 [ V_50 ] ) ;
}
}
printf ( L_91 , ( unsigned long int ) V_156 -> V_165 ) ;
F_84 ( & V_163 , & V_156 -> V_167 ,
& V_168 , V_169 ) ;
if ( V_168 == & V_163 ) {
V_170 = V_163 ;
V_168 = & V_170 ;
}
F_85 ( V_157 , V_156 -> V_171 , V_162 , F_86 ( & V_163 , V_130 ) , & V_163 , & V_156 -> V_116 ) ;
F_87 ( & V_163 , & V_166 ) ;
V_172 = V_163 ;
V_169 = & V_172 ;
V_173 = V_163 ;
V_174 = & V_173 ;
for( V_50 = 0 ; V_50 < V_75 ; V_50 ++ ) {
if ( V_74 [ V_50 ] )
V_164 = F_88 ( V_74 [ V_50 ] , V_157 ) ;
else
V_164 = TRUE ;
printf ( L_92 , V_164 ? 1 : 0 ) ;
}
printf ( L_93 ) ;
if ( V_95 )
fflush ( stdout ) ;
if ( ferror ( stdout ) ) {
F_89 ( V_18 ) ;
exit ( 2 ) ;
}
F_90 ( V_157 ) ;
F_91 ( & V_163 ) ;
return V_164 ;
}
static const char * F_92 ( T_27 * V_175 )
{
if ( ! V_175 ) {
return L_94 ;
}
if ( V_77 -> V_114 > 0 && V_175 -> V_176 ) {
return L_95 ;
}
switch( V_175 -> type ) {
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
return L_95 ;
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
case V_203 :
return L_121 ;
case V_204 :
return L_122 ;
case V_205 :
return L_123 ;
case V_206 :
return L_124 ;
case V_207 :
return L_125 ;
case V_208 :
return L_126 ;
case V_209 :
return L_127 ;
case V_210 :
return L_128 ;
default:
return L_94 ;
} ;
}
static const char * F_93 ( T_28 V_211 )
{
switch( V_211 ) {
case V_212 :
return L_129 ;
case V_213 :
return L_130 ;
default:
return L_94 ;
}
}
static const char * F_94 ( T_29 V_214 )
{
switch( V_214 ) {
case V_215 :
return L_131 ;
case V_216 :
return L_132 ;
case V_217 :
return L_133 ;
case V_218 :
return L_134 ;
case V_219 :
return L_135 ;
case V_220 :
return L_136 ;
default:
return L_94 ;
}
}
static T_1 F_95 ( T_30 * V_221 , int V_222 )
{
T_27 * V_223 ;
static char * V_224 = NULL ;
char * V_225 = V_224 ;
static T_15 * V_226 = NULL ;
int V_227 = V_228 , V_229 ;
T_19 V_50 ;
T_31 * V_230 ;
V_123 V_231 ;
V_145 V_232 ;
T_32 V_233 ;
T_23 V_234 ;
const T_33 * V_235 = & V_236 ;
V_223 = V_221 -> V_223 ;
if ( ! V_224 ) {
V_224 = ( char * ) F_96 ( V_227 + 1 ) ;
V_225 = V_224 ;
}
if ( ! V_226 ) {
V_226 = F_29 ( L_44 ) ;
}
if( V_221 -> V_237 . V_238 -> V_239 )
{
V_229 = F_97 ( & V_221 -> V_237 , V_240 ) ;
while ( V_227 < V_229 ) {
V_227 *= 2 ;
V_224 = ( char * ) F_98 ( V_224 , V_227 + 1 ) ;
V_225 = V_224 ;
}
F_99 ( & V_221 -> V_237 ,
V_240 ,
V_224 ) ;
if ( F_100 ( V_221 -> V_237 . V_238 -> V_238 ) && V_229 > 2 ) {
V_224 [ V_229 - 1 ] = '\0' ;
V_225 ++ ;
}
}
if ( V_77 -> V_114 > 0 && V_221 -> V_223 -> V_176 ) {
F_101 ( V_226 , 0 ) ;
for ( V_50 = 0 ; V_50 < V_77 -> V_114 ; V_50 ++ ) {
V_230 = ( T_31 * ) F_61 ( V_77 , V_50 ) ;
if ( V_230 -> V_241 ) {
F_102 ( V_226 , V_230 -> V_241 ) ;
} else {
switch ( V_230 -> V_242 ) {
case V_243 :
F_102 ( V_226 , V_223 -> V_244 ) ;
break;
case V_245 :
F_102 ( V_226 , V_225 ) ;
break;
case V_246 :
switch( V_223 -> type ) {
case V_179 :
V_231 = F_103 ( & V_221 -> V_237 ) ;
V_235 = ( const struct T_33 * ) V_223 -> V_176 ;
F_102 ( V_226 , V_231 ? V_235 -> V_247 : V_235 -> V_248 ) ;
break;
case V_185 :
case V_186 :
case V_187 :
case V_188 :
F_104 ( ! V_223 -> V_249 ) ;
V_232 = F_105 ( & V_221 -> V_237 ) ;
if ( V_223 -> V_250 & V_251 ) {
F_102 ( V_226 , F_106 ( V_232 , F_107 ( V_223 -> V_176 ) , L_137 ) ) ;
} else if ( V_223 -> V_250 & V_252 ) {
F_102 ( V_226 , F_108 ( V_232 , ( const V_253 * ) V_223 -> V_176 , L_137 ) ) ;
} else {
F_102 ( V_226 , F_109 ( V_232 , F_110 ( V_223 -> V_176 ) , L_137 ) ) ;
}
break;
case V_189 :
F_104 ( ! V_223 -> V_249 ) ;
V_234 = ( T_23 ) F_111 ( & V_221 -> V_237 ) ;
if ( V_223 -> V_250 & V_254 ) {
F_102 ( V_226 , F_112 ( V_234 , ( const V_255 * ) ( V_223 -> V_176 ) , L_137 ) ) ;
}
break;
case V_180 :
case V_181 :
case V_182 :
case V_183 :
V_231 = F_103 ( & V_221 -> V_237 ) ;
if ( ! V_223 -> V_249 && V_223 -> V_250 & V_251 ) {
F_102 ( V_226 , F_106 ( V_231 , F_107 ( V_223 -> V_176 ) , L_137 ) ) ;
} else if ( V_223 -> V_250 & V_252 ) {
F_102 ( V_226 , F_108 ( V_231 , ( const V_253 * ) V_223 -> V_176 , L_137 ) ) ;
} else {
F_102 ( V_226 , F_109 ( V_231 , F_110 ( V_223 -> V_176 ) , L_137 ) ) ;
}
break;
case V_184 :
F_104 ( ! V_223 -> V_249 ) ;
V_233 = F_111 ( & V_221 -> V_237 ) ;
if ( V_223 -> V_250 & V_254 ) {
F_102 ( V_226 , F_112 ( V_233 , ( const V_255 * ) ( V_223 -> V_176 ) , L_137 ) ) ;
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
printf ( L_138 , V_222 , V_226 -> V_42 ) ;
return TRUE ;
}
if( V_221 -> V_237 . V_238 -> V_239 )
{
printf ( L_138 , V_222 , V_225 ) ;
return TRUE ;
}
printf ( L_139 , V_222 ) ;
return TRUE ;
}
static int
F_113 ( void * V_256 , T_34 * T_35 V_6 , T_25 * V_157 , const void * T_36 V_6 )
{
T_37 * V_257 = ( T_37 * ) V_256 ;
T_18 * V_258 ;
T_19 V_50 ;
V_258 = F_114 ( V_157 -> V_259 , V_257 -> V_260 ) ;
if( ! V_258 ) {
printf ( L_140 ) ;
return 0 ;
}
for ( V_50 = 0 ; V_50 < V_258 -> V_114 ; V_50 ++ ) {
F_95 ( ( T_30 * ) V_258 -> V_261 [ V_50 ] , V_257 -> V_222 ) ;
}
return 0 ;
}
static void
F_60 ( char * V_262 )
{
T_37 * V_257 ;
T_27 * V_175 ;
T_15 * V_263 ;
V_175 = F_115 ( V_262 ) ;
if( ! V_175 ) {
fprintf ( V_5 , L_141 , V_262 ) ;
exit ( 1 ) ;
}
switch ( V_175 -> type ) {
case V_192 :
printf ( L_142 ,
V_264 ,
F_92 ( V_175 ) ,
F_93 ( ( T_28 ) V_175 -> V_250 ) ) ;
break;
default:
printf ( L_142 ,
V_264 ,
F_92 ( V_175 ) ,
F_94 ( ( T_29 ) V_175 -> V_250 ) ) ;
break;
}
V_257 = ( T_37 * ) F_96 ( sizeof( T_37 ) ) ;
V_257 -> V_260 = V_175 -> V_265 ;
V_257 -> V_266 = V_262 ;
V_257 -> V_222 = V_264 ++ ;
V_263 = F_116 ( L_143 , V_257 , V_257 -> V_266 , V_267 , NULL , F_113 , NULL ) ;
if( V_263 ) {
fprintf ( V_5 , L_144 ,
V_263 -> V_42 ) ;
F_32 ( V_263 , TRUE ) ;
if( V_257 -> V_266 ) {
F_16 ( V_257 -> V_266 ) ;
}
F_16 ( V_257 ) ;
exit ( 1 ) ;
}
}
static void
F_117 ( T_38 V_242 , T_3 * V_241 ) {
T_31 * V_230 = ( T_31 * ) F_96 ( sizeof( T_31 ) ) ;
V_230 -> V_242 = V_242 ;
V_230 -> V_241 = F_14 ( V_241 ) ;
F_55 ( V_77 , V_230 ) ;
}
static T_1
F_57 ( T_3 * V_242 ) {
T_15 * V_268 = F_29 ( L_44 ) ;
T_20 V_114 ;
T_20 V_10 = 0 ;
if ( ! V_242 ) {
return FALSE ;
}
V_114 = strlen ( V_242 ) ;
F_118 ( V_77 , 0 ) ;
while ( V_10 < V_114 ) {
if ( V_242 [ V_10 ] == '%' ) {
if ( V_10 >= V_114 ) {
return FALSE ;
}
V_10 ++ ;
if ( V_268 -> V_114 > 0 ) {
F_117 ( V_269 , V_268 -> V_42 ) ;
F_101 ( V_268 , 0 ) ;
}
switch ( V_242 [ V_10 ] ) {
case 'D' :
F_117 ( V_243 , NULL ) ;
break;
case 'N' :
F_117 ( V_245 , NULL ) ;
break;
case 'S' :
F_117 ( V_246 , NULL ) ;
break;
case '%' :
F_119 ( V_268 , '%' ) ;
break;
default:
return FALSE ;
}
} else {
F_119 ( V_268 , V_242 [ V_10 ] ) ;
}
V_10 ++ ;
}
if ( V_268 -> V_114 > 0 ) {
F_117 ( V_269 , V_268 -> V_42 ) ;
}
F_32 ( V_268 , TRUE ) ;
return TRUE ;
}
static void
F_89 ( int V_11 )
{
switch ( V_11 ) {
case V_270 :
F_50 ( L_145
L_146 ) ;
break;
#ifdef F_120
case F_120 :
F_50 ( L_147
L_148 ) ;
break;
#endif
default:
F_50 ( L_149 ,
F_9 ( V_11 ) ) ;
break;
}
}
static void
V_82 ( const char * V_159 , int V_11 , T_1 V_271 )
{
fprintf ( V_5 , L_150 ) ;
fprintf ( V_5 , F_121 ( V_11 , V_271 ) , V_159 ) ;
fprintf ( V_5 , L_5 ) ;
}
static const T_39 *
F_122 ( void * T_40 V_6 , V_123 V_272 )
{
if ( V_168 && V_168 -> V_273 == V_272 )
return & V_168 -> V_274 ;
if ( V_169 && V_169 -> V_273 == V_272 )
return & V_169 -> V_274 ;
if ( V_174 && V_174 -> V_273 == V_272 )
return & V_174 -> V_274 ;
return NULL ;
}
static T_41 *
F_123 ( T_24 * V_156 )
{
T_41 * V_119 = F_124 () ;
V_119 -> T_40 = V_156 ;
V_119 -> V_275 = F_122 ;
V_119 -> V_276 = V_277 ;
V_119 -> V_278 = NULL ;
return V_119 ;
}
T_42
F_73 ( T_24 * V_156 , const char * V_279 )
{
if ( ( V_126 = F_4 ( V_279 ) ) < 0 )
return V_280 ;
F_70 ( V_156 -> V_119 ) ;
V_156 -> V_119 = F_123 ( V_156 ) ;
V_156 -> V_281 = NULL ;
V_156 -> V_282 = 0 ;
V_156 -> V_159 = F_14 ( V_279 ) ;
V_156 -> V_283 = FALSE ;
V_156 -> V_284 = FALSE ;
V_156 -> V_171 = V_285 ;
V_156 -> V_286 = V_287 ;
V_156 -> V_165 = 0 ;
V_156 -> V_288 = FALSE ;
V_156 -> V_289 = 0 ;
V_156 -> V_290 = FALSE ;
V_156 -> V_291 = V_153 ;
F_125 ( & V_156 -> V_167 ) ;
V_168 = NULL ;
V_169 = NULL ;
V_174 = NULL ;
return V_120 ;
}
static void
V_81 ( const char * V_292 , T_43 V_293 )
{
fprintf ( V_5 , L_150 ) ;
vfprintf ( V_5 , V_292 , V_293 ) ;
fprintf ( V_5 , L_5 ) ;
}
static void
V_83 ( const char * V_159 , int V_11 )
{
F_50 ( L_151 ,
V_159 , F_9 ( V_11 ) ) ;
}
static void
V_84 ( const char * V_159 , int V_11 )
{
F_50 ( L_152 ,
V_159 , F_9 ( V_11 ) ) ;
}
void
F_50 ( const char * V_294 , ... )
{
T_43 V_293 ;
va_start ( V_293 , V_294 ) ;
fprintf ( V_5 , L_150 ) ;
vfprintf ( V_5 , V_294 , V_293 ) ;
fprintf ( V_5 , L_5 ) ;
va_end ( V_293 ) ;
}
void
F_58 ( const char * V_294 , ... )
{
T_43 V_293 ;
va_start ( V_293 , V_294 ) ;
vfprintf ( V_5 , V_294 , V_293 ) ;
fprintf ( V_5 , L_5 ) ;
va_end ( V_293 ) ;
}
