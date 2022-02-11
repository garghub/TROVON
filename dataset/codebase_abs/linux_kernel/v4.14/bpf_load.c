static int F_1 ( const char * V_1 , int V_2 )
{
int V_3 = atoi ( V_1 ) , V_4 ;
V_4 = F_2 ( V_5 , & V_3 , & V_2 , V_6 ) ;
if ( V_4 < 0 ) {
printf ( L_1 ) ;
return - 1 ;
}
return 0 ;
}
static int F_3 ( const char * V_1 , struct V_7 * V_8 , int V_9 )
{
bool V_10 = strncmp ( V_1 , L_2 , 6 ) == 0 ;
bool V_11 = strncmp ( V_1 , L_3 , 7 ) == 0 ;
bool V_12 = strncmp ( V_1 , L_4 , 10 ) == 0 ;
bool V_13 = strncmp ( V_1 , L_5 , 11 ) == 0 ;
bool V_14 = strncmp ( V_1 , L_6 , 3 ) == 0 ;
bool V_15 = strncmp ( V_1 , L_7 , 10 ) == 0 ;
bool V_16 = strncmp ( V_1 , L_8 , 10 ) == 0 ;
bool V_17 = strncmp ( V_1 , L_9 , 11 ) == 0 ;
bool V_18 = strncmp ( V_1 , L_10 , 7 ) == 0 ;
bool V_19 = strncmp ( V_1 , L_11 , 6 ) == 0 ;
T_1 V_20 = V_9 / sizeof( struct V_7 ) ;
enum V_21 V_22 ;
char V_23 [ 256 ] ;
int V_24 , V_25 , V_4 , V_26 ;
struct V_27 V_28 = {} ;
V_28 . type = V_29 ;
V_28 . V_30 = V_31 ;
V_28 . V_32 = 1 ;
V_28 . V_33 = 1 ;
if ( V_10 ) {
V_22 = V_34 ;
} else if ( V_11 || V_12 ) {
V_22 = V_35 ;
} else if ( V_13 ) {
V_22 = V_36 ;
} else if ( V_14 ) {
V_22 = V_37 ;
} else if ( V_15 ) {
V_22 = V_38 ;
} else if ( V_16 ) {
V_22 = V_39 ;
} else if ( V_17 ) {
V_22 = V_40 ;
} else if ( V_18 ) {
V_22 = V_41 ;
} else if ( V_19 ) {
V_22 = V_42 ;
} else {
printf ( L_12 , V_1 ) ;
return - 1 ;
}
V_24 = F_4 ( V_22 , V_8 , V_20 , V_43 , V_44 ,
V_45 , V_46 ) ;
if ( V_24 < 0 ) {
printf ( L_13 , V_47 , V_45 ) ;
return - 1 ;
}
V_2 [ V_48 ++ ] = V_24 ;
if ( V_14 || V_15 || V_16 || V_17 )
return 0 ;
if ( V_10 || V_18 || V_19 ) {
if ( V_10 )
V_1 += 6 ;
else
V_1 += 7 ;
if ( * V_1 != '/' )
return 0 ;
V_1 ++ ;
if ( ! isdigit ( * V_1 ) ) {
printf ( L_14 ) ;
return - 1 ;
}
return F_1 ( V_1 , V_24 ) ;
}
if ( V_11 || V_12 ) {
if ( V_11 )
V_1 += 7 ;
else
V_1 += 10 ;
if ( * V_1 == 0 ) {
printf ( L_15 ) ;
return - 1 ;
}
if ( isdigit ( * V_1 ) )
return F_1 ( V_1 , V_24 ) ;
snprintf ( V_23 , sizeof( V_23 ) ,
L_16 ,
V_11 ? 'p' : 'r' , V_1 , V_1 ) ;
V_4 = system ( V_23 ) ;
if ( V_4 < 0 ) {
printf ( L_17 ,
V_1 , strerror ( V_47 ) ) ;
return - 1 ;
}
strcpy ( V_23 , V_49 ) ;
strcat ( V_23 , L_18 ) ;
strcat ( V_23 , V_1 ) ;
strcat ( V_23 , L_19 ) ;
} else if ( V_13 ) {
V_1 += 11 ;
if ( * V_1 == 0 ) {
printf ( L_15 ) ;
return - 1 ;
}
strcpy ( V_23 , V_49 ) ;
strcat ( V_23 , L_20 ) ;
strcat ( V_23 , V_1 ) ;
strcat ( V_23 , L_19 ) ;
}
V_25 = F_5 ( V_23 , V_50 , 0 ) ;
if ( V_25 < 0 ) {
printf ( L_21 , V_1 ) ;
return - 1 ;
}
V_4 = F_6 ( V_25 , V_23 , sizeof( V_23 ) ) ;
if ( V_4 < 0 || V_4 >= sizeof( V_23 ) ) {
printf ( L_22 , V_1 , strerror ( V_47 ) ) ;
return - 1 ;
}
F_7 ( V_25 ) ;
V_23 [ V_4 ] = 0 ;
V_26 = atoi ( V_23 ) ;
V_28 . V_51 = V_26 ;
V_25 = F_8 ( & V_28 , - 1 , 0 , - 1 , 0 ) ;
if ( V_25 < 0 ) {
printf ( L_23 , V_26 , V_25 , strerror ( V_47 ) ) ;
return - 1 ;
}
V_52 [ V_48 - 1 ] = V_25 ;
F_9 ( V_25 , V_53 , 0 ) ;
F_9 ( V_25 , V_54 , V_24 ) ;
return 0 ;
}
static int F_10 ( struct V_55 * V_56 , int V_57 ,
T_2 V_58 )
{
int V_59 , V_60 ;
for ( V_59 = 0 ; V_59 < V_57 ; V_59 ++ ) {
if ( V_58 ) {
V_58 ( & V_56 [ V_59 ] , V_59 ) ;
if ( V_56 [ V_59 ] . V_24 != - 1 ) {
V_61 [ V_59 ] = V_56 [ V_59 ] . V_24 ;
continue;
}
}
V_60 = V_56 [ V_59 ] . V_62 . V_63 & V_64 ?
V_56 [ V_59 ] . V_62 . V_60 : - 1 ;
if ( V_56 [ V_59 ] . V_62 . type == V_65 ||
V_56 [ V_59 ] . V_62 . type == V_66 ) {
int V_67 = V_61 [ V_56 [ V_59 ] . V_62 . V_68 ] ;
V_61 [ V_59 ] = F_11 ( V_56 [ V_59 ] . V_62 . type ,
V_56 [ V_59 ] . V_62 . V_69 ,
V_67 ,
V_56 [ V_59 ] . V_62 . V_70 ,
V_56 [ V_59 ] . V_62 . V_63 ,
V_60 ) ;
} else {
V_61 [ V_59 ] = F_12 ( V_56 [ V_59 ] . V_62 . type ,
V_56 [ V_59 ] . V_62 . V_69 ,
V_56 [ V_59 ] . V_62 . V_71 ,
V_56 [ V_59 ] . V_62 . V_70 ,
V_56 [ V_59 ] . V_62 . V_63 ,
V_60 ) ;
}
if ( V_61 [ V_59 ] < 0 ) {
printf ( L_24 ,
V_47 , strerror ( V_47 ) ) ;
return 1 ;
}
V_56 [ V_59 ] . V_24 = V_61 [ V_59 ] ;
if ( V_56 [ V_59 ] . V_62 . type == V_72 )
V_5 = V_61 [ V_59 ] ;
}
return 0 ;
}
static int F_13 ( T_3 * V_73 , int V_59 , T_4 * V_74 , char * * V_75 ,
T_5 * V_76 , T_6 * * V_77 )
{
T_7 * V_78 ;
V_78 = F_14 ( V_73 , V_59 ) ;
if ( ! V_78 )
return 1 ;
if ( F_15 ( V_78 , V_76 ) != V_76 )
return 2 ;
* V_75 = F_16 ( V_73 , V_74 -> V_79 , V_76 -> V_80 ) ;
if ( ! * V_75 || ! V_76 -> V_81 )
return 3 ;
* V_77 = F_17 ( V_78 , 0 ) ;
if ( ! * V_77 || F_17 ( V_78 , * V_77 ) != NULL )
return 4 ;
return 0 ;
}
static int F_18 ( T_6 * V_77 , T_6 * V_82 ,
T_5 * V_76 , struct V_7 * V_83 ,
struct V_55 * V_56 , int V_57 )
{
int V_59 , V_84 ;
V_84 = V_76 -> V_81 / V_76 -> V_85 ;
for ( V_59 = 0 ; V_59 < V_84 ; V_59 ++ ) {
T_8 V_86 ;
T_9 V_87 ;
unsigned int V_88 ;
bool V_89 = false ;
int V_90 , V_91 ;
F_19 ( V_77 , V_59 , & V_87 ) ;
V_88 = V_87 . V_92 / sizeof( struct V_7 ) ;
F_20 ( V_82 , F_21 ( V_87 . V_93 ) , & V_86 ) ;
if ( V_83 [ V_88 ] . V_94 != ( V_95 | V_96 | V_97 ) ) {
printf ( L_25 ,
V_88 , V_83 [ V_88 ] . V_94 ) ;
return 1 ;
}
V_83 [ V_88 ] . V_98 = V_99 ;
for ( V_91 = 0 ; V_91 < V_57 ; V_91 ++ ) {
if ( V_56 [ V_91 ] . V_100 == V_86 . V_101 ) {
V_89 = true ;
break;
}
}
if ( V_89 ) {
V_83 [ V_88 ] . V_102 = V_56 [ V_91 ] . V_24 ;
} else {
printf ( L_26 ,
V_88 ) ;
return 1 ;
}
}
return 0 ;
}
static int F_22 ( const void * V_103 , const void * V_104 )
{
const T_8 * V_105 = ( const T_8 * ) V_103 ;
const T_8 * V_106 = ( const T_8 * ) V_104 ;
if ( V_105 -> V_101 < V_106 -> V_101 )
return - 1 ;
else if ( V_105 -> V_101 > V_106 -> V_101 )
return 1 ;
else
return 0 ;
}
static int F_23 ( struct V_55 * V_56 , int V_107 ,
T_3 * V_73 , T_6 * V_82 , int V_108 )
{
int V_109 , V_110 ;
bool V_111 = false ;
T_6 * V_112 ;
int V_59 , V_57 ;
T_8 * V_86 ;
T_7 * V_78 ;
int V_113 ;
if ( V_107 < 0 )
return - V_114 ;
if ( ! V_82 )
return - V_114 ;
V_78 = F_14 ( V_73 , V_107 ) ;
if ( V_78 )
V_112 = F_17 ( V_78 , NULL ) ;
if ( ! V_78 || ! V_112 ) {
printf ( L_27 ,
V_107 ) ;
return - V_114 ;
}
V_86 = calloc ( V_115 + 1 , sizeof( T_8 ) ) ;
for ( V_59 = 0 , V_57 = 0 ; V_59 < V_82 -> V_116 / sizeof( T_8 ) ; V_59 ++ ) {
assert ( V_57 < V_115 + 1 ) ;
if ( ! F_20 ( V_82 , V_59 , & V_86 [ V_57 ] ) )
continue;
if ( V_86 [ V_57 ] . V_117 != V_107 )
continue;
V_57 ++ ;
}
qsort ( V_86 , V_57 , sizeof( T_8 ) , F_22 ) ;
V_109 = V_112 -> V_116 / V_57 ;
V_110 = sizeof( struct V_118 ) ;
if ( V_109 < V_110 ) {
V_110 = V_109 ;
} else if ( V_109 > V_110 ) {
V_111 = true ;
}
for ( V_59 = 0 ; V_59 < V_57 ; V_59 ++ ) {
unsigned char * V_119 , * V_120 ;
struct V_118 * V_62 ;
const char * V_121 ;
T_1 V_122 ;
V_121 = F_16 ( V_73 , V_108 , V_86 [ V_59 ] . V_123 ) ;
V_56 [ V_59 ] . V_124 = F_24 ( V_121 ) ;
if ( ! V_56 [ V_59 ] . V_124 ) {
printf ( L_28 , V_121 ,
strerror ( V_47 ) , V_47 ) ;
free ( V_86 ) ;
return - V_47 ;
}
V_122 = V_86 [ V_59 ] . V_101 ;
V_62 = (struct V_118 * ) ( V_112 -> V_125 + V_122 ) ;
V_56 [ V_59 ] . V_100 = V_122 ;
memset ( & V_56 [ V_59 ] . V_62 , 0 , sizeof( struct V_118 ) ) ;
memcpy ( & V_56 [ V_59 ] . V_62 , V_62 , V_110 ) ;
if ( V_111 ) {
V_119 = ( unsigned char * ) V_62 + V_110 ;
V_120 = ( unsigned char * ) V_62 + V_109 ;
for (; V_119 < V_120 ; V_119 ++ ) {
if ( * V_119 != 0 ) {
free ( V_86 ) ;
return - V_126 ;
}
}
}
}
free ( V_86 ) ;
return V_57 ;
}
static int F_25 ( const char * V_127 , T_2 V_58 )
{
int V_24 , V_59 , V_128 , V_107 = - 1 , V_108 = - 1 ;
T_3 * V_73 ;
T_4 V_74 ;
T_5 V_76 , V_129 ;
T_6 * V_77 , * V_130 , * V_112 = NULL , * V_82 = NULL ;
char * V_75 , * V_131 ;
int V_57 = 0 ;
V_44 = 0 ;
memset ( V_43 , 0 , sizeof( V_43 ) ) ;
memset ( V_132 , 0 , sizeof( V_132 ) ) ;
if ( F_26 ( V_133 ) == V_134 )
return 1 ;
V_24 = F_5 ( V_127 , V_50 , 0 ) ;
if ( V_24 < 0 )
return 1 ;
V_73 = F_27 ( V_24 , V_135 , NULL ) ;
if ( ! V_73 )
return 1 ;
if ( F_28 ( V_73 , & V_74 ) != & V_74 )
return 1 ;
V_59 = system ( L_29 ) ;
for ( V_59 = 1 ; V_59 < V_74 . V_136 ; V_59 ++ ) {
if ( F_13 ( V_73 , V_59 , & V_74 , & V_75 , & V_76 , & V_77 ) )
continue;
if ( 0 )
printf ( L_30 ,
V_59 , V_75 , V_77 -> V_125 , V_77 -> V_116 ,
V_76 . V_137 , ( int ) V_76 . V_138 ) ;
if ( strcmp ( V_75 , L_31 ) == 0 ) {
V_132 [ V_59 ] = true ;
memcpy ( V_43 , V_77 -> V_125 , V_77 -> V_116 ) ;
} else if ( strcmp ( V_75 , L_32 ) == 0 ) {
V_132 [ V_59 ] = true ;
if ( V_77 -> V_116 != sizeof( int ) ) {
printf ( L_33 ,
V_77 -> V_116 ) ;
return 1 ;
}
memcpy ( & V_44 , V_77 -> V_125 , sizeof( int ) ) ;
} else if ( strcmp ( V_75 , L_34 ) == 0 ) {
int V_90 ;
V_107 = V_59 ;
V_112 = V_77 ;
for ( V_90 = 0 ; V_90 < V_115 ; V_90 ++ )
V_139 [ V_90 ] . V_24 = - 1 ;
} else if ( V_76 . V_140 == V_141 ) {
V_108 = V_76 . V_137 ;
V_82 = V_77 ;
}
}
V_128 = 1 ;
if ( ! V_82 ) {
printf ( L_35 ) ;
goto V_142;
}
if ( V_112 ) {
V_57 = F_23 ( V_139 , V_107 ,
V_73 , V_82 , V_108 ) ;
if ( V_57 < 0 ) {
printf ( L_36 ,
V_57 , strerror ( - V_57 ) ) ;
V_128 = 1 ;
goto V_142;
}
if ( F_10 ( V_139 , V_57 , V_58 ) )
goto V_142;
V_143 = V_57 ;
V_132 [ V_107 ] = true ;
}
for ( V_59 = 1 ; V_59 < V_74 . V_136 ; V_59 ++ ) {
if ( V_132 [ V_59 ] )
continue;
if ( F_13 ( V_73 , V_59 , & V_74 , & V_75 , & V_76 , & V_77 ) )
continue;
if ( V_76 . V_140 == V_144 ) {
struct V_7 * V_145 ;
if ( F_13 ( V_73 , V_76 . V_146 , & V_74 , & V_131 ,
& V_129 , & V_130 ) )
continue;
if ( V_129 . V_140 != V_147 ||
! ( V_129 . V_138 & V_148 ) )
continue;
V_145 = (struct V_7 * ) V_130 -> V_125 ;
V_132 [ V_59 ] = true ;
if ( F_18 ( V_77 , V_82 , & V_76 , V_145 ,
V_139 , V_57 ) )
continue;
}
}
for ( V_59 = 1 ; V_59 < V_74 . V_136 ; V_59 ++ ) {
if ( V_132 [ V_59 ] )
continue;
if ( F_13 ( V_73 , V_59 , & V_74 , & V_75 , & V_76 , & V_77 ) )
continue;
if ( memcmp ( V_75 , L_3 , 7 ) == 0 ||
memcmp ( V_75 , L_4 , 10 ) == 0 ||
memcmp ( V_75 , L_5 , 11 ) == 0 ||
memcmp ( V_75 , L_6 , 3 ) == 0 ||
memcmp ( V_75 , L_7 , 10 ) == 0 ||
memcmp ( V_75 , L_2 , 6 ) == 0 ||
memcmp ( V_75 , L_37 , 7 ) == 0 ||
memcmp ( V_75 , L_10 , 7 ) == 0 ||
memcmp ( V_75 , L_11 , 6 ) == 0 ) {
V_128 = F_3 ( V_75 , V_77 -> V_125 ,
V_77 -> V_116 ) ;
if ( V_128 != 0 )
goto V_142;
}
}
V_128 = 0 ;
V_142:
F_7 ( V_24 ) ;
return V_128 ;
}
int F_29 ( char * V_127 )
{
return F_25 ( V_127 , NULL ) ;
}
int F_30 ( const char * V_127 , T_2 V_58 )
{
return F_25 ( V_127 , V_58 ) ;
}
void F_31 ( void )
{
int V_149 ;
V_149 = F_5 ( V_49 L_38 , V_50 , 0 ) ;
if ( V_149 < 0 )
return;
while ( 1 ) {
static char V_23 [ 4096 ] ;
T_10 V_150 ;
V_150 = F_6 ( V_149 , V_23 , sizeof( V_23 ) ) ;
if ( V_150 > 0 ) {
V_23 [ V_150 ] = 0 ;
puts ( V_23 ) ;
}
}
}
static int F_32 ( const void * V_151 , const void * V_152 )
{
return ( (struct V_153 * ) V_151 ) -> V_119 - ( (struct V_153 * ) V_152 ) -> V_119 ;
}
int F_33 ( void )
{
T_11 * V_154 = fopen ( L_39 , L_40 ) ;
char V_155 [ 256 ] , V_23 [ 256 ] ;
char V_156 ;
void * V_119 ;
int V_59 = 0 ;
if ( ! V_154 )
return - V_157 ;
while ( ! feof ( V_154 ) ) {
if ( ! fgets ( V_23 , sizeof( V_23 ) , V_154 ) )
break;
if ( sscanf ( V_23 , L_41 , & V_119 , & V_156 , V_155 ) != 3 )
break;
if ( ! V_119 )
continue;
V_158 [ V_59 ] . V_119 = ( long ) V_119 ;
V_158 [ V_59 ] . V_124 = F_24 ( V_155 ) ;
V_59 ++ ;
}
V_159 = V_59 ;
qsort ( V_158 , V_159 , sizeof( struct V_153 ) , F_32 ) ;
return 0 ;
}
struct V_153 * F_34 ( long V_160 )
{
int V_161 = 0 , V_120 = V_159 ;
int V_162 ;
while ( V_161 < V_120 ) {
T_1 V_163 = V_161 + ( V_120 - V_161 ) / 2 ;
V_162 = V_160 - V_158 [ V_163 ] . V_119 ;
if ( V_162 < 0 )
V_120 = V_163 ;
else if ( V_162 > 0 )
V_161 = V_163 + 1 ;
else
return & V_158 [ V_163 ] ;
}
if ( V_161 >= 1 && V_158 [ V_161 - 1 ] . V_119 < V_160 &&
V_160 < V_158 [ V_161 ] . V_119 )
return & V_158 [ V_161 - 1 ] ;
return & V_158 [ 0 ] ;
}
int F_35 ( int V_164 , int V_24 , T_12 V_165 )
{
struct V_166 V_167 ;
int V_168 , V_169 = 0 , V_170 , V_128 = - 1 ;
char V_23 [ 4096 ] ;
struct V_171 * V_172 , * V_173 ;
struct {
struct V_174 V_175 ;
struct V_176 V_177 ;
char V_178 [ 64 ] ;
} V_179 ;
struct V_174 * V_175 ;
struct V_180 * V_4 ;
memset ( & V_167 , 0 , sizeof( V_167 ) ) ;
V_167 . V_181 = V_182 ;
V_168 = F_36 ( V_182 , V_183 , V_184 ) ;
if ( V_168 < 0 ) {
printf ( L_42 , strerror ( V_47 ) ) ;
return - 1 ;
}
if ( F_37 ( V_168 , (struct V_185 * ) & V_167 , sizeof( V_167 ) ) < 0 ) {
printf ( L_43 , strerror ( V_47 ) ) ;
goto V_186;
}
memset ( & V_179 , 0 , sizeof( V_179 ) ) ;
V_179 . V_175 . V_187 = F_38 ( sizeof( struct V_176 ) ) ;
V_179 . V_175 . V_188 = V_189 | V_190 ;
V_179 . V_175 . V_191 = V_192 ;
V_179 . V_175 . V_193 = 0 ;
V_179 . V_175 . V_194 = ++ V_169 ;
V_179 . V_177 . V_195 = V_196 ;
V_179 . V_177 . V_197 = V_164 ;
V_172 = (struct V_171 * ) ( ( ( char * ) & V_179 )
+ F_39 ( V_179 . V_175 . V_187 ) ) ;
V_172 -> V_198 = V_199 | 43 ;
V_172 -> V_200 = V_201 ;
V_173 = (struct V_171 * ) ( ( char * ) V_172 + V_172 -> V_200 ) ;
V_173 -> V_198 = 1 ;
V_173 -> V_200 = V_201 + sizeof( int ) ;
memcpy ( ( char * ) V_173 + V_201 , & V_24 , sizeof( V_24 ) ) ;
V_172 -> V_200 += V_173 -> V_200 ;
if ( V_165 ) {
V_173 = (struct V_171 * ) ( ( char * ) V_172 + V_172 -> V_200 ) ;
V_173 -> V_198 = 3 ;
V_173 -> V_200 = V_201 + sizeof( V_165 ) ;
memcpy ( ( char * ) V_173 + V_201 , & V_165 , sizeof( V_165 ) ) ;
V_172 -> V_200 += V_173 -> V_200 ;
}
V_179 . V_175 . V_187 += F_40 ( V_172 -> V_200 ) ;
if ( F_41 ( V_168 , & V_179 , V_179 . V_175 . V_187 , 0 ) < 0 ) {
printf ( L_44 , strerror ( V_47 ) ) ;
goto V_186;
}
V_170 = F_42 ( V_168 , V_23 , sizeof( V_23 ) , 0 ) ;
if ( V_170 < 0 ) {
printf ( L_45 , strerror ( V_47 ) ) ;
goto V_186;
}
for ( V_175 = (struct V_174 * ) V_23 ; F_43 ( V_175 , V_170 ) ;
V_175 = F_44 ( V_175 , V_170 ) ) {
if ( V_175 -> V_193 != F_45 () ) {
printf ( L_46 ,
V_175 -> V_193 , F_45 () ) ;
goto V_186;
}
if ( V_175 -> V_194 != V_169 ) {
printf ( L_47 ,
V_175 -> V_194 , V_169 ) ;
goto V_186;
}
switch ( V_175 -> V_191 ) {
case V_202 :
V_4 = (struct V_180 * ) F_46 ( V_175 ) ;
if ( ! V_4 -> error )
continue;
printf ( L_48 , strerror ( - V_4 -> error ) ) ;
goto V_186;
case V_203 :
break;
}
}
V_128 = 0 ;
V_186:
F_7 ( V_168 ) ;
return V_128 ;
}
