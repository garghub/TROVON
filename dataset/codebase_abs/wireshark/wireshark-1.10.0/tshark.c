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
F_12 ( T_6 V_13 )
{
T_7 * V_14 ;
if ( V_13 ) {
V_14 = stdout ;
fprintf ( V_14 ,
L_3 V_15 L_4
L_5
L_6
L_7
L_8 ,
V_16 , F_13 () ) ;
} else {
V_14 = V_7 ;
}
fprintf ( V_14 , L_7 ) ;
fprintf ( V_14 , L_9 ) ;
fprintf ( V_14 , L_7 ) ;
#ifdef F_14
fprintf ( V_14 , L_10 ) ;
fprintf ( V_14 , L_11 ) ;
fprintf ( V_14 , L_12 ) ;
fprintf ( V_14 , L_13 ) ;
fprintf ( V_14 , L_14 ) ;
#ifdef F_15
fprintf ( V_14 , L_15 ) ;
#endif
#if F_16 ( V_17 ) || F_16 ( F_15 )
fprintf ( V_14 , L_16 , V_18 ) ;
#endif
fprintf ( V_14 , L_17 ) ;
fprintf ( V_14 , L_18 ) ;
fprintf ( V_14 , L_19 ) ;
fprintf ( V_14 , L_7 ) ;
fprintf ( V_14 , L_20 ) ;
fprintf ( V_14 , L_21 ) ;
fprintf ( V_14 , L_22 ) ;
fprintf ( V_14 , L_23 ) ;
fprintf ( V_14 , L_24 ) ;
fprintf ( V_14 , L_25 ) ;
fprintf ( V_14 , L_26 ) ;
fprintf ( V_14 , L_27 ) ;
fprintf ( V_14 , L_28 ) ;
#endif
#ifdef F_17
fprintf ( V_14 , L_29 ) ;
fprintf ( V_14 , L_30 ) ;
#endif
fprintf ( V_14 , L_31 ) ;
fprintf ( V_14 , L_32 ) ;
fprintf ( V_14 , L_7 ) ;
fprintf ( V_14 , L_33 ) ;
fprintf ( V_14 , L_34 ) ;
fprintf ( V_14 , L_35 ) ;
fprintf ( V_14 , L_36 ) ;
fprintf ( V_14 , L_37 ) ;
fprintf ( V_14 , L_38 ) ;
fprintf ( V_14 , L_39 , V_19 ) ;
fprintf ( V_14 , L_40 ) ;
fprintf ( V_14 , L_41 ) ;
fprintf ( V_14 , L_42 ) ;
fprintf ( V_14 , L_43 ) ;
fprintf ( V_14 , L_44 ) ;
fprintf ( V_14 , L_45 ) ;
fprintf ( V_14 , L_46 ) ;
fprintf ( V_14 , L_47 ) ;
fprintf ( V_14 , L_48 ) ;
fprintf ( V_14 , L_49 ) ;
fprintf ( V_14 , L_50 ) ;
fprintf ( V_14 , L_51 ) ;
fprintf ( V_14 , L_52 ) ;
fprintf ( V_14 , L_53 ) ;
fprintf ( V_14 , L_54 ) ;
fprintf ( V_14 , L_55 ) ;
fprintf ( V_14 , L_56 ) ;
fprintf ( V_14 , L_57 ) ;
fprintf ( V_14 , L_58 ) ;
fprintf ( V_14 , L_59 ) ;
fprintf ( V_14 , L_60 ) ;
fprintf ( V_14 , L_61 ) ;
fprintf ( V_14 , L_62 ) ;
fprintf ( V_14 , L_63 ) ;
fprintf ( V_14 , L_64 ) ;
fprintf ( V_14 , L_65 ) ;
fprintf ( V_14 , L_66 ) ;
fprintf ( V_14 , L_67 ) ;
fprintf ( V_14 , L_68 ) ;
fprintf ( V_14 , L_69 ) ;
fprintf ( V_14 , L_70 ) ;
fprintf ( V_14 , L_71 ) ;
fprintf ( V_14 , L_72 ) ;
fprintf ( V_14 , L_73 ) ;
fprintf ( V_14 , L_74 ) ;
fprintf ( V_14 , L_75 ) ;
fprintf ( V_14 , L_76 ) ;
fprintf ( V_14 , L_7 ) ;
fprintf ( V_14 , L_77 ) ;
fprintf ( V_14 , L_78 ) ;
fprintf ( V_14 , L_79 ) ;
fprintf ( V_14 , L_80 ) ;
fprintf ( V_14 , L_81 ) ;
fprintf ( V_14 , L_82 ) ;
fprintf ( V_14 , L_83 ) ;
fprintf ( V_14 , L_84 ) ;
}
static void
F_18 ( void )
{
T_7 * V_14 ;
V_14 = stdout ;
fprintf ( V_14 , L_3 V_15 L_4 , V_16 ) ;
fprintf ( V_14 , L_7 ) ;
fprintf ( V_14 , L_85 ) ;
fprintf ( V_14 , L_7 ) ;
fprintf ( V_14 , L_86 ) ;
fprintf ( V_14 , L_87 ) ;
fprintf ( V_14 , L_88 ) ;
fprintf ( V_14 , L_89 ) ;
fprintf ( V_14 , L_90 ) ;
fprintf ( V_14 , L_91 ) ;
fprintf ( V_14 , L_92 ) ;
fprintf ( V_14 , L_7 ) ;
fprintf ( V_14 , L_93 ) ;
fprintf ( V_14 , L_94 ) ;
fprintf ( V_14 , L_95 ) ;
fprintf ( V_14 , L_7 ) ;
}
static void
F_19 ( const char * V_20 , const char * V_21 ,
T_3 V_14 )
{
if ( ( V_22 == NULL ) ||
( strcmp ( V_22 , V_20 ) != 0 ) ) {
fprintf ( ( T_7 * ) V_14 , L_96 , V_20 , V_21 ) ;
V_22 = V_20 ;
}
}
static void
F_20 ( const T_8 * T_9 V_6 , T_3 V_23 , T_3 V_14 )
{
int V_24 ;
const T_8 * V_25 ;
const T_8 * V_26 ;
V_24 = F_21 ( ( V_27 ) V_23 ) ;
if ( V_24 != - 1 ) {
V_25 = F_22 ( V_24 ) ;
V_26 = F_23 ( V_24 ) ;
F_24 ( V_25 != NULL ) ;
F_24 ( V_26 != NULL ) ;
if ( ( V_22 == NULL ) ||
( strcmp ( V_22 , V_25 ) != 0 ) ) {
fprintf ( ( T_7 * ) V_14 , L_96 ,
V_25 ,
V_26 ) ;
V_22 = V_25 ;
}
}
}
static void
F_25 ( const T_8 * T_9 V_6 , T_3 V_23 , T_3 V_28 )
{
int V_24 ;
const T_8 * V_29 ;
T_10 V_30 ;
F_24 ( V_23 ) ;
V_30 = ( T_10 ) V_28 ;
V_24 = F_21 ( ( V_27 ) V_23 ) ;
if ( V_24 != - 1 ) {
V_29 = F_22 ( V_24 ) ;
F_24 ( V_29 != NULL ) ;
if ( strcmp ( V_29 , V_30 -> V_31 ) == 0 ) {
if ( V_30 -> V_32 == 0 ) {
V_30 -> V_33 = ( V_27 ) V_23 ;
}
V_30 -> V_32 ++ ;
}
}
}
static T_1
F_26 ( T_2 V_34 , T_2 V_35 )
{
return strcmp ( ( const char * ) V_34 , ( const char * ) V_35 ) ;
}
static void
F_27 ( T_7 * V_14 )
{
V_22 = NULL ;
F_28 ( F_19 , ( T_3 ) V_14 , ( V_36 ) F_26 ) ;
}
static void
F_29 ( T_7 * V_14 , T_8 * V_20 )
{
V_22 = NULL ;
F_30 ( V_20 ,
F_20 ,
( T_3 ) V_14 ) ;
}
static T_6
F_31 ( const T_8 * V_37 )
{
T_8 * V_20 ;
T_11 V_38 , V_39 ;
T_8 * V_40 ;
T_8 * V_41 ;
T_8 * V_42 ;
T_8 * V_43 ;
V_27 V_44 ;
T_12 V_45 ;
T_13 V_46 ;
struct V_47 V_48 ;
T_14 V_9 ;
char V_49 ;
F_24 ( V_37 ) ;
V_40 = F_32 ( V_37 ) ;
F_24 ( V_40 ) ;
V_20 = V_40 ;
V_41 = strchr ( V_20 , '=' ) ;
if ( V_41 == NULL ) {
F_33 ( L_97 , V_37 , V_19 ) ;
}
else {
* V_41 = '\0' ;
}
while ( V_20 [ 0 ] == ' ' )
V_20 ++ ;
while ( V_20 [ strlen ( V_20 ) - 1 ] == ' ' )
V_20 [ strlen ( V_20 ) - 1 ] = '\0' ;
V_45 = NULL ;
if ( ! ( * ( V_20 ) ) ) {
F_33 ( L_98 ) ;
}
else {
V_45 = F_34 ( V_20 ) ;
if ( ! V_45 ) {
F_33 ( L_99 , V_20 ) ;
}
}
if ( ! V_45 ) {
F_33 ( L_100 ) ;
F_27 ( V_7 ) ;
}
if ( V_41 == NULL || ! V_45 ) {
F_11 ( V_40 ) ;
return FALSE ;
}
if ( * ( V_41 + 1 ) != '=' ) {
F_33 ( L_101 , V_20 , V_41 + 1 ) ;
}
else {
V_41 ++ ;
* V_41 = '\0' ;
}
V_41 ++ ;
V_42 = V_41 ;
V_41 = strchr ( V_42 , ',' ) ;
if ( V_41 == NULL ) {
F_33 ( L_97 , V_37 , V_19 ) ;
}
else {
* V_41 = '\0' ;
}
V_46 = F_35 ( V_20 ) ;
switch ( V_46 ) {
case V_50 :
case V_51 :
case V_52 :
case V_53 :
switch ( sscanf ( V_42 , L_102 , & V_38 , & V_49 , & V_39 ) ) {
case 1 :
V_49 = '\0' ;
break;
case 3 :
if ( V_49 != ':' && V_49 != '-' ) {
F_33 ( L_103 , V_42 ) ;
F_11 ( V_40 ) ;
return FALSE ;
}
if ( V_49 == ':' ) {
if ( ( V_39 == 0 ) || ( ( T_14 ) V_38 + V_39 - 1 ) > V_54 ) {
F_33 ( L_103 , V_42 ) ;
F_11 ( V_40 ) ;
return FALSE ;
}
}
else if ( V_39 < V_38 ) {
F_33 ( L_103 , V_42 ) ;
F_11 ( V_40 ) ;
return FALSE ;
}
break;
default:
F_33 ( L_104 , V_42 ) ;
F_11 ( V_40 ) ;
return FALSE ;
}
break;
case V_55 :
case V_56 :
break;
default:
F_36 () ;
}
if ( V_41 == NULL ) {
F_33 ( L_105 , V_20 ) ;
F_29 ( V_7 , V_20 ) ;
F_11 ( V_40 ) ;
return FALSE ;
}
V_41 ++ ;
V_43 = V_41 ;
while ( V_43 [ 0 ] == ' ' )
V_43 ++ ;
while ( V_43 [ strlen ( V_43 ) - 1 ] == ' ' )
V_43 [ strlen ( V_43 ) - 1 ] = '\0' ;
V_44 = NULL ;
if ( ! ( * V_43 ) ) {
F_33 ( L_106 ) ;
}
else {
V_48 . V_32 = 0 ;
V_48 . V_31 = V_43 ;
V_48 . V_33 = NULL ;
F_30 ( V_20 , F_25 , & V_48 ) ;
if ( V_48 . V_32 != 0 ) {
V_44 = V_48 . V_33 ;
if ( V_48 . V_32 > 1 ) {
F_33 ( L_107 , V_43 , V_48 . V_32 ) ;
}
}
else {
if ( F_37 ( V_43 ) == - 1 ) {
F_33 ( L_108 , V_43 ) ;
} else {
F_33 ( L_109 ,
V_43 , V_20 ) ;
}
}
}
if ( ! V_44 ) {
F_33 ( L_105 , V_20 ) ;
F_29 ( V_7 , V_20 ) ;
F_11 ( V_40 ) ;
return FALSE ;
}
switch ( V_46 ) {
case V_50 :
case V_51 :
case V_52 :
case V_53 :
if ( V_49 == '\0' ) {
F_38 ( V_20 , V_38 , V_44 ) ;
} else if ( V_49 == ':' ) {
for ( V_9 = V_38 ; V_9 < ( T_14 ) V_38 + V_39 ; V_9 ++ ) {
F_38 ( V_20 , ( T_11 ) V_9 , V_44 ) ;
}
} else {
for ( V_9 = V_38 ; V_9 <= V_39 ; V_9 ++ ) {
F_38 ( V_20 , ( T_11 ) V_9 , V_44 ) ;
}
}
break;
case V_55 :
case V_56 :
F_39 ( V_20 , V_42 , V_44 ) ;
break;
default:
F_36 () ;
}
F_11 ( V_40 ) ;
return TRUE ;
}
static void
F_40 ( const T_8 * V_57 , T_15 V_58 ,
const T_8 * V_59 , T_3 V_28 )
{
if ( ( V_58 & V_60 & V_61 . V_62 ) == 0 &&
V_61 . V_62 != 0 ) {
return;
}
F_41 ( V_57 , V_58 , V_59 , V_28 ) ;
}
static char *
F_42 ( const char * V_63 )
{
char * V_64 ;
if ( strcmp ( V_63 , L_110 ) == 0 ) {
V_64 = F_32 ( L_111 ) ;
} else {
V_64 = F_43 ( L_112 , V_63 ) ;
}
return V_64 ;
}
static void
F_44 ( void ) {
T_8 * V_65 , * V_66 ;
if ( F_45 () ) {
V_65 = F_46 () ;
V_66 = F_47 () ;
fprintf ( V_7 , L_113 ,
V_65 , V_66 ) ;
F_11 ( V_65 ) ;
F_11 ( V_66 ) ;
if ( F_48 () ) {
fprintf ( V_7 , L_114 ) ;
}
fprintf ( V_7 , L_7 ) ;
}
}
static void
F_49 ( void ) {
#ifdef V_17
F_50 () ;
if ( ! F_51 () && F_52 () >= 6 ) {
fprintf ( V_7 , L_115
L_116 ) ;
}
#endif
}
static void
F_53 ( T_16 * V_67 , T_16 * V_68 )
{
printf ( L_3 V_15 L_4
L_7
L_8
L_7
L_8
L_7
L_8 ,
V_16 , F_13 () , V_67 -> V_69 ,
V_68 -> V_69 ) ;
}
int
main ( int V_70 , char * V_71 [] )
{
T_16 * V_67 ;
T_16 * V_68 ;
char * V_72 ;
int V_73 ;
T_6 V_74 = FALSE ;
#ifdef V_17
T_17 V_75 ;
#endif
char * V_76 , * V_77 ;
char * V_78 , * V_79 ;
int V_80 , V_81 ;
int V_82 , V_83 ;
int V_84 , V_85 ;
int V_86 , V_87 ;
int V_88 ;
volatile int V_89 = 0 ;
#ifdef F_14
T_6 V_90 = FALSE ;
T_6 V_91 = FALSE ;
int V_92 ;
T_18 * V_93 ;
T_8 * V_94 ;
#else
T_6 V_95 = FALSE ;
#endif
T_6 V_96 = FALSE ;
#ifdef F_54
volatile int V_97 = V_98 ;
#else
volatile int V_97 = V_99 ;
#endif
volatile T_6 V_100 = FALSE ;
T_8 * volatile V_101 = NULL ;
T_8 * V_102 = NULL ;
T_8 * V_103 = NULL ;
#ifdef F_55
struct V_104 V_105 ;
#endif
T_19 * V_106 = NULL ;
T_19 * V_107 = NULL ;
T_20 * V_108 ;
char V_109 ;
int V_110 ;
int V_111 ;
T_8 * V_112 = NULL ;
#ifdef F_17
#define F_56 "A:"
#else
#define F_56 ""
#endif
#ifdef F_14
#if F_16 ( V_17 ) || F_16 ( F_15 )
#define F_57 "B:"
#else
#define F_57 ""
#endif
#else
#define F_57 ""
#endif
#ifdef F_15
#define F_58 "I"
#else
#define F_58 ""
#endif
#define F_59 "2a:" OPTSTRING_A "b:" OPTSTRING_B "c:C:d:De:E:f:F:gG:hH:i:" OPTSTRING_I "K:lLnN:o:O:pPqQr:R:s:S:t:T:u:vVw:W:xX:y:Y:z:"
static const char V_113 [] = F_59 ;
V_67 = F_60 ( L_117 ) ;
F_61 ( V_67 , NULL , V_114 ) ;
V_68 = F_60 ( L_118 ) ;
F_62 ( V_68 , NULL ) ;
F_63 ( L_3 V_15 L_4
L_7
L_8
L_7
L_8 ,
V_16 , V_67 -> V_69 , V_68 -> V_69 ) ;
#ifdef V_17
F_64 ( V_70 , V_71 ) ;
F_65 () ;
#if ! F_66 ( 2 , 31 , 0 )
F_67 ( NULL ) ;
#endif
#endif
F_68 () ;
V_72 = F_69 ( V_71 [ 0 ] , main ) ;
if ( V_72 != NULL ) {
fprintf ( V_7 , L_119 ,
V_72 ) ;
}
V_115 = 0 ;
V_111 = V_116 ;
while ( ( V_73 = F_70 ( V_70 , V_71 , V_113 ) ) != - 1 ) {
switch ( V_73 ) {
case 'C' :
if ( F_71 ( V_117 , FALSE ) ) {
F_72 ( V_117 ) ;
} else {
F_33 ( L_120 , V_117 ) ;
return 1 ;
}
break;
case 'P' :
V_118 = TRUE ;
V_119 = TRUE ;
break;
case 'O' :
V_112 = F_32 ( V_117 ) ;
case 'V' :
V_120 = TRUE ;
V_118 = TRUE ;
break;
case 'x' :
V_121 = TRUE ;
V_118 = TRUE ;
break;
case 'X' :
F_73 ( V_117 ) ;
break;
default:
break;
}
}
if ( V_119 == - 1 )
V_119 = ( V_120 || V_121 ) ? FALSE : TRUE ;
V_116 = V_111 ;
V_115 = 1 ;
V_110 =
V_122 |
V_123 |
V_124 |
V_125 |
V_126 |
V_127 |
V_128 | V_129 ;
F_74 ( NULL ,
( T_15 ) V_110 ,
F_40 , NULL ) ;
F_74 ( V_130 ,
( T_15 ) V_110 ,
F_40 , NULL ) ;
#ifdef F_14
F_74 ( V_131 ,
( T_15 ) V_110 ,
F_40 , NULL ) ;
F_74 ( V_132 ,
( T_15 ) V_110 ,
F_40 , NULL ) ;
#endif
F_75 () ;
#ifdef F_14
F_76 ( & V_133 ) ;
F_77 ( & V_134 , ( void * ) & V_135 ) ;
#endif
F_78 ( V_136 ) ;
F_79 ( V_137 ) ;
F_80 ( V_138 ) ;
F_81 ( V_139 , V_140 , NULL , NULL ,
V_141 , V_142 , V_143 ,
V_144 ) ;
#ifdef F_82
F_83 () ;
#endif
F_84 () ;
if ( V_70 >= 2 && strcmp ( V_71 [ 1 ] , L_121 ) == 0 ) {
F_85 () ;
if ( V_70 == 2 )
F_86 () ;
else {
if ( strcmp ( V_71 [ 2 ] , L_122 ) == 0 )
F_86 () ;
else if ( strcmp ( V_71 [ 2 ] , L_123 ) == 0 )
F_87 () ;
else if ( strcmp ( V_71 [ 2 ] , L_124 ) == 0 )
F_88 () ;
else if ( strcmp ( V_71 [ 2 ] , L_125 ) == 0 )
F_89 () ;
else if ( strcmp ( V_71 [ 2 ] , L_126 ) == 0 )
F_90 () ;
else if ( strcmp ( V_71 [ 2 ] , L_127 ) == 0 )
F_91 () ;
else if ( strcmp ( V_71 [ 2 ] , L_128 ) == 0 )
F_92 ( NULL ) ;
else if ( strcmp ( V_71 [ 2 ] , L_129 ) == 0 )
F_93 () ;
else if ( strcmp ( V_71 [ 2 ] , L_130 ) == 0 )
F_18 () ;
else if ( strcmp ( V_71 [ 2 ] , L_131 ) == 0 )
F_18 () ;
else if ( strcmp ( V_71 [ 2 ] , L_132 ) == 0 ) {
F_94 ( & V_80 , & V_81 , & V_76 ,
& V_82 , & V_83 , & V_77 ) ;
F_92 ( NULL ) ;
} else {
F_33 ( L_133 , V_71 [ 2 ] ) ;
return 1 ;
}
}
return 0 ;
}
setlocale ( V_145 , L_134 ) ;
V_108 = F_94 ( & V_80 , & V_81 , & V_76 ,
& V_82 , & V_83 , & V_77 ) ;
if ( V_76 != NULL ) {
if ( V_80 != 0 ) {
F_33 ( L_135 ,
V_77 , F_95 ( V_80 ) ) ;
}
if ( V_81 != 0 ) {
F_33 ( L_136 ,
V_77 , F_95 ( V_81 ) ) ;
}
}
if ( V_77 != NULL ) {
if ( V_82 != 0 ) {
F_33 ( L_137 , V_77 ,
F_95 ( V_82 ) ) ;
}
if ( V_83 != 0 ) {
F_33 ( L_138 ,
V_77 , F_95 ( V_83 ) ) ;
}
F_11 ( V_77 ) ;
V_77 = NULL ;
}
F_96 ( & V_78 , & V_84 , & V_85 ,
& V_79 , & V_86 , & V_87 ) ;
if ( V_78 != NULL ) {
if ( V_84 != 0 ) {
F_33 ( L_139 ,
V_78 , F_95 ( V_84 ) ) ;
}
if ( V_85 != 0 ) {
F_33 ( L_140 ,
V_78 , F_95 ( V_85 ) ) ;
}
F_11 ( V_78 ) ;
}
if ( V_79 != NULL ) {
if ( V_86 != 0 ) {
F_33 (
L_141 , V_79 ,
F_95 ( V_86 ) ) ;
}
if ( V_87 != 0 ) {
F_33 (
L_142 , V_79 ,
F_95 ( V_87 ) ) ;
}
F_11 ( V_79 ) ;
}
F_49 () ;
F_97 ( & V_135 ) ;
V_146 = V_147 ;
V_148 = F_98 () ;
while ( ( V_73 = F_70 ( V_70 , V_71 , V_113 ) ) != - 1 ) {
switch ( V_73 ) {
case '2' :
V_149 = TRUE ;
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
#if F_16 ( V_17 ) || F_16 ( F_15 )
case 'B' :
#endif
#ifdef F_14
V_92 = F_99 ( & V_133 , V_73 , V_117 , & V_91 ) ;
if ( V_92 != 0 ) {
return V_92 ;
}
#else
V_95 = TRUE ;
V_74 = TRUE ;
#endif
break;
case 'C' :
break;
case 'd' :
if ( ! F_31 ( V_117 ) )
return 1 ;
break;
#if F_16 ( V_150 ) || F_16 ( V_151 )
case 'K' :
F_100 ( V_117 ) ;
break;
#endif
case 'D' :
#ifdef F_14
V_93 = F_101 ( & V_88 , & V_94 ) ;
if ( V_93 == NULL ) {
switch ( V_88 ) {
case V_152 :
case V_153 :
F_33 ( L_8 , V_94 ) ;
F_11 ( V_94 ) ;
break;
case V_154 :
F_33 ( L_143 ) ;
break;
}
return 2 ;
}
F_102 ( V_93 ) ;
F_103 ( V_93 ) ;
return 0 ;
#else
V_95 = TRUE ;
V_74 = TRUE ;
#endif
break;
case 'e' :
F_104 ( V_148 , V_117 ) ;
break;
case 'E' :
if ( ! F_105 ( V_148 , V_117 ) ) {
F_33 ( L_144 , V_117 ) ;
F_106 ( V_7 ) ;
return 1 ;
}
break;
case 'F' :
V_97 = F_107 ( V_117 ) ;
if ( V_97 < 0 ) {
F_33 ( L_145 , V_117 ) ;
F_3 () ;
return 1 ;
}
break;
case 'W' :
if ( strchr ( V_117 , 'n' ) ) {
V_100 = TRUE ;
} else {
F_33 ( L_146 , V_117 ) ;
return 1 ;
}
break;
case 'H' :
if ( ! F_108 ( V_117 ) )
{
F_33 ( L_147 , V_117 ) ;
return 1 ;
}
V_100 = TRUE ;
break;
case 'h' :
F_12 ( TRUE ) ;
return 0 ;
break;
case 'l' :
V_155 = TRUE ;
break;
case 'L' :
#ifdef F_14
V_90 = TRUE ;
#else
V_95 = TRUE ;
V_74 = TRUE ;
#endif
break;
case 'n' :
V_156 . V_157 = FALSE ;
V_156 . V_158 = FALSE ;
V_156 . V_159 = FALSE ;
V_156 . V_160 = FALSE ;
break;
case 'N' :
V_109 = F_109 ( V_117 , & V_156 ) ;
if ( V_109 != '\0' ) {
F_33 ( L_148 ,
V_109 ) ;
F_110 ( L_149 ) ;
return 1 ;
}
break;
case 'o' :
switch ( F_111 ( V_117 ) ) {
case V_161 :
break;
case V_162 :
F_33 ( L_150 , V_117 ) ;
return 1 ;
break;
case V_163 :
case V_164 :
F_33 ( L_151 , V_117 ) ;
return 1 ;
break;
}
break;
case 'q' :
V_96 = TRUE ;
break;
case 'Q' :
V_96 = TRUE ;
V_165 = TRUE ;
break;
case 'r' :
V_101 = F_32 ( V_117 ) ;
break;
case 'R' :
V_102 = V_117 ;
break;
case 'P' :
break;
case 'S' :
V_166 = F_112 ( V_117 ) ;
break;
case 't' :
if ( strcmp ( V_117 , L_152 ) == 0 )
F_78 ( V_136 ) ;
else if ( strcmp ( V_117 , L_153 ) == 0 )
F_78 ( V_167 ) ;
else if ( strcmp ( V_117 , L_154 ) == 0 )
F_78 ( V_168 ) ;
else if ( strcmp ( V_117 , L_155 ) == 0 )
F_78 ( V_169 ) ;
else if ( strcmp ( V_117 , L_156 ) == 0 )
F_78 ( V_170 ) ;
else if ( strcmp ( V_117 , L_157 ) == 0 )
F_78 ( V_171 ) ;
else if ( strcmp ( V_117 , L_158 ) == 0 )
F_78 ( V_172 ) ;
else if ( strcmp ( V_117 , L_159 ) == 0 )
F_78 ( V_173 ) ;
else {
F_33 ( L_160 ,
V_117 ) ;
F_110 ( L_161 ) ;
F_110 ( L_162 ) ;
return 1 ;
}
break;
case 'T' :
if ( strcmp ( V_117 , L_163 ) == 0 ) {
V_174 = V_175 ;
V_146 = V_147 ;
} else if ( strcmp ( V_117 , L_164 ) == 0 ) {
V_174 = V_175 ;
V_146 = V_176 ;
} else if ( strcmp ( V_117 , L_165 ) == 0 ) {
V_174 = V_177 ;
V_120 = TRUE ;
V_119 = FALSE ;
} else if ( strcmp ( V_117 , L_166 ) == 0 ) {
V_174 = V_177 ;
V_120 = FALSE ;
V_119 = TRUE ;
} else if ( strcmp ( V_117 , L_122 ) == 0 ) {
V_174 = V_178 ;
V_120 = TRUE ;
V_119 = FALSE ;
} else {
F_33 ( L_167 ) ;
F_110 ( L_168 ) ;
return 1 ;
}
break;
case 'u' :
if ( strcmp ( V_117 , L_169 ) == 0 )
F_80 ( V_138 ) ;
else if ( strcmp ( V_117 , L_170 ) == 0 )
F_80 ( V_179 ) ;
else {
F_33 ( L_171 , V_117 ) ;
F_110 ( L_172 ) ;
return 1 ;
}
break;
case 'v' :
{
F_53 ( V_67 , V_68 ) ;
F_113 ( V_67 , TRUE ) ;
F_113 ( V_68 , TRUE ) ;
F_114 () ;
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
V_103 = V_117 ;
break;
case 'z' :
if ( ! F_115 ( V_117 ) ) {
if ( strcmp ( L_173 , V_117 ) == 0 ) {
fprintf ( V_7 , L_174 ) ;
F_116 () ;
return 0 ;
}
F_33 ( L_175 , V_117 ) ;
F_110 ( L_176 ) ;
F_116 () ;
return 1 ;
}
break;
default:
case '?' :
switch( V_180 ) {
case 'F' :
F_3 () ;
break;
default:
F_12 ( TRUE ) ;
}
return 1 ;
break;
}
}
if ( V_178 != V_174 && 0 != F_117 ( V_148 ) ) {
F_33 ( L_177
L_178 ) ;
return 1 ;
} else if ( V_178 == V_174 && 0 == F_117 ( V_148 ) ) {
F_33 ( L_179
L_180 ) ;
return 1 ;
}
if ( V_116 < V_70 ) {
if ( V_101 != NULL ) {
if ( V_103 != NULL ) {
F_33 ( L_181
L_182 ) ;
return 1 ;
}
V_103 = F_118 ( V_70 , V_71 , V_116 ) ;
} else {
#ifdef F_14
T_21 V_9 ;
if ( V_133 . V_181 . V_182 ) {
F_33 ( L_183
L_184 ) ;
return 1 ;
}
for ( V_9 = 0 ; V_9 < V_133 . V_183 -> V_184 ; V_9 ++ ) {
T_22 V_185 ;
V_185 = F_119 ( V_133 . V_183 , T_22 , V_9 ) ;
if ( V_185 . V_182 == NULL ) {
V_185 . V_182 = F_118 ( V_70 , V_71 , V_116 ) ;
V_133 . V_183 = F_120 ( V_133 . V_183 , V_9 ) ;
F_121 ( V_133 . V_183 , V_9 , V_185 ) ;
} else {
F_33 ( L_185
L_184 ) ;
return 1 ;
}
}
V_133 . V_181 . V_182 = F_118 ( V_70 , V_71 , V_116 ) ;
#else
V_95 = TRUE ;
#endif
}
}
#ifdef F_14
if ( ! V_133 . V_186 ) {
if ( ! V_96 )
V_118 = TRUE ;
} else {
if ( strcmp ( V_133 . V_187 , L_110 ) == 0 && V_118 ) {
F_33 ( L_186
L_187 ) ;
return 1 ;
}
}
#else
if ( ! V_96 )
V_118 = TRUE ;
#endif
#ifndef F_14
if ( V_95 )
F_33 ( L_188 ) ;
#endif
if ( V_74 ) {
F_12 ( FALSE ) ;
return 1 ;
}
#ifdef F_14
if ( V_101 != NULL ) {
if ( V_133 . V_181 . V_182 ) {
F_33 ( L_189
L_190 ) ;
return 1 ;
}
}
#endif
if ( V_121 ) {
if ( V_174 != V_175 ) {
F_33 ( L_191 ) ;
return 1 ;
}
}
if ( V_112 != NULL ) {
char * V_188 ;
if ( ! V_120 ) {
F_33 ( L_192 ) ;
return 1 ;
}
V_189 = F_122 ( V_190 , V_191 ) ;
for ( V_188 = strtok ( V_112 , L_193 ) ; V_188 ; V_188 = strtok ( NULL , L_193 ) ) {
F_123 ( V_189 , ( T_3 ) V_188 , ( T_3 ) V_188 ) ;
}
}
if ( V_102 != NULL && ! V_149 ) {
F_33 ( L_194 ) ;
}
#ifdef F_14
if ( V_90 ) {
if ( V_101 ) {
F_33 ( L_195 ) ;
return 1 ;
}
if ( V_133 . V_192 ) {
F_33 ( L_196 ) ;
return 1 ;
}
} else {
if ( V_101 ) {
if ( V_133 . V_192 ) {
F_33 ( L_197
L_198 ) ;
return 1 ;
}
if ( V_133 . V_193 ) {
F_33 ( L_199
L_198 ) ;
return 1 ;
}
if ( V_133 . V_194 ) {
F_33 ( L_200
L_198 ) ;
return 1 ;
}
if ( V_133 . V_195 ) {
F_33 ( L_201
L_198 ) ;
return 1 ;
}
if ( V_133 . V_196 ) {
F_33 ( L_202
L_198 ) ;
return 1 ;
}
} else {
if ( V_133 . V_186 ) {
if ( V_97 != V_99 && V_97 != V_98 ) {
F_33 ( L_203 ) ;
return 1 ;
}
if ( V_133 . V_192 ) {
if ( strcmp ( V_133 . V_187 , L_110 ) == 0 ) {
F_33 ( L_197
L_204 ) ;
return 1 ;
}
if ( V_133 . V_197 ) {
F_33 ( L_197
L_205 ) ;
return 1 ;
}
if ( ! V_133 . V_198 &&
! V_133 . V_193 ) {
F_33 ( L_197
L_206 ) ;
return 1 ;
}
}
if ( V_102 != NULL ) {
F_33 ( L_207 ) ;
return 1 ;
}
if ( V_103 != NULL ) {
F_33 ( L_208 ) ;
return 1 ;
}
} else {
if ( V_133 . V_198 ) {
F_33 ( L_209
L_210 ) ;
return 1 ;
}
if ( V_133 . V_192 ) {
F_33 ( L_197
L_211 ) ;
return 1 ;
}
}
}
}
#endif
#ifdef V_17
F_124 ( F_125 ( 1 , 1 ) , & V_75 ) ;
#endif
F_126 () ;
F_127 () ;
#ifdef F_14
if ( V_133 . V_186 &&
V_133 . V_197 ) {
if ( F_128 () ) {
F_33 ( L_212 ) ;
return 1 ;
}
if ( V_118 ) {
F_33 ( L_213 ) ;
return 1 ;
}
}
#endif
if ( V_78 == NULL && V_79 == NULL ) {
F_129 () ;
}
F_130 ( & V_135 . V_199 , V_108 -> V_200 , TRUE ) ;
#ifdef F_14
F_131 ( & V_133 , V_201 ) ;
F_132 ( & V_133 ) ;
#endif
if ( V_102 != NULL ) {
if ( ! F_133 ( V_102 , & V_106 ) ) {
F_33 ( L_8 , V_202 ) ;
F_114 () ;
#ifdef F_55
{
T_23 * V_203 ;
V_203 = F_134 ( V_204 , V_201 ) ;
if ( V_203 != NULL ) {
if ( F_135 ( V_203 , & V_105 , V_102 , 0 , 0 ) != - 1 ) {
F_110 (
L_214 ) ;
F_110 (
L_215 ) ;
}
F_136 ( V_203 ) ;
}
}
#endif
return 2 ;
}
}
V_135 . V_106 = V_106 ;
if ( V_103 != NULL ) {
if ( ! F_133 ( V_103 , & V_107 ) ) {
F_33 ( L_8 , V_202 ) ;
F_114 () ;
#ifdef F_55
{
T_23 * V_203 ;
V_203 = F_134 ( V_204 , V_201 ) ;
if ( V_203 != NULL ) {
if ( F_135 ( V_203 , & V_105 , V_103 , 0 , 0 ) != - 1 ) {
F_110 (
L_216 ) ;
F_110 (
L_215 ) ;
}
F_136 ( V_203 ) ;
}
}
#endif
return 2 ;
}
}
V_135 . V_107 = V_107 ;
if ( V_118 ) {
if ( V_174 == V_175 ) {
switch ( V_146 ) {
case V_147 :
V_205 = F_137 ( stdout ) ;
break;
case V_176 :
V_205 = F_138 ( stdout ) ;
break;
default:
F_36 () ;
}
}
}
V_206 = V_118 || V_106 || V_107 || F_128 () ;
if ( V_101 ) {
F_139 () ;
F_44 () ;
if ( F_140 ( & V_135 , V_101 , FALSE , & V_88 ) != V_207 ) {
F_114 () ;
return 2 ;
}
switch( F_141 ( V_135 . V_208 ) ) {
case ( V_209 ) :
F_79 ( V_210 ) ;
break;
case ( V_211 ) :
F_79 ( V_212 ) ;
break;
case ( V_213 ) :
F_79 ( V_214 ) ;
break;
case ( V_215 ) :
F_79 ( V_216 ) ;
break;
case ( V_217 ) :
F_79 ( V_218 ) ;
break;
case ( V_219 ) :
F_79 ( V_220 ) ;
break;
default:
F_36 () ;
}
F_142 {
#ifdef F_14
V_88 = F_143 ( & V_135 , V_133 . V_187 , V_97 , V_100 ,
V_133 . V_221 ? V_133 . V_222 : 0 ,
V_133 . V_198 ? V_133 . V_223 : 0 ) ;
#else
V_88 = F_143 ( & V_135 , NULL , V_97 , V_100 , 0 , 0 ) ;
#endif
}
F_144 (OutOfMemoryError) {
fprintf ( V_7 ,
L_217
L_7
L_218
L_7
L_219
L_220 ) ;
V_88 = V_224 ;
}
V_225 ;
if ( V_88 != 0 ) {
V_89 = 2 ;
}
} else {
#ifdef F_14
V_89 = F_145 ( & V_133 ,
( ( V_108 -> V_226 ) && ( * V_108 -> V_226 != '\0' ) ) ? F_146 ( V_108 -> V_226 ) : NULL ) ;
if ( V_89 != 0 )
return V_89 ;
if ( V_90 ) {
T_21 V_9 ;
for ( V_9 = 0 ; V_9 < V_133 . V_183 -> V_184 ; V_9 ++ ) {
T_22 V_185 ;
T_24 * V_227 ;
V_185 = F_119 ( V_133 . V_183 , T_22 , V_9 ) ;
V_227 = F_147 ( V_185 . V_228 , V_185 . V_229 , & V_94 ) ;
if ( V_227 == NULL ) {
F_33 ( L_8 , V_94 ) ;
F_11 ( V_94 ) ;
return 2 ;
}
if ( V_227 -> V_230 == NULL ) {
F_33 ( L_221 , V_185 . V_228 ) ;
return 2 ;
}
F_148 ( V_227 , V_185 . V_228 , V_185 . V_229 ) ;
F_149 ( V_227 ) ;
}
return 0 ;
}
if ( V_118 ) {
if ( ! F_150 ( NULL ) ) {
F_151 ( V_231 ) ;
return 2 ;
}
} else if ( ! V_96 ) {
V_232 = TRUE ;
}
F_79 ( V_218 ) ;
F_152 () ;
V_89 = V_134 . V_233 ;
if ( V_118 ) {
if ( ! F_153 () ) {
V_88 = V_231 ;
F_151 ( V_88 ) ;
}
}
#else
F_33 ( L_188 ) ;
return 2 ;
#endif
}
F_11 ( V_101 ) ;
if ( V_135 . V_234 != NULL ) {
F_154 ( V_135 . V_234 ) ;
V_135 . V_234 = NULL ;
}
F_155 ( TRUE ) ;
F_156 () ;
F_114 () ;
F_157 ( V_148 ) ;
V_148 = NULL ;
return V_89 ;
}
static T_1
F_158 ( T_3 V_5 )
{
T_25 V_23 ;
T_26 V_235 = 0 ;
T_6 V_236 ;
T_26 V_237 ;
T_27 * V_238 = V_5 ;
T_1 V_239 = 0 ;
F_159 ( V_238 -> V_240 ) ;
while( V_239 < 5 ) {
V_23 = ( T_25 ) F_160 ( V_238 -> V_241 ) ;
V_236 = F_161 ( V_23 , NULL , 0 , NULL , & V_235 , NULL ) ;
F_162 ( ( T_25 ) * ( V_238 -> V_242 ) ,
& V_237 ) ;
if ( ! V_236 || V_235 > 0 || V_237 != V_243 ) {
if ( ! V_238 -> V_244 ( V_238 -> V_241 , V_238 -> V_28 ) ) {
F_163 ( NULL , V_127 , L_222 , V_239 ) ;
F_164 ( V_238 -> V_240 ) ;
return FALSE ;
}
}
else {
break;
}
V_239 ++ ;
}
F_164 ( V_238 -> V_240 ) ;
return TRUE ;
}
void
F_165 ( T_1 V_241 , T_3 V_28 , int * V_242 , T_28 V_244 )
{
V_245 . V_241 = V_241 ;
V_245 . V_242 = V_242 ;
V_245 . V_28 = V_28 ;
V_245 . V_244 = V_244 ;
#ifdef V_17
#if F_66 ( 2 , 31 , 0 )
V_245 . V_240 = F_166 ( sizeof( V_246 ) ) ;
F_167 ( V_245 . V_240 ) ;
#else
V_245 . V_240 = F_168 () ;
#endif
V_245 . V_247 = F_169 ( 200 , F_158 , & V_245 ) ;
#endif
}
void F_170 ( void )
{
}
void
F_171 ( T_29 * T_30 V_6 , char * V_248 , char * V_249 )
{
F_33 ( L_8 , V_248 ) ;
F_110 ( L_8 , V_249 ) ;
}
void
F_172 ( T_29 * T_30 , T_21 V_9 , char * V_250 )
{
T_31 * V_251 = T_30 -> V_251 ;
T_19 * V_106 = NULL ;
T_22 V_185 ;
F_24 ( V_9 < V_251 -> V_183 -> V_184 ) ;
V_185 = F_119 ( V_251 -> V_183 , T_22 , V_9 ) ;
if ( F_133 ( V_185 . V_182 , & V_106 ) && V_106 != NULL ) {
F_33 (
L_223
L_7
L_224
L_225
L_7
L_226
L_227
L_7
L_228 ,
V_185 . V_182 , V_185 . V_252 , V_250 ) ;
F_173 ( V_106 ) ;
} else {
F_33 (
L_223
L_7
L_229
L_228 ,
V_185 . V_182 , V_185 . V_252 , V_250 ) ;
}
}
T_6
F_174 ( T_29 * T_30 , T_8 * V_253 )
{
T_31 * V_251 = T_30 -> V_251 ;
T_6 V_254 ;
int V_88 ;
if ( T_30 -> V_255 == V_256 ) {
F_163 ( V_131 , V_125 , L_230 ) ;
}
F_163 ( V_131 , V_125 , L_231 , V_253 ) ;
F_24 ( T_30 -> V_255 == V_256 || T_30 -> V_255 == V_257 ) ;
if ( V_251 -> V_187 != NULL ) {
if ( ( ( V_258 * ) T_30 -> V_259 ) -> V_255 != V_260 ) {
if ( ( ( V_258 * ) T_30 -> V_259 ) -> V_208 != NULL ) {
F_175 ( ( ( V_258 * ) T_30 -> V_259 ) -> V_208 ) ;
}
( ( V_258 * ) T_30 -> V_259 ) -> V_255 = V_260 ;
}
F_11 ( V_251 -> V_187 ) ;
V_254 = FALSE ;
} else {
V_254 = TRUE ;
}
V_251 -> V_187 = F_32 ( V_253 ) ;
if ( V_206 ) {
switch( F_140 ( ( V_258 * ) T_30 -> V_259 , V_251 -> V_187 , V_254 , & V_88 ) ) {
case V_207 :
break;
case V_261 :
F_11 ( V_251 -> V_187 ) ;
V_251 -> V_187 = NULL ;
return FALSE ;
}
}
T_30 -> V_255 = V_257 ;
return TRUE ;
}
void
F_176 ( T_29 * T_30 , int V_262 )
{
T_6 V_263 ;
int V_88 ;
T_8 * V_264 ;
T_32 V_265 ;
V_258 * V_259 = ( V_258 * ) T_30 -> V_259 ;
T_6 V_266 ;
T_21 V_267 ;
#ifdef F_177
V_268 = TRUE ;
#endif
V_266 = F_178 () ;
V_267 = F_179 () ;
if ( V_206 ) {
while ( V_262 -- && V_259 -> V_208 ) {
F_180 ( V_259 -> V_208 ) ;
V_263 = F_181 ( V_259 -> V_208 , & V_88 , & V_264 , & V_265 ) ;
if ( V_263 == FALSE ) {
F_182 ( T_30 ) ;
F_175 ( V_259 -> V_208 ) ;
V_259 -> V_208 = NULL ;
} else {
V_263 = F_183 ( V_259 , V_265 , F_184 ( V_259 -> V_208 ) ,
F_185 ( V_259 -> V_208 ) ,
V_266 , V_267 ) ;
}
if ( V_263 != FALSE ) {
V_269 ++ ;
}
}
} else {
V_269 += V_262 ;
}
if ( V_232 ) {
if ( V_269 != 0 ) {
fprintf ( V_7 , L_232 , V_269 ) ;
fflush ( V_7 ) ;
}
}
#ifdef F_177
V_268 = FALSE ;
if ( V_270 )
F_186 () ;
#endif
}
static void
F_186 ( void )
{
if ( ( V_232 == FALSE ) && ( V_165 == FALSE ) ) {
fprintf ( V_7 , L_233 , V_269 ,
F_187 ( V_269 , L_134 , L_169 ) ) ;
}
#ifdef F_177
V_270 = FALSE ;
#endif
}
static void
F_188 ( int T_33 V_6 )
{
int V_271 = V_231 ;
if ( V_268 )
V_270 = TRUE ;
else
F_186 () ;
V_231 = V_271 ;
}
void
F_189 ( T_29 * T_30 V_6 , T_11 V_272 )
{
if ( V_232 ) {
fprintf ( V_7 , L_7 ) ;
}
if ( V_272 != 0 ) {
fprintf ( V_7 , L_234 , V_272 , F_187 ( V_272 , L_134 , L_169 ) ) ;
}
}
void
F_190 ( T_29 * T_30 , T_8 * V_273 )
{
V_258 * V_259 = ( V_258 * ) T_30 -> V_259 ;
if ( V_273 != NULL )
fprintf ( V_7 , L_235 , V_273 ) ;
F_186 () ;
if ( V_259 != NULL && V_259 -> V_208 != NULL ) {
F_175 ( V_259 -> V_208 ) ;
if ( V_259 -> V_254 ) {
F_191 ( V_259 -> V_274 ) ;
}
}
#ifdef F_192
F_193 ( V_275 ) ;
#else
V_276 = FALSE ;
#endif
}
static BOOL T_34
F_194 ( T_26 T_35 V_6 )
{
F_182 ( & V_134 ) ;
return TRUE ;
}
static void
F_194 ( int T_33 V_6 )
{
F_182 ( & V_134 ) ;
}
static T_6
F_195 ( V_258 * V_259 ,
T_32 V_277 , struct V_278 * V_279 ,
const T_36 * V_280 )
{
T_37 V_281 ;
T_11 V_282 ;
T_6 V_283 = FALSE ;
T_38 V_284 ;
T_6 V_285 ;
V_282 = V_259 -> V_286 + 1 ;
V_285 = TRUE ;
F_196 ( & V_281 , V_282 , V_279 , V_277 , V_287 ) ;
if ( V_206 ) {
if ( V_156 . V_157 || V_156 . V_158 ||
V_156 . V_159 || V_156 . V_160 )
F_197 () ;
if ( V_259 -> V_106 )
V_283 = TRUE ;
F_198 ( & V_284 , V_283 , FALSE ) ;
if ( V_259 -> V_106 )
F_199 ( & V_284 , V_259 -> V_106 ) ;
F_200 ( & V_281 , & V_259 -> V_288 ,
& V_289 , V_290 , V_291 ) ;
F_201 ( & V_284 , V_279 , V_280 , & V_281 , NULL ) ;
if ( V_259 -> V_106 )
V_285 = F_202 ( V_259 -> V_106 , & V_284 ) ;
}
if ( V_285 ) {
F_203 ( & V_281 , & V_287 ) ;
V_291 = V_290 = F_204 ( V_259 -> V_234 , & V_281 ) ;
if ( V_206 ) {
F_9 ( V_284 . V_292 . V_293 , V_294 , V_259 -> V_234 ) ;
}
V_259 -> V_286 ++ ;
} else {
F_205 ( & V_281 ) ;
}
if ( V_206 )
F_206 ( & V_284 ) ;
return V_285 ;
}
static T_6
F_207 ( V_258 * V_259 , T_37 * V_295 ,
struct V_278 * V_296 , const T_36 * V_280 ,
T_6 V_266 , T_21 V_267 )
{
T_6 V_283 ;
T_39 * V_199 ;
T_38 V_284 ;
T_6 V_285 ;
V_285 = TRUE ;
if ( V_206 ) {
if ( V_156 . V_157 || V_156 . V_158 ||
V_156 . V_159 || V_156 . V_160 )
F_197 () ;
if ( V_259 -> V_107 || V_120 || V_266 ||
( V_267 & V_297 ) || F_208 ( & V_259 -> V_199 ) )
V_283 = TRUE ;
else
V_283 = FALSE ;
F_198 ( & V_284 , V_283 , V_118 && V_120 ) ;
if ( V_259 -> V_107 )
F_199 ( & V_284 , V_259 -> V_107 ) ;
F_209 ( & V_284 , & V_259 -> V_199 ) ;
if ( ( V_267 & V_298 ) || ( V_118 && V_119 ) )
V_199 = & V_259 -> V_199 ;
else
V_199 = NULL ;
F_210 ( & V_284 , V_296 , V_280 , V_295 , V_199 ) ;
if ( V_259 -> V_107 )
V_285 = F_202 ( V_259 -> V_107 , & V_284 ) ;
}
if ( V_285 ) {
if ( V_118 ) {
if ( V_206 )
F_211 ( V_259 , & V_284 ) ;
else
F_211 ( V_259 , NULL ) ;
if ( V_155 )
fflush ( stdout ) ;
if ( ferror ( stdout ) ) {
F_151 ( V_231 ) ;
exit ( 2 ) ;
}
}
}
if ( V_206 ) {
F_206 ( & V_284 ) ;
}
return V_285 || V_295 -> V_299 . V_300 ;
}
static int
F_143 ( V_258 * V_259 , char * V_187 , int V_97 ,
T_6 V_100 , int V_301 , T_32 V_302 )
{
T_1 V_303 ;
int V_304 ;
T_40 * V_305 ;
T_11 V_282 ;
int V_88 ;
T_8 * V_264 = NULL ;
T_32 V_265 ;
char * V_64 = NULL ;
T_6 V_266 ;
T_21 V_267 ;
T_41 * V_306 ;
T_42 * V_307 ;
char V_308 [ 100 ] ;
V_306 = F_212 ( V_259 -> V_208 ) ;
V_307 = F_213 ( V_259 -> V_208 ) ;
#ifdef F_54
if ( V_307 -> V_309 > 1 ) {
V_303 = V_310 ;
} else {
V_303 = F_214 ( V_259 -> V_208 ) ;
}
#else
V_303 = F_214 ( V_259 -> V_208 ) ;
#endif
if ( V_187 != NULL ) {
V_64 = F_42 ( V_187 ) ;
V_304 = F_215 ( V_259 -> V_208 ) ;
if ( V_304 == 0 ) {
V_304 = V_311 ;
}
if ( V_306 -> V_312 == NULL ) {
F_216 ( V_308 , sizeof( V_308 ) , L_3 V_15 L_8 , V_16 ) ;
V_306 -> V_312 = V_308 ;
}
if ( V_303 != V_310 && V_97 == V_99 )
V_305 = F_217 ( V_187 , V_97 , V_303 ,
V_304 , FALSE , & V_88 ) ;
else
V_305 = F_218 ( V_187 , V_97 , V_303 ,
V_304 , FALSE , V_306 , V_307 , & V_88 ) ;
F_11 ( V_307 ) ;
V_307 = NULL ;
if ( V_305 == NULL ) {
switch ( V_88 ) {
case V_313 :
F_33 ( L_236 ) ;
break;
case V_314 :
case V_315 :
F_33 ( L_237
L_238 , F_6 ( V_97 ) ) ;
break;
case V_316 :
F_33 ( L_239
L_240 , V_64 ) ;
break;
case V_317 :
F_33 ( L_241 ,
V_64 ) ;
break;
default:
F_33 ( L_242 , V_64 ,
F_219 ( V_88 ) ) ;
break;
}
goto V_318;
}
} else {
if ( V_118 ) {
if ( ! F_150 ( V_259 ) ) {
V_88 = V_231 ;
F_151 ( V_88 ) ;
goto V_318;
}
}
V_305 = NULL ;
}
if ( V_305 && V_100 ) {
if ( ! F_220 ( V_305 , F_221 () ) ) {
F_33 ( L_243 ,
F_6 ( V_97 ) ) ;
}
}
V_266 = F_178 () ;
V_267 = F_179 () ;
if ( V_149 ) {
T_37 * V_295 ;
int V_319 = V_301 ;
V_259 -> V_234 = F_222 () ;
while ( F_181 ( V_259 -> V_208 , & V_88 , & V_264 , & V_265 ) ) {
if ( F_195 ( V_259 , V_265 , F_184 ( V_259 -> V_208 ) ,
F_185 ( V_259 -> V_208 ) ) ) {
if ( ( -- V_301 == 0 ) || ( V_302 != 0 && V_265 >= V_302 ) ) {
V_88 = 0 ;
break;
}
}
}
F_223 ( V_259 -> V_208 ) ;
F_224 () ;
V_301 = V_319 ;
for ( V_282 = 1 ; V_88 == 0 && V_282 <= V_259 -> V_286 ; V_282 ++ ) {
V_295 = F_225 ( V_259 -> V_234 , V_282 ) ;
if ( F_226 ( V_259 -> V_208 , V_295 -> V_320 , & V_259 -> V_296 ,
V_259 -> V_280 , V_295 -> V_321 , & V_88 , & V_264 ) ) {
if ( F_207 ( V_259 , V_295 ,
& V_259 -> V_296 , V_259 -> V_280 ,
V_266 , V_267 ) ) {
if ( V_305 != NULL ) {
if ( ! F_227 ( V_305 , & V_259 -> V_296 , V_259 -> V_280 , & V_88 ) ) {
switch ( V_88 ) {
case V_314 :
fprintf ( V_7 ,
L_244 ,
V_282 , V_259 -> V_274 ,
F_6 ( V_97 ) ) ;
break;
default:
F_228 ( V_187 , V_88 , FALSE ) ;
break;
}
F_229 ( V_305 , & V_88 ) ;
F_11 ( V_306 ) ;
exit ( 2 ) ;
}
}
if ( ( -- V_301 == 0 ) || ( V_302 != 0 && V_265 >= V_302 ) ) {
V_88 = 0 ;
break;
}
}
}
}
}
else {
V_282 = 0 ;
while ( F_181 ( V_259 -> V_208 , & V_88 , & V_264 , & V_265 ) ) {
V_282 ++ ;
if ( F_183 ( V_259 , V_265 , F_184 ( V_259 -> V_208 ) ,
F_185 ( V_259 -> V_208 ) ,
V_266 , V_267 ) ) {
if ( V_305 != NULL ) {
if ( ! F_227 ( V_305 , F_184 ( V_259 -> V_208 ) , F_185 ( V_259 -> V_208 ) , & V_88 ) ) {
switch ( V_88 ) {
case V_314 :
fprintf ( V_7 ,
L_244 ,
V_282 , V_259 -> V_274 ,
F_6 ( V_97 ) ) ;
break;
default:
F_228 ( V_187 , V_88 , FALSE ) ;
break;
}
F_229 ( V_305 , & V_88 ) ;
F_11 ( V_306 ) ;
exit ( 2 ) ;
}
}
if ( ( -- V_301 == 0 ) || ( V_302 != 0 && V_265 >= V_302 ) ) {
V_88 = 0 ;
break;
}
}
}
}
if ( V_88 != 0 ) {
#ifndef V_17
if ( V_118 ) {
struct V_322 V_323 , V_324 ;
if ( F_230 ( 1 , & V_323 ) == 0 && F_230 ( 2 , & V_324 ) == 0 ) {
if ( V_323 . V_325 == V_324 . V_325 &&
V_323 . V_326 == V_324 . V_326 ) {
fflush ( stdout ) ;
fprintf ( V_7 , L_7 ) ;
}
}
}
#endif
switch ( V_88 ) {
case V_327 :
F_33 ( L_245 ,
V_259 -> V_274 , V_264 ) ;
F_11 ( V_264 ) ;
break;
case V_314 :
F_33 ( L_246 ,
V_259 -> V_274 , V_264 ) ;
F_11 ( V_264 ) ;
break;
case V_328 :
F_33 ( L_247 ,
V_259 -> V_274 ) ;
break;
case V_329 :
F_33 ( L_248 ,
V_259 -> V_274 ) ;
break;
case V_330 :
F_33 ( L_249 ,
V_259 -> V_274 , V_264 ) ;
F_11 ( V_264 ) ;
break;
case V_331 :
F_33 ( L_250
L_251 , V_259 -> V_274 , V_264 ) ;
break;
default:
F_33 ( L_252 ,
V_259 -> V_274 , F_219 ( V_88 ) ) ;
break;
}
if ( V_187 != NULL ) {
if ( ! F_229 ( V_305 , & V_88 ) )
F_228 ( V_187 , V_88 , TRUE ) ;
}
} else {
if ( V_187 != NULL ) {
if ( ! F_229 ( V_305 , & V_88 ) )
F_228 ( V_187 , V_88 , TRUE ) ;
} else {
if ( V_118 ) {
if ( ! F_153 () ) {
V_88 = V_231 ;
F_151 ( V_88 ) ;
}
}
}
}
V_318:
F_175 ( V_259 -> V_208 ) ;
V_259 -> V_208 = NULL ;
F_11 ( V_64 ) ;
F_11 ( V_306 ) ;
return V_88 ;
}
static T_6
F_183 ( V_258 * V_259 , T_32 V_277 , struct V_278 * V_279 ,
const T_36 * V_280 ,
T_6 V_266 , T_21 V_267 )
{
T_37 V_295 ;
T_6 V_283 ;
T_39 * V_199 ;
T_38 V_284 ;
T_6 V_285 ;
V_259 -> V_286 ++ ;
V_285 = TRUE ;
F_196 ( & V_295 , V_259 -> V_286 , V_279 , V_277 , V_287 ) ;
if ( V_206 ) {
if ( V_118 && ( V_156 . V_157 || V_156 . V_158 ||
V_156 . V_159 || V_156 . V_160 ) )
F_197 () ;
if ( V_259 -> V_106 || V_259 -> V_107 || V_120 || V_266 ||
( V_267 & V_297 ) || F_208 ( & V_259 -> V_199 ) )
V_283 = TRUE ;
else
V_283 = FALSE ;
F_198 ( & V_284 , V_283 , V_118 && V_120 ) ;
if ( V_259 -> V_106 )
F_199 ( & V_284 , V_259 -> V_106 ) ;
if ( V_259 -> V_107 )
F_199 ( & V_284 , V_259 -> V_107 ) ;
F_209 ( & V_284 , & V_259 -> V_199 ) ;
if ( ( V_267 & V_298 ) || ( V_118 && V_119 ) || F_231 ( V_148 ) )
V_199 = & V_259 -> V_199 ;
else
V_199 = NULL ;
F_200 ( & V_295 , & V_259 -> V_288 ,
& V_289 , V_290 , V_291 ) ;
F_210 ( & V_284 , V_279 , V_280 , & V_295 , V_199 ) ;
if ( V_259 -> V_106 )
V_285 = F_202 ( V_259 -> V_106 , & V_284 ) ;
if ( V_285 && V_259 -> V_107 )
V_285 = F_202 ( V_259 -> V_107 , & V_284 ) ;
}
if ( V_285 ) {
F_203 ( & V_295 , & V_287 ) ;
if ( V_118 ) {
if ( V_206 )
F_211 ( V_259 , & V_284 ) ;
else
F_211 ( V_259 , NULL ) ;
if ( V_155 )
fflush ( stdout ) ;
if ( ferror ( stdout ) ) {
F_151 ( V_231 ) ;
exit ( 2 ) ;
}
}
V_332 = V_295 ;
V_290 = & V_332 ;
}
V_333 = V_295 ;
V_291 = & V_333 ;
if ( V_206 ) {
F_206 ( & V_284 ) ;
F_205 ( & V_295 ) ;
}
return V_285 ;
}
static T_6
F_150 ( V_258 * V_259 )
{
switch ( V_174 ) {
case V_175 :
return F_232 ( V_205 , V_259 ? V_259 -> V_274 : NULL ) ;
case V_177 :
if ( V_120 )
F_233 ( stdout , V_259 ? V_259 -> V_274 : NULL ) ;
else
F_234 ( stdout ) ;
return ! ferror ( stdout ) ;
case V_178 :
F_235 ( V_148 , stdout ) ;
return ! ferror ( stdout ) ;
default:
F_36 () ;
return FALSE ;
}
}
static char *
F_236 ( T_43 V_184 )
{
static char * V_334 = NULL ;
static T_43 V_335 = 256 ;
T_43 V_336 ;
for ( V_336 = V_335 ; V_184 > V_336 ;
V_336 *= 2 )
;
if ( V_334 == NULL ) {
V_335 = V_336 ;
V_334 = ( char * ) F_166 ( V_335 + 1 ) ;
} else {
if ( V_336 > V_335 ) {
V_335 = V_336 ;
V_334 = ( char * ) F_237 ( V_334 , V_335 + 1 ) ;
}
}
return V_334 ;
}
static T_6
F_238 ( V_258 * V_259 )
{
char * V_334 ;
int V_9 ;
T_43 V_337 ;
T_43 V_338 ;
V_334 = F_236 ( 256 ) ;
V_337 = 0 ;
* V_334 = '\0' ;
for ( V_9 = 0 ; V_9 < V_259 -> V_199 . V_200 ; V_9 ++ ) {
if ( ! F_239 ( V_9 ) )
continue;
switch ( V_259 -> V_199 . V_339 [ V_9 ] ) {
case V_340 :
#ifdef F_14
if ( V_133 . V_183 -> V_184 > 0 )
continue;
#endif
V_338 = strlen ( V_259 -> V_199 . V_341 [ V_9 ] ) ;
if ( V_338 < 3 )
V_338 = 3 ;
V_334 = F_236 ( V_337 + V_338 ) ;
F_216 ( V_334 + V_337 , ( int ) V_338 + 1 , L_253 , V_259 -> V_199 . V_341 [ V_9 ] ) ;
break;
case V_342 :
case V_343 :
case V_344 :
case V_345 :
case V_346 :
case V_347 :
V_338 = strlen ( V_259 -> V_199 . V_341 [ V_9 ] ) ;
if ( V_338 < 10 )
V_338 = 10 ;
V_334 = F_236 ( V_337 + V_338 ) ;
F_216 ( V_334 + V_337 , ( int ) V_338 + 1 , L_254 , V_259 -> V_199 . V_341 [ V_9 ] ) ;
break;
case V_348 :
case V_349 :
case V_350 :
case V_351 :
case V_352 :
case V_353 :
case V_354 :
case V_355 :
case V_356 :
V_338 = strlen ( V_259 -> V_199 . V_341 [ V_9 ] ) ;
if ( V_338 < 12 )
V_338 = 12 ;
V_334 = F_236 ( V_337 + V_338 ) ;
F_216 ( V_334 + V_337 , ( int ) V_338 + 1 , L_255 , V_259 -> V_199 . V_341 [ V_9 ] ) ;
break;
case V_357 :
case V_358 :
case V_359 :
case V_360 :
case V_361 :
case V_362 :
case V_363 :
case V_364 :
case V_365 :
V_338 = strlen ( V_259 -> V_199 . V_341 [ V_9 ] ) ;
if ( V_338 < 12 )
V_338 = 12 ;
V_334 = F_236 ( V_337 + V_338 ) ;
F_216 ( V_334 + V_337 , ( int ) V_338 + 1 , L_256 , V_259 -> V_199 . V_341 [ V_9 ] ) ;
break;
default:
V_338 = strlen ( V_259 -> V_199 . V_341 [ V_9 ] ) ;
V_334 = F_236 ( V_337 + V_338 ) ;
F_240 ( V_334 + V_337 , V_259 -> V_199 . V_341 [ V_9 ] , V_338 + 1 ) ;
break;
}
V_337 += V_338 ;
if ( V_9 != V_259 -> V_199 . V_200 - 1 ) {
V_334 = F_236 ( V_337 + 4 ) ;
switch ( V_259 -> V_199 . V_339 [ V_9 ] ) {
case V_348 :
case V_349 :
case V_350 :
switch ( V_259 -> V_199 . V_339 [ V_9 + 1 ] ) {
case V_357 :
case V_358 :
case V_359 :
F_240 ( V_334 + V_337 , L_257 , 5 ) ;
V_337 += 4 ;
break;
default:
F_240 ( V_334 + V_337 , L_258 , 5 ) ;
V_337 += 1 ;
break;
}
break;
case V_351 :
case V_352 :
case V_353 :
switch ( V_259 -> V_199 . V_339 [ V_9 + 1 ] ) {
case V_360 :
case V_361 :
case V_362 :
F_240 ( V_334 + V_337 , L_257 , 5 ) ;
V_337 += 4 ;
break;
default:
F_240 ( V_334 + V_337 , L_258 , 5 ) ;
V_337 += 1 ;
break;
}
break;
case V_354 :
case V_355 :
case V_356 :
switch ( V_259 -> V_199 . V_339 [ V_9 + 1 ] ) {
case V_363 :
case V_364 :
case V_365 :
F_240 ( V_334 + V_337 , L_257 , 5 ) ;
V_337 += 4 ;
break;
default:
F_240 ( V_334 + V_337 , L_258 , 5 ) ;
V_337 += 1 ;
break;
}
break;
case V_357 :
case V_358 :
case V_359 :
switch ( V_259 -> V_199 . V_339 [ V_9 + 1 ] ) {
case V_348 :
case V_349 :
case V_350 :
F_240 ( V_334 + V_337 , L_259 , 5 ) ;
V_337 += 4 ;
break;
default:
F_240 ( V_334 + V_337 , L_258 , 5 ) ;
V_337 += 1 ;
break;
}
break;
case V_360 :
case V_361 :
case V_362 :
switch ( V_259 -> V_199 . V_339 [ V_9 + 1 ] ) {
case V_351 :
case V_352 :
case V_353 :
F_240 ( V_334 + V_337 , L_259 , 5 ) ;
V_337 += 4 ;
break;
default:
F_240 ( V_334 + V_337 , L_258 , 5 ) ;
V_337 += 1 ;
break;
}
break;
case V_363 :
case V_364 :
case V_365 :
switch ( V_259 -> V_199 . V_339 [ V_9 + 1 ] ) {
case V_354 :
case V_355 :
case V_356 :
F_240 ( V_334 + V_337 , L_259 , 5 ) ;
V_337 += 4 ;
break;
default:
F_240 ( V_334 + V_337 , L_258 , 5 ) ;
V_337 += 1 ;
break;
}
break;
default:
F_240 ( V_334 + V_337 , L_258 , 5 ) ;
V_337 += 1 ;
break;
}
}
}
return F_241 ( V_205 , 0 , V_334 ) ;
}
static T_6
F_211 ( V_258 * V_259 , T_38 * V_284 )
{
T_44 V_366 ;
if ( V_119 || F_231 ( V_148 ) ) {
F_242 ( V_284 , FALSE , TRUE ) ;
if ( V_119 ) {
switch ( V_174 ) {
case V_175 :
if ( ! F_238 ( V_259 ) )
return FALSE ;
break;
case V_177 :
F_243 ( V_284 , stdout ) ;
return ! ferror ( stdout ) ;
case V_178 :
F_36 () ;
break;
}
}
}
if ( V_120 ) {
switch ( V_174 ) {
case V_175 :
V_366 . V_121 = V_121 ;
V_366 . V_367 = V_120 ? V_368 : V_369 ;
if ( ! F_244 ( & V_366 , V_284 , V_205 ) )
return FALSE ;
if ( ! V_121 ) {
if ( ! F_241 ( V_205 , 0 , V_166 ) )
return FALSE ;
}
break;
case V_177 :
F_245 ( V_284 , stdout ) ;
printf ( L_7 ) ;
return ! ferror ( stdout ) ;
case V_178 :
F_246 ( V_148 , V_284 , & V_259 -> V_199 , stdout ) ;
printf ( L_7 ) ;
return ! ferror ( stdout ) ;
}
}
if ( V_121 ) {
if ( V_119 || V_120 ) {
if ( ! F_241 ( V_205 , 0 , L_134 ) )
return FALSE ;
}
if ( ! F_247 ( V_205 , V_284 ) )
return FALSE ;
if ( ! F_241 ( V_205 , 0 , V_166 ) )
return FALSE ;
}
return TRUE ;
}
static T_6
F_153 ( void )
{
switch ( V_174 ) {
case V_175 :
return F_248 ( V_205 ) ;
case V_177 :
if ( V_120 )
F_249 ( stdout ) ;
else
F_250 ( stdout ) ;
return ! ferror ( stdout ) ;
case V_178 :
F_251 ( V_148 , stdout ) ;
return ! ferror ( stdout ) ;
default:
F_36 () ;
return FALSE ;
}
}
T_45
F_140 ( V_258 * V_259 , const char * V_63 , T_6 V_254 , int * V_88 )
{
T_46 * V_208 ;
T_8 * V_264 ;
char V_370 [ 2048 + 1 ] ;
V_208 = F_252 ( V_63 , V_88 , & V_264 , V_149 ) ;
if ( V_208 == NULL )
goto V_371;
F_253 () ;
F_254 () ;
V_259 -> V_208 = V_208 ;
V_259 -> V_372 = 0 ;
V_259 -> V_274 = F_32 ( V_63 ) ;
V_259 -> V_254 = V_254 ;
V_259 -> V_373 = FALSE ;
V_259 -> V_374 = F_255 ( V_259 -> V_208 ) ;
V_259 -> V_286 = 0 ;
V_259 -> V_375 = FALSE ;
V_259 -> V_376 = 0 ;
V_259 -> V_377 = F_215 ( V_259 -> V_208 ) ;
if ( V_259 -> V_377 == 0 ) {
V_259 -> V_378 = FALSE ;
V_259 -> V_377 = V_311 ;
} else
V_259 -> V_378 = TRUE ;
F_256 ( & V_259 -> V_288 ) ;
F_257 ( & V_289 ) ;
V_290 = NULL ;
V_291 = NULL ;
V_259 -> V_255 = V_379 ;
F_258 ( V_259 -> V_208 , V_380 ) ;
F_259 ( V_259 -> V_208 , ( V_381 ) V_382 ) ;
return V_207 ;
V_371:
F_216 ( V_370 , sizeof V_370 ,
F_260 ( * V_88 , V_264 , FALSE , V_259 -> V_374 ) , V_63 ) ;
F_33 ( L_8 , V_370 ) ;
return V_261 ;
}
static void
F_228 ( const char * V_63 , int V_88 , T_6 V_383 )
{
char * V_64 ;
V_64 = F_42 ( V_63 ) ;
switch ( V_88 ) {
case V_384 :
F_33 ( L_260
L_261 ,
V_64 ) ;
break;
#ifdef F_261
case F_261 :
F_33 ( L_262
L_263 ,
V_64 ) ;
break;
#endif
case V_385 :
F_33 ( L_264 ,
V_64 ) ;
break;
case V_317 :
F_33 ( L_265 ,
V_64 ) ;
break;
default:
if ( V_383 ) {
F_33 ( L_266 , V_64 ,
F_219 ( V_88 ) ) ;
} else {
F_33 ( L_267 ,
V_64 , F_219 ( V_88 ) ) ;
}
break;
}
F_11 ( V_64 ) ;
}
static void
F_151 ( int V_88 )
{
switch ( V_88 ) {
case V_384 :
F_33 ( L_268
L_261 ) ;
break;
#ifdef F_261
case F_261 :
F_33 ( L_269
L_263 ) ;
break;
#endif
default:
F_33 ( L_270 ,
F_95 ( V_88 ) ) ;
break;
}
}
static const char *
F_260 ( int V_88 , T_8 * V_264 , T_6 V_386 ,
int V_387 )
{
const char * V_388 ;
static char V_389 [ 1024 + 1 ] ;
if ( V_88 < 0 ) {
switch ( V_88 ) {
case V_390 :
V_388 = L_271 ;
break;
case V_391 :
V_388 = L_272 ;
break;
case V_392 :
V_388 = L_273 ;
break;
case V_327 :
F_216 ( V_389 , sizeof( V_389 ) ,
L_274
L_251 , V_264 ) ;
F_11 ( V_264 ) ;
V_388 = V_389 ;
break;
case V_393 :
F_216 ( V_389 , sizeof( V_389 ) ,
L_275
L_276 , F_6 ( V_387 ) ) ;
V_388 = V_389 ;
break;
case V_313 :
V_388 = L_277 ;
break;
case V_314 :
if ( V_386 ) {
F_216 ( V_389 , sizeof( V_389 ) ,
L_278 ,
F_6 ( V_387 ) ) ;
} else {
F_216 ( V_389 , sizeof( V_389 ) ,
L_279
L_251 , V_264 ) ;
F_11 ( V_264 ) ;
}
V_388 = V_389 ;
break;
case V_315 :
if ( V_386 ) {
F_216 ( V_389 , sizeof( V_389 ) ,
L_278 ,
F_6 ( V_387 ) ) ;
V_388 = V_389 ;
} else
V_388 = L_280 ;
break;
case V_330 :
F_216 ( V_389 , sizeof( V_389 ) ,
L_281
L_251 , V_264 ) ;
F_11 ( V_264 ) ;
V_388 = V_389 ;
break;
case V_316 :
if ( V_386 )
V_388 = L_282 ;
else
V_388 = L_283 ;
break;
case V_329 :
V_388 = L_284
L_285 ;
break;
case V_317 :
V_388 = L_286 ;
break;
case V_394 :
V_388 = L_287 ;
break;
case V_331 :
F_216 ( V_389 , sizeof( V_389 ) ,
L_288
L_251 , V_264 ) ;
F_11 ( V_264 ) ;
V_388 = V_389 ;
break;
default:
F_216 ( V_389 , sizeof( V_389 ) ,
L_289 ,
V_386 ? L_290 : L_291 ,
F_219 ( V_88 ) ) ;
V_388 = V_389 ;
break;
}
} else
V_388 = F_262 ( V_88 , V_386 ) ;
return V_388 ;
}
static void
V_142 ( const char * V_274 , int V_88 , T_6 V_386 )
{
fprintf ( V_7 , L_292 ) ;
fprintf ( V_7 , F_262 ( V_88 , V_386 ) , V_274 ) ;
fprintf ( V_7 , L_7 ) ;
}
static void
V_141 ( const char * V_395 , T_47 V_396 )
{
fprintf ( V_7 , L_292 ) ;
vfprintf ( V_7 , V_395 , V_396 ) ;
fprintf ( V_7 , L_7 ) ;
}
static void
V_143 ( const char * V_274 , int V_88 )
{
F_33 ( L_293 ,
V_274 , F_95 ( V_88 ) ) ;
}
static void
V_144 ( const char * V_274 , int V_88 )
{
F_33 ( L_294 ,
V_274 , F_95 ( V_88 ) ) ;
}
void
F_33 ( const char * V_397 , ... )
{
T_47 V_396 ;
va_start ( V_396 , V_397 ) ;
V_141 ( V_397 , V_396 ) ;
va_end ( V_396 ) ;
}
void
F_110 ( const char * V_397 , ... )
{
T_47 V_396 ;
va_start ( V_396 , V_397 ) ;
vfprintf ( V_7 , V_397 , V_396 ) ;
fprintf ( V_7 , L_7 ) ;
va_end ( V_396 ) ;
}
