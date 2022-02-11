static T_1
F_1 ( T_2 V_1 , T_2 V_2 )
{
return strcmp ( ( ( const struct V_3 * ) V_1 ) -> V_4 ,
( ( const struct V_3 * ) V_2 ) -> V_4 ) ;
}
static void
F_2 ( T_3 V_5 , T_3 T_4 V_6 )
{
fprintf ( V_7 , L_1 ,
( (struct V_3 * ) V_5 ) -> V_4 ,
( (struct V_3 * ) V_5 ) -> V_8 ) ;
}
static void
F_3 ( void ) {
int V_9 ;
struct V_3 * V_10 ;
T_5 * V_11 = NULL ;
V_10 = F_4 ( struct V_3 , V_12 ) ;
fprintf ( V_7 , L_2 ) ;
for ( V_9 = 0 ; V_9 < V_12 ; V_9 ++ ) {
if ( F_5 ( V_9 ) ) {
V_10 [ V_9 ] . V_4 = F_6 ( V_9 ) ;
V_10 [ V_9 ] . V_8 = F_7 ( V_9 ) ;
V_11 = F_8 ( V_11 , & V_10 [ V_9 ] , F_1 ) ;
}
}
F_9 ( V_11 , F_2 , NULL ) ;
F_10 ( V_11 ) ;
F_11 ( V_10 ) ;
}
static void
F_12 ( void ) {
int V_9 ;
struct V_3 * V_10 ;
T_5 * V_11 = NULL ;
const char * V_13 = L_3 ;
const char * V_14 = L_4 ;
V_10 = F_4 ( struct V_3 , V_12 ) ;
fprintf ( V_7 , L_5 ) ;
for ( V_9 = 0 ; V_15 [ V_9 ] . V_16 != NULL ; V_9 ++ ) {
V_10 [ V_9 ] . V_4 = V_15 [ V_9 ] . V_16 ;
V_10 [ V_9 ] . V_8 = ( V_15 [ V_9 ] . type == V_17 ) ? V_13 : V_14 ;
V_11 = F_8 ( V_11 , & V_10 [ V_9 ] , F_1 ) ;
}
F_9 ( V_11 , F_2 , NULL ) ;
F_10 ( V_11 ) ;
F_11 ( V_10 ) ;
}
static void
F_13 ( T_6 * V_18 )
{
fprintf ( V_18 , L_6 ) ;
fprintf ( V_18 , L_7 ) ;
fprintf ( V_18 , L_6 ) ;
#ifdef F_14
fprintf ( V_18 , L_8 ) ;
fprintf ( V_18 , L_9 ) ;
fprintf ( V_18 , L_10 ) ;
fprintf ( V_18 , L_11 ) ;
fprintf ( V_18 , L_12 ) ;
#ifdef F_15
fprintf ( V_18 , L_13 ) ;
#endif
#ifdef F_16
fprintf ( V_18 , L_14 , V_19 ) ;
#endif
fprintf ( V_18 , L_15 ) ;
fprintf ( V_18 , L_16 ) ;
fprintf ( V_18 , L_17 ) ;
fprintf ( V_18 , L_6 ) ;
fprintf ( V_18 , L_18 ) ;
fprintf ( V_18 , L_19 ) ;
fprintf ( V_18 , L_20 ) ;
fprintf ( V_18 , L_21 ) ;
fprintf ( V_18 , L_22 ) ;
fprintf ( V_18 , L_23 ) ;
fprintf ( V_18 , L_24 ) ;
fprintf ( V_18 , L_25 ) ;
fprintf ( V_18 , L_26 ) ;
#endif
#ifdef F_17
fprintf ( V_18 , L_27 ) ;
fprintf ( V_18 , L_28 ) ;
#endif
fprintf ( V_18 , L_29 ) ;
fprintf ( V_18 , L_30 ) ;
fprintf ( V_18 , L_6 ) ;
fprintf ( V_18 , L_31 ) ;
fprintf ( V_18 , L_32 ) ;
fprintf ( V_18 , L_33 ) ;
fprintf ( V_18 , L_34 ) ;
fprintf ( V_18 , L_35 ) ;
fprintf ( V_18 , L_36 ) ;
fprintf ( V_18 , L_37 ) ;
fprintf ( V_18 , L_38 , V_20 ) ;
fprintf ( V_18 , L_39 ) ;
fprintf ( V_18 , L_40 ) ;
fprintf ( V_18 , L_41 ) ;
fprintf ( V_18 , L_42 ) ;
fprintf ( V_18 , L_43 ) ;
fprintf ( V_18 , L_44 ) ;
fprintf ( V_18 , L_45 ) ;
fprintf ( V_18 , L_46 ) ;
fprintf ( V_18 , L_47 ) ;
fprintf ( V_18 , L_48 ) ;
fprintf ( V_18 , L_49 ) ;
fprintf ( V_18 , L_50 ) ;
fprintf ( V_18 , L_51 ) ;
fprintf ( V_18 , L_52 ) ;
fprintf ( V_18 , L_53 ) ;
fprintf ( V_18 , L_54 ) ;
fprintf ( V_18 , L_55 ) ;
fprintf ( V_18 , L_56 ) ;
fprintf ( V_18 , L_57 ) ;
fprintf ( V_18 , L_58 ) ;
fprintf ( V_18 , L_59 ) ;
fprintf ( V_18 , L_60 ) ;
fprintf ( V_18 , L_61 ) ;
fprintf ( V_18 , L_62 ) ;
fprintf ( V_18 , L_63 ) ;
fprintf ( V_18 , L_64 ) ;
fprintf ( V_18 , L_65 ) ;
fprintf ( V_18 , L_66 ) ;
fprintf ( V_18 , L_67 ) ;
fprintf ( V_18 , L_68 ) ;
fprintf ( V_18 , L_69 ) ;
fprintf ( V_18 , L_70 ) ;
fprintf ( V_18 , L_71 ) ;
fprintf ( V_18 , L_72 ) ;
fprintf ( V_18 , L_73 ) ;
fprintf ( V_18 , L_74 ) ;
fprintf ( V_18 , L_75 ) ;
fprintf ( V_18 , L_76 ) ;
fprintf ( V_18 , L_77 ) ;
fprintf ( V_18 , L_78 ) ;
fprintf ( V_18 , L_79 ) ;
fprintf ( V_18 , L_80 ) ;
fprintf ( V_18 , L_81 ) ;
fprintf ( V_18 , L_82 ) ;
fprintf ( V_18 , L_83 ) ;
fprintf ( V_18 , L_84 ) ;
fprintf ( V_18 , L_85 ) ;
fprintf ( V_18 , L_86 ) ;
fprintf ( V_18 , L_87 ) ;
fprintf ( V_18 , L_88 ) ;
fprintf ( V_18 , L_89 ) ;
fprintf ( V_18 , L_6 ) ;
fprintf ( V_18 , L_90 ) ;
fprintf ( V_18 , L_91 ) ;
fprintf ( V_18 , L_92 ) ;
fprintf ( V_18 , L_93 ) ;
fprintf ( V_18 , L_94 ) ;
fprintf ( V_18 , L_95 ) ;
fprintf ( V_18 , L_96 ) ;
fprintf ( V_18 , L_97 ) ;
#ifdef F_18
fprintf ( V_18 , L_6 ) ;
fprintf ( V_18 , L_98 ) ;
fprintf ( V_18 , L_99 ) ;
fprintf ( V_18 , L_100 ) ;
fprintf ( V_18 , L_6 ) ;
#endif
}
static void
F_19 ( void )
{
T_6 * V_18 ;
V_18 = stdout ;
fprintf ( V_18 , L_101 , F_20 () ) ;
fprintf ( V_18 , L_6 ) ;
fprintf ( V_18 , L_102 ) ;
fprintf ( V_18 , L_6 ) ;
fprintf ( V_18 , L_103 ) ;
fprintf ( V_18 , L_104 ) ;
fprintf ( V_18 , L_105 ) ;
fprintf ( V_18 , L_106 ) ;
fprintf ( V_18 , L_107 ) ;
fprintf ( V_18 , L_108 ) ;
fprintf ( V_18 , L_109 ) ;
fprintf ( V_18 , L_110 ) ;
fprintf ( V_18 , L_111 ) ;
fprintf ( V_18 , L_112 ) ;
fprintf ( V_18 , L_113 ) ;
fprintf ( V_18 , L_6 ) ;
fprintf ( V_18 , L_114 ) ;
fprintf ( V_18 , L_115 ) ;
fprintf ( V_18 , L_116 ) ;
fprintf ( V_18 , L_6 ) ;
}
static void
F_21 ( const T_7 * V_21 , T_8 V_22 ,
const T_7 * V_23 , T_3 V_24 )
{
if ( ( V_22 & V_25 & V_26 . V_27 ) == 0 &&
V_26 . V_27 != 0 ) {
return;
}
F_22 ( V_21 , V_22 , V_23 , V_24 ) ;
}
static char *
F_23 ( const char * V_28 )
{
char * V_29 ;
if ( strcmp ( V_28 , L_117 ) == 0 ) {
V_29 = F_24 ( L_118 ) ;
} else {
V_29 = F_25 ( L_119 , V_28 ) ;
}
return V_29 ;
}
static void
F_26 ( void ) {
T_7 * V_30 , * V_31 ;
if ( F_27 () ) {
V_30 = F_28 () ;
V_31 = F_29 () ;
fprintf ( V_7 , L_120 ,
V_30 , V_31 ) ;
F_11 ( V_30 ) ;
F_11 ( V_31 ) ;
if ( F_30 () ) {
fprintf ( V_7 , L_121 ) ;
}
fprintf ( V_7 , L_6 ) ;
}
}
static void
F_31 ( T_9 * V_32 )
{
F_32 ( V_32 ) ;
}
static void
F_33 ( T_9 * V_32 )
{
#ifdef F_14
F_34 ( V_32 , L_122 ) ;
F_35 ( V_32 ) ;
#endif
F_36 ( V_32 ) ;
}
int
main ( int V_33 , char * V_34 [] )
{
T_9 * V_35 ;
T_9 * V_36 ;
char * V_37 ;
int V_38 ;
static const struct V_39 V_40 [] = {
{ L_123 , V_41 , NULL , 'h' } ,
{ L_124 , V_41 , NULL , 'v' } ,
V_42
{ 0 , 0 , 0 , 0 }
} ;
T_10 V_43 = FALSE ;
#ifdef F_37
T_11 V_44 ;
#endif
char * V_45 , * V_46 ;
char * V_47 , * V_48 ;
char * V_49 ;
int V_50 , V_51 ;
int V_52 , V_53 ;
int V_54 , V_55 ;
int V_56 , V_57 ;
int V_58 ;
int V_59 ;
volatile int V_60 = 0 ;
#ifdef F_14
T_10 V_61 = FALSE ;
T_10 V_62 = FALSE ;
int V_63 ;
T_12 * V_64 ;
T_7 * V_65 ;
#else
T_10 V_66 = FALSE ;
#endif
T_10 V_67 = FALSE ;
#ifdef F_38
volatile int V_68 = V_69 ;
#else
volatile int V_68 = V_70 ;
#endif
volatile T_10 V_71 = FALSE ;
volatile int V_72 = V_73 ;
T_7 * volatile V_74 = NULL ;
T_7 * V_75 = NULL ;
T_7 * V_76 = NULL ;
#ifdef F_39
struct V_77 V_78 ;
#endif
T_13 * V_79 = NULL ;
T_13 * V_80 = NULL ;
T_7 * V_81 ;
T_14 * V_82 ;
char V_83 ;
int V_84 ;
T_7 * V_85 = NULL ;
T_5 * V_86 = NULL ;
T_5 * V_87 = NULL ;
T_5 * V_88 = NULL ;
T_7 * volatile V_89 = NULL ;
T_15 V_90 ;
#define F_40 "+2" OPTSTRING_CAPTURE_COMMON "C:d:e:E:F:gG:hH:j:" "K:lnN:o:O:PqQr:R:S:t:T:u:U:vVw:W:xX:Y:z:"
static const char V_91 [] = F_40 ;
F_41 ( L_125 , V_33 ) ;
setlocale ( V_92 , L_126 ) ;
F_42 ( V_93 , V_94 ) ;
#ifdef F_37
F_43 ( V_33 , V_34 ) ;
F_44 () ;
#if ! F_45 ( 2 , 31 , 0 )
F_46 ( NULL ) ;
#endif
#endif
F_47 () ;
F_48 () ;
F_26 () ;
V_37 = F_49 ( V_34 [ 0 ] , main ) ;
if ( V_37 != NULL ) {
fprintf ( V_7 , L_127 ,
V_37 ) ;
}
F_50 () ;
#ifdef F_37
F_51 () ;
F_52 () ;
if ( ! F_53 () && F_54 () >= 6 ) {
fprintf ( V_7 , L_128
L_129 ) ;
}
#endif
V_35 = F_55 ( F_31 ,
V_95 ) ;
V_36 = F_56 ( F_33 ) ;
F_57 ( L_101
L_6
L_130
L_6
L_130 ,
F_20 () , V_35 -> V_32 , V_36 -> V_32 ) ;
F_58 ( V_35 , TRUE ) ;
F_58 ( V_36 , TRUE ) ;
V_96 = 0 ;
while ( ( V_38 = F_59 ( V_33 , V_34 , V_91 , V_40 , NULL ) ) != - 1 ) {
switch ( V_38 ) {
case 'C' :
if ( F_60 ( V_97 , FALSE ) ) {
F_61 ( V_97 ) ;
} else {
F_62 ( L_131 , V_97 ) ;
return 1 ;
}
break;
case 'P' :
V_98 = TRUE ;
V_99 = TRUE ;
break;
case 'O' :
V_85 = F_24 ( V_97 ) ;
case 'V' :
V_100 = TRUE ;
V_98 = TRUE ;
break;
case 'x' :
V_101 = TRUE ;
V_98 = TRUE ;
break;
case 'X' :
F_63 ( V_97 ) ;
break;
default:
break;
}
}
if ( V_99 == - 1 )
V_99 = ( V_100 || V_101 ) ? FALSE : TRUE ;
V_84 =
V_102 |
V_103 |
V_104 |
V_105 |
V_106 |
V_107 |
V_108 | V_109 ;
F_64 ( NULL ,
( T_8 ) V_84 ,
F_21 , NULL ) ;
F_64 ( V_110 ,
( T_8 ) V_84 ,
F_21 , NULL ) ;
#ifdef F_14
F_64 ( V_111 ,
( T_8 ) V_84 ,
F_21 , NULL ) ;
F_64 ( V_112 ,
( T_8 ) V_84 ,
F_21 , NULL ) ;
#endif
F_65 ( V_93 , V_113 , V_114 ,
V_115 ) ;
#ifdef F_14
F_66 ( & V_116 ) ;
F_67 ( & V_117 , & V_118 ) ;
#endif
F_68 ( V_119 ) ;
F_69 ( V_120 ) ;
F_70 ( V_121 ) ;
F_71 () ;
#ifdef F_72
F_73 () ;
F_74 () ;
F_75 () ;
F_76 () ;
#endif
if ( ! F_77 ( V_122 , V_123 , NULL ,
NULL ) )
return 2 ;
#ifdef F_72
F_78 () ;
#endif
F_79 () ;
F_80 ( V_124 ) ;
F_81 ( V_125 ) ;
F_82 ( V_126 , NULL ) ;
F_83 ( V_127 , NULL ) ;
F_84 ( V_128 , NULL ) ;
if ( V_33 >= 2 && strcmp ( V_34 [ 1 ] , L_132 ) == 0 ) {
F_85 () ;
if ( V_33 == 2 )
F_86 () ;
else {
if ( strcmp ( V_34 [ 2 ] , L_133 ) == 0 )
F_87 () ;
else if ( strcmp ( V_34 [ 2 ] , L_134 ) == 0 ) {
F_88 ( & V_50 , & V_51 , & V_45 ,
& V_52 , & V_53 , & V_46 ) ;
F_89 ( NULL ) ;
}
else if ( strcmp ( V_34 [ 2 ] , L_135 ) == 0 )
F_90 () ;
else if ( strcmp ( V_34 [ 2 ] , L_136 ) == 0 )
F_89 ( NULL ) ;
else if ( strcmp ( V_34 [ 2 ] , L_137 ) == 0 )
F_91 () ;
else if ( strcmp ( V_34 [ 2 ] , L_138 ) == 0 ) {
return F_92 () ;
} else if ( strcmp ( V_34 [ 2 ] , L_139 ) == 0 )
F_86 () ;
else if ( strcmp ( V_34 [ 2 ] , L_140 ) == 0 )
F_93 () ;
else if ( strcmp ( V_34 [ 2 ] , L_141 ) == 0 )
F_94 () ;
else if ( strcmp ( V_34 [ 2 ] , L_142 ) == 0 ) {
#ifdef F_72
F_95 () ;
#endif
#ifdef F_96
F_97 () ;
#endif
}
else if ( strcmp ( V_34 [ 2 ] , L_143 ) == 0 )
F_98 () ;
else if ( strcmp ( V_34 [ 2 ] , L_144 ) == 0 )
F_99 () ;
else if ( strcmp ( V_34 [ 2 ] , L_145 ) == 0 )
F_19 () ;
else if ( strcmp ( V_34 [ 2 ] , L_146 ) == 0 )
F_19 () ;
else {
F_62 ( L_147 , V_34 [ 2 ] ) ;
return 1 ;
}
}
return 0 ;
}
F_100 () ;
F_41 ( L_148 ) ;
V_82 = F_88 ( & V_50 , & V_51 , & V_45 ,
& V_52 , & V_53 , & V_46 ) ;
if ( V_45 != NULL ) {
if ( V_50 != 0 ) {
F_62 ( L_149 ,
V_46 , F_101 ( V_50 ) ) ;
}
if ( V_51 != 0 ) {
F_62 ( L_150 ,
V_46 , F_101 ( V_51 ) ) ;
}
}
if ( V_46 != NULL ) {
if ( V_52 != 0 ) {
F_62 ( L_151 , V_46 ,
F_101 ( V_52 ) ) ;
}
if ( V_53 != 0 ) {
F_62 ( L_152 ,
V_46 , F_101 ( V_53 ) ) ;
}
F_11 ( V_46 ) ;
V_46 = NULL ;
}
F_102 ( V_129 , & V_49 , & V_58 ) ;
if ( V_49 != NULL ) {
F_62 ( L_153 ,
V_49 , F_101 ( V_58 ) ) ;
F_11 ( V_49 ) ;
}
F_103 ( & V_47 , & V_54 , & V_55 ,
& V_48 , & V_56 , & V_57 ) ;
F_104 ( & V_47 , & V_54 , & V_55 ,
& V_48 , & V_56 , & V_57 ) ;
if ( V_47 != NULL ) {
if ( V_54 != 0 ) {
F_62 ( L_154 ,
V_47 , F_101 ( V_54 ) ) ;
}
if ( V_55 != 0 ) {
F_62 ( L_155 ,
V_47 , F_101 ( V_55 ) ) ;
}
F_11 ( V_47 ) ;
}
if ( V_48 != NULL ) {
if ( V_56 != 0 ) {
F_62 (
L_156 , V_48 ,
F_101 ( V_56 ) ) ;
}
if ( V_57 != 0 ) {
F_62 (
L_157 , V_48 ,
F_101 ( V_57 ) ) ;
}
F_11 ( V_48 ) ;
}
F_105 ( & V_118 ) ;
V_130 = V_131 ;
V_132 = F_106 () ;
#ifdef F_107
V_133 = 1 ;
V_134 = 1 ;
#else
V_134 = 0 ;
#endif
V_96 = 1 ;
while ( ( V_38 = F_59 ( V_33 , V_34 , V_91 , V_40 , NULL ) ) != - 1 ) {
switch ( V_38 ) {
case '2' :
V_135 = TRUE ;
break;
case 'a' :
case 'b' :
case 'c' :
case 'f' :
case 'g' :
case 'i' :
case 'p' :
#ifdef F_17
case 'A' :
#endif
#ifdef F_15
case 'I' :
#endif
case 's' :
case 'w' :
case 'y' :
case V_136 :
#ifdef F_16
case 'B' :
#endif
#ifdef F_14
V_63 = F_108 ( & V_116 , V_38 , V_97 , & V_62 ) ;
if ( V_63 != 0 ) {
return V_63 ;
}
#else
if ( V_38 == 'w' ) {
V_137 = V_97 ;
} else {
V_66 = TRUE ;
V_43 = TRUE ;
}
#endif
break;
case 'C' :
break;
case 'd' :
if ( ! F_109 ( V_97 ) )
return 1 ;
break;
#if F_110 ( V_138 ) || F_110 ( V_139 )
case 'K' :
F_111 ( V_97 ) ;
break;
#endif
case 'D' :
#ifdef F_14
V_64 = F_112 ( & V_59 , & V_65 , NULL ) ;
if ( V_64 == NULL ) {
if ( V_59 == 0 )
F_62 ( L_158 ) ;
else {
F_62 ( L_130 , V_65 ) ;
F_11 ( V_65 ) ;
}
return 2 ;
}
F_113 ( V_64 ) ;
F_114 ( V_64 ) ;
return 0 ;
#else
V_66 = TRUE ;
V_43 = TRUE ;
#endif
break;
case 'e' :
F_115 ( V_132 , V_97 ) ;
break;
case 'E' :
if ( ! F_116 ( V_132 , V_97 ) ) {
F_62 ( L_159 , V_97 ) ;
F_117 ( V_7 ) ;
return 1 ;
}
break;
case 'F' :
V_68 = F_118 ( V_97 ) ;
if ( V_68 < 0 ) {
F_62 ( L_160 , V_97 ) ;
F_3 () ;
return 1 ;
}
break;
case 'j' :
V_140 = F_119 ( F_120 () , V_97 , L_161 , - 1 ) ;
break;
case 'W' :
if ( strchr ( V_97 , 'n' ) ) {
V_71 = TRUE ;
} else {
F_62 ( L_162 , V_97 ) ;
F_121 ( L_163 ) ;
return 1 ;
}
break;
case 'H' :
if ( ! F_122 ( V_97 ) )
{
F_62 ( L_164 , V_97 ) ;
return 1 ;
}
V_71 = TRUE ;
break;
case 'h' :
printf ( L_101
L_165
L_166 ,
F_20 () ) ;
F_13 ( stdout ) ;
return 0 ;
break;
case 'l' :
V_141 = TRUE ;
break;
case 'L' :
#ifdef F_14
V_61 = TRUE ;
#else
V_66 = TRUE ;
V_43 = TRUE ;
#endif
break;
case 'n' :
F_123 () ;
break;
case 'N' :
V_83 = F_124 ( V_97 , & V_142 ) ;
if ( V_83 != '\0' ) {
F_62 ( L_167 ,
V_83 ) ;
F_121 ( L_168
L_169
L_170
L_171
L_172
L_173 ) ;
return 1 ;
}
break;
case 'o' :
switch ( F_125 ( V_97 ) ) {
case V_143 :
break;
case V_144 :
F_62 ( L_174 , V_97 ) ;
return 1 ;
break;
case V_145 :
case V_146 :
F_62 ( L_175 , V_97 ) ;
return 1 ;
break;
}
break;
case 'q' :
V_67 = TRUE ;
break;
case 'Q' :
V_67 = TRUE ;
V_147 = TRUE ;
break;
case 'r' :
V_74 = F_24 ( V_97 ) ;
break;
case 'R' :
V_75 = V_97 ;
break;
case 'P' :
break;
case 'S' :
V_148 = V_97 ;
break;
case 't' :
if ( strcmp ( V_97 , L_176 ) == 0 )
F_68 ( V_119 ) ;
else if ( strcmp ( V_97 , L_177 ) == 0 )
F_68 ( V_149 ) ;
else if ( strcmp ( V_97 , L_178 ) == 0 )
F_68 ( V_150 ) ;
else if ( strcmp ( V_97 , L_179 ) == 0 )
F_68 ( V_151 ) ;
else if ( strcmp ( V_97 , L_180 ) == 0 )
F_68 ( V_152 ) ;
else if ( strcmp ( V_97 , L_181 ) == 0 )
F_68 ( V_153 ) ;
else if ( strcmp ( V_97 , L_182 ) == 0 )
F_68 ( V_154 ) ;
else if ( strcmp ( V_97 , L_183 ) == 0 )
F_68 ( V_155 ) ;
else if ( strcmp ( V_97 , L_184 ) == 0 )
F_68 ( V_156 ) ;
else if ( strcmp ( V_97 , L_185 ) == 0 )
F_68 ( V_157 ) ;
else {
F_62 ( L_186 , V_97 ) ;
F_121 ( L_187
L_188
L_189
L_190
L_191
L_192
L_193
L_194
L_195
L_196 ) ;
return 1 ;
}
break;
case 'T' :
V_98 = TRUE ;
if ( strcmp ( V_97 , L_197 ) == 0 ) {
V_158 = V_159 ;
V_130 = V_131 ;
} else if ( strcmp ( V_97 , L_198 ) == 0 ) {
V_158 = V_159 ;
V_130 = V_160 ;
} else if ( strcmp ( V_97 , L_199 ) == 0 ) {
V_158 = V_161 ;
V_100 = TRUE ;
V_99 = FALSE ;
} else if ( strcmp ( V_97 , L_200 ) == 0 ) {
V_158 = V_161 ;
V_100 = FALSE ;
V_99 = TRUE ;
} else if ( strcmp ( V_97 , L_139 ) == 0 ) {
V_158 = V_162 ;
V_100 = TRUE ;
V_99 = FALSE ;
} else if ( strcmp ( V_97 , L_201 ) == 0 ) {
V_158 = V_163 ;
V_100 = TRUE ;
V_99 = FALSE ;
} else if ( strcmp ( V_97 , L_202 ) == 0 ) {
V_158 = V_164 ;
V_100 = TRUE ;
V_99 = FALSE ;
}
else {
F_62 ( L_203 , V_97 ) ;
F_121 ( L_204
L_205
L_206
L_207
L_208
L_209
L_210
L_211
L_212
L_213
L_214
L_215
L_216
L_217
L_218
L_219
L_220
L_218
L_221
L_222
L_223
L_224 ) ;
return 1 ;
}
break;
case 'u' :
if ( strcmp ( V_97 , L_225 ) == 0 )
F_70 ( V_121 ) ;
else if ( strcmp ( V_97 , L_226 ) == 0 )
F_70 ( V_165 ) ;
else {
F_62 ( L_227 , V_97 ) ;
F_121 ( L_228
L_229 ) ;
return 1 ;
}
break;
case 'U' :
{
T_5 * V_166 = NULL ;
if ( ! * V_97 ) {
F_62 ( L_230 ) ;
for ( V_166 = F_126 () ; V_166 ; V_166 = F_127 ( V_166 ) ) {
F_62 ( L_231 , ( const char * ) ( V_166 -> V_5 ) ) ;
}
return 1 ;
}
V_89 = F_24 ( V_97 ) ;
break;
}
case 'v' :
V_35 = F_55 ( F_31 ,
V_95 ) ;
V_36 = F_56 ( F_33 ) ;
F_128 ( L_232 , V_35 , V_36 ) ;
F_58 ( V_35 , TRUE ) ;
F_58 ( V_36 , TRUE ) ;
#ifdef F_129
F_130 () ;
#endif
F_131 () ;
return 0 ;
case 'O' :
break;
case 'V' :
break;
case 'x' :
break;
case 'X' :
break;
case 'Y' :
V_76 = V_97 ;
break;
case 'z' :
if ( strcmp ( L_123 , V_97 ) == 0 ) {
fprintf ( V_7 , L_233 ) ;
F_132 () ;
return 0 ;
}
if ( ! F_133 ( V_97 ) ) {
F_62 ( L_234 , V_97 ) ;
F_132 () ;
return 1 ;
}
break;
case V_167 :
V_86 = F_134 ( V_86 , V_97 ) ;
break;
case V_168 :
V_87 = F_134 ( V_87 , V_97 ) ;
break;
case V_169 :
V_88 = F_134 ( V_88 , V_97 ) ;
break;
default:
case '?' :
switch( V_170 ) {
case 'F' :
F_3 () ;
break;
default:
F_13 ( V_7 ) ;
}
return 1 ;
break;
}
}
if ( ( V_162 != V_158 && V_161 != V_158 && V_163 != V_158 && V_164 != V_158 ) && 0 != F_135 ( V_132 ) ) {
F_62 ( L_235
L_236 ) ;
return 1 ;
} else if ( V_162 == V_158 && 0 == F_135 ( V_132 ) ) {
F_62 ( L_237
L_238 ) ;
return 1 ;
}
if ( V_134 < V_33 ) {
if ( V_74 != NULL ) {
if ( V_76 != NULL ) {
F_62 ( L_239
L_240 ) ;
return 1 ;
}
V_76 = F_136 ( V_33 , V_34 , V_134 ) ;
} else {
#ifdef F_14
T_16 V_9 ;
if ( V_116 . V_171 . V_172 ) {
F_62 ( L_241
L_242 ) ;
return 1 ;
}
for ( V_9 = 0 ; V_9 < V_116 . V_173 -> V_174 ; V_9 ++ ) {
T_17 V_175 ;
V_175 = F_137 ( V_116 . V_173 , T_17 , V_9 ) ;
if ( V_175 . V_172 == NULL ) {
V_175 . V_172 = F_136 ( V_33 , V_34 , V_134 ) ;
V_116 . V_173 = F_138 ( V_116 . V_173 , V_9 ) ;
F_139 ( V_116 . V_173 , V_9 , V_175 ) ;
} else {
F_62 ( L_243
L_242 ) ;
return 1 ;
}
}
V_116 . V_171 . V_172 = F_136 ( V_33 , V_34 , V_134 ) ;
#else
V_66 = TRUE ;
#endif
}
}
#ifdef F_14
if ( ! V_116 . V_176 ) {
if ( ! V_67 )
V_98 = TRUE ;
} else {
if ( strcmp ( V_116 . V_177 , L_117 ) == 0 && V_98 ) {
F_62 ( L_244
L_245 ) ;
return 1 ;
}
}
#else
if ( ! V_67 )
V_98 = TRUE ;
#endif
#ifndef F_14
if ( V_66 )
F_62 ( L_246 ) ;
#endif
if ( V_43 ) {
F_13 ( V_7 ) ;
return 1 ;
}
if ( V_101 ) {
if ( V_158 != V_159 && V_158 != V_163 && V_158 != V_164 ) {
F_62 ( L_247 ) ;
return 1 ;
}
}
if ( V_85 != NULL ) {
char * V_178 ;
if ( ! V_100 ) {
F_62 ( L_248 ) ;
return 1 ;
}
V_179 = F_140 ( V_180 , V_181 ) ;
for ( V_178 = strtok ( V_85 , L_249 ) ; V_178 ; V_178 = strtok ( NULL , L_249 ) ) {
F_141 ( V_179 , ( T_3 ) V_178 , ( T_3 ) V_178 ) ;
}
}
if ( V_75 != NULL && ! V_135 ) {
F_62 ( L_250 ) ;
return 1 ;
}
#ifdef F_14
if ( V_61 ) {
if ( V_74 ) {
F_62 ( L_251 ) ;
return 1 ;
}
if ( V_116 . V_182 ) {
F_62 ( L_252 ) ;
return 1 ;
}
} else {
if ( V_74 ) {
if ( V_116 . V_171 . V_172 ) {
F_62 ( L_253
L_254 ) ;
return 1 ;
}
if ( V_116 . V_182 ) {
F_62 ( L_255
L_256 ) ;
return 1 ;
}
if ( V_116 . V_183 ) {
F_62 ( L_257
L_256 ) ;
return 1 ;
}
if ( V_116 . V_184 ) {
F_62 ( L_258
L_256 ) ;
return 1 ;
}
if ( V_116 . V_185 ) {
F_62 ( L_259
L_256 ) ;
return 1 ;
}
if ( V_116 . V_186 ) {
F_62 ( L_260
L_261
L_262 ) ;
return 1 ;
}
if ( V_116 . V_187 ) {
F_62 ( L_263
L_256 ) ;
return 1 ;
}
} else {
if ( V_135 ) {
F_62 ( L_264 ) ;
return 1 ;
}
if ( V_116 . V_176 ) {
if ( V_68 != V_70 &&
V_68 != V_69 ) {
F_62 ( L_265 ) ;
return 1 ;
}
if ( V_116 . V_186 &&
V_68 != V_69 ) {
F_62 ( L_266 ) ;
return 1 ;
}
if ( V_116 . V_182 ) {
if ( strcmp ( V_116 . V_177 , L_117 ) == 0 ) {
F_62 ( L_255
L_267 ) ;
return 1 ;
}
if ( V_116 . V_188 ) {
F_62 ( L_255
L_268 ) ;
return 1 ;
}
if ( ! V_116 . V_189 &&
! V_116 . V_183 ) {
F_62 ( L_255
L_269 ) ;
return 1 ;
}
}
if ( V_75 != NULL ) {
F_62 ( L_270 ) ;
return 1 ;
}
if ( V_76 != NULL ) {
F_62 ( L_271 ) ;
return 1 ;
}
V_116 . V_190 = ( V_68 == V_69 ) ? TRUE : FALSE ;
} else {
if ( V_116 . V_189 ) {
F_62 ( L_272
L_273 ) ;
return 1 ;
}
if ( V_116 . V_182 ) {
F_62 ( L_255
L_274 ) ;
return 1 ;
}
if ( V_116 . V_186 ) {
F_62 ( L_260
L_274 ) ;
return 1 ;
}
}
}
}
#endif
#ifdef F_37
F_142 ( F_143 ( 1 , 1 ) , & V_44 ) ;
#endif
F_144 () ;
F_145 () ;
{
T_5 * V_191 = NULL ;
T_5 * V_192 = F_146 ( V_132 ) ;
if ( V_192 != NULL ) {
F_62 ( L_275 ) ;
for ( V_191 = V_192 ; V_191 != NULL ; V_191 = F_127 ( V_191 ) ) {
F_121 ( L_276 , ( T_7 * ) V_191 -> V_5 ) ;
}
F_10 ( V_192 ) ;
return 1 ;
}
}
#ifdef F_14
if ( V_116 . V_176 &&
V_116 . V_188 ) {
if ( F_147 () ) {
F_62 ( L_277 ) ;
return 1 ;
}
if ( V_98 ) {
F_62 ( L_278 ) ;
return 1 ;
}
}
#endif
if ( F_148 ( L_279 ) > 0 ) {
const T_7 * V_16 = F_149 ( L_279 ) ;
V_72 = F_150 ( V_16 ) ;
if ( V_72 == V_73 ) {
F_62 ( L_280 , V_16 ? V_16 : L_126 ) ;
F_12 () ;
return 1 ;
}
}
if ( V_47 == NULL && V_48 == NULL ) {
F_151 () ;
F_152 () ;
}
if( V_86 ) {
T_5 * V_193 ;
for ( V_193 = V_86 ; V_193 != NULL ; V_193 = F_127 ( V_193 ) )
{
F_153 ( ( char * ) V_193 -> V_5 ) ;
}
}
if( V_87 ) {
T_5 * V_194 ;
for ( V_194 = V_87 ; V_194 != NULL ; V_194 = F_127 ( V_194 ) )
{
F_154 ( ( char * ) V_194 -> V_5 , TRUE ) ;
}
}
if( V_88 ) {
T_5 * V_195 ;
for ( V_195 = V_88 ; V_195 != NULL ; V_195 = F_127 ( V_195 ) )
{
F_154 ( ( char * ) V_195 -> V_5 , FALSE ) ;
}
}
F_155 ( & V_118 . V_196 , V_82 -> V_197 , TRUE ) ;
#ifdef F_14
F_156 ( & V_116 , V_198 ) ;
F_157 ( & V_116 ) ;
#endif
if ( V_75 != NULL ) {
F_41 ( L_281 , V_75 ) ;
if ( ! F_158 ( V_75 , & V_79 , & V_81 ) ) {
F_62 ( L_130 , V_81 ) ;
F_11 ( V_81 ) ;
#ifdef F_129
F_130 () ;
#endif
F_131 () ;
#ifdef F_39
{
T_18 * V_199 ;
V_199 = F_159 ( V_200 , V_198 ) ;
if ( V_199 != NULL ) {
if ( F_160 ( V_199 , & V_78 , V_75 , 0 , 0 ) != - 1 ) {
F_121 (
L_282
L_283 ) ;
}
F_161 ( V_199 ) ;
}
}
#endif
return 2 ;
}
}
V_118 . V_79 = V_79 ;
if ( V_76 != NULL ) {
F_41 ( L_284 , V_76 ) ;
if ( ! F_158 ( V_76 , & V_80 , & V_81 ) ) {
F_62 ( L_130 , V_81 ) ;
F_11 ( V_81 ) ;
#ifdef F_129
F_130 () ;
#endif
F_131 () ;
#ifdef F_39
{
T_18 * V_199 ;
V_199 = F_159 ( V_200 , V_198 ) ;
if ( V_199 != NULL ) {
if ( F_160 ( V_199 , & V_78 , V_76 , 0 , 0 ) != - 1 ) {
F_121 (
L_285
L_283 ) ;
}
F_161 ( V_199 ) ;
}
}
#endif
return 2 ;
}
}
V_118 . V_80 = V_80 ;
if ( V_98 ) {
if ( V_158 == V_159 ) {
switch ( V_130 ) {
case V_131 :
V_201 = F_162 ( stdout ) ;
break;
case V_160 :
V_201 = F_163 ( stdout ) ;
break;
default:
F_164 () ;
}
}
}
if ( V_89 ) {
const char * V_202 ;
const char * V_203 = V_89 ;
const char * V_204 = V_76 ;
char * V_205 ;
int V_206 ;
if ( ! V_74 ) {
F_62 ( L_286 ) ;
return 1 ;
}
#ifdef F_14
V_202 = V_116 . V_177 ;
V_116 . V_177 = NULL ;
#else
V_202 = V_137 ;
V_137 = NULL ;
#endif
if ( V_202 == NULL ) {
F_62 ( L_287 ) ;
return 1 ;
}
V_205 = F_165 ( V_203 , V_204 ,
& V_90 ) ;
if ( V_205 ) {
F_62 ( L_288 , V_205 ) ;
F_11 ( V_205 ) ;
return 2 ;
}
V_206 = F_166 ( V_202 , V_207 | V_208 | V_209 | V_210 , 0644 ) ;
if ( V_206 == - 1 ) {
F_62 ( L_289 , V_202 , F_167 ( V_211 , TRUE ) ) ;
return 2 ;
}
V_59 = F_168 ( & V_90 , V_206 ,
F_25 ( L_290 , V_74 ) ) ;
if ( V_59 != 0 ) {
F_62 ( L_291 , F_101 ( V_59 ) ) ;
return 2 ;
}
}
V_212 = V_98 || V_79 || V_80 || V_89 ||
F_147 () ;
F_41 ( L_292 , V_212 ? L_293 : L_294 ) ;
if ( V_74 ) {
F_41 ( L_295 , V_74 ) ;
if ( F_169 ( & V_118 , V_74 , V_72 , FALSE , & V_59 ) != V_213 ) {
#ifdef F_129
F_130 () ;
#endif
F_131 () ;
return 2 ;
}
F_41 ( L_296 ) ;
F_170 {
#ifdef F_14
V_59 = F_171 ( & V_118 , V_116 . V_177 , V_68 , V_71 ,
V_116 . V_214 ? V_116 . V_215 : 0 ,
V_116 . V_189 ? V_116 . V_216 : 0 ) ;
#else
V_59 = F_171 ( & V_118 , V_137 , V_68 , V_71 , 0 , 0 ) ;
#endif
}
F_172 (OutOfMemoryError) {
fprintf ( V_7 ,
L_297
L_6
L_298
L_6
L_299
L_300 ) ;
V_59 = V_217 ;
}
V_218 ;
if ( V_59 != 0 ) {
V_60 = 2 ;
}
if ( V_89 ) {
V_59 = F_173 ( & V_90 ) ;
if ( V_59 ) {
F_62 ( L_130 , F_174 ( V_59 ) ) ;
V_60 = 2 ;
}
F_11 ( V_89 ) ;
}
} else {
F_41 ( L_301 ) ;
#ifdef F_14
V_60 = F_175 ( & V_116 ,
( ( V_82 -> V_219 ) && ( * V_82 -> V_219 != '\0' ) ) ? F_176 ( V_82 -> V_219 ) : NULL ) ;
if ( V_60 != 0 )
return V_60 ;
if ( V_61 ) {
T_16 V_9 ;
for ( V_9 = 0 ; V_9 < V_116 . V_173 -> V_174 ; V_9 ++ ) {
T_17 V_175 ;
T_19 * V_220 ;
char * V_221 = NULL ;
V_175 = F_137 ( V_116 . V_173 , T_17 , V_9 ) ;
#ifdef F_17
if ( V_175 . V_222 == V_223 ) {
V_221 = F_25 ( L_302 , V_175 . V_224 , V_175 . V_225 ) ;
}
#endif
V_220 = F_177 ( V_175 . V_16 , V_175 . V_226 , V_221 , & V_65 , NULL ) ;
F_11 ( V_221 ) ;
if ( V_220 == NULL ) {
F_62 ( L_130 , V_65 ) ;
F_11 ( V_65 ) ;
return 2 ;
}
if ( V_220 -> V_227 == NULL ) {
F_62 ( L_303 , V_175 . V_16 ) ;
return 2 ;
}
F_178 ( V_220 , V_175 . V_16 , V_175 . V_226 ) ;
F_179 ( V_220 ) ;
}
return 0 ;
}
if ( ! F_180 ( F_181 ( V_7 ) ) )
V_228 = FALSE ;
else if ( V_98 && F_180 ( F_181 ( stdout ) ) )
V_228 = FALSE ;
else if ( V_67 )
V_228 = FALSE ;
else
V_228 = TRUE ;
if ( V_98 ) {
if ( ! F_182 ( & V_118 ) ) {
F_183 ( V_211 ) ;
return 2 ;
}
}
F_41 ( L_304 ) ;
F_184 () ;
V_60 = V_117 . V_229 ;
if ( V_98 ) {
if ( ! F_185 () ) {
V_59 = V_211 ;
F_183 ( V_59 ) ;
}
}
#else
F_62 ( L_246 ) ;
return 2 ;
#endif
}
F_11 ( V_74 ) ;
if ( V_118 . V_230 != NULL ) {
F_186 ( V_118 . V_230 ) ;
V_118 . V_230 = NULL ;
}
F_187 ( TRUE ) ;
F_188 () ;
F_189 ( V_118 . V_231 ) ;
#ifdef F_129
F_130 () ;
#endif
F_131 () ;
F_190 ( V_132 ) ;
V_132 = NULL ;
return V_60 ;
}
static T_1
F_191 ( T_3 V_5 )
{
T_20 V_232 ;
T_21 V_233 = 0 ;
T_10 V_234 ;
T_21 V_235 ;
T_22 * V_236 = V_5 ;
T_1 V_237 = 0 ;
F_192 ( V_236 -> V_238 ) ;
while( V_237 < 5 ) {
V_232 = ( T_20 ) F_193 ( V_236 -> V_239 ) ;
V_234 = F_194 ( V_232 , NULL , 0 , NULL , & V_233 , NULL ) ;
F_195 ( ( T_20 ) * ( V_236 -> V_240 ) ,
& V_235 ) ;
if ( ! V_234 || V_233 > 0 || V_235 != V_241 ) {
if ( ! V_236 -> V_242 ( V_236 -> V_239 , V_236 -> V_24 ) ) {
F_196 ( NULL , V_107 , L_305 , V_237 ) ;
F_197 ( V_236 -> V_238 ) ;
return FALSE ;
}
}
else {
break;
}
V_237 ++ ;
}
F_197 ( V_236 -> V_238 ) ;
return TRUE ;
}
void
F_198 ( T_1 V_239 , T_3 V_24 , T_23 * V_240 , T_24 V_242 )
{
V_243 . V_239 = V_239 ;
V_243 . V_240 = V_240 ;
V_243 . V_24 = V_24 ;
V_243 . V_242 = V_242 ;
#ifdef F_37
#if F_45 ( 2 , 31 , 0 )
V_243 . V_238 = F_199 ( sizeof( V_244 ) ) ;
F_200 ( V_243 . V_238 ) ;
#else
V_243 . V_238 = F_201 () ;
#endif
V_243 . V_245 = F_202 ( 200 , F_191 , & V_243 ) ;
#endif
}
static const T_25 *
F_203 ( void * V_5 , T_26 V_246 )
{
T_27 * V_247 = ( T_27 * ) V_5 ;
if ( V_248 && V_248 -> V_249 == V_246 )
return & V_248 -> V_250 ;
if ( V_251 && V_251 -> V_249 == V_246 )
return & V_251 -> V_250 ;
if ( V_252 && V_252 -> V_249 == V_246 )
return & V_252 -> V_250 ;
if ( V_247 -> V_230 ) {
T_28 * V_253 = F_204 ( V_247 -> V_230 , V_246 ) ;
return ( V_253 ) ? & V_253 -> V_250 : NULL ;
}
return NULL ;
}
static T_29 *
F_205 ( T_27 * V_247 )
{
T_29 * V_231 = F_206 () ;
V_231 -> V_5 = V_247 ;
V_231 -> V_254 = F_203 ;
V_231 -> V_255 = V_256 ;
V_231 -> V_257 = NULL ;
return V_231 ;
}
static T_10
F_184 ( void )
{
T_10 V_258 ;
T_16 V_9 ;
T_9 * V_32 ;
#ifdef F_207
T_30 V_259 ;
#endif
#ifndef F_37
struct V_260 V_261 , V_262 ;
#endif
F_189 ( V_118 . V_231 ) ;
V_118 . V_231 = F_205 ( & V_118 ) ;
#ifdef F_37
F_208 ( V_263 , TRUE ) ;
#else
memset ( & V_261 , 0 , sizeof( V_261 ) ) ;
V_261 . V_264 = V_263 ;
V_261 . V_265 = V_266 ;
F_209 ( & V_261 . V_267 ) ;
V_260 ( V_268 , & V_261 , NULL ) ;
V_260 ( V_269 , & V_261 , NULL ) ;
V_260 ( V_270 , NULL , & V_262 ) ;
if ( V_262 . V_264 == V_271 )
V_260 ( V_270 , & V_261 , NULL ) ;
#ifdef F_210
V_261 . V_264 = V_272 ;
V_261 . V_265 = V_266 ;
F_209 ( & V_261 . V_267 ) ;
V_260 ( F_210 , & V_261 , NULL ) ;
#endif
#endif
V_117 . V_273 = V_274 ;
for ( V_9 = 0 ; V_9 < V_116 . V_173 -> V_174 ; V_9 ++ ) {
T_17 V_175 ;
V_175 = F_137 ( V_116 . V_173 , T_17 , V_9 ) ;
V_175 . V_275 = F_211 ( V_175 . V_16 ) ;
V_116 . V_173 = F_138 ( V_116 . V_173 , V_9 ) ;
F_139 ( V_116 . V_173 , V_9 , V_175 ) ;
}
V_32 = F_212 ( & V_116 , V_276 ) ;
if ( V_147 == FALSE )
fprintf ( V_7 , L_306 , V_32 -> V_32 ) ;
fflush ( V_7 ) ;
F_58 ( V_32 , TRUE ) ;
V_258 = F_213 ( & V_116 , & V_117 , & V_277 , NULL ) ;
if ( ! V_258 )
return FALSE ;
#ifdef F_207
F_214 ( & V_259 ) ;
F_215 ( V_243 . V_239 , & V_259 ) ;
#endif
V_278 = TRUE ;
F_170
{
while ( V_278 )
{
#ifdef F_207
V_258 = F_216 ( V_243 . V_239 + 1 , & V_259 , NULL , NULL , NULL ) ;
if ( V_258 == - 1 )
{
fprintf ( V_7 , L_307 , L_308 , F_101 ( V_211 ) ) ;
return TRUE ;
} else if ( V_258 == 1 ) {
#endif
if ( ! V_243 . V_242 ( V_243 . V_239 , V_243 . V_24 ) ) {
F_196 ( NULL , V_107 , L_309 ) ;
return FALSE ;
}
#ifdef F_207
}
#endif
}
}
F_172 (OutOfMemoryError) {
fprintf ( V_7 ,
L_297
L_6
L_298
L_6
L_299
L_300 ) ;
exit ( 1 ) ;
}
V_218 ;
return TRUE ;
}
void
F_217 ( T_31 * T_32 V_6 , char * V_279 , char * V_280 )
{
F_62 ( L_130 , V_279 ) ;
F_121 ( L_130 , V_280 ) ;
}
void
F_218 ( T_31 * T_32 , T_16 V_9 , char * V_281 )
{
T_33 * V_282 = T_32 -> V_282 ;
T_13 * V_79 = NULL ;
T_17 V_175 ;
F_219 ( V_9 < V_282 -> V_173 -> V_174 ) ;
V_175 = F_137 ( V_282 -> V_173 , T_17 , V_9 ) ;
if ( F_158 ( V_175 . V_172 , & V_79 , NULL ) && V_79 != NULL ) {
F_62 (
L_310
L_6
L_311
L_312
L_6
L_313
L_314
L_6
L_315 ,
V_175 . V_172 , V_175 . V_275 , V_281 ) ;
F_220 ( V_79 ) ;
} else {
F_62 (
L_310
L_6
L_316
L_315 ,
V_175 . V_172 , V_175 . V_275 , V_281 ) ;
}
}
T_10
F_221 ( T_31 * T_32 , T_7 * V_283 )
{
T_33 * V_282 = T_32 -> V_282 ;
T_27 * V_247 = ( T_27 * ) T_32 -> V_247 ;
T_10 V_284 ;
int V_59 ;
if ( T_32 -> V_273 == V_274 ) {
F_196 ( V_111 , V_105 , L_317 ) ;
}
F_196 ( V_111 , V_105 , L_318 , V_283 ) ;
F_219 ( T_32 -> V_273 == V_274 || T_32 -> V_273 == V_285 ) ;
if ( V_282 -> V_177 != NULL ) {
if ( V_247 -> V_273 != V_286 ) {
if ( V_247 -> V_287 != NULL ) {
F_222 ( V_247 -> V_287 ) ;
V_247 -> V_287 = NULL ;
}
V_247 -> V_273 = V_286 ;
}
F_11 ( V_282 -> V_177 ) ;
V_284 = FALSE ;
F_189 ( V_247 -> V_231 ) ;
V_247 -> V_231 = F_205 ( V_247 ) ;
} else {
V_284 = TRUE ;
}
V_282 -> V_177 = F_24 ( V_283 ) ;
if ( V_212 ) {
( ( T_27 * ) T_32 -> V_247 ) -> V_288 = V_73 ;
switch( F_169 ( ( T_27 * ) T_32 -> V_247 , V_282 -> V_177 , V_73 , V_284 , & V_59 ) ) {
case V_213 :
break;
case V_289 :
F_11 ( V_282 -> V_177 ) ;
V_282 -> V_177 = NULL ;
return FALSE ;
}
}
T_32 -> V_273 = V_285 ;
return TRUE ;
}
void
F_223 ( T_31 * T_32 , int V_290 )
{
T_10 V_258 ;
int V_59 ;
T_7 * V_291 ;
T_34 V_292 ;
T_27 * V_247 = ( T_27 * ) T_32 -> V_247 ;
T_10 V_293 ;
T_16 V_294 ;
#ifdef F_210
V_295 = TRUE ;
#endif
V_293 = F_224 () ;
V_294 = F_225 () ;
if ( V_212 ) {
T_10 V_296 ;
T_35 * V_297 ;
if ( V_247 -> V_79 || V_247 -> V_80 || V_100 || V_293 ||
( V_294 & V_298 ) || F_226 ( & V_247 -> V_196 ) )
V_296 = TRUE ;
else
V_296 = FALSE ;
V_297 = F_227 ( V_247 -> V_231 , V_296 , V_98 && V_100 ) ;
while ( V_290 -- && V_247 -> V_287 ) {
F_228 ( V_247 -> V_287 ) ;
V_258 = F_229 ( V_247 -> V_287 , & V_59 , & V_291 , & V_292 ) ;
if ( V_258 == FALSE ) {
F_230 ( T_32 ) ;
F_222 ( V_247 -> V_287 ) ;
V_247 -> V_287 = NULL ;
} else {
V_258 = F_231 ( V_247 , V_297 , V_292 , F_232 ( V_247 -> V_287 ) ,
F_233 ( V_247 -> V_287 ) ,
V_294 ) ;
}
if ( V_258 != FALSE ) {
V_299 ++ ;
}
}
F_234 ( V_297 ) ;
} else {
V_299 += V_290 ;
}
if ( V_228 ) {
if ( V_299 != 0 ) {
fprintf ( V_7 , L_319 , V_299 ) ;
fflush ( V_7 ) ;
}
}
#ifdef F_210
V_295 = FALSE ;
if ( V_300 )
F_235 () ;
#endif
}
static void
F_235 ( void )
{
if ( ( V_228 == FALSE ) && ( V_147 == FALSE ) ) {
fprintf ( V_7 , L_320 , V_299 ,
F_236 ( V_299 , L_126 , L_225 ) ) ;
}
#ifdef F_210
V_300 = FALSE ;
#endif
}
static void
V_272 ( int T_36 V_6 )
{
int V_301 = V_211 ;
if ( V_295 )
V_300 = TRUE ;
else
F_235 () ;
V_211 = V_301 ;
}
void
F_237 ( T_31 * T_32 V_6 , T_26 V_302 )
{
if ( V_228 ) {
fprintf ( V_7 , L_6 ) ;
}
if ( V_302 != 0 ) {
fprintf ( V_7 , L_321 , V_302 , F_236 ( V_302 , L_126 , L_225 ) ) ;
}
}
void
F_238 ( T_31 * T_32 , T_7 * V_303 )
{
T_27 * V_247 = ( T_27 * ) T_32 -> V_247 ;
if ( V_303 != NULL )
fprintf ( V_7 , L_322 , V_303 ) ;
F_235 () ;
if ( V_247 != NULL && V_247 -> V_287 != NULL ) {
F_222 ( V_247 -> V_287 ) ;
if ( V_247 -> V_284 ) {
F_239 ( V_247 -> V_304 ) ;
}
}
#ifdef F_240
F_241 ( V_305 ) ;
#else
V_278 = FALSE ;
#endif
}
static BOOL T_37
V_263 ( T_21 T_38 V_6 )
{
F_230 ( & V_117 ) ;
return TRUE ;
}
static void
V_263 ( int T_36 V_6 )
{
F_230 ( & V_117 ) ;
}
static T_10
F_242 ( T_27 * V_247 , T_35 * V_297 ,
T_34 V_306 , struct V_307 * V_308 ,
const T_39 * V_309 )
{
T_28 V_310 ;
T_26 V_311 ;
T_10 V_312 ;
V_311 = V_247 -> V_313 + 1 ;
V_312 = TRUE ;
F_243 ( & V_310 , V_311 , V_308 , V_306 , V_314 ) ;
if ( V_297 ) {
if ( V_142 . V_315 || V_142 . V_316 ||
V_142 . V_317 )
F_244 () ;
if ( V_247 -> V_79 )
F_245 ( V_297 , V_247 -> V_79 ) ;
if ( V_247 -> V_80 )
F_245 ( V_297 , V_247 -> V_80 ) ;
F_246 ( & V_310 , & V_247 -> V_318 ,
& V_248 , V_251 ) ;
if ( V_248 == & V_310 ) {
V_319 = V_310 ;
V_248 = & V_319 ;
}
F_247 ( V_297 , V_247 -> V_320 , V_308 , F_248 ( & V_310 , V_309 ) , & V_310 , NULL ) ;
if ( V_247 -> V_79 )
V_312 = F_249 ( V_247 -> V_79 , V_297 ) ;
}
if ( V_312 ) {
F_250 ( & V_310 , & V_314 ) ;
V_252 = V_251 = F_251 ( V_247 -> V_230 , & V_310 ) ;
if ( V_297 && V_247 -> V_80 ) {
if ( F_249 ( V_247 -> V_80 , V_297 ) ) {
F_9 ( V_297 -> V_321 . V_322 , V_323 , V_247 -> V_230 ) ;
}
}
V_247 -> V_313 ++ ;
} else {
F_252 ( & V_310 ) ;
}
if ( V_297 )
F_253 ( V_297 ) ;
return V_312 ;
}
static T_10
F_254 ( T_27 * V_247 , T_35 * V_297 , T_28 * V_324 ,
struct V_307 * V_325 , T_40 * V_326 ,
T_16 V_294 )
{
T_41 * V_196 ;
T_10 V_312 ;
V_312 = TRUE ;
if ( V_297 ) {
if ( V_142 . V_315 || V_142 . V_316 ||
V_142 . V_317 )
F_244 () ;
if ( V_247 -> V_80 )
F_245 ( V_297 , V_247 -> V_80 ) ;
F_255 ( V_297 , & V_247 -> V_196 ) ;
if ( ( V_294 & V_327 ) || ( V_98 && V_99 ) || F_256 ( V_132 ) )
V_196 = & V_247 -> V_196 ;
else
V_196 = NULL ;
F_246 ( V_324 , & V_247 -> V_318 ,
& V_248 , V_251 ) ;
if ( V_248 == V_324 ) {
V_319 = * V_324 ;
V_248 = & V_319 ;
}
F_257 ( V_297 , V_247 -> V_320 , V_325 , F_258 ( V_324 , V_326 ) , V_324 , V_196 ) ;
if ( V_247 -> V_80 )
V_312 = F_249 ( V_247 -> V_80 , V_297 ) ;
}
if ( V_312 ) {
F_250 ( V_324 , & V_314 ) ;
if ( V_98 ) {
F_259 ( V_247 , V_297 ) ;
if ( V_141 )
fflush ( stdout ) ;
if ( ferror ( stdout ) ) {
F_183 ( V_211 ) ;
exit ( 2 ) ;
}
}
V_251 = V_324 ;
}
V_252 = V_324 ;
if ( V_297 ) {
F_253 ( V_297 ) ;
}
return V_312 || V_324 -> V_328 . V_329 ;
}
static int
F_171 ( T_27 * V_247 , char * V_177 , int V_68 ,
T_10 V_71 , int V_330 , T_34 V_331 )
{
T_1 V_332 ;
int V_333 ;
T_42 * V_334 ;
T_26 V_311 ;
int V_59 ;
T_7 * V_291 = NULL ;
T_34 V_292 ;
char * V_29 = NULL ;
T_10 V_293 ;
T_16 V_294 ;
T_43 * V_335 = NULL ;
T_44 * V_336 = NULL ;
T_43 * V_337 = NULL ;
struct V_307 V_325 ;
T_40 V_326 ;
T_35 * V_297 = NULL ;
char * V_338 ;
F_260 ( & V_325 ) ;
V_336 = F_261 ( V_247 -> V_287 ) ;
#ifdef F_38
if ( V_336 -> V_339 -> V_174 > 1 ) {
V_332 = V_340 ;
} else {
V_332 = F_262 ( V_247 -> V_287 ) ;
}
#else
V_332 = F_262 ( V_247 -> V_287 ) ;
#endif
if ( V_177 != NULL ) {
V_29 = F_23 ( V_177 ) ;
V_333 = F_263 ( V_247 -> V_287 ) ;
if ( V_333 == 0 ) {
V_333 = V_341 ;
}
F_41 ( L_323 , V_333 ) ;
V_335 = F_264 ( V_247 -> V_287 ) ;
V_337 = F_265 ( V_247 -> V_287 ) ;
if ( F_266 ( F_137 ( V_335 , V_342 , 0 ) , V_343 , & V_338 ) != V_344 ) {
F_267 ( F_137 ( V_335 , V_342 , 0 ) , V_343 , L_324 , F_20 () ) ;
}
if ( V_332 != V_340 &&
V_68 == V_70 ) {
F_41 ( L_325 , V_177 ) ;
if ( strcmp ( V_177 , L_117 ) == 0 ) {
V_334 = F_268 ( V_68 , V_332 ,
V_333 , FALSE , & V_59 ) ;
} else {
V_334 = F_269 ( V_177 , V_68 , V_332 ,
V_333 , FALSE , & V_59 ) ;
}
}
else {
F_41 ( L_326 , V_68 , V_177 ) ;
if ( strcmp ( V_177 , L_117 ) == 0 ) {
V_334 = F_270 ( V_68 , V_332 ,
V_333 , FALSE , V_335 , V_336 , V_337 , & V_59 ) ;
} else {
V_334 = F_271 ( V_177 , V_68 , V_332 ,
V_333 , FALSE , V_335 , V_336 , V_337 , & V_59 ) ;
}
}
F_11 ( V_336 ) ;
V_336 = NULL ;
if ( V_334 == NULL ) {
switch ( V_59 ) {
case V_345 :
F_62 ( L_327 ) ;
break;
case V_346 :
case V_347 :
F_62 ( L_328
L_329 , F_6 ( V_68 ) ) ;
break;
case V_348 :
F_62 ( L_330
L_331 , V_29 ) ;
break;
case V_349 :
F_62 ( L_332 ,
V_29 ) ;
break;
default:
F_62 ( L_333 , V_29 ,
F_174 ( V_59 ) ) ;
break;
}
goto V_350;
}
} else {
if ( V_98 ) {
if ( ! F_182 ( V_247 ) ) {
V_59 = V_211 ;
F_183 ( V_59 ) ;
goto V_350;
}
}
F_11 ( V_336 ) ;
V_336 = NULL ;
V_334 = NULL ;
}
V_293 = F_224 () ;
V_294 = F_225 () ;
if ( V_135 ) {
T_28 * V_324 ;
F_41 ( L_334 , V_212 ? L_293 : L_294 ) ;
V_247 -> V_230 = F_272 () ;
if ( V_212 ) {
T_10 V_296 = FALSE ;
if ( V_247 -> V_79 || V_247 -> V_80 )
V_296 = TRUE ;
F_41 ( L_335 , V_296 ? L_293 : L_294 ) ;
V_297 = F_227 ( V_247 -> V_231 , V_296 , FALSE ) ;
}
F_41 ( L_336 ) ;
while ( F_229 ( V_247 -> V_287 , & V_59 , & V_291 , & V_292 ) ) {
if ( F_242 ( V_247 , V_297 , V_292 , F_232 ( V_247 -> V_287 ) ,
F_233 ( V_247 -> V_287 ) ) ) {
if ( ( -- V_330 == 0 ) || ( V_331 != 0 && V_292 >= V_331 ) ) {
F_41 ( L_337 V_351 L_338 V_351 L_339 ,
V_330 , V_292 , V_331 ) ;
V_59 = 0 ;
break;
}
}
}
if ( V_297 ) {
F_234 ( V_297 ) ;
V_297 = NULL ;
}
F_273 ( V_247 -> V_287 ) ;
F_274 () ;
V_251 = NULL ;
V_252 = NULL ;
F_275 ( & V_326 , 1500 ) ;
F_41 ( L_340 ) ;
if ( V_212 ) {
T_10 V_296 ;
if ( V_247 -> V_80 || V_100 || V_293 ||
( V_294 & V_298 ) || F_226 ( & V_247 -> V_196 ) )
V_296 = TRUE ;
else
V_296 = FALSE ;
F_41 ( L_335 , V_296 ? L_293 : L_294 ) ;
V_297 = F_227 ( V_247 -> V_231 , V_296 , V_98 && V_100 ) ;
}
for ( V_311 = 1 ; V_59 == 0 && V_311 <= V_247 -> V_313 ; V_311 ++ ) {
V_324 = F_204 ( V_247 -> V_230 , V_311 ) ;
if ( F_276 ( V_247 -> V_287 , V_324 -> V_352 , & V_325 , & V_326 , & V_59 ,
& V_291 ) ) {
F_41 ( L_341 , V_311 ) ;
if ( F_254 ( V_247 , V_297 , V_324 , & V_325 , & V_326 ,
V_294 ) ) {
if ( V_334 != NULL ) {
F_41 ( L_342 , V_311 ) ;
if ( ! F_277 ( V_334 , & V_325 , F_278 ( & V_326 ) , & V_59 , & V_291 ) ) {
F_41 ( L_343 , V_59 ) ;
switch ( V_59 ) {
case V_346 :
fprintf ( V_7 ,
L_344 ,
V_311 , V_247 -> V_304 ,
F_6 ( V_68 ) ) ;
break;
case V_353 :
fprintf ( V_7 ,
L_345 ,
V_311 , V_247 -> V_304 ,
F_6 ( V_68 ) ) ;
break;
case V_354 :
fprintf ( V_7 ,
L_346 ,
V_311 , V_247 -> V_304 ,
F_6 ( V_68 ) ) ;
break;
case V_355 :
fprintf ( V_7 ,
L_347 ,
V_311 , V_247 -> V_304 ,
F_6 ( V_68 ) ,
V_291 != NULL ? V_291 : L_348 ) ;
F_11 ( V_291 ) ;
break;
default:
F_279 ( V_177 , V_59 , FALSE ) ;
break;
}
F_280 ( V_334 , & V_59 ) ;
F_281 ( V_335 ) ;
F_281 ( V_337 ) ;
exit ( 2 ) ;
}
}
}
}
}
if ( V_297 ) {
F_234 ( V_297 ) ;
V_297 = NULL ;
}
F_282 ( & V_326 ) ;
F_41 ( L_349 ) ;
}
else {
V_311 = 0 ;
F_41 ( L_350 , V_212 ? L_293 : L_294 ) ;
if ( V_212 ) {
T_10 V_296 ;
if ( V_247 -> V_79 || V_247 -> V_80 || V_100 || V_293 ||
( V_294 & V_298 ) || F_226 ( & V_247 -> V_196 ) )
V_296 = TRUE ;
else
V_296 = FALSE ;
F_41 ( L_335 , V_296 ? L_293 : L_294 ) ;
V_297 = F_227 ( V_247 -> V_231 , V_296 , V_98 && V_100 ) ;
}
while ( F_229 ( V_247 -> V_287 , & V_59 , & V_291 , & V_292 ) ) {
V_311 ++ ;
F_41 ( L_351 , V_311 ) ;
if ( F_231 ( V_247 , V_297 , V_292 , F_232 ( V_247 -> V_287 ) ,
F_233 ( V_247 -> V_287 ) ,
V_294 ) ) {
if ( V_334 != NULL ) {
F_41 ( L_342 , V_311 ) ;
if ( ! F_277 ( V_334 , F_232 ( V_247 -> V_287 ) , F_233 ( V_247 -> V_287 ) , & V_59 , & V_291 ) ) {
F_41 ( L_343 , V_59 ) ;
switch ( V_59 ) {
case V_346 :
fprintf ( V_7 ,
L_344 ,
V_311 , V_247 -> V_304 ,
F_6 ( V_68 ) ) ;
break;
case V_353 :
fprintf ( V_7 ,
L_345 ,
V_311 , V_247 -> V_304 ,
F_6 ( V_68 ) ) ;
break;
case V_354 :
fprintf ( V_7 ,
L_346 ,
V_311 , V_247 -> V_304 ,
F_6 ( V_68 ) ) ;
break;
case V_355 :
fprintf ( V_7 ,
L_347 ,
V_311 , V_247 -> V_304 ,
F_6 ( V_68 ) ,
V_291 != NULL ? V_291 : L_348 ) ;
F_11 ( V_291 ) ;
break;
default:
F_279 ( V_177 , V_59 , FALSE ) ;
break;
}
F_280 ( V_334 , & V_59 ) ;
F_281 ( V_335 ) ;
F_281 ( V_337 ) ;
exit ( 2 ) ;
}
}
}
if ( ( -- V_330 == 0 ) || ( V_331 != 0 && V_292 >= V_331 ) ) {
F_41 ( L_337 V_351 L_338 V_351 L_339 ,
V_330 , V_292 , V_331 ) ;
V_59 = 0 ;
break;
}
}
if ( V_297 ) {
F_234 ( V_297 ) ;
V_297 = NULL ;
}
}
F_283 ( & V_325 ) ;
if ( V_59 != 0 ) {
F_41 ( L_352 , V_59 ) ;
#ifndef F_37
if ( V_98 ) {
T_45 V_356 , V_357 ;
if ( F_284 ( 1 , & V_356 ) == 0 && F_284 ( 2 , & V_357 ) == 0 ) {
if ( V_356 . V_358 == V_357 . V_358 &&
V_356 . V_359 == V_357 . V_359 ) {
fflush ( stdout ) ;
fprintf ( V_7 , L_6 ) ;
}
}
}
#endif
switch ( V_59 ) {
case V_360 :
F_62 ( L_353 ,
V_247 -> V_304 ,
V_291 != NULL ? V_291 : L_348 ) ;
F_11 ( V_291 ) ;
break;
case V_361 :
F_62 ( L_354 ,
V_247 -> V_304 ) ;
break;
case V_362 :
F_62 ( L_355 ,
V_247 -> V_304 ,
V_291 != NULL ? V_291 : L_348 ) ;
F_11 ( V_291 ) ;
break;
case V_363 :
F_62 ( L_356
L_357 , V_247 -> V_304 ,
V_291 != NULL ? V_291 : L_348 ) ;
F_11 ( V_291 ) ;
break;
default:
F_62 ( L_358 ,
V_247 -> V_304 , F_174 ( V_59 ) ) ;
break;
}
if ( V_177 != NULL ) {
if ( ! F_280 ( V_334 , & V_59 ) )
F_279 ( V_177 , V_59 , TRUE ) ;
}
} else {
if ( V_177 != NULL ) {
if ( V_334 && V_71 ) {
if ( ! F_285 ( V_334 , F_286 () ) ) {
F_62 ( L_359 ,
F_6 ( V_68 ) ) ;
}
}
if ( ! F_280 ( V_334 , & V_59 ) )
F_279 ( V_177 , V_59 , TRUE ) ;
} else {
if ( V_98 ) {
if ( ! F_185 () ) {
V_59 = V_211 ;
F_183 ( V_59 ) ;
}
}
}
}
V_350:
F_222 ( V_247 -> V_287 ) ;
V_247 -> V_287 = NULL ;
F_11 ( V_29 ) ;
F_281 ( V_335 ) ;
F_281 ( V_337 ) ;
return V_59 ;
}
static T_10
F_231 ( T_27 * V_247 , T_35 * V_297 , T_34 V_306 , struct V_307 * V_308 ,
const T_39 * V_309 , T_16 V_294 )
{
T_28 V_324 ;
T_41 * V_196 ;
T_10 V_312 ;
V_247 -> V_313 ++ ;
V_312 = TRUE ;
F_243 ( & V_324 , V_247 -> V_313 , V_308 , V_306 , V_314 ) ;
if ( V_297 ) {
if ( V_98 && ( V_142 . V_315 || V_142 . V_316 ||
V_142 . V_317 ) )
F_244 () ;
if ( V_247 -> V_80 )
F_245 ( V_297 , V_247 -> V_80 ) ;
F_255 ( V_297 , & V_247 -> V_196 ) ;
if ( ( V_294 & V_327 ) || ( V_98 && V_99 ) || F_256 ( V_132 ) )
V_196 = & V_247 -> V_196 ;
else
V_196 = NULL ;
F_246 ( & V_324 , & V_247 -> V_318 ,
& V_248 , V_251 ) ;
if ( V_248 == & V_324 ) {
V_319 = V_324 ;
V_248 = & V_319 ;
}
F_257 ( V_297 , V_247 -> V_320 , V_308 , F_248 ( & V_324 , V_309 ) , & V_324 , V_196 ) ;
if ( V_247 -> V_80 )
V_312 = F_249 ( V_247 -> V_80 , V_297 ) ;
}
if ( V_312 ) {
F_250 ( & V_324 , & V_314 ) ;
if ( V_98 ) {
F_259 ( V_247 , V_297 ) ;
if ( V_141 )
fflush ( stdout ) ;
if ( ferror ( stdout ) ) {
F_183 ( V_211 ) ;
exit ( 2 ) ;
}
}
V_364 = V_324 ;
V_251 = & V_364 ;
}
V_365 = V_324 ;
V_252 = & V_365 ;
if ( V_297 ) {
F_253 ( V_297 ) ;
F_252 ( & V_324 ) ;
}
return V_312 ;
}
static T_10
F_182 ( T_27 * V_247 )
{
switch ( V_158 ) {
case V_159 :
return F_287 ( V_201 , V_247 -> V_304 , F_20 () ) ;
case V_161 :
if ( V_100 )
F_288 ( stdout , V_247 -> V_304 ) ;
else
F_289 ( & V_247 -> V_196 , stdout ) ;
return ! ferror ( stdout ) ;
case V_162 :
F_290 ( V_132 , stdout ) ;
return ! ferror ( stdout ) ;
case V_163 :
F_291 ( stdout ) ;
return ! ferror ( stdout ) ;
case V_164 :
return ! ferror ( stdout ) ;
default:
F_164 () ;
return FALSE ;
}
}
static char *
F_292 ( T_46 V_174 )
{
static char * V_366 = NULL ;
static T_46 V_367 = 256 ;
T_46 V_368 ;
for ( V_368 = V_367 ; V_174 > V_368 ;
V_368 *= 2 )
;
if ( V_366 == NULL ) {
V_367 = V_368 ;
V_366 = ( char * ) F_199 ( V_367 + 1 ) ;
} else {
if ( V_368 > V_367 ) {
V_367 = V_368 ;
V_366 = ( char * ) F_293 ( V_366 , V_367 + 1 ) ;
}
}
return V_366 ;
}
static inline void
F_294 ( char * V_369 , const char * V_32 , T_46 V_370 )
{
memcpy ( V_369 , V_32 , V_370 ) ;
V_369 [ V_370 ] = '\0' ;
}
static inline void
F_295 ( char * V_369 , const char * V_32 , T_46 V_370 , T_46 V_371 )
{
T_46 V_9 ;
for ( V_9 = V_370 ; V_9 < V_371 ; V_9 ++ )
* V_369 ++ = ' ' ;
F_294 ( V_369 , V_32 , V_370 ) ;
}
static inline void
F_296 ( char * V_369 , const char * V_32 , T_46 V_370 , T_46 V_371 )
{
T_46 V_9 ;
memcpy ( V_369 , V_32 , V_370 ) ;
for ( V_9 = V_370 ; V_9 < V_371 ; V_9 ++ )
V_369 [ V_9 ] = ' ' ;
V_369 [ V_371 ] = '\0' ;
}
static T_10
F_297 ( T_27 * V_247 )
{
char * V_366 ;
int V_9 ;
T_46 V_372 ;
T_46 V_373 ;
T_46 V_374 ;
T_47 * V_375 ;
V_366 = F_292 ( 256 ) ;
V_372 = 0 ;
* V_366 = '\0' ;
for ( V_9 = 0 ; V_9 < V_247 -> V_196 . V_197 ; V_9 ++ ) {
V_375 = & V_247 -> V_196 . V_376 [ V_9 ] ;
if ( ! F_298 ( V_9 ) )
continue;
switch ( V_375 -> V_377 ) {
case V_378 :
V_373 = V_374 = strlen ( V_375 -> V_379 ) ;
if ( V_373 < 3 )
V_373 = 3 ;
V_366 = F_292 ( V_372 + V_373 ) ;
F_295 ( V_366 + V_372 , V_375 -> V_379 , V_374 , V_373 ) ;
break;
case V_380 :
case V_381 :
case V_382 :
case V_383 :
case V_384 :
case V_385 :
case V_386 :
case V_387 :
V_373 = V_374 = strlen ( V_375 -> V_379 ) ;
if ( V_373 < 10 )
V_373 = 10 ;
V_366 = F_292 ( V_372 + V_373 ) ;
F_295 ( V_366 + V_372 , V_375 -> V_379 , V_374 , V_373 ) ;
break;
case V_388 :
case V_389 :
case V_390 :
case V_391 :
case V_392 :
case V_393 :
case V_394 :
case V_395 :
case V_396 :
V_373 = V_374 = strlen ( V_375 -> V_379 ) ;
if ( V_373 < 12 )
V_373 = 12 ;
V_366 = F_292 ( V_372 + V_373 ) ;
F_295 ( V_366 + V_372 , V_375 -> V_379 , V_374 , V_373 ) ;
break;
case V_397 :
case V_398 :
case V_399 :
case V_400 :
case V_401 :
case V_402 :
case V_403 :
case V_404 :
case V_405 :
V_373 = V_374 = strlen ( V_375 -> V_379 ) ;
if ( V_373 < 12 )
V_373 = 12 ;
V_366 = F_292 ( V_372 + V_373 ) ;
F_296 ( V_366 + V_372 , V_375 -> V_379 , V_374 , V_373 ) ;
break;
default:
V_373 = strlen ( V_375 -> V_379 ) ;
V_366 = F_292 ( V_372 + V_373 ) ;
F_294 ( V_366 + V_372 , V_375 -> V_379 , V_373 ) ;
break;
}
V_372 += V_373 ;
if ( V_9 != V_247 -> V_196 . V_197 - 1 ) {
V_366 = F_292 ( V_372 + 5 ) ;
switch ( V_375 -> V_377 ) {
case V_388 :
case V_389 :
case V_390 :
switch ( V_247 -> V_196 . V_376 [ V_9 + 1 ] . V_377 ) {
case V_397 :
case V_398 :
case V_399 :
F_294 ( V_366 + V_372 , L_161 V_406 L_161 , 5 ) ;
V_372 += 5 ;
break;
default:
F_294 ( V_366 + V_372 , L_161 , 1 ) ;
V_372 += 1 ;
break;
}
break;
case V_391 :
case V_392 :
case V_393 :
switch ( V_247 -> V_196 . V_376 [ V_9 + 1 ] . V_377 ) {
case V_400 :
case V_401 :
case V_402 :
F_294 ( V_366 + V_372 , L_161 V_406 L_161 , 5 ) ;
V_372 += 5 ;
break;
default:
F_294 ( V_366 + V_372 , L_161 , 1 ) ;
V_372 += 1 ;
break;
}
break;
case V_394 :
case V_395 :
case V_396 :
switch ( V_247 -> V_196 . V_376 [ V_9 + 1 ] . V_377 ) {
case V_403 :
case V_404 :
case V_405 :
F_294 ( V_366 + V_372 , L_161 V_406 L_161 , 5 ) ;
V_372 += 5 ;
break;
default:
F_294 ( V_366 + V_372 , L_161 , 1 ) ;
V_372 += 1 ;
break;
}
break;
case V_397 :
case V_398 :
case V_399 :
switch ( V_247 -> V_196 . V_376 [ V_9 + 1 ] . V_377 ) {
case V_388 :
case V_389 :
case V_390 :
F_294 ( V_366 + V_372 , L_161 V_407 L_161 , 5 ) ;
V_372 += 5 ;
break;
default:
F_294 ( V_366 + V_372 , L_161 , 1 ) ;
V_372 += 1 ;
break;
}
break;
case V_400 :
case V_401 :
case V_402 :
switch ( V_247 -> V_196 . V_376 [ V_9 + 1 ] . V_377 ) {
case V_391 :
case V_392 :
case V_393 :
F_294 ( V_366 + V_372 , L_161 V_407 L_161 , 5 ) ;
V_372 += 5 ;
break;
default:
F_294 ( V_366 + V_372 , L_161 , 1 ) ;
V_372 += 1 ;
break;
}
break;
case V_403 :
case V_404 :
case V_405 :
switch ( V_247 -> V_196 . V_376 [ V_9 + 1 ] . V_377 ) {
case V_394 :
case V_395 :
case V_396 :
F_294 ( V_366 + V_372 , L_161 V_407 L_161 , 5 ) ;
V_372 += 5 ;
break;
default:
F_294 ( V_366 + V_372 , L_161 , 1 ) ;
V_372 += 1 ;
break;
}
break;
default:
F_294 ( V_366 + V_372 , L_161 , 1 ) ;
V_372 += 1 ;
break;
}
}
}
return F_299 ( V_201 , 0 , V_366 ) ;
}
static T_10
F_259 ( T_27 * V_247 , T_35 * V_297 )
{
T_48 V_408 ;
if ( V_99 || F_256 ( V_132 ) ) {
F_300 ( V_297 , FALSE , TRUE ) ;
if ( V_99 ) {
switch ( V_158 ) {
case V_159 :
if ( ! F_297 ( V_247 ) )
return FALSE ;
break;
case V_161 :
F_301 ( V_297 , stdout ) ;
return ! ferror ( stdout ) ;
case V_162 :
case V_163 :
case V_164 :
F_164 () ;
break;
}
}
}
if ( V_100 ) {
switch ( V_158 ) {
case V_159 :
V_408 . V_101 = V_101 ;
V_408 . V_409 = V_100 ? V_410 : V_411 ;
if ( ! F_302 ( & V_408 , V_297 , V_179 , V_201 ) )
return FALSE ;
if ( ! V_101 ) {
if ( ! F_299 ( V_201 , 0 , V_148 ) )
return FALSE ;
}
break;
case V_161 :
F_303 ( V_132 , V_140 , V_297 , stdout ) ;
printf ( L_6 ) ;
return ! ferror ( stdout ) ;
case V_162 :
F_304 ( V_132 , V_297 , & V_247 -> V_196 , stdout ) ;
printf ( L_6 ) ;
return ! ferror ( stdout ) ;
case V_163 :
V_408 . V_101 = V_101 ;
F_305 ( V_132 , & V_408 , V_140 , V_297 , stdout ) ;
printf ( L_6 ) ;
return ! ferror ( stdout ) ;
case V_164 :
V_408 . V_101 = V_101 ;
F_306 ( V_132 , & V_408 , V_140 , V_297 , stdout ) ;
printf ( L_6 ) ;
return ! ferror ( stdout ) ;
}
}
if ( V_101 ) {
if ( V_99 || V_100 ) {
if ( ! F_299 ( V_201 , 0 , L_126 ) )
return FALSE ;
}
if ( ! F_307 ( V_201 , V_297 ) )
return FALSE ;
if ( ! F_299 ( V_201 , 0 , V_148 ) )
return FALSE ;
}
return TRUE ;
}
static T_10
F_185 ( void )
{
switch ( V_158 ) {
case V_159 :
return F_308 ( V_201 ) ;
case V_161 :
if ( V_100 )
F_309 ( stdout ) ;
else
F_310 ( stdout ) ;
return ! ferror ( stdout ) ;
case V_162 :
F_311 ( V_132 , stdout ) ;
return ! ferror ( stdout ) ;
case V_163 :
F_312 ( stdout ) ;
return ! ferror ( stdout ) ;
case V_164 :
return ! ferror ( stdout ) ;
default:
F_164 () ;
return FALSE ;
}
}
T_49
F_169 ( T_27 * V_247 , const char * V_28 , unsigned int type , T_10 V_284 , int * V_59 )
{
T_50 * V_287 ;
T_7 * V_291 ;
char V_81 [ 2048 + 1 ] ;
V_287 = F_313 ( V_28 , type , V_59 , & V_291 , V_135 ) ;
if ( V_287 == NULL )
goto V_412;
F_189 ( V_247 -> V_231 ) ;
V_247 -> V_231 = F_205 ( V_247 ) ;
V_247 -> V_287 = V_287 ;
V_247 -> V_413 = 0 ;
V_247 -> V_304 = F_24 ( V_28 ) ;
V_247 -> V_284 = V_284 ;
V_247 -> V_414 = FALSE ;
V_247 -> V_320 = F_314 ( V_247 -> V_287 ) ;
V_247 -> V_288 = type ;
V_247 -> V_313 = 0 ;
V_247 -> V_415 = FALSE ;
V_247 -> V_416 = 0 ;
V_247 -> V_417 = F_263 ( V_247 -> V_287 ) ;
if ( V_247 -> V_417 == 0 ) {
V_247 -> V_418 = FALSE ;
V_247 -> V_417 = V_341 ;
} else
V_247 -> V_418 = TRUE ;
F_315 ( & V_247 -> V_318 ) ;
V_248 = NULL ;
V_251 = NULL ;
V_252 = NULL ;
V_247 -> V_273 = V_419 ;
F_316 ( V_247 -> V_287 , V_420 ) ;
F_317 ( V_247 -> V_287 , ( V_421 ) V_422 ) ;
return V_213 ;
V_412:
F_318 ( V_81 , sizeof V_81 ,
F_319 ( * V_59 , V_291 , FALSE , V_247 -> V_320 ) , V_28 ) ;
F_62 ( L_130 , V_81 ) ;
return V_289 ;
}
static void
F_279 ( const char * V_28 , int V_59 , T_10 V_423 )
{
char * V_29 ;
V_29 = F_23 ( V_28 ) ;
switch ( V_59 ) {
case V_424 :
F_62 ( L_360
L_361 ,
V_29 ) ;
break;
#ifdef F_320
case F_320 :
F_62 ( L_362
L_363 ,
V_29 ) ;
break;
#endif
case V_425 :
F_62 ( L_364 ,
V_29 ) ;
break;
case V_349 :
F_62 ( L_365 ,
V_29 ) ;
break;
default:
if ( V_423 ) {
F_62 ( L_366 , V_29 ,
F_174 ( V_59 ) ) ;
} else {
F_62 ( L_367 ,
V_29 , F_174 ( V_59 ) ) ;
}
break;
}
F_11 ( V_29 ) ;
}
static void
F_183 ( int V_59 )
{
switch ( V_59 ) {
case V_424 :
F_62 ( L_368
L_361 ) ;
break;
#ifdef F_320
case F_320 :
F_62 ( L_369
L_363 ) ;
break;
#endif
default:
F_62 ( L_370 ,
F_101 ( V_59 ) ) ;
break;
}
}
static const char *
F_319 ( int V_59 , T_7 * V_291 , T_10 V_426 ,
int V_427 )
{
const char * V_428 ;
static char V_429 [ 1024 + 1 ] ;
if ( V_59 < 0 ) {
switch ( V_59 ) {
case V_430 :
V_428 = L_371 ;
break;
case V_431 :
V_428 = L_372 ;
break;
case V_432 :
V_428 = L_373 ;
break;
case V_360 :
F_318 ( V_429 , sizeof( V_429 ) ,
L_374
L_357 ,
V_291 != NULL ? V_291 : L_348 ) ;
F_11 ( V_291 ) ;
V_428 = V_429 ;
break;
case V_433 :
F_318 ( V_429 , sizeof( V_429 ) ,
L_375
L_376 , F_6 ( V_427 ) ) ;
V_428 = V_429 ;
break;
case V_345 :
V_428 = L_377 ;
break;
case V_346 :
F_318 ( V_429 , sizeof( V_429 ) ,
L_378 ,
F_6 ( V_427 ) ) ;
V_428 = V_429 ;
break;
case V_347 :
if ( V_426 ) {
F_318 ( V_429 , sizeof( V_429 ) ,
L_378 ,
F_6 ( V_427 ) ) ;
V_428 = V_429 ;
} else
V_428 = L_379 ;
break;
case V_362 :
F_318 ( V_429 , sizeof( V_429 ) ,
L_380
L_357 ,
V_291 != NULL ? V_291 : L_348 ) ;
F_11 ( V_291 ) ;
V_428 = V_429 ;
break;
case V_348 :
if ( V_426 )
V_428 = L_381 ;
else
V_428 = L_382 ;
break;
case V_361 :
V_428 = L_383
L_384 ;
break;
case V_349 :
V_428 = L_385 ;
break;
case V_434 :
V_428 = L_386 ;
break;
case V_363 :
F_318 ( V_429 , sizeof( V_429 ) ,
L_387
L_357 ,
V_291 != NULL ? V_291 : L_348 ) ;
F_11 ( V_291 ) ;
V_428 = V_429 ;
break;
default:
F_318 ( V_429 , sizeof( V_429 ) ,
L_388 ,
V_426 ? L_389 : L_390 ,
F_174 ( V_59 ) ) ;
V_428 = V_429 ;
break;
}
} else
V_428 = F_167 ( V_59 , V_426 ) ;
return V_428 ;
}
static void
V_113 ( const char * V_304 , int V_59 , T_10 V_426 )
{
fprintf ( V_7 , L_391 ) ;
fprintf ( V_7 , F_167 ( V_59 , V_426 ) , V_304 ) ;
fprintf ( V_7 , L_6 ) ;
}
static void
V_93 ( const char * V_435 , T_51 V_436 )
{
fprintf ( V_7 , L_391 ) ;
vfprintf ( V_7 , V_435 , V_436 ) ;
fprintf ( V_7 , L_6 ) ;
}
static void
V_114 ( const char * V_304 , int V_59 )
{
F_62 ( L_392 ,
V_304 , F_101 ( V_59 ) ) ;
}
static void
V_115 ( const char * V_304 , int V_59 )
{
F_62 ( L_393 ,
V_304 , F_101 ( V_59 ) ) ;
}
static void
V_94 ( const char * V_435 , T_51 V_436 )
{
vfprintf ( V_7 , V_435 , V_436 ) ;
fprintf ( V_7 , L_6 ) ;
}
