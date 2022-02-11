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
F_13 ( T_6 V_18 )
{
T_7 * V_19 ;
if ( V_18 ) {
V_19 = stdout ;
fprintf ( V_19 ,
L_6 V_20 L_7
L_8
L_9
L_10
L_11 ,
V_21 , F_14 () ) ;
} else {
V_19 = V_7 ;
}
fprintf ( V_19 , L_10 ) ;
fprintf ( V_19 , L_12 ) ;
fprintf ( V_19 , L_10 ) ;
#ifdef F_15
fprintf ( V_19 , L_13 ) ;
fprintf ( V_19 , L_14 ) ;
fprintf ( V_19 , L_15 ) ;
fprintf ( V_19 , L_16 ) ;
fprintf ( V_19 , L_17 ) ;
#ifdef F_16
fprintf ( V_19 , L_18 ) ;
#endif
#if F_17 ( V_22 ) || F_17 ( F_16 )
fprintf ( V_19 , L_19 , V_23 ) ;
#endif
fprintf ( V_19 , L_20 ) ;
fprintf ( V_19 , L_21 ) ;
fprintf ( V_19 , L_22 ) ;
fprintf ( V_19 , L_10 ) ;
fprintf ( V_19 , L_23 ) ;
fprintf ( V_19 , L_24 ) ;
fprintf ( V_19 , L_25 ) ;
fprintf ( V_19 , L_26 ) ;
fprintf ( V_19 , L_27 ) ;
fprintf ( V_19 , L_28 ) ;
fprintf ( V_19 , L_29 ) ;
fprintf ( V_19 , L_30 ) ;
fprintf ( V_19 , L_31 ) ;
#endif
#ifdef F_18
fprintf ( V_19 , L_32 ) ;
fprintf ( V_19 , L_33 ) ;
#endif
fprintf ( V_19 , L_34 ) ;
fprintf ( V_19 , L_35 ) ;
fprintf ( V_19 , L_10 ) ;
fprintf ( V_19 , L_36 ) ;
fprintf ( V_19 , L_37 ) ;
fprintf ( V_19 , L_38 ) ;
fprintf ( V_19 , L_39 ) ;
fprintf ( V_19 , L_40 ) ;
fprintf ( V_19 , L_41 ) ;
fprintf ( V_19 , L_42 ) ;
fprintf ( V_19 , L_43 , V_24 ) ;
fprintf ( V_19 , L_44 ) ;
fprintf ( V_19 , L_45 ) ;
fprintf ( V_19 , L_46 ) ;
fprintf ( V_19 , L_47 ) ;
fprintf ( V_19 , L_48 ) ;
fprintf ( V_19 , L_49 ) ;
fprintf ( V_19 , L_50 ) ;
fprintf ( V_19 , L_51 ) ;
fprintf ( V_19 , L_52 ) ;
fprintf ( V_19 , L_53 ) ;
fprintf ( V_19 , L_54 ) ;
fprintf ( V_19 , L_55 ) ;
fprintf ( V_19 , L_56 ) ;
fprintf ( V_19 , L_57 ) ;
fprintf ( V_19 , L_58 ) ;
fprintf ( V_19 , L_59 ) ;
fprintf ( V_19 , L_60 ) ;
fprintf ( V_19 , L_61 ) ;
fprintf ( V_19 , L_62 ) ;
fprintf ( V_19 , L_63 ) ;
fprintf ( V_19 , L_64 ) ;
fprintf ( V_19 , L_65 ) ;
fprintf ( V_19 , L_66 ) ;
fprintf ( V_19 , L_67 ) ;
fprintf ( V_19 , L_68 ) ;
fprintf ( V_19 , L_69 ) ;
fprintf ( V_19 , L_70 ) ;
fprintf ( V_19 , L_71 ) ;
fprintf ( V_19 , L_72 ) ;
fprintf ( V_19 , L_73 ) ;
fprintf ( V_19 , L_74 ) ;
fprintf ( V_19 , L_75 ) ;
fprintf ( V_19 , L_76 ) ;
fprintf ( V_19 , L_77 ) ;
fprintf ( V_19 , L_78 ) ;
fprintf ( V_19 , L_79 ) ;
fprintf ( V_19 , L_80 ) ;
fprintf ( V_19 , L_81 ) ;
fprintf ( V_19 , L_82 ) ;
fprintf ( V_19 , L_83 ) ;
fprintf ( V_19 , L_84 ) ;
fprintf ( V_19 , L_10 ) ;
fprintf ( V_19 , L_85 ) ;
fprintf ( V_19 , L_86 ) ;
fprintf ( V_19 , L_87 ) ;
fprintf ( V_19 , L_88 ) ;
fprintf ( V_19 , L_89 ) ;
fprintf ( V_19 , L_90 ) ;
fprintf ( V_19 , L_91 ) ;
fprintf ( V_19 , L_92 ) ;
#ifdef F_19
fprintf ( V_19 , L_10 ) ;
fprintf ( V_19 , L_93 ) ;
fprintf ( V_19 , L_94 ) ;
fprintf ( V_19 , L_95 ) ;
fprintf ( V_19 , L_10 ) ;
#endif
}
static void
F_20 ( void )
{
T_7 * V_19 ;
V_19 = stdout ;
fprintf ( V_19 , L_6 V_20 L_7 , V_21 ) ;
fprintf ( V_19 , L_10 ) ;
fprintf ( V_19 , L_96 ) ;
fprintf ( V_19 , L_10 ) ;
fprintf ( V_19 , L_97 ) ;
fprintf ( V_19 , L_98 ) ;
fprintf ( V_19 , L_99 ) ;
fprintf ( V_19 , L_100 ) ;
fprintf ( V_19 , L_101 ) ;
fprintf ( V_19 , L_102 ) ;
fprintf ( V_19 , L_103 ) ;
fprintf ( V_19 , L_104 ) ;
fprintf ( V_19 , L_105 ) ;
fprintf ( V_19 , L_10 ) ;
fprintf ( V_19 , L_106 ) ;
fprintf ( V_19 , L_107 ) ;
fprintf ( V_19 , L_108 ) ;
fprintf ( V_19 , L_10 ) ;
}
static void
F_21 ( const char * V_25 , const char * V_26 ,
T_3 V_19 )
{
if ( ( V_27 == NULL ) ||
( strcmp ( V_27 , V_25 ) != 0 ) ) {
fprintf ( ( T_7 * ) V_19 , L_109 , V_25 , V_26 ) ;
V_27 = V_25 ;
}
}
static void
F_22 ( const T_8 * T_9 V_6 , T_3 V_28 , T_3 V_19 )
{
int V_29 ;
const T_8 * V_30 ;
const T_8 * V_31 ;
V_29 = F_23 ( ( V_32 ) V_28 ) ;
if ( V_29 != - 1 ) {
V_30 = F_24 ( V_29 ) ;
V_31 = F_25 ( V_29 ) ;
F_26 ( V_30 != NULL ) ;
F_26 ( V_31 != NULL ) ;
if ( ( V_27 == NULL ) ||
( strcmp ( V_27 , V_30 ) != 0 ) ) {
fprintf ( ( T_7 * ) V_19 , L_109 ,
V_30 ,
V_31 ) ;
V_27 = V_30 ;
}
}
}
static void
F_27 ( const T_8 * T_9 V_6 , T_3 V_28 , T_3 V_33 )
{
int V_29 ;
const T_8 * V_34 ;
T_10 V_35 ;
F_26 ( V_28 ) ;
V_35 = ( T_10 ) V_33 ;
V_29 = F_23 ( ( V_32 ) V_28 ) ;
if ( V_29 != - 1 ) {
V_34 = F_24 ( V_29 ) ;
F_26 ( V_34 != NULL ) ;
if ( strcmp ( V_34 , V_35 -> V_36 ) == 0 ) {
if ( V_35 -> V_37 == 0 ) {
V_35 -> V_38 = ( V_32 ) V_28 ;
}
V_35 -> V_37 ++ ;
}
}
}
static T_1
F_28 ( T_2 V_39 , T_2 V_40 )
{
return strcmp ( ( const char * ) V_39 , ( const char * ) V_40 ) ;
}
static void
F_29 ( T_7 * V_19 )
{
V_27 = NULL ;
F_30 ( F_21 , ( T_3 ) V_19 , ( V_41 ) F_28 ) ;
}
static void
F_31 ( T_7 * V_19 , T_8 * V_25 )
{
V_27 = NULL ;
F_32 ( V_25 ,
F_22 ,
( T_3 ) V_19 ) ;
}
static T_6
F_33 ( const T_8 * V_42 )
{
T_8 * V_25 ;
T_11 V_43 , V_44 ;
T_8 * V_45 ;
T_8 * V_46 ;
T_8 * V_47 ;
T_8 * V_48 ;
V_32 V_49 ;
T_12 V_50 ;
T_13 V_51 ;
struct V_52 V_53 ;
T_14 V_9 ;
char V_54 ;
F_26 ( V_42 ) ;
V_45 = F_34 ( V_42 ) ;
F_26 ( V_45 ) ;
V_25 = V_45 ;
V_46 = strchr ( V_25 , '=' ) ;
if ( V_46 == NULL ) {
F_35 ( L_110 , V_42 , V_24 ) ;
}
else {
* V_46 = '\0' ;
}
while ( V_25 [ 0 ] == ' ' )
V_25 ++ ;
while ( V_25 [ strlen ( V_25 ) - 1 ] == ' ' )
V_25 [ strlen ( V_25 ) - 1 ] = '\0' ;
V_50 = NULL ;
if ( ! ( * ( V_25 ) ) ) {
F_35 ( L_111 ) ;
}
else {
V_50 = F_36 ( V_25 ) ;
if ( ! V_50 ) {
F_35 ( L_112 , V_25 ) ;
}
}
if ( ! V_50 ) {
F_35 ( L_113 ) ;
F_29 ( V_7 ) ;
}
if ( V_46 == NULL || ! V_50 ) {
F_11 ( V_45 ) ;
return FALSE ;
}
if ( * ( V_46 + 1 ) != '=' ) {
F_35 ( L_114 , V_25 , V_46 + 1 ) ;
}
else {
V_46 ++ ;
* V_46 = '\0' ;
}
V_46 ++ ;
V_47 = V_46 ;
V_46 = strchr ( V_47 , ',' ) ;
if ( V_46 == NULL ) {
F_35 ( L_110 , V_42 , V_24 ) ;
}
else {
* V_46 = '\0' ;
}
V_51 = F_37 ( V_25 ) ;
switch ( V_51 ) {
case V_55 :
case V_56 :
case V_57 :
case V_58 :
switch ( sscanf ( V_47 , L_115 , & V_43 , & V_54 , & V_44 ) ) {
case 1 :
V_54 = '\0' ;
break;
case 3 :
if ( V_54 != ':' && V_54 != '-' ) {
F_35 ( L_116 , V_47 ) ;
F_11 ( V_45 ) ;
return FALSE ;
}
if ( V_54 == ':' ) {
if ( ( V_44 == 0 ) || ( ( T_14 ) V_43 + V_44 - 1 ) > V_59 ) {
F_35 ( L_116 , V_47 ) ;
F_11 ( V_45 ) ;
return FALSE ;
}
}
else if ( V_44 < V_43 ) {
F_35 ( L_116 , V_47 ) ;
F_11 ( V_45 ) ;
return FALSE ;
}
break;
default:
F_35 ( L_117 , V_47 ) ;
F_11 ( V_45 ) ;
return FALSE ;
}
break;
case V_60 :
case V_61 :
case V_62 :
case V_63 :
break;
default:
F_38 () ;
}
if ( V_46 == NULL ) {
F_35 ( L_118 , V_25 ) ;
F_31 ( V_7 , V_25 ) ;
F_11 ( V_45 ) ;
return FALSE ;
}
V_46 ++ ;
V_48 = V_46 ;
while ( V_48 [ 0 ] == ' ' )
V_48 ++ ;
while ( V_48 [ strlen ( V_48 ) - 1 ] == ' ' )
V_48 [ strlen ( V_48 ) - 1 ] = '\0' ;
V_49 = NULL ;
if ( ! ( * V_48 ) ) {
F_35 ( L_119 ) ;
}
else {
V_53 . V_37 = 0 ;
V_53 . V_36 = V_48 ;
V_53 . V_38 = NULL ;
F_32 ( V_25 , F_27 , & V_53 ) ;
if ( V_53 . V_37 != 0 ) {
V_49 = V_53 . V_38 ;
if ( V_53 . V_37 > 1 ) {
F_35 ( L_120 , V_48 , V_53 . V_37 ) ;
}
}
else {
if ( F_39 ( V_48 ) == - 1 ) {
F_35 ( L_121 , V_48 ) ;
} else {
F_35 ( L_122 ,
V_48 , V_25 ) ;
}
}
}
if ( ! V_49 ) {
F_35 ( L_118 , V_25 ) ;
F_31 ( V_7 , V_25 ) ;
F_11 ( V_45 ) ;
return FALSE ;
}
switch ( V_51 ) {
case V_55 :
case V_56 :
case V_57 :
case V_58 :
if ( V_54 == '\0' ) {
F_40 ( V_25 , V_43 , V_49 ) ;
} else if ( V_54 == ':' ) {
for ( V_9 = V_43 ; V_9 < ( T_14 ) V_43 + V_44 ; V_9 ++ ) {
F_40 ( V_25 , ( T_11 ) V_9 , V_49 ) ;
}
} else {
for ( V_9 = V_43 ; V_9 <= V_44 ; V_9 ++ ) {
F_40 ( V_25 , ( T_11 ) V_9 , V_49 ) ;
}
}
break;
case V_60 :
case V_61 :
case V_62 :
case V_63 :
F_41 ( V_25 , V_47 , V_49 ) ;
break;
default:
F_38 () ;
}
F_11 ( V_45 ) ;
return TRUE ;
}
static void
F_42 ( const T_8 * V_64 , T_15 V_65 ,
const T_8 * V_66 , T_3 V_33 )
{
if ( ( V_65 & V_67 & V_68 . V_69 ) == 0 &&
V_68 . V_69 != 0 ) {
return;
}
F_43 ( V_64 , V_65 , V_66 , V_33 ) ;
}
static char *
F_44 ( const char * V_70 )
{
char * V_71 ;
if ( strcmp ( V_70 , L_123 ) == 0 ) {
V_71 = F_34 ( L_124 ) ;
} else {
V_71 = F_45 ( L_125 , V_70 ) ;
}
return V_71 ;
}
static void
F_46 ( void ) {
T_8 * V_72 , * V_73 ;
if ( F_47 () ) {
V_72 = F_48 () ;
V_73 = F_49 () ;
fprintf ( V_7 , L_126 ,
V_72 , V_73 ) ;
F_11 ( V_72 ) ;
F_11 ( V_73 ) ;
if ( F_50 () ) {
fprintf ( V_7 , L_127 ) ;
}
fprintf ( V_7 , L_10 ) ;
}
}
static void
F_51 ( void ) {
#ifdef V_22
F_52 () ;
if ( ! F_53 () && F_54 () >= 6 ) {
fprintf ( V_7 , L_128
L_129 ) ;
}
#endif
}
static void
F_55 ( T_16 * V_74 , T_16 * V_75 )
{
printf ( L_6 V_20 L_7
L_10
L_11
L_10
L_11
L_10
L_11 ,
V_21 , F_14 () , V_74 -> V_76 ,
V_75 -> V_76 ) ;
}
int
main ( int V_77 , char * V_78 [] )
{
T_16 * V_74 ;
T_16 * V_75 ;
char * V_79 ;
int V_80 ;
struct V_81 V_82 [] = {
{ ( char * ) L_130 , V_83 , NULL , V_84 } ,
{ 0 , 0 , 0 , 0 }
} ;
T_6 V_85 = FALSE ;
#ifdef V_22
T_17 V_86 ;
#endif
char * V_87 , * V_88 ;
char * V_89 , * V_90 ;
int V_91 , V_92 ;
int V_93 , V_94 ;
int V_95 , V_96 ;
int V_97 , V_98 ;
int V_99 ;
volatile int V_100 = 0 ;
#ifdef F_15
T_6 V_101 = FALSE ;
T_6 V_102 = FALSE ;
int V_103 ;
T_18 * V_104 ;
T_8 * V_105 ;
#else
T_6 V_106 = FALSE ;
#endif
T_6 V_107 = FALSE ;
#ifdef F_56
volatile int V_108 = V_109 ;
#else
volatile int V_108 = V_110 ;
#endif
volatile T_6 V_111 = FALSE ;
volatile int V_112 = V_113 ;
T_8 * volatile V_114 = NULL ;
T_8 * V_115 = NULL ;
T_8 * V_116 = NULL ;
#ifdef F_57
struct V_117 V_118 ;
#endif
T_19 * V_119 = NULL ;
T_19 * V_120 = NULL ;
T_20 * V_121 ;
char V_122 ;
int V_123 ;
int V_124 ;
T_8 * V_125 = NULL ;
#ifdef F_18
#define F_58 "A:"
#else
#define F_58 ""
#endif
#ifdef F_15
#if F_17 ( V_22 ) || F_17 ( F_16 )
#define F_59 "B:"
#else
#define F_59 ""
#endif
#else
#define F_59 ""
#endif
#ifdef F_16
#define F_60 "I"
#else
#define F_60 ""
#endif
#define F_61 "-2a:" OPTSTRING_A "b:" OPTSTRING_B "c:C:d:De:E:f:F:gG:hH:i:" OPTSTRING_I "K:lLnN:o:O:pPqQr:R:s:S:t:T:u:vVw:W:xX:y:Y:z:"
static const char V_126 [] = F_61 ;
V_74 = F_62 ( L_131 ) ;
F_63 ( V_74 , NULL , V_127 ) ;
V_75 = F_62 ( L_132 ) ;
F_64 ( V_75 , NULL ) ;
F_65 ( L_6 V_20 L_7
L_10
L_11
L_10
L_11 ,
V_21 , V_74 -> V_76 , V_75 -> V_76 ) ;
#ifdef V_22
F_66 ( V_77 , V_78 ) ;
F_67 () ;
#if ! F_68 ( 2 , 31 , 0 )
F_69 ( NULL ) ;
#endif
#endif
F_70 () ;
V_79 = F_71 ( V_78 [ 0 ] , main ) ;
if ( V_79 != NULL ) {
fprintf ( V_7 , L_133 ,
V_79 ) ;
}
V_128 = 0 ;
V_124 = V_129 ;
while ( ( V_80 = F_72 ( V_77 , V_78 , V_126 ) ) != - 1 ) {
switch ( V_80 ) {
case 'C' :
if ( F_73 ( V_130 , FALSE ) ) {
F_74 ( V_130 ) ;
} else {
F_35 ( L_134 , V_130 ) ;
return 1 ;
}
break;
case 'P' :
V_131 = TRUE ;
V_132 = TRUE ;
break;
case 'O' :
V_125 = F_34 ( V_130 ) ;
case 'V' :
V_133 = TRUE ;
V_131 = TRUE ;
break;
case 'x' :
V_134 = TRUE ;
V_131 = TRUE ;
break;
case 'X' :
F_75 ( V_130 ) ;
break;
default:
break;
}
}
if ( V_132 == - 1 )
V_132 = ( V_133 || V_134 ) ? FALSE : TRUE ;
V_129 = V_124 ;
V_128 = 1 ;
V_123 =
V_135 |
V_136 |
V_137 |
V_138 |
V_139 |
V_140 |
V_141 | V_142 ;
F_76 ( NULL ,
( T_15 ) V_123 ,
F_42 , NULL ) ;
F_76 ( V_143 ,
( T_15 ) V_123 ,
F_42 , NULL ) ;
#ifdef F_15
F_76 ( V_144 ,
( T_15 ) V_123 ,
F_42 , NULL ) ;
F_76 ( V_145 ,
( T_15 ) V_123 ,
F_42 , NULL ) ;
#endif
F_77 () ;
F_78 ( V_146 , V_147 , V_148 ,
V_149 ) ;
#ifdef F_15
F_79 ( & V_150 ) ;
F_80 ( & V_151 , ( void * ) & V_152 ) ;
#endif
F_81 ( V_153 ) ;
F_82 ( V_154 ) ;
F_83 ( V_155 ) ;
F_84 () ;
#ifdef F_85
F_86 () ;
F_87 () ;
F_88 () ;
F_89 () ;
#endif
F_90 ( V_156 , V_157 , NULL , NULL ) ;
#ifdef F_85
F_91 () ;
#endif
F_92 () ;
if ( V_77 >= 2 && strcmp ( V_78 [ 1 ] , L_135 ) == 0 ) {
F_93 () ;
if ( V_77 == 2 )
F_94 () ;
else {
if ( strcmp ( V_78 [ 2 ] , L_136 ) == 0 )
F_95 () ;
else if ( strcmp ( V_78 [ 2 ] , L_137 ) == 0 ) {
F_96 ( & V_91 , & V_92 , & V_87 ,
& V_93 , & V_94 , & V_88 ) ;
F_97 ( NULL ) ;
}
else if ( strcmp ( V_78 [ 2 ] , L_138 ) == 0 )
F_98 () ;
else if ( strcmp ( V_78 [ 2 ] , L_139 ) == 0 )
F_97 ( NULL ) ;
else if ( strcmp ( V_78 [ 2 ] , L_140 ) == 0 )
F_94 () ;
else if ( strcmp ( V_78 [ 2 ] , L_141 ) == 0 )
F_99 () ;
else if ( strcmp ( V_78 [ 2 ] , L_142 ) == 0 )
F_100 () ;
else if ( strcmp ( V_78 [ 2 ] , L_143 ) == 0 ) {
#ifdef F_85
F_101 () ;
#endif
#ifdef F_102
F_103 () ;
#endif
}
else if ( strcmp ( V_78 [ 2 ] , L_144 ) == 0 )
F_104 () ;
else if ( strcmp ( V_78 [ 2 ] , L_145 ) == 0 )
F_105 () ;
else if ( strcmp ( V_78 [ 2 ] , L_146 ) == 0 )
F_20 () ;
else if ( strcmp ( V_78 [ 2 ] , L_147 ) == 0 )
F_20 () ;
else {
F_35 ( L_148 , V_78 [ 2 ] ) ;
return 1 ;
}
}
return 0 ;
}
setlocale ( V_158 , L_149 ) ;
V_121 = F_96 ( & V_91 , & V_92 , & V_87 ,
& V_93 , & V_94 , & V_88 ) ;
if ( V_87 != NULL ) {
if ( V_91 != 0 ) {
F_35 ( L_150 ,
V_88 , F_106 ( V_91 ) ) ;
}
if ( V_92 != 0 ) {
F_35 ( L_151 ,
V_88 , F_106 ( V_92 ) ) ;
}
}
if ( V_88 != NULL ) {
if ( V_93 != 0 ) {
F_35 ( L_152 , V_88 ,
F_106 ( V_93 ) ) ;
}
if ( V_94 != 0 ) {
F_35 ( L_153 ,
V_88 , F_106 ( V_94 ) ) ;
}
F_11 ( V_88 ) ;
V_88 = NULL ;
}
F_107 ( & V_89 , & V_95 , & V_96 ,
& V_90 , & V_97 , & V_98 ) ;
if ( V_89 != NULL ) {
if ( V_95 != 0 ) {
F_35 ( L_154 ,
V_89 , F_106 ( V_95 ) ) ;
}
if ( V_96 != 0 ) {
F_35 ( L_155 ,
V_89 , F_106 ( V_96 ) ) ;
}
F_11 ( V_89 ) ;
}
if ( V_90 != NULL ) {
if ( V_97 != 0 ) {
F_35 (
L_156 , V_90 ,
F_106 ( V_97 ) ) ;
}
if ( V_98 != 0 ) {
F_35 (
L_157 , V_90 ,
F_106 ( V_98 ) ) ;
}
F_11 ( V_90 ) ;
}
F_51 () ;
F_108 ( & V_152 ) ;
V_159 = V_160 ;
V_161 = F_109 () ;
while ( ( V_80 = F_110 ( V_77 , V_78 , V_126 , V_82 , NULL ) ) != - 1 ) {
switch ( V_80 ) {
case '2' :
V_162 = TRUE ;
break;
case 'a' :
case 'b' :
case 'c' :
case 'f' :
case 'g' :
case 'i' :
case 'p' :
#ifdef F_18
case 'A' :
#endif
#ifdef F_16
case 'I' :
#endif
case 's' :
case 'w' :
case 'y' :
case V_84 :
#if F_17 ( V_22 ) || F_17 ( F_16 )
case 'B' :
#endif
#ifdef F_15
V_103 = F_111 ( & V_150 , V_80 , V_130 , & V_102 ) ;
if ( V_103 != 0 ) {
return V_103 ;
}
#else
if ( V_80 == 'w' ) {
V_163 = V_130 ;
} else {
V_106 = TRUE ;
V_85 = TRUE ;
}
#endif
break;
case 'C' :
break;
case 'd' :
if ( ! F_33 ( V_130 ) )
return 1 ;
break;
#if F_17 ( V_164 ) || F_17 ( V_165 )
case 'K' :
F_112 ( V_130 ) ;
break;
#endif
case 'D' :
#ifdef F_15
V_104 = F_113 ( & V_99 , & V_105 , NULL ) ;
if ( V_104 == NULL ) {
switch ( V_99 ) {
case V_166 :
case V_167 :
F_35 ( L_11 , V_105 ) ;
F_11 ( V_105 ) ;
break;
case V_168 :
F_35 ( L_158 ) ;
break;
}
return 2 ;
}
F_114 ( V_104 ) ;
F_115 ( V_104 ) ;
return 0 ;
#else
V_106 = TRUE ;
V_85 = TRUE ;
#endif
break;
case 'e' :
F_116 ( V_161 , V_130 ) ;
break;
case 'E' :
if ( ! F_117 ( V_161 , V_130 ) ) {
F_35 ( L_159 , V_130 ) ;
F_118 ( V_7 ) ;
return 1 ;
}
break;
case 'F' :
V_108 = F_119 ( V_130 ) ;
if ( V_108 < 0 ) {
F_35 ( L_160 , V_130 ) ;
F_3 () ;
return 1 ;
}
break;
case 'W' :
if ( strchr ( V_130 , 'n' ) ) {
V_111 = TRUE ;
} else {
F_35 ( L_161 , V_130 ) ;
F_120 ( L_162 ) ;
return 1 ;
}
break;
case 'H' :
if ( ! F_121 ( V_130 ) )
{
F_35 ( L_163 , V_130 ) ;
return 1 ;
}
V_111 = TRUE ;
break;
case 'h' :
F_13 ( TRUE ) ;
return 0 ;
break;
case 'l' :
V_169 = TRUE ;
break;
case 'L' :
#ifdef F_15
V_101 = TRUE ;
#else
V_106 = TRUE ;
V_85 = TRUE ;
#endif
break;
case 'n' :
V_170 . V_171 = FALSE ;
V_170 . V_172 = FALSE ;
V_170 . V_173 = FALSE ;
V_170 . V_174 = FALSE ;
break;
case 'N' :
V_122 = F_122 ( V_130 , & V_170 ) ;
if ( V_122 != '\0' ) {
F_35 ( L_164 ,
V_122 ) ;
F_120 ( L_165
L_166
L_167
L_168
L_169
L_170 ) ;
return 1 ;
}
break;
case 'o' :
switch ( F_123 ( V_130 ) ) {
case V_175 :
break;
case V_176 :
F_35 ( L_171 , V_130 ) ;
return 1 ;
break;
case V_177 :
case V_178 :
F_35 ( L_172 , V_130 ) ;
return 1 ;
break;
}
break;
case 'q' :
V_107 = TRUE ;
break;
case 'Q' :
V_107 = TRUE ;
V_179 = TRUE ;
break;
case 'r' :
V_114 = F_34 ( V_130 ) ;
break;
case 'R' :
V_115 = V_130 ;
break;
case 'P' :
break;
case 'S' :
V_180 = V_130 ;
break;
case 't' :
if ( strcmp ( V_130 , L_173 ) == 0 )
F_81 ( V_153 ) ;
else if ( strcmp ( V_130 , L_174 ) == 0 )
F_81 ( V_181 ) ;
else if ( strcmp ( V_130 , L_175 ) == 0 )
F_81 ( V_182 ) ;
else if ( strcmp ( V_130 , L_176 ) == 0 )
F_81 ( V_183 ) ;
else if ( strcmp ( V_130 , L_177 ) == 0 )
F_81 ( V_184 ) ;
else if ( strcmp ( V_130 , L_178 ) == 0 )
F_81 ( V_185 ) ;
else if ( strcmp ( V_130 , L_179 ) == 0 )
F_81 ( V_186 ) ;
else if ( strcmp ( V_130 , L_180 ) == 0 )
F_81 ( V_187 ) ;
else if ( strcmp ( V_130 , L_181 ) == 0 )
F_81 ( V_188 ) ;
else if ( strcmp ( V_130 , L_182 ) == 0 )
F_81 ( V_189 ) ;
else {
F_35 ( L_183 , V_130 ) ;
F_120 ( L_184
L_185
L_186
L_187
L_188
L_189
L_190
L_191
L_192
L_193 ) ;
return 1 ;
}
break;
case 'T' :
V_131 = TRUE ;
if ( strcmp ( V_130 , L_194 ) == 0 ) {
V_190 = V_191 ;
V_159 = V_160 ;
} else if ( strcmp ( V_130 , L_195 ) == 0 ) {
V_190 = V_191 ;
V_159 = V_192 ;
} else if ( strcmp ( V_130 , L_196 ) == 0 ) {
V_190 = V_193 ;
V_133 = TRUE ;
V_132 = FALSE ;
} else if ( strcmp ( V_130 , L_197 ) == 0 ) {
V_190 = V_193 ;
V_133 = FALSE ;
V_132 = TRUE ;
} else if ( strcmp ( V_130 , L_140 ) == 0 ) {
V_190 = V_194 ;
V_133 = TRUE ;
V_132 = FALSE ;
} else {
F_35 ( L_198 , V_130 ) ;
F_120 ( L_199
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
L_214 ) ;
return 1 ;
}
break;
case 'u' :
if ( strcmp ( V_130 , L_215 ) == 0 )
F_83 ( V_155 ) ;
else if ( strcmp ( V_130 , L_216 ) == 0 )
F_83 ( V_195 ) ;
else {
F_35 ( L_217 , V_130 ) ;
F_120 ( L_218
L_219 ) ;
return 1 ;
}
break;
case 'v' :
{
F_55 ( V_74 , V_75 ) ;
F_124 ( V_74 , TRUE ) ;
F_124 ( V_75 , TRUE ) ;
F_125 () ;
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
V_116 = V_130 ;
break;
case 'z' :
if ( ! F_126 ( V_130 ) ) {
if ( strcmp ( L_220 , V_130 ) == 0 ) {
fprintf ( V_7 , L_221 ) ;
F_127 () ;
return 0 ;
}
F_35 ( L_222 , V_130 ) ;
F_127 () ;
return 1 ;
}
break;
default:
case '?' :
switch( V_196 ) {
case 'F' :
F_3 () ;
break;
default:
F_13 ( TRUE ) ;
}
return 1 ;
break;
}
}
if ( V_194 != V_190 && 0 != F_128 ( V_161 ) ) {
F_35 ( L_223
L_224 ) ;
return 1 ;
} else if ( V_194 == V_190 && 0 == F_128 ( V_161 ) ) {
F_35 ( L_225
L_226 ) ;
return 1 ;
}
if ( V_129 < V_77 ) {
if ( V_114 != NULL ) {
if ( V_116 != NULL ) {
F_35 ( L_227
L_228 ) ;
return 1 ;
}
V_116 = F_129 ( V_77 , V_78 , V_129 ) ;
} else {
#ifdef F_15
T_21 V_9 ;
if ( V_150 . V_197 . V_198 ) {
F_35 ( L_229
L_230 ) ;
return 1 ;
}
for ( V_9 = 0 ; V_9 < V_150 . V_199 -> V_200 ; V_9 ++ ) {
T_22 V_201 ;
V_201 = F_130 ( V_150 . V_199 , T_22 , V_9 ) ;
if ( V_201 . V_198 == NULL ) {
V_201 . V_198 = F_129 ( V_77 , V_78 , V_129 ) ;
V_150 . V_199 = F_131 ( V_150 . V_199 , V_9 ) ;
F_132 ( V_150 . V_199 , V_9 , V_201 ) ;
} else {
F_35 ( L_231
L_230 ) ;
return 1 ;
}
}
V_150 . V_197 . V_198 = F_129 ( V_77 , V_78 , V_129 ) ;
#else
V_106 = TRUE ;
#endif
}
}
#ifdef F_15
if ( ! V_150 . V_202 ) {
if ( ! V_107 )
V_131 = TRUE ;
} else {
if ( strcmp ( V_150 . V_203 , L_123 ) == 0 && V_131 ) {
F_35 ( L_232
L_233 ) ;
return 1 ;
}
}
#else
if ( ! V_107 )
V_131 = TRUE ;
#endif
#ifndef F_15
if ( V_106 )
F_35 ( L_234 ) ;
#endif
if ( V_85 ) {
F_13 ( FALSE ) ;
return 1 ;
}
if ( V_134 ) {
if ( V_190 != V_191 ) {
F_35 ( L_235 ) ;
return 1 ;
}
}
if ( V_125 != NULL ) {
char * V_204 ;
if ( ! V_133 ) {
F_35 ( L_236 ) ;
return 1 ;
}
V_205 = F_133 ( V_206 , V_207 ) ;
for ( V_204 = strtok ( V_125 , L_237 ) ; V_204 ; V_204 = strtok ( NULL , L_237 ) ) {
F_134 ( V_205 , ( T_3 ) V_204 , ( T_3 ) V_204 ) ;
}
}
if ( V_115 != NULL && ! V_162 ) {
F_35 ( L_238 ) ;
return 1 ;
}
#ifdef F_15
if ( V_101 ) {
if ( V_114 ) {
F_35 ( L_239 ) ;
return 1 ;
}
if ( V_150 . V_208 ) {
F_35 ( L_240 ) ;
return 1 ;
}
} else {
if ( V_114 ) {
if ( V_150 . V_197 . V_198 ) {
F_35 ( L_241
L_242 ) ;
return 1 ;
}
if ( V_150 . V_208 ) {
F_35 ( L_243
L_244 ) ;
return 1 ;
}
if ( V_150 . V_209 ) {
F_35 ( L_245
L_244 ) ;
return 1 ;
}
if ( V_150 . V_210 ) {
F_35 ( L_246
L_244 ) ;
return 1 ;
}
if ( V_150 . V_211 ) {
F_35 ( L_247
L_244 ) ;
return 1 ;
}
if ( V_150 . V_212 ) {
F_35 ( L_248
L_249
L_250 ) ;
return 1 ;
}
if ( V_150 . V_213 ) {
F_35 ( L_251
L_244 ) ;
return 1 ;
}
} else {
if ( V_162 ) {
F_35 ( L_252 ) ;
return 1 ;
}
if ( V_150 . V_202 ) {
if ( V_108 != V_110 &&
V_108 != V_109 ) {
F_35 ( L_253 ) ;
return 1 ;
}
if ( V_150 . V_212 &&
V_108 != V_109 ) {
F_35 ( L_254 ) ;
return 1 ;
}
if ( V_150 . V_208 ) {
if ( strcmp ( V_150 . V_203 , L_123 ) == 0 ) {
F_35 ( L_243
L_255 ) ;
return 1 ;
}
if ( V_150 . V_214 ) {
F_35 ( L_243
L_256 ) ;
return 1 ;
}
if ( ! V_150 . V_215 &&
! V_150 . V_209 ) {
F_35 ( L_243
L_257 ) ;
return 1 ;
}
}
if ( V_115 != NULL ) {
F_35 ( L_258 ) ;
return 1 ;
}
if ( V_116 != NULL ) {
F_35 ( L_259 ) ;
return 1 ;
}
V_150 . V_216 = ( V_108 == V_109 ) ? TRUE : FALSE ;
} else {
if ( V_150 . V_215 ) {
F_35 ( L_260
L_261 ) ;
return 1 ;
}
if ( V_150 . V_208 ) {
F_35 ( L_243
L_262 ) ;
return 1 ;
}
if ( V_150 . V_212 ) {
F_35 ( L_248
L_262 ) ;
return 1 ;
}
}
}
}
#endif
#ifdef V_22
F_135 ( F_136 ( 1 , 1 ) , & V_86 ) ;
#endif
F_137 () ;
F_138 () ;
if ( ! F_139 ( V_161 ) ) {
F_35 ( L_263 ) ;
return 1 ;
}
#ifdef F_15
if ( V_150 . V_202 &&
V_150 . V_214 ) {
if ( F_140 () ) {
F_35 ( L_264 ) ;
return 1 ;
}
if ( V_131 ) {
F_35 ( L_265 ) ;
return 1 ;
}
}
#endif
if ( F_141 ( L_266 ) > 0 ) {
const T_8 * V_16 = F_142 ( L_266 ) ;
V_112 = F_143 ( V_16 ) ;
if ( V_112 == V_113 ) {
F_35 ( L_267 , V_16 ? V_16 : L_149 ) ;
F_12 () ;
return 1 ;
}
}
if ( V_89 == NULL && V_90 == NULL ) {
F_144 () ;
}
F_145 ( & V_152 . V_217 , V_121 -> V_218 , TRUE ) ;
#ifdef F_15
F_146 ( & V_150 , V_219 ) ;
F_147 ( & V_150 ) ;
#endif
if ( V_115 != NULL ) {
if ( ! F_148 ( V_115 , & V_119 ) ) {
F_35 ( L_11 , V_220 ) ;
F_125 () ;
#ifdef F_57
{
T_23 * V_221 ;
V_221 = F_149 ( V_222 , V_219 ) ;
if ( V_221 != NULL ) {
if ( F_150 ( V_221 , & V_118 , V_115 , 0 , 0 ) != - 1 ) {
F_120 (
L_268
L_269 ) ;
}
F_151 ( V_221 ) ;
}
}
#endif
return 2 ;
}
}
V_152 . V_119 = V_119 ;
if ( V_116 != NULL ) {
if ( ! F_148 ( V_116 , & V_120 ) ) {
F_35 ( L_11 , V_220 ) ;
F_125 () ;
#ifdef F_57
{
T_23 * V_221 ;
V_221 = F_149 ( V_222 , V_219 ) ;
if ( V_221 != NULL ) {
if ( F_150 ( V_221 , & V_118 , V_116 , 0 , 0 ) != - 1 ) {
F_120 (
L_270
L_269 ) ;
}
F_151 ( V_221 ) ;
}
}
#endif
return 2 ;
}
}
V_152 . V_120 = V_120 ;
if ( V_131 ) {
if ( V_190 == V_191 ) {
switch ( V_159 ) {
case V_160 :
V_223 = F_152 ( stdout ) ;
break;
case V_192 :
V_223 = F_153 ( stdout ) ;
break;
default:
F_38 () ;
}
}
}
V_224 = V_131 || V_119 || V_120 || F_140 () ;
if ( V_114 ) {
F_154 () ;
F_46 () ;
if ( F_155 ( & V_152 , V_114 , V_112 , FALSE , & V_99 ) != V_225 ) {
F_125 () ;
return 2 ;
}
switch( F_156 ( V_152 . V_226 ) ) {
case ( V_227 ) :
F_82 ( V_228 ) ;
break;
case ( V_229 ) :
F_82 ( V_230 ) ;
break;
case ( V_231 ) :
F_82 ( V_232 ) ;
break;
case ( V_233 ) :
F_82 ( V_234 ) ;
break;
case ( V_235 ) :
F_82 ( V_236 ) ;
break;
case ( V_237 ) :
F_82 ( V_238 ) ;
break;
default:
F_38 () ;
}
F_157 {
#ifdef F_15
V_99 = F_158 ( & V_152 , V_150 . V_203 , V_108 , V_111 ,
V_150 . V_239 ? V_150 . V_240 : 0 ,
V_150 . V_215 ? V_150 . V_241 : 0 ) ;
#else
V_99 = F_158 ( & V_152 , V_163 , V_108 , V_111 , 0 , 0 ) ;
#endif
}
F_159 (OutOfMemoryError) {
fprintf ( V_7 ,
L_271
L_10
L_272
L_10
L_273
L_274 ) ;
V_99 = V_242 ;
}
V_243 ;
if ( V_99 != 0 ) {
V_100 = 2 ;
}
} else {
#ifdef F_15
V_100 = F_160 ( & V_150 ,
( ( V_121 -> V_244 ) && ( * V_121 -> V_244 != '\0' ) ) ? F_161 ( V_121 -> V_244 ) : NULL ) ;
if ( V_100 != 0 )
return V_100 ;
if ( V_101 ) {
T_21 V_9 ;
for ( V_9 = 0 ; V_9 < V_150 . V_199 -> V_200 ; V_9 ++ ) {
T_22 V_201 ;
T_24 * V_245 ;
V_201 = F_130 ( V_150 . V_199 , T_22 , V_9 ) ;
V_245 = F_162 ( V_201 . V_16 , V_201 . V_246 , & V_105 , NULL ) ;
if ( V_245 == NULL ) {
F_35 ( L_11 , V_105 ) ;
F_11 ( V_105 ) ;
return 2 ;
}
if ( V_245 -> V_247 == NULL ) {
F_35 ( L_275 , V_201 . V_16 ) ;
return 2 ;
}
F_163 ( V_245 , V_201 . V_16 , V_201 . V_246 ) ;
F_164 ( V_245 ) ;
}
return 0 ;
}
if ( ! F_165 ( fileno ( V_7 ) ) )
V_248 = FALSE ;
else if ( V_131 && F_165 ( fileno ( stdout ) ) )
V_248 = FALSE ;
else if ( V_107 )
V_248 = FALSE ;
else
V_248 = TRUE ;
if ( V_131 ) {
if ( ! F_166 ( NULL ) ) {
F_167 ( V_249 ) ;
return 2 ;
}
}
F_82 ( V_236 ) ;
F_168 () ;
V_100 = V_151 . V_250 ;
if ( V_131 ) {
if ( ! F_169 () ) {
V_99 = V_249 ;
F_167 ( V_99 ) ;
}
}
#else
F_35 ( L_234 ) ;
return 2 ;
#endif
}
F_11 ( V_114 ) ;
if ( V_152 . V_251 != NULL ) {
F_170 ( V_152 . V_251 ) ;
V_152 . V_251 = NULL ;
}
F_171 ( TRUE ) ;
F_172 () ;
F_173 ( V_152 . V_252 ) ;
F_125 () ;
F_174 ( V_161 ) ;
V_161 = NULL ;
return V_100 ;
}
static T_1
F_175 ( T_3 V_5 )
{
T_25 V_28 ;
T_26 V_253 = 0 ;
T_6 V_254 ;
T_26 V_255 ;
T_27 * V_256 = V_5 ;
T_1 V_257 = 0 ;
F_176 ( V_256 -> V_258 ) ;
while( V_257 < 5 ) {
V_28 = ( T_25 ) F_177 ( V_256 -> V_259 ) ;
V_254 = F_178 ( V_28 , NULL , 0 , NULL , & V_253 , NULL ) ;
F_179 ( ( T_25 ) * ( V_256 -> V_260 ) ,
& V_255 ) ;
if ( ! V_254 || V_253 > 0 || V_255 != V_261 ) {
if ( ! V_256 -> V_262 ( V_256 -> V_259 , V_256 -> V_33 ) ) {
F_180 ( NULL , V_140 , L_276 , V_257 ) ;
F_181 ( V_256 -> V_258 ) ;
return FALSE ;
}
}
else {
break;
}
V_257 ++ ;
}
F_181 ( V_256 -> V_258 ) ;
return TRUE ;
}
void
F_182 ( T_1 V_259 , T_3 V_33 , int * V_260 , T_28 V_262 )
{
V_263 . V_259 = V_259 ;
V_263 . V_260 = V_260 ;
V_263 . V_33 = V_33 ;
V_263 . V_262 = V_262 ;
#ifdef V_22
#if F_68 ( 2 , 31 , 0 )
V_263 . V_258 = F_183 ( sizeof( V_264 ) ) ;
F_184 ( V_263 . V_258 ) ;
#else
V_263 . V_258 = F_185 () ;
#endif
V_263 . V_265 = F_186 ( 200 , F_175 , & V_263 ) ;
#endif
}
static const T_29 *
F_187 ( void * V_5 , T_11 V_266 )
{
T_30 * V_267 = ( T_30 * ) V_5 ;
if ( V_268 && V_268 -> V_269 == V_266 )
return & V_268 -> V_270 ;
if ( V_271 && V_271 -> V_269 == V_266 )
return & V_271 -> V_270 ;
if ( V_272 && V_272 -> V_269 == V_266 )
return & V_272 -> V_270 ;
if ( V_267 -> V_251 ) {
T_31 * V_273 = F_188 ( V_267 -> V_251 , V_266 ) ;
return ( V_273 ) ? & V_273 -> V_270 : NULL ;
}
return NULL ;
}
static T_32 *
F_189 ( T_30 * V_267 )
{
T_32 * V_252 = F_190 () ;
V_252 -> V_5 = V_267 ;
V_252 -> V_274 = F_187 ;
V_252 -> V_275 = V_276 ;
V_252 -> V_277 = NULL ;
return V_252 ;
}
static T_6
F_168 ( void )
{
T_6 V_278 ;
T_21 V_9 ;
T_16 * V_76 = F_62 ( L_149 ) ;
#ifdef F_191
T_33 V_279 ;
#endif
#ifndef V_22
struct V_280 V_281 , V_282 ;
#endif
F_154 () ;
F_46 () ;
F_173 ( V_152 . V_252 ) ;
V_152 . V_252 = F_189 ( & V_152 ) ;
#ifdef V_22
F_192 ( V_283 , TRUE ) ;
#else
memset ( & V_281 , 0 , sizeof( V_281 ) ) ;
V_281 . V_284 = V_283 ;
V_281 . V_285 = V_286 ;
F_193 ( & V_281 . V_287 ) ;
V_280 ( V_288 , & V_281 , NULL ) ;
V_280 ( V_289 , & V_281 , NULL ) ;
V_280 ( V_290 , NULL , & V_282 ) ;
if ( V_282 . V_284 == V_291 )
V_280 ( V_290 , & V_281 , NULL ) ;
#ifdef F_194
V_281 . V_284 = V_292 ;
V_281 . V_285 = V_286 ;
F_193 ( & V_281 . V_287 ) ;
V_280 ( F_194 , & V_281 , NULL ) ;
#endif
#endif
V_151 . V_293 = V_294 ;
for ( V_9 = 0 ; V_9 < V_150 . V_199 -> V_200 ; V_9 ++ ) {
T_22 V_201 ;
V_201 = F_130 ( V_150 . V_199 , T_22 , V_9 ) ;
V_201 . V_295 = F_195 ( V_201 . V_16 ) ;
V_150 . V_199 = F_131 ( V_150 . V_199 , V_9 ) ;
F_132 ( V_150 . V_199 , V_9 , V_201 ) ;
}
#ifdef V_22
if ( V_150 . V_199 -> V_200 < 2 )
#else
if ( V_150 . V_199 -> V_200 < 4 )
#endif
{
for ( V_9 = 0 ; V_9 < V_150 . V_199 -> V_200 ; V_9 ++ ) {
T_22 V_201 ;
V_201 = F_130 ( V_150 . V_199 , T_22 , V_9 ) ;
if ( V_9 > 0 ) {
if ( V_150 . V_199 -> V_200 > 2 ) {
F_196 ( V_76 , L_237 ) ;
}
F_196 ( V_76 , L_277 ) ;
if ( V_9 == V_150 . V_199 -> V_200 - 1 ) {
F_196 ( V_76 , L_278 ) ;
}
}
F_196 ( V_76 , L_279 , V_201 . V_295 ) ;
}
} else {
F_196 ( V_76 , L_280 , V_150 . V_199 -> V_200 ) ;
}
if ( V_179 == FALSE )
fprintf ( V_7 , L_281 , V_76 -> V_76 ) ;
fflush ( V_7 ) ;
F_124 ( V_76 , TRUE ) ;
V_278 = F_197 ( & V_150 , & V_151 , NULL ) ;
if ( ! V_278 )
return FALSE ;
#ifdef F_191
F_198 ( & V_279 ) ;
F_199 ( V_263 . V_259 , & V_279 ) ;
#endif
V_296 = TRUE ;
F_157
{
while ( V_296 )
{
#ifdef F_191
V_278 = F_200 ( V_263 . V_259 + 1 , & V_279 , NULL , NULL , NULL ) ;
if ( V_278 == - 1 )
{
fprintf ( V_7 , L_282 , L_283 , F_106 ( V_249 ) ) ;
return TRUE ;
} else if ( V_278 == 1 ) {
#endif
if ( ! V_263 . V_262 ( V_263 . V_259 , V_263 . V_33 ) ) {
F_180 ( NULL , V_140 , L_284 ) ;
return FALSE ;
}
#ifdef F_191
}
#endif
}
}
F_159 (OutOfMemoryError) {
fprintf ( V_7 ,
L_271
L_10
L_272
L_10
L_273
L_274 ) ;
exit ( 1 ) ;
}
V_243 ;
return TRUE ;
}
void
F_201 ( T_34 * T_35 V_6 , char * V_297 , char * V_298 )
{
F_35 ( L_11 , V_297 ) ;
F_120 ( L_11 , V_298 ) ;
}
void
F_202 ( T_34 * T_35 , T_21 V_9 , char * V_299 )
{
T_36 * V_300 = T_35 -> V_300 ;
T_19 * V_119 = NULL ;
T_22 V_201 ;
F_26 ( V_9 < V_300 -> V_199 -> V_200 ) ;
V_201 = F_130 ( V_300 -> V_199 , T_22 , V_9 ) ;
if ( F_148 ( V_201 . V_198 , & V_119 ) && V_119 != NULL ) {
F_35 (
L_285
L_10
L_286
L_287
L_10
L_288
L_289
L_10
L_290 ,
V_201 . V_198 , V_201 . V_295 , V_299 ) ;
F_203 ( V_119 ) ;
} else {
F_35 (
L_285
L_10
L_291
L_290 ,
V_201 . V_198 , V_201 . V_295 , V_299 ) ;
}
}
T_6
F_204 ( T_34 * T_35 , T_8 * V_301 )
{
T_36 * V_300 = T_35 -> V_300 ;
T_6 V_302 ;
int V_99 ;
if ( T_35 -> V_293 == V_294 ) {
F_180 ( V_144 , V_138 , L_292 ) ;
}
F_180 ( V_144 , V_138 , L_293 , V_301 ) ;
F_26 ( T_35 -> V_293 == V_294 || T_35 -> V_293 == V_303 ) ;
if ( V_300 -> V_203 != NULL ) {
if ( ( ( T_30 * ) T_35 -> V_267 ) -> V_293 != V_304 ) {
if ( ( ( T_30 * ) T_35 -> V_267 ) -> V_226 != NULL ) {
F_205 ( ( ( T_30 * ) T_35 -> V_267 ) -> V_226 ) ;
( ( T_30 * ) T_35 -> V_267 ) -> V_226 = NULL ;
}
( ( T_30 * ) T_35 -> V_267 ) -> V_293 = V_304 ;
}
F_11 ( V_300 -> V_203 ) ;
V_302 = FALSE ;
} else {
V_302 = TRUE ;
}
V_300 -> V_203 = F_34 ( V_301 ) ;
if ( V_224 ) {
( ( T_30 * ) T_35 -> V_267 ) -> V_305 = V_113 ;
switch( F_155 ( ( T_30 * ) T_35 -> V_267 , V_300 -> V_203 , V_113 , V_302 , & V_99 ) ) {
case V_225 :
break;
case V_306 :
F_11 ( V_300 -> V_203 ) ;
V_300 -> V_203 = NULL ;
return FALSE ;
}
}
T_35 -> V_293 = V_303 ;
return TRUE ;
}
void
F_206 ( T_34 * T_35 , int V_307 )
{
T_6 V_278 ;
int V_99 ;
T_8 * V_308 ;
T_37 V_309 ;
T_30 * V_267 = ( T_30 * ) T_35 -> V_267 ;
T_6 V_310 ;
T_21 V_311 ;
#ifdef F_194
V_312 = TRUE ;
#endif
V_310 = F_207 () ;
V_311 = F_208 () ;
if ( V_224 ) {
T_6 V_313 ;
T_38 * V_314 ;
if ( V_267 -> V_119 || V_267 -> V_120 || V_133 || V_310 ||
( V_311 & V_315 ) || F_209 ( & V_267 -> V_217 ) )
V_313 = TRUE ;
else
V_313 = FALSE ;
V_314 = F_210 ( V_267 -> V_252 , V_313 , V_131 && V_133 ) ;
while ( V_307 -- && V_267 -> V_226 ) {
F_211 ( V_267 -> V_226 ) ;
V_278 = F_212 ( V_267 -> V_226 , & V_99 , & V_308 , & V_309 ) ;
if ( V_278 == FALSE ) {
F_213 ( T_35 ) ;
F_205 ( V_267 -> V_226 ) ;
V_267 -> V_226 = NULL ;
} else {
V_278 = F_214 ( V_267 , V_314 , V_309 , F_215 ( V_267 -> V_226 ) ,
F_216 ( V_267 -> V_226 ) ,
V_311 ) ;
}
if ( V_278 != FALSE ) {
V_316 ++ ;
}
}
F_217 ( V_314 ) ;
} else {
V_316 += V_307 ;
}
if ( V_248 ) {
if ( V_316 != 0 ) {
fprintf ( V_7 , L_294 , V_316 ) ;
fflush ( V_7 ) ;
}
}
#ifdef F_194
V_312 = FALSE ;
if ( V_317 )
F_218 () ;
#endif
}
static void
F_218 ( void )
{
if ( ( V_248 == FALSE ) && ( V_179 == FALSE ) ) {
fprintf ( V_7 , L_295 , V_316 ,
F_219 ( V_316 , L_149 , L_215 ) ) ;
}
#ifdef F_194
V_317 = FALSE ;
#endif
}
static void
V_292 ( int T_39 V_6 )
{
int V_318 = V_249 ;
if ( V_312 )
V_317 = TRUE ;
else
F_218 () ;
V_249 = V_318 ;
}
void
F_220 ( T_34 * T_35 V_6 , T_11 V_319 )
{
if ( V_248 ) {
fprintf ( V_7 , L_10 ) ;
}
if ( V_319 != 0 ) {
fprintf ( V_7 , L_296 , V_319 , F_219 ( V_319 , L_149 , L_215 ) ) ;
}
}
void
F_221 ( T_34 * T_35 , T_8 * V_320 )
{
T_30 * V_267 = ( T_30 * ) T_35 -> V_267 ;
if ( V_320 != NULL )
fprintf ( V_7 , L_297 , V_320 ) ;
F_218 () ;
if ( V_267 != NULL && V_267 -> V_226 != NULL ) {
F_205 ( V_267 -> V_226 ) ;
if ( V_267 -> V_302 ) {
F_222 ( V_267 -> V_321 ) ;
}
}
#ifdef F_223
F_224 ( V_322 ) ;
#else
V_296 = FALSE ;
#endif
}
static BOOL T_40
V_283 ( T_26 T_41 V_6 )
{
F_213 ( & V_151 ) ;
return TRUE ;
}
static void
V_283 ( int T_39 V_6 )
{
F_213 ( & V_151 ) ;
}
static T_6
F_225 ( T_30 * V_267 , T_38 * V_314 ,
T_37 V_323 , struct V_324 * V_325 ,
const T_42 * V_326 )
{
T_31 V_327 ;
T_11 V_328 ;
T_6 V_329 ;
V_328 = V_267 -> V_330 + 1 ;
V_329 = TRUE ;
F_226 ( & V_327 , V_328 , V_325 , V_323 , V_331 ) ;
if ( V_314 ) {
if ( V_170 . V_171 || V_170 . V_172 ||
V_170 . V_173 || V_170 . V_174 )
F_227 () ;
if ( V_267 -> V_119 )
F_228 ( V_314 , V_267 -> V_119 ) ;
if ( V_267 -> V_120 )
F_228 ( V_314 , V_267 -> V_120 ) ;
F_229 ( & V_327 , & V_267 -> V_332 ,
& V_268 , V_271 ) ;
if ( V_268 == & V_327 ) {
V_333 = V_327 ;
V_268 = & V_333 ;
}
F_230 ( V_314 , V_267 -> V_334 , V_325 , F_231 ( & V_327 , V_326 ) , & V_327 , NULL ) ;
if ( V_267 -> V_119 )
V_329 = F_232 ( V_267 -> V_119 , V_314 ) ;
}
if ( V_329 ) {
F_233 ( & V_327 , & V_331 ) ;
V_272 = V_271 = F_234 ( V_267 -> V_251 , & V_327 ) ;
if ( V_314 && V_267 -> V_120 ) {
if ( F_232 ( V_267 -> V_120 , V_314 ) ) {
F_9 ( V_314 -> V_335 . V_336 , V_337 , V_267 -> V_251 ) ;
}
}
V_267 -> V_330 ++ ;
} else {
F_235 ( & V_327 ) ;
}
if ( V_314 )
F_236 ( V_314 ) ;
return V_329 ;
}
static T_6
F_237 ( T_30 * V_267 , T_38 * V_314 , T_31 * V_338 ,
struct V_324 * V_339 , T_43 * V_340 ,
T_21 V_311 )
{
T_44 * V_217 ;
T_6 V_329 ;
V_329 = TRUE ;
if ( V_314 ) {
if ( V_170 . V_171 || V_170 . V_172 ||
V_170 . V_173 || V_170 . V_174 )
F_227 () ;
if ( V_267 -> V_120 )
F_228 ( V_314 , V_267 -> V_120 ) ;
F_238 ( V_314 , & V_267 -> V_217 ) ;
if ( ( V_311 & V_341 ) || ( V_131 && V_132 ) )
V_217 = & V_267 -> V_217 ;
else
V_217 = NULL ;
F_229 ( V_338 , & V_267 -> V_332 ,
& V_268 , V_271 ) ;
if ( V_268 == V_338 ) {
V_333 = * V_338 ;
V_268 = & V_333 ;
}
F_239 ( V_314 , V_267 -> V_334 , V_339 , F_240 ( V_338 , V_340 ) , V_338 , V_217 ) ;
if ( V_267 -> V_120 )
V_329 = F_232 ( V_267 -> V_120 , V_314 ) ;
}
if ( V_329 ) {
F_233 ( V_338 , & V_331 ) ;
if ( V_131 ) {
F_241 ( V_267 , V_314 ) ;
if ( V_169 )
fflush ( stdout ) ;
if ( ferror ( stdout ) ) {
F_167 ( V_249 ) ;
exit ( 2 ) ;
}
}
V_271 = V_338 ;
}
V_272 = V_338 ;
if ( V_314 ) {
F_236 ( V_314 ) ;
}
return V_329 || V_338 -> V_342 . V_343 ;
}
static int
F_158 ( T_30 * V_267 , char * V_203 , int V_108 ,
T_6 V_111 , int V_344 , T_37 V_345 )
{
T_1 V_346 ;
int V_347 ;
T_45 * V_348 ;
T_11 V_328 ;
int V_99 ;
T_8 * V_308 = NULL ;
T_37 V_309 ;
char * V_71 = NULL ;
T_6 V_310 ;
T_21 V_311 ;
T_46 * V_349 ;
T_47 * V_350 ;
char V_351 [ 100 ] ;
struct V_324 V_339 ;
T_43 V_340 ;
T_38 * V_314 = NULL ;
memset ( & V_339 , 0 , sizeof( struct V_324 ) ) ;
V_349 = F_242 ( V_267 -> V_226 ) ;
V_350 = F_243 ( V_267 -> V_226 ) ;
#ifdef F_56
if ( V_350 -> V_352 -> V_200 > 1 ) {
V_346 = V_353 ;
} else {
V_346 = F_244 ( V_267 -> V_226 ) ;
}
#else
V_346 = F_244 ( V_267 -> V_226 ) ;
#endif
if ( V_203 != NULL ) {
V_71 = F_44 ( V_203 ) ;
V_347 = F_245 ( V_267 -> V_226 ) ;
if ( V_347 == 0 ) {
V_347 = V_354 ;
}
if ( V_349 -> V_355 == NULL ) {
F_246 ( V_351 , sizeof( V_351 ) , L_6 V_20 L_11 , V_21 ) ;
V_349 -> V_355 = V_351 ;
}
if ( V_346 != V_353 &&
V_108 == V_110 )
V_348 = F_247 ( V_203 , V_108 , V_346 ,
V_347 , FALSE , & V_99 ) ;
else
V_348 = F_248 ( V_203 , V_108 , V_346 ,
V_347 , FALSE , V_349 , V_350 , & V_99 ) ;
F_11 ( V_350 ) ;
V_350 = NULL ;
if ( V_348 == NULL ) {
switch ( V_99 ) {
case V_356 :
F_35 ( L_298 ) ;
break;
case V_357 :
case V_358 :
F_35 ( L_299
L_300 , F_6 ( V_108 ) ) ;
break;
case V_359 :
F_35 ( L_301
L_302 , V_71 ) ;
break;
case V_360 :
F_35 ( L_303 ,
V_71 ) ;
break;
default:
F_35 ( L_304 , V_71 ,
F_249 ( V_99 ) ) ;
break;
}
goto V_361;
}
} else {
if ( V_131 ) {
if ( ! F_166 ( V_267 ) ) {
V_99 = V_249 ;
F_167 ( V_99 ) ;
goto V_361;
}
}
F_11 ( V_350 ) ;
V_350 = NULL ;
V_348 = NULL ;
}
if ( V_348 && V_111 ) {
if ( ! F_250 ( V_348 , F_251 () ) ) {
F_35 ( L_305 ,
F_6 ( V_108 ) ) ;
}
}
V_310 = F_207 () ;
V_311 = F_208 () ;
if ( V_162 ) {
T_31 * V_338 ;
V_267 -> V_251 = F_252 () ;
if ( V_224 ) {
T_6 V_313 = FALSE ;
if ( V_267 -> V_119 || V_267 -> V_120 )
V_313 = TRUE ;
V_314 = F_210 ( V_267 -> V_252 , V_313 , FALSE ) ;
}
while ( F_212 ( V_267 -> V_226 , & V_99 , & V_308 , & V_309 ) ) {
if ( F_225 ( V_267 , V_314 , V_309 , F_215 ( V_267 -> V_226 ) ,
F_216 ( V_267 -> V_226 ) ) ) {
if ( ( -- V_344 == 0 ) || ( V_345 != 0 && V_309 >= V_345 ) ) {
V_99 = 0 ;
break;
}
}
}
if ( V_314 ) {
F_217 ( V_314 ) ;
V_314 = NULL ;
}
F_253 ( V_267 -> V_226 ) ;
F_254 () ;
V_271 = NULL ;
V_272 = NULL ;
F_255 ( & V_340 , 1500 ) ;
if ( V_224 ) {
T_6 V_313 ;
if ( V_267 -> V_120 || V_133 || V_310 ||
( V_311 & V_315 ) || F_209 ( & V_267 -> V_217 ) )
V_313 = TRUE ;
else
V_313 = FALSE ;
V_314 = F_210 ( V_267 -> V_252 , V_313 , V_131 && V_133 ) ;
}
for ( V_328 = 1 ; V_99 == 0 && V_328 <= V_267 -> V_330 ; V_328 ++ ) {
V_338 = F_188 ( V_267 -> V_251 , V_328 ) ;
if ( F_256 ( V_267 -> V_226 , V_338 -> V_362 , & V_339 , & V_340 , & V_99 ,
& V_308 ) ) {
if ( F_237 ( V_267 , V_314 , V_338 , & V_339 , & V_340 ,
V_311 ) ) {
if ( V_348 != NULL ) {
if ( ! F_257 ( V_348 , & V_339 , F_258 ( & V_340 ) , & V_99 ) ) {
switch ( V_99 ) {
case V_357 :
fprintf ( V_7 ,
L_306 ,
V_328 , V_267 -> V_321 ,
F_6 ( V_108 ) ) ;
break;
case V_363 :
fprintf ( V_7 ,
L_307 ,
V_328 , V_267 -> V_321 ,
F_6 ( V_108 ) ) ;
break;
default:
F_259 ( V_203 , V_99 , FALSE ) ;
break;
}
F_260 ( V_348 , & V_99 ) ;
F_11 ( V_349 ) ;
exit ( 2 ) ;
}
}
}
}
}
if ( V_314 ) {
F_217 ( V_314 ) ;
V_314 = NULL ;
}
F_261 ( & V_340 ) ;
}
else {
V_328 = 0 ;
if ( V_224 ) {
T_6 V_313 ;
if ( V_267 -> V_119 || V_267 -> V_120 || V_133 || V_310 ||
( V_311 & V_315 ) || F_209 ( & V_267 -> V_217 ) )
V_313 = TRUE ;
else
V_313 = FALSE ;
V_314 = F_210 ( V_267 -> V_252 , V_313 , V_131 && V_133 ) ;
}
while ( F_212 ( V_267 -> V_226 , & V_99 , & V_308 , & V_309 ) ) {
V_328 ++ ;
if ( F_214 ( V_267 , V_314 , V_309 , F_215 ( V_267 -> V_226 ) ,
F_216 ( V_267 -> V_226 ) ,
V_311 ) ) {
if ( V_348 != NULL ) {
if ( ! F_257 ( V_348 , F_215 ( V_267 -> V_226 ) , F_216 ( V_267 -> V_226 ) , & V_99 ) ) {
switch ( V_99 ) {
case V_357 :
fprintf ( V_7 ,
L_306 ,
V_328 , V_267 -> V_321 ,
F_6 ( V_108 ) ) ;
break;
case V_363 :
fprintf ( V_7 ,
L_307 ,
V_328 , V_267 -> V_321 ,
F_6 ( V_108 ) ) ;
break;
default:
F_259 ( V_203 , V_99 , FALSE ) ;
break;
}
F_260 ( V_348 , & V_99 ) ;
F_11 ( V_349 ) ;
exit ( 2 ) ;
}
}
}
if ( ( -- V_344 == 0 ) || ( V_345 != 0 && V_309 >= V_345 ) ) {
V_99 = 0 ;
break;
}
}
if ( V_314 ) {
F_217 ( V_314 ) ;
V_314 = NULL ;
}
}
if ( V_99 != 0 ) {
#ifndef V_22
if ( V_131 ) {
struct V_364 V_365 , V_366 ;
if ( F_262 ( 1 , & V_365 ) == 0 && F_262 ( 2 , & V_366 ) == 0 ) {
if ( V_365 . V_367 == V_366 . V_367 &&
V_365 . V_368 == V_366 . V_368 ) {
fflush ( stdout ) ;
fprintf ( V_7 , L_10 ) ;
}
}
}
#endif
switch ( V_99 ) {
case V_369 :
F_35 ( L_308 ,
V_267 -> V_321 , V_308 ) ;
F_11 ( V_308 ) ;
break;
case V_357 :
F_35 ( L_309 ,
V_267 -> V_321 , V_308 ) ;
F_11 ( V_308 ) ;
break;
case V_370 :
F_35 ( L_310 ,
V_267 -> V_321 ) ;
break;
case V_371 :
F_35 ( L_311 ,
V_267 -> V_321 ) ;
break;
case V_372 :
F_35 ( L_312 ,
V_267 -> V_321 , V_308 ) ;
F_11 ( V_308 ) ;
break;
case V_373 :
F_35 ( L_313
L_314 , V_267 -> V_321 , V_308 ) ;
break;
default:
F_35 ( L_315 ,
V_267 -> V_321 , F_249 ( V_99 ) ) ;
break;
}
if ( V_203 != NULL ) {
if ( ! F_260 ( V_348 , & V_99 ) )
F_259 ( V_203 , V_99 , TRUE ) ;
}
} else {
if ( V_203 != NULL ) {
if ( ! F_260 ( V_348 , & V_99 ) )
F_259 ( V_203 , V_99 , TRUE ) ;
} else {
if ( V_131 ) {
if ( ! F_169 () ) {
V_99 = V_249 ;
F_167 ( V_99 ) ;
}
}
}
}
V_361:
F_205 ( V_267 -> V_226 ) ;
V_267 -> V_226 = NULL ;
F_11 ( V_71 ) ;
F_11 ( V_349 ) ;
return V_99 ;
}
static T_6
F_214 ( T_30 * V_267 , T_38 * V_314 , T_37 V_323 , struct V_324 * V_325 ,
const T_42 * V_326 , T_21 V_311 )
{
T_31 V_338 ;
T_44 * V_217 ;
T_6 V_329 ;
V_267 -> V_330 ++ ;
V_329 = TRUE ;
F_226 ( & V_338 , V_267 -> V_330 , V_325 , V_323 , V_331 ) ;
if ( V_314 ) {
if ( V_131 && ( V_170 . V_171 || V_170 . V_172 ||
V_170 . V_173 || V_170 . V_174 ) )
F_227 () ;
if ( V_267 -> V_120 )
F_228 ( V_314 , V_267 -> V_120 ) ;
F_238 ( V_314 , & V_267 -> V_217 ) ;
if ( ( V_311 & V_341 ) || ( V_131 && V_132 ) || F_263 ( V_161 ) )
V_217 = & V_267 -> V_217 ;
else
V_217 = NULL ;
F_229 ( & V_338 , & V_267 -> V_332 ,
& V_268 , V_271 ) ;
if ( V_268 == & V_338 ) {
V_333 = V_338 ;
V_268 = & V_333 ;
}
F_239 ( V_314 , V_267 -> V_334 , V_325 , F_231 ( & V_338 , V_326 ) , & V_338 , V_217 ) ;
if ( V_267 -> V_120 )
V_329 = F_232 ( V_267 -> V_120 , V_314 ) ;
}
if ( V_329 ) {
F_233 ( & V_338 , & V_331 ) ;
if ( V_131 ) {
F_241 ( V_267 , V_314 ) ;
if ( V_169 )
fflush ( stdout ) ;
if ( ferror ( stdout ) ) {
F_167 ( V_249 ) ;
exit ( 2 ) ;
}
}
V_374 = V_338 ;
V_271 = & V_374 ;
}
V_375 = V_338 ;
V_272 = & V_375 ;
if ( V_314 ) {
F_236 ( V_314 ) ;
F_235 ( & V_338 ) ;
}
return V_329 ;
}
static T_6
F_166 ( T_30 * V_267 )
{
switch ( V_190 ) {
case V_191 :
return F_264 ( V_223 , V_267 ? V_267 -> V_321 : NULL , V_21 ) ;
case V_193 :
if ( V_133 )
F_265 ( stdout , V_267 ? V_267 -> V_321 : NULL ) ;
else
F_266 ( stdout ) ;
return ! ferror ( stdout ) ;
case V_194 :
F_267 ( V_161 , stdout ) ;
return ! ferror ( stdout ) ;
default:
F_38 () ;
return FALSE ;
}
}
static char *
F_268 ( T_48 V_200 )
{
static char * V_376 = NULL ;
static T_48 V_377 = 256 ;
T_48 V_378 ;
for ( V_378 = V_377 ; V_200 > V_378 ;
V_378 *= 2 )
;
if ( V_376 == NULL ) {
V_377 = V_378 ;
V_376 = ( char * ) F_183 ( V_377 + 1 ) ;
} else {
if ( V_378 > V_377 ) {
V_377 = V_378 ;
V_376 = ( char * ) F_269 ( V_376 , V_377 + 1 ) ;
}
}
return V_376 ;
}
static inline void
F_270 ( char * V_379 , const char * V_76 , T_48 V_380 )
{
memcpy ( V_379 , V_76 , V_380 ) ;
V_379 [ V_380 ] = '\0' ;
}
static inline void
F_271 ( char * V_379 , const char * V_76 , T_48 V_380 , T_48 V_381 )
{
T_48 V_9 ;
for ( V_9 = V_380 ; V_9 < V_381 ; V_9 ++ )
* V_379 ++ = ' ' ;
F_270 ( V_379 , V_76 , V_380 ) ;
}
static inline void
F_272 ( char * V_379 , const char * V_76 , T_48 V_380 , T_48 V_381 )
{
T_48 V_9 ;
memcpy ( V_379 , V_76 , V_380 ) ;
for ( V_9 = V_380 ; V_9 < V_381 ; V_9 ++ )
V_379 [ V_9 ] = ' ' ;
V_379 [ V_381 ] = '\0' ;
}
static T_6
F_273 ( T_30 * V_267 )
{
char * V_376 ;
int V_9 ;
T_48 V_382 ;
T_48 V_383 ;
T_48 V_384 ;
V_376 = F_268 ( 256 ) ;
V_382 = 0 ;
* V_376 = '\0' ;
for ( V_9 = 0 ; V_9 < V_267 -> V_217 . V_218 ; V_9 ++ ) {
if ( ! F_274 ( V_9 ) )
continue;
switch ( V_267 -> V_217 . V_385 [ V_9 ] ) {
case V_386 :
V_383 = V_384 = strlen ( V_267 -> V_217 . V_387 [ V_9 ] ) ;
if ( V_383 < 3 )
V_383 = 3 ;
V_376 = F_268 ( V_382 + V_383 ) ;
F_271 ( V_376 + V_382 , V_267 -> V_217 . V_387 [ V_9 ] , V_384 , V_383 ) ;
break;
case V_388 :
case V_389 :
case V_390 :
case V_391 :
case V_392 :
case V_393 :
case V_394 :
case V_395 :
V_383 = V_384 = strlen ( V_267 -> V_217 . V_387 [ V_9 ] ) ;
if ( V_383 < 10 )
V_383 = 10 ;
V_376 = F_268 ( V_382 + V_383 ) ;
F_271 ( V_376 + V_382 , V_267 -> V_217 . V_387 [ V_9 ] , V_384 , V_383 ) ;
break;
case V_396 :
case V_397 :
case V_398 :
case V_399 :
case V_400 :
case V_401 :
case V_402 :
case V_403 :
case V_404 :
V_383 = V_384 = strlen ( V_267 -> V_217 . V_387 [ V_9 ] ) ;
if ( V_383 < 12 )
V_383 = 12 ;
V_376 = F_268 ( V_382 + V_383 ) ;
F_271 ( V_376 + V_382 , V_267 -> V_217 . V_387 [ V_9 ] , V_384 , V_383 ) ;
break;
case V_405 :
case V_406 :
case V_407 :
case V_408 :
case V_409 :
case V_410 :
case V_411 :
case V_412 :
case V_413 :
V_383 = V_384 = strlen ( V_267 -> V_217 . V_387 [ V_9 ] ) ;
if ( V_383 < 12 )
V_383 = 12 ;
V_376 = F_268 ( V_382 + V_383 ) ;
F_272 ( V_376 + V_382 , V_267 -> V_217 . V_387 [ V_9 ] , V_384 , V_383 ) ;
break;
default:
V_383 = strlen ( V_267 -> V_217 . V_387 [ V_9 ] ) ;
V_376 = F_268 ( V_382 + V_383 ) ;
F_270 ( V_376 + V_382 , V_267 -> V_217 . V_387 [ V_9 ] , V_383 ) ;
break;
}
V_382 += V_383 ;
if ( V_9 != V_267 -> V_217 . V_218 - 1 ) {
V_376 = F_268 ( V_382 + 4 ) ;
switch ( V_267 -> V_217 . V_385 [ V_9 ] ) {
case V_396 :
case V_397 :
case V_398 :
switch ( V_267 -> V_217 . V_385 [ V_9 + 1 ] ) {
case V_405 :
case V_406 :
case V_407 :
F_270 ( V_376 + V_382 , L_316 , 4 ) ;
V_382 += 4 ;
break;
default:
F_270 ( V_376 + V_382 , L_277 , 1 ) ;
V_382 += 1 ;
break;
}
break;
case V_399 :
case V_400 :
case V_401 :
switch ( V_267 -> V_217 . V_385 [ V_9 + 1 ] ) {
case V_408 :
case V_409 :
case V_410 :
F_270 ( V_376 + V_382 , L_316 , 4 ) ;
V_382 += 4 ;
break;
default:
F_270 ( V_376 + V_382 , L_277 , 1 ) ;
V_382 += 1 ;
break;
}
break;
case V_402 :
case V_403 :
case V_404 :
switch ( V_267 -> V_217 . V_385 [ V_9 + 1 ] ) {
case V_411 :
case V_412 :
case V_413 :
F_270 ( V_376 + V_382 , L_316 , 4 ) ;
V_382 += 4 ;
break;
default:
F_270 ( V_376 + V_382 , L_277 , 1 ) ;
V_382 += 1 ;
break;
}
break;
case V_405 :
case V_406 :
case V_407 :
switch ( V_267 -> V_217 . V_385 [ V_9 + 1 ] ) {
case V_396 :
case V_397 :
case V_398 :
F_270 ( V_376 + V_382 , L_317 , 4 ) ;
V_382 += 4 ;
break;
default:
F_270 ( V_376 + V_382 , L_277 , 1 ) ;
V_382 += 1 ;
break;
}
break;
case V_408 :
case V_409 :
case V_410 :
switch ( V_267 -> V_217 . V_385 [ V_9 + 1 ] ) {
case V_399 :
case V_400 :
case V_401 :
F_270 ( V_376 + V_382 , L_317 , 4 ) ;
V_382 += 4 ;
break;
default:
F_270 ( V_376 + V_382 , L_277 , 1 ) ;
V_382 += 1 ;
break;
}
break;
case V_411 :
case V_412 :
case V_413 :
switch ( V_267 -> V_217 . V_385 [ V_9 + 1 ] ) {
case V_402 :
case V_403 :
case V_404 :
F_270 ( V_376 + V_382 , L_317 , 4 ) ;
V_382 += 4 ;
break;
default:
F_270 ( V_376 + V_382 , L_277 , 1 ) ;
V_382 += 1 ;
break;
}
break;
default:
F_270 ( V_376 + V_382 , L_277 , 1 ) ;
V_382 += 1 ;
break;
}
}
}
return F_275 ( V_223 , 0 , V_376 ) ;
}
static T_6
F_241 ( T_30 * V_267 , T_38 * V_314 )
{
T_49 V_414 ;
if ( V_132 || F_263 ( V_161 ) ) {
F_276 ( V_314 , FALSE , TRUE ) ;
if ( V_132 ) {
switch ( V_190 ) {
case V_191 :
if ( ! F_273 ( V_267 ) )
return FALSE ;
break;
case V_193 :
F_277 ( V_314 , stdout ) ;
return ! ferror ( stdout ) ;
case V_194 :
F_38 () ;
break;
}
}
}
if ( V_133 ) {
switch ( V_190 ) {
case V_191 :
V_414 . V_134 = V_134 ;
V_414 . V_415 = V_133 ? V_416 : V_417 ;
if ( ! F_278 ( & V_414 , V_314 , V_223 ) )
return FALSE ;
if ( ! V_134 ) {
if ( ! F_275 ( V_223 , 0 , V_180 ) )
return FALSE ;
}
break;
case V_193 :
F_279 ( V_314 , stdout ) ;
printf ( L_10 ) ;
return ! ferror ( stdout ) ;
case V_194 :
F_280 ( V_161 , V_314 , & V_267 -> V_217 , stdout ) ;
printf ( L_10 ) ;
return ! ferror ( stdout ) ;
}
}
if ( V_134 ) {
if ( V_132 || V_133 ) {
if ( ! F_275 ( V_223 , 0 , L_149 ) )
return FALSE ;
}
if ( ! F_281 ( V_223 , V_314 ) )
return FALSE ;
if ( ! F_275 ( V_223 , 0 , V_180 ) )
return FALSE ;
}
return TRUE ;
}
static T_6
F_169 ( void )
{
switch ( V_190 ) {
case V_191 :
return F_282 ( V_223 ) ;
case V_193 :
if ( V_133 )
F_283 ( stdout ) ;
else
F_284 ( stdout ) ;
return ! ferror ( stdout ) ;
case V_194 :
F_285 ( V_161 , stdout ) ;
return ! ferror ( stdout ) ;
default:
F_38 () ;
return FALSE ;
}
}
T_50
F_155 ( T_30 * V_267 , const char * V_70 , unsigned int type , T_6 V_302 , int * V_99 )
{
T_51 * V_226 ;
T_8 * V_308 ;
char V_418 [ 2048 + 1 ] ;
V_226 = F_286 ( V_70 , type , V_99 , & V_308 , V_162 ) ;
if ( V_226 == NULL )
goto V_419;
F_173 ( V_267 -> V_252 ) ;
V_267 -> V_252 = F_189 ( V_267 ) ;
V_267 -> V_226 = V_226 ;
V_267 -> V_420 = 0 ;
V_267 -> V_321 = F_34 ( V_70 ) ;
V_267 -> V_302 = V_302 ;
V_267 -> V_421 = FALSE ;
V_267 -> V_334 = F_287 ( V_267 -> V_226 ) ;
V_267 -> V_305 = type ;
V_267 -> V_330 = 0 ;
V_267 -> V_422 = FALSE ;
V_267 -> V_423 = 0 ;
V_267 -> V_424 = F_245 ( V_267 -> V_226 ) ;
if ( V_267 -> V_424 == 0 ) {
V_267 -> V_425 = FALSE ;
V_267 -> V_424 = V_354 ;
} else
V_267 -> V_425 = TRUE ;
F_288 ( & V_267 -> V_332 ) ;
V_268 = NULL ;
V_271 = NULL ;
V_272 = NULL ;
V_267 -> V_293 = V_426 ;
F_289 ( V_267 -> V_226 , V_427 ) ;
F_290 ( V_267 -> V_226 , ( V_428 ) V_429 ) ;
return V_225 ;
V_419:
F_246 ( V_418 , sizeof V_418 ,
F_291 ( * V_99 , V_308 , FALSE , V_267 -> V_334 ) , V_70 ) ;
F_35 ( L_11 , V_418 ) ;
return V_306 ;
}
static void
F_259 ( const char * V_70 , int V_99 , T_6 V_430 )
{
char * V_71 ;
V_71 = F_44 ( V_70 ) ;
switch ( V_99 ) {
case V_431 :
F_35 ( L_318
L_319 ,
V_71 ) ;
break;
#ifdef F_292
case F_292 :
F_35 ( L_320
L_321 ,
V_71 ) ;
break;
#endif
case V_432 :
F_35 ( L_322 ,
V_71 ) ;
break;
case V_360 :
F_35 ( L_323 ,
V_71 ) ;
break;
default:
if ( V_430 ) {
F_35 ( L_324 , V_71 ,
F_249 ( V_99 ) ) ;
} else {
F_35 ( L_325 ,
V_71 , F_249 ( V_99 ) ) ;
}
break;
}
F_11 ( V_71 ) ;
}
static void
F_167 ( int V_99 )
{
switch ( V_99 ) {
case V_431 :
F_35 ( L_326
L_319 ) ;
break;
#ifdef F_292
case F_292 :
F_35 ( L_327
L_321 ) ;
break;
#endif
default:
F_35 ( L_328 ,
F_106 ( V_99 ) ) ;
break;
}
}
static const char *
F_291 ( int V_99 , T_8 * V_308 , T_6 V_433 ,
int V_434 )
{
const char * V_435 ;
static char V_436 [ 1024 + 1 ] ;
if ( V_99 < 0 ) {
switch ( V_99 ) {
case V_437 :
V_435 = L_329 ;
break;
case V_438 :
V_435 = L_330 ;
break;
case V_439 :
V_435 = L_331 ;
break;
case V_369 :
F_246 ( V_436 , sizeof( V_436 ) ,
L_332
L_314 , V_308 ) ;
F_11 ( V_308 ) ;
V_435 = V_436 ;
break;
case V_440 :
F_246 ( V_436 , sizeof( V_436 ) ,
L_333
L_334 , F_6 ( V_434 ) ) ;
V_435 = V_436 ;
break;
case V_356 :
V_435 = L_335 ;
break;
case V_357 :
if ( V_433 ) {
F_246 ( V_436 , sizeof( V_436 ) ,
L_336 ,
F_6 ( V_434 ) ) ;
} else {
F_246 ( V_436 , sizeof( V_436 ) ,
L_337
L_314 , V_308 ) ;
F_11 ( V_308 ) ;
}
V_435 = V_436 ;
break;
case V_358 :
if ( V_433 ) {
F_246 ( V_436 , sizeof( V_436 ) ,
L_336 ,
F_6 ( V_434 ) ) ;
V_435 = V_436 ;
} else
V_435 = L_338 ;
break;
case V_372 :
F_246 ( V_436 , sizeof( V_436 ) ,
L_339
L_314 , V_308 ) ;
F_11 ( V_308 ) ;
V_435 = V_436 ;
break;
case V_359 :
if ( V_433 )
V_435 = L_340 ;
else
V_435 = L_341 ;
break;
case V_371 :
V_435 = L_342
L_343 ;
break;
case V_360 :
V_435 = L_344 ;
break;
case V_441 :
V_435 = L_345 ;
break;
case V_373 :
F_246 ( V_436 , sizeof( V_436 ) ,
L_346
L_314 , V_308 ) ;
F_11 ( V_308 ) ;
V_435 = V_436 ;
break;
default:
F_246 ( V_436 , sizeof( V_436 ) ,
L_347 ,
V_433 ? L_348 : L_349 ,
F_249 ( V_99 ) ) ;
V_435 = V_436 ;
break;
}
} else
V_435 = F_293 ( V_99 , V_433 ) ;
return V_435 ;
}
static void
V_147 ( const char * V_321 , int V_99 , T_6 V_433 )
{
fprintf ( V_7 , L_350 ) ;
fprintf ( V_7 , F_293 ( V_99 , V_433 ) , V_321 ) ;
fprintf ( V_7 , L_10 ) ;
}
static void
V_146 ( const char * V_442 , T_52 V_443 )
{
fprintf ( V_7 , L_350 ) ;
vfprintf ( V_7 , V_442 , V_443 ) ;
fprintf ( V_7 , L_10 ) ;
}
static void
V_148 ( const char * V_321 , int V_99 )
{
F_35 ( L_351 ,
V_321 , F_106 ( V_99 ) ) ;
}
static void
V_149 ( const char * V_321 , int V_99 )
{
F_35 ( L_352 ,
V_321 , F_106 ( V_99 ) ) ;
}
void
F_35 ( const char * V_444 , ... )
{
T_52 V_443 ;
va_start ( V_443 , V_444 ) ;
V_146 ( V_444 , V_443 ) ;
va_end ( V_443 ) ;
}
void
F_120 ( const char * V_444 , ... )
{
T_52 V_443 ;
va_start ( V_443 , V_444 ) ;
vfprintf ( V_7 , V_444 , V_443 ) ;
fprintf ( V_7 , L_10 ) ;
va_end ( V_443 ) ;
}
