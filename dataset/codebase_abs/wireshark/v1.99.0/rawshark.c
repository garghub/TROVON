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
V_10 = F_23 ( ( long ) V_9 , V_27 ) ;
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
F_24 ( const char * V_28 ) {
char * V_29 = strchr ( V_28 , ':' ) ;
char * V_30 ;
int V_31 ;
long V_32 ;
T_14 V_33 ;
T_15 * V_34 ;
if ( ! V_29 )
return FALSE ;
V_29 ++ ;
if ( strncmp ( V_28 , L_32 , strlen ( L_32 ) ) == 0 ) {
V_31 = F_25 ( V_29 ) ;
if ( V_31 == - 1 ) {
V_15 = 0 ;
V_32 = strtol ( V_29 , & V_30 , 10 ) ;
if ( V_30 == V_29 || * V_30 != '\0' || V_15 != 0 || V_32 > V_35 ) {
return FALSE ;
}
V_31 = ( int ) V_32 ;
}
V_36 = F_26 ( V_31 ) ;
if ( V_36 == V_37 ) {
return FALSE ;
}
return TRUE ;
} else if ( strncmp ( V_28 , L_33 , strlen ( L_33 ) ) == 0 ) {
V_33 = F_27 ( V_29 ) ;
if ( V_33 ) {
V_36 = V_38 ;
V_34 = F_28 ( L_34 ) ;
F_29 ( V_34 ,
L_35 ,
V_29 ) ;
if ( F_30 ( V_34 -> V_39 ) != V_40 ) {
F_31 ( V_34 , TRUE ) ;
return FALSE ;
}
F_31 ( V_34 , TRUE ) ;
return TRUE ;
}
}
return FALSE ;
}
static void
F_32 ( T_15 * V_41 , T_15 * V_42 )
{
printf ( L_36
L_1
L_37
L_1
L_37
L_1
L_37 ,
F_33 () , F_34 () , V_41 -> V_39 ,
V_42 -> V_39 ) ;
}
int
main ( int V_43 , char * V_44 [] )
{
T_15 * V_41 ;
T_15 * V_42 ;
char * V_45 ;
int V_46 , V_47 ;
T_13 V_48 = FALSE ;
#ifdef F_4
T_16 V_49 ;
#endif
char * V_50 , * V_51 ;
char * V_52 , * V_53 ;
int V_54 , V_55 ;
int V_56 , V_57 ;
int V_58 , V_59 ;
int V_60 , V_61 ;
T_2 * V_3 = NULL ;
T_2 * V_62 [ 64 ] ;
T_17 * V_63 ;
char V_64 ;
int V_65 ;
T_18 * V_66 = F_35 () ;
T_19 V_67 ;
T_13 V_68 = FALSE ;
static const struct V_69 V_70 [] = {
{ ( char * ) L_38 , V_71 , NULL , 'h' } ,
{ ( char * ) L_39 , V_71 , NULL , 'v' } ,
{ 0 , 0 , 0 , 0 }
} ;
#define F_36 "d:F:hlnN:o:pr:R:sS:t:v"
static const char V_72 [] = F_36 ;
F_37 ( V_73 , V_74 ) ;
V_41 = F_28 ( L_40 ) ;
F_38 ( V_41 , NULL , V_75 ) ;
V_42 = F_28 ( L_41 ) ;
F_39 ( V_42 , NULL ) ;
F_40 ( L_36
L_1
L_37
L_1
L_37 ,
F_33 () , V_41 -> V_39 , V_42 -> V_39 ) ;
#ifdef F_4
F_41 ( V_43 , V_44 ) ;
F_42 () ;
#endif
F_43 () ;
memset ( V_62 , 0 , sizeof( V_62 ) ) ;
memset ( V_76 , 0 , sizeof( V_76 ) ) ;
V_77 = 0 ;
V_78 = 0 ;
V_79 = F_35 () ;
V_45 = F_44 ( V_44 [ 0 ] , main ) ;
if ( V_45 != NULL ) {
fprintf ( V_14 , L_42 ,
V_45 ) ;
}
F_43 () ;
V_65 =
V_80 |
V_81 |
V_82 |
V_12 ;
F_45 ( NULL ,
( T_4 ) V_65 ,
F_2 , NULL ) ;
F_45 ( V_11 ,
( T_4 ) V_65 ,
F_2 , NULL ) ;
F_46 ( V_83 , V_84 , V_85 ,
V_86 ) ;
F_47 ( V_87 ) ;
F_48 ( V_88 ) ;
F_49 ( V_89 ) ;
F_50 ( V_90 , V_91 , NULL , NULL ) ;
setlocale ( V_92 , L_43 ) ;
V_63 = F_51 ( & V_54 , & V_55 , & V_50 ,
& V_56 , & V_57 , & V_51 ) ;
if ( V_50 != NULL ) {
if ( V_54 != 0 ) {
F_52 ( L_44 ,
V_51 , F_8 ( V_54 ) ) ;
}
if ( V_55 != 0 ) {
F_52 ( L_45 ,
V_51 , F_8 ( V_55 ) ) ;
}
}
if ( V_51 != NULL ) {
if ( V_56 != 0 ) {
F_52 ( L_46 , V_51 ,
F_8 ( V_56 ) ) ;
}
if ( V_57 != 0 ) {
F_52 ( L_47 ,
V_51 , F_8 ( V_57 ) ) ;
}
F_15 ( V_51 ) ;
V_51 = NULL ;
}
F_53 ( & V_52 , & V_58 , & V_59 ,
& V_53 , & V_60 , & V_61 ) ;
if ( V_52 != NULL ) {
if ( V_58 != 0 ) {
F_52 ( L_48 ,
V_52 , F_8 ( V_58 ) ) ;
}
if ( V_59 != 0 ) {
F_52 ( L_49 ,
V_52 , F_8 ( V_59 ) ) ;
}
F_15 ( V_52 ) ;
}
if ( V_53 != NULL ) {
if ( V_60 != 0 ) {
F_52 (
L_50 , V_53 ,
F_8 ( V_60 ) ) ;
}
if ( V_61 != 0 ) {
F_52 (
L_51 , V_53 ,
F_8 ( V_61 ) ) ;
}
F_15 ( V_53 ) ;
}
#ifdef F_4
F_54 () ;
#endif
F_55 ( & V_93 ) ;
V_94 = V_95 ;
V_36 = V_37 ;
while ( ( V_46 = F_56 ( V_43 , V_44 , V_72 , V_70 , NULL ) ) != - 1 ) {
switch ( V_46 ) {
case 'd' :
if ( ! F_24 ( V_96 ) ) {
F_52 ( L_52 , V_96 ) ;
exit ( 1 ) ;
}
break;
case 'F' :
F_57 ( V_66 , F_13 ( V_96 ) ) ;
break;
case 'h' :
printf ( L_36
L_53
L_54 ,
F_33 () ) ;
F_1 ( stdout ) ;
exit ( 0 ) ;
break;
case 'l' :
V_97 = TRUE ;
break;
case 'n' :
V_98 . V_99 = FALSE ;
V_98 . V_100 = FALSE ;
V_98 . V_101 = FALSE ;
V_98 . V_102 = FALSE ;
break;
case 'N' :
V_64 = F_58 ( V_96 , & V_98 ) ;
if ( V_64 != '\0' ) {
F_52 ( L_55 ,
V_64 ) ;
exit ( 1 ) ;
}
break;
case 'o' :
switch ( F_30 ( V_96 ) ) {
case V_40 :
break;
case V_103 :
F_52 ( L_56 , V_96 ) ;
exit ( 1 ) ;
break;
case V_104 :
case V_105 :
F_52 ( L_57 , V_96 ) ;
exit ( 1 ) ;
break;
}
break;
case 'p' :
V_106 = TRUE ;
break;
case 'r' :
V_3 = F_13 ( V_96 ) ;
break;
case 'R' :
if( V_77 < ( int ) sizeof( V_62 ) / ( int ) sizeof( V_62 [ 0 ] ) ) {
V_62 [ V_77 ++ ] = V_96 ;
}
else {
F_52 ( L_58 ) ;
exit ( 1 ) ;
}
break;
case 's' :
V_68 = TRUE ;
break;
case 'S' :
if ( ! F_59 ( V_96 ) ) {
F_52 ( L_59 ) ;
exit ( 1 ) ;
}
break;
case 't' :
if ( strcmp ( V_96 , L_60 ) == 0 )
F_47 ( V_87 ) ;
else if ( strcmp ( V_96 , L_61 ) == 0 )
F_47 ( V_107 ) ;
else if ( strcmp ( V_96 , L_62 ) == 0 )
F_47 ( V_108 ) ;
else if ( strcmp ( V_96 , L_63 ) == 0 )
F_47 ( V_109 ) ;
else if ( strcmp ( V_96 , L_64 ) == 0 )
F_47 ( V_110 ) ;
else if ( strcmp ( V_96 , L_65 ) == 0 )
F_47 ( V_111 ) ;
else if ( strcmp ( V_96 , L_66 ) == 0 )
F_47 ( V_112 ) ;
else if ( strcmp ( V_96 , L_67 ) == 0 )
F_47 ( V_113 ) ;
else if ( strcmp ( V_96 , L_68 ) == 0 )
F_47 ( V_114 ) ;
else if ( strcmp ( V_96 , L_69 ) == 0 )
F_47 ( V_115 ) ;
else {
F_52 ( L_70 ,
V_96 ) ;
F_60 (
L_71 ) ;
F_60 (
L_72 ) ;
F_60 (
L_73 ) ;
F_60 (
L_74 ) ;
F_60 (
L_75 ) ;
exit ( 1 ) ;
}
break;
case 'v' :
{
F_32 ( V_41 , V_42 ) ;
F_31 ( V_41 , TRUE ) ;
F_31 ( V_42 , TRUE ) ;
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
F_61 () ;
for ( V_67 = 0 ; V_67 < V_66 -> V_116 ; V_67 ++ ) {
F_62 ( ( char * ) F_63 ( V_66 , V_67 ) ) ;
}
F_64 ( V_66 , TRUE ) ;
printf ( L_1 ) ;
fflush ( stdout ) ;
if ( V_117 < V_43 ) {
if ( V_3 != NULL ) {
if ( V_77 != 0 ) {
F_52 ( L_76
L_77 ) ;
exit ( 1 ) ;
}
V_62 [ V_77 ] = F_65 ( V_43 , V_44 , V_117 ) ;
}
}
if ( V_36 == V_37 ) {
F_52 ( L_78 ) ;
exit ( 1 ) ;
}
if ( V_48 ) {
F_1 ( V_14 ) ;
exit ( 1 ) ;
}
#ifdef F_4
F_66 ( F_67 ( 1 , 1 ) , & V_49 ) ;
#endif
F_68 () ;
if ( V_52 == NULL && V_53 == NULL ) {
F_69 () ;
}
F_70 ( & V_93 . V_118 , V_63 -> V_119 , TRUE ) ;
if ( V_77 != 0 ) {
for ( V_47 = 0 ; V_47 < V_77 ; V_47 ++ ) {
if ( ! F_71 ( V_62 [ V_47 ] , & V_76 [ V_78 ] ) ) {
F_52 ( L_37 , V_120 ) ;
F_72 ( V_93 . V_121 ) ;
F_73 () ;
exit ( 2 ) ;
}
V_78 ++ ;
}
}
if ( V_3 ) {
F_74 () ;
if ( F_75 ( & V_93 , V_3 ) != V_122 ) {
F_72 ( V_93 . V_121 ) ;
F_73 () ;
exit ( 2 ) ;
}
if ( V_68 ) {
T_20 V_123 = sizeof( struct V_124 ) + sizeof( V_125 ) ;
T_2 V_126 [ sizeof( struct V_124 ) + sizeof( V_125 ) ] ;
while ( V_123 != 0 ) {
T_21 V_127 = F_76 ( V_128 , V_126 , ( int ) V_123 ) ;
if ( V_127 <= 0 ) {
F_52 ( L_79 ) ;
exit ( 2 ) ;
}
V_123 -= V_127 ;
}
}
if ( ! F_77 ( & V_93 ) ) {
F_72 ( V_93 . V_121 ) ;
F_73 () ;
exit ( 2 ) ;
}
} else {
F_52 ( L_80 ) ;
exit ( 2 ) ;
}
F_72 ( V_93 . V_121 ) ;
F_73 () ;
return 0 ;
}
static T_13
F_78 ( struct V_129 * V_130 , T_22 * V_131 , int * V_7 , const T_2 * * V_132 , T_23 * V_133 ) {
struct V_134 V_135 ;
struct V_136 V_137 ;
T_21 V_138 = 0 ;
T_20 V_139 = sizeof( V_137 ) ;
T_22 * V_140 = ( T_22 * ) & V_137 ;
static T_2 V_8 [ 100 ] ;
if ( V_106 ) {
V_139 = sizeof( V_135 ) ;
V_140 = ( T_22 * ) & V_135 ;
}
while ( V_139 > 0 ) {
V_138 = F_76 ( V_128 , V_140 , ( int ) V_139 ) ;
if ( V_138 == 0 ) {
* V_7 = 0 ;
return FALSE ;
} else if ( V_138 < 0 ) {
* V_7 = V_141 ;
* V_132 = L_81 ;
return FALSE ;
}
V_139 -= V_138 ;
* V_133 += V_138 ;
V_140 += V_138 ;
}
if ( V_106 ) {
V_130 -> V_142 . V_143 = V_135 . V_142 . V_144 ;
V_130 -> V_142 . V_145 = ( V_146 ) V_135 . V_142 . V_147 * 1000 ;
V_130 -> V_148 = V_135 . V_148 ;
V_130 -> V_116 = V_135 . V_116 ;
} else {
V_130 -> V_142 . V_143 = V_137 . V_149 ;
V_130 -> V_142 . V_145 = V_137 . V_150 * 1000 ;
V_130 -> V_148 = V_137 . V_151 ;
V_130 -> V_116 = V_137 . V_152 ;
}
V_139 = V_130 -> V_148 ;
V_130 -> V_153 = V_36 ;
#if 0
printf("mem_hdr: %lu disk_hdr: %lu\n", sizeof(mem_hdr), sizeof(disk_hdr));
printf("tv_sec: %u (%04x)\n", (unsigned int) phdr->ts.secs, (unsigned int) phdr->ts.secs);
printf("tv_nsec: %d (%04x)\n", phdr->ts.nsecs, phdr->ts.nsecs);
printf("caplen: %d (%04x)\n", phdr->caplen, phdr->caplen);
printf("len: %d (%04x)\n", phdr->len, phdr->len);
#endif
if ( V_139 > V_154 ) {
* V_7 = V_155 ;
F_79 ( V_8 , 100 , L_82 ,
( unsigned long ) V_139 ) ;
* V_132 = V_8 ;
return FALSE ;
}
V_140 = V_131 ;
while ( V_139 > 0 ) {
V_138 = F_76 ( V_128 , V_140 , ( int ) V_139 ) ;
if ( V_138 == 0 ) {
* V_7 = V_156 ;
* V_132 = L_83 ;
return FALSE ;
} else if ( V_138 < 0 ) {
* V_7 = V_141 ;
* V_132 = L_84 ;
return FALSE ;
}
V_139 -= V_138 ;
* V_133 += V_138 ;
V_140 += V_138 ;
}
return TRUE ;
}
static T_13
F_77 ( T_24 * V_157 )
{
int V_7 ;
const T_2 * V_132 ;
T_23 V_133 = 0 ;
T_22 V_131 [ V_154 ] ;
struct V_129 V_130 ;
T_25 V_158 ;
memset ( & V_130 , 0 , sizeof( V_130 ) ) ;
F_80 ( & V_158 , V_157 -> V_121 , TRUE , FALSE ) ;
while ( F_78 ( & V_130 , V_131 , & V_7 , & V_132 , & V_133 ) ) {
F_81 ( V_157 , & V_158 , V_133 , & V_130 , V_131 ) ;
}
F_82 ( & V_158 ) ;
if ( V_7 != 0 ) {
switch ( V_7 ) {
case V_159 :
F_52 ( L_85 ,
V_157 -> V_160 , V_132 ) ;
break;
case V_141 :
F_52 ( L_86 ,
V_157 -> V_160 ) ;
break;
case V_156 :
F_52 ( L_87 ,
V_157 -> V_160 ) ;
break;
case V_155 :
F_52 ( L_88 ,
V_157 -> V_160 , V_132 ) ;
break;
case V_161 :
F_52 ( L_89 ,
V_157 -> V_160 , V_132 ) ;
break;
default:
F_52 ( L_90 ,
V_157 -> V_160 , F_83 ( V_7 ) ) ;
break;
}
return FALSE ;
}
return TRUE ;
}
static T_13
F_81 ( T_24 * V_157 , T_25 * V_158 , T_23 V_162 ,
struct V_129 * V_163 , const T_22 * V_131 )
{
T_26 V_164 ;
T_13 V_165 ;
int V_47 ;
if( V_163 -> V_116 == 0 )
{
printf ( L_91 , ( unsigned long int ) V_157 -> V_166 ,
( unsigned long int ) V_163 -> V_142 . V_143 ,
( unsigned long int ) V_163 -> V_142 . V_145 ) ;
fflush ( stdout ) ;
return FALSE ;
}
V_157 -> V_166 ++ ;
F_84 ( & V_164 , V_157 -> V_166 , V_163 , V_162 , V_167 ) ;
V_165 = TRUE ;
if ( V_77 > 0 ) {
for( V_47 = 0 ; V_47 < V_78 ; V_47 ++ ) {
F_85 ( V_158 , V_76 [ V_47 ] ) ;
}
}
printf ( L_92 , ( unsigned long int ) V_157 -> V_166 ) ;
F_86 ( & V_164 , & V_157 -> V_168 ,
& V_169 , V_170 ) ;
if ( V_169 == & V_164 ) {
V_171 = V_164 ;
V_169 = & V_171 ;
}
F_87 ( V_158 , V_157 -> V_172 , V_163 , F_88 ( & V_164 , V_131 ) , & V_164 , & V_157 -> V_118 ) ;
F_89 ( & V_164 , & V_167 ) ;
V_173 = V_164 ;
V_170 = & V_173 ;
V_174 = V_164 ;
V_175 = & V_174 ;
for( V_47 = 0 ; V_47 < V_77 ; V_47 ++ ) {
if ( V_76 [ V_47 ] )
V_165 = F_90 ( V_76 [ V_47 ] , V_158 ) ;
else
V_165 = TRUE ;
printf ( L_93 , V_165 ? 1 : 0 ) ;
}
printf ( L_94 ) ;
if ( V_97 )
fflush ( stdout ) ;
if ( ferror ( stdout ) ) {
F_91 ( V_15 ) ;
exit ( 2 ) ;
}
F_92 ( V_158 ) ;
F_93 ( & V_164 ) ;
return V_165 ;
}
static const char * F_94 ( T_27 * V_176 )
{
if ( ! V_176 ) {
return L_95 ;
}
if ( V_79 -> V_116 > 0 && V_176 -> V_177 ) {
return L_96 ;
}
switch( V_176 -> type ) {
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
return L_113 ;
case V_195 :
return L_96 ;
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
case V_211 :
return L_129 ;
default:
return L_95 ;
} ;
}
static const char * F_95 ( T_28 V_212 )
{
switch( V_212 ) {
case V_213 :
return L_130 ;
case V_214 :
return L_131 ;
default:
return L_95 ;
}
}
static const char * F_96 ( T_29 V_215 )
{
switch( V_215 ) {
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
case V_221 :
return L_137 ;
default:
return L_95 ;
}
}
static T_13 F_97 ( T_30 * V_222 , int V_223 )
{
T_27 * V_224 ;
static char * V_225 = NULL ;
char * V_226 = V_225 ;
static T_15 * V_227 = NULL ;
int V_228 = V_229 , V_230 ;
T_19 V_47 ;
T_31 * V_231 ;
V_125 V_232 ;
V_146 V_233 ;
T_32 V_234 ;
T_23 V_235 ;
const T_33 * V_236 = & V_237 ;
V_224 = V_222 -> V_224 ;
if ( ! V_225 ) {
V_225 = ( char * ) F_98 ( V_228 + 1 ) ;
V_226 = V_225 ;
}
if ( ! V_227 ) {
V_227 = F_28 ( L_43 ) ;
}
if( V_222 -> V_238 . V_239 -> V_240 )
{
V_230 = F_99 ( & V_222 -> V_238 , V_241 ) ;
while ( V_228 < V_230 ) {
V_228 *= 2 ;
V_225 = ( char * ) F_100 ( V_225 , V_228 + 1 ) ;
V_226 = V_225 ;
}
F_101 ( & V_222 -> V_238 ,
V_241 ,
V_225 ) ;
if ( F_102 ( V_222 -> V_238 . V_239 -> V_239 ) && V_230 > 2 ) {
V_225 [ V_230 - 1 ] = '\0' ;
V_226 ++ ;
}
}
if ( V_79 -> V_116 > 0 && V_222 -> V_224 -> V_177 ) {
F_103 ( V_227 , 0 ) ;
for ( V_47 = 0 ; V_47 < V_79 -> V_116 ; V_47 ++ ) {
V_231 = ( T_31 * ) F_63 ( V_79 , V_47 ) ;
if ( V_231 -> V_242 ) {
F_104 ( V_227 , V_231 -> V_242 ) ;
} else {
switch ( V_231 -> V_243 ) {
case V_244 :
F_104 ( V_227 , V_224 -> V_245 ) ;
break;
case V_246 :
F_104 ( V_227 , V_226 ) ;
break;
case V_247 :
switch( V_224 -> type ) {
case V_180 :
V_232 = F_105 ( & V_222 -> V_238 ) ;
V_236 = ( const struct T_33 * ) V_224 -> V_177 ;
F_104 ( V_227 , V_232 ? V_236 -> V_248 : V_236 -> V_249 ) ;
break;
case V_186 :
case V_187 :
case V_188 :
case V_189 :
F_106 ( ! V_224 -> V_250 ) ;
V_233 = F_107 ( & V_222 -> V_238 ) ;
if ( V_224 -> V_251 & V_252 ) {
F_104 ( V_227 , F_108 ( V_233 , F_109 ( V_224 -> V_177 ) , L_138 ) ) ;
} else if ( V_224 -> V_251 & V_253 ) {
F_104 ( V_227 , F_110 ( V_233 , ( V_254 * ) V_224 -> V_177 , L_138 ) ) ;
} else {
F_104 ( V_227 , F_111 ( V_233 , F_112 ( V_224 -> V_177 ) , L_138 ) ) ;
}
break;
case V_190 :
F_106 ( ! V_224 -> V_250 ) ;
V_235 = ( T_23 ) F_113 ( & V_222 -> V_238 ) ;
if ( V_224 -> V_251 & V_255 ) {
F_104 ( V_227 , F_114 ( V_235 , ( const V_256 * ) ( V_224 -> V_177 ) , L_138 ) ) ;
}
break;
case V_181 :
case V_182 :
case V_183 :
case V_184 :
V_232 = F_105 ( & V_222 -> V_238 ) ;
if ( ! V_224 -> V_250 && V_224 -> V_251 & V_252 ) {
F_104 ( V_227 , F_108 ( V_232 , F_109 ( V_224 -> V_177 ) , L_138 ) ) ;
} else if ( V_224 -> V_251 & V_253 ) {
F_104 ( V_227 , F_110 ( V_232 , ( V_254 * ) V_224 -> V_177 , L_138 ) ) ;
} else {
F_104 ( V_227 , F_111 ( V_232 , F_112 ( V_224 -> V_177 ) , L_138 ) ) ;
}
break;
case V_185 :
F_106 ( ! V_224 -> V_250 ) ;
V_234 = F_113 ( & V_222 -> V_238 ) ;
if ( V_224 -> V_251 & V_255 ) {
F_104 ( V_227 , F_114 ( V_234 , ( const V_256 * ) ( V_224 -> V_177 ) , L_138 ) ) ;
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
printf ( L_139 , V_223 , V_227 -> V_39 ) ;
return TRUE ;
}
if( V_222 -> V_238 . V_239 -> V_240 )
{
printf ( L_139 , V_223 , V_226 ) ;
return TRUE ;
}
printf ( L_140 , V_223 ) ;
return TRUE ;
}
static int
F_115 ( void * V_257 , T_34 * T_35 V_2 , T_25 * V_158 , const void * T_36 V_2 )
{
T_37 * V_258 = ( T_37 * ) V_257 ;
T_18 * V_259 ;
T_19 V_47 ;
V_259 = F_116 ( V_158 -> V_260 , V_258 -> V_261 ) ;
if( ! V_259 ) {
printf ( L_141 ) ;
return 0 ;
}
for ( V_47 = 0 ; V_47 < V_259 -> V_116 ; V_47 ++ ) {
F_97 ( ( T_30 * ) V_259 -> V_262 [ V_47 ] , V_258 -> V_223 ) ;
}
return 0 ;
}
static void
F_62 ( char * V_263 )
{
T_37 * V_258 ;
T_27 * V_176 ;
T_15 * V_264 ;
V_176 = F_117 ( V_263 ) ;
if( ! V_176 ) {
fprintf ( V_14 , L_142 , V_263 ) ;
exit ( 1 ) ;
}
switch ( V_176 -> type ) {
case V_193 :
printf ( L_143 ,
V_265 ,
F_94 ( V_176 ) ,
F_95 ( ( T_28 ) V_176 -> V_251 ) ) ;
break;
default:
printf ( L_143 ,
V_265 ,
F_94 ( V_176 ) ,
F_96 ( ( T_29 ) V_176 -> V_251 ) ) ;
break;
}
V_258 = ( T_37 * ) F_98 ( sizeof( T_37 ) ) ;
V_258 -> V_261 = V_176 -> V_266 ;
V_258 -> V_267 = V_263 ;
V_258 -> V_223 = V_265 ++ ;
V_264 = F_118 ( L_144 , V_258 , V_258 -> V_267 , V_268 , NULL , F_115 , NULL ) ;
if( V_264 ) {
fprintf ( V_14 , L_145 ,
V_264 -> V_39 ) ;
F_31 ( V_264 , TRUE ) ;
if( V_258 -> V_267 ) {
F_15 ( V_258 -> V_267 ) ;
}
F_15 ( V_258 ) ;
exit ( 1 ) ;
}
}
static void
F_119 ( T_38 V_243 , T_2 * V_242 ) {
T_31 * V_231 = ( T_31 * ) F_98 ( sizeof( T_31 ) ) ;
V_231 -> V_243 = V_243 ;
V_231 -> V_242 = F_13 ( V_242 ) ;
F_57 ( V_79 , V_231 ) ;
}
static T_13
F_59 ( T_2 * V_243 ) {
T_15 * V_269 = F_28 ( L_43 ) ;
T_20 V_116 ;
T_20 V_6 = 0 ;
if ( ! V_243 ) {
return FALSE ;
}
V_116 = strlen ( V_243 ) ;
F_120 ( V_79 , 0 ) ;
while ( V_6 < V_116 ) {
if ( V_243 [ V_6 ] == '%' ) {
if ( V_6 >= V_116 ) {
return FALSE ;
}
V_6 ++ ;
if ( V_269 -> V_116 > 0 ) {
F_119 ( V_270 , V_269 -> V_39 ) ;
F_103 ( V_269 , 0 ) ;
}
switch ( V_243 [ V_6 ] ) {
case 'D' :
F_119 ( V_244 , NULL ) ;
break;
case 'N' :
F_119 ( V_246 , NULL ) ;
break;
case 'S' :
F_119 ( V_247 , NULL ) ;
break;
case '%' :
F_121 ( V_269 , '%' ) ;
break;
default:
return FALSE ;
}
} else {
F_121 ( V_269 , V_243 [ V_6 ] ) ;
}
V_6 ++ ;
}
if ( V_269 -> V_116 > 0 ) {
F_119 ( V_270 , V_269 -> V_39 ) ;
}
F_31 ( V_269 , TRUE ) ;
return TRUE ;
}
static void
F_91 ( int V_7 )
{
switch ( V_7 ) {
case V_271 :
F_52 ( L_146
L_147 ) ;
break;
#ifdef F_122
case F_122 :
F_52 ( L_148
L_149 ) ;
break;
#endif
default:
F_52 ( L_150 ,
F_8 ( V_7 ) ) ;
break;
}
}
static void
V_84 ( const char * V_160 , int V_7 , T_13 V_272 )
{
fprintf ( V_14 , L_151 ) ;
fprintf ( V_14 , F_123 ( V_7 , V_272 ) , V_160 ) ;
fprintf ( V_14 , L_1 ) ;
}
static const T_39 *
F_124 ( void * T_40 V_2 , V_125 V_273 )
{
if ( V_169 && V_169 -> V_274 == V_273 )
return & V_169 -> V_275 ;
if ( V_170 && V_170 -> V_274 == V_273 )
return & V_170 -> V_275 ;
if ( V_175 && V_175 -> V_274 == V_273 )
return & V_175 -> V_275 ;
return NULL ;
}
static T_41 *
F_125 ( T_24 * V_157 )
{
T_41 * V_121 = F_126 () ;
V_121 -> T_40 = V_157 ;
V_121 -> V_276 = F_124 ;
V_121 -> V_277 = V_278 ;
V_121 -> V_279 = NULL ;
return V_121 ;
}
T_42
F_75 ( T_24 * V_157 , const char * V_280 )
{
if ( ( V_128 = F_3 ( V_280 ) ) < 0 )
return V_281 ;
F_72 ( V_157 -> V_121 ) ;
V_157 -> V_121 = F_125 ( V_157 ) ;
V_157 -> V_282 = NULL ;
V_157 -> V_283 = 0 ;
V_157 -> V_160 = F_13 ( V_280 ) ;
V_157 -> V_284 = FALSE ;
V_157 -> V_285 = FALSE ;
V_157 -> V_172 = V_286 ;
V_157 -> V_287 = V_288 ;
V_157 -> V_166 = 0 ;
V_157 -> V_289 = FALSE ;
V_157 -> V_290 = 0 ;
V_157 -> V_291 = FALSE ;
V_157 -> V_292 = V_154 ;
F_127 ( & V_157 -> V_168 ) ;
V_169 = NULL ;
V_170 = NULL ;
V_175 = NULL ;
return V_122 ;
}
static void
V_83 ( const char * V_293 , T_43 V_294 )
{
fprintf ( V_14 , L_151 ) ;
vfprintf ( V_14 , V_293 , V_294 ) ;
fprintf ( V_14 , L_1 ) ;
}
static void
V_85 ( const char * V_160 , int V_7 )
{
F_52 ( L_152 ,
V_160 , F_8 ( V_7 ) ) ;
}
static void
V_86 ( const char * V_160 , int V_7 )
{
F_52 ( L_153 ,
V_160 , F_8 ( V_7 ) ) ;
}
static void
V_73 ( const char * V_295 , T_43 V_294 )
{
fprintf ( V_14 , L_151 ) ;
vfprintf ( V_14 , V_295 , V_294 ) ;
fprintf ( V_14 , L_1 ) ;
}
static void
V_74 ( const char * V_295 , T_43 V_294 )
{
vfprintf ( V_14 , V_295 , V_294 ) ;
fprintf ( V_14 , L_1 ) ;
}
