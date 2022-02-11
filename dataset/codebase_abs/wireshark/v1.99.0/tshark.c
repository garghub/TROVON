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
#if F_16 ( V_19 ) || F_16 ( F_15 )
fprintf ( V_18 , L_14 , V_20 ) ;
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
fprintf ( V_18 , L_38 , V_21 ) ;
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
fprintf ( V_18 , L_6 ) ;
fprintf ( V_18 , L_80 ) ;
fprintf ( V_18 , L_81 ) ;
fprintf ( V_18 , L_82 ) ;
fprintf ( V_18 , L_83 ) ;
fprintf ( V_18 , L_84 ) ;
fprintf ( V_18 , L_85 ) ;
fprintf ( V_18 , L_86 ) ;
fprintf ( V_18 , L_87 ) ;
#ifdef F_18
fprintf ( V_18 , L_6 ) ;
fprintf ( V_18 , L_88 ) ;
fprintf ( V_18 , L_89 ) ;
fprintf ( V_18 , L_90 ) ;
fprintf ( V_18 , L_6 ) ;
#endif
}
static void
F_19 ( void )
{
T_6 * V_18 ;
V_18 = stdout ;
fprintf ( V_18 , L_91 , F_20 () ) ;
fprintf ( V_18 , L_6 ) ;
fprintf ( V_18 , L_92 ) ;
fprintf ( V_18 , L_6 ) ;
fprintf ( V_18 , L_93 ) ;
fprintf ( V_18 , L_94 ) ;
fprintf ( V_18 , L_95 ) ;
fprintf ( V_18 , L_96 ) ;
fprintf ( V_18 , L_97 ) ;
fprintf ( V_18 , L_98 ) ;
fprintf ( V_18 , L_99 ) ;
fprintf ( V_18 , L_100 ) ;
fprintf ( V_18 , L_101 ) ;
fprintf ( V_18 , L_6 ) ;
fprintf ( V_18 , L_102 ) ;
fprintf ( V_18 , L_103 ) ;
fprintf ( V_18 , L_104 ) ;
fprintf ( V_18 , L_6 ) ;
}
static void
F_21 ( const char * V_22 , const char * V_23 ,
T_3 V_18 )
{
if ( ( V_24 == NULL ) ||
( strcmp ( V_24 , V_22 ) != 0 ) ) {
fprintf ( ( T_6 * ) V_18 , L_105 , V_22 , V_23 ) ;
V_24 = V_22 ;
}
}
static void
F_22 ( const T_7 * T_8 V_6 , T_3 V_25 , T_3 V_18 )
{
int V_26 ;
const T_7 * V_27 ;
const T_7 * V_28 ;
V_26 = F_23 ( ( V_29 ) V_25 ) ;
if ( V_26 != - 1 ) {
V_27 = F_24 ( V_26 ) ;
V_28 = F_25 ( V_26 ) ;
F_26 ( V_27 != NULL ) ;
F_26 ( V_28 != NULL ) ;
if ( ( V_24 == NULL ) ||
( strcmp ( V_24 , V_27 ) != 0 ) ) {
fprintf ( ( T_6 * ) V_18 , L_105 ,
V_27 ,
V_28 ) ;
V_24 = V_27 ;
}
}
}
static void
F_27 ( const T_7 * T_8 V_6 , T_3 V_25 , T_3 V_30 )
{
int V_26 ;
const T_7 * V_31 ;
T_9 V_32 ;
F_26 ( V_25 ) ;
V_32 = ( T_9 ) V_30 ;
V_26 = F_23 ( ( V_29 ) V_25 ) ;
if ( V_26 != - 1 ) {
V_31 = F_24 ( V_26 ) ;
F_26 ( V_31 != NULL ) ;
if ( strcmp ( V_31 , V_32 -> V_33 ) == 0 ) {
if ( V_32 -> V_34 == 0 ) {
V_32 -> V_35 = ( V_29 ) V_25 ;
}
V_32 -> V_34 ++ ;
}
}
}
static T_1
F_28 ( T_2 V_36 , T_2 V_37 )
{
return strcmp ( ( const char * ) V_36 , ( const char * ) V_37 ) ;
}
static void
F_29 ( T_6 * V_18 )
{
V_24 = NULL ;
F_30 ( F_21 , ( T_3 ) V_18 , ( V_38 ) F_28 ) ;
}
static void
F_31 ( T_6 * V_18 , T_7 * V_22 )
{
V_24 = NULL ;
F_32 ( V_22 ,
F_22 ,
( T_3 ) V_18 ) ;
}
static T_10
F_33 ( const T_7 * V_39 )
{
T_7 * V_22 ;
T_11 V_40 , V_41 ;
T_7 * V_42 ;
T_7 * V_43 ;
T_7 * V_44 ;
T_7 * V_45 ;
V_29 V_46 ;
T_12 V_47 ;
T_13 V_48 ;
struct V_49 V_50 ;
T_14 V_9 ;
char V_51 ;
F_26 ( V_39 ) ;
V_42 = F_34 ( V_39 ) ;
F_26 ( V_42 ) ;
V_22 = V_42 ;
V_43 = strchr ( V_22 , '=' ) ;
if ( V_43 == NULL ) {
F_35 ( L_106 , V_39 , V_21 ) ;
}
else {
* V_43 = '\0' ;
}
while ( V_22 [ 0 ] == ' ' )
V_22 ++ ;
while ( V_22 [ strlen ( V_22 ) - 1 ] == ' ' )
V_22 [ strlen ( V_22 ) - 1 ] = '\0' ;
V_47 = NULL ;
if ( ! ( * ( V_22 ) ) ) {
F_35 ( L_107 ) ;
}
else {
V_47 = F_36 ( V_22 ) ;
if ( ! V_47 ) {
F_35 ( L_108 , V_22 ) ;
}
}
if ( ! V_47 ) {
F_35 ( L_109 ) ;
F_29 ( V_7 ) ;
}
if ( V_43 == NULL || ! V_47 ) {
F_11 ( V_42 ) ;
return FALSE ;
}
if ( * ( V_43 + 1 ) != '=' ) {
F_35 ( L_110 , V_22 , V_43 + 1 ) ;
}
else {
V_43 ++ ;
* V_43 = '\0' ;
}
V_43 ++ ;
V_44 = V_43 ;
V_43 = strchr ( V_44 , ',' ) ;
if ( V_43 == NULL ) {
F_35 ( L_106 , V_39 , V_21 ) ;
}
else {
* V_43 = '\0' ;
}
V_48 = F_37 ( V_22 ) ;
switch ( V_48 ) {
case V_52 :
case V_53 :
case V_54 :
case V_55 :
switch ( sscanf ( V_44 , L_111 , & V_40 , & V_51 , & V_41 ) ) {
case 1 :
V_51 = '\0' ;
break;
case 3 :
if ( V_51 != ':' && V_51 != '-' ) {
F_35 ( L_112 , V_44 ) ;
F_11 ( V_42 ) ;
return FALSE ;
}
if ( V_51 == ':' ) {
if ( ( V_41 == 0 ) || ( ( T_14 ) V_40 + V_41 - 1 ) > V_56 ) {
F_35 ( L_112 , V_44 ) ;
F_11 ( V_42 ) ;
return FALSE ;
}
}
else if ( V_41 < V_40 ) {
F_35 ( L_112 , V_44 ) ;
F_11 ( V_42 ) ;
return FALSE ;
}
break;
default:
F_35 ( L_113 , V_44 ) ;
F_11 ( V_42 ) ;
return FALSE ;
}
break;
case V_57 :
case V_58 :
case V_59 :
case V_60 :
break;
default:
F_38 () ;
}
if ( V_43 == NULL ) {
F_35 ( L_114 , V_22 ) ;
F_31 ( V_7 , V_22 ) ;
F_11 ( V_42 ) ;
return FALSE ;
}
V_43 ++ ;
V_45 = V_43 ;
while ( V_45 [ 0 ] == ' ' )
V_45 ++ ;
while ( V_45 [ strlen ( V_45 ) - 1 ] == ' ' )
V_45 [ strlen ( V_45 ) - 1 ] = '\0' ;
V_46 = NULL ;
if ( ! ( * V_45 ) ) {
F_35 ( L_115 ) ;
}
else {
V_50 . V_34 = 0 ;
V_50 . V_33 = V_45 ;
V_50 . V_35 = NULL ;
F_32 ( V_22 , F_27 , & V_50 ) ;
if ( V_50 . V_34 != 0 ) {
V_46 = V_50 . V_35 ;
if ( V_50 . V_34 > 1 ) {
F_35 ( L_116 , V_45 , V_50 . V_34 ) ;
}
}
else {
if ( F_39 ( V_45 ) == - 1 ) {
F_35 ( L_117 , V_45 ) ;
} else {
F_35 ( L_118 ,
V_45 , V_22 ) ;
}
}
}
if ( ! V_46 ) {
F_35 ( L_114 , V_22 ) ;
F_31 ( V_7 , V_22 ) ;
F_11 ( V_42 ) ;
return FALSE ;
}
switch ( V_48 ) {
case V_52 :
case V_53 :
case V_54 :
case V_55 :
if ( V_51 == '\0' ) {
F_40 ( V_22 , V_40 , V_46 ) ;
} else if ( V_51 == ':' ) {
for ( V_9 = V_40 ; V_9 < ( T_14 ) V_40 + V_41 ; V_9 ++ ) {
F_40 ( V_22 , ( T_11 ) V_9 , V_46 ) ;
}
} else {
for ( V_9 = V_40 ; V_9 <= V_41 ; V_9 ++ ) {
F_40 ( V_22 , ( T_11 ) V_9 , V_46 ) ;
}
}
break;
case V_57 :
case V_58 :
case V_59 :
case V_60 :
F_41 ( V_22 , V_44 , V_46 ) ;
break;
default:
F_38 () ;
}
F_11 ( V_42 ) ;
return TRUE ;
}
static void
F_42 ( const T_7 * V_61 , T_15 V_62 ,
const T_7 * V_63 , T_3 V_30 )
{
if ( ( V_62 & V_64 & V_65 . V_66 ) == 0 &&
V_65 . V_66 != 0 ) {
return;
}
F_43 ( V_61 , V_62 , V_63 , V_30 ) ;
}
static char *
F_44 ( const char * V_67 )
{
char * V_68 ;
if ( strcmp ( V_67 , L_119 ) == 0 ) {
V_68 = F_34 ( L_120 ) ;
} else {
V_68 = F_45 ( L_121 , V_67 ) ;
}
return V_68 ;
}
static void
F_46 ( void ) {
T_7 * V_69 , * V_70 ;
if ( F_47 () ) {
V_69 = F_48 () ;
V_70 = F_49 () ;
fprintf ( V_7 , L_122 ,
V_69 , V_70 ) ;
F_11 ( V_69 ) ;
F_11 ( V_70 ) ;
if ( F_50 () ) {
fprintf ( V_7 , L_123 ) ;
}
fprintf ( V_7 , L_6 ) ;
}
}
static void
F_51 ( T_16 * V_71 , T_16 * V_72 )
{
printf ( L_91
L_6
L_124
L_6
L_124
L_6
L_124 ,
F_20 () , F_52 () ,
V_71 -> V_73 , V_72 -> V_73 ) ;
}
static void
F_53 ( T_16 * V_73 )
{
F_54 ( V_73 ) ;
F_55 ( V_73 , L_125 ) ;
#ifdef F_56
F_55 ( V_73 , L_126 ) ;
#ifdef F_57
F_55 ( V_73 , F_57 ) ;
#else
F_55 ( V_73 , L_127 ) ;
#endif
#else
F_55 ( V_73 , L_128 ) ;
#endif
}
static void
F_58 ( T_16 * V_73 )
{
#ifdef F_14
F_55 ( V_73 , L_125 ) ;
F_59 ( V_73 ) ;
#endif
#if F_16 ( F_56 ) && ! F_16 ( V_19 )
F_60 ( V_73 , L_129 , F_61 () ) ;
#endif
F_62 ( V_73 ) ;
}
int
main ( int V_74 , char * V_75 [] )
{
T_16 * V_71 ;
T_16 * V_72 ;
char * V_76 ;
int V_77 ;
static const struct V_78 V_79 [] = {
{ ( char * ) L_130 , V_80 , NULL , 'h' } ,
{ ( char * ) L_131 , V_80 , NULL , 'v' } ,
V_81
{ 0 , 0 , 0 , 0 }
} ;
T_10 V_82 = FALSE ;
#ifdef V_19
T_17 V_83 ;
#endif
char * V_84 , * V_85 ;
char * V_86 , * V_87 ;
int V_88 , V_89 ;
int V_90 , V_91 ;
int V_92 , V_93 ;
int V_94 , V_95 ;
int V_96 ;
volatile int V_97 = 0 ;
#ifdef F_14
T_10 V_98 = FALSE ;
T_10 V_99 = FALSE ;
int V_100 ;
T_18 * V_101 ;
T_7 * V_102 ;
#else
T_10 V_103 = FALSE ;
#endif
T_10 V_104 = FALSE ;
#ifdef F_63
volatile int V_105 = V_106 ;
#else
volatile int V_105 = V_107 ;
#endif
volatile T_10 V_108 = FALSE ;
volatile int V_109 = V_110 ;
T_7 * volatile V_111 = NULL ;
T_7 * V_112 = NULL ;
T_7 * V_113 = NULL ;
#ifdef F_64
struct V_114 V_115 ;
#endif
T_19 * V_116 = NULL ;
T_19 * V_117 = NULL ;
T_20 * V_118 ;
char V_119 ;
int V_120 ;
int V_121 ;
T_7 * V_122 = NULL ;
#define F_65 "-2" OPTSTRING_CAPTURE_COMMON "C:d:e:E:F:gG:hH:" "K:lnN:o:O:PqQr:R:S:t:T:u:vVw:W:xX:Y:z:"
static const char V_123 [] = F_65 ;
F_66 ( V_124 , V_125 ) ;
#ifdef V_19
F_67 ( V_74 , V_75 ) ;
F_68 () ;
#if ! F_69 ( 2 , 31 , 0 )
F_70 ( NULL ) ;
#endif
#endif
F_71 () ;
F_72 () ;
F_46 () ;
V_76 = F_73 ( V_75 [ 0 ] , main ) ;
if ( V_76 != NULL ) {
fprintf ( V_7 , L_132 ,
V_76 ) ;
}
F_74 () ;
#ifdef V_19
F_75 () ;
if ( ! F_76 () && F_77 () >= 6 ) {
fprintf ( V_7 , L_133
L_134 ) ;
}
#endif
V_71 = F_78 ( L_135 ) ;
F_79 ( V_71 , F_53 ,
V_126 ) ;
V_72 = F_78 ( L_136 ) ;
F_80 ( V_72 , F_58 ) ;
F_81 ( L_91
L_6
L_124
L_6
L_124 ,
F_20 () , V_71 -> V_73 , V_72 -> V_73 ) ;
V_127 = 0 ;
V_121 = V_128 ;
while ( ( V_77 = F_82 ( V_74 , V_75 , V_123 ) ) != - 1 ) {
switch ( V_77 ) {
case 'C' :
if ( F_83 ( V_129 , FALSE ) ) {
F_84 ( V_129 ) ;
} else {
F_35 ( L_137 , V_129 ) ;
return 1 ;
}
break;
case 'P' :
V_130 = TRUE ;
V_131 = TRUE ;
break;
case 'O' :
V_122 = F_34 ( V_129 ) ;
case 'V' :
V_132 = TRUE ;
V_130 = TRUE ;
break;
case 'x' :
V_133 = TRUE ;
V_130 = TRUE ;
break;
case 'X' :
F_85 ( V_129 ) ;
break;
default:
break;
}
}
if ( V_131 == - 1 )
V_131 = ( V_132 || V_133 ) ? FALSE : TRUE ;
V_128 = V_121 ;
V_127 = 1 ;
V_120 =
V_134 |
V_135 |
V_136 |
V_137 |
V_138 |
V_139 |
V_140 | V_141 ;
F_86 ( NULL ,
( T_15 ) V_120 ,
F_42 , NULL ) ;
F_86 ( V_142 ,
( T_15 ) V_120 ,
F_42 , NULL ) ;
#ifdef F_14
F_86 ( V_143 ,
( T_15 ) V_120 ,
F_42 , NULL ) ;
F_86 ( V_144 ,
( T_15 ) V_120 ,
F_42 , NULL ) ;
#endif
F_87 ( V_124 , V_145 , V_146 ,
V_147 ) ;
#ifdef F_14
F_88 ( & V_148 ) ;
F_89 ( & V_149 , ( void * ) & V_150 ) ;
#endif
F_90 ( V_151 ) ;
F_91 ( V_152 ) ;
F_92 ( V_153 ) ;
F_93 () ;
#ifdef F_94
F_95 () ;
F_96 () ;
F_97 () ;
F_98 () ;
#endif
F_99 ( V_154 , V_155 , NULL , NULL ) ;
#ifdef F_94
F_100 () ;
#endif
F_101 () ;
F_102 ( V_156 ) ;
F_103 ( NULL ) ;
if ( V_74 >= 2 && strcmp ( V_75 [ 1 ] , L_138 ) == 0 ) {
F_104 () ;
if ( V_74 == 2 )
F_105 () ;
else {
if ( strcmp ( V_75 [ 2 ] , L_139 ) == 0 )
F_106 () ;
else if ( strcmp ( V_75 [ 2 ] , L_140 ) == 0 ) {
F_107 ( & V_88 , & V_89 , & V_84 ,
& V_90 , & V_91 , & V_85 ) ;
F_108 ( NULL ) ;
}
else if ( strcmp ( V_75 [ 2 ] , L_141 ) == 0 )
F_109 () ;
else if ( strcmp ( V_75 [ 2 ] , L_142 ) == 0 )
F_108 ( NULL ) ;
else if ( strcmp ( V_75 [ 2 ] , L_143 ) == 0 )
F_105 () ;
else if ( strcmp ( V_75 [ 2 ] , L_144 ) == 0 )
F_110 () ;
else if ( strcmp ( V_75 [ 2 ] , L_145 ) == 0 )
F_111 () ;
else if ( strcmp ( V_75 [ 2 ] , L_146 ) == 0 ) {
#ifdef F_94
F_112 () ;
#endif
#ifdef F_113
F_114 () ;
#endif
}
else if ( strcmp ( V_75 [ 2 ] , L_147 ) == 0 )
F_115 () ;
else if ( strcmp ( V_75 [ 2 ] , L_148 ) == 0 )
F_116 () ;
else if ( strcmp ( V_75 [ 2 ] , L_149 ) == 0 )
F_19 () ;
else if ( strcmp ( V_75 [ 2 ] , L_150 ) == 0 )
F_19 () ;
else {
F_35 ( L_151 , V_75 [ 2 ] ) ;
return 1 ;
}
}
return 0 ;
}
setlocale ( V_157 , L_152 ) ;
V_118 = F_107 ( & V_88 , & V_89 , & V_84 ,
& V_90 , & V_91 , & V_85 ) ;
if ( V_84 != NULL ) {
if ( V_88 != 0 ) {
F_35 ( L_153 ,
V_85 , F_117 ( V_88 ) ) ;
}
if ( V_89 != 0 ) {
F_35 ( L_154 ,
V_85 , F_117 ( V_89 ) ) ;
}
}
if ( V_85 != NULL ) {
if ( V_90 != 0 ) {
F_35 ( L_155 , V_85 ,
F_117 ( V_90 ) ) ;
}
if ( V_91 != 0 ) {
F_35 ( L_156 ,
V_85 , F_117 ( V_91 ) ) ;
}
F_11 ( V_85 ) ;
V_85 = NULL ;
}
F_118 ( & V_86 , & V_92 , & V_93 ,
& V_87 , & V_94 , & V_95 ) ;
if ( V_86 != NULL ) {
if ( V_92 != 0 ) {
F_35 ( L_157 ,
V_86 , F_117 ( V_92 ) ) ;
}
if ( V_93 != 0 ) {
F_35 ( L_158 ,
V_86 , F_117 ( V_93 ) ) ;
}
F_11 ( V_86 ) ;
}
if ( V_87 != NULL ) {
if ( V_94 != 0 ) {
F_35 (
L_159 , V_87 ,
F_117 ( V_94 ) ) ;
}
if ( V_95 != 0 ) {
F_35 (
L_160 , V_87 ,
F_117 ( V_95 ) ) ;
}
F_11 ( V_87 ) ;
}
F_119 ( & V_150 ) ;
V_158 = V_159 ;
V_160 = F_120 () ;
while ( ( V_77 = F_121 ( V_74 , V_75 , V_123 , V_79 , NULL ) ) != - 1 ) {
switch ( V_77 ) {
case '2' :
V_161 = TRUE ;
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
case V_162 :
#if F_16 ( V_19 ) || F_16 ( F_15 )
case 'B' :
#endif
#ifdef F_14
V_100 = F_122 ( & V_148 , V_77 , V_129 , & V_99 ) ;
if ( V_100 != 0 ) {
return V_100 ;
}
#else
if ( V_77 == 'w' ) {
V_163 = V_129 ;
} else {
V_103 = TRUE ;
V_82 = TRUE ;
}
#endif
break;
case 'C' :
break;
case 'd' :
if ( ! F_33 ( V_129 ) )
return 1 ;
break;
#if F_16 ( V_164 ) || F_16 ( V_165 )
case 'K' :
F_123 ( V_129 ) ;
break;
#endif
case 'D' :
#ifdef F_14
V_101 = F_124 ( & V_96 , & V_102 , NULL ) ;
if ( V_101 == NULL ) {
if ( V_96 == 0 )
F_35 ( L_161 ) ;
else {
F_35 ( L_124 , V_102 ) ;
F_11 ( V_102 ) ;
}
return 2 ;
}
F_125 ( V_101 ) ;
F_126 ( V_101 ) ;
return 0 ;
#else
V_103 = TRUE ;
V_82 = TRUE ;
#endif
break;
case 'e' :
F_127 ( V_160 , V_129 ) ;
break;
case 'E' :
if ( ! F_128 ( V_160 , V_129 ) ) {
F_35 ( L_162 , V_129 ) ;
F_129 ( V_7 ) ;
return 1 ;
}
break;
case 'F' :
V_105 = F_130 ( V_129 ) ;
if ( V_105 < 0 ) {
F_35 ( L_163 , V_129 ) ;
F_3 () ;
return 1 ;
}
break;
case 'W' :
if ( strchr ( V_129 , 'n' ) ) {
V_108 = TRUE ;
} else {
F_35 ( L_164 , V_129 ) ;
F_131 ( L_165 ) ;
return 1 ;
}
break;
case 'H' :
if ( ! F_132 ( V_129 ) )
{
F_35 ( L_166 , V_129 ) ;
return 1 ;
}
V_108 = TRUE ;
break;
case 'h' :
printf ( L_91
L_167
L_168 ,
F_20 () ) ;
F_13 ( stdout ) ;
return 0 ;
break;
case 'l' :
V_166 = TRUE ;
break;
case 'L' :
#ifdef F_14
V_98 = TRUE ;
#else
V_103 = TRUE ;
V_82 = TRUE ;
#endif
break;
case 'n' :
V_167 . V_168 = FALSE ;
V_167 . V_169 = FALSE ;
V_167 . V_170 = FALSE ;
V_167 . V_171 = FALSE ;
break;
case 'N' :
V_119 = F_133 ( V_129 , & V_167 ) ;
if ( V_119 != '\0' ) {
F_35 ( L_169 ,
V_119 ) ;
F_131 ( L_170
L_171
L_172
L_173
L_174
L_175 ) ;
return 1 ;
}
break;
case 'o' :
switch ( F_134 ( V_129 ) ) {
case V_172 :
break;
case V_173 :
F_35 ( L_176 , V_129 ) ;
return 1 ;
break;
case V_174 :
case V_175 :
F_35 ( L_177 , V_129 ) ;
return 1 ;
break;
}
break;
case 'q' :
V_104 = TRUE ;
break;
case 'Q' :
V_104 = TRUE ;
V_176 = TRUE ;
break;
case 'r' :
V_111 = F_34 ( V_129 ) ;
break;
case 'R' :
V_112 = V_129 ;
break;
case 'P' :
break;
case 'S' :
V_177 = V_129 ;
break;
case 't' :
if ( strcmp ( V_129 , L_178 ) == 0 )
F_90 ( V_151 ) ;
else if ( strcmp ( V_129 , L_179 ) == 0 )
F_90 ( V_178 ) ;
else if ( strcmp ( V_129 , L_180 ) == 0 )
F_90 ( V_179 ) ;
else if ( strcmp ( V_129 , L_181 ) == 0 )
F_90 ( V_180 ) ;
else if ( strcmp ( V_129 , L_182 ) == 0 )
F_90 ( V_181 ) ;
else if ( strcmp ( V_129 , L_183 ) == 0 )
F_90 ( V_182 ) ;
else if ( strcmp ( V_129 , L_184 ) == 0 )
F_90 ( V_183 ) ;
else if ( strcmp ( V_129 , L_185 ) == 0 )
F_90 ( V_184 ) ;
else if ( strcmp ( V_129 , L_186 ) == 0 )
F_90 ( V_185 ) ;
else if ( strcmp ( V_129 , L_187 ) == 0 )
F_90 ( V_186 ) ;
else {
F_35 ( L_188 , V_129 ) ;
F_131 ( L_189
L_190
L_191
L_192
L_193
L_194
L_195
L_196
L_197
L_198 ) ;
return 1 ;
}
break;
case 'T' :
V_130 = TRUE ;
if ( strcmp ( V_129 , L_199 ) == 0 ) {
V_187 = V_188 ;
V_158 = V_159 ;
} else if ( strcmp ( V_129 , L_200 ) == 0 ) {
V_187 = V_188 ;
V_158 = V_189 ;
} else if ( strcmp ( V_129 , L_201 ) == 0 ) {
V_187 = V_190 ;
V_132 = TRUE ;
V_131 = FALSE ;
} else if ( strcmp ( V_129 , L_202 ) == 0 ) {
V_187 = V_190 ;
V_132 = FALSE ;
V_131 = TRUE ;
} else if ( strcmp ( V_129 , L_143 ) == 0 ) {
V_187 = V_191 ;
V_132 = TRUE ;
V_131 = FALSE ;
} else {
F_35 ( L_203 , V_129 ) ;
F_131 ( L_204
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
L_219 ) ;
return 1 ;
}
break;
case 'u' :
if ( strcmp ( V_129 , L_220 ) == 0 )
F_92 ( V_153 ) ;
else if ( strcmp ( V_129 , L_221 ) == 0 )
F_92 ( V_192 ) ;
else {
F_35 ( L_222 , V_129 ) ;
F_131 ( L_223
L_224 ) ;
return 1 ;
}
break;
case 'v' :
{
F_51 ( V_71 , V_72 ) ;
F_135 ( V_71 , TRUE ) ;
F_135 ( V_72 , TRUE ) ;
F_136 () ;
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
V_113 = V_129 ;
break;
case 'z' :
if ( ! F_137 ( V_129 ) ) {
if ( strcmp ( L_130 , V_129 ) == 0 ) {
fprintf ( V_7 , L_225 ) ;
F_138 () ;
return 0 ;
}
F_35 ( L_226 , V_129 ) ;
F_138 () ;
return 1 ;
}
break;
default:
case '?' :
switch( V_193 ) {
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
if ( V_191 != V_187 && 0 != F_139 ( V_160 ) ) {
F_35 ( L_227
L_228 ) ;
return 1 ;
} else if ( V_191 == V_187 && 0 == F_139 ( V_160 ) ) {
F_35 ( L_229
L_230 ) ;
return 1 ;
}
if ( V_128 < V_74 ) {
if ( V_111 != NULL ) {
if ( V_113 != NULL ) {
F_35 ( L_231
L_232 ) ;
return 1 ;
}
V_113 = F_140 ( V_74 , V_75 , V_128 ) ;
} else {
#ifdef F_14
T_21 V_9 ;
if ( V_148 . V_194 . V_195 ) {
F_35 ( L_233
L_234 ) ;
return 1 ;
}
for ( V_9 = 0 ; V_9 < V_148 . V_196 -> V_197 ; V_9 ++ ) {
T_22 V_198 ;
V_198 = F_141 ( V_148 . V_196 , T_22 , V_9 ) ;
if ( V_198 . V_195 == NULL ) {
V_198 . V_195 = F_140 ( V_74 , V_75 , V_128 ) ;
V_148 . V_196 = F_142 ( V_148 . V_196 , V_9 ) ;
F_143 ( V_148 . V_196 , V_9 , V_198 ) ;
} else {
F_35 ( L_235
L_234 ) ;
return 1 ;
}
}
V_148 . V_194 . V_195 = F_140 ( V_74 , V_75 , V_128 ) ;
#else
V_103 = TRUE ;
#endif
}
}
#ifdef F_14
if ( ! V_148 . V_199 ) {
if ( ! V_104 )
V_130 = TRUE ;
} else {
if ( strcmp ( V_148 . V_200 , L_119 ) == 0 && V_130 ) {
F_35 ( L_236
L_237 ) ;
return 1 ;
}
}
#else
if ( ! V_104 )
V_130 = TRUE ;
#endif
#ifndef F_14
if ( V_103 )
F_35 ( L_238 ) ;
#endif
if ( V_82 ) {
F_13 ( V_7 ) ;
return 1 ;
}
if ( V_133 ) {
if ( V_187 != V_188 ) {
F_35 ( L_239 ) ;
return 1 ;
}
}
if ( V_122 != NULL ) {
char * V_201 ;
if ( ! V_132 ) {
F_35 ( L_240 ) ;
return 1 ;
}
V_202 = F_144 ( V_203 , V_204 ) ;
for ( V_201 = strtok ( V_122 , L_241 ) ; V_201 ; V_201 = strtok ( NULL , L_241 ) ) {
F_145 ( V_202 , ( T_3 ) V_201 , ( T_3 ) V_201 ) ;
}
}
if ( V_112 != NULL && ! V_161 ) {
F_35 ( L_242 ) ;
return 1 ;
}
#ifdef F_14
if ( V_98 ) {
if ( V_111 ) {
F_35 ( L_243 ) ;
return 1 ;
}
if ( V_148 . V_205 ) {
F_35 ( L_244 ) ;
return 1 ;
}
} else {
if ( V_111 ) {
if ( V_148 . V_194 . V_195 ) {
F_35 ( L_245
L_246 ) ;
return 1 ;
}
if ( V_148 . V_205 ) {
F_35 ( L_247
L_248 ) ;
return 1 ;
}
if ( V_148 . V_206 ) {
F_35 ( L_249
L_248 ) ;
return 1 ;
}
if ( V_148 . V_207 ) {
F_35 ( L_250
L_248 ) ;
return 1 ;
}
if ( V_148 . V_208 ) {
F_35 ( L_251
L_248 ) ;
return 1 ;
}
if ( V_148 . V_209 ) {
F_35 ( L_252
L_253
L_254 ) ;
return 1 ;
}
if ( V_148 . V_210 ) {
F_35 ( L_255
L_248 ) ;
return 1 ;
}
} else {
if ( V_161 ) {
F_35 ( L_256 ) ;
return 1 ;
}
if ( V_148 . V_199 ) {
if ( V_105 != V_107 &&
V_105 != V_106 ) {
F_35 ( L_257 ) ;
return 1 ;
}
if ( V_148 . V_209 &&
V_105 != V_106 ) {
F_35 ( L_258 ) ;
return 1 ;
}
if ( V_148 . V_205 ) {
if ( strcmp ( V_148 . V_200 , L_119 ) == 0 ) {
F_35 ( L_247
L_259 ) ;
return 1 ;
}
if ( V_148 . V_211 ) {
F_35 ( L_247
L_260 ) ;
return 1 ;
}
if ( ! V_148 . V_212 &&
! V_148 . V_206 ) {
F_35 ( L_247
L_261 ) ;
return 1 ;
}
}
if ( V_112 != NULL ) {
F_35 ( L_262 ) ;
return 1 ;
}
if ( V_113 != NULL ) {
F_35 ( L_263 ) ;
return 1 ;
}
V_148 . V_213 = ( V_105 == V_106 ) ? TRUE : FALSE ;
} else {
if ( V_148 . V_212 ) {
F_35 ( L_264
L_265 ) ;
return 1 ;
}
if ( V_148 . V_205 ) {
F_35 ( L_247
L_266 ) ;
return 1 ;
}
if ( V_148 . V_209 ) {
F_35 ( L_252
L_266 ) ;
return 1 ;
}
}
}
}
#endif
#ifdef V_19
F_146 ( F_147 ( 1 , 1 ) , & V_83 ) ;
#endif
F_148 () ;
F_149 () ;
if ( ! F_150 ( V_160 ) ) {
F_35 ( L_267 ) ;
return 1 ;
}
#ifdef F_14
if ( V_148 . V_199 &&
V_148 . V_211 ) {
if ( F_151 () ) {
F_35 ( L_268 ) ;
return 1 ;
}
if ( V_130 ) {
F_35 ( L_269 ) ;
return 1 ;
}
}
#endif
if ( F_152 ( L_270 ) > 0 ) {
const T_7 * V_16 = F_153 ( L_270 ) ;
V_109 = F_154 ( V_16 ) ;
if ( V_109 == V_110 ) {
F_35 ( L_271 , V_16 ? V_16 : L_152 ) ;
F_12 () ;
return 1 ;
}
}
if ( V_86 == NULL && V_87 == NULL ) {
F_155 () ;
}
F_156 ( & V_150 . V_214 , V_118 -> V_215 , TRUE ) ;
#ifdef F_14
F_157 ( & V_148 , V_216 ) ;
F_158 ( & V_148 ) ;
#endif
if ( V_112 != NULL ) {
if ( ! F_159 ( V_112 , & V_116 ) ) {
F_35 ( L_124 , V_217 ) ;
F_136 () ;
#ifdef F_64
{
T_23 * V_218 ;
V_218 = F_160 ( V_219 , V_216 ) ;
if ( V_218 != NULL ) {
if ( F_161 ( V_218 , & V_115 , V_112 , 0 , 0 ) != - 1 ) {
F_131 (
L_272
L_273 ) ;
}
F_162 ( V_218 ) ;
}
}
#endif
return 2 ;
}
}
V_150 . V_116 = V_116 ;
if ( V_113 != NULL ) {
if ( ! F_159 ( V_113 , & V_117 ) ) {
F_35 ( L_124 , V_217 ) ;
F_136 () ;
#ifdef F_64
{
T_23 * V_218 ;
V_218 = F_160 ( V_219 , V_216 ) ;
if ( V_218 != NULL ) {
if ( F_161 ( V_218 , & V_115 , V_113 , 0 , 0 ) != - 1 ) {
F_131 (
L_274
L_273 ) ;
}
F_162 ( V_218 ) ;
}
}
#endif
return 2 ;
}
}
V_150 . V_117 = V_117 ;
if ( V_130 ) {
if ( V_187 == V_188 ) {
switch ( V_158 ) {
case V_159 :
V_220 = F_163 ( stdout ) ;
break;
case V_189 :
V_220 = F_164 ( stdout ) ;
break;
default:
F_38 () ;
}
}
}
V_221 = V_130 || V_116 || V_117 || F_151 () ;
if ( V_111 ) {
if ( F_165 ( & V_150 , V_111 , V_109 , FALSE , & V_96 ) != V_222 ) {
F_136 () ;
return 2 ;
}
F_166 {
#ifdef F_14
V_96 = F_167 ( & V_150 , V_148 . V_200 , V_105 , V_108 ,
V_148 . V_223 ? V_148 . V_224 : 0 ,
V_148 . V_212 ? V_148 . V_225 : 0 ) ;
#else
V_96 = F_167 ( & V_150 , V_163 , V_105 , V_108 , 0 , 0 ) ;
#endif
}
F_168 (OutOfMemoryError) {
fprintf ( V_7 ,
L_275
L_6
L_276
L_6
L_277
L_278 ) ;
V_96 = V_226 ;
}
V_227 ;
if ( V_96 != 0 ) {
V_97 = 2 ;
}
} else {
#ifdef F_14
V_97 = F_169 ( & V_148 ,
( ( V_118 -> V_228 ) && ( * V_118 -> V_228 != '\0' ) ) ? F_170 ( V_118 -> V_228 ) : NULL ) ;
if ( V_97 != 0 )
return V_97 ;
if ( V_98 ) {
T_21 V_9 ;
for ( V_9 = 0 ; V_9 < V_148 . V_196 -> V_197 ; V_9 ++ ) {
T_22 V_198 ;
T_24 * V_229 ;
V_198 = F_141 ( V_148 . V_196 , T_22 , V_9 ) ;
V_229 = F_171 ( V_198 . V_16 , V_198 . V_230 , & V_102 , NULL ) ;
if ( V_229 == NULL ) {
F_35 ( L_124 , V_102 ) ;
F_11 ( V_102 ) ;
return 2 ;
}
if ( V_229 -> V_231 == NULL ) {
F_35 ( L_279 , V_198 . V_16 ) ;
return 2 ;
}
F_172 ( V_229 , V_198 . V_16 , V_198 . V_230 ) ;
F_173 ( V_229 ) ;
}
return 0 ;
}
if ( ! F_174 ( fileno ( V_7 ) ) )
V_232 = FALSE ;
else if ( V_130 && F_174 ( fileno ( stdout ) ) )
V_232 = FALSE ;
else if ( V_104 )
V_232 = FALSE ;
else
V_232 = TRUE ;
if ( V_130 ) {
if ( ! F_175 ( NULL ) ) {
F_176 ( V_233 ) ;
return 2 ;
}
}
F_177 () ;
V_97 = V_149 . V_234 ;
if ( V_130 ) {
if ( ! F_178 () ) {
V_96 = V_233 ;
F_176 ( V_96 ) ;
}
}
#else
F_35 ( L_238 ) ;
return 2 ;
#endif
}
F_11 ( V_111 ) ;
if ( V_150 . V_235 != NULL ) {
F_179 ( V_150 . V_235 ) ;
V_150 . V_235 = NULL ;
}
F_180 ( TRUE ) ;
F_181 () ;
F_182 ( V_150 . V_236 ) ;
F_136 () ;
F_183 ( V_160 ) ;
V_160 = NULL ;
return V_97 ;
}
static T_1
F_184 ( T_3 V_5 )
{
T_25 V_25 ;
T_26 V_237 = 0 ;
T_10 V_238 ;
T_26 V_239 ;
T_27 * V_240 = V_5 ;
T_1 V_241 = 0 ;
F_185 ( V_240 -> V_242 ) ;
while( V_241 < 5 ) {
V_25 = ( T_25 ) F_186 ( V_240 -> V_243 ) ;
V_238 = F_187 ( V_25 , NULL , 0 , NULL , & V_237 , NULL ) ;
F_188 ( ( T_25 ) * ( V_240 -> V_244 ) ,
& V_239 ) ;
if ( ! V_238 || V_237 > 0 || V_239 != V_245 ) {
if ( ! V_240 -> V_246 ( V_240 -> V_243 , V_240 -> V_30 ) ) {
F_189 ( NULL , V_139 , L_280 , V_241 ) ;
F_190 ( V_240 -> V_242 ) ;
return FALSE ;
}
}
else {
break;
}
V_241 ++ ;
}
F_190 ( V_240 -> V_242 ) ;
return TRUE ;
}
void
F_191 ( T_1 V_243 , T_3 V_30 , int * V_244 , T_28 V_246 )
{
V_247 . V_243 = V_243 ;
V_247 . V_244 = V_244 ;
V_247 . V_30 = V_30 ;
V_247 . V_246 = V_246 ;
#ifdef V_19
#if F_69 ( 2 , 31 , 0 )
V_247 . V_242 = F_192 ( sizeof( V_248 ) ) ;
F_193 ( V_247 . V_242 ) ;
#else
V_247 . V_242 = F_194 () ;
#endif
V_247 . V_249 = F_195 ( 200 , F_184 , & V_247 ) ;
#endif
}
static const T_29 *
F_196 ( void * V_5 , T_11 V_250 )
{
T_30 * V_251 = ( T_30 * ) V_5 ;
if ( V_252 && V_252 -> V_253 == V_250 )
return & V_252 -> V_254 ;
if ( V_255 && V_255 -> V_253 == V_250 )
return & V_255 -> V_254 ;
if ( V_256 && V_256 -> V_253 == V_250 )
return & V_256 -> V_254 ;
if ( V_251 -> V_235 ) {
T_31 * V_257 = F_197 ( V_251 -> V_235 , V_250 ) ;
return ( V_257 ) ? & V_257 -> V_254 : NULL ;
}
return NULL ;
}
static T_32 *
F_198 ( T_30 * V_251 )
{
T_32 * V_236 = F_199 () ;
V_236 -> V_5 = V_251 ;
V_236 -> V_258 = F_196 ;
V_236 -> V_259 = V_260 ;
V_236 -> V_261 = NULL ;
return V_236 ;
}
static T_10
F_177 ( void )
{
T_10 V_262 ;
T_21 V_9 ;
T_16 * V_73 = F_78 ( L_152 ) ;
#ifdef F_200
T_33 V_263 ;
#endif
#ifndef V_19
struct V_264 V_265 , V_266 ;
#endif
F_182 ( V_150 . V_236 ) ;
V_150 . V_236 = F_198 ( & V_150 ) ;
#ifdef V_19
F_201 ( V_267 , TRUE ) ;
#else
memset ( & V_265 , 0 , sizeof( V_265 ) ) ;
V_265 . V_268 = V_267 ;
V_265 . V_269 = V_270 ;
F_202 ( & V_265 . V_271 ) ;
V_264 ( V_272 , & V_265 , NULL ) ;
V_264 ( V_273 , & V_265 , NULL ) ;
V_264 ( V_274 , NULL , & V_266 ) ;
if ( V_266 . V_268 == V_275 )
V_264 ( V_274 , & V_265 , NULL ) ;
#ifdef F_203
V_265 . V_268 = V_276 ;
V_265 . V_269 = V_270 ;
F_202 ( & V_265 . V_271 ) ;
V_264 ( F_203 , & V_265 , NULL ) ;
#endif
#endif
V_149 . V_277 = V_278 ;
for ( V_9 = 0 ; V_9 < V_148 . V_196 -> V_197 ; V_9 ++ ) {
T_22 V_198 ;
V_198 = F_141 ( V_148 . V_196 , T_22 , V_9 ) ;
V_198 . V_279 = F_204 ( V_198 . V_16 ) ;
V_148 . V_196 = F_142 ( V_148 . V_196 , V_9 ) ;
F_143 ( V_148 . V_196 , V_9 , V_198 ) ;
}
#ifdef V_19
if ( V_148 . V_196 -> V_197 < 2 )
#else
if ( V_148 . V_196 -> V_197 < 4 )
#endif
{
for ( V_9 = 0 ; V_9 < V_148 . V_196 -> V_197 ; V_9 ++ ) {
T_22 V_198 ;
V_198 = F_141 ( V_148 . V_196 , T_22 , V_9 ) ;
if ( V_9 > 0 ) {
if ( V_148 . V_196 -> V_197 > 2 ) {
F_60 ( V_73 , L_241 ) ;
}
F_60 ( V_73 , L_281 ) ;
if ( V_9 == V_148 . V_196 -> V_197 - 1 ) {
F_60 ( V_73 , L_282 ) ;
}
}
F_60 ( V_73 , L_283 , V_198 . V_279 ) ;
}
} else {
F_60 ( V_73 , L_284 , V_148 . V_196 -> V_197 ) ;
}
if ( V_176 == FALSE )
fprintf ( V_7 , L_285 , V_73 -> V_73 ) ;
fflush ( V_7 ) ;
F_135 ( V_73 , TRUE ) ;
V_262 = F_205 ( & V_148 , & V_149 , NULL ) ;
if ( ! V_262 )
return FALSE ;
#ifdef F_200
F_206 ( & V_263 ) ;
F_207 ( V_247 . V_243 , & V_263 ) ;
#endif
V_280 = TRUE ;
F_166
{
while ( V_280 )
{
#ifdef F_200
V_262 = F_208 ( V_247 . V_243 + 1 , & V_263 , NULL , NULL , NULL ) ;
if ( V_262 == - 1 )
{
fprintf ( V_7 , L_286 , L_287 , F_117 ( V_233 ) ) ;
return TRUE ;
} else if ( V_262 == 1 ) {
#endif
if ( ! V_247 . V_246 ( V_247 . V_243 , V_247 . V_30 ) ) {
F_189 ( NULL , V_139 , L_288 ) ;
return FALSE ;
}
#ifdef F_200
}
#endif
}
}
F_168 (OutOfMemoryError) {
fprintf ( V_7 ,
L_275
L_6
L_276
L_6
L_277
L_278 ) ;
exit ( 1 ) ;
}
V_227 ;
return TRUE ;
}
void
F_209 ( T_34 * T_35 V_6 , char * V_281 , char * V_282 )
{
F_35 ( L_124 , V_281 ) ;
F_131 ( L_124 , V_282 ) ;
}
void
F_210 ( T_34 * T_35 , T_21 V_9 , char * V_283 )
{
T_36 * V_284 = T_35 -> V_284 ;
T_19 * V_116 = NULL ;
T_22 V_198 ;
F_26 ( V_9 < V_284 -> V_196 -> V_197 ) ;
V_198 = F_141 ( V_284 -> V_196 , T_22 , V_9 ) ;
if ( F_159 ( V_198 . V_195 , & V_116 ) && V_116 != NULL ) {
F_35 (
L_289
L_6
L_290
L_291
L_6
L_292
L_293
L_6
L_294 ,
V_198 . V_195 , V_198 . V_279 , V_283 ) ;
F_211 ( V_116 ) ;
} else {
F_35 (
L_289
L_6
L_295
L_294 ,
V_198 . V_195 , V_198 . V_279 , V_283 ) ;
}
}
T_10
F_212 ( T_34 * T_35 , T_7 * V_285 )
{
T_36 * V_284 = T_35 -> V_284 ;
T_30 * V_251 = ( T_30 * ) T_35 -> V_251 ;
T_10 V_286 ;
int V_96 ;
if ( T_35 -> V_277 == V_278 ) {
F_189 ( V_143 , V_137 , L_296 ) ;
}
F_189 ( V_143 , V_137 , L_297 , V_285 ) ;
F_26 ( T_35 -> V_277 == V_278 || T_35 -> V_277 == V_287 ) ;
if ( V_284 -> V_200 != NULL ) {
if ( V_251 -> V_277 != V_288 ) {
if ( V_251 -> V_289 != NULL ) {
F_213 ( V_251 -> V_289 ) ;
V_251 -> V_289 = NULL ;
}
V_251 -> V_277 = V_288 ;
}
F_11 ( V_284 -> V_200 ) ;
V_286 = FALSE ;
F_182 ( V_251 -> V_236 ) ;
V_251 -> V_236 = F_198 ( V_251 ) ;
} else {
V_286 = TRUE ;
}
V_284 -> V_200 = F_34 ( V_285 ) ;
if ( V_221 ) {
( ( T_30 * ) T_35 -> V_251 ) -> V_290 = V_110 ;
switch( F_165 ( ( T_30 * ) T_35 -> V_251 , V_284 -> V_200 , V_110 , V_286 , & V_96 ) ) {
case V_222 :
break;
case V_291 :
F_11 ( V_284 -> V_200 ) ;
V_284 -> V_200 = NULL ;
return FALSE ;
}
}
T_35 -> V_277 = V_287 ;
return TRUE ;
}
void
F_214 ( T_34 * T_35 , int V_292 )
{
T_10 V_262 ;
int V_96 ;
T_7 * V_293 ;
T_37 V_294 ;
T_30 * V_251 = ( T_30 * ) T_35 -> V_251 ;
T_10 V_295 ;
T_21 V_296 ;
#ifdef F_203
V_297 = TRUE ;
#endif
V_295 = F_215 () ;
V_296 = F_216 () ;
if ( V_221 ) {
T_10 V_298 ;
T_38 * V_299 ;
if ( V_251 -> V_116 || V_251 -> V_117 || V_132 || V_295 ||
( V_296 & V_300 ) || F_217 ( & V_251 -> V_214 ) )
V_298 = TRUE ;
else
V_298 = FALSE ;
V_299 = F_218 ( V_251 -> V_236 , V_298 , V_130 && V_132 ) ;
while ( V_292 -- && V_251 -> V_289 ) {
F_219 ( V_251 -> V_289 ) ;
V_262 = F_220 ( V_251 -> V_289 , & V_96 , & V_293 , & V_294 ) ;
if ( V_262 == FALSE ) {
F_221 ( T_35 ) ;
F_213 ( V_251 -> V_289 ) ;
V_251 -> V_289 = NULL ;
} else {
V_262 = F_222 ( V_251 , V_299 , V_294 , F_223 ( V_251 -> V_289 ) ,
F_224 ( V_251 -> V_289 ) ,
V_296 ) ;
}
if ( V_262 != FALSE ) {
V_301 ++ ;
}
}
F_225 ( V_299 ) ;
} else {
V_301 += V_292 ;
}
if ( V_232 ) {
if ( V_301 != 0 ) {
fprintf ( V_7 , L_298 , V_301 ) ;
fflush ( V_7 ) ;
}
}
#ifdef F_203
V_297 = FALSE ;
if ( V_302 )
F_226 () ;
#endif
}
static void
F_226 ( void )
{
if ( ( V_232 == FALSE ) && ( V_176 == FALSE ) ) {
fprintf ( V_7 , L_299 , V_301 ,
F_227 ( V_301 , L_152 , L_220 ) ) ;
}
#ifdef F_203
V_302 = FALSE ;
#endif
}
static void
V_276 ( int T_39 V_6 )
{
int V_303 = V_233 ;
if ( V_297 )
V_302 = TRUE ;
else
F_226 () ;
V_233 = V_303 ;
}
void
F_228 ( T_34 * T_35 V_6 , T_11 V_304 )
{
if ( V_232 ) {
fprintf ( V_7 , L_6 ) ;
}
if ( V_304 != 0 ) {
fprintf ( V_7 , L_300 , V_304 , F_227 ( V_304 , L_152 , L_220 ) ) ;
}
}
void
F_229 ( T_34 * T_35 , T_7 * V_305 )
{
T_30 * V_251 = ( T_30 * ) T_35 -> V_251 ;
if ( V_305 != NULL )
fprintf ( V_7 , L_301 , V_305 ) ;
F_226 () ;
if ( V_251 != NULL && V_251 -> V_289 != NULL ) {
F_213 ( V_251 -> V_289 ) ;
if ( V_251 -> V_286 ) {
F_230 ( V_251 -> V_306 ) ;
}
}
#ifdef F_231
F_232 ( V_307 ) ;
#else
V_280 = FALSE ;
#endif
}
static BOOL T_40
V_267 ( T_26 T_41 V_6 )
{
F_221 ( & V_149 ) ;
return TRUE ;
}
static void
V_267 ( int T_39 V_6 )
{
F_221 ( & V_149 ) ;
}
static T_10
F_233 ( T_30 * V_251 , T_38 * V_299 ,
T_37 V_308 , struct V_309 * V_310 ,
const T_42 * V_311 )
{
T_31 V_312 ;
T_11 V_313 ;
T_10 V_314 ;
V_313 = V_251 -> V_315 + 1 ;
V_314 = TRUE ;
F_234 ( & V_312 , V_313 , V_310 , V_308 , V_316 ) ;
if ( V_299 ) {
if ( V_167 . V_168 || V_167 . V_169 ||
V_167 . V_170 || V_167 . V_171 )
F_235 () ;
if ( V_251 -> V_116 )
F_236 ( V_299 , V_251 -> V_116 ) ;
if ( V_251 -> V_117 )
F_236 ( V_299 , V_251 -> V_117 ) ;
F_237 ( & V_312 , & V_251 -> V_317 ,
& V_252 , V_255 ) ;
if ( V_252 == & V_312 ) {
V_318 = V_312 ;
V_252 = & V_318 ;
}
F_238 ( V_299 , V_251 -> V_319 , V_310 , F_239 ( & V_312 , V_311 ) , & V_312 , NULL ) ;
if ( V_251 -> V_116 )
V_314 = F_240 ( V_251 -> V_116 , V_299 ) ;
}
if ( V_314 ) {
F_241 ( & V_312 , & V_316 ) ;
V_256 = V_255 = F_242 ( V_251 -> V_235 , & V_312 ) ;
if ( V_299 && V_251 -> V_117 ) {
if ( F_240 ( V_251 -> V_117 , V_299 ) ) {
F_9 ( V_299 -> V_320 . V_321 , V_322 , V_251 -> V_235 ) ;
}
}
V_251 -> V_315 ++ ;
} else {
F_243 ( & V_312 ) ;
}
if ( V_299 )
F_244 ( V_299 ) ;
return V_314 ;
}
static T_10
F_245 ( T_30 * V_251 , T_38 * V_299 , T_31 * V_323 ,
struct V_309 * V_324 , T_43 * V_325 ,
T_21 V_296 )
{
T_44 * V_214 ;
T_10 V_314 ;
V_314 = TRUE ;
if ( V_299 ) {
if ( V_167 . V_168 || V_167 . V_169 ||
V_167 . V_170 || V_167 . V_171 )
F_235 () ;
if ( V_251 -> V_117 )
F_236 ( V_299 , V_251 -> V_117 ) ;
F_246 ( V_299 , & V_251 -> V_214 ) ;
if ( ( V_296 & V_326 ) || ( V_130 && V_131 ) )
V_214 = & V_251 -> V_214 ;
else
V_214 = NULL ;
F_237 ( V_323 , & V_251 -> V_317 ,
& V_252 , V_255 ) ;
if ( V_252 == V_323 ) {
V_318 = * V_323 ;
V_252 = & V_318 ;
}
F_247 ( V_299 , V_251 -> V_319 , V_324 , F_248 ( V_323 , V_325 ) , V_323 , V_214 ) ;
if ( V_251 -> V_117 )
V_314 = F_240 ( V_251 -> V_117 , V_299 ) ;
}
if ( V_314 ) {
F_241 ( V_323 , & V_316 ) ;
if ( V_130 ) {
F_249 ( V_251 , V_299 ) ;
if ( V_166 )
fflush ( stdout ) ;
if ( ferror ( stdout ) ) {
F_176 ( V_233 ) ;
exit ( 2 ) ;
}
}
V_255 = V_323 ;
}
V_256 = V_323 ;
if ( V_299 ) {
F_244 ( V_299 ) ;
}
return V_314 || V_323 -> V_327 . V_328 ;
}
static int
F_167 ( T_30 * V_251 , char * V_200 , int V_105 ,
T_10 V_108 , int V_329 , T_37 V_330 )
{
T_1 V_331 ;
int V_332 ;
T_45 * V_333 ;
T_11 V_313 ;
int V_96 ;
T_7 * V_293 = NULL ;
T_37 V_294 ;
char * V_68 = NULL ;
T_10 V_295 ;
T_21 V_296 ;
T_46 * V_334 ;
T_47 * V_335 ;
char V_336 [ 100 ] ;
struct V_309 V_324 ;
T_43 V_325 ;
T_38 * V_299 = NULL ;
memset ( & V_324 , 0 , sizeof( struct V_309 ) ) ;
V_334 = F_250 ( V_251 -> V_289 ) ;
V_335 = F_251 ( V_251 -> V_289 ) ;
#ifdef F_63
if ( V_335 -> V_337 -> V_197 > 1 ) {
V_331 = V_338 ;
} else {
V_331 = F_252 ( V_251 -> V_289 ) ;
}
#else
V_331 = F_252 ( V_251 -> V_289 ) ;
#endif
if ( V_200 != NULL ) {
V_68 = F_44 ( V_200 ) ;
V_332 = F_253 ( V_251 -> V_289 ) ;
if ( V_332 == 0 ) {
V_332 = V_339 ;
}
if ( V_334 -> V_340 == NULL ) {
F_254 ( V_336 , sizeof( V_336 ) , L_302 , F_20 () ) ;
V_334 -> V_340 = V_336 ;
}
if ( V_331 != V_338 &&
V_105 == V_107 )
V_333 = F_255 ( V_200 , V_105 , V_331 ,
V_332 , FALSE , & V_96 ) ;
else
V_333 = F_256 ( V_200 , V_105 , V_331 ,
V_332 , FALSE , V_334 , V_335 , & V_96 ) ;
F_11 ( V_335 ) ;
V_335 = NULL ;
if ( V_333 == NULL ) {
switch ( V_96 ) {
case V_341 :
F_35 ( L_303 ) ;
break;
case V_342 :
case V_343 :
F_35 ( L_304
L_305 , F_6 ( V_105 ) ) ;
break;
case V_344 :
F_35 ( L_306
L_307 , V_68 ) ;
break;
case V_345 :
F_35 ( L_308 ,
V_68 ) ;
break;
default:
F_35 ( L_309 , V_68 ,
F_257 ( V_96 ) ) ;
break;
}
goto V_346;
}
} else {
if ( V_130 ) {
if ( ! F_175 ( V_251 ) ) {
V_96 = V_233 ;
F_176 ( V_96 ) ;
goto V_346;
}
}
F_11 ( V_335 ) ;
V_335 = NULL ;
V_333 = NULL ;
}
V_295 = F_215 () ;
V_296 = F_216 () ;
if ( V_161 ) {
T_31 * V_323 ;
V_251 -> V_235 = F_258 () ;
if ( V_221 ) {
T_10 V_298 = FALSE ;
if ( V_251 -> V_116 || V_251 -> V_117 )
V_298 = TRUE ;
V_299 = F_218 ( V_251 -> V_236 , V_298 , FALSE ) ;
}
while ( F_220 ( V_251 -> V_289 , & V_96 , & V_293 , & V_294 ) ) {
if ( F_233 ( V_251 , V_299 , V_294 , F_223 ( V_251 -> V_289 ) ,
F_224 ( V_251 -> V_289 ) ) ) {
if ( ( -- V_329 == 0 ) || ( V_330 != 0 && V_294 >= V_330 ) ) {
V_96 = 0 ;
break;
}
}
}
if ( V_299 ) {
F_225 ( V_299 ) ;
V_299 = NULL ;
}
F_259 ( V_251 -> V_289 ) ;
F_260 () ;
V_255 = NULL ;
V_256 = NULL ;
F_261 ( & V_325 , 1500 ) ;
if ( V_221 ) {
T_10 V_298 ;
if ( V_251 -> V_117 || V_132 || V_295 ||
( V_296 & V_300 ) || F_217 ( & V_251 -> V_214 ) )
V_298 = TRUE ;
else
V_298 = FALSE ;
V_299 = F_218 ( V_251 -> V_236 , V_298 , V_130 && V_132 ) ;
}
for ( V_313 = 1 ; V_96 == 0 && V_313 <= V_251 -> V_315 ; V_313 ++ ) {
V_323 = F_197 ( V_251 -> V_235 , V_313 ) ;
if ( F_262 ( V_251 -> V_289 , V_323 -> V_347 , & V_324 , & V_325 , & V_96 ,
& V_293 ) ) {
if ( F_245 ( V_251 , V_299 , V_323 , & V_324 , & V_325 ,
V_296 ) ) {
if ( V_333 != NULL ) {
if ( ! F_263 ( V_333 , & V_324 , F_264 ( & V_325 ) , & V_96 ) ) {
switch ( V_96 ) {
case V_342 :
fprintf ( V_7 ,
L_310 ,
V_313 , V_251 -> V_306 ,
F_6 ( V_105 ) ) ;
break;
case V_348 :
fprintf ( V_7 ,
L_311 ,
V_313 , V_251 -> V_306 ,
F_6 ( V_105 ) ) ;
break;
default:
F_265 ( V_200 , V_96 , FALSE ) ;
break;
}
F_266 ( V_333 , & V_96 ) ;
F_11 ( V_334 ) ;
exit ( 2 ) ;
}
}
}
}
}
if ( V_299 ) {
F_225 ( V_299 ) ;
V_299 = NULL ;
}
F_267 ( & V_325 ) ;
}
else {
V_313 = 0 ;
if ( V_221 ) {
T_10 V_298 ;
if ( V_251 -> V_116 || V_251 -> V_117 || V_132 || V_295 ||
( V_296 & V_300 ) || F_217 ( & V_251 -> V_214 ) )
V_298 = TRUE ;
else
V_298 = FALSE ;
V_299 = F_218 ( V_251 -> V_236 , V_298 , V_130 && V_132 ) ;
}
while ( F_220 ( V_251 -> V_289 , & V_96 , & V_293 , & V_294 ) ) {
V_313 ++ ;
if ( F_222 ( V_251 , V_299 , V_294 , F_223 ( V_251 -> V_289 ) ,
F_224 ( V_251 -> V_289 ) ,
V_296 ) ) {
if ( V_333 != NULL ) {
if ( ! F_263 ( V_333 , F_223 ( V_251 -> V_289 ) , F_224 ( V_251 -> V_289 ) , & V_96 ) ) {
switch ( V_96 ) {
case V_342 :
fprintf ( V_7 ,
L_310 ,
V_313 , V_251 -> V_306 ,
F_6 ( V_105 ) ) ;
break;
case V_348 :
fprintf ( V_7 ,
L_311 ,
V_313 , V_251 -> V_306 ,
F_6 ( V_105 ) ) ;
break;
default:
F_265 ( V_200 , V_96 , FALSE ) ;
break;
}
F_266 ( V_333 , & V_96 ) ;
F_11 ( V_334 ) ;
exit ( 2 ) ;
}
}
}
if ( ( -- V_329 == 0 ) || ( V_330 != 0 && V_294 >= V_330 ) ) {
V_96 = 0 ;
break;
}
}
if ( V_299 ) {
F_225 ( V_299 ) ;
V_299 = NULL ;
}
}
if ( V_96 != 0 ) {
#ifndef V_19
if ( V_130 ) {
T_48 V_349 , V_350 ;
if ( F_268 ( 1 , & V_349 ) == 0 && F_268 ( 2 , & V_350 ) == 0 ) {
if ( V_349 . V_351 == V_350 . V_351 &&
V_349 . V_352 == V_350 . V_352 ) {
fflush ( stdout ) ;
fprintf ( V_7 , L_6 ) ;
}
}
}
#endif
switch ( V_96 ) {
case V_353 :
F_35 ( L_312 ,
V_251 -> V_306 , V_293 ) ;
F_11 ( V_293 ) ;
break;
case V_342 :
F_35 ( L_313 ,
V_251 -> V_306 , V_293 ) ;
F_11 ( V_293 ) ;
break;
case V_354 :
F_35 ( L_314 ,
V_251 -> V_306 ) ;
break;
case V_355 :
F_35 ( L_315 ,
V_251 -> V_306 ) ;
break;
case V_356 :
F_35 ( L_316 ,
V_251 -> V_306 , V_293 ) ;
F_11 ( V_293 ) ;
break;
case V_357 :
F_35 ( L_317
L_318 , V_251 -> V_306 , V_293 ) ;
F_11 ( V_293 ) ;
break;
default:
F_35 ( L_319 ,
V_251 -> V_306 , F_257 ( V_96 ) ) ;
break;
}
if ( V_200 != NULL ) {
if ( ! F_266 ( V_333 , & V_96 ) )
F_265 ( V_200 , V_96 , TRUE ) ;
}
} else {
if ( V_200 != NULL ) {
if ( V_333 && V_108 ) {
if ( ! F_269 ( V_333 , F_270 () ) ) {
F_35 ( L_320 ,
F_6 ( V_105 ) ) ;
}
}
if ( ! F_266 ( V_333 , & V_96 ) )
F_265 ( V_200 , V_96 , TRUE ) ;
} else {
if ( V_130 ) {
if ( ! F_178 () ) {
V_96 = V_233 ;
F_176 ( V_96 ) ;
}
}
}
}
V_346:
F_213 ( V_251 -> V_289 ) ;
V_251 -> V_289 = NULL ;
F_11 ( V_68 ) ;
F_11 ( V_334 ) ;
return V_96 ;
}
static T_10
F_222 ( T_30 * V_251 , T_38 * V_299 , T_37 V_308 , struct V_309 * V_310 ,
const T_42 * V_311 , T_21 V_296 )
{
T_31 V_323 ;
T_44 * V_214 ;
T_10 V_314 ;
V_251 -> V_315 ++ ;
V_314 = TRUE ;
F_234 ( & V_323 , V_251 -> V_315 , V_310 , V_308 , V_316 ) ;
if ( V_299 ) {
if ( V_130 && ( V_167 . V_168 || V_167 . V_169 ||
V_167 . V_170 || V_167 . V_171 ) )
F_235 () ;
if ( V_251 -> V_117 )
F_236 ( V_299 , V_251 -> V_117 ) ;
F_246 ( V_299 , & V_251 -> V_214 ) ;
if ( ( V_296 & V_326 ) || ( V_130 && V_131 ) || F_271 ( V_160 ) )
V_214 = & V_251 -> V_214 ;
else
V_214 = NULL ;
F_237 ( & V_323 , & V_251 -> V_317 ,
& V_252 , V_255 ) ;
if ( V_252 == & V_323 ) {
V_318 = V_323 ;
V_252 = & V_318 ;
}
F_247 ( V_299 , V_251 -> V_319 , V_310 , F_239 ( & V_323 , V_311 ) , & V_323 , V_214 ) ;
if ( V_251 -> V_117 )
V_314 = F_240 ( V_251 -> V_117 , V_299 ) ;
}
if ( V_314 ) {
F_241 ( & V_323 , & V_316 ) ;
if ( V_130 ) {
F_249 ( V_251 , V_299 ) ;
if ( V_166 )
fflush ( stdout ) ;
if ( ferror ( stdout ) ) {
F_176 ( V_233 ) ;
exit ( 2 ) ;
}
}
V_358 = V_323 ;
V_255 = & V_358 ;
}
V_359 = V_323 ;
V_256 = & V_359 ;
if ( V_299 ) {
F_244 ( V_299 ) ;
F_243 ( & V_323 ) ;
}
return V_314 ;
}
static T_10
F_175 ( T_30 * V_251 )
{
switch ( V_187 ) {
case V_188 :
return F_272 ( V_220 , V_251 ? V_251 -> V_306 : NULL , F_20 () ) ;
case V_190 :
if ( V_132 )
F_273 ( stdout , V_251 ? V_251 -> V_306 : NULL ) ;
else
F_274 ( stdout ) ;
return ! ferror ( stdout ) ;
case V_191 :
F_275 ( V_160 , stdout ) ;
return ! ferror ( stdout ) ;
default:
F_38 () ;
return FALSE ;
}
}
static char *
F_276 ( T_49 V_197 )
{
static char * V_360 = NULL ;
static T_49 V_361 = 256 ;
T_49 V_362 ;
for ( V_362 = V_361 ; V_197 > V_362 ;
V_362 *= 2 )
;
if ( V_360 == NULL ) {
V_361 = V_362 ;
V_360 = ( char * ) F_192 ( V_361 + 1 ) ;
} else {
if ( V_362 > V_361 ) {
V_361 = V_362 ;
V_360 = ( char * ) F_277 ( V_360 , V_361 + 1 ) ;
}
}
return V_360 ;
}
static inline void
F_278 ( char * V_363 , const char * V_73 , T_49 V_364 )
{
memcpy ( V_363 , V_73 , V_364 ) ;
V_363 [ V_364 ] = '\0' ;
}
static inline void
F_279 ( char * V_363 , const char * V_73 , T_49 V_364 , T_49 V_365 )
{
T_49 V_9 ;
for ( V_9 = V_364 ; V_9 < V_365 ; V_9 ++ )
* V_363 ++ = ' ' ;
F_278 ( V_363 , V_73 , V_364 ) ;
}
static inline void
F_280 ( char * V_363 , const char * V_73 , T_49 V_364 , T_49 V_365 )
{
T_49 V_9 ;
memcpy ( V_363 , V_73 , V_364 ) ;
for ( V_9 = V_364 ; V_9 < V_365 ; V_9 ++ )
V_363 [ V_9 ] = ' ' ;
V_363 [ V_365 ] = '\0' ;
}
static T_10
F_281 ( T_30 * V_251 )
{
char * V_360 ;
int V_9 ;
T_49 V_366 ;
T_49 V_367 ;
T_49 V_368 ;
V_360 = F_276 ( 256 ) ;
V_366 = 0 ;
* V_360 = '\0' ;
for ( V_9 = 0 ; V_9 < V_251 -> V_214 . V_215 ; V_9 ++ ) {
if ( ! F_282 ( V_9 ) )
continue;
switch ( V_251 -> V_214 . V_369 [ V_9 ] ) {
case V_370 :
V_367 = V_368 = strlen ( V_251 -> V_214 . V_371 [ V_9 ] ) ;
if ( V_367 < 3 )
V_367 = 3 ;
V_360 = F_276 ( V_366 + V_367 ) ;
F_279 ( V_360 + V_366 , V_251 -> V_214 . V_371 [ V_9 ] , V_368 , V_367 ) ;
break;
case V_372 :
case V_373 :
case V_374 :
case V_375 :
case V_376 :
case V_377 :
case V_378 :
case V_379 :
V_367 = V_368 = strlen ( V_251 -> V_214 . V_371 [ V_9 ] ) ;
if ( V_367 < 10 )
V_367 = 10 ;
V_360 = F_276 ( V_366 + V_367 ) ;
F_279 ( V_360 + V_366 , V_251 -> V_214 . V_371 [ V_9 ] , V_368 , V_367 ) ;
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
V_367 = V_368 = strlen ( V_251 -> V_214 . V_371 [ V_9 ] ) ;
if ( V_367 < 12 )
V_367 = 12 ;
V_360 = F_276 ( V_366 + V_367 ) ;
F_279 ( V_360 + V_366 , V_251 -> V_214 . V_371 [ V_9 ] , V_368 , V_367 ) ;
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
V_367 = V_368 = strlen ( V_251 -> V_214 . V_371 [ V_9 ] ) ;
if ( V_367 < 12 )
V_367 = 12 ;
V_360 = F_276 ( V_366 + V_367 ) ;
F_280 ( V_360 + V_366 , V_251 -> V_214 . V_371 [ V_9 ] , V_368 , V_367 ) ;
break;
default:
V_367 = strlen ( V_251 -> V_214 . V_371 [ V_9 ] ) ;
V_360 = F_276 ( V_366 + V_367 ) ;
F_278 ( V_360 + V_366 , V_251 -> V_214 . V_371 [ V_9 ] , V_367 ) ;
break;
}
V_366 += V_367 ;
if ( V_9 != V_251 -> V_214 . V_215 - 1 ) {
V_360 = F_276 ( V_366 + 4 ) ;
switch ( V_251 -> V_214 . V_369 [ V_9 ] ) {
case V_380 :
case V_381 :
case V_382 :
switch ( V_251 -> V_214 . V_369 [ V_9 + 1 ] ) {
case V_389 :
case V_390 :
case V_391 :
F_278 ( V_360 + V_366 , L_321 , 4 ) ;
V_366 += 4 ;
break;
default:
F_278 ( V_360 + V_366 , L_281 , 1 ) ;
V_366 += 1 ;
break;
}
break;
case V_383 :
case V_384 :
case V_385 :
switch ( V_251 -> V_214 . V_369 [ V_9 + 1 ] ) {
case V_392 :
case V_393 :
case V_394 :
F_278 ( V_360 + V_366 , L_321 , 4 ) ;
V_366 += 4 ;
break;
default:
F_278 ( V_360 + V_366 , L_281 , 1 ) ;
V_366 += 1 ;
break;
}
break;
case V_386 :
case V_387 :
case V_388 :
switch ( V_251 -> V_214 . V_369 [ V_9 + 1 ] ) {
case V_395 :
case V_396 :
case V_397 :
F_278 ( V_360 + V_366 , L_321 , 4 ) ;
V_366 += 4 ;
break;
default:
F_278 ( V_360 + V_366 , L_281 , 1 ) ;
V_366 += 1 ;
break;
}
break;
case V_389 :
case V_390 :
case V_391 :
switch ( V_251 -> V_214 . V_369 [ V_9 + 1 ] ) {
case V_380 :
case V_381 :
case V_382 :
F_278 ( V_360 + V_366 , L_322 , 4 ) ;
V_366 += 4 ;
break;
default:
F_278 ( V_360 + V_366 , L_281 , 1 ) ;
V_366 += 1 ;
break;
}
break;
case V_392 :
case V_393 :
case V_394 :
switch ( V_251 -> V_214 . V_369 [ V_9 + 1 ] ) {
case V_383 :
case V_384 :
case V_385 :
F_278 ( V_360 + V_366 , L_322 , 4 ) ;
V_366 += 4 ;
break;
default:
F_278 ( V_360 + V_366 , L_281 , 1 ) ;
V_366 += 1 ;
break;
}
break;
case V_395 :
case V_396 :
case V_397 :
switch ( V_251 -> V_214 . V_369 [ V_9 + 1 ] ) {
case V_386 :
case V_387 :
case V_388 :
F_278 ( V_360 + V_366 , L_322 , 4 ) ;
V_366 += 4 ;
break;
default:
F_278 ( V_360 + V_366 , L_281 , 1 ) ;
V_366 += 1 ;
break;
}
break;
default:
F_278 ( V_360 + V_366 , L_281 , 1 ) ;
V_366 += 1 ;
break;
}
}
}
return F_283 ( V_220 , 0 , V_360 ) ;
}
static T_10
F_249 ( T_30 * V_251 , T_38 * V_299 )
{
T_50 V_398 ;
if ( V_131 || F_271 ( V_160 ) ) {
F_284 ( V_299 , FALSE , TRUE ) ;
if ( V_131 ) {
switch ( V_187 ) {
case V_188 :
if ( ! F_281 ( V_251 ) )
return FALSE ;
break;
case V_190 :
F_285 ( V_299 , stdout ) ;
return ! ferror ( stdout ) ;
case V_191 :
F_38 () ;
break;
}
}
}
if ( V_132 ) {
switch ( V_187 ) {
case V_188 :
V_398 . V_133 = V_133 ;
V_398 . V_399 = V_132 ? V_400 : V_401 ;
if ( ! F_286 ( & V_398 , V_299 , V_220 ) )
return FALSE ;
if ( ! V_133 ) {
if ( ! F_283 ( V_220 , 0 , V_177 ) )
return FALSE ;
}
break;
case V_190 :
F_287 ( V_299 , stdout ) ;
printf ( L_6 ) ;
return ! ferror ( stdout ) ;
case V_191 :
F_288 ( V_160 , V_299 , & V_251 -> V_214 , stdout ) ;
printf ( L_6 ) ;
return ! ferror ( stdout ) ;
}
}
if ( V_133 ) {
if ( V_131 || V_132 ) {
if ( ! F_283 ( V_220 , 0 , L_152 ) )
return FALSE ;
}
if ( ! F_289 ( V_220 , V_299 ) )
return FALSE ;
if ( ! F_283 ( V_220 , 0 , V_177 ) )
return FALSE ;
}
return TRUE ;
}
static T_10
F_178 ( void )
{
switch ( V_187 ) {
case V_188 :
return F_290 ( V_220 ) ;
case V_190 :
if ( V_132 )
F_291 ( stdout ) ;
else
F_292 ( stdout ) ;
return ! ferror ( stdout ) ;
case V_191 :
F_293 ( V_160 , stdout ) ;
return ! ferror ( stdout ) ;
default:
F_38 () ;
return FALSE ;
}
}
T_51
F_165 ( T_30 * V_251 , const char * V_67 , unsigned int type , T_10 V_286 , int * V_96 )
{
T_52 * V_289 ;
T_7 * V_293 ;
char V_402 [ 2048 + 1 ] ;
V_289 = F_294 ( V_67 , type , V_96 , & V_293 , V_161 ) ;
if ( V_289 == NULL )
goto V_403;
F_182 ( V_251 -> V_236 ) ;
V_251 -> V_236 = F_198 ( V_251 ) ;
V_251 -> V_289 = V_289 ;
V_251 -> V_404 = 0 ;
V_251 -> V_306 = F_34 ( V_67 ) ;
V_251 -> V_286 = V_286 ;
V_251 -> V_405 = FALSE ;
V_251 -> V_319 = F_295 ( V_251 -> V_289 ) ;
V_251 -> V_290 = type ;
V_251 -> V_315 = 0 ;
V_251 -> V_406 = FALSE ;
V_251 -> V_407 = 0 ;
V_251 -> V_408 = F_253 ( V_251 -> V_289 ) ;
if ( V_251 -> V_408 == 0 ) {
V_251 -> V_409 = FALSE ;
V_251 -> V_408 = V_339 ;
} else
V_251 -> V_409 = TRUE ;
F_296 ( & V_251 -> V_317 ) ;
V_252 = NULL ;
V_255 = NULL ;
V_256 = NULL ;
V_251 -> V_277 = V_410 ;
F_297 ( V_251 -> V_289 , V_411 ) ;
F_298 ( V_251 -> V_289 , ( V_412 ) V_413 ) ;
return V_222 ;
V_403:
F_254 ( V_402 , sizeof V_402 ,
F_299 ( * V_96 , V_293 , FALSE , V_251 -> V_319 ) , V_67 ) ;
F_35 ( L_124 , V_402 ) ;
return V_291 ;
}
static void
F_265 ( const char * V_67 , int V_96 , T_10 V_414 )
{
char * V_68 ;
V_68 = F_44 ( V_67 ) ;
switch ( V_96 ) {
case V_415 :
F_35 ( L_323
L_324 ,
V_68 ) ;
break;
#ifdef F_300
case F_300 :
F_35 ( L_325
L_326 ,
V_68 ) ;
break;
#endif
case V_416 :
F_35 ( L_327 ,
V_68 ) ;
break;
case V_345 :
F_35 ( L_328 ,
V_68 ) ;
break;
default:
if ( V_414 ) {
F_35 ( L_329 , V_68 ,
F_257 ( V_96 ) ) ;
} else {
F_35 ( L_330 ,
V_68 , F_257 ( V_96 ) ) ;
}
break;
}
F_11 ( V_68 ) ;
}
static void
F_176 ( int V_96 )
{
switch ( V_96 ) {
case V_415 :
F_35 ( L_331
L_324 ) ;
break;
#ifdef F_300
case F_300 :
F_35 ( L_332
L_326 ) ;
break;
#endif
default:
F_35 ( L_333 ,
F_117 ( V_96 ) ) ;
break;
}
}
static const char *
F_299 ( int V_96 , T_7 * V_293 , T_10 V_417 ,
int V_418 )
{
const char * V_419 ;
static char V_420 [ 1024 + 1 ] ;
if ( V_96 < 0 ) {
switch ( V_96 ) {
case V_421 :
V_419 = L_334 ;
break;
case V_422 :
V_419 = L_335 ;
break;
case V_423 :
V_419 = L_336 ;
break;
case V_353 :
F_254 ( V_420 , sizeof( V_420 ) ,
L_337
L_318 , V_293 ) ;
F_11 ( V_293 ) ;
V_419 = V_420 ;
break;
case V_424 :
F_254 ( V_420 , sizeof( V_420 ) ,
L_338
L_339 , F_6 ( V_418 ) ) ;
V_419 = V_420 ;
break;
case V_341 :
V_419 = L_340 ;
break;
case V_342 :
if ( V_417 ) {
F_254 ( V_420 , sizeof( V_420 ) ,
L_341 ,
F_6 ( V_418 ) ) ;
} else {
F_254 ( V_420 , sizeof( V_420 ) ,
L_342
L_318 , V_293 ) ;
F_11 ( V_293 ) ;
}
V_419 = V_420 ;
break;
case V_343 :
if ( V_417 ) {
F_254 ( V_420 , sizeof( V_420 ) ,
L_341 ,
F_6 ( V_418 ) ) ;
V_419 = V_420 ;
} else
V_419 = L_343 ;
break;
case V_356 :
F_254 ( V_420 , sizeof( V_420 ) ,
L_344
L_318 , V_293 ) ;
F_11 ( V_293 ) ;
V_419 = V_420 ;
break;
case V_344 :
if ( V_417 )
V_419 = L_345 ;
else
V_419 = L_346 ;
break;
case V_355 :
V_419 = L_347
L_348 ;
break;
case V_345 :
V_419 = L_349 ;
break;
case V_425 :
V_419 = L_350 ;
break;
case V_357 :
F_254 ( V_420 , sizeof( V_420 ) ,
L_351
L_318 , V_293 ) ;
F_11 ( V_293 ) ;
V_419 = V_420 ;
break;
default:
F_254 ( V_420 , sizeof( V_420 ) ,
L_352 ,
V_417 ? L_353 : L_354 ,
F_257 ( V_96 ) ) ;
V_419 = V_420 ;
break;
}
} else
V_419 = F_301 ( V_96 , V_417 ) ;
return V_419 ;
}
static void
V_145 ( const char * V_306 , int V_96 , T_10 V_417 )
{
fprintf ( V_7 , L_355 ) ;
fprintf ( V_7 , F_301 ( V_96 , V_417 ) , V_306 ) ;
fprintf ( V_7 , L_6 ) ;
}
static void
V_124 ( const char * V_426 , T_53 V_427 )
{
fprintf ( V_7 , L_355 ) ;
vfprintf ( V_7 , V_426 , V_427 ) ;
fprintf ( V_7 , L_6 ) ;
}
static void
V_146 ( const char * V_306 , int V_96 )
{
F_35 ( L_356 ,
V_306 , F_117 ( V_96 ) ) ;
}
static void
V_147 ( const char * V_306 , int V_96 )
{
F_35 ( L_357 ,
V_306 , F_117 ( V_96 ) ) ;
}
static void
V_125 ( const char * V_426 , T_53 V_427 )
{
vfprintf ( V_7 , V_426 , V_427 ) ;
fprintf ( V_7 , L_6 ) ;
}
