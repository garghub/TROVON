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
F_34 ( V_53 ) ;
}
int
main ( int V_54 , char * V_55 [] )
{
T_14 * V_56 ;
T_14 * V_57 ;
char * V_58 ;
int V_59 ;
static const struct V_60 V_61 [] = {
{ L_78 , V_62 , NULL , 'h' } ,
{ L_79 , V_62 , NULL , 'v' } ,
{ 0 , 0 , 0 , 0 }
} ;
T_8 V_63 = FALSE ;
char * V_64 , * V_65 ;
char * V_66 , * V_67 ;
int V_68 , V_69 ;
int V_70 , V_71 ;
int V_72 , V_73 ;
int V_74 , V_75 ;
int V_76 ;
volatile int V_77 = 0 ;
T_8 V_78 = FALSE ;
T_3 * volatile V_79 = NULL ;
T_3 * V_80 = NULL ;
T_3 * V_81 = NULL ;
T_15 * V_82 = NULL ;
T_15 * V_83 = NULL ;
T_3 * V_84 ;
T_16 * V_85 ;
int V_86 ;
T_3 * V_87 = NULL ;
#define F_35 "+2C:d:e:E:hK:lo:O:qQr:R:S:t:T:u:vVxX:Y:z:"
static const char V_88 [] = F_35 ;
setlocale ( V_89 , L_80 ) ;
F_36 ( V_90 , V_91 ) ;
#ifdef F_37
F_38 ( V_54 , V_55 ) ;
F_39 () ;
#if ! F_40 ( 2 , 31 , 0 )
F_41 ( NULL ) ;
#endif
#endif
F_42 () ;
F_43 () ;
F_28 () ;
V_58 = F_44 ( V_55 [ 0 ] , main ) ;
if ( V_58 != NULL ) {
fprintf ( V_35 , L_81 ,
V_58 ) ;
}
F_45 () ;
V_56 = F_46 ( NULL , V_92 ) ;
V_57 = F_47 ( F_33 ) ;
F_48 ( L_47
L_1
L_82
L_1
L_82 ,
F_3 () , V_56 -> V_53 , V_57 -> V_53 ) ;
V_93 = 0 ;
while ( ( V_59 = F_49 ( V_54 , V_55 , V_88 , V_61 , NULL ) ) != - 1 ) {
switch ( V_59 ) {
case 'C' :
if ( F_50 ( V_94 , FALSE ) ) {
F_51 ( V_94 ) ;
} else {
F_18 ( L_83 , V_94 ) ;
return 1 ;
}
break;
case 'O' :
V_87 = F_17 ( V_94 ) ;
case 'V' :
V_95 = TRUE ;
V_96 = TRUE ;
break;
case 'x' :
V_97 = TRUE ;
V_96 = TRUE ;
break;
case 'X' :
F_52 ( V_94 ) ;
break;
default:
break;
}
}
if ( V_98 == - 1 )
V_98 = ( V_95 || V_97 ) ? FALSE : TRUE ;
V_86 =
V_99 |
V_100 |
V_101 |
V_102 |
V_103 |
V_104 |
V_105 | V_106 ;
F_53 ( NULL ,
( T_13 ) V_86 ,
F_26 , NULL ) ;
F_53 ( V_107 ,
( T_13 ) V_86 ,
F_26 , NULL ) ;
F_54 ( V_90 , V_108 , V_109 ,
V_110 ) ;
F_55 ( V_111 ) ;
F_56 ( V_112 ) ;
F_57 ( V_113 ) ;
F_58 () ;
#ifdef F_59
F_60 () ;
F_61 () ;
#endif
if ( ! F_62 ( V_114 , V_115 , NULL ,
NULL ) )
return 2 ;
if ( V_54 >= 2 && strcmp ( V_55 [ 1 ] , L_84 ) == 0 ) {
F_63 () ;
if ( V_54 == 2 )
F_64 () ;
else {
if ( strcmp ( V_55 [ 2 ] , L_85 ) == 0 )
F_65 () ;
else if ( strcmp ( V_55 [ 2 ] , L_86 ) == 0 ) {
F_66 ( & V_68 , & V_69 , & V_64 ,
& V_70 , & V_71 , & V_65 ) ;
F_67 ( NULL ) ;
}
else if ( strcmp ( V_55 [ 2 ] , L_87 ) == 0 )
F_68 () ;
else if ( strcmp ( V_55 [ 2 ] , L_88 ) == 0 )
F_67 ( NULL ) ;
else if ( strcmp ( V_55 [ 2 ] , L_89 ) == 0 )
F_69 () ;
else if ( strcmp ( V_55 [ 2 ] , L_90 ) == 0 )
F_64 () ;
else if ( strcmp ( V_55 [ 2 ] , L_91 ) == 0 )
F_70 () ;
else if ( strcmp ( V_55 [ 2 ] , L_92 ) == 0 )
F_71 () ;
else if ( strcmp ( V_55 [ 2 ] , L_93 ) == 0 ) {
#ifdef F_59
F_72 () ;
#endif
#ifdef F_73
F_74 () ;
#endif
}
else if ( strcmp ( V_55 [ 2 ] , L_94 ) == 0 )
F_75 () ;
else if ( strcmp ( V_55 [ 2 ] , L_95 ) == 0 )
F_76 () ;
else if ( strcmp ( V_55 [ 2 ] , L_96 ) == 0 )
F_2 () ;
else if ( strcmp ( V_55 [ 2 ] , L_97 ) == 0 )
F_2 () ;
else {
F_18 ( L_98 , V_55 [ 2 ] ) ;
return 1 ;
}
}
return 0 ;
}
V_85 = F_66 ( & V_68 , & V_69 , & V_64 ,
& V_70 , & V_71 , & V_65 ) ;
if ( V_64 != NULL ) {
if ( V_68 != 0 ) {
F_18 ( L_99 ,
V_65 , F_77 ( V_68 ) ) ;
}
if ( V_69 != 0 ) {
F_18 ( L_100 ,
V_65 , F_77 ( V_69 ) ) ;
}
}
if ( V_65 != NULL ) {
if ( V_70 != 0 ) {
F_18 ( L_101 , V_65 ,
F_77 ( V_70 ) ) ;
}
if ( V_71 != 0 ) {
F_18 ( L_102 ,
V_65 , F_77 ( V_71 ) ) ;
}
F_20 ( V_65 ) ;
V_65 = NULL ;
}
F_78 ( & V_66 , & V_72 , & V_73 ,
& V_67 , & V_74 , & V_75 ) ;
F_79 ( & V_66 , & V_72 , & V_73 ,
& V_67 , & V_74 , & V_75 ) ;
if ( V_66 != NULL ) {
if ( V_72 != 0 ) {
F_18 ( L_103 ,
V_66 , F_77 ( V_72 ) ) ;
}
if ( V_73 != 0 ) {
F_18 ( L_104 ,
V_66 , F_77 ( V_73 ) ) ;
}
F_20 ( V_66 ) ;
}
if ( V_67 != NULL ) {
if ( V_74 != 0 ) {
F_18 (
L_105 , V_67 ,
F_77 ( V_74 ) ) ;
}
if ( V_75 != 0 ) {
F_18 (
L_106 , V_67 ,
F_77 ( V_75 ) ) ;
}
F_20 ( V_67 ) ;
}
F_80 ( & V_116 ) ;
V_117 = V_118 ;
V_119 = F_81 () ;
#ifdef F_82
V_120 = 1 ;
V_121 = 1 ;
#else
V_121 = 0 ;
#endif
V_93 = 1 ;
while ( ( V_59 = F_49 ( V_54 , V_55 , V_88 , V_61 , NULL ) ) != - 1 ) {
switch ( V_59 ) {
case '2' :
V_122 = TRUE ;
break;
case 'C' :
break;
case 'd' :
if ( ! F_16 ( V_94 ) )
return 1 ;
break;
#if F_83 ( V_123 ) || F_83 ( V_124 )
case 'K' :
F_84 ( V_94 ) ;
break;
#endif
case 'e' :
F_85 ( V_119 , V_94 ) ;
break;
case 'E' :
if ( ! F_86 ( V_119 , V_94 ) ) {
F_18 ( L_107 , V_94 ) ;
F_87 ( V_35 ) ;
return 1 ;
}
break;
case 'h' :
printf ( L_47
L_108
L_109 ,
F_3 () ) ;
F_1 ( stdout ) ;
return 0 ;
break;
case 'l' :
V_125 = TRUE ;
break;
case 'o' :
switch ( F_88 ( V_94 ) ) {
case V_126 :
break;
case V_127 :
F_18 ( L_110 , V_94 ) ;
return 1 ;
break;
case V_128 :
case V_129 :
F_18 ( L_111 , V_94 ) ;
return 1 ;
break;
}
break;
case 'q' :
V_78 = TRUE ;
break;
case 'Q' :
V_78 = TRUE ;
V_130 = TRUE ;
break;
case 'r' :
V_79 = F_17 ( V_94 ) ;
break;
case 'R' :
V_80 = V_94 ;
break;
case 'S' :
V_131 = F_17 ( V_94 ) ;
break;
case 't' :
if ( strcmp ( V_94 , L_112 ) == 0 )
F_55 ( V_111 ) ;
else if ( strcmp ( V_94 , L_113 ) == 0 )
F_55 ( V_132 ) ;
else if ( strcmp ( V_94 , L_114 ) == 0 )
F_55 ( V_133 ) ;
else if ( strcmp ( V_94 , L_115 ) == 0 )
F_55 ( V_134 ) ;
else if ( strcmp ( V_94 , L_116 ) == 0 )
F_55 ( V_135 ) ;
else if ( strcmp ( V_94 , L_117 ) == 0 )
F_55 ( V_136 ) ;
else if ( strcmp ( V_94 , L_118 ) == 0 )
F_55 ( V_137 ) ;
else if ( strcmp ( V_94 , L_119 ) == 0 )
F_55 ( V_138 ) ;
else if ( strcmp ( V_94 , L_120 ) == 0 )
F_55 ( V_139 ) ;
else if ( strcmp ( V_94 , L_121 ) == 0 )
F_55 ( V_140 ) ;
else {
F_18 ( L_122 , V_94 ) ;
F_89 ( L_123
L_124
L_125
L_126
L_127
L_128
L_129
L_130
L_131
L_132 ) ;
return 1 ;
}
break;
case 'T' :
if ( strcmp ( V_94 , L_133 ) == 0 ) {
V_141 = V_142 ;
V_117 = V_118 ;
} else if ( strcmp ( V_94 , L_134 ) == 0 ) {
V_141 = V_142 ;
V_117 = V_143 ;
} else if ( strcmp ( V_94 , L_135 ) == 0 ) {
V_141 = V_144 ;
V_95 = TRUE ;
V_98 = FALSE ;
} else if ( strcmp ( V_94 , L_136 ) == 0 ) {
V_141 = V_144 ;
V_95 = FALSE ;
V_98 = TRUE ;
} else if ( strcmp ( V_94 , L_90 ) == 0 ) {
V_141 = V_145 ;
V_95 = TRUE ;
V_98 = FALSE ;
} else {
F_18 ( L_137 , V_94 ) ;
F_89 ( L_138
L_139
L_140
L_141
L_142
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
L_153 ) ;
return 1 ;
}
break;
case 'u' :
if ( strcmp ( V_94 , L_154 ) == 0 )
F_57 ( V_113 ) ;
else if ( strcmp ( V_94 , L_155 ) == 0 )
F_57 ( V_146 ) ;
else {
F_18 ( L_156 , V_94 ) ;
F_89 ( L_157
L_158 ) ;
return 1 ;
}
break;
case 'v' :
{
F_90 ( L_159 , V_56 , V_57 ) ;
F_91 ( V_56 , TRUE ) ;
F_91 ( V_57 , TRUE ) ;
F_92 () ;
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
V_81 = V_94 ;
break;
case 'z' :
if ( strcmp ( L_78 , V_94 ) == 0 ) {
fprintf ( V_35 , L_160 ) ;
F_93 () ;
return 0 ;
}
if ( ! F_94 ( V_94 ) ) {
F_18 ( L_161 , V_94 ) ;
F_93 () ;
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
if ( V_145 != V_141 && 0 != F_95 ( V_119 ) ) {
F_18 ( L_162
L_163 ) ;
return 1 ;
} else if ( V_145 == V_141 && 0 == F_95 ( V_119 ) ) {
F_18 ( L_164
L_165 ) ;
return 1 ;
}
if ( V_121 < V_54 ) {
if ( V_79 != NULL ) {
if ( V_81 != NULL ) {
F_18 ( L_166
L_167 ) ;
return 1 ;
}
V_81 = F_96 ( V_54 , V_55 , V_121 ) ;
}
}
if ( ! V_78 )
V_96 = TRUE ;
if ( V_63 ) {
F_1 ( V_35 ) ;
return 1 ;
}
if ( V_97 ) {
if ( V_141 != V_142 ) {
F_18 ( L_168 ) ;
return 1 ;
}
}
if ( V_87 != NULL ) {
char * V_147 ;
if ( ! V_95 ) {
F_18 ( L_169 ) ;
return 1 ;
}
V_148 = F_97 ( V_149 , V_150 ) ;
for ( V_147 = strtok ( V_87 , L_170 ) ; V_147 ; V_147 = strtok ( NULL , L_170 ) ) {
F_98 ( V_148 , ( T_2 ) V_147 , ( T_2 ) V_147 ) ;
}
}
if ( V_80 != NULL && ! V_122 ) {
F_18 ( L_171 ) ;
return 1 ;
}
F_99 () ;
F_100 () ;
if ( V_66 == NULL && V_67 == NULL ) {
F_101 () ;
F_102 () ;
}
F_103 ( & V_116 . V_151 , V_85 -> V_152 , TRUE ) ;
if ( V_80 != NULL ) {
if ( ! F_104 ( V_80 , & V_82 , & V_84 ) ) {
F_18 ( L_82 , V_84 ) ;
F_20 ( V_84 ) ;
F_92 () ;
return 2 ;
}
}
V_116 . V_82 = V_82 ;
if ( V_81 != NULL ) {
if ( ! F_104 ( V_81 , & V_83 , & V_84 ) ) {
F_18 ( L_82 , V_84 ) ;
F_20 ( V_84 ) ;
F_92 () ;
return 2 ;
}
}
V_116 . V_83 = V_83 ;
if ( V_96 ) {
if ( V_141 == V_142 ) {
switch ( V_117 ) {
case V_118 :
V_153 = F_105 ( stdout ) ;
break;
case V_143 :
V_153 = F_106 ( stdout ) ;
break;
default:
F_22 () ;
}
}
}
V_154 = V_96 || V_82 || V_83 || F_107 () ;
if ( V_79 ) {
if ( F_108 ( & V_116 , V_79 , V_155 , FALSE , & V_76 ) != V_156 ) {
F_92 () ;
return 2 ;
}
F_109 {
V_76 = F_110 ( & V_116 , 1 , 0 ) ;
}
F_111 (OutOfMemoryError) {
fprintf ( V_35 ,
L_172
L_1
L_173
L_1
L_174
L_175 ) ;
V_76 = V_157 ;
}
V_158 ;
if ( V_76 != 0 ) {
V_77 = 2 ;
}
}
F_20 ( V_79 ) ;
if ( V_116 . V_159 != NULL ) {
F_112 ( V_116 . V_159 ) ;
V_116 . V_159 = NULL ;
}
F_113 ( TRUE ) ;
F_114 () ;
F_115 ( V_116 . V_160 ) ;
F_92 () ;
F_116 ( V_119 ) ;
V_119 = NULL ;
return V_77 ;
}
static const T_17 *
F_117 ( void * V_161 , T_9 V_162 )
{
T_18 * V_163 = ( T_18 * ) V_161 ;
if ( V_164 && V_164 -> V_165 == V_162 )
return & V_164 -> V_166 ;
if ( V_167 && V_167 -> V_165 == V_162 )
return & V_167 -> V_166 ;
if ( V_168 && V_168 -> V_165 == V_162 )
return & V_168 -> V_166 ;
if ( V_163 -> V_159 ) {
T_19 * V_169 = F_118 ( V_163 -> V_159 , V_162 ) ;
return ( V_169 ) ? & V_169 -> V_166 : NULL ;
}
return NULL ;
}
static const char *
F_119 ( void * V_161 V_6 , T_9 T_20 V_6 )
{
return L_80 ;
}
static T_21 *
F_120 ( T_18 * V_163 )
{
T_21 * V_160 = F_121 () ;
V_160 -> V_161 = V_163 ;
V_160 -> V_170 = F_117 ;
V_160 -> V_171 = F_119 ;
V_160 -> V_172 = NULL ;
return V_160 ;
}
static T_8
F_122 ( T_18 * V_163 , T_22 * V_173 ,
T_23 V_174 , struct V_175 * V_176 ,
const T_24 * V_177 )
{
T_19 V_178 ;
T_9 V_179 ;
T_8 V_180 ;
V_179 = V_163 -> V_181 + 1 ;
V_180 = TRUE ;
F_123 ( & V_178 , V_179 , V_176 , V_174 , V_182 ) ;
if ( V_173 ) {
if ( V_163 -> V_82 )
F_124 ( V_173 , V_163 -> V_82 ) ;
F_125 ( & V_178 , & V_163 -> V_183 ,
& V_164 , V_167 ) ;
if ( V_164 == & V_178 ) {
V_184 = V_178 ;
V_164 = & V_184 ;
}
F_126 ( V_173 , V_176 , F_127 ( & V_178 , V_177 ) , & V_178 , NULL ) ;
if ( V_163 -> V_82 )
V_180 = F_128 ( V_163 -> V_82 , V_173 ) ;
}
if ( V_180 ) {
F_129 ( & V_178 , & V_182 ) ;
V_168 = V_167 = F_130 ( V_163 -> V_159 , & V_178 ) ;
if ( V_173 ) {
F_131 ( V_173 -> V_185 . V_186 , V_187 , V_163 -> V_159 ) ;
}
V_163 -> V_181 ++ ;
} else {
F_132 ( & V_178 ) ;
}
if ( V_173 )
F_133 ( V_173 ) ;
return V_180 ;
}
static T_8
F_134 ( T_18 * V_163 , T_22 * V_173 , T_19 * V_188 ,
struct V_175 * V_189 , T_25 * V_190 ,
T_26 V_191 )
{
T_27 * V_151 ;
T_8 V_180 ;
V_180 = TRUE ;
if ( V_173 ) {
if ( V_163 -> V_83 )
F_124 ( V_173 , V_163 -> V_83 ) ;
F_135 ( V_173 , & V_163 -> V_151 ) ;
if ( ( V_191 & V_192 ) || ( V_96 && V_98 ) )
V_151 = & V_163 -> V_151 ;
else
V_151 = NULL ;
F_125 ( V_188 , & V_163 -> V_183 ,
& V_164 , V_167 ) ;
if ( V_164 == V_188 ) {
V_184 = * V_188 ;
V_164 = & V_184 ;
}
F_136 ( V_173 , V_189 , F_137 ( V_188 , V_190 ) , V_188 , V_151 ) ;
if ( V_163 -> V_83 )
V_180 = F_128 ( V_163 -> V_83 , V_173 ) ;
}
if ( V_180 ) {
F_129 ( V_188 , & V_182 ) ;
if ( V_96 ) {
F_138 ( V_163 , V_173 ) ;
if ( V_125 )
fflush ( stdout ) ;
if ( ferror ( stdout ) ) {
F_139 ( V_193 ) ;
exit ( 2 ) ;
}
}
V_167 = V_188 ;
}
V_168 = V_188 ;
if ( V_173 ) {
F_133 ( V_173 ) ;
}
return V_180 || V_188 -> V_194 . V_195 ;
}
static T_8
F_140 ( T_18 * V_163 , struct V_175 * T_28 V_6 , int * V_76 , T_3 * * T_29 V_6 , T_23 * T_30 V_6 , T_31 * * V_196 )
{
T_23 V_197 = F_141 ( V_163 -> V_198 , V_76 ) ;
* V_196 = ( T_31 * ) F_142 ( ( V_199 ) V_197 ) ;
F_143 ( * V_196 , ( unsigned int ) V_197 , V_163 -> V_198 -> V_200 ) ;
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
F_110 ( T_18 * V_163 , int V_201 , T_23 V_202 )
{
T_9 V_179 ;
int V_76 ;
T_3 * T_29 = NULL ;
T_23 T_30 = 0 ;
T_8 V_203 ;
T_26 V_191 ;
T_25 V_190 ;
T_22 * V_173 = NULL ;
struct V_175 T_28 ;
T_31 * V_204 ;
if ( V_96 ) {
if ( ! F_144 ( V_163 ) ) {
V_76 = V_193 ;
F_139 ( V_76 ) ;
goto V_205;
}
}
V_203 = F_145 () ;
V_191 = F_146 () ;
F_147 ( & T_28 ) ;
T_28 . V_206 = 1234 ;
if ( V_122 ) {
T_19 * V_188 ;
V_163 -> V_159 = F_148 () ;
if ( V_154 ) {
T_8 V_207 = FALSE ;
if ( V_163 -> V_82 )
V_207 = TRUE ;
V_173 = F_149 ( V_163 -> V_160 , V_207 , FALSE ) ;
}
while ( F_140 ( V_163 , & T_28 , & V_76 , & T_29 , & T_30 , & V_204 ) ) {
if ( F_122 ( V_163 , V_173 , T_30 , & T_28 ,
F_150 ( V_163 -> V_198 ) ) ) {
if ( ( -- V_201 == 0 ) || ( V_202 != 0 && T_30 >= V_202 ) ) {
V_76 = 0 ;
break;
}
}
}
if ( V_173 ) {
F_151 ( V_173 ) ;
V_173 = NULL ;
}
#if 0
wtap_sequential_close(cf->wth);
#endif
F_152 () ;
V_167 = NULL ;
V_168 = NULL ;
F_153 ( & V_190 , 1500 ) ;
if ( V_154 ) {
T_8 V_207 ;
if ( V_163 -> V_83 || V_95 || V_203 ||
( V_191 & V_208 ) || F_154 ( & V_163 -> V_151 ) )
V_207 = TRUE ;
else
V_207 = FALSE ;
V_173 = F_149 ( V_163 -> V_160 , V_207 , V_96 && V_95 ) ;
}
for ( V_179 = 1 ; V_76 == 0 && V_179 <= V_163 -> V_181 ; V_179 ++ ) {
V_188 = F_118 ( V_163 -> V_159 , V_179 ) ;
#if 0
if (wtap_seek_read(cf->wth, fdata->file_off,
&buf, fdata->cap_len, &err, &err_info)) {
process_packet_second_pass(cf, edt, fdata, &cf->phdr, &buf, tap_flags);
}
#else
F_134 ( V_163 , V_173 , V_188 , & V_163 -> V_189 , & V_190 , V_191 ) ;
#endif
}
if ( V_173 ) {
F_151 ( V_173 ) ;
V_173 = NULL ;
}
F_155 ( & V_190 ) ;
}
else {
V_179 = 0 ;
if ( V_154 ) {
T_8 V_207 ;
if ( V_163 -> V_82 || V_163 -> V_83 || V_95 || V_203 ||
( V_191 & V_208 ) || F_154 ( & V_163 -> V_151 ) )
V_207 = TRUE ;
else
V_207 = FALSE ;
V_173 = F_149 ( V_163 -> V_160 , V_207 , V_96 && V_95 ) ;
}
while ( F_140 ( V_163 , & T_28 , & V_76 , & T_29 , & T_30 , & V_204 ) ) {
V_179 ++ ;
F_156 ( V_163 , V_173 , T_30 , & T_28 ,
V_204 , V_191 ) ;
if ( ( -- V_201 == 0 ) || ( V_202 != 0 && T_30 >= V_202 ) ) {
V_76 = 0 ;
break;
}
}
if ( V_173 ) {
F_151 ( V_173 ) ;
V_173 = NULL ;
}
}
F_157 ( & T_28 ) ;
if ( V_76 != 0 ) {
#ifndef F_37
if ( V_96 ) {
T_32 V_209 , V_210 ;
if ( F_158 ( 1 , & V_209 ) == 0 && F_158 ( 2 , & V_210 ) == 0 ) {
if ( V_209 . V_211 == V_210 . V_211 &&
V_209 . V_212 == V_210 . V_212 ) {
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
if ( V_96 ) {
if ( ! F_159 () ) {
V_76 = V_193 ;
F_139 ( V_76 ) ;
}
}
}
V_205:
F_160 ( V_163 -> V_198 ) ;
V_163 -> V_198 = NULL ;
return V_76 ;
}
static T_8
F_156 ( T_18 * V_163 , T_22 * V_173 , T_23 V_174 ,
struct V_175 * V_176 , const T_24 * V_177 , T_26 V_191 )
{
T_19 V_188 ;
T_27 * V_151 ;
T_8 V_180 ;
V_163 -> V_181 ++ ;
V_180 = TRUE ;
F_123 ( & V_188 , V_163 -> V_181 , V_176 , V_174 , V_182 ) ;
if ( V_173 ) {
if ( V_163 -> V_83 )
F_124 ( V_173 , V_163 -> V_83 ) ;
F_135 ( V_173 , & V_163 -> V_151 ) ;
if ( ( V_191 & V_192 ) || ( V_96 && V_98 ) || F_161 ( V_119 ) )
V_151 = & V_163 -> V_151 ;
else
V_151 = NULL ;
F_125 ( & V_188 , & V_163 -> V_183 ,
& V_164 , V_167 ) ;
if ( V_164 == & V_188 ) {
V_184 = V_188 ;
V_164 = & V_184 ;
}
F_136 ( V_173 , V_176 , F_162 ( & V_188 , V_177 ) , & V_188 , V_151 ) ;
if ( V_163 -> V_83 )
V_180 = F_128 ( V_163 -> V_83 , V_173 ) ;
}
if ( V_180 ) {
F_129 ( & V_188 , & V_182 ) ;
if ( V_96 ) {
F_138 ( V_163 , V_173 ) ;
if ( V_125 )
fflush ( stdout ) ;
if ( ferror ( stdout ) ) {
F_139 ( V_193 ) ;
exit ( 2 ) ;
}
}
V_213 = V_188 ;
V_167 = & V_213 ;
}
V_214 = V_188 ;
V_168 = & V_214 ;
if ( V_173 ) {
F_133 ( V_173 ) ;
F_132 ( & V_188 ) ;
}
return V_180 ;
}
static T_8
F_144 ( T_18 * V_163 )
{
switch ( V_141 ) {
case V_142 :
return F_163 ( V_153 , V_163 -> V_215 , F_3 () ) ;
case V_144 :
if ( V_95 )
F_164 ( stdout , V_163 -> V_215 ) ;
else
F_165 ( & V_163 -> V_151 , stdout ) ;
return ! ferror ( stdout ) ;
case V_145 :
F_166 ( V_119 , stdout ) ;
return ! ferror ( stdout ) ;
default:
F_22 () ;
return FALSE ;
}
}
static char *
F_167 ( T_33 V_216 )
{
static char * V_217 = NULL ;
static T_33 V_218 = 256 ;
T_33 V_219 ;
for ( V_219 = V_218 ; V_216 > V_219 ;
V_219 *= 2 )
;
if ( V_217 == NULL ) {
V_218 = V_219 ;
V_217 = ( char * ) F_142 ( V_218 + 1 ) ;
} else {
if ( V_219 > V_218 ) {
V_218 = V_219 ;
V_217 = ( char * ) F_168 ( V_217 , V_218 + 1 ) ;
}
}
return V_217 ;
}
static inline void
F_169 ( char * V_220 , const char * V_53 , T_33 V_221 )
{
memcpy ( V_220 , V_53 , V_221 ) ;
V_220 [ V_221 ] = '\0' ;
}
static inline void
F_170 ( char * V_220 , const char * V_53 , T_33 V_221 , T_33 V_222 )
{
T_33 V_33 ;
for ( V_33 = V_221 ; V_33 < V_222 ; V_33 ++ )
* V_220 ++ = ' ' ;
F_169 ( V_220 , V_53 , V_221 ) ;
}
static inline void
F_171 ( char * V_220 , const char * V_53 , T_33 V_221 , T_33 V_222 )
{
T_33 V_33 ;
memcpy ( V_220 , V_53 , V_221 ) ;
for ( V_33 = V_221 ; V_33 < V_222 ; V_33 ++ )
V_220 [ V_33 ] = ' ' ;
V_220 [ V_222 ] = '\0' ;
}
static T_8
F_172 ( T_18 * V_163 )
{
char * V_217 ;
int V_33 ;
T_33 V_223 ;
T_33 V_224 ;
T_33 V_225 ;
T_34 * V_226 ;
V_217 = F_167 ( 256 ) ;
V_223 = 0 ;
* V_217 = '\0' ;
for ( V_33 = 0 ; V_33 < V_163 -> V_151 . V_152 ; V_33 ++ ) {
V_226 = & V_163 -> V_151 . V_227 [ V_33 ] ;
if ( ! F_173 ( V_33 ) )
continue;
switch ( V_226 -> V_228 ) {
case V_229 :
V_224 = V_225 = strlen ( V_226 -> V_230 ) ;
if ( V_224 < 3 )
V_224 = 3 ;
V_217 = F_167 ( V_223 + V_224 ) ;
F_170 ( V_217 + V_223 , V_226 -> V_230 , V_225 , V_224 ) ;
break;
case V_231 :
case V_232 :
case V_233 :
case V_234 :
case V_235 :
case V_236 :
case V_237 :
case V_238 :
V_224 = V_225 = strlen ( V_226 -> V_230 ) ;
if ( V_224 < 10 )
V_224 = 10 ;
V_217 = F_167 ( V_223 + V_224 ) ;
F_170 ( V_217 + V_223 , V_226 -> V_230 , V_225 , V_224 ) ;
break;
case V_239 :
case V_240 :
case V_241 :
case V_242 :
case V_243 :
case V_244 :
case V_245 :
case V_246 :
case V_247 :
V_224 = V_225 = strlen ( V_226 -> V_230 ) ;
if ( V_224 < 12 )
V_224 = 12 ;
V_217 = F_167 ( V_223 + V_224 ) ;
F_170 ( V_217 + V_223 , V_226 -> V_230 , V_225 , V_224 ) ;
break;
case V_248 :
case V_249 :
case V_250 :
case V_251 :
case V_252 :
case V_253 :
case V_254 :
case V_255 :
case V_256 :
V_224 = V_225 = strlen ( V_226 -> V_230 ) ;
if ( V_224 < 12 )
V_224 = 12 ;
V_217 = F_167 ( V_223 + V_224 ) ;
F_171 ( V_217 + V_223 , V_226 -> V_230 , V_225 , V_224 ) ;
break;
default:
V_224 = strlen ( V_226 -> V_230 ) ;
V_217 = F_167 ( V_223 + V_224 ) ;
F_169 ( V_217 + V_223 , V_226 -> V_230 , V_224 ) ;
break;
}
V_223 += V_224 ;
if ( V_33 != V_163 -> V_151 . V_152 - 1 ) {
V_217 = F_167 ( V_223 + 4 ) ;
switch ( V_226 -> V_228 ) {
case V_239 :
case V_240 :
case V_241 :
switch ( V_163 -> V_151 . V_227 [ V_33 + 1 ] . V_228 ) {
case V_248 :
case V_249 :
case V_250 :
F_169 ( V_217 + V_223 , L_176 , 4 ) ;
V_223 += 4 ;
break;
default:
F_169 ( V_217 + V_223 , L_177 , 1 ) ;
V_223 += 1 ;
break;
}
break;
case V_242 :
case V_243 :
case V_244 :
switch ( V_163 -> V_151 . V_227 [ V_33 + 1 ] . V_228 ) {
case V_251 :
case V_252 :
case V_253 :
F_169 ( V_217 + V_223 , L_176 , 4 ) ;
V_223 += 4 ;
break;
default:
F_169 ( V_217 + V_223 , L_177 , 1 ) ;
V_223 += 1 ;
break;
}
break;
case V_245 :
case V_246 :
case V_247 :
switch ( V_163 -> V_151 . V_227 [ V_33 + 1 ] . V_228 ) {
case V_254 :
case V_255 :
case V_256 :
F_169 ( V_217 + V_223 , L_176 , 4 ) ;
V_223 += 4 ;
break;
default:
F_169 ( V_217 + V_223 , L_177 , 1 ) ;
V_223 += 1 ;
break;
}
break;
case V_248 :
case V_249 :
case V_250 :
switch ( V_163 -> V_151 . V_227 [ V_33 + 1 ] . V_228 ) {
case V_239 :
case V_240 :
case V_241 :
F_169 ( V_217 + V_223 , L_178 , 4 ) ;
V_223 += 4 ;
break;
default:
F_169 ( V_217 + V_223 , L_177 , 1 ) ;
V_223 += 1 ;
break;
}
break;
case V_251 :
case V_252 :
case V_253 :
switch ( V_163 -> V_151 . V_227 [ V_33 + 1 ] . V_228 ) {
case V_242 :
case V_243 :
case V_244 :
F_169 ( V_217 + V_223 , L_178 , 4 ) ;
V_223 += 4 ;
break;
default:
F_169 ( V_217 + V_223 , L_177 , 1 ) ;
V_223 += 1 ;
break;
}
break;
case V_254 :
case V_255 :
case V_256 :
switch ( V_163 -> V_151 . V_227 [ V_33 + 1 ] . V_228 ) {
case V_245 :
case V_246 :
case V_247 :
F_169 ( V_217 + V_223 , L_178 , 4 ) ;
V_223 += 4 ;
break;
default:
F_169 ( V_217 + V_223 , L_177 , 1 ) ;
V_223 += 1 ;
break;
}
break;
default:
F_169 ( V_217 + V_223 , L_177 , 1 ) ;
V_223 += 1 ;
break;
}
}
}
return F_174 ( V_153 , 0 , V_217 ) ;
}
static T_8
F_138 ( T_18 * V_163 , T_22 * V_173 )
{
T_35 V_257 ;
if ( V_98 || F_161 ( V_119 ) ) {
F_175 ( V_173 , FALSE , TRUE ) ;
if ( V_98 ) {
switch ( V_141 ) {
case V_142 :
if ( ! F_172 ( V_163 ) )
return FALSE ;
break;
case V_144 :
F_176 ( V_173 , stdout ) ;
return ! ferror ( stdout ) ;
case V_145 :
F_22 () ;
break;
}
}
}
if ( V_95 ) {
switch ( V_141 ) {
case V_142 :
V_257 . V_97 = V_97 ;
V_257 . V_258 = V_95 ? V_259 : V_260 ;
if ( ! F_177 ( & V_257 , V_173 , V_148 , V_153 ) )
return FALSE ;
if ( ! V_97 ) {
if ( ! F_174 ( V_153 , 0 , V_131 ) )
return FALSE ;
}
break;
case V_144 :
F_178 ( V_173 , stdout ) ;
printf ( L_1 ) ;
return ! ferror ( stdout ) ;
case V_145 :
F_179 ( V_119 , V_173 , & V_163 -> V_151 , stdout ) ;
printf ( L_1 ) ;
return ! ferror ( stdout ) ;
}
}
if ( V_97 ) {
if ( V_98 || V_95 ) {
if ( ! F_174 ( V_153 , 0 , L_80 ) )
return FALSE ;
}
if ( ! F_180 ( V_153 , V_173 ) )
return FALSE ;
if ( ! F_174 ( V_153 , 0 , V_131 ) )
return FALSE ;
}
return TRUE ;
}
static T_8
F_159 ( void )
{
switch ( V_141 ) {
case V_142 :
return F_181 ( V_153 ) ;
case V_144 :
if ( V_95 )
F_182 ( stdout ) ;
else
F_183 ( stdout ) ;
return ! ferror ( stdout ) ;
case V_145 :
F_184 ( V_119 , stdout ) ;
return ! ferror ( stdout ) ;
default:
F_22 () ;
return FALSE ;
}
}
T_36
F_108 ( T_18 * V_163 , const char * V_261 , unsigned int type , T_8 V_262 , int * V_76 )
{
T_3 * T_29 ;
char V_84 [ 2048 + 1 ] ;
F_115 ( V_163 -> V_160 ) ;
V_163 -> V_160 = F_120 ( V_163 ) ;
V_163 -> V_198 = NULL ;
V_163 -> V_263 = 0 ;
V_163 -> V_215 = F_17 ( V_261 ) ;
V_163 -> V_262 = V_262 ;
V_163 -> V_264 = FALSE ;
V_163 -> V_265 = 0 ;
V_163 -> V_266 = type ;
V_163 -> V_181 = 0 ;
V_163 -> V_267 = FALSE ;
V_163 -> V_268 = 0 ;
V_163 -> V_269 = 0 ;
if ( V_163 -> V_269 == 0 ) {
V_163 -> V_270 = FALSE ;
V_163 -> V_269 = 0 ;
} else
V_163 -> V_270 = TRUE ;
F_185 ( & V_163 -> V_183 ) ;
V_164 = NULL ;
V_167 = NULL ;
V_168 = NULL ;
V_163 -> V_271 = V_272 ;
return V_156 ;
F_186 ( V_84 , sizeof V_84 ,
F_187 ( * V_76 , T_29 , FALSE , V_163 -> V_265 ) , V_261 ) ;
F_18 ( L_82 , V_84 ) ;
return V_273 ;
}
static void
F_139 ( int V_76 )
{
switch ( V_76 ) {
case V_274 :
F_18 ( L_179
L_180 ) ;
break;
#ifdef F_188
case F_188 :
F_18 ( L_181
L_182 ) ;
break;
#endif
default:
F_18 ( L_183 ,
F_77 ( V_76 ) ) ;
break;
}
}
static const char *
F_187 ( int V_76 , T_3 * T_29 V_6 , T_8 V_275 ,
int T_37 V_6 )
{
const char * V_276 ;
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
V_276 = F_189 ( V_76 , V_275 ) ;
return V_276 ;
}
static void
V_108 ( const char * V_215 , int V_76 , T_8 V_275 )
{
fprintf ( V_35 , L_184 ) ;
fprintf ( V_35 , F_189 ( V_76 , V_275 ) , V_215 ) ;
fprintf ( V_35 , L_1 ) ;
}
static void
V_90 ( const char * V_277 , T_38 V_278 )
{
fprintf ( V_35 , L_184 ) ;
vfprintf ( V_35 , V_277 , V_278 ) ;
fprintf ( V_35 , L_1 ) ;
}
static void
V_109 ( const char * V_215 , int V_76 )
{
F_18 ( L_185 ,
V_215 , F_77 ( V_76 ) ) ;
}
static void
V_110 ( const char * V_215 , int V_76 )
{
F_18 ( L_186 ,
V_215 , F_77 ( V_76 ) ) ;
}
static void
V_91 ( const char * V_277 , T_38 V_278 )
{
vfprintf ( V_35 , V_277 , V_278 ) ;
fprintf ( V_35 , L_1 ) ;
}
