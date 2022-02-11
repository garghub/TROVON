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
if ( V_2 -> V_10 [ 0 ] == V_11 ) {
V_9 = F_9 ( V_2 -> V_12 [ 0 ] . V_13 + V_8 ) ;
} else {
V_9 = F_10 ( V_2 -> V_12 [ ( V_8 ) >> 8 ] . V_14 + ( ( V_8 ) & 0xFF ) ) ;
}
F_11 () ;
return ( V_9 ) ;
}
void
F_12 ( struct V_1 * V_2 , long V_8 , T_1 V_15 )
{
if ( V_2 -> V_10 [ 0 ] == V_11 ) {
F_13 ( V_15 , V_2 -> V_12 [ 0 ] . V_13 + V_8 ) ;
} else {
F_14 ( V_15 , V_2 -> V_12 [ ( V_8 ) >> 8 ] . V_14 + ( V_8 & 0xFF ) ) ;
}
F_11 () ;
}
void
F_15 ( struct V_1 * V_2 , long V_8 , T_2 V_15 )
{
if ( V_2 -> V_10 [ 0 ] == V_11 ) {
F_16 ( V_15 , V_2 -> V_12 [ 0 ] . V_13 + V_8 ) ;
} else {
F_17 ( V_15 , V_2 -> V_12 [ ( V_8 ) >> 8 ] . V_14 + ( V_8 & 0xFF ) ) ;
}
F_11 () ;
}
void
F_18 ( struct V_1 * V_2 , long V_8 , T_1 * V_16 , int V_17 )
{
int V_18 ;
for ( V_18 = 0 ; V_18 < V_17 ; V_18 ++ )
F_12 ( V_2 , V_8 , * V_16 ++ ) ;
}
void
F_19 ( struct V_1 * V_2 , long V_8 , T_1 * V_16 , int V_17 )
{
int V_18 ;
for ( V_18 = 0 ; V_18 < V_17 ; V_18 ++ )
* V_16 ++ = F_8 ( V_2 , V_8 ) ;
}
T_3
F_20 ( T_4 V_19 , int V_20 , int V_21 )
{
switch ( V_21 ) {
case 1 :
{
T_1 V_22 ;
F_21 ( V_19 , V_20 , & V_22 ) ;
return ( V_22 ) ;
}
case 2 :
{
T_2 V_22 ;
F_22 ( V_19 , V_20 , & V_22 ) ;
return ( V_22 ) ;
}
case 4 :
{
T_3 V_22 ;
F_23 ( V_19 , V_20 , & V_22 ) ;
return ( V_22 ) ;
}
default:
F_24 ( L_2 ) ;
return ( 0 ) ;
}
}
void
F_25 ( T_4 V_19 , int V_20 , T_3 V_23 , int V_21 )
{
switch ( V_21 ) {
case 1 :
F_26 ( V_19 , V_20 , V_23 ) ;
break;
case 2 :
F_27 ( V_19 , V_20 , V_23 ) ;
break;
case 4 :
F_28 ( V_19 , V_20 , V_23 ) ;
break;
default:
F_24 ( L_3 ) ;
}
}
static void
F_29 ( struct V_1 * V_2 , struct V_3 * V_3 )
{
struct V_24 * V_25 ;
V_25 = V_3 -> V_26 ;
F_30 ( V_2 , V_3 , V_27 ) ;
F_31 ( V_25 ) ;
}
static const char *
F_32 ( struct V_28 * V_5 )
{
static char V_29 [ 512 ] ;
char V_30 [ 256 ] ;
char * V_31 ;
struct V_1 * V_2 ;
V_31 = & V_29 [ 0 ] ;
V_2 = * (struct V_1 * * ) V_5 -> V_32 ;
memset ( V_31 , 0 , sizeof( V_29 ) ) ;
strcpy ( V_31 , L_4 V_33 L_5
L_6 ) ;
strcat ( V_31 , V_2 -> V_34 ) ;
strcat ( V_31 , L_7
L_8 ) ;
F_33 ( V_2 , V_30 ) ;
strcat ( V_31 , V_30 ) ;
return ( V_31 ) ;
}
static int
F_34 ( struct V_24 * V_25 , void (* F_35) ( struct V_24 * ) )
{
struct V_1 * V_2 ;
struct V_35 * V_36 = F_36 ( V_25 -> V_37 ) ;
int V_38 = V_39 ;
V_2 = * (struct V_1 * * ) V_25 -> V_37 -> V_5 -> V_32 ;
V_25 -> F_35 = F_35 ;
V_25 -> V_40 = V_41 << 16 ;
V_38 = F_37 ( V_2 , V_36 , V_25 ) ;
return V_38 ;
}
int
F_38 ( struct V_42 * V_43 )
{
struct V_1 * V_2 =
* ( (struct V_1 * * ) F_39 ( & V_43 -> V_36 ) -> V_32 ) ;
struct V_44 * V_45 = V_2 -> V_46 ;
unsigned long V_47 ;
struct V_42 * * V_48 = F_40 ( V_43 ) ;
struct V_49 V_50 ;
struct V_51 * V_52 ;
struct V_53 * V_54 ;
char V_55 = V_43 -> V_55 + 'A' ;
F_41 ( V_2 , & V_47 ) ;
F_42 ( * V_48 != NULL ) ;
* V_48 = V_43 ;
if ( V_45 ) {
int V_47 = V_45 -> V_56 [ V_43 -> V_57 ] ;
V_52 = F_43 ( V_2 , 'A' , V_2 -> V_58 ,
V_43 -> V_57 , & V_54 ) ;
if ( ( V_47 & V_59 ) == 0 ) {
F_44 ( V_43 ) = 0 ;
} else {
if ( ( V_2 -> V_60 & V_61 ) == 0 )
F_45 ( V_43 ) = 0 ;
}
if ( ( V_47 & V_62 ) == 0 )
F_46 ( V_43 ) = 0 ;
F_47 ( V_43 ) = ( V_47 & V_63 ) ? 1 : 0 ;
F_48 ( V_43 ) = V_52 -> V_64 . V_65 ;
F_49 ( V_43 ) = V_52 -> V_64 . V_66 ;
}
V_52 = F_43 ( V_2 , V_55 , V_2 -> V_58 ,
V_43 -> V_57 , & V_54 ) ;
F_50 ( & V_50 , V_2 -> V_58 , V_43 -> V_57 ,
V_67 , V_55 ,
V_68 ) ;
F_51 ( V_2 , & V_50 , 0 , 0 , 0 ,
V_69 , FALSE ) ;
F_52 ( V_2 , & V_50 , V_70 ,
V_69 , FALSE ) ;
F_53 ( V_2 , & V_47 ) ;
return 0 ;
}
static void
F_54 ( struct V_42 * V_43 )
{
struct V_42 * * V_48 = F_40 ( V_43 ) ;
* V_48 = NULL ;
}
static int
F_55 ( struct V_71 * V_72 )
{
struct V_1 * V_2 =
* ( (struct V_1 * * ) V_72 -> V_5 -> V_32 ) ;
struct V_35 * V_36 ;
if ( V_73 )
F_2 ( L_9 , F_56 ( V_2 ) , V_72 -> V_57 ) ;
V_36 = F_36 ( V_72 ) ;
memset ( V_36 , 0 , sizeof( * V_36 ) ) ;
V_36 -> V_74 = 1 ;
V_36 -> V_75 = 0 ;
return ( 0 ) ;
}
static int
F_57 ( struct V_71 * V_72 )
{
struct V_1 * V_2 ;
V_2 = * ( (struct V_1 * * ) V_72 -> V_5 -> V_32 ) ;
if ( V_73 )
F_58 ( V_76 , V_72 , L_10 ) ;
F_59 ( V_72 ) ;
if ( ! F_60 ( V_72 -> V_77 ) )
F_61 ( V_72 ) ;
return 0 ;
}
static int
F_62 ( struct V_71 * V_72 , struct V_78 * V_79 ,
T_5 V_80 , int V_81 [] )
{
T_1 * V_82 ;
int V_83 ;
int V_84 ;
int V_85 ;
int V_86 ;
int V_87 ;
struct V_1 * V_2 ;
V_2 = * ( (struct V_1 * * ) V_72 -> V_5 -> V_32 ) ;
V_82 = F_63 ( V_79 ) ;
if ( V_82 ) {
V_86 = F_64 ( V_82 , V_80 ,
& V_81 [ 2 ] , & V_81 [ 0 ] , & V_81 [ 1 ] ) ;
F_65 ( V_82 ) ;
if ( V_86 != - 1 )
return ( V_86 ) ;
}
V_83 = 64 ;
V_84 = 32 ;
V_85 = F_66 ( V_80 , V_83 , V_84 ) ;
if ( V_88 != 0 )
V_87 = 1 ;
else
V_87 = ( V_2 -> V_47 & V_89 ) != 0 ;
if ( V_87 && V_85 >= 1024 ) {
V_83 = 255 ;
V_84 = 63 ;
V_85 = F_66 ( V_80 , V_83 , V_84 ) ;
}
V_81 [ 0 ] = V_83 ;
V_81 [ 1 ] = V_84 ;
V_81 [ 2 ] = V_85 ;
return ( 0 ) ;
}
static int
F_67 ( struct V_24 * V_25 )
{
int error ;
error = F_68 ( V_25 ) ;
return error ;
}
static int
F_69 ( struct V_24 * V_25 )
{
struct V_1 * V_2 ;
struct V_35 * V_36 ;
struct V_3 * V_90 ;
T_6 V_91 ;
int V_22 = V_92 ;
int V_93 ;
int V_94 ;
struct V_51 * V_52 ;
struct V_53 * V_54 ;
unsigned long V_47 ;
F_70 ( V_95 ) ;
V_90 = NULL ;
V_93 = FALSE ;
V_94 = FALSE ;
V_2 = * (struct V_1 * * ) V_25 -> V_37 -> V_5 -> V_32 ;
F_71 ( V_76 , V_25 ,
L_11 ) ;
F_2 ( L_12 ) ;
for ( V_91 = 0 ; V_91 < V_25 -> V_96 ; V_91 ++ )
F_2 ( L_13 , V_25 -> V_97 [ V_91 ] ) ;
F_2 ( L_5 ) ;
V_36 = F_36 ( V_25 -> V_37 ) ;
if ( V_36 == NULL ) {
F_71 ( V_76 , V_25 , L_14 ) ;
return V_92 ;
}
V_90 = F_72 ( V_2 , V_98 ) ;
if ( ! V_90 ) {
F_71 ( V_76 , V_25 , L_15 ) ;
return V_99 ;
}
V_52 = F_43 ( V_2 , 'A' , V_2 -> V_58 ,
V_25 -> V_37 -> V_57 , & V_54 ) ;
V_90 -> V_26 = V_25 ;
V_90 -> V_4 -> V_36 = V_36 ;
V_90 -> V_100 = 0 ;
F_73 ( V_90 , 0 ) ;
F_74 ( V_90 , 0 ) ;
V_90 -> V_4 -> V_101 = 0 ;
V_90 -> V_102 -> V_103 = 0 ;
V_90 -> V_102 -> V_104 = F_75 ( V_2 , V_25 ) ;
V_90 -> V_102 -> V_105 = V_25 -> V_37 -> V_105 ;
V_90 -> V_102 -> V_106 = 0 ;
V_90 -> V_102 -> V_107 = V_108 ;
V_90 -> V_47 |= V_109 | V_110 | V_111 ;
if ( ( V_52 -> V_112 . V_113 & V_114 ) != 0 ) {
V_90 -> V_47 |= V_115 ;
} else {
V_90 -> V_102 -> V_103 |= V_116 ;
}
V_36 -> V_74 -- ;
V_36 -> V_117 ++ ;
V_36 -> V_118 ++ ;
F_41 ( V_2 , & V_47 ) ;
F_76 ( & V_2 -> V_119 , V_90 , V_120 ) ;
F_77 ( V_2 , V_90 ) ;
V_2 -> V_4 -> V_121 = & V_95 ;
F_53 ( V_2 , & V_47 ) ;
F_2 ( L_16 , F_56 ( V_2 ) ) ;
if ( ! F_78 ( & V_95 , 5 * V_122 ) ) {
F_41 ( V_2 , & V_47 ) ;
V_2 -> V_4 -> V_121 = NULL ;
F_53 ( V_2 , & V_47 ) ;
F_2 ( L_17 ,
F_56 ( V_2 ) , V_36 -> V_117 ) ;
V_22 = V_99 ;
}
F_2 ( L_18 , F_56 ( V_2 ) , V_22 ) ;
return ( V_22 ) ;
}
static int
F_79 ( struct V_24 * V_25 )
{
struct V_1 * V_2 ;
int V_123 ;
unsigned long V_47 ;
V_2 = * (struct V_1 * * ) V_25 -> V_37 -> V_5 -> V_32 ;
#ifdef F_80
if ( ( V_124 & V_125 ) != 0 )
F_2 ( L_19 ,
F_56 ( V_2 ) , V_25 ) ;
#endif
F_41 ( V_2 , & V_47 ) ;
V_123 = F_81 ( V_2 , F_82 ( V_25 ) + 'A' ,
TRUE ) ;
F_53 ( V_2 , & V_47 ) ;
if ( V_73 )
F_2 ( L_20
L_21 , F_56 ( V_2 ) , V_123 ) ;
return ( V_92 ) ;
}
int
F_83 ( struct V_1 * V_2 , T_7 V_126 ,
T_8 V_127 , T_8 V_128 ,
T_9 V_129 , T_9 V_130 ,
T_10 * V_131 , void * V_132 ,
T_8 V_133 , int V_134 ,
T_8 V_135 , int V_47 , T_7 * V_136 )
{
T_7 V_137 ;
V_137 = F_84 ( sizeof( * V_137 ) , V_138 ) ;
if ( V_137 == NULL )
return ( V_139 ) ;
V_137 -> V_127 = V_127 ;
V_137 -> V_128 = V_128 ;
V_137 -> V_133 = V_133 ;
* V_136 = V_137 ;
return ( 0 ) ;
}
void
F_85 ( struct V_1 * V_2 , T_7 V_137 )
{
F_65 ( V_137 ) ;
}
int
F_86 ( struct V_1 * V_2 , T_7 V_137 , void * * V_140 ,
int V_47 , T_11 * V_141 )
{
* V_140 = F_87 ( V_2 -> V_142 ,
V_137 -> V_133 , V_141 ) ;
if ( * V_140 == NULL )
return ( V_139 ) ;
return ( 0 ) ;
}
void
F_88 ( struct V_1 * V_2 , T_7 V_137 ,
void * V_140 , T_11 V_143 )
{
F_89 ( V_2 -> V_142 , V_137 -> V_133 ,
V_140 , V_143 ) ;
}
int
F_90 ( struct V_1 * V_2 , T_7 V_137 , T_11 V_143 ,
void * V_144 , T_8 V_145 , T_12 * V_146 ,
void * V_147 , int V_47 )
{
T_13 V_148 ;
V_148 . V_149 = V_143 ;
V_148 . V_150 = V_137 -> V_133 ;
V_146 ( V_147 , & V_148 , 1 , 0 ) ;
return ( 0 ) ;
}
void
F_91 ( struct V_1 * V_2 , T_7 V_137 , T_11 V_143 )
{
}
int
F_92 ( struct V_1 * V_2 , T_7 V_137 , T_11 V_143 )
{
return ( 0 ) ;
}
static void
F_93 ( T_14 V_151 , int V_152 , int V_153 , T_15 V_23 )
{
if ( ( V_152 >= 0 )
&& ( V_152 < F_94 ( V_154 ) ) ) {
T_1 * V_155 ;
V_155 = ( T_1 * ) & V_154 [ V_152 ] ;
V_155 [ V_151 ] = V_23 & 0xFFFF ;
if ( V_73 )
F_2 ( L_22 , V_152 , V_151 , V_23 ) ;
}
}
static void
F_95 ( char * V_156 )
{
int V_10 , V_18 , V_157 ;
V_10 = F_96 ( V_156 + 1 , NULL , 0 ) & 0xff ;
F_2 ( L_23 , V_10 ) ;
for ( V_18 = 0 ; V_18 < F_94 ( V_158 ) ; V_18 ++ ) {
for ( V_157 = 0 ; V_157 < V_159 ; V_157 ++ ) {
V_158 [ V_18 ] . V_160 [ V_157 ] = V_10 ;
}
}
}
static void
F_97 ( T_14 V_161 , int V_152 , int V_153 , T_15 V_23 )
{
if ( ( V_152 >= 0 ) && ( V_153 >= 0 )
&& ( V_152 < F_94 ( V_158 ) )
&& ( V_153 < V_159 ) ) {
V_158 [ V_152 ] . V_160 [ V_153 ] = V_23 & 0x1FF ;
if ( V_73 )
F_2 ( L_24 , V_152 , V_153 , V_23 ) ;
}
}
static char *
F_98 ( char * V_162 , char * V_163 , char * V_164 , int V_165 ,
void (* F_99)( T_14 , int , int , T_15 ) ,
T_14 V_166 )
{
char * V_167 ;
char * V_168 ;
int V_18 ;
int V_152 ;
int V_153 ;
int V_95 ;
char V_169 [] = { '.' , ',' , '{' , '}' , '\0' } ;
if ( * V_163 != ':' )
return ( V_163 ) ;
V_163 ++ ;
V_152 = - 1 ;
V_153 = - 1 ;
V_95 = FALSE ;
V_167 = strchr ( V_163 , '\0' ) ;
if ( V_167 < V_164 )
* V_167 = ',' ;
while ( ! V_95 ) {
switch ( * V_163 ) {
case '{' :
if ( V_152 == - 1 ) {
V_152 = 0 ;
} else {
if ( V_165 > 1 ) {
if ( V_153 == - 1 )
V_153 = 0 ;
} else {
F_2 ( L_25 ,
V_162 ) ;
V_95 = TRUE ;
}
}
V_163 ++ ;
break;
case '}' :
if ( V_153 != - 1 )
V_153 = - 1 ;
else if ( V_152 != - 1 )
V_152 = - 1 ;
V_163 ++ ;
break;
case ',' :
case '.' :
if ( V_152 == - 1 )
V_95 = TRUE ;
else if ( V_153 >= 0 )
V_153 ++ ;
else if ( V_152 >= 0 )
V_152 ++ ;
V_163 ++ ;
break;
case '\0' :
V_95 = TRUE ;
break;
default:
V_167 = V_164 ;
for ( V_18 = 0 ; V_169 [ V_18 ] ; V_18 ++ ) {
V_168 = strchr ( V_163 , V_169 [ V_18 ] ) ;
if ( ( V_168 ) && ( V_168 < V_167 ) )
V_167 = V_168 ;
}
F_99 ( V_166 , V_152 , V_153 ,
F_100 ( V_163 , NULL , 0 ) ) ;
V_163 = V_167 ;
break;
}
}
return ( V_163 ) ;
}
static int
F_101 ( char * V_170 )
{
int V_18 , V_171 ;
char * V_156 ;
char * V_164 ;
static const struct {
const char * V_172 ;
T_3 * V_173 ;
} V_174 [] = {
{ L_26 , & V_88 } ,
{ L_27 , & V_175 } ,
{ L_28 , & V_176 } ,
{ L_29 , & V_177 } ,
#ifdef F_80
{ L_30 , & V_124 } ,
#endif
{ L_31 , & V_178 } ,
{ L_32 , & V_179 } ,
{ L_33 , & V_180 } ,
{ L_34 , NULL } ,
{ L_35 , NULL } ,
{ L_36 , NULL } ,
{ L_37 , NULL } ,
{ L_38 , NULL } ,
{ L_39 , & V_181 } ,
} ;
V_164 = strchr ( V_170 , '\0' ) ;
V_171 = 0 ;
while ( ( V_156 = F_102 ( & V_170 , L_40 ) ) != NULL ) {
if ( * V_156 == '\0' )
continue;
for ( V_18 = 0 ; V_18 < F_94 ( V_174 ) ; V_18 ++ ) {
V_171 = strlen ( V_174 [ V_18 ] . V_172 ) ;
if ( strncmp ( V_174 [ V_18 ] . V_172 , V_156 , V_171 ) == 0 )
break;
}
if ( V_18 == F_94 ( V_174 ) )
continue;
if ( strncmp ( V_156 , L_35 , V_171 ) == 0 ) {
F_95 ( V_156 + V_171 ) ;
} else if ( strncmp ( V_156 , L_34 , V_171 ) == 0 ) {
V_170 = F_98 ( L_34 , V_156 + V_171 , V_164 ,
2 , F_97 , 0 ) ;
} else if ( strncmp ( V_156 , L_36 , V_171 ) == 0 ) {
V_170 = F_98 ( L_36 ,
V_156 + V_171 , V_164 , 1 , F_93 ,
V_182 ) ;
} else if ( strncmp ( V_156 , L_37 , V_171 ) == 0 ) {
V_170 = F_98 ( L_37 ,
V_156 + V_171 , V_164 , 1 , F_93 ,
V_183 ) ;
} else if ( strncmp ( V_156 , L_38 , V_171 ) == 0 ) {
V_170 = F_98 ( L_38 ,
V_156 + V_171 , V_164 , 1 , F_93 ,
V_184 ) ;
} else if ( V_156 [ V_171 ] == ':' ) {
* ( V_174 [ V_18 ] . V_173 ) = F_96 ( V_156 + V_171 + 1 , NULL , 0 ) ;
} else if ( ! strncmp ( V_156 , L_28 , V_171 ) ) {
* ( V_174 [ V_18 ] . V_173 ) = 1 ;
} else {
* ( V_174 [ V_18 ] . V_173 ) ^= 0xFFFFFFFF ;
}
}
return 1 ;
}
int
F_103 ( struct V_1 * V_2 , struct V_185 * V_186 )
{
char V_144 [ 80 ] ;
struct V_28 * V_5 ;
char * V_187 ;
T_14 V_170 ;
int V_22 ;
V_186 -> V_172 = V_2 -> V_34 ;
V_5 = F_104 ( V_186 , sizeof( struct V_1 * ) ) ;
if ( V_5 == NULL )
return ( V_139 ) ;
* ( (struct V_1 * * ) V_5 -> V_32 ) = V_2 ;
V_2 -> V_4 -> V_5 = V_5 ;
V_5 -> V_188 = V_189 ;
V_5 -> V_190 = 2 ;
V_5 -> V_191 = V_192 ;
V_5 -> V_193 = V_2 -> V_58 ;
V_5 -> V_194 = V_2 -> V_4 -> V_194 ;
V_5 -> V_195 = ( V_2 -> V_60 & V_196 ) ? 16 : 8 ;
V_5 -> V_197 = V_198 ;
V_5 -> V_199 = 0 ;
V_5 -> V_191 = V_192 ;
F_41 ( V_2 , & V_170 ) ;
F_105 ( V_2 , V_200 ++ ) ;
F_53 ( V_2 , & V_170 ) ;
sprintf ( V_144 , L_41 , V_5 -> V_6 ) ;
V_187 = F_84 ( strlen ( V_144 ) + 1 , V_138 ) ;
if ( V_187 != NULL ) {
strcpy ( V_187 , V_144 ) ;
F_106 ( V_2 , V_187 ) ;
}
V_5 -> V_201 = V_2 -> V_202 ;
F_107 ( V_2 ) ;
F_108 ( V_2 , TRUE ) ;
V_5 -> V_203 = V_204 ;
V_22 = F_109 ( V_5 , & V_2 -> V_142 -> V_36 ) ;
if ( V_22 ) {
F_2 ( V_205 L_42 ) ;
F_110 ( V_5 ) ;
return V_22 ;
}
F_111 ( V_5 ) ;
return 0 ;
}
static void
F_107 ( struct V_1 * V_2 )
{
T_6 V_206 ;
T_6 V_207 ;
unsigned long V_170 ;
V_206 = 0 ;
V_207 = 0 ;
if ( V_175 != 0 )
V_2 -> V_47 &= ~ V_208 ;
if ( ( V_2 -> V_47 & V_208 ) != 0 )
F_81 ( V_2 , 'A' , TRUE ) ;
else
V_207 = ( V_2 -> V_60 & V_196 ) ? 16 : 8 ;
F_41 ( V_2 , & V_170 ) ;
for (; V_206 < V_207 ; V_206 ++ ) {
struct V_49 V_50 ;
struct V_51 * V_52 ;
struct V_53 * V_54 ;
V_52 = F_43 ( V_2 , 'A' , V_2 -> V_58 ,
V_206 , & V_54 ) ;
F_50 ( & V_50 , V_2 -> V_58 , V_206 ,
V_67 , 'A' , V_68 ) ;
F_112 ( V_2 , & V_50 , V_54 ,
V_52 , V_209 ) ;
}
F_53 ( V_2 , & V_170 ) ;
if ( ( V_2 -> V_47 & V_208 ) != 0 ) {
F_113 ( V_2 ) ;
F_114 ( V_210 ) ;
F_115 ( V_2 ) ;
}
}
int
F_116 ( struct V_1 * V_2 , void * V_211 )
{
V_2 -> V_4 =
F_84 ( sizeof( struct V_212 ) , V_138 ) ;
if ( V_2 -> V_4 == NULL )
return ( V_139 ) ;
memset ( V_2 -> V_4 , 0 , sizeof( struct V_212 ) ) ;
V_2 -> V_4 -> V_194 = V_213 ;
F_117 ( V_2 ) ;
V_2 -> V_214 = ( V_180 & 0x3 ) << 4 ;
return ( 0 ) ;
}
void
F_118 ( struct V_1 * V_2 )
{
struct V_42 * V_43 ;
int V_18 ;
if ( V_2 -> V_4 != NULL ) {
for ( V_18 = 0 ; V_18 < V_159 ; V_18 ++ ) {
V_43 = V_2 -> V_4 -> V_43 [ V_18 ] ;
if ( V_43 != NULL ) {
V_2 -> V_4 -> V_43 [ V_18 ] = NULL ;
}
}
if ( V_2 -> V_4 -> V_194 != V_213 )
F_119 ( V_2 -> V_4 -> V_194 , V_2 ) ;
if ( V_2 -> V_10 [ 0 ] == V_215
&& V_2 -> V_12 [ 0 ] . V_14 != 0 )
F_120 ( V_2 -> V_12 [ 0 ] . V_14 , 256 ) ;
if ( V_2 -> V_10 [ 1 ] == V_215
&& V_2 -> V_12 [ 1 ] . V_14 != 0 )
F_120 ( V_2 -> V_12 [ 1 ] . V_14 , 256 ) ;
if ( V_2 -> V_10 [ 0 ] == V_11
&& V_2 -> V_12 [ 0 ] . V_13 != NULL ) {
F_121 ( V_2 -> V_12 [ 0 ] . V_13 ) ;
F_122 ( V_2 -> V_4 -> V_216 ,
0x1000 ) ;
}
if ( V_2 -> V_4 -> V_5 )
F_110 ( V_2 -> V_4 -> V_5 ) ;
F_65 ( V_2 -> V_4 ) ;
}
}
void
F_123 ( struct V_1 * V_2 )
{
if ( V_2 -> V_202 < F_94 ( V_154 ) ) {
const struct V_217 * V_218 ;
V_218 = & V_154 [ V_2 -> V_202 ] ;
if ( V_218 -> V_219 != V_220 )
F_124 ( V_2 , V_218 -> V_219 ) ;
if ( V_218 -> V_221 != V_222 )
F_125 ( V_2 , V_218 -> V_221 ) ;
if ( V_218 -> V_223 != V_224 )
F_126 ( V_2 , V_218 -> V_223 ) ;
}
}
void
F_127 ( struct V_1 * V_2 , struct V_3 * V_3 )
{
F_128 ( V_2 , F_4 ( V_2 , V_3 ) ,
F_3 ( V_2 , V_3 ) ,
F_5 ( V_3 ) , V_225 ,
V_226 , V_227 ) ;
}
void
F_129 ( struct V_1 * V_2 , struct V_71 * V_72 ,
struct V_49 * V_50 , T_16 V_228 )
{
struct V_35 * V_36 ;
int V_229 ;
int V_230 ;
if ( V_72 == NULL )
return;
V_36 = F_36 ( V_72 ) ;
if ( V_36 == NULL )
return;
V_229 = V_36 -> V_47 & ( V_231 | V_232 ) ;
switch ( V_228 ) {
default:
case V_233 :
V_230 = 0 ;
break;
case V_234 :
V_230 = V_231 ;
break;
case V_235 :
V_230 = V_232 ;
break;
}
if ( ( V_36 -> V_47 & V_236 ) == 0
&& ( V_229 != V_230 )
&& ( V_36 -> V_117 != 0 ) ) {
V_36 -> V_47 |= V_236 ;
V_36 -> V_237 ++ ;
}
V_36 -> V_47 &= ~ ( V_231 | V_232 | V_238 ) ;
if ( V_230 ) {
T_6 V_239 ;
V_239 = F_130 ( V_2 , V_50 ) ;
if ( ! V_229 ) {
V_36 -> V_75 = V_239 ;
V_36 -> V_74 = V_36 -> V_75 - V_36 -> V_117 ;
}
if ( V_36 -> V_75 == 0 ) {
V_36 -> V_74 = 1 ;
} else if ( V_228 == V_235 ) {
V_36 -> V_47 |= V_232 ;
if ( V_178 != 0 )
V_36 -> V_47 |= V_238 ;
} else
V_36 -> V_47 |= V_231 ;
} else {
V_36 -> V_75 = 0 ;
V_36 -> V_74 = 1 - V_36 -> V_117 ;
}
switch ( ( V_36 -> V_47 & ( V_231 | V_232 ) ) ) {
case V_231 :
F_131 ( V_72 , V_240 ) ;
F_132 ( V_72 , V_36 -> V_74 + V_36 -> V_117 ) ;
break;
case V_232 :
F_131 ( V_72 , V_241 ) ;
F_132 ( V_72 , V_36 -> V_74 + V_36 -> V_117 ) ;
break;
default:
F_133 ( V_72 , 1 ) ;
break;
}
}
int
F_128 ( struct V_1 * V_2 , int V_242 , char V_55 ,
int V_105 , T_6 V_243 , T_17 V_244 , T_3 V_245 )
{
return 0 ;
}
static T_6
F_130 ( struct V_1 * V_2 , struct V_49 * V_50 )
{
static int V_246 ;
T_6 V_10 ;
V_10 = 0 ;
if ( ( V_2 -> V_247 & V_50 -> V_248 ) != 0 ) {
if ( V_2 -> V_202 >= F_94 ( V_158 ) ) {
if ( V_246 == 0 ) {
F_2 ( V_205
L_43
L_44
L_45
L_46 ) ;
V_246 ++ ;
}
V_10 = V_189 ;
} else {
T_18 * V_249 ;
V_249 = & V_158 [ V_2 -> V_202 ] ;
V_10 = V_249 -> V_160 [ V_50 -> V_250 ] ;
if ( V_10 > V_189 )
V_10 = V_189 ;
}
}
return ( V_10 ) ;
}
static void
F_59 ( struct V_71 * V_72 )
{
struct V_49 V_50 ;
T_6 V_10 ;
struct V_1 * V_2 = * ( (struct V_1 * * ) V_72 -> V_5 -> V_32 ) ;
F_50 ( & V_50 ,
V_2 -> V_58 ,
V_72 -> V_77 -> V_57 , V_72 -> V_105 ,
V_72 -> V_77 -> V_55 == 0 ? 'A' : 'B' ,
V_68 ) ;
V_10 = F_130 ( V_2 , & V_50 ) ;
if ( V_10 != 0 && V_72 -> V_251 != 0 ) {
F_129 ( V_2 , V_72 , & V_50 , V_235 ) ;
F_134 ( V_2 , V_50 . V_55 , V_50 . V_242 ,
V_50 . V_105 , V_252 ) ;
F_135 ( V_2 , & V_50 ) ;
F_2 ( L_47 , V_10 ) ;
} else {
F_129 ( V_2 , V_72 , & V_50 , V_233 ) ;
F_134 ( V_2 , V_50 . V_55 , V_50 . V_242 ,
V_50 . V_105 , V_252 ) ;
}
}
static int
F_37 ( struct V_1 * V_2 , struct V_35 * V_36 ,
struct V_24 * V_25 )
{
struct V_3 * V_3 ;
struct V_253 * V_102 ;
struct V_51 * V_52 ;
struct V_53 * V_54 ;
T_6 V_254 ;
T_2 V_255 ;
unsigned long V_47 ;
int V_256 ;
V_256 = F_136 ( V_25 ) ;
if ( V_256 < 0 )
return V_39 ;
F_41 ( V_2 , & V_47 ) ;
V_52 = F_43 ( V_2 , 'A' , V_2 -> V_58 ,
V_25 -> V_37 -> V_57 , & V_54 ) ;
if ( ( V_36 -> V_47 & ( V_232 | V_231 ) ) == 0
|| ( V_52 -> V_112 . V_113 & V_114 ) != 0 ) {
V_254 = V_98 ;
} else {
V_254 = F_137 ( V_25 -> V_37 -> V_57 ,
V_25 -> V_37 -> V_105 ) ;
}
if ( ( V_3 = F_72 ( V_2 , V_254 ) ) == NULL ) {
V_2 -> V_47 |= V_257 ;
F_53 ( V_2 , & V_47 ) ;
F_31 ( V_25 ) ;
return V_39 ;
}
V_3 -> V_26 = V_25 ;
V_3 -> V_4 -> V_36 = V_36 ;
V_102 = V_3 -> V_102 ;
V_25 -> V_258 = ( char * ) V_3 ;
V_102 -> V_103 = 0 ;
V_102 -> V_104 = F_75 ( V_2 , V_25 ) ;
V_102 -> V_105 = V_25 -> V_37 -> V_105 ;
V_3 -> V_102 -> V_107 = 0 ;
V_255 = F_138 ( V_2 , V_3 ) ;
if ( ( V_2 -> V_247 & V_255 ) != 0 )
V_102 -> V_103 |= V_259 ;
if ( ( V_52 -> V_112 . V_113 & V_114 ) != 0 )
V_3 -> V_47 |= V_115 ;
if ( ( V_54 -> V_260 & V_255 ) != 0 ) {
V_3 -> V_47 |= V_261 ;
V_3 -> V_102 -> V_103 |= V_116 ;
}
if ( ( V_36 -> V_47 & ( V_232 | V_231 ) ) != 0 ) {
int V_262 ;
T_1 V_263 [ 2 ] ;
V_262 = F_139 ( V_25 , V_263 ) ;
if ( V_262 && V_263 [ 0 ] != V_240 ) {
V_102 -> V_103 |= V_263 [ 0 ] ;
if ( V_263 [ 0 ] == V_241 )
V_36 -> V_264 = 0 ;
} else
if ( V_36 -> V_264 == V_265
&& ( V_36 -> V_47 & V_232 ) != 0 ) {
V_102 -> V_103 |= V_241 ;
V_36 -> V_264 = 0 ;
} else {
V_102 -> V_103 |= V_240 ;
}
}
V_102 -> V_106 = V_25 -> V_96 ;
memcpy ( V_102 -> V_266 . V_267 . V_268 , V_25 -> V_97 , V_102 -> V_106 ) ;
V_3 -> V_4 -> V_101 = 0 ;
F_73 ( V_3 , 0 ) ;
F_74 ( V_3 , 0 ) ;
V_3 -> V_100 = 0 ;
if ( V_256 > 0 ) {
void * V_269 = V_3 -> V_270 ;
struct V_271 * V_272 ;
int V_18 ;
V_3 -> V_4 -> V_101 = 0 ;
F_140 (cmd, cur_seg, nseg, i) {
T_9 V_273 ;
T_8 V_274 ;
V_273 = F_141 ( V_272 ) ;
V_274 = F_142 ( V_272 ) ;
V_3 -> V_4 -> V_101 += V_274 ;
V_269 = F_143 ( V_2 , V_3 , V_269 , V_273 , V_274 ,
V_18 == ( V_256 - 1 ) ) ;
}
}
F_76 ( & V_2 -> V_119 , V_3 , V_120 ) ;
V_36 -> V_74 -- ;
V_36 -> V_117 ++ ;
V_36 -> V_118 ++ ;
if ( ( V_36 -> V_47 & V_238 ) != 0 )
V_36 -> V_264 ++ ;
V_3 -> V_47 |= V_111 ;
F_77 ( V_2 , V_3 ) ;
F_53 ( V_2 , & V_47 ) ;
return 0 ;
}
T_19
F_144 ( int V_194 , void * V_275 )
{
struct V_1 * V_2 ;
T_14 V_47 ;
int V_276 ;
V_2 = (struct V_1 * ) V_275 ;
F_41 ( V_2 , & V_47 ) ;
V_276 = F_145 ( V_2 ) ;
F_53 ( V_2 , & V_47 ) ;
return F_146 ( V_276 ) ;
}
void
F_134 ( struct V_1 * V_2 , char V_55 ,
T_6 V_242 , T_6 V_105 , T_20 V_277 )
{
switch ( V_277 ) {
case V_252 :
{
char V_144 [ 80 ] ;
struct V_42 * V_43 ;
struct V_278 V_279 ;
struct V_51 * V_52 ;
struct V_53 * V_54 ;
unsigned int V_280 ;
F_42 ( V_242 == V_281 ) ;
V_279 . V_29 = V_144 ;
V_279 . V_282 = sizeof( V_144 ) ;
V_279 . V_66 = 0 ;
V_279 . V_283 = 0 ;
V_52 = F_43 ( V_2 , V_55 , V_2 -> V_58 ,
V_242 , & V_54 ) ;
if ( V_52 -> V_112 . V_65 != V_52 -> V_284 . V_65
|| V_52 -> V_112 . V_21 != V_52 -> V_284 . V_21
|| V_52 -> V_112 . V_66 != V_52 -> V_284 . V_66
|| V_52 -> V_112 . V_113 != V_52 -> V_284 . V_113 )
if ( V_73 == 0 )
break;
V_43 = V_2 -> V_4 -> V_43 [ V_242 ] ;
if ( V_43 == NULL )
break;
V_280 =
( F_147 ( V_43 ) ? V_285 : 0 )
+ ( F_148 ( V_43 ) ? V_286 : 0 )
+ ( F_149 ( V_43 ) ? V_114 : 0 )
+ ( F_150 ( V_43 ) ? V_287 : 0 )
+ ( F_151 ( V_43 ) ? V_288 : 0 )
+ ( F_45 ( V_43 ) ? V_289 : 0 )
+ ( F_152 ( V_43 ) ? V_290 : 0 )
+ ( F_153 ( V_43 ) ? V_291 : 0 ) ;
if ( V_52 -> V_112 . V_65 == F_154 ( V_43 )
&& V_52 -> V_112 . V_21 == F_155 ( V_43 )
&& V_52 -> V_112 . V_66 == F_156 ( V_43 )
&& V_52 -> V_112 . V_113 == V_280 )
if ( V_73 == 0 )
break;
F_154 ( V_43 ) = V_52 -> V_112 . V_65 ;
F_155 ( V_43 ) = V_52 -> V_112 . V_21 ;
F_156 ( V_43 ) = V_52 -> V_112 . V_66 ;
F_147 ( V_43 ) = V_52 -> V_112 . V_113 & V_285 ? 1 : 0 ;
F_148 ( V_43 ) = V_52 -> V_112 . V_113 & V_286 ? 1 : 0 ;
F_149 ( V_43 ) = V_52 -> V_112 . V_113 & V_114 ? 1 : 0 ;
F_150 ( V_43 ) = V_52 -> V_112 . V_113 & V_287 ? 1 : 0 ;
F_151 ( V_43 ) = V_52 -> V_112 . V_113 & V_288 ? 1 : 0 ;
F_45 ( V_43 ) = V_52 -> V_112 . V_113 & V_289 ? 1 : 0 ;
F_152 ( V_43 ) = V_52 -> V_112 . V_113 & V_290 ? 1 : 0 ;
F_153 ( V_43 ) = V_52 -> V_112 . V_113 & V_291 ? 1 : 0 ;
F_157 ( V_43 ) ;
break;
}
case V_292 :
{
F_158 ( V_105 != V_67 ) ;
F_159 ( V_2 -> V_4 -> V_5 ,
V_55 - 'A' , V_242 ) ;
break;
}
case V_293 :
if ( V_2 -> V_4 -> V_5 != NULL ) {
F_160 ( V_2 -> V_4 -> V_5 ,
V_55 - 'A' ) ;
}
break;
default:
F_24 ( L_48 ) ;
}
}
void
F_161 ( struct V_1 * V_2 , struct V_3 * V_3 )
{
struct V_24 * V_25 ;
struct V_35 * V_36 ;
if ( ( V_3 -> V_47 & V_111 ) == 0 ) {
F_2 ( L_49 , F_162 ( V_3 ) ) ;
F_163 ( V_2 ) ;
F_24 ( L_50 ) ;
}
F_164 ( V_3 , V_120 ) ;
V_25 = V_3 -> V_26 ;
V_36 = V_3 -> V_4 -> V_36 ;
V_36 -> V_117 -- ;
V_36 -> V_74 ++ ;
if ( ( V_25 -> V_40 & ( V_294 << 16 ) ) != 0 ) {
V_25 -> V_40 &= ~ ( V_294 << 16 ) ;
V_36 -> V_237 -- ;
}
F_29 ( V_2 , V_3 ) ;
V_25 -> V_295 [ 0 ] = 0 ;
if ( F_165 ( V_3 ) == V_41 ) {
T_3 V_296 ;
V_296 =
F_166 ( V_3 ) - F_167 ( V_3 ) ;
if ( ( V_3 -> V_47 & V_297 ) != 0 ) {
#ifdef F_80
if ( ( V_124 & V_298 ) != 0 ) {
F_1 ( V_2 , V_3 ) ;
F_2 ( L_51 ) ;
}
#endif
F_168 ( V_3 , V_299 ) ;
#ifdef F_169
} else if ( V_296 < V_3 -> V_26 -> V_300 ) {
T_6 V_18 ;
F_1 ( V_2 , V_3 ) ;
F_2 ( L_12 ) ;
for ( V_18 = 0 ; V_18 < V_3 -> V_26 -> V_96 ; V_18 ++ )
F_2 ( L_13 , V_3 -> V_26 -> V_97 [ V_18 ] ) ;
F_2 ( L_5 ) ;
F_1 ( V_2 , V_3 ) ;
F_2 ( L_52
L_53 ,
F_167 ( V_3 ) ,
F_166 ( V_3 ) ) ;
F_168 ( V_3 , V_301 ) ;
#endif
} else {
F_168 ( V_3 , V_302 ) ;
}
} else if ( F_165 ( V_3 ) == V_303 ) {
F_170 ( V_2 , V_25 -> V_37 , V_3 ) ;
}
if ( V_36 -> V_74 == 1
&& F_165 ( V_3 ) == V_302
&& F_171 ( V_3 ) != V_304 )
V_36 -> V_305 ++ ;
if ( ( V_36 -> V_74 + V_36 -> V_117 ) < V_36 -> V_75
&& V_36 -> V_305 > V_306 ) {
V_36 -> V_305 = 0 ;
V_36 -> V_74 ++ ;
}
if ( V_36 -> V_117 == 0 )
V_36 -> V_264 = 0 ;
if ( ( V_3 -> V_47 & V_110 ) != 0 ) {
F_2 ( L_54 ) ;
if ( F_165 ( V_3 ) == V_307
|| F_165 ( V_3 ) == V_308 )
F_168 ( V_3 , V_309 ) ;
if ( V_2 -> V_4 -> V_121 )
F_172 ( V_2 -> V_4 -> V_121 ) ;
}
F_173 ( V_2 , V_3 ) ;
F_174 ( V_2 , V_25 ) ;
}
static void
F_170 ( struct V_1 * V_2 ,
struct V_71 * V_72 , struct V_3 * V_3 )
{
struct V_49 V_50 ;
struct V_35 * V_36 = F_36 ( V_72 ) ;
F_50 ( & V_50 ,
V_2 -> V_58 ,
V_72 -> V_77 -> V_57 , V_72 -> V_105 ,
V_72 -> V_77 -> V_55 == 0 ? 'A' : 'B' ,
V_68 ) ;
switch ( F_171 ( V_3 ) ) {
default:
break;
case V_310 :
case V_311 :
{
struct V_24 * V_25 ;
V_25 = V_3 -> V_26 ;
if ( ( V_3 -> V_47 & ( V_312 | V_313 ) ) != 0 ) {
struct V_314 * V_315 ;
T_6 V_316 ;
T_6 V_317 ;
if ( V_3 -> V_47 & V_312 ) {
V_316 = F_175 ( sizeof( struct V_318 )
- F_176 ( V_3 ) ,
( T_14 ) V_319 ) ;
V_317 = 0 ;
} else {
V_315 = (struct V_314 * )
V_3 -> V_320 ;
V_316 = F_177 ( V_321 ,
F_178 ( V_315 -> V_322 ) ,
V_319 ) ;
V_317 = F_179 ( V_315 ) ;
}
memset ( V_25 -> V_295 , 0 , V_319 ) ;
memcpy ( V_25 -> V_295 ,
F_180 ( V_2 , V_3 )
+ V_317 , V_316 ) ;
V_25 -> V_40 |= ( V_323 << 24 ) ;
#ifdef F_80
if ( V_124 & V_324 ) {
int V_18 ;
F_2 ( L_55 ,
V_316 , V_317 ) ;
for ( V_18 = 0 ; V_18 < V_316 ; V_18 ++ ) {
if ( ( V_18 & 0xF ) == 0 )
F_2 ( L_5 ) ;
F_2 ( L_56 , V_25 -> V_295 [ V_18 ] ) ;
}
F_2 ( L_5 ) ;
}
#endif
}
break;
}
case V_304 :
V_36 -> V_305 = 0 ;
if ( V_36 -> V_117 != 0 ) {
V_36 -> V_74 = 0 ;
#ifdef F_80
if ( ( V_124 & V_325 ) != 0 ) {
F_1 ( V_2 , V_3 ) ;
F_2 ( L_57 ,
V_36 -> V_117 ) ;
}
#endif
if ( V_36 -> V_117 == V_36 -> V_326 ) {
V_36 -> V_327 ++ ;
if ( V_36 -> V_327
== V_328 ) {
V_36 -> V_75 = V_36 -> V_117 ;
F_1 ( V_2 , V_3 ) ;
F_2 ( L_58 ,
V_36 -> V_117 ) ;
}
} else {
V_36 -> V_326 = V_36 -> V_117 ;
V_36 -> V_327 = 0 ;
}
F_168 ( V_3 , V_227 ) ;
F_181 ( V_3 , V_329 ) ;
F_129 ( V_2 , V_72 , & V_50 ,
( V_36 -> V_47 & V_231 )
? V_234 : V_235 ) ;
break;
}
V_36 -> V_74 = 1 ;
F_129 ( V_2 , V_72 , & V_50 ,
( V_36 -> V_47 & V_231 )
? V_234 : V_235 ) ;
F_181 ( V_3 , V_330 ) ;
}
}
static void
F_174 ( struct V_1 * V_2 , struct V_24 * V_25 )
{
int V_245 ;
int V_331 = V_332 ;
int V_333 = 0 ;
int V_334 ;
V_245 = F_182 ( V_25 ) ;
switch ( V_245 ) {
case V_41 :
case V_302 :
V_331 = V_332 ;
break;
case V_335 :
V_331 = V_336 ;
case V_303 :
V_334 = F_183 ( V_25 ) ;
switch( V_334 ) {
case V_311 :
case V_310 :
if ( ( V_25 -> V_40 >> 24 ) != V_323 ) {
V_333 = 1 ;
} else {
struct V_318 * V_337 ;
V_337 = (struct V_318 * )
V_25 -> V_295 ;
if ( V_337 -> V_338 >= 5 &&
( V_337 -> V_339 == 0x47
|| V_337 -> V_339 == 0x48 ) )
V_333 = 1 ;
}
break;
default:
break;
}
break;
case V_308 :
V_331 = V_340 ;
break;
case V_341 :
V_331 = V_342 ;
break;
case V_343 :
case V_344 :
V_331 = V_345 ;
break;
case V_346 :
V_331 = V_347 ;
break;
case V_348 :
case V_307 :
V_331 = V_349 ;
break;
case V_299 :
V_331 = V_350 ;
V_333 = 1 ;
break;
case V_309 :
V_331 = V_351 ;
V_333 = 1 ;
break;
case V_352 :
case V_353 :
case V_301 :
V_331 = V_336 ;
V_333 = 1 ;
break;
case V_354 :
case V_355 :
case V_356 :
case V_357 :
case V_358 :
case V_359 :
case V_360 :
case V_361 :
V_331 = V_336 ;
break;
case V_227 :
V_331 = V_362 ;
break;
default:
V_331 = V_336 ;
break;
}
if ( V_333 ) {
F_2 ( L_59 ,
F_56 ( V_2 ) , V_245 , V_25 -> V_37 -> V_55 ,
V_25 -> V_37 -> V_57 , V_25 -> V_37 -> V_105 ) ;
}
F_184 ( V_25 , V_331 ) ;
V_25 -> F_35 ( V_25 ) ;
}
static void
F_113 ( struct V_1 * V_2 )
{
F_185 ( V_2 -> V_4 -> V_5 ) ;
}
static void
F_115 ( struct V_1 * V_2 )
{
F_186 ( V_2 -> V_4 -> V_5 ) ;
}
static int
F_68 ( struct V_24 * V_25 )
{
struct V_1 * V_2 ;
struct V_35 * V_36 ;
struct V_3 * V_363 ;
T_6 V_364 ;
T_6 V_365 ;
T_6 V_366 ;
T_6 V_367 ;
T_6 V_91 ;
int V_22 ;
int V_368 ;
int V_93 ;
int V_94 ;
int V_369 ;
T_21 V_370 ;
unsigned long V_47 ;
V_363 = NULL ;
V_93 = FALSE ;
V_94 = FALSE ;
V_2 = * (struct V_1 * * ) V_25 -> V_37 -> V_5 -> V_32 ;
F_71 ( V_76 , V_25 ,
L_60 ) ;
F_2 ( L_12 ) ;
for ( V_91 = 0 ; V_91 < V_25 -> V_96 ; V_91 ++ )
F_2 ( L_13 , V_25 -> V_97 [ V_91 ] ) ;
F_2 ( L_5 ) ;
F_41 ( V_2 , & V_47 ) ;
V_36 = F_36 ( V_25 -> V_37 ) ;
if ( V_36 == NULL ) {
F_71 ( V_76 , V_25 , L_14 ) ;
V_22 = V_92 ;
goto V_371;
}
F_187 (pending_scb, &ahd->pending_scbs, pending_links) {
if ( V_363 -> V_26 == V_25 )
break;
}
if ( V_363 == NULL ) {
F_71 ( V_76 , V_25 , L_61 ) ;
goto V_371;
}
if ( ( V_363 -> V_47 & V_110 ) != 0 ) {
V_22 = V_99 ;
goto V_95;
}
V_368 = F_188 ( V_2 ) ;
F_189 ( V_2 ) ;
V_93 = TRUE ;
if ( ( V_363 -> V_47 & V_111 ) == 0 ) {
F_71 ( V_76 , V_25 , L_62 ) ;
goto V_371;
}
F_2 ( L_63 ,
F_56 ( V_2 ) , V_368 ? L_64 : L_65 ) ;
F_163 ( V_2 ) ;
V_369 = TRUE ;
if ( F_190 ( V_2 , V_25 -> V_37 -> V_57 ,
V_25 -> V_37 -> V_55 + 'A' ,
V_25 -> V_37 -> V_105 ,
V_363 -> V_102 -> V_243 ,
V_68 , V_308 ,
V_372 ) > 0 ) {
F_2 ( L_66 ,
F_56 ( V_2 ) , V_25 -> V_37 -> V_55 ,
V_25 -> V_37 -> V_57 , V_25 -> V_37 -> V_105 ) ;
V_22 = V_92 ;
goto V_95;
}
V_370 = F_191 ( V_2 ) ;
F_192 ( V_2 , V_373 , V_373 ) ;
V_366 = F_8 ( V_2 , V_374 ) ;
V_364 = F_193 ( V_2 ) ;
V_365 = V_364 ;
if ( V_369 && ( F_8 ( V_2 , V_375 ) & V_376 ) == 0 ) {
struct V_3 * V_377 ;
V_377 = F_194 ( V_2 , V_365 ) ;
if ( V_377 == V_363 )
V_369 = FALSE ;
}
V_367 = F_8 ( V_2 , V_378 ) ;
if ( V_366 != V_379
&& F_162 ( V_363 ) == V_365 ) {
V_363 = F_194 ( V_2 , V_365 ) ;
V_363 -> V_47 |= V_110 | V_380 ;
F_12 ( V_2 , V_381 , V_382 ) ;
F_12 ( V_2 , V_383 , V_366 | V_384 ) ;
F_71 ( V_76 , V_25 , L_67 ) ;
V_94 = TRUE ;
} else if ( V_369 ) {
V_363 -> V_47 |= V_110 | V_380 ;
F_195 ( V_2 , F_162 ( V_363 ) ) ;
V_363 -> V_102 -> V_106 = 0 ;
V_363 -> V_102 -> V_385 = 0 ;
V_363 -> V_102 -> V_107 = V_386 ;
if ( ( V_363 -> V_47 & V_115 ) != 0 ) {
F_12 ( V_2 , V_387 ,
V_363 -> V_102 -> V_107 ) ;
} else {
V_363 -> V_102 -> V_103 |= V_116 | V_388 ;
F_12 ( V_2 , V_389 ,
F_8 ( V_2 , V_389 ) | V_116 ) ;
}
F_190 ( V_2 , V_25 -> V_37 -> V_57 ,
V_25 -> V_37 -> V_55 + 'A' , V_25 -> V_37 -> V_105 ,
V_225 , V_68 ,
V_227 , V_372 ) ;
F_196 ( V_2 , V_363 ) ;
F_195 ( V_2 , V_364 ) ;
F_1 ( V_2 , V_363 ) ;
F_2 ( L_68 ) ;
V_94 = TRUE ;
} else {
F_71 ( V_76 , V_25 , L_69 ) ;
V_22 = V_99 ;
goto V_95;
}
V_371:
V_22 = V_92 ;
V_95:
if ( V_93 )
F_197 ( V_2 ) ;
if ( V_94 ) {
F_70 ( V_95 ) ;
V_2 -> V_4 -> V_121 = & V_95 ;
F_53 ( V_2 , & V_47 ) ;
F_2 ( L_70 , F_56 ( V_2 ) ) ;
if ( ! F_78 ( & V_95 , 5 * V_122 ) ) {
F_41 ( V_2 , & V_47 ) ;
V_2 -> V_4 -> V_121 = NULL ;
F_53 ( V_2 , & V_47 ) ;
F_2 ( L_71 ,
F_56 ( V_2 ) , V_36 -> V_117 ) ;
V_22 = V_99 ;
}
F_2 ( L_72 ) ;
} else
F_53 ( V_2 , & V_47 ) ;
if ( V_22 != V_92 )
F_2 ( L_73 ,
F_56 ( V_2 ) , V_22 ) ;
return V_22 ;
}
static void F_198 ( struct V_42 * V_43 , int V_21 )
{
struct V_28 * V_390 = F_39 ( V_43 -> V_36 . V_126 ) ;
struct V_1 * V_2 = * ( (struct V_1 * * ) V_390 -> V_32 ) ;
struct V_49 V_50 ;
unsigned long V_47 ;
F_50 ( & V_50 , V_390 -> V_193 , V_43 -> V_57 , 0 ,
V_43 -> V_55 + 'A' , V_68 ) ;
F_41 ( V_2 , & V_47 ) ;
F_52 ( V_2 , & V_50 , V_21 , V_69 , FALSE ) ;
F_53 ( V_2 , & V_47 ) ;
}
static void F_199 ( struct V_42 * V_43 , int V_65 )
{
struct V_28 * V_390 = F_39 ( V_43 -> V_36 . V_126 ) ;
struct V_1 * V_2 = * ( (struct V_1 * * ) V_390 -> V_32 ) ;
struct V_53 * V_54 ;
struct V_51 * V_52
= F_43 ( V_2 ,
V_43 -> V_55 + 'A' ,
V_390 -> V_193 , V_43 -> V_57 , & V_54 ) ;
struct V_49 V_50 ;
unsigned int V_113 = V_52 -> V_284 . V_113 ;
unsigned int V_391 ;
unsigned long V_47 ;
unsigned long V_66 = V_52 -> V_284 . V_66 ;
#ifdef F_80
if ( ( V_124 & V_392 ) != 0 )
F_2 ( L_74 , F_56 ( V_2 ) , V_65 ) ;
#endif
if ( V_66 == 0 )
V_66 = V_393 ;
if ( V_65 < 8 )
V_65 = 8 ;
if ( V_65 < 10 ) {
if ( F_47 ( V_43 ) ) {
V_113 |= V_285 ;
if ( V_65 == 8 )
V_113 |= V_114 ;
} else
V_65 = 10 ;
}
V_391 = V_113 & V_285 ;
F_50 ( & V_50 , V_390 -> V_193 , V_43 -> V_57 , 0 ,
V_43 -> V_55 + 'A' , V_68 ) ;
if ( V_113 & ~ V_286 ) {
if ( F_155 ( V_43 ) == 0 )
V_113 &= V_286 ;
}
F_200 ( V_2 , & V_65 , & V_113 ,
V_391 ? V_394 : V_395 ) ;
F_41 ( V_2 , & V_47 ) ;
F_51 ( V_2 , & V_50 , V_65 , V_66 ,
V_113 , V_69 , FALSE ) ;
F_53 ( V_2 , & V_47 ) ;
}
static void F_201 ( struct V_42 * V_43 , int V_66 )
{
struct V_28 * V_390 = F_39 ( V_43 -> V_36 . V_126 ) ;
struct V_1 * V_2 = * ( (struct V_1 * * ) V_390 -> V_32 ) ;
struct V_53 * V_54 ;
struct V_51 * V_52
= F_43 ( V_2 ,
V_43 -> V_55 + 'A' ,
V_390 -> V_193 , V_43 -> V_57 , & V_54 ) ;
struct V_49 V_50 ;
unsigned int V_113 = 0 ;
unsigned int V_65 = 0 ;
unsigned int V_391 = V_113 & V_285 ;
unsigned long V_47 ;
#ifdef F_80
if ( ( V_124 & V_392 ) != 0 )
F_2 ( L_75 , F_56 ( V_2 ) , V_66 ) ;
#endif
F_50 ( & V_50 , V_390 -> V_193 , V_43 -> V_57 , 0 ,
V_43 -> V_55 + 'A' , V_68 ) ;
if ( V_66 != 0 ) {
V_65 = V_52 -> V_284 . V_65 ;
V_113 = V_52 -> V_284 . V_113 ;
F_200 ( V_2 , & V_65 , & V_113 ,
V_391 ? V_394 : V_395 ) ;
}
F_41 ( V_2 , & V_47 ) ;
F_51 ( V_2 , & V_50 , V_65 , V_66 , V_113 ,
V_69 , FALSE ) ;
F_53 ( V_2 , & V_47 ) ;
}
static void F_202 ( struct V_42 * V_43 , int V_391 )
{
struct V_28 * V_390 = F_39 ( V_43 -> V_36 . V_126 ) ;
struct V_1 * V_2 = * ( (struct V_1 * * ) V_390 -> V_32 ) ;
struct V_53 * V_54 ;
struct V_51 * V_52
= F_43 ( V_2 ,
V_43 -> V_55 + 'A' ,
V_390 -> V_193 , V_43 -> V_57 , & V_54 ) ;
struct V_49 V_50 ;
unsigned int V_113 = V_52 -> V_284 . V_113
& ~ V_285 ;
unsigned int V_65 = V_52 -> V_284 . V_65 ;
unsigned int V_21 = V_52 -> V_284 . V_21 ;
unsigned long V_47 ;
#ifdef F_80
if ( ( V_124 & V_392 ) != 0 )
F_2 ( L_76 , F_56 ( V_2 ) ,
V_391 ? L_77 : L_78 ) ;
#endif
if ( V_391 && F_47 ( V_43 ) ) {
V_113 |= V_285 ;
if ( ! V_21 )
F_198 ( V_43 , 1 ) ;
} else {
if ( V_65 <= 9 )
V_65 = 10 ;
V_113 &= ~ V_114 ;
}
F_50 ( & V_50 , V_390 -> V_193 , V_43 -> V_57 , 0 ,
V_43 -> V_55 + 'A' , V_68 ) ;
F_200 ( V_2 , & V_65 , & V_113 ,
V_391 ? V_394 : V_395 ) ;
F_41 ( V_2 , & V_47 ) ;
F_51 ( V_2 , & V_50 , V_65 , V_52 -> V_284 . V_66 ,
V_113 , V_69 , FALSE ) ;
F_53 ( V_2 , & V_47 ) ;
}
static void F_203 ( struct V_42 * V_43 , int V_396 )
{
struct V_28 * V_390 = F_39 ( V_43 -> V_36 . V_126 ) ;
struct V_1 * V_2 = * ( (struct V_1 * * ) V_390 -> V_32 ) ;
struct V_53 * V_54 ;
struct V_51 * V_52
= F_43 ( V_2 ,
V_43 -> V_55 + 'A' ,
V_390 -> V_193 , V_43 -> V_57 , & V_54 ) ;
struct V_49 V_50 ;
unsigned int V_113 = V_52 -> V_284 . V_113
& ~ V_286 ;
unsigned int V_65 = V_52 -> V_284 . V_65 ;
unsigned int V_391 ;
unsigned long V_47 ;
#ifdef F_80
if ( ( V_124 & V_392 ) != 0 )
F_2 ( L_79 , F_56 ( V_2 ) ,
V_396 ? L_77 : L_78 ) ;
#endif
if ( V_396 ) {
V_113 |= V_286 ;
}
V_391 = V_113 & V_285 ;
F_50 ( & V_50 , V_390 -> V_193 , V_43 -> V_57 , 0 ,
V_43 -> V_55 + 'A' , V_68 ) ;
F_200 ( V_2 , & V_65 , & V_113 ,
V_391 ? V_394 : V_395 ) ;
F_41 ( V_2 , & V_47 ) ;
F_51 ( V_2 , & V_50 , V_65 , V_52 -> V_284 . V_66 ,
V_113 , V_69 , FALSE ) ;
F_53 ( V_2 , & V_47 ) ;
}
static void F_204 ( struct V_42 * V_43 , int V_397 )
{
struct V_28 * V_390 = F_39 ( V_43 -> V_36 . V_126 ) ;
struct V_1 * V_2 = * ( (struct V_1 * * ) V_390 -> V_32 ) ;
struct V_53 * V_54 ;
struct V_51 * V_52
= F_43 ( V_2 ,
V_43 -> V_55 + 'A' ,
V_390 -> V_193 , V_43 -> V_57 , & V_54 ) ;
struct V_49 V_50 ;
unsigned int V_113 = V_52 -> V_284 . V_113
& ~ V_114 ;
unsigned int V_65 = V_52 -> V_284 . V_65 ;
unsigned int V_391 ;
unsigned long V_47 ;
#ifdef F_80
if ( ( V_124 & V_392 ) != 0 )
F_2 ( L_80 , F_56 ( V_2 ) ,
V_397 ? L_77 : L_78 ) ;
#endif
if ( V_397 && F_47 ( V_43 ) ) {
V_113 |= V_114 ;
V_113 |= V_285 ;
}
V_391 = V_113 & V_285 ;
F_50 ( & V_50 , V_390 -> V_193 , V_43 -> V_57 , 0 ,
V_43 -> V_55 + 'A' , V_68 ) ;
F_200 ( V_2 , & V_65 , & V_113 ,
V_391 ? V_394 : V_395 ) ;
F_41 ( V_2 , & V_47 ) ;
F_51 ( V_2 , & V_50 , V_65 , V_52 -> V_284 . V_66 ,
V_113 , V_69 , FALSE ) ;
F_53 ( V_2 , & V_47 ) ;
}
static void F_205 ( struct V_42 * V_43 , int V_398 )
{
struct V_28 * V_390 = F_39 ( V_43 -> V_36 . V_126 ) ;
struct V_1 * V_2 = * ( (struct V_1 * * ) V_390 -> V_32 ) ;
struct V_53 * V_54 ;
struct V_51 * V_52
= F_43 ( V_2 ,
V_43 -> V_55 + 'A' ,
V_390 -> V_193 , V_43 -> V_57 , & V_54 ) ;
struct V_49 V_50 ;
unsigned int V_113 = V_52 -> V_284 . V_113
& ~ V_287 ;
unsigned int V_65 = V_52 -> V_284 . V_65 ;
unsigned int V_391 = V_113 & V_285 ;
unsigned long V_47 ;
#ifdef F_80
if ( ( V_124 & V_392 ) != 0 )
F_2 ( L_81 , F_56 ( V_2 ) ,
V_398 ? L_77 : L_78 ) ;
#endif
if ( V_398 && F_47 ( V_43 ) )
V_113 |= V_287 ;
F_50 ( & V_50 , V_390 -> V_193 , V_43 -> V_57 , 0 ,
V_43 -> V_55 + 'A' , V_68 ) ;
F_200 ( V_2 , & V_65 , & V_113 ,
V_391 ? V_394 : V_395 ) ;
F_41 ( V_2 , & V_47 ) ;
F_51 ( V_2 , & V_50 , V_65 , V_52 -> V_284 . V_66 ,
V_113 , V_69 , FALSE ) ;
F_53 ( V_2 , & V_47 ) ;
}
static void F_206 ( struct V_42 * V_43 , int V_399 )
{
struct V_28 * V_390 = F_39 ( V_43 -> V_36 . V_126 ) ;
struct V_1 * V_2 = * ( (struct V_1 * * ) V_390 -> V_32 ) ;
struct V_53 * V_54 ;
struct V_51 * V_52
= F_43 ( V_2 ,
V_43 -> V_55 + 'A' ,
V_390 -> V_193 , V_43 -> V_57 , & V_54 ) ;
struct V_49 V_50 ;
unsigned int V_113 = V_52 -> V_284 . V_113
& ~ V_290 ;
unsigned int V_65 = V_52 -> V_284 . V_65 ;
unsigned int V_391 = V_113 & V_285 ;
unsigned long V_47 ;
#ifdef F_80
if ( ( V_124 & V_392 ) != 0 )
F_2 ( L_82 , F_56 ( V_2 ) ,
V_399 ? L_77 : L_78 ) ;
#endif
if ( V_399 && F_47 ( V_43 ) )
V_113 |= V_290 ;
F_50 ( & V_50 , V_390 -> V_193 , V_43 -> V_57 , 0 ,
V_43 -> V_55 + 'A' , V_68 ) ;
F_200 ( V_2 , & V_65 , & V_113 ,
V_391 ? V_394 : V_395 ) ;
F_41 ( V_2 , & V_47 ) ;
F_51 ( V_2 , & V_50 , V_65 , V_52 -> V_284 . V_66 ,
V_113 , V_69 , FALSE ) ;
F_53 ( V_2 , & V_47 ) ;
}
static void F_207 ( struct V_42 * V_43 , int V_400 )
{
struct V_28 * V_390 = F_39 ( V_43 -> V_36 . V_126 ) ;
struct V_1 * V_2 = * ( (struct V_1 * * ) V_390 -> V_32 ) ;
struct V_53 * V_54 ;
struct V_51 * V_52
= F_43 ( V_2 ,
V_43 -> V_55 + 'A' ,
V_390 -> V_193 , V_43 -> V_57 , & V_54 ) ;
struct V_49 V_50 ;
unsigned int V_113 = V_52 -> V_284 . V_113
& ~ V_289 ;
unsigned int V_65 = V_52 -> V_284 . V_65 ;
unsigned int V_391 = V_113 & V_285 ;
unsigned long V_47 ;
if ( ( V_2 -> V_60 & V_61 ) == 0 ) {
#ifdef F_80
if ( ( V_124 & V_392 ) != 0 )
F_2 ( L_83 , F_56 ( V_2 ) ) ;
#endif
return;
}
#ifdef F_80
if ( ( V_124 & V_392 ) != 0 )
F_2 ( L_84 , F_56 ( V_2 ) ,
V_400 ? L_77 : L_78 ) ;
#endif
if ( V_400 && F_47 ( V_43 ) )
V_113 |= V_289 ;
F_50 ( & V_50 , V_390 -> V_193 , V_43 -> V_57 , 0 ,
V_43 -> V_55 + 'A' , V_68 ) ;
F_200 ( V_2 , & V_65 , & V_113 ,
V_391 ? V_394 : V_395 ) ;
F_41 ( V_2 , & V_47 ) ;
F_51 ( V_2 , & V_50 , V_65 , V_52 -> V_284 . V_66 ,
V_113 , V_69 , FALSE ) ;
F_53 ( V_2 , & V_47 ) ;
}
static void F_208 ( struct V_42 * V_43 , int V_401 )
{
struct V_28 * V_390 = F_39 ( V_43 -> V_36 . V_126 ) ;
struct V_1 * V_2 = * ( (struct V_1 * * ) V_390 -> V_32 ) ;
struct V_53 * V_54 ;
struct V_51 * V_52
= F_43 ( V_2 ,
V_43 -> V_55 + 'A' ,
V_390 -> V_193 , V_43 -> V_57 , & V_54 ) ;
struct V_49 V_50 ;
unsigned int V_113 = V_52 -> V_284 . V_113
& ~ V_288 ;
unsigned int V_65 = V_52 -> V_284 . V_65 ;
unsigned int V_391 = V_113 & V_285 ;
unsigned long V_47 ;
#ifdef F_80
if ( ( V_124 & V_392 ) != 0 )
F_2 ( L_85 , F_56 ( V_2 ) ,
V_401 ? L_86 : L_87 ) ;
#endif
if ( V_401 && F_47 ( V_43 ) ) {
T_1 V_219 ;
if ( V_2 -> V_202 < F_94 ( V_154 ) ) {
const struct V_217 * V_218 ;
V_218 = & V_154 [ V_2 -> V_202 ] ;
V_219 = V_218 -> V_219 ;
} else {
V_219 = V_220 ;
}
V_113 |= V_288 ;
F_124 ( V_2 , V_219 ) ;
} else {
F_124 ( V_2 , 0 ) ;
}
F_50 ( & V_50 , V_390 -> V_193 , V_43 -> V_57 , 0 ,
V_43 -> V_55 + 'A' , V_68 ) ;
F_200 ( V_2 , & V_65 , & V_113 ,
V_391 ? V_394 : V_395 ) ;
F_41 ( V_2 , & V_47 ) ;
F_51 ( V_2 , & V_50 , V_65 , V_52 -> V_284 . V_66 ,
V_113 , V_69 , FALSE ) ;
F_53 ( V_2 , & V_47 ) ;
}
static void F_209 ( struct V_42 * V_43 , int V_402 )
{
struct V_28 * V_390 = F_39 ( V_43 -> V_36 . V_126 ) ;
struct V_1 * V_2 = * ( (struct V_1 * * ) V_390 -> V_32 ) ;
struct V_53 * V_54 ;
struct V_51 * V_52
= F_43 ( V_2 ,
V_43 -> V_55 + 'A' ,
V_390 -> V_193 , V_43 -> V_57 , & V_54 ) ;
struct V_49 V_50 ;
unsigned int V_113 = V_52 -> V_284 . V_113
& ~ V_291 ;
unsigned int V_65 = V_52 -> V_284 . V_65 ;
unsigned int V_391 = V_113 & V_285 ;
unsigned long V_47 ;
if ( V_402 && F_47 ( V_43 ) )
V_113 |= V_291 ;
F_50 ( & V_50 , V_390 -> V_193 , V_43 -> V_57 , 0 ,
V_43 -> V_55 + 'A' , V_68 ) ;
F_200 ( V_2 , & V_65 , & V_113 ,
V_391 ? V_394 : V_395 ) ;
F_41 ( V_2 , & V_47 ) ;
F_51 ( V_2 , & V_50 , V_65 , V_52 -> V_284 . V_66 ,
V_113 , V_69 , FALSE ) ;
F_53 ( V_2 , & V_47 ) ;
}
static void F_210 ( struct V_28 * V_390 )
{
struct V_1 * V_2 = * (struct V_1 * * ) V_390 -> V_32 ;
unsigned long V_47 ;
T_22 V_403 ;
F_41 ( V_2 , & V_47 ) ;
F_211 ( V_2 ) ;
V_403 = F_8 ( V_2 , V_404 ) ;
F_197 ( V_2 ) ;
F_53 ( V_2 , & V_47 ) ;
if ( V_403 & V_405 )
F_212 ( V_390 ) = V_406 ;
else if ( V_403 & V_407 )
F_212 ( V_390 ) = V_408 ;
else
F_212 ( V_390 ) = V_409 ;
}
static int T_23
F_213 ( void )
{
int error = 0 ;
if ( V_410 )
F_101 ( V_410 ) ;
V_204 =
F_214 ( & V_411 ) ;
if ( ! V_204 )
return - V_412 ;
F_215 ( V_204 ,
sizeof( struct V_35 ) ) ;
error = F_216 () ;
if ( error )
F_217 ( V_204 ) ;
return error ;
}
static void T_24
F_218 ( void )
{
F_219 () ;
F_217 ( V_204 ) ;
}
