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
#ifdef F_15
fprintf ( V_18 , L_11 ) ;
#else
fprintf ( V_18 , L_12 , V_19 ) ;
#endif
fprintf ( V_18 , L_13 ) ;
#ifdef F_15
fprintf ( V_18 , L_14 ) ;
#endif
#ifdef F_16
fprintf ( V_18 , L_15 , V_20 ) ;
#endif
fprintf ( V_18 , L_16 ) ;
fprintf ( V_18 , L_17 ) ;
fprintf ( V_18 , L_18 ) ;
fprintf ( V_18 , L_6 ) ;
fprintf ( V_18 , L_19 ) ;
fprintf ( V_18 , L_20 ) ;
fprintf ( V_18 , L_21 ) ;
fprintf ( V_18 , L_22 ) ;
fprintf ( V_18 , L_23 ) ;
fprintf ( V_18 , L_24 ) ;
fprintf ( V_18 , L_25 ) ;
fprintf ( V_18 , L_26 ) ;
fprintf ( V_18 , L_27 ) ;
#endif
#ifdef F_17
fprintf ( V_18 , L_28 ) ;
fprintf ( V_18 , L_29 ) ;
#endif
fprintf ( V_18 , L_30 ) ;
fprintf ( V_18 , L_31 ) ;
fprintf ( V_18 , L_6 ) ;
fprintf ( V_18 , L_32 ) ;
fprintf ( V_18 , L_33 ) ;
fprintf ( V_18 , L_34 ) ;
fprintf ( V_18 , L_35 ) ;
fprintf ( V_18 , L_36 ) ;
fprintf ( V_18 , L_37 ) ;
fprintf ( V_18 , L_38 ) ;
fprintf ( V_18 , L_39 ) ;
fprintf ( V_18 , L_40 ) ;
fprintf ( V_18 , L_41 , V_21 ) ;
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
fprintf ( V_18 , L_90 ) ;
fprintf ( V_18 , L_91 ) ;
fprintf ( V_18 , L_92 ) ;
fprintf ( V_18 , L_93 ) ;
fprintf ( V_18 , L_94 ) ;
fprintf ( V_18 , L_95 ) ;
fprintf ( V_18 , L_96 ) ;
fprintf ( V_18 , L_97 ) ;
fprintf ( V_18 , L_98 ) ;
fprintf ( V_18 , L_99 ) ;
fprintf ( V_18 , L_6 ) ;
fprintf ( V_18 , L_100 ) ;
fprintf ( V_18 , L_101 ) ;
fprintf ( V_18 , L_102 ) ;
fprintf ( V_18 , L_103 ) ;
fprintf ( V_18 , L_104 ) ;
fprintf ( V_18 , L_105 ) ;
fprintf ( V_18 , L_106 ) ;
fprintf ( V_18 , L_107 ) ;
#ifdef F_18
fprintf ( V_18 , L_6 ) ;
fprintf ( V_18 , L_108 ) ;
fprintf ( V_18 , L_109 ) ;
fprintf ( V_18 , L_110 ) ;
fprintf ( V_18 , L_6 ) ;
#endif
}
static void
F_19 ( void )
{
T_6 * V_18 ;
V_18 = stdout ;
fprintf ( V_18 , L_111 , F_20 () ) ;
fprintf ( V_18 , L_6 ) ;
fprintf ( V_18 , L_112 ) ;
fprintf ( V_18 , L_6 ) ;
fprintf ( V_18 , L_113 ) ;
fprintf ( V_18 , L_114 ) ;
fprintf ( V_18 , L_115 ) ;
fprintf ( V_18 , L_116 ) ;
fprintf ( V_18 , L_117 ) ;
fprintf ( V_18 , L_118 ) ;
fprintf ( V_18 , L_119 ) ;
fprintf ( V_18 , L_120 ) ;
fprintf ( V_18 , L_121 ) ;
fprintf ( V_18 , L_122 ) ;
fprintf ( V_18 , L_123 ) ;
fprintf ( V_18 , L_6 ) ;
fprintf ( V_18 , L_124 ) ;
fprintf ( V_18 , L_125 ) ;
fprintf ( V_18 , L_126 ) ;
fprintf ( V_18 , L_127 ) ;
fprintf ( V_18 , L_6 ) ;
}
static void
F_21 ( const T_7 * V_22 , T_8 V_23 ,
const T_7 * V_24 , T_3 V_25 )
{
if ( ( V_23 & V_26 & V_27 . V_28 ) == 0 &&
V_27 . V_28 != 0 ) {
return;
}
F_22 ( V_22 , V_23 , V_24 , V_25 ) ;
}
static void
F_23 ( void ) {
T_7 * V_29 , * V_30 ;
if ( F_24 () ) {
V_29 = F_25 () ;
V_30 = F_26 () ;
fprintf ( V_7 , L_128 ,
V_29 , V_30 ) ;
F_11 ( V_29 ) ;
F_11 ( V_30 ) ;
if ( F_27 () ) {
fprintf ( V_7 , L_129 ) ;
}
fprintf ( V_7 , L_6 ) ;
}
}
static void
F_28 ( T_9 * V_31 )
{
F_29 ( V_31 ) ;
}
static void
F_30 ( T_9 * V_31 )
{
#ifdef F_14
F_31 ( V_31 , L_130 ) ;
F_32 ( V_31 ) ;
#endif
F_33 ( V_31 ) ;
}
static void
F_34 ( void )
{
const char * V_32 ;
char * V_33 ;
#if F_35 ( V_34 ) || F_35 ( V_35 ) || F_35 ( V_36 )
T_1 V_9 ;
T_7 * * V_37 ;
#endif
printf ( L_131 , L_132 , F_36 () ) ;
V_33 = F_37 ( L_133 , FALSE ) ;
printf ( L_131 , L_134 , V_33 ) ;
F_11 ( V_33 ) ;
V_32 = F_38 () ;
if ( V_32 != NULL ) {
printf ( L_131 , L_135 , V_32 ) ;
}
V_32 = F_39 () ;
printf ( L_131 , L_136 , V_32 ) ;
V_32 = F_40 () ;
printf ( L_131 , L_137 , V_32 ) ;
#if F_35 ( V_38 ) || F_35 ( V_39 )
V_33 = F_41 () ;
printf ( L_131 , L_138 , V_33 ) ;
F_11 ( V_33 ) ;
printf ( L_131 , L_139 , F_42 () ) ;
#endif
#ifdef V_35
V_33 = F_43 () ;
V_37 = F_44 ( V_33 , V_40 , 10 ) ;
for( V_9 = 0 ; V_37 [ V_9 ] ; V_9 ++ )
printf ( L_131 , L_140 , F_45 ( V_37 [ V_9 ] ) ) ;
F_46 ( V_37 ) ;
F_11 ( V_33 ) ;
#endif
#ifdef V_34
V_33 = F_47 () ;
V_37 = F_44 ( V_33 , V_40 , 10 ) ;
for( V_9 = 0 ; V_37 [ V_9 ] ; V_9 ++ )
printf ( L_131 , L_141 , F_45 ( V_37 [ V_9 ] ) ) ;
F_46 ( V_37 ) ;
F_11 ( V_33 ) ;
#endif
#ifdef V_36
V_32 = F_48 () ;
V_37 = F_44 ( V_32 , V_40 , 10 ) ;
for( V_9 = 0 ; V_37 [ V_9 ] ; V_9 ++ )
printf ( L_131 , L_142 , F_45 ( V_37 [ V_9 ] ) ) ;
F_46 ( V_37 ) ;
#endif
}
int
main ( int V_41 , char * V_42 [] )
{
T_9 * V_43 ;
T_9 * V_44 ;
char * V_45 ;
int V_46 ;
static const struct V_47 V_48 [] = {
{ L_143 , V_49 , NULL , 'h' } ,
{ L_144 , V_49 , NULL , 'v' } ,
V_50
V_51
{ L_145 , V_52 , NULL , V_53 } ,
{ 0 , 0 , 0 , 0 }
} ;
T_10 V_54 = FALSE ;
#ifdef F_49
int V_55 ;
T_11 V_56 ;
#endif
int V_57 ;
volatile T_10 V_58 ;
volatile int V_59 = V_60 ;
#ifdef F_14
T_10 V_61 = FALSE ;
T_10 V_62 = FALSE ;
T_12 * V_63 ;
T_7 * V_64 ;
#else
T_10 V_65 = FALSE ;
#endif
T_10 V_66 = FALSE ;
#ifdef F_50
volatile int V_67 = V_68 ;
#else
volatile int V_67 = V_69 ;
#endif
volatile T_10 V_70 = FALSE ;
volatile int V_71 = V_72 ;
T_7 * volatile V_73 = NULL ;
T_7 * V_74 = NULL ;
T_7 * V_75 = NULL ;
#ifdef F_51
struct V_76 V_77 ;
#endif
T_13 * V_78 = NULL ;
T_13 * V_79 = NULL ;
T_7 * V_80 ;
T_14 * V_81 ;
int V_82 ;
T_7 * V_83 = NULL ;
T_7 * volatile V_84 = NULL ;
const char * volatile V_85 = NULL ;
T_15 V_86 ;
#define F_52 "+2" OPTSTRING_CAPTURE_COMMON OPTSTRING_DISSECT_COMMON "M:C:e:E:F:gG:hH:j:J:lo:O:PqQr:R:S:T:U:vVw:W:xX:Y:z:"
static const char V_87 [] = F_52 ;
F_53 ( L_146 , V_41 ) ;
setlocale ( V_88 , L_133 ) ;
F_54 ( V_89 , V_90 ) ;
#ifdef F_49
F_55 ( V_41 , V_42 ) ;
F_56 () ;
#if ! F_57 ( 2 , 31 , 0 )
F_58 ( NULL ) ;
#endif
#endif
F_59 () ;
F_60 () ;
F_23 () ;
V_45 = F_61 ( V_42 [ 0 ] , main ) ;
if ( V_45 != NULL ) {
fprintf ( V_7 ,
L_147
L_148
L_149 ,
V_45 ) ;
F_11 ( V_45 ) ;
}
F_62 () ;
#ifdef F_49
F_63 () ;
#ifdef F_14
F_64 () ;
if ( ! F_65 () && F_66 () >= 6 ) {
fprintf ( V_7 , L_150
L_151 ) ;
}
#endif
#endif
V_43 = F_67 ( F_28 ,
V_91 ) ;
V_44 = F_68 ( F_30 ) ;
F_69 ( L_111
L_6
L_152
L_6
L_152 ,
F_20 () , V_43 -> V_31 , V_44 -> V_31 ) ;
F_70 ( V_43 , TRUE ) ;
F_70 ( V_44 , TRUE ) ;
V_92 = 0 ;
while ( ( V_46 = F_71 ( V_41 , V_42 , V_87 , V_48 , NULL ) ) != - 1 ) {
switch ( V_46 ) {
case 'C' :
if ( F_72 ( V_93 , FALSE ) ) {
F_73 ( V_93 ) ;
} else {
F_74 ( L_153 , V_93 ) ;
V_59 = V_94 ;
goto V_95;
}
break;
case 'P' :
V_96 = TRUE ;
V_97 = TRUE ;
break;
case 'O' :
V_83 = F_75 ( V_93 ) ;
case 'V' :
V_98 = TRUE ;
V_96 = TRUE ;
break;
case 'x' :
V_99 = TRUE ;
V_96 = TRUE ;
break;
case 'X' :
F_76 ( V_93 ) ;
break;
default:
break;
}
}
if ( V_97 == - 1 )
V_97 = ( V_98 || V_99 ) ? FALSE : TRUE ;
V_82 =
V_100 |
V_101 |
V_102 |
V_103 |
V_104 |
V_105 |
V_106 | V_107 ;
F_77 ( NULL ,
( T_8 ) V_82 ,
F_21 , NULL ) ;
F_77 ( V_108 ,
( T_8 ) V_82 ,
F_21 , NULL ) ;
#ifdef F_14
F_77 ( V_109 ,
( T_8 ) V_82 ,
F_21 , NULL ) ;
F_77 ( V_110 ,
( T_8 ) V_82 ,
F_21 , NULL ) ;
#endif
F_78 ( V_89 , V_89 ,
V_111 , V_112 ,
V_113 ) ;
#ifdef F_14
F_79 ( & V_114 ) ;
F_80 ( & V_115 , & V_116 ) ;
#endif
F_81 ( V_117 ) ;
F_82 ( V_118 ) ;
F_83 ( V_119 ) ;
F_84 () ;
#ifdef V_38
F_85 () ;
F_86 ( V_120 ) ;
F_87 () ;
#endif
if ( ! F_88 ( V_121 , V_122 , NULL ,
NULL ) ) {
V_59 = V_123 ;
goto V_95;
}
#ifdef V_38
F_89 () ;
#endif
#ifdef V_36
F_90 () ;
#endif
F_91 () ;
F_92 ( V_124 ) ;
F_93 ( V_125 ) ;
F_94 ( V_126 , NULL ) ;
F_95 ( V_127 , NULL ) ;
F_96 ( V_128 , NULL ) ;
if ( V_41 >= 2 && strcmp ( V_42 [ 1 ] , L_154 ) == 0 ) {
F_97 () ;
if ( V_41 == 2 )
F_98 () ;
else {
if ( strcmp ( V_42 [ 2 ] , L_155 ) == 0 )
F_99 () ;
else if ( strcmp ( V_42 [ 2 ] , L_156 ) == 0 ) {
F_100 () ;
F_101 ( NULL ) ;
}
else if ( strcmp ( V_42 [ 2 ] , L_157 ) == 0 )
F_102 () ;
else if ( strcmp ( V_42 [ 2 ] , L_158 ) == 0 )
F_101 ( NULL ) ;
else if ( strcmp ( V_42 [ 2 ] , L_159 ) == 0 )
F_103 () ;
else if ( strcmp ( V_42 [ 2 ] , L_160 ) == 0 ) {
V_59 = F_104 () ;
goto V_95;
} else if ( strcmp ( V_42 [ 2 ] , L_161 ) == 0 )
F_98 () ;
else if ( strcmp ( V_42 [ 2 ] , L_162 ) == 0 )
F_34 () ;
else if ( strcmp ( V_42 [ 2 ] , L_163 ) == 0 )
F_105 () ;
else if ( strcmp ( V_42 [ 2 ] , L_164 ) == 0 )
F_106 () ;
else if ( strcmp ( V_42 [ 2 ] , L_165 ) == 0 ) {
#ifdef V_38
F_107 () ;
#endif
#ifdef V_39
F_108 () ;
#endif
}
else if ( strcmp ( V_42 [ 2 ] , L_166 ) == 0 )
F_109 () ;
else if ( strcmp ( V_42 [ 2 ] , L_167 ) == 0 )
F_110 () ;
else if ( strcmp ( V_42 [ 2 ] , L_168 ) == 0 )
F_19 () ;
else if ( strcmp ( V_42 [ 2 ] , L_169 ) == 0 )
F_19 () ;
else {
F_74 ( L_170 , V_42 [ 2 ] ) ;
V_59 = V_94 ;
goto V_95;
}
}
V_59 = V_60 ;
goto V_95;
}
F_53 ( L_171 ) ;
V_81 = F_100 () ;
F_111 ( V_129 ) ;
F_112 ( & V_116 ) ;
V_130 = V_131 ;
V_132 = L_172 ;
V_133 = F_113 () ;
#ifdef F_114
V_134 = 1 ;
V_135 = 1 ;
#else
V_135 = 0 ;
#endif
V_92 = 1 ;
while ( ( V_46 = F_71 ( V_41 , V_42 , V_87 , V_48 , NULL ) ) != - 1 ) {
switch ( V_46 ) {
case '2' :
if( V_136 ) {
F_74 ( L_173 ) ;
V_54 = TRUE ;
}
V_137 = TRUE ;
break;
case 'M' :
if( V_137 ) {
F_74 ( L_174 ) ;
V_54 = TRUE ;
}
V_138 = F_115 ( V_93 , L_175 ) ;
V_136 = TRUE ;
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
case V_139 :
#ifdef F_16
case 'B' :
#endif
#ifdef F_14
V_59 = F_116 ( & V_114 , V_46 , V_93 , & V_62 ) ;
if ( V_59 != 0 ) {
goto V_95;
}
#else
if ( V_46 == 'w' ) {
V_140 = V_93 ;
} else {
V_65 = TRUE ;
V_54 = TRUE ;
}
#endif
break;
case 'C' :
break;
case 'D' :
#ifdef F_14
V_63 = F_117 ( & V_57 , & V_64 , NULL ) ;
if ( V_63 == NULL ) {
if ( V_57 == 0 )
F_74 ( L_176 ) ;
else {
F_74 ( L_152 , V_64 ) ;
F_11 ( V_64 ) ;
}
V_59 = V_141 ;
goto V_95;
}
F_118 ( V_63 ) ;
F_119 ( V_63 ) ;
V_59 = V_60 ;
goto V_95;
#else
V_65 = TRUE ;
V_54 = TRUE ;
#endif
break;
case 'e' :
F_120 ( V_133 , V_93 ) ;
break;
case 'E' :
if ( ! F_121 ( V_133 , V_93 ) ) {
F_74 ( L_177 , V_93 ) ;
F_122 ( V_7 ) ;
V_59 = V_94 ;
goto V_95;
}
break;
case 'F' :
V_67 = F_123 ( V_93 ) ;
if ( V_67 < 0 ) {
F_74 ( L_178 , V_93 ) ;
F_3 () ;
V_59 = V_94 ;
goto V_95;
}
break;
case 'j' :
V_142 = F_124 ( F_125 () , V_93 , L_172 , - 1 ) ;
break;
case 'J' :
V_143 = V_144 ;
V_142 = F_124 ( F_125 () , V_93 , L_172 , - 1 ) ;
break;
case 'W' :
if ( strchr ( V_93 , 'n' ) ) {
V_70 = TRUE ;
} else {
F_74 ( L_179 , V_93 ) ;
F_126 ( L_180 ) ;
V_59 = V_94 ;
goto V_95;
}
break;
case 'H' :
if ( ! F_127 ( V_93 ) )
{
F_74 ( L_181 , V_93 ) ;
V_59 = V_94 ;
goto V_95;
}
V_70 = TRUE ;
break;
case 'h' :
printf ( L_111
L_182
L_183 ,
F_20 () ) ;
F_13 ( stdout ) ;
V_59 = V_60 ;
goto V_95;
break;
case 'l' :
V_145 = TRUE ;
break;
case 'L' :
#ifdef F_14
V_61 = TRUE ;
#else
V_65 = TRUE ;
V_54 = TRUE ;
#endif
break;
case 'o' :
{
char * V_146 = NULL ;
switch ( F_128 ( V_93 , & V_146 ) ) {
case V_147 :
break;
case V_148 :
F_74 ( L_184 , V_93 ,
V_146 ? L_185 : L_133 , V_146 ? V_146 : L_133 ) ;
F_11 ( V_146 ) ;
V_59 = V_94 ;
goto V_95;
break;
case V_149 :
case V_150 :
F_74 ( L_186 , V_93 ) ;
V_59 = V_94 ;
goto V_95;
break;
}
break;
}
case 'q' :
V_66 = TRUE ;
break;
case 'Q' :
V_66 = TRUE ;
V_151 = TRUE ;
break;
case 'r' :
V_73 = F_75 ( V_93 ) ;
break;
case 'R' :
V_74 = V_93 ;
break;
case 'P' :
break;
case 'S' :
V_152 = V_93 ;
break;
case 'T' :
V_96 = TRUE ;
if ( strcmp ( V_93 , L_187 ) == 0 ) {
V_153 = V_154 ;
V_130 = V_131 ;
} else if ( strcmp ( V_93 , L_188 ) == 0 ) {
V_153 = V_154 ;
V_130 = V_131 ;
V_132 = L_189 ;
} else if ( strcmp ( V_93 , L_190 ) == 0 ) {
V_153 = V_154 ;
V_130 = V_155 ;
} else if ( strcmp ( V_93 , L_191 ) == 0 ) {
V_153 = V_156 ;
V_98 = TRUE ;
V_97 = FALSE ;
} else if ( strcmp ( V_93 , L_192 ) == 0 ) {
V_153 = V_156 ;
V_98 = FALSE ;
V_97 = TRUE ;
} else if ( strcmp ( V_93 , L_161 ) == 0 ) {
V_153 = V_157 ;
V_98 = TRUE ;
V_97 = FALSE ;
} else if ( strcmp ( V_93 , L_193 ) == 0 ) {
V_153 = V_158 ;
V_98 = TRUE ;
V_97 = FALSE ;
} else if ( strcmp ( V_93 , L_194 ) == 0 ) {
V_153 = V_159 ;
V_98 = TRUE ;
V_97 = FALSE ;
} else if ( strcmp ( V_93 , L_195 ) == 0 ) {
V_153 = V_160 ;
V_98 = TRUE ;
V_97 = FALSE ;
}
else {
F_74 ( L_196 , V_93 ) ;
F_126 ( L_197
L_198
L_199
L_200
L_201
L_202
L_203
L_204
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
L_211
L_217
L_218
L_219
L_220
L_221
L_222
L_223 ) ;
V_59 = V_94 ;
goto V_95;
}
break;
case 'U' :
{
T_5 * V_161 = NULL ;
if ( ! * V_93 ) {
F_74 ( L_224 ) ;
for ( V_161 = F_129 () ; V_161 ; V_161 = F_130 ( V_161 ) ) {
F_74 ( L_225 , ( const char * ) ( V_161 -> V_5 ) ) ;
}
V_59 = V_94 ;
goto V_95;
}
V_84 = F_75 ( V_93 ) ;
break;
}
case 'v' :
V_43 = F_67 ( F_28 ,
V_91 ) ;
V_44 = F_68 ( F_30 ) ;
F_131 ( L_226 , V_43 , V_44 ) ;
F_70 ( V_43 , TRUE ) ;
F_70 ( V_44 , TRUE ) ;
F_132 () ;
#ifdef V_36
F_133 () ;
#endif
V_59 = V_60 ;
goto V_95;
case 'O' :
break;
case 'V' :
break;
case 'x' :
break;
case 'X' :
break;
case 'Y' :
V_75 = V_93 ;
break;
case 'z' :
if ( strcmp ( L_143 , V_93 ) == 0 ) {
fprintf ( V_7 , L_227 ) ;
F_134 () ;
V_59 = V_60 ;
goto V_95;
}
if ( ! F_135 ( V_93 ) ) {
F_74 ( L_228 , V_93 ) ;
F_134 () ;
V_59 = V_94 ;
goto V_95;
}
break;
case 'd' :
case 'K' :
case 'n' :
case 'N' :
case 't' :
case 'u' :
case V_162 :
case V_163 :
case V_164 :
case V_165 :
if ( ! F_136 ( V_46 , V_93 ) ) {
V_59 = V_94 ;
goto V_95;
}
break;
case V_53 :
if ( strcmp ( L_143 , V_93 ) == 0 ) {
fprintf ( V_7 , L_229 ) ;
F_137 () ;
V_59 = V_60 ;
goto V_95;
}
if ( ! F_138 ( V_93 ) ) {
V_59 = V_94 ;
goto V_95;
}
break;
default:
case '?' :
switch( V_166 ) {
case 'F' :
F_3 () ;
break;
default:
F_13 ( V_7 ) ;
}
V_59 = V_94 ;
goto V_95;
break;
}
}
if ( ( V_157 != V_153 && V_156 != V_153 && V_158 != V_153 && V_159 != V_153 ) && 0 != F_139 ( V_133 ) ) {
F_74 ( L_230
L_231 ) ;
V_59 = V_94 ;
goto V_95;
} else if ( V_157 == V_153 && 0 == F_139 ( V_133 ) ) {
F_74 ( L_232
L_233 ) ;
V_59 = V_94 ;
goto V_95;
}
if ( V_135 < V_41 ) {
if ( V_73 != NULL ) {
if ( V_75 != NULL ) {
F_74 ( L_234
L_235 ) ;
V_59 = V_94 ;
goto V_95;
}
V_75 = F_140 ( V_41 , V_42 , V_135 ) ;
} else {
#ifdef F_14
T_16 V_9 ;
if ( V_114 . V_167 . V_168 ) {
F_74 ( L_236
L_237 ) ;
V_59 = V_94 ;
goto V_95;
}
for ( V_9 = 0 ; V_9 < V_114 . V_169 -> V_170 ; V_9 ++ ) {
T_17 V_171 ;
V_171 = F_141 ( V_114 . V_169 , T_17 , V_9 ) ;
if ( V_171 . V_168 == NULL ) {
V_171 . V_168 = F_140 ( V_41 , V_42 , V_135 ) ;
V_114 . V_169 = F_142 ( V_114 . V_169 , V_9 ) ;
F_143 ( V_114 . V_169 , V_9 , V_171 ) ;
} else {
F_74 ( L_238
L_237 ) ;
V_59 = V_94 ;
goto V_95;
}
}
V_114 . V_167 . V_168 = F_140 ( V_41 , V_42 , V_135 ) ;
#else
V_65 = TRUE ;
#endif
}
}
#ifdef F_14
if ( ! V_114 . V_172 ) {
if ( ! V_66 )
V_96 = TRUE ;
} else {
if ( strcmp ( V_114 . V_173 , L_239 ) == 0 && V_96 ) {
F_74 ( L_240
L_241 ) ;
V_59 = V_94 ;
goto V_95;
}
}
#else
if ( ! V_66 )
V_96 = TRUE ;
#endif
#ifndef F_14
if ( V_65 )
F_74 ( L_242 ) ;
#endif
if ( V_54 ) {
F_13 ( V_7 ) ;
V_59 = V_94 ;
goto V_95;
}
if ( V_99 ) {
if ( V_153 != V_154 && V_153 != V_158 && V_153 != V_160 && V_153 != V_159 ) {
F_74 ( L_243 ) ;
V_59 = V_94 ;
goto V_95;
}
}
if ( V_83 != NULL ) {
char * V_174 ;
if ( ! V_98 ) {
F_74 ( L_244 ) ;
V_59 = V_94 ;
goto V_95;
}
V_175 = F_144 ( V_176 , V_177 ) ;
for ( V_174 = strtok ( V_83 , L_245 ) ; V_174 ; V_174 = strtok ( NULL , L_245 ) ) {
F_145 ( V_175 , ( T_3 ) V_174 , ( T_3 ) V_174 ) ;
}
}
if ( V_74 != NULL && ! V_137 ) {
F_74 ( L_246 ) ;
V_59 = V_94 ;
goto V_95;
}
#ifdef F_14
if ( V_61 ) {
if ( V_73 ) {
F_74 ( L_247 ) ;
V_59 = V_94 ;
goto V_95;
}
if ( V_114 . V_178 ) {
F_74 ( L_248 ) ;
V_59 = V_94 ;
goto V_95;
}
} else {
if ( V_73 ) {
if ( V_114 . V_167 . V_168 ) {
F_74 ( L_249
L_250 ) ;
V_59 = V_94 ;
goto V_95;
}
if ( V_114 . V_178 ) {
F_74 ( L_251
L_252 ) ;
V_59 = V_94 ;
goto V_95;
}
if ( V_114 . V_179 ) {
F_74 ( L_253
L_252 ) ;
V_59 = V_94 ;
goto V_95;
}
if ( V_114 . V_180 ) {
F_74 ( L_254
L_252 ) ;
V_59 = V_94 ;
goto V_95;
}
if ( V_114 . V_181 ) {
F_74 ( L_255
L_252 ) ;
V_59 = V_94 ;
goto V_95;
}
if ( V_114 . V_182 ) {
F_74 ( L_256
L_257
L_258 ) ;
V_59 = V_94 ;
goto V_95;
}
if ( V_114 . V_183 ) {
F_74 ( L_259
L_252 ) ;
V_59 = V_94 ;
goto V_95;
}
} else {
if ( V_137 ) {
F_74 ( L_260 ) ;
V_59 = V_94 ;
goto V_95;
}
if ( V_114 . V_172 ) {
if ( V_67 != V_69 &&
V_67 != V_68 ) {
F_74 ( L_261 ) ;
V_59 = V_94 ;
goto V_95;
}
if ( V_114 . V_182 &&
V_67 != V_68 ) {
F_74 ( L_262 ) ;
V_59 = V_94 ;
goto V_95;
}
if ( V_114 . V_178 ) {
if ( strcmp ( V_114 . V_173 , L_239 ) == 0 ) {
F_74 ( L_251
L_263 ) ;
V_59 = V_94 ;
goto V_95;
}
if ( V_114 . V_184 ) {
F_74 ( L_251
L_264 ) ;
V_59 = V_94 ;
goto V_95;
}
if ( ! V_114 . V_185 &&
! V_114 . V_179 ) {
F_74 ( L_251
L_265 ) ;
V_59 = V_94 ;
goto V_95;
}
}
if ( V_74 != NULL ) {
F_74 ( L_266 ) ;
V_59 = V_94 ;
goto V_95;
}
if ( V_75 != NULL ) {
F_74 ( L_267 ) ;
V_59 = V_94 ;
goto V_95;
}
V_114 . V_186 = ( V_67 == V_68 ) ? TRUE : FALSE ;
} else {
if ( V_114 . V_185 ) {
F_74 ( L_268
L_269 ) ;
V_59 = V_94 ;
goto V_95;
}
if ( V_114 . V_178 ) {
F_74 ( L_251
L_270 ) ;
V_59 = V_94 ;
goto V_95;
}
if ( V_114 . V_182 ) {
F_74 ( L_256
L_270 ) ;
V_59 = V_94 ;
goto V_95;
}
}
}
}
#endif
#ifdef F_49
V_55 = F_146 ( F_147 ( 1 , 1 ) , & V_56 ) ;
if ( V_55 != 0 )
{
V_59 = V_123 ;
goto V_95;
}
#endif
F_148 () ;
F_149 () ;
F_150 () ;
{
T_5 * V_187 = NULL ;
T_5 * V_188 = F_151 ( V_133 ) ;
if ( V_188 != NULL ) {
F_74 ( L_271 ) ;
for ( V_187 = V_188 ; V_187 != NULL ; V_187 = F_130 ( V_187 ) ) {
F_126 ( L_272 , ( T_7 * ) V_187 -> V_5 ) ;
}
F_10 ( V_188 ) ;
V_59 = V_94 ;
goto V_95;
}
}
#ifdef F_14
if ( V_114 . V_172 &&
V_114 . V_184 ) {
if ( F_152 () ) {
F_74 ( L_273 ) ;
V_59 = V_94 ;
goto V_95;
}
if ( V_96 ) {
F_74 ( L_274 ) ;
V_59 = V_94 ;
goto V_95;
}
}
#endif
if ( F_153 ( L_275 ) > 0 ) {
const T_7 * V_16 = F_154 ( L_275 ) ;
V_71 = F_155 ( V_16 ) ;
if ( V_71 == V_72 ) {
F_74 ( L_276 , V_16 ? V_16 : L_133 ) ;
F_12 () ;
V_59 = V_94 ;
goto V_95;
}
}
F_81 ( V_189 . V_190 ) ;
if ( ! F_156 () ) {
V_59 = V_94 ;
goto V_95;
}
F_157 ( & V_116 . V_191 , V_81 -> V_192 , TRUE ) ;
#ifdef F_14
F_158 ( & V_114 , V_193 ) ;
F_159 ( & V_114 ) ;
#endif
if ( V_74 != NULL ) {
F_53 ( L_277 , V_74 ) ;
if ( ! F_160 ( V_74 , & V_78 , & V_80 ) ) {
F_74 ( L_152 , V_80 ) ;
F_11 ( V_80 ) ;
F_132 () ;
#ifdef V_36
F_133 () ;
#endif
#ifdef F_51
{
T_18 * V_194 ;
V_194 = F_161 ( V_195 , V_193 ) ;
if ( V_194 != NULL ) {
if ( F_162 ( V_194 , & V_77 , V_74 , 0 , 0 ) != - 1 ) {
F_126 (
L_278
L_279 ) ;
}
F_163 ( V_194 ) ;
}
}
#endif
V_59 = V_141 ;
goto V_95;
}
}
V_116 . V_78 = V_78 ;
if ( V_75 != NULL ) {
F_53 ( L_280 , V_75 ) ;
if ( ! F_160 ( V_75 , & V_79 , & V_80 ) ) {
F_74 ( L_152 , V_80 ) ;
F_11 ( V_80 ) ;
F_132 () ;
#ifdef V_36
F_133 () ;
#endif
#ifdef F_51
{
T_18 * V_194 ;
V_194 = F_161 ( V_195 , V_193 ) ;
if ( V_194 != NULL ) {
if ( F_162 ( V_194 , & V_77 , V_75 , 0 , 0 ) != - 1 ) {
F_126 (
L_281
L_279 ) ;
}
F_163 ( V_194 ) ;
}
}
#endif
V_59 = V_196 ;
goto V_95;
}
}
V_116 . V_79 = V_79 ;
if ( V_96 ) {
if ( V_153 == V_154 ) {
switch ( V_130 ) {
case V_131 :
V_197 = F_164 ( stdout ) ;
break;
case V_155 :
V_197 = F_165 ( stdout ) ;
break;
default:
F_166 () ;
}
}
}
if ( V_84 ) {
const char * V_198 = V_84 ;
const char * V_199 = V_75 ;
char * V_200 ;
int V_201 ;
char * V_202 ;
if ( ! V_73 ) {
F_74 ( L_282 ) ;
V_59 = V_94 ;
goto V_95;
}
#ifdef F_14
V_85 = V_114 . V_173 ;
V_114 . V_173 = NULL ;
#else
V_85 = V_140 ;
V_140 = NULL ;
#endif
if ( V_85 == NULL ) {
F_74 ( L_283 ) ;
V_59 = V_94 ;
goto V_95;
}
V_200 = F_167 ( V_198 , V_199 ,
& V_86 ) ;
if ( V_200 ) {
F_74 ( L_284 , V_200 ) ;
F_11 ( V_200 ) ;
V_59 = V_203 ;
goto V_95;
}
V_201 = F_168 ( V_85 , V_204 | V_205 | V_206 | V_207 , 0644 ) ;
if ( V_201 == - 1 ) {
F_74 ( L_285 , V_85 , F_169 ( V_208 , TRUE ) ) ;
V_59 = V_209 ;
goto V_95;
}
V_202 = F_170 ( L_286 , V_73 ) ;
V_57 = F_171 ( & V_86 , V_201 , V_202 ) ;
if ( V_57 != 0 ) {
F_172 ( L_287 , V_85 , V_57 ,
V_68 ) ;
F_11 ( V_202 ) ;
V_59 = V_210 ;
goto V_95;
}
}
V_211 = V_96 || V_78 || V_79 || V_84 ||
F_152 () ;
F_53 ( L_288 , V_211 ? L_289 : L_290 ) ;
if ( V_73 ) {
F_53 ( L_291 , V_73 ) ;
if ( F_173 ( & V_116 , V_73 , V_71 , FALSE , & V_57 ) != V_212 ) {
F_132 () ;
#ifdef V_36
F_133 () ;
#endif
V_59 = V_209 ;
goto V_95;
}
F_53 ( L_292 ) ;
F_174 {
#ifdef F_14
V_58 = F_175 ( & V_116 , V_114 . V_173 , V_67 , V_70 ,
V_114 . V_213 ? V_114 . V_214 : 0 ,
V_114 . V_185 ? V_114 . V_215 : 0 ) ;
#else
V_58 = F_175 ( & V_116 , V_140 , V_67 , V_70 , 0 , 0 ) ;
#endif
}
F_176 (OutOfMemoryError) {
fprintf ( V_7 ,
L_293
L_6
L_294
L_6
L_295
L_296 ) ;
V_58 = FALSE ;
}
V_216 ;
if ( ! V_58 ) {
V_59 = 2 ;
}
if ( V_84 ) {
V_57 = F_177 ( & V_86 ) ;
if ( V_57 ) {
F_178 ( V_85 , V_57 ) ;
V_59 = 2 ;
}
F_11 ( V_84 ) ;
}
} else {
F_53 ( L_297 ) ;
#ifdef F_14
V_59 = F_179 ( & V_114 ,
( ( V_81 -> V_217 ) && ( * V_81 -> V_217 != '\0' ) ) ? F_180 ( V_81 -> V_217 ) : NULL ) ;
if ( V_59 != 0 ) {
goto V_95;
}
if ( V_61 ) {
T_16 V_9 ;
for ( V_9 = 0 ; V_9 < V_114 . V_169 -> V_170 ; V_9 ++ ) {
T_17 V_171 ;
T_19 * V_218 ;
char * V_219 = NULL ;
V_171 = F_141 ( V_114 . V_169 , T_17 , V_9 ) ;
#ifdef F_17
if ( V_171 . V_220 == V_221 ) {
V_219 = F_170 ( L_298 , V_171 . V_222 , V_171 . V_223 ) ;
}
#endif
V_218 = F_181 ( V_171 . V_16 , V_171 . V_224 , V_219 , & V_64 , NULL ) ;
F_11 ( V_219 ) ;
if ( V_218 == NULL ) {
F_74 ( L_152 , V_64 ) ;
F_11 ( V_64 ) ;
V_59 = V_225 ;
goto V_95;
}
if ( V_218 -> V_226 == NULL ) {
F_74 ( L_299 , V_171 . V_16 ) ;
V_59 = V_227 ;
goto V_95;
}
F_182 ( V_218 , V_171 . V_16 , V_171 . V_224 ) ;
F_183 ( V_218 ) ;
}
V_59 = V_60 ;
goto V_95;
}
if ( ! F_184 ( F_185 ( V_7 ) ) )
V_228 = FALSE ;
else if ( V_96 && F_184 ( F_185 ( stdout ) ) )
V_228 = FALSE ;
else if ( V_66 )
V_228 = FALSE ;
else
V_228 = TRUE ;
if ( V_96 ) {
if ( ! F_186 ( & V_116 ) ) {
F_187 ( V_208 ) ;
V_59 = V_209 ;
goto V_95;
}
}
F_53 ( L_300 ) ;
F_188 () ;
V_59 = V_115 . V_229 ;
if ( V_96 ) {
if ( ! F_189 () ) {
F_187 ( V_208 ) ;
}
}
#else
F_74 ( L_242 ) ;
V_59 = V_230 ;
goto V_95;
#endif
}
F_11 ( V_73 ) ;
if ( V_116 . V_231 != NULL ) {
F_190 ( V_116 . V_231 ) ;
V_116 . V_231 = NULL ;
}
F_191 ( TRUE ) ;
F_192 () ;
F_193 ( V_116 . V_232 ) ;
F_132 () ;
#ifdef V_36
F_133 () ;
#endif
F_194 ( V_133 ) ;
V_133 = NULL ;
V_95:
F_195 ( V_197 ) ;
#ifdef F_14
F_196 ( & V_114 ) ;
#endif
F_197 ( & V_116 . V_191 ) ;
F_198 () ;
F_199 () ;
F_200 () ;
#ifdef V_38
F_201 () ;
#endif
F_202 ( & V_116 ) ;
return V_59 ;
}
static T_1
F_203 ( T_3 V_5 )
{
T_20 V_233 ;
T_21 V_234 = 0 ;
T_10 V_55 ;
T_21 V_235 ;
T_22 * V_236 = V_5 ;
T_1 V_237 = 0 ;
F_204 ( V_236 -> V_238 ) ;
while( V_237 < 5 ) {
V_233 = ( T_20 ) F_205 ( V_236 -> V_239 ) ;
V_55 = F_206 ( V_233 , NULL , 0 , NULL , & V_234 , NULL ) ;
F_207 ( ( T_20 ) * ( V_236 -> V_240 ) ,
& V_235 ) ;
if ( ! V_55 || V_234 > 0 || V_235 != V_241 ) {
if ( ! V_236 -> V_242 ( V_236 -> V_239 , V_236 -> V_25 ) ) {
F_208 ( NULL , V_105 , L_301 , V_237 ) ;
F_209 ( V_236 -> V_238 ) ;
return FALSE ;
}
}
else {
break;
}
V_237 ++ ;
}
F_209 ( V_236 -> V_238 ) ;
return TRUE ;
}
void
F_210 ( T_1 V_239 , T_3 V_25 , T_23 * V_240 , T_24 V_242 )
{
V_243 . V_239 = V_239 ;
V_243 . V_240 = V_240 ;
V_243 . V_25 = V_25 ;
V_243 . V_242 = V_242 ;
#ifdef F_49
#if F_57 ( 2 , 31 , 0 )
V_243 . V_238 = F_211 ( sizeof( V_244 ) ) ;
F_212 ( V_243 . V_238 ) ;
#else
V_243 . V_238 = F_213 () ;
#endif
V_243 . V_245 = F_214 ( 200 , F_203 , & V_243 ) ;
#endif
}
static const T_25 *
F_215 ( void * V_5 , T_26 V_246 )
{
T_27 * V_247 = ( T_27 * ) V_5 ;
if ( V_248 && V_248 -> V_249 == V_246 )
return & V_248 -> V_250 ;
if ( V_251 && V_251 -> V_249 == V_246 )
return & V_251 -> V_250 ;
if ( V_252 && V_252 -> V_249 == V_246 )
return & V_252 -> V_250 ;
if ( V_247 -> V_231 ) {
T_28 * V_253 = F_216 ( V_247 -> V_231 , V_246 ) ;
return ( V_253 ) ? & V_253 -> V_250 : NULL ;
}
return NULL ;
}
static T_29 *
F_217 ( T_27 * V_247 )
{
T_29 * V_232 = F_218 () ;
V_232 -> V_5 = V_247 ;
V_232 -> V_254 = F_215 ;
V_232 -> V_255 = V_256 ;
V_232 -> V_257 = V_258 ;
V_232 -> V_259 = NULL ;
return V_232 ;
}
static T_10
F_188 ( void )
{
T_10 V_260 ;
T_16 V_9 ;
T_9 * V_31 ;
#ifdef F_219
T_30 V_261 ;
#endif
#ifndef F_49
struct V_262 V_263 , V_264 ;
#endif
F_193 ( V_116 . V_232 ) ;
V_116 . V_232 = F_217 ( & V_116 ) ;
#ifdef F_49
F_220 ( V_265 , TRUE ) ;
#else
memset ( & V_263 , 0 , sizeof( V_263 ) ) ;
V_263 . V_266 = V_265 ;
V_263 . V_267 = V_268 ;
F_221 ( & V_263 . V_269 ) ;
V_262 ( V_270 , & V_263 , NULL ) ;
V_262 ( V_271 , & V_263 , NULL ) ;
V_262 ( V_272 , NULL , & V_264 ) ;
if ( V_264 . V_266 == V_273 )
V_262 ( V_272 , & V_263 , NULL ) ;
#ifdef F_222
V_263 . V_266 = V_274 ;
V_263 . V_267 = V_268 ;
F_221 ( & V_263 . V_269 ) ;
V_262 ( F_222 , & V_263 , NULL ) ;
#endif
#endif
V_115 . V_275 = V_276 ;
for ( V_9 = 0 ; V_9 < V_114 . V_169 -> V_170 ; V_9 ++ ) {
T_17 V_171 ;
V_171 = F_141 ( V_114 . V_169 , T_17 , V_9 ) ;
V_171 . V_277 = F_223 ( V_171 . V_16 ) ;
V_114 . V_169 = F_142 ( V_114 . V_169 , V_9 ) ;
F_143 ( V_114 . V_169 , V_9 , V_171 ) ;
}
V_31 = F_224 ( & V_114 , V_278 ) ;
if ( V_151 == FALSE )
fprintf ( V_7 , L_302 , V_31 -> V_31 ) ;
fflush ( V_7 ) ;
F_70 ( V_31 , TRUE ) ;
V_260 = F_225 ( & V_114 , & V_115 , & V_279 , NULL ) ;
if ( ! V_260 )
return FALSE ;
#ifdef F_219
F_226 ( & V_261 ) ;
F_227 ( V_243 . V_239 , & V_261 ) ;
#endif
V_280 = TRUE ;
F_174
{
while ( V_280 )
{
#ifdef F_219
V_260 = F_228 ( V_243 . V_239 + 1 , & V_261 , NULL , NULL , NULL ) ;
if ( V_260 == - 1 )
{
fprintf ( V_7 , L_303 , L_304 , F_229 ( V_208 ) ) ;
return TRUE ;
} else if ( V_260 == 1 ) {
#endif
if ( ! V_243 . V_242 ( V_243 . V_239 , V_243 . V_25 ) ) {
F_208 ( NULL , V_105 , L_305 ) ;
return FALSE ;
}
#ifdef F_219
}
#endif
}
}
F_176 (OutOfMemoryError) {
fprintf ( V_7 ,
L_293
L_6
L_294
L_6
L_295
L_296 ) ;
exit ( 1 ) ;
}
V_216 ;
return TRUE ;
}
void
F_230 ( T_31 * T_32 V_6 , char * V_281 , char * V_282 )
{
F_74 ( L_152 , V_281 ) ;
F_126 ( L_152 , V_282 ) ;
}
void
F_231 ( T_31 * T_32 , T_16 V_9 , char * V_283 )
{
T_33 * V_284 = T_32 -> V_284 ;
T_13 * V_78 = NULL ;
T_17 V_171 ;
F_232 ( V_9 < V_284 -> V_169 -> V_170 ) ;
V_171 = F_141 ( V_284 -> V_169 , T_17 , V_9 ) ;
if ( F_160 ( V_171 . V_168 , & V_78 , NULL ) && V_78 != NULL ) {
F_74 (
L_306
L_6
L_307
L_308
L_6
L_309
L_310
L_6
L_311 ,
V_171 . V_168 , V_171 . V_277 , V_283 ) ;
F_233 ( V_78 ) ;
} else {
F_74 (
L_306
L_6
L_312
L_311 ,
V_171 . V_168 , V_171 . V_277 , V_283 ) ;
}
}
T_10
F_234 ( T_31 * T_32 , T_7 * V_285 )
{
T_33 * V_284 = T_32 -> V_284 ;
T_27 * V_247 = ( T_27 * ) T_32 -> V_247 ;
T_10 V_286 ;
int V_57 ;
if ( T_32 -> V_275 == V_276 ) {
F_208 ( V_109 , V_103 , L_313 ) ;
}
F_208 ( V_109 , V_103 , L_314 , V_285 ) ;
F_232 ( T_32 -> V_275 == V_276 || T_32 -> V_275 == V_287 ) ;
if ( V_284 -> V_173 != NULL ) {
if ( V_247 -> V_275 != V_288 ) {
if ( V_247 -> V_289 != NULL ) {
F_235 ( V_247 -> V_289 ) ;
V_247 -> V_289 = NULL ;
}
V_247 -> V_275 = V_288 ;
}
F_11 ( V_284 -> V_173 ) ;
V_286 = FALSE ;
F_193 ( V_247 -> V_232 ) ;
V_247 -> V_232 = F_217 ( V_247 ) ;
} else {
V_286 = TRUE ;
}
V_284 -> V_173 = F_75 ( V_285 ) ;
if ( V_211 ) {
( ( T_27 * ) T_32 -> V_247 ) -> V_290 = V_72 ;
switch( F_173 ( ( T_27 * ) T_32 -> V_247 , V_284 -> V_173 , V_72 , V_286 , & V_57 ) ) {
case V_212 :
break;
case V_291 :
F_11 ( V_284 -> V_173 ) ;
V_284 -> V_173 = NULL ;
return FALSE ;
}
}
T_32 -> V_275 = V_287 ;
return TRUE ;
}
void
F_236 ( T_31 * T_32 , int V_292 )
{
T_10 V_260 ;
int V_57 ;
T_7 * V_293 ;
T_34 V_294 ;
T_27 * V_247 = ( T_27 * ) T_32 -> V_247 ;
T_10 V_295 ;
T_16 V_296 ;
#ifdef F_222
V_297 = TRUE ;
#endif
V_295 = F_237 () ;
V_296 = F_238 () ;
if ( V_211 ) {
T_10 V_298 ;
T_35 * V_299 ;
V_298 =
( V_247 -> V_78 || V_247 -> V_79 || V_98 || V_295 ||
( V_296 & V_300 ) || F_239 () ||
F_240 ( & V_247 -> V_191 ) ) ;
V_299 = F_241 ( V_247 -> V_232 , V_298 , V_96 && V_98 ) ;
while ( V_292 -- && V_247 -> V_289 ) {
F_242 ( V_247 -> V_289 ) ;
V_260 = F_243 ( V_247 -> V_289 , & V_57 , & V_293 , & V_294 ) ;
F_244 ( V_247 , V_299 , V_298 , V_96 && V_98 ) ;
if ( V_260 == FALSE ) {
F_245 ( T_32 ) ;
F_235 ( V_247 -> V_289 ) ;
V_247 -> V_289 = NULL ;
} else {
V_260 = F_246 ( V_247 , V_299 , V_294 ,
F_247 ( V_247 -> V_289 ) ,
F_248 ( V_247 -> V_289 ) , V_296 ) ;
}
if ( V_260 != FALSE ) {
V_301 ++ ;
}
}
F_249 ( V_299 ) ;
} else {
V_301 += V_292 ;
}
if ( V_228 ) {
if ( V_301 != 0 ) {
fprintf ( V_7 , L_315 , V_301 ) ;
fflush ( V_7 ) ;
}
}
#ifdef F_222
V_297 = FALSE ;
if ( V_302 )
F_250 () ;
#endif
}
static void
F_250 ( void )
{
if ( ( V_228 == FALSE ) && ( V_151 == FALSE ) ) {
fprintf ( V_7 , L_316 , V_301 ,
F_251 ( V_301 , L_133 , L_317 ) ) ;
}
#ifdef F_222
V_302 = FALSE ;
#endif
}
static void
V_274 ( int T_36 V_6 )
{
int V_303 = V_208 ;
if ( V_297 )
V_302 = TRUE ;
else
F_250 () ;
V_208 = V_303 ;
}
void
F_252 ( T_31 * T_32 V_6 , T_26 V_304 )
{
if ( V_228 ) {
fprintf ( V_7 , L_6 ) ;
}
if ( V_304 != 0 ) {
fprintf ( V_7 , L_318 , V_304 , F_251 ( V_304 , L_133 , L_317 ) ) ;
}
}
void
F_253 ( T_31 * T_32 , T_7 * V_305 )
{
T_27 * V_247 = ( T_27 * ) T_32 -> V_247 ;
if ( V_305 != NULL )
fprintf ( V_7 , L_319 , V_305 ) ;
F_250 () ;
if ( V_247 != NULL && V_247 -> V_289 != NULL ) {
F_235 ( V_247 -> V_289 ) ;
if ( V_247 -> V_286 ) {
F_254 ( V_247 -> V_306 ) ;
}
}
#ifdef F_255
F_256 ( V_307 ) ;
#else
V_280 = FALSE ;
#endif
}
static BOOL T_37
V_265 ( T_21 T_38 V_6 )
{
F_245 ( & V_115 ) ;
return TRUE ;
}
static void
V_265 ( int T_36 V_6 )
{
F_245 ( & V_115 ) ;
}
static T_10
F_257 ( T_27 * V_247 , T_35 * V_299 ,
T_34 V_308 , struct V_309 * V_310 ,
const T_39 * V_311 )
{
T_28 V_312 ;
T_26 V_313 ;
T_10 V_314 ;
V_313 = V_247 -> V_315 + 1 ;
V_314 = TRUE ;
F_258 ( & V_312 , V_313 , V_310 , V_308 , V_316 ) ;
if ( V_299 ) {
if ( V_317 . V_318 || V_317 . V_319 ||
V_317 . V_320 )
F_259 () ;
if ( V_247 -> V_78 )
F_260 ( V_299 , V_247 -> V_78 ) ;
if ( V_247 -> V_79 )
F_260 ( V_299 , V_247 -> V_79 ) ;
F_261 ( V_299 ) ;
F_262 ( & V_312 , & V_247 -> V_321 ,
& V_248 , V_251 ) ;
if ( V_248 == & V_312 ) {
V_322 = V_312 ;
V_248 = & V_322 ;
}
F_263 ( V_299 , V_247 -> V_323 , V_310 , F_264 ( & V_312 , V_311 ) , & V_312 , NULL ) ;
if ( V_247 -> V_78 )
V_314 = F_265 ( V_247 -> V_78 , V_299 ) ;
}
if ( V_314 ) {
F_266 ( & V_312 , & V_316 ) ;
V_252 = V_251 = F_267 ( V_247 -> V_231 , & V_312 ) ;
if ( V_299 && V_247 -> V_79 ) {
if ( F_265 ( V_247 -> V_79 , V_299 ) ) {
F_9 ( V_299 -> V_324 . V_325 , V_326 , V_247 -> V_231 ) ;
}
}
V_247 -> V_315 ++ ;
} else {
F_268 ( & V_312 ) ;
}
if ( V_299 )
F_269 ( V_299 ) ;
return V_314 ;
}
static T_10
F_270 ( T_27 * V_247 , T_35 * V_299 ,
T_28 * V_327 , struct V_309 * V_328 ,
T_40 * V_329 , T_16 V_296 )
{
T_41 * V_191 ;
T_10 V_314 ;
V_314 = TRUE ;
if ( V_299 ) {
if ( V_317 . V_318 || V_317 . V_319 ||
V_317 . V_320 )
F_259 () ;
if ( V_247 -> V_79 )
F_260 ( V_299 , V_247 -> V_79 ) ;
F_271 ( V_299 , & V_247 -> V_191 ) ;
if ( ( V_296 & V_330 ) || ( V_96 && V_97 ) || F_272 ( V_133 ) )
V_191 = & V_247 -> V_191 ;
else
V_191 = NULL ;
F_262 ( V_327 , & V_247 -> V_321 ,
& V_248 , V_251 ) ;
if ( V_248 == V_327 ) {
V_322 = * V_327 ;
V_248 = & V_322 ;
}
F_273 ( V_299 , V_247 -> V_323 , V_328 , F_274 ( V_327 , V_329 ) , V_327 , V_191 ) ;
if ( V_247 -> V_79 )
V_314 = F_265 ( V_247 -> V_79 , V_299 ) ;
}
if ( V_314 ) {
F_266 ( V_327 , & V_316 ) ;
if ( V_96 ) {
F_275 ( V_247 , V_299 ) ;
if ( V_145 )
fflush ( stdout ) ;
if ( ferror ( stdout ) ) {
F_187 ( V_208 ) ;
exit ( 2 ) ;
}
}
V_251 = V_327 ;
}
V_252 = V_327 ;
if ( V_299 ) {
F_269 ( V_299 ) ;
}
return V_314 || V_327 -> V_331 . V_332 ;
}
static T_10
F_175 ( T_27 * V_247 , char * V_173 , int V_67 ,
T_10 V_70 , int V_333 , T_34 V_334 )
{
T_10 V_58 = TRUE ;
T_1 V_335 ;
int V_336 ;
T_42 * V_337 ;
T_26 V_313 ;
int V_57 = 0 , V_338 = 0 ;
T_7 * V_293 = NULL , * V_339 = NULL ;
T_34 V_294 ;
T_10 V_295 ;
T_16 V_296 ;
T_43 * V_340 = NULL ;
T_44 * V_341 = NULL ;
T_43 * V_342 = NULL ;
struct V_309 V_328 ;
T_40 V_329 ;
T_35 * V_299 = NULL ;
char * V_343 ;
F_276 ( & V_328 ) ;
V_341 = F_277 ( V_247 -> V_289 ) ;
#ifdef F_50
if ( V_341 -> V_344 -> V_170 > 1 ) {
V_335 = V_345 ;
} else {
V_335 = F_278 ( V_247 -> V_289 ) ;
}
#else
V_335 = F_278 ( V_247 -> V_289 ) ;
#endif
if ( V_173 != NULL ) {
V_336 = F_279 ( V_247 -> V_289 ) ;
if ( V_336 == 0 ) {
V_336 = V_19 ;
}
F_53 ( L_320 , V_336 ) ;
V_340 = F_280 ( V_247 -> V_289 ) ;
V_342 = F_281 ( V_247 -> V_289 ) ;
if ( F_282 ( F_141 ( V_340 , V_346 , 0 ) , V_347 , & V_343 ) != V_348 ) {
F_283 ( F_141 ( V_340 , V_346 , 0 ) , V_347 , L_321 , F_20 () ) ;
}
if ( V_335 != V_345 &&
V_67 == V_69 ) {
F_53 ( L_322 , V_173 ) ;
if ( strcmp ( V_173 , L_239 ) == 0 ) {
V_337 = F_284 ( V_67 , V_335 ,
V_336 , FALSE , & V_57 ) ;
} else {
V_337 = F_285 ( V_173 , V_67 , V_335 ,
V_336 , FALSE , & V_57 ) ;
}
}
else {
F_53 ( L_323 , V_67 , V_173 ) ;
if ( strcmp ( V_173 , L_239 ) == 0 ) {
V_337 = F_286 ( V_67 , V_335 ,
V_336 , FALSE , V_340 , V_341 , V_342 , & V_57 ) ;
} else {
V_337 = F_287 ( V_173 , V_67 , V_335 ,
V_336 , FALSE , V_340 , V_341 , V_342 , & V_57 ) ;
}
}
F_11 ( V_341 ) ;
V_341 = NULL ;
if ( V_337 == NULL ) {
F_172 ( L_287 , V_173 , V_57 , V_67 ) ;
V_58 = FALSE ;
goto V_349;
}
} else {
if ( V_96 ) {
if ( ! F_186 ( V_247 ) ) {
F_187 ( V_208 ) ;
V_58 = FALSE ;
goto V_349;
}
}
F_11 ( V_341 ) ;
V_341 = NULL ;
V_337 = NULL ;
}
V_295 = F_237 () ;
V_296 = F_238 () ;
if ( V_137 ) {
T_28 * V_327 ;
F_53 ( L_324 , V_211 ? L_289 : L_290 ) ;
V_247 -> V_231 = F_288 () ;
if ( V_211 ) {
T_10 V_298 ;
V_298 =
( V_247 -> V_78 != NULL || V_247 -> V_79 != NULL || F_239 () ) ;
F_53 ( L_325 , V_298 ? L_289 : L_290 ) ;
V_299 = F_241 ( V_247 -> V_232 , V_298 , FALSE ) ;
}
F_53 ( L_326 ) ;
while ( F_243 ( V_247 -> V_289 , & V_57 , & V_293 , & V_294 ) ) {
if ( F_257 ( V_247 , V_299 , V_294 , F_247 ( V_247 -> V_289 ) ,
F_248 ( V_247 -> V_289 ) ) ) {
if ( ( -- V_333 == 0 ) || ( V_334 != 0 && V_294 >= V_334 ) ) {
F_53 ( L_327 V_350 L_328 V_350 L_329 ,
V_333 , V_294 , V_334 ) ;
V_57 = 0 ;
break;
}
}
}
if ( V_57 != 0 ) {
V_338 = V_57 ;
V_339 = V_293 ;
V_57 = 0 ;
V_293 = NULL ;
}
if ( V_299 ) {
F_249 ( V_299 ) ;
V_299 = NULL ;
}
F_289 ( V_247 -> V_289 ) ;
F_290 () ;
V_251 = NULL ;
V_252 = NULL ;
F_291 ( & V_329 , 1500 ) ;
F_53 ( L_330 ) ;
if ( V_211 ) {
T_10 V_298 ;
V_298 =
( V_247 -> V_79 || V_98 || V_295 ||
( V_296 & V_300 ) || F_240 ( & V_247 -> V_191 ) ) ;
F_53 ( L_325 , V_298 ? L_289 : L_290 ) ;
V_299 = F_241 ( V_247 -> V_232 , V_298 , V_96 && V_98 ) ;
}
for ( V_313 = 1 ; V_57 == 0 && V_313 <= V_247 -> V_315 ; V_313 ++ ) {
V_327 = F_216 ( V_247 -> V_231 , V_313 ) ;
if ( F_292 ( V_247 -> V_289 , V_327 -> V_351 , & V_328 , & V_329 , & V_57 ,
& V_293 ) ) {
F_53 ( L_331 , V_313 ) ;
if ( F_270 ( V_247 , V_299 , V_327 , & V_328 , & V_329 ,
V_296 ) ) {
if ( V_337 != NULL ) {
F_53 ( L_332 , V_313 ) ;
if ( ! F_293 ( V_337 , & V_328 , F_294 ( & V_329 ) , & V_57 , & V_293 ) ) {
F_53 ( L_333 , V_57 ) ;
F_295 ( L_287 , V_247 -> V_306 , V_173 ,
V_57 , V_293 , V_313 ,
V_67 ) ;
F_296 ( V_337 , & V_57 ) ;
F_297 ( V_340 ) ;
F_297 ( V_342 ) ;
exit ( 2 ) ;
}
}
}
}
}
if ( V_299 ) {
F_249 ( V_299 ) ;
V_299 = NULL ;
}
F_298 ( & V_329 ) ;
F_53 ( L_334 ) ;
}
else {
V_313 = 0 ;
T_10 V_298 = FALSE ;
F_53 ( L_335 , V_211 ? L_289 : L_290 ) ;
if ( V_211 ) {
V_298 =
( V_247 -> V_78 || V_247 -> V_79 || V_98 || V_295 ||
( V_296 & V_300 ) || F_239 () ||
F_240 ( & V_247 -> V_191 ) ) ;
F_53 ( L_325 , V_298 ? L_289 : L_290 ) ;
V_299 = F_241 ( V_247 -> V_232 , V_298 , V_96 && V_98 ) ;
}
while ( F_243 ( V_247 -> V_289 , & V_57 , & V_293 , & V_294 ) ) {
V_313 ++ ;
F_53 ( L_336 , V_313 ) ;
F_244 ( V_247 , V_299 , V_298 , V_96 && V_98 ) ;
if ( F_246 ( V_247 , V_299 , V_294 , F_247 ( V_247 -> V_289 ) ,
F_248 ( V_247 -> V_289 ) , V_296 ) ) {
if ( V_337 != NULL ) {
F_53 ( L_332 , V_313 ) ;
if ( ! F_293 ( V_337 , F_247 ( V_247 -> V_289 ) , F_248 ( V_247 -> V_289 ) , & V_57 , & V_293 ) ) {
F_53 ( L_333 , V_57 ) ;
F_295 ( L_287 , V_247 -> V_306 , V_173 ,
V_57 , V_293 , V_313 , V_67 ) ;
F_296 ( V_337 , & V_57 ) ;
F_297 ( V_340 ) ;
F_297 ( V_342 ) ;
exit ( 2 ) ;
}
}
}
if ( ( -- V_333 == 0 ) || ( V_334 != 0 && V_294 >= V_334 ) ) {
F_53 ( L_327 V_350 L_328 V_350 L_329 ,
V_333 , V_294 , V_334 ) ;
V_57 = 0 ;
break;
}
}
if ( V_299 ) {
F_249 ( V_299 ) ;
V_299 = NULL ;
}
}
F_299 ( & V_328 ) ;
if ( V_57 != 0 || V_338 != 0 ) {
F_53 ( L_337 , V_57 ) ;
#ifndef F_49
if ( V_96 ) {
T_45 V_352 , V_353 ;
if ( F_300 ( 1 , & V_352 ) == 0 && F_300 ( 2 , & V_353 ) == 0 ) {
if ( V_352 . V_354 == V_353 . V_354 &&
V_352 . V_355 == V_353 . V_355 ) {
fflush ( stdout ) ;
fprintf ( V_7 , L_6 ) ;
}
}
}
#endif
if ( V_338 != 0 ) {
F_301 ( L_287 , V_247 -> V_306 , V_338 ,
V_339 ) ;
}
if ( V_57 != 0 ) {
F_301 ( L_287 , V_247 -> V_306 , V_57 , V_293 ) ;
}
V_58 = FALSE ;
}
if ( V_173 != NULL ) {
if ( V_337 && V_70 ) {
if ( ! F_302 ( V_337 , F_303 () ) ) {
F_74 ( L_338 ,
F_6 ( V_67 ) ) ;
}
}
if ( ! F_296 ( V_337 , & V_57 ) ) {
F_178 ( V_173 , V_57 ) ;
V_58 = FALSE ;
}
} else {
if ( V_96 ) {
if ( ! F_189 () ) {
F_187 ( V_208 ) ;
V_58 = FALSE ;
}
}
}
V_349:
F_235 ( V_247 -> V_289 ) ;
V_247 -> V_289 = NULL ;
F_297 ( V_340 ) ;
F_297 ( V_342 ) ;
return V_58 ;
}
static T_10
F_246 ( T_27 * V_247 , T_35 * V_299 , T_34 V_308 ,
struct V_309 * V_310 , const T_39 * V_311 ,
T_16 V_296 )
{
T_28 V_327 ;
T_41 * V_191 ;
T_10 V_314 ;
V_247 -> V_315 ++ ;
V_314 = TRUE ;
F_258 ( & V_327 , V_247 -> V_315 , V_310 , V_308 , V_316 ) ;
if ( V_299 ) {
if ( V_96 && ( V_317 . V_318 || V_317 . V_319 ||
V_317 . V_320 ) )
F_259 () ;
if ( V_247 -> V_79 )
F_260 ( V_299 , V_247 -> V_79 ) ;
F_261 ( V_299 ) ;
F_271 ( V_299 , & V_247 -> V_191 ) ;
if ( ( V_296 & V_330 ) || ( V_96 && V_97 ) || F_272 ( V_133 ) )
V_191 = & V_247 -> V_191 ;
else
V_191 = NULL ;
F_262 ( & V_327 , & V_247 -> V_321 ,
& V_248 , V_251 ) ;
if ( V_248 == & V_327 ) {
V_322 = V_327 ;
V_248 = & V_322 ;
}
F_273 ( V_299 , V_247 -> V_323 , V_310 , F_264 ( & V_327 , V_311 ) , & V_327 , V_191 ) ;
if ( V_247 -> V_79 )
V_314 = F_265 ( V_247 -> V_79 , V_299 ) ;
}
if ( V_314 ) {
F_266 ( & V_327 , & V_316 ) ;
if ( V_96 ) {
F_275 ( V_247 , V_299 ) ;
if ( V_145 )
fflush ( stdout ) ;
if ( ferror ( stdout ) ) {
F_187 ( V_208 ) ;
exit ( 2 ) ;
}
}
V_356 = V_327 ;
V_251 = & V_356 ;
}
V_357 = V_327 ;
V_252 = & V_357 ;
if ( V_299 ) {
F_269 ( V_299 ) ;
F_268 ( & V_327 ) ;
}
return V_314 ;
}
static T_10
F_186 ( T_27 * V_247 )
{
switch ( V_153 ) {
case V_154 :
return F_304 ( V_197 , V_247 -> V_306 , F_20 () ) ;
case V_156 :
if ( V_98 )
F_305 ( stdout , V_247 -> V_306 ) ;
else
F_306 ( & V_247 -> V_191 , stdout ) ;
return ! ferror ( stdout ) ;
case V_157 :
F_307 ( V_133 , stdout ) ;
return ! ferror ( stdout ) ;
case V_158 :
case V_160 :
F_308 ( stdout ) ;
return ! ferror ( stdout ) ;
case V_159 :
return ! ferror ( stdout ) ;
default:
F_166 () ;
return FALSE ;
}
}
static char *
F_309 ( T_46 V_170 )
{
static char * V_358 = NULL ;
static T_46 V_359 = 256 ;
T_46 V_360 ;
for ( V_360 = V_359 ; V_170 > V_360 ;
V_360 *= 2 )
;
if ( V_358 == NULL ) {
V_359 = V_360 ;
V_358 = ( char * ) F_211 ( V_359 + 1 ) ;
} else {
if ( V_360 > V_359 ) {
V_359 = V_360 ;
V_358 = ( char * ) F_310 ( V_358 , V_359 + 1 ) ;
}
}
return V_358 ;
}
static inline void
F_311 ( char * V_361 , const char * V_31 , T_46 V_362 )
{
memcpy ( V_361 , V_31 , V_362 ) ;
V_361 [ V_362 ] = '\0' ;
}
static inline void
F_312 ( char * V_361 , const char * V_31 , T_46 V_362 , T_46 V_363 )
{
T_46 V_9 ;
for ( V_9 = V_362 ; V_9 < V_363 ; V_9 ++ )
* V_361 ++ = ' ' ;
F_311 ( V_361 , V_31 , V_362 ) ;
}
static inline void
F_313 ( char * V_361 , const char * V_31 , T_46 V_362 , T_46 V_363 )
{
T_46 V_9 ;
memcpy ( V_361 , V_31 , V_362 ) ;
for ( V_9 = V_362 ; V_9 < V_363 ; V_9 ++ )
V_361 [ V_9 ] = ' ' ;
V_361 [ V_363 ] = '\0' ;
}
static T_10
F_314 ( T_27 * V_247 )
{
char * V_358 ;
int V_9 ;
T_46 V_364 ;
T_46 V_365 ;
T_46 V_366 ;
T_47 * V_367 ;
T_7 V_368 [ 11 ] ;
V_358 = F_309 ( 256 ) ;
V_364 = 0 ;
* V_358 = '\0' ;
for ( V_9 = 0 ; V_9 < V_247 -> V_191 . V_192 ; V_9 ++ ) {
V_367 = & V_247 -> V_191 . V_369 [ V_9 ] ;
if ( ! F_315 ( V_9 ) )
continue;
switch ( V_367 -> V_370 ) {
case V_371 :
V_365 = V_366 = strlen ( V_367 -> V_372 ) ;
if ( V_365 < 5 )
V_365 = 5 ;
V_358 = F_309 ( V_364 + V_365 ) ;
F_312 ( V_358 + V_364 , V_367 -> V_372 , V_366 , V_365 ) ;
break;
case V_373 :
case V_374 :
case V_375 :
case V_376 :
case V_377 :
case V_378 :
case V_379 :
case V_380 :
V_365 = V_366 = strlen ( V_367 -> V_372 ) ;
if ( V_365 < 10 )
V_365 = 10 ;
V_358 = F_309 ( V_364 + V_365 ) ;
F_312 ( V_358 + V_364 , V_367 -> V_372 , V_366 , V_365 ) ;
break;
case V_381 :
case V_382 :
case V_383 :
case V_384 :
case V_385 :
case V_386 :
case V_387 :
case V_388 :
case V_389 :
V_365 = V_366 = strlen ( V_367 -> V_372 ) ;
if ( V_365 < 12 )
V_365 = 12 ;
V_358 = F_309 ( V_364 + V_365 ) ;
F_312 ( V_358 + V_364 , V_367 -> V_372 , V_366 , V_365 ) ;
break;
case V_390 :
case V_391 :
case V_392 :
case V_393 :
case V_394 :
case V_395 :
case V_396 :
case V_397 :
case V_398 :
V_365 = V_366 = strlen ( V_367 -> V_372 ) ;
if ( V_365 < 12 )
V_365 = 12 ;
V_358 = F_309 ( V_364 + V_365 ) ;
F_313 ( V_358 + V_364 , V_367 -> V_372 , V_366 , V_365 ) ;
break;
default:
V_365 = strlen ( V_367 -> V_372 ) ;
V_358 = F_309 ( V_364 + V_365 ) ;
F_311 ( V_358 + V_364 , V_367 -> V_372 , V_365 ) ;
break;
}
V_364 += V_365 ;
if ( V_9 != V_247 -> V_191 . V_192 - 1 ) {
V_358 = F_309 ( V_364 + 5 ) ;
switch ( V_367 -> V_370 ) {
case V_381 :
case V_382 :
case V_383 :
switch ( V_247 -> V_191 . V_369 [ V_9 + 1 ] . V_370 ) {
case V_390 :
case V_391 :
case V_392 :
F_316 ( V_368 , sizeof( V_368 ) , L_339 , V_399 , V_132 ) ;
F_311 ( V_358 + V_364 , V_368 , 5 ) ;
V_364 += 5 ;
break;
default:
F_311 ( V_358 + V_364 , V_132 , 1 ) ;
V_364 += 1 ;
break;
}
break;
case V_384 :
case V_385 :
case V_386 :
switch ( V_247 -> V_191 . V_369 [ V_9 + 1 ] . V_370 ) {
case V_393 :
case V_394 :
case V_395 :
F_316 ( V_368 , sizeof( V_368 ) , L_339 , V_399 , V_132 ) ;
F_311 ( V_358 + V_364 , V_368 , 5 ) ;
V_364 += 5 ;
break;
default:
F_311 ( V_358 + V_364 , V_132 , 1 ) ;
V_364 += 1 ;
break;
}
break;
case V_387 :
case V_388 :
case V_389 :
switch ( V_247 -> V_191 . V_369 [ V_9 + 1 ] . V_370 ) {
case V_396 :
case V_397 :
case V_398 :
F_316 ( V_368 , sizeof( V_368 ) , L_339 , V_399 , V_132 ) ;
F_311 ( V_358 + V_364 , V_368 , 5 ) ;
V_364 += 5 ;
break;
default:
F_311 ( V_358 + V_364 , V_132 , 1 ) ;
V_364 += 1 ;
break;
}
break;
case V_390 :
case V_391 :
case V_392 :
switch ( V_247 -> V_191 . V_369 [ V_9 + 1 ] . V_370 ) {
case V_381 :
case V_382 :
case V_383 :
F_316 ( V_368 , sizeof( V_368 ) , L_339 , V_400 , V_132 ) ;
F_311 ( V_358 + V_364 , V_368 , 5 ) ;
V_364 += 5 ;
break;
default:
F_311 ( V_358 + V_364 , V_132 , 1 ) ;
V_364 += 1 ;
break;
}
break;
case V_393 :
case V_394 :
case V_395 :
switch ( V_247 -> V_191 . V_369 [ V_9 + 1 ] . V_370 ) {
case V_384 :
case V_385 :
case V_386 :
F_316 ( V_368 , sizeof( V_368 ) , L_339 , V_400 , V_132 ) ;
F_311 ( V_358 + V_364 , V_368 , 5 ) ;
V_364 += 5 ;
break;
default:
F_311 ( V_358 + V_364 , V_132 , 1 ) ;
V_364 += 1 ;
break;
}
break;
case V_396 :
case V_397 :
case V_398 :
switch ( V_247 -> V_191 . V_369 [ V_9 + 1 ] . V_370 ) {
case V_387 :
case V_388 :
case V_389 :
F_316 ( V_368 , sizeof( V_368 ) , L_339 , V_400 , V_132 ) ;
F_311 ( V_358 + V_364 , V_368 , 5 ) ;
V_364 += 5 ;
break;
default:
F_311 ( V_358 + V_364 , V_132 , 1 ) ;
V_364 += 1 ;
break;
}
break;
default:
F_311 ( V_358 + V_364 , V_132 , 1 ) ;
V_364 += 1 ;
break;
}
}
}
return F_317 ( V_197 , 0 , V_358 ) ;
}
static T_10
F_275 ( T_27 * V_247 , T_35 * V_299 )
{
if ( V_97 || F_272 ( V_133 ) ) {
F_318 ( V_299 , FALSE , TRUE ) ;
if ( V_97 ) {
switch ( V_153 ) {
case V_154 :
if ( ! F_314 ( V_247 ) )
return FALSE ;
break;
case V_156 :
F_319 ( V_299 , stdout ) ;
return ! ferror ( stdout ) ;
case V_157 :
case V_158 :
case V_159 :
case V_160 :
F_166 () ;
break;
}
}
}
if ( V_98 ) {
switch ( V_153 ) {
case V_154 :
if ( ! F_320 ( V_98 ? V_401 : V_402 ,
V_99 , V_299 , V_175 , V_197 ) )
return FALSE ;
if ( ! V_99 ) {
if ( ! F_317 ( V_197 , 0 , V_152 ) )
return FALSE ;
}
break;
case V_156 :
F_321 ( V_133 , V_142 , V_143 , V_299 , stdout ) ;
printf ( L_6 ) ;
return ! ferror ( stdout ) ;
case V_157 :
F_322 ( V_133 , V_299 , & V_247 -> V_191 , stdout ) ;
printf ( L_6 ) ;
return ! ferror ( stdout ) ;
case V_158 :
F_323 ( V_133 , V_401 ,
V_99 , V_142 , V_143 ,
V_299 , stdout ) ;
printf ( L_6 ) ;
return ! ferror ( stdout ) ;
case V_160 :
F_323 ( V_133 , V_402 , TRUE ,
V_142 , V_143 , V_299 , stdout ) ;
printf ( L_6 ) ;
return ! ferror ( stdout ) ;
case V_159 :
F_324 ( V_133 , V_99 , V_142 ,
V_143 , V_299 , stdout ) ;
return ! ferror ( stdout ) ;
}
}
if ( V_99 ) {
if ( V_97 || V_98 ) {
if ( ! F_317 ( V_197 , 0 , L_133 ) )
return FALSE ;
}
if ( ! F_325 ( V_197 , V_299 ) )
return FALSE ;
if ( ! F_317 ( V_197 , 0 , V_152 ) )
return FALSE ;
}
return TRUE ;
}
static T_10
F_189 ( void )
{
switch ( V_153 ) {
case V_154 :
return F_326 ( V_197 ) ;
case V_156 :
if ( V_98 )
F_327 ( stdout ) ;
else
F_328 ( stdout ) ;
return ! ferror ( stdout ) ;
case V_157 :
F_329 ( V_133 , stdout ) ;
return ! ferror ( stdout ) ;
case V_158 :
case V_160 :
F_330 ( stdout ) ;
return ! ferror ( stdout ) ;
case V_159 :
return ! ferror ( stdout ) ;
default:
F_166 () ;
return FALSE ;
}
}
void
F_202 ( T_27 * V_247 )
{
F_11 ( V_247 -> V_306 ) ;
}
T_48
F_173 ( T_27 * V_247 , const char * V_403 , unsigned int type , T_10 V_286 , int * V_57 )
{
T_49 * V_289 ;
T_7 * V_293 ;
V_289 = F_331 ( V_403 , type , V_57 , & V_293 , V_137 ) ;
if ( V_289 == NULL )
goto V_404;
F_193 ( V_247 -> V_232 ) ;
V_247 -> V_232 = F_217 ( V_247 ) ;
V_247 -> V_289 = V_289 ;
V_247 -> V_405 = 0 ;
V_247 -> V_306 = F_75 ( V_403 ) ;
V_247 -> V_286 = V_286 ;
V_247 -> V_406 = FALSE ;
V_247 -> V_323 = F_332 ( V_247 -> V_289 ) ;
V_247 -> V_290 = type ;
V_247 -> V_315 = 0 ;
V_247 -> V_407 = FALSE ;
V_247 -> V_408 = 0 ;
V_247 -> V_409 = F_279 ( V_247 -> V_289 ) ;
F_333 ( & V_247 -> V_321 ) ;
V_248 = NULL ;
V_251 = NULL ;
V_252 = NULL ;
V_247 -> V_275 = V_410 ;
F_334 ( V_247 -> V_289 , V_411 ) ;
F_335 ( V_247 -> V_289 , ( V_412 ) V_413 ) ;
return V_212 ;
V_404:
F_336 ( L_287 , V_403 , * V_57 , V_293 ) ;
return V_291 ;
}
static void
F_187 ( int V_57 )
{
switch ( V_57 ) {
case V_414 :
F_74 ( L_340
L_341 ) ;
break;
#ifdef F_337
case F_337 :
F_74 ( L_342
L_343 ) ;
break;
#endif
default:
F_74 ( L_344 ,
F_229 ( V_57 ) ) ;
break;
}
}
static void
V_89 ( const char * V_415 , T_50 V_416 )
{
fprintf ( V_7 , L_345 ) ;
vfprintf ( V_7 , V_415 , V_416 ) ;
fprintf ( V_7 , L_6 ) ;
}
static void
V_111 ( const char * V_306 , int V_57 , T_10 V_417 )
{
fprintf ( V_7 , L_345 ) ;
fprintf ( V_7 , F_169 ( V_57 , V_417 ) , V_306 ) ;
fprintf ( V_7 , L_6 ) ;
}
static void
V_112 ( const char * V_306 , int V_57 )
{
F_74 ( L_346 ,
V_306 , F_229 ( V_57 ) ) ;
}
static void
V_113 ( const char * V_306 , int V_57 )
{
F_74 ( L_347 ,
V_306 , F_229 ( V_57 ) ) ;
}
static void F_244 ( T_27 * V_247 , T_35 * V_299 , T_10 V_418 , T_10 V_419 )
{
if ( ! V_136 || ( V_247 -> V_315 < V_138 ) )
return;
fprintf ( V_7 , L_348 ) ;
F_338 ( V_299 ) ;
F_193 ( V_247 -> V_232 ) ;
V_247 -> V_232 = F_217 ( V_247 ) ;
F_339 ( V_299 , V_247 -> V_232 , V_418 , V_419 ) ;
V_247 -> V_315 = 0 ;
}
static void
V_90 ( const char * V_415 , T_50 V_416 )
{
vfprintf ( V_7 , V_415 , V_416 ) ;
fprintf ( V_7 , L_6 ) ;
}
