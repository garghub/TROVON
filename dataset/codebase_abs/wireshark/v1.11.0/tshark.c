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
fprintf ( V_14 , L_77 ) ;
fprintf ( V_14 , L_78 ) ;
fprintf ( V_14 , L_79 ) ;
fprintf ( V_14 , L_7 ) ;
fprintf ( V_14 , L_80 ) ;
fprintf ( V_14 , L_81 ) ;
fprintf ( V_14 , L_82 ) ;
fprintf ( V_14 , L_83 ) ;
fprintf ( V_14 , L_84 ) ;
fprintf ( V_14 , L_85 ) ;
fprintf ( V_14 , L_86 ) ;
fprintf ( V_14 , L_87 ) ;
#ifdef F_18
fprintf ( V_14 , L_7 ) ;
fprintf ( V_14 , L_88 ) ;
fprintf ( V_14 , L_89 ) ;
fprintf ( V_14 , L_90 ) ;
fprintf ( V_14 , L_7 ) ;
#endif
}
static void
F_19 ( void )
{
T_7 * V_14 ;
V_14 = stdout ;
fprintf ( V_14 , L_3 V_15 L_4 , V_16 ) ;
fprintf ( V_14 , L_7 ) ;
fprintf ( V_14 , L_91 ) ;
fprintf ( V_14 , L_7 ) ;
fprintf ( V_14 , L_92 ) ;
fprintf ( V_14 , L_93 ) ;
fprintf ( V_14 , L_94 ) ;
fprintf ( V_14 , L_95 ) ;
fprintf ( V_14 , L_96 ) ;
fprintf ( V_14 , L_97 ) ;
fprintf ( V_14 , L_98 ) ;
fprintf ( V_14 , L_99 ) ;
fprintf ( V_14 , L_100 ) ;
fprintf ( V_14 , L_7 ) ;
fprintf ( V_14 , L_101 ) ;
fprintf ( V_14 , L_102 ) ;
fprintf ( V_14 , L_103 ) ;
fprintf ( V_14 , L_7 ) ;
}
static void
F_20 ( const char * V_20 , const char * V_21 ,
T_3 V_14 )
{
if ( ( V_22 == NULL ) ||
( strcmp ( V_22 , V_20 ) != 0 ) ) {
fprintf ( ( T_7 * ) V_14 , L_104 , V_20 , V_21 ) ;
V_22 = V_20 ;
}
}
static void
F_21 ( const T_8 * T_9 V_6 , T_3 V_23 , T_3 V_14 )
{
int V_24 ;
const T_8 * V_25 ;
const T_8 * V_26 ;
V_24 = F_22 ( ( V_27 ) V_23 ) ;
if ( V_24 != - 1 ) {
V_25 = F_23 ( V_24 ) ;
V_26 = F_24 ( V_24 ) ;
F_25 ( V_25 != NULL ) ;
F_25 ( V_26 != NULL ) ;
if ( ( V_22 == NULL ) ||
( strcmp ( V_22 , V_25 ) != 0 ) ) {
fprintf ( ( T_7 * ) V_14 , L_104 ,
V_25 ,
V_26 ) ;
V_22 = V_25 ;
}
}
}
static void
F_26 ( const T_8 * T_9 V_6 , T_3 V_23 , T_3 V_28 )
{
int V_24 ;
const T_8 * V_29 ;
T_10 V_30 ;
F_25 ( V_23 ) ;
V_30 = ( T_10 ) V_28 ;
V_24 = F_22 ( ( V_27 ) V_23 ) ;
if ( V_24 != - 1 ) {
V_29 = F_23 ( V_24 ) ;
F_25 ( V_29 != NULL ) ;
if ( strcmp ( V_29 , V_30 -> V_31 ) == 0 ) {
if ( V_30 -> V_32 == 0 ) {
V_30 -> V_33 = ( V_27 ) V_23 ;
}
V_30 -> V_32 ++ ;
}
}
}
static T_1
F_27 ( T_2 V_34 , T_2 V_35 )
{
return strcmp ( ( const char * ) V_34 , ( const char * ) V_35 ) ;
}
static void
F_28 ( T_7 * V_14 )
{
V_22 = NULL ;
F_29 ( F_20 , ( T_3 ) V_14 , ( V_36 ) F_27 ) ;
}
static void
F_30 ( T_7 * V_14 , T_8 * V_20 )
{
V_22 = NULL ;
F_31 ( V_20 ,
F_21 ,
( T_3 ) V_14 ) ;
}
static T_6
F_32 ( const T_8 * V_37 )
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
F_25 ( V_37 ) ;
V_40 = F_33 ( V_37 ) ;
F_25 ( V_40 ) ;
V_20 = V_40 ;
V_41 = strchr ( V_20 , '=' ) ;
if ( V_41 == NULL ) {
F_34 ( L_105 , V_37 , V_19 ) ;
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
F_34 ( L_106 ) ;
}
else {
V_45 = F_35 ( V_20 ) ;
if ( ! V_45 ) {
F_34 ( L_107 , V_20 ) ;
}
}
if ( ! V_45 ) {
F_34 ( L_108 ) ;
F_28 ( V_7 ) ;
}
if ( V_41 == NULL || ! V_45 ) {
F_11 ( V_40 ) ;
return FALSE ;
}
if ( * ( V_41 + 1 ) != '=' ) {
F_34 ( L_109 , V_20 , V_41 + 1 ) ;
}
else {
V_41 ++ ;
* V_41 = '\0' ;
}
V_41 ++ ;
V_42 = V_41 ;
V_41 = strchr ( V_42 , ',' ) ;
if ( V_41 == NULL ) {
F_34 ( L_105 , V_37 , V_19 ) ;
}
else {
* V_41 = '\0' ;
}
V_46 = F_36 ( V_20 ) ;
switch ( V_46 ) {
case V_50 :
case V_51 :
case V_52 :
case V_53 :
switch ( sscanf ( V_42 , L_110 , & V_38 , & V_49 , & V_39 ) ) {
case 1 :
V_49 = '\0' ;
break;
case 3 :
if ( V_49 != ':' && V_49 != '-' ) {
F_34 ( L_111 , V_42 ) ;
F_11 ( V_40 ) ;
return FALSE ;
}
if ( V_49 == ':' ) {
if ( ( V_39 == 0 ) || ( ( T_14 ) V_38 + V_39 - 1 ) > V_54 ) {
F_34 ( L_111 , V_42 ) ;
F_11 ( V_40 ) ;
return FALSE ;
}
}
else if ( V_39 < V_38 ) {
F_34 ( L_111 , V_42 ) ;
F_11 ( V_40 ) ;
return FALSE ;
}
break;
default:
F_34 ( L_112 , V_42 ) ;
F_11 ( V_40 ) ;
return FALSE ;
}
break;
case V_55 :
case V_56 :
break;
default:
F_37 () ;
}
if ( V_41 == NULL ) {
F_34 ( L_113 , V_20 ) ;
F_30 ( V_7 , V_20 ) ;
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
F_34 ( L_114 ) ;
}
else {
V_48 . V_32 = 0 ;
V_48 . V_31 = V_43 ;
V_48 . V_33 = NULL ;
F_31 ( V_20 , F_26 , & V_48 ) ;
if ( V_48 . V_32 != 0 ) {
V_44 = V_48 . V_33 ;
if ( V_48 . V_32 > 1 ) {
F_34 ( L_115 , V_43 , V_48 . V_32 ) ;
}
}
else {
if ( F_38 ( V_43 ) == - 1 ) {
F_34 ( L_116 , V_43 ) ;
} else {
F_34 ( L_117 ,
V_43 , V_20 ) ;
}
}
}
if ( ! V_44 ) {
F_34 ( L_113 , V_20 ) ;
F_30 ( V_7 , V_20 ) ;
F_11 ( V_40 ) ;
return FALSE ;
}
switch ( V_46 ) {
case V_50 :
case V_51 :
case V_52 :
case V_53 :
if ( V_49 == '\0' ) {
F_39 ( V_20 , V_38 , V_44 ) ;
} else if ( V_49 == ':' ) {
for ( V_9 = V_38 ; V_9 < ( T_14 ) V_38 + V_39 ; V_9 ++ ) {
F_39 ( V_20 , ( T_11 ) V_9 , V_44 ) ;
}
} else {
for ( V_9 = V_38 ; V_9 <= V_39 ; V_9 ++ ) {
F_39 ( V_20 , ( T_11 ) V_9 , V_44 ) ;
}
}
break;
case V_55 :
case V_56 :
F_40 ( V_20 , V_42 , V_44 ) ;
break;
default:
F_37 () ;
}
F_11 ( V_40 ) ;
return TRUE ;
}
static void
F_41 ( const T_8 * V_57 , T_15 V_58 ,
const T_8 * V_59 , T_3 V_28 )
{
if ( ( V_58 & V_60 & V_61 . V_62 ) == 0 &&
V_61 . V_62 != 0 ) {
return;
}
F_42 ( V_57 , V_58 , V_59 , V_28 ) ;
}
static char *
F_43 ( const char * V_63 )
{
char * V_64 ;
if ( strcmp ( V_63 , L_118 ) == 0 ) {
V_64 = F_33 ( L_119 ) ;
} else {
V_64 = F_44 ( L_120 , V_63 ) ;
}
return V_64 ;
}
static void
F_45 ( void ) {
T_8 * V_65 , * V_66 ;
if ( F_46 () ) {
V_65 = F_47 () ;
V_66 = F_48 () ;
fprintf ( V_7 , L_121 ,
V_65 , V_66 ) ;
F_11 ( V_65 ) ;
F_11 ( V_66 ) ;
if ( F_49 () ) {
fprintf ( V_7 , L_122 ) ;
}
fprintf ( V_7 , L_7 ) ;
}
}
static void
F_50 ( void ) {
#ifdef V_17
F_51 () ;
if ( ! F_52 () && F_53 () >= 6 ) {
fprintf ( V_7 , L_123
L_124 ) ;
}
#endif
}
static void
F_54 ( T_16 * V_67 , T_16 * V_68 )
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
struct V_74 V_75 [] = {
{ ( char * ) L_125 , V_76 , NULL , V_77 } ,
{ 0 , 0 , 0 , 0 }
} ;
T_6 V_78 = FALSE ;
#ifdef V_17
T_17 V_79 ;
#endif
char * V_80 , * V_81 ;
char * V_82 , * V_83 ;
int V_84 , V_85 ;
int V_86 , V_87 ;
int V_88 , V_89 ;
int V_90 , V_91 ;
int V_92 ;
volatile int V_93 = 0 ;
#ifdef F_14
T_6 V_94 = FALSE ;
T_6 V_95 = FALSE ;
int V_96 ;
T_18 * V_97 ;
T_8 * V_98 ;
#else
T_6 V_99 = FALSE ;
#endif
T_6 V_100 = FALSE ;
#ifdef F_55
volatile int V_101 = V_102 ;
#else
volatile int V_101 = V_103 ;
#endif
volatile T_6 V_104 = FALSE ;
T_8 * volatile V_105 = NULL ;
T_8 * V_106 = NULL ;
T_8 * V_107 = NULL ;
#ifdef F_56
struct V_108 V_109 ;
#endif
T_19 * V_110 = NULL ;
T_19 * V_111 = NULL ;
T_20 * V_112 ;
char V_113 ;
int V_114 ;
int V_115 ;
T_8 * V_116 = NULL ;
#ifdef F_17
#define F_57 "A:"
#else
#define F_57 ""
#endif
#ifdef F_14
#if F_16 ( V_17 ) || F_16 ( F_15 )
#define F_58 "B:"
#else
#define F_58 ""
#endif
#else
#define F_58 ""
#endif
#ifdef F_15
#define F_59 "I"
#else
#define F_59 ""
#endif
#define F_60 "-2a:" OPTSTRING_A "b:" OPTSTRING_B "c:C:d:De:E:f:F:gG:hH:i:" OPTSTRING_I "K:lLnN:o:O:pPqQr:R:s:S:t:T:u:vVw:W:xX:y:Y:z:"
static const char V_117 [] = F_60 ;
V_67 = F_61 ( L_126 ) ;
F_62 ( V_67 , NULL , V_118 ) ;
V_68 = F_61 ( L_127 ) ;
F_63 ( V_68 , NULL ) ;
F_64 ( L_3 V_15 L_4
L_7
L_8
L_7
L_8 ,
V_16 , V_67 -> V_69 , V_68 -> V_69 ) ;
#ifdef V_17
F_65 ( V_70 , V_71 ) ;
F_66 () ;
#if ! F_67 ( 2 , 31 , 0 )
F_68 ( NULL ) ;
#endif
#endif
F_69 () ;
V_72 = F_70 ( V_71 [ 0 ] , main ) ;
if ( V_72 != NULL ) {
fprintf ( V_7 , L_128 ,
V_72 ) ;
}
V_119 = 0 ;
V_115 = V_120 ;
while ( ( V_73 = F_71 ( V_70 , V_71 , V_117 ) ) != - 1 ) {
switch ( V_73 ) {
case 'C' :
if ( F_72 ( V_121 , FALSE ) ) {
F_73 ( V_121 ) ;
} else {
F_34 ( L_129 , V_121 ) ;
return 1 ;
}
break;
case 'P' :
V_122 = TRUE ;
V_123 = TRUE ;
break;
case 'O' :
V_116 = F_33 ( V_121 ) ;
case 'V' :
V_124 = TRUE ;
V_122 = TRUE ;
break;
case 'x' :
V_125 = TRUE ;
V_122 = TRUE ;
break;
case 'X' :
F_74 ( V_121 ) ;
break;
default:
break;
}
}
if ( V_123 == - 1 )
V_123 = ( V_124 || V_125 ) ? FALSE : TRUE ;
V_120 = V_115 ;
V_119 = 1 ;
V_114 =
V_126 |
V_127 |
V_128 |
V_129 |
V_130 |
V_131 |
V_132 | V_133 ;
F_75 ( NULL ,
( T_15 ) V_114 ,
F_41 , NULL ) ;
F_75 ( V_134 ,
( T_15 ) V_114 ,
F_41 , NULL ) ;
#ifdef F_14
F_75 ( V_135 ,
( T_15 ) V_114 ,
F_41 , NULL ) ;
F_75 ( V_136 ,
( T_15 ) V_114 ,
F_41 , NULL ) ;
#endif
F_76 () ;
#ifdef F_14
F_77 ( & V_137 ) ;
F_78 ( & V_138 , ( void * ) & V_139 ) ;
#endif
F_79 ( V_140 ) ;
F_80 ( V_141 ) ;
F_81 ( V_142 ) ;
F_82 ( V_143 , V_144 , NULL , NULL ,
V_145 , V_146 , V_147 ,
V_148 ) ;
#ifdef F_83
F_84 () ;
#endif
F_85 () ;
if ( V_70 >= 2 && strcmp ( V_71 [ 1 ] , L_130 ) == 0 ) {
F_86 () ;
if ( V_70 == 2 )
F_87 () ;
else {
if ( strcmp ( V_71 [ 2 ] , L_131 ) == 0 )
F_88 () ;
else if ( strcmp ( V_71 [ 2 ] , L_132 ) == 0 ) {
F_89 ( & V_84 , & V_85 , & V_80 ,
& V_86 , & V_87 , & V_81 ) ;
F_90 ( NULL ) ;
}
else if ( strcmp ( V_71 [ 2 ] , L_133 ) == 0 )
F_91 () ;
else if ( strcmp ( V_71 [ 2 ] , L_134 ) == 0 )
F_90 ( NULL ) ;
else if ( strcmp ( V_71 [ 2 ] , L_135 ) == 0 )
F_87 () ;
else if ( strcmp ( V_71 [ 2 ] , L_136 ) == 0 )
F_92 () ;
else if ( strcmp ( V_71 [ 2 ] , L_137 ) == 0 )
F_93 () ;
else if ( strcmp ( V_71 [ 2 ] , L_138 ) == 0 )
F_94 () ;
else if ( strcmp ( V_71 [ 2 ] , L_139 ) == 0 )
F_95 () ;
else if ( strcmp ( V_71 [ 2 ] , L_140 ) == 0 )
F_96 () ;
else if ( strcmp ( V_71 [ 2 ] , L_141 ) == 0 )
F_19 () ;
else if ( strcmp ( V_71 [ 2 ] , L_142 ) == 0 )
F_19 () ;
else {
F_34 ( L_143 , V_71 [ 2 ] ) ;
return 1 ;
}
}
return 0 ;
}
setlocale ( V_149 , L_144 ) ;
V_112 = F_89 ( & V_84 , & V_85 , & V_80 ,
& V_86 , & V_87 , & V_81 ) ;
if ( V_80 != NULL ) {
if ( V_84 != 0 ) {
F_34 ( L_145 ,
V_81 , F_97 ( V_84 ) ) ;
}
if ( V_85 != 0 ) {
F_34 ( L_146 ,
V_81 , F_97 ( V_85 ) ) ;
}
}
if ( V_81 != NULL ) {
if ( V_86 != 0 ) {
F_34 ( L_147 , V_81 ,
F_97 ( V_86 ) ) ;
}
if ( V_87 != 0 ) {
F_34 ( L_148 ,
V_81 , F_97 ( V_87 ) ) ;
}
F_11 ( V_81 ) ;
V_81 = NULL ;
}
F_98 ( & V_82 , & V_88 , & V_89 ,
& V_83 , & V_90 , & V_91 ) ;
if ( V_82 != NULL ) {
if ( V_88 != 0 ) {
F_34 ( L_149 ,
V_82 , F_97 ( V_88 ) ) ;
}
if ( V_89 != 0 ) {
F_34 ( L_150 ,
V_82 , F_97 ( V_89 ) ) ;
}
F_11 ( V_82 ) ;
}
if ( V_83 != NULL ) {
if ( V_90 != 0 ) {
F_34 (
L_151 , V_83 ,
F_97 ( V_90 ) ) ;
}
if ( V_91 != 0 ) {
F_34 (
L_152 , V_83 ,
F_97 ( V_91 ) ) ;
}
F_11 ( V_83 ) ;
}
F_50 () ;
F_99 ( & V_139 ) ;
V_150 = V_151 ;
V_152 = F_100 () ;
while ( ( V_73 = F_101 ( V_70 , V_71 , V_117 , V_75 , NULL ) ) != - 1 ) {
switch ( V_73 ) {
case '2' :
V_153 = TRUE ;
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
case V_77 :
#if F_16 ( V_17 ) || F_16 ( F_15 )
case 'B' :
#endif
#ifdef F_14
V_96 = F_102 ( & V_137 , V_73 , V_121 , & V_95 ) ;
if ( V_96 != 0 ) {
return V_96 ;
}
#else
V_99 = TRUE ;
V_78 = TRUE ;
#endif
break;
case 'C' :
break;
case 'd' :
if ( ! F_32 ( V_121 ) )
return 1 ;
break;
#if F_16 ( V_154 ) || F_16 ( V_155 )
case 'K' :
F_103 ( V_121 ) ;
break;
#endif
case 'D' :
#ifdef F_14
V_97 = F_104 ( & V_92 , & V_98 , NULL ) ;
if ( V_97 == NULL ) {
switch ( V_92 ) {
case V_156 :
case V_157 :
F_34 ( L_8 , V_98 ) ;
F_11 ( V_98 ) ;
break;
case V_158 :
F_34 ( L_153 ) ;
break;
}
return 2 ;
}
F_105 ( V_97 ) ;
F_106 ( V_97 ) ;
return 0 ;
#else
V_99 = TRUE ;
V_78 = TRUE ;
#endif
break;
case 'e' :
F_107 ( V_152 , V_121 ) ;
break;
case 'E' :
if ( ! F_108 ( V_152 , V_121 ) ) {
F_34 ( L_154 , V_121 ) ;
F_109 ( V_7 ) ;
return 1 ;
}
break;
case 'F' :
V_101 = F_110 ( V_121 ) ;
if ( V_101 < 0 ) {
F_34 ( L_155 , V_121 ) ;
F_3 () ;
return 1 ;
}
break;
case 'W' :
if ( strchr ( V_121 , 'n' ) ) {
V_104 = TRUE ;
} else {
F_34 ( L_156 , V_121 ) ;
return 1 ;
}
break;
case 'H' :
if ( ! F_111 ( V_121 ) )
{
F_34 ( L_157 , V_121 ) ;
return 1 ;
}
V_104 = TRUE ;
break;
case 'h' :
F_12 ( TRUE ) ;
return 0 ;
break;
case 'l' :
V_159 = TRUE ;
break;
case 'L' :
#ifdef F_14
V_94 = TRUE ;
#else
V_99 = TRUE ;
V_78 = TRUE ;
#endif
break;
case 'n' :
V_160 . V_161 = FALSE ;
V_160 . V_162 = FALSE ;
V_160 . V_163 = FALSE ;
V_160 . V_164 = FALSE ;
break;
case 'N' :
V_113 = F_112 ( V_121 , & V_160 ) ;
if ( V_113 != '\0' ) {
F_34 ( L_158 ,
V_113 ) ;
F_113 ( L_159 ) ;
return 1 ;
}
break;
case 'o' :
switch ( F_114 ( V_121 ) ) {
case V_165 :
break;
case V_166 :
F_34 ( L_160 , V_121 ) ;
return 1 ;
break;
case V_167 :
case V_168 :
F_34 ( L_161 , V_121 ) ;
return 1 ;
break;
}
break;
case 'q' :
V_100 = TRUE ;
break;
case 'Q' :
V_100 = TRUE ;
V_169 = TRUE ;
break;
case 'r' :
V_105 = F_33 ( V_121 ) ;
break;
case 'R' :
V_106 = V_121 ;
break;
case 'P' :
break;
case 'S' :
V_170 = F_115 ( V_121 ) ;
break;
case 't' :
if ( strcmp ( V_121 , L_162 ) == 0 )
F_79 ( V_140 ) ;
else if ( strcmp ( V_121 , L_163 ) == 0 )
F_79 ( V_171 ) ;
else if ( strcmp ( V_121 , L_164 ) == 0 )
F_79 ( V_172 ) ;
else if ( strcmp ( V_121 , L_165 ) == 0 )
F_79 ( V_173 ) ;
else if ( strcmp ( V_121 , L_166 ) == 0 )
F_79 ( V_174 ) ;
else if ( strcmp ( V_121 , L_167 ) == 0 )
F_79 ( V_175 ) ;
else if ( strcmp ( V_121 , L_168 ) == 0 )
F_79 ( V_176 ) ;
else if ( strcmp ( V_121 , L_169 ) == 0 )
F_79 ( V_177 ) ;
else {
F_34 ( L_170 ,
V_121 ) ;
F_113 ( L_171 ) ;
F_113 ( L_172 ) ;
F_113 ( L_173 ) ;
return 1 ;
}
break;
case 'T' :
if ( strcmp ( V_121 , L_174 ) == 0 ) {
V_178 = V_179 ;
V_150 = V_151 ;
} else if ( strcmp ( V_121 , L_175 ) == 0 ) {
V_178 = V_179 ;
V_150 = V_180 ;
} else if ( strcmp ( V_121 , L_176 ) == 0 ) {
V_178 = V_181 ;
V_124 = TRUE ;
V_123 = FALSE ;
} else if ( strcmp ( V_121 , L_177 ) == 0 ) {
V_178 = V_181 ;
V_124 = FALSE ;
V_123 = TRUE ;
} else if ( strcmp ( V_121 , L_135 ) == 0 ) {
V_178 = V_182 ;
V_124 = TRUE ;
V_123 = FALSE ;
} else {
F_34 ( L_178 ) ;
F_113 ( L_179 ) ;
return 1 ;
}
break;
case 'u' :
if ( strcmp ( V_121 , L_180 ) == 0 )
F_81 ( V_142 ) ;
else if ( strcmp ( V_121 , L_181 ) == 0 )
F_81 ( V_183 ) ;
else {
F_34 ( L_182 , V_121 ) ;
F_113 ( L_183 ) ;
return 1 ;
}
break;
case 'v' :
{
F_54 ( V_67 , V_68 ) ;
F_116 ( V_67 , TRUE ) ;
F_116 ( V_68 , TRUE ) ;
F_117 () ;
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
V_107 = V_121 ;
break;
case 'z' :
if ( ! F_118 ( V_121 ) ) {
if ( strcmp ( L_184 , V_121 ) == 0 ) {
fprintf ( V_7 , L_185 ) ;
F_119 () ;
return 0 ;
}
F_34 ( L_186 , V_121 ) ;
F_113 ( L_187 ) ;
F_119 () ;
return 1 ;
}
break;
default:
case '?' :
switch( V_184 ) {
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
if ( V_182 != V_178 && 0 != F_120 ( V_152 ) ) {
F_34 ( L_188
L_189 ) ;
return 1 ;
} else if ( V_182 == V_178 && 0 == F_120 ( V_152 ) ) {
F_34 ( L_190
L_191 ) ;
return 1 ;
}
if ( V_120 < V_70 ) {
if ( V_105 != NULL ) {
if ( V_107 != NULL ) {
F_34 ( L_192
L_193 ) ;
return 1 ;
}
V_107 = F_121 ( V_70 , V_71 , V_120 ) ;
} else {
#ifdef F_14
T_21 V_9 ;
if ( V_137 . V_185 . V_186 ) {
F_34 ( L_194
L_195 ) ;
return 1 ;
}
for ( V_9 = 0 ; V_9 < V_137 . V_187 -> V_188 ; V_9 ++ ) {
T_22 V_189 ;
V_189 = F_122 ( V_137 . V_187 , T_22 , V_9 ) ;
if ( V_189 . V_186 == NULL ) {
V_189 . V_186 = F_121 ( V_70 , V_71 , V_120 ) ;
V_137 . V_187 = F_123 ( V_137 . V_187 , V_9 ) ;
F_124 ( V_137 . V_187 , V_9 , V_189 ) ;
} else {
F_34 ( L_196
L_195 ) ;
return 1 ;
}
}
V_137 . V_185 . V_186 = F_121 ( V_70 , V_71 , V_120 ) ;
#else
V_99 = TRUE ;
#endif
}
}
#ifdef F_14
if ( ! V_137 . V_190 ) {
if ( ! V_100 )
V_122 = TRUE ;
} else {
if ( strcmp ( V_137 . V_191 , L_118 ) == 0 && V_122 ) {
F_34 ( L_197
L_198 ) ;
return 1 ;
}
}
#else
if ( ! V_100 )
V_122 = TRUE ;
#endif
#ifndef F_14
if ( V_99 )
F_34 ( L_199 ) ;
#endif
if ( V_78 ) {
F_12 ( FALSE ) ;
return 1 ;
}
if ( V_125 ) {
if ( V_178 != V_179 ) {
F_34 ( L_200 ) ;
return 1 ;
}
}
if ( V_116 != NULL ) {
char * V_192 ;
if ( ! V_124 ) {
F_34 ( L_201 ) ;
return 1 ;
}
V_193 = F_125 ( V_194 , V_195 ) ;
for ( V_192 = strtok ( V_116 , L_202 ) ; V_192 ; V_192 = strtok ( NULL , L_202 ) ) {
F_126 ( V_193 , ( T_3 ) V_192 , ( T_3 ) V_192 ) ;
}
}
if ( V_106 != NULL && ! V_153 ) {
F_34 ( L_203 ) ;
return 1 ;
}
#ifdef F_14
if ( V_94 ) {
if ( V_105 ) {
F_34 ( L_204 ) ;
return 1 ;
}
if ( V_137 . V_196 ) {
F_34 ( L_205 ) ;
return 1 ;
}
} else {
if ( V_105 ) {
if ( V_137 . V_185 . V_186 ) {
F_34 ( L_206
L_207 ) ;
return 1 ;
}
if ( V_137 . V_196 ) {
F_34 ( L_208
L_209 ) ;
return 1 ;
}
if ( V_137 . V_197 ) {
F_34 ( L_210
L_209 ) ;
return 1 ;
}
if ( V_137 . V_198 ) {
F_34 ( L_211
L_209 ) ;
return 1 ;
}
if ( V_137 . V_199 ) {
F_34 ( L_212
L_209 ) ;
return 1 ;
}
if ( V_137 . V_200 ) {
F_34 ( L_213
L_214
L_215 ) ;
return 1 ;
}
if ( V_137 . V_201 ) {
F_34 ( L_216
L_209 ) ;
return 1 ;
}
} else {
if ( V_137 . V_190 ) {
if ( V_101 != V_103 && V_101 != V_102 ) {
F_34 ( L_217 ) ;
return 1 ;
}
if ( V_137 . V_200 && V_101 != V_102 ) {
F_34 ( L_218 ) ;
return 1 ;
}
if ( V_137 . V_196 ) {
if ( strcmp ( V_137 . V_191 , L_118 ) == 0 ) {
F_34 ( L_208
L_219 ) ;
return 1 ;
}
if ( V_137 . V_202 ) {
F_34 ( L_208
L_220 ) ;
return 1 ;
}
if ( ! V_137 . V_203 &&
! V_137 . V_197 ) {
F_34 ( L_208
L_221 ) ;
return 1 ;
}
}
if ( V_106 != NULL ) {
F_34 ( L_222 ) ;
return 1 ;
}
if ( V_107 != NULL ) {
F_34 ( L_223 ) ;
return 1 ;
}
} else {
if ( V_137 . V_203 ) {
F_34 ( L_224
L_225 ) ;
return 1 ;
}
if ( V_137 . V_196 ) {
F_34 ( L_208
L_226 ) ;
return 1 ;
}
if ( V_137 . V_200 ) {
F_34 ( L_213
L_226 ) ;
return 1 ;
}
}
}
}
#endif
#ifdef V_17
F_127 ( F_128 ( 1 , 1 ) , & V_79 ) ;
#endif
F_129 () ;
F_130 () ;
#ifdef F_14
if ( V_137 . V_190 &&
V_137 . V_202 ) {
if ( F_131 () ) {
F_34 ( L_227 ) ;
return 1 ;
}
if ( V_122 ) {
F_34 ( L_228 ) ;
return 1 ;
}
}
#endif
if ( V_82 == NULL && V_83 == NULL ) {
F_132 () ;
}
F_133 ( & V_139 . V_204 , V_112 -> V_205 , TRUE ) ;
#ifdef F_14
F_134 ( & V_137 , V_206 ) ;
F_135 ( & V_137 ) ;
#endif
if ( V_106 != NULL ) {
if ( ! F_136 ( V_106 , & V_110 ) ) {
F_34 ( L_8 , V_207 ) ;
F_117 () ;
#ifdef F_56
{
T_23 * V_208 ;
V_208 = F_137 ( V_209 , V_206 ) ;
if ( V_208 != NULL ) {
if ( F_138 ( V_208 , & V_109 , V_106 , 0 , 0 ) != - 1 ) {
F_113 (
L_229 ) ;
F_113 (
L_230 ) ;
}
F_139 ( V_208 ) ;
}
}
#endif
return 2 ;
}
}
V_139 . V_110 = V_110 ;
if ( V_107 != NULL ) {
if ( ! F_136 ( V_107 , & V_111 ) ) {
F_34 ( L_8 , V_207 ) ;
F_117 () ;
#ifdef F_56
{
T_23 * V_208 ;
V_208 = F_137 ( V_209 , V_206 ) ;
if ( V_208 != NULL ) {
if ( F_138 ( V_208 , & V_109 , V_107 , 0 , 0 ) != - 1 ) {
F_113 (
L_231 ) ;
F_113 (
L_230 ) ;
}
F_139 ( V_208 ) ;
}
}
#endif
return 2 ;
}
}
V_139 . V_111 = V_111 ;
if ( V_122 ) {
if ( V_178 == V_179 ) {
switch ( V_150 ) {
case V_151 :
V_210 = F_140 ( stdout ) ;
break;
case V_180 :
V_210 = F_141 ( stdout ) ;
break;
default:
F_37 () ;
}
}
}
V_211 = V_122 || V_110 || V_111 || F_131 () ;
if ( V_105 ) {
F_142 () ;
F_45 () ;
if ( F_143 ( & V_139 , V_105 , FALSE , & V_92 ) != V_212 ) {
F_117 () ;
return 2 ;
}
switch( F_144 ( V_139 . V_213 ) ) {
case ( V_214 ) :
F_80 ( V_215 ) ;
break;
case ( V_216 ) :
F_80 ( V_217 ) ;
break;
case ( V_218 ) :
F_80 ( V_219 ) ;
break;
case ( V_220 ) :
F_80 ( V_221 ) ;
break;
case ( V_222 ) :
F_80 ( V_223 ) ;
break;
case ( V_224 ) :
F_80 ( V_225 ) ;
break;
default:
F_37 () ;
}
F_145 {
#ifdef F_14
V_92 = F_146 ( & V_139 , V_137 . V_191 , V_101 , V_104 ,
V_137 . V_226 ? V_137 . V_227 : 0 ,
V_137 . V_203 ? V_137 . V_228 : 0 ) ;
#else
V_92 = F_146 ( & V_139 , NULL , V_101 , V_104 , 0 , 0 ) ;
#endif
}
F_147 (OutOfMemoryError) {
fprintf ( V_7 ,
L_232
L_7
L_233
L_7
L_234
L_235 ) ;
V_92 = V_229 ;
}
V_230 ;
if ( V_92 != 0 ) {
V_93 = 2 ;
}
} else {
#ifdef F_14
V_93 = F_148 ( & V_137 ,
( ( V_112 -> V_231 ) && ( * V_112 -> V_231 != '\0' ) ) ? F_149 ( V_112 -> V_231 ) : NULL ) ;
if ( V_93 != 0 )
return V_93 ;
if ( V_94 ) {
T_21 V_9 ;
for ( V_9 = 0 ; V_9 < V_137 . V_187 -> V_188 ; V_9 ++ ) {
T_22 V_189 ;
T_24 * V_232 ;
V_189 = F_122 ( V_137 . V_187 , T_22 , V_9 ) ;
V_232 = F_150 ( V_189 . V_233 , V_189 . V_234 , & V_98 , NULL ) ;
if ( V_232 == NULL ) {
F_34 ( L_8 , V_98 ) ;
F_11 ( V_98 ) ;
return 2 ;
}
if ( V_232 -> V_235 == NULL ) {
F_34 ( L_236 , V_189 . V_233 ) ;
return 2 ;
}
F_151 ( V_232 , V_189 . V_233 , V_189 . V_234 ) ;
F_152 ( V_232 ) ;
}
return 0 ;
}
if ( ! F_153 ( fileno ( V_7 ) ) )
V_236 = FALSE ;
else if ( V_122 && F_153 ( fileno ( stdout ) ) )
V_236 = FALSE ;
else if ( V_100 )
V_236 = FALSE ;
else
V_236 = TRUE ;
if ( V_122 ) {
if ( ! F_154 ( NULL ) ) {
F_155 ( V_237 ) ;
return 2 ;
}
}
F_80 ( V_223 ) ;
F_156 () ;
V_93 = V_138 . V_238 ;
if ( V_122 ) {
if ( ! F_157 () ) {
V_92 = V_237 ;
F_155 ( V_92 ) ;
}
}
#else
F_34 ( L_199 ) ;
return 2 ;
#endif
}
F_11 ( V_105 ) ;
if ( V_139 . V_239 != NULL ) {
F_158 ( V_139 . V_239 ) ;
V_139 . V_239 = NULL ;
}
F_159 ( TRUE ) ;
F_160 () ;
F_161 ( V_139 . V_240 ) ;
F_117 () ;
F_162 ( V_152 ) ;
V_152 = NULL ;
return V_93 ;
}
static T_1
F_163 ( T_3 V_5 )
{
T_25 V_23 ;
T_26 V_241 = 0 ;
T_6 V_242 ;
T_26 V_243 ;
T_27 * V_244 = V_5 ;
T_1 V_245 = 0 ;
F_164 ( V_244 -> V_246 ) ;
while( V_245 < 5 ) {
V_23 = ( T_25 ) F_165 ( V_244 -> V_247 ) ;
V_242 = F_166 ( V_23 , NULL , 0 , NULL , & V_241 , NULL ) ;
F_167 ( ( T_25 ) * ( V_244 -> V_248 ) ,
& V_243 ) ;
if ( ! V_242 || V_241 > 0 || V_243 != V_249 ) {
if ( ! V_244 -> V_250 ( V_244 -> V_247 , V_244 -> V_28 ) ) {
F_168 ( NULL , V_131 , L_237 , V_245 ) ;
F_169 ( V_244 -> V_246 ) ;
return FALSE ;
}
}
else {
break;
}
V_245 ++ ;
}
F_169 ( V_244 -> V_246 ) ;
return TRUE ;
}
void
F_170 ( T_1 V_247 , T_3 V_28 , int * V_248 , T_28 V_250 )
{
V_251 . V_247 = V_247 ;
V_251 . V_248 = V_248 ;
V_251 . V_28 = V_28 ;
V_251 . V_250 = V_250 ;
#ifdef V_17
#if F_67 ( 2 , 31 , 0 )
V_251 . V_246 = F_171 ( sizeof( V_252 ) ) ;
F_172 ( V_251 . V_246 ) ;
#else
V_251 . V_246 = F_173 () ;
#endif
V_251 . V_253 = F_174 ( 200 , F_163 , & V_251 ) ;
#endif
}
static const T_29 *
F_175 ( void * V_5 , T_11 V_254 )
{
T_30 * V_255 = ( T_30 * ) V_5 ;
if ( V_256 && V_256 -> V_257 == V_254 )
return & V_256 -> V_258 ;
if ( V_259 && V_259 -> V_257 == V_254 )
return & V_259 -> V_258 ;
if ( V_260 && V_260 -> V_257 == V_254 )
return & V_260 -> V_258 ;
if ( V_255 -> V_239 ) {
T_31 * V_261 = F_176 ( V_255 -> V_239 , V_254 ) ;
return ( V_261 ) ? & V_261 -> V_258 : NULL ;
}
return NULL ;
}
static T_32 *
F_177 ( T_30 * V_255 )
{
T_32 * V_240 = F_178 () ;
V_240 -> V_5 = V_255 ;
V_240 -> V_262 = F_175 ;
V_240 -> V_263 = V_264 ;
V_240 -> V_265 = NULL ;
return V_240 ;
}
static T_6
F_156 ( void )
{
T_6 V_266 ;
T_21 V_9 ;
T_16 * V_69 = F_61 ( L_144 ) ;
#ifdef F_179
T_33 V_267 ;
#endif
#ifndef V_17
struct V_268 V_269 , V_270 ;
#endif
F_142 () ;
F_45 () ;
F_161 ( V_139 . V_240 ) ;
V_139 . V_240 = F_177 ( & V_139 ) ;
#ifdef V_17
F_180 ( V_271 , TRUE ) ;
#else
memset ( & V_269 , 0 , sizeof( V_269 ) ) ;
V_269 . V_272 = V_271 ;
V_269 . V_273 = V_274 ;
F_181 ( & V_269 . V_275 ) ;
V_268 ( V_276 , & V_269 , NULL ) ;
V_268 ( V_277 , & V_269 , NULL ) ;
V_268 ( V_278 , NULL , & V_270 ) ;
if ( V_270 . V_272 == V_279 )
V_268 ( V_278 , & V_269 , NULL ) ;
#ifdef F_182
V_269 . V_272 = V_280 ;
V_269 . V_273 = V_274 ;
F_181 ( & V_269 . V_275 ) ;
V_268 ( F_182 , & V_269 , NULL ) ;
#endif
#endif
V_138 . V_281 = V_282 ;
for ( V_9 = 0 ; V_9 < V_137 . V_187 -> V_188 ; V_9 ++ ) {
T_22 V_189 ;
V_189 = F_122 ( V_137 . V_187 , T_22 , V_9 ) ;
V_189 . V_283 = F_183 ( V_189 . V_233 ) ;
V_137 . V_187 = F_123 ( V_137 . V_187 , V_9 ) ;
F_124 ( V_137 . V_187 , V_9 , V_189 ) ;
}
#ifdef V_17
if ( V_137 . V_187 -> V_188 < 2 )
#else
if ( V_137 . V_187 -> V_188 < 4 )
#endif
{
for ( V_9 = 0 ; V_9 < V_137 . V_187 -> V_188 ; V_9 ++ ) {
T_22 V_189 ;
V_189 = F_122 ( V_137 . V_187 , T_22 , V_9 ) ;
if ( V_9 > 0 ) {
if ( V_137 . V_187 -> V_188 > 2 ) {
F_184 ( V_69 , L_202 ) ;
}
F_184 ( V_69 , L_238 ) ;
if ( V_9 == V_137 . V_187 -> V_188 - 1 ) {
F_184 ( V_69 , L_239 ) ;
}
}
F_184 ( V_69 , L_240 , V_189 . V_283 ) ;
}
} else {
F_184 ( V_69 , L_241 , V_137 . V_187 -> V_188 ) ;
}
if ( V_169 == FALSE )
fprintf ( V_7 , L_242 , V_69 -> V_69 ) ;
fflush ( V_7 ) ;
F_116 ( V_69 , TRUE ) ;
V_266 = F_185 ( & V_137 , & V_138 , NULL ) ;
if ( ! V_266 )
return FALSE ;
#ifdef F_179
F_186 ( & V_267 ) ;
F_187 ( V_251 . V_247 , & V_267 ) ;
#endif
V_284 = TRUE ;
F_145
{
while ( V_284 )
{
#ifdef F_179
V_266 = F_188 ( V_251 . V_247 + 1 , & V_267 , NULL , NULL , NULL ) ;
if ( V_266 == - 1 )
{
perror ( L_243 ) ;
return TRUE ;
} else if ( V_266 == 1 ) {
#endif
if ( ! V_251 . V_250 ( V_251 . V_247 , V_251 . V_28 ) ) {
F_168 ( NULL , V_131 , L_244 ) ;
return FALSE ;
}
#ifdef F_179
}
#endif
}
}
F_147 (OutOfMemoryError) {
fprintf ( V_7 ,
L_232
L_7
L_233
L_7
L_234
L_235 ) ;
exit ( 1 ) ;
}
V_230 ;
return TRUE ;
}
void
F_189 ( T_34 * T_35 V_6 , char * V_285 , char * V_286 )
{
F_34 ( L_8 , V_285 ) ;
F_113 ( L_8 , V_286 ) ;
}
void
F_190 ( T_34 * T_35 , T_21 V_9 , char * V_287 )
{
T_36 * V_288 = T_35 -> V_288 ;
T_19 * V_110 = NULL ;
T_22 V_189 ;
F_25 ( V_9 < V_288 -> V_187 -> V_188 ) ;
V_189 = F_122 ( V_288 -> V_187 , T_22 , V_9 ) ;
if ( F_136 ( V_189 . V_186 , & V_110 ) && V_110 != NULL ) {
F_34 (
L_245
L_7
L_246
L_247
L_7
L_248
L_249
L_7
L_250 ,
V_189 . V_186 , V_189 . V_283 , V_287 ) ;
F_191 ( V_110 ) ;
} else {
F_34 (
L_245
L_7
L_251
L_250 ,
V_189 . V_186 , V_189 . V_283 , V_287 ) ;
}
}
T_6
F_192 ( T_34 * T_35 , T_8 * V_289 )
{
T_36 * V_288 = T_35 -> V_288 ;
T_6 V_290 ;
int V_92 ;
if ( T_35 -> V_281 == V_282 ) {
F_168 ( V_135 , V_129 , L_252 ) ;
}
F_168 ( V_135 , V_129 , L_253 , V_289 ) ;
F_25 ( T_35 -> V_281 == V_282 || T_35 -> V_281 == V_291 ) ;
if ( V_288 -> V_191 != NULL ) {
if ( ( ( T_30 * ) T_35 -> V_255 ) -> V_281 != V_292 ) {
if ( ( ( T_30 * ) T_35 -> V_255 ) -> V_213 != NULL ) {
F_193 ( ( ( T_30 * ) T_35 -> V_255 ) -> V_213 ) ;
( ( T_30 * ) T_35 -> V_255 ) -> V_213 = NULL ;
}
( ( T_30 * ) T_35 -> V_255 ) -> V_281 = V_292 ;
}
F_11 ( V_288 -> V_191 ) ;
V_290 = FALSE ;
} else {
V_290 = TRUE ;
}
V_288 -> V_191 = F_33 ( V_289 ) ;
if ( V_211 ) {
switch( F_143 ( ( T_30 * ) T_35 -> V_255 , V_288 -> V_191 , V_290 , & V_92 ) ) {
case V_212 :
break;
case V_293 :
F_11 ( V_288 -> V_191 ) ;
V_288 -> V_191 = NULL ;
return FALSE ;
}
}
T_35 -> V_281 = V_291 ;
return TRUE ;
}
void
F_194 ( T_34 * T_35 , int V_294 )
{
T_6 V_266 ;
int V_92 ;
T_8 * V_295 ;
T_37 V_296 ;
T_30 * V_255 = ( T_30 * ) T_35 -> V_255 ;
T_6 V_297 ;
T_21 V_298 ;
#ifdef F_182
V_299 = TRUE ;
#endif
V_297 = F_195 () ;
V_298 = F_196 () ;
if ( V_211 ) {
while ( V_294 -- && V_255 -> V_213 ) {
F_197 ( V_255 -> V_213 ) ;
V_266 = F_198 ( V_255 -> V_213 , & V_92 , & V_295 , & V_296 ) ;
if ( V_266 == FALSE ) {
F_199 ( T_35 ) ;
F_193 ( V_255 -> V_213 ) ;
V_255 -> V_213 = NULL ;
} else {
V_266 = F_200 ( V_255 , V_296 , F_201 ( V_255 -> V_213 ) ,
F_202 ( V_255 -> V_213 ) ,
V_297 , V_298 ) ;
}
if ( V_266 != FALSE ) {
V_300 ++ ;
}
}
} else {
V_300 += V_294 ;
}
if ( V_236 ) {
if ( V_300 != 0 ) {
fprintf ( V_7 , L_254 , V_300 ) ;
fflush ( V_7 ) ;
}
}
#ifdef F_182
V_299 = FALSE ;
if ( V_301 )
F_203 () ;
#endif
}
static void
F_203 ( void )
{
if ( ( V_236 == FALSE ) && ( V_169 == FALSE ) ) {
fprintf ( V_7 , L_255 , V_300 ,
F_204 ( V_300 , L_144 , L_180 ) ) ;
}
#ifdef F_182
V_301 = FALSE ;
#endif
}
static void
V_280 ( int T_38 V_6 )
{
int V_302 = V_237 ;
if ( V_299 )
V_301 = TRUE ;
else
F_203 () ;
V_237 = V_302 ;
}
void
F_205 ( T_34 * T_35 V_6 , T_11 V_303 )
{
if ( V_236 ) {
fprintf ( V_7 , L_7 ) ;
}
if ( V_303 != 0 ) {
fprintf ( V_7 , L_256 , V_303 , F_204 ( V_303 , L_144 , L_180 ) ) ;
}
}
void
F_206 ( T_34 * T_35 , T_8 * V_304 )
{
T_30 * V_255 = ( T_30 * ) T_35 -> V_255 ;
if ( V_304 != NULL )
fprintf ( V_7 , L_257 , V_304 ) ;
F_203 () ;
if ( V_255 != NULL && V_255 -> V_213 != NULL ) {
F_193 ( V_255 -> V_213 ) ;
if ( V_255 -> V_290 ) {
F_207 ( V_255 -> V_305 ) ;
}
}
#ifdef F_208
F_209 ( V_306 ) ;
#else
V_284 = FALSE ;
#endif
}
static BOOL T_39
V_271 ( T_26 T_40 V_6 )
{
F_199 ( & V_138 ) ;
return TRUE ;
}
static void
V_271 ( int T_38 V_6 )
{
F_199 ( & V_138 ) ;
}
static T_6
F_210 ( T_30 * V_255 ,
T_37 V_307 , struct V_308 * V_309 ,
const T_41 * V_310 )
{
T_31 V_311 ;
T_11 V_312 ;
T_6 V_313 = FALSE ;
T_42 V_314 ;
T_6 V_315 ;
V_312 = V_255 -> V_316 + 1 ;
V_315 = TRUE ;
F_211 ( & V_311 , V_312 , V_309 , V_307 , V_317 ) ;
if ( V_211 ) {
if ( V_160 . V_161 || V_160 . V_162 ||
V_160 . V_163 || V_160 . V_164 )
F_212 () ;
if ( V_255 -> V_110 )
V_313 = TRUE ;
F_213 ( & V_314 , V_255 -> V_240 , V_313 , FALSE ) ;
if ( V_255 -> V_110 )
F_214 ( & V_314 , V_255 -> V_110 ) ;
F_215 ( & V_311 , & V_255 -> V_318 ,
& V_256 , V_259 ) ;
if ( V_256 == & V_311 ) {
V_319 = V_311 ;
V_256 = & V_319 ;
}
F_216 ( & V_314 , V_309 , F_217 ( & V_311 , V_310 ) , & V_311 , NULL ) ;
if ( V_255 -> V_110 )
V_315 = F_218 ( V_255 -> V_110 , & V_314 ) ;
}
if ( V_315 ) {
F_219 ( & V_311 , & V_317 ) ;
V_260 = V_259 = F_220 ( V_255 -> V_239 , & V_311 ) ;
if ( V_211 ) {
F_9 ( V_314 . V_320 . V_321 , V_322 , V_255 -> V_239 ) ;
}
V_255 -> V_316 ++ ;
} else {
F_221 ( & V_311 ) ;
}
if ( V_211 )
F_222 ( & V_314 ) ;
return V_315 ;
}
static T_6
F_223 ( T_30 * V_255 , T_31 * V_323 ,
struct V_308 * V_324 , T_43 * V_325 ,
T_6 V_297 , T_21 V_298 )
{
T_6 V_313 ;
T_44 * V_204 ;
T_42 V_314 ;
T_6 V_315 ;
V_315 = TRUE ;
if ( V_211 ) {
if ( V_160 . V_161 || V_160 . V_162 ||
V_160 . V_163 || V_160 . V_164 )
F_212 () ;
if ( V_255 -> V_111 || V_124 || V_297 ||
( V_298 & V_326 ) || F_224 ( & V_255 -> V_204 ) )
V_313 = TRUE ;
else
V_313 = FALSE ;
F_213 ( & V_314 , V_255 -> V_240 , V_313 , V_122 && V_124 ) ;
if ( V_255 -> V_111 )
F_214 ( & V_314 , V_255 -> V_111 ) ;
F_225 ( & V_314 , & V_255 -> V_204 ) ;
if ( ( V_298 & V_327 ) || ( V_122 && V_123 ) )
V_204 = & V_255 -> V_204 ;
else
V_204 = NULL ;
F_215 ( V_323 , & V_255 -> V_318 ,
& V_256 , V_259 ) ;
if ( V_256 == V_323 ) {
V_319 = * V_323 ;
V_256 = & V_319 ;
}
F_226 ( & V_314 , V_324 , F_227 ( V_323 , V_325 ) , V_323 , V_204 ) ;
if ( V_255 -> V_111 )
V_315 = F_218 ( V_255 -> V_111 , & V_314 ) ;
}
if ( V_315 ) {
F_219 ( V_323 , & V_317 ) ;
if ( V_122 ) {
if ( V_211 )
F_228 ( V_255 , & V_314 ) ;
else
F_228 ( V_255 , NULL ) ;
if ( V_159 )
fflush ( stdout ) ;
if ( ferror ( stdout ) ) {
F_155 ( V_237 ) ;
exit ( 2 ) ;
}
}
V_259 = V_323 ;
}
V_260 = V_323 ;
if ( V_211 ) {
F_222 ( & V_314 ) ;
}
return V_315 || V_323 -> V_328 . V_329 ;
}
static int
F_146 ( T_30 * V_255 , char * V_191 , int V_101 ,
T_6 V_104 , int V_330 , T_37 V_331 )
{
T_1 V_332 ;
int V_333 ;
T_45 * V_334 ;
T_11 V_312 ;
int V_92 ;
T_8 * V_295 = NULL ;
T_37 V_296 ;
char * V_64 = NULL ;
T_6 V_297 ;
T_21 V_298 ;
T_46 * V_335 ;
T_47 * V_336 ;
char V_337 [ 100 ] ;
T_43 V_325 ;
V_335 = F_229 ( V_255 -> V_213 ) ;
V_336 = F_230 ( V_255 -> V_213 ) ;
#ifdef F_55
if ( V_336 -> V_338 > 1 ) {
V_332 = V_339 ;
} else {
V_332 = F_231 ( V_255 -> V_213 ) ;
}
#else
V_332 = F_231 ( V_255 -> V_213 ) ;
#endif
if ( V_191 != NULL ) {
V_64 = F_43 ( V_191 ) ;
V_333 = F_232 ( V_255 -> V_213 ) ;
if ( V_333 == 0 ) {
V_333 = V_340 ;
}
if ( V_335 -> V_341 == NULL ) {
F_233 ( V_337 , sizeof( V_337 ) , L_3 V_15 L_8 , V_16 ) ;
V_335 -> V_341 = V_337 ;
}
if ( V_332 != V_339 && V_101 == V_103 )
V_334 = F_234 ( V_191 , V_101 , V_332 ,
V_333 , FALSE , & V_92 ) ;
else
V_334 = F_235 ( V_191 , V_101 , V_332 ,
V_333 , FALSE , V_335 , V_336 , & V_92 ) ;
F_11 ( V_336 ) ;
V_336 = NULL ;
if ( V_334 == NULL ) {
switch ( V_92 ) {
case V_342 :
F_34 ( L_258 ) ;
break;
case V_343 :
case V_344 :
F_34 ( L_259
L_260 , F_6 ( V_101 ) ) ;
break;
case V_345 :
F_34 ( L_261
L_262 , V_64 ) ;
break;
case V_346 :
F_34 ( L_263 ,
V_64 ) ;
break;
default:
F_34 ( L_264 , V_64 ,
F_236 ( V_92 ) ) ;
break;
}
goto V_347;
}
} else {
if ( V_122 ) {
if ( ! F_154 ( V_255 ) ) {
V_92 = V_237 ;
F_155 ( V_92 ) ;
goto V_347;
}
}
F_11 ( V_336 ) ;
V_336 = NULL ;
V_334 = NULL ;
}
if ( V_334 && V_104 ) {
if ( ! F_237 ( V_334 , F_238 () ) ) {
F_34 ( L_265 ,
F_6 ( V_101 ) ) ;
}
}
V_297 = F_195 () ;
V_298 = F_196 () ;
if ( V_153 ) {
T_31 * V_323 ;
V_255 -> V_239 = F_239 () ;
while ( F_198 ( V_255 -> V_213 , & V_92 , & V_295 , & V_296 ) ) {
if ( F_210 ( V_255 , V_296 , F_201 ( V_255 -> V_213 ) ,
F_202 ( V_255 -> V_213 ) ) ) {
if ( ( -- V_330 == 0 ) || ( V_331 != 0 && V_296 >= V_331 ) ) {
V_92 = 0 ;
break;
}
}
}
F_240 ( V_255 -> V_213 ) ;
F_241 () ;
V_259 = NULL ;
V_260 = NULL ;
F_242 ( & V_325 , 1500 ) ;
for ( V_312 = 1 ; V_92 == 0 && V_312 <= V_255 -> V_316 ; V_312 ++ ) {
V_323 = F_176 ( V_255 -> V_239 , V_312 ) ;
if ( F_243 ( V_255 -> V_213 , V_323 -> V_348 , & V_255 -> V_324 ,
& V_325 , V_323 -> V_349 , & V_92 , & V_295 ) ) {
if ( F_223 ( V_255 , V_323 , & V_255 -> V_324 , & V_325 ,
V_297 , V_298 ) ) {
if ( V_334 != NULL ) {
if ( ! F_244 ( V_334 , & V_255 -> V_324 , F_245 ( & V_255 -> V_325 ) , & V_92 ) ) {
switch ( V_92 ) {
case V_343 :
fprintf ( V_7 ,
L_266 ,
V_312 , V_255 -> V_305 ,
F_6 ( V_101 ) ) ;
break;
default:
F_246 ( V_191 , V_92 , FALSE ) ;
break;
}
F_247 ( V_334 , & V_92 ) ;
F_11 ( V_335 ) ;
exit ( 2 ) ;
}
}
}
}
}
F_248 ( & V_325 ) ;
}
else {
V_312 = 0 ;
while ( F_198 ( V_255 -> V_213 , & V_92 , & V_295 , & V_296 ) ) {
V_312 ++ ;
if ( F_200 ( V_255 , V_296 , F_201 ( V_255 -> V_213 ) ,
F_202 ( V_255 -> V_213 ) ,
V_297 , V_298 ) ) {
if ( V_334 != NULL ) {
if ( ! F_244 ( V_334 , F_201 ( V_255 -> V_213 ) , F_202 ( V_255 -> V_213 ) , & V_92 ) ) {
switch ( V_92 ) {
case V_343 :
fprintf ( V_7 ,
L_266 ,
V_312 , V_255 -> V_305 ,
F_6 ( V_101 ) ) ;
break;
default:
F_246 ( V_191 , V_92 , FALSE ) ;
break;
}
F_247 ( V_334 , & V_92 ) ;
F_11 ( V_335 ) ;
exit ( 2 ) ;
}
}
}
if ( ( -- V_330 == 0 ) || ( V_331 != 0 && V_296 >= V_331 ) ) {
V_92 = 0 ;
break;
}
}
}
if ( V_92 != 0 ) {
#ifndef V_17
if ( V_122 ) {
struct V_350 V_351 , V_352 ;
if ( F_249 ( 1 , & V_351 ) == 0 && F_249 ( 2 , & V_352 ) == 0 ) {
if ( V_351 . V_353 == V_352 . V_353 &&
V_351 . V_354 == V_352 . V_354 ) {
fflush ( stdout ) ;
fprintf ( V_7 , L_7 ) ;
}
}
}
#endif
switch ( V_92 ) {
case V_355 :
F_34 ( L_267 ,
V_255 -> V_305 , V_295 ) ;
F_11 ( V_295 ) ;
break;
case V_343 :
F_34 ( L_268 ,
V_255 -> V_305 , V_295 ) ;
F_11 ( V_295 ) ;
break;
case V_356 :
F_34 ( L_269 ,
V_255 -> V_305 ) ;
break;
case V_357 :
F_34 ( L_270 ,
V_255 -> V_305 ) ;
break;
case V_358 :
F_34 ( L_271 ,
V_255 -> V_305 , V_295 ) ;
F_11 ( V_295 ) ;
break;
case V_359 :
F_34 ( L_272
L_273 , V_255 -> V_305 , V_295 ) ;
break;
default:
F_34 ( L_274 ,
V_255 -> V_305 , F_236 ( V_92 ) ) ;
break;
}
if ( V_191 != NULL ) {
if ( ! F_247 ( V_334 , & V_92 ) )
F_246 ( V_191 , V_92 , TRUE ) ;
}
} else {
if ( V_191 != NULL ) {
if ( ! F_247 ( V_334 , & V_92 ) )
F_246 ( V_191 , V_92 , TRUE ) ;
} else {
if ( V_122 ) {
if ( ! F_157 () ) {
V_92 = V_237 ;
F_155 ( V_92 ) ;
}
}
}
}
V_347:
F_193 ( V_255 -> V_213 ) ;
V_255 -> V_213 = NULL ;
F_11 ( V_64 ) ;
F_11 ( V_335 ) ;
return V_92 ;
}
static T_6
F_200 ( T_30 * V_255 , T_37 V_307 , struct V_308 * V_309 ,
const T_41 * V_310 ,
T_6 V_297 , T_21 V_298 )
{
T_31 V_323 ;
T_6 V_313 ;
T_44 * V_204 ;
T_42 V_314 ;
T_6 V_315 ;
V_255 -> V_316 ++ ;
V_315 = TRUE ;
F_211 ( & V_323 , V_255 -> V_316 , V_309 , V_307 , V_317 ) ;
if ( V_211 ) {
if ( V_122 && ( V_160 . V_161 || V_160 . V_162 ||
V_160 . V_163 || V_160 . V_164 ) )
F_212 () ;
if ( V_255 -> V_110 || V_255 -> V_111 || V_124 || V_297 ||
( V_298 & V_326 ) || F_224 ( & V_255 -> V_204 ) )
V_313 = TRUE ;
else
V_313 = FALSE ;
F_213 ( & V_314 , V_255 -> V_240 , V_313 , V_122 && V_124 ) ;
if ( V_255 -> V_111 )
F_214 ( & V_314 , V_255 -> V_111 ) ;
F_225 ( & V_314 , & V_255 -> V_204 ) ;
if ( ( V_298 & V_327 ) || ( V_122 && V_123 ) || F_250 ( V_152 ) )
V_204 = & V_255 -> V_204 ;
else
V_204 = NULL ;
F_215 ( & V_323 , & V_255 -> V_318 ,
& V_256 , V_259 ) ;
if ( V_256 == & V_323 ) {
V_319 = V_323 ;
V_256 = & V_319 ;
}
F_226 ( & V_314 , V_309 , F_217 ( & V_323 , V_310 ) , & V_323 , V_204 ) ;
if ( V_255 -> V_111 )
V_315 = F_218 ( V_255 -> V_111 , & V_314 ) ;
}
if ( V_315 ) {
F_219 ( & V_323 , & V_317 ) ;
if ( V_122 ) {
if ( V_211 )
F_228 ( V_255 , & V_314 ) ;
else
F_228 ( V_255 , NULL ) ;
if ( V_159 )
fflush ( stdout ) ;
if ( ferror ( stdout ) ) {
F_155 ( V_237 ) ;
exit ( 2 ) ;
}
}
V_360 = V_323 ;
V_259 = & V_360 ;
}
V_361 = V_323 ;
V_260 = & V_361 ;
if ( V_211 ) {
F_222 ( & V_314 ) ;
F_221 ( & V_323 ) ;
}
return V_315 ;
}
static T_6
F_154 ( T_30 * V_255 )
{
switch ( V_178 ) {
case V_179 :
return F_251 ( V_210 , V_255 ? V_255 -> V_305 : NULL , V_16 ) ;
case V_181 :
if ( V_124 )
F_252 ( stdout , V_255 ? V_255 -> V_305 : NULL ) ;
else
F_253 ( stdout ) ;
return ! ferror ( stdout ) ;
case V_182 :
F_254 ( V_152 , stdout ) ;
return ! ferror ( stdout ) ;
default:
F_37 () ;
return FALSE ;
}
}
static char *
F_255 ( T_48 V_188 )
{
static char * V_362 = NULL ;
static T_48 V_363 = 256 ;
T_48 V_364 ;
for ( V_364 = V_363 ; V_188 > V_364 ;
V_364 *= 2 )
;
if ( V_362 == NULL ) {
V_363 = V_364 ;
V_362 = ( char * ) F_171 ( V_363 + 1 ) ;
} else {
if ( V_364 > V_363 ) {
V_363 = V_364 ;
V_362 = ( char * ) F_256 ( V_362 , V_363 + 1 ) ;
}
}
return V_362 ;
}
static inline void
F_257 ( char * V_365 , const char * V_69 , T_48 V_366 )
{
memcpy ( V_365 , V_69 , V_366 ) ;
V_365 [ V_366 ] = '\0' ;
}
static inline void
F_258 ( char * V_365 , const char * V_69 , T_48 V_366 , T_48 V_367 )
{
T_48 V_9 ;
for ( V_9 = V_366 ; V_9 < V_367 ; V_9 ++ )
* V_365 ++ = ' ' ;
F_257 ( V_365 , V_69 , V_366 ) ;
}
static inline void
F_259 ( char * V_365 , const char * V_69 , T_48 V_366 , T_48 V_367 )
{
T_48 V_9 ;
memcpy ( V_365 , V_69 , V_366 ) ;
for ( V_9 = V_366 ; V_9 < V_367 ; V_9 ++ )
V_365 [ V_9 ] = ' ' ;
V_365 [ V_367 ] = '\0' ;
}
static T_6
F_260 ( T_30 * V_255 )
{
char * V_362 ;
int V_9 ;
T_48 V_368 ;
T_48 V_369 ;
T_48 V_370 ;
V_362 = F_255 ( 256 ) ;
V_368 = 0 ;
* V_362 = '\0' ;
for ( V_9 = 0 ; V_9 < V_255 -> V_204 . V_205 ; V_9 ++ ) {
if ( ! F_261 ( V_9 ) )
continue;
switch ( V_255 -> V_204 . V_371 [ V_9 ] ) {
case V_372 :
#ifdef F_14
if ( V_137 . V_187 -> V_188 > 0 )
continue;
#endif
V_369 = V_370 = strlen ( V_255 -> V_204 . V_373 [ V_9 ] ) ;
if ( V_369 < 3 )
V_369 = 3 ;
V_362 = F_255 ( V_368 + V_369 ) ;
F_258 ( V_362 + V_368 , V_255 -> V_204 . V_373 [ V_9 ] , V_370 , V_369 ) ;
break;
case V_374 :
case V_375 :
case V_376 :
case V_377 :
case V_378 :
case V_379 :
V_369 = V_370 = strlen ( V_255 -> V_204 . V_373 [ V_9 ] ) ;
if ( V_369 < 10 )
V_369 = 10 ;
V_362 = F_255 ( V_368 + V_369 ) ;
F_258 ( V_362 + V_368 , V_255 -> V_204 . V_373 [ V_9 ] , V_370 , V_369 ) ;
break;
case V_380 :
case V_381 :
case V_382 :
case V_383 :
case V_384 :
case V_385 :
case V_386 :
case V_387 :
case V_388 :
V_369 = V_370 = strlen ( V_255 -> V_204 . V_373 [ V_9 ] ) ;
if ( V_369 < 12 )
V_369 = 12 ;
V_362 = F_255 ( V_368 + V_369 ) ;
F_258 ( V_362 + V_368 , V_255 -> V_204 . V_373 [ V_9 ] , V_370 , V_369 ) ;
break;
case V_389 :
case V_390 :
case V_391 :
case V_392 :
case V_393 :
case V_394 :
case V_395 :
case V_396 :
case V_397 :
V_369 = V_370 = strlen ( V_255 -> V_204 . V_373 [ V_9 ] ) ;
if ( V_369 < 12 )
V_369 = 12 ;
V_362 = F_255 ( V_368 + V_369 ) ;
F_259 ( V_362 + V_368 , V_255 -> V_204 . V_373 [ V_9 ] , V_370 , V_369 ) ;
break;
default:
V_369 = strlen ( V_255 -> V_204 . V_373 [ V_9 ] ) ;
V_362 = F_255 ( V_368 + V_369 ) ;
F_257 ( V_362 + V_368 , V_255 -> V_204 . V_373 [ V_9 ] , V_369 ) ;
break;
}
V_368 += V_369 ;
if ( V_9 != V_255 -> V_204 . V_205 - 1 ) {
V_362 = F_255 ( V_368 + 4 ) ;
switch ( V_255 -> V_204 . V_371 [ V_9 ] ) {
case V_380 :
case V_381 :
case V_382 :
switch ( V_255 -> V_204 . V_371 [ V_9 + 1 ] ) {
case V_389 :
case V_390 :
case V_391 :
F_257 ( V_362 + V_368 , L_275 , 4 ) ;
V_368 += 4 ;
break;
default:
F_257 ( V_362 + V_368 , L_238 , 1 ) ;
V_368 += 1 ;
break;
}
break;
case V_383 :
case V_384 :
case V_385 :
switch ( V_255 -> V_204 . V_371 [ V_9 + 1 ] ) {
case V_392 :
case V_393 :
case V_394 :
F_257 ( V_362 + V_368 , L_275 , 4 ) ;
V_368 += 4 ;
break;
default:
F_257 ( V_362 + V_368 , L_238 , 1 ) ;
V_368 += 1 ;
break;
}
break;
case V_386 :
case V_387 :
case V_388 :
switch ( V_255 -> V_204 . V_371 [ V_9 + 1 ] ) {
case V_395 :
case V_396 :
case V_397 :
F_257 ( V_362 + V_368 , L_275 , 4 ) ;
V_368 += 4 ;
break;
default:
F_257 ( V_362 + V_368 , L_238 , 1 ) ;
V_368 += 1 ;
break;
}
break;
case V_389 :
case V_390 :
case V_391 :
switch ( V_255 -> V_204 . V_371 [ V_9 + 1 ] ) {
case V_380 :
case V_381 :
case V_382 :
F_257 ( V_362 + V_368 , L_276 , 4 ) ;
V_368 += 4 ;
break;
default:
F_257 ( V_362 + V_368 , L_238 , 1 ) ;
V_368 += 1 ;
break;
}
break;
case V_392 :
case V_393 :
case V_394 :
switch ( V_255 -> V_204 . V_371 [ V_9 + 1 ] ) {
case V_383 :
case V_384 :
case V_385 :
F_257 ( V_362 + V_368 , L_276 , 4 ) ;
V_368 += 4 ;
break;
default:
F_257 ( V_362 + V_368 , L_238 , 1 ) ;
V_368 += 1 ;
break;
}
break;
case V_395 :
case V_396 :
case V_397 :
switch ( V_255 -> V_204 . V_371 [ V_9 + 1 ] ) {
case V_386 :
case V_387 :
case V_388 :
F_257 ( V_362 + V_368 , L_276 , 4 ) ;
V_368 += 4 ;
break;
default:
F_257 ( V_362 + V_368 , L_238 , 1 ) ;
V_368 += 1 ;
break;
}
break;
default:
F_257 ( V_362 + V_368 , L_238 , 1 ) ;
V_368 += 1 ;
break;
}
}
}
return F_262 ( V_210 , 0 , V_362 ) ;
}
static T_6
F_228 ( T_30 * V_255 , T_42 * V_314 )
{
T_49 V_398 ;
if ( V_123 || F_250 ( V_152 ) ) {
F_263 ( V_314 , FALSE , TRUE ) ;
if ( V_123 ) {
switch ( V_178 ) {
case V_179 :
if ( ! F_260 ( V_255 ) )
return FALSE ;
break;
case V_181 :
F_264 ( V_314 , stdout ) ;
return ! ferror ( stdout ) ;
case V_182 :
F_37 () ;
break;
}
}
}
if ( V_124 ) {
switch ( V_178 ) {
case V_179 :
V_398 . V_125 = V_125 ;
V_398 . V_399 = V_124 ? V_400 : V_401 ;
if ( ! F_265 ( & V_398 , V_314 , V_210 ) )
return FALSE ;
if ( ! V_125 ) {
if ( ! F_262 ( V_210 , 0 , V_170 ) )
return FALSE ;
}
break;
case V_181 :
F_266 ( V_314 , stdout ) ;
printf ( L_7 ) ;
return ! ferror ( stdout ) ;
case V_182 :
F_267 ( V_152 , V_314 , & V_255 -> V_204 , stdout ) ;
printf ( L_7 ) ;
return ! ferror ( stdout ) ;
}
}
if ( V_125 ) {
if ( V_123 || V_124 ) {
if ( ! F_262 ( V_210 , 0 , L_144 ) )
return FALSE ;
}
if ( ! F_268 ( V_210 , V_314 ) )
return FALSE ;
if ( ! F_262 ( V_210 , 0 , V_170 ) )
return FALSE ;
}
return TRUE ;
}
static T_6
F_157 ( void )
{
switch ( V_178 ) {
case V_179 :
return F_269 ( V_210 ) ;
case V_181 :
if ( V_124 )
F_270 ( stdout ) ;
else
F_271 ( stdout ) ;
return ! ferror ( stdout ) ;
case V_182 :
F_272 ( V_152 , stdout ) ;
return ! ferror ( stdout ) ;
default:
F_37 () ;
return FALSE ;
}
}
T_50
F_143 ( T_30 * V_255 , const char * V_63 , T_6 V_290 , int * V_92 )
{
T_51 * V_213 ;
T_8 * V_295 ;
char V_402 [ 2048 + 1 ] ;
V_213 = F_273 ( V_63 , V_92 , & V_295 , V_153 ) ;
if ( V_213 == NULL )
goto V_403;
F_161 ( V_255 -> V_240 ) ;
V_255 -> V_240 = F_177 ( V_255 ) ;
V_255 -> V_213 = V_213 ;
V_255 -> V_404 = 0 ;
V_255 -> V_305 = F_33 ( V_63 ) ;
V_255 -> V_290 = V_290 ;
V_255 -> V_405 = FALSE ;
V_255 -> V_406 = F_274 ( V_255 -> V_213 ) ;
V_255 -> V_316 = 0 ;
V_255 -> V_407 = FALSE ;
V_255 -> V_408 = 0 ;
V_255 -> V_409 = F_232 ( V_255 -> V_213 ) ;
if ( V_255 -> V_409 == 0 ) {
V_255 -> V_410 = FALSE ;
V_255 -> V_409 = V_340 ;
} else
V_255 -> V_410 = TRUE ;
F_275 ( & V_255 -> V_318 ) ;
V_256 = NULL ;
V_259 = NULL ;
V_260 = NULL ;
V_255 -> V_281 = V_411 ;
F_276 ( V_255 -> V_213 , V_412 ) ;
F_277 ( V_255 -> V_213 , ( V_413 ) V_414 ) ;
return V_212 ;
V_403:
F_233 ( V_402 , sizeof V_402 ,
F_278 ( * V_92 , V_295 , FALSE , V_255 -> V_406 ) , V_63 ) ;
F_34 ( L_8 , V_402 ) ;
return V_293 ;
}
static void
F_246 ( const char * V_63 , int V_92 , T_6 V_415 )
{
char * V_64 ;
V_64 = F_43 ( V_63 ) ;
switch ( V_92 ) {
case V_416 :
F_34 ( L_277
L_278 ,
V_64 ) ;
break;
#ifdef F_279
case F_279 :
F_34 ( L_279
L_280 ,
V_64 ) ;
break;
#endif
case V_417 :
F_34 ( L_281 ,
V_64 ) ;
break;
case V_346 :
F_34 ( L_282 ,
V_64 ) ;
break;
default:
if ( V_415 ) {
F_34 ( L_283 , V_64 ,
F_236 ( V_92 ) ) ;
} else {
F_34 ( L_284 ,
V_64 , F_236 ( V_92 ) ) ;
}
break;
}
F_11 ( V_64 ) ;
}
static void
F_155 ( int V_92 )
{
switch ( V_92 ) {
case V_416 :
F_34 ( L_285
L_278 ) ;
break;
#ifdef F_279
case F_279 :
F_34 ( L_286
L_280 ) ;
break;
#endif
default:
F_34 ( L_287 ,
F_97 ( V_92 ) ) ;
break;
}
}
static const char *
F_278 ( int V_92 , T_8 * V_295 , T_6 V_418 ,
int V_419 )
{
const char * V_420 ;
static char V_421 [ 1024 + 1 ] ;
if ( V_92 < 0 ) {
switch ( V_92 ) {
case V_422 :
V_420 = L_288 ;
break;
case V_423 :
V_420 = L_289 ;
break;
case V_424 :
V_420 = L_290 ;
break;
case V_355 :
F_233 ( V_421 , sizeof( V_421 ) ,
L_291
L_273 , V_295 ) ;
F_11 ( V_295 ) ;
V_420 = V_421 ;
break;
case V_425 :
F_233 ( V_421 , sizeof( V_421 ) ,
L_292
L_293 , F_6 ( V_419 ) ) ;
V_420 = V_421 ;
break;
case V_342 :
V_420 = L_294 ;
break;
case V_343 :
if ( V_418 ) {
F_233 ( V_421 , sizeof( V_421 ) ,
L_295 ,
F_6 ( V_419 ) ) ;
} else {
F_233 ( V_421 , sizeof( V_421 ) ,
L_296
L_273 , V_295 ) ;
F_11 ( V_295 ) ;
}
V_420 = V_421 ;
break;
case V_344 :
if ( V_418 ) {
F_233 ( V_421 , sizeof( V_421 ) ,
L_295 ,
F_6 ( V_419 ) ) ;
V_420 = V_421 ;
} else
V_420 = L_297 ;
break;
case V_358 :
F_233 ( V_421 , sizeof( V_421 ) ,
L_298
L_273 , V_295 ) ;
F_11 ( V_295 ) ;
V_420 = V_421 ;
break;
case V_345 :
if ( V_418 )
V_420 = L_299 ;
else
V_420 = L_300 ;
break;
case V_357 :
V_420 = L_301
L_302 ;
break;
case V_346 :
V_420 = L_303 ;
break;
case V_426 :
V_420 = L_304 ;
break;
case V_359 :
F_233 ( V_421 , sizeof( V_421 ) ,
L_305
L_273 , V_295 ) ;
F_11 ( V_295 ) ;
V_420 = V_421 ;
break;
default:
F_233 ( V_421 , sizeof( V_421 ) ,
L_306 ,
V_418 ? L_307 : L_308 ,
F_236 ( V_92 ) ) ;
V_420 = V_421 ;
break;
}
} else
V_420 = F_280 ( V_92 , V_418 ) ;
return V_420 ;
}
static void
V_146 ( const char * V_305 , int V_92 , T_6 V_418 )
{
fprintf ( V_7 , L_309 ) ;
fprintf ( V_7 , F_280 ( V_92 , V_418 ) , V_305 ) ;
fprintf ( V_7 , L_7 ) ;
}
static void
V_145 ( const char * V_427 , T_52 V_428 )
{
fprintf ( V_7 , L_309 ) ;
vfprintf ( V_7 , V_427 , V_428 ) ;
fprintf ( V_7 , L_7 ) ;
}
static void
V_147 ( const char * V_305 , int V_92 )
{
F_34 ( L_310 ,
V_305 , F_97 ( V_92 ) ) ;
}
static void
V_148 ( const char * V_305 , int V_92 )
{
F_34 ( L_311 ,
V_305 , F_97 ( V_92 ) ) ;
}
void
F_34 ( const char * V_429 , ... )
{
T_52 V_428 ;
va_start ( V_428 , V_429 ) ;
V_145 ( V_429 , V_428 ) ;
va_end ( V_428 ) ;
}
void
F_113 ( const char * V_429 , ... )
{
T_52 V_428 ;
va_start ( V_428 , V_429 ) ;
vfprintf ( V_7 , V_429 , V_428 ) ;
fprintf ( V_7 , L_7 ) ;
va_end ( V_428 ) ;
}
