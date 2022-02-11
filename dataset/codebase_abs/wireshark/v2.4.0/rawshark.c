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
#ifndef F_2
fprintf ( V_1 , L_9 ) ;
#endif
fprintf ( V_1 , L_10 ) ;
fprintf ( V_1 , L_11 ) ;
fprintf ( V_1 , L_12 ) ;
fprintf ( V_1 , L_13 ) ;
fprintf ( V_1 , L_14 ) ;
fprintf ( V_1 , L_15 ) ;
fprintf ( V_1 , L_1 ) ;
fprintf ( V_1 , L_16 ) ;
fprintf ( V_1 , L_17 ) ;
fprintf ( V_1 , L_18 ) ;
fprintf ( V_1 , L_19 ) ;
fprintf ( V_1 , L_20 ) ;
fprintf ( V_1 , L_1 ) ;
fprintf ( V_1 , L_21 ) ;
fprintf ( V_1 , L_22 ) ;
fprintf ( V_1 , L_23 ) ;
fprintf ( V_1 , L_24 ) ;
}
static void
F_3 ( const T_2 * T_3 V_2 , T_4 T_5 V_2 ,
const T_2 * T_6 V_2 , T_7 T_8 V_2 )
{
}
static int
F_4 ( const char * V_3 )
{
#ifndef F_2
T_9 V_4 ;
#else
char * V_5 , * V_6 = NULL ;
T_10 V_7 ;
T_11 * V_8 ;
T_12 V_9 = NULL ;
#endif
int V_10 ;
F_5 ( V_11 , V_12 , L_25 , V_3 ) ;
if ( strcmp ( V_3 , L_26 ) == 0 ) {
V_10 = 0 ;
#ifdef F_2
F_6 ( 0 , V_13 ) ;
#endif
} else {
#ifndef F_2
if ( F_7 ( V_3 , & V_4 ) < 0 ) {
fprintf ( V_14 , L_27 ,
V_3 , F_8 ( V_15 ) ) ;
return - 1 ;
}
if ( ! F_9 ( V_4 . V_16 ) ) {
if ( F_10 ( V_4 . V_16 ) ) {
} else
{
fprintf ( V_14 , L_28 ,
V_3 ) ;
}
return - 1 ;
}
V_10 = F_11 ( V_3 , V_17 | V_18 , 0000 ) ;
if ( V_10 == - 1 ) {
fprintf ( V_14 , L_29 ,
V_3 , F_8 ( V_15 ) ) ;
return - 1 ;
}
#else
#define F_12 "\\pipe\\"
V_5 = F_13 ( V_3 ) ;
if ( strstr ( V_5 , L_30 ) == V_5 ) {
V_6 = strchr ( V_5 + 3 , '\\' ) ;
if ( V_6 && F_14 ( V_6 , F_12 , strlen ( F_12 ) ) != 0 )
V_6 = NULL ;
}
F_15 ( V_5 ) ;
if ( ! V_6 ) {
fprintf ( V_14 , L_28 ,
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
fprintf ( V_14 , L_31 ,
V_3 , F_20 ( V_8 ) , V_7 ) ;
F_21 ( V_8 ) ;
return - 1 ;
}
if ( ! F_22 ( F_17 ( V_3 ) , 30 * 1000 ) ) {
V_7 = F_18 () ;
F_19 ( V_23 | V_24 | V_25 ,
NULL , V_7 , 0 , ( V_26 ) & V_8 , 0 , NULL ) ;
fprintf ( V_14 , L_32 ,
V_3 , F_20 ( V_8 ) , V_7 ) ;
F_21 ( V_8 ) ;
return - 1 ;
}
}
V_10 = F_23 ( ( V_27 ) V_9 , V_28 ) ;
if ( V_10 == - 1 ) {
fprintf ( V_14 , L_29 ,
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
char * V_36 = NULL ;
if ( ! V_30 )
return FALSE ;
V_30 ++ ;
if ( strncmp ( V_29 , L_33 , strlen ( L_33 ) ) == 0 ) {
V_32 = F_25 ( V_30 ) ;
if ( V_32 == - 1 ) {
V_15 = 0 ;
V_33 = strtol ( V_30 , & V_31 , 10 ) ;
if ( V_31 == V_30 || * V_31 != '\0' || V_15 != 0 || V_33 > V_37 ) {
return FALSE ;
}
V_32 = ( int ) V_33 ;
}
V_38 = F_26 ( V_32 ) ;
if ( V_38 == V_39 ) {
return FALSE ;
}
return TRUE ;
} else if ( strncmp ( V_29 , L_34 , strlen ( L_34 ) ) == 0 ) {
V_34 = F_27 ( V_30 ) ;
if ( V_34 ) {
V_38 = V_40 ;
V_35 = F_28 ( L_35 ) ;
F_29 ( V_35 ,
L_36 ,
V_30 ) ;
if ( F_30 ( V_35 -> V_41 , & V_36 ) != V_42 ) {
F_31 ( V_35 , TRUE ) ;
F_15 ( V_36 ) ;
return FALSE ;
}
F_31 ( V_35 , TRUE ) ;
return TRUE ;
}
}
return FALSE ;
}
int
main ( int V_43 , char * V_44 [] )
{
T_15 * V_45 ;
T_15 * V_46 ;
char * V_47 ;
int V_48 , V_49 ;
#ifdef F_2
int V_50 ;
T_16 V_51 ;
#else
struct V_52 V_53 ;
#endif
T_2 * V_3 = NULL ;
T_2 * V_54 [ 64 ] ;
T_17 * V_55 ;
char V_56 ;
int V_57 ;
T_18 * V_58 = F_32 () ;
T_19 V_59 ;
T_13 V_60 = FALSE ;
int V_61 = V_62 ;
static const struct V_63 V_64 [] = {
{ L_37 , V_65 , NULL , 'h' } ,
{ L_38 , V_65 , NULL , 'v' } ,
{ 0 , 0 , 0 , 0 }
} ;
#define F_33 "d:F:hlm:nN:o:pr:R:sS:t:v"
static const char V_66 [] = F_33 ;
setlocale ( V_67 , L_39 ) ;
F_34 ( V_68 , V_69 ) ;
V_45 = F_35 ( NULL , V_70 ) ;
V_46 = F_36 ( NULL ) ;
F_37 ( L_40
L_1
L_41
L_1
L_41 ,
F_38 () , V_45 -> V_41 , V_46 -> V_41 ) ;
#ifdef F_2
F_39 ( V_43 , V_44 ) ;
F_40 () ;
#endif
F_41 () ;
memset ( V_54 , 0 , sizeof( V_54 ) ) ;
memset ( V_71 , 0 , sizeof( V_71 ) ) ;
V_72 = 0 ;
V_73 = 0 ;
V_74 = F_32 () ;
V_47 = F_42 ( V_44 [ 0 ] , main ) ;
if ( V_47 != NULL ) {
fprintf ( V_14 , L_42 ,
V_47 ) ;
}
V_57 =
V_75 |
V_76 |
V_77 |
V_12 ;
F_43 ( NULL ,
( T_4 ) V_57 ,
F_3 , NULL ) ;
F_43 ( V_11 ,
( T_4 ) V_57 ,
F_3 , NULL ) ;
F_44 ( V_78 , V_78 ,
V_79 , V_80 ,
V_81 ) ;
F_45 ( V_82 ) ;
F_46 ( V_83 ) ;
F_47 ( V_84 ) ;
F_48 () ;
if ( ! F_49 ( V_85 , V_86 ,
NULL , NULL ) ) {
V_61 = V_87 ;
goto V_88;
}
V_55 = F_50 () ;
#ifdef F_2
F_51 () ;
F_52 () ;
#endif
F_53 ( & V_89 ) ;
V_90 = V_91 ;
V_38 = V_39 ;
while ( ( V_48 = F_54 ( V_43 , V_44 , V_66 , V_64 , NULL ) ) != - 1 ) {
switch ( V_48 ) {
case 'd' :
if ( ! F_24 ( V_92 ) ) {
F_55 ( L_43 , V_92 ) ;
V_61 = V_93 ;
goto V_88;
}
break;
case 'F' :
F_56 ( V_58 , F_13 ( V_92 ) ) ;
break;
case 'h' :
printf ( L_40
L_44
L_45 ,
F_38 () ) ;
F_1 ( stdout ) ;
goto V_88;
break;
case 'l' :
V_94 = TRUE ;
break;
#ifndef F_2
case 'm' :
V_53 . V_95 = F_57 ( V_92 , L_46 ) ;
V_53 . V_96 = F_57 ( V_92 , L_46 ) ;
if( F_58 ( V_97 , & V_53 ) != 0 ) {
F_55 ( L_47 ) ;
V_61 = V_93 ;
goto V_88;
}
break;
#endif
case 'n' :
F_59 () ;
break;
case 'N' :
V_56 = F_60 ( V_92 , & V_98 ) ;
if ( V_56 != '\0' ) {
F_55 ( L_48 ,
V_56 ) ;
V_61 = V_93 ;
goto V_88;
}
break;
case 'o' :
{
char * V_36 = NULL ;
switch ( F_30 ( V_92 , & V_36 ) ) {
case V_42 :
break;
case V_99 :
F_55 ( L_49 , V_92 ,
V_36 ? L_50 : L_39 , V_36 ? V_36 : L_39 ) ;
F_15 ( V_36 ) ;
V_61 = V_93 ;
goto V_88;
break;
case V_100 :
case V_101 :
F_55 ( L_51 , V_92 ) ;
V_61 = V_93 ;
goto V_88;
break;
}
break;
}
case 'p' :
V_102 = TRUE ;
break;
case 'r' :
V_3 = F_13 ( V_92 ) ;
break;
case 'R' :
if( V_72 < ( int ) sizeof( V_54 ) / ( int ) sizeof( V_54 [ 0 ] ) ) {
V_54 [ V_72 ++ ] = V_92 ;
}
else {
F_55 ( L_52 ) ;
V_61 = V_93 ;
goto V_88;
}
break;
case 's' :
V_60 = TRUE ;
break;
case 'S' :
if ( ! F_61 ( V_92 ) ) {
F_55 ( L_53 ) ;
V_61 = V_93 ;
goto V_88;
}
break;
case 't' :
if ( strcmp ( V_92 , L_54 ) == 0 )
F_45 ( V_82 ) ;
else if ( strcmp ( V_92 , L_55 ) == 0 )
F_45 ( V_103 ) ;
else if ( strcmp ( V_92 , L_56 ) == 0 )
F_45 ( V_104 ) ;
else if ( strcmp ( V_92 , L_57 ) == 0 )
F_45 ( V_105 ) ;
else if ( strcmp ( V_92 , L_58 ) == 0 )
F_45 ( V_106 ) ;
else if ( strcmp ( V_92 , L_59 ) == 0 )
F_45 ( V_107 ) ;
else if ( strcmp ( V_92 , L_60 ) == 0 )
F_45 ( V_108 ) ;
else if ( strcmp ( V_92 , L_61 ) == 0 )
F_45 ( V_109 ) ;
else if ( strcmp ( V_92 , L_62 ) == 0 )
F_45 ( V_110 ) ;
else if ( strcmp ( V_92 , L_63 ) == 0 )
F_45 ( V_111 ) ;
else {
F_55 ( L_64 ,
V_92 ) ;
F_62 (
L_65 ) ;
F_62 (
L_66 ) ;
F_62 (
L_67 ) ;
F_62 (
L_68 ) ;
F_62 (
L_69 ) ;
V_61 = V_93 ;
goto V_88;
}
break;
case 'v' :
{
F_63 ( L_70 , V_45 , V_46 ) ;
F_31 ( V_45 , TRUE ) ;
F_31 ( V_46 , TRUE ) ;
goto V_88;
break;
}
default:
case '?' :
F_1 ( V_14 ) ;
V_61 = V_93 ;
goto V_88;
break;
}
}
F_64 () ;
for ( V_59 = 0 ; V_59 < V_58 -> V_112 ; V_59 ++ ) {
F_65 ( ( char * ) F_66 ( V_58 , V_59 ) ) ;
}
F_67 ( V_58 , TRUE ) ;
printf ( L_1 ) ;
fflush ( stdout ) ;
if ( V_113 < V_43 ) {
if ( V_3 != NULL ) {
if ( V_72 != 0 ) {
F_55 ( L_71
L_72 ) ;
V_61 = V_93 ;
goto V_88;
}
V_54 [ V_72 ] = F_68 ( V_43 , V_44 , V_113 ) ;
}
}
if ( V_38 == V_39 ) {
F_55 ( L_73 ) ;
V_61 = V_93 ;
goto V_88;
}
#ifdef F_2
V_50 = F_69 ( F_70 ( 1 , 1 ) , & V_51 ) ;
if ( V_50 != 0 )
{
V_61 = V_87 ;
goto V_88;
}
#endif
F_71 () ;
F_72 () ;
F_73 ( & V_89 . V_114 , V_55 -> V_115 , TRUE ) ;
if ( V_72 != 0 ) {
for ( V_49 = 0 ; V_49 < V_72 ; V_49 ++ ) {
T_2 * V_116 ;
if ( ! F_74 ( V_54 [ V_49 ] , & V_71 [ V_73 ] , & V_116 ) ) {
F_55 ( L_41 , V_116 ) ;
F_15 ( V_116 ) ;
V_61 = V_117 ;
goto V_88;
}
V_73 ++ ;
}
}
if ( V_3 ) {
F_75 () ;
if ( F_76 ( & V_89 , V_3 ) != V_118 ) {
V_61 = V_119 ;
goto V_88;
}
if ( V_60 ) {
unsigned int V_120 = ( unsigned int ) sizeof( struct V_121 ) + sizeof( V_122 ) ;
T_2 V_123 [ sizeof( struct V_121 ) + sizeof( V_122 ) ] ;
while ( V_120 != 0 ) {
T_20 V_124 = F_77 ( V_125 , V_123 , V_120 ) ;
if ( V_124 <= 0 ) {
F_55 ( L_74 ) ;
V_61 = V_126 ;
goto V_88;
}
V_120 -= ( unsigned int ) V_124 ;
}
}
if ( ! F_78 ( & V_89 ) ) {
V_61 = V_119 ;
goto V_88;
}
} else {
F_55 ( L_75 ) ;
V_61 = V_119 ;
goto V_88;
}
V_88:
F_79 ( V_89 . V_127 ) ;
F_80 () ;
#ifdef F_81
F_82 () ;
#endif
F_83 () ;
return V_61 ;
}
static T_13
F_84 ( struct V_128 * V_129 , T_21 * V_130 , int * V_7 , T_2 * * V_131 , T_22 * V_132 ) {
struct V_133 V_134 ;
struct V_135 V_136 ;
T_20 V_137 = 0 ;
unsigned int V_138 = ( unsigned int ) sizeof( V_136 ) ;
T_21 * V_139 = ( T_21 * ) & V_136 ;
* V_7 = 0 ;
if ( V_102 ) {
V_138 = sizeof( V_134 ) ;
V_139 = ( T_21 * ) & V_134 ;
}
#ifdef F_2
T_10 V_140 ;
if ( V_125 == 0 && F_85 ( F_86 ( V_141 ) , & V_140 ) == 0 ) {
* V_7 = 0 ;
* V_131 = NULL ;
return FALSE ;
}
#endif
while ( V_138 > 0 ) {
V_137 = F_77 ( V_125 , V_139 , V_138 ) ;
if ( V_137 == 0 ) {
* V_7 = 0 ;
* V_131 = NULL ;
return FALSE ;
} else if ( V_137 < 0 ) {
* V_7 = V_15 ;
* V_131 = NULL ;
return FALSE ;
}
V_138 -= ( unsigned int ) V_137 ;
* V_132 += V_137 ;
V_139 += V_137 ;
}
if ( V_102 ) {
V_129 -> V_142 . V_143 = V_134 . V_142 . V_144 ;
V_129 -> V_142 . V_145 = ( V_146 ) V_134 . V_142 . V_147 * 1000 ;
V_129 -> V_148 = V_134 . V_148 ;
V_129 -> V_112 = V_134 . V_112 ;
} else {
V_129 -> V_142 . V_143 = V_136 . V_149 ;
V_129 -> V_142 . V_145 = V_136 . V_150 * 1000 ;
V_129 -> V_148 = V_136 . V_151 ;
V_129 -> V_112 = V_136 . V_152 ;
}
V_138 = V_129 -> V_148 ;
V_129 -> V_153 = V_38 ;
#if 0
printf("mem_hdr: %lu disk_hdr: %lu\n", sizeof(mem_hdr), sizeof(disk_hdr));
printf("tv_sec: %u (%04x)\n", (unsigned int) phdr->ts.secs, (unsigned int) phdr->ts.secs);
printf("tv_nsec: %d (%04x)\n", phdr->ts.nsecs, phdr->ts.nsecs);
printf("caplen: %d (%04x)\n", phdr->caplen, phdr->caplen);
printf("len: %d (%04x)\n", phdr->len, phdr->len);
#endif
if ( V_138 > V_154 ) {
* V_7 = V_155 ;
* V_131 = F_87 ( L_76 ,
( unsigned long ) V_138 ) ;
return FALSE ;
}
V_139 = V_130 ;
while ( V_138 > 0 ) {
V_137 = F_77 ( V_125 , V_139 , V_138 ) ;
if ( V_137 == 0 ) {
* V_7 = V_156 ;
* V_131 = NULL ;
return FALSE ;
} else if ( V_137 < 0 ) {
* V_7 = V_15 ;
* V_131 = NULL ;
return FALSE ;
}
V_138 -= ( unsigned int ) V_137 ;
* V_132 += V_137 ;
V_139 += V_137 ;
}
return TRUE ;
}
static T_13
F_78 ( T_23 * V_157 )
{
int V_7 ;
T_2 * V_131 = NULL ;
T_22 V_132 = 0 ;
T_21 * V_130 ;
struct V_128 V_129 ;
T_24 V_158 ;
F_88 ( & V_129 ) ;
F_89 ( & V_158 , V_157 -> V_127 , TRUE , FALSE ) ;
V_130 = ( T_21 * ) F_90 ( V_154 ) ;
while ( F_84 ( & V_129 , V_130 , & V_7 , & V_131 , & V_132 ) ) {
F_91 ( V_157 , & V_158 , V_132 , & V_129 , V_130 ) ;
}
F_92 ( & V_158 ) ;
F_93 ( & V_129 ) ;
F_15 ( V_130 ) ;
if ( V_7 != 0 ) {
F_94 ( L_77 , V_157 -> V_159 , V_7 , V_131 ) ;
return FALSE ;
}
return TRUE ;
}
static T_13
F_91 ( T_23 * V_157 , T_24 * V_158 , T_22 V_160 ,
struct V_128 * V_161 , const T_21 * V_130 )
{
T_25 V_162 ;
T_13 V_163 ;
int V_49 ;
if( V_161 -> V_112 == 0 )
{
printf ( L_78 , ( unsigned long int ) V_157 -> V_164 ,
( unsigned long int ) V_161 -> V_142 . V_143 ,
( unsigned long int ) V_161 -> V_142 . V_145 ) ;
fflush ( stdout ) ;
return FALSE ;
}
V_157 -> V_164 ++ ;
F_95 ( & V_162 , V_157 -> V_164 , V_161 , V_160 , V_165 ) ;
V_163 = TRUE ;
if ( V_72 > 0 ) {
for( V_49 = 0 ; V_49 < V_73 ; V_49 ++ ) {
F_96 ( V_158 , V_71 [ V_49 ] ) ;
}
}
printf ( L_79 , ( unsigned long int ) V_157 -> V_164 ) ;
F_97 ( & V_162 , & V_157 -> V_166 ,
& V_167 , V_168 ) ;
if ( V_167 == & V_162 ) {
V_169 = V_162 ;
V_167 = & V_169 ;
}
F_98 ( V_158 , V_157 -> V_170 , V_161 , F_99 ( & V_162 , V_130 ) , & V_162 , & V_157 -> V_114 ) ;
F_100 ( & V_162 , & V_165 ) ;
V_171 = V_162 ;
V_168 = & V_171 ;
V_172 = V_162 ;
V_173 = & V_172 ;
for( V_49 = 0 ; V_49 < V_72 ; V_49 ++ ) {
if ( V_71 [ V_49 ] )
V_163 = F_101 ( V_71 [ V_49 ] , V_158 ) ;
else
V_163 = TRUE ;
printf ( L_80 , V_163 ? 1 : 0 ) ;
}
printf ( L_81 ) ;
if ( V_94 )
fflush ( stdout ) ;
if ( ferror ( stdout ) ) {
F_102 ( V_15 ) ;
exit ( 2 ) ;
}
F_103 ( V_158 ) ;
F_104 ( & V_162 ) ;
return V_163 ;
}
static const char * F_105 ( T_26 * V_174 )
{
const char * V_41 ;
if ( ! V_174 ) {
return L_82 ;
}
if ( V_74 -> V_112 > 0 && V_174 -> V_175 ) {
return L_83 ;
}
V_41 = F_106 ( V_174 -> type ) ;
if ( V_41 == NULL ) {
V_41 = L_82 ;
}
return V_41 ;
}
static void F_107 ( T_26 * V_174 , char * V_123 , int V_176 )
{
if ( V_174 -> type != V_177 )
{
F_108 ( V_123 , F_109 ( V_174 -> V_178 ) , V_176 ) ;
}
else
{
F_110 ( V_123 , V_176 , L_84 , V_174 -> V_178 ) ;
}
}
static T_13 F_111 ( T_27 * V_179 , int V_180 )
{
T_26 * V_181 ;
char * V_182 = NULL ;
char * V_183 = NULL ;
static T_15 * V_184 = NULL ;
int V_185 ;
T_19 V_49 ;
T_28 * V_186 ;
V_122 V_187 ;
V_146 V_188 ;
T_29 V_189 ;
T_22 V_190 ;
const T_30 * V_191 = & V_192 ;
V_181 = V_179 -> V_181 ;
if ( ! V_184 ) {
V_184 = F_28 ( L_39 ) ;
}
if( V_179 -> V_193 . V_194 -> V_195 )
{
V_185 = F_112 ( & V_179 -> V_193 , V_196 , V_179 -> V_181 -> V_178 ) ;
V_182 = F_113 ( NULL , & V_179 -> V_193 ,
V_196 , V_179 -> V_181 -> V_178 ) ;
V_183 = V_182 ;
if ( F_114 ( V_179 -> V_193 . V_194 -> V_194 ) && V_185 > 2 ) {
V_182 [ V_185 - 1 ] = '\0' ;
V_183 ++ ;
}
}
if ( V_74 -> V_112 > 0 && V_179 -> V_181 -> V_175 ) {
F_115 ( V_184 , 0 ) ;
for ( V_49 = 0 ; V_49 < V_74 -> V_112 ; V_49 ++ ) {
V_186 = ( T_28 * ) F_66 ( V_74 , V_49 ) ;
if ( V_186 -> V_197 ) {
F_116 ( V_184 , V_186 -> V_197 ) ;
} else {
switch ( V_186 -> V_198 ) {
case V_199 :
F_116 ( V_184 , V_181 -> V_200 ) ;
break;
case V_201 :
F_116 ( V_184 , V_183 ) ;
break;
case V_202 :
switch( V_181 -> type ) {
case V_177 :
V_189 = F_117 ( & V_179 -> V_193 ) ;
V_191 = ( const struct T_30 * ) V_181 -> V_175 ;
F_116 ( V_184 , V_189 ? V_191 -> V_203 : V_191 -> V_204 ) ;
break;
case V_205 :
case V_206 :
case V_207 :
case V_208 :
F_118 ( ! V_181 -> V_209 ) ;
V_188 = F_119 ( & V_179 -> V_193 ) ;
if ( V_181 -> V_178 & V_210 ) {
F_116 ( V_184 , F_120 ( V_188 , F_121 ( V_181 -> V_175 ) , L_85 ) ) ;
} else if ( V_181 -> V_178 & V_211 ) {
F_116 ( V_184 , F_122 ( V_188 , ( V_212 * ) V_181 -> V_175 , L_85 ) ) ;
} else {
F_116 ( V_184 , F_123 ( V_188 , F_124 ( V_181 -> V_175 ) , L_85 ) ) ;
}
break;
case V_213 :
case V_214 :
case V_215 :
case V_216 :
F_118 ( ! V_181 -> V_209 ) ;
V_190 = ( T_22 ) F_125 ( & V_179 -> V_193 ) ;
if ( V_181 -> V_178 & V_217 ) {
F_116 ( V_184 , F_126 ( V_190 , ( const V_218 * ) ( V_181 -> V_175 ) , L_85 ) ) ;
}
break;
case V_219 :
case V_220 :
case V_221 :
case V_222 :
F_118 ( ! V_181 -> V_209 ) ;
V_187 = F_127 ( & V_179 -> V_193 ) ;
if ( ! V_181 -> V_209 && V_181 -> V_178 & V_210 ) {
F_116 ( V_184 , F_120 ( V_187 , F_121 ( V_181 -> V_175 ) , L_85 ) ) ;
} else if ( V_181 -> V_178 & V_211 ) {
F_116 ( V_184 , F_122 ( V_187 , ( V_212 * ) V_181 -> V_175 , L_85 ) ) ;
} else {
F_116 ( V_184 , F_123 ( V_187 , F_124 ( V_181 -> V_175 ) , L_85 ) ) ;
}
break;
case V_223 :
case V_224 :
case V_225 :
case V_226 :
F_118 ( ! V_181 -> V_209 ) ;
V_189 = F_117 ( & V_179 -> V_193 ) ;
if ( V_181 -> V_178 & V_217 ) {
F_116 ( V_184 , F_126 ( V_189 , ( const V_218 * ) ( V_181 -> V_175 ) , L_85 ) ) ;
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
printf ( L_86 , V_180 , V_184 -> V_41 ) ;
F_128 ( NULL , V_182 ) ;
return TRUE ;
}
if( V_179 -> V_193 . V_194 -> V_195 )
{
printf ( L_86 , V_180 , V_183 ) ;
F_128 ( NULL , V_182 ) ;
return TRUE ;
}
printf ( L_87 , V_180 ) ;
return TRUE ;
}
static int
F_129 ( void * V_227 , T_31 * T_32 V_2 , T_24 * V_158 , const void * T_33 V_2 )
{
T_34 * V_228 = ( T_34 * ) V_227 ;
T_18 * V_229 ;
T_19 V_49 ;
V_229 = F_130 ( V_158 -> V_230 , V_228 -> V_231 ) ;
if( ! V_229 ) {
printf ( L_88 ) ;
return 0 ;
}
for ( V_49 = 0 ; V_49 < V_229 -> V_112 ; V_49 ++ ) {
F_111 ( ( T_27 * ) V_229 -> V_232 [ V_49 ] , V_228 -> V_180 ) ;
}
return 0 ;
}
static void
F_65 ( char * V_233 )
{
T_34 * V_228 ;
T_26 * V_174 ;
T_15 * V_234 ;
char V_235 [ 100 ] ;
V_174 = F_131 ( V_233 ) ;
if( ! V_174 ) {
fprintf ( V_14 , L_89 , V_233 ) ;
exit ( 1 ) ;
}
F_107 ( V_174 , V_235 , sizeof( V_235 ) ) ;
printf ( L_90 ,
V_236 ,
F_105 ( V_174 ) ,
V_235 ) ;
V_228 = ( T_34 * ) F_90 ( sizeof( T_34 ) ) ;
V_228 -> V_231 = V_174 -> V_237 ;
V_228 -> V_238 = V_233 ;
V_228 -> V_180 = V_236 ++ ;
V_234 = F_132 ( L_91 , V_228 , V_228 -> V_238 , V_239 , NULL , F_129 , NULL ) ;
if( V_234 ) {
fprintf ( V_14 , L_92 ,
V_234 -> V_41 ) ;
F_31 ( V_234 , TRUE ) ;
if( V_228 -> V_238 ) {
F_15 ( V_228 -> V_238 ) ;
}
F_15 ( V_228 ) ;
exit ( 1 ) ;
}
}
static void
F_133 ( T_35 V_198 , T_2 * V_197 ) {
T_28 * V_186 = ( T_28 * ) F_90 ( sizeof( T_28 ) ) ;
V_186 -> V_198 = V_198 ;
V_186 -> V_197 = F_13 ( V_197 ) ;
F_56 ( V_74 , V_186 ) ;
}
static T_13
F_61 ( T_2 * V_198 ) {
T_15 * V_240 = F_28 ( L_39 ) ;
T_36 V_112 ;
T_36 V_6 = 0 ;
if ( ! V_198 ) {
return FALSE ;
}
V_112 = strlen ( V_198 ) ;
F_134 ( V_74 , 0 ) ;
while ( V_6 < V_112 ) {
if ( V_198 [ V_6 ] == '%' ) {
if ( V_6 >= V_112 ) {
return FALSE ;
}
V_6 ++ ;
if ( V_240 -> V_112 > 0 ) {
F_133 ( V_241 , V_240 -> V_41 ) ;
F_115 ( V_240 , 0 ) ;
}
switch ( V_198 [ V_6 ] ) {
case 'D' :
F_133 ( V_199 , NULL ) ;
break;
case 'N' :
F_133 ( V_201 , NULL ) ;
break;
case 'S' :
F_133 ( V_202 , NULL ) ;
break;
case '%' :
F_135 ( V_240 , '%' ) ;
break;
default:
return FALSE ;
}
} else {
F_135 ( V_240 , V_198 [ V_6 ] ) ;
}
V_6 ++ ;
}
if ( V_240 -> V_112 > 0 ) {
F_133 ( V_241 , V_240 -> V_41 ) ;
}
F_31 ( V_240 , TRUE ) ;
return TRUE ;
}
static void
F_102 ( int V_7 )
{
switch ( V_7 ) {
case V_242 :
F_55 ( L_93
L_94 ) ;
break;
#ifdef F_136
case F_136 :
F_55 ( L_95
L_96 ) ;
break;
#endif
default:
F_55 ( L_97 ,
F_8 ( V_7 ) ) ;
break;
}
}
static void
V_78 ( const char * V_243 , T_37 V_244 )
{
fprintf ( V_14 , L_98 ) ;
vfprintf ( V_14 , V_243 , V_244 ) ;
fprintf ( V_14 , L_1 ) ;
}
static void
V_79 ( const char * V_159 , int V_7 , T_13 V_245 )
{
fprintf ( V_14 , L_98 ) ;
fprintf ( V_14 , F_137 ( V_7 , V_245 ) , V_159 ) ;
fprintf ( V_14 , L_1 ) ;
}
static const T_38 *
F_138 ( void * T_39 V_2 , V_122 V_246 )
{
if ( V_167 && V_167 -> V_247 == V_246 )
return & V_167 -> V_248 ;
if ( V_168 && V_168 -> V_247 == V_246 )
return & V_168 -> V_248 ;
if ( V_173 && V_173 -> V_247 == V_246 )
return & V_173 -> V_248 ;
return NULL ;
}
static T_40 *
F_139 ( T_23 * V_157 )
{
T_40 * V_127 = F_140 () ;
V_127 -> T_39 = V_157 ;
V_127 -> V_249 = F_138 ;
V_127 -> V_250 = V_251 ;
V_127 -> V_252 = V_253 ;
V_127 -> V_254 = NULL ;
return V_127 ;
}
T_41
F_76 ( T_23 * V_157 , const char * V_255 )
{
if ( ( V_125 = F_4 ( V_255 ) ) < 0 )
return V_256 ;
F_79 ( V_157 -> V_127 ) ;
V_157 -> V_127 = F_139 ( V_157 ) ;
V_157 -> V_257 = NULL ;
V_157 -> V_258 = 0 ;
V_157 -> V_159 = F_13 ( V_255 ) ;
V_157 -> V_259 = FALSE ;
V_157 -> V_260 = FALSE ;
V_157 -> V_170 = V_261 ;
V_157 -> V_262 = V_263 ;
V_157 -> V_164 = 0 ;
V_157 -> V_264 = FALSE ;
V_157 -> V_265 = 0 ;
V_157 -> V_266 = 0 ;
F_141 ( & V_157 -> V_166 ) ;
V_167 = NULL ;
V_168 = NULL ;
V_173 = NULL ;
return V_118 ;
}
static void
V_80 ( const char * V_159 , int V_7 )
{
F_55 ( L_99 ,
V_159 , F_8 ( V_7 ) ) ;
}
static void
V_81 ( const char * V_159 , int V_7 )
{
F_55 ( L_100 ,
V_159 , F_8 ( V_7 ) ) ;
}
static void
V_68 ( const char * V_267 , T_37 V_244 )
{
fprintf ( V_14 , L_98 ) ;
vfprintf ( V_14 , V_267 , V_244 ) ;
fprintf ( V_14 , L_1 ) ;
}
static void
V_69 ( const char * V_267 , T_37 V_244 )
{
vfprintf ( V_14 , V_267 , V_244 ) ;
fprintf ( V_14 , L_1 ) ;
}
