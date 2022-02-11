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
T_1 V_19 = V_9 / sizeof( struct V_7 ) ;
enum V_20 V_21 ;
char V_22 [ 256 ] ;
int V_23 , V_24 , V_4 , V_25 ;
struct V_26 V_27 = {} ;
V_27 . type = V_28 ;
V_27 . V_29 = V_30 ;
V_27 . V_31 = 1 ;
V_27 . V_32 = 1 ;
if ( V_10 ) {
V_21 = V_33 ;
} else if ( V_11 || V_12 ) {
V_21 = V_34 ;
} else if ( V_13 ) {
V_21 = V_35 ;
} else if ( V_14 ) {
V_21 = V_36 ;
} else if ( V_15 ) {
V_21 = V_37 ;
} else if ( V_16 ) {
V_21 = V_38 ;
} else if ( V_17 ) {
V_21 = V_39 ;
} else if ( V_18 ) {
V_21 = V_40 ;
} else {
printf ( L_11 , V_1 ) ;
return - 1 ;
}
V_23 = F_4 ( V_21 , V_8 , V_19 , V_41 , V_42 ,
V_43 , V_44 ) ;
if ( V_23 < 0 ) {
printf ( L_12 , V_45 , V_43 ) ;
return - 1 ;
}
V_2 [ V_46 ++ ] = V_23 ;
if ( V_14 || V_15 || V_16 || V_17 )
return 0 ;
if ( V_10 || V_18 ) {
if ( V_10 )
V_1 += 6 ;
else
V_1 += 7 ;
if ( * V_1 != '/' )
return 0 ;
V_1 ++ ;
if ( ! isdigit ( * V_1 ) ) {
printf ( L_13 ) ;
return - 1 ;
}
return F_1 ( V_1 , V_23 ) ;
}
if ( V_11 || V_12 ) {
if ( V_11 )
V_1 += 7 ;
else
V_1 += 10 ;
if ( * V_1 == 0 ) {
printf ( L_14 ) ;
return - 1 ;
}
if ( isdigit ( * V_1 ) )
return F_1 ( V_1 , V_23 ) ;
snprintf ( V_22 , sizeof( V_22 ) ,
L_15 ,
V_11 ? 'p' : 'r' , V_1 , V_1 ) ;
V_4 = system ( V_22 ) ;
if ( V_4 < 0 ) {
printf ( L_16 ,
V_1 , strerror ( V_45 ) ) ;
return - 1 ;
}
strcpy ( V_22 , V_47 ) ;
strcat ( V_22 , L_17 ) ;
strcat ( V_22 , V_1 ) ;
strcat ( V_22 , L_18 ) ;
} else if ( V_13 ) {
V_1 += 11 ;
if ( * V_1 == 0 ) {
printf ( L_14 ) ;
return - 1 ;
}
strcpy ( V_22 , V_47 ) ;
strcat ( V_22 , L_19 ) ;
strcat ( V_22 , V_1 ) ;
strcat ( V_22 , L_18 ) ;
}
V_24 = F_5 ( V_22 , V_48 , 0 ) ;
if ( V_24 < 0 ) {
printf ( L_20 , V_1 ) ;
return - 1 ;
}
V_4 = F_6 ( V_24 , V_22 , sizeof( V_22 ) ) ;
if ( V_4 < 0 || V_4 >= sizeof( V_22 ) ) {
printf ( L_21 , V_1 , strerror ( V_45 ) ) ;
return - 1 ;
}
F_7 ( V_24 ) ;
V_22 [ V_4 ] = 0 ;
V_25 = atoi ( V_22 ) ;
V_27 . V_49 = V_25 ;
V_24 = F_8 ( & V_27 , - 1 , 0 , - 1 , 0 ) ;
if ( V_24 < 0 ) {
printf ( L_22 , V_25 , V_24 , strerror ( V_45 ) ) ;
return - 1 ;
}
V_50 [ V_46 - 1 ] = V_24 ;
F_9 ( V_24 , V_51 , 0 ) ;
F_9 ( V_24 , V_52 , V_23 ) ;
return 0 ;
}
static int F_10 ( struct V_53 * V_54 , int V_55 ,
T_2 V_56 )
{
int V_57 ;
for ( V_57 = 0 ; V_57 < V_55 ; V_57 ++ ) {
if ( V_56 ) {
V_56 ( & V_54 [ V_57 ] , V_57 ) ;
if ( V_54 [ V_57 ] . V_23 != - 1 ) {
V_58 [ V_57 ] = V_54 [ V_57 ] . V_23 ;
continue;
}
}
if ( V_54 [ V_57 ] . V_59 . type == V_60 ||
V_54 [ V_57 ] . V_59 . type == V_61 ) {
int V_62 = V_58 [ V_54 [ V_57 ] . V_59 . V_63 ] ;
V_58 [ V_57 ] = F_11 ( V_54 [ V_57 ] . V_59 . type ,
V_54 [ V_57 ] . V_59 . V_64 ,
V_62 ,
V_54 [ V_57 ] . V_59 . V_65 ,
V_54 [ V_57 ] . V_59 . V_66 ) ;
} else {
V_58 [ V_57 ] = F_12 ( V_54 [ V_57 ] . V_59 . type ,
V_54 [ V_57 ] . V_59 . V_64 ,
V_54 [ V_57 ] . V_59 . V_67 ,
V_54 [ V_57 ] . V_59 . V_65 ,
V_54 [ V_57 ] . V_59 . V_66 ) ;
}
if ( V_58 [ V_57 ] < 0 ) {
printf ( L_23 ,
V_45 , strerror ( V_45 ) ) ;
return 1 ;
}
V_54 [ V_57 ] . V_23 = V_58 [ V_57 ] ;
if ( V_54 [ V_57 ] . V_59 . type == V_68 )
V_5 = V_58 [ V_57 ] ;
}
return 0 ;
}
static int F_13 ( T_3 * V_69 , int V_57 , T_4 * V_70 , char * * V_71 ,
T_5 * V_72 , T_6 * * V_73 )
{
T_7 * V_74 ;
V_74 = F_14 ( V_69 , V_57 ) ;
if ( ! V_74 )
return 1 ;
if ( F_15 ( V_74 , V_72 ) != V_72 )
return 2 ;
* V_71 = F_16 ( V_69 , V_70 -> V_75 , V_72 -> V_76 ) ;
if ( ! * V_71 || ! V_72 -> V_77 )
return 3 ;
* V_73 = F_17 ( V_74 , 0 ) ;
if ( ! * V_73 || F_17 ( V_74 , * V_73 ) != NULL )
return 4 ;
return 0 ;
}
static int F_18 ( T_6 * V_73 , T_6 * V_78 ,
T_5 * V_72 , struct V_7 * V_79 ,
struct V_53 * V_54 , int V_55 )
{
int V_57 , V_80 ;
V_80 = V_72 -> V_77 / V_72 -> V_81 ;
for ( V_57 = 0 ; V_57 < V_80 ; V_57 ++ ) {
T_8 V_82 ;
T_9 V_83 ;
unsigned int V_84 ;
bool V_85 = false ;
int V_86 , V_87 ;
F_19 ( V_73 , V_57 , & V_83 ) ;
V_84 = V_83 . V_88 / sizeof( struct V_7 ) ;
F_20 ( V_78 , F_21 ( V_83 . V_89 ) , & V_82 ) ;
if ( V_79 [ V_84 ] . V_90 != ( V_91 | V_92 | V_93 ) ) {
printf ( L_24 ,
V_84 , V_79 [ V_84 ] . V_90 ) ;
return 1 ;
}
V_79 [ V_84 ] . V_94 = V_95 ;
for ( V_87 = 0 ; V_87 < V_55 ; V_87 ++ ) {
if ( V_54 [ V_87 ] . V_96 == V_82 . V_97 ) {
V_85 = true ;
break;
}
}
if ( V_85 ) {
V_79 [ V_84 ] . V_98 = V_54 [ V_87 ] . V_23 ;
} else {
printf ( L_25 ,
V_84 ) ;
return 1 ;
}
}
return 0 ;
}
static int F_22 ( const void * V_99 , const void * V_100 )
{
const T_8 * V_101 = ( const T_8 * ) V_99 ;
const T_8 * V_102 = ( const T_8 * ) V_100 ;
if ( V_101 -> V_97 < V_102 -> V_97 )
return - 1 ;
else if ( V_101 -> V_97 > V_102 -> V_97 )
return 1 ;
else
return 0 ;
}
static int F_23 ( struct V_53 * V_54 , int V_103 ,
T_3 * V_69 , T_6 * V_78 , int V_104 )
{
int V_105 , V_106 ;
bool V_107 = false ;
T_6 * V_108 ;
int V_57 , V_55 ;
T_8 * V_82 ;
T_7 * V_74 ;
int V_109 ;
if ( V_103 < 0 )
return - V_110 ;
if ( ! V_78 )
return - V_110 ;
V_74 = F_14 ( V_69 , V_103 ) ;
if ( V_74 )
V_108 = F_17 ( V_74 , NULL ) ;
if ( ! V_74 || ! V_108 ) {
printf ( L_26 ,
V_103 ) ;
return - V_110 ;
}
V_82 = calloc ( V_111 + 1 , sizeof( T_8 ) ) ;
for ( V_57 = 0 , V_55 = 0 ; V_57 < V_78 -> V_112 / sizeof( T_8 ) ; V_57 ++ ) {
assert ( V_55 < V_111 + 1 ) ;
if ( ! F_20 ( V_78 , V_57 , & V_82 [ V_55 ] ) )
continue;
if ( V_82 [ V_55 ] . V_113 != V_103 )
continue;
V_55 ++ ;
}
qsort ( V_82 , V_55 , sizeof( T_8 ) , F_22 ) ;
V_105 = V_108 -> V_112 / V_55 ;
V_106 = sizeof( struct V_114 ) ;
if ( V_105 < V_106 ) {
V_106 = V_105 ;
} else if ( V_105 > V_106 ) {
V_107 = true ;
}
for ( V_57 = 0 ; V_57 < V_55 ; V_57 ++ ) {
unsigned char * V_115 , * V_116 ;
struct V_114 * V_59 ;
const char * V_117 ;
T_1 V_118 ;
V_117 = F_16 ( V_69 , V_104 , V_82 [ V_57 ] . V_119 ) ;
V_54 [ V_57 ] . V_120 = F_24 ( V_117 ) ;
if ( ! V_54 [ V_57 ] . V_120 ) {
printf ( L_27 , V_117 ,
strerror ( V_45 ) , V_45 ) ;
free ( V_82 ) ;
return - V_45 ;
}
V_118 = V_82 [ V_57 ] . V_97 ;
V_59 = (struct V_114 * ) ( V_108 -> V_121 + V_118 ) ;
V_54 [ V_57 ] . V_96 = V_118 ;
memset ( & V_54 [ V_57 ] . V_59 , 0 , sizeof( struct V_114 ) ) ;
memcpy ( & V_54 [ V_57 ] . V_59 , V_59 , V_106 ) ;
if ( V_107 ) {
V_115 = ( unsigned char * ) V_59 + V_106 ;
V_116 = ( unsigned char * ) V_59 + V_105 ;
for (; V_115 < V_116 ; V_115 ++ ) {
if ( * V_115 != 0 ) {
free ( V_82 ) ;
return - V_122 ;
}
}
}
}
free ( V_82 ) ;
return V_55 ;
}
static int F_25 ( const char * V_123 , T_2 V_56 )
{
int V_23 , V_57 , V_124 , V_103 = - 1 , V_104 = - 1 ;
T_3 * V_69 ;
T_4 V_70 ;
T_5 V_72 , V_125 ;
T_6 * V_73 , * V_126 , * V_108 = NULL , * V_78 = NULL ;
char * V_71 , * V_127 ;
int V_55 = 0 ;
V_42 = 0 ;
memset ( V_41 , 0 , sizeof( V_41 ) ) ;
memset ( V_128 , 0 , sizeof( V_128 ) ) ;
if ( F_26 ( V_129 ) == V_130 )
return 1 ;
V_23 = F_5 ( V_123 , V_48 , 0 ) ;
if ( V_23 < 0 )
return 1 ;
V_69 = F_27 ( V_23 , V_131 , NULL ) ;
if ( ! V_69 )
return 1 ;
if ( F_28 ( V_69 , & V_70 ) != & V_70 )
return 1 ;
V_57 = system ( L_28 ) ;
for ( V_57 = 1 ; V_57 < V_70 . V_132 ; V_57 ++ ) {
if ( F_13 ( V_69 , V_57 , & V_70 , & V_71 , & V_72 , & V_73 ) )
continue;
if ( 0 )
printf ( L_29 ,
V_57 , V_71 , V_73 -> V_121 , V_73 -> V_112 ,
V_72 . V_133 , ( int ) V_72 . V_134 ) ;
if ( strcmp ( V_71 , L_30 ) == 0 ) {
V_128 [ V_57 ] = true ;
memcpy ( V_41 , V_73 -> V_121 , V_73 -> V_112 ) ;
} else if ( strcmp ( V_71 , L_31 ) == 0 ) {
V_128 [ V_57 ] = true ;
if ( V_73 -> V_112 != sizeof( int ) ) {
printf ( L_32 ,
V_73 -> V_112 ) ;
return 1 ;
}
memcpy ( & V_42 , V_73 -> V_121 , sizeof( int ) ) ;
} else if ( strcmp ( V_71 , L_33 ) == 0 ) {
int V_86 ;
V_103 = V_57 ;
V_108 = V_73 ;
for ( V_86 = 0 ; V_86 < V_111 ; V_86 ++ )
V_135 [ V_86 ] . V_23 = - 1 ;
} else if ( V_72 . V_136 == V_137 ) {
V_104 = V_72 . V_133 ;
V_78 = V_73 ;
}
}
V_124 = 1 ;
if ( ! V_78 ) {
printf ( L_34 ) ;
goto V_138;
}
if ( V_108 ) {
V_55 = F_23 ( V_135 , V_103 ,
V_69 , V_78 , V_104 ) ;
if ( V_55 < 0 ) {
printf ( L_35 ,
V_55 , strerror ( - V_55 ) ) ;
V_124 = 1 ;
goto V_138;
}
if ( F_10 ( V_135 , V_55 , V_56 ) )
goto V_138;
V_139 = V_55 ;
V_128 [ V_103 ] = true ;
}
for ( V_57 = 1 ; V_57 < V_70 . V_132 ; V_57 ++ ) {
if ( V_128 [ V_57 ] )
continue;
if ( F_13 ( V_69 , V_57 , & V_70 , & V_71 , & V_72 , & V_73 ) )
continue;
if ( V_72 . V_136 == V_140 ) {
struct V_7 * V_141 ;
if ( F_13 ( V_69 , V_72 . V_142 , & V_70 , & V_127 ,
& V_125 , & V_126 ) )
continue;
if ( V_125 . V_136 != V_143 ||
! ( V_125 . V_134 & V_144 ) )
continue;
V_141 = (struct V_7 * ) V_126 -> V_121 ;
V_128 [ V_57 ] = true ;
if ( F_18 ( V_73 , V_78 , & V_72 , V_141 ,
V_135 , V_55 ) )
continue;
}
}
for ( V_57 = 1 ; V_57 < V_70 . V_132 ; V_57 ++ ) {
if ( V_128 [ V_57 ] )
continue;
if ( F_13 ( V_69 , V_57 , & V_70 , & V_71 , & V_72 , & V_73 ) )
continue;
if ( memcmp ( V_71 , L_3 , 7 ) == 0 ||
memcmp ( V_71 , L_4 , 10 ) == 0 ||
memcmp ( V_71 , L_5 , 11 ) == 0 ||
memcmp ( V_71 , L_6 , 3 ) == 0 ||
memcmp ( V_71 , L_7 , 10 ) == 0 ||
memcmp ( V_71 , L_2 , 6 ) == 0 ||
memcmp ( V_71 , L_36 , 7 ) == 0 ||
memcmp ( V_71 , L_10 , 7 ) == 0 ) {
V_124 = F_3 ( V_71 , V_73 -> V_121 ,
V_73 -> V_112 ) ;
if ( V_124 != 0 )
goto V_138;
}
}
V_124 = 0 ;
V_138:
F_7 ( V_23 ) ;
return V_124 ;
}
int F_29 ( char * V_123 )
{
return F_25 ( V_123 , NULL ) ;
}
int F_30 ( const char * V_123 , T_2 V_56 )
{
return F_25 ( V_123 , V_56 ) ;
}
void F_31 ( void )
{
int V_145 ;
V_145 = F_5 ( V_47 L_37 , V_48 , 0 ) ;
if ( V_145 < 0 )
return;
while ( 1 ) {
static char V_22 [ 4096 ] ;
T_10 V_146 ;
V_146 = F_6 ( V_145 , V_22 , sizeof( V_22 ) ) ;
if ( V_146 > 0 ) {
V_22 [ V_146 ] = 0 ;
puts ( V_22 ) ;
}
}
}
static int F_32 ( const void * V_147 , const void * V_148 )
{
return ( (struct V_149 * ) V_147 ) -> V_115 - ( (struct V_149 * ) V_148 ) -> V_115 ;
}
int F_33 ( void )
{
T_11 * V_150 = fopen ( L_38 , L_39 ) ;
char V_151 [ 256 ] , V_22 [ 256 ] ;
char V_152 ;
void * V_115 ;
int V_57 = 0 ;
if ( ! V_150 )
return - V_153 ;
while ( ! feof ( V_150 ) ) {
if ( ! fgets ( V_22 , sizeof( V_22 ) , V_150 ) )
break;
if ( sscanf ( V_22 , L_40 , & V_115 , & V_152 , V_151 ) != 3 )
break;
if ( ! V_115 )
continue;
V_154 [ V_57 ] . V_115 = ( long ) V_115 ;
V_154 [ V_57 ] . V_120 = F_24 ( V_151 ) ;
V_57 ++ ;
}
V_155 = V_57 ;
qsort ( V_154 , V_155 , sizeof( struct V_149 ) , F_32 ) ;
return 0 ;
}
struct V_149 * F_34 ( long V_156 )
{
int V_157 = 0 , V_116 = V_155 ;
int V_158 ;
while ( V_157 < V_116 ) {
T_1 V_159 = V_157 + ( V_116 - V_157 ) / 2 ;
V_158 = V_156 - V_154 [ V_159 ] . V_115 ;
if ( V_158 < 0 )
V_116 = V_159 ;
else if ( V_158 > 0 )
V_157 = V_159 + 1 ;
else
return & V_154 [ V_159 ] ;
}
if ( V_157 >= 1 && V_154 [ V_157 - 1 ] . V_115 < V_156 &&
V_156 < V_154 [ V_157 ] . V_115 )
return & V_154 [ V_157 - 1 ] ;
return & V_154 [ 0 ] ;
}
int F_35 ( int V_160 , int V_23 , T_12 V_161 )
{
struct V_162 V_163 ;
int V_164 , V_165 = 0 , V_166 , V_124 = - 1 ;
char V_22 [ 4096 ] ;
struct V_167 * V_168 , * V_169 ;
struct {
struct V_170 V_171 ;
struct V_172 V_173 ;
char V_174 [ 64 ] ;
} V_175 ;
struct V_170 * V_171 ;
struct V_176 * V_4 ;
memset ( & V_163 , 0 , sizeof( V_163 ) ) ;
V_163 . V_177 = V_178 ;
V_164 = F_36 ( V_178 , V_179 , V_180 ) ;
if ( V_164 < 0 ) {
printf ( L_41 , strerror ( V_45 ) ) ;
return - 1 ;
}
if ( F_37 ( V_164 , (struct V_181 * ) & V_163 , sizeof( V_163 ) ) < 0 ) {
printf ( L_42 , strerror ( V_45 ) ) ;
goto V_182;
}
memset ( & V_175 , 0 , sizeof( V_175 ) ) ;
V_175 . V_171 . V_183 = F_38 ( sizeof( struct V_172 ) ) ;
V_175 . V_171 . V_184 = V_185 | V_186 ;
V_175 . V_171 . V_187 = V_188 ;
V_175 . V_171 . V_189 = 0 ;
V_175 . V_171 . V_190 = ++ V_165 ;
V_175 . V_173 . V_191 = V_192 ;
V_175 . V_173 . V_193 = V_160 ;
V_168 = (struct V_167 * ) ( ( ( char * ) & V_175 )
+ F_39 ( V_175 . V_171 . V_183 ) ) ;
V_168 -> V_194 = V_195 | 43 ;
V_168 -> V_196 = V_197 ;
V_169 = (struct V_167 * ) ( ( char * ) V_168 + V_168 -> V_196 ) ;
V_169 -> V_194 = 1 ;
V_169 -> V_196 = V_197 + sizeof( int ) ;
memcpy ( ( char * ) V_169 + V_197 , & V_23 , sizeof( V_23 ) ) ;
V_168 -> V_196 += V_169 -> V_196 ;
if ( V_161 ) {
V_169 = (struct V_167 * ) ( ( char * ) V_168 + V_168 -> V_196 ) ;
V_169 -> V_194 = 3 ;
V_169 -> V_196 = V_197 + sizeof( V_161 ) ;
memcpy ( ( char * ) V_169 + V_197 , & V_161 , sizeof( V_161 ) ) ;
V_168 -> V_196 += V_169 -> V_196 ;
}
V_175 . V_171 . V_183 += F_40 ( V_168 -> V_196 ) ;
if ( F_41 ( V_164 , & V_175 , V_175 . V_171 . V_183 , 0 ) < 0 ) {
printf ( L_43 , strerror ( V_45 ) ) ;
goto V_182;
}
V_166 = F_42 ( V_164 , V_22 , sizeof( V_22 ) , 0 ) ;
if ( V_166 < 0 ) {
printf ( L_44 , strerror ( V_45 ) ) ;
goto V_182;
}
for ( V_171 = (struct V_170 * ) V_22 ; F_43 ( V_171 , V_166 ) ;
V_171 = F_44 ( V_171 , V_166 ) ) {
if ( V_171 -> V_189 != F_45 () ) {
printf ( L_45 ,
V_171 -> V_189 , F_45 () ) ;
goto V_182;
}
if ( V_171 -> V_190 != V_165 ) {
printf ( L_46 ,
V_171 -> V_190 , V_165 ) ;
goto V_182;
}
switch ( V_171 -> V_187 ) {
case V_198 :
V_4 = (struct V_176 * ) F_46 ( V_171 ) ;
if ( ! V_4 -> error )
continue;
printf ( L_47 , strerror ( - V_4 -> error ) ) ;
goto V_182;
case V_199 :
break;
}
}
V_124 = 0 ;
V_182:
F_7 ( V_164 ) ;
return V_124 ;
}
