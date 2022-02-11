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
static const struct V_70 V_71 [] = {
{ L_36 , V_72 , NULL , 'h' } ,
{ L_37 , V_72 , NULL , 'v' } ,
{ 0 , 0 , 0 , 0 }
} ;
#define F_33 "d:F:hlnN:o:pr:R:sS:t:v"
static const char V_73 [] = F_33 ;
setlocale ( V_74 , L_38 ) ;
F_34 ( V_75 , V_76 ) ;
V_44 = F_35 ( NULL , V_77 ) ;
V_45 = F_36 ( NULL ) ;
F_37 ( L_39
L_1
L_40
L_1
L_40 ,
F_38 () , V_44 -> V_40 , V_45 -> V_40 ) ;
#ifdef F_4
F_39 ( V_42 , V_43 ) ;
F_40 () ;
#endif
F_41 () ;
memset ( V_63 , 0 , sizeof( V_63 ) ) ;
memset ( V_78 , 0 , sizeof( V_78 ) ) ;
V_79 = 0 ;
V_80 = 0 ;
V_81 = F_32 () ;
V_46 = F_42 ( V_43 [ 0 ] , main ) ;
if ( V_46 != NULL ) {
fprintf ( V_14 , L_41 ,
V_46 ) ;
}
V_66 =
V_82 |
V_83 |
V_84 |
V_12 ;
F_43 ( NULL ,
( T_4 ) V_66 ,
F_2 , NULL ) ;
F_43 ( V_11 ,
( T_4 ) V_66 ,
F_2 , NULL ) ;
F_44 ( V_85 , V_86 , V_87 ,
V_88 ) ;
F_45 ( V_89 ) ;
F_46 ( V_90 ) ;
F_47 ( V_91 ) ;
if ( ! F_48 ( V_92 , V_93 ,
NULL , NULL ) )
return 2 ;
V_64 = F_49 ( & V_55 , & V_56 , & V_51 ,
& V_57 , & V_58 , & V_52 ) ;
if ( V_51 != NULL ) {
if ( V_55 != 0 ) {
F_50 ( L_42 ,
V_52 , F_8 ( V_55 ) ) ;
}
if ( V_56 != 0 ) {
F_50 ( L_43 ,
V_52 , F_8 ( V_56 ) ) ;
}
}
if ( V_52 != NULL ) {
if ( V_57 != 0 ) {
F_50 ( L_44 , V_52 ,
F_8 ( V_57 ) ) ;
}
if ( V_58 != 0 ) {
F_50 ( L_45 ,
V_52 , F_8 ( V_58 ) ) ;
}
F_15 ( V_52 ) ;
V_52 = NULL ;
}
F_51 ( & V_53 , & V_59 , & V_60 ,
& V_54 , & V_61 , & V_62 ) ;
F_52 ( & V_53 , & V_59 , & V_60 ,
& V_54 , & V_61 , & V_62 ) ;
if ( V_53 != NULL ) {
if ( V_59 != 0 ) {
F_50 ( L_46 ,
V_53 , F_8 ( V_59 ) ) ;
}
if ( V_60 != 0 ) {
F_50 ( L_47 ,
V_53 , F_8 ( V_60 ) ) ;
}
F_15 ( V_53 ) ;
}
if ( V_54 != NULL ) {
if ( V_61 != 0 ) {
F_50 (
L_48 , V_54 ,
F_8 ( V_61 ) ) ;
}
if ( V_62 != 0 ) {
F_50 (
L_49 , V_54 ,
F_8 ( V_62 ) ) ;
}
F_15 ( V_54 ) ;
}
#ifdef F_4
F_53 () ;
#endif
F_54 ( & V_94 ) ;
V_95 = V_96 ;
V_37 = V_38 ;
while ( ( V_47 = F_55 ( V_42 , V_43 , V_73 , V_71 , NULL ) ) != - 1 ) {
switch ( V_47 ) {
case 'd' :
if ( ! F_24 ( V_97 ) ) {
F_50 ( L_50 , V_97 ) ;
exit ( 1 ) ;
}
break;
case 'F' :
F_56 ( V_67 , F_13 ( V_97 ) ) ;
break;
case 'h' :
printf ( L_39
L_51
L_52 ,
F_38 () ) ;
F_1 ( stdout ) ;
exit ( 0 ) ;
break;
case 'l' :
V_98 = TRUE ;
break;
case 'n' :
F_57 () ;
break;
case 'N' :
V_65 = F_58 ( V_97 , & V_99 ) ;
if ( V_65 != '\0' ) {
F_50 ( L_53 ,
V_65 ) ;
exit ( 1 ) ;
}
break;
case 'o' :
switch ( F_30 ( V_97 ) ) {
case V_41 :
break;
case V_100 :
F_50 ( L_54 , V_97 ) ;
exit ( 1 ) ;
break;
case V_101 :
case V_102 :
F_50 ( L_55 , V_97 ) ;
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
F_50 ( L_56 ) ;
exit ( 1 ) ;
}
break;
case 's' :
V_69 = TRUE ;
break;
case 'S' :
if ( ! F_59 ( V_97 ) ) {
F_50 ( L_57 ) ;
exit ( 1 ) ;
}
break;
case 't' :
if ( strcmp ( V_97 , L_58 ) == 0 )
F_45 ( V_89 ) ;
else if ( strcmp ( V_97 , L_59 ) == 0 )
F_45 ( V_104 ) ;
else if ( strcmp ( V_97 , L_60 ) == 0 )
F_45 ( V_105 ) ;
else if ( strcmp ( V_97 , L_61 ) == 0 )
F_45 ( V_106 ) ;
else if ( strcmp ( V_97 , L_62 ) == 0 )
F_45 ( V_107 ) ;
else if ( strcmp ( V_97 , L_63 ) == 0 )
F_45 ( V_108 ) ;
else if ( strcmp ( V_97 , L_64 ) == 0 )
F_45 ( V_109 ) ;
else if ( strcmp ( V_97 , L_65 ) == 0 )
F_45 ( V_110 ) ;
else if ( strcmp ( V_97 , L_66 ) == 0 )
F_45 ( V_111 ) ;
else if ( strcmp ( V_97 , L_67 ) == 0 )
F_45 ( V_112 ) ;
else {
F_50 ( L_68 ,
V_97 ) ;
F_60 (
L_69 ) ;
F_60 (
L_70 ) ;
F_60 (
L_71 ) ;
F_60 (
L_72 ) ;
F_60 (
L_73 ) ;
exit ( 1 ) ;
}
break;
case 'v' :
{
F_61 ( L_74 , V_44 , V_45 ) ;
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
F_62 () ;
for ( V_68 = 0 ; V_68 < V_67 -> V_113 ; V_68 ++ ) {
F_63 ( ( char * ) F_64 ( V_67 , V_68 ) ) ;
}
F_65 ( V_67 , TRUE ) ;
printf ( L_1 ) ;
fflush ( stdout ) ;
if ( V_114 < V_42 ) {
if ( V_3 != NULL ) {
if ( V_79 != 0 ) {
F_50 ( L_75
L_76 ) ;
exit ( 1 ) ;
}
V_63 [ V_79 ] = F_66 ( V_42 , V_43 , V_114 ) ;
}
}
if ( V_37 == V_38 ) {
F_50 ( L_77 ) ;
exit ( 1 ) ;
}
if ( V_49 ) {
F_1 ( V_14 ) ;
exit ( 1 ) ;
}
#ifdef F_4
F_67 ( F_68 ( 1 , 1 ) , & V_50 ) ;
#endif
F_69 () ;
if ( V_53 == NULL && V_54 == NULL ) {
F_70 () ;
F_71 () ;
}
F_72 ( & V_94 . V_115 , V_64 -> V_116 , TRUE ) ;
if ( V_79 != 0 ) {
for ( V_48 = 0 ; V_48 < V_79 ; V_48 ++ ) {
T_2 * V_117 ;
if ( ! F_73 ( V_63 [ V_48 ] , & V_78 [ V_80 ] , & V_117 ) ) {
F_50 ( L_40 , V_117 ) ;
F_15 ( V_117 ) ;
F_74 ( V_94 . V_118 ) ;
F_75 () ;
exit ( 2 ) ;
}
V_80 ++ ;
}
}
if ( V_3 ) {
F_76 () ;
if ( F_77 ( & V_94 , V_3 ) != V_119 ) {
F_74 ( V_94 . V_118 ) ;
F_75 () ;
exit ( 2 ) ;
}
if ( V_69 ) {
T_20 V_120 = sizeof( struct V_121 ) + sizeof( V_122 ) ;
T_2 V_123 [ sizeof( struct V_121 ) + sizeof( V_122 ) ] ;
while ( V_120 != 0 ) {
T_21 V_124 = F_78 ( V_125 , V_123 , ( int ) V_120 ) ;
if ( V_124 <= 0 ) {
F_50 ( L_78 ) ;
exit ( 2 ) ;
}
V_120 -= V_124 ;
}
}
if ( ! F_79 ( & V_94 ) ) {
F_74 ( V_94 . V_118 ) ;
F_75 () ;
exit ( 2 ) ;
}
} else {
F_50 ( L_79 ) ;
exit ( 2 ) ;
}
F_74 ( V_94 . V_118 ) ;
F_75 () ;
return 0 ;
}
static T_13
F_80 ( struct V_126 * V_127 , T_22 * V_128 , int * V_7 , T_2 * * V_129 , T_23 * V_130 ) {
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
V_135 = F_78 ( V_125 , V_137 , ( int ) V_136 ) ;
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
* V_129 = F_81 ( L_80 ,
( unsigned long ) V_136 ) ;
return FALSE ;
}
V_137 = V_128 ;
while ( V_136 > 0 ) {
V_135 = F_78 ( V_125 , V_137 , ( int ) V_136 ) ;
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
F_79 ( T_24 * V_153 )
{
int V_7 ;
T_2 * V_129 ;
T_23 V_130 = 0 ;
T_22 V_128 [ V_150 ] ;
struct V_126 V_127 ;
T_25 V_154 ;
F_82 ( & V_127 ) ;
F_83 ( & V_154 , V_153 -> V_118 , TRUE , FALSE ) ;
while ( F_80 ( & V_127 , V_128 , & V_7 , & V_129 , & V_130 ) ) {
F_84 ( V_153 , & V_154 , V_130 , & V_127 , V_128 ) ;
}
F_85 ( & V_154 ) ;
F_86 ( & V_127 ) ;
if ( V_7 != 0 ) {
switch ( V_7 ) {
case V_155 :
F_50 ( L_81 ,
V_153 -> V_156 ,
V_129 != NULL ? V_129 : L_82 ) ;
F_15 ( V_129 ) ;
break;
case V_152 :
F_50 ( L_83 ,
V_153 -> V_156 ) ;
break;
case V_151 :
F_50 ( L_84 ,
V_153 -> V_156 ,
V_129 != NULL ? V_129 : L_82 ) ;
F_15 ( V_129 ) ;
break;
case V_157 :
F_50 ( L_85 ,
V_153 -> V_156 ,
V_129 != NULL ? V_129 : L_82 ) ;
F_15 ( V_129 ) ;
break;
default:
F_50 ( L_86 ,
V_153 -> V_156 , F_87 ( V_7 ) ) ;
break;
}
return FALSE ;
}
return TRUE ;
}
static T_13
F_84 ( T_24 * V_153 , T_25 * V_154 , T_23 V_158 ,
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
F_88 ( & V_160 , V_153 -> V_162 , V_159 , V_158 , V_163 ) ;
V_161 = TRUE ;
if ( V_79 > 0 ) {
for( V_48 = 0 ; V_48 < V_80 ; V_48 ++ ) {
F_89 ( V_154 , V_78 [ V_48 ] ) ;
}
}
printf ( L_88 , ( unsigned long int ) V_153 -> V_162 ) ;
F_90 ( & V_160 , & V_153 -> V_164 ,
& V_165 , V_166 ) ;
if ( V_165 == & V_160 ) {
V_167 = V_160 ;
V_165 = & V_167 ;
}
F_91 ( V_154 , V_153 -> V_168 , V_159 , F_92 ( & V_160 , V_128 ) , & V_160 , & V_153 -> V_115 ) ;
F_93 ( & V_160 , & V_163 ) ;
V_169 = V_160 ;
V_166 = & V_169 ;
V_170 = V_160 ;
V_171 = & V_170 ;
for( V_48 = 0 ; V_48 < V_79 ; V_48 ++ ) {
if ( V_78 [ V_48 ] )
V_161 = F_94 ( V_78 [ V_48 ] , V_154 ) ;
else
V_161 = TRUE ;
printf ( L_89 , V_161 ? 1 : 0 ) ;
}
printf ( L_90 ) ;
if ( V_98 )
fflush ( stdout ) ;
if ( ferror ( stdout ) ) {
F_95 ( V_15 ) ;
exit ( 2 ) ;
}
F_96 ( V_154 ) ;
F_97 ( & V_160 ) ;
return V_161 ;
}
static const char * F_98 ( T_27 * V_172 )
{
const char * V_40 ;
if ( ! V_172 ) {
return L_91 ;
}
if ( V_81 -> V_113 > 0 && V_172 -> V_173 ) {
return L_92 ;
}
V_40 = F_99 ( V_172 -> type ) ;
if ( V_40 == NULL ) {
V_40 = L_91 ;
}
return V_40 ;
}
static void F_100 ( T_27 * V_172 , char * V_123 , int V_174 )
{
if ( V_172 -> type != V_175 )
{
F_101 ( V_123 , F_102 ( V_172 -> V_176 ) , V_174 ) ;
}
else
{
F_103 ( V_123 , V_174 , L_93 , V_172 -> V_176 ) ;
}
}
static T_13 F_104 ( T_28 * V_177 , int V_178 )
{
T_27 * V_179 ;
char * V_180 = NULL ;
char * V_181 = NULL ;
static T_15 * V_182 = NULL ;
int V_183 ;
T_19 V_48 ;
T_29 * V_184 ;
V_122 V_185 ;
V_142 V_186 ;
T_30 V_187 ;
T_23 V_188 ;
const T_31 * V_189 = & V_190 ;
V_179 = V_177 -> V_179 ;
if ( ! V_182 ) {
V_182 = F_28 ( L_38 ) ;
}
if( V_177 -> V_191 . V_192 -> V_193 )
{
V_183 = F_105 ( & V_177 -> V_191 , V_194 , V_177 -> V_179 -> V_176 ) ;
V_180 = F_106 ( NULL , & V_177 -> V_191 ,
V_194 , V_177 -> V_179 -> V_176 ) ;
V_181 = V_180 ;
if ( F_107 ( V_177 -> V_191 . V_192 -> V_192 ) && V_183 > 2 ) {
V_180 [ V_183 - 1 ] = '\0' ;
V_181 ++ ;
}
}
if ( V_81 -> V_113 > 0 && V_177 -> V_179 -> V_173 ) {
F_108 ( V_182 , 0 ) ;
for ( V_48 = 0 ; V_48 < V_81 -> V_113 ; V_48 ++ ) {
V_184 = ( T_29 * ) F_64 ( V_81 , V_48 ) ;
if ( V_184 -> V_195 ) {
F_109 ( V_182 , V_184 -> V_195 ) ;
} else {
switch ( V_184 -> V_196 ) {
case V_197 :
F_109 ( V_182 , V_179 -> V_198 ) ;
break;
case V_199 :
F_109 ( V_182 , V_181 ) ;
break;
case V_200 :
switch( V_179 -> type ) {
case V_175 :
V_187 = F_110 ( & V_177 -> V_191 ) ;
V_189 = ( const struct T_31 * ) V_179 -> V_173 ;
F_109 ( V_182 , V_187 ? V_189 -> V_201 : V_189 -> V_202 ) ;
break;
case V_203 :
case V_204 :
case V_205 :
case V_206 :
F_111 ( ! V_179 -> V_207 ) ;
V_186 = F_112 ( & V_177 -> V_191 ) ;
if ( V_179 -> V_176 & V_208 ) {
F_109 ( V_182 , F_113 ( V_186 , F_114 ( V_179 -> V_173 ) , L_94 ) ) ;
} else if ( V_179 -> V_176 & V_209 ) {
F_109 ( V_182 , F_115 ( V_186 , ( V_210 * ) V_179 -> V_173 , L_94 ) ) ;
} else {
F_109 ( V_182 , F_116 ( V_186 , F_117 ( V_179 -> V_173 ) , L_94 ) ) ;
}
break;
case V_211 :
case V_212 :
case V_213 :
case V_214 :
F_111 ( ! V_179 -> V_207 ) ;
V_188 = ( T_23 ) F_118 ( & V_177 -> V_191 ) ;
if ( V_179 -> V_176 & V_215 ) {
F_109 ( V_182 , F_119 ( V_188 , ( const V_216 * ) ( V_179 -> V_173 ) , L_94 ) ) ;
}
break;
case V_217 :
case V_218 :
case V_219 :
case V_220 :
F_111 ( ! V_179 -> V_207 ) ;
V_185 = F_120 ( & V_177 -> V_191 ) ;
if ( ! V_179 -> V_207 && V_179 -> V_176 & V_208 ) {
F_109 ( V_182 , F_113 ( V_185 , F_114 ( V_179 -> V_173 ) , L_94 ) ) ;
} else if ( V_179 -> V_176 & V_209 ) {
F_109 ( V_182 , F_115 ( V_185 , ( V_210 * ) V_179 -> V_173 , L_94 ) ) ;
} else {
F_109 ( V_182 , F_116 ( V_185 , F_117 ( V_179 -> V_173 ) , L_94 ) ) ;
}
break;
case V_221 :
case V_222 :
case V_223 :
case V_224 :
F_111 ( ! V_179 -> V_207 ) ;
V_187 = F_110 ( & V_177 -> V_191 ) ;
if ( V_179 -> V_176 & V_215 ) {
F_109 ( V_182 , F_119 ( V_187 , ( const V_216 * ) ( V_179 -> V_173 ) , L_94 ) ) ;
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
printf ( L_95 , V_178 , V_182 -> V_40 ) ;
F_121 ( NULL , V_180 ) ;
return TRUE ;
}
if( V_177 -> V_191 . V_192 -> V_193 )
{
printf ( L_95 , V_178 , V_181 ) ;
F_121 ( NULL , V_180 ) ;
return TRUE ;
}
printf ( L_96 , V_178 ) ;
return TRUE ;
}
static int
F_122 ( void * V_225 , T_32 * T_33 V_2 , T_25 * V_154 , const void * T_34 V_2 )
{
T_35 * V_226 = ( T_35 * ) V_225 ;
T_18 * V_227 ;
T_19 V_48 ;
V_227 = F_123 ( V_154 -> V_228 , V_226 -> V_229 ) ;
if( ! V_227 ) {
printf ( L_97 ) ;
return 0 ;
}
for ( V_48 = 0 ; V_48 < V_227 -> V_113 ; V_48 ++ ) {
F_104 ( ( T_28 * ) V_227 -> V_230 [ V_48 ] , V_226 -> V_178 ) ;
}
return 0 ;
}
static void
F_63 ( char * V_231 )
{
T_35 * V_226 ;
T_27 * V_172 ;
T_15 * V_232 ;
char V_233 [ 100 ] ;
V_172 = F_124 ( V_231 ) ;
if( ! V_172 ) {
fprintf ( V_14 , L_98 , V_231 ) ;
exit ( 1 ) ;
}
F_100 ( V_172 , V_233 , sizeof( V_233 ) ) ;
printf ( L_99 ,
V_234 ,
F_98 ( V_172 ) ,
V_233 ) ;
V_226 = ( T_35 * ) F_125 ( sizeof( T_35 ) ) ;
V_226 -> V_229 = V_172 -> V_235 ;
V_226 -> V_236 = V_231 ;
V_226 -> V_178 = V_234 ++ ;
V_232 = F_126 ( L_100 , V_226 , V_226 -> V_236 , V_237 , NULL , F_122 , NULL ) ;
if( V_232 ) {
fprintf ( V_14 , L_101 ,
V_232 -> V_40 ) ;
F_31 ( V_232 , TRUE ) ;
if( V_226 -> V_236 ) {
F_15 ( V_226 -> V_236 ) ;
}
F_15 ( V_226 ) ;
exit ( 1 ) ;
}
}
static void
F_127 ( T_36 V_196 , T_2 * V_195 ) {
T_29 * V_184 = ( T_29 * ) F_125 ( sizeof( T_29 ) ) ;
V_184 -> V_196 = V_196 ;
V_184 -> V_195 = F_13 ( V_195 ) ;
F_56 ( V_81 , V_184 ) ;
}
static T_13
F_59 ( T_2 * V_196 ) {
T_15 * V_238 = F_28 ( L_38 ) ;
T_20 V_113 ;
T_20 V_6 = 0 ;
if ( ! V_196 ) {
return FALSE ;
}
V_113 = strlen ( V_196 ) ;
F_128 ( V_81 , 0 ) ;
while ( V_6 < V_113 ) {
if ( V_196 [ V_6 ] == '%' ) {
if ( V_6 >= V_113 ) {
return FALSE ;
}
V_6 ++ ;
if ( V_238 -> V_113 > 0 ) {
F_127 ( V_239 , V_238 -> V_40 ) ;
F_108 ( V_238 , 0 ) ;
}
switch ( V_196 [ V_6 ] ) {
case 'D' :
F_127 ( V_197 , NULL ) ;
break;
case 'N' :
F_127 ( V_199 , NULL ) ;
break;
case 'S' :
F_127 ( V_200 , NULL ) ;
break;
case '%' :
F_129 ( V_238 , '%' ) ;
break;
default:
return FALSE ;
}
} else {
F_129 ( V_238 , V_196 [ V_6 ] ) ;
}
V_6 ++ ;
}
if ( V_238 -> V_113 > 0 ) {
F_127 ( V_239 , V_238 -> V_40 ) ;
}
F_31 ( V_238 , TRUE ) ;
return TRUE ;
}
static void
F_95 ( int V_7 )
{
switch ( V_7 ) {
case V_240 :
F_50 ( L_102
L_103 ) ;
break;
#ifdef F_130
case F_130 :
F_50 ( L_104
L_105 ) ;
break;
#endif
default:
F_50 ( L_106 ,
F_8 ( V_7 ) ) ;
break;
}
}
static void
V_86 ( const char * V_156 , int V_7 , T_13 V_241 )
{
fprintf ( V_14 , L_107 ) ;
fprintf ( V_14 , F_131 ( V_7 , V_241 ) , V_156 ) ;
fprintf ( V_14 , L_1 ) ;
}
static const T_37 *
F_132 ( void * T_38 V_2 , V_122 V_242 )
{
if ( V_165 && V_165 -> V_243 == V_242 )
return & V_165 -> V_244 ;
if ( V_166 && V_166 -> V_243 == V_242 )
return & V_166 -> V_244 ;
if ( V_171 && V_171 -> V_243 == V_242 )
return & V_171 -> V_244 ;
return NULL ;
}
static T_39 *
F_133 ( T_24 * V_153 )
{
T_39 * V_118 = F_134 () ;
V_118 -> T_38 = V_153 ;
V_118 -> V_245 = F_132 ;
V_118 -> V_246 = V_247 ;
V_118 -> V_248 = NULL ;
return V_118 ;
}
T_40
F_77 ( T_24 * V_153 , const char * V_249 )
{
if ( ( V_125 = F_3 ( V_249 ) ) < 0 )
return V_250 ;
F_74 ( V_153 -> V_118 ) ;
V_153 -> V_118 = F_133 ( V_153 ) ;
V_153 -> V_251 = NULL ;
V_153 -> V_252 = 0 ;
V_153 -> V_156 = F_13 ( V_249 ) ;
V_153 -> V_253 = FALSE ;
V_153 -> V_254 = FALSE ;
V_153 -> V_168 = V_255 ;
V_153 -> V_256 = V_257 ;
V_153 -> V_162 = 0 ;
V_153 -> V_258 = FALSE ;
V_153 -> V_259 = 0 ;
V_153 -> V_260 = FALSE ;
V_153 -> V_261 = V_150 ;
F_135 ( & V_153 -> V_164 ) ;
V_165 = NULL ;
V_166 = NULL ;
V_171 = NULL ;
return V_119 ;
}
static void
V_85 ( const char * V_262 , T_41 V_263 )
{
fprintf ( V_14 , L_107 ) ;
vfprintf ( V_14 , V_262 , V_263 ) ;
fprintf ( V_14 , L_1 ) ;
}
static void
V_87 ( const char * V_156 , int V_7 )
{
F_50 ( L_108 ,
V_156 , F_8 ( V_7 ) ) ;
}
static void
V_88 ( const char * V_156 , int V_7 )
{
F_50 ( L_109 ,
V_156 , F_8 ( V_7 ) ) ;
}
static void
V_75 ( const char * V_264 , T_41 V_263 )
{
fprintf ( V_14 , L_107 ) ;
vfprintf ( V_14 , V_264 , V_263 ) ;
fprintf ( V_14 , L_1 ) ;
}
static void
V_76 ( const char * V_264 , T_41 V_263 )
{
vfprintf ( V_14 , V_264 , V_263 ) ;
fprintf ( V_14 , L_1 ) ;
}
