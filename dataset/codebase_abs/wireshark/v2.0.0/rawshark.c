static void
F_1 ( T_1 * V_1 )
{
fprintf ( V_1 , L_1 ) ;
fprintf ( V_1 , L_2 ) ;
fprintf ( V_1 , L_1 ) ;
fprintf ( V_1 , L_3 ) ;
fprintf ( V_1 , L_4 ) ;
fprintf ( V_1 , L_1 ) ;
fprintf ( V_1 , L_5 ) ;
fprintf ( V_1 , L_6 ) ;
fprintf ( V_1 , L_7 ) ;
fprintf ( V_1 , L_8 ) ;
fprintf ( V_1 , L_9 ) ;
fprintf ( V_1 , L_10 ) ;
fprintf ( V_1 , L_11 ) ;
fprintf ( V_1 , L_12 ) ;
fprintf ( V_1 , L_13 ) ;
fprintf ( V_1 , L_14 ) ;
fprintf ( V_1 , L_1 ) ;
fprintf ( V_1 , L_15 ) ;
fprintf ( V_1 , L_16 ) ;
fprintf ( V_1 , L_17 ) ;
fprintf ( V_1 , L_18 ) ;
fprintf ( V_1 , L_19 ) ;
fprintf ( V_1 , L_1 ) ;
fprintf ( V_1 , L_20 ) ;
fprintf ( V_1 , L_21 ) ;
fprintf ( V_1 , L_22 ) ;
fprintf ( V_1 , L_23 ) ;
}
static void
F_2 ( const T_2 * T_3 V_2 , T_4 T_5 V_2 ,
const T_2 * T_6 V_2 , T_7 T_8 V_2 )
{
}
static int
F_3 ( const char * V_3 )
{
#ifndef F_4
T_9 V_4 ;
#else
char * V_5 , * V_6 = NULL ;
T_10 V_7 ;
T_11 * V_8 ;
T_12 V_9 = NULL ;
#endif
int V_10 ;
F_5 ( V_11 , V_12 , L_24 , V_3 ) ;
if ( strcmp ( V_3 , L_25 ) == 0 ) {
V_10 = 0 ;
#ifdef F_4
F_6 ( 0 , V_13 ) ;
#endif
} else {
#ifndef F_4
if ( F_7 ( V_3 , & V_4 ) < 0 ) {
fprintf ( V_14 , L_26 ,
V_3 , F_8 ( V_15 ) ) ;
return - 1 ;
}
if ( ! F_9 ( V_4 . V_16 ) ) {
if ( F_10 ( V_4 . V_16 ) ) {
} else
{
fprintf ( V_14 , L_27 ,
V_3 ) ;
}
return - 1 ;
}
V_10 = F_11 ( V_3 , V_17 | V_18 , 0000 ) ;
if ( V_10 == - 1 ) {
fprintf ( V_14 , L_28 ,
V_3 , F_8 ( V_15 ) ) ;
return - 1 ;
}
#else
#define F_12 "\\pipe\\"
V_5 = F_13 ( V_3 ) ;
if ( strstr ( V_5 , L_29 ) == V_5 ) {
V_6 = strchr ( V_5 + 3 , '\\' ) ;
if ( V_6 && F_14 ( V_6 , F_12 , strlen ( F_12 ) ) != 0 )
V_6 = NULL ;
}
F_15 ( V_5 ) ;
if ( ! V_6 ) {
fprintf ( V_14 , L_27 ,
V_3 ) ;
return - 1 ;
}
while ( 1 ) {
V_9 = F_16 ( F_17 ( V_3 ) , V_19 , 0 , NULL ,
V_20 , 0 , NULL ) ;
if ( V_9 != V_21 )
break;
V_7 = F_18 () ;
if ( V_7 != V_22 ) {
F_19 ( V_23 | V_24 | V_25 ,
NULL , V_7 , 0 , ( V_26 ) & V_8 , 0 , NULL ) ;
fprintf ( V_14 , L_30 ,
V_3 , F_20 ( V_8 ) , V_7 ) ;
F_21 ( V_8 ) ;
return - 1 ;
}
if ( ! F_22 ( F_17 ( V_3 ) , 30 * 1000 ) ) {
V_7 = F_18 () ;
F_19 ( V_23 | V_24 | V_25 ,
NULL , V_7 , 0 , ( V_26 ) & V_8 , 0 , NULL ) ;
fprintf ( V_14 , L_31 ,
V_3 , F_20 ( V_8 ) , V_7 ) ;
F_21 ( V_8 ) ;
return - 1 ;
}
}
V_10 = F_23 ( ( V_27 ) V_9 , V_28 ) ;
if ( V_10 == - 1 ) {
fprintf ( V_14 , L_28 ,
V_3 , F_8 ( V_15 ) ) ;
return - 1 ;
}
#endif
}
return V_10 ;
}
static T_13
F_24 ( const char * V_29 ) {
char * V_30 = strchr ( V_29 , ':' ) ;
char * V_31 ;
int V_32 ;
long V_33 ;
T_14 V_34 ;
T_15 * V_35 ;
if ( ! V_30 )
return FALSE ;
V_30 ++ ;
if ( strncmp ( V_29 , L_32 , strlen ( L_32 ) ) == 0 ) {
V_32 = F_25 ( V_30 ) ;
if ( V_32 == - 1 ) {
V_15 = 0 ;
V_33 = strtol ( V_30 , & V_31 , 10 ) ;
if ( V_31 == V_30 || * V_31 != '\0' || V_15 != 0 || V_33 > V_36 ) {
return FALSE ;
}
V_32 = ( int ) V_33 ;
}
V_37 = F_26 ( V_32 ) ;
if ( V_37 == V_38 ) {
return FALSE ;
}
return TRUE ;
} else if ( strncmp ( V_29 , L_33 , strlen ( L_33 ) ) == 0 ) {
V_34 = F_27 ( V_30 ) ;
if ( V_34 ) {
V_37 = V_39 ;
V_35 = F_28 ( L_34 ) ;
F_29 ( V_35 ,
L_35 ,
V_30 ) ;
if ( F_30 ( V_35 -> V_40 ) != V_41 ) {
F_31 ( V_35 , TRUE ) ;
return FALSE ;
}
F_31 ( V_35 , TRUE ) ;
return TRUE ;
}
}
return FALSE ;
}
int
main ( int V_42 , char * V_43 [] )
{
T_15 * V_44 ;
T_15 * V_45 ;
char * V_46 ;
int V_47 , V_48 ;
T_13 V_49 = FALSE ;
#ifdef F_4
T_16 V_50 ;
#endif
char * V_51 , * V_52 ;
char * V_53 , * V_54 ;
int V_55 , V_56 ;
int V_57 , V_58 ;
int V_59 , V_60 ;
int V_61 , V_62 ;
T_2 * V_3 = NULL ;
T_2 * V_63 [ 64 ] ;
T_17 * V_64 ;
char V_65 ;
int V_66 ;
T_18 * V_67 = F_32 () ;
T_19 V_68 ;
T_13 V_69 = FALSE ;
F_33 (cast-qual)
static const struct V_70 V_71 [] = {
{ ( char * ) L_36 , V_72 , NULL , 'h' } ,
{ ( char * ) L_37 , V_72 , NULL , 'v' } ,
{ 0 , 0 , 0 , 0 }
} ;
F_34 (cast-qual)
#define F_35 "d:F:hlnN:o:pr:R:sS:t:v"
static const char V_73 [] = F_35 ;
setlocale ( V_74 , L_38 ) ;
F_36 ( V_75 , V_76 ) ;
V_44 = F_37 ( NULL , V_77 ) ;
V_45 = F_38 ( NULL ) ;
F_39 ( L_39
L_1
L_40
L_1
L_40 ,
F_40 () , V_44 -> V_40 , V_45 -> V_40 ) ;
#ifdef F_4
F_41 ( V_42 , V_43 ) ;
F_42 () ;
#endif
F_43 () ;
memset ( V_63 , 0 , sizeof( V_63 ) ) ;
memset ( V_78 , 0 , sizeof( V_78 ) ) ;
V_79 = 0 ;
V_80 = 0 ;
V_81 = F_32 () ;
V_46 = F_44 ( V_43 [ 0 ] , ( void * )main ) ;
if ( V_46 != NULL ) {
fprintf ( V_14 , L_41 ,
V_46 ) ;
}
V_66 =
V_82 |
V_83 |
V_84 |
V_12 ;
F_45 ( NULL ,
( T_4 ) V_66 ,
F_2 , NULL ) ;
F_45 ( V_11 ,
( T_4 ) V_66 ,
F_2 , NULL ) ;
F_46 ( V_85 , V_86 , V_87 ,
V_88 ) ;
F_47 ( V_89 ) ;
F_48 ( V_90 ) ;
F_49 ( V_91 ) ;
F_50 ( V_92 , V_93 , NULL , NULL ) ;
V_64 = F_51 ( & V_55 , & V_56 , & V_51 ,
& V_57 , & V_58 , & V_52 ) ;
if ( V_51 != NULL ) {
if ( V_55 != 0 ) {
F_52 ( L_42 ,
V_52 , F_8 ( V_55 ) ) ;
}
if ( V_56 != 0 ) {
F_52 ( L_43 ,
V_52 , F_8 ( V_56 ) ) ;
}
}
if ( V_52 != NULL ) {
if ( V_57 != 0 ) {
F_52 ( L_44 , V_52 ,
F_8 ( V_57 ) ) ;
}
if ( V_58 != 0 ) {
F_52 ( L_45 ,
V_52 , F_8 ( V_58 ) ) ;
}
F_15 ( V_52 ) ;
V_52 = NULL ;
}
F_53 ( & V_53 , & V_59 , & V_60 ,
& V_54 , & V_61 , & V_62 ) ;
F_54 ( & V_53 , & V_59 , & V_60 ,
& V_54 , & V_61 , & V_62 ) ;
if ( V_53 != NULL ) {
if ( V_59 != 0 ) {
F_52 ( L_46 ,
V_53 , F_8 ( V_59 ) ) ;
}
if ( V_60 != 0 ) {
F_52 ( L_47 ,
V_53 , F_8 ( V_60 ) ) ;
}
F_15 ( V_53 ) ;
}
if ( V_54 != NULL ) {
if ( V_61 != 0 ) {
F_52 (
L_48 , V_54 ,
F_8 ( V_61 ) ) ;
}
if ( V_62 != 0 ) {
F_52 (
L_49 , V_54 ,
F_8 ( V_62 ) ) ;
}
F_15 ( V_54 ) ;
}
#ifdef F_4
F_55 () ;
#endif
F_56 ( & V_94 ) ;
V_95 = V_96 ;
V_37 = V_38 ;
while ( ( V_47 = F_57 ( V_42 , V_43 , V_73 , V_71 , NULL ) ) != - 1 ) {
switch ( V_47 ) {
case 'd' :
if ( ! F_24 ( V_97 ) ) {
F_52 ( L_50 , V_97 ) ;
exit ( 1 ) ;
}
break;
case 'F' :
F_58 ( V_67 , F_13 ( V_97 ) ) ;
break;
case 'h' :
printf ( L_39
L_51
L_52 ,
F_40 () ) ;
F_1 ( stdout ) ;
exit ( 0 ) ;
break;
case 'l' :
V_98 = TRUE ;
break;
case 'n' :
F_59 () ;
break;
case 'N' :
V_65 = F_60 ( V_97 , & V_99 ) ;
if ( V_65 != '\0' ) {
F_52 ( L_53 ,
V_65 ) ;
exit ( 1 ) ;
}
break;
case 'o' :
switch ( F_30 ( V_97 ) ) {
case V_41 :
break;
case V_100 :
F_52 ( L_54 , V_97 ) ;
exit ( 1 ) ;
break;
case V_101 :
case V_102 :
F_52 ( L_55 , V_97 ) ;
exit ( 1 ) ;
break;
}
break;
case 'p' :
V_103 = TRUE ;
break;
case 'r' :
V_3 = F_13 ( V_97 ) ;
break;
case 'R' :
if( V_79 < ( int ) sizeof( V_63 ) / ( int ) sizeof( V_63 [ 0 ] ) ) {
V_63 [ V_79 ++ ] = V_97 ;
}
else {
F_52 ( L_56 ) ;
exit ( 1 ) ;
}
break;
case 's' :
V_69 = TRUE ;
break;
case 'S' :
if ( ! F_61 ( V_97 ) ) {
F_52 ( L_57 ) ;
exit ( 1 ) ;
}
break;
case 't' :
if ( strcmp ( V_97 , L_58 ) == 0 )
F_47 ( V_89 ) ;
else if ( strcmp ( V_97 , L_59 ) == 0 )
F_47 ( V_104 ) ;
else if ( strcmp ( V_97 , L_60 ) == 0 )
F_47 ( V_105 ) ;
else if ( strcmp ( V_97 , L_61 ) == 0 )
F_47 ( V_106 ) ;
else if ( strcmp ( V_97 , L_62 ) == 0 )
F_47 ( V_107 ) ;
else if ( strcmp ( V_97 , L_63 ) == 0 )
F_47 ( V_108 ) ;
else if ( strcmp ( V_97 , L_64 ) == 0 )
F_47 ( V_109 ) ;
else if ( strcmp ( V_97 , L_65 ) == 0 )
F_47 ( V_110 ) ;
else if ( strcmp ( V_97 , L_66 ) == 0 )
F_47 ( V_111 ) ;
else if ( strcmp ( V_97 , L_67 ) == 0 )
F_47 ( V_112 ) ;
else {
F_52 ( L_68 ,
V_97 ) ;
F_62 (
L_69 ) ;
F_62 (
L_70 ) ;
F_62 (
L_71 ) ;
F_62 (
L_72 ) ;
F_62 (
L_73 ) ;
exit ( 1 ) ;
}
break;
case 'v' :
{
F_63 ( L_74 , V_44 , V_45 ) ;
F_31 ( V_44 , TRUE ) ;
F_31 ( V_45 , TRUE ) ;
exit ( 0 ) ;
break;
}
default:
case '?' :
F_1 ( V_14 ) ;
exit ( 1 ) ;
break;
}
}
F_64 () ;
for ( V_68 = 0 ; V_68 < V_67 -> V_113 ; V_68 ++ ) {
F_65 ( ( char * ) F_66 ( V_67 , V_68 ) ) ;
}
F_67 ( V_67 , TRUE ) ;
printf ( L_1 ) ;
fflush ( stdout ) ;
if ( V_114 < V_42 ) {
if ( V_3 != NULL ) {
if ( V_79 != 0 ) {
F_52 ( L_75
L_76 ) ;
exit ( 1 ) ;
}
V_63 [ V_79 ] = F_68 ( V_42 , V_43 , V_114 ) ;
}
}
if ( V_37 == V_38 ) {
F_52 ( L_77 ) ;
exit ( 1 ) ;
}
if ( V_49 ) {
F_1 ( V_14 ) ;
exit ( 1 ) ;
}
#ifdef F_4
F_69 ( F_70 ( 1 , 1 ) , & V_50 ) ;
#endif
F_71 () ;
if ( V_53 == NULL && V_54 == NULL ) {
F_72 () ;
F_73 () ;
}
F_74 ( & V_94 . V_115 , V_64 -> V_116 , TRUE ) ;
if ( V_79 != 0 ) {
for ( V_48 = 0 ; V_48 < V_79 ; V_48 ++ ) {
T_2 * V_117 ;
if ( ! F_75 ( V_63 [ V_48 ] , & V_78 [ V_80 ] , & V_117 ) ) {
F_52 ( L_40 , V_117 ) ;
F_15 ( V_117 ) ;
F_76 ( V_94 . V_118 ) ;
F_77 () ;
exit ( 2 ) ;
}
V_80 ++ ;
}
}
if ( V_3 ) {
F_78 () ;
if ( F_79 ( & V_94 , V_3 ) != V_119 ) {
F_76 ( V_94 . V_118 ) ;
F_77 () ;
exit ( 2 ) ;
}
if ( V_69 ) {
T_20 V_120 = sizeof( struct V_121 ) + sizeof( V_122 ) ;
T_2 V_123 [ sizeof( struct V_121 ) + sizeof( V_122 ) ] ;
while ( V_120 != 0 ) {
T_21 V_124 = F_80 ( V_125 , V_123 , ( int ) V_120 ) ;
if ( V_124 <= 0 ) {
F_52 ( L_78 ) ;
exit ( 2 ) ;
}
V_120 -= V_124 ;
}
}
if ( ! F_81 ( & V_94 ) ) {
F_76 ( V_94 . V_118 ) ;
F_77 () ;
exit ( 2 ) ;
}
} else {
F_52 ( L_79 ) ;
exit ( 2 ) ;
}
F_76 ( V_94 . V_118 ) ;
F_77 () ;
return 0 ;
}
static T_13
F_82 ( struct V_126 * V_127 , T_22 * V_128 , int * V_7 , T_2 * * V_129 , T_23 * V_130 ) {
struct V_131 V_132 ;
struct V_133 V_134 ;
T_21 V_135 = 0 ;
T_20 V_136 = sizeof( V_134 ) ;
T_22 * V_137 = ( T_22 * ) & V_134 ;
if ( V_103 ) {
V_136 = sizeof( V_132 ) ;
V_137 = ( T_22 * ) & V_132 ;
}
while ( V_136 > 0 ) {
V_135 = F_80 ( V_125 , V_137 , ( int ) V_136 ) ;
if ( V_135 == 0 ) {
* V_7 = 0 ;
* V_129 = NULL ;
return FALSE ;
} else if ( V_135 < 0 ) {
* V_7 = V_15 ;
* V_129 = NULL ;
return FALSE ;
}
V_136 -= V_135 ;
* V_130 += V_135 ;
V_137 += V_135 ;
}
if ( V_103 ) {
V_127 -> V_138 . V_139 = V_132 . V_138 . V_140 ;
V_127 -> V_138 . V_141 = ( V_142 ) V_132 . V_138 . V_143 * 1000 ;
V_127 -> V_144 = V_132 . V_144 ;
V_127 -> V_113 = V_132 . V_113 ;
} else {
V_127 -> V_138 . V_139 = V_134 . V_145 ;
V_127 -> V_138 . V_141 = V_134 . V_146 * 1000 ;
V_127 -> V_144 = V_134 . V_147 ;
V_127 -> V_113 = V_134 . V_148 ;
}
V_136 = V_127 -> V_144 ;
V_127 -> V_149 = V_37 ;
#if 0
printf("mem_hdr: %lu disk_hdr: %lu\n", sizeof(mem_hdr), sizeof(disk_hdr));
printf("tv_sec: %u (%04x)\n", (unsigned int) phdr->ts.secs, (unsigned int) phdr->ts.secs);
printf("tv_nsec: %d (%04x)\n", phdr->ts.nsecs, phdr->ts.nsecs);
printf("caplen: %d (%04x)\n", phdr->caplen, phdr->caplen);
printf("len: %d (%04x)\n", phdr->len, phdr->len);
#endif
if ( V_136 > V_150 ) {
* V_7 = V_151 ;
* V_129 = F_83 ( L_80 ,
( unsigned long ) V_136 ) ;
return FALSE ;
}
V_137 = V_128 ;
while ( V_136 > 0 ) {
V_135 = F_80 ( V_125 , V_137 , ( int ) V_136 ) ;
if ( V_135 == 0 ) {
* V_7 = V_152 ;
* V_129 = NULL ;
return FALSE ;
} else if ( V_135 < 0 ) {
* V_7 = V_15 ;
* V_129 = NULL ;
return FALSE ;
}
V_136 -= V_135 ;
* V_130 += V_135 ;
V_137 += V_135 ;
}
return TRUE ;
}
static T_13
F_81 ( T_24 * V_153 )
{
int V_7 ;
T_2 * V_129 ;
T_23 V_130 = 0 ;
T_22 V_128 [ V_150 ] ;
struct V_126 V_127 ;
T_25 V_154 ;
F_84 ( & V_127 ) ;
F_85 ( & V_154 , V_153 -> V_118 , TRUE , FALSE ) ;
while ( F_82 ( & V_127 , V_128 , & V_7 , & V_129 , & V_130 ) ) {
F_86 ( V_153 , & V_154 , V_130 , & V_127 , V_128 ) ;
}
F_87 ( & V_154 ) ;
F_88 ( & V_127 ) ;
if ( V_7 != 0 ) {
switch ( V_7 ) {
case V_155 :
F_52 ( L_81 ,
V_153 -> V_156 ,
V_129 != NULL ? V_129 : L_82 ) ;
F_15 ( V_129 ) ;
break;
case V_152 :
F_52 ( L_83 ,
V_153 -> V_156 ) ;
break;
case V_151 :
F_52 ( L_84 ,
V_153 -> V_156 ,
V_129 != NULL ? V_129 : L_82 ) ;
F_15 ( V_129 ) ;
break;
case V_157 :
F_52 ( L_85 ,
V_153 -> V_156 ,
V_129 != NULL ? V_129 : L_82 ) ;
F_15 ( V_129 ) ;
break;
default:
F_52 ( L_86 ,
V_153 -> V_156 , F_89 ( V_7 ) ) ;
break;
}
return FALSE ;
}
return TRUE ;
}
static T_13
F_86 ( T_24 * V_153 , T_25 * V_154 , T_23 V_158 ,
struct V_126 * V_159 , const T_22 * V_128 )
{
T_26 V_160 ;
T_13 V_161 ;
int V_48 ;
if( V_159 -> V_113 == 0 )
{
printf ( L_87 , ( unsigned long int ) V_153 -> V_162 ,
( unsigned long int ) V_159 -> V_138 . V_139 ,
( unsigned long int ) V_159 -> V_138 . V_141 ) ;
fflush ( stdout ) ;
return FALSE ;
}
V_153 -> V_162 ++ ;
F_90 ( & V_160 , V_153 -> V_162 , V_159 , V_158 , V_163 ) ;
V_161 = TRUE ;
if ( V_79 > 0 ) {
for( V_48 = 0 ; V_48 < V_80 ; V_48 ++ ) {
F_91 ( V_154 , V_78 [ V_48 ] ) ;
}
}
printf ( L_88 , ( unsigned long int ) V_153 -> V_162 ) ;
F_92 ( & V_160 , & V_153 -> V_164 ,
& V_165 , V_166 ) ;
if ( V_165 == & V_160 ) {
V_167 = V_160 ;
V_165 = & V_167 ;
}
F_93 ( V_154 , V_153 -> V_168 , V_159 , F_94 ( & V_160 , V_128 ) , & V_160 , & V_153 -> V_115 ) ;
F_95 ( & V_160 , & V_163 ) ;
V_169 = V_160 ;
V_166 = & V_169 ;
V_170 = V_160 ;
V_171 = & V_170 ;
for( V_48 = 0 ; V_48 < V_79 ; V_48 ++ ) {
if ( V_78 [ V_48 ] )
V_161 = F_96 ( V_78 [ V_48 ] , V_154 ) ;
else
V_161 = TRUE ;
printf ( L_89 , V_161 ? 1 : 0 ) ;
}
printf ( L_90 ) ;
if ( V_98 )
fflush ( stdout ) ;
if ( ferror ( stdout ) ) {
F_97 ( V_15 ) ;
exit ( 2 ) ;
}
F_98 ( V_154 ) ;
F_99 ( & V_160 ) ;
return V_161 ;
}
static const char * F_100 ( T_27 * V_172 )
{
if ( ! V_172 ) {
return L_91 ;
}
if ( V_81 -> V_113 > 0 && V_172 -> V_173 ) {
return L_92 ;
}
switch( V_172 -> type ) {
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
return L_108 ;
case V_190 :
return L_109 ;
case V_191 :
return L_92 ;
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
default:
return L_91 ;
} ;
}
static const char * F_101 ( T_28 V_208 )
{
switch( V_208 ) {
case V_209 :
return L_126 ;
case V_210 :
return L_127 ;
default:
return L_91 ;
}
}
static const char * F_102 ( T_29 V_211 )
{
switch( V_211 ) {
case V_212 :
return L_128 ;
case V_213 :
return L_129 ;
case V_214 :
return L_130 ;
case V_215 :
return L_131 ;
case V_216 :
return L_132 ;
case V_217 :
return L_133 ;
default:
return L_91 ;
}
}
static T_13 F_103 ( T_30 * V_218 , int V_219 )
{
T_27 * V_220 ;
static char * V_221 = NULL ;
char * V_222 = V_221 ;
static T_15 * V_223 = NULL ;
int V_224 = V_225 , V_226 ;
T_19 V_48 ;
T_31 * V_227 ;
V_122 V_228 ;
V_142 V_229 ;
T_32 V_230 ;
T_23 V_231 ;
const T_33 * V_232 = & V_233 ;
V_220 = V_218 -> V_220 ;
if ( ! V_221 ) {
V_221 = ( char * ) F_104 ( V_224 + 1 ) ;
V_222 = V_221 ;
}
if ( ! V_223 ) {
V_223 = F_28 ( L_38 ) ;
}
if( V_218 -> V_234 . V_235 -> V_236 )
{
V_226 = F_105 ( & V_218 -> V_234 , V_237 , V_218 -> V_220 -> V_238 ) ;
while ( V_224 < V_226 ) {
V_224 *= 2 ;
V_221 = ( char * ) F_106 ( V_221 , V_224 + 1 ) ;
V_222 = V_221 ;
}
F_107 ( & V_218 -> V_234 ,
V_237 , V_218 -> V_220 -> V_238 ,
V_221 ) ;
if ( F_108 ( V_218 -> V_234 . V_235 -> V_235 ) && V_226 > 2 ) {
V_221 [ V_226 - 1 ] = '\0' ;
V_222 ++ ;
}
}
if ( V_81 -> V_113 > 0 && V_218 -> V_220 -> V_173 ) {
F_109 ( V_223 , 0 ) ;
for ( V_48 = 0 ; V_48 < V_81 -> V_113 ; V_48 ++ ) {
V_227 = ( T_31 * ) F_66 ( V_81 , V_48 ) ;
if ( V_227 -> V_239 ) {
F_110 ( V_223 , V_227 -> V_239 ) ;
} else {
switch ( V_227 -> V_240 ) {
case V_241 :
F_110 ( V_223 , V_220 -> V_242 ) ;
break;
case V_243 :
F_110 ( V_223 , V_222 ) ;
break;
case V_244 :
switch( V_220 -> type ) {
case V_176 :
V_228 = F_111 ( & V_218 -> V_234 ) ;
V_232 = ( const struct T_33 * ) V_220 -> V_173 ;
F_110 ( V_223 , V_228 ? V_232 -> V_245 : V_232 -> V_246 ) ;
break;
case V_182 :
case V_183 :
case V_184 :
case V_185 :
F_112 ( ! V_220 -> V_247 ) ;
V_229 = F_113 ( & V_218 -> V_234 ) ;
if ( V_220 -> V_238 & V_248 ) {
F_110 ( V_223 , F_114 ( V_229 , F_115 ( V_220 -> V_173 ) , L_134 ) ) ;
} else if ( V_220 -> V_238 & V_249 ) {
F_110 ( V_223 , F_116 ( V_229 , ( V_250 * ) V_220 -> V_173 , L_134 ) ) ;
} else {
F_110 ( V_223 , F_117 ( V_229 , F_118 ( V_220 -> V_173 ) , L_134 ) ) ;
}
break;
case V_251 :
case V_252 :
case V_253 :
case V_186 :
F_112 ( ! V_220 -> V_247 ) ;
V_231 = ( T_23 ) F_119 ( & V_218 -> V_234 ) ;
if ( V_220 -> V_238 & V_254 ) {
F_110 ( V_223 , F_120 ( V_231 , ( const V_255 * ) ( V_220 -> V_173 ) , L_134 ) ) ;
}
break;
case V_177 :
case V_178 :
case V_179 :
case V_180 :
F_112 ( ! V_220 -> V_247 ) ;
V_228 = F_111 ( & V_218 -> V_234 ) ;
if ( ! V_220 -> V_247 && V_220 -> V_238 & V_248 ) {
F_110 ( V_223 , F_114 ( V_228 , F_115 ( V_220 -> V_173 ) , L_134 ) ) ;
} else if ( V_220 -> V_238 & V_249 ) {
F_110 ( V_223 , F_116 ( V_228 , ( V_250 * ) V_220 -> V_173 , L_134 ) ) ;
} else {
F_110 ( V_223 , F_117 ( V_228 , F_118 ( V_220 -> V_173 ) , L_134 ) ) ;
}
break;
case V_256 :
case V_257 :
case V_258 :
case V_181 :
F_112 ( ! V_220 -> V_247 ) ;
V_230 = F_121 ( & V_218 -> V_234 ) ;
if ( V_220 -> V_238 & V_254 ) {
F_110 ( V_223 , F_120 ( V_230 , ( const V_255 * ) ( V_220 -> V_173 ) , L_134 ) ) ;
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
printf ( L_135 , V_219 , V_223 -> V_40 ) ;
return TRUE ;
}
if( V_218 -> V_234 . V_235 -> V_236 )
{
printf ( L_135 , V_219 , V_222 ) ;
return TRUE ;
}
printf ( L_136 , V_219 ) ;
return TRUE ;
}
static int
F_122 ( void * V_259 , T_34 * T_35 V_2 , T_25 * V_154 , const void * T_36 V_2 )
{
T_37 * V_260 = ( T_37 * ) V_259 ;
T_18 * V_261 ;
T_19 V_48 ;
V_261 = F_123 ( V_154 -> V_262 , V_260 -> V_263 ) ;
if( ! V_261 ) {
printf ( L_137 ) ;
return 0 ;
}
for ( V_48 = 0 ; V_48 < V_261 -> V_113 ; V_48 ++ ) {
F_103 ( ( T_30 * ) V_261 -> V_264 [ V_48 ] , V_260 -> V_219 ) ;
}
return 0 ;
}
static void
F_65 ( char * V_265 )
{
T_37 * V_260 ;
T_27 * V_172 ;
T_15 * V_266 ;
V_172 = F_124 ( V_265 ) ;
if( ! V_172 ) {
fprintf ( V_14 , L_138 , V_265 ) ;
exit ( 1 ) ;
}
switch ( V_172 -> type ) {
case V_189 :
printf ( L_139 ,
V_267 ,
F_100 ( V_172 ) ,
F_101 ( ( T_28 ) V_172 -> V_238 ) ) ;
break;
default:
printf ( L_139 ,
V_267 ,
F_100 ( V_172 ) ,
F_102 ( ( T_29 ) V_172 -> V_238 ) ) ;
break;
}
V_260 = ( T_37 * ) F_104 ( sizeof( T_37 ) ) ;
V_260 -> V_263 = V_172 -> V_268 ;
V_260 -> V_269 = V_265 ;
V_260 -> V_219 = V_267 ++ ;
V_266 = F_125 ( L_140 , V_260 , V_260 -> V_269 , V_270 , NULL , F_122 , NULL ) ;
if( V_266 ) {
fprintf ( V_14 , L_141 ,
V_266 -> V_40 ) ;
F_31 ( V_266 , TRUE ) ;
if( V_260 -> V_269 ) {
F_15 ( V_260 -> V_269 ) ;
}
F_15 ( V_260 ) ;
exit ( 1 ) ;
}
}
static void
F_126 ( T_38 V_240 , T_2 * V_239 ) {
T_31 * V_227 = ( T_31 * ) F_104 ( sizeof( T_31 ) ) ;
V_227 -> V_240 = V_240 ;
V_227 -> V_239 = F_13 ( V_239 ) ;
F_58 ( V_81 , V_227 ) ;
}
static T_13
F_61 ( T_2 * V_240 ) {
T_15 * V_271 = F_28 ( L_38 ) ;
T_20 V_113 ;
T_20 V_6 = 0 ;
if ( ! V_240 ) {
return FALSE ;
}
V_113 = strlen ( V_240 ) ;
F_127 ( V_81 , 0 ) ;
while ( V_6 < V_113 ) {
if ( V_240 [ V_6 ] == '%' ) {
if ( V_6 >= V_113 ) {
return FALSE ;
}
V_6 ++ ;
if ( V_271 -> V_113 > 0 ) {
F_126 ( V_272 , V_271 -> V_40 ) ;
F_109 ( V_271 , 0 ) ;
}
switch ( V_240 [ V_6 ] ) {
case 'D' :
F_126 ( V_241 , NULL ) ;
break;
case 'N' :
F_126 ( V_243 , NULL ) ;
break;
case 'S' :
F_126 ( V_244 , NULL ) ;
break;
case '%' :
F_128 ( V_271 , '%' ) ;
break;
default:
return FALSE ;
}
} else {
F_128 ( V_271 , V_240 [ V_6 ] ) ;
}
V_6 ++ ;
}
if ( V_271 -> V_113 > 0 ) {
F_126 ( V_272 , V_271 -> V_40 ) ;
}
F_31 ( V_271 , TRUE ) ;
return TRUE ;
}
static void
F_97 ( int V_7 )
{
switch ( V_7 ) {
case V_273 :
F_52 ( L_142
L_143 ) ;
break;
#ifdef F_129
case F_129 :
F_52 ( L_144
L_145 ) ;
break;
#endif
default:
F_52 ( L_146 ,
F_8 ( V_7 ) ) ;
break;
}
}
static void
V_86 ( const char * V_156 , int V_7 , T_13 V_274 )
{
fprintf ( V_14 , L_147 ) ;
fprintf ( V_14 , F_130 ( V_7 , V_274 ) , V_156 ) ;
fprintf ( V_14 , L_1 ) ;
}
static const T_39 *
F_131 ( void * T_40 V_2 , V_122 V_275 )
{
if ( V_165 && V_165 -> V_276 == V_275 )
return & V_165 -> V_277 ;
if ( V_166 && V_166 -> V_276 == V_275 )
return & V_166 -> V_277 ;
if ( V_171 && V_171 -> V_276 == V_275 )
return & V_171 -> V_277 ;
return NULL ;
}
static T_41 *
F_132 ( T_24 * V_153 )
{
T_41 * V_118 = F_133 () ;
V_118 -> T_40 = V_153 ;
V_118 -> V_278 = F_131 ;
V_118 -> V_279 = V_280 ;
V_118 -> V_281 = NULL ;
return V_118 ;
}
T_42
F_79 ( T_24 * V_153 , const char * V_282 )
{
if ( ( V_125 = F_3 ( V_282 ) ) < 0 )
return V_283 ;
F_76 ( V_153 -> V_118 ) ;
V_153 -> V_118 = F_132 ( V_153 ) ;
V_153 -> V_284 = NULL ;
V_153 -> V_285 = 0 ;
V_153 -> V_156 = F_13 ( V_282 ) ;
V_153 -> V_286 = FALSE ;
V_153 -> V_287 = FALSE ;
V_153 -> V_168 = V_288 ;
V_153 -> V_289 = V_290 ;
V_153 -> V_162 = 0 ;
V_153 -> V_291 = FALSE ;
V_153 -> V_292 = 0 ;
V_153 -> V_293 = FALSE ;
V_153 -> V_294 = V_150 ;
F_134 ( & V_153 -> V_164 ) ;
V_165 = NULL ;
V_166 = NULL ;
V_171 = NULL ;
return V_119 ;
}
static void
V_85 ( const char * V_295 , T_43 V_296 )
{
fprintf ( V_14 , L_147 ) ;
vfprintf ( V_14 , V_295 , V_296 ) ;
fprintf ( V_14 , L_1 ) ;
}
static void
V_87 ( const char * V_156 , int V_7 )
{
F_52 ( L_148 ,
V_156 , F_8 ( V_7 ) ) ;
}
static void
V_88 ( const char * V_156 , int V_7 )
{
F_52 ( L_149 ,
V_156 , F_8 ( V_7 ) ) ;
}
static void
V_75 ( const char * V_297 , T_43 V_296 )
{
fprintf ( V_14 , L_147 ) ;
vfprintf ( V_14 , V_297 , V_296 ) ;
fprintf ( V_14 , L_1 ) ;
}
static void
V_76 ( const char * V_297 , T_43 V_296 )
{
vfprintf ( V_14 , V_297 , V_296 ) ;
fprintf ( V_14 , L_1 ) ;
}
