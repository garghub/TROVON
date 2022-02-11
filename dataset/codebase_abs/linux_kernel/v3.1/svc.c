static int
F_1 ( const char * V_1 , struct V_2 * V_3 )
{
int * V_4 = ( int * ) V_3 -> V_5 ;
struct V_6 * V_7 = & V_6 ;
int V_8 ;
F_2 ( & V_9 ) ;
V_8 = - V_10 ;
if ( V_7 -> V_11 )
goto V_12;
V_8 = 0 ;
if ( ! strncmp ( V_1 , L_1 , 4 ) )
* V_4 = V_13 ;
else if ( ! strncmp ( V_1 , L_2 , 6 ) )
* V_4 = V_14 ;
else if ( ! strncmp ( V_1 , L_3 , 6 ) )
* V_4 = V_15 ;
else if ( ! strncmp ( V_1 , L_4 , 7 ) )
* V_4 = V_16 ;
else
V_8 = - V_17 ;
V_12:
F_3 ( & V_9 ) ;
return V_8 ;
}
static int
F_4 ( char * V_18 , struct V_2 * V_3 )
{
int * V_4 = ( int * ) V_3 -> V_5 ;
switch ( * V_4 )
{
case V_13 :
return F_5 ( V_18 , L_1 , 20 ) ;
case V_14 :
return F_5 ( V_18 , L_2 , 20 ) ;
case V_15 :
return F_5 ( V_18 , L_3 , 20 ) ;
case V_16 :
return F_5 ( V_18 , L_4 , 20 ) ;
default:
return sprintf ( V_18 , L_5 , * V_4 ) ;
}
}
static int
F_6 ( void )
{
unsigned int V_19 ;
if ( V_20 > 1 ) {
return V_16 ;
}
V_19 = V_21 ;
if ( F_7 ( V_19 ) > 2 ) {
return V_15 ;
}
return V_14 ;
}
static int
F_8 ( struct V_6 * V_7 , unsigned int V_22 )
{
V_7 -> V_23 = F_9 ( V_22 , sizeof( unsigned int ) , V_24 ) ;
if ( ! V_7 -> V_23 )
goto V_25;
V_7 -> V_26 = F_9 ( V_22 , sizeof( unsigned int ) , V_24 ) ;
if ( ! V_7 -> V_26 )
goto V_27;
return 0 ;
V_27:
F_10 ( V_7 -> V_23 ) ;
V_25:
return - V_28 ;
}
static int
F_11 ( struct V_6 * V_7 )
{
unsigned int V_22 = V_29 ;
unsigned int V_30 = 0 ;
unsigned int V_31 ;
int V_8 ;
V_8 = F_8 ( V_7 , V_22 ) ;
if ( V_8 )
return V_8 ;
F_12 (cpu) {
F_13 ( V_30 > V_22 ) ;
V_7 -> V_23 [ V_31 ] = V_30 ;
V_7 -> V_26 [ V_30 ] = V_31 ;
V_30 ++ ;
}
return V_30 ;
}
static int
F_14 ( struct V_6 * V_7 )
{
unsigned int V_22 = V_32 ;
unsigned int V_30 = 0 ;
unsigned int V_19 ;
int V_8 ;
V_8 = F_8 ( V_7 , V_22 ) ;
if ( V_8 )
return V_8 ;
F_15 (node) {
F_13 ( V_30 > V_22 ) ;
V_7 -> V_23 [ V_19 ] = V_30 ;
V_7 -> V_26 [ V_30 ] = V_19 ;
V_30 ++ ;
}
return V_30 ;
}
static unsigned int
F_16 ( void )
{
struct V_6 * V_7 = & V_6 ;
int V_33 = - 1 ;
F_2 ( & V_9 ) ;
if ( V_7 -> V_11 ++ ) {
F_3 ( & V_9 ) ;
return V_7 -> V_33 ;
}
if ( V_7 -> V_34 == V_13 )
V_7 -> V_34 = F_6 () ;
switch ( V_7 -> V_34 ) {
case V_15 :
V_33 = F_11 ( V_7 ) ;
break;
case V_16 :
V_33 = F_14 ( V_7 ) ;
break;
}
if ( V_33 < 0 ) {
V_33 = 1 ;
V_7 -> V_34 = V_14 ;
}
V_7 -> V_33 = V_33 ;
F_3 ( & V_9 ) ;
return V_7 -> V_33 ;
}
static void
F_17 ( void )
{
struct V_6 * V_7 = & V_6 ;
F_2 ( & V_9 ) ;
if ( ! -- V_7 -> V_11 ) {
V_7 -> V_34 = V_35 ;
F_10 ( V_7 -> V_23 ) ;
F_10 ( V_7 -> V_26 ) ;
V_7 -> V_33 = 0 ;
}
F_3 ( & V_9 ) ;
}
static inline void
F_18 ( struct V_36 * V_37 , unsigned int V_30 )
{
struct V_6 * V_7 = & V_6 ;
unsigned int V_19 = V_7 -> V_26 [ V_30 ] ;
F_13 ( V_7 -> V_11 == 0 ) ;
switch ( V_7 -> V_34 ) {
case V_15 :
{
F_19 ( V_37 , F_20 ( V_19 ) ) ;
break;
}
case V_16 :
{
F_19 ( V_37 , F_21 ( V_19 ) ) ;
break;
}
}
}
struct V_38 *
F_22 ( struct V_39 * V_40 , int V_31 )
{
struct V_6 * V_7 = & V_6 ;
unsigned int V_30 = 0 ;
if ( F_23 ( V_40 ) ) {
switch ( V_7 -> V_34 ) {
case V_15 :
V_30 = V_7 -> V_23 [ V_31 ] ;
break;
case V_16 :
V_30 = V_7 -> V_23 [ F_24 ( V_31 ) ] ;
break;
}
}
return & V_40 -> V_41 [ V_30 % V_40 -> V_42 ] ;
}
static struct V_39 *
F_25 ( struct V_43 * V_44 , unsigned int V_45 , int V_33 ,
void (* F_26)( struct V_39 * V_40 ) )
{
struct V_39 * V_40 ;
unsigned int V_46 ;
unsigned int V_47 ;
unsigned int V_48 ;
if ( ! ( V_40 = F_27 ( sizeof( * V_40 ) , V_24 ) ) )
return NULL ;
V_40 -> V_49 = V_44 -> V_50 ;
V_40 -> V_51 = V_44 ;
V_40 -> V_52 = 1 ;
V_40 -> V_53 = V_44 -> V_54 ;
if ( V_45 > V_55 )
V_45 = V_55 ;
V_40 -> V_56 = V_45 ? V_45 : 4096 ;
V_40 -> V_57 = F_28 ( V_40 -> V_56 + V_58 , V_58 ) ;
V_40 -> V_59 = F_26 ;
V_47 = 0 ;
while ( V_44 ) {
V_44 -> V_60 = V_44 -> V_61 - 1 ;
for ( V_46 = 0 ; V_46 < V_44 -> V_61 ; V_46 ++ )
if ( V_44 -> V_62 [ V_46 ] ) {
V_44 -> V_63 = V_46 ;
if ( V_44 -> V_60 > V_46 )
V_44 -> V_60 = V_46 ;
if ( V_44 -> V_62 [ V_46 ] -> V_64 > V_47 )
V_47 = V_44 -> V_62 [ V_46 ] -> V_64 ;
}
V_44 = V_44 -> V_65 ;
}
V_40 -> V_66 = V_47 ;
F_29 ( & V_40 -> V_67 ) ;
F_29 ( & V_40 -> V_68 ) ;
F_30 ( & V_40 -> V_69 ) ;
F_31 ( & V_40 -> V_70 ) ;
V_40 -> V_42 = V_33 ;
V_40 -> V_41 =
F_9 ( V_40 -> V_42 , sizeof( struct V_38 ) ,
V_24 ) ;
if ( ! V_40 -> V_41 ) {
F_10 ( V_40 ) ;
return NULL ;
}
for ( V_48 = 0 ; V_48 < V_40 -> V_42 ; V_48 ++ ) {
struct V_38 * V_71 = & V_40 -> V_41 [ V_48 ] ;
F_32 ( L_6 ,
V_48 , V_40 -> V_49 ) ;
V_71 -> V_72 = V_48 ;
F_29 ( & V_71 -> V_73 ) ;
F_29 ( & V_71 -> V_74 ) ;
F_29 ( & V_71 -> V_75 ) ;
F_31 ( & V_71 -> V_76 ) ;
}
F_33 ( V_40 ) ;
return V_40 ;
}
struct V_39 *
F_34 ( struct V_43 * V_44 , unsigned int V_45 ,
void (* F_26)( struct V_39 * V_40 ) )
{
return F_25 ( V_44 , V_45 , 1 , F_26 ) ;
}
struct V_39 *
F_35 ( struct V_43 * V_44 , unsigned int V_45 ,
void (* F_26)( struct V_39 * V_40 ) ,
T_1 V_77 , struct V_78 * V_79 )
{
struct V_39 * V_40 ;
unsigned int V_33 = F_16 () ;
V_40 = F_25 ( V_44 , V_45 , V_33 , F_26 ) ;
if ( V_40 != NULL ) {
V_40 -> V_80 = V_77 ;
V_40 -> V_81 = V_79 ;
}
return V_40 ;
}
void
F_36 ( struct V_39 * V_40 )
{
F_32 ( L_7 ,
V_40 -> V_51 -> V_50 ,
V_40 -> V_52 ) ;
if ( V_40 -> V_52 ) {
if ( -- ( V_40 -> V_52 ) != 0 ) {
F_37 ( V_40 ) ;
return;
}
} else
F_38 ( L_8 , V_40 ) ;
F_39 ( & V_40 -> V_69 ) ;
F_40 ( & V_40 -> V_67 ) ;
if ( V_40 -> V_59 )
V_40 -> V_59 ( V_40 ) ;
F_40 ( & V_40 -> V_68 ) ;
F_13 ( ! F_41 ( & V_40 -> V_68 ) ) ;
F_13 ( ! F_41 ( & V_40 -> V_67 ) ) ;
F_42 ( V_40 ) ;
if ( F_23 ( V_40 ) )
F_17 () ;
F_33 ( V_40 ) ;
F_10 ( V_40 -> V_41 ) ;
F_10 ( V_40 ) ;
}
static int
F_43 ( struct V_82 * V_83 , unsigned int V_84 )
{
unsigned int V_85 , V_86 ;
if ( F_44 ( V_83 ) )
return 1 ;
V_85 = V_84 / V_58 + 1 ;
V_86 = 0 ;
F_13 ( V_85 > V_87 ) ;
while ( V_85 ) {
struct V_88 * V_89 = F_45 ( V_24 ) ;
if ( ! V_89 )
break;
V_83 -> V_90 [ V_86 ++ ] = V_89 ;
V_85 -- ;
}
return V_85 == 0 ;
}
static void
F_46 ( struct V_82 * V_83 )
{
unsigned int V_48 ;
for ( V_48 = 0 ; V_48 < F_47 ( V_83 -> V_90 ) ; V_48 ++ )
if ( V_83 -> V_90 [ V_48 ] )
F_48 ( V_83 -> V_90 [ V_48 ] ) ;
}
struct V_82 *
F_49 ( struct V_39 * V_40 , struct V_38 * V_71 )
{
struct V_82 * V_83 ;
V_83 = F_27 ( sizeof( * V_83 ) , V_24 ) ;
if ( ! V_83 )
goto V_91;
F_50 ( & V_83 -> V_92 ) ;
V_40 -> V_52 ++ ;
F_51 ( & V_71 -> V_76 ) ;
V_71 -> V_93 ++ ;
F_52 ( & V_83 -> V_94 , & V_71 -> V_75 ) ;
F_53 ( & V_71 -> V_76 ) ;
V_83 -> V_95 = V_40 ;
V_83 -> V_96 = V_71 ;
V_83 -> V_97 = F_54 ( V_40 -> V_66 , V_24 ) ;
if ( ! V_83 -> V_97 )
goto V_98;
V_83 -> V_99 = F_54 ( V_40 -> V_66 , V_24 ) ;
if ( ! V_83 -> V_99 )
goto V_98;
if ( ! F_43 ( V_83 , V_40 -> V_57 ) )
goto V_98;
return V_83 ;
V_98:
F_55 ( V_83 ) ;
V_91:
return F_56 ( - V_28 ) ;
}
static inline struct V_38 *
F_57 ( struct V_39 * V_40 , struct V_38 * V_71 , unsigned int * V_100 )
{
if ( V_71 != NULL )
return V_71 ;
return & V_40 -> V_41 [ ( * V_100 ) ++ % V_40 -> V_42 ] ;
}
static inline struct V_36 *
F_58 ( struct V_39 * V_40 , struct V_38 * V_71 , unsigned int * V_100 )
{
unsigned int V_48 ;
struct V_36 * V_37 = NULL ;
if ( V_71 != NULL ) {
F_51 ( & V_71 -> V_76 ) ;
} else {
for ( V_48 = 0 ; V_48 < V_40 -> V_42 ; V_48 ++ ) {
V_71 = & V_40 -> V_41 [ -- ( * V_100 ) % V_40 -> V_42 ] ;
F_51 ( & V_71 -> V_76 ) ;
if ( ! F_41 ( & V_71 -> V_75 ) )
goto V_101;
F_53 ( & V_71 -> V_76 ) ;
}
return NULL ;
}
V_101:
if ( ! F_41 ( & V_71 -> V_75 ) ) {
struct V_82 * V_83 ;
V_83 = F_59 ( V_71 -> V_75 . V_102 , struct V_82 , V_94 ) ;
F_60 ( & V_83 -> V_94 ) ;
V_37 = V_83 -> V_103 ;
}
F_53 ( & V_71 -> V_76 ) ;
return V_37 ;
}
int
F_61 ( struct V_39 * V_40 , struct V_38 * V_71 , int V_104 )
{
struct V_82 * V_83 ;
struct V_36 * V_37 ;
struct V_38 * V_105 ;
int error = 0 ;
unsigned int V_100 = V_40 -> V_52 - 1 ;
if ( V_71 == NULL ) {
V_104 -= ( V_40 -> V_52 - 1 ) ;
} else {
F_51 ( & V_71 -> V_76 ) ;
V_104 -= V_71 -> V_93 ;
F_53 ( & V_71 -> V_76 ) ;
}
while ( V_104 > 0 ) {
V_104 -- ;
V_105 = F_57 ( V_40 , V_71 , & V_100 ) ;
V_83 = F_49 ( V_40 , V_105 ) ;
if ( F_62 ( V_83 ) ) {
error = F_63 ( V_83 ) ;
break;
}
F_64 ( V_40 -> V_81 ) ;
V_37 = F_65 ( V_40 -> V_80 , V_83 , V_40 -> V_49 ) ;
if ( F_62 ( V_37 ) ) {
error = F_63 ( V_37 ) ;
F_66 ( V_40 -> V_81 ) ;
F_55 ( V_83 ) ;
break;
}
V_83 -> V_103 = V_37 ;
if ( V_40 -> V_42 > 1 )
F_18 ( V_37 , V_105 -> V_72 ) ;
F_37 ( V_40 ) ;
F_67 ( V_37 ) ;
}
while ( V_104 < 0 &&
( V_37 = F_58 ( V_40 , V_71 , & V_100 ) ) != NULL ) {
F_68 ( V_106 , V_37 , 1 ) ;
V_104 ++ ;
}
return error ;
}
void
F_55 ( struct V_82 * V_83 )
{
struct V_39 * V_40 = V_83 -> V_95 ;
struct V_38 * V_71 = V_83 -> V_96 ;
F_46 ( V_83 ) ;
F_10 ( V_83 -> V_99 ) ;
F_10 ( V_83 -> V_97 ) ;
F_10 ( V_83 -> V_107 ) ;
F_51 ( & V_71 -> V_76 ) ;
V_71 -> V_93 -- ;
F_69 ( & V_83 -> V_94 ) ;
F_53 ( & V_71 -> V_76 ) ;
F_10 ( V_83 ) ;
if ( V_40 )
F_36 ( V_40 ) ;
}
static int F_70 ( const T_2 V_108 , const T_2 V_109 ,
const unsigned short V_110 ,
const unsigned short V_111 )
{
const struct V_112 sin = {
. V_113 = V_114 ,
. V_115 . V_116 = F_71 ( V_117 ) ,
. V_118 = F_72 ( V_111 ) ,
} ;
const char * V_119 ;
int error ;
switch ( V_110 ) {
case V_120 :
V_119 = V_121 ;
break;
case V_122 :
V_119 = V_123 ;
break;
default:
return - V_124 ;
}
error = F_73 ( V_108 , V_109 ,
( const struct V_125 * ) & sin , V_119 ) ;
if ( error == - V_126 )
error = F_74 ( V_108 , V_109 , V_110 , V_111 ) ;
return error ;
}
static int F_75 ( const T_2 V_108 , const T_2 V_109 ,
const unsigned short V_110 ,
const unsigned short V_111 )
{
const struct V_127 V_128 = {
. V_129 = V_130 ,
. V_131 = V_132 ,
. V_133 = F_72 ( V_111 ) ,
} ;
const char * V_119 ;
int error ;
switch ( V_110 ) {
case V_120 :
V_119 = V_134 ;
break;
case V_122 :
V_119 = V_135 ;
break;
default:
return - V_124 ;
}
error = F_73 ( V_108 , V_109 ,
( const struct V_125 * ) & V_128 , V_119 ) ;
if ( error == - V_126 )
error = - V_136 ;
return error ;
}
static int F_76 ( const char * V_137 ,
const T_2 V_108 , const T_2 V_109 ,
const int V_138 ,
const unsigned short V_110 ,
const unsigned short V_111 )
{
int error = - V_136 ;
switch ( V_138 ) {
case V_139 :
error = F_70 ( V_108 , V_109 ,
V_110 , V_111 ) ;
break;
#if F_77 ( V_140 ) || F_77 ( V_141 )
case V_142 :
error = F_75 ( V_108 , V_109 ,
V_110 , V_111 ) ;
#endif
}
if ( error < 0 )
F_38 ( V_143 L_9
L_10 , V_137 , V_109 , - error ) ;
return error ;
}
int F_78 ( const struct V_39 * V_40 , const int V_138 ,
const unsigned short V_144 , const unsigned short V_111 )
{
struct V_43 * V_145 ;
unsigned int V_48 ;
int error = 0 ;
F_13 ( V_144 == 0 && V_111 == 0 ) ;
for ( V_145 = V_40 -> V_51 ; V_145 ; V_145 = V_145 -> V_65 ) {
for ( V_48 = 0 ; V_48 < V_145 -> V_61 ; V_48 ++ ) {
if ( V_145 -> V_62 [ V_48 ] == NULL )
continue;
F_32 ( L_11 ,
V_145 -> V_50 ,
V_48 ,
V_144 == V_120 ? L_12 : L_13 ,
V_111 ,
V_138 ,
V_145 -> V_62 [ V_48 ] -> V_146 ?
L_14 : L_15 ) ;
if ( V_145 -> V_62 [ V_48 ] -> V_146 )
continue;
error = F_76 ( V_145 -> V_50 , V_145 -> V_147 ,
V_48 , V_138 , V_144 , V_111 ) ;
if ( error < 0 )
break;
}
}
return error ;
}
static void F_79 ( const T_2 V_108 , const T_2 V_109 ,
const char * V_137 )
{
int error ;
error = F_73 ( V_108 , V_109 , NULL , L_15 ) ;
if ( error == - V_126 )
error = F_74 ( V_108 , V_109 , 0 , 0 ) ;
F_32 ( L_16 ,
V_148 , V_137 , V_109 , error ) ;
}
static void F_33 ( const struct V_39 * V_40 )
{
struct V_43 * V_145 ;
unsigned long V_149 ;
unsigned int V_48 ;
F_80 ( V_150 ) ;
for ( V_145 = V_40 -> V_51 ; V_145 ; V_145 = V_145 -> V_65 ) {
for ( V_48 = 0 ; V_48 < V_145 -> V_61 ; V_48 ++ ) {
if ( V_145 -> V_62 [ V_48 ] == NULL )
continue;
if ( V_145 -> V_62 [ V_48 ] -> V_146 )
continue;
F_32 ( L_17 ,
V_145 -> V_50 , V_48 ) ;
F_79 ( V_145 -> V_147 , V_48 , V_145 -> V_50 ) ;
}
}
F_81 ( & V_151 -> V_152 -> V_153 , V_149 ) ;
F_82 () ;
F_83 ( & V_151 -> V_152 -> V_153 , V_149 ) ;
}
static int
F_84 ( struct V_82 * V_83 , struct V_154 * V_155 , struct V_154 * V_156 )
{
struct V_43 * V_145 ;
struct V_157 * V_158 = NULL ;
struct V_159 * V_160 = NULL ;
struct V_39 * V_40 = V_83 -> V_95 ;
T_3 V_161 ;
T_4 * V_162 ;
T_2 V_44 , V_46 , V_163 ;
T_4 V_164 , V_165 ;
int V_166 ;
T_4 * V_167 ;
V_165 = V_168 ;
if ( V_155 -> V_169 < 6 * 4 )
goto V_170;
V_83 -> V_171 = 1 ;
V_83 -> V_172 = 1 ;
V_83 -> V_173 = false ;
V_83 -> V_174 -> V_175 -> V_176 ( V_83 ) ;
F_85 ( V_156 , V_83 -> V_177 ) ;
V_46 = F_86 ( V_155 ) ;
F_87 ( V_156 , 1 ) ;
if ( V_46 != 2 )
goto V_178;
V_167 = V_156 -> V_179 + V_156 -> V_169 ;
F_87 ( V_156 , 0 ) ;
V_83 -> V_180 = V_44 = F_86 ( V_155 ) ;
V_83 -> V_181 = V_46 = F_86 ( V_155 ) ;
V_83 -> V_182 = V_163 = F_86 ( V_155 ) ;
V_145 = V_40 -> V_51 ;
for ( V_145 = V_40 -> V_51 ; V_145 ; V_145 = V_145 -> V_65 )
if ( V_44 == V_145 -> V_147 )
break;
V_166 = F_88 ( V_83 , & V_164 ) ;
if ( V_166 == V_183 && V_145 ) {
V_164 = V_184 ;
V_166 = V_145 -> V_185 ( V_83 ) ;
}
switch ( V_166 ) {
case V_183 :
break;
case V_186 :
goto V_187;
case V_188 :
V_165 = V_189 ;
goto V_190;
case V_191 :
goto V_192;
case V_193 :
if ( F_89 ( V_194 , & V_83 -> V_174 -> V_195 ) )
F_90 ( V_83 -> V_174 ) ;
case V_196 :
goto V_197;
case V_198 :
goto V_199;
}
if ( V_145 == NULL )
goto V_200;
if ( V_46 >= V_145 -> V_61 ||
! ( V_158 = V_145 -> V_62 [ V_46 ] ) )
goto V_201;
V_160 = V_158 -> V_202 + V_163 ;
if ( V_163 >= V_158 -> V_203 || ! V_160 -> V_204 )
goto V_205;
V_83 -> V_206 = V_160 ;
V_40 -> V_53 -> V_207 ++ ;
V_162 = V_156 -> V_179 + V_156 -> V_169 ;
F_87 ( V_156 , V_208 ) ;
V_160 -> V_209 ++ ;
memset ( V_83 -> V_97 , 0 , V_160 -> V_210 ) ;
memset ( V_83 -> V_99 , 0 , V_160 -> V_211 ) ;
if ( V_160 -> V_212 )
F_91 ( V_83 , V_160 -> V_212 << 2 ) ;
if ( ! V_158 -> V_213 ) {
V_161 = V_160 -> V_214 ;
if ( V_161 && ! V_161 ( V_83 , V_155 -> V_179 , V_83 -> V_97 ) )
goto V_187;
* V_162 = V_160 -> V_204 ( V_83 , V_83 -> V_97 , V_83 -> V_99 ) ;
if ( V_83 -> V_173 ) {
if ( V_160 -> V_215 )
V_160 -> V_215 ( V_83 , NULL , V_83 -> V_99 ) ;
goto V_197;
}
if ( * V_162 == V_168 &&
( V_161 = V_160 -> V_216 ) &&
! V_161 ( V_83 , V_156 -> V_179 + V_156 -> V_169 , V_83 -> V_99 ) ) {
F_32 ( L_18 ) ;
* V_162 = V_189 ;
}
} else {
F_32 ( L_19 ) ;
if ( ! V_158 -> V_213 ( V_83 , V_162 ) ) {
if ( V_160 -> V_215 )
V_160 -> V_215 ( V_83 , NULL , V_83 -> V_99 ) ;
goto V_197;
}
}
if ( * V_162 != V_168 )
V_156 -> V_169 = ( ( void * ) V_162 ) - V_156 -> V_179 + 4 ;
if ( V_160 -> V_215 )
V_160 -> V_215 ( V_83 , NULL , V_83 -> V_99 ) ;
if ( V_160 -> V_216 == NULL )
goto V_197;
V_199:
if ( F_92 ( V_83 ) )
goto V_197;
return 1 ;
V_197:
F_92 ( V_83 ) ;
F_32 ( L_20 ) ;
return 0 ;
V_170:
F_93 ( V_83 , L_21 ,
V_155 -> V_169 ) ;
goto V_197;
V_178:
V_40 -> V_53 -> V_217 ++ ;
F_87 ( V_156 , 1 ) ;
F_87 ( V_156 , 0 ) ;
F_87 ( V_156 , 2 ) ;
F_87 ( V_156 , 2 ) ;
goto V_199;
V_192:
F_32 ( L_22 , F_94 ( V_164 ) ) ;
V_40 -> V_53 -> V_218 ++ ;
F_95 ( V_83 , V_167 ) ;
F_87 ( V_156 , 1 ) ;
F_87 ( V_156 , 1 ) ;
F_87 ( V_156 , F_94 ( V_164 ) ) ;
goto V_199;
V_200:
F_32 ( L_23 , V_44 ) ;
V_40 -> V_53 -> V_217 ++ ;
F_87 ( V_156 , V_219 ) ;
goto V_199;
V_201:
F_93 ( V_83 , L_24 ,
V_46 , V_44 , V_145 -> V_50 ) ;
V_40 -> V_53 -> V_217 ++ ;
F_87 ( V_156 , V_220 ) ;
F_87 ( V_156 , V_145 -> V_60 ) ;
F_87 ( V_156 , V_145 -> V_63 ) ;
goto V_199;
V_205:
F_93 ( V_83 , L_25 , V_163 ) ;
V_40 -> V_53 -> V_217 ++ ;
F_87 ( V_156 , V_221 ) ;
goto V_199;
V_187:
F_93 ( V_83 , L_26 ) ;
V_165 = V_222 ;
V_190:
V_40 -> V_53 -> V_217 ++ ;
F_87 ( V_156 , F_94 ( V_165 ) ) ;
goto V_199;
}
int
F_96 ( struct V_82 * V_83 )
{
struct V_154 * V_155 = & V_83 -> V_223 . V_224 [ 0 ] ;
struct V_154 * V_156 = & V_83 -> V_225 . V_224 [ 0 ] ;
struct V_39 * V_40 = V_83 -> V_95 ;
T_2 V_226 ;
V_83 -> V_227 = 1 ;
V_156 -> V_179 = F_97 ( V_83 -> V_228 [ 0 ] ) ;
V_156 -> V_169 = 0 ;
V_83 -> V_225 . V_85 = V_83 -> V_228 + 1 ;
V_83 -> V_225 . V_229 = 0 ;
V_83 -> V_225 . V_230 = 0 ;
V_83 -> V_225 . V_231 = 0 ;
V_83 -> V_225 . V_232 = V_58 ;
V_83 -> V_225 . V_233 [ 0 ] . V_179 = NULL ;
V_83 -> V_225 . V_233 [ 0 ] . V_169 = 0 ;
V_83 -> V_177 = F_98 ( V_155 ) ;
V_226 = F_86 ( V_155 ) ;
if ( V_226 != 0 ) {
F_93 ( V_83 , L_27 , V_226 ) ;
V_40 -> V_53 -> V_217 ++ ;
F_99 ( V_83 ) ;
return 0 ;
}
if ( F_84 ( V_83 , V_155 , V_156 ) )
return F_100 ( V_83 ) ;
else {
F_99 ( V_83 ) ;
return 0 ;
}
}
int
F_101 ( struct V_39 * V_40 , struct V_234 * V_235 ,
struct V_82 * V_83 )
{
struct V_154 * V_155 = & V_83 -> V_223 . V_224 [ 0 ] ;
struct V_154 * V_156 = & V_83 -> V_225 . V_224 [ 0 ] ;
V_83 -> V_174 = V_40 -> V_236 ;
V_83 -> V_177 = V_235 -> V_177 ;
V_83 -> V_237 = V_235 -> V_174 -> V_238 ;
V_83 -> V_95 = V_40 ;
V_83 -> V_239 = sizeof( V_235 -> V_174 -> V_240 ) ;
memcpy ( & V_83 -> V_241 , & V_235 -> V_174 -> V_240 , V_83 -> V_239 ) ;
memcpy ( & V_83 -> V_223 , & V_235 -> V_242 , sizeof( V_83 -> V_223 ) ) ;
memcpy ( & V_83 -> V_225 , & V_235 -> V_243 , sizeof( V_83 -> V_225 ) ) ;
V_156 -> V_169 = 0 ;
if ( V_83 -> V_237 != V_122 ) {
F_38 ( V_244 L_28 ) ;
F_102 () ;
}
F_98 ( V_155 ) ;
F_86 ( V_155 ) ;
if ( F_84 ( V_83 , V_155 , V_156 ) ) {
memcpy ( & V_235 -> V_243 , & V_83 -> V_225 ,
sizeof( V_235 -> V_243 ) ) ;
return F_103 ( V_235 ) ;
} else {
return 0 ;
}
}
T_2 F_104 ( const struct V_82 * V_83 )
{
T_2 V_245 = V_83 -> V_174 -> V_246 -> V_247 ;
if ( V_83 -> V_95 -> V_56 < V_245 )
V_245 = V_83 -> V_95 -> V_56 ;
return V_245 ;
}
