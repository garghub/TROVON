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
V_10 = F_4 ( sizeof( struct V_3 ) * V_12 ) ;
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
fprintf ( V_14 , L_16 ) ;
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
fprintf ( V_14 , L_29 ) ;
fprintf ( V_14 , L_30 ) ;
fprintf ( V_14 , L_7 ) ;
fprintf ( V_14 , L_31 ) ;
fprintf ( V_14 , L_32 ) ;
fprintf ( V_14 , L_33 ) ;
fprintf ( V_14 , L_34 ) ;
fprintf ( V_14 , L_35 ) ;
fprintf ( V_14 , L_36 , V_18 ) ;
fprintf ( V_14 , L_37 ) ;
fprintf ( V_14 , L_38 ) ;
fprintf ( V_14 , L_39 ) ;
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
fprintf ( V_14 , L_7 ) ;
fprintf ( V_14 , L_72 ) ;
fprintf ( V_14 , L_73 ) ;
fprintf ( V_14 , L_74 ) ;
fprintf ( V_14 , L_75 ) ;
fprintf ( V_14 , L_76 ) ;
fprintf ( V_14 , L_77 ) ;
fprintf ( V_14 , L_78 ) ;
fprintf ( V_14 , L_79 ) ;
}
static void
F_17 ( void )
{
T_7 * V_14 ;
V_14 = stdout ;
fprintf ( V_14 , L_3 V_15 L_4 , V_16 ) ;
fprintf ( V_14 , L_7 ) ;
fprintf ( V_14 , L_80 ) ;
fprintf ( V_14 , L_7 ) ;
fprintf ( V_14 , L_81 ) ;
fprintf ( V_14 , L_82 ) ;
fprintf ( V_14 , L_83 ) ;
fprintf ( V_14 , L_84 ) ;
fprintf ( V_14 , L_85 ) ;
fprintf ( V_14 , L_86 ) ;
fprintf ( V_14 , L_87 ) ;
fprintf ( V_14 , L_88 ) ;
fprintf ( V_14 , L_89 ) ;
fprintf ( V_14 , L_7 ) ;
fprintf ( V_14 , L_90 ) ;
fprintf ( V_14 , L_91 ) ;
fprintf ( V_14 , L_92 ) ;
fprintf ( V_14 , L_7 ) ;
}
static void
F_18 ( const char * V_19 , const char * V_20 ,
T_3 V_14 )
{
fprintf ( ( T_7 * ) V_14 , L_93 , V_19 , V_20 ) ;
}
static void
F_19 ( const T_8 * T_9 V_6 , T_3 V_21 , T_3 V_14 )
{
int V_22 ;
const T_8 * V_23 ;
const T_8 * V_24 ;
V_22 = F_20 ( ( V_25 ) V_21 ) ;
if ( V_22 != - 1 ) {
V_23 = F_21 ( V_22 ) ;
V_24 = F_22 ( V_22 ) ;
F_23 ( V_23 != NULL ) ;
F_23 ( V_24 != NULL ) ;
fprintf ( ( T_7 * ) V_14 , L_93 ,
V_23 ,
V_24 ) ;
}
}
static void
F_24 ( const T_8 * T_9 V_6 , T_3 V_21 , T_3 V_26 )
{
int V_22 ;
const T_8 * V_27 ;
T_10 V_28 ;
F_23 ( V_21 ) ;
V_28 = ( T_10 ) V_26 ;
V_22 = F_20 ( ( V_25 ) V_21 ) ;
if ( V_22 != - 1 ) {
V_27 = F_21 ( V_22 ) ;
F_23 ( V_27 != NULL ) ;
if ( strcmp ( V_27 , V_28 -> V_29 ) == 0 ) {
if ( V_28 -> V_30 == 0 ) {
V_28 -> V_31 = ( V_25 ) V_21 ;
}
V_28 -> V_30 ++ ;
}
}
}
static void
F_25 ( T_7 * V_14 )
{
F_26 ( F_18 , ( T_3 ) V_14 ) ;
}
static void
F_27 ( T_7 * V_14 , T_8 * V_19 )
{
F_28 ( V_19 ,
F_19 ,
( T_3 ) V_14 ) ;
}
static T_6
F_29 ( const T_8 * V_32 )
{
T_8 * V_19 ;
T_11 V_33 ;
T_8 * V_34 ;
T_8 * V_35 ;
T_8 * V_36 ;
T_8 * V_37 ;
V_25 V_38 ;
T_12 V_39 ;
T_13 V_40 ;
struct V_41 V_42 ;
F_23 ( V_32 ) ;
V_34 = F_30 ( V_32 ) ;
F_23 ( V_34 ) ;
V_19 = V_34 ;
V_35 = strchr ( V_19 , '=' ) ;
if ( V_35 == NULL ) {
F_31 ( L_94 , V_32 , V_18 ) ;
}
else {
* V_35 = '\0' ;
}
while ( V_19 [ 0 ] == ' ' )
V_19 ++ ;
while ( V_19 [ strlen ( V_19 ) - 1 ] == ' ' )
V_19 [ strlen ( V_19 ) - 1 ] = '\0' ;
V_39 = NULL ;
if ( ! ( * ( V_19 ) ) ) {
F_31 ( L_95 ) ;
}
else {
V_39 = F_32 ( V_19 ) ;
if ( ! V_39 ) {
F_31 ( L_96 , V_19 ) ;
}
}
if ( ! V_39 ) {
F_31 ( L_97 ) ;
F_25 ( V_7 ) ;
}
if ( V_35 == NULL || ! V_39 ) {
F_11 ( V_34 ) ;
return FALSE ;
}
if ( * ( V_35 + 1 ) != '=' ) {
F_31 ( L_98 , V_19 , V_35 + 1 ) ;
}
else {
V_35 ++ ;
* V_35 = '\0' ;
}
V_35 ++ ;
V_36 = V_35 ;
V_35 = strchr ( V_36 , ',' ) ;
if ( V_35 == NULL ) {
F_31 ( L_94 , V_32 , V_18 ) ;
}
else {
* V_35 = '\0' ;
}
V_40 = F_33 ( V_19 ) ;
switch ( V_40 ) {
case V_43 :
case V_44 :
case V_45 :
case V_46 :
if ( sscanf ( V_36 , L_99 , & V_33 ) != 1 ) {
F_31 ( L_100 , V_36 ) ;
F_11 ( V_34 ) ;
return FALSE ;
}
break;
case V_47 :
case V_48 :
break;
default:
F_34 () ;
}
if ( V_35 == NULL ) {
F_31 ( L_101 , V_19 ) ;
F_27 ( V_7 , V_19 ) ;
F_11 ( V_34 ) ;
return FALSE ;
}
V_35 ++ ;
V_37 = V_35 ;
while ( V_37 [ 0 ] == ' ' )
V_37 ++ ;
while ( V_37 [ strlen ( V_37 ) - 1 ] == ' ' )
V_37 [ strlen ( V_37 ) - 1 ] = '\0' ;
V_38 = NULL ;
if ( ! ( * V_37 ) ) {
F_31 ( L_102 ) ;
}
else {
V_42 . V_30 = 0 ;
V_42 . V_29 = V_37 ;
V_42 . V_31 = NULL ;
F_28 ( V_19 , F_24 , & V_42 ) ;
if ( V_42 . V_30 != 0 ) {
V_38 = V_42 . V_31 ;
if ( V_42 . V_30 > 1 ) {
F_31 ( L_103 , V_37 , V_42 . V_30 ) ;
}
}
else {
if ( F_35 ( V_37 ) == - 1 ) {
F_31 ( L_104 , V_37 ) ;
} else {
F_31 ( L_105 ,
V_37 , V_19 ) ;
}
}
}
if ( ! V_38 ) {
F_31 ( L_101 , V_19 ) ;
F_27 ( V_7 , V_19 ) ;
F_11 ( V_34 ) ;
return FALSE ;
}
switch ( V_40 ) {
case V_43 :
case V_44 :
case V_45 :
case V_46 :
F_36 ( V_19 , V_33 , V_38 ) ;
break;
case V_47 :
case V_48 :
F_37 ( V_19 , V_36 , V_38 ) ;
break;
default:
F_34 () ;
}
F_11 ( V_34 ) ;
return TRUE ;
}
static void
F_38 ( const T_8 * V_49 , T_14 V_50 ,
const T_8 * V_51 , T_3 V_26 )
{
if( ( V_50 & V_52 & V_53 . V_54 ) == 0 &&
V_53 . V_54 != 0 ) {
return;
}
F_39 ( V_49 , V_50 , V_51 , V_26 ) ;
}
static char *
F_40 ( const char * V_55 )
{
char * V_56 ;
if ( strcmp ( V_55 , L_106 ) == 0 ) {
V_56 = F_30 ( L_107 ) ;
} else {
V_56 = F_41 ( L_108 , V_55 ) ;
}
return V_56 ;
}
static void
F_42 ( void ) {
T_8 * V_57 , * V_58 ;
if ( F_43 () ) {
V_57 = F_44 () ;
V_58 = F_45 () ;
fprintf ( V_7 , L_109 ,
V_57 , V_58 ) ;
F_11 ( V_57 ) ;
F_11 ( V_58 ) ;
if ( F_46 () ) {
fprintf ( V_7 , L_110 ) ;
}
fprintf ( V_7 , L_7 ) ;
}
}
static void
F_47 ( void ) {
#ifdef V_17
F_48 () ;
if ( ! F_49 () && F_50 () >= 6 ) {
fprintf ( V_7 , L_111
L_112 ) ;
}
#endif
}
static void
F_51 ( T_15 * V_59 , T_15 * V_60 )
{
printf ( L_3 V_15 L_4
L_7
L_8
L_7
L_8
L_7
L_8 ,
V_16 , F_13 () , V_59 -> V_61 ,
V_60 -> V_61 ) ;
}
int
main ( int V_62 , char * V_63 [] )
{
char * V_64 ;
int V_65 ;
T_6 V_66 = FALSE ;
#ifdef V_17
T_16 V_67 ;
#endif
char * V_68 , * V_69 ;
char * V_70 , * V_71 ;
int V_72 , V_73 ;
int V_74 , V_75 ;
int V_76 , V_77 ;
int V_78 , V_79 ;
int V_80 ;
volatile int V_81 = 0 ;
#ifdef F_14
T_6 V_82 = FALSE ;
T_6 V_83 = FALSE ;
int V_84 ;
T_17 * V_85 ;
T_8 * V_86 ;
T_18 V_9 ;
T_19 V_87 ;
#else
T_6 V_88 = FALSE ;
#endif
T_6 V_89 = FALSE ;
#ifdef F_52
volatile int V_90 = V_91 ;
#else
volatile int V_90 = V_92 ;
#endif
volatile T_6 V_93 = FALSE ;
T_8 * volatile V_94 = NULL ;
T_8 * V_95 = NULL ;
#ifdef F_53
struct V_96 V_97 ;
#endif
T_20 * V_98 = NULL ;
T_21 * V_99 ;
char V_100 ;
T_14 V_101 ;
int V_102 ;
T_8 * V_103 = NULL ;
#ifdef F_14
#if F_16 ( V_17 ) || F_16 ( F_15 )
#define F_54 "B:"
#else
#define F_54 ""
#endif
#else
#define F_54 ""
#endif
#ifdef F_15
#define F_55 "I"
#else
#define F_55 ""
#endif
#define F_56 "2a:A:b:" OPTSTRING_B "c:C:d:De:E:f:F:G:hH:i:" OPTSTRING_I "K:lLnN:o:O:pPqr:R:s:S:t:T:u:vVw:W:xX:y:z:"
static const char V_104 [] = F_56 ;
#ifdef V_17
F_57 ( V_62 , V_63 ) ;
#if ! F_58 ( 2 , 31 , 0 )
F_59 ( NULL ) ;
#endif
#endif
F_60 () ;
V_64 = F_61 ( V_63 [ 0 ] , main ) ;
if ( V_64 != NULL ) {
fprintf ( V_7 , L_113 ,
V_64 ) ;
}
V_105 = 0 ;
V_102 = V_106 ;
while ( ( V_65 = F_62 ( V_62 , V_63 , V_104 ) ) != - 1 ) {
switch ( V_65 ) {
case 'C' :
if ( F_63 ( V_107 , FALSE ) ) {
F_64 ( V_107 ) ;
} else {
F_31 ( L_114 , V_107 ) ;
return 1 ;
}
break;
case 'X' :
F_65 ( V_107 ) ;
break;
default:
break;
}
}
V_106 = V_102 ;
V_105 = 1 ;
V_101 =
V_108 |
V_109 |
V_110 |
V_111 |
V_112 |
V_113 |
V_114 | V_115 ;
F_66 ( NULL ,
V_101 ,
F_38 , NULL ) ;
F_66 ( V_116 ,
V_101 ,
F_38 , NULL ) ;
#ifdef F_14
F_66 ( V_117 ,
V_101 ,
F_38 , NULL ) ;
F_66 ( V_118 ,
V_101 ,
F_38 , NULL ) ;
#endif
F_67 () ;
#ifdef F_14
F_68 ( & V_119 , & V_120 ) ;
#endif
F_69 ( V_121 ) ;
F_70 ( V_122 ) ;
F_71 ( V_123 ) ;
F_72 ( V_124 , V_125 , NULL , NULL ,
V_126 , V_127 , V_128 ,
V_129 ) ;
#ifdef F_73
F_74 () ;
#endif
F_75 () ;
F_76 () ;
if ( V_62 >= 2 && strcmp ( V_63 [ 1 ] , L_115 ) == 0 ) {
F_77 () ;
if ( V_62 == 2 )
F_78 ( 1 ) ;
else {
if ( strcmp ( V_63 [ 2 ] , L_116 ) == 0 )
F_78 ( 1 ) ;
else if ( strcmp ( V_63 [ 2 ] , L_117 ) == 0 )
F_78 ( 2 ) ;
else if ( strcmp ( V_63 [ 2 ] , L_118 ) == 0 )
F_78 ( 3 ) ;
else if ( strcmp ( V_63 [ 2 ] , L_119 ) == 0 )
F_79 () ;
else if ( strcmp ( V_63 [ 2 ] , L_120 ) == 0 )
F_80 () ;
else if ( strcmp ( V_63 [ 2 ] , L_121 ) == 0 )
F_81 () ;
else if ( strcmp ( V_63 [ 2 ] , L_122 ) == 0 )
F_82 () ;
else if ( strcmp ( V_63 [ 2 ] , L_123 ) == 0 )
F_83 () ;
else if ( strcmp ( V_63 [ 2 ] , L_124 ) == 0 )
F_84 ( NULL ) ;
else if ( strcmp ( V_63 [ 2 ] , L_125 ) == 0 )
F_85 () ;
else if ( strcmp ( V_63 [ 2 ] , L_126 ) == 0 )
F_17 () ;
else if ( strcmp ( V_63 [ 2 ] , L_127 ) == 0 )
F_17 () ;
else if ( strcmp ( V_63 [ 2 ] , L_128 ) == 0 ) {
F_86 ( & V_72 , & V_73 , & V_68 ,
& V_74 , & V_75 , & V_69 ) ;
F_84 ( NULL ) ;
} else {
F_31 ( L_129 , V_63 [ 2 ] ) ;
return 1 ;
}
}
return 0 ;
}
setlocale ( V_130 , L_130 ) ;
V_99 = F_86 ( & V_72 , & V_73 , & V_68 ,
& V_74 , & V_75 , & V_69 ) ;
if ( V_68 != NULL ) {
if ( V_72 != 0 ) {
F_31 ( L_131 ,
V_69 , F_87 ( V_72 ) ) ;
}
if ( V_73 != 0 ) {
F_31 ( L_132 ,
V_69 , F_87 ( V_73 ) ) ;
}
}
if ( V_69 != NULL ) {
if ( V_74 != 0 ) {
F_31 ( L_133 , V_69 ,
F_87 ( V_74 ) ) ;
}
if ( V_75 != 0 ) {
F_31 ( L_134 ,
V_69 , F_87 ( V_75 ) ) ;
}
F_11 ( V_69 ) ;
V_69 = NULL ;
}
V_131 = V_99 -> V_132 ;
F_88 ( & V_70 , & V_76 , & V_77 ,
& V_71 , & V_78 , & V_79 ) ;
if ( V_70 != NULL ) {
if ( V_76 != 0 ) {
F_31 ( L_135 ,
V_70 , F_87 ( V_76 ) ) ;
}
if ( V_77 != 0 ) {
F_31 ( L_136 ,
V_70 , F_87 ( V_77 ) ) ;
}
F_11 ( V_70 ) ;
}
if ( V_71 != NULL ) {
if ( V_78 != 0 ) {
F_31 (
L_137 , V_71 ,
F_87 ( V_78 ) ) ;
}
if ( V_79 != 0 ) {
F_31 (
L_138 , V_71 ,
F_87 ( V_79 ) ) ;
}
F_11 ( V_71 ) ;
}
F_47 () ;
F_89 ( & V_120 ) ;
V_133 = V_134 ;
V_135 = F_90 () ;
while ( ( V_65 = F_62 ( V_62 , V_63 , V_104 ) ) != - 1 ) {
switch ( V_65 ) {
case '2' :
V_136 = TRUE ;
break;
case 'a' :
case 'b' :
case 'c' :
case 'f' :
case 'i' :
case 'p' :
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
V_84 = F_91 ( & V_119 , V_65 , V_107 , & V_83 ) ;
if( V_84 != 0 ) {
return V_84 ;
}
#else
V_88 = TRUE ;
V_66 = TRUE ;
#endif
break;
case 'C' :
break;
case 'd' :
if ( ! F_29 ( V_107 ) )
return 1 ;
break;
#if F_16 ( V_137 ) || F_16 ( V_138 )
case 'K' :
F_92 ( V_107 ) ;
break;
#endif
case 'D' :
#ifdef F_14
V_85 = F_93 ( & V_80 , & V_86 ) ;
if ( V_85 == NULL ) {
switch ( V_80 ) {
case V_139 :
case V_140 :
F_31 ( L_8 , V_86 ) ;
F_11 ( V_86 ) ;
break;
case V_141 :
F_31 ( L_139 ) ;
break;
}
return 2 ;
}
F_94 ( V_85 ) ;
F_95 ( V_85 ) ;
return 0 ;
#else
V_88 = TRUE ;
V_66 = TRUE ;
#endif
break;
case 'e' :
F_96 ( V_135 , V_107 ) ;
break;
case 'E' :
if( ! F_97 ( V_135 , V_107 ) ) {
F_31 ( L_140 , V_107 ) ;
F_98 ( V_7 ) ;
return 1 ;
}
break;
case 'F' :
V_90 = F_99 ( V_107 ) ;
if ( V_90 < 0 ) {
F_31 ( L_141 , V_107 ) ;
F_3 () ;
return 1 ;
}
break;
case 'W' :
if ( strchr ( V_107 , 'n' ) )
V_93 = TRUE ;
break;
case 'H' :
if ( ! F_100 ( V_107 ) )
{
F_31 ( L_142 , V_107 ) ;
return 1 ;
}
V_93 = TRUE ;
break;
case 'h' :
F_12 ( TRUE ) ;
return 0 ;
break;
case 'l' :
V_142 = TRUE ;
break;
case 'L' :
#ifdef F_14
V_82 = TRUE ;
#else
V_88 = TRUE ;
V_66 = TRUE ;
#endif
break;
case 'n' :
V_131 = V_143 ;
break;
case 'N' :
if ( V_131 == V_144 )
V_131 = V_143 ;
V_100 = F_101 ( V_107 , & V_131 ) ;
if ( V_100 != '\0' ) {
F_31 ( L_143 ,
V_100 ) ;
F_102 ( L_144 ) ;
return 1 ;
}
break;
case 'o' :
switch ( F_103 ( V_107 ) ) {
case V_145 :
break;
case V_146 :
F_31 ( L_145 , V_107 ) ;
return 1 ;
break;
case V_147 :
case V_148 :
F_31 ( L_146 , V_107 ) ;
return 1 ;
break;
}
break;
case 'q' :
V_89 = TRUE ;
break;
case 'r' :
V_94 = F_30 ( V_107 ) ;
break;
case 'R' :
V_95 = V_107 ;
break;
case 'P' :
V_149 = TRUE ;
break;
case 'S' :
V_150 = F_104 ( V_107 ) ;
break;
case 't' :
if ( strcmp ( V_107 , L_147 ) == 0 )
F_69 ( V_121 ) ;
else if ( strcmp ( V_107 , L_148 ) == 0 )
F_69 ( V_151 ) ;
else if ( strcmp ( V_107 , L_149 ) == 0 )
F_69 ( V_152 ) ;
else if ( strcmp ( V_107 , L_150 ) == 0 )
F_69 ( V_153 ) ;
else if ( strcmp ( V_107 , L_151 ) == 0 )
F_69 ( V_154 ) ;
else if ( strcmp ( V_107 , L_152 ) == 0 )
F_69 ( V_155 ) ;
else if ( strcmp ( V_107 , L_153 ) == 0 )
F_69 ( V_156 ) ;
else if ( strcmp ( V_107 , L_154 ) == 0 )
F_69 ( V_157 ) ;
else {
F_31 ( L_155 ,
V_107 ) ;
F_102 ( L_156 ) ;
F_102 ( L_157 ) ;
return 1 ;
}
break;
case 'T' :
if ( strcmp ( V_107 , L_158 ) == 0 ) {
V_158 = V_159 ;
V_133 = V_134 ;
} else if ( strcmp ( V_107 , L_159 ) == 0 ) {
V_158 = V_159 ;
V_133 = V_160 ;
} else if ( strcmp ( V_107 , L_160 ) == 0 ) {
V_158 = V_161 ;
V_162 = TRUE ;
} else if ( strcmp ( V_107 , L_161 ) == 0 ) {
V_158 = V_161 ;
V_162 = FALSE ;
} else if( strcmp ( V_107 , L_116 ) == 0 ) {
V_158 = V_163 ;
V_162 = TRUE ;
} else {
F_31 ( L_162 ) ;
F_102 ( L_163 ) ;
return 1 ;
}
break;
case 'u' :
if ( strcmp ( V_107 , L_164 ) == 0 )
F_71 ( V_123 ) ;
else if ( strcmp ( V_107 , L_165 ) == 0 )
F_71 ( V_164 ) ;
else {
F_31 ( L_166 , V_107 ) ;
F_102 ( L_167 ) ;
return 1 ;
}
break;
case 'v' :
{
T_15 * V_59 ;
T_15 * V_60 ;
V_59 = F_105 ( L_168 ) ;
F_106 ( V_59 , NULL , V_165 ) ;
V_60 = F_105 ( L_169 ) ;
F_107 ( V_60 , NULL ) ;
F_51 ( V_59 , V_60 ) ;
F_108 ( V_59 , TRUE ) ;
F_108 ( V_60 , TRUE ) ;
return 0 ;
}
case 'O' :
V_103 = F_30 ( V_107 ) ;
case 'V' :
V_162 = TRUE ;
V_149 = TRUE ;
break;
case 'x' :
V_166 = TRUE ;
V_149 = TRUE ;
break;
case 'X' :
break;
case 'z' :
if ( ! F_109 ( V_107 ) ) {
F_31 ( L_170 ) ;
F_102 ( L_171 ) ;
F_110 () ;
return 1 ;
}
break;
default:
case '?' :
switch( V_167 ) {
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
if( V_163 != V_158 && 0 != F_111 ( V_135 ) ) {
F_31 ( L_172
L_173 ) ;
return 1 ;
} else if( V_163 == V_158 && 0 == F_111 ( V_135 ) ) {
F_31 ( L_174
L_175 ) ;
return 1 ;
}
if ( V_106 < V_62 ) {
if ( V_94 != NULL ) {
if ( V_95 != NULL ) {
F_31 ( L_176
L_177 ) ;
return 1 ;
}
V_95 = F_112 ( V_62 , V_63 , V_106 ) ;
} else {
#ifdef F_14
if ( V_119 . V_168 . V_169 ) {
F_31 ( L_178
L_179 ) ;
return 1 ;
}
for ( V_9 = 0 ; V_9 < V_119 . V_170 -> V_171 ; V_9 ++ ) {
V_87 = F_113 ( V_119 . V_170 , T_19 , V_9 ) ;
if ( V_87 . V_169 == NULL ) {
V_87 . V_169 = F_112 ( V_62 , V_63 , V_106 ) ;
V_119 . V_170 = F_114 ( V_119 . V_170 , V_9 ) ;
F_115 ( V_119 . V_170 , V_9 , V_87 ) ;
} else {
F_31 ( L_180
L_179 ) ;
return 1 ;
}
}
V_119 . V_168 . V_169 = F_112 ( V_62 , V_63 , V_106 ) ;
#else
V_88 = TRUE ;
#endif
}
}
#ifdef F_14
if ( ! V_119 . V_172 ) {
if ( ! V_89 )
V_149 = TRUE ;
} else {
if ( strcmp ( V_119 . V_173 , L_106 ) == 0 && V_149 ) {
F_31 ( L_181
L_182 ) ;
return 1 ;
}
}
#else
if ( ! V_89 )
V_149 = TRUE ;
#endif
#ifndef F_14
if ( V_88 )
F_31 ( L_183 ) ;
#endif
if ( V_66 ) {
F_12 ( FALSE ) ;
return 1 ;
}
#ifdef F_14
if ( V_94 != NULL ) {
if ( V_119 . V_168 . V_169 ) {
F_31 ( L_184
L_185 ) ;
return 1 ;
}
}
#endif
if ( V_166 ) {
if ( V_158 != V_159 ) {
F_31 ( L_186 ) ;
return 1 ;
}
}
if ( V_103 != NULL ) {
char * V_174 ;
if ( ! V_162 ) {
F_31 ( L_187 ) ;
return 1 ;
}
V_175 = F_116 ( V_176 , V_177 ) ;
for ( V_174 = strtok ( V_103 , L_188 ) ; V_174 ; V_174 = strtok ( NULL , L_188 ) ) {
F_117 ( V_175 , ( T_3 ) V_174 , ( T_3 ) V_174 ) ;
}
}
#ifdef F_14
if ( V_82 ) {
if ( V_94 ) {
F_31 ( L_189 ) ;
return 1 ;
}
if ( V_119 . V_178 ) {
F_31 ( L_190 ) ;
return 1 ;
}
} else {
if ( V_94 ) {
if ( V_119 . V_178 ) {
F_31 ( L_191
L_192 ) ;
return 1 ;
}
if ( V_119 . V_179 ) {
F_31 ( L_193
L_192 ) ;
return 1 ;
}
if ( V_119 . V_180 ) {
F_31 ( L_194
L_192 ) ;
return 1 ;
}
if ( V_119 . V_181 ) {
F_31 ( L_195
L_192 ) ;
return 1 ;
}
if ( V_119 . V_182 ) {
F_31 ( L_196
L_192 ) ;
return 1 ;
}
} else {
if ( V_119 . V_172 ) {
if ( V_90 != V_92 && V_90 != V_91 ) {
F_31 ( L_197 ) ;
return 1 ;
}
if ( V_119 . V_178 ) {
if ( strcmp ( V_119 . V_173 , L_106 ) == 0 ) {
F_31 ( L_191
L_198 ) ;
return 1 ;
}
if ( V_119 . V_183 ) {
F_31 ( L_191
L_199 ) ;
return 1 ;
}
if ( ! V_119 . V_184 &&
! V_119 . V_179 ) {
F_31 ( L_191
L_200 ) ;
return 1 ;
}
}
if ( V_95 != NULL ) {
F_31 ( L_201 ) ;
return 1 ;
}
} else {
if ( V_119 . V_184 ) {
F_31 ( L_202
L_203 ) ;
return 1 ;
}
if ( V_119 . V_178 ) {
F_31 ( L_191
L_204 ) ;
return 1 ;
}
}
}
}
#endif
#ifdef V_17
F_118 ( F_119 ( 1 , 1 ) , & V_67 ) ;
#endif
F_120 () ;
F_121 () ;
#ifdef F_14
if ( V_119 . V_172 &&
V_119 . V_183 ) {
if ( F_122 () ) {
F_31 ( L_205 ) ;
return 1 ;
}
if ( V_149 ) {
F_31 ( L_206 ) ;
return 1 ;
}
}
#endif
if ( V_70 == NULL && V_71 == NULL ) {
F_123 () ;
}
F_124 ( & V_120 . V_185 , V_99 -> V_186 , TRUE ) ;
#ifdef F_14
F_125 ( & V_119 , V_187 ) ;
F_126 ( & V_119 ) ;
#endif
if ( V_95 != NULL ) {
if ( ! F_127 ( V_95 , & V_98 ) ) {
F_31 ( L_8 , V_188 ) ;
F_128 () ;
#ifdef F_53
{
T_22 * V_189 ;
V_189 = F_129 ( V_190 , V_187 ) ;
if ( V_189 != NULL ) {
if ( F_130 ( V_189 , & V_97 , V_95 , 0 , 0 ) != - 1 ) {
F_102 (
L_207 ) ;
F_102 (
L_208 ) ;
}
F_131 ( V_189 ) ;
}
}
#endif
return 2 ;
}
}
V_120 . V_98 = V_98 ;
if ( V_149 ) {
if ( V_158 == V_159 ) {
switch ( V_133 ) {
case V_134 :
V_191 = F_132 ( stdout ) ;
break;
case V_160 :
V_191 = F_133 ( stdout ) ;
break;
default:
F_34 () ;
}
}
}
V_192 = V_149 || V_98 || F_122 () ;
if ( V_94 ) {
F_134 () ;
F_42 () ;
if ( F_135 ( & V_120 , V_94 , FALSE , & V_80 ) != V_193 ) {
F_128 () ;
return 2 ;
}
switch( F_136 ( V_120 . V_194 ) ) {
case ( V_195 ) :
F_70 ( V_196 ) ;
break;
case ( V_197 ) :
F_70 ( V_198 ) ;
break;
case ( V_199 ) :
F_70 ( V_200 ) ;
break;
case ( V_201 ) :
F_70 ( V_202 ) ;
break;
case ( V_203 ) :
F_70 ( V_204 ) ;
break;
case ( V_205 ) :
F_70 ( V_206 ) ;
break;
default:
F_34 () ;
}
F_137 {
#ifdef F_14
V_80 = F_138 ( & V_120 , V_119 . V_173 , V_90 , V_93 ,
V_119 . V_207 ? V_119 . V_208 : 0 ,
V_119 . V_184 ? V_119 . V_209 : 0 ) ;
#else
V_80 = F_138 ( & V_120 , NULL , V_90 , V_93 , 0 , 0 ) ;
#endif
}
F_139 (OutOfMemoryError) {
fprintf ( V_7 ,
L_209
L_7
L_210
L_7
L_211
L_212 ) ;
V_80 = V_210 ;
}
V_211 ;
if ( V_80 != 0 ) {
V_81 = 2 ;
}
} else {
#ifdef F_14
if ( ! F_140 ( & V_119 ,
( V_99 -> V_212 ) ? F_141 ( V_99 -> V_212 ) : NULL ) ) {
return 2 ;
}
if ( V_82 ) {
T_18 V_9 ;
T_19 V_87 ;
for ( V_9 = 0 ; V_9 < V_119 . V_170 -> V_171 ; V_9 ++ ) {
T_23 * V_213 ;
V_87 = F_113 ( V_119 . V_170 , T_19 , V_9 ) ;
V_213 = F_142 ( V_87 . V_214 , V_87 . V_215 , & V_86 ) ;
if ( V_213 == NULL ) {
F_31 ( L_8 , V_86 ) ;
F_11 ( V_86 ) ;
return 2 ;
}
if ( V_213 -> V_216 == NULL ) {
F_31 ( L_213 , V_87 . V_214 ) ;
return 2 ;
}
F_143 ( V_213 , V_87 . V_214 , V_87 . V_215 ) ;
F_144 ( V_213 ) ;
}
return 0 ;
}
if ( V_149 ) {
if ( ! F_145 ( NULL ) ) {
F_146 ( V_217 ) ;
return 2 ;
}
} else if ( ! V_89 ) {
V_218 = TRUE ;
}
F_70 ( V_204 ) ;
F_147 () ;
V_81 = V_119 . V_219 ;
if ( V_149 ) {
if ( ! F_148 () ) {
V_80 = V_217 ;
F_146 ( V_80 ) ;
}
}
#else
F_31 ( L_183 ) ;
return 2 ;
#endif
}
F_11 ( V_94 ) ;
if ( V_120 . V_220 != NULL ) {
F_149 ( V_120 . V_220 ) ;
V_120 . V_220 = NULL ;
}
F_150 ( TRUE ) ;
F_151 () ;
F_128 () ;
F_152 ( V_135 ) ;
V_135 = NULL ;
return V_81 ;
}
static T_1
F_153 ( T_3 V_5 )
{
T_24 V_21 ;
T_25 V_221 = 0 ;
T_6 V_222 , V_223 ;
T_25 V_224 ;
T_26 * V_225 = V_5 ;
T_1 V_226 = 0 ;
F_154 ( V_225 -> V_227 ) ;
while( V_226 < 5 ) {
V_21 = ( T_24 ) F_155 ( V_225 -> V_228 ) ;
V_222 = F_156 ( V_21 , NULL , 0 , NULL , & V_221 , NULL ) ;
V_223 = F_157 ( ( T_24 ) * ( V_225 -> V_229 ) ,
& V_224 ) ;
if ( ! V_222 || V_221 > 0 || V_224 != V_230 ) {
if ( ! V_225 -> V_231 ( V_225 -> V_228 , V_225 -> V_26 ) ) {
F_158 ( NULL , V_113 , L_214 , V_226 ) ;
F_159 ( V_225 -> V_227 ) ;
return FALSE ;
}
}
else {
break;
}
V_226 ++ ;
}
F_159 ( V_225 -> V_227 ) ;
return TRUE ;
}
void
F_160 ( T_1 V_228 , T_3 V_26 , int * V_229 , T_27 V_231 )
{
V_232 . V_228 = V_228 ;
V_232 . V_229 = V_229 ;
V_232 . V_26 = V_26 ;
V_232 . V_231 = V_231 ;
#ifdef V_17
#if F_58 ( 2 , 31 , 0 )
V_232 . V_227 = F_4 ( sizeof( V_233 ) ) ;
F_161 ( V_232 . V_227 ) ;
#else
V_232 . V_227 = F_162 () ;
#endif
V_232 . V_234 = F_163 ( 200 , F_153 , & V_232 ) ;
#endif
}
void F_164 ( void )
{
}
void
F_165 ( T_28 * T_29 V_6 , char * V_235 , char * V_236 )
{
F_31 ( L_8 , V_235 ) ;
F_102 ( L_8 , V_236 ) ;
}
void
F_166 ( T_28 * T_29 , T_18 V_9 , char * V_237 )
{
T_20 * V_98 = NULL ;
T_19 V_87 ;
F_23 ( V_9 < T_29 -> V_170 -> V_171 ) ;
V_87 = F_113 ( T_29 -> V_170 , T_19 , V_9 ) ;
if ( F_127 ( V_87 . V_169 , & V_98 ) && V_98 != NULL ) {
F_31 (
L_215
L_7
L_216
L_217
L_7
L_218
L_219
L_7
L_220 ,
V_87 . V_169 , V_87 . V_238 , V_237 ) ;
F_167 ( V_98 ) ;
} else {
F_31 (
L_215
L_7
L_221
L_220 ,
V_87 . V_169 , V_87 . V_238 , V_237 ) ;
}
}
T_6
F_168 ( T_28 * T_29 , T_8 * V_239 )
{
T_6 V_240 ;
int V_80 ;
if( T_29 -> V_241 == V_242 ) {
F_158 ( V_117 , V_111 , L_222 ) ;
}
F_158 ( V_117 , V_111 , L_223 , V_239 ) ;
F_23 ( T_29 -> V_241 == V_242 || T_29 -> V_241 == V_243 ) ;
if ( T_29 -> V_173 != NULL ) {
if( ( ( V_244 * ) T_29 -> V_245 ) -> V_241 != V_246 ) {
if ( ( ( V_244 * ) T_29 -> V_245 ) -> V_194 != NULL ) {
F_169 ( ( ( V_244 * ) T_29 -> V_245 ) -> V_194 ) ;
}
( ( V_244 * ) T_29 -> V_245 ) -> V_241 = V_246 ;
}
F_11 ( T_29 -> V_173 ) ;
V_240 = FALSE ;
} else {
V_240 = TRUE ;
}
T_29 -> V_173 = F_30 ( V_239 ) ;
if( V_192 ) {
switch( F_135 ( T_29 -> V_245 , T_29 -> V_173 , V_240 , & V_80 ) ) {
case V_193 :
break;
case V_247 :
F_11 ( T_29 -> V_173 ) ;
T_29 -> V_173 = NULL ;
return FALSE ;
}
}
T_29 -> V_241 = V_243 ;
return TRUE ;
}
void
F_170 ( T_28 * T_29 , int V_248 )
{
T_6 V_249 ;
int V_80 ;
T_8 * V_250 ;
T_30 V_251 ;
V_244 * V_245 = T_29 -> V_245 ;
T_6 V_252 ;
T_18 V_253 ;
#ifdef F_171
V_254 = TRUE ;
#endif
V_252 = F_172 () ;
V_253 = F_173 () ;
if( V_192 ) {
while ( V_248 -- && V_245 -> V_194 ) {
F_174 ( V_245 -> V_194 ) ;
V_249 = F_175 ( V_245 -> V_194 , & V_80 , & V_250 , & V_251 ) ;
if( V_249 == FALSE ) {
F_176 ( T_29 ) ;
F_169 ( V_245 -> V_194 ) ;
V_245 -> V_194 = NULL ;
} else {
V_249 = F_177 ( V_245 , V_251 , F_178 ( V_245 -> V_194 ) ,
F_179 ( V_245 -> V_194 ) , F_180 ( V_245 -> V_194 ) ,
V_252 , V_253 ) ;
}
if ( V_249 != FALSE ) {
V_255 ++ ;
}
}
} else {
V_255 += V_248 ;
}
if ( V_218 ) {
if ( V_255 != 0 ) {
fprintf ( V_7 , L_224 , V_255 ) ;
fflush ( V_7 ) ;
}
}
#ifdef F_171
V_254 = FALSE ;
if ( V_256 )
F_181 () ;
#endif
}
static void
F_181 ( void )
{
if ( ! V_218 ) {
fprintf ( V_7 , L_225 , V_255 ,
F_182 ( V_255 , L_130 , L_164 ) ) ;
}
#ifdef F_171
V_256 = FALSE ;
#endif
}
static void
F_183 ( int T_31 V_6 )
{
int V_257 = V_217 ;
if ( V_254 )
V_256 = TRUE ;
else
F_181 () ;
V_217 = V_257 ;
}
void
F_184 ( T_28 * T_29 V_6 , T_11 V_258 )
{
if ( V_218 ) {
fprintf ( V_7 , L_7 ) ;
}
if ( V_258 != 0 ) {
fprintf ( V_7 , L_226 , V_258 , F_182 ( V_258 , L_130 , L_164 ) ) ;
}
}
void
F_185 ( T_28 * T_29 , T_8 * V_259 )
{
V_244 * V_245 = ( V_244 * ) T_29 -> V_245 ;
if ( V_259 != NULL )
fprintf ( V_7 , L_227 , V_259 ) ;
F_181 () ;
if( V_245 != NULL && V_245 -> V_194 != NULL ) {
F_169 ( V_245 -> V_194 ) ;
if( V_245 -> V_240 ) {
F_186 ( V_245 -> V_260 ) ;
}
}
#ifdef F_187
F_188 ( V_261 ) ;
#else
V_262 = FALSE ;
#endif
}
static BOOL T_32
F_189 ( T_25 T_33 V_6 )
{
F_176 ( & V_119 ) ;
return TRUE ;
}
static void
F_189 ( int T_31 V_6 )
{
F_176 ( & V_119 ) ;
}
static T_6
F_190 ( V_244 * V_245 ,
T_30 V_263 , const struct V_264 * V_265 ,
union V_266 * V_267 , const T_34 * V_268 )
{
T_35 V_269 ;
T_11 V_270 ;
T_6 V_271 = FALSE ;
T_36 V_272 ;
T_6 V_273 ;
V_270 = V_245 -> V_274 + 1 ;
V_273 = TRUE ;
F_191 ( & V_269 , V_270 , V_265 , V_263 , V_275 ) ;
if ( V_192 ) {
if ( V_131 )
F_192 ( NULL ) ;
if ( V_245 -> V_98 )
V_271 = TRUE ;
F_193 ( & V_272 , V_271 , FALSE ) ;
if ( V_245 -> V_98 )
F_194 ( & V_272 , V_245 -> V_98 ) ;
F_195 ( & V_269 , & V_245 -> V_276 ,
& V_277 , & V_278 , & V_279 ) ;
F_196 ( & V_272 , V_267 , V_268 , & V_269 , NULL ) ;
if ( V_245 -> V_98 )
V_273 = F_197 ( V_245 -> V_98 , & V_272 ) ;
}
if ( V_273 ) {
F_198 ( & V_269 , & V_275 , & V_278 ) ;
F_199 ( V_245 -> V_220 , & V_269 ) ;
V_245 -> V_274 ++ ;
}
if ( V_192 )
F_200 ( & V_272 ) ;
return V_273 ;
}
static T_6
F_201 ( V_244 * V_245 , T_35 * V_280 ,
union V_266 * V_267 , const T_34 * V_268 ,
T_6 V_252 , T_18 V_253 )
{
T_6 V_271 ;
T_37 * V_185 ;
T_36 V_272 ;
T_6 V_273 ;
V_273 = TRUE ;
if ( V_192 ) {
if ( V_131 )
F_192 ( NULL ) ;
if ( V_245 -> V_98 || V_162 || V_252 ||
( V_253 & V_281 ) || F_202 ( & V_245 -> V_185 ) )
V_271 = TRUE ;
else
V_271 = FALSE ;
F_193 ( & V_272 , V_271 , V_149 && V_162 ) ;
if ( V_245 -> V_98 )
F_194 ( & V_272 , V_245 -> V_98 ) ;
F_203 ( & V_272 , & V_245 -> V_185 ) ;
F_204 ( & V_272 ) ;
if ( ( V_253 & V_282 ) || ( V_149 && ! V_162 ) )
V_185 = & V_245 -> V_185 ;
else
V_185 = NULL ;
F_196 ( & V_272 , V_267 , V_268 , V_280 , V_185 ) ;
F_205 ( & V_272 ) ;
if ( V_245 -> V_98 )
V_273 = F_197 ( V_245 -> V_98 , & V_272 ) ;
}
if ( V_273 ) {
if ( V_149 ) {
if ( V_192 )
F_206 ( V_245 , & V_272 ) ;
else
F_206 ( V_245 , NULL ) ;
if ( V_142 )
fflush ( stdout ) ;
if ( ferror ( stdout ) ) {
F_146 ( V_217 ) ;
exit ( 2 ) ;
}
}
}
if ( V_192 ) {
F_200 ( & V_272 ) ;
}
return V_273 ;
}
static int
F_138 ( V_244 * V_245 , char * V_173 , int V_90 ,
T_6 V_93 , int V_283 , T_30 V_284 )
{
T_1 V_285 ;
int V_286 ;
T_38 * V_287 ;
T_11 V_270 ;
int V_80 ;
T_8 * V_250 = NULL ;
T_30 V_251 ;
char * V_56 = NULL ;
T_6 V_252 ;
T_18 V_253 ;
T_39 * V_288 ;
T_40 * V_289 ;
char V_290 [ 100 ] ;
V_288 = F_207 ( V_245 -> V_194 ) ;
V_289 = F_208 ( V_245 -> V_194 ) ;
#ifdef F_52
if ( V_289 -> V_291 > 0 ) {
V_285 = V_292 ;
} else {
V_285 = F_209 ( V_245 -> V_194 ) ;
}
#else
V_285 = F_209 ( V_245 -> V_194 ) ;
#endif
if ( V_173 != NULL ) {
V_56 = F_40 ( V_173 ) ;
V_286 = F_210 ( V_245 -> V_194 ) ;
if ( V_286 == 0 ) {
V_286 = V_293 ;
}
if( V_288 -> V_294 == NULL ) {
F_211 ( V_290 , sizeof( V_290 ) , L_3 V_15 L_8 , V_16 ) ;
V_288 -> V_294 = V_290 ;
}
V_287 = F_212 ( V_173 , V_90 , V_285 , V_286 ,
FALSE , V_288 , V_289 , & V_80 ) ;
F_11 ( V_289 ) ;
V_289 = NULL ;
if ( V_287 == NULL ) {
switch ( V_80 ) {
case V_295 :
F_31 ( L_228 ) ;
break;
case V_296 :
case V_297 :
F_31 ( L_229
L_230 , F_6 ( V_90 ) ) ;
break;
case V_298 :
F_31 ( L_231
L_232 , V_56 ) ;
break;
case V_299 :
F_31 ( L_233 ,
V_56 ) ;
break;
default:
F_31 ( L_234 , V_56 ,
F_213 ( V_80 ) ) ;
break;
}
goto V_300;
}
} else {
if ( V_149 ) {
if ( ! F_145 ( V_245 ) ) {
V_80 = V_217 ;
F_146 ( V_80 ) ;
goto V_300;
}
}
V_287 = NULL ;
}
if ( V_287 && V_93 ) {
if ( ! F_214 ( V_287 , F_215 () ) ) {
F_31 ( L_235 ,
F_6 ( V_90 ) ) ;
}
}
V_252 = F_172 () ;
V_253 = F_173 () ;
if ( V_136 ) {
T_35 * V_280 ;
int V_301 = V_283 ;
V_245 -> V_220 = F_216 () ;
while ( F_175 ( V_245 -> V_194 , & V_80 , & V_250 , & V_251 ) ) {
if ( F_190 ( V_245 , V_251 , F_178 ( V_245 -> V_194 ) ,
F_179 ( V_245 -> V_194 ) , F_180 ( V_245 -> V_194 ) ) ) {
if( ( -- V_283 == 0 ) || ( V_284 != 0 && V_251 >= V_284 ) ) {
V_80 = 0 ;
break;
}
}
}
F_217 ( V_245 -> V_194 ) ;
F_218 () ;
V_283 = V_301 ;
for ( V_270 = 1 ; V_80 == 0 && V_270 <= V_245 -> V_274 ; V_270 ++ ) {
V_280 = F_219 ( V_245 -> V_220 , V_270 ) ;
if ( F_220 ( V_245 -> V_194 , V_280 -> V_302 , & V_245 -> V_267 ,
V_245 -> V_268 , V_280 -> V_303 , & V_80 , & V_250 ) ) {
if ( F_201 ( V_245 , V_280 ,
& V_245 -> V_267 , V_245 -> V_268 ,
V_252 , V_253 ) ) {
if ( V_287 != NULL ) {
if ( ! F_221 ( V_287 , F_178 ( V_245 -> V_194 ) ,
F_179 ( V_245 -> V_194 ) , F_180 ( V_245 -> V_194 ) ,
& V_80 ) ) {
switch ( V_80 ) {
case V_296 :
fprintf ( V_7 ,
L_236 ,
V_270 , V_245 -> V_260 ,
F_6 ( V_90 ) ) ;
break;
default:
F_222 ( V_173 , V_80 , FALSE ) ;
break;
}
F_223 ( V_287 , & V_80 ) ;
F_11 ( V_288 ) ;
exit ( 2 ) ;
}
}
if( ( -- V_283 == 0 ) || ( V_284 != 0 && V_251 >= V_284 ) ) {
V_80 = 0 ;
break;
}
}
}
}
}
else {
V_270 = 0 ;
while ( F_175 ( V_245 -> V_194 , & V_80 , & V_250 , & V_251 ) ) {
V_270 ++ ;
if ( F_177 ( V_245 , V_251 , F_178 ( V_245 -> V_194 ) ,
F_179 ( V_245 -> V_194 ) , F_180 ( V_245 -> V_194 ) ,
V_252 , V_253 ) ) {
if ( V_287 != NULL ) {
if ( ! F_221 ( V_287 , F_178 ( V_245 -> V_194 ) ,
F_179 ( V_245 -> V_194 ) , F_180 ( V_245 -> V_194 ) ,
& V_80 ) ) {
switch ( V_80 ) {
case V_296 :
fprintf ( V_7 ,
L_236 ,
V_270 , V_245 -> V_260 ,
F_6 ( V_90 ) ) ;
break;
default:
F_222 ( V_173 , V_80 , FALSE ) ;
break;
}
F_223 ( V_287 , & V_80 ) ;
F_11 ( V_288 ) ;
exit ( 2 ) ;
}
}
if( ( -- V_283 == 0 ) || ( V_284 != 0 && V_251 >= V_284 ) ) {
V_80 = 0 ;
break;
}
}
}
}
if ( V_80 != 0 ) {
#ifndef V_17
if ( V_149 ) {
struct V_304 V_305 , V_306 ;
if ( F_224 ( 1 , & V_305 ) == 0 && F_224 ( 2 , & V_306 ) == 0 ) {
if ( V_305 . V_307 == V_306 . V_307 &&
V_305 . V_308 == V_306 . V_308 ) {
fflush ( stdout ) ;
fprintf ( V_7 , L_7 ) ;
}
}
}
#endif
switch ( V_80 ) {
case V_309 :
F_31 ( L_237 ,
V_245 -> V_260 , V_250 ) ;
F_11 ( V_250 ) ;
break;
case V_296 :
F_31 ( L_238 ,
V_245 -> V_260 , V_250 ) ;
F_11 ( V_250 ) ;
break;
case V_310 :
F_31 ( L_239 ,
V_245 -> V_260 ) ;
break;
case V_311 :
F_31 ( L_240 ,
V_245 -> V_260 ) ;
break;
case V_312 :
F_31 ( L_241 ,
V_245 -> V_260 , V_250 ) ;
F_11 ( V_250 ) ;
break;
case V_313 :
F_31 ( L_242
L_243 , V_245 -> V_260 , V_250 ) ;
break;
default:
F_31 ( L_244 ,
V_245 -> V_260 , F_213 ( V_80 ) ) ;
break;
}
if ( V_173 != NULL ) {
if ( ! F_223 ( V_287 , & V_80 ) )
F_222 ( V_173 , V_80 , TRUE ) ;
}
} else {
if ( V_173 != NULL ) {
if ( ! F_223 ( V_287 , & V_80 ) )
F_222 ( V_173 , V_80 , TRUE ) ;
} else {
if ( V_149 ) {
if ( ! F_148 () ) {
V_80 = V_217 ;
F_146 ( V_80 ) ;
}
}
}
}
V_300:
F_169 ( V_245 -> V_194 ) ;
V_245 -> V_194 = NULL ;
F_11 ( V_56 ) ;
F_11 ( V_288 ) ;
return V_80 ;
}
static T_6
F_177 ( V_244 * V_245 , T_30 V_263 , const struct V_264 * V_265 ,
union V_266 * V_267 , const T_34 * V_268 ,
T_6 V_252 , T_18 V_253 )
{
T_35 V_280 ;
T_6 V_271 ;
T_37 * V_185 ;
T_36 V_272 ;
T_6 V_273 ;
V_245 -> V_274 ++ ;
V_273 = TRUE ;
F_191 ( & V_280 , V_245 -> V_274 , V_265 , V_263 , V_275 ) ;
if ( V_192 ) {
if ( V_149 && V_131 )
F_192 ( NULL ) ;
if ( V_245 -> V_98 || V_162 || V_252 ||
( V_253 & V_281 ) || F_202 ( & V_245 -> V_185 ) )
V_271 = TRUE ;
else
V_271 = FALSE ;
F_193 ( & V_272 , V_271 , V_149 && V_162 ) ;
if ( V_245 -> V_98 )
F_194 ( & V_272 , V_245 -> V_98 ) ;
F_203 ( & V_272 , & V_245 -> V_185 ) ;
F_204 ( & V_272 ) ;
if ( ( V_253 & V_282 ) || ( V_149 && ! V_162 ) )
V_185 = & V_245 -> V_185 ;
else
V_185 = NULL ;
F_195 ( & V_280 , & V_245 -> V_276 ,
& V_277 , & V_278 , & V_279 ) ;
F_196 ( & V_272 , V_267 , V_268 , & V_280 , V_185 ) ;
F_205 ( & V_272 ) ;
if ( V_245 -> V_98 )
V_273 = F_197 ( V_245 -> V_98 , & V_272 ) ;
}
if ( V_273 ) {
F_198 ( & V_280 , & V_275 , & V_278 ) ;
if ( V_149 ) {
if ( V_192 )
F_206 ( V_245 , & V_272 ) ;
else
F_206 ( V_245 , NULL ) ;
if ( V_142 )
fflush ( stdout ) ;
if ( ferror ( stdout ) ) {
F_146 ( V_217 ) ;
exit ( 2 ) ;
}
}
}
if ( V_192 ) {
F_200 ( & V_272 ) ;
F_225 ( & V_280 ) ;
}
return V_273 ;
}
static T_6
F_145 ( V_244 * V_245 )
{
switch ( V_158 ) {
case V_159 :
return F_226 ( V_191 , V_245 ? V_245 -> V_260 : NULL ) ;
case V_161 :
if ( V_162 )
F_227 ( stdout , V_245 ? V_245 -> V_260 : NULL ) ;
else
F_228 ( stdout ) ;
return ! ferror ( stdout ) ;
case V_163 :
F_229 ( V_135 , stdout ) ;
return ! ferror ( stdout ) ;
default:
F_34 () ;
return FALSE ;
}
}
static char *
F_230 ( T_41 V_171 )
{
static char * V_314 = NULL ;
static T_41 V_315 = 256 ;
T_41 V_316 ;
for ( V_316 = V_315 ; V_171 > V_316 ;
V_316 *= 2 )
;
if ( V_314 == NULL ) {
V_315 = V_316 ;
V_314 = F_4 ( V_315 + 1 ) ;
} else {
if ( V_316 > V_315 ) {
V_315 = V_316 ;
V_314 = F_231 ( V_314 , V_315 + 1 ) ;
}
}
return V_314 ;
}
static T_6
F_232 ( V_244 * V_245 )
{
char * V_314 ;
int V_9 ;
T_41 V_317 ;
T_41 V_318 ;
V_314 = F_230 ( 256 ) ;
V_317 = 0 ;
* V_314 = '\0' ;
for ( V_9 = 0 ; V_9 < V_245 -> V_185 . V_186 ; V_9 ++ ) {
if ( ! F_233 ( V_9 ) )
continue;
switch ( V_245 -> V_185 . V_319 [ V_9 ] ) {
case V_320 :
#ifdef F_14
if ( V_119 . V_170 -> V_171 > 0 )
continue;
#endif
V_318 = strlen ( V_245 -> V_185 . V_321 [ V_9 ] ) ;
if ( V_318 < 3 )
V_318 = 3 ;
V_314 = F_230 ( V_317 + V_318 ) ;
F_211 ( V_314 + V_317 , ( int ) V_318 + 1 , L_245 , V_245 -> V_185 . V_321 [ V_9 ] ) ;
break;
case V_322 :
case V_323 :
case V_324 :
case V_325 :
case V_326 :
case V_327 :
V_318 = strlen ( V_245 -> V_185 . V_321 [ V_9 ] ) ;
if ( V_318 < 10 )
V_318 = 10 ;
V_314 = F_230 ( V_317 + V_318 ) ;
F_211 ( V_314 + V_317 , ( int ) V_318 + 1 , L_246 , V_245 -> V_185 . V_321 [ V_9 ] ) ;
break;
case V_328 :
case V_329 :
case V_330 :
case V_331 :
case V_332 :
case V_333 :
case V_334 :
case V_335 :
case V_336 :
V_318 = strlen ( V_245 -> V_185 . V_321 [ V_9 ] ) ;
if ( V_318 < 12 )
V_318 = 12 ;
V_314 = F_230 ( V_317 + V_318 ) ;
F_211 ( V_314 + V_317 , ( int ) V_318 + 1 , L_247 , V_245 -> V_185 . V_321 [ V_9 ] ) ;
break;
case V_337 :
case V_338 :
case V_339 :
case V_340 :
case V_341 :
case V_342 :
case V_343 :
case V_344 :
case V_345 :
V_318 = strlen ( V_245 -> V_185 . V_321 [ V_9 ] ) ;
if ( V_318 < 12 )
V_318 = 12 ;
V_314 = F_230 ( V_317 + V_318 ) ;
F_211 ( V_314 + V_317 , ( int ) V_318 + 1 , L_248 , V_245 -> V_185 . V_321 [ V_9 ] ) ;
break;
default:
V_318 = strlen ( V_245 -> V_185 . V_321 [ V_9 ] ) ;
V_314 = F_230 ( V_317 + V_318 ) ;
F_234 ( V_314 + V_317 , V_245 -> V_185 . V_321 [ V_9 ] , V_318 + 1 ) ;
break;
}
V_317 += V_318 ;
if ( V_9 != V_245 -> V_185 . V_186 - 1 ) {
V_314 = F_230 ( V_317 + 4 ) ;
switch ( V_245 -> V_185 . V_319 [ V_9 ] ) {
case V_328 :
case V_329 :
case V_330 :
switch ( V_245 -> V_185 . V_319 [ V_9 + 1 ] ) {
case V_337 :
case V_338 :
case V_339 :
F_234 ( V_314 + V_317 , L_249 , 5 ) ;
V_317 += 4 ;
break;
default:
F_234 ( V_314 + V_317 , L_250 , 5 ) ;
V_317 += 1 ;
break;
}
break;
case V_331 :
case V_332 :
case V_333 :
switch ( V_245 -> V_185 . V_319 [ V_9 + 1 ] ) {
case V_340 :
case V_341 :
case V_342 :
F_234 ( V_314 + V_317 , L_249 , 5 ) ;
V_317 += 4 ;
break;
default:
F_234 ( V_314 + V_317 , L_250 , 5 ) ;
V_317 += 1 ;
break;
}
break;
case V_334 :
case V_335 :
case V_336 :
switch ( V_245 -> V_185 . V_319 [ V_9 + 1 ] ) {
case V_343 :
case V_344 :
case V_345 :
F_234 ( V_314 + V_317 , L_249 , 5 ) ;
V_317 += 4 ;
break;
default:
F_234 ( V_314 + V_317 , L_250 , 5 ) ;
V_317 += 1 ;
break;
}
break;
case V_337 :
case V_338 :
case V_339 :
switch ( V_245 -> V_185 . V_319 [ V_9 + 1 ] ) {
case V_328 :
case V_329 :
case V_330 :
F_234 ( V_314 + V_317 , L_251 , 5 ) ;
V_317 += 4 ;
break;
default:
F_234 ( V_314 + V_317 , L_250 , 5 ) ;
V_317 += 1 ;
break;
}
break;
case V_340 :
case V_341 :
case V_342 :
switch ( V_245 -> V_185 . V_319 [ V_9 + 1 ] ) {
case V_331 :
case V_332 :
case V_333 :
F_234 ( V_314 + V_317 , L_251 , 5 ) ;
V_317 += 4 ;
break;
default:
F_234 ( V_314 + V_317 , L_250 , 5 ) ;
V_317 += 1 ;
break;
}
break;
case V_343 :
case V_344 :
case V_345 :
switch ( V_245 -> V_185 . V_319 [ V_9 + 1 ] ) {
case V_334 :
case V_335 :
case V_336 :
F_234 ( V_314 + V_317 , L_251 , 5 ) ;
V_317 += 4 ;
break;
default:
F_234 ( V_314 + V_317 , L_250 , 5 ) ;
V_317 += 1 ;
break;
}
break;
default:
F_234 ( V_314 + V_317 , L_250 , 5 ) ;
V_317 += 1 ;
break;
}
}
}
return F_235 ( V_191 , 0 , V_314 ) ;
}
static T_6
F_206 ( V_244 * V_245 , T_36 * V_272 )
{
T_42 V_346 ;
if ( V_162 ) {
switch ( V_158 ) {
case V_159 :
V_346 . V_347 = TRUE ;
V_346 . V_348 = V_133 ;
V_346 . V_349 = ! V_162 ;
V_346 . V_166 = V_162 && V_166 ;
V_346 . V_350 = FALSE ;
V_346 . V_351 = V_162 ? V_352 : V_353 ;
F_236 ( & V_346 . V_354 ) ;
if ( ! F_237 ( & V_346 , V_272 , V_191 ) )
return FALSE ;
if ( ! V_166 ) {
if ( ! F_235 ( V_191 , 0 , V_150 ) )
return FALSE ;
}
break;
case V_161 :
F_238 ( V_272 , stdout ) ;
printf ( L_7 ) ;
return ! ferror ( stdout ) ;
case V_163 :
F_239 ( V_135 , V_272 , stdout ) ;
printf ( L_7 ) ;
return ! ferror ( stdout ) ;
}
} else {
F_240 ( V_272 , FALSE , TRUE ) ;
switch ( V_158 ) {
case V_159 :
if ( ! F_232 ( V_245 ) )
return FALSE ;
break;
case V_161 :
F_241 ( V_272 , stdout ) ;
return ! ferror ( stdout ) ;
case V_163 :
F_34 () ;
break;
}
}
if ( V_166 ) {
if ( ! F_242 ( V_191 , V_272 ) )
return FALSE ;
if ( ! F_235 ( V_191 , 0 , L_130 ) )
return FALSE ;
}
return TRUE ;
}
static T_6
F_148 ( void )
{
switch ( V_158 ) {
case V_159 :
return F_243 ( V_191 ) ;
case V_161 :
if ( V_162 )
F_244 ( stdout ) ;
else
F_245 ( stdout ) ;
return ! ferror ( stdout ) ;
case V_163 :
F_246 ( V_135 , stdout ) ;
return ! ferror ( stdout ) ;
default:
F_34 () ;
return FALSE ;
}
}
T_43
F_135 ( V_244 * V_245 , const char * V_55 , T_6 V_240 , int * V_80 )
{
T_44 * V_194 ;
T_8 * V_250 ;
char V_355 [ 2048 + 1 ] ;
V_194 = F_247 ( V_55 , V_80 , & V_250 , V_136 ) ;
if ( V_194 == NULL )
goto V_356;
F_248 () ;
F_249 () ;
V_245 -> V_194 = V_194 ;
V_245 -> V_357 = 0 ;
V_245 -> V_260 = F_30 ( V_55 ) ;
V_245 -> V_240 = V_240 ;
V_245 -> V_358 = FALSE ;
V_245 -> V_359 = F_250 ( V_245 -> V_194 ) ;
V_245 -> V_274 = 0 ;
V_245 -> V_360 = FALSE ;
V_245 -> V_361 = 0 ;
V_245 -> V_362 = F_210 ( V_245 -> V_194 ) ;
if ( V_245 -> V_362 == 0 ) {
V_245 -> V_363 = FALSE ;
V_245 -> V_362 = V_293 ;
} else
V_245 -> V_363 = TRUE ;
F_251 ( & V_245 -> V_276 ) ;
F_252 ( & V_277 ) ;
F_252 ( & V_278 ) ;
F_252 ( & V_279 ) ;
V_245 -> V_241 = V_364 ;
F_253 ( V_245 -> V_194 , V_365 ) ;
F_254 ( V_245 -> V_194 , ( V_366 ) V_367 ) ;
return V_193 ;
V_356:
F_211 ( V_355 , sizeof V_355 ,
F_255 ( * V_80 , V_250 , FALSE , V_245 -> V_359 ) , V_55 ) ;
F_31 ( L_8 , V_355 ) ;
return V_247 ;
}
static void
F_222 ( const char * V_55 , int V_80 , T_6 V_368 )
{
char * V_56 ;
V_56 = F_40 ( V_55 ) ;
switch ( V_80 ) {
case V_369 :
F_31 ( L_252
L_253 ,
V_56 ) ;
break;
#ifdef F_256
case F_256 :
F_31 ( L_254
L_255 ,
V_56 ) ;
break;
#endif
case V_370 :
F_31 ( L_256 ,
V_56 ) ;
break;
case V_299 :
F_31 ( L_257 ,
V_56 ) ;
break;
default:
if ( V_368 ) {
F_31 ( L_258 , V_56 ,
F_213 ( V_80 ) ) ;
} else {
F_31 ( L_259 ,
V_56 , F_213 ( V_80 ) ) ;
}
break;
}
F_11 ( V_56 ) ;
}
static void
F_146 ( int V_80 )
{
switch ( V_80 ) {
case V_369 :
F_31 ( L_260
L_253 ) ;
break;
#ifdef F_256
case F_256 :
F_31 ( L_261
L_255 ) ;
break;
#endif
default:
F_31 ( L_262 ,
F_87 ( V_80 ) ) ;
break;
}
}
static const char *
F_255 ( int V_80 , T_8 * V_250 , T_6 V_371 ,
int V_372 )
{
const char * V_373 ;
static char V_374 [ 1024 + 1 ] ;
if ( V_80 < 0 ) {
switch ( V_80 ) {
case V_375 :
V_373 = L_263 ;
break;
case V_376 :
V_373 = L_264 ;
break;
case V_377 :
V_373 = L_265 ;
break;
case V_309 :
F_211 ( V_374 , sizeof( V_374 ) ,
L_266
L_243 , V_250 ) ;
F_11 ( V_250 ) ;
V_373 = V_374 ;
break;
case V_378 :
F_211 ( V_374 , sizeof( V_374 ) ,
L_267
L_268 , F_6 ( V_372 ) ) ;
V_373 = V_374 ;
break;
case V_295 :
V_373 = L_269 ;
break;
case V_296 :
if ( V_371 ) {
F_211 ( V_374 , sizeof( V_374 ) ,
L_270 ,
F_6 ( V_372 ) ) ;
} else {
F_211 ( V_374 , sizeof( V_374 ) ,
L_271
L_243 , V_250 ) ;
F_11 ( V_250 ) ;
}
V_373 = V_374 ;
break;
case V_297 :
if ( V_371 ) {
F_211 ( V_374 , sizeof( V_374 ) ,
L_270 ,
F_6 ( V_372 ) ) ;
V_373 = V_374 ;
} else
V_373 = L_272 ;
break;
case V_312 :
F_211 ( V_374 , sizeof( V_374 ) ,
L_273
L_243 , V_250 ) ;
F_11 ( V_250 ) ;
V_373 = V_374 ;
break;
case V_298 :
if ( V_371 )
V_373 = L_274 ;
else
V_373 = L_275 ;
break;
case V_311 :
V_373 = L_276
L_277 ;
break;
case V_299 :
V_373 = L_278 ;
break;
case V_379 :
V_373 = L_279 ;
break;
case V_313 :
F_211 ( V_374 , sizeof( V_374 ) ,
L_280
L_243 , V_250 ) ;
F_11 ( V_250 ) ;
V_373 = V_374 ;
break;
default:
F_211 ( V_374 , sizeof( V_374 ) ,
L_281 ,
V_371 ? L_282 : L_283 ,
F_213 ( V_80 ) ) ;
V_373 = V_374 ;
break;
}
} else
V_373 = F_257 ( V_80 , V_371 ) ;
return V_373 ;
}
static void
V_127 ( const char * V_260 , int V_80 , T_6 V_371 )
{
fprintf ( V_7 , L_284 ) ;
fprintf ( V_7 , F_257 ( V_80 , V_371 ) , V_260 ) ;
fprintf ( V_7 , L_7 ) ;
}
static void
V_126 ( const char * V_380 , T_45 V_381 )
{
fprintf ( V_7 , L_284 ) ;
vfprintf ( V_7 , V_380 , V_381 ) ;
fprintf ( V_7 , L_7 ) ;
}
static void
V_128 ( const char * V_260 , int V_80 )
{
F_31 ( L_285 ,
V_260 , F_87 ( V_80 ) ) ;
}
static void
V_129 ( const char * V_260 , int V_80 )
{
F_31 ( L_286 ,
V_260 , F_87 ( V_80 ) ) ;
}
void
F_258 ( const char * V_382 , T_45 V_381 )
{
vfprintf ( V_7 , V_382 , V_381 ) ;
}
void
F_259 ( const char * V_382 , ... )
{
T_45 V_381 ;
va_start ( V_381 , V_382 ) ;
F_258 ( V_382 , V_381 ) ;
va_end ( V_381 ) ;
}
void
F_31 ( const char * V_382 , ... )
{
T_45 V_381 ;
va_start ( V_381 , V_382 ) ;
V_126 ( V_382 , V_381 ) ;
va_end ( V_381 ) ;
}
void
F_102 ( const char * V_382 , ... )
{
T_45 V_381 ;
va_start ( V_381 , V_382 ) ;
vfprintf ( V_7 , V_382 , V_381 ) ;
fprintf ( V_7 , L_7 ) ;
va_end ( V_381 ) ;
}
