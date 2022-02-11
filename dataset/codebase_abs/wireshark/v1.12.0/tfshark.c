static void
F_1 ( T_1 V_1 )
{
T_2 * V_2 ;
if ( V_1 ) {
V_2 = stdout ;
fprintf ( V_2 ,
L_1 V_3 L_2
L_3
L_4
L_5
L_6 ,
V_4 , F_2 () ) ;
} else {
V_2 = V_5 ;
}
fprintf ( V_2 , L_5 ) ;
fprintf ( V_2 , L_7 ) ;
fprintf ( V_2 , L_5 ) ;
fprintf ( V_2 , L_8 ) ;
fprintf ( V_2 , L_9 ) ;
fprintf ( V_2 , L_5 ) ;
fprintf ( V_2 , L_10 ) ;
fprintf ( V_2 , L_11 ) ;
fprintf ( V_2 , L_12 ) ;
fprintf ( V_2 , L_13 ) ;
fprintf ( V_2 , L_14 ) ;
fprintf ( V_2 , L_15 , V_6 ) ;
fprintf ( V_2 , L_16 ) ;
fprintf ( V_2 , L_17 ) ;
fprintf ( V_2 , L_18 ) ;
fprintf ( V_2 , L_19 ) ;
fprintf ( V_2 , L_20 ) ;
fprintf ( V_2 , L_21 ) ;
fprintf ( V_2 , L_22 ) ;
fprintf ( V_2 , L_23 ) ;
fprintf ( V_2 , L_24 ) ;
fprintf ( V_2 , L_25 ) ;
fprintf ( V_2 , L_26 ) ;
fprintf ( V_2 , L_27 ) ;
fprintf ( V_2 , L_28 ) ;
fprintf ( V_2 , L_29 ) ;
fprintf ( V_2 , L_30 ) ;
fprintf ( V_2 , L_31 ) ;
fprintf ( V_2 , L_32 ) ;
fprintf ( V_2 , L_33 ) ;
fprintf ( V_2 , L_34 ) ;
fprintf ( V_2 , L_35 ) ;
fprintf ( V_2 , L_36 ) ;
fprintf ( V_2 , L_37 ) ;
fprintf ( V_2 , L_38 ) ;
fprintf ( V_2 , L_39 ) ;
fprintf ( V_2 , L_40 ) ;
fprintf ( V_2 , L_41 ) ;
fprintf ( V_2 , L_42 ) ;
fprintf ( V_2 , L_43 ) ;
fprintf ( V_2 , L_5 ) ;
fprintf ( V_2 , L_44 ) ;
fprintf ( V_2 , L_45 ) ;
fprintf ( V_2 , L_46 ) ;
fprintf ( V_2 , L_47 ) ;
fprintf ( V_2 , L_48 ) ;
fprintf ( V_2 , L_49 ) ;
fprintf ( V_2 , L_50 ) ;
fprintf ( V_2 , L_51 ) ;
}
static void
F_3 ( void )
{
T_2 * V_2 ;
V_2 = stdout ;
fprintf ( V_2 , L_1 V_3 L_2 , V_4 ) ;
fprintf ( V_2 , L_5 ) ;
fprintf ( V_2 , L_52 ) ;
fprintf ( V_2 , L_5 ) ;
fprintf ( V_2 , L_53 ) ;
fprintf ( V_2 , L_54 ) ;
fprintf ( V_2 , L_55 ) ;
fprintf ( V_2 , L_56 ) ;
fprintf ( V_2 , L_57 ) ;
fprintf ( V_2 , L_58 ) ;
fprintf ( V_2 , L_59 ) ;
fprintf ( V_2 , L_60 ) ;
fprintf ( V_2 , L_61 ) ;
fprintf ( V_2 , L_5 ) ;
fprintf ( V_2 , L_62 ) ;
fprintf ( V_2 , L_63 ) ;
fprintf ( V_2 , L_64 ) ;
fprintf ( V_2 , L_5 ) ;
}
static void
F_4 ( const char * V_7 , const char * V_8 ,
T_3 V_2 )
{
if ( ( V_9 == NULL ) ||
( strcmp ( V_9 , V_7 ) != 0 ) ) {
fprintf ( ( T_2 * ) V_2 , L_65 , V_7 , V_8 ) ;
V_9 = V_7 ;
}
}
static void
F_5 ( const T_4 * T_5 V_10 , T_3 V_11 , T_3 V_2 )
{
int V_12 ;
const T_4 * V_13 ;
const T_4 * V_14 ;
V_12 = F_6 ( ( V_15 ) V_11 ) ;
if ( V_12 != - 1 ) {
V_13 = F_7 ( V_12 ) ;
V_14 = F_8 ( V_12 ) ;
F_9 ( V_13 != NULL ) ;
F_9 ( V_14 != NULL ) ;
if ( ( V_9 == NULL ) ||
( strcmp ( V_9 , V_13 ) != 0 ) ) {
fprintf ( ( T_2 * ) V_2 , L_65 ,
V_13 ,
V_14 ) ;
V_9 = V_13 ;
}
}
}
static void
F_10 ( const T_4 * T_5 V_10 , T_3 V_11 , T_3 V_16 )
{
int V_12 ;
const T_4 * V_17 ;
T_6 V_18 ;
F_9 ( V_11 ) ;
V_18 = ( T_6 ) V_16 ;
V_12 = F_6 ( ( V_15 ) V_11 ) ;
if ( V_12 != - 1 ) {
V_17 = F_7 ( V_12 ) ;
F_9 ( V_17 != NULL ) ;
if ( strcmp ( V_17 , V_18 -> V_19 ) == 0 ) {
if ( V_18 -> V_20 == 0 ) {
V_18 -> V_21 = ( V_15 ) V_11 ;
}
V_18 -> V_20 ++ ;
}
}
}
static T_7
F_11 ( T_8 V_22 , T_8 V_23 )
{
return strcmp ( ( const char * ) V_22 , ( const char * ) V_23 ) ;
}
static void
F_12 ( T_2 * V_2 )
{
V_9 = NULL ;
F_13 ( F_4 , ( T_3 ) V_2 , ( V_24 ) F_11 ) ;
}
static void
F_14 ( T_2 * V_2 , T_4 * V_7 )
{
V_9 = NULL ;
F_15 ( V_7 ,
F_5 ,
( T_3 ) V_2 ) ;
}
static T_1
F_16 ( const T_4 * V_25 )
{
T_4 * V_7 ;
T_9 V_26 , V_27 ;
T_4 * V_28 ;
T_4 * V_29 ;
T_4 * V_30 ;
T_4 * V_31 ;
V_15 V_32 ;
T_10 V_33 ;
T_11 V_34 ;
struct V_35 V_36 ;
T_12 V_37 ;
char V_38 ;
F_9 ( V_25 ) ;
V_28 = F_17 ( V_25 ) ;
F_9 ( V_28 ) ;
V_7 = V_28 ;
V_29 = strchr ( V_7 , '=' ) ;
if ( V_29 == NULL ) {
F_18 ( L_66 , V_25 , V_6 ) ;
}
else {
* V_29 = '\0' ;
}
while ( V_7 [ 0 ] == ' ' )
V_7 ++ ;
while ( V_7 [ strlen ( V_7 ) - 1 ] == ' ' )
V_7 [ strlen ( V_7 ) - 1 ] = '\0' ;
V_33 = NULL ;
if ( ! ( * ( V_7 ) ) ) {
F_18 ( L_67 ) ;
}
else {
V_33 = F_19 ( V_7 ) ;
if ( ! V_33 ) {
F_18 ( L_68 , V_7 ) ;
}
}
if ( ! V_33 ) {
F_18 ( L_69 ) ;
F_12 ( V_5 ) ;
}
if ( V_29 == NULL || ! V_33 ) {
F_20 ( V_28 ) ;
return FALSE ;
}
if ( * ( V_29 + 1 ) != '=' ) {
F_18 ( L_70 , V_7 , V_29 + 1 ) ;
}
else {
V_29 ++ ;
* V_29 = '\0' ;
}
V_29 ++ ;
V_30 = V_29 ;
V_29 = strchr ( V_30 , ',' ) ;
if ( V_29 == NULL ) {
F_18 ( L_66 , V_25 , V_6 ) ;
}
else {
* V_29 = '\0' ;
}
V_34 = F_21 ( V_7 ) ;
switch ( V_34 ) {
case V_39 :
case V_40 :
case V_41 :
case V_42 :
switch ( sscanf ( V_30 , L_71 , & V_26 , & V_38 , & V_27 ) ) {
case 1 :
V_38 = '\0' ;
break;
case 3 :
if ( V_38 != ':' && V_38 != '-' ) {
F_18 ( L_72 , V_30 ) ;
F_20 ( V_28 ) ;
return FALSE ;
}
if ( V_38 == ':' ) {
if ( ( V_27 == 0 ) || ( ( T_12 ) V_26 + V_27 - 1 ) > V_43 ) {
F_18 ( L_72 , V_30 ) ;
F_20 ( V_28 ) ;
return FALSE ;
}
}
else if ( V_27 < V_26 ) {
F_18 ( L_72 , V_30 ) ;
F_20 ( V_28 ) ;
return FALSE ;
}
break;
default:
F_18 ( L_73 , V_30 ) ;
F_20 ( V_28 ) ;
return FALSE ;
}
break;
case V_44 :
case V_45 :
case V_46 :
case V_47 :
break;
default:
F_22 () ;
}
if ( V_29 == NULL ) {
F_18 ( L_74 , V_7 ) ;
F_14 ( V_5 , V_7 ) ;
F_20 ( V_28 ) ;
return FALSE ;
}
V_29 ++ ;
V_31 = V_29 ;
while ( V_31 [ 0 ] == ' ' )
V_31 ++ ;
while ( V_31 [ strlen ( V_31 ) - 1 ] == ' ' )
V_31 [ strlen ( V_31 ) - 1 ] = '\0' ;
V_32 = NULL ;
if ( ! ( * V_31 ) ) {
F_18 ( L_75 ) ;
}
else {
V_36 . V_20 = 0 ;
V_36 . V_19 = V_31 ;
V_36 . V_21 = NULL ;
F_15 ( V_7 , F_10 , & V_36 ) ;
if ( V_36 . V_20 != 0 ) {
V_32 = V_36 . V_21 ;
if ( V_36 . V_20 > 1 ) {
F_18 ( L_76 , V_31 , V_36 . V_20 ) ;
}
}
else {
if ( F_23 ( V_31 ) == - 1 ) {
F_18 ( L_77 , V_31 ) ;
} else {
F_18 ( L_78 ,
V_31 , V_7 ) ;
}
}
}
if ( ! V_32 ) {
F_18 ( L_74 , V_7 ) ;
F_14 ( V_5 , V_7 ) ;
F_20 ( V_28 ) ;
return FALSE ;
}
switch ( V_34 ) {
case V_39 :
case V_40 :
case V_41 :
case V_42 :
if ( V_38 == '\0' ) {
F_24 ( V_7 , V_26 , V_32 ) ;
} else if ( V_38 == ':' ) {
for ( V_37 = V_26 ; V_37 < ( T_12 ) V_26 + V_27 ; V_37 ++ ) {
F_24 ( V_7 , ( T_9 ) V_37 , V_32 ) ;
}
} else {
for ( V_37 = V_26 ; V_37 <= V_27 ; V_37 ++ ) {
F_24 ( V_7 , ( T_9 ) V_37 , V_32 ) ;
}
}
break;
case V_44 :
case V_45 :
case V_46 :
case V_47 :
F_25 ( V_7 , V_30 , V_32 ) ;
break;
default:
F_22 () ;
}
F_20 ( V_28 ) ;
return TRUE ;
}
static void
F_26 ( const T_4 * V_48 , T_13 V_49 ,
const T_4 * V_50 , T_3 V_16 )
{
if ( ( V_49 & V_51 & V_52 . V_53 ) == 0 &&
V_52 . V_53 != 0 ) {
return;
}
F_27 ( V_48 , V_49 , V_50 , V_16 ) ;
}
static void
F_28 ( void ) {
T_4 * V_54 , * V_55 ;
if ( F_29 () ) {
V_54 = F_30 () ;
V_55 = F_31 () ;
fprintf ( V_5 , L_79 ,
V_54 , V_55 ) ;
F_20 ( V_54 ) ;
F_20 ( V_55 ) ;
if ( F_32 () ) {
fprintf ( V_5 , L_80 ) ;
}
fprintf ( V_5 , L_5 ) ;
}
}
static void
F_33 ( T_14 * V_56 , T_14 * V_57 )
{
printf ( L_1 V_3 L_2
L_5
L_6
L_5
L_6
L_5
L_6 ,
V_4 , F_2 () , V_56 -> V_58 ,
V_57 -> V_58 ) ;
}
int
main ( int V_59 , char * V_60 [] )
{
T_14 * V_56 ;
T_14 * V_57 ;
char * V_61 ;
int V_62 ;
T_1 V_63 = FALSE ;
char * V_64 , * V_65 ;
char * V_66 , * V_67 ;
int V_68 , V_69 ;
int V_70 , V_71 ;
int V_72 , V_73 ;
int V_74 , V_75 ;
int V_76 ;
volatile int V_77 = 0 ;
T_1 V_78 = FALSE ;
T_4 * volatile V_79 = NULL ;
T_4 * V_80 = NULL ;
T_4 * V_81 = NULL ;
T_15 * V_82 = NULL ;
T_15 * V_83 = NULL ;
T_16 * V_84 ;
int V_85 ;
int V_86 ;
T_4 * V_87 = NULL ;
#define F_34 "-2C:d:e:E:hK:lo:O:qQr:R:S:t:T:u:vVxX:Y:z:"
static const char V_88 [] = F_34 ;
V_56 = F_35 ( L_81 ) ;
F_36 ( V_56 , NULL , V_89 ) ;
V_57 = F_35 ( L_82 ) ;
F_37 ( V_57 , NULL ) ;
F_38 ( L_1 V_3 L_2
L_5
L_6
L_5
L_6 ,
V_4 , V_56 -> V_58 , V_57 -> V_58 ) ;
#ifdef F_39
F_40 ( V_59 , V_60 ) ;
F_41 () ;
#if ! F_42 ( 2 , 31 , 0 )
F_43 ( NULL ) ;
#endif
#endif
F_44 () ;
V_61 = F_45 ( V_60 [ 0 ] , main ) ;
if ( V_61 != NULL ) {
fprintf ( V_5 , L_83 ,
V_61 ) ;
}
V_90 = 0 ;
V_86 = V_91 ;
while ( ( V_62 = F_46 ( V_59 , V_60 , V_88 ) ) != - 1 ) {
switch ( V_62 ) {
case 'C' :
if ( F_47 ( V_92 , FALSE ) ) {
F_48 ( V_92 ) ;
} else {
F_18 ( L_84 , V_92 ) ;
return 1 ;
}
break;
case 'O' :
V_87 = F_17 ( V_92 ) ;
case 'V' :
V_93 = TRUE ;
V_94 = TRUE ;
break;
case 'x' :
V_95 = TRUE ;
V_94 = TRUE ;
break;
case 'X' :
F_49 ( V_92 ) ;
break;
default:
break;
}
}
if ( V_96 == - 1 )
V_96 = ( V_93 || V_95 ) ? FALSE : TRUE ;
V_91 = V_86 ;
V_90 = 1 ;
V_85 =
V_97 |
V_98 |
V_99 |
V_100 |
V_101 |
V_102 |
V_103 | V_104 ;
F_50 ( NULL ,
( T_13 ) V_85 ,
F_26 , NULL ) ;
F_50 ( V_105 ,
( T_13 ) V_85 ,
F_26 , NULL ) ;
F_51 () ;
F_52 ( V_106 , V_107 , V_108 ,
V_109 ) ;
F_53 ( V_110 ) ;
F_54 ( V_111 ) ;
F_55 ( V_112 ) ;
F_56 () ;
#ifdef F_57
F_58 () ;
F_59 () ;
F_60 () ;
F_61 () ;
#endif
F_62 ( V_113 , V_114 , NULL , NULL ) ;
if ( V_59 >= 2 && strcmp ( V_60 [ 1 ] , L_85 ) == 0 ) {
F_63 () ;
if ( V_59 == 2 )
F_64 () ;
else {
if ( strcmp ( V_60 [ 2 ] , L_86 ) == 0 )
F_65 () ;
else if ( strcmp ( V_60 [ 2 ] , L_87 ) == 0 ) {
F_66 ( & V_68 , & V_69 , & V_64 ,
& V_70 , & V_71 , & V_65 ) ;
F_67 ( NULL ) ;
}
else if ( strcmp ( V_60 [ 2 ] , L_88 ) == 0 )
F_68 () ;
else if ( strcmp ( V_60 [ 2 ] , L_89 ) == 0 )
F_67 ( NULL ) ;
else if ( strcmp ( V_60 [ 2 ] , L_90 ) == 0 )
F_64 () ;
else if ( strcmp ( V_60 [ 2 ] , L_91 ) == 0 )
F_69 () ;
else if ( strcmp ( V_60 [ 2 ] , L_92 ) == 0 )
F_70 () ;
else if ( strcmp ( V_60 [ 2 ] , L_93 ) == 0 ) {
#ifdef F_57
F_71 () ;
#endif
#ifdef F_72
F_73 () ;
#endif
}
else if ( strcmp ( V_60 [ 2 ] , L_94 ) == 0 )
F_74 () ;
else if ( strcmp ( V_60 [ 2 ] , L_95 ) == 0 )
F_75 () ;
else if ( strcmp ( V_60 [ 2 ] , L_96 ) == 0 )
F_3 () ;
else if ( strcmp ( V_60 [ 2 ] , L_97 ) == 0 )
F_3 () ;
else {
F_18 ( L_98 , V_60 [ 2 ] ) ;
return 1 ;
}
}
return 0 ;
}
setlocale ( V_115 , L_99 ) ;
V_84 = F_66 ( & V_68 , & V_69 , & V_64 ,
& V_70 , & V_71 , & V_65 ) ;
if ( V_64 != NULL ) {
if ( V_68 != 0 ) {
F_18 ( L_100 ,
V_65 , F_76 ( V_68 ) ) ;
}
if ( V_69 != 0 ) {
F_18 ( L_101 ,
V_65 , F_76 ( V_69 ) ) ;
}
}
if ( V_65 != NULL ) {
if ( V_70 != 0 ) {
F_18 ( L_102 , V_65 ,
F_76 ( V_70 ) ) ;
}
if ( V_71 != 0 ) {
F_18 ( L_103 ,
V_65 , F_76 ( V_71 ) ) ;
}
F_20 ( V_65 ) ;
V_65 = NULL ;
}
F_77 ( & V_66 , & V_72 , & V_73 ,
& V_67 , & V_74 , & V_75 ) ;
if ( V_66 != NULL ) {
if ( V_72 != 0 ) {
F_18 ( L_104 ,
V_66 , F_76 ( V_72 ) ) ;
}
if ( V_73 != 0 ) {
F_18 ( L_105 ,
V_66 , F_76 ( V_73 ) ) ;
}
F_20 ( V_66 ) ;
}
if ( V_67 != NULL ) {
if ( V_74 != 0 ) {
F_18 (
L_106 , V_67 ,
F_76 ( V_74 ) ) ;
}
if ( V_75 != 0 ) {
F_18 (
L_107 , V_67 ,
F_76 ( V_75 ) ) ;
}
F_20 ( V_67 ) ;
}
F_78 ( & V_116 ) ;
V_117 = V_118 ;
V_119 = F_79 () ;
while ( ( V_62 = F_46 ( V_59 , V_60 , V_88 ) ) != - 1 ) {
switch ( V_62 ) {
case '2' :
V_120 = TRUE ;
break;
case 'C' :
break;
case 'd' :
if ( ! F_16 ( V_92 ) )
return 1 ;
break;
#if F_80 ( V_121 ) || F_80 ( V_122 )
case 'K' :
F_81 ( V_92 ) ;
break;
#endif
case 'e' :
F_82 ( V_119 , V_92 ) ;
break;
case 'E' :
if ( ! F_83 ( V_119 , V_92 ) ) {
F_18 ( L_108 , V_92 ) ;
F_84 ( V_5 ) ;
return 1 ;
}
break;
case 'h' :
F_1 ( TRUE ) ;
return 0 ;
break;
case 'l' :
V_123 = TRUE ;
break;
case 'o' :
switch ( F_85 ( V_92 ) ) {
case V_124 :
break;
case V_125 :
F_18 ( L_109 , V_92 ) ;
return 1 ;
break;
case V_126 :
case V_127 :
F_18 ( L_110 , V_92 ) ;
return 1 ;
break;
}
break;
case 'q' :
V_78 = TRUE ;
break;
case 'Q' :
V_78 = TRUE ;
V_128 = TRUE ;
break;
case 'r' :
V_79 = F_17 ( V_92 ) ;
break;
case 'R' :
V_80 = V_92 ;
break;
case 'S' :
V_129 = F_86 ( V_92 ) ;
break;
case 't' :
if ( strcmp ( V_92 , L_111 ) == 0 )
F_53 ( V_110 ) ;
else if ( strcmp ( V_92 , L_112 ) == 0 )
F_53 ( V_130 ) ;
else if ( strcmp ( V_92 , L_113 ) == 0 )
F_53 ( V_131 ) ;
else if ( strcmp ( V_92 , L_114 ) == 0 )
F_53 ( V_132 ) ;
else if ( strcmp ( V_92 , L_115 ) == 0 )
F_53 ( V_133 ) ;
else if ( strcmp ( V_92 , L_116 ) == 0 )
F_53 ( V_134 ) ;
else if ( strcmp ( V_92 , L_117 ) == 0 )
F_53 ( V_135 ) ;
else if ( strcmp ( V_92 , L_118 ) == 0 )
F_53 ( V_136 ) ;
else if ( strcmp ( V_92 , L_119 ) == 0 )
F_53 ( V_137 ) ;
else if ( strcmp ( V_92 , L_120 ) == 0 )
F_53 ( V_138 ) ;
else {
F_18 ( L_121 , V_92 ) ;
F_87 ( L_122
L_123
L_124
L_125
L_126
L_127
L_128
L_129
L_130
L_131 ) ;
return 1 ;
}
break;
case 'T' :
if ( strcmp ( V_92 , L_132 ) == 0 ) {
V_139 = V_140 ;
V_117 = V_118 ;
} else if ( strcmp ( V_92 , L_133 ) == 0 ) {
V_139 = V_140 ;
V_117 = V_141 ;
} else if ( strcmp ( V_92 , L_134 ) == 0 ) {
V_139 = V_142 ;
V_93 = TRUE ;
V_96 = FALSE ;
} else if ( strcmp ( V_92 , L_135 ) == 0 ) {
V_139 = V_142 ;
V_93 = FALSE ;
V_96 = TRUE ;
} else if ( strcmp ( V_92 , L_90 ) == 0 ) {
V_139 = V_143 ;
V_93 = TRUE ;
V_96 = FALSE ;
} else {
F_18 ( L_136 , V_92 ) ;
F_87 ( L_137
L_138
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
L_152 ) ;
return 1 ;
}
break;
case 'u' :
if ( strcmp ( V_92 , L_153 ) == 0 )
F_55 ( V_112 ) ;
else if ( strcmp ( V_92 , L_154 ) == 0 )
F_55 ( V_144 ) ;
else {
F_18 ( L_155 , V_92 ) ;
F_87 ( L_156
L_157 ) ;
return 1 ;
}
break;
case 'v' :
{
F_33 ( V_56 , V_57 ) ;
F_88 ( V_56 , TRUE ) ;
F_88 ( V_57 , TRUE ) ;
F_89 () ;
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
V_81 = V_92 ;
break;
case 'z' :
if ( ! F_90 ( V_92 ) ) {
if ( strcmp ( L_158 , V_92 ) == 0 ) {
fprintf ( V_5 , L_159 ) ;
F_91 () ;
return 0 ;
}
F_18 ( L_160 , V_92 ) ;
F_91 () ;
return 1 ;
}
break;
default:
case '?' :
F_1 ( TRUE ) ;
return 1 ;
break;
}
}
if ( V_143 != V_139 && 0 != F_92 ( V_119 ) ) {
F_18 ( L_161
L_162 ) ;
return 1 ;
} else if ( V_143 == V_139 && 0 == F_92 ( V_119 ) ) {
F_18 ( L_163
L_164 ) ;
return 1 ;
}
if ( V_91 < V_59 ) {
if ( V_79 != NULL ) {
if ( V_81 != NULL ) {
F_18 ( L_165
L_166 ) ;
return 1 ;
}
V_81 = F_93 ( V_59 , V_60 , V_91 ) ;
}
}
if ( ! V_78 )
V_94 = TRUE ;
if ( V_63 ) {
F_1 ( FALSE ) ;
return 1 ;
}
if ( V_95 ) {
if ( V_139 != V_140 ) {
F_18 ( L_167 ) ;
return 1 ;
}
}
if ( V_87 != NULL ) {
char * V_145 ;
if ( ! V_93 ) {
F_18 ( L_168 ) ;
return 1 ;
}
V_146 = F_94 ( V_147 , V_148 ) ;
for ( V_145 = strtok ( V_87 , L_169 ) ; V_145 ; V_145 = strtok ( NULL , L_169 ) ) {
F_95 ( V_146 , ( T_3 ) V_145 , ( T_3 ) V_145 ) ;
}
}
if ( V_80 != NULL && ! V_120 ) {
F_18 ( L_170 ) ;
return 1 ;
}
F_96 () ;
F_97 () ;
if ( V_66 == NULL && V_67 == NULL ) {
F_98 () ;
}
F_99 ( & V_116 . V_149 , V_84 -> V_150 , TRUE ) ;
if ( V_80 != NULL ) {
if ( ! F_100 ( V_80 , & V_82 ) ) {
F_18 ( L_6 , V_151 ) ;
F_89 () ;
return 2 ;
}
}
V_116 . V_82 = V_82 ;
if ( V_81 != NULL ) {
if ( ! F_100 ( V_81 , & V_83 ) ) {
F_18 ( L_6 , V_151 ) ;
F_89 () ;
return 2 ;
}
}
V_116 . V_83 = V_83 ;
if ( V_94 ) {
if ( V_139 == V_140 ) {
switch ( V_117 ) {
case V_118 :
V_152 = F_101 ( stdout ) ;
break;
case V_141 :
V_152 = F_102 ( stdout ) ;
break;
default:
F_22 () ;
}
}
}
V_153 = V_94 || V_82 || V_83 || F_103 () ;
if ( V_79 ) {
F_104 () ;
F_28 () ;
if ( F_105 ( & V_116 , V_79 , V_154 , FALSE , & V_76 ) != V_155 ) {
F_89 () ;
return 2 ;
}
F_106 {
V_76 = F_107 ( & V_116 , 1 , 0 ) ;
}
F_108 (OutOfMemoryError) {
fprintf ( V_5 ,
L_171
L_5
L_172
L_5
L_173
L_174 ) ;
V_76 = V_156 ;
}
V_157 ;
if ( V_76 != 0 ) {
V_77 = 2 ;
}
}
F_20 ( V_79 ) ;
if ( V_116 . V_158 != NULL ) {
F_109 ( V_116 . V_158 ) ;
V_116 . V_158 = NULL ;
}
F_110 ( TRUE ) ;
F_111 () ;
F_112 ( V_116 . V_159 ) ;
F_89 () ;
F_113 ( V_119 ) ;
V_119 = NULL ;
return V_77 ;
}
static const T_17 *
F_114 ( void * V_160 , T_9 V_161 )
{
T_18 * V_162 = ( T_18 * ) V_160 ;
if ( V_163 && V_163 -> V_164 == V_161 )
return & V_163 -> V_165 ;
if ( V_166 && V_166 -> V_164 == V_161 )
return & V_166 -> V_165 ;
if ( V_167 && V_167 -> V_164 == V_161 )
return & V_167 -> V_165 ;
if ( V_162 -> V_158 ) {
T_19 * V_168 = F_115 ( V_162 -> V_158 , V_161 ) ;
return ( V_168 ) ? & V_168 -> V_165 : NULL ;
}
return NULL ;
}
static const char *
F_116 ( void * V_160 V_10 , T_9 T_20 V_10 )
{
return L_99 ;
}
static T_21 *
F_117 ( T_18 * V_162 )
{
T_21 * V_159 = F_118 () ;
V_159 -> V_160 = V_162 ;
V_159 -> V_169 = F_114 ;
V_159 -> V_170 = F_116 ;
V_159 -> V_171 = NULL ;
return V_159 ;
}
static T_1
F_119 ( T_18 * V_162 , T_22 * V_172 ,
T_23 V_173 , struct V_174 * V_175 ,
const T_24 * V_176 )
{
T_19 V_177 ;
T_9 V_178 ;
T_1 V_179 ;
V_178 = V_162 -> V_180 + 1 ;
V_179 = TRUE ;
F_120 ( & V_177 , V_178 , V_175 , V_173 , V_181 ) ;
if ( V_172 ) {
if ( V_162 -> V_82 )
F_121 ( V_172 , V_162 -> V_82 ) ;
F_122 ( & V_177 , & V_162 -> V_182 ,
& V_163 , V_166 ) ;
if ( V_163 == & V_177 ) {
V_183 = V_177 ;
V_163 = & V_183 ;
}
F_123 ( V_172 , V_175 , F_124 ( & V_177 , V_176 ) , & V_177 , NULL ) ;
if ( V_162 -> V_82 )
V_179 = F_125 ( V_162 -> V_82 , V_172 ) ;
}
if ( V_179 ) {
F_126 ( & V_177 , & V_181 ) ;
V_167 = V_166 = F_127 ( V_162 -> V_158 , & V_177 ) ;
if ( V_172 ) {
F_128 ( V_172 -> V_184 . V_185 , V_186 , V_162 -> V_158 ) ;
}
V_162 -> V_180 ++ ;
} else {
F_129 ( & V_177 ) ;
}
if ( V_172 )
F_130 ( V_172 ) ;
return V_179 ;
}
static T_1
F_131 ( T_18 * V_162 , T_22 * V_172 , T_19 * V_187 ,
struct V_174 * V_188 , T_25 * V_189 ,
T_26 V_190 )
{
T_27 * V_149 ;
T_1 V_179 ;
V_179 = TRUE ;
if ( V_172 ) {
if ( V_162 -> V_83 )
F_121 ( V_172 , V_162 -> V_83 ) ;
F_132 ( V_172 , & V_162 -> V_149 ) ;
if ( ( V_190 & V_191 ) || ( V_94 && V_96 ) )
V_149 = & V_162 -> V_149 ;
else
V_149 = NULL ;
F_122 ( V_187 , & V_162 -> V_182 ,
& V_163 , V_166 ) ;
if ( V_163 == V_187 ) {
V_183 = * V_187 ;
V_163 = & V_183 ;
}
F_133 ( V_172 , V_188 , F_134 ( V_187 , V_189 ) , V_187 , V_149 ) ;
if ( V_162 -> V_83 )
V_179 = F_125 ( V_162 -> V_83 , V_172 ) ;
}
if ( V_179 ) {
F_126 ( V_187 , & V_181 ) ;
if ( V_94 ) {
F_135 ( V_162 , V_172 ) ;
if ( V_123 )
fflush ( stdout ) ;
if ( ferror ( stdout ) ) {
F_136 ( V_192 ) ;
exit ( 2 ) ;
}
}
V_166 = V_187 ;
}
V_167 = V_187 ;
if ( V_172 ) {
F_130 ( V_172 ) ;
}
return V_179 || V_187 -> V_193 . V_194 ;
}
T_1
F_137 ( T_18 * V_162 , struct V_174 * V_195 , int * V_76 , T_4 * * V_196 , T_23 * T_28 V_10 , T_29 * * V_197 )
{
int V_198 ;
T_23 V_199 = F_138 ( V_162 -> V_200 , V_76 ) ;
* V_197 = ( T_29 * ) F_139 ( ( V_201 ) V_199 ) ;
V_198 = F_140 ( * V_197 , ( unsigned int ) V_199 , V_162 -> V_200 -> V_202 ) ;
if ( V_198 < 0 ) {
* V_76 = F_141 ( V_162 -> V_200 -> V_202 , V_196 ) ;
if ( * V_76 == 0 )
* V_76 = V_203 ;
return FALSE ;
} else if ( V_198 == 0 ) {
return FALSE ;
}
V_195 -> V_204 = ( T_9 ) V_199 ;
V_195 -> V_205 = ( T_9 ) V_199 ;
#if 0
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
F_107 ( T_18 * V_162 , int V_206 , T_23 V_207 )
{
T_9 V_178 ;
int V_76 ;
T_4 * V_196 = NULL ;
T_23 T_28 = 0 ;
T_1 V_208 ;
T_26 V_190 ;
T_25 V_189 ;
T_22 * V_172 = NULL ;
struct V_174 V_195 ;
T_29 * V_209 ;
if ( V_94 ) {
if ( ! F_142 ( V_162 ) ) {
V_76 = V_192 ;
F_136 ( V_76 ) ;
goto V_210;
}
}
V_208 = F_143 () ;
V_190 = F_144 () ;
memset ( & V_195 , 0 , sizeof( V_195 ) ) ;
V_195 . V_211 = 1234 ;
if ( V_120 ) {
T_19 * V_187 ;
V_162 -> V_158 = F_145 () ;
if ( V_153 ) {
T_1 V_212 = FALSE ;
if ( V_162 -> V_82 )
V_212 = TRUE ;
V_172 = F_146 ( V_162 -> V_159 , V_212 , FALSE ) ;
}
while ( F_137 ( V_162 , & V_195 , & V_76 , & V_196 , & T_28 , & V_209 ) ) {
if ( F_119 ( V_162 , V_172 , T_28 , & V_195 ,
F_147 ( V_162 -> V_200 ) ) ) {
if ( ( -- V_206 == 0 ) || ( V_207 != 0 && T_28 >= V_207 ) ) {
V_76 = 0 ;
break;
}
}
}
if ( V_172 ) {
F_148 ( V_172 ) ;
V_172 = NULL ;
}
#if 0
wtap_sequential_close(cf->wth);
#endif
F_149 () ;
V_166 = NULL ;
V_167 = NULL ;
F_150 ( & V_189 , 1500 ) ;
if ( V_153 ) {
T_1 V_212 ;
if ( V_162 -> V_83 || V_93 || V_208 ||
( V_190 & V_213 ) || F_151 ( & V_162 -> V_149 ) )
V_212 = TRUE ;
else
V_212 = FALSE ;
V_172 = F_146 ( V_162 -> V_159 , V_212 , V_94 && V_93 ) ;
}
for ( V_178 = 1 ; V_76 == 0 && V_178 <= V_162 -> V_180 ; V_178 ++ ) {
V_187 = F_115 ( V_162 -> V_158 , V_178 ) ;
#if 0
if (wtap_seek_read(cf->wth, fdata->file_off,
&buf, fdata->cap_len, &err, &err_info)) {
process_packet_second_pass(cf, edt, fdata, &cf->phdr, &buf, tap_flags);
}
#else
F_131 ( V_162 , V_172 , V_187 , & V_162 -> V_188 , & V_189 , V_190 ) ;
#endif
}
if ( V_172 ) {
F_148 ( V_172 ) ;
V_172 = NULL ;
}
F_152 ( & V_189 ) ;
}
else {
V_178 = 0 ;
if ( V_153 ) {
T_1 V_212 ;
if ( V_162 -> V_82 || V_162 -> V_83 || V_93 || V_208 ||
( V_190 & V_213 ) || F_151 ( & V_162 -> V_149 ) )
V_212 = TRUE ;
else
V_212 = FALSE ;
V_172 = F_146 ( V_162 -> V_159 , V_212 , V_94 && V_93 ) ;
}
while ( F_137 ( V_162 , & V_195 , & V_76 , & V_196 , & T_28 , & V_209 ) ) {
V_178 ++ ;
F_153 ( V_162 , V_172 , T_28 , & V_195 ,
V_209 , V_190 ) ;
if ( ( -- V_206 == 0 ) || ( V_207 != 0 && T_28 >= V_207 ) ) {
V_76 = 0 ;
break;
}
}
if ( V_172 ) {
F_148 ( V_172 ) ;
V_172 = NULL ;
}
}
if ( V_76 != 0 ) {
#ifndef F_39
if ( V_94 ) {
struct V_214 V_215 , V_216 ;
if ( F_154 ( 1 , & V_215 ) == 0 && F_154 ( 2 , & V_216 ) == 0 ) {
if ( V_215 . V_217 == V_216 . V_217 &&
V_215 . V_218 == V_216 . V_218 ) {
fflush ( stdout ) ;
fprintf ( V_5 , L_5 ) ;
}
}
}
#endif
switch ( V_76 ) {
case V_219 :
F_18 ( L_175 ,
V_162 -> V_220 , V_196 ) ;
F_20 ( V_196 ) ;
break;
case V_221 :
F_18 ( L_176 ,
V_162 -> V_220 , V_196 ) ;
F_20 ( V_196 ) ;
break;
case V_222 :
F_18 ( L_177 ,
V_162 -> V_220 ) ;
break;
case V_203 :
F_18 ( L_178 ,
V_162 -> V_220 ) ;
break;
case V_223 :
F_18 ( L_179 ,
V_162 -> V_220 , V_196 ) ;
F_20 ( V_196 ) ;
break;
case V_224 :
F_18 ( L_180
L_181 , V_162 -> V_220 , V_196 ) ;
break;
default:
F_18 ( L_182 ,
V_162 -> V_220 , F_155 ( V_76 ) ) ;
break;
}
} else {
if ( V_94 ) {
if ( ! F_156 () ) {
V_76 = V_192 ;
F_136 ( V_76 ) ;
}
}
}
V_210:
F_157 ( V_162 -> V_200 ) ;
V_162 -> V_200 = NULL ;
return V_76 ;
}
static T_1
F_153 ( T_18 * V_162 , T_22 * V_172 , T_23 V_173 ,
struct V_174 * V_175 , const T_24 * V_176 , T_26 V_190 )
{
T_19 V_187 ;
T_27 * V_149 ;
T_1 V_179 ;
V_162 -> V_180 ++ ;
V_179 = TRUE ;
F_120 ( & V_187 , V_162 -> V_180 , V_175 , V_173 , V_181 ) ;
if ( V_172 ) {
if ( V_162 -> V_83 )
F_121 ( V_172 , V_162 -> V_83 ) ;
F_132 ( V_172 , & V_162 -> V_149 ) ;
if ( ( V_190 & V_191 ) || ( V_94 && V_96 ) || F_158 ( V_119 ) )
V_149 = & V_162 -> V_149 ;
else
V_149 = NULL ;
F_122 ( & V_187 , & V_162 -> V_182 ,
& V_163 , V_166 ) ;
if ( V_163 == & V_187 ) {
V_183 = V_187 ;
V_163 = & V_183 ;
}
F_133 ( V_172 , V_175 , F_159 ( & V_187 , V_176 ) , & V_187 , V_149 ) ;
if ( V_162 -> V_83 )
V_179 = F_125 ( V_162 -> V_83 , V_172 ) ;
}
if ( V_179 ) {
F_126 ( & V_187 , & V_181 ) ;
if ( V_94 ) {
F_135 ( V_162 , V_172 ) ;
if ( V_123 )
fflush ( stdout ) ;
if ( ferror ( stdout ) ) {
F_136 ( V_192 ) ;
exit ( 2 ) ;
}
}
V_225 = V_187 ;
V_166 = & V_225 ;
}
V_226 = V_187 ;
V_167 = & V_226 ;
if ( V_172 ) {
F_130 ( V_172 ) ;
F_129 ( & V_187 ) ;
}
return V_179 ;
}
static T_1
F_142 ( T_18 * V_162 )
{
switch ( V_139 ) {
case V_140 :
return F_160 ( V_152 , V_162 ? V_162 -> V_220 : NULL , V_4 ) ;
case V_142 :
if ( V_93 )
F_161 ( stdout , V_162 ? V_162 -> V_220 : NULL ) ;
else
F_162 ( stdout ) ;
return ! ferror ( stdout ) ;
case V_143 :
F_163 ( V_119 , stdout ) ;
return ! ferror ( stdout ) ;
default:
F_22 () ;
return FALSE ;
}
}
static char *
F_164 ( T_30 V_205 )
{
static char * V_227 = NULL ;
static T_30 V_228 = 256 ;
T_30 V_229 ;
for ( V_229 = V_228 ; V_205 > V_229 ;
V_229 *= 2 )
;
if ( V_227 == NULL ) {
V_228 = V_229 ;
V_227 = ( char * ) F_139 ( V_228 + 1 ) ;
} else {
if ( V_229 > V_228 ) {
V_228 = V_229 ;
V_227 = ( char * ) F_165 ( V_227 , V_228 + 1 ) ;
}
}
return V_227 ;
}
static inline void
F_166 ( char * V_230 , const char * V_58 , T_30 V_231 )
{
memcpy ( V_230 , V_58 , V_231 ) ;
V_230 [ V_231 ] = '\0' ;
}
static inline void
F_167 ( char * V_230 , const char * V_58 , T_30 V_231 , T_30 V_232 )
{
T_30 V_37 ;
for ( V_37 = V_231 ; V_37 < V_232 ; V_37 ++ )
* V_230 ++ = ' ' ;
F_166 ( V_230 , V_58 , V_231 ) ;
}
static inline void
F_168 ( char * V_230 , const char * V_58 , T_30 V_231 , T_30 V_232 )
{
T_30 V_37 ;
memcpy ( V_230 , V_58 , V_231 ) ;
for ( V_37 = V_231 ; V_37 < V_232 ; V_37 ++ )
V_230 [ V_37 ] = ' ' ;
V_230 [ V_232 ] = '\0' ;
}
static T_1
F_169 ( T_18 * V_162 )
{
char * V_227 ;
int V_37 ;
T_30 V_233 ;
T_30 V_234 ;
T_30 V_235 ;
V_227 = F_164 ( 256 ) ;
V_233 = 0 ;
* V_227 = '\0' ;
for ( V_37 = 0 ; V_37 < V_162 -> V_149 . V_150 ; V_37 ++ ) {
if ( ! F_170 ( V_37 ) )
continue;
switch ( V_162 -> V_149 . V_236 [ V_37 ] ) {
case V_237 :
V_234 = V_235 = strlen ( V_162 -> V_149 . V_238 [ V_37 ] ) ;
if ( V_234 < 3 )
V_234 = 3 ;
V_227 = F_164 ( V_233 + V_234 ) ;
F_167 ( V_227 + V_233 , V_162 -> V_149 . V_238 [ V_37 ] , V_235 , V_234 ) ;
break;
case V_239 :
case V_240 :
case V_241 :
case V_242 :
case V_243 :
case V_244 :
case V_245 :
case V_246 :
V_234 = V_235 = strlen ( V_162 -> V_149 . V_238 [ V_37 ] ) ;
if ( V_234 < 10 )
V_234 = 10 ;
V_227 = F_164 ( V_233 + V_234 ) ;
F_167 ( V_227 + V_233 , V_162 -> V_149 . V_238 [ V_37 ] , V_235 , V_234 ) ;
break;
case V_247 :
case V_248 :
case V_249 :
case V_250 :
case V_251 :
case V_252 :
case V_253 :
case V_254 :
case V_255 :
V_234 = V_235 = strlen ( V_162 -> V_149 . V_238 [ V_37 ] ) ;
if ( V_234 < 12 )
V_234 = 12 ;
V_227 = F_164 ( V_233 + V_234 ) ;
F_167 ( V_227 + V_233 , V_162 -> V_149 . V_238 [ V_37 ] , V_235 , V_234 ) ;
break;
case V_256 :
case V_257 :
case V_258 :
case V_259 :
case V_260 :
case V_261 :
case V_262 :
case V_263 :
case V_264 :
V_234 = V_235 = strlen ( V_162 -> V_149 . V_238 [ V_37 ] ) ;
if ( V_234 < 12 )
V_234 = 12 ;
V_227 = F_164 ( V_233 + V_234 ) ;
F_168 ( V_227 + V_233 , V_162 -> V_149 . V_238 [ V_37 ] , V_235 , V_234 ) ;
break;
default:
V_234 = strlen ( V_162 -> V_149 . V_238 [ V_37 ] ) ;
V_227 = F_164 ( V_233 + V_234 ) ;
F_166 ( V_227 + V_233 , V_162 -> V_149 . V_238 [ V_37 ] , V_234 ) ;
break;
}
V_233 += V_234 ;
if ( V_37 != V_162 -> V_149 . V_150 - 1 ) {
V_227 = F_164 ( V_233 + 4 ) ;
switch ( V_162 -> V_149 . V_236 [ V_37 ] ) {
case V_247 :
case V_248 :
case V_249 :
switch ( V_162 -> V_149 . V_236 [ V_37 + 1 ] ) {
case V_256 :
case V_257 :
case V_258 :
F_166 ( V_227 + V_233 , L_183 , 4 ) ;
V_233 += 4 ;
break;
default:
F_166 ( V_227 + V_233 , L_184 , 1 ) ;
V_233 += 1 ;
break;
}
break;
case V_250 :
case V_251 :
case V_252 :
switch ( V_162 -> V_149 . V_236 [ V_37 + 1 ] ) {
case V_259 :
case V_260 :
case V_261 :
F_166 ( V_227 + V_233 , L_183 , 4 ) ;
V_233 += 4 ;
break;
default:
F_166 ( V_227 + V_233 , L_184 , 1 ) ;
V_233 += 1 ;
break;
}
break;
case V_253 :
case V_254 :
case V_255 :
switch ( V_162 -> V_149 . V_236 [ V_37 + 1 ] ) {
case V_262 :
case V_263 :
case V_264 :
F_166 ( V_227 + V_233 , L_183 , 4 ) ;
V_233 += 4 ;
break;
default:
F_166 ( V_227 + V_233 , L_184 , 1 ) ;
V_233 += 1 ;
break;
}
break;
case V_256 :
case V_257 :
case V_258 :
switch ( V_162 -> V_149 . V_236 [ V_37 + 1 ] ) {
case V_247 :
case V_248 :
case V_249 :
F_166 ( V_227 + V_233 , L_185 , 4 ) ;
V_233 += 4 ;
break;
default:
F_166 ( V_227 + V_233 , L_184 , 1 ) ;
V_233 += 1 ;
break;
}
break;
case V_259 :
case V_260 :
case V_261 :
switch ( V_162 -> V_149 . V_236 [ V_37 + 1 ] ) {
case V_250 :
case V_251 :
case V_252 :
F_166 ( V_227 + V_233 , L_185 , 4 ) ;
V_233 += 4 ;
break;
default:
F_166 ( V_227 + V_233 , L_184 , 1 ) ;
V_233 += 1 ;
break;
}
break;
case V_262 :
case V_263 :
case V_264 :
switch ( V_162 -> V_149 . V_236 [ V_37 + 1 ] ) {
case V_253 :
case V_254 :
case V_255 :
F_166 ( V_227 + V_233 , L_185 , 4 ) ;
V_233 += 4 ;
break;
default:
F_166 ( V_227 + V_233 , L_184 , 1 ) ;
V_233 += 1 ;
break;
}
break;
default:
F_166 ( V_227 + V_233 , L_184 , 1 ) ;
V_233 += 1 ;
break;
}
}
}
return F_171 ( V_152 , 0 , V_227 ) ;
}
static T_1
F_135 ( T_18 * V_162 , T_22 * V_172 )
{
T_31 V_265 ;
if ( V_96 || F_158 ( V_119 ) ) {
F_172 ( V_172 , FALSE , TRUE ) ;
if ( V_96 ) {
switch ( V_139 ) {
case V_140 :
if ( ! F_169 ( V_162 ) )
return FALSE ;
break;
case V_142 :
F_173 ( V_172 , stdout ) ;
return ! ferror ( stdout ) ;
case V_143 :
F_22 () ;
break;
}
}
}
if ( V_93 ) {
switch ( V_139 ) {
case V_140 :
V_265 . V_95 = V_95 ;
V_265 . V_266 = V_93 ? V_267 : V_268 ;
if ( ! F_174 ( & V_265 , V_172 , V_152 ) )
return FALSE ;
if ( ! V_95 ) {
if ( ! F_171 ( V_152 , 0 , V_129 ) )
return FALSE ;
}
break;
case V_142 :
F_175 ( V_172 , stdout ) ;
printf ( L_5 ) ;
return ! ferror ( stdout ) ;
case V_143 :
F_176 ( V_119 , V_172 , & V_162 -> V_149 , stdout ) ;
printf ( L_5 ) ;
return ! ferror ( stdout ) ;
}
}
if ( V_95 ) {
if ( V_96 || V_93 ) {
if ( ! F_171 ( V_152 , 0 , L_99 ) )
return FALSE ;
}
if ( ! F_177 ( V_152 , V_172 ) )
return FALSE ;
if ( ! F_171 ( V_152 , 0 , V_129 ) )
return FALSE ;
}
return TRUE ;
}
static T_1
F_156 ( void )
{
switch ( V_139 ) {
case V_140 :
return F_178 ( V_152 ) ;
case V_142 :
if ( V_93 )
F_179 ( stdout ) ;
else
F_180 ( stdout ) ;
return ! ferror ( stdout ) ;
case V_143 :
F_181 ( V_119 , stdout ) ;
return ! ferror ( stdout ) ;
default:
F_22 () ;
return FALSE ;
}
}
T_32
F_105 ( T_18 * V_162 , const char * V_269 , unsigned int type , T_1 V_270 , int * V_76 )
{
#if V_271
T_33 * V_272 ;
#else
T_34 * V_200 ;
#endif
T_4 * V_196 ;
char V_273 [ 2048 + 1 ] ;
#if V_271
V_272 = F_182 ( V_269 , V_76 , & V_196 , V_120 ) ;
if ( V_272 == NULL )
goto V_274;
#else
V_200 = F_183 ( V_269 , type , V_76 , & V_196 , V_120 ) ;
if ( V_200 == NULL )
goto V_274;
#endif
F_112 ( V_162 -> V_159 ) ;
V_162 -> V_159 = F_117 ( V_162 ) ;
#if V_271
V_162 -> V_200 = (struct T_34 * ) V_272 ;
#else
V_162 -> V_200 = V_200 ;
#endif
V_162 -> V_275 = 0 ;
V_162 -> V_220 = F_17 ( V_269 ) ;
V_162 -> V_270 = V_270 ;
V_162 -> V_276 = FALSE ;
V_162 -> V_277 = F_184 ( (struct T_33 * ) V_162 -> V_200 ) ;
V_162 -> V_278 = type ;
V_162 -> V_180 = 0 ;
V_162 -> V_279 = FALSE ;
V_162 -> V_280 = 0 ;
V_162 -> V_281 = F_185 ( (struct T_33 * ) V_162 -> V_200 ) ;
if ( V_162 -> V_281 == 0 ) {
V_162 -> V_282 = FALSE ;
V_162 -> V_281 = V_283 ;
} else
V_162 -> V_282 = TRUE ;
F_186 ( & V_162 -> V_182 ) ;
V_163 = NULL ;
V_166 = NULL ;
V_167 = NULL ;
V_162 -> V_284 = V_285 ;
return V_155 ;
V_274:
F_187 ( V_273 , sizeof V_273 ,
F_188 ( * V_76 , V_196 , FALSE , V_162 -> V_277 ) , V_269 ) ;
F_18 ( L_6 , V_273 ) ;
return V_286 ;
}
static void
F_136 ( int V_76 )
{
switch ( V_76 ) {
case V_287 :
F_18 ( L_186
L_187 ) ;
break;
#ifdef F_189
case F_189 :
F_18 ( L_188
L_189 ) ;
break;
#endif
default:
F_18 ( L_190 ,
F_76 ( V_76 ) ) ;
break;
}
}
static const char *
F_188 ( int V_76 , T_4 * V_196 , T_1 V_288 ,
int V_289 )
{
const char * V_290 ;
static char V_291 [ 1024 + 1 ] ;
if ( V_76 < 0 ) {
switch ( V_76 ) {
case V_292 :
V_290 = L_191 ;
break;
case V_293 :
V_290 = L_192 ;
break;
case V_294 :
V_290 = L_193 ;
break;
case V_219 :
F_187 ( V_291 , sizeof( V_291 ) ,
L_194
L_181 , V_196 ) ;
F_20 ( V_196 ) ;
V_290 = V_291 ;
break;
case V_295 :
F_187 ( V_291 , sizeof( V_291 ) ,
L_195
L_196 , F_190 ( V_289 ) ) ;
V_290 = V_291 ;
break;
case V_296 :
V_290 = L_197 ;
break;
case V_221 :
if ( V_288 ) {
F_187 ( V_291 , sizeof( V_291 ) ,
L_198 ,
F_190 ( V_289 ) ) ;
} else {
F_187 ( V_291 , sizeof( V_291 ) ,
L_199
L_181 , V_196 ) ;
F_20 ( V_196 ) ;
}
V_290 = V_291 ;
break;
case V_297 :
if ( V_288 ) {
F_187 ( V_291 , sizeof( V_291 ) ,
L_198 ,
F_190 ( V_289 ) ) ;
V_290 = V_291 ;
} else
V_290 = L_200 ;
break;
case V_223 :
F_187 ( V_291 , sizeof( V_291 ) ,
L_201
L_181 , V_196 ) ;
F_20 ( V_196 ) ;
V_290 = V_291 ;
break;
case V_298 :
if ( V_288 )
V_290 = L_202 ;
else
V_290 = L_203 ;
break;
case V_203 :
V_290 = L_204
L_205 ;
break;
case V_299 :
V_290 = L_206 ;
break;
case V_300 :
V_290 = L_207 ;
break;
case V_224 :
F_187 ( V_291 , sizeof( V_291 ) ,
L_208
L_181 , V_196 ) ;
F_20 ( V_196 ) ;
V_290 = V_291 ;
break;
default:
F_187 ( V_291 , sizeof( V_291 ) ,
L_209 ,
V_288 ? L_210 : L_211 ,
F_155 ( V_76 ) ) ;
V_290 = V_291 ;
break;
}
} else
V_290 = F_191 ( V_76 , V_288 ) ;
return V_290 ;
}
static void
V_107 ( const char * V_220 , int V_76 , T_1 V_288 )
{
fprintf ( V_5 , L_212 ) ;
fprintf ( V_5 , F_191 ( V_76 , V_288 ) , V_220 ) ;
fprintf ( V_5 , L_5 ) ;
}
static void
V_106 ( const char * V_301 , T_35 V_302 )
{
fprintf ( V_5 , L_212 ) ;
vfprintf ( V_5 , V_301 , V_302 ) ;
fprintf ( V_5 , L_5 ) ;
}
static void
V_108 ( const char * V_220 , int V_76 )
{
F_18 ( L_213 ,
V_220 , F_76 ( V_76 ) ) ;
}
static void
V_109 ( const char * V_220 , int V_76 )
{
F_18 ( L_214 ,
V_220 , F_76 ( V_76 ) ) ;
}
void
F_18 ( const char * V_303 , ... )
{
T_35 V_302 ;
va_start ( V_302 , V_303 ) ;
V_106 ( V_303 , V_302 ) ;
va_end ( V_302 ) ;
}
void
F_87 ( const char * V_303 , ... )
{
T_35 V_302 ;
va_start ( V_302 , V_303 ) ;
vfprintf ( V_5 , V_303 , V_302 ) ;
fprintf ( V_5 , L_5 ) ;
va_end ( V_302 ) ;
}
