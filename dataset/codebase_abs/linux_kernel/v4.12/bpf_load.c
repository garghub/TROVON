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
T_1 V_18 = V_9 / sizeof( struct V_7 ) ;
enum V_19 V_20 ;
char V_21 [ 256 ] ;
int V_22 , V_23 , V_4 , V_24 ;
struct V_25 V_26 = {} ;
V_26 . type = V_27 ;
V_26 . V_28 = V_29 ;
V_26 . V_30 = 1 ;
V_26 . V_31 = 1 ;
if ( V_10 ) {
V_20 = V_32 ;
} else if ( V_11 || V_12 ) {
V_20 = V_33 ;
} else if ( V_13 ) {
V_20 = V_34 ;
} else if ( V_14 ) {
V_20 = V_35 ;
} else if ( V_15 ) {
V_20 = V_36 ;
} else if ( V_16 ) {
V_20 = V_37 ;
} else if ( V_17 ) {
V_20 = V_38 ;
} else {
printf ( L_10 , V_1 ) ;
return - 1 ;
}
V_22 = F_4 ( V_20 , V_8 , V_18 , V_39 , V_40 ,
V_41 , V_42 ) ;
if ( V_22 < 0 ) {
printf ( L_11 , V_43 , V_41 ) ;
return - 1 ;
}
V_2 [ V_44 ++ ] = V_22 ;
if ( V_14 || V_15 || V_16 || V_17 )
return 0 ;
if ( V_10 ) {
V_1 += 6 ;
if ( * V_1 != '/' )
return 0 ;
V_1 ++ ;
if ( ! isdigit ( * V_1 ) ) {
printf ( L_12 ) ;
return - 1 ;
}
return F_1 ( V_1 , V_22 ) ;
}
if ( V_11 || V_12 ) {
if ( V_11 )
V_1 += 7 ;
else
V_1 += 10 ;
if ( * V_1 == 0 ) {
printf ( L_13 ) ;
return - 1 ;
}
if ( isdigit ( * V_1 ) )
return F_1 ( V_1 , V_22 ) ;
snprintf ( V_21 , sizeof( V_21 ) ,
L_14 ,
V_11 ? 'p' : 'r' , V_1 , V_1 ) ;
V_4 = system ( V_21 ) ;
if ( V_4 < 0 ) {
printf ( L_15 ,
V_1 , strerror ( V_43 ) ) ;
return - 1 ;
}
strcpy ( V_21 , V_45 ) ;
strcat ( V_21 , L_16 ) ;
strcat ( V_21 , V_1 ) ;
strcat ( V_21 , L_17 ) ;
} else if ( V_13 ) {
V_1 += 11 ;
if ( * V_1 == 0 ) {
printf ( L_13 ) ;
return - 1 ;
}
strcpy ( V_21 , V_45 ) ;
strcat ( V_21 , L_18 ) ;
strcat ( V_21 , V_1 ) ;
strcat ( V_21 , L_17 ) ;
}
V_23 = F_5 ( V_21 , V_46 , 0 ) ;
if ( V_23 < 0 ) {
printf ( L_19 , V_1 ) ;
return - 1 ;
}
V_4 = F_6 ( V_23 , V_21 , sizeof( V_21 ) ) ;
if ( V_4 < 0 || V_4 >= sizeof( V_21 ) ) {
printf ( L_20 , V_1 , strerror ( V_43 ) ) ;
return - 1 ;
}
F_7 ( V_23 ) ;
V_21 [ V_4 ] = 0 ;
V_24 = atoi ( V_21 ) ;
V_26 . V_47 = V_24 ;
V_23 = F_8 ( & V_26 , - 1 , 0 , - 1 , 0 ) ;
if ( V_23 < 0 ) {
printf ( L_21 , V_24 , V_23 , strerror ( V_43 ) ) ;
return - 1 ;
}
V_48 [ V_44 - 1 ] = V_23 ;
F_9 ( V_23 , V_49 , 0 ) ;
F_9 ( V_23 , V_50 , V_22 ) ;
return 0 ;
}
static int F_10 ( struct V_51 * V_52 , int V_53 ,
T_2 V_54 )
{
int V_55 ;
for ( V_55 = 0 ; V_55 < V_53 ; V_55 ++ ) {
if ( V_54 ) {
V_54 ( & V_52 [ V_55 ] , V_55 ) ;
if ( V_52 [ V_55 ] . V_22 != - 1 ) {
V_56 [ V_55 ] = V_52 [ V_55 ] . V_22 ;
continue;
}
}
if ( V_52 [ V_55 ] . V_57 . type == V_58 ||
V_52 [ V_55 ] . V_57 . type == V_59 ) {
int V_60 = V_56 [ V_52 [ V_55 ] . V_57 . V_61 ] ;
V_56 [ V_55 ] = F_11 ( V_52 [ V_55 ] . V_57 . type ,
V_52 [ V_55 ] . V_57 . V_62 ,
V_60 ,
V_52 [ V_55 ] . V_57 . V_63 ,
V_52 [ V_55 ] . V_57 . V_64 ) ;
} else {
V_56 [ V_55 ] = F_12 ( V_52 [ V_55 ] . V_57 . type ,
V_52 [ V_55 ] . V_57 . V_62 ,
V_52 [ V_55 ] . V_57 . V_65 ,
V_52 [ V_55 ] . V_57 . V_63 ,
V_52 [ V_55 ] . V_57 . V_64 ) ;
}
if ( V_56 [ V_55 ] < 0 ) {
printf ( L_22 ,
V_43 , strerror ( V_43 ) ) ;
return 1 ;
}
V_52 [ V_55 ] . V_22 = V_56 [ V_55 ] ;
if ( V_52 [ V_55 ] . V_57 . type == V_66 )
V_5 = V_56 [ V_55 ] ;
}
return 0 ;
}
static int F_13 ( T_3 * V_67 , int V_55 , T_4 * V_68 , char * * V_69 ,
T_5 * V_70 , T_6 * * V_71 )
{
T_7 * V_72 ;
V_72 = F_14 ( V_67 , V_55 ) ;
if ( ! V_72 )
return 1 ;
if ( F_15 ( V_72 , V_70 ) != V_70 )
return 2 ;
* V_69 = F_16 ( V_67 , V_68 -> V_73 , V_70 -> V_74 ) ;
if ( ! * V_69 || ! V_70 -> V_75 )
return 3 ;
* V_71 = F_17 ( V_72 , 0 ) ;
if ( ! * V_71 || F_17 ( V_72 , * V_71 ) != NULL )
return 4 ;
return 0 ;
}
static int F_18 ( T_6 * V_71 , T_6 * V_76 ,
T_5 * V_70 , struct V_7 * V_77 ,
struct V_51 * V_52 , int V_53 )
{
int V_55 , V_78 ;
V_78 = V_70 -> V_75 / V_70 -> V_79 ;
for ( V_55 = 0 ; V_55 < V_78 ; V_55 ++ ) {
T_8 V_80 ;
T_9 V_81 ;
unsigned int V_82 ;
bool V_83 = false ;
int V_84 , V_85 ;
F_19 ( V_71 , V_55 , & V_81 ) ;
V_82 = V_81 . V_86 / sizeof( struct V_7 ) ;
F_20 ( V_76 , F_21 ( V_81 . V_87 ) , & V_80 ) ;
if ( V_77 [ V_82 ] . V_88 != ( V_89 | V_90 | V_91 ) ) {
printf ( L_23 ,
V_82 , V_77 [ V_82 ] . V_88 ) ;
return 1 ;
}
V_77 [ V_82 ] . V_92 = V_93 ;
for ( V_85 = 0 ; V_85 < V_53 ; V_85 ++ ) {
if ( V_52 [ V_85 ] . V_94 == V_80 . V_95 ) {
V_83 = true ;
break;
}
}
if ( V_83 ) {
V_77 [ V_82 ] . V_96 = V_52 [ V_85 ] . V_22 ;
} else {
printf ( L_24 ,
V_82 ) ;
return 1 ;
}
}
return 0 ;
}
static int F_22 ( const void * V_97 , const void * V_98 )
{
const T_8 * V_99 = ( const T_8 * ) V_97 ;
const T_8 * V_100 = ( const T_8 * ) V_98 ;
if ( V_99 -> V_95 < V_100 -> V_95 )
return - 1 ;
else if ( V_99 -> V_95 > V_100 -> V_95 )
return 1 ;
else
return 0 ;
}
static int F_23 ( struct V_51 * V_52 , int V_101 ,
T_3 * V_67 , T_6 * V_76 , int V_102 )
{
int V_103 , V_104 ;
bool V_105 = false ;
T_6 * V_106 ;
int V_55 , V_53 ;
T_8 * V_80 ;
T_7 * V_72 ;
int V_107 ;
if ( V_101 < 0 )
return - V_108 ;
if ( ! V_76 )
return - V_108 ;
V_72 = F_14 ( V_67 , V_101 ) ;
if ( V_72 )
V_106 = F_17 ( V_72 , NULL ) ;
if ( ! V_72 || ! V_106 ) {
printf ( L_25 ,
V_101 ) ;
return - V_108 ;
}
V_80 = calloc ( V_109 + 1 , sizeof( T_8 ) ) ;
for ( V_55 = 0 , V_53 = 0 ; V_55 < V_76 -> V_110 / sizeof( T_8 ) ; V_55 ++ ) {
assert ( V_53 < V_109 + 1 ) ;
if ( ! F_20 ( V_76 , V_55 , & V_80 [ V_53 ] ) )
continue;
if ( V_80 [ V_53 ] . V_111 != V_101 )
continue;
V_53 ++ ;
}
qsort ( V_80 , V_53 , sizeof( T_8 ) , F_22 ) ;
V_103 = V_106 -> V_110 / V_53 ;
V_104 = sizeof( struct V_112 ) ;
if ( V_103 < V_104 ) {
V_104 = V_103 ;
} else if ( V_103 > V_104 ) {
V_105 = true ;
}
for ( V_55 = 0 ; V_55 < V_53 ; V_55 ++ ) {
unsigned char * V_113 , * V_114 ;
struct V_112 * V_57 ;
const char * V_115 ;
T_1 V_116 ;
V_115 = F_16 ( V_67 , V_102 , V_80 [ V_55 ] . V_117 ) ;
V_52 [ V_55 ] . V_118 = F_24 ( V_115 ) ;
if ( ! V_52 [ V_55 ] . V_118 ) {
printf ( L_26 , V_115 ,
strerror ( V_43 ) , V_43 ) ;
free ( V_80 ) ;
return - V_43 ;
}
V_116 = V_80 [ V_55 ] . V_95 ;
V_57 = (struct V_112 * ) ( V_106 -> V_119 + V_116 ) ;
V_52 [ V_55 ] . V_94 = V_116 ;
memset ( & V_52 [ V_55 ] . V_57 , 0 , sizeof( struct V_112 ) ) ;
memcpy ( & V_52 [ V_55 ] . V_57 , V_57 , V_104 ) ;
if ( V_105 ) {
V_113 = ( unsigned char * ) V_57 + V_104 ;
V_114 = ( unsigned char * ) V_57 + V_103 ;
for (; V_113 < V_114 ; V_113 ++ ) {
if ( * V_113 != 0 ) {
free ( V_80 ) ;
return - V_120 ;
}
}
}
}
free ( V_80 ) ;
return V_53 ;
}
static int F_25 ( const char * V_121 , T_2 V_54 )
{
int V_22 , V_55 , V_122 , V_101 = - 1 , V_102 = - 1 ;
T_3 * V_67 ;
T_4 V_68 ;
T_5 V_70 , V_123 ;
T_6 * V_71 , * V_124 , * V_106 = NULL , * V_76 = NULL ;
char * V_69 , * V_125 ;
int V_53 = 0 ;
V_40 = 0 ;
memset ( V_39 , 0 , sizeof( V_39 ) ) ;
memset ( V_126 , 0 , sizeof( V_126 ) ) ;
if ( F_26 ( V_127 ) == V_128 )
return 1 ;
V_22 = F_5 ( V_121 , V_46 , 0 ) ;
if ( V_22 < 0 )
return 1 ;
V_67 = F_27 ( V_22 , V_129 , NULL ) ;
if ( ! V_67 )
return 1 ;
if ( F_28 ( V_67 , & V_68 ) != & V_68 )
return 1 ;
V_55 = system ( L_27 ) ;
for ( V_55 = 1 ; V_55 < V_68 . V_130 ; V_55 ++ ) {
if ( F_13 ( V_67 , V_55 , & V_68 , & V_69 , & V_70 , & V_71 ) )
continue;
if ( 0 )
printf ( L_28 ,
V_55 , V_69 , V_71 -> V_119 , V_71 -> V_110 ,
V_70 . V_131 , ( int ) V_70 . V_132 ) ;
if ( strcmp ( V_69 , L_29 ) == 0 ) {
V_126 [ V_55 ] = true ;
memcpy ( V_39 , V_71 -> V_119 , V_71 -> V_110 ) ;
} else if ( strcmp ( V_69 , L_30 ) == 0 ) {
V_126 [ V_55 ] = true ;
if ( V_71 -> V_110 != sizeof( int ) ) {
printf ( L_31 ,
V_71 -> V_110 ) ;
return 1 ;
}
memcpy ( & V_40 , V_71 -> V_119 , sizeof( int ) ) ;
} else if ( strcmp ( V_69 , L_32 ) == 0 ) {
int V_84 ;
V_101 = V_55 ;
V_106 = V_71 ;
for ( V_84 = 0 ; V_84 < V_109 ; V_84 ++ )
V_133 [ V_84 ] . V_22 = - 1 ;
} else if ( V_70 . V_134 == V_135 ) {
V_102 = V_70 . V_131 ;
V_76 = V_71 ;
}
}
V_122 = 1 ;
if ( ! V_76 ) {
printf ( L_33 ) ;
goto V_136;
}
if ( V_106 ) {
V_53 = F_23 ( V_133 , V_101 ,
V_67 , V_76 , V_102 ) ;
if ( V_53 < 0 ) {
printf ( L_34 ,
V_53 , strerror ( - V_53 ) ) ;
V_122 = 1 ;
goto V_136;
}
if ( F_10 ( V_133 , V_53 , V_54 ) )
goto V_136;
V_137 = V_53 ;
V_126 [ V_101 ] = true ;
}
for ( V_55 = 1 ; V_55 < V_68 . V_130 ; V_55 ++ ) {
if ( V_126 [ V_55 ] )
continue;
if ( F_13 ( V_67 , V_55 , & V_68 , & V_69 , & V_70 , & V_71 ) )
continue;
if ( V_70 . V_134 == V_138 ) {
struct V_7 * V_139 ;
if ( F_13 ( V_67 , V_70 . V_140 , & V_68 , & V_125 ,
& V_123 , & V_124 ) )
continue;
if ( V_123 . V_134 != V_141 ||
! ( V_123 . V_132 & V_142 ) )
continue;
V_139 = (struct V_7 * ) V_124 -> V_119 ;
V_126 [ V_70 . V_140 ] = true ;
V_126 [ V_55 ] = true ;
if ( F_18 ( V_71 , V_76 , & V_70 , V_139 ,
V_133 , V_53 ) )
continue;
if ( memcmp ( V_125 , L_3 , 7 ) == 0 ||
memcmp ( V_125 , L_4 , 10 ) == 0 ||
memcmp ( V_125 , L_5 , 11 ) == 0 ||
memcmp ( V_125 , L_6 , 3 ) == 0 ||
memcmp ( V_125 , L_7 , 10 ) == 0 ||
memcmp ( V_125 , L_2 , 6 ) == 0 ||
memcmp ( V_125 , L_35 , 7 ) == 0 )
F_3 ( V_125 , V_139 , V_124 -> V_110 ) ;
}
}
for ( V_55 = 1 ; V_55 < V_68 . V_130 ; V_55 ++ ) {
if ( V_126 [ V_55 ] )
continue;
if ( F_13 ( V_67 , V_55 , & V_68 , & V_69 , & V_70 , & V_71 ) )
continue;
if ( memcmp ( V_69 , L_3 , 7 ) == 0 ||
memcmp ( V_69 , L_4 , 10 ) == 0 ||
memcmp ( V_69 , L_5 , 11 ) == 0 ||
memcmp ( V_69 , L_6 , 3 ) == 0 ||
memcmp ( V_69 , L_7 , 10 ) == 0 ||
memcmp ( V_69 , L_2 , 6 ) == 0 ||
memcmp ( V_69 , L_35 , 7 ) == 0 )
F_3 ( V_69 , V_71 -> V_119 , V_71 -> V_110 ) ;
}
V_122 = 0 ;
V_136:
F_7 ( V_22 ) ;
return V_122 ;
}
int F_29 ( char * V_121 )
{
return F_25 ( V_121 , NULL ) ;
}
int F_30 ( const char * V_121 , T_2 V_54 )
{
return F_25 ( V_121 , V_54 ) ;
}
void F_31 ( void )
{
int V_143 ;
V_143 = F_5 ( V_45 L_36 , V_46 , 0 ) ;
if ( V_143 < 0 )
return;
while ( 1 ) {
static char V_21 [ 4096 ] ;
T_10 V_144 ;
V_144 = F_6 ( V_143 , V_21 , sizeof( V_21 ) ) ;
if ( V_144 > 0 ) {
V_21 [ V_144 ] = 0 ;
puts ( V_21 ) ;
}
}
}
static int F_32 ( const void * V_145 , const void * V_146 )
{
return ( (struct V_147 * ) V_145 ) -> V_113 - ( (struct V_147 * ) V_146 ) -> V_113 ;
}
int F_33 ( void )
{
T_11 * V_148 = fopen ( L_37 , L_38 ) ;
char V_149 [ 256 ] , V_21 [ 256 ] ;
char V_150 ;
void * V_113 ;
int V_55 = 0 ;
if ( ! V_148 )
return - V_151 ;
while ( ! feof ( V_148 ) ) {
if ( ! fgets ( V_21 , sizeof( V_21 ) , V_148 ) )
break;
if ( sscanf ( V_21 , L_39 , & V_113 , & V_150 , V_149 ) != 3 )
break;
if ( ! V_113 )
continue;
V_152 [ V_55 ] . V_113 = ( long ) V_113 ;
V_152 [ V_55 ] . V_118 = F_24 ( V_149 ) ;
V_55 ++ ;
}
V_153 = V_55 ;
qsort ( V_152 , V_153 , sizeof( struct V_147 ) , F_32 ) ;
return 0 ;
}
struct V_147 * F_34 ( long V_154 )
{
int V_155 = 0 , V_114 = V_153 ;
int V_156 ;
while ( V_155 < V_114 ) {
T_1 V_157 = V_155 + ( V_114 - V_155 ) / 2 ;
V_156 = V_154 - V_152 [ V_157 ] . V_113 ;
if ( V_156 < 0 )
V_114 = V_157 ;
else if ( V_156 > 0 )
V_155 = V_157 + 1 ;
else
return & V_152 [ V_157 ] ;
}
if ( V_155 >= 1 && V_152 [ V_155 - 1 ] . V_113 < V_154 &&
V_154 < V_152 [ V_155 ] . V_113 )
return & V_152 [ V_155 - 1 ] ;
return & V_152 [ 0 ] ;
}
int F_35 ( int V_158 , int V_22 , T_12 V_159 )
{
struct V_160 V_161 ;
int V_162 , V_163 = 0 , V_164 , V_122 = - 1 ;
char V_21 [ 4096 ] ;
struct V_165 * V_166 , * V_167 ;
struct {
struct V_168 V_169 ;
struct V_170 V_171 ;
char V_172 [ 64 ] ;
} V_173 ;
struct V_168 * V_169 ;
struct V_174 * V_4 ;
memset ( & V_161 , 0 , sizeof( V_161 ) ) ;
V_161 . V_175 = V_176 ;
V_162 = F_36 ( V_176 , V_177 , V_178 ) ;
if ( V_162 < 0 ) {
printf ( L_40 , strerror ( V_43 ) ) ;
return - 1 ;
}
if ( F_37 ( V_162 , (struct V_179 * ) & V_161 , sizeof( V_161 ) ) < 0 ) {
printf ( L_41 , strerror ( V_43 ) ) ;
goto V_180;
}
memset ( & V_173 , 0 , sizeof( V_173 ) ) ;
V_173 . V_169 . V_181 = F_38 ( sizeof( struct V_170 ) ) ;
V_173 . V_169 . V_182 = V_183 | V_184 ;
V_173 . V_169 . V_185 = V_186 ;
V_173 . V_169 . V_187 = 0 ;
V_173 . V_169 . V_188 = ++ V_163 ;
V_173 . V_171 . V_189 = V_190 ;
V_173 . V_171 . V_191 = V_158 ;
V_166 = (struct V_165 * ) ( ( ( char * ) & V_173 )
+ F_39 ( V_173 . V_169 . V_181 ) ) ;
V_166 -> V_192 = V_193 | 43 ;
V_166 -> V_194 = V_195 ;
V_167 = (struct V_165 * ) ( ( char * ) V_166 + V_166 -> V_194 ) ;
V_167 -> V_192 = 1 ;
V_167 -> V_194 = V_195 + sizeof( int ) ;
memcpy ( ( char * ) V_167 + V_195 , & V_22 , sizeof( V_22 ) ) ;
V_166 -> V_194 += V_167 -> V_194 ;
if ( V_159 ) {
V_167 = (struct V_165 * ) ( ( char * ) V_166 + V_166 -> V_194 ) ;
V_167 -> V_192 = 3 ;
V_167 -> V_194 = V_195 + sizeof( V_159 ) ;
memcpy ( ( char * ) V_167 + V_195 , & V_159 , sizeof( V_159 ) ) ;
V_166 -> V_194 += V_167 -> V_194 ;
}
V_173 . V_169 . V_181 += F_40 ( V_166 -> V_194 ) ;
if ( F_41 ( V_162 , & V_173 , V_173 . V_169 . V_181 , 0 ) < 0 ) {
printf ( L_42 , strerror ( V_43 ) ) ;
goto V_180;
}
V_164 = F_42 ( V_162 , V_21 , sizeof( V_21 ) , 0 ) ;
if ( V_164 < 0 ) {
printf ( L_43 , strerror ( V_43 ) ) ;
goto V_180;
}
for ( V_169 = (struct V_168 * ) V_21 ; F_43 ( V_169 , V_164 ) ;
V_169 = F_44 ( V_169 , V_164 ) ) {
if ( V_169 -> V_187 != F_45 () ) {
printf ( L_44 ,
V_169 -> V_187 , F_45 () ) ;
goto V_180;
}
if ( V_169 -> V_188 != V_163 ) {
printf ( L_45 ,
V_169 -> V_188 , V_163 ) ;
goto V_180;
}
switch ( V_169 -> V_185 ) {
case V_196 :
V_4 = (struct V_174 * ) F_46 ( V_169 ) ;
if ( ! V_4 -> error )
continue;
printf ( L_46 , strerror ( - V_4 -> error ) ) ;
goto V_180;
case V_197 :
break;
}
}
V_122 = 0 ;
V_180:
F_7 ( V_162 ) ;
return V_122 ;
}
