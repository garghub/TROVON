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
fprintf ( V_1 , L_10 , V_2 ) ;
fprintf ( V_1 , L_11 ) ;
fprintf ( V_1 , L_12 ) ;
fprintf ( V_1 , L_13 ) ;
fprintf ( V_1 , L_14 ) ;
fprintf ( V_1 , L_15 ) ;
fprintf ( V_1 , L_16 ) ;
fprintf ( V_1 , L_17 ) ;
fprintf ( V_1 , L_18 ) ;
fprintf ( V_1 , L_19 ) ;
fprintf ( V_1 , L_20 ) ;
fprintf ( V_1 , L_21 ) ;
fprintf ( V_1 , L_22 ) ;
fprintf ( V_1 , L_23 ) ;
fprintf ( V_1 , L_24 ) ;
fprintf ( V_1 , L_25 ) ;
fprintf ( V_1 , L_26 ) ;
fprintf ( V_1 , L_27 ) ;
fprintf ( V_1 , L_28 ) ;
fprintf ( V_1 , L_29 ) ;
fprintf ( V_1 , L_30 ) ;
fprintf ( V_1 , L_31 ) ;
fprintf ( V_1 , L_32 ) ;
fprintf ( V_1 , L_33 ) ;
fprintf ( V_1 , L_34 ) ;
fprintf ( V_1 , L_35 ) ;
fprintf ( V_1 , L_36 ) ;
fprintf ( V_1 , L_37 ) ;
fprintf ( V_1 , L_38 ) ;
fprintf ( V_1 , L_1 ) ;
fprintf ( V_1 , L_39 ) ;
fprintf ( V_1 , L_40 ) ;
fprintf ( V_1 , L_41 ) ;
fprintf ( V_1 , L_42 ) ;
fprintf ( V_1 , L_43 ) ;
fprintf ( V_1 , L_44 ) ;
fprintf ( V_1 , L_45 ) ;
fprintf ( V_1 , L_46 ) ;
}
static void
F_2 ( void )
{
T_1 * V_1 ;
V_1 = stdout ;
fprintf ( V_1 , L_47 , F_3 () ) ;
fprintf ( V_1 , L_1 ) ;
fprintf ( V_1 , L_48 ) ;
fprintf ( V_1 , L_1 ) ;
fprintf ( V_1 , L_49 ) ;
fprintf ( V_1 , L_50 ) ;
fprintf ( V_1 , L_51 ) ;
fprintf ( V_1 , L_52 ) ;
fprintf ( V_1 , L_53 ) ;
fprintf ( V_1 , L_54 ) ;
fprintf ( V_1 , L_55 ) ;
fprintf ( V_1 , L_56 ) ;
fprintf ( V_1 , L_57 ) ;
fprintf ( V_1 , L_58 ) ;
fprintf ( V_1 , L_1 ) ;
fprintf ( V_1 , L_59 ) ;
fprintf ( V_1 , L_60 ) ;
fprintf ( V_1 , L_61 ) ;
fprintf ( V_1 , L_1 ) ;
}
static void
F_4 ( const char * V_3 , const char * V_4 ,
T_2 V_1 )
{
if ( ( V_5 == NULL ) ||
( strcmp ( V_5 , V_3 ) != 0 ) ) {
fprintf ( ( T_1 * ) V_1 , L_62 , V_3 , V_4 ) ;
V_5 = V_3 ;
}
}
static void
F_5 ( const T_3 * T_4 V_6 , T_2 V_7 , T_2 V_1 )
{
int V_8 ;
const T_3 * V_9 ;
const T_3 * V_10 ;
V_8 = F_6 ( ( V_11 ) V_7 ) ;
if ( V_8 != - 1 ) {
V_9 = F_7 ( V_8 ) ;
V_10 = F_8 ( V_8 ) ;
F_9 ( V_9 != NULL ) ;
F_9 ( V_10 != NULL ) ;
if ( ( V_5 == NULL ) ||
( strcmp ( V_5 , V_9 ) != 0 ) ) {
fprintf ( ( T_1 * ) V_1 , L_62 ,
V_9 ,
V_10 ) ;
V_5 = V_9 ;
}
}
}
static void
F_10 ( const T_3 * T_4 V_6 , T_2 V_7 , T_2 V_12 )
{
int V_8 ;
const T_3 * V_13 ;
T_5 V_14 ;
F_9 ( V_7 ) ;
V_14 = ( T_5 ) V_12 ;
V_8 = F_6 ( ( V_11 ) V_7 ) ;
if ( V_8 != - 1 ) {
V_13 = F_7 ( V_8 ) ;
F_9 ( V_13 != NULL ) ;
if ( strcmp ( V_13 , V_14 -> V_15 ) == 0 ) {
if ( V_14 -> V_16 == 0 ) {
V_14 -> V_17 = ( V_11 ) V_7 ;
}
V_14 -> V_16 ++ ;
}
}
}
static T_6
F_11 ( T_7 V_18 , T_7 V_19 )
{
return strcmp ( ( const char * ) V_18 , ( const char * ) V_19 ) ;
}
static void
F_12 ( T_1 * V_1 )
{
V_5 = NULL ;
F_13 ( F_4 , ( T_2 ) V_1 , ( V_20 ) F_11 ) ;
}
static void
F_14 ( T_1 * V_1 , T_3 * V_3 )
{
V_5 = NULL ;
F_15 ( V_3 ,
F_5 ,
( T_2 ) V_1 ) ;
}
static T_8
F_16 ( const T_3 * V_21 )
{
T_3 * V_3 ;
T_9 V_22 , V_23 ;
T_3 * V_24 ;
T_3 * V_25 ;
T_3 * V_26 ;
T_3 * V_27 ;
V_11 V_28 ;
T_10 V_29 ;
T_11 V_30 ;
struct V_31 V_32 ;
T_12 V_33 ;
char V_34 ;
F_9 ( V_21 ) ;
V_24 = F_17 ( V_21 ) ;
F_9 ( V_24 ) ;
V_3 = V_24 ;
V_25 = strchr ( V_3 , '=' ) ;
if ( V_25 == NULL ) {
F_18 ( L_63 , V_21 , V_2 ) ;
}
else {
* V_25 = '\0' ;
}
while ( V_3 [ 0 ] == ' ' )
V_3 ++ ;
while ( V_3 [ strlen ( V_3 ) - 1 ] == ' ' )
V_3 [ strlen ( V_3 ) - 1 ] = '\0' ;
V_29 = NULL ;
if ( ! ( * ( V_3 ) ) ) {
F_18 ( L_64 ) ;
}
else {
V_29 = F_19 ( V_3 ) ;
if ( ! V_29 ) {
F_18 ( L_65 , V_3 ) ;
}
}
if ( ! V_29 ) {
F_18 ( L_66 ) ;
F_12 ( V_35 ) ;
}
if ( V_25 == NULL || ! V_29 ) {
F_20 ( V_24 ) ;
return FALSE ;
}
if ( * ( V_25 + 1 ) != '=' ) {
F_18 ( L_67 , V_3 , V_25 + 1 ) ;
}
else {
V_25 ++ ;
* V_25 = '\0' ;
}
V_25 ++ ;
V_26 = V_25 ;
V_25 = strchr ( V_26 , ',' ) ;
if ( V_25 == NULL ) {
F_18 ( L_63 , V_21 , V_2 ) ;
}
else {
* V_25 = '\0' ;
}
V_30 = F_21 ( V_3 ) ;
switch ( V_30 ) {
case V_36 :
case V_37 :
case V_38 :
case V_39 :
switch ( sscanf ( V_26 , L_68 , & V_22 , & V_34 , & V_23 ) ) {
case 1 :
V_34 = '\0' ;
break;
case 3 :
if ( V_34 != ':' && V_34 != '-' ) {
F_18 ( L_69 , V_26 ) ;
F_20 ( V_24 ) ;
return FALSE ;
}
if ( V_34 == ':' ) {
if ( ( V_23 == 0 ) || ( ( T_12 ) V_22 + V_23 - 1 ) > V_40 ) {
F_18 ( L_69 , V_26 ) ;
F_20 ( V_24 ) ;
return FALSE ;
}
}
else if ( V_23 < V_22 ) {
F_18 ( L_69 , V_26 ) ;
F_20 ( V_24 ) ;
return FALSE ;
}
break;
default:
F_18 ( L_70 , V_26 ) ;
F_20 ( V_24 ) ;
return FALSE ;
}
break;
case V_41 :
case V_42 :
case V_43 :
case V_44 :
break;
default:
F_22 () ;
}
if ( V_25 == NULL ) {
F_18 ( L_71 , V_3 ) ;
F_14 ( V_35 , V_3 ) ;
F_20 ( V_24 ) ;
return FALSE ;
}
V_25 ++ ;
V_27 = V_25 ;
while ( V_27 [ 0 ] == ' ' )
V_27 ++ ;
while ( V_27 [ strlen ( V_27 ) - 1 ] == ' ' )
V_27 [ strlen ( V_27 ) - 1 ] = '\0' ;
V_28 = NULL ;
if ( ! ( * V_27 ) ) {
F_18 ( L_72 ) ;
}
else {
V_32 . V_16 = 0 ;
V_32 . V_15 = V_27 ;
V_32 . V_17 = NULL ;
F_15 ( V_3 , F_10 , & V_32 ) ;
if ( V_32 . V_16 != 0 ) {
V_28 = V_32 . V_17 ;
if ( V_32 . V_16 > 1 ) {
F_18 ( L_73 , V_27 , V_32 . V_16 ) ;
}
}
else {
if ( F_23 ( V_27 ) == - 1 ) {
F_18 ( L_74 , V_27 ) ;
} else {
F_18 ( L_75 ,
V_27 , V_3 ) ;
}
}
}
if ( ! V_28 ) {
F_18 ( L_71 , V_3 ) ;
F_14 ( V_35 , V_3 ) ;
F_20 ( V_24 ) ;
return FALSE ;
}
switch ( V_30 ) {
case V_36 :
case V_37 :
case V_38 :
case V_39 :
if ( V_34 == '\0' ) {
F_24 ( V_3 , V_22 , V_28 ) ;
} else if ( V_34 == ':' ) {
for ( V_33 = V_22 ; V_33 < ( T_12 ) V_22 + V_23 ; V_33 ++ ) {
F_24 ( V_3 , ( T_9 ) V_33 , V_28 ) ;
}
} else {
for ( V_33 = V_22 ; V_33 <= V_23 ; V_33 ++ ) {
F_24 ( V_3 , ( T_9 ) V_33 , V_28 ) ;
}
}
break;
case V_41 :
case V_42 :
case V_43 :
case V_44 :
F_25 ( V_3 , V_26 , V_28 ) ;
break;
default:
F_22 () ;
}
F_20 ( V_24 ) ;
return TRUE ;
}
static void
F_26 ( const T_3 * V_45 , T_13 V_46 ,
const T_3 * V_47 , T_2 V_12 )
{
if ( ( V_46 & V_48 & V_49 . V_50 ) == 0 &&
V_49 . V_50 != 0 ) {
return;
}
F_27 ( V_45 , V_46 , V_47 , V_12 ) ;
}
static void
F_28 ( void ) {
T_3 * V_51 , * V_52 ;
if ( F_29 () ) {
V_51 = F_30 () ;
V_52 = F_31 () ;
fprintf ( V_35 , L_76 ,
V_51 , V_52 ) ;
F_20 ( V_51 ) ;
F_20 ( V_52 ) ;
if ( F_32 () ) {
fprintf ( V_35 , L_77 ) ;
}
fprintf ( V_35 , L_1 ) ;
}
}
static void
F_33 ( T_14 * V_53 )
{
#ifdef F_34
F_35 ( V_53 , L_78 ) ;
#ifdef F_36
F_35 ( V_53 , F_36 ) ;
#else
F_35 ( V_53 , L_79 ) ;
#endif
#else
F_35 ( V_53 , L_80 ) ;
#endif
}
static void
F_37 ( T_14 * V_53 )
{
#if F_38 ( F_34 ) && ! F_38 ( V_54 )
F_39 ( V_53 , L_81 , F_40 () ) ;
#endif
F_41 ( V_53 ) ;
}
int
main ( int V_55 , char * V_56 [] )
{
T_14 * V_57 ;
T_14 * V_58 ;
char * V_59 ;
int V_60 ;
F_42 (cast-qual)
static const struct V_61 V_62 [] = {
{ ( char * ) L_82 , V_63 , NULL , 'h' } ,
{ ( char * ) L_83 , V_63 , NULL , 'v' } ,
{ 0 , 0 , 0 , 0 }
} ;
F_43 (cast-qual)
T_8 V_64 = FALSE ;
char * V_65 , * V_66 ;
char * V_67 , * V_68 ;
int V_69 , V_70 ;
int V_71 , V_72 ;
int V_73 , V_74 ;
int V_75 , V_76 ;
int V_77 ;
volatile int V_78 = 0 ;
T_8 V_79 = FALSE ;
T_3 * volatile V_80 = NULL ;
T_3 * V_81 = NULL ;
T_3 * V_82 = NULL ;
T_15 * V_83 = NULL ;
T_15 * V_84 = NULL ;
T_3 * V_85 ;
T_16 * V_86 ;
int V_87 ;
T_3 * V_88 = NULL ;
#define F_44 "+2C:d:e:E:hK:lo:O:qQr:R:S:t:T:u:vVxX:Y:z:"
static const char V_89 [] = F_44 ;
setlocale ( V_90 , L_84 ) ;
F_45 ( V_91 , V_92 ) ;
#ifdef V_54
F_46 ( V_55 , V_56 ) ;
F_47 () ;
#if ! F_48 ( 2 , 31 , 0 )
F_49 ( NULL ) ;
#endif
#endif
F_50 () ;
F_51 () ;
F_28 () ;
V_59 = F_52 ( V_56 [ 0 ] , ( void * )main ) ;
if ( V_59 != NULL ) {
fprintf ( V_35 , L_85 ,
V_59 ) ;
}
F_53 () ;
V_57 = F_54 ( F_33 ,
V_93 ) ;
V_58 = F_55 ( F_37 ) ;
F_56 ( L_47
L_1
L_86
L_1
L_86 ,
F_3 () , V_57 -> V_53 , V_58 -> V_53 ) ;
V_94 = 0 ;
while ( ( V_60 = F_57 ( V_55 , V_56 , V_89 , V_62 , NULL ) ) != - 1 ) {
switch ( V_60 ) {
case 'C' :
if ( F_58 ( V_95 , FALSE ) ) {
F_59 ( V_95 ) ;
} else {
F_18 ( L_87 , V_95 ) ;
return 1 ;
}
break;
case 'O' :
V_88 = F_17 ( V_95 ) ;
case 'V' :
V_96 = TRUE ;
V_97 = TRUE ;
break;
case 'x' :
V_98 = TRUE ;
V_97 = TRUE ;
break;
case 'X' :
F_60 ( V_95 ) ;
break;
default:
break;
}
}
if ( V_99 == - 1 )
V_99 = ( V_96 || V_98 ) ? FALSE : TRUE ;
V_87 =
V_100 |
V_101 |
V_102 |
V_103 |
V_104 |
V_105 |
V_106 | V_107 ;
F_61 ( NULL ,
( T_13 ) V_87 ,
F_26 , NULL ) ;
F_61 ( V_108 ,
( T_13 ) V_87 ,
F_26 , NULL ) ;
F_62 ( V_91 , V_109 , V_110 ,
V_111 ) ;
F_63 ( V_112 ) ;
F_64 ( V_113 ) ;
F_65 ( V_114 ) ;
F_66 () ;
#ifdef F_67
F_68 () ;
F_69 () ;
#endif
F_70 ( V_115 , V_116 , NULL , NULL ) ;
if ( V_55 >= 2 && strcmp ( V_56 [ 1 ] , L_88 ) == 0 ) {
F_71 () ;
if ( V_55 == 2 )
F_72 () ;
else {
if ( strcmp ( V_56 [ 2 ] , L_89 ) == 0 )
F_73 () ;
else if ( strcmp ( V_56 [ 2 ] , L_90 ) == 0 ) {
F_74 ( & V_69 , & V_70 , & V_65 ,
& V_71 , & V_72 , & V_66 ) ;
F_75 ( NULL ) ;
}
else if ( strcmp ( V_56 [ 2 ] , L_91 ) == 0 )
F_76 () ;
else if ( strcmp ( V_56 [ 2 ] , L_92 ) == 0 )
F_75 ( NULL ) ;
else if ( strcmp ( V_56 [ 2 ] , L_93 ) == 0 )
F_77 () ;
else if ( strcmp ( V_56 [ 2 ] , L_94 ) == 0 )
F_72 () ;
else if ( strcmp ( V_56 [ 2 ] , L_95 ) == 0 )
F_78 () ;
else if ( strcmp ( V_56 [ 2 ] , L_96 ) == 0 )
F_79 () ;
else if ( strcmp ( V_56 [ 2 ] , L_97 ) == 0 ) {
#ifdef F_67
F_80 () ;
#endif
#ifdef F_81
F_82 () ;
#endif
}
else if ( strcmp ( V_56 [ 2 ] , L_98 ) == 0 )
F_83 () ;
else if ( strcmp ( V_56 [ 2 ] , L_99 ) == 0 )
F_84 () ;
else if ( strcmp ( V_56 [ 2 ] , L_100 ) == 0 )
F_2 () ;
else if ( strcmp ( V_56 [ 2 ] , L_101 ) == 0 )
F_2 () ;
else {
F_18 ( L_102 , V_56 [ 2 ] ) ;
return 1 ;
}
}
return 0 ;
}
V_86 = F_74 ( & V_69 , & V_70 , & V_65 ,
& V_71 , & V_72 , & V_66 ) ;
if ( V_65 != NULL ) {
if ( V_69 != 0 ) {
F_18 ( L_103 ,
V_66 , F_85 ( V_69 ) ) ;
}
if ( V_70 != 0 ) {
F_18 ( L_104 ,
V_66 , F_85 ( V_70 ) ) ;
}
}
if ( V_66 != NULL ) {
if ( V_71 != 0 ) {
F_18 ( L_105 , V_66 ,
F_85 ( V_71 ) ) ;
}
if ( V_72 != 0 ) {
F_18 ( L_106 ,
V_66 , F_85 ( V_72 ) ) ;
}
F_20 ( V_66 ) ;
V_66 = NULL ;
}
F_86 ( & V_67 , & V_73 , & V_74 ,
& V_68 , & V_75 , & V_76 ) ;
F_87 ( & V_67 , & V_73 , & V_74 ,
& V_68 , & V_75 , & V_76 ) ;
if ( V_67 != NULL ) {
if ( V_73 != 0 ) {
F_18 ( L_107 ,
V_67 , F_85 ( V_73 ) ) ;
}
if ( V_74 != 0 ) {
F_18 ( L_108 ,
V_67 , F_85 ( V_74 ) ) ;
}
F_20 ( V_67 ) ;
}
if ( V_68 != NULL ) {
if ( V_75 != 0 ) {
F_18 (
L_109 , V_68 ,
F_85 ( V_75 ) ) ;
}
if ( V_76 != 0 ) {
F_18 (
L_110 , V_68 ,
F_85 ( V_76 ) ) ;
}
F_20 ( V_68 ) ;
}
F_88 ( & V_117 ) ;
V_118 = V_119 ;
V_120 = F_89 () ;
#ifdef F_90
V_121 = 1 ;
V_122 = 1 ;
#else
V_122 = 0 ;
#endif
V_94 = 1 ;
while ( ( V_60 = F_57 ( V_55 , V_56 , V_89 , V_62 , NULL ) ) != - 1 ) {
switch ( V_60 ) {
case '2' :
V_123 = TRUE ;
break;
case 'C' :
break;
case 'd' :
if ( ! F_16 ( V_95 ) )
return 1 ;
break;
#if F_38 ( V_124 ) || F_38 ( V_125 )
case 'K' :
F_91 ( V_95 ) ;
break;
#endif
case 'e' :
F_92 ( V_120 , V_95 ) ;
break;
case 'E' :
if ( ! F_93 ( V_120 , V_95 ) ) {
F_18 ( L_111 , V_95 ) ;
F_94 ( V_35 ) ;
return 1 ;
}
break;
case 'h' :
printf ( L_47
L_112
L_113 ,
F_3 () ) ;
F_1 ( stdout ) ;
return 0 ;
break;
case 'l' :
V_126 = TRUE ;
break;
case 'o' :
switch ( F_95 ( V_95 ) ) {
case V_127 :
break;
case V_128 :
F_18 ( L_114 , V_95 ) ;
return 1 ;
break;
case V_129 :
case V_130 :
F_18 ( L_115 , V_95 ) ;
return 1 ;
break;
}
break;
case 'q' :
V_79 = TRUE ;
break;
case 'Q' :
V_79 = TRUE ;
V_131 = TRUE ;
break;
case 'r' :
V_80 = F_17 ( V_95 ) ;
break;
case 'R' :
V_81 = V_95 ;
break;
case 'S' :
V_132 = F_17 ( V_95 ) ;
break;
case 't' :
if ( strcmp ( V_95 , L_116 ) == 0 )
F_63 ( V_112 ) ;
else if ( strcmp ( V_95 , L_117 ) == 0 )
F_63 ( V_133 ) ;
else if ( strcmp ( V_95 , L_118 ) == 0 )
F_63 ( V_134 ) ;
else if ( strcmp ( V_95 , L_119 ) == 0 )
F_63 ( V_135 ) ;
else if ( strcmp ( V_95 , L_120 ) == 0 )
F_63 ( V_136 ) ;
else if ( strcmp ( V_95 , L_121 ) == 0 )
F_63 ( V_137 ) ;
else if ( strcmp ( V_95 , L_122 ) == 0 )
F_63 ( V_138 ) ;
else if ( strcmp ( V_95 , L_123 ) == 0 )
F_63 ( V_139 ) ;
else if ( strcmp ( V_95 , L_124 ) == 0 )
F_63 ( V_140 ) ;
else if ( strcmp ( V_95 , L_125 ) == 0 )
F_63 ( V_141 ) ;
else {
F_18 ( L_126 , V_95 ) ;
F_96 ( L_127
L_128
L_129
L_130
L_131
L_132
L_133
L_134
L_135
L_136 ) ;
return 1 ;
}
break;
case 'T' :
if ( strcmp ( V_95 , L_137 ) == 0 ) {
V_142 = V_143 ;
V_118 = V_119 ;
} else if ( strcmp ( V_95 , L_138 ) == 0 ) {
V_142 = V_143 ;
V_118 = V_144 ;
} else if ( strcmp ( V_95 , L_139 ) == 0 ) {
V_142 = V_145 ;
V_96 = TRUE ;
V_99 = FALSE ;
} else if ( strcmp ( V_95 , L_140 ) == 0 ) {
V_142 = V_145 ;
V_96 = FALSE ;
V_99 = TRUE ;
} else if ( strcmp ( V_95 , L_94 ) == 0 ) {
V_142 = V_146 ;
V_96 = TRUE ;
V_99 = FALSE ;
} else {
F_18 ( L_141 , V_95 ) ;
F_96 ( L_142
L_143
L_144
L_145
L_146
L_147
L_148
L_149
L_150
L_151
L_152
L_153
L_154
L_155
L_156
L_157 ) ;
return 1 ;
}
break;
case 'u' :
if ( strcmp ( V_95 , L_158 ) == 0 )
F_65 ( V_114 ) ;
else if ( strcmp ( V_95 , L_159 ) == 0 )
F_65 ( V_147 ) ;
else {
F_18 ( L_160 , V_95 ) ;
F_96 ( L_161
L_162 ) ;
return 1 ;
}
break;
case 'v' :
{
F_97 ( L_163 , V_57 , V_58 ) ;
F_98 ( V_57 , TRUE ) ;
F_98 ( V_58 , TRUE ) ;
F_99 () ;
return 0 ;
}
case 'O' :
break;
case 'V' :
break;
case 'x' :
break;
case 'X' :
break;
case 'Y' :
V_82 = V_95 ;
break;
case 'z' :
if ( strcmp ( L_82 , V_95 ) == 0 ) {
fprintf ( V_35 , L_164 ) ;
F_100 () ;
return 0 ;
}
if ( ! F_101 ( V_95 ) ) {
F_18 ( L_165 , V_95 ) ;
F_100 () ;
return 1 ;
}
break;
default:
case '?' :
F_1 ( V_35 ) ;
return 1 ;
break;
}
}
if ( V_146 != V_142 && 0 != F_102 ( V_120 ) ) {
F_18 ( L_166
L_167 ) ;
return 1 ;
} else if ( V_146 == V_142 && 0 == F_102 ( V_120 ) ) {
F_18 ( L_168
L_169 ) ;
return 1 ;
}
if ( V_122 < V_55 ) {
if ( V_80 != NULL ) {
if ( V_82 != NULL ) {
F_18 ( L_170
L_171 ) ;
return 1 ;
}
V_82 = F_103 ( V_55 , V_56 , V_122 ) ;
}
}
if ( ! V_79 )
V_97 = TRUE ;
if ( V_64 ) {
F_1 ( V_35 ) ;
return 1 ;
}
if ( V_98 ) {
if ( V_142 != V_143 ) {
F_18 ( L_172 ) ;
return 1 ;
}
}
if ( V_88 != NULL ) {
char * V_148 ;
if ( ! V_96 ) {
F_18 ( L_173 ) ;
return 1 ;
}
V_149 = F_104 ( V_150 , V_151 ) ;
for ( V_148 = strtok ( V_88 , L_174 ) ; V_148 ; V_148 = strtok ( NULL , L_174 ) ) {
F_105 ( V_149 , ( T_2 ) V_148 , ( T_2 ) V_148 ) ;
}
}
if ( V_81 != NULL && ! V_123 ) {
F_18 ( L_175 ) ;
return 1 ;
}
F_106 () ;
F_107 () ;
if ( V_67 == NULL && V_68 == NULL ) {
F_108 () ;
F_109 () ;
}
F_110 ( & V_117 . V_152 , V_86 -> V_153 , TRUE ) ;
if ( V_81 != NULL ) {
if ( ! F_111 ( V_81 , & V_83 , & V_85 ) ) {
F_18 ( L_86 , V_85 ) ;
F_20 ( V_85 ) ;
F_99 () ;
return 2 ;
}
}
V_117 . V_83 = V_83 ;
if ( V_82 != NULL ) {
if ( ! F_111 ( V_82 , & V_84 , & V_85 ) ) {
F_18 ( L_86 , V_85 ) ;
F_20 ( V_85 ) ;
F_99 () ;
return 2 ;
}
}
V_117 . V_84 = V_84 ;
if ( V_97 ) {
if ( V_142 == V_143 ) {
switch ( V_118 ) {
case V_119 :
V_154 = F_112 ( stdout ) ;
break;
case V_144 :
V_154 = F_113 ( stdout ) ;
break;
default:
F_22 () ;
}
}
}
V_155 = V_97 || V_83 || V_84 || F_114 () ;
if ( V_80 ) {
if ( F_115 ( & V_117 , V_80 , V_156 , FALSE , & V_77 ) != V_157 ) {
F_99 () ;
return 2 ;
}
F_116 {
V_77 = F_117 ( & V_117 , 1 , 0 ) ;
}
F_118 (OutOfMemoryError) {
fprintf ( V_35 ,
L_176
L_1
L_177
L_1
L_178
L_179 ) ;
V_77 = V_158 ;
}
V_159 ;
if ( V_77 != 0 ) {
V_78 = 2 ;
}
}
F_20 ( V_80 ) ;
if ( V_117 . V_160 != NULL ) {
F_119 ( V_117 . V_160 ) ;
V_117 . V_160 = NULL ;
}
F_120 ( TRUE ) ;
F_121 () ;
F_122 ( V_117 . V_161 ) ;
F_99 () ;
F_123 ( V_120 ) ;
V_120 = NULL ;
return V_78 ;
}
static const T_17 *
F_124 ( void * V_162 , T_9 V_163 )
{
T_18 * V_164 = ( T_18 * ) V_162 ;
if ( V_165 && V_165 -> V_166 == V_163 )
return & V_165 -> V_167 ;
if ( V_168 && V_168 -> V_166 == V_163 )
return & V_168 -> V_167 ;
if ( V_169 && V_169 -> V_166 == V_163 )
return & V_169 -> V_167 ;
if ( V_164 -> V_160 ) {
T_19 * V_170 = F_125 ( V_164 -> V_160 , V_163 ) ;
return ( V_170 ) ? & V_170 -> V_167 : NULL ;
}
return NULL ;
}
static const char *
F_126 ( void * V_162 V_6 , T_9 T_20 V_6 )
{
return L_84 ;
}
static T_21 *
F_127 ( T_18 * V_164 )
{
T_21 * V_161 = F_128 () ;
V_161 -> V_162 = V_164 ;
V_161 -> V_171 = F_124 ;
V_161 -> V_172 = F_126 ;
V_161 -> V_173 = NULL ;
return V_161 ;
}
static T_8
F_129 ( T_18 * V_164 , T_22 * V_174 ,
T_23 V_175 , struct V_176 * V_177 ,
const T_24 * V_178 )
{
T_19 V_179 ;
T_9 V_180 ;
T_8 V_181 ;
V_180 = V_164 -> V_182 + 1 ;
V_181 = TRUE ;
F_130 ( & V_179 , V_180 , V_177 , V_175 , V_183 ) ;
if ( V_174 ) {
if ( V_164 -> V_83 )
F_131 ( V_174 , V_164 -> V_83 ) ;
F_132 ( & V_179 , & V_164 -> V_184 ,
& V_165 , V_168 ) ;
if ( V_165 == & V_179 ) {
V_185 = V_179 ;
V_165 = & V_185 ;
}
F_133 ( V_174 , V_177 , F_134 ( & V_179 , V_178 ) , & V_179 , NULL ) ;
if ( V_164 -> V_83 )
V_181 = F_135 ( V_164 -> V_83 , V_174 ) ;
}
if ( V_181 ) {
F_136 ( & V_179 , & V_183 ) ;
V_169 = V_168 = F_137 ( V_164 -> V_160 , & V_179 ) ;
if ( V_174 ) {
F_138 ( V_174 -> V_186 . V_187 , V_188 , V_164 -> V_160 ) ;
}
V_164 -> V_182 ++ ;
} else {
F_139 ( & V_179 ) ;
}
if ( V_174 )
F_140 ( V_174 ) ;
return V_181 ;
}
static T_8
F_141 ( T_18 * V_164 , T_22 * V_174 , T_19 * V_189 ,
struct V_176 * V_190 , T_25 * V_191 ,
T_26 V_192 )
{
T_27 * V_152 ;
T_8 V_181 ;
V_181 = TRUE ;
if ( V_174 ) {
if ( V_164 -> V_84 )
F_131 ( V_174 , V_164 -> V_84 ) ;
F_142 ( V_174 , & V_164 -> V_152 ) ;
if ( ( V_192 & V_193 ) || ( V_97 && V_99 ) )
V_152 = & V_164 -> V_152 ;
else
V_152 = NULL ;
F_132 ( V_189 , & V_164 -> V_184 ,
& V_165 , V_168 ) ;
if ( V_165 == V_189 ) {
V_185 = * V_189 ;
V_165 = & V_185 ;
}
F_143 ( V_174 , V_190 , F_144 ( V_189 , V_191 ) , V_189 , V_152 ) ;
if ( V_164 -> V_84 )
V_181 = F_135 ( V_164 -> V_84 , V_174 ) ;
}
if ( V_181 ) {
F_136 ( V_189 , & V_183 ) ;
if ( V_97 ) {
F_145 ( V_164 , V_174 ) ;
if ( V_126 )
fflush ( stdout ) ;
if ( ferror ( stdout ) ) {
F_146 ( V_194 ) ;
exit ( 2 ) ;
}
}
V_168 = V_189 ;
}
V_169 = V_189 ;
if ( V_174 ) {
F_140 ( V_174 ) ;
}
return V_181 || V_189 -> V_195 . V_196 ;
}
T_8
F_147 ( T_18 * V_164 , struct V_176 * T_28 V_6 , int * V_77 , T_3 * * T_29 V_6 , T_23 * T_30 V_6 , T_31 * * V_197 )
{
T_23 V_198 = F_148 ( V_164 -> V_199 , V_77 ) ;
* V_197 = ( T_31 * ) F_149 ( ( V_200 ) V_198 ) ;
F_150 ( * V_197 , ( unsigned int ) V_198 , V_164 -> V_199 -> V_201 ) ;
#if 0
if (bytes_read < 0) {
*err = file_error(cf->wth->fh, err_info);
if (*err == 0)
*err = FTAP_ERR_SHORT_READ;
return FALSE;
} else if (bytes_read == 0) {
return FALSE;
}
file_phdr->caplen = (guint32)packet_size;
file_phdr->len = (guint32)packet_size;
wth->phdr.pkt_encap = wth->file_encap;
if (!wth->subtype_read(wth, err, err_info, data_offset)) {
if (*err == 0)
*err = file_error(wth->fh, err_info);
return FALSE;
}
if (wth->phdr.caplen > wth->phdr.len)
wth->phdr.caplen = wth->phdr.len;
g_assert(wth->phdr.pkt_encap != WTAP_ENCAP_PER_PACKET);
#endif
return TRUE ;
}
static int
F_117 ( T_18 * V_164 , int V_202 , T_23 V_203 )
{
T_9 V_180 ;
int V_77 ;
T_3 * T_29 = NULL ;
T_23 T_30 = 0 ;
T_8 V_204 ;
T_26 V_192 ;
T_25 V_191 ;
T_22 * V_174 = NULL ;
struct V_176 T_28 ;
T_31 * V_205 ;
if ( V_97 ) {
if ( ! F_151 ( V_164 ) ) {
V_77 = V_194 ;
F_146 ( V_77 ) ;
goto V_206;
}
}
V_204 = F_152 () ;
V_192 = F_153 () ;
F_154 ( & T_28 ) ;
T_28 . V_207 = 1234 ;
if ( V_123 ) {
T_19 * V_189 ;
V_164 -> V_160 = F_155 () ;
if ( V_155 ) {
T_8 V_208 = FALSE ;
if ( V_164 -> V_83 )
V_208 = TRUE ;
V_174 = F_156 ( V_164 -> V_161 , V_208 , FALSE ) ;
}
while ( F_147 ( V_164 , & T_28 , & V_77 , & T_29 , & T_30 , & V_205 ) ) {
if ( F_129 ( V_164 , V_174 , T_30 , & T_28 ,
F_157 ( V_164 -> V_199 ) ) ) {
if ( ( -- V_202 == 0 ) || ( V_203 != 0 && T_30 >= V_203 ) ) {
V_77 = 0 ;
break;
}
}
}
if ( V_174 ) {
F_158 ( V_174 ) ;
V_174 = NULL ;
}
#if 0
wtap_sequential_close(cf->wth);
#endif
F_159 () ;
V_168 = NULL ;
V_169 = NULL ;
F_160 ( & V_191 , 1500 ) ;
if ( V_155 ) {
T_8 V_208 ;
if ( V_164 -> V_84 || V_96 || V_204 ||
( V_192 & V_209 ) || F_161 ( & V_164 -> V_152 ) )
V_208 = TRUE ;
else
V_208 = FALSE ;
V_174 = F_156 ( V_164 -> V_161 , V_208 , V_97 && V_96 ) ;
}
for ( V_180 = 1 ; V_77 == 0 && V_180 <= V_164 -> V_182 ; V_180 ++ ) {
V_189 = F_125 ( V_164 -> V_160 , V_180 ) ;
#if 0
if (wtap_seek_read(cf->wth, fdata->file_off,
&buf, fdata->cap_len, &err, &err_info)) {
process_packet_second_pass(cf, edt, fdata, &cf->phdr, &buf, tap_flags);
}
#else
F_141 ( V_164 , V_174 , V_189 , & V_164 -> V_190 , & V_191 , V_192 ) ;
#endif
}
if ( V_174 ) {
F_158 ( V_174 ) ;
V_174 = NULL ;
}
F_162 ( & V_191 ) ;
}
else {
V_180 = 0 ;
if ( V_155 ) {
T_8 V_208 ;
if ( V_164 -> V_83 || V_164 -> V_84 || V_96 || V_204 ||
( V_192 & V_209 ) || F_161 ( & V_164 -> V_152 ) )
V_208 = TRUE ;
else
V_208 = FALSE ;
V_174 = F_156 ( V_164 -> V_161 , V_208 , V_97 && V_96 ) ;
}
while ( F_147 ( V_164 , & T_28 , & V_77 , & T_29 , & T_30 , & V_205 ) ) {
V_180 ++ ;
F_163 ( V_164 , V_174 , T_30 , & T_28 ,
V_205 , V_192 ) ;
if ( ( -- V_202 == 0 ) || ( V_203 != 0 && T_30 >= V_203 ) ) {
V_77 = 0 ;
break;
}
}
if ( V_174 ) {
F_158 ( V_174 ) ;
V_174 = NULL ;
}
}
F_164 ( & T_28 ) ;
if ( V_77 != 0 ) {
#ifndef V_54
if ( V_97 ) {
T_32 V_210 , V_211 ;
if ( F_165 ( 1 , & V_210 ) == 0 && F_165 ( 2 , & V_211 ) == 0 ) {
if ( V_210 . V_212 == V_211 . V_212 &&
V_210 . V_213 == V_211 . V_213 ) {
fflush ( stdout ) ;
fprintf ( V_35 , L_1 ) ;
}
}
}
#endif
#if 0
switch (err) {
case FTAP_ERR_UNSUPPORTED:
cmdarg_err("The file \"%s\" contains record data that TFShark doesn't support.\n(%s)",
cf->filename, err_info);
g_free(err_info);
break;
case FTAP_ERR_UNSUPPORTED_ENCAP:
cmdarg_err("The file \"%s\" has a packet with a network type that TFShark doesn't support.\n(%s)",
cf->filename, err_info);
g_free(err_info);
break;
case FTAP_ERR_CANT_READ:
cmdarg_err("An attempt to read from the file \"%s\" failed for some unknown reason.",
cf->filename);
break;
case FTAP_ERR_SHORT_READ:
cmdarg_err("The file \"%s\" appears to have been cut short in the middle of a packet.",
cf->filename);
break;
case FTAP_ERR_BAD_FILE:
cmdarg_err("The file \"%s\" appears to be damaged or corrupt.\n(%s)",
cf->filename, err_info);
g_free(err_info);
break;
case FTAP_ERR_DECOMPRESS:
cmdarg_err("The compressed file \"%s\" appears to be damaged or corrupt.\n"
"(%s)", cf->filename, err_info);
break;
default:
cmdarg_err("An error occurred while reading the file \"%s\": %s.",
cf->filename, ftap_strerror(err));
break;
}
#endif
} else {
if ( V_97 ) {
if ( ! F_166 () ) {
V_77 = V_194 ;
F_146 ( V_77 ) ;
}
}
}
V_206:
F_167 ( V_164 -> V_199 ) ;
V_164 -> V_199 = NULL ;
return V_77 ;
}
static T_8
F_163 ( T_18 * V_164 , T_22 * V_174 , T_23 V_175 ,
struct V_176 * V_177 , const T_24 * V_178 , T_26 V_192 )
{
T_19 V_189 ;
T_27 * V_152 ;
T_8 V_181 ;
V_164 -> V_182 ++ ;
V_181 = TRUE ;
F_130 ( & V_189 , V_164 -> V_182 , V_177 , V_175 , V_183 ) ;
if ( V_174 ) {
if ( V_164 -> V_84 )
F_131 ( V_174 , V_164 -> V_84 ) ;
F_142 ( V_174 , & V_164 -> V_152 ) ;
if ( ( V_192 & V_193 ) || ( V_97 && V_99 ) || F_168 ( V_120 ) )
V_152 = & V_164 -> V_152 ;
else
V_152 = NULL ;
F_132 ( & V_189 , & V_164 -> V_184 ,
& V_165 , V_168 ) ;
if ( V_165 == & V_189 ) {
V_185 = V_189 ;
V_165 = & V_185 ;
}
F_143 ( V_174 , V_177 , F_169 ( & V_189 , V_178 ) , & V_189 , V_152 ) ;
if ( V_164 -> V_84 )
V_181 = F_135 ( V_164 -> V_84 , V_174 ) ;
}
if ( V_181 ) {
F_136 ( & V_189 , & V_183 ) ;
if ( V_97 ) {
F_145 ( V_164 , V_174 ) ;
if ( V_126 )
fflush ( stdout ) ;
if ( ferror ( stdout ) ) {
F_146 ( V_194 ) ;
exit ( 2 ) ;
}
}
V_214 = V_189 ;
V_168 = & V_214 ;
}
V_215 = V_189 ;
V_169 = & V_215 ;
if ( V_174 ) {
F_140 ( V_174 ) ;
F_139 ( & V_189 ) ;
}
return V_181 ;
}
static T_8
F_151 ( T_18 * V_164 )
{
switch ( V_142 ) {
case V_143 :
return F_170 ( V_154 , V_164 -> V_216 , F_3 () ) ;
case V_145 :
if ( V_96 )
F_171 ( stdout , V_164 -> V_216 ) ;
else
F_172 ( & V_164 -> V_152 , stdout ) ;
return ! ferror ( stdout ) ;
case V_146 :
F_173 ( V_120 , stdout ) ;
return ! ferror ( stdout ) ;
default:
F_22 () ;
return FALSE ;
}
}
static char *
F_174 ( T_33 V_217 )
{
static char * V_218 = NULL ;
static T_33 V_219 = 256 ;
T_33 V_220 ;
for ( V_220 = V_219 ; V_217 > V_220 ;
V_220 *= 2 )
;
if ( V_218 == NULL ) {
V_219 = V_220 ;
V_218 = ( char * ) F_149 ( V_219 + 1 ) ;
} else {
if ( V_220 > V_219 ) {
V_219 = V_220 ;
V_218 = ( char * ) F_175 ( V_218 , V_219 + 1 ) ;
}
}
return V_218 ;
}
static inline void
F_176 ( char * V_221 , const char * V_53 , T_33 V_222 )
{
memcpy ( V_221 , V_53 , V_222 ) ;
V_221 [ V_222 ] = '\0' ;
}
static inline void
F_177 ( char * V_221 , const char * V_53 , T_33 V_222 , T_33 V_223 )
{
T_33 V_33 ;
for ( V_33 = V_222 ; V_33 < V_223 ; V_33 ++ )
* V_221 ++ = ' ' ;
F_176 ( V_221 , V_53 , V_222 ) ;
}
static inline void
F_178 ( char * V_221 , const char * V_53 , T_33 V_222 , T_33 V_223 )
{
T_33 V_33 ;
memcpy ( V_221 , V_53 , V_222 ) ;
for ( V_33 = V_222 ; V_33 < V_223 ; V_33 ++ )
V_221 [ V_33 ] = ' ' ;
V_221 [ V_223 ] = '\0' ;
}
static T_8
F_179 ( T_18 * V_164 )
{
char * V_218 ;
int V_33 ;
T_33 V_224 ;
T_33 V_225 ;
T_33 V_226 ;
T_34 * V_227 ;
V_218 = F_174 ( 256 ) ;
V_224 = 0 ;
* V_218 = '\0' ;
for ( V_33 = 0 ; V_33 < V_164 -> V_152 . V_153 ; V_33 ++ ) {
V_227 = & V_164 -> V_152 . V_228 [ V_33 ] ;
if ( ! F_180 ( V_33 ) )
continue;
switch ( V_227 -> V_229 ) {
case V_230 :
V_225 = V_226 = strlen ( V_227 -> V_231 ) ;
if ( V_225 < 3 )
V_225 = 3 ;
V_218 = F_174 ( V_224 + V_225 ) ;
F_177 ( V_218 + V_224 , V_227 -> V_231 , V_226 , V_225 ) ;
break;
case V_232 :
case V_233 :
case V_234 :
case V_235 :
case V_236 :
case V_237 :
case V_238 :
case V_239 :
V_225 = V_226 = strlen ( V_227 -> V_231 ) ;
if ( V_225 < 10 )
V_225 = 10 ;
V_218 = F_174 ( V_224 + V_225 ) ;
F_177 ( V_218 + V_224 , V_227 -> V_231 , V_226 , V_225 ) ;
break;
case V_240 :
case V_241 :
case V_242 :
case V_243 :
case V_244 :
case V_245 :
case V_246 :
case V_247 :
case V_248 :
V_225 = V_226 = strlen ( V_227 -> V_231 ) ;
if ( V_225 < 12 )
V_225 = 12 ;
V_218 = F_174 ( V_224 + V_225 ) ;
F_177 ( V_218 + V_224 , V_227 -> V_231 , V_226 , V_225 ) ;
break;
case V_249 :
case V_250 :
case V_251 :
case V_252 :
case V_253 :
case V_254 :
case V_255 :
case V_256 :
case V_257 :
V_225 = V_226 = strlen ( V_227 -> V_231 ) ;
if ( V_225 < 12 )
V_225 = 12 ;
V_218 = F_174 ( V_224 + V_225 ) ;
F_178 ( V_218 + V_224 , V_227 -> V_231 , V_226 , V_225 ) ;
break;
default:
V_225 = strlen ( V_227 -> V_231 ) ;
V_218 = F_174 ( V_224 + V_225 ) ;
F_176 ( V_218 + V_224 , V_227 -> V_231 , V_225 ) ;
break;
}
V_224 += V_225 ;
if ( V_33 != V_164 -> V_152 . V_153 - 1 ) {
V_218 = F_174 ( V_224 + 4 ) ;
switch ( V_227 -> V_229 ) {
case V_240 :
case V_241 :
case V_242 :
switch ( V_164 -> V_152 . V_228 [ V_33 + 1 ] . V_229 ) {
case V_249 :
case V_250 :
case V_251 :
F_176 ( V_218 + V_224 , L_180 , 4 ) ;
V_224 += 4 ;
break;
default:
F_176 ( V_218 + V_224 , L_181 , 1 ) ;
V_224 += 1 ;
break;
}
break;
case V_243 :
case V_244 :
case V_245 :
switch ( V_164 -> V_152 . V_228 [ V_33 + 1 ] . V_229 ) {
case V_252 :
case V_253 :
case V_254 :
F_176 ( V_218 + V_224 , L_180 , 4 ) ;
V_224 += 4 ;
break;
default:
F_176 ( V_218 + V_224 , L_181 , 1 ) ;
V_224 += 1 ;
break;
}
break;
case V_246 :
case V_247 :
case V_248 :
switch ( V_164 -> V_152 . V_228 [ V_33 + 1 ] . V_229 ) {
case V_255 :
case V_256 :
case V_257 :
F_176 ( V_218 + V_224 , L_180 , 4 ) ;
V_224 += 4 ;
break;
default:
F_176 ( V_218 + V_224 , L_181 , 1 ) ;
V_224 += 1 ;
break;
}
break;
case V_249 :
case V_250 :
case V_251 :
switch ( V_164 -> V_152 . V_228 [ V_33 + 1 ] . V_229 ) {
case V_240 :
case V_241 :
case V_242 :
F_176 ( V_218 + V_224 , L_182 , 4 ) ;
V_224 += 4 ;
break;
default:
F_176 ( V_218 + V_224 , L_181 , 1 ) ;
V_224 += 1 ;
break;
}
break;
case V_252 :
case V_253 :
case V_254 :
switch ( V_164 -> V_152 . V_228 [ V_33 + 1 ] . V_229 ) {
case V_243 :
case V_244 :
case V_245 :
F_176 ( V_218 + V_224 , L_182 , 4 ) ;
V_224 += 4 ;
break;
default:
F_176 ( V_218 + V_224 , L_181 , 1 ) ;
V_224 += 1 ;
break;
}
break;
case V_255 :
case V_256 :
case V_257 :
switch ( V_164 -> V_152 . V_228 [ V_33 + 1 ] . V_229 ) {
case V_246 :
case V_247 :
case V_248 :
F_176 ( V_218 + V_224 , L_182 , 4 ) ;
V_224 += 4 ;
break;
default:
F_176 ( V_218 + V_224 , L_181 , 1 ) ;
V_224 += 1 ;
break;
}
break;
default:
F_176 ( V_218 + V_224 , L_181 , 1 ) ;
V_224 += 1 ;
break;
}
}
}
return F_181 ( V_154 , 0 , V_218 ) ;
}
static T_8
F_145 ( T_18 * V_164 , T_22 * V_174 )
{
T_35 V_258 ;
if ( V_99 || F_168 ( V_120 ) ) {
F_182 ( V_174 , FALSE , TRUE ) ;
if ( V_99 ) {
switch ( V_142 ) {
case V_143 :
if ( ! F_179 ( V_164 ) )
return FALSE ;
break;
case V_145 :
F_183 ( V_174 , stdout ) ;
return ! ferror ( stdout ) ;
case V_146 :
F_22 () ;
break;
}
}
}
if ( V_96 ) {
switch ( V_142 ) {
case V_143 :
V_258 . V_98 = V_98 ;
V_258 . V_259 = V_96 ? V_260 : V_261 ;
if ( ! F_184 ( & V_258 , V_174 , V_149 , V_154 ) )
return FALSE ;
if ( ! V_98 ) {
if ( ! F_181 ( V_154 , 0 , V_132 ) )
return FALSE ;
}
break;
case V_145 :
F_185 ( V_174 , stdout ) ;
printf ( L_1 ) ;
return ! ferror ( stdout ) ;
case V_146 :
F_186 ( V_120 , V_174 , & V_164 -> V_152 , stdout ) ;
printf ( L_1 ) ;
return ! ferror ( stdout ) ;
}
}
if ( V_98 ) {
if ( V_99 || V_96 ) {
if ( ! F_181 ( V_154 , 0 , L_84 ) )
return FALSE ;
}
if ( ! F_187 ( V_154 , V_174 ) )
return FALSE ;
if ( ! F_181 ( V_154 , 0 , V_132 ) )
return FALSE ;
}
return TRUE ;
}
static T_8
F_166 ( void )
{
switch ( V_142 ) {
case V_143 :
return F_188 ( V_154 ) ;
case V_145 :
if ( V_96 )
F_189 ( stdout ) ;
else
F_190 ( stdout ) ;
return ! ferror ( stdout ) ;
case V_146 :
F_191 ( V_120 , stdout ) ;
return ! ferror ( stdout ) ;
default:
F_22 () ;
return FALSE ;
}
}
T_36
F_115 ( T_18 * V_164 , const char * V_262 , unsigned int type , T_8 V_263 , int * V_77 )
{
T_3 * T_29 ;
char V_85 [ 2048 + 1 ] ;
F_122 ( V_164 -> V_161 ) ;
V_164 -> V_161 = F_127 ( V_164 ) ;
V_164 -> V_199 = NULL ;
V_164 -> V_264 = 0 ;
V_164 -> V_216 = F_17 ( V_262 ) ;
V_164 -> V_263 = V_263 ;
V_164 -> V_265 = FALSE ;
V_164 -> V_266 = 0 ;
V_164 -> V_267 = type ;
V_164 -> V_182 = 0 ;
V_164 -> V_268 = FALSE ;
V_164 -> V_269 = 0 ;
V_164 -> V_270 = 0 ;
if ( V_164 -> V_270 == 0 ) {
V_164 -> V_271 = FALSE ;
V_164 -> V_270 = 0 ;
} else
V_164 -> V_271 = TRUE ;
F_192 ( & V_164 -> V_184 ) ;
V_165 = NULL ;
V_168 = NULL ;
V_169 = NULL ;
V_164 -> V_272 = V_273 ;
return V_157 ;
F_193 ( V_85 , sizeof V_85 ,
F_194 ( * V_77 , T_29 , FALSE , V_164 -> V_266 ) , V_262 ) ;
F_18 ( L_86 , V_85 ) ;
return V_274 ;
}
static void
F_146 ( int V_77 )
{
switch ( V_77 ) {
case V_275 :
F_18 ( L_183
L_184 ) ;
break;
#ifdef F_195
case F_195 :
F_18 ( L_185
L_186 ) ;
break;
#endif
default:
F_18 ( L_187 ,
F_85 ( V_77 ) ) ;
break;
}
}
static const char *
F_194 ( int V_77 , T_3 * T_29 V_6 , T_8 V_276 ,
int T_37 V_6 )
{
const char * V_277 ;
#if 0
if (err < 0) {
switch (err) {
case FTAP_ERR_NOT_REGULAR_FILE:
errmsg = "The file \"%s\" is a \"special file\" or socket or other non-regular file.";
break;
case FTAP_ERR_RANDOM_OPEN_PIPE:
errmsg = "The file \"%s\" is a pipe or FIFO; TFShark can't read pipe or FIFO files in two-pass mode.";
break;
case FTAP_ERR_FILE_UNKNOWN_FORMAT:
errmsg = "The file \"%s\" isn't a capture file in a format TFShark understands.";
break;
case FTAP_ERR_UNSUPPORTED:
g_snprintf(errmsg_errno, sizeof(errmsg_errno),
"The file \"%%s\" isn't a capture file in a format TFShark understands.\n"
"(%s)", err_info);
g_free(err_info);
errmsg = errmsg_errno;
break;
case FTAP_ERR_CANT_WRITE_TO_PIPE:
g_snprintf(errmsg_errno, sizeof(errmsg_errno),
"The file \"%%s\" is a pipe, and \"%s\" capture files can't be "
"written to a pipe.", ftap_file_type_subtype_short_string(file_type));
errmsg = errmsg_errno;
break;
case FTAP_ERR_UNSUPPORTED_FILE_TYPE:
errmsg = "TFShark doesn't support writing capture files in that format.";
break;
case FTAP_ERR_UNSUPPORTED_ENCAP:
if (for_writing) {
g_snprintf(errmsg_errno, sizeof(errmsg_errno),
"TFShark can't save this capture as a \"%s\" file.",
ftap_file_type_subtype_short_string(file_type));
} else {
g_snprintf(errmsg_errno, sizeof(errmsg_errno),
"The file \"%%s\" is a capture for a network type that TFShark doesn't support.\n"
"(%s)", err_info);
g_free(err_info);
}
errmsg = errmsg_errno;
break;
case FTAP_ERR_ENCAP_PER_RECORD_UNSUPPORTED:
if (for_writing) {
g_snprintf(errmsg_errno, sizeof(errmsg_errno),
"TFShark can't save this capture as a \"%s\" file.",
ftap_file_type_subtype_short_string(file_type));
errmsg = errmsg_errno;
} else
errmsg = "The file \"%s\" is a capture for a network type that TFShark doesn't support.";
break;
case FTAP_ERR_BAD_FILE:
g_snprintf(errmsg_errno, sizeof(errmsg_errno),
"The file \"%%s\" appears to be damaged or corrupt.\n"
"(%s)", err_info);
g_free(err_info);
errmsg = errmsg_errno;
break;
case FTAP_ERR_CANT_OPEN:
if (for_writing)
errmsg = "The file \"%s\" could not be created for some unknown reason.";
else
errmsg = "The file \"%s\" could not be opened for some unknown reason.";
break;
case FTAP_ERR_SHORT_READ:
errmsg = "The file \"%s\" appears to have been cut short"
" in the middle of a packet or other data.";
break;
case FTAP_ERR_SHORT_WRITE:
errmsg = "A full header couldn't be written to the file \"%s\".";
break;
case FTAP_ERR_COMPRESSION_NOT_SUPPORTED:
errmsg = "This file type cannot be written as a compressed file.";
break;
case FTAP_ERR_DECOMPRESS:
g_snprintf(errmsg_errno, sizeof(errmsg_errno),
"The compressed file \"%%s\" appears to be damaged or corrupt.\n"
"(%s)", err_info);
g_free(err_info);
errmsg = errmsg_errno;
break;
default:
g_snprintf(errmsg_errno, sizeof(errmsg_errno),
"The file \"%%s\" could not be %s: %s.",
for_writing ? "created" : "opened",
ftap_strerror(err));
errmsg = errmsg_errno;
break;
}
} else
#endif
V_277 = F_196 ( V_77 , V_276 ) ;
return V_277 ;
}
static void
V_109 ( const char * V_216 , int V_77 , T_8 V_276 )
{
fprintf ( V_35 , L_188 ) ;
fprintf ( V_35 , F_196 ( V_77 , V_276 ) , V_216 ) ;
fprintf ( V_35 , L_1 ) ;
}
static void
V_91 ( const char * V_278 , T_38 V_279 )
{
fprintf ( V_35 , L_188 ) ;
vfprintf ( V_35 , V_278 , V_279 ) ;
fprintf ( V_35 , L_1 ) ;
}
static void
V_110 ( const char * V_216 , int V_77 )
{
F_18 ( L_189 ,
V_216 , F_85 ( V_77 ) ) ;
}
static void
V_111 ( const char * V_216 , int V_77 )
{
F_18 ( L_190 ,
V_216 , F_85 ( V_77 ) ) ;
}
static void
V_92 ( const char * V_278 , T_38 V_279 )
{
vfprintf ( V_35 , V_278 , V_279 ) ;
fprintf ( V_35 , L_1 ) ;
}
