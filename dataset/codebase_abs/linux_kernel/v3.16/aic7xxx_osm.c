void
F_1 ( struct V_1 * V_2 , struct V_3 * V_3 )
{
F_2 ( L_1 ,
V_2 -> V_4 -> V_5 -> V_6 ,
V_3 != NULL ? F_3 ( V_2 , V_3 ) : 'X' ,
V_3 != NULL ? F_4 ( V_2 , V_3 ) : - 1 ,
V_3 != NULL ? F_5 ( V_3 ) : - 1 ) ;
}
void
F_6 ( long V_7 )
{
while ( V_7 > 0 ) {
F_7 ( V_7 % 1024 ) ;
V_7 -= 1024 ;
}
}
T_1
F_8 ( struct V_1 * V_2 , long V_8 )
{
T_1 V_9 ;
if ( V_2 -> V_10 == V_11 ) {
V_9 = F_9 ( V_2 -> V_12 . V_13 + V_8 ) ;
} else {
V_9 = F_10 ( V_2 -> V_12 . V_14 + V_8 ) ;
}
F_11 () ;
return ( V_9 ) ;
}
void
F_12 ( struct V_1 * V_2 , long V_8 , T_1 V_15 )
{
if ( V_2 -> V_10 == V_11 ) {
F_13 ( V_15 , V_2 -> V_12 . V_13 + V_8 ) ;
} else {
F_14 ( V_15 , V_2 -> V_12 . V_14 + V_8 ) ;
}
F_11 () ;
}
void
F_15 ( struct V_1 * V_2 , long V_8 , T_1 * V_16 , int V_17 )
{
int V_18 ;
for ( V_18 = 0 ; V_18 < V_17 ; V_18 ++ )
F_12 ( V_2 , V_8 , * V_16 ++ ) ;
}
void
F_16 ( struct V_1 * V_2 , long V_8 , T_1 * V_16 , int V_17 )
{
int V_18 ;
for ( V_18 = 0 ; V_18 < V_17 ; V_18 ++ )
* V_16 ++ = F_8 ( V_2 , V_8 ) ;
}
static void
F_17 ( struct V_1 * V_2 , struct V_3 * V_3 )
{
struct V_19 * V_20 ;
V_20 = V_3 -> V_21 ;
F_18 ( V_2 , V_3 , V_22 ) ;
F_19 ( V_20 ) ;
}
static int
F_20 ( struct V_1 * V_2 , struct V_3 * V_3 ,
struct V_23 * V_24 , T_2 V_25 , T_3 V_26 )
{
int V_27 ;
if ( ( V_3 -> V_28 + 1 ) > V_29 )
F_21 ( L_2
L_3 ) ;
V_27 = 1 ;
V_24 -> V_25 = F_22 ( V_25 & 0xFFFFFFFF ) ;
V_3 -> V_4 -> V_30 += V_26 ;
if ( sizeof( T_2 ) > 4
&& ( V_2 -> V_31 & V_32 ) != 0 )
V_26 |= ( V_25 >> 8 ) & V_33 ;
V_24 -> V_26 = F_22 ( V_26 ) ;
return ( V_27 ) ;
}
static const char *
F_23 ( struct V_34 * V_5 )
{
static char V_35 [ 512 ] ;
char V_36 [ 256 ] ;
char * V_37 ;
struct V_1 * V_2 ;
V_37 = & V_35 [ 0 ] ;
V_2 = * (struct V_1 * * ) V_5 -> V_38 ;
memset ( V_37 , 0 , sizeof( V_35 ) ) ;
strcpy ( V_37 , L_4 V_39 L_5
L_6 ) ;
strcat ( V_37 , V_2 -> V_40 ) ;
strcat ( V_37 , L_7
L_8 ) ;
F_24 ( V_2 , V_36 ) ;
strcat ( V_37 , V_36 ) ;
strcat ( V_37 , L_5 ) ;
return ( V_37 ) ;
}
static int
F_25 ( struct V_19 * V_20 , void (* F_26) ( struct V_19 * ) )
{
struct V_1 * V_2 ;
struct V_41 * V_42 = F_27 ( V_20 -> V_43 ) ;
int V_44 = V_45 ;
unsigned long V_31 ;
V_2 = * (struct V_1 * * ) V_20 -> V_43 -> V_5 -> V_38 ;
F_28 ( V_2 , & V_31 ) ;
if ( V_2 -> V_4 -> V_46 == 0 ) {
V_20 -> F_26 = F_26 ;
V_20 -> V_47 = V_48 << 16 ;
V_44 = F_29 ( V_2 , V_42 , V_20 ) ;
}
F_30 ( V_2 , & V_31 ) ;
return V_44 ;
}
int
F_31 ( struct V_49 * V_50 )
{
struct V_1 * V_2 =
* ( (struct V_1 * * ) F_32 ( & V_50 -> V_42 ) -> V_38 ) ;
struct V_51 * V_52 = V_2 -> V_53 ;
unsigned long V_31 ;
struct V_49 * * V_54 = F_33 ( V_50 ) ;
unsigned short V_55 ;
struct V_56 V_57 ;
struct V_58 * V_59 ;
struct V_60 * V_61 ;
char V_62 = V_50 -> V_62 + 'A' ;
unsigned int V_63 = V_2 -> V_63 ;
unsigned int V_64 ;
V_64 = V_50 -> V_65 ;
if ( V_50 -> V_62 != 0 )
V_64 += 8 ;
if ( V_50 -> V_62 )
V_63 = V_2 -> V_66 ;
F_28 ( V_2 , & V_31 ) ;
F_34 ( * V_54 != NULL ) ;
* V_54 = V_50 ;
if ( V_52 ) {
int V_67 = V_68 ;
int V_69 = 0 ;
int V_31 = V_52 -> V_70 [ V_64 ] ;
if ( V_2 -> V_31 & V_71 ) {
if ( V_31 & V_72 )
V_69 = 1 ;
} else if ( V_31 & V_73 )
V_69 = 1 ;
if( V_69 && ( V_31 & V_74 ) == 0x04 ) {
V_69 = 0 ;
V_31 &= ~ V_74 ;
}
if ( ( V_2 -> V_75 & V_76 ) != 0 ) {
V_55 = ( V_31 & V_74 ) | ( V_69 ? 0x8 : 0 ) ;
} else {
V_55 = ( V_31 & V_74 ) << 4 ;
V_67 = V_69 ? V_77 :
V_78 ;
}
F_35 ( V_50 ) = ( V_31 & V_79 ) ? 1 : 0 ;
if ( ! ( V_31 & V_80 ) )
F_36 ( V_50 ) = 0 ;
F_37 ( V_50 ) =
F_38 ( V_2 , V_55 , V_67 ) ;
V_59 = F_39 ( V_2 , V_62 , V_2 -> V_63 ,
V_50 -> V_65 , & V_61 ) ;
}
F_40 ( & V_57 , V_63 , V_50 -> V_65 ,
V_81 , V_62 ,
V_82 ) ;
F_41 ( V_2 , & V_57 , NULL , 0 , 0 , 0 ,
V_83 , FALSE ) ;
F_42 ( V_2 , & V_57 , V_84 ,
V_83 , FALSE ) ;
F_30 ( V_2 , & V_31 ) ;
return 0 ;
}
static void
F_43 ( struct V_49 * V_50 )
{
struct V_49 * * V_54 = F_33 ( V_50 ) ;
* V_54 = NULL ;
}
static int
F_44 ( struct V_85 * V_86 )
{
struct V_1 * V_2 =
* ( (struct V_1 * * ) V_86 -> V_5 -> V_38 ) ;
struct V_49 * V_50 = V_86 -> V_87 ;
struct V_41 * V_42 ;
if ( V_88 )
F_2 ( L_9 , F_45 ( V_2 ) , V_86 -> V_65 ) ;
V_42 = F_27 ( V_86 ) ;
memset ( V_42 , 0 , sizeof( * V_42 ) ) ;
V_42 -> V_89 = 1 ;
V_42 -> V_90 = 0 ;
F_46 ( V_50 ) = 0 ;
return 0 ;
}
static int
F_47 ( struct V_85 * V_86 )
{
struct V_1 * V_2 ;
V_2 = * ( (struct V_1 * * ) V_86 -> V_5 -> V_38 ) ;
if ( V_88 )
F_48 ( V_91 , V_86 , L_10 ) ;
F_49 ( V_86 ) ;
if ( ! F_50 ( V_86 -> V_87 ) )
F_51 ( V_86 ) ;
return 0 ;
}
static int
F_52 ( struct V_85 * V_86 , struct V_92 * V_93 ,
T_4 V_94 , int V_95 [] )
{
T_1 * V_96 ;
int V_97 ;
int V_98 ;
int V_99 ;
int V_100 ;
int V_101 ;
struct V_1 * V_2 ;
T_5 V_62 ;
V_2 = * ( (struct V_1 * * ) V_86 -> V_5 -> V_38 ) ;
V_62 = F_53 ( V_86 ) ;
V_96 = F_54 ( V_93 ) ;
if ( V_96 ) {
V_100 = F_55 ( V_96 , V_94 ,
& V_95 [ 2 ] , & V_95 [ 0 ] , & V_95 [ 1 ] ) ;
F_56 ( V_96 ) ;
if ( V_100 != - 1 )
return ( V_100 ) ;
}
V_97 = 64 ;
V_98 = 32 ;
V_99 = F_57 ( V_94 , V_97 , V_98 ) ;
if ( V_102 != 0 )
V_101 = 1 ;
else if ( V_62 == 0 )
V_101 = ( V_2 -> V_31 & V_103 ) != 0 ;
else
V_101 = ( V_2 -> V_31 & V_104 ) != 0 ;
if ( V_101 && V_99 >= 1024 ) {
V_97 = 255 ;
V_98 = 63 ;
V_99 = F_57 ( V_94 , V_97 , V_98 ) ;
}
V_95 [ 0 ] = V_97 ;
V_95 [ 1 ] = V_98 ;
V_95 [ 2 ] = V_99 ;
return ( 0 ) ;
}
static int
F_58 ( struct V_19 * V_20 )
{
int error ;
error = F_59 ( V_20 , V_105 ) ;
if ( error != 0 )
F_2 ( L_11 , error ) ;
return ( error ) ;
}
static int
F_60 ( struct V_19 * V_20 )
{
int error ;
error = F_59 ( V_20 , V_106 ) ;
if ( error != 0 )
F_2 ( L_12 , error ) ;
return ( error ) ;
}
static int
F_61 ( struct V_19 * V_20 )
{
struct V_1 * V_2 ;
int V_107 ;
unsigned long V_31 ;
V_2 = * (struct V_1 * * ) V_20 -> V_43 -> V_5 -> V_38 ;
F_28 ( V_2 , & V_31 ) ;
V_107 = F_62 ( V_2 , F_63 ( V_20 ) + 'A' ,
TRUE ) ;
F_30 ( V_2 , & V_31 ) ;
if ( V_88 )
F_2 ( L_13
L_14 , F_45 ( V_2 ) , V_107 ) ;
return V_108 ;
}
int
F_64 ( struct V_1 * V_2 , T_6 V_109 ,
T_3 V_110 , T_3 V_111 ,
T_2 V_112 , T_2 V_113 ,
T_7 * V_114 , void * V_115 ,
T_3 V_116 , int V_117 ,
T_3 V_118 , int V_31 , T_6 * V_119 )
{
T_6 V_120 ;
V_120 = F_65 ( sizeof( * V_120 ) , V_121 ) ;
if ( V_120 == NULL )
return ( V_122 ) ;
V_120 -> V_110 = V_110 ;
V_120 -> V_111 = V_111 ;
V_120 -> V_116 = V_116 ;
* V_119 = V_120 ;
return ( 0 ) ;
}
void
F_66 ( struct V_1 * V_2 , T_6 V_120 )
{
F_56 ( V_120 ) ;
}
int
F_67 ( struct V_1 * V_2 , T_6 V_120 , void * * V_123 ,
int V_31 , T_8 * V_124 )
{
* V_123 = F_68 ( V_2 -> V_125 ,
V_120 -> V_116 , V_124 ) ;
if ( * V_123 == NULL )
return V_122 ;
return 0 ;
}
void
F_69 ( struct V_1 * V_2 , T_6 V_120 ,
void * V_123 , T_8 V_126 )
{
F_70 ( V_2 -> V_125 , V_120 -> V_116 ,
V_123 , V_126 ) ;
}
int
F_71 ( struct V_1 * V_2 , T_6 V_120 , T_8 V_126 ,
void * V_127 , T_3 V_128 , T_9 * V_129 ,
void * V_130 , int V_31 )
{
T_10 V_131 ;
V_131 . V_132 = V_126 ;
V_131 . V_133 = V_120 -> V_116 ;
V_129 ( V_130 , & V_131 , 1 , 0 ) ;
return ( 0 ) ;
}
void
F_72 ( struct V_1 * V_2 , T_6 V_120 , T_8 V_126 )
{
}
int
F_73 ( struct V_1 * V_2 , T_6 V_120 , T_8 V_126 )
{
return ( 0 ) ;
}
static void
F_74 ( char * V_134 )
{
int V_135 , V_18 , V_136 ;
V_135 = F_75 ( V_134 + 1 , NULL , 0 ) & 0xff ;
F_2 ( L_15 , V_135 ) ;
for ( V_18 = 0 ; V_18 < F_76 ( V_137 ) ; V_18 ++ ) {
for ( V_136 = 0 ; V_136 < V_138 ; V_136 ++ ) {
V_137 [ V_18 ] . V_139 [ V_136 ] = V_135 ;
}
}
}
static void
F_77 ( T_11 V_140 , int V_141 , int V_142 , T_12 V_143 )
{
if ( ( V_141 >= 0 ) && ( V_142 >= 0 )
&& ( V_141 < F_76 ( V_137 ) )
&& ( V_142 < V_138 ) ) {
V_137 [ V_141 ] . V_139 [ V_142 ] = V_143 & 0xff ;
if ( V_88 )
F_2 ( L_16 , V_141 , V_142 , V_143 ) ;
}
}
static char *
F_78 ( char * V_144 , char * V_145 , char * V_146 , int V_147 ,
void (* F_79)( T_11 , int , int , T_12 ) ,
T_11 V_148 )
{
char * V_149 ;
char * V_150 ;
int V_18 ;
int V_141 ;
int V_142 ;
int V_151 ;
char V_152 [] = { '.' , ',' , '{' , '}' , '\0' } ;
if ( * V_145 != ':' )
return ( V_145 ) ;
V_145 ++ ;
V_141 = - 1 ;
V_142 = - 1 ;
V_151 = FALSE ;
V_149 = strchr ( V_145 , '\0' ) ;
if ( V_149 < V_146 )
* V_149 = ',' ;
while ( ! V_151 ) {
switch ( * V_145 ) {
case '{' :
if ( V_141 == - 1 ) {
V_141 = 0 ;
} else {
if ( V_147 > 1 ) {
if ( V_142 == - 1 )
V_142 = 0 ;
} else {
F_2 ( L_17 ,
V_144 ) ;
V_151 = TRUE ;
}
}
V_145 ++ ;
break;
case '}' :
if ( V_142 != - 1 )
V_142 = - 1 ;
else if ( V_141 != - 1 )
V_141 = - 1 ;
V_145 ++ ;
break;
case ',' :
case '.' :
if ( V_141 == - 1 )
V_151 = TRUE ;
else if ( V_142 >= 0 )
V_142 ++ ;
else if ( V_141 >= 0 )
V_141 ++ ;
V_145 ++ ;
break;
case '\0' :
V_151 = TRUE ;
break;
default:
V_149 = V_146 ;
for ( V_18 = 0 ; V_152 [ V_18 ] ; V_18 ++ ) {
V_150 = strchr ( V_145 , V_152 [ V_18 ] ) ;
if ( ( V_150 ) && ( V_150 < V_149 ) )
V_149 = V_150 ;
}
F_79 ( V_148 , V_141 , V_142 ,
F_80 ( V_145 , NULL , 0 ) ) ;
V_145 = V_149 ;
break;
}
}
return ( V_145 ) ;
}
static int
F_81 ( char * V_153 )
{
int V_18 , V_154 ;
char * V_134 ;
char * V_146 ;
static const struct {
const char * V_155 ;
T_13 * V_156 ;
} V_157 [] = {
{ L_18 , & V_102 } ,
{ L_19 , & V_158 } ,
{ L_20 , & V_159 } ,
{ L_21 , & V_160 } ,
#ifdef F_82
{ L_22 , & V_161 } ,
#endif
{ L_23 , & V_162 } ,
{ L_24 , & V_163 } ,
{ L_25 , & V_164 } ,
{ L_26 , NULL } ,
{ L_27 , NULL } ,
{ L_28 , NULL }
} ;
V_146 = strchr ( V_153 , '\0' ) ;
V_154 = 0 ;
while ( ( V_134 = F_83 ( & V_153 , L_29 ) ) != NULL ) {
if ( * V_134 == '\0' )
continue;
for ( V_18 = 0 ; V_18 < F_76 ( V_157 ) ; V_18 ++ ) {
V_154 = strlen ( V_157 [ V_18 ] . V_155 ) ;
if ( strncmp ( V_157 [ V_18 ] . V_155 , V_134 , V_154 ) == 0 )
break;
}
if ( V_18 == F_76 ( V_157 ) )
continue;
if ( strncmp ( V_134 , L_27 , V_154 ) == 0 ) {
F_74 ( V_134 + V_154 ) ;
} else if ( strncmp ( V_134 , L_26 , V_154 ) == 0 ) {
V_153 = F_78 ( L_26 , V_134 + V_154 , V_146 ,
2 , F_77 , 0 ) ;
} else if ( V_134 [ V_154 ] == ':' ) {
* ( V_157 [ V_18 ] . V_156 ) = F_75 ( V_134 + V_154 + 1 , NULL , 0 ) ;
} else if ( strncmp ( V_134 , L_20 , V_154 ) == 0 ) {
* ( V_157 [ V_18 ] . V_156 ) = 1 ;
} else {
* ( V_157 [ V_18 ] . V_156 ) ^= 0xFFFFFFFF ;
}
}
return 1 ;
}
int
F_84 ( struct V_1 * V_2 , struct V_165 * V_166 )
{
char V_127 [ 80 ] ;
struct V_34 * V_5 ;
char * V_167 ;
T_11 V_153 ;
int V_168 ;
V_166 -> V_155 = V_2 -> V_40 ;
V_5 = F_85 ( V_166 , sizeof( struct V_1 * ) ) ;
if ( V_5 == NULL )
return ( V_122 ) ;
* ( (struct V_1 * * ) V_5 -> V_38 ) = V_2 ;
V_2 -> V_4 -> V_5 = V_5 ;
V_5 -> V_169 = V_170 ;
V_5 -> V_171 = 2 ;
V_5 -> V_172 = V_2 -> V_63 ;
V_5 -> V_173 = V_2 -> V_4 -> V_173 ;
V_5 -> V_174 = ( V_2 -> V_75 & V_175 ) ? 16 : 8 ;
V_5 -> V_176 = V_177 ;
V_5 -> V_178 = ( V_2 -> V_75 & V_179 ) ? 1 : 0 ;
V_5 -> V_180 = V_29 ;
F_28 ( V_2 , & V_153 ) ;
F_86 ( V_2 , V_181 ++ ) ;
F_30 ( V_2 , & V_153 ) ;
sprintf ( V_127 , L_30 , V_5 -> V_6 ) ;
V_167 = F_65 ( strlen ( V_127 ) + 1 , V_121 ) ;
if ( V_167 != NULL ) {
strcpy ( V_167 , V_127 ) ;
F_87 ( V_2 , V_167 ) ;
}
V_5 -> V_182 = V_2 -> V_183 ;
F_88 ( V_2 ) ;
F_89 ( V_2 , TRUE ) ;
V_5 -> V_184 = V_185 ;
V_168 = F_90 ( V_5 ,
( V_2 -> V_125 ? & V_2 -> V_125 -> V_42 : NULL ) ) ;
if ( V_168 ) {
F_2 ( V_186 L_31 ) ;
F_91 ( V_5 ) ;
return V_168 ;
}
F_92 ( V_5 ) ;
return 0 ;
}
void
F_88 ( struct V_1 * V_2 )
{
int V_18 ;
int V_187 ;
unsigned long V_153 ;
V_18 = 0 ;
V_187 = 0 ;
F_28 ( V_2 , & V_153 ) ;
if ( V_158 != 0 )
V_2 -> V_31 &= ~ ( V_188 | V_189 ) ;
if ( ( V_2 -> V_31 & V_188 ) != 0 )
F_62 ( V_2 , 'A' , TRUE ) ;
else
V_187 = ( V_2 -> V_75 & V_175 ) ? 16 : 8 ;
if ( ( V_2 -> V_75 & V_179 ) != 0 ) {
if ( ( V_2 -> V_31 & V_189 ) != 0 ) {
F_62 ( V_2 , 'B' , TRUE ) ;
} else {
if ( V_187 == 0 )
V_18 = 8 ;
V_187 += 8 ;
}
}
for (; V_18 < V_187 ; V_18 ++ ) {
struct V_56 V_57 ;
struct V_58 * V_59 ;
struct V_60 * V_61 ;
T_5 V_63 ;
T_5 V_190 ;
char V_62 ;
V_62 = 'A' ;
V_63 = V_2 -> V_63 ;
V_190 = V_18 ;
if ( V_18 > 7 && ( V_2 -> V_75 & V_179 ) != 0 ) {
V_62 = 'B' ;
V_63 = V_2 -> V_66 ;
V_190 = V_18 % 8 ;
}
V_59 = F_39 ( V_2 , V_62 , V_63 ,
V_190 , & V_61 ) ;
F_40 ( & V_57 , V_63 , V_190 ,
V_81 , V_62 , V_82 ) ;
F_93 ( V_2 , & V_57 , V_61 ,
V_59 , V_191 ) ;
}
F_30 ( V_2 , & V_153 ) ;
if ( ( V_2 -> V_31 & ( V_188 | V_189 ) ) != 0 ) {
F_94 ( V_2 ) ;
F_95 ( V_192 ) ;
F_96 ( V_2 ) ;
}
}
int
F_97 ( struct V_1 * V_2 , void * V_193 )
{
V_2 -> V_4 =
F_65 ( sizeof( struct V_194 ) , V_121 ) ;
if ( V_2 -> V_4 == NULL )
return ( V_122 ) ;
memset ( V_2 -> V_4 , 0 , sizeof( struct V_194 ) ) ;
V_2 -> V_4 -> V_173 = V_195 ;
F_98 ( V_2 ) ;
V_2 -> V_196 = ( V_164 & 0x3 ) << 4 ;
V_2 -> V_197 = ( V_164 & 0x3 ) << 4 ;
if ( V_163 == 0 )
V_2 -> V_31 |= V_198 ;
return ( 0 ) ;
}
void
F_99 ( struct V_1 * V_2 )
{
struct V_49 * V_50 ;
int V_18 ;
if ( V_2 -> V_4 != NULL ) {
for ( V_18 = 0 ; V_18 < V_138 ; V_18 ++ ) {
V_50 = V_2 -> V_4 -> V_50 [ V_18 ] ;
if ( V_50 != NULL ) {
V_2 -> V_4 -> V_50 [ V_18 ] = NULL ;
}
}
if ( V_2 -> V_4 -> V_173 != V_195 )
F_100 ( V_2 -> V_4 -> V_173 , V_2 ) ;
if ( V_2 -> V_10 == V_199
&& V_2 -> V_12 . V_14 != 0 )
F_101 ( V_2 -> V_12 . V_14 , 256 ) ;
if ( V_2 -> V_10 == V_11
&& V_2 -> V_12 . V_13 != NULL ) {
F_102 ( V_2 -> V_12 . V_13 ) ;
F_103 ( V_2 -> V_4 -> V_200 ,
0x1000 ) ;
}
if ( V_2 -> V_4 -> V_5 )
F_91 ( V_2 -> V_4 -> V_5 ) ;
F_56 ( V_2 -> V_4 ) ;
}
}
void
F_104 ( struct V_1 * V_2 , struct V_3 * V_3 )
{
F_105 ( V_2 , F_4 ( V_2 , V_3 ) ,
F_3 ( V_2 , V_3 ) ,
F_5 ( V_3 ) , V_201 ,
V_202 , V_203 ) ;
}
void
F_106 ( struct V_1 * V_2 , struct V_85 * V_86 ,
struct V_56 * V_57 , T_14 V_204 )
{
struct V_41 * V_42 ;
int V_205 ;
int V_206 ;
if ( V_86 == NULL )
return;
V_42 = F_27 ( V_86 ) ;
V_205 = V_42 -> V_31 & ( V_207 | V_208 ) ;
switch ( V_204 ) {
default:
case V_209 :
V_206 = 0 ;
break;
case V_210 :
V_206 = V_207 ;
break;
case V_211 :
V_206 = V_208 ;
break;
}
if ( ( V_42 -> V_31 & V_212 ) == 0
&& ( V_205 != V_206 )
&& ( V_42 -> V_213 != 0 ) ) {
V_42 -> V_31 |= V_212 ;
V_42 -> V_46 ++ ;
}
V_42 -> V_31 &= ~ ( V_207 | V_208 | V_214 ) ;
if ( V_206 ) {
T_5 V_215 ;
V_215 = F_107 ( V_2 , V_57 ) ;
if ( ! V_205 ) {
V_42 -> V_90 = V_215 ;
V_42 -> V_89 = V_42 -> V_90 - V_42 -> V_213 ;
}
if ( V_42 -> V_90 == 0 ) {
V_42 -> V_89 = 1 ;
} else if ( V_204 == V_211 ) {
V_42 -> V_31 |= V_208 ;
if ( V_162 != 0 )
V_42 -> V_31 |= V_214 ;
} else
V_42 -> V_31 |= V_207 ;
} else {
V_42 -> V_90 = 0 ;
V_42 -> V_89 = 1 - V_42 -> V_213 ;
}
switch ( ( V_42 -> V_31 & ( V_207 | V_208 ) ) ) {
case V_207 :
F_108 ( V_86 , V_216 ) ;
F_109 ( V_86 , V_42 -> V_89 + V_42 -> V_213 ) ;
break;
case V_208 :
F_108 ( V_86 , V_217 ) ;
F_109 ( V_86 , V_42 -> V_89 + V_42 -> V_213 ) ;
break;
default:
F_110 ( V_86 , 2 ) ;
break;
}
}
int
F_105 ( struct V_1 * V_2 , int V_218 , char V_62 ,
int V_219 , T_5 V_10 , T_15 V_220 , T_13 V_221 )
{
return 0 ;
}
static T_5
F_107 ( struct V_1 * V_2 , struct V_56 * V_57 )
{
static int V_222 ;
T_5 V_135 ;
V_135 = 0 ;
if ( ( V_2 -> V_223 & V_57 -> V_224 ) != 0 ) {
if ( V_2 -> V_183 >= F_76 ( V_137 ) ) {
if ( V_222 == 0 ) {
F_2 ( V_186
L_32
L_33
L_34
L_35 ) ;
V_222 ++ ;
}
V_135 = V_170 ;
} else {
T_16 * V_225 ;
V_225 = & V_137 [ V_2 -> V_183 ] ;
V_135 = V_225 -> V_139 [ V_57 -> V_64 ] ;
if ( V_135 > V_170 )
V_135 = V_170 ;
}
}
return ( V_135 ) ;
}
static void
F_49 ( struct V_85 * V_86 )
{
struct V_56 V_57 ;
T_5 V_135 ;
struct V_1 * V_2 = * ( (struct V_1 * * ) V_86 -> V_5 -> V_38 ) ;
F_40 ( & V_57 ,
V_86 -> V_87 -> V_62 == 0
? V_2 -> V_63 : V_2 -> V_66 ,
V_86 -> V_87 -> V_65 , V_86 -> V_219 ,
V_86 -> V_87 -> V_62 == 0 ? 'A' : 'B' ,
V_82 ) ;
V_135 = F_107 ( V_2 , & V_57 ) ;
if ( V_135 != 0 && V_86 -> V_226 != 0 ) {
F_106 ( V_2 , V_86 , & V_57 , V_211 ) ;
F_111 ( V_2 , V_57 . V_62 , V_57 . V_218 ,
V_57 . V_219 , V_227 ) ;
F_112 ( V_2 , & V_57 ) ;
F_2 ( L_36 , V_135 ) ;
} else {
F_106 ( V_2 , V_86 , & V_57 , V_209 ) ;
F_111 ( V_2 , V_57 . V_62 , V_57 . V_218 ,
V_57 . V_219 , V_227 ) ;
}
}
static int
F_29 ( struct V_1 * V_2 , struct V_41 * V_42 ,
struct V_19 * V_20 )
{
struct V_3 * V_3 ;
struct V_228 * V_229 ;
struct V_58 * V_59 ;
struct V_60 * V_61 ;
T_17 V_230 ;
struct V_231 * V_232 = NULL ;
int V_233 ;
if ( V_2 -> V_4 -> V_46 != 0 )
return V_45 ;
if ( ! F_113 ( V_20 -> V_234 )
&& ( V_2 -> V_75 & V_235 ) == 0 ) {
int V_64 ;
V_64 = V_20 -> V_43 -> V_65 + V_20 -> V_43 -> V_62 * 8 ;
V_232 = & ( V_2 -> V_236 [ V_64 ] ) ;
if ( ! F_114 ( V_232 ) )
return V_237 ;
}
V_233 = F_115 ( V_20 ) ;
if ( V_233 < 0 )
return V_45 ;
V_3 = F_116 ( V_2 ) ;
if ( ! V_3 ) {
F_19 ( V_20 ) ;
return V_45 ;
}
V_3 -> V_21 = V_20 ;
V_3 -> V_4 -> V_42 = V_42 ;
V_229 = V_3 -> V_229 ;
V_20 -> V_238 = ( char * ) V_3 ;
V_229 -> V_239 = 0 ;
V_229 -> V_240 = F_117 ( V_2 , V_20 ) ;
V_229 -> V_219 = V_20 -> V_43 -> V_219 ;
V_230 = F_118 ( V_2 , V_3 ) ;
V_59 = F_39 ( V_2 , F_3 ( V_2 , V_3 ) ,
F_119 ( V_3 ) ,
F_4 ( V_2 , V_3 ) , & V_61 ) ;
V_229 -> V_55 = V_59 -> V_55 ;
V_229 -> V_241 = V_59 -> V_242 . V_243 ;
if ( ( V_61 -> V_244 & V_230 ) != 0 )
V_229 -> V_239 |= V_245 ;
if ( ( V_2 -> V_223 & V_230 ) != 0 )
V_229 -> V_239 |= V_246 ;
if ( ( V_61 -> V_247 & V_230 ) != 0 ) {
V_3 -> V_31 |= V_248 ;
V_3 -> V_229 -> V_239 |= V_249 ;
}
if ( ( V_42 -> V_31 & ( V_208 | V_207 ) ) != 0 ) {
int V_250 ;
T_1 V_251 [ 2 ] ;
V_250 = F_120 ( V_20 , V_251 ) ;
if ( V_250 && V_251 [ 0 ] != V_252 ) {
V_229 -> V_239 |= V_251 [ 0 ] ;
if ( V_251 [ 0 ] == V_253 )
V_42 -> V_254 = 0 ;
} else if ( V_42 -> V_254 == V_255
&& ( V_42 -> V_31 & V_208 ) != 0 ) {
V_229 -> V_239 |= V_253 ;
V_42 -> V_254 = 0 ;
} else {
V_229 -> V_239 |= V_252 ;
}
}
V_229 -> V_256 = V_20 -> V_257 ;
if ( V_229 -> V_256 <= 12 ) {
memcpy ( V_229 -> V_258 . V_259 , V_20 -> V_260 , V_229 -> V_256 ) ;
} else {
memcpy ( V_229 -> V_261 , V_20 -> V_260 , V_229 -> V_256 ) ;
V_3 -> V_31 |= V_262 ;
}
V_3 -> V_4 -> V_30 = 0 ;
F_121 ( V_3 , 0 ) ;
F_122 ( V_3 , 0 ) ;
V_3 -> V_28 = 0 ;
if ( V_233 > 0 ) {
struct V_23 * V_24 ;
struct V_263 * V_264 ;
int V_18 ;
V_24 = V_3 -> V_265 ;
F_123 (cmd, cur_seg, nseg, i) {
T_2 V_25 ;
T_3 V_26 ;
int V_27 ;
V_25 = F_124 ( V_264 ) ;
V_26 = F_125 ( V_264 ) ;
V_27 = F_20 ( V_2 , V_3 ,
V_24 , V_25 , V_26 ) ;
V_24 += V_27 ;
V_3 -> V_28 += V_27 ;
}
V_24 -- ;
V_24 -> V_26 |= F_22 ( V_266 ) ;
V_3 -> V_229 -> V_267 =
F_22 ( V_3 -> V_268 | V_269 ) ;
V_3 -> V_229 -> V_270 = V_3 -> V_265 -> V_25 ;
V_3 -> V_229 -> V_271 = V_3 -> V_265 -> V_26 ;
} else {
V_3 -> V_229 -> V_267 = F_22 ( V_272 ) ;
V_3 -> V_229 -> V_270 = 0 ;
V_3 -> V_229 -> V_271 = 0 ;
V_3 -> V_28 = 0 ;
}
F_126 ( & V_2 -> V_273 , V_3 , V_274 ) ;
V_42 -> V_89 -- ;
V_42 -> V_213 ++ ;
V_42 -> V_275 ++ ;
if ( ( V_42 -> V_31 & V_214 ) != 0 )
V_42 -> V_254 ++ ;
V_3 -> V_31 |= V_276 ;
if ( V_232 ) {
F_127 ( V_232 , V_3 , V_277 . V_278 ) ;
V_3 -> V_31 |= V_279 ;
}
F_128 ( V_2 , V_3 ) ;
return 0 ;
}
T_18
F_129 ( int V_173 , void * V_280 )
{
struct V_1 * V_2 ;
T_11 V_31 ;
int V_281 ;
V_2 = (struct V_1 * ) V_280 ;
F_28 ( V_2 , & V_31 ) ;
V_281 = F_130 ( V_2 ) ;
F_30 ( V_2 , & V_31 ) ;
return F_131 ( V_281 ) ;
}
void
F_132 ( struct V_1 * V_2 )
{
}
void
F_111 ( struct V_1 * V_2 , char V_62 ,
T_5 V_218 , T_5 V_219 , T_19 V_282 )
{
switch ( V_282 ) {
case V_227 :
{
struct V_49 * V_50 ;
struct V_283 * V_142 ;
struct V_58 * V_59 ;
struct V_60 * V_61 ;
int V_64 ;
unsigned int V_284 ;
F_34 ( V_218 == V_285 ) ;
V_59 = F_39 ( V_2 , V_62 ,
V_62 == 'A' ? V_2 -> V_63
: V_2 -> V_66 ,
V_218 , & V_61 ) ;
if ( V_59 -> V_242 . V_286 != V_59 -> V_287 . V_286
|| V_59 -> V_242 . V_288 != V_59 -> V_287 . V_288
|| V_59 -> V_242 . V_243 != V_59 -> V_287 . V_243
|| V_59 -> V_242 . V_289 != V_59 -> V_287 . V_289 )
if ( V_88 == 0 )
break;
V_64 = V_218 ;
if ( V_62 == 'B' )
V_64 += 8 ;
V_50 = V_2 -> V_4 -> V_50 [ V_64 ] ;
if ( V_50 == NULL )
break;
V_142 = F_133 ( V_50 ) ;
V_284 =
( F_134 ( V_50 ) ? V_290 : 0 )
+ ( F_135 ( V_50 ) ? V_291 : 0 )
+ ( F_136 ( V_50 ) ? V_292 : 0 ) ;
if ( V_59 -> V_242 . V_286 == F_46 ( V_50 )
&& V_59 -> V_242 . V_288 == F_137 ( V_50 )
&& V_59 -> V_242 . V_243 == F_138 ( V_50 )
&& V_59 -> V_242 . V_289 == V_284 )
if ( V_88 == 0 )
break;
F_46 ( V_50 ) = V_59 -> V_242 . V_286 ;
F_137 ( V_50 ) = V_59 -> V_242 . V_288 ;
F_138 ( V_50 ) = V_59 -> V_242 . V_243 ;
F_134 ( V_50 ) = V_59 -> V_242 . V_289 & V_290 ? 1 : 0 ;
F_135 ( V_50 ) = V_59 -> V_242 . V_289 & V_291 ? 1 : 0 ;
F_136 ( V_50 ) = V_59 -> V_242 . V_289 & V_292 ? 1 : 0 ;
F_139 ( V_50 ) ;
break;
}
case V_293 :
{
F_140 ( V_219 != V_81 ) ;
F_141 ( V_2 -> V_4 -> V_5 ,
V_62 - 'A' , V_218 ) ;
break;
}
case V_294 :
if ( V_2 -> V_4 -> V_5 != NULL ) {
F_142 ( V_2 -> V_4 -> V_5 ,
V_62 - 'A' ) ;
}
break;
default:
F_21 ( L_37 ) ;
}
}
void
F_143 ( struct V_1 * V_2 , struct V_3 * V_3 )
{
struct V_19 * V_20 ;
struct V_41 * V_42 ;
F_144 ( V_3 , V_274 ) ;
if ( ( V_3 -> V_31 & V_279 ) != 0 ) {
struct V_231 * V_232 ;
int V_64 ;
V_64 = F_145 ( V_2 , V_3 ) ;
V_232 = & ( V_2 -> V_236 [ V_64 ] ) ;
F_146 ( V_232 , V_3 , V_277 . V_278 ) ;
F_34 ( ! F_114 ( V_232 ) ) ;
} else if ( ( V_3 -> V_31 & V_276 ) == 0 ) {
F_2 ( L_38 , V_3 -> V_229 -> V_10 ) ;
F_147 ( V_2 ) ;
F_21 ( L_39 ) ;
}
V_20 = V_3 -> V_21 ;
V_42 = V_3 -> V_4 -> V_42 ;
V_42 -> V_213 -- ;
V_42 -> V_89 ++ ;
if ( ( V_20 -> V_47 & ( V_295 << 16 ) ) != 0 ) {
V_20 -> V_47 &= ~ ( V_295 << 16 ) ;
V_42 -> V_46 -- ;
}
F_17 ( V_2 , V_3 ) ;
V_20 -> V_296 [ 0 ] = 0 ;
if ( F_148 ( V_3 ) == V_48 ) {
T_13 V_297 ;
V_297 =
F_149 ( V_3 ) - F_150 ( V_3 ) ;
if ( ( V_3 -> V_31 & V_298 ) != 0 ) {
#ifdef F_82
if ( ( V_161 & V_299 ) != 0 ) {
F_1 ( V_2 , V_3 ) ;
F_2 ( L_40 ) ;
}
#endif
F_151 ( V_3 , V_300 ) ;
#ifdef F_152
} else if ( V_297 < V_3 -> V_21 -> V_301 ) {
T_5 V_18 ;
F_1 ( V_2 , V_3 ) ;
F_2 ( L_41 ) ;
for ( V_18 = 0 ; V_18 < V_3 -> V_21 -> V_257 ; V_18 ++ )
F_2 ( L_42 , V_3 -> V_21 -> V_260 [ V_18 ] ) ;
F_2 ( L_5 ) ;
F_1 ( V_2 , V_3 ) ;
F_2 ( L_43
L_44 ,
F_150 ( V_3 ) ,
F_149 ( V_3 ) ) ;
F_151 ( V_3 , V_302 ) ;
#endif
} else {
F_151 ( V_3 , V_303 ) ;
}
} else if ( F_148 ( V_3 ) == V_304 ) {
F_153 ( V_2 , V_20 -> V_43 , V_3 ) ;
}
if ( V_42 -> V_89 == 1
&& F_148 ( V_3 ) == V_303
&& F_154 ( V_3 ) != V_305 )
V_42 -> V_306 ++ ;
if ( ( V_42 -> V_89 + V_42 -> V_213 ) < V_42 -> V_90
&& V_42 -> V_306 > V_307 ) {
V_42 -> V_306 = 0 ;
V_42 -> V_89 ++ ;
}
if ( V_42 -> V_213 == 0 )
V_42 -> V_254 = 0 ;
if ( ( V_3 -> V_31 & V_308 ) != 0 ) {
F_2 ( L_45 ) ;
if ( F_148 ( V_3 ) == V_309
|| F_148 ( V_3 ) == V_310 )
F_151 ( V_3 , V_311 ) ;
if ( V_2 -> V_4 -> V_312 )
F_155 ( V_2 -> V_4 -> V_312 ) ;
}
F_156 ( V_2 , V_3 ) ;
F_157 ( V_2 , V_20 ) ;
}
static void
F_153 ( struct V_1 * V_2 ,
struct V_85 * V_86 , struct V_3 * V_3 )
{
struct V_56 V_57 ;
struct V_41 * V_42 = F_27 ( V_86 ) ;
F_40 ( & V_57 ,
V_2 -> V_63 ,
V_86 -> V_87 -> V_65 , V_86 -> V_219 ,
V_86 -> V_87 -> V_62 == 0 ? 'A' : 'B' ,
V_82 ) ;
switch ( F_154 ( V_3 ) ) {
default:
break;
case V_313 :
case V_314 :
{
struct V_19 * V_20 ;
V_20 = V_3 -> V_21 ;
if ( V_3 -> V_31 & V_315 ) {
T_5 V_316 ;
V_316 = F_158 ( sizeof( struct V_317 )
- F_159 ( V_3 ) ,
( T_11 ) V_318 ) ;
memcpy ( V_20 -> V_296 ,
F_160 ( V_2 , V_3 ) , V_316 ) ;
if ( V_316 < V_318 )
memset ( & V_20 -> V_296 [ V_316 ] , 0 ,
V_318 - V_316 ) ;
V_20 -> V_47 |= ( V_319 << 24 ) ;
#ifdef F_82
if ( V_161 & V_320 ) {
int V_18 ;
F_2 ( L_46 ,
V_316 ) ;
for ( V_18 = 0 ; V_18 < V_316 ; V_18 ++ ) {
if ( ( V_18 & 0xF ) == 0 )
F_2 ( L_5 ) ;
F_2 ( L_47 , V_20 -> V_296 [ V_18 ] ) ;
}
F_2 ( L_5 ) ;
}
#endif
}
break;
}
case V_305 :
{
V_42 -> V_306 = 0 ;
if ( V_42 -> V_213 != 0 ) {
V_42 -> V_89 = 0 ;
if ( V_42 -> V_213 == V_42 -> V_321 ) {
V_42 -> V_322 ++ ;
if ( V_42 -> V_322
== V_323 ) {
V_42 -> V_90 = V_42 -> V_213 ;
F_1 ( V_2 , V_3 ) ;
F_2 ( L_48 ,
V_42 -> V_213 ) ;
}
} else {
V_42 -> V_321 = V_42 -> V_213 ;
V_42 -> V_322 = 0 ;
}
F_151 ( V_3 , V_203 ) ;
F_161 ( V_3 , V_324 ) ;
F_106 ( V_2 , V_86 , & V_57 ,
( V_42 -> V_31 & V_207 )
? V_210 : V_211 ) ;
break;
}
V_42 -> V_89 = 1 ;
F_161 ( V_3 , V_325 ) ;
F_106 ( V_2 , V_86 , & V_57 ,
( V_42 -> V_31 & V_207 )
? V_210 : V_211 ) ;
break;
}
}
}
static void
F_157 ( struct V_1 * V_2 , struct V_19 * V_20 )
{
{
T_5 V_326 ;
switch ( F_162 ( V_20 ) ) {
case V_48 :
case V_303 :
case V_304 :
V_326 = V_327 ;
break;
case V_310 :
V_326 = V_328 ;
break;
case V_329 :
V_326 = V_330 ;
break;
case V_331 :
case V_332 :
V_326 = V_333 ;
break;
case V_334 :
V_326 = V_335 ;
break;
case V_336 :
case V_309 :
V_326 = V_337 ;
break;
case V_300 :
V_326 = V_338 ;
break;
case V_311 :
V_326 = V_339 ;
break;
case V_340 :
case V_341 :
case V_342 :
case V_343 :
case V_302 :
case V_344 :
case V_345 :
case V_346 :
case V_347 :
case V_348 :
case V_349 :
case V_350 :
V_326 = V_351 ;
break;
case V_203 :
V_326 = V_352 ;
break;
default:
V_326 = V_351 ;
break;
}
F_163 ( V_20 , V_326 ) ;
}
V_20 -> F_26 ( V_20 ) ;
}
static void
F_94 ( struct V_1 * V_2 )
{
unsigned long V_153 ;
F_28 ( V_2 , & V_153 ) ;
V_2 -> V_4 -> V_46 ++ ;
if ( V_2 -> V_4 -> V_46 == 1 ) {
F_164 ( V_2 -> V_4 -> V_5 ) ;
F_105 ( V_2 , V_285 , V_353 ,
V_81 , V_201 ,
V_82 , V_203 ) ;
}
F_30 ( V_2 , & V_153 ) ;
}
static void
F_96 ( struct V_1 * V_2 )
{
T_11 V_153 ;
int V_354 ;
V_354 = 0 ;
F_28 ( V_2 , & V_153 ) ;
if ( V_2 -> V_4 -> V_46 > 0 )
V_2 -> V_4 -> V_46 -- ;
if ( V_2 -> V_4 -> V_46 == 0 )
V_354 = 1 ;
F_30 ( V_2 , & V_153 ) ;
if ( V_354 )
F_165 ( V_2 -> V_4 -> V_5 ) ;
}
static int
F_59 ( struct V_19 * V_20 , T_20 V_156 )
{
struct V_1 * V_2 ;
struct V_41 * V_42 ;
struct V_3 * V_355 ;
T_5 V_356 ;
T_5 V_357 ;
T_5 V_358 ;
T_5 V_359 ;
T_5 V_360 ;
int V_168 ;
int V_361 ;
int V_362 ;
int V_363 ;
int V_364 ;
unsigned long V_31 ;
V_355 = NULL ;
V_362 = FALSE ;
V_363 = FALSE ;
V_2 = * (struct V_1 * * ) V_20 -> V_43 -> V_5 -> V_38 ;
F_166 ( V_91 , V_20 , L_49 ,
V_156 == V_105 ? L_50 : L_51 ) ;
F_2 ( L_41 ) ;
for ( V_360 = 0 ; V_360 < V_20 -> V_257 ; V_360 ++ )
F_2 ( L_42 , V_20 -> V_260 [ V_360 ] ) ;
F_2 ( L_5 ) ;
F_28 ( V_2 , & V_31 ) ;
V_42 = F_27 ( V_20 -> V_43 ) ;
if ( V_42 == NULL ) {
F_2 ( L_52 ,
F_45 ( V_2 ) , V_20 -> V_43 -> V_62 , V_20 -> V_43 -> V_65 ,
V_20 -> V_43 -> V_219 ) ;
V_168 = V_108 ;
goto V_365;
}
if ( ( V_42 -> V_31 & ( V_207 | V_208 ) ) == 0
&& F_167 ( V_2 , V_20 , V_20 -> V_43 -> V_65 ,
V_20 -> V_43 -> V_62 + 'A' ,
V_20 -> V_43 -> V_219 ,
V_310 , V_366 ) != 0 ) {
F_2 ( L_53 ,
F_45 ( V_2 ) , V_20 -> V_43 -> V_62 , V_20 -> V_43 -> V_65 ,
V_20 -> V_43 -> V_219 ) ;
V_168 = V_108 ;
goto V_151;
}
F_168 (pending_scb, &ahc->pending_scbs, pending_links) {
if ( V_355 -> V_21 == V_20 )
break;
}
if ( V_355 == NULL && V_156 == V_106 ) {
F_168 (pending_scb, &ahc->pending_scbs, pending_links) {
if ( F_169 ( V_2 , V_355 , F_170 ( V_20 ) ,
F_63 ( V_20 ) + 'A' ,
V_81 ,
V_201 , V_82 ) )
break;
}
}
if ( V_355 == NULL ) {
F_166 ( V_91 , V_20 , L_54 ) ;
goto V_365;
}
if ( ( V_355 -> V_31 & V_308 ) != 0 ) {
V_168 = V_367 ;
goto V_151;
}
V_361 = F_171 ( V_2 ) ;
F_172 ( V_2 ) ;
V_362 = TRUE ;
if ( ( V_355 -> V_31 & V_276 ) == 0 ) {
F_166 ( V_91 , V_20 , L_55 ) ;
goto V_365;
}
F_2 ( L_56 ,
F_45 ( V_2 ) , V_361 ? L_57 : L_58 ) ;
F_147 ( V_2 ) ;
V_364 = TRUE ;
if ( V_156 == V_105 ) {
if ( F_173 ( V_2 , V_20 -> V_43 -> V_65 ,
V_20 -> V_43 -> V_62 + 'A' ,
V_20 -> V_43 -> V_219 ,
V_355 -> V_229 -> V_10 ,
V_82 , V_310 ,
V_366 ) > 0 ) {
F_2 ( L_59 ,
F_45 ( V_2 ) , V_20 -> V_43 -> V_62 ,
V_20 -> V_43 -> V_65 , V_20 -> V_43 -> V_219 ) ;
V_168 = V_108 ;
goto V_151;
}
} else if ( F_173 ( V_2 , V_20 -> V_43 -> V_65 ,
V_20 -> V_43 -> V_62 + 'A' ,
V_20 -> V_43 -> V_219 , V_355 -> V_229 -> V_10 ,
V_82 , 0 ,
V_368 ) > 0 ) {
V_364 = FALSE ;
}
if ( V_364 && ( F_8 ( V_2 , V_369 ) & V_370 ) == 0 ) {
struct V_3 * V_371 ;
V_371 = F_174 ( V_2 , F_8 ( V_2 , V_372 ) ) ;
if ( V_371 == V_355 )
V_364 = FALSE ;
else if ( V_156 != V_105
&& F_8 ( V_2 , V_373 ) == V_355 -> V_229 -> V_240
&& F_8 ( V_2 , V_374 ) == F_5 ( V_355 ) )
V_364 = FALSE ;
}
V_358 = F_8 ( V_2 , V_375 ) ;
V_356 = F_8 ( V_2 , V_376 ) ;
V_357 = F_8 ( V_2 , V_372 ) ;
V_359 = F_8 ( V_2 , V_373 ) ;
if ( V_358 != V_377
&& ( V_355 -> V_229 -> V_10 == V_357
|| ( V_156 == V_106
&& F_175 ( V_2 , V_359 ) == F_170 ( V_20 ) ) ) ) {
V_355 = F_174 ( V_2 , V_357 ) ;
V_355 -> V_31 |= V_308 | V_156 ;
F_12 ( V_2 , V_378 , V_379 ) ;
F_12 ( V_2 , V_380 , V_358 | V_381 ) ;
F_166 ( V_91 , V_20 , L_60 ) ;
V_363 = TRUE ;
} else if ( V_364 ) {
V_355 -> V_229 -> V_239 |= V_249 | V_382 ;
V_355 -> V_31 |= V_308 | V_156 ;
F_176 ( V_2 , V_20 -> V_43 -> V_65 ,
V_20 -> V_43 -> V_62 + 'A' ,
V_20 -> V_43 -> V_219 , V_355 -> V_229 -> V_10 ,
TRUE ,
TRUE ,
FALSE ) ;
if ( ( V_2 -> V_31 & V_383 ) == 0 ) {
F_12 ( V_2 , V_376 , V_355 -> V_229 -> V_10 ) ;
F_12 ( V_2 , V_384 ,
F_8 ( V_2 , V_384 ) | V_249 ) ;
}
F_173 ( V_2 , V_20 -> V_43 -> V_65 ,
V_20 -> V_43 -> V_62 + 'A' ,
V_20 -> V_43 -> V_219 , V_201 ,
V_82 , V_203 ,
V_366 ) ;
F_177 ( V_2 , V_355 ) ;
F_12 ( V_2 , V_376 , V_356 ) ;
F_1 ( V_2 , V_355 ) ;
F_2 ( L_61 ) ;
V_363 = TRUE ;
} else {
F_166 ( V_91 , V_20 , L_62 ) ;
V_168 = V_367 ;
goto V_151;
}
V_365:
V_168 = V_108 ;
V_151:
if ( V_362 )
F_178 ( V_2 ) ;
if ( V_363 ) {
F_179 ( V_151 ) ;
V_2 -> V_4 -> V_312 = & V_151 ;
F_30 ( V_2 , & V_31 ) ;
F_2 ( L_63 ) ;
if ( ! F_180 ( & V_151 , 5 * V_385 ) ) {
F_28 ( V_2 , & V_31 ) ;
V_2 -> V_4 -> V_312 = NULL ;
F_30 ( V_2 , & V_31 ) ;
F_2 ( L_64 ) ;
V_168 = V_367 ;
}
F_2 ( L_65 ) ;
} else
F_30 ( V_2 , & V_31 ) ;
return ( V_168 ) ;
}
void
F_181 ( struct V_1 * V_2 )
{
}
static void F_182 ( struct V_49 * V_50 , int V_288 )
{
struct V_34 * V_386 = F_32 ( V_50 -> V_42 . V_109 ) ;
struct V_1 * V_2 = * ( (struct V_1 * * ) V_386 -> V_38 ) ;
struct V_56 V_57 ;
unsigned long V_31 ;
F_40 ( & V_57 , V_386 -> V_172 , V_50 -> V_65 , 0 ,
V_50 -> V_62 + 'A' , V_82 ) ;
F_28 ( V_2 , & V_31 ) ;
F_42 ( V_2 , & V_57 , V_288 , V_83 , FALSE ) ;
F_30 ( V_2 , & V_31 ) ;
}
static void F_183 ( struct V_49 * V_50 , int V_286 )
{
struct V_34 * V_386 = F_32 ( V_50 -> V_42 . V_109 ) ;
struct V_1 * V_2 = * ( (struct V_1 * * ) V_386 -> V_38 ) ;
struct V_60 * V_61 ;
struct V_58 * V_59
= F_39 ( V_2 ,
V_50 -> V_62 + 'A' ,
V_386 -> V_172 , V_50 -> V_65 , & V_61 ) ;
struct V_56 V_57 ;
unsigned int V_289 = V_59 -> V_287 . V_289 ;
unsigned long V_31 ;
unsigned long V_243 = V_59 -> V_287 . V_243 ;
const struct V_387 * V_388 ;
if ( V_243 == 0 )
V_243 = V_389 ;
if ( V_286 < 9 )
V_286 = 9 ;
if ( V_286 == 9 ) {
if ( F_35 ( V_50 ) )
V_289 |= V_290 ;
else
V_286 = 10 ;
}
F_40 ( & V_57 , V_386 -> V_172 , V_50 -> V_65 , 0 ,
V_50 -> V_62 + 'A' , V_82 ) ;
if ( V_289 & ~ V_291 ) {
if ( F_137 ( V_50 ) == 0 )
V_289 &= V_291 ;
}
V_388 = F_184 ( V_2 , & V_286 , & V_289 , V_68 ) ;
F_28 ( V_2 , & V_31 ) ;
F_41 ( V_2 , & V_57 , V_388 , V_286 , V_243 ,
V_289 , V_83 , FALSE ) ;
F_30 ( V_2 , & V_31 ) ;
}
static void F_185 ( struct V_49 * V_50 , int V_243 )
{
struct V_34 * V_386 = F_32 ( V_50 -> V_42 . V_109 ) ;
struct V_1 * V_2 = * ( (struct V_1 * * ) V_386 -> V_38 ) ;
struct V_60 * V_61 ;
struct V_58 * V_59
= F_39 ( V_2 ,
V_50 -> V_62 + 'A' ,
V_386 -> V_172 , V_50 -> V_65 , & V_61 ) ;
struct V_56 V_57 ;
unsigned int V_289 = 0 ;
unsigned int V_286 = 0 ;
unsigned long V_31 ;
const struct V_387 * V_388 = NULL ;
F_40 ( & V_57 , V_386 -> V_172 , V_50 -> V_65 , 0 ,
V_50 -> V_62 + 'A' , V_82 ) ;
if ( V_243 != 0 ) {
V_388 = F_184 ( V_2 , & V_286 , & V_289 , V_68 ) ;
V_286 = V_59 -> V_287 . V_286 ;
V_289 = V_59 -> V_287 . V_289 ;
}
F_28 ( V_2 , & V_31 ) ;
F_41 ( V_2 , & V_57 , V_388 , V_286 , V_243 ,
V_289 , V_83 , FALSE ) ;
F_30 ( V_2 , & V_31 ) ;
}
static void F_186 ( struct V_49 * V_50 , int V_390 )
{
struct V_34 * V_386 = F_32 ( V_50 -> V_42 . V_109 ) ;
struct V_1 * V_2 = * ( (struct V_1 * * ) V_386 -> V_38 ) ;
struct V_60 * V_61 ;
struct V_58 * V_59
= F_39 ( V_2 ,
V_50 -> V_62 + 'A' ,
V_386 -> V_172 , V_50 -> V_65 , & V_61 ) ;
struct V_56 V_57 ;
unsigned int V_289 = V_59 -> V_287 . V_289
& ~ V_290 ;
unsigned int V_286 = V_59 -> V_287 . V_286 ;
unsigned int V_288 = V_59 -> V_287 . V_288 ;
unsigned long V_31 ;
const struct V_387 * V_388 ;
if ( V_390 && F_35 ( V_50 ) ) {
V_289 |= V_290 ;
if ( ! V_288 )
F_182 ( V_50 , 1 ) ;
} else if ( V_286 == 9 )
V_286 = 10 ;
F_40 ( & V_57 , V_386 -> V_172 , V_50 -> V_65 , 0 ,
V_50 -> V_62 + 'A' , V_82 ) ;
V_388 = F_184 ( V_2 , & V_286 , & V_289 , V_68 ) ;
F_28 ( V_2 , & V_31 ) ;
F_41 ( V_2 , & V_57 , V_388 , V_286 , V_59 -> V_287 . V_243 ,
V_289 , V_83 , FALSE ) ;
F_30 ( V_2 , & V_31 ) ;
}
static void F_187 ( struct V_34 * V_386 )
{
struct V_1 * V_2 = * (struct V_1 * * ) V_386 -> V_38 ;
unsigned long V_31 ;
T_21 V_391 ;
if ( ! ( V_2 -> V_75 & V_76 ) ) {
F_188 ( V_386 ) =
V_2 -> V_75 & V_392 ?
V_393 :
V_394 ;
return;
}
F_28 ( V_2 , & V_31 ) ;
F_189 ( V_2 ) ;
V_391 = F_8 ( V_2 , V_395 ) ;
F_178 ( V_2 ) ;
F_30 ( V_2 , & V_31 ) ;
if ( V_391 & V_396 )
F_188 ( V_386 ) = V_397 ;
else if ( V_391 & V_398 )
F_188 ( V_386 ) = V_394 ;
else
F_188 ( V_386 ) = V_399 ;
}
static int T_22
F_190 ( void )
{
if ( V_400 )
F_81 ( V_400 ) ;
V_185 =
F_191 ( & V_401 ) ;
if ( ! V_185 )
return - V_402 ;
F_192 ( V_185 ,
sizeof( struct V_41 ) ) ;
F_193 () ;
F_194 () ;
return 0 ;
}
static void
F_195 ( void )
{
F_196 () ;
F_197 () ;
F_198 ( V_185 ) ;
}
